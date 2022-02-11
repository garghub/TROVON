static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 )
{
int V_8 = ( V_6 == NULL || V_7 == 0 ) ;
T_1 V_9 [ 1 + V_5 ] ;
memset ( V_9 , 0 , 1 + V_5 ) ;
V_9 [ 0 ] = V_3 ;
memcpy ( & V_9 [ 1 ] , V_4 , V_5 ) ;
if ( V_8 )
return F_2 ( V_2 , V_9 , 1 + V_5 ) ;
else
return F_3 ( V_2 , V_9 , 1 + V_5 , V_6 , V_7 , 0 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_10 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
T_1 V_14 [ 2 ] , V_15 ;
if ( V_12 -> V_16 [ V_17 ] == V_10 )
return;
V_14 [ 0 ] = V_17 ;
V_14 [ 1 ] = V_10 ;
F_1 ( V_2 , V_18 , V_14 , 2 , & V_15 , 1 ) ;
if ( V_15 != 0x01 )
F_5 ( L_1 ) ;
V_12 -> V_16 [ V_17 ] = V_10 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_19 ,
T_1 V_20 )
{
T_1 V_14 [ 2 ] , V_21 ;
int V_22 ;
V_14 [ 0 ] = 0xff & ~ V_19 ;
V_14 [ 1 ] = V_20 & V_19 ;
V_22 = F_1 ( V_2 , V_23 , V_14 , 2 , & V_21 , 1 ) ;
if ( V_22 < 0 || ( V_21 & V_19 ) != ( V_20 & V_19 ) )
F_5 ( L_2 ) ;
return V_22 < 0 ? V_22 : V_21 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_24 , int V_25 )
{
F_6 ( V_2 , V_24 , V_25 ? 0 : V_24 ) ;
F_8 ( 5 ) ;
F_6 ( V_2 , V_24 , V_25 ? V_24 : 0 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_10 )
{
F_6 ( V_2 , 0x40 , V_10 ? 0 : 0x40 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_26 , int V_10 )
{
T_1 V_14 [ 2 ] = { V_26 , V_10 } ;
T_1 V_15 ;
int V_22 ;
V_22 = F_1 ( V_2 , V_18 , V_14 , 2 , & V_15 , 1 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_15 == 0x01 )
return 0 ;
else {
F_5 ( L_1 ) ;
return - V_27 ;
}
}
static int F_11 ( struct V_28 * V_29 , struct V_30 V_31 [] ,
int V_32 )
{
struct V_1 * V_2 = F_12 ( V_29 ) ;
int V_15 ;
if ( F_13 ( & V_2 -> V_33 ) < 0 )
return - V_34 ;
for ( V_15 = 0 ; V_15 < V_32 ; V_15 ++ ) {
if ( V_2 -> V_35 -> V_36 . V_37 == V_38 )
switch ( V_31 [ V_15 ] . V_26 ) {
case 0x63 :
F_4 ( V_2 , 0 ) ;
break;
default:
F_4 ( V_2 , 1 ) ;
break;
}
if ( V_31 [ V_15 ] . V_39 & V_40 ) {
T_1 V_41 [ 3 ] , V_42 [ 1 + V_31 [ V_15 ] . V_43 ] ;
V_41 [ 0 ] = 0 ;
V_41 [ 1 ] = V_31 [ V_15 ] . V_43 ;
V_41 [ 2 ] = V_31 [ V_15 ] . V_26 ;
if ( F_1 ( V_2 , V_44 ,
V_41 , 3 ,
V_42 , 1 + V_31 [ V_15 ] . V_43 ) < 0 ) {
F_14 ( L_3 ) ;
break;
}
memcpy ( V_31 [ V_15 ] . V_45 , & V_42 [ 1 ] , V_31 [ V_15 ] . V_43 ) ;
} else if ( V_15 + 1 < V_32 && ( V_31 [ V_15 + 1 ] . V_39 & V_40 ) &&
V_31 [ V_15 ] . V_26 == V_31 [ V_15 + 1 ] . V_26 ) {
T_1 V_41 [ 3 + V_31 [ V_15 ] . V_43 ] , V_42 [ 1 + V_31 [ V_15 + 1 ] . V_43 ] ;
V_41 [ 0 ] = V_31 [ V_15 ] . V_43 ;
V_41 [ 1 ] = V_31 [ V_15 + 1 ] . V_43 ;
V_41 [ 2 ] = V_31 [ V_15 ] . V_26 ;
memcpy ( & V_41 [ 3 ] , V_31 [ V_15 ] . V_45 , V_31 [ V_15 ] . V_43 ) ;
if ( F_1 ( V_2 , V_44 ,
V_41 , 3 + V_31 [ V_15 ] . V_43 ,
V_42 , 1 + V_31 [ V_15 + 1 ] . V_43 ) < 0 )
break;
if ( V_42 [ 0 ] != 0x08 )
F_15 ( L_4 ) ;
memcpy ( V_31 [ V_15 + 1 ] . V_45 , & V_42 [ 1 ] , V_31 [ V_15 + 1 ] . V_43 ) ;
V_15 ++ ;
} else {
T_1 V_41 [ 2 + V_31 [ V_15 ] . V_43 ] , V_42 ;
V_41 [ 0 ] = V_31 [ V_15 ] . V_26 ;
V_41 [ 1 ] = V_31 [ V_15 ] . V_43 ;
memcpy ( & V_41 [ 2 ] , V_31 [ V_15 ] . V_45 , V_31 [ V_15 ] . V_43 ) ;
if ( F_1 ( V_2 , V_46 , V_41 ,
2 + V_31 [ V_15 ] . V_43 , & V_42 , 1 ) < 0 )
break;
if ( V_42 != 0x08 )
F_15 ( L_5 ) ;
}
}
F_16 ( & V_2 -> V_33 ) ;
return V_15 == V_32 ? V_32 : - V_47 ;
}
static T_2 F_17 ( struct V_28 * V_48 )
{
return V_49 ;
}
static int F_18 ( struct V_1 * V_2 , int V_10 )
{
T_1 V_50 = 0 ;
if ( V_10 )
return F_1 ( V_2 , V_51 , & V_50 , 1 , NULL , 0 ) ;
else
return F_1 ( V_2 , V_52 , & V_50 , 1 , NULL , 0 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_10 )
{
int V_53 ;
if ( ! V_10 )
return F_1 ( V_2 , V_52 , NULL , 0 , NULL , 0 ) ;
if ( V_2 -> V_54 == V_55 &&
F_20 ( V_2 -> V_35 , 0 , 0 ) < 0 )
F_21 ( L_6 ) ;
do {} while ( ! ( V_53 = F_1 ( V_2 , V_51 , NULL , 0 , NULL , 0 ) ) &&
! ( V_53 = F_1 ( V_2 , 0x15 , NULL , 0 , NULL , 0 ) ) &&
! ( V_53 = F_1 ( V_2 , 0x17 , NULL , 0 , NULL , 0 ) ) && 0 );
if ( ! V_53 ) {
int V_15 ;
T_1 V_45 , V_56 [] = {
0x0e , 0x2 , 0x00 , 0x7f ,
0x0e , 0x2 , 0x02 , 0xfe ,
0x0e , 0x2 , 0x02 , 0x01 ,
0x0e , 0x2 , 0x00 , 0x03 ,
0x0e , 0x2 , 0x0d , 0x40 ,
0x0e , 0x2 , 0x0e , 0x87 ,
0x0e , 0x2 , 0x0f , 0x8e ,
0x0e , 0x2 , 0x10 , 0x01 ,
0x0e , 0x2 , 0x14 , 0xd7 ,
0x0e , 0x2 , 0x47 , 0x88 ,
} ;
F_8 ( 20 ) ;
for ( V_15 = 0 ; V_15 < sizeof( V_56 ) / sizeof( T_1 ) ; V_15 += 4 / sizeof( T_1 ) ) {
V_53 = F_1 ( V_2 , V_46 ,
V_56 + V_15 , 4 , & V_45 , 1 ) ;
if ( V_53 )
break;
if ( V_45 != 0x8 )
return - V_47 ;
}
}
return V_53 ;
}
static int F_22 ( struct V_1 * V_2 , int V_10 )
{
T_1 V_50 = 0 ;
if ( V_10 )
return F_1 ( V_2 , V_51 , & V_50 , 1 , NULL , 0 ) ;
else
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , int V_10 )
{
int V_22 = 0 ;
V_22 = F_18 ( V_2 , V_10 ) ;
if ( ! V_10 )
F_9 ( V_2 , 0 ) ;
return V_22 ;
}
static int F_24 ( struct V_1 * V_2 , int V_10 )
{
int V_53 ;
T_1 V_50 ;
V_53 = F_18 ( V_2 , V_10 ) ;
if ( ! V_10 )
return V_53 ;
F_8 ( 128 ) ;
F_1 ( V_2 , V_57 , NULL , 0 , & V_50 , 1 ) ;
F_8 ( 100 ) ;
return V_53 ;
}
static int F_25 ( struct V_58 * V_29 , int V_10 )
{
T_1 V_45 [ 2 ] = { 0x03 , 0x00 } ;
if ( V_10 )
F_1 ( V_29 -> V_59 , V_60 , V_45 , 2 , NULL , 0 ) ;
else
F_1 ( V_29 -> V_59 , V_61 , NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_58 * V_29 , int V_10 )
{
if ( V_10 )
F_1 ( V_29 -> V_59 , V_62 , NULL , 0 , NULL , 0 ) ;
else
F_1 ( V_29 -> V_59 , V_63 ,
NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_64 = V_2 -> V_65 . V_66 ;
const int V_67 = 100 ;
const int V_68 = 32 ;
T_1 * V_69 ;
int V_70 ;
V_69 = F_28 ( V_68 , V_71 ) ;
if ( ! V_69 )
return;
while ( 1 ) {
if ( F_29 ( V_2 -> V_35 ,
F_30 ( V_2 -> V_35 , V_64 ) ,
V_69 , V_68 , & V_70 , V_67 ) < 0 )
break;
if ( ! V_70 )
break;
}
F_31 ( V_69 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = & V_2 -> V_65 . V_48 [ 0 ] . V_74 ;
const int V_67 = 100 ;
const int V_68 = V_73 -> V_75 . V_76 . V_77 ;
T_1 * V_69 ;
int V_70 ;
V_69 = F_28 ( V_68 , V_71 ) ;
if ( ! V_69 )
return;
while ( 1 ) {
if ( F_29 ( V_2 -> V_35 ,
F_30 ( V_2 -> V_35 , V_73 -> V_78 ) ,
V_69 , V_68 , & V_70 , V_67 ) < 0 )
break;
if ( ! V_70 )
break;
}
F_31 ( V_69 ) ;
}
static int F_33 (
struct V_58 * V_29 , int V_10 )
{
if ( V_10 ) {
T_1 V_45 [ 2 ] = { 0x03 , 0x00 } ;
F_32 ( V_29 -> V_59 ) ;
return F_1 ( V_29 -> V_59 , V_60 ,
V_45 , sizeof( V_45 ) , NULL , 0 ) ;
} else {
int V_53 = F_1 ( V_29 -> V_59 ,
V_61 , NULL , 0 , NULL , 0 ) ;
return V_53 ;
}
}
static int F_34 ( struct V_1 * V_2 , T_2 * V_79 , int * V_54 )
{
struct V_80 * V_81 = V_2 -> V_65 . V_22 . V_82 . V_80 ;
T_1 V_83 [ 4 ] ;
int V_15 ;
F_1 ( V_2 , V_84 , NULL , 0 , V_83 , 4 ) ;
* V_79 = 0 ;
* V_54 = V_85 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_65 . V_22 . V_82 . V_86 ; V_15 ++ ) {
if ( F_35 ( & V_81 [ V_15 ] ) == V_83 [ 2 ] &&
F_36 ( & V_81 [ V_15 ] ) == V_83 [ 3 ] ) {
* V_79 = V_81 [ V_15 ] . V_87 ;
* V_54 = V_88 ;
return 0 ;
}
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_2 * V_79 ,
int * V_54 )
{
struct V_80 * V_81 = V_2 -> V_65 . V_22 . V_82 . V_80 ;
T_1 V_83 [ 4 ] ;
int V_15 ;
struct V_30 V_31 = { . V_26 = 0x6b , . V_39 = V_40 ,
. V_45 = V_83 , . V_43 = 4 } ;
* V_79 = 0 ;
* V_54 = V_85 ;
if ( F_11 ( & V_2 -> V_89 , & V_31 , 1 ) != 1 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_65 . V_22 . V_82 . V_86 ; V_15 ++ ) {
if ( F_35 ( & V_81 [ V_15 ] ) == V_83 [ 1 ] &&
F_36 ( & V_81 [ V_15 ] ) == V_83 [ 2 ] ) {
* V_79 = V_81 [ V_15 ] . V_87 ;
* V_54 = V_88 ;
return 0 ;
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , T_2 * V_79 ,
int * V_54 )
{
struct V_80 * V_81 = V_2 -> V_65 . V_22 . V_82 . V_80 ;
T_1 V_83 [ 2 ] ;
int V_15 ;
* V_79 = 0 ;
* V_54 = V_85 ;
if ( F_1 ( V_2 , 0x10 , NULL , 0 , V_83 , 2 ) < 0 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_65 . V_22 . V_82 . V_86 ; V_15 ++ ) {
if ( F_35 ( & V_81 [ V_15 ] ) == V_83 [ 0 ] &&
F_36 ( & V_81 [ V_15 ] ) == V_83 [ 1 ] ) {
* V_79 = V_81 [ V_15 ] . V_87 ;
* V_54 = V_88 ;
return 0 ;
}
}
return 0 ;
}
static int F_39 ( struct V_90 * V_91 )
{
static T_1 V_92 [] = { V_93 , 0x38 , 0x28 } ;
static T_1 V_94 [] = { V_95 , 0x80 } ;
static T_1 V_96 [] = { V_97 , 0x40 } ;
static T_1 V_98 [] = { V_99 , 0x28 , 0x20 } ;
static T_1 V_100 [] = { V_101 , 0x33 } ;
static T_1 V_102 [] = { V_103 , 0x32 } ;
F_40 ( V_91 , V_92 , sizeof( V_92 ) ) ;
F_41 ( 200 ) ;
F_40 ( V_91 , V_94 , sizeof( V_94 ) ) ;
F_40 ( V_91 , V_96 , sizeof( V_96 ) ) ;
F_40 ( V_91 , V_98 , sizeof( V_98 ) ) ;
F_40 ( V_91 , V_100 , sizeof( V_100 ) ) ;
F_40 ( V_91 , V_102 , sizeof( V_102 ) ) ;
return 0 ;
}
static int F_42 ( struct V_90 * V_91 )
{
static T_1 V_92 [] = { V_93 , 0x38 , 0x29 } ;
static T_1 V_94 [] = { V_95 , 0x80 } ;
static T_1 V_96 [] = { V_97 , 0x40 } ;
static T_1 V_98 [] = { V_99 , 0x24 , 0x20 } ;
static T_1 V_100 [] = { V_101 , 0x33 } ;
static T_1 V_102 [] = { V_103 , 0x32 } ;
F_40 ( V_91 , V_92 , sizeof( V_92 ) ) ;
F_41 ( 200 ) ;
F_40 ( V_91 , V_94 , sizeof( V_94 ) ) ;
F_40 ( V_91 , V_96 , sizeof( V_96 ) ) ;
F_40 ( V_91 , V_98 , sizeof( V_98 ) ) ;
F_40 ( V_91 , V_100 , sizeof( V_100 ) ) ;
F_40 ( V_91 , V_102 , sizeof( V_102 ) ) ;
return 0 ;
}
static int F_43 ( struct V_58 * V_29 )
{
F_44 ( V_104 , V_29 -> V_91 ,
& V_29 -> V_59 -> V_89 , 0x61 ,
V_105 ) ;
return 0 ;
}
static int F_45 ( struct V_58 * V_29 )
{
F_44 ( V_106 , V_29 -> V_91 , 0x61 ,
NULL , V_107 ) ;
return 0 ;
}
static int F_46 ( struct V_58 * V_29 )
{
F_44 ( V_106 , V_29 -> V_91 , 0x61 , NULL , V_108 ) ;
return 0 ;
}
static int F_47 ( struct V_58 * V_29 )
{
F_44 ( V_106 , V_29 -> V_91 , 0x60 ,
NULL , V_107 ) ;
return 0 ;
}
static int F_48 ( struct V_58 * V_29 )
{
F_44 ( V_104 , V_29 -> V_91 ,
& V_29 -> V_59 -> V_89 , 0x61 , V_109 ) ;
return 0 ;
}
static int F_49 ( void * V_110 , int V_111 ,
int V_112 , int V_113 )
{
struct V_58 * V_29 = V_110 ;
struct V_1 * V_2 = V_29 -> V_59 ;
switch ( V_112 ) {
case V_114 :
F_5 ( L_7 , V_115 , V_113 ) ;
F_7 ( V_2 , 0x01 , 1 ) ;
break;
case V_116 :
F_5 ( L_8 , V_115 , V_113 ) ;
break;
default:
F_5 ( L_9 , V_115 ,
V_112 , V_113 ) ;
return - V_117 ;
}
return 0 ;
}
static int F_50 ( struct V_58 * V_29 )
{
struct V_90 * V_91 ;
struct V_118 V_119 = {
. V_89 = & V_29 -> V_59 -> V_89 ,
. V_120 = 0x61 ,
} ;
static struct V_121 V_122 = {
. V_123 = V_124 ,
. V_125 = 64 ,
. V_126 = V_127 ,
} ;
V_29 -> V_91 -> V_128 = F_49 ;
V_91 = F_44 ( V_129 , V_29 -> V_91 , & V_119 ) ;
if ( V_91 == NULL || V_91 -> V_130 . V_131 . V_132 == NULL )
return - V_27 ;
V_91 -> V_130 . V_131 . V_132 ( V_91 , & V_122 ) ;
return 0 ;
}
static int F_51 ( struct V_58 * V_29 )
{
F_44 ( V_133 , V_29 -> V_91 ,
& V_29 -> V_59 -> V_89 , & V_134 ) ;
return 0 ;
}
static int F_52 ( struct V_58 * V_29 )
{
struct V_90 * V_91 ;
V_91 = F_44 ( V_133 , V_29 -> V_91 ,
& V_29 -> V_59 -> V_89 , & V_135 ) ;
return ( V_91 == NULL ) ? - V_27 : 0 ;
}
static int F_53 ( struct V_58 * V_29 )
{
struct V_90 * V_91 ;
V_91 = F_44 ( V_136 , V_29 -> V_91 ,
& V_29 -> V_59 -> V_89 , & V_137 ) ;
return ( V_91 == NULL ) ? - V_27 : 0 ;
}
static int F_54 ( struct V_58 * V_29 )
{
T_1 V_50 ;
if ( F_20 ( V_29 -> V_59 -> V_35 , 0 , 6 ) < 0 )
F_21 ( L_6 ) ;
F_1 ( V_29 -> V_59 , V_57 , NULL , 0 , & V_50 , 1 ) ;
if ( ( V_29 -> V_91 = F_44 ( V_138 , & V_139 ,
& V_29 -> V_59 -> V_89 ) ) != NULL )
return 0 ;
return - V_27 ;
}
static int F_55 ( struct V_58 * V_29 )
{
if ( F_20 ( V_29 -> V_59 -> V_35 , 0 , 7 ) < 0 )
F_21 ( L_6 ) ;
F_1 ( V_29 -> V_59 , V_57 , NULL , 0 , NULL , 0 ) ;
if ( ( V_29 -> V_91 = F_44 ( V_140 , & V_141 ,
& V_29 -> V_59 -> V_89 ) ) != NULL )
return 0 ;
return - V_27 ;
}
static int F_56 ( struct V_58 * V_29 )
{
V_29 -> V_91 = F_44 ( V_140 , & V_142 ,
& V_29 -> V_59 -> V_89 ) ;
if ( V_29 -> V_91 != NULL )
return 0 ;
return - V_27 ;
}
static int F_57 ( struct V_58 * V_29 )
{
if ( F_20 ( V_29 -> V_59 -> V_35 , 0 , 0 ) < 0 )
F_21 ( L_6 ) ;
F_1 ( V_29 -> V_59 , V_57 , NULL , 0 , NULL , 0 ) ;
if ( ( V_29 -> V_91 = F_44 ( V_143 , & V_144 ,
& V_29 -> V_59 -> V_89 ) ) != NULL )
return 0 ;
return - V_27 ;
}
static int F_58 ( struct V_58 * V_29 )
{
if ( F_20 ( V_29 -> V_59 -> V_35 , 0 , 0 ) < 0 )
F_21 ( L_6 ) ;
F_1 ( V_29 -> V_59 , V_57 , NULL , 0 , NULL , 0 ) ;
if ( ( ( V_29 -> V_91 = F_44 ( V_143 , & V_145 ,
& V_29 -> V_59 -> V_89 ) ) != NULL ) ||
( ( V_29 -> V_91 = F_44 ( V_146 ,
& V_147 ,
& V_29 -> V_59 -> V_89 ) ) != NULL ) )
return 0 ;
return - V_27 ;
}
static int F_59 ( struct V_58 * V_29 )
{
T_1 V_83 [ 4 ] ;
int V_15 ;
struct V_30 V_31 = { . V_26 = 0x6b , . V_39 = V_40 ,
. V_45 = V_83 , . V_43 = 4 } ;
if ( F_20 ( V_29 -> V_59 -> V_35 , 0 , 1 ) < 0 )
F_21 ( L_6 ) ;
F_1 ( V_29 -> V_59 , V_57 , NULL , 0 , NULL , 0 ) ;
F_6 ( V_29 -> V_59 , 0x04 , 0 ) ;
F_7 ( V_29 -> V_59 , 0x01 , 1 ) ;
F_7 ( V_29 -> V_59 , 0x02 , 1 ) ;
if ( ( V_29 -> V_91 = F_44 ( V_146 ,
& V_148 ,
& V_29 -> V_59 -> V_89 ) ) == NULL )
return - V_27 ;
for ( V_15 = 0 ; V_29 -> V_59 -> V_65 . V_22 . V_82 . V_80 != NULL && V_15 < 5 ; V_15 ++ ) {
F_8 ( 20 ) ;
if ( F_11 ( & V_29 -> V_59 -> V_89 , & V_31 , 1 ) != 1 )
goto V_149;
if ( V_83 [ 0 ] == 0 && V_83 [ 1 ] == 0 )
continue;
if ( V_83 [ 2 ] + V_83 [ 3 ] != 0xff ) {
V_149:
V_29 -> V_59 -> V_65 . V_22 . V_82 . V_80 = NULL ;
F_60 ( L_10 ) ;
break;
}
}
return 0 ;
}
static int F_61 ( struct V_58 * V_29 )
{
if ( F_20 ( V_29 -> V_59 -> V_35 , 0 , 1 ) < 0 )
F_21 ( L_6 ) ;
F_1 ( V_29 -> V_59 , V_57 , NULL , 0 , NULL , 0 ) ;
F_7 ( V_29 -> V_59 , 0x02 , 1 ) ;
if ( F_62 ( & V_29 -> V_59 -> V_89 , 1 , 18 ,
& V_150 ) < 0 ) {
F_63 ( V_151 L_11 ) ;
return - V_152 ;
}
V_29 -> V_91 = F_44 ( V_153 , & V_29 -> V_59 -> V_89 , 0x80 ,
& V_150 ) ;
if ( V_29 -> V_91 == NULL )
return - V_27 ;
return 0 ;
}
static int F_64 ( struct V_90 * V_91 , int V_10 )
{
return F_65 ( V_91 , 8 , 0 , ! V_10 ) ;
}
static int F_66 ( struct V_90 * V_91 , int V_10 )
{
return 0 ;
}
static int F_67 ( struct V_90 * V_91 ,
struct V_154 * V_155 )
{
struct V_58 * V_29 = V_91 -> V_156 -> V_13 ;
struct V_157 * V_54 = V_29 -> V_13 ;
T_3 V_158 ;
T_1 V_159 = F_68 ( V_155 -> V_160 / 1000 ) ;
switch ( V_159 ) {
case V_161 : V_158 = 950 ; break;
default:
case V_162 : V_158 = 550 ; break;
}
F_69 ( V_91 , V_158 + F_70 ( V_91 ) ) ;
return V_54 -> V_163 ( V_91 , V_155 ) ;
}
static int F_71 ( struct V_58 * V_29 )
{
struct V_157 * V_12 = V_29 -> V_13 ;
struct V_28 * V_164 =
F_72 ( V_29 -> V_91 ,
V_165 , 1 ) ;
if ( F_44 ( V_166 , V_29 -> V_91 , V_164 ,
& V_167 ) == NULL )
return - V_152 ;
V_12 -> V_163 = V_29 -> V_91 -> V_130 . V_131 . V_168 ;
V_29 -> V_91 -> V_130 . V_131 . V_168 = F_67 ;
return 0 ;
}
static int F_73 ( struct V_58 * V_29 )
{
if ( F_20 ( V_29 -> V_59 -> V_35 , 0 , 1 ) < 0 )
F_21 ( L_6 ) ;
F_1 ( V_29 -> V_59 , V_57 , NULL , 0 , NULL , 0 ) ;
F_6 ( V_29 -> V_59 , 0x04 , 0 ) ;
F_7 ( V_29 -> V_59 , 0x01 , 1 ) ;
F_7 ( V_29 -> V_59 , 0x02 , 1 ) ;
if ( ( V_29 -> V_91 = F_44 ( V_146 ,
& V_169 ,
& V_29 -> V_59 -> V_89 ) ) != NULL )
return 0 ;
if ( ( V_29 -> V_91 = F_44 ( V_143 ,
& V_170 ,
& V_29 -> V_59 -> V_89 ) ) != NULL )
return 0 ;
return - V_27 ;
}
static int F_74 ( struct V_58 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_59 ;
int V_171 ;
if ( F_20 ( V_2 -> V_35 , 0 , 0 ) < 0 )
F_21 ( L_6 ) ;
F_75 ( V_2 -> V_35 ,
F_76 ( V_2 -> V_35 , V_2 -> V_65 . V_66 ) ) ;
F_75 ( V_2 -> V_35 ,
F_30 ( V_2 -> V_35 , V_2 -> V_65 . V_66 ) ) ;
F_75 ( V_2 -> V_35 ,
F_30 ( V_2 -> V_35 , V_2 -> V_65 . V_48 [ 0 ] . V_74 . V_78 ) ) ;
for ( V_171 = 0 ; V_171 < 5 ; V_171 ++ ) {
F_27 ( V_2 ) ;
F_32 ( V_2 ) ;
F_8 ( 200 ) ;
}
if ( F_10 ( V_2 , 0x07 , 0 ) < 0 ) {
F_21 ( L_12 ) ;
return - V_27 ;
}
F_8 ( 100 ) ;
if ( F_10 ( V_2 , 0x07 , 1 ) < 0 ) {
F_21 ( L_13 ) ;
return - V_27 ;
}
F_8 ( 100 ) ;
V_29 -> V_91 = F_44 ( V_172 , & V_173 , & V_2 -> V_89 ) ;
if ( V_29 -> V_91 == NULL )
return - V_27 ;
return 0 ;
}
static int F_77 ( struct V_58 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_59 ;
if ( F_20 ( V_2 -> V_35 , 0 , 0 ) < 0 )
F_21 ( L_6 ) ;
F_75 ( V_2 -> V_35 ,
F_76 ( V_2 -> V_35 , V_2 -> V_65 . V_66 ) ) ;
F_75 ( V_2 -> V_35 ,
F_30 ( V_2 -> V_35 , V_2 -> V_65 . V_66 ) ) ;
F_75 ( V_2 -> V_35 ,
F_30 ( V_2 -> V_35 , V_2 -> V_65 . V_48 [ 0 ] . V_74 . V_78 ) ) ;
if ( F_10 ( V_2 , 0x07 , 0 ) < 0 ) {
F_21 ( L_12 ) ;
return - V_27 ;
}
F_8 ( 100 ) ;
if ( F_10 ( V_2 , 0x07 , 1 ) < 0 ) {
F_21 ( L_13 ) ;
return - V_27 ;
}
F_8 ( 100 ) ;
V_29 -> V_91 = F_44 ( V_174 , & V_175 ,
& V_2 -> V_89 ) ;
if ( V_29 -> V_91 == NULL )
return - V_27 ;
return 0 ;
}
static int F_78 ( struct V_176 * V_35 ,
struct V_177 * V_65 ,
struct V_178 * * V_179 ,
int * V_180 )
{
int V_181 = * V_180 ;
* V_180 = V_35 -> V_36 . V_182 == 0xff &&
V_35 -> V_36 . V_183 == 0xff &&
V_35 -> V_36 . V_184 == 0xff ;
if ( * V_180 && ! V_181 )
* V_179 = NULL ;
return 0 ;
}
static int F_79 ( struct V_176 * V_35 ,
const struct V_185 * V_186 )
{
int V_187 ;
for ( V_187 = 0 ; V_187 < F_80 ( V_188 ) ; V_187 ++ ) {
int V_189 = V_188 [ V_187 ] ;
if ( V_186 -> V_190 < V_189 + 4 )
continue;
if ( V_186 -> V_191 [ V_189 ] == ( V_192 & 0xff ) &&
V_186 -> V_191 [ V_189 + 1 ] == V_192 >> 8 ) {
struct V_185 V_193 ;
T_1 * V_194 = F_81 ( V_186 -> V_190 ) ;
int V_53 ;
if ( ! V_194 )
return - V_195 ;
memcpy ( V_194 , V_186 -> V_191 , V_186 -> V_190 ) ;
V_193 . V_190 = V_186 -> V_190 ;
V_193 . V_191 = V_194 ;
V_194 [ V_189 + 2 ] =
F_82 ( V_35 -> V_36 . V_196 ) + 1 ;
V_194 [ V_189 + 3 ] =
F_82 ( V_35 -> V_36 . V_196 ) >> 8 ;
V_53 = F_83 ( V_35 , & V_193 ,
V_197 ) ;
F_84 ( V_194 ) ;
return V_53 ;
}
}
return - V_117 ;
}
static int F_85 ( struct V_198 * V_199 ,
const struct V_200 * V_201 )
{
if ( 0 == F_86 ( V_199 , & V_202 ,
V_203 , NULL , V_204 ) ||
0 == F_86 ( V_199 , & V_205 ,
V_203 , NULL , V_204 ) ||
0 == F_86 ( V_199 , & V_206 ,
V_203 , NULL , V_204 ) ||
0 == F_86 ( V_199 , & V_207 ,
V_203 , NULL , V_204 ) ||
0 == F_86 ( V_199 , & V_208 ,
V_203 , NULL , V_204 ) ||
0 == F_86 ( V_199 , & V_209 ,
V_203 , NULL , V_204 ) ||
0 == F_86 ( V_199 , & V_210 ,
V_203 , NULL , V_204 ) ||
0 == F_86 ( V_199 ,
& V_211 ,
V_203 , NULL , V_204 ) ||
0 == F_86 ( V_199 , & V_212 ,
V_203 , NULL , V_204 ) ||
0 == F_86 ( V_199 ,
& V_213 ,
V_203 , NULL , V_204 ) ||
0 == F_86 ( V_199 , & V_214 ,
V_203 , NULL , V_204 ) ||
0 == F_86 ( V_199 , & V_215 ,
V_203 , NULL , V_204 ) ||
0 )
return 0 ;
return - V_117 ;
}
static int T_4 F_87 ( void )
{
int V_216 ;
if ( ( V_216 = F_88 ( & V_217 ) ) ) {
F_21 ( L_14 , V_216 ) ;
return V_216 ;
}
return 0 ;
}
static void T_5 F_89 ( void )
{
F_90 ( & V_217 ) ;
}
