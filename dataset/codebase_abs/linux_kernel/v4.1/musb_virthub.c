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
F_6 ( V_24 , V_9 ,
V_5 & ~ V_42 ) ;
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
void F_17 ( struct V_3 * V_3 )
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
int F_18 ( struct V_57 * V_17 , char * V_58 )
{
struct V_3 * V_3 = F_19 ( V_17 ) ;
int V_59 = 0 ;
if ( V_3 -> V_13 & 0xffff0000 ) {
* V_58 = 0x02 ;
V_59 = 1 ;
}
return V_59 ;
}
static int F_20 ( struct V_3 * V_3 )
{
#ifdef F_21
return 1 ;
#else
if ( V_3 -> V_60 == V_61 )
return 1 ;
return V_3 -> V_53 . V_62 . V_63 != NULL ;
#endif
}
int F_22 (
struct V_57 * V_17 ,
T_3 V_64 ,
T_3 V_65 ,
T_3 V_66 ,
char * V_58 ,
T_3 V_67 )
{
struct V_3 * V_3 = F_19 ( V_17 ) ;
T_4 V_68 ;
int V_59 = 0 ;
unsigned long V_4 ;
F_3 ( & V_3 -> V_7 , V_4 ) ;
if ( F_23 ( ! F_24 ( V_17 ) ) ) {
F_8 ( & V_3 -> V_7 , V_4 ) ;
return - V_69 ;
}
switch ( V_64 ) {
case V_70 :
case V_71 :
switch ( V_65 ) {
case V_72 :
case V_73 :
break;
default:
goto error;
}
break;
case V_74 :
if ( ( V_66 & 0xff ) != 1 )
goto error;
switch ( V_65 ) {
case V_75 :
break;
case V_76 :
F_9 ( V_3 , false ) ;
break;
case V_77 :
if ( ! V_17 -> V_78 . V_79 )
F_25 ( V_3 , 0 ) ;
break;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
break;
default:
goto error;
}
F_5 ( V_3 -> V_11 , L_9 , V_65 ) ;
V_3 -> V_13 &= ~ ( 1 << V_65 ) ;
break;
case V_85 :
{
struct V_86 * V_87 = ( void * ) V_58 ;
V_87 -> V_88 = 9 ;
V_87 -> V_89 = V_90 ;
V_87 -> V_91 = 1 ;
V_87 -> V_92 = F_26 (
V_93
| V_94
) ;
V_87 -> V_95 = 5 ;
V_87 -> V_96 = 0 ;
V_87 -> V_97 . V_98 . V_99 [ 0 ] = 0x02 ;
V_87 -> V_97 . V_98 . V_99 [ 1 ] = 0xff ;
}
break;
case V_100 :
V_68 = 0 ;
* ( V_101 * ) V_58 = F_27 ( V_68 ) ;
break;
case V_102 :
if ( V_66 != 1 )
goto error;
F_28 ( F_27 ( V_3 -> V_13
& ~ V_15 ) ,
( V_101 * ) V_58 ) ;
F_5 ( V_3 -> V_11 , L_10 ,
V_3 -> V_13 ) ;
break;
case V_103 :
if ( ( V_66 & 0xff ) != 1 )
goto error;
switch ( V_65 ) {
case V_77 :
if ( ! V_17 -> V_78 . V_79 && F_20 ( V_3 ) )
F_29 ( V_3 ) ;
break;
case V_104 :
F_16 ( V_3 , true ) ;
break;
case V_76 :
F_9 ( V_3 , true ) ;
break;
case V_105 :
if ( F_23 ( F_10 ( V_3 ) ) )
goto error;
V_66 >>= 8 ;
switch ( V_66 ) {
case 1 :
F_30 ( L_11 ) ;
V_68 = V_106 ;
break;
case 2 :
F_30 ( L_12 ) ;
V_68 = V_107 ;
break;
case 3 :
F_30 ( L_13 ) ;
V_68 = V_108 ;
break;
case 4 :
F_30 ( L_14 ) ;
V_68 = V_109 ;
F_31 ( V_3 ) ;
break;
case 5 :
F_30 ( L_15 ) ;
V_68 = V_110
| V_111 ;
F_6 ( V_3 -> V_8 , V_112 ,
V_113 ) ;
break;
case 6 :
F_30 ( L_16 ) ;
V_68 = V_114 ;
break;
default:
goto error;
}
F_6 ( V_3 -> V_8 , V_115 , V_68 ) ;
break;
default:
goto error;
}
F_5 ( V_3 -> V_11 , L_17 , V_65 ) ;
V_3 -> V_13 |= 1 << V_65 ;
break;
default:
error:
V_59 = - V_116 ;
}
F_8 ( & V_3 -> V_7 , V_4 ) ;
return V_59 ;
}
