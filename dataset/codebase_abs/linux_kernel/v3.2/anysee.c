static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 V_4 ,
T_1 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 , V_11 ;
T_1 V_12 [ 64 ] ;
memcpy ( & V_12 [ 0 ] , V_3 , V_4 ) ;
V_12 [ 60 ] = V_8 -> V_13 ++ ;
if ( F_2 ( & V_14 ) < 0 )
return - V_15 ;
V_11 = F_3 ( V_2 , V_12 , sizeof( V_12 ) , V_12 , sizeof( V_12 ) , 0 ) ;
if ( ! V_11 ) {
V_11 = F_4 ( V_2 -> V_16 , F_5 ( V_2 -> V_16 ,
V_2 -> V_17 . V_18 ) , V_12 , sizeof( V_12 ) ,
& V_10 , 2000 ) ;
if ( V_11 )
F_6 ( L_1 , V_19 , V_11 ) ;
else {
F_7 ( L_2 ) ;
F_8 ( V_12 , V_10 , F_7 ) ;
}
}
if ( ! V_11 && V_5 && V_6 )
memcpy ( V_5 , V_12 , V_6 ) ;
F_9 ( & V_14 ) ;
return V_11 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_20 , T_1 * V_21 )
{
T_1 V_12 [] = { V_22 , V_20 >> 8 , V_20 & 0xff , 0x01 } ;
int V_11 ;
V_11 = F_1 ( V_2 , V_12 , sizeof( V_12 ) , V_21 , 1 ) ;
F_11 ( L_3 , V_19 , V_20 , * V_21 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_20 , T_1 V_21 )
{
T_1 V_12 [] = { V_23 , V_20 >> 8 , V_20 & 0xff , 0x01 , V_21 } ;
F_11 ( L_3 , V_19 , V_20 , V_21 ) ;
return F_1 ( V_2 , V_12 , sizeof( V_12 ) , NULL , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_20 , T_1 V_21 ,
T_1 V_24 )
{
int V_11 ;
T_1 V_25 ;
if ( V_24 != 0xff ) {
V_11 = F_10 ( V_2 , V_20 , & V_25 ) ;
if ( V_11 )
return V_11 ;
V_21 &= V_24 ;
V_25 &= ~ V_24 ;
V_21 |= V_25 ;
}
return F_12 ( V_2 , V_20 , V_21 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_26 )
{
T_1 V_12 [] = { V_27 } ;
return F_1 ( V_2 , V_12 , sizeof( V_12 ) , V_26 , 3 ) ;
}
static int F_15 ( struct V_28 * V_29 , int V_30 )
{
T_1 V_12 [] = { V_31 , ( T_1 ) V_30 , 0x00 } ;
F_11 ( L_4 , V_19 , V_30 ) ;
return F_1 ( V_29 -> V_32 , V_12 , sizeof( V_12 ) , NULL , 0 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_33 , T_1 V_34 )
{
T_1 V_12 [] = { V_35 , 0x01 , V_33 , V_34 } ;
F_11 ( L_5 , V_19 , V_33 , V_34 ) ;
return F_1 ( V_2 , V_12 , sizeof( V_12 ) , NULL , 0 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_30 )
{
T_1 V_12 [] = { V_35 , 0x02 , V_30 } ;
F_11 ( L_4 , V_19 , V_30 ) ;
return F_1 ( V_2 , V_12 , sizeof( V_12 ) , NULL , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_16 ( V_2 , 0x01 , 0x03 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_17 ( V_2 , 1 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_19 ( struct V_36 * V_29 , struct V_37 * V_38 ,
int V_39 )
{
struct V_1 * V_2 = F_20 ( V_29 ) ;
int V_11 = 0 , V_40 , V_41 = 0 ;
T_1 V_12 [ 52 ] ;
if ( F_2 ( & V_2 -> V_42 ) < 0 )
return - V_15 ;
while ( V_41 < V_39 ) {
if ( V_39 > V_41 + 1 && ( V_38 [ V_41 + 1 ] . V_43 & V_44 ) ) {
if ( V_38 [ V_41 ] . V_45 > 2 || V_38 [ V_41 + 1 ] . V_45 > 60 ) {
V_11 = - V_46 ;
break;
}
V_12 [ 0 ] = V_47 ;
V_12 [ 1 ] = ( V_38 [ V_41 ] . V_48 << 1 ) | 0x01 ;
V_12 [ 2 ] = V_38 [ V_41 ] . V_12 [ 0 ] ;
V_12 [ 3 ] = V_38 [ V_41 ] . V_12 [ 1 ] ;
V_12 [ 4 ] = V_38 [ V_41 ] . V_45 - 1 ;
V_12 [ 5 ] = V_38 [ V_41 + 1 ] . V_45 ;
V_11 = F_1 ( V_2 , V_12 , 6 , V_38 [ V_41 + 1 ] . V_12 ,
V_38 [ V_41 + 1 ] . V_45 ) ;
V_40 = 2 ;
} else {
if ( V_38 [ V_41 ] . V_45 > 48 ) {
V_11 = - V_46 ;
break;
}
V_12 [ 0 ] = V_49 ;
V_12 [ 1 ] = ( V_38 [ V_41 ] . V_48 << 1 ) ;
V_12 [ 2 ] = V_38 [ V_41 ] . V_45 ;
V_12 [ 3 ] = 0x01 ;
memcpy ( & V_12 [ 4 ] , V_38 [ V_41 ] . V_12 , V_38 [ V_41 ] . V_45 ) ;
V_11 = F_1 ( V_2 , V_12 , 4 + V_38 [ V_41 ] . V_45 , NULL , 0 ) ;
V_40 = 1 ;
}
if ( V_11 )
break;
V_41 += V_40 ;
}
F_9 ( & V_2 -> V_42 ) ;
return V_11 ? V_11 : V_41 ;
}
static T_3 F_21 ( struct V_36 * V_50 )
{
return V_51 ;
}
static int F_22 ( struct V_52 * V_53 )
{
static T_1 V_54 [] = { V_55 , 0x38 , 0x28 } ;
static T_1 V_56 [] = { V_57 , 0x80 } ;
static T_1 V_58 [] = { V_59 , 0x40 } ;
static T_1 V_60 [] = { V_61 , 0x28 , 0x20 } ;
static T_1 V_62 [] = { V_63 , 0x33 } ;
static T_1 V_64 [] = { V_65 , 0x32 } ;
F_23 ( V_53 , V_54 , sizeof( V_54 ) ) ;
F_24 ( 200 ) ;
F_23 ( V_53 , V_56 , sizeof( V_56 ) ) ;
F_23 ( V_53 , V_58 , sizeof( V_58 ) ) ;
F_23 ( V_53 , V_60 , sizeof( V_60 ) ) ;
F_23 ( V_53 , V_62 , sizeof( V_62 ) ) ;
F_23 ( V_53 , V_64 , sizeof( V_64 ) ) ;
return 0 ;
}
static int F_25 ( struct V_52 * V_53 , int V_30 )
{
struct V_28 * V_29 = V_53 -> V_66 -> V_9 ;
struct V_7 * V_8 = V_29 -> V_32 -> V_9 ;
int V_11 ;
F_11 ( L_6 , V_19 , V_53 -> V_26 , V_30 ) ;
if ( V_30 == 0 )
return 0 ;
switch ( V_8 -> V_67 ) {
case V_68 :
if ( ( V_53 -> V_26 ^ V_69 ) == 0 ) {
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 0 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 1 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_71 , ( 1 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
} else {
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 0 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 1 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_71 , ( 0 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
}
break;
case V_72 :
case V_73 :
if ( ( V_53 -> V_26 ^ V_69 ) == 0 ) {
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 0 << 6 ) ,
0x40 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 1 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_71 , ( 1 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
} else {
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 0 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 1 << 6 ) ,
0x40 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_71 , ( 0 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
}
break;
default:
V_11 = 0 ;
}
error:
return V_11 ;
}
static int F_26 ( struct V_28 * V_29 )
{
int V_11 ;
struct V_7 * V_8 = V_29 -> V_32 -> V_9 ;
T_1 V_74 [ 3 ] ;
T_1 V_25 ;
struct V_37 V_38 [ 2 ] = {
{
. V_48 = V_75 . V_76 ,
. V_43 = 0 ,
. V_45 = 1 ,
. V_12 = L_7 ,
} , {
. V_48 = V_75 . V_76 ,
. V_43 = V_44 ,
. V_45 = 1 ,
. V_12 = & V_25 ,
}
} ;
if ( V_29 -> V_77 [ 0 ] . V_53 == NULL ) {
V_11 = F_14 ( V_29 -> V_32 , V_74 ) ;
if ( V_11 )
goto error;
V_11 = F_14 ( V_29 -> V_32 , V_74 ) ;
if ( V_11 )
goto error;
F_27 ( L_8 ,
V_74 [ 1 ] , V_74 [ 2 ] , V_74 [ 0 ] ) ;
V_8 -> V_67 = V_74 [ 0 ] ;
}
if ( V_29 -> V_77 [ 0 ] . V_53 )
V_8 -> V_78 ++ ;
switch ( V_8 -> V_67 ) {
case V_79 :
if ( V_8 -> V_78 )
break;
V_29 -> V_77 [ 0 ] . V_53 = F_28 ( V_80 , & V_81 ,
& V_29 -> V_32 -> V_82 ) ;
if ( V_29 -> V_77 [ 0 ] . V_53 )
break;
V_29 -> V_77 [ 0 ] . V_53 = F_28 ( V_83 , & V_84 ,
& V_29 -> V_32 -> V_82 ) ;
break;
case V_85 :
if ( V_8 -> V_78 )
break;
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 1 << 0 ) , 0x01 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_86 , ( 0 << 7 ) , 0x80 ) ;
if ( V_11 )
goto error;
V_29 -> V_77 [ 0 ] . V_53 = F_28 ( V_83 ,
& V_84 , & V_29 -> V_32 -> V_82 ) ;
break;
case V_87 :
if ( V_8 -> V_78 )
break;
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 1 << 0 ) , 0x01 ) ;
if ( V_11 )
goto error;
V_29 -> V_77 [ 0 ] . V_53 = F_28 ( V_88 ,
& V_89 , & V_29 -> V_32 -> V_82 , 0x48 ) ;
break;
case V_90 :
if ( V_8 -> V_78 )
break;
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 1 << 0 ) , 0x01 ) ;
if ( V_11 )
goto error;
V_29 -> V_77 [ 0 ] . V_53 = F_28 ( V_91 , & V_92 ,
& V_29 -> V_32 -> V_82 ) ;
break;
case V_68 :
V_11 = F_13 ( V_29 -> V_32 , V_71 , ( 1 << 4 ) , 0x10 ) ;
if ( V_11 )
goto error;
V_25 = 0 ;
V_11 = F_29 ( & V_29 -> V_32 -> V_82 , V_38 , 2 ) ;
if ( V_11 == 2 && V_25 == 0xc7 )
F_11 ( L_9 , V_19 ) ;
else
V_25 = 0 ;
V_11 = F_13 ( V_29 -> V_32 , V_71 , ( 0 << 4 ) , 0x10 ) ;
if ( V_11 )
goto error;
if ( ( V_8 -> V_78 ^ V_69 ) == 0 ) {
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 0 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 1 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
if ( V_25 == 0xc7 ) {
V_29 -> V_77 [ V_8 -> V_78 ] . V_53 = F_28 (
V_88 ,
& V_93 ,
& V_29 -> V_32 -> V_82 , 0x48 ) ;
} else {
V_29 -> V_77 [ V_8 -> V_78 ] . V_53 = F_28 (
V_88 ,
& V_89 ,
& V_29 -> V_32 -> V_82 , 0x48 ) ;
}
} else {
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 0 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 1 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
if ( V_25 == 0xc7 ) {
V_29 -> V_77 [ V_8 -> V_78 ] . V_53 = F_28 (
V_83 ,
& V_94 ,
& V_29 -> V_32 -> V_82 ) ;
} else {
V_29 -> V_77 [ V_8 -> V_78 ] . V_53 = F_28 (
V_83 ,
& V_84 ,
& V_29 -> V_32 -> V_82 ) ;
}
}
break;
case V_72 :
case V_73 :
V_11 = F_13 ( V_29 -> V_32 , V_86 , ( 1 << 7 ) , 0x80 ) ;
if ( V_11 )
goto error;
if ( ( V_8 -> V_78 ^ V_69 ) == 0 ) {
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 0 << 6 ) ,
0x40 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 1 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_29 -> V_77 [ V_8 -> V_78 ] . V_53 = F_28 ( V_88 ,
& V_93 ,
& V_29 -> V_32 -> V_82 , 0x48 ) ;
} else {
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 0 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_70 , ( 1 << 6 ) ,
0x40 ) ;
if ( V_11 )
goto error;
V_29 -> V_77 [ V_8 -> V_78 ] . V_53 = F_28 ( V_83 ,
& V_95 ,
& V_29 -> V_32 -> V_82 ) ;
}
break;
case V_96 :
case V_97 :
if ( V_8 -> V_78 )
break;
V_11 = F_13 ( V_29 -> V_32 , V_86 , ( 1 << 7 ) , 0x80 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_29 -> V_32 , V_71 , ( 1 << 5 ) , 0x20 ) ;
if ( V_11 )
goto error;
V_29 -> V_77 [ 0 ] . V_53 = F_28 ( V_98 , & V_99 ,
& V_29 -> V_32 -> V_82 , 0 ) ;
break;
}
if ( ! V_29 -> V_77 [ 0 ] . V_53 ) {
V_11 = - V_100 ;
F_6 ( L_10 \
L_11 ) ;
}
error:
return V_11 ;
}
static int F_30 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = V_29 -> V_32 -> V_9 ;
struct V_52 * V_53 ;
int V_11 ;
F_11 ( L_12 , V_19 , V_8 -> V_78 ) ;
switch ( V_8 -> V_67 ) {
case V_79 :
V_53 = F_28 ( V_101 , V_29 -> V_77 [ 0 ] . V_53 , ( 0xc2 >> 1 ) ,
NULL , V_102 ) ;
break;
case V_85 :
V_53 = F_28 ( V_101 , V_29 -> V_77 [ 0 ] . V_53 , ( 0xc2 >> 1 ) ,
& V_29 -> V_32 -> V_82 , V_102 ) ;
break;
case V_87 :
V_53 = F_28 ( V_101 , V_29 -> V_77 [ 0 ] . V_53 , ( 0xc0 >> 1 ) ,
& V_29 -> V_32 -> V_82 , V_103 ) ;
break;
case V_90 :
V_53 = F_28 ( V_104 , V_29 -> V_77 [ 0 ] . V_53 ,
& V_29 -> V_32 -> V_82 , & V_105 ) ;
break;
case V_68 :
V_11 = F_13 ( V_29 -> V_32 , V_71 , ( 1 << 4 ) , 0x10 ) ;
if ( V_11 )
goto error;
V_53 = F_28 ( V_106 , V_29 -> V_77 [ V_8 -> V_78 ] . V_53 ,
& V_29 -> V_32 -> V_82 , & V_75 ) ;
if ( V_53 )
break;
V_11 = F_13 ( V_29 -> V_32 , V_71 , ( 0 << 4 ) , 0x10 ) ;
if ( V_11 )
goto error;
V_53 = F_28 ( V_101 , V_29 -> V_77 [ V_8 -> V_78 ] . V_53 ,
( 0xc0 >> 1 ) , & V_29 -> V_32 -> V_82 ,
V_103 ) ;
break;
case V_72 :
case V_73 :
V_11 = F_13 ( V_29 -> V_32 , V_71 , ( 1 << 4 ) , 0x10 ) ;
if ( V_11 )
goto error;
V_53 = F_28 ( V_106 , V_29 -> V_77 [ V_8 -> V_78 ] . V_53 ,
& V_29 -> V_32 -> V_82 , & V_75 ) ;
break;
case V_96 :
case V_97 :
V_53 = F_28 ( V_107 , V_29 -> V_77 [ 0 ] . V_53 ,
& V_108 , & V_29 -> V_32 -> V_82 ) ;
if ( V_53 ) {
V_53 = F_28 ( V_104 , V_29 -> V_77 [ 0 ] . V_53 ,
& V_29 -> V_32 -> V_82 , & V_105 ) ;
}
break;
default:
V_53 = NULL ;
}
if ( V_53 )
V_11 = 0 ;
else
V_11 = - V_100 ;
error:
return V_11 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_12 [] = { V_109 } ;
T_1 V_110 [ 2 ] ;
int V_11 ;
V_11 = F_1 ( V_2 , V_12 , sizeof( V_12 ) , V_110 , sizeof( V_110 ) ) ;
if ( V_11 )
return V_11 ;
if ( V_110 [ 0 ] ) {
F_32 ( L_13 , V_19 , V_110 [ 1 ] ) ;
F_33 ( V_2 -> V_111 , 0x08 << 8 | V_110 [ 1 ] , 0 ) ;
}
return 0 ;
}
static int F_34 ( struct V_112 * V_113 ,
const struct V_114 * V_26 )
{
struct V_1 * V_2 ;
struct V_115 * V_116 ;
int V_11 ;
if ( V_113 -> V_117 < 1 )
return - V_100 ;
V_11 = F_35 ( V_113 , & V_118 , V_119 , & V_2 ,
V_120 ) ;
if ( V_11 )
return V_11 ;
V_116 = F_36 ( V_113 , 0 ) ;
if ( V_116 == NULL ) {
F_11 ( L_14 , V_19 ) ;
return - V_100 ;
}
V_11 = F_37 ( V_2 -> V_16 , V_116 -> V_121 . V_122 ,
V_116 -> V_121 . V_123 ) ;
if ( V_11 )
return V_11 ;
return F_18 ( V_2 ) ;
}
static int T_4 F_38 ( void )
{
int V_11 ;
V_11 = F_39 ( & V_124 ) ;
if ( V_11 )
F_6 ( L_15 , V_19 , V_11 ) ;
return V_11 ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_124 ) ;
}
