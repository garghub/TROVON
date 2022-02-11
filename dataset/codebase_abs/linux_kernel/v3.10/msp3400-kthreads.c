const char * F_1 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_3 [ V_2 ] . V_4 != NULL ; V_2 ++ )
if ( V_3 [ V_2 ] . V_5 == V_1 )
return V_3 [ V_2 ] . V_4 ;
return L_1 ;
}
static T_1 F_2 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_3 [ V_2 ] . V_4 != NULL ; V_2 ++ )
if ( V_3 [ V_2 ] . V_5 == V_1 )
return V_3 [ V_2 ] . V_1 ;
return V_6 ;
}
static void F_3 ( struct V_7 * V_8 , T_2 V_9 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
if ( V_12 ) {
F_6 ( V_8 , 0x0008 , 0x0520 ) ;
F_6 ( V_8 , 0x0009 , 0x0620 ) ;
} else {
F_6 ( V_8 , 0x0008 , V_9 ) ;
F_6 ( V_8 , 0x0009 , V_9 ) ;
}
F_6 ( V_8 , 0x000a , V_9 ) ;
F_6 ( V_8 , 0x000b , V_9 ) ;
F_6 ( V_8 , 0x000c , V_9 ) ;
if ( V_11 -> V_13 )
F_6 ( V_8 , 0x0041 , V_9 ) ;
}
void F_7 ( struct V_7 * V_8 , int V_14 , int V_15 )
{
F_8 ( V_8 , 0x0093 , V_14 & 0xfff ) ;
F_8 ( V_8 , 0x009b , V_14 >> 12 ) ;
F_8 ( V_8 , 0x00a3 , V_15 & 0xfff ) ;
F_8 ( V_8 , 0x00ab , V_15 >> 12 ) ;
F_8 ( V_8 , 0x0056 , 0 ) ;
}
void F_9 ( struct V_7 * V_8 , int V_16 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
struct V_17 * V_18 = & V_19 [ V_16 ] ;
int V_20 = ( V_11 -> V_21 >> 3 ) & 1 ;
int V_2 ;
F_10 ( 1 , V_22 , V_8 , L_2 , V_16 ) ;
V_11 -> V_16 = V_16 ;
V_11 -> V_23 = V_24 ;
F_8 ( V_8 , 0x00bb , V_18 -> V_25 | ( V_20 ? 0x100 : 0 ) ) ;
for ( V_2 = 5 ; V_2 >= 0 ; V_2 -- )
F_8 ( V_8 , 0x0001 , V_18 -> V_26 [ V_2 ] ) ;
F_8 ( V_8 , 0x0005 , 0x0004 ) ;
F_8 ( V_8 , 0x0005 , 0x0040 ) ;
F_8 ( V_8 , 0x0005 , 0x0000 ) ;
for ( V_2 = 5 ; V_2 >= 0 ; V_2 -- )
F_8 ( V_8 , 0x0005 , V_18 -> V_27 [ V_2 ] ) ;
F_8 ( V_8 , 0x0083 , V_18 -> V_28 ) ;
F_7 ( V_8 , V_18 -> V_14 , V_18 -> V_15 ) ;
F_3 ( V_8 , V_18 -> V_29 ) ;
F_6 ( V_8 , 0x000d , 0x1900 ) ;
F_6 ( V_8 , 0x000e , V_18 -> V_30 ) ;
if ( V_11 -> V_31 )
F_6 ( V_8 , 0x0010 , 0x5a00 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
static char * V_32 [] = {
L_3 , L_4 , L_5 , L_6 , L_7
} ;
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
char * V_33 = ( V_11 -> V_34 >= 0 && V_11 -> V_34 < 5 ) ?
V_32 [ V_11 -> V_34 ] : L_1 ;
int V_9 = 0 ;
int V_34 = V_11 -> V_34 ;
if ( V_11 -> V_35 == V_36 ) {
F_10 ( 1 , V_22 , V_8 ,
L_8 ,
V_11 -> V_34 ) ;
return;
}
if ( V_11 -> V_16 != V_37 ) {
if ( V_11 -> V_23 == V_24 )
V_34 = V_38 ;
else if ( V_11 -> V_23 & V_39 ) {
if ( V_34 == V_38 ||
V_34 == V_40 )
V_34 = V_41 ;
}
else if ( V_34 != V_38 )
V_34 = V_40 ;
}
switch ( V_11 -> V_16 ) {
case V_42 :
F_10 ( 1 , V_22 , V_8 , L_9 , V_33 ) ;
switch ( V_34 ) {
case V_40 :
F_6 ( V_8 , 0x000e , 0x3001 ) ;
break;
case V_38 :
case V_41 :
case V_43 :
case V_44 :
F_6 ( V_8 , 0x000e , 0x3000 ) ;
break;
}
break;
case V_45 :
F_10 ( 1 , V_22 , V_8 , L_10 , V_33 ) ;
switch ( V_34 ) {
case V_38 :
F_7 ( V_8 , F_12 ( 6.5 ) , F_12 ( 6.5 ) ) ;
break;
case V_40 :
case V_44 :
F_7 ( V_8 , F_12 ( 7.2 ) , F_12 ( 7.02 ) ) ;
break;
case V_41 :
F_7 ( V_8 , F_12 ( 7.38 ) , F_12 ( 7.02 ) ) ;
break;
case V_43 :
F_7 ( V_8 , F_12 ( 7.38 ) , F_12 ( 7.02 ) ) ;
break;
}
break;
case V_46 :
case V_47 :
case V_48 :
F_10 ( 1 , V_22 , V_8 ,
L_11 , V_33 ) ;
if ( V_11 -> V_49 )
V_9 = 0x0100 ;
break;
case V_50 :
F_10 ( 1 , V_22 , V_8 ,
L_12 , V_33 ) ;
break;
case V_37 :
F_10 ( 1 , V_22 , V_8 ,
L_13 , V_33 ) ;
V_9 = 0x0200 ;
break;
case V_51 :
F_10 ( 1 , V_22 , V_8 ,
L_14 , V_33 ) ;
break;
default:
F_10 ( 1 , V_22 , V_8 , L_15 ) ;
return;
}
F_10 ( 1 , V_22 , V_8 , L_16 , V_34 ) ;
switch ( V_34 ) {
case V_40 :
case V_44 :
V_9 |= 0x0020 ;
break;
case V_38 :
if ( V_11 -> V_16 == V_48 ) {
F_10 ( 1 , V_22 , V_8 , L_17 ) ;
F_13 ( V_8 , V_52 , 0 ) ;
V_9 = 0x0200 ;
break;
}
if ( V_11 -> V_23 & V_53 )
V_9 = 0x0030 ;
break;
case V_41 :
break;
case V_43 :
V_9 |= 0x0010 ;
break;
}
F_10 ( 1 , V_22 , V_8 ,
L_18 , V_9 ) ;
F_3 ( V_8 , V_9 ) ;
}
static void F_14 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
if ( V_11 -> main == V_11 -> V_54 )
F_10 ( 1 , V_22 , V_8 ,
L_19 ,
V_11 -> main / 910000 , ( V_11 -> main / 910 ) % 1000 ) ;
else
F_10 ( 1 , V_22 , V_8 ,
L_20 ,
V_11 -> main / 910000 , ( V_11 -> main / 910 ) % 1000 ) ;
if ( V_11 -> V_16 == V_46 || V_11 -> V_16 == V_47 )
F_10 ( 1 , V_22 , V_8 ,
L_21 ,
V_11 -> V_54 / 910000 , ( V_11 -> V_54 / 910 ) % 1000 ) ;
if ( V_11 -> V_16 == V_48 )
F_10 ( 1 , V_22 , V_8 ,
L_22 ,
V_11 -> V_54 / 910000 , ( V_11 -> V_54 / 910 ) % 1000 ) ;
if ( V_11 -> V_16 == V_42 && V_11 -> main != V_11 -> V_54 ) {
F_10 ( 1 , V_22 , V_8 ,
L_23 ,
V_11 -> V_54 / 910000 , ( V_11 -> V_54 / 910 ) % 1000 ) ;
}
}
static int F_15 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
int V_55 ;
int V_23 = V_11 -> V_23 ;
int V_56 = V_11 -> V_49 ;
int V_57 = 0 ;
switch ( V_11 -> V_16 ) {
case V_42 :
V_55 = F_16 ( V_8 , 0x18 ) ;
if ( V_55 > 32767 )
V_55 -= 65536 ;
F_10 ( 2 , V_22 , V_8 ,
L_24 , V_55 ) ;
if ( V_55 > 8192 ) {
V_23 = V_53 ;
} else if ( V_55 < - 4096 ) {
V_23 = V_58 | V_39 ;
} else {
V_23 = V_24 ;
}
V_56 = 0 ;
break;
case V_46 :
case V_47 :
case V_48 :
V_55 = F_17 ( V_8 , 0x23 ) ;
F_10 ( 2 , V_22 , V_8 , L_25 ,
V_55 & 1 , ( V_55 & 0x1e ) >> 1 ) ;
if ( V_55 & 1 ) {
switch ( ( V_55 & 0x1e ) >> 1 ) {
case 0 :
case 8 :
V_23 = V_53 ;
break;
case 1 :
case 9 :
V_23 = V_24 ;
break;
case 2 :
case 10 :
V_23 = V_58 | V_39 ;
break;
default:
V_23 = V_24 ;
break;
}
V_56 = 1 ;
} else {
V_56 = 0 ;
V_23 = V_24 ;
}
break;
}
if ( V_23 != V_11 -> V_23 ) {
V_57 = 1 ;
F_10 ( 1 , V_22 , V_8 ,
L_26 ,
V_11 -> V_23 , V_23 ) ;
V_11 -> V_23 = V_23 ;
}
if ( V_56 != V_11 -> V_49 ) {
V_57 = 1 ;
F_10 ( 1 , V_22 , V_8 , L_27 ,
V_11 -> V_49 , V_56 ) ;
V_11 -> V_49 = V_56 ;
}
return V_57 ;
}
static void F_18 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
if ( F_19 ( V_8 ) )
F_20 ( V_8 ) ;
if ( V_59 )
V_11 -> F_18 = 0 ;
}
int F_21 ( void * V_18 )
{
struct V_7 * V_8 = V_18 ;
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
struct V_60 * V_61 ;
int V_62 , V_63 , V_64 , V_65 , V_66 , V_55 , V_2 ;
F_10 ( 1 , V_22 , V_8 , L_28 ) ;
V_11 -> V_67 = V_6 ;
F_22 () ;
for (; ; ) {
F_10 ( 2 , V_22 , V_8 , L_29 ) ;
F_23 ( V_11 , - 1 ) ;
F_10 ( 2 , V_22 , V_8 , L_30 ) ;
V_68:
F_10 ( 2 , V_22 , V_8 , L_31 ) ;
V_11 -> V_68 = 0 ;
if ( F_24 () )
break;
if ( V_11 -> V_69 || V_37 == V_11 -> V_16 ) {
F_10 ( 1 , V_22 , V_8 ,
L_32 ) ;
V_11 -> V_70 = 0 ;
F_25 ( V_11 ) ;
continue;
}
V_11 -> V_70 = 1 ;
F_25 ( V_11 ) ;
F_9 ( V_8 , V_71 ) ;
V_65 = V_66 = 0 ;
V_63 = V_64 = - 1 ;
V_11 -> F_18 = 0 ;
V_11 -> V_49 = 0 ;
if ( F_23 ( V_11 , 200 ) )
goto V_68;
V_61 = V_72 ;
V_62 = F_26 ( V_72 ) ;
if ( V_73 && ( V_11 -> V_74 & V_75 ) ) {
V_63 = 3 ;
V_62 = 0 ;
F_10 ( 1 , V_22 , V_8 , L_33 ) ;
}
for ( V_2 = 0 ; V_2 < V_62 ; V_2 ++ ) {
F_7 ( V_8 , V_61 [ V_2 ] . V_76 , V_61 [ V_2 ] . V_76 ) ;
if ( F_23 ( V_11 , 100 ) )
goto V_68;
V_55 = F_16 ( V_8 , 0x1b ) ;
if ( V_55 > 32767 )
V_55 -= 65536 ;
if ( V_65 < V_55 )
V_65 = V_55 , V_63 = V_2 ;
F_10 ( 1 , V_22 , V_8 ,
L_34 , V_55 , V_61 [ V_2 ] . V_4 ) ;
}
switch ( V_63 ) {
case 1 :
V_61 = V_77 ;
V_62 = F_26 ( V_77 ) ;
break;
case 3 :
V_61 = V_78 ;
V_62 = F_26 ( V_78 ) ;
break;
case 0 :
case 2 :
default:
V_61 = NULL ;
V_62 = 0 ;
break;
}
if ( V_73 && ( V_11 -> V_74 & V_75 ) ) {
V_61 = NULL ;
V_62 = 0 ;
V_64 = 0 ;
}
for ( V_2 = 0 ; V_2 < V_62 ; V_2 ++ ) {
F_7 ( V_8 , V_61 [ V_2 ] . V_76 , V_61 [ V_2 ] . V_76 ) ;
if ( F_23 ( V_11 , 100 ) )
goto V_68;
V_55 = F_16 ( V_8 , 0x1b ) ;
if ( V_55 > 32767 )
V_55 -= 65536 ;
if ( V_66 < V_55 )
V_66 = V_55 , V_64 = V_2 ;
F_10 ( 1 , V_22 , V_8 ,
L_35 , V_55 , V_61 [ V_2 ] . V_4 ) ;
}
V_11 -> main = V_72 [ V_63 ] . V_76 ;
switch ( V_63 ) {
case 1 :
V_11 -> V_67 = V_79 | V_80 ;
if ( V_64 == 0 ) {
V_11 -> V_54 = V_77 [ V_64 ] . V_76 ;
F_9 ( V_8 , V_42 ) ;
V_11 -> F_18 = 1 ;
} else if ( V_64 == 1 && V_11 -> V_31 ) {
V_11 -> V_54 = V_77 [ V_64 ] . V_76 ;
F_9 ( V_8 , V_46 ) ;
V_11 -> V_49 = 1 ;
V_11 -> F_18 = 1 ;
} else {
goto V_81;
}
break;
case 2 :
V_11 -> V_67 = V_82 ;
V_11 -> V_54 = F_12 ( 6.552 ) ;
F_9 ( V_8 , V_47 ) ;
V_11 -> V_49 = 1 ;
V_11 -> F_18 = 1 ;
break;
case 3 :
if ( V_64 == 1 || V_64 == 2 ) {
V_11 -> V_54 = V_78 [ V_64 ] . V_76 ;
F_9 ( V_8 , V_42 ) ;
V_11 -> F_18 = 1 ;
V_11 -> V_67 = V_83 ;
} else if ( V_64 == 0 && ( V_11 -> V_74 & V_75 ) ) {
V_11 -> V_54 = V_78 [ V_64 ] . V_76 ;
F_9 ( V_8 , V_48 ) ;
V_11 -> F_18 = 1 ;
V_11 -> V_67 = V_84 ;
} else if ( V_64 == 0 && V_11 -> V_31 ) {
V_11 -> V_54 = V_78 [ V_64 ] . V_76 ;
F_9 ( V_8 , V_46 ) ;
V_11 -> V_49 = 1 ;
V_11 -> F_18 = 1 ;
V_11 -> V_67 = V_83 ;
} else {
goto V_81;
}
break;
case 0 :
V_11 -> V_67 = V_85 ;
default:
V_81:
V_11 -> V_54 = V_72 [ V_63 ] . V_76 ;
F_9 ( V_8 , V_42 ) ;
break;
}
F_7 ( V_8 , V_11 -> V_54 , V_11 -> main ) ;
V_11 -> V_70 = 0 ;
F_11 ( V_8 ) ;
F_25 ( V_11 ) ;
if ( V_22 )
F_14 ( V_8 ) ;
V_62 = 3 ;
while ( V_11 -> F_18 ) {
if ( F_23 ( V_11 , V_62 ? 1000 : 5000 ) )
goto V_68;
if ( V_62 )
V_62 -- ;
F_18 ( V_8 ) ;
}
}
F_10 ( 1 , V_22 , V_8 , L_36 ) ;
return 0 ;
}
int F_27 ( void * V_18 )
{
struct V_7 * V_8 = V_18 ;
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
int V_55 , V_2 , V_1 , V_62 ;
F_10 ( 1 , V_22 , V_8 , L_37 ) ;
V_11 -> V_67 = V_6 ;
F_22 () ;
for (; ; ) {
F_10 ( 2 , V_22 , V_8 , L_38 ) ;
F_23 ( V_11 , - 1 ) ;
F_10 ( 2 , V_22 , V_8 , L_39 ) ;
V_68:
F_10 ( 2 , V_22 , V_8 , L_31 ) ;
V_11 -> V_68 = 0 ;
if ( F_24 () )
break;
if ( V_11 -> V_16 == V_37 ) {
F_10 ( 1 , V_22 , V_8 ,
L_32 ) ;
V_11 -> V_70 = 0 ;
F_25 ( V_11 ) ;
continue;
}
V_11 -> V_70 = 1 ;
F_25 ( V_11 ) ;
if ( V_11 -> V_69 )
V_1 = 0x40 ;
else
V_1 = ( V_11 -> V_74 & V_86 ) ? 0x20 : 1 ;
V_11 -> F_18 = 0 ;
V_11 -> V_49 = 0 ;
if ( F_23 ( V_11 , 200 ) )
goto V_68;
if ( V_22 )
F_10 ( 2 , V_22 , V_8 ,
L_40 ,
F_1 ( V_1 ) , V_1 ) ;
if ( V_1 != 1 ) {
V_55 = V_1 ;
} else {
F_8 ( V_8 , 0x20 , V_1 ) ;
for (; ; ) {
if ( F_23 ( V_11 , 100 ) )
goto V_68;
V_55 = F_17 ( V_8 , 0x7e ) ;
if ( V_55 < 0x07ff )
break;
F_10 ( 2 , V_22 , V_8 ,
L_41 ) ;
}
}
for ( V_2 = 0 ; V_3 [ V_2 ] . V_4 != NULL ; V_2 ++ )
if ( V_3 [ V_2 ] . V_5 == V_55 )
break;
F_10 ( 1 , V_22 , V_8 , L_42 ,
F_1 ( V_55 ) , V_55 ) ;
V_11 -> main = V_3 [ V_2 ] .main;
V_11 -> V_54 = V_3 [ V_2 ] . V_54 ;
V_11 -> V_1 = V_55 ;
V_11 -> V_23 = V_24 ;
if ( V_73 && ! V_11 -> V_69 &&
( V_11 -> V_74 & V_75 ) && ( V_55 != 0x0009 ) ) {
F_10 ( 1 , V_22 , V_8 , L_43
L_44 ,
V_3 [ 8 ] . V_4 ?
V_3 [ 8 ] . V_4 : L_1 , V_55 ) ;
V_11 -> V_1 = V_55 = 0x0009 ;
F_8 ( V_8 , 0x20 , V_55 ) ;
} else {
V_11 -> V_67 = F_2 ( V_11 -> V_1 ) ;
}
switch ( V_55 ) {
case 0x0008 :
case 0x000a :
case 0x000b :
if ( V_55 == 0x000a )
V_11 -> V_16 = V_47 ;
else
V_11 -> V_16 = V_46 ;
V_11 -> V_49 = 1 ;
V_11 -> F_18 = 1 ;
break;
case 0x0009 :
V_11 -> V_16 = V_48 ;
V_11 -> V_49 = 1 ;
V_11 -> F_18 = 1 ;
break;
case 0x0020 :
V_11 -> V_16 = V_50 ;
break;
case 0x0040 :
V_11 -> V_16 = V_51 ;
V_11 -> V_23 = V_53 ;
F_9 ( V_8 , V_51 ) ;
F_7 ( V_8 , F_12 ( 10.7 ) ,
F_12 ( 10.7 ) ) ;
break;
case 0x0002 :
case 0x0003 :
case 0x0004 :
case 0x0005 :
V_11 -> V_16 = V_42 ;
V_11 -> F_18 = 1 ;
break;
}
F_6 ( V_8 , 0x0d , 0x1900 ) ;
F_6 ( V_8 , 0x0e , 0x3000 ) ;
if ( V_11 -> V_31 )
F_6 ( V_8 , 0x10 , 0x5a00 ) ;
if ( V_11 -> V_87 )
F_8 ( V_8 , 0x40 , V_11 -> V_88 ) ;
F_11 ( V_8 ) ;
V_11 -> V_70 = 0 ;
F_25 ( V_11 ) ;
V_62 = 3 ;
while ( V_11 -> F_18 ) {
if ( F_23 ( V_11 , V_62 ? 1000 : 5000 ) )
goto V_68;
if ( V_62 )
V_62 -- ;
F_18 ( V_8 ) ;
}
}
F_10 ( 1 , V_22 , V_8 , L_36 ) ;
return 0 ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
if ( V_11 -> V_69 ) {
F_10 ( 1 , V_22 , V_8 , L_45 ) ;
return 0x0001 ;
}
if ( V_11 -> V_74 == V_89 ) {
F_10 ( 1 , V_22 , V_8 , L_46 ) ;
return 0x4001 ;
}
if ( V_11 -> V_74 == V_90 ) {
F_10 ( 1 , V_22 , V_8 , L_47 ) ;
return 0x0001 ;
}
if ( V_11 -> V_74 == V_91 ) {
F_10 ( 1 , V_22 , V_8 , L_48 ) ;
return 0x6001 ;
}
if ( V_11 -> V_74 & V_85 ) {
F_10 ( 1 , V_22 , V_8 , L_49 ) ;
return 0x2001 ;
}
return 0x7001 ;
}
static void F_29 ( struct V_7 * V_8 , T_2 V_92 , int V_93 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
int V_94 , V_95 ;
switch ( V_11 -> V_34 ) {
case V_38 :
V_94 = 0 ;
V_95 = 0x30 ;
break;
case V_43 :
V_94 = 4 ;
V_95 = 0x10 ;
break;
case V_44 :
V_94 = 1 ;
V_95 = 0x20 ;
break;
case V_41 :
V_94 = 3 ;
V_95 = 0x00 ;
break;
case V_40 :
default:
V_94 = 3 ;
V_95 = 0x20 ;
break;
}
if ( V_93 == V_96 )
V_94 = ( V_94 << 8 ) | 0x20 ;
else if ( V_93 >= V_97 && V_11 -> V_98 )
V_94 = ( ( V_93 + 1 ) << 8 ) | V_95 ;
else
V_94 = ( V_93 << 8 ) | V_95 ;
F_10 ( 1 , V_22 , V_8 ,
L_50 , V_93 , V_94 , V_92 ) ;
F_6 ( V_8 , V_92 , V_94 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
T_3 V_93 = V_11 -> V_21 ;
F_29 ( V_8 , 0x0008 , ( V_93 >> 4 ) & 0xf ) ;
F_29 ( V_8 , 0x000c , ( V_93 >> 4 ) & 0xf ) ;
F_29 ( V_8 , 0x0009 , ( V_93 >> 8 ) & 0xf ) ;
F_29 ( V_8 , 0x000a , ( V_93 >> 12 ) & 0xf ) ;
if ( V_11 -> V_13 )
F_29 ( V_8 , 0x0041 , ( V_93 >> 16 ) & 0xf ) ;
F_29 ( V_8 , 0x000b , ( V_93 >> 20 ) & 0xf ) ;
}
static void F_31 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
int V_20 = ( V_11 -> V_21 >> 3 ) & 1 ;
int V_99 ;
V_11 -> V_1 = 1 ;
F_32 ( V_8 ) ;
if ( V_11 -> V_87 )
F_8 ( V_8 , 0x40 , V_11 -> V_88 ) ;
V_99 = F_28 ( V_8 ) ;
V_99 |= V_20 ? 0x100 : 0 ;
F_8 ( V_8 , 0x30 , V_99 ) ;
F_30 ( V_8 ) ;
F_6 ( V_8 , 0x0d , 0x1900 ) ;
F_6 ( V_8 , 0x0e , 0x3000 ) ;
if ( V_11 -> V_31 )
F_6 ( V_8 , 0x10 , 0x5a00 ) ;
F_8 ( V_8 , 0x22 , V_100 ) ;
}
int F_33 ( void * V_18 )
{
struct V_7 * V_8 = V_18 ;
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
int V_55 , V_2 ;
F_10 ( 1 , V_22 , V_8 , L_51 ) ;
V_11 -> V_67 = V_6 ;
F_22 () ;
for (; ; ) {
F_10 ( 2 , V_22 , V_8 , L_52 ) ;
F_23 ( V_11 , - 1 ) ;
F_10 ( 2 , V_22 , V_8 , L_53 ) ;
V_68:
F_10 ( 1 , V_22 , V_8 , L_31 ) ;
V_11 -> V_68 = 0 ;
if ( F_24 () )
break;
if ( V_11 -> V_16 == V_37 ) {
F_10 ( 1 , V_22 , V_8 ,
L_32 ) ;
V_11 -> V_70 = 0 ;
F_25 ( V_11 ) ;
continue;
}
F_31 ( V_8 ) ;
V_11 -> V_1 = V_11 -> V_69 ? 0x40 :
( V_11 -> V_101 && V_102 == 1 ) ? 32 : V_102 ;
F_8 ( V_8 , 0x20 , V_11 -> V_1 ) ;
if ( V_11 -> V_1 != 1 )
goto V_103;
F_10 ( 1 , V_22 , V_8 ,
L_54 ) ;
for ( V_2 = 0 ; V_2 < 10 ; V_2 ++ ) {
if ( F_23 ( V_11 , 100 ) )
goto V_68;
V_55 = F_17 ( V_8 , 0x7e ) ;
if ( V_55 < 0x07ff ) {
V_11 -> V_1 = V_55 ;
break;
}
F_10 ( 2 , V_22 , V_8 ,
L_41 ) ;
}
if ( V_11 -> V_1 == 1 ) {
F_10 ( 1 , V_22 , V_8 ,
L_55 ) ;
continue;
}
V_103:
F_10 ( 1 , V_22 , V_8 ,
L_56 ,
F_1 ( V_11 -> V_1 ) , V_11 -> V_1 ) ;
V_11 -> V_67 = F_2 ( V_11 -> V_1 ) ;
if ( V_11 -> V_1 == 9 ) {
F_6 ( V_8 , 0x0e , 0x7c00 ) ;
}
F_25 ( V_11 ) ;
if ( F_6 ( V_8 , 0x13 , V_11 -> V_104 ) )
return - 1 ;
if ( V_11 -> V_1 != 0x20 )
continue;
V_11 -> F_18 = 1 ;
F_18 ( V_8 ) ;
while ( V_11 -> F_18 ) {
F_18 ( V_8 ) ;
if ( F_23 ( V_11 , 5000 ) )
goto V_68;
}
}
F_10 ( 1 , V_22 , V_8 , L_36 ) ;
return 0 ;
}
static int F_34 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
int V_105 = F_17 ( V_8 , 0x0200 ) ;
int V_106 = V_105 & 0x100 ;
int V_107 = V_105 & 0x40 ;
int V_108 = V_11 -> V_23 ;
if ( V_11 -> V_16 == V_37 )
return 0 ;
V_11 -> V_23 = 0 ;
if ( V_107 )
V_11 -> V_23 = V_53 ;
else
V_11 -> V_23 = V_24 ;
if ( V_106 ) {
if ( V_11 -> V_1 == 0x20 )
V_11 -> V_23 |= V_109 ;
else
V_11 -> V_23 =
V_58 | V_39 ;
}
F_10 ( 1 , V_22 , V_8 ,
L_57 ,
V_105 , V_107 , V_106 , V_11 -> V_23 ) ;
return ( V_108 != V_11 -> V_23 ) ;
}
static void F_35 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
if ( V_11 -> V_1 == 0x20 ) {
if ( ( V_11 -> V_23 & V_109 ) &&
( V_11 -> V_34 == V_44 ||
V_11 -> V_34 == V_43 ) ) {
F_8 ( V_8 , 0x20 , 0x21 ) ;
} else {
F_8 ( V_8 , 0x20 , 0x20 ) ;
}
}
F_30 ( V_8 ) ;
}
void F_20 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
switch ( V_11 -> V_35 ) {
case V_110 :
case V_111 :
F_11 ( V_8 ) ;
break;
case V_36 :
F_35 ( V_8 ) ;
break;
}
}
int F_19 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( F_5 ( V_8 ) ) ;
switch ( V_11 -> V_35 ) {
case V_110 :
case V_111 :
return F_15 ( V_8 ) ;
case V_36 :
return F_34 ( V_8 ) ;
}
return 0 ;
}
