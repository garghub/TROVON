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
static int F_17 ( struct V_1 * V_1 )
{
#ifdef F_18
return 1 ;
#else
if ( V_1 -> V_51 == V_52 )
return 1 ;
return V_1 -> V_44 . V_53 . V_54 != NULL ;
#endif
}
int F_19 (
struct V_48 * V_38 ,
T_3 V_55 ,
T_3 V_56 ,
T_3 V_57 ,
char * V_49 ,
T_3 V_58 )
{
struct V_1 * V_1 = F_16 ( V_38 ) ;
T_4 V_59 ;
int V_50 = 0 ;
unsigned long V_60 ;
F_20 ( & V_1 -> V_61 , V_60 ) ;
if ( F_21 ( ! F_22 ( V_38 ) ) ) {
F_23 ( & V_1 -> V_61 , V_60 ) ;
return - V_62 ;
}
switch ( V_55 ) {
case V_63 :
case V_64 :
switch ( V_56 ) {
case V_65 :
case V_66 :
break;
default:
goto error;
}
break;
case V_67 :
if ( ( V_57 & 0xff ) != 1 )
goto error;
switch ( V_56 ) {
case V_68 :
break;
case V_69 :
F_1 ( V_1 , false ) ;
break;
case V_70 :
if ( ! V_38 -> V_71 . V_72 )
F_24 ( V_1 , 0 ) ;
break;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
break;
default:
goto error;
}
F_5 ( V_1 -> V_13 , L_8 , V_56 ) ;
V_1 -> V_14 &= ~ ( 1 << V_56 ) ;
break;
case V_78 :
{
struct V_79 * V_80 = ( void * ) V_49 ;
V_80 -> V_81 = 9 ;
V_80 -> V_82 = 0x29 ;
V_80 -> V_83 = 1 ;
V_80 -> V_84 = F_25 (
0x0001
| 0x0010
) ;
V_80 -> V_85 = 5 ;
V_80 -> V_86 = 0 ;
V_80 -> V_87 . V_88 . V_89 [ 0 ] = 0x02 ;
V_80 -> V_87 . V_88 . V_89 [ 1 ] = 0xff ;
}
break;
case V_90 :
V_59 = 0 ;
* ( V_91 * ) V_49 = F_26 ( V_59 ) ;
break;
case V_92 :
if ( V_57 != 1 )
goto error;
if ( ( V_1 -> V_14 & V_31 )
&& F_27 ( V_23 , V_1 -> V_28 ) )
F_10 ( V_1 , false ) ;
if ( ( V_1 -> V_14 & V_27 )
&& F_27 ( V_23 , V_1 -> V_28 ) ) {
T_1 V_6 ;
V_6 = F_3 ( V_1 -> V_8 , V_9 ) ;
V_6 &= ~ V_11 ;
F_5 ( V_1 -> V_13 , L_9 ,
V_6 ) ;
F_4 ( V_1 -> V_8 , V_9 , V_6 ) ;
V_1 -> V_19 = 1 ;
V_1 -> V_14 &= ~ ( V_15
| V_27 ) ;
V_1 -> V_14 |= V_93 << 16 ;
F_13 ( V_1 -> V_38 ) ;
V_1 -> V_5 -> V_16 = V_17 ;
}
F_28 ( F_26 ( V_1 -> V_14
& ~ V_27 ) ,
( V_91 * ) V_49 ) ;
F_5 ( V_1 -> V_13 , L_10 ,
V_1 -> V_14 ) ;
break;
case V_94 :
if ( ( V_57 & 0xff ) != 1 )
goto error;
switch ( V_56 ) {
case V_70 :
if ( ! V_38 -> V_71 . V_72 && F_17 ( V_1 ) )
F_29 ( V_1 ) ;
break;
case V_95 :
F_10 ( V_1 , true ) ;
break;
case V_69 :
F_1 ( V_1 , true ) ;
break;
case V_96 :
if ( F_21 ( F_2 ( V_1 ) ) )
goto error;
V_57 >>= 8 ;
switch ( V_57 ) {
case 1 :
F_30 ( L_11 ) ;
V_59 = V_97 ;
break;
case 2 :
F_30 ( L_12 ) ;
V_59 = V_98 ;
break;
case 3 :
F_30 ( L_13 ) ;
V_59 = V_99 ;
break;
case 4 :
F_30 ( L_14 ) ;
V_59 = V_100 ;
F_31 ( V_1 ) ;
break;
case 5 :
F_30 ( L_15 ) ;
V_59 = V_101
| V_102 ;
F_4 ( V_1 -> V_8 , V_103 ,
V_104 ) ;
break;
case 6 :
F_30 ( L_16 ) ;
V_59 = V_105 ;
break;
default:
goto error;
}
F_4 ( V_1 -> V_8 , V_106 , V_59 ) ;
break;
default:
goto error;
}
F_5 ( V_1 -> V_13 , L_17 , V_56 ) ;
V_1 -> V_14 |= 1 << V_56 ;
break;
default:
error:
V_50 = - V_107 ;
}
F_23 ( & V_1 -> V_61 , V_60 ) ;
return V_50 ;
}
