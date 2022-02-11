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
if ( F_53 ( V_63 ) > 1 )
V_22 -> V_35 ++ ;
F_51 ( V_22 ) ;
}
static void F_54 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
struct V_47 * V_63 ;
if ( ! F_26 ( V_49 ) )
return;
V_63 = F_23 ( V_49 ) ;
V_22 = & F_27 ( V_22 ) -> V_50 ;
V_22 -> V_70 -- ;
if ( F_53 ( V_63 ) > 1 )
V_22 -> V_35 -- ;
F_51 ( V_22 ) ;
}
static inline int F_55 ( struct V_51 * V_51 )
{
return ! F_56 ( & V_51 -> V_50 . V_37 ) ;
}
static inline void F_57 ( struct V_51 * V_51 )
{
if ( ! F_55 ( V_51 ) )
return;
F_58 ( V_51 , & F_59 ( V_71 , V_51 -> V_54 ) , V_72 ) ;
}
static inline void F_60 ( struct V_51 * V_51 )
{
F_58 ( V_51 , & F_59 ( V_73 , V_51 -> V_54 ) , V_74 ) ;
}
static void F_61 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
F_62 ( & V_63 -> V_37 , & V_51 -> V_50 . V_37 ) ;
F_63 ( & V_63 -> V_37 , V_63 -> V_65 ) ;
F_64 ( & V_63 -> V_37 , & V_51 -> V_50 . V_37 ) ;
if ( V_63 -> V_65 < V_51 -> V_50 . V_32 . V_34 )
V_51 -> V_50 . V_32 . V_34 = V_63 -> V_65 ;
}
static void F_65 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
F_62 ( & V_63 -> V_37 , & V_51 -> V_50 . V_37 ) ;
if ( F_55 ( V_51 ) ) {
V_63 = F_66 ( & V_51 -> V_50 . V_37 ,
struct V_47 , V_37 ) ;
V_51 -> V_50 . V_32 . V_34 = V_63 -> V_65 ;
} else
V_51 -> V_50 . V_32 . V_34 = V_27 ;
}
static inline void F_61 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
}
static inline void F_65 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
}
static inline
void F_52 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
}
static inline
void F_54 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
}
static inline bool F_41 ( struct V_51 * V_51 , struct V_47 * V_64 )
{
return false ;
}
static inline void V_74 ( struct V_51 * V_75 )
{
}
static inline void F_57 ( struct V_51 * V_51 )
{
}
static inline int F_67 ( struct V_48 * V_49 )
{
return V_49 -> V_76 ;
}
static inline T_1 F_68 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_53 )
return V_20 ;
return V_22 -> V_16 ;
}
static inline T_1 F_69 ( struct V_22 * V_22 )
{
return F_37 ( V_22 -> V_53 -> V_4 . V_10 ) ;
}
static inline struct V_52 * F_70 ( struct V_52 * V_53 )
{
do {
V_53 = F_71 ( V_53 -> V_77 . V_34 ,
F_72 ( struct V_52 ) , V_77 ) ;
} while ( & V_53 -> V_77 != & V_78 && F_73 ( V_53 ) );
if ( & V_53 -> V_77 == & V_78 )
V_53 = NULL ;
return V_53 ;
}
static inline struct V_22 * F_74 ( struct V_48 * V_49 )
{
return V_49 -> V_57 ;
}
static void F_75 ( struct V_22 * V_22 )
{
struct V_47 * V_33 = F_27 ( V_22 ) -> V_33 ;
struct V_51 * V_51 = F_27 ( V_22 ) ;
struct V_48 * V_49 ;
int V_54 = F_76 ( V_51 ) ;
V_49 = V_22 -> V_53 -> V_49 [ V_54 ] ;
if ( V_22 -> V_79 ) {
if ( ! V_49 )
F_77 ( V_22 ) ;
else if ( ! F_67 ( V_49 ) )
F_78 ( V_49 , 0 ) ;
if ( V_22 -> V_32 . V_33 < V_33 -> V_65 )
F_79 ( V_51 ) ;
}
}
static void F_80 ( struct V_22 * V_22 )
{
struct V_48 * V_49 ;
int V_54 = F_76 ( F_27 ( V_22 ) ) ;
V_49 = V_22 -> V_53 -> V_49 [ V_54 ] ;
if ( ! V_49 )
F_81 ( V_22 ) ;
else if ( F_67 ( V_49 ) )
F_82 ( V_49 , 0 ) ;
}
static inline int F_83 ( struct V_22 * V_22 )
{
return V_22 -> V_46 && ! V_22 -> V_56 ;
}
static int F_84 ( struct V_48 * V_49 )
{
struct V_22 * V_22 = F_74 ( V_49 ) ;
struct V_47 * V_63 ;
if ( V_22 )
return ! ! V_22 -> V_56 ;
V_63 = F_23 ( V_49 ) ;
return V_63 -> V_65 != V_63 -> V_80 ;
}
static inline const struct V_81 * F_85 ( void )
{
return V_75 () -> V_66 -> V_82 ;
}
static inline const struct V_81 * F_85 ( void )
{
return V_83 ;
}
static inline
struct V_22 * F_86 ( struct V_4 * V_5 , int V_54 )
{
return F_2 ( V_5 , struct V_52 , V_4 ) -> V_22 [ V_54 ] ;
}
static inline struct V_4 * F_87 ( struct V_22 * V_22 )
{
return & V_22 -> V_53 -> V_4 ;
}
static inline T_1 F_68 ( struct V_22 * V_22 )
{
return V_22 -> V_16 ;
}
static inline T_1 F_69 ( struct V_22 * V_22 )
{
return F_37 ( V_61 . V_10 ) ;
}
static inline struct V_22 * F_74 ( struct V_48 * V_49 )
{
return NULL ;
}
static inline void F_75 ( struct V_22 * V_22 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
if ( ! V_22 -> V_79 )
return;
F_77 ( V_22 ) ;
F_79 ( V_51 ) ;
}
static inline void F_80 ( struct V_22 * V_22 )
{
F_81 ( V_22 ) ;
}
static inline int F_83 ( struct V_22 * V_22 )
{
return V_22 -> V_46 ;
}
static inline const struct V_81 * F_85 ( void )
{
return V_83 ;
}
static inline
struct V_22 * F_86 ( struct V_4 * V_5 , int V_54 )
{
return & F_34 ( V_54 ) -> V_50 ;
}
static inline struct V_4 * F_87 ( struct V_22 * V_22 )
{
return & V_61 ;
}
bool F_88 ( struct V_22 * V_22 )
{
struct V_4 * V_5 = F_87 ( V_22 ) ;
return ( F_89 ( & V_5 -> V_6 ) ||
V_22 -> V_45 < V_5 -> V_16 ) ;
}
static void F_90 ( struct V_22 * V_22 )
{
struct V_4 * V_5 = F_87 ( V_22 ) ;
struct V_84 * V_66 = F_27 ( V_22 ) -> V_66 ;
int V_25 , V_85 ;
T_1 V_10 ;
V_85 = F_91 ( V_66 -> V_82 ) ;
F_3 ( & V_5 -> V_9 ) ;
V_10 = F_37 ( V_5 -> V_10 ) ;
F_92 (i, rd->span) {
struct V_22 * V_86 = F_86 ( V_5 , V_25 ) ;
T_2 V_87 ;
if ( V_86 == V_22 )
continue;
F_3 ( & V_86 -> V_9 ) ;
if ( V_86 -> V_16 == V_20 )
goto V_34;
V_87 = V_86 -> V_16 - V_86 -> V_45 ;
if ( V_87 > 0 ) {
V_87 = F_93 ( ( T_1 ) V_87 , V_85 ) ;
if ( V_22 -> V_16 + V_87 > V_10 )
V_87 = V_10 - V_22 -> V_16 ;
V_86 -> V_16 -= V_87 ;
V_22 -> V_16 += V_87 ;
if ( V_22 -> V_16 == V_10 ) {
F_5 ( & V_86 -> V_9 ) ;
break;
}
}
V_34:
F_5 ( & V_86 -> V_9 ) ;
}
F_5 ( & V_5 -> V_9 ) ;
}
static void F_94 ( struct V_51 * V_51 )
{
struct V_84 * V_66 = V_51 -> V_66 ;
T_3 V_86 ;
struct V_22 * V_22 ;
if ( F_95 ( ! V_88 ) )
return;
F_96 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_87 ( V_22 ) ;
T_2 V_89 ;
int V_25 ;
F_3 ( & V_5 -> V_9 ) ;
F_3 ( & V_22 -> V_9 ) ;
if ( V_22 -> V_16 == V_20 ||
V_22 -> V_16 == V_5 -> V_16 )
goto V_90;
F_5 ( & V_22 -> V_9 ) ;
V_89 = V_5 -> V_16 - V_22 -> V_16 ;
F_92 (i, rd->span) {
struct V_22 * V_86 = F_86 ( V_5 , V_25 ) ;
T_2 V_87 ;
if ( V_86 == V_22 || V_86 -> V_16 == V_20 )
continue;
F_3 ( & V_86 -> V_9 ) ;
if ( V_89 > 0 ) {
V_87 = F_97 ( T_2 , V_86 -> V_16 , V_89 ) ;
V_86 -> V_16 -= V_87 ;
V_89 -= V_87 ;
} else {
V_86 -> V_16 -= V_89 ;
V_89 -= V_89 ;
}
F_5 ( & V_86 -> V_9 ) ;
if ( ! V_89 )
break;
}
F_3 ( & V_22 -> V_9 ) ;
F_98 ( V_89 ) ;
V_90:
V_22 -> V_16 = V_20 ;
V_22 -> V_46 = 0 ;
F_5 ( & V_22 -> V_9 ) ;
F_5 ( & V_5 -> V_9 ) ;
F_75 ( V_22 ) ;
}
}
static void F_99 ( struct V_51 * V_51 )
{
T_3 V_86 ;
struct V_22 * V_22 ;
if ( F_95 ( ! V_88 ) )
return;
F_96 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_87 ( V_22 ) ;
F_3 ( & V_5 -> V_9 ) ;
F_3 ( & V_22 -> V_9 ) ;
V_22 -> V_16 = V_5 -> V_16 ;
V_22 -> V_45 = 0 ;
V_22 -> V_46 = 0 ;
F_5 ( & V_22 -> V_9 ) ;
F_5 ( & V_5 -> V_9 ) ;
}
}
static void F_100 ( struct V_22 * V_22 )
{
if ( ! F_101 ( V_91 ) )
return;
if ( V_22 -> V_45 > V_22 -> V_16 ) {
F_5 ( & V_22 -> V_9 ) ;
F_90 ( V_22 ) ;
F_3 ( & V_22 -> V_9 ) ;
}
}
static inline void F_100 ( struct V_22 * V_22 ) {}
static int F_6 ( struct V_4 * V_5 , int V_8 )
{
int V_25 , V_7 = 1 , V_92 = 0 ;
const struct V_81 * V_82 ;
V_82 = F_85 () ;
#ifdef F_102
if ( V_5 == & V_93 . V_4 )
V_82 = V_83 ;
#endif
F_92 (i, span) {
int V_94 = 0 ;
struct V_22 * V_22 = F_86 ( V_5 , V_25 ) ;
struct V_51 * V_51 = F_27 ( V_22 ) ;
F_3 ( & V_51 -> V_95 ) ;
if ( V_22 -> V_45 ) {
T_1 V_15 ;
F_3 ( & V_22 -> V_9 ) ;
if ( V_22 -> V_46 )
F_100 ( V_22 ) ;
V_15 = V_22 -> V_16 ;
V_22 -> V_45 -= F_103 ( V_22 -> V_45 , V_8 * V_15 ) ;
if ( V_22 -> V_46 && V_22 -> V_45 < V_15 ) {
V_22 -> V_46 = 0 ;
V_94 = 1 ;
if ( V_22 -> V_79 && V_51 -> V_33 == V_51 -> V_7 )
F_104 ( V_51 , false ) ;
}
if ( V_22 -> V_45 || V_22 -> V_79 )
V_7 = 0 ;
F_5 ( & V_22 -> V_9 ) ;
} else if ( V_22 -> V_79 ) {
V_7 = 0 ;
if ( ! F_83 ( V_22 ) )
V_94 = 1 ;
}
if ( V_22 -> V_46 )
V_92 = 1 ;
if ( V_94 )
F_75 ( V_22 ) ;
F_5 ( & V_51 -> V_95 ) ;
}
if ( ! V_92 && ( ! F_12 () || V_5 -> V_16 == V_20 ) )
return 1 ;
return V_7 ;
}
static inline int F_105 ( struct V_48 * V_49 )
{
#ifdef F_102
struct V_22 * V_22 = F_74 ( V_49 ) ;
if ( V_22 )
return V_22 -> V_32 . V_33 ;
#endif
return F_23 ( V_49 ) -> V_65 ;
}
static int F_106 ( struct V_22 * V_22 )
{
T_1 V_15 = F_68 ( V_22 ) ;
if ( V_22 -> V_46 )
return F_83 ( V_22 ) ;
if ( V_15 >= F_69 ( V_22 ) )
return 0 ;
F_100 ( V_22 ) ;
V_15 = F_68 ( V_22 ) ;
if ( V_15 == V_20 )
return 0 ;
if ( V_22 -> V_45 > V_15 ) {
struct V_4 * V_5 = F_87 ( V_22 ) ;
if ( F_107 ( V_5 -> V_16 ) ) {
V_22 -> V_46 = 1 ;
F_108 ( L_1 ) ;
} else {
V_22 -> V_45 = 0 ;
}
if ( F_83 ( V_22 ) ) {
F_80 ( V_22 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_109 ( struct V_51 * V_51 )
{
struct V_47 * V_33 = V_51 -> V_33 ;
struct V_48 * V_49 = & V_33 -> V_50 ;
T_1 V_96 ;
if ( V_33 -> V_97 != & V_98 )
return;
V_96 = F_110 ( V_51 ) - V_33 -> V_99 . V_100 ;
if ( F_95 ( ( T_2 ) V_96 <= 0 ) )
return;
if ( F_76 ( V_51 ) == F_111 () )
F_112 ( F_113 ( V_51 ) ) ;
F_114 ( V_33 -> V_99 . V_101 . V_102 ,
F_115 ( V_33 -> V_99 . V_101 . V_102 , V_96 ) ) ;
V_33 -> V_99 . V_103 += V_96 ;
F_116 ( V_33 , V_96 ) ;
V_33 -> V_99 . V_100 = F_110 ( V_51 ) ;
F_117 ( V_33 , V_96 ) ;
F_118 ( V_51 , V_96 ) ;
if ( ! F_12 () )
return;
F_119 (rt_se) {
struct V_22 * V_22 = F_28 ( V_49 ) ;
if ( F_68 ( V_22 ) != V_20 ) {
F_3 ( & V_22 -> V_9 ) ;
V_22 -> V_45 += V_96 ;
if ( F_106 ( V_22 ) )
F_79 ( V_51 ) ;
F_5 ( & V_22 -> V_9 ) ;
}
}
}
static void
F_81 ( struct V_22 * V_22 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
F_98 ( & V_51 -> V_50 != V_22 ) ;
if ( ! V_22 -> V_44 )
return;
F_98 ( ! V_51 -> V_104 ) ;
F_120 ( V_51 , V_22 -> V_79 ) ;
V_22 -> V_44 = 0 ;
}
static void
F_77 ( struct V_22 * V_22 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
F_98 ( & V_51 -> V_50 != V_22 ) ;
if ( V_22 -> V_44 )
return;
if ( F_83 ( V_22 ) || ! V_22 -> V_79 )
return;
F_121 ( V_51 , V_22 -> V_79 ) ;
V_22 -> V_44 = 1 ;
}
static void
F_122 ( struct V_22 * V_22 , int V_65 , int V_105 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
#ifdef F_102
if ( & V_51 -> V_50 != V_22 )
return;
#endif
if ( V_51 -> V_68 && V_65 < V_105 )
F_123 ( & V_51 -> V_66 -> V_106 , V_51 -> V_54 , V_65 ) ;
}
static void
F_124 ( struct V_22 * V_22 , int V_65 , int V_105 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
#ifdef F_102
if ( & V_51 -> V_50 != V_22 )
return;
#endif
if ( V_51 -> V_68 && V_22 -> V_32 . V_33 != V_105 )
F_123 ( & V_51 -> V_66 -> V_106 , V_51 -> V_54 , V_22 -> V_32 . V_33 ) ;
}
static inline
void F_122 ( struct V_22 * V_22 , int V_65 , int V_105 ) {}
static inline
void F_124 ( struct V_22 * V_22 , int V_65 , int V_105 ) {}
static void
F_125 ( struct V_22 * V_22 , int V_65 )
{
int V_105 = V_22 -> V_32 . V_33 ;
if ( V_65 < V_105 )
V_22 -> V_32 . V_33 = V_65 ;
F_122 ( V_22 , V_65 , V_105 ) ;
}
static void
F_126 ( struct V_22 * V_22 , int V_65 )
{
int V_105 = V_22 -> V_32 . V_33 ;
if ( V_22 -> V_79 ) {
F_127 ( V_65 < V_105 ) ;
if ( V_65 == V_105 ) {
struct V_23 * V_24 = & V_22 -> V_26 ;
V_22 -> V_32 . V_33 =
F_128 ( V_24 -> V_29 ) ;
}
} else
V_22 -> V_32 . V_33 = V_27 ;
F_124 ( V_22 , V_65 , V_105 ) ;
}
static inline void F_125 ( struct V_22 * V_22 , int V_65 ) {}
static inline void F_126 ( struct V_22 * V_22 , int V_65 ) {}
static void
F_129 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
if ( F_84 ( V_49 ) )
V_22 -> V_56 ++ ;
if ( V_22 -> V_53 )
F_11 ( & V_22 -> V_53 -> V_4 ) ;
}
static void
F_130 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
if ( F_84 ( V_49 ) )
V_22 -> V_56 -- ;
F_127 ( ! V_22 -> V_79 && V_22 -> V_56 ) ;
}
static void
F_129 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
F_11 ( & V_61 ) ;
}
static inline
void F_130 ( struct V_48 * V_49 , struct V_22 * V_22 ) {}
static inline
unsigned int F_131 ( struct V_48 * V_49 )
{
struct V_22 * V_107 = F_74 ( V_49 ) ;
if ( V_107 )
return V_107 -> V_79 ;
else
return 1 ;
}
static inline
unsigned int F_132 ( struct V_48 * V_49 )
{
struct V_22 * V_107 = F_74 ( V_49 ) ;
struct V_47 * V_108 ;
if ( V_107 )
return V_107 -> V_109 ;
V_108 = F_23 ( V_49 ) ;
return ( V_108 -> V_110 == V_111 ) ? 1 : 0 ;
}
static inline
void F_133 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
int V_65 = F_105 ( V_49 ) ;
F_127 ( ! F_134 ( V_65 ) ) ;
V_22 -> V_79 += F_131 ( V_49 ) ;
V_22 -> V_109 += F_132 ( V_49 ) ;
F_125 ( V_22 , V_65 ) ;
F_52 ( V_49 , V_22 ) ;
F_129 ( V_49 , V_22 ) ;
}
static inline
void F_135 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
F_127 ( ! F_134 ( F_105 ( V_49 ) ) ) ;
F_127 ( ! V_22 -> V_79 ) ;
V_22 -> V_79 -= F_131 ( V_49 ) ;
V_22 -> V_109 -= F_132 ( V_49 ) ;
F_126 ( V_22 , F_105 ( V_49 ) ) ;
F_54 ( V_49 , V_22 ) ;
F_130 ( V_49 , V_22 ) ;
}
static inline bool F_136 ( unsigned int V_112 )
{
if ( ( V_112 & ( V_113 | V_114 ) ) == V_113 )
return false ;
return true ;
}
static void F_137 ( struct V_48 * V_49 , struct V_23 * V_24 )
{
F_138 ( & V_49 -> V_58 ) ;
if ( F_139 ( V_24 -> V_28 + F_105 ( V_49 ) ) )
F_16 ( F_105 ( V_49 ) , V_24 -> V_29 ) ;
V_49 -> V_115 = 0 ;
}
static void F_140 ( struct V_48 * V_49 , unsigned int V_112 )
{
struct V_22 * V_22 = F_28 ( V_49 ) ;
struct V_23 * V_24 = & V_22 -> V_26 ;
struct V_22 * V_107 = F_74 ( V_49 ) ;
struct V_116 * V_28 = V_24 -> V_28 + F_105 ( V_49 ) ;
if ( V_107 && ( F_83 ( V_107 ) || ! V_107 -> V_79 ) ) {
if ( V_49 -> V_115 )
F_137 ( V_49 , V_24 ) ;
return;
}
if ( F_136 ( V_112 ) ) {
F_25 ( V_49 -> V_115 ) ;
if ( V_112 & V_117 )
F_141 ( & V_49 -> V_58 , V_28 ) ;
else
F_142 ( & V_49 -> V_58 , V_28 ) ;
F_17 ( F_105 ( V_49 ) , V_24 -> V_29 ) ;
V_49 -> V_115 = 1 ;
}
V_49 -> V_76 = 1 ;
F_133 ( V_49 , V_22 ) ;
}
static void F_143 ( struct V_48 * V_49 , unsigned int V_112 )
{
struct V_22 * V_22 = F_28 ( V_49 ) ;
struct V_23 * V_24 = & V_22 -> V_26 ;
if ( F_136 ( V_112 ) ) {
F_25 ( ! V_49 -> V_115 ) ;
F_137 ( V_49 , V_24 ) ;
}
V_49 -> V_76 = 0 ;
F_135 ( V_49 , V_22 ) ;
}
static void F_144 ( struct V_48 * V_49 , unsigned int V_112 )
{
struct V_48 * V_118 = NULL ;
F_119 (rt_se) {
V_49 -> V_118 = V_118 ;
V_118 = V_49 ;
}
F_81 ( F_28 ( V_118 ) ) ;
for ( V_49 = V_118 ; V_49 ; V_49 = V_49 -> V_118 ) {
if ( F_67 ( V_49 ) )
F_143 ( V_49 , V_112 ) ;
}
}
static void F_78 ( struct V_48 * V_49 , unsigned int V_112 )
{
struct V_51 * V_51 = F_29 ( V_49 ) ;
F_144 ( V_49 , V_112 ) ;
F_119 (rt_se)
F_140 ( V_49 , V_112 ) ;
F_77 ( & V_51 -> V_50 ) ;
}
static void F_82 ( struct V_48 * V_49 , unsigned int V_112 )
{
struct V_51 * V_51 = F_29 ( V_49 ) ;
F_144 ( V_49 , V_112 ) ;
F_119 (rt_se) {
struct V_22 * V_22 = F_74 ( V_49 ) ;
if ( V_22 && V_22 -> V_79 )
F_140 ( V_49 , V_112 ) ;
}
F_77 ( & V_51 -> V_50 ) ;
}
static void
F_145 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_112 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
if ( V_112 & V_119 )
V_49 -> V_120 = 0 ;
F_78 ( V_49 , V_112 ) ;
if ( ! F_146 ( V_51 , V_63 ) && F_53 ( V_63 ) > 1 )
F_61 ( V_51 , V_63 ) ;
}
static void F_147 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_112 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
F_109 ( V_51 ) ;
F_82 ( V_49 , V_112 ) ;
F_65 ( V_51 , V_63 ) ;
}
static void
F_148 ( struct V_22 * V_22 , struct V_48 * V_49 , int V_121 )
{
if ( F_67 ( V_49 ) ) {
struct V_23 * V_24 = & V_22 -> V_26 ;
struct V_116 * V_28 = V_24 -> V_28 + F_105 ( V_49 ) ;
if ( V_121 )
F_149 ( & V_49 -> V_58 , V_28 ) ;
else
F_150 ( & V_49 -> V_58 , V_28 ) ;
}
}
static void F_151 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_121 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
struct V_22 * V_22 ;
F_119 (rt_se) {
V_22 = F_28 ( V_49 ) ;
F_148 ( V_22 , V_49 , V_121 ) ;
}
}
static void F_152 ( struct V_51 * V_51 )
{
F_151 ( V_51 , V_51 -> V_33 , 0 ) ;
}
static int
F_153 ( struct V_47 * V_63 , int V_54 , int V_122 , int V_112 )
{
struct V_47 * V_33 ;
struct V_51 * V_51 ;
if ( V_122 != V_123 && V_122 != V_124 )
goto V_125;
V_51 = F_34 ( V_54 ) ;
F_154 () ;
V_33 = F_155 ( V_51 -> V_33 ) ;
if ( V_33 && F_95 ( F_156 ( V_33 ) ) &&
( F_53 ( V_33 ) < 2 ||
V_33 -> V_65 <= V_63 -> V_65 ) ) {
int V_126 = F_157 ( V_63 ) ;
if ( V_126 != - 1 &&
V_63 -> V_65 < F_34 ( V_126 ) -> V_50 . V_32 . V_33 )
V_54 = V_126 ;
}
F_158 () ;
V_125:
return V_54 ;
}
static void F_159 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( F_53 ( V_51 -> V_33 ) == 1 ||
! F_160 ( & V_51 -> V_66 -> V_106 , V_51 -> V_33 , NULL ) )
return;
if ( F_53 ( V_63 ) != 1
&& F_160 ( & V_51 -> V_66 -> V_106 , V_63 , NULL ) )
return;
F_151 ( V_51 , V_63 , 1 ) ;
F_79 ( V_51 ) ;
}
static void F_161 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_112 )
{
if ( V_63 -> V_65 < V_51 -> V_33 -> V_65 ) {
F_79 ( V_51 ) ;
return;
}
#ifdef V_31
if ( V_63 -> V_65 == V_51 -> V_33 -> V_65 && ! F_162 ( V_51 -> V_33 ) )
F_159 ( V_51 , V_63 ) ;
#endif
}
static struct V_48 * F_163 ( struct V_51 * V_51 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_26 ;
struct V_48 * V_34 = NULL ;
struct V_116 * V_28 ;
int V_127 ;
V_127 = F_128 ( V_24 -> V_29 ) ;
F_98 ( V_127 >= V_27 ) ;
V_28 = V_24 -> V_28 + V_127 ;
V_34 = F_164 ( V_28 -> V_34 , struct V_48 , V_58 ) ;
return V_34 ;
}
static struct V_47 * F_165 ( struct V_51 * V_51 )
{
struct V_48 * V_49 ;
struct V_47 * V_63 ;
struct V_22 * V_22 = & V_51 -> V_50 ;
do {
V_49 = F_163 ( V_51 , V_22 ) ;
F_98 ( ! V_49 ) ;
V_22 = F_74 ( V_49 ) ;
} while ( V_22 );
V_63 = F_23 ( V_49 ) ;
V_63 -> V_99 . V_100 = F_110 ( V_51 ) ;
return V_63 ;
}
static struct V_47 *
F_166 ( struct V_51 * V_51 , struct V_47 * V_64 , struct V_128 V_129 )
{
struct V_47 * V_63 ;
struct V_22 * V_22 = & V_51 -> V_50 ;
if ( F_41 ( V_51 , V_64 ) ) {
F_167 ( & V_51 -> V_95 , V_129 ) ;
V_74 ( V_51 ) ;
F_168 ( & V_51 -> V_95 , V_129 ) ;
if ( F_95 ( ( V_51 -> V_130 && F_169 ( V_51 -> V_130 ) ) ||
V_51 -> V_131 . V_132 ) )
return V_133 ;
}
if ( V_64 -> V_97 == & V_98 )
F_109 ( V_51 ) ;
if ( ! V_22 -> V_44 )
return NULL ;
F_170 ( V_51 , V_64 ) ;
V_63 = F_165 ( V_51 ) ;
F_65 ( V_51 , V_63 ) ;
F_57 ( V_51 ) ;
return V_63 ;
}
static void F_171 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
F_109 ( V_51 ) ;
if ( F_67 ( & V_63 -> V_50 ) && F_53 ( V_63 ) > 1 )
F_61 ( V_51 , V_63 ) ;
}
static int F_172 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_54 )
{
if ( ! F_173 ( V_51 , V_63 ) &&
F_174 ( V_54 , F_175 ( V_63 ) ) )
return 1 ;
return 0 ;
}
static struct V_47 * F_176 ( struct V_51 * V_51 , int V_54 )
{
struct V_134 * V_121 = & V_51 -> V_50 . V_37 ;
struct V_47 * V_63 ;
if ( ! F_55 ( V_51 ) )
return NULL ;
F_177 (p, head, pushable_tasks) {
if ( F_172 ( V_51 , V_63 , V_54 ) )
return V_63 ;
}
return NULL ;
}
static int F_157 ( struct V_47 * V_135 )
{
struct V_136 * V_137 ;
struct V_81 * V_138 = F_178 ( V_139 ) ;
int V_140 = F_111 () ;
int V_54 = F_179 ( V_135 ) ;
if ( F_95 ( ! V_138 ) )
return - 1 ;
if ( F_53 ( V_135 ) == 1 )
return - 1 ;
if ( ! F_160 ( & F_40 ( V_135 ) -> V_66 -> V_106 , V_135 , V_138 ) )
return - 1 ;
if ( F_174 ( V_54 , V_138 ) )
return V_54 ;
if ( ! F_174 ( V_140 , V_138 ) )
V_140 = - 1 ;
F_154 () ;
F_180 (cpu, sd) {
if ( V_137 -> V_112 & V_141 ) {
int V_142 ;
if ( V_140 != - 1 &&
F_174 ( V_140 , F_181 ( V_137 ) ) ) {
F_158 () ;
return V_140 ;
}
V_142 = F_182 ( V_138 ,
F_181 ( V_137 ) ) ;
if ( V_142 < V_40 ) {
F_158 () ;
return V_142 ;
}
}
}
F_158 () ;
if ( V_140 != - 1 )
return V_140 ;
V_54 = F_183 ( V_138 ) ;
if ( V_54 < V_40 )
return V_54 ;
return - 1 ;
}
static struct V_51 * F_184 ( struct V_47 * V_135 , struct V_51 * V_51 )
{
struct V_51 * V_143 = NULL ;
int V_144 ;
int V_54 ;
for ( V_144 = 0 ; V_144 < V_145 ; V_144 ++ ) {
V_54 = F_157 ( V_135 ) ;
if ( ( V_54 == - 1 ) || ( V_54 == V_51 -> V_54 ) )
break;
V_143 = F_34 ( V_54 ) ;
if ( V_143 -> V_50 . V_32 . V_33 <= V_135 -> V_65 ) {
V_143 = NULL ;
break;
}
if ( F_185 ( V_51 , V_143 ) ) {
if ( F_95 ( F_40 ( V_135 ) != V_51 ||
! F_174 ( V_143 -> V_54 ,
F_175 ( V_135 ) ) ||
F_173 ( V_51 , V_135 ) ||
! F_156 ( V_135 ) ||
! F_169 ( V_135 ) ) ) {
F_186 ( V_51 , V_143 ) ;
V_143 = NULL ;
break;
}
}
if ( V_143 -> V_50 . V_32 . V_33 > V_135 -> V_65 )
break;
F_186 ( V_51 , V_143 ) ;
V_143 = NULL ;
}
return V_143 ;
}
static struct V_47 * F_187 ( struct V_51 * V_51 )
{
struct V_47 * V_63 ;
if ( ! F_55 ( V_51 ) )
return NULL ;
V_63 = F_66 ( & V_51 -> V_50 . V_37 ,
struct V_47 , V_37 ) ;
F_98 ( V_51 -> V_54 != F_179 ( V_63 ) ) ;
F_98 ( F_146 ( V_51 , V_63 ) ) ;
F_98 ( F_53 ( V_63 ) <= 1 ) ;
F_98 ( ! F_169 ( V_63 ) ) ;
F_98 ( ! F_156 ( V_63 ) ) ;
return V_63 ;
}
static int F_188 ( struct V_51 * V_51 )
{
struct V_47 * V_146 ;
struct V_51 * V_143 ;
int V_147 = 0 ;
if ( ! V_51 -> V_50 . V_36 )
return 0 ;
V_146 = F_187 ( V_51 ) ;
if ( ! V_146 )
return 0 ;
V_148:
if ( F_95 ( V_146 == V_51 -> V_33 ) ) {
F_127 ( 1 ) ;
return 0 ;
}
if ( F_95 ( V_146 -> V_65 < V_51 -> V_33 -> V_65 ) ) {
F_79 ( V_51 ) ;
return 0 ;
}
F_189 ( V_146 ) ;
V_143 = F_184 ( V_146 , V_51 ) ;
if ( ! V_143 ) {
struct V_47 * V_135 ;
V_135 = F_187 ( V_51 ) ;
if ( F_179 ( V_146 ) == V_51 -> V_54 && V_135 == V_146 ) {
goto V_125;
}
if ( ! V_135 )
goto V_125;
F_190 ( V_146 ) ;
V_146 = V_135 ;
goto V_148;
}
F_191 ( V_51 , V_146 , 0 ) ;
F_192 ( V_146 , V_143 -> V_54 ) ;
F_193 ( V_143 , V_146 , 0 ) ;
V_147 = 1 ;
F_79 ( V_143 ) ;
F_186 ( V_51 , V_143 ) ;
V_125:
F_190 ( V_146 ) ;
return V_147 ;
}
static void V_72 ( struct V_51 * V_51 )
{
while ( F_188 ( V_51 ) )
;
}
static int F_194 ( struct V_51 * V_51 )
{
int V_149 = V_51 -> V_50 . V_39 ;
int V_54 ;
V_54 = F_195 ( V_149 , V_51 -> V_66 -> V_69 ) ;
if ( V_149 < V_51 -> V_54 ) {
if ( V_54 >= V_51 -> V_54 )
return V_40 ;
} else if ( V_54 >= V_40 ) {
V_54 = F_196 ( V_51 -> V_66 -> V_69 ) ;
if ( V_54 >= V_51 -> V_54 )
return V_40 ;
}
V_51 -> V_50 . V_39 = V_54 ;
return V_54 ;
}
static int F_197 ( struct V_51 * V_51 )
{
struct V_51 * V_150 ;
int V_54 ;
while ( 1 ) {
V_54 = F_194 ( V_51 ) ;
if ( V_54 >= V_40 )
break;
V_150 = F_34 ( V_54 ) ;
if ( V_150 -> V_50 . V_32 . V_34 < V_51 -> V_50 . V_32 . V_33 )
break;
}
return V_54 ;
}
static void F_198 ( struct V_51 * V_51 )
{
int V_54 ;
if ( V_51 -> V_50 . V_38 & V_151 ) {
F_3 ( & V_51 -> V_50 . V_41 ) ;
if ( V_51 -> V_50 . V_38 & V_151 ) {
V_51 -> V_50 . V_38 |= V_152 ;
F_5 ( & V_51 -> V_50 . V_41 ) ;
return;
}
F_5 ( & V_51 -> V_50 . V_41 ) ;
}
V_51 -> V_50 . V_39 = V_51 -> V_54 ;
V_54 = F_197 ( V_51 ) ;
if ( V_54 >= V_40 )
return;
V_51 -> V_50 . V_38 = V_151 ;
F_199 ( & V_51 -> V_50 . V_42 , V_54 ) ;
}
static void F_200 ( void * V_153 )
{
struct V_22 * V_22 = V_153 ;
struct V_51 * V_51 , * V_154 ;
int V_140 ;
int V_54 ;
V_140 = V_22 -> V_39 ;
F_98 ( V_140 != F_111 () ) ;
V_51 = F_34 ( V_140 ) ;
V_154 = F_27 ( V_22 ) ;
V_155:
if ( F_55 ( V_51 ) ) {
F_3 ( & V_51 -> V_95 ) ;
F_188 ( V_51 ) ;
F_5 ( & V_51 -> V_95 ) ;
}
F_3 ( & V_22 -> V_41 ) ;
if ( V_22 -> V_38 & V_152 ) {
V_22 -> V_38 &= ~ V_152 ;
V_22 -> V_39 = V_154 -> V_54 ;
}
V_54 = F_197 ( V_154 ) ;
if ( V_54 >= V_40 )
V_22 -> V_38 &= ~ V_151 ;
F_5 ( & V_22 -> V_41 ) ;
if ( V_54 >= V_40 )
return;
if ( F_95 ( V_54 == V_51 -> V_54 ) )
goto V_155;
F_199 ( & V_22 -> V_42 , V_54 ) ;
}
static void V_43 ( struct V_156 * V_157 )
{
struct V_22 * V_22 = F_2 ( V_157 , struct V_22 , V_42 ) ;
F_200 ( V_22 ) ;
}
static void V_74 ( struct V_51 * V_75 )
{
int V_140 = V_75 -> V_54 , V_54 ;
bool V_158 = false ;
struct V_47 * V_63 ;
struct V_51 * V_154 ;
if ( F_107 ( ! F_42 ( V_75 ) ) )
return;
F_201 () ;
#ifdef F_19
if ( F_101 ( V_159 ) ) {
F_198 ( V_75 ) ;
return;
}
#endif
F_92 (cpu, this_rq->rd->rto_mask) {
if ( V_140 == V_54 )
continue;
V_154 = F_34 ( V_54 ) ;
if ( V_154 -> V_50 . V_32 . V_34 >=
V_75 -> V_50 . V_32 . V_33 )
continue;
F_185 ( V_75 , V_154 ) ;
V_63 = F_176 ( V_154 , V_140 ) ;
if ( V_63 && ( V_63 -> V_65 < V_75 -> V_50 . V_32 . V_33 ) ) {
F_127 ( V_63 == V_154 -> V_33 ) ;
F_127 ( ! F_169 ( V_63 ) ) ;
if ( V_63 -> V_65 < V_154 -> V_33 -> V_65 )
goto V_160;
V_158 = true ;
F_191 ( V_154 , V_63 , 0 ) ;
F_192 ( V_63 , V_140 ) ;
F_193 ( V_75 , V_63 , 0 ) ;
}
V_160:
F_186 ( V_75 , V_154 ) ;
}
if ( V_158 )
F_79 ( V_75 ) ;
}
static void F_202 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( ! F_173 ( V_51 , V_63 ) &&
! F_162 ( V_51 -> V_33 ) &&
F_53 ( V_63 ) > 1 &&
( F_203 ( V_51 -> V_33 ) || F_156 ( V_51 -> V_33 ) ) &&
( F_53 ( V_51 -> V_33 ) < 2 ||
V_51 -> V_33 -> V_65 <= V_63 -> V_65 ) )
V_72 ( V_51 ) ;
}
static void F_204 ( struct V_51 * V_51 )
{
if ( V_51 -> V_50 . V_36 )
F_44 ( V_51 ) ;
F_99 ( V_51 ) ;
F_123 ( & V_51 -> V_66 -> V_106 , V_51 -> V_54 , V_51 -> V_50 . V_32 . V_33 ) ;
}
static void F_205 ( struct V_51 * V_51 )
{
if ( V_51 -> V_50 . V_36 )
F_48 ( V_51 ) ;
F_94 ( V_51 ) ;
F_123 ( & V_51 -> V_66 -> V_106 , V_51 -> V_54 , V_161 ) ;
}
static void F_206 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( ! F_169 ( V_63 ) || V_51 -> V_50 . V_79 )
return;
F_60 ( V_51 ) ;
}
void T_4 F_207 ( void )
{
unsigned int V_25 ;
F_31 (i) {
F_208 ( & F_59 ( V_139 , V_25 ) ,
V_59 , F_39 ( V_25 ) ) ;
}
}
static void F_209 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( F_169 ( V_63 ) && V_51 -> V_33 != V_63 ) {
#ifdef V_31
if ( F_53 ( V_63 ) > 1 && V_51 -> V_50 . V_36 )
F_57 ( V_51 ) ;
#else
if ( V_63 -> V_65 < V_51 -> V_33 -> V_65 )
F_79 ( V_51 ) ;
#endif
}
}
static void
F_210 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_162 )
{
if ( ! F_169 ( V_63 ) )
return;
if ( V_51 -> V_33 == V_63 ) {
#ifdef V_31
if ( V_162 < V_63 -> V_65 )
F_60 ( V_51 ) ;
if ( V_63 -> V_65 > V_51 -> V_50 . V_32 . V_33 )
F_79 ( V_51 ) ;
#else
if ( V_162 < V_63 -> V_65 )
F_79 ( V_51 ) ;
#endif
} else {
if ( V_63 -> V_65 < V_51 -> V_33 -> V_65 )
F_79 ( V_51 ) ;
}
}
static void F_211 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
unsigned long V_163 , V_164 ;
V_163 = F_212 ( V_63 , V_165 ) ;
V_164 = F_213 ( V_63 , V_165 ) ;
if ( V_163 != V_166 ) {
unsigned long V_34 ;
if ( V_63 -> V_50 . V_167 != V_168 ) {
V_63 -> V_50 . V_120 ++ ;
V_63 -> V_50 . V_167 = V_168 ;
}
V_34 = F_214 ( F_103 ( V_163 , V_164 ) , V_169 / V_170 ) ;
if ( V_63 -> V_50 . V_120 > V_34 )
V_63 -> V_171 . V_172 = V_63 -> V_99 . V_103 ;
}
}
static void F_215 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_173 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
F_109 ( V_51 ) ;
F_211 ( V_51 , V_63 ) ;
if ( V_63 -> V_110 != V_111 )
return;
if ( -- V_63 -> V_50 . V_174 )
return;
V_63 -> V_50 . V_174 = V_175 ;
F_119 (rt_se) {
if ( V_49 -> V_58 . V_64 != V_49 -> V_58 . V_34 ) {
F_151 ( V_51 , V_63 , 0 ) ;
F_79 ( V_51 ) ;
return;
}
}
}
static void F_216 ( struct V_51 * V_51 )
{
struct V_47 * V_63 = V_51 -> V_33 ;
V_63 -> V_99 . V_100 = F_110 ( V_51 ) ;
F_65 ( V_51 , V_63 ) ;
}
static unsigned int F_217 ( struct V_51 * V_51 , struct V_47 * V_135 )
{
if ( V_135 -> V_110 == V_111 )
return V_175 ;
else
return 0 ;
}
void F_218 ( struct V_176 * V_177 , int V_54 )
{
T_3 V_86 ;
struct V_22 * V_22 ;
F_154 () ;
F_96 (rt_rq, iter, cpu_rq(cpu))
F_219 ( V_177 , V_54 , V_22 ) ;
F_158 () ;
}
