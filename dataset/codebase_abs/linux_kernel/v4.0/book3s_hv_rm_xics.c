static inline void F_1 ( unsigned long V_1 , T_1 V_2 )
{
__asm__ __volatile__("sync; stbcix %0,0,%1"
: : "r" (val), "r" (paddr) : "memory");
}
static void F_2 ( struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 . V_9 ;
unsigned long V_10 ;
int V_11 ;
V_4 -> V_12 . V_13 ++ ;
F_3 ( V_14 , & V_4 -> V_8 . V_15 ) ;
if ( V_4 == V_5 ) {
F_4 ( V_16 , F_5 ( V_16 ) | V_17 ) ;
return;
}
V_11 = V_4 -> V_11 ;
if ( V_11 < 0 || V_11 >= V_18 ) {
V_7 -> V_19 |= V_20 ;
V_7 -> V_21 = V_4 ;
return;
}
V_11 += V_4 -> V_8 . V_22 ;
V_10 = V_23 [ V_11 ] . V_24 . V_10 ;
F_1 ( V_10 + V_25 , V_26 ) ;
}
static void F_6 ( struct V_3 * V_4 )
{
F_7 ( V_14 ,
& V_4 -> V_8 . V_15 ) ;
F_4 ( V_16 , F_5 ( V_16 ) & ~ V_17 ) ;
}
static inline bool F_8 ( struct V_6 * V_9 ,
union V_27 V_28 ,
union V_27 V_29 )
{
struct V_3 * V_5 = V_30 -> V_24 . V_3 ;
bool V_31 ;
V_29 . V_32 = ( V_29 . V_33 && ( V_29 . V_34 < V_29 . V_35 ) ) ;
V_31 = F_9 ( & V_9 -> V_36 . V_37 , V_28 . V_37 , V_29 . V_37 ) == V_28 . V_37 ;
if ( ! V_31 )
goto V_38;
if ( V_29 . V_32 )
F_2 ( V_9 -> V_4 , V_5 ) ;
V_5 -> V_8 . V_9 -> V_39 = V_29 ;
V_5 -> V_8 . V_9 -> V_40 = V_9 -> V_4 ;
V_38:
return V_31 ;
}
static inline int F_10 ( struct V_41 * V_42 ,
struct V_6 * V_9 )
{
return ( V_42 -> V_43 || V_9 -> V_19 ) ? V_44 : V_45 ;
}
static void F_11 ( struct V_41 * V_42 , struct V_6 * V_9 ,
T_1 V_46 )
{
union V_27 V_47 , V_48 ;
bool V_49 ;
do {
V_47 = V_48 = F_12 ( V_9 -> V_36 ) ;
V_48 . V_35 = V_46 ;
if ( V_48 . V_50 < V_46 &&
V_48 . V_50 <= V_48 . V_34 ) {
V_48 . V_34 = V_48 . V_50 ;
V_48 . V_33 = V_51 ;
}
V_49 = V_48 . V_52 ;
V_48 . V_52 = 0 ;
} while ( ! F_8 ( V_9 , V_47 , V_48 ) );
if ( V_49 ) {
V_9 -> V_19 |= V_53 ;
V_9 -> V_54 = V_9 ;
}
}
unsigned long F_13 ( struct V_3 * V_4 )
{
union V_27 V_47 , V_48 ;
struct V_41 * V_42 = V_4 -> V_55 -> V_8 . V_42 ;
struct V_6 * V_9 = V_4 -> V_8 . V_9 ;
T_2 V_56 ;
if ( ! V_42 || ! V_42 -> V_57 )
return V_44 ;
F_6 ( V_9 -> V_4 ) ;
do {
V_47 = V_48 = F_12 ( V_9 -> V_36 ) ;
V_56 = V_47 . V_33 | ( ( ( T_2 ) V_47 . V_35 ) << 24 ) ;
if ( ! V_47 . V_33 )
break;
V_48 . V_35 = V_48 . V_34 ;
V_48 . V_34 = 0xff ;
V_48 . V_33 = 0 ;
} while ( ! F_8 ( V_9 , V_47 , V_48 ) );
V_4 -> V_8 . V_58 [ 4 ] = V_56 ;
return F_10 ( V_42 , V_9 ) ;
}
int F_14 ( struct V_3 * V_4 , unsigned long V_59 ,
unsigned long V_50 )
{
union V_27 V_47 , V_48 ;
struct V_41 * V_42 = V_4 -> V_55 -> V_8 . V_42 ;
struct V_6 * V_9 , * V_7 = V_4 -> V_8 . V_9 ;
T_2 V_60 ;
bool V_49 ;
bool V_61 ;
if ( ! V_42 || ! V_42 -> V_57 )
return V_44 ;
V_61 = V_7 -> V_62 == V_59 ;
if ( V_61 )
V_9 = V_7 ;
else
V_9 = F_15 ( V_4 -> V_55 , V_59 ) ;
if ( ! V_9 )
return V_63 ;
do {
V_47 = V_48 = F_12 ( V_9 -> V_36 ) ;
V_48 . V_50 = V_50 ;
V_60 = 0 ;
V_49 = false ;
if ( V_50 < V_48 . V_35 ) {
if ( V_50 <= V_48 . V_34 ) {
V_60 = V_48 . V_33 ;
V_48 . V_34 = V_50 ;
V_48 . V_33 = V_51 ;
}
}
if ( V_50 > V_47 . V_50 ) {
V_49 = V_48 . V_52 ;
V_48 . V_52 = 0 ;
}
} while ( ! F_8 ( V_9 , V_47 , V_48 ) );
if ( V_60 && V_60 != V_51 ) {
V_7 -> V_19 |= V_64 ;
V_7 -> V_65 = V_60 ;
}
if ( V_49 ) {
V_7 -> V_19 |= V_53 ;
V_7 -> V_54 = V_9 ;
}
return F_10 ( V_42 , V_7 ) ;
}
int F_16 ( struct V_3 * V_4 , unsigned long V_35 )
{
union V_27 V_47 , V_48 ;
struct V_41 * V_42 = V_4 -> V_55 -> V_8 . V_42 ;
struct V_6 * V_9 = V_4 -> V_8 . V_9 ;
T_2 V_60 ;
if ( ! V_42 || ! V_42 -> V_57 )
return V_44 ;
if ( V_35 > V_9 -> V_36 . V_35 ) {
F_11 ( V_42 , V_9 , V_35 ) ;
goto V_38;
} else if ( V_35 == V_9 -> V_36 . V_35 )
return V_45 ;
F_6 ( V_9 -> V_4 ) ;
do {
V_47 = V_48 = F_12 ( V_9 -> V_36 ) ;
V_60 = 0 ;
V_48 . V_35 = V_35 ;
if ( V_35 <= V_48 . V_34 ) {
V_60 = V_48 . V_33 ;
V_48 . V_33 = 0 ;
V_48 . V_34 = 0xff ;
}
} while ( ! F_8 ( V_9 , V_47 , V_48 ) );
if ( V_60 && V_60 != V_51 ) {
V_9 -> V_19 |= V_64 ;
V_9 -> V_65 = V_60 ;
}
V_38:
return F_10 ( V_42 , V_9 ) ;
}
int F_17 ( struct V_3 * V_4 , unsigned long V_56 )
{
struct V_41 * V_42 = V_4 -> V_55 -> V_8 . V_42 ;
struct V_6 * V_9 = V_4 -> V_8 . V_9 ;
struct V_66 * V_67 ;
struct V_68 * V_36 ;
T_2 V_69 = V_56 & 0x00ffffff ;
T_3 V_70 ;
if ( ! V_42 || ! V_42 -> V_57 )
return V_44 ;
F_11 ( V_42 , V_9 , V_56 >> 24 ) ;
if ( V_69 == V_51 )
goto V_38;
V_67 = F_18 ( V_42 , V_69 , & V_70 ) ;
if ( ! V_67 )
goto V_38;
V_36 = & V_67 -> V_71 [ V_70 ] ;
if ( V_36 -> V_72 ) {
V_9 -> V_19 |= V_64 ;
V_9 -> V_65 = V_69 ;
}
if ( ! F_19 ( & V_4 -> V_55 -> V_73 ) ) {
V_9 -> V_19 |= V_74 ;
V_9 -> V_75 = V_69 ;
}
V_38:
return F_10 ( V_42 , V_9 ) ;
}
