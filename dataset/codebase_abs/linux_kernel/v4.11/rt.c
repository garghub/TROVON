static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
int V_7 = 0 ;
int V_8 ;
F_3 ( & V_5 -> V_9 ) ;
for (; ; ) {
V_8 = F_4 ( V_3 , V_5 -> V_10 ) ;
if ( ! V_8 )
break;
F_5 ( & V_5 -> V_9 ) ;
V_7 = F_6 ( V_5 , V_8 ) ;
F_3 ( & V_5 -> V_9 ) ;
}
if ( V_7 )
V_5 -> V_11 = 0 ;
F_5 ( & V_5 -> V_9 ) ;
return V_7 ? V_12 : V_13 ;
}
void F_7 ( struct V_4 * V_5 , T_1 V_14 , T_1 V_15 )
{
V_5 -> V_10 = F_8 ( V_14 ) ;
V_5 -> V_16 = V_15 ;
F_9 ( & V_5 -> V_9 ) ;
F_10 ( & V_5 -> V_6 ,
V_17 , V_18 ) ;
V_5 -> V_6 . V_19 = F_1 ;
}
static void F_11 ( struct V_4 * V_5 )
{
if ( ! F_12 () || V_5 -> V_16 == V_20 )
return;
F_3 ( & V_5 -> V_9 ) ;
if ( ! V_5 -> V_11 ) {
V_5 -> V_11 = 1 ;
F_4 ( & V_5 -> V_6 , F_8 ( 0 ) ) ;
F_13 ( & V_5 -> V_6 , V_21 ) ;
}
F_5 ( & V_5 -> V_9 ) ;
}
void F_14 ( struct V_22 * V_22 )
{
struct V_23 * V_24 ;
int V_25 ;
V_24 = & V_22 -> V_26 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
F_15 ( V_24 -> V_28 + V_25 ) ;
F_16 ( V_25 , V_24 -> V_29 ) ;
}
F_17 ( V_27 , V_24 -> V_29 ) ;
#if V_30 V_31
V_22 -> V_32 . V_33 = V_27 ;
V_22 -> V_32 . V_34 = V_27 ;
V_22 -> V_35 = 0 ;
V_22 -> V_36 = 0 ;
F_18 ( & V_22 -> V_37 ) ;
#ifdef F_19
V_22 -> V_38 = 0 ;
V_22 -> V_39 = V_40 ;
F_9 ( & V_22 -> V_41 ) ;
F_20 ( & V_22 -> V_42 , V_43 ) ;
#endif
#endif
V_22 -> V_44 = 0 ;
V_22 -> V_45 = 0 ;
V_22 -> V_46 = 0 ;
V_22 -> V_16 = 0 ;
F_9 ( & V_22 -> V_9 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
F_22 ( & V_5 -> V_6 ) ;
}
static inline struct V_47 * F_23 ( struct V_48 * V_49 )
{
#ifdef F_24
F_25 ( ! F_26 ( V_49 ) ) ;
#endif
return F_2 ( V_49 , struct V_47 , V_50 ) ;
}
static inline struct V_51 * F_27 ( struct V_22 * V_22 )
{
return V_22 -> V_51 ;
}
static inline struct V_22 * F_28 ( struct V_48 * V_49 )
{
return V_49 -> V_22 ;
}
static inline struct V_51 * F_29 ( struct V_48 * V_49 )
{
struct V_22 * V_22 = V_49 -> V_22 ;
return V_22 -> V_51 ;
}
void F_30 ( struct V_52 * V_53 )
{
int V_25 ;
if ( V_53 -> V_49 )
F_21 ( & V_53 -> V_4 ) ;
F_31 (i) {
if ( V_53 -> V_22 )
F_32 ( V_53 -> V_22 [ V_25 ] ) ;
if ( V_53 -> V_49 )
F_32 ( V_53 -> V_49 [ V_25 ] ) ;
}
F_32 ( V_53 -> V_22 ) ;
F_32 ( V_53 -> V_49 ) ;
}
void F_33 ( struct V_52 * V_53 , struct V_22 * V_22 ,
struct V_48 * V_49 , int V_54 ,
struct V_48 * V_55 )
{
struct V_51 * V_51 = F_34 ( V_54 ) ;
V_22 -> V_32 . V_33 = V_27 ;
V_22 -> V_56 = 0 ;
V_22 -> V_51 = V_51 ;
V_22 -> V_53 = V_53 ;
V_53 -> V_22 [ V_54 ] = V_22 ;
V_53 -> V_49 [ V_54 ] = V_49 ;
if ( ! V_49 )
return;
if ( ! V_55 )
V_49 -> V_22 = & V_51 -> V_50 ;
else
V_49 -> V_22 = V_55 -> V_57 ;
V_49 -> V_57 = V_22 ;
V_49 -> V_55 = V_55 ;
F_15 ( & V_49 -> V_58 ) ;
}
int F_35 ( struct V_52 * V_53 , struct V_52 * V_55 )
{
struct V_22 * V_22 ;
struct V_48 * V_49 ;
int V_25 ;
V_53 -> V_22 = F_36 ( sizeof( V_22 ) * V_40 , V_59 ) ;
if ( ! V_53 -> V_22 )
goto V_60;
V_53 -> V_49 = F_36 ( sizeof( V_49 ) * V_40 , V_59 ) ;
if ( ! V_53 -> V_49 )
goto V_60;
F_7 ( & V_53 -> V_4 ,
F_37 ( V_61 . V_10 ) , 0 ) ;
F_31 (i) {
V_22 = F_38 ( sizeof( struct V_22 ) ,
V_59 , F_39 ( V_25 ) ) ;
if ( ! V_22 )
goto V_60;
V_49 = F_38 ( sizeof( struct V_48 ) ,
V_59 , F_39 ( V_25 ) ) ;
if ( ! V_49 )
goto V_62;
F_14 ( V_22 ) ;
V_22 -> V_16 = V_53 -> V_4 . V_16 ;
F_33 ( V_53 , V_22 , V_49 , V_25 , V_55 -> V_49 [ V_25 ] ) ;
}
return 1 ;
V_62:
F_32 ( V_22 ) ;
V_60:
return 0 ;
}
static inline struct V_47 * F_23 ( struct V_48 * V_49 )
{
return F_2 ( V_49 , struct V_47 , V_50 ) ;
}
static inline struct V_51 * F_27 ( struct V_22 * V_22 )
{
return F_2 ( V_22 , struct V_51 , V_50 ) ;
}
static inline struct V_51 * F_29 ( struct V_48 * V_49 )
{
struct V_47 * V_63 = F_23 ( V_49 ) ;
return F_40 ( V_63 ) ;
}
static inline struct V_22 * F_28 ( struct V_48 * V_49 )
{
struct V_51 * V_51 = F_29 ( V_49 ) ;
return & V_51 -> V_50 ;
}
void F_30 ( struct V_52 * V_53 ) { }
int F_35 ( struct V_52 * V_53 , struct V_52 * V_55 )
{
return 1 ;
}
static inline bool F_41 ( struct V_51 * V_51 , struct V_47 * V_64 )
{
return V_51 -> V_50 . V_32 . V_33 > V_64 -> V_65 ;
}
static inline int F_42 ( struct V_51 * V_51 )
{
return F_43 ( & V_51 -> V_66 -> V_67 ) ;
}
static inline void F_44 ( struct V_51 * V_51 )
{
if ( ! V_51 -> V_68 )
return;
F_45 ( V_51 -> V_54 , V_51 -> V_66 -> V_69 ) ;
F_46 () ;
F_47 ( & V_51 -> V_66 -> V_67 ) ;
}
static inline void F_48 ( struct V_51 * V_51 )
{
if ( ! V_51 -> V_68 )
return;
F_49 ( & V_51 -> V_66 -> V_67 ) ;
F_50 ( V_51 -> V_54 , V_51 -> V_66 -> V_69 ) ;
}
static void F_51 ( struct V_22 * V_22 )
{
if ( V_22 -> V_35 && V_22 -> V_70 > 1 ) {
if ( ! V_22 -> V_36 ) {
F_44 ( F_27 ( V_22 ) ) ;
V_22 -> V_36 = 1 ;
}
} else if ( V_22 -> V_36 ) {
F_48 ( F_27 ( V_22 ) ) ;
V_22 -> V_36 = 0 ;
}
}
static void F_52 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
struct V_47 * V_63 ;
if ( ! F_26 ( V_49 ) )
return;
V_63 = F_23 ( V_49 ) ;
V_22 = & F_27 ( V_22 ) -> V_50 ;
V_22 -> V_70 ++ ;
if ( V_63 -> V_71 > 1 )
V_22 -> V_35 ++ ;
F_51 ( V_22 ) ;
}
static void F_53 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
struct V_47 * V_63 ;
if ( ! F_26 ( V_49 ) )
return;
V_63 = F_23 ( V_49 ) ;
V_22 = & F_27 ( V_22 ) -> V_50 ;
V_22 -> V_70 -- ;
if ( V_63 -> V_71 > 1 )
V_22 -> V_35 -- ;
F_51 ( V_22 ) ;
}
static inline int F_54 ( struct V_51 * V_51 )
{
return ! F_55 ( & V_51 -> V_50 . V_37 ) ;
}
static inline void F_56 ( struct V_51 * V_51 )
{
if ( ! F_54 ( V_51 ) )
return;
F_57 ( V_51 , & F_58 ( V_72 , V_51 -> V_54 ) , V_73 ) ;
}
static inline void F_59 ( struct V_51 * V_51 )
{
F_57 ( V_51 , & F_58 ( V_74 , V_51 -> V_54 ) , V_75 ) ;
}
static void F_60 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
F_61 ( & V_63 -> V_37 , & V_51 -> V_50 . V_37 ) ;
F_62 ( & V_63 -> V_37 , V_63 -> V_65 ) ;
F_63 ( & V_63 -> V_37 , & V_51 -> V_50 . V_37 ) ;
if ( V_63 -> V_65 < V_51 -> V_50 . V_32 . V_34 )
V_51 -> V_50 . V_32 . V_34 = V_63 -> V_65 ;
}
static void F_64 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
F_61 ( & V_63 -> V_37 , & V_51 -> V_50 . V_37 ) ;
if ( F_54 ( V_51 ) ) {
V_63 = F_65 ( & V_51 -> V_50 . V_37 ,
struct V_47 , V_37 ) ;
V_51 -> V_50 . V_32 . V_34 = V_63 -> V_65 ;
} else
V_51 -> V_50 . V_32 . V_34 = V_27 ;
}
static inline void F_60 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
}
static inline void F_64 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
}
static inline
void F_52 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
}
static inline
void F_53 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
}
static inline bool F_41 ( struct V_51 * V_51 , struct V_47 * V_64 )
{
return false ;
}
static inline void V_75 ( struct V_51 * V_76 )
{
}
static inline void F_56 ( struct V_51 * V_51 )
{
}
static inline int F_66 ( struct V_48 * V_49 )
{
return V_49 -> V_77 ;
}
static inline T_1 F_67 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_53 )
return V_20 ;
return V_22 -> V_16 ;
}
static inline T_1 F_68 ( struct V_22 * V_22 )
{
return F_37 ( V_22 -> V_53 -> V_4 . V_10 ) ;
}
static inline struct V_52 * F_69 ( struct V_52 * V_53 )
{
do {
V_53 = F_70 ( V_53 -> V_78 . V_34 ,
F_71 ( struct V_52 ) , V_78 ) ;
} while ( & V_53 -> V_78 != & V_79 && F_72 ( V_53 ) );
if ( & V_53 -> V_78 == & V_79 )
V_53 = NULL ;
return V_53 ;
}
static inline struct V_22 * F_73 ( struct V_48 * V_49 )
{
return V_49 -> V_57 ;
}
static void F_74 ( struct V_22 * V_22 )
{
struct V_47 * V_33 = F_27 ( V_22 ) -> V_33 ;
struct V_51 * V_51 = F_27 ( V_22 ) ;
struct V_48 * V_49 ;
int V_54 = F_75 ( V_51 ) ;
V_49 = V_22 -> V_53 -> V_49 [ V_54 ] ;
if ( V_22 -> V_80 ) {
if ( ! V_49 )
F_76 ( V_22 ) ;
else if ( ! F_66 ( V_49 ) )
F_77 ( V_49 , 0 ) ;
if ( V_22 -> V_32 . V_33 < V_33 -> V_65 )
F_78 ( V_51 ) ;
}
}
static void F_79 ( struct V_22 * V_22 )
{
struct V_48 * V_49 ;
int V_54 = F_75 ( F_27 ( V_22 ) ) ;
V_49 = V_22 -> V_53 -> V_49 [ V_54 ] ;
if ( ! V_49 )
F_80 ( V_22 ) ;
else if ( F_66 ( V_49 ) )
F_81 ( V_49 , 0 ) ;
}
static inline int F_82 ( struct V_22 * V_22 )
{
return V_22 -> V_46 && ! V_22 -> V_56 ;
}
static int F_83 ( struct V_48 * V_49 )
{
struct V_22 * V_22 = F_73 ( V_49 ) ;
struct V_47 * V_63 ;
if ( V_22 )
return ! ! V_22 -> V_56 ;
V_63 = F_23 ( V_49 ) ;
return V_63 -> V_65 != V_63 -> V_81 ;
}
static inline const struct V_82 * F_84 ( void )
{
return V_76 () -> V_66 -> V_83 ;
}
static inline const struct V_82 * F_84 ( void )
{
return V_84 ;
}
static inline
struct V_22 * F_85 ( struct V_4 * V_5 , int V_54 )
{
return F_2 ( V_5 , struct V_52 , V_4 ) -> V_22 [ V_54 ] ;
}
static inline struct V_4 * F_86 ( struct V_22 * V_22 )
{
return & V_22 -> V_53 -> V_4 ;
}
static inline T_1 F_67 ( struct V_22 * V_22 )
{
return V_22 -> V_16 ;
}
static inline T_1 F_68 ( struct V_22 * V_22 )
{
return F_37 ( V_61 . V_10 ) ;
}
static inline struct V_22 * F_73 ( struct V_48 * V_49 )
{
return NULL ;
}
static inline void F_74 ( struct V_22 * V_22 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
if ( ! V_22 -> V_80 )
return;
F_76 ( V_22 ) ;
F_78 ( V_51 ) ;
}
static inline void F_79 ( struct V_22 * V_22 )
{
F_80 ( V_22 ) ;
}
static inline int F_82 ( struct V_22 * V_22 )
{
return V_22 -> V_46 ;
}
static inline const struct V_82 * F_84 ( void )
{
return V_84 ;
}
static inline
struct V_22 * F_85 ( struct V_4 * V_5 , int V_54 )
{
return & F_34 ( V_54 ) -> V_50 ;
}
static inline struct V_4 * F_86 ( struct V_22 * V_22 )
{
return & V_61 ;
}
bool F_87 ( struct V_22 * V_22 )
{
struct V_4 * V_5 = F_86 ( V_22 ) ;
return ( F_88 ( & V_5 -> V_6 ) ||
V_22 -> V_45 < V_5 -> V_16 ) ;
}
static void F_89 ( struct V_22 * V_22 )
{
struct V_4 * V_5 = F_86 ( V_22 ) ;
struct V_85 * V_66 = F_27 ( V_22 ) -> V_66 ;
int V_25 , V_86 ;
T_1 V_10 ;
V_86 = F_90 ( V_66 -> V_83 ) ;
F_3 ( & V_5 -> V_9 ) ;
V_10 = F_37 ( V_5 -> V_10 ) ;
F_91 (i, rd->span) {
struct V_22 * V_87 = F_85 ( V_5 , V_25 ) ;
T_2 V_88 ;
if ( V_87 == V_22 )
continue;
F_3 ( & V_87 -> V_9 ) ;
if ( V_87 -> V_16 == V_20 )
goto V_34;
V_88 = V_87 -> V_16 - V_87 -> V_45 ;
if ( V_88 > 0 ) {
V_88 = F_92 ( ( T_1 ) V_88 , V_86 ) ;
if ( V_22 -> V_16 + V_88 > V_10 )
V_88 = V_10 - V_22 -> V_16 ;
V_87 -> V_16 -= V_88 ;
V_22 -> V_16 += V_88 ;
if ( V_22 -> V_16 == V_10 ) {
F_5 ( & V_87 -> V_9 ) ;
break;
}
}
V_34:
F_5 ( & V_87 -> V_9 ) ;
}
F_5 ( & V_5 -> V_9 ) ;
}
static void F_93 ( struct V_51 * V_51 )
{
struct V_85 * V_66 = V_51 -> V_66 ;
T_3 V_87 ;
struct V_22 * V_22 ;
if ( F_94 ( ! V_89 ) )
return;
F_95 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_86 ( V_22 ) ;
T_2 V_90 ;
int V_25 ;
F_3 ( & V_5 -> V_9 ) ;
F_3 ( & V_22 -> V_9 ) ;
if ( V_22 -> V_16 == V_20 ||
V_22 -> V_16 == V_5 -> V_16 )
goto V_91;
F_5 ( & V_22 -> V_9 ) ;
V_90 = V_5 -> V_16 - V_22 -> V_16 ;
F_91 (i, rd->span) {
struct V_22 * V_87 = F_85 ( V_5 , V_25 ) ;
T_2 V_88 ;
if ( V_87 == V_22 || V_87 -> V_16 == V_20 )
continue;
F_3 ( & V_87 -> V_9 ) ;
if ( V_90 > 0 ) {
V_88 = F_96 ( T_2 , V_87 -> V_16 , V_90 ) ;
V_87 -> V_16 -= V_88 ;
V_90 -= V_88 ;
} else {
V_87 -> V_16 -= V_90 ;
V_90 -= V_90 ;
}
F_5 ( & V_87 -> V_9 ) ;
if ( ! V_90 )
break;
}
F_3 ( & V_22 -> V_9 ) ;
F_97 ( V_90 ) ;
V_91:
V_22 -> V_16 = V_20 ;
V_22 -> V_46 = 0 ;
F_5 ( & V_22 -> V_9 ) ;
F_5 ( & V_5 -> V_9 ) ;
F_74 ( V_22 ) ;
}
}
static void F_98 ( struct V_51 * V_51 )
{
T_3 V_87 ;
struct V_22 * V_22 ;
if ( F_94 ( ! V_89 ) )
return;
F_95 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_86 ( V_22 ) ;
F_3 ( & V_5 -> V_9 ) ;
F_3 ( & V_22 -> V_9 ) ;
V_22 -> V_16 = V_5 -> V_16 ;
V_22 -> V_45 = 0 ;
V_22 -> V_46 = 0 ;
F_5 ( & V_22 -> V_9 ) ;
F_5 ( & V_5 -> V_9 ) ;
}
}
static void F_99 ( struct V_22 * V_22 )
{
if ( ! F_100 ( V_92 ) )
return;
if ( V_22 -> V_45 > V_22 -> V_16 ) {
F_5 ( & V_22 -> V_9 ) ;
F_89 ( V_22 ) ;
F_3 ( & V_22 -> V_9 ) ;
}
}
static inline void F_99 ( struct V_22 * V_22 ) {}
static int F_6 ( struct V_4 * V_5 , int V_8 )
{
int V_25 , V_7 = 1 , V_93 = 0 ;
const struct V_82 * V_83 ;
V_83 = F_84 () ;
#ifdef F_101
if ( V_5 == & V_94 . V_4 )
V_83 = V_84 ;
#endif
F_91 (i, span) {
int V_95 = 0 ;
struct V_22 * V_22 = F_85 ( V_5 , V_25 ) ;
struct V_51 * V_51 = F_27 ( V_22 ) ;
F_3 ( & V_51 -> V_96 ) ;
if ( V_22 -> V_45 ) {
T_1 V_15 ;
F_3 ( & V_22 -> V_9 ) ;
if ( V_22 -> V_46 )
F_99 ( V_22 ) ;
V_15 = V_22 -> V_16 ;
V_22 -> V_45 -= F_102 ( V_22 -> V_45 , V_8 * V_15 ) ;
if ( V_22 -> V_46 && V_22 -> V_45 < V_15 ) {
V_22 -> V_46 = 0 ;
V_95 = 1 ;
if ( V_22 -> V_80 && V_51 -> V_33 == V_51 -> V_7 )
F_103 ( V_51 , false ) ;
}
if ( V_22 -> V_45 || V_22 -> V_80 )
V_7 = 0 ;
F_5 ( & V_22 -> V_9 ) ;
} else if ( V_22 -> V_80 ) {
V_7 = 0 ;
if ( ! F_82 ( V_22 ) )
V_95 = 1 ;
}
if ( V_22 -> V_46 )
V_93 = 1 ;
if ( V_95 )
F_74 ( V_22 ) ;
F_5 ( & V_51 -> V_96 ) ;
}
if ( ! V_93 && ( ! F_12 () || V_5 -> V_16 == V_20 ) )
return 1 ;
return V_7 ;
}
static inline int F_104 ( struct V_48 * V_49 )
{
#ifdef F_101
struct V_22 * V_22 = F_73 ( V_49 ) ;
if ( V_22 )
return V_22 -> V_32 . V_33 ;
#endif
return F_23 ( V_49 ) -> V_65 ;
}
static int F_105 ( struct V_22 * V_22 )
{
T_1 V_15 = F_67 ( V_22 ) ;
if ( V_22 -> V_46 )
return F_82 ( V_22 ) ;
if ( V_15 >= F_68 ( V_22 ) )
return 0 ;
F_99 ( V_22 ) ;
V_15 = F_67 ( V_22 ) ;
if ( V_15 == V_20 )
return 0 ;
if ( V_22 -> V_45 > V_15 ) {
struct V_4 * V_5 = F_86 ( V_22 ) ;
if ( F_106 ( V_5 -> V_16 ) ) {
V_22 -> V_46 = 1 ;
F_107 ( L_1 ) ;
} else {
V_22 -> V_45 = 0 ;
}
if ( F_82 ( V_22 ) ) {
F_79 ( V_22 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_108 ( struct V_51 * V_51 )
{
struct V_47 * V_33 = V_51 -> V_33 ;
struct V_48 * V_49 = & V_33 -> V_50 ;
T_1 V_97 ;
if ( V_33 -> V_98 != & V_99 )
return;
V_97 = F_109 ( V_51 ) - V_33 -> V_100 . V_101 ;
if ( F_94 ( ( T_2 ) V_97 <= 0 ) )
return;
F_110 ( V_51 , V_102 ) ;
F_111 ( V_33 -> V_100 . V_103 . V_104 ,
F_112 ( V_33 -> V_100 . V_103 . V_104 , V_97 ) ) ;
V_33 -> V_100 . V_105 += V_97 ;
F_113 ( V_33 , V_97 ) ;
V_33 -> V_100 . V_101 = F_109 ( V_51 ) ;
F_114 ( V_33 , V_97 ) ;
F_115 ( V_51 , V_97 ) ;
if ( ! F_12 () )
return;
F_116 (rt_se) {
struct V_22 * V_22 = F_28 ( V_49 ) ;
if ( F_67 ( V_22 ) != V_20 ) {
F_3 ( & V_22 -> V_9 ) ;
V_22 -> V_45 += V_97 ;
if ( F_105 ( V_22 ) )
F_78 ( V_51 ) ;
F_5 ( & V_22 -> V_9 ) ;
}
}
}
static void
F_80 ( struct V_22 * V_22 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
F_97 ( & V_51 -> V_50 != V_22 ) ;
if ( ! V_22 -> V_44 )
return;
F_97 ( ! V_51 -> V_106 ) ;
F_117 ( V_51 , V_22 -> V_80 ) ;
V_22 -> V_44 = 0 ;
}
static void
F_76 ( struct V_22 * V_22 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
F_97 ( & V_51 -> V_50 != V_22 ) ;
if ( V_22 -> V_44 )
return;
if ( F_82 ( V_22 ) || ! V_22 -> V_80 )
return;
F_118 ( V_51 , V_22 -> V_80 ) ;
V_22 -> V_44 = 1 ;
}
static void
F_119 ( struct V_22 * V_22 , int V_65 , int V_107 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
#ifdef F_101
if ( & V_51 -> V_50 != V_22 )
return;
#endif
if ( V_51 -> V_68 && V_65 < V_107 )
F_120 ( & V_51 -> V_66 -> V_108 , V_51 -> V_54 , V_65 ) ;
}
static void
F_121 ( struct V_22 * V_22 , int V_65 , int V_107 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
#ifdef F_101
if ( & V_51 -> V_50 != V_22 )
return;
#endif
if ( V_51 -> V_68 && V_22 -> V_32 . V_33 != V_107 )
F_120 ( & V_51 -> V_66 -> V_108 , V_51 -> V_54 , V_22 -> V_32 . V_33 ) ;
}
static inline
void F_119 ( struct V_22 * V_22 , int V_65 , int V_107 ) {}
static inline
void F_121 ( struct V_22 * V_22 , int V_65 , int V_107 ) {}
static void
F_122 ( struct V_22 * V_22 , int V_65 )
{
int V_107 = V_22 -> V_32 . V_33 ;
if ( V_65 < V_107 )
V_22 -> V_32 . V_33 = V_65 ;
F_119 ( V_22 , V_65 , V_107 ) ;
}
static void
F_123 ( struct V_22 * V_22 , int V_65 )
{
int V_107 = V_22 -> V_32 . V_33 ;
if ( V_22 -> V_80 ) {
F_124 ( V_65 < V_107 ) ;
if ( V_65 == V_107 ) {
struct V_23 * V_24 = & V_22 -> V_26 ;
V_22 -> V_32 . V_33 =
F_125 ( V_24 -> V_29 ) ;
}
} else
V_22 -> V_32 . V_33 = V_27 ;
F_121 ( V_22 , V_65 , V_107 ) ;
}
static inline void F_122 ( struct V_22 * V_22 , int V_65 ) {}
static inline void F_123 ( struct V_22 * V_22 , int V_65 ) {}
static void
F_126 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
if ( F_83 ( V_49 ) )
V_22 -> V_56 ++ ;
if ( V_22 -> V_53 )
F_11 ( & V_22 -> V_53 -> V_4 ) ;
}
static void
F_127 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
if ( F_83 ( V_49 ) )
V_22 -> V_56 -- ;
F_124 ( ! V_22 -> V_80 && V_22 -> V_56 ) ;
}
static void
F_126 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
F_11 ( & V_61 ) ;
}
static inline
void F_127 ( struct V_48 * V_49 , struct V_22 * V_22 ) {}
static inline
unsigned int F_128 ( struct V_48 * V_49 )
{
struct V_22 * V_109 = F_73 ( V_49 ) ;
if ( V_109 )
return V_109 -> V_80 ;
else
return 1 ;
}
static inline
unsigned int F_129 ( struct V_48 * V_49 )
{
struct V_22 * V_109 = F_73 ( V_49 ) ;
struct V_47 * V_110 ;
if ( V_109 )
return V_109 -> V_111 ;
V_110 = F_23 ( V_49 ) ;
return ( V_110 -> V_112 == V_113 ) ? 1 : 0 ;
}
static inline
void F_130 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
int V_65 = F_104 ( V_49 ) ;
F_124 ( ! F_131 ( V_65 ) ) ;
V_22 -> V_80 += F_128 ( V_49 ) ;
V_22 -> V_111 += F_129 ( V_49 ) ;
F_122 ( V_22 , V_65 ) ;
F_52 ( V_49 , V_22 ) ;
F_126 ( V_49 , V_22 ) ;
}
static inline
void F_132 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
F_124 ( ! F_131 ( F_104 ( V_49 ) ) ) ;
F_124 ( ! V_22 -> V_80 ) ;
V_22 -> V_80 -= F_128 ( V_49 ) ;
V_22 -> V_111 -= F_129 ( V_49 ) ;
F_123 ( V_22 , F_104 ( V_49 ) ) ;
F_53 ( V_49 , V_22 ) ;
F_127 ( V_49 , V_22 ) ;
}
static inline bool F_133 ( unsigned int V_114 )
{
if ( ( V_114 & ( V_115 | V_116 ) ) == V_115 )
return false ;
return true ;
}
static void F_134 ( struct V_48 * V_49 , struct V_23 * V_24 )
{
F_135 ( & V_49 -> V_58 ) ;
if ( F_136 ( V_24 -> V_28 + F_104 ( V_49 ) ) )
F_16 ( F_104 ( V_49 ) , V_24 -> V_29 ) ;
V_49 -> V_117 = 0 ;
}
static void F_137 ( struct V_48 * V_49 , unsigned int V_114 )
{
struct V_22 * V_22 = F_28 ( V_49 ) ;
struct V_23 * V_24 = & V_22 -> V_26 ;
struct V_22 * V_109 = F_73 ( V_49 ) ;
struct V_118 * V_28 = V_24 -> V_28 + F_104 ( V_49 ) ;
if ( V_109 && ( F_82 ( V_109 ) || ! V_109 -> V_80 ) ) {
if ( V_49 -> V_117 )
F_134 ( V_49 , V_24 ) ;
return;
}
if ( F_133 ( V_114 ) ) {
F_25 ( V_49 -> V_117 ) ;
if ( V_114 & V_119 )
F_138 ( & V_49 -> V_58 , V_28 ) ;
else
F_139 ( & V_49 -> V_58 , V_28 ) ;
F_17 ( F_104 ( V_49 ) , V_24 -> V_29 ) ;
V_49 -> V_117 = 1 ;
}
V_49 -> V_77 = 1 ;
F_130 ( V_49 , V_22 ) ;
}
static void F_140 ( struct V_48 * V_49 , unsigned int V_114 )
{
struct V_22 * V_22 = F_28 ( V_49 ) ;
struct V_23 * V_24 = & V_22 -> V_26 ;
if ( F_133 ( V_114 ) ) {
F_25 ( ! V_49 -> V_117 ) ;
F_134 ( V_49 , V_24 ) ;
}
V_49 -> V_77 = 0 ;
F_132 ( V_49 , V_22 ) ;
}
static void F_141 ( struct V_48 * V_49 , unsigned int V_114 )
{
struct V_48 * V_120 = NULL ;
F_116 (rt_se) {
V_49 -> V_120 = V_120 ;
V_120 = V_49 ;
}
F_80 ( F_28 ( V_120 ) ) ;
for ( V_49 = V_120 ; V_49 ; V_49 = V_49 -> V_120 ) {
if ( F_66 ( V_49 ) )
F_140 ( V_49 , V_114 ) ;
}
}
static void F_77 ( struct V_48 * V_49 , unsigned int V_114 )
{
struct V_51 * V_51 = F_29 ( V_49 ) ;
F_141 ( V_49 , V_114 ) ;
F_116 (rt_se)
F_137 ( V_49 , V_114 ) ;
F_76 ( & V_51 -> V_50 ) ;
}
static void F_81 ( struct V_48 * V_49 , unsigned int V_114 )
{
struct V_51 * V_51 = F_29 ( V_49 ) ;
F_141 ( V_49 , V_114 ) ;
F_116 (rt_se) {
struct V_22 * V_22 = F_73 ( V_49 ) ;
if ( V_22 && V_22 -> V_80 )
F_137 ( V_49 , V_114 ) ;
}
F_76 ( & V_51 -> V_50 ) ;
}
static void
F_142 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_114 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
if ( V_114 & V_121 )
V_49 -> V_122 = 0 ;
F_77 ( V_49 , V_114 ) ;
if ( ! F_143 ( V_51 , V_63 ) && V_63 -> V_71 > 1 )
F_60 ( V_51 , V_63 ) ;
}
static void F_144 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_114 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
F_108 ( V_51 ) ;
F_81 ( V_49 , V_114 ) ;
F_64 ( V_51 , V_63 ) ;
}
static void
F_145 ( struct V_22 * V_22 , struct V_48 * V_49 , int V_123 )
{
if ( F_66 ( V_49 ) ) {
struct V_23 * V_24 = & V_22 -> V_26 ;
struct V_118 * V_28 = V_24 -> V_28 + F_104 ( V_49 ) ;
if ( V_123 )
F_146 ( & V_49 -> V_58 , V_28 ) ;
else
F_147 ( & V_49 -> V_58 , V_28 ) ;
}
}
static void F_148 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_123 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
struct V_22 * V_22 ;
F_116 (rt_se) {
V_22 = F_28 ( V_49 ) ;
F_145 ( V_22 , V_49 , V_123 ) ;
}
}
static void F_149 ( struct V_51 * V_51 )
{
F_148 ( V_51 , V_51 -> V_33 , 0 ) ;
}
static int
F_150 ( struct V_47 * V_63 , int V_54 , int V_124 , int V_114 )
{
struct V_47 * V_33 ;
struct V_51 * V_51 ;
if ( V_124 != V_125 && V_124 != V_126 )
goto V_127;
V_51 = F_34 ( V_54 ) ;
F_151 () ;
V_33 = F_152 ( V_51 -> V_33 ) ;
if ( V_33 && F_94 ( F_153 ( V_33 ) ) &&
( V_33 -> V_71 < 2 ||
V_33 -> V_65 <= V_63 -> V_65 ) ) {
int V_128 = F_154 ( V_63 ) ;
if ( V_128 != - 1 &&
V_63 -> V_65 < F_34 ( V_128 ) -> V_50 . V_32 . V_33 )
V_54 = V_128 ;
}
F_155 () ;
V_127:
return V_54 ;
}
static void F_156 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( V_51 -> V_33 -> V_71 == 1 ||
! F_157 ( & V_51 -> V_66 -> V_108 , V_51 -> V_33 , NULL ) )
return;
if ( V_63 -> V_71 != 1
&& F_157 ( & V_51 -> V_66 -> V_108 , V_63 , NULL ) )
return;
F_148 ( V_51 , V_63 , 1 ) ;
F_78 ( V_51 ) ;
}
static void F_158 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_114 )
{
if ( V_63 -> V_65 < V_51 -> V_33 -> V_65 ) {
F_78 ( V_51 ) ;
return;
}
#ifdef V_31
if ( V_63 -> V_65 == V_51 -> V_33 -> V_65 && ! F_159 ( V_51 -> V_33 ) )
F_156 ( V_51 , V_63 ) ;
#endif
}
static struct V_48 * F_160 ( struct V_51 * V_51 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_26 ;
struct V_48 * V_34 = NULL ;
struct V_118 * V_28 ;
int V_129 ;
V_129 = F_125 ( V_24 -> V_29 ) ;
F_97 ( V_129 >= V_27 ) ;
V_28 = V_24 -> V_28 + V_129 ;
V_34 = F_161 ( V_28 -> V_34 , struct V_48 , V_58 ) ;
return V_34 ;
}
static struct V_47 * F_162 ( struct V_51 * V_51 )
{
struct V_48 * V_49 ;
struct V_47 * V_63 ;
struct V_22 * V_22 = & V_51 -> V_50 ;
do {
V_49 = F_160 ( V_51 , V_22 ) ;
F_97 ( ! V_49 ) ;
V_22 = F_73 ( V_49 ) ;
} while ( V_22 );
V_63 = F_23 ( V_49 ) ;
V_63 -> V_100 . V_101 = F_109 ( V_51 ) ;
return V_63 ;
}
static struct V_47 *
F_163 ( struct V_51 * V_51 , struct V_47 * V_64 , struct V_130 * V_131 )
{
struct V_47 * V_63 ;
struct V_22 * V_22 = & V_51 -> V_50 ;
if ( F_41 ( V_51 , V_64 ) ) {
F_164 ( V_51 , V_131 ) ;
V_75 ( V_51 ) ;
F_165 ( V_51 , V_131 ) ;
if ( F_94 ( ( V_51 -> V_132 && F_166 ( V_51 -> V_132 ) ) ||
V_51 -> V_133 . V_134 ) )
return V_135 ;
}
if ( V_64 -> V_98 == & V_99 )
F_108 ( V_51 ) ;
if ( ! V_22 -> V_44 )
return NULL ;
F_167 ( V_51 , V_64 ) ;
V_63 = F_162 ( V_51 ) ;
F_64 ( V_51 , V_63 ) ;
F_56 ( V_51 ) ;
return V_63 ;
}
static void F_168 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
F_108 ( V_51 ) ;
if ( F_66 ( & V_63 -> V_50 ) && V_63 -> V_71 > 1 )
F_60 ( V_51 , V_63 ) ;
}
static int F_169 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_54 )
{
if ( ! F_170 ( V_51 , V_63 ) &&
F_171 ( V_54 , & V_63 -> V_136 ) )
return 1 ;
return 0 ;
}
static struct V_47 * F_172 ( struct V_51 * V_51 , int V_54 )
{
struct V_137 * V_123 = & V_51 -> V_50 . V_37 ;
struct V_47 * V_63 ;
if ( ! F_54 ( V_51 ) )
return NULL ;
F_173 (p, head, pushable_tasks) {
if ( F_169 ( V_51 , V_63 , V_54 ) )
return V_63 ;
}
return NULL ;
}
static int F_154 ( struct V_47 * V_138 )
{
struct V_139 * V_140 ;
struct V_82 * V_141 = F_174 ( V_142 ) ;
int V_143 = F_175 () ;
int V_54 = F_176 ( V_138 ) ;
if ( F_94 ( ! V_141 ) )
return - 1 ;
if ( V_138 -> V_71 == 1 )
return - 1 ;
if ( ! F_157 ( & F_40 ( V_138 ) -> V_66 -> V_108 , V_138 , V_141 ) )
return - 1 ;
if ( F_171 ( V_54 , V_141 ) )
return V_54 ;
if ( ! F_171 ( V_143 , V_141 ) )
V_143 = - 1 ;
F_151 () ;
F_177 (cpu, sd) {
if ( V_140 -> V_114 & V_144 ) {
int V_145 ;
if ( V_143 != - 1 &&
F_171 ( V_143 , F_178 ( V_140 ) ) ) {
F_155 () ;
return V_143 ;
}
V_145 = F_179 ( V_141 ,
F_178 ( V_140 ) ) ;
if ( V_145 < V_40 ) {
F_155 () ;
return V_145 ;
}
}
}
F_155 () ;
if ( V_143 != - 1 )
return V_143 ;
V_54 = F_180 ( V_141 ) ;
if ( V_54 < V_40 )
return V_54 ;
return - 1 ;
}
static struct V_51 * F_181 ( struct V_47 * V_138 , struct V_51 * V_51 )
{
struct V_51 * V_146 = NULL ;
int V_147 ;
int V_54 ;
for ( V_147 = 0 ; V_147 < V_148 ; V_147 ++ ) {
V_54 = F_154 ( V_138 ) ;
if ( ( V_54 == - 1 ) || ( V_54 == V_51 -> V_54 ) )
break;
V_146 = F_34 ( V_54 ) ;
if ( V_146 -> V_50 . V_32 . V_33 <= V_138 -> V_65 ) {
V_146 = NULL ;
break;
}
if ( F_182 ( V_51 , V_146 ) ) {
if ( F_94 ( F_40 ( V_138 ) != V_51 ||
! F_171 ( V_146 -> V_54 , & V_138 -> V_136 ) ||
F_170 ( V_51 , V_138 ) ||
! F_153 ( V_138 ) ||
! F_166 ( V_138 ) ) ) {
F_183 ( V_51 , V_146 ) ;
V_146 = NULL ;
break;
}
}
if ( V_146 -> V_50 . V_32 . V_33 > V_138 -> V_65 )
break;
F_183 ( V_51 , V_146 ) ;
V_146 = NULL ;
}
return V_146 ;
}
static struct V_47 * F_184 ( struct V_51 * V_51 )
{
struct V_47 * V_63 ;
if ( ! F_54 ( V_51 ) )
return NULL ;
V_63 = F_65 ( & V_51 -> V_50 . V_37 ,
struct V_47 , V_37 ) ;
F_97 ( V_51 -> V_54 != F_176 ( V_63 ) ) ;
F_97 ( F_143 ( V_51 , V_63 ) ) ;
F_97 ( V_63 -> V_71 <= 1 ) ;
F_97 ( ! F_166 ( V_63 ) ) ;
F_97 ( ! F_153 ( V_63 ) ) ;
return V_63 ;
}
static int F_185 ( struct V_51 * V_51 )
{
struct V_47 * V_149 ;
struct V_51 * V_146 ;
int V_150 = 0 ;
if ( ! V_51 -> V_50 . V_36 )
return 0 ;
V_149 = F_184 ( V_51 ) ;
if ( ! V_149 )
return 0 ;
V_151:
if ( F_94 ( V_149 == V_51 -> V_33 ) ) {
F_124 ( 1 ) ;
return 0 ;
}
if ( F_94 ( V_149 -> V_65 < V_51 -> V_33 -> V_65 ) ) {
F_78 ( V_51 ) ;
return 0 ;
}
F_186 ( V_149 ) ;
V_146 = F_181 ( V_149 , V_51 ) ;
if ( ! V_146 ) {
struct V_47 * V_138 ;
V_138 = F_184 ( V_51 ) ;
if ( F_176 ( V_149 ) == V_51 -> V_54 && V_138 == V_149 ) {
goto V_127;
}
if ( ! V_138 )
goto V_127;
F_187 ( V_149 ) ;
V_149 = V_138 ;
goto V_151;
}
F_188 ( V_51 , V_149 , 0 ) ;
F_189 ( V_149 , V_146 -> V_54 ) ;
F_190 ( V_146 , V_149 , 0 ) ;
V_150 = 1 ;
F_78 ( V_146 ) ;
F_183 ( V_51 , V_146 ) ;
V_127:
F_187 ( V_149 ) ;
return V_150 ;
}
static void V_73 ( struct V_51 * V_51 )
{
while ( F_185 ( V_51 ) )
;
}
static int F_191 ( struct V_51 * V_51 )
{
int V_152 = V_51 -> V_50 . V_39 ;
int V_54 ;
V_54 = F_192 ( V_152 , V_51 -> V_66 -> V_69 ) ;
if ( V_152 < V_51 -> V_54 ) {
if ( V_54 >= V_51 -> V_54 )
return V_40 ;
} else if ( V_54 >= V_40 ) {
V_54 = F_193 ( V_51 -> V_66 -> V_69 ) ;
if ( V_54 >= V_51 -> V_54 )
return V_40 ;
}
V_51 -> V_50 . V_39 = V_54 ;
return V_54 ;
}
static int F_194 ( struct V_51 * V_51 )
{
struct V_51 * V_153 ;
int V_54 ;
while ( 1 ) {
V_54 = F_191 ( V_51 ) ;
if ( V_54 >= V_40 )
break;
V_153 = F_34 ( V_54 ) ;
if ( V_153 -> V_50 . V_32 . V_34 < V_51 -> V_50 . V_32 . V_33 )
break;
}
return V_54 ;
}
static void F_195 ( struct V_51 * V_51 )
{
int V_54 ;
if ( V_51 -> V_50 . V_38 & V_154 ) {
F_3 ( & V_51 -> V_50 . V_41 ) ;
if ( V_51 -> V_50 . V_38 & V_154 ) {
V_51 -> V_50 . V_38 |= V_155 ;
F_5 ( & V_51 -> V_50 . V_41 ) ;
return;
}
F_5 ( & V_51 -> V_50 . V_41 ) ;
}
V_51 -> V_50 . V_39 = V_51 -> V_54 ;
V_54 = F_194 ( V_51 ) ;
if ( V_54 >= V_40 )
return;
V_51 -> V_50 . V_38 = V_154 ;
F_196 ( & V_51 -> V_50 . V_42 , V_54 ) ;
}
static void F_197 ( void * V_156 )
{
struct V_22 * V_22 = V_156 ;
struct V_51 * V_51 , * V_157 ;
int V_143 ;
int V_54 ;
V_143 = V_22 -> V_39 ;
F_97 ( V_143 != F_175 () ) ;
V_51 = F_34 ( V_143 ) ;
V_157 = F_27 ( V_22 ) ;
V_158:
if ( F_54 ( V_51 ) ) {
F_3 ( & V_51 -> V_96 ) ;
F_185 ( V_51 ) ;
F_5 ( & V_51 -> V_96 ) ;
}
F_3 ( & V_22 -> V_41 ) ;
if ( V_22 -> V_38 & V_155 ) {
V_22 -> V_38 &= ~ V_155 ;
V_22 -> V_39 = V_157 -> V_54 ;
}
V_54 = F_194 ( V_157 ) ;
if ( V_54 >= V_40 )
V_22 -> V_38 &= ~ V_154 ;
F_5 ( & V_22 -> V_41 ) ;
if ( V_54 >= V_40 )
return;
if ( F_94 ( V_54 == V_51 -> V_54 ) )
goto V_158;
F_196 ( & V_22 -> V_42 , V_54 ) ;
}
static void V_43 ( struct V_159 * V_160 )
{
struct V_22 * V_22 = F_2 ( V_160 , struct V_22 , V_42 ) ;
F_197 ( V_22 ) ;
}
static void V_75 ( struct V_51 * V_76 )
{
int V_143 = V_76 -> V_54 , V_54 ;
bool V_161 = false ;
struct V_47 * V_63 ;
struct V_51 * V_157 ;
if ( F_106 ( ! F_42 ( V_76 ) ) )
return;
F_198 () ;
#ifdef F_19
if ( F_100 ( V_162 ) ) {
F_195 ( V_76 ) ;
return;
}
#endif
F_91 (cpu, this_rq->rd->rto_mask) {
if ( V_143 == V_54 )
continue;
V_157 = F_34 ( V_54 ) ;
if ( V_157 -> V_50 . V_32 . V_34 >=
V_76 -> V_50 . V_32 . V_33 )
continue;
F_182 ( V_76 , V_157 ) ;
V_63 = F_172 ( V_157 , V_143 ) ;
if ( V_63 && ( V_63 -> V_65 < V_76 -> V_50 . V_32 . V_33 ) ) {
F_124 ( V_63 == V_157 -> V_33 ) ;
F_124 ( ! F_166 ( V_63 ) ) ;
if ( V_63 -> V_65 < V_157 -> V_33 -> V_65 )
goto V_163;
V_161 = true ;
F_188 ( V_157 , V_63 , 0 ) ;
F_189 ( V_63 , V_143 ) ;
F_190 ( V_76 , V_63 , 0 ) ;
}
V_163:
F_183 ( V_76 , V_157 ) ;
}
if ( V_161 )
F_78 ( V_76 ) ;
}
static void F_199 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( ! F_170 ( V_51 , V_63 ) &&
! F_159 ( V_51 -> V_33 ) &&
V_63 -> V_71 > 1 &&
( F_200 ( V_51 -> V_33 ) || F_153 ( V_51 -> V_33 ) ) &&
( V_51 -> V_33 -> V_71 < 2 ||
V_51 -> V_33 -> V_65 <= V_63 -> V_65 ) )
V_73 ( V_51 ) ;
}
static void F_201 ( struct V_51 * V_51 )
{
if ( V_51 -> V_50 . V_36 )
F_44 ( V_51 ) ;
F_98 ( V_51 ) ;
F_120 ( & V_51 -> V_66 -> V_108 , V_51 -> V_54 , V_51 -> V_50 . V_32 . V_33 ) ;
}
static void F_202 ( struct V_51 * V_51 )
{
if ( V_51 -> V_50 . V_36 )
F_48 ( V_51 ) ;
F_93 ( V_51 ) ;
F_120 ( & V_51 -> V_66 -> V_108 , V_51 -> V_54 , V_164 ) ;
}
static void F_203 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( ! F_166 ( V_63 ) || V_51 -> V_50 . V_80 )
return;
F_59 ( V_51 ) ;
}
void T_4 F_204 ( void )
{
unsigned int V_25 ;
F_31 (i) {
F_205 ( & F_58 ( V_142 , V_25 ) ,
V_59 , F_39 ( V_25 ) ) ;
}
}
static void F_206 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( F_166 ( V_63 ) && V_51 -> V_33 != V_63 ) {
#ifdef V_31
if ( V_63 -> V_71 > 1 && V_51 -> V_50 . V_36 )
F_56 ( V_51 ) ;
#endif
if ( V_63 -> V_65 < V_51 -> V_33 -> V_65 )
F_78 ( V_51 ) ;
}
}
static void
F_207 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_165 )
{
if ( ! F_166 ( V_63 ) )
return;
if ( V_51 -> V_33 == V_63 ) {
#ifdef V_31
if ( V_165 < V_63 -> V_65 )
F_59 ( V_51 ) ;
if ( V_63 -> V_65 > V_51 -> V_50 . V_32 . V_33 )
F_78 ( V_51 ) ;
#else
if ( V_165 < V_63 -> V_65 )
F_78 ( V_51 ) ;
#endif
} else {
if ( V_63 -> V_65 < V_51 -> V_33 -> V_65 )
F_78 ( V_51 ) ;
}
}
static void F_208 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
unsigned long V_166 , V_167 ;
V_166 = F_209 ( V_63 , V_168 ) ;
V_167 = F_210 ( V_63 , V_168 ) ;
if ( V_166 != V_169 ) {
unsigned long V_34 ;
if ( V_63 -> V_50 . V_170 != V_171 ) {
V_63 -> V_50 . V_122 ++ ;
V_63 -> V_50 . V_170 = V_171 ;
}
V_34 = F_211 ( F_102 ( V_166 , V_167 ) , V_172 / V_173 ) ;
if ( V_63 -> V_50 . V_122 > V_34 )
V_63 -> V_174 . V_175 = V_63 -> V_100 . V_105 ;
}
}
static inline void F_208 ( struct V_51 * V_51 , struct V_47 * V_63 ) { }
static void F_212 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_176 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
F_108 ( V_51 ) ;
F_208 ( V_51 , V_63 ) ;
if ( V_63 -> V_112 != V_113 )
return;
if ( -- V_63 -> V_50 . V_177 )
return;
V_63 -> V_50 . V_177 = V_178 ;
F_116 (rt_se) {
if ( V_49 -> V_58 . V_64 != V_49 -> V_58 . V_34 ) {
F_148 ( V_51 , V_63 , 0 ) ;
F_78 ( V_51 ) ;
return;
}
}
}
static void F_213 ( struct V_51 * V_51 )
{
struct V_47 * V_63 = V_51 -> V_33 ;
V_63 -> V_100 . V_101 = F_109 ( V_51 ) ;
F_64 ( V_51 , V_63 ) ;
}
static unsigned int F_214 ( struct V_51 * V_51 , struct V_47 * V_138 )
{
if ( V_138 -> V_112 == V_113 )
return V_178 ;
else
return 0 ;
}
void F_215 ( struct V_179 * V_180 , int V_54 )
{
T_3 V_87 ;
struct V_22 * V_22 ;
F_151 () ;
F_95 (rt_rq, iter, cpu_rq(cpu))
F_216 ( V_180 , V_54 , V_22 ) ;
F_155 () ;
}
