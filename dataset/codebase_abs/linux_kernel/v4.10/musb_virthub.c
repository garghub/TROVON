void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
unsigned long V_4 ;
T_1 V_5 ;
V_3 = F_2 ( V_2 , struct V_3 , V_6 . V_2 ) ;
F_3 ( & V_3 -> V_7 , V_4 ) ;
V_5 = F_4 ( V_3 -> V_8 , V_9 ) ;
V_5 &= ~ V_10 ;
F_5 ( V_3 , L_1 , V_5 ) ;
F_6 ( V_3 -> V_8 , V_9 , V_5 ) ;
V_3 -> V_11 = 1 ;
V_3 -> V_12 &= ~ ( V_13 | V_14 ) ;
V_3 -> V_12 |= V_15 << 16 ;
F_7 ( V_3 -> V_16 ) ;
V_3 -> V_17 -> V_18 -> V_19 = V_20 ;
F_8 ( & V_3 -> V_7 , V_4 ) ;
}
void F_9 ( struct V_3 * V_3 , bool V_21 )
{
struct V_22 * V_18 = V_3 -> V_17 -> V_18 ;
T_1 V_5 ;
void T_2 * V_23 = V_3 -> V_8 ;
if ( ! F_10 ( V_3 ) )
return;
V_5 = F_4 ( V_23 , V_9 ) ;
if ( V_21 ) {
int V_24 = 10000 ;
V_5 &= ~ V_10 ;
V_5 |= V_25 ;
F_6 ( V_23 , V_9 , V_5 ) ;
V_5 = F_4 ( V_23 , V_9 ) ;
while ( V_5 & V_25 ) {
V_5 = F_4 ( V_23 , V_9 ) ;
if ( V_24 -- < 1 )
break;
}
F_5 ( V_3 , L_2 , V_5 ) ;
V_3 -> V_12 |= V_13 ;
switch ( V_3 -> V_17 -> V_18 -> V_19 ) {
case V_20 :
V_3 -> V_17 -> V_18 -> V_19 = V_26 ;
V_3 -> V_11 = V_18 -> V_27 -> V_28 ;
if ( V_3 -> V_11 )
F_11 ( & V_3 -> V_29 , V_30
+ F_12 (
V_31 ) ) ;
F_13 ( V_3 , 0 ) ;
break;
case V_32 :
V_3 -> V_17 -> V_18 -> V_19 = V_33 ;
V_3 -> V_11 = V_18 -> V_27 -> V_28 ;
F_13 ( V_3 , 0 ) ;
break;
default:
F_5 ( V_3 , L_3 ,
F_14 ( V_3 -> V_17 -> V_18 -> V_19 ) ) ;
}
} else if ( V_5 & V_25 ) {
V_5 &= ~ V_25 ;
V_5 |= V_10 ;
F_6 ( V_23 , V_9 , V_5 ) ;
F_5 ( V_3 , L_4 , V_5 ) ;
V_3 -> V_12 |= V_14 ;
F_15 ( & V_3 -> V_6 ,
F_12 ( V_34 ) ) ;
}
}
void F_16 ( struct V_3 * V_3 , bool V_35 )
{
T_1 V_5 ;
void T_2 * V_23 = V_3 -> V_8 ;
if ( V_3 -> V_17 -> V_18 -> V_19 == V_36 ) {
F_5 ( V_3 , L_5 ) ;
V_3 -> V_12 &= ~ V_37 ;
return;
}
if ( ! F_10 ( V_3 ) )
return;
V_5 = F_4 ( V_23 , V_9 ) ;
if ( V_35 ) {
if ( V_5 & V_10 ) {
long V_38 = ( unsigned long ) V_3 -> V_39 - V_30 ;
if ( V_3 -> V_39 > 0 && V_38 > 0 ) {
F_15 (
& V_3 -> V_40 , V_38 ) ;
return;
}
F_6 ( V_23 , V_9 ,
V_5 & ~ V_10 ) ;
F_15 ( & V_3 -> V_40 ,
F_12 ( 1 ) ) ;
return;
}
V_5 &= 0xf0 ;
F_6 ( V_23 , V_9 ,
V_5 | V_41 ) ;
V_3 -> V_12 |= V_37 ;
V_3 -> V_12 &= ~ V_42 ;
F_15 ( & V_3 -> V_40 ,
F_12 ( 50 ) ) ;
} else {
F_5 ( V_3 , L_6 ) ;
F_17 ( V_3 ) ;
F_6 ( V_23 , V_9 ,
V_5 & ~ V_41 ) ;
F_18 ( V_3 ) ;
V_5 = F_4 ( V_23 , V_9 ) ;
if ( V_5 & V_43 ) {
F_5 ( V_3 , L_7 ) ;
V_3 -> V_12 |= V_44 ;
}
V_3 -> V_12 &= ~ V_37 ;
V_3 -> V_12 |= V_42
| ( V_45 << 16 )
| ( V_46 << 16 ) ;
F_7 ( V_3 -> V_16 ) ;
V_3 -> V_47 = V_48 ;
}
}
void F_19 ( struct V_3 * V_3 )
{
struct V_22 * V_18 = V_3 -> V_17 -> V_18 ;
V_3 -> V_12 = V_49
| ( V_50 << 16 ) ;
F_7 ( V_3 -> V_16 ) ;
V_3 -> V_11 = 0 ;
switch ( V_3 -> V_17 -> V_18 -> V_19 ) {
case V_26 :
if ( V_18 -> V_27 -> V_28 ) {
V_3 -> V_17 -> V_18 -> V_19 = V_51 ;
V_3 -> V_52 . V_53 = 1 ;
break;
}
case V_20 :
V_3 -> V_17 -> V_18 -> V_19 = V_54 ;
V_3 -> V_11 = 0 ;
break;
case V_55 :
V_3 -> V_17 -> V_18 -> V_19 = V_36 ;
break;
default:
F_5 ( V_3 , L_8 ,
F_14 ( V_3 -> V_17 -> V_18 -> V_19 ) ) ;
}
}
int F_20 ( struct V_56 * V_16 , char * V_57 )
{
struct V_3 * V_3 = F_21 ( V_16 ) ;
int V_58 = 0 ;
if ( V_3 -> V_12 & 0xffff0000 ) {
* V_57 = 0x02 ;
V_58 = 1 ;
}
return V_58 ;
}
static int F_22 ( struct V_3 * V_3 )
{
#ifdef F_23
return 1 ;
#else
return V_3 -> V_59 == V_60 ;
#endif
}
int F_24 (
struct V_56 * V_16 ,
T_3 V_61 ,
T_3 V_62 ,
T_3 V_63 ,
char * V_57 ,
T_3 V_64 )
{
struct V_3 * V_3 = F_21 ( V_16 ) ;
T_4 V_65 ;
int V_58 = 0 ;
unsigned long V_4 ;
bool V_66 = false ;
F_3 ( & V_3 -> V_7 , V_4 ) ;
if ( F_25 ( ! F_26 ( V_16 ) ) ) {
F_8 ( & V_3 -> V_7 , V_4 ) ;
return - V_67 ;
}
switch ( V_61 ) {
case V_68 :
case V_69 :
switch ( V_62 ) {
case V_70 :
case V_71 :
break;
default:
goto error;
}
break;
case V_72 :
if ( ( V_63 & 0xff ) != 1 )
goto error;
switch ( V_62 ) {
case V_73 :
break;
case V_74 :
F_9 ( V_3 , false ) ;
break;
case V_75 :
if ( ! V_16 -> V_76 . V_77 )
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
F_5 ( V_3 , L_9 , V_62 ) ;
V_3 -> V_12 &= ~ ( 1 << V_62 ) ;
break;
case V_83 :
{
struct V_84 * V_85 = ( void * ) V_57 ;
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
V_65 = 0 ;
* ( V_99 * ) V_57 = F_29 ( V_65 ) ;
break;
case V_100 :
if ( V_63 != 1 )
goto error;
F_30 ( F_29 ( V_3 -> V_12
& ~ V_14 ) ,
( V_99 * ) V_57 ) ;
F_5 ( V_3 , L_10 , V_3 -> V_12 ) ;
break;
case V_101 :
if ( ( V_63 & 0xff ) != 1 )
goto error;
switch ( V_62 ) {
case V_75 :
if ( ! V_16 -> V_76 . V_77 && F_22 ( V_3 ) )
V_66 = true ;
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
V_63 >>= 8 ;
switch ( V_63 ) {
case 1 :
F_31 ( L_11 ) ;
V_65 = V_104 ;
break;
case 2 :
F_31 ( L_12 ) ;
V_65 = V_105 ;
break;
case 3 :
F_31 ( L_13 ) ;
V_65 = V_106 ;
break;
case 4 :
F_31 ( L_14 ) ;
V_65 = V_107 ;
F_32 ( V_3 ) ;
break;
case 5 :
F_31 ( L_15 ) ;
V_65 = V_108
| V_109 ;
F_6 ( V_3 -> V_8 , V_110 ,
V_111 ) ;
break;
case 6 :
F_31 ( L_16 ) ;
V_65 = V_112 ;
break;
default:
goto error;
}
F_6 ( V_3 -> V_8 , V_113 , V_65 ) ;
break;
default:
goto error;
}
F_5 ( V_3 , L_17 , V_62 ) ;
V_3 -> V_12 |= 1 << V_62 ;
break;
default:
error:
V_58 = - V_114 ;
}
F_8 ( & V_3 -> V_7 , V_4 ) ;
if ( V_66 )
F_33 ( V_3 ) ;
return V_58 ;
}
