static void F_1 ( struct V_1 * V_1 , bool V_2 )
{
T_1 V_3 ;
void T_2 * V_4 = V_1 -> V_5 ;
if ( ! F_2 ( V_1 ) )
return;
V_3 = F_3 ( V_4 , V_6 ) ;
if ( V_2 ) {
int V_7 = 10000 ;
V_3 &= ~ V_8 ;
V_3 |= V_9 ;
F_4 ( V_4 , V_6 , V_3 ) ;
V_3 = F_3 ( V_4 , V_6 ) ;
while ( V_3 & V_9 ) {
V_3 = F_3 ( V_4 , V_6 ) ;
if ( V_7 -- < 1 )
break;
}
F_5 ( V_1 -> V_10 , L_1 , V_3 ) ;
V_1 -> V_11 |= V_12 ;
switch ( V_1 -> V_13 -> V_14 ) {
case V_15 :
V_1 -> V_13 -> V_14 = V_16 ;
V_1 -> V_17 = F_6 ( V_1 )
&& V_1 -> V_13 -> V_18 -> V_19 ;
if ( V_1 -> V_17 )
F_7 ( & V_1 -> V_20 , V_21
+ F_8 (
V_22 ) ) ;
F_9 ( V_1 , 0 ) ;
break;
#ifdef F_10
case V_23 :
V_1 -> V_13 -> V_14 = V_24 ;
V_1 -> V_17 = F_6 ( V_1 )
&& V_1 -> V_13 -> V_18 -> V_19 ;
F_9 ( V_1 , 0 ) ;
break;
#endif
default:
F_5 ( V_1 -> V_10 , L_2 ,
F_11 ( V_1 -> V_13 -> V_14 ) ) ;
}
} else if ( V_3 & V_9 ) {
V_3 &= ~ V_9 ;
V_3 |= V_8 ;
F_4 ( V_4 , V_6 , V_3 ) ;
F_5 ( V_1 -> V_10 , L_3 , V_3 ) ;
V_1 -> V_11 |= V_25 ;
V_1 -> V_26 = V_21 + F_8 ( 20 ) ;
}
}
static void F_12 ( struct V_1 * V_1 , bool V_27 )
{
T_1 V_3 ;
void T_2 * V_4 = V_1 -> V_5 ;
#ifdef F_10
if ( V_1 -> V_13 -> V_14 == V_28 ) {
F_5 ( V_1 -> V_10 , L_4 ) ;
V_1 -> V_11 &= ~ V_29 ;
return;
}
#endif
if ( ! F_2 ( V_1 ) )
return;
V_3 = F_3 ( V_4 , V_6 ) ;
if ( V_27 ) {
if ( V_3 & V_8 ) {
while ( F_13 ( V_21 , V_1 -> V_26 ) )
F_14 ( 1 ) ;
F_4 ( V_4 , V_6 ,
V_3 & ~ V_8 ) ;
F_14 ( 1 ) ;
}
V_1 -> V_30 = true ;
V_3 &= 0xf0 ;
F_4 ( V_4 , V_6 ,
V_3 | V_31 ) ;
V_1 -> V_11 |= V_29 ;
V_1 -> V_11 &= ~ V_32 ;
V_1 -> V_26 = V_21 + F_8 ( 50 ) ;
} else {
F_5 ( V_1 -> V_10 , L_5 ) ;
F_4 ( V_4 , V_6 ,
V_3 & ~ V_31 ) ;
V_1 -> V_30 = false ;
V_3 = F_3 ( V_4 , V_6 ) ;
if ( V_3 & V_33 ) {
F_5 ( V_1 -> V_10 , L_6 ) ;
V_1 -> V_11 |= V_34 ;
}
V_1 -> V_11 &= ~ V_29 ;
V_1 -> V_11 |= V_32
| ( V_35 << 16 )
| ( V_36 << 16 ) ;
F_15 ( F_16 ( V_1 ) ) ;
V_1 -> V_37 = V_38 ;
}
}
void F_17 ( struct V_1 * V_1 )
{
V_1 -> V_11 = V_39
| ( V_40 << 16 ) ;
F_15 ( F_16 ( V_1 ) ) ;
V_1 -> V_17 = 0 ;
switch ( V_1 -> V_13 -> V_14 ) {
case V_16 :
#ifdef F_10
if ( F_6 ( V_1 )
&& V_1 -> V_13 -> V_18 -> V_19 ) {
V_1 -> V_13 -> V_14 = V_41 ;
V_1 -> V_42 . V_43 = 1 ;
break;
}
#endif
case V_15 :
V_1 -> V_13 -> V_14 = V_44 ;
V_1 -> V_17 = 0 ;
break;
case V_45 :
V_1 -> V_13 -> V_14 = V_28 ;
break;
default:
F_5 ( V_1 -> V_10 , L_7 ,
F_11 ( V_1 -> V_13 -> V_14 ) ) ;
}
}
int F_18 ( struct V_46 * V_47 , char * V_48 )
{
struct V_1 * V_1 = F_19 ( V_47 ) ;
int V_49 = 0 ;
if ( V_1 -> V_11 & 0xffff0000 ) {
* V_48 = 0x02 ;
V_49 = 1 ;
}
return V_49 ;
}
int F_20 (
struct V_46 * V_47 ,
T_3 V_50 ,
T_3 V_51 ,
T_3 V_52 ,
char * V_48 ,
T_3 V_53 )
{
struct V_1 * V_1 = F_19 ( V_47 ) ;
T_4 V_54 ;
int V_49 = 0 ;
unsigned long V_55 ;
F_21 ( & V_1 -> V_56 , V_55 ) ;
if ( F_22 ( ! F_23 ( V_47 ) ) ) {
F_24 ( & V_1 -> V_56 , V_55 ) ;
return - V_57 ;
}
switch ( V_50 ) {
case V_58 :
case V_59 :
switch ( V_51 ) {
case V_60 :
case V_61 :
break;
default:
goto error;
}
break;
case V_62 :
if ( ( V_52 & 0xff ) != 1 )
goto error;
switch ( V_51 ) {
case V_63 :
break;
case V_64 :
F_1 ( V_1 , false ) ;
break;
case V_65 :
if ( ! ( F_6 ( V_1 ) && V_47 -> V_66 . V_67 ) )
F_25 ( V_1 , 0 ) ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
break;
default:
goto error;
}
F_5 ( V_1 -> V_10 , L_8 , V_51 ) ;
V_1 -> V_11 &= ~ ( 1 << V_51 ) ;
break;
case V_73 :
{
struct V_74 * V_75 = ( void * ) V_48 ;
V_75 -> V_76 = 9 ;
V_75 -> V_77 = 0x29 ;
V_75 -> V_78 = 1 ;
V_75 -> V_79 = F_26 (
0x0001
| 0x0010
) ;
V_75 -> V_80 = 5 ;
V_75 -> V_81 = 0 ;
V_75 -> V_82 . V_83 . V_84 [ 0 ] = 0x02 ;
V_75 -> V_82 . V_83 . V_84 [ 1 ] = 0xff ;
}
break;
case V_85 :
V_54 = 0 ;
* ( V_86 * ) V_48 = F_27 ( V_54 ) ;
break;
case V_87 :
if ( V_52 != 1 )
goto error;
if ( ( V_1 -> V_11 & V_29 )
&& F_28 ( V_21 , V_1 -> V_26 ) )
F_12 ( V_1 , false ) ;
if ( ( V_1 -> V_11 & V_25 )
&& F_28 ( V_21 , V_1 -> V_26 ) ) {
T_1 V_3 ;
V_3 = F_3 ( V_1 -> V_5 , V_6 ) ;
V_3 &= ~ V_8 ;
F_5 ( V_1 -> V_10 , L_9 ,
V_3 ) ;
F_4 ( V_1 -> V_5 , V_6 , V_3 ) ;
V_1 -> V_17 = 1 ;
V_1 -> V_11 &= ~ ( V_12
| V_25 ) ;
V_1 -> V_11 |= V_88 << 16 ;
F_15 ( F_16 ( V_1 ) ) ;
V_1 -> V_13 -> V_14 = V_15 ;
}
F_29 ( F_27 ( V_1 -> V_11
& ~ V_25 ) ,
( V_86 * ) V_48 ) ;
F_5 ( V_1 -> V_10 , L_10 ,
V_1 -> V_11 ) ;
break;
case V_89 :
if ( ( V_52 & 0xff ) != 1 )
goto error;
switch ( V_51 ) {
case V_65 :
if ( ! ( F_6 ( V_1 ) && V_47 -> V_66 . V_67 ) )
F_30 ( V_1 ) ;
break;
case V_90 :
F_12 ( V_1 , true ) ;
break;
case V_64 :
F_1 ( V_1 , true ) ;
break;
case V_91 :
if ( F_22 ( F_2 ( V_1 ) ) )
goto error;
V_52 >>= 8 ;
switch ( V_52 ) {
case 1 :
F_31 ( L_11 ) ;
V_54 = V_92 ;
break;
case 2 :
F_31 ( L_12 ) ;
V_54 = V_93 ;
break;
case 3 :
F_31 ( L_13 ) ;
V_54 = V_94 ;
break;
case 4 :
F_31 ( L_14 ) ;
V_54 = V_95 ;
F_32 ( V_1 ) ;
break;
case 5 :
F_31 ( L_15 ) ;
V_54 = V_96
| V_97 ;
F_4 ( V_1 -> V_5 , V_98 ,
V_99 ) ;
break;
case 6 :
F_31 ( L_16 ) ;
V_54 = V_100 ;
break;
default:
goto error;
}
F_4 ( V_1 -> V_5 , V_101 , V_54 ) ;
break;
default:
goto error;
}
F_5 ( V_1 -> V_10 , L_17 , V_51 ) ;
V_1 -> V_11 |= 1 << V_51 ;
break;
default:
error:
V_49 = - V_102 ;
}
F_24 ( & V_1 -> V_56 , V_55 ) ;
return V_49 ;
}
