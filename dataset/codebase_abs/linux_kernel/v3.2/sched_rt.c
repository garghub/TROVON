static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
#ifdef F_2
F_3 ( ! F_4 ( V_3 ) ) ;
#endif
return F_5 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_6 ( struct V_6 * V_6 )
{
return V_6 -> V_5 ;
}
static inline struct V_6 * F_7 ( struct V_2 * V_3 )
{
return V_3 -> V_6 ;
}
static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_5 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_6 ( struct V_6 * V_6 )
{
return F_5 ( V_6 , struct V_5 , V_4 ) ;
}
static inline struct V_6 * F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_5 * V_5 = F_8 ( V_7 ) ;
return & V_5 -> V_4 ;
}
static inline int F_9 ( struct V_5 * V_5 )
{
return F_10 ( & V_5 -> V_8 -> V_9 ) ;
}
static inline void F_11 ( struct V_5 * V_5 )
{
if ( ! V_5 -> V_10 )
return;
F_12 ( V_5 -> V_11 , V_5 -> V_8 -> V_12 ) ;
F_13 () ;
F_14 ( & V_5 -> V_8 -> V_9 ) ;
}
static inline void F_15 ( struct V_5 * V_5 )
{
if ( ! V_5 -> V_10 )
return;
F_16 ( & V_5 -> V_8 -> V_9 ) ;
F_17 ( V_5 -> V_11 , V_5 -> V_8 -> V_12 ) ;
}
static void F_18 ( struct V_6 * V_6 )
{
if ( V_6 -> V_13 && V_6 -> V_14 > 1 ) {
if ( ! V_6 -> V_15 ) {
F_11 ( F_6 ( V_6 ) ) ;
V_6 -> V_15 = 1 ;
}
} else if ( V_6 -> V_15 ) {
F_15 ( F_6 ( V_6 ) ) ;
V_6 -> V_15 = 0 ;
}
}
static void F_19 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
if ( ! F_4 ( V_3 ) )
return;
V_6 = & F_6 ( V_6 ) -> V_4 ;
V_6 -> V_14 ++ ;
if ( V_3 -> V_16 > 1 )
V_6 -> V_13 ++ ;
F_18 ( V_6 ) ;
}
static void F_20 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
if ( ! F_4 ( V_3 ) )
return;
V_6 = & F_6 ( V_6 ) -> V_4 ;
V_6 -> V_14 -- ;
if ( V_3 -> V_16 > 1 )
V_6 -> V_13 -- ;
F_18 ( V_6 ) ;
}
static inline int F_21 ( struct V_5 * V_5 )
{
return ! F_22 ( & V_5 -> V_4 . V_17 ) ;
}
static void F_23 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_24 ( & V_7 -> V_17 , & V_5 -> V_4 . V_17 ) ;
F_25 ( & V_7 -> V_17 , V_7 -> V_18 ) ;
F_26 ( & V_7 -> V_17 , & V_5 -> V_4 . V_17 ) ;
if ( V_7 -> V_18 < V_5 -> V_4 . V_19 . V_20 )
V_5 -> V_4 . V_19 . V_20 = V_7 -> V_18 ;
}
static void F_27 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_24 ( & V_7 -> V_17 , & V_5 -> V_4 . V_17 ) ;
if ( F_21 ( V_5 ) ) {
V_7 = F_28 ( & V_5 -> V_4 . V_17 ,
struct V_1 , V_17 ) ;
V_5 -> V_4 . V_19 . V_20 = V_7 -> V_18 ;
} else
V_5 -> V_4 . V_19 . V_20 = V_21 ;
}
static inline void F_23 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static inline void F_27 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static inline
void F_19 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
}
static inline
void F_20 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
}
static inline int F_29 ( struct V_2 * V_3 )
{
return ! F_30 ( & V_3 -> V_22 ) ;
}
static inline T_1 F_31 ( struct V_6 * V_6 )
{
if ( ! V_6 -> V_23 )
return V_24 ;
return V_6 -> V_25 ;
}
static inline T_1 F_32 ( struct V_6 * V_6 )
{
return F_33 ( V_6 -> V_23 -> V_26 . V_27 ) ;
}
static inline struct V_28 * F_34 ( struct V_28 * V_23 )
{
do {
V_23 = F_35 ( V_23 -> V_29 . V_20 ,
F_36 ( struct V_28 ) , V_29 ) ;
} while ( & V_23 -> V_29 != & V_30 && F_37 ( V_23 ) );
if ( & V_23 -> V_29 == & V_30 )
V_23 = NULL ;
return V_23 ;
}
static inline void F_38 ( struct V_6 * V_6 )
{
F_39 ( & V_6 -> V_31 ,
& F_6 ( V_6 ) -> V_31 ) ;
}
static inline void F_40 ( struct V_6 * V_6 )
{
F_41 ( & V_6 -> V_31 ) ;
}
static inline struct V_6 * F_42 ( struct V_2 * V_3 )
{
return V_3 -> V_32 ;
}
static void F_43 ( struct V_6 * V_6 )
{
struct V_1 * V_33 = F_6 ( V_6 ) -> V_33 ;
struct V_2 * V_3 ;
int V_11 = F_44 ( F_6 ( V_6 ) ) ;
V_3 = V_6 -> V_23 -> V_3 [ V_11 ] ;
if ( V_6 -> V_34 ) {
if ( V_3 && ! F_29 ( V_3 ) )
F_45 ( V_3 , false ) ;
if ( V_6 -> V_19 . V_33 < V_33 -> V_18 )
F_46 ( V_33 ) ;
}
}
static void F_47 ( struct V_6 * V_6 )
{
struct V_2 * V_3 ;
int V_11 = F_44 ( F_6 ( V_6 ) ) ;
V_3 = V_6 -> V_23 -> V_3 [ V_11 ] ;
if ( V_3 && F_29 ( V_3 ) )
F_48 ( V_3 ) ;
}
static inline int F_49 ( struct V_6 * V_6 )
{
return V_6 -> V_35 && ! V_6 -> V_36 ;
}
static int F_50 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_42 ( V_3 ) ;
struct V_1 * V_7 ;
if ( V_6 )
return ! ! V_6 -> V_36 ;
V_7 = F_1 ( V_3 ) ;
return V_7 -> V_18 != V_7 -> V_37 ;
}
static inline const struct V_38 * F_51 ( void )
{
return F_52 ( F_53 () ) -> V_8 -> V_39 ;
}
static inline const struct V_38 * F_51 ( void )
{
return V_40 ;
}
static inline
struct V_6 * F_54 ( struct V_26 * V_41 , int V_11 )
{
return F_5 ( V_41 , struct V_28 , V_26 ) -> V_6 [ V_11 ] ;
}
static inline struct V_26 * F_55 ( struct V_6 * V_6 )
{
return & V_6 -> V_23 -> V_26 ;
}
static inline T_1 F_31 ( struct V_6 * V_6 )
{
return V_6 -> V_25 ;
}
static inline T_1 F_32 ( struct V_6 * V_6 )
{
return F_33 ( V_42 . V_27 ) ;
}
static inline void F_38 ( struct V_6 * V_6 )
{
}
static inline void F_40 ( struct V_6 * V_6 )
{
}
static inline struct V_6 * F_42 ( struct V_2 * V_3 )
{
return NULL ;
}
static inline void F_43 ( struct V_6 * V_6 )
{
if ( V_6 -> V_34 )
F_46 ( F_6 ( V_6 ) -> V_33 ) ;
}
static inline void F_47 ( struct V_6 * V_6 )
{
}
static inline int F_49 ( struct V_6 * V_6 )
{
return V_6 -> V_35 ;
}
static inline const struct V_38 * F_51 ( void )
{
return V_40 ;
}
static inline
struct V_6 * F_54 ( struct V_26 * V_41 , int V_11 )
{
return & F_52 ( V_11 ) -> V_4 ;
}
static inline struct V_26 * F_55 ( struct V_6 * V_6 )
{
return & V_42 ;
}
static int F_56 ( struct V_6 * V_6 )
{
struct V_26 * V_41 = F_55 ( V_6 ) ;
struct V_43 * V_8 = F_52 ( F_53 () ) -> V_8 ;
int V_44 , V_45 , V_46 = 0 ;
T_1 V_27 ;
V_45 = F_57 ( V_8 -> V_39 ) ;
F_58 ( & V_41 -> V_47 ) ;
V_27 = F_33 ( V_41 -> V_27 ) ;
F_59 (i, rd->span) {
struct V_6 * V_48 = F_54 ( V_41 , V_44 ) ;
T_2 V_49 ;
if ( V_48 == V_6 )
continue;
F_58 ( & V_48 -> V_47 ) ;
if ( V_48 -> V_25 == V_24 )
goto V_20;
V_49 = V_48 -> V_25 - V_48 -> V_50 ;
if ( V_49 > 0 ) {
V_49 = F_60 ( ( T_1 ) V_49 , V_45 ) ;
if ( V_6 -> V_25 + V_49 > V_27 )
V_49 = V_27 - V_6 -> V_25 ;
V_48 -> V_25 -= V_49 ;
V_6 -> V_25 += V_49 ;
V_46 = 1 ;
if ( V_6 -> V_25 == V_27 ) {
F_61 ( & V_48 -> V_47 ) ;
break;
}
}
V_20:
F_61 ( & V_48 -> V_47 ) ;
}
F_61 ( & V_41 -> V_47 ) ;
return V_46 ;
}
static void F_62 ( struct V_5 * V_5 )
{
struct V_43 * V_8 = V_5 -> V_8 ;
T_3 V_48 ;
struct V_6 * V_6 ;
if ( F_63 ( ! V_51 ) )
return;
F_64 (rt_rq, iter, rq) {
struct V_26 * V_41 = F_55 ( V_6 ) ;
T_2 V_52 ;
int V_44 ;
F_58 ( & V_41 -> V_47 ) ;
F_58 ( & V_6 -> V_47 ) ;
if ( V_6 -> V_25 == V_24 ||
V_6 -> V_25 == V_41 -> V_25 )
goto V_53;
F_61 ( & V_6 -> V_47 ) ;
V_52 = V_41 -> V_25 - V_6 -> V_25 ;
F_59 (i, rd->span) {
struct V_6 * V_48 = F_54 ( V_41 , V_44 ) ;
T_2 V_49 ;
if ( V_48 == V_6 || V_48 -> V_25 == V_24 )
continue;
F_58 ( & V_48 -> V_47 ) ;
if ( V_52 > 0 ) {
V_49 = F_65 ( T_2 , V_48 -> V_25 , V_52 ) ;
V_48 -> V_25 -= V_49 ;
V_52 -= V_49 ;
} else {
V_48 -> V_25 -= V_52 ;
V_52 -= V_52 ;
}
F_61 ( & V_48 -> V_47 ) ;
if ( ! V_52 )
break;
}
F_58 ( & V_6 -> V_47 ) ;
F_66 ( V_52 ) ;
V_53:
V_6 -> V_25 = V_24 ;
F_61 ( & V_6 -> V_47 ) ;
F_61 ( & V_41 -> V_47 ) ;
}
}
static void F_67 ( struct V_5 * V_5 )
{
unsigned long V_54 ;
F_68 ( & V_5 -> V_55 , V_54 ) ;
F_62 ( V_5 ) ;
F_69 ( & V_5 -> V_55 , V_54 ) ;
}
static void F_70 ( struct V_5 * V_5 )
{
T_3 V_48 ;
struct V_6 * V_6 ;
if ( F_63 ( ! V_51 ) )
return;
F_64 (rt_rq, iter, rq) {
struct V_26 * V_41 = F_55 ( V_6 ) ;
F_58 ( & V_41 -> V_47 ) ;
F_58 ( & V_6 -> V_47 ) ;
V_6 -> V_25 = V_41 -> V_25 ;
V_6 -> V_50 = 0 ;
V_6 -> V_35 = 0 ;
F_61 ( & V_6 -> V_47 ) ;
F_61 ( & V_41 -> V_47 ) ;
}
}
static void F_71 ( struct V_5 * V_5 )
{
unsigned long V_54 ;
F_68 ( & V_5 -> V_55 , V_54 ) ;
F_70 ( V_5 ) ;
F_69 ( & V_5 -> V_55 , V_54 ) ;
}
static int F_72 ( struct V_6 * V_6 )
{
int V_46 = 0 ;
if ( ! F_73 ( V_56 ) )
return V_46 ;
if ( V_6 -> V_50 > V_6 -> V_25 ) {
F_61 ( & V_6 -> V_47 ) ;
V_46 = F_56 ( V_6 ) ;
F_58 ( & V_6 -> V_47 ) ;
}
return V_46 ;
}
static inline int F_72 ( struct V_6 * V_6 )
{
return 0 ;
}
static int F_74 ( struct V_26 * V_41 , int V_57 )
{
int V_44 , V_58 = 1 ;
const struct V_38 * V_39 ;
if ( ! F_75 () || V_41 -> V_25 == V_24 )
return 1 ;
V_39 = F_51 () ;
F_59 (i, span) {
int V_59 = 0 ;
struct V_6 * V_6 = F_54 ( V_41 , V_44 ) ;
struct V_5 * V_5 = F_6 ( V_6 ) ;
F_58 ( & V_5 -> V_55 ) ;
if ( V_6 -> V_50 ) {
T_1 V_60 ;
F_58 ( & V_6 -> V_47 ) ;
if ( V_6 -> V_35 )
F_72 ( V_6 ) ;
V_60 = V_6 -> V_25 ;
V_6 -> V_50 -= F_76 ( V_6 -> V_50 , V_57 * V_60 ) ;
if ( V_6 -> V_35 && V_6 -> V_50 < V_60 ) {
V_6 -> V_35 = 0 ;
V_59 = 1 ;
if ( V_6 -> V_34 && V_5 -> V_33 == V_5 -> V_58 )
V_5 -> V_61 = - 1 ;
}
if ( V_6 -> V_50 || V_6 -> V_34 )
V_58 = 0 ;
F_61 ( & V_6 -> V_47 ) ;
} else if ( V_6 -> V_34 ) {
V_58 = 0 ;
if ( ! F_49 ( V_6 ) )
V_59 = 1 ;
}
if ( V_59 )
F_43 ( V_6 ) ;
F_61 ( & V_5 -> V_55 ) ;
}
return V_58 ;
}
static inline int F_77 ( struct V_2 * V_3 )
{
#ifdef F_78
struct V_6 * V_6 = F_42 ( V_3 ) ;
if ( V_6 )
return V_6 -> V_19 . V_33 ;
#endif
return F_1 ( V_3 ) -> V_18 ;
}
static int F_79 ( struct V_6 * V_6 )
{
T_1 V_60 = F_31 ( V_6 ) ;
if ( V_6 -> V_35 )
return F_49 ( V_6 ) ;
if ( F_31 ( V_6 ) >= F_32 ( V_6 ) )
return 0 ;
F_72 ( V_6 ) ;
V_60 = F_31 ( V_6 ) ;
if ( V_60 == V_24 )
return 0 ;
if ( V_6 -> V_50 > V_60 ) {
V_6 -> V_35 = 1 ;
F_80 ( V_62 L_1 ) ;
if ( F_49 ( V_6 ) ) {
F_47 ( V_6 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_81 ( struct V_5 * V_5 )
{
struct V_1 * V_33 = V_5 -> V_33 ;
struct V_2 * V_3 = & V_33 -> V_4 ;
struct V_6 * V_6 = F_7 ( V_3 ) ;
T_1 V_63 ;
if ( V_33 -> V_64 != & V_65 )
return;
V_63 = V_5 -> V_66 - V_33 -> V_67 . V_68 ;
if ( F_63 ( ( T_2 ) V_63 < 0 ) )
V_63 = 0 ;
F_82 ( V_33 -> V_67 . V_69 . V_70 , F_83 ( V_33 -> V_67 . V_69 . V_70 , V_63 ) ) ;
V_33 -> V_67 . V_71 += V_63 ;
F_84 ( V_33 , V_63 ) ;
V_33 -> V_67 . V_68 = V_5 -> V_66 ;
F_85 ( V_33 , V_63 ) ;
F_86 ( V_5 , V_63 ) ;
if ( ! F_75 () )
return;
F_87 (rt_se) {
V_6 = F_7 ( V_3 ) ;
if ( F_31 ( V_6 ) != V_24 ) {
F_58 ( & V_6 -> V_47 ) ;
V_6 -> V_50 += V_63 ;
if ( F_79 ( V_6 ) )
F_46 ( V_33 ) ;
F_61 ( & V_6 -> V_47 ) ;
}
}
}
static void
F_88 ( struct V_6 * V_6 , int V_18 , int V_72 )
{
struct V_5 * V_5 = F_6 ( V_6 ) ;
if ( V_5 -> V_10 && V_18 < V_72 )
F_89 ( & V_5 -> V_8 -> V_73 , V_5 -> V_11 , V_18 ) ;
}
static void
F_90 ( struct V_6 * V_6 , int V_18 , int V_72 )
{
struct V_5 * V_5 = F_6 ( V_6 ) ;
if ( V_5 -> V_10 && V_6 -> V_19 . V_33 != V_72 )
F_89 ( & V_5 -> V_8 -> V_73 , V_5 -> V_11 , V_6 -> V_19 . V_33 ) ;
}
static inline
void F_88 ( struct V_6 * V_6 , int V_18 , int V_72 ) {}
static inline
void F_90 ( struct V_6 * V_6 , int V_18 , int V_72 ) {}
static void
F_91 ( struct V_6 * V_6 , int V_18 )
{
int V_72 = V_6 -> V_19 . V_33 ;
if ( V_18 < V_72 )
V_6 -> V_19 . V_33 = V_18 ;
F_88 ( V_6 , V_18 , V_72 ) ;
}
static void
F_92 ( struct V_6 * V_6 , int V_18 )
{
int V_72 = V_6 -> V_19 . V_33 ;
if ( V_6 -> V_34 ) {
F_93 ( V_18 < V_72 ) ;
if ( V_18 == V_72 ) {
struct V_74 * V_75 = & V_6 -> V_76 ;
V_6 -> V_19 . V_33 =
F_94 ( V_75 -> V_77 ) ;
}
} else
V_6 -> V_19 . V_33 = V_21 ;
F_90 ( V_6 , V_18 , V_72 ) ;
}
static inline void F_91 ( struct V_6 * V_6 , int V_18 ) {}
static inline void F_92 ( struct V_6 * V_6 , int V_18 ) {}
static void
F_95 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
if ( F_50 ( V_3 ) )
V_6 -> V_36 ++ ;
if ( V_6 -> V_23 )
F_96 ( & V_6 -> V_23 -> V_26 ) ;
}
static void
F_97 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
if ( F_50 ( V_3 ) )
V_6 -> V_36 -- ;
F_93 ( ! V_6 -> V_34 && V_6 -> V_36 ) ;
}
static void
F_95 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
F_96 ( & V_42 ) ;
}
static inline
void F_97 ( struct V_2 * V_3 , struct V_6 * V_6 ) {}
static inline
void F_98 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_18 = F_77 ( V_3 ) ;
F_93 ( ! F_99 ( V_18 ) ) ;
V_6 -> V_34 ++ ;
F_91 ( V_6 , V_18 ) ;
F_19 ( V_3 , V_6 ) ;
F_95 ( V_3 , V_6 ) ;
}
static inline
void F_100 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
F_93 ( ! F_99 ( F_77 ( V_3 ) ) ) ;
F_93 ( ! V_6 -> V_34 ) ;
V_6 -> V_34 -- ;
F_92 ( V_6 , F_77 ( V_3 ) ) ;
F_20 ( V_3 , V_6 ) ;
F_97 ( V_3 , V_6 ) ;
}
static void F_101 ( struct V_2 * V_3 , bool V_78 )
{
struct V_6 * V_6 = F_7 ( V_3 ) ;
struct V_74 * V_75 = & V_6 -> V_76 ;
struct V_6 * V_79 = F_42 ( V_3 ) ;
struct V_80 * V_81 = V_75 -> V_81 + F_77 ( V_3 ) ;
if ( V_79 && ( F_49 ( V_79 ) || ! V_79 -> V_34 ) )
return;
if ( ! V_6 -> V_34 )
F_38 ( V_6 ) ;
if ( V_78 )
F_102 ( & V_3 -> V_22 , V_81 ) ;
else
F_103 ( & V_3 -> V_22 , V_81 ) ;
F_104 ( F_77 ( V_3 ) , V_75 -> V_77 ) ;
F_98 ( V_3 , V_6 ) ;
}
static void F_105 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_7 ( V_3 ) ;
struct V_74 * V_75 = & V_6 -> V_76 ;
F_106 ( & V_3 -> V_22 ) ;
if ( F_30 ( V_75 -> V_81 + F_77 ( V_3 ) ) )
F_107 ( F_77 ( V_3 ) , V_75 -> V_77 ) ;
F_100 ( V_3 , V_6 ) ;
if ( ! V_6 -> V_34 )
F_40 ( V_6 ) ;
}
static void F_108 ( struct V_2 * V_3 )
{
struct V_2 * V_82 = NULL ;
F_87 (rt_se) {
V_3 -> V_82 = V_82 ;
V_82 = V_3 ;
}
for ( V_3 = V_82 ; V_3 ; V_3 = V_3 -> V_82 ) {
if ( F_29 ( V_3 ) )
F_105 ( V_3 ) ;
}
}
static void F_45 ( struct V_2 * V_3 , bool V_78 )
{
F_108 ( V_3 ) ;
F_87 (rt_se)
F_101 ( V_3 , V_78 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
F_108 ( V_3 ) ;
F_87 (rt_se) {
struct V_6 * V_6 = F_42 ( V_3 ) ;
if ( V_6 && V_6 -> V_34 )
F_101 ( V_3 , false ) ;
}
}
static void
F_109 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_54 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
if ( V_54 & V_83 )
V_3 -> V_84 = 0 ;
F_45 ( V_3 , V_54 & V_85 ) ;
if ( ! F_110 ( V_5 , V_7 ) && V_7 -> V_4 . V_16 > 1 )
F_23 ( V_5 , V_7 ) ;
F_111 ( V_5 ) ;
}
static void F_112 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_54 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
F_81 ( V_5 ) ;
F_48 ( V_3 ) ;
F_27 ( V_5 , V_7 ) ;
F_113 ( V_5 ) ;
}
static void
F_114 ( struct V_6 * V_6 , struct V_2 * V_3 , int V_78 )
{
if ( F_29 ( V_3 ) ) {
struct V_74 * V_75 = & V_6 -> V_76 ;
struct V_80 * V_81 = V_75 -> V_81 + F_77 ( V_3 ) ;
if ( V_78 )
F_115 ( & V_3 -> V_22 , V_81 ) ;
else
F_116 ( & V_3 -> V_22 , V_81 ) ;
}
}
static void F_117 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_78 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
struct V_6 * V_6 ;
F_87 (rt_se) {
V_6 = F_7 ( V_3 ) ;
F_114 ( V_6 , V_3 , V_78 ) ;
}
}
static void F_118 ( struct V_5 * V_5 )
{
F_117 ( V_5 , V_5 -> V_33 , 0 ) ;
}
static int
F_119 ( struct V_1 * V_7 , int V_86 , int V_54 )
{
struct V_1 * V_33 ;
struct V_5 * V_5 ;
int V_11 ;
V_11 = F_120 ( V_7 ) ;
if ( V_86 != V_87 && V_86 != V_88 )
goto V_89;
V_5 = F_52 ( V_11 ) ;
F_121 () ;
V_33 = F_122 ( V_5 -> V_33 ) ;
if ( V_33 && F_63 ( F_123 ( V_33 ) ) &&
( V_33 -> V_4 . V_16 < 2 ||
V_33 -> V_18 <= V_7 -> V_18 ) &&
( V_7 -> V_4 . V_16 > 1 ) ) {
int V_90 = F_124 ( V_7 ) ;
if ( V_90 != - 1 )
V_11 = V_90 ;
}
F_125 () ;
V_89:
return V_11 ;
}
static void F_126 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_5 -> V_33 -> V_4 . V_16 == 1 )
return;
if ( V_7 -> V_4 . V_16 != 1
&& F_127 ( & V_5 -> V_8 -> V_73 , V_7 , NULL ) )
return;
if ( ! F_127 ( & V_5 -> V_8 -> V_73 , V_5 -> V_33 , NULL ) )
return;
F_117 ( V_5 , V_7 , 1 ) ;
F_46 ( V_5 -> V_33 ) ;
}
static void F_128 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_54 )
{
if ( V_7 -> V_18 < V_5 -> V_33 -> V_18 ) {
F_46 ( V_5 -> V_33 ) ;
return;
}
#ifdef F_129
if ( V_7 -> V_18 == V_5 -> V_33 -> V_18 && ! F_130 ( V_5 -> V_33 ) )
F_126 ( V_5 , V_7 ) ;
#endif
}
static struct V_2 * F_131 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_74 * V_75 = & V_6 -> V_76 ;
struct V_2 * V_20 = NULL ;
struct V_80 * V_81 ;
int V_91 ;
V_91 = F_94 ( V_75 -> V_77 ) ;
F_66 ( V_91 >= V_21 ) ;
V_81 = V_75 -> V_81 + V_91 ;
V_20 = F_132 ( V_81 -> V_20 , struct V_2 , V_22 ) ;
return V_20 ;
}
static struct V_1 * F_133 ( struct V_5 * V_5 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_6 * V_6 ;
V_6 = & V_5 -> V_4 ;
if ( ! V_6 -> V_34 )
return NULL ;
if ( F_49 ( V_6 ) )
return NULL ;
do {
V_3 = F_131 ( V_5 , V_6 ) ;
F_66 ( ! V_3 ) ;
V_6 = F_42 ( V_3 ) ;
} while ( V_6 );
V_7 = F_1 ( V_3 ) ;
V_7 -> V_67 . V_68 = V_5 -> V_66 ;
return V_7 ;
}
static struct V_1 * F_134 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = F_133 ( V_5 ) ;
if ( V_7 )
F_27 ( V_5 , V_7 ) ;
#ifdef F_129
V_5 -> V_92 = F_21 ( V_5 ) ;
#endif
return V_7 ;
}
static void F_135 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_81 ( V_5 ) ;
if ( F_29 ( & V_7 -> V_4 ) && V_7 -> V_4 . V_16 > 1 )
F_23 ( V_5 , V_7 ) ;
}
static int F_136 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_11 )
{
if ( ! F_137 ( V_5 , V_7 ) &&
( V_11 < 0 || F_138 ( V_11 , F_139 ( V_7 ) ) ) &&
( V_7 -> V_4 . V_16 > 1 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_140 ( struct V_5 * V_5 , int V_11 )
{
struct V_1 * V_20 = NULL ;
struct V_2 * V_3 ;
struct V_74 * V_75 ;
struct V_6 * V_6 ;
int V_91 ;
F_141 (rt_rq, rq) {
V_75 = & V_6 -> V_76 ;
V_91 = F_94 ( V_75 -> V_77 ) ;
V_93:
if ( V_91 >= V_21 )
continue;
if ( V_20 && V_20 -> V_18 < V_91 )
continue;
F_142 (rt_se, array->queue + idx, run_list) {
struct V_1 * V_7 ;
if ( ! F_4 ( V_3 ) )
continue;
V_7 = F_1 ( V_3 ) ;
if ( F_136 ( V_5 , V_7 , V_11 ) ) {
V_20 = V_7 ;
break;
}
}
if ( ! V_20 ) {
V_91 = F_143 ( V_75 -> V_77 , V_21 , V_91 + 1 ) ;
goto V_93;
}
}
return V_20 ;
}
static int F_124 ( struct V_1 * V_94 )
{
struct V_95 * V_96 ;
struct V_38 * V_97 = F_144 ( V_98 ) ;
int V_99 = F_53 () ;
int V_11 = F_120 ( V_94 ) ;
if ( F_63 ( ! V_97 ) )
return - 1 ;
if ( V_94 -> V_4 . V_16 == 1 )
return - 1 ;
if ( ! F_127 ( & F_8 ( V_94 ) -> V_8 -> V_73 , V_94 , V_97 ) )
return - 1 ;
if ( F_138 ( V_11 , V_97 ) )
return V_11 ;
if ( ! F_138 ( V_99 , V_97 ) )
V_99 = - 1 ;
F_121 () ;
F_145 (cpu, sd) {
if ( V_96 -> V_54 & V_100 ) {
int V_101 ;
if ( V_99 != - 1 &&
F_138 ( V_99 , F_146 ( V_96 ) ) ) {
F_125 () ;
return V_99 ;
}
V_101 = F_147 ( V_97 ,
F_146 ( V_96 ) ) ;
if ( V_101 < V_102 ) {
F_125 () ;
return V_101 ;
}
}
}
F_125 () ;
if ( V_99 != - 1 )
return V_99 ;
V_11 = F_148 ( V_97 ) ;
if ( V_11 < V_102 )
return V_11 ;
return - 1 ;
}
static struct V_5 * F_149 ( struct V_1 * V_94 , struct V_5 * V_5 )
{
struct V_5 * V_103 = NULL ;
int V_104 ;
int V_11 ;
for ( V_104 = 0 ; V_104 < V_105 ; V_104 ++ ) {
V_11 = F_124 ( V_94 ) ;
if ( ( V_11 == - 1 ) || ( V_11 == V_5 -> V_11 ) )
break;
V_103 = F_52 ( V_11 ) ;
if ( F_150 ( V_5 , V_103 ) ) {
if ( F_63 ( F_8 ( V_94 ) != V_5 ||
! F_138 ( V_103 -> V_11 ,
F_139 ( V_94 ) ) ||
F_137 ( V_5 , V_94 ) ||
! V_94 -> V_106 ) ) {
F_61 ( & V_103 -> V_55 ) ;
V_103 = NULL ;
break;
}
}
if ( V_103 -> V_4 . V_19 . V_33 > V_94 -> V_18 )
break;
F_151 ( V_5 , V_103 ) ;
V_103 = NULL ;
}
return V_103 ;
}
static struct V_1 * F_152 ( struct V_5 * V_5 )
{
struct V_1 * V_7 ;
if ( ! F_21 ( V_5 ) )
return NULL ;
V_7 = F_28 ( & V_5 -> V_4 . V_17 ,
struct V_1 , V_17 ) ;
F_66 ( V_5 -> V_11 != F_120 ( V_7 ) ) ;
F_66 ( F_110 ( V_5 , V_7 ) ) ;
F_66 ( V_7 -> V_4 . V_16 <= 1 ) ;
F_66 ( ! V_7 -> V_106 ) ;
F_66 ( ! F_123 ( V_7 ) ) ;
return V_7 ;
}
static int F_153 ( struct V_5 * V_5 )
{
struct V_1 * V_107 ;
struct V_5 * V_103 ;
int V_108 = 0 ;
if ( ! V_5 -> V_4 . V_15 )
return 0 ;
V_107 = F_152 ( V_5 ) ;
if ( ! V_107 )
return 0 ;
V_109:
if ( F_63 ( V_107 == V_5 -> V_33 ) ) {
F_93 ( 1 ) ;
return 0 ;
}
if ( F_63 ( V_107 -> V_18 < V_5 -> V_33 -> V_18 ) ) {
F_46 ( V_5 -> V_33 ) ;
return 0 ;
}
F_154 ( V_107 ) ;
V_103 = F_149 ( V_107 , V_5 ) ;
if ( ! V_103 ) {
struct V_1 * V_94 ;
V_94 = F_152 ( V_5 ) ;
if ( F_120 ( V_107 ) == V_5 -> V_11 && V_94 == V_107 ) {
goto V_89;
}
if ( ! V_94 )
goto V_89;
F_155 ( V_107 ) ;
V_107 = V_94 ;
goto V_109;
}
F_156 ( V_5 , V_107 , 0 ) ;
F_157 ( V_107 , V_103 -> V_11 ) ;
F_158 ( V_103 , V_107 , 0 ) ;
V_108 = 1 ;
F_46 ( V_103 -> V_33 ) ;
F_151 ( V_5 , V_103 ) ;
V_89:
F_155 ( V_107 ) ;
return V_108 ;
}
static void F_159 ( struct V_5 * V_5 )
{
while ( F_153 ( V_5 ) )
;
}
static int F_160 ( struct V_5 * V_110 )
{
int V_99 = V_110 -> V_11 , V_108 = 0 , V_11 ;
struct V_1 * V_7 ;
struct V_5 * V_111 ;
if ( F_161 ( ! F_9 ( V_110 ) ) )
return 0 ;
F_59 (cpu, this_rq->rd->rto_mask) {
if ( V_99 == V_11 )
continue;
V_111 = F_52 ( V_11 ) ;
if ( V_111 -> V_4 . V_19 . V_20 >=
V_110 -> V_4 . V_19 . V_33 )
continue;
F_150 ( V_110 , V_111 ) ;
if ( V_111 -> V_4 . V_34 <= 1 )
goto V_112;
V_7 = F_140 ( V_111 , V_99 ) ;
if ( V_7 && ( V_7 -> V_18 < V_110 -> V_4 . V_19 . V_33 ) ) {
F_93 ( V_7 == V_111 -> V_33 ) ;
F_93 ( ! V_7 -> V_106 ) ;
if ( V_7 -> V_18 < V_111 -> V_33 -> V_18 )
goto V_112;
V_108 = 1 ;
F_156 ( V_111 , V_7 , 0 ) ;
F_157 ( V_7 , V_99 ) ;
F_158 ( V_110 , V_7 , 0 ) ;
}
V_112:
F_151 ( V_110 , V_111 ) ;
}
return V_108 ;
}
static void F_162 ( struct V_5 * V_5 , struct V_1 * V_113 )
{
if ( V_5 -> V_4 . V_19 . V_33 > V_113 -> V_18 )
F_160 ( V_5 ) ;
}
static void F_163 ( struct V_5 * V_5 )
{
F_159 ( V_5 ) ;
}
static void F_164 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_137 ( V_5 , V_7 ) &&
! F_130 ( V_5 -> V_33 ) &&
F_21 ( V_5 ) &&
V_7 -> V_4 . V_16 > 1 &&
F_123 ( V_5 -> V_33 ) &&
( V_5 -> V_33 -> V_4 . V_16 < 2 ||
V_5 -> V_33 -> V_18 <= V_7 -> V_18 ) )
F_159 ( V_5 ) ;
}
static void F_165 ( struct V_1 * V_7 ,
const struct V_38 * V_114 )
{
int V_45 = F_57 ( V_114 ) ;
F_66 ( ! F_123 ( V_7 ) ) ;
if ( V_7 -> V_106 && ( V_45 != V_7 -> V_4 . V_16 ) ) {
struct V_5 * V_5 = F_8 ( V_7 ) ;
if ( ! F_110 ( V_5 , V_7 ) ) {
if ( V_7 -> V_4 . V_16 > 1 )
F_27 ( V_5 , V_7 ) ;
if ( V_45 > 1 )
F_23 ( V_5 , V_7 ) ;
}
if ( ( V_7 -> V_4 . V_16 <= 1 ) && ( V_45 > 1 ) ) {
V_5 -> V_4 . V_13 ++ ;
} else if ( ( V_7 -> V_4 . V_16 > 1 ) && ( V_45 <= 1 ) ) {
F_66 ( ! V_5 -> V_4 . V_13 ) ;
V_5 -> V_4 . V_13 -- ;
}
F_18 ( & V_5 -> V_4 ) ;
}
}
static void F_166 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_15 )
F_11 ( V_5 ) ;
F_70 ( V_5 ) ;
F_89 ( & V_5 -> V_8 -> V_73 , V_5 -> V_11 , V_5 -> V_4 . V_19 . V_33 ) ;
}
static void F_167 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_15 )
F_15 ( V_5 ) ;
F_62 ( V_5 ) ;
F_89 ( & V_5 -> V_8 -> V_73 , V_5 -> V_11 , V_115 ) ;
}
static void F_168 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_7 -> V_106 && ! V_5 -> V_4 . V_34 )
F_160 ( V_5 ) ;
}
static inline void F_169 ( void )
{
unsigned int V_44 ;
F_170 (i)
F_171 ( & F_172 ( V_98 , V_44 ) ,
V_116 , F_173 ( V_44 ) ) ;
}
static void F_174 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
int V_117 = 1 ;
if ( V_7 -> V_106 && V_5 -> V_33 != V_7 ) {
#ifdef F_129
if ( V_5 -> V_4 . V_15 && F_153 ( V_5 ) &&
V_5 != F_8 ( V_7 ) )
V_117 = 0 ;
#endif
if ( V_117 && V_7 -> V_18 < V_5 -> V_33 -> V_18 )
F_46 ( V_5 -> V_33 ) ;
}
}
static void
F_175 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_118 )
{
if ( ! V_7 -> V_106 )
return;
if ( V_5 -> V_33 == V_7 ) {
#ifdef F_129
if ( V_118 < V_7 -> V_18 )
F_160 ( V_5 ) ;
if ( V_7 -> V_18 > V_5 -> V_4 . V_19 . V_33 && V_5 -> V_33 == V_7 )
F_46 ( V_7 ) ;
#else
if ( V_118 < V_7 -> V_18 )
F_46 ( V_7 ) ;
#endif
} else {
if ( V_7 -> V_18 < V_5 -> V_33 -> V_18 )
F_46 ( V_5 -> V_33 ) ;
}
}
static void F_176 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
unsigned long V_119 , V_120 ;
V_119 = F_177 ( V_7 , V_121 ) ;
V_120 = F_178 ( V_7 , V_121 ) ;
if ( V_119 != V_122 ) {
unsigned long V_20 ;
V_7 -> V_4 . V_84 ++ ;
V_20 = F_179 ( F_76 ( V_119 , V_120 ) , V_123 / V_124 ) ;
if ( V_7 -> V_4 . V_84 > V_20 )
V_7 -> V_125 . V_126 = V_7 -> V_67 . V_71 ;
}
}
static void F_180 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_127 )
{
F_81 ( V_5 ) ;
F_176 ( V_5 , V_7 ) ;
if ( V_7 -> V_128 != V_129 )
return;
if ( -- V_7 -> V_4 . V_130 )
return;
V_7 -> V_4 . V_130 = V_131 ;
if ( V_7 -> V_4 . V_22 . V_113 != V_7 -> V_4 . V_22 . V_20 ) {
F_117 ( V_5 , V_7 , 0 ) ;
F_181 ( V_7 ) ;
}
}
static void F_182 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_33 ;
V_7 -> V_67 . V_68 = V_5 -> V_66 ;
F_27 ( V_5 , V_7 ) ;
}
static unsigned int F_183 ( struct V_5 * V_5 , struct V_1 * V_94 )
{
if ( V_94 -> V_128 == V_129 )
return V_131 ;
else
return 0 ;
}
static void F_184 ( struct V_132 * V_133 , int V_11 )
{
T_3 V_48 ;
struct V_6 * V_6 ;
F_121 () ;
F_64 (rt_rq, iter, cpu_rq(cpu))
F_185 ( V_133 , V_11 , V_6 ) ;
F_125 () ;
}
