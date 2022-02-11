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
unsigned V_3 ;
if ( ! V_9 -> V_33 )
return;
for ( V_3 = 0 ; V_3 < V_9 -> V_4 ; V_3 ++ ) {
struct V_13 * V_34 = & V_9 -> V_14 [ V_3 ] ;
if ( V_34 -> V_35 < V_5 ) {
unsigned V_36 ;
for ( V_36 = 0 ; V_36 < V_10 ; V_36 ++ )
if ( V_34 -> V_19 [ V_36 ] ) {
struct V_1 * V_1 = V_34 -> V_17 [ V_36 ] ;
V_31 -> V_37 ( V_32 , V_1 ) ;
V_34 -> V_19 [ V_36 ] = false ;
}
}
memset ( V_34 -> V_17 , 0 , V_5 * sizeof( * V_34 -> V_17 ) ) ;
V_34 -> V_35 = 0 ;
V_34 -> V_38 = NULL ;
}
V_9 -> V_33 = false ;
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
struct V_13 * V_34 = & V_9 -> V_14 [ V_3 ] ;
if ( V_34 -> V_35 )
return V_3 ;
}
return ~ 0 ;
}
static unsigned F_15 ( struct V_7 * V_9 )
{
unsigned V_3 ;
for ( V_3 = V_9 -> V_4 - 1 ; V_3 >= 0 ; -- V_3 ) {
struct V_13 * V_34 = & V_9 -> V_14 [ V_3 ] ;
if ( V_34 -> V_35 )
return V_3 ;
}
return ~ 0 ;
}
static void F_16 ( struct V_7 * V_9 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_4 ; V_3 ++ ) {
struct V_13 * V_34 = & V_9 -> V_14 [ V_3 ] ;
if ( ! V_34 -> V_35 )
continue;
F_17 ( & V_34 -> V_39 ,
V_40 | V_41 ,
NULL ,
NULL , NULL ,
( V_42 * ) V_34 -> V_18 ) ;
V_34 -> V_38 = F_18 ( V_34 -> V_17 [ V_9 -> V_10 ] , V_34 -> V_17 ,
0 , V_9 -> V_10 , V_27 ,
& V_34 -> V_39 ) ;
}
for ( V_3 = 0 ; V_3 < V_9 -> V_4 ; V_3 ++ ) {
struct V_13 * V_34 = & V_9 -> V_14 [ V_3 ] ;
F_19 ( V_34 -> V_38 ) ;
}
}
void F_20 ( struct V_7 * V_9 ,
struct V_43 * V_44 , struct V_1 * V_1 )
{
struct V_13 * V_34 ;
V_9 -> V_33 = true ;
V_34 = & V_9 -> V_14 [ V_44 -> V_45 ] ;
V_34 -> V_17 [ V_44 -> V_46 ] = V_1 ;
++ V_34 -> V_35 ;
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
static int F_25 ( struct V_61 * V_62 ,
struct V_43 * V_44 , struct V_1 * V_1 )
{
struct V_70 * V_71 ;
struct V_47 * V_48 ;
struct V_61 * V_72 ;
unsigned V_73 = V_44 -> V_53 - ( V_44 -> V_53 %
( V_62 -> V_64 -> V_5 * V_62 -> V_64 -> V_68 ) ) ;
unsigned V_74 = V_44 -> V_53 - V_73 ;
unsigned V_75 ;
if ( ! V_62 -> V_69 ) {
int V_65 = F_23 ( V_62 ) ;
if ( F_8 ( V_65 ) )
return V_65 ;
}
V_72 = V_62 -> V_69 ;
V_72 -> V_76 = V_62 -> V_64 -> V_5 * V_62 -> V_64 -> V_68 ;
V_48 = & V_72 -> V_48 [ V_74 ] ;
if ( ! V_48 -> V_56 ) {
V_48 -> V_77 = F_26 ( V_2 ,
V_62 -> V_9 -> V_4 ) ;
if ( F_8 ( ! V_48 -> V_77 ) ) {
F_9 ( L_5 ,
V_62 -> V_9 -> V_4 ) ;
return - V_28 ;
}
V_48 -> V_55 = V_44 -> V_78 ;
V_48 -> V_53 = V_44 -> V_53 ;
} else if ( V_44 -> V_78 != ( V_48 -> V_55 + V_48 -> V_56 ) ) {
T_1 V_79 = V_44 -> V_78 - ( V_48 -> V_55 + V_48 -> V_56 ) ;
F_21 ( V_48 , V_79 , true ) ;
}
V_71 = F_27 ( F_28 ( V_72 -> V_67 , V_48 -> V_53 ) ) ;
V_75 = F_29 ( V_71 , V_48 -> V_77 , V_1 , V_27 , 0 ) ;
if ( F_8 ( V_75 != V_27 ) ) {
F_9 ( L_6 ,
V_48 -> V_77 -> V_80 ) ;
return - V_28 ;
}
V_48 -> V_56 += V_27 ;
return 0 ;
}
static void F_30 ( struct V_61 * V_62 , int V_65 )
{
struct V_81 * V_82 ;
unsigned V_26 , V_83 ;
for ( V_83 = 0 ; V_83 < V_62 -> V_76 ; V_83 ++ ) {
struct V_77 * V_77 = V_62 -> V_48 [ V_83 ] . V_77 ;
if ( ! V_77 )
continue;
F_31 (bv, bio, i, 0 ) {
struct V_1 * V_1 = V_82 -> V_84 ;
F_32 ( V_1 ) ;
if ( F_33 ( V_1 ) )
F_34 ( V_1 ) ;
}
}
}
static int F_35 ( struct V_61 * V_62 )
{
struct V_61 * V_85 ;
struct V_43 V_86 ;
struct V_7 * V_9 = V_62 -> V_9 ;
T_1 V_55 = V_62 -> V_44 . V_87 ;
T_1 V_88 ;
unsigned V_89 = V_62 -> V_44 . V_89 ;
unsigned V_26 , V_36 , V_3 , V_90 = V_9 -> V_4 , V_91 = - 1 ;
int V_65 ;
if ( V_55 == V_62 -> V_55 )
goto V_92;
V_90 = F_14 ( V_9 ) ;
V_91 = F_15 ( V_9 ) ;
for ( V_36 = 0 ; ; V_36 ++ ) {
F_36 ( V_62 -> V_64 , V_55 , 0 , & V_86 ) ;
V_86 . V_78 += V_90 * V_27 ;
V_55 += V_90 * V_27 ;
for ( V_3 = V_90 ; V_3 <= V_91 ; V_3 ++ ) {
struct V_13 * V_34 = & V_9 -> V_14 [ V_3 ] ;
struct V_1 * * V_93 = & V_34 -> V_17 [ V_36 ] ;
bool V_94 ;
if ( * V_93 )
goto V_92;
* V_93 = V_62 -> V_31 -> V_95 ( V_62 -> V_96 , V_55 ,
& V_94 ) ;
if ( F_8 ( ! * V_93 ) )
return - V_28 ;
if ( ! V_94 )
F_25 ( V_62 , & V_86 , * V_93 ) ;
V_34 -> V_19 [ V_36 ] = true ;
V_86 . V_78 += V_27 ;
V_55 += V_27 ;
}
V_55 += ( V_9 -> V_4 - V_3 ) * V_27 ;
}
V_92:
V_55 = V_62 -> V_55 + ( V_62 -> V_56 + V_27 - 1 ) /
V_27 * V_27 ;
V_88 = F_37 ( V_55 + V_89 - 1 , V_89 )
* V_89 ;
if ( V_55 == V_88 )
goto V_97;
F_36 ( V_62 -> V_64 , V_55 , 0 , & V_86 ) ;
V_3 = V_86 . V_98 / V_27 ;
V_36 = F_38 ( V_62 -> V_64 -> V_5 * V_62 -> V_64 -> V_68 ,
V_62 -> V_64 -> V_68 , V_86 . V_99 , V_86 . V_53 ) ;
F_6 ( V_62 -> V_44 . V_87 + V_89 != V_88 ) ;
if ( V_90 == V_9 -> V_4 ) {
V_90 = F_14 ( V_9 ) ;
V_91 = F_15 ( V_9 ) ;
}
while ( V_55 < V_88 ) {
struct V_13 * V_34 = & V_9 -> V_14 [ V_3 ] ;
if ( ( V_90 <= V_3 ) && ( V_3 <= V_91 ) ) {
struct V_1 * V_1 ;
bool V_94 ;
F_6 ( V_34 -> V_17 [ V_36 ] ) ;
V_1 = V_62 -> V_31 -> V_95 ( V_62 -> V_96 , V_55 ,
& V_94 ) ;
if ( F_8 ( ! V_1 ) )
return - V_28 ;
V_34 -> V_17 [ V_36 ] = V_1 ;
V_34 -> V_19 [ V_36 ] = true ;
if ( ! V_94 )
F_25 ( V_62 , & V_86 , V_1 ) ;
}
V_55 += V_27 ;
if ( V_3 == ( V_9 -> V_4 - 1 ) ) {
++ V_36 ;
V_3 = 0 ;
F_36 ( V_62 -> V_64 , V_55 , 0 , & V_86 ) ;
} else {
V_86 . V_78 += V_27 ;
++ V_3 ;
}
}
V_97:
V_85 = V_62 -> V_69 ;
if ( ! V_85 )
return 0 ;
V_85 -> V_17 = V_62 -> V_17 ;
for ( V_26 = 0 ; V_26 < V_85 -> V_76 ; V_26 += V_85 -> V_64 -> V_68 ) {
V_65 = F_39 ( V_85 , V_26 ) ;
if ( F_8 ( V_65 ) )
return V_65 ;
}
V_65 = F_40 ( V_85 ) ;
if ( F_8 ( V_65 ) ) {
F_9 ( L_7 , V_65 ) ;
return V_65 ;
}
F_30 ( V_85 , V_65 ) ;
return 0 ;
}
int F_41 ( struct V_61 * V_62 ,
struct V_43 * V_44 ,
struct V_47 * V_48 ,
unsigned V_49 )
{
if ( V_62 -> V_100 ) {
F_6 ( V_48 -> V_54 >= V_62 -> V_66 ) ;
F_21 ( V_48 , V_49 , true ) ;
} else {
struct V_7 * V_9 = V_62 -> V_9 ;
struct V_1 * * V_17 = V_62 -> V_101 + V_62 -> V_102 ;
unsigned V_103 ;
unsigned V_104 = 0 ;
unsigned V_26 ;
int V_65 ;
V_44 -> V_45 = F_14 ( V_9 ) ;
V_103 = F_15 ( V_9 ) + 1 - V_44 -> V_45 ;
if ( ! V_49 )
V_44 -> V_46 = V_9 -> V_10 ;
if ( ! V_48 -> V_56 ) {
V_48 -> V_55 += V_44 -> V_45 * V_27 ;
F_35 ( V_62 ) ;
}
for ( V_26 = 0 ; V_26 < V_103 ; V_26 ++ ) {
V_17 [ V_26 ] = F_1 () ;
if ( F_8 ( ! V_17 [ V_26 ] ) )
return - V_28 ;
++ ( V_62 -> V_102 ) ;
}
F_6 ( V_44 -> V_46 != V_9 -> V_10 ) ;
F_6 ( V_44 -> V_45 + V_103 > V_9 -> V_4 ) ;
V_65 = F_42 ( V_62 , & V_104 , 0 , V_17 ,
V_48 , V_103 * V_27 ) ;
if ( F_8 ( V_65 ) )
return V_65 ;
F_16 ( V_9 ) ;
F_11 ( V_9 , V_62 -> V_31 , V_62 -> V_96 ) ;
}
return 0 ;
}
int F_43 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_64 ;
if ( V_62 -> V_101 ) {
unsigned V_4 = V_64 -> V_105 / V_27 ;
unsigned V_106 = V_62 -> V_44 . V_89 ;
T_1 V_107 , V_108 ;
if ( F_5 ( V_4 , V_64 -> V_5 ,
V_64 -> V_6 , & V_62 -> V_9 ) ) {
return - V_28 ;
}
F_6 ( V_62 -> V_55 % V_27 ) ;
V_108 = F_37 ( V_62 -> V_55 , V_106 ) ;
V_107 = F_37 ( V_62 -> V_55 + V_62 -> V_56 , V_106 ) ;
if ( V_107 != V_108 ) {
V_62 -> V_56 = V_107 * V_106 - V_62 -> V_55 ;
F_6 ( ! V_62 -> V_56 ) ;
V_62 -> V_109 = ( V_62 -> V_56 + V_27 - 1 ) /
V_27 ;
V_62 -> V_44 . V_56 = V_62 -> V_56 ;
}
}
return 0 ;
}
void F_44 ( struct V_61 * V_62 )
{
if ( V_62 -> V_9 ) {
unsigned V_26 ;
for ( V_26 = 0 ; V_26 < V_62 -> V_102 ; V_26 ++ ) {
struct V_1 * V_1 = V_62 -> V_101 [ V_26 ] ;
if ( V_1 )
F_3 ( V_1 ) ;
}
if ( V_62 -> V_110 )
F_13 ( V_62 -> V_101 ) ;
F_11 ( V_62 -> V_9 , V_62 -> V_31 , V_62 -> V_96 ) ;
F_12 ( V_62 -> V_9 ) ;
} else {
if ( V_62 -> V_110 )
F_13 ( V_62 -> V_48 [ 0 ] . V_58 ) ;
}
if ( V_62 -> V_69 )
F_45 ( V_62 -> V_69 ) ;
}
