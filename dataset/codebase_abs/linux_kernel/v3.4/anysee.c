static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 V_4 ,
T_1 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 , V_11 , V_12 ;
T_1 V_13 [ 64 ] ;
memcpy ( & V_13 [ 0 ] , V_3 , V_4 ) ;
V_13 [ 60 ] = V_8 -> V_14 ++ ;
if ( F_2 ( & V_15 ) < 0 )
return - V_16 ;
F_3 ( L_1 ) ;
F_4 ( V_13 , V_4 , F_3 ) ;
V_11 = F_5 ( V_2 , V_13 , sizeof( V_13 ) , V_13 , sizeof( V_13 ) , 0 ) ;
if ( V_11 )
goto V_17;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
V_11 = F_6 ( V_2 -> V_18 , F_7 ( V_2 -> V_18 ,
V_2 -> V_19 . V_20 ) , V_13 , sizeof( V_13 ) ,
& V_10 , 2000 ) ;
if ( V_11 ) {
F_8 ( L_2 ,
V_21 , V_11 ) ;
} else {
F_3 ( L_3 ) ;
F_4 ( V_13 , V_6 , F_3 ) ;
if ( V_13 [ 63 ] != 0x4f )
F_8 ( L_4 , V_21 ) ;
break;
}
}
if ( V_11 ) {
F_9 ( L_2 , V_21 , V_11 ) ;
goto V_17;
}
if ( V_5 && V_6 )
memcpy ( V_5 , V_13 , V_6 ) ;
V_17:
F_10 ( & V_15 ) ;
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_22 , T_1 * V_23 )
{
T_1 V_13 [] = { V_24 , V_22 >> 8 , V_22 & 0xff , 0x01 } ;
int V_11 ;
V_11 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , V_23 , 1 ) ;
F_8 ( L_5 , V_21 , V_22 , * V_23 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_22 , T_1 V_23 )
{
T_1 V_13 [] = { V_25 , V_22 >> 8 , V_22 & 0xff , 0x01 , V_23 } ;
F_8 ( L_5 , V_21 , V_22 , V_23 ) ;
return F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_22 , T_1 V_23 ,
T_1 V_26 )
{
int V_11 ;
T_1 V_27 ;
if ( V_26 != 0xff ) {
V_11 = F_11 ( V_2 , V_22 , & V_27 ) ;
if ( V_11 )
return V_11 ;
V_23 &= V_26 ;
V_27 &= ~ V_26 ;
V_23 |= V_27 ;
}
return F_12 ( V_2 , V_22 , V_23 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_22 , T_1 * V_23 ,
T_1 V_26 )
{
int V_11 , V_12 ;
T_1 V_27 ;
V_11 = F_11 ( V_2 , V_22 , & V_27 ) ;
if ( V_11 )
return V_11 ;
V_27 &= V_26 ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
if ( ( V_26 >> V_12 ) & 0x01 )
break;
}
* V_23 = V_27 >> V_12 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_28 )
{
T_1 V_13 [] = { V_29 } ;
return F_1 ( V_2 , V_13 , sizeof( V_13 ) , V_28 , 3 ) ;
}
static int F_16 ( struct V_30 * V_31 , int V_32 )
{
T_1 V_13 [] = { V_33 , ( T_1 ) V_32 , 0x00 } ;
F_8 ( L_6 , V_21 , V_32 ) ;
return F_1 ( V_31 -> V_34 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_35 , T_1 V_36 )
{
T_1 V_13 [] = { V_37 , 0x01 , V_35 , V_36 } ;
F_8 ( L_7 , V_21 , V_35 , V_36 ) ;
return F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_32 )
{
T_1 V_13 [] = { V_37 , 0x02 , V_32 } ;
F_8 ( L_6 , V_21 , V_32 ) ;
return F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
}
static int F_19 ( struct V_38 * V_31 , struct V_39 * V_40 ,
int V_41 )
{
struct V_1 * V_2 = F_20 ( V_31 ) ;
int V_11 = 0 , V_42 , V_12 = 0 ;
T_1 V_13 [ 52 ] ;
if ( F_2 ( & V_2 -> V_43 ) < 0 )
return - V_16 ;
while ( V_12 < V_41 ) {
if ( V_41 > V_12 + 1 && ( V_40 [ V_12 + 1 ] . V_44 & V_45 ) ) {
if ( V_40 [ V_12 ] . V_46 > 2 || V_40 [ V_12 + 1 ] . V_46 > 60 ) {
V_11 = - V_47 ;
break;
}
V_13 [ 0 ] = V_48 ;
V_13 [ 1 ] = ( V_40 [ V_12 ] . V_49 << 1 ) | 0x01 ;
V_13 [ 2 ] = V_40 [ V_12 ] . V_13 [ 0 ] ;
V_13 [ 3 ] = V_40 [ V_12 ] . V_13 [ 1 ] ;
V_13 [ 4 ] = V_40 [ V_12 ] . V_46 - 1 ;
V_13 [ 5 ] = V_40 [ V_12 + 1 ] . V_46 ;
V_11 = F_1 ( V_2 , V_13 , 6 , V_40 [ V_12 + 1 ] . V_13 ,
V_40 [ V_12 + 1 ] . V_46 ) ;
V_42 = 2 ;
} else {
if ( V_40 [ V_12 ] . V_46 > 48 ) {
V_11 = - V_47 ;
break;
}
V_13 [ 0 ] = V_50 ;
V_13 [ 1 ] = ( V_40 [ V_12 ] . V_49 << 1 ) ;
V_13 [ 2 ] = V_40 [ V_12 ] . V_46 ;
V_13 [ 3 ] = 0x01 ;
memcpy ( & V_13 [ 4 ] , V_40 [ V_12 ] . V_13 , V_40 [ V_12 ] . V_46 ) ;
V_11 = F_1 ( V_2 , V_13 , 4 + V_40 [ V_12 ] . V_46 , NULL , 0 ) ;
V_42 = 1 ;
}
if ( V_11 )
break;
V_12 += V_42 ;
}
F_10 ( & V_2 -> V_43 ) ;
return V_11 ? V_11 : V_12 ;
}
static T_3 F_21 ( struct V_38 * V_51 )
{
return V_52 ;
}
static int F_22 ( struct V_53 * V_54 )
{
static T_1 V_55 [] = { V_56 , 0x38 , 0x28 } ;
static T_1 V_57 [] = { V_58 , 0x80 } ;
static T_1 V_59 [] = { V_60 , 0x40 } ;
static T_1 V_61 [] = { V_62 , 0x28 , 0x20 } ;
static T_1 V_63 [] = { V_64 , 0x33 } ;
static T_1 V_65 [] = { V_66 , 0x32 } ;
F_23 ( V_54 , V_55 , sizeof( V_55 ) ) ;
F_24 ( 200 ) ;
F_23 ( V_54 , V_57 , sizeof( V_57 ) ) ;
F_23 ( V_54 , V_59 , sizeof( V_59 ) ) ;
F_23 ( V_54 , V_61 , sizeof( V_61 ) ) ;
F_23 ( V_54 , V_63 , sizeof( V_63 ) ) ;
F_23 ( V_54 , V_65 , sizeof( V_65 ) ) ;
return 0 ;
}
static int F_25 ( struct V_53 * V_54 , int V_67 )
{
struct V_30 * V_31 = V_54 -> V_68 -> V_9 ;
return F_13 ( V_31 -> V_34 , V_69 , ( V_67 << 4 ) , 0x10 ) ;
}
static int F_26 ( struct V_53 * V_54 , int V_32 )
{
struct V_30 * V_31 = V_54 -> V_68 -> V_9 ;
struct V_7 * V_8 = V_31 -> V_34 -> V_9 ;
int V_11 ;
F_8 ( L_8 , V_21 , V_54 -> V_28 , V_32 ) ;
if ( V_32 == 0 )
return 0 ;
switch ( V_8 -> V_70 ) {
case V_71 :
if ( ( V_54 -> V_28 ^ V_72 ) == 0 ) {
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 0 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 1 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_69 , ( 1 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
} else {
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 0 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 1 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_69 , ( 0 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
}
break;
case V_74 :
case V_75 :
if ( ( V_54 -> V_28 ^ V_72 ) == 0 ) {
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 0 << 6 ) ,
0x40 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 1 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_69 , ( 1 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
} else {
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 0 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 1 << 6 ) ,
0x40 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_69 , ( 0 << 0 ) ,
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
static int F_27 ( struct V_30 * V_31 )
{
int V_11 ;
struct V_7 * V_8 = V_31 -> V_34 -> V_9 ;
T_1 V_76 [ 3 ] ;
T_1 V_27 ;
struct V_39 V_40 [ 2 ] = {
{
. V_49 = V_77 . V_78 ,
. V_44 = 0 ,
. V_46 = 1 ,
. V_13 = L_9 ,
} , {
. V_49 = V_77 . V_78 ,
. V_44 = V_45 ,
. V_46 = 1 ,
. V_13 = & V_27 ,
}
} ;
if ( V_31 -> V_79 [ 0 ] . V_54 == NULL ) {
V_11 = F_15 ( V_31 -> V_34 , V_76 ) ;
if ( V_11 )
goto error;
V_11 = F_15 ( V_31 -> V_34 , V_76 ) ;
if ( V_11 )
goto error;
F_28 ( L_10 ,
V_76 [ 1 ] , V_76 [ 2 ] , V_76 [ 0 ] ) ;
V_8 -> V_70 = V_76 [ 0 ] ;
}
if ( V_31 -> V_79 [ 0 ] . V_54 )
V_8 -> V_80 ++ ;
switch ( V_8 -> V_70 ) {
case V_81 :
if ( V_8 -> V_80 )
break;
V_31 -> V_79 [ 0 ] . V_54 = F_29 ( V_82 ,
& V_83 , & V_31 -> V_34 -> V_84 ) ;
if ( V_31 -> V_79 [ 0 ] . V_54 )
break;
V_31 -> V_79 [ 0 ] . V_54 = F_29 ( V_85 ,
& V_86 , & V_31 -> V_34 -> V_84 ) ;
break;
case V_87 :
if ( V_8 -> V_80 )
break;
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 1 << 0 ) , 0x01 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_88 , ( 0 << 7 ) , 0x80 ) ;
if ( V_11 )
goto error;
V_31 -> V_79 [ 0 ] . V_54 = F_29 ( V_85 ,
& V_86 , & V_31 -> V_34 -> V_84 ) ;
break;
case V_89 :
if ( V_8 -> V_80 )
break;
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 1 << 0 ) , 0x01 ) ;
if ( V_11 )
goto error;
V_31 -> V_79 [ 0 ] . V_54 = F_29 ( V_90 ,
& V_91 , & V_31 -> V_34 -> V_84 , 0x48 ) ;
break;
case V_92 :
if ( V_8 -> V_80 )
break;
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 1 << 0 ) , 0x01 ) ;
if ( V_11 )
goto error;
V_31 -> V_79 [ 0 ] . V_54 = F_29 ( V_93 ,
& V_94 , & V_31 -> V_34 -> V_84 ) ;
break;
case V_71 :
V_11 = F_13 ( V_31 -> V_34 , V_69 , ( 1 << 4 ) , 0x10 ) ;
if ( V_11 )
goto error;
V_27 = 0 ;
V_11 = F_30 ( & V_31 -> V_34 -> V_84 , V_40 , 2 ) ;
if ( V_11 == 2 && V_27 == 0xc7 )
F_8 ( L_11 , V_21 ) ;
else
V_27 = 0 ;
V_11 = F_13 ( V_31 -> V_34 , V_69 , ( 0 << 4 ) , 0x10 ) ;
if ( V_11 )
goto error;
if ( ( V_8 -> V_80 ^ V_72 ) == 0 ) {
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 0 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 1 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
if ( V_27 == 0xc7 ) {
V_31 -> V_79 [ V_8 -> V_80 ] . V_54 = F_29 (
V_90 ,
& V_95 ,
& V_31 -> V_34 -> V_84 , 0x48 ) ;
} else {
V_31 -> V_79 [ V_8 -> V_80 ] . V_54 = F_29 (
V_90 ,
& V_91 ,
& V_31 -> V_34 -> V_84 , 0x48 ) ;
}
} else {
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 0 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 1 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
if ( V_27 == 0xc7 ) {
V_31 -> V_79 [ V_8 -> V_80 ] . V_54 = F_29 (
V_85 ,
& V_96 ,
& V_31 -> V_34 -> V_84 ) ;
} else {
V_31 -> V_79 [ V_8 -> V_80 ] . V_54 = F_29 (
V_85 ,
& V_86 ,
& V_31 -> V_34 -> V_84 ) ;
}
}
if ( V_27 == 0xc7 ) {
if ( V_31 -> V_79 [ V_8 -> V_80 ] . V_54 )
V_31 -> V_79 [ V_8 -> V_80 ] . V_54 -> V_97 . V_98 =
F_25 ;
}
break;
case V_74 :
case V_75 :
if ( ( V_8 -> V_80 ^ V_72 ) == 0 ) {
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 0 << 6 ) ,
0x40 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 1 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_31 -> V_79 [ V_8 -> V_80 ] . V_54 =
F_29 ( V_90 ,
& V_95 ,
& V_31 -> V_34 -> V_84 , 0x48 ) ;
} else {
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 0 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_31 -> V_34 , V_73 , ( 1 << 6 ) ,
0x40 ) ;
if ( V_11 )
goto error;
V_31 -> V_79 [ V_8 -> V_80 ] . V_54 =
F_29 ( V_85 ,
& V_99 ,
& V_31 -> V_34 -> V_84 ) ;
}
if ( V_31 -> V_79 [ V_8 -> V_80 ] . V_54 )
V_31 -> V_79 [ V_8 -> V_80 ] . V_54 -> V_97 . V_98 =
F_25 ;
V_8 -> V_100 = true ;
break;
case V_101 :
case V_102 :
if ( V_8 -> V_80 )
break;
V_11 = F_13 ( V_31 -> V_34 , V_69 , ( 1 << 5 ) , 0x20 ) ;
if ( V_11 )
goto error;
V_31 -> V_79 [ 0 ] . V_54 = F_29 ( V_103 ,
& V_104 , & V_31 -> V_34 -> V_84 , 0 ) ;
V_8 -> V_100 = true ;
break;
case V_105 :
if ( V_8 -> V_80 )
break;
V_11 = F_13 ( V_31 -> V_34 , V_69 , ( 1 << 5 ) , 0x20 ) ;
if ( V_11 )
goto error;
V_31 -> V_79 [ V_8 -> V_80 ] . V_54 = F_29 ( V_106 ,
& V_107 , & V_31 -> V_34 -> V_84 ) ;
V_8 -> V_100 = true ;
break;
}
if ( ! V_31 -> V_79 [ 0 ] . V_54 ) {
V_11 = - V_108 ;
F_9 ( L_12 \
L_13 ) ;
}
error:
return V_11 ;
}
static int F_31 ( struct V_30 * V_31 )
{
struct V_7 * V_8 = V_31 -> V_34 -> V_9 ;
struct V_53 * V_54 ;
int V_11 ;
F_8 ( L_14 , V_21 , V_8 -> V_80 ) ;
switch ( V_8 -> V_70 ) {
case V_81 :
V_54 = F_29 ( V_109 , V_31 -> V_79 [ 0 ] . V_54 ,
( 0xc2 >> 1 ) , NULL , V_110 ) ;
break;
case V_87 :
V_54 = F_29 ( V_109 , V_31 -> V_79 [ 0 ] . V_54 ,
( 0xc2 >> 1 ) , & V_31 -> V_34 -> V_84 ,
V_110 ) ;
break;
case V_89 :
V_54 = F_29 ( V_109 , V_31 -> V_79 [ 0 ] . V_54 ,
( 0xc0 >> 1 ) , & V_31 -> V_34 -> V_84 ,
V_111 ) ;
break;
case V_92 :
V_54 = F_29 ( V_112 , V_31 -> V_79 [ 0 ] . V_54 ,
& V_31 -> V_34 -> V_84 , & V_113 ) ;
break;
case V_71 :
V_54 = F_29 ( V_114 , V_31 -> V_79 [ V_8 -> V_80 ] . V_54 ,
& V_31 -> V_34 -> V_84 , & V_77 ) ;
if ( V_54 )
break;
V_54 = F_29 ( V_109 , V_31 -> V_79 [ V_8 -> V_80 ] . V_54 ,
( 0xc0 >> 1 ) , & V_31 -> V_34 -> V_84 ,
V_111 ) ;
break;
case V_74 :
case V_75 :
V_54 = F_29 ( V_114 , V_31 -> V_79 [ V_8 -> V_80 ] . V_54 ,
& V_31 -> V_34 -> V_84 , & V_77 ) ;
break;
case V_101 :
case V_102 :
V_54 = F_29 ( V_115 , V_31 -> V_79 [ 0 ] . V_54 ,
& V_116 , & V_31 -> V_34 -> V_84 ) ;
if ( V_54 ) {
V_54 = F_29 ( V_112 , V_31 -> V_79 [ 0 ] . V_54 ,
& V_31 -> V_34 -> V_84 , & V_113 ) ;
}
break;
case V_105 :
V_54 = F_29 ( V_114 , V_31 -> V_79 [ V_8 -> V_80 ] . V_54 ,
& V_31 -> V_34 -> V_84 , & V_117 ) ;
break;
default:
V_54 = NULL ;
}
if ( V_54 )
V_11 = 0 ;
else
V_11 = - V_108 ;
return V_11 ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_1 V_13 [] = { V_118 } ;
T_1 V_119 [ 2 ] ;
int V_11 ;
V_11 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , V_119 , sizeof( V_119 ) ) ;
if ( V_11 )
return V_11 ;
if ( V_119 [ 0 ] ) {
F_33 ( L_15 , V_21 , V_119 [ 1 ] ) ;
F_34 ( V_2 -> V_120 , 0x08 << 8 | V_119 [ 1 ] , 0 ) ;
}
return 0 ;
}
static int F_35 ( struct V_121 * V_122 , int V_123 ,
int V_49 )
{
struct V_1 * V_2 = V_122 -> V_124 ;
int V_11 ;
T_1 V_13 [] = { V_125 , 0x02 , 0x40 | V_49 >> 8 , V_49 & 0xff , 0x00 , 1 } ;
T_1 V_23 ;
V_11 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , & V_23 , 1 ) ;
if ( V_11 )
return V_11 ;
return V_23 ;
}
static int F_36 ( struct V_121 * V_122 , int V_123 ,
int V_49 , T_1 V_23 )
{
struct V_1 * V_2 = V_122 -> V_124 ;
int V_11 ;
T_1 V_13 [] = { V_125 , 0x03 , 0x40 | V_49 >> 8 , V_49 & 0xff , 0x00 , 1 , V_23 } ;
V_11 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_37 ( struct V_121 * V_122 , int V_123 ,
T_1 V_49 )
{
struct V_1 * V_2 = V_122 -> V_124 ;
int V_11 ;
T_1 V_13 [] = { V_125 , 0x04 , 0x40 , V_49 , 0x00 , 1 } ;
T_1 V_23 ;
V_11 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , & V_23 , 1 ) ;
if ( V_11 )
return V_11 ;
return V_23 ;
}
static int F_38 ( struct V_121 * V_122 , int V_123 ,
T_1 V_49 , T_1 V_23 )
{
struct V_1 * V_2 = V_122 -> V_124 ;
int V_11 ;
T_1 V_13 [] = { V_125 , 0x05 , 0x40 , V_49 , 0x00 , 1 , V_23 } ;
V_11 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_39 ( struct V_121 * V_122 , int V_123 )
{
struct V_1 * V_2 = V_122 -> V_124 ;
int V_11 ;
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_126 = V_127 + F_40 ( 1000 ) ;
V_11 = F_13 ( V_2 , V_88 , ( 0 << 7 ) , 0x80 ) ;
if ( V_11 )
return V_11 ;
F_41 ( 300 ) ;
V_11 = F_13 ( V_2 , V_88 , ( 1 << 7 ) , 0x80 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_42 ( struct V_121 * V_122 , int V_123 )
{
struct V_1 * V_2 = V_122 -> V_124 ;
int V_11 ;
V_11 = F_13 ( V_2 , V_88 , ( 0 << 7 ) , 0x80 ) ;
if ( V_11 )
return V_11 ;
F_41 ( 30 ) ;
V_11 = F_13 ( V_2 , V_88 , ( 1 << 7 ) , 0x80 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_43 ( struct V_121 * V_122 , int V_123 )
{
struct V_1 * V_2 = V_122 -> V_124 ;
int V_11 ;
V_11 = F_13 ( V_2 , V_73 , ( 0 << 1 ) , 0x02 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_44 ( struct V_121 * V_122 , int V_123 ,
int V_128 )
{
struct V_1 * V_2 = V_122 -> V_124 ;
struct V_7 * V_8 = V_2 -> V_9 ;
int V_11 ;
T_1 V_27 ;
V_11 = F_14 ( V_2 , V_129 , & V_27 , 0x40 ) ;
if ( V_11 )
return V_11 ;
if ( V_27 == 0 ) {
V_11 = V_130 ;
if ( F_45 ( V_127 , V_8 -> V_126 ) )
V_11 |= V_131 ;
}
return V_11 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_11 ;
V_8 -> V_122 . V_132 = V_133 ;
V_8 -> V_122 . V_134 = F_35 ;
V_8 -> V_122 . V_135 = F_36 ;
V_8 -> V_122 . V_136 = F_37 ;
V_8 -> V_122 . V_137 = F_38 ;
V_8 -> V_122 . V_138 = F_39 ;
V_8 -> V_122 . V_139 = F_42 ;
V_8 -> V_122 . V_140 = F_43 ;
V_8 -> V_122 . V_141 = F_44 ;
V_8 -> V_122 . V_124 = V_2 ;
V_11 = F_13 ( V_2 , V_88 , ( 1 << 7 ) , 0x80 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_13 ( V_2 , V_73 , ( 0 << 2 ) | ( 0 << 1 ) | ( 0 << 0 ) , 0x07 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_13 ( V_2 , V_73 , ( 1 << 2 ) | ( 1 << 1 ) | ( 1 << 0 ) , 0x07 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_47 ( & V_2 -> V_51 [ 0 ] . V_142 , & V_8 -> V_122 , 0 , 1 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 -> V_100 )
F_49 ( & V_8 -> V_122 ) ;
return;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_11 ;
V_11 = F_17 ( V_2 , 0x01 , 0x03 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_18 ( V_2 , 1 ) ;
if ( V_11 )
return V_11 ;
if ( V_8 -> V_100 ) {
V_11 = F_46 ( V_2 ) ;
if ( V_11 ) {
V_8 -> V_100 = false ;
return V_11 ;
}
}
return 0 ;
}
static int F_51 ( struct V_143 * V_144 ,
const struct V_145 * V_28 )
{
struct V_1 * V_2 ;
struct V_146 * V_147 ;
int V_11 ;
if ( V_144 -> V_148 < 1 )
return - V_108 ;
V_11 = F_52 ( V_144 , & V_149 , V_133 , & V_2 ,
V_150 ) ;
if ( V_11 )
return V_11 ;
V_147 = F_53 ( V_144 , 0 ) ;
if ( V_147 == NULL ) {
F_8 ( L_16 , V_21 ) ;
return - V_108 ;
}
V_11 = F_54 ( V_2 -> V_18 , V_147 -> V_151 . V_152 ,
V_147 -> V_151 . V_153 ) ;
if ( V_11 )
return V_11 ;
return F_50 ( V_2 ) ;
}
static void F_55 ( struct V_143 * V_144 )
{
struct V_1 * V_2 = F_56 ( V_144 ) ;
F_48 ( V_2 ) ;
F_57 ( V_144 ) ;
return;
}
