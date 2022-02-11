static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 V_4 , T_1 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 , V_10 , V_11 ;
F_3 ( & V_2 -> V_12 ) ;
memcpy ( & V_8 -> V_13 [ 0 ] , V_3 , V_4 ) ;
V_8 -> V_13 [ 60 ] = V_8 -> V_14 ++ ;
F_4 ( & V_2 -> V_15 -> V_16 , L_1 , V_17 , V_4 , V_8 -> V_13 ) ;
V_10 = F_5 ( V_2 , V_8 -> V_13 , sizeof( V_8 -> V_13 ) ,
V_8 -> V_13 , sizeof( V_8 -> V_13 ) ) ;
if ( V_10 )
goto V_18;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
V_10 = F_6 ( V_2 -> V_15 , F_7 ( V_2 -> V_15 ,
V_2 -> V_19 -> V_20 ) ,
V_8 -> V_13 , sizeof( V_8 -> V_13 ) , & V_9 , 2000 ) ;
if ( V_10 ) {
F_4 ( & V_2 -> V_15 -> V_16 ,
L_2 ,
V_17 , V_10 ) ;
} else {
F_4 ( & V_2 -> V_15 -> V_16 , L_3 , V_17 ,
V_6 , V_8 -> V_13 ) ;
if ( V_8 -> V_13 [ 63 ] != 0x4f )
F_4 ( & V_2 -> V_15 -> V_16 ,
L_4 , V_17 ) ;
break;
}
}
if ( V_10 ) {
F_8 ( & V_2 -> V_15 -> V_16 , L_2 ,
V_21 , V_10 ) ;
goto V_18;
}
if ( V_5 && V_6 )
memcpy ( V_5 , V_8 -> V_13 , V_6 ) ;
V_18:
F_9 ( & V_2 -> V_12 ) ;
return V_10 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_22 , T_1 * V_23 )
{
T_1 V_13 [] = { V_24 , V_22 >> 8 , V_22 & 0xff , 0x01 } ;
int V_10 ;
V_10 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , V_23 , 1 ) ;
F_4 ( & V_2 -> V_15 -> V_16 , L_5 , V_17 , V_22 , * V_23 ) ;
return V_10 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_22 , T_1 V_23 )
{
T_1 V_13 [] = { V_25 , V_22 >> 8 , V_22 & 0xff , 0x01 , V_23 } ;
F_4 ( & V_2 -> V_15 -> V_16 , L_5 , V_17 , V_22 , V_23 ) ;
return F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_22 , T_1 V_23 ,
T_1 V_26 )
{
int V_10 ;
T_1 V_27 ;
if ( V_26 != 0xff ) {
V_10 = F_10 ( V_2 , V_22 , & V_27 ) ;
if ( V_10 )
return V_10 ;
V_23 &= V_26 ;
V_27 &= ~ V_26 ;
V_23 |= V_27 ;
}
return F_11 ( V_2 , V_22 , V_23 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_22 , T_1 * V_23 ,
T_1 V_26 )
{
int V_10 , V_11 ;
T_1 V_27 ;
V_10 = F_10 ( V_2 , V_22 , & V_27 ) ;
if ( V_10 )
return V_10 ;
V_27 &= V_26 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
if ( ( V_26 >> V_11 ) & 0x01 )
break;
}
* V_23 = V_27 >> V_11 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_28 )
{
T_1 V_13 [] = { V_29 } ;
return F_1 ( V_2 , V_13 , sizeof( V_13 ) , V_28 , 3 ) ;
}
static int F_15 ( struct V_30 * V_31 , int V_32 )
{
T_1 V_13 [] = { V_33 , ( T_1 ) V_32 , 0x00 } ;
F_4 ( & F_16 ( V_31 ) -> V_15 -> V_16 , L_6 , V_17 , V_32 ) ;
return F_1 ( F_16 ( V_31 ) , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_34 , T_1 V_35 )
{
T_1 V_13 [] = { V_36 , 0x01 , V_34 , V_35 } ;
F_4 ( & V_2 -> V_15 -> V_16 , L_7 , V_17 ,
V_34 , V_35 ) ;
return F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_32 )
{
T_1 V_13 [] = { V_36 , 0x02 , V_32 } ;
F_4 ( & V_2 -> V_15 -> V_16 , L_6 , V_17 , V_32 ) ;
return F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
}
static int F_19 ( struct V_37 * V_38 , struct V_39 * V_40 ,
int V_41 )
{
struct V_1 * V_2 = F_20 ( V_38 ) ;
int V_10 = 0 , V_42 , V_11 = 0 ;
T_1 V_13 [ 52 ] ;
if ( F_21 ( & V_2 -> V_43 ) < 0 )
return - V_44 ;
while ( V_11 < V_41 ) {
if ( V_41 > V_11 + 1 && ( V_40 [ V_11 + 1 ] . V_45 & V_46 ) ) {
if ( V_40 [ V_11 ] . V_47 > 2 || V_40 [ V_11 + 1 ] . V_47 > 60 ) {
V_10 = - V_48 ;
break;
}
V_13 [ 0 ] = V_49 ;
V_13 [ 1 ] = ( V_40 [ V_11 ] . V_50 << 1 ) | 0x01 ;
V_13 [ 2 ] = V_40 [ V_11 ] . V_13 [ 0 ] ;
V_13 [ 3 ] = V_40 [ V_11 ] . V_13 [ 1 ] ;
V_13 [ 4 ] = V_40 [ V_11 ] . V_47 - 1 ;
V_13 [ 5 ] = V_40 [ V_11 + 1 ] . V_47 ;
V_10 = F_1 ( V_2 , V_13 , 6 , V_40 [ V_11 + 1 ] . V_13 ,
V_40 [ V_11 + 1 ] . V_47 ) ;
V_42 = 2 ;
} else {
if ( V_40 [ V_11 ] . V_47 > 48 ) {
V_10 = - V_48 ;
break;
}
V_13 [ 0 ] = V_51 ;
V_13 [ 1 ] = ( V_40 [ V_11 ] . V_50 << 1 ) ;
V_13 [ 2 ] = V_40 [ V_11 ] . V_47 ;
V_13 [ 3 ] = 0x01 ;
memcpy ( & V_13 [ 4 ] , V_40 [ V_11 ] . V_13 , V_40 [ V_11 ] . V_47 ) ;
V_10 = F_1 ( V_2 , V_13 , 4 + V_40 [ V_11 ] . V_47 , NULL , 0 ) ;
V_42 = 1 ;
}
if ( V_10 )
break;
V_11 += V_42 ;
}
F_9 ( & V_2 -> V_43 ) ;
return V_10 ? V_10 : V_11 ;
}
static T_3 F_22 ( struct V_37 * V_52 )
{
return V_53 ;
}
static int F_23 ( struct V_30 * V_31 )
{
static T_1 V_54 [] = { V_55 , 0x38 , 0x28 } ;
static T_1 V_56 [] = { V_57 , 0x80 } ;
static T_1 V_58 [] = { V_59 , 0x40 } ;
static T_1 V_60 [] = { V_61 , 0x28 , 0x20 } ;
static T_1 V_62 [] = { V_63 , 0x33 } ;
static T_1 V_64 [] = { V_65 , 0x32 } ;
F_24 ( V_31 , V_54 , sizeof( V_54 ) ) ;
F_25 ( 200 ) ;
F_24 ( V_31 , V_56 , sizeof( V_56 ) ) ;
F_24 ( V_31 , V_58 , sizeof( V_58 ) ) ;
F_24 ( V_31 , V_60 , sizeof( V_60 ) ) ;
F_24 ( V_31 , V_62 , sizeof( V_62 ) ) ;
F_24 ( V_31 , V_64 , sizeof( V_64 ) ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_10 ;
T_1 V_66 [ 3 ] ;
V_10 = F_14 ( V_2 , V_66 ) ;
if ( V_10 )
goto error;
V_10 = F_14 ( V_2 , V_66 ) ;
if ( V_10 )
goto error;
F_27 ( & V_2 -> V_15 -> V_16 , L_8 ,
V_21 , V_66 [ 1 ] , V_66 [ 2 ] , V_66 [ 0 ] ) ;
V_8 -> V_67 = V_66 [ 0 ] ;
error:
return V_10 ;
}
static int F_28 ( struct V_30 * V_31 , int V_68 )
{
return F_12 ( F_16 ( V_31 ) , V_69 , ( V_68 << 4 ) , 0x10 ) ;
}
static int F_29 ( struct V_30 * V_31 , int V_32 )
{
struct V_7 * V_8 = F_30 ( V_31 ) ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_10 ;
F_4 ( & V_2 -> V_15 -> V_16 , L_9 , V_17 , V_31 -> V_28 , V_32 ) ;
if ( V_32 == 0 )
return 0 ;
switch ( V_8 -> V_67 ) {
case V_70 :
if ( V_31 -> V_28 == 0 ) {
V_10 = F_12 ( V_2 , V_71 , ( 0 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_69 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
} else {
V_10 = F_12 ( V_2 , V_71 , ( 0 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_69 , ( 0 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
}
break;
case V_72 :
case V_73 :
if ( V_31 -> V_28 == 0 ) {
V_10 = F_12 ( V_2 , V_71 , ( 0 << 6 ) , 0x40 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_69 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
} else {
V_10 = F_12 ( V_2 , V_71 , ( 0 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 6 ) , 0x40 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_69 , ( 0 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
}
break;
default:
V_10 = 0 ;
}
error:
return V_10 ;
}
static int F_31 ( struct V_74 * V_38 )
{
struct V_7 * V_8 = F_32 ( V_38 ) ;
struct V_1 * V_2 = F_33 ( V_38 ) ;
int V_10 = 0 ;
T_1 V_27 ;
struct V_39 V_40 [ 2 ] = {
{
. V_50 = V_75 . V_76 ,
. V_45 = 0 ,
. V_47 = 1 ,
. V_13 = L_10 ,
} , {
. V_50 = V_75 . V_76 ,
. V_45 = V_46 ,
. V_47 = 1 ,
. V_13 = & V_27 ,
}
} ;
switch ( V_8 -> V_67 ) {
case V_77 :
V_38 -> V_31 [ 0 ] = F_34 ( V_78 , & V_79 ,
& V_2 -> V_80 ) ;
if ( V_38 -> V_31 [ 0 ] )
break;
V_38 -> V_31 [ 0 ] = F_34 ( V_81 , & V_82 ,
& V_2 -> V_80 ) ;
break;
case V_83 :
V_10 = F_12 ( V_2 , V_71 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_84 , ( 0 << 7 ) , 0x80 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 0 ] = F_34 ( V_81 , & V_82 ,
& V_2 -> V_80 ) ;
break;
case V_85 :
V_10 = F_12 ( V_2 , V_71 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 0 ] = F_34 ( V_86 ,
& V_87 , & V_2 -> V_80 , 0x48 ) ;
break;
case V_88 :
V_10 = F_12 ( V_2 , V_71 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 0 ] = F_34 ( V_89 , & V_90 ,
& V_2 -> V_80 ) ;
break;
case V_70 :
V_10 = F_12 ( V_2 , V_69 , ( 1 << 4 ) , 0x10 ) ;
if ( V_10 )
goto error;
V_27 = 0 ;
V_10 = F_35 ( & V_2 -> V_80 , V_40 , 2 ) ;
if ( V_10 == 2 && V_27 == 0xc7 )
F_4 ( & V_2 -> V_15 -> V_16 , L_11 ,
V_17 ) ;
else
V_27 = 0 ;
V_10 = F_12 ( V_2 , V_69 , ( 0 << 4 ) , 0x10 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 0 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
if ( V_27 == 0xc7 ) {
V_38 -> V_31 [ 0 ] = F_34 ( V_86 ,
& V_91 ,
& V_2 -> V_80 , 0x48 ) ;
if ( V_38 -> V_31 [ 0 ] )
V_38 -> V_31 [ 0 ] -> V_92 . V_93 =
F_28 ;
} else {
V_38 -> V_31 [ 0 ] = F_34 ( V_86 ,
& V_87 ,
& V_2 -> V_80 , 0x48 ) ;
}
if ( ! V_38 -> V_31 [ 0 ] )
break;
V_10 = F_12 ( V_2 , V_71 , ( 0 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 0 ) , 0x01 ) ;
if ( V_10 )
goto error;
if ( V_27 == 0xc7 ) {
V_38 -> V_31 [ 1 ] = F_34 ( V_81 ,
& V_94 ,
& V_2 -> V_80 ) ;
if ( V_38 -> V_31 [ 1 ] )
V_38 -> V_31 [ 1 ] -> V_92 . V_93 =
F_28 ;
} else {
V_38 -> V_31 [ 1 ] = F_34 ( V_81 ,
& V_82 ,
& V_2 -> V_80 ) ;
}
break;
case V_72 :
case V_73 :
V_10 = F_12 ( V_2 , V_71 , ( 0 << 6 ) , 0x40 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 0 ] = F_34 ( V_86 ,
& V_91 ,
& V_2 -> V_80 , 0x48 ) ;
if ( V_38 -> V_31 [ 0 ] )
V_38 -> V_31 [ 0 ] -> V_92 . V_93 = F_28 ;
if ( ! V_38 -> V_31 [ 0 ] )
break;
V_10 = F_12 ( V_2 , V_71 , ( 0 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 6 ) , 0x40 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 1 ] = F_34 ( V_81 ,
& V_95 ,
& V_2 -> V_80 ) ;
if ( V_38 -> V_31 [ 1 ] )
V_38 -> V_31 [ 1 ] -> V_92 . V_93 = F_28 ;
V_8 -> V_96 = true ;
break;
case V_97 :
case V_98 :
V_10 = F_12 ( V_2 , V_69 , ( 1 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 0 ] = F_34 ( V_99 ,
& V_100 , & V_2 -> V_80 , 0 ) ;
V_8 -> V_96 = true ;
break;
case V_101 :
V_10 = F_12 ( V_2 , V_69 , ( 1 << 5 ) , 0x20 ) ;
if ( V_10 )
goto error;
V_38 -> V_31 [ 0 ] = F_34 ( V_102 ,
& V_103 , & V_2 -> V_80 , NULL ) ;
V_8 -> V_96 = true ;
break;
}
if ( ! V_38 -> V_31 [ 0 ] ) {
V_10 = - V_104 ;
F_8 ( & V_2 -> V_15 -> V_16 ,
L_12 ,
V_21 ) ;
}
error:
return V_10 ;
}
static int F_36 ( struct V_74 * V_38 )
{
struct V_7 * V_8 = F_32 ( V_38 ) ;
struct V_1 * V_2 = F_33 ( V_38 ) ;
struct V_30 * V_31 ;
int V_10 ;
F_4 ( & V_2 -> V_15 -> V_16 , L_13 , V_17 ) ;
switch ( V_8 -> V_67 ) {
case V_77 :
V_31 = F_34 ( V_105 , V_38 -> V_31 [ 0 ] , ( 0xc2 >> 1 ) , NULL ,
V_106 ) ;
break;
case V_83 :
V_31 = F_34 ( V_105 , V_38 -> V_31 [ 0 ] , ( 0xc2 >> 1 ) ,
& V_2 -> V_80 , V_106 ) ;
break;
case V_85 :
V_31 = F_34 ( V_105 , V_38 -> V_31 [ 0 ] , ( 0xc0 >> 1 ) ,
& V_2 -> V_80 , V_107 ) ;
break;
case V_88 :
V_31 = F_34 ( V_108 , V_38 -> V_31 [ 0 ] , & V_2 -> V_80 ,
& V_109 ) ;
break;
case V_70 :
V_31 = F_34 ( V_110 , V_38 -> V_31 [ 0 ] , & V_2 -> V_80 ,
& V_75 ) ;
if ( V_31 && V_38 -> V_31 [ 1 ] ) {
V_31 = F_34 ( V_110 , V_38 -> V_31 [ 1 ] ,
& V_2 -> V_80 , & V_75 ) ;
break;
} else if ( V_31 ) {
break;
}
V_31 = F_34 ( V_105 , V_38 -> V_31 [ 0 ] , ( 0xc0 >> 1 ) ,
& V_2 -> V_80 , V_107 ) ;
if ( V_31 && V_38 -> V_31 [ 1 ] ) {
V_31 = F_34 ( V_105 , V_38 -> V_31 [ 0 ] ,
( 0xc0 >> 1 ) , & V_2 -> V_80 ,
V_107 ) ;
}
break;
case V_72 :
case V_73 :
V_31 = F_34 ( V_110 , V_38 -> V_31 [ 0 ] , & V_2 -> V_80 ,
& V_75 ) ;
if ( V_31 ) {
V_31 = F_34 ( V_110 , V_38 -> V_31 [ 1 ] ,
& V_2 -> V_80 , & V_75 ) ;
}
break;
case V_97 :
case V_98 :
V_31 = F_34 ( V_111 , V_38 -> V_31 [ 0 ] ,
& V_112 , & V_2 -> V_80 ) ;
if ( V_31 ) {
V_31 = F_34 ( V_108 , V_38 -> V_31 [ 0 ] ,
& V_2 -> V_80 , & V_109 ) ;
}
break;
case V_101 :
V_31 = F_34 ( V_110 , V_38 -> V_31 [ 0 ] , & V_2 -> V_80 ,
& V_113 ) ;
break;
default:
V_31 = NULL ;
}
if ( V_31 )
V_10 = 0 ;
else
V_10 = - V_104 ;
return V_10 ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_1 V_13 [] = { V_114 } ;
T_1 V_115 [ 2 ] ;
int V_10 ;
V_10 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , V_115 , sizeof( V_115 ) ) ;
if ( V_10 )
return V_10 ;
if ( V_115 [ 0 ] ) {
F_4 ( & V_2 -> V_15 -> V_16 , L_14 , V_17 ,
V_115 [ 1 ] ) ;
F_38 ( V_2 -> V_116 , 0x08 << 8 | V_115 [ 1 ] , 0 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_117 * V_118 )
{
V_118 -> V_119 = V_120 ;
V_118 -> V_121 = F_37 ;
V_118 -> V_35 = 250 ;
return 0 ;
}
static int F_40 ( struct V_122 * V_123 , int V_124 ,
int V_50 )
{
struct V_1 * V_2 = V_123 -> V_125 ;
int V_10 ;
T_1 V_13 [] = { V_126 , 0x02 , 0x40 | V_50 >> 8 , V_50 & 0xff , 0x00 , 1 } ;
T_1 V_23 ;
V_10 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , & V_23 , 1 ) ;
if ( V_10 )
return V_10 ;
return V_23 ;
}
static int F_41 ( struct V_122 * V_123 , int V_124 ,
int V_50 , T_1 V_23 )
{
struct V_1 * V_2 = V_123 -> V_125 ;
int V_10 ;
T_1 V_13 [] = { V_126 , 0x03 , 0x40 | V_50 >> 8 , V_50 & 0xff , 0x00 , 1 , V_23 } ;
V_10 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_42 ( struct V_122 * V_123 , int V_124 ,
T_1 V_50 )
{
struct V_1 * V_2 = V_123 -> V_125 ;
int V_10 ;
T_1 V_13 [] = { V_126 , 0x04 , 0x40 , V_50 , 0x00 , 1 } ;
T_1 V_23 ;
V_10 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , & V_23 , 1 ) ;
if ( V_10 )
return V_10 ;
return V_23 ;
}
static int F_43 ( struct V_122 * V_123 , int V_124 ,
T_1 V_50 , T_1 V_23 )
{
struct V_1 * V_2 = V_123 -> V_125 ;
int V_10 ;
T_1 V_13 [] = { V_126 , 0x05 , 0x40 , V_50 , 0x00 , 1 , V_23 } ;
V_10 = F_1 ( V_2 , V_13 , sizeof( V_13 ) , NULL , 0 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_44 ( struct V_122 * V_123 , int V_124 )
{
struct V_1 * V_2 = V_123 -> V_125 ;
int V_10 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_127 = V_128 + F_45 ( 1000 ) ;
V_10 = F_12 ( V_2 , V_84 , ( 0 << 7 ) , 0x80 ) ;
if ( V_10 )
return V_10 ;
F_46 ( 300 ) ;
V_10 = F_12 ( V_2 , V_84 , ( 1 << 7 ) , 0x80 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_47 ( struct V_122 * V_123 , int V_124 )
{
struct V_1 * V_2 = V_123 -> V_125 ;
int V_10 ;
V_10 = F_12 ( V_2 , V_84 , ( 0 << 7 ) , 0x80 ) ;
if ( V_10 )
return V_10 ;
F_46 ( 30 ) ;
V_10 = F_12 ( V_2 , V_84 , ( 1 << 7 ) , 0x80 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_48 ( struct V_122 * V_123 , int V_124 )
{
struct V_1 * V_2 = V_123 -> V_125 ;
int V_10 ;
V_10 = F_12 ( V_2 , V_71 , ( 0 << 1 ) , 0x02 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_49 ( struct V_122 * V_123 , int V_124 ,
int V_129 )
{
struct V_1 * V_2 = V_123 -> V_125 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_10 ;
T_1 V_27 = 0 ;
V_10 = F_13 ( V_2 , V_130 , & V_27 , 0x40 ) ;
if ( V_10 )
return V_10 ;
if ( V_27 == 0 ) {
V_10 = V_131 ;
if ( F_50 ( V_128 , V_8 -> V_127 ) )
V_10 |= V_132 ;
}
return V_10 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_10 ;
V_8 -> V_123 . V_133 = V_134 ;
V_8 -> V_123 . V_135 = F_40 ;
V_8 -> V_123 . V_136 = F_41 ;
V_8 -> V_123 . V_137 = F_42 ;
V_8 -> V_123 . V_138 = F_43 ;
V_8 -> V_123 . V_139 = F_44 ;
V_8 -> V_123 . V_140 = F_47 ;
V_8 -> V_123 . V_141 = F_48 ;
V_8 -> V_123 . V_142 = F_49 ;
V_8 -> V_123 . V_125 = V_2 ;
V_10 = F_12 ( V_2 , V_84 , ( 1 << 7 ) , 0x80 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_12 ( V_2 , V_71 , ( 0 << 2 ) | ( 0 << 1 ) | ( 0 << 0 ) , 0x07 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_12 ( V_2 , V_71 , ( 1 << 2 ) | ( 1 << 1 ) | ( 1 << 0 ) , 0x07 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_52 ( & V_2 -> V_52 [ 0 ] . V_143 , & V_8 -> V_123 , 0 , 1 ) ;
if ( V_10 )
return V_10 ;
V_8 -> V_144 = true ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_144 )
F_54 ( & V_8 -> V_123 ) ;
return;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_56 ( V_2 -> V_15 , 0 , 0 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_17 ( V_2 , 0x01 , 0x03 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_18 ( V_2 , 1 ) ;
if ( V_10 )
return V_10 ;
if ( V_8 -> V_96 ) {
V_10 = F_51 ( V_2 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
return F_53 ( V_2 ) ;
}
