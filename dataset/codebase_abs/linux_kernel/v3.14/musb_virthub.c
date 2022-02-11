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
V_3 -> V_18 -> V_19 = V_20 ;
F_8 ( & V_3 -> V_7 , V_4 ) ;
}
void F_9 ( struct V_3 * V_3 , bool V_21 )
{
struct V_22 * V_23 = V_3 -> V_18 -> V_23 ;
T_1 V_5 ;
void T_2 * V_24 = V_3 -> V_8 ;
if ( ! F_10 ( V_3 ) )
return;
V_5 = F_4 ( V_24 , V_9 ) ;
if ( V_21 ) {
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
switch ( V_3 -> V_18 -> V_19 ) {
case V_20 :
V_3 -> V_18 -> V_19 = V_27 ;
V_3 -> V_12 = V_23 -> V_28 -> V_29 ;
if ( V_3 -> V_12 )
F_11 ( & V_3 -> V_30 , V_31
+ F_12 (
V_32 ) ) ;
F_13 ( V_3 , 0 ) ;
break;
case V_33 :
V_3 -> V_18 -> V_19 = V_34 ;
V_3 -> V_12 = V_23 -> V_28 -> V_29 ;
F_13 ( V_3 , 0 ) ;
break;
default:
F_5 ( V_3 -> V_11 , L_3 ,
F_14 ( V_3 -> V_18 -> V_19 ) ) ;
}
} else if ( V_5 & V_26 ) {
V_5 &= ~ V_26 ;
V_5 |= V_10 ;
F_6 ( V_24 , V_9 , V_5 ) ;
F_5 ( V_3 -> V_11 , L_4 , V_5 ) ;
V_3 -> V_13 |= V_15 ;
F_15 ( & V_3 -> V_6 ,
F_12 ( 20 ) ) ;
}
}
void F_16 ( struct V_3 * V_3 , bool V_35 )
{
T_1 V_5 ;
void T_2 * V_24 = V_3 -> V_8 ;
if ( V_3 -> V_18 -> V_19 == V_36 ) {
F_5 ( V_3 -> V_11 , L_5 ) ;
V_3 -> V_13 &= ~ V_37 ;
return;
}
if ( ! F_10 ( V_3 ) )
return;
V_5 = F_4 ( V_24 , V_9 ) ;
if ( V_35 ) {
if ( V_5 & V_10 ) {
long V_38 = ( unsigned long ) V_3 -> V_39 - V_31 ;
if ( V_3 -> V_39 > 0 && V_38 > 0 ) {
F_15 (
& V_3 -> V_40 , V_38 ) ;
return;
}
F_6 ( V_24 , V_9 ,
V_5 & ~ V_10 ) ;
F_15 ( & V_3 -> V_40 ,
F_12 ( 1 ) ) ;
return;
}
V_5 &= 0xf0 ;
F_6 ( V_24 , V_9 ,
V_5 | V_41 ) ;
V_3 -> V_13 |= V_37 ;
V_3 -> V_13 &= ~ V_42 ;
F_15 ( & V_3 -> V_40 ,
F_12 ( 50 ) ) ;
} else {
F_5 ( V_3 -> V_11 , L_6 ) ;
F_6 ( V_24 , V_9 ,
V_5 & ~ V_41 ) ;
V_5 = F_4 ( V_24 , V_9 ) ;
if ( V_5 & V_43 ) {
F_5 ( V_3 -> V_11 , L_7 ) ;
V_3 -> V_13 |= V_44 ;
}
V_3 -> V_13 &= ~ V_37 ;
V_3 -> V_13 |= V_42
| ( V_45 << 16 )
| ( V_46 << 16 ) ;
F_7 ( V_3 -> V_17 ) ;
V_3 -> V_47 = V_48 ;
}
}
void F_17 ( struct V_3 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_18 -> V_23 ;
V_3 -> V_13 = V_49
| ( V_50 << 16 ) ;
F_7 ( V_3 -> V_17 ) ;
V_3 -> V_12 = 0 ;
switch ( V_3 -> V_18 -> V_19 ) {
case V_27 :
if ( V_23 -> V_28 -> V_29 ) {
V_3 -> V_18 -> V_19 = V_51 ;
V_3 -> V_52 . V_53 = 1 ;
break;
}
case V_20 :
V_3 -> V_18 -> V_19 = V_54 ;
V_3 -> V_12 = 0 ;
break;
case V_55 :
V_3 -> V_18 -> V_19 = V_36 ;
break;
default:
F_5 ( V_3 -> V_11 , L_8 ,
F_14 ( V_3 -> V_18 -> V_19 ) ) ;
}
}
int F_18 ( struct V_56 * V_17 , char * V_57 )
{
struct V_3 * V_3 = F_19 ( V_17 ) ;
int V_58 = 0 ;
if ( V_3 -> V_13 & 0xffff0000 ) {
* V_57 = 0x02 ;
V_58 = 1 ;
}
return V_58 ;
}
static int F_20 ( struct V_3 * V_3 )
{
#ifdef F_21
return 1 ;
#else
if ( V_3 -> V_59 == V_60 )
return 1 ;
return V_3 -> V_52 . V_61 . V_62 != NULL ;
#endif
}
int F_22 (
struct V_56 * V_17 ,
T_3 V_63 ,
T_3 V_64 ,
T_3 V_65 ,
char * V_57 ,
T_3 V_66 )
{
struct V_3 * V_3 = F_19 ( V_17 ) ;
T_4 V_67 ;
int V_58 = 0 ;
unsigned long V_4 ;
F_3 ( & V_3 -> V_7 , V_4 ) ;
if ( F_23 ( ! F_24 ( V_17 ) ) ) {
F_8 ( & V_3 -> V_7 , V_4 ) ;
return - V_68 ;
}
switch ( V_63 ) {
case V_69 :
case V_70 :
switch ( V_64 ) {
case V_71 :
case V_72 :
break;
default:
goto error;
}
break;
case V_73 :
if ( ( V_65 & 0xff ) != 1 )
goto error;
switch ( V_64 ) {
case V_74 :
break;
case V_75 :
F_9 ( V_3 , false ) ;
break;
case V_76 :
if ( ! V_17 -> V_77 . V_78 )
F_25 ( V_3 , 0 ) ;
break;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
break;
default:
goto error;
}
F_5 ( V_3 -> V_11 , L_9 , V_64 ) ;
V_3 -> V_13 &= ~ ( 1 << V_64 ) ;
break;
case V_84 :
{
struct V_85 * V_86 = ( void * ) V_57 ;
V_86 -> V_87 = 9 ;
V_86 -> V_88 = 0x29 ;
V_86 -> V_89 = 1 ;
V_86 -> V_90 = F_26 (
0x0001
| 0x0010
) ;
V_86 -> V_91 = 5 ;
V_86 -> V_92 = 0 ;
V_86 -> V_93 . V_94 . V_95 [ 0 ] = 0x02 ;
V_86 -> V_93 . V_94 . V_95 [ 1 ] = 0xff ;
}
break;
case V_96 :
V_67 = 0 ;
* ( V_97 * ) V_57 = F_27 ( V_67 ) ;
break;
case V_98 :
if ( V_65 != 1 )
goto error;
F_28 ( F_27 ( V_3 -> V_13
& ~ V_15 ) ,
( V_97 * ) V_57 ) ;
F_5 ( V_3 -> V_11 , L_10 ,
V_3 -> V_13 ) ;
break;
case V_99 :
if ( ( V_65 & 0xff ) != 1 )
goto error;
switch ( V_64 ) {
case V_76 :
if ( ! V_17 -> V_77 . V_78 && F_20 ( V_3 ) )
F_29 ( V_3 ) ;
break;
case V_100 :
F_16 ( V_3 , true ) ;
break;
case V_75 :
F_9 ( V_3 , true ) ;
break;
case V_101 :
if ( F_23 ( F_10 ( V_3 ) ) )
goto error;
V_65 >>= 8 ;
switch ( V_65 ) {
case 1 :
F_30 ( L_11 ) ;
V_67 = V_102 ;
break;
case 2 :
F_30 ( L_12 ) ;
V_67 = V_103 ;
break;
case 3 :
F_30 ( L_13 ) ;
V_67 = V_104 ;
break;
case 4 :
F_30 ( L_14 ) ;
V_67 = V_105 ;
F_31 ( V_3 ) ;
break;
case 5 :
F_30 ( L_15 ) ;
V_67 = V_106
| V_107 ;
F_6 ( V_3 -> V_8 , V_108 ,
V_109 ) ;
break;
case 6 :
F_30 ( L_16 ) ;
V_67 = V_110 ;
break;
default:
goto error;
}
F_6 ( V_3 -> V_8 , V_111 , V_67 ) ;
break;
default:
goto error;
}
F_5 ( V_3 -> V_11 , L_17 , V_64 ) ;
V_3 -> V_13 |= 1 << V_64 ;
break;
default:
error:
V_58 = - V_112 ;
}
F_8 ( & V_3 -> V_7 , V_4 ) ;
return V_58 ;
}
