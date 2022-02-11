static void F_1 ( struct V_1 * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 -> V_4 ;
T_1 V_6 ;
void T_2 * V_7 = V_1 -> V_8 ;
if ( ! F_2 ( V_1 ) )
return;
V_6 = F_3 ( V_7 , V_9 ) ;
if ( V_2 ) {
int V_10 = 10000 ;
V_6 &= ~ V_11 ;
V_6 |= V_12 ;
F_4 ( V_7 , V_9 , V_6 ) ;
V_6 = F_3 ( V_7 , V_9 ) ;
while ( V_6 & V_12 ) {
V_6 = F_3 ( V_7 , V_9 ) ;
if ( V_10 -- < 1 )
break;
}
F_5 ( V_1 -> V_13 , L_1 , V_6 ) ;
V_1 -> V_14 |= V_15 ;
switch ( V_1 -> V_5 -> V_16 ) {
case V_17 :
V_1 -> V_5 -> V_16 = V_18 ;
V_1 -> V_19 = V_4 -> V_20 -> V_21 ;
if ( V_1 -> V_19 )
F_6 ( & V_1 -> V_22 , V_23
+ F_7 (
V_24 ) ) ;
F_8 ( V_1 , 0 ) ;
break;
case V_25 :
V_1 -> V_5 -> V_16 = V_26 ;
V_1 -> V_19 = V_4 -> V_20 -> V_21 ;
F_8 ( V_1 , 0 ) ;
break;
default:
F_5 ( V_1 -> V_13 , L_2 ,
F_9 ( V_1 -> V_5 -> V_16 ) ) ;
}
} else if ( V_6 & V_12 ) {
V_6 &= ~ V_12 ;
V_6 |= V_11 ;
F_4 ( V_7 , V_9 , V_6 ) ;
F_5 ( V_1 -> V_13 , L_3 , V_6 ) ;
V_1 -> V_14 |= V_27 ;
V_1 -> V_28 = V_23 + F_7 ( 20 ) ;
}
}
static void F_10 ( struct V_1 * V_1 , bool V_29 )
{
T_1 V_6 ;
void T_2 * V_7 = V_1 -> V_8 ;
if ( V_1 -> V_5 -> V_16 == V_30 ) {
F_5 ( V_1 -> V_13 , L_4 ) ;
V_1 -> V_14 &= ~ V_31 ;
return;
}
if ( ! F_2 ( V_1 ) )
return;
V_6 = F_3 ( V_7 , V_9 ) ;
if ( V_29 ) {
if ( V_6 & V_11 ) {
while ( F_11 ( V_23 , V_1 -> V_28 ) )
F_12 ( 1 ) ;
F_4 ( V_7 , V_9 ,
V_6 & ~ V_11 ) ;
F_12 ( 1 ) ;
}
V_6 &= 0xf0 ;
F_4 ( V_7 , V_9 ,
V_6 | V_32 ) ;
V_1 -> V_14 |= V_31 ;
V_1 -> V_14 &= ~ V_33 ;
V_1 -> V_28 = V_23 + F_7 ( 50 ) ;
} else {
F_5 ( V_1 -> V_13 , L_5 ) ;
F_4 ( V_7 , V_9 ,
V_6 & ~ V_32 ) ;
V_6 = F_3 ( V_7 , V_9 ) ;
if ( V_6 & V_34 ) {
F_5 ( V_1 -> V_13 , L_6 ) ;
V_1 -> V_14 |= V_35 ;
}
V_1 -> V_14 &= ~ V_31 ;
V_1 -> V_14 |= V_33
| ( V_36 << 16 )
| ( V_37 << 16 ) ;
F_13 ( V_1 -> V_38 ) ;
V_1 -> V_39 = V_40 ;
}
}
void F_14 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 -> V_4 ;
V_1 -> V_14 = V_41
| ( V_42 << 16 ) ;
F_13 ( V_1 -> V_38 ) ;
V_1 -> V_19 = 0 ;
switch ( V_1 -> V_5 -> V_16 ) {
case V_18 :
if ( V_4 -> V_20 -> V_21 ) {
V_1 -> V_5 -> V_16 = V_43 ;
V_1 -> V_44 . V_45 = 1 ;
break;
}
case V_17 :
V_1 -> V_5 -> V_16 = V_46 ;
V_1 -> V_19 = 0 ;
break;
case V_47 :
V_1 -> V_5 -> V_16 = V_30 ;
break;
default:
F_5 ( V_1 -> V_13 , L_7 ,
F_9 ( V_1 -> V_5 -> V_16 ) ) ;
}
}
int F_15 ( struct V_48 * V_38 , char * V_49 )
{
struct V_1 * V_1 = F_16 ( V_38 ) ;
int V_50 = 0 ;
if ( V_1 -> V_14 & 0xffff0000 ) {
* V_49 = 0x02 ;
V_50 = 1 ;
}
return V_50 ;
}
int F_17 (
struct V_48 * V_38 ,
T_3 V_51 ,
T_3 V_52 ,
T_3 V_53 ,
char * V_49 ,
T_3 V_54 )
{
struct V_1 * V_1 = F_16 ( V_38 ) ;
T_4 V_55 ;
int V_50 = 0 ;
unsigned long V_56 ;
F_18 ( & V_1 -> V_57 , V_56 ) ;
if ( F_19 ( ! F_20 ( V_38 ) ) ) {
F_21 ( & V_1 -> V_57 , V_56 ) ;
return - V_58 ;
}
switch ( V_51 ) {
case V_59 :
case V_60 :
switch ( V_52 ) {
case V_61 :
case V_62 :
break;
default:
goto error;
}
break;
case V_63 :
if ( ( V_53 & 0xff ) != 1 )
goto error;
switch ( V_52 ) {
case V_64 :
break;
case V_65 :
F_1 ( V_1 , false ) ;
break;
case V_66 :
if ( ! V_38 -> V_67 . V_68 )
F_22 ( V_1 , 0 ) ;
break;
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
break;
default:
goto error;
}
F_5 ( V_1 -> V_13 , L_8 , V_52 ) ;
V_1 -> V_14 &= ~ ( 1 << V_52 ) ;
break;
case V_74 :
{
struct V_75 * V_76 = ( void * ) V_49 ;
V_76 -> V_77 = 9 ;
V_76 -> V_78 = 0x29 ;
V_76 -> V_79 = 1 ;
V_76 -> V_80 = F_23 (
0x0001
| 0x0010
) ;
V_76 -> V_81 = 5 ;
V_76 -> V_82 = 0 ;
V_76 -> V_83 . V_84 . V_85 [ 0 ] = 0x02 ;
V_76 -> V_83 . V_84 . V_85 [ 1 ] = 0xff ;
}
break;
case V_86 :
V_55 = 0 ;
* ( V_87 * ) V_49 = F_24 ( V_55 ) ;
break;
case V_88 :
if ( V_53 != 1 )
goto error;
if ( ( V_1 -> V_14 & V_31 )
&& F_25 ( V_23 , V_1 -> V_28 ) )
F_10 ( V_1 , false ) ;
if ( ( V_1 -> V_14 & V_27 )
&& F_25 ( V_23 , V_1 -> V_28 ) ) {
T_1 V_6 ;
V_6 = F_3 ( V_1 -> V_8 , V_9 ) ;
V_6 &= ~ V_11 ;
F_5 ( V_1 -> V_13 , L_9 ,
V_6 ) ;
F_4 ( V_1 -> V_8 , V_9 , V_6 ) ;
V_1 -> V_19 = 1 ;
V_1 -> V_14 &= ~ ( V_15
| V_27 ) ;
V_1 -> V_14 |= V_89 << 16 ;
F_13 ( V_1 -> V_38 ) ;
V_1 -> V_5 -> V_16 = V_17 ;
}
F_26 ( F_24 ( V_1 -> V_14
& ~ V_27 ) ,
( V_87 * ) V_49 ) ;
F_5 ( V_1 -> V_13 , L_10 ,
V_1 -> V_14 ) ;
break;
case V_90 :
if ( ( V_53 & 0xff ) != 1 )
goto error;
switch ( V_52 ) {
case V_66 :
if ( ! V_38 -> V_67 . V_68 )
F_27 ( V_1 ) ;
break;
case V_91 :
F_10 ( V_1 , true ) ;
break;
case V_65 :
F_1 ( V_1 , true ) ;
break;
case V_92 :
if ( F_19 ( F_2 ( V_1 ) ) )
goto error;
V_53 >>= 8 ;
switch ( V_53 ) {
case 1 :
F_28 ( L_11 ) ;
V_55 = V_93 ;
break;
case 2 :
F_28 ( L_12 ) ;
V_55 = V_94 ;
break;
case 3 :
F_28 ( L_13 ) ;
V_55 = V_95 ;
break;
case 4 :
F_28 ( L_14 ) ;
V_55 = V_96 ;
F_29 ( V_1 ) ;
break;
case 5 :
F_28 ( L_15 ) ;
V_55 = V_97
| V_98 ;
F_4 ( V_1 -> V_8 , V_99 ,
V_100 ) ;
break;
case 6 :
F_28 ( L_16 ) ;
V_55 = V_101 ;
break;
default:
goto error;
}
F_4 ( V_1 -> V_8 , V_102 , V_55 ) ;
break;
default:
goto error;
}
F_5 ( V_1 -> V_13 , L_17 , V_52 ) ;
V_1 -> V_14 |= 1 << V_52 ;
break;
default:
error:
V_50 = - V_103 ;
}
F_21 ( & V_1 -> V_57 , V_56 ) ;
return V_50 ;
}
