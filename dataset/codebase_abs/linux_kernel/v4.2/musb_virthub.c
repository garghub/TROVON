void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
unsigned long V_4 ;
T_1 V_5 ;
V_3 = F_2 ( V_2 , struct V_3 , V_6 . V_2 ) ;
F_3 ( & V_3 -> V_7 , V_4 ) ;
V_5 = F_4 ( V_3 -> V_8 , V_9 ) ;
V_5 &= ~ V_10 ;
F_5 ( V_3 -> V_11 , L_1 ,
V_5 ) ;
F_6 ( V_3 -> V_8 , V_9 , V_5 ) ;
V_3 -> V_12 = 1 ;
V_3 -> V_13 &= ~ ( V_14 | V_15 ) ;
V_3 -> V_13 |= V_16 << 16 ;
F_7 ( V_3 -> V_17 ) ;
V_3 -> V_18 -> V_19 -> V_20 = V_21 ;
F_8 ( & V_3 -> V_7 , V_4 ) ;
}
void F_9 ( struct V_3 * V_3 , bool V_22 )
{
struct V_23 * V_19 = V_3 -> V_18 -> V_19 ;
T_1 V_5 ;
void T_2 * V_24 = V_3 -> V_8 ;
if ( ! F_10 ( V_3 ) )
return;
V_5 = F_4 ( V_24 , V_9 ) ;
if ( V_22 ) {
int V_25 = 10000 ;
V_5 &= ~ V_10 ;
V_5 |= V_26 ;
F_6 ( V_24 , V_9 , V_5 ) ;
V_5 = F_4 ( V_24 , V_9 ) ;
while ( V_5 & V_26 ) {
V_5 = F_4 ( V_24 , V_9 ) ;
if ( V_25 -- < 1 )
break;
}
F_5 ( V_3 -> V_11 , L_2 , V_5 ) ;
V_3 -> V_13 |= V_14 ;
switch ( V_3 -> V_18 -> V_19 -> V_20 ) {
case V_21 :
V_3 -> V_18 -> V_19 -> V_20 = V_27 ;
V_3 -> V_12 = V_19 -> V_28 -> V_29 ;
if ( V_3 -> V_12 )
F_11 ( & V_3 -> V_30 , V_31
+ F_12 (
V_32 ) ) ;
F_13 ( V_3 , 0 ) ;
break;
case V_33 :
V_3 -> V_18 -> V_19 -> V_20 = V_34 ;
V_3 -> V_12 = V_19 -> V_28 -> V_29 ;
F_13 ( V_3 , 0 ) ;
break;
default:
F_5 ( V_3 -> V_11 , L_3 ,
F_14 ( V_3 -> V_18 -> V_19 -> V_20 ) ) ;
}
} else if ( V_5 & V_26 ) {
V_5 &= ~ V_26 ;
V_5 |= V_10 ;
F_6 ( V_24 , V_9 , V_5 ) ;
F_5 ( V_3 -> V_11 , L_4 , V_5 ) ;
V_3 -> V_13 |= V_15 ;
F_15 ( & V_3 -> V_6 ,
F_12 ( V_35 ) ) ;
}
}
void F_16 ( struct V_3 * V_3 , bool V_36 )
{
T_1 V_5 ;
void T_2 * V_24 = V_3 -> V_8 ;
if ( V_3 -> V_18 -> V_19 -> V_20 == V_37 ) {
F_5 ( V_3 -> V_11 , L_5 ) ;
V_3 -> V_13 &= ~ V_38 ;
return;
}
if ( ! F_10 ( V_3 ) )
return;
V_5 = F_4 ( V_24 , V_9 ) ;
if ( V_36 ) {
if ( V_5 & V_10 ) {
long V_39 = ( unsigned long ) V_3 -> V_40 - V_31 ;
if ( V_3 -> V_40 > 0 && V_39 > 0 ) {
F_15 (
& V_3 -> V_41 , V_39 ) ;
return;
}
F_6 ( V_24 , V_9 ,
V_5 & ~ V_10 ) ;
F_15 ( & V_3 -> V_41 ,
F_12 ( 1 ) ) ;
return;
}
V_5 &= 0xf0 ;
F_6 ( V_24 , V_9 ,
V_5 | V_42 ) ;
V_3 -> V_13 |= V_38 ;
V_3 -> V_13 &= ~ V_43 ;
F_15 ( & V_3 -> V_41 ,
F_12 ( 50 ) ) ;
} else {
F_5 ( V_3 -> V_11 , L_6 ) ;
F_17 ( V_3 ) ;
F_6 ( V_24 , V_9 ,
V_5 & ~ V_42 ) ;
F_18 ( V_3 ) ;
V_5 = F_4 ( V_24 , V_9 ) ;
if ( V_5 & V_44 ) {
F_5 ( V_3 -> V_11 , L_7 ) ;
V_3 -> V_13 |= V_45 ;
}
V_3 -> V_13 &= ~ V_38 ;
V_3 -> V_13 |= V_43
| ( V_46 << 16 )
| ( V_47 << 16 ) ;
F_7 ( V_3 -> V_17 ) ;
V_3 -> V_48 = V_49 ;
}
}
void F_19 ( struct V_3 * V_3 )
{
struct V_23 * V_19 = V_3 -> V_18 -> V_19 ;
V_3 -> V_13 = V_50
| ( V_51 << 16 ) ;
F_7 ( V_3 -> V_17 ) ;
V_3 -> V_12 = 0 ;
switch ( V_3 -> V_18 -> V_19 -> V_20 ) {
case V_27 :
if ( V_19 -> V_28 -> V_29 ) {
V_3 -> V_18 -> V_19 -> V_20 = V_52 ;
V_3 -> V_53 . V_54 = 1 ;
break;
}
case V_21 :
V_3 -> V_18 -> V_19 -> V_20 = V_55 ;
V_3 -> V_12 = 0 ;
break;
case V_56 :
V_3 -> V_18 -> V_19 -> V_20 = V_37 ;
break;
default:
F_5 ( V_3 -> V_11 , L_8 ,
F_14 ( V_3 -> V_18 -> V_19 -> V_20 ) ) ;
}
}
int F_20 ( struct V_57 * V_17 , char * V_58 )
{
struct V_3 * V_3 = F_21 ( V_17 ) ;
int V_59 = 0 ;
if ( V_3 -> V_13 & 0xffff0000 ) {
* V_58 = 0x02 ;
V_59 = 1 ;
}
return V_59 ;
}
static int F_22 ( struct V_3 * V_3 )
{
#ifdef F_23
return 1 ;
#else
return V_3 -> V_60 == V_61 ;
#endif
}
int F_24 (
struct V_57 * V_17 ,
T_3 V_62 ,
T_3 V_63 ,
T_3 V_64 ,
char * V_58 ,
T_3 V_65 )
{
struct V_3 * V_3 = F_21 ( V_17 ) ;
T_4 V_66 ;
int V_59 = 0 ;
unsigned long V_4 ;
F_3 ( & V_3 -> V_7 , V_4 ) ;
if ( F_25 ( ! F_26 ( V_17 ) ) ) {
F_8 ( & V_3 -> V_7 , V_4 ) ;
return - V_67 ;
}
switch ( V_62 ) {
case V_68 :
case V_69 :
switch ( V_63 ) {
case V_70 :
case V_71 :
break;
default:
goto error;
}
break;
case V_72 :
if ( ( V_64 & 0xff ) != 1 )
goto error;
switch ( V_63 ) {
case V_73 :
break;
case V_74 :
F_9 ( V_3 , false ) ;
break;
case V_75 :
if ( ! V_17 -> V_76 . V_77 )
F_27 ( V_3 , 0 ) ;
break;
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
break;
default:
goto error;
}
F_5 ( V_3 -> V_11 , L_9 , V_63 ) ;
V_3 -> V_13 &= ~ ( 1 << V_63 ) ;
break;
case V_83 :
{
struct V_84 * V_85 = ( void * ) V_58 ;
V_85 -> V_86 = 9 ;
V_85 -> V_87 = V_88 ;
V_85 -> V_89 = 1 ;
V_85 -> V_90 = F_28 (
V_91
| V_92
) ;
V_85 -> V_93 = 5 ;
V_85 -> V_94 = 0 ;
V_85 -> V_95 . V_96 . V_97 [ 0 ] = 0x02 ;
V_85 -> V_95 . V_96 . V_97 [ 1 ] = 0xff ;
}
break;
case V_98 :
V_66 = 0 ;
* ( V_99 * ) V_58 = F_29 ( V_66 ) ;
break;
case V_100 :
if ( V_64 != 1 )
goto error;
F_30 ( F_29 ( V_3 -> V_13
& ~ V_15 ) ,
( V_99 * ) V_58 ) ;
F_5 ( V_3 -> V_11 , L_10 ,
V_3 -> V_13 ) ;
break;
case V_101 :
if ( ( V_64 & 0xff ) != 1 )
goto error;
switch ( V_63 ) {
case V_75 :
if ( ! V_17 -> V_76 . V_77 && F_22 ( V_3 ) )
F_31 ( V_3 ) ;
break;
case V_102 :
F_16 ( V_3 , true ) ;
break;
case V_74 :
F_9 ( V_3 , true ) ;
break;
case V_103 :
if ( F_25 ( F_10 ( V_3 ) ) )
goto error;
V_64 >>= 8 ;
switch ( V_64 ) {
case 1 :
F_32 ( L_11 ) ;
V_66 = V_104 ;
break;
case 2 :
F_32 ( L_12 ) ;
V_66 = V_105 ;
break;
case 3 :
F_32 ( L_13 ) ;
V_66 = V_106 ;
break;
case 4 :
F_32 ( L_14 ) ;
V_66 = V_107 ;
F_33 ( V_3 ) ;
break;
case 5 :
F_32 ( L_15 ) ;
V_66 = V_108
| V_109 ;
F_6 ( V_3 -> V_8 , V_110 ,
V_111 ) ;
break;
case 6 :
F_32 ( L_16 ) ;
V_66 = V_112 ;
break;
default:
goto error;
}
F_6 ( V_3 -> V_8 , V_113 , V_66 ) ;
break;
default:
goto error;
}
F_5 ( V_3 -> V_11 , L_17 , V_63 ) ;
V_3 -> V_13 |= 1 << V_63 ;
break;
default:
error:
V_59 = - V_114 ;
}
F_8 ( & V_3 -> V_7 , V_4 ) ;
return V_59 ;
}
