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
static int F_29 ( struct V_68 * V_69 ,
enum V_70 * V_71 )
{
struct V_62 * V_33 = (struct V_62 * ) V_69 -> V_72 -> V_10 ;
struct V_8 * V_58 = (struct V_8 * ) V_33 -> V_63 -> V_10 ;
int V_11 ;
V_11 = V_58 -> V_73 ( V_69 , V_71 ) ;
if ( ( * V_71 & V_74 ) && ( ! V_58 -> V_75 ) ) {
F_3 ( & V_58 -> V_76 ) ;
F_27 ( V_33 , 1 ) ;
F_6 ( & V_58 -> V_76 ) ;
}
V_58 -> V_75 = ( * V_71 & V_74 ) ? 1 : 0 ;
return V_11 ;
}
static void F_30 ( struct V_1 * V_2 )
{
int V_77 = V_2 -> V_78 . V_79 ;
const int V_80 = 100 ;
const int V_81 = 32 ;
T_1 * V_82 ;
int V_83 ;
V_82 = F_31 ( V_81 , V_84 ) ;
if ( ! V_82 )
return;
while ( 1 ) {
if ( F_32 ( V_2 -> V_39 ,
F_33 ( V_2 -> V_39 , V_77 ) ,
V_82 , V_81 , & V_83 , V_80 ) < 0 )
break;
if ( ! V_83 )
break;
}
F_34 ( V_82 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_85 * V_86 = & V_2 -> V_78 . V_53 [ 0 ] . V_69 [ 0 ] . V_87 ;
const int V_80 = 100 ;
const int V_81 = V_86 -> V_88 . V_89 . V_90 ;
T_1 * V_82 ;
int V_83 ;
V_82 = F_31 ( V_81 , V_84 ) ;
if ( ! V_82 )
return;
while ( 1 ) {
if ( F_32 ( V_2 -> V_39 ,
F_33 ( V_2 -> V_39 , V_86 -> V_91 ) ,
V_82 , V_81 , & V_83 , V_80 ) < 0 )
break;
if ( ! V_83 )
break;
}
F_34 ( V_82 ) ;
}
static int F_36 (
struct V_62 * V_33 , int V_17 )
{
if ( V_17 ) {
T_1 V_50 [ 2 ] = { 0x03 , 0x00 } ;
F_35 ( V_33 -> V_63 ) ;
return F_1 ( V_33 -> V_63 , V_64 ,
V_50 , sizeof( V_50 ) , NULL , 0 ) ;
} else {
int V_11 = F_1 ( V_33 -> V_63 ,
V_65 , NULL , 0 , NULL , 0 ) ;
return V_11 ;
}
}
static int F_37 ( struct V_1 * V_2 , T_2 * V_92 , int * V_58 )
{
struct V_93 * V_94 = V_2 -> V_78 . V_26 . V_95 . V_93 ;
T_1 V_96 [ 4 ] ;
int V_19 ;
F_1 ( V_2 , V_97 , NULL , 0 , V_96 , 4 ) ;
* V_92 = 0 ;
* V_58 = V_98 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_78 . V_26 . V_95 . V_99 ; V_19 ++ ) {
if ( F_38 ( & V_94 [ V_19 ] ) == V_96 [ 2 ] &&
F_39 ( & V_94 [ V_19 ] ) == V_96 [ 3 ] ) {
* V_92 = V_94 [ V_19 ] . V_100 ;
* V_58 = V_101 ;
return 0 ;
}
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , T_2 * V_92 ,
int * V_58 )
{
struct V_93 * V_94 = V_2 -> V_78 . V_26 . V_95 . V_93 ;
T_1 V_96 [ 4 ] ;
int V_19 ;
struct V_34 V_35 = { . V_30 = 0x6b , . V_43 = V_44 ,
. V_50 = V_96 , . V_47 = 4 } ;
* V_92 = 0 ;
* V_58 = V_98 ;
if ( F_14 ( & V_2 -> V_102 , & V_35 , 1 ) != 1 )
return 0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_78 . V_26 . V_95 . V_99 ; V_19 ++ ) {
if ( F_38 ( & V_94 [ V_19 ] ) == V_96 [ 1 ] &&
F_39 ( & V_94 [ V_19 ] ) == V_96 [ 2 ] ) {
* V_92 = V_94 [ V_19 ] . V_100 ;
* V_58 = V_101 ;
return 0 ;
}
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , T_2 * V_92 ,
int * V_58 )
{
struct V_93 * V_94 = V_2 -> V_78 . V_26 . V_95 . V_93 ;
T_1 V_96 [ 2 ] ;
int V_19 ;
* V_92 = 0 ;
* V_58 = V_98 ;
if ( F_1 ( V_2 , 0x10 , NULL , 0 , V_96 , 2 ) < 0 )
return 0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_78 . V_26 . V_95 . V_99 ; V_19 ++ ) {
if ( F_38 ( & V_94 [ V_19 ] ) == V_96 [ 0 ] &&
F_39 ( & V_94 [ V_19 ] ) == V_96 [ 1 ] ) {
* V_92 = V_94 [ V_19 ] . V_100 ;
* V_58 = V_101 ;
return 0 ;
}
}
return 0 ;
}
static int F_42 ( struct V_68 * V_69 )
{
static T_1 V_103 [] = { V_104 , 0x38 , 0x28 } ;
static T_1 V_105 [] = { V_106 , 0x80 } ;
static T_1 V_107 [] = { V_108 , 0x40 } ;
static T_1 V_109 [] = { V_110 , 0x28 , 0x20 } ;
static T_1 V_111 [] = { V_112 , 0x33 } ;
static T_1 V_113 [] = { V_114 , 0x32 } ;
F_43 ( V_69 , V_103 , sizeof( V_103 ) ) ;
F_44 ( 200 ) ;
F_43 ( V_69 , V_105 , sizeof( V_105 ) ) ;
F_43 ( V_69 , V_107 , sizeof( V_107 ) ) ;
F_43 ( V_69 , V_109 , sizeof( V_109 ) ) ;
F_43 ( V_69 , V_111 , sizeof( V_111 ) ) ;
F_43 ( V_69 , V_113 , sizeof( V_113 ) ) ;
return 0 ;
}
static int F_45 ( struct V_68 * V_69 )
{
static T_1 V_103 [] = { V_104 , 0x38 , 0x29 } ;
static T_1 V_105 [] = { V_106 , 0x80 } ;
static T_1 V_107 [] = { V_108 , 0x40 } ;
static T_1 V_109 [] = { V_110 , 0x24 , 0x20 } ;
static T_1 V_111 [] = { V_112 , 0x33 } ;
static T_1 V_113 [] = { V_114 , 0x32 } ;
F_43 ( V_69 , V_103 , sizeof( V_103 ) ) ;
F_44 ( 200 ) ;
F_43 ( V_69 , V_105 , sizeof( V_105 ) ) ;
F_43 ( V_69 , V_107 , sizeof( V_107 ) ) ;
F_43 ( V_69 , V_109 , sizeof( V_109 ) ) ;
F_43 ( V_69 , V_111 , sizeof( V_111 ) ) ;
F_43 ( V_69 , V_113 , sizeof( V_113 ) ) ;
return 0 ;
}
static int F_46 ( struct V_62 * V_33 )
{
F_47 ( V_115 , V_33 -> V_116 [ 0 ] . V_69 ,
& V_33 -> V_63 -> V_102 , 0x61 ,
V_117 ) ;
return 0 ;
}
static int F_48 ( struct V_62 * V_33 )
{
F_47 ( V_118 , V_33 -> V_116 [ 0 ] . V_69 , 0x61 ,
NULL , V_119 ) ;
return 0 ;
}
static int F_49 ( struct V_62 * V_33 )
{
F_47 ( V_118 , V_33 -> V_116 [ 0 ] . V_69 , 0x61 , NULL , V_120 ) ;
return 0 ;
}
static int F_50 ( struct V_62 * V_33 )
{
F_47 ( V_118 , V_33 -> V_116 [ 0 ] . V_69 , 0x60 ,
NULL , V_119 ) ;
return 0 ;
}
static int F_51 ( struct V_62 * V_33 )
{
F_47 ( V_115 , V_33 -> V_116 [ 0 ] . V_69 ,
& V_33 -> V_63 -> V_102 , 0x61 , V_121 ) ;
return 0 ;
}
static int F_52 ( void * V_122 , int V_123 ,
int V_124 , int V_125 )
{
struct V_62 * V_33 = V_122 ;
struct V_1 * V_2 = V_33 -> V_63 ;
switch ( V_124 ) {
case V_126 :
F_8 ( L_9 , V_127 , V_125 ) ;
F_10 ( V_2 , 0x01 , 1 ) ;
break;
case V_128 :
F_8 ( L_10 , V_127 , V_125 ) ;
break;
default:
F_8 ( L_11 , V_127 ,
V_124 , V_125 ) ;
return - V_129 ;
}
return 0 ;
}
static int F_53 ( struct V_62 * V_33 )
{
struct V_68 * V_69 ;
struct V_130 V_131 = {
. V_102 = & V_33 -> V_63 -> V_102 ,
. V_132 = 0x61 ,
} ;
static struct V_133 V_134 = {
. V_135 = V_136 ,
. V_137 = 64 ,
. V_138 = V_139 ,
} ;
V_33 -> V_116 [ 0 ] . V_69 -> V_140 = F_52 ;
V_69 = F_47 ( V_141 , V_33 -> V_116 [ 0 ] . V_69 , & V_131 ) ;
if ( V_69 == NULL || V_69 -> V_142 . V_143 . V_144 == NULL )
return - V_31 ;
V_69 -> V_142 . V_143 . V_144 ( V_69 , & V_134 ) ;
return 0 ;
}
static int F_54 ( struct V_62 * V_33 )
{
F_47 ( V_145 , V_33 -> V_116 [ 0 ] . V_69 ,
& V_33 -> V_63 -> V_102 , & V_146 ) ;
return 0 ;
}
static int F_55 ( struct V_62 * V_33 )
{
struct V_68 * V_69 ;
V_69 = F_47 ( V_145 , V_33 -> V_116 [ 0 ] . V_69 ,
& V_33 -> V_63 -> V_102 , & V_147 ) ;
return ( V_69 == NULL ) ? - V_31 : 0 ;
}
static int F_56 ( struct V_62 * V_33 )
{
struct V_68 * V_69 ;
V_69 = F_47 ( V_148 , V_33 -> V_116 [ 0 ] . V_69 ,
& V_33 -> V_63 -> V_102 , & V_149 ) ;
return ( V_69 == NULL ) ? - V_31 : 0 ;
}
static int F_57 ( struct V_62 * V_33 )
{
T_1 V_55 ;
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 6 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , & V_55 , 1 ) ;
V_33 -> V_116 [ 0 ] . V_69 = F_47 ( V_150 , & V_151 ,
& V_33 -> V_63 -> V_102 ) ;
if ( ( V_33 -> V_116 [ 0 ] . V_69 ) != NULL )
return 0 ;
return - V_31 ;
}
static int F_58 ( struct V_62 * V_33 )
{
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 7 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , NULL , 0 ) ;
V_33 -> V_116 [ 0 ] . V_69 = F_47 ( V_152 ,
& V_153 ,
& V_33 -> V_63 -> V_102 ) ;
if ( ( V_33 -> V_116 [ 0 ] . V_69 ) != NULL )
return 0 ;
return - V_31 ;
}
static int F_59 ( struct V_62 * V_33 )
{
V_33 -> V_116 [ 0 ] . V_69 = F_47 ( V_152 , & V_154 ,
& V_33 -> V_63 -> V_102 ) ;
if ( V_33 -> V_116 [ 0 ] . V_69 != NULL )
return 0 ;
return - V_31 ;
}
static int F_60 ( struct V_62 * V_33 )
{
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , NULL , 0 ) ;
V_33 -> V_116 [ 0 ] . V_69 = F_47 ( V_155 , & V_156 ,
& V_33 -> V_63 -> V_102 ) ;
if ( ( V_33 -> V_116 [ 0 ] . V_69 ) != NULL )
return 0 ;
return - V_31 ;
}
static int F_61 ( struct V_62 * V_33 )
{
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , NULL , 0 ) ;
V_33 -> V_116 [ 0 ] . V_69 = F_47 ( V_155 , & V_157 ,
& V_33 -> V_63 -> V_102 ) ;
if ( ( V_33 -> V_116 [ 0 ] . V_69 ) != NULL )
return 0 ;
V_33 -> V_116 [ 0 ] . V_69 = F_47 ( V_158 ,
& V_159 ,
& V_33 -> V_63 -> V_102 ) ;
if ( ( V_33 -> V_116 [ 0 ] . V_69 ) != NULL )
return 0 ;
return - V_31 ;
}
static int F_62 ( struct V_62 * V_33 )
{
T_1 V_96 [ 4 ] ;
int V_19 ;
struct V_34 V_35 = { . V_30 = 0x6b , . V_43 = V_44 ,
. V_50 = V_96 , . V_47 = 4 } ;
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 1 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , NULL , 0 ) ;
F_9 ( V_33 -> V_63 , 0x04 , 0 ) ;
F_10 ( V_33 -> V_63 , 0x01 , 1 ) ;
F_10 ( V_33 -> V_63 , 0x02 , 1 ) ;
V_33 -> V_116 [ 0 ] . V_69 =
F_47 ( V_158 ,
& V_160 ,
& V_33 -> V_63 -> V_102 ) ;
if ( ( V_33 -> V_116 [ 0 ] . V_69 ) == NULL )
return - V_31 ;
for ( V_19 = 0 ; V_33 -> V_63 -> V_78 . V_26 . V_95 . V_93 != NULL && V_19 < 5 ; V_19 ++ ) {
F_11 ( 20 ) ;
if ( F_14 ( & V_33 -> V_63 -> V_102 , & V_35 , 1 ) != 1 )
goto V_161;
if ( V_96 [ 0 ] == 0 && V_96 [ 1 ] == 0 )
continue;
if ( V_96 [ 2 ] + V_96 [ 3 ] != 0xff ) {
V_161:
V_33 -> V_63 -> V_78 . V_26 . V_95 . V_93 = NULL ;
F_63 ( L_12 ) ;
break;
}
}
return 0 ;
}
static int F_64 ( struct V_62 * V_33 )
{
struct V_162 * V_58 = V_33 -> V_10 ;
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 1 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , NULL , 0 ) ;
F_10 ( V_33 -> V_63 , 0x02 , 1 ) ;
if ( ! F_47 ( V_163 , & V_58 -> V_164 ) )
return - V_165 ;
if ( V_58 -> V_164 . V_166 ( & V_33 -> V_63 -> V_102 , 1 , 18 ,
& V_167 ) < 0 ) {
F_65 ( V_168 L_13 ) ;
return - V_165 ;
}
V_33 -> V_116 [ 0 ] . V_69 = V_58 -> V_164 . V_169 ( & V_33 -> V_63 -> V_102 , 0x80 ,
& V_167 ) ;
if ( V_33 -> V_116 [ 0 ] . V_69 == NULL )
return - V_31 ;
return 0 ;
}
static int F_66 ( struct V_68 * V_69 , int V_17 )
{
struct V_62 * V_33 = V_69 -> V_72 -> V_10 ;
struct V_162 * V_58 = V_33 -> V_10 ;
return V_58 -> V_164 . V_170 ( V_69 , 8 , 0 , ! V_17 ) ;
}
static int F_67 ( struct V_68 * V_69 , int V_17 )
{
return 0 ;
}
static int F_68 ( struct V_68 * V_69 )
{
struct V_171 * V_86 = & V_69 -> V_172 ;
struct V_62 * V_33 = V_69 -> V_72 -> V_10 ;
struct V_162 * V_58 = V_33 -> V_10 ;
T_3 V_173 ;
T_1 V_174 = F_69 ( V_86 -> V_175 / 1000 ) ;
switch ( V_174 ) {
case V_176 : V_173 = 950 ; break;
default:
case V_177 : V_173 = 550 ; break;
}
V_58 -> V_164 . V_178 ( V_69 , V_173 + F_70 ( V_69 ) ) ;
return V_58 -> V_179 ( V_69 ) ;
}
static int F_71 ( struct V_62 * V_33 )
{
struct V_162 * V_9 = V_33 -> V_10 ;
struct V_32 * V_180 ;
V_180 = V_9 -> V_164 . V_181 ( V_33 -> V_116 [ 0 ] . V_69 ,
V_182 , 1 ) ;
if ( F_47 ( V_183 , V_33 -> V_116 [ 0 ] . V_69 , V_180 ,
& V_184 ) == NULL )
return - V_165 ;
V_9 -> V_179 = V_33 -> V_116 [ 0 ] . V_69 -> V_142 . V_143 . V_185 ;
V_33 -> V_116 [ 0 ] . V_69 -> V_142 . V_143 . V_185 = F_68 ;
return 0 ;
}
static int F_72 ( struct V_62 * V_33 )
{
if ( F_22 ( V_33 -> V_63 -> V_39 , 0 , 1 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_33 -> V_63 , V_61 , NULL , 0 , NULL , 0 ) ;
F_9 ( V_33 -> V_63 , 0x04 , 0 ) ;
F_10 ( V_33 -> V_63 , 0x01 , 1 ) ;
F_10 ( V_33 -> V_63 , 0x02 , 1 ) ;
V_33 -> V_116 [ 0 ] . V_69 = F_47 ( V_158 ,
& V_186 ,
& V_33 -> V_63 -> V_102 ) ;
if ( ( V_33 -> V_116 [ 0 ] . V_69 ) != NULL )
return 0 ;
V_33 -> V_116 [ 0 ] . V_69 = F_47 ( V_155 ,
& V_187 ,
& V_33 -> V_63 -> V_102 ) ;
if ( ( V_33 -> V_116 [ 0 ] . V_69 ) != NULL )
return 0 ;
return - V_31 ;
}
static int F_73 ( struct V_62 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_63 ;
int V_188 ;
if ( F_22 ( V_2 -> V_39 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_74 ( V_2 -> V_39 ,
F_75 ( V_2 -> V_39 , V_2 -> V_78 . V_79 ) ) ;
F_74 ( V_2 -> V_39 ,
F_33 ( V_2 -> V_39 , V_2 -> V_78 . V_79 ) ) ;
F_74 ( V_2 -> V_39 ,
F_33 ( V_2 -> V_39 , V_2 -> V_78 . V_53 [ 0 ] . V_69 [ 0 ] . V_87 . V_91 ) ) ;
for ( V_188 = 0 ; V_188 < 5 ; V_188 ++ ) {
F_30 ( V_2 ) ;
F_35 ( V_2 ) ;
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
V_33 -> V_116 [ 0 ] . V_69 = F_47 ( V_189 , & V_190 , & V_2 -> V_102 ) ;
if ( V_33 -> V_116 [ 0 ] . V_69 == NULL )
return - V_31 ;
return 0 ;
}
static int F_76 ( struct V_62 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_63 ;
if ( F_22 ( V_2 -> V_39 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_74 ( V_2 -> V_39 ,
F_75 ( V_2 -> V_39 , V_2 -> V_78 . V_79 ) ) ;
F_74 ( V_2 -> V_39 ,
F_33 ( V_2 -> V_39 , V_2 -> V_78 . V_79 ) ) ;
F_74 ( V_2 -> V_39 ,
F_33 ( V_2 -> V_39 , V_2 -> V_78 . V_53 [ 0 ] . V_69 [ 0 ] . V_87 . V_91 ) ) ;
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
V_33 -> V_116 [ 0 ] . V_69 = F_47 ( V_191 , & V_192 ,
& V_2 -> V_102 ) ;
if ( V_33 -> V_116 [ 0 ] . V_69 == NULL )
return - V_31 ;
return 0 ;
}
static int F_77 ( struct V_62 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_63 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_32 * V_53 ;
struct V_193 * V_194 ;
struct V_193 * V_195 ;
struct V_196 F_63 ;
struct V_197 V_197 ;
struct V_198 V_198 ;
if ( F_22 ( V_2 -> V_39 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_74 ( V_2 -> V_39 ,
F_75 ( V_2 -> V_39 , V_2 -> V_78 . V_79 ) ) ;
F_74 ( V_2 -> V_39 ,
F_33 ( V_2 -> V_39 , V_2 -> V_78 . V_79 ) ) ;
F_74 ( V_2 -> V_39 ,
F_33 ( V_2 -> V_39 , V_2 -> V_78 . V_53 [ 0 ] . V_69 [ 0 ] . V_87 . V_91 ) ) ;
V_197 . V_32 = & V_53 ;
V_197 . V_69 = & V_33 -> V_116 [ 0 ] . V_69 ;
V_197 . V_199 = V_200 ;
V_197 . V_201 = 1 ;
memset ( & F_63 , 0 , sizeof( struct V_196 ) ) ;
F_78 ( F_63 . type , L_16 , V_202 ) ;
F_63 . V_30 = 0x64 ;
F_63 . V_203 = & V_197 ;
F_79 ( F_63 . type ) ;
V_194 = F_80 ( & V_2 -> V_102 , & F_63 ) ;
if ( V_194 == NULL || V_194 -> V_63 . V_204 == NULL )
return - V_165 ;
if ( ! F_81 ( V_194 -> V_63 . V_204 -> V_205 ) ) {
F_82 ( V_194 ) ;
return - V_165 ;
}
V_9 -> V_206 = V_194 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_69 = V_33 -> V_116 [ 0 ] . V_69 ;
V_198 . V_207 = 1 ;
memset ( & F_63 , 0 , sizeof( struct V_196 ) ) ;
F_78 ( F_63 . type , L_17 , V_202 ) ;
F_63 . V_30 = 0x60 ;
F_63 . V_203 = & V_198 ;
F_79 ( F_63 . type ) ;
V_195 = F_80 ( V_53 , & F_63 ) ;
if ( V_195 == NULL || V_195 -> V_63 . V_204 == NULL ) {
F_83 ( V_194 -> V_63 . V_204 -> V_205 ) ;
F_82 ( V_194 ) ;
return - V_165 ;
}
if ( ! F_81 ( V_195 -> V_63 . V_204 -> V_205 ) ) {
F_82 ( V_195 ) ;
F_83 ( V_194 -> V_63 . V_204 -> V_205 ) ;
F_82 ( V_194 ) ;
return - V_165 ;
}
V_9 -> V_208 = V_195 ;
F_84 ( & V_9 -> V_76 ) ;
V_9 -> V_75 = 0 ;
V_9 -> V_73 = V_33 -> V_116 [ 0 ] . V_69 -> V_142 . V_209 ;
V_33 -> V_116 [ 0 ] . V_69 -> V_142 . V_209 = F_29 ;
return 0 ;
}
static int F_85 ( struct V_210 * V_39 ,
struct V_211 * V_78 ,
struct V_212 * * V_213 ,
int * V_214 )
{
int V_215 = * V_214 ;
* V_214 = V_39 -> V_40 . V_216 == 0xff &&
V_39 -> V_40 . V_217 == 0xff &&
V_39 -> V_40 . V_218 == 0xff ;
if ( * V_214 && ! V_215 )
* V_213 = NULL ;
return 0 ;
}
static int F_86 ( struct V_210 * V_39 ,
const struct V_219 * V_220 )
{
int V_221 ;
for ( V_221 = 0 ; V_221 < F_87 ( V_222 ) ; V_221 ++ ) {
int V_223 = V_222 [ V_221 ] ;
if ( V_220 -> V_224 < V_223 + 4 )
continue;
if ( V_220 -> V_16 [ V_223 ] == ( V_225 & 0xff ) &&
V_220 -> V_16 [ V_223 + 1 ] == V_225 >> 8 ) {
struct V_219 V_226 ;
T_1 * V_227 = F_88 ( V_220 -> V_224 ) ;
int V_11 ;
if ( ! V_227 )
return - V_228 ;
memcpy ( V_227 , V_220 -> V_16 , V_220 -> V_224 ) ;
V_226 . V_224 = V_220 -> V_224 ;
V_226 . V_16 = V_227 ;
V_227 [ V_223 + 2 ] =
F_17 ( V_39 -> V_40 . V_229 ) + 1 ;
V_227 [ V_223 + 3 ] =
F_17 ( V_39 -> V_40 . V_229 ) >> 8 ;
V_11 = F_89 ( V_39 , & V_226 ,
V_230 ) ;
F_90 ( V_227 ) ;
return V_11 ;
}
}
return - V_129 ;
}
static int F_91 ( struct V_231 * V_232 ,
const struct V_233 * V_234 )
{
if ( 0 == F_92 ( V_232 , & V_235 ,
V_236 , NULL , V_237 ) ||
0 == F_92 ( V_232 , & V_238 ,
V_236 , NULL , V_237 ) ||
0 == F_92 ( V_232 , & V_239 ,
V_236 , NULL , V_237 ) ||
0 == F_92 ( V_232 , & V_240 ,
V_236 , NULL , V_237 ) ||
0 == F_92 ( V_232 , & V_241 ,
V_236 , NULL , V_237 ) ||
0 == F_92 ( V_232 , & V_242 ,
V_236 , NULL , V_237 ) ||
0 == F_92 ( V_232 , & V_243 ,
V_236 , NULL , V_237 ) ||
0 == F_92 ( V_232 ,
& V_244 ,
V_236 , NULL , V_237 ) ||
0 == F_92 ( V_232 , & V_245 ,
V_236 , NULL , V_237 ) ||
0 == F_92 ( V_232 ,
& V_246 ,
V_236 , NULL , V_237 ) ||
0 == F_92 ( V_232 , & V_247 ,
V_236 , NULL , V_237 ) ||
0 == F_92 ( V_232 , & V_248 ,
V_236 , NULL , V_237 ) ||
0 == F_92 ( V_232 , & V_249 ,
V_236 , NULL , V_237 ) ||
0 )
return 0 ;
return - V_129 ;
}
static void F_93 ( struct V_231 * V_232 )
{
struct V_1 * V_2 = F_94 ( V_232 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_193 * V_250 ;
V_250 = V_9 -> V_208 ;
if ( V_250 ) {
F_83 ( V_250 -> V_63 . V_204 -> V_205 ) ;
F_82 ( V_250 ) ;
}
V_250 = V_9 -> V_206 ;
if ( V_250 ) {
F_83 ( V_250 -> V_63 . V_204 -> V_205 ) ;
F_82 ( V_250 ) ;
}
F_95 ( V_232 ) ;
}
