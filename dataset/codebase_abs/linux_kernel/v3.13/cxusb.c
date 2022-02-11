static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 )
{
int V_8 = ( V_6 == NULL || V_7 == 0 ) ;
T_1 V_9 [ V_10 ] ;
if ( 1 + V_5 > sizeof( V_9 ) ) {
F_2 ( L_1 ,
V_5 ) ;
return - V_11 ;
}
memset ( V_9 , 0 , 1 + V_5 ) ;
V_9 [ 0 ] = V_3 ;
memcpy ( & V_9 [ 1 ] , V_4 , V_5 ) ;
if ( V_8 )
return F_3 ( V_2 , V_9 , 1 + V_5 ) ;
else
return F_4 ( V_2 , V_9 , 1 + V_5 , V_6 , V_7 , 0 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
T_1 V_16 [ 2 ] , V_17 ;
if ( V_14 -> V_18 [ V_19 ] == V_12 )
return;
V_16 [ 0 ] = V_19 ;
V_16 [ 1 ] = V_12 ;
F_1 ( V_2 , V_20 , V_16 , 2 , & V_17 , 1 ) ;
if ( V_17 != 0x01 )
F_6 ( L_2 ) ;
V_14 -> V_18 [ V_19 ] = V_12 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_21 ,
T_1 V_22 )
{
T_1 V_16 [ 2 ] , V_23 ;
int V_24 ;
V_16 [ 0 ] = 0xff & ~ V_21 ;
V_16 [ 1 ] = V_22 & V_21 ;
V_24 = F_1 ( V_2 , V_25 , V_16 , 2 , & V_23 , 1 ) ;
if ( V_24 < 0 || ( V_23 & V_21 ) != ( V_22 & V_21 ) )
F_6 ( L_3 ) ;
return V_24 < 0 ? V_24 : V_23 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_26 , int V_27 )
{
F_7 ( V_2 , V_26 , V_27 ? 0 : V_26 ) ;
F_9 ( 5 ) ;
F_7 ( V_2 , V_26 , V_27 ? V_26 : 0 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_12 )
{
F_7 ( V_2 , 0x40 , V_12 ? 0 : 0x40 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_28 , int V_12 )
{
T_1 V_16 [ 2 ] = { V_28 , V_12 } ;
T_1 V_17 ;
int V_24 ;
V_24 = F_1 ( V_2 , V_20 , V_16 , 2 , & V_17 , 1 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_17 == 0x01 )
return 0 ;
else {
F_6 ( L_2 ) ;
return - V_29 ;
}
}
static int F_12 ( struct V_30 * V_31 , struct V_32 V_33 [] ,
int V_34 )
{
struct V_1 * V_2 = F_13 ( V_31 ) ;
int V_17 ;
if ( F_14 ( & V_2 -> V_35 ) < 0 )
return - V_36 ;
for ( V_17 = 0 ; V_17 < V_34 ; V_17 ++ ) {
if ( V_2 -> V_37 -> V_38 . V_39 == V_40 )
switch ( V_33 [ V_17 ] . V_28 ) {
case 0x63 :
F_5 ( V_2 , 0 ) ;
break;
default:
F_5 ( V_2 , 1 ) ;
break;
}
if ( V_33 [ V_17 ] . V_41 & V_42 ) {
T_1 V_43 [ 3 ] , V_44 [ V_10 ] ;
if ( 1 + V_33 [ V_17 ] . V_45 > sizeof( V_44 ) ) {
F_2 ( L_4 ,
V_33 [ V_17 ] . V_45 ) ;
return - V_11 ;
}
V_43 [ 0 ] = 0 ;
V_43 [ 1 ] = V_33 [ V_17 ] . V_45 ;
V_43 [ 2 ] = V_33 [ V_17 ] . V_28 ;
if ( F_1 ( V_2 , V_46 ,
V_43 , 3 ,
V_44 , 1 + V_33 [ V_17 ] . V_45 ) < 0 ) {
F_2 ( L_5 ) ;
break;
}
memcpy ( V_33 [ V_17 ] . V_47 , & V_44 [ 1 ] , V_33 [ V_17 ] . V_45 ) ;
} else if ( V_17 + 1 < V_34 && ( V_33 [ V_17 + 1 ] . V_41 & V_42 ) &&
V_33 [ V_17 ] . V_28 == V_33 [ V_17 + 1 ] . V_28 ) {
T_1 V_43 [ V_10 ] , V_44 [ V_10 ] ;
if ( 3 + V_33 [ V_17 ] . V_45 > sizeof( V_43 ) ) {
F_2 ( L_1 ,
V_33 [ V_17 ] . V_45 ) ;
return - V_11 ;
}
if ( 1 + V_33 [ V_17 + 1 ] . V_45 > sizeof( V_44 ) ) {
F_2 ( L_4 ,
V_33 [ V_17 + 1 ] . V_45 ) ;
return - V_11 ;
}
V_43 [ 0 ] = V_33 [ V_17 ] . V_45 ;
V_43 [ 1 ] = V_33 [ V_17 + 1 ] . V_45 ;
V_43 [ 2 ] = V_33 [ V_17 ] . V_28 ;
memcpy ( & V_43 [ 3 ] , V_33 [ V_17 ] . V_47 , V_33 [ V_17 ] . V_45 ) ;
if ( F_1 ( V_2 , V_46 ,
V_43 , 3 + V_33 [ V_17 ] . V_45 ,
V_44 , 1 + V_33 [ V_17 + 1 ] . V_45 ) < 0 )
break;
if ( V_44 [ 0 ] != 0x08 )
F_15 ( L_6 ) ;
memcpy ( V_33 [ V_17 + 1 ] . V_47 , & V_44 [ 1 ] , V_33 [ V_17 + 1 ] . V_45 ) ;
V_17 ++ ;
} else {
T_1 V_43 [ V_10 ] , V_44 ;
if ( 2 + V_33 [ V_17 ] . V_45 > sizeof( V_43 ) ) {
F_2 ( L_1 ,
V_33 [ V_17 ] . V_45 ) ;
return - V_11 ;
}
V_43 [ 0 ] = V_33 [ V_17 ] . V_28 ;
V_43 [ 1 ] = V_33 [ V_17 ] . V_45 ;
memcpy ( & V_43 [ 2 ] , V_33 [ V_17 ] . V_47 , V_33 [ V_17 ] . V_45 ) ;
if ( F_1 ( V_2 , V_48 , V_43 ,
2 + V_33 [ V_17 ] . V_45 , & V_44 , 1 ) < 0 )
break;
if ( V_44 != 0x08 )
F_15 ( L_7 ) ;
}
}
F_16 ( & V_2 -> V_35 ) ;
return V_17 == V_34 ? V_34 : - V_49 ;
}
static T_2 F_17 ( struct V_30 * V_50 )
{
return V_51 ;
}
static int F_18 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_52 = 0 ;
if ( V_12 )
return F_1 ( V_2 , V_53 , & V_52 , 1 , NULL , 0 ) ;
else
return F_1 ( V_2 , V_54 , & V_52 , 1 , NULL , 0 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_12 )
{
int V_55 ;
if ( ! V_12 )
return F_1 ( V_2 , V_54 , NULL , 0 , NULL , 0 ) ;
if ( V_2 -> V_56 == V_57 &&
F_20 ( V_2 -> V_37 , 0 , 0 ) < 0 )
F_21 ( L_8 ) ;
do {} while ( ! ( V_55 = F_1 ( V_2 , V_53 , NULL , 0 , NULL , 0 ) ) &&
! ( V_55 = F_1 ( V_2 , 0x15 , NULL , 0 , NULL , 0 ) ) &&
! ( V_55 = F_1 ( V_2 , 0x17 , NULL , 0 , NULL , 0 ) ) && 0 );
if ( ! V_55 ) {
int V_17 ;
T_1 V_47 , V_58 [] = {
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
F_9 ( 20 ) ;
for ( V_17 = 0 ; V_17 < sizeof( V_58 ) / sizeof( T_1 ) ; V_17 += 4 / sizeof( T_1 ) ) {
V_55 = F_1 ( V_2 , V_48 ,
V_58 + V_17 , 4 , & V_47 , 1 ) ;
if ( V_55 )
break;
if ( V_47 != 0x8 )
return - V_49 ;
}
}
return V_55 ;
}
static int F_22 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_52 = 0 ;
if ( V_12 )
return F_1 ( V_2 , V_53 , & V_52 , 1 , NULL , 0 ) ;
else
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , int V_12 )
{
int V_24 = 0 ;
V_24 = F_18 ( V_2 , V_12 ) ;
if ( ! V_12 )
F_10 ( V_2 , 0 ) ;
return V_24 ;
}
static int F_24 ( struct V_1 * V_2 , int V_12 )
{
int V_55 ;
T_1 V_52 ;
V_55 = F_18 ( V_2 , V_12 ) ;
if ( ! V_12 )
return V_55 ;
F_9 ( 128 ) ;
F_1 ( V_2 , V_59 , NULL , 0 , & V_52 , 1 ) ;
F_9 ( 100 ) ;
return V_55 ;
}
static int F_25 ( struct V_60 * V_31 , int V_12 )
{
T_1 V_47 [ 2 ] = { 0x03 , 0x00 } ;
if ( V_12 )
F_1 ( V_31 -> V_61 , V_62 , V_47 , 2 , NULL , 0 ) ;
else
F_1 ( V_31 -> V_61 , V_63 , NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_60 * V_31 , int V_12 )
{
if ( V_12 )
F_1 ( V_31 -> V_61 , V_64 , NULL , 0 , NULL , 0 ) ;
else
F_1 ( V_31 -> V_61 , V_65 ,
NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_66 = V_2 -> V_67 . V_68 ;
const int V_69 = 100 ;
const int V_70 = 32 ;
T_1 * V_71 ;
int V_72 ;
V_71 = F_28 ( V_70 , V_73 ) ;
if ( ! V_71 )
return;
while ( 1 ) {
if ( F_29 ( V_2 -> V_37 ,
F_30 ( V_2 -> V_37 , V_66 ) ,
V_71 , V_70 , & V_72 , V_69 ) < 0 )
break;
if ( ! V_72 )
break;
}
F_31 ( V_71 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_74 * V_75 = & V_2 -> V_67 . V_50 [ 0 ] . V_76 [ 0 ] . V_77 ;
const int V_69 = 100 ;
const int V_70 = V_75 -> V_78 . V_79 . V_80 ;
T_1 * V_71 ;
int V_72 ;
V_71 = F_28 ( V_70 , V_73 ) ;
if ( ! V_71 )
return;
while ( 1 ) {
if ( F_29 ( V_2 -> V_37 ,
F_30 ( V_2 -> V_37 , V_75 -> V_81 ) ,
V_71 , V_70 , & V_72 , V_69 ) < 0 )
break;
if ( ! V_72 )
break;
}
F_31 ( V_71 ) ;
}
static int F_33 (
struct V_60 * V_31 , int V_12 )
{
if ( V_12 ) {
T_1 V_47 [ 2 ] = { 0x03 , 0x00 } ;
F_32 ( V_31 -> V_61 ) ;
return F_1 ( V_31 -> V_61 , V_62 ,
V_47 , sizeof( V_47 ) , NULL , 0 ) ;
} else {
int V_55 = F_1 ( V_31 -> V_61 ,
V_63 , NULL , 0 , NULL , 0 ) ;
return V_55 ;
}
}
static int F_34 ( struct V_1 * V_2 , T_2 * V_82 , int * V_56 )
{
struct V_83 * V_84 = V_2 -> V_67 . V_24 . V_85 . V_83 ;
T_1 V_86 [ 4 ] ;
int V_17 ;
F_1 ( V_2 , V_87 , NULL , 0 , V_86 , 4 ) ;
* V_82 = 0 ;
* V_56 = V_88 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_67 . V_24 . V_85 . V_89 ; V_17 ++ ) {
if ( F_35 ( & V_84 [ V_17 ] ) == V_86 [ 2 ] &&
F_36 ( & V_84 [ V_17 ] ) == V_86 [ 3 ] ) {
* V_82 = V_84 [ V_17 ] . V_90 ;
* V_56 = V_91 ;
return 0 ;
}
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_2 * V_82 ,
int * V_56 )
{
struct V_83 * V_84 = V_2 -> V_67 . V_24 . V_85 . V_83 ;
T_1 V_86 [ 4 ] ;
int V_17 ;
struct V_32 V_33 = { . V_28 = 0x6b , . V_41 = V_42 ,
. V_47 = V_86 , . V_45 = 4 } ;
* V_82 = 0 ;
* V_56 = V_88 ;
if ( F_12 ( & V_2 -> V_92 , & V_33 , 1 ) != 1 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_67 . V_24 . V_85 . V_89 ; V_17 ++ ) {
if ( F_35 ( & V_84 [ V_17 ] ) == V_86 [ 1 ] &&
F_36 ( & V_84 [ V_17 ] ) == V_86 [ 2 ] ) {
* V_82 = V_84 [ V_17 ] . V_90 ;
* V_56 = V_91 ;
return 0 ;
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , T_2 * V_82 ,
int * V_56 )
{
struct V_83 * V_84 = V_2 -> V_67 . V_24 . V_85 . V_83 ;
T_1 V_86 [ 2 ] ;
int V_17 ;
* V_82 = 0 ;
* V_56 = V_88 ;
if ( F_1 ( V_2 , 0x10 , NULL , 0 , V_86 , 2 ) < 0 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_67 . V_24 . V_85 . V_89 ; V_17 ++ ) {
if ( F_35 ( & V_84 [ V_17 ] ) == V_86 [ 0 ] &&
F_36 ( & V_84 [ V_17 ] ) == V_86 [ 1 ] ) {
* V_82 = V_84 [ V_17 ] . V_90 ;
* V_56 = V_91 ;
return 0 ;
}
}
return 0 ;
}
static int F_39 ( struct V_93 * V_76 )
{
static T_1 V_94 [] = { V_95 , 0x38 , 0x28 } ;
static T_1 V_96 [] = { V_97 , 0x80 } ;
static T_1 V_98 [] = { V_99 , 0x40 } ;
static T_1 V_100 [] = { V_101 , 0x28 , 0x20 } ;
static T_1 V_102 [] = { V_103 , 0x33 } ;
static T_1 V_104 [] = { V_105 , 0x32 } ;
F_40 ( V_76 , V_94 , sizeof( V_94 ) ) ;
F_41 ( 200 ) ;
F_40 ( V_76 , V_96 , sizeof( V_96 ) ) ;
F_40 ( V_76 , V_98 , sizeof( V_98 ) ) ;
F_40 ( V_76 , V_100 , sizeof( V_100 ) ) ;
F_40 ( V_76 , V_102 , sizeof( V_102 ) ) ;
F_40 ( V_76 , V_104 , sizeof( V_104 ) ) ;
return 0 ;
}
static int F_42 ( struct V_93 * V_76 )
{
static T_1 V_94 [] = { V_95 , 0x38 , 0x29 } ;
static T_1 V_96 [] = { V_97 , 0x80 } ;
static T_1 V_98 [] = { V_99 , 0x40 } ;
static T_1 V_100 [] = { V_101 , 0x24 , 0x20 } ;
static T_1 V_102 [] = { V_103 , 0x33 } ;
static T_1 V_104 [] = { V_105 , 0x32 } ;
F_40 ( V_76 , V_94 , sizeof( V_94 ) ) ;
F_41 ( 200 ) ;
F_40 ( V_76 , V_96 , sizeof( V_96 ) ) ;
F_40 ( V_76 , V_98 , sizeof( V_98 ) ) ;
F_40 ( V_76 , V_100 , sizeof( V_100 ) ) ;
F_40 ( V_76 , V_102 , sizeof( V_102 ) ) ;
F_40 ( V_76 , V_104 , sizeof( V_104 ) ) ;
return 0 ;
}
static int F_43 ( struct V_60 * V_31 )
{
F_44 ( V_106 , V_31 -> V_107 [ 0 ] . V_76 ,
& V_31 -> V_61 -> V_92 , 0x61 ,
V_108 ) ;
return 0 ;
}
static int F_45 ( struct V_60 * V_31 )
{
F_44 ( V_109 , V_31 -> V_107 [ 0 ] . V_76 , 0x61 ,
NULL , V_110 ) ;
return 0 ;
}
static int F_46 ( struct V_60 * V_31 )
{
F_44 ( V_109 , V_31 -> V_107 [ 0 ] . V_76 , 0x61 , NULL , V_111 ) ;
return 0 ;
}
static int F_47 ( struct V_60 * V_31 )
{
F_44 ( V_109 , V_31 -> V_107 [ 0 ] . V_76 , 0x60 ,
NULL , V_110 ) ;
return 0 ;
}
static int F_48 ( struct V_60 * V_31 )
{
F_44 ( V_106 , V_31 -> V_107 [ 0 ] . V_76 ,
& V_31 -> V_61 -> V_92 , 0x61 , V_112 ) ;
return 0 ;
}
static int F_49 ( void * V_113 , int V_114 ,
int V_115 , int V_116 )
{
struct V_60 * V_31 = V_113 ;
struct V_1 * V_2 = V_31 -> V_61 ;
switch ( V_115 ) {
case V_117 :
F_6 ( L_9 , V_118 , V_116 ) ;
F_8 ( V_2 , 0x01 , 1 ) ;
break;
case V_119 :
F_6 ( L_10 , V_118 , V_116 ) ;
break;
default:
F_6 ( L_11 , V_118 ,
V_115 , V_116 ) ;
return - V_120 ;
}
return 0 ;
}
static int F_50 ( struct V_60 * V_31 )
{
struct V_93 * V_76 ;
struct V_121 V_122 = {
. V_92 = & V_31 -> V_61 -> V_92 ,
. V_123 = 0x61 ,
} ;
static struct V_124 V_125 = {
. V_126 = V_127 ,
. V_128 = 64 ,
. V_129 = V_130 ,
} ;
V_31 -> V_107 [ 0 ] . V_76 -> V_131 = F_49 ;
V_76 = F_44 ( V_132 , V_31 -> V_107 [ 0 ] . V_76 , & V_122 ) ;
if ( V_76 == NULL || V_76 -> V_133 . V_134 . V_135 == NULL )
return - V_29 ;
V_76 -> V_133 . V_134 . V_135 ( V_76 , & V_125 ) ;
return 0 ;
}
static int F_51 ( struct V_60 * V_31 )
{
F_44 ( V_136 , V_31 -> V_107 [ 0 ] . V_76 ,
& V_31 -> V_61 -> V_92 , & V_137 ) ;
return 0 ;
}
static int F_52 ( struct V_60 * V_31 )
{
struct V_93 * V_76 ;
V_76 = F_44 ( V_136 , V_31 -> V_107 [ 0 ] . V_76 ,
& V_31 -> V_61 -> V_92 , & V_138 ) ;
return ( V_76 == NULL ) ? - V_29 : 0 ;
}
static int F_53 ( struct V_60 * V_31 )
{
struct V_93 * V_76 ;
V_76 = F_44 ( V_139 , V_31 -> V_107 [ 0 ] . V_76 ,
& V_31 -> V_61 -> V_92 , & V_140 ) ;
return ( V_76 == NULL ) ? - V_29 : 0 ;
}
static int F_54 ( struct V_60 * V_31 )
{
T_1 V_52 ;
if ( F_20 ( V_31 -> V_61 -> V_37 , 0 , 6 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_61 , V_59 , NULL , 0 , & V_52 , 1 ) ;
V_31 -> V_107 [ 0 ] . V_76 = F_44 ( V_141 , & V_142 ,
& V_31 -> V_61 -> V_92 ) ;
if ( ( V_31 -> V_107 [ 0 ] . V_76 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_55 ( struct V_60 * V_31 )
{
if ( F_20 ( V_31 -> V_61 -> V_37 , 0 , 7 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_61 , V_59 , NULL , 0 , NULL , 0 ) ;
V_31 -> V_107 [ 0 ] . V_76 = F_44 ( V_143 ,
& V_144 ,
& V_31 -> V_61 -> V_92 ) ;
if ( ( V_31 -> V_107 [ 0 ] . V_76 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_56 ( struct V_60 * V_31 )
{
V_31 -> V_107 [ 0 ] . V_76 = F_44 ( V_143 , & V_145 ,
& V_31 -> V_61 -> V_92 ) ;
if ( V_31 -> V_107 [ 0 ] . V_76 != NULL )
return 0 ;
return - V_29 ;
}
static int F_57 ( struct V_60 * V_31 )
{
if ( F_20 ( V_31 -> V_61 -> V_37 , 0 , 0 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_61 , V_59 , NULL , 0 , NULL , 0 ) ;
V_31 -> V_107 [ 0 ] . V_76 = F_44 ( V_146 , & V_147 ,
& V_31 -> V_61 -> V_92 ) ;
if ( ( V_31 -> V_107 [ 0 ] . V_76 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_58 ( struct V_60 * V_31 )
{
if ( F_20 ( V_31 -> V_61 -> V_37 , 0 , 0 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_61 , V_59 , NULL , 0 , NULL , 0 ) ;
V_31 -> V_107 [ 0 ] . V_76 = F_44 ( V_146 , & V_148 ,
& V_31 -> V_61 -> V_92 ) ;
if ( ( V_31 -> V_107 [ 0 ] . V_76 ) != NULL )
return 0 ;
V_31 -> V_107 [ 0 ] . V_76 = F_44 ( V_149 ,
& V_150 ,
& V_31 -> V_61 -> V_92 ) ;
if ( ( V_31 -> V_107 [ 0 ] . V_76 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_59 ( struct V_60 * V_31 )
{
T_1 V_86 [ 4 ] ;
int V_17 ;
struct V_32 V_33 = { . V_28 = 0x6b , . V_41 = V_42 ,
. V_47 = V_86 , . V_45 = 4 } ;
if ( F_20 ( V_31 -> V_61 -> V_37 , 0 , 1 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_61 , V_59 , NULL , 0 , NULL , 0 ) ;
F_7 ( V_31 -> V_61 , 0x04 , 0 ) ;
F_8 ( V_31 -> V_61 , 0x01 , 1 ) ;
F_8 ( V_31 -> V_61 , 0x02 , 1 ) ;
V_31 -> V_107 [ 0 ] . V_76 =
F_44 ( V_149 ,
& V_151 ,
& V_31 -> V_61 -> V_92 ) ;
if ( ( V_31 -> V_107 [ 0 ] . V_76 ) == NULL )
return - V_29 ;
for ( V_17 = 0 ; V_31 -> V_61 -> V_67 . V_24 . V_85 . V_83 != NULL && V_17 < 5 ; V_17 ++ ) {
F_9 ( 20 ) ;
if ( F_12 ( & V_31 -> V_61 -> V_92 , & V_33 , 1 ) != 1 )
goto V_152;
if ( V_86 [ 0 ] == 0 && V_86 [ 1 ] == 0 )
continue;
if ( V_86 [ 2 ] + V_86 [ 3 ] != 0xff ) {
V_152:
V_31 -> V_61 -> V_67 . V_24 . V_85 . V_83 = NULL ;
F_60 ( L_12 ) ;
break;
}
}
return 0 ;
}
static int F_61 ( struct V_60 * V_31 )
{
if ( F_20 ( V_31 -> V_61 -> V_37 , 0 , 1 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_61 , V_59 , NULL , 0 , NULL , 0 ) ;
F_8 ( V_31 -> V_61 , 0x02 , 1 ) ;
if ( F_62 ( & V_31 -> V_61 -> V_92 , 1 , 18 ,
& V_153 ) < 0 ) {
F_63 ( V_154 L_13 ) ;
return - V_155 ;
}
V_31 -> V_107 [ 0 ] . V_76 = F_44 ( V_156 , & V_31 -> V_61 -> V_92 , 0x80 ,
& V_153 ) ;
if ( V_31 -> V_107 [ 0 ] . V_76 == NULL )
return - V_29 ;
return 0 ;
}
static int F_64 ( struct V_93 * V_76 , int V_12 )
{
return F_65 ( V_76 , 8 , 0 , ! V_12 ) ;
}
static int F_66 ( struct V_93 * V_76 , int V_12 )
{
return 0 ;
}
static int F_67 ( struct V_93 * V_76 )
{
struct V_157 * V_75 = & V_76 -> V_158 ;
struct V_60 * V_31 = V_76 -> V_159 -> V_15 ;
struct V_160 * V_56 = V_31 -> V_15 ;
T_3 V_161 ;
T_1 V_162 = F_68 ( V_75 -> V_163 / 1000 ) ;
switch ( V_162 ) {
case V_164 : V_161 = 950 ; break;
default:
case V_165 : V_161 = 550 ; break;
}
F_69 ( V_76 , V_161 + F_70 ( V_76 ) ) ;
return V_56 -> V_166 ( V_76 ) ;
}
static int F_71 ( struct V_60 * V_31 )
{
struct V_160 * V_14 = V_31 -> V_15 ;
struct V_30 * V_167 =
F_72 ( V_31 -> V_107 [ 0 ] . V_76 ,
V_168 , 1 ) ;
if ( F_44 ( V_169 , V_31 -> V_107 [ 0 ] . V_76 , V_167 ,
& V_170 ) == NULL )
return - V_155 ;
V_14 -> V_166 = V_31 -> V_107 [ 0 ] . V_76 -> V_133 . V_134 . V_171 ;
V_31 -> V_107 [ 0 ] . V_76 -> V_133 . V_134 . V_171 = F_67 ;
return 0 ;
}
static int F_73 ( struct V_60 * V_31 )
{
if ( F_20 ( V_31 -> V_61 -> V_37 , 0 , 1 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_61 , V_59 , NULL , 0 , NULL , 0 ) ;
F_7 ( V_31 -> V_61 , 0x04 , 0 ) ;
F_8 ( V_31 -> V_61 , 0x01 , 1 ) ;
F_8 ( V_31 -> V_61 , 0x02 , 1 ) ;
V_31 -> V_107 [ 0 ] . V_76 = F_44 ( V_149 ,
& V_172 ,
& V_31 -> V_61 -> V_92 ) ;
if ( ( V_31 -> V_107 [ 0 ] . V_76 ) != NULL )
return 0 ;
V_31 -> V_107 [ 0 ] . V_76 = F_44 ( V_146 ,
& V_173 ,
& V_31 -> V_61 -> V_92 ) ;
if ( ( V_31 -> V_107 [ 0 ] . V_76 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_74 ( struct V_60 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_61 ;
int V_174 ;
if ( F_20 ( V_2 -> V_37 , 0 , 0 ) < 0 )
F_21 ( L_8 ) ;
F_75 ( V_2 -> V_37 ,
F_76 ( V_2 -> V_37 , V_2 -> V_67 . V_68 ) ) ;
F_75 ( V_2 -> V_37 ,
F_30 ( V_2 -> V_37 , V_2 -> V_67 . V_68 ) ) ;
F_75 ( V_2 -> V_37 ,
F_30 ( V_2 -> V_37 , V_2 -> V_67 . V_50 [ 0 ] . V_76 [ 0 ] . V_77 . V_81 ) ) ;
for ( V_174 = 0 ; V_174 < 5 ; V_174 ++ ) {
F_27 ( V_2 ) ;
F_32 ( V_2 ) ;
F_9 ( 200 ) ;
}
if ( F_11 ( V_2 , 0x07 , 0 ) < 0 ) {
F_21 ( L_14 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
if ( F_11 ( V_2 , 0x07 , 1 ) < 0 ) {
F_21 ( L_15 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
V_31 -> V_107 [ 0 ] . V_76 = F_44 ( V_175 , & V_176 , & V_2 -> V_92 ) ;
if ( V_31 -> V_107 [ 0 ] . V_76 == NULL )
return - V_29 ;
return 0 ;
}
static int F_77 ( struct V_60 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_61 ;
if ( F_20 ( V_2 -> V_37 , 0 , 0 ) < 0 )
F_21 ( L_8 ) ;
F_75 ( V_2 -> V_37 ,
F_76 ( V_2 -> V_37 , V_2 -> V_67 . V_68 ) ) ;
F_75 ( V_2 -> V_37 ,
F_30 ( V_2 -> V_37 , V_2 -> V_67 . V_68 ) ) ;
F_75 ( V_2 -> V_37 ,
F_30 ( V_2 -> V_37 , V_2 -> V_67 . V_50 [ 0 ] . V_76 [ 0 ] . V_77 . V_81 ) ) ;
if ( F_11 ( V_2 , 0x07 , 0 ) < 0 ) {
F_21 ( L_14 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
if ( F_11 ( V_2 , 0x07 , 1 ) < 0 ) {
F_21 ( L_15 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
V_31 -> V_107 [ 0 ] . V_76 = F_44 ( V_177 , & V_178 ,
& V_2 -> V_92 ) ;
if ( V_31 -> V_107 [ 0 ] . V_76 == NULL )
return - V_29 ;
return 0 ;
}
static int F_78 ( struct V_179 * V_37 ,
struct V_180 * V_67 ,
struct V_181 * * V_182 ,
int * V_183 )
{
int V_184 = * V_183 ;
* V_183 = V_37 -> V_38 . V_185 == 0xff &&
V_37 -> V_38 . V_186 == 0xff &&
V_37 -> V_38 . V_187 == 0xff ;
if ( * V_183 && ! V_184 )
* V_182 = NULL ;
return 0 ;
}
static int F_79 ( struct V_179 * V_37 ,
const struct V_188 * V_189 )
{
int V_190 ;
for ( V_190 = 0 ; V_190 < F_80 ( V_191 ) ; V_190 ++ ) {
int V_192 = V_191 [ V_190 ] ;
if ( V_189 -> V_193 < V_192 + 4 )
continue;
if ( V_189 -> V_194 [ V_192 ] == ( V_195 & 0xff ) &&
V_189 -> V_194 [ V_192 + 1 ] == V_195 >> 8 ) {
struct V_188 V_196 ;
T_1 * V_197 = F_81 ( V_189 -> V_193 ) ;
int V_55 ;
if ( ! V_197 )
return - V_198 ;
memcpy ( V_197 , V_189 -> V_194 , V_189 -> V_193 ) ;
V_196 . V_193 = V_189 -> V_193 ;
V_196 . V_194 = V_197 ;
V_197 [ V_192 + 2 ] =
F_82 ( V_37 -> V_38 . V_199 ) + 1 ;
V_197 [ V_192 + 3 ] =
F_82 ( V_37 -> V_38 . V_199 ) >> 8 ;
V_55 = F_83 ( V_37 , & V_196 ,
V_200 ) ;
F_84 ( V_197 ) ;
return V_55 ;
}
}
return - V_120 ;
}
static int F_85 ( struct V_201 * V_202 ,
const struct V_203 * V_204 )
{
if ( 0 == F_86 ( V_202 , & V_205 ,
V_206 , NULL , V_207 ) ||
0 == F_86 ( V_202 , & V_208 ,
V_206 , NULL , V_207 ) ||
0 == F_86 ( V_202 , & V_209 ,
V_206 , NULL , V_207 ) ||
0 == F_86 ( V_202 , & V_210 ,
V_206 , NULL , V_207 ) ||
0 == F_86 ( V_202 , & V_211 ,
V_206 , NULL , V_207 ) ||
0 == F_86 ( V_202 , & V_212 ,
V_206 , NULL , V_207 ) ||
0 == F_86 ( V_202 , & V_213 ,
V_206 , NULL , V_207 ) ||
0 == F_86 ( V_202 ,
& V_214 ,
V_206 , NULL , V_207 ) ||
0 == F_86 ( V_202 , & V_215 ,
V_206 , NULL , V_207 ) ||
0 == F_86 ( V_202 ,
& V_216 ,
V_206 , NULL , V_207 ) ||
0 == F_86 ( V_202 , & V_217 ,
V_206 , NULL , V_207 ) ||
0 == F_86 ( V_202 , & V_218 ,
V_206 , NULL , V_207 ) ||
0 )
return 0 ;
return - V_120 ;
}
