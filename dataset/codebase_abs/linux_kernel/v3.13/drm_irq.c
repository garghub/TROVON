int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
if ( ! V_2 -> V_8 -> V_9 -> V_10 )
return - V_11 ;
if ( ! F_2 ( V_2 , V_12 ) )
return - V_11 ;
return V_2 -> V_8 -> V_9 -> V_10 ( V_2 , V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_13 )
{
memset ( V_2 -> V_14 [ V_13 ] . time , 0 , sizeof( V_2 -> V_14 [ V_13 ] . time ) ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_13 )
{
unsigned long V_15 ;
T_1 V_16 ;
T_2 V_17 ;
int V_18 ;
struct V_19 V_20 ;
int V_21 = V_22 ;
F_5 ( & V_2 -> V_23 , V_15 ) ;
V_2 -> V_8 -> V_24 ( V_2 , V_13 ) ;
V_2 -> V_14 [ V_13 ] . V_25 = false ;
do {
V_2 -> V_14 [ V_13 ] . V_26 = V_2 -> V_8 -> V_27 ( V_2 , V_13 ) ;
V_18 = F_6 ( V_2 , V_13 , & V_20 , 0 ) ;
} while ( V_2 -> V_14 [ V_13 ] . V_26 != V_2 -> V_8 -> V_27 ( V_2 , V_13 ) && ( -- V_21 ) && V_18 );
if ( ! V_21 )
V_18 = 0 ;
V_16 = F_7 ( & V_2 -> V_14 [ V_13 ] . V_21 ) ;
V_17 = F_8 ( & V_20 ) -
F_8 ( & F_9 ( V_2 , V_13 , V_16 ) ) ;
if ( ( V_18 > 0 ) && ( F_10 ( V_17 ) > 1000000 ) ) {
F_11 ( & V_2 -> V_14 [ V_13 ] . V_21 ) ;
F_12 () ;
}
F_3 ( V_2 , V_13 ) ;
F_13 ( & V_2 -> V_23 , V_15 ) ;
}
static void F_14 ( unsigned long V_28 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
unsigned long V_15 ;
int V_29 ;
if ( ! V_2 -> V_30 )
return;
for ( V_29 = 0 ; V_29 < V_2 -> V_31 ; V_29 ++ ) {
F_5 ( & V_2 -> V_32 , V_15 ) ;
if ( F_7 ( & V_2 -> V_14 [ V_29 ] . V_33 ) == 0 &&
V_2 -> V_14 [ V_29 ] . V_25 ) {
F_15 ( L_1 , V_29 ) ;
F_4 ( V_2 , V_29 ) ;
}
F_13 ( & V_2 -> V_32 , V_15 ) ;
}
}
void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 == 0 )
return;
F_17 ( & V_2 -> V_34 ) ;
F_14 ( ( unsigned long ) V_2 ) ;
F_18 ( V_2 -> V_14 ) ;
V_2 -> V_31 = 0 ;
}
int F_19 ( struct V_1 * V_2 , int V_31 )
{
int V_29 , V_35 = - V_36 ;
F_20 ( & V_2 -> V_34 , F_14 ,
( unsigned long ) V_2 ) ;
F_21 ( & V_2 -> V_32 ) ;
F_21 ( & V_2 -> V_23 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_14 = F_22 ( V_31 , sizeof( * V_2 -> V_14 ) , V_37 ) ;
if ( ! V_2 -> V_14 )
goto V_38;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ )
F_23 ( & V_2 -> V_14 [ V_29 ] . V_39 ) ;
F_24 ( L_2 ) ;
if ( V_2 -> V_8 -> V_40 )
F_24 ( L_3 ) ;
else
F_24 ( L_4 ) ;
V_2 -> V_30 = false ;
return 0 ;
V_38:
F_16 ( V_2 ) ;
return V_35 ;
}
static void F_25 ( void * V_41 , bool V_42 )
{
struct V_1 * V_2 = V_41 ;
if ( V_2 -> V_8 -> V_43 ) {
V_2 -> V_8 -> V_43 ( V_2 , V_42 ) ;
return;
}
if ( ! V_2 -> V_44 )
return;
if ( V_42 ) {
if ( V_2 -> V_8 -> V_45 )
V_2 -> V_8 -> V_45 ( V_2 ) ;
} else {
if ( V_2 -> V_8 -> V_46 )
V_2 -> V_8 -> V_46 ( V_2 ) ;
if ( V_2 -> V_8 -> V_47 )
V_2 -> V_8 -> V_47 ( V_2 ) ;
}
}
int F_26 ( struct V_1 * V_2 )
{
int V_35 ;
unsigned long V_48 = 0 ;
char * V_49 ;
if ( ! F_2 ( V_2 , V_12 ) )
return - V_11 ;
if ( F_27 ( V_2 ) == 0 )
return - V_11 ;
F_28 ( & V_2 -> V_50 ) ;
if ( ! V_2 -> V_51 ) {
F_29 ( & V_2 -> V_50 ) ;
return - V_11 ;
}
if ( V_2 -> V_44 ) {
F_29 ( & V_2 -> V_50 ) ;
return - V_52 ;
}
V_2 -> V_44 = true ;
F_29 ( & V_2 -> V_50 ) ;
F_15 ( L_5 , F_27 ( V_2 ) ) ;
if ( V_2 -> V_8 -> V_46 )
V_2 -> V_8 -> V_46 ( V_2 ) ;
if ( F_2 ( V_2 , V_53 ) )
V_48 = V_54 ;
if ( V_2 -> V_55 )
V_49 = V_2 -> V_55 ;
else
V_49 = V_2 -> V_8 -> V_56 ;
V_35 = F_30 ( F_27 ( V_2 ) , V_2 -> V_8 -> V_57 ,
V_48 , V_49 , V_2 ) ;
if ( V_35 < 0 ) {
F_28 ( & V_2 -> V_50 ) ;
V_2 -> V_44 = false ;
F_29 ( & V_2 -> V_50 ) ;
return V_35 ;
}
if ( ! F_2 ( V_2 , V_58 ) )
F_31 ( V_2 -> V_59 , ( void * ) V_2 , F_25 , NULL ) ;
if ( V_2 -> V_8 -> V_47 )
V_35 = V_2 -> V_8 -> V_47 ( V_2 ) ;
if ( V_35 < 0 ) {
F_28 ( & V_2 -> V_50 ) ;
V_2 -> V_44 = false ;
F_29 ( & V_2 -> V_50 ) ;
if ( ! F_2 ( V_2 , V_58 ) )
F_31 ( V_2 -> V_59 , NULL , NULL , NULL ) ;
F_32 ( F_27 ( V_2 ) , V_2 ) ;
}
return V_35 ;
}
int F_33 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
bool V_44 ;
int V_29 ;
if ( ! F_2 ( V_2 , V_12 ) )
return - V_11 ;
F_28 ( & V_2 -> V_50 ) ;
V_44 = V_2 -> V_44 ;
V_2 -> V_44 = false ;
F_29 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_31 ) {
F_5 ( & V_2 -> V_32 , V_15 ) ;
for ( V_29 = 0 ; V_29 < V_2 -> V_31 ; V_29 ++ ) {
F_34 ( & V_2 -> V_14 [ V_29 ] . V_39 ) ;
V_2 -> V_14 [ V_29 ] . V_25 = false ;
V_2 -> V_14 [ V_29 ] . V_26 =
V_2 -> V_8 -> V_27 ( V_2 , V_29 ) ;
}
F_13 ( & V_2 -> V_32 , V_15 ) ;
}
if ( ! V_44 )
return - V_11 ;
F_15 ( L_5 , F_27 ( V_2 ) ) ;
if ( ! F_2 ( V_2 , V_58 ) )
F_31 ( V_2 -> V_59 , NULL , NULL , NULL ) ;
if ( V_2 -> V_8 -> V_45 )
V_2 -> V_8 -> V_45 ( V_2 ) ;
F_32 ( F_27 ( V_2 ) , V_2 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_35 * V_60 = V_3 ;
switch ( V_60 -> V_61 ) {
case V_62 :
if ( ! F_2 ( V_2 , V_12 ) )
return 0 ;
if ( F_2 ( V_2 , V_58 ) )
return 0 ;
if ( V_2 -> V_63 < F_36 ( 1 , 2 ) &&
V_60 -> V_64 != F_27 ( V_2 ) )
return - V_11 ;
return F_26 ( V_2 ) ;
case V_65 :
if ( ! F_2 ( V_2 , V_12 ) )
return 0 ;
if ( F_2 ( V_2 , V_58 ) )
return 0 ;
return F_33 ( V_2 ) ;
default:
return - V_11 ;
}
}
void F_37 ( struct V_66 * V_13 )
{
T_2 V_67 = 0 , V_68 = 0 , V_69 = 0 ;
T_3 V_70 ;
V_70 = ( T_3 ) V_13 -> V_71 . clock * 1000 ;
if ( V_13 -> V_71 . V_72 & V_73 )
V_70 *= 2 ;
if ( V_70 > 0 ) {
int V_74 ;
V_68 = ( T_2 ) F_38 ( 1000000000 , V_70 ) ;
V_67 = ( T_2 ) F_38 ( ( ( T_3 ) V_13 -> V_71 . V_75 *
1000000000 ) , V_70 ) ;
V_74 = V_13 -> V_71 . V_75 *
V_13 -> V_71 . V_76 ;
V_69 = ( T_2 ) F_38 ( ( T_3 ) V_74 * 1000000000 ,
V_70 ) ;
} else
F_39 ( L_6 ,
V_13 -> V_77 . V_78 ) ;
V_13 -> V_68 = V_68 ;
V_13 -> V_67 = V_67 ;
V_13 -> V_69 = V_69 ;
F_15 ( L_7 ,
V_13 -> V_77 . V_78 , V_13 -> V_71 . V_75 ,
V_13 -> V_71 . V_76 , V_13 -> V_71 . V_79 ) ;
F_15 ( L_8 ,
V_13 -> V_77 . V_78 , ( int ) V_70 / 1000 , ( int ) V_69 ,
( int ) V_67 , ( int ) V_68 ) ;
}
int F_40 ( struct V_1 * V_2 , int V_13 ,
int * V_80 ,
struct V_19 * V_81 ,
unsigned V_72 ,
struct V_66 * V_82 )
{
T_4 V_83 , V_84 , V_85 ;
struct V_19 V_86 ;
struct V_87 * V_88 ;
int V_89 , V_90 , V_91 ;
int V_92 , V_93 , V_29 ;
T_2 V_69 , V_67 , V_68 , V_94 , V_95 ;
bool V_96 ;
if ( V_13 < 0 || V_13 >= V_2 -> V_31 ) {
F_39 ( L_9 , V_13 ) ;
return - V_11 ;
}
if ( ! V_2 -> V_8 -> V_97 ) {
F_39 ( L_10 ) ;
return - V_98 ;
}
V_88 = & V_82 -> V_71 ;
V_90 = V_88 -> V_76 ;
V_91 = V_88 -> V_79 ;
V_69 = V_82 -> V_69 ;
V_67 = V_82 -> V_67 ;
V_68 = V_82 -> V_68 ;
if ( V_90 <= 0 || V_91 <= 0 || V_69 == 0 ) {
F_15 ( L_11 , V_13 ) ;
return - V_99 ;
}
for ( V_29 = 0 ; V_29 < V_22 ; V_29 ++ ) {
V_89 = V_2 -> V_8 -> V_97 ( V_2 , V_13 , & V_92 ,
& V_93 , & V_83 , & V_84 ) ;
if ( ! V_100 )
V_85 = F_41 () ;
if ( ! ( V_89 & V_101 ) ) {
F_15 ( L_12 ,
V_13 , V_89 ) ;
return - V_98 ;
}
V_95 = F_42 ( V_84 ) - F_42 ( V_83 ) ;
if ( V_95 <= ( T_2 ) * V_80 )
break;
}
if ( V_29 == V_22 ) {
F_15 ( L_13 ,
V_13 , ( int ) V_95 / 1000 , * V_80 / 1000 , V_29 ) ;
}
* V_80 = ( int ) V_95 ;
V_96 = V_89 & V_102 ;
V_94 = ( T_2 ) V_92 * V_67 + ( T_2 ) V_93 * V_68 ;
if ( ( V_72 & V_103 ) && ! V_96 &&
( ( V_91 - V_92 ) < V_90 / 100 ) ) {
V_94 = V_94 - V_69 ;
V_89 |= 0x8 ;
}
if ( ! V_100 )
V_84 = F_43 ( V_84 , V_85 ) ;
V_86 = F_44 ( V_84 ) ;
if ( V_94 < 0 )
V_84 = F_45 ( V_84 , - V_94 ) ;
else
V_84 = F_46 ( V_84 , V_94 ) ;
* V_81 = F_44 ( V_84 ) ;
F_15 ( L_14 ,
V_13 , ( int ) V_89 , V_93 , V_92 ,
( long ) V_86 . V_104 , ( long ) V_86 . V_105 ,
( long ) V_81 -> V_104 , ( long ) V_81 -> V_105 ,
( int ) V_95 / 1000 , V_29 ) ;
V_89 = V_106 ;
if ( V_96 )
V_89 |= V_107 ;
return V_89 ;
}
static struct V_19 F_47 ( void )
{
T_4 V_108 ;
V_108 = F_48 () ;
if ( ! V_100 )
V_108 = F_43 ( V_108 , F_41 () ) ;
return F_44 ( V_108 ) ;
}
T_1 F_6 ( struct V_1 * V_2 , int V_13 ,
struct V_19 * V_20 , unsigned V_72 )
{
int V_35 ;
int V_80 = ( int ) V_109 * 1000 ;
if ( V_2 -> V_8 -> V_40 && ( V_80 > 0 ) ) {
V_35 = V_2 -> V_8 -> V_40 ( V_2 , V_13 , & V_80 ,
V_20 , V_72 ) ;
if ( V_35 > 0 )
return ( T_1 ) V_35 ;
}
* V_20 = F_47 () ;
return 0 ;
}
T_1 F_49 ( struct V_1 * V_2 , int V_13 )
{
return F_7 ( & V_2 -> V_14 [ V_13 ] . V_21 ) ;
}
T_1 F_50 ( struct V_1 * V_2 , int V_13 ,
struct V_19 * V_110 )
{
T_1 V_111 ;
do {
V_111 = F_7 ( & V_2 -> V_14 [ V_13 ] . V_21 ) ;
* V_110 = F_9 ( V_2 , V_13 , V_111 ) ;
F_51 () ;
} while ( V_111 != F_7 ( & V_2 -> V_14 [ V_13 ] . V_21 ) );
return V_111 ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_112 * V_113 ,
unsigned long V_114 , struct V_19 * V_108 )
{
F_53 ( ! F_54 ( & V_2 -> V_115 ) ) ;
V_113 -> V_116 . V_117 = V_114 ;
V_113 -> V_116 . V_104 = V_108 -> V_104 ;
V_113 -> V_116 . V_105 = V_108 -> V_105 ;
F_55 ( & V_113 -> V_77 . V_118 ,
& V_113 -> V_77 . V_5 -> V_119 ) ;
F_56 ( & V_113 -> V_77 . V_5 -> V_120 ) ;
F_57 ( V_113 -> V_77 . V_121 , V_113 -> V_122 ,
V_113 -> V_116 . V_117 ) ;
}
void F_58 ( struct V_1 * V_2 , int V_13 ,
struct V_112 * V_113 )
{
struct V_19 V_108 ;
unsigned int V_114 ;
if ( V_13 >= 0 ) {
V_114 = F_50 ( V_2 , V_13 , & V_108 ) ;
} else {
V_114 = 0 ;
V_108 = F_47 () ;
}
V_113 -> V_122 = V_13 ;
F_52 ( V_2 , V_113 , V_114 , & V_108 ) ;
}
static void F_59 ( struct V_1 * V_2 , int V_13 )
{
T_1 V_111 , V_123 , V_124 , V_125 ;
struct V_19 V_126 ;
do {
V_111 = V_2 -> V_8 -> V_27 ( V_2 , V_13 ) ;
V_125 = F_6 ( V_2 , V_13 , & V_126 , 0 ) ;
} while ( V_111 != V_2 -> V_8 -> V_27 ( V_2 , V_13 ) );
V_123 = V_111 - V_2 -> V_14 [ V_13 ] . V_26 ;
if ( V_111 < V_2 -> V_14 [ V_13 ] . V_26 ) {
V_123 += V_2 -> V_127 ;
F_15 ( L_15 ,
V_13 , V_2 -> V_14 [ V_13 ] . V_26 , V_111 , V_123 ) ;
}
F_15 ( L_16 ,
V_13 , V_123 ) ;
if ( V_125 ) {
V_124 = F_7 ( & V_2 -> V_14 [ V_13 ] . V_21 ) + V_123 ;
F_9 ( V_2 , V_13 , V_124 ) = V_126 ;
}
F_60 () ;
F_61 ( V_123 , & V_2 -> V_14 [ V_13 ] . V_21 ) ;
F_12 () ;
}
int F_62 ( struct V_1 * V_2 , int V_13 )
{
unsigned long V_15 , V_128 ;
int V_35 = 0 ;
F_5 ( & V_2 -> V_32 , V_15 ) ;
if ( F_63 ( 1 , & V_2 -> V_14 [ V_13 ] . V_33 ) == 1 ) {
F_5 ( & V_2 -> V_23 , V_128 ) ;
if ( ! V_2 -> V_14 [ V_13 ] . V_25 ) {
V_35 = V_2 -> V_8 -> V_129 ( V_2 , V_13 ) ;
F_15 ( L_17 ,
V_13 , V_35 ) ;
if ( V_35 )
F_64 ( & V_2 -> V_14 [ V_13 ] . V_33 ) ;
else {
V_2 -> V_14 [ V_13 ] . V_25 = true ;
F_59 ( V_2 , V_13 ) ;
}
}
F_13 ( & V_2 -> V_23 , V_128 ) ;
} else {
if ( ! V_2 -> V_14 [ V_13 ] . V_25 ) {
F_64 ( & V_2 -> V_14 [ V_13 ] . V_33 ) ;
V_35 = - V_11 ;
}
}
F_13 ( & V_2 -> V_32 , V_15 ) ;
return V_35 ;
}
void F_65 ( struct V_1 * V_2 , int V_13 )
{
F_66 ( F_7 ( & V_2 -> V_14 [ V_13 ] . V_33 ) == 0 ) ;
if ( F_67 ( & V_2 -> V_14 [ V_13 ] . V_33 ) &&
( V_130 > 0 ) )
F_68 ( & V_2 -> V_34 ,
V_131 + ( ( V_130 * V_132 ) / 1000 ) ) ;
}
void F_69 ( struct V_1 * V_2 , int V_13 )
{
struct V_112 * V_113 , * V_133 ;
struct V_19 V_108 ;
unsigned long V_15 ;
unsigned int V_114 ;
F_5 ( & V_2 -> V_32 , V_15 ) ;
F_4 ( V_2 , V_13 ) ;
F_34 ( & V_2 -> V_14 [ V_13 ] . V_39 ) ;
V_114 = F_50 ( V_2 , V_13 , & V_108 ) ;
F_70 ( & V_2 -> V_115 ) ;
F_71 (e, t, &dev->vblank_event_list, base.link) {
if ( V_113 -> V_122 != V_13 )
continue;
F_15 ( L_18 ,
V_113 -> V_116 . V_117 , V_114 ) ;
F_72 ( & V_113 -> V_77 . V_118 ) ;
F_65 ( V_2 , V_113 -> V_122 ) ;
F_52 ( V_2 , V_113 , V_114 , & V_108 ) ;
}
F_73 ( & V_2 -> V_115 ) ;
F_13 ( & V_2 -> V_32 , V_15 ) ;
}
void F_74 ( struct V_1 * V_2 , int V_13 )
{
if ( ! V_2 -> V_31 )
return;
if ( ! V_2 -> V_14 [ V_13 ] . V_134 ) {
V_2 -> V_14 [ V_13 ] . V_134 = 0x1 ;
if ( F_62 ( V_2 , V_13 ) == 0 )
V_2 -> V_14 [ V_13 ] . V_134 |= 0x2 ;
}
}
void F_75 ( struct V_1 * V_2 , int V_13 )
{
unsigned long V_15 ;
if ( ! V_2 -> V_31 )
return;
if ( V_2 -> V_14 [ V_13 ] . V_134 ) {
F_5 ( & V_2 -> V_32 , V_15 ) ;
V_2 -> V_30 = true ;
F_13 ( & V_2 -> V_32 , V_15 ) ;
if ( V_2 -> V_14 [ V_13 ] . V_134 & 0x2 )
F_65 ( V_2 , V_13 ) ;
V_2 -> V_14 [ V_13 ] . V_134 = 0 ;
}
}
int F_76 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_76 * V_135 = V_3 ;
unsigned int V_13 ;
if ( ! V_2 -> V_31 )
return 0 ;
if ( F_2 ( V_2 , V_58 ) )
return 0 ;
V_13 = V_135 -> V_13 ;
if ( V_13 >= V_2 -> V_31 )
return - V_11 ;
switch ( V_135 -> V_136 ) {
case V_137 :
F_74 ( V_2 , V_13 ) ;
break;
case V_138 :
F_75 ( V_2 , V_13 ) ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , int V_122 ,
union V_139 * V_140 ,
struct V_4 * V_5 )
{
struct V_112 * V_113 ;
struct V_19 V_108 ;
unsigned long V_72 ;
unsigned int V_114 ;
int V_35 ;
V_113 = F_78 ( sizeof *V_113 , V_37 ) ;
if ( V_113 == NULL ) {
V_35 = - V_36 ;
goto V_141;
}
V_113 -> V_122 = V_122 ;
V_113 -> V_77 . V_121 = V_142 -> V_121 ;
V_113 -> V_116 . V_77 . type = V_143 ;
V_113 -> V_116 . V_77 . V_144 = sizeof V_113 -> V_116 ;
V_113 -> V_116 . V_145 = V_140 -> V_146 . signal ;
V_113 -> V_77 . V_116 = & V_113 -> V_116 . V_77 ;
V_113 -> V_77 . V_5 = V_5 ;
V_113 -> V_77 . V_147 = ( void ( * ) ( struct V_148 * ) ) F_18 ;
F_5 ( & V_2 -> V_115 , V_72 ) ;
if ( V_5 -> V_149 < sizeof V_113 -> V_116 ) {
V_35 = - V_52 ;
goto V_150;
}
V_5 -> V_149 -= sizeof V_113 -> V_116 ;
V_114 = F_50 ( V_2 , V_122 , & V_108 ) ;
if ( ( V_140 -> V_146 . type & V_151 ) &&
( V_114 - V_140 -> V_146 . V_117 ) <= ( 1 << 23 ) ) {
V_140 -> V_146 . V_117 = V_114 + 1 ;
V_140 -> V_152 . V_117 = V_140 -> V_146 . V_117 ;
}
F_15 ( L_19 ,
V_140 -> V_146 . V_117 , V_114 , V_122 ) ;
F_79 ( V_142 -> V_121 , V_122 ,
V_140 -> V_146 . V_117 ) ;
V_113 -> V_116 . V_117 = V_140 -> V_146 . V_117 ;
if ( ( V_114 - V_140 -> V_146 . V_117 ) <= ( 1 << 23 ) ) {
F_65 ( V_2 , V_122 ) ;
F_52 ( V_2 , V_113 , V_114 , & V_108 ) ;
V_140 -> V_152 . V_117 = V_114 ;
} else {
F_55 ( & V_113 -> V_77 . V_118 , & V_2 -> V_153 ) ;
V_140 -> V_152 . V_117 = V_140 -> V_146 . V_117 ;
}
F_13 ( & V_2 -> V_115 , V_72 ) ;
return 0 ;
V_150:
F_13 ( & V_2 -> V_115 , V_72 ) ;
F_18 ( V_113 ) ;
V_141:
F_65 ( V_2 , V_122 ) ;
return V_35 ;
}
int V_139 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
union V_139 * V_140 = V_3 ;
int V_35 ;
unsigned int V_72 , V_114 , V_13 , V_154 ;
if ( F_2 ( V_2 , V_12 ) )
if ( ( ! F_27 ( V_2 ) ) || ( ! V_2 -> V_44 ) )
return - V_11 ;
if ( V_140 -> V_146 . type & V_155 )
return - V_11 ;
if ( V_140 -> V_146 . type &
~ ( V_156 | V_157 |
V_158 ) ) {
F_39 ( L_20 ,
V_140 -> V_146 . type ,
( V_156 | V_157 |
V_158 ) ) ;
return - V_11 ;
}
V_72 = V_140 -> V_146 . type & V_157 ;
V_154 = ( V_140 -> V_146 . type & V_158 ) ;
if ( V_154 )
V_13 = V_154 >> V_159 ;
else
V_13 = V_72 & V_160 ? 1 : 0 ;
if ( V_13 >= V_2 -> V_31 )
return - V_11 ;
V_35 = F_62 ( V_2 , V_13 ) ;
if ( V_35 ) {
F_15 ( L_21 , V_35 ) ;
return V_35 ;
}
V_114 = F_49 ( V_2 , V_13 ) ;
switch ( V_140 -> V_146 . type & V_156 ) {
case V_161 :
V_140 -> V_146 . V_117 += V_114 ;
V_140 -> V_146 . type &= ~ V_161 ;
case V_162 :
break;
default:
V_35 = - V_11 ;
goto V_163;
}
if ( V_72 & V_164 ) {
return F_77 ( V_2 , V_13 , V_140 , V_5 ) ;
}
if ( ( V_72 & V_151 ) &&
( V_114 - V_140 -> V_146 . V_117 ) <= ( 1 << 23 ) ) {
V_140 -> V_146 . V_117 = V_114 + 1 ;
}
F_15 ( L_22 ,
V_140 -> V_146 . V_117 , V_13 ) ;
V_2 -> V_14 [ V_13 ] . V_165 = V_140 -> V_146 . V_117 ;
F_80 ( V_35 , V_2 -> V_14 [ V_13 ] . V_39 , 3 * V_132 ,
( ( ( F_49 ( V_2 , V_13 ) -
V_140 -> V_146 . V_117 ) <= ( 1 << 23 ) ) ||
! V_2 -> V_44 ) ) ;
if ( V_35 != - V_166 ) {
struct V_19 V_108 ;
V_140 -> V_152 . V_117 = F_50 ( V_2 , V_13 , & V_108 ) ;
V_140 -> V_152 . V_167 = V_108 . V_104 ;
V_140 -> V_152 . V_168 = V_108 . V_105 ;
F_15 ( L_23 ,
V_140 -> V_152 . V_117 ) ;
} else {
F_15 ( L_24 ) ;
}
V_163:
F_65 ( V_2 , V_13 ) ;
return V_35 ;
}
static void F_81 ( struct V_1 * V_2 , int V_13 )
{
struct V_112 * V_113 , * V_133 ;
struct V_19 V_108 ;
unsigned long V_72 ;
unsigned int V_114 ;
V_114 = F_50 ( V_2 , V_13 , & V_108 ) ;
F_5 ( & V_2 -> V_115 , V_72 ) ;
F_71 (e, t, &dev->vblank_event_list, base.link) {
if ( V_113 -> V_122 != V_13 )
continue;
if ( ( V_114 - V_113 -> V_116 . V_117 ) > ( 1 << 23 ) )
continue;
F_15 ( L_25 ,
V_113 -> V_116 . V_117 , V_114 ) ;
F_72 ( & V_113 -> V_77 . V_118 ) ;
F_65 ( V_2 , V_113 -> V_122 ) ;
F_52 ( V_2 , V_113 , V_114 , & V_108 ) ;
}
F_13 ( & V_2 -> V_115 , V_72 ) ;
F_82 ( V_13 , V_114 ) ;
}
bool F_83 ( struct V_1 * V_2 , int V_13 )
{
T_1 V_16 ;
T_2 V_17 ;
struct V_19 V_20 ;
unsigned long V_15 ;
if ( ! V_2 -> V_31 )
return false ;
F_5 ( & V_2 -> V_23 , V_15 ) ;
if ( ! V_2 -> V_14 [ V_13 ] . V_25 ) {
F_13 ( & V_2 -> V_23 , V_15 ) ;
return false ;
}
V_16 = F_7 ( & V_2 -> V_14 [ V_13 ] . V_21 ) ;
F_6 ( V_2 , V_13 , & V_20 , V_103 ) ;
V_17 = F_8 ( & V_20 ) -
F_8 ( & F_9 ( V_2 , V_13 , V_16 ) ) ;
if ( F_10 ( V_17 ) > V_169 ) {
F_9 ( V_2 , V_13 , V_16 + 1 ) = V_20 ;
F_60 () ;
F_11 ( & V_2 -> V_14 [ V_13 ] . V_21 ) ;
F_12 () ;
} else {
F_15 ( L_26 ,
V_13 , ( int ) V_17 ) ;
}
F_34 ( & V_2 -> V_14 [ V_13 ] . V_39 ) ;
F_81 ( V_2 , V_13 ) ;
F_13 ( & V_2 -> V_23 , V_15 ) ;
return true ;
}
