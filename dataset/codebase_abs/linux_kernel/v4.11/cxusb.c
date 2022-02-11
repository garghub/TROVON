static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 ;
if ( 1 + V_5 > V_12 ) {
F_2 ( L_1 , V_5 ) ;
return - V_13 ;
}
if ( V_7 > V_12 ) {
F_2 ( L_2 , V_7 ) ;
return - V_13 ;
}
F_3 ( & V_2 -> V_14 ) ;
V_9 -> V_15 [ 0 ] = V_3 ;
memcpy ( & V_9 -> V_15 [ 1 ] , V_4 , V_5 ) ;
V_11 = F_4 ( V_2 , V_9 -> V_15 , 1 + V_5 , V_9 -> V_15 , V_7 , 0 ) ;
if ( ! V_11 && V_6 && V_7 )
memcpy ( V_6 , V_9 -> V_15 , V_7 ) ;
F_5 ( & V_2 -> V_14 ) ;
return V_11 ;
}
static void F_6 ( struct V_1 * V_2 , int V_16 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_1 V_17 [ 2 ] , V_18 ;
if ( V_9 -> V_19 [ V_20 ] == V_16 )
return;
V_17 [ 0 ] = V_20 ;
V_17 [ 1 ] = V_16 ;
F_1 ( V_2 , V_21 , V_17 , 2 , & V_18 , 1 ) ;
if ( V_18 != 0x01 )
F_7 ( L_3 ) ;
V_9 -> V_19 [ V_20 ] = V_16 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_22 ,
T_1 V_23 )
{
T_1 V_17 [ 2 ] , V_24 ;
int V_25 ;
V_17 [ 0 ] = 0xff & ~ V_22 ;
V_17 [ 1 ] = V_23 & V_22 ;
V_25 = F_1 ( V_2 , V_26 , V_17 , 2 , & V_24 , 1 ) ;
if ( V_25 < 0 || ( V_24 & V_22 ) != ( V_23 & V_22 ) )
F_7 ( L_4 ) ;
return V_25 < 0 ? V_25 : V_24 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_27 , int V_28 )
{
F_8 ( V_2 , V_27 , V_28 ? 0 : V_27 ) ;
F_10 ( 5 ) ;
F_8 ( V_2 , V_27 , V_28 ? V_27 : 0 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_16 )
{
F_8 ( V_2 , 0x40 , V_16 ? 0 : 0x40 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_29 , int V_16 )
{
T_1 V_17 [ 2 ] = { V_29 , V_16 } ;
T_1 V_18 ;
int V_25 ;
V_25 = F_1 ( V_2 , V_21 , V_17 , 2 , & V_18 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_18 == 0x01 )
return 0 ;
else {
F_7 ( L_3 ) ;
return - V_30 ;
}
}
static int F_13 ( struct V_31 * V_32 , struct V_33 V_34 [] ,
int V_35 )
{
struct V_1 * V_2 = F_14 ( V_32 ) ;
int V_11 ;
int V_18 ;
if ( F_15 ( & V_2 -> V_36 ) < 0 )
return - V_37 ;
for ( V_18 = 0 ; V_18 < V_35 ; V_18 ++ ) {
if ( F_16 ( V_2 -> V_38 -> V_39 . V_40 ) == V_41 )
switch ( V_34 [ V_18 ] . V_29 ) {
case 0x63 :
F_6 ( V_2 , 0 ) ;
break;
default:
F_6 ( V_2 , 1 ) ;
break;
}
if ( V_34 [ V_18 ] . V_42 & V_43 ) {
T_1 V_44 [ 3 ] , V_45 [ V_12 ] ;
if ( 1 + V_34 [ V_18 ] . V_46 > sizeof( V_45 ) ) {
F_2 ( L_2 ,
V_34 [ V_18 ] . V_46 ) ;
V_11 = - V_13 ;
goto V_47;
}
V_44 [ 0 ] = 0 ;
V_44 [ 1 ] = V_34 [ V_18 ] . V_46 ;
V_44 [ 2 ] = V_34 [ V_18 ] . V_29 ;
if ( F_1 ( V_2 , V_48 ,
V_44 , 3 ,
V_45 , 1 + V_34 [ V_18 ] . V_46 ) < 0 ) {
F_2 ( L_5 ) ;
break;
}
memcpy ( V_34 [ V_18 ] . V_49 , & V_45 [ 1 ] , V_34 [ V_18 ] . V_46 ) ;
} else if ( V_18 + 1 < V_35 && ( V_34 [ V_18 + 1 ] . V_42 & V_43 ) &&
V_34 [ V_18 ] . V_29 == V_34 [ V_18 + 1 ] . V_29 ) {
T_1 V_44 [ V_12 ] , V_45 [ V_12 ] ;
if ( 3 + V_34 [ V_18 ] . V_46 > sizeof( V_44 ) ) {
F_2 ( L_1 ,
V_34 [ V_18 ] . V_46 ) ;
V_11 = - V_13 ;
goto V_47;
}
if ( 1 + V_34 [ V_18 + 1 ] . V_46 > sizeof( V_45 ) ) {
F_2 ( L_2 ,
V_34 [ V_18 + 1 ] . V_46 ) ;
V_11 = - V_13 ;
goto V_47;
}
V_44 [ 0 ] = V_34 [ V_18 ] . V_46 ;
V_44 [ 1 ] = V_34 [ V_18 + 1 ] . V_46 ;
V_44 [ 2 ] = V_34 [ V_18 ] . V_29 ;
memcpy ( & V_44 [ 3 ] , V_34 [ V_18 ] . V_49 , V_34 [ V_18 ] . V_46 ) ;
if ( F_1 ( V_2 , V_48 ,
V_44 , 3 + V_34 [ V_18 ] . V_46 ,
V_45 , 1 + V_34 [ V_18 + 1 ] . V_46 ) < 0 )
break;
if ( V_45 [ 0 ] != 0x08 )
F_17 ( L_6 ) ;
memcpy ( V_34 [ V_18 + 1 ] . V_49 , & V_45 [ 1 ] , V_34 [ V_18 + 1 ] . V_46 ) ;
V_18 ++ ;
} else {
T_1 V_44 [ V_12 ] , V_45 ;
if ( 2 + V_34 [ V_18 ] . V_46 > sizeof( V_44 ) ) {
F_2 ( L_1 ,
V_34 [ V_18 ] . V_46 ) ;
V_11 = - V_13 ;
goto V_47;
}
V_44 [ 0 ] = V_34 [ V_18 ] . V_29 ;
V_44 [ 1 ] = V_34 [ V_18 ] . V_46 ;
memcpy ( & V_44 [ 2 ] , V_34 [ V_18 ] . V_49 , V_34 [ V_18 ] . V_46 ) ;
if ( F_1 ( V_2 , V_50 , V_44 ,
2 + V_34 [ V_18 ] . V_46 , & V_45 , 1 ) < 0 )
break;
if ( V_45 != 0x08 )
F_17 ( L_7 ) ;
}
}
if ( V_18 == V_35 )
V_11 = V_35 ;
else
V_11 = - V_51 ;
V_47:
F_5 ( & V_2 -> V_36 ) ;
return V_11 ;
}
static T_2 F_18 ( struct V_31 * V_52 )
{
return V_53 ;
}
static int F_19 ( struct V_1 * V_2 , int V_16 )
{
T_1 V_54 = 0 ;
if ( V_16 )
return F_1 ( V_2 , V_55 , & V_54 , 1 , NULL , 0 ) ;
else
return F_1 ( V_2 , V_56 , & V_54 , 1 , NULL , 0 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_16 )
{
int V_11 ;
if ( ! V_16 )
return F_1 ( V_2 , V_56 , NULL , 0 , NULL , 0 ) ;
if ( V_2 -> V_57 == V_58 &&
F_21 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_22 ( L_8 ) ;
do {} while ( ! ( V_11 = F_1 ( V_2 , V_55 , NULL , 0 , NULL , 0 ) ) &&
! ( V_11 = F_1 ( V_2 , 0x15 , NULL , 0 , NULL , 0 ) ) &&
! ( V_11 = F_1 ( V_2 , 0x17 , NULL , 0 , NULL , 0 ) ) && 0 );
if ( ! V_11 ) {
int V_18 ;
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
F_10 ( 20 ) ;
for ( V_18 = 0 ; V_18 < sizeof( V_59 ) / sizeof( T_1 ) ; V_18 += 4 / sizeof( T_1 ) ) {
V_11 = F_1 ( V_2 , V_50 ,
V_59 + V_18 , 4 , & V_49 , 1 ) ;
if ( V_11 )
break;
if ( V_49 != 0x8 )
return - V_51 ;
}
}
return V_11 ;
}
static int F_23 ( struct V_1 * V_2 , int V_16 )
{
T_1 V_54 = 0 ;
if ( V_16 )
return F_1 ( V_2 , V_55 , & V_54 , 1 , NULL , 0 ) ;
else
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_16 )
{
int V_25 = 0 ;
V_25 = F_19 ( V_2 , V_16 ) ;
if ( ! V_16 )
F_11 ( V_2 , 0 ) ;
return V_25 ;
}
static int F_25 ( struct V_1 * V_2 , int V_16 )
{
int V_11 ;
T_1 V_54 ;
V_11 = F_19 ( V_2 , V_16 ) ;
if ( ! V_16 )
return V_11 ;
F_10 ( 128 ) ;
F_1 ( V_2 , V_60 , NULL , 0 , & V_54 , 1 ) ;
F_10 ( 100 ) ;
return V_11 ;
}
static int F_26 ( struct V_61 * V_32 , int V_16 )
{
T_1 V_49 [ 2 ] = { 0x03 , 0x00 } ;
if ( V_16 )
F_1 ( V_32 -> V_62 , V_63 , V_49 , 2 , NULL , 0 ) ;
else
F_1 ( V_32 -> V_62 , V_64 , NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_61 * V_32 , int V_16 )
{
if ( V_16 )
F_1 ( V_32 -> V_62 , V_65 , NULL , 0 , NULL , 0 ) ;
else
F_1 ( V_32 -> V_62 , V_66 ,
NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static int F_28 ( struct V_67 * V_68 ,
enum V_69 * V_70 )
{
struct V_61 * V_32 = (struct V_61 * ) V_68 -> V_71 -> V_10 ;
struct V_8 * V_57 = (struct V_8 * ) V_32 -> V_62 -> V_10 ;
int V_11 ;
V_11 = V_57 -> V_72 ( V_68 , V_70 ) ;
if ( ( * V_70 & V_73 ) && ( ! V_57 -> V_74 ) ) {
F_3 ( & V_57 -> V_75 ) ;
F_26 ( V_32 , 1 ) ;
F_5 ( & V_57 -> V_75 ) ;
}
V_57 -> V_74 = ( * V_70 & V_73 ) ? 1 : 0 ;
return V_11 ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_76 = V_2 -> V_77 . V_78 ;
const int V_79 = 100 ;
const int V_80 = 32 ;
T_1 * V_81 ;
int V_82 ;
V_81 = F_30 ( V_80 , V_83 ) ;
if ( ! V_81 )
return;
while ( 1 ) {
if ( F_31 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_76 ) ,
V_81 , V_80 , & V_82 , V_79 ) < 0 )
break;
if ( ! V_82 )
break;
}
F_33 ( V_81 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = & V_2 -> V_77 . V_52 [ 0 ] . V_68 [ 0 ] . V_86 ;
const int V_79 = 100 ;
const int V_80 = V_85 -> V_87 . V_88 . V_89 ;
T_1 * V_81 ;
int V_82 ;
V_81 = F_30 ( V_80 , V_83 ) ;
if ( ! V_81 )
return;
while ( 1 ) {
if ( F_31 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_85 -> V_90 ) ,
V_81 , V_80 , & V_82 , V_79 ) < 0 )
break;
if ( ! V_82 )
break;
}
F_33 ( V_81 ) ;
}
static int F_35 (
struct V_61 * V_32 , int V_16 )
{
if ( V_16 ) {
T_1 V_49 [ 2 ] = { 0x03 , 0x00 } ;
F_34 ( V_32 -> V_62 ) ;
return F_1 ( V_32 -> V_62 , V_63 ,
V_49 , sizeof( V_49 ) , NULL , 0 ) ;
} else {
int V_11 = F_1 ( V_32 -> V_62 ,
V_64 , NULL , 0 , NULL , 0 ) ;
return V_11 ;
}
}
static int F_36 ( struct V_1 * V_2 )
{
T_1 V_91 [ 4 ] ;
F_1 ( V_2 , V_92 , NULL , 0 , V_91 , 4 ) ;
if ( V_91 [ 2 ] || V_91 [ 3 ] )
F_37 ( V_2 -> V_93 , V_94 ,
F_38 ( V_91 [ 2 ] , V_91 [ 3 ] ) , 0 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
T_1 V_91 [ 4 ] ;
struct V_33 V_34 = { . V_29 = 0x6b , . V_42 = V_43 ,
. V_49 = V_91 , . V_46 = 4 } ;
if ( F_13 ( & V_2 -> V_95 , & V_34 , 1 ) != 1 )
return 0 ;
if ( V_91 [ 1 ] || V_91 [ 2 ] )
F_37 ( V_2 -> V_93 , V_94 ,
F_38 ( V_91 [ 1 ] , V_91 [ 2 ] ) , 0 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
T_1 V_91 [ 2 ] ;
if ( F_1 ( V_2 , 0x10 , NULL , 0 , V_91 , 2 ) < 0 )
return 0 ;
if ( V_91 [ 0 ] || V_91 [ 1 ] )
F_37 ( V_2 -> V_93 , V_94 ,
F_38 ( V_91 [ 0 ] , V_91 [ 1 ] ) , 0 ) ;
return 0 ;
}
static int F_41 ( struct V_67 * V_68 )
{
static T_1 V_96 [] = { V_97 , 0x38 , 0x28 } ;
static T_1 V_98 [] = { V_99 , 0x80 } ;
static T_1 V_100 [] = { V_101 , 0x40 } ;
static T_1 V_102 [] = { V_103 , 0x28 , 0x20 } ;
static T_1 V_104 [] = { V_105 , 0x33 } ;
static T_1 V_106 [] = { V_107 , 0x32 } ;
F_42 ( V_68 , V_96 , sizeof( V_96 ) ) ;
F_43 ( 200 ) ;
F_42 ( V_68 , V_98 , sizeof( V_98 ) ) ;
F_42 ( V_68 , V_100 , sizeof( V_100 ) ) ;
F_42 ( V_68 , V_102 , sizeof( V_102 ) ) ;
F_42 ( V_68 , V_104 , sizeof( V_104 ) ) ;
F_42 ( V_68 , V_106 , sizeof( V_106 ) ) ;
return 0 ;
}
static int F_44 ( struct V_67 * V_68 )
{
static T_1 V_96 [] = { V_97 , 0x38 , 0x29 } ;
static T_1 V_98 [] = { V_99 , 0x80 } ;
static T_1 V_100 [] = { V_101 , 0x40 } ;
static T_1 V_102 [] = { V_103 , 0x24 , 0x20 } ;
static T_1 V_104 [] = { V_105 , 0x33 } ;
static T_1 V_106 [] = { V_107 , 0x32 } ;
F_42 ( V_68 , V_96 , sizeof( V_96 ) ) ;
F_43 ( 200 ) ;
F_42 ( V_68 , V_98 , sizeof( V_98 ) ) ;
F_42 ( V_68 , V_100 , sizeof( V_100 ) ) ;
F_42 ( V_68 , V_102 , sizeof( V_102 ) ) ;
F_42 ( V_68 , V_104 , sizeof( V_104 ) ) ;
F_42 ( V_68 , V_106 , sizeof( V_106 ) ) ;
return 0 ;
}
static int F_45 ( struct V_61 * V_32 )
{
F_46 ( V_108 , V_32 -> V_109 [ 0 ] . V_68 ,
& V_32 -> V_62 -> V_95 , 0x61 ,
V_110 ) ;
return 0 ;
}
static int F_47 ( struct V_61 * V_32 )
{
F_46 ( V_111 , V_32 -> V_109 [ 0 ] . V_68 , 0x61 ,
NULL , V_112 ) ;
return 0 ;
}
static int F_48 ( struct V_61 * V_32 )
{
F_46 ( V_111 , V_32 -> V_109 [ 0 ] . V_68 , 0x61 , NULL , V_113 ) ;
return 0 ;
}
static int F_49 ( struct V_61 * V_32 )
{
F_46 ( V_111 , V_32 -> V_109 [ 0 ] . V_68 , 0x60 ,
NULL , V_112 ) ;
return 0 ;
}
static int F_50 ( struct V_61 * V_32 )
{
F_46 ( V_108 , V_32 -> V_109 [ 0 ] . V_68 ,
& V_32 -> V_62 -> V_95 , 0x61 , V_114 ) ;
return 0 ;
}
static int F_51 ( void * V_115 , int V_116 ,
int V_117 , int V_118 )
{
struct V_61 * V_32 = V_115 ;
struct V_1 * V_2 = V_32 -> V_62 ;
switch ( V_117 ) {
case V_119 :
F_7 ( L_9 , V_120 , V_118 ) ;
F_9 ( V_2 , 0x01 , 1 ) ;
break;
case V_121 :
F_7 ( L_10 , V_120 , V_118 ) ;
break;
default:
F_7 ( L_11 , V_120 ,
V_117 , V_118 ) ;
return - V_122 ;
}
return 0 ;
}
static int F_52 ( struct V_61 * V_32 )
{
struct V_67 * V_68 ;
struct V_123 V_124 = {
. V_95 = & V_32 -> V_62 -> V_95 ,
. V_125 = 0x61 ,
} ;
static struct V_126 V_127 = {
. V_128 = V_129 ,
. V_130 = 64 ,
. V_131 = V_132 ,
} ;
V_32 -> V_109 [ 0 ] . V_68 -> V_133 = F_51 ;
V_68 = F_46 ( V_134 , V_32 -> V_109 [ 0 ] . V_68 , & V_124 ) ;
if ( V_68 == NULL || V_68 -> V_135 . V_136 . V_137 == NULL )
return - V_30 ;
V_68 -> V_135 . V_136 . V_137 ( V_68 , & V_127 ) ;
return 0 ;
}
static int F_53 ( struct V_61 * V_32 )
{
F_46 ( V_138 , V_32 -> V_109 [ 0 ] . V_68 ,
& V_32 -> V_62 -> V_95 , & V_139 ) ;
return 0 ;
}
static int F_54 ( struct V_61 * V_32 )
{
struct V_67 * V_68 ;
V_68 = F_46 ( V_138 , V_32 -> V_109 [ 0 ] . V_68 ,
& V_32 -> V_62 -> V_95 , & V_140 ) ;
return ( V_68 == NULL ) ? - V_30 : 0 ;
}
static int F_55 ( struct V_61 * V_32 )
{
struct V_67 * V_68 ;
V_68 = F_46 ( V_141 , V_32 -> V_109 [ 0 ] . V_68 ,
& V_32 -> V_62 -> V_95 , & V_142 ) ;
return ( V_68 == NULL ) ? - V_30 : 0 ;
}
static int F_56 ( struct V_61 * V_32 )
{
T_1 V_54 ;
if ( F_21 ( V_32 -> V_62 -> V_38 , 0 , 6 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_32 -> V_62 , V_60 , NULL , 0 , & V_54 , 1 ) ;
V_32 -> V_109 [ 0 ] . V_68 = F_46 ( V_143 , & V_144 ,
& V_32 -> V_62 -> V_95 ) ;
if ( ( V_32 -> V_109 [ 0 ] . V_68 ) != NULL )
return 0 ;
return - V_30 ;
}
static int F_57 ( struct V_61 * V_32 )
{
if ( F_21 ( V_32 -> V_62 -> V_38 , 0 , 7 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_32 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
V_32 -> V_109 [ 0 ] . V_68 = F_46 ( V_145 ,
& V_146 ,
& V_32 -> V_62 -> V_95 ) ;
if ( ( V_32 -> V_109 [ 0 ] . V_68 ) != NULL )
return 0 ;
return - V_30 ;
}
static int F_58 ( struct V_61 * V_32 )
{
V_32 -> V_109 [ 0 ] . V_68 = F_46 ( V_145 , & V_147 ,
& V_32 -> V_62 -> V_95 ) ;
if ( V_32 -> V_109 [ 0 ] . V_68 != NULL )
return 0 ;
return - V_30 ;
}
static int F_59 ( struct V_61 * V_32 )
{
if ( F_21 ( V_32 -> V_62 -> V_38 , 0 , 0 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_32 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
V_32 -> V_109 [ 0 ] . V_68 = F_46 ( V_148 , & V_149 ,
& V_32 -> V_62 -> V_95 ) ;
if ( ( V_32 -> V_109 [ 0 ] . V_68 ) != NULL )
return 0 ;
return - V_30 ;
}
static int F_60 ( struct V_61 * V_32 )
{
if ( F_21 ( V_32 -> V_62 -> V_38 , 0 , 0 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_32 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
V_32 -> V_109 [ 0 ] . V_68 = F_46 ( V_148 , & V_150 ,
& V_32 -> V_62 -> V_95 ) ;
if ( ( V_32 -> V_109 [ 0 ] . V_68 ) != NULL )
return 0 ;
V_32 -> V_109 [ 0 ] . V_68 = F_46 ( V_151 ,
& V_152 ,
& V_32 -> V_62 -> V_95 ) ;
if ( ( V_32 -> V_109 [ 0 ] . V_68 ) != NULL )
return 0 ;
return - V_30 ;
}
static int F_61 ( struct V_61 * V_32 )
{
T_1 V_91 [ 4 ] ;
int V_18 ;
struct V_33 V_34 = { . V_29 = 0x6b , . V_42 = V_43 ,
. V_49 = V_91 , . V_46 = 4 } ;
if ( F_21 ( V_32 -> V_62 -> V_38 , 0 , 1 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_32 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
F_8 ( V_32 -> V_62 , 0x04 , 0 ) ;
F_9 ( V_32 -> V_62 , 0x01 , 1 ) ;
F_9 ( V_32 -> V_62 , 0x02 , 1 ) ;
V_32 -> V_109 [ 0 ] . V_68 =
F_46 ( V_151 ,
& V_153 ,
& V_32 -> V_62 -> V_95 ) ;
if ( ( V_32 -> V_109 [ 0 ] . V_68 ) == NULL )
return - V_30 ;
for ( V_18 = 0 ; V_32 -> V_62 -> V_77 . V_25 . V_154 . V_155 && V_18 < 5 ; V_18 ++ ) {
F_10 ( 20 ) ;
if ( F_13 ( & V_32 -> V_62 -> V_95 , & V_34 , 1 ) != 1 )
goto V_156;
if ( V_91 [ 0 ] == 0 && V_91 [ 1 ] == 0 )
continue;
if ( V_91 [ 2 ] + V_91 [ 3 ] != 0xff ) {
V_156:
V_32 -> V_62 -> V_77 . V_25 . V_154 . V_155 = NULL ;
F_62 ( L_12 ) ;
break;
}
}
return 0 ;
}
static int F_63 ( struct V_61 * V_32 )
{
struct V_157 * V_57 = V_32 -> V_10 ;
if ( F_21 ( V_32 -> V_62 -> V_38 , 0 , 1 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_32 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
F_9 ( V_32 -> V_62 , 0x02 , 1 ) ;
if ( ! F_46 ( V_158 , & V_57 -> V_159 ) )
return - V_160 ;
if ( V_57 -> V_159 . V_161 ( & V_32 -> V_62 -> V_95 , 1 , 18 ,
& V_162 ) < 0 ) {
F_64 ( V_163 L_13 ) ;
return - V_160 ;
}
V_32 -> V_109 [ 0 ] . V_68 = V_57 -> V_159 . V_164 ( & V_32 -> V_62 -> V_95 , 0x80 ,
& V_162 ) ;
if ( V_32 -> V_109 [ 0 ] . V_68 == NULL )
return - V_30 ;
return 0 ;
}
static int F_65 ( struct V_67 * V_68 , int V_16 )
{
struct V_61 * V_32 = V_68 -> V_71 -> V_10 ;
struct V_157 * V_57 = V_32 -> V_10 ;
return V_57 -> V_159 . V_165 ( V_68 , 8 , 0 , ! V_16 ) ;
}
static int F_66 ( struct V_67 * V_68 , int V_16 )
{
return 0 ;
}
static int F_67 ( struct V_67 * V_68 )
{
struct V_166 * V_85 = & V_68 -> V_167 ;
struct V_61 * V_32 = V_68 -> V_71 -> V_10 ;
struct V_157 * V_57 = V_32 -> V_10 ;
T_3 V_168 ;
T_1 V_169 = F_68 ( V_85 -> V_170 / 1000 ) ;
switch ( V_169 ) {
case V_171 : V_168 = 950 ; break;
default:
case V_172 : V_168 = 550 ; break;
}
V_57 -> V_159 . V_173 ( V_68 , V_168 + F_69 ( V_68 ) ) ;
return V_57 -> V_174 ( V_68 ) ;
}
static int F_70 ( struct V_61 * V_32 )
{
struct V_157 * V_9 = V_32 -> V_10 ;
struct V_31 * V_175 ;
V_175 = V_9 -> V_159 . V_176 ( V_32 -> V_109 [ 0 ] . V_68 ,
V_177 , 1 ) ;
if ( F_46 ( V_178 , V_32 -> V_109 [ 0 ] . V_68 , V_175 ,
& V_179 ) == NULL )
return - V_160 ;
V_9 -> V_174 = V_32 -> V_109 [ 0 ] . V_68 -> V_135 . V_136 . V_180 ;
V_32 -> V_109 [ 0 ] . V_68 -> V_135 . V_136 . V_180 = F_67 ;
return 0 ;
}
static int F_71 ( struct V_61 * V_32 )
{
if ( F_21 ( V_32 -> V_62 -> V_38 , 0 , 1 ) < 0 )
F_22 ( L_8 ) ;
F_1 ( V_32 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
F_8 ( V_32 -> V_62 , 0x04 , 0 ) ;
F_9 ( V_32 -> V_62 , 0x01 , 1 ) ;
F_9 ( V_32 -> V_62 , 0x02 , 1 ) ;
V_32 -> V_109 [ 0 ] . V_68 = F_46 ( V_151 ,
& V_181 ,
& V_32 -> V_62 -> V_95 ) ;
if ( ( V_32 -> V_109 [ 0 ] . V_68 ) != NULL )
return 0 ;
V_32 -> V_109 [ 0 ] . V_68 = F_46 ( V_148 ,
& V_182 ,
& V_32 -> V_62 -> V_95 ) ;
if ( ( V_32 -> V_109 [ 0 ] . V_68 ) != NULL )
return 0 ;
return - V_30 ;
}
static int F_72 ( struct V_61 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_62 ;
int V_183 ;
if ( F_21 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_22 ( L_8 ) ;
F_73 ( V_2 -> V_38 ,
F_74 ( V_2 -> V_38 , V_2 -> V_77 . V_78 ) ) ;
F_73 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_2 -> V_77 . V_78 ) ) ;
F_73 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_2 -> V_77 . V_52 [ 0 ] . V_68 [ 0 ] . V_86 . V_90 ) ) ;
for ( V_183 = 0 ; V_183 < 5 ; V_183 ++ ) {
F_29 ( V_2 ) ;
F_34 ( V_2 ) ;
F_10 ( 200 ) ;
}
if ( F_12 ( V_2 , 0x07 , 0 ) < 0 ) {
F_22 ( L_14 ) ;
return - V_30 ;
}
F_10 ( 100 ) ;
if ( F_12 ( V_2 , 0x07 , 1 ) < 0 ) {
F_22 ( L_15 ) ;
return - V_30 ;
}
F_10 ( 100 ) ;
V_32 -> V_109 [ 0 ] . V_68 = F_46 ( V_184 , & V_185 , & V_2 -> V_95 ) ;
if ( V_32 -> V_109 [ 0 ] . V_68 == NULL )
return - V_30 ;
return 0 ;
}
static int F_75 ( struct V_61 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_62 ;
if ( F_21 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_22 ( L_8 ) ;
F_73 ( V_2 -> V_38 ,
F_74 ( V_2 -> V_38 , V_2 -> V_77 . V_78 ) ) ;
F_73 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_2 -> V_77 . V_78 ) ) ;
F_73 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_2 -> V_77 . V_52 [ 0 ] . V_68 [ 0 ] . V_86 . V_90 ) ) ;
if ( F_12 ( V_2 , 0x07 , 0 ) < 0 ) {
F_22 ( L_14 ) ;
return - V_30 ;
}
F_10 ( 100 ) ;
if ( F_12 ( V_2 , 0x07 , 1 ) < 0 ) {
F_22 ( L_15 ) ;
return - V_30 ;
}
F_10 ( 100 ) ;
V_32 -> V_109 [ 0 ] . V_68 = F_46 ( V_186 , & V_187 ,
& V_2 -> V_95 ) ;
if ( V_32 -> V_109 [ 0 ] . V_68 == NULL )
return - V_30 ;
return 0 ;
}
static int F_76 ( struct V_61 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_62 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_31 * V_52 ;
struct V_188 * V_189 ;
struct V_188 * V_190 ;
struct V_191 F_62 ;
struct V_192 V_192 ;
struct V_193 V_193 ;
if ( F_21 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_22 ( L_8 ) ;
F_73 ( V_2 -> V_38 ,
F_74 ( V_2 -> V_38 , V_2 -> V_77 . V_78 ) ) ;
F_73 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_2 -> V_77 . V_78 ) ) ;
F_73 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_2 -> V_77 . V_52 [ 0 ] . V_68 [ 0 ] . V_86 . V_90 ) ) ;
V_192 . V_31 = & V_52 ;
V_192 . V_68 = & V_32 -> V_109 [ 0 ] . V_68 ;
V_192 . V_194 = V_195 ;
V_192 . V_196 = 1 ;
memset ( & F_62 , 0 , sizeof( struct V_191 ) ) ;
F_77 ( F_62 . type , L_16 , V_197 ) ;
F_62 . V_29 = 0x64 ;
F_62 . V_198 = & V_192 ;
F_78 ( F_62 . type ) ;
V_189 = F_79 ( & V_2 -> V_95 , & F_62 ) ;
if ( V_189 == NULL || V_189 -> V_62 . V_199 == NULL )
return - V_160 ;
if ( ! F_80 ( V_189 -> V_62 . V_199 -> V_200 ) ) {
F_81 ( V_189 ) ;
return - V_160 ;
}
V_9 -> V_201 = V_189 ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
V_193 . V_68 = V_32 -> V_109 [ 0 ] . V_68 ;
V_193 . V_202 = 1 ;
memset ( & F_62 , 0 , sizeof( struct V_191 ) ) ;
F_77 ( F_62 . type , L_17 , V_197 ) ;
F_62 . V_29 = 0x60 ;
F_62 . V_198 = & V_193 ;
F_78 ( F_62 . type ) ;
V_190 = F_79 ( V_52 , & F_62 ) ;
if ( V_190 == NULL || V_190 -> V_62 . V_199 == NULL ) {
F_82 ( V_189 -> V_62 . V_199 -> V_200 ) ;
F_81 ( V_189 ) ;
return - V_160 ;
}
if ( ! F_80 ( V_190 -> V_62 . V_199 -> V_200 ) ) {
F_81 ( V_190 ) ;
F_82 ( V_189 -> V_62 . V_199 -> V_200 ) ;
F_81 ( V_189 ) ;
return - V_160 ;
}
V_9 -> V_203 = V_190 ;
F_83 ( & V_9 -> V_75 ) ;
V_9 -> V_74 = 0 ;
V_9 -> V_72 = V_32 -> V_109 [ 0 ] . V_68 -> V_135 . V_204 ;
V_32 -> V_109 [ 0 ] . V_68 -> V_135 . V_204 = F_28 ;
return 0 ;
}
static int F_84 ( struct V_205 * V_38 ,
struct V_206 * V_77 ,
struct V_207 * * V_208 ,
int * V_209 )
{
int V_210 = * V_209 ;
* V_209 = V_38 -> V_39 . V_211 == 0xff &&
V_38 -> V_39 . V_212 == 0xff &&
V_38 -> V_39 . V_213 == 0xff ;
if ( * V_209 && ! V_210 )
* V_208 = NULL ;
return 0 ;
}
static int F_85 ( struct V_205 * V_38 ,
const struct V_214 * V_215 )
{
int V_216 ;
for ( V_216 = 0 ; V_216 < F_86 ( V_217 ) ; V_216 ++ ) {
int V_218 = V_217 [ V_216 ] ;
if ( V_215 -> V_219 < V_218 + 4 )
continue;
if ( V_215 -> V_15 [ V_218 ] == ( V_220 & 0xff ) &&
V_215 -> V_15 [ V_218 + 1 ] == V_220 >> 8 ) {
struct V_214 V_221 ;
T_1 * V_222 = F_87 ( V_215 -> V_219 ) ;
int V_11 ;
if ( ! V_222 )
return - V_223 ;
memcpy ( V_222 , V_215 -> V_15 , V_215 -> V_219 ) ;
V_221 . V_219 = V_215 -> V_219 ;
V_221 . V_15 = V_222 ;
V_222 [ V_218 + 2 ] =
F_16 ( V_38 -> V_39 . V_224 ) + 1 ;
V_222 [ V_218 + 3 ] =
F_16 ( V_38 -> V_39 . V_224 ) >> 8 ;
V_11 = F_88 ( V_38 , & V_221 ,
V_225 ) ;
F_89 ( V_222 ) ;
return V_11 ;
}
}
return - V_122 ;
}
static int F_90 ( struct V_226 * V_227 ,
const struct V_228 * V_229 )
{
if ( 0 == F_91 ( V_227 , & V_230 ,
V_231 , NULL , V_232 ) ||
0 == F_91 ( V_227 , & V_233 ,
V_231 , NULL , V_232 ) ||
0 == F_91 ( V_227 , & V_234 ,
V_231 , NULL , V_232 ) ||
0 == F_91 ( V_227 , & V_235 ,
V_231 , NULL , V_232 ) ||
0 == F_91 ( V_227 , & V_236 ,
V_231 , NULL , V_232 ) ||
0 == F_91 ( V_227 , & V_237 ,
V_231 , NULL , V_232 ) ||
0 == F_91 ( V_227 , & V_238 ,
V_231 , NULL , V_232 ) ||
0 == F_91 ( V_227 ,
& V_239 ,
V_231 , NULL , V_232 ) ||
0 == F_91 ( V_227 , & V_240 ,
V_231 , NULL , V_232 ) ||
0 == F_91 ( V_227 ,
& V_241 ,
V_231 , NULL , V_232 ) ||
0 == F_91 ( V_227 , & V_242 ,
V_231 , NULL , V_232 ) ||
0 == F_91 ( V_227 , & V_243 ,
V_231 , NULL , V_232 ) ||
0 == F_91 ( V_227 , & V_244 ,
V_231 , NULL , V_232 ) ||
0 )
return 0 ;
return - V_122 ;
}
static void F_92 ( struct V_226 * V_227 )
{
struct V_1 * V_2 = F_93 ( V_227 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_188 * V_245 ;
V_245 = V_9 -> V_203 ;
if ( V_245 ) {
F_82 ( V_245 -> V_62 . V_199 -> V_200 ) ;
F_81 ( V_245 ) ;
}
V_245 = V_9 -> V_201 ;
if ( V_245 ) {
F_82 ( V_245 -> V_62 . V_199 -> V_200 ) ;
F_81 ( V_245 ) ;
}
F_94 ( V_227 ) ;
}
