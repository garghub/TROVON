void F_1 ( T_1 V_1 [ V_2 ] , const struct V_3 * V_4 )
{
F_2 ( V_1 , V_4 , false , true ) ;
}
int F_3 ( struct V_5 * V_6 , T_1 * V_7 , struct V_3 * V_4 ,
T_2 V_8 , void * V_9 , unsigned V_10 )
{
struct V_11 * V_12 = F_4 ( V_6 , V_13 ) ;
int V_14 ;
if ( F_5 ( ! V_12 ) ) {
F_6 ( L_1 , V_15 ) ;
return - V_16 ;
}
V_14 = F_7 ( V_12 , V_4 , V_8 , V_9 , V_10 ) ;
if ( F_5 ( V_14 ) ) {
F_6 ( L_2 , V_15 ) ;
goto V_17;
}
V_14 = F_8 ( V_12 , 0 , V_7 , NULL ) ;
if ( F_5 ( V_14 ) ) {
F_6 ( L_3 , V_14 ) ;
goto V_17;
}
V_14 = F_9 ( V_12 ) ;
if ( F_5 ( V_14 ) )
F_6 ( L_4 , V_14 ) ;
V_17:
F_10 ( V_12 ) ;
return V_14 ;
}
int F_11 ( struct V_18 * V_19 ,
struct V_20 * * V_21 )
{
struct V_20 * V_22 ;
V_22 = F_12 ( F_13 ( V_19 -> V_23 ) , V_13 ) ;
if ( F_5 ( ! V_22 ) ) {
F_6 ( L_5 ,
F_13 ( V_19 -> V_23 ) ) ;
* V_21 = NULL ;
return - V_16 ;
}
V_22 -> V_19 = V_19 ;
V_22 -> V_4 . V_24 = V_19 -> V_25 ;
* V_21 = V_22 ;
return 0 ;
}
void F_14 ( struct V_20 * V_22 )
{
if ( V_22 ) {
unsigned V_26 ;
for ( V_26 = 0 ; V_26 < V_22 -> V_27 ; V_26 ++ ) {
struct V_28 * V_29 = & V_22 -> V_29 [ V_26 ] ;
if ( V_29 -> V_12 )
F_10 ( V_29 -> V_12 ) ;
if ( V_29 -> V_30 )
F_15 ( V_29 -> V_30 ) ;
}
F_16 ( V_22 ) ;
}
}
unsigned F_17 ( struct V_18 * V_19 ,
T_3 V_31 , unsigned V_32 )
{
unsigned V_33 = V_31 ;
return ( V_32 + V_33 * V_19 -> V_34 ) %
V_19 -> V_23 ;
}
static inline struct V_5 * F_18 ( struct V_20 * V_22 ,
unsigned V_32 )
{
return V_22 -> V_19 -> V_35 [
F_17 ( V_22 -> V_19 , V_22 -> V_4 . V_36 , V_32 ) ] ;
}
static void F_19 ( struct V_20 * V_22 , void * V_9 )
{
struct V_37 * V_38 = V_9 ;
F_20 ( V_38 ) ;
}
static void F_21 ( struct V_39 * V_39 )
{
struct V_20 * V_22 = F_22 (
V_39 , struct V_20 , V_39 ) ;
V_22 -> V_40 ( V_22 , V_22 -> V_41 ) ;
}
static void F_23 ( struct V_11 * V_12 , void * V_9 )
{
struct V_20 * V_22 = V_9 ;
F_24 ( & V_22 -> V_39 , F_21 ) ;
}
static int F_25 ( struct V_20 * V_22 )
{
F_26 ( V_42 ) ;
bool V_43 = ( V_22 -> V_40 == NULL ) ;
int V_26 , V_14 ;
if ( V_43 ) {
V_22 -> V_40 = F_19 ;
V_22 -> V_41 = & V_42 ;
}
for ( V_26 = 0 ; V_26 < V_22 -> V_27 ; V_26 ++ ) {
struct V_11 * V_12 = V_22 -> V_29 [ V_26 ] . V_12 ;
if ( F_5 ( ! V_12 ) )
continue;
V_14 = F_8 ( V_12 , 0 , V_22 -> V_7 , NULL ) ;
if ( F_5 ( V_14 ) ) {
F_6 ( L_3 ,
V_14 ) ;
return V_14 ;
}
}
F_27 ( & V_22 -> V_39 ) ;
for ( V_26 = 0 ; V_26 < V_22 -> V_27 ; V_26 ++ ) {
struct V_11 * V_12 = V_22 -> V_29 [ V_26 ] . V_12 ;
if ( F_5 ( ! V_12 ) )
continue;
F_28 ( & V_22 -> V_39 ) ;
F_29 ( V_12 , F_23 , V_22 ) ;
}
F_24 ( & V_22 -> V_39 , F_21 ) ;
V_14 = 0 ;
if ( V_43 ) {
F_30 ( & V_42 ) ;
V_14 = F_31 ( V_22 , NULL ) ;
}
return V_14 ;
}
static void F_32 ( struct V_30 * V_30 )
{
struct V_44 * V_45 ;
unsigned V_26 ;
F_33 (bv, bio, i, 0 ) {
unsigned V_46 = V_45 -> V_47 ;
if ( F_34 ( V_48 == V_46 ) )
F_35 ( V_45 -> V_49 ) ;
else
F_36 ( V_45 -> V_49 , V_45 -> V_50 , V_46 ) ;
}
}
int F_31 ( struct V_20 * V_22 , T_2 * V_51 )
{
enum V_52 V_53 = 0 ;
int V_54 = 0 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_22 -> V_27 ; V_26 ++ ) {
struct V_55 V_56 ;
struct V_11 * V_12 = V_22 -> V_29 [ V_26 ] . V_12 ;
int V_14 ;
if ( F_5 ( ! V_12 ) )
continue;
V_14 = F_37 ( V_12 , & V_56 ) ;
if ( F_34 ( ! V_14 ) )
continue;
if ( V_57 == V_56 . V_58 ) {
F_32 ( V_22 -> V_29 [ V_26 ] . V_30 ) ;
F_6 ( L_6
L_7 ,
F_38 ( V_22 -> V_29 [ V_26 ] . V_8 ) ,
F_38 ( V_22 -> V_29 [ V_26 ] . V_10 ) ) ;
continue;
}
if ( V_56 . V_58 >= V_53 ) {
V_53 = V_56 . V_58 ;
V_54 = V_14 ;
}
}
if ( V_51 ) {
if ( F_34 ( ! V_54 ) )
* V_51 = 0 ;
else
* V_51 = V_22 -> V_10 ;
}
return V_54 ;
}
static void F_39 ( struct V_20 * V_22 , T_2 V_59 ,
struct V_60 * V_61 )
{
T_4 V_62 = V_22 -> V_19 -> V_62 ;
T_4 V_63 = V_22 -> V_19 -> V_63 ;
T_2 V_64 = V_22 -> V_19 -> V_64 ;
T_4 V_65 = V_62 * V_63 ;
T_2 V_66 = V_65 * V_64 ;
T_2 V_67 = V_66 * V_22 -> V_19 -> V_68 ;
T_2 V_69 = F_40 ( V_59 , V_67 ) ;
T_2 V_70 = V_59 - V_69 * V_67 ;
T_4 V_71 = F_40 ( V_70 , V_66 ) ;
T_2 V_72 = V_70 - V_71 * V_66 ;
T_4 V_73 = F_41 ( V_72 , V_65 ) ;
V_61 -> V_74 = ( T_4 ) ( V_72 - ( V_73 * V_65 ) ) / V_62 + V_71 * V_63 ;
V_61 -> V_74 *= V_22 -> V_19 -> V_34 ;
F_42 ( V_59 , V_62 , & V_61 -> V_75 ) ;
V_61 -> V_76 = V_61 -> V_75 + ( V_73 * V_62 ) +
( V_69 * V_64 * V_62 ) ;
V_61 -> V_77 = V_66 - V_72 ;
}
static int F_43 ( struct V_20 * V_22 , unsigned * V_78 ,
unsigned V_79 , struct V_28 * V_29 ,
int V_80 )
{
unsigned V_81 = * V_78 ;
struct V_82 * V_83 =
F_44 ( F_18 ( V_22 , V_29 -> V_74 ) ) ;
V_29 -> V_10 += V_80 ;
if ( V_29 -> V_30 == NULL ) {
unsigned V_84 = V_22 -> V_19 -> V_63 *
( V_22 -> V_19 -> V_62 / V_48 ) ;
unsigned V_85 = ( V_22 -> V_86 + V_84 ) /
V_22 -> V_19 -> V_63 ;
V_29 -> V_30 = F_45 ( V_13 , V_85 ) ;
if ( F_5 ( ! V_29 -> V_30 ) ) {
F_6 ( L_8 ,
V_85 ) ;
return - V_16 ;
}
}
while ( V_80 > 0 ) {
unsigned V_87 = F_46 ( unsigned , V_48 - V_79 , V_80 ) ;
unsigned V_88 ;
F_47 ( V_22 -> V_86 <= V_81 ) ;
V_80 -= V_87 ;
V_88 = F_48 ( V_83 , V_29 -> V_30 , V_22 -> V_89 [ V_81 ] ,
V_87 , V_79 ) ;
if ( F_5 ( V_87 != V_88 ) )
return - V_16 ;
V_79 = 0 ;
++ V_81 ;
}
F_47 ( V_80 ) ;
* V_78 = V_81 ;
return 0 ;
}
static int F_49 ( struct V_20 * V_22 , T_2 V_10 ,
struct V_60 * V_61 )
{
unsigned V_62 = V_22 -> V_19 -> V_62 ;
unsigned V_34 = V_22 -> V_19 -> V_34 ;
unsigned V_90 = V_22 -> V_19 -> V_63 * V_34 ;
unsigned V_74 = V_61 -> V_74 ;
unsigned V_91 = V_74 - ( V_74 % V_90 ) ;
unsigned V_92 = V_22 -> V_27 ? V_22 -> V_27 - V_34 : 0 ;
unsigned V_78 = V_22 -> V_93 ;
int V_14 = 0 ;
while ( V_10 ) {
struct V_28 * V_29 = & V_22 -> V_29 [ V_74 ] ;
unsigned V_80 , V_94 = 0 ;
if ( ! V_29 -> V_10 ) {
V_29 -> V_74 = V_74 ;
if ( V_74 < V_61 -> V_74 ) {
V_29 -> V_8 = V_61 -> V_76 + V_62 -
V_61 -> V_75 ;
V_80 = V_62 ;
} else if ( V_74 == V_61 -> V_74 ) {
V_29 -> V_8 = V_61 -> V_76 ;
V_80 = V_62 - V_61 -> V_75 ;
V_94 = V_61 -> V_75 & ~ V_95 ;
F_47 ( V_94 && ( V_94 != V_22 -> V_79 ) ) ;
} else {
V_29 -> V_8 = V_61 -> V_76 - V_61 -> V_75 ;
V_80 = V_62 ;
}
if ( V_92 < V_74 )
V_92 = V_74 ;
} else {
V_80 = V_62 ;
}
if ( V_80 >= V_10 )
V_80 = V_10 ;
V_14 = F_43 ( V_22 , & V_78 , V_94 , V_29 ,
V_80 ) ;
if ( F_5 ( V_14 ) )
goto V_17;
V_74 += V_34 ;
V_74 = ( V_74 % V_90 ) + V_91 ;
V_10 -= V_80 ;
}
V_17:
V_22 -> V_27 = V_92 + V_34 ;
V_22 -> V_93 = V_78 ;
return V_14 ;
}
static int F_50 ( struct V_20 * V_22 )
{
T_2 V_10 = V_22 -> V_10 ;
T_2 V_8 = V_22 -> V_8 ;
struct V_60 V_61 ;
int V_14 = 0 ;
if ( ! V_22 -> V_89 ) {
if ( V_22 -> V_96 ) {
struct V_28 * V_29 = & V_22 -> V_29 [ 0 ] ;
F_39 ( V_22 , V_22 -> V_8 , & V_61 ) ;
V_29 -> V_8 = V_61 . V_76 ;
V_29 -> V_74 = V_61 . V_74 ;
F_47 ( ( V_22 -> V_19 -> V_63 > 1 ) &&
( V_61 . V_75 + V_22 -> V_10 >
V_22 -> V_19 -> V_62 ) ) ;
}
V_22 -> V_27 = V_22 -> V_19 -> V_34 ;
return 0 ;
}
while ( V_10 ) {
F_39 ( V_22 , V_8 , & V_61 ) ;
if ( V_10 < V_61 . V_77 )
V_61 . V_77 = V_10 ;
V_14 = F_49 ( V_22 , V_61 . V_77 , & V_61 ) ;
if ( F_5 ( V_14 ) )
goto V_17;
V_8 += V_61 . V_77 ;
V_10 -= V_61 . V_77 ;
}
V_17:
return V_14 ;
}
int F_51 ( struct V_20 * V_22 )
{
int V_26 , V_14 ;
for ( V_26 = 0 ; V_26 < V_22 -> V_19 -> V_23 ; V_26 ++ ) {
struct V_11 * V_12 ;
V_12 = F_4 ( F_18 ( V_22 , V_26 ) , V_13 ) ;
if ( F_5 ( ! V_12 ) ) {
F_52 ( L_9 , V_15 ) ;
V_14 = - V_16 ;
goto V_17;
}
V_22 -> V_29 [ V_26 ] . V_12 = V_12 ;
V_22 -> V_27 ++ ;
F_53 ( V_12 , & V_22 -> V_4 ) ;
}
V_14 = F_25 ( V_22 ) ;
V_17:
return V_14 ;
}
int F_54 ( struct V_20 * V_22 )
{
int V_26 , V_14 ;
for ( V_26 = 0 ; V_26 < V_22 -> V_19 -> V_23 ; V_26 ++ ) {
struct V_11 * V_12 ;
V_12 = F_4 ( F_18 ( V_22 , V_26 ) , V_13 ) ;
if ( F_5 ( ! V_12 ) ) {
F_52 ( L_9 , V_15 ) ;
V_14 = - V_16 ;
goto V_17;
}
V_22 -> V_29 [ V_26 ] . V_12 = V_12 ;
V_22 -> V_27 ++ ;
F_55 ( V_12 , & V_22 -> V_4 ) ;
}
V_14 = F_25 ( V_22 ) ;
V_17:
return V_14 ;
}
static int F_56 ( struct V_20 * V_22 , int V_97 )
{
struct V_28 * V_98 = & V_22 -> V_29 [ V_97 ] ;
unsigned V_74 = V_22 -> V_29 [ V_97 ] . V_74 ;
unsigned V_99 = V_97 + V_22 -> V_19 -> V_34 ;
int V_14 = 0 ;
if ( V_22 -> V_89 && ! V_98 -> V_10 )
return 0 ;
for (; V_97 < V_99 ; ++ V_97 , ++ V_74 ) {
struct V_28 * V_29 = & V_22 -> V_29 [ V_97 ] ;
struct V_11 * V_12 ;
V_12 = F_4 ( F_18 ( V_22 , V_74 ) , V_13 ) ;
if ( F_5 ( ! V_12 ) ) {
F_52 ( L_9 , V_15 ) ;
V_14 = - V_16 ;
goto V_17;
}
V_29 -> V_12 = V_12 ;
V_29 -> V_8 = V_98 -> V_8 ;
if ( V_22 -> V_89 ) {
struct V_30 * V_30 ;
if ( V_29 != V_98 ) {
V_30 = F_45 ( V_13 ,
V_98 -> V_30 -> V_100 ) ;
if ( F_5 ( ! V_30 ) ) {
F_6 (
L_8 ,
V_98 -> V_30 -> V_100 ) ;
V_14 = - V_16 ;
goto V_17;
}
F_57 ( V_30 , V_98 -> V_30 ) ;
V_30 -> V_101 = NULL ;
V_30 -> V_102 = NULL ;
V_29 -> V_10 = V_98 -> V_10 ;
V_29 -> V_30 = V_30 ;
V_29 -> V_74 = V_74 ;
} else {
V_30 = V_98 -> V_30 ;
V_30 -> V_103 |= V_104 ;
}
F_58 ( V_12 , & V_22 -> V_4 , V_29 -> V_8 , V_30 ,
V_29 -> V_10 ) ;
F_6 ( L_10
L_11 ,
F_38 ( V_22 -> V_4 . V_36 ) , F_38 ( V_29 -> V_8 ) ,
F_38 ( V_29 -> V_10 ) , V_74 ) ;
} else if ( V_22 -> V_96 ) {
V_14 = F_59 ( V_12 , & V_22 -> V_4 , V_29 -> V_8 ,
V_22 -> V_96 , V_22 -> V_10 ) ;
if ( F_5 ( V_14 ) )
goto V_17;
F_60 ( L_12
L_11 ,
F_38 ( V_22 -> V_4 . V_36 ) , F_38 ( V_29 -> V_8 ) ,
F_38 ( V_22 -> V_10 ) , V_74 ) ;
} else {
F_61 ( V_12 , & V_22 -> V_4 ) ;
F_60 ( L_13 ,
F_38 ( V_22 -> V_4 . V_36 ) , V_22 -> V_105 , V_74 ) ;
}
if ( V_22 -> V_106 )
F_62 ( V_12 , V_22 -> V_106 ,
V_22 -> V_105 ) ;
if ( V_22 -> V_107 )
F_63 ( V_12 , V_22 -> V_107 ,
V_22 -> V_108 ) ;
}
V_17:
return V_14 ;
}
int F_64 ( struct V_20 * V_22 )
{
int V_26 ;
int V_14 ;
V_14 = F_50 ( V_22 ) ;
if ( F_5 ( V_14 ) )
return V_14 ;
for ( V_26 = 0 ; V_26 < V_22 -> V_27 ; V_26 += V_22 -> V_19 -> V_34 ) {
V_14 = F_56 ( V_22 , V_26 ) ;
if ( F_5 ( V_14 ) )
return V_14 ;
}
V_14 = F_25 ( V_22 ) ;
return V_14 ;
}
static int F_65 ( struct V_20 * V_22 , unsigned V_97 )
{
struct V_11 * V_12 ;
struct V_28 * V_29 = & V_22 -> V_29 [ V_97 ] ;
unsigned V_91 = ( unsigned ) V_22 -> V_4 . V_36 ;
if ( V_22 -> V_89 && ! V_29 -> V_10 )
return 0 ;
V_91 = V_29 -> V_74 + V_91 % V_22 -> V_19 -> V_34 ;
V_12 = F_4 ( F_18 ( V_22 , V_91 ) , V_13 ) ;
if ( F_5 ( ! V_12 ) ) {
F_52 ( L_9 , V_15 ) ;
return - V_16 ;
}
V_29 -> V_12 = V_12 ;
if ( V_22 -> V_89 ) {
F_66 ( V_12 , & V_22 -> V_4 , V_29 -> V_8 ,
V_29 -> V_30 , V_29 -> V_10 ) ;
F_6 ( L_14
L_15 , F_38 ( V_22 -> V_4 . V_36 ) ,
F_38 ( V_29 -> V_8 ) , F_38 ( V_29 -> V_10 ) ,
V_91 ) ;
} else if ( V_22 -> V_96 ) {
int V_14 = F_7 ( V_12 , & V_22 -> V_4 , V_29 -> V_8 ,
V_22 -> V_96 , V_22 -> V_10 ) ;
F_60 ( L_16
L_17 ,
F_38 ( V_22 -> V_4 . V_36 ) , F_38 ( V_29 -> V_8 ) ,
F_38 ( V_22 -> V_10 ) , V_91 , V_14 ) ;
if ( F_5 ( V_14 ) )
return V_14 ;
} else {
F_67 ( V_12 , & V_22 -> V_4 ) ;
F_60 ( L_18 ,
F_38 ( V_22 -> V_4 . V_36 ) , V_22 -> V_108 , V_91 ) ;
}
if ( V_22 -> V_106 )
F_62 ( V_12 , V_22 -> V_106 , V_22 -> V_105 ) ;
if ( V_22 -> V_107 )
F_63 ( V_12 , V_22 -> V_107 , V_22 -> V_108 ) ;
return 0 ;
}
int F_68 ( struct V_20 * V_22 )
{
int V_26 ;
int V_14 ;
V_14 = F_50 ( V_22 ) ;
if ( F_5 ( V_14 ) )
return V_14 ;
for ( V_26 = 0 ; V_26 < V_22 -> V_27 ; V_26 += V_22 -> V_19 -> V_34 ) {
V_14 = F_65 ( V_22 , V_26 ) ;
if ( F_5 ( V_14 ) )
return V_14 ;
}
V_14 = F_25 ( V_22 ) ;
return V_14 ;
}
int F_69 ( struct V_20 * V_22 , struct V_109 * V_110 )
{
struct V_109 V_111 = { . V_112 = 0 } ;
void * V_113 = NULL ;
int V_114 ;
do {
V_114 = 1 ;
F_70 ( V_22 -> V_29 [ 0 ] . V_12 ,
& V_111 , & V_114 , & V_113 ) ;
if ( ( V_111 . V_112 == V_110 -> V_112 ) &&
( V_111 . V_115 == V_110 -> V_115 ) ) {
V_110 -> V_116 = V_111 . V_116 ;
V_110 -> V_117 = V_111 . V_117 ;
return 0 ;
}
} while ( V_113 );
return - V_118 ;
}
static int F_71 ( struct V_20 * V_22 , unsigned V_97 ,
struct V_109 * V_110 )
{
int V_99 = V_97 + V_22 -> V_19 -> V_34 ;
for (; V_97 < V_99 ; ++ V_97 ) {
struct V_28 * V_29 = & V_22 -> V_29 [ V_97 ] ;
struct V_11 * V_12 ;
V_12 = F_4 ( F_18 ( V_22 , V_97 ) , V_13 ) ;
if ( F_5 ( ! V_12 ) ) {
F_52 ( L_9 , V_15 ) ;
return - V_16 ;
}
V_29 -> V_12 = V_12 ;
F_61 ( V_12 , & V_22 -> V_4 ) ;
F_62 ( V_12 , V_110 , 1 ) ;
}
return 0 ;
}
int F_72 ( struct V_119 * V_120 , T_2 V_121 )
{
struct V_122 * V_123 = V_120 -> V_124 . V_125 -> V_126 ;
struct V_20 * V_22 ;
struct V_127 {
struct V_109 V_110 ;
T_5 V_128 ;
} * V_129 ;
struct V_60 V_61 ;
int V_26 , V_14 ;
V_14 = F_11 ( & V_123 -> V_19 , & V_22 ) ;
if ( F_5 ( V_14 ) )
return V_14 ;
V_129 = F_73 ( V_22 -> V_19 -> V_63 , sizeof( * V_129 ) ,
V_13 ) ;
if ( F_5 ( ! V_129 ) ) {
V_14 = - V_16 ;
goto V_17;
}
V_22 -> V_4 . V_36 = F_74 ( V_120 ) ;
V_22 -> V_7 = V_120 -> V_130 ;
V_22 -> V_27 = V_22 -> V_19 -> V_23 ;
F_39 ( V_22 , V_121 , & V_61 ) ;
for ( V_26 = 0 ; V_26 < V_22 -> V_19 -> V_63 ; ++ V_26 ) {
struct V_127 * V_131 = & V_129 [ V_26 ] ;
T_2 V_132 ;
if ( V_26 < V_61 . V_74 )
V_132 = V_61 . V_76 +
V_22 -> V_19 -> V_62 - V_61 . V_75 ;
else if ( V_26 == V_61 . V_74 )
V_132 = V_61 . V_76 ;
else
V_132 = V_61 . V_76 - V_61 . V_75 ;
V_131 -> V_128 = F_75 ( V_132 ) ;
V_131 -> V_110 = V_133 ;
V_131 -> V_110 . V_117 = & V_131 -> V_128 ;
V_14 = F_71 ( V_22 , V_26 * V_22 -> V_19 -> V_34 ,
& V_131 -> V_110 ) ;
if ( F_5 ( V_14 ) )
goto V_17;
}
V_14 = F_25 ( V_22 ) ;
V_17:
F_16 ( V_129 ) ;
F_14 ( V_22 ) ;
return V_14 ;
}
