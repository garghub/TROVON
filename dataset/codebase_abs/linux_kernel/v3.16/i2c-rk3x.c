static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , unsigned int V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_6 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_8 ;
F_5 ( V_2 ) ;
F_1 ( V_2 , V_9 , V_10 ) ;
V_8 = V_11 | F_7 ( V_2 -> V_12 ) | V_13 ;
if ( ! ( V_2 -> V_14 -> V_15 & V_16 ) )
V_8 |= V_17 ;
F_1 ( V_2 , V_8 , V_18 ) ;
}
static void F_8 ( struct V_1 * V_2 , int error )
{
unsigned int V_19 ;
V_2 -> V_20 = 0 ;
V_2 -> V_14 = NULL ;
V_2 -> error = error ;
if ( V_2 -> V_21 ) {
F_1 ( V_2 , V_22 , V_10 ) ;
V_2 -> V_23 = V_24 ;
V_19 = F_3 ( V_2 , V_18 ) ;
V_19 |= V_25 ;
F_1 ( V_2 , V_19 , V_18 ) ;
} else {
V_2 -> V_26 = false ;
V_2 -> V_23 = V_27 ;
F_1 ( V_2 , 0 , V_18 ) ;
F_9 ( & V_2 -> V_28 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned int V_29 = V_2 -> V_14 -> V_29 - V_2 -> V_20 ;
T_1 V_30 ;
V_30 = F_3 ( V_2 , V_18 ) ;
if ( F_11 ( V_29 > 32 ) ) {
V_29 = 32 ;
V_30 &= ~ V_31 ;
} else {
V_30 |= V_31 ;
}
if ( V_2 -> V_20 != 0 ) {
V_30 &= ~ V_32 ;
V_30 |= F_7 ( V_33 ) ;
}
F_1 ( V_2 , V_30 , V_18 ) ;
F_1 ( V_2 , V_29 , V_34 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned int V_35 , V_36 ;
T_1 V_37 = 0 ;
T_1 V_8 ;
T_2 V_38 ;
for ( V_35 = 0 ; V_35 < 8 ; ++ V_35 ) {
V_8 = 0 ;
for ( V_36 = 0 ; V_36 < 4 ; ++ V_36 ) {
if ( V_2 -> V_20 == V_2 -> V_14 -> V_29 )
break;
if ( V_2 -> V_20 == 0 && V_37 == 0 )
V_38 = ( V_2 -> V_39 & 0x7f ) << 1 ;
else
V_38 = V_2 -> V_14 -> V_40 [ V_2 -> V_20 ++ ] ;
V_8 |= V_38 << ( V_36 * 8 ) ;
V_37 ++ ;
}
F_1 ( V_2 , V_8 , V_41 + 4 * V_35 ) ;
if ( V_2 -> V_20 == V_2 -> V_14 -> V_29 )
break;
}
F_1 ( V_2 , V_37 , V_42 ) ;
}
static void F_13 ( struct V_1 * V_2 , unsigned int V_43 )
{
if ( ! ( V_43 & V_9 ) ) {
F_8 ( V_2 , - V_44 ) ;
F_14 ( V_2 -> V_45 , L_1 , V_43 ) ;
F_5 ( V_2 ) ;
return;
}
F_1 ( V_2 , V_9 , V_7 ) ;
F_1 ( V_2 , F_3 ( V_2 , V_18 ) & ~ V_13 , V_18 ) ;
if ( V_2 -> V_12 == V_46 ) {
F_1 ( V_2 , V_47 | V_48 , V_10 ) ;
V_2 -> V_23 = V_49 ;
F_12 ( V_2 ) ;
} else {
F_1 ( V_2 , V_50 | V_48 , V_10 ) ;
V_2 -> V_23 = V_51 ;
F_10 ( V_2 ) ;
}
}
static void F_15 ( struct V_1 * V_2 , unsigned int V_43 )
{
if ( ! ( V_43 & V_47 ) ) {
F_8 ( V_2 , - V_44 ) ;
F_16 ( V_2 -> V_45 , L_2 , V_43 ) ;
F_5 ( V_2 ) ;
return;
}
F_1 ( V_2 , V_47 , V_7 ) ;
if ( V_2 -> V_20 == V_2 -> V_14 -> V_29 )
F_8 ( V_2 , V_2 -> error ) ;
else
F_12 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_43 )
{
unsigned int V_35 ;
unsigned int V_29 = V_2 -> V_14 -> V_29 - V_2 -> V_20 ;
T_1 V_52 ( V_8 ) ;
T_2 V_38 ;
if ( ! ( V_43 & V_50 ) )
return;
F_1 ( V_2 , V_50 , V_7 ) ;
for ( V_35 = 0 ; V_35 < V_29 ; ++ V_35 ) {
if ( V_35 % 4 == 0 )
V_8 = F_3 ( V_2 , V_53 + ( V_35 / 4 ) * 4 ) ;
V_38 = ( V_8 >> ( ( V_35 % 4 ) * 8 ) ) & 0xff ;
V_2 -> V_14 -> V_40 [ V_2 -> V_20 ++ ] = V_38 ;
}
if ( V_2 -> V_20 == V_2 -> V_14 -> V_29 )
F_8 ( V_2 , V_2 -> error ) ;
else
F_10 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_43 )
{
unsigned int V_30 ;
if ( ! ( V_43 & V_22 ) ) {
F_8 ( V_2 , - V_44 ) ;
F_16 ( V_2 -> V_45 , L_3 , V_43 ) ;
F_5 ( V_2 ) ;
return;
}
F_1 ( V_2 , V_22 , V_7 ) ;
V_30 = F_3 ( V_2 , V_18 ) ;
V_30 &= ~ V_25 ;
F_1 ( V_2 , V_30 , V_18 ) ;
V_2 -> V_26 = false ;
V_2 -> V_23 = V_27 ;
F_9 ( & V_2 -> V_28 ) ;
}
static T_3 F_19 ( int V_54 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
unsigned int V_43 ;
F_20 ( & V_2 -> V_56 ) ;
V_43 = F_3 ( V_2 , V_7 ) ;
if ( V_2 -> V_23 == V_27 ) {
F_14 ( V_2 -> V_45 , L_4 , V_43 ) ;
F_5 ( V_2 ) ;
goto V_57;
}
F_21 ( V_2 -> V_45 , L_5 , V_2 -> V_23 , V_43 ) ;
V_43 &= ~ ( V_58 | V_59 ) ;
if ( V_43 & V_48 ) {
F_1 ( V_2 , V_48 , V_7 ) ;
V_43 &= ~ V_48 ;
if ( ! ( V_2 -> V_14 -> V_15 & V_16 ) )
F_8 ( V_2 , - V_60 ) ;
}
if ( F_11 ( V_43 == 0 ) )
goto V_57;
switch ( V_2 -> V_23 ) {
case V_61 :
F_13 ( V_2 , V_43 ) ;
break;
case V_49 :
F_15 ( V_2 , V_43 ) ;
break;
case V_51 :
F_17 ( V_2 , V_43 ) ;
break;
case V_24 :
F_18 ( V_2 , V_43 ) ;
break;
case V_27 :
break;
}
V_57:
F_22 ( & V_2 -> V_56 ) ;
return V_62 ;
}
static void F_23 ( struct V_1 * V_2 , unsigned long V_63 )
{
unsigned long V_64 = F_24 ( V_2 -> V_65 ) ;
unsigned int div ;
div = F_25 ( V_64 , V_63 * 8 ) ;
div = F_25 ( div , 2 ) ;
F_1 ( V_2 , ( div << 16 ) | ( div & 0xffff ) , V_66 ) ;
}
static int F_26 ( struct V_1 * V_2 , struct V_67 * V_68 , int V_69 )
{
T_1 V_39 = ( V_68 [ 0 ] . V_39 & 0x7f ) << 1 ;
int V_70 = 0 ;
if ( V_69 >= 2 && V_68 [ 0 ] . V_29 < 4 &&
! ( V_68 [ 0 ] . V_15 & V_71 ) && ( V_68 [ 1 ] . V_15 & V_71 ) ) {
T_1 V_72 = 0 ;
int V_35 ;
F_21 ( V_2 -> V_45 , L_6 ,
V_39 >> 1 ) ;
for ( V_35 = 0 ; V_35 < V_68 [ 0 ] . V_29 ; ++ V_35 ) {
V_72 |= V_68 [ 0 ] . V_40 [ V_35 ] << ( V_35 * 8 ) ;
V_72 |= F_27 ( V_35 ) ;
}
V_2 -> V_14 = & V_68 [ 1 ] ;
V_2 -> V_12 = V_73 ;
F_1 ( V_2 , V_39 | F_27 ( 0 ) , V_74 ) ;
F_1 ( V_2 , V_72 , V_75 ) ;
V_70 = 2 ;
} else {
if ( V_68 [ 0 ] . V_15 & V_71 ) {
V_39 |= 1 ;
V_2 -> V_12 = V_73 ;
F_1 ( V_2 , V_39 | F_27 ( 0 ) ,
V_74 ) ;
F_1 ( V_2 , 0 , V_75 ) ;
} else {
V_2 -> V_12 = V_46 ;
}
V_2 -> V_14 = & V_68 [ 0 ] ;
V_70 = 1 ;
}
V_2 -> V_39 = V_68 [ 0 ] . V_39 ;
V_2 -> V_26 = true ;
V_2 -> V_23 = V_61 ;
V_2 -> V_20 = 0 ;
V_2 -> error = 0 ;
F_5 ( V_2 ) ;
return V_70 ;
}
static int F_28 ( struct V_76 * V_77 ,
struct V_67 * V_68 , int V_69 )
{
struct V_1 * V_2 = (struct V_1 * ) V_77 -> V_78 ;
unsigned long V_79 , V_15 ;
int V_70 = 0 ;
int V_35 ;
F_29 ( & V_2 -> V_56 , V_15 ) ;
F_30 ( V_2 -> V_65 ) ;
F_23 ( V_2 , V_2 -> V_80 ) ;
V_2 -> V_21 = false ;
for ( V_35 = 0 ; V_35 < V_69 ; V_35 += V_70 ) {
V_70 = F_26 ( V_2 , V_68 + V_35 , V_69 - V_35 ) ;
if ( V_70 < 0 ) {
F_16 ( V_2 -> V_45 , L_7 ) ;
break;
}
if ( V_35 + V_70 >= V_69 )
V_2 -> V_21 = true ;
F_31 ( & V_2 -> V_56 , V_15 ) ;
F_6 ( V_2 ) ;
V_79 = F_32 ( V_2 -> V_28 , ! V_2 -> V_26 ,
F_33 ( V_81 ) ) ;
F_29 ( & V_2 -> V_56 , V_15 ) ;
if ( V_79 == 0 ) {
F_16 ( V_2 -> V_45 , L_8 ,
F_3 ( V_2 , V_7 ) , V_2 -> V_23 ) ;
F_1 ( V_2 , 0 , V_10 ) ;
F_1 ( V_2 , V_11 | V_25 , V_18 ) ;
V_2 -> V_23 = V_27 ;
V_70 = - V_82 ;
break;
}
if ( V_2 -> error ) {
V_70 = V_2 -> error ;
break;
}
}
F_34 ( V_2 -> V_65 ) ;
F_31 ( & V_2 -> V_56 , V_15 ) ;
return V_70 ;
}
static T_1 F_35 ( struct V_76 * V_77 )
{
return V_83 | V_84 | V_85 ;
}
static int F_36 ( struct V_86 * V_87 )
{
struct V_88 * V_89 = V_87 -> V_45 . V_90 ;
const struct V_91 * V_92 ;
struct V_1 * V_2 ;
struct V_93 * V_94 ;
int V_70 = 0 ;
int V_95 ;
T_1 V_3 ;
int V_96 ;
V_2 = F_37 ( & V_87 -> V_45 , sizeof( struct V_1 ) , V_97 ) ;
if ( ! V_2 )
return - V_98 ;
V_92 = F_38 ( V_99 , V_89 ) ;
V_2 -> V_100 = (struct V_101 * ) V_92 -> V_102 ;
if ( F_39 ( V_87 -> V_45 . V_90 , L_9 ,
& V_2 -> V_80 ) ) {
F_40 ( & V_87 -> V_45 , L_10 ,
V_103 ) ;
V_2 -> V_80 = V_103 ;
}
if ( V_2 -> V_80 == 0 || V_2 -> V_80 > 400 * 1000 ) {
F_14 ( & V_87 -> V_45 , L_11 ) ;
F_14 ( & V_87 -> V_45 , L_10 ,
V_103 ) ;
V_2 -> V_80 = V_103 ;
}
F_41 ( V_2 -> V_77 . V_104 , L_12 , sizeof( V_2 -> V_77 . V_104 ) ) ;
V_2 -> V_77 . V_105 = V_106 ;
V_2 -> V_77 . V_107 = & V_108 ;
V_2 -> V_77 . V_109 = 3 ;
V_2 -> V_77 . V_45 . V_90 = V_89 ;
V_2 -> V_77 . V_78 = V_2 ;
V_2 -> V_77 . V_45 . V_110 = & V_87 -> V_45 ;
V_2 -> V_45 = & V_87 -> V_45 ;
F_42 ( & V_2 -> V_56 ) ;
F_43 ( & V_2 -> V_28 ) ;
V_2 -> V_65 = F_44 ( & V_87 -> V_45 , NULL ) ;
if ( F_45 ( V_2 -> V_65 ) ) {
F_16 ( & V_87 -> V_45 , L_13 ) ;
return F_46 ( V_2 -> V_65 ) ;
}
V_94 = F_47 ( V_87 , V_111 , 0 ) ;
V_2 -> V_5 = F_48 ( & V_87 -> V_45 , V_94 ) ;
if ( F_45 ( V_2 -> V_5 ) )
return F_46 ( V_2 -> V_5 ) ;
V_95 = F_49 ( V_89 , L_14 ) ;
if ( V_2 -> V_100 -> V_112 >= 0 ) {
struct V_113 * V_114 ;
V_114 = F_50 ( V_89 , L_15 ) ;
if ( F_45 ( V_114 ) ) {
F_16 ( & V_87 -> V_45 ,
L_16 ) ;
return F_46 ( V_114 ) ;
}
if ( V_95 < 0 ) {
F_16 ( & V_87 -> V_45 , L_17 ) ;
return - V_115 ;
}
V_3 = F_51 ( 27 + V_95 ) | F_51 ( 11 + V_95 ) ;
V_70 = F_52 ( V_114 , V_2 -> V_100 -> V_112 , V_3 ) ;
if ( V_70 != 0 ) {
F_16 ( V_2 -> V_45 , L_18 , V_70 ) ;
return V_70 ;
}
}
V_96 = F_53 ( V_87 , 0 ) ;
if ( V_96 < 0 ) {
F_16 ( & V_87 -> V_45 , L_19 ) ;
return V_96 ;
}
V_70 = F_54 ( & V_87 -> V_45 , V_96 , F_19 ,
0 , F_55 ( & V_87 -> V_45 ) , V_2 ) ;
if ( V_70 < 0 ) {
F_16 ( & V_87 -> V_45 , L_20 ) ;
return V_70 ;
}
F_56 ( V_87 , V_2 ) ;
V_70 = F_57 ( V_2 -> V_65 ) ;
if ( V_70 < 0 ) {
F_16 ( & V_87 -> V_45 , L_21 ) ;
return V_70 ;
}
V_70 = F_58 ( & V_2 -> V_77 ) ;
if ( V_70 < 0 ) {
F_16 ( & V_87 -> V_45 , L_22 ) ;
goto V_116;
}
F_40 ( & V_87 -> V_45 , L_23 , V_2 -> V_5 ) ;
return 0 ;
V_116:
F_59 ( V_2 -> V_65 ) ;
return V_70 ;
}
static int F_60 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_61 ( V_87 ) ;
F_62 ( & V_2 -> V_77 ) ;
F_59 ( V_2 -> V_65 ) ;
return 0 ;
}
