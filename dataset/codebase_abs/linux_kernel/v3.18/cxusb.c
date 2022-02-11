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
if ( F_16 ( V_2 -> V_38 -> V_39 . V_40 ) == V_41 )
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
F_17 ( L_6 ) ;
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
F_17 ( L_7 ) ;
}
}
if ( V_17 == V_34 )
V_35 = V_34 ;
else
V_35 = - V_51 ;
V_47:
F_18 ( & V_2 -> V_36 ) ;
return V_35 ;
}
static T_2 F_19 ( struct V_30 * V_52 )
{
return V_53 ;
}
static int F_20 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_54 = 0 ;
if ( V_12 )
return F_1 ( V_2 , V_55 , & V_54 , 1 , NULL , 0 ) ;
else
return F_1 ( V_2 , V_56 , & V_54 , 1 , NULL , 0 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_12 )
{
int V_35 ;
if ( ! V_12 )
return F_1 ( V_2 , V_56 , NULL , 0 , NULL , 0 ) ;
if ( V_2 -> V_57 == V_58 &&
F_22 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
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
static int F_24 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_54 = 0 ;
if ( V_12 )
return F_1 ( V_2 , V_55 , & V_54 , 1 , NULL , 0 ) ;
else
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , int V_12 )
{
int V_24 = 0 ;
V_24 = F_20 ( V_2 , V_12 ) ;
if ( ! V_12 )
F_10 ( V_2 , 0 ) ;
return V_24 ;
}
static int F_26 ( struct V_1 * V_2 , int V_12 )
{
int V_35 ;
T_1 V_54 ;
V_35 = F_20 ( V_2 , V_12 ) ;
if ( ! V_12 )
return V_35 ;
F_9 ( 128 ) ;
F_1 ( V_2 , V_60 , NULL , 0 , & V_54 , 1 ) ;
F_9 ( 100 ) ;
return V_35 ;
}
static int F_27 ( struct V_61 * V_31 , int V_12 )
{
T_1 V_49 [ 2 ] = { 0x03 , 0x00 } ;
if ( V_12 )
F_1 ( V_31 -> V_62 , V_63 , V_49 , 2 , NULL , 0 ) ;
else
F_1 ( V_31 -> V_62 , V_64 , NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static int F_28 ( struct V_61 * V_31 , int V_12 )
{
if ( V_12 )
F_1 ( V_31 -> V_62 , V_65 , NULL , 0 , NULL , 0 ) ;
else
F_1 ( V_31 -> V_62 , V_66 ,
NULL , 0 , NULL , 0 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_67 = V_2 -> V_68 . V_69 ;
const int V_70 = 100 ;
const int V_71 = 32 ;
T_1 * V_72 ;
int V_73 ;
V_72 = F_30 ( V_71 , V_74 ) ;
if ( ! V_72 )
return;
while ( 1 ) {
if ( F_31 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_67 ) ,
V_72 , V_71 , & V_73 , V_70 ) < 0 )
break;
if ( ! V_73 )
break;
}
F_33 ( V_72 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = & V_2 -> V_68 . V_52 [ 0 ] . V_77 [ 0 ] . V_78 ;
const int V_70 = 100 ;
const int V_71 = V_76 -> V_79 . V_80 . V_81 ;
T_1 * V_72 ;
int V_73 ;
V_72 = F_30 ( V_71 , V_74 ) ;
if ( ! V_72 )
return;
while ( 1 ) {
if ( F_31 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_76 -> V_82 ) ,
V_72 , V_71 , & V_73 , V_70 ) < 0 )
break;
if ( ! V_73 )
break;
}
F_33 ( V_72 ) ;
}
static int F_35 (
struct V_61 * V_31 , int V_12 )
{
if ( V_12 ) {
T_1 V_49 [ 2 ] = { 0x03 , 0x00 } ;
F_34 ( V_31 -> V_62 ) ;
return F_1 ( V_31 -> V_62 , V_63 ,
V_49 , sizeof( V_49 ) , NULL , 0 ) ;
} else {
int V_35 = F_1 ( V_31 -> V_62 ,
V_64 , NULL , 0 , NULL , 0 ) ;
return V_35 ;
}
}
static int F_36 ( struct V_1 * V_2 , T_2 * V_83 , int * V_57 )
{
struct V_84 * V_85 = V_2 -> V_68 . V_24 . V_86 . V_84 ;
T_1 V_87 [ 4 ] ;
int V_17 ;
F_1 ( V_2 , V_88 , NULL , 0 , V_87 , 4 ) ;
* V_83 = 0 ;
* V_57 = V_89 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_68 . V_24 . V_86 . V_90 ; V_17 ++ ) {
if ( F_37 ( & V_85 [ V_17 ] ) == V_87 [ 2 ] &&
F_38 ( & V_85 [ V_17 ] ) == V_87 [ 3 ] ) {
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
T_1 V_87 [ 4 ] ;
int V_17 ;
struct V_32 V_33 = { . V_28 = 0x6b , . V_42 = V_43 ,
. V_49 = V_87 , . V_46 = 4 } ;
* V_83 = 0 ;
* V_57 = V_89 ;
if ( F_13 ( & V_2 -> V_93 , & V_33 , 1 ) != 1 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_68 . V_24 . V_86 . V_90 ; V_17 ++ ) {
if ( F_37 ( & V_85 [ V_17 ] ) == V_87 [ 1 ] &&
F_38 ( & V_85 [ V_17 ] ) == V_87 [ 2 ] ) {
* V_83 = V_85 [ V_17 ] . V_91 ;
* V_57 = V_92 ;
return 0 ;
}
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , T_2 * V_83 ,
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
if ( F_37 ( & V_85 [ V_17 ] ) == V_87 [ 0 ] &&
F_38 ( & V_85 [ V_17 ] ) == V_87 [ 1 ] ) {
* V_83 = V_85 [ V_17 ] . V_91 ;
* V_57 = V_92 ;
return 0 ;
}
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
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
F_42 ( V_2 -> V_97 , V_98 , V_91 , V_96 ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_99 [ 6 ] )
{
T_1 V_4 [ 2 ] ;
T_1 V_6 [ 6 ] ;
int V_35 ;
struct V_32 V_33 [] = {
{
. V_28 = 0x51 ,
. V_42 = 0 ,
. V_49 = V_4 ,
. V_46 = 2 ,
} , {
. V_28 = 0x51 ,
. V_42 = V_43 ,
. V_49 = V_6 ,
. V_46 = 6 ,
}
} ;
V_4 [ 0 ] = 0x1e ;
V_4 [ 1 ] = 0x00 ;
V_35 = F_13 ( & V_2 -> V_93 , V_33 , 2 ) ;
if ( V_35 == 2 ) {
memcpy ( V_99 , V_6 , 6 ) ;
return 0 ;
} else {
if ( V_35 < 0 )
return V_35 ;
return - V_29 ;
}
}
static int F_44 ( void * V_15 , T_1 V_100 , int V_28 ,
T_1 V_101 , int * V_102 )
{
struct V_1 * V_2 = V_15 ;
T_1 V_4 [ 3 ] ;
T_1 V_6 [ 2 ] ;
int V_35 ;
V_4 [ 0 ] = ( V_28 >> 8 ) & 0xff ;
V_4 [ 1 ] = V_28 & 0xff ;
if ( V_100 ) {
V_35 = F_1 ( V_2 , V_103 , V_4 , 2 , V_6 , 2 ) ;
} else {
V_4 [ 2 ] = V_101 ;
V_35 = F_1 ( V_2 , V_104 , V_4 , 3 , V_6 , 1 ) ;
}
if ( V_35 )
goto F_23;
if ( V_100 )
* V_102 = V_6 [ 1 ] ;
return 0 ;
F_23:
F_6 ( L_9 , V_105 , V_35 ) ;
return V_35 ;
}
static int F_45 ( struct V_106 * V_77 )
{
static T_1 V_107 [] = { V_108 , 0x38 , 0x28 } ;
static T_1 V_109 [] = { V_110 , 0x80 } ;
static T_1 V_111 [] = { V_112 , 0x40 } ;
static T_1 V_113 [] = { V_114 , 0x28 , 0x20 } ;
static T_1 V_115 [] = { V_116 , 0x33 } ;
static T_1 V_117 [] = { V_118 , 0x32 } ;
F_46 ( V_77 , V_107 , sizeof( V_107 ) ) ;
F_47 ( 200 ) ;
F_46 ( V_77 , V_109 , sizeof( V_109 ) ) ;
F_46 ( V_77 , V_111 , sizeof( V_111 ) ) ;
F_46 ( V_77 , V_113 , sizeof( V_113 ) ) ;
F_46 ( V_77 , V_115 , sizeof( V_115 ) ) ;
F_46 ( V_77 , V_117 , sizeof( V_117 ) ) ;
return 0 ;
}
static int F_48 ( struct V_106 * V_77 )
{
static T_1 V_107 [] = { V_108 , 0x38 , 0x29 } ;
static T_1 V_109 [] = { V_110 , 0x80 } ;
static T_1 V_111 [] = { V_112 , 0x40 } ;
static T_1 V_113 [] = { V_114 , 0x24 , 0x20 } ;
static T_1 V_115 [] = { V_116 , 0x33 } ;
static T_1 V_117 [] = { V_118 , 0x32 } ;
F_46 ( V_77 , V_107 , sizeof( V_107 ) ) ;
F_47 ( 200 ) ;
F_46 ( V_77 , V_109 , sizeof( V_109 ) ) ;
F_46 ( V_77 , V_111 , sizeof( V_111 ) ) ;
F_46 ( V_77 , V_113 , sizeof( V_113 ) ) ;
F_46 ( V_77 , V_115 , sizeof( V_115 ) ) ;
F_46 ( V_77 , V_117 , sizeof( V_117 ) ) ;
return 0 ;
}
static int F_49 ( struct V_61 * V_31 )
{
F_50 ( V_119 , V_31 -> V_120 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , 0x61 ,
V_121 ) ;
return 0 ;
}
static int F_51 ( struct V_61 * V_31 )
{
F_50 ( V_122 , V_31 -> V_120 [ 0 ] . V_77 , 0x61 ,
NULL , V_123 ) ;
return 0 ;
}
static int F_52 ( struct V_61 * V_31 )
{
F_50 ( V_122 , V_31 -> V_120 [ 0 ] . V_77 , 0x61 , NULL , V_124 ) ;
return 0 ;
}
static int F_53 ( struct V_61 * V_31 )
{
F_50 ( V_122 , V_31 -> V_120 [ 0 ] . V_77 , 0x60 ,
NULL , V_123 ) ;
return 0 ;
}
static int F_54 ( struct V_61 * V_31 )
{
F_50 ( V_119 , V_31 -> V_120 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , 0x61 , V_125 ) ;
return 0 ;
}
static int F_55 ( void * V_126 , int V_127 ,
int V_128 , int V_129 )
{
struct V_61 * V_31 = V_126 ;
struct V_1 * V_2 = V_31 -> V_62 ;
switch ( V_128 ) {
case V_130 :
F_6 ( L_10 , V_105 , V_129 ) ;
F_8 ( V_2 , 0x01 , 1 ) ;
break;
case V_131 :
F_6 ( L_11 , V_105 , V_129 ) ;
break;
default:
F_6 ( L_12 , V_105 ,
V_128 , V_129 ) ;
return - V_132 ;
}
return 0 ;
}
static int F_56 ( struct V_61 * V_31 )
{
struct V_106 * V_77 ;
struct V_133 V_134 = {
. V_93 = & V_31 -> V_62 -> V_93 ,
. V_135 = 0x61 ,
} ;
static struct V_136 V_137 = {
. V_138 = V_139 ,
. V_140 = 64 ,
. V_141 = V_142 ,
} ;
V_31 -> V_120 [ 0 ] . V_77 -> V_143 = F_55 ;
V_77 = F_50 ( V_144 , V_31 -> V_120 [ 0 ] . V_77 , & V_134 ) ;
if ( V_77 == NULL || V_77 -> V_145 . V_146 . V_147 == NULL )
return - V_29 ;
V_77 -> V_145 . V_146 . V_147 ( V_77 , & V_137 ) ;
return 0 ;
}
static int F_57 ( struct V_61 * V_31 )
{
F_50 ( V_148 , V_31 -> V_120 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , & V_149 ) ;
return 0 ;
}
static int F_58 ( struct V_61 * V_31 )
{
struct V_106 * V_77 ;
V_77 = F_50 ( V_148 , V_31 -> V_120 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , & V_150 ) ;
return ( V_77 == NULL ) ? - V_29 : 0 ;
}
static int F_59 ( struct V_61 * V_31 )
{
struct V_106 * V_77 ;
V_77 = F_50 ( V_151 , V_31 -> V_120 [ 0 ] . V_77 ,
& V_31 -> V_62 -> V_93 , & V_152 ) ;
return ( V_77 == NULL ) ? - V_29 : 0 ;
}
static int F_60 ( struct V_61 * V_31 )
{
T_1 V_54 ;
if ( F_22 ( V_31 -> V_62 -> V_38 , 0 , 6 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , & V_54 , 1 ) ;
V_31 -> V_120 [ 0 ] . V_77 = F_50 ( V_153 , & V_154 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_120 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_61 ( struct V_61 * V_31 )
{
if ( F_22 ( V_31 -> V_62 -> V_38 , 0 , 7 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
V_31 -> V_120 [ 0 ] . V_77 = F_50 ( V_155 ,
& V_156 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_120 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_62 ( struct V_61 * V_31 )
{
V_31 -> V_120 [ 0 ] . V_77 = F_50 ( V_155 , & V_157 ,
& V_31 -> V_62 -> V_93 ) ;
if ( V_31 -> V_120 [ 0 ] . V_77 != NULL )
return 0 ;
return - V_29 ;
}
static int F_63 ( struct V_61 * V_31 )
{
if ( F_22 ( V_31 -> V_62 -> V_38 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
V_31 -> V_120 [ 0 ] . V_77 = F_50 ( V_158 , & V_159 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_120 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_64 ( struct V_61 * V_31 )
{
if ( F_22 ( V_31 -> V_62 -> V_38 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
V_31 -> V_120 [ 0 ] . V_77 = F_50 ( V_158 , & V_160 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_120 [ 0 ] . V_77 ) != NULL )
return 0 ;
V_31 -> V_120 [ 0 ] . V_77 = F_50 ( V_161 ,
& V_162 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_120 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_65 ( struct V_61 * V_31 )
{
T_1 V_87 [ 4 ] ;
int V_17 ;
struct V_32 V_33 = { . V_28 = 0x6b , . V_42 = V_43 ,
. V_49 = V_87 , . V_46 = 4 } ;
if ( F_22 ( V_31 -> V_62 -> V_38 , 0 , 1 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
F_7 ( V_31 -> V_62 , 0x04 , 0 ) ;
F_8 ( V_31 -> V_62 , 0x01 , 1 ) ;
F_8 ( V_31 -> V_62 , 0x02 , 1 ) ;
V_31 -> V_120 [ 0 ] . V_77 =
F_50 ( V_161 ,
& V_163 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_120 [ 0 ] . V_77 ) == NULL )
return - V_29 ;
for ( V_17 = 0 ; V_31 -> V_62 -> V_68 . V_24 . V_86 . V_84 != NULL && V_17 < 5 ; V_17 ++ ) {
F_9 ( 20 ) ;
if ( F_13 ( & V_31 -> V_62 -> V_93 , & V_33 , 1 ) != 1 )
goto V_164;
if ( V_87 [ 0 ] == 0 && V_87 [ 1 ] == 0 )
continue;
if ( V_87 [ 2 ] + V_87 [ 3 ] != 0xff ) {
V_164:
V_31 -> V_62 -> V_68 . V_24 . V_86 . V_84 = NULL ;
F_66 ( L_13 ) ;
break;
}
}
return 0 ;
}
static int F_67 ( struct V_61 * V_31 )
{
struct V_165 * V_57 = V_31 -> V_15 ;
if ( F_22 ( V_31 -> V_62 -> V_38 , 0 , 1 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
F_8 ( V_31 -> V_62 , 0x02 , 1 ) ;
if ( ! F_50 ( V_166 , & V_57 -> V_167 ) )
return - V_168 ;
if ( V_57 -> V_167 . V_169 ( & V_31 -> V_62 -> V_93 , 1 , 18 ,
& V_170 ) < 0 ) {
F_68 ( V_171 L_14 ) ;
return - V_168 ;
}
V_31 -> V_120 [ 0 ] . V_77 = V_57 -> V_167 . V_172 ( & V_31 -> V_62 -> V_93 , 0x80 ,
& V_170 ) ;
if ( V_31 -> V_120 [ 0 ] . V_77 == NULL )
return - V_29 ;
return 0 ;
}
static int F_69 ( struct V_106 * V_77 , int V_12 )
{
struct V_61 * V_31 = V_77 -> V_173 -> V_15 ;
struct V_165 * V_57 = V_31 -> V_15 ;
return V_57 -> V_167 . V_174 ( V_77 , 8 , 0 , ! V_12 ) ;
}
static int F_70 ( struct V_106 * V_77 , int V_12 )
{
return 0 ;
}
static int F_71 ( struct V_106 * V_77 )
{
struct V_175 * V_76 = & V_77 -> V_176 ;
struct V_61 * V_31 = V_77 -> V_173 -> V_15 ;
struct V_165 * V_57 = V_31 -> V_15 ;
T_3 V_177 ;
T_1 V_178 = F_72 ( V_76 -> V_179 / 1000 ) ;
switch ( V_178 ) {
case V_180 : V_177 = 950 ; break;
default:
case V_181 : V_177 = 550 ; break;
}
V_57 -> V_167 . V_182 ( V_77 , V_177 + F_73 ( V_77 ) ) ;
return V_57 -> V_183 ( V_77 ) ;
}
static int F_74 ( struct V_61 * V_31 )
{
struct V_165 * V_14 = V_31 -> V_15 ;
struct V_30 * V_184 ;
V_184 = V_14 -> V_167 . V_185 ( V_31 -> V_120 [ 0 ] . V_77 ,
V_186 , 1 ) ;
if ( F_50 ( V_187 , V_31 -> V_120 [ 0 ] . V_77 , V_184 ,
& V_188 ) == NULL )
return - V_168 ;
V_14 -> V_183 = V_31 -> V_120 [ 0 ] . V_77 -> V_145 . V_146 . V_189 ;
V_31 -> V_120 [ 0 ] . V_77 -> V_145 . V_146 . V_189 = F_71 ;
return 0 ;
}
static int F_75 ( struct V_61 * V_31 )
{
if ( F_22 ( V_31 -> V_62 -> V_38 , 0 , 1 ) < 0 )
F_23 ( L_8 ) ;
F_1 ( V_31 -> V_62 , V_60 , NULL , 0 , NULL , 0 ) ;
F_7 ( V_31 -> V_62 , 0x04 , 0 ) ;
F_8 ( V_31 -> V_62 , 0x01 , 1 ) ;
F_8 ( V_31 -> V_62 , 0x02 , 1 ) ;
V_31 -> V_120 [ 0 ] . V_77 = F_50 ( V_161 ,
& V_190 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_120 [ 0 ] . V_77 ) != NULL )
return 0 ;
V_31 -> V_120 [ 0 ] . V_77 = F_50 ( V_158 ,
& V_191 ,
& V_31 -> V_62 -> V_93 ) ;
if ( ( V_31 -> V_120 [ 0 ] . V_77 ) != NULL )
return 0 ;
return - V_29 ;
}
static int F_76 ( struct V_61 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_62 ;
int V_192 ;
if ( F_22 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_77 ( V_2 -> V_38 ,
F_78 ( V_2 -> V_38 , V_2 -> V_68 . V_69 ) ) ;
F_77 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_2 -> V_68 . V_69 ) ) ;
F_77 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_2 -> V_68 . V_52 [ 0 ] . V_77 [ 0 ] . V_78 . V_82 ) ) ;
for ( V_192 = 0 ; V_192 < 5 ; V_192 ++ ) {
F_29 ( V_2 ) ;
F_34 ( V_2 ) ;
F_9 ( 200 ) ;
}
if ( F_11 ( V_2 , 0x07 , 0 ) < 0 ) {
F_23 ( L_15 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
if ( F_11 ( V_2 , 0x07 , 1 ) < 0 ) {
F_23 ( L_16 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
V_31 -> V_120 [ 0 ] . V_77 = F_50 ( V_193 , & V_194 , & V_2 -> V_93 ) ;
if ( V_31 -> V_120 [ 0 ] . V_77 == NULL )
return - V_29 ;
return 0 ;
}
static int F_79 ( struct V_61 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_62 ;
if ( F_22 ( V_2 -> V_38 , 0 , 0 ) < 0 )
F_23 ( L_8 ) ;
F_77 ( V_2 -> V_38 ,
F_78 ( V_2 -> V_38 , V_2 -> V_68 . V_69 ) ) ;
F_77 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_2 -> V_68 . V_69 ) ) ;
F_77 ( V_2 -> V_38 ,
F_32 ( V_2 -> V_38 , V_2 -> V_68 . V_52 [ 0 ] . V_77 [ 0 ] . V_78 . V_82 ) ) ;
if ( F_11 ( V_2 , 0x07 , 0 ) < 0 ) {
F_23 ( L_15 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
if ( F_11 ( V_2 , 0x07 , 1 ) < 0 ) {
F_23 ( L_16 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
V_31 -> V_120 [ 0 ] . V_77 = F_50 ( V_195 , & V_196 ,
& V_2 -> V_93 ) ;
if ( V_31 -> V_120 [ 0 ] . V_77 == NULL )
return - V_29 ;
return 0 ;
}
static int F_80 ( struct V_61 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_62 ;
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_30 * V_52 ;
struct V_197 * V_198 ;
struct V_197 * V_199 ;
struct V_197 * V_200 ;
struct V_201 F_66 ;
struct V_202 V_202 ;
struct V_203 V_203 ;
struct V_204 V_204 ;
T_1 V_16 [ 2 ] , V_17 ;
if ( F_12 ( V_2 , 0 ) < 0 ) {
F_23 ( L_15 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
if ( F_12 ( V_2 , 1 ) < 0 ) {
F_23 ( L_16 ) ;
return - V_29 ;
}
F_9 ( 100 ) ;
V_202 . V_30 = & V_52 ;
V_202 . V_77 = & V_31 -> V_120 [ 0 ] . V_77 ;
V_202 . V_205 = V_206 ;
memset ( & F_66 , 0 , sizeof( struct V_201 ) ) ;
F_81 ( F_66 . type , L_17 , V_207 ) ;
F_66 . V_28 = 0x64 ;
F_66 . V_208 = & V_202 ;
F_82 ( F_66 . type ) ;
V_198 = F_83 ( & V_2 -> V_93 , & F_66 ) ;
if ( V_198 == NULL || V_198 -> V_62 . V_209 == NULL )
return - V_168 ;
if ( ! F_84 ( V_198 -> V_62 . V_209 -> V_210 ) ) {
F_85 ( V_198 ) ;
return - V_168 ;
}
V_14 -> V_211 = V_198 ;
memset ( & V_203 , 0 , sizeof( V_203 ) ) ;
V_203 . V_77 = V_31 -> V_120 [ 0 ] . V_77 ;
memset ( & F_66 , 0 , sizeof( struct V_201 ) ) ;
F_81 ( F_66 . type , L_18 , V_207 ) ;
F_66 . V_28 = 0x60 ;
F_66 . V_208 = & V_203 ;
F_82 ( F_66 . type ) ;
V_199 = F_83 ( V_52 , & F_66 ) ;
if ( V_199 == NULL || V_199 -> V_62 . V_209 == NULL ) {
F_86 ( V_198 -> V_62 . V_209 -> V_210 ) ;
F_85 ( V_198 ) ;
return - V_168 ;
}
if ( ! F_84 ( V_199 -> V_62 . V_209 -> V_210 ) ) {
F_85 ( V_199 ) ;
F_86 ( V_198 -> V_62 . V_209 -> V_210 ) ;
F_85 ( V_198 ) ;
return - V_168 ;
}
V_14 -> V_212 = V_199 ;
if ( V_2 -> V_38 -> V_39 . V_213 ==
V_214 ) {
memcpy ( V_16 , L_19 , 2 ) ;
F_1 ( V_2 , V_20 , V_16 , 2 , & V_17 , 1 ) ;
F_9 ( 100 ) ;
memcpy ( V_16 , L_20 , 2 ) ;
F_1 ( V_2 , V_20 , V_16 , 2 , & V_17 , 1 ) ;
F_9 ( 100 ) ;
memset ( & V_204 , 0 , sizeof( V_204 ) ) ;
V_204 . V_215 = & V_31 -> V_215 ;
V_204 . V_15 = V_2 ;
V_204 . V_216 = F_44 ;
memset ( & F_66 , 0 , sizeof( struct V_201 ) ) ;
F_81 ( F_66 . type , L_21 , V_207 ) ;
F_66 . V_28 = 0x40 ;
F_66 . V_208 = & V_204 ;
F_82 ( F_66 . type ) ;
V_200 = F_83 ( & V_2 -> V_93 , & F_66 ) ;
if ( V_200 == NULL || V_200 -> V_62 . V_209 == NULL ) {
F_86 ( V_199 -> V_62 . V_209 -> V_210 ) ;
F_85 ( V_199 ) ;
F_86 ( V_198 -> V_62 . V_209 -> V_210 ) ;
F_85 ( V_198 ) ;
return - V_168 ;
}
if ( ! F_84 ( V_200 -> V_62 . V_209 -> V_210 ) ) {
F_85 ( V_200 ) ;
F_86 ( V_199 -> V_62 . V_209 -> V_210 ) ;
F_85 ( V_199 ) ;
F_86 ( V_198 -> V_62 . V_209 -> V_210 ) ;
F_85 ( V_198 ) ;
return - V_168 ;
}
V_14 -> V_217 = V_200 ;
}
return 0 ;
}
static int F_87 ( struct V_218 * V_38 ,
struct V_219 * V_68 ,
struct V_220 * * V_221 ,
int * V_222 )
{
int V_223 = * V_222 ;
* V_222 = V_38 -> V_39 . V_224 == 0xff &&
V_38 -> V_39 . V_225 == 0xff &&
V_38 -> V_39 . V_226 == 0xff ;
if ( * V_222 && ! V_223 )
* V_221 = NULL ;
return 0 ;
}
static int F_88 ( struct V_218 * V_38 ,
const struct V_227 * V_228 )
{
int V_229 ;
for ( V_229 = 0 ; V_229 < F_89 ( V_230 ) ; V_229 ++ ) {
int V_231 = V_230 [ V_229 ] ;
if ( V_228 -> V_232 < V_231 + 4 )
continue;
if ( V_228 -> V_101 [ V_231 ] == ( V_233 & 0xff ) &&
V_228 -> V_101 [ V_231 + 1 ] == V_233 >> 8 ) {
struct V_227 V_234 ;
T_1 * V_235 = F_90 ( V_228 -> V_232 ) ;
int V_35 ;
if ( ! V_235 )
return - V_236 ;
memcpy ( V_235 , V_228 -> V_101 , V_228 -> V_232 ) ;
V_234 . V_232 = V_228 -> V_232 ;
V_234 . V_101 = V_235 ;
V_235 [ V_231 + 2 ] =
F_16 ( V_38 -> V_39 . V_213 ) + 1 ;
V_235 [ V_231 + 3 ] =
F_16 ( V_38 -> V_39 . V_213 ) >> 8 ;
V_35 = F_91 ( V_38 , & V_234 ,
V_237 ) ;
F_92 ( V_235 ) ;
return V_35 ;
}
}
return - V_132 ;
}
static int F_93 ( struct V_238 * V_239 ,
const struct V_240 * V_241 )
{
if ( 0 == F_94 ( V_239 , & V_242 ,
V_243 , NULL , V_244 ) ||
0 == F_94 ( V_239 , & V_245 ,
V_243 , NULL , V_244 ) ||
0 == F_94 ( V_239 , & V_246 ,
V_243 , NULL , V_244 ) ||
0 == F_94 ( V_239 , & V_247 ,
V_243 , NULL , V_244 ) ||
0 == F_94 ( V_239 , & V_248 ,
V_243 , NULL , V_244 ) ||
0 == F_94 ( V_239 , & V_249 ,
V_243 , NULL , V_244 ) ||
0 == F_94 ( V_239 , & V_250 ,
V_243 , NULL , V_244 ) ||
0 == F_94 ( V_239 ,
& V_251 ,
V_243 , NULL , V_244 ) ||
0 == F_94 ( V_239 , & V_252 ,
V_243 , NULL , V_244 ) ||
0 == F_94 ( V_239 ,
& V_253 ,
V_243 , NULL , V_244 ) ||
0 == F_94 ( V_239 , & V_254 ,
V_243 , NULL , V_244 ) ||
0 == F_94 ( V_239 , & V_255 ,
V_243 , NULL , V_244 ) ||
0 == F_94 ( V_239 , & V_256 ,
V_243 , NULL , V_244 ) ||
0 )
return 0 ;
return - V_132 ;
}
static void F_95 ( struct V_238 * V_239 )
{
struct V_1 * V_2 = F_96 ( V_239 ) ;
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_197 * V_257 ;
V_257 = V_14 -> V_217 ;
if ( V_257 ) {
F_86 ( V_257 -> V_62 . V_209 -> V_210 ) ;
F_85 ( V_257 ) ;
}
V_257 = V_14 -> V_212 ;
if ( V_257 ) {
F_86 ( V_257 -> V_62 . V_209 -> V_210 ) ;
F_85 ( V_257 ) ;
}
V_257 = V_14 -> V_211 ;
if ( V_257 ) {
F_86 ( V_257 -> V_62 . V_209 -> V_210 ) ;
F_85 ( V_257 ) ;
}
F_97 ( V_239 ) ;
}
