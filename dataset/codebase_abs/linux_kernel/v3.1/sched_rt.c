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
static void F_21 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_22 ( & V_7 -> V_17 , & V_5 -> V_4 . V_17 ) ;
F_23 ( & V_7 -> V_17 , V_7 -> V_18 ) ;
F_24 ( & V_7 -> V_17 , & V_5 -> V_4 . V_17 ) ;
}
static void F_25 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_22 ( & V_7 -> V_17 , & V_5 -> V_4 . V_17 ) ;
}
static inline int F_26 ( struct V_5 * V_5 )
{
return ! F_27 ( & V_5 -> V_4 . V_17 ) ;
}
static inline void F_21 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static inline void F_25 ( struct V_5 * V_5 , struct V_1 * V_7 )
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
static inline int F_28 ( struct V_2 * V_3 )
{
return ! F_29 ( & V_3 -> V_19 ) ;
}
static inline T_1 F_30 ( struct V_6 * V_6 )
{
if ( ! V_6 -> V_20 )
return V_21 ;
return V_6 -> V_22 ;
}
static inline T_1 F_31 ( struct V_6 * V_6 )
{
return F_32 ( V_6 -> V_20 -> V_23 . V_24 ) ;
}
static inline struct V_25 * F_33 ( struct V_25 * V_20 )
{
do {
V_20 = F_34 ( V_20 -> V_26 . V_27 ,
F_35 ( struct V_25 ) , V_26 ) ;
} while ( & V_20 -> V_26 != & V_28 && F_36 ( V_20 ) );
if ( & V_20 -> V_26 == & V_28 )
V_20 = NULL ;
return V_20 ;
}
static inline void F_37 ( struct V_6 * V_6 )
{
F_38 ( & V_6 -> V_29 ,
& F_6 ( V_6 ) -> V_29 ) ;
}
static inline void F_39 ( struct V_6 * V_6 )
{
F_40 ( & V_6 -> V_29 ) ;
}
static inline struct V_6 * F_41 ( struct V_2 * V_3 )
{
return V_3 -> V_30 ;
}
static void F_42 ( struct V_6 * V_6 )
{
struct V_1 * V_31 = F_6 ( V_6 ) -> V_31 ;
struct V_2 * V_3 ;
int V_11 = F_43 ( F_6 ( V_6 ) ) ;
V_3 = V_6 -> V_20 -> V_3 [ V_11 ] ;
if ( V_6 -> V_32 ) {
if ( V_3 && ! F_28 ( V_3 ) )
F_44 ( V_3 , false ) ;
if ( V_6 -> V_33 . V_31 < V_31 -> V_18 )
F_45 ( V_31 ) ;
}
}
static void F_46 ( struct V_6 * V_6 )
{
struct V_2 * V_3 ;
int V_11 = F_43 ( F_6 ( V_6 ) ) ;
V_3 = V_6 -> V_20 -> V_3 [ V_11 ] ;
if ( V_3 && F_28 ( V_3 ) )
F_47 ( V_3 ) ;
}
static inline int F_48 ( struct V_6 * V_6 )
{
return V_6 -> V_34 && ! V_6 -> V_35 ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_41 ( V_3 ) ;
struct V_1 * V_7 ;
if ( V_6 )
return ! ! V_6 -> V_35 ;
V_7 = F_1 ( V_3 ) ;
return V_7 -> V_18 != V_7 -> V_36 ;
}
static inline const struct V_37 * F_50 ( void )
{
return F_51 ( F_52 () ) -> V_8 -> V_38 ;
}
static inline const struct V_37 * F_50 ( void )
{
return V_39 ;
}
static inline
struct V_6 * F_53 ( struct V_23 * V_40 , int V_11 )
{
return F_5 ( V_40 , struct V_25 , V_23 ) -> V_6 [ V_11 ] ;
}
static inline struct V_23 * F_54 ( struct V_6 * V_6 )
{
return & V_6 -> V_20 -> V_23 ;
}
static inline T_1 F_30 ( struct V_6 * V_6 )
{
return V_6 -> V_22 ;
}
static inline T_1 F_31 ( struct V_6 * V_6 )
{
return F_32 ( V_41 . V_24 ) ;
}
static inline void F_37 ( struct V_6 * V_6 )
{
}
static inline void F_39 ( struct V_6 * V_6 )
{
}
static inline struct V_6 * F_41 ( struct V_2 * V_3 )
{
return NULL ;
}
static inline void F_42 ( struct V_6 * V_6 )
{
if ( V_6 -> V_32 )
F_45 ( F_6 ( V_6 ) -> V_31 ) ;
}
static inline void F_46 ( struct V_6 * V_6 )
{
}
static inline int F_48 ( struct V_6 * V_6 )
{
return V_6 -> V_34 ;
}
static inline const struct V_37 * F_50 ( void )
{
return V_39 ;
}
static inline
struct V_6 * F_53 ( struct V_23 * V_40 , int V_11 )
{
return & F_51 ( V_11 ) -> V_4 ;
}
static inline struct V_23 * F_54 ( struct V_6 * V_6 )
{
return & V_41 ;
}
static int F_55 ( struct V_6 * V_6 )
{
struct V_23 * V_40 = F_54 ( V_6 ) ;
struct V_42 * V_8 = F_51 ( F_52 () ) -> V_8 ;
int V_43 , V_44 , V_45 = 0 ;
T_1 V_24 ;
V_44 = F_56 ( V_8 -> V_38 ) ;
F_57 ( & V_40 -> V_46 ) ;
V_24 = F_32 ( V_40 -> V_24 ) ;
F_58 (i, rd->span) {
struct V_6 * V_47 = F_53 ( V_40 , V_43 ) ;
T_2 V_48 ;
if ( V_47 == V_6 )
continue;
F_57 ( & V_47 -> V_46 ) ;
if ( V_47 -> V_22 == V_21 )
goto V_27;
V_48 = V_47 -> V_22 - V_47 -> V_49 ;
if ( V_48 > 0 ) {
V_48 = F_59 ( ( T_1 ) V_48 , V_44 ) ;
if ( V_6 -> V_22 + V_48 > V_24 )
V_48 = V_24 - V_6 -> V_22 ;
V_47 -> V_22 -= V_48 ;
V_6 -> V_22 += V_48 ;
V_45 = 1 ;
if ( V_6 -> V_22 == V_24 ) {
F_60 ( & V_47 -> V_46 ) ;
break;
}
}
V_27:
F_60 ( & V_47 -> V_46 ) ;
}
F_60 ( & V_40 -> V_46 ) ;
return V_45 ;
}
static void F_61 ( struct V_5 * V_5 )
{
struct V_42 * V_8 = V_5 -> V_8 ;
T_3 V_47 ;
struct V_6 * V_6 ;
if ( F_62 ( ! V_50 ) )
return;
F_63 (rt_rq, iter, rq) {
struct V_23 * V_40 = F_54 ( V_6 ) ;
T_2 V_51 ;
int V_43 ;
F_57 ( & V_40 -> V_46 ) ;
F_57 ( & V_6 -> V_46 ) ;
if ( V_6 -> V_22 == V_21 ||
V_6 -> V_22 == V_40 -> V_22 )
goto V_52;
F_60 ( & V_6 -> V_46 ) ;
V_51 = V_40 -> V_22 - V_6 -> V_22 ;
F_58 (i, rd->span) {
struct V_6 * V_47 = F_53 ( V_40 , V_43 ) ;
T_2 V_48 ;
if ( V_47 == V_6 || V_47 -> V_22 == V_21 )
continue;
F_57 ( & V_47 -> V_46 ) ;
if ( V_51 > 0 ) {
V_48 = F_64 ( T_2 , V_47 -> V_22 , V_51 ) ;
V_47 -> V_22 -= V_48 ;
V_51 -= V_48 ;
} else {
V_47 -> V_22 -= V_51 ;
V_51 -= V_51 ;
}
F_60 ( & V_47 -> V_46 ) ;
if ( ! V_51 )
break;
}
F_57 ( & V_6 -> V_46 ) ;
F_65 ( V_51 ) ;
V_52:
V_6 -> V_22 = V_21 ;
F_60 ( & V_6 -> V_46 ) ;
F_60 ( & V_40 -> V_46 ) ;
}
}
static void F_66 ( struct V_5 * V_5 )
{
unsigned long V_53 ;
F_67 ( & V_5 -> V_54 , V_53 ) ;
F_61 ( V_5 ) ;
F_68 ( & V_5 -> V_54 , V_53 ) ;
}
static void F_69 ( struct V_5 * V_5 )
{
T_3 V_47 ;
struct V_6 * V_6 ;
if ( F_62 ( ! V_50 ) )
return;
F_63 (rt_rq, iter, rq) {
struct V_23 * V_40 = F_54 ( V_6 ) ;
F_57 ( & V_40 -> V_46 ) ;
F_57 ( & V_6 -> V_46 ) ;
V_6 -> V_22 = V_40 -> V_22 ;
V_6 -> V_49 = 0 ;
V_6 -> V_34 = 0 ;
F_60 ( & V_6 -> V_46 ) ;
F_60 ( & V_40 -> V_46 ) ;
}
}
static void F_70 ( struct V_5 * V_5 )
{
unsigned long V_53 ;
F_67 ( & V_5 -> V_54 , V_53 ) ;
F_69 ( V_5 ) ;
F_68 ( & V_5 -> V_54 , V_53 ) ;
}
static int F_71 ( struct V_6 * V_6 )
{
int V_45 = 0 ;
if ( V_6 -> V_49 > V_6 -> V_22 ) {
F_60 ( & V_6 -> V_46 ) ;
V_45 = F_55 ( V_6 ) ;
F_57 ( & V_6 -> V_46 ) ;
}
return V_45 ;
}
static inline int F_71 ( struct V_6 * V_6 )
{
return 0 ;
}
static int F_72 ( struct V_23 * V_40 , int V_55 )
{
int V_43 , V_56 = 1 ;
const struct V_37 * V_38 ;
if ( ! F_73 () || V_40 -> V_22 == V_21 )
return 1 ;
V_38 = F_50 () ;
F_58 (i, span) {
int V_57 = 0 ;
struct V_6 * V_6 = F_53 ( V_40 , V_43 ) ;
struct V_5 * V_5 = F_6 ( V_6 ) ;
F_57 ( & V_5 -> V_54 ) ;
if ( V_6 -> V_49 ) {
T_1 V_58 ;
F_57 ( & V_6 -> V_46 ) ;
if ( V_6 -> V_34 )
F_71 ( V_6 ) ;
V_58 = V_6 -> V_22 ;
V_6 -> V_49 -= F_74 ( V_6 -> V_49 , V_55 * V_58 ) ;
if ( V_6 -> V_34 && V_6 -> V_49 < V_58 ) {
V_6 -> V_34 = 0 ;
V_57 = 1 ;
if ( V_6 -> V_32 && V_5 -> V_31 == V_5 -> V_56 )
V_5 -> V_59 = - 1 ;
}
if ( V_6 -> V_49 || V_6 -> V_32 )
V_56 = 0 ;
F_60 ( & V_6 -> V_46 ) ;
} else if ( V_6 -> V_32 ) {
V_56 = 0 ;
if ( ! F_48 ( V_6 ) )
V_57 = 1 ;
}
if ( V_57 )
F_42 ( V_6 ) ;
F_60 ( & V_5 -> V_54 ) ;
}
return V_56 ;
}
static inline int F_75 ( struct V_2 * V_3 )
{
#ifdef F_76
struct V_6 * V_6 = F_41 ( V_3 ) ;
if ( V_6 )
return V_6 -> V_33 . V_31 ;
#endif
return F_1 ( V_3 ) -> V_18 ;
}
static int F_77 ( struct V_6 * V_6 )
{
T_1 V_58 = F_30 ( V_6 ) ;
if ( V_6 -> V_34 )
return F_48 ( V_6 ) ;
if ( F_30 ( V_6 ) >= F_31 ( V_6 ) )
return 0 ;
F_71 ( V_6 ) ;
V_58 = F_30 ( V_6 ) ;
if ( V_58 == V_21 )
return 0 ;
if ( V_6 -> V_49 > V_58 ) {
V_6 -> V_34 = 1 ;
if ( F_48 ( V_6 ) ) {
F_46 ( V_6 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_78 ( struct V_5 * V_5 )
{
struct V_1 * V_31 = V_5 -> V_31 ;
struct V_2 * V_3 = & V_31 -> V_4 ;
struct V_6 * V_6 = F_7 ( V_3 ) ;
T_1 V_60 ;
if ( V_31 -> V_61 != & V_62 )
return;
V_60 = V_5 -> V_63 - V_31 -> V_64 . V_65 ;
if ( F_62 ( ( T_2 ) V_60 < 0 ) )
V_60 = 0 ;
F_79 ( V_31 -> V_64 . V_66 . V_67 , F_80 ( V_31 -> V_64 . V_66 . V_67 , V_60 ) ) ;
V_31 -> V_64 . V_68 += V_60 ;
F_81 ( V_31 , V_60 ) ;
V_31 -> V_64 . V_65 = V_5 -> V_63 ;
F_82 ( V_31 , V_60 ) ;
F_83 ( V_5 , V_60 ) ;
if ( ! F_73 () )
return;
F_84 (rt_se) {
V_6 = F_7 ( V_3 ) ;
if ( F_30 ( V_6 ) != V_21 ) {
F_57 ( & V_6 -> V_46 ) ;
V_6 -> V_49 += V_60 ;
if ( F_77 ( V_6 ) )
F_45 ( V_31 ) ;
F_60 ( & V_6 -> V_46 ) ;
}
}
}
static inline int F_85 ( struct V_5 * V_5 )
{
struct V_1 * V_27 = F_86 ( V_5 , V_5 -> V_11 ) ;
if ( V_27 && F_87 ( V_27 -> V_18 ) )
return V_27 -> V_18 ;
else
return V_69 ;
}
static void
F_88 ( struct V_6 * V_6 , int V_18 , int V_70 )
{
struct V_5 * V_5 = F_6 ( V_6 ) ;
if ( V_18 < V_70 ) {
V_6 -> V_33 . V_27 = V_70 ;
if ( V_5 -> V_10 )
F_89 ( & V_5 -> V_8 -> V_71 , V_5 -> V_11 , V_18 ) ;
} else if ( V_18 == V_6 -> V_33 . V_31 )
V_6 -> V_33 . V_27 = V_18 ;
else if ( V_18 < V_6 -> V_33 . V_27 )
V_6 -> V_33 . V_27 = F_85 ( V_5 ) ;
}
static void
F_90 ( struct V_6 * V_6 , int V_18 , int V_70 )
{
struct V_5 * V_5 = F_6 ( V_6 ) ;
if ( V_6 -> V_32 && ( V_18 <= V_6 -> V_33 . V_27 ) )
V_6 -> V_33 . V_27 = F_85 ( V_5 ) ;
if ( V_5 -> V_10 && V_6 -> V_33 . V_31 != V_70 )
F_89 ( & V_5 -> V_8 -> V_71 , V_5 -> V_11 , V_6 -> V_33 . V_31 ) ;
}
static inline
void F_88 ( struct V_6 * V_6 , int V_18 , int V_70 ) {}
static inline
void F_90 ( struct V_6 * V_6 , int V_18 , int V_70 ) {}
static void
F_91 ( struct V_6 * V_6 , int V_18 )
{
int V_70 = V_6 -> V_33 . V_31 ;
if ( V_18 < V_70 )
V_6 -> V_33 . V_31 = V_18 ;
F_88 ( V_6 , V_18 , V_70 ) ;
}
static void
F_92 ( struct V_6 * V_6 , int V_18 )
{
int V_70 = V_6 -> V_33 . V_31 ;
if ( V_6 -> V_32 ) {
F_93 ( V_18 < V_70 ) ;
if ( V_18 == V_70 ) {
struct V_72 * V_73 = & V_6 -> V_74 ;
V_6 -> V_33 . V_31 =
F_94 ( V_73 -> V_75 ) ;
}
} else
V_6 -> V_33 . V_31 = V_69 ;
F_90 ( V_6 , V_18 , V_70 ) ;
}
static inline void F_91 ( struct V_6 * V_6 , int V_18 ) {}
static inline void F_92 ( struct V_6 * V_6 , int V_18 ) {}
static void
F_95 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
if ( F_49 ( V_3 ) )
V_6 -> V_35 ++ ;
if ( V_6 -> V_20 )
F_96 ( & V_6 -> V_20 -> V_23 ) ;
}
static void
F_97 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
if ( F_49 ( V_3 ) )
V_6 -> V_35 -- ;
F_93 ( ! V_6 -> V_32 && V_6 -> V_35 ) ;
}
static void
F_95 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
F_96 ( & V_41 ) ;
}
static inline
void F_97 ( struct V_2 * V_3 , struct V_6 * V_6 ) {}
static inline
void F_98 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_18 = F_75 ( V_3 ) ;
F_93 ( ! F_87 ( V_18 ) ) ;
V_6 -> V_32 ++ ;
F_91 ( V_6 , V_18 ) ;
F_19 ( V_3 , V_6 ) ;
F_95 ( V_3 , V_6 ) ;
}
static inline
void F_99 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
F_93 ( ! F_87 ( F_75 ( V_3 ) ) ) ;
F_93 ( ! V_6 -> V_32 ) ;
V_6 -> V_32 -- ;
F_92 ( V_6 , F_75 ( V_3 ) ) ;
F_20 ( V_3 , V_6 ) ;
F_97 ( V_3 , V_6 ) ;
}
static void F_100 ( struct V_2 * V_3 , bool V_76 )
{
struct V_6 * V_6 = F_7 ( V_3 ) ;
struct V_72 * V_73 = & V_6 -> V_74 ;
struct V_6 * V_77 = F_41 ( V_3 ) ;
struct V_78 * V_79 = V_73 -> V_79 + F_75 ( V_3 ) ;
if ( V_77 && ( F_48 ( V_77 ) || ! V_77 -> V_32 ) )
return;
if ( ! V_6 -> V_32 )
F_37 ( V_6 ) ;
if ( V_76 )
F_101 ( & V_3 -> V_19 , V_79 ) ;
else
F_102 ( & V_3 -> V_19 , V_79 ) ;
F_103 ( F_75 ( V_3 ) , V_73 -> V_75 ) ;
F_98 ( V_3 , V_6 ) ;
}
static void F_104 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_7 ( V_3 ) ;
struct V_72 * V_73 = & V_6 -> V_74 ;
F_105 ( & V_3 -> V_19 ) ;
if ( F_29 ( V_73 -> V_79 + F_75 ( V_3 ) ) )
F_106 ( F_75 ( V_3 ) , V_73 -> V_75 ) ;
F_99 ( V_3 , V_6 ) ;
if ( ! V_6 -> V_32 )
F_39 ( V_6 ) ;
}
static void F_107 ( struct V_2 * V_3 )
{
struct V_2 * V_80 = NULL ;
F_84 (rt_se) {
V_3 -> V_80 = V_80 ;
V_80 = V_3 ;
}
for ( V_3 = V_80 ; V_3 ; V_3 = V_3 -> V_80 ) {
if ( F_28 ( V_3 ) )
F_104 ( V_3 ) ;
}
}
static void F_44 ( struct V_2 * V_3 , bool V_76 )
{
F_107 ( V_3 ) ;
F_84 (rt_se)
F_100 ( V_3 , V_76 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
F_107 ( V_3 ) ;
F_84 (rt_se) {
struct V_6 * V_6 = F_41 ( V_3 ) ;
if ( V_6 && V_6 -> V_32 )
F_100 ( V_3 , false ) ;
}
}
static void
F_108 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_53 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
if ( V_53 & V_81 )
V_3 -> V_82 = 0 ;
F_44 ( V_3 , V_53 & V_83 ) ;
if ( ! F_109 ( V_5 , V_7 ) && V_7 -> V_4 . V_16 > 1 )
F_21 ( V_5 , V_7 ) ;
}
static void F_110 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_53 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
F_78 ( V_5 ) ;
F_47 ( V_3 ) ;
F_25 ( V_5 , V_7 ) ;
}
static void
F_111 ( struct V_6 * V_6 , struct V_2 * V_3 , int V_76 )
{
if ( F_28 ( V_3 ) ) {
struct V_72 * V_73 = & V_6 -> V_74 ;
struct V_78 * V_79 = V_73 -> V_79 + F_75 ( V_3 ) ;
if ( V_76 )
F_112 ( & V_3 -> V_19 , V_79 ) ;
else
F_113 ( & V_3 -> V_19 , V_79 ) ;
}
}
static void F_114 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_76 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
struct V_6 * V_6 ;
F_84 (rt_se) {
V_6 = F_7 ( V_3 ) ;
F_111 ( V_6 , V_3 , V_76 ) ;
}
}
static void F_115 ( struct V_5 * V_5 )
{
F_114 ( V_5 , V_5 -> V_31 , 0 ) ;
}
static int
F_116 ( struct V_1 * V_7 , int V_84 , int V_53 )
{
struct V_1 * V_31 ;
struct V_5 * V_5 ;
int V_11 ;
if ( V_84 != V_85 )
return F_52 () ;
V_11 = F_117 ( V_7 ) ;
V_5 = F_51 ( V_11 ) ;
F_118 () ;
V_31 = F_119 ( V_5 -> V_31 ) ;
if ( V_31 && F_62 ( F_120 ( V_31 ) ) &&
( V_31 -> V_4 . V_16 < 2 ||
V_31 -> V_18 <= V_7 -> V_18 ) &&
( V_7 -> V_4 . V_16 > 1 ) ) {
int V_86 = F_121 ( V_7 ) ;
if ( V_86 != - 1 )
V_11 = V_86 ;
}
F_122 () ;
return V_11 ;
}
static void F_123 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_5 -> V_31 -> V_4 . V_16 == 1 )
return;
if ( V_7 -> V_4 . V_16 != 1
&& F_124 ( & V_5 -> V_8 -> V_71 , V_7 , NULL ) )
return;
if ( ! F_124 ( & V_5 -> V_8 -> V_71 , V_5 -> V_31 , NULL ) )
return;
F_114 ( V_5 , V_7 , 1 ) ;
F_45 ( V_5 -> V_31 ) ;
}
static void F_125 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_53 )
{
if ( V_7 -> V_18 < V_5 -> V_31 -> V_18 ) {
F_45 ( V_5 -> V_31 ) ;
return;
}
#ifdef F_126
if ( V_7 -> V_18 == V_5 -> V_31 -> V_18 && ! F_127 ( V_5 -> V_31 ) )
F_123 ( V_5 , V_7 ) ;
#endif
}
static struct V_2 * F_128 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_72 * V_73 = & V_6 -> V_74 ;
struct V_2 * V_27 = NULL ;
struct V_78 * V_79 ;
int V_87 ;
V_87 = F_94 ( V_73 -> V_75 ) ;
F_65 ( V_87 >= V_69 ) ;
V_79 = V_73 -> V_79 + V_87 ;
V_27 = F_129 ( V_79 -> V_27 , struct V_2 , V_19 ) ;
return V_27 ;
}
static struct V_1 * F_130 ( struct V_5 * V_5 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_6 * V_6 ;
V_6 = & V_5 -> V_4 ;
if ( ! V_6 -> V_32 )
return NULL ;
if ( F_48 ( V_6 ) )
return NULL ;
do {
V_3 = F_128 ( V_5 , V_6 ) ;
F_65 ( ! V_3 ) ;
V_6 = F_41 ( V_3 ) ;
} while ( V_6 );
V_7 = F_1 ( V_3 ) ;
V_7 -> V_64 . V_65 = V_5 -> V_63 ;
return V_7 ;
}
static struct V_1 * F_131 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = F_130 ( V_5 ) ;
if ( V_7 )
F_25 ( V_5 , V_7 ) ;
#ifdef F_126
V_5 -> V_88 = F_26 ( V_5 ) ;
#endif
return V_7 ;
}
static void F_132 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_78 ( V_5 ) ;
V_7 -> V_64 . V_65 = 0 ;
if ( F_28 ( & V_7 -> V_4 ) && V_7 -> V_4 . V_16 > 1 )
F_21 ( V_5 , V_7 ) ;
}
static int F_133 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_11 )
{
if ( ! F_134 ( V_5 , V_7 ) &&
( V_11 < 0 || F_135 ( V_11 , & V_7 -> V_89 ) ) &&
( V_7 -> V_4 . V_16 > 1 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_86 ( struct V_5 * V_5 , int V_11 )
{
struct V_1 * V_27 = NULL ;
struct V_2 * V_3 ;
struct V_72 * V_73 ;
struct V_6 * V_6 ;
int V_87 ;
F_136 (rt_rq, rq) {
V_73 = & V_6 -> V_74 ;
V_87 = F_94 ( V_73 -> V_75 ) ;
V_90:
if ( V_87 >= V_69 )
continue;
if ( V_27 && V_27 -> V_18 < V_87 )
continue;
F_137 (rt_se, array->queue + idx, run_list) {
struct V_1 * V_7 ;
if ( ! F_4 ( V_3 ) )
continue;
V_7 = F_1 ( V_3 ) ;
if ( F_133 ( V_5 , V_7 , V_11 ) ) {
V_27 = V_7 ;
break;
}
}
if ( ! V_27 ) {
V_87 = F_138 ( V_73 -> V_75 , V_69 , V_87 + 1 ) ;
goto V_90;
}
}
return V_27 ;
}
static int F_121 ( struct V_1 * V_91 )
{
struct V_92 * V_93 ;
struct V_37 * V_94 = F_139 ( V_95 ) ;
int V_96 = F_52 () ;
int V_11 = F_117 ( V_91 ) ;
if ( F_62 ( ! V_94 ) )
return - 1 ;
if ( V_91 -> V_4 . V_16 == 1 )
return - 1 ;
if ( ! F_124 ( & F_8 ( V_91 ) -> V_8 -> V_71 , V_91 , V_94 ) )
return - 1 ;
if ( F_135 ( V_11 , V_94 ) )
return V_11 ;
if ( ! F_135 ( V_96 , V_94 ) )
V_96 = - 1 ;
F_118 () ;
F_140 (cpu, sd) {
if ( V_93 -> V_53 & V_97 ) {
int V_98 ;
if ( V_96 != - 1 &&
F_135 ( V_96 , F_141 ( V_93 ) ) ) {
F_122 () ;
return V_96 ;
}
V_98 = F_142 ( V_94 ,
F_141 ( V_93 ) ) ;
if ( V_98 < V_99 ) {
F_122 () ;
return V_98 ;
}
}
}
F_122 () ;
if ( V_96 != - 1 )
return V_96 ;
V_11 = F_143 ( V_94 ) ;
if ( V_11 < V_99 )
return V_11 ;
return - 1 ;
}
static struct V_5 * F_144 ( struct V_1 * V_91 , struct V_5 * V_5 )
{
struct V_5 * V_100 = NULL ;
int V_101 ;
int V_11 ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ ) {
V_11 = F_121 ( V_91 ) ;
if ( ( V_11 == - 1 ) || ( V_11 == V_5 -> V_11 ) )
break;
V_100 = F_51 ( V_11 ) ;
if ( F_145 ( V_5 , V_100 ) ) {
if ( F_62 ( F_8 ( V_91 ) != V_5 ||
! F_135 ( V_100 -> V_11 ,
& V_91 -> V_89 ) ||
F_134 ( V_5 , V_91 ) ||
! V_91 -> V_103 ) ) {
F_60 ( & V_100 -> V_54 ) ;
V_100 = NULL ;
break;
}
}
if ( V_100 -> V_4 . V_33 . V_31 > V_91 -> V_18 )
break;
F_146 ( V_5 , V_100 ) ;
V_100 = NULL ;
}
return V_100 ;
}
static struct V_1 * F_147 ( struct V_5 * V_5 )
{
struct V_1 * V_7 ;
if ( ! F_26 ( V_5 ) )
return NULL ;
V_7 = F_148 ( & V_5 -> V_4 . V_17 ,
struct V_1 , V_17 ) ;
F_65 ( V_5 -> V_11 != F_117 ( V_7 ) ) ;
F_65 ( F_109 ( V_5 , V_7 ) ) ;
F_65 ( V_7 -> V_4 . V_16 <= 1 ) ;
F_65 ( ! V_7 -> V_103 ) ;
F_65 ( ! F_120 ( V_7 ) ) ;
return V_7 ;
}
static int F_149 ( struct V_5 * V_5 )
{
struct V_1 * V_104 ;
struct V_5 * V_100 ;
if ( ! V_5 -> V_4 . V_15 )
return 0 ;
V_104 = F_147 ( V_5 ) ;
if ( ! V_104 )
return 0 ;
V_105:
if ( F_62 ( V_104 == V_5 -> V_31 ) ) {
F_93 ( 1 ) ;
return 0 ;
}
if ( F_62 ( V_104 -> V_18 < V_5 -> V_31 -> V_18 ) ) {
F_45 ( V_5 -> V_31 ) ;
return 0 ;
}
F_150 ( V_104 ) ;
V_100 = F_144 ( V_104 , V_5 ) ;
if ( ! V_100 ) {
struct V_1 * V_91 ;
V_91 = F_147 ( V_5 ) ;
if ( F_117 ( V_104 ) == V_5 -> V_11 && V_91 == V_104 ) {
F_25 ( V_5 , V_104 ) ;
goto V_106;
}
if ( ! V_91 )
goto V_106;
F_151 ( V_104 ) ;
V_104 = V_91 ;
goto V_105;
}
F_152 ( V_5 , V_104 , 0 ) ;
F_153 ( V_104 , V_100 -> V_11 ) ;
F_154 ( V_100 , V_104 , 0 ) ;
F_45 ( V_100 -> V_31 ) ;
F_146 ( V_5 , V_100 ) ;
V_106:
F_151 ( V_104 ) ;
return 1 ;
}
static void F_155 ( struct V_5 * V_5 )
{
while ( F_149 ( V_5 ) )
;
}
static int F_156 ( struct V_5 * V_107 )
{
int V_96 = V_107 -> V_11 , V_108 = 0 , V_11 ;
struct V_1 * V_7 ;
struct V_5 * V_109 ;
if ( F_157 ( ! F_9 ( V_107 ) ) )
return 0 ;
F_58 (cpu, this_rq->rd->rto_mask) {
if ( V_96 == V_11 )
continue;
V_109 = F_51 ( V_11 ) ;
if ( V_109 -> V_4 . V_33 . V_27 >=
V_107 -> V_4 . V_33 . V_31 )
continue;
F_145 ( V_107 , V_109 ) ;
if ( V_109 -> V_4 . V_32 <= 1 )
goto V_110;
V_7 = F_86 ( V_109 , V_96 ) ;
if ( V_7 && ( V_7 -> V_18 < V_107 -> V_4 . V_33 . V_31 ) ) {
F_93 ( V_7 == V_109 -> V_31 ) ;
F_93 ( ! V_7 -> V_103 ) ;
if ( V_7 -> V_18 < V_109 -> V_31 -> V_18 )
goto V_110;
V_108 = 1 ;
F_152 ( V_109 , V_7 , 0 ) ;
F_153 ( V_7 , V_96 ) ;
F_154 ( V_107 , V_7 , 0 ) ;
}
V_110:
F_146 ( V_107 , V_109 ) ;
}
return V_108 ;
}
static void F_158 ( struct V_5 * V_5 , struct V_1 * V_111 )
{
if ( V_5 -> V_4 . V_33 . V_31 > V_111 -> V_18 )
F_156 ( V_5 ) ;
}
static void F_159 ( struct V_5 * V_5 )
{
F_155 ( V_5 ) ;
}
static void F_160 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_134 ( V_5 , V_7 ) &&
! F_127 ( V_5 -> V_31 ) &&
F_26 ( V_5 ) &&
V_7 -> V_4 . V_16 > 1 &&
F_120 ( V_5 -> V_31 ) &&
( V_5 -> V_31 -> V_4 . V_16 < 2 ||
V_5 -> V_31 -> V_18 <= V_7 -> V_18 ) )
F_155 ( V_5 ) ;
}
static void F_161 ( struct V_1 * V_7 ,
const struct V_37 * V_112 )
{
int V_44 = F_56 ( V_112 ) ;
F_65 ( ! F_120 ( V_7 ) ) ;
if ( V_7 -> V_103 && ( V_44 != V_7 -> V_4 . V_16 ) ) {
struct V_5 * V_5 = F_8 ( V_7 ) ;
if ( ! F_109 ( V_5 , V_7 ) ) {
if ( V_7 -> V_4 . V_16 > 1 )
F_25 ( V_5 , V_7 ) ;
if ( V_44 > 1 )
F_21 ( V_5 , V_7 ) ;
}
if ( ( V_7 -> V_4 . V_16 <= 1 ) && ( V_44 > 1 ) ) {
V_5 -> V_4 . V_13 ++ ;
} else if ( ( V_7 -> V_4 . V_16 > 1 ) && ( V_44 <= 1 ) ) {
F_65 ( ! V_5 -> V_4 . V_13 ) ;
V_5 -> V_4 . V_13 -- ;
}
F_18 ( & V_5 -> V_4 ) ;
}
F_162 ( & V_7 -> V_89 , V_112 ) ;
V_7 -> V_4 . V_16 = V_44 ;
}
static void F_163 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_15 )
F_11 ( V_5 ) ;
F_69 ( V_5 ) ;
F_89 ( & V_5 -> V_8 -> V_71 , V_5 -> V_11 , V_5 -> V_4 . V_33 . V_31 ) ;
}
static void F_164 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_15 )
F_15 ( V_5 ) ;
F_61 ( V_5 ) ;
F_89 ( & V_5 -> V_8 -> V_71 , V_5 -> V_11 , V_113 ) ;
}
static void F_165 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_7 -> V_103 && ! V_5 -> V_4 . V_32 )
F_156 ( V_5 ) ;
}
static inline void F_166 ( void )
{
unsigned int V_43 ;
F_167 (i)
F_168 ( & F_169 ( V_95 , V_43 ) ,
V_114 , F_170 ( V_43 ) ) ;
}
static void F_171 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
int V_115 = 1 ;
if ( V_7 -> V_103 && V_5 -> V_31 != V_7 ) {
#ifdef F_126
if ( V_5 -> V_4 . V_15 && F_149 ( V_5 ) &&
V_5 != F_8 ( V_7 ) )
V_115 = 0 ;
#endif
if ( V_115 && V_7 -> V_18 < V_5 -> V_31 -> V_18 )
F_45 ( V_5 -> V_31 ) ;
}
}
static void
F_172 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_116 )
{
if ( ! V_7 -> V_103 )
return;
if ( V_5 -> V_31 == V_7 ) {
#ifdef F_126
if ( V_116 < V_7 -> V_18 )
F_156 ( V_5 ) ;
if ( V_7 -> V_18 > V_5 -> V_4 . V_33 . V_31 && V_5 -> V_31 == V_7 )
F_45 ( V_7 ) ;
#else
if ( V_116 < V_7 -> V_18 )
F_45 ( V_7 ) ;
#endif
} else {
if ( V_7 -> V_18 < V_5 -> V_31 -> V_18 )
F_45 ( V_5 -> V_31 ) ;
}
}
static void F_173 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
unsigned long V_117 , V_118 ;
V_117 = F_174 ( V_7 , V_119 ) ;
V_118 = F_175 ( V_7 , V_119 ) ;
if ( V_117 != V_120 ) {
unsigned long V_27 ;
V_7 -> V_4 . V_82 ++ ;
V_27 = F_176 ( F_74 ( V_117 , V_118 ) , V_121 / V_122 ) ;
if ( V_7 -> V_4 . V_82 > V_27 )
V_7 -> V_123 . V_124 = V_7 -> V_64 . V_68 ;
}
}
static void F_177 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_125 )
{
F_78 ( V_5 ) ;
F_173 ( V_5 , V_7 ) ;
if ( V_7 -> V_126 != V_127 )
return;
if ( -- V_7 -> V_4 . V_128 )
return;
V_7 -> V_4 . V_128 = V_129 ;
if ( V_7 -> V_4 . V_19 . V_111 != V_7 -> V_4 . V_19 . V_27 ) {
F_114 ( V_5 , V_7 , 0 ) ;
F_178 ( V_7 ) ;
}
}
static void F_179 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_31 ;
V_7 -> V_64 . V_65 = V_5 -> V_63 ;
F_25 ( V_5 , V_7 ) ;
}
static unsigned int F_180 ( struct V_5 * V_5 , struct V_1 * V_91 )
{
if ( V_91 -> V_126 == V_127 )
return V_129 ;
else
return 0 ;
}
static void F_181 ( struct V_130 * V_131 , int V_11 )
{
T_3 V_47 ;
struct V_6 * V_6 ;
F_118 () ;
F_63 (rt_rq, iter, cpu_rq(cpu))
F_182 ( V_131 , V_11 , V_6 ) ;
F_122 () ;
}
