static struct V_1 * F_1 ( void )
{
return F_2 ( V_2 ) ;
}
static void F_3 ( struct V_1 * V_3 )
{
F_4 ( V_3 ) ;
}
static int F_5 ( unsigned V_4 , unsigned V_5 ,
unsigned V_6 , struct V_7 * * V_8 )
{
struct V_7 * V_9 ;
unsigned V_10 = V_5 - V_6 ;
struct V_11 {
struct V_12 {
struct V_7 V_9 ;
struct V_13 V_14 [ V_4 ] ;
} V_15 ;
struct V_16 {
struct V_1 * V_17 [ V_5 ] ;
struct V_1 * V_18 [ V_5 ] ;
char V_19 [ V_10 ] ;
} V_20 [ V_4 ] ;
} * V_21 ;
struct V_16 * V_20 ;
struct V_16 * V_22 ;
const unsigned V_23 = sizeof( V_21 -> V_20 [ 0 ] ) ;
unsigned V_24 , V_25 , V_26 ;
F_6 ( sizeof( V_21 -> V_15 ) > V_27 ) ;
F_6 ( V_23 > V_27 ) ;
if ( sizeof( * V_21 ) > V_27 ) {
V_24 = ( V_27 - sizeof( V_21 -> V_15 ) ) / V_23 ;
V_25 = sizeof( V_21 -> V_15 ) + V_23 * V_24 ;
} else {
V_24 = V_4 ;
V_25 = sizeof( * V_21 ) ;
}
V_21 = F_7 ( V_25 , V_2 ) ;
if ( F_8 ( ! V_21 ) ) {
F_9 ( L_1 , V_25 ) ;
return - V_28 ;
}
V_9 = & V_21 -> V_15 . V_9 ;
* V_8 = V_9 ;
V_20 = V_21 -> V_20 ;
V_22 = V_20 + V_24 ;
for ( V_26 = 0 ; V_26 < V_4 ; ++ V_26 ) {
if ( F_8 ( V_20 >= V_22 ) ) {
V_24 = F_10 ( unsigned , V_27 / V_23 ,
V_4 - V_26 ) ;
V_20 = F_7 ( V_24 * V_23 , V_2 ) ;
if ( F_8 ( ! V_20 ) ) {
F_9 ( L_2 ,
V_24 ) ;
return - V_28 ;
}
V_22 = V_20 + V_24 ;
V_9 -> V_14 [ V_26 ] . V_29 = true ;
}
V_9 -> V_14 [ V_26 ] . V_17 = V_20 -> V_17 ;
V_9 -> V_14 [ V_26 ] . V_18 = V_20 -> V_18 ;
V_9 -> V_14 [ V_26 ] . V_19 = V_20 -> V_19 ;
++ V_20 ;
}
V_9 -> V_6 = V_6 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_4 = V_4 ;
return 0 ;
}
static void F_11 ( struct V_7 * V_9 ,
const struct V_30 * V_31 , void * V_32 )
{
unsigned V_10 = V_9 -> V_10 ;
unsigned V_5 = V_10 + V_9 -> V_6 ;
int V_3 , V_33 ;
if ( ! V_9 -> V_34 )
return;
for ( V_33 = V_10 - 1 ; V_33 >= 0 ; -- V_33 )
for ( V_3 = V_9 -> V_4 - 1 ; V_3 >= 0 ; -- V_3 ) {
struct V_13 * V_35 = & V_9 -> V_14 [ V_3 ] ;
if ( V_35 -> V_19 [ V_33 ] ) {
struct V_1 * V_1 = V_35 -> V_17 [ V_33 ] ;
V_31 -> V_36 ( V_32 , V_1 ) ;
V_35 -> V_19 [ V_33 ] = false ;
}
}
for ( V_3 = 0 ; V_3 < V_9 -> V_4 ; V_3 ++ ) {
struct V_13 * V_35 = & V_9 -> V_14 [ V_3 ] ;
memset ( V_35 -> V_17 , 0 , V_5 * sizeof( * V_35 -> V_17 ) ) ;
V_35 -> V_37 = 0 ;
V_35 -> V_38 = NULL ;
}
V_9 -> V_34 = false ;
}
static void F_12 ( struct V_7 * V_9 )
{
unsigned V_26 ;
if ( ! V_9 )
return;
for ( V_26 = 0 ; V_26 < V_9 -> V_4 ; ++ V_26 ) {
if ( V_9 -> V_14 [ V_26 ] . V_29 )
F_13 ( V_9 -> V_14 [ V_26 ] . V_17 ) ;
}
F_13 ( V_9 ) ;
}
static unsigned F_14 ( struct V_7 * V_9 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_4 ; V_3 ++ ) {
struct V_13 * V_35 = & V_9 -> V_14 [ V_3 ] ;
if ( V_35 -> V_37 )
return V_3 ;
}
return ~ 0 ;
}
static unsigned F_15 ( struct V_7 * V_9 )
{
int V_3 ;
for ( V_3 = V_9 -> V_4 - 1 ; V_3 >= 0 ; -- V_3 ) {
struct V_13 * V_35 = & V_9 -> V_14 [ V_3 ] ;
if ( V_35 -> V_37 )
return V_3 ;
}
return ~ 0 ;
}
static void F_16 ( struct V_7 * V_9 )
{
unsigned V_3 ;
unsigned V_39 = V_40 ;
if ( V_9 -> V_6 == 1 )
V_39 |= V_41 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_4 ; V_3 ++ ) {
struct V_13 * V_35 = & V_9 -> V_14 [ V_3 ] ;
if ( ! V_35 -> V_37 )
continue;
F_17 ( & V_35 -> V_42 , V_39 ,
NULL , NULL , NULL , ( V_43 * ) V_35 -> V_18 ) ;
if ( V_9 -> V_6 == 1 )
V_35 -> V_38 = F_18 ( V_35 -> V_17 [ V_9 -> V_10 ] ,
V_35 -> V_17 , 0 , V_9 -> V_10 ,
V_27 , & V_35 -> V_42 ) ;
else
V_35 -> V_38 = F_19 ( V_35 -> V_17 , 0 ,
V_9 -> V_10 + V_9 -> V_6 ,
V_27 , & V_35 -> V_42 ) ;
}
for ( V_3 = 0 ; V_3 < V_9 -> V_4 ; V_3 ++ ) {
struct V_13 * V_35 = & V_9 -> V_14 [ V_3 ] ;
F_20 ( V_35 -> V_38 ) ;
}
}
void F_21 ( struct V_7 * V_9 ,
struct V_44 * V_45 , struct V_1 * V_1 )
{
struct V_13 * V_35 ;
V_9 -> V_34 = true ;
V_35 = & V_9 -> V_14 [ V_45 -> V_46 ] ;
V_35 -> V_17 [ V_45 -> V_47 ] = V_1 ;
++ V_35 -> V_37 ;
V_45 -> V_46 = ( V_45 -> V_46 + 1 ) % V_9 -> V_4 ;
}
void F_22 ( struct V_48 * V_49 , unsigned V_50 ,
bool V_51 )
{
struct V_52 * V_53 ;
F_9 ( L_3
L_4 ,
V_49 -> V_54 , V_50 , V_51 , V_49 -> V_55 ,
F_23 ( V_49 -> V_56 ) , V_49 -> V_57 ,
V_49 -> V_58 ) ;
if ( ! V_49 -> V_55 ) {
V_53 = V_49 -> V_59 ;
if ( V_49 -> V_57 ) {
++ V_49 -> V_55 ;
V_53 -> V_56 = V_49 -> V_56 ;
V_53 -> V_60 = V_49 -> V_57 ;
} else {
V_49 -> V_56 += V_50 ;
return;
}
} else {
V_53 = & V_49 -> V_59 [ V_49 -> V_55 - 1 ] ;
V_53 -> V_60 = V_49 -> V_57 - V_49 -> V_58 ;
}
if ( V_51 ) {
struct V_52 * V_61 = V_53 + 1 ;
++ V_49 -> V_55 ;
V_61 -> V_56 = V_53 -> V_56 + V_53 -> V_60 + V_50 ;
V_49 -> V_58 = V_49 -> V_57 ;
V_61 -> V_60 = 0 ;
} else if ( ! V_53 -> V_60 ) {
-- V_49 -> V_55 ;
}
}
static int F_24 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_65 ;
int V_66 ;
unsigned V_67 = V_63 -> V_9 -> V_4 + 2 ;
V_66 = F_25 ( V_65 , V_63 -> V_68 ,
V_65 -> V_5 * V_65 -> V_69 ,
V_67 , 0 , & V_63 -> V_70 ) ;
return V_66 ;
}
static int F_26 ( struct V_62 * V_63 , struct V_44 * V_45 ,
struct V_1 * V_1 , unsigned V_71 )
{
struct V_72 * V_73 ;
struct V_48 * V_49 ;
struct V_62 * V_74 ;
unsigned V_75 = V_45 -> V_54 - ( V_45 -> V_54 %
( V_63 -> V_65 -> V_5 * V_63 -> V_65 -> V_69 ) ) ;
unsigned V_76 = V_45 -> V_54 - V_75 ;
unsigned V_77 ;
if ( ! V_63 -> V_70 ) {
int V_66 = F_24 ( V_63 ) ;
if ( F_8 ( V_66 ) )
return V_66 ;
}
V_74 = V_63 -> V_70 ;
V_74 -> V_78 = V_63 -> V_65 -> V_5 * V_63 -> V_65 -> V_69 ;
V_49 = & V_74 -> V_49 [ V_76 ] ;
if ( ! V_49 -> V_57 ) {
V_49 -> V_79 = F_27 ( V_2 ,
V_63 -> V_9 -> V_4 ) ;
if ( F_8 ( ! V_49 -> V_79 ) ) {
F_9 ( L_5 ,
V_63 -> V_9 -> V_4 ) ;
return - V_28 ;
}
V_49 -> V_56 = V_45 -> V_80 ;
V_49 -> V_54 = V_45 -> V_54 ;
} else if ( V_45 -> V_80 != ( V_49 -> V_56 + V_49 -> V_57 ) ) {
T_1 V_81 = V_45 -> V_80 - ( V_49 -> V_56 + V_49 -> V_57 ) ;
F_22 ( V_49 , V_81 , true ) ;
}
V_73 = F_28 ( F_29 ( V_74 -> V_68 , V_49 -> V_54 ) ) ;
V_77 = F_30 ( V_73 , V_49 -> V_79 , V_1 , V_71 ,
V_45 -> V_80 % V_27 ) ;
if ( F_8 ( V_77 != V_71 ) ) {
F_9 ( L_6 ,
V_49 -> V_79 -> V_82 ) ;
return - V_28 ;
}
V_49 -> V_57 += V_71 ;
return 0 ;
}
static int F_31 ( struct V_62 * V_63 , struct V_1 * V_1 )
{
struct V_44 V_45 ;
unsigned V_71 ;
F_32 ( V_63 -> V_65 , V_63 -> V_56 , 0 , & V_45 ) ;
V_71 = V_45 . V_80 % V_27 ;
V_45 . V_80 -= V_71 ;
F_9 ( L_7 ,
F_23 ( V_45 . V_80 ) , V_71 , V_1 -> V_83 , V_45 . V_54 ) ;
return F_26 ( V_63 , & V_45 , V_1 , V_71 ) ;
}
static int F_33 ( struct V_62 * V_63 , T_1 * V_56 )
{
struct V_44 V_45 ;
struct V_1 * V_1 ;
unsigned V_71 , V_3 , V_33 ;
F_32 ( V_63 -> V_65 , * V_56 , 0 , & V_45 ) ;
V_3 = V_45 . V_46 ;
V_33 = V_45 . V_47 ;
V_1 = V_63 -> V_9 -> V_14 [ V_3 ] . V_17 [ V_33 ] ;
V_71 = V_27 - ( V_45 . V_84 % V_27 ) ;
* V_56 += V_71 ;
F_9 ( L_8 ,
V_3 , V_33 , F_23 ( * V_56 ) , V_71 , V_45 . V_54 , V_45 . V_85 ) ;
F_6 ( ! V_1 ) ;
return F_26 ( V_63 , & V_45 , V_1 , V_71 ) ;
}
static void F_34 ( struct V_62 * V_63 , int V_66 )
{
struct V_86 * V_87 ;
unsigned V_26 , V_88 ;
for ( V_88 = 0 ; V_88 < V_63 -> V_78 ; V_88 ++ ) {
struct V_79 * V_79 = V_63 -> V_49 [ V_88 ] . V_79 ;
if ( ! V_79 )
continue;
F_35 (bv, bio, i) {
struct V_1 * V_1 = V_87 -> V_89 ;
F_36 ( V_1 ) ;
if ( F_37 ( V_1 ) )
F_38 ( V_1 ) ;
}
}
}
static int F_39 ( struct V_62 * V_63 )
{
struct V_44 V_90 ;
struct V_7 * V_9 = V_63 -> V_9 ;
T_1 V_56 = V_63 -> V_45 . V_91 ;
unsigned V_33 , V_3 , V_92 = V_9 -> V_4 , V_93 = - 1 ;
if ( V_56 == V_63 -> V_56 )
goto V_94;
V_92 = F_14 ( V_9 ) ;
V_93 = F_15 ( V_9 ) ;
F_9 ( L_9 ,
V_56 , V_63 -> V_56 , V_92 , V_93 ) ;
for ( V_33 = 0 ; ; V_33 ++ ) {
F_32 ( V_63 -> V_65 , V_56 , 0 , & V_90 ) ;
V_90 . V_80 += V_92 * V_27 ;
V_56 += V_92 * V_27 ;
for ( V_3 = V_92 ; V_3 <= V_93 ; V_3 ++ ) {
struct V_13 * V_35 = & V_9 -> V_14 [ V_3 ] ;
struct V_1 * * V_95 = & V_35 -> V_17 [ V_33 ] ;
bool V_96 ;
if ( * V_95 ) {
if ( V_63 -> V_56 % V_27 )
F_31 ( V_63 , * V_95 ) ;
goto V_94;
}
* V_95 = V_63 -> V_31 -> V_97 ( V_63 -> V_98 , V_56 ,
& V_96 ) ;
if ( F_8 ( ! * V_95 ) )
return - V_28 ;
if ( ! V_96 )
F_26 ( V_63 , & V_90 , * V_95 , V_27 ) ;
V_35 -> V_19 [ V_33 ] = true ;
V_90 . V_80 += V_27 ;
V_56 += V_27 ;
}
V_56 += ( V_9 -> V_4 - V_3 ) * V_27 ;
}
V_94:
return 0 ;
}
static int F_40 ( struct V_62 * V_63 )
{
struct V_44 V_90 ;
struct V_7 * V_9 = V_63 -> V_9 ;
T_1 V_56 ;
T_1 V_99 ;
unsigned V_100 = V_63 -> V_45 . V_100 ;
unsigned V_33 , V_3 , V_92 = V_9 -> V_4 , V_93 = - 1 ;
V_56 = V_63 -> V_56 + V_63 -> V_57 ;
if ( V_56 % V_27 )
F_33 ( V_63 , & V_56 ) ;
V_99 = F_41 ( V_56 + V_100 - 1 , V_100 )
* V_100 ;
if ( V_56 == V_99 )
goto V_101;
F_32 ( V_63 -> V_65 , V_56 , 0 , & V_90 ) ;
V_3 = V_90 . V_46 ;
V_33 = V_90 . V_47 ;
if ( V_92 == V_9 -> V_4 ) {
V_92 = F_14 ( V_9 ) ;
V_93 = F_15 ( V_9 ) ;
}
F_9 ( L_10 ,
V_56 , V_99 , V_92 , V_93 ) ;
while ( V_56 < V_99 ) {
struct V_13 * V_35 = & V_9 -> V_14 [ V_3 ] ;
if ( ( V_92 <= V_3 ) && ( V_3 <= V_93 ) ) {
struct V_1 * V_1 ;
bool V_96 ;
F_6 ( V_35 -> V_17 [ V_33 ] ) ;
V_1 = V_63 -> V_31 -> V_97 ( V_63 -> V_98 , V_56 ,
& V_96 ) ;
if ( F_8 ( ! V_1 ) )
return - V_28 ;
V_35 -> V_17 [ V_33 ] = V_1 ;
V_35 -> V_19 [ V_33 ] = true ;
if ( ! V_96 )
F_26 ( V_63 , & V_90 , V_1 , V_27 ) ;
}
V_56 += V_27 ;
if ( V_3 == ( V_9 -> V_4 - 1 ) ) {
++ V_33 ;
V_3 = 0 ;
F_32 ( V_63 -> V_65 , V_56 , 0 , & V_90 ) ;
} else {
V_90 . V_80 += V_27 ;
++ V_3 ;
}
}
V_101:
return 0 ;
}
static int F_42 ( struct V_62 * V_63 )
{
struct V_62 * V_102 ;
unsigned V_26 ;
int V_66 ;
V_102 = V_63 -> V_70 ;
if ( ! V_102 )
return 0 ;
V_102 -> V_17 = V_63 -> V_17 ;
for ( V_26 = 0 ; V_26 < V_102 -> V_78 ; V_26 += V_102 -> V_65 -> V_69 ) {
V_66 = F_43 ( V_102 , V_26 ) ;
if ( F_8 ( V_66 ) )
return V_66 ;
}
V_66 = F_44 ( V_102 ) ;
if ( F_8 ( V_66 ) ) {
F_9 ( L_11 , V_66 ) ;
return V_66 ;
}
F_34 ( V_102 , V_66 ) ;
F_45 ( V_102 ) ;
V_63 -> V_70 = NULL ;
return 0 ;
}
int F_46 ( struct V_62 * V_63 ,
struct V_44 * V_45 ,
struct V_48 * V_49 ,
unsigned V_50 , bool V_103 )
{
if ( V_63 -> V_104 ) {
if ( V_49 -> V_55 >= V_63 -> V_67 ) {
F_9 ( L_12 ,
V_49 -> V_55 , V_63 -> V_67 ) ;
return - V_28 ;
}
F_22 ( V_49 , V_50 , true ) ;
} else {
struct V_7 * V_9 = V_63 -> V_9 ;
struct V_1 * * V_17 = V_63 -> V_105 + V_63 -> V_106 ;
unsigned V_107 ;
unsigned V_108 = 0 ;
unsigned V_26 ;
int V_66 ;
V_45 -> V_46 = F_14 ( V_9 ) ;
V_107 = F_15 ( V_9 ) + 1 - V_45 -> V_46 ;
if ( ! V_49 -> V_57 ) {
V_49 -> V_56 += V_45 -> V_46 * V_27 ;
if ( V_103 )
F_39 ( V_63 ) ;
}
if ( ! V_50 && V_103 )
F_40 ( V_63 ) ;
F_42 ( V_63 ) ;
for ( V_26 = 0 ; V_26 < V_107 ; V_26 ++ ) {
V_17 [ V_26 ] = F_1 () ;
if ( F_8 ( ! V_17 [ V_26 ] ) )
return - V_28 ;
++ ( V_63 -> V_106 ) ;
}
F_6 ( V_45 -> V_47 < V_9 -> V_10 ) ;
F_6 ( V_45 -> V_46 + V_107 > V_9 -> V_4 ) ;
V_66 = F_47 ( V_63 , & V_108 , 0 , V_17 ,
V_49 , V_107 * V_27 ) ;
if ( F_8 ( V_66 ) )
return V_66 ;
if ( V_103 ) {
F_16 ( V_9 ) ;
F_11 ( V_9 , V_63 -> V_31 , V_63 -> V_98 ) ;
}
}
return 0 ;
}
int F_48 ( struct V_62 * V_63 )
{
if ( V_63 -> V_105 ) {
struct V_64 * V_65 = V_63 -> V_65 ;
unsigned V_4 = V_65 -> V_109 / V_27 ;
if ( F_5 ( V_4 , V_65 -> V_5 ,
V_65 -> V_6 , & V_63 -> V_9 ) ) {
return - V_28 ;
}
}
return 0 ;
}
void F_49 ( struct V_62 * V_63 )
{
if ( V_63 -> V_9 ) {
unsigned V_26 ;
for ( V_26 = 0 ; V_26 < V_63 -> V_106 ; V_26 ++ ) {
struct V_1 * V_1 = V_63 -> V_105 [ V_26 ] ;
if ( V_1 )
F_3 ( V_1 ) ;
}
if ( V_63 -> V_110 )
F_13 ( V_63 -> V_105 ) ;
F_11 ( V_63 -> V_9 , V_63 -> V_31 , V_63 -> V_98 ) ;
F_12 ( V_63 -> V_9 ) ;
} else {
if ( V_63 -> V_110 )
F_13 ( V_63 -> V_49 [ 0 ] . V_59 ) ;
}
if ( V_63 -> V_70 )
F_45 ( V_63 -> V_70 ) ;
}
