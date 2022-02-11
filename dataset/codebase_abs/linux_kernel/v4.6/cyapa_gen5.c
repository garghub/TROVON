int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
F_2 ( & V_3 -> V_5 ) ;
F_3 ( & V_3 -> V_6 , 0 ) ;
F_4 ( & V_3 -> V_7 ) ;
F_4 ( & V_3 -> V_8 ) ;
V_3 -> V_9 = V_10 ;
V_3 -> V_11 = NULL ;
V_3 -> V_12 = V_13 ;
V_3 -> V_14 = NULL ;
V_3 -> V_15 = NULL ;
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = V_19 ;
return 0 ;
}
T_1 F_5 ( struct V_1 * V_1 , T_2 * V_20 , T_3 V_21 )
{
int V_22 ;
if ( V_21 == 0 )
return 0 ;
if ( ! V_20 || V_21 > V_23 )
return - V_24 ;
V_22 = F_6 ( V_1 -> V_25 , V_20 , V_21 ) ;
if ( V_22 != V_21 )
return ( V_22 < 0 ) ? V_22 : - V_26 ;
return V_21 ;
}
T_1 F_7 ( struct V_1 * V_1 , T_2 * V_20 , T_3 V_21 )
{
int V_22 ;
if ( ! V_20 || ! V_21 )
return - V_24 ;
V_22 = F_8 ( V_1 -> V_25 , V_20 , V_21 ) ;
if ( V_22 != V_21 )
return ( V_22 < 0 ) ? V_22 : - V_26 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_1 ,
enum V_27 V_9 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
F_10 ( & V_3 -> V_8 ) ;
V_3 -> V_9 = V_9 ;
F_11 ( & V_3 -> V_8 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
F_10 ( & V_3 -> V_8 ) ;
V_3 -> V_9 = V_10 ;
F_11 ( & V_3 -> V_8 ) ;
}
static enum V_27 F_13 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
enum V_27 V_9 ;
F_10 ( & V_3 -> V_8 ) ;
V_9 = V_3 -> V_9 ;
F_11 ( & V_3 -> V_8 ) ;
return V_9 ;
}
int F_14 ( struct V_1 * V_1 ,
T_2 * V_20 , int * V_28 , T_4 V_29 )
{
struct V_30 * V_31 = V_1 -> V_31 ;
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
enum V_27 V_9 = F_13 ( V_1 ) ;
int V_32 ;
int V_33 ;
int V_34 ;
int V_35 ;
int error ;
V_35 = 0 ;
if ( V_28 ) {
V_35 = ( * V_28 < V_23 ) ?
* V_28 : V_23 ;
* V_28 = 0 ;
}
V_33 = 8 ;
V_34 = 0 ;
do {
if ( V_34 > 5 )
return 0 ;
error = F_5 ( V_1 , V_3 -> V_36 ,
V_37 ) ;
if ( error < 0 )
return error ;
V_32 = F_15 ( V_3 -> V_36 ) ;
if ( V_32 == V_37 ) {
V_34 ++ ;
continue;
} else if ( V_32 > V_23 ) {
return - V_24 ;
} else if ( V_32 == 0 ) {
V_32 = V_37 ;
if ( V_20 && V_35 && V_29 &&
V_29 ( V_1 , V_3 -> V_36 , V_32 ) ) {
V_32 = F_16 ( V_35 , V_32 ) ;
memcpy ( V_20 , V_3 -> V_36 , V_32 ) ;
* V_28 = V_32 ;
return 0 ;
}
continue;
}
error = F_5 ( V_1 , V_3 -> V_36 , V_32 ) ;
if ( error < 0 )
return error ;
V_33 -- ;
V_34 = 0 ;
V_32 = F_15 ( V_3 -> V_36 ) ;
if ( V_32 <= V_37 ) {
V_34 ++ ;
} else if ( V_20 && V_35 && V_29 &&
V_29 ( V_1 , V_3 -> V_36 , V_32 ) ) {
V_32 = F_16 ( V_35 , V_32 ) ;
memcpy ( V_20 , V_3 -> V_36 , V_32 ) ;
* V_28 = V_32 ;
return 0 ;
} else if ( V_1 -> V_38 && V_31 && V_31 -> V_39 &&
( V_9 == V_40 ||
V_9 == V_41 ) ) {
F_17 ( V_1 ,
(struct V_42 * ) V_3 -> V_36 ) ;
}
error = - V_24 ;
} while ( V_33 );
return error ;
}
static int F_18 (
struct V_1 * V_1 ,
T_2 * V_43 , T_3 V_44 ,
unsigned long V_45 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int error ;
F_2 ( & V_3 -> V_5 ) ;
F_19 ( & V_3 -> V_6 ) ;
error = F_7 ( V_1 , V_43 , V_44 ) ;
if ( error ) {
F_20 ( & V_3 -> V_6 ) ;
return ( error < 0 ) ? error : - V_26 ;
}
V_45 = F_21 ( & V_3 -> V_5 ,
F_22 ( V_45 ) ) ;
if ( V_45 == 0 ) {
F_20 ( & V_3 -> V_6 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_23 (
struct V_1 * V_1 ,
T_2 * V_43 , T_3 V_44 ,
T_2 * V_14 , int * V_15 ,
unsigned long V_45 ,
T_4 V_29 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int V_47 ;
int V_32 ;
int error ;
F_19 ( & V_3 -> V_6 ) ;
error = F_7 ( V_1 , V_43 , V_44 ) ;
if ( error ) {
F_20 ( & V_3 -> V_6 ) ;
return error < 0 ? error : - V_26 ;
}
V_32 = V_15 ? * V_15 : 0 ;
if ( V_14 && V_15 && V_32 != 0 && V_29 ) {
V_47 = V_45 / 5 ;
do {
F_24 ( 3000 , 5000 ) ;
* V_15 = V_32 ;
error = F_14 ( V_1 ,
V_14 , V_15 , V_29 ) ;
if ( error || * V_15 == 0 )
continue;
else
break;
} while ( -- V_47 > 0 );
if ( ( error || * V_15 == 0 ) || V_47 <= 0 )
error = error ? error : - V_46 ;
}
F_20 ( & V_3 -> V_6 ) ;
return error ;
}
int F_25 (
struct V_1 * V_1 ,
T_2 * V_43 , int V_44 ,
T_2 * V_14 , int * V_15 ,
unsigned long V_45 ,
T_4 V_29 ,
bool V_48 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int error ;
if ( ! V_43 || ! V_44 )
return - V_24 ;
error = F_26 ( & V_3 -> V_7 ) ;
if ( error )
return error ;
V_3 -> V_11 = V_29 ;
V_3 -> V_14 = V_14 ;
V_3 -> V_15 = V_15 ;
if ( V_44 >= V_49 &&
V_43 [ 4 ] == V_50 ) {
V_3 -> V_12 = V_43 [ 6 ] & 0x7f ;
} else if ( V_44 >= V_51 &&
V_43 [ 4 ] == V_52 ) {
V_3 -> V_12 = V_43 [ 7 ] ;
}
if ( V_48 ) {
V_3 -> V_53 = true ;
error = F_18 ( V_1 , V_43 , V_44 ,
V_45 ) ;
if ( error == - V_46 && V_14 &&
V_15 && * V_15 != 0 && V_29 ) {
error = F_14 ( V_1 ,
V_14 , V_15 , V_29 ) ;
if ( error || * V_15 == 0 )
error = error ? error : - V_46 ;
}
} else {
V_3 -> V_53 = false ;
error = F_23 ( V_1 , V_43 , V_44 ,
V_14 , V_15 , V_45 , V_29 ) ;
}
V_3 -> V_11 = NULL ;
V_3 -> V_14 = NULL ;
V_3 -> V_15 = NULL ;
V_3 -> V_12 = V_13 ;
F_11 ( & V_3 -> V_7 ) ;
return error ;
}
bool F_27 ( struct V_1 * V_1 ,
T_2 * V_54 , int V_28 )
{
if ( ! V_54 || V_28 < V_55 )
return false ;
if ( V_54 [ V_56 ] == V_57 &&
V_54 [ V_58 ] == V_59 &&
V_54 [ V_60 ] == V_61 )
return true ;
return false ;
}
bool F_28 ( struct V_1 * V_1 ,
T_2 * V_54 , int V_28 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int V_15 ;
if ( ! V_54 || V_28 < V_62 )
return false ;
if ( V_54 [ V_56 ] == V_63 &&
V_54 [ V_58 ] == V_59 ) {
V_15 = F_15 ( & V_54 [ V_64 ] ) ;
if ( F_29 ( V_54 [ V_65 ] ) == 0x00 &&
V_15 == V_66 &&
V_54 [ 5 ] == V_3 -> V_12 ) {
return false ;
} else if ( F_29 ( V_54 [ V_65 ] ) ==
V_3 -> V_12 ) {
return true ;
}
}
return false ;
}
static bool F_30 ( struct V_1 * V_1 ,
T_2 * V_20 , int V_28 )
{
if ( V_20 == NULL || V_28 < V_37 )
return false ;
if ( V_20 [ 0 ] == 0 && V_20 [ 1 ] == 0 )
return true ;
return false ;
}
static bool F_31 ( struct V_1 * V_1 ,
T_2 * V_20 , int V_28 )
{
int V_15 ;
int V_67 ;
if ( V_28 != V_68 )
return false ;
V_15 = F_15 ( & V_20 [ V_64 ] ) ;
V_67 = F_15 ( & V_20 [ 16 ] ) ;
if ( V_15 == V_68 ) {
if ( V_20 [ V_56 ] == V_69 &&
V_67 == V_70 ) {
return true ;
} else if ( ( V_20 [ V_56 ] ==
V_71 ) &&
V_67 == V_72 ) {
return true ;
}
}
return false ;
}
static bool F_32 ( struct V_1 * V_1 ,
T_2 * V_20 , int V_28 )
{
if ( V_28 == V_73 &&
V_20 [ V_56 ] ==
V_74 &&
( V_20 [ 4 ] & V_75 ) ==
V_76 )
return true ;
return false ;
}
static int F_33 ( struct V_1 * V_1 )
{
T_2 V_14 [ V_68 ] ;
int V_67 ;
int V_32 ;
T_2 V_43 [ 2 ] ;
int V_22 ;
int error ;
F_14 ( V_1 , NULL , NULL , NULL ) ;
memset ( V_14 , 0 , sizeof( V_14 ) ) ;
V_22 = F_5 ( V_1 , V_14 , 3 ) ;
if ( V_22 != 3 )
return V_22 < 0 ? V_22 : - V_26 ;
V_32 = F_15 ( & V_14 [ V_64 ] ) ;
if ( V_32 == V_37 ) {
V_1 -> V_77 = V_78 ;
F_14 ( V_1 , NULL , NULL , NULL ) ;
V_43 [ 0 ] = 0x01 ;
V_43 [ 1 ] = 0x00 ;
V_32 = V_68 ;
error = F_25 ( V_1 ,
V_43 , V_37 ,
V_14 , & V_32 ,
300 ,
F_31 ,
false ) ;
if ( error )
return error ;
V_32 = F_15 (
& V_14 [ V_64 ] ) ;
V_67 = F_15 ( & V_14 [ 16 ] ) ;
if ( ( V_32 == V_68 ||
V_32 == V_37 ) &&
( V_14 [ V_56 ] ==
V_69 ) &&
V_67 == V_70 ) {
V_1 -> V_79 = V_80 ;
} else if ( ( V_32 == V_68 ||
V_32 == V_37 ) &&
( V_14 [ V_56 ] ==
V_71 ) &&
V_67 == V_72 ) {
V_1 -> V_79 = V_81 ;
} else {
V_1 -> V_79 = V_82 ;
}
}
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , T_2 * V_83 )
{
int V_32 ;
T_2 V_14 [ 32 ] ;
int V_67 ;
int V_22 ;
V_22 = F_5 ( V_1 , V_14 ,
V_68 ) ;
if ( V_22 != V_68 )
return V_22 < 0 ? V_22 : - V_26 ;
V_32 = F_15 ( & V_14 [ V_64 ] ) ;
V_67 = F_15 ( & V_14 [ 16 ] ) ;
if ( V_32 == V_37 ) {
if ( V_83 [ V_56 ] ==
V_69 ) {
V_1 -> V_77 = V_78 ;
V_1 -> V_79 = V_80 ;
} else {
V_1 -> V_77 = V_78 ;
V_1 -> V_79 = V_81 ;
}
} else if ( V_32 == V_68 &&
V_14 [ 2 ] == V_69 &&
V_67 == V_70 ) {
V_1 -> V_77 = V_78 ;
V_1 -> V_79 = V_80 ;
} else if ( V_32 == V_68 &&
( V_14 [ V_56 ] ==
V_71 ) &&
V_67 == V_72 ) {
V_1 -> V_77 = V_78 ;
V_1 -> V_79 = V_81 ;
} else {
V_1 -> V_79 = V_82 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , T_2 * V_83 )
{
int V_32 ;
V_32 = F_15 ( & V_83 [ V_64 ] ) ;
switch ( V_83 [ V_56 ] ) {
case V_84 :
if ( V_32 < V_85 ||
V_32 > V_86 )
return - V_24 ;
break;
case V_87 :
case V_88 :
case V_89 :
if ( V_32 < V_90 ||
V_32 > V_91 )
return - V_24 ;
break;
case V_92 :
if ( V_32 != V_93 )
return - V_24 ;
break;
default:
return - V_24 ;
}
V_1 -> V_77 = V_78 ;
V_1 -> V_79 = V_81 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_1 , T_2 * V_83 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int V_32 ;
int V_22 ;
V_32 = F_15 ( & V_83 [ V_64 ] ) ;
V_22 = F_5 ( V_1 , V_3 -> V_36 , V_32 ) ;
if ( V_22 != V_32 )
return V_22 < 0 ? V_22 : - V_26 ;
if ( V_32 == V_37 ) {
if ( V_83 [ V_56 ] ==
V_57 ) {
V_1 -> V_77 = V_78 ;
V_1 -> V_79 = V_80 ;
} else {
V_1 -> V_77 = V_78 ;
V_1 -> V_79 = V_81 ;
}
} else if ( ( V_3 -> V_36 [ V_56 ] ==
V_57 ) &&
( V_3 -> V_36 [ V_58 ] ==
V_59 ) &&
( V_3 -> V_36 [ V_60 ] ==
V_61 ) &&
( V_3 -> V_36 [ V_32 - 1 ] ==
V_94 ) ) {
V_1 -> V_77 = V_78 ;
V_1 -> V_79 = V_80 ;
} else if ( V_3 -> V_36 [ V_56 ] ==
V_63 &&
V_3 -> V_36 [ V_58 ] ==
V_59 ) {
V_1 -> V_77 = V_78 ;
V_1 -> V_79 = V_81 ;
} else {
V_1 -> V_79 = V_82 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , T_2 * V_83 , int V_28 )
{
int V_32 ;
if ( ! V_83 || V_28 < 3 )
return - V_24 ;
V_1 -> V_79 = V_82 ;
V_32 = F_15 ( & V_83 [ V_64 ] ) ;
if ( V_32 == 0 || V_32 == V_37 ) {
F_33 ( V_1 ) ;
} else if ( V_32 == V_68 &&
( V_83 [ 2 ] == V_69 ||
V_83 [ 2 ] == V_71 ) ) {
F_34 ( V_1 , V_83 ) ;
} else if ( ( V_32 == V_95 ||
V_32 == V_96 ) &&
V_83 [ 2 ] == V_97 ) {
V_1 -> V_77 = V_78 ;
V_1 -> V_79 = V_81 ;
} else if ( V_32 == V_98 &&
V_83 [ 2 ] == V_99 ) {
V_1 -> V_77 = V_78 ;
V_1 -> V_79 = V_80 ;
} else if ( V_83 [ 2 ] == V_84 ||
V_83 [ 2 ] == V_87 ||
V_83 [ 2 ] == V_88 ||
V_83 [ 2 ] == V_89 ||
V_83 [ 2 ] == V_92 ) {
F_35 ( V_1 , V_83 ) ;
} else if ( V_83 [ 2 ] == V_57 ||
V_83 [ 2 ] == V_63 ) {
F_36 ( V_1 , V_83 ) ;
}
if ( V_1 -> V_77 == V_78 ) {
F_14 ( V_1 , NULL , NULL , NULL ) ;
if ( V_1 -> V_79 == V_81 ||
V_1 -> V_79 == V_80 )
return 0 ;
}
return - V_100 ;
}
static struct V_101 *
F_38 ( const struct V_102 * V_103 ,
int * V_104 )
{
int V_105 ;
V_105 = V_103 -> V_54 [ 0 ] + 1 ;
* V_104 = ( V_103 -> V_21 - V_105 ) /
sizeof( struct V_101 ) ;
return (struct V_101 * ) & V_103 -> V_54 [ V_105 ] ;
}
int F_39 ( struct V_1 * V_1 , const struct V_102 * V_103 )
{
struct V_101 * V_106 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
struct V_113 * V_114 ;
T_2 V_43 [ V_115 ] ;
int V_44 ;
T_5 V_116 ;
T_5 V_117 = 0 ;
T_5 V_118 = 0 ;
T_2 V_14 [ 11 ] ;
int V_15 ;
int V_119 ;
T_2 * V_54 ;
int error ;
F_14 ( V_1 , NULL , NULL , NULL ) ;
memset ( V_43 , 0 , V_115 ) ;
V_108 = (struct V_107 * ) V_43 ;
V_116 = V_120 + V_121 ;
V_44 = sizeof( struct V_107 ) + V_116 +
sizeof( struct V_113 ) ;
F_40 ( V_122 , & V_108 -> V_123 ) ;
F_40 ( V_44 - 2 , & V_108 -> V_32 ) ;
V_108 -> V_124 = V_52 ;
V_110 = & V_108 -> V_125 ;
V_110 -> V_126 = V_61 ;
V_110 -> V_127 = V_128 ;
F_40 ( V_116 , & V_110 -> V_129 ) ;
V_112 = (struct V_111 * ) V_108 -> V_54 ;
memcpy ( V_112 -> V_130 , V_131 , V_120 ) ;
V_106 = F_38 ( V_103 , & V_119 ) ;
V_54 = V_106 [ V_119 - 1 ] . V_132 ;
memcpy ( V_112 -> V_133 , V_54 ,
V_134 ) ;
V_118 = F_41 ( 0xffff , V_112 -> V_133 ,
V_134 ) ;
F_40 ( V_118 , & V_112 -> V_135 ) ;
V_114 = (struct V_113 * ) ( V_108 -> V_54 +
V_116 ) ;
V_117 = F_41 ( 0xffff , ( T_2 * ) V_110 ,
sizeof( struct V_109 ) + V_116 ) ;
F_40 ( V_117 , & V_114 -> V_136 ) ;
V_114 -> V_137 = V_94 ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 ,
V_43 , V_44 ,
V_14 , & V_15 , 12000 ,
F_27 , true ) ;
if ( error || V_15 != V_138 ||
V_14 [ 2 ] != V_57 ||
! F_42 ( V_14 ) )
return error ? error : - V_100 ;
return 0 ;
}
static bool F_43 ( struct V_1 * V_1 , T_2 * V_20 , int V_28 )
{
if ( V_20 == NULL || V_28 < V_37 )
return false ;
if ( V_20 [ 0 ] == 0 && V_20 [ 1 ] == 0 )
return true ;
if ( V_28 == V_139 &&
V_20 [ V_56 ] ==
V_57 &&
V_20 [ V_58 ] == V_59 &&
V_20 [ V_60 ] == V_61 &&
V_20 [ 10 ] == V_94 )
return true ;
return false ;
}
int F_44 ( struct V_1 * V_1 )
{
T_2 V_140 [] = { 0x04 , 0x00 ,
0x0B , 0x00 , 0x40 , 0x00 , 0x01 , 0x3b , 0x00 , 0x00 ,
0x20 , 0xc7 , 0x17
} ;
T_2 V_14 [ 11 ] ;
int V_15 ;
int error ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 ,
V_140 , sizeof( V_140 ) ,
V_14 , & V_15 ,
5000 , F_43 , false ) ;
if ( error )
return error ;
if ( V_15 == V_139 ||
V_14 [ V_56 ] ==
V_57 )
return - V_100 ;
if ( V_14 [ 0 ] == 0x00 && V_14 [ 1 ] == 0x00 )
return 0 ;
return - V_141 ;
}
int F_45 ( struct V_1 * V_1 )
{
T_2 V_43 [] = { 0x04 , 0x00 , 0x05 , 0x00 , 0x2F , 0x00 , 0x01 } ;
T_2 V_14 [ 2 ] ;
int V_15 ;
int error ;
error = F_46 ( V_1 , 500 ) ;
if ( error < 0 )
return error ;
if ( F_47 ( V_1 ) )
return 0 ;
else if ( ! F_48 ( V_1 ) )
return - V_24 ;
F_14 ( V_1 , NULL , NULL , NULL ) ;
V_15 = sizeof( V_14 ) ;
memset ( V_14 , 0 , V_15 ) ;
error = F_25 ( V_1 ,
V_43 , sizeof( V_43 ) ,
V_14 , & V_15 ,
5000 , F_30 ,
true ) ;
if ( error || V_14 [ 0 ] != 0x00 || V_14 [ 1 ] != 0x00 )
return error < 0 ? error : - V_100 ;
V_1 -> V_38 = false ;
if ( V_1 -> V_77 == V_78 )
V_1 -> V_79 = V_80 ;
else if ( V_1 -> V_77 == V_142 )
V_1 -> V_79 = V_143 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_1 ,
struct V_144 * V_145 )
{
if ( V_145 -> V_105 != 0x0C && V_145 -> V_105 != 0x12 )
return - V_24 ;
switch ( V_1 -> V_77 ) {
case V_142 :
if ( V_145 -> V_146 != 0x9B ||
V_145 -> V_147 != 0x0B )
return - V_24 ;
break;
case V_78 :
if ( V_1 -> V_148 < 2 ) {
if ( V_145 -> V_105 == 0x0C )
break;
return - V_24 ;
}
if ( V_145 -> V_146 != 0x91 ||
V_145 -> V_147 != 0x02 )
return - V_24 ;
break;
default:
return - V_24 ;
}
return 0 ;
}
int F_50 ( struct V_1 * V_1 , const struct V_102 * V_103 )
{
struct V_149 * V_150 = & V_1 -> V_25 -> V_150 ;
struct V_101 * V_106 ;
const struct V_101 * V_151 ;
const struct V_152 * V_153 ;
int V_154 ;
T_6 V_155 , V_156 ;
T_5 V_157 , V_158 ;
T_5 V_159 ;
T_5 V_160 ;
int V_161 ;
if ( F_49 ( V_1 ,
(struct V_144 * ) V_103 -> V_54 ) ) {
F_51 ( V_150 , L_1 ,
V_162 ) ;
return - V_24 ;
}
V_106 =
F_38 ( V_103 , & V_154 ) ;
V_151 = & V_106 [ V_154 - 1 ] ;
if ( V_151 -> V_163 != 0x00 ||
F_52 ( & V_151 -> V_164 ) != 0x01ff ) {
F_51 ( V_150 , L_2 , V_162 ) ;
return - V_24 ;
}
V_153 = ( const void * ) V_151 -> V_132 ;
V_160 = F_41 ( 0xffff , V_151 -> V_132 ,
V_165 ) ;
if ( V_160 != F_15 ( & V_153 -> V_135 ) ) {
F_51 ( V_150 , L_3 , V_162 ) ;
return - V_24 ;
}
V_155 = F_53 ( & V_153 -> V_166 ) ;
V_157 = F_15 ( & V_153 -> V_167 ) ;
V_156 = F_53 ( & V_153 -> V_168 ) ;
V_158 = F_15 ( & V_153 -> V_169 ) ;
if ( V_155 % V_170 ||
V_157 % V_170 ||
V_156 % V_170 ||
V_158 % V_170 ) {
F_51 ( V_150 , L_4 , V_162 ) ;
return - V_24 ;
}
V_159 = 0xffffU ;
for ( V_161 = 0 ; V_161 < V_157 / V_170 ; V_161 ++ ) {
const T_2 * V_54 = V_106 [ V_161 ] . V_132 ;
V_159 = F_41 ( V_159 , V_54 , V_170 ) ;
}
if ( V_159 != F_15 ( & V_153 -> V_159 ) ) {
F_51 ( V_150 , L_5 , V_162 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_1 ,
struct V_101 * V_171 )
{
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_172 * V_173 ;
struct V_113 * V_114 ;
T_2 V_43 [ V_115 ] ;
T_5 V_44 ;
T_2 V_163 ;
T_5 V_174 ;
T_5 V_175 ;
T_2 * V_132 ;
T_5 V_176 ;
T_5 V_136 ;
T_2 V_14 [ 11 ] ;
int V_15 ;
int error ;
V_163 = V_171 -> V_163 ;
V_174 = F_52 ( & V_171 -> V_164 ) ;
V_175 = F_52 ( & V_171 -> V_175 ) ;
V_132 = V_171 -> V_132 ;
memset ( V_43 , 0 , V_115 ) ;
V_108 = (struct V_107 * ) V_43 ;
V_110 = & V_108 -> V_125 ;
V_44 = sizeof( struct V_107 ) +
sizeof( struct V_172 ) +
V_121 +
sizeof( struct V_113 ) ;
F_40 ( V_122 , & V_108 -> V_123 ) ;
F_40 ( V_44 - 2 , & V_108 -> V_32 ) ;
V_108 -> V_124 = V_52 ;
V_110 -> V_126 = V_61 ;
V_110 -> V_127 = V_177 ;
V_176 = sizeof( struct V_172 ) + V_175 ;
F_40 ( V_176 , & V_110 -> V_129 ) ;
V_173 = (struct V_172 * ) V_108 -> V_54 ;
V_173 -> V_163 = V_163 ;
F_40 ( V_174 , & V_173 -> V_174 ) ;
memcpy ( V_173 -> V_178 , V_132 , V_175 ) ;
V_114 = (struct V_113 * ) ( V_108 -> V_54 +
V_176 ) ;
V_136 = F_41 ( 0xffff , ( T_2 * ) V_110 ,
sizeof( struct V_109 ) + V_176 ) ;
F_40 ( V_136 , & V_114 -> V_136 ) ;
V_114 -> V_137 = V_94 ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 , V_43 , V_44 ,
V_14 , & V_15 ,
500 , F_27 , true ) ;
if ( error || V_15 != V_179 ||
V_14 [ 2 ] != V_57 ||
! F_42 ( V_14 ) )
return error < 0 ? error : - V_100 ;
return 0 ;
}
int F_55 ( struct V_1 * V_1 ,
const struct V_102 * V_103 )
{
struct V_149 * V_150 = & V_1 -> V_25 -> V_150 ;
struct V_101 * V_106 ;
int V_154 ;
int V_161 ;
int error ;
F_14 ( V_1 , NULL , NULL , NULL ) ;
V_106 =
F_38 ( V_103 , & V_154 ) ;
for ( V_161 = 0 ; V_161 < ( V_154 - 1 ) ; V_161 ++ ) {
error = F_54 ( V_1 , & V_106 [ V_161 ] ) ;
if ( error ) {
F_51 ( V_150 , L_6 ,
V_162 , error ) ;
return error ;
}
}
return 0 ;
}
static int F_56 ( struct V_1 * V_1 , T_2 V_180 )
{
T_2 V_43 [ 8 ] = { 0x04 , 0x00 , 0x06 , 0x00 , 0x2f , 0x00 , 0x08 , 0x01 } ;
T_2 V_14 [ 6 ] ;
int V_15 ;
int error ;
V_43 [ 7 ] = V_180 ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 , V_43 , sizeof( V_43 ) ,
V_14 , & V_15 ,
500 , F_28 , false ) ;
if ( error || ! F_57 ( V_14 , 0x08 ) ||
! F_42 ( V_14 ) )
return error < 0 ? error : - V_24 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_1 ,
T_2 V_181 , T_5 V_182 )
{
struct V_183 * V_184 ;
struct V_185 * V_186 ;
T_2 V_43 [ V_115 ] ;
int V_44 ;
T_2 V_14 [ 7 ] ;
int V_15 ;
T_2 V_187 ;
int error ;
memset ( V_43 , 0 , V_115 ) ;
V_184 = (struct V_183 * ) V_43 ;
V_186 = (struct V_185 * )
V_184 -> V_186 ;
V_44 = sizeof( struct V_183 ) +
sizeof( struct V_185 ) ;
switch ( V_181 ) {
case V_188 :
V_187 = V_189 ;
break;
case V_190 :
V_187 = V_191 ;
break;
case V_192 :
V_187 = V_193 ;
break;
default:
return - V_24 ;
}
F_40 ( V_122 , & V_184 -> V_123 ) ;
F_40 ( V_44 - ( 4 - V_187 ) - 2 ,
& V_184 -> V_32 ) ;
V_184 -> V_124 = V_50 ;
V_184 -> V_127 = V_194 ;
V_186 -> V_181 = V_181 ;
V_186 -> V_187 = V_187 ;
F_59 ( ( T_6 ) V_182 , & V_186 -> V_195 ) ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 , V_43 , V_44 ,
V_14 , & V_15 ,
500 , F_28 , false ) ;
if ( error || V_14 [ 5 ] != V_181 ||
V_14 [ 6 ] != V_187 ||
! F_57 ( V_14 , V_194 ) )
return error < 0 ? error : - V_24 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_1 ,
T_2 V_181 , T_5 * V_182 )
{
struct V_183 * V_184 ;
struct V_196 * V_186 ;
T_2 V_43 [ V_115 ] ;
int V_44 ;
T_2 V_14 [ 11 ] ;
int V_15 ;
T_2 V_187 ;
T_5 V_197 , V_161 ;
int error ;
memset ( V_43 , 0 , V_115 ) ;
V_184 = (struct V_183 * ) V_43 ;
V_186 = (struct V_196 * )
V_184 -> V_186 ;
V_44 = sizeof( struct V_183 ) +
sizeof( struct V_196 ) ;
* V_182 = 0 ;
switch ( V_181 ) {
case V_188 :
V_187 = V_189 ;
break;
case V_190 :
V_187 = V_191 ;
break;
case V_192 :
V_187 = V_193 ;
break;
default:
return - V_24 ;
}
F_40 ( V_122 , & V_184 -> V_123 ) ;
F_40 ( V_44 - 2 , & V_184 -> V_32 ) ;
V_184 -> V_124 = V_50 ;
V_184 -> V_127 = V_198 ;
V_186 -> V_181 = V_181 ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 , V_43 , V_44 ,
V_14 , & V_15 ,
500 , F_28 , false ) ;
if ( error || V_14 [ 5 ] != V_181 || V_14 [ 6 ] == 0 ||
! F_57 ( V_14 , V_198 ) )
return error < 0 ? error : - V_24 ;
V_197 = 0 ;
for ( V_161 = 0 ; V_161 < V_187 ; V_161 ++ )
V_197 |= ( 0xff << ( V_161 * 8 ) ) ;
* V_182 = F_15 ( & V_14 [ 7 ] ) & V_197 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_1 )
{
struct V_183 * V_184 ;
T_2 V_43 [ 10 ] ;
T_2 V_14 [ 7 ] ;
int V_15 ;
int error ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
V_184 = (struct V_183 * ) V_43 ;
F_40 ( V_122 , & V_184 -> V_123 ) ;
F_40 ( sizeof( V_43 ) - 2 , & V_184 -> V_32 ) ;
V_184 -> V_124 = V_50 ;
V_184 -> V_127 = V_194 ;
V_184 -> V_186 [ 0 ] = V_199 ;
V_184 -> V_186 [ 1 ] = 0x01 ;
V_184 -> V_186 [ 2 ] = 0x01 ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 , V_43 , sizeof( V_43 ) ,
V_14 , & V_15 ,
500 , F_28 , false ) ;
if ( error || V_14 [ 5 ] != V_199 ||
! F_57 ( V_14 , V_194 ) ||
V_14 [ 6 ] != 0x01 )
return error < 0 ? error : - V_24 ;
return 0 ;
}
int F_62 ( struct V_1 * V_1 , bool V_200 )
{
T_2 V_43 [] = { 0x04 , 0x00 , 0x06 , 0x00 , 0x2f , 0x00 , V_201 ,
( T_2 ) ! ! V_200
} ;
T_2 V_14 [ 6 ] ;
int V_15 ;
int error ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 , V_43 , sizeof( V_43 ) ,
V_14 , & V_15 ,
500 , F_28 , false ) ;
if ( error || ! F_57 ( V_14 , V_201 ) ||
! F_42 ( V_14 ) ) {
error = ( error == - V_46 ) ? - V_202 : error ;
return error < 0 ? error : - V_24 ;
}
return 0 ;
}
int F_63 ( struct V_1 * V_1 , T_2 V_79 )
{
T_2 V_43 [] = { 0x05 , 0x00 , 0x00 , 0x08 } ;
T_2 V_14 [ 5 ] ;
int V_15 ;
int error ;
V_43 [ 2 ] = V_79 & V_203 ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 , V_43 , sizeof( V_43 ) ,
V_14 , & V_15 ,
500 , F_32 , false ) ;
if ( error || ( ( V_14 [ 3 ] & V_203 ) != V_79 ) )
return - V_24 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_1 ,
T_2 V_204 , T_5 V_205 , enum V_27 V_9 )
{
struct V_149 * V_150 = & V_1 -> V_25 -> V_150 ;
T_2 V_180 ;
int error = 0 ;
if ( V_1 -> V_79 != V_81 )
return 0 ;
F_9 ( V_1 , V_9 ) ;
if ( F_65 ( V_1 ) == V_17 ) {
F_66 ( V_1 , V_206 ) ;
}
if ( F_67 ( V_1 ) &&
F_65 ( V_1 ) != V_206 )
if ( F_60 ( V_1 ,
V_192 ,
& V_1 -> V_18 ) != 0 )
F_68 ( V_1 , V_19 ) ;
if ( F_65 ( V_1 ) == V_204 ) {
if ( V_204 == V_206 ||
V_204 == V_207 ||
V_204 == V_208 ||
F_69 ( V_1 ) == V_205 ) {
goto V_209;
}
}
if ( V_204 == V_206 ) {
error = F_63 ( V_1 , V_210 ) ;
if ( error ) {
F_51 ( V_150 , L_7 , error ) ;
goto V_209;
}
F_66 ( V_1 , V_206 ) ;
goto V_209;
}
if ( F_65 ( V_1 ) == V_206 ) {
error = F_63 ( V_1 , V_211 ) ;
if ( error ) {
F_51 ( V_150 , L_8 , error ) ;
goto V_209;
}
}
if ( V_204 == V_207 ) {
error = F_56 ( V_1 ,
V_212 ) ;
if ( error ) {
F_51 ( V_150 , L_9 , error ) ;
goto V_209;
}
F_66 ( V_1 , V_207 ) ;
} else if ( V_204 == V_208 ) {
error = F_56 ( V_1 ,
V_213 ) ;
if ( error ) {
F_51 ( V_150 , L_10 , error ) ;
goto V_209;
}
F_66 ( V_1 , V_208 ) ;
} else {
if ( F_67 ( V_1 ) ||
V_205 != F_69 ( V_1 ) )
if ( F_58 ( V_1 ,
V_192 ,
V_205 ) == 0 )
F_68 ( V_1 , V_205 ) ;
if ( V_205 <= V_214 )
V_180 = V_215 ;
else
V_180 = V_216 ;
error = F_56 ( V_1 , V_180 ) ;
if ( error ) {
F_51 ( V_150 , L_11 ,
V_180 , error ) ;
goto V_209;
}
if ( V_9 == V_217 )
F_61 ( V_1 ) ;
F_66 ( V_1 ,
F_70 ( V_205 ) ) ;
}
V_209:
F_12 ( V_1 ) ;
return error ;
}
int F_71 ( struct V_1 * V_1 )
{
T_2 V_43 [] = { 0x04 , 0x00 , 0x05 , 0x00 , 0x2f , 0x00 , 0x04 } ;
T_2 V_14 [ 6 ] ;
int V_15 ;
int error ;
F_14 ( V_1 , NULL , NULL , NULL ) ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 ,
V_43 , sizeof( V_43 ) ,
V_14 , & V_15 ,
500 , F_28 , true ) ;
if ( error || ! F_57 ( V_14 , 0x04 ) )
return - V_24 ;
F_14 ( V_1 , NULL , NULL , NULL ) ;
return 0 ;
}
int F_72 ( struct V_1 * V_1 )
{
T_2 V_43 [] = { 0x04 , 0x00 , 0x05 , 0x00 , 0x2f , 0x00 , 0x03 } ;
T_2 V_14 [ 6 ] ;
int V_15 ;
int error ;
F_14 ( V_1 , NULL , NULL , NULL ) ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 ,
V_43 , sizeof( V_43 ) ,
V_14 , & V_15 ,
500 , F_28 , true ) ;
if ( error || ! F_57 ( V_14 , 0x03 ) )
return - V_24 ;
F_14 ( V_1 , NULL , NULL , NULL ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_1 ,
T_2 V_218 )
{
struct V_183 * V_184 ;
T_2 V_43 [ 8 ] ;
T_2 V_14 [ 6 ] ;
int V_15 ;
int error ;
F_14 ( V_1 , NULL , NULL , NULL ) ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
V_184 = (struct V_183 * ) V_43 ;
F_40 ( V_122 , & V_184 -> V_123 ) ;
F_40 ( sizeof( V_43 ) - 2 , & V_184 -> V_32 ) ;
V_184 -> V_124 = V_50 ;
V_184 -> V_127 = V_219 ;
V_184 -> V_186 [ 0 ] = V_218 ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 ,
V_43 , sizeof( V_43 ) ,
V_14 , & V_15 ,
5000 , F_28 , true ) ;
if ( error || ! F_57 ( V_14 , V_219 ) ||
! F_42 ( V_14 ) )
return error < 0 ? error : - V_100 ;
return 0 ;
}
T_1 F_74 ( struct V_149 * V_150 ,
struct V_220 * V_221 ,
const char * V_20 , T_3 V_222 )
{
struct V_1 * V_1 = F_75 ( V_150 ) ;
int error , V_223 ;
error = F_72 ( V_1 ) ;
if ( error )
return error ;
V_223 = F_73 ( V_1 ,
V_224 ) ;
if ( V_223 )
goto V_225;
V_223 = F_73 ( V_1 ,
V_226 ) ;
if ( V_223 )
goto V_225;
V_225:
error = F_71 ( V_1 ) ;
if ( error || V_223 )
return error ? error : V_223 ;
return V_222 ;
}
static T_7 F_76 ( T_7 V_195 , int V_227 )
{
if ( V_195 >> ( V_227 - 1 ) )
V_195 |= - 1 << V_227 ;
return V_195 ;
}
static T_7 F_77 ( T_2 V_228 , T_2 * V_20 , int V_35 )
{
int V_229 ;
bool V_230 ;
bool V_231 ;
T_7 V_195 ;
V_229 = ( V_228 & 0x07 ) ;
V_230 = ( ( V_228 & 0x10 ) == 0x00 ) ;
V_231 = ( ( V_228 & 0x20 ) == 0x00 ) ;
if ( V_35 < V_229 )
return 0 ;
switch ( V_229 ) {
case 1 :
V_195 = V_20 [ 0 ] ;
break;
case 2 :
if ( V_230 )
V_195 = F_52 ( V_20 ) ;
else
V_195 = F_15 ( V_20 ) ;
break;
case 4 :
if ( V_230 )
V_195 = F_78 ( V_20 ) ;
else
V_195 = F_53 ( V_20 ) ;
break;
default:
V_195 = 0 ;
break;
}
if ( ! V_231 )
V_195 = F_76 ( V_195 , V_229 * 8 ) ;
return V_195 ;
}
static void F_79 ( struct V_1 * V_1 ,
int * V_232 , int * V_233 )
{
if ( V_1 -> V_232 != 0 ) {
* V_232 = V_1 -> V_232 ;
* V_233 = ( V_1 -> V_234 == * V_232 ) ?
V_1 -> V_235 : V_1 -> V_234 ;
} else {
* V_233 = F_16 ( V_1 -> V_234 , V_1 -> V_235 ) ;
* V_232 = F_80 ( V_1 -> V_234 , V_1 -> V_235 ) ;
}
}
static int F_81 ( struct V_1 * V_1 ,
T_2 V_127 , T_2 V_236 , int * V_229 ,
int * V_237 , int * V_238 , int * V_239 )
{
struct V_183 * V_240 ;
T_2 V_43 [ 12 ] ;
T_2 V_14 [ 256 ] ;
int V_15 ;
int V_241 ;
int V_195 ;
T_5 V_242 ;
int V_243 ;
bool V_244 ;
int V_245 , V_222 , V_246 ;
int V_247 , V_248 , V_249 , V_250 , V_251 ;
int V_232 , V_233 ;
int V_161 ;
int error ;
if ( V_127 != V_252 ||
( V_236 != V_253 &&
V_236 != V_254 ) ||
! V_229 || ! V_237 || ! V_238 || ! V_239 )
return - V_24 ;
* V_237 = V_255 ;
* V_238 = V_256 ;
V_245 = V_222 = V_251 = 0 ;
V_232 = V_233 = 0 ;
if ( * V_229 == 0 ) {
V_244 = true ;
V_242 = 0 ;
* V_229 = 4 ;
V_247 = V_255 ;
V_248 = V_256 ;
V_249 = V_250 = V_251 = 0 ;
if ( V_236 == V_253 ) {
if ( V_1 -> V_257 == 0 ) {
F_79 ( V_1 ,
& V_232 , & V_233 ) ;
V_1 -> V_257 =
( V_232 + 3 ) & ~ 3u ;
}
V_246 =
( V_1 -> V_257 + 7 ) & ~ 7u ;
} else {
V_246 = 2 ;
}
} else {
V_244 = false ;
if ( * V_229 > 4 )
* V_229 = 4 ;
if ( V_236 == V_253 ) {
V_242 = V_1 -> V_257 * ( * V_229 ) ;
if ( V_1 -> V_232 == V_1 -> V_234 )
V_233 = V_1 -> V_235 ;
else
V_233 = V_1 -> V_234 ;
V_246 = ( ( V_1 -> V_257 + 7 ) &
~ 7u ) * V_233 ;
} else {
V_242 = 2 ;
V_246 = V_1 -> V_234 +
V_1 -> V_235 ;
V_246 = ( V_246 + 3 ) & ~ 3u ;
}
}
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
V_240 = (struct V_183 * ) V_43 ;
F_40 ( V_122 , & V_240 -> V_123 ) ;
F_40 ( sizeof( V_43 ) - 2 , & V_240 -> V_32 ) ;
V_240 -> V_124 = V_50 ;
V_240 -> V_127 = V_127 ;
do {
V_243 = ( 256 - V_258 ) /
( * V_229 ) ;
V_243 = F_16 ( V_243 , V_246 - V_222 ) ;
V_241 = V_243 * ( * V_229 ) ;
F_40 ( V_242 , & V_240 -> V_186 [ 0 ] ) ;
F_40 ( V_241 , & V_240 -> V_186 [ 2 ] ) ;
V_240 -> V_186 [ 4 ] = V_236 ;
V_15 = V_258 + V_241 ;
error = F_25 ( V_1 ,
V_43 , sizeof( V_43 ) ,
V_14 , & V_15 ,
500 , F_28 ,
true ) ;
if ( error || V_15 < V_258 ||
! F_57 ( V_14 , V_127 ) ||
! F_42 ( V_14 ) ||
V_14 [ 6 ] != V_236 )
return ( error < 0 ) ? error : - V_100 ;
V_241 = F_15 ( & V_14 [ 7 ] ) ;
if ( V_241 == 0 )
break;
* V_229 = ( V_14 [ 9 ] & V_259 ) ;
if ( V_241 < * V_229 )
return - V_24 ;
if ( V_244 &&
V_236 == V_254 ) {
* V_237 = F_77 (
V_14 [ 9 ] ,
& V_14 [ V_258 ] ,
* V_229 ) ;
* V_238 = F_77 (
V_14 [ 9 ] ,
& V_14 [ V_258 +
* V_229 ] ,
* V_229 ) ;
break;
}
V_242 += V_241 ;
for ( V_161 = 10 ; V_161 < ( V_241 + V_258 ) ;
V_161 += * V_229 ) {
V_195 = F_77 ( V_14 [ 9 ] ,
& V_14 [ V_161 ] , * V_229 ) ;
* V_238 = F_16 ( V_195 , * V_238 ) ;
* V_237 = F_80 ( V_195 , * V_237 ) ;
if ( V_236 == V_253 &&
V_251 < V_1 -> V_257 &&
V_244 ) {
if ( ! V_249 || V_195 > V_249 / 2 ) {
V_248 = F_16 ( V_195 , V_248 ) ;
V_247 = F_80 ( V_195 , V_247 ) ;
V_250 += V_195 ;
V_251 ++ ;
V_249 = V_250 / V_251 ;
}
}
V_245 += V_195 ;
V_222 ++ ;
if ( V_222 >= V_246 )
goto V_209;
}
} while ( true );
V_209:
* V_239 = V_222 ? ( V_245 / V_222 ) : 0 ;
if ( V_244 &&
V_236 == V_253 ) {
if ( V_251 == 0 )
return 0 ;
if ( V_251 == V_1 -> V_257 ) {
V_1 -> V_232 = V_1 -> V_232 ?
V_1 -> V_232 : V_232 ;
} else if ( V_251 == V_232 ) {
V_1 -> V_232 = V_1 -> V_232 ?
V_1 -> V_232 : V_232 ;
V_1 -> V_257 = V_232 ;
} else {
V_1 -> V_232 = V_1 -> V_232 ?
V_1 -> V_232 : V_233 ;
V_1 -> V_257 = V_251 ;
}
* V_238 = V_248 ;
* V_237 = V_247 ;
* V_239 = V_249 ;
}
return 0 ;
}
static int F_82 ( struct V_1 * V_1 ,
int * V_260 , int * V_261 , int * V_262 ,
int * V_263 , int * V_264 , int * V_265 )
{
int V_229 ;
int error ;
* V_260 = * V_261 = * V_262 = 0 ;
* V_263 = * V_264 = * V_265 = 0 ;
V_229 = 0 ;
error = F_81 ( V_1 ,
V_252 ,
V_253 ,
& V_229 ,
V_260 , V_261 , V_262 ) ;
if ( error )
return error ;
error = F_81 ( V_1 ,
V_252 ,
V_253 ,
& V_229 ,
V_263 , V_264 , V_265 ) ;
return error ;
}
static int F_83 ( struct V_1 * V_1 ,
int * V_266 , int * V_267 ,
int * V_268 , int * V_269 , int * V_270 )
{
int V_229 ;
int error ;
* V_266 = * V_267 = 0 ;
* V_268 = * V_269 = * V_270 = 0 ;
V_229 = 0 ;
error = F_81 ( V_1 ,
V_252 ,
V_254 ,
& V_229 ,
V_268 , V_269 , V_270 ) ;
if ( error )
return error ;
* V_266 = * V_268 ;
* V_267 = * V_269 ;
error = F_81 ( V_1 ,
V_252 ,
V_254 ,
& V_229 ,
V_268 , V_269 , V_270 ) ;
return error ;
}
static T_1 F_84 ( struct V_1 * V_1 )
{
struct V_183 * V_184 ;
T_2 V_43 [ 7 ] ;
T_2 V_14 [ 6 ] ;
int V_15 ;
int error ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
V_184 = (struct V_183 * ) V_43 ;
F_40 ( V_122 , & V_184 -> V_123 ) ;
F_40 ( sizeof( V_43 ) - 2 , & V_184 -> V_32 ) ;
V_184 -> V_124 = V_50 ;
V_184 -> V_127 = V_271 ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 ,
V_43 , sizeof( V_43 ) ,
V_14 , & V_15 ,
500 , F_28 , true ) ;
if ( error || V_15 != sizeof( V_14 ) ||
! F_57 ( V_14 ,
V_271 ) ||
! F_42 ( V_14 ) )
return error ? error : - V_100 ;
return 0 ;
}
static int F_85 ( struct V_1 * V_1 ,
T_2 V_127 , T_2 V_272 , int V_273 ,
int * V_274 , int * V_275 , int * V_276 ,
T_2 * V_277 )
{
struct V_183 * V_184 ;
struct V_278 * V_279 ;
T_2 V_43 [ 12 ] ;
T_2 V_14 [ 256 ] ;
int V_15 ;
int V_243 ;
int V_241 ;
T_5 V_242 ;
T_7 V_195 ;
int V_245 , V_222 ;
int V_229 ;
T_7 * V_280 ;
int V_161 ;
int error ;
if ( V_127 != V_281 ||
( V_272 > V_282 ) ||
! V_274 || ! V_275 || ! V_276 )
return - V_24 ;
V_280 = ( T_7 * ) V_277 ;
* V_274 = V_255 ;
* V_275 = V_256 ;
V_245 = V_222 = 0 ;
V_242 = 0 ;
V_243 = ( 256 - V_258 ) / 4 ;
V_241 = V_243 * 4 ;
V_184 = (struct V_183 * ) V_43 ;
F_40 ( V_122 , & V_184 -> V_123 ) ;
F_40 ( sizeof( V_43 ) - 2 , & V_184 -> V_32 ) ;
V_184 -> V_124 = V_50 ;
V_184 -> V_127 = V_127 ;
V_279 = (struct V_278 * )
V_184 -> V_186 ;
do {
F_40 ( V_242 , & V_279 -> V_283 ) ;
F_40 ( V_243 ,
& V_279 -> V_243 ) ;
V_279 -> V_284 = V_272 ;
V_15 = V_258 + V_241 ;
error = F_25 ( V_1 ,
V_43 , sizeof( V_43 ) ,
V_14 , & V_15 ,
500 , F_28 , true ) ;
if ( error || V_15 < V_258 ||
! F_57 ( V_14 , V_127 ) ||
! F_42 ( V_14 ) ||
V_14 [ 6 ] != V_272 )
return error ? error : - V_100 ;
V_243 = F_15 ( & V_14 [ 7 ] ) ;
if ( V_243 == 0 )
break;
V_229 = ( V_14 [ 9 ] & V_259 ) ;
V_242 += V_243 ;
if ( V_243 ) {
for ( V_161 = V_258 ;
V_161 < ( V_243 * V_229 +
V_258 ) ;
V_161 += V_229 ) {
V_195 = F_77 ( V_14 [ 9 ] ,
& V_14 [ V_161 ] , V_229 ) ;
* V_275 = F_16 ( V_195 , * V_275 ) ;
* V_274 = F_80 ( V_195 , * V_274 ) ;
if ( V_280 )
F_59 ( V_195 , & V_280 [ V_222 ] ) ;
V_245 += V_195 ;
V_222 ++ ;
}
}
if ( V_222 >= V_273 )
break;
V_243 = ( sizeof( V_14 ) -
V_258 ) / V_229 ;
V_241 = V_243 * V_229 ;
} while ( true );
* V_276 = V_222 ? ( V_245 / V_222 ) : 0 ;
return 0 ;
}
static T_1 F_86 ( struct V_149 * V_150 ,
struct V_220 * V_221 , char * V_20 )
{
struct V_1 * V_1 = F_75 ( V_150 ) ;
int V_260 , V_261 , V_262 ;
int V_263 , V_264 , V_265 ;
int V_266 , V_267 ;
int V_268 , V_269 , V_270 ;
int V_285 , V_286 , V_287 ;
int V_288 , V_289 , V_290 ;
int V_291 , V_292 , V_293 ;
int V_294 , V_295 , V_296 ;
int V_297 , V_298 , V_299 ;
int V_300 , V_301 , V_302 ;
int error , V_303 ;
int V_21 ;
if ( ! F_48 ( V_1 ) )
return - V_304 ;
error = F_72 ( V_1 ) ;
if ( error )
return error ;
V_266 = V_267 = 0 ;
error = F_82 ( V_1 ,
& V_260 , & V_261 ,
& V_262 , & V_263 ,
& V_264 , & V_265 ) ;
if ( error )
goto V_225;
error = F_83 ( V_1 ,
& V_266 , & V_267 ,
& V_268 , & V_269 ,
& V_270 ) ;
if ( error )
goto V_225;
error = F_84 ( V_1 ) ;
if ( error )
goto V_225;
error = F_85 ( V_1 ,
V_281 ,
V_305 ,
V_1 -> V_234 * V_1 -> V_235 ,
& V_285 , & V_286 ,
& V_287 ,
NULL ) ;
if ( error )
goto V_225;
error = F_85 ( V_1 ,
V_281 ,
V_306 ,
V_1 -> V_234 + V_1 -> V_235 ,
& V_288 , & V_289 ,
& V_290 ,
NULL ) ;
if ( error )
goto V_225;
error = F_85 ( V_1 ,
V_281 ,
V_307 ,
V_1 -> V_234 * V_1 -> V_235 ,
& V_291 , & V_292 ,
& V_293 ,
NULL ) ;
if ( error )
goto V_225;
error = F_85 ( V_1 ,
V_281 ,
V_282 ,
V_1 -> V_234 + V_1 -> V_235 ,
& V_294 , & V_295 ,
& V_296 ,
NULL ) ;
if ( error )
goto V_225;
error = F_85 ( V_1 ,
V_281 ,
V_308 ,
V_1 -> V_234 * V_1 -> V_235 ,
& V_297 , & V_298 ,
& V_299 ,
NULL ) ;
if ( error )
goto V_225;
error = F_85 ( V_1 ,
V_281 ,
V_309 ,
V_1 -> V_234 + V_1 -> V_235 ,
& V_300 , & V_301 ,
& V_302 ,
NULL ) ;
if ( error )
goto V_225;
V_225:
V_303 = F_71 ( V_1 ) ;
if ( V_303 || error )
return V_303 ? V_303 : error ;
V_21 = F_87 ( V_20 , V_310 , L_12 ,
V_261 , V_260 , V_262 ,
V_264 , V_263 , V_265 ,
V_266 , V_267 ,
V_269 , V_268 , V_270 ) ;
V_21 += F_87 ( V_20 + V_21 , V_310 - V_21 ,
L_13 ,
V_286 , V_285 , V_287 ,
V_289 , V_288 , V_290 ,
V_292 , V_291 , V_293 ,
V_295 , V_294 , V_296 ,
V_298 , V_297 , V_299 ,
V_301 , V_300 , V_302 ) ;
return V_21 ;
}
bool F_88 ( struct V_1 * V_1 ,
T_2 * V_20 , int V_28 )
{
if ( F_57 ( V_20 , 0x02 ) )
return true ;
return false ;
}
static int F_89 ( struct V_1 * V_1 )
{
T_2 V_14 [ V_311 ] ;
int V_15 ;
int error ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 ,
V_312 , V_313 ,
V_14 , & V_15 ,
500 , F_27 , false ) ;
if ( error || V_15 < V_311 ||
! F_42 ( V_14 ) )
return error ? error : - V_26 ;
memcpy ( & V_1 -> V_314 [ 0 ] , & V_14 [ 8 ] , 5 ) ;
V_1 -> V_314 [ 5 ] = '-' ;
memcpy ( & V_1 -> V_314 [ 6 ] , & V_14 [ 13 ] , 6 ) ;
V_1 -> V_314 [ 12 ] = '-' ;
memcpy ( & V_1 -> V_314 [ 13 ] , & V_14 [ 19 ] , 2 ) ;
V_1 -> V_314 [ 15 ] = '\0' ;
V_1 -> V_315 = V_14 [ 22 ] ;
V_1 -> V_316 = V_14 [ 23 ] ;
V_1 -> V_148 = ( V_14 [ 26 ] >> V_317 ) &
V_318 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_1 )
{
T_2 V_14 [ V_319 ] ;
int V_15 ;
T_5 V_320 ;
int error ;
V_15 = sizeof( V_14 ) ;
error = F_25 ( V_1 ,
V_321 , V_322 ,
V_14 , & V_15 ,
2000 , F_88 , false ) ;
if ( error || V_15 < sizeof( V_14 ) )
return error ? error : - V_26 ;
V_320 = F_15 ( & V_14 [ 7 ] ) ;
if ( ( V_320 & V_323 ) !=
V_324 )
return - V_24 ;
V_1 -> V_148 = ( V_14 [ 49 ] >> V_317 ) &
V_318 ;
if ( V_1 -> V_77 == V_78 && V_1 -> V_148 < 2 ) {
V_1 -> V_315 = V_14 [ 15 ] ;
V_1 -> V_316 = V_14 [ 16 ] ;
} else {
V_1 -> V_315 = V_14 [ 9 ] ;
V_1 -> V_316 = V_14 [ 10 ] ;
}
V_1 -> V_234 = V_14 [ 52 ] ;
V_1 -> V_235 = V_14 [ 53 ] ;
V_1 -> V_325 = F_15 ( & V_14 [ 54 ] ) / 100 ;
V_1 -> V_326 = F_15 ( & V_14 [ 56 ] ) / 100 ;
V_1 -> V_327 = F_15 ( & V_14 [ 58 ] ) ;
V_1 -> V_328 = F_15 ( & V_14 [ 60 ] ) ;
V_1 -> V_329 = F_15 ( & V_14 [ 62 ] ) ;
V_1 -> V_330 = V_14 [ 64 ] & 0x01 ;
V_1 -> V_331 = V_14 [ 65 ] & 0x01 ;
V_1 -> V_332 = ( V_14 [ 70 ] << 3 ) & V_333 ;
memcpy ( & V_1 -> V_314 [ 0 ] , & V_14 [ 33 ] , 5 ) ;
V_1 -> V_314 [ 5 ] = '-' ;
memcpy ( & V_1 -> V_314 [ 6 ] , & V_14 [ 38 ] , 6 ) ;
V_1 -> V_314 [ 12 ] = '-' ;
memcpy ( & V_1 -> V_314 [ 13 ] , & V_14 [ 44 ] , 2 ) ;
V_1 -> V_314 [ 15 ] = '\0' ;
if ( ! V_1 -> V_234 || ! V_1 -> V_235 ||
! V_1 -> V_325 || ! V_1 -> V_326 ||
! V_1 -> V_327 || ! V_1 -> V_328 || ! V_1 -> V_329 )
return - V_24 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_1 )
{
struct V_149 * V_150 = & V_1 -> V_25 -> V_150 ;
int error ;
if ( V_1 -> V_77 != V_78 )
return - V_141 ;
switch ( V_1 -> V_79 ) {
case V_80 :
error = F_44 ( V_1 ) ;
if ( error ) {
F_89 ( V_1 ) ;
goto V_209;
}
V_1 -> V_79 = V_81 ;
case V_81 :
error = F_64 ( V_1 ,
V_207 , 0 , V_334 ) ;
if ( error )
F_92 ( V_150 , L_14 ,
V_162 ) ;
if ( V_1 -> V_148 >= 2 ) {
error = F_62 ( V_1 , true ) ;
if ( error )
F_92 ( V_150 ,
L_15 ,
V_162 ) ;
}
error = F_90 ( V_1 ) ;
if ( error )
goto V_209;
if ( memcmp ( V_1 -> V_314 , V_314 ,
strlen ( V_314 ) ) != 0 ) {
F_51 ( V_150 , L_16 ,
V_162 , V_1 -> V_314 ) ;
error = - V_24 ;
}
break;
default:
error = - V_24 ;
}
V_209:
return error ;
}
bool F_93 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int V_32 ;
if ( F_94 ( & V_3 -> V_6 ) ) {
if ( V_3 -> V_53 == false )
return false ;
F_5 ( V_1 , V_3 -> V_335 ,
V_37 ) ;
V_32 = F_15 ( V_3 -> V_335 ) ;
V_32 = ( V_32 <= V_37 ) ?
V_37 : V_32 ;
if ( V_32 > V_37 )
F_5 ( V_1 ,
V_3 -> V_335 , V_32 ) ;
if ( ! ( V_3 -> V_11 &&
V_3 -> V_11 ( V_1 ,
V_3 -> V_335 , V_32 ) ) ) {
V_32 = 0 ;
if ( V_3 -> V_15 )
V_32 = * V_3 -> V_15 ;
F_14 ( V_1 ,
V_3 -> V_14 ,
& V_32 ,
V_3 -> V_11 ) ;
if ( V_3 -> V_15 && V_32 != 0 ) {
* V_3 -> V_15 = V_32 ;
F_20 ( & V_3 -> V_6 ) ;
F_95 ( & V_3 -> V_5 ) ;
}
return false ;
}
if ( V_3 -> V_14 && V_3 -> V_15 ) {
* V_3 -> V_15 = ( * V_3 -> V_15 < V_32 ) ?
* V_3 -> V_15 : V_32 ;
memcpy ( V_3 -> V_14 , V_3 -> V_335 ,
* V_3 -> V_15 ) ;
}
F_20 ( & V_3 -> V_6 ) ;
F_95 ( & V_3 -> V_5 ) ;
return false ;
}
return true ;
}
static void F_96 ( struct V_1 * V_1 ,
const struct V_42 * V_336 )
{
struct V_30 * V_31 = V_1 -> V_31 ;
T_2 V_337 = V_336 -> V_338 [ V_339 ] ;
V_337 = ( V_337 << V_340 ) & V_333 ;
if ( V_1 -> V_332 & V_341 ) {
F_97 ( V_31 , V_342 ,
! ! ( V_337 & V_341 ) ) ;
}
if ( V_1 -> V_332 & V_343 ) {
F_97 ( V_31 , V_344 ,
! ! ( V_337 & V_343 ) ) ;
}
if ( V_1 -> V_332 & V_345 ) {
F_97 ( V_31 , V_346 ,
! ! ( V_337 & V_345 ) ) ;
}
F_98 ( V_31 ) ;
}
static void F_99 ( struct V_1 * V_1 ,
const struct V_42 * V_336 )
{
struct V_30 * V_31 = V_1 -> V_31 ;
T_2 V_347 = V_336 -> V_338 [ V_348 ] &
V_349 ;
F_100 ( V_31 , V_350 , V_347 ) ;
F_98 ( V_31 ) ;
}
static void F_101 ( struct V_1 * V_1 ,
const struct V_351 * V_352 )
{
struct V_30 * V_31 = V_1 -> V_31 ;
T_2 V_353 = F_102 ( V_352 -> V_354 ) ;
int V_355 = F_103 ( V_352 -> V_354 ) ;
int V_356 , V_357 ;
if ( V_353 == V_358 )
return;
F_104 ( V_31 , V_355 ) ;
F_105 ( V_31 , V_359 , true ) ;
V_356 = ( V_352 -> V_360 << 8 ) | V_352 -> V_361 ;
if ( V_1 -> V_330 )
V_356 = V_1 -> V_327 - V_356 ;
V_357 = ( V_352 -> V_362 << 8 ) | V_352 -> V_363 ;
if ( V_1 -> V_331 )
V_357 = V_1 -> V_328 - V_357 ;
F_100 ( V_31 , V_364 , V_356 ) ;
F_100 ( V_31 , V_365 , V_357 ) ;
F_100 ( V_31 , V_350 , 0 ) ;
F_100 ( V_31 , V_366 ,
V_352 -> V_367 ) ;
F_100 ( V_31 , V_368 ,
V_352 -> V_369 ) ;
F_100 ( V_31 , V_370 ,
V_352 -> V_371 ) ;
F_100 ( V_31 , V_372 ,
V_352 -> V_373 ) ;
F_100 ( V_31 , V_374 ,
V_352 -> V_375 ) ;
F_100 ( V_31 , V_376 ,
V_352 -> V_377 ) ;
}
static void F_106 ( struct V_1 * V_1 ,
const struct V_42 * V_336 )
{
struct V_30 * V_31 = V_1 -> V_31 ;
unsigned int V_378 ;
int V_161 ;
V_378 = V_336 -> V_338 [ V_379 ] &
V_380 ;
for ( V_161 = 0 ; V_161 < V_378 ; V_161 ++ )
F_101 ( V_1 ,
& V_336 -> V_381 [ V_161 ] ) ;
F_107 ( V_31 ) ;
F_98 ( V_31 ) ;
}
int F_108 ( struct V_1 * V_1 )
{
struct V_149 * V_150 = & V_1 -> V_25 -> V_150 ;
struct V_42 V_336 ;
unsigned int V_382 ;
int V_22 ;
if ( ! F_48 ( V_1 ) ) {
F_51 ( V_150 , L_17 ,
V_1 -> V_77 , V_1 -> V_79 ) ;
return - V_24 ;
}
V_22 = F_5 ( V_1 , ( T_2 * ) & V_336 ,
V_37 ) ;
if ( V_22 != V_37 ) {
F_51 ( V_150 , L_18 , V_22 ) ;
return - V_24 ;
}
V_382 = F_15 (
& V_336 . V_338 [ V_64 ] ) ;
if ( V_382 < V_37 ) {
F_51 ( V_150 , L_19 ,
V_382 , V_336 . V_338 [ 0 ] ,
V_336 . V_338 [ 1 ] ) ;
return - V_24 ;
}
if ( V_382 == V_37 )
return 0 ;
V_22 = F_5 ( V_1 , ( T_2 * ) & V_336 , V_382 ) ;
if ( V_22 != V_382 ) {
F_51 ( V_150 , L_20 ,
V_382 , V_22 ) ;
return - V_24 ;
}
return F_17 ( V_1 , & V_336 ) ;
}
static int F_17 ( struct V_1 * V_1 ,
struct V_42 * V_336 )
{
struct V_149 * V_150 = & V_1 -> V_25 -> V_150 ;
unsigned int V_382 ;
T_2 V_124 ;
V_382 = F_15 (
& V_336 -> V_338 [ V_64 ] ) ;
if ( V_382 == V_37 )
return 0 ;
V_124 = V_336 -> V_338 [ V_56 ] ;
if ( V_124 == V_92 &&
V_382 == V_93 ) {
F_109 ( V_150 ) ;
F_110 ( V_150 ) ;
F_111 ( V_150 ) ;
return 0 ;
} else if ( V_124 != V_84 &&
V_124 != V_87 &&
V_124 != V_88 &&
V_124 != V_89 &&
V_124 != V_383 ) {
F_51 ( V_150 , L_21 , V_124 ) ;
return - V_24 ;
}
if ( V_124 == V_84 &&
( V_382 < V_85 ||
V_382 > V_86 ) ) {
F_51 ( V_150 , L_22 , V_382 ) ;
return 0 ;
}
if ( ( V_124 == V_87 ||
V_124 == V_88 ||
V_124 == V_89 ) &&
( V_382 < V_90 ||
V_382 > V_91 ) ) {
F_51 ( V_150 , L_23 , V_382 ) ;
return 0 ;
}
if ( V_124 == V_383 &&
V_382 != V_384 ) {
F_51 ( V_150 , L_24 , V_382 ) ;
return 0 ;
}
if ( V_124 == V_84 )
F_106 ( V_1 , V_336 ) ;
else if ( V_124 == V_383 )
F_99 ( V_1 , V_336 ) ;
else
F_96 ( V_1 , V_336 ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_1 ) { return 0 ; }
int F_113 ( struct V_1 * V_1 ) { return 0 ; }
