static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_7 ) ;
if ( ! V_6 )
return - 1 ;
F_3 ( & V_6 -> V_8 ) ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
V_6 -> V_11 = 0 ;
V_6 -> V_12 =
( F_4 ( V_4 -> V_13 . V_14 ) <= 0x0206 ) ? 1 : 0 ;
F_5 ( & V_4 -> V_4 , L_1 ,
F_4 ( V_4 -> V_13 . V_14 ) ,
V_6 -> V_12 ) ;
F_6 ( & V_2 -> V_15 [ 0 ] -> V_16 ) ;
F_7 ( V_2 -> V_15 [ 0 ] , V_6 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_18 ; ++ V_17 )
F_9 ( F_10 ( V_2 -> V_15 [ V_17 ] ) ) ;
}
static int F_11 ( struct V_19 * V_20 ,
struct V_21 * V_15 )
{
int V_22 ;
V_22 = F_12 ( V_15 -> V_23 , V_7 ) ;
if ( V_22 ) {
F_13 ( & V_15 -> V_4 , L_2 ) ;
return V_22 ;
}
V_22 = F_14 ( V_20 , V_15 ) ;
if ( V_22 )
F_15 ( V_15 -> V_23 ) ;
return V_22 ;
}
static void F_16 ( struct V_21 * V_15 )
{
F_17 ( V_15 ) ;
F_15 ( V_15 -> V_23 ) ;
}
static void F_18 ( struct V_24 * V_24 )
{
struct V_21 * V_15 = V_24 -> V_25 ;
struct V_5 * V_6 ;
unsigned char * V_26 = V_24 -> V_27 ;
int V_22 ;
int V_28 = V_24 -> V_28 ;
unsigned long V_29 ;
switch ( V_28 ) {
case 0 :
break;
case - V_30 :
case - V_31 :
case - V_32 :
F_19 ( & V_15 -> V_4 , L_3 ,
V_33 , V_28 ) ;
return;
default:
F_19 ( & V_15 -> V_4 , L_4 ,
V_33 , V_28 ) ;
goto exit;
}
F_20 ( V_34 , & V_15 -> V_4 , V_33 ,
V_24 -> V_35 , V_26 ) ;
V_6 = F_10 ( V_15 ) ;
F_21 ( & V_6 -> V_8 , V_29 ) ;
V_6 -> V_11 = V_26 [ V_36 ] ;
if ( V_6 -> V_11 & V_37 )
V_6 -> V_9 |= V_38 ;
else
V_6 -> V_9 &= ~ V_38 ;
if ( V_6 -> V_11 & V_39 )
V_6 -> V_9 |= V_40 ;
else
V_6 -> V_9 &= ~ V_40 ;
if ( V_6 -> V_11 & V_41 )
V_6 -> V_9 |= V_42 ;
else
V_6 -> V_9 &= ~ V_42 ;
if ( V_6 -> V_11 & V_43 )
V_6 -> V_9 |= V_44 ;
else
V_6 -> V_9 &= ~ V_44 ;
V_6 -> V_10 = V_26 [ V_45 ] ;
F_22 ( & V_6 -> V_8 , V_29 ) ;
exit:
V_22 = F_12 ( V_24 , V_46 ) ;
if ( V_22 )
F_13 ( & V_15 -> V_4 , L_5
L_6 , V_33 , V_22 ) ;
}
static void F_23 ( struct V_24 * V_24 )
{
struct V_21 * V_15 = V_24 -> V_25 ;
struct V_5 * V_6 = F_10 ( V_15 ) ;
struct V_19 * V_20 ;
unsigned char * V_26 = V_24 -> V_27 ;
unsigned long V_29 ;
unsigned char V_28 ;
char V_47 ;
V_47 = V_48 ;
F_21 ( & V_6 -> V_8 , V_29 ) ;
V_28 = V_6 -> V_10 ;
V_6 -> V_10 &= ~ V_49 ;
F_22 ( & V_6 -> V_8 , V_29 ) ;
if ( ! V_24 -> V_35 )
return;
V_20 = F_24 ( & V_15 -> V_15 ) ;
if ( ! V_20 )
return;
if ( V_28 & V_49 ) {
if ( V_28 & V_50 )
V_47 = V_51 ;
else if ( V_28 & V_52 )
V_47 = V_53 ;
else if ( V_28 & V_54 )
V_47 = V_55 ;
F_19 ( & V_15 -> V_4 , L_7 , V_47 ) ;
if ( V_28 & V_56 )
F_25 ( V_20 , 0 , V_57 ) ;
}
F_26 ( V_20 , V_26 , V_47 ,
V_24 -> V_35 ) ;
F_27 ( V_20 ) ;
F_28 ( V_20 ) ;
}
static void F_29 ( struct V_19 * V_20 ,
struct V_21 * V_15 , struct V_58 * V_59 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_5 * V_6 = F_10 ( V_15 ) ;
unsigned int V_60 ;
unsigned int V_61 ;
unsigned int V_62 = 0 ;
unsigned int V_63 = 0 ;
T_1 V_64 = 0 ;
unsigned long V_29 ;
unsigned long V_9 ;
int V_12 ;
T_2 V_65 ;
struct V_58 * V_66 = V_20 -> V_66 ;
V_60 = V_66 -> V_67 ;
V_61 = V_66 -> V_68 ;
V_66 -> V_68 &= ~ V_69 ;
F_21 ( & V_6 -> V_8 , V_29 ) ;
V_9 = V_6 -> V_9 ;
V_12 = V_6 -> V_12 ;
F_22 ( & V_6 -> V_8 , V_29 ) ;
V_62 = V_59 -> V_67 ;
V_63 = V_59 -> V_68 ;
if ( ( V_61 & V_70 ) != ( V_63 & V_70 ) ) {
if ( ( V_63 & V_70 ) == V_71 ) {
V_9 |= ( V_72 | V_73 ) ;
if ( F_30 ( V_74 , 1 ) < 0 )
F_13 ( & V_15 -> V_4 , L_8 ) ;
if ( ! ( V_63 & V_75 ) )
if ( F_30 ( V_76
, 1 ) < 0 )
F_13 ( & V_15 -> V_4 , L_9 ) ;
}
}
V_65 = F_31 ( V_20 ) ;
if ( V_65 ) {
V_64 = F_32 ( V_65 ) ;
if ( V_64 == 0 )
V_64 = 1 ;
V_65 = F_32 ( V_64 ) ;
F_33 ( V_20 , V_65 , V_65 ) ;
if ( F_30 ( V_77 , V_64 ) < 0 )
F_13 ( & V_15 -> V_4 , L_10 ) ;
} else {
if ( F_30 ( V_78 ,
V_79 ) < 0 )
F_13 ( & V_15 -> V_4 , L_11 ) ;
V_9 &= ~ ( V_72 | V_73 ) ;
if ( F_30 ( V_74 , 0 ) < 0 )
F_13 ( & V_15 -> V_4 , L_12 ) ;
if ( F_30 ( V_76 , 0 ) < 0 )
F_13 ( & V_15 -> V_4 , L_13 ) ;
}
if ( ( V_61 ^ V_63 ) & ( V_80 | V_81 ) ) {
if ( V_61 & V_80 )
V_64 = ( V_61 & V_81 ) ? V_82
: V_83 ;
else
V_64 = V_84 ;
if ( F_30 ( V_85 , V_64 ) < 0 )
F_13 ( & V_15 -> V_4 , L_14 ) ;
}
if ( ( V_61 & V_86 ) != ( V_63 & V_86 ) ) {
switch ( V_61 & V_86 ) {
case V_87 :
V_64 = F_34 ( 5 ) ;
break;
case V_88 :
V_64 = F_34 ( 6 ) ;
break;
case V_89 :
V_64 = F_34 ( 7 ) ;
break;
case V_90 :
V_64 = F_34 ( 8 ) ;
break;
default:
F_19 ( & V_15 -> V_4 ,
L_15 ) ;
V_64 = F_34 ( 8 ) ;
break;
}
if ( F_30 ( V_91 , V_64 ) < 0 )
F_13 ( & V_15 -> V_4 , L_16 ) ;
}
if ( ( V_61 & V_92 ) != ( V_63 & V_92 ) ) {
V_64 = ( V_61 & V_92 ) ? F_35 ( 2 )
: F_35 ( 1 ) ;
if ( F_30 ( V_93 ,
V_64 ) < 0 )
F_13 ( & V_15 -> V_4 , L_17 ) ;
}
if ( ( ( V_60 ^ V_62 ) & ( V_94 | V_95 ) ) ||
( ( V_61 ^ V_63 ) & V_75 ) ) {
V_64 = 0 ;
if ( ( V_60 & V_94 ) || ( V_60 & V_95 ) )
V_64 |= ( V_96 | V_97 ) ;
else
V_64 &= ~ ( V_96 | V_97 ) ;
if ( V_61 & V_75 )
V_64 |= ( V_98 | V_99 ) ;
else
V_64 &= ~ ( V_98 | V_99 ) ;
if ( V_12 )
V_64 &= ~ ( V_99 ) ;
if ( F_30 ( V_78 , V_64 ) < 0 )
F_13 ( & V_15 -> V_4 , L_18 ) ;
}
F_21 ( & V_6 -> V_8 , V_29 ) ;
V_6 -> V_9 = V_9 ;
F_22 ( & V_6 -> V_8 , V_29 ) ;
}
static void F_36 ( struct V_19 * V_20 , int V_100 )
{
struct V_21 * V_15 = V_20 -> V_101 ;
struct V_1 * V_2 = V_15 -> V_2 ;
if ( F_30 ( V_102 , V_100 ? 1 : 0 ) < 0 )
F_13 ( & V_15 -> V_4 , L_19 , V_100 ) ;
}
static int F_37 ( struct V_19 * V_20 )
{
struct V_21 * V_15 = V_20 -> V_101 ;
struct V_5 * V_6 = F_10 ( V_15 ) ;
unsigned long V_9 ;
unsigned long V_29 ;
F_21 ( & V_6 -> V_8 , V_29 ) ;
V_9 = V_6 -> V_9 ;
F_22 ( & V_6 -> V_8 , V_29 ) ;
return V_9 ;
}
static int F_38 ( struct V_19 * V_20 ,
unsigned int V_103 , unsigned int V_104 )
{
struct V_21 * V_15 = V_20 -> V_101 ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_5 * V_6 = F_10 ( V_15 ) ;
unsigned long V_9 ;
unsigned long V_29 ;
int V_22 ;
int V_105 = 0 ;
int V_106 = 0 ;
F_21 ( & V_6 -> V_8 , V_29 ) ;
V_9 = V_6 -> V_9 ;
if ( V_103 & V_73 ) {
V_9 |= V_73 ;
V_105 = 1 ;
}
if ( V_103 & V_72 ) {
V_9 |= V_72 ;
V_106 = 1 ;
}
if ( V_104 & V_73 ) {
V_9 &= ~ V_73 ;
V_105 = 0 ;
}
if ( V_104 & V_72 ) {
V_9 &= ~ V_72 ;
V_106 = 0 ;
}
V_6 -> V_9 = V_9 ;
F_22 ( & V_6 -> V_8 , V_29 ) ;
V_22 = F_30 ( V_76 , V_105 ) ;
if ( V_22 < 0 ) {
F_13 ( & V_15 -> V_4 , L_20 , V_22 ) ;
goto exit;
}
V_22 = F_30 ( V_74 , V_106 ) ;
if ( V_22 < 0 ) {
F_13 ( & V_15 -> V_4 , L_21 , V_22 ) ;
goto exit;
}
exit:
return V_22 ;
}
