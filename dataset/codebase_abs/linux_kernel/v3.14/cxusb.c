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
int V_35 ;
int V_17 ;
if ( F_14 ( & V_2 -> V_36 ) < 0 )
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
F_15 ( L_6 ) ;
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
F_15 ( L_7 ) ;
}
}
if ( V_17 == V_34 )
V_35 = V_34 ;
else
V_35 = - V_51 ;
V_47:
F_16 ( & V_2 -> V_36 ) ;
return V_35 ;
}
static T_2 F_17 ( struct V_30 * V_52 )
{
return V_53 ;
}
static int F_18 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_54 = 0 ;
if ( V_12 )
return F_1 ( V_2 , V_55 , & V_54 , 1 , NULL , 0 ) ;
else
return F_1 ( V_2 , V_56 , & V_54 , 1 , NULL , 0 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_12 )
{
int V_35 ;
if ( ! V_12 )
return F_1 ( V_2 , V_56 , NULL , 0 , NULL , 0 ) ;
if ( V_2 -> V_57 == V_58 &&
F_20 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_21 ( L_8 ) ;
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
static int F_22 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_54 = 0 ;
if ( V_12 )
return F_1 ( V_2 , V_55 , & V_54 , 1 , NULL , 0 ) ;
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
int V_35 ;
T_1 V_54 ;
V_35 = F_18 ( V_2 , V_12 ) ;
if ( ! V_12 )
return V_35 ;
F_9 ( 128 ) ;
F_1 ( V_2 , V_60 , NULL , 0 , & V_54 , 1 ) ;
F_9 ( 100 ) ;
return V_35 ;
}
static int F_25 ( struct V_61 * V_31 , int V_12 )
{
T_1 V_49 [ 2 ] = { 0x03 , 0x00 } ;
if ( V_12 )
F_1 ( V_31 -> V_62 , V_63 , V_49 , 2 , NULL , 0 ) ;
else
F_1 ( V_31 -> V_62 , V_64 , NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_61 * V_31 , int V_12 )
{
if ( V_12 )
F_1 ( V_31 -> V_62 , V_65 , NULL , 0 , NULL , 0 ) ;
else
F_1 ( V_31 -> V_62 , V_66 ,
NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_67 = V_2 -> V_68 . V_69 ;
const int V_70 = 100 ;
const int V_71 = 32 ;
T_1 * V_72 ;
int V_73 ;
V_72 = F_28 ( V_71 , V_74 ) ;
if ( ! V_72 )
return;
while ( 1 ) {
if ( F_29 ( V_2 -> V_38 ,
F_30 ( V_2 -> V_38 , V_67 ) ,
V_72 , V_71 , & V_73 , V_70 ) < 0 )
break;
if ( ! V_73 )
break;
}
F_31 ( V_72 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = & V_2 -> V_68 . V_52 [ 0 ] . V_77 [ 0 ] . V_78 ;
const int V_70 = 100 ;
const int V_71 = V_76 -> V_79 . V_80 . V_81 ;
T_1 * V_72 ;
int V_73 ;
V_72 = F_28 ( V_71 , V_74 ) ;
if ( ! V_72 )
return;
while ( 1 ) {
if ( F_29 ( V_2 -> V_38 ,
F_30 ( V_2 -> V_38 , V_76 -> V_82 ) ,
V_72 , V_71 , & V_73 , V_70 ) < 0 )
break;
if ( ! V_73 )
break;
}
F_31 ( V_72 ) ;
}
static int F_33 (
struct V_61 * V_31 , int V_12 )
{
if ( V_12 ) {
T_1 V_49 [ 2 ] = { 0x03 , 0x00 } ;
F_32 ( V_31 -> V_62 ) ;
return F_1 ( V_31 -> V_62 , V_63 ,
V_49 , sizeof( V_49 ) , NULL , 0 ) ;
} else {
int V_35 = F_1 ( V_31 -> V_62 ,
V_64 , NULL , 0 , NULL , 0 ) ;
return V_35 ;
}
}
static int F_34 ( struct V_1 * V_2 , T_2 * V_83 , int * V_57 )
{
struct V_84 * V_85 = V_2 -> V_68 . V_24 . V_86 . V_84 ;
T_1 V_87 [ 4 ] ;
int V_17 ;
F_1 ( V_2 , V_88 , NULL , 0 , V_87 , 4 ) ;
* V_83 = 0 ;
* V_57 = V_89 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_68 . V_24 . V_86 . V_90 ; V_17 ++ ) {
if ( F_35 ( & V_85 [ V_17 ] ) == V_87 [ 2 ] &&
F_36 ( & V_85 [ V_17 ] ) == V_87 [ 3 ] ) {
* V_83 = V_85 [ V_17 ] . V_91 ;
* V_57 = V_92 ;
return 0 ;
}
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_2 * V_83 ,
int * V_57 )
{
struct V_84 * V_85 = V_2 -> V_68 . V_24 . V_86 . V_84 ;
T_1 V_87 [ 4 ] ;
int V_17 ;
struct V_32 V_33 = { . V_28 = 0x6b , . V_42 = V_43 ,
. V_49 = V_87 , . V_46 = 4 } ;
* V_83 = 0 ;
* V_57 = V_89 ;
if ( F_12 ( & V_2 -> V_93 , & V_33 , 1 ) != 1 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_68 . V_24 . V_86 . V_90 ; V_17 ++ ) {
if ( F_35 ( & V_85 [ V_17 ] ) == V_87 [ 1 ] &&
F_36 ( & V_85 [ V_17 ] ) == V_87 [ 2 ] ) {
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
T_1 V_87 [ 2 ] ;
int V_17 ;
* V_83 = 0 ;
* V_57 = V_89 ;
if ( F_1 ( V_2 , 0x10 , NULL , 0 , V_87 , 2 ) < 0 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_68 . V_24 . V_86 . V_90 ; V_17 ++ ) {
if ( F_35 ( & V_85 [ V_17 ] ) == V_87 [ 0 ] &&
F_36 ( & V_85 [ V_17 ] ) == V_87 [ 1 ] ) {
* V_83 = V_85 [ V_17 ] . V_91 ;
* V_57 = V_92 ;
return 0 ;
}
}
return 0 ;
}
static int F_39 ( struct V_94 * V_77 )
{
static T_1 V_95 [] = { V_96 , 0x38 , 0x28 } ;
static T_1 V_97 [] = { V_98 , 0x80 } ;
static T_1 V_99 [] = { V_100 , 0x40 } ;
static T_1 V_101 [] = { V_102 , 0x28 , 0x20 } ;
static T_1 V_103 [] = { V_104 , 0x33 } ;
static T_1 V_105 [] = { V_106 , 0x32 } ;
F_40 ( V_77 , V_95 , sizeof( V_95 ) ) ;
F_41 ( 200 ) ;
F_40 ( V_77 , V_97 , sizeof( V_97 ) ) ;
F_40 ( V_77 , V_99 , sizeof( V_99 ) ) ;
F_40 ( V_77 , V_101 , sizeof( V_101 ) ) ;
F_40 ( V_77 , V_103 , sizeof( V_103 ) ) ;
F_40 ( V_77 , V_105 , sizeof( V_105 ) ) ;
return 0 ;
}
static int F_42 ( struct V_94 * V_77 )
{
static T_1 V_95 [] = { V_96 , 0x38 , 0x29 } ;
static T_1 V_97 [] = { V_98 , 0x80 } ;
static T_1 V_99 [] = { V_100 , 0x40 } ;
static T_1 V_101 [] = { V_102 , 0x24 , 0x20 } ;
static T_1 V_103 [] = { V_104 , 0x33 } ;
static T_1 V_105 [] = { V_106 , 0x32 } ;
F_40 ( V_77 , V_95 , sizeof( V_95 ) ) ;
F_41 ( 200 ) ;
F_40 ( V_77 , V_97 , sizeof( V_97 ) ) ;
F_40 ( V_77 , V_99 , sizeof( V_99 ) ) ;
F_40 ( V_77 , V_101 , sizeof( V_101 ) ) ;
F_40 ( V_77 , V_103 , sizeof( V_103 ) ) ;
F_40 ( V_77 , V_105 , sizeof( V_105 ) ) ;
return 0 ;
}
static int F_43 ( struct V_61 * V_31 )
{
F_44 ( V_107 , V_31 -> V_108 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , 0x61 ,
V_109 ) ;
return 0 ;
}
static int F_45 ( struct V_61 * V_31 )
{
F_44 ( V_110 , V_31 -> V_108 [ 0 ] . V_77 , 0x61 ,
NULL , V_111 ) ;
return 0 ;
}
static int F_46 ( struct V_61 * V_31 )
{
F_44 ( V_110 , V_31 -> V_108 [ 0 ] . V_77 , 0x61 , NULL , V_112 ) ;
return 0 ;
}
static int F_47 ( struct V_61 * V_31 )
{
F_44 ( V_110 , V_31 -> V_108 [ 0 ] . V_77 , 0x60 ,
NULL , V_111 ) ;
return 0 ;
}
static int F_48 ( struct V_61 * V_31 )
{
F_44 ( V_107 , V_31 -> V_108 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , 0x61 , V_113 ) ;
return 0 ;
}
static int F_49 ( void * V_114 , int V_115 ,
int V_116 , int V_117 )
{
struct V_61 * V_31 = V_114 ;
struct V_1 * V_2 = V_31 -> V_62 ;
switch ( V_116 ) {
case V_118 :
F_6 ( L_9 , V_119 , V_117 ) ;
F_8 ( V_2 , 0x01 , 1 ) ;
break;
case V_120 :
F_6 ( L_10 , V_119 , V_117 ) ;
break;
default:
F_6 ( L_11 , V_119 ,
V_116 , V_117 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_50 ( struct V_61 * V_31 )
{
struct V_94 * V_77 ;
struct V_122 V_123 = {
. V_93 = & V_31 -> V_62 -> V_93 ,
. V_124 = 0x61 ,
} ;
static struct V_125 V_126 = {
. V_127 = V_128 ,
. V_129 = 64 ,
. V_130 = V_131 ,
} ;
V_31 -> V_108 [ 0 ] . V_77 -> V_132 = F_49 ;
V_77 = F_44 ( V_133 , V_31 -> V_108 [ 0 ] . V_77 , & V_123 ) ;
if ( V_77 == NULL || V_77 -> V_134 . V_135 . V_136 == NULL )
return - V_29 ;
V_77 -> V_134 . V_135 . V_136 ( V_77 , & V_126 ) ;
return 0 ;
}
static int F_51 ( struct V_61 * V_31 )
{
F_44 ( V_137 , V_31 -> V_108 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , & V_138 ) ;
return 0 ;
}
static int F_52 ( struct V_61 * V_31 )
{
struct V_94 * V_77 ;
V_77 = F_44 ( V_137 , V_31 -> V_108 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , & V_139 ) ;
return ( V_77 == NULL ) ? - V_29 : 0 ;
}
static int F_53 ( struct V_61 * V_31 )
{
struct V_94 * V_77 ;
V_77 = F_44 ( V_140 , V_31 -> V_108 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , & V_141 ) ;
return ( V_77 == NULL ) ? - V_29 : 0 ;
}
static int F_54 ( struct V_61 * V_31 )
{
T_1 V_54 ;
if ( F_20 ( V_31 -> V_62 -> V_38 , 0 , 6 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , & V_54 , 1 ) ;
V_31 -> V_108 [ 0 ] . V_77 = F_44 ( V_142 , & V_143 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_108 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_55 ( struct V_61 * V_31 )
{
if ( F_20 ( V_31 -> V_62 -> V_38 , 0 , 7 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
V_31 -> V_108 [ 0 ] . V_77 = F_44 ( V_144 ,
& V_145 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_108 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_56 ( struct V_61 * V_31 )
{
V_31 -> V_108 [ 0 ] . V_77 = F_44 ( V_144 , & V_146 ,
& V_31 -> V_62 -> V_93 ) ;
if ( V_31 -> V_108 [ 0 ] . V_77 != NULL )
return 0 ;
return - V_29 ;
}
static int F_57 ( struct V_61 * V_31 )
{
if ( F_20 ( V_31 -> V_62 -> V_38 , 0 , 0 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
V_31 -> V_108 [ 0 ] . V_77 = F_44 ( V_147 , & V_148 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_108 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_58 ( struct V_61 * V_31 )
{
if ( F_20 ( V_31 -> V_62 -> V_38 , 0 , 0 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
V_31 -> V_108 [ 0 ] . V_77 = F_44 ( V_147 , & V_149 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_108 [ 0 ] . V_77 ) != NULL )
return 0 ;
V_31 -> V_108 [ 0 ] . V_77 = F_44 ( V_150 ,
& V_151 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_108 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_59 ( struct V_61 * V_31 )
{
T_1 V_87 [ 4 ] ;
int V_17 ;
struct V_32 V_33 = { . V_28 = 0x6b , . V_42 = V_43 ,
. V_49 = V_87 , . V_46 = 4 } ;
if ( F_20 ( V_31 -> V_62 -> V_38 , 0 , 1 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
F_7 ( V_31 -> V_62 , 0x04 , 0 ) ;
F_8 ( V_31 -> V_62 , 0x01 , 1 ) ;
F_8 ( V_31 -> V_62 , 0x02 , 1 ) ;
V_31 -> V_108 [ 0 ] . V_77 =
F_44 ( V_150 ,
& V_152 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_108 [ 0 ] . V_77 ) == NULL )
return - V_29 ;
for ( V_17 = 0 ; V_31 -> V_62 -> V_68 . V_24 . V_86 . V_84 != NULL && V_17 < 5 ; V_17 ++ ) {
F_9 ( 20 ) ;
if ( F_12 ( & V_31 -> V_62 -> V_93 , & V_33 , 1 ) != 1 )
goto V_153;
if ( V_87 [ 0 ] == 0 && V_87 [ 1 ] == 0 )
continue;
if ( V_87 [ 2 ] + V_87 [ 3 ] != 0xff ) {
V_153:
V_31 -> V_62 -> V_68 . V_24 . V_86 . V_84 = NULL ;
F_60 ( L_12 ) ;
break;
}
}
return 0 ;
}
static int F_61 ( struct V_61 * V_31 )
{
if ( F_20 ( V_31 -> V_62 -> V_38 , 0 , 1 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
F_8 ( V_31 -> V_62 , 0x02 , 1 ) ;
if ( F_62 ( & V_31 -> V_62 -> V_93 , 1 , 18 ,
& V_154 ) < 0 ) {
F_63 ( V_155 L_13 ) ;
return - V_156 ;
}
V_31 -> V_108 [ 0 ] . V_77 = F_44 ( V_157 , & V_31 -> V_62 -> V_93 , 0x80 ,
& V_154 ) ;
if ( V_31 -> V_108 [ 0 ] . V_77 == NULL )
return - V_29 ;
return 0 ;
}
static int F_64 ( struct V_94 * V_77 , int V_12 )
{
return F_65 ( V_77 , 8 , 0 , ! V_12 ) ;
}
static int F_66 ( struct V_94 * V_77 , int V_12 )
{
return 0 ;
}
static int F_67 ( struct V_94 * V_77 )
{
struct V_158 * V_76 = & V_77 -> V_159 ;
struct V_61 * V_31 = V_77 -> V_160 -> V_15 ;
struct V_161 * V_57 = V_31 -> V_15 ;
T_3 V_162 ;
T_1 V_163 = F_68 ( V_76 -> V_164 / 1000 ) ;
switch ( V_163 ) {
case V_165 : V_162 = 950 ; break;
default:
case V_166 : V_162 = 550 ; break;
}
F_69 ( V_77 , V_162 + F_70 ( V_77 ) ) ;
return V_57 -> V_167 ( V_77 ) ;
}
static int F_71 ( struct V_61 * V_31 )
{
struct V_161 * V_14 = V_31 -> V_15 ;
struct V_30 * V_168 =
F_72 ( V_31 -> V_108 [ 0 ] . V_77 ,
V_169 , 1 ) ;
if ( F_44 ( V_170 , V_31 -> V_108 [ 0 ] . V_77 , V_168 ,
& V_171 ) == NULL )
return - V_156 ;
V_14 -> V_167 = V_31 -> V_108 [ 0 ] . V_77 -> V_134 . V_135 . V_172 ;
V_31 -> V_108 [ 0 ] . V_77 -> V_134 . V_135 . V_172 = F_67 ;
return 0 ;
}
static int F_73 ( struct V_61 * V_31 )
{
if ( F_20 ( V_31 -> V_62 -> V_38 , 0 , 1 ) < 0 )
F_21 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
F_7 ( V_31 -> V_62 , 0x04 , 0 ) ;
F_8 ( V_31 -> V_62 , 0x01 , 1 ) ;
F_8 ( V_31 -> V_62 , 0x02 , 1 ) ;
V_31 -> V_108 [ 0 ] . V_77 = F_44 ( V_150 ,
& V_173 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_108 [ 0 ] . V_77 ) != NULL )
return 0 ;
V_31 -> V_108 [ 0 ] . V_77 = F_44 ( V_147 ,
& V_174 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_108 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_74 ( struct V_61 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_62 ;
int V_175 ;
if ( F_20 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_21 ( L_8 ) ;
F_75 ( V_2 -> V_38 ,
F_76 ( V_2 -> V_38 , V_2 -> V_68 . V_69 ) ) ;
F_75 ( V_2 -> V_38 ,
F_30 ( V_2 -> V_38 , V_2 -> V_68 . V_69 ) ) ;
F_75 ( V_2 -> V_38 ,
F_30 ( V_2 -> V_38 , V_2 -> V_68 . V_52 [ 0 ] . V_77 [ 0 ] . V_78 . V_82 ) ) ;
for ( V_175 = 0 ; V_175 < 5 ; V_175 ++ ) {
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
V_31 -> V_108 [ 0 ] . V_77 = F_44 ( V_176 , & V_177 , & V_2 -> V_93 ) ;
if ( V_31 -> V_108 [ 0 ] . V_77 == NULL )
return - V_29 ;
return 0 ;
}
static int F_77 ( struct V_61 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_62 ;
if ( F_20 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_21 ( L_8 ) ;
F_75 ( V_2 -> V_38 ,
F_76 ( V_2 -> V_38 , V_2 -> V_68 . V_69 ) ) ;
F_75 ( V_2 -> V_38 ,
F_30 ( V_2 -> V_38 , V_2 -> V_68 . V_69 ) ) ;
F_75 ( V_2 -> V_38 ,
F_30 ( V_2 -> V_38 , V_2 -> V_68 . V_52 [ 0 ] . V_77 [ 0 ] . V_78 . V_82 ) ) ;
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
V_31 -> V_108 [ 0 ] . V_77 = F_44 ( V_178 , & V_179 ,
& V_2 -> V_93 ) ;
if ( V_31 -> V_108 [ 0 ] . V_77 == NULL )
return - V_29 ;
return 0 ;
}
static int F_78 ( struct V_180 * V_38 ,
struct V_181 * V_68 ,
struct V_182 * * V_183 ,
int * V_184 )
{
int V_185 = * V_184 ;
* V_184 = V_38 -> V_39 . V_186 == 0xff &&
V_38 -> V_39 . V_187 == 0xff &&
V_38 -> V_39 . V_188 == 0xff ;
if ( * V_184 && ! V_185 )
* V_183 = NULL ;
return 0 ;
}
static int F_79 ( struct V_180 * V_38 ,
const struct V_189 * V_190 )
{
int V_191 ;
for ( V_191 = 0 ; V_191 < F_80 ( V_192 ) ; V_191 ++ ) {
int V_193 = V_192 [ V_191 ] ;
if ( V_190 -> V_194 < V_193 + 4 )
continue;
if ( V_190 -> V_195 [ V_193 ] == ( V_196 & 0xff ) &&
V_190 -> V_195 [ V_193 + 1 ] == V_196 >> 8 ) {
struct V_189 V_197 ;
T_1 * V_198 = F_81 ( V_190 -> V_194 ) ;
int V_35 ;
if ( ! V_198 )
return - V_199 ;
memcpy ( V_198 , V_190 -> V_195 , V_190 -> V_194 ) ;
V_197 . V_194 = V_190 -> V_194 ;
V_197 . V_195 = V_198 ;
V_198 [ V_193 + 2 ] =
F_82 ( V_38 -> V_39 . V_200 ) + 1 ;
V_198 [ V_193 + 3 ] =
F_82 ( V_38 -> V_39 . V_200 ) >> 8 ;
V_35 = F_83 ( V_38 , & V_197 ,
V_201 ) ;
F_84 ( V_198 ) ;
return V_35 ;
}
}
return - V_121 ;
}
static int F_85 ( struct V_202 * V_203 ,
const struct V_204 * V_205 )
{
if ( 0 == F_86 ( V_203 , & V_206 ,
V_207 , NULL , V_208 ) ||
0 == F_86 ( V_203 , & V_209 ,
V_207 , NULL , V_208 ) ||
0 == F_86 ( V_203 , & V_210 ,
V_207 , NULL , V_208 ) ||
0 == F_86 ( V_203 , & V_211 ,
V_207 , NULL , V_208 ) ||
0 == F_86 ( V_203 , & V_212 ,
V_207 , NULL , V_208 ) ||
0 == F_86 ( V_203 , & V_213 ,
V_207 , NULL , V_208 ) ||
0 == F_86 ( V_203 , & V_214 ,
V_207 , NULL , V_208 ) ||
0 == F_86 ( V_203 ,
& V_215 ,
V_207 , NULL , V_208 ) ||
0 == F_86 ( V_203 , & V_216 ,
V_207 , NULL , V_208 ) ||
0 == F_86 ( V_203 ,
& V_217 ,
V_207 , NULL , V_208 ) ||
0 == F_86 ( V_203 , & V_218 ,
V_207 , NULL , V_208 ) ||
0 == F_86 ( V_203 , & V_219 ,
V_207 , NULL , V_208 ) ||
0 )
return 0 ;
return - V_121 ;
}
