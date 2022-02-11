static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( & F_3 ( V_2 ) -> V_4 , V_5 ) ;
V_2 -> V_6 -> V_7 |= F_4 ( V_2 , V_8 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_7 &= ~ F_4 ( V_2 , V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
V_2 -> V_11 = 1 ;
V_10 = F_7 ( V_2 -> V_12 -> V_13 . V_14 ,
struct V_9 , V_13 ) ;
V_10 -> V_15 = F_8 ( V_2 , V_2 -> V_16 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
V_2 -> V_11 = 0 ;
V_10 = F_7 ( V_2 -> V_12 -> V_13 . V_14 ,
struct V_9 , V_13 ) ;
V_10 -> V_15 = F_10 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_17 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
if ( ! ( V_17 -> V_21 & V_22 ) )
V_19 -> V_23 = 1 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
if ( V_19 -> V_23 ) {
V_2 -> V_24 = 1 ;
if ( ! V_2 -> V_11 )
F_6 ( V_2 ) ;
else if ( V_2 -> V_25 ) {
V_2 -> V_25 = 0 ;
F_13 ( & V_2 -> V_26 ) ;
}
}
}
static void F_14 ( unsigned long V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
unsigned long V_28 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
if ( V_2 -> V_25 ) {
V_2 -> V_25 = 0 ;
F_9 ( V_2 ) ;
}
F_16 ( & V_2 -> V_29 , V_28 ) ;
}
static struct V_30 * F_17 ( struct V_1 * V_2 )
{
T_1 V_31 ;
struct V_30 * V_32 ;
V_32 = F_18 ( V_2 -> V_33 , V_34 , & V_31 ) ;
if ( ! V_32 )
return NULL ;
V_32 -> V_31 = V_31 ;
V_32 -> V_35 = - 1 ;
F_19 ( & V_32 -> V_36 ) ;
F_19 ( & V_32 -> V_37 ) ;
return V_32 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_30 * V_32 )
{
if ( ! F_21 ( & V_32 -> V_36 ) )
F_22 ( F_23 ( V_2 ) , L_1 , V_32 ) ;
if ( ! F_21 ( & V_32 -> V_37 ) )
F_22 ( F_23 ( V_2 ) , L_2 , V_32 ) ;
F_24 ( V_2 -> V_33 , V_32 , V_32 -> V_31 ) ;
}
static inline void F_25 ( struct V_1 * V_2 , struct V_30 * V_32 ,
T_2 V_7 , T_2 V_38 , T_2 V_39 )
{
V_32 -> V_7 = F_4 ( V_2 , V_7 ) ;
V_32 -> V_38 = F_4 ( V_2 , V_38 ) ;
V_32 -> V_39 = F_4 ( V_2 , V_39 ) ;
}
static void F_26 ( struct V_30 * V_32 , struct V_18 * V_19 )
{
F_27 ( & V_32 -> V_36 , & V_19 -> V_40 ) ;
}
static void F_28 ( struct V_30 * V_32 )
{
F_29 ( & V_32 -> V_36 ) ;
}
static inline void F_30 ( struct V_1 * V_2 ,
struct V_30 * V_32 , unsigned V_41 )
{
V_41 &= ( V_42 - 1 ) ;
V_32 -> V_35 = V_41 ;
if ( V_2 -> V_43 [ V_41 ] ) {
struct V_30 * V_44 , * V_45 ;
V_44 = V_2 -> V_43 [ V_41 ] ;
V_45 = F_7 ( V_44 -> V_37 . V_14 , struct V_30 , V_37 ) ;
F_27 ( & V_32 -> V_37 , & V_44 -> V_37 ) ;
V_32 -> V_15 = V_45 -> V_15 ;
F_31 () ;
V_45 -> V_15 = F_32 ( V_2 , V_32 ) ;
} else {
V_32 -> V_15 = V_2 -> V_35 [ V_41 ] ;
F_31 () ;
V_2 -> V_35 [ V_41 ] = F_32 ( V_2 , V_32 ) ;
V_2 -> V_43 [ V_41 ] = V_32 ;
}
}
static inline void F_33 ( struct V_1 * V_2 ,
struct V_30 * V_32 )
{
if ( V_32 -> V_35 == - 1 ) {
F_34 ( ! F_21 ( & V_32 -> V_37 ) ) ;
return;
}
if ( V_2 -> V_43 [ V_32 -> V_35 ] == V_32 ) {
if ( F_21 ( & V_32 -> V_37 ) ) {
V_2 -> V_35 [ V_32 -> V_35 ] = V_32 -> V_15 ;
V_2 -> V_43 [ V_32 -> V_35 ] = NULL ;
} else {
struct V_30 * V_46 ;
V_46 = F_7 ( V_32 -> V_37 . V_47 ,
struct V_30 ,
V_37 ) ;
V_2 -> V_35 [ V_32 -> V_35 ] = F_32 ( V_2 , V_46 ) ;
V_2 -> V_43 [ V_32 -> V_35 ] = V_46 ;
}
} else {
struct V_30 * V_48 ;
V_48 = F_7 ( V_32 -> V_37 . V_14 , struct V_30 , V_37 ) ;
V_48 -> V_15 = V_32 -> V_15 ;
}
F_29 ( & V_32 -> V_37 ) ;
V_32 -> V_35 = - 1 ;
}
static inline void F_35 ( struct V_1 * V_2 ,
unsigned int V_41 )
{
struct V_30 * V_44 , * V_45 ;
V_41 &= ( V_42 - 1 ) ;
V_44 = V_2 -> V_43 [ V_41 ] ;
if ( V_44 ) {
V_45 = F_7 ( V_44 -> V_37 . V_14 , struct V_30 , V_37 ) ;
V_2 -> V_35 [ V_41 ] = V_45 -> V_15 ;
V_2 -> V_43 [ V_41 ] = NULL ;
while ( ! F_21 ( & V_44 -> V_37 ) )
F_29 ( V_44 -> V_37 . V_14 ) ;
}
}
static void F_36 ( struct V_1 * V_2 , struct V_17 * V_17 )
{
struct V_18 * V_19 = (struct V_18 * ) V_17 -> V_20 ;
struct V_30 * V_32 ;
F_37 (td, &urbp->td_list, list)
F_33 ( V_2 , V_32 ) ;
}
static struct V_9 * F_38 ( struct V_1 * V_2 ,
struct V_49 * V_50 , struct V_51 * V_52 )
{
T_1 V_31 ;
struct V_9 * V_53 ;
V_53 = F_18 ( V_2 -> V_54 , V_34 , & V_31 ) ;
if ( ! V_53 )
return NULL ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_31 = V_31 ;
V_53 -> V_55 = F_10 ( V_2 ) ;
V_53 -> V_15 = F_10 ( V_2 ) ;
F_19 ( & V_53 -> V_56 ) ;
F_19 ( & V_53 -> V_13 ) ;
if ( V_50 ) {
V_53 -> type = F_39 ( & V_52 -> V_57 ) ;
if ( V_53 -> type != V_58 ) {
V_53 -> V_59 = F_17 ( V_2 ) ;
if ( ! V_53 -> V_59 ) {
F_24 ( V_2 -> V_54 , V_53 , V_31 ) ;
return NULL ;
}
}
V_53 -> V_60 = V_61 ;
V_53 -> V_52 = V_52 ;
V_53 -> V_50 = V_50 ;
V_52 -> V_20 = V_53 ;
if ( V_53 -> type == V_62 ||
V_53 -> type == V_58 )
V_53 -> V_63 = F_40 ( V_50 -> V_64 ,
F_41 ( & V_52 -> V_57 ) ,
V_53 -> type == V_58 ,
F_42 ( V_52 -> V_57 . V_65 ) )
/ 1000 + 1 ;
} else {
V_53 -> V_60 = V_66 ;
V_53 -> type = - 1 ;
}
return V_53 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
F_34 ( V_53 -> V_60 != V_61 && V_53 -> V_50 ) ;
if ( ! F_21 ( & V_53 -> V_56 ) )
F_22 ( F_23 ( V_2 ) , L_3 , V_53 ) ;
F_44 ( & V_53 -> V_13 ) ;
if ( V_53 -> V_50 ) {
V_53 -> V_52 -> V_20 = NULL ;
if ( V_53 -> V_59 )
F_20 ( V_2 , V_53 -> V_59 ) ;
}
F_24 ( V_2 -> V_54 , V_53 , V_53 -> V_31 ) ;
}
static int F_45 ( struct V_1 * V_2 , struct V_9 * V_53 ,
struct V_17 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_30 * V_32 ;
int V_67 = 1 ;
if ( V_53 -> type == V_58 ) {
V_67 = ( V_2 -> V_68 + V_2 -> V_3 !=
V_53 -> V_69 ) ;
goto V_70;
}
if ( V_53 -> V_56 . V_47 != & V_19 -> V_13 ) {
struct V_18 * V_71 ;
struct V_30 * V_48 ;
V_71 = F_7 ( V_19 -> V_13 . V_14 , struct V_18 , V_13 ) ;
F_34 ( F_21 ( & V_71 -> V_40 ) ) ;
V_48 = F_7 ( V_71 -> V_40 . V_14 , struct V_30 ,
V_36 ) ;
V_32 = F_7 ( V_19 -> V_40 . V_14 , struct V_30 ,
V_36 ) ;
V_48 -> V_15 = V_32 -> V_15 ;
goto V_70;
}
if ( F_46 ( V_53 ) == F_10 ( V_2 ) )
goto V_70;
V_53 -> V_55 = F_10 ( V_2 ) ;
if ( V_53 -> type == V_72 )
goto V_70;
F_34 ( F_21 ( & V_19 -> V_40 ) ) ;
V_32 = F_7 ( V_19 -> V_40 . V_47 , struct V_30 , V_36 ) ;
V_53 -> V_73 = 1 ;
V_53 -> V_74 = F_47 ( F_48 ( V_2 , V_32 ) ) ;
V_70:
return V_67 ;
}
static void F_49 ( struct V_1 * V_2 , struct V_9 * V_53 ,
int V_75 )
{
struct V_18 * V_19 = NULL ;
struct V_30 * V_32 ;
unsigned int V_76 = V_53 -> V_74 ;
unsigned int V_77 ;
if ( V_75 )
V_19 = F_7 ( V_53 -> V_56 . V_47 , struct V_18 , V_13 ) ;
else if ( F_46 ( V_53 ) != F_10 ( V_2 ) )
V_76 = 2 ;
V_19 = F_50 ( V_19 , & V_53 -> V_56 , V_13 ) ;
F_51 (urbp, &qh->queue, node) {
V_32 = F_7 ( V_19 -> V_40 . V_47 , struct V_30 , V_36 ) ;
if ( V_76 > 1 || F_47 ( F_48 ( V_2 , V_32 ) ) == V_76 ) {
V_32 = F_7 ( V_19 -> V_40 . V_14 , struct V_30 ,
V_36 ) ;
V_76 = F_47 ( F_48 ( V_2 , V_32 ) ) ^ 1 ;
} else {
F_37 (td, &urbp->td_list, list) {
V_32 -> V_38 ^= F_4 ( V_2 ,
V_78 ) ;
V_76 ^= 1 ;
}
}
}
F_31 () ;
V_77 = F_7 ( V_53 -> V_56 . V_47 , struct V_18 , V_13 ) -> V_17 -> V_77 ;
F_52 ( V_53 -> V_50 , F_53 ( V_77 ) ,
F_54 ( V_77 ) , V_76 ) ;
V_53 -> V_73 = 0 ;
}
static inline void F_55 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
F_27 ( & V_53 -> V_13 , & V_2 -> V_79 -> V_13 ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
struct V_9 * V_80 ;
F_27 ( & V_53 -> V_13 , & V_2 -> V_81 [ V_53 -> V_82 ] -> V_13 ) ;
V_80 = F_7 ( V_53 -> V_13 . V_14 , struct V_9 , V_13 ) ;
V_53 -> V_15 = V_80 -> V_15 ;
F_31 () ;
V_80 -> V_15 = F_8 ( V_2 , V_53 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
struct V_9 * V_80 ;
T_3 V_83 ;
F_58 (pqh, &uhci->skel_async_qh->node, node) {
if ( V_80 -> V_82 <= V_53 -> V_82 )
break;
}
F_59 ( & V_53 -> V_13 , & V_80 -> V_13 ) ;
V_53 -> V_15 = V_80 -> V_15 ;
F_31 () ;
V_83 = F_8 ( V_2 , V_53 ) ;
V_80 -> V_15 = V_83 ;
if ( V_80 -> V_82 < V_84 && V_53 -> V_82 >= V_84 )
V_2 -> V_16 -> V_15 = V_83 ;
}
static void F_60 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
F_34 ( F_21 ( & V_53 -> V_56 ) ) ;
if ( F_46 ( V_53 ) == F_10 ( V_2 ) ) {
struct V_18 * V_19 = F_7 ( V_53 -> V_56 . V_47 ,
struct V_18 , V_13 ) ;
struct V_30 * V_32 = F_7 ( V_19 -> V_40 . V_47 ,
struct V_30 , V_36 ) ;
V_53 -> V_55 = F_32 ( V_2 , V_32 ) ;
}
V_53 -> V_85 = 0 ;
V_53 -> V_86 = V_5 ;
if ( V_53 -> V_60 == V_66 )
return;
V_53 -> V_60 = V_66 ;
if ( V_53 == V_2 -> V_87 )
V_2 -> V_87 = F_7 ( V_53 -> V_13 . V_47 , struct V_9 ,
V_13 ) ;
F_44 ( & V_53 -> V_13 ) ;
if ( V_53 -> V_82 == V_88 )
F_55 ( V_2 , V_53 ) ;
else if ( V_53 -> V_82 < V_89 )
F_56 ( V_2 , V_53 ) ;
else
F_57 ( V_2 , V_53 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
struct V_9 * V_80 ;
V_80 = F_7 ( V_53 -> V_13 . V_14 , struct V_9 , V_13 ) ;
V_80 -> V_15 = V_53 -> V_15 ;
F_62 () ;
}
static void F_63 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
struct V_9 * V_80 ;
T_3 V_90 = V_53 -> V_15 ;
V_80 = F_7 ( V_53 -> V_13 . V_14 , struct V_9 , V_13 ) ;
V_80 -> V_15 = V_90 ;
if ( V_80 -> V_82 < V_84 && V_53 -> V_82 >= V_84 )
V_2 -> V_16 -> V_15 = V_90 ;
F_62 () ;
}
static void F_64 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
if ( V_53 -> V_60 == V_91 )
return;
F_34 ( V_53 -> V_60 != V_66 || ! V_53 -> V_50 ) ;
V_53 -> V_60 = V_91 ;
if ( V_53 -> V_82 == V_88 )
;
else if ( V_53 -> V_82 < V_89 )
F_61 ( V_2 , V_53 ) ;
else
F_63 ( V_2 , V_53 ) ;
F_65 ( V_2 ) ;
V_53 -> V_69 = V_2 -> V_68 ;
if ( F_21 ( & V_2 -> V_92 -> V_13 ) || V_2 -> V_3 )
F_1 ( V_2 ) ;
if ( V_53 == V_2 -> V_87 )
V_2 -> V_87 = F_7 ( V_53 -> V_13 . V_47 , struct V_9 ,
V_13 ) ;
F_66 ( & V_53 -> V_13 , & V_2 -> V_92 -> V_13 ) ;
}
static void F_67 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
F_34 ( V_53 -> V_60 == V_66 ) ;
if ( V_53 == V_2 -> V_87 )
V_2 -> V_87 = F_7 ( V_53 -> V_13 . V_47 , struct V_9 ,
V_13 ) ;
F_68 ( & V_53 -> V_13 , & V_2 -> V_93 ) ;
V_53 -> V_60 = V_61 ;
if ( V_53 -> V_94 ) {
F_20 ( V_2 , V_53 -> V_94 ) ;
V_53 -> V_94 = NULL ;
}
if ( V_2 -> V_95 )
F_69 ( & V_2 -> V_96 ) ;
}
static int F_70 ( struct V_1 * V_2 , int V_97 , int V_98 )
{
int V_99 = V_2 -> V_63 [ V_97 ] ;
for ( V_97 += V_98 ; V_97 < V_100 ; V_97 += V_98 )
V_99 = F_71 ( int , V_99 , V_2 -> V_63 [ V_97 ] ) ;
return V_99 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
int V_101 ;
if ( V_53 -> V_97 >= 0 )
V_101 = F_70 ( V_2 , V_53 -> V_97 , V_53 -> V_98 ) ;
else {
int V_97 , V_63 ;
int V_102 = F_73 ( int , V_100 , V_53 -> V_98 ) ;
V_53 -> V_97 = 0 ;
V_101 = F_70 ( V_2 , V_53 -> V_97 , V_53 -> V_98 ) ;
for ( V_97 = 1 ; V_97 < V_102 ; ++ V_97 ) {
V_63 = F_70 ( V_2 , V_97 , V_53 -> V_98 ) ;
if ( V_63 < V_101 ) {
V_101 = V_63 ;
V_53 -> V_97 = V_97 ;
}
}
}
if ( V_101 + V_53 -> V_63 > 900 ) {
F_74 ( F_23 ( V_2 ) , L_4
L_5 ,
V_53 -> V_98 , V_53 -> V_97 , V_101 , V_53 -> V_63 ) ;
return - V_103 ;
}
return 0 ;
}
static void F_75 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
int V_104 ;
int V_63 = V_53 -> V_63 ;
char * V_105 = L_6 ;
for ( V_104 = V_53 -> V_97 ; V_104 < V_100 ; V_104 += V_53 -> V_98 ) {
V_2 -> V_63 [ V_104 ] += V_63 ;
V_2 -> V_106 += V_63 ;
}
F_3 ( V_2 ) -> V_107 . V_108 =
V_2 -> V_106 / V_100 ;
switch ( V_53 -> type ) {
case V_62 :
++ F_3 ( V_2 ) -> V_107 . V_109 ;
V_105 = L_7 ;
break;
case V_58 :
++ F_3 ( V_2 ) -> V_107 . V_110 ;
V_105 = L_8 ;
break;
}
V_53 -> V_111 = 1 ;
F_74 ( F_23 ( V_2 ) ,
L_9 ,
L_10 , V_53 -> V_50 -> V_112 ,
V_53 -> V_52 -> V_57 . V_113 , V_105 ,
V_53 -> V_98 , V_53 -> V_97 , V_63 ) ;
}
static void F_76 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
int V_104 ;
int V_63 = V_53 -> V_63 ;
char * V_105 = L_6 ;
for ( V_104 = V_53 -> V_97 ; V_104 < V_100 ; V_104 += V_53 -> V_98 ) {
V_2 -> V_63 [ V_104 ] -= V_63 ;
V_2 -> V_106 -= V_63 ;
}
F_3 ( V_2 ) -> V_107 . V_108 =
V_2 -> V_106 / V_100 ;
switch ( V_53 -> type ) {
case V_62 :
-- F_3 ( V_2 ) -> V_107 . V_109 ;
V_105 = L_7 ;
break;
case V_58 :
-- F_3 ( V_2 ) -> V_107 . V_110 ;
V_105 = L_8 ;
break;
}
V_53 -> V_111 = 0 ;
F_74 ( F_23 ( V_2 ) ,
L_9 ,
L_11 , V_53 -> V_50 -> V_112 ,
V_53 -> V_52 -> V_57 . V_113 , V_105 ,
V_53 -> V_98 , V_53 -> V_97 , V_63 ) ;
}
static inline struct V_18 * F_77 ( struct V_1 * V_2 ,
struct V_17 * V_17 )
{
struct V_18 * V_19 ;
V_19 = F_78 ( V_114 , V_34 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_17 = V_17 ;
V_17 -> V_20 = V_19 ;
F_19 ( & V_19 -> V_13 ) ;
F_19 ( & V_19 -> V_40 ) ;
return V_19 ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_30 * V_32 , * V_115 ;
if ( ! F_21 ( & V_19 -> V_13 ) )
F_22 ( F_23 ( V_2 ) , L_12 ,
V_19 -> V_17 ) ;
F_80 (td, tmp, &urbp->td_list, list) {
F_28 ( V_32 ) ;
F_20 ( V_2 , V_32 ) ;
}
F_81 ( V_114 , V_19 ) ;
}
static int F_82 ( int V_7 , int V_116 )
{
if ( ! V_7 )
return 0 ;
if ( V_7 & V_117 )
return - V_118 ;
if ( V_7 & V_119 ) {
if ( V_116 )
return - V_118 ;
else
return - V_120 ;
}
if ( V_7 & V_121 )
return - V_122 ;
if ( V_7 & V_123 )
return - V_124 ;
if ( V_7 & V_125 )
return - V_126 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_17 * V_17 ,
struct V_9 * V_53 )
{
struct V_30 * V_32 ;
unsigned long V_127 , V_7 ;
int V_128 = F_42 ( V_53 -> V_52 -> V_57 . V_65 ) ;
int V_129 = V_17 -> V_130 ;
T_1 V_131 = V_17 -> V_132 ;
T_3 * V_133 ;
struct V_18 * V_19 = V_17 -> V_20 ;
int V_82 ;
V_127 = ( V_17 -> V_77 & V_134 ) | V_135 ;
V_7 = F_84 ( 3 ) ;
if ( V_17 -> V_136 -> V_64 == V_137 )
V_7 |= V_138 ;
V_32 = V_53 -> V_59 ;
F_26 ( V_32 , V_19 ) ;
F_25 ( V_2 , V_32 , V_7 , V_127 | F_85 ( 8 ) ,
V_17 -> V_139 ) ;
V_133 = & V_32 -> V_15 ;
V_7 |= V_140 ;
if ( F_54 ( V_17 -> V_77 ) || V_129 == 0 )
V_127 ^= ( V_135 ^ V_141 ) ;
else {
V_127 ^= ( V_135 ^ V_142 ) ;
V_7 |= V_143 ;
}
while ( V_129 > 0 ) {
int V_144 = V_128 ;
if ( V_129 <= V_144 ) {
V_144 = V_129 ;
V_7 &= ~ V_143 ;
}
V_32 = F_17 ( V_2 ) ;
if ( ! V_32 )
goto V_145;
* V_133 = F_32 ( V_2 , V_32 ) ;
V_127 ^= V_78 ;
F_26 ( V_32 , V_19 ) ;
F_25 ( V_2 , V_32 , V_7 ,
V_127 | F_85 ( V_144 ) , V_131 ) ;
V_133 = & V_32 -> V_15 ;
V_131 += V_144 ;
V_129 -= V_144 ;
}
V_32 = F_17 ( V_2 ) ;
if ( ! V_32 )
goto V_145;
* V_133 = F_32 ( V_2 , V_32 ) ;
V_127 ^= ( V_142 ^ V_141 ) ;
V_127 |= V_78 ;
F_26 ( V_32 , V_19 ) ;
F_25 ( V_2 , V_32 , V_7 | V_8 ,
V_127 | F_85 ( 0 ) , 0 ) ;
V_133 = & V_32 -> V_15 ;
V_32 = F_17 ( V_2 ) ;
if ( ! V_32 )
goto V_145;
* V_133 = F_32 ( V_2 , V_32 ) ;
F_25 ( V_2 , V_32 , 0 , V_141 | F_85 ( 0 ) , 0 ) ;
F_31 () ;
V_53 -> V_59 -> V_7 |= F_4 ( V_2 , V_140 ) ;
V_53 -> V_59 = V_32 ;
if ( V_17 -> V_136 -> V_64 == V_137 ||
V_17 -> V_136 -> V_60 != V_146 )
V_82 = V_147 ;
else {
V_82 = V_148 ;
F_11 ( V_2 , V_17 ) ;
}
if ( V_53 -> V_60 != V_66 )
V_53 -> V_82 = V_82 ;
return 0 ;
V_145:
F_28 ( V_53 -> V_59 ) ;
return - V_149 ;
}
static int F_86 ( struct V_1 * V_2 , struct V_17 * V_17 ,
struct V_9 * V_53 )
{
struct V_30 * V_32 ;
unsigned long V_127 , V_7 ;
int V_128 = F_42 ( V_53 -> V_52 -> V_57 . V_65 ) ;
int V_129 = V_17 -> V_130 ;
int V_150 ;
T_1 V_131 ;
T_3 * V_133 ;
struct V_18 * V_19 = V_17 -> V_20 ;
unsigned int V_76 ;
struct V_151 * V_152 ;
int V_104 ;
if ( V_129 < 0 )
return - V_153 ;
V_127 = ( V_17 -> V_77 & V_134 ) | F_87 ( V_17 -> V_77 ) ;
V_76 = F_88 ( V_17 -> V_136 , F_53 ( V_17 -> V_77 ) ,
F_54 ( V_17 -> V_77 ) ) ;
V_7 = F_84 ( 3 ) ;
if ( V_17 -> V_136 -> V_64 == V_137 )
V_7 |= V_138 ;
if ( F_89 ( V_17 -> V_77 ) )
V_7 |= V_143 ;
V_104 = V_17 -> V_154 ;
if ( V_129 > 0 && V_104 > 0 ) {
V_152 = V_17 -> V_152 ;
V_131 = F_90 ( V_152 ) ;
V_150 = F_73 ( int , F_91 ( V_152 ) , V_129 ) ;
} else {
V_152 = NULL ;
V_131 = V_17 -> V_132 ;
V_150 = V_129 ;
}
V_133 = NULL ;
V_32 = V_53 -> V_59 ;
for (; ; ) {
int V_144 = V_128 ;
if ( V_129 <= V_144 ) {
V_144 = V_129 ;
if ( ! ( V_17 -> V_21 & V_155 ) )
V_7 &= ~ V_143 ;
}
if ( V_133 ) {
V_32 = F_17 ( V_2 ) ;
if ( ! V_32 )
goto V_145;
* V_133 = F_32 ( V_2 , V_32 ) ;
}
F_26 ( V_32 , V_19 ) ;
F_25 ( V_2 , V_32 , V_7 ,
V_127 | F_85 ( V_144 ) |
( V_76 << V_156 ) ,
V_131 ) ;
V_133 = & V_32 -> V_15 ;
V_7 |= V_140 ;
V_76 ^= 1 ;
V_131 += V_144 ;
V_150 -= V_144 ;
V_129 -= V_128 ;
if ( V_150 <= 0 ) {
if ( -- V_104 <= 0 || V_129 <= 0 )
break;
V_152 = F_92 ( V_152 ) ;
V_131 = F_90 ( V_152 ) ;
V_150 = F_73 ( int , F_91 ( V_152 ) , V_129 ) ;
}
}
if ( ( V_17 -> V_21 & V_157 ) &&
F_54 ( V_17 -> V_77 ) && V_129 == 0 &&
V_17 -> V_130 > 0 ) {
V_32 = F_17 ( V_2 ) ;
if ( ! V_32 )
goto V_145;
* V_133 = F_32 ( V_2 , V_32 ) ;
F_26 ( V_32 , V_19 ) ;
F_25 ( V_2 , V_32 , V_7 ,
V_127 | F_85 ( 0 ) |
( V_76 << V_156 ) ,
V_131 ) ;
V_133 = & V_32 -> V_15 ;
V_76 ^= 1 ;
}
V_32 -> V_7 |= F_4 ( V_2 , V_8 ) ;
V_32 = F_17 ( V_2 ) ;
if ( ! V_32 )
goto V_145;
* V_133 = F_32 ( V_2 , V_32 ) ;
F_25 ( V_2 , V_32 , 0 , V_141 | F_85 ( 0 ) , 0 ) ;
F_31 () ;
V_53 -> V_59 -> V_7 |= F_4 ( V_2 , V_140 ) ;
V_53 -> V_59 = V_32 ;
F_52 ( V_17 -> V_136 , F_53 ( V_17 -> V_77 ) ,
F_54 ( V_17 -> V_77 ) , V_76 ) ;
return 0 ;
V_145:
F_28 ( V_53 -> V_59 ) ;
return - V_149 ;
}
static int F_93 ( struct V_1 * V_2 , struct V_17 * V_17 ,
struct V_9 * V_53 )
{
int V_67 ;
if ( V_17 -> V_136 -> V_64 == V_137 )
return - V_153 ;
if ( V_53 -> V_60 != V_66 )
V_53 -> V_82 = V_158 ;
V_67 = F_86 ( V_2 , V_17 , V_53 ) ;
if ( V_67 == 0 )
F_11 ( V_2 , V_17 ) ;
return V_67 ;
}
static int F_94 ( struct V_1 * V_2 , struct V_17 * V_17 ,
struct V_9 * V_53 )
{
int V_67 ;
if ( ! V_53 -> V_111 ) {
int V_159 ;
for ( V_159 = 7 ; V_159 >= 0 ; -- V_159 ) {
if ( ( 1 << V_159 ) <= V_17 -> V_160 )
break;
}
if ( V_159 < 0 )
return - V_153 ;
do {
V_53 -> V_98 = 1 << V_159 ;
V_53 -> V_82 = F_95 ( V_159 ) ;
V_53 -> V_97 = ( V_53 -> V_98 / 2 ) & ( V_100 - 1 ) ;
V_67 = F_72 ( V_2 , V_53 ) ;
} while ( V_67 != 0 && -- V_159 >= 0 );
if ( V_67 )
return V_67 ;
} else if ( V_53 -> V_98 > V_17 -> V_160 )
return - V_153 ;
V_67 = F_86 ( V_2 , V_17 , V_53 ) ;
if ( V_67 == 0 ) {
V_17 -> V_160 = V_53 -> V_98 ;
if ( ! V_53 -> V_111 )
F_75 ( V_2 , V_53 ) ;
}
return V_67 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_9 * V_53 , struct V_18 * V_19 )
{
struct V_30 * V_32 ;
struct V_161 * V_115 ;
int V_67 ;
V_32 = F_7 ( V_19 -> V_40 . V_14 , struct V_30 , V_36 ) ;
if ( V_53 -> type == V_72 ) {
F_34 ( F_21 ( & V_19 -> V_40 ) ) ;
V_53 -> V_55 = F_32 ( V_2 , V_32 ) ;
V_115 = V_32 -> V_36 . V_14 ;
V_67 = - V_162 ;
} else {
V_53 -> V_74 =
F_47 ( F_48 ( V_2 , V_53 -> V_94 ) ) ^ 1 ;
F_49 ( V_2 , V_53 , 1 ) ;
if ( F_21 ( & V_19 -> V_40 ) )
V_32 = V_53 -> V_94 ;
V_53 -> V_55 = V_32 -> V_15 ;
V_115 = V_19 -> V_40 . V_14 ;
V_67 = 0 ;
}
while ( V_115 != & V_19 -> V_40 ) {
V_32 = F_7 ( V_115 , struct V_30 , V_36 ) ;
V_115 = V_115 -> V_14 ;
F_28 ( V_32 ) ;
F_20 ( V_2 , V_32 ) ;
}
return V_67 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_17 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_9 * V_53 = V_19 -> V_53 ;
struct V_30 * V_32 , * V_115 ;
unsigned V_7 ;
int V_67 = 0 ;
F_80 (td, tmp, &urbp->td_list, list) {
unsigned int V_163 ;
int V_129 ;
V_163 = F_98 ( V_2 , V_32 ) ;
V_7 = F_99 ( V_163 ) ;
if ( V_7 & V_140 )
return - V_162 ;
V_129 = F_100 ( V_163 ) ;
V_17 -> V_164 += V_129 ;
if ( V_7 ) {
V_67 = F_82 ( V_7 ,
F_101 ( F_48 ( V_2 , V_32 ) ) ) ;
if ( ( V_165 == 1 && V_67 != - V_126 ) || V_165 > 1 ) {
F_74 ( & V_17 -> V_136 -> V_136 ,
L_13 ,
V_166 , V_7 ) ;
if ( V_165 > 1 && V_167 ) {
F_102 ( V_2 , V_19 -> V_53 , V_167 ,
V_168 , 0 ) ;
F_103 ( V_167 ) ;
}
}
} else if ( V_129 < F_104 ( F_48 ( V_2 , V_32 ) ) ) {
if ( V_53 -> type == V_72 ) {
if ( V_32 -> V_36 . V_47 != V_19 -> V_40 . V_14 )
V_67 = 1 ;
}
else if ( V_17 -> V_21 & V_155 )
V_67 = - V_169 ;
else if ( & V_32 -> V_36 != V_19 -> V_40 . V_14 )
V_67 = 1 ;
}
F_28 ( V_32 ) ;
if ( V_53 -> V_94 )
F_20 ( V_2 , V_53 -> V_94 ) ;
V_53 -> V_94 = V_32 ;
if ( V_67 != 0 )
goto V_170;
}
return V_67 ;
V_170:
if ( V_67 < 0 ) {
V_53 -> V_55 = F_10 ( V_2 ) ;
V_53 -> V_3 = 1 ;
V_53 -> V_73 = ( V_53 -> type != V_72 ) ;
V_53 -> V_74 = F_47 ( F_48 ( V_2 , V_32 ) ) ^
( V_67 == - V_169 ) ;
} else
V_67 = F_96 ( V_2 , V_53 , V_19 ) ;
return V_67 ;
}
static int F_105 ( struct V_1 * V_2 , struct V_17 * V_17 ,
struct V_9 * V_53 )
{
struct V_30 * V_32 = NULL ;
int V_104 , V_35 ;
unsigned long V_127 , V_7 ;
struct V_18 * V_19 = (struct V_18 * ) V_17 -> V_20 ;
if ( V_17 -> V_160 >= V_42 ||
V_17 -> V_171 >= V_42 )
return - V_172 ;
if ( ! V_53 -> V_111 ) {
V_53 -> V_98 = V_17 -> V_160 ;
if ( V_17 -> V_21 & V_173 ) {
V_53 -> V_97 = - 1 ;
V_104 = F_72 ( V_2 , V_53 ) ;
if ( V_104 )
return V_104 ;
F_65 ( V_2 ) ;
V_35 = V_2 -> V_68 + 10 ;
V_17 -> V_174 = V_35 + ( ( V_53 -> V_97 - V_35 ) &
( V_53 -> V_98 - 1 ) ) ;
} else {
V_104 = V_17 -> V_174 - V_2 -> V_175 ;
if ( V_104 <= 0 || V_104 >= V_42 )
return - V_153 ;
V_53 -> V_97 = V_17 -> V_174 & ( V_53 -> V_98 - 1 ) ;
V_104 = F_72 ( V_2 , V_53 ) ;
if ( V_104 )
return V_104 ;
}
} else if ( V_53 -> V_98 != V_17 -> V_160 ) {
return - V_153 ;
} else {
if ( F_21 ( & V_53 -> V_56 ) ) {
V_35 = V_53 -> V_176 ;
} else {
struct V_17 * V_177 ;
V_177 = F_7 ( V_53 -> V_56 . V_14 ,
struct V_18 , V_13 ) -> V_17 ;
V_35 = V_177 -> V_174 +
V_177 -> V_171 *
V_177 -> V_160 ;
}
if ( V_17 -> V_21 & V_173 ) {
F_65 ( V_2 ) ;
if ( F_106 ( V_35 , V_2 -> V_68 ) ) {
V_35 = V_2 -> V_68 + 1 ;
V_35 += ( ( V_53 -> V_97 - V_35 ) &
( V_53 -> V_98 - 1 ) ) ;
}
}
V_17 -> V_174 = V_35 ;
}
if ( F_106 ( V_2 -> V_175 + V_42 ,
V_17 -> V_174 + V_17 -> V_171 *
V_17 -> V_160 ) )
return - V_172 ;
V_7 = V_140 | V_178 ;
V_127 = ( V_17 -> V_77 & V_134 ) | F_87 ( V_17 -> V_77 ) ;
for ( V_104 = 0 ; V_104 < V_17 -> V_171 ; V_104 ++ ) {
V_32 = F_17 ( V_2 ) ;
if ( ! V_32 )
return - V_149 ;
F_26 ( V_32 , V_19 ) ;
F_25 ( V_2 , V_32 , V_7 , V_127 |
F_85 ( V_17 -> V_179 [ V_104 ] . V_180 ) ,
V_17 -> V_132 +
V_17 -> V_179 [ V_104 ] . V_181 ) ;
}
V_32 -> V_7 |= F_4 ( V_2 , V_8 ) ;
V_35 = V_17 -> V_174 ;
F_37 (td, &urbp->td_list, list) {
F_30 ( V_2 , V_32 , V_35 ) ;
V_35 += V_53 -> V_98 ;
}
if ( F_21 ( & V_53 -> V_56 ) ) {
V_53 -> V_182 = & V_17 -> V_179 [ 0 ] ;
V_53 -> V_176 = V_17 -> V_174 ;
}
V_53 -> V_82 = V_88 ;
if ( ! V_53 -> V_111 )
F_75 ( V_2 , V_53 ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 , struct V_17 * V_17 )
{
struct V_30 * V_32 , * V_115 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_9 * V_53 = V_19 -> V_53 ;
F_80 (td, tmp, &urbp->td_list, list) {
unsigned int V_163 ;
int V_7 ;
int V_183 ;
if ( F_106 ( V_2 -> V_184 , V_53 -> V_176 ) )
return - V_162 ;
F_35 ( V_2 , V_53 -> V_176 ) ;
V_163 = F_98 ( V_2 , V_32 ) ;
if ( V_163 & V_140 ) {
V_7 = - V_185 ;
} else {
V_7 = F_82 ( F_99 ( V_163 ) ,
F_54 ( V_17 -> V_77 ) ) ;
V_183 = F_100 ( V_163 ) ;
V_17 -> V_164 += V_183 ;
V_53 -> V_182 -> V_164 = V_183 ;
V_53 -> V_182 -> V_7 = V_7 ;
}
if ( V_7 )
V_17 -> V_186 ++ ;
F_28 ( V_32 ) ;
F_20 ( V_2 , V_32 ) ;
V_53 -> V_176 += V_53 -> V_98 ;
++ V_53 -> V_182 ;
}
return 0 ;
}
static int F_108 ( struct V_187 * V_188 ,
struct V_17 * V_17 , T_4 V_189 )
{
int V_67 ;
struct V_1 * V_2 = F_109 ( V_188 ) ;
unsigned long V_28 ;
struct V_18 * V_19 ;
struct V_9 * V_53 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
V_67 = F_110 ( V_188 , V_17 ) ;
if ( V_67 )
goto V_190;
V_67 = - V_149 ;
V_19 = F_77 ( V_2 , V_17 ) ;
if ( ! V_19 )
goto V_70;
if ( V_17 -> V_191 -> V_20 )
V_53 = V_17 -> V_191 -> V_20 ;
else {
V_53 = F_38 ( V_2 , V_17 -> V_136 , V_17 -> V_191 ) ;
if ( ! V_53 )
goto V_192;
}
V_19 -> V_53 = V_53 ;
switch ( V_53 -> type ) {
case V_72 :
V_67 = F_83 ( V_2 , V_17 , V_53 ) ;
break;
case V_193 :
V_67 = F_93 ( V_2 , V_17 , V_53 ) ;
break;
case V_62 :
V_67 = F_94 ( V_2 , V_17 , V_53 ) ;
break;
case V_58 :
V_17 -> V_186 = 0 ;
V_67 = F_105 ( V_2 , V_17 , V_53 ) ;
break;
}
if ( V_67 != 0 )
goto V_194;
F_27 ( & V_19 -> V_13 , & V_53 -> V_56 ) ;
if ( V_53 -> V_56 . V_47 == & V_19 -> V_13 && ! V_53 -> V_3 ) {
F_60 ( V_2 , V_53 ) ;
F_12 ( V_2 , V_19 ) ;
}
goto V_70;
V_194:
if ( V_53 -> V_60 == V_61 )
F_67 ( V_2 , V_53 ) ;
V_192:
F_79 ( V_2 , V_19 ) ;
V_70:
if ( V_67 )
F_111 ( V_188 , V_17 ) ;
V_190:
F_16 ( & V_2 -> V_29 , V_28 ) ;
return V_67 ;
}
static int F_112 ( struct V_187 * V_188 , struct V_17 * V_17 , int V_7 )
{
struct V_1 * V_2 = F_109 ( V_188 ) ;
unsigned long V_28 ;
struct V_9 * V_53 ;
int V_195 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
V_195 = F_113 ( V_188 , V_17 , V_7 ) ;
if ( V_195 )
goto V_70;
V_53 = ( (struct V_18 * ) V_17 -> V_20 ) -> V_53 ;
if ( V_53 -> type == V_58 ) {
F_36 ( V_2 , V_17 ) ;
F_62 () ;
F_65 ( V_2 ) ;
if ( F_106 ( V_17 -> V_174 , V_2 -> V_68 ) )
V_53 -> V_69 = V_2 -> V_68 ;
}
F_64 ( V_2 , V_53 ) ;
V_70:
F_16 ( & V_2 -> V_29 , V_28 ) ;
return V_195 ;
}
static void F_114 ( struct V_1 * V_2 , struct V_9 * V_53 ,
struct V_17 * V_17 , int V_7 )
__releases( V_2 -> V_29 )
__acquires( V_2 -> V_29 )
{
struct V_18 * V_19 = (struct V_18 * ) V_17 -> V_20 ;
if ( V_53 -> type == V_72 ) {
V_17 -> V_164 -= F_73 ( T_2 , 8 , V_17 -> V_164 ) ;
}
else if ( V_53 -> type == V_58 &&
V_19 -> V_13 . V_14 == & V_53 -> V_56 &&
V_19 -> V_13 . V_47 != & V_53 -> V_56 ) {
struct V_17 * V_196 = F_7 ( V_19 -> V_13 . V_47 ,
struct V_18 , V_13 ) -> V_17 ;
V_53 -> V_182 = & V_196 -> V_179 [ 0 ] ;
V_53 -> V_176 = V_196 -> V_174 ;
}
F_29 ( & V_19 -> V_13 ) ;
if ( F_21 ( & V_53 -> V_56 ) && V_53 -> V_73 ) {
F_52 ( V_17 -> V_136 , F_53 ( V_17 -> V_77 ) ,
F_54 ( V_17 -> V_77 ) , V_53 -> V_74 ) ;
V_53 -> V_73 = 0 ;
}
F_79 ( V_2 , V_19 ) ;
F_111 ( F_3 ( V_2 ) , V_17 ) ;
F_115 ( & V_2 -> V_29 ) ;
F_116 ( F_3 ( V_2 ) , V_17 , V_7 ) ;
F_117 ( & V_2 -> V_29 ) ;
if ( F_21 ( & V_53 -> V_56 ) ) {
F_64 ( V_2 , V_53 ) ;
if ( V_53 -> V_111 )
F_76 ( V_2 , V_53 ) ;
}
}
static void F_118 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
struct V_18 * V_19 ;
struct V_17 * V_17 ;
int V_7 ;
while ( ! F_21 ( & V_53 -> V_56 ) ) {
V_19 = F_7 ( V_53 -> V_56 . V_47 , struct V_18 , V_13 ) ;
V_17 = V_19 -> V_17 ;
if ( V_53 -> type == V_58 )
V_7 = F_107 ( V_2 , V_17 ) ;
else
V_7 = F_97 ( V_2 , V_17 ) ;
if ( V_7 == - V_162 )
break;
if ( V_17 -> V_197 ) {
if ( F_119 ( V_53 ) )
V_53 -> V_3 = 1 ;
else if ( ! V_53 -> V_3 )
return;
}
F_114 ( V_2 , V_53 , V_17 , V_7 ) ;
if ( V_7 < 0 )
break;
}
if ( F_119 ( V_53 ) )
V_53 -> V_3 = 1 ;
else if ( ! V_53 -> V_3 )
return;
V_198:
F_37 (urbp, &qh->queue, node) {
V_17 = V_19 -> V_17 ;
if ( V_17 -> V_197 ) {
if ( ! F_45 ( V_2 , V_53 , V_17 ) ) {
V_53 -> V_3 = 0 ;
return;
}
F_114 ( V_2 , V_53 , V_17 , 0 ) ;
goto V_198;
}
}
V_53 -> V_3 = 0 ;
if ( ! F_21 ( & V_53 -> V_56 ) ) {
if ( V_53 -> V_73 )
F_49 ( V_2 , V_53 , 0 ) ;
V_19 = F_7 ( V_53 -> V_56 . V_47 , struct V_18 , V_13 ) ;
if ( V_19 -> V_23 && V_53 -> V_85 ) {
struct V_30 * V_32 = F_7 ( V_19 -> V_40 . V_47 ,
struct V_30 , V_36 ) ;
V_32 -> V_7 |= F_4 ( V_2 , V_8 ) ;
}
F_60 ( V_2 , V_53 ) ;
}
else if ( F_119 ( V_53 ) )
F_67 ( V_2 , V_53 ) ;
}
static int F_120 ( struct V_1 * V_2 , struct V_9 * V_53 )
{
struct V_18 * V_19 = NULL ;
struct V_30 * V_32 ;
int V_67 = 1 ;
unsigned V_7 ;
if ( V_53 -> type == V_58 )
goto V_70;
if ( V_53 -> V_60 != V_66 ) {
V_19 = NULL ;
V_7 = 0 ;
} else {
V_19 = F_7 ( V_53 -> V_56 . V_47 , struct V_18 , V_13 ) ;
V_32 = F_7 ( V_19 -> V_40 . V_47 , struct V_30 , V_36 ) ;
V_7 = F_98 ( V_2 , V_32 ) ;
if ( ! ( V_7 & V_140 ) ) {
V_53 -> V_85 = 0 ;
V_53 -> V_86 = V_5 ;
goto V_70;
}
V_67 = V_2 -> V_3 ;
}
if ( V_53 -> V_85 )
goto V_70;
if ( F_121 ( V_5 , V_53 -> V_86 + V_199 ) ) {
if ( V_53 -> V_94 && F_46 ( V_53 ) ==
F_32 ( V_2 , V_53 -> V_94 ) ) {
V_53 -> V_55 = V_53 -> V_94 -> V_15 ;
V_53 -> V_86 = V_5 ;
V_67 = 1 ;
goto V_70;
}
V_53 -> V_85 = 1 ;
if ( V_19 && V_19 -> V_23 && ! ( V_7 & V_8 ) )
F_64 ( V_2 , V_53 ) ;
} else {
if ( V_19 )
F_12 ( V_2 , V_19 ) ;
}
V_70:
return V_67 ;
}
static void F_122 ( struct V_1 * V_2 )
{
int V_104 ;
struct V_9 * V_53 ;
if ( V_2 -> V_200 ) {
V_2 -> V_201 = 1 ;
return;
}
V_2 -> V_200 = 1 ;
V_202:
V_2 -> V_201 = 0 ;
V_2 -> V_24 = 0 ;
F_5 ( V_2 ) ;
F_65 ( V_2 ) ;
V_2 -> V_184 = V_2 -> V_68 ;
for ( V_104 = 0 ; V_104 < V_203 - 1 ; ++ V_104 ) {
V_2 -> V_87 = F_7 ( V_2 -> V_81 [ V_104 ] -> V_13 . V_47 ,
struct V_9 , V_13 ) ;
while ( ( V_53 = V_2 -> V_87 ) != V_2 -> V_81 [ V_104 ] ) {
V_2 -> V_87 = F_7 ( V_53 -> V_13 . V_47 ,
struct V_9 , V_13 ) ;
if ( F_120 ( V_2 , V_53 ) ) {
F_118 ( V_2 , V_53 ) ;
if ( V_53 -> V_60 == V_66 ) {
F_12 ( V_2 ,
F_7 ( V_53 -> V_56 . V_47 , struct V_18 , V_13 ) ) ;
}
}
}
}
V_2 -> V_175 = V_2 -> V_184 ;
if ( V_2 -> V_201 )
goto V_202;
V_2 -> V_200 = 0 ;
if ( V_2 -> V_11 && ! V_2 -> V_24 &&
! V_2 -> V_25 ) {
V_2 -> V_25 = 1 ;
F_2 ( & V_2 -> V_26 , V_5 + V_204 ) ;
}
if ( F_21 ( & V_2 -> V_92 -> V_13 ) )
F_5 ( V_2 ) ;
else
F_1 ( V_2 ) ;
}
