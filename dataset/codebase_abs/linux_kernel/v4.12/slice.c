static void F_1 ( const char * V_1 , struct V_2 V_3 )
{
if ( ! V_4 )
return;
F_2 ( L_1 , V_1 , ( int ) V_5 , & V_3 . V_6 ) ;
F_2 ( L_2 , V_1 , ( int ) V_7 , V_3 . V_8 ) ;
}
static void F_1 ( const char * V_1 , struct V_2 V_3 ) {}
static void F_3 ( unsigned long V_9 , unsigned long V_10 ,
struct V_2 * V_11 )
{
unsigned long V_12 = V_9 + V_10 - 1 ;
V_11 -> V_6 = 0 ;
F_4 ( V_11 -> V_8 , V_7 ) ;
if ( V_9 < V_13 ) {
unsigned long V_14 = F_5 ( V_12 , ( V_13 - 1 ) ) ;
V_11 -> V_6 = ( 1u << ( F_6 ( V_14 ) + 1 ) )
- ( 1u << F_6 ( V_9 ) ) ;
}
if ( ( V_9 + V_10 ) > V_13 ) {
unsigned long V_15 = F_7 ( V_9 ) ;
unsigned long V_16 = F_8 ( V_12 , ( 1UL << V_17 ) ) ;
unsigned long V_18 = F_7 ( V_16 ) - V_15 ;
F_9 ( V_11 -> V_8 , V_15 , V_18 ) ;
}
}
static int F_10 ( struct V_19 * V_20 , unsigned long V_21 ,
unsigned long V_10 )
{
struct V_22 * V_23 ;
if ( ( V_20 -> V_24 - V_10 ) < V_21 )
return 0 ;
V_23 = F_11 ( V_20 , V_21 ) ;
return ( ! V_23 || ( V_21 + V_10 ) <= F_12 ( V_23 ) ) ;
}
static int F_13 ( struct V_19 * V_20 , unsigned long V_25 )
{
return ! F_10 ( V_20 , V_25 << V_26 ,
1ul << V_26 ) ;
}
static int F_14 ( struct V_19 * V_20 , unsigned long V_25 )
{
unsigned long V_9 = V_25 << V_17 ;
unsigned long V_12 = V_9 + ( 1ul << V_17 ) ;
if ( V_9 == 0 )
V_9 = V_13 ;
return ! F_10 ( V_20 , V_9 , V_12 - V_9 ) ;
}
static void F_15 ( struct V_19 * V_20 , struct V_2 * V_11 )
{
unsigned long V_27 ;
V_11 -> V_6 = 0 ;
F_4 ( V_11 -> V_8 , V_7 ) ;
for ( V_27 = 0 ; V_27 < V_5 ; V_27 ++ )
if ( ! F_13 ( V_20 , V_27 ) )
V_11 -> V_6 |= 1u << V_27 ;
if ( V_20 -> V_24 <= V_13 )
return;
for ( V_27 = 0 ; V_27 < F_7 ( V_20 -> V_28 . V_29 ) ; V_27 ++ )
if ( ! F_14 ( V_20 , V_27 ) )
F_16 ( V_27 , V_11 -> V_8 ) ;
}
static void F_17 ( struct V_19 * V_20 , int V_30 , struct V_2 * V_11 )
{
unsigned char * V_31 ;
int V_32 , V_33 ;
unsigned long V_27 ;
T_1 V_34 ;
V_11 -> V_6 = 0 ;
F_4 ( V_11 -> V_8 , V_7 ) ;
V_34 = V_20 -> V_28 . V_35 ;
for ( V_27 = 0 ; V_27 < V_5 ; V_27 ++ )
if ( ( ( V_34 >> ( V_27 * 4 ) ) & 0xf ) == V_30 )
V_11 -> V_6 |= 1u << V_27 ;
V_31 = V_20 -> V_28 . V_36 ;
for ( V_27 = 0 ; V_27 < F_7 ( V_20 -> V_28 . V_29 ) ; V_27 ++ ) {
V_33 = V_27 & 0x1 ;
V_32 = V_27 >> 1 ;
if ( ( ( V_31 [ V_32 ] >> ( V_33 * 4 ) ) & 0xf ) == V_30 )
F_16 ( V_27 , V_11 -> V_8 ) ;
}
}
static int F_18 ( struct V_19 * V_20 ,
struct V_2 V_3 , struct V_2 V_37 )
{
F_19 ( V_38 , V_7 ) ;
unsigned long V_39 = F_7 ( V_20 -> V_28 . V_29 ) ;
F_20 ( V_38 , V_3 . V_8 ,
V_37 . V_8 , V_39 ) ;
return ( V_3 . V_6 & V_37 . V_6 ) == V_3 . V_6 &&
F_21 ( V_38 , V_3 . V_8 , V_39 ) ;
}
static void F_22 ( void * V_40 )
{
struct V_19 * V_20 = V_40 ;
unsigned long V_41 ;
if ( V_20 != V_42 -> V_43 )
return;
F_23 ( V_42 -> V_43 ) ;
F_24 ( V_41 ) ;
F_25 () ;
F_26 ( V_41 ) ;
}
static void F_27 ( struct V_19 * V_20 , struct V_2 V_3 , int V_30 )
{
int V_32 , V_33 ;
unsigned char * V_31 ;
T_1 V_34 ;
unsigned long V_27 , V_41 ;
F_28 ( L_3 , V_20 , V_30 ) ;
F_1 ( L_4 , V_3 ) ;
F_29 ( & V_44 , V_41 ) ;
V_34 = V_20 -> V_28 . V_35 ;
for ( V_27 = 0 ; V_27 < V_5 ; V_27 ++ )
if ( V_3 . V_6 & ( 1u << V_27 ) )
V_34 = ( V_34 & ~ ( 0xful << ( V_27 * 4 ) ) ) |
( ( ( unsigned long ) V_30 ) << ( V_27 * 4 ) ) ;
V_20 -> V_28 . V_35 = V_34 ;
V_31 = V_20 -> V_28 . V_36 ;
for ( V_27 = 0 ; V_27 < F_7 ( V_20 -> V_28 . V_29 ) ; V_27 ++ ) {
V_33 = V_27 & 0x1 ;
V_32 = V_27 >> 1 ;
if ( F_30 ( V_27 , V_3 . V_8 ) )
V_31 [ V_32 ] = ( V_31 [ V_32 ] &
~ ( 0xf << ( V_33 * 4 ) ) ) |
( ( ( unsigned long ) V_30 ) << ( V_33 * 4 ) ) ;
}
F_28 ( L_5 ,
( unsigned long ) V_20 -> V_28 . V_35 ,
( unsigned long ) V_20 -> V_28 . V_36 ) ;
F_31 ( & V_44 , V_41 ) ;
F_32 ( V_20 ) ;
}
static bool F_33 ( unsigned long V_21 ,
struct V_2 V_37 ,
int V_12 ,
unsigned long * V_45 )
{
unsigned long V_25 ;
if ( V_21 < V_13 ) {
V_25 = F_6 ( V_21 ) ;
* V_45 = ( V_25 + V_12 ) << V_26 ;
return ! ! ( V_37 . V_6 & ( 1u << V_25 ) ) ;
} else {
V_25 = F_7 ( V_21 ) ;
* V_45 = ( V_25 + V_12 ) ?
( ( V_25 + V_12 ) << V_17 ) : V_13 ;
return ! ! F_30 ( V_25 , V_37 . V_8 ) ;
}
}
static unsigned long F_34 ( struct V_19 * V_20 ,
unsigned long V_10 ,
struct V_2 V_37 ,
int V_30 , unsigned long V_46 )
{
int V_47 = F_35 ( int , V_48 [ V_30 ] . V_49 , V_50 ) ;
unsigned long V_21 , V_51 , V_52 ;
struct V_53 V_54 ;
V_54 . V_41 = 0 ;
V_54 . V_55 = V_10 ;
V_54 . V_56 = V_57 & ( ( 1ul << V_47 ) - 1 ) ;
V_54 . V_58 = 0 ;
V_21 = V_59 ;
while ( V_21 < V_46 ) {
V_54 . V_60 = V_21 ;
if ( ! F_33 ( V_21 , V_37 , 1 , & V_21 ) )
continue;
V_61:
if ( V_21 >= V_46 )
V_21 = V_46 ;
else if ( F_33 ( V_21 , V_37 , 1 , & V_52 ) ) {
V_21 = V_52 ;
goto V_61;
}
V_54 . V_46 = V_21 ;
V_51 = F_36 ( & V_54 ) ;
if ( ! ( V_51 & ~ V_57 ) )
return V_51 ;
}
return - V_62 ;
}
static unsigned long F_37 ( struct V_19 * V_20 ,
unsigned long V_10 ,
struct V_2 V_37 ,
int V_30 , unsigned long V_46 )
{
int V_47 = F_35 ( int , V_48 [ V_30 ] . V_49 , V_50 ) ;
unsigned long V_21 , V_51 , V_63 ;
struct V_53 V_54 ;
V_54 . V_41 = V_64 ;
V_54 . V_55 = V_10 ;
V_54 . V_56 = V_57 & ( ( 1ul << V_47 ) - 1 ) ;
V_54 . V_58 = 0 ;
V_21 = V_20 -> V_65 ;
if ( V_46 > V_66 )
V_21 += V_20 -> V_28 . V_29 - V_66 ;
while ( V_21 > V_67 ) {
V_54 . V_46 = V_21 ;
if ( ! F_33 ( V_21 - 1 , V_37 , 0 , & V_21 ) )
continue;
V_68:
if ( V_21 < V_67 )
V_21 = V_67 ;
else if ( F_33 ( V_21 - 1 , V_37 , 0 , & V_63 ) ) {
V_21 = V_63 ;
goto V_68;
}
V_54 . V_60 = V_21 ;
V_51 = F_36 ( & V_54 ) ;
if ( ! ( V_51 & ~ V_57 ) )
return V_51 ;
}
return F_34 ( V_20 , V_10 , V_37 , V_30 , V_46 ) ;
}
static unsigned long F_38 ( struct V_19 * V_20 , unsigned long V_10 ,
struct V_2 V_3 , int V_30 ,
int V_69 , unsigned long V_46 )
{
if ( V_69 )
return F_37 ( V_20 , V_10 , V_3 , V_30 , V_46 ) ;
else
return F_34 ( V_20 , V_10 , V_3 , V_30 , V_46 ) ;
}
static inline void F_39 ( struct V_2 * V_70 , struct V_2 * V_71 )
{
F_19 ( V_38 , V_7 ) ;
V_70 -> V_6 |= V_71 -> V_6 ;
F_40 ( V_38 , V_70 -> V_8 , V_71 -> V_8 , V_7 ) ;
F_41 ( V_70 -> V_8 , V_38 , V_7 ) ;
}
static inline void F_42 ( struct V_2 * V_70 , struct V_2 * V_71 )
{
F_19 ( V_38 , V_7 ) ;
V_70 -> V_6 &= ~ V_71 -> V_6 ;
F_43 ( V_38 , V_70 -> V_8 , V_71 -> V_8 , V_7 ) ;
F_41 ( V_70 -> V_8 , V_38 , V_7 ) ;
}
unsigned long F_44 ( unsigned long V_21 , unsigned long V_10 ,
unsigned long V_41 , unsigned int V_30 ,
int V_69 )
{
struct V_2 V_3 ;
struct V_2 V_72 ;
struct V_2 V_73 ;
struct V_2 V_74 ;
int V_75 = ( V_41 & V_76 ) ;
int V_47 = F_35 ( int , V_48 [ V_30 ] . V_49 , V_50 ) ;
struct V_19 * V_20 = V_42 -> V_20 ;
unsigned long V_77 ;
unsigned long V_46 ;
if ( F_45 ( V_21 > V_20 -> V_28 . V_29 &&
V_20 -> V_28 . V_29 != V_78 ) ) {
V_20 -> V_28 . V_29 = V_78 ;
F_46 ( F_22 , V_20 , 1 ) ;
}
if ( V_21 > V_66 )
V_46 = V_20 -> V_28 . V_29 ;
else
V_46 = V_66 ;
V_3 . V_6 = 0 ;
F_4 ( V_3 . V_8 , V_7 ) ;
;
V_73 . V_6 = 0 ;
F_4 ( V_73 . V_8 , V_7 ) ;
V_74 . V_6 = 0 ;
F_4 ( V_74 . V_8 , V_7 ) ;
F_47 ( V_20 -> V_24 == 0 ) ;
F_48 ( F_49 () ) ;
F_28 ( L_6 , V_20 , V_30 ) ;
F_28 ( L_7 ,
V_21 , V_10 , V_41 , V_69 ) ;
if ( V_10 > V_20 -> V_24 )
return - V_62 ;
if ( V_10 & ( ( 1ul << V_47 ) - 1 ) )
return - V_79 ;
if ( V_75 && ( V_21 & ( ( 1ul << V_47 ) - 1 ) ) )
return - V_79 ;
if ( V_75 && V_21 > ( V_20 -> V_24 - V_10 ) )
return - V_62 ;
if ( ! V_75 && V_21 ) {
V_21 = F_50 ( V_21 , 1ul << V_47 ) ;
F_28 ( L_8 , V_21 ) ;
if ( V_21 > V_20 -> V_24 - V_10 ||
! F_10 ( V_20 , V_21 , V_10 ) )
V_21 = 0 ;
}
F_17 ( V_20 , V_30 , & V_72 ) ;
F_1 ( L_9 , V_72 ) ;
#ifdef F_51
if ( V_30 == V_80 ) {
F_17 ( V_20 , V_81 , & V_74 ) ;
if ( V_75 )
F_39 ( & V_72 , & V_74 ) ;
}
#endif
if ( V_21 != 0 || V_75 ) {
F_3 ( V_21 , V_10 , & V_3 ) ;
F_1 ( L_4 , V_3 ) ;
if ( F_18 ( V_20 , V_3 , V_72 ) ) {
F_28 ( L_10 ) ;
return V_21 ;
}
} else {
V_77 = F_38 ( V_20 , V_10 , V_72 ,
V_30 , V_69 , V_46 ) ;
if ( V_77 != - V_62 ) {
F_28 ( L_11 , V_77 ) ;
return V_77 ;
}
}
F_15 ( V_20 , & V_73 ) ;
F_39 ( & V_73 , & V_72 ) ;
F_1 ( L_12 , V_73 ) ;
if ( ( V_21 != 0 || V_75 ) && F_18 ( V_20 , V_3 , V_73 ) ) {
F_28 ( L_13 ) ;
goto V_82;
}
if ( V_75 )
return - V_83 ;
F_28 ( L_14 ) ;
if ( V_21 ) {
V_21 = F_38 ( V_20 , V_10 , V_72 ,
V_30 , V_69 , V_46 ) ;
if ( V_21 != - V_62 ) {
F_28 ( L_11 , V_21 ) ;
return V_21 ;
}
}
V_21 = F_38 ( V_20 , V_10 , V_73 ,
V_30 , V_69 , V_46 ) ;
#ifdef F_51
if ( V_21 == - V_62 && V_30 == V_80 ) {
F_39 ( & V_73 , & V_74 ) ;
V_21 = F_38 ( V_20 , V_10 , V_73 ,
V_30 , V_69 , V_46 ) ;
}
#endif
if ( V_21 == - V_62 )
return - V_62 ;
F_3 ( V_21 , V_10 , & V_3 ) ;
F_28 ( L_15 , V_21 ) ;
F_1 ( L_4 , V_3 ) ;
V_82:
F_42 ( & V_3 , & V_72 ) ;
F_42 ( & V_3 , & V_74 ) ;
if ( V_3 . V_6 || ! F_52 ( V_3 . V_8 , V_7 ) ) {
F_27 ( V_20 , V_3 , V_30 ) ;
if ( V_30 > V_84 )
F_46 ( F_22 , V_20 , 1 ) ;
}
return V_21 ;
}
unsigned long F_53 ( struct V_85 * V_86 ,
unsigned long V_21 ,
unsigned long V_10 ,
unsigned long V_87 ,
unsigned long V_41 )
{
return F_44 ( V_21 , V_10 , V_41 ,
V_42 -> V_20 -> V_28 . V_88 , 0 ) ;
}
unsigned long F_54 ( struct V_85 * V_86 ,
const unsigned long V_89 ,
const unsigned long V_10 ,
const unsigned long V_87 ,
const unsigned long V_41 )
{
return F_44 ( V_89 , V_10 , V_41 ,
V_42 -> V_20 -> V_28 . V_88 , 1 ) ;
}
unsigned int F_55 ( struct V_19 * V_20 , unsigned long V_21 )
{
unsigned char * V_31 ;
int V_32 , V_33 ;
if ( F_49 () ) {
#ifdef F_51
return V_80 ;
#else
return V_81 ;
#endif
}
if ( V_21 < V_13 ) {
T_1 V_34 ;
V_34 = V_20 -> V_28 . V_35 ;
V_32 = F_6 ( V_21 ) ;
return ( V_34 >> ( V_32 * 4 ) ) & 0xf ;
}
V_31 = V_20 -> V_28 . V_36 ;
V_32 = F_7 ( V_21 ) ;
V_33 = V_32 & 0x1 ;
return ( V_31 [ V_32 >> 1 ] >> ( V_33 * 4 ) ) & 0xf ;
}
void F_56 ( struct V_19 * V_20 , unsigned int V_30 )
{
int V_32 , V_33 ;
unsigned char * V_31 ;
unsigned long V_41 , V_34 ;
unsigned int V_90 ;
int V_27 ;
F_28 ( L_16 , V_20 , V_30 ) ;
F_48 ( F_49 () ) ;
F_29 ( & V_44 , V_41 ) ;
V_90 = V_20 -> V_28 . V_88 ;
F_28 ( L_17 , V_90 ) ;
if ( V_90 == V_30 )
goto V_91;
V_20 -> V_28 . V_88 = V_30 ;
F_57 () ;
V_34 = V_20 -> V_28 . V_35 ;
for ( V_27 = 0 ; V_27 < V_5 ; V_27 ++ )
if ( ( ( V_34 >> ( V_27 * 4 ) ) & 0xf ) == V_90 )
V_34 = ( V_34 & ~ ( 0xful << ( V_27 * 4 ) ) ) |
( ( ( unsigned long ) V_30 ) << ( V_27 * 4 ) ) ;
V_20 -> V_28 . V_35 = V_34 ;
V_31 = V_20 -> V_28 . V_36 ;
for ( V_27 = 0 ; V_27 < V_7 ; V_27 ++ ) {
V_33 = V_27 & 0x1 ;
V_32 = V_27 >> 1 ;
if ( ( ( V_31 [ V_32 ] >> ( V_33 * 4 ) ) & 0xf ) == V_90 )
V_31 [ V_32 ] = ( V_31 [ V_32 ] &
~ ( 0xf << ( V_33 * 4 ) ) ) |
( ( ( unsigned long ) V_30 ) << ( V_33 * 4 ) ) ;
}
F_28 ( L_5 ,
( unsigned long ) V_20 -> V_28 . V_35 ,
( unsigned long ) V_20 -> V_28 . V_36 ) ;
V_91:
F_31 ( & V_44 , V_41 ) ;
}
void F_58 ( struct V_19 * V_20 , unsigned long V_9 ,
unsigned long V_10 , unsigned int V_30 )
{
struct V_2 V_3 ;
F_48 ( F_49 () ) ;
F_3 ( V_9 , V_10 , & V_3 ) ;
F_27 ( V_20 , V_3 , V_30 ) ;
}
int F_59 ( struct V_19 * V_20 , unsigned long V_21 ,
unsigned long V_10 )
{
struct V_2 V_3 , V_37 ;
unsigned int V_30 = V_20 -> V_28 . V_88 ;
if ( F_49 () )
return 0 ;
F_3 ( V_21 , V_10 , & V_3 ) ;
F_17 ( V_20 , V_30 , & V_37 ) ;
#ifdef F_51
if ( V_30 == V_80 ) {
struct V_2 V_74 ;
F_17 ( V_20 , V_81 , & V_74 ) ;
F_39 ( & V_37 , & V_74 ) ;
}
#endif
#if 0
slice_dbg("is_hugepage_only_range(mm=%p, addr=%lx, len=%lx)\n",
mm, addr, len);
slice_print_mask(" mask", mask);
slice_print_mask(" available", available);
#endif
return ! F_18 ( V_20 , V_3 , V_37 ) ;
}
