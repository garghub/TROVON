static int F_1 ( unsigned int V_1 )
{
return ( V_1 & ( V_2 - 1 ) ) >> V_3 ;
}
static unsigned long F_2 ( unsigned int V_1 ,
unsigned long V_4 )
{
return ( F_1 ( V_1 ) + V_4 ) << V_3 ;
}
static inline unsigned long F_3 ( unsigned long V_5 ,
unsigned int V_1 , unsigned long V_4 )
{
unsigned long V_6 = ( V_5 + V_2 - 1 ) & ~ ( V_2 - 1 ) ;
unsigned long V_7 = ( V_2 - 1 ) &
( F_2 ( V_1 , V_4 ) << V_3 ) ;
return V_6 + V_7 ;
}
static unsigned long F_4 ( void )
{
unsigned long V_8 ;
V_8 = F_5 ( V_9 ) ;
if ( V_8 > V_10 )
V_8 = V_10 ;
V_8 += ( V_11 << V_3 ) ;
return F_6 ( V_12 - V_8 ) ;
}
unsigned long F_7 ( struct V_13 * V_14 , unsigned long V_5 ,
unsigned long V_15 , unsigned long V_4 , unsigned long V_16 )
{
struct V_17 * V_18 = V_19 -> V_18 ;
struct V_20 * V_21 ;
unsigned long V_22 = V_23 ;
int V_24 , V_1 ;
struct V_25 V_26 ;
if ( V_15 > V_22 )
return - V_27 ;
V_24 = 0 ;
if ( V_14 || ( V_16 & V_28 ) )
V_24 = 1 ;
V_1 = F_8 ( V_14 ) ;
if ( V_16 & V_29 ) {
if ( ( V_16 & V_28 ) && V_1 &&
( V_5 - F_2 ( V_1 , V_4 ) )
& ( V_2 - 1 ) )
return - V_30 ;
goto V_31;
}
if ( V_5 ) {
if ( V_24 && V_1 )
V_5 = F_3 ( V_5 , V_1 , V_4 ) ;
else
V_5 = F_6 ( V_5 ) ;
V_21 = F_9 ( V_18 , V_5 ) ;
if ( V_22 - V_15 >= V_5 &&
( ! V_21 || V_5 + V_15 <= V_21 -> V_32 ) )
goto V_31;
}
V_26 . V_16 = 0 ;
V_26 . V_33 = V_15 ;
V_26 . V_34 = V_18 -> V_35 ;
V_26 . V_36 = F_4 () ;
V_26 . V_37 = V_1 ? ( V_38 & ( V_2 - 1 ) ) : 0 ;
V_26 . V_39 = F_2 ( V_1 , V_4 ) ;
V_5 = F_10 ( & V_26 ) ;
V_31:
if ( V_24 && ! V_1 && ! ( V_5 & ~ V_38 ) )
F_11 ( V_14 , V_5 - ( V_4 << V_3 ) ) ;
return V_5 ;
}
unsigned long
F_12 ( struct V_13 * V_14 , const unsigned long V_40 ,
const unsigned long V_15 , const unsigned long V_4 ,
const unsigned long V_16 )
{
struct V_20 * V_21 ;
struct V_17 * V_18 = V_19 -> V_18 ;
unsigned long V_5 = V_40 ;
int V_24 , V_1 ;
struct V_25 V_26 ;
#ifdef F_13
F_14 ( ! F_15 ( V_41 ) ) ;
#endif
if ( V_15 > V_23 )
return - V_27 ;
V_24 = 0 ;
if ( V_14 || ( V_16 & V_28 ) )
V_24 = 1 ;
V_1 = F_8 ( V_14 ) ;
if ( V_16 & V_29 ) {
if ( ( V_16 & V_28 ) && V_1 &&
( V_5 - F_2 ( V_1 , V_4 ) )
& ( V_2 - 1 ) )
return - V_30 ;
goto V_31;
}
if ( V_5 ) {
if ( V_24 && V_1 )
V_5 = F_3 ( V_5 , V_1 , V_4 ) ;
else
V_5 = F_6 ( V_5 ) ;
V_21 = F_9 ( V_18 , V_5 ) ;
if ( V_23 - V_15 >= V_5 &&
( ! V_21 || V_5 + V_15 <= V_21 -> V_32 ) )
goto V_31;
}
V_26 . V_16 = V_42 ;
V_26 . V_33 = V_15 ;
V_26 . V_34 = V_43 ;
V_26 . V_36 = V_18 -> V_44 ;
V_26 . V_37 = V_1 ? ( V_38 & ( V_2 - 1 ) ) : 0 ;
V_26 . V_39 = F_2 ( V_1 , V_4 ) ;
V_5 = F_10 ( & V_26 ) ;
if ( ! ( V_5 & ~ V_38 ) )
goto V_31;
F_16 ( V_5 != - V_27 ) ;
return F_7 ( V_14 , V_40 , V_15 , V_4 , V_16 ) ;
V_31:
if ( V_24 && ! V_1 && ! ( V_5 & ~ V_38 ) )
F_11 ( V_14 , V_5 - ( V_4 << V_3 ) ) ;
return V_5 ;
}
static int F_17 ( void )
{
if ( V_19 -> V_45 & V_46 )
return 1 ;
return V_47 ;
}
static unsigned long F_18 ( void )
{
unsigned long V_48 = 0 ;
if ( V_19 -> V_16 & V_49 ) {
if ( F_19 () )
V_48 = F_20 () % ( 1 << 8 ) ;
else
V_48 = F_20 () % ( 1 << 28 ) ;
}
return V_48 << V_3 ;
}
static unsigned long V_35 ( void )
{
return V_50 + F_18 () ;
}
void F_21 ( struct V_17 * V_18 )
{
V_18 -> V_35 = V_35 () ;
V_18 -> V_44 = F_4 () ;
if ( F_17 () ) {
V_18 -> V_44 = V_18 -> V_35 ;
V_18 -> V_51 = F_7 ;
} else {
V_18 -> V_51 = F_12 ;
}
}
T_1 unsigned long F_22 ( unsigned long V_5 , unsigned long V_15 ,
unsigned long V_52 , unsigned long V_16 , unsigned long V_53 ,
unsigned long V_4 )
{
return F_23 ( V_5 , V_15 , V_52 , V_16 , V_53 ,
V_4 >> ( V_3 - 12 ) ) ;
}
T_1 unsigned long F_24 ( unsigned long V_5 , unsigned long V_15 ,
unsigned long V_52 , unsigned long V_16 , unsigned long V_53 ,
unsigned long V_54 )
{
if ( ! ( V_54 & ~ V_38 ) ) {
return F_23 ( V_5 , V_15 , V_52 , V_16 , V_53 ,
V_54 >> V_3 ) ;
} else {
return - V_30 ;
}
}
T_1 long F_25 ( const char T_2 * V_55 ,
unsigned int V_56 , unsigned int V_57 )
{
return F_26 ( V_55 , ( long ) V_56 << 32 | V_57 ) ;
}
T_1 long F_27 ( unsigned int V_53 ,
unsigned int V_56 , unsigned int V_57 )
{
return F_28 ( V_53 , ( long ) V_56 << 32 | V_57 ) ;
}
T_1 long F_29 ( const char T_2 * V_55 , unsigned long V_33 )
{
return F_26 ( V_55 , V_33 ) ;
}
T_1 long F_30 ( unsigned int V_53 , unsigned long V_33 )
{
return F_28 ( V_53 , V_33 ) ;
}
T_1 long F_31 ( unsigned int V_53 , unsigned int V_58 , unsigned long V_59 )
{
return F_32 ( V_53 , V_58 , V_59 ) ;
}
T_1 long F_25 ( const char T_2 * V_55 ,
unsigned int V_56 , unsigned int V_57 )
{
return F_29 ( V_55 , ( V_60 ) V_56 << 32 | V_57 ) ;
}
T_1 long F_27 ( unsigned int V_53 ,
unsigned int V_56 , unsigned int V_57 )
{
return F_30 ( V_53 , ( V_60 ) V_56 << 32 | V_57 ) ;
}
T_1 T_3 F_33 ( unsigned int V_53 , char T_2 * V_61 , T_4 V_62 ,
unsigned int V_56 , unsigned int V_57 )
{
return F_34 ( V_53 , V_61 , V_62 , ( V_60 ) V_56 << 32 | V_57 ) ;
}
T_1 T_3 F_35 ( unsigned int V_53 , const char T_2 * V_61 ,
T_4 V_62 , unsigned int V_56 , unsigned int V_57 )
{
return F_36 ( V_53 , V_61 , V_62 , ( V_60 ) V_56 << 32 | V_57 ) ;
}
T_1 T_3 F_37 ( int V_53 , unsigned int V_56 , unsigned int V_57 ,
T_4 V_62 )
{
return F_38 ( V_53 , ( V_60 ) V_56 << 32 | V_57 , V_62 ) ;
}
T_1 long F_39 ( int V_53 ,
unsigned int V_63 , unsigned int V_64 ,
unsigned int V_65 , unsigned int V_66 , int V_67 )
{
return F_40 ( V_53 , ( V_60 ) V_63 << 32 | V_64 ,
( V_60 ) V_65 << 32 | V_66 , V_67 ) ;
}
T_1 long F_41 ( int V_53 ,
T_5 V_68 , T_5 V_69 , T_5 V_70 , T_5 V_71 ,
unsigned int V_16 )
{
return F_42 ( V_53 , ( V_60 ) V_68 << 32 | V_69 ,
( V_60 ) V_70 << 32 | V_71 , V_16 ) ;
}
T_1 long F_43 ( int V_53 , int V_72 , T_5 V_73 , T_5 V_74 ,
T_5 V_75 , T_5 V_76 )
{
return F_44 ( V_53 , V_72 , ( ( V_77 ) V_73 << 32 ) | V_74 ,
( ( V_77 ) V_75 << 32 ) | V_76 ) ;
}
T_1 unsigned long F_45 ( int V_78 , unsigned long V_5 , unsigned long V_15 , int V_52 , int V_79 )
{
return - V_27 ;
}
T_1 int F_46 ( unsigned long V_5 )
{
return - V_30 ;
}
long F_47 ( unsigned long V_45 )
{
long V_80 ;
if ( V_45 ( V_19 -> V_45 ) == V_81
&& V_45 ( V_45 ) == V_82 )
V_45 = ( V_45 & ~ V_83 ) | V_81 ;
V_80 = F_48 ( V_45 ) ;
if ( V_45 ( V_80 ) == V_81 )
V_80 = ( V_80 & ~ V_83 ) | V_82 ;
return V_80 ;
}
