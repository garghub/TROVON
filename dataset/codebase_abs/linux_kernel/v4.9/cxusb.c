static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 , V_12 ;
if ( 1 + V_5 > V_13 ) {
F_2 ( L_1 , V_5 ) ;
return - V_14 ;
}
V_12 = ( V_6 == NULL || V_7 == 0 ) ;
F_3 ( & V_2 -> V_15 ) ;
V_9 -> V_16 [ 0 ] = V_3 ;
memcpy ( & V_9 -> V_16 [ 1 ] , V_4 , V_5 ) ;
if ( V_12 )
V_11 = F_4 ( V_2 , V_9 -> V_16 , 1 + V_5 ) ;
else
V_11 = F_5 ( V_2 , V_9 -> V_16 , 1 + V_5 ,
V_6 , V_7 , 0 ) ;
F_6 ( & V_2 -> V_15 ) ;
return V_11 ;
}
static void F_7 ( struct V_1 * V_2 , int V_17 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_1 V_18 [ 2 ] , V_19 ;
if ( V_9 -> V_20 [ V_21 ] == V_17 )
return;
V_18 [ 0 ] = V_21 ;
V_18 [ 1 ] = V_17 ;
F_1 ( V_2 , V_22 , V_18 , 2 , & V_19 , 1 ) ;
if ( V_19 != 0x01 )
F_8 ( L_2 ) ;
V_9 -> V_20 [ V_21 ] = V_17 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_23 ,
T_1 V_24 )
{
T_1 V_18 [ 2 ] , V_25 ;
int V_26 ;
V_18 [ 0 ] = 0xff & ~ V_23 ;
V_18 [ 1 ] = V_24 & V_23 ;
V_26 = F_1 ( V_2 , V_27 , V_18 , 2 , & V_25 , 1 ) ;
if ( V_26 < 0 || ( V_25 & V_23 ) != ( V_24 & V_23 ) )
F_8 ( L_3 ) ;
return V_26 < 0 ? V_26 : V_25 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_28 , int V_29 )
{
F_9 ( V_2 , V_28 , V_29 ? 0 : V_28 ) ;
F_11 ( 5 ) ;
F_9 ( V_2 , V_28 , V_29 ? V_28 : 0 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_17 )
{
F_9 ( V_2 , 0x40 , V_17 ? 0 : 0x40 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
T_1 V_30 , int V_17 )
{
T_1 V_18 [ 2 ] = { V_30 , V_17 } ;
T_1 V_19 ;
int V_26 ;
V_26 = F_1 ( V_2 , V_22 , V_18 , 2 , & V_19 , 1 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_19 == 0x01 )
return 0 ;
else {
F_8 ( L_2 ) ;
return - V_31 ;
}
}
static int F_14 ( struct V_32 * V_33 , struct V_34 V_35 [] ,
int V_36 )
{
struct V_1 * V_2 = F_15 ( V_33 ) ;
int V_11 ;
int V_19 ;
if ( F_16 ( & V_2 -> V_37 ) < 0 )
return - V_38 ;
for ( V_19 = 0 ; V_19 < V_36 ; V_19 ++ ) {
if ( F_17 ( V_2 -> V_39 -> V_40 . V_41 ) == V_42 )
switch ( V_35 [ V_19 ] . V_30 ) {
case 0x63 :
F_7 ( V_2 , 0 ) ;
break;
default:
F_7 ( V_2 , 1 ) ;
break;
}
if ( V_35 [ V_19 ] . V_43 & V_44 ) {
T_1 V_45 [ 3 ] , V_46 [ V_13 ] ;
if ( 1 + V_35 [ V_19 ] . V_47 > sizeof( V_46 ) ) {
F_2 ( L_4 ,
V_35 [ V_19 ] . V_47 ) ;
V_11 = - V_14 ;
goto V_48;
}
V_45 [ 0 ] = 0 ;
V_45 [ 1 ] = V_35 [ V_19 ] . V_47 ;
V_45 [ 2 ] = V_35 [ V_19 ] . V_30 ;
if ( F_1 ( V_2 , V_49 ,
V_45 , 3 ,
V_46 , 1 + V_35 [ V_19 ] . V_47 ) < 0 ) {
F_2 ( L_5 ) ;
break;
}
memcpy ( V_35 [ V_19 ] . V_50 , & V_46 [ 1 ] , V_35 [ V_19 ] . V_47 ) ;
} else if ( V_19 + 1 < V_36 && ( V_35 [ V_19 + 1 ] . V_43 & V_44 ) &&
V_35 [ V_19 ] . V_30 == V_35 [ V_19 + 1 ] . V_30 ) {
T_1 V_45 [ V_13 ] , V_46 [ V_13 ] ;
if ( 3 + V_35 [ V_19 ] . V_47 > sizeof( V_45 ) ) {
F_2 ( L_1 ,
V_35 [ V_19 ] . V_47 ) ;
V_11 = - V_14 ;
goto V_48;
}
if ( 1 + V_35 [ V_19 + 1 ] . V_47 > sizeof( V_46 ) ) {
F_2 ( L_4 ,
V_35 [ V_19 + 1 ] . V_47 ) ;
V_11 = - V_14 ;
goto V_48;
}
V_45 [ 0 ] = V_35 [ V_19 ] . V_47 ;
V_45 [ 1 ] = V_35 [ V_19 + 1 ] . V_47 ;
V_45 [ 2 ] = V_35 [ V_19 ] . V_30 ;
memcpy ( & V_45 [ 3 ] , V_35 [ V_19 ] . V_50 , V_35 [ V_19 ] . V_47 ) ;
if ( F_1 ( V_2 , V_49 ,
V_45 , 3 + V_35 [ V_19 ] . V_47 ,
V_46 , 1 + V_35 [ V_19 + 1 ] . V_47 ) < 0 )
break;
if ( V_46 [ 0 ] != 0x08 )
F_18 ( L_6 ) ;
memcpy ( V_35 [ V_19 + 1 ] . V_50 , & V_46 [ 1 ] , V_35 [ V_19 + 1 ] . V_47 ) ;
V_19 ++ ;
} else {
T_1 V_45 [ V_13 ] , V_46 ;
if ( 2 + V_35 [ V_19 ] . V_47 > sizeof( V_45 ) ) {
F_2 ( L_1 ,
V_35 [ V_19 ] . V_47 ) ;
V_11 = - V_14 ;
goto V_48;
}
V_45 [ 0 ] = V_35 [ V_19 ] . V_30 ;
V_45 [ 1 ] = V_35 [ V_19 ] . V_47 ;
memcpy ( & V_45 [ 2 ] , V_35 [ V_19 ] . V_50 , V_35 [ V_19 ] . V_47 ) ;
if ( F_1 ( V_2 , V_51 , V_45 ,
2 + V_35 [ V_19 ] . V_47 , & V_46 , 1 ) < 0 )
break;
if ( V_46 != 0x08 )
F_18 ( L_7 ) ;
}
}
if ( V_19 == V_36 )
V_11 = V_36 ;
else
V_11 = - V_52 ;
V_48:
F_6 ( & V_2 -> V_37 ) ;
return V_11 ;
}
static T_2 F_19 ( struct V_32 * V_53 )
{
return V_54 ;
}
static int F_20 ( struct V_1 * V_2 , int V_17 )
{
T_1 V_55 = 0 ;
if ( V_17 )
return F_1 ( V_2 , V_56 , & V_55 , 1 , NULL , 0 ) ;
else
return F_1 ( V_2 , V_57 , & V_55 , 1 , NULL , 0 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_17 )
{
int V_11 ;
if ( ! V_17 )
return F_1 ( V_2 , V_57 , NULL , 0 , NULL , 0 ) ;
if ( V_2 -> V_58 == V_59 &&
F_22 ( V_2 -> V_39 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
do {} while ( ! ( V_11 = F_1 ( V_2 , V_56 , NULL , 0 , NULL , 0 ) ) &&
! ( V_11 = F_1 ( V_2 , 0x15 , NULL , 0 , NULL , 0 ) ) &&
! ( V_11 = F_1 ( V_2 , 0x17 , NULL , 0 , NULL , 0 ) ) && 0 );
if ( ! V_11 ) {
int V_19 ;
T_1 V_50 , V_60 [] = {
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
F_11 ( 20 ) ;
for ( V_19 = 0 ; V_19 < sizeof( V_60 ) / sizeof( T_1 ) ; V_19 += 4 / sizeof( T_1 ) ) {
V_11 = F_1 ( V_2 , V_51 ,
V_60 + V_19 , 4 , & V_50 , 1 ) ;
if ( V_11 )
break;
if ( V_50 != 0x8 )
return - V_52 ;
}
}
return V_11 ;
}
static int F_24 ( struct V_1 * V_2 , int V_17 )
{
T_1 V_55 = 0 ;
if ( V_17 )
return F_1 ( V_2 , V_56 , & V_55 , 1 , NULL , 0 ) ;
else
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , int V_17 )
{
int V_26 = 0 ;
V_26 = F_20 ( V_2 , V_17 ) ;
if ( ! V_17 )
F_12 ( V_2 , 0 ) ;
return V_26 ;
}
static int F_26 ( struct V_1 * V_2 , int V_17 )
{
int V_11 ;
T_1 V_55 ;
V_11 = F_20 ( V_2 , V_17 ) ;
if ( ! V_17 )
return V_11 ;
F_11 ( 128 ) ;
F_1 ( V_2 , V_61 , NULL , 0 , & V_55 , 1 ) ;
F_11 ( 100 ) ;
return V_11 ;
}
static int F_27 ( struct V_62 * V_33 , int V_17 )
{
T_1 V_50 [ 2 ] = { 0x03 , 0x00 } ;
if ( V_17 )
F_1 ( V_33 -> V_63 , V_64 , V_50 , 2 , NULL , 0 ) ;
else
F_1 ( V_33 -> V_63 , V_65 , NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static int F_28 ( struct V_62 * V_33 , int V_17 )
{
if ( V_17 )
F_1 ( V_33 -> V_63 , V_66 , NULL , 0 , NULL , 0 ) ;
else
F_1 ( V_33 -> V_63 , V_67 ,
NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_68 = V_2 -> V_69 . V_70 ;
const int V_71 = 100 ;
const int V_72 = 32 ;
T_1 * V_73 ;
int V_74 ;
V_73 = F_30 ( V_72 , V_75 ) ;
if ( ! V_73 )
return;
while ( 1 ) {
if ( F_31 ( V_2 -> V_39 ,
F_32 ( V_2 -> V_39 , V_68 ) ,
V_73 , V_72 , & V_74 , V_71 ) < 0 )
break;
if ( ! V_74 )
break;
}
F_33 ( V_73 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = & V_2 -> V_69 . V_53 [ 0 ] . V_78 [ 0 ] . V_79 ;
const int V_71 = 100 ;
const int V_72 = V_77 -> V_80 . V_81 . V_82 ;
T_1 * V_73 ;
int V_74 ;
V_73 = F_30 ( V_72 , V_75 ) ;
if ( ! V_73 )
return;
while ( 1 ) {
if ( F_31 ( V_2 -> V_39 ,
F_32 ( V_2 -> V_39 , V_77 -> V_83 ) ,
V_73 , V_72 , & V_74 , V_71 ) < 0 )
break;
if ( ! V_74 )
break;
}
F_33 ( V_73 ) ;
}
static int F_35 (
struct V_62 * V_33 , int V_17 )
{
if ( V_17 ) {
T_1 V_50 [ 2 ] = { 0x03 , 0x00 } ;
F_34 ( V_33 -> V_63 ) ;
return F_1 ( V_33 -> V_63 , V_64 ,
V_50 , sizeof( V_50 ) , NULL , 0 ) ;
} else {
int V_11 = F_1 ( V_33 -> V_63 ,
V_65 , NULL , 0 , NULL , 0 ) ;
return V_11 ;
}
}
static int F_36 ( struct V_1 * V_2 , T_2 * V_84 , int * V_58 )
{
struct V_85 * V_86 = V_2 -> V_69 . V_26 . V_87 . V_85 ;
T_1 V_88 [ 4 ] ;
int V_19 ;
F_1 ( V_2 , V_89 , NULL , 0 , V_88 , 4 ) ;
* V_84 = 0 ;
* V_58 = V_90 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_69 . V_26 . V_87 . V_91 ; V_19 ++ ) {
if ( F_37 ( & V_86 [ V_19 ] ) == V_88 [ 2 ] &&
F_38 ( & V_86 [ V_19 ] ) == V_88 [ 3 ] ) {
* V_84 = V_86 [ V_19 ] . V_92 ;
* V_58 = V_93 ;
return 0 ;
}
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_2 * V_84 ,
int * V_58 )
{
struct V_85 * V_86 = V_2 -> V_69 . V_26 . V_87 . V_85 ;
T_1 V_88 [ 4 ] ;
int V_19 ;
struct V_34 V_35 = { . V_30 = 0x6b , . V_43 = V_44 ,
. V_50 = V_88 , . V_47 = 4 } ;
* V_84 = 0 ;
* V_58 = V_90 ;
if ( F_14 ( & V_2 -> V_94 , & V_35 , 1 ) != 1 )
return 0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_69 . V_26 . V_87 . V_91 ; V_19 ++ ) {
if ( F_37 ( & V_86 [ V_19 ] ) == V_88 [ 1 ] &&
F_38 ( & V_86 [ V_19 ] ) == V_88 [ 2 ] ) {
* V_84 = V_86 [ V_19 ] . V_92 ;
* V_58 = V_93 ;
return 0 ;
}
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , T_2 * V_84 ,
int * V_58 )
{
struct V_85 * V_86 = V_2 -> V_69 . V_26 . V_87 . V_85 ;
T_1 V_88 [ 2 ] ;
int V_19 ;
* V_84 = 0 ;
* V_58 = V_90 ;
if ( F_1 ( V_2 , 0x10 , NULL , 0 , V_88 , 2 ) < 0 )
return 0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_69 . V_26 . V_87 . V_91 ; V_19 ++ ) {
if ( F_37 ( & V_86 [ V_19 ] ) == V_88 [ 0 ] &&
F_38 ( & V_86 [ V_19 ] ) == V_88 [ 1 ] ) {
* V_84 = V_86 [ V_19 ] . V_92 ;
* V_58 = V_93 ;
return 0 ;
}
}
return 0 ;
}
static int F_41 ( struct V_95 * V_78 )
{
static T_1 V_96 [] = { V_97 , 0x38 , 0x28 } ;
static T_1 V_98 [] = { V_99 , 0x80 } ;
static T_1 V_100 [] = { V_101 , 0x40 } ;
static T_1 V_102 [] = { V_103 , 0x28 , 0x20 } ;
static T_1 V_104 [] = { V_105 , 0x33 } ;
static T_1 V_106 [] = { V_107 , 0x32 } ;
F_42 ( V_78 , V_96 , sizeof( V_96 ) ) ;
F_43 ( 200 ) ;
F_42 ( V_78 , V_98 , sizeof( V_98 ) ) ;
F_42 ( V_78 , V_100 , sizeof( V_100 ) ) ;
F_42 ( V_78 , V_102 , sizeof( V_102 ) ) ;
F_42 ( V_78 , V_104 , sizeof( V_104 ) ) ;
F_42 ( V_78 , V_106 , sizeof( V_106 ) ) ;
return 0 ;
}
static int F_44 ( struct V_95 * V_78 )
{
static T_1 V_96 [] = { V_97 , 0x38 , 0x29 } ;
static T_1 V_98 [] = { V_99 , 0x80 } ;
static T_1 V_100 [] = { V_101 , 0x40 } ;
static T_1 V_102 [] = { V_103 , 0x24 , 0x20 } ;
static T_1 V_104 [] = { V_105 , 0x33 } ;
static T_1 V_106 [] = { V_107 , 0x32 } ;
F_42 ( V_78 , V_96 , sizeof( V_96 ) ) ;
F_43 ( 200 ) ;
F_42 ( V_78 , V_98 , sizeof( V_98 ) ) ;
F_42 ( V_78 , V_100 , sizeof( V_100 ) ) ;
F_42 ( V_78 , V_102 , sizeof( V_102 ) ) ;
F_42 ( V_78 , V_104 , sizeof( V_104 ) ) ;
F_42 ( V_78 , V_106 , sizeof( V_106 ) ) ;
return 0 ;
}
static int F_45 ( struct V_62 * V_33 )
{
F_46 ( V_108 , V_33 -> V_109 [ 0 ] . V_78 ,
& V_33 -> V_63 -> V_94 , 0x61 ,
V_110 ) ;
return 0 ;
}
static int F_47 ( struct V_62 * V_33 )
{
F_46 ( V_111 , V_33 -> V_109 [ 0 ] . V_78 , 0x61 ,
NULL , V_112 ) ;
return 0 ;
}
static int F_48 ( struct V_62 * V_33 )
{
F_46 ( V_111 , V_33 -> V_109 [ 0 ] . V_78 , 0x61 , NULL , V_113 ) ;
return 0 ;
}
static int F_49 ( struct V_62 * V_33 )
{
F_46 ( V_111 , V_33 -> V_109 [ 0 ] . V_78 , 0x60 ,
NULL , V_112 ) ;
return 0 ;
}
static int F_50 ( struct V_62 * V_33 )
{
F_46 ( V_108 , V_33 -> V_109 [ 0 ] . V_78 ,
& V_33 -> V_63 -> V_94 , 0x61 , V_114 ) ;
return 0 ;
}
static int F_51 ( void * V_115 , int V_116 ,
int V_117 , int V_118 )
{
struct V_62 * V_33 = V_115 ;
struct V_1 * V_2 = V_33 -> V_63 ;
switch ( V_117 ) {
case V_119 :
F_8 ( L_9 , V_120 , V_118 ) ;
F_10 ( V_2 , 0x01 , 1 ) ;
break;
case V_121 :
F_8 ( L_10 , V_120 , V_118 ) ;
break;
default:
F_8 ( L_11 , V_120 ,
V_117 , V_118 ) ;
return - V_122 ;
}
return 0 ;
}
static int F_52 ( struct V_62 * V_33 )
{
struct V_95 * V_78 ;
struct V_123 V_124 = {
. V_94 = & V_33 -> V_63 -> V_94 ,
. V_125 = 0x61 ,
} ;
static struct V_126 V_127 = {
. V_128 = V_129 ,
. V_130 = 64 ,
. V_131 = V_132 ,
} ;
V_33 -> V_109 [ 0 ] . V_78 -> V_133 = F_51 ;
V_78 = F_46 ( V_134 , V_33 -> V_109 [ 0 ] . V_78 , & V_124 ) ;
if ( V_78 == NULL || V_78 -> V_135 . V_136 . V_137 == NULL )
return - V_31 ;
V_78 -> V_135 . V_136 . V_137 ( V_78 , & V_127 ) ;
return 0 ;
}
static int F_53 ( struct V_62 * V_33 )
{
F_46 ( V_138 , V_33 -> V_109 [ 0 ] . V_78 ,
& V_33 -> V_63 -> V_94 , & V_139 ) ;
return 0 ;
}
static int F_54 ( struct V_62 * V_33 )
{
struct V_95 * V_78 ;
V_78 = F_46 ( V_138 , V_33 -> V_109 [ 0 ] . V_78 ,
& V_33 -> V_63 -> V_94 , & V_140 ) ;
return ( V_78 == NULL ) ? - V_31 : 0 ;
}
static int F_55 ( struct V_62 * V_33 )
{
struct V_95 * V_78 ;
V_78 = F_46 ( V_141 , V_33 -> V_109 [ 0 ] . V_78 ,
& V_33 -> V_63 -> V_94 , & V_142 ) ;
return ( V_78 == NULL ) ? - V_31 : 0 ;
}
static int F_56 ( struct V_62 * V_33 )
{
T_1 V_55 ;
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 6 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , & V_55 , 1 ) ;
V_33 -> V_109 [ 0 ] . V_78 = F_46 ( V_143 , & V_144 ,
& V_33 -> V_63 -> V_94 ) ;
if ( ( V_33 -> V_109 [ 0 ] . V_78 ) != NULL )
return 0 ;
return - V_31 ;
}
static int F_57 ( struct V_62 * V_33 )
{
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 7 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , NULL , 0 ) ;
V_33 -> V_109 [ 0 ] . V_78 = F_46 ( V_145 ,
& V_146 ,
& V_33 -> V_63 -> V_94 ) ;
if ( ( V_33 -> V_109 [ 0 ] . V_78 ) != NULL )
return 0 ;
return - V_31 ;
}
static int F_58 ( struct V_62 * V_33 )
{
V_33 -> V_109 [ 0 ] . V_78 = F_46 ( V_145 , & V_147 ,
& V_33 -> V_63 -> V_94 ) ;
if ( V_33 -> V_109 [ 0 ] . V_78 != NULL )
return 0 ;
return - V_31 ;
}
static int F_59 ( struct V_62 * V_33 )
{
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , NULL , 0 ) ;
V_33 -> V_109 [ 0 ] . V_78 = F_46 ( V_148 , & V_149 ,
& V_33 -> V_63 -> V_94 ) ;
if ( ( V_33 -> V_109 [ 0 ] . V_78 ) != NULL )
return 0 ;
return - V_31 ;
}
static int F_60 ( struct V_62 * V_33 )
{
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , NULL , 0 ) ;
V_33 -> V_109 [ 0 ] . V_78 = F_46 ( V_148 , & V_150 ,
& V_33 -> V_63 -> V_94 ) ;
if ( ( V_33 -> V_109 [ 0 ] . V_78 ) != NULL )
return 0 ;
V_33 -> V_109 [ 0 ] . V_78 = F_46 ( V_151 ,
& V_152 ,
& V_33 -> V_63 -> V_94 ) ;
if ( ( V_33 -> V_109 [ 0 ] . V_78 ) != NULL )
return 0 ;
return - V_31 ;
}
static int F_61 ( struct V_62 * V_33 )
{
T_1 V_88 [ 4 ] ;
int V_19 ;
struct V_34 V_35 = { . V_30 = 0x6b , . V_43 = V_44 ,
. V_50 = V_88 , . V_47 = 4 } ;
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 1 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , NULL , 0 ) ;
F_9 ( V_33 -> V_63 , 0x04 , 0 ) ;
F_10 ( V_33 -> V_63 , 0x01 , 1 ) ;
F_10 ( V_33 -> V_63 , 0x02 , 1 ) ;
V_33 -> V_109 [ 0 ] . V_78 =
F_46 ( V_151 ,
& V_153 ,
& V_33 -> V_63 -> V_94 ) ;
if ( ( V_33 -> V_109 [ 0 ] . V_78 ) == NULL )
return - V_31 ;
for ( V_19 = 0 ; V_33 -> V_63 -> V_69 . V_26 . V_87 . V_85 != NULL && V_19 < 5 ; V_19 ++ ) {
F_11 ( 20 ) ;
if ( F_14 ( & V_33 -> V_63 -> V_94 , & V_35 , 1 ) != 1 )
goto V_154;
if ( V_88 [ 0 ] == 0 && V_88 [ 1 ] == 0 )
continue;
if ( V_88 [ 2 ] + V_88 [ 3 ] != 0xff ) {
V_154:
V_33 -> V_63 -> V_69 . V_26 . V_87 . V_85 = NULL ;
F_62 ( L_12 ) ;
break;
}
}
return 0 ;
}
static int F_63 ( struct V_62 * V_33 )
{
struct V_155 * V_58 = V_33 -> V_10 ;
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 1 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , NULL , 0 ) ;
F_10 ( V_33 -> V_63 , 0x02 , 1 ) ;
if ( ! F_46 ( V_156 , & V_58 -> V_157 ) )
return - V_158 ;
if ( V_58 -> V_157 . V_159 ( & V_33 -> V_63 -> V_94 , 1 , 18 ,
& V_160 ) < 0 ) {
F_64 ( V_161 L_13 ) ;
return - V_158 ;
}
V_33 -> V_109 [ 0 ] . V_78 = V_58 -> V_157 . V_162 ( & V_33 -> V_63 -> V_94 , 0x80 ,
& V_160 ) ;
if ( V_33 -> V_109 [ 0 ] . V_78 == NULL )
return - V_31 ;
return 0 ;
}
static int F_65 ( struct V_95 * V_78 , int V_17 )
{
struct V_62 * V_33 = V_78 -> V_163 -> V_10 ;
struct V_155 * V_58 = V_33 -> V_10 ;
return V_58 -> V_157 . V_164 ( V_78 , 8 , 0 , ! V_17 ) ;
}
static int F_66 ( struct V_95 * V_78 , int V_17 )
{
return 0 ;
}
static int F_67 ( struct V_95 * V_78 )
{
struct V_165 * V_77 = & V_78 -> V_166 ;
struct V_62 * V_33 = V_78 -> V_163 -> V_10 ;
struct V_155 * V_58 = V_33 -> V_10 ;
T_3 V_167 ;
T_1 V_168 = F_68 ( V_77 -> V_169 / 1000 ) ;
switch ( V_168 ) {
case V_170 : V_167 = 950 ; break;
default:
case V_171 : V_167 = 550 ; break;
}
V_58 -> V_157 . V_172 ( V_78 , V_167 + F_69 ( V_78 ) ) ;
return V_58 -> V_173 ( V_78 ) ;
}
static int F_70 ( struct V_62 * V_33 )
{
struct V_155 * V_9 = V_33 -> V_10 ;
struct V_32 * V_174 ;
V_174 = V_9 -> V_157 . V_175 ( V_33 -> V_109 [ 0 ] . V_78 ,
V_176 , 1 ) ;
if ( F_46 ( V_177 , V_33 -> V_109 [ 0 ] . V_78 , V_174 ,
& V_178 ) == NULL )
return - V_158 ;
V_9 -> V_173 = V_33 -> V_109 [ 0 ] . V_78 -> V_135 . V_136 . V_179 ;
V_33 -> V_109 [ 0 ] . V_78 -> V_135 . V_136 . V_179 = F_67 ;
return 0 ;
}
static int F_71 ( struct V_62 * V_33 )
{
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 1 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , NULL , 0 ) ;
F_9 ( V_33 -> V_63 , 0x04 , 0 ) ;
F_10 ( V_33 -> V_63 , 0x01 , 1 ) ;
F_10 ( V_33 -> V_63 , 0x02 , 1 ) ;
V_33 -> V_109 [ 0 ] . V_78 = F_46 ( V_151 ,
& V_180 ,
& V_33 -> V_63 -> V_94 ) ;
if ( ( V_33 -> V_109 [ 0 ] . V_78 ) != NULL )
return 0 ;
V_33 -> V_109 [ 0 ] . V_78 = F_46 ( V_148 ,
& V_181 ,
& V_33 -> V_63 -> V_94 ) ;
if ( ( V_33 -> V_109 [ 0 ] . V_78 ) != NULL )
return 0 ;
return - V_31 ;
}
static int F_72 ( struct V_62 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_63 ;
int V_182 ;
if ( F_22 ( V_2 -> V_39 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_73 ( V_2 -> V_39 ,
F_74 ( V_2 -> V_39 , V_2 -> V_69 . V_70 ) ) ;
F_73 ( V_2 -> V_39 ,
F_32 ( V_2 -> V_39 , V_2 -> V_69 . V_70 ) ) ;
F_73 ( V_2 -> V_39 ,
F_32 ( V_2 -> V_39 , V_2 -> V_69 . V_53 [ 0 ] . V_78 [ 0 ] . V_79 . V_83 ) ) ;
for ( V_182 = 0 ; V_182 < 5 ; V_182 ++ ) {
F_29 ( V_2 ) ;
F_34 ( V_2 ) ;
F_11 ( 200 ) ;
}
if ( F_13 ( V_2 , 0x07 , 0 ) < 0 ) {
F_23 ( L_14 ) ;
return - V_31 ;
}
F_11 ( 100 ) ;
if ( F_13 ( V_2 , 0x07 , 1 ) < 0 ) {
F_23 ( L_15 ) ;
return - V_31 ;
}
F_11 ( 100 ) ;
V_33 -> V_109 [ 0 ] . V_78 = F_46 ( V_183 , & V_184 , & V_2 -> V_94 ) ;
if ( V_33 -> V_109 [ 0 ] . V_78 == NULL )
return - V_31 ;
return 0 ;
}
static int F_75 ( struct V_62 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_63 ;
if ( F_22 ( V_2 -> V_39 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_73 ( V_2 -> V_39 ,
F_74 ( V_2 -> V_39 , V_2 -> V_69 . V_70 ) ) ;
F_73 ( V_2 -> V_39 ,
F_32 ( V_2 -> V_39 , V_2 -> V_69 . V_70 ) ) ;
F_73 ( V_2 -> V_39 ,
F_32 ( V_2 -> V_39 , V_2 -> V_69 . V_53 [ 0 ] . V_78 [ 0 ] . V_79 . V_83 ) ) ;
if ( F_13 ( V_2 , 0x07 , 0 ) < 0 ) {
F_23 ( L_14 ) ;
return - V_31 ;
}
F_11 ( 100 ) ;
if ( F_13 ( V_2 , 0x07 , 1 ) < 0 ) {
F_23 ( L_15 ) ;
return - V_31 ;
}
F_11 ( 100 ) ;
V_33 -> V_109 [ 0 ] . V_78 = F_46 ( V_185 , & V_186 ,
& V_2 -> V_94 ) ;
if ( V_33 -> V_109 [ 0 ] . V_78 == NULL )
return - V_31 ;
return 0 ;
}
static int F_76 ( struct V_62 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_63 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_32 * V_53 ;
struct V_187 * V_188 ;
struct V_187 * V_189 ;
struct V_190 F_62 ;
struct V_191 V_191 ;
struct V_192 V_192 ;
if ( F_22 ( V_2 -> V_39 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_73 ( V_2 -> V_39 ,
F_74 ( V_2 -> V_39 , V_2 -> V_69 . V_70 ) ) ;
F_73 ( V_2 -> V_39 ,
F_32 ( V_2 -> V_39 , V_2 -> V_69 . V_70 ) ) ;
F_73 ( V_2 -> V_39 ,
F_32 ( V_2 -> V_39 , V_2 -> V_69 . V_53 [ 0 ] . V_78 [ 0 ] . V_79 . V_83 ) ) ;
V_191 . V_32 = & V_53 ;
V_191 . V_78 = & V_33 -> V_109 [ 0 ] . V_78 ;
V_191 . V_193 = V_194 ;
V_191 . V_195 = 1 ;
memset ( & F_62 , 0 , sizeof( struct V_190 ) ) ;
F_77 ( F_62 . type , L_16 , V_196 ) ;
F_62 . V_30 = 0x64 ;
F_62 . V_197 = & V_191 ;
F_78 ( F_62 . type ) ;
V_188 = F_79 ( & V_2 -> V_94 , & F_62 ) ;
if ( V_188 == NULL || V_188 -> V_63 . V_198 == NULL )
return - V_158 ;
if ( ! F_80 ( V_188 -> V_63 . V_198 -> V_199 ) ) {
F_81 ( V_188 ) ;
return - V_158 ;
}
V_9 -> V_200 = V_188 ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
V_192 . V_78 = V_33 -> V_109 [ 0 ] . V_78 ;
V_192 . V_201 = 1 ;
memset ( & F_62 , 0 , sizeof( struct V_190 ) ) ;
F_77 ( F_62 . type , L_17 , V_196 ) ;
F_62 . V_30 = 0x60 ;
F_62 . V_197 = & V_192 ;
F_78 ( F_62 . type ) ;
V_189 = F_79 ( V_53 , & F_62 ) ;
if ( V_189 == NULL || V_189 -> V_63 . V_198 == NULL ) {
F_82 ( V_188 -> V_63 . V_198 -> V_199 ) ;
F_81 ( V_188 ) ;
return - V_158 ;
}
if ( ! F_80 ( V_189 -> V_63 . V_198 -> V_199 ) ) {
F_81 ( V_189 ) ;
F_82 ( V_188 -> V_63 . V_198 -> V_199 ) ;
F_81 ( V_188 ) ;
return - V_158 ;
}
V_9 -> V_202 = V_189 ;
return 0 ;
}
static int F_83 ( struct V_203 * V_39 ,
struct V_204 * V_69 ,
struct V_205 * * V_206 ,
int * V_207 )
{
int V_208 = * V_207 ;
* V_207 = V_39 -> V_40 . V_209 == 0xff &&
V_39 -> V_40 . V_210 == 0xff &&
V_39 -> V_40 . V_211 == 0xff ;
if ( * V_207 && ! V_208 )
* V_206 = NULL ;
return 0 ;
}
static int F_84 ( struct V_203 * V_39 ,
const struct V_212 * V_213 )
{
int V_214 ;
for ( V_214 = 0 ; V_214 < F_85 ( V_215 ) ; V_214 ++ ) {
int V_216 = V_215 [ V_214 ] ;
if ( V_213 -> V_217 < V_216 + 4 )
continue;
if ( V_213 -> V_16 [ V_216 ] == ( V_218 & 0xff ) &&
V_213 -> V_16 [ V_216 + 1 ] == V_218 >> 8 ) {
struct V_212 V_219 ;
T_1 * V_220 = F_86 ( V_213 -> V_217 ) ;
int V_11 ;
if ( ! V_220 )
return - V_221 ;
memcpy ( V_220 , V_213 -> V_16 , V_213 -> V_217 ) ;
V_219 . V_217 = V_213 -> V_217 ;
V_219 . V_16 = V_220 ;
V_220 [ V_216 + 2 ] =
F_17 ( V_39 -> V_40 . V_222 ) + 1 ;
V_220 [ V_216 + 3 ] =
F_17 ( V_39 -> V_40 . V_222 ) >> 8 ;
V_11 = F_87 ( V_39 , & V_219 ,
V_223 ) ;
F_88 ( V_220 ) ;
return V_11 ;
}
}
return - V_122 ;
}
static int F_89 ( struct V_224 * V_225 ,
const struct V_226 * V_227 )
{
if ( 0 == F_90 ( V_225 , & V_228 ,
V_229 , NULL , V_230 ) ||
0 == F_90 ( V_225 , & V_231 ,
V_229 , NULL , V_230 ) ||
0 == F_90 ( V_225 , & V_232 ,
V_229 , NULL , V_230 ) ||
0 == F_90 ( V_225 , & V_233 ,
V_229 , NULL , V_230 ) ||
0 == F_90 ( V_225 , & V_234 ,
V_229 , NULL , V_230 ) ||
0 == F_90 ( V_225 , & V_235 ,
V_229 , NULL , V_230 ) ||
0 == F_90 ( V_225 , & V_236 ,
V_229 , NULL , V_230 ) ||
0 == F_90 ( V_225 ,
& V_237 ,
V_229 , NULL , V_230 ) ||
0 == F_90 ( V_225 , & V_238 ,
V_229 , NULL , V_230 ) ||
0 == F_90 ( V_225 ,
& V_239 ,
V_229 , NULL , V_230 ) ||
0 == F_90 ( V_225 , & V_240 ,
V_229 , NULL , V_230 ) ||
0 == F_90 ( V_225 , & V_241 ,
V_229 , NULL , V_230 ) ||
0 == F_90 ( V_225 , & V_242 ,
V_229 , NULL , V_230 ) ||
0 )
return 0 ;
return - V_122 ;
}
static void F_91 ( struct V_224 * V_225 )
{
struct V_1 * V_2 = F_92 ( V_225 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_187 * V_243 ;
V_243 = V_9 -> V_202 ;
if ( V_243 ) {
F_82 ( V_243 -> V_63 . V_198 -> V_199 ) ;
F_81 ( V_243 ) ;
}
V_243 = V_9 -> V_200 ;
if ( V_243 ) {
F_82 ( V_243 -> V_63 . V_198 -> V_199 ) ;
F_81 ( V_243 ) ;
}
F_93 ( V_225 ) ;
}
