static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
T_1 V_7 ;
int V_8 ;
int V_9 = 0 ;
for (; ; ) {
V_7 = F_3 ( V_3 ) ;
V_8 = F_4 ( V_3 , V_7 , V_5 -> V_10 ) ;
if ( ! V_8 )
break;
V_9 = F_5 ( V_5 , V_8 ) ;
}
return V_9 ? V_11 : V_12 ;
}
void F_6 ( struct V_4 * V_5 , T_2 V_13 , T_2 V_14 )
{
V_5 -> V_10 = F_7 ( V_13 ) ;
V_5 -> V_15 = V_14 ;
F_8 ( & V_5 -> V_16 ) ;
F_9 ( & V_5 -> V_6 ,
V_17 , V_18 ) ;
V_5 -> V_6 . V_19 = F_1 ;
}
static void F_10 ( struct V_4 * V_5 )
{
if ( ! F_11 () || V_5 -> V_15 == V_20 )
return;
if ( F_12 ( & V_5 -> V_6 ) )
return;
F_13 ( & V_5 -> V_16 ) ;
F_14 ( & V_5 -> V_6 , V_5 -> V_10 ) ;
F_15 ( & V_5 -> V_16 ) ;
}
void F_16 ( struct V_21 * V_21 )
{
struct V_22 * V_23 ;
int V_24 ;
V_23 = & V_21 -> V_25 ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
F_17 ( V_23 -> V_27 + V_24 ) ;
F_18 ( V_24 , V_23 -> V_28 ) ;
}
F_19 ( V_26 , V_23 -> V_28 ) ;
#if V_29 V_30
V_21 -> V_31 . V_32 = V_26 ;
V_21 -> V_31 . V_33 = V_26 ;
V_21 -> V_34 = 0 ;
V_21 -> V_35 = 0 ;
F_20 ( & V_21 -> V_36 ) ;
#ifdef F_21
V_21 -> V_37 = 0 ;
V_21 -> V_38 = V_39 ;
F_8 ( & V_21 -> V_40 ) ;
F_22 ( & V_21 -> V_41 , V_42 ) ;
#endif
#endif
V_21 -> V_43 = 0 ;
V_21 -> V_44 = 0 ;
V_21 -> V_45 = 0 ;
V_21 -> V_15 = 0 ;
F_8 ( & V_21 -> V_16 ) ;
}
static void F_23 ( struct V_4 * V_5 )
{
F_24 ( & V_5 -> V_6 ) ;
}
static inline struct V_46 * F_25 ( struct V_47 * V_48 )
{
#ifdef F_26
F_27 ( ! F_28 ( V_48 ) ) ;
#endif
return F_2 ( V_48 , struct V_46 , V_49 ) ;
}
static inline struct V_50 * F_29 ( struct V_21 * V_21 )
{
return V_21 -> V_50 ;
}
static inline struct V_21 * F_30 ( struct V_47 * V_48 )
{
return V_48 -> V_21 ;
}
static inline struct V_50 * F_31 ( struct V_47 * V_48 )
{
struct V_21 * V_21 = V_48 -> V_21 ;
return V_21 -> V_50 ;
}
void F_32 ( struct V_51 * V_52 )
{
int V_24 ;
if ( V_52 -> V_48 )
F_23 ( & V_52 -> V_4 ) ;
F_33 (i) {
if ( V_52 -> V_21 )
F_34 ( V_52 -> V_21 [ V_24 ] ) ;
if ( V_52 -> V_48 )
F_34 ( V_52 -> V_48 [ V_24 ] ) ;
}
F_34 ( V_52 -> V_21 ) ;
F_34 ( V_52 -> V_48 ) ;
}
void F_35 ( struct V_51 * V_52 , struct V_21 * V_21 ,
struct V_47 * V_48 , int V_53 ,
struct V_47 * V_54 )
{
struct V_50 * V_50 = F_36 ( V_53 ) ;
V_21 -> V_31 . V_32 = V_26 ;
V_21 -> V_55 = 0 ;
V_21 -> V_50 = V_50 ;
V_21 -> V_52 = V_52 ;
V_52 -> V_21 [ V_53 ] = V_21 ;
V_52 -> V_48 [ V_53 ] = V_48 ;
if ( ! V_48 )
return;
if ( ! V_54 )
V_48 -> V_21 = & V_50 -> V_49 ;
else
V_48 -> V_21 = V_54 -> V_56 ;
V_48 -> V_56 = V_21 ;
V_48 -> V_54 = V_54 ;
F_17 ( & V_48 -> V_57 ) ;
}
int F_37 ( struct V_51 * V_52 , struct V_51 * V_54 )
{
struct V_21 * V_21 ;
struct V_47 * V_48 ;
int V_24 ;
V_52 -> V_21 = F_38 ( sizeof( V_21 ) * V_39 , V_58 ) ;
if ( ! V_52 -> V_21 )
goto V_59;
V_52 -> V_48 = F_38 ( sizeof( V_48 ) * V_39 , V_58 ) ;
if ( ! V_52 -> V_48 )
goto V_59;
F_6 ( & V_52 -> V_4 ,
F_39 ( V_60 . V_10 ) , 0 ) ;
F_33 (i) {
V_21 = F_40 ( sizeof( struct V_21 ) ,
V_58 , F_41 ( V_24 ) ) ;
if ( ! V_21 )
goto V_59;
V_48 = F_40 ( sizeof( struct V_47 ) ,
V_58 , F_41 ( V_24 ) ) ;
if ( ! V_48 )
goto V_61;
F_16 ( V_21 ) ;
V_21 -> V_15 = V_52 -> V_4 . V_15 ;
F_35 ( V_52 , V_21 , V_48 , V_24 , V_54 -> V_48 [ V_24 ] ) ;
}
return 1 ;
V_61:
F_34 ( V_21 ) ;
V_59:
return 0 ;
}
static inline struct V_46 * F_25 ( struct V_47 * V_48 )
{
return F_2 ( V_48 , struct V_46 , V_49 ) ;
}
static inline struct V_50 * F_29 ( struct V_21 * V_21 )
{
return F_2 ( V_21 , struct V_50 , V_49 ) ;
}
static inline struct V_50 * F_31 ( struct V_47 * V_48 )
{
struct V_46 * V_62 = F_25 ( V_48 ) ;
return F_42 ( V_62 ) ;
}
static inline struct V_21 * F_30 ( struct V_47 * V_48 )
{
struct V_50 * V_50 = F_31 ( V_48 ) ;
return & V_50 -> V_49 ;
}
void F_32 ( struct V_51 * V_52 ) { }
int F_37 ( struct V_51 * V_52 , struct V_51 * V_54 )
{
return 1 ;
}
static inline bool F_43 ( struct V_50 * V_50 , struct V_46 * V_63 )
{
return V_50 -> V_49 . V_31 . V_32 > V_63 -> V_64 ;
}
static inline int F_44 ( struct V_50 * V_50 )
{
return F_45 ( & V_50 -> V_65 -> V_66 ) ;
}
static inline void F_46 ( struct V_50 * V_50 )
{
if ( ! V_50 -> V_67 )
return;
F_47 ( V_50 -> V_53 , V_50 -> V_65 -> V_68 ) ;
F_48 () ;
F_49 ( & V_50 -> V_65 -> V_66 ) ;
}
static inline void F_50 ( struct V_50 * V_50 )
{
if ( ! V_50 -> V_67 )
return;
F_51 ( & V_50 -> V_65 -> V_66 ) ;
F_52 ( V_50 -> V_53 , V_50 -> V_65 -> V_68 ) ;
}
static void F_53 ( struct V_21 * V_21 )
{
if ( V_21 -> V_34 && V_21 -> V_69 > 1 ) {
if ( ! V_21 -> V_35 ) {
F_46 ( F_29 ( V_21 ) ) ;
V_21 -> V_35 = 1 ;
}
} else if ( V_21 -> V_35 ) {
F_50 ( F_29 ( V_21 ) ) ;
V_21 -> V_35 = 0 ;
}
}
static void F_54 ( struct V_47 * V_48 , struct V_21 * V_21 )
{
struct V_46 * V_62 ;
if ( ! F_28 ( V_48 ) )
return;
V_62 = F_25 ( V_48 ) ;
V_21 = & F_29 ( V_21 ) -> V_49 ;
V_21 -> V_69 ++ ;
if ( V_62 -> V_70 > 1 )
V_21 -> V_34 ++ ;
F_53 ( V_21 ) ;
}
static void F_55 ( struct V_47 * V_48 , struct V_21 * V_21 )
{
struct V_46 * V_62 ;
if ( ! F_28 ( V_48 ) )
return;
V_62 = F_25 ( V_48 ) ;
V_21 = & F_29 ( V_21 ) -> V_49 ;
V_21 -> V_69 -- ;
if ( V_62 -> V_70 > 1 )
V_21 -> V_34 -- ;
F_53 ( V_21 ) ;
}
static inline int F_56 ( struct V_50 * V_50 )
{
return ! F_57 ( & V_50 -> V_49 . V_36 ) ;
}
static inline void F_58 ( struct V_50 * V_50 )
{
V_50 -> V_71 = F_56 ( V_50 ) ;
}
static void F_59 ( struct V_50 * V_50 , struct V_46 * V_62 )
{
F_60 ( & V_62 -> V_36 , & V_50 -> V_49 . V_36 ) ;
F_61 ( & V_62 -> V_36 , V_62 -> V_64 ) ;
F_62 ( & V_62 -> V_36 , & V_50 -> V_49 . V_36 ) ;
if ( V_62 -> V_64 < V_50 -> V_49 . V_31 . V_33 )
V_50 -> V_49 . V_31 . V_33 = V_62 -> V_64 ;
}
static void F_63 ( struct V_50 * V_50 , struct V_46 * V_62 )
{
F_60 ( & V_62 -> V_36 , & V_50 -> V_49 . V_36 ) ;
if ( F_56 ( V_50 ) ) {
V_62 = F_64 ( & V_50 -> V_49 . V_36 ,
struct V_46 , V_36 ) ;
V_50 -> V_49 . V_31 . V_33 = V_62 -> V_64 ;
} else
V_50 -> V_49 . V_31 . V_33 = V_26 ;
}
static inline void F_59 ( struct V_50 * V_50 , struct V_46 * V_62 )
{
}
static inline void F_63 ( struct V_50 * V_50 , struct V_46 * V_62 )
{
}
static inline
void F_54 ( struct V_47 * V_48 , struct V_21 * V_21 )
{
}
static inline
void F_55 ( struct V_47 * V_48 , struct V_21 * V_21 )
{
}
static inline bool F_43 ( struct V_50 * V_50 , struct V_46 * V_63 )
{
return false ;
}
static inline int F_65 ( struct V_50 * V_72 )
{
return 0 ;
}
static inline void F_58 ( struct V_50 * V_50 )
{
}
static inline int F_66 ( struct V_47 * V_48 )
{
return ! F_67 ( & V_48 -> V_57 ) ;
}
static inline T_2 F_68 ( struct V_21 * V_21 )
{
if ( ! V_21 -> V_52 )
return V_20 ;
return V_21 -> V_15 ;
}
static inline T_2 F_69 ( struct V_21 * V_21 )
{
return F_39 ( V_21 -> V_52 -> V_4 . V_10 ) ;
}
static inline struct V_51 * F_70 ( struct V_51 * V_52 )
{
do {
V_52 = F_71 ( V_52 -> V_73 . V_33 ,
F_72 ( struct V_51 ) , V_73 ) ;
} while ( & V_52 -> V_73 != & V_74 && F_73 ( V_52 ) );
if ( & V_52 -> V_73 == & V_74 )
V_52 = NULL ;
return V_52 ;
}
static inline struct V_21 * F_74 ( struct V_47 * V_48 )
{
return V_48 -> V_56 ;
}
static void F_75 ( struct V_21 * V_21 )
{
struct V_46 * V_32 = F_29 ( V_21 ) -> V_32 ;
struct V_50 * V_50 = F_29 ( V_21 ) ;
struct V_47 * V_48 ;
int V_53 = F_76 ( V_50 ) ;
V_48 = V_21 -> V_52 -> V_48 [ V_53 ] ;
if ( V_21 -> V_75 ) {
if ( ! V_48 )
F_77 ( V_21 ) ;
else if ( ! F_66 ( V_48 ) )
F_78 ( V_48 , false ) ;
if ( V_21 -> V_31 . V_32 < V_32 -> V_64 )
F_79 ( V_50 ) ;
}
}
static void F_80 ( struct V_21 * V_21 )
{
struct V_47 * V_48 ;
int V_53 = F_76 ( F_29 ( V_21 ) ) ;
V_48 = V_21 -> V_52 -> V_48 [ V_53 ] ;
if ( ! V_48 )
F_81 ( V_21 ) ;
else if ( F_66 ( V_48 ) )
F_82 ( V_48 ) ;
}
static inline int F_83 ( struct V_21 * V_21 )
{
return V_21 -> V_45 && ! V_21 -> V_55 ;
}
static int F_84 ( struct V_47 * V_48 )
{
struct V_21 * V_21 = F_74 ( V_48 ) ;
struct V_46 * V_62 ;
if ( V_21 )
return ! ! V_21 -> V_55 ;
V_62 = F_25 ( V_48 ) ;
return V_62 -> V_64 != V_62 -> V_76 ;
}
static inline const struct V_77 * F_85 ( void )
{
return V_72 () -> V_65 -> V_78 ;
}
static inline const struct V_77 * F_85 ( void )
{
return V_79 ;
}
static inline
struct V_21 * F_86 ( struct V_4 * V_5 , int V_53 )
{
return F_2 ( V_5 , struct V_51 , V_4 ) -> V_21 [ V_53 ] ;
}
static inline struct V_4 * F_87 ( struct V_21 * V_21 )
{
return & V_21 -> V_52 -> V_4 ;
}
static inline T_2 F_68 ( struct V_21 * V_21 )
{
return V_21 -> V_15 ;
}
static inline T_2 F_69 ( struct V_21 * V_21 )
{
return F_39 ( V_60 . V_10 ) ;
}
static inline struct V_21 * F_74 ( struct V_47 * V_48 )
{
return NULL ;
}
static inline void F_75 ( struct V_21 * V_21 )
{
struct V_50 * V_50 = F_29 ( V_21 ) ;
if ( ! V_21 -> V_75 )
return;
F_77 ( V_21 ) ;
F_79 ( V_50 ) ;
}
static inline void F_80 ( struct V_21 * V_21 )
{
F_81 ( V_21 ) ;
}
static inline int F_83 ( struct V_21 * V_21 )
{
return V_21 -> V_45 ;
}
static inline const struct V_77 * F_85 ( void )
{
return V_79 ;
}
static inline
struct V_21 * F_86 ( struct V_4 * V_5 , int V_53 )
{
return & F_36 ( V_53 ) -> V_49 ;
}
static inline struct V_4 * F_87 ( struct V_21 * V_21 )
{
return & V_60 ;
}
bool F_88 ( struct V_21 * V_21 )
{
struct V_4 * V_5 = F_87 ( V_21 ) ;
return ( F_12 ( & V_5 -> V_6 ) ||
V_21 -> V_44 < V_5 -> V_15 ) ;
}
static int F_89 ( struct V_21 * V_21 )
{
struct V_4 * V_5 = F_87 ( V_21 ) ;
struct V_80 * V_65 = F_29 ( V_21 ) -> V_65 ;
int V_24 , V_81 , V_82 = 0 ;
T_2 V_10 ;
V_81 = F_90 ( V_65 -> V_78 ) ;
F_13 ( & V_5 -> V_16 ) ;
V_10 = F_39 ( V_5 -> V_10 ) ;
F_91 (i, rd->span) {
struct V_21 * V_83 = F_86 ( V_5 , V_24 ) ;
T_3 V_84 ;
if ( V_83 == V_21 )
continue;
F_13 ( & V_83 -> V_16 ) ;
if ( V_83 -> V_15 == V_20 )
goto V_33;
V_84 = V_83 -> V_15 - V_83 -> V_44 ;
if ( V_84 > 0 ) {
V_84 = F_92 ( ( T_2 ) V_84 , V_81 ) ;
if ( V_21 -> V_15 + V_84 > V_10 )
V_84 = V_10 - V_21 -> V_15 ;
V_83 -> V_15 -= V_84 ;
V_21 -> V_15 += V_84 ;
V_82 = 1 ;
if ( V_21 -> V_15 == V_10 ) {
F_15 ( & V_83 -> V_16 ) ;
break;
}
}
V_33:
F_15 ( & V_83 -> V_16 ) ;
}
F_15 ( & V_5 -> V_16 ) ;
return V_82 ;
}
static void F_93 ( struct V_50 * V_50 )
{
struct V_80 * V_65 = V_50 -> V_65 ;
T_4 V_83 ;
struct V_21 * V_21 ;
if ( F_94 ( ! V_85 ) )
return;
F_95 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_87 ( V_21 ) ;
T_3 V_86 ;
int V_24 ;
F_13 ( & V_5 -> V_16 ) ;
F_13 ( & V_21 -> V_16 ) ;
if ( V_21 -> V_15 == V_20 ||
V_21 -> V_15 == V_5 -> V_15 )
goto V_87;
F_15 ( & V_21 -> V_16 ) ;
V_86 = V_5 -> V_15 - V_21 -> V_15 ;
F_91 (i, rd->span) {
struct V_21 * V_83 = F_86 ( V_5 , V_24 ) ;
T_3 V_84 ;
if ( V_83 == V_21 || V_83 -> V_15 == V_20 )
continue;
F_13 ( & V_83 -> V_16 ) ;
if ( V_86 > 0 ) {
V_84 = F_96 ( T_3 , V_83 -> V_15 , V_86 ) ;
V_83 -> V_15 -= V_84 ;
V_86 -= V_84 ;
} else {
V_83 -> V_15 -= V_86 ;
V_86 -= V_86 ;
}
F_15 ( & V_83 -> V_16 ) ;
if ( ! V_86 )
break;
}
F_13 ( & V_21 -> V_16 ) ;
F_97 ( V_86 ) ;
V_87:
V_21 -> V_15 = V_20 ;
V_21 -> V_45 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
F_15 ( & V_5 -> V_16 ) ;
F_75 ( V_21 ) ;
}
}
static void F_98 ( struct V_50 * V_50 )
{
T_4 V_83 ;
struct V_21 * V_21 ;
if ( F_94 ( ! V_85 ) )
return;
F_95 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_87 ( V_21 ) ;
F_13 ( & V_5 -> V_16 ) ;
F_13 ( & V_21 -> V_16 ) ;
V_21 -> V_15 = V_5 -> V_15 ;
V_21 -> V_44 = 0 ;
V_21 -> V_45 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
F_15 ( & V_5 -> V_16 ) ;
}
}
static int F_99 ( struct V_21 * V_21 )
{
int V_82 = 0 ;
if ( ! F_100 ( V_88 ) )
return V_82 ;
if ( V_21 -> V_44 > V_21 -> V_15 ) {
F_15 ( & V_21 -> V_16 ) ;
V_82 = F_89 ( V_21 ) ;
F_13 ( & V_21 -> V_16 ) ;
}
return V_82 ;
}
static inline int F_99 ( struct V_21 * V_21 )
{
return 0 ;
}
static int F_5 ( struct V_4 * V_5 , int V_8 )
{
int V_24 , V_9 = 1 , V_89 = 0 ;
const struct V_77 * V_78 ;
V_78 = F_85 () ;
#ifdef F_101
if ( V_5 == & V_90 . V_4 )
V_78 = V_79 ;
#endif
F_91 (i, span) {
int V_91 = 0 ;
struct V_21 * V_21 = F_86 ( V_5 , V_24 ) ;
struct V_50 * V_50 = F_29 ( V_21 ) ;
F_13 ( & V_50 -> V_92 ) ;
if ( V_21 -> V_44 ) {
T_2 V_14 ;
F_13 ( & V_21 -> V_16 ) ;
if ( V_21 -> V_45 )
F_99 ( V_21 ) ;
V_14 = V_21 -> V_15 ;
V_21 -> V_44 -= F_102 ( V_21 -> V_44 , V_8 * V_14 ) ;
if ( V_21 -> V_45 && V_21 -> V_44 < V_14 ) {
V_21 -> V_45 = 0 ;
V_91 = 1 ;
if ( V_21 -> V_75 && V_50 -> V_32 == V_50 -> V_9 )
F_103 ( V_50 , false ) ;
}
if ( V_21 -> V_44 || V_21 -> V_75 )
V_9 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
} else if ( V_21 -> V_75 ) {
V_9 = 0 ;
if ( ! F_83 ( V_21 ) )
V_91 = 1 ;
}
if ( V_21 -> V_45 )
V_89 = 1 ;
if ( V_91 )
F_75 ( V_21 ) ;
F_15 ( & V_50 -> V_92 ) ;
}
if ( ! V_89 && ( ! F_11 () || V_5 -> V_15 == V_20 ) )
return 1 ;
return V_9 ;
}
static inline int F_104 ( struct V_47 * V_48 )
{
#ifdef F_101
struct V_21 * V_21 = F_74 ( V_48 ) ;
if ( V_21 )
return V_21 -> V_31 . V_32 ;
#endif
return F_25 ( V_48 ) -> V_64 ;
}
static int F_105 ( struct V_21 * V_21 )
{
T_2 V_14 = F_68 ( V_21 ) ;
if ( V_21 -> V_45 )
return F_83 ( V_21 ) ;
if ( V_14 >= F_69 ( V_21 ) )
return 0 ;
F_99 ( V_21 ) ;
V_14 = F_68 ( V_21 ) ;
if ( V_14 == V_20 )
return 0 ;
if ( V_21 -> V_44 > V_14 ) {
struct V_4 * V_5 = F_87 ( V_21 ) ;
if ( F_106 ( V_5 -> V_15 ) ) {
V_21 -> V_45 = 1 ;
F_107 ( L_1 ) ;
} else {
V_21 -> V_44 = 0 ;
}
if ( F_83 ( V_21 ) ) {
F_80 ( V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_108 ( struct V_50 * V_50 )
{
struct V_46 * V_32 = V_50 -> V_32 ;
struct V_47 * V_48 = & V_32 -> V_49 ;
T_2 V_93 ;
if ( V_32 -> V_94 != & V_95 )
return;
V_93 = F_109 ( V_50 ) - V_32 -> V_96 . V_97 ;
if ( F_94 ( ( T_3 ) V_93 <= 0 ) )
return;
F_110 ( V_32 -> V_96 . V_98 . V_99 ,
F_111 ( V_32 -> V_96 . V_98 . V_99 , V_93 ) ) ;
V_32 -> V_96 . V_100 += V_93 ;
F_112 ( V_32 , V_93 ) ;
V_32 -> V_96 . V_97 = F_109 ( V_50 ) ;
F_113 ( V_32 , V_93 ) ;
F_114 ( V_50 , V_93 ) ;
if ( ! F_11 () )
return;
F_115 (rt_se) {
struct V_21 * V_21 = F_30 ( V_48 ) ;
if ( F_68 ( V_21 ) != V_20 ) {
F_13 ( & V_21 -> V_16 ) ;
V_21 -> V_44 += V_93 ;
if ( F_105 ( V_21 ) )
F_79 ( V_50 ) ;
F_15 ( & V_21 -> V_16 ) ;
}
}
}
static void
F_81 ( struct V_21 * V_21 )
{
struct V_50 * V_50 = F_29 ( V_21 ) ;
F_97 ( & V_50 -> V_49 != V_21 ) ;
if ( ! V_21 -> V_43 )
return;
F_97 ( ! V_50 -> V_101 ) ;
F_116 ( V_50 , V_21 -> V_75 ) ;
V_21 -> V_43 = 0 ;
}
static void
F_77 ( struct V_21 * V_21 )
{
struct V_50 * V_50 = F_29 ( V_21 ) ;
F_97 ( & V_50 -> V_49 != V_21 ) ;
if ( V_21 -> V_43 )
return;
if ( F_83 ( V_21 ) || ! V_21 -> V_75 )
return;
F_117 ( V_50 , V_21 -> V_75 ) ;
V_21 -> V_43 = 1 ;
}
static void
F_118 ( struct V_21 * V_21 , int V_64 , int V_102 )
{
struct V_50 * V_50 = F_29 ( V_21 ) ;
#ifdef F_101
if ( & V_50 -> V_49 != V_21 )
return;
#endif
if ( V_50 -> V_67 && V_64 < V_102 )
F_119 ( & V_50 -> V_65 -> V_103 , V_50 -> V_53 , V_64 ) ;
}
static void
F_120 ( struct V_21 * V_21 , int V_64 , int V_102 )
{
struct V_50 * V_50 = F_29 ( V_21 ) ;
#ifdef F_101
if ( & V_50 -> V_49 != V_21 )
return;
#endif
if ( V_50 -> V_67 && V_21 -> V_31 . V_32 != V_102 )
F_119 ( & V_50 -> V_65 -> V_103 , V_50 -> V_53 , V_21 -> V_31 . V_32 ) ;
}
static inline
void F_118 ( struct V_21 * V_21 , int V_64 , int V_102 ) {}
static inline
void F_120 ( struct V_21 * V_21 , int V_64 , int V_102 ) {}
static void
F_121 ( struct V_21 * V_21 , int V_64 )
{
int V_102 = V_21 -> V_31 . V_32 ;
if ( V_64 < V_102 )
V_21 -> V_31 . V_32 = V_64 ;
F_118 ( V_21 , V_64 , V_102 ) ;
}
static void
F_122 ( struct V_21 * V_21 , int V_64 )
{
int V_102 = V_21 -> V_31 . V_32 ;
if ( V_21 -> V_75 ) {
F_123 ( V_64 < V_102 ) ;
if ( V_64 == V_102 ) {
struct V_22 * V_23 = & V_21 -> V_25 ;
V_21 -> V_31 . V_32 =
F_124 ( V_23 -> V_28 ) ;
}
} else
V_21 -> V_31 . V_32 = V_26 ;
F_120 ( V_21 , V_64 , V_102 ) ;
}
static inline void F_121 ( struct V_21 * V_21 , int V_64 ) {}
static inline void F_122 ( struct V_21 * V_21 , int V_64 ) {}
static void
F_125 ( struct V_47 * V_48 , struct V_21 * V_21 )
{
if ( F_84 ( V_48 ) )
V_21 -> V_55 ++ ;
if ( V_21 -> V_52 )
F_10 ( & V_21 -> V_52 -> V_4 ) ;
}
static void
F_126 ( struct V_47 * V_48 , struct V_21 * V_21 )
{
if ( F_84 ( V_48 ) )
V_21 -> V_55 -- ;
F_123 ( ! V_21 -> V_75 && V_21 -> V_55 ) ;
}
static void
F_125 ( struct V_47 * V_48 , struct V_21 * V_21 )
{
F_10 ( & V_60 ) ;
}
static inline
void F_126 ( struct V_47 * V_48 , struct V_21 * V_21 ) {}
static inline
unsigned int F_127 ( struct V_47 * V_48 )
{
struct V_21 * V_104 = F_74 ( V_48 ) ;
if ( V_104 )
return V_104 -> V_75 ;
else
return 1 ;
}
static inline
void F_128 ( struct V_47 * V_48 , struct V_21 * V_21 )
{
int V_64 = F_104 ( V_48 ) ;
F_123 ( ! F_129 ( V_64 ) ) ;
V_21 -> V_75 += F_127 ( V_48 ) ;
F_121 ( V_21 , V_64 ) ;
F_54 ( V_48 , V_21 ) ;
F_125 ( V_48 , V_21 ) ;
}
static inline
void F_130 ( struct V_47 * V_48 , struct V_21 * V_21 )
{
F_123 ( ! F_129 ( F_104 ( V_48 ) ) ) ;
F_123 ( ! V_21 -> V_75 ) ;
V_21 -> V_75 -= F_127 ( V_48 ) ;
F_122 ( V_21 , F_104 ( V_48 ) ) ;
F_55 ( V_48 , V_21 ) ;
F_126 ( V_48 , V_21 ) ;
}
static void F_131 ( struct V_47 * V_48 , bool V_105 )
{
struct V_21 * V_21 = F_30 ( V_48 ) ;
struct V_22 * V_23 = & V_21 -> V_25 ;
struct V_21 * V_104 = F_74 ( V_48 ) ;
struct V_106 * V_27 = V_23 -> V_27 + F_104 ( V_48 ) ;
if ( V_104 && ( F_83 ( V_104 ) || ! V_104 -> V_75 ) )
return;
if ( V_105 )
F_132 ( & V_48 -> V_57 , V_27 ) ;
else
F_133 ( & V_48 -> V_57 , V_27 ) ;
F_19 ( F_104 ( V_48 ) , V_23 -> V_28 ) ;
F_128 ( V_48 , V_21 ) ;
}
static void F_134 ( struct V_47 * V_48 )
{
struct V_21 * V_21 = F_30 ( V_48 ) ;
struct V_22 * V_23 = & V_21 -> V_25 ;
F_135 ( & V_48 -> V_57 ) ;
if ( F_67 ( V_23 -> V_27 + F_104 ( V_48 ) ) )
F_18 ( F_104 ( V_48 ) , V_23 -> V_28 ) ;
F_130 ( V_48 , V_21 ) ;
}
static void F_136 ( struct V_47 * V_48 )
{
struct V_47 * V_107 = NULL ;
F_115 (rt_se) {
V_48 -> V_107 = V_107 ;
V_107 = V_48 ;
}
F_81 ( F_30 ( V_107 ) ) ;
for ( V_48 = V_107 ; V_48 ; V_48 = V_48 -> V_107 ) {
if ( F_66 ( V_48 ) )
F_134 ( V_48 ) ;
}
}
static void F_78 ( struct V_47 * V_48 , bool V_105 )
{
struct V_50 * V_50 = F_31 ( V_48 ) ;
F_136 ( V_48 ) ;
F_115 (rt_se)
F_131 ( V_48 , V_105 ) ;
F_77 ( & V_50 -> V_49 ) ;
}
static void F_82 ( struct V_47 * V_48 )
{
struct V_50 * V_50 = F_31 ( V_48 ) ;
F_136 ( V_48 ) ;
F_115 (rt_se) {
struct V_21 * V_21 = F_74 ( V_48 ) ;
if ( V_21 && V_21 -> V_75 )
F_131 ( V_48 , false ) ;
}
F_77 ( & V_50 -> V_49 ) ;
}
static void
F_137 ( struct V_50 * V_50 , struct V_46 * V_62 , int V_108 )
{
struct V_47 * V_48 = & V_62 -> V_49 ;
if ( V_108 & V_109 )
V_48 -> V_110 = 0 ;
F_78 ( V_48 , V_108 & V_111 ) ;
if ( ! F_138 ( V_50 , V_62 ) && V_62 -> V_70 > 1 )
F_59 ( V_50 , V_62 ) ;
}
static void F_139 ( struct V_50 * V_50 , struct V_46 * V_62 , int V_108 )
{
struct V_47 * V_48 = & V_62 -> V_49 ;
F_108 ( V_50 ) ;
F_82 ( V_48 ) ;
F_63 ( V_50 , V_62 ) ;
}
static void
F_140 ( struct V_21 * V_21 , struct V_47 * V_48 , int V_105 )
{
if ( F_66 ( V_48 ) ) {
struct V_22 * V_23 = & V_21 -> V_25 ;
struct V_106 * V_27 = V_23 -> V_27 + F_104 ( V_48 ) ;
if ( V_105 )
F_141 ( & V_48 -> V_57 , V_27 ) ;
else
F_142 ( & V_48 -> V_57 , V_27 ) ;
}
}
static void F_143 ( struct V_50 * V_50 , struct V_46 * V_62 , int V_105 )
{
struct V_47 * V_48 = & V_62 -> V_49 ;
struct V_21 * V_21 ;
F_115 (rt_se) {
V_21 = F_30 ( V_48 ) ;
F_140 ( V_21 , V_48 , V_105 ) ;
}
}
static void F_144 ( struct V_50 * V_50 )
{
F_143 ( V_50 , V_50 -> V_32 , 0 ) ;
}
static int
F_145 ( struct V_46 * V_62 , int V_53 , int V_112 , int V_108 )
{
struct V_46 * V_32 ;
struct V_50 * V_50 ;
if ( V_112 != V_113 && V_112 != V_114 )
goto V_115;
V_50 = F_36 ( V_53 ) ;
F_146 () ;
V_32 = F_147 ( V_50 -> V_32 ) ;
if ( V_32 && F_94 ( F_148 ( V_32 ) ) &&
( V_32 -> V_70 < 2 ||
V_32 -> V_64 <= V_62 -> V_64 ) ) {
int V_116 = F_149 ( V_62 ) ;
if ( V_116 != - 1 &&
V_62 -> V_64 < F_36 ( V_116 ) -> V_49 . V_31 . V_32 )
V_53 = V_116 ;
}
F_150 () ;
V_115:
return V_53 ;
}
static void F_151 ( struct V_50 * V_50 , struct V_46 * V_62 )
{
if ( V_50 -> V_32 -> V_70 == 1 ||
! F_152 ( & V_50 -> V_65 -> V_103 , V_50 -> V_32 , NULL ) )
return;
if ( V_62 -> V_70 != 1
&& F_152 ( & V_50 -> V_65 -> V_103 , V_62 , NULL ) )
return;
F_143 ( V_50 , V_62 , 1 ) ;
F_79 ( V_50 ) ;
}
static void F_153 ( struct V_50 * V_50 , struct V_46 * V_62 , int V_108 )
{
if ( V_62 -> V_64 < V_50 -> V_32 -> V_64 ) {
F_79 ( V_50 ) ;
return;
}
#ifdef V_30
if ( V_62 -> V_64 == V_50 -> V_32 -> V_64 && ! F_154 ( V_50 -> V_32 ) )
F_151 ( V_50 , V_62 ) ;
#endif
}
static struct V_47 * F_155 ( struct V_50 * V_50 ,
struct V_21 * V_21 )
{
struct V_22 * V_23 = & V_21 -> V_25 ;
struct V_47 * V_33 = NULL ;
struct V_106 * V_27 ;
int V_117 ;
V_117 = F_124 ( V_23 -> V_28 ) ;
F_97 ( V_117 >= V_26 ) ;
V_27 = V_23 -> V_27 + V_117 ;
V_33 = F_156 ( V_27 -> V_33 , struct V_47 , V_57 ) ;
return V_33 ;
}
static struct V_46 * F_157 ( struct V_50 * V_50 )
{
struct V_47 * V_48 ;
struct V_46 * V_62 ;
struct V_21 * V_21 = & V_50 -> V_49 ;
do {
V_48 = F_155 ( V_50 , V_21 ) ;
F_97 ( ! V_48 ) ;
V_21 = F_74 ( V_48 ) ;
} while ( V_21 );
V_62 = F_25 ( V_48 ) ;
V_62 -> V_96 . V_97 = F_109 ( V_50 ) ;
return V_62 ;
}
static struct V_46 *
F_158 ( struct V_50 * V_50 , struct V_46 * V_63 )
{
struct V_46 * V_62 ;
struct V_21 * V_21 = & V_50 -> V_49 ;
if ( F_43 ( V_50 , V_63 ) ) {
F_65 ( V_50 ) ;
if ( F_94 ( ( V_50 -> V_118 && F_159 ( V_50 -> V_118 ) ) ||
V_50 -> V_119 . V_120 ) )
return V_121 ;
}
if ( V_63 -> V_94 == & V_95 )
F_108 ( V_50 ) ;
if ( ! V_21 -> V_43 )
return NULL ;
F_160 ( V_50 , V_63 ) ;
V_62 = F_157 ( V_50 ) ;
F_63 ( V_50 , V_62 ) ;
F_58 ( V_50 ) ;
return V_62 ;
}
static void F_161 ( struct V_50 * V_50 , struct V_46 * V_62 )
{
F_108 ( V_50 ) ;
if ( F_66 ( & V_62 -> V_49 ) && V_62 -> V_70 > 1 )
F_59 ( V_50 , V_62 ) ;
}
static int F_162 ( struct V_50 * V_50 , struct V_46 * V_62 , int V_53 )
{
if ( ! F_163 ( V_50 , V_62 ) &&
F_164 ( V_53 , F_165 ( V_62 ) ) )
return 1 ;
return 0 ;
}
static struct V_46 * F_166 ( struct V_50 * V_50 , int V_53 )
{
struct V_122 * V_105 = & V_50 -> V_49 . V_36 ;
struct V_46 * V_62 ;
if ( ! F_56 ( V_50 ) )
return NULL ;
F_167 (p, head, pushable_tasks) {
if ( F_162 ( V_50 , V_62 , V_53 ) )
return V_62 ;
}
return NULL ;
}
static int F_149 ( struct V_46 * V_123 )
{
struct V_124 * V_125 ;
struct V_77 * V_126 = F_168 ( V_127 ) ;
int V_128 = F_169 () ;
int V_53 = F_170 ( V_123 ) ;
if ( F_94 ( ! V_126 ) )
return - 1 ;
if ( V_123 -> V_70 == 1 )
return - 1 ;
if ( ! F_152 ( & F_42 ( V_123 ) -> V_65 -> V_103 , V_123 , V_126 ) )
return - 1 ;
if ( F_164 ( V_53 , V_126 ) )
return V_53 ;
if ( ! F_164 ( V_128 , V_126 ) )
V_128 = - 1 ;
F_146 () ;
F_171 (cpu, sd) {
if ( V_125 -> V_108 & V_129 ) {
int V_130 ;
if ( V_128 != - 1 &&
F_164 ( V_128 , F_172 ( V_125 ) ) ) {
F_150 () ;
return V_128 ;
}
V_130 = F_173 ( V_126 ,
F_172 ( V_125 ) ) ;
if ( V_130 < V_39 ) {
F_150 () ;
return V_130 ;
}
}
}
F_150 () ;
if ( V_128 != - 1 )
return V_128 ;
V_53 = F_174 ( V_126 ) ;
if ( V_53 < V_39 )
return V_53 ;
return - 1 ;
}
static struct V_50 * F_175 ( struct V_46 * V_123 , struct V_50 * V_50 )
{
struct V_50 * V_131 = NULL ;
int V_132 ;
int V_53 ;
for ( V_132 = 0 ; V_132 < V_133 ; V_132 ++ ) {
V_53 = F_149 ( V_123 ) ;
if ( ( V_53 == - 1 ) || ( V_53 == V_50 -> V_53 ) )
break;
V_131 = F_36 ( V_53 ) ;
if ( V_131 -> V_49 . V_31 . V_32 <= V_123 -> V_64 ) {
V_131 = NULL ;
break;
}
if ( F_176 ( V_50 , V_131 ) ) {
if ( F_94 ( F_42 ( V_123 ) != V_50 ||
! F_164 ( V_131 -> V_53 ,
F_165 ( V_123 ) ) ||
F_163 ( V_50 , V_123 ) ||
! F_159 ( V_123 ) ) ) {
F_177 ( V_50 , V_131 ) ;
V_131 = NULL ;
break;
}
}
if ( V_131 -> V_49 . V_31 . V_32 > V_123 -> V_64 )
break;
F_177 ( V_50 , V_131 ) ;
V_131 = NULL ;
}
return V_131 ;
}
static struct V_46 * F_178 ( struct V_50 * V_50 )
{
struct V_46 * V_62 ;
if ( ! F_56 ( V_50 ) )
return NULL ;
V_62 = F_64 ( & V_50 -> V_49 . V_36 ,
struct V_46 , V_36 ) ;
F_97 ( V_50 -> V_53 != F_170 ( V_62 ) ) ;
F_97 ( F_138 ( V_50 , V_62 ) ) ;
F_97 ( V_62 -> V_70 <= 1 ) ;
F_97 ( ! F_159 ( V_62 ) ) ;
F_97 ( ! F_148 ( V_62 ) ) ;
return V_62 ;
}
static int F_179 ( struct V_50 * V_50 )
{
struct V_46 * V_134 ;
struct V_50 * V_131 ;
int V_135 = 0 ;
if ( ! V_50 -> V_49 . V_35 )
return 0 ;
V_134 = F_178 ( V_50 ) ;
if ( ! V_134 )
return 0 ;
V_136:
if ( F_94 ( V_134 == V_50 -> V_32 ) ) {
F_123 ( 1 ) ;
return 0 ;
}
if ( F_94 ( V_134 -> V_64 < V_50 -> V_32 -> V_64 ) ) {
F_79 ( V_50 ) ;
return 0 ;
}
F_180 ( V_134 ) ;
V_131 = F_175 ( V_134 , V_50 ) ;
if ( ! V_131 ) {
struct V_46 * V_123 ;
V_123 = F_178 ( V_50 ) ;
if ( F_170 ( V_134 ) == V_50 -> V_53 && V_123 == V_134 ) {
goto V_115;
}
if ( ! V_123 )
goto V_115;
F_181 ( V_134 ) ;
V_134 = V_123 ;
goto V_136;
}
F_182 ( V_50 , V_134 , 0 ) ;
F_183 ( V_134 , V_131 -> V_53 ) ;
F_184 ( V_131 , V_134 , 0 ) ;
V_135 = 1 ;
F_79 ( V_131 ) ;
F_177 ( V_50 , V_131 ) ;
V_115:
F_181 ( V_134 ) ;
return V_135 ;
}
static void F_185 ( struct V_50 * V_50 )
{
while ( F_179 ( V_50 ) )
;
}
static int F_186 ( struct V_50 * V_50 )
{
int V_137 = V_50 -> V_49 . V_38 ;
int V_53 ;
V_53 = F_187 ( V_137 , V_50 -> V_65 -> V_68 ) ;
if ( V_137 < V_50 -> V_53 ) {
if ( V_53 >= V_50 -> V_53 )
return V_39 ;
} else if ( V_53 >= V_39 ) {
V_53 = F_188 ( V_50 -> V_65 -> V_68 ) ;
if ( V_53 >= V_50 -> V_53 )
return V_39 ;
}
V_50 -> V_49 . V_38 = V_53 ;
return V_53 ;
}
static int F_189 ( struct V_50 * V_50 )
{
struct V_50 * V_138 ;
int V_53 ;
while ( 1 ) {
V_53 = F_186 ( V_50 ) ;
if ( V_53 >= V_39 )
break;
V_138 = F_36 ( V_53 ) ;
if ( V_138 -> V_49 . V_31 . V_33 < V_50 -> V_49 . V_31 . V_32 )
break;
}
return V_53 ;
}
static void F_190 ( struct V_50 * V_50 )
{
int V_53 ;
if ( V_50 -> V_49 . V_37 & V_139 ) {
F_13 ( & V_50 -> V_49 . V_40 ) ;
if ( V_50 -> V_49 . V_37 & V_139 ) {
V_50 -> V_49 . V_37 |= V_140 ;
F_15 ( & V_50 -> V_49 . V_40 ) ;
return;
}
F_15 ( & V_50 -> V_49 . V_40 ) ;
}
V_50 -> V_49 . V_38 = V_50 -> V_53 ;
V_53 = F_189 ( V_50 ) ;
if ( V_53 >= V_39 )
return;
V_50 -> V_49 . V_37 = V_139 ;
F_191 ( & V_50 -> V_49 . V_41 , V_53 ) ;
}
static void F_192 ( void * V_141 )
{
struct V_21 * V_21 = V_141 ;
struct V_50 * V_50 , * V_142 ;
int V_128 ;
int V_53 ;
V_128 = V_21 -> V_38 ;
F_97 ( V_128 != F_169 () ) ;
V_50 = F_36 ( V_128 ) ;
V_142 = F_29 ( V_21 ) ;
V_143:
if ( F_56 ( V_50 ) ) {
F_13 ( & V_50 -> V_92 ) ;
F_179 ( V_50 ) ;
F_15 ( & V_50 -> V_92 ) ;
}
F_13 ( & V_21 -> V_40 ) ;
if ( V_21 -> V_37 & V_140 ) {
V_21 -> V_37 &= ~ V_140 ;
V_21 -> V_38 = V_142 -> V_53 ;
}
V_53 = F_189 ( V_142 ) ;
if ( V_53 >= V_39 )
V_21 -> V_37 &= ~ V_139 ;
F_15 ( & V_21 -> V_40 ) ;
if ( V_53 >= V_39 )
return;
if ( F_94 ( V_53 == V_50 -> V_53 ) )
goto V_143;
F_191 ( & V_21 -> V_41 , V_53 ) ;
}
static void V_42 ( struct V_144 * V_145 )
{
struct V_21 * V_21 = F_2 ( V_145 , struct V_21 , V_41 ) ;
F_192 ( V_21 ) ;
}
static int F_65 ( struct V_50 * V_72 )
{
int V_128 = V_72 -> V_53 , V_135 = 0 , V_53 ;
struct V_46 * V_62 ;
struct V_50 * V_142 ;
if ( F_106 ( ! F_44 ( V_72 ) ) )
return 0 ;
F_193 () ;
#ifdef F_21
if ( F_100 ( V_146 ) ) {
F_190 ( V_72 ) ;
return 0 ;
}
#endif
F_91 (cpu, this_rq->rd->rto_mask) {
if ( V_128 == V_53 )
continue;
V_142 = F_36 ( V_53 ) ;
if ( V_142 -> V_49 . V_31 . V_33 >=
V_72 -> V_49 . V_31 . V_32 )
continue;
F_176 ( V_72 , V_142 ) ;
V_62 = F_166 ( V_142 , V_128 ) ;
if ( V_62 && ( V_62 -> V_64 < V_72 -> V_49 . V_31 . V_32 ) ) {
F_123 ( V_62 == V_142 -> V_32 ) ;
F_123 ( ! F_159 ( V_62 ) ) ;
if ( V_62 -> V_64 < V_142 -> V_32 -> V_64 )
goto V_147;
V_135 = 1 ;
F_182 ( V_142 , V_62 , 0 ) ;
F_183 ( V_62 , V_128 ) ;
F_184 ( V_72 , V_62 , 0 ) ;
}
V_147:
F_177 ( V_72 , V_142 ) ;
}
return V_135 ;
}
static void F_194 ( struct V_50 * V_50 )
{
F_185 ( V_50 ) ;
}
static void F_195 ( struct V_50 * V_50 , struct V_46 * V_62 )
{
if ( ! F_163 ( V_50 , V_62 ) &&
! F_154 ( V_50 -> V_32 ) &&
F_56 ( V_50 ) &&
V_62 -> V_70 > 1 &&
( F_196 ( V_50 -> V_32 ) || F_148 ( V_50 -> V_32 ) ) &&
( V_50 -> V_32 -> V_70 < 2 ||
V_50 -> V_32 -> V_64 <= V_62 -> V_64 ) )
F_185 ( V_50 ) ;
}
static void F_197 ( struct V_46 * V_62 ,
const struct V_77 * V_148 )
{
struct V_50 * V_50 ;
int V_81 ;
F_97 ( ! F_148 ( V_62 ) ) ;
if ( ! F_159 ( V_62 ) )
return;
V_81 = F_90 ( V_148 ) ;
if ( ( V_62 -> V_70 > 1 ) == ( V_81 > 1 ) )
return;
V_50 = F_42 ( V_62 ) ;
if ( V_81 <= 1 ) {
if ( ! F_138 ( V_50 , V_62 ) )
F_63 ( V_50 , V_62 ) ;
F_97 ( ! V_50 -> V_49 . V_34 ) ;
V_50 -> V_49 . V_34 -- ;
} else {
if ( ! F_138 ( V_50 , V_62 ) )
F_59 ( V_50 , V_62 ) ;
V_50 -> V_49 . V_34 ++ ;
}
F_53 ( & V_50 -> V_49 ) ;
}
static void F_198 ( struct V_50 * V_50 )
{
if ( V_50 -> V_49 . V_35 )
F_46 ( V_50 ) ;
F_98 ( V_50 ) ;
F_119 ( & V_50 -> V_65 -> V_103 , V_50 -> V_53 , V_50 -> V_49 . V_31 . V_32 ) ;
}
static void F_199 ( struct V_50 * V_50 )
{
if ( V_50 -> V_49 . V_35 )
F_50 ( V_50 ) ;
F_93 ( V_50 ) ;
F_119 ( & V_50 -> V_65 -> V_103 , V_50 -> V_53 , V_149 ) ;
}
static void F_200 ( struct V_50 * V_50 , struct V_46 * V_62 )
{
if ( ! F_159 ( V_62 ) || V_50 -> V_49 . V_75 )
return;
if ( F_65 ( V_50 ) )
F_79 ( V_50 ) ;
}
void T_5 F_201 ( void )
{
unsigned int V_24 ;
F_33 (i) {
F_202 ( & F_203 ( V_127 , V_24 ) ,
V_58 , F_41 ( V_24 ) ) ;
}
}
static void F_204 ( struct V_50 * V_50 , struct V_46 * V_62 )
{
int V_150 = 1 ;
if ( F_159 ( V_62 ) && V_50 -> V_32 != V_62 ) {
#ifdef V_30
if ( V_62 -> V_70 > 1 && V_50 -> V_49 . V_35 &&
F_179 ( V_50 ) && V_50 != F_42 ( V_62 ) )
V_150 = 0 ;
#endif
if ( V_150 && V_62 -> V_64 < V_50 -> V_32 -> V_64 )
F_79 ( V_50 ) ;
}
}
static void
F_205 ( struct V_50 * V_50 , struct V_46 * V_62 , int V_151 )
{
if ( ! F_159 ( V_62 ) )
return;
if ( V_50 -> V_32 == V_62 ) {
#ifdef V_30
if ( V_151 < V_62 -> V_64 )
F_65 ( V_50 ) ;
if ( V_62 -> V_64 > V_50 -> V_49 . V_31 . V_32 && V_50 -> V_32 == V_62 )
F_79 ( V_50 ) ;
#else
if ( V_151 < V_62 -> V_64 )
F_79 ( V_50 ) ;
#endif
} else {
if ( V_62 -> V_64 < V_50 -> V_32 -> V_64 )
F_79 ( V_50 ) ;
}
}
static void F_206 ( struct V_50 * V_50 , struct V_46 * V_62 )
{
unsigned long V_152 , V_153 ;
V_152 = F_207 ( V_62 , V_154 ) ;
V_153 = F_208 ( V_62 , V_154 ) ;
if ( V_152 != V_155 ) {
unsigned long V_33 ;
if ( V_62 -> V_49 . V_156 != V_157 ) {
V_62 -> V_49 . V_110 ++ ;
V_62 -> V_49 . V_156 = V_157 ;
}
V_33 = F_209 ( F_102 ( V_152 , V_153 ) , V_158 / V_159 ) ;
if ( V_62 -> V_49 . V_110 > V_33 )
V_62 -> V_160 . V_161 = V_62 -> V_96 . V_100 ;
}
}
static void F_210 ( struct V_50 * V_50 , struct V_46 * V_62 , int V_162 )
{
struct V_47 * V_48 = & V_62 -> V_49 ;
F_108 ( V_50 ) ;
F_206 ( V_50 , V_62 ) ;
if ( V_62 -> V_163 != V_164 )
return;
if ( -- V_62 -> V_49 . V_165 )
return;
V_62 -> V_49 . V_165 = V_166 ;
F_115 (rt_se) {
if ( V_48 -> V_57 . V_63 != V_48 -> V_57 . V_33 ) {
F_143 ( V_50 , V_62 , 0 ) ;
F_79 ( V_50 ) ;
return;
}
}
}
static void F_211 ( struct V_50 * V_50 )
{
struct V_46 * V_62 = V_50 -> V_32 ;
V_62 -> V_96 . V_97 = F_109 ( V_50 ) ;
F_63 ( V_50 , V_62 ) ;
}
static unsigned int F_212 ( struct V_50 * V_50 , struct V_46 * V_123 )
{
if ( V_123 -> V_163 == V_164 )
return V_166 ;
else
return 0 ;
}
void F_213 ( struct V_167 * V_168 , int V_53 )
{
T_4 V_83 ;
struct V_21 * V_21 ;
F_146 () ;
F_95 (rt_rq, iter, cpu_rq(cpu))
F_214 ( V_168 , V_53 , V_21 ) ;
F_150 () ;
}
