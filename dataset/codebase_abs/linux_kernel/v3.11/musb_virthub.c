static void F_1 ( struct V_1 * V_1 )
{
void T_1 * V_2 = V_1 -> V_3 ;
T_2 V_4 = F_2 ( V_2 , V_5 ) ;
F_3 ( V_1 -> V_6 , L_1 , V_4 ) ;
V_1 -> V_7 = V_1 -> V_8 ;
F_4 ( V_2 , V_9 , V_1 -> V_7 ) ;
V_1 -> V_10 = V_1 -> V_8 & 0xfffe ;
F_4 ( V_2 , V_11 , V_1 -> V_10 ) ;
F_5 ( V_2 , V_12 , 0xf7 ) ;
F_5 ( V_2 , V_13 , 0 ) ;
F_5 ( V_2 , V_14 , V_15
| V_16
) ;
V_1 -> V_17 = 0 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_4 &= ~ V_18 ;
if ( V_1 -> V_19 != V_20 &&
( V_4 & V_21 ) == V_21 ) {
V_1 -> V_17 = 1 ;
} else {
V_4 |= V_18 ;
}
F_6 ( V_1 ) ;
F_5 ( V_2 , V_5 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_1 , bool V_22 )
{
struct V_23 * V_24 = V_1 -> V_25 -> V_24 ;
T_2 V_26 ;
void T_1 * V_27 = V_1 -> V_3 ;
if ( ! F_8 ( V_1 ) )
return;
V_26 = F_2 ( V_27 , V_14 ) ;
if ( V_22 ) {
int V_28 = 10000 ;
V_26 &= ~ V_29 ;
V_26 |= V_30 ;
F_5 ( V_27 , V_14 , V_26 ) ;
V_26 = F_2 ( V_27 , V_14 ) ;
while ( V_26 & V_30 ) {
V_26 = F_2 ( V_27 , V_14 ) ;
if ( V_28 -- < 1 )
break;
}
F_3 ( V_1 -> V_6 , L_2 , V_26 ) ;
V_1 -> V_31 |= V_32 ;
switch ( V_1 -> V_25 -> V_33 ) {
case V_34 :
V_1 -> V_25 -> V_33 = V_35 ;
V_1 -> V_17 = V_24 -> V_36 -> V_37 ;
if ( V_1 -> V_17 )
F_9 ( & V_1 -> V_38 , V_39
+ F_10 (
V_40 ) ) ;
F_11 ( V_1 , 0 ) ;
break;
case V_41 :
V_1 -> V_25 -> V_33 = V_42 ;
V_1 -> V_17 = V_24 -> V_36 -> V_37 ;
F_11 ( V_1 , 0 ) ;
break;
default:
F_3 ( V_1 -> V_6 , L_3 ,
F_12 ( V_1 -> V_25 -> V_33 ) ) ;
}
} else if ( V_26 & V_30 ) {
V_26 &= ~ V_30 ;
V_26 |= V_29 ;
F_5 ( V_27 , V_14 , V_26 ) ;
F_3 ( V_1 -> V_6 , L_4 , V_26 ) ;
V_1 -> V_31 |= V_43 ;
V_1 -> V_44 = V_39 + F_10 ( 20 ) ;
}
}
static void F_13 ( struct V_1 * V_1 , bool V_45 )
{
T_2 V_26 ;
void T_1 * V_27 = V_1 -> V_3 ;
if ( V_1 -> V_25 -> V_33 == V_46 ) {
F_3 ( V_1 -> V_6 , L_5 ) ;
V_1 -> V_31 &= ~ V_47 ;
return;
}
if ( ! F_8 ( V_1 ) )
return;
V_26 = F_2 ( V_27 , V_14 ) ;
if ( V_45 ) {
if ( V_26 & V_29 ) {
while ( F_14 ( V_39 , V_1 -> V_44 ) )
F_15 ( 1 ) ;
F_5 ( V_27 , V_14 ,
V_26 & ~ V_29 ) ;
F_15 ( 1 ) ;
}
V_26 &= 0xf0 ;
F_5 ( V_27 , V_14 ,
V_26 | V_48 ) ;
V_1 -> V_31 |= V_47 ;
V_1 -> V_31 &= ~ V_49 ;
V_1 -> V_44 = V_39 + F_10 ( 50 ) ;
} else {
F_3 ( V_1 -> V_6 , L_6 ) ;
F_5 ( V_27 , V_14 ,
V_26 & ~ V_48 ) ;
V_26 = F_2 ( V_27 , V_14 ) ;
if ( V_26 & V_50 ) {
F_3 ( V_1 -> V_6 , L_7 ) ;
V_1 -> V_31 |= V_51 ;
}
V_1 -> V_31 &= ~ V_47 ;
V_1 -> V_31 |= V_49
| ( V_52 << 16 )
| ( V_53 << 16 ) ;
F_16 ( V_1 -> V_54 ) ;
V_1 -> V_55 = V_56 ;
}
}
void F_17 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = V_1 -> V_25 -> V_24 ;
V_1 -> V_31 = V_57
| ( V_58 << 16 ) ;
F_16 ( V_1 -> V_54 ) ;
V_1 -> V_17 = 0 ;
switch ( V_1 -> V_25 -> V_33 ) {
case V_35 :
if ( V_24 -> V_36 -> V_37 ) {
V_1 -> V_25 -> V_33 = V_59 ;
V_1 -> V_60 . V_61 = 1 ;
break;
}
case V_34 :
V_1 -> V_25 -> V_33 = V_62 ;
V_1 -> V_17 = 0 ;
break;
case V_63 :
V_1 -> V_25 -> V_33 = V_46 ;
break;
default:
F_3 ( V_1 -> V_6 , L_8 ,
F_12 ( V_1 -> V_25 -> V_33 ) ) ;
}
}
int F_18 ( struct V_64 * V_54 , char * V_65 )
{
struct V_1 * V_1 = F_19 ( V_54 ) ;
int V_66 = 0 ;
if ( V_1 -> V_31 & 0xffff0000 ) {
* V_65 = 0x02 ;
V_66 = 1 ;
}
return V_66 ;
}
int F_20 (
struct V_64 * V_54 ,
T_3 V_67 ,
T_3 V_68 ,
T_3 V_69 ,
char * V_65 ,
T_3 V_70 )
{
struct V_1 * V_1 = F_19 ( V_54 ) ;
T_4 V_71 ;
int V_66 = 0 ;
unsigned long V_72 ;
F_21 ( & V_1 -> V_73 , V_72 ) ;
if ( F_22 ( ! F_23 ( V_54 ) ) ) {
F_24 ( & V_1 -> V_73 , V_72 ) ;
return - V_74 ;
}
switch ( V_67 ) {
case V_75 :
case V_76 :
switch ( V_68 ) {
case V_77 :
case V_78 :
break;
default:
goto error;
}
break;
case V_79 :
if ( ( V_69 & 0xff ) != 1 )
goto error;
switch ( V_68 ) {
case V_80 :
break;
case V_81 :
F_7 ( V_1 , false ) ;
break;
case V_82 :
if ( ! V_54 -> V_83 . V_84 )
F_25 ( V_1 , 0 ) ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
break;
default:
goto error;
}
F_3 ( V_1 -> V_6 , L_9 , V_68 ) ;
V_1 -> V_31 &= ~ ( 1 << V_68 ) ;
break;
case V_90 :
{
struct V_91 * V_92 = ( void * ) V_65 ;
V_92 -> V_93 = 9 ;
V_92 -> V_94 = 0x29 ;
V_92 -> V_95 = 1 ;
V_92 -> V_96 = F_26 (
0x0001
| 0x0010
) ;
V_92 -> V_97 = 5 ;
V_92 -> V_98 = 0 ;
V_92 -> V_99 . V_100 . V_101 [ 0 ] = 0x02 ;
V_92 -> V_99 . V_100 . V_101 [ 1 ] = 0xff ;
}
break;
case V_102 :
V_71 = 0 ;
* ( V_103 * ) V_65 = F_27 ( V_71 ) ;
break;
case V_104 :
if ( V_69 != 1 )
goto error;
if ( ( V_1 -> V_31 & V_47 )
&& F_28 ( V_39 , V_1 -> V_44 ) )
F_13 ( V_1 , false ) ;
if ( ( V_1 -> V_31 & V_43 )
&& F_28 ( V_39 , V_1 -> V_44 ) ) {
T_2 V_26 ;
V_26 = F_2 ( V_1 -> V_3 , V_14 ) ;
V_26 &= ~ V_29 ;
F_3 ( V_1 -> V_6 , L_10 ,
V_26 ) ;
F_5 ( V_1 -> V_3 , V_14 , V_26 ) ;
V_1 -> V_17 = 1 ;
V_1 -> V_31 &= ~ ( V_32
| V_43 ) ;
V_1 -> V_31 |= V_105 << 16 ;
F_16 ( V_1 -> V_54 ) ;
V_1 -> V_25 -> V_33 = V_34 ;
}
F_29 ( F_27 ( V_1 -> V_31
& ~ V_43 ) ,
( V_103 * ) V_65 ) ;
F_3 ( V_1 -> V_6 , L_11 ,
V_1 -> V_31 ) ;
break;
case V_106 :
if ( ( V_69 & 0xff ) != 1 )
goto error;
switch ( V_68 ) {
case V_82 :
if ( ! V_54 -> V_83 . V_84 )
F_1 ( V_1 ) ;
break;
case V_107 :
F_13 ( V_1 , true ) ;
break;
case V_81 :
F_7 ( V_1 , true ) ;
break;
case V_108 :
if ( F_22 ( F_8 ( V_1 ) ) )
goto error;
V_69 >>= 8 ;
switch ( V_69 ) {
case 1 :
F_30 ( L_12 ) ;
V_71 = V_109 ;
break;
case 2 :
F_30 ( L_13 ) ;
V_71 = V_110 ;
break;
case 3 :
F_30 ( L_14 ) ;
V_71 = V_111 ;
break;
case 4 :
F_30 ( L_15 ) ;
V_71 = V_112 ;
F_31 ( V_1 ) ;
break;
case 5 :
F_30 ( L_16 ) ;
V_71 = V_113
| V_114 ;
F_5 ( V_1 -> V_3 , V_5 ,
V_18 ) ;
break;
case 6 :
F_30 ( L_17 ) ;
V_71 = V_115 ;
break;
default:
goto error;
}
F_5 ( V_1 -> V_3 , V_13 , V_71 ) ;
break;
default:
goto error;
}
F_3 ( V_1 -> V_6 , L_18 , V_68 ) ;
V_1 -> V_31 |= 1 << V_68 ;
break;
default:
error:
V_66 = - V_116 ;
}
F_24 ( & V_1 -> V_73 , V_72 ) ;
return V_66 ;
}
