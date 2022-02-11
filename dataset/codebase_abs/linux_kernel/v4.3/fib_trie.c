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
else if ( V_4 -> V_20 <= V_22 )
F_12 ( V_4 ) ;
else
F_13 ( V_4 ) ;
}
static struct V_1 * F_14 ( int V_8 )
{
T_2 V_23 ;
if ( V_8 > V_24 )
return NULL ;
V_23 = F_15 ( 1ul << V_8 ) ;
if ( V_23 <= V_25 )
return F_16 ( V_23 , V_26 ) ;
else
return F_17 ( V_23 ) ;
}
static inline void F_18 ( struct V_2 * V_4 )
{
++ F_1 ( V_4 ) -> V_27 ? : ++ F_1 ( V_4 ) -> V_28 ;
}
static inline void F_19 ( struct V_2 * V_4 )
{
F_1 ( V_4 ) -> V_27 -- ? : F_1 ( V_4 ) -> V_28 -- ;
}
static struct V_2 * F_20 ( T_1 V_9 , struct V_16 * V_17 )
{
struct V_2 * V_29 ;
struct V_1 * V_3 ;
V_3 = F_21 ( V_21 , V_26 ) ;
if ( ! V_3 )
return NULL ;
V_29 = V_3 -> V_3 ;
V_29 -> V_9 = V_9 ;
V_29 -> V_13 = 0 ;
V_29 -> V_8 = 0 ;
V_29 -> V_30 = V_17 -> V_31 ;
F_22 ( & V_29 -> V_32 ) ;
F_23 ( & V_17 -> V_33 , & V_29 -> V_32 ) ;
return V_29 ;
}
static struct V_2 * F_24 ( T_1 V_9 , int V_13 , int V_8 )
{
unsigned int V_34 = V_13 + V_8 ;
struct V_2 * V_7 ;
struct V_1 * V_1 ;
F_25 ( ! V_8 || ( V_34 > V_12 ) ) ;
V_1 = F_14 ( V_8 ) ;
if ( ! V_1 )
return NULL ;
F_26 ( L_1 , V_1 , F_15 ( 0 ) ,
sizeof( struct V_2 * ) << V_8 ) ;
if ( V_8 == V_12 )
V_1 -> V_28 = 1 ;
else
V_1 -> V_27 = 1ul << V_8 ;
V_7 = V_1 -> V_3 ;
V_7 -> V_9 = ( V_34 < V_12 ) ? ( V_9 >> V_34 ) << V_34 : 0 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_8 = V_8 ;
V_7 -> V_30 = V_13 ;
return V_7 ;
}
static inline int F_27 ( struct V_2 * V_7 , struct V_2 * V_4 )
{
return V_4 && ( ( V_4 -> V_13 + V_4 -> V_8 ) == V_7 -> V_13 ) && F_28 ( V_4 ) ;
}
static void F_29 ( struct V_2 * V_7 , unsigned long V_35 ,
struct V_2 * V_4 )
{
struct V_2 * V_36 = F_30 ( V_7 , V_35 ) ;
int V_37 , V_38 ;
F_25 ( V_35 >= F_5 ( V_7 ) ) ;
if ( ! V_4 && V_36 )
F_18 ( V_7 ) ;
if ( V_4 && ! V_36 )
F_19 ( V_7 ) ;
V_38 = F_27 ( V_7 , V_36 ) ;
V_37 = F_27 ( V_7 , V_4 ) ;
if ( V_38 && ! V_37 )
F_1 ( V_7 ) -> V_28 -- ;
else if ( ! V_38 && V_37 )
F_1 ( V_7 ) -> V_28 ++ ;
if ( V_4 && ( V_7 -> V_30 < V_4 -> V_30 ) )
V_7 -> V_30 = V_4 -> V_30 ;
F_4 ( V_7 -> V_1 [ V_35 ] , V_4 ) ;
}
static void F_31 ( struct V_2 * V_7 )
{
unsigned long V_35 ;
for ( V_35 = F_5 ( V_7 ) ; V_35 ; ) {
struct V_2 * V_39 = F_30 ( V_7 , -- V_35 ) ;
if ( ! V_39 )
continue;
if ( F_32 ( V_39 ) == V_7 )
F_31 ( V_39 ) ;
else
F_3 ( V_39 , V_7 ) ;
}
}
static inline void F_33 ( struct V_2 * V_5 , T_1 V_9 ,
struct V_2 * V_4 )
{
if ( F_34 ( V_5 ) )
F_4 ( V_5 -> V_1 [ 0 ] , V_4 ) ;
else
F_29 ( V_5 , F_6 ( V_9 , V_5 ) , V_4 ) ;
}
static inline void F_35 ( struct V_2 * V_7 )
{
F_1 ( V_7 ) -> V_18 . V_40 = NULL ;
}
static inline void F_36 ( struct V_2 * V_7 ,
struct V_2 * V_4 )
{
F_1 ( V_4 ) -> V_18 . V_40 = F_1 ( V_7 ) -> V_18 . V_40 ;
F_1 ( V_7 ) -> V_18 . V_40 = & F_1 ( V_4 ) -> V_18 ;
}
static void F_37 ( struct V_2 * V_7 )
{
struct V_41 * V_15 = & F_1 ( V_7 ) -> V_18 ;
while ( V_15 ) {
V_15 = V_15 -> V_40 ;
V_42 += F_15 ( 1ul << V_7 -> V_8 ) ;
F_38 ( V_7 ) ;
V_7 = F_2 ( V_15 , struct V_1 , V_18 ) -> V_3 ;
}
if ( V_42 >= V_25 * V_43 ) {
V_42 = 0 ;
F_39 () ;
}
}
static struct V_2 * F_40 ( struct V_44 * V_45 ,
struct V_2 * V_46 ,
struct V_2 * V_7 )
{
struct V_2 * V_5 = F_32 ( V_46 ) ;
unsigned long V_35 ;
F_41 ( V_7 , V_5 ) ;
F_33 ( V_5 , V_7 -> V_9 , V_7 ) ;
F_31 ( V_7 ) ;
F_37 ( V_46 ) ;
for ( V_35 = F_5 ( V_7 ) ; V_35 ; ) {
struct V_2 * V_39 = F_30 ( V_7 , -- V_35 ) ;
if ( F_27 ( V_7 , V_39 ) )
V_7 = F_42 ( V_45 , V_39 ) ;
}
return V_5 ;
}
static struct V_2 * F_43 ( struct V_44 * V_45 ,
struct V_2 * V_46 )
{
struct V_2 * V_7 ;
unsigned long V_35 ;
T_1 V_47 ;
F_26 ( L_2 ) ;
V_7 = F_24 ( V_46 -> V_9 , V_46 -> V_13 - 1 , V_46 -> V_8 + 1 ) ;
if ( ! V_7 )
goto V_48;
F_35 ( V_46 ) ;
for ( V_35 = F_5 ( V_46 ) , V_47 = 1u << V_7 -> V_13 ; V_35 ; ) {
struct V_2 * V_39 = F_30 ( V_46 , -- V_35 ) ;
struct V_2 * V_49 , * V_50 ;
unsigned long V_51 , V_52 ;
if ( ! V_39 )
continue;
if ( ! F_27 ( V_46 , V_39 ) ) {
F_29 ( V_7 , F_6 ( V_39 -> V_9 , V_7 ) , V_39 ) ;
continue;
}
F_36 ( V_46 , V_39 ) ;
if ( V_39 -> V_8 == 1 ) {
F_29 ( V_7 , 2 * V_35 + 1 , F_30 ( V_39 , 1 ) ) ;
F_29 ( V_7 , 2 * V_35 , F_30 ( V_39 , 0 ) ) ;
continue;
}
V_50 = F_24 ( V_39 -> V_9 | V_47 , V_39 -> V_13 , V_39 -> V_8 - 1 ) ;
if ( ! V_50 )
goto V_53;
V_49 = F_24 ( V_39 -> V_9 , V_39 -> V_13 , V_39 -> V_8 - 1 ) ;
F_36 ( V_7 , V_50 ) ;
if ( ! V_49 )
goto V_53;
F_36 ( V_7 , V_49 ) ;
for ( V_52 = F_5 ( V_39 ) , V_51 = V_52 / 2 ; V_51 ; ) {
F_29 ( V_50 , -- V_51 , F_30 ( V_39 , -- V_52 ) ) ;
F_29 ( V_49 , V_51 , F_30 ( V_39 , V_51 ) ) ;
F_29 ( V_50 , -- V_51 , F_30 ( V_39 , -- V_52 ) ) ;
F_29 ( V_49 , V_51 , F_30 ( V_39 , V_51 ) ) ;
}
F_41 ( V_50 , V_7 ) ;
F_41 ( V_49 , V_7 ) ;
F_29 ( V_7 , 2 * V_35 + 1 , V_50 ) ;
F_29 ( V_7 , 2 * V_35 , V_49 ) ;
}
return F_40 ( V_45 , V_46 , V_7 ) ;
V_53:
F_37 ( V_7 ) ;
V_48:
return NULL ;
}
static struct V_2 * F_44 ( struct V_44 * V_45 ,
struct V_2 * V_46 )
{
struct V_2 * V_7 ;
unsigned long V_35 ;
F_26 ( L_3 ) ;
V_7 = F_24 ( V_46 -> V_9 , V_46 -> V_13 + 1 , V_46 -> V_8 - 1 ) ;
if ( ! V_7 )
goto V_48;
F_35 ( V_46 ) ;
for ( V_35 = F_5 ( V_46 ) ; V_35 ; ) {
struct V_2 * V_50 = F_30 ( V_46 , -- V_35 ) ;
struct V_2 * V_49 = F_30 ( V_46 , -- V_35 ) ;
struct V_2 * V_39 ;
if ( ! V_50 || ! V_49 ) {
F_29 ( V_7 , V_35 / 2 , V_50 ? : V_49 ) ;
continue;
}
V_39 = F_24 ( V_49 -> V_9 , V_46 -> V_13 , 1 ) ;
if ( ! V_39 )
goto V_53;
F_36 ( V_7 , V_39 ) ;
F_29 ( V_39 , 1 , V_50 ) ;
F_29 ( V_39 , 0 , V_49 ) ;
F_41 ( V_39 , V_7 ) ;
F_29 ( V_7 , V_35 / 2 , V_39 ) ;
}
return F_40 ( V_45 , V_46 , V_7 ) ;
V_53:
F_37 ( V_7 ) ;
V_48:
return NULL ;
}
static struct V_2 * F_45 ( struct V_44 * V_45 ,
struct V_2 * V_46 )
{
struct V_2 * V_4 , * V_5 ;
unsigned long V_35 ;
for ( V_4 = NULL , V_35 = F_5 ( V_46 ) ; ! V_4 && V_35 ; )
V_4 = F_30 ( V_46 , -- V_35 ) ;
V_5 = F_32 ( V_46 ) ;
F_33 ( V_5 , V_46 -> V_9 , V_4 ) ;
F_3 ( V_4 , V_5 ) ;
F_38 ( V_46 ) ;
return V_5 ;
}
static unsigned char F_46 ( struct V_2 * V_7 )
{
unsigned char V_30 = V_7 -> V_13 ;
unsigned long V_54 , V_35 ;
for ( V_35 = 0 , V_54 = 0x2ul ; V_35 < F_5 ( V_7 ) ; V_35 += V_54 ) {
struct V_2 * V_4 = F_30 ( V_7 , V_35 ) ;
if ( ! V_4 || ( V_4 -> V_30 <= V_30 ) )
continue;
V_54 <<= ( V_4 -> V_30 - V_30 ) ;
V_30 = V_4 -> V_30 ;
V_35 &= ~ ( V_54 - 1 ) ;
if ( ( V_30 + 1 ) >= ( V_7 -> V_13 + V_7 -> V_8 ) )
break;
}
V_7 -> V_30 = V_30 ;
return V_30 ;
}
static inline bool F_47 ( struct V_2 * V_5 , struct V_2 * V_7 )
{
unsigned long V_55 = F_5 ( V_7 ) ;
unsigned long V_56 = V_55 ;
V_56 *= F_34 ( V_5 ) ? V_57 : V_58 ;
V_55 -= F_1 ( V_7 ) -> V_27 ;
V_55 += F_1 ( V_7 ) -> V_28 ;
return ( V_55 > 1 ) && V_7 -> V_13 && ( ( 50 * V_55 ) >= V_56 ) ;
}
static inline bool F_48 ( struct V_2 * V_5 , struct V_2 * V_7 )
{
unsigned long V_55 = F_5 ( V_7 ) ;
unsigned long V_56 = V_55 ;
V_56 *= F_34 ( V_5 ) ? V_59 : V_60 ;
V_55 -= F_1 ( V_7 ) -> V_27 ;
return ( V_55 > 1 ) && ( V_7 -> V_8 > 1 ) && ( ( 100 * V_55 ) < V_56 ) ;
}
static inline bool F_49 ( struct V_2 * V_7 )
{
unsigned long V_55 = F_5 ( V_7 ) ;
V_55 -= F_1 ( V_7 ) -> V_27 ;
if ( ( V_7 -> V_8 == V_12 ) && F_1 ( V_7 ) -> V_28 )
V_55 -= V_61 ;
return V_55 < 2 ;
}
static struct V_2 * F_42 ( struct V_44 * V_45 , struct V_2 * V_7 )
{
#ifdef F_50
struct V_62 T_3 * V_63 = V_45 -> V_63 ;
#endif
struct V_2 * V_5 = F_32 ( V_7 ) ;
unsigned long V_64 = F_6 ( V_7 -> V_9 , V_5 ) ;
int V_65 = V_66 ;
F_26 ( L_4 ,
V_7 , V_58 , V_60 ) ;
F_25 ( V_7 != F_30 ( V_5 , V_64 ) ) ;
while ( F_47 ( V_5 , V_7 ) && V_65 ) {
V_5 = F_43 ( V_45 , V_7 ) ;
if ( ! V_5 ) {
#ifdef F_50
F_51 ( V_63 -> V_67 ) ;
#endif
break;
}
V_65 -- ;
V_7 = F_30 ( V_5 , V_64 ) ;
}
V_5 = F_32 ( V_7 ) ;
if ( V_65 != V_66 )
return V_5 ;
while ( F_48 ( V_5 , V_7 ) && V_65 ) {
V_5 = F_44 ( V_45 , V_7 ) ;
if ( ! V_5 ) {
#ifdef F_50
F_51 ( V_63 -> V_67 ) ;
#endif
break;
}
V_65 -- ;
V_7 = F_30 ( V_5 , V_64 ) ;
}
if ( F_49 ( V_7 ) )
return F_45 ( V_45 , V_7 ) ;
V_5 = F_32 ( V_7 ) ;
if ( V_65 != V_66 )
return V_5 ;
if ( V_7 -> V_30 > V_7 -> V_13 ) {
unsigned char V_30 = F_46 ( V_7 ) ;
if ( V_30 > V_5 -> V_30 )
V_5 -> V_30 = V_30 ;
}
return V_5 ;
}
static void F_52 ( struct V_2 * V_5 , struct V_2 * V_29 )
{
while ( ( V_5 -> V_30 > V_5 -> V_13 ) && ( V_5 -> V_30 > V_29 -> V_30 ) ) {
if ( F_46 ( V_5 ) > V_29 -> V_30 )
break;
V_5 = F_32 ( V_5 ) ;
}
}
static void F_53 ( struct V_2 * V_7 , struct V_2 * V_29 )
{
while ( V_7 -> V_30 < V_29 -> V_30 ) {
V_7 -> V_30 = V_29 -> V_30 ;
V_7 = F_32 ( V_7 ) ;
}
}
static struct V_2 * F_54 ( struct V_44 * V_45 ,
struct V_2 * * V_5 , T_4 V_9 )
{
struct V_2 * V_68 , * V_4 = V_45 -> V_3 ;
unsigned long V_10 = 0 ;
do {
V_68 = V_4 ;
V_4 = F_55 ( V_4 , V_10 ) ;
if ( ! V_4 )
break;
V_10 = F_56 ( V_9 , V_4 ) ;
if ( V_10 >= ( 1ul << V_4 -> V_8 ) ) {
V_4 = NULL ;
break;
}
} while ( F_28 ( V_4 ) );
* V_5 = V_68 ;
return V_4 ;
}
static struct V_16 * F_57 ( struct V_69 * V_70 , T_5 V_30 ,
T_5 V_71 , T_4 V_72 , T_4 V_73 )
{
struct V_16 * V_17 ;
if ( ! V_70 )
return NULL ;
F_58 (fa, fah, fa_list) {
if ( V_17 -> V_31 < V_30 )
continue;
if ( V_17 -> V_31 != V_30 )
break;
if ( V_17 -> V_73 > V_73 )
continue;
if ( V_17 -> V_73 != V_73 )
break;
if ( V_17 -> V_74 > V_71 )
continue;
if ( V_17 -> V_75 -> V_76 >= V_72 || V_17 -> V_74 < V_71 )
return V_17 ;
}
return NULL ;
}
static void F_59 ( struct V_44 * V_45 , struct V_2 * V_7 )
{
while ( ! F_34 ( V_7 ) )
V_7 = F_42 ( V_45 , V_7 ) ;
}
static int F_60 ( struct V_44 * V_45 , struct V_2 * V_5 ,
struct V_16 * V_77 , T_1 V_9 )
{
struct V_2 * V_4 , * V_29 ;
V_29 = F_20 ( V_9 , V_77 ) ;
if ( ! V_29 )
goto V_78;
V_4 = F_30 ( V_5 , F_6 ( V_9 , V_5 ) ) ;
if ( V_4 ) {
struct V_2 * V_7 ;
V_7 = F_24 ( V_9 , F_61 ( V_9 ^ V_4 -> V_9 ) , 1 ) ;
if ( ! V_7 )
goto V_48;
F_41 ( V_7 , V_5 ) ;
F_29 ( V_7 , F_6 ( V_9 , V_7 ) ^ 1 , V_4 ) ;
F_33 ( V_5 , V_9 , V_7 ) ;
F_3 ( V_4 , V_7 ) ;
V_5 = V_7 ;
}
F_41 ( V_29 , V_5 ) ;
F_33 ( V_5 , V_9 , V_29 ) ;
F_59 ( V_45 , V_5 ) ;
return 0 ;
V_48:
F_38 ( V_29 ) ;
V_78:
return - V_79 ;
}
static int F_62 ( struct V_44 * V_45 , struct V_2 * V_5 ,
struct V_2 * V_29 , struct V_16 * V_77 ,
struct V_16 * V_17 , T_1 V_9 )
{
if ( ! V_29 )
return F_60 ( V_45 , V_5 , V_77 , V_9 ) ;
if ( V_17 ) {
F_63 ( & V_77 -> V_33 , & V_17 -> V_33 ) ;
} else {
struct V_16 * V_80 ;
F_58 (last, &l->leaf, fa_list) {
if ( V_77 -> V_31 < V_80 -> V_31 )
break;
if ( ( V_77 -> V_31 == V_80 -> V_31 ) &&
( V_77 -> V_73 > V_80 -> V_73 ) )
break;
V_17 = V_80 ;
}
if ( V_17 )
F_64 ( & V_77 -> V_33 , & V_17 -> V_33 ) ;
else
F_65 ( & V_77 -> V_33 , & V_29 -> V_32 ) ;
}
if ( V_29 -> V_30 < V_77 -> V_31 ) {
V_29 -> V_30 = V_77 -> V_31 ;
F_53 ( V_5 , V_29 ) ;
}
return 0 ;
}
int F_66 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_16 * V_17 , * V_86 ;
struct V_2 * V_29 , * V_5 ;
unsigned int V_87 = 0 ;
struct V_88 * V_89 ;
T_5 V_90 = V_84 -> V_91 ;
T_5 V_30 = V_12 - V_90 ;
T_5 V_71 = V_84 -> V_92 ;
T_4 V_9 ;
int V_93 ;
if ( V_90 > V_12 )
return - V_94 ;
V_9 = F_67 ( V_84 -> V_95 ) ;
F_26 ( L_5 , V_82 -> V_73 , V_9 , V_90 ) ;
if ( ( V_90 < V_12 ) && ( V_9 << V_90 ) )
return - V_94 ;
V_89 = F_68 ( V_84 ) ;
if ( F_69 ( V_89 ) ) {
V_93 = F_70 ( V_89 ) ;
goto V_93;
}
V_29 = F_54 ( V_45 , & V_5 , V_9 ) ;
V_17 = V_29 ? F_57 ( & V_29 -> V_32 , V_30 , V_71 , V_89 -> V_76 ,
V_82 -> V_73 ) : NULL ;
if ( V_17 && V_17 -> V_74 == V_71 &&
V_17 -> V_75 -> V_76 == V_89 -> V_76 ) {
struct V_16 * V_96 , * V_97 ;
V_93 = - V_98 ;
if ( V_84 -> V_99 & V_100 )
goto V_101;
V_97 = NULL ;
V_96 = V_17 ;
F_71 (fa, fa_list) {
if ( ( V_17 -> V_31 != V_30 ) ||
( V_17 -> V_73 != V_82 -> V_73 ) ||
( V_17 -> V_74 != V_71 ) )
break;
if ( V_17 -> V_75 -> V_76 != V_89 -> V_76 )
break;
if ( V_17 -> V_102 == V_84 -> V_103 &&
V_17 -> V_75 == V_89 ) {
V_97 = V_17 ;
break;
}
}
if ( V_84 -> V_99 & V_104 ) {
struct V_88 * V_105 ;
T_5 V_106 ;
V_17 = V_96 ;
if ( V_97 ) {
if ( V_17 == V_97 )
V_93 = 0 ;
goto V_101;
}
V_93 = - V_107 ;
V_86 = F_21 ( V_19 , V_26 ) ;
if ( ! V_86 )
goto V_101;
V_105 = V_17 -> V_75 ;
V_86 -> V_74 = V_17 -> V_74 ;
V_86 -> V_75 = V_89 ;
V_86 -> V_102 = V_84 -> V_103 ;
V_106 = V_17 -> V_108 ;
V_86 -> V_108 = V_106 & ~ V_109 ;
V_86 -> V_31 = V_17 -> V_31 ;
V_86 -> V_73 = V_82 -> V_73 ;
V_86 -> V_110 = - 1 ;
V_93 = F_72 ( V_9 , V_90 , V_89 ,
V_86 -> V_74 ,
V_84 -> V_103 ,
V_84 -> V_99 ,
V_82 -> V_73 ) ;
if ( V_93 ) {
F_73 ( V_89 ) ;
F_8 ( V_19 , V_86 ) ;
goto V_101;
}
F_74 ( & V_17 -> V_33 , & V_86 -> V_33 ) ;
F_9 ( V_17 ) ;
F_75 ( V_105 ) ;
if ( V_106 & V_109 )
F_76 ( V_84 -> V_111 . V_112 ) ;
F_77 ( V_113 , F_78 ( V_9 ) , V_86 , V_90 ,
V_82 -> V_73 , & V_84 -> V_111 , V_104 ) ;
goto V_114;
}
if ( V_97 )
goto V_101;
if ( V_84 -> V_99 & V_115 )
V_87 = V_115 ;
else
V_17 = V_96 ;
}
V_93 = - V_116 ;
if ( ! ( V_84 -> V_99 & V_117 ) )
goto V_101;
V_93 = - V_107 ;
V_86 = F_21 ( V_19 , V_26 ) ;
if ( ! V_86 )
goto V_101;
V_86 -> V_75 = V_89 ;
V_86 -> V_74 = V_71 ;
V_86 -> V_102 = V_84 -> V_103 ;
V_86 -> V_108 = 0 ;
V_86 -> V_31 = V_30 ;
V_86 -> V_73 = V_82 -> V_73 ;
V_86 -> V_110 = - 1 ;
V_93 = F_72 ( V_9 , V_90 , V_89 , V_71 , V_84 -> V_103 ,
V_84 -> V_99 , V_82 -> V_73 ) ;
if ( V_93 ) {
F_73 ( V_89 ) ;
goto V_118;
}
V_93 = F_62 ( V_45 , V_5 , V_29 , V_86 , V_17 , V_9 ) ;
if ( V_93 )
goto V_119;
if ( ! V_90 )
V_82 -> V_120 ++ ;
F_76 ( V_84 -> V_111 . V_112 ) ;
F_77 ( V_113 , F_78 ( V_9 ) , V_86 , V_90 , V_86 -> V_73 ,
& V_84 -> V_111 , V_87 ) ;
V_114:
return 0 ;
V_119:
F_79 ( V_9 , V_90 , V_89 , V_71 , V_84 -> V_103 , V_82 -> V_73 ) ;
V_118:
F_8 ( V_19 , V_86 ) ;
V_101:
F_75 ( V_89 ) ;
V_93:
return V_93 ;
}
static inline T_1 F_80 ( T_1 V_9 , struct V_2 * V_4 )
{
T_1 V_121 = V_4 -> V_9 ;
return ( V_9 ^ V_121 ) & ( V_121 | - V_121 ) ;
}
int F_81 ( struct V_81 * V_82 , const struct V_122 * V_123 ,
struct V_124 * V_125 , int V_126 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
#ifdef F_50
struct V_62 T_3 * V_63 = V_45 -> V_63 ;
#endif
const T_1 V_9 = F_67 ( V_123 -> V_127 ) ;
struct V_2 * V_4 , * V_68 ;
struct V_16 * V_17 ;
unsigned long V_10 ;
T_1 V_64 ;
F_82 ( V_82 -> V_73 , V_123 ) ;
V_68 = V_45 -> V_3 ;
V_64 = 0 ;
V_4 = F_55 ( V_68 , V_64 ) ;
if ( ! V_4 )
return - V_128 ;
#ifdef F_50
F_51 ( V_63 -> gets ) ;
#endif
for (; ; ) {
V_10 = F_56 ( V_9 , V_4 ) ;
if ( V_10 >= ( 1ul << V_4 -> V_8 ) )
break;
if ( F_83 ( V_4 ) )
goto V_129;
if ( V_4 -> V_30 > V_4 -> V_13 ) {
V_68 = V_4 ;
V_64 = V_10 ;
}
V_4 = F_55 ( V_4 , V_10 ) ;
if ( F_84 ( ! V_4 ) )
goto V_130;
}
for (; ; ) {
struct V_2 T_6 * * V_131 = V_4 -> V_1 ;
if ( F_84 ( F_80 ( V_9 , V_4 ) ) || ( V_4 -> V_30 == V_4 -> V_13 ) )
goto V_130;
if ( F_84 ( F_83 ( V_4 ) ) )
break;
while ( ( V_4 = F_85 ( * V_131 ) ) == NULL ) {
V_130:
#ifdef F_50
if ( ! V_4 )
F_51 ( V_63 -> V_132 ) ;
#endif
while ( ! V_64 ) {
T_1 V_133 = V_68 -> V_9 ;
if ( F_34 ( V_68 ) )
return - V_128 ;
#ifdef F_50
F_51 ( V_63 -> V_134 ) ;
#endif
V_68 = F_86 ( V_68 ) ;
V_64 = F_6 ( V_133 , V_68 ) ;
}
V_64 &= V_64 - 1 ;
V_131 = & V_68 -> V_1 [ V_64 ] ;
}
}
V_129:
V_10 = V_9 ^ V_4 -> V_9 ;
F_87 (fa, &n->leaf, fa_list) {
struct V_88 * V_89 = V_17 -> V_75 ;
int V_135 , V_93 ;
if ( ( V_10 >= ( 1ul << V_17 -> V_31 ) ) &&
( ( V_11 > V_12 ) || ( V_17 -> V_31 != V_12 ) ) )
continue;
if ( V_17 -> V_74 && V_17 -> V_74 != V_123 -> V_136 )
continue;
if ( V_89 -> V_137 )
continue;
if ( V_17 -> V_75 -> V_138 < V_123 -> V_139 )
continue;
F_88 ( V_17 ) ;
V_93 = V_140 [ V_17 -> V_102 ] . error ;
if ( F_84 ( V_93 < 0 ) ) {
#ifdef F_50
F_51 ( V_63 -> V_141 ) ;
#endif
return V_93 ;
}
if ( V_89 -> V_126 & V_142 )
continue;
for ( V_135 = 0 ; V_135 < V_89 -> V_143 ; V_135 ++ ) {
const struct V_144 * V_145 = & V_89 -> V_144 [ V_135 ] ;
struct V_146 * V_147 = F_89 ( V_145 -> V_148 ) ;
if ( V_145 -> V_149 & V_142 )
continue;
if ( V_147 &&
F_90 ( V_147 ) &&
V_145 -> V_149 & V_150 &&
! ( V_126 & V_151 ) )
continue;
if ( ! ( V_123 -> V_152 & V_153 ) ) {
if ( V_123 -> V_154 &&
V_123 -> V_154 != V_145 -> V_155 )
continue;
}
if ( ! ( V_126 & V_156 ) )
F_91 ( & V_89 -> V_157 ) ;
V_125 -> V_158 = V_12 - V_17 -> V_31 ;
V_125 -> V_159 = V_135 ;
V_125 -> type = V_17 -> V_102 ;
V_125 -> V_160 = V_89 -> V_138 ;
V_125 -> V_89 = V_89 ;
V_125 -> V_161 = V_82 ;
V_125 -> V_162 = & V_4 -> V_32 ;
#ifdef F_50
F_51 ( V_63 -> V_141 ) ;
#endif
F_92 ( V_145 ) ;
return V_93 ;
}
}
#ifdef F_50
F_51 ( V_63 -> V_163 ) ;
#endif
goto V_130;
}
static void F_93 ( struct V_44 * V_45 , struct V_2 * V_5 ,
struct V_2 * V_29 , struct V_16 * V_164 )
{
struct V_165 * * V_166 = V_164 -> V_33 . V_166 ;
struct V_16 * V_17 = F_94 ( V_166 , F_95 ( * V_17 ) , V_33 . V_40 ) ;
F_96 ( & V_164 -> V_33 ) ;
if ( F_97 ( & V_29 -> V_32 ) ) {
F_33 ( V_5 , V_29 -> V_9 , NULL ) ;
F_38 ( V_29 ) ;
F_59 ( V_45 , V_5 ) ;
return;
}
if ( * V_166 )
return;
V_29 -> V_30 = V_17 -> V_31 ;
F_52 ( V_5 , V_29 ) ;
}
int F_98 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_16 * V_17 , * V_167 ;
struct V_2 * V_29 , * V_5 ;
T_5 V_90 = V_84 -> V_91 ;
T_5 V_30 = V_12 - V_90 ;
T_5 V_71 = V_84 -> V_92 ;
T_4 V_9 ;
if ( V_90 > V_12 )
return - V_94 ;
V_9 = F_67 ( V_84 -> V_95 ) ;
if ( ( V_90 < V_12 ) && ( V_9 << V_90 ) )
return - V_94 ;
V_29 = F_54 ( V_45 , & V_5 , V_9 ) ;
if ( ! V_29 )
return - V_168 ;
V_17 = F_57 ( & V_29 -> V_32 , V_30 , V_71 , 0 , V_82 -> V_73 ) ;
if ( ! V_17 )
return - V_168 ;
F_26 ( L_6 , V_9 , V_90 , V_71 , V_45 ) ;
V_167 = NULL ;
F_71 (fa, fa_list) {
struct V_88 * V_89 = V_17 -> V_75 ;
if ( ( V_17 -> V_31 != V_30 ) ||
( V_17 -> V_73 != V_82 -> V_73 ) ||
( V_17 -> V_74 != V_71 ) )
break;
if ( ( ! V_84 -> V_103 || V_17 -> V_102 == V_84 -> V_103 ) &&
( V_84 -> V_169 == V_170 ||
V_17 -> V_75 -> V_138 == V_84 -> V_169 ) &&
( ! V_84 -> V_171 ||
V_89 -> V_172 == V_84 -> V_171 ) &&
( ! V_84 -> V_173 ||
V_89 -> V_174 == V_84 -> V_173 ) &&
F_99 ( V_84 , V_89 ) == 0 ) {
V_167 = V_17 ;
break;
}
}
if ( ! V_167 )
return - V_168 ;
F_79 ( V_9 , V_90 , V_167 -> V_75 , V_71 ,
V_84 -> V_103 , V_82 -> V_73 ) ;
F_77 ( V_175 , F_78 ( V_9 ) , V_167 , V_90 , V_82 -> V_73 ,
& V_84 -> V_111 , 0 ) ;
if ( ! V_90 )
V_82 -> V_120 -- ;
F_93 ( V_45 , V_5 , V_29 , V_167 ) ;
if ( V_167 -> V_108 & V_109 )
F_76 ( V_84 -> V_111 . V_112 ) ;
F_75 ( V_167 -> V_75 ) ;
F_9 ( V_167 ) ;
return 0 ;
}
static struct V_2 * F_100 ( struct V_2 * * V_7 , T_1 V_9 )
{
struct V_2 * V_68 , * V_4 = * V_7 ;
unsigned long V_64 ;
do {
V_68 = V_4 ;
V_64 = ( V_9 > V_68 -> V_9 ) ? F_6 ( V_9 , V_68 ) : 0 ;
if ( V_64 >> V_68 -> V_8 )
break;
V_4 = F_55 ( V_68 , V_64 ++ ) ;
if ( ! V_4 )
break;
if ( F_83 ( V_4 ) && ( V_4 -> V_9 >= V_9 ) )
goto V_129;
} while ( F_28 ( V_4 ) );
while ( ! F_34 ( V_68 ) ) {
if ( V_64 >= ( 1ul << V_68 -> V_8 ) ) {
T_1 V_133 = V_68 -> V_9 ;
V_68 = F_86 ( V_68 ) ;
V_64 = F_6 ( V_133 , V_68 ) + 1 ;
continue;
}
V_4 = F_55 ( V_68 , V_64 ++ ) ;
if ( ! V_4 )
continue;
if ( F_83 ( V_4 ) )
goto V_129;
V_68 = V_4 ;
V_64 = 0 ;
}
* V_7 = V_68 ;
return NULL ;
V_129:
* V_7 = V_68 ;
return V_4 ;
}
static void F_101 ( struct V_81 * V_82 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_2 * V_68 = V_45 -> V_3 ;
unsigned long V_64 = 1 ;
struct V_165 * V_176 ;
struct V_16 * V_17 ;
for (; ; ) {
struct V_2 * V_4 ;
if ( ! ( V_64 -- ) ) {
T_1 V_133 = V_68 -> V_9 ;
if ( F_34 ( V_68 ) )
break;
V_4 = V_68 ;
V_68 = F_32 ( V_68 ) ;
F_33 ( V_68 , V_4 -> V_9 , NULL ) ;
F_38 ( V_4 ) ;
V_64 = F_6 ( V_133 , V_68 ) ;
continue;
}
V_4 = F_30 ( V_68 , V_64 ) ;
if ( ! V_4 )
continue;
if ( F_28 ( V_4 ) ) {
V_68 = V_4 ;
V_64 = 1ul << V_4 -> V_8 ;
continue;
}
F_102 (fa, tmp, &n->leaf, fa_list) {
F_96 ( & V_17 -> V_33 ) ;
F_9 ( V_17 ) ;
}
F_33 ( V_68 , V_4 -> V_9 , NULL ) ;
F_38 ( V_4 ) ;
}
#ifdef F_50
F_103 ( V_45 -> V_63 ) ;
#endif
F_12 ( V_82 ) ;
}
struct V_81 * F_104 ( struct V_81 * V_177 )
{
struct V_44 * V_178 = (struct V_44 * ) V_177 -> V_85 ;
struct V_2 * V_29 , * V_5 = V_178 -> V_3 ;
struct V_81 * V_179 ;
struct V_16 * V_17 ;
struct V_44 * V_180 ;
T_1 V_9 = 0 ;
if ( V_177 -> V_85 == V_177 -> V_181 )
return V_177 ;
V_179 = F_105 ( V_182 , NULL ) ;
if ( ! V_179 )
return NULL ;
V_180 = (struct V_44 * ) V_179 -> V_85 ;
while ( ( V_29 = F_100 ( & V_5 , V_9 ) ) != NULL ) {
struct V_2 * V_183 = NULL , * V_184 ;
F_87 (fa, &l->leaf, fa_list) {
struct V_16 * V_86 ;
if ( V_179 -> V_73 != V_17 -> V_73 )
continue;
V_86 = F_21 ( V_19 , V_26 ) ;
if ( ! V_86 )
goto V_101;
memcpy ( V_86 , V_17 , sizeof( * V_17 ) ) ;
if ( ! V_183 )
V_183 = F_54 ( V_180 , & V_184 , V_29 -> V_9 ) ;
if ( F_62 ( V_180 , V_184 , V_183 , V_86 ,
NULL , V_29 -> V_9 ) )
goto V_101;
}
V_9 = V_29 -> V_9 + 1 ;
if ( V_9 < V_29 -> V_9 )
break;
}
return V_179 ;
V_101:
F_101 ( V_179 ) ;
return NULL ;
}
void F_106 ( struct V_81 * V_82 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_2 * V_68 = V_45 -> V_3 ;
unsigned long V_64 = 1 ;
struct V_165 * V_176 ;
struct V_16 * V_17 ;
for (; ; ) {
unsigned char V_30 = 0 ;
struct V_2 * V_4 ;
if ( ! ( V_64 -- ) ) {
T_1 V_133 = V_68 -> V_9 ;
if ( F_34 ( V_68 ) )
break;
V_68 = F_42 ( V_45 , V_68 ) ;
V_64 = F_6 ( V_133 , V_68 ) ;
continue;
}
V_4 = F_30 ( V_68 , V_64 ) ;
if ( ! V_4 )
continue;
if ( F_28 ( V_4 ) ) {
V_68 = V_4 ;
V_64 = 1ul << V_4 -> V_8 ;
continue;
}
F_102 (fa, tmp, &n->leaf, fa_list) {
struct V_88 * V_89 = V_17 -> V_75 ;
if ( V_82 -> V_73 != V_17 -> V_73 ) {
F_96 ( & V_17 -> V_33 ) ;
F_9 ( V_17 ) ;
continue;
}
V_30 = V_17 -> V_31 ;
if ( ! V_89 || ! ( V_89 -> V_126 & V_185 ) )
continue;
F_79 ( V_4 -> V_9 , V_12 - V_17 -> V_31 ,
V_89 , V_17 -> V_74 , V_17 -> V_102 ,
V_82 -> V_73 ) ;
}
V_4 -> V_30 = V_30 ;
if ( F_97 ( & V_4 -> V_32 ) ) {
F_33 ( V_68 , V_4 -> V_9 , NULL ) ;
F_38 ( V_4 ) ;
}
}
}
int F_107 ( struct V_81 * V_82 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_2 * V_68 = V_45 -> V_3 ;
unsigned long V_64 = 1 ;
struct V_165 * V_176 ;
struct V_16 * V_17 ;
int V_129 = 0 ;
for (; ; ) {
unsigned char V_30 = 0 ;
struct V_2 * V_4 ;
if ( ! ( V_64 -- ) ) {
T_1 V_133 = V_68 -> V_9 ;
if ( F_34 ( V_68 ) )
break;
V_68 = F_42 ( V_45 , V_68 ) ;
V_64 = F_6 ( V_133 , V_68 ) ;
continue;
}
V_4 = F_30 ( V_68 , V_64 ) ;
if ( ! V_4 )
continue;
if ( F_28 ( V_4 ) ) {
V_68 = V_4 ;
V_64 = 1ul << V_4 -> V_8 ;
continue;
}
F_102 (fa, tmp, &n->leaf, fa_list) {
struct V_88 * V_89 = V_17 -> V_75 ;
if ( ! V_89 || ! ( V_89 -> V_126 & V_142 ) ) {
V_30 = V_17 -> V_31 ;
continue;
}
F_79 ( V_4 -> V_9 , V_12 - V_17 -> V_31 ,
V_89 , V_17 -> V_74 , V_17 -> V_102 ,
V_82 -> V_73 ) ;
F_96 ( & V_17 -> V_33 ) ;
F_75 ( V_17 -> V_75 ) ;
F_9 ( V_17 ) ;
V_129 ++ ;
}
V_4 -> V_30 = V_30 ;
if ( F_97 ( & V_4 -> V_32 ) ) {
F_33 ( V_68 , V_4 -> V_9 , NULL ) ;
F_38 ( V_4 ) ;
}
}
F_26 ( L_7 , V_129 ) ;
return V_129 ;
}
static void F_108 ( struct V_14 * V_15 )
{
struct V_81 * V_82 = F_2 ( V_15 , struct V_81 , V_18 ) ;
#ifdef F_50
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
if ( V_82 -> V_85 == V_82 -> V_181 )
F_103 ( V_45 -> V_63 ) ;
#endif
F_12 ( V_82 ) ;
}
void F_109 ( struct V_81 * V_82 )
{
F_10 ( & V_82 -> V_18 , F_108 ) ;
}
static int F_110 ( struct V_2 * V_29 , struct V_81 * V_82 ,
struct V_186 * V_187 , struct V_188 * V_189 )
{
T_7 V_190 = F_78 ( V_29 -> V_9 ) ;
struct V_16 * V_17 ;
int V_35 , V_191 ;
V_191 = V_189 -> args [ 4 ] ;
V_35 = 0 ;
F_87 (fa, &l->leaf, fa_list) {
if ( V_35 < V_191 ) {
V_35 ++ ;
continue;
}
if ( V_82 -> V_73 != V_17 -> V_73 ) {
V_35 ++ ;
continue;
}
if ( F_111 ( V_187 , F_112 ( V_189 -> V_187 ) . V_192 ,
V_189 -> V_193 -> V_194 ,
V_113 ,
V_82 -> V_73 ,
V_17 -> V_102 ,
V_190 ,
V_12 - V_17 -> V_31 ,
V_17 -> V_74 ,
V_17 -> V_75 , V_195 ) < 0 ) {
V_189 -> args [ 4 ] = V_35 ;
return - 1 ;
}
V_35 ++ ;
}
V_189 -> args [ 4 ] = V_35 ;
return V_187 -> V_196 ;
}
int F_113 ( struct V_81 * V_82 , struct V_186 * V_187 ,
struct V_188 * V_189 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_2 * V_29 , * V_5 = V_45 -> V_3 ;
int V_197 = V_189 -> args [ 2 ] ;
T_1 V_9 = V_189 -> args [ 3 ] ;
while ( ( V_29 = F_100 ( & V_5 , V_9 ) ) != NULL ) {
if ( F_110 ( V_29 , V_82 , V_187 , V_189 ) < 0 ) {
V_189 -> args [ 3 ] = V_9 ;
V_189 -> args [ 2 ] = V_197 ;
return - 1 ;
}
++ V_197 ;
V_9 = V_29 -> V_9 + 1 ;
memset ( & V_189 -> args [ 4 ] , 0 ,
sizeof( V_189 -> args ) - 4 * sizeof( V_189 -> args [ 0 ] ) ) ;
if ( V_9 < V_29 -> V_9 )
break;
}
V_189 -> args [ 3 ] = V_9 ;
V_189 -> args [ 2 ] = V_197 ;
return V_187 -> V_196 ;
}
void T_8 F_114 ( void )
{
V_19 = F_115 ( L_8 ,
sizeof( struct V_16 ) ,
0 , V_198 , NULL ) ;
V_21 = F_115 ( L_9 ,
V_199 ,
0 , V_198 , NULL ) ;
}
struct V_81 * F_105 ( T_4 V_200 , struct V_81 * V_201 )
{
struct V_81 * V_82 ;
struct V_44 * V_45 ;
T_2 V_202 = sizeof( * V_82 ) ;
if ( ! V_201 )
V_202 += sizeof( struct V_44 ) ;
V_82 = F_16 ( V_202 , V_26 ) ;
if ( ! V_82 )
return NULL ;
V_82 -> V_73 = V_200 ;
V_82 -> V_120 = 0 ;
V_82 -> V_85 = ( V_201 ? V_201 -> V_181 : V_82 -> V_181 ) ;
if ( V_201 )
return V_82 ;
V_45 = (struct V_44 * ) V_82 -> V_85 ;
V_45 -> V_3 [ 0 ] . V_13 = V_12 ;
V_45 -> V_3 [ 0 ] . V_30 = V_12 ;
#ifdef F_50
V_45 -> V_63 = F_116 ( struct V_62 ) ;
if ( ! V_45 -> V_63 ) {
F_12 ( V_82 ) ;
V_82 = NULL ;
}
#endif
return V_82 ;
}
static struct V_2 * F_117 ( struct V_203 * V_204 )
{
unsigned long V_64 = V_204 -> V_10 ;
struct V_2 * V_68 = V_204 -> V_1 ;
T_1 V_133 ;
F_26 ( L_10 ,
V_204 -> V_1 , V_204 -> V_10 , V_204 -> V_205 ) ;
while ( ! F_34 ( V_68 ) ) {
while ( V_64 < F_5 ( V_68 ) ) {
struct V_2 * V_4 = F_55 ( V_68 , V_64 ++ ) ;
if ( ! V_4 )
continue;
if ( F_83 ( V_4 ) ) {
V_204 -> V_1 = V_68 ;
V_204 -> V_10 = V_64 ;
} else {
V_204 -> V_1 = V_4 ;
V_204 -> V_10 = 0 ;
++ V_204 -> V_205 ;
}
return V_4 ;
}
V_133 = V_68 -> V_9 ;
V_68 = F_86 ( V_68 ) ;
V_64 = F_6 ( V_133 , V_68 ) + 1 ;
-- V_204 -> V_205 ;
}
V_204 -> V_1 = V_68 ;
V_204 -> V_10 = 0 ;
return NULL ;
}
static struct V_2 * F_118 ( struct V_203 * V_204 ,
struct V_44 * V_45 )
{
struct V_2 * V_4 , * V_68 ;
if ( ! V_45 )
return NULL ;
V_68 = V_45 -> V_3 ;
V_4 = F_85 ( V_68 -> V_1 [ 0 ] ) ;
if ( ! V_4 )
return NULL ;
if ( F_28 ( V_4 ) ) {
V_204 -> V_1 = V_4 ;
V_204 -> V_10 = 0 ;
V_204 -> V_205 = 1 ;
} else {
V_204 -> V_1 = V_68 ;
V_204 -> V_10 = 0 ;
V_204 -> V_205 = 0 ;
}
return V_4 ;
}
static void F_119 ( struct V_44 * V_45 , struct V_206 * V_207 )
{
struct V_2 * V_4 ;
struct V_203 V_204 ;
memset ( V_207 , 0 , sizeof( * V_207 ) ) ;
F_120 () ;
for ( V_4 = F_118 ( & V_204 , V_45 ) ; V_4 ; V_4 = F_117 ( & V_204 ) ) {
if ( F_83 ( V_4 ) ) {
struct V_16 * V_17 ;
V_207 -> V_208 ++ ;
V_207 -> V_209 += V_204 . V_205 ;
if ( V_204 . V_205 > V_207 -> V_210 )
V_207 -> V_210 = V_204 . V_205 ;
F_87 ( V_17 , & V_4 -> V_32 , V_33 )
++ V_207 -> V_211 ;
} else {
V_207 -> V_212 ++ ;
if ( V_4 -> V_8 < V_213 )
V_207 -> V_214 [ V_4 -> V_8 ] ++ ;
V_207 -> V_215 += F_1 ( V_4 ) -> V_27 ;
}
}
F_121 () ;
}
static void F_122 ( struct V_216 * V_217 , struct V_206 * V_218 )
{
unsigned int V_35 , V_219 , V_220 , V_221 , V_222 ;
if ( V_218 -> V_208 )
V_222 = V_218 -> V_209 * 100 / V_218 -> V_208 ;
else
V_222 = 0 ;
F_123 ( V_217 , L_11 ,
V_222 / 100 , V_222 % 100 ) ;
F_123 ( V_217 , L_12 , V_218 -> V_210 ) ;
F_123 ( V_217 , L_13 , V_218 -> V_208 ) ;
V_221 = V_199 * V_218 -> V_208 ;
F_123 ( V_217 , L_14 , V_218 -> V_211 ) ;
V_221 += sizeof( struct V_16 ) * V_218 -> V_211 ;
F_123 ( V_217 , L_15 , V_218 -> V_212 ) ;
V_221 += F_15 ( 0 ) * V_218 -> V_212 ;
V_219 = V_213 ;
while ( V_219 > 0 && V_218 -> V_214 [ V_219 - 1 ] == 0 )
V_219 -- ;
V_220 = 0 ;
for ( V_35 = 1 ; V_35 < V_219 ; V_35 ++ )
if ( V_218 -> V_214 [ V_35 ] != 0 ) {
F_123 ( V_217 , L_16 , V_35 , V_218 -> V_214 [ V_35 ] ) ;
V_220 += ( 1 << V_35 ) * V_218 -> V_214 [ V_35 ] ;
}
F_124 ( V_217 , '\n' ) ;
F_123 ( V_217 , L_17 , V_220 ) ;
V_221 += sizeof( struct V_2 * ) * V_220 ;
F_123 ( V_217 , L_18 , V_218 -> V_215 ) ;
F_123 ( V_217 , L_19 , ( V_221 + 1023 ) / 1024 ) ;
}
static void F_125 ( struct V_216 * V_217 ,
const struct V_62 T_3 * V_63 )
{
struct V_62 V_207 = { 0 } ;
int V_223 ;
F_126 (cpu) {
const struct V_62 * V_224 = F_127 ( V_63 , V_223 ) ;
V_207 . gets += V_224 -> gets ;
V_207 . V_134 += V_224 -> V_134 ;
V_207 . V_141 += V_224 -> V_141 ;
V_207 . V_163 += V_224 -> V_163 ;
V_207 . V_132 += V_224 -> V_132 ;
V_207 . V_67 += V_224 -> V_67 ;
}
F_123 ( V_217 , L_20 ) ;
F_123 ( V_217 , L_21 , V_207 . gets ) ;
F_123 ( V_217 , L_22 , V_207 . V_134 ) ;
F_123 ( V_217 , L_23 ,
V_207 . V_141 ) ;
F_123 ( V_217 , L_24 , V_207 . V_163 ) ;
F_123 ( V_217 , L_25 , V_207 . V_132 ) ;
F_123 ( V_217 , L_26 , V_207 . V_67 ) ;
}
static void F_128 ( struct V_216 * V_217 , struct V_81 * V_82 )
{
if ( V_82 -> V_73 == V_182 )
F_129 ( V_217 , L_27 ) ;
else if ( V_82 -> V_73 == V_225 )
F_129 ( V_217 , L_28 ) ;
else
F_123 ( V_217 , L_29 , V_82 -> V_73 ) ;
}
static int F_130 ( struct V_216 * V_217 , void * V_226 )
{
struct V_227 * V_227 = (struct V_227 * ) V_217 -> V_228 ;
unsigned int V_229 ;
F_123 ( V_217 ,
L_30
L_31 ,
V_199 , F_15 ( 0 ) ) ;
for ( V_229 = 0 ; V_229 < V_230 ; V_229 ++ ) {
struct V_69 * V_15 = & V_227 -> V_231 . V_232 [ V_229 ] ;
struct V_81 * V_82 ;
F_87 (tb, head, tb_hlist) {
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_206 V_218 ;
if ( ! V_45 )
continue;
F_128 ( V_217 , V_82 ) ;
F_119 ( V_45 , & V_218 ) ;
F_122 ( V_217 , & V_218 ) ;
#ifdef F_50
F_125 ( V_217 , V_45 -> V_63 ) ;
#endif
}
}
return 0 ;
}
static int F_131 ( struct V_39 * V_39 , struct V_233 * V_233 )
{
return F_132 ( V_39 , V_233 , F_130 ) ;
}
static struct V_2 * F_133 ( struct V_216 * V_217 , T_9 V_13 )
{
struct V_203 * V_204 = V_217 -> V_228 ;
struct V_227 * V_227 = F_134 ( V_217 ) ;
T_9 V_234 = 0 ;
unsigned int V_229 ;
for ( V_229 = 0 ; V_229 < V_230 ; V_229 ++ ) {
struct V_69 * V_15 = & V_227 -> V_231 . V_232 [ V_229 ] ;
struct V_81 * V_82 ;
F_87 (tb, head, tb_hlist) {
struct V_2 * V_4 ;
for ( V_4 = F_118 ( V_204 ,
(struct V_44 * ) V_82 -> V_85 ) ;
V_4 ; V_4 = F_117 ( V_204 ) )
if ( V_13 == V_234 ++ ) {
V_204 -> V_82 = V_82 ;
return V_4 ;
}
}
}
return NULL ;
}
static void * F_135 ( struct V_216 * V_217 , T_9 * V_13 )
__acquires( T_10 )
{
F_120 () ;
return F_133 ( V_217 , * V_13 ) ;
}
static void * F_136 ( struct V_216 * V_217 , void * V_226 , T_9 * V_13 )
{
struct V_203 * V_204 = V_217 -> V_228 ;
struct V_227 * V_227 = F_134 ( V_217 ) ;
struct V_81 * V_82 = V_204 -> V_82 ;
struct V_165 * V_235 ;
unsigned int V_229 ;
struct V_2 * V_4 ;
++ * V_13 ;
V_4 = F_117 ( V_204 ) ;
if ( V_4 )
return V_4 ;
V_229 = V_82 -> V_73 & ( V_230 - 1 ) ;
while ( ( V_235 = F_85 ( F_137 ( & V_82 -> V_236 ) ) ) ) {
V_82 = F_94 ( V_235 , struct V_81 , V_236 ) ;
V_4 = F_118 ( V_204 , (struct V_44 * ) V_82 -> V_85 ) ;
if ( V_4 )
goto V_129;
}
while ( ++ V_229 < V_230 ) {
struct V_69 * V_15 = & V_227 -> V_231 . V_232 [ V_229 ] ;
F_87 (tb, head, tb_hlist) {
V_4 = F_118 ( V_204 , (struct V_44 * ) V_82 -> V_85 ) ;
if ( V_4 )
goto V_129;
}
}
return NULL ;
V_129:
V_204 -> V_82 = V_82 ;
return V_4 ;
}
static void F_138 ( struct V_216 * V_217 , void * V_226 )
__releases( T_10 )
{
F_121 () ;
}
static void F_139 ( struct V_216 * V_217 , int V_4 )
{
while ( V_4 -- > 0 )
F_129 ( V_217 , L_32 ) ;
}
static inline const char * F_140 ( char * V_237 , T_2 V_196 , enum V_238 V_207 )
{
switch ( V_207 ) {
case V_239 : return L_33 ;
case V_240 : return L_34 ;
case V_241 : return L_35 ;
case V_242 : return L_36 ;
case V_170 : return L_37 ;
default:
snprintf ( V_237 , V_196 , L_38 , V_207 ) ;
return V_237 ;
}
}
static inline const char * F_141 ( char * V_237 , T_2 V_196 , unsigned int V_45 )
{
if ( V_45 < V_243 && V_244 [ V_45 ] )
return V_244 [ V_45 ] ;
snprintf ( V_237 , V_196 , L_39 , V_45 ) ;
return V_237 ;
}
static int F_142 ( struct V_216 * V_217 , void * V_226 )
{
const struct V_203 * V_204 = V_217 -> V_228 ;
struct V_2 * V_4 = V_226 ;
if ( F_34 ( F_86 ( V_4 ) ) )
F_128 ( V_217 , V_204 -> V_82 ) ;
if ( F_28 ( V_4 ) ) {
T_7 V_245 = F_78 ( V_4 -> V_9 ) ;
F_139 ( V_217 , V_204 -> V_205 - 1 ) ;
F_123 ( V_217 , L_40 ,
& V_245 , V_12 - V_4 -> V_13 - V_4 -> V_8 , V_4 -> V_8 ,
F_1 ( V_4 ) -> V_28 ,
F_1 ( V_4 ) -> V_27 ) ;
} else {
T_7 V_246 = F_78 ( V_4 -> V_9 ) ;
struct V_16 * V_17 ;
F_139 ( V_217 , V_204 -> V_205 ) ;
F_123 ( V_217 , L_41 , & V_246 ) ;
F_87 (fa, &n->leaf, fa_list) {
char V_247 [ 32 ] , V_248 [ 32 ] ;
F_139 ( V_217 , V_204 -> V_205 + 1 ) ;
F_123 ( V_217 , L_42 ,
V_12 - V_17 -> V_31 ,
F_140 ( V_247 , sizeof( V_247 ) ,
V_17 -> V_75 -> V_138 ) ,
F_141 ( V_248 , sizeof( V_248 ) ,
V_17 -> V_102 ) ) ;
if ( V_17 -> V_74 )
F_123 ( V_217 , L_43 , V_17 -> V_74 ) ;
F_124 ( V_217 , '\n' ) ;
}
}
return 0 ;
}
static int F_143 ( struct V_39 * V_39 , struct V_233 * V_233 )
{
return F_144 ( V_39 , V_233 , & V_249 ,
sizeof( struct V_203 ) ) ;
}
static struct V_2 * F_145 ( struct V_250 * V_204 ,
T_9 V_13 )
{
struct V_81 * V_82 = V_204 -> V_251 ;
struct V_2 * V_29 , * * V_5 = & V_204 -> V_1 ;
struct V_44 * V_45 ;
T_1 V_9 ;
if ( V_204 -> V_13 > 0 && V_13 >= V_204 -> V_13 ) {
V_13 -= V_204 -> V_13 ;
V_9 = V_204 -> V_9 ;
} else {
V_45 = (struct V_44 * ) V_82 -> V_85 ;
V_204 -> V_1 = V_45 -> V_3 ;
V_204 -> V_13 = 0 ;
V_9 = 0 ;
}
while ( ( V_29 = F_100 ( V_5 , V_9 ) ) != NULL ) {
V_9 = V_29 -> V_9 + 1 ;
V_204 -> V_13 ++ ;
if ( -- V_13 <= 0 )
break;
V_29 = NULL ;
if ( ! V_9 )
break;
}
if ( V_29 )
V_204 -> V_9 = V_9 ;
else
V_204 -> V_13 = 0 ;
return V_29 ;
}
static void * F_146 ( struct V_216 * V_217 , T_9 * V_13 )
__acquires( T_10 )
{
struct V_250 * V_204 = V_217 -> V_228 ;
struct V_81 * V_82 ;
struct V_44 * V_45 ;
F_120 () ;
V_82 = F_147 ( F_134 ( V_217 ) , V_225 ) ;
if ( ! V_82 )
return NULL ;
V_204 -> V_251 = V_82 ;
if ( * V_13 != 0 )
return F_145 ( V_204 , * V_13 ) ;
V_45 = (struct V_44 * ) V_82 -> V_85 ;
V_204 -> V_1 = V_45 -> V_3 ;
V_204 -> V_13 = 0 ;
V_204 -> V_9 = 0 ;
return V_252 ;
}
static void * F_148 ( struct V_216 * V_217 , void * V_226 , T_9 * V_13 )
{
struct V_250 * V_204 = V_217 -> V_228 ;
struct V_2 * V_29 = NULL ;
T_1 V_9 = V_204 -> V_9 ;
++ * V_13 ;
if ( ( V_226 == V_252 ) || V_9 )
V_29 = F_100 ( & V_204 -> V_1 , V_9 ) ;
if ( V_29 ) {
V_204 -> V_9 = V_29 -> V_9 + 1 ;
V_204 -> V_13 ++ ;
} else {
V_204 -> V_13 = 0 ;
}
return V_29 ;
}
static void F_149 ( struct V_216 * V_217 , void * V_226 )
__releases( T_10 )
{
F_121 () ;
}
static unsigned int F_150 ( int type , T_7 V_253 , const struct V_88 * V_89 )
{
unsigned int V_254 = 0 ;
if ( type == V_255 || type == V_256 )
V_254 = V_257 ;
if ( V_89 && V_89 -> V_144 -> V_258 )
V_254 |= V_259 ;
if ( V_253 == F_78 ( 0xFFFFFFFF ) )
V_254 |= V_260 ;
V_254 |= V_261 ;
return V_254 ;
}
static int F_151 ( struct V_216 * V_217 , void * V_226 )
{
struct V_250 * V_204 = V_217 -> V_228 ;
struct V_81 * V_82 = V_204 -> V_251 ;
struct V_16 * V_17 ;
struct V_2 * V_29 = V_226 ;
T_7 V_121 ;
if ( V_226 == V_252 ) {
F_123 ( V_217 , L_44 , L_45
L_46
L_47 ) ;
return 0 ;
}
V_121 = F_78 ( V_29 -> V_9 ) ;
F_87 (fa, &l->leaf, fa_list) {
const struct V_88 * V_89 = V_17 -> V_75 ;
T_7 V_253 = F_152 ( V_12 - V_17 -> V_31 ) ;
unsigned int V_254 = F_150 ( V_17 -> V_102 , V_253 , V_89 ) ;
if ( ( V_17 -> V_102 == V_262 ) ||
( V_17 -> V_102 == V_263 ) )
continue;
if ( V_17 -> V_73 != V_82 -> V_73 )
continue;
F_153 ( V_217 , 127 ) ;
if ( V_89 )
F_123 ( V_217 ,
L_48
L_49 ,
V_89 -> V_264 ? V_89 -> V_264 -> V_265 : L_50 ,
V_121 ,
V_89 -> V_144 -> V_258 , V_254 , 0 , 0 ,
V_89 -> V_76 ,
V_253 ,
( V_89 -> V_266 ?
V_89 -> V_266 + 40 : 0 ) ,
V_89 -> V_267 ,
V_89 -> V_268 >> 3 ) ;
else
F_123 ( V_217 ,
L_51
L_49 ,
V_121 , 0 , V_254 , 0 , 0 , 0 ,
V_253 , 0 , 0 , 0 ) ;
F_154 ( V_217 , '\n' ) ;
}
return 0 ;
}
static int F_155 ( struct V_39 * V_39 , struct V_233 * V_233 )
{
return F_144 ( V_39 , V_233 , & V_269 ,
sizeof( struct V_250 ) ) ;
}
int T_11 F_156 ( struct V_227 * V_227 )
{
if ( ! F_157 ( L_52 , V_270 , V_227 -> V_271 , & V_272 ) )
goto V_273;
if ( ! F_157 ( L_53 , V_270 , V_227 -> V_271 ,
& V_274 ) )
goto V_275;
if ( ! F_157 ( L_54 , V_270 , V_227 -> V_271 , & V_276 ) )
goto V_277;
return 0 ;
V_277:
F_158 ( L_53 , V_227 -> V_271 ) ;
V_275:
F_158 ( L_52 , V_227 -> V_271 ) ;
V_273:
return - V_79 ;
}
void T_12 F_159 ( struct V_227 * V_227 )
{
F_158 ( L_52 , V_227 -> V_271 ) ;
F_158 ( L_53 , V_227 -> V_271 ) ;
F_158 ( L_54 , V_227 -> V_271 ) ;
}
