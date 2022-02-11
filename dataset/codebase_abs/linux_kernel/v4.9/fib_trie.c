int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
return F_4 ( & V_3 , V_2 ) ;
}
int F_5 ( struct V_4 * V_4 , enum V_5 V_6 ,
struct V_7 * V_8 )
{
V_8 -> V_4 = V_4 ;
return F_6 ( & V_3 , V_6 , V_8 ) ;
}
static int F_7 ( struct V_4 * V_4 ,
enum V_5 V_6 , T_1 V_9 ,
int V_10 , struct V_11 * V_12 ,
T_2 V_13 , T_2 type , T_1 V_14 , T_1 V_15 )
{
struct V_16 V_8 = {
. V_9 = V_9 ,
. V_10 = V_10 ,
. V_12 = V_12 ,
. V_13 = V_13 ,
. type = type ,
. V_14 = V_14 ,
. V_15 = V_15 ,
} ;
return F_5 ( V_4 , V_6 , & V_8 . V_8 ) ;
}
static inline struct V_17 * F_8 ( struct V_18 * V_19 )
{
return F_9 ( V_19 , struct V_17 , V_19 [ 0 ] ) ;
}
static inline void F_10 ( struct V_18 * V_20 , struct V_18 * V_21 )
{
if ( V_20 )
F_11 ( F_8 ( V_20 ) -> V_22 , V_21 ) ;
}
static inline unsigned long F_12 ( const struct V_18 * V_23 )
{
return ( 1ul << V_23 -> V_24 ) & ~ ( 1ul ) ;
}
static inline unsigned long F_13 ( T_3 V_25 , struct V_18 * V_19 )
{
unsigned long V_26 = V_25 ^ V_19 -> V_25 ;
if ( ( V_27 <= V_28 ) && ( V_28 == V_19 -> V_29 ) )
return 0 ;
return V_26 >> V_19 -> V_29 ;
}
static void F_14 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = F_9 ( V_31 , struct V_32 , V_34 ) ;
F_15 ( V_35 , V_33 ) ;
}
static inline void F_16 ( struct V_32 * V_33 )
{
F_17 ( & V_33 -> V_34 , F_14 ) ;
}
static void F_18 ( struct V_30 * V_31 )
{
struct V_17 * V_20 = F_9 ( V_31 , struct V_17 , V_34 ) ;
if ( ! V_20 -> V_36 )
F_15 ( V_37 , V_20 ) ;
else
F_19 ( V_20 ) ;
}
static struct V_17 * F_20 ( int V_24 )
{
T_4 V_38 ;
if ( V_24 > V_39 )
return NULL ;
V_38 = F_21 ( 1ul << V_24 ) ;
if ( V_38 <= V_40 )
return F_22 ( V_38 , V_41 ) ;
else
return F_23 ( V_38 ) ;
}
static inline void F_24 ( struct V_18 * V_20 )
{
++ F_8 ( V_20 ) -> V_42 ? : ++ F_8 ( V_20 ) -> V_43 ;
}
static inline void F_25 ( struct V_18 * V_20 )
{
F_8 ( V_20 ) -> V_42 -- ? : F_8 ( V_20 ) -> V_43 -- ;
}
static struct V_18 * F_26 ( T_3 V_25 , struct V_32 * V_33 )
{
struct V_18 * V_44 ;
struct V_17 * V_19 ;
V_19 = F_27 ( V_37 , V_41 ) ;
if ( ! V_19 )
return NULL ;
V_44 = V_19 -> V_19 ;
V_44 -> V_25 = V_25 ;
V_44 -> V_29 = 0 ;
V_44 -> V_24 = 0 ;
V_44 -> V_45 = V_33 -> V_46 ;
F_28 ( & V_44 -> V_47 ) ;
F_29 ( & V_33 -> V_48 , & V_44 -> V_47 ) ;
return V_44 ;
}
static struct V_18 * F_30 ( T_3 V_25 , int V_29 , int V_24 )
{
unsigned int V_49 = V_29 + V_24 ;
struct V_18 * V_23 ;
struct V_17 * V_17 ;
F_31 ( ! V_24 || ( V_49 > V_28 ) ) ;
V_17 = F_20 ( V_24 ) ;
if ( ! V_17 )
return NULL ;
F_32 ( L_1 , V_17 , F_21 ( 0 ) ,
sizeof( struct V_18 * ) << V_24 ) ;
if ( V_24 == V_28 )
V_17 -> V_43 = 1 ;
else
V_17 -> V_42 = 1ul << V_24 ;
V_23 = V_17 -> V_19 ;
V_23 -> V_25 = ( V_49 < V_28 ) ? ( V_25 >> V_49 ) << V_49 : 0 ;
V_23 -> V_29 = V_29 ;
V_23 -> V_24 = V_24 ;
V_23 -> V_45 = V_29 ;
return V_23 ;
}
static inline int F_33 ( struct V_18 * V_23 , struct V_18 * V_20 )
{
return V_20 && ( ( V_20 -> V_29 + V_20 -> V_24 ) == V_23 -> V_29 ) && F_34 ( V_20 ) ;
}
static void F_35 ( struct V_18 * V_23 , unsigned long V_50 ,
struct V_18 * V_20 )
{
struct V_18 * V_51 = F_36 ( V_23 , V_50 ) ;
int V_52 , V_53 ;
F_31 ( V_50 >= F_12 ( V_23 ) ) ;
if ( ! V_20 && V_51 )
F_24 ( V_23 ) ;
if ( V_20 && ! V_51 )
F_25 ( V_23 ) ;
V_53 = F_33 ( V_23 , V_51 ) ;
V_52 = F_33 ( V_23 , V_20 ) ;
if ( V_53 && ! V_52 )
F_8 ( V_23 ) -> V_43 -- ;
else if ( ! V_53 && V_52 )
F_8 ( V_23 ) -> V_43 ++ ;
if ( V_20 && ( V_23 -> V_45 < V_20 -> V_45 ) )
V_23 -> V_45 = V_20 -> V_45 ;
F_11 ( V_23 -> V_17 [ V_50 ] , V_20 ) ;
}
static void F_37 ( struct V_18 * V_23 )
{
unsigned long V_50 ;
for ( V_50 = F_12 ( V_23 ) ; V_50 ; ) {
struct V_18 * V_54 = F_36 ( V_23 , -- V_50 ) ;
if ( ! V_54 )
continue;
if ( F_38 ( V_54 ) == V_23 )
F_37 ( V_54 ) ;
else
F_10 ( V_54 , V_23 ) ;
}
}
static inline void F_39 ( struct V_18 * V_21 , T_3 V_25 ,
struct V_18 * V_20 )
{
if ( F_40 ( V_21 ) )
F_11 ( V_21 -> V_17 [ 0 ] , V_20 ) ;
else
F_35 ( V_21 , F_13 ( V_25 , V_21 ) , V_20 ) ;
}
static inline void F_41 ( struct V_18 * V_23 )
{
F_8 ( V_23 ) -> V_34 . V_55 = NULL ;
}
static inline void F_42 ( struct V_18 * V_23 ,
struct V_18 * V_20 )
{
F_8 ( V_20 ) -> V_34 . V_55 = F_8 ( V_23 ) -> V_34 . V_55 ;
F_8 ( V_23 ) -> V_34 . V_55 = & F_8 ( V_20 ) -> V_34 ;
}
static void F_43 ( struct V_18 * V_23 )
{
struct V_56 * V_31 = & F_8 ( V_23 ) -> V_34 ;
while ( V_31 ) {
V_31 = V_31 -> V_55 ;
V_57 += F_21 ( 1ul << V_23 -> V_24 ) ;
F_44 ( V_23 ) ;
V_23 = F_9 ( V_31 , struct V_17 , V_34 ) -> V_19 ;
}
if ( V_57 >= V_40 * V_58 ) {
V_57 = 0 ;
F_45 () ;
}
}
static struct V_18 * F_46 ( struct V_59 * V_60 ,
struct V_18 * V_61 ,
struct V_18 * V_23 )
{
struct V_18 * V_21 = F_38 ( V_61 ) ;
unsigned long V_50 ;
F_47 ( V_23 , V_21 ) ;
F_39 ( V_21 , V_23 -> V_25 , V_23 ) ;
F_37 ( V_23 ) ;
F_43 ( V_61 ) ;
for ( V_50 = F_12 ( V_23 ) ; V_50 ; ) {
struct V_18 * V_54 = F_36 ( V_23 , -- V_50 ) ;
if ( F_33 ( V_23 , V_54 ) )
V_23 = F_48 ( V_60 , V_54 ) ;
}
return V_21 ;
}
static struct V_18 * F_49 ( struct V_59 * V_60 ,
struct V_18 * V_61 )
{
struct V_18 * V_23 ;
unsigned long V_50 ;
T_3 V_62 ;
F_32 ( L_2 ) ;
V_23 = F_30 ( V_61 -> V_25 , V_61 -> V_29 - 1 , V_61 -> V_24 + 1 ) ;
if ( ! V_23 )
goto V_63;
F_41 ( V_61 ) ;
for ( V_50 = F_12 ( V_61 ) , V_62 = 1u << V_23 -> V_29 ; V_50 ; ) {
struct V_18 * V_54 = F_36 ( V_61 , -- V_50 ) ;
struct V_18 * V_64 , * V_65 ;
unsigned long V_66 , V_67 ;
if ( ! V_54 )
continue;
if ( ! F_33 ( V_61 , V_54 ) ) {
F_35 ( V_23 , F_13 ( V_54 -> V_25 , V_23 ) , V_54 ) ;
continue;
}
F_42 ( V_61 , V_54 ) ;
if ( V_54 -> V_24 == 1 ) {
F_35 ( V_23 , 2 * V_50 + 1 , F_36 ( V_54 , 1 ) ) ;
F_35 ( V_23 , 2 * V_50 , F_36 ( V_54 , 0 ) ) ;
continue;
}
V_65 = F_30 ( V_54 -> V_25 | V_62 , V_54 -> V_29 , V_54 -> V_24 - 1 ) ;
if ( ! V_65 )
goto V_68;
V_64 = F_30 ( V_54 -> V_25 , V_54 -> V_29 , V_54 -> V_24 - 1 ) ;
F_42 ( V_23 , V_65 ) ;
if ( ! V_64 )
goto V_68;
F_42 ( V_23 , V_64 ) ;
for ( V_67 = F_12 ( V_54 ) , V_66 = V_67 / 2 ; V_66 ; ) {
F_35 ( V_65 , -- V_66 , F_36 ( V_54 , -- V_67 ) ) ;
F_35 ( V_64 , V_66 , F_36 ( V_54 , V_66 ) ) ;
F_35 ( V_65 , -- V_66 , F_36 ( V_54 , -- V_67 ) ) ;
F_35 ( V_64 , V_66 , F_36 ( V_54 , V_66 ) ) ;
}
F_47 ( V_65 , V_23 ) ;
F_47 ( V_64 , V_23 ) ;
F_35 ( V_23 , 2 * V_50 + 1 , V_65 ) ;
F_35 ( V_23 , 2 * V_50 , V_64 ) ;
}
return F_46 ( V_60 , V_61 , V_23 ) ;
V_68:
F_43 ( V_23 ) ;
V_63:
return NULL ;
}
static struct V_18 * F_50 ( struct V_59 * V_60 ,
struct V_18 * V_61 )
{
struct V_18 * V_23 ;
unsigned long V_50 ;
F_32 ( L_3 ) ;
V_23 = F_30 ( V_61 -> V_25 , V_61 -> V_29 + 1 , V_61 -> V_24 - 1 ) ;
if ( ! V_23 )
goto V_63;
F_41 ( V_61 ) ;
for ( V_50 = F_12 ( V_61 ) ; V_50 ; ) {
struct V_18 * V_65 = F_36 ( V_61 , -- V_50 ) ;
struct V_18 * V_64 = F_36 ( V_61 , -- V_50 ) ;
struct V_18 * V_54 ;
if ( ! V_65 || ! V_64 ) {
F_35 ( V_23 , V_50 / 2 , V_65 ? : V_64 ) ;
continue;
}
V_54 = F_30 ( V_64 -> V_25 , V_61 -> V_29 , 1 ) ;
if ( ! V_54 )
goto V_68;
F_42 ( V_23 , V_54 ) ;
F_35 ( V_54 , 1 , V_65 ) ;
F_35 ( V_54 , 0 , V_64 ) ;
F_47 ( V_54 , V_23 ) ;
F_35 ( V_23 , V_50 / 2 , V_54 ) ;
}
return F_46 ( V_60 , V_61 , V_23 ) ;
V_68:
F_43 ( V_23 ) ;
V_63:
return NULL ;
}
static struct V_18 * F_51 ( struct V_59 * V_60 ,
struct V_18 * V_61 )
{
struct V_18 * V_20 , * V_21 ;
unsigned long V_50 ;
for ( V_20 = NULL , V_50 = F_12 ( V_61 ) ; ! V_20 && V_50 ; )
V_20 = F_36 ( V_61 , -- V_50 ) ;
V_21 = F_38 ( V_61 ) ;
F_39 ( V_21 , V_61 -> V_25 , V_20 ) ;
F_10 ( V_20 , V_21 ) ;
F_44 ( V_61 ) ;
return V_21 ;
}
static unsigned char F_52 ( struct V_18 * V_23 )
{
unsigned char V_45 = V_23 -> V_29 ;
unsigned long V_69 , V_50 ;
unsigned char V_70 ;
V_70 = F_53 (unsigned char, tn->pos + tn->bits - 1 , tn->slen) ;
for ( V_50 = 0 , V_69 = 0x2ul ; V_50 < F_12 ( V_23 ) ; V_50 += V_69 ) {
struct V_18 * V_20 = F_36 ( V_23 , V_50 ) ;
if ( ! V_20 || ( V_20 -> V_45 <= V_45 ) )
continue;
V_69 <<= ( V_20 -> V_45 - V_45 ) ;
V_45 = V_20 -> V_45 ;
V_50 &= ~ ( V_69 - 1 ) ;
if ( V_45 >= V_70 )
break;
}
V_23 -> V_45 = V_45 ;
return V_45 ;
}
static inline bool F_54 ( struct V_18 * V_21 , struct V_18 * V_23 )
{
unsigned long V_71 = F_12 ( V_23 ) ;
unsigned long V_72 = V_71 ;
V_72 *= F_40 ( V_21 ) ? V_73 : V_74 ;
V_71 -= F_8 ( V_23 ) -> V_42 ;
V_71 += F_8 ( V_23 ) -> V_43 ;
return ( V_71 > 1 ) && V_23 -> V_29 && ( ( 50 * V_71 ) >= V_72 ) ;
}
static inline bool F_55 ( struct V_18 * V_21 , struct V_18 * V_23 )
{
unsigned long V_71 = F_12 ( V_23 ) ;
unsigned long V_72 = V_71 ;
V_72 *= F_40 ( V_21 ) ? V_75 : V_76 ;
V_71 -= F_8 ( V_23 ) -> V_42 ;
return ( V_71 > 1 ) && ( V_23 -> V_24 > 1 ) && ( ( 100 * V_71 ) < V_72 ) ;
}
static inline bool F_56 ( struct V_18 * V_23 )
{
unsigned long V_71 = F_12 ( V_23 ) ;
V_71 -= F_8 ( V_23 ) -> V_42 ;
if ( ( V_23 -> V_24 == V_28 ) && F_8 ( V_23 ) -> V_43 )
V_71 -= V_77 ;
return V_71 < 2 ;
}
static struct V_18 * F_48 ( struct V_59 * V_60 , struct V_18 * V_23 )
{
#ifdef F_57
struct V_78 T_5 * V_79 = V_60 -> V_79 ;
#endif
struct V_18 * V_21 = F_38 ( V_23 ) ;
unsigned long V_80 = F_13 ( V_23 -> V_25 , V_21 ) ;
int V_81 = V_82 ;
F_32 ( L_4 ,
V_23 , V_74 , V_76 ) ;
F_31 ( V_23 != F_36 ( V_21 , V_80 ) ) ;
while ( F_54 ( V_21 , V_23 ) && V_81 ) {
V_21 = F_49 ( V_60 , V_23 ) ;
if ( ! V_21 ) {
#ifdef F_57
F_58 ( V_79 -> V_83 ) ;
#endif
break;
}
V_81 -- ;
V_23 = F_36 ( V_21 , V_80 ) ;
}
V_21 = F_38 ( V_23 ) ;
if ( V_81 != V_82 )
return V_21 ;
while ( F_55 ( V_21 , V_23 ) && V_81 ) {
V_21 = F_50 ( V_60 , V_23 ) ;
if ( ! V_21 ) {
#ifdef F_57
F_58 ( V_79 -> V_83 ) ;
#endif
break;
}
V_81 -- ;
V_23 = F_36 ( V_21 , V_80 ) ;
}
if ( F_56 ( V_23 ) )
return F_51 ( V_60 , V_23 ) ;
return F_38 ( V_23 ) ;
}
static void F_59 ( struct V_18 * V_23 , unsigned char V_45 )
{
unsigned char V_84 = V_23 -> V_45 ;
while ( ( V_84 > V_23 -> V_29 ) && ( V_84 > V_45 ) ) {
V_45 = F_52 ( V_23 ) ;
if ( V_84 == V_45 )
break;
V_23 = F_38 ( V_23 ) ;
V_84 = V_23 -> V_45 ;
}
}
static void F_60 ( struct V_18 * V_23 , unsigned char V_45 )
{
while ( V_23 -> V_45 < V_45 ) {
V_23 -> V_45 = V_45 ;
V_23 = F_38 ( V_23 ) ;
}
}
static struct V_18 * F_61 ( struct V_59 * V_60 ,
struct V_18 * * V_21 , T_1 V_25 )
{
struct V_18 * V_85 , * V_20 = V_60 -> V_19 ;
unsigned long V_26 = 0 ;
do {
V_85 = V_20 ;
V_20 = F_62 ( V_20 , V_26 ) ;
if ( ! V_20 )
break;
V_26 = F_63 ( V_25 , V_20 ) ;
if ( V_26 >= ( 1ul << V_20 -> V_24 ) ) {
V_20 = NULL ;
break;
}
} while ( F_34 ( V_20 ) );
* V_21 = V_85 ;
return V_20 ;
}
static struct V_32 * F_64 ( struct V_86 * V_87 , T_2 V_45 ,
T_2 V_13 , T_1 V_88 , T_1 V_14 )
{
struct V_32 * V_33 ;
if ( ! V_87 )
return NULL ;
F_65 (fa, fah, fa_list) {
if ( V_33 -> V_46 < V_45 )
continue;
if ( V_33 -> V_46 != V_45 )
break;
if ( V_33 -> V_14 > V_14 )
continue;
if ( V_33 -> V_14 != V_14 )
break;
if ( V_33 -> V_89 > V_13 )
continue;
if ( V_33 -> V_90 -> V_91 >= V_88 || V_33 -> V_89 < V_13 )
return V_33 ;
}
return NULL ;
}
static void F_66 ( struct V_59 * V_60 , struct V_18 * V_23 )
{
while ( ! F_40 ( V_23 ) )
V_23 = F_48 ( V_60 , V_23 ) ;
}
static int F_67 ( struct V_59 * V_60 , struct V_18 * V_21 ,
struct V_32 * V_92 , T_3 V_25 )
{
struct V_18 * V_20 , * V_44 ;
V_44 = F_26 ( V_25 , V_92 ) ;
if ( ! V_44 )
goto V_93;
V_20 = F_36 ( V_21 , F_13 ( V_25 , V_21 ) ) ;
if ( V_20 ) {
struct V_18 * V_23 ;
V_23 = F_30 ( V_25 , F_68 ( V_25 ^ V_20 -> V_25 ) , 1 ) ;
if ( ! V_23 )
goto V_63;
F_47 ( V_23 , V_21 ) ;
F_35 ( V_23 , F_13 ( V_25 , V_23 ) ^ 1 , V_20 ) ;
F_39 ( V_21 , V_25 , V_23 ) ;
F_10 ( V_20 , V_23 ) ;
V_21 = V_23 ;
}
F_60 ( V_21 , V_92 -> V_46 ) ;
F_47 ( V_44 , V_21 ) ;
F_39 ( V_21 , V_25 , V_44 ) ;
F_66 ( V_60 , V_21 ) ;
return 0 ;
V_63:
F_44 ( V_44 ) ;
V_93:
return - V_94 ;
}
static int F_69 ( struct V_59 * V_60 , struct V_18 * V_21 ,
struct V_18 * V_44 , struct V_32 * V_92 ,
struct V_32 * V_33 , T_3 V_25 )
{
if ( ! V_44 )
return F_67 ( V_60 , V_21 , V_92 , V_25 ) ;
if ( V_33 ) {
F_70 ( & V_92 -> V_48 , & V_33 -> V_48 ) ;
} else {
struct V_32 * V_95 ;
F_65 (last, &l->leaf, fa_list) {
if ( V_92 -> V_46 < V_95 -> V_46 )
break;
if ( ( V_92 -> V_46 == V_95 -> V_46 ) &&
( V_92 -> V_14 > V_95 -> V_14 ) )
break;
V_33 = V_95 ;
}
if ( V_33 )
F_71 ( & V_92 -> V_48 , & V_33 -> V_48 ) ;
else
F_72 ( & V_92 -> V_48 , & V_44 -> V_47 ) ;
}
if ( V_44 -> V_45 < V_92 -> V_46 ) {
V_44 -> V_45 = V_92 -> V_46 ;
F_60 ( V_21 , V_92 -> V_46 ) ;
}
return 0 ;
}
int F_73 ( struct V_4 * V_4 , struct V_96 * V_97 ,
struct V_98 * V_99 )
{
struct V_59 * V_60 = (struct V_59 * ) V_97 -> V_100 ;
struct V_32 * V_33 , * V_101 ;
struct V_18 * V_44 , * V_21 ;
T_6 V_15 = V_102 ;
struct V_11 * V_12 ;
T_2 V_103 = V_99 -> V_104 ;
T_2 V_45 = V_28 - V_103 ;
T_2 V_13 = V_99 -> V_105 ;
T_1 V_25 ;
int V_106 ;
if ( V_103 > V_28 )
return - V_107 ;
V_25 = F_74 ( V_99 -> V_108 ) ;
F_32 ( L_5 , V_97 -> V_14 , V_25 , V_103 ) ;
if ( ( V_103 < V_28 ) && ( V_25 << V_103 ) )
return - V_107 ;
V_12 = F_75 ( V_99 ) ;
if ( F_76 ( V_12 ) ) {
V_106 = F_77 ( V_12 ) ;
goto V_106;
}
V_44 = F_61 ( V_60 , & V_21 , V_25 ) ;
V_33 = V_44 ? F_64 ( & V_44 -> V_47 , V_45 , V_13 , V_12 -> V_91 ,
V_97 -> V_14 ) : NULL ;
if ( V_33 && V_33 -> V_89 == V_13 &&
V_33 -> V_90 -> V_91 == V_12 -> V_91 ) {
struct V_32 * V_109 , * V_110 ;
V_106 = - V_111 ;
if ( V_99 -> V_112 & V_102 )
goto V_113;
V_15 &= ~ V_102 ;
V_110 = NULL ;
V_109 = V_33 ;
F_78 (fa, fa_list) {
if ( ( V_33 -> V_46 != V_45 ) ||
( V_33 -> V_14 != V_97 -> V_14 ) ||
( V_33 -> V_89 != V_13 ) )
break;
if ( V_33 -> V_90 -> V_91 != V_12 -> V_91 )
break;
if ( V_33 -> V_114 == V_99 -> V_115 &&
V_33 -> V_90 == V_12 ) {
V_110 = V_33 ;
break;
}
}
if ( V_99 -> V_112 & V_116 ) {
struct V_11 * V_117 ;
T_2 V_118 ;
V_15 |= V_116 ;
V_33 = V_109 ;
if ( V_110 ) {
if ( V_33 == V_110 )
V_106 = 0 ;
goto V_113;
}
V_106 = - V_119 ;
V_101 = F_27 ( V_35 , V_41 ) ;
if ( ! V_101 )
goto V_113;
V_117 = V_33 -> V_90 ;
V_101 -> V_89 = V_33 -> V_89 ;
V_101 -> V_90 = V_12 ;
V_101 -> V_114 = V_99 -> V_115 ;
V_118 = V_33 -> V_120 ;
V_101 -> V_120 = V_118 & ~ V_121 ;
V_101 -> V_46 = V_33 -> V_46 ;
V_101 -> V_14 = V_97 -> V_14 ;
V_101 -> V_122 = - 1 ;
F_79 ( & V_33 -> V_48 , & V_101 -> V_48 ) ;
F_16 ( V_33 ) ;
F_80 ( V_117 ) ;
if ( V_118 & V_121 )
F_81 ( V_99 -> V_123 . V_124 ) ;
F_7 ( V_4 , V_125 ,
V_25 , V_103 , V_12 ,
V_101 -> V_89 , V_99 -> V_115 ,
V_97 -> V_14 , V_99 -> V_112 ) ;
F_82 ( V_126 , F_83 ( V_25 ) , V_101 , V_103 ,
V_97 -> V_14 , & V_99 -> V_123 , V_15 ) ;
goto V_127;
}
if ( V_110 )
goto V_113;
if ( V_99 -> V_112 & V_128 )
V_15 |= V_128 ;
else
V_33 = V_109 ;
}
V_106 = - V_129 ;
if ( ! ( V_99 -> V_112 & V_130 ) )
goto V_113;
V_15 |= V_130 ;
V_106 = - V_119 ;
V_101 = F_27 ( V_35 , V_41 ) ;
if ( ! V_101 )
goto V_113;
V_101 -> V_90 = V_12 ;
V_101 -> V_89 = V_13 ;
V_101 -> V_114 = V_99 -> V_115 ;
V_101 -> V_120 = 0 ;
V_101 -> V_46 = V_45 ;
V_101 -> V_14 = V_97 -> V_14 ;
V_101 -> V_122 = - 1 ;
V_106 = F_69 ( V_60 , V_21 , V_44 , V_101 , V_33 , V_25 ) ;
if ( V_106 )
goto V_131;
if ( ! V_103 )
V_97 -> V_132 ++ ;
F_81 ( V_99 -> V_123 . V_124 ) ;
F_7 ( V_4 , V_125 , V_25 , V_103 , V_12 , V_13 ,
V_99 -> V_115 , V_97 -> V_14 , V_99 -> V_112 ) ;
F_82 ( V_126 , F_83 ( V_25 ) , V_101 , V_103 , V_101 -> V_14 ,
& V_99 -> V_123 , V_15 ) ;
V_127:
return 0 ;
V_131:
F_15 ( V_35 , V_101 ) ;
V_113:
F_80 ( V_12 ) ;
V_106:
return V_106 ;
}
static inline T_3 F_84 ( T_3 V_25 , struct V_18 * V_20 )
{
T_3 V_133 = V_20 -> V_25 ;
return ( V_25 ^ V_133 ) & ( V_133 | - V_133 ) ;
}
int F_85 ( struct V_96 * V_97 , const struct V_134 * V_135 ,
struct V_136 * V_137 , int V_138 )
{
struct V_59 * V_60 = (struct V_59 * ) V_97 -> V_100 ;
#ifdef F_57
struct V_78 T_5 * V_79 = V_60 -> V_79 ;
#endif
const T_3 V_25 = F_74 ( V_135 -> V_139 ) ;
struct V_18 * V_20 , * V_85 ;
struct V_32 * V_33 ;
unsigned long V_26 ;
T_3 V_80 ;
F_86 ( V_97 -> V_14 , V_135 ) ;
V_85 = V_60 -> V_19 ;
V_80 = 0 ;
V_20 = F_62 ( V_85 , V_80 ) ;
if ( ! V_20 )
return - V_140 ;
#ifdef F_57
F_58 ( V_79 -> gets ) ;
#endif
for (; ; ) {
V_26 = F_63 ( V_25 , V_20 ) ;
if ( V_26 >= ( 1ul << V_20 -> V_24 ) )
break;
if ( F_87 ( V_20 ) )
goto V_141;
if ( V_20 -> V_45 > V_20 -> V_29 ) {
V_85 = V_20 ;
V_80 = V_26 ;
}
V_20 = F_62 ( V_20 , V_26 ) ;
if ( F_88 ( ! V_20 ) )
goto V_142;
}
for (; ; ) {
struct V_18 T_7 * * V_143 = V_20 -> V_17 ;
if ( F_88 ( F_84 ( V_25 , V_20 ) ) || ( V_20 -> V_45 == V_20 -> V_29 ) )
goto V_142;
if ( F_88 ( F_87 ( V_20 ) ) )
break;
while ( ( V_20 = F_89 ( * V_143 ) ) == NULL ) {
V_142:
#ifdef F_57
if ( ! V_20 )
F_58 ( V_79 -> V_144 ) ;
#endif
while ( ! V_80 ) {
T_3 V_145 = V_85 -> V_25 ;
if ( F_40 ( V_85 ) )
return - V_140 ;
#ifdef F_57
F_58 ( V_79 -> V_146 ) ;
#endif
V_85 = F_90 ( V_85 ) ;
V_80 = F_13 ( V_145 , V_85 ) ;
}
V_80 &= V_80 - 1 ;
V_143 = & V_85 -> V_17 [ V_80 ] ;
}
}
V_141:
V_26 = V_25 ^ V_20 -> V_25 ;
F_91 (fa, &n->leaf, fa_list) {
struct V_11 * V_12 = V_33 -> V_90 ;
int V_147 , V_106 ;
if ( ( V_27 > V_28 ) || ( V_33 -> V_46 < V_28 ) ) {
if ( V_26 >= ( 1ul << V_33 -> V_46 ) )
continue;
}
if ( V_33 -> V_89 && V_33 -> V_89 != V_135 -> V_148 )
continue;
if ( V_12 -> V_149 )
continue;
if ( V_33 -> V_90 -> V_150 < V_135 -> V_151 )
continue;
F_92 ( V_33 ) ;
V_106 = V_152 [ V_33 -> V_114 ] . error ;
if ( F_88 ( V_106 < 0 ) ) {
#ifdef F_57
F_58 ( V_79 -> V_153 ) ;
#endif
return V_106 ;
}
if ( V_12 -> V_138 & V_154 )
continue;
for ( V_147 = 0 ; V_147 < V_12 -> V_155 ; V_147 ++ ) {
const struct V_156 * V_157 = & V_12 -> V_156 [ V_147 ] ;
struct V_158 * V_159 = F_93 ( V_157 -> V_160 ) ;
if ( V_157 -> V_161 & V_154 )
continue;
if ( V_159 &&
F_94 ( V_159 ) &&
V_157 -> V_161 & V_162 &&
! ( V_138 & V_163 ) )
continue;
if ( ! ( V_135 -> V_164 & V_165 ) ) {
if ( V_135 -> V_166 &&
V_135 -> V_166 != V_157 -> V_167 )
continue;
}
if ( ! ( V_138 & V_168 ) )
F_95 ( & V_12 -> V_169 ) ;
V_137 -> V_170 = V_28 - V_33 -> V_46 ;
V_137 -> V_171 = V_147 ;
V_137 -> type = V_33 -> V_114 ;
V_137 -> V_172 = V_12 -> V_150 ;
V_137 -> V_12 = V_12 ;
V_137 -> V_173 = V_97 ;
V_137 -> V_174 = & V_20 -> V_47 ;
#ifdef F_57
F_58 ( V_79 -> V_153 ) ;
#endif
F_96 ( V_157 ) ;
return V_106 ;
}
}
#ifdef F_57
F_58 ( V_79 -> V_175 ) ;
#endif
goto V_142;
}
static void F_97 ( struct V_59 * V_60 , struct V_18 * V_21 ,
struct V_18 * V_44 , struct V_32 * V_176 )
{
struct V_177 * * V_178 = V_176 -> V_48 . V_178 ;
struct V_32 * V_33 = F_98 ( V_178 , F_99 ( * V_33 ) , V_48 . V_55 ) ;
F_100 ( & V_176 -> V_48 ) ;
if ( F_101 ( & V_44 -> V_47 ) ) {
if ( V_21 -> V_45 == V_44 -> V_45 )
F_59 ( V_21 , V_21 -> V_29 ) ;
F_39 ( V_21 , V_44 -> V_25 , NULL ) ;
F_44 ( V_44 ) ;
F_66 ( V_60 , V_21 ) ;
return;
}
if ( * V_178 )
return;
V_44 -> V_45 = V_33 -> V_46 ;
F_59 ( V_21 , V_33 -> V_46 ) ;
}
int F_102 ( struct V_4 * V_4 , struct V_96 * V_97 ,
struct V_98 * V_99 )
{
struct V_59 * V_60 = (struct V_59 * ) V_97 -> V_100 ;
struct V_32 * V_33 , * V_179 ;
struct V_18 * V_44 , * V_21 ;
T_2 V_103 = V_99 -> V_104 ;
T_2 V_45 = V_28 - V_103 ;
T_2 V_13 = V_99 -> V_105 ;
T_1 V_25 ;
if ( V_103 > V_28 )
return - V_107 ;
V_25 = F_74 ( V_99 -> V_108 ) ;
if ( ( V_103 < V_28 ) && ( V_25 << V_103 ) )
return - V_107 ;
V_44 = F_61 ( V_60 , & V_21 , V_25 ) ;
if ( ! V_44 )
return - V_180 ;
V_33 = F_64 ( & V_44 -> V_47 , V_45 , V_13 , 0 , V_97 -> V_14 ) ;
if ( ! V_33 )
return - V_180 ;
F_32 ( L_6 , V_25 , V_103 , V_13 , V_60 ) ;
V_179 = NULL ;
F_78 (fa, fa_list) {
struct V_11 * V_12 = V_33 -> V_90 ;
if ( ( V_33 -> V_46 != V_45 ) ||
( V_33 -> V_14 != V_97 -> V_14 ) ||
( V_33 -> V_89 != V_13 ) )
break;
if ( ( ! V_99 -> V_115 || V_33 -> V_114 == V_99 -> V_115 ) &&
( V_99 -> V_181 == V_182 ||
V_33 -> V_90 -> V_150 == V_99 -> V_181 ) &&
( ! V_99 -> V_183 ||
V_12 -> V_184 == V_99 -> V_183 ) &&
( ! V_99 -> V_185 ||
V_12 -> V_186 == V_99 -> V_185 ) &&
F_103 ( V_99 , V_12 ) == 0 ) {
V_179 = V_33 ;
break;
}
}
if ( ! V_179 )
return - V_180 ;
F_7 ( V_4 , V_187 , V_25 , V_103 ,
V_179 -> V_90 , V_13 , V_99 -> V_115 ,
V_97 -> V_14 , 0 ) ;
F_82 ( V_188 , F_83 ( V_25 ) , V_179 , V_103 , V_97 -> V_14 ,
& V_99 -> V_123 , 0 ) ;
if ( ! V_103 )
V_97 -> V_132 -- ;
F_97 ( V_60 , V_21 , V_44 , V_179 ) ;
if ( V_179 -> V_120 & V_121 )
F_81 ( V_99 -> V_123 . V_124 ) ;
F_80 ( V_179 -> V_90 ) ;
F_16 ( V_179 ) ;
return 0 ;
}
static struct V_18 * F_104 ( struct V_18 * * V_23 , T_3 V_25 )
{
struct V_18 * V_85 , * V_20 = * V_23 ;
unsigned long V_80 ;
do {
V_85 = V_20 ;
V_80 = ( V_25 > V_85 -> V_25 ) ? F_13 ( V_25 , V_85 ) : 0 ;
if ( V_80 >> V_85 -> V_24 )
break;
V_20 = F_62 ( V_85 , V_80 ++ ) ;
if ( ! V_20 )
break;
if ( F_87 ( V_20 ) && ( V_20 -> V_25 >= V_25 ) )
goto V_141;
} while ( F_34 ( V_20 ) );
while ( ! F_40 ( V_85 ) ) {
if ( V_80 >= ( 1ul << V_85 -> V_24 ) ) {
T_3 V_145 = V_85 -> V_25 ;
V_85 = F_90 ( V_85 ) ;
V_80 = F_13 ( V_145 , V_85 ) + 1 ;
continue;
}
V_20 = F_62 ( V_85 , V_80 ++ ) ;
if ( ! V_20 )
continue;
if ( F_87 ( V_20 ) )
goto V_141;
V_85 = V_20 ;
V_80 = 0 ;
}
* V_23 = V_85 ;
return NULL ;
V_141:
* V_23 = V_85 ;
return V_20 ;
}
static void F_105 ( struct V_96 * V_97 )
{
struct V_59 * V_60 = (struct V_59 * ) V_97 -> V_100 ;
struct V_18 * V_85 = V_60 -> V_19 ;
unsigned long V_80 = 1 ;
struct V_177 * V_189 ;
struct V_32 * V_33 ;
for (; ; ) {
struct V_18 * V_20 ;
if ( ! ( V_80 -- ) ) {
T_3 V_145 = V_85 -> V_25 ;
if ( F_40 ( V_85 ) )
break;
V_20 = V_85 ;
V_85 = F_38 ( V_85 ) ;
F_39 ( V_85 , V_20 -> V_25 , NULL ) ;
F_44 ( V_20 ) ;
V_80 = F_13 ( V_145 , V_85 ) ;
continue;
}
V_20 = F_36 ( V_85 , V_80 ) ;
if ( ! V_20 )
continue;
if ( F_34 ( V_20 ) ) {
V_85 = V_20 ;
V_80 = 1ul << V_20 -> V_24 ;
continue;
}
F_106 (fa, tmp, &n->leaf, fa_list) {
F_100 ( & V_33 -> V_48 ) ;
F_16 ( V_33 ) ;
}
F_39 ( V_85 , V_20 -> V_25 , NULL ) ;
F_44 ( V_20 ) ;
}
#ifdef F_57
F_107 ( V_60 -> V_79 ) ;
#endif
F_108 ( V_97 ) ;
}
struct V_96 * F_109 ( struct V_96 * V_190 )
{
struct V_59 * V_191 = (struct V_59 * ) V_190 -> V_100 ;
struct V_18 * V_44 , * V_21 = V_191 -> V_19 ;
struct V_96 * V_192 ;
struct V_32 * V_33 ;
struct V_59 * V_193 ;
T_3 V_25 = 0 ;
if ( V_190 -> V_100 == V_190 -> V_194 )
return V_190 ;
V_192 = F_110 ( V_195 , NULL ) ;
if ( ! V_192 )
return NULL ;
V_193 = (struct V_59 * ) V_192 -> V_100 ;
while ( ( V_44 = F_104 ( & V_21 , V_25 ) ) != NULL ) {
struct V_18 * V_196 = NULL , * V_197 ;
F_91 (fa, &l->leaf, fa_list) {
struct V_32 * V_101 ;
if ( V_192 -> V_14 != V_33 -> V_14 )
continue;
V_101 = F_27 ( V_35 , V_41 ) ;
if ( ! V_101 )
goto V_113;
memcpy ( V_101 , V_33 , sizeof( * V_33 ) ) ;
if ( ! V_196 )
V_196 = F_61 ( V_193 , & V_197 , V_44 -> V_25 ) ;
if ( F_69 ( V_193 , V_197 , V_196 , V_101 ,
NULL , V_44 -> V_25 ) ) {
F_15 ( V_35 , V_101 ) ;
goto V_113;
}
}
V_25 = V_44 -> V_25 + 1 ;
if ( V_25 < V_44 -> V_25 )
break;
}
return V_192 ;
V_113:
F_105 ( V_192 ) ;
return NULL ;
}
void F_111 ( struct V_96 * V_97 )
{
struct V_59 * V_60 = (struct V_59 * ) V_97 -> V_100 ;
struct V_18 * V_85 = V_60 -> V_19 ;
unsigned long V_80 = 1 ;
struct V_177 * V_189 ;
struct V_32 * V_33 ;
for (; ; ) {
unsigned char V_45 = 0 ;
struct V_18 * V_20 ;
if ( ! ( V_80 -- ) ) {
T_3 V_145 = V_85 -> V_25 ;
if ( F_40 ( V_85 ) )
break;
if ( V_85 -> V_45 > V_85 -> V_29 )
F_52 ( V_85 ) ;
V_85 = F_48 ( V_60 , V_85 ) ;
V_80 = F_13 ( V_145 , V_85 ) ;
continue;
}
V_20 = F_36 ( V_85 , V_80 ) ;
if ( ! V_20 )
continue;
if ( F_34 ( V_20 ) ) {
V_85 = V_20 ;
V_80 = 1ul << V_20 -> V_24 ;
continue;
}
F_106 (fa, tmp, &n->leaf, fa_list) {
if ( V_97 -> V_14 != V_33 -> V_14 ) {
F_100 ( & V_33 -> V_48 ) ;
F_16 ( V_33 ) ;
continue;
}
V_45 = V_33 -> V_46 ;
}
V_20 -> V_45 = V_45 ;
if ( F_101 ( & V_20 -> V_47 ) ) {
F_39 ( V_85 , V_20 -> V_25 , NULL ) ;
F_44 ( V_20 ) ;
}
}
}
int F_112 ( struct V_4 * V_4 , struct V_96 * V_97 )
{
struct V_59 * V_60 = (struct V_59 * ) V_97 -> V_100 ;
struct V_18 * V_85 = V_60 -> V_19 ;
unsigned long V_80 = 1 ;
struct V_177 * V_189 ;
struct V_32 * V_33 ;
int V_141 = 0 ;
for (; ; ) {
unsigned char V_45 = 0 ;
struct V_18 * V_20 ;
if ( ! ( V_80 -- ) ) {
T_3 V_145 = V_85 -> V_25 ;
if ( F_40 ( V_85 ) )
break;
if ( V_85 -> V_45 > V_85 -> V_29 )
F_52 ( V_85 ) ;
V_85 = F_48 ( V_60 , V_85 ) ;
V_80 = F_13 ( V_145 , V_85 ) ;
continue;
}
V_20 = F_36 ( V_85 , V_80 ) ;
if ( ! V_20 )
continue;
if ( F_34 ( V_20 ) ) {
V_85 = V_20 ;
V_80 = 1ul << V_20 -> V_24 ;
continue;
}
F_106 (fa, tmp, &n->leaf, fa_list) {
struct V_11 * V_12 = V_33 -> V_90 ;
if ( ! V_12 || ! ( V_12 -> V_138 & V_154 ) ) {
V_45 = V_33 -> V_46 ;
continue;
}
F_7 ( V_4 , V_187 ,
V_20 -> V_25 ,
V_28 - V_33 -> V_46 ,
V_12 , V_33 -> V_89 , V_33 -> V_114 ,
V_97 -> V_14 , 0 ) ;
F_100 ( & V_33 -> V_48 ) ;
F_80 ( V_33 -> V_90 ) ;
F_16 ( V_33 ) ;
V_141 ++ ;
}
V_20 -> V_45 = V_45 ;
if ( F_101 ( & V_20 -> V_47 ) ) {
F_39 ( V_85 , V_20 -> V_25 , NULL ) ;
F_44 ( V_20 ) ;
}
}
F_32 ( L_7 , V_141 ) ;
return V_141 ;
}
static void F_113 ( struct V_30 * V_31 )
{
struct V_96 * V_97 = F_9 ( V_31 , struct V_96 , V_34 ) ;
#ifdef F_57
struct V_59 * V_60 = (struct V_59 * ) V_97 -> V_100 ;
if ( V_97 -> V_100 == V_97 -> V_194 )
F_107 ( V_60 -> V_79 ) ;
#endif
F_108 ( V_97 ) ;
}
void F_114 ( struct V_96 * V_97 )
{
F_17 ( & V_97 -> V_34 , F_113 ) ;
}
static int F_115 ( struct V_18 * V_44 , struct V_96 * V_97 ,
struct V_198 * V_199 , struct V_200 * V_201 )
{
T_8 V_202 = F_83 ( V_44 -> V_25 ) ;
struct V_32 * V_33 ;
int V_50 , V_203 ;
V_203 = V_201 -> args [ 4 ] ;
V_50 = 0 ;
F_91 (fa, &l->leaf, fa_list) {
if ( V_50 < V_203 ) {
V_50 ++ ;
continue;
}
if ( V_97 -> V_14 != V_33 -> V_14 ) {
V_50 ++ ;
continue;
}
if ( F_116 ( V_199 , F_117 ( V_201 -> V_199 ) . V_204 ,
V_201 -> V_205 -> V_206 ,
V_126 ,
V_97 -> V_14 ,
V_33 -> V_114 ,
V_202 ,
V_28 - V_33 -> V_46 ,
V_33 -> V_89 ,
V_33 -> V_90 , V_207 ) < 0 ) {
V_201 -> args [ 4 ] = V_50 ;
return - 1 ;
}
V_50 ++ ;
}
V_201 -> args [ 4 ] = V_50 ;
return V_199 -> V_208 ;
}
int F_118 ( struct V_96 * V_97 , struct V_198 * V_199 ,
struct V_200 * V_201 )
{
struct V_59 * V_60 = (struct V_59 * ) V_97 -> V_100 ;
struct V_18 * V_44 , * V_21 = V_60 -> V_19 ;
int V_209 = V_201 -> args [ 2 ] ;
T_3 V_25 = V_201 -> args [ 3 ] ;
while ( ( V_44 = F_104 ( & V_21 , V_25 ) ) != NULL ) {
if ( F_115 ( V_44 , V_97 , V_199 , V_201 ) < 0 ) {
V_201 -> args [ 3 ] = V_25 ;
V_201 -> args [ 2 ] = V_209 ;
return - 1 ;
}
++ V_209 ;
V_25 = V_44 -> V_25 + 1 ;
memset ( & V_201 -> args [ 4 ] , 0 ,
sizeof( V_201 -> args ) - 4 * sizeof( V_201 -> args [ 0 ] ) ) ;
if ( V_25 < V_44 -> V_25 )
break;
}
V_201 -> args [ 3 ] = V_25 ;
V_201 -> args [ 2 ] = V_209 ;
return V_199 -> V_208 ;
}
void T_9 F_119 ( void )
{
V_35 = F_120 ( L_8 ,
sizeof( struct V_32 ) ,
0 , V_210 , NULL ) ;
V_37 = F_120 ( L_9 ,
V_211 ,
0 , V_210 , NULL ) ;
}
struct V_96 * F_110 ( T_1 V_212 , struct V_96 * V_213 )
{
struct V_96 * V_97 ;
struct V_59 * V_60 ;
T_4 V_214 = sizeof( * V_97 ) ;
if ( ! V_213 )
V_214 += sizeof( struct V_59 ) ;
V_97 = F_22 ( V_214 , V_41 ) ;
if ( ! V_97 )
return NULL ;
V_97 -> V_14 = V_212 ;
V_97 -> V_132 = 0 ;
V_97 -> V_100 = ( V_213 ? V_213 -> V_194 : V_97 -> V_194 ) ;
if ( V_213 )
return V_97 ;
V_60 = (struct V_59 * ) V_97 -> V_100 ;
V_60 -> V_19 [ 0 ] . V_29 = V_28 ;
V_60 -> V_19 [ 0 ] . V_45 = V_28 ;
#ifdef F_57
V_60 -> V_79 = F_121 ( struct V_78 ) ;
if ( ! V_60 -> V_79 ) {
F_108 ( V_97 ) ;
V_97 = NULL ;
}
#endif
return V_97 ;
}
static struct V_18 * F_122 ( struct V_215 * V_216 )
{
unsigned long V_80 = V_216 -> V_26 ;
struct V_18 * V_85 = V_216 -> V_17 ;
T_3 V_145 ;
F_32 ( L_10 ,
V_216 -> V_17 , V_216 -> V_26 , V_216 -> V_217 ) ;
while ( ! F_40 ( V_85 ) ) {
while ( V_80 < F_12 ( V_85 ) ) {
struct V_18 * V_20 = F_62 ( V_85 , V_80 ++ ) ;
if ( ! V_20 )
continue;
if ( F_87 ( V_20 ) ) {
V_216 -> V_17 = V_85 ;
V_216 -> V_26 = V_80 ;
} else {
V_216 -> V_17 = V_20 ;
V_216 -> V_26 = 0 ;
++ V_216 -> V_217 ;
}
return V_20 ;
}
V_145 = V_85 -> V_25 ;
V_85 = F_90 ( V_85 ) ;
V_80 = F_13 ( V_145 , V_85 ) + 1 ;
-- V_216 -> V_217 ;
}
V_216 -> V_17 = V_85 ;
V_216 -> V_26 = 0 ;
return NULL ;
}
static struct V_18 * F_123 ( struct V_215 * V_216 ,
struct V_59 * V_60 )
{
struct V_18 * V_20 , * V_85 ;
if ( ! V_60 )
return NULL ;
V_85 = V_60 -> V_19 ;
V_20 = F_89 ( V_85 -> V_17 [ 0 ] ) ;
if ( ! V_20 )
return NULL ;
if ( F_34 ( V_20 ) ) {
V_216 -> V_17 = V_20 ;
V_216 -> V_26 = 0 ;
V_216 -> V_217 = 1 ;
} else {
V_216 -> V_17 = V_85 ;
V_216 -> V_26 = 0 ;
V_216 -> V_217 = 0 ;
}
return V_20 ;
}
static void F_124 ( struct V_59 * V_60 , struct V_218 * V_219 )
{
struct V_18 * V_20 ;
struct V_215 V_216 ;
memset ( V_219 , 0 , sizeof( * V_219 ) ) ;
F_125 () ;
for ( V_20 = F_123 ( & V_216 , V_60 ) ; V_20 ; V_20 = F_122 ( & V_216 ) ) {
if ( F_87 ( V_20 ) ) {
struct V_32 * V_33 ;
V_219 -> V_220 ++ ;
V_219 -> V_221 += V_216 . V_217 ;
if ( V_216 . V_217 > V_219 -> V_222 )
V_219 -> V_222 = V_216 . V_217 ;
F_91 ( V_33 , & V_20 -> V_47 , V_48 )
++ V_219 -> V_223 ;
} else {
V_219 -> V_224 ++ ;
if ( V_20 -> V_24 < V_225 )
V_219 -> V_226 [ V_20 -> V_24 ] ++ ;
V_219 -> V_227 += F_8 ( V_20 ) -> V_42 ;
}
}
F_126 () ;
}
static void F_127 ( struct V_228 * V_229 , struct V_218 * V_230 )
{
unsigned int V_50 , V_231 , V_232 , V_233 , V_234 ;
if ( V_230 -> V_220 )
V_234 = V_230 -> V_221 * 100 / V_230 -> V_220 ;
else
V_234 = 0 ;
F_128 ( V_229 , L_11 ,
V_234 / 100 , V_234 % 100 ) ;
F_128 ( V_229 , L_12 , V_230 -> V_222 ) ;
F_128 ( V_229 , L_13 , V_230 -> V_220 ) ;
V_233 = V_211 * V_230 -> V_220 ;
F_128 ( V_229 , L_14 , V_230 -> V_223 ) ;
V_233 += sizeof( struct V_32 ) * V_230 -> V_223 ;
F_128 ( V_229 , L_15 , V_230 -> V_224 ) ;
V_233 += F_21 ( 0 ) * V_230 -> V_224 ;
V_231 = V_225 ;
while ( V_231 > 0 && V_230 -> V_226 [ V_231 - 1 ] == 0 )
V_231 -- ;
V_232 = 0 ;
for ( V_50 = 1 ; V_50 < V_231 ; V_50 ++ )
if ( V_230 -> V_226 [ V_50 ] != 0 ) {
F_128 ( V_229 , L_16 , V_50 , V_230 -> V_226 [ V_50 ] ) ;
V_232 += ( 1 << V_50 ) * V_230 -> V_226 [ V_50 ] ;
}
F_129 ( V_229 , '\n' ) ;
F_128 ( V_229 , L_17 , V_232 ) ;
V_233 += sizeof( struct V_18 * ) * V_232 ;
F_128 ( V_229 , L_18 , V_230 -> V_227 ) ;
F_128 ( V_229 , L_19 , ( V_233 + 1023 ) / 1024 ) ;
}
static void F_130 ( struct V_228 * V_229 ,
const struct V_78 T_5 * V_79 )
{
struct V_78 V_219 = { 0 } ;
int V_235 ;
F_131 (cpu) {
const struct V_78 * V_236 = F_132 ( V_79 , V_235 ) ;
V_219 . gets += V_236 -> gets ;
V_219 . V_146 += V_236 -> V_146 ;
V_219 . V_153 += V_236 -> V_153 ;
V_219 . V_175 += V_236 -> V_175 ;
V_219 . V_144 += V_236 -> V_144 ;
V_219 . V_83 += V_236 -> V_83 ;
}
F_128 ( V_229 , L_20 ) ;
F_128 ( V_229 , L_21 , V_219 . gets ) ;
F_128 ( V_229 , L_22 , V_219 . V_146 ) ;
F_128 ( V_229 , L_23 ,
V_219 . V_153 ) ;
F_128 ( V_229 , L_24 , V_219 . V_175 ) ;
F_128 ( V_229 , L_25 , V_219 . V_144 ) ;
F_128 ( V_229 , L_26 , V_219 . V_83 ) ;
}
static void F_133 ( struct V_228 * V_229 , struct V_96 * V_97 )
{
if ( V_97 -> V_14 == V_195 )
F_134 ( V_229 , L_27 ) ;
else if ( V_97 -> V_14 == V_237 )
F_134 ( V_229 , L_28 ) ;
else
F_128 ( V_229 , L_29 , V_97 -> V_14 ) ;
}
static int F_135 ( struct V_228 * V_229 , void * V_238 )
{
struct V_4 * V_4 = (struct V_4 * ) V_229 -> V_239 ;
unsigned int V_240 ;
F_128 ( V_229 ,
L_30
L_31 ,
V_211 , F_21 ( 0 ) ) ;
for ( V_240 = 0 ; V_240 < V_241 ; V_240 ++ ) {
struct V_86 * V_31 = & V_4 -> V_242 . V_243 [ V_240 ] ;
struct V_96 * V_97 ;
F_91 (tb, head, tb_hlist) {
struct V_59 * V_60 = (struct V_59 * ) V_97 -> V_100 ;
struct V_218 V_230 ;
if ( ! V_60 )
continue;
F_133 ( V_229 , V_97 ) ;
F_124 ( V_60 , & V_230 ) ;
F_127 ( V_229 , & V_230 ) ;
#ifdef F_57
F_130 ( V_229 , V_60 -> V_79 ) ;
#endif
}
}
return 0 ;
}
static int F_136 ( struct V_54 * V_54 , struct V_244 * V_244 )
{
return F_137 ( V_54 , V_244 , F_135 ) ;
}
static struct V_18 * F_138 ( struct V_228 * V_229 , T_10 V_29 )
{
struct V_215 * V_216 = V_229 -> V_239 ;
struct V_4 * V_4 = F_139 ( V_229 ) ;
T_10 V_245 = 0 ;
unsigned int V_240 ;
for ( V_240 = 0 ; V_240 < V_241 ; V_240 ++ ) {
struct V_86 * V_31 = & V_4 -> V_242 . V_243 [ V_240 ] ;
struct V_96 * V_97 ;
F_91 (tb, head, tb_hlist) {
struct V_18 * V_20 ;
for ( V_20 = F_123 ( V_216 ,
(struct V_59 * ) V_97 -> V_100 ) ;
V_20 ; V_20 = F_122 ( V_216 ) )
if ( V_29 == V_245 ++ ) {
V_216 -> V_97 = V_97 ;
return V_20 ;
}
}
}
return NULL ;
}
static void * F_140 ( struct V_228 * V_229 , T_10 * V_29 )
__acquires( T_11 )
{
F_125 () ;
return F_138 ( V_229 , * V_29 ) ;
}
static void * F_141 ( struct V_228 * V_229 , void * V_238 , T_10 * V_29 )
{
struct V_215 * V_216 = V_229 -> V_239 ;
struct V_4 * V_4 = F_139 ( V_229 ) ;
struct V_96 * V_97 = V_216 -> V_97 ;
struct V_177 * V_246 ;
unsigned int V_240 ;
struct V_18 * V_20 ;
++ * V_29 ;
V_20 = F_122 ( V_216 ) ;
if ( V_20 )
return V_20 ;
V_240 = V_97 -> V_14 & ( V_241 - 1 ) ;
while ( ( V_246 = F_89 ( F_142 ( & V_97 -> V_247 ) ) ) ) {
V_97 = F_98 ( V_246 , struct V_96 , V_247 ) ;
V_20 = F_123 ( V_216 , (struct V_59 * ) V_97 -> V_100 ) ;
if ( V_20 )
goto V_141;
}
while ( ++ V_240 < V_241 ) {
struct V_86 * V_31 = & V_4 -> V_242 . V_243 [ V_240 ] ;
F_91 (tb, head, tb_hlist) {
V_20 = F_123 ( V_216 , (struct V_59 * ) V_97 -> V_100 ) ;
if ( V_20 )
goto V_141;
}
}
return NULL ;
V_141:
V_216 -> V_97 = V_97 ;
return V_20 ;
}
static void F_143 ( struct V_228 * V_229 , void * V_238 )
__releases( T_11 )
{
F_126 () ;
}
static void F_144 ( struct V_228 * V_229 , int V_20 )
{
while ( V_20 -- > 0 )
F_134 ( V_229 , L_32 ) ;
}
static inline const char * F_145 ( char * V_248 , T_4 V_208 , enum V_249 V_219 )
{
switch ( V_219 ) {
case V_250 : return L_33 ;
case V_251 : return L_34 ;
case V_252 : return L_35 ;
case V_253 : return L_36 ;
case V_182 : return L_37 ;
default:
snprintf ( V_248 , V_208 , L_38 , V_219 ) ;
return V_248 ;
}
}
static inline const char * F_146 ( char * V_248 , T_4 V_208 , unsigned int V_60 )
{
if ( V_60 < V_254 && V_255 [ V_60 ] )
return V_255 [ V_60 ] ;
snprintf ( V_248 , V_208 , L_39 , V_60 ) ;
return V_248 ;
}
static int F_147 ( struct V_228 * V_229 , void * V_238 )
{
const struct V_215 * V_216 = V_229 -> V_239 ;
struct V_18 * V_20 = V_238 ;
if ( F_40 ( F_90 ( V_20 ) ) )
F_133 ( V_229 , V_216 -> V_97 ) ;
if ( F_34 ( V_20 ) ) {
T_8 V_256 = F_83 ( V_20 -> V_25 ) ;
F_144 ( V_229 , V_216 -> V_217 - 1 ) ;
F_128 ( V_229 , L_40 ,
& V_256 , V_28 - V_20 -> V_29 - V_20 -> V_24 , V_20 -> V_24 ,
F_8 ( V_20 ) -> V_43 ,
F_8 ( V_20 ) -> V_42 ) ;
} else {
T_8 V_257 = F_83 ( V_20 -> V_25 ) ;
struct V_32 * V_33 ;
F_144 ( V_229 , V_216 -> V_217 ) ;
F_128 ( V_229 , L_41 , & V_257 ) ;
F_91 (fa, &n->leaf, fa_list) {
char V_258 [ 32 ] , V_259 [ 32 ] ;
F_144 ( V_229 , V_216 -> V_217 + 1 ) ;
F_128 ( V_229 , L_42 ,
V_28 - V_33 -> V_46 ,
F_145 ( V_258 , sizeof( V_258 ) ,
V_33 -> V_90 -> V_150 ) ,
F_146 ( V_259 , sizeof( V_259 ) ,
V_33 -> V_114 ) ) ;
if ( V_33 -> V_89 )
F_128 ( V_229 , L_43 , V_33 -> V_89 ) ;
F_129 ( V_229 , '\n' ) ;
}
}
return 0 ;
}
static int F_148 ( struct V_54 * V_54 , struct V_244 * V_244 )
{
return F_149 ( V_54 , V_244 , & V_260 ,
sizeof( struct V_215 ) ) ;
}
static struct V_18 * F_150 ( struct V_261 * V_216 ,
T_10 V_29 )
{
struct V_18 * V_44 , * * V_21 = & V_216 -> V_17 ;
T_3 V_25 ;
if ( V_216 -> V_29 > 0 && V_29 >= V_216 -> V_29 ) {
V_25 = V_216 -> V_25 ;
} else {
V_216 -> V_29 = 1 ;
V_25 = 0 ;
}
V_29 -= V_216 -> V_29 ;
while ( ( V_44 = F_104 ( V_21 , V_25 ) ) && ( V_29 -- > 0 ) ) {
V_25 = V_44 -> V_25 + 1 ;
V_216 -> V_29 ++ ;
V_44 = NULL ;
if ( ! V_25 )
break;
}
if ( V_44 )
V_216 -> V_25 = V_44 -> V_25 ;
else
V_216 -> V_29 = 0 ;
return V_44 ;
}
static void * F_151 ( struct V_228 * V_229 , T_10 * V_29 )
__acquires( T_11 )
{
struct V_261 * V_216 = V_229 -> V_239 ;
struct V_96 * V_97 ;
struct V_59 * V_60 ;
F_125 () ;
V_97 = F_152 ( F_139 ( V_229 ) , V_237 ) ;
if ( ! V_97 )
return NULL ;
V_216 -> V_262 = V_97 ;
V_60 = (struct V_59 * ) V_97 -> V_100 ;
V_216 -> V_17 = V_60 -> V_19 ;
if ( * V_29 != 0 )
return F_150 ( V_216 , * V_29 ) ;
V_216 -> V_29 = 0 ;
V_216 -> V_25 = V_77 ;
return V_263 ;
}
static void * F_153 ( struct V_228 * V_229 , void * V_238 , T_10 * V_29 )
{
struct V_261 * V_216 = V_229 -> V_239 ;
struct V_18 * V_44 = NULL ;
T_3 V_25 = V_216 -> V_25 + 1 ;
++ * V_29 ;
if ( ( V_238 == V_263 ) || V_25 )
V_44 = F_104 ( & V_216 -> V_17 , V_25 ) ;
if ( V_44 ) {
V_216 -> V_25 = V_44 -> V_25 ;
V_216 -> V_29 ++ ;
} else {
V_216 -> V_29 = 0 ;
}
return V_44 ;
}
static void F_154 ( struct V_228 * V_229 , void * V_238 )
__releases( T_11 )
{
F_126 () ;
}
static unsigned int F_155 ( int type , T_8 V_264 , const struct V_11 * V_12 )
{
unsigned int V_265 = 0 ;
if ( type == V_266 || type == V_267 )
V_265 = V_268 ;
if ( V_12 && V_12 -> V_156 -> V_269 )
V_265 |= V_270 ;
if ( V_264 == F_83 ( 0xFFFFFFFF ) )
V_265 |= V_271 ;
V_265 |= V_272 ;
return V_265 ;
}
static int F_156 ( struct V_228 * V_229 , void * V_238 )
{
struct V_261 * V_216 = V_229 -> V_239 ;
struct V_96 * V_97 = V_216 -> V_262 ;
struct V_32 * V_33 ;
struct V_18 * V_44 = V_238 ;
T_8 V_133 ;
if ( V_238 == V_263 ) {
F_128 ( V_229 , L_44 , L_45
L_46
L_47 ) ;
return 0 ;
}
V_133 = F_83 ( V_44 -> V_25 ) ;
F_91 (fa, &l->leaf, fa_list) {
const struct V_11 * V_12 = V_33 -> V_90 ;
T_8 V_264 = F_157 ( V_28 - V_33 -> V_46 ) ;
unsigned int V_265 = F_155 ( V_33 -> V_114 , V_264 , V_12 ) ;
if ( ( V_33 -> V_114 == V_273 ) ||
( V_33 -> V_114 == V_274 ) )
continue;
if ( V_33 -> V_14 != V_97 -> V_14 )
continue;
F_158 ( V_229 , 127 ) ;
if ( V_12 )
F_128 ( V_229 ,
L_48
L_49 ,
V_12 -> V_275 ? V_12 -> V_275 -> V_276 : L_50 ,
V_133 ,
V_12 -> V_156 -> V_269 , V_265 , 0 , 0 ,
V_12 -> V_91 ,
V_264 ,
( V_12 -> V_277 ?
V_12 -> V_277 + 40 : 0 ) ,
V_12 -> V_278 ,
V_12 -> V_279 >> 3 ) ;
else
F_128 ( V_229 ,
L_51
L_49 ,
V_133 , 0 , V_265 , 0 , 0 , 0 ,
V_264 , 0 , 0 , 0 ) ;
F_159 ( V_229 , '\n' ) ;
}
return 0 ;
}
static int F_160 ( struct V_54 * V_54 , struct V_244 * V_244 )
{
return F_149 ( V_54 , V_244 , & V_280 ,
sizeof( struct V_261 ) ) ;
}
int T_12 F_161 ( struct V_4 * V_4 )
{
if ( ! F_162 ( L_52 , V_281 , V_4 -> V_282 , & V_283 ) )
goto V_284;
if ( ! F_162 ( L_53 , V_281 , V_4 -> V_282 ,
& V_285 ) )
goto V_286;
if ( ! F_162 ( L_54 , V_281 , V_4 -> V_282 , & V_287 ) )
goto V_288;
return 0 ;
V_288:
F_163 ( L_53 , V_4 -> V_282 ) ;
V_286:
F_163 ( L_52 , V_4 -> V_282 ) ;
V_284:
return - V_94 ;
}
void T_13 F_164 ( struct V_4 * V_4 )
{
F_163 ( L_52 , V_4 -> V_282 ) ;
F_163 ( L_53 , V_4 -> V_282 ) ;
F_163 ( L_54 , V_4 -> V_282 ) ;
}
