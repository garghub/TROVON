static inline void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
if ( V_2 )
F_2 ( V_2 -> V_4 , V_3 ) ;
}
static inline unsigned long F_3 ( const struct V_1 * V_5 )
{
return ( 1ul << V_5 -> V_6 ) & ~ ( 1ul ) ;
}
static inline struct V_1 * F_4 ( const struct V_1 * V_5 ,
unsigned long V_7 )
{
return F_5 ( V_5 -> V_8 [ V_7 ] ) ;
}
static inline struct V_1 * F_6 ( const struct V_1 * V_5 ,
unsigned long V_7 )
{
return F_7 ( V_5 -> V_8 [ V_7 ] ) ;
}
static void F_8 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_9 ( V_10 , struct V_11 , V_13 ) ;
F_10 ( V_14 , V_12 ) ;
}
static inline void F_11 ( struct V_11 * V_12 )
{
F_12 ( & V_12 -> V_13 , F_8 ) ;
}
static void F_13 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 , struct V_1 , V_13 ) ;
if ( F_14 ( V_2 ) )
F_10 ( V_15 , V_2 ) ;
else if ( V_2 -> V_6 <= V_16 )
F_15 ( V_2 ) ;
else
F_16 ( V_2 ) ;
}
static inline void F_17 ( struct V_17 * V_18 )
{
F_18 ( V_18 , V_13 ) ;
}
static struct V_1 * F_19 ( T_1 V_19 )
{
if ( V_19 <= V_20 )
return F_20 ( V_19 , V_21 ) ;
else
return F_21 ( V_19 ) ;
}
static inline void F_22 ( struct V_1 * V_2 )
{
++ V_2 -> V_22 ? : ++ V_2 -> V_23 ;
}
static inline void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_22 -- ? : V_2 -> V_23 -- ;
}
static struct V_1 * F_24 ( T_2 V_24 )
{
struct V_1 * V_25 = F_25 ( V_15 , V_21 ) ;
if ( V_25 ) {
V_25 -> V_4 = NULL ;
V_25 -> V_24 = V_24 ;
V_25 -> V_26 = 0 ;
V_25 -> V_27 = 0 ;
V_25 -> V_6 = 0 ;
F_26 ( & V_25 -> V_28 ) ;
}
return V_25 ;
}
static struct V_17 * F_27 ( int V_29 )
{
struct V_17 * V_30 = F_28 ( sizeof( struct V_17 ) , V_21 ) ;
if ( V_30 ) {
V_30 -> V_29 = V_29 ;
V_30 -> V_31 = F_29 ( F_30 ( V_29 ) ) ;
F_31 ( & V_30 -> V_32 ) ;
}
return V_30 ;
}
static struct V_1 * F_32 ( T_2 V_24 , int V_27 , int V_6 )
{
T_1 V_33 = F_33 ( struct V_1 , V_8 [ 1ul << V_6 ] ) ;
struct V_1 * V_5 = F_19 ( V_33 ) ;
unsigned int V_34 = V_27 + V_6 ;
F_34 ( ! V_6 || ( V_34 > V_35 ) ) ;
if ( V_5 ) {
V_5 -> V_4 = NULL ;
V_5 -> V_26 = V_27 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_24 = ( V_34 < V_35 ) ? ( V_24 >> V_34 ) << V_34 : 0 ;
if ( V_6 == V_35 )
V_5 -> V_23 = 1 ;
else
V_5 -> V_22 = 1ul << V_6 ;
}
F_35 ( L_1 , V_5 , sizeof( struct V_1 ) ,
sizeof( struct V_1 * ) << V_6 ) ;
return V_5 ;
}
static inline int F_36 ( const struct V_1 * V_5 , const struct V_1 * V_2 )
{
return V_2 && ( ( V_2 -> V_27 + V_2 -> V_6 ) == V_5 -> V_27 ) && F_37 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_5 , unsigned long V_7 , struct V_1 * V_2 )
{
struct V_1 * V_36 = F_4 ( V_5 , V_7 ) ;
int V_37 , V_38 ;
F_34 ( V_7 >= F_3 ( V_5 ) ) ;
if ( V_2 == NULL && V_36 != NULL )
F_22 ( V_5 ) ;
if ( V_2 != NULL && V_36 == NULL )
F_23 ( V_5 ) ;
V_38 = F_36 ( V_5 , V_36 ) ;
V_37 = F_36 ( V_5 , V_2 ) ;
if ( V_38 && ! V_37 )
V_5 -> V_23 -- ;
else if ( ! V_38 && V_37 )
V_5 -> V_23 ++ ;
if ( V_2 && ( V_5 -> V_26 < V_2 -> V_26 ) )
V_5 -> V_26 = V_2 -> V_26 ;
F_2 ( V_5 -> V_8 [ V_7 ] , V_2 ) ;
}
static void F_39 ( struct V_1 * V_5 )
{
unsigned long V_7 ;
for ( V_7 = F_3 ( V_5 ) ; V_7 ; ) {
struct V_1 * V_39 = F_4 ( V_5 , -- V_7 ) ;
if ( ! V_39 )
continue;
if ( F_40 ( V_39 ) == V_5 )
F_39 ( V_39 ) ;
else
F_1 ( V_39 , V_5 ) ;
}
}
static inline void F_41 ( struct V_1 * V_3 , struct V_40 * V_41 ,
T_2 V_24 , struct V_1 * V_2 )
{
if ( V_3 )
F_38 ( V_3 , F_42 ( V_24 , V_3 ) , V_2 ) ;
else
F_2 ( V_41 -> V_40 , V_2 ) ;
}
static inline void F_43 ( struct V_1 * V_5 )
{
V_5 -> V_13 . V_42 = NULL ;
}
static inline void F_44 ( struct V_1 * V_5 , struct V_1 * V_2 )
{
V_2 -> V_13 . V_42 = V_5 -> V_13 . V_42 ;
V_5 -> V_13 . V_42 = & V_2 -> V_13 ;
}
static void F_45 ( struct V_1 * V_5 )
{
struct V_43 * V_10 = & V_5 -> V_13 ;
while ( V_10 ) {
V_10 = V_10 -> V_42 ;
V_44 += F_33 ( struct V_1 , V_8 [ 1 << V_5 -> V_6 ] ) ;
F_46 ( V_5 ) ;
V_5 = F_9 ( V_10 , struct V_1 , V_13 ) ;
}
if ( V_44 >= V_20 * V_45 ) {
V_44 = 0 ;
F_47 () ;
}
}
static void F_48 ( struct V_40 * V_41 , struct V_1 * V_46 , struct V_1 * V_5 )
{
struct V_1 * V_3 = F_40 ( V_46 ) ;
unsigned long V_7 ;
F_49 ( V_5 , V_3 ) ;
F_41 ( V_3 , V_41 , V_5 -> V_24 , V_5 ) ;
F_39 ( V_5 ) ;
F_45 ( V_46 ) ;
for ( V_7 = F_3 ( V_5 ) ; V_7 ; ) {
struct V_1 * V_39 = F_4 ( V_5 , -- V_7 ) ;
if ( F_36 ( V_5 , V_39 ) )
F_50 ( V_41 , V_39 ) ;
}
}
static int F_51 ( struct V_40 * V_41 , struct V_1 * V_46 )
{
struct V_1 * V_5 ;
unsigned long V_7 ;
T_2 V_47 ;
F_35 ( L_2 ) ;
V_5 = F_32 ( V_46 -> V_24 , V_46 -> V_27 - 1 , V_46 -> V_6 + 1 ) ;
if ( ! V_5 )
return - V_48 ;
F_43 ( V_46 ) ;
for ( V_7 = F_3 ( V_46 ) , V_47 = 1u << V_5 -> V_27 ; V_7 ; ) {
struct V_1 * V_39 = F_4 ( V_46 , -- V_7 ) ;
struct V_1 * V_49 , * V_50 ;
unsigned long V_51 , V_52 ;
if ( V_39 == NULL )
continue;
if ( ! F_36 ( V_46 , V_39 ) ) {
F_38 ( V_5 , F_42 ( V_39 -> V_24 , V_5 ) , V_39 ) ;
continue;
}
F_44 ( V_46 , V_39 ) ;
if ( V_39 -> V_6 == 1 ) {
F_38 ( V_5 , 2 * V_7 + 1 , F_4 ( V_39 , 1 ) ) ;
F_38 ( V_5 , 2 * V_7 , F_4 ( V_39 , 0 ) ) ;
continue;
}
V_50 = F_32 ( V_39 -> V_24 | V_47 , V_39 -> V_27 , V_39 -> V_6 - 1 ) ;
if ( ! V_50 )
goto V_53;
V_49 = F_32 ( V_39 -> V_24 , V_39 -> V_27 , V_39 -> V_6 - 1 ) ;
F_44 ( V_5 , V_50 ) ;
if ( ! V_49 )
goto V_53;
F_44 ( V_5 , V_49 ) ;
for ( V_52 = F_3 ( V_39 ) , V_51 = V_52 / 2 ; V_51 ; ) {
F_38 ( V_50 , -- V_51 , F_4 ( V_39 , -- V_52 ) ) ;
F_38 ( V_49 , V_51 , F_4 ( V_39 , V_51 ) ) ;
F_38 ( V_50 , -- V_51 , F_4 ( V_39 , -- V_52 ) ) ;
F_38 ( V_49 , V_51 , F_4 ( V_39 , V_51 ) ) ;
}
F_49 ( V_50 , V_5 ) ;
F_49 ( V_49 , V_5 ) ;
F_38 ( V_5 , 2 * V_7 + 1 , V_50 ) ;
F_38 ( V_5 , 2 * V_7 , V_49 ) ;
}
F_48 ( V_41 , V_46 , V_5 ) ;
return 0 ;
V_53:
F_45 ( V_5 ) ;
return - V_48 ;
}
static int F_52 ( struct V_40 * V_41 , struct V_1 * V_46 )
{
struct V_1 * V_5 ;
unsigned long V_7 ;
F_35 ( L_3 ) ;
V_5 = F_32 ( V_46 -> V_24 , V_46 -> V_27 + 1 , V_46 -> V_6 - 1 ) ;
if ( ! V_5 )
return - V_48 ;
F_43 ( V_46 ) ;
for ( V_7 = F_3 ( V_46 ) ; V_7 ; ) {
struct V_1 * V_50 = F_4 ( V_46 , -- V_7 ) ;
struct V_1 * V_49 = F_4 ( V_46 , -- V_7 ) ;
struct V_1 * V_39 ;
if ( ! V_50 || ! V_49 ) {
F_38 ( V_5 , V_7 / 2 , V_50 ? : V_49 ) ;
continue;
}
V_39 = F_32 ( V_49 -> V_24 , V_46 -> V_27 , 1 ) ;
if ( ! V_39 ) {
F_45 ( V_5 ) ;
return - V_48 ;
}
F_44 ( V_5 , V_39 ) ;
F_38 ( V_39 , 1 , V_50 ) ;
F_38 ( V_39 , 0 , V_49 ) ;
F_49 ( V_39 , V_5 ) ;
F_38 ( V_5 , V_7 / 2 , V_39 ) ;
}
F_48 ( V_41 , V_46 , V_5 ) ;
return 0 ;
}
static void F_53 ( struct V_40 * V_41 , struct V_1 * V_46 )
{
struct V_1 * V_2 , * V_3 ;
unsigned long V_7 ;
for ( V_2 = NULL , V_7 = F_3 ( V_46 ) ; ! V_2 && V_7 ; )
V_2 = F_4 ( V_46 , -- V_7 ) ;
V_3 = F_40 ( V_46 ) ;
F_41 ( V_3 , V_41 , V_46 -> V_24 , V_2 ) ;
F_1 ( V_2 , V_3 ) ;
F_46 ( V_46 ) ;
}
static unsigned char F_54 ( struct V_1 * V_5 )
{
unsigned char V_26 = V_5 -> V_27 ;
unsigned long V_54 , V_7 ;
for ( V_7 = 0 , V_54 = 0x2ul ; V_7 < F_3 ( V_5 ) ; V_7 += V_54 ) {
struct V_1 * V_2 = F_4 ( V_5 , V_7 ) ;
if ( ! V_2 || ( V_2 -> V_26 <= V_26 ) )
continue;
V_54 <<= ( V_2 -> V_26 - V_26 ) ;
V_26 = V_2 -> V_26 ;
V_7 &= ~ ( V_54 - 1 ) ;
if ( ( V_26 + 1 ) >= ( V_5 -> V_27 + V_5 -> V_6 ) )
break;
}
V_5 -> V_26 = V_26 ;
return V_26 ;
}
static bool F_55 ( const struct V_1 * V_3 , const struct V_1 * V_5 )
{
unsigned long V_55 = F_3 ( V_5 ) ;
unsigned long V_56 = V_55 ;
V_56 *= V_3 ? V_57 : V_58 ;
V_55 -= V_5 -> V_22 ;
V_55 += V_5 -> V_23 ;
return ( V_55 > 1 ) && V_5 -> V_27 && ( ( 50 * V_55 ) >= V_56 ) ;
}
static bool F_56 ( const struct V_1 * V_3 , const struct V_1 * V_5 )
{
unsigned long V_55 = F_3 ( V_5 ) ;
unsigned long V_56 = V_55 ;
V_56 *= V_3 ? V_59 : V_60 ;
V_55 -= V_5 -> V_22 ;
return ( V_55 > 1 ) && ( V_5 -> V_6 > 1 ) && ( ( 100 * V_55 ) < V_56 ) ;
}
static bool F_57 ( const struct V_1 * V_5 )
{
unsigned long V_55 = F_3 ( V_5 ) ;
V_55 -= V_5 -> V_22 ;
if ( ( V_5 -> V_6 == V_35 ) && V_5 -> V_23 )
V_55 -= V_61 ;
return V_55 < 2 ;
}
static void F_50 ( struct V_40 * V_41 , struct V_1 * V_5 )
{
struct V_1 * V_3 = F_40 ( V_5 ) ;
struct V_1 T_3 * * V_62 ;
int V_63 = V_64 ;
F_35 ( L_4 ,
V_5 , V_57 , V_59 ) ;
V_62 = V_3 ? & V_3 -> V_8 [ F_42 ( V_5 -> V_24 , V_3 ) ] : & V_41 -> V_40 ;
F_34 ( V_5 != F_5 ( * V_62 ) ) ;
while ( F_55 ( V_3 , V_5 ) && V_63 ) {
if ( F_51 ( V_41 , V_5 ) ) {
#ifdef F_58
F_59 ( V_41 -> V_65 -> V_66 ) ;
#endif
break;
}
V_63 -- ;
V_5 = F_5 ( * V_62 ) ;
}
if ( V_63 != V_64 )
return;
while ( F_56 ( V_3 , V_5 ) && V_63 ) {
if ( F_52 ( V_41 , V_5 ) ) {
#ifdef F_58
F_59 ( V_41 -> V_65 -> V_66 ) ;
#endif
break;
}
V_63 -- ;
V_5 = F_5 ( * V_62 ) ;
}
if ( F_57 ( V_5 ) ) {
F_53 ( V_41 , V_5 ) ;
return;
}
if ( V_63 != V_64 )
return;
if ( V_5 -> V_26 > V_5 -> V_27 ) {
unsigned char V_26 = F_54 ( V_5 ) ;
if ( V_3 && ( V_26 > V_3 -> V_26 ) )
V_3 -> V_26 = V_26 ;
}
}
static struct V_17 * F_60 ( struct V_1 * V_25 , int V_29 )
{
struct V_67 * V_10 = & V_25 -> V_28 ;
struct V_17 * V_30 ;
F_61 (li, head, hlist)
if ( V_30 -> V_29 == V_29 )
return V_30 ;
return NULL ;
}
static inline struct V_68 * F_62 ( struct V_1 * V_25 , int V_29 )
{
struct V_17 * V_30 = F_60 ( V_25 , V_29 ) ;
if ( ! V_30 )
return NULL ;
return & V_30 -> V_32 ;
}
static void F_63 ( struct V_1 * V_25 )
{
struct V_1 * V_3 = F_40 ( V_25 ) ;
while ( V_3 && ( V_3 -> V_26 > V_3 -> V_27 ) && ( V_3 -> V_26 > V_25 -> V_26 ) ) {
if ( F_54 ( V_3 ) > V_25 -> V_26 )
break;
V_3 = F_40 ( V_3 ) ;
}
}
static void F_64 ( struct V_1 * V_25 )
{
struct V_1 * V_5 = F_40 ( V_25 ) ;
while ( V_5 && ( V_5 -> V_26 < V_25 -> V_26 ) ) {
V_5 -> V_26 = V_25 -> V_26 ;
V_5 = F_40 ( V_5 ) ;
}
}
static void F_65 ( struct V_1 * V_25 , struct V_17 * V_69 )
{
struct V_70 * * V_71 = V_69 -> V_72 . V_71 ;
struct V_17 * V_30 = F_66 ( V_71 , F_67 ( * V_30 ) , V_72 . V_42 ) ;
F_68 ( & V_69 -> V_72 ) ;
if ( F_69 ( & V_25 -> V_28 ) || ( * V_71 ) )
return;
V_25 -> V_26 = V_35 - V_30 -> V_29 ;
F_63 ( V_25 ) ;
}
static void F_70 ( struct V_1 * V_25 , struct V_17 * V_73 )
{
struct V_67 * V_10 = & V_25 -> V_28 ;
struct V_17 * V_30 = NULL , * V_74 = NULL ;
if ( F_69 ( V_10 ) ) {
F_71 ( & V_73 -> V_72 , V_10 ) ;
} else {
F_72 (li, head, hlist) {
if ( V_73 -> V_29 > V_30 -> V_29 )
break;
V_74 = V_30 ;
}
if ( V_74 )
F_73 ( & V_73 -> V_72 , & V_74 -> V_72 ) ;
else
F_74 ( & V_73 -> V_72 , & V_30 -> V_72 ) ;
}
if ( V_25 -> V_26 < ( V_35 - V_73 -> V_29 ) ) {
V_25 -> V_26 = V_35 - V_73 -> V_29 ;
F_64 ( V_25 ) ;
}
}
static struct V_1 * F_75 ( struct V_40 * V_41 , T_4 V_24 )
{
struct V_1 * V_2 = F_7 ( V_41 -> V_40 ) ;
while ( V_2 ) {
unsigned long V_75 = F_42 ( V_24 , V_2 ) ;
if ( V_75 & ( ~ 0ul << V_2 -> V_6 ) )
return NULL ;
if ( F_14 ( V_2 ) )
break;
V_2 = F_6 ( V_2 , V_75 ) ;
}
return V_2 ;
}
static struct V_11 * F_76 ( struct V_68 * V_76 , T_5 V_77 , T_4 V_78 )
{
struct V_11 * V_12 ;
if ( ! V_76 )
return NULL ;
F_77 (fa, fah, fa_list) {
if ( V_12 -> V_79 > V_77 )
continue;
if ( V_12 -> V_80 -> V_81 >= V_78 || V_12 -> V_79 < V_77 )
return V_12 ;
}
return NULL ;
}
static void F_78 ( struct V_40 * V_41 , struct V_1 * V_5 )
{
struct V_1 * V_3 ;
while ( ( V_3 = F_40 ( V_5 ) ) != NULL ) {
F_50 ( V_41 , V_5 ) ;
V_5 = V_3 ;
}
if ( F_37 ( V_5 ) )
F_50 ( V_41 , V_5 ) ;
}
static struct V_68 * F_79 ( struct V_40 * V_41 , T_4 V_24 , int V_29 )
{
struct V_68 * V_82 = NULL ;
struct V_1 * V_25 , * V_2 , * V_3 = NULL ;
struct V_17 * V_30 ;
V_30 = F_27 ( V_29 ) ;
if ( ! V_30 )
return NULL ;
V_82 = & V_30 -> V_32 ;
V_2 = F_5 ( V_41 -> V_40 ) ;
while ( V_2 ) {
unsigned long V_75 = F_42 ( V_24 , V_2 ) ;
if ( V_75 >> V_2 -> V_6 )
break;
if ( F_14 ( V_2 ) ) {
F_70 ( V_2 , V_30 ) ;
return V_82 ;
}
V_3 = V_2 ;
V_2 = F_6 ( V_2 , V_75 ) ;
}
V_25 = F_24 ( V_24 ) ;
if ( ! V_25 ) {
F_17 ( V_30 ) ;
return NULL ;
}
F_70 ( V_25 , V_30 ) ;
if ( V_2 ) {
struct V_1 * V_5 ;
V_5 = F_32 ( V_24 , F_80 ( V_24 ^ V_2 -> V_24 ) , 1 ) ;
if ( ! V_5 ) {
F_17 ( V_30 ) ;
F_46 ( V_25 ) ;
return NULL ;
}
F_49 ( V_5 , V_3 ) ;
F_38 ( V_5 , F_42 ( V_24 , V_5 ) ^ 1 , V_2 ) ;
F_41 ( V_3 , V_41 , V_24 , V_5 ) ;
F_1 ( V_2 , V_5 ) ;
V_3 = V_5 ;
}
if ( V_3 ) {
F_49 ( V_25 , V_3 ) ;
F_38 ( V_3 , F_42 ( V_24 , V_3 ) , V_25 ) ;
F_78 ( V_41 , V_3 ) ;
} else {
F_2 ( V_41 -> V_40 , V_25 ) ;
}
return V_82 ;
}
int F_81 ( struct V_83 * V_84 , struct V_85 * V_86 )
{
struct V_40 * V_41 = (struct V_40 * ) V_84 -> V_87 ;
struct V_11 * V_12 , * V_88 ;
struct V_68 * V_82 = NULL ;
struct V_89 * V_90 ;
int V_29 = V_86 -> V_91 ;
T_5 V_77 = V_86 -> V_92 ;
T_4 V_24 , V_93 ;
int V_94 ;
struct V_1 * V_25 ;
if ( V_29 > 32 )
return - V_95 ;
V_24 = F_29 ( V_86 -> V_96 ) ;
F_35 ( L_5 , V_84 -> V_97 , V_24 , V_29 ) ;
V_93 = F_29 ( F_30 ( V_29 ) ) ;
if ( V_24 & ~ V_93 )
return - V_95 ;
V_24 = V_24 & V_93 ;
V_90 = F_82 ( V_86 ) ;
if ( F_83 ( V_90 ) ) {
V_94 = F_84 ( V_90 ) ;
goto V_94;
}
V_25 = F_75 ( V_41 , V_24 ) ;
V_12 = NULL ;
if ( V_25 ) {
V_82 = F_62 ( V_25 , V_29 ) ;
V_12 = F_76 ( V_82 , V_77 , V_90 -> V_81 ) ;
}
if ( V_12 && V_12 -> V_79 == V_77 &&
V_12 -> V_80 -> V_81 == V_90 -> V_81 ) {
struct V_11 * V_98 , * V_99 ;
V_94 = - V_100 ;
if ( V_86 -> V_101 & V_102 )
goto V_103;
V_99 = NULL ;
V_98 = V_12 ;
V_12 = F_85 ( V_12 -> V_104 . V_105 , struct V_11 , V_104 ) ;
F_86 (fa, fa_head, fa_list) {
if ( V_12 -> V_79 != V_77 )
break;
if ( V_12 -> V_80 -> V_81 != V_90 -> V_81 )
break;
if ( V_12 -> V_106 == V_86 -> V_107 &&
V_12 -> V_80 == V_90 ) {
V_99 = V_12 ;
break;
}
}
if ( V_86 -> V_101 & V_108 ) {
struct V_89 * V_109 ;
T_5 V_110 ;
V_12 = V_98 ;
if ( V_99 ) {
if ( V_12 == V_99 )
V_94 = 0 ;
goto V_103;
}
V_94 = - V_111 ;
V_88 = F_25 ( V_14 , V_21 ) ;
if ( V_88 == NULL )
goto V_103;
V_109 = V_12 -> V_80 ;
V_88 -> V_79 = V_12 -> V_79 ;
V_88 -> V_80 = V_90 ;
V_88 -> V_106 = V_86 -> V_107 ;
V_110 = V_12 -> V_112 ;
V_88 -> V_112 = V_110 & ~ V_113 ;
F_87 ( & V_12 -> V_104 , & V_88 -> V_104 ) ;
F_11 ( V_12 ) ;
F_88 ( V_109 ) ;
if ( V_110 & V_113 )
F_89 ( V_86 -> V_114 . V_115 ) ;
F_90 ( V_116 , F_91 ( V_24 ) , V_88 , V_29 ,
V_84 -> V_97 , & V_86 -> V_114 , V_108 ) ;
goto V_117;
}
if ( V_99 )
goto V_103;
if ( ! ( V_86 -> V_101 & V_118 ) )
V_12 = V_98 ;
}
V_94 = - V_119 ;
if ( ! ( V_86 -> V_101 & V_120 ) )
goto V_103;
V_94 = - V_111 ;
V_88 = F_25 ( V_14 , V_21 ) ;
if ( V_88 == NULL )
goto V_103;
V_88 -> V_80 = V_90 ;
V_88 -> V_79 = V_77 ;
V_88 -> V_106 = V_86 -> V_107 ;
V_88 -> V_112 = 0 ;
if ( ! V_82 ) {
V_82 = F_79 ( V_41 , V_24 , V_29 ) ;
if ( F_92 ( ! V_82 ) ) {
V_94 = - V_48 ;
goto V_121;
}
}
if ( ! V_29 )
V_84 -> V_122 ++ ;
F_93 ( & V_88 -> V_104 ,
( V_12 ? & V_12 -> V_104 : V_82 ) ) ;
F_89 ( V_86 -> V_114 . V_115 ) ;
F_90 ( V_116 , F_91 ( V_24 ) , V_88 , V_29 , V_84 -> V_97 ,
& V_86 -> V_114 , 0 ) ;
V_117:
return 0 ;
V_121:
F_10 ( V_14 , V_88 ) ;
V_103:
F_88 ( V_90 ) ;
V_94:
return V_94 ;
}
static inline T_2 F_94 ( T_2 V_24 , struct V_1 * V_2 )
{
T_2 V_123 = V_2 -> V_24 ;
return ( V_24 ^ V_123 ) & ( V_123 | - V_123 ) ;
}
int F_95 ( struct V_83 * V_84 , const struct V_124 * V_125 ,
struct V_126 * V_127 , int V_128 )
{
struct V_40 * V_41 = (struct V_40 * ) V_84 -> V_87 ;
#ifdef F_58
struct V_129 T_6 * V_65 = V_41 -> V_65 ;
#endif
const T_2 V_24 = F_29 ( V_125 -> V_130 ) ;
struct V_1 * V_2 , * V_131 ;
struct V_17 * V_30 ;
T_2 V_132 ;
V_2 = F_96 ( V_41 -> V_40 ) ;
if ( ! V_2 )
return - V_133 ;
#ifdef F_58
F_59 ( V_65 -> gets ) ;
#endif
V_131 = V_2 ;
V_132 = 0 ;
for (; ; ) {
unsigned long V_75 = F_42 ( V_24 , V_2 ) ;
if ( V_75 & ( ~ 0ul << V_2 -> V_6 ) )
break;
if ( F_14 ( V_2 ) )
goto V_134;
if ( V_2 -> V_26 > V_2 -> V_27 ) {
V_131 = V_2 ;
V_132 = V_75 ;
}
V_2 = F_6 ( V_2 , V_75 ) ;
if ( F_92 ( ! V_2 ) )
goto V_135;
}
for (; ; ) {
struct V_1 T_3 * * V_62 = V_2 -> V_8 ;
if ( F_92 ( F_94 ( V_24 , V_2 ) ) || ( V_2 -> V_26 == V_2 -> V_27 ) )
goto V_135;
if ( F_92 ( F_14 ( V_2 ) ) )
break;
while ( ( V_2 = F_96 ( * V_62 ) ) == NULL ) {
V_135:
#ifdef F_58
if ( ! V_2 )
F_59 ( V_65 -> V_136 ) ;
#endif
while ( ! V_132 ) {
T_2 V_137 = V_131 -> V_24 ;
V_131 = F_97 ( V_131 ) ;
if ( F_92 ( ! V_131 ) )
return - V_133 ;
#ifdef F_58
F_59 ( V_65 -> V_138 ) ;
#endif
V_132 = F_42 ( V_137 , V_131 ) ;
}
V_132 &= V_132 - 1 ;
V_62 = & V_131 -> V_8 [ V_132 ] ;
}
}
V_134:
F_61 (li, &n->list, hlist) {
struct V_11 * V_12 ;
if ( ( V_24 ^ V_2 -> V_24 ) & V_30 -> V_31 )
continue;
F_98 (fa, &li->falh, fa_list) {
struct V_89 * V_90 = V_12 -> V_80 ;
int V_139 , V_94 ;
if ( V_12 -> V_79 && V_12 -> V_79 != V_125 -> V_140 )
continue;
if ( V_90 -> V_141 )
continue;
if ( V_12 -> V_80 -> V_142 < V_125 -> V_143 )
continue;
F_99 ( V_12 ) ;
V_94 = V_144 [ V_12 -> V_106 ] . error ;
if ( F_92 ( V_94 < 0 ) ) {
#ifdef F_58
F_59 ( V_65 -> V_145 ) ;
#endif
return V_94 ;
}
if ( V_90 -> V_128 & V_146 )
continue;
for ( V_139 = 0 ; V_139 < V_90 -> V_147 ; V_139 ++ ) {
const struct V_148 * V_149 = & V_90 -> V_148 [ V_139 ] ;
if ( V_149 -> V_150 & V_146 )
continue;
if ( V_125 -> V_151 && V_125 -> V_151 != V_149 -> V_152 )
continue;
if ( ! ( V_128 & V_153 ) )
F_100 ( & V_90 -> V_154 ) ;
V_127 -> V_155 = V_30 -> V_29 ;
V_127 -> V_156 = V_139 ;
V_127 -> type = V_12 -> V_106 ;
V_127 -> V_157 = V_90 -> V_142 ;
V_127 -> V_90 = V_90 ;
V_127 -> V_158 = V_84 ;
V_127 -> V_82 = & V_30 -> V_32 ;
#ifdef F_58
F_59 ( V_65 -> V_145 ) ;
#endif
return V_94 ;
}
}
#ifdef F_58
F_59 ( V_65 -> V_159 ) ;
#endif
}
goto V_135;
}
static void F_101 ( struct V_40 * V_41 , struct V_1 * V_25 )
{
struct V_1 * V_3 = F_40 ( V_25 ) ;
F_35 ( L_6 , V_25 ) ;
if ( V_3 ) {
F_38 ( V_3 , F_42 ( V_25 -> V_24 , V_3 ) , NULL ) ;
F_78 ( V_41 , V_3 ) ;
} else {
F_102 ( V_41 -> V_40 , NULL ) ;
}
F_46 ( V_25 ) ;
}
int F_103 ( struct V_83 * V_84 , struct V_85 * V_86 )
{
struct V_40 * V_41 = (struct V_40 * ) V_84 -> V_87 ;
T_4 V_24 , V_93 ;
int V_29 = V_86 -> V_91 ;
T_5 V_77 = V_86 -> V_92 ;
struct V_11 * V_12 , * V_160 ;
struct V_68 * V_82 ;
struct V_1 * V_25 ;
struct V_17 * V_30 ;
if ( V_29 > 32 )
return - V_95 ;
V_24 = F_29 ( V_86 -> V_96 ) ;
V_93 = F_29 ( F_30 ( V_29 ) ) ;
if ( V_24 & ~ V_93 )
return - V_95 ;
V_24 = V_24 & V_93 ;
V_25 = F_75 ( V_41 , V_24 ) ;
if ( ! V_25 )
return - V_161 ;
V_30 = F_60 ( V_25 , V_29 ) ;
if ( ! V_30 )
return - V_161 ;
V_82 = & V_30 -> V_32 ;
V_12 = F_76 ( V_82 , V_77 , 0 ) ;
if ( ! V_12 )
return - V_161 ;
F_35 ( L_7 , V_24 , V_29 , V_77 , V_41 ) ;
V_160 = NULL ;
V_12 = F_85 ( V_12 -> V_104 . V_105 , struct V_11 , V_104 ) ;
F_86 (fa, fa_head, fa_list) {
struct V_89 * V_90 = V_12 -> V_80 ;
if ( V_12 -> V_79 != V_77 )
break;
if ( ( ! V_86 -> V_107 || V_12 -> V_106 == V_86 -> V_107 ) &&
( V_86 -> V_162 == V_163 ||
V_12 -> V_80 -> V_142 == V_86 -> V_162 ) &&
( ! V_86 -> V_164 ||
V_90 -> V_165 == V_86 -> V_164 ) &&
( ! V_86 -> V_166 ||
V_90 -> V_167 == V_86 -> V_166 ) &&
F_104 ( V_86 , V_90 ) == 0 ) {
V_160 = V_12 ;
break;
}
}
if ( ! V_160 )
return - V_161 ;
V_12 = V_160 ;
F_90 ( V_168 , F_91 ( V_24 ) , V_12 , V_29 , V_84 -> V_97 ,
& V_86 -> V_114 , 0 ) ;
F_105 ( & V_12 -> V_104 ) ;
if ( ! V_29 )
V_84 -> V_122 -- ;
if ( F_106 ( V_82 ) ) {
F_65 ( V_25 , V_30 ) ;
F_17 ( V_30 ) ;
}
if ( F_69 ( & V_25 -> V_28 ) )
F_101 ( V_41 , V_25 ) ;
if ( V_12 -> V_112 & V_113 )
F_89 ( V_86 -> V_114 . V_115 ) ;
F_88 ( V_12 -> V_80 ) ;
F_11 ( V_12 ) ;
return 0 ;
}
static int F_107 ( struct V_68 * V_10 )
{
struct V_11 * V_12 , * V_169 ;
int V_134 = 0 ;
F_108 (fa, fa_node, head, fa_list) {
struct V_89 * V_90 = V_12 -> V_80 ;
if ( V_90 && ( V_90 -> V_128 & V_146 ) ) {
F_105 ( & V_12 -> V_104 ) ;
F_88 ( V_12 -> V_80 ) ;
F_11 ( V_12 ) ;
V_134 ++ ;
}
}
return V_134 ;
}
static int F_109 ( struct V_1 * V_25 )
{
int V_134 = 0 ;
struct V_67 * V_170 = & V_25 -> V_28 ;
struct V_70 * V_171 ;
struct V_17 * V_30 = NULL ;
unsigned char V_29 = V_35 ;
F_110 (li, tmp, lih, hlist) {
V_134 += F_107 ( & V_30 -> V_32 ) ;
if ( F_106 ( & V_30 -> V_32 ) ) {
F_68 ( & V_30 -> V_72 ) ;
F_17 ( V_30 ) ;
continue;
}
V_29 = V_30 -> V_29 ;
}
V_25 -> V_26 = V_35 - V_29 ;
return V_134 ;
}
static struct V_1 * F_111 ( struct V_1 * V_172 , struct V_1 * V_173 )
{
do {
unsigned long V_174 = V_173 ? V_174 = F_42 ( V_173 -> V_24 , V_172 ) + 1 : 0 ;
while ( V_174 < F_3 ( V_172 ) ) {
V_173 = F_6 ( V_172 , V_174 ++ ) ;
if ( ! V_173 )
continue;
if ( F_14 ( V_173 ) )
return V_173 ;
V_172 = V_173 ;
V_174 = 0 ;
}
V_173 = V_172 ;
} while ( ( V_172 = F_97 ( V_173 ) ) != NULL );
return NULL ;
}
static struct V_1 * F_112 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_7 ( V_41 -> V_40 ) ;
if ( ! V_2 )
return NULL ;
if ( F_14 ( V_2 ) )
return V_2 ;
return F_111 ( V_2 , NULL ) ;
}
static struct V_1 * F_113 ( struct V_1 * V_25 )
{
struct V_1 * V_172 = F_97 ( V_25 ) ;
if ( ! V_172 )
return NULL ;
return F_111 ( V_172 , V_25 ) ;
}
static struct V_1 * F_114 ( struct V_40 * V_41 , int V_75 )
{
struct V_1 * V_25 = F_112 ( V_41 ) ;
while ( V_25 && V_75 -- > 0 )
V_25 = F_113 ( V_25 ) ;
return V_25 ;
}
int F_115 ( struct V_83 * V_84 )
{
struct V_40 * V_41 = (struct V_40 * ) V_84 -> V_87 ;
struct V_1 * V_25 , * V_175 = NULL ;
int V_134 = 0 ;
for ( V_25 = F_112 ( V_41 ) ; V_25 ; V_25 = F_113 ( V_25 ) ) {
V_134 += F_109 ( V_25 ) ;
if ( V_175 ) {
if ( F_69 ( & V_175 -> V_28 ) )
F_101 ( V_41 , V_175 ) ;
else
F_63 ( V_175 ) ;
}
V_175 = V_25 ;
}
if ( V_175 ) {
if ( F_69 ( & V_175 -> V_28 ) )
F_101 ( V_41 , V_175 ) ;
else
F_63 ( V_175 ) ;
}
F_35 ( L_8 , V_134 ) ;
return V_134 ;
}
void F_116 ( struct V_83 * V_84 )
{
#ifdef F_58
struct V_40 * V_41 = (struct V_40 * ) V_84 -> V_87 ;
F_117 ( V_41 -> V_65 ) ;
#endif
F_15 ( V_84 ) ;
}
static int F_118 ( T_2 V_24 , int V_29 , struct V_68 * V_76 ,
struct V_83 * V_84 ,
struct V_176 * V_177 , struct V_178 * V_179 )
{
int V_7 , V_180 ;
struct V_11 * V_12 ;
T_7 V_181 = F_91 ( V_24 ) ;
V_180 = V_179 -> args [ 5 ] ;
V_7 = 0 ;
F_98 (fa, fah, fa_list) {
if ( V_7 < V_180 ) {
V_7 ++ ;
continue;
}
if ( F_119 ( V_177 , F_120 ( V_179 -> V_177 ) . V_182 ,
V_179 -> V_183 -> V_184 ,
V_116 ,
V_84 -> V_97 ,
V_12 -> V_106 ,
V_181 ,
V_29 ,
V_12 -> V_79 ,
V_12 -> V_80 , V_185 ) < 0 ) {
V_179 -> args [ 5 ] = V_7 ;
return - 1 ;
}
V_7 ++ ;
}
V_179 -> args [ 5 ] = V_7 ;
return V_177 -> V_186 ;
}
static int F_121 ( struct V_1 * V_25 , struct V_83 * V_84 ,
struct V_176 * V_177 , struct V_178 * V_179 )
{
struct V_17 * V_30 ;
int V_7 , V_180 ;
V_180 = V_179 -> args [ 4 ] ;
V_7 = 0 ;
F_61 (li, &l->list, hlist) {
if ( V_7 < V_180 ) {
V_7 ++ ;
continue;
}
if ( V_7 > V_180 )
V_179 -> args [ 5 ] = 0 ;
if ( F_106 ( & V_30 -> V_32 ) )
continue;
if ( F_118 ( V_25 -> V_24 , V_30 -> V_29 , & V_30 -> V_32 , V_84 , V_177 , V_179 ) < 0 ) {
V_179 -> args [ 4 ] = V_7 ;
return - 1 ;
}
V_7 ++ ;
}
V_179 -> args [ 4 ] = V_7 ;
return V_177 -> V_186 ;
}
int F_122 ( struct V_83 * V_84 , struct V_176 * V_177 ,
struct V_178 * V_179 )
{
struct V_1 * V_25 ;
struct V_40 * V_41 = (struct V_40 * ) V_84 -> V_87 ;
T_2 V_24 = V_179 -> args [ 2 ] ;
int V_187 = V_179 -> args [ 3 ] ;
F_123 () ;
if ( V_187 == 0 )
V_25 = F_112 ( V_41 ) ;
else {
V_25 = F_75 ( V_41 , V_24 ) ;
if ( ! V_25 )
V_25 = F_114 ( V_41 , V_187 ) ;
}
while ( V_25 ) {
V_179 -> args [ 2 ] = V_25 -> V_24 ;
if ( F_121 ( V_25 , V_84 , V_177 , V_179 ) < 0 ) {
V_179 -> args [ 3 ] = V_187 ;
F_124 () ;
return - 1 ;
}
++ V_187 ;
V_25 = F_113 ( V_25 ) ;
memset ( & V_179 -> args [ 4 ] , 0 ,
sizeof( V_179 -> args ) - 4 * sizeof( V_179 -> args [ 0 ] ) ) ;
}
V_179 -> args [ 3 ] = V_187 ;
F_124 () ;
return V_177 -> V_186 ;
}
void T_8 F_125 ( void )
{
V_14 = F_126 ( L_9 ,
sizeof( struct V_11 ) ,
0 , V_188 , NULL ) ;
V_15 = F_126 ( L_10 ,
F_127 ( sizeof( struct V_1 ) ,
sizeof( struct V_17 ) ) ,
0 , V_188 , NULL ) ;
}
struct V_83 * F_128 ( T_4 V_189 )
{
struct V_83 * V_84 ;
struct V_40 * V_41 ;
V_84 = F_28 ( sizeof( struct V_83 ) + sizeof( struct V_40 ) ,
V_21 ) ;
if ( V_84 == NULL )
return NULL ;
V_84 -> V_97 = V_189 ;
V_84 -> V_190 = - 1 ;
V_84 -> V_122 = 0 ;
V_41 = (struct V_40 * ) V_84 -> V_87 ;
F_102 ( V_41 -> V_40 , NULL ) ;
#ifdef F_58
V_41 -> V_65 = F_129 ( struct V_129 ) ;
if ( ! V_41 -> V_65 ) {
F_15 ( V_84 ) ;
V_84 = NULL ;
}
#endif
return V_84 ;
}
static struct V_1 * F_130 ( struct V_191 * V_192 )
{
unsigned long V_132 = V_192 -> V_75 ;
struct V_1 * V_5 = V_192 -> V_1 ;
struct V_1 * V_172 ;
if ( ! V_5 )
return NULL ;
F_35 ( L_11 ,
V_192 -> V_1 , V_192 -> V_75 , V_192 -> V_193 ) ;
V_194:
while ( V_132 < F_3 ( V_5 ) ) {
struct V_1 * V_2 = F_6 ( V_5 , V_132 ) ;
if ( V_2 ) {
if ( F_14 ( V_2 ) ) {
V_192 -> V_1 = V_5 ;
V_192 -> V_75 = V_132 + 1 ;
} else {
V_192 -> V_1 = V_2 ;
V_192 -> V_75 = 0 ;
++ V_192 -> V_193 ;
}
return V_2 ;
}
++ V_132 ;
}
V_172 = F_97 ( V_5 ) ;
if ( V_172 ) {
V_132 = F_42 ( V_5 -> V_24 , V_172 ) + 1 ;
V_5 = V_172 ;
-- V_192 -> V_193 ;
goto V_194;
}
return NULL ;
}
static struct V_1 * F_131 ( struct V_191 * V_192 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 ;
if ( ! V_41 )
return NULL ;
V_2 = F_96 ( V_41 -> V_40 ) ;
if ( ! V_2 )
return NULL ;
if ( F_37 ( V_2 ) ) {
V_192 -> V_1 = V_2 ;
V_192 -> V_75 = 0 ;
V_192 -> V_193 = 1 ;
} else {
V_192 -> V_1 = NULL ;
V_192 -> V_75 = 0 ;
V_192 -> V_193 = 0 ;
}
return V_2 ;
}
static void F_132 ( struct V_40 * V_41 , struct V_195 * V_196 )
{
struct V_1 * V_2 ;
struct V_191 V_192 ;
memset ( V_196 , 0 , sizeof( * V_196 ) ) ;
F_123 () ;
for ( V_2 = F_131 ( & V_192 , V_41 ) ; V_2 ; V_2 = F_130 ( & V_192 ) ) {
if ( F_14 ( V_2 ) ) {
struct V_17 * V_30 ;
V_196 -> V_197 ++ ;
V_196 -> V_198 += V_192 . V_193 ;
if ( V_192 . V_193 > V_196 -> V_199 )
V_196 -> V_199 = V_192 . V_193 ;
F_61 ( V_30 , & V_2 -> V_28 , V_72 )
++ V_196 -> V_200 ;
} else {
V_196 -> V_201 ++ ;
if ( V_2 -> V_6 < V_202 )
V_196 -> V_203 [ V_2 -> V_6 ] ++ ;
V_196 -> V_204 += V_2 -> V_22 ;
}
}
F_124 () ;
}
static void F_133 ( struct V_205 * V_206 , struct V_195 * V_207 )
{
unsigned int V_7 , F_127 , V_208 , V_209 , V_210 ;
if ( V_207 -> V_197 )
V_210 = V_207 -> V_198 * 100 / V_207 -> V_197 ;
else
V_210 = 0 ;
F_134 ( V_206 , L_12 ,
V_210 / 100 , V_210 % 100 ) ;
F_134 ( V_206 , L_13 , V_207 -> V_199 ) ;
F_134 ( V_206 , L_14 , V_207 -> V_197 ) ;
V_209 = sizeof( struct V_1 ) * V_207 -> V_197 ;
F_134 ( V_206 , L_15 , V_207 -> V_200 ) ;
V_209 += sizeof( struct V_17 ) * V_207 -> V_200 ;
F_134 ( V_206 , L_16 , V_207 -> V_201 ) ;
V_209 += sizeof( struct V_1 ) * V_207 -> V_201 ;
F_127 = V_202 ;
while ( F_127 > 0 && V_207 -> V_203 [ F_127 - 1 ] == 0 )
F_127 -- ;
V_208 = 0 ;
for ( V_7 = 1 ; V_7 < F_127 ; V_7 ++ )
if ( V_207 -> V_203 [ V_7 ] != 0 ) {
F_134 ( V_206 , L_17 , V_7 , V_207 -> V_203 [ V_7 ] ) ;
V_208 += ( 1 << V_7 ) * V_207 -> V_203 [ V_7 ] ;
}
F_135 ( V_206 , '\n' ) ;
F_134 ( V_206 , L_18 , V_208 ) ;
V_209 += sizeof( struct V_1 * ) * V_208 ;
F_134 ( V_206 , L_19 , V_207 -> V_204 ) ;
F_134 ( V_206 , L_20 , ( V_209 + 1023 ) / 1024 ) ;
}
static void F_136 ( struct V_205 * V_206 ,
const struct V_129 T_6 * V_65 )
{
struct V_129 V_196 = { 0 } ;
int V_211 ;
F_137 (cpu) {
const struct V_129 * V_212 = F_138 ( V_65 , V_211 ) ;
V_196 . gets += V_212 -> gets ;
V_196 . V_138 += V_212 -> V_138 ;
V_196 . V_145 += V_212 -> V_145 ;
V_196 . V_159 += V_212 -> V_159 ;
V_196 . V_136 += V_212 -> V_136 ;
V_196 . V_66 += V_212 -> V_66 ;
}
F_134 ( V_206 , L_21 ) ;
F_134 ( V_206 , L_22 , V_196 . gets ) ;
F_134 ( V_206 , L_23 , V_196 . V_138 ) ;
F_134 ( V_206 , L_24 ,
V_196 . V_145 ) ;
F_134 ( V_206 , L_25 , V_196 . V_159 ) ;
F_134 ( V_206 , L_26 , V_196 . V_136 ) ;
F_134 ( V_206 , L_27 , V_196 . V_66 ) ;
}
static void F_139 ( struct V_205 * V_206 , struct V_83 * V_84 )
{
if ( V_84 -> V_97 == V_213 )
F_140 ( V_206 , L_28 ) ;
else if ( V_84 -> V_97 == V_214 )
F_140 ( V_206 , L_29 ) ;
else
F_134 ( V_206 , L_30 , V_84 -> V_97 ) ;
}
static int F_141 ( struct V_205 * V_206 , void * V_215 )
{
struct V_216 * V_216 = (struct V_216 * ) V_206 -> V_217 ;
unsigned int V_218 ;
F_134 ( V_206 ,
L_31
L_32 ,
sizeof( struct V_1 ) , sizeof( struct V_1 ) ) ;
for ( V_218 = 0 ; V_218 < V_219 ; V_218 ++ ) {
struct V_67 * V_10 = & V_216 -> V_220 . V_221 [ V_218 ] ;
struct V_83 * V_84 ;
F_61 (tb, head, tb_hlist) {
struct V_40 * V_41 = (struct V_40 * ) V_84 -> V_87 ;
struct V_195 V_207 ;
if ( ! V_41 )
continue;
F_139 ( V_206 , V_84 ) ;
F_132 ( V_41 , & V_207 ) ;
F_133 ( V_206 , & V_207 ) ;
#ifdef F_58
F_136 ( V_206 , V_41 -> V_65 ) ;
#endif
}
}
return 0 ;
}
static int F_142 ( struct V_39 * V_39 , struct V_222 * V_222 )
{
return F_143 ( V_39 , V_222 , F_141 ) ;
}
static struct V_1 * F_144 ( struct V_205 * V_206 , T_9 V_27 )
{
struct V_191 * V_192 = V_206 -> V_217 ;
struct V_216 * V_216 = F_145 ( V_206 ) ;
T_9 V_174 = 0 ;
unsigned int V_218 ;
for ( V_218 = 0 ; V_218 < V_219 ; V_218 ++ ) {
struct V_67 * V_10 = & V_216 -> V_220 . V_221 [ V_218 ] ;
struct V_83 * V_84 ;
F_61 (tb, head, tb_hlist) {
struct V_1 * V_2 ;
for ( V_2 = F_131 ( V_192 ,
(struct V_40 * ) V_84 -> V_87 ) ;
V_2 ; V_2 = F_130 ( V_192 ) )
if ( V_27 == V_174 ++ ) {
V_192 -> V_84 = V_84 ;
return V_2 ;
}
}
}
return NULL ;
}
static void * F_146 ( struct V_205 * V_206 , T_9 * V_27 )
__acquires( T_10 )
{
F_123 () ;
return F_144 ( V_206 , * V_27 ) ;
}
static void * F_147 ( struct V_205 * V_206 , void * V_215 , T_9 * V_27 )
{
struct V_191 * V_192 = V_206 -> V_217 ;
struct V_216 * V_216 = F_145 ( V_206 ) ;
struct V_83 * V_84 = V_192 -> V_84 ;
struct V_70 * V_223 ;
unsigned int V_218 ;
struct V_1 * V_2 ;
++ * V_27 ;
V_2 = F_130 ( V_192 ) ;
if ( V_2 )
return V_2 ;
V_218 = V_84 -> V_97 & ( V_219 - 1 ) ;
while ( ( V_223 = F_96 ( F_148 ( & V_84 -> V_224 ) ) ) ) {
V_84 = F_66 ( V_223 , struct V_83 , V_224 ) ;
V_2 = F_131 ( V_192 , (struct V_40 * ) V_84 -> V_87 ) ;
if ( V_2 )
goto V_134;
}
while ( ++ V_218 < V_219 ) {
struct V_67 * V_10 = & V_216 -> V_220 . V_221 [ V_218 ] ;
F_61 (tb, head, tb_hlist) {
V_2 = F_131 ( V_192 , (struct V_40 * ) V_84 -> V_87 ) ;
if ( V_2 )
goto V_134;
}
}
return NULL ;
V_134:
V_192 -> V_84 = V_84 ;
return V_2 ;
}
static void F_149 ( struct V_205 * V_206 , void * V_215 )
__releases( T_10 )
{
F_124 () ;
}
static void F_150 ( struct V_205 * V_206 , int V_2 )
{
while ( V_2 -- > 0 )
F_140 ( V_206 , L_33 ) ;
}
static inline const char * F_151 ( char * V_225 , T_1 V_186 , enum V_226 V_196 )
{
switch ( V_196 ) {
case V_227 : return L_34 ;
case V_228 : return L_35 ;
case V_229 : return L_36 ;
case V_230 : return L_37 ;
case V_163 : return L_38 ;
default:
snprintf ( V_225 , V_186 , L_39 , V_196 ) ;
return V_225 ;
}
}
static inline const char * F_152 ( char * V_225 , T_1 V_186 , unsigned int V_41 )
{
if ( V_41 < V_231 && V_232 [ V_41 ] )
return V_232 [ V_41 ] ;
snprintf ( V_225 , V_186 , L_40 , V_41 ) ;
return V_225 ;
}
static int F_153 ( struct V_205 * V_206 , void * V_215 )
{
const struct V_191 * V_192 = V_206 -> V_217 ;
struct V_1 * V_2 = V_215 ;
if ( ! F_97 ( V_2 ) )
F_139 ( V_206 , V_192 -> V_84 ) ;
if ( F_37 ( V_2 ) ) {
T_7 V_233 = F_91 ( V_2 -> V_24 ) ;
F_150 ( V_206 , V_192 -> V_193 - 1 ) ;
F_134 ( V_206 , L_41 ,
& V_233 , V_35 - V_2 -> V_27 - V_2 -> V_6 , V_2 -> V_6 ,
V_2 -> V_23 , V_2 -> V_22 ) ;
} else {
struct V_17 * V_30 ;
T_7 V_234 = F_91 ( V_2 -> V_24 ) ;
F_150 ( V_206 , V_192 -> V_193 ) ;
F_134 ( V_206 , L_42 , & V_234 ) ;
F_61 (li, &n->list, hlist) {
struct V_11 * V_12 ;
F_98 (fa, &li->falh, fa_list) {
char V_235 [ 32 ] , V_236 [ 32 ] ;
F_150 ( V_206 , V_192 -> V_193 + 1 ) ;
F_134 ( V_206 , L_43 , V_30 -> V_29 ,
F_151 ( V_235 , sizeof( V_235 ) ,
V_12 -> V_80 -> V_142 ) ,
F_152 ( V_236 , sizeof( V_236 ) ,
V_12 -> V_106 ) ) ;
if ( V_12 -> V_79 )
F_134 ( V_206 , L_44 , V_12 -> V_79 ) ;
F_135 ( V_206 , '\n' ) ;
}
}
}
return 0 ;
}
static int F_154 ( struct V_39 * V_39 , struct V_222 * V_222 )
{
return F_155 ( V_39 , V_222 , & V_237 ,
sizeof( struct V_191 ) ) ;
}
static struct V_1 * F_156 ( struct V_238 * V_192 , T_9 V_27 )
{
struct V_1 * V_25 = NULL ;
struct V_40 * V_41 = V_192 -> V_239 ;
if ( V_192 -> V_27 > 0 && V_27 >= V_192 -> V_27 && ( V_25 = F_75 ( V_41 , V_192 -> V_24 ) ) )
V_27 -= V_192 -> V_27 ;
else {
V_192 -> V_27 = 0 ;
V_25 = F_112 ( V_41 ) ;
}
while ( V_25 && V_27 -- > 0 ) {
V_192 -> V_27 ++ ;
V_25 = F_113 ( V_25 ) ;
}
if ( V_25 )
V_192 -> V_24 = V_27 ;
else
V_192 -> V_27 = 0 ;
return V_25 ;
}
static void * F_157 ( struct V_205 * V_206 , T_9 * V_27 )
__acquires( T_10 )
{
struct V_238 * V_192 = V_206 -> V_217 ;
struct V_83 * V_84 ;
F_123 () ;
V_84 = F_158 ( F_145 ( V_206 ) , V_214 ) ;
if ( ! V_84 )
return NULL ;
V_192 -> V_239 = (struct V_40 * ) V_84 -> V_87 ;
if ( * V_27 == 0 )
return V_240 ;
else
return F_156 ( V_192 , * V_27 - 1 ) ;
}
static void * F_159 ( struct V_205 * V_206 , void * V_215 , T_9 * V_27 )
{
struct V_238 * V_192 = V_206 -> V_217 ;
struct V_1 * V_25 = V_215 ;
++ * V_27 ;
if ( V_215 == V_240 ) {
V_192 -> V_27 = 0 ;
V_25 = F_112 ( V_192 -> V_239 ) ;
} else {
V_192 -> V_27 ++ ;
V_25 = F_113 ( V_25 ) ;
}
if ( V_25 )
V_192 -> V_24 = V_25 -> V_24 ;
else
V_192 -> V_27 = 0 ;
return V_25 ;
}
static void F_160 ( struct V_205 * V_206 , void * V_215 )
__releases( T_10 )
{
F_124 () ;
}
static unsigned int F_161 ( int type , T_7 V_93 , const struct V_89 * V_90 )
{
unsigned int V_241 = 0 ;
if ( type == V_242 || type == V_243 )
V_241 = V_244 ;
if ( V_90 && V_90 -> V_148 -> V_245 )
V_241 |= V_246 ;
if ( V_93 == F_91 ( 0xFFFFFFFF ) )
V_241 |= V_247 ;
V_241 |= V_248 ;
return V_241 ;
}
static int F_162 ( struct V_205 * V_206 , void * V_215 )
{
struct V_1 * V_25 = V_215 ;
struct V_17 * V_30 ;
if ( V_215 == V_240 ) {
F_134 ( V_206 , L_45 , L_46
L_47
L_48 ) ;
return 0 ;
}
F_61 (li, &l->list, hlist) {
struct V_11 * V_12 ;
T_7 V_93 , V_123 ;
V_93 = F_30 ( V_30 -> V_29 ) ;
V_123 = F_91 ( V_25 -> V_24 ) ;
F_98 (fa, &li->falh, fa_list) {
const struct V_89 * V_90 = V_12 -> V_80 ;
unsigned int V_241 = F_161 ( V_12 -> V_106 , V_93 , V_90 ) ;
if ( V_12 -> V_106 == V_249
|| V_12 -> V_106 == V_250 )
continue;
F_163 ( V_206 , 127 ) ;
if ( V_90 )
F_134 ( V_206 ,
L_49
L_50 ,
V_90 -> V_251 ? V_90 -> V_251 -> V_252 : L_51 ,
V_123 ,
V_90 -> V_148 -> V_245 , V_241 , 0 , 0 ,
V_90 -> V_81 ,
V_93 ,
( V_90 -> V_253 ?
V_90 -> V_253 + 40 : 0 ) ,
V_90 -> V_254 ,
V_90 -> V_255 >> 3 ) ;
else
F_134 ( V_206 ,
L_52
L_50 ,
V_123 , 0 , V_241 , 0 , 0 , 0 ,
V_93 , 0 , 0 , 0 ) ;
F_164 ( V_206 , '\n' ) ;
}
}
return 0 ;
}
static int F_165 ( struct V_39 * V_39 , struct V_222 * V_222 )
{
return F_155 ( V_39 , V_222 , & V_256 ,
sizeof( struct V_238 ) ) ;
}
int T_11 F_166 ( struct V_216 * V_216 )
{
if ( ! F_167 ( L_53 , V_257 , V_216 -> V_258 , & V_259 ) )
goto V_260;
if ( ! F_167 ( L_54 , V_257 , V_216 -> V_258 ,
& V_261 ) )
goto V_262;
if ( ! F_167 ( L_55 , V_257 , V_216 -> V_258 , & V_263 ) )
goto V_264;
return 0 ;
V_264:
F_168 ( L_54 , V_216 -> V_258 ) ;
V_262:
F_168 ( L_53 , V_216 -> V_258 ) ;
V_260:
return - V_48 ;
}
void T_12 F_169 ( struct V_216 * V_216 )
{
F_168 ( L_53 , V_216 -> V_258 ) ;
F_168 ( L_54 , V_216 -> V_258 ) ;
F_168 ( L_55 , V_216 -> V_258 ) ;
}
