.. include:: includes/aliases.rst

.. _xmldynamictypes:

Dynamic Types profiles
----------------------

Fast DDS supports the implementation of |DynamicTypes| by defining them through XML profile files.
Thus the :ref:`Dynamic Types <dynamic-types>` can be modified without the need to modify the source code of the DDS
application.

XML Structure
^^^^^^^^^^^^^

The definition of type profiles in the XML file is done with the ``<types>`` tag.
The definition of a type via XML can be done in two manners:

1.   Stand-Alone XML types files:

.. literalinclude:: /../code/XMLTester.xml
    :language: xml
    :start-after: <!-- STAND ALONE TYPES START -->
    :end-before: <!-- STAND ALONE TYPES END -->

2.  The ``<type>`` element is a child of the Fast DDS XML root tag referred to as ``<dds>``:

.. literalinclude:: /../code/XMLTesterAux.xml
    :language: xml
    :start-after: <!-- ROOTED TYPES START -->
    :end-before: <!-- ROOTED TYPES END -->

Finally, each ``<type>`` element can contain one or more :ref:`Type definitions <Type definition>`.
Defining several types within a ``<type>`` element or a single type for each ``<type>`` element has the same
result.

.. _Type definition:

Type definition
^^^^^^^^^^^^^^^
Below are presented the types supported by Fast DDS.
For further information about the supported |DynamicTypes|, please, refer to :ref:`dynamictypes_supportedtypes`.
For each of the types detailed below, an example of how to build the type's XML profile is provided, as well as its
equivalence in C++ source code for further insight.

Enum
""""

The ``<enum>`` type is defined by its attribute ``name`` and a set of ``<enumerator>`` child elements.
Each ``<enumerator>`` is defined by two attributes: a ``name`` and an optional ``value``.
Please, refer to :ref:`dynamictypes_supportedtypes_enumeration` for more information on the ``<enum>`` type.

+----------------------------------------------------------------------------------------------------------------------+
| **XML**                                                                                                              |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/XMLTester.xml                                                                           |
|   :language: xml                                                                                                     |
|   :start-after: <!-->XML-DYN-ENUM<-->                                                                                |
|   :end-before: <!--><-->                                                                                             |
+----------------------------------------------------------------------------------------------------------------------+
| **C++**                                                                                                              |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/CodeTester.cpp                                                                          |
|   :language: c++                                                                                                     |
|   :start-after: //XML-DYN-ENUM                                                                                       |
|   :end-before: //!--                                                                                                 |
|   :dedent: 4                                                                                                         |
+----------------------------------------------------------------------------------------------------------------------+

Typedef
"""""""

The ``<typedef>`` XML element is defined by a ``name`` and a ``type`` mandatory attributes, and various optional
attributes for complex types.
The ``<typedef>`` element corresponds to :ref:`dynamictypes_supportedtypes_alias` in :ref:`dynamictypes_supportedtypes`
section.

+----------------------------------------------------------------------------------------------------------------------+
| **XML**                                                                                                              |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/XMLTester.xml                                                                           |
|   :language: xml                                                                                                     |
|   :start-after: <!-->XML-TYPEDEF<-->                                                                                 |
|   :end-before: <!--><-->                                                                                             |
+----------------------------------------------------------------------------------------------------------------------+
| **C++**                                                                                                              |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/CodeTester.cpp                                                                          |
|   :language: c++                                                                                                     |
|   :start-after: //XML-TYPEDEF                                                                                        |
|   :end-before: //!--                                                                                                 |
|   :dedent: 4                                                                                                         |
+----------------------------------------------------------------------------------------------------------------------+

Struct
""""""

The ``<struct>`` element is defined by its ``name`` attribute and its ``<member>`` child elements.
Please, refer to :ref:`dynamictypes_supportedtypes_structure` for more information on the ``<struct>`` type.

+----------------------------------------------------------------------------------------------------------------------+
| **XML**                                                                                                              |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/XMLTester.xml                                                                           |
|   :language: xml                                                                                                     |
|   :start-after: <!-->XML-STRUCT<-->                                                                                  |
|   :end-before: <!--><-->                                                                                             |
+----------------------------------------------------------------------------------------------------------------------+
| **C++**                                                                                                              |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/CodeTester.cpp                                                                          |
|   :language: c++                                                                                                     |
|   :start-after: //XML-STRUCT                                                                                         |
|   :end-before: //!--                                                                                                 |
|   :dedent: 8                                                                                                         |
+----------------------------------------------------------------------------------------------------------------------+

Structs can inherit from another structs.
This is implemented by defining as the value of the ``baseType`` attribute, on the child ``<struct>`` element, the value
of the ``name`` attribute of the parent ``<struct>`` element.
This is exemplified by the code snippet below.

+----------------------------------------------------------------------------------------------------------------------+
| **XML**                                                                                                              |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/XMLTester.xml                                                                           |
|   :language: xml                                                                                                     |
|   :start-after: <!-->XML-STRUCT-INHERIT<-->                                                                          |
|   :end-before: <!--><-->                                                                                             |
|                                                                                                                      |
+----------------------------------------------------------------------------------------------------------------------+
| **C++**                                                                                                              |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/CodeTester.cpp                                                                          |
|   :language: c++                                                                                                     |
|   :start-after: //XML-STRUCT-INHERIT                                                                                 |
|   :end-before: //!--                                                                                                 |
|   :dedent: 8                                                                                                         |
+----------------------------------------------------------------------------------------------------------------------+

Union
"""""

