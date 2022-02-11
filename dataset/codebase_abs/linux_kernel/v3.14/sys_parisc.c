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
if ( V_8 > ( 1 << 30 ) )
V_8 = 1 << 30 ;
return F_6 ( V_10 - V_8 ) ;
}
unsigned long F_7 ( struct V_11 * V_12 , unsigned long V_5 ,
unsigned long V_13 , unsigned long V_4 , unsigned long V_14 )
{
struct V_15 * V_16 = V_17 -> V_16 ;
struct V_18 * V_19 ;
unsigned long V_20 = V_21 ;
int V_22 , V_1 ;
struct V_23 V_24 ;
if ( V_13 > V_20 )
return - V_25 ;
V_22 = 0 ;
if ( V_12 || ( V_14 & V_26 ) )
V_22 = 1 ;
V_1 = F_8 ( V_12 ) ;
if ( V_14 & V_27 ) {
if ( ( V_14 & V_26 ) && V_1 &&
( V_5 - F_2 ( V_1 , V_4 ) )
& ( V_2 - 1 ) )
return - V_28 ;
goto V_29;
}
if ( V_5 ) {
if ( V_22 && V_1 )
V_5 = F_3 ( V_5 , V_1 , V_4 ) ;
else
V_5 = F_6 ( V_5 ) ;
V_19 = F_9 ( V_16 , V_5 ) ;
if ( V_20 - V_13 >= V_5 &&
( ! V_19 || V_5 + V_13 <= V_19 -> V_30 ) )
goto V_29;
}
V_24 . V_14 = 0 ;
V_24 . V_31 = V_13 ;
V_24 . V_32 = V_16 -> V_33 ;
V_24 . V_34 = F_4 () ;
V_24 . V_35 = V_1 ? ( V_36 & ( V_2 - 1 ) ) : 0 ;
V_24 . V_37 = F_2 ( V_1 , V_4 ) ;
V_5 = F_10 ( & V_24 ) ;
V_29:
if ( V_22 && ! V_1 && ! ( V_5 & ~ V_36 ) )
F_11 ( V_12 , V_5 - ( V_4 << V_3 ) ) ;
return V_5 ;
}
unsigned long
F_12 ( struct V_11 * V_12 , const unsigned long V_38 ,
const unsigned long V_13 , const unsigned long V_4 ,
const unsigned long V_14 )
{
struct V_18 * V_19 ;
struct V_15 * V_16 = V_17 -> V_16 ;
unsigned long V_5 = V_38 ;
int V_22 , V_1 ;
struct V_23 V_24 ;
#ifdef F_13
F_14 ( ! F_15 ( V_39 ) ) ;
#endif
if ( V_13 > V_21 )
return - V_25 ;
V_22 = 0 ;
if ( V_12 || ( V_14 & V_26 ) )
V_22 = 1 ;
V_1 = F_8 ( V_12 ) ;
if ( V_14 & V_27 ) {
if ( ( V_14 & V_26 ) && V_1 &&
( V_5 - F_2 ( V_1 , V_4 ) )
& ( V_2 - 1 ) )
return - V_28 ;
goto V_29;
}
if ( V_5 ) {
if ( V_22 && V_1 )
V_5 = F_3 ( V_5 , V_1 , V_4 ) ;
else
V_5 = F_6 ( V_5 ) ;
V_19 = F_9 ( V_16 , V_5 ) ;
if ( V_21 - V_13 >= V_5 &&
( ! V_19 || V_5 + V_13 <= V_19 -> V_30 ) )
goto V_29;
}
V_24 . V_14 = V_40 ;
V_24 . V_31 = V_13 ;
V_24 . V_32 = V_41 ;
V_24 . V_34 = V_16 -> V_42 ;
V_24 . V_35 = V_1 ? ( V_36 & ( V_2 - 1 ) ) : 0 ;
V_24 . V_37 = F_2 ( V_1 , V_4 ) ;
V_5 = F_10 ( & V_24 ) ;
if ( ! ( V_5 & ~ V_36 ) )
goto V_29;
F_16 ( V_5 != - V_25 ) ;
return F_7 ( V_12 , V_38 , V_13 , V_4 , V_14 ) ;
V_29:
if ( V_22 && ! V_1 && ! ( V_5 & ~ V_36 ) )
F_11 ( V_12 , V_5 - ( V_4 << V_3 ) ) ;
return V_5 ;
}
static int F_17 ( void )
{
if ( V_17 -> V_43 & V_44 )
return 1 ;
return V_45 ;
}
static unsigned long F_18 ( void )
{
unsigned long V_46 = 0 ;
if ( V_17 -> V_14 & V_47 ) {
if ( F_19 () )
V_46 = F_20 () % ( 1 << 8 ) ;
else
V_46 = F_20 () % ( 1 << 28 ) ;
}
return V_46 << V_3 ;
}
static unsigned long V_33 ( void )
{
return V_48 + F_18 () ;
}
void F_21 ( struct V_15 * V_16 )
{
V_16 -> V_33 = V_33 () ;
V_16 -> V_42 = F_4 () ;
if ( F_17 () ) {
V_16 -> V_42 = V_16 -> V_33 ;
V_16 -> V_49 = F_7 ;
} else {
V_16 -> V_49 = F_12 ;
}
}
T_1 unsigned long F_22 ( unsigned long V_5 , unsigned long V_13 ,
unsigned long V_50 , unsigned long V_14 , unsigned long V_51 ,
unsigned long V_4 )
{
return F_23 ( V_5 , V_13 , V_50 , V_14 , V_51 ,
V_4 >> ( V_3 - 12 ) ) ;
}
T_1 unsigned long F_24 ( unsigned long V_5 , unsigned long V_13 ,
unsigned long V_50 , unsigned long V_14 , unsigned long V_51 ,
unsigned long V_52 )
{
if ( ! ( V_52 & ~ V_36 ) ) {
return F_23 ( V_5 , V_13 , V_50 , V_14 , V_51 ,
V_52 >> V_3 ) ;
} else {
return - V_28 ;
}
}
T_1 long F_25 ( const char T_2 * V_53 ,
unsigned int V_54 , unsigned int V_55 )
{
return F_26 ( V_53 , ( long ) V_54 << 32 | V_55 ) ;
}
T_1 long F_27 ( unsigned int V_51 ,
unsigned int V_54 , unsigned int V_55 )
{
return F_28 ( V_51 , ( long ) V_54 << 32 | V_55 ) ;
}
T_1 long F_29 ( const char T_2 * V_53 , unsigned long V_31 )
{
return F_26 ( V_53 , V_31 ) ;
}
T_1 long F_30 ( unsigned int V_51 , unsigned long V_31 )
{
return F_28 ( V_51 , V_31 ) ;
}
T_1 long F_31 ( unsigned int V_51 , unsigned int V_56 , unsigned long V_57 )
{
return F_32 ( V_51 , V_56 , V_57 ) ;
}
T_1 long F_25 ( const char T_2 * V_53 ,
unsigned int V_54 , unsigned int V_55 )
{
return F_29 ( V_53 , ( V_58 ) V_54 << 32 | V_55 ) ;
}
T_1 long F_27 ( unsigned int V_51 ,
unsigned int V_54 , unsigned int V_55 )
{
return F_30 ( V_51 , ( V_58 ) V_54 << 32 | V_55 ) ;
}
T_1 T_3 F_33 ( unsigned int V_51 , char T_2 * V_59 , T_4 V_60 ,
unsigned int V_54 , unsigned int V_55 )
{
return F_34 ( V_51 , V_59 , V_60 , ( V_58 ) V_54 << 32 | V_55 ) ;
}
T_1 T_3 F_35 ( unsigned int V_51 , const char T_2 * V_59 ,
T_4 V_60 , unsigned int V_54 , unsigned int V_55 )
{
return F_36 ( V_51 , V_59 , V_60 , ( V_58 ) V_54 << 32 | V_55 ) ;
}
T_1 T_3 F_37 ( int V_51 , unsigned int V_54 , unsigned int V_55 ,
T_4 V_60 )
{
return F_38 ( V_51 , ( V_58 ) V_54 << 32 | V_55 , V_60 ) ;
}
T_1 long F_39 ( int V_51 ,
unsigned int V_61 , unsigned int V_62 ,
unsigned int V_63 , unsigned int V_64 , int V_65 )
{
return F_40 ( V_51 , ( V_58 ) V_61 << 32 | V_62 ,
( V_58 ) V_63 << 32 | V_64 , V_65 ) ;
}
T_1 long F_41 ( int V_51 ,
T_5 V_66 , T_5 V_67 , T_5 V_68 , T_5 V_69 ,
unsigned int V_14 )
{
return F_42 ( V_51 , ( V_58 ) V_66 << 32 | V_67 ,
( V_58 ) V_68 << 32 | V_69 , V_14 ) ;
}
T_1 long F_43 ( int V_51 , int V_70 , T_5 V_71 , T_5 V_72 ,
T_5 V_73 , T_5 V_74 )
{
return F_44 ( V_51 , V_70 , ( ( V_75 ) V_71 << 32 ) | V_72 ,
( ( V_75 ) V_73 << 32 ) | V_74 ) ;
}
T_1 unsigned long F_45 ( int V_76 , unsigned long V_5 , unsigned long V_13 , int V_50 , int V_77 )
{
return - V_25 ;
}
T_1 int F_46 ( unsigned long V_5 )
{
return - V_28 ;
}
long F_47 ( unsigned long V_43 )
{
long V_78 ;
if ( V_43 ( V_17 -> V_43 ) == V_79
&& V_43 ( V_43 ) == V_80 )
V_43 = ( V_43 & ~ V_81 ) | V_79 ;
V_78 = F_48 ( V_43 ) ;
if ( V_43 ( V_78 ) == V_79 )
V_78 = ( V_78 & ~ V_81 ) | V_80 ;
return V_78 ;
}
