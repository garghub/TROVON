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
struct V_20 * V_21 , * V_22 ;
unsigned long V_23 = V_24 ;
int V_25 , V_1 ;
struct V_26 V_27 ;
if ( V_15 > V_23 )
return - V_28 ;
V_25 = 0 ;
if ( V_14 || ( V_16 & V_29 ) )
V_25 = 1 ;
V_1 = F_8 ( V_14 ) ;
if ( V_16 & V_30 ) {
if ( ( V_16 & V_29 ) && V_1 &&
( V_5 - F_2 ( V_1 , V_4 ) )
& ( V_2 - 1 ) )
return - V_31 ;
goto V_32;
}
if ( V_5 ) {
if ( V_25 && V_1 )
V_5 = F_3 ( V_5 , V_1 , V_4 ) ;
else
V_5 = F_6 ( V_5 ) ;
V_21 = F_9 ( V_18 , V_5 , & V_22 ) ;
if ( V_23 - V_15 >= V_5 &&
( ! V_21 || V_5 + V_15 <= F_10 ( V_21 ) ) &&
( ! V_22 || V_5 >= F_11 ( V_22 ) ) )
goto V_32;
}
V_27 . V_16 = 0 ;
V_27 . V_33 = V_15 ;
V_27 . V_34 = V_18 -> V_35 ;
V_27 . V_36 = F_4 () ;
V_27 . V_37 = V_1 ? ( V_38 & ( V_2 - 1 ) ) : 0 ;
V_27 . V_39 = F_2 ( V_1 , V_4 ) ;
V_5 = F_12 ( & V_27 ) ;
V_32:
if ( V_25 && ! V_1 && ! ( V_5 & ~ V_38 ) )
F_13 ( V_14 , V_5 - ( V_4 << V_3 ) ) ;
return V_5 ;
}
unsigned long
F_14 ( struct V_13 * V_14 , const unsigned long V_40 ,
const unsigned long V_15 , const unsigned long V_4 ,
const unsigned long V_16 )
{
struct V_20 * V_21 , * V_22 ;
struct V_17 * V_18 = V_19 -> V_18 ;
unsigned long V_5 = V_40 ;
int V_25 , V_1 ;
struct V_26 V_27 ;
#ifdef F_15
F_16 ( ! F_17 ( V_41 ) ) ;
#endif
if ( V_15 > V_24 )
return - V_28 ;
V_25 = 0 ;
if ( V_14 || ( V_16 & V_29 ) )
V_25 = 1 ;
V_1 = F_8 ( V_14 ) ;
if ( V_16 & V_30 ) {
if ( ( V_16 & V_29 ) && V_1 &&
( V_5 - F_2 ( V_1 , V_4 ) )
& ( V_2 - 1 ) )
return - V_31 ;
goto V_32;
}
if ( V_5 ) {
if ( V_25 && V_1 )
V_5 = F_3 ( V_5 , V_1 , V_4 ) ;
else
V_5 = F_6 ( V_5 ) ;
V_21 = F_9 ( V_18 , V_5 , & V_22 ) ;
if ( V_24 - V_15 >= V_5 &&
( ! V_21 || V_5 + V_15 <= F_10 ( V_21 ) ) &&
( ! V_22 || V_5 >= F_11 ( V_22 ) ) )
goto V_32;
}
V_27 . V_16 = V_42 ;
V_27 . V_33 = V_15 ;
V_27 . V_34 = V_43 ;
V_27 . V_36 = V_18 -> V_44 ;
V_27 . V_37 = V_1 ? ( V_38 & ( V_2 - 1 ) ) : 0 ;
V_27 . V_39 = F_2 ( V_1 , V_4 ) ;
V_5 = F_12 ( & V_27 ) ;
if ( ! ( V_5 & ~ V_38 ) )
goto V_32;
F_18 ( V_5 != - V_28 ) ;
return F_7 ( V_14 , V_40 , V_15 , V_4 , V_16 ) ;
V_32:
if ( V_25 && ! V_1 && ! ( V_5 & ~ V_38 ) )
F_13 ( V_14 , V_5 - ( V_4 << V_3 ) ) ;
return V_5 ;
}
static int F_19 ( void )
{
if ( V_19 -> V_45 & V_46 )
return 1 ;
return V_47 ;
}
static unsigned long F_20 ( void )
{
unsigned long V_48 = 0 ;
if ( V_19 -> V_16 & V_49 )
V_48 = F_21 () & V_50 ;
return V_48 << V_3 ;
}
unsigned long F_22 ( void )
{
return ( F_21 () & V_50 ) << V_3 ;
}
static unsigned long V_35 ( void )
{
return V_51 + F_20 () ;
}
void F_23 ( struct V_17 * V_18 )
{
V_18 -> V_35 = V_35 () ;
V_18 -> V_44 = F_4 () ;
if ( F_19 () ) {
V_18 -> V_44 = V_18 -> V_35 ;
V_18 -> V_52 = F_7 ;
} else {
V_18 -> V_52 = F_14 ;
}
}
T_1 unsigned long F_24 ( unsigned long V_5 , unsigned long V_15 ,
unsigned long V_53 , unsigned long V_16 , unsigned long V_54 ,
unsigned long V_4 )
{
return F_25 ( V_5 , V_15 , V_53 , V_16 , V_54 ,
V_4 >> ( V_3 - 12 ) ) ;
}
T_1 unsigned long F_26 ( unsigned long V_5 , unsigned long V_15 ,
unsigned long V_53 , unsigned long V_16 , unsigned long V_54 ,
unsigned long V_55 )
{
if ( ! ( V_55 & ~ V_38 ) ) {
return F_25 ( V_5 , V_15 , V_53 , V_16 , V_54 ,
V_55 >> V_3 ) ;
} else {
return - V_31 ;
}
}
T_1 long F_27 ( const char T_2 * V_56 ,
unsigned int V_57 , unsigned int V_58 )
{
return F_28 ( V_56 , ( long ) V_57 << 32 | V_58 ) ;
}
T_1 long F_29 ( unsigned int V_54 ,
unsigned int V_57 , unsigned int V_58 )
{
return F_30 ( V_54 , ( long ) V_57 << 32 | V_58 ) ;
}
T_1 long F_31 ( const char T_2 * V_56 , unsigned long V_33 )
{
return F_28 ( V_56 , V_33 ) ;
}
T_1 long F_32 ( unsigned int V_54 , unsigned long V_33 )
{
return F_30 ( V_54 , V_33 ) ;
}
T_1 long F_33 ( unsigned int V_54 , unsigned int V_59 , unsigned long V_60 )
{
return F_34 ( V_54 , V_59 , V_60 ) ;
}
T_1 long F_27 ( const char T_2 * V_56 ,
unsigned int V_57 , unsigned int V_58 )
{
return F_31 ( V_56 , ( V_61 ) V_57 << 32 | V_58 ) ;
}
T_1 long F_29 ( unsigned int V_54 ,
unsigned int V_57 , unsigned int V_58 )
{
return F_32 ( V_54 , ( V_61 ) V_57 << 32 | V_58 ) ;
}
T_1 T_3 F_35 ( unsigned int V_54 , char T_2 * V_62 , T_4 V_63 ,
unsigned int V_57 , unsigned int V_58 )
{
return F_36 ( V_54 , V_62 , V_63 , ( V_61 ) V_57 << 32 | V_58 ) ;
}
T_1 T_3 F_37 ( unsigned int V_54 , const char T_2 * V_62 ,
T_4 V_63 , unsigned int V_57 , unsigned int V_58 )
{
return F_38 ( V_54 , V_62 , V_63 , ( V_61 ) V_57 << 32 | V_58 ) ;
}
T_1 T_3 F_39 ( int V_54 , unsigned int V_57 , unsigned int V_58 ,
T_4 V_63 )
{
return F_40 ( V_54 , ( V_61 ) V_57 << 32 | V_58 , V_63 ) ;
}
T_1 long F_41 ( int V_54 ,
unsigned int V_64 , unsigned int V_65 ,
unsigned int V_66 , unsigned int V_67 , int V_68 )
{
return F_42 ( V_54 , ( V_61 ) V_64 << 32 | V_65 ,
( V_61 ) V_66 << 32 | V_67 , V_68 ) ;
}
T_1 long F_43 ( int V_54 ,
T_5 V_69 , T_5 V_70 , T_5 V_71 , T_5 V_72 ,
unsigned int V_16 )
{
return F_44 ( V_54 , ( V_61 ) V_69 << 32 | V_70 ,
( V_61 ) V_71 << 32 | V_72 , V_16 ) ;
}
T_1 long F_45 ( int V_54 , int V_73 , T_5 V_74 , T_5 V_75 ,
T_5 V_76 , T_5 V_77 )
{
return F_46 ( V_54 , V_73 , ( ( V_78 ) V_74 << 32 ) | V_75 ,
( ( V_78 ) V_76 << 32 ) | V_77 ) ;
}
long F_47 ( unsigned long V_45 )
{
long V_79 ;
if ( V_45 ( V_19 -> V_45 ) == V_80
&& V_45 ( V_45 ) == V_81 )
V_45 = ( V_45 & ~ V_82 ) | V_80 ;
V_79 = F_48 ( V_45 ) ;
if ( V_45 ( V_79 ) == V_80 )
V_79 = ( V_79 & ~ V_82 ) | V_81 ;
return V_79 ;
}
