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
memset ( & V_2 -> V_14 [ V_13 * V_15 ] , 0 ,
V_15 * sizeof( struct V_16 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_13 )
{
unsigned long V_17 ;
T_1 V_18 ;
T_2 V_19 ;
int V_20 ;
struct V_16 V_21 ;
F_5 ( & V_2 -> V_22 , V_17 ) ;
V_2 -> V_8 -> V_23 ( V_2 , V_13 ) ;
V_2 -> V_24 [ V_13 ] = 0 ;
do {
V_2 -> V_25 [ V_13 ] = V_2 -> V_8 -> V_26 ( V_2 , V_13 ) ;
V_20 = F_6 ( V_2 , V_13 , & V_21 , 0 ) ;
} while ( V_2 -> V_25 [ V_13 ] != V_2 -> V_8 -> V_26 ( V_2 , V_13 ) );
V_18 = F_7 ( & V_2 -> V_27 [ V_13 ] ) ;
V_19 = F_8 ( & V_21 ) -
F_8 ( & F_9 ( V_2 , V_13 , V_18 ) ) ;
if ( ( V_20 > 0 ) && ( F_10 ( V_19 ) > 1000000 ) ) {
F_11 ( & V_2 -> V_27 [ V_13 ] ) ;
F_12 () ;
}
F_3 ( V_2 , V_13 ) ;
F_13 ( & V_2 -> V_22 , V_17 ) ;
}
static void F_14 ( unsigned long V_28 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
unsigned long V_17 ;
int V_29 ;
if ( ! V_2 -> V_30 )
return;
for ( V_29 = 0 ; V_29 < V_2 -> V_31 ; V_29 ++ ) {
F_5 ( & V_2 -> V_32 , V_17 ) ;
if ( F_7 ( & V_2 -> V_33 [ V_29 ] ) == 0 &&
V_2 -> V_24 [ V_29 ] ) {
F_15 ( L_1 , V_29 ) ;
F_4 ( V_2 , V_29 ) ;
}
F_13 ( & V_2 -> V_32 , V_17 ) ;
}
}
void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 == 0 )
return;
F_17 ( & V_2 -> V_34 ) ;
F_14 ( ( unsigned long ) V_2 ) ;
F_18 ( V_2 -> V_35 ) ;
F_18 ( V_2 -> V_27 ) ;
F_18 ( V_2 -> V_33 ) ;
F_18 ( V_2 -> V_24 ) ;
F_18 ( V_2 -> V_25 ) ;
F_18 ( V_2 -> V_36 ) ;
F_18 ( V_2 -> V_37 ) ;
F_18 ( V_2 -> V_14 ) ;
V_2 -> V_31 = 0 ;
}
int F_19 ( struct V_1 * V_2 , int V_31 )
{
int V_29 , V_38 = - V_39 ;
F_20 ( & V_2 -> V_34 , F_14 ,
( unsigned long ) V_2 ) ;
F_21 ( & V_2 -> V_32 ) ;
F_21 ( & V_2 -> V_22 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_35 = F_22 ( sizeof( V_40 ) * V_31 ,
V_41 ) ;
if ( ! V_2 -> V_35 )
goto V_42;
V_2 -> V_27 = F_22 ( sizeof( V_43 ) * V_31 , V_41 ) ;
if ( ! V_2 -> V_27 )
goto V_42;
V_2 -> V_33 = F_22 ( sizeof( V_43 ) * V_31 ,
V_41 ) ;
if ( ! V_2 -> V_33 )
goto V_42;
V_2 -> V_24 = F_23 ( V_31 , sizeof( int ) , V_41 ) ;
if ( ! V_2 -> V_24 )
goto V_42;
V_2 -> V_25 = F_23 ( V_31 , sizeof( T_1 ) , V_41 ) ;
if ( ! V_2 -> V_25 )
goto V_42;
V_2 -> V_36 = F_23 ( V_31 , sizeof( T_1 ) , V_41 ) ;
if ( ! V_2 -> V_36 )
goto V_42;
V_2 -> V_37 = F_23 ( V_31 , sizeof( int ) , V_41 ) ;
if ( ! V_2 -> V_37 )
goto V_42;
V_2 -> V_14 = F_23 ( V_31 * V_15 ,
sizeof( struct V_16 ) , V_41 ) ;
if ( ! V_2 -> V_14 )
goto V_42;
F_24 ( L_2 ) ;
if ( V_2 -> V_8 -> V_44 )
F_24 ( L_3 ) ;
else
F_24 ( L_4 ) ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
F_25 ( & V_2 -> V_35 [ V_29 ] ) ;
F_26 ( & V_2 -> V_27 [ V_29 ] , 0 ) ;
F_26 ( & V_2 -> V_33 [ V_29 ] , 0 ) ;
}
V_2 -> V_30 = 0 ;
return 0 ;
V_42:
F_16 ( V_2 ) ;
return V_38 ;
}
static void F_27 ( void * V_45 , bool V_46 )
{
struct V_1 * V_2 = V_45 ;
if ( V_2 -> V_8 -> V_47 ) {
V_2 -> V_8 -> V_47 ( V_2 , V_46 ) ;
return;
}
if ( ! V_2 -> V_48 )
return;
if ( V_46 ) {
if ( V_2 -> V_8 -> V_49 )
V_2 -> V_8 -> V_49 ( V_2 ) ;
} else {
if ( V_2 -> V_8 -> V_50 )
V_2 -> V_8 -> V_50 ( V_2 ) ;
if ( V_2 -> V_8 -> V_51 )
V_2 -> V_8 -> V_51 ( V_2 ) ;
}
}
int F_28 ( struct V_1 * V_2 )
{
int V_38 ;
unsigned long V_52 = 0 ;
char * V_53 ;
if ( ! F_2 ( V_2 , V_12 ) )
return - V_11 ;
if ( F_29 ( V_2 ) == 0 )
return - V_11 ;
F_30 ( & V_2 -> V_54 ) ;
if ( ! V_2 -> V_55 ) {
F_31 ( & V_2 -> V_54 ) ;
return - V_11 ;
}
if ( V_2 -> V_48 ) {
F_31 ( & V_2 -> V_54 ) ;
return - V_56 ;
}
V_2 -> V_48 = 1 ;
F_31 ( & V_2 -> V_54 ) ;
F_15 ( L_5 , F_29 ( V_2 ) ) ;
if ( V_2 -> V_8 -> V_50 )
V_2 -> V_8 -> V_50 ( V_2 ) ;
if ( F_2 ( V_2 , V_57 ) )
V_52 = V_58 ;
if ( V_2 -> V_59 )
V_53 = V_2 -> V_59 ;
else
V_53 = V_2 -> V_8 -> V_60 ;
V_38 = F_32 ( F_29 ( V_2 ) , V_2 -> V_8 -> V_61 ,
V_52 , V_53 , V_2 ) ;
if ( V_38 < 0 ) {
F_30 ( & V_2 -> V_54 ) ;
V_2 -> V_48 = 0 ;
F_31 ( & V_2 -> V_54 ) ;
return V_38 ;
}
if ( ! F_2 ( V_2 , V_62 ) )
F_33 ( V_2 -> V_63 , ( void * ) V_2 , F_27 , NULL ) ;
if ( V_2 -> V_8 -> V_51 )
V_38 = V_2 -> V_8 -> V_51 ( V_2 ) ;
if ( V_38 < 0 ) {
F_30 ( & V_2 -> V_54 ) ;
V_2 -> V_48 = 0 ;
F_31 ( & V_2 -> V_54 ) ;
if ( ! F_2 ( V_2 , V_62 ) )
F_33 ( V_2 -> V_63 , NULL , NULL , NULL ) ;
F_34 ( F_29 ( V_2 ) , V_2 ) ;
}
return V_38 ;
}
int F_35 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
int V_48 , V_29 ;
if ( ! F_2 ( V_2 , V_12 ) )
return - V_11 ;
F_30 ( & V_2 -> V_54 ) ;
V_48 = V_2 -> V_48 ;
V_2 -> V_48 = 0 ;
F_31 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_31 ) {
F_5 ( & V_2 -> V_32 , V_17 ) ;
for ( V_29 = 0 ; V_29 < V_2 -> V_31 ; V_29 ++ ) {
F_36 ( & V_2 -> V_35 [ V_29 ] ) ;
V_2 -> V_24 [ V_29 ] = 0 ;
V_2 -> V_25 [ V_29 ] =
V_2 -> V_8 -> V_26 ( V_2 , V_29 ) ;
}
F_13 ( & V_2 -> V_32 , V_17 ) ;
}
if ( ! V_48 )
return - V_11 ;
F_15 ( L_5 , F_29 ( V_2 ) ) ;
if ( ! F_2 ( V_2 , V_62 ) )
F_33 ( V_2 -> V_63 , NULL , NULL , NULL ) ;
if ( V_2 -> V_8 -> V_49 )
V_2 -> V_8 -> V_49 ( V_2 ) ;
F_34 ( F_29 ( V_2 ) , V_2 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_37 * V_64 = V_3 ;
switch ( V_64 -> V_65 ) {
case V_66 :
if ( ! F_2 ( V_2 , V_12 ) )
return 0 ;
if ( F_2 ( V_2 , V_62 ) )
return 0 ;
if ( V_2 -> V_67 < F_38 ( 1 , 2 ) &&
V_64 -> V_68 != F_29 ( V_2 ) )
return - V_11 ;
return F_28 ( V_2 ) ;
case V_69 :
if ( ! F_2 ( V_2 , V_12 ) )
return 0 ;
if ( F_2 ( V_2 , V_62 ) )
return 0 ;
return F_35 ( V_2 ) ;
default:
return - V_11 ;
}
}
void F_39 ( struct V_70 * V_13 )
{
T_2 V_71 = 0 , V_72 = 0 , V_73 = 0 ;
T_3 V_74 ;
V_74 = ( T_3 ) V_13 -> V_75 . clock * 1000 ;
if ( V_13 -> V_75 . V_76 & V_77 )
V_74 *= 2 ;
if ( V_74 > 0 ) {
V_72 = ( T_2 ) F_40 ( 1000000000 , V_74 ) ;
V_71 = ( T_2 ) F_40 ( ( ( T_3 ) V_13 -> V_75 . V_78 *
1000000000 ) , V_74 ) ;
V_73 = ( T_2 ) V_13 -> V_75 . V_79 * V_71 ;
} else
F_41 ( L_6 ,
V_13 -> V_80 . V_81 ) ;
V_13 -> V_72 = V_72 ;
V_13 -> V_71 = V_71 ;
V_13 -> V_73 = V_73 ;
F_15 ( L_7 ,
V_13 -> V_80 . V_81 , V_13 -> V_75 . V_78 ,
V_13 -> V_75 . V_79 , V_13 -> V_75 . V_82 ) ;
F_15 ( L_8 ,
V_13 -> V_80 . V_81 , ( int ) V_74 / 1000 , ( int ) V_73 ,
( int ) V_71 , ( int ) V_72 ) ;
}
int F_42 ( struct V_1 * V_2 , int V_13 ,
int * V_83 ,
struct V_16 * V_84 ,
unsigned V_76 ,
struct V_70 * V_85 )
{
struct V_16 V_86 , V_87 ;
struct V_88 * V_89 ;
int V_90 , V_91 , V_92 ;
int V_93 , V_94 , V_29 ;
T_2 V_73 , V_71 , V_72 , V_95 , V_96 ;
bool V_97 ;
if ( V_13 < 0 || V_13 >= V_2 -> V_31 ) {
F_41 ( L_9 , V_13 ) ;
return - V_11 ;
}
if ( ! V_2 -> V_8 -> V_98 ) {
F_41 ( L_10 ) ;
return - V_99 ;
}
V_89 = & V_85 -> V_75 ;
V_91 = V_89 -> V_79 ;
V_92 = V_89 -> V_82 ;
V_73 = V_85 -> V_73 ;
V_71 = V_85 -> V_71 ;
V_72 = V_85 -> V_72 ;
if ( V_91 <= 0 || V_92 <= 0 || V_73 == 0 ) {
F_15 ( L_11 , V_13 ) ;
return - V_100 ;
}
for ( V_29 = 0 ; V_29 < V_101 ; V_29 ++ ) {
F_43 () ;
F_44 ( & V_86 ) ;
V_90 = V_2 -> V_8 -> V_98 ( V_2 , V_13 , & V_93 , & V_94 ) ;
F_44 ( & V_87 ) ;
F_45 () ;
if ( ! ( V_90 & V_102 ) ) {
F_15 ( L_12 ,
V_13 , V_90 ) ;
return - V_99 ;
}
V_96 = F_8 ( & V_87 ) - F_8 ( & V_86 ) ;
if ( V_96 <= ( T_2 ) * V_83 )
break;
}
if ( V_29 == V_101 ) {
F_15 ( L_13 ,
V_13 , ( int ) V_96 / 1000 , * V_83 / 1000 , V_29 ) ;
}
* V_83 = ( int ) V_96 ;
V_97 = V_90 & V_103 ;
V_95 = ( T_2 ) V_93 * V_71 + ( T_2 ) V_94 * V_72 ;
if ( ( V_76 & V_104 ) && ! V_97 &&
( ( V_92 - V_93 ) < V_91 / 100 ) ) {
V_95 = V_95 - V_73 ;
V_90 |= 0x8 ;
}
* V_84 = F_46 ( F_8 ( & V_87 ) - V_95 ) ;
F_15 ( L_14 ,
V_13 , ( int ) V_90 , V_94 , V_93 ,
( long ) V_87 . V_105 , ( long ) V_87 . V_106 ,
( long ) V_84 -> V_105 , ( long ) V_84 -> V_106 ,
( int ) V_96 / 1000 , V_29 ) ;
V_90 = V_107 ;
if ( V_97 )
V_90 |= V_108 ;
return V_90 ;
}
T_1 F_6 ( struct V_1 * V_2 , int V_13 ,
struct V_16 * V_21 , unsigned V_76 )
{
int V_38 ;
int V_83 = ( int ) V_109 * 1000 ;
if ( V_2 -> V_8 -> V_44 && ( V_83 > 0 ) ) {
V_38 = V_2 -> V_8 -> V_44 ( V_2 , V_13 , & V_83 ,
V_21 , V_76 ) ;
if ( V_38 > 0 )
return ( T_1 ) V_38 ;
}
F_44 ( V_21 ) ;
return 0 ;
}
T_1 F_47 ( struct V_1 * V_2 , int V_13 )
{
return F_7 ( & V_2 -> V_27 [ V_13 ] ) ;
}
T_1 F_48 ( struct V_1 * V_2 , int V_13 ,
struct V_16 * V_110 )
{
T_1 V_111 ;
do {
V_111 = F_7 ( & V_2 -> V_27 [ V_13 ] ) ;
* V_110 = F_9 ( V_2 , V_13 , V_111 ) ;
F_49 () ;
} while ( V_111 != F_7 ( & V_2 -> V_27 [ V_13 ] ) );
return V_111 ;
}
static void F_50 ( struct V_1 * V_2 , int V_13 )
{
T_1 V_111 , V_112 , V_113 , V_114 ;
struct V_16 V_115 ;
do {
V_111 = V_2 -> V_8 -> V_26 ( V_2 , V_13 ) ;
V_114 = F_6 ( V_2 , V_13 , & V_115 , 0 ) ;
} while ( V_111 != V_2 -> V_8 -> V_26 ( V_2 , V_13 ) );
V_112 = V_111 - V_2 -> V_25 [ V_13 ] ;
if ( V_111 < V_2 -> V_25 [ V_13 ] ) {
V_112 += V_2 -> V_116 ;
F_15 ( L_15 ,
V_13 , V_2 -> V_25 [ V_13 ] , V_111 , V_112 ) ;
}
F_15 ( L_16 ,
V_13 , V_112 ) ;
if ( V_114 ) {
V_113 = F_7 ( & V_2 -> V_27 [ V_13 ] ) + V_112 ;
F_9 ( V_2 , V_13 , V_113 ) = V_115 ;
}
F_51 () ;
F_52 ( V_112 , & V_2 -> V_27 [ V_13 ] ) ;
F_12 () ;
}
int F_53 ( struct V_1 * V_2 , int V_13 )
{
unsigned long V_17 , V_117 ;
int V_38 = 0 ;
F_5 ( & V_2 -> V_32 , V_17 ) ;
if ( F_54 ( 1 , & V_2 -> V_33 [ V_13 ] ) == 1 ) {
F_5 ( & V_2 -> V_22 , V_117 ) ;
if ( ! V_2 -> V_24 [ V_13 ] ) {
V_38 = V_2 -> V_8 -> V_118 ( V_2 , V_13 ) ;
F_15 ( L_17 ,
V_13 , V_38 ) ;
if ( V_38 )
F_55 ( & V_2 -> V_33 [ V_13 ] ) ;
else {
V_2 -> V_24 [ V_13 ] = 1 ;
F_50 ( V_2 , V_13 ) ;
}
}
F_13 ( & V_2 -> V_22 , V_117 ) ;
} else {
if ( ! V_2 -> V_24 [ V_13 ] ) {
F_55 ( & V_2 -> V_33 [ V_13 ] ) ;
V_38 = - V_11 ;
}
}
F_13 ( & V_2 -> V_32 , V_17 ) ;
return V_38 ;
}
void F_56 ( struct V_1 * V_2 , int V_13 )
{
F_57 ( F_7 ( & V_2 -> V_33 [ V_13 ] ) == 0 ) ;
if ( F_58 ( & V_2 -> V_33 [ V_13 ] ) &&
( V_119 > 0 ) )
F_59 ( & V_2 -> V_34 ,
V_120 + ( ( V_119 * V_121 ) / 1000 ) ) ;
}
void F_60 ( struct V_1 * V_2 , int V_13 )
{
struct V_122 * V_123 , * V_124 ;
struct V_16 V_125 ;
unsigned long V_17 ;
unsigned int V_126 ;
F_5 ( & V_2 -> V_32 , V_17 ) ;
F_4 ( V_2 , V_13 ) ;
F_36 ( & V_2 -> V_35 [ V_13 ] ) ;
V_126 = F_48 ( V_2 , V_13 , & V_125 ) ;
F_61 (e, t, &dev->vblank_event_list, base.link) {
if ( V_123 -> V_127 != V_13 )
continue;
F_15 ( L_18 ,
V_123 -> V_128 . V_129 , V_126 ) ;
V_123 -> V_128 . V_129 = V_126 ;
V_123 -> V_128 . V_105 = V_125 . V_105 ;
V_123 -> V_128 . V_106 = V_125 . V_106 ;
F_56 ( V_2 , V_123 -> V_127 ) ;
F_62 ( & V_123 -> V_80 . V_130 , & V_123 -> V_80 . V_5 -> V_131 ) ;
F_63 ( & V_123 -> V_80 . V_5 -> V_132 ) ;
F_64 ( V_123 -> V_80 . V_133 , V_123 -> V_127 ,
V_123 -> V_128 . V_129 ) ;
}
F_13 ( & V_2 -> V_32 , V_17 ) ;
}
void F_65 ( struct V_1 * V_2 , int V_13 )
{
if ( ! V_2 -> V_31 )
return;
if ( ! V_2 -> V_37 [ V_13 ] ) {
V_2 -> V_37 [ V_13 ] = 0x1 ;
if ( F_53 ( V_2 , V_13 ) == 0 )
V_2 -> V_37 [ V_13 ] |= 0x2 ;
}
}
void F_66 ( struct V_1 * V_2 , int V_13 )
{
unsigned long V_17 ;
if ( V_2 -> V_37 [ V_13 ] ) {
F_5 ( & V_2 -> V_32 , V_17 ) ;
V_2 -> V_30 = 1 ;
F_13 ( & V_2 -> V_32 , V_17 ) ;
if ( V_2 -> V_37 [ V_13 ] & 0x2 )
F_56 ( V_2 , V_13 ) ;
V_2 -> V_37 [ V_13 ] = 0 ;
}
}
int F_67 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_67 * V_134 = V_3 ;
unsigned int V_13 ;
if ( ! V_2 -> V_31 )
return 0 ;
if ( F_2 ( V_2 , V_62 ) )
return 0 ;
V_13 = V_134 -> V_13 ;
if ( V_13 >= V_2 -> V_31 )
return - V_11 ;
switch ( V_134 -> V_135 ) {
case V_136 :
F_65 ( V_2 , V_13 ) ;
break;
case V_137 :
F_66 ( V_2 , V_13 ) ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , int V_127 ,
union V_138 * V_139 ,
struct V_4 * V_5 )
{
struct V_122 * V_123 ;
struct V_16 V_125 ;
unsigned long V_76 ;
unsigned int V_126 ;
int V_38 ;
V_123 = F_69 ( sizeof *V_123 , V_41 ) ;
if ( V_123 == NULL ) {
V_38 = - V_39 ;
goto V_140;
}
V_123 -> V_127 = V_127 ;
V_123 -> V_80 . V_133 = V_141 -> V_133 ;
V_123 -> V_128 . V_80 . type = V_142 ;
V_123 -> V_128 . V_80 . V_143 = sizeof V_123 -> V_128 ;
V_123 -> V_128 . V_144 = V_139 -> V_145 . signal ;
V_123 -> V_80 . V_128 = & V_123 -> V_128 . V_80 ;
V_123 -> V_80 . V_5 = V_5 ;
V_123 -> V_80 . V_146 = ( void ( * ) ( struct V_147 * ) ) F_18 ;
F_5 ( & V_2 -> V_148 , V_76 ) ;
if ( V_5 -> V_149 < sizeof V_123 -> V_128 ) {
V_38 = - V_56 ;
goto V_150;
}
V_5 -> V_149 -= sizeof V_123 -> V_128 ;
V_126 = F_48 ( V_2 , V_127 , & V_125 ) ;
if ( ( V_139 -> V_145 . type & V_151 ) &&
( V_126 - V_139 -> V_145 . V_129 ) <= ( 1 << 23 ) ) {
V_139 -> V_145 . V_129 = V_126 + 1 ;
V_139 -> V_152 . V_129 = V_139 -> V_145 . V_129 ;
}
F_15 ( L_19 ,
V_139 -> V_145 . V_129 , V_126 , V_127 ) ;
F_70 ( V_141 -> V_133 , V_127 ,
V_139 -> V_145 . V_129 ) ;
V_123 -> V_128 . V_129 = V_139 -> V_145 . V_129 ;
if ( ( V_126 - V_139 -> V_145 . V_129 ) <= ( 1 << 23 ) ) {
V_123 -> V_128 . V_129 = V_126 ;
V_123 -> V_128 . V_105 = V_125 . V_105 ;
V_123 -> V_128 . V_106 = V_125 . V_106 ;
F_56 ( V_2 , V_127 ) ;
F_71 ( & V_123 -> V_80 . V_130 , & V_123 -> V_80 . V_5 -> V_131 ) ;
F_63 ( & V_123 -> V_80 . V_5 -> V_132 ) ;
V_139 -> V_152 . V_129 = V_126 ;
F_64 ( V_141 -> V_133 , V_127 ,
V_139 -> V_145 . V_129 ) ;
} else {
F_71 ( & V_123 -> V_80 . V_130 , & V_2 -> V_153 ) ;
V_139 -> V_152 . V_129 = V_139 -> V_145 . V_129 ;
}
F_13 ( & V_2 -> V_148 , V_76 ) ;
return 0 ;
V_150:
F_13 ( & V_2 -> V_148 , V_76 ) ;
F_18 ( V_123 ) ;
V_140:
F_56 ( V_2 , V_127 ) ;
return V_38 ;
}
int V_138 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
union V_138 * V_139 = V_3 ;
int V_38 ;
unsigned int V_76 , V_126 , V_13 , V_154 ;
if ( ( ! F_29 ( V_2 ) ) || ( ! V_2 -> V_48 ) )
return - V_11 ;
if ( V_139 -> V_145 . type & V_155 )
return - V_11 ;
if ( V_139 -> V_145 . type &
~ ( V_156 | V_157 |
V_158 ) ) {
F_41 ( L_20 ,
V_139 -> V_145 . type ,
( V_156 | V_157 |
V_158 ) ) ;
return - V_11 ;
}
V_76 = V_139 -> V_145 . type & V_157 ;
V_154 = ( V_139 -> V_145 . type & V_158 ) ;
if ( V_154 )
V_13 = V_154 >> V_159 ;
else
V_13 = V_76 & V_160 ? 1 : 0 ;
if ( V_13 >= V_2 -> V_31 )
return - V_11 ;
V_38 = F_53 ( V_2 , V_13 ) ;
if ( V_38 ) {
F_15 ( L_21 , V_38 ) ;
return V_38 ;
}
V_126 = F_47 ( V_2 , V_13 ) ;
switch ( V_139 -> V_145 . type & V_156 ) {
case V_161 :
V_139 -> V_145 . V_129 += V_126 ;
V_139 -> V_145 . type &= ~ V_161 ;
case V_162 :
break;
default:
V_38 = - V_11 ;
goto V_163;
}
if ( V_76 & V_164 ) {
return F_68 ( V_2 , V_13 , V_139 , V_5 ) ;
}
if ( ( V_76 & V_151 ) &&
( V_126 - V_139 -> V_145 . V_129 ) <= ( 1 << 23 ) ) {
V_139 -> V_145 . V_129 = V_126 + 1 ;
}
F_15 ( L_22 ,
V_139 -> V_145 . V_129 , V_13 ) ;
V_2 -> V_36 [ V_13 ] = V_139 -> V_145 . V_129 ;
F_72 ( V_38 , V_2 -> V_35 [ V_13 ] , 3 * V_121 ,
( ( ( F_47 ( V_2 , V_13 ) -
V_139 -> V_145 . V_129 ) <= ( 1 << 23 ) ) ||
! V_2 -> V_48 ) ) ;
if ( V_38 != - V_165 ) {
struct V_16 V_125 ;
V_139 -> V_152 . V_129 = F_48 ( V_2 , V_13 , & V_125 ) ;
V_139 -> V_152 . V_166 = V_125 . V_105 ;
V_139 -> V_152 . V_167 = V_125 . V_106 ;
F_15 ( L_23 ,
V_139 -> V_152 . V_129 ) ;
} else {
F_15 ( L_24 ) ;
}
V_163:
F_56 ( V_2 , V_13 ) ;
return V_38 ;
}
void F_73 ( struct V_1 * V_2 , int V_13 )
{
struct V_122 * V_123 , * V_124 ;
struct V_16 V_125 ;
unsigned long V_76 ;
unsigned int V_126 ;
V_126 = F_48 ( V_2 , V_13 , & V_125 ) ;
F_5 ( & V_2 -> V_148 , V_76 ) ;
F_61 (e, t, &dev->vblank_event_list, base.link) {
if ( V_123 -> V_127 != V_13 )
continue;
if ( ( V_126 - V_123 -> V_128 . V_129 ) > ( 1 << 23 ) )
continue;
F_15 ( L_25 ,
V_123 -> V_128 . V_129 , V_126 ) ;
V_123 -> V_128 . V_129 = V_126 ;
V_123 -> V_128 . V_105 = V_125 . V_105 ;
V_123 -> V_128 . V_106 = V_125 . V_106 ;
F_56 ( V_2 , V_123 -> V_127 ) ;
F_62 ( & V_123 -> V_80 . V_130 , & V_123 -> V_80 . V_5 -> V_131 ) ;
F_63 ( & V_123 -> V_80 . V_5 -> V_132 ) ;
F_64 ( V_123 -> V_80 . V_133 , V_123 -> V_127 ,
V_123 -> V_128 . V_129 ) ;
}
F_13 ( & V_2 -> V_148 , V_76 ) ;
F_74 ( V_13 , V_126 ) ;
}
bool F_75 ( struct V_1 * V_2 , int V_13 )
{
T_1 V_18 ;
T_2 V_19 ;
struct V_16 V_21 ;
unsigned long V_17 ;
if ( ! V_2 -> V_31 )
return false ;
F_5 ( & V_2 -> V_22 , V_17 ) ;
if ( ! V_2 -> V_24 [ V_13 ] ) {
F_13 ( & V_2 -> V_22 , V_17 ) ;
return false ;
}
V_18 = F_7 ( & V_2 -> V_27 [ V_13 ] ) ;
F_6 ( V_2 , V_13 , & V_21 , V_104 ) ;
V_19 = F_8 ( & V_21 ) -
F_8 ( & F_9 ( V_2 , V_13 , V_18 ) ) ;
if ( F_10 ( V_19 ) > V_168 ) {
F_9 ( V_2 , V_13 , V_18 + 1 ) = V_21 ;
F_51 () ;
F_11 ( & V_2 -> V_27 [ V_13 ] ) ;
F_12 () ;
} else {
F_15 ( L_26 ,
V_13 , ( int ) V_19 ) ;
}
F_36 ( & V_2 -> V_35 [ V_13 ] ) ;
F_73 ( V_2 , V_13 ) ;
F_13 ( & V_2 -> V_22 , V_17 ) ;
return true ;
}
