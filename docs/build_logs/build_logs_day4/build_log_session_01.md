Build Log
=========

**Date:** 4 July 2026 | **Time:** 12:00 - 2:00

Session 3 – Redesigning the Bucket Storage and Implementing Rehashing
---------------------------------------------------------------------

In this session, I revised the internal design of my HashMap after gaining a better understanding of how buckets should be organized. Initially, I had considered storing the buckets differently, but I realized that using a DynamicArray where each element is a LinkedList provides a much cleaner and more scalable implementation for separate chaining.

The new bucket structure is:

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   DynamicArray> buckets;   `

Each element of the dynamic array represents one bucket, and every bucket is an independent linked list that stores pointers to Entry objects. Instead of storing Entry objects directly inside the linked list, I chose to store Entry\* so that all Entry objects are created and destroyed using my custom allocator. This design gives me full control over object lifetime and memory management.

I updated the HashMap constructor to initialize the bucket array with an initial capacity of eight buckets. Since my DynamicArray uses lazy construction, I explicitly appended an empty LinkedList into every bucket during initialization.

After finalizing the bucket layout, I implemented the put() operation. The insertion process first computes the bucket index using the hash function, traverses the corresponding linked list to check whether the key already exists, updates the value if it is found, and otherwise allocates a new Entry using my custom allocator before inserting its pointer into the appropriate bucket. I also integrated load factor checking after every successful insertion.

The next major feature implemented was automatic rehashing. Whenever the load factor exceeds the predefined threshold, the hash table doubles its capacity. During rehashing, I create a new bucket array with twice the number of buckets, traverse every bucket from the old table, recompute the bucket index for each stored key using the new capacity, and insert the existing Entry\* into the corresponding bucket of the new table. The actual Entry objects are not recreated or copied; only their pointers are redistributed among the new buckets. Finally, the old bucket array is replaced with the new one.

I also added utility functions such as loadFactor(), get\_size(), get\_capacity(), and a print() function for debugging and visualizing the bucket distribution after insertions and rehashing.

Throughout this session, I developed a much clearer understanding of the relationship between dynamic arrays, linked lists, pointers, and custom allocators. One of the most important concepts I learned is that rehashing does not move or recreate the stored objects—it simply reorganizes the pointers into a larger bucket array based on the updated hash function.

### Current Features Completed

*   Implemented bucket storage using DynamicArray\>.
    
*   Initialized all buckets during HashMap construction.
    
*   Implemented insertion (put()).
    
*   Implemented duplicate key detection and value updates.
    
*   Integrated custom allocator for Entry allocation and destruction.
    
*   Implemented load factor calculation.
    
*   Implemented automatic rehashing by doubling the bucket count.
    
*   Added debugging utilities (print(), get\_size(), and get\_capacity()).
    
*   Implemented proper cleanup of allocated Entry objects in the destructor.
    

### Next Steps

*   Implement get() for key lookup.
    
*   Implement containsKey().
    
*   Implement remove().
    
*   Add clear() and empty() operations.
    
*   Improve the hash function to support generic key types beyond integer keys.