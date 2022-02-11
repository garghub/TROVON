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
return NULL ;
F_14 ( V_21 ) ;
V_21 -> V_5 = V_5 ;
F_17 ( & V_5 -> V_24 ) ;
F_18 ( & V_21 -> V_17 , & V_5 -> V_25 ) ;
F_19 ( & V_5 -> V_24 ) ;
return V_21 ;
}
static void F_20 ( struct V_20 * V_21 , struct V_5 * V_5 )
{
F_17 ( & V_5 -> V_24 ) ;
F_21 ( & V_21 -> V_17 ) ;
F_19 ( & V_5 -> V_24 ) ;
F_22 ( V_21 ) ;
}
static void F_23 ( struct V_20 * V_21 )
{
if ( V_21 -> V_22 != - 1 )
return;
V_21 -> V_22 = F_8 ( V_21 -> V_6 ) ;
V_21 -> V_14 = V_21 -> V_22 ;
V_21 -> V_26 = 0 ;
if ( F_9 ( F_13 ( V_21 ) ) )
V_21 -> V_26 = 2 ;
}
static int F_24 ( struct V_20 * V_21 , struct V_5 * V_5 )
{
if ( V_21 -> V_27 )
return 0 ;
V_21 -> V_27 = F_3 ( V_5 ) ;
if ( ! V_21 -> V_27 )
return - V_28 ;
V_21 -> V_6 = V_21 -> V_27 ;
V_21 -> V_22 = - 1 ;
F_23 ( V_21 ) ;
return 0 ;
}
static int F_25 ( struct V_20 * V_21 )
{
V_21 -> V_6 = F_12 ( V_21 -> V_6 ) ;
V_21 -> V_22 = - 1 ;
if ( V_21 -> V_6 == V_21 -> V_27 ) {
V_21 -> V_29 ++ ;
return 1 ;
}
F_23 ( V_21 ) ;
return 0 ;
}
static int F_26 ( struct V_20 * V_21 )
{
V_21 -> V_30 = 0 ;
if ( V_21 -> V_26 && V_21 -> V_14 == V_21 -> V_22 ) {
V_21 -> V_26 -- ;
if ( ! V_21 -> V_26 )
return F_25 ( V_21 ) ;
}
if ( ! V_21 -> V_26 && F_10 ( F_13 ( V_21 ) ) )
return F_25 ( V_21 ) ;
if ( ++ V_21 -> V_14 == V_21 -> V_6 -> V_19 )
V_21 -> V_14 = 0 ;
if ( ! V_21 -> V_26 && V_21 -> V_14 == V_21 -> V_22 )
return F_25 ( V_21 ) ;
return 0 ;
}
static void F_27 ( struct V_5 * V_5 )
{
struct V_4 * V_6 ;
F_17 ( & V_5 -> V_31 ) ;
F_6 (win, &msc->win_list, entry) {
unsigned int V_18 ;
T_2 V_32 = sizeof( struct V_1 ) -
F_28 ( struct V_1 , V_33 ) ;
for ( V_18 = 0 ; V_18 < V_6 -> V_19 ; V_18 ++ ) {
struct V_1 * V_2 = V_6 -> V_14 [ V_18 ] . V_2 ;
memset ( & V_2 -> V_33 , 0 , V_32 ) ;
}
}
F_19 ( & V_5 -> V_31 ) ;
}
static int F_29 ( struct V_5 * V_5 )
{
T_1 V_7 ;
if ( V_5 -> V_34 > V_35 )
return - V_36 ;
if ( V_5 -> V_34 == V_35 )
F_27 ( V_5 ) ;
V_7 = V_5 -> V_37 >> V_11 ;
F_30 ( V_7 , V_5 -> V_8 + V_38 ) ;
if ( V_5 -> V_34 == V_39 ) {
V_7 = V_5 -> V_40 ;
F_30 ( V_7 , V_5 -> V_8 + V_41 ) ;
}
V_7 = F_4 ( V_5 -> V_8 + V_42 ) ;
V_7 &= ~ ( V_43 | V_44 | V_45 | V_46 ) ;
V_7 |= V_5 -> V_34 << F_31 ( V_43 ) ;
V_7 |= V_5 -> V_47 << F_31 ( V_48 ) ;
if ( V_5 -> V_49 )
V_7 |= V_44 ;
if ( V_5 -> V_50 )
V_7 |= V_45 ;
F_30 ( V_7 , V_5 -> V_8 + V_42 ) ;
if ( V_5 -> V_50 ) {
V_5 -> V_51 -> V_52 . V_53 = V_5 -> V_34 == V_35 ;
F_32 ( V_5 -> V_51 ) ;
}
return 0 ;
}
static void F_33 ( struct V_5 * V_5 )
{
unsigned long V_54 ;
T_1 V_7 ;
if ( ! V_5 -> V_50 )
return;
F_34 ( V_5 -> V_51 ) ;
for ( V_7 = 0 , V_54 = V_55 ;
V_54 && ! ( V_7 & V_56 ) ; V_54 -- ) {
V_7 = F_4 ( V_5 -> V_8 + V_57 ) ;
F_35 () ;
}
if ( ! V_54 )
F_36 ( F_37 ( V_5 ) , L_1 ) ;
if ( V_5 -> V_34 == V_39 ) {
V_5 -> V_58 = ! ! ( V_7 & V_59 ) ;
V_7 = F_4 ( V_5 -> V_8 + V_60 ) ;
V_5 -> V_61 = V_7 & ( ( V_5 -> V_40 << V_11 ) - 1 ) ;
F_36 ( F_37 ( V_5 ) , L_2 ,
V_7 , V_5 -> V_61 , V_5 -> V_58 ) ;
}
V_7 = F_4 ( V_5 -> V_8 + V_42 ) ;
V_7 &= ~ V_45 ;
F_30 ( V_7 , V_5 -> V_8 + V_42 ) ;
V_5 -> V_50 = 0 ;
F_30 ( 0 , V_5 -> V_8 + V_38 ) ;
F_30 ( 0 , V_5 -> V_8 + V_41 ) ;
F_36 ( F_37 ( V_5 ) , L_3 ,
F_4 ( V_5 -> V_8 + V_9 ) ) ;
V_7 = F_4 ( V_5 -> V_8 + V_57 ) ;
F_36 ( F_37 ( V_5 ) , L_4 , V_7 ) ;
}
static int F_38 ( struct V_62 * V_51 )
{
struct V_5 * V_5 = F_39 ( & V_51 -> V_63 ) ;
int V_64 = 0 ;
if ( ! F_40 ( & V_5 -> V_65 ) )
return - V_66 ;
F_17 ( & V_5 -> V_24 ) ;
if ( ! F_5 ( & V_5 -> V_25 ) )
V_64 = - V_67 ;
F_19 ( & V_5 -> V_24 ) ;
if ( V_64 ) {
F_41 ( & V_5 -> V_65 ) ;
return V_64 ;
}
V_5 -> V_50 = 1 ;
return F_29 ( V_5 ) ;
}
static void F_42 ( struct V_62 * V_51 )
{
struct V_5 * V_5 = F_39 ( & V_51 -> V_63 ) ;
F_33 ( V_5 ) ;
F_41 ( & V_5 -> V_65 ) ;
}
static int F_43 ( struct V_5 * V_5 , unsigned long V_68 )
{
unsigned int V_69 = F_44 ( V_68 ) ;
struct V_70 * V_70 ;
if ( ! V_68 )
return 0 ;
V_70 = F_45 ( V_23 | V_71 , V_69 ) ;
if ( ! V_70 )
return - V_72 ;
F_46 ( V_70 , V_69 ) ;
V_5 -> V_40 = V_68 >> V_11 ;
V_5 -> V_73 = F_47 ( V_70 ) ;
V_5 -> V_37 = F_48 ( V_70 ) ;
return 0 ;
}
static void F_49 ( struct V_5 * V_5 )
{
unsigned long V_74 ;
for ( V_74 = 0 ; V_74 < V_5 -> V_40 << V_11 ; V_74 += V_75 ) {
struct V_70 * V_70 = F_50 ( V_5 -> V_73 + V_74 ) ;
V_70 -> V_76 = NULL ;
F_51 ( V_70 ) ;
}
V_5 -> V_40 = 0 ;
}
static struct V_70 * F_52 ( struct V_5 * V_5 ,
unsigned long V_77 )
{
if ( V_77 >= V_5 -> V_40 )
return NULL ;
return F_50 ( V_5 -> V_73 + ( V_77 << V_11 ) ) ;
}
static int F_53 ( struct V_5 * V_5 , unsigned int V_19 )
{
struct V_4 * V_6 ;
unsigned long V_68 = V_75 ;
int V_78 , V_64 = - V_72 ;
if ( ! V_19 )
return 0 ;
V_6 = F_16 ( F_28 ( struct V_4 , V_14 [ V_19 ] ) ,
V_23 ) ;
if ( ! V_6 )
return - V_72 ;
if ( ! F_5 ( & V_5 -> V_13 ) ) {
struct V_4 * V_79 = F_7 ( V_5 -> V_13 . V_79 ,
struct V_4 , V_17 ) ;
V_6 -> V_77 = V_79 -> V_77 + V_79 -> V_19 ;
}
for ( V_78 = 0 ; V_78 < V_19 ; V_78 ++ ) {
V_6 -> V_14 [ V_78 ] . V_2 = F_54 ( F_37 ( V_5 ) , V_68 ,
& V_6 -> V_14 [ V_78 ] . V_15 ,
V_23 ) ;
#ifdef F_55
F_56 ( ( unsigned long ) V_6 -> V_14 [ V_78 ] . V_2 , 1 ) ;
#endif
if ( ! V_6 -> V_14 [ V_78 ] . V_2 )
goto V_80;
}
V_6 -> V_5 = V_5 ;
V_6 -> V_19 = V_19 ;
if ( F_5 ( & V_5 -> V_13 ) ) {
V_5 -> V_73 = V_6 -> V_14 [ 0 ] . V_2 ;
V_5 -> V_37 = V_6 -> V_14 [ 0 ] . V_15 ;
}
F_18 ( & V_6 -> V_17 , & V_5 -> V_13 ) ;
V_5 -> V_40 += V_19 ;
return 0 ;
V_80:
for ( V_78 -- ; V_78 >= 0 ; V_78 -- ) {
#ifdef F_55
F_57 ( ( unsigned long ) V_6 -> V_14 [ V_78 ] . V_2 , 1 ) ;
#endif
F_58 ( F_37 ( V_5 ) , V_68 , V_6 -> V_14 [ V_78 ] . V_2 ,
V_6 -> V_14 [ V_78 ] . V_15 ) ;
}
F_22 ( V_6 ) ;
return V_64 ;
}
static void F_59 ( struct V_5 * V_5 , struct V_4 * V_6 )
{
int V_78 ;
V_5 -> V_40 -= V_6 -> V_19 ;
F_21 ( & V_6 -> V_17 ) ;
if ( F_5 ( & V_5 -> V_13 ) ) {
V_5 -> V_73 = NULL ;
V_5 -> V_37 = 0 ;
}
for ( V_78 = 0 ; V_78 < V_6 -> V_19 ; V_78 ++ ) {
struct V_70 * V_70 = F_50 ( V_6 -> V_14 [ V_78 ] . V_2 ) ;
V_70 -> V_76 = NULL ;
#ifdef F_55
F_57 ( ( unsigned long ) V_6 -> V_14 [ V_78 ] . V_2 , 1 ) ;
#endif
F_58 ( F_37 ( V_6 -> V_5 ) , V_75 ,
V_6 -> V_14 [ V_78 ] . V_2 , V_6 -> V_14 [ V_78 ] . V_15 ) ;
}
F_22 ( V_6 ) ;
}
static void F_60 ( struct V_5 * V_5 )
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
F_61 () ;
}
static void F_62 ( struct V_5 * V_5 )
{
struct V_4 * V_6 , * V_21 ;
F_63 (win, iter, &msc->win_list, entry)
F_59 ( V_5 , V_6 ) ;
}
static int F_64 ( struct V_5 * V_5 , unsigned long * V_40 ,
unsigned int V_87 )
{
int V_64 , V_78 ;
for ( V_78 = 0 ; V_78 < V_87 ; V_78 ++ ) {
V_64 = F_53 ( V_5 , V_40 [ V_78 ] ) ;
if ( V_64 ) {
F_62 ( V_5 ) ;
return V_64 ;
}
}
F_60 ( V_5 ) ;
return 0 ;
}
static void F_65 ( struct V_5 * V_5 )
{
if ( V_5 -> V_34 == V_39 )
F_49 ( V_5 ) ;
else if ( V_5 -> V_34 == V_35 )
F_62 ( V_5 ) ;
}
static int F_66 ( struct V_5 * V_5 , unsigned long * V_40 ,
unsigned int V_87 )
{
int V_64 ;
if ( F_67 ( & V_5 -> V_65 ) != - 1 )
return - V_67 ;
if ( V_5 -> V_34 == V_39 ) {
if ( V_87 != 1 )
return - V_28 ;
V_64 = F_43 ( V_5 , V_40 [ 0 ] << V_11 ) ;
} else if ( V_5 -> V_34 == V_35 ) {
V_64 = F_64 ( V_5 , V_40 , V_87 ) ;
} else {
V_64 = - V_36 ;
}
if ( ! V_64 ) {
F_68 () ;
if ( F_69 ( F_70 ( & V_5 -> V_65 , - 1 , 0 ) != - 1 ) )
return - V_28 ;
}
return V_64 ;
}
static int F_71 ( struct V_5 * V_5 )
{
int V_54 , V_64 = 0 ;
V_54 = F_70 ( & V_5 -> V_65 , 0 , - 1 ) ;
if ( V_54 > 0 )
V_64 = - V_67 ;
else if ( ! V_54 )
F_65 ( V_5 ) ;
return V_64 ;
}
static int F_72 ( struct V_5 * V_5 )
{
int V_64 ;
F_17 ( & V_5 -> V_31 ) ;
V_64 = F_71 ( V_5 ) ;
F_19 ( & V_5 -> V_31 ) ;
return V_64 ;
}
static struct V_70 * F_73 ( struct V_5 * V_5 , unsigned long V_77 )
{
struct V_4 * V_6 ;
if ( V_5 -> V_34 == V_39 )
return F_52 ( V_5 , V_77 ) ;
F_6 (win, &msc->win_list, entry)
if ( V_77 >= V_6 -> V_77 && V_77 < V_6 -> V_77 + V_6 -> V_19 )
goto V_12;
return NULL ;
V_12:
V_77 -= V_6 -> V_77 ;
return F_50 ( V_6 -> V_14 [ V_77 ] . V_2 ) ;
}
static unsigned long F_74 ( void * V_88 , void * V_89 , T_2 V_90 )
{
struct V_91 * V_92 = V_88 ;
unsigned long V_64 ;
V_64 = F_75 ( V_92 -> V_93 + V_92 -> V_94 , V_89 , V_90 ) ;
V_92 -> V_94 += V_90 - V_64 ;
return V_64 ;
}
static int F_76 ( struct V_95 * V_95 , struct V_96 * V_96 )
{
struct V_62 * V_51 = V_96 -> V_97 ;
struct V_5 * V_5 = F_39 ( & V_51 -> V_63 ) ;
struct V_20 * V_21 ;
if ( ! F_77 ( V_98 ) )
return - V_99 ;
V_21 = F_15 ( V_5 ) ;
if ( ! V_21 )
return - V_72 ;
V_96 -> V_97 = V_21 ;
return F_78 ( V_95 , V_96 ) ;
}
static int F_79 ( struct V_95 * V_95 , struct V_96 * V_96 )
{
struct V_20 * V_21 = V_96 -> V_97 ;
struct V_5 * V_5 = V_21 -> V_5 ;
F_20 ( V_21 , V_5 ) ;
return 0 ;
}
static T_3
F_80 ( struct V_5 * V_5 , char T_4 * V_93 , T_5 V_74 , T_2 V_90 )
{
unsigned long V_68 = V_5 -> V_40 << V_11 , V_100 = V_90 ;
unsigned long V_101 = V_74 , V_102 = 0 ;
if ( V_5 -> V_58 ) {
V_101 += V_5 -> V_61 ;
if ( V_101 < V_68 ) {
V_102 = F_81 ( V_100 , V_68 - V_101 ) ;
if ( F_75 ( V_93 , V_5 -> V_73 + V_101 , V_102 ) )
return - V_103 ;
V_93 += V_102 ;
V_100 -= V_102 ;
V_101 += V_102 ;
}
V_101 &= V_68 - 1 ;
if ( V_100 ) {
V_102 = F_81 ( V_100 , V_5 -> V_61 - V_101 ) ;
if ( F_75 ( V_93 , V_5 -> V_73 + V_101 , V_102 ) )
return - V_103 ;
V_100 -= V_102 ;
}
return V_90 - V_100 ;
}
if ( F_75 ( V_93 , V_5 -> V_73 + V_101 , V_100 ) )
return - V_103 ;
return V_90 ;
}
static T_3 F_82 ( struct V_96 * V_96 , char T_4 * V_93 ,
T_2 V_90 , T_5 * V_104 )
{
struct V_20 * V_21 = V_96 -> V_97 ;
struct V_5 * V_5 = V_21 -> V_5 ;
T_2 V_68 ;
T_5 V_74 = * V_104 ;
T_3 V_64 = 0 ;
if ( ! F_40 ( & V_5 -> V_65 ) )
return 0 ;
if ( V_5 -> V_50 ) {
V_64 = - V_67 ;
goto V_105;
}
if ( V_5 -> V_34 == V_39 && ! V_5 -> V_58 )
V_68 = V_5 -> V_61 ;
else
V_68 = V_5 -> V_40 << V_11 ;
if ( ! V_68 )
goto V_105;
if ( V_74 >= V_68 )
goto V_105;
if ( V_74 + V_90 >= V_68 )
V_90 = V_68 - V_74 ;
if ( V_5 -> V_34 == V_39 ) {
V_64 = F_80 ( V_5 , V_93 , V_74 , V_90 ) ;
if ( V_64 >= 0 )
* V_104 += V_64 ;
} else if ( V_5 -> V_34 == V_35 ) {
struct V_91 V_92 = {
. V_93 = V_93 ,
. V_94 = 0 ,
} ;
V_64 = F_83 ( V_21 , V_90 , & V_92 , F_74 ) ;
if ( V_64 >= 0 )
* V_104 = V_21 -> V_94 ;
} else {
V_64 = - V_36 ;
}
V_105:
F_41 ( & V_5 -> V_65 ) ;
return V_64 ;
}
static void F_84 ( struct V_106 * V_107 )
{
struct V_20 * V_21 = V_107 -> V_108 -> V_97 ;
struct V_5 * V_5 = V_21 -> V_5 ;
F_85 ( & V_5 -> V_109 ) ;
}
static void F_86 ( struct V_106 * V_107 )
{
struct V_20 * V_21 = V_107 -> V_108 -> V_97 ;
struct V_5 * V_5 = V_21 -> V_5 ;
unsigned long V_110 ;
if ( ! F_87 ( & V_5 -> V_109 , & V_5 -> V_31 ) )
return;
for ( V_110 = 0 ; V_110 < V_5 -> V_40 ; V_110 ++ ) {
struct V_70 * V_70 = F_73 ( V_5 , V_110 ) ;
if ( F_69 ( ! V_70 ) )
continue;
if ( V_70 -> V_76 )
V_70 -> V_76 = NULL ;
}
F_41 ( & V_5 -> V_65 ) ;
F_19 ( & V_5 -> V_31 ) ;
}
static int F_88 ( struct V_106 * V_107 , struct V_111 * V_112 )
{
struct V_20 * V_21 = V_107 -> V_108 -> V_97 ;
struct V_5 * V_5 = V_21 -> V_5 ;
V_112 -> V_70 = F_73 ( V_5 , V_112 -> V_77 ) ;
if ( ! V_112 -> V_70 )
return V_113 ;
F_89 ( V_112 -> V_70 ) ;
V_112 -> V_70 -> V_76 = V_107 -> V_108 -> V_114 ;
V_112 -> V_70 -> V_115 = V_112 -> V_77 ;
return 0 ;
}
static int F_90 ( struct V_96 * V_96 , struct V_106 * V_107 )
{
unsigned long V_68 = V_107 -> V_116 - V_107 -> V_117 ;
struct V_20 * V_21 = V_107 -> V_108 -> V_97 ;
struct V_5 * V_5 = V_21 -> V_5 ;
int V_64 = - V_28 ;
if ( ! V_68 || F_91 ( V_68 ) )
return - V_28 ;
if ( V_107 -> V_118 )
return - V_28 ;
if ( ! F_40 ( & V_5 -> V_65 ) )
return - V_28 ;
if ( V_5 -> V_34 != V_39 &&
V_5 -> V_34 != V_35 )
goto V_119;
if ( V_68 >> V_11 != V_5 -> V_40 )
goto V_119;
F_92 ( & V_5 -> V_109 , 1 ) ;
V_64 = 0 ;
V_119:
if ( V_64 )
F_41 ( & V_5 -> V_65 ) ;
V_107 -> V_120 = F_93 ( V_107 -> V_120 ) ;
V_107 -> V_121 |= V_122 | V_123 ;
V_107 -> V_124 = & V_125 ;
return V_64 ;
}
static int F_94 ( struct V_5 * V_5 )
{
F_92 ( & V_5 -> V_65 , - 1 ) ;
V_5 -> V_34 = V_35 ;
F_95 ( & V_5 -> V_31 ) ;
F_96 ( & V_5 -> V_13 ) ;
F_95 ( & V_5 -> V_24 ) ;
F_96 ( & V_5 -> V_25 ) ;
V_5 -> V_47 =
( F_4 ( V_5 -> V_8 + V_42 ) & V_48 ) >>
F_31 ( V_48 ) ;
return 0 ;
}
static T_3
F_97 ( struct V_126 * V_63 , struct V_127 * V_128 , char * V_93 )
{
struct V_5 * V_5 = F_39 ( V_63 ) ;
return F_98 ( V_93 , V_75 , L_5 , V_5 -> V_49 ) ;
}
static T_3
F_99 ( struct V_126 * V_63 , struct V_127 * V_128 , const char * V_93 ,
T_2 V_68 )
{
struct V_5 * V_5 = F_39 ( V_63 ) ;
unsigned long V_129 ;
int V_64 ;
V_64 = F_100 ( V_93 , 10 , & V_129 ) ;
if ( V_64 )
return V_64 ;
V_5 -> V_49 = ! ! V_129 ;
return V_68 ;
}
static T_3
F_101 ( struct V_126 * V_63 , struct V_127 * V_128 , char * V_93 )
{
struct V_5 * V_5 = F_39 ( V_63 ) ;
return F_98 ( V_93 , V_75 , L_6 , V_130 [ V_5 -> V_34 ] ) ;
}
static T_3
F_102 ( struct V_126 * V_63 , struct V_127 * V_128 , const char * V_93 ,
T_2 V_68 )
{
struct V_5 * V_5 = F_39 ( V_63 ) ;
T_2 V_90 = V_68 ;
char * V_131 ;
int V_78 , V_64 ;
if ( ! F_77 ( V_98 ) )
return - V_99 ;
V_131 = memchr ( V_93 , '\n' , V_90 ) ;
if ( V_131 )
V_90 = V_131 - V_93 ;
for ( V_78 = 0 ; V_78 < F_103 ( V_130 ) ; V_78 ++ )
if ( ! strncmp ( V_130 [ V_78 ] , V_93 , V_90 ) )
goto V_12;
return - V_28 ;
V_12:
F_17 ( & V_5 -> V_31 ) ;
V_64 = F_71 ( V_5 ) ;
if ( ! V_64 )
V_5 -> V_34 = V_78 ;
F_19 ( & V_5 -> V_31 ) ;
return V_64 ? V_64 : V_68 ;
}
static T_3
F_104 ( struct V_126 * V_63 , struct V_127 * V_128 , char * V_93 )
{
struct V_5 * V_5 = F_39 ( V_63 ) ;
struct V_4 * V_6 ;
T_2 V_54 = 0 ;
F_17 ( & V_5 -> V_31 ) ;
if ( V_5 -> V_34 == V_39 )
V_54 = F_98 ( V_93 , V_75 , L_7 , V_5 -> V_40 ) ;
else if ( V_5 -> V_34 == V_35 ) {
F_6 (win, &msc->win_list, entry) {
V_54 += F_98 ( V_93 + V_54 , V_75 - V_54 ,
L_8 , V_6 -> V_19 ,
F_11 ( V_6 ) ? '\n' : ',' ) ;
}
} else {
V_54 = F_98 ( V_93 , V_75 , L_9 ) ;
}
F_19 ( & V_5 -> V_31 ) ;
return V_54 ;
}
static T_3
F_105 ( struct V_126 * V_63 , struct V_127 * V_128 ,
const char * V_93 , T_2 V_68 )
{
struct V_5 * V_5 = F_39 ( V_63 ) ;
unsigned long V_129 , * V_6 = NULL , * V_132 ;
T_2 V_90 = V_68 ;
const char * V_133 = V_93 ;
char * V_134 , * V_135 ;
int V_64 , V_87 = 0 ;
if ( ! F_77 ( V_98 ) )
return - V_99 ;
V_64 = F_72 ( V_5 ) ;
if ( V_64 )
return V_64 ;
V_134 = memchr ( V_93 , '\n' , V_90 ) ;
if ( V_134 )
V_90 = V_134 - V_93 ;
do {
V_134 = memchr ( V_133 , ',' , V_90 ) ;
V_135 = F_106 ( V_133 , V_134 ? V_134 - V_133 : V_90 , V_23 ) ;
V_64 = F_100 ( V_135 , 10 , & V_129 ) ;
F_22 ( V_135 ) ;
if ( V_64 || ! V_129 )
goto V_136;
if ( V_87 && V_5 -> V_34 == V_39 ) {
V_64 = - V_28 ;
goto V_136;
}
V_87 ++ ;
V_132 = F_107 ( V_6 , sizeof( * V_6 ) * V_87 , V_23 ) ;
if ( ! V_132 ) {
F_22 ( V_6 ) ;
return - V_72 ;
}
V_6 = V_132 ;
V_6 [ V_87 - 1 ] = V_129 ;
if ( ! V_134 )
break;
V_90 -= V_134 - V_133 ;
V_133 = V_134 + 1 ;
} while ( V_90 );
F_17 ( & V_5 -> V_31 ) ;
V_64 = F_66 ( V_5 , V_6 , V_87 ) ;
F_19 ( & V_5 -> V_31 ) ;
V_136:
F_22 ( V_6 ) ;
return V_64 ? V_64 : V_68 ;
}
static int F_108 ( struct V_62 * V_51 )
{
struct V_126 * V_63 = & V_51 -> V_63 ;
struct V_137 * V_138 ;
struct V_5 * V_5 ;
void T_6 * V_73 ;
int V_139 ;
V_138 = F_109 ( V_51 , V_140 , 0 ) ;
if ( ! V_138 )
return - V_66 ;
V_73 = F_110 ( V_63 , V_138 -> V_101 , F_111 ( V_138 ) ) ;
if ( ! V_73 )
return - V_72 ;
V_5 = F_112 ( V_63 , sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 )
return - V_72 ;
V_5 -> V_115 = V_51 -> V_141 ;
V_5 -> V_51 = V_51 ;
V_5 -> V_8 = V_73 + V_5 -> V_115 * 0x100 ;
V_139 = F_94 ( V_5 ) ;
if ( V_139 )
return V_139 ;
V_139 = F_113 ( & V_63 -> V_142 , & V_143 ) ;
if ( V_139 )
return V_139 ;
F_114 ( V_63 , V_5 ) ;
return 0 ;
}
static void F_115 ( struct V_62 * V_51 )
{
F_116 ( & V_51 -> V_63 . V_142 , & V_143 ) ;
}
