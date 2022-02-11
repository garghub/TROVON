static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 [ 0 ] ) ;
}
static inline void F_3 ( struct V_2 * V_4 , struct V_2 * V_5 )
{
if ( V_4 )
F_4 ( F_1 ( V_4 ) -> V_6 , V_5 ) ;
}
static inline unsigned long F_5 ( const struct V_2 * V_7 )
{
return ( 1ul << V_7 -> V_8 ) & ~ ( 1ul ) ;
}
static inline unsigned long F_6 ( T_1 V_9 , struct V_2 * V_3 )
{
unsigned long V_10 = V_9 ^ V_3 -> V_9 ;
if ( ( V_11 <= V_12 ) && ( V_12 == V_3 -> V_13 ) )
return 0 ;
return V_10 >> V_3 -> V_13 ;
}
static void F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_2 ( V_15 , struct V_16 , V_18 ) ;
F_8 ( V_19 , V_17 ) ;
}
static inline void F_9 ( struct V_16 * V_17 )
{
F_10 ( & V_17 -> V_18 , F_7 ) ;
}
static void F_11 ( struct V_14 * V_15 )
{
struct V_1 * V_4 = F_2 ( V_15 , struct V_1 , V_18 ) ;
if ( ! V_4 -> V_20 )
F_8 ( V_21 , V_4 ) ;
else
F_12 ( V_4 ) ;
}
static struct V_1 * F_13 ( int V_8 )
{
T_2 V_22 ;
if ( V_8 > V_23 )
return NULL ;
V_22 = F_14 ( 1ul << V_8 ) ;
if ( V_22 <= V_24 )
return F_15 ( V_22 , V_25 ) ;
else
return F_16 ( V_22 ) ;
}
static inline void F_17 ( struct V_2 * V_4 )
{
++ F_1 ( V_4 ) -> V_26 ? : ++ F_1 ( V_4 ) -> V_27 ;
}
static inline void F_18 ( struct V_2 * V_4 )
{
F_1 ( V_4 ) -> V_26 -- ? : F_1 ( V_4 ) -> V_27 -- ;
}
static struct V_2 * F_19 ( T_1 V_9 , struct V_16 * V_17 )
{
struct V_2 * V_28 ;
struct V_1 * V_3 ;
V_3 = F_20 ( V_21 , V_25 ) ;
if ( ! V_3 )
return NULL ;
V_28 = V_3 -> V_3 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_13 = 0 ;
V_28 -> V_8 = 0 ;
V_28 -> V_29 = V_17 -> V_30 ;
F_21 ( & V_28 -> V_31 ) ;
F_22 ( & V_17 -> V_32 , & V_28 -> V_31 ) ;
return V_28 ;
}
static struct V_2 * F_23 ( T_1 V_9 , int V_13 , int V_8 )
{
unsigned int V_33 = V_13 + V_8 ;
struct V_2 * V_7 ;
struct V_1 * V_1 ;
F_24 ( ! V_8 || ( V_33 > V_12 ) ) ;
V_1 = F_13 ( V_8 ) ;
if ( ! V_1 )
return NULL ;
F_25 ( L_1 , V_1 , F_14 ( 0 ) ,
sizeof( struct V_2 * ) << V_8 ) ;
if ( V_8 == V_12 )
V_1 -> V_27 = 1 ;
else
V_1 -> V_26 = 1ul << V_8 ;
V_7 = V_1 -> V_3 ;
V_7 -> V_9 = ( V_33 < V_12 ) ? ( V_9 >> V_33 ) << V_33 : 0 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_8 = V_8 ;
V_7 -> V_29 = V_13 ;
return V_7 ;
}
static inline int F_26 ( struct V_2 * V_7 , struct V_2 * V_4 )
{
return V_4 && ( ( V_4 -> V_13 + V_4 -> V_8 ) == V_7 -> V_13 ) && F_27 ( V_4 ) ;
}
static void F_28 ( struct V_2 * V_7 , unsigned long V_34 ,
struct V_2 * V_4 )
{
struct V_2 * V_35 = F_29 ( V_7 , V_34 ) ;
int V_36 , V_37 ;
F_24 ( V_34 >= F_5 ( V_7 ) ) ;
if ( ! V_4 && V_35 )
F_17 ( V_7 ) ;
if ( V_4 && ! V_35 )
F_18 ( V_7 ) ;
V_37 = F_26 ( V_7 , V_35 ) ;
V_36 = F_26 ( V_7 , V_4 ) ;
if ( V_37 && ! V_36 )
F_1 ( V_7 ) -> V_27 -- ;
else if ( ! V_37 && V_36 )
F_1 ( V_7 ) -> V_27 ++ ;
if ( V_4 && ( V_7 -> V_29 < V_4 -> V_29 ) )
V_7 -> V_29 = V_4 -> V_29 ;
F_4 ( V_7 -> V_1 [ V_34 ] , V_4 ) ;
}
static void F_30 ( struct V_2 * V_7 )
{
unsigned long V_34 ;
for ( V_34 = F_5 ( V_7 ) ; V_34 ; ) {
struct V_2 * V_38 = F_29 ( V_7 , -- V_34 ) ;
if ( ! V_38 )
continue;
if ( F_31 ( V_38 ) == V_7 )
F_30 ( V_38 ) ;
else
F_3 ( V_38 , V_7 ) ;
}
}
static inline void F_32 ( struct V_2 * V_5 , T_1 V_9 ,
struct V_2 * V_4 )
{
if ( F_33 ( V_5 ) )
F_4 ( V_5 -> V_1 [ 0 ] , V_4 ) ;
else
F_28 ( V_5 , F_6 ( V_9 , V_5 ) , V_4 ) ;
}
static inline void F_34 ( struct V_2 * V_7 )
{
F_1 ( V_7 ) -> V_18 . V_39 = NULL ;
}
static inline void F_35 ( struct V_2 * V_7 ,
struct V_2 * V_4 )
{
F_1 ( V_4 ) -> V_18 . V_39 = F_1 ( V_7 ) -> V_18 . V_39 ;
F_1 ( V_7 ) -> V_18 . V_39 = & F_1 ( V_4 ) -> V_18 ;
}
static void F_36 ( struct V_2 * V_7 )
{
struct V_40 * V_15 = & F_1 ( V_7 ) -> V_18 ;
while ( V_15 ) {
V_15 = V_15 -> V_39 ;
V_41 += F_14 ( 1ul << V_7 -> V_8 ) ;
F_37 ( V_7 ) ;
V_7 = F_2 ( V_15 , struct V_1 , V_18 ) -> V_3 ;
}
if ( V_41 >= V_24 * V_42 ) {
V_41 = 0 ;
F_38 () ;
}
}
static struct V_2 * F_39 ( struct V_43 * V_44 ,
struct V_2 * V_45 ,
struct V_2 * V_7 )
{
struct V_2 * V_5 = F_31 ( V_45 ) ;
unsigned long V_34 ;
F_40 ( V_7 , V_5 ) ;
F_32 ( V_5 , V_7 -> V_9 , V_7 ) ;
F_30 ( V_7 ) ;
F_36 ( V_45 ) ;
for ( V_34 = F_5 ( V_7 ) ; V_34 ; ) {
struct V_2 * V_38 = F_29 ( V_7 , -- V_34 ) ;
if ( F_26 ( V_7 , V_38 ) )
V_7 = F_41 ( V_44 , V_38 ) ;
}
return V_5 ;
}
static struct V_2 * F_42 ( struct V_43 * V_44 ,
struct V_2 * V_45 )
{
struct V_2 * V_7 ;
unsigned long V_34 ;
T_1 V_46 ;
F_25 ( L_2 ) ;
V_7 = F_23 ( V_45 -> V_9 , V_45 -> V_13 - 1 , V_45 -> V_8 + 1 ) ;
if ( ! V_7 )
goto V_47;
F_34 ( V_45 ) ;
for ( V_34 = F_5 ( V_45 ) , V_46 = 1u << V_7 -> V_13 ; V_34 ; ) {
struct V_2 * V_38 = F_29 ( V_45 , -- V_34 ) ;
struct V_2 * V_48 , * V_49 ;
unsigned long V_50 , V_51 ;
if ( ! V_38 )
continue;
if ( ! F_26 ( V_45 , V_38 ) ) {
F_28 ( V_7 , F_6 ( V_38 -> V_9 , V_7 ) , V_38 ) ;
continue;
}
F_35 ( V_45 , V_38 ) ;
if ( V_38 -> V_8 == 1 ) {
F_28 ( V_7 , 2 * V_34 + 1 , F_29 ( V_38 , 1 ) ) ;
F_28 ( V_7 , 2 * V_34 , F_29 ( V_38 , 0 ) ) ;
continue;
}
V_49 = F_23 ( V_38 -> V_9 | V_46 , V_38 -> V_13 , V_38 -> V_8 - 1 ) ;
if ( ! V_49 )
goto V_52;
V_48 = F_23 ( V_38 -> V_9 , V_38 -> V_13 , V_38 -> V_8 - 1 ) ;
F_35 ( V_7 , V_49 ) ;
if ( ! V_48 )
goto V_52;
F_35 ( V_7 , V_48 ) ;
for ( V_51 = F_5 ( V_38 ) , V_50 = V_51 / 2 ; V_50 ; ) {
F_28 ( V_49 , -- V_50 , F_29 ( V_38 , -- V_51 ) ) ;
F_28 ( V_48 , V_50 , F_29 ( V_38 , V_50 ) ) ;
F_28 ( V_49 , -- V_50 , F_29 ( V_38 , -- V_51 ) ) ;
F_28 ( V_48 , V_50 , F_29 ( V_38 , V_50 ) ) ;
}
F_40 ( V_49 , V_7 ) ;
F_40 ( V_48 , V_7 ) ;
F_28 ( V_7 , 2 * V_34 + 1 , V_49 ) ;
F_28 ( V_7 , 2 * V_34 , V_48 ) ;
}
return F_39 ( V_44 , V_45 , V_7 ) ;
V_52:
F_36 ( V_7 ) ;
V_47:
return NULL ;
}
static struct V_2 * F_43 ( struct V_43 * V_44 ,
struct V_2 * V_45 )
{
struct V_2 * V_7 ;
unsigned long V_34 ;
F_25 ( L_3 ) ;
V_7 = F_23 ( V_45 -> V_9 , V_45 -> V_13 + 1 , V_45 -> V_8 - 1 ) ;
if ( ! V_7 )
goto V_47;
F_34 ( V_45 ) ;
for ( V_34 = F_5 ( V_45 ) ; V_34 ; ) {
struct V_2 * V_49 = F_29 ( V_45 , -- V_34 ) ;
struct V_2 * V_48 = F_29 ( V_45 , -- V_34 ) ;
struct V_2 * V_38 ;
if ( ! V_49 || ! V_48 ) {
F_28 ( V_7 , V_34 / 2 , V_49 ? : V_48 ) ;
continue;
}
V_38 = F_23 ( V_48 -> V_9 , V_45 -> V_13 , 1 ) ;
if ( ! V_38 )
goto V_52;
F_35 ( V_7 , V_38 ) ;
F_28 ( V_38 , 1 , V_49 ) ;
F_28 ( V_38 , 0 , V_48 ) ;
F_40 ( V_38 , V_7 ) ;
F_28 ( V_7 , V_34 / 2 , V_38 ) ;
}
return F_39 ( V_44 , V_45 , V_7 ) ;
V_52:
F_36 ( V_7 ) ;
V_47:
return NULL ;
}
static struct V_2 * F_44 ( struct V_43 * V_44 ,
struct V_2 * V_45 )
{
struct V_2 * V_4 , * V_5 ;
unsigned long V_34 ;
for ( V_4 = NULL , V_34 = F_5 ( V_45 ) ; ! V_4 && V_34 ; )
V_4 = F_29 ( V_45 , -- V_34 ) ;
V_5 = F_31 ( V_45 ) ;
F_32 ( V_5 , V_45 -> V_9 , V_4 ) ;
F_3 ( V_4 , V_5 ) ;
F_37 ( V_45 ) ;
return V_5 ;
}
static unsigned char F_45 ( struct V_2 * V_7 )
{
unsigned char V_29 = V_7 -> V_13 ;
unsigned long V_53 , V_34 ;
for ( V_34 = 0 , V_53 = 0x2ul ; V_34 < F_5 ( V_7 ) ; V_34 += V_53 ) {
struct V_2 * V_4 = F_29 ( V_7 , V_34 ) ;
if ( ! V_4 || ( V_4 -> V_29 <= V_29 ) )
continue;
V_53 <<= ( V_4 -> V_29 - V_29 ) ;
V_29 = V_4 -> V_29 ;
V_34 &= ~ ( V_53 - 1 ) ;
if ( ( V_29 + 1 ) >= ( V_7 -> V_13 + V_7 -> V_8 ) )
break;
}
V_7 -> V_29 = V_29 ;
return V_29 ;
}
static inline bool F_46 ( struct V_2 * V_5 , struct V_2 * V_7 )
{
unsigned long V_54 = F_5 ( V_7 ) ;
unsigned long V_55 = V_54 ;
V_55 *= F_33 ( V_5 ) ? V_56 : V_57 ;
V_54 -= F_1 ( V_7 ) -> V_26 ;
V_54 += F_1 ( V_7 ) -> V_27 ;
return ( V_54 > 1 ) && V_7 -> V_13 && ( ( 50 * V_54 ) >= V_55 ) ;
}
static inline bool F_47 ( struct V_2 * V_5 , struct V_2 * V_7 )
{
unsigned long V_54 = F_5 ( V_7 ) ;
unsigned long V_55 = V_54 ;
V_55 *= F_33 ( V_5 ) ? V_58 : V_59 ;
V_54 -= F_1 ( V_7 ) -> V_26 ;
return ( V_54 > 1 ) && ( V_7 -> V_8 > 1 ) && ( ( 100 * V_54 ) < V_55 ) ;
}
static inline bool F_48 ( struct V_2 * V_7 )
{
unsigned long V_54 = F_5 ( V_7 ) ;
V_54 -= F_1 ( V_7 ) -> V_26 ;
if ( ( V_7 -> V_8 == V_12 ) && F_1 ( V_7 ) -> V_27 )
V_54 -= V_60 ;
return V_54 < 2 ;
}
static struct V_2 * F_41 ( struct V_43 * V_44 , struct V_2 * V_7 )
{
#ifdef F_49
struct V_61 T_3 * V_62 = V_44 -> V_62 ;
#endif
struct V_2 * V_5 = F_31 ( V_7 ) ;
unsigned long V_63 = F_6 ( V_7 -> V_9 , V_5 ) ;
int V_64 = V_65 ;
F_25 ( L_4 ,
V_7 , V_57 , V_59 ) ;
F_24 ( V_7 != F_29 ( V_5 , V_63 ) ) ;
while ( F_46 ( V_5 , V_7 ) && V_64 ) {
V_5 = F_42 ( V_44 , V_7 ) ;
if ( ! V_5 ) {
#ifdef F_49
F_50 ( V_62 -> V_66 ) ;
#endif
break;
}
V_64 -- ;
V_7 = F_29 ( V_5 , V_63 ) ;
}
V_5 = F_31 ( V_7 ) ;
if ( V_64 != V_65 )
return V_5 ;
while ( F_47 ( V_5 , V_7 ) && V_64 ) {
V_5 = F_43 ( V_44 , V_7 ) ;
if ( ! V_5 ) {
#ifdef F_49
F_50 ( V_62 -> V_66 ) ;
#endif
break;
}
V_64 -- ;
V_7 = F_29 ( V_5 , V_63 ) ;
}
if ( F_48 ( V_7 ) )
return F_44 ( V_44 , V_7 ) ;
V_5 = F_31 ( V_7 ) ;
if ( V_64 != V_65 )
return V_5 ;
if ( V_7 -> V_29 > V_7 -> V_13 ) {
unsigned char V_29 = F_45 ( V_7 ) ;
if ( V_29 > V_5 -> V_29 )
V_5 -> V_29 = V_29 ;
}
return V_5 ;
}
static void F_51 ( struct V_2 * V_5 , struct V_2 * V_28 )
{
while ( ( V_5 -> V_29 > V_5 -> V_13 ) && ( V_5 -> V_29 > V_28 -> V_29 ) ) {
if ( F_45 ( V_5 ) > V_28 -> V_29 )
break;
V_5 = F_31 ( V_5 ) ;
}
}
static void F_52 ( struct V_2 * V_7 , struct V_2 * V_28 )
{
while ( V_7 -> V_29 < V_28 -> V_29 ) {
V_7 -> V_29 = V_28 -> V_29 ;
V_7 = F_31 ( V_7 ) ;
}
}
static struct V_2 * F_53 ( struct V_43 * V_44 ,
struct V_2 * * V_5 , T_4 V_9 )
{
struct V_2 * V_67 , * V_4 = V_44 -> V_3 ;
unsigned long V_10 = 0 ;
do {
V_67 = V_4 ;
V_4 = F_54 ( V_4 , V_10 ) ;
if ( ! V_4 )
break;
V_10 = F_55 ( V_9 , V_4 ) ;
if ( V_10 >= ( 1ul << V_4 -> V_8 ) ) {
V_4 = NULL ;
break;
}
} while ( F_27 ( V_4 ) );
* V_5 = V_67 ;
return V_4 ;
}
static struct V_16 * F_56 ( struct V_68 * V_69 , T_5 V_29 ,
T_5 V_70 , T_4 V_71 , T_4 V_72 )
{
struct V_16 * V_17 ;
if ( ! V_69 )
return NULL ;
F_57 (fa, fah, fa_list) {
if ( V_17 -> V_30 < V_29 )
continue;
if ( V_17 -> V_30 != V_29 )
break;
if ( V_17 -> V_72 > V_72 )
continue;
if ( V_17 -> V_72 != V_72 )
break;
if ( V_17 -> V_73 > V_70 )
continue;
if ( V_17 -> V_74 -> V_75 >= V_71 || V_17 -> V_73 < V_70 )
return V_17 ;
}
return NULL ;
}
static void F_58 ( struct V_43 * V_44 , struct V_2 * V_7 )
{
while ( ! F_33 ( V_7 ) )
V_7 = F_41 ( V_44 , V_7 ) ;
}
static int F_59 ( struct V_43 * V_44 , struct V_2 * V_5 ,
struct V_16 * V_76 , T_1 V_9 )
{
struct V_2 * V_4 , * V_28 ;
V_28 = F_19 ( V_9 , V_76 ) ;
if ( ! V_28 )
goto V_77;
V_4 = F_29 ( V_5 , F_6 ( V_9 , V_5 ) ) ;
if ( V_4 ) {
struct V_2 * V_7 ;
V_7 = F_23 ( V_9 , F_60 ( V_9 ^ V_4 -> V_9 ) , 1 ) ;
if ( ! V_7 )
goto V_47;
F_40 ( V_7 , V_5 ) ;
F_28 ( V_7 , F_6 ( V_9 , V_7 ) ^ 1 , V_4 ) ;
F_32 ( V_5 , V_9 , V_7 ) ;
F_3 ( V_4 , V_7 ) ;
V_5 = V_7 ;
}
F_40 ( V_28 , V_5 ) ;
F_32 ( V_5 , V_9 , V_28 ) ;
F_58 ( V_44 , V_5 ) ;
return 0 ;
V_47:
F_37 ( V_28 ) ;
V_77:
return - V_78 ;
}
static int F_61 ( struct V_43 * V_44 , struct V_2 * V_5 ,
struct V_2 * V_28 , struct V_16 * V_76 ,
struct V_16 * V_17 , T_1 V_9 )
{
if ( ! V_28 )
return F_59 ( V_44 , V_5 , V_76 , V_9 ) ;
if ( V_17 ) {
F_62 ( & V_76 -> V_32 , & V_17 -> V_32 ) ;
} else {
struct V_16 * V_79 ;
F_57 (last, &l->leaf, fa_list) {
if ( V_76 -> V_30 < V_79 -> V_30 )
break;
if ( ( V_76 -> V_30 == V_79 -> V_30 ) &&
( V_76 -> V_72 > V_79 -> V_72 ) )
break;
V_17 = V_79 ;
}
if ( V_17 )
F_63 ( & V_76 -> V_32 , & V_17 -> V_32 ) ;
else
F_64 ( & V_76 -> V_32 , & V_28 -> V_31 ) ;
}
if ( V_28 -> V_29 < V_76 -> V_30 ) {
V_28 -> V_29 = V_76 -> V_30 ;
F_52 ( V_5 , V_28 ) ;
}
return 0 ;
}
int F_65 ( struct V_80 * V_81 , struct V_82 * V_83 )
{
struct V_43 * V_44 = (struct V_43 * ) V_81 -> V_84 ;
struct V_16 * V_17 , * V_85 ;
struct V_2 * V_28 , * V_5 ;
unsigned int V_86 = 0 ;
struct V_87 * V_88 ;
T_5 V_89 = V_83 -> V_90 ;
T_5 V_29 = V_12 - V_89 ;
T_5 V_70 = V_83 -> V_91 ;
T_4 V_9 ;
int V_92 ;
if ( V_89 > V_12 )
return - V_93 ;
V_9 = F_66 ( V_83 -> V_94 ) ;
F_25 ( L_5 , V_81 -> V_72 , V_9 , V_89 ) ;
if ( ( V_89 < V_12 ) && ( V_9 << V_89 ) )
return - V_93 ;
V_88 = F_67 ( V_83 ) ;
if ( F_68 ( V_88 ) ) {
V_92 = F_69 ( V_88 ) ;
goto V_92;
}
V_28 = F_53 ( V_44 , & V_5 , V_9 ) ;
V_17 = V_28 ? F_56 ( & V_28 -> V_31 , V_29 , V_70 , V_88 -> V_75 ,
V_81 -> V_72 ) : NULL ;
if ( V_17 && V_17 -> V_73 == V_70 &&
V_17 -> V_74 -> V_75 == V_88 -> V_75 ) {
struct V_16 * V_95 , * V_96 ;
V_92 = - V_97 ;
if ( V_83 -> V_98 & V_99 )
goto V_100;
V_96 = NULL ;
V_95 = V_17 ;
F_70 (fa, fa_list) {
if ( ( V_17 -> V_30 != V_29 ) ||
( V_17 -> V_72 != V_81 -> V_72 ) ||
( V_17 -> V_73 != V_70 ) )
break;
if ( V_17 -> V_74 -> V_75 != V_88 -> V_75 )
break;
if ( V_17 -> V_101 == V_83 -> V_102 &&
V_17 -> V_74 == V_88 ) {
V_96 = V_17 ;
break;
}
}
if ( V_83 -> V_98 & V_103 ) {
struct V_87 * V_104 ;
T_5 V_105 ;
V_17 = V_95 ;
if ( V_96 ) {
if ( V_17 == V_96 )
V_92 = 0 ;
goto V_100;
}
V_92 = - V_106 ;
V_85 = F_20 ( V_19 , V_25 ) ;
if ( ! V_85 )
goto V_100;
V_104 = V_17 -> V_74 ;
V_85 -> V_73 = V_17 -> V_73 ;
V_85 -> V_74 = V_88 ;
V_85 -> V_101 = V_83 -> V_102 ;
V_105 = V_17 -> V_107 ;
V_85 -> V_107 = V_105 & ~ V_108 ;
V_85 -> V_30 = V_17 -> V_30 ;
V_85 -> V_72 = V_81 -> V_72 ;
V_85 -> V_109 = - 1 ;
V_92 = F_71 ( V_9 , V_89 , V_88 ,
V_85 -> V_73 ,
V_83 -> V_102 ,
V_83 -> V_98 ,
V_81 -> V_72 ) ;
if ( V_92 ) {
F_72 ( V_88 ) ;
F_8 ( V_19 , V_85 ) ;
goto V_100;
}
F_73 ( & V_17 -> V_32 , & V_85 -> V_32 ) ;
F_9 ( V_17 ) ;
F_74 ( V_104 ) ;
if ( V_105 & V_108 )
F_75 ( V_83 -> V_110 . V_111 ) ;
F_76 ( V_112 , F_77 ( V_9 ) , V_85 , V_89 ,
V_81 -> V_72 , & V_83 -> V_110 , V_103 ) ;
goto V_113;
}
if ( V_96 )
goto V_100;
if ( V_83 -> V_98 & V_114 )
V_86 = V_114 ;
else
V_17 = V_95 ;
}
V_92 = - V_115 ;
if ( ! ( V_83 -> V_98 & V_116 ) )
goto V_100;
V_92 = - V_106 ;
V_85 = F_20 ( V_19 , V_25 ) ;
if ( ! V_85 )
goto V_100;
V_85 -> V_74 = V_88 ;
V_85 -> V_73 = V_70 ;
V_85 -> V_101 = V_83 -> V_102 ;
V_85 -> V_107 = 0 ;
V_85 -> V_30 = V_29 ;
V_85 -> V_72 = V_81 -> V_72 ;
V_85 -> V_109 = - 1 ;
V_92 = F_71 ( V_9 , V_89 , V_88 , V_70 , V_83 -> V_102 ,
V_83 -> V_98 , V_81 -> V_72 ) ;
if ( V_92 ) {
F_72 ( V_88 ) ;
goto V_117;
}
V_92 = F_61 ( V_44 , V_5 , V_28 , V_85 , V_17 , V_9 ) ;
if ( V_92 )
goto V_118;
if ( ! V_89 )
V_81 -> V_119 ++ ;
F_75 ( V_83 -> V_110 . V_111 ) ;
F_76 ( V_112 , F_77 ( V_9 ) , V_85 , V_89 , V_85 -> V_72 ,
& V_83 -> V_110 , V_86 ) ;
V_113:
return 0 ;
V_118:
F_78 ( V_9 , V_89 , V_88 , V_70 , V_83 -> V_102 , V_81 -> V_72 ) ;
V_117:
F_8 ( V_19 , V_85 ) ;
V_100:
F_74 ( V_88 ) ;
V_92:
return V_92 ;
}
static inline T_1 F_79 ( T_1 V_9 , struct V_2 * V_4 )
{
T_1 V_120 = V_4 -> V_9 ;
return ( V_9 ^ V_120 ) & ( V_120 | - V_120 ) ;
}
int F_80 ( struct V_80 * V_81 , const struct V_121 * V_122 ,
struct V_123 * V_124 , int V_125 )
{
struct V_43 * V_44 = (struct V_43 * ) V_81 -> V_84 ;
#ifdef F_49
struct V_61 T_3 * V_62 = V_44 -> V_62 ;
#endif
const T_1 V_9 = F_66 ( V_122 -> V_126 ) ;
struct V_2 * V_4 , * V_67 ;
struct V_16 * V_17 ;
unsigned long V_10 ;
T_1 V_63 ;
F_81 ( V_81 -> V_72 , V_122 ) ;
V_67 = V_44 -> V_3 ;
V_63 = 0 ;
V_4 = F_54 ( V_67 , V_63 ) ;
if ( ! V_4 )
return - V_127 ;
#ifdef F_49
F_50 ( V_62 -> gets ) ;
#endif
for (; ; ) {
V_10 = F_55 ( V_9 , V_4 ) ;
if ( V_10 >= ( 1ul << V_4 -> V_8 ) )
break;
if ( F_82 ( V_4 ) )
goto V_128;
if ( V_4 -> V_29 > V_4 -> V_13 ) {
V_67 = V_4 ;
V_63 = V_10 ;
}
V_4 = F_54 ( V_4 , V_10 ) ;
if ( F_83 ( ! V_4 ) )
goto V_129;
}
for (; ; ) {
struct V_2 T_6 * * V_130 = V_4 -> V_1 ;
if ( F_83 ( F_79 ( V_9 , V_4 ) ) || ( V_4 -> V_29 == V_4 -> V_13 ) )
goto V_129;
if ( F_83 ( F_82 ( V_4 ) ) )
break;
while ( ( V_4 = F_84 ( * V_130 ) ) == NULL ) {
V_129:
#ifdef F_49
if ( ! V_4 )
F_50 ( V_62 -> V_131 ) ;
#endif
while ( ! V_63 ) {
T_1 V_132 = V_67 -> V_9 ;
if ( F_33 ( V_67 ) )
return - V_127 ;
#ifdef F_49
F_50 ( V_62 -> V_133 ) ;
#endif
V_67 = F_85 ( V_67 ) ;
V_63 = F_6 ( V_132 , V_67 ) ;
}
V_63 &= V_63 - 1 ;
V_130 = & V_67 -> V_1 [ V_63 ] ;
}
}
V_128:
V_10 = V_9 ^ V_4 -> V_9 ;
F_86 (fa, &n->leaf, fa_list) {
struct V_87 * V_88 = V_17 -> V_74 ;
int V_134 , V_92 ;
if ( ( V_11 > V_12 ) || ( V_17 -> V_30 < V_12 ) ) {
if ( V_10 >= ( 1ul << V_17 -> V_30 ) )
continue;
}
if ( V_17 -> V_73 && V_17 -> V_73 != V_122 -> V_135 )
continue;
if ( V_88 -> V_136 )
continue;
if ( V_17 -> V_74 -> V_137 < V_122 -> V_138 )
continue;
F_87 ( V_17 ) ;
V_92 = V_139 [ V_17 -> V_101 ] . error ;
if ( F_83 ( V_92 < 0 ) ) {
#ifdef F_49
F_50 ( V_62 -> V_140 ) ;
#endif
return V_92 ;
}
if ( V_88 -> V_125 & V_141 )
continue;
for ( V_134 = 0 ; V_134 < V_88 -> V_142 ; V_134 ++ ) {
const struct V_143 * V_144 = & V_88 -> V_143 [ V_134 ] ;
struct V_145 * V_146 = F_88 ( V_144 -> V_147 ) ;
if ( V_144 -> V_148 & V_141 )
continue;
if ( V_146 &&
F_89 ( V_146 ) &&
V_144 -> V_148 & V_149 &&
! ( V_125 & V_150 ) )
continue;
if ( ! ( V_122 -> V_151 & V_152 ) ) {
if ( V_122 -> V_153 &&
V_122 -> V_153 != V_144 -> V_154 )
continue;
}
if ( ! ( V_125 & V_155 ) )
F_90 ( & V_88 -> V_156 ) ;
V_124 -> V_157 = V_12 - V_17 -> V_30 ;
V_124 -> V_158 = V_134 ;
V_124 -> type = V_17 -> V_101 ;
V_124 -> V_159 = V_88 -> V_137 ;
V_124 -> V_88 = V_88 ;
V_124 -> V_160 = V_81 ;
V_124 -> V_161 = & V_4 -> V_31 ;
#ifdef F_49
F_50 ( V_62 -> V_140 ) ;
#endif
F_91 ( V_144 ) ;
return V_92 ;
}
}
#ifdef F_49
F_50 ( V_62 -> V_162 ) ;
#endif
goto V_129;
}
static void F_92 ( struct V_43 * V_44 , struct V_2 * V_5 ,
struct V_2 * V_28 , struct V_16 * V_163 )
{
struct V_164 * * V_165 = V_163 -> V_32 . V_165 ;
struct V_16 * V_17 = F_93 ( V_165 , F_94 ( * V_17 ) , V_32 . V_39 ) ;
F_95 ( & V_163 -> V_32 ) ;
if ( F_96 ( & V_28 -> V_31 ) ) {
F_32 ( V_5 , V_28 -> V_9 , NULL ) ;
F_37 ( V_28 ) ;
F_58 ( V_44 , V_5 ) ;
return;
}
if ( * V_165 )
return;
V_28 -> V_29 = V_17 -> V_30 ;
F_51 ( V_5 , V_28 ) ;
}
int F_97 ( struct V_80 * V_81 , struct V_82 * V_83 )
{
struct V_43 * V_44 = (struct V_43 * ) V_81 -> V_84 ;
struct V_16 * V_17 , * V_166 ;
struct V_2 * V_28 , * V_5 ;
T_5 V_89 = V_83 -> V_90 ;
T_5 V_29 = V_12 - V_89 ;
T_5 V_70 = V_83 -> V_91 ;
T_4 V_9 ;
if ( V_89 > V_12 )
return - V_93 ;
V_9 = F_66 ( V_83 -> V_94 ) ;
if ( ( V_89 < V_12 ) && ( V_9 << V_89 ) )
return - V_93 ;
V_28 = F_53 ( V_44 , & V_5 , V_9 ) ;
if ( ! V_28 )
return - V_167 ;
V_17 = F_56 ( & V_28 -> V_31 , V_29 , V_70 , 0 , V_81 -> V_72 ) ;
if ( ! V_17 )
return - V_167 ;
F_25 ( L_6 , V_9 , V_89 , V_70 , V_44 ) ;
V_166 = NULL ;
F_70 (fa, fa_list) {
struct V_87 * V_88 = V_17 -> V_74 ;
if ( ( V_17 -> V_30 != V_29 ) ||
( V_17 -> V_72 != V_81 -> V_72 ) ||
( V_17 -> V_73 != V_70 ) )
break;
if ( ( ! V_83 -> V_102 || V_17 -> V_101 == V_83 -> V_102 ) &&
( V_83 -> V_168 == V_169 ||
V_17 -> V_74 -> V_137 == V_83 -> V_168 ) &&
( ! V_83 -> V_170 ||
V_88 -> V_171 == V_83 -> V_170 ) &&
( ! V_83 -> V_172 ||
V_88 -> V_173 == V_83 -> V_172 ) &&
F_98 ( V_83 , V_88 ) == 0 ) {
V_166 = V_17 ;
break;
}
}
if ( ! V_166 )
return - V_167 ;
F_78 ( V_9 , V_89 , V_166 -> V_74 , V_70 ,
V_83 -> V_102 , V_81 -> V_72 ) ;
F_76 ( V_174 , F_77 ( V_9 ) , V_166 , V_89 , V_81 -> V_72 ,
& V_83 -> V_110 , 0 ) ;
if ( ! V_89 )
V_81 -> V_119 -- ;
F_92 ( V_44 , V_5 , V_28 , V_166 ) ;
if ( V_166 -> V_107 & V_108 )
F_75 ( V_83 -> V_110 . V_111 ) ;
F_74 ( V_166 -> V_74 ) ;
F_9 ( V_166 ) ;
return 0 ;
}
static struct V_2 * F_99 ( struct V_2 * * V_7 , T_1 V_9 )
{
struct V_2 * V_67 , * V_4 = * V_7 ;
unsigned long V_63 ;
do {
V_67 = V_4 ;
V_63 = ( V_9 > V_67 -> V_9 ) ? F_6 ( V_9 , V_67 ) : 0 ;
if ( V_63 >> V_67 -> V_8 )
break;
V_4 = F_54 ( V_67 , V_63 ++ ) ;
if ( ! V_4 )
break;
if ( F_82 ( V_4 ) && ( V_4 -> V_9 >= V_9 ) )
goto V_128;
} while ( F_27 ( V_4 ) );
while ( ! F_33 ( V_67 ) ) {
if ( V_63 >= ( 1ul << V_67 -> V_8 ) ) {
T_1 V_132 = V_67 -> V_9 ;
V_67 = F_85 ( V_67 ) ;
V_63 = F_6 ( V_132 , V_67 ) + 1 ;
continue;
}
V_4 = F_54 ( V_67 , V_63 ++ ) ;
if ( ! V_4 )
continue;
if ( F_82 ( V_4 ) )
goto V_128;
V_67 = V_4 ;
V_63 = 0 ;
}
* V_7 = V_67 ;
return NULL ;
V_128:
* V_7 = V_67 ;
return V_4 ;
}
static void F_100 ( struct V_80 * V_81 )
{
struct V_43 * V_44 = (struct V_43 * ) V_81 -> V_84 ;
struct V_2 * V_67 = V_44 -> V_3 ;
unsigned long V_63 = 1 ;
struct V_164 * V_175 ;
struct V_16 * V_17 ;
for (; ; ) {
struct V_2 * V_4 ;
if ( ! ( V_63 -- ) ) {
T_1 V_132 = V_67 -> V_9 ;
if ( F_33 ( V_67 ) )
break;
V_4 = V_67 ;
V_67 = F_31 ( V_67 ) ;
F_32 ( V_67 , V_4 -> V_9 , NULL ) ;
F_37 ( V_4 ) ;
V_63 = F_6 ( V_132 , V_67 ) ;
continue;
}
V_4 = F_29 ( V_67 , V_63 ) ;
if ( ! V_4 )
continue;
if ( F_27 ( V_4 ) ) {
V_67 = V_4 ;
V_63 = 1ul << V_4 -> V_8 ;
continue;
}
F_101 (fa, tmp, &n->leaf, fa_list) {
F_95 ( & V_17 -> V_32 ) ;
F_9 ( V_17 ) ;
}
F_32 ( V_67 , V_4 -> V_9 , NULL ) ;
F_37 ( V_4 ) ;
}
#ifdef F_49
F_102 ( V_44 -> V_62 ) ;
#endif
F_103 ( V_81 ) ;
}
struct V_80 * F_104 ( struct V_80 * V_176 )
{
struct V_43 * V_177 = (struct V_43 * ) V_176 -> V_84 ;
struct V_2 * V_28 , * V_5 = V_177 -> V_3 ;
struct V_80 * V_178 ;
struct V_16 * V_17 ;
struct V_43 * V_179 ;
T_1 V_9 = 0 ;
if ( V_176 -> V_84 == V_176 -> V_180 )
return V_176 ;
V_178 = F_105 ( V_181 , NULL ) ;
if ( ! V_178 )
return NULL ;
V_179 = (struct V_43 * ) V_178 -> V_84 ;
while ( ( V_28 = F_99 ( & V_5 , V_9 ) ) != NULL ) {
struct V_2 * V_182 = NULL , * V_183 ;
F_86 (fa, &l->leaf, fa_list) {
struct V_16 * V_85 ;
if ( V_178 -> V_72 != V_17 -> V_72 )
continue;
V_85 = F_20 ( V_19 , V_25 ) ;
if ( ! V_85 )
goto V_100;
memcpy ( V_85 , V_17 , sizeof( * V_17 ) ) ;
if ( ! V_182 )
V_182 = F_53 ( V_179 , & V_183 , V_28 -> V_9 ) ;
if ( F_61 ( V_179 , V_183 , V_182 , V_85 ,
NULL , V_28 -> V_9 ) )
goto V_100;
}
V_9 = V_28 -> V_9 + 1 ;
if ( V_9 < V_28 -> V_9 )
break;
}
return V_178 ;
V_100:
F_100 ( V_178 ) ;
return NULL ;
}
void F_106 ( struct V_80 * V_81 )
{
struct V_43 * V_44 = (struct V_43 * ) V_81 -> V_84 ;
struct V_2 * V_67 = V_44 -> V_3 ;
unsigned long V_63 = 1 ;
struct V_164 * V_175 ;
struct V_16 * V_17 ;
for (; ; ) {
unsigned char V_29 = 0 ;
struct V_2 * V_4 ;
if ( ! ( V_63 -- ) ) {
T_1 V_132 = V_67 -> V_9 ;
if ( F_33 ( V_67 ) )
break;
V_67 = F_41 ( V_44 , V_67 ) ;
V_63 = F_6 ( V_132 , V_67 ) ;
continue;
}
V_4 = F_29 ( V_67 , V_63 ) ;
if ( ! V_4 )
continue;
if ( F_27 ( V_4 ) ) {
V_67 = V_4 ;
V_63 = 1ul << V_4 -> V_8 ;
continue;
}
F_101 (fa, tmp, &n->leaf, fa_list) {
struct V_87 * V_88 = V_17 -> V_74 ;
if ( V_81 -> V_72 != V_17 -> V_72 ) {
F_95 ( & V_17 -> V_32 ) ;
F_9 ( V_17 ) ;
continue;
}
V_29 = V_17 -> V_30 ;
if ( ! V_88 || ! ( V_88 -> V_125 & V_184 ) )
continue;
F_78 ( V_4 -> V_9 , V_12 - V_17 -> V_30 ,
V_88 , V_17 -> V_73 , V_17 -> V_101 ,
V_81 -> V_72 ) ;
}
V_4 -> V_29 = V_29 ;
if ( F_96 ( & V_4 -> V_31 ) ) {
F_32 ( V_67 , V_4 -> V_9 , NULL ) ;
F_37 ( V_4 ) ;
}
}
}
int F_107 ( struct V_80 * V_81 )
{
struct V_43 * V_44 = (struct V_43 * ) V_81 -> V_84 ;
struct V_2 * V_67 = V_44 -> V_3 ;
unsigned long V_63 = 1 ;
struct V_164 * V_175 ;
struct V_16 * V_17 ;
int V_128 = 0 ;
for (; ; ) {
unsigned char V_29 = 0 ;
struct V_2 * V_4 ;
if ( ! ( V_63 -- ) ) {
T_1 V_132 = V_67 -> V_9 ;
if ( F_33 ( V_67 ) )
break;
V_67 = F_41 ( V_44 , V_67 ) ;
V_63 = F_6 ( V_132 , V_67 ) ;
continue;
}
V_4 = F_29 ( V_67 , V_63 ) ;
if ( ! V_4 )
continue;
if ( F_27 ( V_4 ) ) {
V_67 = V_4 ;
V_63 = 1ul << V_4 -> V_8 ;
continue;
}
F_101 (fa, tmp, &n->leaf, fa_list) {
struct V_87 * V_88 = V_17 -> V_74 ;
if ( ! V_88 || ! ( V_88 -> V_125 & V_141 ) ) {
V_29 = V_17 -> V_30 ;
continue;
}
F_78 ( V_4 -> V_9 , V_12 - V_17 -> V_30 ,
V_88 , V_17 -> V_73 , V_17 -> V_101 ,
V_81 -> V_72 ) ;
F_95 ( & V_17 -> V_32 ) ;
F_74 ( V_17 -> V_74 ) ;
F_9 ( V_17 ) ;
V_128 ++ ;
}
V_4 -> V_29 = V_29 ;
if ( F_96 ( & V_4 -> V_31 ) ) {
F_32 ( V_67 , V_4 -> V_9 , NULL ) ;
F_37 ( V_4 ) ;
}
}
F_25 ( L_7 , V_128 ) ;
return V_128 ;
}
static void F_108 ( struct V_14 * V_15 )
{
struct V_80 * V_81 = F_2 ( V_15 , struct V_80 , V_18 ) ;
#ifdef F_49
struct V_43 * V_44 = (struct V_43 * ) V_81 -> V_84 ;
if ( V_81 -> V_84 == V_81 -> V_180 )
F_102 ( V_44 -> V_62 ) ;
#endif
F_103 ( V_81 ) ;
}
void F_109 ( struct V_80 * V_81 )
{
F_10 ( & V_81 -> V_18 , F_108 ) ;
}
static int F_110 ( struct V_2 * V_28 , struct V_80 * V_81 ,
struct V_185 * V_186 , struct V_187 * V_188 )
{
T_7 V_189 = F_77 ( V_28 -> V_9 ) ;
struct V_16 * V_17 ;
int V_34 , V_190 ;
V_190 = V_188 -> args [ 4 ] ;
V_34 = 0 ;
F_86 (fa, &l->leaf, fa_list) {
if ( V_34 < V_190 ) {
V_34 ++ ;
continue;
}
if ( V_81 -> V_72 != V_17 -> V_72 ) {
V_34 ++ ;
continue;
}
if ( F_111 ( V_186 , F_112 ( V_188 -> V_186 ) . V_191 ,
V_188 -> V_192 -> V_193 ,
V_112 ,
V_81 -> V_72 ,
V_17 -> V_101 ,
V_189 ,
V_12 - V_17 -> V_30 ,
V_17 -> V_73 ,
V_17 -> V_74 , V_194 ) < 0 ) {
V_188 -> args [ 4 ] = V_34 ;
return - 1 ;
}
V_34 ++ ;
}
V_188 -> args [ 4 ] = V_34 ;
return V_186 -> V_195 ;
}
int F_113 ( struct V_80 * V_81 , struct V_185 * V_186 ,
struct V_187 * V_188 )
{
struct V_43 * V_44 = (struct V_43 * ) V_81 -> V_84 ;
struct V_2 * V_28 , * V_5 = V_44 -> V_3 ;
int V_196 = V_188 -> args [ 2 ] ;
T_1 V_9 = V_188 -> args [ 3 ] ;
while ( ( V_28 = F_99 ( & V_5 , V_9 ) ) != NULL ) {
if ( F_110 ( V_28 , V_81 , V_186 , V_188 ) < 0 ) {
V_188 -> args [ 3 ] = V_9 ;
V_188 -> args [ 2 ] = V_196 ;
return - 1 ;
}
++ V_196 ;
V_9 = V_28 -> V_9 + 1 ;
memset ( & V_188 -> args [ 4 ] , 0 ,
sizeof( V_188 -> args ) - 4 * sizeof( V_188 -> args [ 0 ] ) ) ;
if ( V_9 < V_28 -> V_9 )
break;
}
V_188 -> args [ 3 ] = V_9 ;
V_188 -> args [ 2 ] = V_196 ;
return V_186 -> V_195 ;
}
void T_8 F_114 ( void )
{
V_19 = F_115 ( L_8 ,
sizeof( struct V_16 ) ,
0 , V_197 , NULL ) ;
V_21 = F_115 ( L_9 ,
V_198 ,
0 , V_197 , NULL ) ;
}
struct V_80 * F_105 ( T_4 V_199 , struct V_80 * V_200 )
{
struct V_80 * V_81 ;
struct V_43 * V_44 ;
T_2 V_201 = sizeof( * V_81 ) ;
if ( ! V_200 )
V_201 += sizeof( struct V_43 ) ;
V_81 = F_15 ( V_201 , V_25 ) ;
if ( ! V_81 )
return NULL ;
V_81 -> V_72 = V_199 ;
V_81 -> V_119 = 0 ;
V_81 -> V_84 = ( V_200 ? V_200 -> V_180 : V_81 -> V_180 ) ;
if ( V_200 )
return V_81 ;
V_44 = (struct V_43 * ) V_81 -> V_84 ;
V_44 -> V_3 [ 0 ] . V_13 = V_12 ;
V_44 -> V_3 [ 0 ] . V_29 = V_12 ;
#ifdef F_49
V_44 -> V_62 = F_116 ( struct V_61 ) ;
if ( ! V_44 -> V_62 ) {
F_103 ( V_81 ) ;
V_81 = NULL ;
}
#endif
return V_81 ;
}
static struct V_2 * F_117 ( struct V_202 * V_203 )
{
unsigned long V_63 = V_203 -> V_10 ;
struct V_2 * V_67 = V_203 -> V_1 ;
T_1 V_132 ;
F_25 ( L_10 ,
V_203 -> V_1 , V_203 -> V_10 , V_203 -> V_204 ) ;
while ( ! F_33 ( V_67 ) ) {
while ( V_63 < F_5 ( V_67 ) ) {
struct V_2 * V_4 = F_54 ( V_67 , V_63 ++ ) ;
if ( ! V_4 )
continue;
if ( F_82 ( V_4 ) ) {
V_203 -> V_1 = V_67 ;
V_203 -> V_10 = V_63 ;
} else {
V_203 -> V_1 = V_4 ;
V_203 -> V_10 = 0 ;
++ V_203 -> V_204 ;
}
return V_4 ;
}
V_132 = V_67 -> V_9 ;
V_67 = F_85 ( V_67 ) ;
V_63 = F_6 ( V_132 , V_67 ) + 1 ;
-- V_203 -> V_204 ;
}
V_203 -> V_1 = V_67 ;
V_203 -> V_10 = 0 ;
return NULL ;
}
static struct V_2 * F_118 ( struct V_202 * V_203 ,
struct V_43 * V_44 )
{
struct V_2 * V_4 , * V_67 ;
if ( ! V_44 )
return NULL ;
V_67 = V_44 -> V_3 ;
V_4 = F_84 ( V_67 -> V_1 [ 0 ] ) ;
if ( ! V_4 )
return NULL ;
if ( F_27 ( V_4 ) ) {
V_203 -> V_1 = V_4 ;
V_203 -> V_10 = 0 ;
V_203 -> V_204 = 1 ;
} else {
V_203 -> V_1 = V_67 ;
V_203 -> V_10 = 0 ;
V_203 -> V_204 = 0 ;
}
return V_4 ;
}
static void F_119 ( struct V_43 * V_44 , struct V_205 * V_206 )
{
struct V_2 * V_4 ;
struct V_202 V_203 ;
memset ( V_206 , 0 , sizeof( * V_206 ) ) ;
F_120 () ;
for ( V_4 = F_118 ( & V_203 , V_44 ) ; V_4 ; V_4 = F_117 ( & V_203 ) ) {
if ( F_82 ( V_4 ) ) {
struct V_16 * V_17 ;
V_206 -> V_207 ++ ;
V_206 -> V_208 += V_203 . V_204 ;
if ( V_203 . V_204 > V_206 -> V_209 )
V_206 -> V_209 = V_203 . V_204 ;
F_86 ( V_17 , & V_4 -> V_31 , V_32 )
++ V_206 -> V_210 ;
} else {
V_206 -> V_211 ++ ;
if ( V_4 -> V_8 < V_212 )
V_206 -> V_213 [ V_4 -> V_8 ] ++ ;
V_206 -> V_214 += F_1 ( V_4 ) -> V_26 ;
}
}
F_121 () ;
}
static void F_122 ( struct V_215 * V_216 , struct V_205 * V_217 )
{
unsigned int V_34 , V_218 , V_219 , V_220 , V_221 ;
if ( V_217 -> V_207 )
V_221 = V_217 -> V_208 * 100 / V_217 -> V_207 ;
else
V_221 = 0 ;
F_123 ( V_216 , L_11 ,
V_221 / 100 , V_221 % 100 ) ;
F_123 ( V_216 , L_12 , V_217 -> V_209 ) ;
F_123 ( V_216 , L_13 , V_217 -> V_207 ) ;
V_220 = V_198 * V_217 -> V_207 ;
F_123 ( V_216 , L_14 , V_217 -> V_210 ) ;
V_220 += sizeof( struct V_16 ) * V_217 -> V_210 ;
F_123 ( V_216 , L_15 , V_217 -> V_211 ) ;
V_220 += F_14 ( 0 ) * V_217 -> V_211 ;
V_218 = V_212 ;
while ( V_218 > 0 && V_217 -> V_213 [ V_218 - 1 ] == 0 )
V_218 -- ;
V_219 = 0 ;
for ( V_34 = 1 ; V_34 < V_218 ; V_34 ++ )
if ( V_217 -> V_213 [ V_34 ] != 0 ) {
F_123 ( V_216 , L_16 , V_34 , V_217 -> V_213 [ V_34 ] ) ;
V_219 += ( 1 << V_34 ) * V_217 -> V_213 [ V_34 ] ;
}
F_124 ( V_216 , '\n' ) ;
F_123 ( V_216 , L_17 , V_219 ) ;
V_220 += sizeof( struct V_2 * ) * V_219 ;
F_123 ( V_216 , L_18 , V_217 -> V_214 ) ;
F_123 ( V_216 , L_19 , ( V_220 + 1023 ) / 1024 ) ;
}
static void F_125 ( struct V_215 * V_216 ,
const struct V_61 T_3 * V_62 )
{
struct V_61 V_206 = { 0 } ;
int V_222 ;
F_126 (cpu) {
const struct V_61 * V_223 = F_127 ( V_62 , V_222 ) ;
V_206 . gets += V_223 -> gets ;
V_206 . V_133 += V_223 -> V_133 ;
V_206 . V_140 += V_223 -> V_140 ;
V_206 . V_162 += V_223 -> V_162 ;
V_206 . V_131 += V_223 -> V_131 ;
V_206 . V_66 += V_223 -> V_66 ;
}
F_123 ( V_216 , L_20 ) ;
F_123 ( V_216 , L_21 , V_206 . gets ) ;
F_123 ( V_216 , L_22 , V_206 . V_133 ) ;
F_123 ( V_216 , L_23 ,
V_206 . V_140 ) ;
F_123 ( V_216 , L_24 , V_206 . V_162 ) ;
F_123 ( V_216 , L_25 , V_206 . V_131 ) ;
F_123 ( V_216 , L_26 , V_206 . V_66 ) ;
}
static void F_128 ( struct V_215 * V_216 , struct V_80 * V_81 )
{
if ( V_81 -> V_72 == V_181 )
F_129 ( V_216 , L_27 ) ;
else if ( V_81 -> V_72 == V_224 )
F_129 ( V_216 , L_28 ) ;
else
F_123 ( V_216 , L_29 , V_81 -> V_72 ) ;
}
static int F_130 ( struct V_215 * V_216 , void * V_225 )
{
struct V_226 * V_226 = (struct V_226 * ) V_216 -> V_227 ;
unsigned int V_228 ;
F_123 ( V_216 ,
L_30
L_31 ,
V_198 , F_14 ( 0 ) ) ;
for ( V_228 = 0 ; V_228 < V_229 ; V_228 ++ ) {
struct V_68 * V_15 = & V_226 -> V_230 . V_231 [ V_228 ] ;
struct V_80 * V_81 ;
F_86 (tb, head, tb_hlist) {
struct V_43 * V_44 = (struct V_43 * ) V_81 -> V_84 ;
struct V_205 V_217 ;
if ( ! V_44 )
continue;
F_128 ( V_216 , V_81 ) ;
F_119 ( V_44 , & V_217 ) ;
F_122 ( V_216 , & V_217 ) ;
#ifdef F_49
F_125 ( V_216 , V_44 -> V_62 ) ;
#endif
}
}
return 0 ;
}
static int F_131 ( struct V_38 * V_38 , struct V_232 * V_232 )
{
return F_132 ( V_38 , V_232 , F_130 ) ;
}
static struct V_2 * F_133 ( struct V_215 * V_216 , T_9 V_13 )
{
struct V_202 * V_203 = V_216 -> V_227 ;
struct V_226 * V_226 = F_134 ( V_216 ) ;
T_9 V_233 = 0 ;
unsigned int V_228 ;
for ( V_228 = 0 ; V_228 < V_229 ; V_228 ++ ) {
struct V_68 * V_15 = & V_226 -> V_230 . V_231 [ V_228 ] ;
struct V_80 * V_81 ;
F_86 (tb, head, tb_hlist) {
struct V_2 * V_4 ;
for ( V_4 = F_118 ( V_203 ,
(struct V_43 * ) V_81 -> V_84 ) ;
V_4 ; V_4 = F_117 ( V_203 ) )
if ( V_13 == V_233 ++ ) {
V_203 -> V_81 = V_81 ;
return V_4 ;
}
}
}
return NULL ;
}
static void * F_135 ( struct V_215 * V_216 , T_9 * V_13 )
__acquires( T_10 )
{
F_120 () ;
return F_133 ( V_216 , * V_13 ) ;
}
static void * F_136 ( struct V_215 * V_216 , void * V_225 , T_9 * V_13 )
{
struct V_202 * V_203 = V_216 -> V_227 ;
struct V_226 * V_226 = F_134 ( V_216 ) ;
struct V_80 * V_81 = V_203 -> V_81 ;
struct V_164 * V_234 ;
unsigned int V_228 ;
struct V_2 * V_4 ;
++ * V_13 ;
V_4 = F_117 ( V_203 ) ;
if ( V_4 )
return V_4 ;
V_228 = V_81 -> V_72 & ( V_229 - 1 ) ;
while ( ( V_234 = F_84 ( F_137 ( & V_81 -> V_235 ) ) ) ) {
V_81 = F_93 ( V_234 , struct V_80 , V_235 ) ;
V_4 = F_118 ( V_203 , (struct V_43 * ) V_81 -> V_84 ) ;
if ( V_4 )
goto V_128;
}
while ( ++ V_228 < V_229 ) {
struct V_68 * V_15 = & V_226 -> V_230 . V_231 [ V_228 ] ;
F_86 (tb, head, tb_hlist) {
V_4 = F_118 ( V_203 , (struct V_43 * ) V_81 -> V_84 ) ;
if ( V_4 )
goto V_128;
}
}
return NULL ;
V_128:
V_203 -> V_81 = V_81 ;
return V_4 ;
}
static void F_138 ( struct V_215 * V_216 , void * V_225 )
__releases( T_10 )
{
F_121 () ;
}
static void F_139 ( struct V_215 * V_216 , int V_4 )
{
while ( V_4 -- > 0 )
F_129 ( V_216 , L_32 ) ;
}
static inline const char * F_140 ( char * V_236 , T_2 V_195 , enum V_237 V_206 )
{
switch ( V_206 ) {
case V_238 : return L_33 ;
case V_239 : return L_34 ;
case V_240 : return L_35 ;
case V_241 : return L_36 ;
case V_169 : return L_37 ;
default:
snprintf ( V_236 , V_195 , L_38 , V_206 ) ;
return V_236 ;
}
}
static inline const char * F_141 ( char * V_236 , T_2 V_195 , unsigned int V_44 )
{
if ( V_44 < V_242 && V_243 [ V_44 ] )
return V_243 [ V_44 ] ;
snprintf ( V_236 , V_195 , L_39 , V_44 ) ;
return V_236 ;
}
static int F_142 ( struct V_215 * V_216 , void * V_225 )
{
const struct V_202 * V_203 = V_216 -> V_227 ;
struct V_2 * V_4 = V_225 ;
if ( F_33 ( F_85 ( V_4 ) ) )
F_128 ( V_216 , V_203 -> V_81 ) ;
if ( F_27 ( V_4 ) ) {
T_7 V_244 = F_77 ( V_4 -> V_9 ) ;
F_139 ( V_216 , V_203 -> V_204 - 1 ) ;
F_123 ( V_216 , L_40 ,
& V_244 , V_12 - V_4 -> V_13 - V_4 -> V_8 , V_4 -> V_8 ,
F_1 ( V_4 ) -> V_27 ,
F_1 ( V_4 ) -> V_26 ) ;
} else {
T_7 V_245 = F_77 ( V_4 -> V_9 ) ;
struct V_16 * V_17 ;
F_139 ( V_216 , V_203 -> V_204 ) ;
F_123 ( V_216 , L_41 , & V_245 ) ;
F_86 (fa, &n->leaf, fa_list) {
char V_246 [ 32 ] , V_247 [ 32 ] ;
F_139 ( V_216 , V_203 -> V_204 + 1 ) ;
F_123 ( V_216 , L_42 ,
V_12 - V_17 -> V_30 ,
F_140 ( V_246 , sizeof( V_246 ) ,
V_17 -> V_74 -> V_137 ) ,
F_141 ( V_247 , sizeof( V_247 ) ,
V_17 -> V_101 ) ) ;
if ( V_17 -> V_73 )
F_123 ( V_216 , L_43 , V_17 -> V_73 ) ;
F_124 ( V_216 , '\n' ) ;
}
}
return 0 ;
}
static int F_143 ( struct V_38 * V_38 , struct V_232 * V_232 )
{
return F_144 ( V_38 , V_232 , & V_248 ,
sizeof( struct V_202 ) ) ;
}
static struct V_2 * F_145 ( struct V_249 * V_203 ,
T_9 V_13 )
{
struct V_80 * V_81 = V_203 -> V_250 ;
struct V_2 * V_28 , * * V_5 = & V_203 -> V_1 ;
struct V_43 * V_44 ;
T_1 V_9 ;
if ( V_203 -> V_13 > 0 && V_13 >= V_203 -> V_13 ) {
V_13 -= V_203 -> V_13 ;
V_9 = V_203 -> V_9 ;
} else {
V_44 = (struct V_43 * ) V_81 -> V_84 ;
V_203 -> V_1 = V_44 -> V_3 ;
V_203 -> V_13 = 0 ;
V_9 = 0 ;
}
while ( ( V_28 = F_99 ( V_5 , V_9 ) ) != NULL ) {
V_9 = V_28 -> V_9 + 1 ;
V_203 -> V_13 ++ ;
if ( -- V_13 <= 0 )
break;
V_28 = NULL ;
if ( ! V_9 )
break;
}
if ( V_28 )
V_203 -> V_9 = V_9 ;
else
V_203 -> V_13 = 0 ;
return V_28 ;
}
static void * F_146 ( struct V_215 * V_216 , T_9 * V_13 )
__acquires( T_10 )
{
struct V_249 * V_203 = V_216 -> V_227 ;
struct V_80 * V_81 ;
struct V_43 * V_44 ;
F_120 () ;
V_81 = F_147 ( F_134 ( V_216 ) , V_224 ) ;
if ( ! V_81 )
return NULL ;
V_203 -> V_250 = V_81 ;
if ( * V_13 != 0 )
return F_145 ( V_203 , * V_13 ) ;
V_44 = (struct V_43 * ) V_81 -> V_84 ;
V_203 -> V_1 = V_44 -> V_3 ;
V_203 -> V_13 = 0 ;
V_203 -> V_9 = 0 ;
return V_251 ;
}
static void * F_148 ( struct V_215 * V_216 , void * V_225 , T_9 * V_13 )
{
struct V_249 * V_203 = V_216 -> V_227 ;
struct V_2 * V_28 = NULL ;
T_1 V_9 = V_203 -> V_9 ;
++ * V_13 ;
if ( ( V_225 == V_251 ) || V_9 )
V_28 = F_99 ( & V_203 -> V_1 , V_9 ) ;
if ( V_28 ) {
V_203 -> V_9 = V_28 -> V_9 + 1 ;
V_203 -> V_13 ++ ;
} else {
V_203 -> V_13 = 0 ;
}
return V_28 ;
}
static void F_149 ( struct V_215 * V_216 , void * V_225 )
__releases( T_10 )
{
F_121 () ;
}
static unsigned int F_150 ( int type , T_7 V_252 , const struct V_87 * V_88 )
{
unsigned int V_253 = 0 ;
if ( type == V_254 || type == V_255 )
V_253 = V_256 ;
if ( V_88 && V_88 -> V_143 -> V_257 )
V_253 |= V_258 ;
if ( V_252 == F_77 ( 0xFFFFFFFF ) )
V_253 |= V_259 ;
V_253 |= V_260 ;
return V_253 ;
}
static int F_151 ( struct V_215 * V_216 , void * V_225 )
{
struct V_249 * V_203 = V_216 -> V_227 ;
struct V_80 * V_81 = V_203 -> V_250 ;
struct V_16 * V_17 ;
struct V_2 * V_28 = V_225 ;
T_7 V_120 ;
if ( V_225 == V_251 ) {
F_123 ( V_216 , L_44 , L_45
L_46
L_47 ) ;
return 0 ;
}
V_120 = F_77 ( V_28 -> V_9 ) ;
F_86 (fa, &l->leaf, fa_list) {
const struct V_87 * V_88 = V_17 -> V_74 ;
T_7 V_252 = F_152 ( V_12 - V_17 -> V_30 ) ;
unsigned int V_253 = F_150 ( V_17 -> V_101 , V_252 , V_88 ) ;
if ( ( V_17 -> V_101 == V_261 ) ||
( V_17 -> V_101 == V_262 ) )
continue;
if ( V_17 -> V_72 != V_81 -> V_72 )
continue;
F_153 ( V_216 , 127 ) ;
if ( V_88 )
F_123 ( V_216 ,
L_48
L_49 ,
V_88 -> V_263 ? V_88 -> V_263 -> V_264 : L_50 ,
V_120 ,
V_88 -> V_143 -> V_257 , V_253 , 0 , 0 ,
V_88 -> V_75 ,
V_252 ,
( V_88 -> V_265 ?
V_88 -> V_265 + 40 : 0 ) ,
V_88 -> V_266 ,
V_88 -> V_267 >> 3 ) ;
else
F_123 ( V_216 ,
L_51
L_49 ,
V_120 , 0 , V_253 , 0 , 0 , 0 ,
V_252 , 0 , 0 , 0 ) ;
F_154 ( V_216 , '\n' ) ;
}
return 0 ;
}
static int F_155 ( struct V_38 * V_38 , struct V_232 * V_232 )
{
return F_144 ( V_38 , V_232 , & V_268 ,
sizeof( struct V_249 ) ) ;
}
int T_11 F_156 ( struct V_226 * V_226 )
{
if ( ! F_157 ( L_52 , V_269 , V_226 -> V_270 , & V_271 ) )
goto V_272;
if ( ! F_157 ( L_53 , V_269 , V_226 -> V_270 ,
& V_273 ) )
goto V_274;
if ( ! F_157 ( L_54 , V_269 , V_226 -> V_270 , & V_275 ) )
goto V_276;
return 0 ;
V_276:
F_158 ( L_53 , V_226 -> V_270 ) ;
V_274:
F_158 ( L_52 , V_226 -> V_270 ) ;
V_272:
return - V_78 ;
}
void T_12 F_159 ( struct V_226 * V_226 )
{
F_158 ( L_52 , V_226 -> V_270 ) ;
F_158 ( L_53 , V_226 -> V_270 ) ;
F_158 ( L_54 , V_226 -> V_270 ) ;
}
