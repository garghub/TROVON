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
int V_22 = V_23 ;
F_5 ( & V_2 -> V_24 , V_17 ) ;
V_2 -> V_8 -> V_25 ( V_2 , V_13 ) ;
V_2 -> V_26 [ V_13 ] = 0 ;
do {
V_2 -> V_27 [ V_13 ] = V_2 -> V_8 -> V_28 ( V_2 , V_13 ) ;
V_20 = F_6 ( V_2 , V_13 , & V_21 , 0 ) ;
} while ( V_2 -> V_27 [ V_13 ] != V_2 -> V_8 -> V_28 ( V_2 , V_13 ) && ( -- V_22 ) && V_20 );
if ( ! V_22 )
V_20 = 0 ;
V_18 = F_7 ( & V_2 -> V_29 [ V_13 ] ) ;
V_19 = F_8 ( & V_21 ) -
F_8 ( & F_9 ( V_2 , V_13 , V_18 ) ) ;
if ( ( V_20 > 0 ) && ( F_10 ( V_19 ) > 1000000 ) ) {
F_11 ( & V_2 -> V_29 [ V_13 ] ) ;
F_12 () ;
}
F_3 ( V_2 , V_13 ) ;
F_13 ( & V_2 -> V_24 , V_17 ) ;
}
static void F_14 ( unsigned long V_30 )
{
struct V_1 * V_2 = (struct V_1 * ) V_30 ;
unsigned long V_17 ;
int V_31 ;
if ( ! V_2 -> V_32 )
return;
for ( V_31 = 0 ; V_31 < V_2 -> V_33 ; V_31 ++ ) {
F_5 ( & V_2 -> V_34 , V_17 ) ;
if ( F_7 ( & V_2 -> V_35 [ V_31 ] ) == 0 &&
V_2 -> V_26 [ V_31 ] ) {
F_15 ( L_1 , V_31 ) ;
F_4 ( V_2 , V_31 ) ;
}
F_13 ( & V_2 -> V_34 , V_17 ) ;
}
}
void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_33 == 0 )
return;
F_17 ( & V_2 -> V_36 ) ;
F_14 ( ( unsigned long ) V_2 ) ;
F_18 ( V_2 -> V_37 ) ;
F_18 ( V_2 -> V_29 ) ;
F_18 ( V_2 -> V_35 ) ;
F_18 ( V_2 -> V_26 ) ;
F_18 ( V_2 -> V_27 ) ;
F_18 ( V_2 -> V_38 ) ;
F_18 ( V_2 -> V_39 ) ;
F_18 ( V_2 -> V_14 ) ;
V_2 -> V_33 = 0 ;
}
int F_19 ( struct V_1 * V_2 , int V_33 )
{
int V_31 , V_40 = - V_41 ;
F_20 ( & V_2 -> V_36 , F_14 ,
( unsigned long ) V_2 ) ;
F_21 ( & V_2 -> V_34 ) ;
F_21 ( & V_2 -> V_24 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_37 = F_22 ( sizeof( V_42 ) * V_33 ,
V_43 ) ;
if ( ! V_2 -> V_37 )
goto V_44;
V_2 -> V_29 = F_22 ( sizeof( V_45 ) * V_33 , V_43 ) ;
if ( ! V_2 -> V_29 )
goto V_44;
V_2 -> V_35 = F_22 ( sizeof( V_45 ) * V_33 ,
V_43 ) ;
if ( ! V_2 -> V_35 )
goto V_44;
V_2 -> V_26 = F_23 ( V_33 , sizeof( int ) , V_43 ) ;
if ( ! V_2 -> V_26 )
goto V_44;
V_2 -> V_27 = F_23 ( V_33 , sizeof( T_1 ) , V_43 ) ;
if ( ! V_2 -> V_27 )
goto V_44;
V_2 -> V_38 = F_23 ( V_33 , sizeof( T_1 ) , V_43 ) ;
if ( ! V_2 -> V_38 )
goto V_44;
V_2 -> V_39 = F_23 ( V_33 , sizeof( int ) , V_43 ) ;
if ( ! V_2 -> V_39 )
goto V_44;
V_2 -> V_14 = F_23 ( V_33 * V_15 ,
sizeof( struct V_16 ) , V_43 ) ;
if ( ! V_2 -> V_14 )
goto V_44;
F_24 ( L_2 ) ;
if ( V_2 -> V_8 -> V_46 )
F_24 ( L_3 ) ;
else
F_24 ( L_4 ) ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
F_25 ( & V_2 -> V_37 [ V_31 ] ) ;
F_26 ( & V_2 -> V_29 [ V_31 ] , 0 ) ;
F_26 ( & V_2 -> V_35 [ V_31 ] , 0 ) ;
}
V_2 -> V_32 = 0 ;
return 0 ;
V_44:
F_16 ( V_2 ) ;
return V_40 ;
}
static void F_27 ( void * V_47 , bool V_48 )
{
struct V_1 * V_2 = V_47 ;
if ( V_2 -> V_8 -> V_49 ) {
V_2 -> V_8 -> V_49 ( V_2 , V_48 ) ;
return;
}
if ( ! V_2 -> V_50 )
return;
if ( V_48 ) {
if ( V_2 -> V_8 -> V_51 )
V_2 -> V_8 -> V_51 ( V_2 ) ;
} else {
if ( V_2 -> V_8 -> V_52 )
V_2 -> V_8 -> V_52 ( V_2 ) ;
if ( V_2 -> V_8 -> V_53 )
V_2 -> V_8 -> V_53 ( V_2 ) ;
}
}
int F_28 ( struct V_1 * V_2 )
{
int V_40 ;
unsigned long V_54 = 0 ;
char * V_55 ;
if ( ! F_2 ( V_2 , V_12 ) )
return - V_11 ;
if ( F_29 ( V_2 ) == 0 )
return - V_11 ;
F_30 ( & V_2 -> V_56 ) ;
if ( ! V_2 -> V_57 ) {
F_31 ( & V_2 -> V_56 ) ;
return - V_11 ;
}
if ( V_2 -> V_50 ) {
F_31 ( & V_2 -> V_56 ) ;
return - V_58 ;
}
V_2 -> V_50 = 1 ;
F_31 ( & V_2 -> V_56 ) ;
F_15 ( L_5 , F_29 ( V_2 ) ) ;
if ( V_2 -> V_8 -> V_52 )
V_2 -> V_8 -> V_52 ( V_2 ) ;
if ( F_2 ( V_2 , V_59 ) )
V_54 = V_60 ;
if ( V_2 -> V_61 )
V_55 = V_2 -> V_61 ;
else
V_55 = V_2 -> V_8 -> V_62 ;
V_40 = F_32 ( F_29 ( V_2 ) , V_2 -> V_8 -> V_63 ,
V_54 , V_55 , V_2 ) ;
if ( V_40 < 0 ) {
F_30 ( & V_2 -> V_56 ) ;
V_2 -> V_50 = 0 ;
F_31 ( & V_2 -> V_56 ) ;
return V_40 ;
}
if ( ! F_2 ( V_2 , V_64 ) )
F_33 ( V_2 -> V_65 , ( void * ) V_2 , F_27 , NULL ) ;
if ( V_2 -> V_8 -> V_53 )
V_40 = V_2 -> V_8 -> V_53 ( V_2 ) ;
if ( V_40 < 0 ) {
F_30 ( & V_2 -> V_56 ) ;
V_2 -> V_50 = 0 ;
F_31 ( & V_2 -> V_56 ) ;
if ( ! F_2 ( V_2 , V_64 ) )
F_33 ( V_2 -> V_65 , NULL , NULL , NULL ) ;
F_34 ( F_29 ( V_2 ) , V_2 ) ;
}
return V_40 ;
}
int F_35 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
int V_50 , V_31 ;
if ( ! F_2 ( V_2 , V_12 ) )
return - V_11 ;
F_30 ( & V_2 -> V_56 ) ;
V_50 = V_2 -> V_50 ;
V_2 -> V_50 = 0 ;
F_31 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_33 ) {
F_5 ( & V_2 -> V_34 , V_17 ) ;
for ( V_31 = 0 ; V_31 < V_2 -> V_33 ; V_31 ++ ) {
F_36 ( & V_2 -> V_37 [ V_31 ] ) ;
V_2 -> V_26 [ V_31 ] = 0 ;
V_2 -> V_27 [ V_31 ] =
V_2 -> V_8 -> V_28 ( V_2 , V_31 ) ;
}
F_13 ( & V_2 -> V_34 , V_17 ) ;
}
if ( ! V_50 )
return - V_11 ;
F_15 ( L_5 , F_29 ( V_2 ) ) ;
if ( ! F_2 ( V_2 , V_64 ) )
F_33 ( V_2 -> V_65 , NULL , NULL , NULL ) ;
if ( V_2 -> V_8 -> V_51 )
V_2 -> V_8 -> V_51 ( V_2 ) ;
F_34 ( F_29 ( V_2 ) , V_2 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_37 * V_66 = V_3 ;
switch ( V_66 -> V_67 ) {
case V_68 :
if ( ! F_2 ( V_2 , V_12 ) )
return 0 ;
if ( F_2 ( V_2 , V_64 ) )
return 0 ;
if ( V_2 -> V_69 < F_38 ( 1 , 2 ) &&
V_66 -> V_70 != F_29 ( V_2 ) )
return - V_11 ;
return F_28 ( V_2 ) ;
case V_71 :
if ( ! F_2 ( V_2 , V_12 ) )
return 0 ;
if ( F_2 ( V_2 , V_64 ) )
return 0 ;
return F_35 ( V_2 ) ;
default:
return - V_11 ;
}
}
void F_39 ( struct V_72 * V_13 )
{
T_2 V_73 = 0 , V_74 = 0 , V_75 = 0 ;
T_3 V_76 ;
V_76 = ( T_3 ) V_13 -> V_77 . clock * 1000 ;
if ( V_13 -> V_77 . V_78 & V_79 )
V_76 *= 2 ;
if ( V_76 > 0 ) {
int V_80 ;
V_74 = ( T_2 ) F_40 ( 1000000000 , V_76 ) ;
V_73 = ( T_2 ) F_40 ( ( ( T_3 ) V_13 -> V_77 . V_81 *
1000000000 ) , V_76 ) ;
V_80 = V_13 -> V_77 . V_81 *
V_13 -> V_77 . V_82 ;
V_75 = ( T_2 ) F_40 ( ( T_3 ) V_80 * 1000000000 ,
V_76 ) ;
} else
F_41 ( L_6 ,
V_13 -> V_83 . V_84 ) ;
V_13 -> V_74 = V_74 ;
V_13 -> V_73 = V_73 ;
V_13 -> V_75 = V_75 ;
F_15 ( L_7 ,
V_13 -> V_83 . V_84 , V_13 -> V_77 . V_81 ,
V_13 -> V_77 . V_82 , V_13 -> V_77 . V_85 ) ;
F_15 ( L_8 ,
V_13 -> V_83 . V_84 , ( int ) V_76 / 1000 , ( int ) V_75 ,
( int ) V_73 , ( int ) V_74 ) ;
}
int F_42 ( struct V_1 * V_2 , int V_13 ,
int * V_86 ,
struct V_16 * V_87 ,
unsigned V_78 ,
struct V_72 * V_88 )
{
T_4 V_89 , V_90 , V_91 ;
struct V_16 V_92 ;
struct V_93 * V_94 ;
int V_95 , V_96 , V_97 ;
int V_98 , V_99 , V_31 ;
T_2 V_75 , V_73 , V_74 , V_100 , V_101 ;
bool V_102 ;
if ( V_13 < 0 || V_13 >= V_2 -> V_33 ) {
F_41 ( L_9 , V_13 ) ;
return - V_11 ;
}
if ( ! V_2 -> V_8 -> V_103 ) {
F_41 ( L_10 ) ;
return - V_104 ;
}
V_94 = & V_88 -> V_77 ;
V_96 = V_94 -> V_82 ;
V_97 = V_94 -> V_85 ;
V_75 = V_88 -> V_75 ;
V_73 = V_88 -> V_73 ;
V_74 = V_88 -> V_74 ;
if ( V_96 <= 0 || V_97 <= 0 || V_75 == 0 ) {
F_15 ( L_11 , V_13 ) ;
return - V_105 ;
}
for ( V_31 = 0 ; V_31 < V_23 ; V_31 ++ ) {
F_43 () ;
V_89 = F_44 () ;
V_95 = V_2 -> V_8 -> V_103 ( V_2 , V_13 , & V_98 , & V_99 ) ;
V_90 = F_44 () ;
if ( ! V_106 )
V_91 = F_45 () ;
F_46 () ;
if ( ! ( V_95 & V_107 ) ) {
F_15 ( L_12 ,
V_13 , V_95 ) ;
return - V_104 ;
}
V_101 = F_47 ( V_90 ) - F_47 ( V_89 ) ;
if ( V_101 <= ( T_2 ) * V_86 )
break;
}
if ( V_31 == V_23 ) {
F_15 ( L_13 ,
V_13 , ( int ) V_101 / 1000 , * V_86 / 1000 , V_31 ) ;
}
* V_86 = ( int ) V_101 ;
V_102 = V_95 & V_108 ;
V_100 = ( T_2 ) V_98 * V_73 + ( T_2 ) V_99 * V_74 ;
if ( ( V_78 & V_109 ) && ! V_102 &&
( ( V_97 - V_98 ) < V_96 / 100 ) ) {
V_100 = V_100 - V_75 ;
V_95 |= 0x8 ;
}
if ( ! V_106 )
V_90 = F_48 ( V_90 , V_91 ) ;
V_92 = F_49 ( V_90 ) ;
V_90 = F_50 ( V_90 , V_100 ) ;
* V_87 = F_49 ( V_90 ) ;
F_15 ( L_14 ,
V_13 , ( int ) V_95 , V_99 , V_98 ,
( long ) V_92 . V_110 , ( long ) V_92 . V_111 ,
( long ) V_87 -> V_110 , ( long ) V_87 -> V_111 ,
( int ) V_101 / 1000 , V_31 ) ;
V_95 = V_112 ;
if ( V_102 )
V_95 |= V_113 ;
return V_95 ;
}
static struct V_16 F_51 ( void )
{
T_4 V_114 ;
V_114 = F_44 () ;
if ( ! V_106 )
V_114 = F_48 ( V_114 , F_45 () ) ;
return F_49 ( V_114 ) ;
}
T_1 F_6 ( struct V_1 * V_2 , int V_13 ,
struct V_16 * V_21 , unsigned V_78 )
{
int V_40 ;
int V_86 = ( int ) V_115 * 1000 ;
if ( V_2 -> V_8 -> V_46 && ( V_86 > 0 ) ) {
V_40 = V_2 -> V_8 -> V_46 ( V_2 , V_13 , & V_86 ,
V_21 , V_78 ) ;
if ( V_40 > 0 )
return ( T_1 ) V_40 ;
}
* V_21 = F_51 () ;
return 0 ;
}
T_1 F_52 ( struct V_1 * V_2 , int V_13 )
{
return F_7 ( & V_2 -> V_29 [ V_13 ] ) ;
}
T_1 F_53 ( struct V_1 * V_2 , int V_13 ,
struct V_16 * V_116 )
{
T_1 V_117 ;
do {
V_117 = F_7 ( & V_2 -> V_29 [ V_13 ] ) ;
* V_116 = F_9 ( V_2 , V_13 , V_117 ) ;
F_54 () ;
} while ( V_117 != F_7 ( & V_2 -> V_29 [ V_13 ] ) );
return V_117 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_118 * V_119 ,
unsigned long V_120 , struct V_16 * V_114 )
{
F_56 ( ! F_57 ( & V_2 -> V_121 ) ) ;
V_119 -> V_122 . V_123 = V_120 ;
V_119 -> V_122 . V_110 = V_114 -> V_110 ;
V_119 -> V_122 . V_111 = V_114 -> V_111 ;
F_58 ( & V_119 -> V_83 . V_124 ,
& V_119 -> V_83 . V_5 -> V_125 ) ;
F_59 ( & V_119 -> V_83 . V_5 -> V_126 ) ;
F_60 ( V_119 -> V_83 . V_127 , V_119 -> V_128 ,
V_119 -> V_122 . V_123 ) ;
}
void F_61 ( struct V_1 * V_2 , int V_13 ,
struct V_118 * V_119 )
{
struct V_16 V_114 ;
unsigned int V_120 ;
if ( V_13 >= 0 ) {
V_120 = F_53 ( V_2 , V_13 , & V_114 ) ;
} else {
V_120 = 0 ;
V_114 = F_51 () ;
}
V_119 -> V_128 = V_13 ;
F_55 ( V_2 , V_119 , V_120 , & V_114 ) ;
}
static void F_62 ( struct V_1 * V_2 , int V_13 )
{
T_1 V_117 , V_129 , V_130 , V_131 ;
struct V_16 V_132 ;
do {
V_117 = V_2 -> V_8 -> V_28 ( V_2 , V_13 ) ;
V_131 = F_6 ( V_2 , V_13 , & V_132 , 0 ) ;
} while ( V_117 != V_2 -> V_8 -> V_28 ( V_2 , V_13 ) );
V_129 = V_117 - V_2 -> V_27 [ V_13 ] ;
if ( V_117 < V_2 -> V_27 [ V_13 ] ) {
V_129 += V_2 -> V_133 ;
F_15 ( L_15 ,
V_13 , V_2 -> V_27 [ V_13 ] , V_117 , V_129 ) ;
}
F_15 ( L_16 ,
V_13 , V_129 ) ;
if ( V_131 ) {
V_130 = F_7 ( & V_2 -> V_29 [ V_13 ] ) + V_129 ;
F_9 ( V_2 , V_13 , V_130 ) = V_132 ;
}
F_63 () ;
F_64 ( V_129 , & V_2 -> V_29 [ V_13 ] ) ;
F_12 () ;
}
int F_65 ( struct V_1 * V_2 , int V_13 )
{
unsigned long V_17 , V_134 ;
int V_40 = 0 ;
F_5 ( & V_2 -> V_34 , V_17 ) ;
if ( F_66 ( 1 , & V_2 -> V_35 [ V_13 ] ) == 1 ) {
F_5 ( & V_2 -> V_24 , V_134 ) ;
if ( ! V_2 -> V_26 [ V_13 ] ) {
V_40 = V_2 -> V_8 -> V_135 ( V_2 , V_13 ) ;
F_15 ( L_17 ,
V_13 , V_40 ) ;
if ( V_40 )
F_67 ( & V_2 -> V_35 [ V_13 ] ) ;
else {
V_2 -> V_26 [ V_13 ] = 1 ;
F_62 ( V_2 , V_13 ) ;
}
}
F_13 ( & V_2 -> V_24 , V_134 ) ;
} else {
if ( ! V_2 -> V_26 [ V_13 ] ) {
F_67 ( & V_2 -> V_35 [ V_13 ] ) ;
V_40 = - V_11 ;
}
}
F_13 ( & V_2 -> V_34 , V_17 ) ;
return V_40 ;
}
void F_68 ( struct V_1 * V_2 , int V_13 )
{
F_69 ( F_7 ( & V_2 -> V_35 [ V_13 ] ) == 0 ) ;
if ( F_70 ( & V_2 -> V_35 [ V_13 ] ) &&
( V_136 > 0 ) )
F_71 ( & V_2 -> V_36 ,
V_137 + ( ( V_136 * V_138 ) / 1000 ) ) ;
}
void F_72 ( struct V_1 * V_2 , int V_13 )
{
struct V_118 * V_119 , * V_139 ;
struct V_16 V_114 ;
unsigned long V_17 ;
unsigned int V_120 ;
F_5 ( & V_2 -> V_34 , V_17 ) ;
F_4 ( V_2 , V_13 ) ;
F_36 ( & V_2 -> V_37 [ V_13 ] ) ;
V_120 = F_53 ( V_2 , V_13 , & V_114 ) ;
F_73 ( & V_2 -> V_121 ) ;
F_74 (e, t, &dev->vblank_event_list, base.link) {
if ( V_119 -> V_128 != V_13 )
continue;
F_15 ( L_18 ,
V_119 -> V_122 . V_123 , V_120 ) ;
F_75 ( & V_119 -> V_83 . V_124 ) ;
F_68 ( V_2 , V_119 -> V_128 ) ;
F_55 ( V_2 , V_119 , V_120 , & V_114 ) ;
}
F_76 ( & V_2 -> V_121 ) ;
F_13 ( & V_2 -> V_34 , V_17 ) ;
}
void F_77 ( struct V_1 * V_2 , int V_13 )
{
if ( ! V_2 -> V_33 )
return;
if ( ! V_2 -> V_39 [ V_13 ] ) {
V_2 -> V_39 [ V_13 ] = 0x1 ;
if ( F_65 ( V_2 , V_13 ) == 0 )
V_2 -> V_39 [ V_13 ] |= 0x2 ;
}
}
void F_78 ( struct V_1 * V_2 , int V_13 )
{
unsigned long V_17 ;
if ( V_2 -> V_39 [ V_13 ] ) {
F_5 ( & V_2 -> V_34 , V_17 ) ;
V_2 -> V_32 = 1 ;
F_13 ( & V_2 -> V_34 , V_17 ) ;
if ( V_2 -> V_39 [ V_13 ] & 0x2 )
F_68 ( V_2 , V_13 ) ;
V_2 -> V_39 [ V_13 ] = 0 ;
}
}
int F_79 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_79 * V_140 = V_3 ;
unsigned int V_13 ;
if ( ! V_2 -> V_33 )
return 0 ;
if ( F_2 ( V_2 , V_64 ) )
return 0 ;
V_13 = V_140 -> V_13 ;
if ( V_13 >= V_2 -> V_33 )
return - V_11 ;
switch ( V_140 -> V_141 ) {
case V_142 :
F_77 ( V_2 , V_13 ) ;
break;
case V_143 :
F_78 ( V_2 , V_13 ) ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , int V_128 ,
union V_144 * V_145 ,
struct V_4 * V_5 )
{
struct V_118 * V_119 ;
struct V_16 V_114 ;
unsigned long V_78 ;
unsigned int V_120 ;
int V_40 ;
V_119 = F_81 ( sizeof *V_119 , V_43 ) ;
if ( V_119 == NULL ) {
V_40 = - V_41 ;
goto V_146;
}
V_119 -> V_128 = V_128 ;
V_119 -> V_83 . V_127 = V_147 -> V_127 ;
V_119 -> V_122 . V_83 . type = V_148 ;
V_119 -> V_122 . V_83 . V_149 = sizeof V_119 -> V_122 ;
V_119 -> V_122 . V_150 = V_145 -> V_151 . signal ;
V_119 -> V_83 . V_122 = & V_119 -> V_122 . V_83 ;
V_119 -> V_83 . V_5 = V_5 ;
V_119 -> V_83 . V_152 = ( void ( * ) ( struct V_153 * ) ) F_18 ;
F_5 ( & V_2 -> V_121 , V_78 ) ;
if ( V_5 -> V_154 < sizeof V_119 -> V_122 ) {
V_40 = - V_58 ;
goto V_155;
}
V_5 -> V_154 -= sizeof V_119 -> V_122 ;
V_120 = F_53 ( V_2 , V_128 , & V_114 ) ;
if ( ( V_145 -> V_151 . type & V_156 ) &&
( V_120 - V_145 -> V_151 . V_123 ) <= ( 1 << 23 ) ) {
V_145 -> V_151 . V_123 = V_120 + 1 ;
V_145 -> V_157 . V_123 = V_145 -> V_151 . V_123 ;
}
F_15 ( L_19 ,
V_145 -> V_151 . V_123 , V_120 , V_128 ) ;
F_82 ( V_147 -> V_127 , V_128 ,
V_145 -> V_151 . V_123 ) ;
V_119 -> V_122 . V_123 = V_145 -> V_151 . V_123 ;
if ( ( V_120 - V_145 -> V_151 . V_123 ) <= ( 1 << 23 ) ) {
F_68 ( V_2 , V_128 ) ;
F_55 ( V_2 , V_119 , V_120 , & V_114 ) ;
V_145 -> V_157 . V_123 = V_120 ;
} else {
F_58 ( & V_119 -> V_83 . V_124 , & V_2 -> V_158 ) ;
V_145 -> V_157 . V_123 = V_145 -> V_151 . V_123 ;
}
F_13 ( & V_2 -> V_121 , V_78 ) ;
return 0 ;
V_155:
F_13 ( & V_2 -> V_121 , V_78 ) ;
F_18 ( V_119 ) ;
V_146:
F_68 ( V_2 , V_128 ) ;
return V_40 ;
}
int V_144 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
union V_144 * V_145 = V_3 ;
int V_40 ;
unsigned int V_78 , V_120 , V_13 , V_159 ;
if ( F_2 ( V_2 , V_12 ) )
if ( ( ! F_29 ( V_2 ) ) || ( ! V_2 -> V_50 ) )
return - V_11 ;
if ( V_145 -> V_151 . type & V_160 )
return - V_11 ;
if ( V_145 -> V_151 . type &
~ ( V_161 | V_162 |
V_163 ) ) {
F_41 ( L_20 ,
V_145 -> V_151 . type ,
( V_161 | V_162 |
V_163 ) ) ;
return - V_11 ;
}
V_78 = V_145 -> V_151 . type & V_162 ;
V_159 = ( V_145 -> V_151 . type & V_163 ) ;
if ( V_159 )
V_13 = V_159 >> V_164 ;
else
V_13 = V_78 & V_165 ? 1 : 0 ;
if ( V_13 >= V_2 -> V_33 )
return - V_11 ;
V_40 = F_65 ( V_2 , V_13 ) ;
if ( V_40 ) {
F_15 ( L_21 , V_40 ) ;
return V_40 ;
}
V_120 = F_52 ( V_2 , V_13 ) ;
switch ( V_145 -> V_151 . type & V_161 ) {
case V_166 :
V_145 -> V_151 . V_123 += V_120 ;
V_145 -> V_151 . type &= ~ V_166 ;
case V_167 :
break;
default:
V_40 = - V_11 ;
goto V_168;
}
if ( V_78 & V_169 ) {
return F_80 ( V_2 , V_13 , V_145 , V_5 ) ;
}
if ( ( V_78 & V_156 ) &&
( V_120 - V_145 -> V_151 . V_123 ) <= ( 1 << 23 ) ) {
V_145 -> V_151 . V_123 = V_120 + 1 ;
}
F_15 ( L_22 ,
V_145 -> V_151 . V_123 , V_13 ) ;
V_2 -> V_38 [ V_13 ] = V_145 -> V_151 . V_123 ;
F_83 ( V_40 , V_2 -> V_37 [ V_13 ] , 3 * V_138 ,
( ( ( F_52 ( V_2 , V_13 ) -
V_145 -> V_151 . V_123 ) <= ( 1 << 23 ) ) ||
! V_2 -> V_50 ) ) ;
if ( V_40 != - V_170 ) {
struct V_16 V_114 ;
V_145 -> V_157 . V_123 = F_53 ( V_2 , V_13 , & V_114 ) ;
V_145 -> V_157 . V_171 = V_114 . V_110 ;
V_145 -> V_157 . V_172 = V_114 . V_111 ;
F_15 ( L_23 ,
V_145 -> V_157 . V_123 ) ;
} else {
F_15 ( L_24 ) ;
}
V_168:
F_68 ( V_2 , V_13 ) ;
return V_40 ;
}
static void F_84 ( struct V_1 * V_2 , int V_13 )
{
struct V_118 * V_119 , * V_139 ;
struct V_16 V_114 ;
unsigned long V_78 ;
unsigned int V_120 ;
V_120 = F_53 ( V_2 , V_13 , & V_114 ) ;
F_5 ( & V_2 -> V_121 , V_78 ) ;
F_74 (e, t, &dev->vblank_event_list, base.link) {
if ( V_119 -> V_128 != V_13 )
continue;
if ( ( V_120 - V_119 -> V_122 . V_123 ) > ( 1 << 23 ) )
continue;
F_15 ( L_25 ,
V_119 -> V_122 . V_123 , V_120 ) ;
F_75 ( & V_119 -> V_83 . V_124 ) ;
F_68 ( V_2 , V_119 -> V_128 ) ;
F_55 ( V_2 , V_119 , V_120 , & V_114 ) ;
}
F_13 ( & V_2 -> V_121 , V_78 ) ;
F_85 ( V_13 , V_120 ) ;
}
bool F_86 ( struct V_1 * V_2 , int V_13 )
{
T_1 V_18 ;
T_2 V_19 ;
struct V_16 V_21 ;
unsigned long V_17 ;
if ( ! V_2 -> V_33 )
return false ;
F_5 ( & V_2 -> V_24 , V_17 ) ;
if ( ! V_2 -> V_26 [ V_13 ] ) {
F_13 ( & V_2 -> V_24 , V_17 ) ;
return false ;
}
V_18 = F_7 ( & V_2 -> V_29 [ V_13 ] ) ;
F_6 ( V_2 , V_13 , & V_21 , V_109 ) ;
V_19 = F_8 ( & V_21 ) -
F_8 ( & F_9 ( V_2 , V_13 , V_18 ) ) ;
if ( F_10 ( V_19 ) > V_173 ) {
F_9 ( V_2 , V_13 , V_18 + 1 ) = V_21 ;
F_63 () ;
F_11 ( & V_2 -> V_29 [ V_13 ] ) ;
F_12 () ;
} else {
F_15 ( L_26 ,
V_13 , ( int ) V_19 ) ;
}
F_36 ( & V_2 -> V_37 [ V_13 ] ) ;
F_84 ( V_2 , V_13 ) ;
F_13 ( & V_2 -> V_24 , V_17 ) ;
return true ;
}
