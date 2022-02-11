static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
F_2 ( & V_3 -> V_6 ) ;
F_3 ( & V_3 -> V_7 , 0 ) ;
F_4 ( & V_3 -> V_8 ) ;
V_3 -> V_9 = NULL ;
V_3 -> V_10 = V_11 ;
V_3 -> V_12 = NULL ;
V_3 -> V_13 = NULL ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
return 0 ;
}
static T_1 F_5 ( struct V_1 * V_1 , T_2 * V_18 , T_3 V_19 )
{
int V_20 ;
if ( V_19 == 0 )
return 0 ;
if ( ! V_18 || V_19 > V_21 )
return - V_22 ;
V_20 = F_6 ( V_1 -> V_23 , V_18 , V_19 ) ;
if ( V_20 != V_19 )
return ( V_20 < 0 ) ? V_20 : - V_24 ;
return V_19 ;
}
static T_1 F_7 ( struct V_1 * V_1 , T_2 * V_18 , T_3 V_19 )
{
int V_20 ;
if ( ! V_18 || ! V_19 )
return - V_22 ;
V_20 = F_8 ( V_1 -> V_23 , V_18 , V_19 ) ;
if ( V_20 != V_19 )
return ( V_20 < 0 ) ? V_20 : - V_24 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 ,
T_2 * V_18 , int * V_25 , T_4 V_26 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
int V_27 ;
int V_28 ;
int V_29 ;
int V_30 ;
int error ;
V_30 = 0 ;
if ( V_25 ) {
V_30 = ( * V_25 < V_21 ) ?
* V_25 : V_21 ;
* V_25 = 0 ;
}
V_28 = 8 ;
V_29 = 0 ;
do {
if ( V_29 > 5 )
return 0 ;
error = F_5 ( V_1 , V_3 -> V_31 ,
V_32 ) ;
if ( error < 0 )
return error ;
V_27 = F_10 ( V_3 -> V_31 ) ;
if ( V_27 == V_32 ) {
V_29 ++ ;
continue;
} else if ( V_27 > V_21 ) {
return - V_22 ;
} else if ( V_27 == 0 ) {
V_27 = V_32 ;
if ( V_18 && V_30 && V_26 &&
V_26 ( V_1 , V_3 -> V_31 , V_27 ) ) {
V_27 = F_11 ( V_30 , V_27 ) ;
memcpy ( V_18 , V_3 -> V_31 , V_27 ) ;
* V_25 = V_27 ;
return 0 ;
}
continue;
}
error = F_5 ( V_1 , V_3 -> V_31 , V_27 ) ;
if ( error < 0 )
return error ;
V_28 -- ;
V_29 = 0 ;
V_27 = F_10 ( V_3 -> V_31 ) ;
if ( V_27 <= V_32 ) {
V_29 ++ ;
} else if ( V_18 && V_30 && V_26 &&
V_26 ( V_1 , V_3 -> V_31 , V_27 ) ) {
V_27 = F_11 ( V_30 , V_27 ) ;
memcpy ( V_18 , V_3 -> V_31 , V_27 ) ;
* V_25 = V_27 ;
return 0 ;
}
error = - V_22 ;
} while ( V_28 );
return error ;
}
static int F_12 (
struct V_1 * V_1 ,
T_2 * V_33 , T_3 V_34 ,
unsigned long V_35 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
int error ;
F_2 ( & V_3 -> V_6 ) ;
F_13 ( & V_3 -> V_7 ) ;
error = F_7 ( V_1 , V_33 , V_34 ) ;
if ( error ) {
F_14 ( & V_3 -> V_7 ) ;
return ( error < 0 ) ? error : - V_24 ;
}
V_35 = F_15 ( & V_3 -> V_6 ,
F_16 ( V_35 ) ) ;
if ( V_35 == 0 ) {
F_14 ( & V_3 -> V_7 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_17 (
struct V_1 * V_1 ,
T_2 * V_33 , T_3 V_34 ,
T_2 * V_12 , int * V_13 ,
unsigned long V_35 ,
T_4 V_26 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
int V_37 ;
int V_27 ;
int error ;
F_13 ( & V_3 -> V_7 ) ;
error = F_7 ( V_1 , V_33 , V_34 ) ;
if ( error ) {
F_14 ( & V_3 -> V_7 ) ;
return error < 0 ? error : - V_24 ;
}
V_27 = V_13 ? * V_13 : 0 ;
if ( V_12 && V_13 && V_27 != 0 && V_26 ) {
V_37 = V_35 / 5 ;
do {
F_18 ( 3000 , 5000 ) ;
* V_13 = V_27 ;
error = F_9 ( V_1 ,
V_12 , V_13 , V_26 ) ;
if ( error || * V_13 == 0 )
continue;
else
break;
} while ( -- V_37 > 0 );
if ( ( error || * V_13 == 0 ) || V_37 <= 0 )
error = error ? error : - V_36 ;
}
F_14 ( & V_3 -> V_7 ) ;
return error ;
}
static int F_19 (
struct V_1 * V_1 ,
T_2 * V_33 , int V_34 ,
T_2 * V_12 , int * V_13 ,
unsigned long V_35 ,
T_4 V_26 ,
bool V_38 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
int error ;
if ( ! V_33 || ! V_34 )
return - V_22 ;
error = F_20 ( & V_3 -> V_8 ) ;
if ( error )
return error ;
V_3 -> V_9 = V_26 ;
V_3 -> V_12 = V_12 ;
V_3 -> V_13 = V_13 ;
if ( V_34 >= V_39 &&
V_33 [ 4 ] == V_40 ) {
V_3 -> V_10 = V_33 [ 6 ] & 0x7f ;
} else if ( V_34 >= V_41 &&
V_33 [ 4 ] == V_42 ) {
V_3 -> V_10 = V_33 [ 7 ] ;
}
if ( V_38 ) {
V_3 -> V_43 = true ;
error = F_12 ( V_1 , V_33 , V_34 ,
V_35 ) ;
if ( error == - V_36 && V_12 &&
V_13 && * V_13 != 0 && V_26 ) {
error = F_9 ( V_1 ,
V_12 , V_13 , V_26 ) ;
if ( error || * V_13 == 0 )
error = error ? error : - V_36 ;
}
} else {
V_3 -> V_43 = false ;
error = F_17 ( V_1 , V_33 , V_34 ,
V_12 , V_13 , V_35 , V_26 ) ;
}
V_3 -> V_9 = NULL ;
V_3 -> V_12 = NULL ;
V_3 -> V_13 = NULL ;
V_3 -> V_10 = V_11 ;
F_21 ( & V_3 -> V_8 ) ;
return error ;
}
static bool F_22 ( struct V_1 * V_1 ,
T_2 * V_44 , int V_25 )
{
if ( ! V_44 || V_25 < V_45 )
return false ;
if ( V_44 [ V_46 ] == V_47 &&
V_44 [ V_48 ] == V_49 &&
V_44 [ V_50 ] == V_51 )
return true ;
return false ;
}
static bool F_23 ( struct V_1 * V_1 ,
T_2 * V_44 , int V_25 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
int V_13 ;
if ( ! V_44 || V_25 < V_52 )
return false ;
if ( V_44 [ V_46 ] == V_53 &&
V_44 [ V_48 ] == V_49 ) {
V_13 = F_10 ( & V_44 [ V_54 ] ) ;
if ( F_24 ( V_44 [ V_55 ] ) == 0x00 &&
V_13 == V_56 &&
V_44 [ 5 ] == V_3 -> V_10 ) {
return false ;
} else if ( F_24 ( V_44 [ V_55 ] ) ==
V_3 -> V_10 ) {
return true ;
}
}
return false ;
}
static bool F_25 ( struct V_1 * V_1 ,
T_2 * V_18 , int V_25 )
{
if ( V_18 == NULL || V_25 < V_32 )
return false ;
if ( V_18 [ 0 ] == 0 && V_18 [ 1 ] == 0 )
return true ;
return false ;
}
static bool F_26 ( struct V_1 * V_1 ,
T_2 * V_18 , int V_25 )
{
int V_13 ;
int V_57 ;
if ( V_25 != V_58 )
return false ;
V_13 = F_10 ( & V_18 [ V_54 ] ) ;
V_57 = F_10 ( & V_18 [ 16 ] ) ;
if ( V_13 == V_58 ) {
if ( V_18 [ V_46 ] == V_59 &&
V_57 == V_60 ) {
return true ;
} else if ( ( V_18 [ V_46 ] ==
V_61 ) &&
V_57 == V_62 ) {
return true ;
}
}
return false ;
}
static bool F_27 ( struct V_1 * V_1 ,
T_2 * V_18 , int V_25 )
{
if ( V_25 == V_63 &&
V_18 [ V_46 ] ==
V_64 &&
( V_18 [ 4 ] & V_65 ) ==
V_66 )
return true ;
return false ;
}
static int F_28 ( struct V_1 * V_1 )
{
T_2 V_12 [ V_58 ] ;
int V_57 ;
int V_27 ;
T_2 V_33 [ 2 ] ;
int V_20 ;
int error ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
V_20 = F_5 ( V_1 , V_12 , 3 ) ;
if ( V_20 != 3 )
return V_20 < 0 ? V_20 : - V_24 ;
V_27 = F_10 ( & V_12 [ V_54 ] ) ;
if ( V_27 == V_32 ) {
V_1 -> V_67 = V_68 ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
V_33 [ 0 ] = 0x01 ;
V_33 [ 1 ] = 0x00 ;
V_27 = V_58 ;
error = F_19 ( V_1 ,
V_33 , V_32 ,
V_12 , & V_27 ,
300 ,
F_26 ,
false ) ;
if ( error )
return error ;
V_27 = F_10 (
& V_12 [ V_54 ] ) ;
V_57 = F_10 ( & V_12 [ 16 ] ) ;
if ( ( V_27 == V_58 ||
V_27 == V_32 ) &&
( V_12 [ V_46 ] ==
V_59 ) &&
V_57 == V_60 ) {
V_1 -> V_69 = V_70 ;
} else if ( ( V_27 == V_58 ||
V_27 == V_32 ) &&
( V_12 [ V_46 ] ==
V_61 ) &&
V_57 == V_62 ) {
V_1 -> V_69 = V_71 ;
} else {
V_1 -> V_69 = V_72 ;
}
}
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , T_2 * V_73 )
{
int V_27 ;
T_2 V_12 [ 32 ] ;
int V_57 ;
int V_20 ;
V_20 = F_5 ( V_1 , V_12 ,
V_58 ) ;
if ( V_20 != V_58 )
return V_20 < 0 ? V_20 : - V_24 ;
V_27 = F_10 ( & V_12 [ V_54 ] ) ;
V_57 = F_10 ( & V_12 [ 16 ] ) ;
if ( V_27 == V_32 ) {
if ( V_73 [ V_46 ] ==
V_59 ) {
V_1 -> V_67 = V_68 ;
V_1 -> V_69 = V_70 ;
} else {
V_1 -> V_67 = V_68 ;
V_1 -> V_69 = V_71 ;
}
} else if ( V_27 == V_58 &&
V_12 [ 2 ] == V_59 &&
V_57 == V_60 ) {
V_1 -> V_67 = V_68 ;
V_1 -> V_69 = V_70 ;
} else if ( V_27 == V_58 &&
( V_12 [ V_46 ] ==
V_61 ) &&
V_57 == V_62 ) {
V_1 -> V_67 = V_68 ;
V_1 -> V_69 = V_71 ;
} else {
V_1 -> V_69 = V_72 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , T_2 * V_73 )
{
int V_27 ;
V_27 = F_10 ( & V_73 [ V_54 ] ) ;
switch ( V_73 [ V_46 ] ) {
case V_74 :
if ( V_27 < V_75 ||
V_27 > V_76 )
return - V_22 ;
break;
case V_77 :
case V_78 :
case V_79 :
if ( V_27 < V_80 ||
V_27 > V_81 )
return - V_22 ;
break;
case V_82 :
if ( V_27 != V_83 )
return - V_22 ;
break;
default:
return - V_22 ;
}
V_1 -> V_67 = V_68 ;
V_1 -> V_69 = V_71 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , T_2 * V_73 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
int V_27 ;
int V_20 ;
V_27 = F_10 ( & V_73 [ V_54 ] ) ;
V_20 = F_5 ( V_1 , V_3 -> V_31 , V_27 ) ;
if ( V_20 != V_27 )
return V_20 < 0 ? V_20 : - V_24 ;
if ( V_27 == V_32 ) {
if ( V_73 [ V_46 ] ==
V_47 ) {
V_1 -> V_67 = V_68 ;
V_1 -> V_69 = V_70 ;
} else {
V_1 -> V_67 = V_68 ;
V_1 -> V_69 = V_71 ;
}
} else if ( ( V_3 -> V_31 [ V_46 ] ==
V_47 ) &&
( V_3 -> V_31 [ V_48 ] ==
V_49 ) &&
( V_3 -> V_31 [ V_50 ] ==
V_51 ) &&
( V_3 -> V_31 [ V_27 - 1 ] ==
V_84 ) ) {
V_1 -> V_67 = V_68 ;
V_1 -> V_69 = V_70 ;
} else if ( V_3 -> V_31 [ V_46 ] ==
V_53 &&
V_3 -> V_31 [ V_48 ] ==
V_49 ) {
V_1 -> V_67 = V_68 ;
V_1 -> V_69 = V_71 ;
} else {
V_1 -> V_69 = V_72 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , T_2 * V_73 , int V_25 )
{
int V_27 ;
if ( ! V_73 || V_25 < 3 )
return - V_22 ;
V_1 -> V_69 = V_72 ;
V_27 = F_10 ( & V_73 [ V_54 ] ) ;
if ( V_27 == 0 || V_27 == V_32 ) {
F_28 ( V_1 ) ;
} else if ( V_27 == V_58 &&
( V_73 [ 2 ] == V_59 ||
V_73 [ 2 ] == V_61 ) ) {
F_29 ( V_1 , V_73 ) ;
} else if ( ( V_27 == V_85 ||
V_27 == V_86 ) &&
V_73 [ 2 ] == V_87 ) {
V_1 -> V_67 = V_68 ;
V_1 -> V_69 = V_71 ;
} else if ( V_27 == V_88 &&
V_73 [ 2 ] == V_89 ) {
V_1 -> V_67 = V_68 ;
V_1 -> V_69 = V_70 ;
} else if ( V_73 [ 2 ] == V_74 ||
V_73 [ 2 ] == V_77 ||
V_73 [ 2 ] == V_78 ||
V_73 [ 2 ] == V_79 ||
V_73 [ 2 ] == V_82 ) {
F_30 ( V_1 , V_73 ) ;
} else if ( V_73 [ 2 ] == V_47 ||
V_73 [ 2 ] == V_53 ) {
F_31 ( V_1 , V_73 ) ;
}
if ( V_1 -> V_67 == V_68 ) {
F_9 ( V_1 , NULL , NULL , NULL ) ;
if ( V_1 -> V_69 == V_71 ||
V_1 -> V_69 == V_70 )
return 0 ;
}
return - V_90 ;
}
static int F_33 ( struct V_1 * V_1 ,
const struct V_91 * V_92 )
{
struct V_93 * V_94 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
T_2 V_33 [ V_103 ] ;
int V_34 ;
T_5 V_104 ;
T_5 V_105 = 0 ;
T_5 V_106 = 0 ;
T_2 V_12 [ 11 ] ;
int V_13 ;
int V_107 ;
T_2 * V_44 ;
int error ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
memset ( V_33 , 0 , V_103 ) ;
V_96 = (struct V_95 * ) V_33 ;
V_104 = V_108 + V_109 ;
V_34 = sizeof( struct V_95 ) + V_104 +
sizeof( struct V_101 ) ;
F_34 ( V_110 , & V_96 -> V_111 ) ;
F_34 ( V_34 - 2 , & V_96 -> V_27 ) ;
V_96 -> V_112 = V_42 ;
V_98 = & V_96 -> V_113 ;
V_98 -> V_114 = V_51 ;
V_98 -> V_115 = V_116 ;
F_34 ( V_104 , & V_98 -> V_117 ) ;
V_100 = (struct V_99 * ) V_96 -> V_44 ;
memcpy ( V_100 -> V_118 , V_119 , V_108 ) ;
V_94 = (struct V_93 * ) V_92 -> V_44 ;
V_107 = ( V_92 -> V_19 - sizeof( struct V_120 ) ) /
sizeof( struct V_121 ) ;
V_44 = V_94 -> V_122 [ V_107 - 1 ] . V_123 ;
memcpy ( V_100 -> V_124 , V_44 ,
V_125 ) ;
V_106 = F_35 ( 0xffff , V_100 -> V_124 ,
V_125 ) ;
F_34 ( V_106 , & V_100 -> V_126 ) ;
V_102 = (struct V_101 * ) ( V_96 -> V_44 +
V_104 ) ;
V_105 = F_35 ( 0xffff , ( T_2 * ) V_98 ,
sizeof( struct V_97 ) + V_104 ) ;
F_34 ( V_105 , & V_102 -> V_127 ) ;
V_102 -> V_128 = V_84 ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 ,
V_33 , V_34 ,
V_12 , & V_13 , 12000 ,
F_22 , true ) ;
if ( error || V_13 != V_129 ||
V_12 [ 2 ] != V_47 ||
! F_36 ( V_12 [ 5 ] ) )
return error ? error : - V_90 ;
return 0 ;
}
static bool F_37 ( struct V_1 * V_1 , T_2 * V_18 , int V_25 )
{
if ( V_18 == NULL || V_25 < V_32 )
return false ;
if ( V_18 [ 0 ] == 0 && V_18 [ 1 ] == 0 )
return true ;
if ( V_25 == V_130 &&
V_18 [ V_46 ] ==
V_47 &&
V_18 [ V_48 ] == V_49 &&
V_18 [ V_50 ] == V_51 &&
V_18 [ 10 ] == V_84 )
return true ;
return false ;
}
static int F_38 ( struct V_1 * V_1 )
{
T_2 V_131 [] = { 0x04 , 0x00 ,
0x0B , 0x00 , 0x40 , 0x00 , 0x01 , 0x3b , 0x00 , 0x00 ,
0x20 , 0xc7 , 0x17
} ;
T_2 V_12 [ 11 ] ;
int V_13 ;
int error ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 ,
V_131 , sizeof( V_131 ) ,
V_12 , & V_13 ,
5000 , F_37 , false ) ;
if ( error )
return error ;
if ( V_13 == V_130 ||
V_12 [ V_46 ] ==
V_47 )
return - V_90 ;
if ( V_12 [ 0 ] == 0x00 && V_12 [ 1 ] == 0x00 )
return 0 ;
return - V_132 ;
}
static int F_39 ( struct V_1 * V_1 )
{
T_2 V_33 [] = { 0x04 , 0x00 , 0x05 , 0x00 , 0x2F , 0x00 , 0x01 } ;
T_2 V_12 [ 2 ] ;
int V_13 ;
int error ;
error = F_40 ( V_1 , 500 ) ;
if ( error < 0 )
return error ;
if ( V_1 -> V_67 != V_68 )
return - V_22 ;
if ( V_1 -> V_69 == V_70 )
return 0 ;
if ( V_1 -> V_69 != V_71 )
return - V_90 ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
V_13 = sizeof( V_12 ) ;
memset ( V_12 , 0 , V_13 ) ;
error = F_19 ( V_1 ,
V_33 , sizeof( V_33 ) ,
V_12 , & V_13 ,
5000 , F_25 ,
true ) ;
if ( error || V_12 [ 0 ] != 0x00 || V_12 [ 1 ] != 0x00 )
return error < 0 ? error : - V_90 ;
V_1 -> V_133 = false ;
V_1 -> V_69 = V_70 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_1 , const struct V_91 * V_92 )
{
struct V_134 * V_135 = & V_1 -> V_23 -> V_135 ;
const struct V_93 * V_94 = ( const void * ) V_92 -> V_44 ;
const struct V_121 * V_136 ;
const struct V_137 * V_138 ;
T_3 V_139 ;
T_6 V_140 , V_141 ;
T_5 V_142 , V_143 ;
T_5 V_144 ;
T_5 V_145 ;
int V_146 ;
int V_147 ;
V_139 = ( V_92 -> V_19 -
sizeof( struct V_120 ) ) /
sizeof( struct V_121 ) ;
V_136 = & V_94 -> V_122 [ V_139 - 1 ] ;
if ( V_136 -> V_148 != 0x00 ||
F_42 ( & V_136 -> V_149 ) != 0x01ff ) {
F_43 ( V_135 , L_1 , V_150 ) ;
return - V_22 ;
}
V_138 = ( const void * ) V_136 -> V_123 ;
V_145 = F_35 ( 0xffff , V_136 -> V_123 ,
V_151 ) ;
if ( V_145 != F_10 ( & V_138 -> V_126 ) ) {
F_43 ( V_135 , L_2 , V_150 ) ;
return - V_22 ;
}
V_140 = F_44 ( & V_138 -> V_152 ) ;
V_142 = F_10 ( & V_138 -> V_153 ) ;
V_141 = F_44 ( & V_138 -> V_154 ) ;
V_143 = F_10 ( & V_138 -> V_155 ) ;
if ( V_140 % V_156 ||
V_142 % V_156 ||
V_141 % V_156 ||
V_143 % V_156 ) {
F_43 ( V_135 , L_3 , V_150 ) ;
return - V_22 ;
}
V_146 = V_140 / V_156 -
V_157 ;
V_144 = 0xffffU ;
for ( V_147 = 0 ; V_147 < V_142 / V_156 ; V_147 ++ ) {
const T_2 * V_44 = V_94 -> V_122 [ V_146 + V_147 ] . V_123 ;
V_144 = F_35 ( V_144 , V_44 , V_156 ) ;
}
if ( V_144 != F_10 ( & V_138 -> V_144 ) ) {
F_43 ( V_135 , L_4 , V_150 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_1 ,
struct V_121 * V_158 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_159 * V_160 ;
struct V_101 * V_102 ;
T_2 V_33 [ V_103 ] ;
T_5 V_34 ;
T_2 V_148 ;
T_5 V_161 ;
T_5 V_162 ;
T_2 * V_123 ;
T_5 V_163 ;
T_5 V_127 ;
T_2 V_12 [ 11 ] ;
int V_13 ;
int error ;
V_148 = V_158 -> V_148 ;
V_161 = F_42 ( & V_158 -> V_149 ) ;
V_162 = F_42 ( & V_158 -> V_162 ) ;
V_123 = V_158 -> V_123 ;
memset ( V_33 , 0 , V_103 ) ;
V_96 = (struct V_95 * ) V_33 ;
V_98 = & V_96 -> V_113 ;
V_34 = sizeof( struct V_95 ) +
sizeof( struct V_159 ) +
V_109 +
sizeof( struct V_101 ) ;
F_34 ( V_110 , & V_96 -> V_111 ) ;
F_34 ( V_34 - 2 , & V_96 -> V_27 ) ;
V_96 -> V_112 = V_42 ;
V_98 -> V_114 = V_51 ;
V_98 -> V_115 = V_164 ;
V_163 = sizeof( struct V_159 ) + V_162 ;
F_34 ( V_163 , & V_98 -> V_117 ) ;
V_160 = (struct V_159 * ) V_96 -> V_44 ;
V_160 -> V_148 = V_148 ;
F_34 ( V_161 , & V_160 -> V_161 ) ;
memcpy ( V_160 -> V_165 , V_123 , V_162 ) ;
V_102 = (struct V_101 * ) ( V_96 -> V_44 +
V_163 ) ;
V_127 = F_35 ( 0xffff , ( T_2 * ) V_98 ,
sizeof( struct V_97 ) + V_163 ) ;
F_34 ( V_127 , & V_102 -> V_127 ) ;
V_102 -> V_128 = V_84 ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 , V_33 , V_34 ,
V_12 , & V_13 ,
500 , F_22 , true ) ;
if ( error || V_13 != V_166 ||
V_12 [ 2 ] != V_47 ||
! F_36 ( V_12 [ 5 ] ) )
return error < 0 ? error : - V_90 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_1 ,
const struct V_91 * V_92 )
{
struct V_134 * V_135 = & V_1 -> V_23 -> V_135 ;
struct V_121 * V_158 ;
struct V_93 * V_94 =
(struct V_93 * ) V_92 -> V_44 ;
int V_139 ;
int V_147 ;
int error ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
V_139 =
( V_92 -> V_19 - sizeof( struct V_120 ) ) /
sizeof( struct V_121 ) ;
for ( V_147 = 0 ; V_147 < ( V_139 - 1 ) ; V_147 ++ ) {
V_158 = & V_94 -> V_122 [ V_147 ] ;
error = F_45 ( V_1 , V_158 ) ;
if ( error ) {
F_43 ( V_135 , L_5 ,
V_150 , error ) ;
return error ;
}
}
return 0 ;
}
static int F_47 ( struct V_1 * V_1 , T_2 V_167 )
{
T_2 V_33 [ 8 ] = { 0x04 , 0x00 , 0x06 , 0x00 , 0x2f , 0x00 , 0x08 , 0x01 } ;
T_2 V_12 [ 6 ] ;
int V_13 ;
int error ;
V_33 [ 7 ] = V_167 ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 , V_33 , sizeof( V_33 ) ,
V_12 , & V_13 ,
500 , F_23 , false ) ;
if ( error || ! F_48 ( V_12 , 0x08 ) ||
! F_36 ( V_12 [ 5 ] ) )
return error < 0 ? error : - V_22 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_1 ,
T_2 V_168 , T_5 V_169 )
{
struct V_170 * V_171 ;
struct V_172 * V_173 ;
T_2 V_33 [ V_103 ] ;
int V_34 ;
T_2 V_12 [ 7 ] ;
int V_13 ;
T_2 V_174 ;
int error ;
memset ( V_33 , 0 , V_103 ) ;
V_171 = (struct V_170 * ) V_33 ;
V_173 = (struct V_172 * )
V_171 -> V_173 ;
V_34 = sizeof( struct V_170 ) +
sizeof( struct V_172 ) ;
switch ( V_168 ) {
case V_175 :
V_174 = V_176 ;
break;
case V_177 :
V_174 = V_178 ;
break;
case V_179 :
V_174 = V_180 ;
break;
default:
return - V_22 ;
}
F_34 ( V_110 , & V_171 -> V_111 ) ;
F_34 ( V_34 - ( 4 - V_174 ) - 2 ,
& V_171 -> V_27 ) ;
V_171 -> V_112 = V_40 ;
V_171 -> V_115 = V_181 ;
V_173 -> V_168 = V_168 ;
V_173 -> V_174 = V_174 ;
F_50 ( ( T_6 ) V_169 , & V_173 -> V_182 ) ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 , V_33 , V_34 ,
V_12 , & V_13 ,
500 , F_23 , false ) ;
if ( error || V_12 [ 5 ] != V_168 ||
V_12 [ 6 ] != V_174 ||
! F_48 ( V_12 , V_181 ) )
return error < 0 ? error : - V_22 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_1 ,
T_2 V_168 , T_5 * V_169 )
{
struct V_170 * V_171 ;
struct V_183 * V_173 ;
T_2 V_33 [ V_103 ] ;
int V_34 ;
T_2 V_12 [ 11 ] ;
int V_13 ;
T_2 V_174 ;
T_5 V_184 , V_147 ;
int error ;
memset ( V_33 , 0 , V_103 ) ;
V_171 = (struct V_170 * ) V_33 ;
V_173 = (struct V_183 * )
V_171 -> V_173 ;
V_34 = sizeof( struct V_170 ) +
sizeof( struct V_183 ) ;
* V_169 = 0 ;
switch ( V_168 ) {
case V_175 :
V_174 = V_176 ;
break;
case V_177 :
V_174 = V_178 ;
break;
case V_179 :
V_174 = V_180 ;
break;
default:
return - V_22 ;
}
F_34 ( V_185 , & V_171 -> V_111 ) ;
F_34 ( V_34 - 2 , & V_171 -> V_27 ) ;
V_171 -> V_112 = V_40 ;
V_171 -> V_115 = V_186 ;
V_173 -> V_168 = V_168 ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 , V_33 , V_34 ,
V_12 , & V_13 ,
500 , F_23 , false ) ;
if ( error || V_12 [ 5 ] != V_168 || V_12 [ 6 ] == 0 ||
! F_48 ( V_12 , V_186 ) )
return error < 0 ? error : - V_22 ;
V_184 = 0 ;
for ( V_147 = 0 ; V_147 < V_174 ; V_147 ++ )
V_184 |= ( 0xff << ( V_147 * 8 ) ) ;
* V_169 = F_10 ( & V_12 [ 7 ] ) & V_184 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_1 )
{
struct V_170 * V_171 ;
T_2 V_33 [ 10 ] ;
T_2 V_12 [ 7 ] ;
int V_13 ;
int error ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
V_171 = (struct V_170 * ) V_33 ;
F_34 ( V_185 , & V_171 -> V_111 ) ;
F_34 ( sizeof( V_33 ) - 2 , & V_171 -> V_27 ) ;
V_171 -> V_112 = V_40 ;
V_171 -> V_115 = V_181 ;
V_171 -> V_173 [ 0 ] = V_187 ;
V_171 -> V_173 [ 1 ] = 0x01 ;
V_171 -> V_173 [ 2 ] = 0x01 ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 , V_33 , sizeof( V_33 ) ,
V_12 , & V_13 ,
500 , F_23 , false ) ;
if ( error || V_12 [ 5 ] != V_187 ||
! F_48 ( V_12 , V_181 ) ||
V_12 [ 6 ] != 0x01 )
return error < 0 ? error : - V_22 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_1 , T_2 V_69 )
{
T_2 V_33 [] = { 0x05 , 0x00 , 0x00 , 0x08 } ;
T_2 V_12 [ 5 ] ;
int V_13 ;
int error ;
V_33 [ 2 ] = V_69 & V_188 ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 , V_33 , sizeof( V_33 ) ,
V_12 , & V_13 ,
500 , F_27 , false ) ;
if ( error || ( ( V_12 [ 3 ] & V_188 ) != V_69 ) )
return - V_22 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_1 ,
T_2 V_189 , T_5 V_190 )
{
struct V_134 * V_135 = & V_1 -> V_23 -> V_135 ;
T_2 V_167 ;
int error ;
if ( V_1 -> V_69 != V_71 )
return 0 ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
if ( F_55 ( V_1 ) == V_15 ) {
F_56 ( V_1 , V_191 ) ;
}
if ( F_57 ( V_1 ) &&
F_55 ( V_1 ) != V_191 )
if ( F_51 ( V_1 ,
V_179 ,
& V_1 -> V_16 ) != 0 )
F_58 ( V_1 , V_17 ) ;
if ( F_55 ( V_1 ) == V_189 ) {
if ( V_189 == V_191 ||
V_189 == V_192 ||
V_189 == V_193 ||
F_59 ( V_1 ) == V_190 ) {
return 0 ;
}
}
if ( V_189 == V_191 ) {
error = F_53 ( V_1 , V_194 ) ;
if ( error ) {
F_43 ( V_135 , L_6 , error ) ;
return error ;
}
F_56 ( V_1 , V_191 ) ;
return 0 ;
}
if ( F_55 ( V_1 ) == V_191 ) {
error = F_53 ( V_1 , V_195 ) ;
if ( error ) {
F_43 ( V_135 , L_7 , error ) ;
return error ;
}
}
if ( V_189 == V_192 ) {
error = F_47 ( V_1 ,
V_196 ) ;
if ( error ) {
F_43 ( V_135 , L_8 , error ) ;
return error ;
}
F_56 ( V_1 , V_192 ) ;
} else if ( V_189 == V_193 ) {
error = F_47 ( V_1 ,
V_197 ) ;
if ( error ) {
F_43 ( V_135 , L_9 , error ) ;
return error ;
}
F_56 ( V_1 , V_193 ) ;
} else {
if ( F_57 ( V_1 ) ||
V_190 != F_59 ( V_1 ) )
if ( F_49 ( V_1 ,
V_179 ,
V_190 ) == 0 )
F_58 ( V_1 , V_190 ) ;
if ( V_190 <= V_198 )
V_167 = V_199 ;
else
V_167 = V_200 ;
error = F_47 ( V_1 , V_167 ) ;
if ( error ) {
F_43 ( V_135 , L_10 ,
V_167 , error ) ;
return error ;
}
F_9 ( V_1 , NULL , NULL , NULL ) ;
F_52 ( V_1 ) ;
F_56 ( V_1 ,
F_60 ( V_190 ) ) ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_1 )
{
T_2 V_33 [] = { 0x04 , 0x00 , 0x05 , 0x00 , 0x2f , 0x00 , 0x04 } ;
T_2 V_12 [ 6 ] ;
int V_13 ;
int error ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 ,
V_33 , sizeof( V_33 ) ,
V_12 , & V_13 ,
500 , F_23 , true ) ;
if ( error || ! F_48 ( V_12 , 0x04 ) )
return - V_22 ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_1 )
{
T_2 V_33 [] = { 0x04 , 0x00 , 0x05 , 0x00 , 0x2f , 0x00 , 0x03 } ;
T_2 V_12 [ 6 ] ;
int V_13 ;
int error ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 ,
V_33 , sizeof( V_33 ) ,
V_12 , & V_13 ,
500 , F_23 , true ) ;
if ( error || ! F_48 ( V_12 , 0x03 ) )
return - V_22 ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_1 ,
T_2 V_201 )
{
struct V_170 * V_171 ;
T_2 V_33 [ 8 ] ;
T_2 V_12 [ 6 ] ;
int V_13 ;
int error ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
V_171 = (struct V_170 * ) V_33 ;
F_34 ( V_110 , & V_171 -> V_111 ) ;
F_34 ( sizeof( V_33 ) - 2 , & V_171 -> V_27 ) ;
V_171 -> V_112 = V_40 ;
V_171 -> V_115 = V_202 ;
V_171 -> V_173 [ 0 ] = V_201 ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 ,
V_33 , sizeof( V_33 ) ,
V_12 , & V_13 ,
5000 , F_23 , true ) ;
if ( error || ! F_48 ( V_12 , V_202 ) ||
! F_36 ( V_12 [ 5 ] ) )
return error < 0 ? error : - V_90 ;
return 0 ;
}
static T_1 F_64 ( struct V_134 * V_135 ,
struct V_203 * V_204 ,
const char * V_18 , T_3 V_205 )
{
struct V_1 * V_1 = F_65 ( V_135 ) ;
int error , V_206 ;
error = F_62 ( V_1 ) ;
if ( error )
return error ;
V_206 = F_63 ( V_1 ,
V_207 ) ;
if ( V_206 )
goto V_208;
V_206 = F_63 ( V_1 ,
V_209 ) ;
if ( V_206 )
goto V_208;
V_208:
error = F_61 ( V_1 ) ;
if ( error || V_206 )
return error ? error : V_206 ;
return V_205 ;
}
static T_7 F_66 ( T_7 V_182 , int V_210 )
{
if ( V_182 >> ( V_210 - 1 ) )
V_182 |= - 1 << V_210 ;
return V_182 ;
}
static T_7 F_67 ( T_2 V_211 , T_2 * V_18 , int V_30 )
{
int V_212 ;
bool V_213 ;
bool V_214 ;
T_7 V_182 ;
V_212 = ( V_211 & 0x07 ) ;
V_213 = ( ( V_211 & 0x10 ) == 0x00 ) ;
V_214 = ( ( V_211 & 0x20 ) == 0x00 ) ;
if ( V_30 < V_212 )
return 0 ;
switch ( V_212 ) {
case 1 :
V_182 = V_18 [ 0 ] ;
break;
case 2 :
if ( V_213 )
V_182 = F_42 ( V_18 ) ;
else
V_182 = F_10 ( V_18 ) ;
break;
case 4 :
if ( V_213 )
V_182 = F_68 ( V_18 ) ;
else
V_182 = F_44 ( V_18 ) ;
break;
default:
V_182 = 0 ;
break;
}
if ( ! V_214 )
V_182 = F_66 ( V_182 , V_212 * 8 ) ;
return V_182 ;
}
static void F_69 ( struct V_1 * V_1 ,
int * V_215 , int * V_216 )
{
if ( V_1 -> V_215 != 0 ) {
* V_215 = V_1 -> V_215 ;
* V_216 = ( V_1 -> V_217 == * V_215 ) ?
V_1 -> V_218 : V_1 -> V_217 ;
} else {
* V_216 = F_11 ( V_1 -> V_217 , V_1 -> V_218 ) ;
* V_215 = F_70 ( V_1 -> V_217 , V_1 -> V_218 ) ;
}
}
static int F_71 ( struct V_1 * V_1 ,
T_2 V_115 , T_2 V_219 , int * V_212 ,
int * V_220 , int * V_221 , int * V_222 )
{
struct V_170 * V_223 ;
T_2 V_33 [ 12 ] ;
T_2 V_12 [ 256 ] ;
int V_13 ;
int V_224 ;
int V_182 ;
T_5 V_225 ;
int V_226 ;
bool V_227 ;
int V_228 , V_205 , V_229 ;
int V_230 , V_231 , V_232 , V_233 , V_234 ;
int V_215 , V_216 ;
int V_147 ;
int error ;
if ( V_115 != V_235 ||
( V_219 != V_236 &&
V_219 != V_237 ) ||
! V_212 || ! V_220 || ! V_221 || ! V_222 )
return - V_22 ;
* V_220 = V_238 ;
* V_221 = V_239 ;
V_228 = V_205 = V_234 = 0 ;
V_215 = V_216 = 0 ;
if ( * V_212 == 0 ) {
V_227 = true ;
V_225 = 0 ;
* V_212 = 4 ;
V_230 = V_238 ;
V_231 = V_239 ;
V_232 = V_233 = V_234 = 0 ;
if ( V_219 == V_236 ) {
if ( V_1 -> V_240 == 0 ) {
F_69 ( V_1 ,
& V_215 , & V_216 ) ;
V_1 -> V_240 =
( V_215 + 3 ) & ~ 3u ;
}
V_229 =
( V_1 -> V_240 + 7 ) & ~ 7u ;
} else {
V_229 = 2 ;
}
} else {
V_227 = false ;
if ( * V_212 > 4 )
* V_212 = 4 ;
if ( V_219 == V_236 ) {
V_225 = V_1 -> V_240 * ( * V_212 ) ;
if ( V_1 -> V_215 == V_1 -> V_217 )
V_216 = V_1 -> V_218 ;
else
V_216 = V_1 -> V_217 ;
V_229 = ( ( V_1 -> V_240 + 7 ) &
~ 7u ) * V_216 ;
} else {
V_225 = 2 ;
V_229 = V_1 -> V_217 +
V_1 -> V_218 ;
V_229 = ( V_229 + 3 ) & ~ 3u ;
}
}
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
V_223 = (struct V_170 * ) V_33 ;
F_34 ( V_110 , & V_223 -> V_111 ) ;
F_34 ( sizeof( V_33 ) - 2 , & V_223 -> V_27 ) ;
V_223 -> V_112 = V_40 ;
V_223 -> V_115 = V_115 ;
do {
V_226 = ( 256 - V_241 ) /
( * V_212 ) ;
V_226 = F_11 ( V_226 , V_229 - V_205 ) ;
V_224 = V_226 * ( * V_212 ) ;
F_34 ( V_225 , & V_223 -> V_173 [ 0 ] ) ;
F_34 ( V_224 , & V_223 -> V_173 [ 2 ] ) ;
V_223 -> V_173 [ 4 ] = V_219 ;
V_13 = V_241 + V_224 ;
error = F_19 ( V_1 ,
V_33 , sizeof( V_33 ) ,
V_12 , & V_13 ,
500 , F_23 ,
true ) ;
if ( error || V_13 < V_241 ||
! F_48 ( V_12 , V_115 ) ||
! F_36 ( V_12 [ 5 ] ) ||
V_12 [ 6 ] != V_219 )
return ( error < 0 ) ? error : - V_90 ;
V_224 = F_10 ( & V_12 [ 7 ] ) ;
if ( V_224 == 0 )
break;
* V_212 = ( V_12 [ 9 ] & V_242 ) ;
if ( V_224 < * V_212 )
return - V_22 ;
if ( V_227 &&
V_219 == V_237 ) {
* V_220 = F_67 (
V_12 [ 9 ] ,
& V_12 [ V_241 ] ,
* V_212 ) ;
* V_221 = F_67 (
V_12 [ 9 ] ,
& V_12 [ V_241 +
* V_212 ] ,
* V_212 ) ;
break;
}
V_225 += V_224 ;
for ( V_147 = 10 ; V_147 < ( V_224 + V_241 ) ;
V_147 += * V_212 ) {
V_182 = F_67 ( V_12 [ 9 ] ,
& V_12 [ V_147 ] , * V_212 ) ;
* V_221 = F_11 ( V_182 , * V_221 ) ;
* V_220 = F_70 ( V_182 , * V_220 ) ;
if ( V_219 == V_236 &&
V_234 < V_1 -> V_240 &&
V_227 ) {
if ( ! V_232 || V_182 > V_232 / 2 ) {
V_231 = F_11 ( V_182 , V_231 ) ;
V_230 = F_70 ( V_182 , V_230 ) ;
V_233 += V_182 ;
V_234 ++ ;
V_232 = V_233 / V_234 ;
}
}
V_228 += V_182 ;
V_205 ++ ;
if ( V_205 >= V_229 )
goto V_243;
}
} while ( true );
V_243:
* V_222 = V_205 ? ( V_228 / V_205 ) : 0 ;
if ( V_227 &&
V_219 == V_236 ) {
if ( V_234 == 0 )
return 0 ;
if ( V_234 == V_1 -> V_240 ) {
V_1 -> V_215 = V_1 -> V_215 ?
V_1 -> V_215 : V_215 ;
} else if ( V_234 == V_215 ) {
V_1 -> V_215 = V_1 -> V_215 ?
V_1 -> V_215 : V_215 ;
V_1 -> V_240 = V_215 ;
} else {
V_1 -> V_215 = V_1 -> V_215 ?
V_1 -> V_215 : V_216 ;
V_1 -> V_240 = V_234 ;
}
* V_221 = V_231 ;
* V_220 = V_230 ;
* V_222 = V_232 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_1 ,
int * V_244 , int * V_245 , int * V_246 ,
int * V_247 , int * V_248 , int * V_249 )
{
int V_212 ;
int error ;
* V_244 = * V_245 = * V_246 = 0 ;
* V_247 = * V_248 = * V_249 = 0 ;
V_212 = 0 ;
error = F_71 ( V_1 ,
V_235 ,
V_236 ,
& V_212 ,
V_244 , V_245 , V_246 ) ;
if ( error )
return error ;
error = F_71 ( V_1 ,
V_235 ,
V_236 ,
& V_212 ,
V_247 , V_248 , V_249 ) ;
return error ;
}
static int F_73 ( struct V_1 * V_1 ,
int * V_250 , int * V_251 ,
int * V_252 , int * V_253 , int * V_254 )
{
int V_212 ;
int error ;
* V_250 = * V_251 = 0 ;
* V_252 = * V_253 = * V_254 = 0 ;
V_212 = 0 ;
error = F_71 ( V_1 ,
V_235 ,
V_237 ,
& V_212 ,
V_252 , V_253 , V_254 ) ;
if ( error )
return error ;
* V_250 = * V_252 ;
* V_251 = * V_253 ;
error = F_71 ( V_1 ,
V_235 ,
V_237 ,
& V_212 ,
V_252 , V_253 , V_254 ) ;
return error ;
}
static T_1 F_74 ( struct V_1 * V_1 )
{
struct V_170 * V_171 ;
T_2 V_33 [ 7 ] ;
T_2 V_12 [ 6 ] ;
int V_13 ;
int error ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
V_171 = (struct V_170 * ) V_33 ;
F_34 ( V_110 , & V_171 -> V_111 ) ;
F_34 ( sizeof( V_33 ) - 2 , & V_171 -> V_27 ) ;
V_171 -> V_112 = V_40 ;
V_171 -> V_115 = V_255 ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 ,
V_33 , sizeof( V_33 ) ,
V_12 , & V_13 ,
500 , F_23 , true ) ;
if ( error || V_13 != sizeof( V_12 ) ||
! F_48 ( V_12 ,
V_255 ) ||
! F_36 ( V_12 [ 5 ] ) )
return error ? error : - V_90 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_1 ,
T_2 V_115 , T_2 V_256 , int V_257 ,
int * V_258 , int * V_259 , int * V_260 ,
T_2 * V_261 )
{
struct V_170 * V_171 ;
struct V_262 * V_263 ;
T_2 V_33 [ 12 ] ;
T_2 V_12 [ 256 ] ;
int V_13 ;
int V_226 ;
int V_224 ;
T_5 V_225 ;
T_7 V_182 ;
int V_228 , V_205 ;
int V_212 ;
T_7 * V_264 ;
int V_147 ;
int error ;
if ( V_115 != V_265 ||
( V_256 > V_266 ) ||
! V_258 || ! V_259 || ! V_260 )
return - V_22 ;
V_264 = ( T_7 * ) V_261 ;
* V_258 = V_238 ;
* V_259 = V_239 ;
V_228 = V_205 = 0 ;
V_225 = 0 ;
V_226 = ( 256 - V_241 ) / 4 ;
V_224 = V_226 * 4 ;
V_171 = (struct V_170 * ) V_33 ;
F_34 ( V_110 , & V_171 -> V_111 ) ;
F_34 ( sizeof( V_33 ) - 2 , & V_171 -> V_27 ) ;
V_171 -> V_112 = V_40 ;
V_171 -> V_115 = V_115 ;
V_263 = (struct V_262 * )
V_171 -> V_173 ;
do {
F_34 ( V_225 , & V_263 -> V_267 ) ;
F_34 ( V_226 ,
& V_263 -> V_226 ) ;
V_263 -> V_268 = V_256 ;
V_13 = V_241 + V_224 ;
error = F_19 ( V_1 ,
V_33 , sizeof( V_33 ) ,
V_12 , & V_13 ,
500 , F_23 , true ) ;
if ( error || V_13 < V_241 ||
! F_48 ( V_12 , V_115 ) ||
! F_36 ( V_12 [ 5 ] ) ||
V_12 [ 6 ] != V_256 )
return error ? error : - V_90 ;
V_226 = F_10 ( & V_12 [ 7 ] ) ;
if ( V_226 == 0 )
break;
V_212 = ( V_12 [ 9 ] & V_242 ) ;
V_225 += V_226 ;
if ( V_226 ) {
for ( V_147 = V_241 ;
V_147 < ( V_226 * V_212 +
V_241 ) ;
V_147 += V_212 ) {
V_182 = F_67 ( V_12 [ 9 ] ,
& V_12 [ V_147 ] , V_212 ) ;
* V_259 = F_11 ( V_182 , * V_259 ) ;
* V_258 = F_70 ( V_182 , * V_258 ) ;
if ( V_264 )
F_50 ( V_182 , & V_264 [ V_205 ] ) ;
V_228 += V_182 ;
V_205 ++ ;
}
}
if ( V_205 >= V_257 )
break;
V_226 = ( sizeof( V_12 ) -
V_241 ) / V_212 ;
V_224 = V_226 * V_212 ;
} while ( true );
* V_260 = V_205 ? ( V_228 / V_205 ) : 0 ;
return 0 ;
}
static T_1 F_76 ( struct V_134 * V_135 ,
struct V_203 * V_204 , char * V_18 )
{
struct V_1 * V_1 = F_65 ( V_135 ) ;
int V_244 , V_245 , V_246 ;
int V_247 , V_248 , V_249 ;
int V_250 , V_251 ;
int V_252 , V_253 , V_254 ;
int V_269 , V_270 , V_271 ;
int V_272 , V_273 , V_274 ;
int V_275 , V_276 , V_277 ;
int V_278 , V_279 , V_280 ;
int V_281 , V_282 , V_283 ;
int V_284 , V_285 , V_286 ;
int error , V_287 ;
int V_19 ;
if ( V_1 -> V_69 != V_71 )
return - V_288 ;
error = F_62 ( V_1 ) ;
if ( error )
return error ;
V_250 = V_251 = 0 ;
error = F_72 ( V_1 ,
& V_244 , & V_245 ,
& V_246 , & V_247 ,
& V_248 , & V_249 ) ;
if ( error )
goto V_208;
error = F_73 ( V_1 ,
& V_250 , & V_251 ,
& V_252 , & V_253 ,
& V_254 ) ;
if ( error )
goto V_208;
error = F_74 ( V_1 ) ;
if ( error )
goto V_208;
error = F_75 ( V_1 ,
V_265 ,
V_289 ,
V_1 -> V_217 * V_1 -> V_218 ,
& V_269 , & V_270 ,
& V_271 ,
NULL ) ;
if ( error )
goto V_208;
error = F_75 ( V_1 ,
V_265 ,
V_290 ,
V_1 -> V_217 + V_1 -> V_218 ,
& V_272 , & V_273 ,
& V_274 ,
NULL ) ;
if ( error )
goto V_208;
error = F_75 ( V_1 ,
V_265 ,
V_291 ,
V_1 -> V_217 * V_1 -> V_218 ,
& V_275 , & V_276 ,
& V_277 ,
NULL ) ;
if ( error )
goto V_208;
error = F_75 ( V_1 ,
V_265 ,
V_266 ,
V_1 -> V_217 + V_1 -> V_218 ,
& V_278 , & V_279 ,
& V_280 ,
NULL ) ;
if ( error )
goto V_208;
error = F_75 ( V_1 ,
V_265 ,
V_292 ,
V_1 -> V_217 * V_1 -> V_218 ,
& V_281 , & V_282 ,
& V_283 ,
NULL ) ;
if ( error )
goto V_208;
error = F_75 ( V_1 ,
V_265 ,
V_293 ,
V_1 -> V_217 + V_1 -> V_218 ,
& V_284 , & V_285 ,
& V_286 ,
NULL ) ;
if ( error )
goto V_208;
V_208:
V_287 = F_61 ( V_1 ) ;
if ( V_287 || error )
return V_287 ? V_287 : error ;
V_19 = F_77 ( V_18 , V_294 , L_11 ,
V_245 , V_244 , V_246 ,
V_248 , V_247 , V_249 ,
V_250 , V_251 ,
V_253 , V_252 , V_254 ) ;
V_19 += F_77 ( V_18 + V_19 , V_294 - V_19 ,
L_12 ,
V_270 , V_269 , V_271 ,
V_273 , V_272 , V_274 ,
V_276 , V_275 , V_277 ,
V_279 , V_278 , V_280 ,
V_282 , V_281 , V_283 ,
V_285 , V_284 , V_286 ) ;
return V_19 ;
}
static bool F_78 ( struct V_1 * V_1 ,
T_2 * V_18 , int V_25 )
{
if ( F_48 ( V_18 , 0x02 ) )
return true ;
return false ;
}
static int F_79 ( struct V_1 * V_1 )
{
T_2 V_295 [] = { 0x04 , 0x00 , 0x0b , 0x00 , 0x40 , 0x00 ,
0x01 , 0x3c , 0x00 , 0x00 , 0xb0 , 0x42 , 0x17
} ;
T_2 V_12 [ V_296 ] ;
int V_13 ;
int error ;
V_13 = V_296 ;
error = F_19 ( V_1 ,
V_295 , sizeof( V_295 ) ,
V_12 , & V_13 ,
500 , F_22 , false ) ;
if ( error || V_13 != V_296 ||
! F_36 ( V_12 [ 5 ] ) )
return error ? error : - V_24 ;
memcpy ( & V_1 -> V_297 [ 0 ] , & V_12 [ 8 ] , 5 ) ;
V_1 -> V_297 [ 5 ] = '-' ;
memcpy ( & V_1 -> V_297 [ 6 ] , & V_12 [ 13 ] , 6 ) ;
V_1 -> V_297 [ 12 ] = '-' ;
memcpy ( & V_1 -> V_297 [ 13 ] , & V_12 [ 19 ] , 2 ) ;
V_1 -> V_297 [ 15 ] = '\0' ;
V_1 -> V_298 = V_12 [ 22 ] ;
V_1 -> V_299 = V_12 [ 23 ] ;
return 0 ;
}
static int F_80 ( struct V_1 * V_1 )
{
T_2 V_300 [] = {
0x04 , 0x00 , 0x05 , 0x00 , 0x2f , 0x00 , 0x02
} ;
T_2 V_12 [ 71 ] ;
int V_13 ;
T_5 V_301 ;
int error ;
V_13 = sizeof( V_12 ) ;
error = F_19 ( V_1 ,
V_300 , sizeof( V_300 ) ,
V_12 , & V_13 ,
2000 , F_78 , false ) ;
if ( error || V_13 < sizeof( V_12 ) )
return error ? error : - V_24 ;
V_301 = F_10 ( & V_12 [ 7 ] ) ;
if ( ( V_301 & V_302 ) !=
V_303 )
return - V_22 ;
V_1 -> V_298 = V_12 [ 15 ] ;
V_1 -> V_299 = V_12 [ 16 ] ;
V_1 -> V_217 = V_12 [ 52 ] ;
V_1 -> V_218 = V_12 [ 53 ] ;
V_1 -> V_304 = F_10 ( & V_12 [ 54 ] ) / 100 ;
V_1 -> V_305 = F_10 ( & V_12 [ 56 ] ) / 100 ;
V_1 -> V_306 = F_10 ( & V_12 [ 58 ] ) ;
V_1 -> V_307 = F_10 ( & V_12 [ 60 ] ) ;
V_1 -> V_308 = F_10 ( & V_12 [ 62 ] ) ;
V_1 -> V_309 = V_12 [ 64 ] & 0x01 ;
V_1 -> V_310 = V_12 [ 65 ] & 0x01 ;
V_1 -> V_311 = ( V_12 [ 70 ] << 3 ) & V_312 ;
memcpy ( & V_1 -> V_297 [ 0 ] , & V_12 [ 33 ] , 5 ) ;
V_1 -> V_297 [ 5 ] = '-' ;
memcpy ( & V_1 -> V_297 [ 6 ] , & V_12 [ 38 ] , 6 ) ;
V_1 -> V_297 [ 12 ] = '-' ;
memcpy ( & V_1 -> V_297 [ 13 ] , & V_12 [ 44 ] , 2 ) ;
V_1 -> V_297 [ 15 ] = '\0' ;
if ( ! V_1 -> V_217 || ! V_1 -> V_218 ||
! V_1 -> V_304 || ! V_1 -> V_305 ||
! V_1 -> V_306 || ! V_1 -> V_307 || ! V_1 -> V_308 )
return - V_22 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_1 )
{
struct V_134 * V_135 = & V_1 -> V_23 -> V_135 ;
int error ;
if ( V_1 -> V_67 != V_68 )
return - V_132 ;
switch ( V_1 -> V_69 ) {
case V_70 :
error = F_38 ( V_1 ) ;
if ( error ) {
F_79 ( V_1 ) ;
goto V_243;
}
V_1 -> V_69 = V_71 ;
case V_71 :
error = F_54 ( V_1 ,
V_192 , 0 ) ;
if ( error )
F_82 ( V_135 , L_13 ,
V_150 ) ;
error = F_80 ( V_1 ) ;
if ( error )
goto V_243;
if ( memcmp ( V_1 -> V_297 , V_297 ,
strlen ( V_297 ) ) != 0 ) {
F_43 ( V_135 , L_14 ,
V_150 , V_1 -> V_297 ) ;
error = - V_22 ;
}
break;
default:
error = - V_22 ;
}
V_243:
return error ;
}
static bool F_83 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
int V_27 ;
if ( F_84 ( & V_3 -> V_7 ) ) {
if ( V_3 -> V_43 == false )
return false ;
F_5 ( V_1 , V_3 -> V_313 ,
V_32 ) ;
V_27 = F_10 ( V_3 -> V_313 ) ;
V_27 = ( V_27 <= V_32 ) ?
V_32 : V_27 ;
if ( V_27 > V_32 )
F_5 ( V_1 ,
V_3 -> V_313 , V_27 ) ;
if ( ! ( V_3 -> V_9 &&
V_3 -> V_9 ( V_1 ,
V_3 -> V_313 , V_27 ) ) ) {
V_27 = 0 ;
if ( V_3 -> V_13 )
V_27 = * V_3 -> V_13 ;
F_9 ( V_1 ,
V_3 -> V_12 ,
& V_27 ,
V_3 -> V_9 ) ;
if ( V_3 -> V_13 && V_27 != 0 ) {
* V_3 -> V_13 = V_27 ;
F_14 ( & V_3 -> V_7 ) ;
F_85 ( & V_3 -> V_6 ) ;
}
return false ;
}
if ( V_3 -> V_12 && V_3 -> V_13 ) {
* V_3 -> V_13 = ( * V_3 -> V_13 < V_27 ) ?
* V_3 -> V_13 : V_27 ;
memcpy ( V_3 -> V_12 , V_3 -> V_313 ,
* V_3 -> V_13 ) ;
}
F_14 ( & V_3 -> V_7 ) ;
F_85 ( & V_3 -> V_6 ) ;
return false ;
}
return true ;
}
static void F_86 ( struct V_1 * V_1 ,
const struct V_314 * V_315 )
{
struct V_316 * V_317 = V_1 -> V_317 ;
T_2 V_318 = V_315 -> V_319 [ V_320 ] ;
V_318 = ( V_318 << V_321 ) & V_312 ;
if ( V_1 -> V_311 & V_322 ) {
F_87 ( V_317 , V_323 ,
! ! ( V_318 & V_322 ) ) ;
}
if ( V_1 -> V_311 & V_324 ) {
F_87 ( V_317 , V_325 ,
! ! ( V_318 & V_324 ) ) ;
}
if ( V_1 -> V_311 & V_326 ) {
F_87 ( V_317 , V_327 ,
! ! ( V_318 & V_326 ) ) ;
}
F_88 ( V_317 ) ;
}
static void F_89 ( struct V_1 * V_1 ,
const struct V_328 * V_329 )
{
struct V_316 * V_317 = V_1 -> V_317 ;
T_2 V_330 = F_90 ( V_329 -> V_331 ) ;
int V_332 = F_91 ( V_329 -> V_331 ) ;
int V_333 , V_334 ;
if ( V_330 == V_335 )
return;
F_92 ( V_317 , V_332 ) ;
F_93 ( V_317 , V_336 , true ) ;
V_333 = ( V_329 -> V_337 << 8 ) | V_329 -> V_338 ;
if ( V_1 -> V_309 )
V_333 = V_1 -> V_306 - V_333 ;
F_94 ( V_317 , V_339 , V_333 ) ;
V_334 = ( V_329 -> V_340 << 8 ) | V_329 -> V_341 ;
if ( V_1 -> V_310 )
V_334 = V_1 -> V_307 - V_334 ;
F_94 ( V_317 , V_342 , V_334 ) ;
F_94 ( V_317 , V_343 ,
V_329 -> V_344 ) ;
F_94 ( V_317 , V_345 ,
V_329 -> V_346 ) ;
F_94 ( V_317 , V_347 ,
V_329 -> V_348 ) ;
F_94 ( V_317 , V_349 ,
V_329 -> V_350 ) ;
F_94 ( V_317 , V_351 ,
V_329 -> V_352 ) ;
F_94 ( V_317 , V_353 ,
V_329 -> V_354 ) ;
}
static void F_95 ( struct V_1 * V_1 ,
const struct V_314 * V_315 )
{
struct V_316 * V_317 = V_1 -> V_317 ;
unsigned int V_355 ;
int V_147 ;
V_355 = V_315 -> V_319 [ V_356 ] &
V_357 ;
for ( V_147 = 0 ; V_147 < V_355 ; V_147 ++ )
F_89 ( V_1 ,
& V_315 -> V_358 [ V_147 ] ) ;
F_96 ( V_317 ) ;
F_88 ( V_317 ) ;
}
static int F_97 ( struct V_1 * V_1 )
{
struct V_134 * V_135 = & V_1 -> V_23 -> V_135 ;
struct V_314 V_315 ;
int V_20 ;
T_2 V_112 ;
unsigned int V_359 ;
if ( V_1 -> V_67 != V_68 ||
V_1 -> V_69 != V_71 ) {
F_43 ( V_135 , L_15 ,
V_1 -> V_67 , V_1 -> V_69 ) ;
return - V_22 ;
}
V_20 = F_5 ( V_1 , ( T_2 * ) & V_315 ,
V_32 ) ;
if ( V_20 != V_32 ) {
F_43 ( V_135 , L_16 , V_20 ) ;
return - V_22 ;
}
V_359 = F_10 (
& V_315 . V_319 [ V_54 ] ) ;
if ( V_359 < V_32 ) {
F_43 ( V_135 , L_17 ,
V_359 , V_315 . V_319 [ 0 ] ,
V_315 . V_319 [ 1 ] ) ;
return - V_22 ;
}
if ( V_359 == V_32 )
return 0 ;
V_20 = F_5 ( V_1 , ( T_2 * ) & V_315 , V_359 ) ;
if ( V_20 != V_359 ) {
F_43 ( V_135 , L_18 ,
V_359 , V_20 ) ;
return - V_22 ;
}
V_112 = V_315 . V_319 [ V_46 ] ;
if ( V_112 == V_82 &&
V_359 == V_83 ) {
return 0 ;
} else if ( V_112 != V_74 &&
V_112 != V_77 &&
V_112 != V_78 &&
V_112 != V_79 ) {
F_43 ( V_135 , L_19 , V_112 ) ;
return - V_22 ;
}
if ( V_112 == V_74 &&
( V_359 < V_75 ||
V_359 > V_76 ) ) {
F_43 ( V_135 , L_20 , V_359 ) ;
return 0 ;
}
if ( ( V_112 == V_77 ||
V_112 == V_78 ||
V_112 == V_79 ) &&
( V_359 < V_80 ||
V_359 > V_81 ) ) {
F_43 ( V_135 , L_21 , V_359 ) ;
return 0 ;
}
if ( V_112 == V_74 )
F_95 ( V_1 , & V_315 ) ;
else
F_86 ( V_1 , & V_315 ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_1 ) { return 0 ; }
static int F_99 ( struct V_1 * V_1 ) { return 0 ; }
