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
static void F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
T_1 V_12 , V_13 ;
bool V_14 ;
struct V_5 V_6 ;
do {
V_12 = V_2 -> V_15 -> V_16 ( V_2 , V_3 ) ;
V_14 = F_6 ( V_2 , V_3 , & V_6 , 0 ) ;
} while ( V_12 != V_2 -> V_15 -> V_16 ( V_2 , V_3 ) );
V_13 = V_12 - V_8 -> V_17 ;
if ( V_12 < V_8 -> V_17 ) {
V_13 += V_2 -> V_18 + 1 ;
F_7 ( L_1 ,
V_3 , V_8 -> V_17 , V_12 , V_13 ) ;
}
F_7 ( L_2 ,
V_3 , V_13 ) ;
if ( V_13 == 0 )
return;
if ( ! V_14 )
V_6 = (struct V_5 ) { 0 , 0 } ;
F_1 ( V_2 , V_3 , V_13 , & V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
unsigned long V_19 ;
T_1 V_20 ;
T_2 V_21 ;
bool V_22 ;
struct V_5 V_23 ;
int V_11 = V_24 ;
F_9 ( & V_2 -> V_10 , V_19 ) ;
if ( ! V_8 -> V_25 &&
F_6 ( V_2 , V_3 , & V_23 , 0 ) ) {
F_5 ( V_2 , V_3 ) ;
F_10 ( & V_2 -> V_10 , V_19 ) ;
return;
}
if ( V_8 -> V_25 ) {
V_2 -> V_15 -> V_26 ( V_2 , V_3 ) ;
V_8 -> V_25 = false ;
}
do {
V_8 -> V_17 = V_2 -> V_15 -> V_16 ( V_2 , V_3 ) ;
V_22 = F_6 ( V_2 , V_3 , & V_23 , 0 ) ;
} while ( V_8 -> V_17 != V_2 -> V_15 -> V_16 ( V_2 , V_3 ) && ( -- V_11 ) && V_22 );
if ( ! V_11 )
V_22 = 0 ;
V_20 = V_8 -> V_11 ;
V_21 = F_11 ( & V_23 ) -
F_11 ( & F_3 ( V_2 , V_3 , V_20 ) ) ;
if ( V_22 && ( F_12 ( V_21 ) > 1000000 ) )
F_1 ( V_2 , V_3 , 1 , & V_23 ) ;
F_10 ( & V_2 -> V_10 , V_19 ) ;
}
static void F_13 ( unsigned long V_27 )
{
struct V_7 * V_8 = ( void * ) V_27 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned long V_19 ;
int V_3 = V_8 -> V_3 ;
if ( ! V_2 -> V_28 )
return;
F_9 ( & V_2 -> V_29 , V_19 ) ;
if ( F_14 ( & V_8 -> V_30 ) == 0 && V_8 -> V_25 ) {
F_7 ( L_3 , V_3 ) ;
F_8 ( V_2 , V_3 ) ;
}
F_10 ( & V_2 -> V_29 , V_19 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_31 == 0 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_31 ; V_3 ++ ) {
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
F_16 ( V_8 -> V_25 &&
F_17 ( V_2 , V_32 ) ) ;
F_18 ( & V_8 -> V_33 ) ;
}
F_19 ( V_2 -> V_8 ) ;
V_2 -> V_31 = 0 ;
}
int F_20 ( struct V_1 * V_2 , int V_31 )
{
int V_34 , V_35 = - V_36 ;
F_21 ( & V_2 -> V_29 ) ;
F_21 ( & V_2 -> V_10 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_8 = F_22 ( V_31 , sizeof( * V_2 -> V_8 ) , V_37 ) ;
if ( ! V_2 -> V_8 )
goto V_38;
for ( V_34 = 0 ; V_34 < V_31 ; V_34 ++ ) {
struct V_7 * V_8 = & V_2 -> V_8 [ V_34 ] ;
V_8 -> V_2 = V_2 ;
V_8 -> V_3 = V_34 ;
F_23 ( & V_8 -> V_39 ) ;
F_24 ( & V_8 -> V_33 , F_13 ,
( unsigned long ) V_8 ) ;
}
F_25 ( L_4 ) ;
if ( V_2 -> V_15 -> V_40 )
F_25 ( L_5 ) ;
else
F_25 ( L_6 ) ;
if ( V_2 -> V_41 && ! V_2 -> V_15 -> V_40 ) {
V_2 -> V_41 = false ;
F_25 ( L_7
L_8 ) ;
}
V_2 -> V_28 = false ;
return 0 ;
V_38:
V_2 -> V_31 = 0 ;
return V_35 ;
}
static void F_26 ( void * V_42 , bool V_43 )
{
struct V_1 * V_2 = V_42 ;
if ( V_2 -> V_15 -> V_44 ) {
V_2 -> V_15 -> V_44 ( V_2 , V_43 ) ;
return;
}
if ( ! V_2 -> V_45 )
return;
if ( V_43 ) {
if ( V_2 -> V_15 -> V_46 )
V_2 -> V_15 -> V_46 ( V_2 ) ;
} else {
if ( V_2 -> V_15 -> V_47 )
V_2 -> V_15 -> V_47 ( V_2 ) ;
if ( V_2 -> V_15 -> V_48 )
V_2 -> V_15 -> V_48 ( V_2 ) ;
}
}
int F_27 ( struct V_1 * V_2 , int V_49 )
{
int V_35 ;
unsigned long V_50 = 0 ;
if ( ! F_17 ( V_2 , V_51 ) )
return - V_52 ;
if ( V_49 == 0 )
return - V_52 ;
if ( ! V_2 -> V_53 )
return - V_52 ;
if ( V_2 -> V_45 )
return - V_54 ;
V_2 -> V_45 = true ;
F_7 ( L_9 , V_49 ) ;
if ( V_2 -> V_15 -> V_47 )
V_2 -> V_15 -> V_47 ( V_2 ) ;
if ( F_17 ( V_2 , V_55 ) )
V_50 = V_56 ;
V_35 = F_28 ( V_49 , V_2 -> V_15 -> V_57 ,
V_50 , V_2 -> V_15 -> V_58 , V_2 ) ;
if ( V_35 < 0 ) {
V_2 -> V_45 = false ;
return V_35 ;
}
if ( ! F_17 ( V_2 , V_32 ) )
F_29 ( V_2 -> V_59 , ( void * ) V_2 , F_26 , NULL ) ;
if ( V_2 -> V_15 -> V_48 )
V_35 = V_2 -> V_15 -> V_48 ( V_2 ) ;
if ( V_35 < 0 ) {
V_2 -> V_45 = false ;
if ( ! F_17 ( V_2 , V_32 ) )
F_29 ( V_2 -> V_59 , NULL , NULL , NULL ) ;
F_30 ( V_49 , V_2 ) ;
} else {
V_2 -> V_49 = V_49 ;
}
return V_35 ;
}
int F_31 ( struct V_1 * V_2 )
{
unsigned long V_19 ;
bool V_45 ;
int V_34 ;
if ( ! F_17 ( V_2 , V_51 ) )
return - V_52 ;
V_45 = V_2 -> V_45 ;
V_2 -> V_45 = false ;
if ( V_2 -> V_31 ) {
F_9 ( & V_2 -> V_29 , V_19 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_31 ; V_34 ++ ) {
struct V_7 * V_8 = & V_2 -> V_8 [ V_34 ] ;
if ( ! V_8 -> V_25 )
continue;
F_16 ( F_17 ( V_2 , V_32 ) ) ;
F_8 ( V_2 , V_34 ) ;
F_32 ( & V_8 -> V_39 ) ;
}
F_10 ( & V_2 -> V_29 , V_19 ) ;
}
if ( ! V_45 )
return - V_52 ;
F_7 ( L_9 , V_2 -> V_49 ) ;
if ( ! F_17 ( V_2 , V_32 ) )
F_29 ( V_2 -> V_59 , NULL , NULL , NULL ) ;
if ( V_2 -> V_15 -> V_46 )
V_2 -> V_15 -> V_46 ( V_2 ) ;
F_30 ( V_2 -> V_49 , V_2 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , void * V_60 ,
struct V_61 * V_62 )
{
struct F_33 * V_63 = V_60 ;
int V_35 = 0 , V_49 ;
if ( ! F_17 ( V_2 , V_51 ) )
return 0 ;
if ( F_17 ( V_2 , V_32 ) )
return 0 ;
if ( F_16 ( ! V_2 -> V_59 ) )
return - V_52 ;
switch ( V_63 -> V_64 ) {
case V_65 :
V_49 = V_2 -> V_59 -> V_49 ;
if ( V_2 -> V_66 < F_34 ( 1 , 2 ) &&
V_63 -> V_49 != V_49 )
return - V_52 ;
F_35 ( & V_2 -> V_67 ) ;
V_35 = F_27 ( V_2 , V_49 ) ;
F_36 ( & V_2 -> V_67 ) ;
return V_35 ;
case V_68 :
F_35 ( & V_2 -> V_67 ) ;
V_35 = F_31 ( V_2 ) ;
F_36 ( & V_2 -> V_67 ) ;
return V_35 ;
default:
return - V_52 ;
}
}
void F_37 ( struct V_69 * V_3 ,
const struct V_70 * V_71 )
{
int V_72 = 0 , V_73 = 0 , V_74 = 0 ;
int V_75 = V_71 -> V_76 ;
if ( V_75 > 0 ) {
int V_77 = V_71 -> V_78 * V_71 -> V_79 ;
V_73 = 1000000 / V_75 ;
V_72 = F_38 ( ( V_80 ) V_71 -> V_78 * 1000000 , V_75 ) ;
V_74 = F_38 ( ( V_80 ) V_77 * 1000000 , V_75 ) ;
if ( V_71 -> V_81 & V_82 )
V_74 /= 2 ;
} else
F_39 ( L_10 ,
V_3 -> V_83 . V_84 ) ;
V_3 -> V_73 = V_73 ;
V_3 -> V_72 = V_72 ;
V_3 -> V_74 = V_74 ;
F_7 ( L_11 ,
V_3 -> V_83 . V_84 , V_71 -> V_78 ,
V_71 -> V_79 , V_71 -> V_85 ) ;
F_7 ( L_12 ,
V_3 -> V_83 . V_84 , V_75 , V_74 ,
V_72 , V_73 ) ;
}
int F_40 ( struct V_1 * V_2 , int V_3 ,
int * V_86 ,
struct V_5 * V_87 ,
unsigned V_81 ,
const struct V_69 * V_88 ,
const struct V_70 * V_71 )
{
struct V_5 V_89 ;
T_3 V_90 , V_91 ;
int V_92 ;
int V_93 , V_94 , V_34 ;
int V_74 , V_72 , V_73 , V_95 , V_96 ;
bool V_97 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_31 ) {
F_39 ( L_13 , V_3 ) ;
return - V_52 ;
}
if ( ! V_2 -> V_15 -> V_98 ) {
F_39 ( L_14 ) ;
return - V_99 ;
}
V_74 = V_88 -> V_74 ;
V_72 = V_88 -> V_72 ;
V_73 = V_88 -> V_73 ;
if ( V_74 == 0 ) {
F_7 ( L_15 , V_3 ) ;
return - V_100 ;
}
for ( V_34 = 0 ; V_34 < V_24 ; V_34 ++ ) {
V_92 = V_2 -> V_15 -> V_98 ( V_2 , V_3 , V_81 , & V_93 ,
& V_94 , & V_90 , & V_91 ) ;
if ( ! ( V_92 & V_101 ) ) {
F_7 ( L_16 ,
V_3 , V_92 ) ;
return - V_99 ;
}
V_96 = F_41 ( V_91 ) - F_41 ( V_90 ) ;
if ( V_96 <= * V_86 )
break;
}
if ( V_34 == V_24 ) {
F_7 ( L_17 ,
V_3 , V_96 / 1000 , * V_86 / 1000 , V_34 ) ;
}
* V_86 = V_96 ;
V_97 = V_92 & V_102 ;
V_95 = V_93 * V_72 + V_94 * V_73 ;
if ( ! V_103 )
V_91 = F_42 ( V_91 ) ;
V_89 = F_43 ( V_91 ) ;
if ( V_95 < 0 )
V_91 = F_44 ( V_91 , - V_95 ) ;
else
V_91 = F_45 ( V_91 , V_95 ) ;
* V_87 = F_43 ( V_91 ) ;
F_7 ( L_18 ,
V_3 , ( int ) V_92 , V_94 , V_93 ,
( long ) V_89 . V_104 , ( long ) V_89 . V_105 ,
( long ) V_87 -> V_104 , ( long ) V_87 -> V_105 ,
V_96 / 1000 , V_34 ) ;
V_92 = V_106 ;
if ( V_97 )
V_92 |= V_107 ;
return V_92 ;
}
static struct V_5 F_46 ( void )
{
T_3 V_108 ;
V_108 = V_103 ? F_47 () : F_48 () ;
return F_43 ( V_108 ) ;
}
static bool
F_6 ( struct V_1 * V_2 , int V_3 ,
struct V_5 * V_23 , unsigned V_81 )
{
int V_35 ;
int V_86 = ( int ) V_109 * 1000 ;
if ( V_2 -> V_15 -> V_40 && ( V_86 > 0 ) ) {
V_35 = V_2 -> V_15 -> V_40 ( V_2 , V_3 , & V_86 ,
V_23 , V_81 ) ;
if ( V_35 > 0 )
return true ;
}
* V_23 = F_46 () ;
return false ;
}
T_1 F_49 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
if ( F_16 ( V_3 >= V_2 -> V_31 ) )
return 0 ;
return V_8 -> V_11 ;
}
T_1 F_50 ( struct V_69 * V_3 )
{
return F_49 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
T_1 F_52 ( struct V_1 * V_2 , int V_3 ,
struct V_5 * V_110 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
T_1 V_12 ;
if ( F_16 ( V_3 >= V_2 -> V_31 ) )
return 0 ;
do {
V_12 = V_8 -> V_11 ;
F_53 () ;
* V_110 = F_3 ( V_2 , V_3 , V_12 ) ;
F_53 () ;
} while ( V_12 != V_8 -> V_11 );
return V_12 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_111 * V_112 ,
unsigned long V_113 , struct V_5 * V_108 )
{
F_55 ( ! F_56 ( & V_2 -> V_114 ) ) ;
V_112 -> V_115 . V_116 = V_113 ;
V_112 -> V_115 . V_104 = V_108 -> V_104 ;
V_112 -> V_115 . V_105 = V_108 -> V_105 ;
F_57 ( & V_112 -> V_83 . V_117 ,
& V_112 -> V_83 . V_62 -> V_118 ) ;
F_58 ( & V_112 -> V_83 . V_62 -> V_119 ) ;
F_59 ( V_112 -> V_83 . V_120 , V_112 -> V_121 ,
V_112 -> V_115 . V_116 ) ;
}
void F_60 ( struct V_1 * V_2 , int V_3 ,
struct V_111 * V_112 )
{
struct V_5 V_108 ;
unsigned int V_113 ;
if ( V_3 >= 0 ) {
V_113 = F_52 ( V_2 , V_3 , & V_108 ) ;
} else {
V_113 = 0 ;
V_108 = F_46 () ;
}
V_112 -> V_121 = V_3 ;
F_54 ( V_2 , V_112 , V_113 , & V_108 ) ;
}
void F_61 ( struct V_69 * V_3 ,
struct V_111 * V_112 )
{
F_60 ( V_3 -> V_2 , F_51 ( V_3 ) , V_112 ) ;
}
static int F_62 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
int V_35 = 0 ;
F_2 ( & V_2 -> V_29 ) ;
F_63 ( & V_2 -> V_10 ) ;
if ( ! V_8 -> V_25 ) {
V_35 = V_2 -> V_15 -> V_122 ( V_2 , V_3 ) ;
F_7 ( L_19 , V_3 , V_35 ) ;
if ( V_35 )
F_64 ( & V_8 -> V_30 ) ;
else {
V_8 -> V_25 = true ;
F_5 ( V_2 , V_3 ) ;
}
}
F_65 ( & V_2 -> V_10 ) ;
return V_35 ;
}
int F_66 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
unsigned long V_19 ;
int V_35 = 0 ;
if ( ! V_2 -> V_31 )
return - V_52 ;
if ( F_16 ( V_3 >= V_2 -> V_31 ) )
return - V_52 ;
F_9 ( & V_2 -> V_29 , V_19 ) ;
if ( F_67 ( 1 , & V_8 -> V_30 ) == 1 ) {
V_35 = F_62 ( V_2 , V_3 ) ;
} else {
if ( ! V_8 -> V_25 ) {
F_64 ( & V_8 -> V_30 ) ;
V_35 = - V_52 ;
}
}
F_10 ( & V_2 -> V_29 , V_19 ) ;
return V_35 ;
}
int F_68 ( struct V_69 * V_3 )
{
return F_66 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
void F_69 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
if ( F_16 ( F_14 ( & V_8 -> V_30 ) == 0 ) )
return;
if ( F_16 ( V_3 >= V_2 -> V_31 ) )
return;
if ( F_70 ( & V_8 -> V_30 ) ) {
if ( V_123 == 0 )
return;
else if ( V_2 -> V_41 || V_123 < 0 )
F_13 ( ( unsigned long ) V_8 ) ;
else
F_71 ( & V_8 -> V_33 ,
V_124 + ( ( V_123 * V_125 ) / 1000 ) ) ;
}
}
void F_72 ( struct V_69 * V_3 )
{
F_69 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
void F_73 ( struct V_1 * V_2 , int V_3 )
{
int V_35 ;
T_1 V_17 ;
V_35 = F_66 ( V_2 , V_3 ) ;
if ( F_74 ( V_35 , L_20 , V_3 , V_35 ) )
return;
V_17 = F_49 ( V_2 , V_3 ) ;
V_35 = F_75 ( V_2 -> V_8 [ V_3 ] . V_39 ,
V_17 != F_49 ( V_2 , V_3 ) ,
F_76 ( 100 ) ) ;
F_74 ( V_35 == 0 , L_21 , V_3 ) ;
F_69 ( V_2 , V_3 ) ;
}
void F_77 ( struct V_69 * V_3 )
{
F_73 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
void F_78 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
struct V_111 * V_112 , * V_126 ;
struct V_5 V_108 ;
unsigned long V_19 ;
unsigned int V_113 ;
if ( F_16 ( V_3 >= V_2 -> V_31 ) )
return;
F_9 ( & V_2 -> V_114 , V_19 ) ;
F_63 ( & V_2 -> V_29 ) ;
F_8 ( V_2 , V_3 ) ;
F_32 ( & V_8 -> V_39 ) ;
if ( ! V_8 -> V_127 ) {
F_79 ( & V_8 -> V_30 ) ;
V_8 -> V_127 = 1 ;
}
F_65 ( & V_2 -> V_29 ) ;
V_113 = F_52 ( V_2 , V_3 , & V_108 ) ;
F_80 (e, t, &dev->vblank_event_list, base.link) {
if ( V_112 -> V_121 != V_3 )
continue;
F_7 ( L_22 ,
V_112 -> V_115 . V_116 , V_113 ) ;
F_81 ( & V_112 -> V_83 . V_117 ) ;
F_69 ( V_2 , V_112 -> V_121 ) ;
F_54 ( V_2 , V_112 , V_113 , & V_108 ) ;
}
F_10 ( & V_2 -> V_114 , V_19 ) ;
}
void F_82 ( struct V_69 * V_3 )
{
F_78 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
void F_83 ( struct V_69 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_2 ;
unsigned long V_19 ;
int V_3 = F_51 ( V_69 ) ;
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
F_9 ( & V_2 -> V_29 , V_19 ) ;
if ( ! V_8 -> V_127 ) {
F_79 ( & V_8 -> V_30 ) ;
V_8 -> V_127 = 1 ;
}
F_10 ( & V_2 -> V_29 , V_19 ) ;
F_16 ( ! F_84 ( & V_2 -> V_128 ) ) ;
}
void F_85 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
unsigned long V_19 ;
if ( F_16 ( V_3 >= V_2 -> V_31 ) )
return;
F_9 ( & V_2 -> V_29 , V_19 ) ;
if ( V_8 -> V_127 ) {
F_64 ( & V_8 -> V_30 ) ;
V_8 -> V_127 = 0 ;
}
V_8 -> V_17 =
( V_2 -> V_15 -> V_16 ( V_2 , V_3 ) - 1 ) &
V_2 -> V_18 ;
if ( F_14 ( & V_8 -> V_30 ) != 0 ||
( ! V_2 -> V_41 && V_123 == 0 ) )
F_16 ( F_62 ( V_2 , V_3 ) ) ;
F_10 ( & V_2 -> V_29 , V_19 ) ;
}
void F_86 ( struct V_69 * V_3 )
{
F_85 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
void F_87 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
if ( ! V_2 -> V_31 )
return;
if ( F_16 ( V_3 >= V_2 -> V_31 ) )
return;
if ( ! V_8 -> V_127 ) {
V_8 -> V_127 = 0x1 ;
if ( F_66 ( V_2 , V_3 ) == 0 )
V_8 -> V_127 |= 0x2 ;
}
}
void F_88 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
unsigned long V_19 ;
if ( ! V_2 -> V_31 )
return;
if ( V_8 -> V_127 ) {
F_9 ( & V_2 -> V_29 , V_19 ) ;
V_2 -> V_28 = true ;
F_10 ( & V_2 -> V_29 , V_19 ) ;
if ( V_8 -> V_127 & 0x2 )
F_69 ( V_2 , V_3 ) ;
V_8 -> V_127 = 0 ;
}
}
int F_89 ( struct V_1 * V_2 , void * V_60 ,
struct V_61 * V_62 )
{
struct F_89 * V_129 = V_60 ;
unsigned int V_3 ;
if ( ! V_2 -> V_31 )
return 0 ;
if ( F_17 ( V_2 , V_32 ) )
return 0 ;
V_3 = V_129 -> V_3 ;
if ( V_3 >= V_2 -> V_31 )
return - V_52 ;
switch ( V_129 -> V_130 ) {
case V_131 :
F_87 ( V_2 , V_3 ) ;
break;
case V_132 :
F_88 ( V_2 , V_3 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , int V_121 ,
union V_133 * V_134 ,
struct V_61 * V_62 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_121 ] ;
struct V_111 * V_112 ;
struct V_5 V_108 ;
unsigned long V_81 ;
unsigned int V_113 ;
int V_35 ;
V_112 = F_91 ( sizeof( * V_112 ) , V_37 ) ;
if ( V_112 == NULL ) {
V_35 = - V_36 ;
goto V_135;
}
V_112 -> V_121 = V_121 ;
V_112 -> V_83 . V_120 = V_136 -> V_120 ;
V_112 -> V_115 . V_83 . type = V_137 ;
V_112 -> V_115 . V_83 . V_138 = sizeof( V_112 -> V_115 ) ;
V_112 -> V_115 . V_139 = V_134 -> V_140 . signal ;
V_112 -> V_83 . V_115 = & V_112 -> V_115 . V_83 ;
V_112 -> V_83 . V_62 = V_62 ;
V_112 -> V_83 . V_141 = ( void ( * ) ( struct V_142 * ) ) F_19 ;
F_9 ( & V_2 -> V_114 , V_81 ) ;
if ( ! V_8 -> V_25 ) {
V_35 = - V_52 ;
goto V_143;
}
if ( V_62 -> V_144 < sizeof( V_112 -> V_115 ) ) {
V_35 = - V_54 ;
goto V_143;
}
V_62 -> V_144 -= sizeof( V_112 -> V_115 ) ;
V_113 = F_52 ( V_2 , V_121 , & V_108 ) ;
if ( ( V_134 -> V_140 . type & V_145 ) &&
( V_113 - V_134 -> V_140 . V_116 ) <= ( 1 << 23 ) ) {
V_134 -> V_140 . V_116 = V_113 + 1 ;
V_134 -> V_146 . V_116 = V_134 -> V_140 . V_116 ;
}
F_7 ( L_23 ,
V_134 -> V_140 . V_116 , V_113 , V_121 ) ;
F_92 ( V_136 -> V_120 , V_121 ,
V_134 -> V_140 . V_116 ) ;
V_112 -> V_115 . V_116 = V_134 -> V_140 . V_116 ;
if ( ( V_113 - V_134 -> V_140 . V_116 ) <= ( 1 << 23 ) ) {
F_69 ( V_2 , V_121 ) ;
F_54 ( V_2 , V_112 , V_113 , & V_108 ) ;
V_134 -> V_146 . V_116 = V_113 ;
} else {
F_57 ( & V_112 -> V_83 . V_117 , & V_2 -> V_128 ) ;
V_134 -> V_146 . V_116 = V_134 -> V_140 . V_116 ;
}
F_10 ( & V_2 -> V_114 , V_81 ) ;
return 0 ;
V_143:
F_10 ( & V_2 -> V_114 , V_81 ) ;
F_19 ( V_112 ) ;
V_135:
F_69 ( V_2 , V_121 ) ;
return V_35 ;
}
int V_133 ( struct V_1 * V_2 , void * V_60 ,
struct V_61 * V_62 )
{
struct V_7 * V_8 ;
union V_133 * V_134 = V_60 ;
int V_35 ;
unsigned int V_81 , V_113 , V_3 , V_147 ;
if ( ! V_2 -> V_45 )
return - V_52 ;
if ( V_134 -> V_140 . type & V_148 )
return - V_52 ;
if ( V_134 -> V_140 . type &
~ ( V_149 | V_150 |
V_151 ) ) {
F_39 ( L_24 ,
V_134 -> V_140 . type ,
( V_149 | V_150 |
V_151 ) ) ;
return - V_52 ;
}
V_81 = V_134 -> V_140 . type & V_150 ;
V_147 = ( V_134 -> V_140 . type & V_151 ) ;
if ( V_147 )
V_3 = V_147 >> V_152 ;
else
V_3 = V_81 & V_153 ? 1 : 0 ;
if ( V_3 >= V_2 -> V_31 )
return - V_52 ;
V_8 = & V_2 -> V_8 [ V_3 ] ;
V_35 = F_66 ( V_2 , V_3 ) ;
if ( V_35 ) {
F_7 ( L_25 , V_35 ) ;
return V_35 ;
}
V_113 = F_49 ( V_2 , V_3 ) ;
switch ( V_134 -> V_140 . type & V_149 ) {
case V_154 :
V_134 -> V_140 . V_116 += V_113 ;
V_134 -> V_140 . type &= ~ V_154 ;
case V_155 :
break;
default:
V_35 = - V_52 ;
goto V_156;
}
if ( V_81 & V_157 ) {
return F_90 ( V_2 , V_3 , V_134 , V_62 ) ;
}
if ( ( V_81 & V_145 ) &&
( V_113 - V_134 -> V_140 . V_116 ) <= ( 1 << 23 ) ) {
V_134 -> V_140 . V_116 = V_113 + 1 ;
}
F_7 ( L_26 ,
V_134 -> V_140 . V_116 , V_3 ) ;
V_8 -> V_158 = V_134 -> V_140 . V_116 ;
F_93 ( V_35 , V_8 -> V_39 , 3 * V_125 ,
( ( ( F_49 ( V_2 , V_3 ) -
V_134 -> V_140 . V_116 ) <= ( 1 << 23 ) ) ||
! V_8 -> V_25 ||
! V_2 -> V_45 ) ) ;
if ( V_35 != - V_159 ) {
struct V_5 V_108 ;
V_134 -> V_146 . V_116 = F_52 ( V_2 , V_3 , & V_108 ) ;
V_134 -> V_146 . V_160 = V_108 . V_104 ;
V_134 -> V_146 . V_161 = V_108 . V_105 ;
F_7 ( L_27 ,
V_134 -> V_146 . V_116 ) ;
} else {
F_7 ( L_28 ) ;
}
V_156:
F_69 ( V_2 , V_3 ) ;
return V_35 ;
}
static void F_94 ( struct V_1 * V_2 , int V_3 )
{
struct V_111 * V_112 , * V_126 ;
struct V_5 V_108 ;
unsigned int V_113 ;
F_2 ( & V_2 -> V_114 ) ;
V_113 = F_52 ( V_2 , V_3 , & V_108 ) ;
F_80 (e, t, &dev->vblank_event_list, base.link) {
if ( V_112 -> V_121 != V_3 )
continue;
if ( ( V_113 - V_112 -> V_115 . V_116 ) > ( 1 << 23 ) )
continue;
F_7 ( L_29 ,
V_112 -> V_115 . V_116 , V_113 ) ;
F_81 ( & V_112 -> V_83 . V_117 ) ;
F_69 ( V_2 , V_112 -> V_121 ) ;
F_54 ( V_2 , V_112 , V_113 , & V_108 ) ;
}
F_95 ( V_3 , V_113 ) ;
}
bool F_96 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = & V_2 -> V_8 [ V_3 ] ;
T_1 V_20 ;
T_2 V_21 ;
struct V_5 V_23 ;
unsigned long V_19 ;
if ( F_97 ( ! V_2 -> V_31 ) )
return false ;
if ( F_16 ( V_3 >= V_2 -> V_31 ) )
return false ;
F_9 ( & V_2 -> V_114 , V_19 ) ;
F_63 ( & V_2 -> V_10 ) ;
if ( ! V_8 -> V_25 ) {
F_65 ( & V_2 -> V_10 ) ;
F_10 ( & V_2 -> V_114 , V_19 ) ;
return false ;
}
V_20 = V_8 -> V_11 ;
F_6 ( V_2 , V_3 , & V_23 , V_162 ) ;
V_21 = F_11 ( & V_23 ) -
F_11 ( & F_3 ( V_2 , V_3 , V_20 ) ) ;
if ( F_12 ( V_21 ) > V_163 )
F_1 ( V_2 , V_3 , 1 , & V_23 ) ;
else
F_7 ( L_30 ,
V_3 , ( int ) V_21 ) ;
F_65 ( & V_2 -> V_10 ) ;
F_32 ( & V_8 -> V_39 ) ;
F_94 ( V_2 , V_3 ) ;
F_10 ( & V_2 -> V_114 , V_19 ) ;
return true ;
}
bool F_98 ( struct V_69 * V_3 )
{
return F_96 ( V_3 -> V_2 , F_51 ( V_3 ) ) ;
}
