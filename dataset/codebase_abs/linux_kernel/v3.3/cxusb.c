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
struct V_72 * V_73 = & V_2 -> V_65 . V_48 [ 0 ] . V_74 [ 0 ] . V_75 ;
const int V_67 = 100 ;
const int V_68 = V_73 -> V_76 . V_77 . V_78 ;
T_1 * V_69 ;
int V_70 ;
V_69 = F_28 ( V_68 , V_71 ) ;
if ( ! V_69 )
return;
while ( 1 ) {
if ( F_29 ( V_2 -> V_35 ,
F_30 ( V_2 -> V_35 , V_73 -> V_79 ) ,
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
static int F_34 ( struct V_1 * V_2 , T_2 * V_80 , int * V_54 )
{
struct V_81 * V_82 = V_2 -> V_65 . V_22 . V_83 . V_81 ;
T_1 V_84 [ 4 ] ;
int V_15 ;
F_1 ( V_2 , V_85 , NULL , 0 , V_84 , 4 ) ;
* V_80 = 0 ;
* V_54 = V_86 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_65 . V_22 . V_83 . V_87 ; V_15 ++ ) {
if ( F_35 ( & V_82 [ V_15 ] ) == V_84 [ 2 ] &&
F_36 ( & V_82 [ V_15 ] ) == V_84 [ 3 ] ) {
* V_80 = V_82 [ V_15 ] . V_88 ;
* V_54 = V_89 ;
return 0 ;
}
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_2 * V_80 ,
int * V_54 )
{
struct V_81 * V_82 = V_2 -> V_65 . V_22 . V_83 . V_81 ;
T_1 V_84 [ 4 ] ;
int V_15 ;
struct V_30 V_31 = { . V_26 = 0x6b , . V_39 = V_40 ,
. V_45 = V_84 , . V_43 = 4 } ;
* V_80 = 0 ;
* V_54 = V_86 ;
if ( F_11 ( & V_2 -> V_90 , & V_31 , 1 ) != 1 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_65 . V_22 . V_83 . V_87 ; V_15 ++ ) {
if ( F_35 ( & V_82 [ V_15 ] ) == V_84 [ 1 ] &&
F_36 ( & V_82 [ V_15 ] ) == V_84 [ 2 ] ) {
* V_80 = V_82 [ V_15 ] . V_88 ;
* V_54 = V_89 ;
return 0 ;
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , T_2 * V_80 ,
int * V_54 )
{
struct V_81 * V_82 = V_2 -> V_65 . V_22 . V_83 . V_81 ;
T_1 V_84 [ 2 ] ;
int V_15 ;
* V_80 = 0 ;
* V_54 = V_86 ;
if ( F_1 ( V_2 , 0x10 , NULL , 0 , V_84 , 2 ) < 0 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_65 . V_22 . V_83 . V_87 ; V_15 ++ ) {
if ( F_35 ( & V_82 [ V_15 ] ) == V_84 [ 0 ] &&
F_36 ( & V_82 [ V_15 ] ) == V_84 [ 1 ] ) {
* V_80 = V_82 [ V_15 ] . V_88 ;
* V_54 = V_89 ;
return 0 ;
}
}
return 0 ;
}
static int F_39 ( struct V_91 * V_74 )
{
static T_1 V_92 [] = { V_93 , 0x38 , 0x28 } ;
static T_1 V_94 [] = { V_95 , 0x80 } ;
static T_1 V_96 [] = { V_97 , 0x40 } ;
static T_1 V_98 [] = { V_99 , 0x28 , 0x20 } ;
static T_1 V_100 [] = { V_101 , 0x33 } ;
static T_1 V_102 [] = { V_103 , 0x32 } ;
F_40 ( V_74 , V_92 , sizeof( V_92 ) ) ;
F_41 ( 200 ) ;
F_40 ( V_74 , V_94 , sizeof( V_94 ) ) ;
F_40 ( V_74 , V_96 , sizeof( V_96 ) ) ;
F_40 ( V_74 , V_98 , sizeof( V_98 ) ) ;
F_40 ( V_74 , V_100 , sizeof( V_100 ) ) ;
F_40 ( V_74 , V_102 , sizeof( V_102 ) ) ;
return 0 ;
}
static int F_42 ( struct V_91 * V_74 )
{
static T_1 V_92 [] = { V_93 , 0x38 , 0x29 } ;
static T_1 V_94 [] = { V_95 , 0x80 } ;
static T_1 V_96 [] = { V_97 , 0x40 } ;
static T_1 V_98 [] = { V_99 , 0x24 , 0x20 } ;
static T_1 V_100 [] = { V_101 , 0x33 } ;
static T_1 V_102 [] = { V_103 , 0x32 } ;
F_40 ( V_74 , V_92 , sizeof( V_92 ) ) ;
F_41 ( 200 ) ;
F_40 ( V_74 , V_94 , sizeof( V_94 ) ) ;
F_40 ( V_74 , V_96 , sizeof( V_96 ) ) ;
F_40 ( V_74 , V_98 , sizeof( V_98 ) ) ;
F_40 ( V_74 , V_100 , sizeof( V_100 ) ) ;
F_40 ( V_74 , V_102 , sizeof( V_102 ) ) ;
return 0 ;
}
static int F_43 ( struct V_58 * V_29 )
{
F_44 ( V_104 , V_29 -> V_105 [ 0 ] . V_74 ,
& V_29 -> V_59 -> V_90 , 0x61 ,
V_106 ) ;
return 0 ;
}
static int F_45 ( struct V_58 * V_29 )
{
F_44 ( V_107 , V_29 -> V_105 [ 0 ] . V_74 , 0x61 ,
NULL , V_108 ) ;
return 0 ;
}
static int F_46 ( struct V_58 * V_29 )
{
F_44 ( V_107 , V_29 -> V_105 [ 0 ] . V_74 , 0x61 , NULL , V_109 ) ;
return 0 ;
}
static int F_47 ( struct V_58 * V_29 )
{
F_44 ( V_107 , V_29 -> V_105 [ 0 ] . V_74 , 0x60 ,
NULL , V_108 ) ;
return 0 ;
}
static int F_48 ( struct V_58 * V_29 )
{
F_44 ( V_104 , V_29 -> V_105 [ 0 ] . V_74 ,
& V_29 -> V_59 -> V_90 , 0x61 , V_110 ) ;
return 0 ;
}
static int F_49 ( void * V_111 , int V_112 ,
int V_113 , int V_114 )
{
struct V_58 * V_29 = V_111 ;
struct V_1 * V_2 = V_29 -> V_59 ;
switch ( V_113 ) {
case V_115 :
F_5 ( L_7 , V_116 , V_114 ) ;
F_7 ( V_2 , 0x01 , 1 ) ;
break;
case V_117 :
F_5 ( L_8 , V_116 , V_114 ) ;
break;
default:
F_5 ( L_9 , V_116 ,
V_113 , V_114 ) ;
return - V_118 ;
}
return 0 ;
}
static int F_50 ( struct V_58 * V_29 )
{
struct V_91 * V_74 ;
struct V_119 V_120 = {
. V_90 = & V_29 -> V_59 -> V_90 ,
. V_121 = 0x61 ,
} ;
static struct V_122 V_123 = {
. V_124 = V_125 ,
. V_126 = 64 ,
. V_127 = V_128 ,
} ;
V_29 -> V_105 [ 0 ] . V_74 -> V_129 = F_49 ;
V_74 = F_44 ( V_130 , V_29 -> V_105 [ 0 ] . V_74 , & V_120 ) ;
if ( V_74 == NULL || V_74 -> V_131 . V_132 . V_133 == NULL )
return - V_27 ;
V_74 -> V_131 . V_132 . V_133 ( V_74 , & V_123 ) ;
return 0 ;
}
static int F_51 ( struct V_58 * V_29 )
{
F_44 ( V_134 , V_29 -> V_105 [ 0 ] . V_74 ,
& V_29 -> V_59 -> V_90 , & V_135 ) ;
return 0 ;
}
static int F_52 ( struct V_58 * V_29 )
{
struct V_91 * V_74 ;
V_74 = F_44 ( V_134 , V_29 -> V_105 [ 0 ] . V_74 ,
& V_29 -> V_59 -> V_90 , & V_136 ) ;
return ( V_74 == NULL ) ? - V_27 : 0 ;
}
static int F_53 ( struct V_58 * V_29 )
{
struct V_91 * V_74 ;
V_74 = F_44 ( V_137 , V_29 -> V_105 [ 0 ] . V_74 ,
& V_29 -> V_59 -> V_90 , & V_138 ) ;
return ( V_74 == NULL ) ? - V_27 : 0 ;
}
static int F_54 ( struct V_58 * V_29 )
{
T_1 V_50 ;
if ( F_20 ( V_29 -> V_59 -> V_35 , 0 , 6 ) < 0 )
F_21 ( L_6 ) ;
F_1 ( V_29 -> V_59 , V_57 , NULL , 0 , & V_50 , 1 ) ;
V_29 -> V_105 [ 0 ] . V_74 = F_44 ( V_139 , & V_140 ,
& V_29 -> V_59 -> V_90 ) ;
if ( ( V_29 -> V_105 [ 0 ] . V_74 ) != NULL )
return 0 ;
return - V_27 ;
}
static int F_55 ( struct V_58 * V_29 )
{
if ( F_20 ( V_29 -> V_59 -> V_35 , 0 , 7 ) < 0 )
F_21 ( L_6 ) ;
F_1 ( V_29 -> V_59 , V_57 , NULL , 0 , NULL , 0 ) ;
V_29 -> V_105 [ 0 ] . V_74 = F_44 ( V_141 ,
& V_142 ,
& V_29 -> V_59 -> V_90 ) ;
if ( ( V_29 -> V_105 [ 0 ] . V_74 ) != NULL )
return 0 ;
return - V_27 ;
}
static int F_56 ( struct V_58 * V_29 )
{
V_29 -> V_105 [ 0 ] . V_74 = F_44 ( V_141 , & V_143 ,
& V_29 -> V_59 -> V_90 ) ;
if ( V_29 -> V_105 [ 0 ] . V_74 != NULL )
return 0 ;
return - V_27 ;
}
static int F_57 ( struct V_58 * V_29 )
{
if ( F_20 ( V_29 -> V_59 -> V_35 , 0 , 0 ) < 0 )
F_21 ( L_6 ) ;
F_1 ( V_29 -> V_59 , V_57 , NULL , 0 , NULL , 0 ) ;
V_29 -> V_105 [ 0 ] . V_74 = F_44 ( V_144 , & V_145 ,
& V_29 -> V_59 -> V_90 ) ;
if ( ( V_29 -> V_105 [ 0 ] . V_74 ) != NULL )
return 0 ;
return - V_27 ;
}
static int F_58 ( struct V_58 * V_29 )
{
if ( F_20 ( V_29 -> V_59 -> V_35 , 0 , 0 ) < 0 )
F_21 ( L_6 ) ;
F_1 ( V_29 -> V_59 , V_57 , NULL , 0 , NULL , 0 ) ;
V_29 -> V_105 [ 0 ] . V_74 = F_44 ( V_144 , & V_146 ,
& V_29 -> V_59 -> V_90 ) ;
if ( ( V_29 -> V_105 [ 0 ] . V_74 ) != NULL )
return 0 ;
V_29 -> V_105 [ 0 ] . V_74 = F_44 ( V_147 ,
& V_148 ,
& V_29 -> V_59 -> V_90 ) ;
if ( ( V_29 -> V_105 [ 0 ] . V_74 ) != NULL )
return 0 ;
return - V_27 ;
}
static int F_59 ( struct V_58 * V_29 )
{
T_1 V_84 [ 4 ] ;
int V_15 ;
struct V_30 V_31 = { . V_26 = 0x6b , . V_39 = V_40 ,
. V_45 = V_84 , . V_43 = 4 } ;
if ( F_20 ( V_29 -> V_59 -> V_35 , 0 , 1 ) < 0 )
F_21 ( L_6 ) ;
F_1 ( V_29 -> V_59 , V_57 , NULL , 0 , NULL , 0 ) ;
F_6 ( V_29 -> V_59 , 0x04 , 0 ) ;
F_7 ( V_29 -> V_59 , 0x01 , 1 ) ;
F_7 ( V_29 -> V_59 , 0x02 , 1 ) ;
V_29 -> V_105 [ 0 ] . V_74 =
F_44 ( V_147 ,
& V_149 ,
& V_29 -> V_59 -> V_90 ) ;
if ( ( V_29 -> V_105 [ 0 ] . V_74 ) == NULL )
return - V_27 ;
for ( V_15 = 0 ; V_29 -> V_59 -> V_65 . V_22 . V_83 . V_81 != NULL && V_15 < 5 ; V_15 ++ ) {
F_8 ( 20 ) ;
if ( F_11 ( & V_29 -> V_59 -> V_90 , & V_31 , 1 ) != 1 )
goto V_150;
if ( V_84 [ 0 ] == 0 && V_84 [ 1 ] == 0 )
continue;
if ( V_84 [ 2 ] + V_84 [ 3 ] != 0xff ) {
V_150:
V_29 -> V_59 -> V_65 . V_22 . V_83 . V_81 = NULL ;
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
if ( F_62 ( & V_29 -> V_59 -> V_90 , 1 , 18 ,
& V_151 ) < 0 ) {
F_63 ( V_152 L_11 ) ;
return - V_153 ;
}
V_29 -> V_105 [ 0 ] . V_74 = F_44 ( V_154 , & V_29 -> V_59 -> V_90 , 0x80 ,
& V_151 ) ;
if ( V_29 -> V_105 [ 0 ] . V_74 == NULL )
return - V_27 ;
return 0 ;
}
static int F_64 ( struct V_91 * V_74 , int V_10 )
{
return F_65 ( V_74 , 8 , 0 , ! V_10 ) ;
}
static int F_66 ( struct V_91 * V_74 , int V_10 )
{
return 0 ;
}
static int F_67 ( struct V_91 * V_74 )
{
struct V_155 * V_73 = & V_74 -> V_156 ;
struct V_58 * V_29 = V_74 -> V_157 -> V_13 ;
struct V_158 * V_54 = V_29 -> V_13 ;
T_3 V_159 ;
T_1 V_160 = F_68 ( V_73 -> V_161 / 1000 ) ;
switch ( V_160 ) {
case V_162 : V_159 = 950 ; break;
default:
case V_163 : V_159 = 550 ; break;
}
F_69 ( V_74 , V_159 + F_70 ( V_74 ) ) ;
return V_54 -> V_164 ( V_74 ) ;
}
static int F_71 ( struct V_58 * V_29 )
{
struct V_158 * V_12 = V_29 -> V_13 ;
struct V_28 * V_165 =
F_72 ( V_29 -> V_105 [ 0 ] . V_74 ,
V_166 , 1 ) ;
if ( F_44 ( V_167 , V_29 -> V_105 [ 0 ] . V_74 , V_165 ,
& V_168 ) == NULL )
return - V_153 ;
V_12 -> V_164 = V_29 -> V_105 [ 0 ] . V_74 -> V_131 . V_132 . V_169 ;
V_29 -> V_105 [ 0 ] . V_74 -> V_131 . V_132 . V_169 = F_67 ;
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
V_29 -> V_105 [ 0 ] . V_74 = F_44 ( V_147 ,
& V_170 ,
& V_29 -> V_59 -> V_90 ) ;
if ( ( V_29 -> V_105 [ 0 ] . V_74 ) != NULL )
return 0 ;
V_29 -> V_105 [ 0 ] . V_74 = F_44 ( V_144 ,
& V_171 ,
& V_29 -> V_59 -> V_90 ) ;
if ( ( V_29 -> V_105 [ 0 ] . V_74 ) != NULL )
return 0 ;
return - V_27 ;
}
static int F_74 ( struct V_58 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_59 ;
int V_172 ;
if ( F_20 ( V_2 -> V_35 , 0 , 0 ) < 0 )
F_21 ( L_6 ) ;
F_75 ( V_2 -> V_35 ,
F_76 ( V_2 -> V_35 , V_2 -> V_65 . V_66 ) ) ;
F_75 ( V_2 -> V_35 ,
F_30 ( V_2 -> V_35 , V_2 -> V_65 . V_66 ) ) ;
F_75 ( V_2 -> V_35 ,
F_30 ( V_2 -> V_35 , V_2 -> V_65 . V_48 [ 0 ] . V_74 [ 0 ] . V_75 . V_79 ) ) ;
for ( V_172 = 0 ; V_172 < 5 ; V_172 ++ ) {
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
V_29 -> V_105 [ 0 ] . V_74 = F_44 ( V_173 , & V_174 , & V_2 -> V_90 ) ;
if ( V_29 -> V_105 [ 0 ] . V_74 == NULL )
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
F_30 ( V_2 -> V_35 , V_2 -> V_65 . V_48 [ 0 ] . V_74 [ 0 ] . V_75 . V_79 ) ) ;
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
V_29 -> V_105 [ 0 ] . V_74 = F_44 ( V_175 , & V_176 ,
& V_2 -> V_90 ) ;
if ( V_29 -> V_105 [ 0 ] . V_74 == NULL )
return - V_27 ;
return 0 ;
}
static int F_78 ( struct V_177 * V_35 ,
struct V_178 * V_65 ,
struct V_179 * * V_180 ,
int * V_181 )
{
int V_182 = * V_181 ;
* V_181 = V_35 -> V_36 . V_183 == 0xff &&
V_35 -> V_36 . V_184 == 0xff &&
V_35 -> V_36 . V_185 == 0xff ;
if ( * V_181 && ! V_182 )
* V_180 = NULL ;
return 0 ;
}
static int F_79 ( struct V_177 * V_35 ,
const struct V_186 * V_187 )
{
int V_188 ;
for ( V_188 = 0 ; V_188 < F_80 ( V_189 ) ; V_188 ++ ) {
int V_190 = V_189 [ V_188 ] ;
if ( V_187 -> V_191 < V_190 + 4 )
continue;
if ( V_187 -> V_192 [ V_190 ] == ( V_193 & 0xff ) &&
V_187 -> V_192 [ V_190 + 1 ] == V_193 >> 8 ) {
struct V_186 V_194 ;
T_1 * V_195 = F_81 ( V_187 -> V_191 ) ;
int V_53 ;
if ( ! V_195 )
return - V_196 ;
memcpy ( V_195 , V_187 -> V_192 , V_187 -> V_191 ) ;
V_194 . V_191 = V_187 -> V_191 ;
V_194 . V_192 = V_195 ;
V_195 [ V_190 + 2 ] =
F_82 ( V_35 -> V_36 . V_197 ) + 1 ;
V_195 [ V_190 + 3 ] =
F_82 ( V_35 -> V_36 . V_197 ) >> 8 ;
V_53 = F_83 ( V_35 , & V_194 ,
V_198 ) ;
F_84 ( V_195 ) ;
return V_53 ;
}
}
return - V_118 ;
}
static int F_85 ( struct V_199 * V_200 ,
const struct V_201 * V_202 )
{
if ( 0 == F_86 ( V_200 , & V_203 ,
V_204 , NULL , V_205 ) ||
0 == F_86 ( V_200 , & V_206 ,
V_204 , NULL , V_205 ) ||
0 == F_86 ( V_200 , & V_207 ,
V_204 , NULL , V_205 ) ||
0 == F_86 ( V_200 , & V_208 ,
V_204 , NULL , V_205 ) ||
0 == F_86 ( V_200 , & V_209 ,
V_204 , NULL , V_205 ) ||
0 == F_86 ( V_200 , & V_210 ,
V_204 , NULL , V_205 ) ||
0 == F_86 ( V_200 , & V_211 ,
V_204 , NULL , V_205 ) ||
0 == F_86 ( V_200 ,
& V_212 ,
V_204 , NULL , V_205 ) ||
0 == F_86 ( V_200 , & V_213 ,
V_204 , NULL , V_205 ) ||
0 == F_86 ( V_200 ,
& V_214 ,
V_204 , NULL , V_205 ) ||
0 == F_86 ( V_200 , & V_215 ,
V_204 , NULL , V_205 ) ||
0 == F_86 ( V_200 , & V_216 ,
V_204 , NULL , V_205 ) ||
0 )
return 0 ;
return - V_118 ;
}
