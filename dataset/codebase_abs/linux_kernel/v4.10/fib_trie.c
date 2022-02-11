static unsigned int F_1 ( void )
{
unsigned int V_1 = 0 ;
struct V_2 * V_2 ;
F_2 () ;
F_3 (net)
V_1 += V_2 -> V_3 . V_1 ;
F_4 () ;
return V_1 ;
}
static int F_5 ( struct V_4 * V_5 , struct V_2 * V_2 ,
enum V_6 V_7 ,
struct V_8 * V_9 )
{
V_9 -> V_2 = V_2 ;
return V_5 -> V_10 ( V_5 , V_7 , V_9 ) ;
}
static void F_6 ( struct V_2 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 )
{
#ifdef F_7
struct V_8 V_9 ;
if ( V_2 -> V_3 . V_11 )
F_5 ( V_5 , V_2 , V_7 , & V_9 ) ;
#endif
}
static int F_8 ( struct V_4 * V_5 , struct V_2 * V_2 ,
enum V_6 V_7 , T_1 V_12 ,
int V_13 , struct V_14 * V_15 ,
T_2 V_16 , T_2 type , T_1 V_17 , T_1 V_18 )
{
struct V_19 V_9 = {
. V_12 = V_12 ,
. V_13 = V_13 ,
. V_15 = V_15 ,
. V_16 = V_16 ,
. type = type ,
. V_17 = V_17 ,
. V_18 = V_18 ,
} ;
return F_5 ( V_5 , V_2 , V_7 , & V_9 . V_9 ) ;
}
static bool F_9 ( struct V_4 * V_5 ,
void (* F_10)( struct V_4 * V_5 ) ,
unsigned int V_1 )
{
F_11 ( & V_20 , V_5 ) ;
if ( V_1 == F_1 () )
return true ;
F_12 ( & V_20 , V_5 ) ;
if ( F_10 )
F_10 ( V_5 ) ;
return false ;
}
int F_13 ( struct V_4 * V_5 ,
void (* F_10)( struct V_4 * V_5 ) )
{
int V_21 = 0 ;
do {
unsigned int V_1 = F_1 () ;
struct V_2 * V_2 ;
F_14 () ;
F_15 (net) {
F_6 ( V_2 , V_5 , V_22 ) ;
F_16 ( V_2 , V_5 , V_23 ) ;
}
F_17 () ;
if ( F_9 ( V_5 , F_10 , V_1 ) )
return 0 ;
} while ( ++ V_21 < V_24 );
return - V_25 ;
}
int F_18 ( struct V_4 * V_5 )
{
return F_12 ( & V_20 , V_5 ) ;
}
int F_19 ( struct V_2 * V_2 , enum V_6 V_7 ,
struct V_8 * V_9 )
{
V_2 -> V_3 . V_1 ++ ;
V_9 -> V_2 = V_2 ;
return F_20 ( & V_20 , V_7 , V_9 ) ;
}
static int F_21 ( struct V_2 * V_2 ,
enum V_6 V_7 , T_1 V_12 ,
int V_13 , struct V_14 * V_15 ,
T_2 V_16 , T_2 type , T_1 V_17 , T_1 V_18 )
{
struct V_19 V_9 = {
. V_12 = V_12 ,
. V_13 = V_13 ,
. V_15 = V_15 ,
. V_16 = V_16 ,
. type = type ,
. V_17 = V_17 ,
. V_18 = V_18 ,
} ;
return F_19 ( V_2 , V_7 , & V_9 . V_9 ) ;
}
static inline struct V_26 * F_22 ( struct V_27 * V_28 )
{
return F_23 ( V_28 , struct V_26 , V_28 [ 0 ] ) ;
}
static inline void F_24 ( struct V_27 * V_29 , struct V_27 * V_30 )
{
if ( V_29 )
F_25 ( F_22 ( V_29 ) -> V_31 , V_30 ) ;
}
static inline unsigned long F_26 ( const struct V_27 * V_32 )
{
return ( 1ul << V_32 -> V_33 ) & ~ ( 1ul ) ;
}
static inline unsigned long F_27 ( T_3 V_34 , struct V_27 * V_28 )
{
unsigned long V_35 = V_34 ^ V_28 -> V_34 ;
if ( ( V_36 <= V_37 ) && ( V_37 == V_28 -> V_38 ) )
return 0 ;
return V_35 >> V_28 -> V_38 ;
}
static void F_28 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = F_23 ( V_40 , struct V_41 , V_43 ) ;
F_29 ( V_44 , V_42 ) ;
}
static inline void F_30 ( struct V_41 * V_42 )
{
F_31 ( & V_42 -> V_43 , F_28 ) ;
}
static void F_32 ( struct V_39 * V_40 )
{
struct V_26 * V_29 = F_23 ( V_40 , struct V_26 , V_43 ) ;
if ( ! V_29 -> V_45 )
F_29 ( V_46 , V_29 ) ;
else
F_33 ( V_29 ) ;
}
static struct V_26 * F_34 ( int V_33 )
{
T_4 V_47 ;
if ( V_33 > V_48 )
return NULL ;
V_47 = F_35 ( 1ul << V_33 ) ;
if ( V_47 <= V_49 )
return F_36 ( V_47 , V_50 ) ;
else
return F_37 ( V_47 ) ;
}
static inline void F_38 ( struct V_27 * V_29 )
{
++ F_22 ( V_29 ) -> V_51 ? : ++ F_22 ( V_29 ) -> V_52 ;
}
static inline void F_39 ( struct V_27 * V_29 )
{
F_22 ( V_29 ) -> V_51 -- ? : F_22 ( V_29 ) -> V_52 -- ;
}
static struct V_27 * F_40 ( T_3 V_34 , struct V_41 * V_42 )
{
struct V_27 * V_53 ;
struct V_26 * V_28 ;
V_28 = F_41 ( V_46 , V_50 ) ;
if ( ! V_28 )
return NULL ;
V_53 = V_28 -> V_28 ;
V_53 -> V_34 = V_34 ;
V_53 -> V_38 = 0 ;
V_53 -> V_33 = 0 ;
V_53 -> V_54 = V_42 -> V_55 ;
F_42 ( & V_53 -> V_56 ) ;
F_43 ( & V_42 -> V_57 , & V_53 -> V_56 ) ;
return V_53 ;
}
static struct V_27 * F_44 ( T_3 V_34 , int V_38 , int V_33 )
{
unsigned int V_58 = V_38 + V_33 ;
struct V_27 * V_32 ;
struct V_26 * V_26 ;
F_45 ( ! V_33 || ( V_58 > V_37 ) ) ;
V_26 = F_34 ( V_33 ) ;
if ( ! V_26 )
return NULL ;
F_46 ( L_1 , V_26 , F_35 ( 0 ) ,
sizeof( struct V_27 * ) << V_33 ) ;
if ( V_33 == V_37 )
V_26 -> V_52 = 1 ;
else
V_26 -> V_51 = 1ul << V_33 ;
V_32 = V_26 -> V_28 ;
V_32 -> V_34 = ( V_58 < V_37 ) ? ( V_34 >> V_58 ) << V_58 : 0 ;
V_32 -> V_38 = V_38 ;
V_32 -> V_33 = V_33 ;
V_32 -> V_54 = V_38 ;
return V_32 ;
}
static inline int F_47 ( struct V_27 * V_32 , struct V_27 * V_29 )
{
return V_29 && ( ( V_29 -> V_38 + V_29 -> V_33 ) == V_32 -> V_38 ) && F_48 ( V_29 ) ;
}
static void F_49 ( struct V_27 * V_32 , unsigned long V_59 ,
struct V_27 * V_29 )
{
struct V_27 * V_60 = F_50 ( V_32 , V_59 ) ;
int V_61 , V_62 ;
F_45 ( V_59 >= F_26 ( V_32 ) ) ;
if ( ! V_29 && V_60 )
F_38 ( V_32 ) ;
if ( V_29 && ! V_60 )
F_39 ( V_32 ) ;
V_62 = F_47 ( V_32 , V_60 ) ;
V_61 = F_47 ( V_32 , V_29 ) ;
if ( V_62 && ! V_61 )
F_22 ( V_32 ) -> V_52 -- ;
else if ( ! V_62 && V_61 )
F_22 ( V_32 ) -> V_52 ++ ;
if ( V_29 && ( V_32 -> V_54 < V_29 -> V_54 ) )
V_32 -> V_54 = V_29 -> V_54 ;
F_25 ( V_32 -> V_26 [ V_59 ] , V_29 ) ;
}
static void F_51 ( struct V_27 * V_32 )
{
unsigned long V_59 ;
for ( V_59 = F_26 ( V_32 ) ; V_59 ; ) {
struct V_27 * V_63 = F_50 ( V_32 , -- V_59 ) ;
if ( ! V_63 )
continue;
if ( F_52 ( V_63 ) == V_32 )
F_51 ( V_63 ) ;
else
F_24 ( V_63 , V_32 ) ;
}
}
static inline void F_53 ( struct V_27 * V_30 , T_3 V_34 ,
struct V_27 * V_29 )
{
if ( F_54 ( V_30 ) )
F_25 ( V_30 -> V_26 [ 0 ] , V_29 ) ;
else
F_49 ( V_30 , F_27 ( V_34 , V_30 ) , V_29 ) ;
}
static inline void F_55 ( struct V_27 * V_32 )
{
F_22 ( V_32 ) -> V_43 . V_64 = NULL ;
}
static inline void F_56 ( struct V_27 * V_32 ,
struct V_27 * V_29 )
{
F_22 ( V_29 ) -> V_43 . V_64 = F_22 ( V_32 ) -> V_43 . V_64 ;
F_22 ( V_32 ) -> V_43 . V_64 = & F_22 ( V_29 ) -> V_43 ;
}
static void F_57 ( struct V_27 * V_32 )
{
struct V_65 * V_40 = & F_22 ( V_32 ) -> V_43 ;
while ( V_40 ) {
V_40 = V_40 -> V_64 ;
V_66 += F_35 ( 1ul << V_32 -> V_33 ) ;
F_58 ( V_32 ) ;
V_32 = F_23 ( V_40 , struct V_26 , V_43 ) -> V_28 ;
}
if ( V_66 >= V_49 * V_67 ) {
V_66 = 0 ;
F_59 () ;
}
}
static struct V_27 * F_60 ( struct V_68 * V_69 ,
struct V_27 * V_70 ,
struct V_27 * V_32 )
{
struct V_27 * V_30 = F_52 ( V_70 ) ;
unsigned long V_59 ;
F_61 ( V_32 , V_30 ) ;
F_53 ( V_30 , V_32 -> V_34 , V_32 ) ;
F_51 ( V_32 ) ;
F_57 ( V_70 ) ;
for ( V_59 = F_26 ( V_32 ) ; V_59 ; ) {
struct V_27 * V_63 = F_50 ( V_32 , -- V_59 ) ;
if ( F_47 ( V_32 , V_63 ) )
V_32 = F_62 ( V_69 , V_63 ) ;
}
return V_30 ;
}
static struct V_27 * F_63 ( struct V_68 * V_69 ,
struct V_27 * V_70 )
{
struct V_27 * V_32 ;
unsigned long V_59 ;
T_3 V_71 ;
F_46 ( L_2 ) ;
V_32 = F_44 ( V_70 -> V_34 , V_70 -> V_38 - 1 , V_70 -> V_33 + 1 ) ;
if ( ! V_32 )
goto V_72;
F_55 ( V_70 ) ;
for ( V_59 = F_26 ( V_70 ) , V_71 = 1u << V_32 -> V_38 ; V_59 ; ) {
struct V_27 * V_63 = F_50 ( V_70 , -- V_59 ) ;
struct V_27 * V_73 , * V_74 ;
unsigned long V_75 , V_76 ;
if ( ! V_63 )
continue;
if ( ! F_47 ( V_70 , V_63 ) ) {
F_49 ( V_32 , F_27 ( V_63 -> V_34 , V_32 ) , V_63 ) ;
continue;
}
F_56 ( V_70 , V_63 ) ;
if ( V_63 -> V_33 == 1 ) {
F_49 ( V_32 , 2 * V_59 + 1 , F_50 ( V_63 , 1 ) ) ;
F_49 ( V_32 , 2 * V_59 , F_50 ( V_63 , 0 ) ) ;
continue;
}
V_74 = F_44 ( V_63 -> V_34 | V_71 , V_63 -> V_38 , V_63 -> V_33 - 1 ) ;
if ( ! V_74 )
goto V_77;
V_73 = F_44 ( V_63 -> V_34 , V_63 -> V_38 , V_63 -> V_33 - 1 ) ;
F_56 ( V_32 , V_74 ) ;
if ( ! V_73 )
goto V_77;
F_56 ( V_32 , V_73 ) ;
for ( V_76 = F_26 ( V_63 ) , V_75 = V_76 / 2 ; V_75 ; ) {
F_49 ( V_74 , -- V_75 , F_50 ( V_63 , -- V_76 ) ) ;
F_49 ( V_73 , V_75 , F_50 ( V_63 , V_75 ) ) ;
F_49 ( V_74 , -- V_75 , F_50 ( V_63 , -- V_76 ) ) ;
F_49 ( V_73 , V_75 , F_50 ( V_63 , V_75 ) ) ;
}
F_61 ( V_74 , V_32 ) ;
F_61 ( V_73 , V_32 ) ;
F_49 ( V_32 , 2 * V_59 + 1 , V_74 ) ;
F_49 ( V_32 , 2 * V_59 , V_73 ) ;
}
return F_60 ( V_69 , V_70 , V_32 ) ;
V_77:
F_57 ( V_32 ) ;
V_72:
return NULL ;
}
static struct V_27 * F_64 ( struct V_68 * V_69 ,
struct V_27 * V_70 )
{
struct V_27 * V_32 ;
unsigned long V_59 ;
F_46 ( L_3 ) ;
V_32 = F_44 ( V_70 -> V_34 , V_70 -> V_38 + 1 , V_70 -> V_33 - 1 ) ;
if ( ! V_32 )
goto V_72;
F_55 ( V_70 ) ;
for ( V_59 = F_26 ( V_70 ) ; V_59 ; ) {
struct V_27 * V_74 = F_50 ( V_70 , -- V_59 ) ;
struct V_27 * V_73 = F_50 ( V_70 , -- V_59 ) ;
struct V_27 * V_63 ;
if ( ! V_74 || ! V_73 ) {
F_49 ( V_32 , V_59 / 2 , V_74 ? : V_73 ) ;
continue;
}
V_63 = F_44 ( V_73 -> V_34 , V_70 -> V_38 , 1 ) ;
if ( ! V_63 )
goto V_77;
F_56 ( V_32 , V_63 ) ;
F_49 ( V_63 , 1 , V_74 ) ;
F_49 ( V_63 , 0 , V_73 ) ;
F_61 ( V_63 , V_32 ) ;
F_49 ( V_32 , V_59 / 2 , V_63 ) ;
}
return F_60 ( V_69 , V_70 , V_32 ) ;
V_77:
F_57 ( V_32 ) ;
V_72:
return NULL ;
}
static struct V_27 * F_65 ( struct V_68 * V_69 ,
struct V_27 * V_70 )
{
struct V_27 * V_29 , * V_30 ;
unsigned long V_59 ;
for ( V_29 = NULL , V_59 = F_26 ( V_70 ) ; ! V_29 && V_59 ; )
V_29 = F_50 ( V_70 , -- V_59 ) ;
V_30 = F_52 ( V_70 ) ;
F_53 ( V_30 , V_70 -> V_34 , V_29 ) ;
F_24 ( V_29 , V_30 ) ;
F_58 ( V_70 ) ;
return V_30 ;
}
static unsigned char F_66 ( struct V_27 * V_32 )
{
unsigned char V_54 = V_32 -> V_38 ;
unsigned long V_78 , V_59 ;
unsigned char V_79 ;
V_79 = F_67 (unsigned char, tn->pos + tn->bits - 1 , tn->slen) ;
for ( V_59 = 0 , V_78 = 0x2ul ; V_59 < F_26 ( V_32 ) ; V_59 += V_78 ) {
struct V_27 * V_29 = F_50 ( V_32 , V_59 ) ;
if ( ! V_29 || ( V_29 -> V_54 <= V_54 ) )
continue;
V_78 <<= ( V_29 -> V_54 - V_54 ) ;
V_54 = V_29 -> V_54 ;
V_59 &= ~ ( V_78 - 1 ) ;
if ( V_54 >= V_79 )
break;
}
V_32 -> V_54 = V_54 ;
return V_54 ;
}
static inline bool F_68 ( struct V_27 * V_30 , struct V_27 * V_32 )
{
unsigned long V_80 = F_26 ( V_32 ) ;
unsigned long V_81 = V_80 ;
V_81 *= F_54 ( V_30 ) ? V_82 : V_83 ;
V_80 -= F_22 ( V_32 ) -> V_51 ;
V_80 += F_22 ( V_32 ) -> V_52 ;
return ( V_80 > 1 ) && V_32 -> V_38 && ( ( 50 * V_80 ) >= V_81 ) ;
}
static inline bool F_69 ( struct V_27 * V_30 , struct V_27 * V_32 )
{
unsigned long V_80 = F_26 ( V_32 ) ;
unsigned long V_81 = V_80 ;
V_81 *= F_54 ( V_30 ) ? V_84 : V_85 ;
V_80 -= F_22 ( V_32 ) -> V_51 ;
return ( V_80 > 1 ) && ( V_32 -> V_33 > 1 ) && ( ( 100 * V_80 ) < V_81 ) ;
}
static inline bool F_70 ( struct V_27 * V_32 )
{
unsigned long V_80 = F_26 ( V_32 ) ;
V_80 -= F_22 ( V_32 ) -> V_51 ;
if ( ( V_32 -> V_33 == V_37 ) && F_22 ( V_32 ) -> V_52 )
V_80 -= V_86 ;
return V_80 < 2 ;
}
static struct V_27 * F_62 ( struct V_68 * V_69 , struct V_27 * V_32 )
{
#ifdef F_71
struct V_87 T_5 * V_88 = V_69 -> V_88 ;
#endif
struct V_27 * V_30 = F_52 ( V_32 ) ;
unsigned long V_89 = F_27 ( V_32 -> V_34 , V_30 ) ;
int V_90 = V_91 ;
F_46 ( L_4 ,
V_32 , V_83 , V_85 ) ;
F_45 ( V_32 != F_50 ( V_30 , V_89 ) ) ;
while ( F_68 ( V_30 , V_32 ) && V_90 ) {
V_30 = F_63 ( V_69 , V_32 ) ;
if ( ! V_30 ) {
#ifdef F_71
F_72 ( V_88 -> V_92 ) ;
#endif
break;
}
V_90 -- ;
V_32 = F_50 ( V_30 , V_89 ) ;
}
V_30 = F_52 ( V_32 ) ;
if ( V_90 != V_91 )
return V_30 ;
while ( F_69 ( V_30 , V_32 ) && V_90 ) {
V_30 = F_64 ( V_69 , V_32 ) ;
if ( ! V_30 ) {
#ifdef F_71
F_72 ( V_88 -> V_92 ) ;
#endif
break;
}
V_90 -- ;
V_32 = F_50 ( V_30 , V_89 ) ;
}
if ( F_70 ( V_32 ) )
return F_65 ( V_69 , V_32 ) ;
return F_52 ( V_32 ) ;
}
static void F_73 ( struct V_27 * V_32 , unsigned char V_54 )
{
unsigned char V_93 = V_32 -> V_54 ;
while ( ( V_93 > V_32 -> V_38 ) && ( V_93 > V_54 ) ) {
V_54 = F_66 ( V_32 ) ;
if ( V_93 == V_54 )
break;
V_32 = F_52 ( V_32 ) ;
V_93 = V_32 -> V_54 ;
}
}
static void F_74 ( struct V_27 * V_32 , unsigned char V_54 )
{
while ( V_32 -> V_54 < V_54 ) {
V_32 -> V_54 = V_54 ;
V_32 = F_52 ( V_32 ) ;
}
}
static struct V_27 * F_75 ( struct V_68 * V_69 ,
struct V_27 * * V_30 , T_1 V_34 )
{
struct V_27 * V_94 , * V_29 = V_69 -> V_28 ;
unsigned long V_35 = 0 ;
do {
V_94 = V_29 ;
V_29 = F_76 ( V_29 , V_35 ) ;
if ( ! V_29 )
break;
V_35 = F_77 ( V_34 , V_29 ) ;
if ( V_35 >= ( 1ul << V_29 -> V_33 ) ) {
V_29 = NULL ;
break;
}
} while ( F_48 ( V_29 ) );
* V_30 = V_94 ;
return V_29 ;
}
static struct V_41 * F_78 ( struct V_95 * V_96 , T_2 V_54 ,
T_2 V_16 , T_1 V_97 , T_1 V_17 )
{
struct V_41 * V_42 ;
if ( ! V_96 )
return NULL ;
F_79 (fa, fah, fa_list) {
if ( V_42 -> V_55 < V_54 )
continue;
if ( V_42 -> V_55 != V_54 )
break;
if ( V_42 -> V_17 > V_17 )
continue;
if ( V_42 -> V_17 != V_17 )
break;
if ( V_42 -> V_98 > V_16 )
continue;
if ( V_42 -> V_99 -> V_100 >= V_97 || V_42 -> V_98 < V_16 )
return V_42 ;
}
return NULL ;
}
static void F_80 ( struct V_68 * V_69 , struct V_27 * V_32 )
{
while ( ! F_54 ( V_32 ) )
V_32 = F_62 ( V_69 , V_32 ) ;
}
static int F_81 ( struct V_68 * V_69 , struct V_27 * V_30 ,
struct V_41 * V_101 , T_3 V_34 )
{
struct V_27 * V_29 , * V_53 ;
V_53 = F_40 ( V_34 , V_101 ) ;
if ( ! V_53 )
goto V_102;
V_29 = F_50 ( V_30 , F_27 ( V_34 , V_30 ) ) ;
if ( V_29 ) {
struct V_27 * V_32 ;
V_32 = F_44 ( V_34 , F_82 ( V_34 ^ V_29 -> V_34 ) , 1 ) ;
if ( ! V_32 )
goto V_72;
F_61 ( V_32 , V_30 ) ;
F_49 ( V_32 , F_27 ( V_34 , V_32 ) ^ 1 , V_29 ) ;
F_53 ( V_30 , V_34 , V_32 ) ;
F_24 ( V_29 , V_32 ) ;
V_30 = V_32 ;
}
F_74 ( V_30 , V_101 -> V_55 ) ;
F_61 ( V_53 , V_30 ) ;
F_53 ( V_30 , V_34 , V_53 ) ;
F_80 ( V_69 , V_30 ) ;
return 0 ;
V_72:
F_58 ( V_53 ) ;
V_102:
return - V_103 ;
}
static int F_83 ( struct V_68 * V_69 , struct V_27 * V_30 ,
struct V_27 * V_53 , struct V_41 * V_101 ,
struct V_41 * V_42 , T_3 V_34 )
{
if ( ! V_53 )
return F_81 ( V_69 , V_30 , V_101 , V_34 ) ;
if ( V_42 ) {
F_84 ( & V_101 -> V_57 , & V_42 -> V_57 ) ;
} else {
struct V_41 * V_104 ;
F_79 (last, &l->leaf, fa_list) {
if ( V_101 -> V_55 < V_104 -> V_55 )
break;
if ( ( V_101 -> V_55 == V_104 -> V_55 ) &&
( V_101 -> V_17 > V_104 -> V_17 ) )
break;
V_42 = V_104 ;
}
if ( V_42 )
F_85 ( & V_101 -> V_57 , & V_42 -> V_57 ) ;
else
F_86 ( & V_101 -> V_57 , & V_53 -> V_56 ) ;
}
if ( V_53 -> V_54 < V_101 -> V_55 ) {
V_53 -> V_54 = V_101 -> V_55 ;
F_74 ( V_30 , V_101 -> V_55 ) ;
}
return 0 ;
}
int F_87 ( struct V_2 * V_2 , struct V_105 * V_106 ,
struct V_107 * V_108 )
{
struct V_68 * V_69 = (struct V_68 * ) V_106 -> V_109 ;
struct V_41 * V_42 , * V_110 ;
struct V_27 * V_53 , * V_30 ;
T_6 V_18 = V_111 ;
struct V_14 * V_15 ;
T_2 V_112 = V_108 -> V_113 ;
T_2 V_54 = V_37 - V_112 ;
T_2 V_16 = V_108 -> V_114 ;
T_1 V_34 ;
int V_115 ;
if ( V_112 > V_37 )
return - V_116 ;
V_34 = F_88 ( V_108 -> V_117 ) ;
F_46 ( L_5 , V_106 -> V_17 , V_34 , V_112 ) ;
if ( ( V_112 < V_37 ) && ( V_34 << V_112 ) )
return - V_116 ;
V_15 = F_89 ( V_108 ) ;
if ( F_90 ( V_15 ) ) {
V_115 = F_91 ( V_15 ) ;
goto V_115;
}
V_53 = F_75 ( V_69 , & V_30 , V_34 ) ;
V_42 = V_53 ? F_78 ( & V_53 -> V_56 , V_54 , V_16 , V_15 -> V_100 ,
V_106 -> V_17 ) : NULL ;
if ( V_42 && V_42 -> V_98 == V_16 &&
V_42 -> V_99 -> V_100 == V_15 -> V_100 ) {
struct V_41 * V_118 , * V_119 ;
V_115 = - V_120 ;
if ( V_108 -> V_121 & V_111 )
goto V_122;
V_18 &= ~ V_111 ;
V_119 = NULL ;
V_118 = V_42 ;
F_92 (fa, fa_list) {
if ( ( V_42 -> V_55 != V_54 ) ||
( V_42 -> V_17 != V_106 -> V_17 ) ||
( V_42 -> V_98 != V_16 ) )
break;
if ( V_42 -> V_99 -> V_100 != V_15 -> V_100 )
break;
if ( V_42 -> V_123 == V_108 -> V_124 &&
V_42 -> V_99 == V_15 ) {
V_119 = V_42 ;
break;
}
}
if ( V_108 -> V_121 & V_125 ) {
struct V_14 * V_126 ;
T_2 V_127 ;
V_18 |= V_125 ;
V_42 = V_118 ;
if ( V_119 ) {
if ( V_42 == V_119 )
V_115 = 0 ;
goto V_122;
}
V_115 = - V_128 ;
V_110 = F_41 ( V_44 , V_50 ) ;
if ( ! V_110 )
goto V_122;
V_126 = V_42 -> V_99 ;
V_110 -> V_98 = V_42 -> V_98 ;
V_110 -> V_99 = V_15 ;
V_110 -> V_123 = V_108 -> V_124 ;
V_127 = V_42 -> V_129 ;
V_110 -> V_129 = V_127 & ~ V_130 ;
V_110 -> V_55 = V_42 -> V_55 ;
V_110 -> V_17 = V_106 -> V_17 ;
V_110 -> V_131 = - 1 ;
F_93 ( & V_42 -> V_57 , & V_110 -> V_57 ) ;
F_30 ( V_42 ) ;
F_94 ( V_126 ) ;
if ( V_127 & V_130 )
F_95 ( V_108 -> V_132 . V_133 ) ;
F_21 ( V_2 , V_23 ,
V_34 , V_112 , V_15 ,
V_110 -> V_98 , V_108 -> V_124 ,
V_106 -> V_17 , V_108 -> V_121 ) ;
F_96 ( V_134 , F_97 ( V_34 ) , V_110 , V_112 ,
V_106 -> V_17 , & V_108 -> V_132 , V_18 ) ;
goto V_135;
}
if ( V_119 )
goto V_122;
if ( V_108 -> V_121 & V_136 )
V_18 |= V_136 ;
else
V_42 = V_118 ;
}
V_115 = - V_137 ;
if ( ! ( V_108 -> V_121 & V_138 ) )
goto V_122;
V_18 |= V_138 ;
V_115 = - V_128 ;
V_110 = F_41 ( V_44 , V_50 ) ;
if ( ! V_110 )
goto V_122;
V_110 -> V_99 = V_15 ;
V_110 -> V_98 = V_16 ;
V_110 -> V_123 = V_108 -> V_124 ;
V_110 -> V_129 = 0 ;
V_110 -> V_55 = V_54 ;
V_110 -> V_17 = V_106 -> V_17 ;
V_110 -> V_131 = - 1 ;
V_115 = F_83 ( V_69 , V_30 , V_53 , V_110 , V_42 , V_34 ) ;
if ( V_115 )
goto V_139;
if ( ! V_112 )
V_106 -> V_140 ++ ;
F_95 ( V_108 -> V_132 . V_133 ) ;
F_21 ( V_2 , V_23 , V_34 , V_112 , V_15 , V_16 ,
V_108 -> V_124 , V_106 -> V_17 , V_108 -> V_121 ) ;
F_96 ( V_134 , F_97 ( V_34 ) , V_110 , V_112 , V_110 -> V_17 ,
& V_108 -> V_132 , V_18 ) ;
V_135:
return 0 ;
V_139:
F_29 ( V_44 , V_110 ) ;
V_122:
F_94 ( V_15 ) ;
V_115:
return V_115 ;
}
static inline T_3 F_98 ( T_3 V_34 , struct V_27 * V_29 )
{
T_3 V_141 = V_29 -> V_34 ;
return ( V_34 ^ V_141 ) & ( V_141 | - V_141 ) ;
}
int F_99 ( struct V_105 * V_106 , const struct V_142 * V_143 ,
struct V_144 * V_145 , int V_146 )
{
struct V_68 * V_69 = (struct V_68 * ) V_106 -> V_109 ;
#ifdef F_71
struct V_87 T_5 * V_88 = V_69 -> V_88 ;
#endif
const T_3 V_34 = F_88 ( V_143 -> V_147 ) ;
struct V_27 * V_29 , * V_94 ;
struct V_41 * V_42 ;
unsigned long V_35 ;
T_3 V_89 ;
F_100 ( V_106 -> V_17 , V_143 ) ;
V_94 = V_69 -> V_28 ;
V_89 = 0 ;
V_29 = F_76 ( V_94 , V_89 ) ;
if ( ! V_29 )
return - V_148 ;
#ifdef F_71
F_72 ( V_88 -> gets ) ;
#endif
for (; ; ) {
V_35 = F_77 ( V_34 , V_29 ) ;
if ( V_35 >= ( 1ul << V_29 -> V_33 ) )
break;
if ( F_101 ( V_29 ) )
goto V_149;
if ( V_29 -> V_54 > V_29 -> V_38 ) {
V_94 = V_29 ;
V_89 = V_35 ;
}
V_29 = F_76 ( V_29 , V_35 ) ;
if ( F_102 ( ! V_29 ) )
goto V_150;
}
for (; ; ) {
struct V_27 T_7 * * V_151 = V_29 -> V_26 ;
if ( F_102 ( F_98 ( V_34 , V_29 ) ) || ( V_29 -> V_54 == V_29 -> V_38 ) )
goto V_150;
if ( F_102 ( F_101 ( V_29 ) ) )
break;
while ( ( V_29 = F_103 ( * V_151 ) ) == NULL ) {
V_150:
#ifdef F_71
if ( ! V_29 )
F_72 ( V_88 -> V_152 ) ;
#endif
while ( ! V_89 ) {
T_3 V_153 = V_94 -> V_34 ;
if ( F_54 ( V_94 ) )
return - V_148 ;
#ifdef F_71
F_72 ( V_88 -> V_154 ) ;
#endif
V_94 = F_104 ( V_94 ) ;
V_89 = F_27 ( V_153 , V_94 ) ;
}
V_89 &= V_89 - 1 ;
V_151 = & V_94 -> V_26 [ V_89 ] ;
}
}
V_149:
V_35 = V_34 ^ V_29 -> V_34 ;
F_105 (fa, &n->leaf, fa_list) {
struct V_14 * V_15 = V_42 -> V_99 ;
int V_155 , V_115 ;
if ( ( V_36 > V_37 ) || ( V_42 -> V_55 < V_37 ) ) {
if ( V_35 >= ( 1ul << V_42 -> V_55 ) )
continue;
}
if ( V_42 -> V_98 && V_42 -> V_98 != V_143 -> V_156 )
continue;
if ( V_15 -> V_157 )
continue;
if ( V_42 -> V_99 -> V_158 < V_143 -> V_159 )
continue;
F_106 ( V_42 ) ;
V_115 = V_160 [ V_42 -> V_123 ] . error ;
if ( F_102 ( V_115 < 0 ) ) {
#ifdef F_71
F_72 ( V_88 -> V_161 ) ;
#endif
return V_115 ;
}
if ( V_15 -> V_146 & V_162 )
continue;
for ( V_155 = 0 ; V_155 < V_15 -> V_163 ; V_155 ++ ) {
const struct V_164 * V_165 = & V_15 -> V_164 [ V_155 ] ;
struct V_166 * V_167 = F_107 ( V_165 -> V_168 ) ;
if ( V_165 -> V_169 & V_162 )
continue;
if ( V_167 &&
F_108 ( V_167 ) &&
V_165 -> V_169 & V_170 &&
! ( V_146 & V_171 ) )
continue;
if ( ! ( V_143 -> V_172 & V_173 ) ) {
if ( V_143 -> V_174 &&
V_143 -> V_174 != V_165 -> V_175 )
continue;
}
if ( ! ( V_146 & V_176 ) )
F_109 ( & V_15 -> V_177 ) ;
V_145 -> V_178 = V_37 - V_42 -> V_55 ;
V_145 -> V_179 = V_155 ;
V_145 -> type = V_42 -> V_123 ;
V_145 -> V_180 = V_15 -> V_158 ;
V_145 -> V_15 = V_15 ;
V_145 -> V_181 = V_106 ;
V_145 -> V_182 = & V_29 -> V_56 ;
#ifdef F_71
F_72 ( V_88 -> V_161 ) ;
#endif
F_110 ( V_165 ) ;
return V_115 ;
}
}
#ifdef F_71
F_72 ( V_88 -> V_183 ) ;
#endif
goto V_150;
}
static void F_111 ( struct V_68 * V_69 , struct V_27 * V_30 ,
struct V_27 * V_53 , struct V_41 * V_184 )
{
struct V_185 * * V_186 = V_184 -> V_57 . V_186 ;
struct V_41 * V_42 = F_112 ( V_186 , F_113 ( * V_42 ) , V_57 . V_64 ) ;
F_114 ( & V_184 -> V_57 ) ;
if ( F_115 ( & V_53 -> V_56 ) ) {
if ( V_30 -> V_54 == V_53 -> V_54 )
F_73 ( V_30 , V_30 -> V_38 ) ;
F_53 ( V_30 , V_53 -> V_34 , NULL ) ;
F_58 ( V_53 ) ;
F_80 ( V_69 , V_30 ) ;
return;
}
if ( * V_186 )
return;
V_53 -> V_54 = V_42 -> V_55 ;
F_73 ( V_30 , V_42 -> V_55 ) ;
}
int F_116 ( struct V_2 * V_2 , struct V_105 * V_106 ,
struct V_107 * V_108 )
{
struct V_68 * V_69 = (struct V_68 * ) V_106 -> V_109 ;
struct V_41 * V_42 , * V_187 ;
struct V_27 * V_53 , * V_30 ;
T_2 V_112 = V_108 -> V_113 ;
T_2 V_54 = V_37 - V_112 ;
T_2 V_16 = V_108 -> V_114 ;
T_1 V_34 ;
if ( V_112 > V_37 )
return - V_116 ;
V_34 = F_88 ( V_108 -> V_117 ) ;
if ( ( V_112 < V_37 ) && ( V_34 << V_112 ) )
return - V_116 ;
V_53 = F_75 ( V_69 , & V_30 , V_34 ) ;
if ( ! V_53 )
return - V_188 ;
V_42 = F_78 ( & V_53 -> V_56 , V_54 , V_16 , 0 , V_106 -> V_17 ) ;
if ( ! V_42 )
return - V_188 ;
F_46 ( L_6 , V_34 , V_112 , V_16 , V_69 ) ;
V_187 = NULL ;
F_92 (fa, fa_list) {
struct V_14 * V_15 = V_42 -> V_99 ;
if ( ( V_42 -> V_55 != V_54 ) ||
( V_42 -> V_17 != V_106 -> V_17 ) ||
( V_42 -> V_98 != V_16 ) )
break;
if ( ( ! V_108 -> V_124 || V_42 -> V_123 == V_108 -> V_124 ) &&
( V_108 -> V_189 == V_190 ||
V_42 -> V_99 -> V_158 == V_108 -> V_189 ) &&
( ! V_108 -> V_191 ||
V_15 -> V_192 == V_108 -> V_191 ) &&
( ! V_108 -> V_193 ||
V_15 -> V_194 == V_108 -> V_193 ) &&
F_117 ( V_108 , V_15 ) == 0 ) {
V_187 = V_42 ;
break;
}
}
if ( ! V_187 )
return - V_188 ;
F_21 ( V_2 , V_195 , V_34 , V_112 ,
V_187 -> V_99 , V_16 , V_108 -> V_124 ,
V_106 -> V_17 , 0 ) ;
F_96 ( V_196 , F_97 ( V_34 ) , V_187 , V_112 , V_106 -> V_17 ,
& V_108 -> V_132 , 0 ) ;
if ( ! V_112 )
V_106 -> V_140 -- ;
F_111 ( V_69 , V_30 , V_53 , V_187 ) ;
if ( V_187 -> V_129 & V_130 )
F_95 ( V_108 -> V_132 . V_133 ) ;
F_94 ( V_187 -> V_99 ) ;
F_30 ( V_187 ) ;
return 0 ;
}
static struct V_27 * F_118 ( struct V_27 * * V_32 , T_3 V_34 )
{
struct V_27 * V_94 , * V_29 = * V_32 ;
unsigned long V_89 ;
do {
V_94 = V_29 ;
V_89 = ( V_34 > V_94 -> V_34 ) ? F_27 ( V_34 , V_94 ) : 0 ;
if ( V_89 >> V_94 -> V_33 )
break;
V_29 = F_76 ( V_94 , V_89 ++ ) ;
if ( ! V_29 )
break;
if ( F_101 ( V_29 ) && ( V_29 -> V_34 >= V_34 ) )
goto V_149;
} while ( F_48 ( V_29 ) );
while ( ! F_54 ( V_94 ) ) {
if ( V_89 >= ( 1ul << V_94 -> V_33 ) ) {
T_3 V_153 = V_94 -> V_34 ;
V_94 = F_104 ( V_94 ) ;
V_89 = F_27 ( V_153 , V_94 ) + 1 ;
continue;
}
V_29 = F_76 ( V_94 , V_89 ++ ) ;
if ( ! V_29 )
continue;
if ( F_101 ( V_29 ) )
goto V_149;
V_94 = V_29 ;
V_89 = 0 ;
}
* V_32 = V_94 ;
return NULL ;
V_149:
* V_32 = V_94 ;
return V_29 ;
}
static void F_119 ( struct V_105 * V_106 )
{
struct V_68 * V_69 = (struct V_68 * ) V_106 -> V_109 ;
struct V_27 * V_94 = V_69 -> V_28 ;
unsigned long V_89 = 1 ;
struct V_185 * V_197 ;
struct V_41 * V_42 ;
for (; ; ) {
struct V_27 * V_29 ;
if ( ! ( V_89 -- ) ) {
T_3 V_153 = V_94 -> V_34 ;
if ( F_54 ( V_94 ) )
break;
V_29 = V_94 ;
V_94 = F_52 ( V_94 ) ;
F_53 ( V_94 , V_29 -> V_34 , NULL ) ;
F_58 ( V_29 ) ;
V_89 = F_27 ( V_153 , V_94 ) ;
continue;
}
V_29 = F_50 ( V_94 , V_89 ) ;
if ( ! V_29 )
continue;
if ( F_48 ( V_29 ) ) {
V_94 = V_29 ;
V_89 = 1ul << V_29 -> V_33 ;
continue;
}
F_120 (fa, tmp, &n->leaf, fa_list) {
F_114 ( & V_42 -> V_57 ) ;
F_30 ( V_42 ) ;
}
F_53 ( V_94 , V_29 -> V_34 , NULL ) ;
F_58 ( V_29 ) ;
}
#ifdef F_71
F_121 ( V_69 -> V_88 ) ;
#endif
F_122 ( V_106 ) ;
}
struct V_105 * F_123 ( struct V_105 * V_198 )
{
struct V_68 * V_199 = (struct V_68 * ) V_198 -> V_109 ;
struct V_27 * V_53 , * V_30 = V_199 -> V_28 ;
struct V_105 * V_200 ;
struct V_41 * V_42 ;
struct V_68 * V_201 ;
T_3 V_34 = 0 ;
if ( V_198 -> V_109 == V_198 -> V_202 )
return V_198 ;
V_200 = F_124 ( V_203 , NULL ) ;
if ( ! V_200 )
return NULL ;
V_201 = (struct V_68 * ) V_200 -> V_109 ;
while ( ( V_53 = F_118 ( & V_30 , V_34 ) ) != NULL ) {
struct V_27 * V_204 = NULL , * V_205 ;
F_105 (fa, &l->leaf, fa_list) {
struct V_41 * V_110 ;
if ( V_200 -> V_17 != V_42 -> V_17 )
continue;
V_110 = F_41 ( V_44 , V_50 ) ;
if ( ! V_110 )
goto V_122;
memcpy ( V_110 , V_42 , sizeof( * V_42 ) ) ;
if ( ! V_204 )
V_204 = F_75 ( V_201 , & V_205 , V_53 -> V_34 ) ;
if ( F_83 ( V_201 , V_205 , V_204 , V_110 ,
NULL , V_53 -> V_34 ) ) {
F_29 ( V_44 , V_110 ) ;
goto V_122;
}
}
V_34 = V_53 -> V_34 + 1 ;
if ( V_34 < V_53 -> V_34 )
break;
}
return V_200 ;
V_122:
F_119 ( V_200 ) ;
return NULL ;
}
void F_125 ( struct V_105 * V_106 )
{
struct V_68 * V_69 = (struct V_68 * ) V_106 -> V_109 ;
struct V_27 * V_94 = V_69 -> V_28 ;
unsigned long V_89 = 1 ;
struct V_185 * V_197 ;
struct V_41 * V_42 ;
for (; ; ) {
unsigned char V_54 = 0 ;
struct V_27 * V_29 ;
if ( ! ( V_89 -- ) ) {
T_3 V_153 = V_94 -> V_34 ;
if ( F_54 ( V_94 ) )
break;
if ( V_94 -> V_54 > V_94 -> V_38 )
F_66 ( V_94 ) ;
V_94 = F_62 ( V_69 , V_94 ) ;
V_89 = F_27 ( V_153 , V_94 ) ;
continue;
}
V_29 = F_50 ( V_94 , V_89 ) ;
if ( ! V_29 )
continue;
if ( F_48 ( V_29 ) ) {
V_94 = V_29 ;
V_89 = 1ul << V_29 -> V_33 ;
continue;
}
F_120 (fa, tmp, &n->leaf, fa_list) {
if ( V_106 -> V_17 != V_42 -> V_17 ) {
F_114 ( & V_42 -> V_57 ) ;
F_30 ( V_42 ) ;
continue;
}
V_54 = V_42 -> V_55 ;
}
V_29 -> V_54 = V_54 ;
if ( F_115 ( & V_29 -> V_56 ) ) {
F_53 ( V_94 , V_29 -> V_34 , NULL ) ;
F_58 ( V_29 ) ;
}
}
}
int F_126 ( struct V_2 * V_2 , struct V_105 * V_106 )
{
struct V_68 * V_69 = (struct V_68 * ) V_106 -> V_109 ;
struct V_27 * V_94 = V_69 -> V_28 ;
unsigned long V_89 = 1 ;
struct V_185 * V_197 ;
struct V_41 * V_42 ;
int V_149 = 0 ;
for (; ; ) {
unsigned char V_54 = 0 ;
struct V_27 * V_29 ;
if ( ! ( V_89 -- ) ) {
T_3 V_153 = V_94 -> V_34 ;
if ( F_54 ( V_94 ) )
break;
if ( V_94 -> V_54 > V_94 -> V_38 )
F_66 ( V_94 ) ;
V_94 = F_62 ( V_69 , V_94 ) ;
V_89 = F_27 ( V_153 , V_94 ) ;
continue;
}
V_29 = F_50 ( V_94 , V_89 ) ;
if ( ! V_29 )
continue;
if ( F_48 ( V_29 ) ) {
V_94 = V_29 ;
V_89 = 1ul << V_29 -> V_33 ;
continue;
}
F_120 (fa, tmp, &n->leaf, fa_list) {
struct V_14 * V_15 = V_42 -> V_99 ;
if ( ! V_15 || ! ( V_15 -> V_146 & V_162 ) ) {
V_54 = V_42 -> V_55 ;
continue;
}
F_21 ( V_2 , V_195 ,
V_29 -> V_34 ,
V_37 - V_42 -> V_55 ,
V_15 , V_42 -> V_98 , V_42 -> V_123 ,
V_106 -> V_17 , 0 ) ;
F_114 ( & V_42 -> V_57 ) ;
F_94 ( V_42 -> V_99 ) ;
F_30 ( V_42 ) ;
V_149 ++ ;
}
V_29 -> V_54 = V_54 ;
if ( F_115 ( & V_29 -> V_56 ) ) {
F_53 ( V_94 , V_29 -> V_34 , NULL ) ;
F_58 ( V_29 ) ;
}
}
F_46 ( L_7 , V_149 ) ;
return V_149 ;
}
static void F_127 ( struct V_2 * V_2 , struct V_27 * V_53 ,
struct V_105 * V_106 , struct V_4 * V_5 ,
enum V_6 V_7 )
{
struct V_41 * V_42 ;
F_105 (fa, &l->leaf, fa_list) {
struct V_14 * V_15 = V_42 -> V_99 ;
if ( ! V_15 )
continue;
if ( V_106 -> V_17 != V_42 -> V_17 )
continue;
F_8 ( V_5 , V_2 , V_7 , V_53 -> V_34 ,
V_37 - V_42 -> V_55 , V_15 , V_42 -> V_98 ,
V_42 -> V_123 , V_42 -> V_17 , 0 ) ;
}
}
static void F_128 ( struct V_2 * V_2 , struct V_105 * V_106 ,
struct V_4 * V_5 ,
enum V_6 V_7 )
{
struct V_68 * V_69 = (struct V_68 * ) V_106 -> V_109 ;
struct V_27 * V_53 , * V_30 = V_69 -> V_28 ;
T_3 V_34 = 0 ;
while ( ( V_53 = F_118 ( & V_30 , V_34 ) ) != NULL ) {
F_127 ( V_2 , V_53 , V_106 , V_5 , V_7 ) ;
V_34 = V_53 -> V_34 + 1 ;
if ( V_34 < V_53 -> V_34 )
break;
}
}
static void F_16 ( struct V_2 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 )
{
unsigned int V_206 ;
for ( V_206 = 0 ; V_206 < V_207 ; V_206 ++ ) {
struct V_95 * V_40 = & V_2 -> V_3 . V_208 [ V_206 ] ;
struct V_105 * V_106 ;
F_105 (tb, head, tb_hlist)
F_128 ( V_2 , V_106 , V_5 , V_7 ) ;
}
}
static void F_129 ( struct V_39 * V_40 )
{
struct V_105 * V_106 = F_23 ( V_40 , struct V_105 , V_43 ) ;
#ifdef F_71
struct V_68 * V_69 = (struct V_68 * ) V_106 -> V_109 ;
if ( V_106 -> V_109 == V_106 -> V_202 )
F_121 ( V_69 -> V_88 ) ;
#endif
F_122 ( V_106 ) ;
}
void F_130 ( struct V_105 * V_106 )
{
F_31 ( & V_106 -> V_43 , F_129 ) ;
}
static int F_131 ( struct V_27 * V_53 , struct V_105 * V_106 ,
struct V_209 * V_210 , struct V_211 * F_10 )
{
T_8 V_212 = F_97 ( V_53 -> V_34 ) ;
struct V_41 * V_42 ;
int V_59 , V_213 ;
V_213 = F_10 -> args [ 4 ] ;
V_59 = 0 ;
F_105 (fa, &l->leaf, fa_list) {
if ( V_59 < V_213 ) {
V_59 ++ ;
continue;
}
if ( V_106 -> V_17 != V_42 -> V_17 ) {
V_59 ++ ;
continue;
}
if ( F_132 ( V_210 , F_133 ( F_10 -> V_210 ) . V_214 ,
F_10 -> V_215 -> V_216 ,
V_134 ,
V_106 -> V_17 ,
V_42 -> V_123 ,
V_212 ,
V_37 - V_42 -> V_55 ,
V_42 -> V_98 ,
V_42 -> V_99 , V_217 ) < 0 ) {
F_10 -> args [ 4 ] = V_59 ;
return - 1 ;
}
V_59 ++ ;
}
F_10 -> args [ 4 ] = V_59 ;
return V_210 -> V_218 ;
}
int F_134 ( struct V_105 * V_106 , struct V_209 * V_210 ,
struct V_211 * F_10 )
{
struct V_68 * V_69 = (struct V_68 * ) V_106 -> V_109 ;
struct V_27 * V_53 , * V_30 = V_69 -> V_28 ;
int V_219 = F_10 -> args [ 2 ] ;
T_3 V_34 = F_10 -> args [ 3 ] ;
while ( ( V_53 = F_118 ( & V_30 , V_34 ) ) != NULL ) {
if ( F_131 ( V_53 , V_106 , V_210 , F_10 ) < 0 ) {
F_10 -> args [ 3 ] = V_34 ;
F_10 -> args [ 2 ] = V_219 ;
return - 1 ;
}
++ V_219 ;
V_34 = V_53 -> V_34 + 1 ;
memset ( & F_10 -> args [ 4 ] , 0 ,
sizeof( F_10 -> args ) - 4 * sizeof( F_10 -> args [ 0 ] ) ) ;
if ( V_34 < V_53 -> V_34 )
break;
}
F_10 -> args [ 3 ] = V_34 ;
F_10 -> args [ 2 ] = V_219 ;
return V_210 -> V_218 ;
}
void T_9 F_135 ( void )
{
V_44 = F_136 ( L_8 ,
sizeof( struct V_41 ) ,
0 , V_220 , NULL ) ;
V_46 = F_136 ( L_9 ,
V_221 ,
0 , V_220 , NULL ) ;
}
struct V_105 * F_124 ( T_1 V_222 , struct V_105 * V_223 )
{
struct V_105 * V_106 ;
struct V_68 * V_69 ;
T_4 V_224 = sizeof( * V_106 ) ;
if ( ! V_223 )
V_224 += sizeof( struct V_68 ) ;
V_106 = F_36 ( V_224 , V_50 ) ;
if ( ! V_106 )
return NULL ;
V_106 -> V_17 = V_222 ;
V_106 -> V_140 = 0 ;
V_106 -> V_109 = ( V_223 ? V_223 -> V_202 : V_106 -> V_202 ) ;
if ( V_223 )
return V_106 ;
V_69 = (struct V_68 * ) V_106 -> V_109 ;
V_69 -> V_28 [ 0 ] . V_38 = V_37 ;
V_69 -> V_28 [ 0 ] . V_54 = V_37 ;
#ifdef F_71
V_69 -> V_88 = F_137 ( struct V_87 ) ;
if ( ! V_69 -> V_88 ) {
F_122 ( V_106 ) ;
V_106 = NULL ;
}
#endif
return V_106 ;
}
static struct V_27 * F_138 ( struct V_225 * V_226 )
{
unsigned long V_89 = V_226 -> V_35 ;
struct V_27 * V_94 = V_226 -> V_26 ;
T_3 V_153 ;
F_46 ( L_10 ,
V_226 -> V_26 , V_226 -> V_35 , V_226 -> V_227 ) ;
while ( ! F_54 ( V_94 ) ) {
while ( V_89 < F_26 ( V_94 ) ) {
struct V_27 * V_29 = F_76 ( V_94 , V_89 ++ ) ;
if ( ! V_29 )
continue;
if ( F_101 ( V_29 ) ) {
V_226 -> V_26 = V_94 ;
V_226 -> V_35 = V_89 ;
} else {
V_226 -> V_26 = V_29 ;
V_226 -> V_35 = 0 ;
++ V_226 -> V_227 ;
}
return V_29 ;
}
V_153 = V_94 -> V_34 ;
V_94 = F_104 ( V_94 ) ;
V_89 = F_27 ( V_153 , V_94 ) + 1 ;
-- V_226 -> V_227 ;
}
V_226 -> V_26 = V_94 ;
V_226 -> V_35 = 0 ;
return NULL ;
}
static struct V_27 * F_139 ( struct V_225 * V_226 ,
struct V_68 * V_69 )
{
struct V_27 * V_29 , * V_94 ;
if ( ! V_69 )
return NULL ;
V_94 = V_69 -> V_28 ;
V_29 = F_103 ( V_94 -> V_26 [ 0 ] ) ;
if ( ! V_29 )
return NULL ;
if ( F_48 ( V_29 ) ) {
V_226 -> V_26 = V_29 ;
V_226 -> V_35 = 0 ;
V_226 -> V_227 = 1 ;
} else {
V_226 -> V_26 = V_94 ;
V_226 -> V_35 = 0 ;
V_226 -> V_227 = 0 ;
}
return V_29 ;
}
static void F_140 ( struct V_68 * V_69 , struct V_228 * V_229 )
{
struct V_27 * V_29 ;
struct V_225 V_226 ;
memset ( V_229 , 0 , sizeof( * V_229 ) ) ;
F_14 () ;
for ( V_29 = F_139 ( & V_226 , V_69 ) ; V_29 ; V_29 = F_138 ( & V_226 ) ) {
if ( F_101 ( V_29 ) ) {
struct V_41 * V_42 ;
V_229 -> V_230 ++ ;
V_229 -> V_231 += V_226 . V_227 ;
if ( V_226 . V_227 > V_229 -> V_232 )
V_229 -> V_232 = V_226 . V_227 ;
F_105 ( V_42 , & V_29 -> V_56 , V_57 )
++ V_229 -> V_233 ;
} else {
V_229 -> V_234 ++ ;
if ( V_29 -> V_33 < V_235 )
V_229 -> V_236 [ V_29 -> V_33 ] ++ ;
V_229 -> V_237 += F_22 ( V_29 ) -> V_51 ;
}
}
F_17 () ;
}
static void F_141 ( struct V_238 * V_239 , struct V_228 * V_240 )
{
unsigned int V_59 , V_241 , V_242 , V_243 , V_244 ;
if ( V_240 -> V_230 )
V_244 = V_240 -> V_231 * 100 / V_240 -> V_230 ;
else
V_244 = 0 ;
F_142 ( V_239 , L_11 ,
V_244 / 100 , V_244 % 100 ) ;
F_142 ( V_239 , L_12 , V_240 -> V_232 ) ;
F_142 ( V_239 , L_13 , V_240 -> V_230 ) ;
V_243 = V_221 * V_240 -> V_230 ;
F_142 ( V_239 , L_14 , V_240 -> V_233 ) ;
V_243 += sizeof( struct V_41 ) * V_240 -> V_233 ;
F_142 ( V_239 , L_15 , V_240 -> V_234 ) ;
V_243 += F_35 ( 0 ) * V_240 -> V_234 ;
V_241 = V_235 ;
while ( V_241 > 0 && V_240 -> V_236 [ V_241 - 1 ] == 0 )
V_241 -- ;
V_242 = 0 ;
for ( V_59 = 1 ; V_59 < V_241 ; V_59 ++ )
if ( V_240 -> V_236 [ V_59 ] != 0 ) {
F_142 ( V_239 , L_16 , V_59 , V_240 -> V_236 [ V_59 ] ) ;
V_242 += ( 1 << V_59 ) * V_240 -> V_236 [ V_59 ] ;
}
F_143 ( V_239 , '\n' ) ;
F_142 ( V_239 , L_17 , V_242 ) ;
V_243 += sizeof( struct V_27 * ) * V_242 ;
F_142 ( V_239 , L_18 , V_240 -> V_237 ) ;
F_142 ( V_239 , L_19 , ( V_243 + 1023 ) / 1024 ) ;
}
static void F_144 ( struct V_238 * V_239 ,
const struct V_87 T_5 * V_88 )
{
struct V_87 V_229 = { 0 } ;
int V_245 ;
F_145 (cpu) {
const struct V_87 * V_246 = F_146 ( V_88 , V_245 ) ;
V_229 . gets += V_246 -> gets ;
V_229 . V_154 += V_246 -> V_154 ;
V_229 . V_161 += V_246 -> V_161 ;
V_229 . V_183 += V_246 -> V_183 ;
V_229 . V_152 += V_246 -> V_152 ;
V_229 . V_92 += V_246 -> V_92 ;
}
F_142 ( V_239 , L_20 ) ;
F_142 ( V_239 , L_21 , V_229 . gets ) ;
F_142 ( V_239 , L_22 , V_229 . V_154 ) ;
F_142 ( V_239 , L_23 ,
V_229 . V_161 ) ;
F_142 ( V_239 , L_24 , V_229 . V_183 ) ;
F_142 ( V_239 , L_25 , V_229 . V_152 ) ;
F_142 ( V_239 , L_26 , V_229 . V_92 ) ;
}
static void F_147 ( struct V_238 * V_239 , struct V_105 * V_106 )
{
if ( V_106 -> V_17 == V_203 )
F_148 ( V_239 , L_27 ) ;
else if ( V_106 -> V_17 == V_247 )
F_148 ( V_239 , L_28 ) ;
else
F_142 ( V_239 , L_29 , V_106 -> V_17 ) ;
}
static int F_149 ( struct V_238 * V_239 , void * V_248 )
{
struct V_2 * V_2 = (struct V_2 * ) V_239 -> V_249 ;
unsigned int V_206 ;
F_142 ( V_239 ,
L_30
L_31 ,
V_221 , F_35 ( 0 ) ) ;
for ( V_206 = 0 ; V_206 < V_207 ; V_206 ++ ) {
struct V_95 * V_40 = & V_2 -> V_3 . V_208 [ V_206 ] ;
struct V_105 * V_106 ;
F_105 (tb, head, tb_hlist) {
struct V_68 * V_69 = (struct V_68 * ) V_106 -> V_109 ;
struct V_228 V_240 ;
if ( ! V_69 )
continue;
F_147 ( V_239 , V_106 ) ;
F_140 ( V_69 , & V_240 ) ;
F_141 ( V_239 , & V_240 ) ;
#ifdef F_71
F_144 ( V_239 , V_69 -> V_88 ) ;
#endif
}
}
return 0 ;
}
static int F_150 ( struct V_63 * V_63 , struct V_250 * V_250 )
{
return F_151 ( V_63 , V_250 , F_149 ) ;
}
static struct V_27 * F_152 ( struct V_238 * V_239 , T_10 V_38 )
{
struct V_225 * V_226 = V_239 -> V_249 ;
struct V_2 * V_2 = F_153 ( V_239 ) ;
T_10 V_251 = 0 ;
unsigned int V_206 ;
for ( V_206 = 0 ; V_206 < V_207 ; V_206 ++ ) {
struct V_95 * V_40 = & V_2 -> V_3 . V_208 [ V_206 ] ;
struct V_105 * V_106 ;
F_105 (tb, head, tb_hlist) {
struct V_27 * V_29 ;
for ( V_29 = F_139 ( V_226 ,
(struct V_68 * ) V_106 -> V_109 ) ;
V_29 ; V_29 = F_138 ( V_226 ) )
if ( V_38 == V_251 ++ ) {
V_226 -> V_106 = V_106 ;
return V_29 ;
}
}
}
return NULL ;
}
static void * F_154 ( struct V_238 * V_239 , T_10 * V_38 )
__acquires( T_11 )
{
F_14 () ;
return F_152 ( V_239 , * V_38 ) ;
}
static void * F_155 ( struct V_238 * V_239 , void * V_248 , T_10 * V_38 )
{
struct V_225 * V_226 = V_239 -> V_249 ;
struct V_2 * V_2 = F_153 ( V_239 ) ;
struct V_105 * V_106 = V_226 -> V_106 ;
struct V_185 * V_252 ;
unsigned int V_206 ;
struct V_27 * V_29 ;
++ * V_38 ;
V_29 = F_138 ( V_226 ) ;
if ( V_29 )
return V_29 ;
V_206 = V_106 -> V_17 & ( V_207 - 1 ) ;
while ( ( V_252 = F_103 ( F_156 ( & V_106 -> V_253 ) ) ) ) {
V_106 = F_112 ( V_252 , struct V_105 , V_253 ) ;
V_29 = F_139 ( V_226 , (struct V_68 * ) V_106 -> V_109 ) ;
if ( V_29 )
goto V_149;
}
while ( ++ V_206 < V_207 ) {
struct V_95 * V_40 = & V_2 -> V_3 . V_208 [ V_206 ] ;
F_105 (tb, head, tb_hlist) {
V_29 = F_139 ( V_226 , (struct V_68 * ) V_106 -> V_109 ) ;
if ( V_29 )
goto V_149;
}
}
return NULL ;
V_149:
V_226 -> V_106 = V_106 ;
return V_29 ;
}
static void F_157 ( struct V_238 * V_239 , void * V_248 )
__releases( T_11 )
{
F_17 () ;
}
static void F_158 ( struct V_238 * V_239 , int V_29 )
{
while ( V_29 -- > 0 )
F_148 ( V_239 , L_32 ) ;
}
static inline const char * F_159 ( char * V_254 , T_4 V_218 , enum V_255 V_229 )
{
switch ( V_229 ) {
case V_256 : return L_33 ;
case V_257 : return L_34 ;
case V_258 : return L_35 ;
case V_259 : return L_36 ;
case V_190 : return L_37 ;
default:
snprintf ( V_254 , V_218 , L_38 , V_229 ) ;
return V_254 ;
}
}
static inline const char * F_160 ( char * V_254 , T_4 V_218 , unsigned int V_69 )
{
if ( V_69 < V_260 && V_261 [ V_69 ] )
return V_261 [ V_69 ] ;
snprintf ( V_254 , V_218 , L_39 , V_69 ) ;
return V_254 ;
}
static int F_161 ( struct V_238 * V_239 , void * V_248 )
{
const struct V_225 * V_226 = V_239 -> V_249 ;
struct V_27 * V_29 = V_248 ;
if ( F_54 ( F_104 ( V_29 ) ) )
F_147 ( V_239 , V_226 -> V_106 ) ;
if ( F_48 ( V_29 ) ) {
T_8 V_262 = F_97 ( V_29 -> V_34 ) ;
F_158 ( V_239 , V_226 -> V_227 - 1 ) ;
F_142 ( V_239 , L_40 ,
& V_262 , V_37 - V_29 -> V_38 - V_29 -> V_33 , V_29 -> V_33 ,
F_22 ( V_29 ) -> V_52 ,
F_22 ( V_29 ) -> V_51 ) ;
} else {
T_8 V_263 = F_97 ( V_29 -> V_34 ) ;
struct V_41 * V_42 ;
F_158 ( V_239 , V_226 -> V_227 ) ;
F_142 ( V_239 , L_41 , & V_263 ) ;
F_105 (fa, &n->leaf, fa_list) {
char V_264 [ 32 ] , V_265 [ 32 ] ;
F_158 ( V_239 , V_226 -> V_227 + 1 ) ;
F_142 ( V_239 , L_42 ,
V_37 - V_42 -> V_55 ,
F_159 ( V_264 , sizeof( V_264 ) ,
V_42 -> V_99 -> V_158 ) ,
F_160 ( V_265 , sizeof( V_265 ) ,
V_42 -> V_123 ) ) ;
if ( V_42 -> V_98 )
F_142 ( V_239 , L_43 , V_42 -> V_98 ) ;
F_143 ( V_239 , '\n' ) ;
}
}
return 0 ;
}
static int F_162 ( struct V_63 * V_63 , struct V_250 * V_250 )
{
return F_163 ( V_63 , V_250 , & V_266 ,
sizeof( struct V_225 ) ) ;
}
static struct V_27 * F_164 ( struct V_267 * V_226 ,
T_10 V_38 )
{
struct V_27 * V_53 , * * V_30 = & V_226 -> V_26 ;
T_3 V_34 ;
if ( V_226 -> V_38 > 0 && V_38 >= V_226 -> V_38 ) {
V_34 = V_226 -> V_34 ;
} else {
V_226 -> V_38 = 1 ;
V_34 = 0 ;
}
V_38 -= V_226 -> V_38 ;
while ( ( V_53 = F_118 ( V_30 , V_34 ) ) && ( V_38 -- > 0 ) ) {
V_34 = V_53 -> V_34 + 1 ;
V_226 -> V_38 ++ ;
V_53 = NULL ;
if ( ! V_34 )
break;
}
if ( V_53 )
V_226 -> V_34 = V_53 -> V_34 ;
else
V_226 -> V_38 = 0 ;
return V_53 ;
}
static void * F_165 ( struct V_238 * V_239 , T_10 * V_38 )
__acquires( T_11 )
{
struct V_267 * V_226 = V_239 -> V_249 ;
struct V_105 * V_106 ;
struct V_68 * V_69 ;
F_14 () ;
V_106 = F_166 ( F_153 ( V_239 ) , V_247 ) ;
if ( ! V_106 )
return NULL ;
V_226 -> V_268 = V_106 ;
V_69 = (struct V_68 * ) V_106 -> V_109 ;
V_226 -> V_26 = V_69 -> V_28 ;
if ( * V_38 != 0 )
return F_164 ( V_226 , * V_38 ) ;
V_226 -> V_38 = 0 ;
V_226 -> V_34 = V_86 ;
return V_269 ;
}
static void * F_167 ( struct V_238 * V_239 , void * V_248 , T_10 * V_38 )
{
struct V_267 * V_226 = V_239 -> V_249 ;
struct V_27 * V_53 = NULL ;
T_3 V_34 = V_226 -> V_34 + 1 ;
++ * V_38 ;
if ( ( V_248 == V_269 ) || V_34 )
V_53 = F_118 ( & V_226 -> V_26 , V_34 ) ;
if ( V_53 ) {
V_226 -> V_34 = V_53 -> V_34 ;
V_226 -> V_38 ++ ;
} else {
V_226 -> V_38 = 0 ;
}
return V_53 ;
}
static void F_168 ( struct V_238 * V_239 , void * V_248 )
__releases( T_11 )
{
F_17 () ;
}
static unsigned int F_169 ( int type , T_8 V_270 , const struct V_14 * V_15 )
{
unsigned int V_271 = 0 ;
if ( type == V_272 || type == V_273 )
V_271 = V_274 ;
if ( V_15 && V_15 -> V_164 -> V_275 )
V_271 |= V_276 ;
if ( V_270 == F_97 ( 0xFFFFFFFF ) )
V_271 |= V_277 ;
V_271 |= V_278 ;
return V_271 ;
}
static int F_170 ( struct V_238 * V_239 , void * V_248 )
{
struct V_267 * V_226 = V_239 -> V_249 ;
struct V_105 * V_106 = V_226 -> V_268 ;
struct V_41 * V_42 ;
struct V_27 * V_53 = V_248 ;
T_8 V_141 ;
if ( V_248 == V_269 ) {
F_142 ( V_239 , L_44 , L_45
L_46
L_47 ) ;
return 0 ;
}
V_141 = F_97 ( V_53 -> V_34 ) ;
F_105 (fa, &l->leaf, fa_list) {
const struct V_14 * V_15 = V_42 -> V_99 ;
T_8 V_270 = F_171 ( V_37 - V_42 -> V_55 ) ;
unsigned int V_271 = F_169 ( V_42 -> V_123 , V_270 , V_15 ) ;
if ( ( V_42 -> V_123 == V_279 ) ||
( V_42 -> V_123 == V_280 ) )
continue;
if ( V_42 -> V_17 != V_106 -> V_17 )
continue;
F_172 ( V_239 , 127 ) ;
if ( V_15 )
F_142 ( V_239 ,
L_48
L_49 ,
V_15 -> V_281 ? V_15 -> V_281 -> V_282 : L_50 ,
V_141 ,
V_15 -> V_164 -> V_275 , V_271 , 0 , 0 ,
V_15 -> V_100 ,
V_270 ,
( V_15 -> V_283 ?
V_15 -> V_283 + 40 : 0 ) ,
V_15 -> V_284 ,
V_15 -> V_285 >> 3 ) ;
else
F_142 ( V_239 ,
L_51
L_49 ,
V_141 , 0 , V_271 , 0 , 0 , 0 ,
V_270 , 0 , 0 , 0 ) ;
F_173 ( V_239 , '\n' ) ;
}
return 0 ;
}
static int F_174 ( struct V_63 * V_63 , struct V_250 * V_250 )
{
return F_163 ( V_63 , V_250 , & V_286 ,
sizeof( struct V_267 ) ) ;
}
int T_12 F_175 ( struct V_2 * V_2 )
{
if ( ! F_176 ( L_52 , V_287 , V_2 -> V_288 , & V_289 ) )
goto V_290;
if ( ! F_176 ( L_53 , V_287 , V_2 -> V_288 ,
& V_291 ) )
goto V_292;
if ( ! F_176 ( L_54 , V_287 , V_2 -> V_288 , & V_293 ) )
goto V_294;
return 0 ;
V_294:
F_177 ( L_53 , V_2 -> V_288 ) ;
V_292:
F_177 ( L_52 , V_2 -> V_288 ) ;
V_290:
return - V_103 ;
}
void T_13 F_178 ( struct V_2 * V_2 )
{
F_177 ( L_52 , V_2 -> V_288 ) ;
F_177 ( L_53 , V_2 -> V_288 ) ;
F_177 ( L_54 , V_2 -> V_288 ) ;
}
