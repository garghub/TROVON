static inline void F_1 ( int V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_3 + ( V_1 << V_4 ) ) ;
}
static inline T_1 F_3 ( int V_1 )
{
return F_4 ( V_3 + ( V_1 << V_4 ) ) ;
}
static inline void F_5 ( T_2 V_5 , unsigned long V_6 )
{
T_1 V_7 , V_2 = 0 ;
int V_8 , V_9 ;
if ( V_6 & V_10 )
V_2 ^= 0x03 ;
V_2 = V_6 & 0x3f ;
if ( V_5 & 1 )
V_8 = 6 ;
else
V_8 = 0 ;
if ( V_5 <= 1 )
V_9 = V_11 ;
else
V_9 = V_12 ;
V_7 = F_3 ( V_9 ) ;
V_7 &= ~ ( 0x3f << V_8 ) ;
V_7 |= V_2 << V_8 ;
F_1 ( V_9 , V_7 ) ;
}
static int F_6 ( T_1 V_13 , T_1 V_2 , int V_14 )
{
T_1 V_7 ;
int V_15 = 0 ;
unsigned long V_16 = V_17 + V_18 ;
for (; ; ) {
V_7 = F_3 ( V_19 ) ;
if ( ( V_7 & V_13 ) == V_2 )
break;
if ( F_7 ( V_17 , V_16 ) ) {
F_8 ( V_20 L_1
L_2 ,
V_21 , V_7 , V_13 , V_2 ) ;
return - 1 ;
}
V_15 ++ ;
if ( V_14 && V_15 > 64 )
break;
}
return 0 ;
}
static void F_9 ( int V_22 )
{
T_1 V_7 ;
V_7 = F_3 ( V_23 ) ;
V_7 &= ~ ( 0x03 << 1 ) ;
V_7 |= V_22 << 1 ;
F_1 ( V_23 , V_7 ) ;
}
static void F_10 ( struct V_24 * V_25 , int V_26 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
T_1 V_7 ;
int V_30 ;
F_11 ( F_6 ( V_31 , 0 , 0 ) ) ;
V_7 = F_3 ( V_19 ) ;
V_30 = ( V_7 >> 10 ) & 0x03 ;
if ( V_26 == V_32 || V_30 != V_25 -> V_33 ) {
V_7 &= ~ V_34 ;
F_1 ( V_19 , V_7 ) ;
}
if ( V_26 == V_35 ) {
F_9 ( V_28 -> V_22 ) ;
if ( V_25 -> V_36 & V_37 )
F_1 ( V_38 , 1 ) ;
else
F_1 ( V_38 , 0 ) ;
V_7 = V_25 -> V_33 << 10 ;
V_7 |= V_34 ;
F_1 ( V_19 , V_7 ) ;
}
}
static int F_12 ( struct V_24 * V_25 , struct V_39 * V_40 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned V_41 = V_40 -> V_41 ;
unsigned V_42 = V_28 -> V_43 ;
unsigned V_44 ;
T_1 V_2 , V_7 ;
int V_45 = 0 ;
if ( ! V_40 -> V_46 && ! V_40 -> V_47 )
return 0 ;
if ( V_40 -> V_46 && V_40 -> V_47 )
return - V_48 ;
V_7 = V_25 -> V_33 << 10 ;
V_7 |= V_34 ;
if ( V_40 -> V_46 ) {
const T_2 * V_49 = V_40 -> V_46 ;
while ( V_41 >= 1 ) {
V_2 = * V_49 ++ ;
if ( V_42 > 8 ) {
V_44 = 2 ;
V_2 |= * V_49 ++ << 8 ;
} else
V_44 = 1 ;
V_2 <<= 16 - V_42 ;
#ifdef F_13
F_14 ( L_3 ,
F_15 ( & V_25 -> V_50 ) , V_42 , V_2 ) ;
#endif
if ( F_6 ( V_31 , 0 , 0 ) )
goto V_51;
F_1 ( V_52 , V_2 ) ;
V_2 = V_53 | V_7 | ( V_42 << 5 ) ;
F_1 ( V_19 , V_2 ) ;
V_41 -= V_44 ;
if ( F_6 ( V_31 , V_31 , 1 ) )
goto V_51;
V_45 += V_44 ;
}
if ( F_6 ( V_31 , 0 , 0 ) )
goto V_51;
} else if ( V_40 -> V_47 ) {
T_2 * V_49 = V_40 -> V_47 ;
while ( V_41 ) {
if ( V_42 > 8 ) {
V_44 = 2 ;
} else
V_44 = 1 ;
V_2 = V_53 | V_7 | ( V_42 << 0 ) ;
F_1 ( V_19 , V_2 ) ;
V_41 -= V_44 ;
( void ) F_6 ( V_31 , V_31 , 1 ) ;
if ( F_6 ( V_54 | V_31 ,
V_54 , 0 ) )
goto V_51;
V_2 = F_3 ( V_55 ) ;
V_2 &= ( 1 << V_42 ) - 1 ;
* V_49 ++ = ( T_2 ) V_2 ;
if ( V_44 == 2 )
* V_49 ++ = V_2 >> 8 ;
V_45 += V_44 ;
#ifdef F_13
F_14 ( L_4 ,
F_15 ( & V_25 -> V_50 ) , V_42 , V_2 ) ;
#endif
}
}
return V_45 ;
V_51:
return - V_56 ;
}
static int F_16 ( struct V_24 * V_25 , struct V_39 * V_40 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
struct V_57 * V_58 ;
unsigned V_6 = 0 ;
unsigned V_42 ;
unsigned V_59 ;
unsigned long V_60 ;
int V_22 ;
int V_61 ;
int V_62 ;
int V_45 ;
V_58 = F_17 ( V_25 -> V_63 ) ;
if ( V_25 -> V_33 > 3 ) {
F_14 ( L_5 , F_15 ( & V_25 -> V_50 ) , V_25 -> V_33 ) ;
V_45 = - V_64 ;
goto V_65;
}
V_42 = V_25 -> V_43 ;
if ( V_40 != NULL && V_40 -> V_43 )
V_42 = V_40 -> V_43 ;
if ( V_42 > 16 ) {
F_14 ( L_6 , F_15 ( & V_25 -> V_50 ) , V_42 ) ;
V_45 = - V_64 ;
goto V_65;
}
V_28 -> V_43 = V_42 ;
if ( V_25 -> V_36 & V_66 )
V_6 |= V_67 ;
if ( V_25 -> V_36 & V_37 )
V_6 |= V_10 ;
switch ( V_25 -> V_36 & ( V_37 | V_68 ) ) {
case V_69 :
case V_70 :
V_6 |= V_71 | V_72 ;
break;
case V_73 :
case V_74 :
V_6 |= V_75 | V_76 ;
break;
}
V_60 = F_18 ( V_58 -> V_77 ) ;
V_59 = V_25 -> V_78 ;
if ( V_40 != NULL && V_40 -> V_79 )
V_59 = V_40 -> V_79 ;
if ( ! V_59 ) {
F_14 ( L_7 , F_15 ( & V_25 -> V_50 ) ) ;
V_45 = - V_80 ;
goto V_65;
}
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
switch ( V_22 ) {
case 0 :
V_61 = 2 ;
break;
case 1 :
V_61 = 4 ;
break;
case 2 :
V_61 = 7 ;
break;
default:
case 3 :
V_61 = 10 ;
break;
}
V_62 = ( V_60 / V_61 + V_59 - 1 ) / V_59 ;
if ( V_62 <= 8 )
break;
}
if ( V_22 == 4 ) {
F_14 ( L_8 ,
F_15 ( & V_25 -> V_50 ) , V_60 / 10 / 8 , V_59 ) ;
V_45 = - V_81 ;
goto V_65;
}
V_28 -> V_22 = V_22 ;
F_9 ( V_22 ) ;
V_60 /= V_61 ;
switch ( V_62 ) {
case 0 :
case 1 :
case 2 :
V_6 |= V_82 ;
V_60 /= 2 ;
break;
case 3 :
case 4 :
V_6 |= V_83 ;
V_60 /= 4 ;
break;
case 5 :
case 6 :
case 7 :
case 8 :
V_6 |= V_84 ;
V_60 /= 8 ;
break;
}
F_5 ( V_25 -> V_33 , V_6 ) ;
F_14 ( L_9 ,
V_21 , V_6 ,
F_18 ( V_58 -> V_77 ) / 1000 ,
V_60 / 1000 ) ;
V_45 = 0 ;
V_65:
return V_45 ;
}
static int F_19 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
if ( V_28 == NULL ) {
V_28 = F_20 ( sizeof( * V_28 ) , V_85 ) ;
if ( V_28 == NULL )
return - V_86 ;
V_25 -> V_29 = V_28 ;
}
return F_16 ( V_25 , NULL ) ;
}
static void F_21 ( struct V_24 * V_25 )
{
F_22 ( V_25 -> V_29 ) ;
}
static void F_23 ( struct V_57 * V_58 )
{
F_1 ( V_23 , 0 ) ;
F_24 ( V_58 -> V_77 ) ;
F_25 ( V_58 -> V_77 ) ;
F_26 ( V_58 -> V_87 . V_63 ) ;
}
static int F_27 ( struct V_88 * V_89 )
{
struct V_90 * V_63 ;
struct V_57 * V_58 ;
int V_45 ;
V_63 = F_28 ( & V_89 -> V_50 , sizeof *V_58 ) ;
if ( ! V_63 )
return - V_64 ;
V_58 = F_17 ( V_63 ) ;
V_3 = F_29 ( V_91 , V_92 ) ;
if ( ! V_3 ) {
F_30 ( & V_89 -> V_50 , L_10 ) ;
F_26 ( V_63 ) ;
return - V_86 ;
}
F_31 ( V_89 , V_58 ) ;
V_58 -> V_77 = F_32 ( & V_89 -> V_50 , L_11 ) ;
if ( F_33 ( V_58 -> V_77 ) ) {
V_45 = F_34 ( V_58 -> V_77 ) ;
F_30 ( & V_89 -> V_50 , L_12 ) ;
F_26 ( V_63 ) ;
return V_45 ;
}
F_35 ( V_58 -> V_77 ) ;
if ( F_36 () )
V_4 = 1 ;
else
V_4 = 2 ;
F_1 ( V_23 , 1 ) ;
V_63 -> V_93 = V_37 | V_68 | V_66 ;
V_63 -> V_6 = V_94 ;
V_63 -> V_95 = 2 ;
V_63 -> V_96 = 4 ;
V_63 -> V_97 = F_19 ;
V_63 -> V_98 = F_21 ;
V_58 -> V_87 . V_63 = V_63 ;
V_58 -> V_87 . V_99 = F_10 ;
V_58 -> V_87 . V_100 = F_16 ;
V_58 -> V_87 . V_101 = F_12 ;
V_45 = F_37 ( & V_58 -> V_87 ) ;
if ( V_45 < 0 ) {
F_23 ( V_58 ) ;
F_38 ( V_3 ) ;
}
return V_45 ;
}
static int F_39 ( struct V_88 * V_89 )
{
struct V_57 * V_58 = F_40 ( V_89 ) ;
int V_45 ;
V_45 = F_41 ( & V_58 -> V_87 ) ;
F_23 ( V_58 ) ;
F_38 ( V_3 ) ;
return V_45 ;
}
static int T_3 F_42 ( void )
{
if ( F_43 () ) {
F_44 ( V_102 ) ;
F_44 ( V_103 ) ;
}
if ( F_45 () ) {
int V_2 = F_46 ( V_104 ) & ~ 0x00EEE000 ;
F_47 ( V_2 | 0x00AAA000 , V_104 ) ;
}
return F_48 ( & V_105 , F_27 ) ;
}
static void T_4 F_49 ( void )
{
F_50 ( & V_105 ) ;
}
