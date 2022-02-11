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
static int F_12 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_16 [ 2 ] , V_17 ;
int V_24 ;
V_16 [ 0 ] = 0x83 ;
V_16 [ 1 ] = V_12 ;
V_24 = F_1 ( V_2 , V_20 , V_16 , 2 , & V_17 , 1 ) ;
if ( V_24 ) {
F_6 ( L_2 ) ;
return - V_29 ;
}
return 0 ;
}
static int F_13 ( struct V_30 * V_31 , struct V_32 V_33 [] ,
int V_34 )
{
struct V_1 * V_2 = F_14 ( V_31 ) ;
int V_35 ;
int V_17 ;
if ( F_15 ( & V_2 -> V_36 ) < 0 )
return - V_37 ;
for ( V_17 = 0 ; V_17 < V_34 ; V_17 ++ ) {
if ( V_2 -> V_38 -> V_39 . V_40 == V_41 )
switch ( V_33 [ V_17 ] . V_28 ) {
case 0x63 :
F_5 ( V_2 , 0 ) ;
break;
default:
F_5 ( V_2 , 1 ) ;
break;
}
if ( V_33 [ V_17 ] . V_42 & V_43 ) {
T_1 V_44 [ 3 ] , V_45 [ V_10 ] ;
if ( 1 + V_33 [ V_17 ] . V_46 > sizeof( V_45 ) ) {
F_2 ( L_4 ,
V_33 [ V_17 ] . V_46 ) ;
V_35 = - V_11 ;
goto V_47;
}
V_44 [ 0 ] = 0 ;
V_44 [ 1 ] = V_33 [ V_17 ] . V_46 ;
V_44 [ 2 ] = V_33 [ V_17 ] . V_28 ;
if ( F_1 ( V_2 , V_48 ,
V_44 , 3 ,
V_45 , 1 + V_33 [ V_17 ] . V_46 ) < 0 ) {
F_2 ( L_5 ) ;
break;
}
memcpy ( V_33 [ V_17 ] . V_49 , & V_45 [ 1 ] , V_33 [ V_17 ] . V_46 ) ;
} else if ( V_17 + 1 < V_34 && ( V_33 [ V_17 + 1 ] . V_42 & V_43 ) &&
V_33 [ V_17 ] . V_28 == V_33 [ V_17 + 1 ] . V_28 ) {
T_1 V_44 [ V_10 ] , V_45 [ V_10 ] ;
if ( 3 + V_33 [ V_17 ] . V_46 > sizeof( V_44 ) ) {
F_2 ( L_1 ,
V_33 [ V_17 ] . V_46 ) ;
V_35 = - V_11 ;
goto V_47;
}
if ( 1 + V_33 [ V_17 + 1 ] . V_46 > sizeof( V_45 ) ) {
F_2 ( L_4 ,
V_33 [ V_17 + 1 ] . V_46 ) ;
V_35 = - V_11 ;
goto V_47;
}
V_44 [ 0 ] = V_33 [ V_17 ] . V_46 ;
V_44 [ 1 ] = V_33 [ V_17 + 1 ] . V_46 ;
V_44 [ 2 ] = V_33 [ V_17 ] . V_28 ;
memcpy ( & V_44 [ 3 ] , V_33 [ V_17 ] . V_49 , V_33 [ V_17 ] . V_46 ) ;
if ( F_1 ( V_2 , V_48 ,
V_44 , 3 + V_33 [ V_17 ] . V_46 ,
V_45 , 1 + V_33 [ V_17 + 1 ] . V_46 ) < 0 )
break;
if ( V_45 [ 0 ] != 0x08 )
F_16 ( L_6 ) ;
memcpy ( V_33 [ V_17 + 1 ] . V_49 , & V_45 [ 1 ] , V_33 [ V_17 + 1 ] . V_46 ) ;
V_17 ++ ;
} else {
T_1 V_44 [ V_10 ] , V_45 ;
if ( 2 + V_33 [ V_17 ] . V_46 > sizeof( V_44 ) ) {
F_2 ( L_1 ,
V_33 [ V_17 ] . V_46 ) ;
V_35 = - V_11 ;
goto V_47;
}
V_44 [ 0 ] = V_33 [ V_17 ] . V_28 ;
V_44 [ 1 ] = V_33 [ V_17 ] . V_46 ;
memcpy ( & V_44 [ 2 ] , V_33 [ V_17 ] . V_49 , V_33 [ V_17 ] . V_46 ) ;
if ( F_1 ( V_2 , V_50 , V_44 ,
2 + V_33 [ V_17 ] . V_46 , & V_45 , 1 ) < 0 )
break;
if ( V_45 != 0x08 )
F_16 ( L_7 ) ;
}
}
if ( V_17 == V_34 )
V_35 = V_34 ;
else
V_35 = - V_51 ;
V_47:
F_17 ( & V_2 -> V_36 ) ;
return V_35 ;
}
static T_2 F_18 ( struct V_30 * V_52 )
{
return V_53 ;
}
static int F_19 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_54 = 0 ;
if ( V_12 )
return F_1 ( V_2 , V_55 , & V_54 , 1 , NULL , 0 ) ;
else
return F_1 ( V_2 , V_56 , & V_54 , 1 , NULL , 0 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_12 )
{
int V_35 ;
if ( ! V_12 )
return F_1 ( V_2 , V_56 , NULL , 0 , NULL , 0 ) ;
if ( V_2 -> V_57 == V_58 &&
F_21 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_22 ( L_8 ) ;
do {} while ( ! ( V_35 = F_1 ( V_2 , V_55 , NULL , 0 , NULL , 0 ) ) &&
! ( V_35 = F_1 ( V_2 , 0x15 , NULL , 0 , NULL , 0 ) ) &&
! ( V_35 = F_1 ( V_2 , 0x17 , NULL , 0 , NULL , 0 ) ) && 0 );
if ( ! V_35 ) {
int V_17 ;
T_1 V_49 , V_59 [] = {
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
for ( V_17 = 0 ; V_17 < sizeof( V_59 ) / sizeof( T_1 ) ; V_17 += 4 / sizeof( T_1 ) ) {
V_35 = F_1 ( V_2 , V_50 ,
V_59 + V_17 , 4 , & V_49 , 1 ) ;
if ( V_35 )
break;
if ( V_49 != 0x8 )
return - V_51 ;
}
}
return V_35 ;
}
static int F_23 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_54 = 0 ;
if ( V_12 )
return F_1 ( V_2 , V_55 , & V_54 , 1 , NULL , 0 ) ;
else
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_12 )
{
int V_24 = 0 ;
V_24 = F_19 ( V_2 , V_12 ) ;
if ( ! V_12 )
F_10 ( V_2 , 0 ) ;
return V_24 ;
}
static int F_25 ( struct V_1 * V_2 , int V_12 )
{
int V_35 ;
T_1 V_54 ;
V_35 = F_19 ( V_2 , V_12 ) ;
if ( ! V_12 )
return V_35 ;
F_9 ( 128 ) ;
F_1 ( V_2 , V_60 , NULL , 0 , & V_54 , 1 ) ;
F_9 ( 100 ) ;
return V_35 ;
}
static int F_26 ( struct V_61 * V_31 , int V_12 )
{
T_1 V_49 [ 2 ] = { 0x03 , 0x00 } ;
if ( V_12 )
F_1 ( V_31 -> V_62 , V_63 , V_49 , 2 , NULL , 0 ) ;
else
F_1 ( V_31 -> V_62 , V_64 , NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_61 * V_31 , int V_12 )
{
if ( V_12 )
F_1 ( V_31 -> V_62 , V_65 , NULL , 0 , NULL , 0 ) ;
else
F_1 ( V_31 -> V_62 , V_66 ,
NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
int V_67 = V_2 -> V_68 . V_69 ;
const int V_70 = 100 ;
const int V_71 = 32 ;
T_1 * V_72 ;
int V_73 ;
V_72 = F_29 ( V_71 , V_74 ) ;
if ( ! V_72 )
return;
while ( 1 ) {
if ( F_30 ( V_2 -> V_38 ,
F_31 ( V_2 -> V_38 , V_67 ) ,
V_72 , V_71 , & V_73 , V_70 ) < 0 )
break;
if ( ! V_73 )
break;
}
F_32 ( V_72 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = & V_2 -> V_68 . V_52 [ 0 ] . V_77 [ 0 ] . V_78 ;
const int V_70 = 100 ;
const int V_71 = V_76 -> V_79 . V_80 . V_81 ;
T_1 * V_72 ;
int V_73 ;
V_72 = F_29 ( V_71 , V_74 ) ;
if ( ! V_72 )
return;
while ( 1 ) {
if ( F_30 ( V_2 -> V_38 ,
F_31 ( V_2 -> V_38 , V_76 -> V_82 ) ,
V_72 , V_71 , & V_73 , V_70 ) < 0 )
break;
if ( ! V_73 )
break;
}
F_32 ( V_72 ) ;
}
static int F_34 (
struct V_61 * V_31 , int V_12 )
{
if ( V_12 ) {
T_1 V_49 [ 2 ] = { 0x03 , 0x00 } ;
F_33 ( V_31 -> V_62 ) ;
return F_1 ( V_31 -> V_62 , V_63 ,
V_49 , sizeof( V_49 ) , NULL , 0 ) ;
} else {
int V_35 = F_1 ( V_31 -> V_62 ,
V_64 , NULL , 0 , NULL , 0 ) ;
return V_35 ;
}
}
static int F_35 ( struct V_1 * V_2 , T_2 * V_83 , int * V_57 )
{
struct V_84 * V_85 = V_2 -> V_68 . V_24 . V_86 . V_84 ;
T_1 V_87 [ 4 ] ;
int V_17 ;
F_1 ( V_2 , V_88 , NULL , 0 , V_87 , 4 ) ;
* V_83 = 0 ;
* V_57 = V_89 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_68 . V_24 . V_86 . V_90 ; V_17 ++ ) {
if ( F_36 ( & V_85 [ V_17 ] ) == V_87 [ 2 ] &&
F_37 ( & V_85 [ V_17 ] ) == V_87 [ 3 ] ) {
* V_83 = V_85 [ V_17 ] . V_91 ;
* V_57 = V_92 ;
return 0 ;
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , T_2 * V_83 ,
int * V_57 )
{
struct V_84 * V_85 = V_2 -> V_68 . V_24 . V_86 . V_84 ;
T_1 V_87 [ 4 ] ;
int V_17 ;
struct V_32 V_33 = { . V_28 = 0x6b , . V_42 = V_43 ,
. V_49 = V_87 , . V_46 = 4 } ;
* V_83 = 0 ;
* V_57 = V_89 ;
if ( F_13 ( & V_2 -> V_93 , & V_33 , 1 ) != 1 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_68 . V_24 . V_86 . V_90 ; V_17 ++ ) {
if ( F_36 ( & V_85 [ V_17 ] ) == V_87 [ 1 ] &&
F_37 ( & V_85 [ V_17 ] ) == V_87 [ 2 ] ) {
* V_83 = V_85 [ V_17 ] . V_91 ;
* V_57 = V_92 ;
return 0 ;
}
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_2 * V_83 ,
int * V_57 )
{
struct V_84 * V_85 = V_2 -> V_68 . V_24 . V_86 . V_84 ;
T_1 V_87 [ 2 ] ;
int V_17 ;
* V_83 = 0 ;
* V_57 = V_89 ;
if ( F_1 ( V_2 , 0x10 , NULL , 0 , V_87 , 2 ) < 0 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_68 . V_24 . V_86 . V_90 ; V_17 ++ ) {
if ( F_36 ( & V_85 [ V_17 ] ) == V_87 [ 0 ] &&
F_37 ( & V_85 [ V_17 ] ) == V_87 [ 1 ] ) {
* V_83 = V_85 [ V_17 ] . V_91 ;
* V_57 = V_92 ;
return 0 ;
}
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
T_1 V_17 [ 2 ] ;
int V_35 ;
T_2 V_3 , V_91 ;
T_1 V_94 , V_95 , V_96 ;
V_35 = F_1 ( V_2 , 0x10 , NULL , 0 , V_17 , 2 ) ;
if ( V_35 )
return V_35 ;
V_3 = ( V_17 [ 0 ] << 8 ) | V_17 [ 1 ] ;
if ( V_3 != 0xffff ) {
V_94 = V_3 & 0x3F ;
V_95 = ( V_3 & 0x07C0 ) >> 6 ;
V_96 = ( V_3 & 0x0800 ) >> 11 ;
V_91 = ( V_95 << 8 ) | V_94 ;
F_41 ( V_2 -> V_97 , V_98 , V_91 , V_96 ) ;
}
return 0 ;
}
static int F_42 ( struct V_99 * V_77 )
{
static T_1 V_100 [] = { V_101 , 0x38 , 0x28 } ;
static T_1 V_102 [] = { V_103 , 0x80 } ;
static T_1 V_104 [] = { V_105 , 0x40 } ;
static T_1 V_106 [] = { V_107 , 0x28 , 0x20 } ;
static T_1 V_108 [] = { V_109 , 0x33 } ;
static T_1 V_110 [] = { V_111 , 0x32 } ;
F_43 ( V_77 , V_100 , sizeof( V_100 ) ) ;
F_44 ( 200 ) ;
F_43 ( V_77 , V_102 , sizeof( V_102 ) ) ;
F_43 ( V_77 , V_104 , sizeof( V_104 ) ) ;
F_43 ( V_77 , V_106 , sizeof( V_106 ) ) ;
F_43 ( V_77 , V_108 , sizeof( V_108 ) ) ;
F_43 ( V_77 , V_110 , sizeof( V_110 ) ) ;
return 0 ;
}
static int F_45 ( struct V_99 * V_77 )
{
static T_1 V_100 [] = { V_101 , 0x38 , 0x29 } ;
static T_1 V_102 [] = { V_103 , 0x80 } ;
static T_1 V_104 [] = { V_105 , 0x40 } ;
static T_1 V_106 [] = { V_107 , 0x24 , 0x20 } ;
static T_1 V_108 [] = { V_109 , 0x33 } ;
static T_1 V_110 [] = { V_111 , 0x32 } ;
F_43 ( V_77 , V_100 , sizeof( V_100 ) ) ;
F_44 ( 200 ) ;
F_43 ( V_77 , V_102 , sizeof( V_102 ) ) ;
F_43 ( V_77 , V_104 , sizeof( V_104 ) ) ;
F_43 ( V_77 , V_106 , sizeof( V_106 ) ) ;
F_43 ( V_77 , V_108 , sizeof( V_108 ) ) ;
F_43 ( V_77 , V_110 , sizeof( V_110 ) ) ;
return 0 ;
}
static int F_46 ( struct V_61 * V_31 )
{
F_47 ( V_112 , V_31 -> V_113 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , 0x61 ,
V_114 ) ;
return 0 ;
}
static int F_48 ( struct V_61 * V_31 )
{
F_47 ( V_115 , V_31 -> V_113 [ 0 ] . V_77 , 0x61 ,
NULL , V_116 ) ;
return 0 ;
}
static int F_49 ( struct V_61 * V_31 )
{
F_47 ( V_115 , V_31 -> V_113 [ 0 ] . V_77 , 0x61 , NULL , V_117 ) ;
return 0 ;
}
static int F_50 ( struct V_61 * V_31 )
{
F_47 ( V_115 , V_31 -> V_113 [ 0 ] . V_77 , 0x60 ,
NULL , V_116 ) ;
return 0 ;
}
static int F_51 ( struct V_61 * V_31 )
{
F_47 ( V_112 , V_31 -> V_113 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , 0x61 , V_118 ) ;
return 0 ;
}
static int F_52 ( void * V_119 , int V_120 ,
int V_121 , int V_122 )
{
struct V_61 * V_31 = V_119 ;
struct V_1 * V_2 = V_31 -> V_62 ;
switch ( V_121 ) {
case V_123 :
F_6 ( L_9 , V_124 , V_122 ) ;
F_8 ( V_2 , 0x01 , 1 ) ;
break;
case V_125 :
F_6 ( L_10 , V_124 , V_122 ) ;
break;
default:
F_6 ( L_11 , V_124 ,
V_121 , V_122 ) ;
return - V_126 ;
}
return 0 ;
}
static int F_53 ( struct V_61 * V_31 )
{
struct V_99 * V_77 ;
struct V_127 V_128 = {
. V_93 = & V_31 -> V_62 -> V_93 ,
. V_129 = 0x61 ,
} ;
static struct V_130 V_131 = {
. V_132 = V_133 ,
. V_134 = 64 ,
. V_135 = V_136 ,
} ;
V_31 -> V_113 [ 0 ] . V_77 -> V_137 = F_52 ;
V_77 = F_47 ( V_138 , V_31 -> V_113 [ 0 ] . V_77 , & V_128 ) ;
if ( V_77 == NULL || V_77 -> V_139 . V_140 . V_141 == NULL )
return - V_29 ;
V_77 -> V_139 . V_140 . V_141 ( V_77 , & V_131 ) ;
return 0 ;
}
static int F_54 ( struct V_61 * V_31 )
{
F_47 ( V_142 , V_31 -> V_113 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , & V_143 ) ;
return 0 ;
}
static int F_55 ( struct V_61 * V_31 )
{
struct V_99 * V_77 ;
V_77 = F_47 ( V_142 , V_31 -> V_113 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , & V_144 ) ;
return ( V_77 == NULL ) ? - V_29 : 0 ;
}
static int F_56 ( struct V_61 * V_31 )
{
struct V_99 * V_77 ;
V_77 = F_47 ( V_145 , V_31 -> V_113 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , & V_146 ) ;
return ( V_77 == NULL ) ? - V_29 : 0 ;
}
static int F_57 ( struct V_61 * V_31 )
{
T_1 V_54 ;
if ( F_21 ( V_31 -> V_62 -> V_38 , 0 , 6 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , & V_54 , 1 ) ;
V_31 -> V_113 [ 0 ] . V_77 = F_47 ( V_147 , & V_148 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_113 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_58 ( struct V_61 * V_31 )
{
if ( F_21 ( V_31 -> V_62 -> V_38 , 0 , 7 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
V_31 -> V_113 [ 0 ] . V_77 = F_47 ( V_149 ,
& V_150 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_113 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_59 ( struct V_61 * V_31 )
{
V_31 -> V_113 [ 0 ] . V_77 = F_47 ( V_149 , & V_151 ,
& V_31 -> V_62 -> V_93 ) ;
if ( V_31 -> V_113 [ 0 ] . V_77 != NULL )
return 0 ;
return - V_29 ;
}
static int F_60 ( struct V_61 * V_31 )
{
if ( F_21 ( V_31 -> V_62 -> V_38 , 0 , 0 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
V_31 -> V_113 [ 0 ] . V_77 = F_47 ( V_152 , & V_153 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_113 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_61 ( struct V_61 * V_31 )
{
if ( F_21 ( V_31 -> V_62 -> V_38 , 0 , 0 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
V_31 -> V_113 [ 0 ] . V_77 = F_47 ( V_152 , & V_154 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_113 [ 0 ] . V_77 ) != NULL )
return 0 ;
V_31 -> V_113 [ 0 ] . V_77 = F_47 ( V_155 ,
& V_156 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_113 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_62 ( struct V_61 * V_31 )
{
T_1 V_87 [ 4 ] ;
int V_17 ;
struct V_32 V_33 = { . V_28 = 0x6b , . V_42 = V_43 ,
. V_49 = V_87 , . V_46 = 4 } ;
if ( F_21 ( V_31 -> V_62 -> V_38 , 0 , 1 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
F_7 ( V_31 -> V_62 , 0x04 , 0 ) ;
F_8 ( V_31 -> V_62 , 0x01 , 1 ) ;
F_8 ( V_31 -> V_62 , 0x02 , 1 ) ;
V_31 -> V_113 [ 0 ] . V_77 =
F_47 ( V_155 ,
& V_157 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_113 [ 0 ] . V_77 ) == NULL )
return - V_29 ;
for ( V_17 = 0 ; V_31 -> V_62 -> V_68 . V_24 . V_86 . V_84 != NULL && V_17 < 5 ; V_17 ++ ) {
F_9 ( 20 ) ;
if ( F_13 ( & V_31 -> V_62 -> V_93 , & V_33 , 1 ) != 1 )
goto V_158;
if ( V_87 [ 0 ] == 0 && V_87 [ 1 ] == 0 )
continue;
if ( V_87 [ 2 ] + V_87 [ 3 ] != 0xff ) {
V_158:
V_31 -> V_62 -> V_68 . V_24 . V_86 . V_84 = NULL ;
F_63 ( L_12 ) ;
break;
}
}
return 0 ;
}
static int F_64 ( struct V_61 * V_31 )
{
struct V_159 * V_57 = V_31 -> V_15 ;
if ( F_21 ( V_31 -> V_62 -> V_38 , 0 , 1 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
F_8 ( V_31 -> V_62 , 0x02 , 1 ) ;
if ( ! F_47 ( V_160 , & V_57 -> V_161 ) )
return - V_162 ;
if ( V_57 -> V_161 . V_163 ( & V_31 -> V_62 -> V_93 , 1 , 18 ,
& V_164 ) < 0 ) {
F_65 ( V_165 L_13 ) ;
return - V_162 ;
}
V_31 -> V_113 [ 0 ] . V_77 = V_57 -> V_161 . V_166 ( & V_31 -> V_62 -> V_93 , 0x80 ,
& V_164 ) ;
if ( V_31 -> V_113 [ 0 ] . V_77 == NULL )
return - V_29 ;
return 0 ;
}
static int F_66 ( struct V_99 * V_77 , int V_12 )
{
struct V_61 * V_31 = V_77 -> V_167 -> V_15 ;
struct V_159 * V_57 = V_31 -> V_15 ;
return V_57 -> V_161 . V_168 ( V_77 , 8 , 0 , ! V_12 ) ;
}
static int F_67 ( struct V_99 * V_77 , int V_12 )
{
return 0 ;
}
static int F_68 ( struct V_99 * V_77 )
{
struct V_169 * V_76 = & V_77 -> V_170 ;
struct V_61 * V_31 = V_77 -> V_167 -> V_15 ;
struct V_159 * V_57 = V_31 -> V_15 ;
T_3 V_171 ;
T_1 V_172 = F_69 ( V_76 -> V_173 / 1000 ) ;
switch ( V_172 ) {
case V_174 : V_171 = 950 ; break;
default:
case V_175 : V_171 = 550 ; break;
}
V_57 -> V_161 . V_176 ( V_77 , V_171 + F_70 ( V_77 ) ) ;
return V_57 -> V_177 ( V_77 ) ;
}
static int F_71 ( struct V_61 * V_31 )
{
struct V_159 * V_14 = V_31 -> V_15 ;
struct V_30 * V_178 ;
V_178 = V_14 -> V_161 . V_179 ( V_31 -> V_113 [ 0 ] . V_77 ,
V_180 , 1 ) ;
if ( F_47 ( V_181 , V_31 -> V_113 [ 0 ] . V_77 , V_178 ,
& V_182 ) == NULL )
return - V_162 ;
V_14 -> V_177 = V_31 -> V_113 [ 0 ] . V_77 -> V_139 . V_140 . V_183 ;
V_31 -> V_113 [ 0 ] . V_77 -> V_139 . V_140 . V_183 = F_68 ;
return 0 ;
}
static int F_72 ( struct V_61 * V_31 )
{
if ( F_21 ( V_31 -> V_62 -> V_38 , 0 , 1 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
F_7 ( V_31 -> V_62 , 0x04 , 0 ) ;
F_8 ( V_31 -> V_62 , 0x01 , 1 ) ;
F_8 ( V_31 -> V_62 , 0x02 , 1 ) ;
V_31 -> V_113 [ 0 ] . V_77 = F_47 ( V_155 ,
& V_184 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_113 [ 0 ] . V_77 ) != NULL )
return 0 ;
V_31 -> V_113 [ 0 ] . V_77 = F_47 ( V_152 ,
& V_185 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_113 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_73 ( struct V_61 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_62 ;
int V_186 ;
if ( F_21 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_22 ( L_8 ) ;
F_74 ( V_2 -> V_38 ,
F_75 ( V_2 -> V_38 , V_2 -> V_68 . V_69 ) ) ;
F_74 ( V_2 -> V_38 ,
F_31 ( V_2 -> V_38 , V_2 -> V_68 . V_69 ) ) ;
F_74 ( V_2 -> V_38 ,
F_31 ( V_2 -> V_38 , V_2 -> V_68 . V_52 [ 0 ] . V_77 [ 0 ] . V_78 . V_82 ) ) ;
for ( V_186 = 0 ; V_186 < 5 ; V_186 ++ ) {
F_28 ( V_2 ) ;
F_33 ( V_2 ) ;
F_9 ( 200 ) ;
}
if ( F_11 ( V_2 , 0x07 , 0 ) < 0 ) {
F_22 ( L_14 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
if ( F_11 ( V_2 , 0x07 , 1 ) < 0 ) {
F_22 ( L_15 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
V_31 -> V_113 [ 0 ] . V_77 = F_47 ( V_187 , & V_188 , & V_2 -> V_93 ) ;
if ( V_31 -> V_113 [ 0 ] . V_77 == NULL )
return - V_29 ;
return 0 ;
}
static int F_76 ( struct V_61 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_62 ;
if ( F_21 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_22 ( L_8 ) ;
F_74 ( V_2 -> V_38 ,
F_75 ( V_2 -> V_38 , V_2 -> V_68 . V_69 ) ) ;
F_74 ( V_2 -> V_38 ,
F_31 ( V_2 -> V_38 , V_2 -> V_68 . V_69 ) ) ;
F_74 ( V_2 -> V_38 ,
F_31 ( V_2 -> V_38 , V_2 -> V_68 . V_52 [ 0 ] . V_77 [ 0 ] . V_78 . V_82 ) ) ;
if ( F_11 ( V_2 , 0x07 , 0 ) < 0 ) {
F_22 ( L_14 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
if ( F_11 ( V_2 , 0x07 , 1 ) < 0 ) {
F_22 ( L_15 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
V_31 -> V_113 [ 0 ] . V_77 = F_47 ( V_189 , & V_190 ,
& V_2 -> V_93 ) ;
if ( V_31 -> V_113 [ 0 ] . V_77 == NULL )
return - V_29 ;
return 0 ;
}
static int F_77 ( struct V_61 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_62 ;
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_30 * V_52 ;
struct V_191 * V_192 ;
struct V_191 * V_193 ;
struct V_194 F_63 ;
struct V_195 V_195 ;
struct V_196 V_196 ;
if ( F_12 ( V_2 , 0 ) < 0 ) {
F_22 ( L_14 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
if ( F_12 ( V_2 , 1 ) < 0 ) {
F_22 ( L_15 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
V_195 . V_30 = & V_52 ;
V_195 . V_77 = & V_31 -> V_113 [ 0 ] . V_77 ;
memset ( & F_63 , 0 , sizeof( struct V_194 ) ) ;
F_78 ( F_63 . type , L_16 , V_197 ) ;
F_63 . V_28 = 0x64 ;
F_63 . V_198 = & V_195 ;
F_79 ( F_63 . type ) ;
V_192 = F_80 ( & V_2 -> V_93 , & F_63 ) ;
if ( V_192 == NULL || V_192 -> V_62 . V_199 == NULL )
return - V_162 ;
if ( ! F_81 ( V_192 -> V_62 . V_199 -> V_200 ) ) {
F_82 ( V_192 ) ;
return - V_162 ;
}
V_14 -> V_201 = V_192 ;
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
V_196 . V_77 = V_31 -> V_113 [ 0 ] . V_77 ;
memset ( & F_63 , 0 , sizeof( struct V_194 ) ) ;
F_78 ( F_63 . type , L_17 , V_197 ) ;
F_63 . V_28 = 0x60 ;
F_63 . V_198 = & V_196 ;
F_79 ( F_63 . type ) ;
V_193 = F_80 ( V_52 , & F_63 ) ;
if ( V_193 == NULL || V_193 -> V_62 . V_199 == NULL ) {
F_83 ( V_192 -> V_62 . V_199 -> V_200 ) ;
F_82 ( V_192 ) ;
return - V_162 ;
}
if ( ! F_81 ( V_193 -> V_62 . V_199 -> V_200 ) ) {
F_82 ( V_193 ) ;
F_83 ( V_192 -> V_62 . V_199 -> V_200 ) ;
F_82 ( V_192 ) ;
return - V_162 ;
}
V_14 -> V_202 = V_193 ;
return 0 ;
}
static int F_84 ( struct V_203 * V_38 ,
struct V_204 * V_68 ,
struct V_205 * * V_206 ,
int * V_207 )
{
int V_208 = * V_207 ;
* V_207 = V_38 -> V_39 . V_209 == 0xff &&
V_38 -> V_39 . V_210 == 0xff &&
V_38 -> V_39 . V_211 == 0xff ;
if ( * V_207 && ! V_208 )
* V_206 = NULL ;
return 0 ;
}
static int F_85 ( struct V_203 * V_38 ,
const struct V_212 * V_213 )
{
int V_214 ;
for ( V_214 = 0 ; V_214 < F_86 ( V_215 ) ; V_214 ++ ) {
int V_216 = V_215 [ V_214 ] ;
if ( V_213 -> V_217 < V_216 + 4 )
continue;
if ( V_213 -> V_218 [ V_216 ] == ( V_219 & 0xff ) &&
V_213 -> V_218 [ V_216 + 1 ] == V_219 >> 8 ) {
struct V_212 V_220 ;
T_1 * V_221 = F_87 ( V_213 -> V_217 ) ;
int V_35 ;
if ( ! V_221 )
return - V_222 ;
memcpy ( V_221 , V_213 -> V_218 , V_213 -> V_217 ) ;
V_220 . V_217 = V_213 -> V_217 ;
V_220 . V_218 = V_221 ;
V_221 [ V_216 + 2 ] =
F_88 ( V_38 -> V_39 . V_223 ) + 1 ;
V_221 [ V_216 + 3 ] =
F_88 ( V_38 -> V_39 . V_223 ) >> 8 ;
V_35 = F_89 ( V_38 , & V_220 ,
V_224 ) ;
F_90 ( V_221 ) ;
return V_35 ;
}
}
return - V_126 ;
}
static int F_91 ( struct V_225 * V_226 ,
const struct V_227 * V_228 )
{
if ( 0 == F_92 ( V_226 , & V_229 ,
V_230 , NULL , V_231 ) ||
0 == F_92 ( V_226 , & V_232 ,
V_230 , NULL , V_231 ) ||
0 == F_92 ( V_226 , & V_233 ,
V_230 , NULL , V_231 ) ||
0 == F_92 ( V_226 , & V_234 ,
V_230 , NULL , V_231 ) ||
0 == F_92 ( V_226 , & V_235 ,
V_230 , NULL , V_231 ) ||
0 == F_92 ( V_226 , & V_236 ,
V_230 , NULL , V_231 ) ||
0 == F_92 ( V_226 , & V_237 ,
V_230 , NULL , V_231 ) ||
0 == F_92 ( V_226 ,
& V_238 ,
V_230 , NULL , V_231 ) ||
0 == F_92 ( V_226 , & V_239 ,
V_230 , NULL , V_231 ) ||
0 == F_92 ( V_226 ,
& V_240 ,
V_230 , NULL , V_231 ) ||
0 == F_92 ( V_226 , & V_241 ,
V_230 , NULL , V_231 ) ||
0 == F_92 ( V_226 , & V_242 ,
V_230 , NULL , V_231 ) ||
0 == F_92 ( V_226 , & V_243 ,
V_230 , NULL , V_231 ) ||
0 )
return 0 ;
return - V_126 ;
}
static void F_93 ( struct V_225 * V_226 )
{
struct V_1 * V_2 = F_94 ( V_226 ) ;
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_191 * V_244 ;
V_244 = V_14 -> V_202 ;
if ( V_244 ) {
F_83 ( V_244 -> V_62 . V_199 -> V_200 ) ;
F_82 ( V_244 ) ;
}
V_244 = V_14 -> V_201 ;
if ( V_244 ) {
F_83 ( V_244 -> V_62 . V_199 -> V_200 ) ;
F_82 ( V_244 ) ;
}
F_95 ( V_226 ) ;
}
