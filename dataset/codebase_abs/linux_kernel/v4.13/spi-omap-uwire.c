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
unsigned V_41 = V_40 -> V_41 ;
unsigned V_42 = V_40 -> V_43 ;
unsigned V_44 ;
T_1 V_2 , V_7 ;
int V_45 = 0 ;
if ( ! V_40 -> V_46 && ! V_40 -> V_47 )
return 0 ;
V_7 = V_25 -> V_33 << 10 ;
V_7 |= V_34 ;
if ( V_40 -> V_46 ) {
const T_2 * V_48 = V_40 -> V_46 ;
while ( V_41 >= 1 ) {
V_2 = * V_48 ++ ;
if ( V_42 > 8 ) {
V_44 = 2 ;
V_2 |= * V_48 ++ << 8 ;
} else
V_44 = 1 ;
V_2 <<= 16 - V_42 ;
#ifdef F_13
F_14 ( L_3 ,
F_15 ( & V_25 -> V_49 ) , V_42 , V_2 ) ;
#endif
if ( F_6 ( V_31 , 0 , 0 ) )
goto V_50;
F_1 ( V_51 , V_2 ) ;
V_2 = V_52 | V_7 | ( V_42 << 5 ) ;
F_1 ( V_19 , V_2 ) ;
V_41 -= V_44 ;
if ( F_6 ( V_31 , V_31 , 1 ) )
goto V_50;
V_45 += V_44 ;
}
if ( F_6 ( V_31 , 0 , 0 ) )
goto V_50;
} else if ( V_40 -> V_47 ) {
T_2 * V_48 = V_40 -> V_47 ;
while ( V_41 ) {
if ( V_42 > 8 ) {
V_44 = 2 ;
} else
V_44 = 1 ;
V_2 = V_52 | V_7 | ( V_42 << 0 ) ;
F_1 ( V_19 , V_2 ) ;
V_41 -= V_44 ;
( void ) F_6 ( V_31 , V_31 , 1 ) ;
if ( F_6 ( V_53 | V_31 ,
V_53 , 0 ) )
goto V_50;
V_2 = F_3 ( V_54 ) ;
V_2 &= ( 1 << V_42 ) - 1 ;
* V_48 ++ = ( T_2 ) V_2 ;
if ( V_44 == 2 )
* V_48 ++ = V_2 >> 8 ;
V_45 += V_44 ;
#ifdef F_13
F_14 ( L_4 ,
F_15 ( & V_25 -> V_49 ) , V_42 , V_2 ) ;
#endif
}
}
return V_45 ;
V_50:
return - V_55 ;
}
static int F_16 ( struct V_24 * V_25 , struct V_39 * V_40 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
struct V_56 * V_57 ;
unsigned V_6 = 0 ;
unsigned V_58 ;
unsigned long V_59 ;
int V_22 ;
int V_60 ;
int V_61 ;
int V_45 ;
V_57 = F_17 ( V_25 -> V_62 ) ;
if ( V_25 -> V_36 & V_63 )
V_6 |= V_64 ;
if ( V_25 -> V_36 & V_37 )
V_6 |= V_10 ;
switch ( V_25 -> V_36 & ( V_37 | V_65 ) ) {
case V_66 :
case V_67 :
V_6 |= V_68 | V_69 ;
break;
case V_70 :
case V_71 :
V_6 |= V_72 | V_73 ;
break;
}
V_59 = F_18 ( V_57 -> V_74 ) ;
if ( V_40 != NULL )
V_58 = V_40 -> V_75 ;
else
V_58 = V_25 -> V_76 ;
if ( ! V_58 ) {
F_14 ( L_5 , F_15 ( & V_25 -> V_49 ) ) ;
V_45 = - V_77 ;
goto V_78;
}
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
switch ( V_22 ) {
case 0 :
V_60 = 2 ;
break;
case 1 :
V_60 = 4 ;
break;
case 2 :
V_60 = 7 ;
break;
default:
case 3 :
V_60 = 10 ;
break;
}
V_61 = ( V_59 / V_60 + V_58 - 1 ) / V_58 ;
if ( V_61 <= 8 )
break;
}
if ( V_22 == 4 ) {
F_14 ( L_6 ,
F_15 ( & V_25 -> V_49 ) , V_59 / 10 / 8 , V_58 ) ;
V_45 = - V_79 ;
goto V_78;
}
V_28 -> V_22 = V_22 ;
F_9 ( V_22 ) ;
V_59 /= V_60 ;
switch ( V_61 ) {
case 0 :
case 1 :
case 2 :
V_6 |= V_80 ;
V_59 /= 2 ;
break;
case 3 :
case 4 :
V_6 |= V_81 ;
V_59 /= 4 ;
break;
case 5 :
case 6 :
case 7 :
case 8 :
V_6 |= V_82 ;
V_59 /= 8 ;
break;
}
F_5 ( V_25 -> V_33 , V_6 ) ;
F_14 ( L_7 ,
V_21 , V_6 ,
F_18 ( V_57 -> V_74 ) / 1000 ,
V_59 / 1000 ) ;
V_45 = 0 ;
V_78:
return V_45 ;
}
static int F_19 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
if ( V_28 == NULL ) {
V_28 = F_20 ( sizeof( * V_28 ) , V_83 ) ;
if ( V_28 == NULL )
return - V_84 ;
V_25 -> V_29 = V_28 ;
}
return F_16 ( V_25 , NULL ) ;
}
static void F_21 ( struct V_24 * V_25 )
{
F_22 ( V_25 -> V_29 ) ;
}
static void F_23 ( struct V_56 * V_57 )
{
F_1 ( V_23 , 0 ) ;
F_24 ( V_57 -> V_74 ) ;
F_25 ( V_57 -> V_85 . V_62 ) ;
}
static int F_26 ( struct V_86 * V_87 )
{
struct V_88 * V_62 ;
struct V_56 * V_57 ;
int V_45 ;
V_62 = F_27 ( & V_87 -> V_49 , sizeof *V_57 ) ;
if ( ! V_62 )
return - V_89 ;
V_57 = F_17 ( V_62 ) ;
V_3 = F_28 ( & V_87 -> V_49 , V_90 , V_91 ) ;
if ( ! V_3 ) {
F_29 ( & V_87 -> V_49 , L_8 ) ;
F_25 ( V_62 ) ;
return - V_84 ;
}
F_30 ( V_87 , V_57 ) ;
V_57 -> V_74 = F_31 ( & V_87 -> V_49 , L_9 ) ;
if ( F_32 ( V_57 -> V_74 ) ) {
V_45 = F_33 ( V_57 -> V_74 ) ;
F_29 ( & V_87 -> V_49 , L_10 ) ;
F_25 ( V_62 ) ;
return V_45 ;
}
F_34 ( V_57 -> V_74 ) ;
if ( F_35 () )
V_4 = 1 ;
else
V_4 = 2 ;
F_1 ( V_23 , 1 ) ;
V_62 -> V_92 = V_37 | V_65 | V_63 ;
V_62 -> V_93 = F_36 ( 1 , 16 ) ;
V_62 -> V_6 = V_94 ;
V_62 -> V_95 = 2 ;
V_62 -> V_96 = 4 ;
V_62 -> V_97 = F_19 ;
V_62 -> V_98 = F_21 ;
V_57 -> V_85 . V_62 = V_62 ;
V_57 -> V_85 . V_99 = F_10 ;
V_57 -> V_85 . V_100 = F_16 ;
V_57 -> V_85 . V_101 = F_12 ;
V_45 = F_37 ( & V_57 -> V_85 ) ;
if ( V_45 < 0 ) {
F_23 ( V_57 ) ;
}
return V_45 ;
}
static int F_38 ( struct V_86 * V_87 )
{
struct V_56 * V_57 = F_39 ( V_87 ) ;
F_40 ( & V_57 -> V_85 ) ;
F_23 ( V_57 ) ;
return 0 ;
}
static int T_3 F_41 ( void )
{
if ( F_42 () ) {
F_43 ( V_102 ) ;
F_43 ( V_103 ) ;
}
if ( F_44 () ) {
int V_2 = F_45 ( V_104 ) & ~ 0x00EEE000 ;
F_46 ( V_2 | 0x00AAA000 , V_104 ) ;
}
return F_47 ( & V_105 ) ;
}
static void T_4 F_48 ( void )
{
F_49 ( & V_105 ) ;
}
