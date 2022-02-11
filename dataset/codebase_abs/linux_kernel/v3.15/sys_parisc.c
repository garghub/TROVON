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
return F_6 ( V_11 - V_8 ) ;
}
unsigned long F_7 ( struct V_12 * V_13 , unsigned long V_5 ,
unsigned long V_14 , unsigned long V_4 , unsigned long V_15 )
{
struct V_16 * V_17 = V_18 -> V_17 ;
struct V_19 * V_20 ;
unsigned long V_21 = V_22 ;
int V_23 , V_1 ;
struct V_24 V_25 ;
if ( V_14 > V_21 )
return - V_26 ;
V_23 = 0 ;
if ( V_13 || ( V_15 & V_27 ) )
V_23 = 1 ;
V_1 = F_8 ( V_13 ) ;
if ( V_15 & V_28 ) {
if ( ( V_15 & V_27 ) && V_1 &&
( V_5 - F_2 ( V_1 , V_4 ) )
& ( V_2 - 1 ) )
return - V_29 ;
goto V_30;
}
if ( V_5 ) {
if ( V_23 && V_1 )
V_5 = F_3 ( V_5 , V_1 , V_4 ) ;
else
V_5 = F_6 ( V_5 ) ;
V_20 = F_9 ( V_17 , V_5 ) ;
if ( V_21 - V_14 >= V_5 &&
( ! V_20 || V_5 + V_14 <= V_20 -> V_31 ) )
goto V_30;
}
V_25 . V_15 = 0 ;
V_25 . V_32 = V_14 ;
V_25 . V_33 = V_17 -> V_34 ;
V_25 . V_35 = F_4 () ;
V_25 . V_36 = V_1 ? ( V_37 & ( V_2 - 1 ) ) : 0 ;
V_25 . V_38 = F_2 ( V_1 , V_4 ) ;
V_5 = F_10 ( & V_25 ) ;
V_30:
if ( V_23 && ! V_1 && ! ( V_5 & ~ V_37 ) )
F_11 ( V_13 , V_5 - ( V_4 << V_3 ) ) ;
return V_5 ;
}
unsigned long
F_12 ( struct V_12 * V_13 , const unsigned long V_39 ,
const unsigned long V_14 , const unsigned long V_4 ,
const unsigned long V_15 )
{
struct V_19 * V_20 ;
struct V_16 * V_17 = V_18 -> V_17 ;
unsigned long V_5 = V_39 ;
int V_23 , V_1 ;
struct V_24 V_25 ;
#ifdef F_13
F_14 ( ! F_15 ( V_40 ) ) ;
#endif
if ( V_14 > V_22 )
return - V_26 ;
V_23 = 0 ;
if ( V_13 || ( V_15 & V_27 ) )
V_23 = 1 ;
V_1 = F_8 ( V_13 ) ;
if ( V_15 & V_28 ) {
if ( ( V_15 & V_27 ) && V_1 &&
( V_5 - F_2 ( V_1 , V_4 ) )
& ( V_2 - 1 ) )
return - V_29 ;
goto V_30;
}
if ( V_5 ) {
if ( V_23 && V_1 )
V_5 = F_3 ( V_5 , V_1 , V_4 ) ;
else
V_5 = F_6 ( V_5 ) ;
V_20 = F_9 ( V_17 , V_5 ) ;
if ( V_22 - V_14 >= V_5 &&
( ! V_20 || V_5 + V_14 <= V_20 -> V_31 ) )
goto V_30;
}
V_25 . V_15 = V_41 ;
V_25 . V_32 = V_14 ;
V_25 . V_33 = V_42 ;
V_25 . V_35 = V_17 -> V_43 ;
V_25 . V_36 = V_1 ? ( V_37 & ( V_2 - 1 ) ) : 0 ;
V_25 . V_38 = F_2 ( V_1 , V_4 ) ;
V_5 = F_10 ( & V_25 ) ;
if ( ! ( V_5 & ~ V_37 ) )
goto V_30;
F_16 ( V_5 != - V_26 ) ;
return F_7 ( V_13 , V_39 , V_14 , V_4 , V_15 ) ;
V_30:
if ( V_23 && ! V_1 && ! ( V_5 & ~ V_37 ) )
F_11 ( V_13 , V_5 - ( V_4 << V_3 ) ) ;
return V_5 ;
}
static int F_17 ( void )
{
if ( V_18 -> V_44 & V_45 )
return 1 ;
return V_46 ;
}
static unsigned long F_18 ( void )
{
unsigned long V_47 = 0 ;
if ( V_18 -> V_15 & V_48 ) {
if ( F_19 () )
V_47 = F_20 () % ( 1 << 8 ) ;
else
V_47 = F_20 () % ( 1 << 28 ) ;
}
return V_47 << V_3 ;
}
static unsigned long V_34 ( void )
{
return V_49 + F_18 () ;
}
void F_21 ( struct V_16 * V_17 )
{
V_17 -> V_34 = V_34 () ;
V_17 -> V_43 = F_4 () ;
if ( F_17 () ) {
V_17 -> V_43 = V_17 -> V_34 ;
V_17 -> V_50 = F_7 ;
} else {
V_17 -> V_50 = F_12 ;
}
}
T_1 unsigned long F_22 ( unsigned long V_5 , unsigned long V_14 ,
unsigned long V_51 , unsigned long V_15 , unsigned long V_52 ,
unsigned long V_4 )
{
return F_23 ( V_5 , V_14 , V_51 , V_15 , V_52 ,
V_4 >> ( V_3 - 12 ) ) ;
}
T_1 unsigned long F_24 ( unsigned long V_5 , unsigned long V_14 ,
unsigned long V_51 , unsigned long V_15 , unsigned long V_52 ,
unsigned long V_53 )
{
if ( ! ( V_53 & ~ V_37 ) ) {
return F_23 ( V_5 , V_14 , V_51 , V_15 , V_52 ,
V_53 >> V_3 ) ;
} else {
return - V_29 ;
}
}
T_1 long F_25 ( const char T_2 * V_54 ,
unsigned int V_55 , unsigned int V_56 )
{
return F_26 ( V_54 , ( long ) V_55 << 32 | V_56 ) ;
}
T_1 long F_27 ( unsigned int V_52 ,
unsigned int V_55 , unsigned int V_56 )
{
return F_28 ( V_52 , ( long ) V_55 << 32 | V_56 ) ;
}
T_1 long F_29 ( const char T_2 * V_54 , unsigned long V_32 )
{
return F_26 ( V_54 , V_32 ) ;
}
T_1 long F_30 ( unsigned int V_52 , unsigned long V_32 )
{
return F_28 ( V_52 , V_32 ) ;
}
T_1 long F_31 ( unsigned int V_52 , unsigned int V_57 , unsigned long V_58 )
{
return F_32 ( V_52 , V_57 , V_58 ) ;
}
T_1 long F_25 ( const char T_2 * V_54 ,
unsigned int V_55 , unsigned int V_56 )
{
return F_29 ( V_54 , ( V_59 ) V_55 << 32 | V_56 ) ;
}
T_1 long F_27 ( unsigned int V_52 ,
unsigned int V_55 , unsigned int V_56 )
{
return F_30 ( V_52 , ( V_59 ) V_55 << 32 | V_56 ) ;
}
T_1 T_3 F_33 ( unsigned int V_52 , char T_2 * V_60 , T_4 V_61 ,
unsigned int V_55 , unsigned int V_56 )
{
return F_34 ( V_52 , V_60 , V_61 , ( V_59 ) V_55 << 32 | V_56 ) ;
}
T_1 T_3 F_35 ( unsigned int V_52 , const char T_2 * V_60 ,
T_4 V_61 , unsigned int V_55 , unsigned int V_56 )
{
return F_36 ( V_52 , V_60 , V_61 , ( V_59 ) V_55 << 32 | V_56 ) ;
}
T_1 T_3 F_37 ( int V_52 , unsigned int V_55 , unsigned int V_56 ,
T_4 V_61 )
{
return F_38 ( V_52 , ( V_59 ) V_55 << 32 | V_56 , V_61 ) ;
}
T_1 long F_39 ( int V_52 ,
unsigned int V_62 , unsigned int V_63 ,
unsigned int V_64 , unsigned int V_65 , int V_66 )
{
return F_40 ( V_52 , ( V_59 ) V_62 << 32 | V_63 ,
( V_59 ) V_64 << 32 | V_65 , V_66 ) ;
}
T_1 long F_41 ( int V_52 ,
T_5 V_67 , T_5 V_68 , T_5 V_69 , T_5 V_70 ,
unsigned int V_15 )
{
return F_42 ( V_52 , ( V_59 ) V_67 << 32 | V_68 ,
( V_59 ) V_69 << 32 | V_70 , V_15 ) ;
}
T_1 long F_43 ( int V_52 , int V_71 , T_5 V_72 , T_5 V_73 ,
T_5 V_74 , T_5 V_75 )
{
return F_44 ( V_52 , V_71 , ( ( V_76 ) V_72 << 32 ) | V_73 ,
( ( V_76 ) V_74 << 32 ) | V_75 ) ;
}
T_1 unsigned long F_45 ( int V_77 , unsigned long V_5 , unsigned long V_14 , int V_51 , int V_78 )
{
return - V_26 ;
}
T_1 int F_46 ( unsigned long V_5 )
{
return - V_29 ;
}
long F_47 ( unsigned long V_44 )
{
long V_79 ;
if ( V_44 ( V_18 -> V_44 ) == V_80
&& V_44 ( V_44 ) == V_81 )
V_44 = ( V_44 & ~ V_82 ) | V_80 ;
V_79 = F_48 ( V_44 ) ;
if ( V_44 ( V_79 ) == V_80 )
V_79 = ( V_79 & ~ V_82 ) | V_81 ;
return V_79 ;
}
