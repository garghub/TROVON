static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
T_1 V_6 , V_7 , V_8 ;
bool V_9 ;
struct V_10 V_11 ;
do {
V_6 = V_2 -> V_12 -> V_13 ( V_2 , V_3 ) ;
V_9 = F_2 ( V_2 , V_3 , & V_11 , 0 ) ;
} while ( V_6 != V_2 -> V_12 -> V_13 ( V_2 , V_3 ) );
V_7 = V_6 - V_5 -> V_14 ;
if ( V_6 < V_5 -> V_14 ) {
V_7 += V_2 -> V_15 ;
F_3 ( L_1 ,
V_3 , V_5 -> V_14 , V_6 , V_7 ) ;
}
F_3 ( L_2 ,
V_3 , V_7 ) ;
if ( V_7 == 0 )
return;
V_8 = F_4 ( & V_5 -> V_16 ) + V_7 ;
F_5 ( V_2 , V_3 , V_8 ) = V_9 ? V_11 : (struct V_10 ) { 0 , 0 } ;
F_6 () ;
F_7 ( V_7 , & V_5 -> V_16 ) ;
F_8 () ;
}
static void F_9 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
unsigned long V_17 ;
T_1 V_18 ;
T_2 V_19 ;
bool V_20 ;
struct V_10 V_21 ;
int V_16 = V_22 ;
F_10 ( & V_2 -> V_23 , V_17 ) ;
if ( ! V_5 -> V_24 &&
F_2 ( V_2 , V_3 , & V_21 , 0 ) ) {
F_1 ( V_2 , V_3 ) ;
F_11 ( & V_2 -> V_23 , V_17 ) ;
return;
}
if ( V_5 -> V_24 ) {
V_2 -> V_12 -> V_25 ( V_2 , V_3 ) ;
V_5 -> V_24 = false ;
}
do {
V_5 -> V_14 = V_2 -> V_12 -> V_13 ( V_2 , V_3 ) ;
V_20 = F_2 ( V_2 , V_3 , & V_21 , 0 ) ;
} while ( V_5 -> V_14 != V_2 -> V_12 -> V_13 ( V_2 , V_3 ) && ( -- V_16 ) && V_20 );
if ( ! V_16 )
V_20 = 0 ;
V_18 = F_4 ( & V_5 -> V_16 ) ;
V_19 = F_12 ( & V_21 ) -
F_12 ( & F_5 ( V_2 , V_3 , V_18 ) ) ;
if ( V_20 && ( F_13 ( V_19 ) > 1000000 ) ) {
F_5 ( V_2 , V_3 , V_18 + 1 ) = V_21 ;
F_6 () ;
F_14 ( & V_5 -> V_16 ) ;
F_8 () ;
}
F_11 ( & V_2 -> V_23 , V_17 ) ;
}
static void F_15 ( unsigned long V_26 )
{
struct V_4 * V_5 = ( void * ) V_26 ;
struct V_1 * V_2 = V_5 -> V_2 ;
unsigned long V_17 ;
int V_3 = V_5 -> V_3 ;
if ( ! V_2 -> V_27 )
return;
F_10 ( & V_2 -> V_28 , V_17 ) ;
if ( F_4 ( & V_5 -> V_29 ) == 0 && V_5 -> V_24 ) {
F_3 ( L_3 , V_3 ) ;
F_9 ( V_2 , V_3 ) ;
}
F_11 ( & V_2 -> V_28 , V_17 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_30 == 0 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_30 ; V_3 ++ ) {
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
F_17 ( V_5 -> V_24 &&
F_18 ( V_2 , V_31 ) ) ;
F_19 ( & V_5 -> V_32 ) ;
}
F_20 ( V_2 -> V_5 ) ;
V_2 -> V_30 = 0 ;
}
int F_21 ( struct V_1 * V_2 , int V_30 )
{
int V_33 , V_34 = - V_35 ;
F_22 ( & V_2 -> V_28 ) ;
F_22 ( & V_2 -> V_23 ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_5 = F_23 ( V_30 , sizeof( * V_2 -> V_5 ) , V_36 ) ;
if ( ! V_2 -> V_5 )
goto V_37;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ ) {
struct V_4 * V_5 = & V_2 -> V_5 [ V_33 ] ;
V_5 -> V_2 = V_2 ;
V_5 -> V_3 = V_33 ;
F_24 ( & V_5 -> V_38 ) ;
F_25 ( & V_5 -> V_32 , F_15 ,
( unsigned long ) V_5 ) ;
}
F_26 ( L_4 ) ;
if ( V_2 -> V_12 -> V_39 )
F_26 ( L_5 ) ;
else
F_26 ( L_6 ) ;
V_2 -> V_27 = false ;
return 0 ;
V_37:
V_2 -> V_30 = 0 ;
return V_34 ;
}
static void F_27 ( void * V_40 , bool V_41 )
{
struct V_1 * V_2 = V_40 ;
if ( V_2 -> V_12 -> V_42 ) {
V_2 -> V_12 -> V_42 ( V_2 , V_41 ) ;
return;
}
if ( ! V_2 -> V_43 )
return;
if ( V_41 ) {
if ( V_2 -> V_12 -> V_44 )
V_2 -> V_12 -> V_44 ( V_2 ) ;
} else {
if ( V_2 -> V_12 -> V_45 )
V_2 -> V_12 -> V_45 ( V_2 ) ;
if ( V_2 -> V_12 -> V_46 )
V_2 -> V_12 -> V_46 ( V_2 ) ;
}
}
int F_28 ( struct V_1 * V_2 , int V_47 )
{
int V_34 ;
unsigned long V_48 = 0 ;
if ( ! F_18 ( V_2 , V_49 ) )
return - V_50 ;
if ( V_47 == 0 )
return - V_50 ;
if ( ! V_2 -> V_51 )
return - V_50 ;
if ( V_2 -> V_43 )
return - V_52 ;
V_2 -> V_43 = true ;
F_3 ( L_7 , V_47 ) ;
if ( V_2 -> V_12 -> V_45 )
V_2 -> V_12 -> V_45 ( V_2 ) ;
if ( F_18 ( V_2 , V_53 ) )
V_48 = V_54 ;
V_34 = F_29 ( V_47 , V_2 -> V_12 -> V_55 ,
V_48 , V_2 -> V_12 -> V_56 , V_2 ) ;
if ( V_34 < 0 ) {
V_2 -> V_43 = false ;
return V_34 ;
}
if ( ! F_18 ( V_2 , V_31 ) )
F_30 ( V_2 -> V_57 , ( void * ) V_2 , F_27 , NULL ) ;
if ( V_2 -> V_12 -> V_46 )
V_34 = V_2 -> V_12 -> V_46 ( V_2 ) ;
if ( V_34 < 0 ) {
V_2 -> V_43 = false ;
if ( ! F_18 ( V_2 , V_31 ) )
F_30 ( V_2 -> V_57 , NULL , NULL , NULL ) ;
F_31 ( V_47 , V_2 ) ;
} else {
V_2 -> V_47 = V_47 ;
}
return V_34 ;
}
int F_32 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
bool V_43 ;
int V_33 ;
if ( ! F_18 ( V_2 , V_49 ) )
return - V_50 ;
V_43 = V_2 -> V_43 ;
V_2 -> V_43 = false ;
if ( V_2 -> V_30 ) {
F_10 ( & V_2 -> V_28 , V_17 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_30 ; V_33 ++ ) {
struct V_4 * V_5 = & V_2 -> V_5 [ V_33 ] ;
if ( ! V_5 -> V_24 )
continue;
F_17 ( F_18 ( V_2 , V_31 ) ) ;
F_9 ( V_2 , V_33 ) ;
F_33 ( & V_5 -> V_38 ) ;
}
F_11 ( & V_2 -> V_28 , V_17 ) ;
}
if ( ! V_43 )
return - V_50 ;
F_3 ( L_7 , V_2 -> V_47 ) ;
if ( ! F_18 ( V_2 , V_31 ) )
F_30 ( V_2 -> V_57 , NULL , NULL , NULL ) ;
if ( V_2 -> V_12 -> V_44 )
V_2 -> V_12 -> V_44 ( V_2 ) ;
F_31 ( V_2 -> V_47 , V_2 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 , void * V_58 ,
struct V_59 * V_60 )
{
struct F_34 * V_61 = V_58 ;
int V_34 = 0 , V_47 ;
if ( ! F_18 ( V_2 , V_49 ) )
return 0 ;
if ( F_18 ( V_2 , V_31 ) )
return 0 ;
if ( F_17 ( ! V_2 -> V_57 ) )
return - V_50 ;
switch ( V_61 -> V_62 ) {
case V_63 :
V_47 = V_2 -> V_57 -> V_47 ;
if ( V_2 -> V_64 < F_35 ( 1 , 2 ) &&
V_61 -> V_47 != V_47 )
return - V_50 ;
F_36 ( & V_2 -> V_65 ) ;
V_34 = F_28 ( V_2 , V_47 ) ;
F_37 ( & V_2 -> V_65 ) ;
return V_34 ;
case V_66 :
F_36 ( & V_2 -> V_65 ) ;
V_34 = F_32 ( V_2 ) ;
F_37 ( & V_2 -> V_65 ) ;
return V_34 ;
default:
return - V_50 ;
}
}
void F_38 ( struct V_67 * V_3 ,
const struct V_68 * V_69 )
{
int V_70 = 0 , V_71 = 0 , V_72 = 0 ;
int V_73 = V_69 -> V_74 ;
if ( V_73 > 0 ) {
int V_75 = V_69 -> V_76 * V_69 -> V_77 ;
V_71 = 1000000 / V_73 ;
V_70 = F_39 ( ( V_78 ) V_69 -> V_76 * 1000000 , V_73 ) ;
V_72 = F_39 ( ( V_78 ) V_75 * 1000000 , V_73 ) ;
if ( V_69 -> V_79 & V_80 )
V_72 /= 2 ;
} else
F_40 ( L_8 ,
V_3 -> V_81 . V_82 ) ;
V_3 -> V_71 = V_71 ;
V_3 -> V_70 = V_70 ;
V_3 -> V_72 = V_72 ;
F_3 ( L_9 ,
V_3 -> V_81 . V_82 , V_69 -> V_76 ,
V_69 -> V_77 , V_69 -> V_83 ) ;
F_3 ( L_10 ,
V_3 -> V_81 . V_82 , V_73 , V_72 ,
V_70 , V_71 ) ;
}
int F_41 ( struct V_1 * V_2 , int V_3 ,
int * V_84 ,
struct V_10 * V_85 ,
unsigned V_79 ,
const struct V_67 * V_86 ,
const struct V_68 * V_69 )
{
struct V_10 V_87 ;
T_3 V_88 , V_89 ;
int V_90 ;
int V_91 , V_92 , V_33 ;
int V_72 , V_70 , V_71 , V_93 , V_94 ;
bool V_95 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_30 ) {
F_40 ( L_11 , V_3 ) ;
return - V_50 ;
}
if ( ! V_2 -> V_12 -> V_96 ) {
F_40 ( L_12 ) ;
return - V_97 ;
}
V_72 = V_86 -> V_72 ;
V_70 = V_86 -> V_70 ;
V_71 = V_86 -> V_71 ;
if ( V_72 == 0 ) {
F_3 ( L_13 , V_3 ) ;
return - V_98 ;
}
for ( V_33 = 0 ; V_33 < V_22 ; V_33 ++ ) {
V_90 = V_2 -> V_12 -> V_96 ( V_2 , V_3 , V_79 , & V_91 ,
& V_92 , & V_88 , & V_89 ) ;
if ( ! ( V_90 & V_99 ) ) {
F_3 ( L_14 ,
V_3 , V_90 ) ;
return - V_97 ;
}
V_94 = F_42 ( V_89 ) - F_42 ( V_88 ) ;
if ( V_94 <= * V_84 )
break;
}
if ( V_33 == V_22 ) {
F_3 ( L_15 ,
V_3 , V_94 / 1000 , * V_84 / 1000 , V_33 ) ;
}
* V_84 = V_94 ;
V_95 = V_90 & V_100 ;
V_93 = V_91 * V_70 + V_92 * V_71 ;
if ( ! V_101 )
V_89 = F_43 ( V_89 ) ;
V_87 = F_44 ( V_89 ) ;
if ( V_93 < 0 )
V_89 = F_45 ( V_89 , - V_93 ) ;
else
V_89 = F_46 ( V_89 , V_93 ) ;
* V_85 = F_44 ( V_89 ) ;
F_3 ( L_16 ,
V_3 , ( int ) V_90 , V_92 , V_91 ,
( long ) V_87 . V_102 , ( long ) V_87 . V_103 ,
( long ) V_85 -> V_102 , ( long ) V_85 -> V_103 ,
V_94 / 1000 , V_33 ) ;
V_90 = V_104 ;
if ( V_95 )
V_90 |= V_105 ;
return V_90 ;
}
static struct V_10 F_47 ( void )
{
T_3 V_106 ;
V_106 = V_101 ? F_48 () : F_49 () ;
return F_44 ( V_106 ) ;
}
static bool
F_2 ( struct V_1 * V_2 , int V_3 ,
struct V_10 * V_21 , unsigned V_79 )
{
int V_34 ;
int V_84 = ( int ) V_107 * 1000 ;
if ( V_2 -> V_12 -> V_39 && ( V_84 > 0 ) ) {
V_34 = V_2 -> V_12 -> V_39 ( V_2 , V_3 , & V_84 ,
V_21 , V_79 ) ;
if ( V_34 > 0 )
return true ;
}
* V_21 = F_47 () ;
return false ;
}
T_1 F_50 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
if ( F_17 ( V_3 >= V_2 -> V_30 ) )
return 0 ;
return F_4 ( & V_5 -> V_16 ) ;
}
T_1 F_51 ( struct V_67 * V_3 )
{
return F_50 ( V_3 -> V_2 , F_52 ( V_3 ) ) ;
}
T_1 F_53 ( struct V_1 * V_2 , int V_3 ,
struct V_10 * V_108 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
T_1 V_6 ;
if ( F_17 ( V_3 >= V_2 -> V_30 ) )
return 0 ;
do {
V_6 = F_4 ( & V_5 -> V_16 ) ;
* V_108 = F_5 ( V_2 , V_3 , V_6 ) ;
F_54 () ;
} while ( V_6 != F_4 ( & V_5 -> V_16 ) );
return V_6 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_109 * V_110 ,
unsigned long V_111 , struct V_10 * V_106 )
{
F_56 ( ! F_57 ( & V_2 -> V_112 ) ) ;
V_110 -> V_113 . V_114 = V_111 ;
V_110 -> V_113 . V_102 = V_106 -> V_102 ;
V_110 -> V_113 . V_103 = V_106 -> V_103 ;
F_58 ( & V_110 -> V_81 . V_115 ,
& V_110 -> V_81 . V_60 -> V_116 ) ;
F_59 ( & V_110 -> V_81 . V_60 -> V_117 ) ;
F_60 ( V_110 -> V_81 . V_118 , V_110 -> V_119 ,
V_110 -> V_113 . V_114 ) ;
}
void F_61 ( struct V_1 * V_2 , int V_3 ,
struct V_109 * V_110 )
{
struct V_10 V_106 ;
unsigned int V_111 ;
if ( V_3 >= 0 ) {
V_111 = F_53 ( V_2 , V_3 , & V_106 ) ;
} else {
V_111 = 0 ;
V_106 = F_47 () ;
}
V_110 -> V_119 = V_3 ;
F_55 ( V_2 , V_110 , V_111 , & V_106 ) ;
}
void F_62 ( struct V_67 * V_3 ,
struct V_109 * V_110 )
{
F_61 ( V_3 -> V_2 , F_52 ( V_3 ) , V_110 ) ;
}
static int F_63 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
int V_34 = 0 ;
F_64 ( & V_2 -> V_28 ) ;
F_65 ( & V_2 -> V_23 ) ;
if ( ! V_5 -> V_24 ) {
V_34 = V_2 -> V_12 -> V_120 ( V_2 , V_3 ) ;
F_3 ( L_17 , V_3 , V_34 ) ;
if ( V_34 )
F_66 ( & V_5 -> V_29 ) ;
else {
V_5 -> V_24 = true ;
F_1 ( V_2 , V_3 ) ;
}
}
F_67 ( & V_2 -> V_23 ) ;
return V_34 ;
}
int F_68 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
unsigned long V_17 ;
int V_34 = 0 ;
if ( F_17 ( V_3 >= V_2 -> V_30 ) )
return - V_50 ;
F_10 ( & V_2 -> V_28 , V_17 ) ;
if ( F_69 ( 1 , & V_5 -> V_29 ) == 1 ) {
V_34 = F_63 ( V_2 , V_3 ) ;
} else {
if ( ! V_5 -> V_24 ) {
F_66 ( & V_5 -> V_29 ) ;
V_34 = - V_50 ;
}
}
F_11 ( & V_2 -> V_28 , V_17 ) ;
return V_34 ;
}
int F_70 ( struct V_67 * V_3 )
{
return F_68 ( V_3 -> V_2 , F_52 ( V_3 ) ) ;
}
void F_71 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
if ( F_17 ( F_4 ( & V_5 -> V_29 ) == 0 ) )
return;
if ( F_17 ( V_3 >= V_2 -> V_30 ) )
return;
if ( F_72 ( & V_5 -> V_29 ) ) {
if ( V_121 == 0 )
return;
else if ( V_2 -> V_122 || V_121 < 0 )
F_15 ( ( unsigned long ) V_5 ) ;
else
F_73 ( & V_5 -> V_32 ,
V_123 + ( ( V_121 * V_124 ) / 1000 ) ) ;
}
}
void F_74 ( struct V_67 * V_3 )
{
F_71 ( V_3 -> V_2 , F_52 ( V_3 ) ) ;
}
void F_75 ( struct V_1 * V_2 , int V_3 )
{
int V_34 ;
T_1 V_14 ;
V_34 = F_68 ( V_2 , V_3 ) ;
if ( F_76 ( V_34 , L_18 , V_3 , V_34 ) )
return;
V_14 = F_50 ( V_2 , V_3 ) ;
V_34 = F_77 ( V_2 -> V_5 [ V_3 ] . V_38 ,
V_14 != F_50 ( V_2 , V_3 ) ,
F_78 ( 100 ) ) ;
F_76 ( V_34 == 0 , L_19 , V_3 ) ;
F_71 ( V_2 , V_3 ) ;
}
void F_79 ( struct V_67 * V_3 )
{
F_75 ( V_3 -> V_2 , F_52 ( V_3 ) ) ;
}
void F_80 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
struct V_109 * V_110 , * V_125 ;
struct V_10 V_106 ;
unsigned long V_17 ;
unsigned int V_111 ;
if ( F_17 ( V_3 >= V_2 -> V_30 ) )
return;
F_10 ( & V_2 -> V_112 , V_17 ) ;
F_65 ( & V_2 -> V_28 ) ;
F_9 ( V_2 , V_3 ) ;
F_33 ( & V_5 -> V_38 ) ;
if ( ! V_5 -> V_126 ) {
F_14 ( & V_5 -> V_29 ) ;
V_5 -> V_126 = 1 ;
}
F_67 ( & V_2 -> V_28 ) ;
V_111 = F_53 ( V_2 , V_3 , & V_106 ) ;
F_81 (e, t, &dev->vblank_event_list, base.link) {
if ( V_110 -> V_119 != V_3 )
continue;
F_3 ( L_20 ,
V_110 -> V_113 . V_114 , V_111 ) ;
F_82 ( & V_110 -> V_81 . V_115 ) ;
F_71 ( V_2 , V_110 -> V_119 ) ;
F_55 ( V_2 , V_110 , V_111 , & V_106 ) ;
}
F_11 ( & V_2 -> V_112 , V_17 ) ;
}
void F_83 ( struct V_67 * V_3 )
{
F_80 ( V_3 -> V_2 , F_52 ( V_3 ) ) ;
}
void F_84 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
unsigned long V_17 ;
int V_3 = F_52 ( V_67 ) ;
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
F_10 ( & V_2 -> V_28 , V_17 ) ;
if ( ! V_5 -> V_126 ) {
F_14 ( & V_5 -> V_29 ) ;
V_5 -> V_126 = 1 ;
}
F_11 ( & V_2 -> V_28 , V_17 ) ;
F_17 ( ! F_85 ( & V_2 -> V_127 ) ) ;
}
void F_86 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
unsigned long V_17 ;
if ( F_17 ( V_3 >= V_2 -> V_30 ) )
return;
F_10 ( & V_2 -> V_28 , V_17 ) ;
if ( V_5 -> V_126 ) {
F_66 ( & V_5 -> V_29 ) ;
V_5 -> V_126 = 0 ;
}
V_5 -> V_14 =
( V_2 -> V_12 -> V_13 ( V_2 , V_3 ) - 1 ) &
V_2 -> V_15 ;
if ( F_4 ( & V_5 -> V_29 ) != 0 ||
( ! V_2 -> V_122 && V_121 == 0 ) )
F_17 ( F_63 ( V_2 , V_3 ) ) ;
F_11 ( & V_2 -> V_28 , V_17 ) ;
}
void F_87 ( struct V_67 * V_3 )
{
F_86 ( V_3 -> V_2 , F_52 ( V_3 ) ) ;
}
void F_88 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
if ( ! V_2 -> V_30 )
return;
if ( F_17 ( V_3 >= V_2 -> V_30 ) )
return;
if ( ! V_5 -> V_126 ) {
V_5 -> V_126 = 0x1 ;
if ( F_68 ( V_2 , V_3 ) == 0 )
V_5 -> V_126 |= 0x2 ;
}
}
void F_89 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
unsigned long V_17 ;
if ( ! V_2 -> V_30 )
return;
if ( V_5 -> V_126 ) {
F_10 ( & V_2 -> V_28 , V_17 ) ;
V_2 -> V_27 = true ;
F_11 ( & V_2 -> V_28 , V_17 ) ;
if ( V_5 -> V_126 & 0x2 )
F_71 ( V_2 , V_3 ) ;
V_5 -> V_126 = 0 ;
}
}
int F_90 ( struct V_1 * V_2 , void * V_58 ,
struct V_59 * V_60 )
{
struct F_90 * V_128 = V_58 ;
unsigned int V_3 ;
if ( ! V_2 -> V_30 )
return 0 ;
if ( F_18 ( V_2 , V_31 ) )
return 0 ;
V_3 = V_128 -> V_3 ;
if ( V_3 >= V_2 -> V_30 )
return - V_50 ;
switch ( V_128 -> V_129 ) {
case V_130 :
F_88 ( V_2 , V_3 ) ;
break;
case V_131 :
F_89 ( V_2 , V_3 ) ;
break;
default:
return - V_50 ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , int V_119 ,
union V_132 * V_133 ,
struct V_59 * V_60 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_119 ] ;
struct V_109 * V_110 ;
struct V_10 V_106 ;
unsigned long V_79 ;
unsigned int V_111 ;
int V_34 ;
V_110 = F_92 ( sizeof( * V_110 ) , V_36 ) ;
if ( V_110 == NULL ) {
V_34 = - V_35 ;
goto V_134;
}
V_110 -> V_119 = V_119 ;
V_110 -> V_81 . V_118 = V_135 -> V_118 ;
V_110 -> V_113 . V_81 . type = V_136 ;
V_110 -> V_113 . V_81 . V_137 = sizeof( V_110 -> V_113 ) ;
V_110 -> V_113 . V_138 = V_133 -> V_139 . signal ;
V_110 -> V_81 . V_113 = & V_110 -> V_113 . V_81 ;
V_110 -> V_81 . V_60 = V_60 ;
V_110 -> V_81 . V_140 = ( void ( * ) ( struct V_141 * ) ) F_20 ;
F_10 ( & V_2 -> V_112 , V_79 ) ;
if ( ! V_5 -> V_24 ) {
V_34 = - V_50 ;
goto V_142;
}
if ( V_60 -> V_143 < sizeof( V_110 -> V_113 ) ) {
V_34 = - V_52 ;
goto V_142;
}
V_60 -> V_143 -= sizeof( V_110 -> V_113 ) ;
V_111 = F_53 ( V_2 , V_119 , & V_106 ) ;
if ( ( V_133 -> V_139 . type & V_144 ) &&
( V_111 - V_133 -> V_139 . V_114 ) <= ( 1 << 23 ) ) {
V_133 -> V_139 . V_114 = V_111 + 1 ;
V_133 -> V_145 . V_114 = V_133 -> V_139 . V_114 ;
}
F_3 ( L_21 ,
V_133 -> V_139 . V_114 , V_111 , V_119 ) ;
F_93 ( V_135 -> V_118 , V_119 ,
V_133 -> V_139 . V_114 ) ;
V_110 -> V_113 . V_114 = V_133 -> V_139 . V_114 ;
if ( ( V_111 - V_133 -> V_139 . V_114 ) <= ( 1 << 23 ) ) {
F_71 ( V_2 , V_119 ) ;
F_55 ( V_2 , V_110 , V_111 , & V_106 ) ;
V_133 -> V_145 . V_114 = V_111 ;
} else {
F_58 ( & V_110 -> V_81 . V_115 , & V_2 -> V_127 ) ;
V_133 -> V_145 . V_114 = V_133 -> V_139 . V_114 ;
}
F_11 ( & V_2 -> V_112 , V_79 ) ;
return 0 ;
V_142:
F_11 ( & V_2 -> V_112 , V_79 ) ;
F_20 ( V_110 ) ;
V_134:
F_71 ( V_2 , V_119 ) ;
return V_34 ;
}
int V_132 ( struct V_1 * V_2 , void * V_58 ,
struct V_59 * V_60 )
{
struct V_4 * V_5 ;
union V_132 * V_133 = V_58 ;
int V_34 ;
unsigned int V_79 , V_111 , V_3 , V_146 ;
if ( ! V_2 -> V_43 )
return - V_50 ;
if ( V_133 -> V_139 . type & V_147 )
return - V_50 ;
if ( V_133 -> V_139 . type &
~ ( V_148 | V_149 |
V_150 ) ) {
F_40 ( L_22 ,
V_133 -> V_139 . type ,
( V_148 | V_149 |
V_150 ) ) ;
return - V_50 ;
}
V_79 = V_133 -> V_139 . type & V_149 ;
V_146 = ( V_133 -> V_139 . type & V_150 ) ;
if ( V_146 )
V_3 = V_146 >> V_151 ;
else
V_3 = V_79 & V_152 ? 1 : 0 ;
if ( V_3 >= V_2 -> V_30 )
return - V_50 ;
V_5 = & V_2 -> V_5 [ V_3 ] ;
V_34 = F_68 ( V_2 , V_3 ) ;
if ( V_34 ) {
F_3 ( L_23 , V_34 ) ;
return V_34 ;
}
V_111 = F_50 ( V_2 , V_3 ) ;
switch ( V_133 -> V_139 . type & V_148 ) {
case V_153 :
V_133 -> V_139 . V_114 += V_111 ;
V_133 -> V_139 . type &= ~ V_153 ;
case V_154 :
break;
default:
V_34 = - V_50 ;
goto V_155;
}
if ( V_79 & V_156 ) {
return F_91 ( V_2 , V_3 , V_133 , V_60 ) ;
}
if ( ( V_79 & V_144 ) &&
( V_111 - V_133 -> V_139 . V_114 ) <= ( 1 << 23 ) ) {
V_133 -> V_139 . V_114 = V_111 + 1 ;
}
F_3 ( L_24 ,
V_133 -> V_139 . V_114 , V_3 ) ;
V_5 -> V_157 = V_133 -> V_139 . V_114 ;
F_94 ( V_34 , V_5 -> V_38 , 3 * V_124 ,
( ( ( F_50 ( V_2 , V_3 ) -
V_133 -> V_139 . V_114 ) <= ( 1 << 23 ) ) ||
! V_5 -> V_24 ||
! V_2 -> V_43 ) ) ;
if ( V_34 != - V_158 ) {
struct V_10 V_106 ;
V_133 -> V_145 . V_114 = F_53 ( V_2 , V_3 , & V_106 ) ;
V_133 -> V_145 . V_159 = V_106 . V_102 ;
V_133 -> V_145 . V_160 = V_106 . V_103 ;
F_3 ( L_25 ,
V_133 -> V_145 . V_114 ) ;
} else {
F_3 ( L_26 ) ;
}
V_155:
F_71 ( V_2 , V_3 ) ;
return V_34 ;
}
static void F_95 ( struct V_1 * V_2 , int V_3 )
{
struct V_109 * V_110 , * V_125 ;
struct V_10 V_106 ;
unsigned int V_111 ;
F_64 ( & V_2 -> V_112 ) ;
V_111 = F_53 ( V_2 , V_3 , & V_106 ) ;
F_81 (e, t, &dev->vblank_event_list, base.link) {
if ( V_110 -> V_119 != V_3 )
continue;
if ( ( V_111 - V_110 -> V_113 . V_114 ) > ( 1 << 23 ) )
continue;
F_3 ( L_27 ,
V_110 -> V_113 . V_114 , V_111 ) ;
F_82 ( & V_110 -> V_81 . V_115 ) ;
F_71 ( V_2 , V_110 -> V_119 ) ;
F_55 ( V_2 , V_110 , V_111 , & V_106 ) ;
}
F_96 ( V_3 , V_111 ) ;
}
bool F_97 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 [ V_3 ] ;
T_1 V_18 ;
T_2 V_19 ;
struct V_10 V_21 ;
unsigned long V_17 ;
if ( F_98 ( ! V_2 -> V_30 ) )
return false ;
if ( F_17 ( V_3 >= V_2 -> V_30 ) )
return false ;
F_10 ( & V_2 -> V_112 , V_17 ) ;
F_65 ( & V_2 -> V_23 ) ;
if ( ! V_5 -> V_24 ) {
F_67 ( & V_2 -> V_23 ) ;
F_11 ( & V_2 -> V_112 , V_17 ) ;
return false ;
}
V_18 = F_4 ( & V_5 -> V_16 ) ;
F_2 ( V_2 , V_3 , & V_21 , V_161 ) ;
V_19 = F_12 ( & V_21 ) -
F_12 ( & F_5 ( V_2 , V_3 , V_18 ) ) ;
if ( F_13 ( V_19 ) > V_162 ) {
F_5 ( V_2 , V_3 , V_18 + 1 ) = V_21 ;
F_6 () ;
F_14 ( & V_5 -> V_16 ) ;
F_8 () ;
} else {
F_3 ( L_28 ,
V_3 , ( int ) V_19 ) ;
}
F_67 ( & V_2 -> V_23 ) ;
F_33 ( & V_5 -> V_38 ) ;
F_95 ( V_2 , V_3 ) ;
F_11 ( & V_2 -> V_112 , V_17 ) ;
return true ;
}
bool F_99 ( struct V_67 * V_3 )
{
return F_97 ( V_3 -> V_2 , F_52 ( V_3 ) ) ;
}