The ``<union>`` type is defined by a ``name`` attribute, a ``<discriminator>`` child element and a set of ``<case>``
child elements.
Each ``<case>`` element has one or more ``<caseDiscriminator>`` and a ``<member>`` child elements.
Please, refer to :ref:`dynamictypes_supportedtypes_union` for more information on the ``<struct>`` type.

+----------------------------------------------------------------------------------------------------------------------+
| XML                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/XMLTester.xml                                                                           |
|   :language: xml                                                                                                     |
|   :start-after: <!-->XML-UNION<-->                                                                                   |
|   :end-before: <!--><-->                                                                                             |
+----------------------------------------------------------------------------------------------------------------------+
| C++                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/CodeTester.cpp                                                                          |
|   :language: c++                                                                                                     |
|   :start-after: //XML-UNION                                                                                          |
|   :end-before: //!--                                                                                                 |
|   :dedent: 8                                                                                                         |
+----------------------------------------------------------------------------------------------------------------------+

Bitset
""""""

The ``<bitset>`` element define the :ref:`dynamictypes_supportedtypes_union` type.
It is comprised by a ``name`` attribute and a set of ``<bitfield>`` child elements.
In turn, the ``<bitfield>`` element has the mandatory ``bit_bound`` attribute, which can not be higher than 64, and
two optional attributes:
``name`` and ``type``.
A ``<bitfield>`` with a blank ``name`` attribute is an inaccessible set of bits.
Its management ``type`` can ease the ``<bitfield>`` modification and access.
Please, refer to :ref:`dynamictypes_supportedtypes_bitset` for more information about the ``<bitset>`` type.

+----------------------------------------------------------------------------------------------------------------------+
| XML                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/XMLTester.xml                                                                           |
|   :language: xml                                                                                                     |
|   :start-after: <!-->XML-BITSET<-->                                                                                  |
|   :end-before: <!--><-->                                                                                             |
+----------------------------------------------------------------------------------------------------------------------+
| C++                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/CodeTester.cpp                                                                          |
|   :language: c++                                                                                                     |
|   :start-after: //XML-BITSET                                                                                         |
|   :end-before: //!--                                                                                                 |
|   :dedent: 8                                                                                                         |
+----------------------------------------------------------------------------------------------------------------------+

