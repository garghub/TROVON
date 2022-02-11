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
void F_16 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
struct V_23 * V_24 ;
int V_25 ;
V_24 = & V_21 -> V_26 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
F_17 ( V_24 -> V_28 + V_25 ) ;
F_18 ( V_25 , V_24 -> V_29 ) ;
}
F_19 ( V_27 , V_24 -> V_29 ) ;
#if V_30 V_31
V_21 -> V_32 . V_33 = V_27 ;
V_21 -> V_32 . V_34 = V_27 ;
V_21 -> V_35 = 0 ;
V_21 -> V_36 = 0 ;
F_20 ( & V_21 -> V_37 ) ;
#endif
V_21 -> V_38 = 0 ;
V_21 -> V_39 = 0 ;
V_21 -> V_15 = 0 ;
F_8 ( & V_21 -> V_16 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
F_22 ( & V_5 -> V_6 ) ;
}
static inline struct V_40 * F_23 ( struct V_41 * V_42 )
{
#ifdef F_24
F_25 ( ! F_26 ( V_42 ) ) ;
#endif
return F_2 ( V_42 , struct V_40 , V_43 ) ;
}
static inline struct V_22 * F_27 ( struct V_21 * V_21 )
{
return V_21 -> V_22 ;
}
static inline struct V_21 * F_28 ( struct V_41 * V_42 )
{
return V_42 -> V_21 ;
}
void F_29 ( struct V_44 * V_45 )
{
int V_25 ;
if ( V_45 -> V_42 )
F_21 ( & V_45 -> V_4 ) ;
F_30 (i) {
if ( V_45 -> V_21 )
F_31 ( V_45 -> V_21 [ V_25 ] ) ;
if ( V_45 -> V_42 )
F_31 ( V_45 -> V_42 [ V_25 ] ) ;
}
F_31 ( V_45 -> V_21 ) ;
F_31 ( V_45 -> V_42 ) ;
}
void F_32 ( struct V_44 * V_45 , struct V_21 * V_21 ,
struct V_41 * V_42 , int V_46 ,
struct V_41 * V_47 )
{
struct V_22 * V_22 = F_33 ( V_46 ) ;
V_21 -> V_32 . V_33 = V_27 ;
V_21 -> V_48 = 0 ;
V_21 -> V_22 = V_22 ;
V_21 -> V_45 = V_45 ;
V_45 -> V_21 [ V_46 ] = V_21 ;
V_45 -> V_42 [ V_46 ] = V_42 ;
if ( ! V_42 )
return;
if ( ! V_47 )
V_42 -> V_21 = & V_22 -> V_43 ;
else
V_42 -> V_21 = V_47 -> V_49 ;
V_42 -> V_49 = V_21 ;
V_42 -> V_47 = V_47 ;
F_17 ( & V_42 -> V_50 ) ;
}
int F_34 ( struct V_44 * V_45 , struct V_44 * V_47 )
{
struct V_21 * V_21 ;
struct V_41 * V_42 ;
int V_25 ;
V_45 -> V_21 = F_35 ( sizeof( V_21 ) * V_51 , V_52 ) ;
if ( ! V_45 -> V_21 )
goto V_53;
V_45 -> V_42 = F_35 ( sizeof( V_42 ) * V_51 , V_52 ) ;
if ( ! V_45 -> V_42 )
goto V_53;
F_6 ( & V_45 -> V_4 ,
F_36 ( V_54 . V_10 ) , 0 ) ;
F_30 (i) {
V_21 = F_37 ( sizeof( struct V_21 ) ,
V_52 , F_38 ( V_25 ) ) ;
if ( ! V_21 )
goto V_53;
V_42 = F_37 ( sizeof( struct V_41 ) ,
V_52 , F_38 ( V_25 ) ) ;
if ( ! V_42 )
goto V_55;
F_16 ( V_21 , F_33 ( V_25 ) ) ;
V_21 -> V_15 = V_45 -> V_4 . V_15 ;
F_32 ( V_45 , V_21 , V_42 , V_25 , V_47 -> V_42 [ V_25 ] ) ;
}
return 1 ;
V_55:
F_31 ( V_21 ) ;
V_53:
return 0 ;
}
static inline struct V_40 * F_23 ( struct V_41 * V_42 )
{
return F_2 ( V_42 , struct V_40 , V_43 ) ;
}
static inline struct V_22 * F_27 ( struct V_21 * V_21 )
{
return F_2 ( V_21 , struct V_22 , V_43 ) ;
}
static inline struct V_21 * F_28 ( struct V_41 * V_42 )
{
struct V_40 * V_56 = F_23 ( V_42 ) ;
struct V_22 * V_22 = F_39 ( V_56 ) ;
return & V_22 -> V_43 ;
}
void F_29 ( struct V_44 * V_45 ) { }
int F_34 ( struct V_44 * V_45 , struct V_44 * V_47 )
{
return 1 ;
}
static inline int F_40 ( struct V_22 * V_22 )
{
return F_41 ( & V_22 -> V_57 -> V_58 ) ;
}
static inline void F_42 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_59 )
return;
F_43 ( V_22 -> V_46 , V_22 -> V_57 -> V_60 ) ;
F_44 () ;
F_45 ( & V_22 -> V_57 -> V_58 ) ;
}
static inline void F_46 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_59 )
return;
F_47 ( & V_22 -> V_57 -> V_58 ) ;
F_48 ( V_22 -> V_46 , V_22 -> V_57 -> V_60 ) ;
}
static void F_49 ( struct V_21 * V_21 )
{
if ( V_21 -> V_35 && V_21 -> V_61 > 1 ) {
if ( ! V_21 -> V_36 ) {
F_42 ( F_27 ( V_21 ) ) ;
V_21 -> V_36 = 1 ;
}
} else if ( V_21 -> V_36 ) {
F_46 ( F_27 ( V_21 ) ) ;
V_21 -> V_36 = 0 ;
}
}
static void F_50 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
if ( ! F_26 ( V_42 ) )
return;
V_21 = & F_27 ( V_21 ) -> V_43 ;
V_21 -> V_61 ++ ;
if ( V_42 -> V_62 > 1 )
V_21 -> V_35 ++ ;
F_49 ( V_21 ) ;
}
static void F_51 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
if ( ! F_26 ( V_42 ) )
return;
V_21 = & F_27 ( V_21 ) -> V_43 ;
V_21 -> V_61 -- ;
if ( V_42 -> V_62 > 1 )
V_21 -> V_35 -- ;
F_49 ( V_21 ) ;
}
static inline int F_52 ( struct V_22 * V_22 )
{
return ! F_53 ( & V_22 -> V_43 . V_37 ) ;
}
static void F_54 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
F_55 ( & V_56 -> V_37 , & V_22 -> V_43 . V_37 ) ;
F_56 ( & V_56 -> V_37 , V_56 -> V_63 ) ;
F_57 ( & V_56 -> V_37 , & V_22 -> V_43 . V_37 ) ;
if ( V_56 -> V_63 < V_22 -> V_43 . V_32 . V_34 )
V_22 -> V_43 . V_32 . V_34 = V_56 -> V_63 ;
}
static void F_58 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
F_55 ( & V_56 -> V_37 , & V_22 -> V_43 . V_37 ) ;
if ( F_52 ( V_22 ) ) {
V_56 = F_59 ( & V_22 -> V_43 . V_37 ,
struct V_40 , V_37 ) ;
V_22 -> V_43 . V_32 . V_34 = V_56 -> V_63 ;
} else
V_22 -> V_43 . V_32 . V_34 = V_27 ;
}
static inline void F_54 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
}
static inline void F_58 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
}
static inline
void F_50 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
}
static inline
void F_51 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
}
static inline int F_60 ( struct V_41 * V_42 )
{
return ! F_61 ( & V_42 -> V_50 ) ;
}
static inline T_2 F_62 ( struct V_21 * V_21 )
{
if ( ! V_21 -> V_45 )
return V_20 ;
return V_21 -> V_15 ;
}
static inline T_2 F_63 ( struct V_21 * V_21 )
{
return F_36 ( V_21 -> V_45 -> V_4 . V_10 ) ;
}
static inline struct V_44 * F_64 ( struct V_44 * V_45 )
{
do {
V_45 = F_65 ( V_45 -> V_64 . V_34 ,
F_66 ( struct V_44 ) , V_64 ) ;
} while ( & V_45 -> V_64 != & V_65 && F_67 ( V_45 ) );
if ( & V_45 -> V_64 == & V_65 )
V_45 = NULL ;
return V_45 ;
}
static inline void F_68 ( struct V_21 * V_21 )
{
F_69 ( & V_21 -> V_66 ,
& F_27 ( V_21 ) -> V_66 ) ;
}
static inline void F_70 ( struct V_21 * V_21 )
{
F_71 ( & V_21 -> V_66 ) ;
}
static inline struct V_21 * F_72 ( struct V_41 * V_42 )
{
return V_42 -> V_49 ;
}
static void F_73 ( struct V_21 * V_21 )
{
struct V_40 * V_33 = F_27 ( V_21 ) -> V_33 ;
struct V_41 * V_42 ;
int V_46 = F_74 ( F_27 ( V_21 ) ) ;
V_42 = V_21 -> V_45 -> V_42 [ V_46 ] ;
if ( V_21 -> V_67 ) {
if ( V_42 && ! F_60 ( V_42 ) )
F_75 ( V_42 , false ) ;
if ( V_21 -> V_32 . V_33 < V_33 -> V_63 )
F_76 ( V_33 ) ;
}
}
static void F_77 ( struct V_21 * V_21 )
{
struct V_41 * V_42 ;
int V_46 = F_74 ( F_27 ( V_21 ) ) ;
V_42 = V_21 -> V_45 -> V_42 [ V_46 ] ;
if ( V_42 && F_60 ( V_42 ) )
F_78 ( V_42 ) ;
}
static inline int F_79 ( struct V_21 * V_21 )
{
return V_21 -> V_39 && ! V_21 -> V_48 ;
}
static int F_80 ( struct V_41 * V_42 )
{
struct V_21 * V_21 = F_72 ( V_42 ) ;
struct V_40 * V_56 ;
if ( V_21 )
return ! ! V_21 -> V_48 ;
V_56 = F_23 ( V_42 ) ;
return V_56 -> V_63 != V_56 -> V_68 ;
}
static inline const struct V_69 * F_81 ( void )
{
return F_33 ( F_82 () ) -> V_57 -> V_70 ;
}
static inline const struct V_69 * F_81 ( void )
{
return V_71 ;
}
static inline
struct V_21 * F_83 ( struct V_4 * V_5 , int V_46 )
{
return F_2 ( V_5 , struct V_44 , V_4 ) -> V_21 [ V_46 ] ;
}
static inline struct V_4 * F_84 ( struct V_21 * V_21 )
{
return & V_21 -> V_45 -> V_4 ;
}
static inline T_2 F_62 ( struct V_21 * V_21 )
{
return V_21 -> V_15 ;
}
static inline T_2 F_63 ( struct V_21 * V_21 )
{
return F_36 ( V_54 . V_10 ) ;
}
static inline void F_68 ( struct V_21 * V_21 )
{
}
static inline void F_70 ( struct V_21 * V_21 )
{
}
static inline struct V_21 * F_72 ( struct V_41 * V_42 )
{
return NULL ;
}
static inline void F_73 ( struct V_21 * V_21 )
{
if ( V_21 -> V_67 )
F_76 ( F_27 ( V_21 ) -> V_33 ) ;
}
static inline void F_77 ( struct V_21 * V_21 )
{
}
static inline int F_79 ( struct V_21 * V_21 )
{
return V_21 -> V_39 ;
}
static inline const struct V_69 * F_81 ( void )
{
return V_71 ;
}
static inline
struct V_21 * F_83 ( struct V_4 * V_5 , int V_46 )
{
return & F_33 ( V_46 ) -> V_43 ;
}
static inline struct V_4 * F_84 ( struct V_21 * V_21 )
{
return & V_54 ;
}
static int F_85 ( struct V_21 * V_21 )
{
struct V_4 * V_5 = F_84 ( V_21 ) ;
struct V_72 * V_57 = F_33 ( F_82 () ) -> V_57 ;
int V_25 , V_73 , V_74 = 0 ;
T_2 V_10 ;
V_73 = F_86 ( V_57 -> V_70 ) ;
F_13 ( & V_5 -> V_16 ) ;
V_10 = F_36 ( V_5 -> V_10 ) ;
F_87 (i, rd->span) {
struct V_21 * V_75 = F_83 ( V_5 , V_25 ) ;
T_3 V_76 ;
if ( V_75 == V_21 )
continue;
F_13 ( & V_75 -> V_16 ) ;
if ( V_75 -> V_15 == V_20 )
goto V_34;
V_76 = V_75 -> V_15 - V_75 -> V_38 ;
if ( V_76 > 0 ) {
V_76 = F_88 ( ( T_2 ) V_76 , V_73 ) ;
if ( V_21 -> V_15 + V_76 > V_10 )
V_76 = V_10 - V_21 -> V_15 ;
V_75 -> V_15 -= V_76 ;
V_21 -> V_15 += V_76 ;
V_74 = 1 ;
if ( V_21 -> V_15 == V_10 ) {
F_15 ( & V_75 -> V_16 ) ;
break;
}
}
V_34:
F_15 ( & V_75 -> V_16 ) ;
}
F_15 ( & V_5 -> V_16 ) ;
return V_74 ;
}
static void F_89 ( struct V_22 * V_22 )
{
struct V_72 * V_57 = V_22 -> V_57 ;
T_4 V_75 ;
struct V_21 * V_21 ;
if ( F_90 ( ! V_77 ) )
return;
F_91 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_84 ( V_21 ) ;
T_3 V_78 ;
int V_25 ;
F_13 ( & V_5 -> V_16 ) ;
F_13 ( & V_21 -> V_16 ) ;
if ( V_21 -> V_15 == V_20 ||
V_21 -> V_15 == V_5 -> V_15 )
goto V_79;
F_15 ( & V_21 -> V_16 ) ;
V_78 = V_5 -> V_15 - V_21 -> V_15 ;
F_87 (i, rd->span) {
struct V_21 * V_75 = F_83 ( V_5 , V_25 ) ;
T_3 V_76 ;
if ( V_75 == V_21 || V_75 -> V_15 == V_20 )
continue;
F_13 ( & V_75 -> V_16 ) ;
if ( V_78 > 0 ) {
V_76 = F_92 ( T_3 , V_75 -> V_15 , V_78 ) ;
V_75 -> V_15 -= V_76 ;
V_78 -= V_76 ;
} else {
V_75 -> V_15 -= V_78 ;
V_78 -= V_78 ;
}
F_15 ( & V_75 -> V_16 ) ;
if ( ! V_78 )
break;
}
F_13 ( & V_21 -> V_16 ) ;
F_93 ( V_78 ) ;
V_79:
V_21 -> V_15 = V_20 ;
F_15 ( & V_21 -> V_16 ) ;
F_15 ( & V_5 -> V_16 ) ;
}
}
static void F_94 ( struct V_22 * V_22 )
{
unsigned long V_80 ;
F_95 ( & V_22 -> V_81 , V_80 ) ;
F_89 ( V_22 ) ;
F_96 ( & V_22 -> V_81 , V_80 ) ;
}
static void F_97 ( struct V_22 * V_22 )
{
T_4 V_75 ;
struct V_21 * V_21 ;
if ( F_90 ( ! V_77 ) )
return;
F_91 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_84 ( V_21 ) ;
F_13 ( & V_5 -> V_16 ) ;
F_13 ( & V_21 -> V_16 ) ;
V_21 -> V_15 = V_5 -> V_15 ;
V_21 -> V_38 = 0 ;
V_21 -> V_39 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
F_15 ( & V_5 -> V_16 ) ;
}
}
static void F_98 ( struct V_22 * V_22 )
{
unsigned long V_80 ;
F_95 ( & V_22 -> V_81 , V_80 ) ;
F_97 ( V_22 ) ;
F_96 ( & V_22 -> V_81 , V_80 ) ;
}
int F_99 ( struct V_82 * V_83 , unsigned long V_84 , void * V_85 )
{
int V_46 = ( int ) ( long ) V_85 ;
switch ( V_84 ) {
case V_86 :
case V_87 :
F_94 ( F_33 ( V_46 ) ) ;
return V_88 ;
case V_89 :
case V_90 :
case V_91 :
case V_92 :
F_98 ( F_33 ( V_46 ) ) ;
return V_88 ;
default:
return V_93 ;
}
}
static int F_100 ( struct V_21 * V_21 )
{
int V_74 = 0 ;
if ( ! F_101 ( V_94 ) )
return V_74 ;
if ( V_21 -> V_38 > V_21 -> V_15 ) {
F_15 ( & V_21 -> V_16 ) ;
V_74 = F_85 ( V_21 ) ;
F_13 ( & V_21 -> V_16 ) ;
}
return V_74 ;
}
static inline int F_100 ( struct V_21 * V_21 )
{
return 0 ;
}
static int F_5 ( struct V_4 * V_5 , int V_8 )
{
int V_25 , V_9 = 1 ;
const struct V_69 * V_70 ;
if ( ! F_11 () || V_5 -> V_15 == V_20 )
return 1 ;
V_70 = F_81 () ;
F_87 (i, span) {
int V_95 = 0 ;
struct V_21 * V_21 = F_83 ( V_5 , V_25 ) ;
struct V_22 * V_22 = F_27 ( V_21 ) ;
F_13 ( & V_22 -> V_81 ) ;
if ( V_21 -> V_38 ) {
T_2 V_14 ;
F_13 ( & V_21 -> V_16 ) ;
if ( V_21 -> V_39 )
F_100 ( V_21 ) ;
V_14 = V_21 -> V_15 ;
V_21 -> V_38 -= F_102 ( V_21 -> V_38 , V_8 * V_14 ) ;
if ( V_21 -> V_39 && V_21 -> V_38 < V_14 ) {
V_21 -> V_39 = 0 ;
V_95 = 1 ;
if ( V_21 -> V_67 && V_22 -> V_33 == V_22 -> V_9 )
V_22 -> V_96 = - 1 ;
}
if ( V_21 -> V_38 || V_21 -> V_67 )
V_9 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
} else if ( V_21 -> V_67 ) {
V_9 = 0 ;
if ( ! F_79 ( V_21 ) )
V_95 = 1 ;
}
if ( V_95 )
F_73 ( V_21 ) ;
F_15 ( & V_22 -> V_81 ) ;
}
return V_9 ;
}
static inline int F_103 ( struct V_41 * V_42 )
{
#ifdef F_104
struct V_21 * V_21 = F_72 ( V_42 ) ;
if ( V_21 )
return V_21 -> V_32 . V_33 ;
#endif
return F_23 ( V_42 ) -> V_63 ;
}
static int F_105 ( struct V_21 * V_21 )
{
T_2 V_14 = F_62 ( V_21 ) ;
if ( V_21 -> V_39 )
return F_79 ( V_21 ) ;
if ( V_14 >= F_63 ( V_21 ) )
return 0 ;
F_100 ( V_21 ) ;
V_14 = F_62 ( V_21 ) ;
if ( V_14 == V_20 )
return 0 ;
if ( V_21 -> V_38 > V_14 ) {
V_21 -> V_39 = 1 ;
F_106 ( V_97 L_1 ) ;
if ( F_79 ( V_21 ) ) {
F_77 ( V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_107 ( struct V_22 * V_22 )
{
struct V_40 * V_33 = V_22 -> V_33 ;
struct V_41 * V_42 = & V_33 -> V_43 ;
struct V_21 * V_21 = F_28 ( V_42 ) ;
T_2 V_98 ;
if ( V_33 -> V_99 != & V_100 )
return;
V_98 = V_22 -> V_101 - V_33 -> V_102 . V_103 ;
if ( F_90 ( ( T_3 ) V_98 < 0 ) )
V_98 = 0 ;
F_108 ( V_33 -> V_102 . V_104 . V_105 , F_109 ( V_33 -> V_102 . V_104 . V_105 , V_98 ) ) ;
V_33 -> V_102 . V_106 += V_98 ;
F_110 ( V_33 , V_98 ) ;
V_33 -> V_102 . V_103 = V_22 -> V_101 ;
F_111 ( V_33 , V_98 ) ;
F_112 ( V_22 , V_98 ) ;
if ( ! F_11 () )
return;
F_113 (rt_se) {
V_21 = F_28 ( V_42 ) ;
if ( F_62 ( V_21 ) != V_20 ) {
F_13 ( & V_21 -> V_16 ) ;
V_21 -> V_38 += V_98 ;
if ( F_105 ( V_21 ) )
F_76 ( V_33 ) ;
F_15 ( & V_21 -> V_16 ) ;
}
}
}
static void
F_114 ( struct V_21 * V_21 , int V_63 , int V_107 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
if ( V_22 -> V_59 && V_63 < V_107 )
F_115 ( & V_22 -> V_57 -> V_108 , V_22 -> V_46 , V_63 ) ;
}
static void
F_116 ( struct V_21 * V_21 , int V_63 , int V_107 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
if ( V_22 -> V_59 && V_21 -> V_32 . V_33 != V_107 )
F_115 ( & V_22 -> V_57 -> V_108 , V_22 -> V_46 , V_21 -> V_32 . V_33 ) ;
}
static inline
void F_114 ( struct V_21 * V_21 , int V_63 , int V_107 ) {}
static inline
void F_116 ( struct V_21 * V_21 , int V_63 , int V_107 ) {}
static void
F_117 ( struct V_21 * V_21 , int V_63 )
{
int V_107 = V_21 -> V_32 . V_33 ;
if ( V_63 < V_107 )
V_21 -> V_32 . V_33 = V_63 ;
F_114 ( V_21 , V_63 , V_107 ) ;
}
static void
F_118 ( struct V_21 * V_21 , int V_63 )
{
int V_107 = V_21 -> V_32 . V_33 ;
if ( V_21 -> V_67 ) {
F_119 ( V_63 < V_107 ) ;
if ( V_63 == V_107 ) {
struct V_23 * V_24 = & V_21 -> V_26 ;
V_21 -> V_32 . V_33 =
F_120 ( V_24 -> V_29 ) ;
}
} else
V_21 -> V_32 . V_33 = V_27 ;
F_116 ( V_21 , V_63 , V_107 ) ;
}
static inline void F_117 ( struct V_21 * V_21 , int V_63 ) {}
static inline void F_118 ( struct V_21 * V_21 , int V_63 ) {}
static void
F_121 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
if ( F_80 ( V_42 ) )
V_21 -> V_48 ++ ;
if ( V_21 -> V_45 )
F_10 ( & V_21 -> V_45 -> V_4 ) ;
}
static void
F_122 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
if ( F_80 ( V_42 ) )
V_21 -> V_48 -- ;
F_119 ( ! V_21 -> V_67 && V_21 -> V_48 ) ;
}
static void
F_121 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
F_10 ( & V_54 ) ;
}
static inline
void F_122 ( struct V_41 * V_42 , struct V_21 * V_21 ) {}
static inline
void F_123 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
int V_63 = F_103 ( V_42 ) ;
F_119 ( ! F_124 ( V_63 ) ) ;
V_21 -> V_67 ++ ;
F_117 ( V_21 , V_63 ) ;
F_50 ( V_42 , V_21 ) ;
F_121 ( V_42 , V_21 ) ;
}
static inline
void F_125 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
F_119 ( ! F_124 ( F_103 ( V_42 ) ) ) ;
F_119 ( ! V_21 -> V_67 ) ;
V_21 -> V_67 -- ;
F_118 ( V_21 , F_103 ( V_42 ) ) ;
F_51 ( V_42 , V_21 ) ;
F_122 ( V_42 , V_21 ) ;
}
static void F_126 ( struct V_41 * V_42 , bool V_109 )
{
struct V_21 * V_21 = F_28 ( V_42 ) ;
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_21 * V_110 = F_72 ( V_42 ) ;
struct V_111 * V_28 = V_24 -> V_28 + F_103 ( V_42 ) ;
if ( V_110 && ( F_79 ( V_110 ) || ! V_110 -> V_67 ) )
return;
if ( ! V_21 -> V_67 )
F_68 ( V_21 ) ;
if ( V_109 )
F_127 ( & V_42 -> V_50 , V_28 ) ;
else
F_128 ( & V_42 -> V_50 , V_28 ) ;
F_19 ( F_103 ( V_42 ) , V_24 -> V_29 ) ;
F_123 ( V_42 , V_21 ) ;
}
static void F_129 ( struct V_41 * V_42 )
{
struct V_21 * V_21 = F_28 ( V_42 ) ;
struct V_23 * V_24 = & V_21 -> V_26 ;
F_130 ( & V_42 -> V_50 ) ;
if ( F_61 ( V_24 -> V_28 + F_103 ( V_42 ) ) )
F_18 ( F_103 ( V_42 ) , V_24 -> V_29 ) ;
F_125 ( V_42 , V_21 ) ;
if ( ! V_21 -> V_67 )
F_70 ( V_21 ) ;
}
static void F_131 ( struct V_41 * V_42 )
{
struct V_41 * V_112 = NULL ;
F_113 (rt_se) {
V_42 -> V_112 = V_112 ;
V_112 = V_42 ;
}
for ( V_42 = V_112 ; V_42 ; V_42 = V_42 -> V_112 ) {
if ( F_60 ( V_42 ) )
F_129 ( V_42 ) ;
}
}
static void F_75 ( struct V_41 * V_42 , bool V_109 )
{
F_131 ( V_42 ) ;
F_113 (rt_se)
F_126 ( V_42 , V_109 ) ;
}
static void F_78 ( struct V_41 * V_42 )
{
F_131 ( V_42 ) ;
F_113 (rt_se) {
struct V_21 * V_21 = F_72 ( V_42 ) ;
if ( V_21 && V_21 -> V_67 )
F_126 ( V_42 , false ) ;
}
}
static void
F_132 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_80 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
if ( V_80 & V_113 )
V_42 -> V_114 = 0 ;
F_75 ( V_42 , V_80 & V_115 ) ;
if ( ! F_133 ( V_22 , V_56 ) && V_56 -> V_43 . V_62 > 1 )
F_54 ( V_22 , V_56 ) ;
F_134 ( V_22 ) ;
}
static void F_135 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_80 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
F_107 ( V_22 ) ;
F_78 ( V_42 ) ;
F_58 ( V_22 , V_56 ) ;
F_136 ( V_22 ) ;
}
static void
F_137 ( struct V_21 * V_21 , struct V_41 * V_42 , int V_109 )
{
if ( F_60 ( V_42 ) ) {
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_111 * V_28 = V_24 -> V_28 + F_103 ( V_42 ) ;
if ( V_109 )
F_138 ( & V_42 -> V_50 , V_28 ) ;
else
F_139 ( & V_42 -> V_50 , V_28 ) ;
}
}
static void F_140 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_109 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
struct V_21 * V_21 ;
F_113 (rt_se) {
V_21 = F_28 ( V_42 ) ;
F_137 ( V_21 , V_42 , V_109 ) ;
}
}
static void F_141 ( struct V_22 * V_22 )
{
F_140 ( V_22 , V_22 -> V_33 , 0 ) ;
}
static int
F_142 ( struct V_40 * V_56 , int V_116 , int V_80 )
{
struct V_40 * V_33 ;
struct V_22 * V_22 ;
int V_46 ;
V_46 = F_143 ( V_56 ) ;
if ( V_56 -> V_43 . V_62 == 1 )
goto V_117;
if ( V_116 != V_118 && V_116 != V_119 )
goto V_117;
V_22 = F_33 ( V_46 ) ;
F_144 () ;
V_33 = F_145 ( V_22 -> V_33 ) ;
if ( V_33 && F_90 ( F_146 ( V_33 ) ) &&
( V_33 -> V_43 . V_62 < 2 ||
V_33 -> V_63 <= V_56 -> V_63 ) &&
( V_56 -> V_43 . V_62 > 1 ) ) {
int V_120 = F_147 ( V_56 ) ;
if ( V_120 != - 1 )
V_46 = V_120 ;
}
F_148 () ;
V_117:
return V_46 ;
}
static void F_149 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
if ( V_22 -> V_33 -> V_43 . V_62 == 1 )
return;
if ( V_56 -> V_43 . V_62 != 1
&& F_150 ( & V_22 -> V_57 -> V_108 , V_56 , NULL ) )
return;
if ( ! F_150 ( & V_22 -> V_57 -> V_108 , V_22 -> V_33 , NULL ) )
return;
F_140 ( V_22 , V_56 , 1 ) ;
F_76 ( V_22 -> V_33 ) ;
}
static void F_151 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_80 )
{
if ( V_56 -> V_63 < V_22 -> V_33 -> V_63 ) {
F_76 ( V_22 -> V_33 ) ;
return;
}
#ifdef V_31
if ( V_56 -> V_63 == V_22 -> V_33 -> V_63 && ! F_152 ( V_22 -> V_33 ) )
F_149 ( V_22 , V_56 ) ;
#endif
}
static struct V_41 * F_153 ( struct V_22 * V_22 ,
struct V_21 * V_21 )
{
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_41 * V_34 = NULL ;
struct V_111 * V_28 ;
int V_121 ;
V_121 = F_120 ( V_24 -> V_29 ) ;
F_93 ( V_121 >= V_27 ) ;
V_28 = V_24 -> V_28 + V_121 ;
V_34 = F_154 ( V_28 -> V_34 , struct V_41 , V_50 ) ;
return V_34 ;
}
static struct V_40 * F_155 ( struct V_22 * V_22 )
{
struct V_41 * V_42 ;
struct V_40 * V_56 ;
struct V_21 * V_21 ;
V_21 = & V_22 -> V_43 ;
if ( ! V_21 -> V_67 )
return NULL ;
if ( F_79 ( V_21 ) )
return NULL ;
do {
V_42 = F_153 ( V_22 , V_21 ) ;
F_93 ( ! V_42 ) ;
V_21 = F_72 ( V_42 ) ;
} while ( V_21 );
V_56 = F_23 ( V_42 ) ;
V_56 -> V_102 . V_103 = V_22 -> V_101 ;
return V_56 ;
}
static struct V_40 * F_156 ( struct V_22 * V_22 )
{
struct V_40 * V_56 = F_155 ( V_22 ) ;
if ( V_56 )
F_58 ( V_22 , V_56 ) ;
#ifdef V_31
V_22 -> V_122 = F_52 ( V_22 ) ;
#endif
return V_56 ;
}
static void F_157 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
F_107 ( V_22 ) ;
if ( F_60 ( & V_56 -> V_43 ) && V_56 -> V_43 . V_62 > 1 )
F_54 ( V_22 , V_56 ) ;
}
static int F_158 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_46 )
{
if ( ! F_159 ( V_22 , V_56 ) &&
( V_46 < 0 || F_160 ( V_46 , F_161 ( V_56 ) ) ) &&
( V_56 -> V_43 . V_62 > 1 ) )
return 1 ;
return 0 ;
}
static struct V_40 * F_162 ( struct V_22 * V_22 , int V_46 )
{
struct V_40 * V_34 = NULL ;
struct V_41 * V_42 ;
struct V_23 * V_24 ;
struct V_21 * V_21 ;
int V_121 ;
F_163 (rt_rq, rq) {
V_24 = & V_21 -> V_26 ;
V_121 = F_120 ( V_24 -> V_29 ) ;
V_123:
if ( V_121 >= V_27 )
continue;
if ( V_34 && V_34 -> V_63 < V_121 )
continue;
F_164 (rt_se, array->queue + idx, run_list) {
struct V_40 * V_56 ;
if ( ! F_26 ( V_42 ) )
continue;
V_56 = F_23 ( V_42 ) ;
if ( F_158 ( V_22 , V_56 , V_46 ) ) {
V_34 = V_56 ;
break;
}
}
if ( ! V_34 ) {
V_121 = F_165 ( V_24 -> V_29 , V_27 , V_121 + 1 ) ;
goto V_123;
}
}
return V_34 ;
}
static int F_147 ( struct V_40 * V_124 )
{
struct V_125 * V_126 ;
struct V_69 * V_127 = F_166 ( V_128 ) ;
int V_129 = F_82 () ;
int V_46 = F_143 ( V_124 ) ;
if ( F_90 ( ! V_127 ) )
return - 1 ;
if ( V_124 -> V_43 . V_62 == 1 )
return - 1 ;
if ( ! F_150 ( & F_39 ( V_124 ) -> V_57 -> V_108 , V_124 , V_127 ) )
return - 1 ;
if ( F_160 ( V_46 , V_127 ) )
return V_46 ;
if ( ! F_160 ( V_129 , V_127 ) )
V_129 = - 1 ;
F_144 () ;
F_167 (cpu, sd) {
if ( V_126 -> V_80 & V_130 ) {
int V_131 ;
if ( V_129 != - 1 &&
F_160 ( V_129 , F_168 ( V_126 ) ) ) {
F_148 () ;
return V_129 ;
}
V_131 = F_169 ( V_127 ,
F_168 ( V_126 ) ) ;
if ( V_131 < V_51 ) {
F_148 () ;
return V_131 ;
}
}
}
F_148 () ;
if ( V_129 != - 1 )
return V_129 ;
V_46 = F_170 ( V_127 ) ;
if ( V_46 < V_51 )
return V_46 ;
return - 1 ;
}
static struct V_22 * F_171 ( struct V_40 * V_124 , struct V_22 * V_22 )
{
struct V_22 * V_132 = NULL ;
int V_133 ;
int V_46 ;
for ( V_133 = 0 ; V_133 < V_134 ; V_133 ++ ) {
V_46 = F_147 ( V_124 ) ;
if ( ( V_46 == - 1 ) || ( V_46 == V_22 -> V_46 ) )
break;
V_132 = F_33 ( V_46 ) ;
if ( F_172 ( V_22 , V_132 ) ) {
if ( F_90 ( F_39 ( V_124 ) != V_22 ||
! F_160 ( V_132 -> V_46 ,
F_161 ( V_124 ) ) ||
F_159 ( V_22 , V_124 ) ||
! V_124 -> V_135 ) ) {
F_15 ( & V_132 -> V_81 ) ;
V_132 = NULL ;
break;
}
}
if ( V_132 -> V_43 . V_32 . V_33 > V_124 -> V_63 )
break;
F_173 ( V_22 , V_132 ) ;
V_132 = NULL ;
}
return V_132 ;
}
static struct V_40 * F_174 ( struct V_22 * V_22 )
{
struct V_40 * V_56 ;
if ( ! F_52 ( V_22 ) )
return NULL ;
V_56 = F_59 ( & V_22 -> V_43 . V_37 ,
struct V_40 , V_37 ) ;
F_93 ( V_22 -> V_46 != F_143 ( V_56 ) ) ;
F_93 ( F_133 ( V_22 , V_56 ) ) ;
F_93 ( V_56 -> V_43 . V_62 <= 1 ) ;
F_93 ( ! V_56 -> V_135 ) ;
F_93 ( ! F_146 ( V_56 ) ) ;
return V_56 ;
}
static int F_175 ( struct V_22 * V_22 )
{
struct V_40 * V_136 ;
struct V_22 * V_132 ;
int V_137 = 0 ;
if ( ! V_22 -> V_43 . V_36 )
return 0 ;
V_136 = F_174 ( V_22 ) ;
if ( ! V_136 )
return 0 ;
#ifdef F_176
if ( F_90 ( F_159 ( V_22 , V_136 ) ) )
return 0 ;
#endif
V_138:
if ( F_90 ( V_136 == V_22 -> V_33 ) ) {
F_119 ( 1 ) ;
return 0 ;
}
if ( F_90 ( V_136 -> V_63 < V_22 -> V_33 -> V_63 ) ) {
F_76 ( V_22 -> V_33 ) ;
return 0 ;
}
F_177 ( V_136 ) ;
V_132 = F_171 ( V_136 , V_22 ) ;
if ( ! V_132 ) {
struct V_40 * V_124 ;
V_124 = F_174 ( V_22 ) ;
if ( F_143 ( V_136 ) == V_22 -> V_46 && V_124 == V_136 ) {
goto V_117;
}
if ( ! V_124 )
goto V_117;
F_178 ( V_136 ) ;
V_136 = V_124 ;
goto V_138;
}
F_179 ( V_22 , V_136 , 0 ) ;
F_180 ( V_136 , V_132 -> V_46 ) ;
F_181 ( V_132 , V_136 , 0 ) ;
V_137 = 1 ;
F_76 ( V_132 -> V_33 ) ;
F_173 ( V_22 , V_132 ) ;
V_117:
F_178 ( V_136 ) ;
return V_137 ;
}
static void F_182 ( struct V_22 * V_22 )
{
while ( F_175 ( V_22 ) )
;
}
static int F_183 ( struct V_22 * V_139 )
{
int V_129 = V_139 -> V_46 , V_137 = 0 , V_46 ;
struct V_40 * V_56 ;
struct V_22 * V_140 ;
if ( F_184 ( ! F_40 ( V_139 ) ) )
return 0 ;
F_87 (cpu, this_rq->rd->rto_mask) {
if ( V_129 == V_46 )
continue;
V_140 = F_33 ( V_46 ) ;
if ( V_140 -> V_43 . V_32 . V_34 >=
V_139 -> V_43 . V_32 . V_33 )
continue;
F_172 ( V_139 , V_140 ) ;
if ( V_140 -> V_43 . V_67 <= 1 )
goto V_141;
V_56 = F_162 ( V_140 , V_129 ) ;
if ( V_56 && ( V_56 -> V_63 < V_139 -> V_43 . V_32 . V_33 ) ) {
F_119 ( V_56 == V_140 -> V_33 ) ;
F_119 ( ! V_56 -> V_135 ) ;
if ( V_56 -> V_63 < V_140 -> V_33 -> V_63 )
goto V_141;
V_137 = 1 ;
F_179 ( V_140 , V_56 , 0 ) ;
F_180 ( V_56 , V_129 ) ;
F_181 ( V_139 , V_56 , 0 ) ;
}
V_141:
F_173 ( V_139 , V_140 ) ;
}
return V_137 ;
}
static void F_185 ( struct V_22 * V_22 , struct V_40 * V_142 )
{
if ( V_22 -> V_43 . V_32 . V_33 > V_142 -> V_63 )
F_183 ( V_22 ) ;
}
static void F_186 ( struct V_22 * V_22 )
{
F_182 ( V_22 ) ;
}
static void F_187 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
if ( ! F_159 ( V_22 , V_56 ) &&
! F_152 ( V_22 -> V_33 ) &&
F_52 ( V_22 ) &&
V_56 -> V_43 . V_62 > 1 &&
F_146 ( V_22 -> V_33 ) &&
( V_22 -> V_33 -> V_43 . V_62 < 2 ||
V_22 -> V_33 -> V_63 <= V_56 -> V_63 ) )
F_182 ( V_22 ) ;
}
static void F_188 ( struct V_40 * V_56 ,
const struct V_69 * V_143 )
{
int V_73 = F_86 ( V_143 ) ;
F_93 ( ! F_146 ( V_56 ) ) ;
if ( V_56 -> V_135 && ( V_73 != V_56 -> V_43 . V_62 ) ) {
struct V_22 * V_22 = F_39 ( V_56 ) ;
if ( ! F_133 ( V_22 , V_56 ) ) {
if ( V_56 -> V_43 . V_62 > 1 )
F_58 ( V_22 , V_56 ) ;
if ( V_73 > 1 )
F_54 ( V_22 , V_56 ) ;
}
if ( ( V_56 -> V_43 . V_62 <= 1 ) && ( V_73 > 1 ) ) {
V_22 -> V_43 . V_35 ++ ;
} else if ( ( V_56 -> V_43 . V_62 > 1 ) && ( V_73 <= 1 ) ) {
F_93 ( ! V_22 -> V_43 . V_35 ) ;
V_22 -> V_43 . V_35 -- ;
}
F_49 ( & V_22 -> V_43 ) ;
}
}
static void F_189 ( struct V_22 * V_22 )
{
if ( V_22 -> V_43 . V_36 )
F_42 ( V_22 ) ;
F_97 ( V_22 ) ;
F_115 ( & V_22 -> V_57 -> V_108 , V_22 -> V_46 , V_22 -> V_43 . V_32 . V_33 ) ;
}
static void F_190 ( struct V_22 * V_22 )
{
if ( V_22 -> V_43 . V_36 )
F_46 ( V_22 ) ;
F_89 ( V_22 ) ;
F_115 ( & V_22 -> V_57 -> V_108 , V_22 -> V_46 , V_144 ) ;
}
static void F_191 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
if ( V_56 -> V_135 && ! V_22 -> V_43 . V_67 )
F_183 ( V_22 ) ;
}
void F_192 ( void )
{
unsigned int V_25 ;
F_30 (i) {
F_193 ( & F_194 ( V_128 , V_25 ) ,
V_52 , F_38 ( V_25 ) ) ;
}
}
static void F_195 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
int V_145 = 1 ;
if ( V_56 -> V_135 && V_22 -> V_33 != V_56 ) {
#ifdef V_31
if ( V_22 -> V_43 . V_36 && F_175 ( V_22 ) &&
V_22 != F_39 ( V_56 ) )
V_145 = 0 ;
#endif
if ( V_145 && V_56 -> V_63 < V_22 -> V_33 -> V_63 )
F_76 ( V_22 -> V_33 ) ;
}
}
static void
F_196 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_146 )
{
if ( ! V_56 -> V_135 )
return;
if ( V_22 -> V_33 == V_56 ) {
#ifdef V_31
if ( V_146 < V_56 -> V_63 )
F_183 ( V_22 ) ;
if ( V_56 -> V_63 > V_22 -> V_43 . V_32 . V_33 && V_22 -> V_33 == V_56 )
F_76 ( V_56 ) ;
#else
if ( V_146 < V_56 -> V_63 )
F_76 ( V_56 ) ;
#endif
} else {
if ( V_56 -> V_63 < V_22 -> V_33 -> V_63 )
F_76 ( V_22 -> V_33 ) ;
}
}
static void F_197 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
unsigned long V_147 , V_148 ;
V_147 = F_198 ( V_56 , V_149 ) ;
V_148 = F_199 ( V_56 , V_149 ) ;
if ( V_147 != V_150 ) {
unsigned long V_34 ;
V_56 -> V_43 . V_114 ++ ;
V_34 = F_200 ( F_102 ( V_147 , V_148 ) , V_151 / V_152 ) ;
if ( V_56 -> V_43 . V_114 > V_34 )
V_56 -> V_153 . V_154 = V_56 -> V_102 . V_106 ;
}
}
static void F_201 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_155 )
{
F_107 ( V_22 ) ;
F_197 ( V_22 , V_56 ) ;
if ( V_56 -> V_156 != V_157 )
return;
if ( -- V_56 -> V_43 . V_158 )
return;
V_56 -> V_43 . V_158 = V_159 ;
if ( V_56 -> V_43 . V_50 . V_142 != V_56 -> V_43 . V_50 . V_34 ) {
F_140 ( V_22 , V_56 , 0 ) ;
F_202 ( V_56 ) ;
}
}
static void F_203 ( struct V_22 * V_22 )
{
struct V_40 * V_56 = V_22 -> V_33 ;
V_56 -> V_102 . V_103 = V_22 -> V_101 ;
F_58 ( V_22 , V_56 ) ;
}
static unsigned int F_204 ( struct V_22 * V_22 , struct V_40 * V_124 )
{
if ( V_124 -> V_156 == V_157 )
return V_159 ;
else
return 0 ;
}
void F_205 ( struct V_160 * V_161 , int V_46 )
{
T_4 V_75 ;
struct V_21 * V_21 ;
F_144 () ;
F_91 (rt_rq, iter, cpu_rq(cpu))
F_206 ( V_161 , V_46 , V_21 ) ;
F_148 () ;
}
