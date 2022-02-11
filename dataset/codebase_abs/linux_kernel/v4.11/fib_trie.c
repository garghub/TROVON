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
T_2 V_16 , T_2 type , T_1 V_17 )
{
struct V_18 V_9 = {
. V_12 = V_12 ,
. V_13 = V_13 ,
. V_15 = V_15 ,
. V_16 = V_16 ,
. type = type ,
. V_17 = V_17 ,
} ;
return F_5 ( V_5 , V_2 , V_7 , & V_9 . V_9 ) ;
}
static bool F_9 ( struct V_4 * V_5 ,
void (* F_10)( struct V_4 * V_5 ) ,
unsigned int V_1 )
{
F_11 ( & V_19 , V_5 ) ;
if ( V_1 == F_1 () )
return true ;
F_12 ( & V_19 , V_5 ) ;
if ( F_10 )
F_10 ( V_5 ) ;
return false ;
}
int F_13 ( struct V_4 * V_5 ,
void (* F_10)( struct V_4 * V_5 ) )
{
int V_20 = 0 ;
do {
unsigned int V_1 = F_1 () ;
struct V_2 * V_2 ;
F_14 () ;
F_15 (net) {
F_6 ( V_2 , V_5 , V_21 ) ;
F_16 ( V_2 , V_5 , V_22 ) ;
}
F_17 () ;
if ( F_9 ( V_5 , F_10 , V_1 ) )
return 0 ;
} while ( ++ V_20 < V_23 );
return - V_24 ;
}
int F_18 ( struct V_4 * V_5 )
{
return F_12 ( & V_19 , V_5 ) ;
}
int F_19 ( struct V_2 * V_2 , enum V_6 V_7 ,
struct V_8 * V_9 )
{
V_2 -> V_3 . V_1 ++ ;
V_9 -> V_2 = V_2 ;
return F_20 ( & V_19 , V_7 , V_9 ) ;
}
static int F_21 ( struct V_2 * V_2 ,
enum V_6 V_7 , T_1 V_12 ,
int V_13 , struct V_14 * V_15 ,
T_2 V_16 , T_2 type , T_1 V_17 )
{
struct V_18 V_9 = {
. V_12 = V_12 ,
. V_13 = V_13 ,
. V_15 = V_15 ,
. V_16 = V_16 ,
. type = type ,
. V_17 = V_17 ,
} ;
return F_19 ( V_2 , V_7 , & V_9 . V_9 ) ;
}
static inline struct V_25 * F_22 ( struct V_26 * V_27 )
{
return F_23 ( V_27 , struct V_25 , V_27 [ 0 ] ) ;
}
static inline void F_24 ( struct V_26 * V_28 , struct V_26 * V_29 )
{
if ( V_28 )
F_25 ( F_22 ( V_28 ) -> V_30 , V_29 ) ;
}
static inline unsigned long F_26 ( const struct V_26 * V_31 )
{
return ( 1ul << V_31 -> V_32 ) & ~ ( 1ul ) ;
}
static inline unsigned long F_27 ( T_3 V_33 , struct V_26 * V_27 )
{
unsigned long V_34 = V_33 ^ V_27 -> V_33 ;
if ( ( V_35 <= V_36 ) && ( V_36 == V_27 -> V_37 ) )
return 0 ;
return V_34 >> V_27 -> V_37 ;
}
static void F_28 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_23 ( V_39 , struct V_40 , V_42 ) ;
F_29 ( V_43 , V_41 ) ;
}
static inline void F_30 ( struct V_40 * V_41 )
{
F_31 ( & V_41 -> V_42 , F_28 ) ;
}
static void F_32 ( struct V_38 * V_39 )
{
struct V_25 * V_28 = F_23 ( V_39 , struct V_25 , V_42 ) ;
if ( ! V_28 -> V_44 )
F_29 ( V_45 , V_28 ) ;
else
F_33 ( V_28 ) ;
}
static struct V_25 * F_34 ( int V_32 )
{
T_4 V_46 ;
if ( V_32 > V_47 )
return NULL ;
V_46 = F_35 ( 1ul << V_32 ) ;
if ( V_46 <= V_48 )
return F_36 ( V_46 , V_49 ) ;
else
return F_37 ( V_46 ) ;
}
static inline void F_38 ( struct V_26 * V_28 )
{
++ F_22 ( V_28 ) -> V_50 ? : ++ F_22 ( V_28 ) -> V_51 ;
}
static inline void F_39 ( struct V_26 * V_28 )
{
F_22 ( V_28 ) -> V_50 -- ? : F_22 ( V_28 ) -> V_51 -- ;
}
static struct V_26 * F_40 ( T_3 V_33 , struct V_40 * V_41 )
{
struct V_26 * V_52 ;
struct V_25 * V_27 ;
V_27 = F_41 ( V_45 , V_49 ) ;
if ( ! V_27 )
return NULL ;
V_52 = V_27 -> V_27 ;
V_52 -> V_33 = V_33 ;
V_52 -> V_37 = 0 ;
V_52 -> V_32 = 0 ;
V_52 -> V_53 = V_41 -> V_54 ;
F_42 ( & V_52 -> V_55 ) ;
F_43 ( & V_41 -> V_56 , & V_52 -> V_55 ) ;
return V_52 ;
}
static struct V_26 * F_44 ( T_3 V_33 , int V_37 , int V_32 )
{
unsigned int V_57 = V_37 + V_32 ;
struct V_26 * V_31 ;
struct V_25 * V_25 ;
F_45 ( ! V_32 || ( V_57 > V_36 ) ) ;
V_25 = F_34 ( V_32 ) ;
if ( ! V_25 )
return NULL ;
F_46 ( L_1 , V_25 , F_35 ( 0 ) ,
sizeof( struct V_26 * ) << V_32 ) ;
if ( V_32 == V_36 )
V_25 -> V_51 = 1 ;
else
V_25 -> V_50 = 1ul << V_32 ;
V_31 = V_25 -> V_27 ;
V_31 -> V_33 = ( V_57 < V_36 ) ? ( V_33 >> V_57 ) << V_57 : 0 ;
V_31 -> V_37 = V_37 ;
V_31 -> V_32 = V_32 ;
V_31 -> V_53 = V_37 ;
return V_31 ;
}
static inline int F_47 ( struct V_26 * V_31 , struct V_26 * V_28 )
{
return V_28 && ( ( V_28 -> V_37 + V_28 -> V_32 ) == V_31 -> V_37 ) && F_48 ( V_28 ) ;
}
static void F_49 ( struct V_26 * V_31 , unsigned long V_58 ,
struct V_26 * V_28 )
{
struct V_26 * V_59 = F_50 ( V_31 , V_58 ) ;
int V_60 , V_61 ;
F_45 ( V_58 >= F_26 ( V_31 ) ) ;
if ( ! V_28 && V_59 )
F_38 ( V_31 ) ;
if ( V_28 && ! V_59 )
F_39 ( V_31 ) ;
V_61 = F_47 ( V_31 , V_59 ) ;
V_60 = F_47 ( V_31 , V_28 ) ;
if ( V_61 && ! V_60 )
F_22 ( V_31 ) -> V_51 -- ;
else if ( ! V_61 && V_60 )
F_22 ( V_31 ) -> V_51 ++ ;
if ( V_28 && ( V_31 -> V_53 < V_28 -> V_53 ) )
V_31 -> V_53 = V_28 -> V_53 ;
F_25 ( V_31 -> V_25 [ V_58 ] , V_28 ) ;
}
static void F_51 ( struct V_26 * V_31 )
{
unsigned long V_58 ;
for ( V_58 = F_26 ( V_31 ) ; V_58 ; ) {
struct V_26 * V_62 = F_50 ( V_31 , -- V_58 ) ;
if ( ! V_62 )
continue;
if ( F_52 ( V_62 ) == V_31 )
F_51 ( V_62 ) ;
else
F_24 ( V_62 , V_31 ) ;
}
}
static inline void F_53 ( struct V_26 * V_29 , T_3 V_33 ,
struct V_26 * V_28 )
{
if ( F_54 ( V_29 ) )
F_25 ( V_29 -> V_25 [ 0 ] , V_28 ) ;
else
F_49 ( V_29 , F_27 ( V_33 , V_29 ) , V_28 ) ;
}
static inline void F_55 ( struct V_26 * V_31 )
{
F_22 ( V_31 ) -> V_42 . V_63 = NULL ;
}
static inline void F_56 ( struct V_26 * V_31 ,
struct V_26 * V_28 )
{
F_22 ( V_28 ) -> V_42 . V_63 = F_22 ( V_31 ) -> V_42 . V_63 ;
F_22 ( V_31 ) -> V_42 . V_63 = & F_22 ( V_28 ) -> V_42 ;
}
static void F_57 ( struct V_26 * V_31 )
{
struct V_64 * V_39 = & F_22 ( V_31 ) -> V_42 ;
while ( V_39 ) {
V_39 = V_39 -> V_63 ;
V_65 += F_35 ( 1ul << V_31 -> V_32 ) ;
F_58 ( V_31 ) ;
V_31 = F_23 ( V_39 , struct V_25 , V_42 ) -> V_27 ;
}
if ( V_65 >= V_48 * V_66 ) {
V_65 = 0 ;
F_59 () ;
}
}
static struct V_26 * F_60 ( struct V_67 * V_68 ,
struct V_26 * V_69 ,
struct V_26 * V_31 )
{
struct V_26 * V_29 = F_52 ( V_69 ) ;
unsigned long V_58 ;
F_61 ( V_31 , V_29 ) ;
F_53 ( V_29 , V_31 -> V_33 , V_31 ) ;
F_51 ( V_31 ) ;
F_57 ( V_69 ) ;
for ( V_58 = F_26 ( V_31 ) ; V_58 ; ) {
struct V_26 * V_62 = F_50 ( V_31 , -- V_58 ) ;
if ( F_47 ( V_31 , V_62 ) )
V_31 = F_62 ( V_68 , V_62 ) ;
}
return V_29 ;
}
static struct V_26 * F_63 ( struct V_67 * V_68 ,
struct V_26 * V_69 )
{
struct V_26 * V_31 ;
unsigned long V_58 ;
T_3 V_70 ;
F_46 ( L_2 ) ;
V_31 = F_44 ( V_69 -> V_33 , V_69 -> V_37 - 1 , V_69 -> V_32 + 1 ) ;
if ( ! V_31 )
goto V_71;
F_55 ( V_69 ) ;
for ( V_58 = F_26 ( V_69 ) , V_70 = 1u << V_31 -> V_37 ; V_58 ; ) {
struct V_26 * V_62 = F_50 ( V_69 , -- V_58 ) ;
struct V_26 * V_72 , * V_73 ;
unsigned long V_74 , V_75 ;
if ( ! V_62 )
continue;
if ( ! F_47 ( V_69 , V_62 ) ) {
F_49 ( V_31 , F_27 ( V_62 -> V_33 , V_31 ) , V_62 ) ;
continue;
}
F_56 ( V_69 , V_62 ) ;
if ( V_62 -> V_32 == 1 ) {
F_49 ( V_31 , 2 * V_58 + 1 , F_50 ( V_62 , 1 ) ) ;
F_49 ( V_31 , 2 * V_58 , F_50 ( V_62 , 0 ) ) ;
continue;
}
V_73 = F_44 ( V_62 -> V_33 | V_70 , V_62 -> V_37 , V_62 -> V_32 - 1 ) ;
if ( ! V_73 )
goto V_76;
V_72 = F_44 ( V_62 -> V_33 , V_62 -> V_37 , V_62 -> V_32 - 1 ) ;
F_56 ( V_31 , V_73 ) ;
if ( ! V_72 )
goto V_76;
F_56 ( V_31 , V_72 ) ;
for ( V_75 = F_26 ( V_62 ) , V_74 = V_75 / 2 ; V_74 ; ) {
F_49 ( V_73 , -- V_74 , F_50 ( V_62 , -- V_75 ) ) ;
F_49 ( V_72 , V_74 , F_50 ( V_62 , V_74 ) ) ;
F_49 ( V_73 , -- V_74 , F_50 ( V_62 , -- V_75 ) ) ;
F_49 ( V_72 , V_74 , F_50 ( V_62 , V_74 ) ) ;
}
F_61 ( V_73 , V_31 ) ;
F_61 ( V_72 , V_31 ) ;
F_49 ( V_31 , 2 * V_58 + 1 , V_73 ) ;
F_49 ( V_31 , 2 * V_58 , V_72 ) ;
}
return F_60 ( V_68 , V_69 , V_31 ) ;
V_76:
F_57 ( V_31 ) ;
V_71:
return NULL ;
}
static struct V_26 * F_64 ( struct V_67 * V_68 ,
struct V_26 * V_69 )
{
struct V_26 * V_31 ;
unsigned long V_58 ;
F_46 ( L_3 ) ;
V_31 = F_44 ( V_69 -> V_33 , V_69 -> V_37 + 1 , V_69 -> V_32 - 1 ) ;
if ( ! V_31 )
goto V_71;
F_55 ( V_69 ) ;
for ( V_58 = F_26 ( V_69 ) ; V_58 ; ) {
struct V_26 * V_73 = F_50 ( V_69 , -- V_58 ) ;
struct V_26 * V_72 = F_50 ( V_69 , -- V_58 ) ;
struct V_26 * V_62 ;
if ( ! V_73 || ! V_72 ) {
F_49 ( V_31 , V_58 / 2 , V_73 ? : V_72 ) ;
continue;
}
V_62 = F_44 ( V_72 -> V_33 , V_69 -> V_37 , 1 ) ;
if ( ! V_62 )
goto V_76;
F_56 ( V_31 , V_62 ) ;
F_49 ( V_62 , 1 , V_73 ) ;
F_49 ( V_62 , 0 , V_72 ) ;
F_61 ( V_62 , V_31 ) ;
F_49 ( V_31 , V_58 / 2 , V_62 ) ;
}
return F_60 ( V_68 , V_69 , V_31 ) ;
V_76:
F_57 ( V_31 ) ;
V_71:
return NULL ;
}
static struct V_26 * F_65 ( struct V_67 * V_68 ,
struct V_26 * V_69 )
{
struct V_26 * V_28 , * V_29 ;
unsigned long V_58 ;
for ( V_28 = NULL , V_58 = F_26 ( V_69 ) ; ! V_28 && V_58 ; )
V_28 = F_50 ( V_69 , -- V_58 ) ;
V_29 = F_52 ( V_69 ) ;
F_53 ( V_29 , V_69 -> V_33 , V_28 ) ;
F_24 ( V_28 , V_29 ) ;
F_58 ( V_69 ) ;
return V_29 ;
}
static unsigned char F_66 ( struct V_26 * V_31 )
{
unsigned char V_53 = V_31 -> V_37 ;
unsigned long V_77 , V_58 ;
unsigned char V_78 ;
V_78 = F_67 (unsigned char, tn->pos + tn->bits - 1 , tn->slen) ;
for ( V_58 = 0 , V_77 = 0x2ul ; V_58 < F_26 ( V_31 ) ; V_58 += V_77 ) {
struct V_26 * V_28 = F_50 ( V_31 , V_58 ) ;
if ( ! V_28 || ( V_28 -> V_53 <= V_53 ) )
continue;
V_77 <<= ( V_28 -> V_53 - V_53 ) ;
V_53 = V_28 -> V_53 ;
V_58 &= ~ ( V_77 - 1 ) ;
if ( V_53 >= V_78 )
break;
}
V_31 -> V_53 = V_53 ;
return V_53 ;
}
static inline bool F_68 ( struct V_26 * V_29 , struct V_26 * V_31 )
{
unsigned long V_79 = F_26 ( V_31 ) ;
unsigned long V_80 = V_79 ;
V_80 *= F_54 ( V_29 ) ? V_81 : V_82 ;
V_79 -= F_22 ( V_31 ) -> V_50 ;
V_79 += F_22 ( V_31 ) -> V_51 ;
return ( V_79 > 1 ) && V_31 -> V_37 && ( ( 50 * V_79 ) >= V_80 ) ;
}
static inline bool F_69 ( struct V_26 * V_29 , struct V_26 * V_31 )
{
unsigned long V_79 = F_26 ( V_31 ) ;
unsigned long V_80 = V_79 ;
V_80 *= F_54 ( V_29 ) ? V_83 : V_84 ;
V_79 -= F_22 ( V_31 ) -> V_50 ;
return ( V_79 > 1 ) && ( V_31 -> V_32 > 1 ) && ( ( 100 * V_79 ) < V_80 ) ;
}
static inline bool F_70 ( struct V_26 * V_31 )
{
unsigned long V_79 = F_26 ( V_31 ) ;
V_79 -= F_22 ( V_31 ) -> V_50 ;
if ( ( V_31 -> V_32 == V_36 ) && F_22 ( V_31 ) -> V_51 )
V_79 -= V_85 ;
return V_79 < 2 ;
}
static struct V_26 * F_62 ( struct V_67 * V_68 , struct V_26 * V_31 )
{
#ifdef F_71
struct V_86 T_5 * V_87 = V_68 -> V_87 ;
#endif
struct V_26 * V_29 = F_52 ( V_31 ) ;
unsigned long V_88 = F_27 ( V_31 -> V_33 , V_29 ) ;
int V_89 = V_90 ;
F_46 ( L_4 ,
V_31 , V_82 , V_84 ) ;
F_45 ( V_31 != F_50 ( V_29 , V_88 ) ) ;
while ( F_68 ( V_29 , V_31 ) && V_89 ) {
V_29 = F_63 ( V_68 , V_31 ) ;
if ( ! V_29 ) {
#ifdef F_71
F_72 ( V_87 -> V_91 ) ;
#endif
break;
}
V_89 -- ;
V_31 = F_50 ( V_29 , V_88 ) ;
}
V_29 = F_52 ( V_31 ) ;
if ( V_89 != V_90 )
return V_29 ;
while ( F_69 ( V_29 , V_31 ) && V_89 ) {
V_29 = F_64 ( V_68 , V_31 ) ;
if ( ! V_29 ) {
#ifdef F_71
F_72 ( V_87 -> V_91 ) ;
#endif
break;
}
V_89 -- ;
V_31 = F_50 ( V_29 , V_88 ) ;
}
if ( F_70 ( V_31 ) )
return F_65 ( V_68 , V_31 ) ;
return F_52 ( V_31 ) ;
}
static void F_73 ( struct V_26 * V_31 , unsigned char V_53 )
{
unsigned char V_92 = V_31 -> V_53 ;
while ( ( V_92 > V_31 -> V_37 ) && ( V_92 > V_53 ) ) {
V_53 = F_66 ( V_31 ) ;
if ( V_92 == V_53 )
break;
V_31 = F_52 ( V_31 ) ;
V_92 = V_31 -> V_53 ;
}
}
static void F_74 ( struct V_26 * V_31 , unsigned char V_53 )
{
while ( V_31 -> V_53 < V_53 ) {
V_31 -> V_53 = V_53 ;
V_31 = F_52 ( V_31 ) ;
}
}
static struct V_26 * F_75 ( struct V_67 * V_68 ,
struct V_26 * * V_29 , T_1 V_33 )
{
struct V_26 * V_93 , * V_28 = V_68 -> V_27 ;
unsigned long V_34 = 0 ;
do {
V_93 = V_28 ;
V_28 = F_76 ( V_28 , V_34 ) ;
if ( ! V_28 )
break;
V_34 = F_77 ( V_33 , V_28 ) ;
if ( V_34 >= ( 1ul << V_28 -> V_32 ) ) {
V_28 = NULL ;
break;
}
} while ( F_48 ( V_28 ) );
* V_29 = V_93 ;
return V_28 ;
}
static struct V_40 * F_78 ( struct V_94 * V_95 , T_2 V_53 ,
T_2 V_16 , T_1 V_96 , T_1 V_17 )
{
struct V_40 * V_41 ;
if ( ! V_95 )
return NULL ;
F_79 (fa, fah, fa_list) {
if ( V_41 -> V_54 < V_53 )
continue;
if ( V_41 -> V_54 != V_53 )
break;
if ( V_41 -> V_17 > V_17 )
continue;
if ( V_41 -> V_17 != V_17 )
break;
if ( V_41 -> V_97 > V_16 )
continue;
if ( V_41 -> V_98 -> V_99 >= V_96 || V_41 -> V_97 < V_16 )
return V_41 ;
}
return NULL ;
}
static void F_80 ( struct V_67 * V_68 , struct V_26 * V_31 )
{
while ( ! F_54 ( V_31 ) )
V_31 = F_62 ( V_68 , V_31 ) ;
}
static int F_81 ( struct V_67 * V_68 , struct V_26 * V_29 ,
struct V_40 * V_100 , T_3 V_33 )
{
struct V_26 * V_28 , * V_52 ;
V_52 = F_40 ( V_33 , V_100 ) ;
if ( ! V_52 )
goto V_101;
V_28 = F_50 ( V_29 , F_27 ( V_33 , V_29 ) ) ;
if ( V_28 ) {
struct V_26 * V_31 ;
V_31 = F_44 ( V_33 , F_82 ( V_33 ^ V_28 -> V_33 ) , 1 ) ;
if ( ! V_31 )
goto V_71;
F_61 ( V_31 , V_29 ) ;
F_49 ( V_31 , F_27 ( V_33 , V_31 ) ^ 1 , V_28 ) ;
F_53 ( V_29 , V_33 , V_31 ) ;
F_24 ( V_28 , V_31 ) ;
V_29 = V_31 ;
}
F_74 ( V_29 , V_100 -> V_54 ) ;
F_61 ( V_52 , V_29 ) ;
F_53 ( V_29 , V_33 , V_52 ) ;
F_80 ( V_68 , V_29 ) ;
return 0 ;
V_71:
F_58 ( V_52 ) ;
V_101:
return - V_102 ;
}
static int F_83 ( struct V_67 * V_68 , struct V_26 * V_29 ,
struct V_26 * V_52 , struct V_40 * V_100 ,
struct V_40 * V_41 , T_3 V_33 )
{
if ( ! V_52 )
return F_81 ( V_68 , V_29 , V_100 , V_33 ) ;
if ( V_41 ) {
F_84 ( & V_100 -> V_56 , & V_41 -> V_56 ) ;
} else {
struct V_40 * V_103 ;
F_79 (last, &l->leaf, fa_list) {
if ( V_100 -> V_54 < V_103 -> V_54 )
break;
if ( ( V_100 -> V_54 == V_103 -> V_54 ) &&
( V_100 -> V_17 > V_103 -> V_17 ) )
break;
V_41 = V_103 ;
}
if ( V_41 )
F_85 ( & V_100 -> V_56 , & V_41 -> V_56 ) ;
else
F_86 ( & V_100 -> V_56 , & V_52 -> V_55 ) ;
}
if ( V_52 -> V_53 < V_100 -> V_54 ) {
V_52 -> V_53 = V_100 -> V_54 ;
F_74 ( V_29 , V_100 -> V_54 ) ;
}
return 0 ;
}
int F_87 ( struct V_2 * V_2 , struct V_104 * V_105 ,
struct V_106 * V_107 )
{
enum V_6 V_108 = V_22 ;
struct V_67 * V_68 = (struct V_67 * ) V_105 -> V_109 ;
struct V_40 * V_41 , * V_110 ;
struct V_26 * V_52 , * V_29 ;
T_6 V_111 = V_112 ;
struct V_14 * V_15 ;
T_2 V_113 = V_107 -> V_114 ;
T_2 V_53 = V_36 - V_113 ;
T_2 V_16 = V_107 -> V_115 ;
T_1 V_33 ;
int V_116 ;
if ( V_113 > V_36 )
return - V_117 ;
V_33 = F_88 ( V_107 -> V_118 ) ;
F_46 ( L_5 , V_105 -> V_17 , V_33 , V_113 ) ;
if ( ( V_113 < V_36 ) && ( V_33 << V_113 ) )
return - V_117 ;
V_15 = F_89 ( V_107 ) ;
if ( F_90 ( V_15 ) ) {
V_116 = F_91 ( V_15 ) ;
goto V_116;
}
V_52 = F_75 ( V_68 , & V_29 , V_33 ) ;
V_41 = V_52 ? F_78 ( & V_52 -> V_55 , V_53 , V_16 , V_15 -> V_99 ,
V_105 -> V_17 ) : NULL ;
if ( V_41 && V_41 -> V_97 == V_16 &&
V_41 -> V_98 -> V_99 == V_15 -> V_99 ) {
struct V_40 * V_119 , * V_120 ;
V_116 = - V_121 ;
if ( V_107 -> V_122 & V_112 )
goto V_123;
V_111 &= ~ V_112 ;
V_120 = NULL ;
V_119 = V_41 ;
F_92 (fa, fa_list) {
if ( ( V_41 -> V_54 != V_53 ) ||
( V_41 -> V_17 != V_105 -> V_17 ) ||
( V_41 -> V_97 != V_16 ) )
break;
if ( V_41 -> V_98 -> V_99 != V_15 -> V_99 )
break;
if ( V_41 -> V_124 == V_107 -> V_125 &&
V_41 -> V_98 == V_15 ) {
V_120 = V_41 ;
break;
}
}
if ( V_107 -> V_122 & V_126 ) {
struct V_14 * V_127 ;
T_2 V_128 ;
V_111 |= V_126 ;
V_41 = V_119 ;
if ( V_120 ) {
if ( V_41 == V_120 )
V_116 = 0 ;
goto V_123;
}
V_116 = - V_129 ;
V_110 = F_41 ( V_43 , V_49 ) ;
if ( ! V_110 )
goto V_123;
V_127 = V_41 -> V_98 ;
V_110 -> V_97 = V_41 -> V_97 ;
V_110 -> V_98 = V_15 ;
V_110 -> V_124 = V_107 -> V_125 ;
V_128 = V_41 -> V_130 ;
V_110 -> V_130 = V_128 & ~ V_131 ;
V_110 -> V_54 = V_41 -> V_54 ;
V_110 -> V_17 = V_105 -> V_17 ;
V_110 -> V_132 = - 1 ;
F_21 ( V_2 , V_133 ,
V_33 , V_113 , V_15 ,
V_110 -> V_97 , V_107 -> V_125 ,
V_105 -> V_17 ) ;
F_93 ( V_134 , F_94 ( V_33 ) , V_110 , V_113 ,
V_105 -> V_17 , & V_107 -> V_135 , V_111 ) ;
F_95 ( & V_41 -> V_56 , & V_110 -> V_56 ) ;
F_30 ( V_41 ) ;
F_96 ( V_127 ) ;
if ( V_128 & V_131 )
F_97 ( V_107 -> V_135 . V_136 ) ;
goto V_137;
}
if ( V_120 )
goto V_123;
if ( V_107 -> V_122 & V_138 ) {
V_108 = V_139 ;
V_111 |= V_138 ;
} else {
V_41 = V_119 ;
}
}
V_116 = - V_140 ;
if ( ! ( V_107 -> V_122 & V_141 ) )
goto V_123;
V_111 |= V_141 ;
V_116 = - V_129 ;
V_110 = F_41 ( V_43 , V_49 ) ;
if ( ! V_110 )
goto V_123;
V_110 -> V_98 = V_15 ;
V_110 -> V_97 = V_16 ;
V_110 -> V_124 = V_107 -> V_125 ;
V_110 -> V_130 = 0 ;
V_110 -> V_54 = V_53 ;
V_110 -> V_17 = V_105 -> V_17 ;
V_110 -> V_132 = - 1 ;
V_116 = F_83 ( V_68 , V_29 , V_52 , V_110 , V_41 , V_33 ) ;
if ( V_116 )
goto V_142;
if ( ! V_113 )
V_105 -> V_143 ++ ;
F_97 ( V_107 -> V_135 . V_136 ) ;
F_21 ( V_2 , V_108 , V_33 , V_113 , V_15 , V_16 , V_107 -> V_125 ,
V_105 -> V_17 ) ;
F_93 ( V_134 , F_94 ( V_33 ) , V_110 , V_113 , V_110 -> V_17 ,
& V_107 -> V_135 , V_111 ) ;
V_137:
return 0 ;
V_142:
F_29 ( V_43 , V_110 ) ;
V_123:
F_96 ( V_15 ) ;
V_116:
return V_116 ;
}
static inline T_3 F_98 ( T_3 V_33 , struct V_26 * V_28 )
{
T_3 V_144 = V_28 -> V_33 ;
return ( V_33 ^ V_144 ) & ( V_144 | - V_144 ) ;
}
int F_99 ( struct V_104 * V_105 , const struct V_145 * V_146 ,
struct V_147 * V_148 , int V_149 )
{
struct V_67 * V_68 = (struct V_67 * ) V_105 -> V_109 ;
#ifdef F_71
struct V_86 T_5 * V_87 = V_68 -> V_87 ;
#endif
const T_3 V_33 = F_88 ( V_146 -> V_150 ) ;
struct V_26 * V_28 , * V_93 ;
struct V_40 * V_41 ;
unsigned long V_34 ;
T_3 V_88 ;
F_100 ( V_105 -> V_17 , V_146 ) ;
V_93 = V_68 -> V_27 ;
V_88 = 0 ;
V_28 = F_76 ( V_93 , V_88 ) ;
if ( ! V_28 )
return - V_151 ;
#ifdef F_71
F_72 ( V_87 -> gets ) ;
#endif
for (; ; ) {
V_34 = F_77 ( V_33 , V_28 ) ;
if ( V_34 >= ( 1ul << V_28 -> V_32 ) )
break;
if ( F_101 ( V_28 ) )
goto V_152;
if ( V_28 -> V_53 > V_28 -> V_37 ) {
V_93 = V_28 ;
V_88 = V_34 ;
}
V_28 = F_76 ( V_28 , V_34 ) ;
if ( F_102 ( ! V_28 ) )
goto V_153;
}
for (; ; ) {
struct V_26 T_7 * * V_154 = V_28 -> V_25 ;
if ( F_102 ( F_98 ( V_33 , V_28 ) ) || ( V_28 -> V_53 == V_28 -> V_37 ) )
goto V_153;
if ( F_102 ( F_101 ( V_28 ) ) )
break;
while ( ( V_28 = F_103 ( * V_154 ) ) == NULL ) {
V_153:
#ifdef F_71
if ( ! V_28 )
F_72 ( V_87 -> V_155 ) ;
#endif
while ( ! V_88 ) {
T_3 V_156 = V_93 -> V_33 ;
if ( F_54 ( V_93 ) )
return - V_151 ;
#ifdef F_71
F_72 ( V_87 -> V_157 ) ;
#endif
V_93 = F_104 ( V_93 ) ;
V_88 = F_27 ( V_156 , V_93 ) ;
}
V_88 &= V_88 - 1 ;
V_154 = & V_93 -> V_25 [ V_88 ] ;
}
}
V_152:
V_34 = V_33 ^ V_28 -> V_33 ;
F_105 (fa, &n->leaf, fa_list) {
struct V_14 * V_15 = V_41 -> V_98 ;
int V_158 , V_116 ;
if ( ( V_35 > V_36 ) || ( V_41 -> V_54 < V_36 ) ) {
if ( V_34 >= ( 1ul << V_41 -> V_54 ) )
continue;
}
if ( V_41 -> V_97 && V_41 -> V_97 != V_146 -> V_159 )
continue;
if ( V_15 -> V_160 )
continue;
if ( V_41 -> V_98 -> V_161 < V_146 -> V_162 )
continue;
F_106 ( V_41 ) ;
V_116 = V_163 [ V_41 -> V_124 ] . error ;
if ( F_102 ( V_116 < 0 ) ) {
#ifdef F_71
F_72 ( V_87 -> V_164 ) ;
#endif
return V_116 ;
}
if ( V_15 -> V_149 & V_165 )
continue;
for ( V_158 = 0 ; V_158 < V_15 -> V_166 ; V_158 ++ ) {
const struct V_167 * V_168 = & V_15 -> V_167 [ V_158 ] ;
struct V_169 * V_170 = F_107 ( V_168 -> V_171 ) ;
if ( V_168 -> V_172 & V_165 )
continue;
if ( V_170 &&
F_108 ( V_170 ) &&
V_168 -> V_172 & V_173 &&
! ( V_149 & V_174 ) )
continue;
if ( ! ( V_146 -> V_175 & V_176 ) ) {
if ( V_146 -> V_177 &&
V_146 -> V_177 != V_168 -> V_178 )
continue;
}
if ( ! ( V_149 & V_179 ) )
F_109 ( & V_15 -> V_180 ) ;
V_148 -> V_181 = V_36 - V_41 -> V_54 ;
V_148 -> V_182 = V_158 ;
V_148 -> type = V_41 -> V_124 ;
V_148 -> V_183 = V_15 -> V_161 ;
V_148 -> V_15 = V_15 ;
V_148 -> V_184 = V_105 ;
V_148 -> V_185 = & V_28 -> V_55 ;
#ifdef F_71
F_72 ( V_87 -> V_164 ) ;
#endif
F_110 ( V_168 ) ;
return V_116 ;
}
}
#ifdef F_71
F_72 ( V_87 -> V_186 ) ;
#endif
goto V_153;
}
static void F_111 ( struct V_67 * V_68 , struct V_26 * V_29 ,
struct V_26 * V_52 , struct V_40 * V_187 )
{
struct V_188 * * V_189 = V_187 -> V_56 . V_189 ;
struct V_40 * V_41 = F_112 ( V_189 , F_113 ( * V_41 ) , V_56 . V_63 ) ;
F_114 ( & V_187 -> V_56 ) ;
if ( F_115 ( & V_52 -> V_55 ) ) {
if ( V_29 -> V_53 == V_52 -> V_53 )
F_73 ( V_29 , V_29 -> V_37 ) ;
F_53 ( V_29 , V_52 -> V_33 , NULL ) ;
F_58 ( V_52 ) ;
F_80 ( V_68 , V_29 ) ;
return;
}
if ( * V_189 )
return;
V_52 -> V_53 = V_41 -> V_54 ;
F_73 ( V_29 , V_41 -> V_54 ) ;
}
int F_116 ( struct V_2 * V_2 , struct V_104 * V_105 ,
struct V_106 * V_107 )
{
struct V_67 * V_68 = (struct V_67 * ) V_105 -> V_109 ;
struct V_40 * V_41 , * V_190 ;
struct V_26 * V_52 , * V_29 ;
T_2 V_113 = V_107 -> V_114 ;
T_2 V_53 = V_36 - V_113 ;
T_2 V_16 = V_107 -> V_115 ;
T_1 V_33 ;
if ( V_113 > V_36 )
return - V_117 ;
V_33 = F_88 ( V_107 -> V_118 ) ;
if ( ( V_113 < V_36 ) && ( V_33 << V_113 ) )
return - V_117 ;
V_52 = F_75 ( V_68 , & V_29 , V_33 ) ;
if ( ! V_52 )
return - V_191 ;
V_41 = F_78 ( & V_52 -> V_55 , V_53 , V_16 , 0 , V_105 -> V_17 ) ;
if ( ! V_41 )
return - V_191 ;
F_46 ( L_6 , V_33 , V_113 , V_16 , V_68 ) ;
V_190 = NULL ;
F_92 (fa, fa_list) {
struct V_14 * V_15 = V_41 -> V_98 ;
if ( ( V_41 -> V_54 != V_53 ) ||
( V_41 -> V_17 != V_105 -> V_17 ) ||
( V_41 -> V_97 != V_16 ) )
break;
if ( ( ! V_107 -> V_125 || V_41 -> V_124 == V_107 -> V_125 ) &&
( V_107 -> V_192 == V_193 ||
V_41 -> V_98 -> V_161 == V_107 -> V_192 ) &&
( ! V_107 -> V_194 ||
V_15 -> V_195 == V_107 -> V_194 ) &&
( ! V_107 -> V_196 ||
V_15 -> V_197 == V_107 -> V_196 ) &&
F_117 ( V_107 , V_15 ) == 0 ) {
V_190 = V_41 ;
break;
}
}
if ( ! V_190 )
return - V_191 ;
F_21 ( V_2 , V_198 , V_33 , V_113 ,
V_190 -> V_98 , V_16 ,
V_190 -> V_124 , V_105 -> V_17 ) ;
F_93 ( V_199 , F_94 ( V_33 ) , V_190 , V_113 , V_105 -> V_17 ,
& V_107 -> V_135 , 0 ) ;
if ( ! V_113 )
V_105 -> V_143 -- ;
F_111 ( V_68 , V_29 , V_52 , V_190 ) ;
if ( V_190 -> V_130 & V_131 )
F_97 ( V_107 -> V_135 . V_136 ) ;
F_96 ( V_190 -> V_98 ) ;
F_30 ( V_190 ) ;
return 0 ;
}
static struct V_26 * F_118 ( struct V_26 * * V_31 , T_3 V_33 )
{
struct V_26 * V_93 , * V_28 = * V_31 ;
unsigned long V_88 ;
do {
V_93 = V_28 ;
V_88 = ( V_33 > V_93 -> V_33 ) ? F_27 ( V_33 , V_93 ) : 0 ;
if ( V_88 >> V_93 -> V_32 )
break;
V_28 = F_76 ( V_93 , V_88 ++ ) ;
if ( ! V_28 )
break;
if ( F_101 ( V_28 ) && ( V_28 -> V_33 >= V_33 ) )
goto V_152;
} while ( F_48 ( V_28 ) );
while ( ! F_54 ( V_93 ) ) {
if ( V_88 >= ( 1ul << V_93 -> V_32 ) ) {
T_3 V_156 = V_93 -> V_33 ;
V_93 = F_104 ( V_93 ) ;
V_88 = F_27 ( V_156 , V_93 ) + 1 ;
continue;
}
V_28 = F_76 ( V_93 , V_88 ++ ) ;
if ( ! V_28 )
continue;
if ( F_101 ( V_28 ) )
goto V_152;
V_93 = V_28 ;
V_88 = 0 ;
}
* V_31 = V_93 ;
return NULL ;
V_152:
* V_31 = V_93 ;
return V_28 ;
}
static void F_119 ( struct V_104 * V_105 )
{
struct V_67 * V_68 = (struct V_67 * ) V_105 -> V_109 ;
struct V_26 * V_93 = V_68 -> V_27 ;
unsigned long V_88 = 1 ;
struct V_188 * V_200 ;
struct V_40 * V_41 ;
for (; ; ) {
struct V_26 * V_28 ;
if ( ! ( V_88 -- ) ) {
T_3 V_156 = V_93 -> V_33 ;
if ( F_54 ( V_93 ) )
break;
V_28 = V_93 ;
V_93 = F_52 ( V_93 ) ;
F_53 ( V_93 , V_28 -> V_33 , NULL ) ;
F_58 ( V_28 ) ;
V_88 = F_27 ( V_156 , V_93 ) ;
continue;
}
V_28 = F_50 ( V_93 , V_88 ) ;
if ( ! V_28 )
continue;
if ( F_48 ( V_28 ) ) {
V_93 = V_28 ;
V_88 = 1ul << V_28 -> V_32 ;
continue;
}
F_120 (fa, tmp, &n->leaf, fa_list) {
F_114 ( & V_41 -> V_56 ) ;
F_30 ( V_41 ) ;
}
F_53 ( V_93 , V_28 -> V_33 , NULL ) ;
F_58 ( V_28 ) ;
}
#ifdef F_71
F_121 ( V_68 -> V_87 ) ;
#endif
F_122 ( V_105 ) ;
}
struct V_104 * F_123 ( struct V_104 * V_201 )
{
struct V_67 * V_202 = (struct V_67 * ) V_201 -> V_109 ;
struct V_26 * V_52 , * V_29 = V_202 -> V_27 ;
struct V_104 * V_203 ;
struct V_40 * V_41 ;
struct V_67 * V_204 ;
T_3 V_33 = 0 ;
if ( V_201 -> V_109 == V_201 -> V_205 )
return V_201 ;
V_203 = F_124 ( V_206 , NULL ) ;
if ( ! V_203 )
return NULL ;
V_204 = (struct V_67 * ) V_203 -> V_109 ;
while ( ( V_52 = F_118 ( & V_29 , V_33 ) ) != NULL ) {
struct V_26 * V_207 = NULL , * V_208 ;
F_105 (fa, &l->leaf, fa_list) {
struct V_40 * V_110 ;
if ( V_203 -> V_17 != V_41 -> V_17 )
continue;
V_110 = F_41 ( V_43 , V_49 ) ;
if ( ! V_110 )
goto V_123;
memcpy ( V_110 , V_41 , sizeof( * V_41 ) ) ;
if ( ! V_207 )
V_207 = F_75 ( V_204 , & V_208 , V_52 -> V_33 ) ;
if ( F_83 ( V_204 , V_208 , V_207 , V_110 ,
NULL , V_52 -> V_33 ) ) {
F_29 ( V_43 , V_110 ) ;
goto V_123;
}
}
V_33 = V_52 -> V_33 + 1 ;
if ( V_33 < V_52 -> V_33 )
break;
}
return V_203 ;
V_123:
F_119 ( V_203 ) ;
return NULL ;
}
void F_125 ( struct V_104 * V_105 )
{
struct V_67 * V_68 = (struct V_67 * ) V_105 -> V_109 ;
struct V_26 * V_93 = V_68 -> V_27 ;
unsigned long V_88 = 1 ;
struct V_188 * V_200 ;
struct V_40 * V_41 ;
for (; ; ) {
unsigned char V_53 = 0 ;
struct V_26 * V_28 ;
if ( ! ( V_88 -- ) ) {
T_3 V_156 = V_93 -> V_33 ;
if ( F_54 ( V_93 ) )
break;
if ( V_93 -> V_53 > V_93 -> V_37 )
F_66 ( V_93 ) ;
V_93 = F_62 ( V_68 , V_93 ) ;
V_88 = F_27 ( V_156 , V_93 ) ;
continue;
}
V_28 = F_50 ( V_93 , V_88 ) ;
if ( ! V_28 )
continue;
if ( F_48 ( V_28 ) ) {
V_93 = V_28 ;
V_88 = 1ul << V_28 -> V_32 ;
continue;
}
F_120 (fa, tmp, &n->leaf, fa_list) {
if ( V_105 -> V_17 != V_41 -> V_17 ) {
F_114 ( & V_41 -> V_56 ) ;
F_30 ( V_41 ) ;
continue;
}
V_53 = V_41 -> V_54 ;
}
V_28 -> V_53 = V_53 ;
if ( F_115 ( & V_28 -> V_55 ) ) {
F_53 ( V_93 , V_28 -> V_33 , NULL ) ;
F_58 ( V_28 ) ;
}
}
}
int F_126 ( struct V_2 * V_2 , struct V_104 * V_105 )
{
struct V_67 * V_68 = (struct V_67 * ) V_105 -> V_109 ;
struct V_26 * V_93 = V_68 -> V_27 ;
unsigned long V_88 = 1 ;
struct V_188 * V_200 ;
struct V_40 * V_41 ;
int V_152 = 0 ;
for (; ; ) {
unsigned char V_53 = 0 ;
struct V_26 * V_28 ;
if ( ! ( V_88 -- ) ) {
T_3 V_156 = V_93 -> V_33 ;
if ( F_54 ( V_93 ) )
break;
if ( V_93 -> V_53 > V_93 -> V_37 )
F_66 ( V_93 ) ;
V_93 = F_62 ( V_68 , V_93 ) ;
V_88 = F_27 ( V_156 , V_93 ) ;
continue;
}
V_28 = F_50 ( V_93 , V_88 ) ;
if ( ! V_28 )
continue;
if ( F_48 ( V_28 ) ) {
V_93 = V_28 ;
V_88 = 1ul << V_28 -> V_32 ;
continue;
}
F_120 (fa, tmp, &n->leaf, fa_list) {
struct V_14 * V_15 = V_41 -> V_98 ;
if ( ! V_15 || ! ( V_15 -> V_149 & V_165 ) ||
V_105 -> V_17 != V_41 -> V_17 ) {
V_53 = V_41 -> V_54 ;
continue;
}
F_21 ( V_2 , V_198 ,
V_28 -> V_33 ,
V_36 - V_41 -> V_54 ,
V_15 , V_41 -> V_97 , V_41 -> V_124 ,
V_105 -> V_17 ) ;
F_114 ( & V_41 -> V_56 ) ;
F_96 ( V_41 -> V_98 ) ;
F_30 ( V_41 ) ;
V_152 ++ ;
}
V_28 -> V_53 = V_53 ;
if ( F_115 ( & V_28 -> V_55 ) ) {
F_53 ( V_93 , V_28 -> V_33 , NULL ) ;
F_58 ( V_28 ) ;
}
}
F_46 ( L_7 , V_152 ) ;
return V_152 ;
}
static void F_127 ( struct V_2 * V_2 , struct V_26 * V_52 ,
struct V_104 * V_105 , struct V_4 * V_5 ,
enum V_6 V_7 )
{
struct V_40 * V_41 ;
F_105 (fa, &l->leaf, fa_list) {
struct V_14 * V_15 = V_41 -> V_98 ;
if ( ! V_15 )
continue;
if ( V_105 -> V_17 != V_41 -> V_17 )
continue;
F_8 ( V_5 , V_2 , V_7 , V_52 -> V_33 ,
V_36 - V_41 -> V_54 , V_15 , V_41 -> V_97 ,
V_41 -> V_124 , V_41 -> V_17 ) ;
}
}
static void F_128 ( struct V_2 * V_2 , struct V_104 * V_105 ,
struct V_4 * V_5 ,
enum V_6 V_7 )
{
struct V_67 * V_68 = (struct V_67 * ) V_105 -> V_109 ;
struct V_26 * V_52 , * V_29 = V_68 -> V_27 ;
T_3 V_33 = 0 ;
while ( ( V_52 = F_118 ( & V_29 , V_33 ) ) != NULL ) {
F_127 ( V_2 , V_52 , V_105 , V_5 , V_7 ) ;
V_33 = V_52 -> V_33 + 1 ;
if ( V_33 < V_52 -> V_33 )
break;
}
}
static void F_16 ( struct V_2 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 )
{
unsigned int V_209 ;
for ( V_209 = 0 ; V_209 < V_210 ; V_209 ++ ) {
struct V_94 * V_39 = & V_2 -> V_3 . V_211 [ V_209 ] ;
struct V_104 * V_105 ;
F_105 (tb, head, tb_hlist)
F_128 ( V_2 , V_105 , V_5 , V_7 ) ;
}
}
static void F_129 ( struct V_38 * V_39 )
{
struct V_104 * V_105 = F_23 ( V_39 , struct V_104 , V_42 ) ;
#ifdef F_71
struct V_67 * V_68 = (struct V_67 * ) V_105 -> V_109 ;
if ( V_105 -> V_109 == V_105 -> V_205 )
F_121 ( V_68 -> V_87 ) ;
#endif
F_122 ( V_105 ) ;
}
void F_130 ( struct V_104 * V_105 )
{
F_31 ( & V_105 -> V_42 , F_129 ) ;
}
static int F_131 ( struct V_26 * V_52 , struct V_104 * V_105 ,
struct V_212 * V_213 , struct V_214 * F_10 )
{
T_8 V_215 = F_94 ( V_52 -> V_33 ) ;
struct V_40 * V_41 ;
int V_58 , V_216 ;
V_216 = F_10 -> args [ 4 ] ;
V_58 = 0 ;
F_105 (fa, &l->leaf, fa_list) {
if ( V_58 < V_216 ) {
V_58 ++ ;
continue;
}
if ( V_105 -> V_17 != V_41 -> V_17 ) {
V_58 ++ ;
continue;
}
if ( F_132 ( V_213 , F_133 ( F_10 -> V_213 ) . V_217 ,
F_10 -> V_218 -> V_219 ,
V_134 ,
V_105 -> V_17 ,
V_41 -> V_124 ,
V_215 ,
V_36 - V_41 -> V_54 ,
V_41 -> V_97 ,
V_41 -> V_98 , V_220 ) < 0 ) {
F_10 -> args [ 4 ] = V_58 ;
return - 1 ;
}
V_58 ++ ;
}
F_10 -> args [ 4 ] = V_58 ;
return V_213 -> V_221 ;
}
int F_134 ( struct V_104 * V_105 , struct V_212 * V_213 ,
struct V_214 * F_10 )
{
struct V_67 * V_68 = (struct V_67 * ) V_105 -> V_109 ;
struct V_26 * V_52 , * V_29 = V_68 -> V_27 ;
int V_222 = F_10 -> args [ 2 ] ;
T_3 V_33 = F_10 -> args [ 3 ] ;
while ( ( V_52 = F_118 ( & V_29 , V_33 ) ) != NULL ) {
if ( F_131 ( V_52 , V_105 , V_213 , F_10 ) < 0 ) {
F_10 -> args [ 3 ] = V_33 ;
F_10 -> args [ 2 ] = V_222 ;
return - 1 ;
}
++ V_222 ;
V_33 = V_52 -> V_33 + 1 ;
memset ( & F_10 -> args [ 4 ] , 0 ,
sizeof( F_10 -> args ) - 4 * sizeof( F_10 -> args [ 0 ] ) ) ;
if ( V_33 < V_52 -> V_33 )
break;
}
F_10 -> args [ 3 ] = V_33 ;
F_10 -> args [ 2 ] = V_222 ;
return V_213 -> V_221 ;
}
void T_9 F_135 ( void )
{
V_43 = F_136 ( L_8 ,
sizeof( struct V_40 ) ,
0 , V_223 , NULL ) ;
V_45 = F_136 ( L_9 ,
V_224 ,
0 , V_223 , NULL ) ;
}
struct V_104 * F_124 ( T_1 V_225 , struct V_104 * V_226 )
{
struct V_104 * V_105 ;
struct V_67 * V_68 ;
T_4 V_227 = sizeof( * V_105 ) ;
if ( ! V_226 )
V_227 += sizeof( struct V_67 ) ;
V_105 = F_36 ( V_227 , V_49 ) ;
if ( ! V_105 )
return NULL ;
V_105 -> V_17 = V_225 ;
V_105 -> V_143 = 0 ;
V_105 -> V_109 = ( V_226 ? V_226 -> V_205 : V_105 -> V_205 ) ;
if ( V_226 )
return V_105 ;
V_68 = (struct V_67 * ) V_105 -> V_109 ;
V_68 -> V_27 [ 0 ] . V_37 = V_36 ;
V_68 -> V_27 [ 0 ] . V_53 = V_36 ;
#ifdef F_71
V_68 -> V_87 = F_137 ( struct V_86 ) ;
if ( ! V_68 -> V_87 ) {
F_122 ( V_105 ) ;
V_105 = NULL ;
}
#endif
return V_105 ;
}
static struct V_26 * F_138 ( struct V_228 * V_229 )
{
unsigned long V_88 = V_229 -> V_34 ;
struct V_26 * V_93 = V_229 -> V_25 ;
T_3 V_156 ;
F_46 ( L_10 ,
V_229 -> V_25 , V_229 -> V_34 , V_229 -> V_230 ) ;
while ( ! F_54 ( V_93 ) ) {
while ( V_88 < F_26 ( V_93 ) ) {
struct V_26 * V_28 = F_76 ( V_93 , V_88 ++ ) ;
if ( ! V_28 )
continue;
if ( F_101 ( V_28 ) ) {
V_229 -> V_25 = V_93 ;
V_229 -> V_34 = V_88 ;
} else {
V_229 -> V_25 = V_28 ;
V_229 -> V_34 = 0 ;
++ V_229 -> V_230 ;
}
return V_28 ;
}
V_156 = V_93 -> V_33 ;
V_93 = F_104 ( V_93 ) ;
V_88 = F_27 ( V_156 , V_93 ) + 1 ;
-- V_229 -> V_230 ;
}
V_229 -> V_25 = V_93 ;
V_229 -> V_34 = 0 ;
return NULL ;
}
static struct V_26 * F_139 ( struct V_228 * V_229 ,
struct V_67 * V_68 )
{
struct V_26 * V_28 , * V_93 ;
if ( ! V_68 )
return NULL ;
V_93 = V_68 -> V_27 ;
V_28 = F_103 ( V_93 -> V_25 [ 0 ] ) ;
if ( ! V_28 )
return NULL ;
if ( F_48 ( V_28 ) ) {
V_229 -> V_25 = V_28 ;
V_229 -> V_34 = 0 ;
V_229 -> V_230 = 1 ;
} else {
V_229 -> V_25 = V_93 ;
V_229 -> V_34 = 0 ;
V_229 -> V_230 = 0 ;
}
return V_28 ;
}
static void F_140 ( struct V_67 * V_68 , struct V_231 * V_232 )
{
struct V_26 * V_28 ;
struct V_228 V_229 ;
memset ( V_232 , 0 , sizeof( * V_232 ) ) ;
F_14 () ;
for ( V_28 = F_139 ( & V_229 , V_68 ) ; V_28 ; V_28 = F_138 ( & V_229 ) ) {
if ( F_101 ( V_28 ) ) {
struct V_40 * V_41 ;
V_232 -> V_233 ++ ;
V_232 -> V_234 += V_229 . V_230 ;
if ( V_229 . V_230 > V_232 -> V_235 )
V_232 -> V_235 = V_229 . V_230 ;
F_105 ( V_41 , & V_28 -> V_55 , V_56 )
++ V_232 -> V_236 ;
} else {
V_232 -> V_237 ++ ;
if ( V_28 -> V_32 < V_238 )
V_232 -> V_239 [ V_28 -> V_32 ] ++ ;
V_232 -> V_240 += F_22 ( V_28 ) -> V_50 ;
}
}
F_17 () ;
}
static void F_141 ( struct V_241 * V_242 , struct V_231 * V_243 )
{
unsigned int V_58 , V_244 , V_245 , V_246 , V_247 ;
if ( V_243 -> V_233 )
V_247 = V_243 -> V_234 * 100 / V_243 -> V_233 ;
else
V_247 = 0 ;
F_142 ( V_242 , L_11 ,
V_247 / 100 , V_247 % 100 ) ;
F_142 ( V_242 , L_12 , V_243 -> V_235 ) ;
F_142 ( V_242 , L_13 , V_243 -> V_233 ) ;
V_246 = V_224 * V_243 -> V_233 ;
F_142 ( V_242 , L_14 , V_243 -> V_236 ) ;
V_246 += sizeof( struct V_40 ) * V_243 -> V_236 ;
F_142 ( V_242 , L_15 , V_243 -> V_237 ) ;
V_246 += F_35 ( 0 ) * V_243 -> V_237 ;
V_244 = V_238 ;
while ( V_244 > 0 && V_243 -> V_239 [ V_244 - 1 ] == 0 )
V_244 -- ;
V_245 = 0 ;
for ( V_58 = 1 ; V_58 < V_244 ; V_58 ++ )
if ( V_243 -> V_239 [ V_58 ] != 0 ) {
F_142 ( V_242 , L_16 , V_58 , V_243 -> V_239 [ V_58 ] ) ;
V_245 += ( 1 << V_58 ) * V_243 -> V_239 [ V_58 ] ;
}
F_143 ( V_242 , '\n' ) ;
F_142 ( V_242 , L_17 , V_245 ) ;
V_246 += sizeof( struct V_26 * ) * V_245 ;
F_142 ( V_242 , L_18 , V_243 -> V_240 ) ;
F_142 ( V_242 , L_19 , ( V_246 + 1023 ) / 1024 ) ;
}
static void F_144 ( struct V_241 * V_242 ,
const struct V_86 T_5 * V_87 )
{
struct V_86 V_232 = { 0 } ;
int V_248 ;
F_145 (cpu) {
const struct V_86 * V_249 = F_146 ( V_87 , V_248 ) ;
V_232 . gets += V_249 -> gets ;
V_232 . V_157 += V_249 -> V_157 ;
V_232 . V_164 += V_249 -> V_164 ;
V_232 . V_186 += V_249 -> V_186 ;
V_232 . V_155 += V_249 -> V_155 ;
V_232 . V_91 += V_249 -> V_91 ;
}
F_142 ( V_242 , L_20 ) ;
F_142 ( V_242 , L_21 , V_232 . gets ) ;
F_142 ( V_242 , L_22 , V_232 . V_157 ) ;
F_142 ( V_242 , L_23 ,
V_232 . V_164 ) ;
F_142 ( V_242 , L_24 , V_232 . V_186 ) ;
F_142 ( V_242 , L_25 , V_232 . V_155 ) ;
F_142 ( V_242 , L_26 , V_232 . V_91 ) ;
}
static void F_147 ( struct V_241 * V_242 , struct V_104 * V_105 )
{
if ( V_105 -> V_17 == V_206 )
F_148 ( V_242 , L_27 ) ;
else if ( V_105 -> V_17 == V_250 )
F_148 ( V_242 , L_28 ) ;
else
F_142 ( V_242 , L_29 , V_105 -> V_17 ) ;
}
static int F_149 ( struct V_241 * V_242 , void * V_251 )
{
struct V_2 * V_2 = (struct V_2 * ) V_242 -> V_252 ;
unsigned int V_209 ;
F_142 ( V_242 ,
L_30
L_31 ,
V_224 , F_35 ( 0 ) ) ;
for ( V_209 = 0 ; V_209 < V_210 ; V_209 ++ ) {
struct V_94 * V_39 = & V_2 -> V_3 . V_211 [ V_209 ] ;
struct V_104 * V_105 ;
F_105 (tb, head, tb_hlist) {
struct V_67 * V_68 = (struct V_67 * ) V_105 -> V_109 ;
struct V_231 V_243 ;
if ( ! V_68 )
continue;
F_147 ( V_242 , V_105 ) ;
F_140 ( V_68 , & V_243 ) ;
F_141 ( V_242 , & V_243 ) ;
#ifdef F_71
F_144 ( V_242 , V_68 -> V_87 ) ;
#endif
}
}
return 0 ;
}
static int F_150 ( struct V_62 * V_62 , struct V_253 * V_253 )
{
return F_151 ( V_62 , V_253 , F_149 ) ;
}
static struct V_26 * F_152 ( struct V_241 * V_242 , T_10 V_37 )
{
struct V_228 * V_229 = V_242 -> V_252 ;
struct V_2 * V_2 = F_153 ( V_242 ) ;
T_10 V_254 = 0 ;
unsigned int V_209 ;
for ( V_209 = 0 ; V_209 < V_210 ; V_209 ++ ) {
struct V_94 * V_39 = & V_2 -> V_3 . V_211 [ V_209 ] ;
struct V_104 * V_105 ;
F_105 (tb, head, tb_hlist) {
struct V_26 * V_28 ;
for ( V_28 = F_139 ( V_229 ,
(struct V_67 * ) V_105 -> V_109 ) ;
V_28 ; V_28 = F_138 ( V_229 ) )
if ( V_37 == V_254 ++ ) {
V_229 -> V_105 = V_105 ;
return V_28 ;
}
}
}
return NULL ;
}
static void * F_154 ( struct V_241 * V_242 , T_10 * V_37 )
__acquires( T_11 )
{
F_14 () ;
return F_152 ( V_242 , * V_37 ) ;
}
static void * F_155 ( struct V_241 * V_242 , void * V_251 , T_10 * V_37 )
{
struct V_228 * V_229 = V_242 -> V_252 ;
struct V_2 * V_2 = F_153 ( V_242 ) ;
struct V_104 * V_105 = V_229 -> V_105 ;
struct V_188 * V_255 ;
unsigned int V_209 ;
struct V_26 * V_28 ;
++ * V_37 ;
V_28 = F_138 ( V_229 ) ;
if ( V_28 )
return V_28 ;
V_209 = V_105 -> V_17 & ( V_210 - 1 ) ;
while ( ( V_255 = F_103 ( F_156 ( & V_105 -> V_256 ) ) ) ) {
V_105 = F_112 ( V_255 , struct V_104 , V_256 ) ;
V_28 = F_139 ( V_229 , (struct V_67 * ) V_105 -> V_109 ) ;
if ( V_28 )
goto V_152;
}
while ( ++ V_209 < V_210 ) {
struct V_94 * V_39 = & V_2 -> V_3 . V_211 [ V_209 ] ;
F_105 (tb, head, tb_hlist) {
V_28 = F_139 ( V_229 , (struct V_67 * ) V_105 -> V_109 ) ;
if ( V_28 )
goto V_152;
}
}
return NULL ;
V_152:
V_229 -> V_105 = V_105 ;
return V_28 ;
}
static void F_157 ( struct V_241 * V_242 , void * V_251 )
__releases( T_11 )
{
F_17 () ;
}
static void F_158 ( struct V_241 * V_242 , int V_28 )
{
while ( V_28 -- > 0 )
F_148 ( V_242 , L_32 ) ;
}
static inline const char * F_159 ( char * V_257 , T_4 V_221 , enum V_258 V_232 )
{
switch ( V_232 ) {
case V_259 : return L_33 ;
case V_260 : return L_34 ;
case V_261 : return L_35 ;
case V_262 : return L_36 ;
case V_193 : return L_37 ;
default:
snprintf ( V_257 , V_221 , L_38 , V_232 ) ;
return V_257 ;
}
}
static inline const char * F_160 ( char * V_257 , T_4 V_221 , unsigned int V_68 )
{
if ( V_68 < V_263 && V_264 [ V_68 ] )
return V_264 [ V_68 ] ;
snprintf ( V_257 , V_221 , L_39 , V_68 ) ;
return V_257 ;
}
static int F_161 ( struct V_241 * V_242 , void * V_251 )
{
const struct V_228 * V_229 = V_242 -> V_252 ;
struct V_26 * V_28 = V_251 ;
if ( F_54 ( F_104 ( V_28 ) ) )
F_147 ( V_242 , V_229 -> V_105 ) ;
if ( F_48 ( V_28 ) ) {
T_8 V_265 = F_94 ( V_28 -> V_33 ) ;
F_158 ( V_242 , V_229 -> V_230 - 1 ) ;
F_142 ( V_242 , L_40 ,
& V_265 , V_36 - V_28 -> V_37 - V_28 -> V_32 , V_28 -> V_32 ,
F_22 ( V_28 ) -> V_51 ,
F_22 ( V_28 ) -> V_50 ) ;
} else {
T_8 V_266 = F_94 ( V_28 -> V_33 ) ;
struct V_40 * V_41 ;
F_158 ( V_242 , V_229 -> V_230 ) ;
F_142 ( V_242 , L_41 , & V_266 ) ;
F_105 (fa, &n->leaf, fa_list) {
char V_267 [ 32 ] , V_268 [ 32 ] ;
F_158 ( V_242 , V_229 -> V_230 + 1 ) ;
F_142 ( V_242 , L_42 ,
V_36 - V_41 -> V_54 ,
F_159 ( V_267 , sizeof( V_267 ) ,
V_41 -> V_98 -> V_161 ) ,
F_160 ( V_268 , sizeof( V_268 ) ,
V_41 -> V_124 ) ) ;
if ( V_41 -> V_97 )
F_142 ( V_242 , L_43 , V_41 -> V_97 ) ;
F_143 ( V_242 , '\n' ) ;
}
}
return 0 ;
}
static int F_162 ( struct V_62 * V_62 , struct V_253 * V_253 )
{
return F_163 ( V_62 , V_253 , & V_269 ,
sizeof( struct V_228 ) ) ;
}
static struct V_26 * F_164 ( struct V_270 * V_229 ,
T_10 V_37 )
{
struct V_26 * V_52 , * * V_29 = & V_229 -> V_25 ;
T_3 V_33 ;
if ( V_229 -> V_37 > 0 && V_37 >= V_229 -> V_37 ) {
V_33 = V_229 -> V_33 ;
} else {
V_229 -> V_37 = 1 ;
V_33 = 0 ;
}
V_37 -= V_229 -> V_37 ;
while ( ( V_52 = F_118 ( V_29 , V_33 ) ) && ( V_37 -- > 0 ) ) {
V_33 = V_52 -> V_33 + 1 ;
V_229 -> V_37 ++ ;
V_52 = NULL ;
if ( ! V_33 )
break;
}
if ( V_52 )
V_229 -> V_33 = V_52 -> V_33 ;
else
V_229 -> V_37 = 0 ;
return V_52 ;
}
static void * F_165 ( struct V_241 * V_242 , T_10 * V_37 )
__acquires( T_11 )
{
struct V_270 * V_229 = V_242 -> V_252 ;
struct V_104 * V_105 ;
struct V_67 * V_68 ;
F_14 () ;
V_105 = F_166 ( F_153 ( V_242 ) , V_250 ) ;
if ( ! V_105 )
return NULL ;
V_229 -> V_271 = V_105 ;
V_68 = (struct V_67 * ) V_105 -> V_109 ;
V_229 -> V_25 = V_68 -> V_27 ;
if ( * V_37 != 0 )
return F_164 ( V_229 , * V_37 ) ;
V_229 -> V_37 = 0 ;
V_229 -> V_33 = V_85 ;
return V_272 ;
}
static void * F_167 ( struct V_241 * V_242 , void * V_251 , T_10 * V_37 )
{
struct V_270 * V_229 = V_242 -> V_252 ;
struct V_26 * V_52 = NULL ;
T_3 V_33 = V_229 -> V_33 + 1 ;
++ * V_37 ;
if ( ( V_251 == V_272 ) || V_33 )
V_52 = F_118 ( & V_229 -> V_25 , V_33 ) ;
if ( V_52 ) {
V_229 -> V_33 = V_52 -> V_33 ;
V_229 -> V_37 ++ ;
} else {
V_229 -> V_37 = 0 ;
}
return V_52 ;
}
static void F_168 ( struct V_241 * V_242 , void * V_251 )
__releases( T_11 )
{
F_17 () ;
}
static unsigned int F_169 ( int type , T_8 V_273 , const struct V_14 * V_15 )
{
unsigned int V_274 = 0 ;
if ( type == V_275 || type == V_276 )
V_274 = V_277 ;
if ( V_15 && V_15 -> V_167 -> V_278 )
V_274 |= V_279 ;
if ( V_273 == F_94 ( 0xFFFFFFFF ) )
V_274 |= V_280 ;
V_274 |= V_281 ;
return V_274 ;
}
static int F_170 ( struct V_241 * V_242 , void * V_251 )
{
struct V_270 * V_229 = V_242 -> V_252 ;
struct V_104 * V_105 = V_229 -> V_271 ;
struct V_40 * V_41 ;
struct V_26 * V_52 = V_251 ;
T_8 V_144 ;
if ( V_251 == V_272 ) {
F_142 ( V_242 , L_44 , L_45
L_46
L_47 ) ;
return 0 ;
}
V_144 = F_94 ( V_52 -> V_33 ) ;
F_105 (fa, &l->leaf, fa_list) {
const struct V_14 * V_15 = V_41 -> V_98 ;
T_8 V_273 = F_171 ( V_36 - V_41 -> V_54 ) ;
unsigned int V_274 = F_169 ( V_41 -> V_124 , V_273 , V_15 ) ;
if ( ( V_41 -> V_124 == V_282 ) ||
( V_41 -> V_124 == V_283 ) )
continue;
if ( V_41 -> V_17 != V_105 -> V_17 )
continue;
F_172 ( V_242 , 127 ) ;
if ( V_15 )
F_142 ( V_242 ,
L_48
L_49 ,
V_15 -> V_284 ? V_15 -> V_284 -> V_285 : L_50 ,
V_144 ,
V_15 -> V_167 -> V_278 , V_274 , 0 , 0 ,
V_15 -> V_99 ,
V_273 ,
( V_15 -> V_286 ?
V_15 -> V_286 + 40 : 0 ) ,
V_15 -> V_287 ,
V_15 -> V_288 >> 3 ) ;
else
F_142 ( V_242 ,
L_51
L_49 ,
V_144 , 0 , V_274 , 0 , 0 , 0 ,
V_273 , 0 , 0 , 0 ) ;
F_173 ( V_242 , '\n' ) ;
}
return 0 ;
}
static int F_174 ( struct V_62 * V_62 , struct V_253 * V_253 )
{
return F_163 ( V_62 , V_253 , & V_289 ,
sizeof( struct V_270 ) ) ;
}
int T_12 F_175 ( struct V_2 * V_2 )
{
if ( ! F_176 ( L_52 , V_290 , V_2 -> V_291 , & V_292 ) )
goto V_293;
if ( ! F_176 ( L_53 , V_290 , V_2 -> V_291 ,
& V_294 ) )
goto V_295;
if ( ! F_176 ( L_54 , V_290 , V_2 -> V_291 , & V_296 ) )
goto V_297;
return 0 ;
V_297:
F_177 ( L_53 , V_2 -> V_291 ) ;
V_295:
F_177 ( L_52 , V_2 -> V_291 ) ;
V_293:
return - V_102 ;
}
void T_13 F_178 ( struct V_2 * V_2 )
{
F_177 ( L_52 , V_2 -> V_291 ) ;
F_177 ( L_53 , V_2 -> V_291 ) ;
F_177 ( L_54 , V_2 -> V_291 ) ;
}
