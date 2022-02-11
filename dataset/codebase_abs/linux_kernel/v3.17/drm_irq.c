static void F_1 ( struct V_1 * V_2 , int V_3 )
{
memset ( V_2 -> V_4 [ V_3 ] . time , 0 , sizeof( V_2 -> V_4 [ V_3 ] . time ) ) ;
}
static void F_2 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_5 ;
T_1 V_6 ;
T_2 V_7 ;
int V_8 ;
struct V_9 V_10 ;
int V_11 = V_12 ;
F_3 ( & V_2 -> V_13 , V_5 ) ;
V_2 -> V_14 -> V_15 ( V_2 , V_3 ) ;
V_2 -> V_4 [ V_3 ] . V_16 = false ;
do {
V_2 -> V_4 [ V_3 ] . V_17 = V_2 -> V_14 -> V_18 ( V_2 , V_3 ) ;
V_8 = F_4 ( V_2 , V_3 , & V_10 , 0 ) ;
} while ( V_2 -> V_4 [ V_3 ] . V_17 != V_2 -> V_14 -> V_18 ( V_2 , V_3 ) && ( -- V_11 ) && V_8 );
if ( ! V_11 )
V_8 = 0 ;
V_6 = F_5 ( & V_2 -> V_4 [ V_3 ] . V_11 ) ;
V_7 = F_6 ( & V_10 ) -
F_6 ( & F_7 ( V_2 , V_3 , V_6 ) ) ;
if ( ( V_8 > 0 ) && ( F_8 ( V_7 ) > 1000000 ) ) {
F_9 ( & V_2 -> V_4 [ V_3 ] . V_11 ) ;
F_10 () ;
}
F_1 ( V_2 , V_3 ) ;
F_11 ( & V_2 -> V_13 , V_5 ) ;
}
static void F_12 ( unsigned long V_19 )
{
struct V_20 * V_4 = ( void * ) V_19 ;
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_5 ;
int V_3 = V_4 -> V_3 ;
if ( ! V_2 -> V_21 )
return;
F_3 ( & V_2 -> V_22 , V_5 ) ;
if ( F_5 ( & V_4 -> V_23 ) == 0 && V_4 -> V_16 ) {
F_13 ( L_1 , V_3 ) ;
F_2 ( V_2 , V_3 ) ;
}
F_11 ( & V_2 -> V_22 , V_5 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_24 == 0 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_24 ; V_3 ++ ) {
F_15 ( & V_2 -> V_4 [ V_3 ] . V_25 ) ;
F_12 ( ( unsigned long ) & V_2 -> V_4 [ V_3 ] ) ;
}
F_16 ( V_2 -> V_4 ) ;
V_2 -> V_24 = 0 ;
}
int F_17 ( struct V_1 * V_2 , int V_24 )
{
int V_26 , V_27 = - V_28 ;
F_18 ( & V_2 -> V_22 ) ;
F_18 ( & V_2 -> V_13 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_4 = F_19 ( V_24 , sizeof( * V_2 -> V_4 ) , V_29 ) ;
if ( ! V_2 -> V_4 )
goto V_30;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ ) {
V_2 -> V_4 [ V_26 ] . V_2 = V_2 ;
V_2 -> V_4 [ V_26 ] . V_3 = V_26 ;
F_20 ( & V_2 -> V_4 [ V_26 ] . V_31 ) ;
F_21 ( & V_2 -> V_4 [ V_26 ] . V_25 , F_12 ,
( unsigned long ) & V_2 -> V_4 [ V_26 ] ) ;
}
F_22 ( L_2 ) ;
if ( V_2 -> V_14 -> V_32 )
F_22 ( L_3 ) ;
else
F_22 ( L_4 ) ;
V_2 -> V_21 = false ;
return 0 ;
V_30:
F_14 ( V_2 ) ;
return V_27 ;
}
static void F_23 ( void * V_33 , bool V_34 )
{
struct V_1 * V_2 = V_33 ;
if ( V_2 -> V_14 -> V_35 ) {
V_2 -> V_14 -> V_35 ( V_2 , V_34 ) ;
return;
}
if ( ! V_2 -> V_36 )
return;
if ( V_34 ) {
if ( V_2 -> V_14 -> V_37 )
V_2 -> V_14 -> V_37 ( V_2 ) ;
} else {
if ( V_2 -> V_14 -> V_38 )
V_2 -> V_14 -> V_38 ( V_2 ) ;
if ( V_2 -> V_14 -> V_39 )
V_2 -> V_14 -> V_39 ( V_2 ) ;
}
}
int F_24 ( struct V_1 * V_2 , int V_40 )
{
int V_27 ;
unsigned long V_41 = 0 ;
if ( ! F_25 ( V_2 , V_42 ) )
return - V_43 ;
if ( V_40 == 0 )
return - V_43 ;
if ( ! V_2 -> V_44 )
return - V_43 ;
if ( V_2 -> V_36 )
return - V_45 ;
V_2 -> V_36 = true ;
F_13 ( L_5 , V_40 ) ;
if ( V_2 -> V_14 -> V_38 )
V_2 -> V_14 -> V_38 ( V_2 ) ;
if ( F_25 ( V_2 , V_46 ) )
V_41 = V_47 ;
V_27 = F_26 ( V_40 , V_2 -> V_14 -> V_48 ,
V_41 , V_2 -> V_14 -> V_49 , V_2 ) ;
if ( V_27 < 0 ) {
V_2 -> V_36 = false ;
return V_27 ;
}
if ( ! F_25 ( V_2 , V_50 ) )
F_27 ( V_2 -> V_51 , ( void * ) V_2 , F_23 , NULL ) ;
if ( V_2 -> V_14 -> V_39 )
V_27 = V_2 -> V_14 -> V_39 ( V_2 ) ;
if ( V_27 < 0 ) {
V_2 -> V_36 = false ;
if ( ! F_25 ( V_2 , V_50 ) )
F_27 ( V_2 -> V_51 , NULL , NULL , NULL ) ;
F_28 ( V_40 , V_2 ) ;
} else {
V_2 -> V_40 = V_40 ;
}
return V_27 ;
}
int F_29 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
bool V_36 ;
int V_26 ;
if ( ! F_25 ( V_2 , V_42 ) )
return - V_43 ;
V_36 = V_2 -> V_36 ;
V_2 -> V_36 = false ;
if ( V_2 -> V_24 ) {
F_3 ( & V_2 -> V_22 , V_5 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_24 ; V_26 ++ ) {
F_30 ( & V_2 -> V_4 [ V_26 ] . V_31 ) ;
V_2 -> V_4 [ V_26 ] . V_16 = false ;
V_2 -> V_4 [ V_26 ] . V_17 =
V_2 -> V_14 -> V_18 ( V_2 , V_26 ) ;
}
F_11 ( & V_2 -> V_22 , V_5 ) ;
}
if ( ! V_36 )
return - V_43 ;
F_13 ( L_5 , V_2 -> V_40 ) ;
if ( ! F_25 ( V_2 , V_50 ) )
F_27 ( V_2 -> V_51 , NULL , NULL , NULL ) ;
if ( V_2 -> V_14 -> V_37 )
V_2 -> V_14 -> V_37 ( V_2 ) ;
F_28 ( V_2 -> V_40 , V_2 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , void * V_52 ,
struct V_53 * V_54 )
{
struct F_31 * V_55 = V_52 ;
int V_27 = 0 , V_40 ;
if ( ! F_25 ( V_2 , V_42 ) )
return 0 ;
if ( F_25 ( V_2 , V_50 ) )
return 0 ;
if ( F_32 ( ! V_2 -> V_51 ) )
return - V_43 ;
switch ( V_55 -> V_56 ) {
case V_57 :
V_40 = V_2 -> V_51 -> V_40 ;
if ( V_2 -> V_58 < F_33 ( 1 , 2 ) &&
V_55 -> V_40 != V_40 )
return - V_43 ;
F_34 ( & V_2 -> V_59 ) ;
V_27 = F_24 ( V_2 , V_40 ) ;
F_35 ( & V_2 -> V_59 ) ;
return V_27 ;
case V_60 :
F_34 ( & V_2 -> V_59 ) ;
V_27 = F_29 ( V_2 ) ;
F_35 ( & V_2 -> V_59 ) ;
return V_27 ;
default:
return - V_43 ;
}
}
void F_36 ( struct V_61 * V_3 ,
const struct V_62 * V_63 )
{
int V_64 = 0 , V_65 = 0 , V_66 = 0 ;
int V_67 = V_63 -> V_68 ;
if ( V_67 > 0 ) {
int V_69 = V_63 -> V_70 * V_63 -> V_71 ;
V_65 = 1000000 / V_67 ;
V_64 = F_37 ( ( V_72 ) V_63 -> V_70 * 1000000 , V_67 ) ;
V_66 = F_37 ( ( V_72 ) V_69 * 1000000 , V_67 ) ;
if ( V_63 -> V_73 & V_74 )
V_66 /= 2 ;
} else
F_38 ( L_6 ,
V_3 -> V_75 . V_76 ) ;
V_3 -> V_65 = V_65 ;
V_3 -> V_64 = V_64 ;
V_3 -> V_66 = V_66 ;
F_13 ( L_7 ,
V_3 -> V_75 . V_76 , V_63 -> V_70 ,
V_63 -> V_71 , V_63 -> V_77 ) ;
F_13 ( L_8 ,
V_3 -> V_75 . V_76 , V_67 , V_66 ,
V_64 , V_65 ) ;
}
int F_39 ( struct V_1 * V_2 , int V_3 ,
int * V_78 ,
struct V_9 * V_79 ,
unsigned V_73 ,
const struct V_61 * V_80 ,
const struct V_62 * V_63 )
{
struct V_9 V_81 ;
T_3 V_82 , V_83 ;
int V_84 ;
int V_85 , V_86 , V_26 ;
int V_66 , V_64 , V_65 , V_87 , V_88 ;
bool V_89 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_24 ) {
F_38 ( L_9 , V_3 ) ;
return - V_43 ;
}
if ( ! V_2 -> V_14 -> V_90 ) {
F_38 ( L_10 ) ;
return - V_91 ;
}
V_66 = V_80 -> V_66 ;
V_64 = V_80 -> V_64 ;
V_65 = V_80 -> V_65 ;
if ( V_66 == 0 ) {
F_13 ( L_11 , V_3 ) ;
return - V_92 ;
}
for ( V_26 = 0 ; V_26 < V_12 ; V_26 ++ ) {
V_84 = V_2 -> V_14 -> V_90 ( V_2 , V_3 , V_73 , & V_85 ,
& V_86 , & V_82 , & V_83 ) ;
if ( ! ( V_84 & V_93 ) ) {
F_13 ( L_12 ,
V_3 , V_84 ) ;
return - V_91 ;
}
V_88 = F_40 ( V_83 ) - F_40 ( V_82 ) ;
if ( V_88 <= * V_78 )
break;
}
if ( V_26 == V_12 ) {
F_13 ( L_13 ,
V_3 , V_88 / 1000 , * V_78 / 1000 , V_26 ) ;
}
* V_78 = V_88 ;
V_89 = V_84 & V_94 ;
V_87 = V_85 * V_64 + V_86 * V_65 ;
if ( ! V_95 )
V_83 = F_41 ( V_83 ) ;
V_81 = F_42 ( V_83 ) ;
if ( V_87 < 0 )
V_83 = F_43 ( V_83 , - V_87 ) ;
else
V_83 = F_44 ( V_83 , V_87 ) ;
* V_79 = F_42 ( V_83 ) ;
F_13 ( L_14 ,
V_3 , ( int ) V_84 , V_86 , V_85 ,
( long ) V_81 . V_96 , ( long ) V_81 . V_97 ,
( long ) V_79 -> V_96 , ( long ) V_79 -> V_97 ,
V_88 / 1000 , V_26 ) ;
V_84 = V_98 ;
if ( V_89 )
V_84 |= V_99 ;
return V_84 ;
}
static struct V_9 F_45 ( void )
{
T_3 V_100 ;
V_100 = V_95 ? F_46 () : F_47 () ;
return F_42 ( V_100 ) ;
}
T_1 F_4 ( struct V_1 * V_2 , int V_3 ,
struct V_9 * V_10 , unsigned V_73 )
{
int V_27 ;
int V_78 = ( int ) V_101 * 1000 ;
if ( V_2 -> V_14 -> V_32 && ( V_78 > 0 ) ) {
V_27 = V_2 -> V_14 -> V_32 ( V_2 , V_3 , & V_78 ,
V_10 , V_73 ) ;
if ( V_27 > 0 )
return ( T_1 ) V_27 ;
}
* V_10 = F_45 () ;
return 0 ;
}
T_1 F_48 ( struct V_1 * V_2 , int V_3 )
{
return F_5 ( & V_2 -> V_4 [ V_3 ] . V_11 ) ;
}
T_1 F_49 ( struct V_1 * V_2 , int V_3 ,
struct V_9 * V_102 )
{
T_1 V_103 ;
do {
V_103 = F_5 ( & V_2 -> V_4 [ V_3 ] . V_11 ) ;
* V_102 = F_7 ( V_2 , V_3 , V_103 ) ;
F_50 () ;
} while ( V_103 != F_5 ( & V_2 -> V_4 [ V_3 ] . V_11 ) );
return V_103 ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_104 * V_105 ,
unsigned long V_106 , struct V_9 * V_100 )
{
F_52 ( ! F_53 ( & V_2 -> V_107 ) ) ;
V_105 -> V_108 . V_109 = V_106 ;
V_105 -> V_108 . V_96 = V_100 -> V_96 ;
V_105 -> V_108 . V_97 = V_100 -> V_97 ;
F_54 ( & V_105 -> V_75 . V_110 ,
& V_105 -> V_75 . V_54 -> V_111 ) ;
F_55 ( & V_105 -> V_75 . V_54 -> V_112 ) ;
F_56 ( V_105 -> V_75 . V_113 , V_105 -> V_114 ,
V_105 -> V_108 . V_109 ) ;
}
void F_57 ( struct V_1 * V_2 , int V_3 ,
struct V_104 * V_105 )
{
struct V_9 V_100 ;
unsigned int V_106 ;
if ( V_3 >= 0 ) {
V_106 = F_49 ( V_2 , V_3 , & V_100 ) ;
} else {
V_106 = 0 ;
V_100 = F_45 () ;
}
V_105 -> V_114 = V_3 ;
F_51 ( V_2 , V_105 , V_106 , & V_100 ) ;
}
static void F_58 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_103 , V_115 , V_116 , V_117 ;
struct V_9 V_118 ;
do {
V_103 = V_2 -> V_14 -> V_18 ( V_2 , V_3 ) ;
V_117 = F_4 ( V_2 , V_3 , & V_118 , 0 ) ;
} while ( V_103 != V_2 -> V_14 -> V_18 ( V_2 , V_3 ) );
V_115 = V_103 - V_2 -> V_4 [ V_3 ] . V_17 ;
if ( V_103 < V_2 -> V_4 [ V_3 ] . V_17 ) {
V_115 += V_2 -> V_119 ;
F_13 ( L_15 ,
V_3 , V_2 -> V_4 [ V_3 ] . V_17 , V_103 , V_115 ) ;
}
F_13 ( L_16 ,
V_3 , V_115 ) ;
if ( V_117 ) {
V_116 = F_5 ( & V_2 -> V_4 [ V_3 ] . V_11 ) + V_115 ;
F_7 ( V_2 , V_3 , V_116 ) = V_118 ;
}
F_59 () ;
F_60 ( V_115 , & V_2 -> V_4 [ V_3 ] . V_11 ) ;
F_10 () ;
}
static int F_61 ( struct V_1 * V_2 , int V_3 )
{
int V_27 = 0 ;
F_62 ( & V_2 -> V_22 ) ;
F_63 ( & V_2 -> V_13 ) ;
if ( ! V_2 -> V_4 [ V_3 ] . V_16 ) {
V_27 = V_2 -> V_14 -> V_120 ( V_2 , V_3 ) ;
F_13 ( L_17 , V_3 , V_27 ) ;
if ( V_27 )
F_64 ( & V_2 -> V_4 [ V_3 ] . V_23 ) ;
else {
V_2 -> V_4 [ V_3 ] . V_16 = true ;
F_58 ( V_2 , V_3 ) ;
}
}
F_65 ( & V_2 -> V_13 ) ;
return V_27 ;
}
int F_66 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_5 ;
int V_27 = 0 ;
F_3 ( & V_2 -> V_22 , V_5 ) ;
if ( F_67 ( 1 , & V_2 -> V_4 [ V_3 ] . V_23 ) == 1 ) {
V_27 = F_61 ( V_2 , V_3 ) ;
} else {
if ( ! V_2 -> V_4 [ V_3 ] . V_16 ) {
F_64 ( & V_2 -> V_4 [ V_3 ] . V_23 ) ;
V_27 = - V_43 ;
}
}
F_11 ( & V_2 -> V_22 , V_5 ) ;
return V_27 ;
}
int F_68 ( struct V_61 * V_3 )
{
return F_66 ( V_3 -> V_2 , F_69 ( V_3 ) ) ;
}
void F_70 ( struct V_1 * V_2 , int V_3 )
{
F_71 ( F_5 ( & V_2 -> V_4 [ V_3 ] . V_23 ) == 0 ) ;
if ( F_72 ( & V_2 -> V_4 [ V_3 ] . V_23 ) &&
( V_121 > 0 ) )
F_73 ( & V_2 -> V_4 [ V_3 ] . V_25 ,
V_122 + ( ( V_121 * V_123 ) / 1000 ) ) ;
}
void F_74 ( struct V_61 * V_3 )
{
F_70 ( V_3 -> V_2 , F_69 ( V_3 ) ) ;
}
void F_75 ( struct V_1 * V_2 , int V_3 )
{
struct V_104 * V_105 , * V_124 ;
struct V_9 V_100 ;
unsigned long V_5 ;
unsigned int V_106 ;
F_3 ( & V_2 -> V_22 , V_5 ) ;
F_2 ( V_2 , V_3 ) ;
F_30 ( & V_2 -> V_4 [ V_3 ] . V_31 ) ;
V_106 = F_49 ( V_2 , V_3 , & V_100 ) ;
F_63 ( & V_2 -> V_107 ) ;
F_76 (e, t, &dev->vblank_event_list, base.link) {
if ( V_105 -> V_114 != V_3 )
continue;
F_13 ( L_18 ,
V_105 -> V_108 . V_109 , V_106 ) ;
F_77 ( & V_105 -> V_75 . V_110 ) ;
F_70 ( V_2 , V_105 -> V_114 ) ;
F_51 ( V_2 , V_105 , V_106 , & V_100 ) ;
}
F_65 ( & V_2 -> V_107 ) ;
F_11 ( & V_2 -> V_22 , V_5 ) ;
}
void F_78 ( struct V_61 * V_3 )
{
F_75 ( V_3 -> V_2 , F_69 ( V_3 ) ) ;
}
void F_79 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_5 ;
F_3 ( & V_2 -> V_22 , V_5 ) ;
if ( F_5 ( & V_2 -> V_4 [ V_3 ] . V_23 ) != 0 )
F_32 ( F_61 ( V_2 , V_3 ) ) ;
F_11 ( & V_2 -> V_22 , V_5 ) ;
}
void F_80 ( struct V_61 * V_3 )
{
F_79 ( V_3 -> V_2 , F_69 ( V_3 ) ) ;
}
void F_81 ( struct V_1 * V_2 , int V_3 )
{
if ( ! V_2 -> V_24 )
return;
if ( ! V_2 -> V_4 [ V_3 ] . V_125 ) {
V_2 -> V_4 [ V_3 ] . V_125 = 0x1 ;
if ( F_66 ( V_2 , V_3 ) == 0 )
V_2 -> V_4 [ V_3 ] . V_125 |= 0x2 ;
}
}
void F_82 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_5 ;
if ( ! V_2 -> V_24 )
return;
if ( V_2 -> V_4 [ V_3 ] . V_125 ) {
F_3 ( & V_2 -> V_22 , V_5 ) ;
V_2 -> V_21 = true ;
F_11 ( & V_2 -> V_22 , V_5 ) ;
if ( V_2 -> V_4 [ V_3 ] . V_125 & 0x2 )
F_70 ( V_2 , V_3 ) ;
V_2 -> V_4 [ V_3 ] . V_125 = 0 ;
}
}
int F_83 ( struct V_1 * V_2 , void * V_52 ,
struct V_53 * V_54 )
{
struct F_83 * V_126 = V_52 ;
unsigned int V_3 ;
if ( ! V_2 -> V_24 )
return 0 ;
if ( F_25 ( V_2 , V_50 ) )
return 0 ;
V_3 = V_126 -> V_3 ;
if ( V_3 >= V_2 -> V_24 )
return - V_43 ;
switch ( V_126 -> V_127 ) {
case V_128 :
F_81 ( V_2 , V_3 ) ;
break;
case V_129 :
F_82 ( V_2 , V_3 ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , int V_114 ,
union V_130 * V_131 ,
struct V_53 * V_54 )
{
struct V_104 * V_105 ;
struct V_9 V_100 ;
unsigned long V_73 ;
unsigned int V_106 ;
int V_27 ;
V_105 = F_85 ( sizeof *V_105 , V_29 ) ;
if ( V_105 == NULL ) {
V_27 = - V_28 ;
goto V_132;
}
V_105 -> V_114 = V_114 ;
V_105 -> V_75 . V_113 = V_133 -> V_113 ;
V_105 -> V_108 . V_75 . type = V_134 ;
V_105 -> V_108 . V_75 . V_135 = sizeof V_105 -> V_108 ;
V_105 -> V_108 . V_136 = V_131 -> V_137 . signal ;
V_105 -> V_75 . V_108 = & V_105 -> V_108 . V_75 ;
V_105 -> V_75 . V_54 = V_54 ;
V_105 -> V_75 . V_138 = ( void ( * ) ( struct V_139 * ) ) F_16 ;
F_3 ( & V_2 -> V_107 , V_73 ) ;
if ( V_54 -> V_140 < sizeof V_105 -> V_108 ) {
V_27 = - V_45 ;
goto V_141;
}
V_54 -> V_140 -= sizeof V_105 -> V_108 ;
V_106 = F_49 ( V_2 , V_114 , & V_100 ) ;
if ( ( V_131 -> V_137 . type & V_142 ) &&
( V_106 - V_131 -> V_137 . V_109 ) <= ( 1 << 23 ) ) {
V_131 -> V_137 . V_109 = V_106 + 1 ;
V_131 -> V_143 . V_109 = V_131 -> V_137 . V_109 ;
}
F_13 ( L_19 ,
V_131 -> V_137 . V_109 , V_106 , V_114 ) ;
F_86 ( V_133 -> V_113 , V_114 ,
V_131 -> V_137 . V_109 ) ;
V_105 -> V_108 . V_109 = V_131 -> V_137 . V_109 ;
if ( ( V_106 - V_131 -> V_137 . V_109 ) <= ( 1 << 23 ) ) {
F_70 ( V_2 , V_114 ) ;
F_51 ( V_2 , V_105 , V_106 , & V_100 ) ;
V_131 -> V_143 . V_109 = V_106 ;
} else {
F_54 ( & V_105 -> V_75 . V_110 , & V_2 -> V_144 ) ;
V_131 -> V_143 . V_109 = V_131 -> V_137 . V_109 ;
}
F_11 ( & V_2 -> V_107 , V_73 ) ;
return 0 ;
V_141:
F_11 ( & V_2 -> V_107 , V_73 ) ;
F_16 ( V_105 ) ;
V_132:
F_70 ( V_2 , V_114 ) ;
return V_27 ;
}
int V_130 ( struct V_1 * V_2 , void * V_52 ,
struct V_53 * V_54 )
{
union V_130 * V_131 = V_52 ;
int V_27 ;
unsigned int V_73 , V_106 , V_3 , V_145 ;
if ( ! V_2 -> V_36 )
return - V_43 ;
if ( V_131 -> V_137 . type & V_146 )
return - V_43 ;
if ( V_131 -> V_137 . type &
~ ( V_147 | V_148 |
V_149 ) ) {
F_38 ( L_20 ,
V_131 -> V_137 . type ,
( V_147 | V_148 |
V_149 ) ) ;
return - V_43 ;
}
V_73 = V_131 -> V_137 . type & V_148 ;
V_145 = ( V_131 -> V_137 . type & V_149 ) ;
if ( V_145 )
V_3 = V_145 >> V_150 ;
else
V_3 = V_73 & V_151 ? 1 : 0 ;
if ( V_3 >= V_2 -> V_24 )
return - V_43 ;
V_27 = F_66 ( V_2 , V_3 ) ;
if ( V_27 ) {
F_13 ( L_21 , V_27 ) ;
return V_27 ;
}
V_106 = F_48 ( V_2 , V_3 ) ;
switch ( V_131 -> V_137 . type & V_147 ) {
case V_152 :
V_131 -> V_137 . V_109 += V_106 ;
V_131 -> V_137 . type &= ~ V_152 ;
case V_153 :
break;
default:
V_27 = - V_43 ;
goto V_154;
}
if ( V_73 & V_155 ) {
return F_84 ( V_2 , V_3 , V_131 , V_54 ) ;
}
if ( ( V_73 & V_142 ) &&
( V_106 - V_131 -> V_137 . V_109 ) <= ( 1 << 23 ) ) {
V_131 -> V_137 . V_109 = V_106 + 1 ;
}
F_13 ( L_22 ,
V_131 -> V_137 . V_109 , V_3 ) ;
V_2 -> V_4 [ V_3 ] . V_156 = V_131 -> V_137 . V_109 ;
F_87 ( V_27 , V_2 -> V_4 [ V_3 ] . V_31 , 3 * V_123 ,
( ( ( F_48 ( V_2 , V_3 ) -
V_131 -> V_137 . V_109 ) <= ( 1 << 23 ) ) ||
! V_2 -> V_4 [ V_3 ] . V_16 ||
! V_2 -> V_36 ) ) ;
if ( V_27 != - V_157 ) {
struct V_9 V_100 ;
V_131 -> V_143 . V_109 = F_49 ( V_2 , V_3 , & V_100 ) ;
V_131 -> V_143 . V_158 = V_100 . V_96 ;
V_131 -> V_143 . V_159 = V_100 . V_97 ;
F_13 ( L_23 ,
V_131 -> V_143 . V_109 ) ;
} else {
F_13 ( L_24 ) ;
}
V_154:
F_70 ( V_2 , V_3 ) ;
return V_27 ;
}
static void F_88 ( struct V_1 * V_2 , int V_3 )
{
struct V_104 * V_105 , * V_124 ;
struct V_9 V_100 ;
unsigned long V_73 ;
unsigned int V_106 ;
V_106 = F_49 ( V_2 , V_3 , & V_100 ) ;
F_3 ( & V_2 -> V_107 , V_73 ) ;
F_76 (e, t, &dev->vblank_event_list, base.link) {
if ( V_105 -> V_114 != V_3 )
continue;
if ( ( V_106 - V_105 -> V_108 . V_109 ) > ( 1 << 23 ) )
continue;
F_13 ( L_25 ,
V_105 -> V_108 . V_109 , V_106 ) ;
F_77 ( & V_105 -> V_75 . V_110 ) ;
F_70 ( V_2 , V_105 -> V_114 ) ;
F_51 ( V_2 , V_105 , V_106 , & V_100 ) ;
}
F_11 ( & V_2 -> V_107 , V_73 ) ;
F_89 ( V_3 , V_106 ) ;
}
bool F_90 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_6 ;
T_2 V_7 ;
struct V_9 V_10 ;
unsigned long V_5 ;
if ( ! V_2 -> V_24 )
return false ;
F_3 ( & V_2 -> V_13 , V_5 ) ;
if ( ! V_2 -> V_4 [ V_3 ] . V_16 ) {
F_11 ( & V_2 -> V_13 , V_5 ) ;
return false ;
}
V_6 = F_5 ( & V_2 -> V_4 [ V_3 ] . V_11 ) ;
F_4 ( V_2 , V_3 , & V_10 , V_160 ) ;
V_7 = F_6 ( & V_10 ) -
F_6 ( & F_7 ( V_2 , V_3 , V_6 ) ) ;
if ( F_8 ( V_7 ) > V_161 ) {
F_7 ( V_2 , V_3 , V_6 + 1 ) = V_10 ;
F_59 () ;
F_9 ( & V_2 -> V_4 [ V_3 ] . V_11 ) ;
F_10 () ;
} else {
F_13 ( L_26 ,
V_3 , ( int ) V_7 ) ;
}
F_30 ( & V_2 -> V_4 [ V_3 ] . V_31 ) ;
F_88 ( V_2 , V_3 ) ;
F_11 ( & V_2 -> V_13 , V_5 ) ;
return true ;
}
