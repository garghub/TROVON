static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
enum V_4 V_5 , T_1 V_6 ,
int V_7 , struct V_8 * V_9 ,
T_2 V_10 , T_2 type , T_1 V_11 )
{
struct V_12 V_13 = {
. V_6 = V_6 ,
. V_7 = V_7 ,
. V_9 = V_9 ,
. V_10 = V_10 ,
. type = type ,
. V_11 = V_11 ,
} ;
return F_2 ( V_2 , V_3 , V_5 , & V_13 . V_13 ) ;
}
static int F_3 ( struct V_3 * V_3 ,
enum V_4 V_5 , T_1 V_6 ,
int V_7 , struct V_8 * V_9 ,
T_2 V_10 , T_2 type , T_1 V_11 )
{
struct V_12 V_13 = {
. V_6 = V_6 ,
. V_7 = V_7 ,
. V_9 = V_9 ,
. V_10 = V_10 ,
. type = type ,
. V_11 = V_11 ,
} ;
return F_4 ( V_3 , V_5 , & V_13 . V_13 ) ;
}
static inline struct V_14 * F_5 ( struct V_15 * V_16 )
{
return F_6 ( V_16 , struct V_14 , V_16 [ 0 ] ) ;
}
static inline void F_7 ( struct V_15 * V_17 , struct V_15 * V_18 )
{
if ( V_17 )
F_8 ( F_5 ( V_17 ) -> V_19 , V_18 ) ;
}
static inline unsigned long F_9 ( const struct V_15 * V_20 )
{
return ( 1ul << V_20 -> V_21 ) & ~ ( 1ul ) ;
}
static inline unsigned long F_10 ( T_3 V_22 , struct V_15 * V_16 )
{
unsigned long V_23 = V_22 ^ V_16 -> V_22 ;
if ( ( V_24 <= V_25 ) && ( V_25 == V_16 -> V_26 ) )
return 0 ;
return V_23 >> V_16 -> V_26 ;
}
static void F_11 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_6 ( V_28 , struct V_29 , V_31 ) ;
F_12 ( V_32 , V_30 ) ;
}
static inline void F_13 ( struct V_29 * V_30 )
{
F_14 ( & V_30 -> V_31 , F_11 ) ;
}
static void F_15 ( struct V_27 * V_28 )
{
struct V_14 * V_17 = F_6 ( V_28 , struct V_14 , V_31 ) ;
if ( ! V_17 -> V_33 )
F_12 ( V_34 , V_17 ) ;
else
F_16 ( V_17 ) ;
}
static struct V_14 * F_17 ( int V_21 )
{
T_4 V_35 ;
if ( V_21 > V_36 )
return NULL ;
V_35 = F_18 ( 1ul << V_21 ) ;
if ( V_35 <= V_37 )
return F_19 ( V_35 , V_38 ) ;
else
return F_20 ( V_35 ) ;
}
static inline void F_21 ( struct V_15 * V_17 )
{
++ F_5 ( V_17 ) -> V_39 ? : ++ F_5 ( V_17 ) -> V_40 ;
}
static inline void F_22 ( struct V_15 * V_17 )
{
F_5 ( V_17 ) -> V_39 -- ? : F_5 ( V_17 ) -> V_40 -- ;
}
static struct V_15 * F_23 ( T_3 V_22 , struct V_29 * V_30 )
{
struct V_15 * V_41 ;
struct V_14 * V_16 ;
V_16 = F_24 ( V_34 , V_38 ) ;
if ( ! V_16 )
return NULL ;
V_41 = V_16 -> V_16 ;
V_41 -> V_22 = V_22 ;
V_41 -> V_26 = 0 ;
V_41 -> V_21 = 0 ;
V_41 -> V_42 = V_30 -> V_43 ;
F_25 ( & V_41 -> V_44 ) ;
F_26 ( & V_30 -> V_45 , & V_41 -> V_44 ) ;
return V_41 ;
}
static struct V_15 * F_27 ( T_3 V_22 , int V_26 , int V_21 )
{
unsigned int V_46 = V_26 + V_21 ;
struct V_15 * V_20 ;
struct V_14 * V_14 ;
F_28 ( ! V_21 || ( V_46 > V_25 ) ) ;
V_14 = F_17 ( V_21 ) ;
if ( ! V_14 )
return NULL ;
F_29 ( L_1 , V_14 , F_18 ( 0 ) ,
sizeof( struct V_15 * ) << V_21 ) ;
if ( V_21 == V_25 )
V_14 -> V_40 = 1 ;
else
V_14 -> V_39 = 1ul << V_21 ;
V_20 = V_14 -> V_16 ;
V_20 -> V_22 = ( V_46 < V_25 ) ? ( V_22 >> V_46 ) << V_46 : 0 ;
V_20 -> V_26 = V_26 ;
V_20 -> V_21 = V_21 ;
V_20 -> V_42 = V_26 ;
return V_20 ;
}
static inline int F_30 ( struct V_15 * V_20 , struct V_15 * V_17 )
{
return V_17 && ( ( V_17 -> V_26 + V_17 -> V_21 ) == V_20 -> V_26 ) && F_31 ( V_17 ) ;
}
static void F_32 ( struct V_15 * V_20 , unsigned long V_47 ,
struct V_15 * V_17 )
{
struct V_15 * V_48 = F_33 ( V_20 , V_47 ) ;
int V_49 , V_50 ;
F_28 ( V_47 >= F_9 ( V_20 ) ) ;
if ( ! V_17 && V_48 )
F_21 ( V_20 ) ;
if ( V_17 && ! V_48 )
F_22 ( V_20 ) ;
V_50 = F_30 ( V_20 , V_48 ) ;
V_49 = F_30 ( V_20 , V_17 ) ;
if ( V_50 && ! V_49 )
F_5 ( V_20 ) -> V_40 -- ;
else if ( ! V_50 && V_49 )
F_5 ( V_20 ) -> V_40 ++ ;
if ( V_17 && ( V_20 -> V_42 < V_17 -> V_42 ) )
V_20 -> V_42 = V_17 -> V_42 ;
F_8 ( V_20 -> V_14 [ V_47 ] , V_17 ) ;
}
static void F_34 ( struct V_15 * V_20 )
{
unsigned long V_47 ;
for ( V_47 = F_9 ( V_20 ) ; V_47 ; ) {
struct V_15 * V_51 = F_33 ( V_20 , -- V_47 ) ;
if ( ! V_51 )
continue;
if ( F_35 ( V_51 ) == V_20 )
F_34 ( V_51 ) ;
else
F_7 ( V_51 , V_20 ) ;
}
}
static inline void F_36 ( struct V_15 * V_18 , T_3 V_22 ,
struct V_15 * V_17 )
{
if ( F_37 ( V_18 ) )
F_8 ( V_18 -> V_14 [ 0 ] , V_17 ) ;
else
F_32 ( V_18 , F_10 ( V_22 , V_18 ) , V_17 ) ;
}
static inline void F_38 ( struct V_15 * V_20 )
{
F_5 ( V_20 ) -> V_31 . V_52 = NULL ;
}
static inline void F_39 ( struct V_15 * V_20 ,
struct V_15 * V_17 )
{
F_5 ( V_17 ) -> V_31 . V_52 = F_5 ( V_20 ) -> V_31 . V_52 ;
F_5 ( V_20 ) -> V_31 . V_52 = & F_5 ( V_17 ) -> V_31 ;
}
static void F_40 ( struct V_15 * V_20 )
{
struct V_53 * V_28 = & F_5 ( V_20 ) -> V_31 ;
while ( V_28 ) {
V_28 = V_28 -> V_52 ;
V_54 += F_18 ( 1ul << V_20 -> V_21 ) ;
F_41 ( V_20 ) ;
V_20 = F_6 ( V_28 , struct V_14 , V_31 ) -> V_16 ;
}
if ( V_54 >= V_37 * V_55 ) {
V_54 = 0 ;
F_42 () ;
}
}
static struct V_15 * F_43 ( struct V_56 * V_57 ,
struct V_15 * V_58 ,
struct V_15 * V_20 )
{
struct V_15 * V_18 = F_35 ( V_58 ) ;
unsigned long V_47 ;
F_44 ( V_20 , V_18 ) ;
F_36 ( V_18 , V_20 -> V_22 , V_20 ) ;
F_34 ( V_20 ) ;
F_40 ( V_58 ) ;
for ( V_47 = F_9 ( V_20 ) ; V_47 ; ) {
struct V_15 * V_51 = F_33 ( V_20 , -- V_47 ) ;
if ( F_30 ( V_20 , V_51 ) )
V_20 = F_45 ( V_57 , V_51 ) ;
}
return V_18 ;
}
static struct V_15 * F_46 ( struct V_56 * V_57 ,
struct V_15 * V_58 )
{
struct V_15 * V_20 ;
unsigned long V_47 ;
T_3 V_59 ;
F_29 ( L_2 ) ;
V_20 = F_27 ( V_58 -> V_22 , V_58 -> V_26 - 1 , V_58 -> V_21 + 1 ) ;
if ( ! V_20 )
goto V_60;
F_38 ( V_58 ) ;
for ( V_47 = F_9 ( V_58 ) , V_59 = 1u << V_20 -> V_26 ; V_47 ; ) {
struct V_15 * V_51 = F_33 ( V_58 , -- V_47 ) ;
struct V_15 * V_61 , * V_62 ;
unsigned long V_63 , V_64 ;
if ( ! V_51 )
continue;
if ( ! F_30 ( V_58 , V_51 ) ) {
F_32 ( V_20 , F_10 ( V_51 -> V_22 , V_20 ) , V_51 ) ;
continue;
}
F_39 ( V_58 , V_51 ) ;
if ( V_51 -> V_21 == 1 ) {
F_32 ( V_20 , 2 * V_47 + 1 , F_33 ( V_51 , 1 ) ) ;
F_32 ( V_20 , 2 * V_47 , F_33 ( V_51 , 0 ) ) ;
continue;
}
V_62 = F_27 ( V_51 -> V_22 | V_59 , V_51 -> V_26 , V_51 -> V_21 - 1 ) ;
if ( ! V_62 )
goto V_65;
V_61 = F_27 ( V_51 -> V_22 , V_51 -> V_26 , V_51 -> V_21 - 1 ) ;
F_39 ( V_20 , V_62 ) ;
if ( ! V_61 )
goto V_65;
F_39 ( V_20 , V_61 ) ;
for ( V_64 = F_9 ( V_51 ) , V_63 = V_64 / 2 ; V_63 ; ) {
F_32 ( V_62 , -- V_63 , F_33 ( V_51 , -- V_64 ) ) ;
F_32 ( V_61 , V_63 , F_33 ( V_51 , V_63 ) ) ;
F_32 ( V_62 , -- V_63 , F_33 ( V_51 , -- V_64 ) ) ;
F_32 ( V_61 , V_63 , F_33 ( V_51 , V_63 ) ) ;
}
F_44 ( V_62 , V_20 ) ;
F_44 ( V_61 , V_20 ) ;
F_32 ( V_20 , 2 * V_47 + 1 , V_62 ) ;
F_32 ( V_20 , 2 * V_47 , V_61 ) ;
}
return F_43 ( V_57 , V_58 , V_20 ) ;
V_65:
F_40 ( V_20 ) ;
V_60:
return NULL ;
}
static struct V_15 * F_47 ( struct V_56 * V_57 ,
struct V_15 * V_58 )
{
struct V_15 * V_20 ;
unsigned long V_47 ;
F_29 ( L_3 ) ;
V_20 = F_27 ( V_58 -> V_22 , V_58 -> V_26 + 1 , V_58 -> V_21 - 1 ) ;
if ( ! V_20 )
goto V_60;
F_38 ( V_58 ) ;
for ( V_47 = F_9 ( V_58 ) ; V_47 ; ) {
struct V_15 * V_62 = F_33 ( V_58 , -- V_47 ) ;
struct V_15 * V_61 = F_33 ( V_58 , -- V_47 ) ;
struct V_15 * V_51 ;
if ( ! V_62 || ! V_61 ) {
F_32 ( V_20 , V_47 / 2 , V_62 ? : V_61 ) ;
continue;
}
V_51 = F_27 ( V_61 -> V_22 , V_58 -> V_26 , 1 ) ;
if ( ! V_51 )
goto V_65;
F_39 ( V_20 , V_51 ) ;
F_32 ( V_51 , 1 , V_62 ) ;
F_32 ( V_51 , 0 , V_61 ) ;
F_44 ( V_51 , V_20 ) ;
F_32 ( V_20 , V_47 / 2 , V_51 ) ;
}
return F_43 ( V_57 , V_58 , V_20 ) ;
V_65:
F_40 ( V_20 ) ;
V_60:
return NULL ;
}
static struct V_15 * F_48 ( struct V_56 * V_57 ,
struct V_15 * V_58 )
{
struct V_15 * V_17 , * V_18 ;
unsigned long V_47 ;
for ( V_17 = NULL , V_47 = F_9 ( V_58 ) ; ! V_17 && V_47 ; )
V_17 = F_33 ( V_58 , -- V_47 ) ;
V_18 = F_35 ( V_58 ) ;
F_36 ( V_18 , V_58 -> V_22 , V_17 ) ;
F_7 ( V_17 , V_18 ) ;
F_41 ( V_58 ) ;
return V_18 ;
}
static unsigned char F_49 ( struct V_15 * V_20 )
{
unsigned char V_42 = V_20 -> V_26 ;
unsigned long V_66 , V_47 ;
unsigned char V_67 ;
V_67 = F_50 (unsigned char, tn->pos + tn->bits - 1 , tn->slen) ;
for ( V_47 = 0 , V_66 = 0x2ul ; V_47 < F_9 ( V_20 ) ; V_47 += V_66 ) {
struct V_15 * V_17 = F_33 ( V_20 , V_47 ) ;
if ( ! V_17 || ( V_17 -> V_42 <= V_42 ) )
continue;
V_66 <<= ( V_17 -> V_42 - V_42 ) ;
V_42 = V_17 -> V_42 ;
V_47 &= ~ ( V_66 - 1 ) ;
if ( V_42 >= V_67 )
break;
}
V_20 -> V_42 = V_42 ;
return V_42 ;
}
static inline bool F_51 ( struct V_15 * V_18 , struct V_15 * V_20 )
{
unsigned long V_68 = F_9 ( V_20 ) ;
unsigned long V_69 = V_68 ;
V_69 *= F_37 ( V_18 ) ? V_70 : V_71 ;
V_68 -= F_5 ( V_20 ) -> V_39 ;
V_68 += F_5 ( V_20 ) -> V_40 ;
return ( V_68 > 1 ) && V_20 -> V_26 && ( ( 50 * V_68 ) >= V_69 ) ;
}
static inline bool F_52 ( struct V_15 * V_18 , struct V_15 * V_20 )
{
unsigned long V_68 = F_9 ( V_20 ) ;
unsigned long V_69 = V_68 ;
V_69 *= F_37 ( V_18 ) ? V_72 : V_73 ;
V_68 -= F_5 ( V_20 ) -> V_39 ;
return ( V_68 > 1 ) && ( V_20 -> V_21 > 1 ) && ( ( 100 * V_68 ) < V_69 ) ;
}
static inline bool F_53 ( struct V_15 * V_20 )
{
unsigned long V_68 = F_9 ( V_20 ) ;
V_68 -= F_5 ( V_20 ) -> V_39 ;
if ( ( V_20 -> V_21 == V_25 ) && F_5 ( V_20 ) -> V_40 )
V_68 -= V_74 ;
return V_68 < 2 ;
}
static struct V_15 * F_45 ( struct V_56 * V_57 , struct V_15 * V_20 )
{
#ifdef F_54
struct V_75 T_5 * V_76 = V_57 -> V_76 ;
#endif
struct V_15 * V_18 = F_35 ( V_20 ) ;
unsigned long V_77 = F_10 ( V_20 -> V_22 , V_18 ) ;
int V_78 = V_79 ;
F_29 ( L_4 ,
V_20 , V_71 , V_73 ) ;
F_28 ( V_20 != F_33 ( V_18 , V_77 ) ) ;
while ( F_51 ( V_18 , V_20 ) && V_78 ) {
V_18 = F_46 ( V_57 , V_20 ) ;
if ( ! V_18 ) {
#ifdef F_54
F_55 ( V_76 -> V_80 ) ;
#endif
break;
}
V_78 -- ;
V_20 = F_33 ( V_18 , V_77 ) ;
}
V_18 = F_35 ( V_20 ) ;
if ( V_78 != V_79 )
return V_18 ;
while ( F_52 ( V_18 , V_20 ) && V_78 ) {
V_18 = F_47 ( V_57 , V_20 ) ;
if ( ! V_18 ) {
#ifdef F_54
F_55 ( V_76 -> V_80 ) ;
#endif
break;
}
V_78 -- ;
V_20 = F_33 ( V_18 , V_77 ) ;
}
if ( F_53 ( V_20 ) )
return F_48 ( V_57 , V_20 ) ;
return F_35 ( V_20 ) ;
}
static void F_56 ( struct V_15 * V_20 , unsigned char V_42 )
{
unsigned char V_81 = V_20 -> V_42 ;
while ( ( V_81 > V_20 -> V_26 ) && ( V_81 > V_42 ) ) {
V_42 = F_49 ( V_20 ) ;
if ( V_81 == V_42 )
break;
V_20 = F_35 ( V_20 ) ;
V_81 = V_20 -> V_42 ;
}
}
static void F_57 ( struct V_15 * V_20 , unsigned char V_42 )
{
while ( V_20 -> V_42 < V_42 ) {
V_20 -> V_42 = V_42 ;
V_20 = F_35 ( V_20 ) ;
}
}
static struct V_15 * F_58 ( struct V_56 * V_57 ,
struct V_15 * * V_18 , T_1 V_22 )
{
struct V_15 * V_82 , * V_17 = V_57 -> V_16 ;
unsigned long V_23 = 0 ;
do {
V_82 = V_17 ;
V_17 = F_59 ( V_17 , V_23 ) ;
if ( ! V_17 )
break;
V_23 = F_60 ( V_22 , V_17 ) ;
if ( V_23 >= ( 1ul << V_17 -> V_21 ) ) {
V_17 = NULL ;
break;
}
} while ( F_31 ( V_17 ) );
* V_18 = V_82 ;
return V_17 ;
}
static struct V_29 * F_61 ( struct V_83 * V_84 , T_2 V_42 ,
T_2 V_10 , T_1 V_85 , T_1 V_11 )
{
struct V_29 * V_30 ;
if ( ! V_84 )
return NULL ;
F_62 (fa, fah, fa_list) {
if ( V_30 -> V_43 < V_42 )
continue;
if ( V_30 -> V_43 != V_42 )
break;
if ( V_30 -> V_11 > V_11 )
continue;
if ( V_30 -> V_11 != V_11 )
break;
if ( V_30 -> V_86 > V_10 )
continue;
if ( V_30 -> V_87 -> V_88 >= V_85 || V_30 -> V_86 < V_10 )
return V_30 ;
}
return NULL ;
}
static void F_63 ( struct V_56 * V_57 , struct V_15 * V_20 )
{
while ( ! F_37 ( V_20 ) )
V_20 = F_45 ( V_57 , V_20 ) ;
}
static int F_64 ( struct V_56 * V_57 , struct V_15 * V_18 ,
struct V_29 * V_89 , T_3 V_22 )
{
struct V_15 * V_17 , * V_41 ;
V_41 = F_23 ( V_22 , V_89 ) ;
if ( ! V_41 )
goto V_90;
V_17 = F_33 ( V_18 , F_10 ( V_22 , V_18 ) ) ;
if ( V_17 ) {
struct V_15 * V_20 ;
V_20 = F_27 ( V_22 , F_65 ( V_22 ^ V_17 -> V_22 ) , 1 ) ;
if ( ! V_20 )
goto V_60;
F_44 ( V_20 , V_18 ) ;
F_32 ( V_20 , F_10 ( V_22 , V_20 ) ^ 1 , V_17 ) ;
F_36 ( V_18 , V_22 , V_20 ) ;
F_7 ( V_17 , V_20 ) ;
V_18 = V_20 ;
}
F_57 ( V_18 , V_89 -> V_43 ) ;
F_44 ( V_41 , V_18 ) ;
F_36 ( V_18 , V_22 , V_41 ) ;
F_63 ( V_57 , V_18 ) ;
return 0 ;
V_60:
F_41 ( V_41 ) ;
V_90:
return - V_91 ;
}
static int F_66 ( struct V_56 * V_57 , struct V_15 * V_18 ,
struct V_15 * V_41 , struct V_29 * V_89 ,
struct V_29 * V_30 , T_3 V_22 )
{
if ( ! V_41 )
return F_64 ( V_57 , V_18 , V_89 , V_22 ) ;
if ( V_30 ) {
F_67 ( & V_89 -> V_45 , & V_30 -> V_45 ) ;
} else {
struct V_29 * V_92 ;
F_62 (last, &l->leaf, fa_list) {
if ( V_89 -> V_43 < V_92 -> V_43 )
break;
if ( ( V_89 -> V_43 == V_92 -> V_43 ) &&
( V_89 -> V_11 > V_92 -> V_11 ) )
break;
V_30 = V_92 ;
}
if ( V_30 )
F_68 ( & V_89 -> V_45 , & V_30 -> V_45 ) ;
else
F_69 ( & V_89 -> V_45 , & V_41 -> V_44 ) ;
}
if ( V_41 -> V_42 < V_89 -> V_43 ) {
V_41 -> V_42 = V_89 -> V_43 ;
F_57 ( V_18 , V_89 -> V_43 ) ;
}
return 0 ;
}
static bool F_70 ( T_1 V_22 , T_2 V_93 , struct V_94 * V_95 )
{
if ( V_93 > V_25 ) {
F_71 ( V_95 , L_5 ) ;
return false ;
}
if ( ( V_93 < V_25 ) && ( V_22 << V_93 ) ) {
F_71 ( V_95 ,
L_6 ) ;
return false ;
}
return true ;
}
int F_72 ( struct V_3 * V_3 , struct V_96 * V_97 ,
struct V_98 * V_99 , struct V_94 * V_95 )
{
enum V_4 V_100 = V_101 ;
struct V_56 * V_57 = (struct V_56 * ) V_97 -> V_102 ;
struct V_29 * V_30 , * V_103 ;
struct V_15 * V_41 , * V_18 ;
T_6 V_104 = V_105 ;
struct V_8 * V_9 ;
T_2 V_93 = V_99 -> V_106 ;
T_2 V_42 = V_25 - V_93 ;
T_2 V_10 = V_99 -> V_107 ;
T_1 V_22 ;
int V_108 ;
V_22 = F_73 ( V_99 -> V_109 ) ;
if ( ! F_70 ( V_22 , V_93 , V_95 ) )
return - V_110 ;
F_29 ( L_7 , V_97 -> V_11 , V_22 , V_93 ) ;
V_9 = F_74 ( V_99 , V_95 ) ;
if ( F_75 ( V_9 ) ) {
V_108 = F_76 ( V_9 ) ;
goto V_108;
}
V_41 = F_58 ( V_57 , & V_18 , V_22 ) ;
V_30 = V_41 ? F_61 ( & V_41 -> V_44 , V_42 , V_10 , V_9 -> V_88 ,
V_97 -> V_11 ) : NULL ;
if ( V_30 && V_30 -> V_86 == V_10 &&
V_30 -> V_87 -> V_88 == V_9 -> V_88 ) {
struct V_29 * V_111 , * V_112 ;
V_108 = - V_113 ;
if ( V_99 -> V_114 & V_105 )
goto V_115;
V_104 &= ~ V_105 ;
V_112 = NULL ;
V_111 = V_30 ;
F_77 (fa, fa_list) {
if ( ( V_30 -> V_43 != V_42 ) ||
( V_30 -> V_11 != V_97 -> V_11 ) ||
( V_30 -> V_86 != V_10 ) )
break;
if ( V_30 -> V_87 -> V_88 != V_9 -> V_88 )
break;
if ( V_30 -> V_116 == V_99 -> V_117 &&
V_30 -> V_87 == V_9 ) {
V_112 = V_30 ;
break;
}
}
if ( V_99 -> V_114 & V_118 ) {
struct V_8 * V_119 ;
T_2 V_120 ;
V_104 |= V_118 ;
V_30 = V_111 ;
if ( V_112 ) {
if ( V_30 == V_112 )
V_108 = 0 ;
goto V_115;
}
V_108 = - V_121 ;
V_103 = F_24 ( V_32 , V_38 ) ;
if ( ! V_103 )
goto V_115;
V_119 = V_30 -> V_87 ;
V_103 -> V_86 = V_30 -> V_86 ;
V_103 -> V_87 = V_9 ;
V_103 -> V_116 = V_99 -> V_117 ;
V_120 = V_30 -> V_122 ;
V_103 -> V_122 = V_120 & ~ V_123 ;
V_103 -> V_43 = V_30 -> V_43 ;
V_103 -> V_11 = V_97 -> V_11 ;
V_103 -> V_124 = - 1 ;
F_3 ( V_3 , V_125 ,
V_22 , V_93 , V_9 ,
V_103 -> V_86 , V_99 -> V_117 ,
V_97 -> V_11 ) ;
F_78 ( V_126 , F_79 ( V_22 ) , V_103 , V_93 ,
V_97 -> V_11 , & V_99 -> V_127 , V_104 ) ;
F_80 ( & V_30 -> V_45 , & V_103 -> V_45 ) ;
F_13 ( V_30 ) ;
F_81 ( V_119 ) ;
if ( V_120 & V_123 )
F_82 ( V_99 -> V_127 . V_128 ) ;
goto V_129;
}
if ( V_112 )
goto V_115;
if ( V_99 -> V_114 & V_130 ) {
V_100 = V_131 ;
V_104 |= V_130 ;
} else {
V_30 = V_111 ;
}
}
V_108 = - V_132 ;
if ( ! ( V_99 -> V_114 & V_133 ) )
goto V_115;
V_104 |= V_133 ;
V_108 = - V_121 ;
V_103 = F_24 ( V_32 , V_38 ) ;
if ( ! V_103 )
goto V_115;
V_103 -> V_87 = V_9 ;
V_103 -> V_86 = V_10 ;
V_103 -> V_116 = V_99 -> V_117 ;
V_103 -> V_122 = 0 ;
V_103 -> V_43 = V_42 ;
V_103 -> V_11 = V_97 -> V_11 ;
V_103 -> V_124 = - 1 ;
V_108 = F_66 ( V_57 , V_18 , V_41 , V_103 , V_30 , V_22 ) ;
if ( V_108 )
goto V_134;
if ( ! V_93 )
V_97 -> V_135 ++ ;
F_82 ( V_99 -> V_127 . V_128 ) ;
F_3 ( V_3 , V_100 , V_22 , V_93 , V_9 , V_10 , V_99 -> V_117 ,
V_97 -> V_11 ) ;
F_78 ( V_126 , F_79 ( V_22 ) , V_103 , V_93 , V_103 -> V_11 ,
& V_99 -> V_127 , V_104 ) ;
V_129:
return 0 ;
V_134:
F_12 ( V_32 , V_103 ) ;
V_115:
F_81 ( V_9 ) ;
V_108:
return V_108 ;
}
static inline T_3 F_83 ( T_3 V_22 , struct V_15 * V_17 )
{
T_3 V_136 = V_17 -> V_22 ;
return ( V_22 ^ V_136 ) & ( V_136 | - V_136 ) ;
}
int F_84 ( struct V_96 * V_97 , const struct V_137 * V_138 ,
struct V_139 * V_140 , int V_141 )
{
struct V_56 * V_57 = (struct V_56 * ) V_97 -> V_102 ;
#ifdef F_54
struct V_75 T_5 * V_76 = V_57 -> V_76 ;
#endif
const T_3 V_22 = F_73 ( V_138 -> V_142 ) ;
struct V_15 * V_17 , * V_82 ;
struct V_29 * V_30 ;
unsigned long V_23 ;
T_3 V_77 ;
F_85 ( V_97 -> V_11 , V_138 ) ;
V_82 = V_57 -> V_16 ;
V_77 = 0 ;
V_17 = F_59 ( V_82 , V_77 ) ;
if ( ! V_17 )
return - V_143 ;
#ifdef F_54
F_55 ( V_76 -> gets ) ;
#endif
for (; ; ) {
V_23 = F_60 ( V_22 , V_17 ) ;
if ( V_23 >= ( 1ul << V_17 -> V_21 ) )
break;
if ( F_86 ( V_17 ) )
goto V_144;
if ( V_17 -> V_42 > V_17 -> V_26 ) {
V_82 = V_17 ;
V_77 = V_23 ;
}
V_17 = F_59 ( V_17 , V_23 ) ;
if ( F_87 ( ! V_17 ) )
goto V_145;
}
for (; ; ) {
struct V_15 T_7 * * V_146 = V_17 -> V_14 ;
if ( F_87 ( F_83 ( V_22 , V_17 ) ) || ( V_17 -> V_42 == V_17 -> V_26 ) )
goto V_145;
if ( F_87 ( F_86 ( V_17 ) ) )
break;
while ( ( V_17 = F_88 ( * V_146 ) ) == NULL ) {
V_145:
#ifdef F_54
if ( ! V_17 )
F_55 ( V_76 -> V_147 ) ;
#endif
while ( ! V_77 ) {
T_3 V_148 = V_82 -> V_22 ;
if ( F_37 ( V_82 ) )
return - V_143 ;
#ifdef F_54
F_55 ( V_76 -> V_149 ) ;
#endif
V_82 = F_89 ( V_82 ) ;
V_77 = F_10 ( V_148 , V_82 ) ;
}
V_77 &= V_77 - 1 ;
V_146 = & V_82 -> V_14 [ V_77 ] ;
}
}
V_144:
V_23 = V_22 ^ V_17 -> V_22 ;
F_90 (fa, &n->leaf, fa_list) {
struct V_8 * V_9 = V_30 -> V_87 ;
int V_150 , V_108 ;
if ( ( V_24 > V_25 ) || ( V_30 -> V_43 < V_25 ) ) {
if ( V_23 >= ( 1ul << V_30 -> V_43 ) )
continue;
}
if ( V_30 -> V_86 && V_30 -> V_86 != V_138 -> V_151 )
continue;
if ( V_9 -> V_152 )
continue;
if ( V_30 -> V_87 -> V_153 < V_138 -> V_154 )
continue;
F_91 ( V_30 ) ;
V_108 = V_155 [ V_30 -> V_116 ] . error ;
if ( F_87 ( V_108 < 0 ) ) {
#ifdef F_54
F_55 ( V_76 -> V_156 ) ;
#endif
return V_108 ;
}
if ( V_9 -> V_141 & V_157 )
continue;
for ( V_150 = 0 ; V_150 < V_9 -> V_158 ; V_150 ++ ) {
const struct V_159 * V_160 = & V_9 -> V_159 [ V_150 ] ;
struct V_161 * V_162 = F_92 ( V_160 -> V_163 ) ;
if ( V_160 -> V_164 & V_157 )
continue;
if ( V_162 &&
F_93 ( V_162 ) &&
V_160 -> V_164 & V_165 &&
! ( V_141 & V_166 ) )
continue;
if ( ! ( V_138 -> V_167 & V_168 ) ) {
if ( V_138 -> V_169 &&
V_138 -> V_169 != V_160 -> V_170 )
continue;
}
if ( ! ( V_141 & V_171 ) )
F_94 ( & V_9 -> V_172 ) ;
V_140 -> V_136 = F_79 ( V_17 -> V_22 ) ;
V_140 -> V_173 = V_25 - V_30 -> V_43 ;
V_140 -> V_174 = V_150 ;
V_140 -> type = V_30 -> V_116 ;
V_140 -> V_175 = V_9 -> V_153 ;
V_140 -> V_9 = V_9 ;
V_140 -> V_176 = V_97 ;
V_140 -> V_177 = & V_17 -> V_44 ;
#ifdef F_54
F_55 ( V_76 -> V_156 ) ;
#endif
F_95 ( V_160 ) ;
return V_108 ;
}
}
#ifdef F_54
F_55 ( V_76 -> V_178 ) ;
#endif
goto V_145;
}
static void F_96 ( struct V_56 * V_57 , struct V_15 * V_18 ,
struct V_15 * V_41 , struct V_29 * V_179 )
{
struct V_180 * * V_181 = V_179 -> V_45 . V_181 ;
struct V_29 * V_30 = F_97 ( V_181 , F_98 ( * V_30 ) , V_45 . V_52 ) ;
F_99 ( & V_179 -> V_45 ) ;
if ( F_100 ( & V_41 -> V_44 ) ) {
if ( V_18 -> V_42 == V_41 -> V_42 )
F_56 ( V_18 , V_18 -> V_26 ) ;
F_36 ( V_18 , V_41 -> V_22 , NULL ) ;
F_41 ( V_41 ) ;
F_63 ( V_57 , V_18 ) ;
return;
}
if ( * V_181 )
return;
V_41 -> V_42 = V_30 -> V_43 ;
F_56 ( V_18 , V_30 -> V_43 ) ;
}
int F_101 ( struct V_3 * V_3 , struct V_96 * V_97 ,
struct V_98 * V_99 , struct V_94 * V_95 )
{
struct V_56 * V_57 = (struct V_56 * ) V_97 -> V_102 ;
struct V_29 * V_30 , * V_182 ;
struct V_15 * V_41 , * V_18 ;
T_2 V_93 = V_99 -> V_106 ;
T_2 V_42 = V_25 - V_93 ;
T_2 V_10 = V_99 -> V_107 ;
T_1 V_22 ;
V_22 = F_73 ( V_99 -> V_109 ) ;
if ( ! F_70 ( V_22 , V_93 , V_95 ) )
return - V_110 ;
V_41 = F_58 ( V_57 , & V_18 , V_22 ) ;
if ( ! V_41 )
return - V_183 ;
V_30 = F_61 ( & V_41 -> V_44 , V_42 , V_10 , 0 , V_97 -> V_11 ) ;
if ( ! V_30 )
return - V_183 ;
F_29 ( L_8 , V_22 , V_93 , V_10 , V_57 ) ;
V_182 = NULL ;
F_77 (fa, fa_list) {
struct V_8 * V_9 = V_30 -> V_87 ;
if ( ( V_30 -> V_43 != V_42 ) ||
( V_30 -> V_11 != V_97 -> V_11 ) ||
( V_30 -> V_86 != V_10 ) )
break;
if ( ( ! V_99 -> V_117 || V_30 -> V_116 == V_99 -> V_117 ) &&
( V_99 -> V_184 == V_185 ||
V_30 -> V_87 -> V_153 == V_99 -> V_184 ) &&
( ! V_99 -> V_186 ||
V_9 -> V_187 == V_99 -> V_186 ) &&
( ! V_99 -> V_188 ||
V_9 -> V_189 == V_99 -> V_188 ) &&
F_102 ( V_99 , V_9 , V_95 ) == 0 ) {
V_182 = V_30 ;
break;
}
}
if ( ! V_182 )
return - V_183 ;
F_3 ( V_3 , V_190 , V_22 , V_93 ,
V_182 -> V_87 , V_10 ,
V_182 -> V_116 , V_97 -> V_11 ) ;
F_78 ( V_191 , F_79 ( V_22 ) , V_182 , V_93 , V_97 -> V_11 ,
& V_99 -> V_127 , 0 ) ;
if ( ! V_93 )
V_97 -> V_135 -- ;
F_96 ( V_57 , V_18 , V_41 , V_182 ) ;
if ( V_182 -> V_122 & V_123 )
F_82 ( V_99 -> V_127 . V_128 ) ;
F_81 ( V_182 -> V_87 ) ;
F_13 ( V_182 ) ;
return 0 ;
}
static struct V_15 * F_103 ( struct V_15 * * V_20 , T_3 V_22 )
{
struct V_15 * V_82 , * V_17 = * V_20 ;
unsigned long V_77 ;
do {
V_82 = V_17 ;
V_77 = ( V_22 > V_82 -> V_22 ) ? F_10 ( V_22 , V_82 ) : 0 ;
if ( V_77 >> V_82 -> V_21 )
break;
V_17 = F_59 ( V_82 , V_77 ++ ) ;
if ( ! V_17 )
break;
if ( F_86 ( V_17 ) && ( V_17 -> V_22 >= V_22 ) )
goto V_144;
} while ( F_31 ( V_17 ) );
while ( ! F_37 ( V_82 ) ) {
if ( V_77 >= ( 1ul << V_82 -> V_21 ) ) {
T_3 V_148 = V_82 -> V_22 ;
V_82 = F_89 ( V_82 ) ;
V_77 = F_10 ( V_148 , V_82 ) + 1 ;
continue;
}
V_17 = F_59 ( V_82 , V_77 ++ ) ;
if ( ! V_17 )
continue;
if ( F_86 ( V_17 ) )
goto V_144;
V_82 = V_17 ;
V_77 = 0 ;
}
* V_20 = V_82 ;
return NULL ;
V_144:
* V_20 = V_82 ;
return V_17 ;
}
static void F_104 ( struct V_96 * V_97 )
{
struct V_56 * V_57 = (struct V_56 * ) V_97 -> V_102 ;
struct V_15 * V_82 = V_57 -> V_16 ;
unsigned long V_77 = 1 ;
struct V_180 * V_192 ;
struct V_29 * V_30 ;
for (; ; ) {
struct V_15 * V_17 ;
if ( ! ( V_77 -- ) ) {
T_3 V_148 = V_82 -> V_22 ;
if ( F_37 ( V_82 ) )
break;
V_17 = V_82 ;
V_82 = F_35 ( V_82 ) ;
F_36 ( V_82 , V_17 -> V_22 , NULL ) ;
F_41 ( V_17 ) ;
V_77 = F_10 ( V_148 , V_82 ) ;
continue;
}
V_17 = F_33 ( V_82 , V_77 ) ;
if ( ! V_17 )
continue;
if ( F_31 ( V_17 ) ) {
V_82 = V_17 ;
V_77 = 1ul << V_17 -> V_21 ;
continue;
}
F_105 (fa, tmp, &n->leaf, fa_list) {
F_99 ( & V_30 -> V_45 ) ;
F_13 ( V_30 ) ;
}
F_36 ( V_82 , V_17 -> V_22 , NULL ) ;
F_41 ( V_17 ) ;
}
#ifdef F_54
F_106 ( V_57 -> V_76 ) ;
#endif
F_107 ( V_97 ) ;
}
struct V_96 * F_108 ( struct V_96 * V_193 )
{
struct V_56 * V_194 = (struct V_56 * ) V_193 -> V_102 ;
struct V_15 * V_41 , * V_18 = V_194 -> V_16 ;
struct V_96 * V_195 ;
struct V_29 * V_30 ;
struct V_56 * V_196 ;
T_3 V_22 = 0 ;
if ( V_193 -> V_102 == V_193 -> V_197 )
return V_193 ;
V_195 = F_109 ( V_198 , NULL ) ;
if ( ! V_195 )
return NULL ;
V_196 = (struct V_56 * ) V_195 -> V_102 ;
while ( ( V_41 = F_103 ( & V_18 , V_22 ) ) != NULL ) {
struct V_15 * V_199 = NULL , * V_200 ;
F_90 (fa, &l->leaf, fa_list) {
struct V_29 * V_103 ;
if ( V_195 -> V_11 != V_30 -> V_11 )
continue;
V_103 = F_24 ( V_32 , V_38 ) ;
if ( ! V_103 )
goto V_115;
memcpy ( V_103 , V_30 , sizeof( * V_30 ) ) ;
if ( ! V_199 )
V_199 = F_58 ( V_196 , & V_200 , V_41 -> V_22 ) ;
if ( F_66 ( V_196 , V_200 , V_199 , V_103 ,
NULL , V_41 -> V_22 ) ) {
F_12 ( V_32 , V_103 ) ;
goto V_115;
}
}
V_22 = V_41 -> V_22 + 1 ;
if ( V_22 < V_41 -> V_22 )
break;
}
return V_195 ;
V_115:
F_104 ( V_195 ) ;
return NULL ;
}
void F_110 ( struct V_96 * V_97 )
{
struct V_56 * V_57 = (struct V_56 * ) V_97 -> V_102 ;
struct V_15 * V_82 = V_57 -> V_16 ;
unsigned long V_77 = 1 ;
struct V_180 * V_192 ;
struct V_29 * V_30 ;
for (; ; ) {
unsigned char V_42 = 0 ;
struct V_15 * V_17 ;
if ( ! ( V_77 -- ) ) {
T_3 V_148 = V_82 -> V_22 ;
if ( F_37 ( V_82 ) )
break;
if ( V_82 -> V_42 > V_82 -> V_26 )
F_49 ( V_82 ) ;
V_82 = F_45 ( V_57 , V_82 ) ;
V_77 = F_10 ( V_148 , V_82 ) ;
continue;
}
V_17 = F_33 ( V_82 , V_77 ) ;
if ( ! V_17 )
continue;
if ( F_31 ( V_17 ) ) {
V_82 = V_17 ;
V_77 = 1ul << V_17 -> V_21 ;
continue;
}
F_105 (fa, tmp, &n->leaf, fa_list) {
if ( V_97 -> V_11 != V_30 -> V_11 ) {
F_99 ( & V_30 -> V_45 ) ;
F_13 ( V_30 ) ;
continue;
}
V_42 = V_30 -> V_43 ;
}
V_17 -> V_42 = V_42 ;
if ( F_100 ( & V_17 -> V_44 ) ) {
F_36 ( V_82 , V_17 -> V_22 , NULL ) ;
F_41 ( V_17 ) ;
}
}
}
int F_111 ( struct V_3 * V_3 , struct V_96 * V_97 )
{
struct V_56 * V_57 = (struct V_56 * ) V_97 -> V_102 ;
struct V_15 * V_82 = V_57 -> V_16 ;
unsigned long V_77 = 1 ;
struct V_180 * V_192 ;
struct V_29 * V_30 ;
int V_144 = 0 ;
for (; ; ) {
unsigned char V_42 = 0 ;
struct V_15 * V_17 ;
if ( ! ( V_77 -- ) ) {
T_3 V_148 = V_82 -> V_22 ;
if ( F_37 ( V_82 ) )
break;
if ( V_82 -> V_42 > V_82 -> V_26 )
F_49 ( V_82 ) ;
V_82 = F_45 ( V_57 , V_82 ) ;
V_77 = F_10 ( V_148 , V_82 ) ;
continue;
}
V_17 = F_33 ( V_82 , V_77 ) ;
if ( ! V_17 )
continue;
if ( F_31 ( V_17 ) ) {
V_82 = V_17 ;
V_77 = 1ul << V_17 -> V_21 ;
continue;
}
F_105 (fa, tmp, &n->leaf, fa_list) {
struct V_8 * V_9 = V_30 -> V_87 ;
if ( ! V_9 || ! ( V_9 -> V_141 & V_157 ) ||
V_97 -> V_11 != V_30 -> V_11 ) {
V_42 = V_30 -> V_43 ;
continue;
}
F_3 ( V_3 , V_190 ,
V_17 -> V_22 ,
V_25 - V_30 -> V_43 ,
V_9 , V_30 -> V_86 , V_30 -> V_116 ,
V_97 -> V_11 ) ;
F_99 ( & V_30 -> V_45 ) ;
F_81 ( V_30 -> V_87 ) ;
F_13 ( V_30 ) ;
V_144 ++ ;
}
V_17 -> V_42 = V_42 ;
if ( F_100 ( & V_17 -> V_44 ) ) {
F_36 ( V_82 , V_17 -> V_22 , NULL ) ;
F_41 ( V_17 ) ;
}
}
F_29 ( L_9 , V_144 ) ;
return V_144 ;
}
static void F_112 ( struct V_3 * V_3 , struct V_15 * V_41 ,
struct V_96 * V_97 , struct V_1 * V_2 )
{
struct V_29 * V_30 ;
F_90 (fa, &l->leaf, fa_list) {
struct V_8 * V_9 = V_30 -> V_87 ;
if ( ! V_9 )
continue;
if ( V_97 -> V_11 != V_30 -> V_11 )
continue;
F_1 ( V_2 , V_3 , V_101 , V_41 -> V_22 ,
V_25 - V_30 -> V_43 , V_9 , V_30 -> V_86 ,
V_30 -> V_116 , V_30 -> V_11 ) ;
}
}
static void F_113 ( struct V_3 * V_3 , struct V_96 * V_97 ,
struct V_1 * V_2 )
{
struct V_56 * V_57 = (struct V_56 * ) V_97 -> V_102 ;
struct V_15 * V_41 , * V_18 = V_57 -> V_16 ;
T_3 V_22 = 0 ;
while ( ( V_41 = F_103 ( & V_18 , V_22 ) ) != NULL ) {
F_112 ( V_3 , V_41 , V_97 , V_2 ) ;
V_22 = V_41 -> V_22 + 1 ;
if ( V_22 < V_41 -> V_22 )
break;
}
}
void F_114 ( struct V_3 * V_3 , struct V_1 * V_2 )
{
unsigned int V_201 ;
for ( V_201 = 0 ; V_201 < V_202 ; V_201 ++ ) {
struct V_83 * V_28 = & V_3 -> V_203 . V_204 [ V_201 ] ;
struct V_96 * V_97 ;
F_90 (tb, head, tb_hlist)
F_113 ( V_3 , V_97 , V_2 ) ;
}
}
static void F_115 ( struct V_27 * V_28 )
{
struct V_96 * V_97 = F_6 ( V_28 , struct V_96 , V_31 ) ;
#ifdef F_54
struct V_56 * V_57 = (struct V_56 * ) V_97 -> V_102 ;
if ( V_97 -> V_102 == V_97 -> V_197 )
F_106 ( V_57 -> V_76 ) ;
#endif
F_107 ( V_97 ) ;
}
void F_116 ( struct V_96 * V_97 )
{
F_14 ( & V_97 -> V_31 , F_115 ) ;
}
static int F_117 ( struct V_15 * V_41 , struct V_96 * V_97 ,
struct V_205 * V_206 , struct V_207 * V_208 )
{
T_8 V_209 = F_79 ( V_41 -> V_22 ) ;
struct V_29 * V_30 ;
int V_47 , V_210 ;
V_210 = V_208 -> args [ 4 ] ;
V_47 = 0 ;
F_90 (fa, &l->leaf, fa_list) {
int V_108 ;
if ( V_47 < V_210 ) {
V_47 ++ ;
continue;
}
if ( V_97 -> V_11 != V_30 -> V_11 ) {
V_47 ++ ;
continue;
}
V_108 = F_118 ( V_206 , F_119 ( V_208 -> V_206 ) . V_211 ,
V_208 -> V_212 -> V_213 , V_126 ,
V_97 -> V_11 , V_30 -> V_116 ,
V_209 , V_25 - V_30 -> V_43 ,
V_30 -> V_86 , V_30 -> V_87 , V_214 ) ;
if ( V_108 < 0 ) {
V_208 -> args [ 4 ] = V_47 ;
return V_108 ;
}
V_47 ++ ;
}
V_208 -> args [ 4 ] = V_47 ;
return V_206 -> V_215 ;
}
int F_120 ( struct V_96 * V_97 , struct V_205 * V_206 ,
struct V_207 * V_208 )
{
struct V_56 * V_57 = (struct V_56 * ) V_97 -> V_102 ;
struct V_15 * V_41 , * V_18 = V_57 -> V_16 ;
int V_216 = V_208 -> args [ 2 ] ;
T_3 V_22 = V_208 -> args [ 3 ] ;
while ( ( V_41 = F_103 ( & V_18 , V_22 ) ) != NULL ) {
int V_108 ;
V_108 = F_117 ( V_41 , V_97 , V_206 , V_208 ) ;
if ( V_108 < 0 ) {
V_208 -> args [ 3 ] = V_22 ;
V_208 -> args [ 2 ] = V_216 ;
return V_108 ;
}
++ V_216 ;
V_22 = V_41 -> V_22 + 1 ;
memset ( & V_208 -> args [ 4 ] , 0 ,
sizeof( V_208 -> args ) - 4 * sizeof( V_208 -> args [ 0 ] ) ) ;
if ( V_22 < V_41 -> V_22 )
break;
}
V_208 -> args [ 3 ] = V_22 ;
V_208 -> args [ 2 ] = V_216 ;
return V_206 -> V_215 ;
}
void T_9 F_121 ( void )
{
V_32 = F_122 ( L_10 ,
sizeof( struct V_29 ) ,
0 , V_217 , NULL ) ;
V_34 = F_122 ( L_11 ,
V_218 ,
0 , V_217 , NULL ) ;
}
struct V_96 * F_109 ( T_1 V_219 , struct V_96 * V_220 )
{
struct V_96 * V_97 ;
struct V_56 * V_57 ;
T_4 V_221 = sizeof( * V_97 ) ;
if ( ! V_220 )
V_221 += sizeof( struct V_56 ) ;
V_97 = F_19 ( V_221 , V_38 ) ;
if ( ! V_97 )
return NULL ;
V_97 -> V_11 = V_219 ;
V_97 -> V_135 = 0 ;
V_97 -> V_102 = ( V_220 ? V_220 -> V_197 : V_97 -> V_197 ) ;
if ( V_220 )
return V_97 ;
V_57 = (struct V_56 * ) V_97 -> V_102 ;
V_57 -> V_16 [ 0 ] . V_26 = V_25 ;
V_57 -> V_16 [ 0 ] . V_42 = V_25 ;
#ifdef F_54
V_57 -> V_76 = F_123 ( struct V_75 ) ;
if ( ! V_57 -> V_76 ) {
F_107 ( V_97 ) ;
V_97 = NULL ;
}
#endif
return V_97 ;
}
static struct V_15 * F_124 ( struct V_222 * V_223 )
{
unsigned long V_77 = V_223 -> V_23 ;
struct V_15 * V_82 = V_223 -> V_14 ;
T_3 V_148 ;
F_29 ( L_12 ,
V_223 -> V_14 , V_223 -> V_23 , V_223 -> V_224 ) ;
while ( ! F_37 ( V_82 ) ) {
while ( V_77 < F_9 ( V_82 ) ) {
struct V_15 * V_17 = F_59 ( V_82 , V_77 ++ ) ;
if ( ! V_17 )
continue;
if ( F_86 ( V_17 ) ) {
V_223 -> V_14 = V_82 ;
V_223 -> V_23 = V_77 ;
} else {
V_223 -> V_14 = V_17 ;
V_223 -> V_23 = 0 ;
++ V_223 -> V_224 ;
}
return V_17 ;
}
V_148 = V_82 -> V_22 ;
V_82 = F_89 ( V_82 ) ;
V_77 = F_10 ( V_148 , V_82 ) + 1 ;
-- V_223 -> V_224 ;
}
V_223 -> V_14 = V_82 ;
V_223 -> V_23 = 0 ;
return NULL ;
}
static struct V_15 * F_125 ( struct V_222 * V_223 ,
struct V_56 * V_57 )
{
struct V_15 * V_17 , * V_82 ;
if ( ! V_57 )
return NULL ;
V_82 = V_57 -> V_16 ;
V_17 = F_88 ( V_82 -> V_14 [ 0 ] ) ;
if ( ! V_17 )
return NULL ;
if ( F_31 ( V_17 ) ) {
V_223 -> V_14 = V_17 ;
V_223 -> V_23 = 0 ;
V_223 -> V_224 = 1 ;
} else {
V_223 -> V_14 = V_82 ;
V_223 -> V_23 = 0 ;
V_223 -> V_224 = 0 ;
}
return V_17 ;
}
static void F_126 ( struct V_56 * V_57 , struct V_225 * V_226 )
{
struct V_15 * V_17 ;
struct V_222 V_223 ;
memset ( V_226 , 0 , sizeof( * V_226 ) ) ;
F_127 () ;
for ( V_17 = F_125 ( & V_223 , V_57 ) ; V_17 ; V_17 = F_124 ( & V_223 ) ) {
if ( F_86 ( V_17 ) ) {
struct V_29 * V_30 ;
V_226 -> V_227 ++ ;
V_226 -> V_228 += V_223 . V_224 ;
if ( V_223 . V_224 > V_226 -> V_229 )
V_226 -> V_229 = V_223 . V_224 ;
F_90 ( V_30 , & V_17 -> V_44 , V_45 )
++ V_226 -> V_230 ;
} else {
V_226 -> V_231 ++ ;
if ( V_17 -> V_21 < V_232 )
V_226 -> V_233 [ V_17 -> V_21 ] ++ ;
V_226 -> V_234 += F_5 ( V_17 ) -> V_39 ;
}
}
F_128 () ;
}
static void F_129 ( struct V_235 * V_236 , struct V_225 * V_237 )
{
unsigned int V_47 , V_238 , V_239 , V_240 , V_241 ;
if ( V_237 -> V_227 )
V_241 = V_237 -> V_228 * 100 / V_237 -> V_227 ;
else
V_241 = 0 ;
F_130 ( V_236 , L_13 ,
V_241 / 100 , V_241 % 100 ) ;
F_130 ( V_236 , L_14 , V_237 -> V_229 ) ;
F_130 ( V_236 , L_15 , V_237 -> V_227 ) ;
V_240 = V_218 * V_237 -> V_227 ;
F_130 ( V_236 , L_16 , V_237 -> V_230 ) ;
V_240 += sizeof( struct V_29 ) * V_237 -> V_230 ;
F_130 ( V_236 , L_17 , V_237 -> V_231 ) ;
V_240 += F_18 ( 0 ) * V_237 -> V_231 ;
V_238 = V_232 ;
while ( V_238 > 0 && V_237 -> V_233 [ V_238 - 1 ] == 0 )
V_238 -- ;
V_239 = 0 ;
for ( V_47 = 1 ; V_47 < V_238 ; V_47 ++ )
if ( V_237 -> V_233 [ V_47 ] != 0 ) {
F_130 ( V_236 , L_18 , V_47 , V_237 -> V_233 [ V_47 ] ) ;
V_239 += ( 1 << V_47 ) * V_237 -> V_233 [ V_47 ] ;
}
F_131 ( V_236 , '\n' ) ;
F_130 ( V_236 , L_19 , V_239 ) ;
V_240 += sizeof( struct V_15 * ) * V_239 ;
F_130 ( V_236 , L_20 , V_237 -> V_234 ) ;
F_130 ( V_236 , L_21 , ( V_240 + 1023 ) / 1024 ) ;
}
static void F_132 ( struct V_235 * V_236 ,
const struct V_75 T_5 * V_76 )
{
struct V_75 V_226 = { 0 } ;
int V_242 ;
F_133 (cpu) {
const struct V_75 * V_243 = F_134 ( V_76 , V_242 ) ;
V_226 . gets += V_243 -> gets ;
V_226 . V_149 += V_243 -> V_149 ;
V_226 . V_156 += V_243 -> V_156 ;
V_226 . V_178 += V_243 -> V_178 ;
V_226 . V_147 += V_243 -> V_147 ;
V_226 . V_80 += V_243 -> V_80 ;
}
F_130 ( V_236 , L_22 ) ;
F_130 ( V_236 , L_23 , V_226 . gets ) ;
F_130 ( V_236 , L_24 , V_226 . V_149 ) ;
F_130 ( V_236 , L_25 ,
V_226 . V_156 ) ;
F_130 ( V_236 , L_26 , V_226 . V_178 ) ;
F_130 ( V_236 , L_27 , V_226 . V_147 ) ;
F_130 ( V_236 , L_28 , V_226 . V_80 ) ;
}
static void F_135 ( struct V_235 * V_236 , struct V_96 * V_97 )
{
if ( V_97 -> V_11 == V_198 )
F_136 ( V_236 , L_29 ) ;
else if ( V_97 -> V_11 == V_244 )
F_136 ( V_236 , L_30 ) ;
else
F_130 ( V_236 , L_31 , V_97 -> V_11 ) ;
}
static int F_137 ( struct V_235 * V_236 , void * V_245 )
{
struct V_3 * V_3 = (struct V_3 * ) V_236 -> V_246 ;
unsigned int V_201 ;
F_130 ( V_236 ,
L_32
L_33 ,
V_218 , F_18 ( 0 ) ) ;
for ( V_201 = 0 ; V_201 < V_202 ; V_201 ++ ) {
struct V_83 * V_28 = & V_3 -> V_203 . V_204 [ V_201 ] ;
struct V_96 * V_97 ;
F_90 (tb, head, tb_hlist) {
struct V_56 * V_57 = (struct V_56 * ) V_97 -> V_102 ;
struct V_225 V_237 ;
if ( ! V_57 )
continue;
F_135 ( V_236 , V_97 ) ;
F_126 ( V_57 , & V_237 ) ;
F_129 ( V_236 , & V_237 ) ;
#ifdef F_54
F_132 ( V_236 , V_57 -> V_76 ) ;
#endif
}
}
return 0 ;
}
static int F_138 ( struct V_51 * V_51 , struct V_247 * V_247 )
{
return F_139 ( V_51 , V_247 , F_137 ) ;
}
static struct V_15 * F_140 ( struct V_235 * V_236 , T_10 V_26 )
{
struct V_222 * V_223 = V_236 -> V_246 ;
struct V_3 * V_3 = F_141 ( V_236 ) ;
T_10 V_248 = 0 ;
unsigned int V_201 ;
for ( V_201 = 0 ; V_201 < V_202 ; V_201 ++ ) {
struct V_83 * V_28 = & V_3 -> V_203 . V_204 [ V_201 ] ;
struct V_96 * V_97 ;
F_90 (tb, head, tb_hlist) {
struct V_15 * V_17 ;
for ( V_17 = F_125 ( V_223 ,
(struct V_56 * ) V_97 -> V_102 ) ;
V_17 ; V_17 = F_124 ( V_223 ) )
if ( V_26 == V_248 ++ ) {
V_223 -> V_97 = V_97 ;
return V_17 ;
}
}
}
return NULL ;
}
static void * F_142 ( struct V_235 * V_236 , T_10 * V_26 )
__acquires( T_11 )
{
F_127 () ;
return F_140 ( V_236 , * V_26 ) ;
}
static void * F_143 ( struct V_235 * V_236 , void * V_245 , T_10 * V_26 )
{
struct V_222 * V_223 = V_236 -> V_246 ;
struct V_3 * V_3 = F_141 ( V_236 ) ;
struct V_96 * V_97 = V_223 -> V_97 ;
struct V_180 * V_249 ;
unsigned int V_201 ;
struct V_15 * V_17 ;
++ * V_26 ;
V_17 = F_124 ( V_223 ) ;
if ( V_17 )
return V_17 ;
V_201 = V_97 -> V_11 & ( V_202 - 1 ) ;
while ( ( V_249 = F_88 ( F_144 ( & V_97 -> V_250 ) ) ) ) {
V_97 = F_97 ( V_249 , struct V_96 , V_250 ) ;
V_17 = F_125 ( V_223 , (struct V_56 * ) V_97 -> V_102 ) ;
if ( V_17 )
goto V_144;
}
while ( ++ V_201 < V_202 ) {
struct V_83 * V_28 = & V_3 -> V_203 . V_204 [ V_201 ] ;
F_90 (tb, head, tb_hlist) {
V_17 = F_125 ( V_223 , (struct V_56 * ) V_97 -> V_102 ) ;
if ( V_17 )
goto V_144;
}
}
return NULL ;
V_144:
V_223 -> V_97 = V_97 ;
return V_17 ;
}
static void F_145 ( struct V_235 * V_236 , void * V_245 )
__releases( T_11 )
{
F_128 () ;
}
static void F_146 ( struct V_235 * V_236 , int V_17 )
{
while ( V_17 -- > 0 )
F_136 ( V_236 , L_34 ) ;
}
static inline const char * F_147 ( char * V_251 , T_4 V_215 , enum V_252 V_226 )
{
switch ( V_226 ) {
case V_253 : return L_35 ;
case V_254 : return L_36 ;
case V_255 : return L_37 ;
case V_256 : return L_38 ;
case V_185 : return L_39 ;
default:
snprintf ( V_251 , V_215 , L_40 , V_226 ) ;
return V_251 ;
}
}
static inline const char * F_148 ( char * V_251 , T_4 V_215 , unsigned int V_57 )
{
if ( V_57 < V_257 && V_258 [ V_57 ] )
return V_258 [ V_57 ] ;
snprintf ( V_251 , V_215 , L_41 , V_57 ) ;
return V_251 ;
}
static int F_149 ( struct V_235 * V_236 , void * V_245 )
{
const struct V_222 * V_223 = V_236 -> V_246 ;
struct V_15 * V_17 = V_245 ;
if ( F_37 ( F_89 ( V_17 ) ) )
F_135 ( V_236 , V_223 -> V_97 ) ;
if ( F_31 ( V_17 ) ) {
T_8 V_259 = F_79 ( V_17 -> V_22 ) ;
F_146 ( V_236 , V_223 -> V_224 - 1 ) ;
F_130 ( V_236 , L_42 ,
& V_259 , V_25 - V_17 -> V_26 - V_17 -> V_21 , V_17 -> V_21 ,
F_5 ( V_17 ) -> V_40 ,
F_5 ( V_17 ) -> V_39 ) ;
} else {
T_8 V_260 = F_79 ( V_17 -> V_22 ) ;
struct V_29 * V_30 ;
F_146 ( V_236 , V_223 -> V_224 ) ;
F_130 ( V_236 , L_43 , & V_260 ) ;
F_90 (fa, &n->leaf, fa_list) {
char V_261 [ 32 ] , V_262 [ 32 ] ;
F_146 ( V_236 , V_223 -> V_224 + 1 ) ;
F_130 ( V_236 , L_44 ,
V_25 - V_30 -> V_43 ,
F_147 ( V_261 , sizeof( V_261 ) ,
V_30 -> V_87 -> V_153 ) ,
F_148 ( V_262 , sizeof( V_262 ) ,
V_30 -> V_116 ) ) ;
if ( V_30 -> V_86 )
F_130 ( V_236 , L_45 , V_30 -> V_86 ) ;
F_131 ( V_236 , '\n' ) ;
}
}
return 0 ;
}
static int F_150 ( struct V_51 * V_51 , struct V_247 * V_247 )
{
return F_151 ( V_51 , V_247 , & V_263 ,
sizeof( struct V_222 ) ) ;
}
static struct V_15 * F_152 ( struct V_264 * V_223 ,
T_10 V_26 )
{
struct V_15 * V_41 , * * V_18 = & V_223 -> V_14 ;
T_3 V_22 ;
if ( V_223 -> V_26 > 0 && V_26 >= V_223 -> V_26 ) {
V_22 = V_223 -> V_22 ;
} else {
V_223 -> V_26 = 1 ;
V_22 = 0 ;
}
V_26 -= V_223 -> V_26 ;
while ( ( V_41 = F_103 ( V_18 , V_22 ) ) && ( V_26 -- > 0 ) ) {
V_22 = V_41 -> V_22 + 1 ;
V_223 -> V_26 ++ ;
V_41 = NULL ;
if ( ! V_22 )
break;
}
if ( V_41 )
V_223 -> V_22 = V_41 -> V_22 ;
else
V_223 -> V_26 = 0 ;
return V_41 ;
}
static void * F_153 ( struct V_235 * V_236 , T_10 * V_26 )
__acquires( T_11 )
{
struct V_264 * V_223 = V_236 -> V_246 ;
struct V_96 * V_97 ;
struct V_56 * V_57 ;
F_127 () ;
V_97 = F_154 ( F_141 ( V_236 ) , V_244 ) ;
if ( ! V_97 )
return NULL ;
V_223 -> V_265 = V_97 ;
V_57 = (struct V_56 * ) V_97 -> V_102 ;
V_223 -> V_14 = V_57 -> V_16 ;
if ( * V_26 != 0 )
return F_152 ( V_223 , * V_26 ) ;
V_223 -> V_26 = 0 ;
V_223 -> V_22 = V_74 ;
return V_266 ;
}
static void * F_155 ( struct V_235 * V_236 , void * V_245 , T_10 * V_26 )
{
struct V_264 * V_223 = V_236 -> V_246 ;
struct V_15 * V_41 = NULL ;
T_3 V_22 = V_223 -> V_22 + 1 ;
++ * V_26 ;
if ( ( V_245 == V_266 ) || V_22 )
V_41 = F_103 ( & V_223 -> V_14 , V_22 ) ;
if ( V_41 ) {
V_223 -> V_22 = V_41 -> V_22 ;
V_223 -> V_26 ++ ;
} else {
V_223 -> V_26 = 0 ;
}
return V_41 ;
}
static void F_156 ( struct V_235 * V_236 , void * V_245 )
__releases( T_11 )
{
F_128 () ;
}
static unsigned int F_157 ( int type , T_8 V_267 , const struct V_8 * V_9 )
{
unsigned int V_268 = 0 ;
if ( type == V_269 || type == V_270 )
V_268 = V_271 ;
if ( V_9 && V_9 -> V_159 -> V_272 )
V_268 |= V_273 ;
if ( V_267 == F_79 ( 0xFFFFFFFF ) )
V_268 |= V_274 ;
V_268 |= V_275 ;
return V_268 ;
}
static int F_158 ( struct V_235 * V_236 , void * V_245 )
{
struct V_264 * V_223 = V_236 -> V_246 ;
struct V_96 * V_97 = V_223 -> V_265 ;
struct V_29 * V_30 ;
struct V_15 * V_41 = V_245 ;
T_8 V_136 ;
if ( V_245 == V_266 ) {
F_130 ( V_236 , L_46 , L_47
L_48
L_49 ) ;
return 0 ;
}
V_136 = F_79 ( V_41 -> V_22 ) ;
F_90 (fa, &l->leaf, fa_list) {
const struct V_8 * V_9 = V_30 -> V_87 ;
T_8 V_267 = F_159 ( V_25 - V_30 -> V_43 ) ;
unsigned int V_268 = F_157 ( V_30 -> V_116 , V_267 , V_9 ) ;
if ( ( V_30 -> V_116 == V_276 ) ||
( V_30 -> V_116 == V_277 ) )
continue;
if ( V_30 -> V_11 != V_97 -> V_11 )
continue;
F_160 ( V_236 , 127 ) ;
if ( V_9 )
F_130 ( V_236 ,
L_50
L_51 ,
V_9 -> V_278 ? V_9 -> V_278 -> V_279 : L_52 ,
V_136 ,
V_9 -> V_159 -> V_272 , V_268 , 0 , 0 ,
V_9 -> V_88 ,
V_267 ,
( V_9 -> V_280 ?
V_9 -> V_280 + 40 : 0 ) ,
V_9 -> V_281 ,
V_9 -> V_282 >> 3 ) ;
else
F_130 ( V_236 ,
L_53
L_51 ,
V_136 , 0 , V_268 , 0 , 0 , 0 ,
V_267 , 0 , 0 , 0 ) ;
F_161 ( V_236 , '\n' ) ;
}
return 0 ;
}
static int F_162 ( struct V_51 * V_51 , struct V_247 * V_247 )
{
return F_151 ( V_51 , V_247 , & V_283 ,
sizeof( struct V_264 ) ) ;
}
int T_12 F_163 ( struct V_3 * V_3 )
{
if ( ! F_164 ( L_54 , V_284 , V_3 -> V_285 , & V_286 ) )
goto V_287;
if ( ! F_164 ( L_55 , V_284 , V_3 -> V_285 ,
& V_288 ) )
goto V_289;
if ( ! F_164 ( L_56 , V_284 , V_3 -> V_285 , & V_290 ) )
goto V_291;
return 0 ;
V_291:
F_165 ( L_55 , V_3 -> V_285 ) ;
V_289:
F_165 ( L_54 , V_3 -> V_285 ) ;
V_287:
return - V_91 ;
}
void T_13 F_166 ( struct V_3 * V_3 )
{
F_165 ( L_54 , V_3 -> V_285 ) ;
F_165 ( L_55 , V_3 -> V_285 ) ;
F_165 ( L_56 , V_3 -> V_285 ) ;
}
