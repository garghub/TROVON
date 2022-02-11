static void F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
T_1 V_9 ;
F_2 ( & V_2 -> V_10 ) ;
if ( V_6 ) {
V_9 = V_8 -> V_11 + V_4 ;
F_3 ( V_2 , V_3 , V_9 ) = * V_6 ;
}
F_4 () ;
V_8 -> V_11 += V_4 ;
F_4 () ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
T_1 V_13 , V_14 ;
bool V_15 ;
struct V_5 V_6 ;
do {
V_13 = V_2 -> V_16 -> V_17 ( V_2 , V_12 ) ;
V_15 = F_6 ( V_2 , V_12 , & V_6 , 0 ) ;
} while ( V_13 != V_2 -> V_16 -> V_17 ( V_2 , V_12 ) );
V_14 = V_13 - V_8 -> V_18 ;
if ( V_13 < V_8 -> V_18 ) {
V_14 += V_2 -> V_19 + 1 ;
F_7 ( L_1 ,
V_12 , V_8 -> V_18 , V_13 , V_14 ) ;
}
F_7 ( L_2 ,
V_12 , V_14 ) ;
if ( V_14 == 0 )
return;
if ( ! V_15 )
V_6 = (struct V_5 ) { 0 , 0 } ;
F_1 ( V_2 , V_12 , V_14 , & V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
unsigned long V_20 ;
T_1 V_21 ;
T_2 V_22 ;
bool V_23 ;
struct V_5 V_24 ;
int V_11 = V_25 ;
F_9 ( & V_2 -> V_10 , V_20 ) ;
if ( ! V_8 -> V_26 &&
F_6 ( V_2 , V_12 , & V_24 , 0 ) ) {
F_5 ( V_2 , V_12 ) ;
F_10 ( & V_2 -> V_10 , V_20 ) ;
return;
}
if ( V_8 -> V_26 ) {
V_2 -> V_16 -> V_27 ( V_2 , V_12 ) ;
V_8 -> V_26 = false ;
}
do {
V_8 -> V_18 = V_2 -> V_16 -> V_17 ( V_2 , V_12 ) ;
V_23 = F_6 ( V_2 , V_12 , & V_24 , 0 ) ;
} while ( V_8 -> V_18 != V_2 -> V_16 -> V_17 ( V_2 , V_12 ) && ( -- V_11 ) && V_23 );
if ( ! V_11 )
V_23 = 0 ;
V_21 = V_8 -> V_11 ;
V_22 = F_11 ( & V_24 ) -
F_11 ( & F_3 ( V_2 , V_12 , V_21 ) ) ;
if ( V_23 && ( F_12 ( V_22 ) > 1000000 ) )
F_1 ( V_2 , V_12 , 1 , & V_24 ) ;
F_10 ( & V_2 -> V_10 , V_20 ) ;
}
static void F_13 ( unsigned long V_28 )
{
struct V_7 * V_8 = ( void * ) V_28 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_12 = V_8 -> V_12 ;
unsigned long V_20 ;
if ( ! V_2 -> V_29 )
return;
F_9 ( & V_2 -> V_30 , V_20 ) ;
if ( F_14 ( & V_8 -> V_31 ) == 0 && V_8 -> V_26 ) {
F_7 ( L_3 , V_12 ) ;
F_8 ( V_2 , V_12 ) ;
}
F_10 ( & V_2 -> V_30 , V_20 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
if ( V_2 -> V_32 == 0 )
return;
for ( V_12 = 0 ; V_12 < V_2 -> V_32 ; V_12 ++ ) {
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
F_16 ( V_8 -> V_26 &&
F_17 ( V_2 , V_33 ) ) ;
F_18 ( & V_8 -> V_34 ) ;
}
F_19 ( V_2 -> V_8 ) ;
V_2 -> V_32 = 0 ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_32 )
{
int V_35 = - V_36 ;
unsigned int V_37 ;
F_21 ( & V_2 -> V_30 ) ;
F_21 ( & V_2 -> V_10 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_8 = F_22 ( V_32 , sizeof( * V_2 -> V_8 ) , V_38 ) ;
if ( ! V_2 -> V_8 )
goto V_39;
for ( V_37 = 0 ; V_37 < V_32 ; V_37 ++ ) {
struct V_7 * V_8 = & V_2 -> V_8 [ V_37 ] ;
V_8 -> V_2 = V_2 ;
V_8 -> V_12 = V_37 ;
F_23 ( & V_8 -> V_40 ) ;
F_24 ( & V_8 -> V_34 , F_13 ,
( unsigned long ) V_8 ) ;
}
F_25 ( L_4 ) ;
if ( V_2 -> V_16 -> V_41 )
F_25 ( L_5 ) ;
else
F_25 ( L_6 ) ;
if ( V_2 -> V_42 && ! V_2 -> V_16 -> V_41 ) {
V_2 -> V_42 = false ;
F_25 ( L_7
L_8 ) ;
}
V_2 -> V_29 = false ;
return 0 ;
V_39:
V_2 -> V_32 = 0 ;
return V_35 ;
}
static void F_26 ( void * V_43 , bool V_44 )
{
struct V_1 * V_2 = V_43 ;
if ( V_2 -> V_16 -> V_45 ) {
V_2 -> V_16 -> V_45 ( V_2 , V_44 ) ;
return;
}
if ( ! V_2 -> V_46 )
return;
if ( V_44 ) {
if ( V_2 -> V_16 -> V_47 )
V_2 -> V_16 -> V_47 ( V_2 ) ;
} else {
if ( V_2 -> V_16 -> V_48 )
V_2 -> V_16 -> V_48 ( V_2 ) ;
if ( V_2 -> V_16 -> V_49 )
V_2 -> V_16 -> V_49 ( V_2 ) ;
}
}
int F_27 ( struct V_1 * V_2 , int V_50 )
{
int V_35 ;
unsigned long V_51 = 0 ;
if ( ! F_17 ( V_2 , V_52 ) )
return - V_53 ;
if ( V_50 == 0 )
return - V_53 ;
if ( ! V_2 -> V_54 )
return - V_53 ;
if ( V_2 -> V_46 )
return - V_55 ;
V_2 -> V_46 = true ;
F_7 ( L_9 , V_50 ) ;
if ( V_2 -> V_16 -> V_48 )
V_2 -> V_16 -> V_48 ( V_2 ) ;
if ( F_17 ( V_2 , V_56 ) )
V_51 = V_57 ;
V_35 = F_28 ( V_50 , V_2 -> V_16 -> V_58 ,
V_51 , V_2 -> V_16 -> V_59 , V_2 ) ;
if ( V_35 < 0 ) {
V_2 -> V_46 = false ;
return V_35 ;
}
if ( ! F_17 ( V_2 , V_33 ) )
F_29 ( V_2 -> V_60 , ( void * ) V_2 , F_26 , NULL ) ;
if ( V_2 -> V_16 -> V_49 )
V_35 = V_2 -> V_16 -> V_49 ( V_2 ) ;
if ( V_35 < 0 ) {
V_2 -> V_46 = false ;
if ( ! F_17 ( V_2 , V_33 ) )
F_29 ( V_2 -> V_60 , NULL , NULL , NULL ) ;
F_30 ( V_50 , V_2 ) ;
} else {
V_2 -> V_50 = V_50 ;
}
return V_35 ;
}
int F_31 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
bool V_46 ;
int V_37 ;
if ( ! F_17 ( V_2 , V_52 ) )
return - V_53 ;
V_46 = V_2 -> V_46 ;
V_2 -> V_46 = false ;
if ( V_2 -> V_32 ) {
F_9 ( & V_2 -> V_30 , V_20 ) ;
for ( V_37 = 0 ; V_37 < V_2 -> V_32 ; V_37 ++ ) {
struct V_7 * V_8 = & V_2 -> V_8 [ V_37 ] ;
if ( ! V_8 -> V_26 )
continue;
F_16 ( F_17 ( V_2 , V_33 ) ) ;
F_8 ( V_2 , V_37 ) ;
F_32 ( & V_8 -> V_40 ) ;
}
F_10 ( & V_2 -> V_30 , V_20 ) ;
}
if ( ! V_46 )
return - V_53 ;
F_7 ( L_9 , V_2 -> V_50 ) ;
if ( ! F_17 ( V_2 , V_33 ) )
F_29 ( V_2 -> V_60 , NULL , NULL , NULL ) ;
if ( V_2 -> V_16 -> V_47 )
V_2 -> V_16 -> V_47 ( V_2 ) ;
F_30 ( V_2 -> V_50 , V_2 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , void * V_61 ,
struct V_62 * V_63 )
{
struct F_33 * V_64 = V_61 ;
int V_35 = 0 , V_50 ;
if ( ! F_17 ( V_2 , V_52 ) )
return 0 ;
if ( F_17 ( V_2 , V_33 ) )
return 0 ;
if ( F_16 ( ! V_2 -> V_60 ) )
return - V_53 ;
switch ( V_64 -> V_65 ) {
case V_66 :
V_50 = V_2 -> V_60 -> V_50 ;
if ( V_2 -> V_67 < F_34 ( 1 , 2 ) &&
V_64 -> V_50 != V_50 )
return - V_53 ;
F_35 ( & V_2 -> V_68 ) ;
V_35 = F_27 ( V_2 , V_50 ) ;
F_36 ( & V_2 -> V_68 ) ;
return V_35 ;
case V_69 :
F_35 ( & V_2 -> V_68 ) ;
V_35 = F_31 ( V_2 ) ;
F_36 ( & V_2 -> V_68 ) ;
return V_35 ;
default:
return - V_53 ;
}
}
void F_37 ( struct V_70 * V_3 ,
const struct V_71 * V_72 )
{
int V_73 = 0 , V_74 = 0 , V_75 = 0 ;
int V_76 = V_72 -> V_77 ;
if ( V_76 > 0 ) {
int V_78 = V_72 -> V_79 * V_72 -> V_80 ;
V_74 = 1000000 / V_76 ;
V_73 = F_38 ( ( V_81 ) V_72 -> V_79 * 1000000 , V_76 ) ;
V_75 = F_38 ( ( V_81 ) V_78 * 1000000 , V_76 ) ;
if ( V_72 -> V_82 & V_83 )
V_75 /= 2 ;
} else
F_39 ( L_10 ,
V_3 -> V_84 . V_85 ) ;
V_3 -> V_74 = V_74 ;
V_3 -> V_73 = V_73 ;
V_3 -> V_75 = V_75 ;
F_7 ( L_11 ,
V_3 -> V_84 . V_85 , V_72 -> V_79 ,
V_72 -> V_80 , V_72 -> V_86 ) ;
F_7 ( L_12 ,
V_3 -> V_84 . V_85 , V_76 , V_75 ,
V_73 , V_74 ) ;
}
int F_40 ( struct V_1 * V_2 ,
unsigned int V_12 ,
int * V_87 ,
struct V_5 * V_88 ,
unsigned V_82 ,
const struct V_70 * V_89 ,
const struct V_71 * V_72 )
{
struct V_5 V_90 ;
T_3 V_91 , V_92 ;
int V_93 ;
int V_94 , V_95 , V_37 ;
int V_75 , V_73 , V_74 , V_96 , V_97 ;
bool V_98 ;
if ( V_12 >= V_2 -> V_32 ) {
F_39 ( L_13 , V_12 ) ;
return - V_53 ;
}
if ( ! V_2 -> V_16 -> V_99 ) {
F_39 ( L_14 ) ;
return - V_100 ;
}
V_75 = V_89 -> V_75 ;
V_73 = V_89 -> V_73 ;
V_74 = V_89 -> V_74 ;
if ( V_75 == 0 ) {
F_7 ( L_15 , V_12 ) ;
return - V_101 ;
}
for ( V_37 = 0 ; V_37 < V_25 ; V_37 ++ ) {
V_93 = V_2 -> V_16 -> V_99 ( V_2 , V_12 , V_82 , & V_94 ,
& V_95 , & V_91 , & V_92 ) ;
if ( ! ( V_93 & V_102 ) ) {
F_7 ( L_16 ,
V_12 , V_93 ) ;
return - V_100 ;
}
V_97 = F_41 ( V_92 ) - F_41 ( V_91 ) ;
if ( V_97 <= * V_87 )
break;
}
if ( V_37 == V_25 ) {
F_7 ( L_17 ,
V_12 , V_97 / 1000 , * V_87 / 1000 , V_37 ) ;
}
* V_87 = V_97 ;
V_98 = V_93 & V_103 ;
V_96 = V_94 * V_73 + V_95 * V_74 ;
if ( ! V_104 )
V_92 = F_42 ( V_92 ) ;
V_90 = F_43 ( V_92 ) ;
if ( V_96 < 0 )
V_92 = F_44 ( V_92 , - V_96 ) ;
else
V_92 = F_45 ( V_92 , V_96 ) ;
* V_88 = F_43 ( V_92 ) ;
F_7 ( L_18 ,
V_12 , ( int ) V_93 , V_95 , V_94 ,
( long ) V_90 . V_105 , ( long ) V_90 . V_106 ,
( long ) V_88 -> V_105 , ( long ) V_88 -> V_106 ,
V_97 / 1000 , V_37 ) ;
V_93 = V_107 ;
if ( V_98 )
V_93 |= V_108 ;
return V_93 ;
}
static struct V_5 F_46 ( void )
{
T_3 V_109 ;
V_109 = V_104 ? F_47 () : F_48 () ;
return F_43 ( V_109 ) ;
}
static bool
F_6 ( struct V_1 * V_2 , unsigned int V_12 ,
struct V_5 * V_24 , unsigned V_82 )
{
int V_35 ;
int V_87 = ( int ) V_110 * 1000 ;
if ( V_2 -> V_16 -> V_41 && ( V_87 > 0 ) ) {
V_35 = V_2 -> V_16 -> V_41 ( V_2 , V_12 , & V_87 ,
V_24 , V_82 ) ;
if ( V_35 > 0 )
return true ;
}
* V_24 = F_46 () ;
return false ;
}
T_1 F_49 ( struct V_1 * V_2 , int V_12 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
if ( F_16 ( V_12 >= V_2 -> V_32 ) )
return 0 ;
return V_8 -> V_11 ;
}
T_1 F_50 ( struct V_70 * V_3 )
{
return F_49 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
T_1 F_52 ( struct V_1 * V_2 , unsigned int V_12 ,
struct V_5 * V_111 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
T_1 V_13 ;
if ( F_16 ( V_12 >= V_2 -> V_32 ) )
return 0 ;
do {
V_13 = V_8 -> V_11 ;
F_53 () ;
* V_111 = F_3 ( V_2 , V_12 , V_13 ) ;
F_53 () ;
} while ( V_13 != V_8 -> V_11 );
return V_13 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_112 * V_113 ,
unsigned long V_114 , struct V_5 * V_109 )
{
F_55 ( ! F_56 ( & V_2 -> V_115 ) ) ;
V_113 -> V_116 . V_117 = V_114 ;
V_113 -> V_116 . V_105 = V_109 -> V_105 ;
V_113 -> V_116 . V_106 = V_109 -> V_106 ;
F_57 ( & V_113 -> V_84 . V_118 ,
& V_113 -> V_84 . V_63 -> V_119 ) ;
F_58 ( & V_113 -> V_84 . V_63 -> V_120 ) ;
F_59 ( V_113 -> V_84 . V_121 , V_113 -> V_12 ,
V_113 -> V_116 . V_117 ) ;
}
void F_60 ( struct V_1 * V_2 , unsigned int V_12 ,
struct V_112 * V_113 )
{
struct V_5 V_109 ;
unsigned int V_114 ;
if ( V_2 -> V_32 > 0 ) {
V_114 = F_52 ( V_2 , V_12 , & V_109 ) ;
} else {
V_114 = 0 ;
V_109 = F_46 () ;
}
V_113 -> V_12 = V_12 ;
F_54 ( V_2 , V_113 , V_114 , & V_109 ) ;
}
void F_61 ( struct V_70 * V_3 ,
struct V_112 * V_113 )
{
F_60 ( V_3 -> V_2 , F_51 ( V_3 ) , V_113 ) ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
int V_35 = 0 ;
F_2 ( & V_2 -> V_30 ) ;
F_63 ( & V_2 -> V_10 ) ;
if ( ! V_8 -> V_26 ) {
V_35 = V_2 -> V_16 -> V_122 ( V_2 , V_12 ) ;
F_7 ( L_19 , V_12 , V_35 ) ;
if ( V_35 )
F_64 ( & V_8 -> V_31 ) ;
else {
V_8 -> V_26 = true ;
F_5 ( V_2 , V_12 ) ;
}
}
F_65 ( & V_2 -> V_10 ) ;
return V_35 ;
}
int F_66 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
unsigned long V_20 ;
int V_35 = 0 ;
if ( ! V_2 -> V_32 )
return - V_53 ;
if ( F_16 ( V_12 >= V_2 -> V_32 ) )
return - V_53 ;
F_9 ( & V_2 -> V_30 , V_20 ) ;
if ( F_67 ( 1 , & V_8 -> V_31 ) == 1 ) {
V_35 = F_62 ( V_2 , V_12 ) ;
} else {
if ( ! V_8 -> V_26 ) {
F_64 ( & V_8 -> V_31 ) ;
V_35 = - V_53 ;
}
}
F_10 ( & V_2 -> V_30 , V_20 ) ;
return V_35 ;
}
int F_68 ( struct V_70 * V_3 )
{
return F_66 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
void F_69 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
if ( F_16 ( V_12 >= V_2 -> V_32 ) )
return;
if ( F_16 ( F_14 ( & V_8 -> V_31 ) == 0 ) )
return;
if ( F_70 ( & V_8 -> V_31 ) ) {
if ( V_123 == 0 )
return;
else if ( V_2 -> V_42 || V_123 < 0 )
F_13 ( ( unsigned long ) V_8 ) ;
else
F_71 ( & V_8 -> V_34 ,
V_124 + ( ( V_123 * V_125 ) / 1000 ) ) ;
}
}
void F_72 ( struct V_70 * V_3 )
{
F_69 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
void F_73 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
int V_35 ;
T_1 V_18 ;
if ( F_16 ( V_12 >= V_2 -> V_32 ) )
return;
V_35 = F_66 ( V_2 , V_12 ) ;
if ( F_74 ( V_35 , L_20 , V_12 , V_35 ) )
return;
V_18 = F_49 ( V_2 , V_12 ) ;
V_35 = F_75 ( V_8 -> V_40 ,
V_18 != F_49 ( V_2 , V_12 ) ,
F_76 ( 100 ) ) ;
F_74 ( V_35 == 0 , L_21 , V_12 ) ;
F_69 ( V_2 , V_12 ) ;
}
void F_77 ( struct V_70 * V_3 )
{
F_73 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
void F_78 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
struct V_112 * V_113 , * V_126 ;
struct V_5 V_109 ;
unsigned long V_20 ;
unsigned int V_114 ;
if ( F_16 ( V_12 >= V_2 -> V_32 ) )
return;
F_9 ( & V_2 -> V_115 , V_20 ) ;
F_63 ( & V_2 -> V_30 ) ;
F_8 ( V_2 , V_12 ) ;
F_32 ( & V_8 -> V_40 ) ;
if ( ! V_8 -> V_127 ) {
F_79 ( & V_8 -> V_31 ) ;
V_8 -> V_127 = 1 ;
}
F_65 ( & V_2 -> V_30 ) ;
V_114 = F_52 ( V_2 , V_12 , & V_109 ) ;
F_80 (e, t, &dev->vblank_event_list, base.link) {
if ( V_113 -> V_12 != V_12 )
continue;
F_7 ( L_22 ,
V_113 -> V_116 . V_117 , V_114 ) ;
F_81 ( & V_113 -> V_84 . V_118 ) ;
F_69 ( V_2 , V_12 ) ;
F_54 ( V_2 , V_113 , V_114 , & V_109 ) ;
}
F_10 ( & V_2 -> V_115 , V_20 ) ;
}
void F_82 ( struct V_70 * V_3 )
{
F_78 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
void F_83 ( struct V_70 * V_70 )
{
struct V_1 * V_2 = V_70 -> V_2 ;
unsigned long V_20 ;
int V_3 = F_51 ( V_70 ) ;
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
F_9 ( & V_2 -> V_30 , V_20 ) ;
if ( ! V_8 -> V_127 ) {
F_79 ( & V_8 -> V_31 ) ;
V_8 -> V_127 = 1 ;
}
F_10 ( & V_2 -> V_30 , V_20 ) ;
F_16 ( ! F_84 ( & V_2 -> V_128 ) ) ;
}
void F_85 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
unsigned long V_20 ;
if ( F_16 ( V_12 >= V_2 -> V_32 ) )
return;
F_9 ( & V_2 -> V_30 , V_20 ) ;
if ( V_8 -> V_127 ) {
F_64 ( & V_8 -> V_31 ) ;
V_8 -> V_127 = 0 ;
}
V_8 -> V_18 =
( V_2 -> V_16 -> V_17 ( V_2 , V_12 ) - 1 ) &
V_2 -> V_19 ;
if ( F_14 ( & V_8 -> V_31 ) != 0 ||
( ! V_2 -> V_42 && V_123 == 0 ) )
F_16 ( F_62 ( V_2 , V_12 ) ) ;
F_10 ( & V_2 -> V_30 , V_20 ) ;
}
void F_86 ( struct V_70 * V_3 )
{
F_85 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
void F_87 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
if ( ! V_2 -> V_32 )
return;
if ( F_16 ( V_12 >= V_2 -> V_32 ) )
return;
if ( ! V_8 -> V_127 ) {
V_8 -> V_127 = 0x1 ;
if ( F_66 ( V_2 , V_12 ) == 0 )
V_8 -> V_127 |= 0x2 ;
}
}
void F_88 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
unsigned long V_20 ;
if ( ! V_2 -> V_32 )
return;
if ( F_16 ( V_12 >= V_2 -> V_32 ) )
return;
if ( V_8 -> V_127 ) {
F_9 ( & V_2 -> V_30 , V_20 ) ;
V_2 -> V_29 = true ;
F_10 ( & V_2 -> V_30 , V_20 ) ;
if ( V_8 -> V_127 & 0x2 )
F_69 ( V_2 , V_12 ) ;
V_8 -> V_127 = 0 ;
}
}
int F_89 ( struct V_1 * V_2 , void * V_61 ,
struct V_62 * V_63 )
{
struct F_89 * V_129 = V_61 ;
unsigned int V_12 ;
if ( ! V_2 -> V_32 )
return 0 ;
if ( F_17 ( V_2 , V_33 ) )
return 0 ;
V_12 = V_129 -> V_3 ;
if ( V_12 >= V_2 -> V_32 )
return - V_53 ;
switch ( V_129 -> V_130 ) {
case V_131 :
F_87 ( V_2 , V_12 ) ;
break;
case V_132 :
F_88 ( V_2 , V_12 ) ;
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , unsigned int V_12 ,
union V_133 * V_134 ,
struct V_62 * V_63 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
struct V_112 * V_113 ;
struct V_5 V_109 ;
unsigned long V_82 ;
unsigned int V_114 ;
int V_35 ;
V_113 = F_91 ( sizeof( * V_113 ) , V_38 ) ;
if ( V_113 == NULL ) {
V_35 = - V_36 ;
goto V_135;
}
V_113 -> V_12 = V_12 ;
V_113 -> V_84 . V_121 = V_136 -> V_121 ;
V_113 -> V_116 . V_84 . type = V_137 ;
V_113 -> V_116 . V_84 . V_138 = sizeof( V_113 -> V_116 ) ;
V_113 -> V_116 . V_139 = V_134 -> V_140 . signal ;
V_113 -> V_84 . V_116 = & V_113 -> V_116 . V_84 ;
V_113 -> V_84 . V_63 = V_63 ;
V_113 -> V_84 . V_141 = ( void ( * ) ( struct V_142 * ) ) F_19 ;
F_9 ( & V_2 -> V_115 , V_82 ) ;
if ( ! V_8 -> V_26 ) {
V_35 = - V_53 ;
goto V_143;
}
if ( V_63 -> V_144 < sizeof( V_113 -> V_116 ) ) {
V_35 = - V_55 ;
goto V_143;
}
V_63 -> V_144 -= sizeof( V_113 -> V_116 ) ;
V_114 = F_52 ( V_2 , V_12 , & V_109 ) ;
if ( ( V_134 -> V_140 . type & V_145 ) &&
( V_114 - V_134 -> V_140 . V_117 ) <= ( 1 << 23 ) ) {
V_134 -> V_140 . V_117 = V_114 + 1 ;
V_134 -> V_146 . V_117 = V_134 -> V_140 . V_117 ;
}
F_7 ( L_23 ,
V_134 -> V_140 . V_117 , V_114 , V_12 ) ;
F_92 ( V_136 -> V_121 , V_12 ,
V_134 -> V_140 . V_117 ) ;
V_113 -> V_116 . V_117 = V_134 -> V_140 . V_117 ;
if ( ( V_114 - V_134 -> V_140 . V_117 ) <= ( 1 << 23 ) ) {
F_69 ( V_2 , V_12 ) ;
F_54 ( V_2 , V_113 , V_114 , & V_109 ) ;
V_134 -> V_146 . V_117 = V_114 ;
} else {
F_57 ( & V_113 -> V_84 . V_118 , & V_2 -> V_128 ) ;
V_134 -> V_146 . V_117 = V_134 -> V_140 . V_117 ;
}
F_10 ( & V_2 -> V_115 , V_82 ) ;
return 0 ;
V_143:
F_10 ( & V_2 -> V_115 , V_82 ) ;
F_19 ( V_113 ) ;
V_135:
F_69 ( V_2 , V_12 ) ;
return V_35 ;
}
int V_133 ( struct V_1 * V_2 , void * V_61 ,
struct V_62 * V_63 )
{
struct V_7 * V_8 ;
union V_133 * V_134 = V_61 ;
int V_35 ;
unsigned int V_82 , V_114 , V_12 , V_147 ;
if ( ! V_2 -> V_46 )
return - V_53 ;
if ( V_134 -> V_140 . type & V_148 )
return - V_53 ;
if ( V_134 -> V_140 . type &
~ ( V_149 | V_150 |
V_151 ) ) {
F_39 ( L_24 ,
V_134 -> V_140 . type ,
( V_149 | V_150 |
V_151 ) ) ;
return - V_53 ;
}
V_82 = V_134 -> V_140 . type & V_150 ;
V_147 = ( V_134 -> V_140 . type & V_151 ) ;
if ( V_147 )
V_12 = V_147 >> V_152 ;
else
V_12 = V_82 & V_153 ? 1 : 0 ;
if ( V_12 >= V_2 -> V_32 )
return - V_53 ;
V_8 = & V_2 -> V_8 [ V_12 ] ;
V_35 = F_66 ( V_2 , V_12 ) ;
if ( V_35 ) {
F_7 ( L_25 , V_35 ) ;
return V_35 ;
}
V_114 = F_49 ( V_2 , V_12 ) ;
switch ( V_134 -> V_140 . type & V_149 ) {
case V_154 :
V_134 -> V_140 . V_117 += V_114 ;
V_134 -> V_140 . type &= ~ V_154 ;
case V_155 :
break;
default:
V_35 = - V_53 ;
goto V_156;
}
if ( V_82 & V_157 ) {
return F_90 ( V_2 , V_12 , V_134 , V_63 ) ;
}
if ( ( V_82 & V_145 ) &&
( V_114 - V_134 -> V_140 . V_117 ) <= ( 1 << 23 ) ) {
V_134 -> V_140 . V_117 = V_114 + 1 ;
}
F_7 ( L_26 ,
V_134 -> V_140 . V_117 , V_12 ) ;
V_8 -> V_158 = V_134 -> V_140 . V_117 ;
F_93 ( V_35 , V_8 -> V_40 , 3 * V_125 ,
( ( ( F_49 ( V_2 , V_12 ) -
V_134 -> V_140 . V_117 ) <= ( 1 << 23 ) ) ||
! V_8 -> V_26 ||
! V_2 -> V_46 ) ) ;
if ( V_35 != - V_159 ) {
struct V_5 V_109 ;
V_134 -> V_146 . V_117 = F_52 ( V_2 , V_12 , & V_109 ) ;
V_134 -> V_146 . V_160 = V_109 . V_105 ;
V_134 -> V_146 . V_161 = V_109 . V_106 ;
F_7 ( L_27 ,
V_134 -> V_146 . V_117 ) ;
} else {
F_7 ( L_28 ) ;
}
V_156:
F_69 ( V_2 , V_12 ) ;
return V_35 ;
}
static void F_94 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_112 * V_113 , * V_126 ;
struct V_5 V_109 ;
unsigned int V_114 ;
F_2 ( & V_2 -> V_115 ) ;
V_114 = F_52 ( V_2 , V_12 , & V_109 ) ;
F_80 (e, t, &dev->vblank_event_list, base.link) {
if ( V_113 -> V_12 != V_12 )
continue;
if ( ( V_114 - V_113 -> V_116 . V_117 ) > ( 1 << 23 ) )
continue;
F_7 ( L_29 ,
V_113 -> V_116 . V_117 , V_114 ) ;
F_81 ( & V_113 -> V_84 . V_118 ) ;
F_69 ( V_2 , V_12 ) ;
F_54 ( V_2 , V_113 , V_114 , & V_109 ) ;
}
F_95 ( V_12 , V_114 ) ;
}
bool F_96 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_12 ] ;
T_1 V_21 ;
T_2 V_22 ;
struct V_5 V_24 ;
unsigned long V_20 ;
if ( F_97 ( ! V_2 -> V_32 ) )
return false ;
if ( F_16 ( V_12 >= V_2 -> V_32 ) )
return false ;
F_9 ( & V_2 -> V_115 , V_20 ) ;
F_63 ( & V_2 -> V_10 ) ;
if ( ! V_8 -> V_26 ) {
F_65 ( & V_2 -> V_10 ) ;
F_10 ( & V_2 -> V_115 , V_20 ) ;
return false ;
}
V_21 = V_8 -> V_11 ;
F_6 ( V_2 , V_12 , & V_24 , V_162 ) ;
V_22 = F_11 ( & V_24 ) -
F_11 ( & F_3 ( V_2 , V_12 , V_21 ) ) ;
if ( F_12 ( V_22 ) > V_163 )
F_1 ( V_2 , V_12 , 1 , & V_24 ) ;
else
F_7 ( L_30 ,
V_12 , ( int ) V_22 ) ;
F_65 ( & V_2 -> V_10 ) ;
F_32 ( & V_8 -> V_40 ) ;
F_94 ( V_2 , V_12 ) ;
F_10 ( & V_2 -> V_115 , V_20 ) ;
return true ;
}
bool F_98 ( struct V_70 * V_3 )
{
return F_96 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
