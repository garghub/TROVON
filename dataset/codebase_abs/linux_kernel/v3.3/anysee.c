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
F_3 ( L_1 ) ;
F_4 ( V_12 , V_4 , F_3 ) ;
V_11 = F_5 ( V_2 , V_12 , sizeof( V_12 ) , V_12 , sizeof( V_12 ) , 0 ) ;
if ( ! V_11 ) {
V_11 = F_6 ( V_2 -> V_16 , F_7 ( V_2 -> V_16 ,
V_2 -> V_17 . V_18 ) , V_12 , sizeof( V_12 ) ,
& V_10 , 2000 ) ;
if ( V_11 )
F_8 ( L_2 , V_19 , V_11 ) ;
else {
F_3 ( L_3 ) ;
F_4 ( V_12 , V_6 , F_3 ) ;
if ( V_12 [ 63 ] != 0x4f )
F_9 ( L_4 , V_19 ) ;
}
}
if ( ! V_11 && V_5 && V_6 )
memcpy ( V_5 , V_12 , V_6 ) ;
F_10 ( & V_14 ) ;
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_20 , T_1 * V_21 )
{
T_1 V_12 [] = { V_22 , V_20 >> 8 , V_20 & 0xff , 0x01 } ;
int V_11 ;
V_11 = F_1 ( V_2 , V_12 , sizeof( V_12 ) , V_21 , 1 ) ;
F_9 ( L_5 , V_19 , V_20 , * V_21 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_20 , T_1 V_21 )
{
T_1 V_12 [] = { V_23 , V_20 >> 8 , V_20 & 0xff , 0x01 , V_21 } ;
F_9 ( L_5 , V_19 , V_20 , V_21 ) ;
return F_1 ( V_2 , V_12 , sizeof( V_12 ) , NULL , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_20 , T_1 V_21 ,
T_1 V_24 )
{
int V_11 ;
T_1 V_25 ;
if ( V_24 != 0xff ) {
V_11 = F_11 ( V_2 , V_20 , & V_25 ) ;
if ( V_11 )
return V_11 ;
V_21 &= V_24 ;
V_25 &= ~ V_24 ;
V_21 |= V_25 ;
}
return F_12 ( V_2 , V_20 , V_21 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_20 , T_1 * V_21 ,
T_1 V_24 )
{
int V_11 , V_26 ;
T_1 V_25 ;
V_11 = F_11 ( V_2 , V_20 , & V_25 ) ;
if ( V_11 )
return V_11 ;
V_25 &= V_24 ;
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ ) {
if ( ( V_24 >> V_26 ) & 0x01 )
break;
}
* V_21 = V_25 >> V_26 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_27 )
{
T_1 V_12 [] = { V_28 } ;
return F_1 ( V_2 , V_12 , sizeof( V_12 ) , V_27 , 3 ) ;
}
static int F_16 ( struct V_29 * V_30 , int V_31 )
{
T_1 V_12 [] = { V_32 , ( T_1 ) V_31 , 0x00 } ;
F_9 ( L_6 , V_19 , V_31 ) ;
return F_1 ( V_30 -> V_33 , V_12 , sizeof( V_12 ) , NULL , 0 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_34 , T_1 V_35 )
{
T_1 V_12 [] = { V_36 , 0x01 , V_34 , V_35 } ;
F_9 ( L_7 , V_19 , V_34 , V_35 ) ;
return F_1 ( V_2 , V_12 , sizeof( V_12 ) , NULL , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_31 )
{
T_1 V_12 [] = { V_36 , 0x02 , V_31 } ;
F_9 ( L_6 , V_19 , V_31 ) ;
return F_1 ( V_2 , V_12 , sizeof( V_12 ) , NULL , 0 ) ;
}
static int F_19 ( struct V_37 * V_30 , struct V_38 * V_39 ,
int V_40 )
{
struct V_1 * V_2 = F_20 ( V_30 ) ;
int V_11 = 0 , V_41 , V_26 = 0 ;
T_1 V_12 [ 52 ] ;
if ( F_2 ( & V_2 -> V_42 ) < 0 )
return - V_15 ;
while ( V_26 < V_40 ) {
if ( V_40 > V_26 + 1 && ( V_39 [ V_26 + 1 ] . V_43 & V_44 ) ) {
if ( V_39 [ V_26 ] . V_45 > 2 || V_39 [ V_26 + 1 ] . V_45 > 60 ) {
V_11 = - V_46 ;
break;
}
V_12 [ 0 ] = V_47 ;
V_12 [ 1 ] = ( V_39 [ V_26 ] . V_48 << 1 ) | 0x01 ;
V_12 [ 2 ] = V_39 [ V_26 ] . V_12 [ 0 ] ;
V_12 [ 3 ] = V_39 [ V_26 ] . V_12 [ 1 ] ;
V_12 [ 4 ] = V_39 [ V_26 ] . V_45 - 1 ;
V_12 [ 5 ] = V_39 [ V_26 + 1 ] . V_45 ;
V_11 = F_1 ( V_2 , V_12 , 6 , V_39 [ V_26 + 1 ] . V_12 ,
V_39 [ V_26 + 1 ] . V_45 ) ;
V_41 = 2 ;
} else {
if ( V_39 [ V_26 ] . V_45 > 48 ) {
V_11 = - V_46 ;
break;
}
V_12 [ 0 ] = V_49 ;
V_12 [ 1 ] = ( V_39 [ V_26 ] . V_48 << 1 ) ;
V_12 [ 2 ] = V_39 [ V_26 ] . V_45 ;
V_12 [ 3 ] = 0x01 ;
memcpy ( & V_12 [ 4 ] , V_39 [ V_26 ] . V_12 , V_39 [ V_26 ] . V_45 ) ;
V_11 = F_1 ( V_2 , V_12 , 4 + V_39 [ V_26 ] . V_45 , NULL , 0 ) ;
V_41 = 1 ;
}
if ( V_11 )
break;
V_26 += V_41 ;
}
F_10 ( & V_2 -> V_42 ) ;
return V_11 ? V_11 : V_26 ;
}
static T_3 F_21 ( struct V_37 * V_50 )
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
static int F_25 ( struct V_52 * V_53 , int V_66 )
{
struct V_29 * V_30 = V_53 -> V_67 -> V_9 ;
return F_13 ( V_30 -> V_33 , V_68 , ( V_66 << 4 ) , 0x10 ) ;
}
static int F_26 ( struct V_52 * V_53 , int V_31 )
{
struct V_29 * V_30 = V_53 -> V_67 -> V_9 ;
struct V_7 * V_8 = V_30 -> V_33 -> V_9 ;
int V_11 ;
F_9 ( L_8 , V_19 , V_53 -> V_27 , V_31 ) ;
if ( V_31 == 0 )
return 0 ;
switch ( V_8 -> V_69 ) {
case V_70 :
if ( ( V_53 -> V_27 ^ V_71 ) == 0 ) {
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 0 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 1 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_68 , ( 1 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
} else {
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 0 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 1 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_68 , ( 0 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
}
break;
case V_73 :
case V_74 :
if ( ( V_53 -> V_27 ^ V_71 ) == 0 ) {
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 0 << 6 ) ,
0x40 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 1 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_68 , ( 1 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
} else {
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 0 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 1 << 6 ) ,
0x40 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_68 , ( 0 << 0 ) ,
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
static int F_27 ( struct V_29 * V_30 )
{
int V_11 ;
struct V_7 * V_8 = V_30 -> V_33 -> V_9 ;
T_1 V_75 [ 3 ] ;
T_1 V_25 ;
struct V_38 V_39 [ 2 ] = {
{
. V_48 = V_76 . V_77 ,
. V_43 = 0 ,
. V_45 = 1 ,
. V_12 = L_9 ,
} , {
. V_48 = V_76 . V_77 ,
. V_43 = V_44 ,
. V_45 = 1 ,
. V_12 = & V_25 ,
}
} ;
if ( V_30 -> V_78 [ 0 ] . V_53 == NULL ) {
V_11 = F_15 ( V_30 -> V_33 , V_75 ) ;
if ( V_11 )
goto error;
V_11 = F_15 ( V_30 -> V_33 , V_75 ) ;
if ( V_11 )
goto error;
F_28 ( L_10 ,
V_75 [ 1 ] , V_75 [ 2 ] , V_75 [ 0 ] ) ;
V_8 -> V_69 = V_75 [ 0 ] ;
}
if ( V_30 -> V_78 [ 0 ] . V_53 )
V_8 -> V_79 ++ ;
switch ( V_8 -> V_69 ) {
case V_80 :
if ( V_8 -> V_79 )
break;
V_30 -> V_78 [ 0 ] . V_53 = F_29 ( V_81 ,
& V_82 , & V_30 -> V_33 -> V_83 ) ;
if ( V_30 -> V_78 [ 0 ] . V_53 )
break;
V_30 -> V_78 [ 0 ] . V_53 = F_29 ( V_84 ,
& V_85 , & V_30 -> V_33 -> V_83 ) ;
break;
case V_86 :
if ( V_8 -> V_79 )
break;
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 1 << 0 ) , 0x01 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_87 , ( 0 << 7 ) , 0x80 ) ;
if ( V_11 )
goto error;
V_30 -> V_78 [ 0 ] . V_53 = F_29 ( V_84 ,
& V_85 , & V_30 -> V_33 -> V_83 ) ;
break;
case V_88 :
if ( V_8 -> V_79 )
break;
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 1 << 0 ) , 0x01 ) ;
if ( V_11 )
goto error;
V_30 -> V_78 [ 0 ] . V_53 = F_29 ( V_89 ,
& V_90 , & V_30 -> V_33 -> V_83 , 0x48 ) ;
break;
case V_91 :
if ( V_8 -> V_79 )
break;
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 1 << 0 ) , 0x01 ) ;
if ( V_11 )
goto error;
V_30 -> V_78 [ 0 ] . V_53 = F_29 ( V_92 ,
& V_93 , & V_30 -> V_33 -> V_83 ) ;
break;
case V_70 :
V_11 = F_13 ( V_30 -> V_33 , V_68 , ( 1 << 4 ) , 0x10 ) ;
if ( V_11 )
goto error;
V_25 = 0 ;
V_11 = F_30 ( & V_30 -> V_33 -> V_83 , V_39 , 2 ) ;
if ( V_11 == 2 && V_25 == 0xc7 )
F_9 ( L_11 , V_19 ) ;
else
V_25 = 0 ;
V_11 = F_13 ( V_30 -> V_33 , V_68 , ( 0 << 4 ) , 0x10 ) ;
if ( V_11 )
goto error;
if ( ( V_8 -> V_79 ^ V_71 ) == 0 ) {
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 0 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 1 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
if ( V_25 == 0xc7 ) {
V_30 -> V_78 [ V_8 -> V_79 ] . V_53 = F_29 (
V_89 ,
& V_94 ,
& V_30 -> V_33 -> V_83 , 0x48 ) ;
} else {
V_30 -> V_78 [ V_8 -> V_79 ] . V_53 = F_29 (
V_89 ,
& V_90 ,
& V_30 -> V_33 -> V_83 , 0x48 ) ;
}
} else {
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 0 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 1 << 0 ) ,
0x01 ) ;
if ( V_11 )
goto error;
if ( V_25 == 0xc7 ) {
V_30 -> V_78 [ V_8 -> V_79 ] . V_53 = F_29 (
V_84 ,
& V_95 ,
& V_30 -> V_33 -> V_83 ) ;
} else {
V_30 -> V_78 [ V_8 -> V_79 ] . V_53 = F_29 (
V_84 ,
& V_85 ,
& V_30 -> V_33 -> V_83 ) ;
}
}
if ( V_25 == 0xc7 ) {
if ( V_30 -> V_78 [ V_8 -> V_79 ] . V_53 )
V_30 -> V_78 [ V_8 -> V_79 ] . V_53 -> V_96 . V_97 =
F_25 ;
}
break;
case V_73 :
case V_74 :
if ( ( V_8 -> V_79 ^ V_71 ) == 0 ) {
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 0 << 6 ) ,
0x40 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 1 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_30 -> V_78 [ V_8 -> V_79 ] . V_53 =
F_29 ( V_89 ,
& V_94 ,
& V_30 -> V_33 -> V_83 , 0x48 ) ;
} else {
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 0 << 5 ) ,
0x20 ) ;
if ( V_11 )
goto error;
V_11 = F_13 ( V_30 -> V_33 , V_72 , ( 1 << 6 ) ,
0x40 ) ;
if ( V_11 )
goto error;
V_30 -> V_78 [ V_8 -> V_79 ] . V_53 =
F_29 ( V_84 ,
& V_98 ,
& V_30 -> V_33 -> V_83 ) ;
}
if ( V_30 -> V_78 [ V_8 -> V_79 ] . V_53 )
V_30 -> V_78 [ V_8 -> V_79 ] . V_53 -> V_96 . V_97 =
F_25 ;
V_8 -> V_99 = true ;
break;
case V_100 :
case V_101 :
if ( V_8 -> V_79 )
break;
V_11 = F_13 ( V_30 -> V_33 , V_68 , ( 1 << 5 ) , 0x20 ) ;
if ( V_11 )
goto error;
V_30 -> V_78 [ 0 ] . V_53 = F_29 ( V_102 ,
& V_103 , & V_30 -> V_33 -> V_83 , 0 ) ;
V_8 -> V_99 = true ;
break;
case V_104 :
if ( V_8 -> V_79 )
break;
V_11 = F_13 ( V_30 -> V_33 , V_68 , ( 1 << 5 ) , 0x20 ) ;
if ( V_11 )
goto error;
V_30 -> V_78 [ V_8 -> V_79 ] . V_53 = F_29 ( V_105 ,
& V_106 , & V_30 -> V_33 -> V_83 ) ;
V_8 -> V_99 = true ;
break;
}
if ( ! V_30 -> V_78 [ 0 ] . V_53 ) {
V_11 = - V_107 ;
F_8 ( L_12 \
L_13 ) ;
}
error:
return V_11 ;
}
static int F_31 ( struct V_29 * V_30 )
{
struct V_7 * V_8 = V_30 -> V_33 -> V_9 ;
struct V_52 * V_53 ;
int V_11 ;
F_9 ( L_14 , V_19 , V_8 -> V_79 ) ;
switch ( V_8 -> V_69 ) {
case V_80 :
V_53 = F_29 ( V_108 , V_30 -> V_78 [ 0 ] . V_53 ,
( 0xc2 >> 1 ) , NULL , V_109 ) ;
break;
case V_86 :
V_53 = F_29 ( V_108 , V_30 -> V_78 [ 0 ] . V_53 ,
( 0xc2 >> 1 ) , & V_30 -> V_33 -> V_83 ,
V_109 ) ;
break;
case V_88 :
V_53 = F_29 ( V_108 , V_30 -> V_78 [ 0 ] . V_53 ,
( 0xc0 >> 1 ) , & V_30 -> V_33 -> V_83 ,
V_110 ) ;
break;
case V_91 :
V_53 = F_29 ( V_111 , V_30 -> V_78 [ 0 ] . V_53 ,
& V_30 -> V_33 -> V_83 , & V_112 ) ;
break;
case V_70 :
V_53 = F_29 ( V_113 , V_30 -> V_78 [ V_8 -> V_79 ] . V_53 ,
& V_30 -> V_33 -> V_83 , & V_76 ) ;
if ( V_53 )
break;
V_53 = F_29 ( V_108 , V_30 -> V_78 [ V_8 -> V_79 ] . V_53 ,
( 0xc0 >> 1 ) , & V_30 -> V_33 -> V_83 ,
V_110 ) ;
break;
case V_73 :
case V_74 :
V_53 = F_29 ( V_113 , V_30 -> V_78 [ V_8 -> V_79 ] . V_53 ,
& V_30 -> V_33 -> V_83 , & V_76 ) ;
break;
case V_100 :
case V_101 :
V_53 = F_29 ( V_114 , V_30 -> V_78 [ 0 ] . V_53 ,
& V_115 , & V_30 -> V_33 -> V_83 ) ;
if ( V_53 ) {
V_53 = F_29 ( V_111 , V_30 -> V_78 [ 0 ] . V_53 ,
& V_30 -> V_33 -> V_83 , & V_112 ) ;
}
break;
case V_104 :
V_53 = F_29 ( V_113 , V_30 -> V_78 [ V_8 -> V_79 ] . V_53 ,
& V_30 -> V_33 -> V_83 , & V_116 ) ;
break;
default:
V_53 = NULL ;
}
if ( V_53 )
V_11 = 0 ;
else
V_11 = - V_107 ;
return V_11 ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_1 V_12 [] = { V_117 } ;
T_1 V_118 [ 2 ] ;
int V_11 ;
V_11 = F_1 ( V_2 , V_12 , sizeof( V_12 ) , V_118 , sizeof( V_118 ) ) ;
if ( V_11 )
return V_11 ;
if ( V_118 [ 0 ] ) {
F_33 ( L_15 , V_19 , V_118 [ 1 ] ) ;
F_34 ( V_2 -> V_119 , 0x08 << 8 | V_118 [ 1 ] , 0 ) ;
}
return 0 ;
}
static int F_35 ( struct V_120 * V_121 , int V_122 ,
int V_48 )
{
struct V_1 * V_2 = V_121 -> V_123 ;
int V_11 ;
T_1 V_12 [] = { V_124 , 0x02 , 0x40 | V_48 >> 8 , V_48 & 0xff , 0x00 , 1 } ;
T_1 V_21 ;
V_11 = F_1 ( V_2 , V_12 , sizeof( V_12 ) , & V_21 , 1 ) ;
if ( V_11 )
return V_11 ;
return V_21 ;
}
static int F_36 ( struct V_120 * V_121 , int V_122 ,
int V_48 , T_1 V_21 )
{
struct V_1 * V_2 = V_121 -> V_123 ;
int V_11 ;
T_1 V_12 [] = { V_124 , 0x03 , 0x40 | V_48 >> 8 , V_48 & 0xff , 0x00 , 1 , V_21 } ;
V_11 = F_1 ( V_2 , V_12 , sizeof( V_12 ) , NULL , 0 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_37 ( struct V_120 * V_121 , int V_122 ,
T_1 V_48 )
{
struct V_1 * V_2 = V_121 -> V_123 ;
int V_11 ;
T_1 V_12 [] = { V_124 , 0x04 , 0x40 , V_48 , 0x00 , 1 } ;
T_1 V_21 ;
V_11 = F_1 ( V_2 , V_12 , sizeof( V_12 ) , & V_21 , 1 ) ;
if ( V_11 )
return V_11 ;
return V_21 ;
}
static int F_38 ( struct V_120 * V_121 , int V_122 ,
T_1 V_48 , T_1 V_21 )
{
struct V_1 * V_2 = V_121 -> V_123 ;
int V_11 ;
T_1 V_12 [] = { V_124 , 0x05 , 0x40 , V_48 , 0x00 , 1 , V_21 } ;
V_11 = F_1 ( V_2 , V_12 , sizeof( V_12 ) , NULL , 0 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_39 ( struct V_120 * V_121 , int V_122 )
{
struct V_1 * V_2 = V_121 -> V_123 ;
int V_11 ;
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_125 = V_126 + F_40 ( 1000 ) ;
V_11 = F_13 ( V_2 , V_87 , ( 0 << 7 ) , 0x80 ) ;
if ( V_11 )
return V_11 ;
F_41 ( 300 ) ;
V_11 = F_13 ( V_2 , V_87 , ( 1 << 7 ) , 0x80 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_42 ( struct V_120 * V_121 , int V_122 )
{
struct V_1 * V_2 = V_121 -> V_123 ;
int V_11 ;
V_11 = F_13 ( V_2 , V_87 , ( 0 << 7 ) , 0x80 ) ;
if ( V_11 )
return V_11 ;
F_41 ( 30 ) ;
V_11 = F_13 ( V_2 , V_87 , ( 1 << 7 ) , 0x80 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_43 ( struct V_120 * V_121 , int V_122 )
{
struct V_1 * V_2 = V_121 -> V_123 ;
int V_11 ;
V_11 = F_13 ( V_2 , V_72 , ( 0 << 1 ) , 0x02 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_44 ( struct V_120 * V_121 , int V_122 ,
int V_127 )
{
struct V_1 * V_2 = V_121 -> V_123 ;
struct V_7 * V_8 = V_2 -> V_9 ;
int V_11 ;
T_1 V_25 ;
V_11 = F_14 ( V_2 , V_128 , & V_25 , 0x40 ) ;
if ( V_11 )
return V_11 ;
if ( V_25 == 0 ) {
V_11 = V_129 ;
if ( F_45 ( V_126 , V_8 -> V_125 ) )
V_11 |= V_130 ;
}
return V_11 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_11 ;
V_8 -> V_121 . V_131 = V_132 ;
V_8 -> V_121 . V_133 = F_35 ;
V_8 -> V_121 . V_134 = F_36 ;
V_8 -> V_121 . V_135 = F_37 ;
V_8 -> V_121 . V_136 = F_38 ;
V_8 -> V_121 . V_137 = F_39 ;
V_8 -> V_121 . V_138 = F_42 ;
V_8 -> V_121 . V_139 = F_43 ;
V_8 -> V_121 . V_140 = F_44 ;
V_8 -> V_121 . V_123 = V_2 ;
V_11 = F_13 ( V_2 , V_87 , ( 1 << 7 ) , 0x80 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_13 ( V_2 , V_72 , ( 0 << 2 ) | ( 0 << 1 ) | ( 0 << 0 ) , 0x07 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_13 ( V_2 , V_72 , ( 1 << 2 ) | ( 1 << 1 ) | ( 1 << 0 ) , 0x07 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_47 ( & V_2 -> V_50 [ 0 ] . V_141 , & V_8 -> V_121 , 0 , 1 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 -> V_99 )
F_49 ( & V_8 -> V_121 ) ;
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
if ( V_8 -> V_99 ) {
V_11 = F_46 ( V_2 ) ;
if ( V_11 ) {
V_8 -> V_99 = false ;
return V_11 ;
}
}
return 0 ;
}
static int F_51 ( struct V_142 * V_143 ,
const struct V_144 * V_27 )
{
struct V_1 * V_2 ;
struct V_145 * V_146 ;
int V_11 ;
if ( V_143 -> V_147 < 1 )
return - V_107 ;
V_11 = F_52 ( V_143 , & V_148 , V_132 , & V_2 ,
V_149 ) ;
if ( V_11 )
return V_11 ;
V_146 = F_53 ( V_143 , 0 ) ;
if ( V_146 == NULL ) {
F_9 ( L_16 , V_19 ) ;
return - V_107 ;
}
V_11 = F_54 ( V_2 -> V_16 , V_146 -> V_150 . V_151 ,
V_146 -> V_150 . V_152 ) ;
if ( V_11 )
return V_11 ;
return F_50 ( V_2 ) ;
}
static void F_55 ( struct V_142 * V_143 )
{
struct V_1 * V_2 = F_56 ( V_143 ) ;
F_48 ( V_2 ) ;
F_57 ( V_143 ) ;
return;
}
