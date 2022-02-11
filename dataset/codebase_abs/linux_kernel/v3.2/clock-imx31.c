static void F_1 ( T_1 div , T_1 * V_1 , T_1 * V_2 )
{
T_1 V_3 , V_4 , V_5 , V_6 ;
if ( div >= 512 ) {
* V_1 = 8 ;
* V_2 = 64 ;
} else if ( div >= 64 ) {
V_3 = ( div - 1 ) / 64 + 1 ;
V_5 = 8 ;
for ( V_4 = 8 ; V_4 >= V_3 ; V_4 -- ) {
V_6 = div % V_4 ;
if ( V_6 == 0 ) {
* V_1 = V_4 ;
break;
}
V_6 = V_4 - V_6 ;
if ( V_6 < V_5 ) {
V_5 = V_6 ;
* V_1 = V_4 ;
}
}
* V_2 = ( div + * V_1 - 1 ) / * V_1 ;
} else if ( div <= 8 ) {
* V_1 = div ;
* V_2 = 1 ;
} else {
* V_1 = 1 ;
* V_2 = div ;
}
}
static int F_2 ( struct V_7 * V_7 )
{
T_1 V_8 ;
if ( ! V_7 -> V_9 )
return 0 ;
V_8 = F_3 ( V_7 -> V_9 ) ;
V_8 |= 3 << V_7 -> V_10 ;
F_4 ( V_8 , V_7 -> V_9 ) ;
return 0 ;
}
static void F_5 ( struct V_7 * V_7 )
{
T_1 V_8 ;
if ( ! V_7 -> V_9 )
return;
V_8 = F_3 ( V_7 -> V_9 ) ;
V_8 &= ~ ( 3 << V_7 -> V_10 ) ;
if ( V_7 -> V_9 == V_11 && V_7 -> V_10 == 8 )
V_8 |= ( 1 << V_7 -> V_10 ) ;
F_4 ( V_8 , V_7 -> V_9 ) ;
}
static unsigned long F_6 ( void )
{
unsigned long V_12 ;
unsigned int V_13 ;
V_12 = F_3 ( V_14 ) ;
V_13 = ( V_12 & V_15 ) >> V_16 ;
if ( V_13 == 0x1 )
return V_17 * 1024 ;
else
return F_7 ( & V_18 ) ;
}
static unsigned long F_8 ( struct V_7 * V_7 )
{
unsigned long V_8 ;
V_8 = F_3 ( V_19 ) ;
return F_9 ( V_8 , F_6 () ) ;
}
static unsigned long F_10 ( struct V_7 * V_7 )
{
unsigned long V_8 ;
V_8 = F_3 ( V_20 ) ;
return F_9 ( V_8 , F_6 () ) ;
}
static unsigned long F_11 ( struct V_7 * V_7 )
{
unsigned long V_8 , V_12 ;
V_12 = F_3 ( V_14 ) ;
if ( ! ( V_12 & V_21 ) || ( V_12 & V_22 ) )
return F_7 ( & V_18 ) ;
V_8 = F_3 ( V_23 ) ;
return F_9 ( V_8 , F_6 () ) ;
}
static int F_12 ( struct V_7 * V_7 )
{
T_1 V_8 ;
V_8 = F_3 ( V_14 ) ;
V_8 |= V_24 ;
F_4 ( V_8 , V_14 ) ;
F_13 ( 80 ) ;
return 0 ;
}
static void F_14 ( struct V_7 * V_7 )
{
T_1 V_8 ;
V_8 = F_3 ( V_14 ) ;
V_8 &= ~ V_24 ;
F_4 ( V_8 , V_14 ) ;
}
static int F_15 ( struct V_7 * V_7 )
{
T_1 V_8 ;
V_8 = F_3 ( V_14 ) ;
V_8 |= V_25 ;
F_4 ( V_8 , V_14 ) ;
F_13 ( 80 ) ;
return 0 ;
}
static void F_16 ( struct V_7 * V_7 )
{
T_1 V_8 ;
V_8 = F_3 ( V_14 ) ;
V_8 &= ~ V_25 ;
F_4 ( V_8 , V_14 ) ;
}
static unsigned long F_17 ( struct V_7 * V_7 )
{
T_1 V_26 = F_3 ( V_27 ) ;
if ( ( V_26 & V_28 ) == V_29 )
return F_7 ( & V_30 ) ;
else
return F_7 ( & V_31 ) ;
}
static unsigned long F_18 ( struct V_7 * V_7 )
{
unsigned long V_32 ;
V_32 = F_19 ( V_33 ,
V_34 ) ;
return F_7 ( V_7 -> V_35 ) / ( V_32 + 1 ) ;
}
static unsigned long F_20 ( struct V_7 * V_7 )
{
unsigned long V_36 ;
V_36 = F_19 ( V_37 ,
V_38 ) ;
return F_7 ( V_7 -> V_35 ) / ( V_36 + 1 ) ;
}
static unsigned long F_21 ( struct V_7 * V_7 )
{
unsigned long V_39 ;
V_39 = F_19 ( V_40 ,
V_41 ) ;
return F_7 ( V_7 -> V_35 ) / ( V_39 + 1 ) ;
}
static unsigned long F_22 ( struct V_7 * V_7 )
{
unsigned long V_42 ;
V_42 = F_19 ( V_43 ,
V_44 ) ;
return F_7 ( V_7 -> V_35 ) / ( V_42 + 1 ) ;
}
static unsigned long F_23 ( struct V_7 * V_7 )
{
unsigned long V_45 , V_46 ;
V_45 = F_24 ( V_47 ,
V_48 ) ;
V_46 = F_24 ( V_49 ,
V_50 ) ;
return F_7 ( V_7 -> V_35 ) / ( V_46 + 1 ) / ( V_45 + 1 ) ;
}
static unsigned long F_25 ( struct V_7 * V_7 )
{
T_1 V_8 , V_1 , V_2 ;
V_8 = F_3 ( V_51 ) ;
V_1 = ( V_8 & V_52 ) >>
V_53 ;
V_1 ++ ;
V_2 = ( V_8 & V_54 ) >>
V_55 ;
V_2 ++ ;
return F_7 ( V_7 -> V_35 ) / ( V_1 * V_2 ) ;
}
static unsigned long F_26 ( struct V_7 * V_7 , unsigned long V_56 )
{
T_1 V_1 , V_2 , V_35 = F_7 ( V_7 -> V_35 ) ;
T_1 div = V_35 / V_56 ;
if ( V_35 % V_56 )
div ++ ;
F_1 ( div , & V_1 , & V_2 ) ;
return V_35 / ( V_1 * V_2 ) ;
}
static int F_27 ( struct V_7 * V_7 , unsigned long V_56 )
{
T_1 V_8 , div , V_1 , V_2 , V_35 = F_7 ( V_7 -> V_35 ) ;
div = V_35 / V_56 ;
if ( ( V_35 / div ) != V_56 )
return - V_57 ;
F_1 ( div , & V_1 , & V_2 ) ;
V_8 = F_3 ( V_51 ) &
~ ( V_54 | V_52 ) ;
V_8 |= ( V_2 - 1 ) << V_55 ;
V_8 |= ( V_1 - 1 ) << V_53 ;
F_4 ( V_8 , V_51 ) ;
return 0 ;
}
static unsigned long F_28 ( struct V_7 * V_7 )
{
unsigned long V_58 , V_59 ;
V_58 = F_24 ( V_60 ,
V_61 ) ;
V_59 = F_24 ( V_62 ,
V_63 ) ;
return F_7 ( V_7 -> V_35 ) / ( V_59 + 1 ) / ( V_58 + 1 ) ;
}
static unsigned long F_29 ( struct V_7 * V_7 )
{
unsigned long V_64 , V_65 ;
V_64 = F_24 ( V_66 ,
V_67 ) ;
V_65 = F_24 ( V_68 ,
V_69 ) ;
return F_7 ( V_7 -> V_35 ) / ( V_65 + 1 ) / ( V_64 + 1 ) ;
}
static unsigned long F_30 ( struct V_7 * V_7 )
{
unsigned long V_70 , V_71 ;
V_70 = F_24 ( V_72 ,
V_73 ) ;
V_71 = F_24 ( V_74 ,
V_75 ) ;
return F_7 ( V_7 -> V_35 ) / ( V_71 + 1 ) / ( V_70 + 1 ) ;
}
static unsigned long F_31 ( struct V_7 * V_7 , unsigned long V_56 )
{
T_1 V_1 , V_2 ;
T_1 V_35 = F_7 ( V_7 -> V_35 ) ;
T_1 div = V_35 / V_56 ;
if ( V_35 % V_56 )
div ++ ;
F_1 ( div , & V_1 , & V_2 ) ;
return V_35 / ( V_1 * V_2 ) ;
}
static int F_32 ( struct V_7 * V_7 , unsigned long V_56 )
{
T_1 V_8 , div , V_1 , V_2 , V_35 = F_7 ( V_7 -> V_35 ) ;
div = V_35 / V_56 ;
if ( ( V_35 / div ) != V_56 )
return - V_57 ;
F_1 ( div , & V_1 , & V_2 ) ;
V_8 = F_3 ( V_76 ) &
~ ( V_72 | V_74 ) ;
V_8 |= ( V_1 - 1 ) << V_75 ;
V_8 |= ( V_2 - 1 ) << V_73 ;
F_4 ( V_8 , V_76 ) ;
return 0 ;
}
static unsigned long F_33 ( struct V_7 * V_7 )
{
return F_7 ( V_7 -> V_35 ) / 2 ;
}
static unsigned long F_34 ( struct V_7 * V_7 )
{
unsigned long V_77 ;
V_77 = F_35 ( V_78 ,
V_79 ) ;
return F_7 ( V_7 -> V_35 ) / ( V_77 + 1 ) ;
}
static unsigned long F_36 ( struct V_7 * V_7 )
{
unsigned long V_77 ;
V_77 = F_35 ( V_80 ,
V_81 ) ;
return F_7 ( V_7 -> V_35 ) / ( V_77 + 1 ) ;
}
static unsigned long F_37 ( struct V_7 * V_7 )
{
return V_82 ;
}
static unsigned long F_38 ( struct V_7 * V_7 )
{
return V_17 ;
}
int T_2 F_39 ( unsigned long V_83 )
{
T_1 V_8 ;
V_82 = V_83 ;
F_40 ( V_84 , F_41 ( V_84 ) ) ;
V_8 = F_3 ( V_14 ) ;
if ( ! ( V_8 & V_85 ) )
if ( F_42 ( & V_86 , & V_87 ) )
F_43 ( L_1 , V_88 ) ;
F_4 ( ( 3 << 4 ) , V_89 ) ;
F_4 ( 0 , V_90 ) ;
F_4 ( ( 3 << 8 ) | ( 3 << 14 ) | ( 3 << 16 ) |
1 << 27 | 1 << 28 ,
V_11 ) ;
F_4 ( F_3 ( V_14 ) | ( 1 << 24 ) , V_14 ) ;
F_14 ( & V_87 ) ;
F_44 ( L_2 , F_7 ( & V_18 ) ) ;
F_45 ( & V_91 ) ;
F_45 ( & V_92 ) ;
F_45 ( & V_93 ) ;
F_46 () ;
F_47 ( & V_93 ) ;
F_45 ( & V_30 ) ;
if ( F_46 () >= V_94 ) {
V_8 = F_3 ( V_95 ) ;
V_8 |= V_96 | V_97 ;
F_4 ( V_8 , V_95 ) ;
}
F_48 ( & V_98 , F_49 ( V_99 ) ,
V_100 ) ;
return 0 ;
}