Moreover, bitsets can inherit from another bitsets:

+----------------------------------------------------------------------------------------------------------------------+
| XML                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/XMLTester.xml                                                                           |
|   :language: xml                                                                                                     |
|   :start-after: <!-->XML-BITSET-INHERIT<-->                                                                          |
|   :end-before: <!--><-->                                                                                             |
+----------------------------------------------------------------------------------------------------------------------+
| C++                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/CodeTester.cpp                                                                          |
|   :language: c++                                                                                                     |
|   :start-after: //XML-BITSET-INHERIT                                                                                 |
|   :end-before: //!--                                                                                                 |
|   :dedent: 8                                                                                                         |
+----------------------------------------------------------------------------------------------------------------------+

Bitmask
"""""""

The ``<bitmask>`` element, which corresponds to the :ref:`dynamictypes_supportedtypes_bitmask` type, is defined by
a mandatory ``name`` attribute, an optional ``bit_bound`` attribute, and several ``<bit_value>`` child elements.
The ``bit_bound`` attribute specifies the number of bits that the type will manage.
The maximum value allowed for the ``bit_bound`` is 64.
The ``<bit_value>`` element can define its position in the bitmask setting the ``positition`` attribute.
Please, refer to :ref:`dynamictypes_supportedtypes_bitmask` for more information on the ``<bitmask>`` type.

+----------------------------------------------------------------------------------------------------------------------+
| XML                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/XMLTester.xml                                                                           |
|   :language: xml                                                                                                     |
|   :start-after: <!-->XML-BITMASK<-->                                                                                 |
|   :end-before: <!--><-->                                                                                             |
+----------------------------------------------------------------------------------------------------------------------+
| C++                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/CodeTester.cpp                                                                          |
|   :language: c++                                                                                                     |
|   :start-after: //XML-BITMASK                                                                                        |
|   :end-before: //!--                                                                                                 |
|   :dedent: 8                                                                                                         |
+----------------------------------------------------------------------------------------------------------------------+

Member types
""""""""""""

Member types are defined as any type that can belong to a ``<struct>`` or a ``<union>``, or be aliased by a
``<typedef>``.
These can be defined by the ``<member>`` XML tag.

Primitive types
***************

The identifiers of the available basic types are listed in the table below.
Please, refer to :ref:`dynamictypes_supportedtypes_primitive` for more information on the primitive types.

+--------------------------------------+---------------------------------------+---------------------------------------+
| ``boolean``                          | ``int32``                             | ``float32``                           |
+--------------------------------------+---------------------------------------+---------------------------------------+
| ``byte``                             | ``int64``                             | ``float64``                           |
+--------------------------------------+---------------------------------------+---------------------------------------+
| ``char``                             | ``uint16``                            | ``float128``                          |
+--------------------------------------+---------------------------------------+---------------------------------------+
| ``wchar``                            | ``uint32``                            | ``string``                            |
+--------------------------------------+---------------------------------------+---------------------------------------+
| ``int16``                            | ``uint64``                            | ``wstring``                           |
+--------------------------------------+---------------------------------------+---------------------------------------+

All of them are defined as follows:

+----------------------------------------------------------------------------------------------------------------------+
| XML                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/XMLTester.xml                                                                           |
|   :language: xml                                                                                                     |
|   :start-after: <!-->XML-GENERIC<-->                                                                                 |
|   :end-before: <!--><-->                                                                                             |
+----------------------------------------------------------------------------------------------------------------------+
| C++                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/CodeTester.cpp                                                                          |
|   :language: c++                                                                                                     |
|   :start-after: //XML-GENERIC                                                                                        |
|   :end-before: //!--                                                                                                 |
|   :dedent: 8                                                                                                         |
+----------------------------------------------------------------------------------------------------------------------+

Arrays
******

Arrays are defined in the same way as any other member type but it adds the attribute ``arrayDimensions``.
The format of the ``arrayDimensions`` attribute value is the size of each dimension separated by commas.
Please, refer to :ref:`dynamictypes_supportedtypes_array` explanation for more information on array type.

