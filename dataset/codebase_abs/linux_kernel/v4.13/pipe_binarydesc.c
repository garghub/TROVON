static void F_1 (
struct V_1 const * const V_2 ,
const int V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_8 [] ,
struct V_6 * V_9 )
{
unsigned int V_10 ;
assert ( V_2 != NULL ) ;
assert ( V_5 != NULL ) ;
F_2 ( V_11 ,
L_1 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_12 = false ;
V_5 -> V_13 = V_2 -> V_14 -> V_15 . V_13 ;
V_5 -> V_16 = false ;
V_5 -> V_17 = false ;
V_5 -> V_18 = false ;
V_5 -> V_19 = false ;
V_5 -> V_20 = false ;
V_5 -> V_21 = false ;
V_5 -> V_22 = true ;
V_5 -> V_23 = false ;
V_5 -> V_24 = false ;
#ifdef F_3
V_5 -> V_25 = false ;
V_5 -> V_26 = false ;
#endif
V_5 -> V_27 = false ;
V_5 -> V_28 = false ;
V_5 -> V_29 . V_30 = 0 ;
V_5 -> V_29 . V_31 = 0 ;
V_5 -> V_32 = V_2 -> V_14 -> V_15 . V_33 . V_34 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_35 = NULL ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ )
V_5 -> V_8 [ V_10 ] = V_8 [ V_10 ] ;
V_5 -> V_9 = V_9 ;
V_5 -> V_37 = V_2 -> V_15 . V_37 ;
V_5 -> V_38 = V_39 ;
V_5 -> V_40 = - 1 ;
}
void F_4 (
struct V_1 const * const V_2 ,
struct V_4 * V_41 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
struct V_6 * V_9 )
{
struct V_6 * V_42 [ V_36 ] ;
unsigned int V_10 ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
F_5 ( L_2 ) ;
* V_7 = * V_8 ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 , V_43 ,
V_41 , V_7 , V_42 , V_9 ) ;
V_41 -> V_12 = true ;
V_41 -> V_13 = false ;
V_41 -> V_17 = ( V_2 -> V_14 -> V_15 . V_44 == 2 ) ;
V_41 -> V_22 = false ;
V_41 -> V_37 = V_45 ;
F_6 ( L_2 ) ;
}
void F_7 (
struct V_1 const * const V_2 ,
struct V_4 * V_46 ,
struct V_6 * V_7 ,
struct V_6 * V_8 )
{
struct V_6 * V_42 [ V_36 ] ;
unsigned int V_10 ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
F_5 ( L_2 ) ;
V_7 -> V_47 = 0 ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 , V_48 ,
V_46 , V_7 , V_42 , NULL ) ;
V_46 -> V_28 = true ;
F_6 ( L_2 ) ;
}
enum V_49 F_8 (
unsigned int V_50 ,
unsigned int * V_51 ,
unsigned int * V_52 )
{
unsigned int V_10 ;
unsigned int V_53 = sizeof( V_54 ) /
sizeof( struct V_55 ) ;
for ( V_10 = 0 ; V_10 < V_53 ; V_10 ++ ) {
if ( V_54 [ V_10 ] . V_50 == V_50 ) {
* V_51 = V_54 [ V_10 ] . V_56 ;
* V_52 = V_54 [ V_10 ] . V_57 ;
return V_58 ;
}
}
return V_59 ;
}
enum V_49 F_9 (
struct V_60 V_61 ,
struct V_60 V_62 ,
unsigned int * V_50 )
{
unsigned int V_10 ;
unsigned int V_53 = sizeof( V_54 ) /
sizeof( struct V_55 ) ;
unsigned int V_63 = V_61 . V_30 ,
V_64 = V_61 . V_31 ,
V_65 = V_62 . V_30 , V_66 = V_62 . V_31 ;
unsigned int V_67 = 8 ;
unsigned int V_68 = 2 ;
unsigned int V_69 = V_67 * V_68 ;
assert ( V_63 != 0 && V_64 != 0 ) ;
assert ( V_65 != 0 && V_66 != 0 ) ;
for ( V_10 = 0 ; V_10 < V_53 ; V_10 ++ ) {
unsigned V_70 = V_54 [ V_10 ] . V_56 ;
unsigned V_71 = V_54 [ V_10 ] . V_57 ;
bool V_72 = ( V_65 * V_70 / V_71 + V_69 > V_63 ) &&
( V_65 * V_70 / V_71 <= V_63 ) &&
( V_66 * V_70 / V_71 + V_69 > V_64 ) &&
( V_66 * V_70 / V_71 <= V_64 ) ;
if ( V_72 ) {
* V_50 = V_54 [ V_10 ] . V_50 ;
return V_58 ;
}
}
return V_59 ;
}
enum V_49 F_10 (
struct V_1 * const V_2 ,
struct V_4 * V_73 ,
struct V_6 * V_7 ,
struct V_6 * V_35 ,
struct V_6 * V_8 ,
struct V_6 * V_9 )
{
enum V_49 V_74 ;
struct V_6 * V_42 [ V_36 ] ;
int V_3 = V_75 ;
unsigned int V_10 ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
assert ( V_8 != NULL ) ;
assert ( V_9 != NULL ) ;
F_5 ( L_2 ) ;
V_7 -> V_76 = V_2 -> V_15 . V_77 ;
V_7 -> V_78 = V_7 -> V_76 . V_30 ;
V_7 -> V_47 = F_11 ( V_2 ) ;
if ( F_12 ( V_2 -> V_14 -> V_15 . V_33 . V_34 ) )
V_3 = V_43 ;
else
V_7 -> V_34 = V_79 ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 , V_3 ,
V_73 , V_7 , V_42 , V_9 ) ;
if ( V_2 -> V_14 -> V_15 . V_12 ) {
V_73 -> V_12 = V_2 -> V_14 -> V_15 . V_12 ;
V_73 -> V_17 =
( V_2 -> V_14 -> V_15 . V_44 == 2 ) ;
}
V_73 -> V_32 = V_2 -> V_14 -> V_15 . V_33 . V_34 ;
* V_35 = * V_7 ;
if ( V_2 -> V_80 . V_81 ) {
if ( V_2 -> V_15 . V_82 . V_30 != 0 &&
V_2 -> V_15 . V_82 . V_31 != 0 ) {
V_35 -> V_76 . V_30 =
V_2 -> V_15 . V_82 . V_30 ;
V_35 -> V_76 . V_31 =
V_2 -> V_15 . V_82 . V_31 ;
V_35 -> V_78 =
V_2 -> V_15 . V_82 . V_30 ;
V_74 =
F_9 ( V_7 -> V_76 ,
V_35 -> V_76 ,
& V_73 -> V_38 ) ;
if ( V_74 != V_58 )
return V_74 ;
} else {
V_35 -> V_76 . V_30 = V_7 -> V_76 . V_30 / 2 ;
V_35 -> V_76 . V_31 = V_7 -> V_76 . V_31 / 2 ;
V_35 -> V_78 = V_7 -> V_78 / 2 ;
V_73 -> V_38 =
V_83 ;
}
} else {
V_35 -> V_76 . V_30 = V_7 -> V_76 . V_30 ;
V_35 -> V_76 . V_31 = V_7 -> V_76 . V_31 ;
V_35 -> V_78 = V_7 -> V_78 ;
V_73 -> V_38 = V_39 ;
}
V_2 -> V_38 = V_73 -> V_38 ;
if ( ! V_2 -> V_80 . V_28 )
V_73 -> V_35 = V_35 ;
else
V_73 -> V_35 = NULL ;
* V_8 = * V_9 ;
if ( ! V_2 -> V_80 . V_28 ) {
V_8 -> V_76 . V_30 = V_35 -> V_76 . V_30 ;
V_8 -> V_76 . V_31 = V_35 -> V_76 . V_31 ;
V_8 -> V_78 = V_35 -> V_78 ;
}
V_73 -> V_28 =
V_2 -> V_80 . V_28 ;
V_73 -> V_24 = V_2 -> V_15 . V_24 ;
V_73 -> V_37 = V_2 -> V_15 . V_37 ;
F_13 ( V_58 ) ;
return V_58 ;
}
enum V_49 F_14 (
struct V_1 * const V_2 ,
struct V_4 * V_84 ,
struct V_6 * V_7 ,
struct V_6 * V_35 ,
struct V_6 * V_8 ,
struct V_6 * V_9 ,
int V_40 )
{
int V_3 = V_85 ;
unsigned int V_10 ;
struct V_6 * V_42 [ V_36 ] ;
enum V_49 V_74 = V_58 ;
bool V_86 = false ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
F_5 ( L_2 ) ;
if ( F_12 ( V_2 -> V_14 -> V_15 . V_33 . V_34 ) )
V_3 = V_43 ;
V_7 -> V_76 = V_2 -> V_15 . V_77 ;
V_7 -> V_78 = V_7 -> V_76 . V_30 ;
V_7 -> V_34 = V_79 ;
V_7 -> V_47 = F_11 ( V_2 ) ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 , V_3 ,
V_84 , V_7 , V_42 , V_9 ) ;
if ( V_2 -> V_14 -> V_15 . V_12 ) {
V_84 -> V_12 = V_2 -> V_14 -> V_15 . V_12 ;
V_84 -> V_17 =
( V_2 -> V_14 -> V_15 . V_44 == 2 ) ;
}
if ( V_3 == V_85 ) {
V_86 =
( ( V_2 -> V_14 -> V_87 -> V_88 . V_89 !=
V_90 )
|| ( V_2 -> V_14 -> V_87 -> V_88 . V_91 !=
V_90 ) ) ;
V_84 -> V_22 = V_2 -> V_15 . V_22
|| V_86 ;
V_84 -> V_29 = V_2 -> V_15 . V_92 ;
V_84 -> V_18 = V_2 -> V_80 . V_18 ;
V_84 -> V_19 =
V_2 -> V_80 . V_19 ;
V_84 -> V_20 =
V_2 -> V_80 . V_20 ;
V_84 -> V_21 =
V_2 -> V_80 . V_21 ;
V_84 -> V_37 = V_2 -> V_15 . V_37 ;
V_84 -> V_28 =
V_2 -> V_80 . V_28 ;
V_84 -> V_24 =
V_2 -> V_15 . V_24 ;
#ifdef F_3
V_84 -> V_25 =
V_2 -> V_15 . V_25 ;
V_84 -> V_26 =
V_2 -> V_15 . V_26 ;
#endif
if ( V_2 -> V_80 . V_81 ) {
if ( V_2 -> V_15 . V_82 . V_30 != 0 &&
V_2 -> V_15 . V_82 . V_31 != 0 ) {
V_35 -> V_76 . V_30 =
V_2 -> V_15 . V_82 . V_30 ;
V_35 -> V_76 . V_31 =
V_2 -> V_15 . V_82 . V_31 ;
V_35 -> V_78 =
V_2 -> V_15 . V_82 . V_30 ;
V_74 =
F_9 (
V_7 -> V_76 , V_35 -> V_76 ,
& V_84 -> V_38 ) ;
if ( V_74 != V_58 )
return V_74 ;
} else {
V_35 -> V_76 . V_30 =
V_7 -> V_76 . V_30 / 2 ;
V_35 -> V_76 . V_31 =
V_7 -> V_76 . V_31 / 2 ;
V_35 -> V_78 =
V_7 -> V_78 / 2 ;
V_84 -> V_38 =
V_83 ;
}
} else {
V_35 -> V_76 . V_30 = V_7 -> V_76 . V_30 ;
V_35 -> V_76 . V_31 = V_7 -> V_76 . V_31 ;
V_35 -> V_78 = V_7 -> V_78 ;
V_84 -> V_38 =
V_39 ;
}
V_2 -> V_38 = V_84 -> V_38 ;
if ( ! V_2 -> V_80 . V_28 )
V_84 -> V_35 = V_35 ;
else
V_84 -> V_35 = NULL ;
V_84 -> V_28 =
V_2 -> V_80 . V_28 ;
V_84 -> V_40 = V_40 ;
}
F_13 ( V_74 ) ;
return V_74 ;
}
void F_15 (
struct V_1 const * const V_2 ,
struct V_4 * V_93 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
struct V_6 * V_94 ,
struct V_6 * V_9 )
{
struct V_6 * V_42 [ V_36 ] ;
struct V_6 * V_95 = NULL ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
assert ( V_36 == 2 ) ;
F_5 ( L_2 ) ;
V_7 -> V_78 = V_7 -> V_76 . V_30 ;
V_7 -> V_47 = 0 ;
F_16 ( V_7 , V_7 -> V_76 . V_30 , 0 ) ;
V_42 [ 0 ] = V_8 ;
V_42 [ 1 ] = V_94 ;
if ( V_9 ) {
V_95 = ( V_9 -> V_76 . V_30 == 0 &&
V_9 -> V_76 . V_31 == 0 ) ? NULL : V_9 ;
}
F_1 ( V_2 ,
V_96 ,
V_93 ,
V_7 , V_42 , V_95 ) ;
V_93 -> V_28 = true ;
F_6 ( L_2 ) ;
}
void F_17 (
struct V_1 * const V_2 ,
struct V_4 * V_97 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
struct V_6 * V_9 )
{
unsigned int V_10 ;
struct V_6 * V_42 [ V_36 ] ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
assert ( V_9 != NULL ) ;
F_5 ( L_2 ) ;
if ( V_2 -> V_98 . V_76 . V_30 )
* V_7 = V_2 -> V_98 ;
else
* V_7 = * V_8 ;
V_7 -> V_34 = V_99 ;
V_7 -> V_47 = 0 ;
F_16 ( V_7 , V_7 -> V_76 . V_30 , 0 ) ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 ,
V_96 ,
V_97 ,
V_7 , V_42 , V_9 ) ;
V_97 -> V_27 =
V_2 -> V_15 . V_100 . V_27 ;
V_97 -> V_28 = true ;
V_97 -> V_23 =
V_2 -> V_15 . V_100 . V_23 != 0 ;
F_6 ( L_2 ) ;
}
void F_18 (
struct V_1 const * const V_2 ,
struct V_4 * V_101 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
struct V_6 * V_9 ,
unsigned int V_102 )
{
enum V_103 V_104 = V_2 -> V_15 . V_37 ;
int V_3 ;
unsigned int V_10 ;
struct V_6 * V_42 [ V_36 ] ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
assert ( V_8 != NULL ) ;
assert ( V_102 < V_105 ) ;
F_5 ( L_2 ) ;
if ( V_104 == V_106 )
V_3 = V_107 [ V_102 ] ;
else
V_3 = V_108 ;
if ( F_12 ( V_2 -> V_14 -> V_15 . V_33 . V_34 ) )
V_3 = V_43 ;
V_7 -> V_76 = V_2 -> V_15 . V_77 ;
V_7 -> V_78 = V_7 -> V_76 . V_30 ;
#if ! F_19 ( V_109 )
if ( V_2 -> V_14 -> V_15 . V_110 )
V_7 -> V_34 = V_111 ;
else
#endif
V_7 -> V_34 = V_79 ;
V_7 -> V_47 = F_11 ( V_2 ) ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 , V_3 ,
V_101 , V_7 , V_42 , V_9 ) ;
if ( V_2 -> V_14 -> V_15 . V_12 &&
V_2 -> V_14 -> V_15 . V_3 != V_112 ) {
V_101 -> V_12 = true ;
V_101 -> V_17 =
( V_2 -> V_14 -> V_15 . V_44 == 2 ) ;
V_101 -> V_32 = V_2 -> V_14 -> V_15 . V_33 . V_34 ;
}
if ( V_3 == V_108 ) {
V_101 -> V_37 = V_2 -> V_15 . V_37 ;
V_101 -> V_28 =
V_2 -> V_80 . V_28 ;
#ifdef F_3
V_101 -> V_25 =
V_2 -> V_15 . V_25 ;
#endif
if ( V_104 == V_106 )
V_101 -> V_16 = false ;
else
#ifndef F_3
V_101 -> V_16 = V_101 -> V_13 && ( ! V_2 -> V_14 -> V_113 || ! V_2 -> V_14 -> V_114 ) ;
#else
V_101 -> V_16 = V_101 -> V_13 && ! V_2 -> V_14 -> V_114 ;
if ( ( V_2 -> V_15 . V_100 . V_23 != 0 ) &&
( V_2 -> V_80 . V_20 == true ) )
V_101 -> V_23 = true ;
#endif
}
F_6 ( L_2 ) ;
}
void F_20 (
struct V_1 const * const V_2 ,
struct V_4 * V_115 ,
struct V_6 * V_7 ,
struct V_6 * V_8 )
{
unsigned int V_10 ;
struct V_6 * V_42 [ V_36 ] ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
assert ( V_8 != NULL ) ;
F_5 ( L_2 ) ;
* V_7 = * V_8 ;
V_7 -> V_34 = V_79 ;
V_7 -> V_47 = F_11 ( V_2 ) ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 , V_116 ,
V_115 , V_7 , V_42 , NULL ) ;
V_115 -> V_37 = V_2 -> V_15 . V_37 ;
F_6 ( L_2 ) ;
}
void F_21 (
struct V_1 const * const V_2 ,
struct V_4 * V_117 ,
struct V_6 * V_7 ,
struct V_6 * V_8 )
{
unsigned int V_10 ;
struct V_6 * V_42 [ V_36 ] ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
assert ( V_8 != NULL ) ;
F_5 ( L_2 ) ;
* V_7 = * V_8 ;
V_7 -> V_34 = V_118 ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 , V_119 ,
V_117 , V_7 , V_42 , NULL ) ;
F_6 ( L_2 ) ;
}
void F_22 (
struct V_1 const * const V_2 ,
struct V_4 * V_120 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
struct V_6 * V_9 )
{
unsigned int V_10 ;
struct V_6 * V_42 [ V_36 ] ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
assert ( V_8 != NULL ) ;
assert ( V_9 != NULL ) ;
F_5 ( L_2 ) ;
* V_7 = * V_8 ;
V_7 -> V_34 = V_121 ;
V_7 -> V_47 = 16 ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 , V_122 ,
V_120 , V_7 , V_42 , V_9 ) ;
V_120 -> V_37 = V_2 -> V_15 . V_37 ;
F_6 ( L_2 ) ;
}
void F_23 (
struct V_1 const * const V_2 ,
struct V_4 * V_123 ,
struct V_6 * V_7 ,
struct V_6 * V_8 )
{
unsigned int V_10 ;
struct V_6 * V_42 [ V_36 ] ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
assert ( V_8 != NULL ) ;
F_5 ( L_2 ) ;
* V_7 = * V_8 ;
V_7 -> V_34 = V_79 ;
V_7 -> V_47 = F_11 ( V_2 ) ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
if ( V_2 -> V_15 . V_37 == V_45 )
F_1 ( V_2 , V_116 ,
V_123 , V_7 , V_42 , NULL ) ;
else if ( V_2 -> V_15 . V_37 == V_124 ) {
F_1 ( V_2 , V_125 ,
V_123 , V_7 , V_42 , NULL ) ;
}
if ( V_2 -> V_14 -> V_15 . V_12 ) {
V_123 -> V_12 = true ;
V_123 -> V_17 =
( V_2 -> V_14 -> V_15 . V_44 == 2 ) ;
V_123 -> V_32 = V_2 -> V_14 -> V_15 . V_33 . V_34 ;
}
V_123 -> V_37 = V_2 -> V_15 . V_37 ;
F_6 ( L_2 ) ;
}
void F_24 (
struct V_1 const * const V_2 ,
struct V_4 * V_126 ,
struct V_6 * V_7 ,
struct V_6 * V_8 )
{
unsigned int V_10 ;
struct V_6 * V_42 [ V_36 ] ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
assert ( V_8 != NULL ) ;
F_5 ( L_2 ) ;
* V_7 = * V_8 ;
V_7 -> V_34 = V_79 ;
V_7 -> V_47 = F_11 ( V_2 ) ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 , V_116 ,
V_126 , V_7 , V_42 , NULL ) ;
if ( V_2 -> V_14 -> V_15 . V_12 ) {
V_126 -> V_12 = true ;
V_126 -> V_17 =
( V_2 -> V_14 -> V_15 . V_44 == 2 ) ;
V_126 -> V_32 = V_2 -> V_14 -> V_15 . V_33 . V_34 ;
}
V_126 -> V_37 = V_2 -> V_15 . V_37 ;
F_6 ( L_2 ) ;
}
void F_25 (
struct V_1 const * const V_2 ,
struct V_4 * V_127 ,
struct V_6 * V_7 ,
struct V_6 * V_8 )
{
unsigned int V_10 ;
struct V_6 * V_42 [ V_36 ] ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
assert ( V_8 != NULL ) ;
F_5 ( L_2 ) ;
* V_7 = * V_8 ;
V_7 -> V_34 = V_79 ;
V_7 -> V_47 = V_128 ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 , V_129 ,
V_127 , V_7 , V_42 , NULL ) ;
V_127 -> V_37 = V_2 -> V_15 . V_37 ;
F_6 ( L_2 ) ;
}
void F_26 (
struct V_1 const * const V_2 ,
struct V_4 * V_130 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
struct V_6 * V_9 )
{
unsigned int V_10 ;
struct V_6 * V_42 [ V_36 ] ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
assert ( V_8 != NULL ) ;
assert ( V_9 != NULL ) ;
F_5 ( L_2 ) ;
* V_7 = * V_8 ;
V_7 -> V_34 = V_79 ;
V_7 -> V_47 = V_128 ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 , V_122 ,
V_130 , V_7 , V_42 , V_9 ) ;
V_130 -> V_37 = V_2 -> V_15 . V_37 ;
F_6 ( L_2 ) ;
}
void F_27 (
struct V_1 const * const V_2 ,
struct V_4 * V_131 ,
struct V_6 * V_7 ,
struct V_6 * V_8 )
{
unsigned int V_10 ;
struct V_6 * V_42 [ V_36 ] ;
assert ( V_2 != NULL ) ;
assert ( V_7 != NULL ) ;
assert ( V_8 != NULL ) ;
F_5 ( L_2 ) ;
#ifndef F_3
* V_7 = * V_8 ;
#else
if ( V_2 -> V_98 . V_76 . V_30 )
* V_7 = V_2 -> V_98 ;
else
* V_7 = * V_8 ;
#endif
V_7 -> V_34 = V_99 ;
V_7 -> V_47 = 0 ;
F_16 ( V_7 , V_7 -> V_76 . V_30 , 0 ) ;
V_42 [ 0 ] = V_8 ;
for ( V_10 = 1 ; V_10 < V_36 ; V_10 ++ )
V_42 [ V_10 ] = NULL ;
F_1 ( V_2 , V_96 ,
V_131 , V_7 , V_42 , NULL ) ;
V_131 -> V_20 =
V_2 -> V_80 . V_20 ;
F_6 ( L_2 ) ;
}
