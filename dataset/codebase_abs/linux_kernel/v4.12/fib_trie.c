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
int F_70 ( struct V_3 * V_3 , struct V_93 * V_94 ,
struct V_95 * V_96 )
{
enum V_4 V_97 = V_98 ;
struct V_56 * V_57 = (struct V_56 * ) V_94 -> V_99 ;
struct V_29 * V_30 , * V_100 ;
struct V_15 * V_41 , * V_18 ;
T_6 V_101 = V_102 ;
struct V_8 * V_9 ;
T_2 V_103 = V_96 -> V_104 ;
T_2 V_42 = V_25 - V_103 ;
T_2 V_10 = V_96 -> V_105 ;
T_1 V_22 ;
int V_106 ;
if ( V_103 > V_25 )
return - V_107 ;
V_22 = F_71 ( V_96 -> V_108 ) ;
F_29 ( L_5 , V_94 -> V_11 , V_22 , V_103 ) ;
if ( ( V_103 < V_25 ) && ( V_22 << V_103 ) )
return - V_107 ;
V_9 = F_72 ( V_96 ) ;
if ( F_73 ( V_9 ) ) {
V_106 = F_74 ( V_9 ) ;
goto V_106;
}
V_41 = F_58 ( V_57 , & V_18 , V_22 ) ;
V_30 = V_41 ? F_61 ( & V_41 -> V_44 , V_42 , V_10 , V_9 -> V_88 ,
V_94 -> V_11 ) : NULL ;
if ( V_30 && V_30 -> V_86 == V_10 &&
V_30 -> V_87 -> V_88 == V_9 -> V_88 ) {
struct V_29 * V_109 , * V_110 ;
V_106 = - V_111 ;
if ( V_96 -> V_112 & V_102 )
goto V_113;
V_101 &= ~ V_102 ;
V_110 = NULL ;
V_109 = V_30 ;
F_75 (fa, fa_list) {
if ( ( V_30 -> V_43 != V_42 ) ||
( V_30 -> V_11 != V_94 -> V_11 ) ||
( V_30 -> V_86 != V_10 ) )
break;
if ( V_30 -> V_87 -> V_88 != V_9 -> V_88 )
break;
if ( V_30 -> V_114 == V_96 -> V_115 &&
V_30 -> V_87 == V_9 ) {
V_110 = V_30 ;
break;
}
}
if ( V_96 -> V_112 & V_116 ) {
struct V_8 * V_117 ;
T_2 V_118 ;
V_101 |= V_116 ;
V_30 = V_109 ;
if ( V_110 ) {
if ( V_30 == V_110 )
V_106 = 0 ;
goto V_113;
}
V_106 = - V_119 ;
V_100 = F_24 ( V_32 , V_38 ) ;
if ( ! V_100 )
goto V_113;
V_117 = V_30 -> V_87 ;
V_100 -> V_86 = V_30 -> V_86 ;
V_100 -> V_87 = V_9 ;
V_100 -> V_114 = V_96 -> V_115 ;
V_118 = V_30 -> V_120 ;
V_100 -> V_120 = V_118 & ~ V_121 ;
V_100 -> V_43 = V_30 -> V_43 ;
V_100 -> V_11 = V_94 -> V_11 ;
V_100 -> V_122 = - 1 ;
F_3 ( V_3 , V_123 ,
V_22 , V_103 , V_9 ,
V_100 -> V_86 , V_96 -> V_115 ,
V_94 -> V_11 ) ;
F_76 ( V_124 , F_77 ( V_22 ) , V_100 , V_103 ,
V_94 -> V_11 , & V_96 -> V_125 , V_101 ) ;
F_78 ( & V_30 -> V_45 , & V_100 -> V_45 ) ;
F_13 ( V_30 ) ;
F_79 ( V_117 ) ;
if ( V_118 & V_121 )
F_80 ( V_96 -> V_125 . V_126 ) ;
goto V_127;
}
if ( V_110 )
goto V_113;
if ( V_96 -> V_112 & V_128 ) {
V_97 = V_129 ;
V_101 |= V_128 ;
} else {
V_30 = V_109 ;
}
}
V_106 = - V_130 ;
if ( ! ( V_96 -> V_112 & V_131 ) )
goto V_113;
V_101 |= V_131 ;
V_106 = - V_119 ;
V_100 = F_24 ( V_32 , V_38 ) ;
if ( ! V_100 )
goto V_113;
V_100 -> V_87 = V_9 ;
V_100 -> V_86 = V_10 ;
V_100 -> V_114 = V_96 -> V_115 ;
V_100 -> V_120 = 0 ;
V_100 -> V_43 = V_42 ;
V_100 -> V_11 = V_94 -> V_11 ;
V_100 -> V_122 = - 1 ;
V_106 = F_66 ( V_57 , V_18 , V_41 , V_100 , V_30 , V_22 ) ;
if ( V_106 )
goto V_132;
if ( ! V_103 )
V_94 -> V_133 ++ ;
F_80 ( V_96 -> V_125 . V_126 ) ;
F_3 ( V_3 , V_97 , V_22 , V_103 , V_9 , V_10 , V_96 -> V_115 ,
V_94 -> V_11 ) ;
F_76 ( V_124 , F_77 ( V_22 ) , V_100 , V_103 , V_100 -> V_11 ,
& V_96 -> V_125 , V_101 ) ;
V_127:
return 0 ;
V_132:
F_12 ( V_32 , V_100 ) ;
V_113:
F_79 ( V_9 ) ;
V_106:
return V_106 ;
}
static inline T_3 F_81 ( T_3 V_22 , struct V_15 * V_17 )
{
T_3 V_134 = V_17 -> V_22 ;
return ( V_22 ^ V_134 ) & ( V_134 | - V_134 ) ;
}
int F_82 ( struct V_93 * V_94 , const struct V_135 * V_136 ,
struct V_137 * V_138 , int V_139 )
{
struct V_56 * V_57 = (struct V_56 * ) V_94 -> V_99 ;
#ifdef F_54
struct V_75 T_5 * V_76 = V_57 -> V_76 ;
#endif
const T_3 V_22 = F_71 ( V_136 -> V_140 ) ;
struct V_15 * V_17 , * V_82 ;
struct V_29 * V_30 ;
unsigned long V_23 ;
T_3 V_77 ;
F_83 ( V_94 -> V_11 , V_136 ) ;
V_82 = V_57 -> V_16 ;
V_77 = 0 ;
V_17 = F_59 ( V_82 , V_77 ) ;
if ( ! V_17 )
return - V_141 ;
#ifdef F_54
F_55 ( V_76 -> gets ) ;
#endif
for (; ; ) {
V_23 = F_60 ( V_22 , V_17 ) ;
if ( V_23 >= ( 1ul << V_17 -> V_21 ) )
break;
if ( F_84 ( V_17 ) )
goto V_142;
if ( V_17 -> V_42 > V_17 -> V_26 ) {
V_82 = V_17 ;
V_77 = V_23 ;
}
V_17 = F_59 ( V_17 , V_23 ) ;
if ( F_85 ( ! V_17 ) )
goto V_143;
}
for (; ; ) {
struct V_15 T_7 * * V_144 = V_17 -> V_14 ;
if ( F_85 ( F_81 ( V_22 , V_17 ) ) || ( V_17 -> V_42 == V_17 -> V_26 ) )
goto V_143;
if ( F_85 ( F_84 ( V_17 ) ) )
break;
while ( ( V_17 = F_86 ( * V_144 ) ) == NULL ) {
V_143:
#ifdef F_54
if ( ! V_17 )
F_55 ( V_76 -> V_145 ) ;
#endif
while ( ! V_77 ) {
T_3 V_146 = V_82 -> V_22 ;
if ( F_37 ( V_82 ) )
return - V_141 ;
#ifdef F_54
F_55 ( V_76 -> V_147 ) ;
#endif
V_82 = F_87 ( V_82 ) ;
V_77 = F_10 ( V_146 , V_82 ) ;
}
V_77 &= V_77 - 1 ;
V_144 = & V_82 -> V_14 [ V_77 ] ;
}
}
V_142:
V_23 = V_22 ^ V_17 -> V_22 ;
F_88 (fa, &n->leaf, fa_list) {
struct V_8 * V_9 = V_30 -> V_87 ;
int V_148 , V_106 ;
if ( ( V_24 > V_25 ) || ( V_30 -> V_43 < V_25 ) ) {
if ( V_23 >= ( 1ul << V_30 -> V_43 ) )
continue;
}
if ( V_30 -> V_86 && V_30 -> V_86 != V_136 -> V_149 )
continue;
if ( V_9 -> V_150 )
continue;
if ( V_30 -> V_87 -> V_151 < V_136 -> V_152 )
continue;
F_89 ( V_30 ) ;
V_106 = V_153 [ V_30 -> V_114 ] . error ;
if ( F_85 ( V_106 < 0 ) ) {
#ifdef F_54
F_55 ( V_76 -> V_154 ) ;
#endif
return V_106 ;
}
if ( V_9 -> V_139 & V_155 )
continue;
for ( V_148 = 0 ; V_148 < V_9 -> V_156 ; V_148 ++ ) {
const struct V_157 * V_158 = & V_9 -> V_157 [ V_148 ] ;
struct V_159 * V_160 = F_90 ( V_158 -> V_161 ) ;
if ( V_158 -> V_162 & V_155 )
continue;
if ( V_160 &&
F_91 ( V_160 ) &&
V_158 -> V_162 & V_163 &&
! ( V_139 & V_164 ) )
continue;
if ( ! ( V_136 -> V_165 & V_166 ) ) {
if ( V_136 -> V_167 &&
V_136 -> V_167 != V_158 -> V_168 )
continue;
}
if ( ! ( V_139 & V_169 ) )
F_92 ( & V_9 -> V_170 ) ;
V_138 -> V_171 = V_25 - V_30 -> V_43 ;
V_138 -> V_172 = V_148 ;
V_138 -> type = V_30 -> V_114 ;
V_138 -> V_173 = V_9 -> V_151 ;
V_138 -> V_9 = V_9 ;
V_138 -> V_174 = V_94 ;
V_138 -> V_175 = & V_17 -> V_44 ;
#ifdef F_54
F_55 ( V_76 -> V_154 ) ;
#endif
F_93 ( V_158 ) ;
return V_106 ;
}
}
#ifdef F_54
F_55 ( V_76 -> V_176 ) ;
#endif
goto V_143;
}
static void F_94 ( struct V_56 * V_57 , struct V_15 * V_18 ,
struct V_15 * V_41 , struct V_29 * V_177 )
{
struct V_178 * * V_179 = V_177 -> V_45 . V_179 ;
struct V_29 * V_30 = F_95 ( V_179 , F_96 ( * V_30 ) , V_45 . V_52 ) ;
F_97 ( & V_177 -> V_45 ) ;
if ( F_98 ( & V_41 -> V_44 ) ) {
if ( V_18 -> V_42 == V_41 -> V_42 )
F_56 ( V_18 , V_18 -> V_26 ) ;
F_36 ( V_18 , V_41 -> V_22 , NULL ) ;
F_41 ( V_41 ) ;
F_63 ( V_57 , V_18 ) ;
return;
}
if ( * V_179 )
return;
V_41 -> V_42 = V_30 -> V_43 ;
F_56 ( V_18 , V_30 -> V_43 ) ;
}
int F_99 ( struct V_3 * V_3 , struct V_93 * V_94 ,
struct V_95 * V_96 )
{
struct V_56 * V_57 = (struct V_56 * ) V_94 -> V_99 ;
struct V_29 * V_30 , * V_180 ;
struct V_15 * V_41 , * V_18 ;
T_2 V_103 = V_96 -> V_104 ;
T_2 V_42 = V_25 - V_103 ;
T_2 V_10 = V_96 -> V_105 ;
T_1 V_22 ;
if ( V_103 > V_25 )
return - V_107 ;
V_22 = F_71 ( V_96 -> V_108 ) ;
if ( ( V_103 < V_25 ) && ( V_22 << V_103 ) )
return - V_107 ;
V_41 = F_58 ( V_57 , & V_18 , V_22 ) ;
if ( ! V_41 )
return - V_181 ;
V_30 = F_61 ( & V_41 -> V_44 , V_42 , V_10 , 0 , V_94 -> V_11 ) ;
if ( ! V_30 )
return - V_181 ;
F_29 ( L_6 , V_22 , V_103 , V_10 , V_57 ) ;
V_180 = NULL ;
F_75 (fa, fa_list) {
struct V_8 * V_9 = V_30 -> V_87 ;
if ( ( V_30 -> V_43 != V_42 ) ||
( V_30 -> V_11 != V_94 -> V_11 ) ||
( V_30 -> V_86 != V_10 ) )
break;
if ( ( ! V_96 -> V_115 || V_30 -> V_114 == V_96 -> V_115 ) &&
( V_96 -> V_182 == V_183 ||
V_30 -> V_87 -> V_151 == V_96 -> V_182 ) &&
( ! V_96 -> V_184 ||
V_9 -> V_185 == V_96 -> V_184 ) &&
( ! V_96 -> V_186 ||
V_9 -> V_187 == V_96 -> V_186 ) &&
F_100 ( V_96 , V_9 ) == 0 ) {
V_180 = V_30 ;
break;
}
}
if ( ! V_180 )
return - V_181 ;
F_3 ( V_3 , V_188 , V_22 , V_103 ,
V_180 -> V_87 , V_10 ,
V_180 -> V_114 , V_94 -> V_11 ) ;
F_76 ( V_189 , F_77 ( V_22 ) , V_180 , V_103 , V_94 -> V_11 ,
& V_96 -> V_125 , 0 ) ;
if ( ! V_103 )
V_94 -> V_133 -- ;
F_94 ( V_57 , V_18 , V_41 , V_180 ) ;
if ( V_180 -> V_120 & V_121 )
F_80 ( V_96 -> V_125 . V_126 ) ;
F_79 ( V_180 -> V_87 ) ;
F_13 ( V_180 ) ;
return 0 ;
}
static struct V_15 * F_101 ( struct V_15 * * V_20 , T_3 V_22 )
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
if ( F_84 ( V_17 ) && ( V_17 -> V_22 >= V_22 ) )
goto V_142;
} while ( F_31 ( V_17 ) );
while ( ! F_37 ( V_82 ) ) {
if ( V_77 >= ( 1ul << V_82 -> V_21 ) ) {
T_3 V_146 = V_82 -> V_22 ;
V_82 = F_87 ( V_82 ) ;
V_77 = F_10 ( V_146 , V_82 ) + 1 ;
continue;
}
V_17 = F_59 ( V_82 , V_77 ++ ) ;
if ( ! V_17 )
continue;
if ( F_84 ( V_17 ) )
goto V_142;
V_82 = V_17 ;
V_77 = 0 ;
}
* V_20 = V_82 ;
return NULL ;
V_142:
* V_20 = V_82 ;
return V_17 ;
}
static void F_102 ( struct V_93 * V_94 )
{
struct V_56 * V_57 = (struct V_56 * ) V_94 -> V_99 ;
struct V_15 * V_82 = V_57 -> V_16 ;
unsigned long V_77 = 1 ;
struct V_178 * V_190 ;
struct V_29 * V_30 ;
for (; ; ) {
struct V_15 * V_17 ;
if ( ! ( V_77 -- ) ) {
T_3 V_146 = V_82 -> V_22 ;
if ( F_37 ( V_82 ) )
break;
V_17 = V_82 ;
V_82 = F_35 ( V_82 ) ;
F_36 ( V_82 , V_17 -> V_22 , NULL ) ;
F_41 ( V_17 ) ;
V_77 = F_10 ( V_146 , V_82 ) ;
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
F_103 (fa, tmp, &n->leaf, fa_list) {
F_97 ( & V_30 -> V_45 ) ;
F_13 ( V_30 ) ;
}
F_36 ( V_82 , V_17 -> V_22 , NULL ) ;
F_41 ( V_17 ) ;
}
#ifdef F_54
F_104 ( V_57 -> V_76 ) ;
#endif
F_105 ( V_94 ) ;
}
struct V_93 * F_106 ( struct V_93 * V_191 )
{
struct V_56 * V_192 = (struct V_56 * ) V_191 -> V_99 ;
struct V_15 * V_41 , * V_18 = V_192 -> V_16 ;
struct V_93 * V_193 ;
struct V_29 * V_30 ;
struct V_56 * V_194 ;
T_3 V_22 = 0 ;
if ( V_191 -> V_99 == V_191 -> V_195 )
return V_191 ;
V_193 = F_107 ( V_196 , NULL ) ;
if ( ! V_193 )
return NULL ;
V_194 = (struct V_56 * ) V_193 -> V_99 ;
while ( ( V_41 = F_101 ( & V_18 , V_22 ) ) != NULL ) {
struct V_15 * V_197 = NULL , * V_198 ;
F_88 (fa, &l->leaf, fa_list) {
struct V_29 * V_100 ;
if ( V_193 -> V_11 != V_30 -> V_11 )
continue;
V_100 = F_24 ( V_32 , V_38 ) ;
if ( ! V_100 )
goto V_113;
memcpy ( V_100 , V_30 , sizeof( * V_30 ) ) ;
if ( ! V_197 )
V_197 = F_58 ( V_194 , & V_198 , V_41 -> V_22 ) ;
if ( F_66 ( V_194 , V_198 , V_197 , V_100 ,
NULL , V_41 -> V_22 ) ) {
F_12 ( V_32 , V_100 ) ;
goto V_113;
}
}
V_22 = V_41 -> V_22 + 1 ;
if ( V_22 < V_41 -> V_22 )
break;
}
return V_193 ;
V_113:
F_102 ( V_193 ) ;
return NULL ;
}
void F_108 ( struct V_93 * V_94 )
{
struct V_56 * V_57 = (struct V_56 * ) V_94 -> V_99 ;
struct V_15 * V_82 = V_57 -> V_16 ;
unsigned long V_77 = 1 ;
struct V_178 * V_190 ;
struct V_29 * V_30 ;
for (; ; ) {
unsigned char V_42 = 0 ;
struct V_15 * V_17 ;
if ( ! ( V_77 -- ) ) {
T_3 V_146 = V_82 -> V_22 ;
if ( F_37 ( V_82 ) )
break;
if ( V_82 -> V_42 > V_82 -> V_26 )
F_49 ( V_82 ) ;
V_82 = F_45 ( V_57 , V_82 ) ;
V_77 = F_10 ( V_146 , V_82 ) ;
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
F_103 (fa, tmp, &n->leaf, fa_list) {
if ( V_94 -> V_11 != V_30 -> V_11 ) {
F_97 ( & V_30 -> V_45 ) ;
F_13 ( V_30 ) ;
continue;
}
V_42 = V_30 -> V_43 ;
}
V_17 -> V_42 = V_42 ;
if ( F_98 ( & V_17 -> V_44 ) ) {
F_36 ( V_82 , V_17 -> V_22 , NULL ) ;
F_41 ( V_17 ) ;
}
}
}
int F_109 ( struct V_3 * V_3 , struct V_93 * V_94 )
{
struct V_56 * V_57 = (struct V_56 * ) V_94 -> V_99 ;
struct V_15 * V_82 = V_57 -> V_16 ;
unsigned long V_77 = 1 ;
struct V_178 * V_190 ;
struct V_29 * V_30 ;
int V_142 = 0 ;
for (; ; ) {
unsigned char V_42 = 0 ;
struct V_15 * V_17 ;
if ( ! ( V_77 -- ) ) {
T_3 V_146 = V_82 -> V_22 ;
if ( F_37 ( V_82 ) )
break;
if ( V_82 -> V_42 > V_82 -> V_26 )
F_49 ( V_82 ) ;
V_82 = F_45 ( V_57 , V_82 ) ;
V_77 = F_10 ( V_146 , V_82 ) ;
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
F_103 (fa, tmp, &n->leaf, fa_list) {
struct V_8 * V_9 = V_30 -> V_87 ;
if ( ! V_9 || ! ( V_9 -> V_139 & V_155 ) ||
V_94 -> V_11 != V_30 -> V_11 ) {
V_42 = V_30 -> V_43 ;
continue;
}
F_3 ( V_3 , V_188 ,
V_17 -> V_22 ,
V_25 - V_30 -> V_43 ,
V_9 , V_30 -> V_86 , V_30 -> V_114 ,
V_94 -> V_11 ) ;
F_97 ( & V_30 -> V_45 ) ;
F_79 ( V_30 -> V_87 ) ;
F_13 ( V_30 ) ;
V_142 ++ ;
}
V_17 -> V_42 = V_42 ;
if ( F_98 ( & V_17 -> V_44 ) ) {
F_36 ( V_82 , V_17 -> V_22 , NULL ) ;
F_41 ( V_17 ) ;
}
}
F_29 ( L_7 , V_142 ) ;
return V_142 ;
}
static void F_110 ( struct V_3 * V_3 , struct V_15 * V_41 ,
struct V_93 * V_94 , struct V_1 * V_2 )
{
struct V_29 * V_30 ;
F_88 (fa, &l->leaf, fa_list) {
struct V_8 * V_9 = V_30 -> V_87 ;
if ( ! V_9 )
continue;
if ( V_94 -> V_11 != V_30 -> V_11 )
continue;
F_1 ( V_2 , V_3 , V_98 , V_41 -> V_22 ,
V_25 - V_30 -> V_43 , V_9 , V_30 -> V_86 ,
V_30 -> V_114 , V_30 -> V_11 ) ;
}
}
static void F_111 ( struct V_3 * V_3 , struct V_93 * V_94 ,
struct V_1 * V_2 )
{
struct V_56 * V_57 = (struct V_56 * ) V_94 -> V_99 ;
struct V_15 * V_41 , * V_18 = V_57 -> V_16 ;
T_3 V_22 = 0 ;
while ( ( V_41 = F_101 ( & V_18 , V_22 ) ) != NULL ) {
F_110 ( V_3 , V_41 , V_94 , V_2 ) ;
V_22 = V_41 -> V_22 + 1 ;
if ( V_22 < V_41 -> V_22 )
break;
}
}
void F_112 ( struct V_3 * V_3 , struct V_1 * V_2 )
{
unsigned int V_199 ;
for ( V_199 = 0 ; V_199 < V_200 ; V_199 ++ ) {
struct V_83 * V_28 = & V_3 -> V_201 . V_202 [ V_199 ] ;
struct V_93 * V_94 ;
F_88 (tb, head, tb_hlist)
F_111 ( V_3 , V_94 , V_2 ) ;
}
}
static void F_113 ( struct V_27 * V_28 )
{
struct V_93 * V_94 = F_6 ( V_28 , struct V_93 , V_31 ) ;
#ifdef F_54
struct V_56 * V_57 = (struct V_56 * ) V_94 -> V_99 ;
if ( V_94 -> V_99 == V_94 -> V_195 )
F_104 ( V_57 -> V_76 ) ;
#endif
F_105 ( V_94 ) ;
}
void F_114 ( struct V_93 * V_94 )
{
F_14 ( & V_94 -> V_31 , F_113 ) ;
}
static int F_115 ( struct V_15 * V_41 , struct V_93 * V_94 ,
struct V_203 * V_204 , struct V_205 * V_206 )
{
T_8 V_207 = F_77 ( V_41 -> V_22 ) ;
struct V_29 * V_30 ;
int V_47 , V_208 ;
V_208 = V_206 -> args [ 4 ] ;
V_47 = 0 ;
F_88 (fa, &l->leaf, fa_list) {
int V_106 ;
if ( V_47 < V_208 ) {
V_47 ++ ;
continue;
}
if ( V_94 -> V_11 != V_30 -> V_11 ) {
V_47 ++ ;
continue;
}
V_106 = F_116 ( V_204 , F_117 ( V_206 -> V_204 ) . V_209 ,
V_206 -> V_210 -> V_211 , V_124 ,
V_94 -> V_11 , V_30 -> V_114 ,
V_207 , V_25 - V_30 -> V_43 ,
V_30 -> V_86 , V_30 -> V_87 , V_212 ) ;
if ( V_106 < 0 ) {
V_206 -> args [ 4 ] = V_47 ;
return V_106 ;
}
V_47 ++ ;
}
V_206 -> args [ 4 ] = V_47 ;
return V_204 -> V_213 ;
}
int F_118 ( struct V_93 * V_94 , struct V_203 * V_204 ,
struct V_205 * V_206 )
{
struct V_56 * V_57 = (struct V_56 * ) V_94 -> V_99 ;
struct V_15 * V_41 , * V_18 = V_57 -> V_16 ;
int V_214 = V_206 -> args [ 2 ] ;
T_3 V_22 = V_206 -> args [ 3 ] ;
while ( ( V_41 = F_101 ( & V_18 , V_22 ) ) != NULL ) {
int V_106 ;
V_106 = F_115 ( V_41 , V_94 , V_204 , V_206 ) ;
if ( V_106 < 0 ) {
V_206 -> args [ 3 ] = V_22 ;
V_206 -> args [ 2 ] = V_214 ;
return V_106 ;
}
++ V_214 ;
V_22 = V_41 -> V_22 + 1 ;
memset ( & V_206 -> args [ 4 ] , 0 ,
sizeof( V_206 -> args ) - 4 * sizeof( V_206 -> args [ 0 ] ) ) ;
if ( V_22 < V_41 -> V_22 )
break;
}
V_206 -> args [ 3 ] = V_22 ;
V_206 -> args [ 2 ] = V_214 ;
return V_204 -> V_213 ;
}
void T_9 F_119 ( void )
{
V_32 = F_120 ( L_8 ,
sizeof( struct V_29 ) ,
0 , V_215 , NULL ) ;
V_34 = F_120 ( L_9 ,
V_216 ,
0 , V_215 , NULL ) ;
}
struct V_93 * F_107 ( T_1 V_217 , struct V_93 * V_218 )
{
struct V_93 * V_94 ;
struct V_56 * V_57 ;
T_4 V_219 = sizeof( * V_94 ) ;
if ( ! V_218 )
V_219 += sizeof( struct V_56 ) ;
V_94 = F_19 ( V_219 , V_38 ) ;
if ( ! V_94 )
return NULL ;
V_94 -> V_11 = V_217 ;
V_94 -> V_133 = 0 ;
V_94 -> V_99 = ( V_218 ? V_218 -> V_195 : V_94 -> V_195 ) ;
if ( V_218 )
return V_94 ;
V_57 = (struct V_56 * ) V_94 -> V_99 ;
V_57 -> V_16 [ 0 ] . V_26 = V_25 ;
V_57 -> V_16 [ 0 ] . V_42 = V_25 ;
#ifdef F_54
V_57 -> V_76 = F_121 ( struct V_75 ) ;
if ( ! V_57 -> V_76 ) {
F_105 ( V_94 ) ;
V_94 = NULL ;
}
#endif
return V_94 ;
}
static struct V_15 * F_122 ( struct V_220 * V_221 )
{
unsigned long V_77 = V_221 -> V_23 ;
struct V_15 * V_82 = V_221 -> V_14 ;
T_3 V_146 ;
F_29 ( L_10 ,
V_221 -> V_14 , V_221 -> V_23 , V_221 -> V_222 ) ;
while ( ! F_37 ( V_82 ) ) {
while ( V_77 < F_9 ( V_82 ) ) {
struct V_15 * V_17 = F_59 ( V_82 , V_77 ++ ) ;
if ( ! V_17 )
continue;
if ( F_84 ( V_17 ) ) {
V_221 -> V_14 = V_82 ;
V_221 -> V_23 = V_77 ;
} else {
V_221 -> V_14 = V_17 ;
V_221 -> V_23 = 0 ;
++ V_221 -> V_222 ;
}
return V_17 ;
}
V_146 = V_82 -> V_22 ;
V_82 = F_87 ( V_82 ) ;
V_77 = F_10 ( V_146 , V_82 ) + 1 ;
-- V_221 -> V_222 ;
}
V_221 -> V_14 = V_82 ;
V_221 -> V_23 = 0 ;
return NULL ;
}
static struct V_15 * F_123 ( struct V_220 * V_221 ,
struct V_56 * V_57 )
{
struct V_15 * V_17 , * V_82 ;
if ( ! V_57 )
return NULL ;
V_82 = V_57 -> V_16 ;
V_17 = F_86 ( V_82 -> V_14 [ 0 ] ) ;
if ( ! V_17 )
return NULL ;
if ( F_31 ( V_17 ) ) {
V_221 -> V_14 = V_17 ;
V_221 -> V_23 = 0 ;
V_221 -> V_222 = 1 ;
} else {
V_221 -> V_14 = V_82 ;
V_221 -> V_23 = 0 ;
V_221 -> V_222 = 0 ;
}
return V_17 ;
}
static void F_124 ( struct V_56 * V_57 , struct V_223 * V_224 )
{
struct V_15 * V_17 ;
struct V_220 V_221 ;
memset ( V_224 , 0 , sizeof( * V_224 ) ) ;
F_125 () ;
for ( V_17 = F_123 ( & V_221 , V_57 ) ; V_17 ; V_17 = F_122 ( & V_221 ) ) {
if ( F_84 ( V_17 ) ) {
struct V_29 * V_30 ;
V_224 -> V_225 ++ ;
V_224 -> V_226 += V_221 . V_222 ;
if ( V_221 . V_222 > V_224 -> V_227 )
V_224 -> V_227 = V_221 . V_222 ;
F_88 ( V_30 , & V_17 -> V_44 , V_45 )
++ V_224 -> V_228 ;
} else {
V_224 -> V_229 ++ ;
if ( V_17 -> V_21 < V_230 )
V_224 -> V_231 [ V_17 -> V_21 ] ++ ;
V_224 -> V_232 += F_5 ( V_17 ) -> V_39 ;
}
}
F_126 () ;
}
static void F_127 ( struct V_233 * V_234 , struct V_223 * V_235 )
{
unsigned int V_47 , V_236 , V_237 , V_238 , V_239 ;
if ( V_235 -> V_225 )
V_239 = V_235 -> V_226 * 100 / V_235 -> V_225 ;
else
V_239 = 0 ;
F_128 ( V_234 , L_11 ,
V_239 / 100 , V_239 % 100 ) ;
F_128 ( V_234 , L_12 , V_235 -> V_227 ) ;
F_128 ( V_234 , L_13 , V_235 -> V_225 ) ;
V_238 = V_216 * V_235 -> V_225 ;
F_128 ( V_234 , L_14 , V_235 -> V_228 ) ;
V_238 += sizeof( struct V_29 ) * V_235 -> V_228 ;
F_128 ( V_234 , L_15 , V_235 -> V_229 ) ;
V_238 += F_18 ( 0 ) * V_235 -> V_229 ;
V_236 = V_230 ;
while ( V_236 > 0 && V_235 -> V_231 [ V_236 - 1 ] == 0 )
V_236 -- ;
V_237 = 0 ;
for ( V_47 = 1 ; V_47 < V_236 ; V_47 ++ )
if ( V_235 -> V_231 [ V_47 ] != 0 ) {
F_128 ( V_234 , L_16 , V_47 , V_235 -> V_231 [ V_47 ] ) ;
V_237 += ( 1 << V_47 ) * V_235 -> V_231 [ V_47 ] ;
}
F_129 ( V_234 , '\n' ) ;
F_128 ( V_234 , L_17 , V_237 ) ;
V_238 += sizeof( struct V_15 * ) * V_237 ;
F_128 ( V_234 , L_18 , V_235 -> V_232 ) ;
F_128 ( V_234 , L_19 , ( V_238 + 1023 ) / 1024 ) ;
}
static void F_130 ( struct V_233 * V_234 ,
const struct V_75 T_5 * V_76 )
{
struct V_75 V_224 = { 0 } ;
int V_240 ;
F_131 (cpu) {
const struct V_75 * V_241 = F_132 ( V_76 , V_240 ) ;
V_224 . gets += V_241 -> gets ;
V_224 . V_147 += V_241 -> V_147 ;
V_224 . V_154 += V_241 -> V_154 ;
V_224 . V_176 += V_241 -> V_176 ;
V_224 . V_145 += V_241 -> V_145 ;
V_224 . V_80 += V_241 -> V_80 ;
}
F_128 ( V_234 , L_20 ) ;
F_128 ( V_234 , L_21 , V_224 . gets ) ;
F_128 ( V_234 , L_22 , V_224 . V_147 ) ;
F_128 ( V_234 , L_23 ,
V_224 . V_154 ) ;
F_128 ( V_234 , L_24 , V_224 . V_176 ) ;
F_128 ( V_234 , L_25 , V_224 . V_145 ) ;
F_128 ( V_234 , L_26 , V_224 . V_80 ) ;
}
static void F_133 ( struct V_233 * V_234 , struct V_93 * V_94 )
{
if ( V_94 -> V_11 == V_196 )
F_134 ( V_234 , L_27 ) ;
else if ( V_94 -> V_11 == V_242 )
F_134 ( V_234 , L_28 ) ;
else
F_128 ( V_234 , L_29 , V_94 -> V_11 ) ;
}
static int F_135 ( struct V_233 * V_234 , void * V_243 )
{
struct V_3 * V_3 = (struct V_3 * ) V_234 -> V_244 ;
unsigned int V_199 ;
F_128 ( V_234 ,
L_30
L_31 ,
V_216 , F_18 ( 0 ) ) ;
for ( V_199 = 0 ; V_199 < V_200 ; V_199 ++ ) {
struct V_83 * V_28 = & V_3 -> V_201 . V_202 [ V_199 ] ;
struct V_93 * V_94 ;
F_88 (tb, head, tb_hlist) {
struct V_56 * V_57 = (struct V_56 * ) V_94 -> V_99 ;
struct V_223 V_235 ;
if ( ! V_57 )
continue;
F_133 ( V_234 , V_94 ) ;
F_124 ( V_57 , & V_235 ) ;
F_127 ( V_234 , & V_235 ) ;
#ifdef F_54
F_130 ( V_234 , V_57 -> V_76 ) ;
#endif
}
}
return 0 ;
}
static int F_136 ( struct V_51 * V_51 , struct V_245 * V_245 )
{
return F_137 ( V_51 , V_245 , F_135 ) ;
}
static struct V_15 * F_138 ( struct V_233 * V_234 , T_10 V_26 )
{
struct V_220 * V_221 = V_234 -> V_244 ;
struct V_3 * V_3 = F_139 ( V_234 ) ;
T_10 V_246 = 0 ;
unsigned int V_199 ;
for ( V_199 = 0 ; V_199 < V_200 ; V_199 ++ ) {
struct V_83 * V_28 = & V_3 -> V_201 . V_202 [ V_199 ] ;
struct V_93 * V_94 ;
F_88 (tb, head, tb_hlist) {
struct V_15 * V_17 ;
for ( V_17 = F_123 ( V_221 ,
(struct V_56 * ) V_94 -> V_99 ) ;
V_17 ; V_17 = F_122 ( V_221 ) )
if ( V_26 == V_246 ++ ) {
V_221 -> V_94 = V_94 ;
return V_17 ;
}
}
}
return NULL ;
}
static void * F_140 ( struct V_233 * V_234 , T_10 * V_26 )
__acquires( T_11 )
{
F_125 () ;
return F_138 ( V_234 , * V_26 ) ;
}
static void * F_141 ( struct V_233 * V_234 , void * V_243 , T_10 * V_26 )
{
struct V_220 * V_221 = V_234 -> V_244 ;
struct V_3 * V_3 = F_139 ( V_234 ) ;
struct V_93 * V_94 = V_221 -> V_94 ;
struct V_178 * V_247 ;
unsigned int V_199 ;
struct V_15 * V_17 ;
++ * V_26 ;
V_17 = F_122 ( V_221 ) ;
if ( V_17 )
return V_17 ;
V_199 = V_94 -> V_11 & ( V_200 - 1 ) ;
while ( ( V_247 = F_86 ( F_142 ( & V_94 -> V_248 ) ) ) ) {
V_94 = F_95 ( V_247 , struct V_93 , V_248 ) ;
V_17 = F_123 ( V_221 , (struct V_56 * ) V_94 -> V_99 ) ;
if ( V_17 )
goto V_142;
}
while ( ++ V_199 < V_200 ) {
struct V_83 * V_28 = & V_3 -> V_201 . V_202 [ V_199 ] ;
F_88 (tb, head, tb_hlist) {
V_17 = F_123 ( V_221 , (struct V_56 * ) V_94 -> V_99 ) ;
if ( V_17 )
goto V_142;
}
}
return NULL ;
V_142:
V_221 -> V_94 = V_94 ;
return V_17 ;
}
static void F_143 ( struct V_233 * V_234 , void * V_243 )
__releases( T_11 )
{
F_126 () ;
}
static void F_144 ( struct V_233 * V_234 , int V_17 )
{
while ( V_17 -- > 0 )
F_134 ( V_234 , L_32 ) ;
}
static inline const char * F_145 ( char * V_249 , T_4 V_213 , enum V_250 V_224 )
{
switch ( V_224 ) {
case V_251 : return L_33 ;
case V_252 : return L_34 ;
case V_253 : return L_35 ;
case V_254 : return L_36 ;
case V_183 : return L_37 ;
default:
snprintf ( V_249 , V_213 , L_38 , V_224 ) ;
return V_249 ;
}
}
static inline const char * F_146 ( char * V_249 , T_4 V_213 , unsigned int V_57 )
{
if ( V_57 < V_255 && V_256 [ V_57 ] )
return V_256 [ V_57 ] ;
snprintf ( V_249 , V_213 , L_39 , V_57 ) ;
return V_249 ;
}
static int F_147 ( struct V_233 * V_234 , void * V_243 )
{
const struct V_220 * V_221 = V_234 -> V_244 ;
struct V_15 * V_17 = V_243 ;
if ( F_37 ( F_87 ( V_17 ) ) )
F_133 ( V_234 , V_221 -> V_94 ) ;
if ( F_31 ( V_17 ) ) {
T_8 V_257 = F_77 ( V_17 -> V_22 ) ;
F_144 ( V_234 , V_221 -> V_222 - 1 ) ;
F_128 ( V_234 , L_40 ,
& V_257 , V_25 - V_17 -> V_26 - V_17 -> V_21 , V_17 -> V_21 ,
F_5 ( V_17 ) -> V_40 ,
F_5 ( V_17 ) -> V_39 ) ;
} else {
T_8 V_258 = F_77 ( V_17 -> V_22 ) ;
struct V_29 * V_30 ;
F_144 ( V_234 , V_221 -> V_222 ) ;
F_128 ( V_234 , L_41 , & V_258 ) ;
F_88 (fa, &n->leaf, fa_list) {
char V_259 [ 32 ] , V_260 [ 32 ] ;
F_144 ( V_234 , V_221 -> V_222 + 1 ) ;
F_128 ( V_234 , L_42 ,
V_25 - V_30 -> V_43 ,
F_145 ( V_259 , sizeof( V_259 ) ,
V_30 -> V_87 -> V_151 ) ,
F_146 ( V_260 , sizeof( V_260 ) ,
V_30 -> V_114 ) ) ;
if ( V_30 -> V_86 )
F_128 ( V_234 , L_43 , V_30 -> V_86 ) ;
F_129 ( V_234 , '\n' ) ;
}
}
return 0 ;
}
static int F_148 ( struct V_51 * V_51 , struct V_245 * V_245 )
{
return F_149 ( V_51 , V_245 , & V_261 ,
sizeof( struct V_220 ) ) ;
}
static struct V_15 * F_150 ( struct V_262 * V_221 ,
T_10 V_26 )
{
struct V_15 * V_41 , * * V_18 = & V_221 -> V_14 ;
T_3 V_22 ;
if ( V_221 -> V_26 > 0 && V_26 >= V_221 -> V_26 ) {
V_22 = V_221 -> V_22 ;
} else {
V_221 -> V_26 = 1 ;
V_22 = 0 ;
}
V_26 -= V_221 -> V_26 ;
while ( ( V_41 = F_101 ( V_18 , V_22 ) ) && ( V_26 -- > 0 ) ) {
V_22 = V_41 -> V_22 + 1 ;
V_221 -> V_26 ++ ;
V_41 = NULL ;
if ( ! V_22 )
break;
}
if ( V_41 )
V_221 -> V_22 = V_41 -> V_22 ;
else
V_221 -> V_26 = 0 ;
return V_41 ;
}
static void * F_151 ( struct V_233 * V_234 , T_10 * V_26 )
__acquires( T_11 )
{
struct V_262 * V_221 = V_234 -> V_244 ;
struct V_93 * V_94 ;
struct V_56 * V_57 ;
F_125 () ;
V_94 = F_152 ( F_139 ( V_234 ) , V_242 ) ;
if ( ! V_94 )
return NULL ;
V_221 -> V_263 = V_94 ;
V_57 = (struct V_56 * ) V_94 -> V_99 ;
V_221 -> V_14 = V_57 -> V_16 ;
if ( * V_26 != 0 )
return F_150 ( V_221 , * V_26 ) ;
V_221 -> V_26 = 0 ;
V_221 -> V_22 = V_74 ;
return V_264 ;
}
static void * F_153 ( struct V_233 * V_234 , void * V_243 , T_10 * V_26 )
{
struct V_262 * V_221 = V_234 -> V_244 ;
struct V_15 * V_41 = NULL ;
T_3 V_22 = V_221 -> V_22 + 1 ;
++ * V_26 ;
if ( ( V_243 == V_264 ) || V_22 )
V_41 = F_101 ( & V_221 -> V_14 , V_22 ) ;
if ( V_41 ) {
V_221 -> V_22 = V_41 -> V_22 ;
V_221 -> V_26 ++ ;
} else {
V_221 -> V_26 = 0 ;
}
return V_41 ;
}
static void F_154 ( struct V_233 * V_234 , void * V_243 )
__releases( T_11 )
{
F_126 () ;
}
static unsigned int F_155 ( int type , T_8 V_265 , const struct V_8 * V_9 )
{
unsigned int V_266 = 0 ;
if ( type == V_267 || type == V_268 )
V_266 = V_269 ;
if ( V_9 && V_9 -> V_157 -> V_270 )
V_266 |= V_271 ;
if ( V_265 == F_77 ( 0xFFFFFFFF ) )
V_266 |= V_272 ;
V_266 |= V_273 ;
return V_266 ;
}
static int F_156 ( struct V_233 * V_234 , void * V_243 )
{
struct V_262 * V_221 = V_234 -> V_244 ;
struct V_93 * V_94 = V_221 -> V_263 ;
struct V_29 * V_30 ;
struct V_15 * V_41 = V_243 ;
T_8 V_134 ;
if ( V_243 == V_264 ) {
F_128 ( V_234 , L_44 , L_45
L_46
L_47 ) ;
return 0 ;
}
V_134 = F_77 ( V_41 -> V_22 ) ;
F_88 (fa, &l->leaf, fa_list) {
const struct V_8 * V_9 = V_30 -> V_87 ;
T_8 V_265 = F_157 ( V_25 - V_30 -> V_43 ) ;
unsigned int V_266 = F_155 ( V_30 -> V_114 , V_265 , V_9 ) ;
if ( ( V_30 -> V_114 == V_274 ) ||
( V_30 -> V_114 == V_275 ) )
continue;
if ( V_30 -> V_11 != V_94 -> V_11 )
continue;
F_158 ( V_234 , 127 ) ;
if ( V_9 )
F_128 ( V_234 ,
L_48
L_49 ,
V_9 -> V_276 ? V_9 -> V_276 -> V_277 : L_50 ,
V_134 ,
V_9 -> V_157 -> V_270 , V_266 , 0 , 0 ,
V_9 -> V_88 ,
V_265 ,
( V_9 -> V_278 ?
V_9 -> V_278 + 40 : 0 ) ,
V_9 -> V_279 ,
V_9 -> V_280 >> 3 ) ;
else
F_128 ( V_234 ,
L_51
L_49 ,
V_134 , 0 , V_266 , 0 , 0 , 0 ,
V_265 , 0 , 0 , 0 ) ;
F_159 ( V_234 , '\n' ) ;
}
return 0 ;
}
static int F_160 ( struct V_51 * V_51 , struct V_245 * V_245 )
{
return F_149 ( V_51 , V_245 , & V_281 ,
sizeof( struct V_262 ) ) ;
}
int T_12 F_161 ( struct V_3 * V_3 )
{
if ( ! F_162 ( L_52 , V_282 , V_3 -> V_283 , & V_284 ) )
goto V_285;
if ( ! F_162 ( L_53 , V_282 , V_3 -> V_283 ,
& V_286 ) )
goto V_287;
if ( ! F_162 ( L_54 , V_282 , V_3 -> V_283 , & V_288 ) )
goto V_289;
return 0 ;
V_289:
F_163 ( L_53 , V_3 -> V_283 ) ;
V_287:
F_163 ( L_52 , V_3 -> V_283 ) ;
V_285:
return - V_91 ;
}
void T_13 F_164 ( struct V_3 * V_3 )
{
F_163 ( L_52 , V_3 -> V_283 ) ;
F_163 ( L_53 , V_3 -> V_283 ) ;
F_163 ( L_54 , V_3 -> V_283 ) ;
}