+----------------------------------------------------------------------------------------------------------------------+
| XML                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/XMLTester.xml                                                                           |
|   :language: xml                                                                                                     |
|   :start-after: <!-->XML-ARRAYS<-->                                                                                  |
|   :end-before: <!--><-->                                                                                             |
+----------------------------------------------------------------------------------------------------------------------+
| C++                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/CodeTester.cpp                                                                          |
|   :language: c++                                                                                                     |
|   :start-after: //XML-ARRAYS                                                                                         |
|   :end-before: //!--                                                                                                 |
|   :dedent: 8                                                                                                         |
+----------------------------------------------------------------------------------------------------------------------+

Sequences
*********

The sequence type is implemented by setting three attributes: ``name``, the ``type``, and the
``sequenceMaxLength``.
The type of its content should be defined by the ``type`` attribute.
The following example shows the implementation of a sequence of maximum length equal to 3.
In turn, this is a sequence of sequences of maximum length of 2 and contents of type ``int32``.
Please, refer to :ref:`dynamictypes_supportedtypes_sequence` section for more information on sequence type.

+----------------------------------------------------------------------------------------------------------------------+
| XML                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/XMLTester.xml                                                                           |
|   :language: xml                                                                                                     |
|   :start-after: <!-->XML-SEQUENCES<-->                                                                               |
|   :end-before: <!--><-->                                                                                             |
+----------------------------------------------------------------------------------------------------------------------+
| C++                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/CodeTester.cpp                                                                          |
|   :language: c++                                                                                                     |
|   :start-after: //XML-SEQUENCES                                                                                      |
|   :end-before: //!--                                                                                                 |
|   :dedent: 8                                                                                                         |
+----------------------------------------------------------------------------------------------------------------------+

Maps
****

Maps are similar to sequences, but they need to define two content types.
The ``key_type`` defines the type of the map key, while the ``type`` defines the map value type.
Again, both types can be defined as attributes of a ``<typedef>`` element, or as a ``<member>`` child element of a
``<struct>`` or ``<union>`` elements.
See section :ref:`dynamictypes_supportedtypes_map` for more information on map type.

+----------------------------------------------------------------------------------------------------------------------+
| XML                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/XMLTester.xml                                                                           |
|   :language: xml                                                                                                     |
|   :start-after: <!-->XML-SEQUENCES<-->                                                                               |
|   :end-before: <!--><-->                                                                                             |
+----------------------------------------------------------------------------------------------------------------------+
| C++                                                                                                                  |
+----------------------------------------------------------------------------------------------------------------------+
| .. literalinclude:: /../code/CodeTester.cpp                                                                          |
|   :language: c++                                                                                                     |
|   :start-after: //XML-SEQUENCES                                                                                      |
|   :end-before: //!--                                                                                                 |
|   :dedent: 8                                                                                                         |
+----------------------------------------------------------------------------------------------------------------------+

Complex types
"""""""""""""

The complex types are a combination of the aforementioned types.
Complex types can be defined using the ``<member>`` element in the same way a basic or an array type would be.
Please, refer to :ref:`dynamictypes_complextypes` section for more information on complex types.

.. literalinclude:: /../code/XMLTester.xml
    :language: xml
    :start-after: <!-->XML-COMPLEX<-->
    :end-before: <!--><-->

.. _Usage:

Loading dynamic types in a Fast DDS application
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In the Fast DDS application that will make use of the *XML Types*, the XML profiles file that
defines the types must be loaded before trying to instantiate |DynamicPubSubType| objects of these types.
It is worth mentioning that only ``<struct>`` types generate usable |DynamicPubSubType| instances.

.. literalinclude:: /../code/CodeTester.cpp
    :language: c++
    :start-after: //XML-USAGE
    :end-before: //!--
    :dedent: 8