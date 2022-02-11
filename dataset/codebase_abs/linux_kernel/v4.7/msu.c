static inline bool F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return true ;
if ( ! F_2 ( V_2 ) )
return true ;
return false ;
}
static struct V_4 * F_3 ( struct V_5 * V_5 )
{
struct V_4 * V_6 ;
T_1 V_7 = F_4 ( V_5 -> V_8 + V_9 ) ;
unsigned long V_10 = ( unsigned long ) V_7 << V_11 ;
unsigned int V_12 = 0 ;
if ( F_5 ( & V_5 -> V_13 ) )
return NULL ;
F_6 (win, &msc->win_list, entry) {
if ( V_6 -> V_14 [ 0 ] . V_15 == V_10 )
V_12 ++ ;
if ( F_1 ( V_6 -> V_14 [ 0 ] . V_2 ) )
continue;
if ( V_12 )
return V_6 ;
}
return F_7 ( V_5 -> V_13 . V_16 , struct V_4 , V_17 ) ;
}
static unsigned int F_8 ( struct V_4 * V_6 )
{
unsigned int V_18 ;
struct V_1 * V_2 = V_6 -> V_14 [ 0 ] . V_2 ;
if ( ! F_9 ( V_2 ) )
return 0 ;
for ( V_18 = 0 ; V_18 < V_6 -> V_19 ; V_18 ++ ) {
V_2 = V_6 -> V_14 [ V_18 ] . V_2 ;
if ( F_10 ( V_2 ) )
return V_18 ;
}
return 0 ;
}
static inline bool F_11 ( struct V_4 * V_6 )
{
return V_6 -> V_17 . V_16 == & V_6 -> V_5 -> V_13 ;
}
static struct V_4 * F_12 ( struct V_4 * V_6 )
{
if ( F_11 ( V_6 ) )
return F_7 ( V_6 -> V_5 -> V_13 . V_16 , struct V_4 ,
V_17 ) ;
return F_7 ( V_6 -> V_17 . V_16 , struct V_4 , V_17 ) ;
}
static struct V_1 * F_13 ( struct V_20 * V_21 )
{
return V_21 -> V_6 -> V_14 [ V_21 -> V_14 ] . V_2 ;
}
static void F_14 ( struct V_20 * V_21 )
{
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_22 = - 1 ;
V_21 -> V_14 = - 1 ;
}
static struct V_20 * F_15 ( struct V_5 * V_5 )
{
struct V_20 * V_21 ;
V_21 = F_16 ( sizeof( * V_21 ) , V_23 ) ;
if ( ! V_21 )
return F_17 ( - V_24 ) ;
F_18 ( & V_5 -> V_25 ) ;
if ( V_5 -> V_26 ) {
F_19 ( V_21 ) ;
V_21 = F_17 ( - V_27 ) ;
goto V_28;
}
F_14 ( V_21 ) ;
V_21 -> V_5 = V_5 ;
F_20 ( & V_21 -> V_17 , & V_5 -> V_29 ) ;
V_28:
F_21 ( & V_5 -> V_25 ) ;
return V_21 ;
}
static void F_22 ( struct V_20 * V_21 , struct V_5 * V_5 )
{
F_18 ( & V_5 -> V_25 ) ;
F_23 ( & V_21 -> V_17 ) ;
F_21 ( & V_5 -> V_25 ) ;
F_19 ( V_21 ) ;
}
static void F_24 ( struct V_20 * V_21 )
{
if ( V_21 -> V_22 != - 1 )
return;
V_21 -> V_22 = F_8 ( V_21 -> V_6 ) ;
V_21 -> V_14 = V_21 -> V_22 ;
V_21 -> V_30 = 0 ;
if ( F_9 ( F_13 ( V_21 ) ) )
V_21 -> V_30 = 2 ;
}
static int F_25 ( struct V_20 * V_21 , struct V_5 * V_5 )
{
if ( V_21 -> V_31 )
return 0 ;
V_21 -> V_31 = F_3 ( V_5 ) ;
if ( ! V_21 -> V_31 )
return - V_32 ;
V_21 -> V_6 = V_21 -> V_31 ;
V_21 -> V_22 = - 1 ;
F_24 ( V_21 ) ;
return 0 ;
}
static int F_26 ( struct V_20 * V_21 )
{
V_21 -> V_6 = F_12 ( V_21 -> V_6 ) ;
V_21 -> V_22 = - 1 ;
if ( V_21 -> V_6 == V_21 -> V_31 ) {
V_21 -> V_33 ++ ;
return 1 ;
}
F_24 ( V_21 ) ;
return 0 ;
}
static int F_27 ( struct V_20 * V_21 )
{
V_21 -> V_34 = 0 ;
if ( V_21 -> V_30 && V_21 -> V_14 == V_21 -> V_22 ) {
V_21 -> V_30 -- ;
if ( ! V_21 -> V_30 )
return F_26 ( V_21 ) ;
}
if ( ! V_21 -> V_30 && F_10 ( F_13 ( V_21 ) ) )
return F_26 ( V_21 ) ;
if ( ++ V_21 -> V_14 == V_21 -> V_6 -> V_19 )
V_21 -> V_14 = 0 ;
if ( ! V_21 -> V_30 && V_21 -> V_14 == V_21 -> V_22 )
return F_26 ( V_21 ) ;
return 0 ;
}
static void F_28 ( struct V_5 * V_5 )
{
struct V_4 * V_6 ;
F_6 (win, &msc->win_list, entry) {
unsigned int V_18 ;
T_2 V_35 = sizeof( struct V_1 ) -
F_29 ( struct V_1 , V_36 ) ;
for ( V_18 = 0 ; V_18 < V_6 -> V_19 ; V_18 ++ ) {
struct V_1 * V_2 = V_6 -> V_14 [ V_18 ] . V_2 ;
memset ( & V_2 -> V_36 , 0 , V_35 ) ;
}
}
}
static int F_30 ( struct V_5 * V_5 )
{
T_1 V_7 ;
F_31 ( & V_5 -> V_25 ) ;
if ( V_5 -> V_37 > V_38 )
return - V_39 ;
if ( V_5 -> V_37 == V_38 )
F_28 ( V_5 ) ;
V_7 = V_5 -> V_40 >> V_11 ;
F_32 ( V_7 , V_5 -> V_8 + V_41 ) ;
if ( V_5 -> V_37 == V_42 ) {
V_7 = V_5 -> V_43 ;
F_32 ( V_7 , V_5 -> V_8 + V_44 ) ;
}
V_7 = F_4 ( V_5 -> V_8 + V_45 ) ;
V_7 &= ~ ( V_46 | V_47 | V_48 | V_49 ) ;
V_7 |= V_48 ;
V_7 |= V_5 -> V_37 << F_33 ( V_46 ) ;
V_7 |= V_5 -> V_50 << F_33 ( V_51 ) ;
if ( V_5 -> V_52 )
V_7 |= V_47 ;
F_32 ( V_7 , V_5 -> V_8 + V_45 ) ;
V_5 -> V_53 -> V_54 . V_55 = V_5 -> V_37 == V_38 ;
F_34 ( V_5 -> V_53 ) ;
V_5 -> V_26 = 1 ;
return 0 ;
}
static void F_35 ( struct V_5 * V_5 )
{
unsigned long V_56 ;
T_1 V_7 ;
F_31 ( & V_5 -> V_25 ) ;
F_36 ( V_5 -> V_53 ) ;
for ( V_7 = 0 , V_56 = V_57 ;
V_56 && ! ( V_7 & V_58 ) ; V_56 -- ) {
V_7 = F_4 ( V_5 -> V_8 + V_59 ) ;
F_37 () ;
}
if ( ! V_56 )
F_38 ( F_39 ( V_5 ) , L_1 ) ;
if ( V_5 -> V_37 == V_42 ) {
V_5 -> V_60 = ! ! ( V_7 & V_61 ) ;
V_7 = F_4 ( V_5 -> V_8 + V_62 ) ;
V_5 -> V_63 = V_7 & ( ( V_5 -> V_43 << V_11 ) - 1 ) ;
F_38 ( F_39 ( V_5 ) , L_2 ,
V_7 , V_5 -> V_63 , V_5 -> V_60 ) ;
}
V_7 = F_4 ( V_5 -> V_8 + V_45 ) ;
V_7 &= ~ V_48 ;
F_32 ( V_7 , V_5 -> V_8 + V_45 ) ;
V_5 -> V_26 = 0 ;
F_32 ( 0 , V_5 -> V_8 + V_41 ) ;
F_32 ( 0 , V_5 -> V_8 + V_44 ) ;
F_38 ( F_39 ( V_5 ) , L_3 ,
F_4 ( V_5 -> V_8 + V_9 ) ) ;
V_7 = F_4 ( V_5 -> V_8 + V_59 ) ;
F_38 ( F_39 ( V_5 ) , L_4 , V_7 ) ;
}
static int F_40 ( struct V_64 * V_53 )
{
struct V_5 * V_5 = F_41 ( & V_53 -> V_65 ) ;
int V_66 = - V_27 ;
if ( ! F_42 ( & V_5 -> V_67 ) )
return - V_68 ;
F_18 ( & V_5 -> V_25 ) ;
if ( F_5 ( & V_5 -> V_29 ) )
V_66 = F_30 ( V_5 ) ;
F_21 ( & V_5 -> V_25 ) ;
if ( V_66 )
F_43 ( & V_5 -> V_67 ) ;
return V_66 ;
}
static void F_44 ( struct V_64 * V_53 )
{
struct V_5 * V_5 = F_41 ( & V_53 -> V_65 ) ;
F_18 ( & V_5 -> V_25 ) ;
if ( V_5 -> V_26 ) {
F_35 ( V_5 ) ;
F_43 ( & V_5 -> V_67 ) ;
}
F_21 ( & V_5 -> V_25 ) ;
}
static int F_45 ( struct V_5 * V_5 , unsigned long V_69 )
{
unsigned int V_70 = F_46 ( V_69 ) ;
struct V_71 * V_71 ;
if ( ! V_69 )
return 0 ;
V_71 = F_47 ( V_23 | V_72 , V_70 ) ;
if ( ! V_71 )
return - V_24 ;
F_48 ( V_71 , V_70 ) ;
V_5 -> V_43 = V_69 >> V_11 ;
V_5 -> V_73 = F_49 ( V_71 ) ;
V_5 -> V_40 = F_50 ( V_71 ) ;
return 0 ;
}
static void F_51 ( struct V_5 * V_5 )
{
unsigned long V_74 ;
for ( V_74 = 0 ; V_74 < V_5 -> V_43 << V_11 ; V_74 += V_75 ) {
struct V_71 * V_71 = F_52 ( V_5 -> V_73 + V_74 ) ;
V_71 -> V_76 = NULL ;
F_53 ( V_71 ) ;
}
V_5 -> V_43 = 0 ;
}
static struct V_71 * F_54 ( struct V_5 * V_5 ,
unsigned long V_77 )
{
if ( V_77 >= V_5 -> V_43 )
return NULL ;
return F_52 ( V_5 -> V_73 + ( V_77 << V_11 ) ) ;
}
static int F_55 ( struct V_5 * V_5 , unsigned int V_19 )
{
struct V_4 * V_6 ;
unsigned long V_69 = V_75 ;
int V_78 , V_66 = - V_24 ;
if ( ! V_19 )
return 0 ;
V_6 = F_16 ( F_29 ( struct V_4 , V_14 [ V_19 ] ) ,
V_23 ) ;
if ( ! V_6 )
return - V_24 ;
if ( ! F_5 ( & V_5 -> V_13 ) ) {
struct V_4 * V_79 = F_7 ( V_5 -> V_13 . V_79 ,
struct V_4 , V_17 ) ;
V_6 -> V_77 = V_79 -> V_77 + V_79 -> V_19 ;
}
for ( V_78 = 0 ; V_78 < V_19 ; V_78 ++ ) {
V_6 -> V_14 [ V_78 ] . V_2 = F_56 ( F_39 ( V_5 ) , V_69 ,
& V_6 -> V_14 [ V_78 ] . V_15 ,
V_23 ) ;
#ifdef F_57
F_58 ( ( unsigned long ) V_6 -> V_14 [ V_78 ] . V_2 , 1 ) ;
#endif
if ( ! V_6 -> V_14 [ V_78 ] . V_2 )
goto V_80;
}
V_6 -> V_5 = V_5 ;
V_6 -> V_19 = V_19 ;
if ( F_5 ( & V_5 -> V_13 ) ) {
V_5 -> V_73 = V_6 -> V_14 [ 0 ] . V_2 ;
V_5 -> V_40 = V_6 -> V_14 [ 0 ] . V_15 ;
}
F_20 ( & V_6 -> V_17 , & V_5 -> V_13 ) ;
V_5 -> V_43 += V_19 ;
return 0 ;
V_80:
for ( V_78 -- ; V_78 >= 0 ; V_78 -- ) {
#ifdef F_57
F_59 ( ( unsigned long ) V_6 -> V_14 [ V_78 ] . V_2 , 1 ) ;
#endif
F_60 ( F_39 ( V_5 ) , V_69 , V_6 -> V_14 [ V_78 ] . V_2 ,
V_6 -> V_14 [ V_78 ] . V_15 ) ;
}
F_19 ( V_6 ) ;
return V_66 ;
}
static void F_61 ( struct V_5 * V_5 , struct V_4 * V_6 )
{
int V_78 ;
V_5 -> V_43 -= V_6 -> V_19 ;
F_23 ( & V_6 -> V_17 ) ;
if ( F_5 ( & V_5 -> V_13 ) ) {
V_5 -> V_73 = NULL ;
V_5 -> V_40 = 0 ;
}
for ( V_78 = 0 ; V_78 < V_6 -> V_19 ; V_78 ++ ) {
struct V_71 * V_71 = F_52 ( V_6 -> V_14 [ V_78 ] . V_2 ) ;
V_71 -> V_76 = NULL ;
#ifdef F_57
F_59 ( ( unsigned long ) V_6 -> V_14 [ V_78 ] . V_2 , 1 ) ;
#endif
F_60 ( F_39 ( V_6 -> V_5 ) , V_75 ,
V_6 -> V_14 [ V_78 ] . V_2 , V_6 -> V_14 [ V_78 ] . V_15 ) ;
}
F_19 ( V_6 ) ;
}
static void F_62 ( struct V_5 * V_5 )
{
struct V_4 * V_6 , * V_81 ;
F_6 (win, &msc->win_list, entry) {
unsigned int V_18 ;
T_1 V_82 = 0 ;
if ( F_11 ( V_6 ) ) {
V_82 |= V_83 ;
V_81 = F_7 ( V_5 -> V_13 . V_16 ,
struct V_4 , V_17 ) ;
} else {
V_81 = F_7 ( V_6 -> V_17 . V_16 ,
struct V_4 , V_17 ) ;
}
for ( V_18 = 0 ; V_18 < V_6 -> V_19 ; V_18 ++ ) {
struct V_1 * V_2 = V_6 -> V_14 [ V_18 ] . V_2 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_81 = V_81 -> V_14 [ 0 ] . V_15 >> V_11 ;
if ( V_18 == V_6 -> V_19 - 1 ) {
V_82 |= V_84 ;
V_2 -> V_85 =
V_6 -> V_14 [ 0 ] . V_15 >> V_11 ;
} else {
V_2 -> V_85 =
V_6 -> V_14 [ V_18 + 1 ] . V_15 >> V_11 ;
}
V_2 -> V_82 = V_82 ;
V_2 -> V_86 = V_75 / 64 ;
}
}
F_63 () ;
}
static void F_64 ( struct V_5 * V_5 )
{
struct V_4 * V_6 , * V_21 ;
F_65 (win, iter, &msc->win_list, entry)
F_61 ( V_5 , V_6 ) ;
}
static int F_66 ( struct V_5 * V_5 , unsigned long * V_43 ,
unsigned int V_87 )
{
int V_66 , V_78 ;
for ( V_78 = 0 ; V_78 < V_87 ; V_78 ++ ) {
V_66 = F_55 ( V_5 , V_43 [ V_78 ] ) ;
if ( V_66 ) {
F_64 ( V_5 ) ;
return V_66 ;
}
}
F_62 ( V_5 ) ;
return 0 ;
}
static void F_67 ( struct V_5 * V_5 )
{
if ( V_5 -> V_37 == V_42 )
F_51 ( V_5 ) ;
else if ( V_5 -> V_37 == V_38 )
F_64 ( V_5 ) ;
}
static int F_68 ( struct V_5 * V_5 , unsigned long * V_43 ,
unsigned int V_87 )
{
int V_66 ;
if ( F_69 ( & V_5 -> V_67 ) != - 1 )
return - V_27 ;
if ( V_5 -> V_37 == V_42 ) {
if ( V_87 != 1 )
return - V_32 ;
V_66 = F_45 ( V_5 , V_43 [ 0 ] << V_11 ) ;
} else if ( V_5 -> V_37 == V_38 ) {
V_66 = F_66 ( V_5 , V_43 , V_87 ) ;
} else {
V_66 = - V_39 ;
}
if ( ! V_66 ) {
F_70 () ;
if ( F_71 ( F_72 ( & V_5 -> V_67 , - 1 , 0 ) != - 1 ) )
return - V_32 ;
}
return V_66 ;
}
static int F_73 ( struct V_5 * V_5 )
{
int V_56 , V_66 = 0 ;
V_56 = F_72 ( & V_5 -> V_67 , 0 , - 1 ) ;
if ( V_56 > 0 )
V_66 = - V_27 ;
else if ( ! V_56 )
F_67 ( V_5 ) ;
return V_66 ;
}
static int F_74 ( struct V_5 * V_5 )
{
int V_66 ;
F_18 ( & V_5 -> V_25 ) ;
V_66 = F_73 ( V_5 ) ;
F_21 ( & V_5 -> V_25 ) ;
return V_66 ;
}
static struct V_71 * F_75 ( struct V_5 * V_5 , unsigned long V_77 )
{
struct V_4 * V_6 ;
if ( V_5 -> V_37 == V_42 )
return F_54 ( V_5 , V_77 ) ;
F_6 (win, &msc->win_list, entry)
if ( V_77 >= V_6 -> V_77 && V_77 < V_6 -> V_77 + V_6 -> V_19 )
goto V_12;
return NULL ;
V_12:
V_77 -= V_6 -> V_77 ;
return F_52 ( V_6 -> V_14 [ V_77 ] . V_2 ) ;
}
static unsigned long F_76 ( void * V_88 , void * V_89 , T_2 V_90 )
{
struct V_91 * V_92 = V_88 ;
unsigned long V_66 ;
V_66 = F_77 ( V_92 -> V_93 + V_92 -> V_94 , V_89 , V_90 ) ;
V_92 -> V_94 += V_90 - V_66 ;
return V_66 ;
}
static int F_78 ( struct V_95 * V_95 , struct V_96 * V_96 )
{
struct V_64 * V_53 = V_96 -> V_97 ;
struct V_5 * V_5 = F_41 ( & V_53 -> V_65 ) ;
struct V_20 * V_21 ;
if ( ! F_79 ( V_98 ) )
return - V_99 ;
V_21 = F_15 ( V_5 ) ;
if ( F_80 ( V_21 ) )
return F_81 ( V_21 ) ;
V_96 -> V_97 = V_21 ;
return F_82 ( V_95 , V_96 ) ;
}
static int F_83 ( struct V_95 * V_95 , struct V_96 * V_96 )
{
struct V_20 * V_21 = V_96 -> V_97 ;
struct V_5 * V_5 = V_21 -> V_5 ;
F_22 ( V_21 , V_5 ) ;
return 0 ;
}
static T_3
F_84 ( struct V_5 * V_5 , char T_4 * V_93 , T_5 V_74 , T_2 V_90 )
{
unsigned long V_69 = V_5 -> V_43 << V_11 , V_100 = V_90 ;
unsigned long V_101 = V_74 , V_102 = 0 ;
if ( V_5 -> V_60 ) {
V_101 += V_5 -> V_63 ;
if ( V_101 < V_69 ) {
V_102 = F_85 ( V_100 , V_69 - V_101 ) ;
if ( F_77 ( V_93 , V_5 -> V_73 + V_101 , V_102 ) )
return - V_103 ;
V_93 += V_102 ;
V_100 -= V_102 ;
V_101 += V_102 ;
}
V_101 &= V_69 - 1 ;
if ( V_100 ) {
V_102 = F_85 ( V_100 , V_5 -> V_63 - V_101 ) ;
if ( F_77 ( V_93 , V_5 -> V_73 + V_101 , V_102 ) )
return - V_103 ;
V_100 -= V_102 ;
}
return V_90 - V_100 ;
}
if ( F_77 ( V_93 , V_5 -> V_73 + V_101 , V_100 ) )
return - V_103 ;
return V_90 ;
}
static T_3 F_86 ( struct V_96 * V_96 , char T_4 * V_93 ,
T_2 V_90 , T_5 * V_104 )
{
struct V_20 * V_21 = V_96 -> V_97 ;
struct V_5 * V_5 = V_21 -> V_5 ;
T_2 V_69 ;
T_5 V_74 = * V_104 ;
T_3 V_66 = 0 ;
if ( ! F_42 ( & V_5 -> V_67 ) )
return 0 ;
if ( V_5 -> V_37 == V_42 && ! V_5 -> V_60 )
V_69 = V_5 -> V_63 ;
else
V_69 = V_5 -> V_43 << V_11 ;
if ( ! V_69 )
goto V_105;
if ( V_74 >= V_69 )
goto V_105;
if ( V_74 + V_90 >= V_69 )
V_90 = V_69 - V_74 ;
if ( V_5 -> V_37 == V_42 ) {
V_66 = F_84 ( V_5 , V_93 , V_74 , V_90 ) ;
if ( V_66 >= 0 )
* V_104 += V_66 ;
} else if ( V_5 -> V_37 == V_38 ) {
struct V_91 V_92 = {
. V_93 = V_93 ,
. V_94 = 0 ,
} ;
V_66 = F_87 ( V_21 , V_90 , & V_92 , F_76 ) ;
if ( V_66 >= 0 )
* V_104 = V_21 -> V_94 ;
} else {
V_66 = - V_39 ;
}
V_105:
F_43 ( & V_5 -> V_67 ) ;
return V_66 ;
}
static void F_88 ( struct V_106 * V_107 )
{
struct V_20 * V_21 = V_107 -> V_108 -> V_97 ;
struct V_5 * V_5 = V_21 -> V_5 ;
F_89 ( & V_5 -> V_109 ) ;
}
static void F_90 ( struct V_106 * V_107 )
{
struct V_20 * V_21 = V_107 -> V_108 -> V_97 ;
struct V_5 * V_5 = V_21 -> V_5 ;
unsigned long V_110 ;
if ( ! F_91 ( & V_5 -> V_109 , & V_5 -> V_25 ) )
return;
for ( V_110 = 0 ; V_110 < V_5 -> V_43 ; V_110 ++ ) {
struct V_71 * V_71 = F_75 ( V_5 , V_110 ) ;
if ( F_71 ( ! V_71 ) )
continue;
if ( V_71 -> V_76 )
V_71 -> V_76 = NULL ;
}
F_43 ( & V_5 -> V_67 ) ;
F_21 ( & V_5 -> V_25 ) ;
}
static int F_92 ( struct V_106 * V_107 , struct V_111 * V_112 )
{
struct V_20 * V_21 = V_107 -> V_108 -> V_97 ;
struct V_5 * V_5 = V_21 -> V_5 ;
V_112 -> V_71 = F_75 ( V_5 , V_112 -> V_77 ) ;
if ( ! V_112 -> V_71 )
return V_113 ;
F_93 ( V_112 -> V_71 ) ;
V_112 -> V_71 -> V_76 = V_107 -> V_108 -> V_114 ;
V_112 -> V_71 -> V_115 = V_112 -> V_77 ;
return 0 ;
}
static int F_94 ( struct V_96 * V_96 , struct V_106 * V_107 )
{
unsigned long V_69 = V_107 -> V_116 - V_107 -> V_117 ;
struct V_20 * V_21 = V_107 -> V_108 -> V_97 ;
struct V_5 * V_5 = V_21 -> V_5 ;
int V_66 = - V_32 ;
if ( ! V_69 || F_95 ( V_69 ) )
return - V_32 ;
if ( V_107 -> V_118 )
return - V_32 ;
if ( ! F_42 ( & V_5 -> V_67 ) )
return - V_32 ;
if ( V_5 -> V_37 != V_42 &&
V_5 -> V_37 != V_38 )
goto V_119;
if ( V_69 >> V_11 != V_5 -> V_43 )
goto V_119;
F_96 ( & V_5 -> V_109 , 1 ) ;
V_66 = 0 ;
V_119:
if ( V_66 )
F_43 ( & V_5 -> V_67 ) ;
V_107 -> V_120 = F_97 ( V_107 -> V_120 ) ;
V_107 -> V_121 |= V_122 | V_123 ;
V_107 -> V_124 = & V_125 ;
return V_66 ;
}
static int F_98 ( struct V_5 * V_5 )
{
F_96 ( & V_5 -> V_67 , - 1 ) ;
V_5 -> V_37 = V_38 ;
F_99 ( & V_5 -> V_25 ) ;
F_100 ( & V_5 -> V_13 ) ;
F_100 ( & V_5 -> V_29 ) ;
V_5 -> V_50 =
( F_4 ( V_5 -> V_8 + V_45 ) & V_51 ) >>
F_33 ( V_51 ) ;
return 0 ;
}
static T_3
F_101 ( struct V_126 * V_65 , struct V_127 * V_128 , char * V_93 )
{
struct V_5 * V_5 = F_41 ( V_65 ) ;
return F_102 ( V_93 , V_75 , L_5 , V_5 -> V_52 ) ;
}
static T_3
F_103 ( struct V_126 * V_65 , struct V_127 * V_128 , const char * V_93 ,
T_2 V_69 )
{
struct V_5 * V_5 = F_41 ( V_65 ) ;
unsigned long V_129 ;
int V_66 ;
V_66 = F_104 ( V_93 , 10 , & V_129 ) ;
if ( V_66 )
return V_66 ;
V_5 -> V_52 = ! ! V_129 ;
return V_69 ;
}
static T_3
F_105 ( struct V_126 * V_65 , struct V_127 * V_128 , char * V_93 )
{
struct V_5 * V_5 = F_41 ( V_65 ) ;
return F_102 ( V_93 , V_75 , L_6 , V_130 [ V_5 -> V_37 ] ) ;
}
static T_3
F_106 ( struct V_126 * V_65 , struct V_127 * V_128 , const char * V_93 ,
T_2 V_69 )
{
struct V_5 * V_5 = F_41 ( V_65 ) ;
T_2 V_90 = V_69 ;
char * V_131 ;
int V_78 , V_66 ;
if ( ! F_79 ( V_98 ) )
return - V_99 ;
V_131 = memchr ( V_93 , '\n' , V_90 ) ;
if ( V_131 )
V_90 = V_131 - V_93 ;
for ( V_78 = 0 ; V_78 < F_107 ( V_130 ) ; V_78 ++ )
if ( ! strncmp ( V_130 [ V_78 ] , V_93 , V_90 ) )
goto V_12;
return - V_32 ;
V_12:
F_18 ( & V_5 -> V_25 ) ;
V_66 = F_73 ( V_5 ) ;
if ( ! V_66 )
V_5 -> V_37 = V_78 ;
F_21 ( & V_5 -> V_25 ) ;
return V_66 ? V_66 : V_69 ;
}
static T_3
F_108 ( struct V_126 * V_65 , struct V_127 * V_128 , char * V_93 )
{
struct V_5 * V_5 = F_41 ( V_65 ) ;
struct V_4 * V_6 ;
T_2 V_56 = 0 ;
F_18 ( & V_5 -> V_25 ) ;
if ( V_5 -> V_37 == V_42 )
V_56 = F_102 ( V_93 , V_75 , L_7 , V_5 -> V_43 ) ;
else if ( V_5 -> V_37 == V_38 ) {
F_6 (win, &msc->win_list, entry) {
V_56 += F_102 ( V_93 + V_56 , V_75 - V_56 ,
L_8 , V_6 -> V_19 ,
F_11 ( V_6 ) ? '\n' : ',' ) ;
}
} else {
V_56 = F_102 ( V_93 , V_75 , L_9 ) ;
}
F_21 ( & V_5 -> V_25 ) ;
return V_56 ;
}
static T_3
F_109 ( struct V_126 * V_65 , struct V_127 * V_128 ,
const char * V_93 , T_2 V_69 )
{
struct V_5 * V_5 = F_41 ( V_65 ) ;
unsigned long V_129 , * V_6 = NULL , * V_132 ;
T_2 V_90 = V_69 ;
const char * V_133 = V_93 ;
char * V_134 , * V_135 ;
int V_66 , V_87 = 0 ;
if ( ! F_79 ( V_98 ) )
return - V_99 ;
V_66 = F_74 ( V_5 ) ;
if ( V_66 )
return V_66 ;
V_134 = memchr ( V_93 , '\n' , V_90 ) ;
if ( V_134 )
V_90 = V_134 - V_93 ;
do {
V_134 = memchr ( V_133 , ',' , V_90 ) ;
V_135 = F_110 ( V_133 , V_134 ? V_134 - V_133 : V_90 , V_23 ) ;
if ( ! V_135 ) {
V_66 = - V_24 ;
goto V_136;
}
V_66 = F_104 ( V_135 , 10 , & V_129 ) ;
F_19 ( V_135 ) ;
if ( V_66 || ! V_129 )
goto V_136;
if ( V_87 && V_5 -> V_37 == V_42 ) {
V_66 = - V_32 ;
goto V_136;
}
V_87 ++ ;
V_132 = F_111 ( V_6 , sizeof( * V_6 ) * V_87 , V_23 ) ;
if ( ! V_132 ) {
F_19 ( V_6 ) ;
return - V_24 ;
}
V_6 = V_132 ;
V_6 [ V_87 - 1 ] = V_129 ;
if ( ! V_134 )
break;
V_90 -= V_134 - V_133 ;
V_133 = V_134 + 1 ;
} while ( V_90 );
F_18 ( & V_5 -> V_25 ) ;
V_66 = F_68 ( V_5 , V_6 , V_87 ) ;
F_21 ( & V_5 -> V_25 ) ;
V_136:
F_19 ( V_6 ) ;
return V_66 ? V_66 : V_69 ;
}
static int F_112 ( struct V_64 * V_53 )
{
struct V_126 * V_65 = & V_53 -> V_65 ;
struct V_137 * V_138 ;
struct V_5 * V_5 ;
void T_6 * V_73 ;
int V_139 ;
V_138 = F_113 ( V_53 , V_140 , 0 ) ;
if ( ! V_138 )
return - V_68 ;
V_73 = F_114 ( V_65 , V_138 -> V_101 , F_115 ( V_138 ) ) ;
if ( ! V_73 )
return - V_24 ;
V_5 = F_116 ( V_65 , sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 )
return - V_24 ;
V_5 -> V_115 = V_53 -> V_141 ;
V_5 -> V_53 = V_53 ;
V_5 -> V_8 = V_73 + V_5 -> V_115 * 0x100 ;
V_139 = F_98 ( V_5 ) ;
if ( V_139 )
return V_139 ;
F_117 ( V_65 , V_5 ) ;
return 0 ;
}
static void F_118 ( struct V_64 * V_53 )
{
struct V_5 * V_5 = F_41 ( & V_53 -> V_65 ) ;
int V_66 ;
F_44 ( V_53 ) ;
V_66 = F_74 ( V_5 ) ;
F_71 ( V_66 ) ;
}
