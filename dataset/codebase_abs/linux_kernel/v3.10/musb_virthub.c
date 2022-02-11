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
V_1 -> V_32 = true ;
V_6 &= 0xf0 ;
F_4 ( V_7 , V_9 ,
V_6 | V_33 ) ;
V_1 -> V_14 |= V_31 ;
V_1 -> V_14 &= ~ V_34 ;
V_1 -> V_28 = V_23 + F_7 ( 50 ) ;
} else {
F_5 ( V_1 -> V_13 , L_5 ) ;
F_4 ( V_7 , V_9 ,
V_6 & ~ V_33 ) ;
V_1 -> V_32 = false ;
V_6 = F_3 ( V_7 , V_9 ) ;
if ( V_6 & V_35 ) {
F_5 ( V_1 -> V_13 , L_6 ) ;
V_1 -> V_14 |= V_36 ;
}
V_1 -> V_14 &= ~ V_31 ;
V_1 -> V_14 |= V_34
| ( V_37 << 16 )
| ( V_38 << 16 ) ;
F_13 ( F_14 ( V_1 ) ) ;
V_1 -> V_39 = V_40 ;
}
}
void F_15 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 -> V_4 ;
V_1 -> V_14 = V_41
| ( V_42 << 16 ) ;
F_13 ( F_14 ( V_1 ) ) ;
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
int F_16 ( struct V_48 * V_49 , char * V_50 )
{
struct V_1 * V_1 = F_17 ( V_49 ) ;
int V_51 = 0 ;
if ( V_1 -> V_14 & 0xffff0000 ) {
* V_50 = 0x02 ;
V_51 = 1 ;
}
return V_51 ;
}
int F_18 (
struct V_48 * V_49 ,
T_3 V_52 ,
T_3 V_53 ,
T_3 V_54 ,
char * V_50 ,
T_3 V_55 )
{
struct V_1 * V_1 = F_17 ( V_49 ) ;
T_4 V_56 ;
int V_51 = 0 ;
unsigned long V_57 ;
F_19 ( & V_1 -> V_58 , V_57 ) ;
if ( F_20 ( ! F_21 ( V_49 ) ) ) {
F_22 ( & V_1 -> V_58 , V_57 ) ;
return - V_59 ;
}
switch ( V_52 ) {
case V_60 :
case V_61 :
switch ( V_53 ) {
case V_62 :
case V_63 :
break;
default:
goto error;
}
break;
case V_64 :
if ( ( V_54 & 0xff ) != 1 )
goto error;
switch ( V_53 ) {
case V_65 :
break;
case V_66 :
F_1 ( V_1 , false ) ;
break;
case V_67 :
if ( ! V_49 -> V_68 . V_69 )
F_23 ( V_1 , 0 ) ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
break;
default:
goto error;
}
F_5 ( V_1 -> V_13 , L_8 , V_53 ) ;
V_1 -> V_14 &= ~ ( 1 << V_53 ) ;
break;
case V_75 :
{
struct V_76 * V_77 = ( void * ) V_50 ;
V_77 -> V_78 = 9 ;
V_77 -> V_79 = 0x29 ;
V_77 -> V_80 = 1 ;
V_77 -> V_81 = F_24 (
0x0001
| 0x0010
) ;
V_77 -> V_82 = 5 ;
V_77 -> V_83 = 0 ;
V_77 -> V_84 . V_85 . V_86 [ 0 ] = 0x02 ;
V_77 -> V_84 . V_85 . V_86 [ 1 ] = 0xff ;
}
break;
case V_87 :
V_56 = 0 ;
* ( V_88 * ) V_50 = F_25 ( V_56 ) ;
break;
case V_89 :
if ( V_54 != 1 )
goto error;
if ( ( V_1 -> V_14 & V_31 )
&& F_26 ( V_23 , V_1 -> V_28 ) )
F_10 ( V_1 , false ) ;
if ( ( V_1 -> V_14 & V_27 )
&& F_26 ( V_23 , V_1 -> V_28 ) ) {
T_1 V_6 ;
V_6 = F_3 ( V_1 -> V_8 , V_9 ) ;
V_6 &= ~ V_11 ;
F_5 ( V_1 -> V_13 , L_9 ,
V_6 ) ;
F_4 ( V_1 -> V_8 , V_9 , V_6 ) ;
V_1 -> V_19 = 1 ;
V_1 -> V_14 &= ~ ( V_15
| V_27 ) ;
V_1 -> V_14 |= V_90 << 16 ;
F_13 ( F_14 ( V_1 ) ) ;
V_1 -> V_5 -> V_16 = V_17 ;
}
F_27 ( F_25 ( V_1 -> V_14
& ~ V_27 ) ,
( V_88 * ) V_50 ) ;
F_5 ( V_1 -> V_13 , L_10 ,
V_1 -> V_14 ) ;
break;
case V_91 :
if ( ( V_54 & 0xff ) != 1 )
goto error;
switch ( V_53 ) {
case V_67 :
if ( ! V_49 -> V_68 . V_69 )
F_28 ( V_1 ) ;
break;
case V_92 :
F_10 ( V_1 , true ) ;
break;
case V_66 :
F_1 ( V_1 , true ) ;
break;
case V_93 :
if ( F_20 ( F_2 ( V_1 ) ) )
goto error;
V_54 >>= 8 ;
switch ( V_54 ) {
case 1 :
F_29 ( L_11 ) ;
V_56 = V_94 ;
break;
case 2 :
F_29 ( L_12 ) ;
V_56 = V_95 ;
break;
case 3 :
F_29 ( L_13 ) ;
V_56 = V_96 ;
break;
case 4 :
F_29 ( L_14 ) ;
V_56 = V_97 ;
F_30 ( V_1 ) ;
break;
case 5 :
F_29 ( L_15 ) ;
V_56 = V_98
| V_99 ;
F_4 ( V_1 -> V_8 , V_100 ,
V_101 ) ;
break;
case 6 :
F_29 ( L_16 ) ;
V_56 = V_102 ;
break;
default:
goto error;
}
F_4 ( V_1 -> V_8 , V_103 , V_56 ) ;
break;
default:
goto error;
}
F_5 ( V_1 -> V_13 , L_17 , V_53 ) ;
V_1 -> V_14 |= 1 << V_53 ;
break;
default:
error:
V_51 = - V_104 ;
}
F_22 ( & V_1 -> V_58 , V_57 ) ;
return V_51 ;
}
