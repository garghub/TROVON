struct V_1 * F_1 ( void )
{
return F_2 ( V_2 ) ;
}
void F_3 ( struct V_1 * V_3 )
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
for ( V_3 = 0 ; V_3 < V_9 -> V_4 ; V_3 ++ ) {
struct V_13 * V_35 = & V_9 -> V_14 [ V_3 ] ;
if ( ! V_35 -> V_37 )
continue;
F_17 ( & V_35 -> V_39 ,
V_40 | V_41 ,
NULL ,
NULL , NULL ,
( V_42 * ) V_35 -> V_18 ) ;
V_35 -> V_38 = F_18 ( V_35 -> V_17 [ V_9 -> V_10 ] , V_35 -> V_17 ,
0 , V_9 -> V_10 , V_27 ,
& V_35 -> V_39 ) ;
}
for ( V_3 = 0 ; V_3 < V_9 -> V_4 ; V_3 ++ ) {
struct V_13 * V_35 = & V_9 -> V_14 [ V_3 ] ;
F_19 ( V_35 -> V_38 ) ;
}
}
void F_20 ( struct V_7 * V_9 ,
struct V_43 * V_44 , struct V_1 * V_1 )
{
struct V_13 * V_35 ;
V_9 -> V_34 = true ;
V_35 = & V_9 -> V_14 [ V_44 -> V_45 ] ;
V_35 -> V_17 [ V_44 -> V_46 ] = V_1 ;
++ V_35 -> V_37 ;
V_44 -> V_45 = ( V_44 -> V_45 + 1 ) % V_9 -> V_4 ;
}
void F_21 ( struct V_47 * V_48 , unsigned V_49 ,
bool V_50 )
{
struct V_51 * V_52 ;
F_9 ( L_3
L_4 ,
V_48 -> V_53 , V_49 , V_50 , V_48 -> V_54 ,
F_22 ( V_48 -> V_55 ) , V_48 -> V_56 ,
V_48 -> V_57 ) ;
if ( ! V_48 -> V_54 ) {
V_52 = V_48 -> V_58 ;
if ( V_48 -> V_56 ) {
++ V_48 -> V_54 ;
V_52 -> V_55 = V_48 -> V_55 ;
V_52 -> V_59 = V_48 -> V_56 ;
} else {
V_48 -> V_55 += V_49 ;
return;
}
} else {
V_52 = & V_48 -> V_58 [ V_48 -> V_54 - 1 ] ;
V_52 -> V_59 = V_48 -> V_56 - V_48 -> V_57 ;
}
if ( V_50 ) {
struct V_51 * V_60 = V_52 + 1 ;
++ V_48 -> V_54 ;
V_60 -> V_55 = V_52 -> V_55 + V_52 -> V_59 + V_49 ;
V_48 -> V_57 = V_48 -> V_56 ;
V_60 -> V_59 = 0 ;
} else if ( ! V_52 -> V_59 ) {
-- V_48 -> V_54 ;
}
}
static int F_23 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_64 ;
int V_65 ;
unsigned V_66 = V_62 -> V_9 -> V_4 + 2 ;
V_65 = F_24 ( V_64 , V_62 -> V_67 ,
V_64 -> V_5 * V_64 -> V_68 ,
V_66 , 0 , & V_62 -> V_69 ) ;
return V_65 ;
}
static int F_25 ( struct V_61 * V_62 , struct V_43 * V_44 ,
struct V_1 * V_1 , unsigned V_70 )
{
struct V_71 * V_72 ;
struct V_47 * V_48 ;
struct V_61 * V_73 ;
unsigned V_74 = V_44 -> V_53 - ( V_44 -> V_53 %
( V_62 -> V_64 -> V_5 * V_62 -> V_64 -> V_68 ) ) ;
unsigned V_75 = V_44 -> V_53 - V_74 ;
unsigned V_76 ;
if ( ! V_62 -> V_69 ) {
int V_65 = F_23 ( V_62 ) ;
if ( F_8 ( V_65 ) )
return V_65 ;
}
V_73 = V_62 -> V_69 ;
V_73 -> V_77 = V_62 -> V_64 -> V_5 * V_62 -> V_64 -> V_68 ;
V_48 = & V_73 -> V_48 [ V_75 ] ;
if ( ! V_48 -> V_56 ) {
V_48 -> V_78 = F_26 ( V_2 ,
V_62 -> V_9 -> V_4 ) ;
if ( F_8 ( ! V_48 -> V_78 ) ) {
F_9 ( L_5 ,
V_62 -> V_9 -> V_4 ) ;
return - V_28 ;
}
V_48 -> V_55 = V_44 -> V_79 ;
V_48 -> V_53 = V_44 -> V_53 ;
} else if ( V_44 -> V_79 != ( V_48 -> V_55 + V_48 -> V_56 ) ) {
T_1 V_80 = V_44 -> V_79 - ( V_48 -> V_55 + V_48 -> V_56 ) ;
F_21 ( V_48 , V_80 , true ) ;
}
V_72 = F_27 ( F_28 ( V_73 -> V_67 , V_48 -> V_53 ) ) ;
V_76 = F_29 ( V_72 , V_48 -> V_78 , V_1 , V_70 ,
V_44 -> V_79 % V_27 ) ;
if ( F_8 ( V_76 != V_70 ) ) {
F_9 ( L_6 ,
V_48 -> V_78 -> V_81 ) ;
return - V_28 ;
}
V_48 -> V_56 += V_70 ;
return 0 ;
}
static int F_30 ( struct V_61 * V_62 , struct V_1 * V_1 )
{
struct V_43 V_44 ;
unsigned V_70 ;
F_31 ( V_62 -> V_64 , V_62 -> V_55 , 0 , & V_44 ) ;
V_70 = V_44 . V_79 % V_27 ;
V_44 . V_79 -= V_70 ;
F_9 ( L_7 ,
F_22 ( V_44 . V_79 ) , V_70 , V_1 -> V_82 , V_44 . V_53 ) ;
return F_25 ( V_62 , & V_44 , V_1 , V_70 ) ;
}
static int F_32 ( struct V_61 * V_62 , T_1 * V_55 )
{
struct V_43 V_44 ;
struct V_1 * V_1 ;
unsigned V_70 , V_3 , V_33 ;
F_31 ( V_62 -> V_64 , * V_55 , 0 , & V_44 ) ;
V_3 = V_44 . V_83 / V_27 ;
V_33 = F_33 ( V_62 -> V_64 -> V_5 * V_62 -> V_64 -> V_68 ,
V_62 -> V_64 -> V_68 , V_44 . V_84 , V_44 . V_53 ) ;
V_1 = V_62 -> V_9 -> V_14 [ V_3 ] . V_17 [ V_33 ] ;
V_70 = V_27 - ( V_44 . V_83 % V_27 ) ;
* V_55 += V_70 ;
F_9 ( L_8 ,
V_3 , V_33 , F_22 ( * V_55 ) , V_70 , V_44 . V_53 , V_44 . V_84 ) ;
F_6 ( ! V_1 ) ;
return F_25 ( V_62 , & V_44 , V_1 , V_70 ) ;
}
static void F_34 ( struct V_61 * V_62 , int V_65 )
{
struct V_85 * V_86 ;
unsigned V_26 , V_87 ;
for ( V_87 = 0 ; V_87 < V_62 -> V_77 ; V_87 ++ ) {
struct V_78 * V_78 = V_62 -> V_48 [ V_87 ] . V_78 ;
if ( ! V_78 )
continue;
F_35 (bv, bio, i, 0 ) {
struct V_1 * V_1 = V_86 -> V_88 ;
F_36 ( V_1 ) ;
if ( F_37 ( V_1 ) )
F_38 ( V_1 ) ;
}
}
}
static int F_39 ( struct V_61 * V_62 )
{
struct V_43 V_89 ;
struct V_7 * V_9 = V_62 -> V_9 ;
T_1 V_55 = V_62 -> V_44 . V_90 ;
unsigned V_33 , V_3 , V_91 = V_9 -> V_4 , V_92 = - 1 ;
if ( V_55 == V_62 -> V_55 )
goto V_93;
V_91 = F_14 ( V_9 ) ;
V_92 = F_15 ( V_9 ) ;
F_9 ( L_9 ,
V_55 , V_62 -> V_55 , V_91 , V_92 ) ;
for ( V_33 = 0 ; ; V_33 ++ ) {
F_31 ( V_62 -> V_64 , V_55 , 0 , & V_89 ) ;
V_89 . V_79 += V_91 * V_27 ;
V_55 += V_91 * V_27 ;
for ( V_3 = V_91 ; V_3 <= V_92 ; V_3 ++ ) {
struct V_13 * V_35 = & V_9 -> V_14 [ V_3 ] ;
struct V_1 * * V_94 = & V_35 -> V_17 [ V_33 ] ;
bool V_95 ;
if ( * V_94 ) {
if ( V_62 -> V_55 % V_27 )
F_30 ( V_62 , * V_94 ) ;
goto V_93;
}
* V_94 = V_62 -> V_31 -> V_96 ( V_62 -> V_97 , V_55 ,
& V_95 ) ;
if ( F_8 ( ! * V_94 ) )
return - V_28 ;
if ( ! V_95 )
F_25 ( V_62 , & V_89 , * V_94 , V_27 ) ;
V_35 -> V_19 [ V_33 ] = true ;
V_89 . V_79 += V_27 ;
V_55 += V_27 ;
}
V_55 += ( V_9 -> V_4 - V_3 ) * V_27 ;
}
V_93:
return 0 ;
}
static int F_40 ( struct V_61 * V_62 )
{
struct V_43 V_89 ;
struct V_7 * V_9 = V_62 -> V_9 ;
T_1 V_55 ;
T_1 V_98 ;
unsigned V_99 = V_62 -> V_44 . V_99 ;
unsigned V_33 , V_3 , V_91 = V_9 -> V_4 , V_92 = - 1 ;
V_55 = V_62 -> V_55 + V_62 -> V_56 ;
if ( V_55 % V_27 )
F_32 ( V_62 , & V_55 ) ;
V_98 = F_41 ( V_55 + V_99 - 1 , V_99 )
* V_99 ;
if ( V_55 == V_98 )
goto V_100;
F_31 ( V_62 -> V_64 , V_55 , 0 , & V_89 ) ;
V_3 = V_89 . V_83 / V_27 ;
V_33 = F_33 ( V_62 -> V_64 -> V_5 * V_62 -> V_64 -> V_68 ,
V_62 -> V_64 -> V_68 , V_89 . V_84 , V_89 . V_53 ) ;
if ( V_91 == V_9 -> V_4 ) {
V_91 = F_14 ( V_9 ) ;
V_92 = F_15 ( V_9 ) ;
}
F_9 ( L_10 ,
V_55 , V_98 , V_91 , V_92 ) ;
while ( V_55 < V_98 ) {
struct V_13 * V_35 = & V_9 -> V_14 [ V_3 ] ;
if ( ( V_91 <= V_3 ) && ( V_3 <= V_92 ) ) {
struct V_1 * V_1 ;
bool V_95 ;
F_6 ( V_35 -> V_17 [ V_33 ] ) ;
V_1 = V_62 -> V_31 -> V_96 ( V_62 -> V_97 , V_55 ,
& V_95 ) ;
if ( F_8 ( ! V_1 ) )
return - V_28 ;
V_35 -> V_17 [ V_33 ] = V_1 ;
V_35 -> V_19 [ V_33 ] = true ;
if ( ! V_95 )
F_25 ( V_62 , & V_89 , V_1 , V_27 ) ;
}
V_55 += V_27 ;
if ( V_3 == ( V_9 -> V_4 - 1 ) ) {
++ V_33 ;
V_3 = 0 ;
F_31 ( V_62 -> V_64 , V_55 , 0 , & V_89 ) ;
} else {
V_89 . V_79 += V_27 ;
++ V_3 ;
}
}
V_100:
return 0 ;
}
static int F_42 ( struct V_61 * V_62 )
{
struct V_61 * V_101 ;
unsigned V_26 ;
int V_65 ;
V_101 = V_62 -> V_69 ;
if ( ! V_101 )
return 0 ;
V_101 -> V_17 = V_62 -> V_17 ;
for ( V_26 = 0 ; V_26 < V_101 -> V_77 ; V_26 += V_101 -> V_64 -> V_68 ) {
V_65 = F_43 ( V_101 , V_26 ) ;
if ( F_8 ( V_65 ) )
return V_65 ;
}
V_65 = F_44 ( V_101 ) ;
if ( F_8 ( V_65 ) ) {
F_9 ( L_11 , V_65 ) ;
return V_65 ;
}
F_34 ( V_101 , V_65 ) ;
F_45 ( V_101 ) ;
V_62 -> V_69 = NULL ;
return 0 ;
}
int F_46 ( struct V_61 * V_62 ,
struct V_43 * V_44 ,
struct V_47 * V_48 ,
unsigned V_49 )
{
if ( V_62 -> V_102 ) {
if ( V_48 -> V_54 >= V_62 -> V_66 ) {
F_9 ( L_12 ,
V_48 -> V_54 , V_62 -> V_66 ) ;
return - V_28 ;
}
F_21 ( V_48 , V_49 , true ) ;
} else {
struct V_7 * V_9 = V_62 -> V_9 ;
struct V_1 * * V_17 = V_62 -> V_103 + V_62 -> V_104 ;
unsigned V_105 ;
unsigned V_106 = 0 ;
unsigned V_26 ;
int V_65 ;
V_44 -> V_45 = F_14 ( V_9 ) ;
V_105 = F_15 ( V_9 ) + 1 - V_44 -> V_45 ;
if ( ! V_49 )
V_44 -> V_46 = V_9 -> V_10 ;
if ( ! V_48 -> V_56 ) {
V_48 -> V_55 += V_44 -> V_45 * V_27 ;
F_39 ( V_62 ) ;
}
if ( ! V_49 )
F_40 ( V_62 ) ;
F_42 ( V_62 ) ;
for ( V_26 = 0 ; V_26 < V_105 ; V_26 ++ ) {
V_17 [ V_26 ] = F_1 () ;
if ( F_8 ( ! V_17 [ V_26 ] ) )
return - V_28 ;
++ ( V_62 -> V_104 ) ;
}
F_6 ( V_44 -> V_46 != V_9 -> V_10 ) ;
F_6 ( V_44 -> V_45 + V_105 > V_9 -> V_4 ) ;
V_65 = F_47 ( V_62 , & V_106 , 0 , V_17 ,
V_48 , V_105 * V_27 ) ;
if ( F_8 ( V_65 ) )
return V_65 ;
F_16 ( V_9 ) ;
F_11 ( V_9 , V_62 -> V_31 , V_62 -> V_97 ) ;
}
return 0 ;
}
int F_48 ( struct V_61 * V_62 )
{
if ( V_62 -> V_103 ) {
struct V_63 * V_64 = V_62 -> V_64 ;
unsigned V_4 = V_64 -> V_107 / V_27 ;
if ( F_5 ( V_4 , V_64 -> V_5 ,
V_64 -> V_6 , & V_62 -> V_9 ) ) {
return - V_28 ;
}
}
return 0 ;
}
void F_49 ( struct V_61 * V_62 )
{
if ( V_62 -> V_9 ) {
unsigned V_26 ;
for ( V_26 = 0 ; V_26 < V_62 -> V_104 ; V_26 ++ ) {
struct V_1 * V_1 = V_62 -> V_103 [ V_26 ] ;
if ( V_1 )
F_3 ( V_1 ) ;
}
if ( V_62 -> V_108 )
F_13 ( V_62 -> V_103 ) ;
F_11 ( V_62 -> V_9 , V_62 -> V_31 , V_62 -> V_97 ) ;
F_12 ( V_62 -> V_9 ) ;
} else {
if ( V_62 -> V_108 )
F_13 ( V_62 -> V_48 [ 0 ] . V_58 ) ;
}
if ( V_62 -> V_69 )
F_45 ( V_62 -> V_69 ) ;
}
