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
struct V_1 * V_3 = F_21 ( V_21 , V_26 ) ;
struct V_2 * V_29 = V_3 -> V_3 ;
if ( ! V_3 )
return NULL ;
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
struct V_1 * V_1 = F_14 ( V_8 ) ;
unsigned int V_34 = V_13 + V_8 ;
struct V_2 * V_7 = V_1 -> V_3 ;
F_25 ( ! V_8 || ( V_34 > V_12 ) ) ;
F_26 ( L_1 , V_1 , F_15 ( 0 ) ,
sizeof( struct V_2 * ) << V_8 ) ;
if ( ! V_1 )
return NULL ;
if ( V_8 == V_12 )
V_1 -> V_28 = 1 ;
else
V_1 -> V_27 = 1ul << V_8 ;
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
struct V_87 * V_88 ;
T_5 V_89 = V_84 -> V_90 ;
T_5 V_30 = V_12 - V_89 ;
T_5 V_71 = V_84 -> V_91 ;
T_4 V_9 ;
int V_92 ;
if ( V_89 > V_12 )
return - V_93 ;
V_9 = F_67 ( V_84 -> V_94 ) ;
F_26 ( L_5 , V_82 -> V_73 , V_9 , V_89 ) ;
if ( ( V_89 < V_12 ) && ( V_9 << V_89 ) )
return - V_93 ;
V_88 = F_68 ( V_84 ) ;
if ( F_69 ( V_88 ) ) {
V_92 = F_70 ( V_88 ) ;
goto V_92;
}
V_29 = F_54 ( V_45 , & V_5 , V_9 ) ;
V_17 = V_29 ? F_57 ( & V_29 -> V_32 , V_30 , V_71 , V_88 -> V_76 ,
V_82 -> V_73 ) : NULL ;
if ( V_17 && V_17 -> V_74 == V_71 &&
V_17 -> V_75 -> V_76 == V_88 -> V_76 ) {
struct V_16 * V_95 , * V_96 ;
V_92 = - V_97 ;
if ( V_84 -> V_98 & V_99 )
goto V_100;
V_96 = NULL ;
V_95 = V_17 ;
F_71 (fa, fa_list) {
if ( ( V_17 -> V_31 != V_30 ) ||
( V_17 -> V_73 != V_82 -> V_73 ) ||
( V_17 -> V_74 != V_71 ) )
break;
if ( V_17 -> V_75 -> V_76 != V_88 -> V_76 )
break;
if ( V_17 -> V_101 == V_84 -> V_102 &&
V_17 -> V_75 == V_88 ) {
V_96 = V_17 ;
break;
}
}
if ( V_84 -> V_98 & V_103 ) {
struct V_87 * V_104 ;
T_5 V_105 ;
V_17 = V_95 ;
if ( V_96 ) {
if ( V_17 == V_96 )
V_92 = 0 ;
goto V_100;
}
V_92 = - V_106 ;
V_86 = F_21 ( V_19 , V_26 ) ;
if ( ! V_86 )
goto V_100;
V_104 = V_17 -> V_75 ;
V_86 -> V_74 = V_17 -> V_74 ;
V_86 -> V_75 = V_88 ;
V_86 -> V_101 = V_84 -> V_102 ;
V_105 = V_17 -> V_107 ;
V_86 -> V_107 = V_105 & ~ V_108 ;
V_86 -> V_31 = V_17 -> V_31 ;
V_86 -> V_73 = V_82 -> V_73 ;
V_92 = F_72 ( V_9 , V_89 , V_88 ,
V_86 -> V_74 ,
V_84 -> V_102 ,
V_84 -> V_98 ,
V_82 -> V_73 ) ;
if ( V_92 ) {
F_73 ( V_88 ) ;
F_8 ( V_19 , V_86 ) ;
goto V_100;
}
F_74 ( & V_17 -> V_33 , & V_86 -> V_33 ) ;
F_9 ( V_17 ) ;
F_75 ( V_104 ) ;
if ( V_105 & V_108 )
F_76 ( V_84 -> V_109 . V_110 ) ;
F_77 ( V_111 , F_78 ( V_9 ) , V_86 , V_89 ,
V_82 -> V_73 , & V_84 -> V_109 , V_103 ) ;
goto V_112;
}
if ( V_96 )
goto V_100;
if ( ! ( V_84 -> V_98 & V_113 ) )
V_17 = V_95 ;
}
V_92 = - V_114 ;
if ( ! ( V_84 -> V_98 & V_115 ) )
goto V_100;
V_92 = - V_106 ;
V_86 = F_21 ( V_19 , V_26 ) ;
if ( ! V_86 )
goto V_100;
V_86 -> V_75 = V_88 ;
V_86 -> V_74 = V_71 ;
V_86 -> V_101 = V_84 -> V_102 ;
V_86 -> V_107 = 0 ;
V_86 -> V_31 = V_30 ;
V_86 -> V_73 = V_82 -> V_73 ;
V_92 = F_72 ( V_9 , V_89 , V_88 , V_71 ,
V_84 -> V_102 ,
V_84 -> V_98 ,
V_82 -> V_73 ) ;
if ( V_92 ) {
F_73 ( V_88 ) ;
goto V_116;
}
V_92 = F_62 ( V_45 , V_5 , V_29 , V_86 , V_17 , V_9 ) ;
if ( V_92 )
goto V_117;
if ( ! V_89 )
V_82 -> V_118 ++ ;
F_76 ( V_84 -> V_109 . V_110 ) ;
F_77 ( V_111 , F_78 ( V_9 ) , V_86 , V_89 , V_86 -> V_73 ,
& V_84 -> V_109 , 0 ) ;
V_112:
return 0 ;
V_117:
F_79 ( V_9 , V_89 , V_88 , V_71 , V_84 -> V_102 , V_82 -> V_73 ) ;
V_116:
F_8 ( V_19 , V_86 ) ;
V_100:
F_75 ( V_88 ) ;
V_92:
return V_92 ;
}
static inline T_1 F_80 ( T_1 V_9 , struct V_2 * V_4 )
{
T_1 V_119 = V_4 -> V_9 ;
return ( V_9 ^ V_119 ) & ( V_119 | - V_119 ) ;
}
int F_81 ( struct V_81 * V_82 , const struct V_120 * V_121 ,
struct V_122 * V_123 , int V_124 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
#ifdef F_50
struct V_62 T_3 * V_63 = V_45 -> V_63 ;
#endif
const T_1 V_9 = F_67 ( V_121 -> V_125 ) ;
struct V_2 * V_4 , * V_68 ;
struct V_16 * V_17 ;
unsigned long V_10 ;
T_1 V_64 ;
V_68 = V_45 -> V_3 ;
V_64 = 0 ;
V_4 = F_55 ( V_68 , V_64 ) ;
if ( ! V_4 )
return - V_126 ;
#ifdef F_50
F_51 ( V_63 -> gets ) ;
#endif
for (; ; ) {
V_10 = F_56 ( V_9 , V_4 ) ;
if ( V_10 >= ( 1ul << V_4 -> V_8 ) )
break;
if ( F_82 ( V_4 ) )
goto V_127;
if ( V_4 -> V_30 > V_4 -> V_13 ) {
V_68 = V_4 ;
V_64 = V_10 ;
}
V_4 = F_55 ( V_4 , V_10 ) ;
if ( F_83 ( ! V_4 ) )
goto V_128;
}
for (; ; ) {
struct V_2 T_6 * * V_129 = V_4 -> V_1 ;
if ( F_83 ( F_80 ( V_9 , V_4 ) ) || ( V_4 -> V_30 == V_4 -> V_13 ) )
goto V_128;
if ( F_83 ( F_82 ( V_4 ) ) )
break;
while ( ( V_4 = F_84 ( * V_129 ) ) == NULL ) {
V_128:
#ifdef F_50
if ( ! V_4 )
F_51 ( V_63 -> V_130 ) ;
#endif
while ( ! V_64 ) {
T_1 V_131 = V_68 -> V_9 ;
if ( F_34 ( V_68 ) )
return - V_126 ;
#ifdef F_50
F_51 ( V_63 -> V_132 ) ;
#endif
V_68 = F_85 ( V_68 ) ;
V_64 = F_6 ( V_131 , V_68 ) ;
}
V_64 &= V_64 - 1 ;
V_129 = & V_68 -> V_1 [ V_64 ] ;
}
}
V_127:
V_10 = V_9 ^ V_4 -> V_9 ;
F_86 (fa, &n->leaf, fa_list) {
struct V_87 * V_88 = V_17 -> V_75 ;
int V_133 , V_92 ;
if ( ( V_10 >= ( 1ul << V_17 -> V_31 ) ) &&
( ( V_11 > V_12 ) || ( V_17 -> V_31 != V_12 ) ) )
continue;
if ( V_17 -> V_74 && V_17 -> V_74 != V_121 -> V_134 )
continue;
if ( V_88 -> V_135 )
continue;
if ( V_17 -> V_75 -> V_136 < V_121 -> V_137 )
continue;
F_87 ( V_17 ) ;
V_92 = V_138 [ V_17 -> V_101 ] . error ;
if ( F_83 ( V_92 < 0 ) ) {
#ifdef F_50
F_51 ( V_63 -> V_139 ) ;
#endif
return V_92 ;
}
if ( V_88 -> V_124 & V_140 )
continue;
for ( V_133 = 0 ; V_133 < V_88 -> V_141 ; V_133 ++ ) {
const struct V_142 * V_143 = & V_88 -> V_142 [ V_133 ] ;
if ( V_143 -> V_144 & V_140 )
continue;
if ( V_121 -> V_145 && V_121 -> V_145 != V_143 -> V_146 )
continue;
if ( ! ( V_124 & V_147 ) )
F_88 ( & V_88 -> V_148 ) ;
V_123 -> V_149 = V_12 - V_17 -> V_31 ;
V_123 -> V_150 = V_133 ;
V_123 -> type = V_17 -> V_101 ;
V_123 -> V_151 = V_88 -> V_136 ;
V_123 -> V_88 = V_88 ;
V_123 -> V_152 = V_82 ;
V_123 -> V_153 = & V_4 -> V_32 ;
#ifdef F_50
F_51 ( V_63 -> V_139 ) ;
#endif
return V_92 ;
}
}
#ifdef F_50
F_51 ( V_63 -> V_154 ) ;
#endif
goto V_128;
}
static void F_89 ( struct V_44 * V_45 , struct V_2 * V_5 ,
struct V_2 * V_29 , struct V_16 * V_155 )
{
struct V_156 * * V_157 = V_155 -> V_33 . V_157 ;
struct V_16 * V_17 = F_90 ( V_157 , F_91 ( * V_17 ) , V_33 . V_40 ) ;
F_92 ( & V_155 -> V_33 ) ;
if ( F_93 ( & V_29 -> V_32 ) ) {
F_33 ( V_5 , V_29 -> V_9 , NULL ) ;
F_38 ( V_29 ) ;
F_59 ( V_45 , V_5 ) ;
return;
}
if ( * V_157 )
return;
V_29 -> V_30 = V_17 -> V_31 ;
F_52 ( V_5 , V_29 ) ;
}
int F_94 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_16 * V_17 , * V_158 ;
struct V_2 * V_29 , * V_5 ;
T_5 V_89 = V_84 -> V_90 ;
T_5 V_30 = V_12 - V_89 ;
T_5 V_71 = V_84 -> V_91 ;
T_4 V_9 ;
if ( V_89 > V_12 )
return - V_93 ;
V_9 = F_67 ( V_84 -> V_94 ) ;
if ( ( V_89 < V_12 ) && ( V_9 << V_89 ) )
return - V_93 ;
V_29 = F_54 ( V_45 , & V_5 , V_9 ) ;
if ( ! V_29 )
return - V_159 ;
V_17 = F_57 ( & V_29 -> V_32 , V_30 , V_71 , 0 , V_82 -> V_73 ) ;
if ( ! V_17 )
return - V_159 ;
F_26 ( L_6 , V_9 , V_89 , V_71 , V_45 ) ;
V_158 = NULL ;
F_71 (fa, fa_list) {
struct V_87 * V_88 = V_17 -> V_75 ;
if ( ( V_17 -> V_31 != V_30 ) ||
( V_17 -> V_73 != V_82 -> V_73 ) ||
( V_17 -> V_74 != V_71 ) )
break;
if ( ( ! V_84 -> V_102 || V_17 -> V_101 == V_84 -> V_102 ) &&
( V_84 -> V_160 == V_161 ||
V_17 -> V_75 -> V_136 == V_84 -> V_160 ) &&
( ! V_84 -> V_162 ||
V_88 -> V_163 == V_84 -> V_162 ) &&
( ! V_84 -> V_164 ||
V_88 -> V_165 == V_84 -> V_164 ) &&
F_95 ( V_84 , V_88 ) == 0 ) {
V_158 = V_17 ;
break;
}
}
if ( ! V_158 )
return - V_159 ;
F_79 ( V_9 , V_89 , V_158 -> V_75 , V_71 ,
V_84 -> V_102 , V_82 -> V_73 ) ;
F_77 ( V_166 , F_78 ( V_9 ) , V_158 , V_89 , V_82 -> V_73 ,
& V_84 -> V_109 , 0 ) ;
if ( ! V_89 )
V_82 -> V_118 -- ;
F_89 ( V_45 , V_5 , V_29 , V_158 ) ;
if ( V_158 -> V_107 & V_108 )
F_76 ( V_84 -> V_109 . V_110 ) ;
F_75 ( V_158 -> V_75 ) ;
F_9 ( V_158 ) ;
return 0 ;
}
static struct V_2 * F_96 ( struct V_2 * * V_7 , T_1 V_9 )
{
struct V_2 * V_68 , * V_4 = * V_7 ;
unsigned long V_64 ;
do {
V_68 = V_4 ;
V_64 = V_9 ? F_6 ( V_9 , V_68 ) : 0 ;
if ( V_64 >> V_68 -> V_8 )
break;
V_4 = F_55 ( V_68 , V_64 ++ ) ;
if ( ! V_4 )
break;
if ( F_82 ( V_4 ) && ( V_4 -> V_9 >= V_9 ) )
goto V_127;
} while ( F_28 ( V_4 ) );
while ( ! F_34 ( V_68 ) ) {
if ( V_64 >= ( 1ul << V_68 -> V_8 ) ) {
T_1 V_131 = V_68 -> V_9 ;
V_68 = F_85 ( V_68 ) ;
V_64 = F_6 ( V_131 , V_68 ) + 1 ;
continue;
}
V_4 = F_55 ( V_68 , V_64 ++ ) ;
if ( ! V_4 )
continue;
if ( F_82 ( V_4 ) )
goto V_127;
V_68 = V_4 ;
V_64 = 0 ;
}
* V_7 = V_68 ;
return NULL ;
V_127:
* V_7 = V_68 ;
return V_4 ;
}
static void F_97 ( struct V_81 * V_82 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_2 * V_68 = V_45 -> V_3 ;
unsigned long V_64 = 1 ;
struct V_156 * V_167 ;
struct V_16 * V_17 ;
for (; ; ) {
struct V_2 * V_4 ;
if ( ! ( V_64 -- ) ) {
T_1 V_131 = V_68 -> V_9 ;
if ( F_34 ( V_68 ) )
break;
V_4 = V_68 ;
V_68 = F_32 ( V_68 ) ;
F_33 ( V_68 , V_4 -> V_9 , NULL ) ;
F_38 ( V_4 ) ;
V_64 = F_6 ( V_131 , V_68 ) ;
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
F_98 (fa, tmp, &n->leaf, fa_list) {
F_92 ( & V_17 -> V_33 ) ;
F_9 ( V_17 ) ;
}
F_33 ( V_68 , V_4 -> V_9 , NULL ) ;
F_38 ( V_4 ) ;
}
#ifdef F_50
F_99 ( V_45 -> V_63 ) ;
#endif
F_12 ( V_82 ) ;
}
struct V_81 * F_100 ( struct V_81 * V_168 )
{
struct V_44 * V_169 = (struct V_44 * ) V_168 -> V_85 ;
struct V_2 * V_29 , * V_5 = V_169 -> V_3 ;
struct V_81 * V_170 ;
struct V_16 * V_17 ;
struct V_44 * V_171 ;
T_1 V_9 = 0 ;
if ( V_168 -> V_85 == V_168 -> V_172 )
return V_168 ;
V_170 = F_101 ( V_173 , NULL ) ;
if ( ! V_170 )
return NULL ;
V_171 = (struct V_44 * ) V_170 -> V_85 ;
while ( ( V_29 = F_96 ( & V_5 , V_9 ) ) != NULL ) {
struct V_2 * V_174 = NULL , * V_175 ;
F_86 (fa, &l->leaf, fa_list) {
struct V_16 * V_86 ;
if ( V_170 -> V_73 != V_17 -> V_73 )
continue;
V_86 = F_21 ( V_19 , V_26 ) ;
if ( ! V_86 )
goto V_100;
memcpy ( V_86 , V_17 , sizeof( * V_17 ) ) ;
if ( ! V_174 )
V_174 = F_54 ( V_171 , & V_175 , V_29 -> V_9 ) ;
if ( F_62 ( V_171 , V_175 , V_174 , V_86 ,
NULL , V_29 -> V_9 ) )
goto V_100;
}
V_9 = V_29 -> V_9 + 1 ;
if ( V_9 < V_29 -> V_9 )
break;
}
return V_170 ;
V_100:
F_97 ( V_170 ) ;
return NULL ;
}
void F_102 ( struct V_81 * V_82 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_2 * V_68 = V_45 -> V_3 ;
unsigned long V_64 = 1 ;
struct V_156 * V_167 ;
struct V_16 * V_17 ;
for (; ; ) {
unsigned char V_30 = 0 ;
struct V_2 * V_4 ;
if ( ! ( V_64 -- ) ) {
T_1 V_131 = V_68 -> V_9 ;
if ( F_34 ( V_68 ) )
break;
V_68 = F_42 ( V_45 , V_68 ) ;
V_64 = F_6 ( V_131 , V_68 ) ;
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
F_98 (fa, tmp, &n->leaf, fa_list) {
struct V_87 * V_88 = V_17 -> V_75 ;
if ( V_82 -> V_73 != V_17 -> V_73 ) {
F_92 ( & V_17 -> V_33 ) ;
F_9 ( V_17 ) ;
continue;
}
V_30 = V_17 -> V_31 ;
if ( ! V_88 || ! ( V_88 -> V_124 & V_176 ) )
continue;
F_79 ( V_4 -> V_9 ,
V_12 - V_17 -> V_31 ,
V_88 , V_17 -> V_74 ,
V_17 -> V_101 , V_82 -> V_73 ) ;
}
V_4 -> V_30 = V_30 ;
if ( F_93 ( & V_4 -> V_32 ) ) {
F_33 ( V_68 , V_4 -> V_9 , NULL ) ;
F_38 ( V_4 ) ;
} else {
F_52 ( V_68 , V_4 ) ;
}
}
}
int F_103 ( struct V_81 * V_82 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_2 * V_68 = V_45 -> V_3 ;
unsigned long V_64 = 1 ;
struct V_156 * V_167 ;
struct V_16 * V_17 ;
int V_127 = 0 ;
for (; ; ) {
unsigned char V_30 = 0 ;
struct V_2 * V_4 ;
if ( ! ( V_64 -- ) ) {
T_1 V_131 = V_68 -> V_9 ;
if ( F_34 ( V_68 ) )
break;
V_68 = F_42 ( V_45 , V_68 ) ;
V_64 = F_6 ( V_131 , V_68 ) ;
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
F_98 (fa, tmp, &n->leaf, fa_list) {
struct V_87 * V_88 = V_17 -> V_75 ;
if ( ! V_88 || ! ( V_88 -> V_124 & V_140 ) ) {
V_30 = V_17 -> V_31 ;
continue;
}
F_79 ( V_4 -> V_9 ,
V_12 - V_17 -> V_31 ,
V_88 , V_17 -> V_74 ,
V_17 -> V_101 , V_82 -> V_73 ) ;
F_92 ( & V_17 -> V_33 ) ;
F_75 ( V_17 -> V_75 ) ;
F_9 ( V_17 ) ;
V_127 ++ ;
}
V_4 -> V_30 = V_30 ;
if ( F_93 ( & V_4 -> V_32 ) ) {
F_33 ( V_68 , V_4 -> V_9 , NULL ) ;
F_38 ( V_4 ) ;
} else {
F_52 ( V_68 , V_4 ) ;
}
}
F_26 ( L_7 , V_127 ) ;
return V_127 ;
}
static void F_104 ( struct V_14 * V_15 )
{
struct V_81 * V_82 = F_2 ( V_15 , struct V_81 , V_18 ) ;
#ifdef F_50
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
if ( V_82 -> V_85 == V_82 -> V_172 )
F_99 ( V_45 -> V_63 ) ;
#endif
F_12 ( V_82 ) ;
}
void F_105 ( struct V_81 * V_82 )
{
F_10 ( & V_82 -> V_18 , F_104 ) ;
}
static int F_106 ( struct V_2 * V_29 , struct V_81 * V_82 ,
struct V_177 * V_178 , struct V_179 * V_180 )
{
T_7 V_181 = F_78 ( V_29 -> V_9 ) ;
struct V_16 * V_17 ;
int V_35 , V_182 ;
V_182 = V_180 -> args [ 4 ] ;
V_35 = 0 ;
F_86 (fa, &l->leaf, fa_list) {
if ( V_35 < V_182 ) {
V_35 ++ ;
continue;
}
if ( V_82 -> V_73 != V_17 -> V_73 ) {
V_35 ++ ;
continue;
}
if ( F_107 ( V_178 , F_108 ( V_180 -> V_178 ) . V_183 ,
V_180 -> V_184 -> V_185 ,
V_111 ,
V_82 -> V_73 ,
V_17 -> V_101 ,
V_181 ,
V_12 - V_17 -> V_31 ,
V_17 -> V_74 ,
V_17 -> V_75 , V_186 ) < 0 ) {
V_180 -> args [ 4 ] = V_35 ;
return - 1 ;
}
V_35 ++ ;
}
V_180 -> args [ 4 ] = V_35 ;
return V_178 -> V_187 ;
}
int F_109 ( struct V_81 * V_82 , struct V_177 * V_178 ,
struct V_179 * V_180 )
{
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_2 * V_29 , * V_5 = V_45 -> V_3 ;
int V_188 = V_180 -> args [ 2 ] ;
T_1 V_9 = V_180 -> args [ 3 ] ;
while ( ( V_29 = F_96 ( & V_5 , V_9 ) ) != NULL ) {
if ( F_106 ( V_29 , V_82 , V_178 , V_180 ) < 0 ) {
V_180 -> args [ 3 ] = V_9 ;
V_180 -> args [ 2 ] = V_188 ;
return - 1 ;
}
++ V_188 ;
V_9 = V_29 -> V_9 + 1 ;
memset ( & V_180 -> args [ 4 ] , 0 ,
sizeof( V_180 -> args ) - 4 * sizeof( V_180 -> args [ 0 ] ) ) ;
if ( V_9 < V_29 -> V_9 )
break;
}
V_180 -> args [ 3 ] = V_9 ;
V_180 -> args [ 2 ] = V_188 ;
return V_178 -> V_187 ;
}
void T_8 F_110 ( void )
{
V_19 = F_111 ( L_8 ,
sizeof( struct V_16 ) ,
0 , V_189 , NULL ) ;
V_21 = F_111 ( L_9 ,
V_190 ,
0 , V_189 , NULL ) ;
}
struct V_81 * F_101 ( T_4 V_191 , struct V_81 * V_192 )
{
struct V_81 * V_82 ;
struct V_44 * V_45 ;
T_2 V_193 = sizeof( * V_82 ) ;
if ( ! V_192 )
V_193 += sizeof( struct V_44 ) ;
V_82 = F_16 ( V_193 , V_26 ) ;
if ( ! V_82 )
return NULL ;
V_82 -> V_73 = V_191 ;
V_82 -> V_194 = - 1 ;
V_82 -> V_118 = 0 ;
V_82 -> V_85 = ( V_192 ? V_192 -> V_172 : V_82 -> V_172 ) ;
if ( V_192 )
return V_82 ;
V_45 = (struct V_44 * ) V_82 -> V_85 ;
V_45 -> V_3 [ 0 ] . V_13 = V_12 ;
V_45 -> V_3 [ 0 ] . V_30 = V_12 ;
#ifdef F_50
V_45 -> V_63 = F_112 ( struct V_62 ) ;
if ( ! V_45 -> V_63 ) {
F_12 ( V_82 ) ;
V_82 = NULL ;
}
#endif
return V_82 ;
}
static struct V_2 * F_113 ( struct V_195 * V_196 )
{
unsigned long V_64 = V_196 -> V_10 ;
struct V_2 * V_68 = V_196 -> V_1 ;
T_1 V_131 ;
F_26 ( L_10 ,
V_196 -> V_1 , V_196 -> V_10 , V_196 -> V_197 ) ;
while ( ! F_34 ( V_68 ) ) {
while ( V_64 < F_5 ( V_68 ) ) {
struct V_2 * V_4 = F_55 ( V_68 , V_64 ++ ) ;
if ( ! V_4 )
continue;
if ( F_82 ( V_4 ) ) {
V_196 -> V_1 = V_68 ;
V_196 -> V_10 = V_64 ;
} else {
V_196 -> V_1 = V_4 ;
V_196 -> V_10 = 0 ;
++ V_196 -> V_197 ;
}
return V_4 ;
}
V_131 = V_68 -> V_9 ;
V_68 = F_85 ( V_68 ) ;
V_64 = F_6 ( V_131 , V_68 ) + 1 ;
-- V_196 -> V_197 ;
}
V_196 -> V_1 = V_68 ;
V_196 -> V_10 = 0 ;
return NULL ;
}
static struct V_2 * F_114 ( struct V_195 * V_196 ,
struct V_44 * V_45 )
{
struct V_2 * V_4 , * V_68 = V_45 -> V_3 ;
if ( ! V_45 )
return NULL ;
V_4 = F_84 ( V_68 -> V_1 [ 0 ] ) ;
if ( ! V_4 )
return NULL ;
if ( F_28 ( V_4 ) ) {
V_196 -> V_1 = V_4 ;
V_196 -> V_10 = 0 ;
V_196 -> V_197 = 1 ;
} else {
V_196 -> V_1 = V_68 ;
V_196 -> V_10 = 0 ;
V_196 -> V_197 = 0 ;
}
return V_4 ;
}
static void F_115 ( struct V_44 * V_45 , struct V_198 * V_199 )
{
struct V_2 * V_4 ;
struct V_195 V_196 ;
memset ( V_199 , 0 , sizeof( * V_199 ) ) ;
F_116 () ;
for ( V_4 = F_114 ( & V_196 , V_45 ) ; V_4 ; V_4 = F_113 ( & V_196 ) ) {
if ( F_82 ( V_4 ) ) {
struct V_16 * V_17 ;
V_199 -> V_200 ++ ;
V_199 -> V_201 += V_196 . V_197 ;
if ( V_196 . V_197 > V_199 -> V_202 )
V_199 -> V_202 = V_196 . V_197 ;
F_86 ( V_17 , & V_4 -> V_32 , V_33 )
++ V_199 -> V_203 ;
} else {
V_199 -> V_204 ++ ;
if ( V_4 -> V_8 < V_205 )
V_199 -> V_206 [ V_4 -> V_8 ] ++ ;
V_199 -> V_207 += F_1 ( V_4 ) -> V_27 ;
}
}
F_117 () ;
}
static void F_118 ( struct V_208 * V_209 , struct V_198 * V_210 )
{
unsigned int V_35 , V_211 , V_212 , V_213 , V_214 ;
if ( V_210 -> V_200 )
V_214 = V_210 -> V_201 * 100 / V_210 -> V_200 ;
else
V_214 = 0 ;
F_119 ( V_209 , L_11 ,
V_214 / 100 , V_214 % 100 ) ;
F_119 ( V_209 , L_12 , V_210 -> V_202 ) ;
F_119 ( V_209 , L_13 , V_210 -> V_200 ) ;
V_213 = V_190 * V_210 -> V_200 ;
F_119 ( V_209 , L_14 , V_210 -> V_203 ) ;
V_213 += sizeof( struct V_16 ) * V_210 -> V_203 ;
F_119 ( V_209 , L_15 , V_210 -> V_204 ) ;
V_213 += F_15 ( 0 ) * V_210 -> V_204 ;
V_211 = V_205 ;
while ( V_211 > 0 && V_210 -> V_206 [ V_211 - 1 ] == 0 )
V_211 -- ;
V_212 = 0 ;
for ( V_35 = 1 ; V_35 < V_211 ; V_35 ++ )
if ( V_210 -> V_206 [ V_35 ] != 0 ) {
F_119 ( V_209 , L_16 , V_35 , V_210 -> V_206 [ V_35 ] ) ;
V_212 += ( 1 << V_35 ) * V_210 -> V_206 [ V_35 ] ;
}
F_120 ( V_209 , '\n' ) ;
F_119 ( V_209 , L_17 , V_212 ) ;
V_213 += sizeof( struct V_2 * ) * V_212 ;
F_119 ( V_209 , L_18 , V_210 -> V_207 ) ;
F_119 ( V_209 , L_19 , ( V_213 + 1023 ) / 1024 ) ;
}
static void F_121 ( struct V_208 * V_209 ,
const struct V_62 T_3 * V_63 )
{
struct V_62 V_199 = { 0 } ;
int V_215 ;
F_122 (cpu) {
const struct V_62 * V_216 = F_123 ( V_63 , V_215 ) ;
V_199 . gets += V_216 -> gets ;
V_199 . V_132 += V_216 -> V_132 ;
V_199 . V_139 += V_216 -> V_139 ;
V_199 . V_154 += V_216 -> V_154 ;
V_199 . V_130 += V_216 -> V_130 ;
V_199 . V_67 += V_216 -> V_67 ;
}
F_119 ( V_209 , L_20 ) ;
F_119 ( V_209 , L_21 , V_199 . gets ) ;
F_119 ( V_209 , L_22 , V_199 . V_132 ) ;
F_119 ( V_209 , L_23 ,
V_199 . V_139 ) ;
F_119 ( V_209 , L_24 , V_199 . V_154 ) ;
F_119 ( V_209 , L_25 , V_199 . V_130 ) ;
F_119 ( V_209 , L_26 , V_199 . V_67 ) ;
}
static void F_124 ( struct V_208 * V_209 , struct V_81 * V_82 )
{
if ( V_82 -> V_73 == V_173 )
F_125 ( V_209 , L_27 ) ;
else if ( V_82 -> V_73 == V_217 )
F_125 ( V_209 , L_28 ) ;
else
F_119 ( V_209 , L_29 , V_82 -> V_73 ) ;
}
static int F_126 ( struct V_208 * V_209 , void * V_218 )
{
struct V_219 * V_219 = (struct V_219 * ) V_209 -> V_220 ;
unsigned int V_221 ;
F_119 ( V_209 ,
L_30
L_31 ,
V_190 , F_15 ( 0 ) ) ;
for ( V_221 = 0 ; V_221 < V_222 ; V_221 ++ ) {
struct V_69 * V_15 = & V_219 -> V_223 . V_224 [ V_221 ] ;
struct V_81 * V_82 ;
F_86 (tb, head, tb_hlist) {
struct V_44 * V_45 = (struct V_44 * ) V_82 -> V_85 ;
struct V_198 V_210 ;
if ( ! V_45 )
continue;
F_124 ( V_209 , V_82 ) ;
F_115 ( V_45 , & V_210 ) ;
F_118 ( V_209 , & V_210 ) ;
#ifdef F_50
F_121 ( V_209 , V_45 -> V_63 ) ;
#endif
}
}
return 0 ;
}
static int F_127 ( struct V_39 * V_39 , struct V_225 * V_225 )
{
return F_128 ( V_39 , V_225 , F_126 ) ;
}
static struct V_2 * F_129 ( struct V_208 * V_209 , T_9 V_13 )
{
struct V_195 * V_196 = V_209 -> V_220 ;
struct V_219 * V_219 = F_130 ( V_209 ) ;
T_9 V_226 = 0 ;
unsigned int V_221 ;
for ( V_221 = 0 ; V_221 < V_222 ; V_221 ++ ) {
struct V_69 * V_15 = & V_219 -> V_223 . V_224 [ V_221 ] ;
struct V_81 * V_82 ;
F_86 (tb, head, tb_hlist) {
struct V_2 * V_4 ;
for ( V_4 = F_114 ( V_196 ,
(struct V_44 * ) V_82 -> V_85 ) ;
V_4 ; V_4 = F_113 ( V_196 ) )
if ( V_13 == V_226 ++ ) {
V_196 -> V_82 = V_82 ;
return V_4 ;
}
}
}
return NULL ;
}
static void * F_131 ( struct V_208 * V_209 , T_9 * V_13 )
__acquires( T_10 )
{
F_116 () ;
return F_129 ( V_209 , * V_13 ) ;
}
static void * F_132 ( struct V_208 * V_209 , void * V_218 , T_9 * V_13 )
{
struct V_195 * V_196 = V_209 -> V_220 ;
struct V_219 * V_219 = F_130 ( V_209 ) ;
struct V_81 * V_82 = V_196 -> V_82 ;
struct V_156 * V_227 ;
unsigned int V_221 ;
struct V_2 * V_4 ;
++ * V_13 ;
V_4 = F_113 ( V_196 ) ;
if ( V_4 )
return V_4 ;
V_221 = V_82 -> V_73 & ( V_222 - 1 ) ;
while ( ( V_227 = F_84 ( F_133 ( & V_82 -> V_228 ) ) ) ) {
V_82 = F_90 ( V_227 , struct V_81 , V_228 ) ;
V_4 = F_114 ( V_196 , (struct V_44 * ) V_82 -> V_85 ) ;
if ( V_4 )
goto V_127;
}
while ( ++ V_221 < V_222 ) {
struct V_69 * V_15 = & V_219 -> V_223 . V_224 [ V_221 ] ;
F_86 (tb, head, tb_hlist) {
V_4 = F_114 ( V_196 , (struct V_44 * ) V_82 -> V_85 ) ;
if ( V_4 )
goto V_127;
}
}
return NULL ;
V_127:
V_196 -> V_82 = V_82 ;
return V_4 ;
}
static void F_134 ( struct V_208 * V_209 , void * V_218 )
__releases( T_10 )
{
F_117 () ;
}
static void F_135 ( struct V_208 * V_209 , int V_4 )
{
while ( V_4 -- > 0 )
F_125 ( V_209 , L_32 ) ;
}
static inline const char * F_136 ( char * V_229 , T_2 V_187 , enum V_230 V_199 )
{
switch ( V_199 ) {
case V_231 : return L_33 ;
case V_232 : return L_34 ;
case V_233 : return L_35 ;
case V_234 : return L_36 ;
case V_161 : return L_37 ;
default:
snprintf ( V_229 , V_187 , L_38 , V_199 ) ;
return V_229 ;
}
}
static inline const char * F_137 ( char * V_229 , T_2 V_187 , unsigned int V_45 )
{
if ( V_45 < V_235 && V_236 [ V_45 ] )
return V_236 [ V_45 ] ;
snprintf ( V_229 , V_187 , L_39 , V_45 ) ;
return V_229 ;
}
static int F_138 ( struct V_208 * V_209 , void * V_218 )
{
const struct V_195 * V_196 = V_209 -> V_220 ;
struct V_2 * V_4 = V_218 ;
if ( F_34 ( F_85 ( V_4 ) ) )
F_124 ( V_209 , V_196 -> V_82 ) ;
if ( F_28 ( V_4 ) ) {
T_7 V_237 = F_78 ( V_4 -> V_9 ) ;
F_135 ( V_209 , V_196 -> V_197 - 1 ) ;
F_119 ( V_209 , L_40 ,
& V_237 , V_12 - V_4 -> V_13 - V_4 -> V_8 , V_4 -> V_8 ,
F_1 ( V_4 ) -> V_28 ,
F_1 ( V_4 ) -> V_27 ) ;
} else {
T_7 V_238 = F_78 ( V_4 -> V_9 ) ;
struct V_16 * V_17 ;
F_135 ( V_209 , V_196 -> V_197 ) ;
F_119 ( V_209 , L_41 , & V_238 ) ;
F_86 (fa, &n->leaf, fa_list) {
char V_239 [ 32 ] , V_240 [ 32 ] ;
F_135 ( V_209 , V_196 -> V_197 + 1 ) ;
F_119 ( V_209 , L_42 ,
V_12 - V_17 -> V_31 ,
F_136 ( V_239 , sizeof( V_239 ) ,
V_17 -> V_75 -> V_136 ) ,
F_137 ( V_240 , sizeof( V_240 ) ,
V_17 -> V_101 ) ) ;
if ( V_17 -> V_74 )
F_119 ( V_209 , L_43 , V_17 -> V_74 ) ;
F_120 ( V_209 , '\n' ) ;
}
}
return 0 ;
}
static int F_139 ( struct V_39 * V_39 , struct V_225 * V_225 )
{
return F_140 ( V_39 , V_225 , & V_241 ,
sizeof( struct V_195 ) ) ;
}
static struct V_2 * F_141 ( struct V_242 * V_196 ,
T_9 V_13 )
{
struct V_81 * V_82 = V_196 -> V_243 ;
struct V_2 * V_29 , * * V_5 = & V_196 -> V_1 ;
struct V_44 * V_45 ;
T_1 V_9 ;
if ( V_196 -> V_13 > 0 && V_13 >= V_196 -> V_13 ) {
V_13 -= V_196 -> V_13 ;
V_9 = V_196 -> V_9 ;
} else {
V_45 = (struct V_44 * ) V_82 -> V_85 ;
V_196 -> V_1 = V_45 -> V_3 ;
V_196 -> V_13 = 0 ;
V_9 = 0 ;
}
while ( ( V_29 = F_96 ( V_5 , V_9 ) ) != NULL ) {
V_9 = V_29 -> V_9 + 1 ;
V_196 -> V_13 ++ ;
if ( V_13 -- <= 0 )
break;
V_29 = NULL ;
if ( ! V_9 )
break;
}
if ( V_29 )
V_196 -> V_9 = V_9 ;
else
V_196 -> V_13 = 0 ;
return V_29 ;
}
static void * F_142 ( struct V_208 * V_209 , T_9 * V_13 )
__acquires( T_10 )
{
struct V_242 * V_196 = V_209 -> V_220 ;
struct V_81 * V_82 ;
struct V_44 * V_45 ;
F_116 () ;
V_82 = F_143 ( F_130 ( V_209 ) , V_217 ) ;
if ( ! V_82 )
return NULL ;
V_196 -> V_243 = V_82 ;
if ( * V_13 != 0 )
return F_141 ( V_196 , * V_13 ) ;
V_45 = (struct V_44 * ) V_82 -> V_85 ;
V_196 -> V_1 = V_45 -> V_3 ;
V_196 -> V_13 = 0 ;
V_196 -> V_9 = 0 ;
return V_244 ;
}
static void * F_144 ( struct V_208 * V_209 , void * V_218 , T_9 * V_13 )
{
struct V_242 * V_196 = V_209 -> V_220 ;
struct V_2 * V_29 = NULL ;
T_1 V_9 = V_196 -> V_9 ;
++ * V_13 ;
if ( ( V_218 == V_244 ) || V_9 )
V_29 = F_96 ( & V_196 -> V_1 , V_9 ) ;
if ( V_29 ) {
V_196 -> V_9 = V_29 -> V_9 + 1 ;
V_196 -> V_13 ++ ;
} else {
V_196 -> V_13 = 0 ;
}
return V_29 ;
}
static void F_145 ( struct V_208 * V_209 , void * V_218 )
__releases( T_10 )
{
F_117 () ;
}
static unsigned int F_146 ( int type , T_7 V_245 , const struct V_87 * V_88 )
{
unsigned int V_246 = 0 ;
if ( type == V_247 || type == V_248 )
V_246 = V_249 ;
if ( V_88 && V_88 -> V_142 -> V_250 )
V_246 |= V_251 ;
if ( V_245 == F_78 ( 0xFFFFFFFF ) )
V_246 |= V_252 ;
V_246 |= V_253 ;
return V_246 ;
}
static int F_147 ( struct V_208 * V_209 , void * V_218 )
{
struct V_242 * V_196 = V_209 -> V_220 ;
struct V_81 * V_82 = V_196 -> V_243 ;
struct V_16 * V_17 ;
struct V_2 * V_29 = V_218 ;
T_7 V_119 ;
if ( V_218 == V_244 ) {
F_119 ( V_209 , L_44 , L_45
L_46
L_47 ) ;
return 0 ;
}
V_119 = F_78 ( V_29 -> V_9 ) ;
F_86 (fa, &l->leaf, fa_list) {
const struct V_87 * V_88 = V_17 -> V_75 ;
T_7 V_245 = F_148 ( V_12 - V_17 -> V_31 ) ;
unsigned int V_246 = F_146 ( V_17 -> V_101 , V_245 , V_88 ) ;
if ( ( V_17 -> V_101 == V_254 ) ||
( V_17 -> V_101 == V_255 ) )
continue;
if ( V_17 -> V_73 != V_82 -> V_73 )
continue;
F_149 ( V_209 , 127 ) ;
if ( V_88 )
F_119 ( V_209 ,
L_48
L_49 ,
V_88 -> V_256 ? V_88 -> V_256 -> V_257 : L_50 ,
V_119 ,
V_88 -> V_142 -> V_250 , V_246 , 0 , 0 ,
V_88 -> V_76 ,
V_245 ,
( V_88 -> V_258 ?
V_88 -> V_258 + 40 : 0 ) ,
V_88 -> V_259 ,
V_88 -> V_260 >> 3 ) ;
else
F_119 ( V_209 ,
L_51
L_49 ,
V_119 , 0 , V_246 , 0 , 0 , 0 ,
V_245 , 0 , 0 , 0 ) ;
F_150 ( V_209 , '\n' ) ;
}
return 0 ;
}
static int F_151 ( struct V_39 * V_39 , struct V_225 * V_225 )
{
return F_140 ( V_39 , V_225 , & V_261 ,
sizeof( struct V_242 ) ) ;
}
int T_11 F_152 ( struct V_219 * V_219 )
{
if ( ! F_153 ( L_52 , V_262 , V_219 -> V_263 , & V_264 ) )
goto V_265;
if ( ! F_153 ( L_53 , V_262 , V_219 -> V_263 ,
& V_266 ) )
goto V_267;
if ( ! F_153 ( L_54 , V_262 , V_219 -> V_263 , & V_268 ) )
goto V_269;
return 0 ;
V_269:
F_154 ( L_53 , V_219 -> V_263 ) ;
V_267:
F_154 ( L_52 , V_219 -> V_263 ) ;
V_265:
return - V_79 ;
}
void T_12 F_155 ( struct V_219 * V_219 )
{
F_154 ( L_52 , V_219 -> V_263 ) ;
F_154 ( L_53 , V_219 -> V_263 ) ;
F_154 ( L_54 , V_219 -> V_263 ) ;
}
