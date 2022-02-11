static T_1 * F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return V_2 -> V_4 -> V_4 [ V_3 & V_2 -> V_4 -> V_5 ] . V_6 ;
}
static struct V_7 * F_2 ( struct V_1 * V_2 , unsigned V_3 )
{
return & V_2 -> V_4 -> V_4 [ V_3 & V_2 -> V_4 -> V_5 ] . V_8 ;
}
static struct V_9 * F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
return V_2 -> V_4 -> V_10 [ V_3 ] ;
}
int F_4 ( struct V_11 * V_12 , struct V_13 * V_4 ,
bool V_14 , T_2 V_15 , T_2 V_16 ,
struct V_1 * * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( F_6 ( V_4 -> V_18 ) , V_19 ) ;
if ( F_7 ( ! V_2 ) ) {
F_8 ( L_1 ,
F_6 ( V_4 -> V_18 ) ) ;
* V_17 = NULL ;
return - V_20 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_21 = V_14 ;
* V_17 = V_2 ;
return 0 ;
}
int F_9 ( struct V_11 * V_12 , struct V_13 * V_4 ,
struct V_1 * * V_2 )
{
return F_4 ( V_12 , V_4 , true , 0 , 0 , V_2 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( V_2 ) {
unsigned V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_18 ; V_22 ++ ) {
struct V_23 * V_24 = & V_2 -> V_24 [ V_22 ] ;
if ( V_24 -> V_25 )
F_11 ( V_24 -> V_25 ) ;
if ( V_24 -> V_26 )
F_12 ( V_24 -> V_26 ) ;
}
F_13 ( V_2 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , void * V_27 )
{
struct V_28 * V_29 = V_27 ;
F_15 ( V_29 ) ;
}
static void F_16 ( struct V_30 * V_30 )
{
struct V_1 * V_2 = F_17 (
V_30 , struct V_1 , V_30 ) ;
V_2 -> V_31 ( V_2 , V_2 -> V_32 ) ;
}
static void F_18 ( struct V_33 * V_25 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
F_19 ( & V_2 -> V_30 , F_16 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_21 ( V_34 ) ;
bool V_35 = ( V_2 -> V_31 == NULL ) ;
int V_22 , V_36 ;
if ( V_35 ) {
V_2 -> V_31 = F_14 ;
V_2 -> V_32 = & V_34 ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_18 ; V_22 ++ ) {
struct V_33 * V_25 = V_2 -> V_24 [ V_22 ] . V_25 ;
if ( F_7 ( ! V_25 ) )
continue;
V_36 = F_22 ( V_25 , 0 , F_1 ( V_2 , V_22 ) , NULL ) ;
if ( F_7 ( V_36 ) ) {
F_8 ( L_2 ,
V_36 ) ;
return V_36 ;
}
}
F_23 ( & V_2 -> V_30 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_18 ; V_22 ++ ) {
struct V_33 * V_25 = V_2 -> V_24 [ V_22 ] . V_25 ;
if ( F_7 ( ! V_25 ) )
continue;
F_24 ( & V_2 -> V_30 ) ;
F_25 ( V_25 , F_18 , V_2 ) ;
}
F_19 ( & V_2 -> V_30 , F_16 ) ;
V_36 = 0 ;
if ( V_35 ) {
F_26 ( & V_34 ) ;
V_36 = F_27 ( V_2 , NULL ) ;
}
return V_36 ;
}
static void F_28 ( struct V_26 * V_26 )
{
struct V_37 * V_38 ;
unsigned V_22 ;
F_29 (bv, bio, i, 0 ) {
unsigned V_39 = V_38 -> V_40 ;
if ( F_30 ( V_41 == V_39 ) )
F_31 ( V_38 -> V_42 ) ;
else
F_32 ( V_38 -> V_42 , V_38 -> V_43 , V_39 ) ;
}
}
int F_27 ( struct V_1 * V_2 , T_2 * V_44 )
{
enum V_45 V_46 = 0 ;
int V_47 = 0 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_18 ; V_22 ++ ) {
struct V_48 V_49 ;
struct V_33 * V_25 = V_2 -> V_24 [ V_22 ] . V_25 ;
int V_36 ;
if ( F_7 ( ! V_25 ) )
continue;
V_36 = F_33 ( V_25 , & V_49 ) ;
if ( F_30 ( ! V_36 ) )
continue;
if ( V_50 == V_49 . V_51 ) {
F_28 ( V_2 -> V_24 [ V_22 ] . V_26 ) ;
F_8 ( L_3
L_4 ,
F_34 ( V_2 -> V_24 [ V_22 ] . V_15 ) ,
F_34 ( V_2 -> V_24 [ V_22 ] . V_16 ) ) ;
continue;
}
if ( V_49 . V_51 >= V_46 ) {
V_46 = V_49 . V_51 ;
V_47 = V_36 ;
}
}
if ( V_44 ) {
if ( F_30 ( ! V_47 ) )
* V_44 = 0 ;
else
* V_44 = V_2 -> V_16 ;
}
return V_47 ;
}
static void F_35 ( struct V_11 * V_12 , T_2 V_52 ,
struct V_53 * V_54 )
{
T_3 V_55 = V_12 -> V_55 ;
T_3 V_56 = V_12 -> V_56 ;
T_2 V_57 = V_12 -> V_57 ;
T_3 V_58 = V_55 * V_56 ;
T_2 V_59 = V_58 * V_57 ;
T_2 V_60 = V_59 * V_12 -> V_61 ;
T_2 V_62 = F_36 ( V_52 , V_60 ) ;
T_2 V_63 = V_52 - V_62 * V_60 ;
T_3 V_64 = F_36 ( V_63 , V_59 ) ;
T_2 V_65 = V_63 - V_64 * V_59 ;
T_3 V_66 = F_37 ( V_65 , V_58 ) ;
V_54 -> V_67 = ( T_3 ) ( V_65 - ( V_66 * V_58 ) ) / V_55 + V_64 * V_56 ;
V_54 -> V_67 *= V_12 -> V_68 ;
F_38 ( V_52 , V_55 , & V_54 -> V_69 ) ;
V_54 -> V_70 = V_54 -> V_69 + ( V_66 * V_55 ) +
( V_62 * V_57 * V_55 ) ;
V_54 -> V_71 = V_59 - V_65 ;
V_54 -> V_62 = V_62 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned * V_72 ,
unsigned V_73 , struct V_23 * V_24 ,
int V_74 )
{
unsigned V_75 = * V_72 ;
struct V_76 * V_77 =
F_40 ( F_3 ( V_2 , V_24 -> V_67 ) ) ;
V_24 -> V_16 += V_74 ;
if ( V_24 -> V_26 == NULL ) {
unsigned V_78 = V_2 -> V_12 -> V_56 *
( V_2 -> V_12 -> V_55 / V_41 ) ;
unsigned V_79 = ( V_2 -> V_80 + V_78 ) /
V_2 -> V_12 -> V_56 ;
V_24 -> V_26 = F_41 ( V_19 , V_79 ) ;
if ( F_7 ( ! V_24 -> V_26 ) ) {
F_8 ( L_5 ,
V_79 ) ;
return - V_20 ;
}
}
while ( V_74 > 0 ) {
unsigned V_81 = F_42 ( unsigned , V_41 - V_73 , V_74 ) ;
unsigned V_82 ;
F_43 ( V_2 -> V_80 <= V_75 ) ;
V_74 -= V_81 ;
V_82 = F_44 ( V_77 , V_24 -> V_26 , V_2 -> V_83 [ V_75 ] ,
V_81 , V_73 ) ;
if ( F_7 ( V_81 != V_82 ) )
return - V_20 ;
V_73 = 0 ;
++ V_75 ;
}
F_43 ( V_74 ) ;
* V_72 = V_75 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , T_2 V_16 ,
struct V_53 * V_54 )
{
unsigned V_55 = V_2 -> V_12 -> V_55 ;
unsigned V_68 = V_2 -> V_12 -> V_68 ;
unsigned V_84 = V_2 -> V_12 -> V_56 * V_68 ;
unsigned V_67 = V_54 -> V_67 ;
unsigned V_85 = V_67 - ( V_67 % V_84 ) ;
unsigned V_86 = V_2 -> V_18 ? V_2 -> V_18 - V_68 : 0 ;
unsigned V_72 = V_2 -> V_87 ;
int V_36 = 0 ;
while ( V_16 ) {
struct V_23 * V_24 = & V_2 -> V_24 [ V_67 ] ;
unsigned V_74 , V_88 = 0 ;
if ( ! V_24 -> V_16 ) {
V_24 -> V_67 = V_67 ;
if ( V_67 < V_54 -> V_67 ) {
V_24 -> V_15 = V_54 -> V_70 + V_55 -
V_54 -> V_69 ;
V_74 = V_55 ;
} else if ( V_67 == V_54 -> V_67 ) {
V_24 -> V_15 = V_54 -> V_70 ;
V_74 = V_55 - V_54 -> V_69 ;
V_88 = V_54 -> V_69 & ~ V_89 ;
F_43 ( V_88 && ( V_88 != V_2 -> V_73 ) ) ;
} else {
V_24 -> V_15 = V_54 -> V_70 - V_54 -> V_69 ;
V_74 = V_55 ;
}
if ( V_86 < V_67 )
V_86 = V_67 ;
} else {
V_74 = V_55 ;
}
if ( V_74 >= V_16 )
V_74 = V_16 ;
V_36 = F_39 ( V_2 , & V_72 , V_88 , V_24 ,
V_74 ) ;
if ( F_7 ( V_36 ) )
goto V_90;
V_67 += V_68 ;
V_67 = ( V_67 % V_84 ) + V_85 ;
V_16 -= V_74 ;
}
V_90:
V_2 -> V_18 = V_86 + V_68 ;
V_2 -> V_87 = V_72 ;
return V_36 ;
}
static int F_46 ( struct V_1 * V_2 )
{
T_2 V_16 = V_2 -> V_16 ;
T_2 V_15 = V_2 -> V_15 ;
struct V_53 V_54 ;
int V_36 = 0 ;
if ( ! V_2 -> V_83 ) {
if ( V_2 -> V_91 ) {
struct V_23 * V_24 = & V_2 -> V_24 [ 0 ] ;
F_35 ( V_2 -> V_12 , V_2 -> V_15 , & V_54 ) ;
V_24 -> V_15 = V_54 . V_70 ;
V_24 -> V_67 = V_54 . V_67 ;
F_43 ( ( V_2 -> V_12 -> V_56 > 1 ) &&
( V_54 . V_69 + V_2 -> V_16 >
V_2 -> V_12 -> V_55 ) ) ;
}
V_2 -> V_18 = V_2 -> V_12 -> V_68 ;
return 0 ;
}
while ( V_16 ) {
F_35 ( V_2 -> V_12 , V_15 , & V_54 ) ;
if ( V_16 < V_54 . V_71 )
V_54 . V_71 = V_16 ;
V_36 = F_45 ( V_2 , V_54 . V_71 , & V_54 ) ;
if ( F_7 ( V_36 ) )
goto V_90;
V_15 += V_54 . V_71 ;
V_16 -= V_54 . V_71 ;
}
V_90:
return V_36 ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_22 , V_36 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_4 -> V_18 ; V_22 ++ ) {
struct V_33 * V_25 ;
V_25 = F_48 ( F_3 ( V_2 , V_22 ) , V_19 ) ;
if ( F_7 ( ! V_25 ) ) {
F_49 ( L_6 , V_92 ) ;
V_36 = - V_20 ;
goto V_90;
}
V_2 -> V_24 [ V_22 ] . V_25 = V_25 ;
V_2 -> V_18 ++ ;
F_50 ( V_25 , F_2 ( V_2 , V_22 ) ) ;
}
V_36 = F_20 ( V_2 ) ;
V_90:
return V_36 ;
}
int F_51 ( struct V_1 * V_2 )
{
int V_22 , V_36 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_4 -> V_18 ; V_22 ++ ) {
struct V_33 * V_25 ;
V_25 = F_48 ( F_3 ( V_2 , V_22 ) , V_19 ) ;
if ( F_7 ( ! V_25 ) ) {
F_49 ( L_6 , V_92 ) ;
V_36 = - V_20 ;
goto V_90;
}
V_2 -> V_24 [ V_22 ] . V_25 = V_25 ;
V_2 -> V_18 ++ ;
F_52 ( V_25 , F_2 ( V_2 , V_22 ) ) ;
}
V_36 = F_20 ( V_2 ) ;
V_90:
return V_36 ;
}
static int F_53 ( struct V_1 * V_2 , int V_93 )
{
struct V_23 * V_94 = & V_2 -> V_24 [ V_93 ] ;
unsigned V_67 = V_2 -> V_24 [ V_93 ] . V_67 ;
unsigned V_95 = V_93 + V_2 -> V_12 -> V_68 ;
int V_36 = 0 ;
if ( V_2 -> V_83 && ! V_94 -> V_16 )
return 0 ;
for (; V_93 < V_95 ; ++ V_93 , ++ V_67 ) {
struct V_23 * V_24 = & V_2 -> V_24 [ V_93 ] ;
struct V_33 * V_25 ;
V_25 = F_48 ( F_3 ( V_2 , V_67 ) , V_19 ) ;
if ( F_7 ( ! V_25 ) ) {
F_49 ( L_6 , V_92 ) ;
V_36 = - V_20 ;
goto V_90;
}
V_24 -> V_25 = V_25 ;
V_24 -> V_15 = V_94 -> V_15 ;
if ( V_2 -> V_83 ) {
struct V_26 * V_26 ;
if ( V_24 != V_94 ) {
V_26 = F_41 ( V_19 ,
V_94 -> V_26 -> V_96 ) ;
if ( F_7 ( ! V_26 ) ) {
F_8 (
L_5 ,
V_94 -> V_26 -> V_96 ) ;
V_36 = - V_20 ;
goto V_90;
}
F_54 ( V_26 , V_94 -> V_26 ) ;
V_26 -> V_97 = NULL ;
V_26 -> V_98 = NULL ;
V_24 -> V_16 = V_94 -> V_16 ;
V_24 -> V_26 = V_26 ;
V_24 -> V_67 = V_67 ;
} else {
V_26 = V_94 -> V_26 ;
V_26 -> V_99 |= V_100 ;
}
F_55 ( V_25 , F_2 ( V_2 , V_67 ) , V_24 -> V_15 ,
V_26 , V_24 -> V_16 ) ;
F_8 ( L_7
L_8 ,
F_34 ( F_2 ( V_2 , V_67 ) -> V_101 ) ,
F_34 ( V_24 -> V_15 ) ,
F_34 ( V_24 -> V_16 ) , V_67 ) ;
} else if ( V_2 -> V_91 ) {
V_36 = F_56 ( V_25 , F_2 ( V_2 , V_67 ) ,
V_24 -> V_15 ,
V_2 -> V_91 , V_2 -> V_16 ) ;
if ( F_7 ( V_36 ) )
goto V_90;
F_57 ( L_9
L_8 ,
F_34 ( F_2 ( V_2 , V_67 ) -> V_101 ) ,
F_34 ( V_24 -> V_15 ) ,
F_34 ( V_2 -> V_16 ) , V_67 ) ;
} else {
F_58 ( V_25 , F_2 ( V_2 , V_67 ) ) ;
F_57 ( L_10 ,
F_34 ( F_2 ( V_2 , V_67 ) -> V_101 ) ,
V_2 -> V_102 , V_67 ) ;
}
if ( V_2 -> V_103 )
F_59 ( V_25 , V_2 -> V_103 ,
V_2 -> V_102 ) ;
if ( V_2 -> V_104 )
F_60 ( V_25 , V_2 -> V_104 ,
V_2 -> V_105 ) ;
}
V_90:
return V_36 ;
}
int F_61 ( struct V_1 * V_2 )
{
int V_22 ;
int V_36 ;
V_36 = F_46 ( V_2 ) ;
if ( F_7 ( V_36 ) )
return V_36 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_18 ; V_22 += V_2 -> V_12 -> V_68 ) {
V_36 = F_53 ( V_2 , V_22 ) ;
if ( F_7 ( V_36 ) )
return V_36 ;
}
V_36 = F_20 ( V_2 ) ;
return V_36 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned V_93 )
{
struct V_33 * V_25 ;
struct V_23 * V_24 = & V_2 -> V_24 [ V_93 ] ;
struct V_7 * V_8 = F_2 ( V_2 , V_93 ) ;
unsigned V_85 = ( unsigned ) V_8 -> V_101 ;
if ( V_2 -> V_83 && ! V_24 -> V_16 )
return 0 ;
V_85 = V_24 -> V_67 + V_85 % V_2 -> V_12 -> V_68 ;
V_25 = F_48 ( F_3 ( V_2 , V_85 ) , V_19 ) ;
if ( F_7 ( ! V_25 ) ) {
F_49 ( L_6 , V_92 ) ;
return - V_20 ;
}
V_24 -> V_25 = V_25 ;
if ( V_2 -> V_83 ) {
F_63 ( V_25 , V_8 , V_24 -> V_15 ,
V_24 -> V_26 , V_24 -> V_16 ) ;
F_8 ( L_11
L_12 , F_34 ( V_8 -> V_101 ) ,
F_34 ( V_24 -> V_15 ) , F_34 ( V_24 -> V_16 ) ,
V_85 ) ;
} else if ( V_2 -> V_91 ) {
int V_36 = F_64 ( V_25 , V_8 , V_24 -> V_15 ,
V_2 -> V_91 , V_2 -> V_16 ) ;
F_57 ( L_13
L_14 ,
F_34 ( V_8 -> V_101 ) , F_34 ( V_24 -> V_15 ) ,
F_34 ( V_2 -> V_16 ) , V_85 , V_36 ) ;
if ( F_7 ( V_36 ) )
return V_36 ;
} else {
F_65 ( V_25 , V_8 ) ;
F_57 ( L_15 ,
F_34 ( V_8 -> V_101 ) ,
V_2 -> V_105 , V_85 ) ;
}
if ( V_2 -> V_103 )
F_59 ( V_25 , V_2 -> V_103 , V_2 -> V_102 ) ;
if ( V_2 -> V_104 )
F_60 ( V_25 , V_2 -> V_104 , V_2 -> V_105 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 )
{
int V_22 ;
int V_36 ;
V_36 = F_46 ( V_2 ) ;
if ( F_7 ( V_36 ) )
return V_36 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_18 ; V_22 += V_2 -> V_12 -> V_68 ) {
V_36 = F_62 ( V_2 , V_22 ) ;
if ( F_7 ( V_36 ) )
return V_36 ;
}
V_36 = F_20 ( V_2 ) ;
return V_36 ;
}
int F_67 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
struct V_106 V_108 = { . V_109 = 0 } ;
void * V_110 = NULL ;
int V_111 ;
do {
V_111 = 1 ;
F_68 ( V_2 -> V_24 [ 0 ] . V_25 ,
& V_108 , & V_111 , & V_110 ) ;
if ( ( V_108 . V_109 == V_107 -> V_109 ) &&
( V_108 . V_112 == V_107 -> V_112 ) ) {
V_107 -> V_113 = V_108 . V_113 ;
V_107 -> V_114 = V_108 . V_114 ;
return 0 ;
}
} while ( V_110 );
return - V_115 ;
}
static int F_69 ( struct V_1 * V_2 , unsigned V_93 ,
struct V_106 * V_107 )
{
int V_95 = V_93 + V_2 -> V_12 -> V_68 ;
for (; V_93 < V_95 ; ++ V_93 ) {
struct V_23 * V_24 = & V_2 -> V_24 [ V_93 ] ;
struct V_33 * V_25 ;
V_25 = F_48 ( F_3 ( V_2 , V_93 ) , V_19 ) ;
if ( F_7 ( ! V_25 ) ) {
F_49 ( L_6 , V_92 ) ;
return - V_20 ;
}
V_24 -> V_25 = V_25 ;
F_58 ( V_25 , F_2 ( V_2 , V_93 ) ) ;
F_59 ( V_25 , V_107 , 1 ) ;
}
return 0 ;
}
void F_70 ( struct V_11 * V_12 , T_2 V_52 ,
struct V_116 * V_117 )
{
unsigned V_55 = V_12 -> V_55 ;
F_35 ( V_12 , V_52 , & V_117 -> V_54 ) ;
V_117 -> V_118 = V_117 -> V_54 . V_62 * V_55 ;
V_117 -> V_119 = V_117 -> V_54 . V_62 ? ( V_117 -> V_54 . V_62 - 1 ) * V_55 : 0 ;
V_117 -> V_120 = V_117 -> V_54 . V_67 - ( V_117 -> V_54 . V_67 % V_12 -> V_56 ) ;
V_117 -> V_121 = V_117 -> V_120 + V_12 -> V_56 ;
V_117 -> V_122 = V_12 -> V_56 * V_12 -> V_61 ;
}
int F_71 ( struct V_11 * V_12 , struct V_13 * V_4 ,
T_2 V_123 )
{
struct V_1 * V_2 ;
struct V_124 {
struct V_106 V_107 ;
T_4 V_125 ;
} * V_126 ;
struct V_116 V_117 ;
int V_22 , V_36 ;
V_36 = F_9 ( V_12 , V_4 , & V_2 ) ;
if ( F_7 ( V_36 ) )
return V_36 ;
F_70 ( V_2 -> V_12 , V_123 , & V_117 ) ;
V_126 = F_72 ( V_117 . V_122 , sizeof( * V_126 ) ,
V_19 ) ;
if ( F_7 ( ! V_126 ) ) {
V_36 = - V_20 ;
goto V_90;
}
V_2 -> V_18 = V_2 -> V_4 -> V_18 ;
for ( V_22 = 0 ; V_22 < V_117 . V_122 ; ++ V_22 ) {
struct V_124 * V_127 = & V_126 [ V_22 ] ;
T_2 V_128 ;
if ( V_22 < V_117 . V_120 )
V_128 = V_117 . V_118 ;
else if ( V_22 >= V_117 . V_121 )
V_128 = V_117 . V_119 ;
else if ( V_22 < V_117 . V_54 . V_67 )
V_128 = V_117 . V_54 . V_70 +
V_2 -> V_12 -> V_55 - V_117 . V_54 . V_69 ;
else if ( V_22 == V_117 . V_54 . V_67 )
V_128 = V_117 . V_54 . V_70 ;
else
V_128 = V_117 . V_54 . V_70 - V_117 . V_54 . V_69 ;
V_127 -> V_125 = F_73 ( V_128 ) ;
V_127 -> V_107 = V_129 ;
V_127 -> V_107 . V_114 = & V_127 -> V_125 ;
F_8 ( L_16 ,
F_34 ( V_4 -> V_4 -> V_8 . V_101 ) , F_34 ( V_128 ) , V_22 ) ;
V_36 = F_69 ( V_2 , V_22 * V_2 -> V_12 -> V_68 ,
& V_127 -> V_107 ) ;
if ( F_7 ( V_36 ) )
goto V_90;
}
V_36 = F_20 ( V_2 ) ;
V_90:
F_13 ( V_126 ) ;
F_10 ( V_2 ) ;
return V_36 ;
}
