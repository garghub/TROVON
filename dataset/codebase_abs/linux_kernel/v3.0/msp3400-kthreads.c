const char * F_1 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_3 [ V_2 ] . V_4 != NULL ; V_2 ++ )
if ( V_3 [ V_2 ] . V_5 == V_1 )
return V_3 [ V_2 ] . V_4 ;
return L_1 ;
}
static void F_2 ( struct V_6 * V_7 , T_1 V_8 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
if ( V_11 ) {
F_5 ( V_7 , 0x0008 , 0x0520 ) ;
F_5 ( V_7 , 0x0009 , 0x0620 ) ;
} else {
F_5 ( V_7 , 0x0008 , V_8 ) ;
F_5 ( V_7 , 0x0009 , V_8 ) ;
}
F_5 ( V_7 , 0x000a , V_8 ) ;
F_5 ( V_7 , 0x000b , V_8 ) ;
F_5 ( V_7 , 0x000c , V_8 ) ;
if ( V_10 -> V_12 )
F_5 ( V_7 , 0x0041 , V_8 ) ;
}
void F_6 ( struct V_6 * V_7 , int V_13 , int V_14 )
{
F_7 ( V_7 , 0x0093 , V_13 & 0xfff ) ;
F_7 ( V_7 , 0x009b , V_13 >> 12 ) ;
F_7 ( V_7 , 0x00a3 , V_14 & 0xfff ) ;
F_7 ( V_7 , 0x00ab , V_14 >> 12 ) ;
F_7 ( V_7 , 0x0056 , 0 ) ;
}
void F_8 ( struct V_6 * V_7 , int V_15 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
struct V_16 * V_17 = & V_18 [ V_15 ] ;
int V_19 = ( V_10 -> V_20 >> 3 ) & 1 ;
int V_2 ;
F_9 ( 1 , V_21 , V_7 , L_2 , V_15 ) ;
V_10 -> V_15 = V_15 ;
V_10 -> V_22 = V_23 ;
F_7 ( V_7 , 0x00bb , V_17 -> V_24 | ( V_19 ? 0x100 : 0 ) ) ;
for ( V_2 = 5 ; V_2 >= 0 ; V_2 -- )
F_7 ( V_7 , 0x0001 , V_17 -> V_25 [ V_2 ] ) ;
F_7 ( V_7 , 0x0005 , 0x0004 ) ;
F_7 ( V_7 , 0x0005 , 0x0040 ) ;
F_7 ( V_7 , 0x0005 , 0x0000 ) ;
for ( V_2 = 5 ; V_2 >= 0 ; V_2 -- )
F_7 ( V_7 , 0x0005 , V_17 -> V_26 [ V_2 ] ) ;
F_7 ( V_7 , 0x0083 , V_17 -> V_27 ) ;
F_6 ( V_7 , V_17 -> V_13 , V_17 -> V_14 ) ;
F_2 ( V_7 , V_17 -> V_28 ) ;
F_5 ( V_7 , 0x000d , 0x1900 ) ;
F_5 ( V_7 , 0x000e , V_17 -> V_29 ) ;
if ( V_10 -> V_30 )
F_5 ( V_7 , 0x0010 , 0x5a00 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
static char * V_31 [] = {
L_3 , L_4 , L_5 , L_6 , L_7
} ;
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
char * V_32 = ( V_10 -> V_33 >= 0 && V_10 -> V_33 < 5 ) ?
V_31 [ V_10 -> V_33 ] : L_1 ;
int V_8 = 0 ;
int V_33 = V_10 -> V_33 ;
if ( V_10 -> V_34 == V_35 ) {
F_9 ( 1 , V_21 , V_7 ,
L_8 ,
V_10 -> V_33 ) ;
return;
}
if ( V_10 -> V_15 != V_36 ) {
if ( V_10 -> V_22 == V_23 )
V_33 = V_37 ;
else if ( V_10 -> V_22 & V_38 ) {
if ( V_33 == V_37 ||
V_33 == V_39 )
V_33 = V_40 ;
}
else if ( V_33 != V_37 )
V_33 = V_39 ;
}
switch ( V_10 -> V_15 ) {
case V_41 :
F_9 ( 1 , V_21 , V_7 , L_9 , V_32 ) ;
switch ( V_33 ) {
case V_39 :
F_5 ( V_7 , 0x000e , 0x3001 ) ;
break;
case V_37 :
case V_40 :
case V_42 :
case V_43 :
F_5 ( V_7 , 0x000e , 0x3000 ) ;
break;
}
break;
case V_44 :
F_9 ( 1 , V_21 , V_7 , L_10 , V_32 ) ;
switch ( V_33 ) {
case V_37 :
F_6 ( V_7 , F_11 ( 6.5 ) , F_11 ( 6.5 ) ) ;
break;
case V_39 :
case V_43 :
F_6 ( V_7 , F_11 ( 7.2 ) , F_11 ( 7.02 ) ) ;
break;
case V_40 :
F_6 ( V_7 , F_11 ( 7.38 ) , F_11 ( 7.02 ) ) ;
break;
case V_42 :
F_6 ( V_7 , F_11 ( 7.38 ) , F_11 ( 7.02 ) ) ;
break;
}
break;
case V_45 :
case V_46 :
case V_47 :
F_9 ( 1 , V_21 , V_7 ,
L_11 , V_32 ) ;
if ( V_10 -> V_48 )
V_8 = 0x0100 ;
break;
case V_49 :
F_9 ( 1 , V_21 , V_7 ,
L_12 , V_32 ) ;
break;
case V_36 :
F_9 ( 1 , V_21 , V_7 ,
L_13 , V_32 ) ;
V_8 = 0x0200 ;
break;
case V_50 :
F_9 ( 1 , V_21 , V_7 ,
L_14 , V_32 ) ;
break;
default:
F_9 ( 1 , V_21 , V_7 , L_15 ) ;
return;
}
F_9 ( 1 , V_21 , V_7 , L_16 , V_33 ) ;
switch ( V_33 ) {
case V_39 :
case V_43 :
V_8 |= 0x0020 ;
break;
case V_37 :
if ( V_10 -> V_15 == V_47 ) {
F_9 ( 1 , V_21 , V_7 , L_17 ) ;
F_12 ( V_7 , V_51 , 0 ) ;
V_8 = 0x0200 ;
break;
}
if ( V_10 -> V_22 & V_52 )
V_8 = 0x0030 ;
break;
case V_40 :
break;
case V_42 :
V_8 |= 0x0010 ;
break;
}
F_9 ( 1 , V_21 , V_7 ,
L_18 , V_8 ) ;
F_2 ( V_7 , V_8 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
if ( V_10 -> main == V_10 -> V_53 )
F_9 ( 1 , V_21 , V_7 ,
L_19 ,
V_10 -> main / 910000 , ( V_10 -> main / 910 ) % 1000 ) ;
else
F_9 ( 1 , V_21 , V_7 ,
L_20 ,
V_10 -> main / 910000 , ( V_10 -> main / 910 ) % 1000 ) ;
if ( V_10 -> V_15 == V_45 || V_10 -> V_15 == V_46 )
F_9 ( 1 , V_21 , V_7 ,
L_21 ,
V_10 -> V_53 / 910000 , ( V_10 -> V_53 / 910 ) % 1000 ) ;
if ( V_10 -> V_15 == V_47 )
F_9 ( 1 , V_21 , V_7 ,
L_22 ,
V_10 -> V_53 / 910000 , ( V_10 -> V_53 / 910 ) % 1000 ) ;
if ( V_10 -> V_15 == V_41 && V_10 -> main != V_10 -> V_53 ) {
F_9 ( 1 , V_21 , V_7 ,
L_23 ,
V_10 -> V_53 / 910000 , ( V_10 -> V_53 / 910 ) % 1000 ) ;
}
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
int V_54 ;
int V_22 = V_10 -> V_22 ;
int V_55 = V_10 -> V_48 ;
int V_56 = 0 ;
switch ( V_10 -> V_15 ) {
case V_41 :
V_54 = F_15 ( V_7 , 0x18 ) ;
if ( V_54 > 32767 )
V_54 -= 65536 ;
F_9 ( 2 , V_21 , V_7 ,
L_24 , V_54 ) ;
if ( V_54 > 8192 ) {
V_22 = V_52 ;
} else if ( V_54 < - 4096 ) {
V_22 = V_57 | V_38 ;
} else {
V_22 = V_23 ;
}
V_55 = 0 ;
break;
case V_45 :
case V_46 :
case V_47 :
V_54 = F_16 ( V_7 , 0x23 ) ;
F_9 ( 2 , V_21 , V_7 , L_25 ,
V_54 & 1 , ( V_54 & 0x1e ) >> 1 ) ;
if ( V_54 & 1 ) {
switch ( ( V_54 & 0x1e ) >> 1 ) {
case 0 :
case 8 :
V_22 = V_52 ;
break;
case 1 :
case 9 :
V_22 = V_23 ;
break;
case 2 :
case 10 :
V_22 = V_57 | V_38 ;
break;
default:
V_22 = V_23 ;
break;
}
V_55 = 1 ;
} else {
V_55 = 0 ;
V_22 = V_23 ;
}
break;
}
if ( V_22 != V_10 -> V_22 ) {
V_56 = 1 ;
F_9 ( 1 , V_21 , V_7 ,
L_26 ,
V_10 -> V_22 , V_22 ) ;
V_10 -> V_22 = V_22 ;
}
if ( V_55 != V_10 -> V_48 ) {
V_56 = 1 ;
F_9 ( 1 , V_21 , V_7 , L_27 ,
V_10 -> V_48 , V_55 ) ;
V_10 -> V_48 = V_55 ;
}
return V_56 ;
}
static void F_17 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
if ( F_18 ( V_7 ) )
F_19 ( V_7 ) ;
if ( V_58 )
V_10 -> F_17 = 0 ;
}
int F_20 ( void * V_17 )
{
struct V_6 * V_7 = V_17 ;
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
struct V_59 * V_60 ;
int V_61 , V_62 , V_63 , V_64 , V_65 , V_54 , V_2 ;
F_9 ( 1 , V_21 , V_7 , L_28 ) ;
F_21 () ;
for (; ; ) {
F_9 ( 2 , V_21 , V_7 , L_29 ) ;
F_22 ( V_10 , - 1 ) ;
F_9 ( 2 , V_21 , V_7 , L_30 ) ;
V_66:
F_9 ( 2 , V_21 , V_7 , L_31 ) ;
V_10 -> V_66 = 0 ;
if ( F_23 () )
break;
if ( V_10 -> V_67 || V_36 == V_10 -> V_15 ) {
F_9 ( 1 , V_21 , V_7 ,
L_32 ) ;
V_10 -> V_68 = 0 ;
F_24 ( V_10 ) ;
continue;
}
V_10 -> V_68 = 1 ;
F_24 ( V_10 ) ;
F_8 ( V_7 , V_69 ) ;
V_64 = V_65 = 0 ;
V_62 = V_63 = - 1 ;
V_10 -> F_17 = 0 ;
V_10 -> V_48 = 0 ;
if ( F_22 ( V_10 , 200 ) )
goto V_66;
V_60 = V_70 ;
V_61 = F_25 ( V_70 ) ;
if ( V_71 && ( V_10 -> V_72 & V_73 ) ) {
V_62 = 3 ;
V_61 = 0 ;
F_9 ( 1 , V_21 , V_7 , L_33 ) ;
}
for ( V_2 = 0 ; V_2 < V_61 ; V_2 ++ ) {
F_6 ( V_7 , V_60 [ V_2 ] . V_74 , V_60 [ V_2 ] . V_74 ) ;
if ( F_22 ( V_10 , 100 ) )
goto V_66;
V_54 = F_15 ( V_7 , 0x1b ) ;
if ( V_54 > 32767 )
V_54 -= 65536 ;
if ( V_64 < V_54 )
V_64 = V_54 , V_62 = V_2 ;
F_9 ( 1 , V_21 , V_7 ,
L_34 , V_54 , V_60 [ V_2 ] . V_4 ) ;
}
switch ( V_62 ) {
case 1 :
V_60 = V_75 ;
V_61 = F_25 ( V_75 ) ;
break;
case 3 :
V_60 = V_76 ;
V_61 = F_25 ( V_76 ) ;
break;
case 0 :
case 2 :
default:
V_60 = NULL ;
V_61 = 0 ;
break;
}
if ( V_71 && ( V_10 -> V_72 & V_73 ) ) {
V_60 = NULL ;
V_61 = 0 ;
V_63 = 0 ;
}
for ( V_2 = 0 ; V_2 < V_61 ; V_2 ++ ) {
F_6 ( V_7 , V_60 [ V_2 ] . V_74 , V_60 [ V_2 ] . V_74 ) ;
if ( F_22 ( V_10 , 100 ) )
goto V_66;
V_54 = F_15 ( V_7 , 0x1b ) ;
if ( V_54 > 32767 )
V_54 -= 65536 ;
if ( V_65 < V_54 )
V_65 = V_54 , V_63 = V_2 ;
F_9 ( 1 , V_21 , V_7 ,
L_35 , V_54 , V_60 [ V_2 ] . V_4 ) ;
}
V_10 -> main = V_70 [ V_62 ] . V_74 ;
switch ( V_62 ) {
case 1 :
if ( V_63 == 0 ) {
V_10 -> V_53 = V_75 [ V_63 ] . V_74 ;
F_8 ( V_7 , V_41 ) ;
V_10 -> F_17 = 1 ;
} else if ( V_63 == 1 && V_10 -> V_30 ) {
V_10 -> V_53 = V_75 [ V_63 ] . V_74 ;
F_8 ( V_7 , V_45 ) ;
V_10 -> V_48 = 1 ;
V_10 -> F_17 = 1 ;
} else {
goto V_77;
}
break;
case 2 :
V_10 -> V_53 = F_11 ( 6.552 ) ;
F_8 ( V_7 , V_46 ) ;
V_10 -> V_48 = 1 ;
V_10 -> F_17 = 1 ;
break;
case 3 :
if ( V_63 == 1 || V_63 == 2 ) {
V_10 -> V_53 = V_76 [ V_63 ] . V_74 ;
F_8 ( V_7 , V_41 ) ;
V_10 -> F_17 = 1 ;
} else if ( V_63 == 0 && ( V_10 -> V_72 & V_73 ) ) {
V_10 -> V_53 = V_76 [ V_63 ] . V_74 ;
F_8 ( V_7 , V_47 ) ;
V_10 -> F_17 = 1 ;
} else if ( V_63 == 0 && V_10 -> V_30 ) {
V_10 -> V_53 = V_76 [ V_63 ] . V_74 ;
F_8 ( V_7 , V_45 ) ;
V_10 -> V_48 = 1 ;
V_10 -> F_17 = 1 ;
} else {
goto V_77;
}
break;
case 0 :
default:
V_77:
V_10 -> V_53 = V_70 [ V_62 ] . V_74 ;
F_8 ( V_7 , V_41 ) ;
break;
}
F_6 ( V_7 , V_10 -> V_53 , V_10 -> main ) ;
V_10 -> V_68 = 0 ;
F_10 ( V_7 ) ;
F_24 ( V_10 ) ;
if ( V_21 )
F_13 ( V_7 ) ;
V_61 = 3 ;
while ( V_10 -> F_17 ) {
if ( F_22 ( V_10 , V_61 ? 1000 : 5000 ) )
goto V_66;
if ( V_61 )
V_61 -- ;
F_17 ( V_7 ) ;
}
}
F_9 ( 1 , V_21 , V_7 , L_36 ) ;
return 0 ;
}
int F_26 ( void * V_17 )
{
struct V_6 * V_7 = V_17 ;
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
int V_54 , V_2 , V_1 , V_61 ;
F_9 ( 1 , V_21 , V_7 , L_37 ) ;
F_21 () ;
for (; ; ) {
F_9 ( 2 , V_21 , V_7 , L_38 ) ;
F_22 ( V_10 , - 1 ) ;
F_9 ( 2 , V_21 , V_7 , L_39 ) ;
V_66:
F_9 ( 2 , V_21 , V_7 , L_31 ) ;
V_10 -> V_66 = 0 ;
if ( F_23 () )
break;
if ( V_10 -> V_15 == V_36 ) {
F_9 ( 1 , V_21 , V_7 ,
L_32 ) ;
V_10 -> V_68 = 0 ;
F_24 ( V_10 ) ;
continue;
}
V_10 -> V_68 = 1 ;
F_24 ( V_10 ) ;
if ( V_10 -> V_67 )
V_1 = 0x40 ;
else
V_1 = ( V_10 -> V_72 & V_78 ) ? 0x20 : 1 ;
V_10 -> F_17 = 0 ;
V_10 -> V_48 = 0 ;
if ( F_22 ( V_10 , 200 ) )
goto V_66;
if ( V_21 )
F_9 ( 2 , V_21 , V_7 ,
L_40 ,
F_1 ( V_1 ) , V_1 ) ;
if ( V_1 != 1 ) {
V_54 = V_1 ;
} else {
F_7 ( V_7 , 0x20 , V_1 ) ;
for (; ; ) {
if ( F_22 ( V_10 , 100 ) )
goto V_66;
V_54 = F_16 ( V_7 , 0x7e ) ;
if ( V_54 < 0x07ff )
break;
F_9 ( 2 , V_21 , V_7 ,
L_41 ) ;
}
}
for ( V_2 = 0 ; V_3 [ V_2 ] . V_4 != NULL ; V_2 ++ )
if ( V_3 [ V_2 ] . V_5 == V_54 )
break;
F_9 ( 1 , V_21 , V_7 , L_42 ,
F_1 ( V_54 ) , V_54 ) ;
V_10 -> main = V_3 [ V_2 ] .main;
V_10 -> V_53 = V_3 [ V_2 ] . V_53 ;
V_10 -> V_1 = V_54 ;
V_10 -> V_22 = V_23 ;
if ( V_71 && ! V_10 -> V_67 &&
( V_10 -> V_72 & V_73 ) && ( V_54 != 0x0009 ) ) {
F_9 ( 1 , V_21 , V_7 , L_43
L_44 ,
V_3 [ 8 ] . V_4 ?
V_3 [ 8 ] . V_4 : L_1 , V_54 ) ;
V_10 -> V_1 = V_54 = 0x0009 ;
F_7 ( V_7 , 0x20 , V_54 ) ;
}
switch ( V_54 ) {
case 0x0008 :
case 0x000a :
case 0x000b :
if ( V_54 == 0x000a )
V_10 -> V_15 = V_46 ;
else
V_10 -> V_15 = V_45 ;
V_10 -> V_48 = 1 ;
V_10 -> F_17 = 1 ;
break;
case 0x0009 :
V_10 -> V_15 = V_47 ;
V_10 -> V_48 = 1 ;
V_10 -> F_17 = 1 ;
break;
case 0x0020 :
V_10 -> V_15 = V_49 ;
break;
case 0x0040 :
V_10 -> V_15 = V_50 ;
V_10 -> V_22 = V_52 ;
F_8 ( V_7 , V_50 ) ;
F_6 ( V_7 , F_11 ( 10.7 ) ,
F_11 ( 10.7 ) ) ;
break;
case 0x0002 :
case 0x0003 :
case 0x0004 :
case 0x0005 :
V_10 -> V_15 = V_41 ;
V_10 -> F_17 = 1 ;
break;
}
F_5 ( V_7 , 0x0d , 0x1900 ) ;
F_5 ( V_7 , 0x0e , 0x3000 ) ;
if ( V_10 -> V_30 )
F_5 ( V_7 , 0x10 , 0x5a00 ) ;
if ( V_10 -> V_79 )
F_7 ( V_7 , 0x40 , V_10 -> V_80 ) ;
F_10 ( V_7 ) ;
V_10 -> V_68 = 0 ;
F_24 ( V_10 ) ;
V_61 = 3 ;
while ( V_10 -> F_17 ) {
if ( F_22 ( V_10 , V_61 ? 1000 : 5000 ) )
goto V_66;
if ( V_61 )
V_61 -- ;
F_17 ( V_7 ) ;
}
}
F_9 ( 1 , V_21 , V_7 , L_36 ) ;
return 0 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
if ( V_10 -> V_67 ) {
F_9 ( 1 , V_21 , V_7 , L_45 ) ;
return 0x0001 ;
}
if ( V_10 -> V_72 == V_81 ) {
F_9 ( 1 , V_21 , V_7 , L_46 ) ;
return 0x4001 ;
}
if ( V_10 -> V_72 == V_82 ) {
F_9 ( 1 , V_21 , V_7 , L_47 ) ;
return 0x0001 ;
}
if ( V_10 -> V_72 == V_83 ) {
F_9 ( 1 , V_21 , V_7 , L_48 ) ;
return 0x6001 ;
}
if ( V_10 -> V_72 & V_84 ) {
F_9 ( 1 , V_21 , V_7 , L_49 ) ;
return 0x2001 ;
}
return 0x7001 ;
}
static void F_28 ( struct V_6 * V_7 , T_1 V_85 , int V_86 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
int V_87 , V_88 ;
switch ( V_10 -> V_33 ) {
case V_37 :
V_87 = 0 ;
V_88 = 0x30 ;
break;
case V_42 :
V_87 = 4 ;
V_88 = 0x10 ;
break;
case V_43 :
V_87 = 1 ;
V_88 = 0x20 ;
break;
case V_40 :
V_87 = 3 ;
V_88 = 0x00 ;
break;
case V_39 :
default:
V_87 = 3 ;
V_88 = 0x20 ;
break;
}
if ( V_86 == V_89 )
V_87 = ( V_87 << 8 ) | 0x20 ;
else if ( V_86 >= V_90 && V_10 -> V_91 )
V_87 = ( ( V_86 + 1 ) << 8 ) | V_88 ;
else
V_87 = ( V_86 << 8 ) | V_88 ;
F_9 ( 1 , V_21 , V_7 ,
L_50 , V_86 , V_87 , V_85 ) ;
F_5 ( V_7 , V_85 , V_87 ) ;
}
static void F_29 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
T_2 V_86 = V_10 -> V_20 ;
F_28 ( V_7 , 0x0008 , ( V_86 >> 4 ) & 0xf ) ;
F_28 ( V_7 , 0x000c , ( V_86 >> 4 ) & 0xf ) ;
F_28 ( V_7 , 0x0009 , ( V_86 >> 8 ) & 0xf ) ;
F_28 ( V_7 , 0x000a , ( V_86 >> 12 ) & 0xf ) ;
if ( V_10 -> V_12 )
F_28 ( V_7 , 0x0041 , ( V_86 >> 16 ) & 0xf ) ;
F_28 ( V_7 , 0x000b , ( V_86 >> 20 ) & 0xf ) ;
}
static void F_30 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
int V_19 = ( V_10 -> V_20 >> 3 ) & 1 ;
int V_92 ;
V_10 -> V_1 = 1 ;
F_31 ( V_7 ) ;
if ( V_10 -> V_79 )
F_7 ( V_7 , 0x40 , V_10 -> V_80 ) ;
V_92 = F_27 ( V_7 ) ;
V_92 |= V_19 ? 0x100 : 0 ;
F_7 ( V_7 , 0x30 , V_92 ) ;
F_29 ( V_7 ) ;
F_5 ( V_7 , 0x0d , 0x1900 ) ;
F_5 ( V_7 , 0x0e , 0x3000 ) ;
if ( V_10 -> V_30 )
F_5 ( V_7 , 0x10 , 0x5a00 ) ;
F_7 ( V_7 , 0x22 , V_93 ) ;
}
int F_32 ( void * V_17 )
{
struct V_6 * V_7 = V_17 ;
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
int V_54 , V_2 ;
F_9 ( 1 , V_21 , V_7 , L_51 ) ;
F_21 () ;
for (; ; ) {
F_9 ( 2 , V_21 , V_7 , L_52 ) ;
F_22 ( V_10 , - 1 ) ;
F_9 ( 2 , V_21 , V_7 , L_53 ) ;
V_66:
F_9 ( 1 , V_21 , V_7 , L_31 ) ;
V_10 -> V_66 = 0 ;
if ( F_23 () )
break;
if ( V_10 -> V_15 == V_36 ) {
F_9 ( 1 , V_21 , V_7 ,
L_32 ) ;
V_10 -> V_68 = 0 ;
F_24 ( V_10 ) ;
continue;
}
F_30 ( V_7 ) ;
V_10 -> V_1 = V_10 -> V_67 ? 0x40 :
( V_10 -> V_94 && V_95 == 1 ) ? 32 : V_95 ;
F_7 ( V_7 , 0x20 , V_10 -> V_1 ) ;
if ( V_10 -> V_1 != 1 )
goto V_96;
F_9 ( 1 , V_21 , V_7 ,
L_54 ) ;
for ( V_2 = 0 ; V_2 < 10 ; V_2 ++ ) {
if ( F_22 ( V_10 , 100 ) )
goto V_66;
V_54 = F_16 ( V_7 , 0x7e ) ;
if ( V_54 < 0x07ff ) {
V_10 -> V_1 = V_54 ;
break;
}
F_9 ( 2 , V_21 , V_7 ,
L_41 ) ;
}
if ( V_10 -> V_1 == 1 ) {
F_9 ( 1 , V_21 , V_7 ,
L_55 ) ;
continue;
}
V_96:
F_9 ( 1 , V_21 , V_7 ,
L_56 ,
F_1 ( V_10 -> V_1 ) , V_10 -> V_1 ) ;
if ( V_10 -> V_1 == 9 ) {
F_5 ( V_7 , 0x0e , 0x7c00 ) ;
}
F_24 ( V_10 ) ;
if ( F_5 ( V_7 , 0x13 , V_10 -> V_97 ) )
return - 1 ;
if ( V_10 -> V_1 != 0x20 )
continue;
V_10 -> F_17 = 1 ;
F_17 ( V_7 ) ;
while ( V_10 -> F_17 ) {
F_17 ( V_7 ) ;
if ( F_22 ( V_10 , 5000 ) )
goto V_66;
}
}
F_9 ( 1 , V_21 , V_7 , L_36 ) ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
int V_98 = F_16 ( V_7 , 0x0200 ) ;
int V_99 = V_98 & 0x100 ;
int V_100 = V_98 & 0x40 ;
int V_101 = V_10 -> V_22 ;
if ( V_10 -> V_15 == V_36 )
return 0 ;
V_10 -> V_22 = 0 ;
if ( V_100 )
V_10 -> V_22 = V_52 ;
else
V_10 -> V_22 = V_23 ;
if ( V_99 ) {
if ( V_10 -> V_1 == 0x20 )
V_10 -> V_22 |= V_102 ;
else
V_10 -> V_22 =
V_57 | V_38 ;
}
F_9 ( 1 , V_21 , V_7 ,
L_57 ,
V_98 , V_100 , V_99 , V_10 -> V_22 ) ;
return ( V_101 != V_10 -> V_22 ) ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
if ( V_10 -> V_1 == 0x20 ) {
if ( ( V_10 -> V_22 & V_102 ) &&
( V_10 -> V_33 == V_43 ||
V_10 -> V_33 == V_42 ) ) {
F_7 ( V_7 , 0x20 , 0x21 ) ;
} else {
F_7 ( V_7 , 0x20 , 0x20 ) ;
}
}
F_29 ( V_7 ) ;
}
void F_19 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
switch ( V_10 -> V_34 ) {
case V_103 :
case V_104 :
F_10 ( V_7 ) ;
break;
case V_35 :
F_34 ( V_7 ) ;
break;
}
}
int F_18 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( F_4 ( V_7 ) ) ;
switch ( V_10 -> V_34 ) {
case V_103 :
case V_104 :
return F_14 ( V_7 ) ;
case V_35 :
return F_33 ( V_7 ) ;
}
return 0 ;
}
