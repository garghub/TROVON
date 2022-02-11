static int F_1 ( T_1 * V_1 )
{
F_2 () ;
return 0 ;
}
int F_3 ( void )
{
struct V_2 V_3 ;
struct V_4 * V_4 ;
int V_5 ;
F_4 ( L_1 ) ;
V_5 = - V_6 ;
V_7 = F_5 ( L_2 , V_8 , 0 ) ;
if ( ! V_7 )
goto V_9;
V_5 = F_6 ( & V_10 , V_11 , V_12 , V_13 , & V_4 ) ;
if ( V_5 < 0 )
goto V_14;
V_4 -> V_15 -> V_16 = V_17 ;
V_3 . V_18 = V_11 ;
V_3 . V_19 = V_20 ;
V_3 . V_21 = V_12 ;
V_3 . V_22 = sizeof( V_3 . V_23 . sin ) ;
V_3 . V_23 . sin . V_24 = V_25 ;
V_3 . V_23 . sin . V_26 = F_7 ( V_27 ) ;
memset ( & V_3 . V_23 . sin . V_28 , 0 ,
sizeof( V_3 . V_23 . sin . V_28 ) ) ;
V_5 = F_8 ( V_4 , (struct V_29 * ) & V_3 , sizeof( V_3 ) ) ;
if ( V_5 < 0 )
goto V_30;
F_9 ( V_4 , V_31 ,
V_32 ) ;
V_5 = F_10 ( V_4 , V_33 ) ;
if ( V_5 < 0 )
goto V_30;
V_34 = V_4 ;
F_11 ( NULL ) ;
F_12 ( L_3 ) ;
return 0 ;
V_30:
F_13 ( V_4 ) ;
V_14:
F_14 ( V_7 ) ;
V_9:
F_12 ( L_4 , V_5 ) ;
return V_5 ;
}
void F_15 ( void )
{
F_4 ( L_1 ) ;
if ( V_35 ) {
F_16 ( & V_36 ) ;
F_17 ( V_35 ) ;
V_35 = NULL ;
}
F_18 ( L_5 , F_19 ( & V_36 ) ) ;
F_20 ( & V_36 , F_1 ,
V_37 ) ;
F_18 ( L_6 ) ;
F_21 ( V_7 ) ;
F_22 ( V_34 , V_38 ) ;
F_21 ( V_7 ) ;
F_13 ( V_34 ) ;
F_18 ( L_7 ) ;
F_14 ( V_7 ) ;
F_12 ( L_1 ) ;
}
static void F_17 ( struct V_39 * V_40 )
{
F_18 ( L_8 ,
V_40 , V_40 -> type -> V_41 , F_19 ( & V_36 ) ) ;
F_23 ( V_40 -> V_42 , == , NULL ) ;
ASSERT ( ! F_24 ( & V_40 -> V_43 ) ) ;
ASSERT ( V_40 -> type -> V_41 != NULL ) ;
F_25 ( V_40 -> V_44 ) ;
F_25 ( V_40 ) ;
if ( F_26 ( & V_36 ) )
F_27 ( & V_36 ) ;
}
static void F_28 ( struct V_39 * V_40 )
{
if ( V_40 -> V_42 ) {
F_29 ( V_34 , V_40 -> V_42 ) ;
V_40 -> V_42 = NULL ;
}
if ( V_40 -> type -> V_45 )
V_40 -> type -> V_45 ( V_40 ) ;
}
static void F_30 ( struct V_39 * V_40 )
{
F_28 ( V_40 ) ;
F_17 ( V_40 ) ;
}
struct V_39 * F_31 ( const struct V_46 * type ,
T_2 V_47 , T_2 V_48 )
{
struct V_39 * V_40 ;
V_40 = F_32 ( sizeof( * V_40 ) , V_17 ) ;
if ( ! V_40 )
goto V_49;
F_18 ( L_9 ,
V_40 , type -> V_41 , F_19 ( & V_36 ) ) ;
F_16 ( & V_36 ) ;
V_40 -> type = type ;
V_40 -> V_47 = V_47 ;
V_40 -> V_48 = V_48 ;
if ( V_47 ) {
V_40 -> V_44 = F_33 ( V_47 , V_17 ) ;
if ( ! V_40 -> V_44 )
goto V_50;
}
if ( V_48 ) {
V_40 -> V_51 = F_33 ( V_48 , V_17 ) ;
if ( ! V_40 -> V_51 )
goto V_50;
}
F_34 ( & V_40 -> V_52 ) ;
return V_40 ;
V_50:
F_17 ( V_40 ) ;
V_49:
return NULL ;
}
void F_35 ( struct V_39 * V_40 )
{
F_4 ( L_1 ) ;
F_25 ( V_40 -> V_44 ) ;
V_40 -> V_44 = NULL ;
F_25 ( V_40 -> V_51 ) ;
V_40 -> V_51 = NULL ;
}
static int F_36 ( struct V_39 * V_40 , struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_57 * V_58 [ 8 ] ;
unsigned V_59 , V_60 , V_61 , V_62 , V_63 ;
T_3 V_64 = V_40 -> V_64 , V_65 = V_40 -> V_65 ;
int V_5 ;
F_4 ( L_1 ) ;
V_62 = V_40 -> V_66 ;
V_40 -> V_66 = 0 ;
do {
F_18 ( L_10 , V_64 , V_65 ) ;
V_59 = V_65 - V_64 + 1 ;
if ( V_59 > F_37 ( V_58 ) )
V_59 = F_37 ( V_58 ) ;
V_60 = F_38 ( V_40 -> V_67 , V_64 , V_59 , V_58 ) ;
F_23 ( V_60 , == , V_59 ) ;
V_61 = 0 ;
do {
V_54 -> V_68 = 0 ;
V_63 = V_69 ;
if ( V_64 + V_61 >= V_65 )
V_63 = V_40 -> V_70 ;
else
V_54 -> V_68 = V_71 ;
V_56 -> V_72 = F_39 ( V_58 [ V_61 ] ) + V_62 ;
V_56 -> V_73 = V_63 - V_62 ;
V_62 = 0 ;
F_18 ( L_11 ,
V_62 , V_63 , V_54 -> V_68 ? L_12 : L_1 ) ;
F_40 ( & V_54 -> V_74 , V_75 | V_76 ,
V_56 , 1 , V_63 - V_62 ) ;
if ( V_64 + V_61 >= V_65 )
V_40 -> V_77 = V_78 ;
V_5 = F_41 ( V_34 , V_40 -> V_42 ,
V_54 , V_63 - V_62 ) ;
F_42 ( V_58 [ V_61 ] ) ;
if ( V_5 < 0 )
break;
} while ( ++ V_61 < V_59 );
V_64 += V_59 ;
for ( V_61 = 0 ; V_61 < V_59 ; V_61 ++ )
F_43 ( V_58 [ V_61 ] ) ;
if ( V_5 < 0 )
break;
} while ( V_64 <= V_65 );
F_12 ( L_4 , V_5 ) ;
return V_5 ;
}
int F_44 ( struct V_79 * V_80 , struct V_39 * V_40 , T_4 V_81 ,
const struct V_82 * V_83 )
{
struct V_2 V_3 ;
struct V_84 * V_42 ;
struct V_53 V_54 ;
struct V_55 V_56 [ 1 ] ;
int V_5 ;
F_4 ( L_13 , V_80 -> V_85 , F_45 ( V_40 -> V_86 ) ) ;
ASSERT ( V_40 -> type != NULL ) ;
ASSERT ( V_40 -> type -> V_41 != NULL ) ;
F_18 ( L_14 ,
V_40 , V_40 -> type -> V_41 , F_46 ( V_40 -> V_87 ) ,
F_19 ( & V_36 ) ) ;
V_40 -> V_83 = V_83 ;
F_47 ( & V_40 -> V_43 , V_88 ) ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_18 = V_11 ;
V_3 . V_19 = V_40 -> V_89 ;
V_3 . V_21 = V_12 ;
V_3 . V_22 = sizeof( V_3 . V_23 . sin ) ;
V_3 . V_23 . sin . V_24 = V_25 ;
V_3 . V_23 . sin . V_26 = V_40 -> V_86 ;
memcpy ( & V_3 . V_23 . sin . V_28 , V_80 , 4 ) ;
V_42 = F_48 ( V_34 , & V_3 , V_40 -> V_87 ,
( unsigned long ) V_40 , V_81 ,
V_83 -> V_90 ) ;
V_40 -> V_87 = NULL ;
if ( F_49 ( V_42 ) ) {
V_5 = F_50 ( V_42 ) ;
goto V_91;
}
V_40 -> V_42 = V_42 ;
V_56 [ 0 ] . V_72 = V_40 -> V_44 ;
V_56 [ 0 ] . V_73 = V_40 -> V_47 ;
V_54 . V_92 = NULL ;
V_54 . V_93 = 0 ;
F_40 ( & V_54 . V_74 , V_75 | V_76 , V_56 , 1 ,
V_40 -> V_47 ) ;
V_54 . V_94 = NULL ;
V_54 . V_95 = 0 ;
V_54 . V_68 = ( V_40 -> V_96 ? V_71 : 0 ) ;
if ( ! V_40 -> V_96 )
V_40 -> V_77 = V_78 ;
V_5 = F_41 ( V_34 , V_42 ,
& V_54 , V_40 -> V_47 ) ;
if ( V_5 < 0 )
goto V_97;
if ( V_40 -> V_96 ) {
V_5 = F_36 ( V_40 , & V_54 , V_56 ) ;
if ( V_5 < 0 )
goto V_97;
}
return V_83 -> V_98 ( V_40 ) ;
V_97:
F_51 ( V_34 , V_42 , V_99 , - V_5 , L_15 ) ;
V_91:
F_30 ( V_40 ) ;
F_12 ( L_4 , V_5 ) ;
return V_5 ;
}
static void F_52 ( struct V_39 * V_40 )
{
T_5 V_100 ;
int V_5 ;
F_4 ( L_16 , V_40 -> type -> V_41 ) ;
while ( V_40 -> V_77 == V_78 ||
V_40 -> V_77 == V_101 ||
V_40 -> V_77 == V_102 ||
V_40 -> V_77 == V_103
) {
if ( V_40 -> V_77 == V_103 ) {
T_2 V_62 = 0 ;
V_5 = F_53 ( V_34 , V_40 -> V_42 ,
NULL , 0 , & V_62 , false ,
& V_40 -> V_100 ) ;
if ( V_5 == - V_104 || V_5 == - V_105 )
return;
if ( V_5 == 1 || V_5 < 0 ) {
V_40 -> V_77 = V_106 ;
goto V_107;
}
return;
}
V_5 = V_40 -> type -> V_108 ( V_40 ) ;
switch ( V_5 ) {
case 0 :
if ( V_40 -> V_77 == V_78 )
V_40 -> V_77 = V_106 ;
goto V_107;
case - V_104 :
case - V_105 :
goto V_109;
case - V_110 :
V_100 = V_111 ;
F_51 ( V_34 , V_40 -> V_42 ,
V_100 , - V_5 , L_17 ) ;
goto V_112;
case - V_113 :
V_100 = V_114 ;
F_51 ( V_34 , V_40 -> V_42 ,
V_100 , - V_5 , L_18 ) ;
goto V_112;
case - V_115 :
case - V_116 :
case - V_117 :
default:
V_100 = V_118 ;
if ( V_40 -> V_77 != V_78 )
V_100 = V_119 ;
F_51 ( V_34 , V_40 -> V_42 ,
V_100 , V_116 , L_19 ) ;
goto V_112;
}
}
V_107:
if ( V_40 -> V_77 == V_106 && V_40 -> V_120 )
F_30 ( V_40 ) ;
V_109:
F_12 ( L_1 ) ;
return;
V_112:
V_40 -> error = V_5 ;
V_40 -> V_77 = V_106 ;
goto V_107;
}
static int F_54 ( struct V_39 * V_40 )
{
const char * V_121 ;
int V_5 ;
F_55 ( V_122 , V_123 ) ;
F_4 ( L_1 ) ;
F_56 ( & V_40 -> V_52 , & V_122 ) ;
for (; ; ) {
F_57 ( V_124 ) ;
if ( V_40 -> V_77 < V_106 && V_40 -> V_125 ) {
V_40 -> V_125 = false ;
F_58 ( V_126 ) ;
F_52 ( V_40 ) ;
continue;
}
V_121 = L_20 ;
V_5 = V_40 -> error ;
if ( V_40 -> V_77 == V_106 )
break;
V_121 = L_21 ;
V_5 = - V_127 ;
if ( F_59 ( V_123 ) )
break;
F_2 () ;
}
F_60 ( & V_40 -> V_52 , & V_122 ) ;
F_58 ( V_126 ) ;
if ( V_40 -> V_77 < V_106 ) {
F_18 ( L_22 ) ;
F_51 ( V_34 , V_40 -> V_42 ,
V_111 , - V_5 , V_121 ) ;
}
F_18 ( L_23 ) ;
F_30 ( V_40 ) ;
F_12 ( L_4 , V_5 ) ;
return V_5 ;
}
static void F_61 ( struct V_128 * V_15 , struct V_84 * V_42 ,
unsigned long V_129 )
{
struct V_39 * V_40 = (struct V_39 * ) V_129 ;
V_40 -> V_125 = true ;
F_62 ( & V_40 -> V_52 ) ;
}
static void F_63 ( struct V_128 * V_15 , struct V_84 * V_42 ,
unsigned long V_129 )
{
struct V_39 * V_40 = (struct V_39 * ) V_129 ;
V_40 -> V_125 = true ;
F_64 ( V_7 , & V_40 -> V_43 ) ;
}
static int F_65 ( struct V_39 * V_40 )
{
F_4 ( L_1 ) ;
return - V_104 ;
}
static void F_66 ( struct V_130 * V_131 )
{
struct V_39 * V_40 = F_67 ( V_131 , struct V_39 , V_43 ) ;
F_4 ( L_1 ) ;
F_17 ( V_40 ) ;
F_12 ( L_1 ) ;
}
static void V_88 ( struct V_130 * V_131 )
{
struct V_39 * V_40 = F_67 ( V_131 , struct V_39 , V_43 ) ;
F_4 ( L_1 ) ;
if ( V_40 -> V_77 < V_106 && V_40 -> V_125 ) {
V_40 -> V_125 = false ;
F_52 ( V_40 ) ;
}
if ( V_40 -> V_77 == V_106 && V_40 -> V_83 ) {
if ( V_40 -> V_83 -> V_132 )
V_40 -> V_83 -> V_132 ( V_40 -> V_133 ,
V_40 -> error ) ;
V_40 -> V_133 = NULL ;
F_28 ( V_40 ) ;
V_40 -> V_43 . V_134 = F_66 ;
F_64 ( V_7 , & V_40 -> V_43 ) ;
}
F_12 ( L_1 ) ;
}
static void F_68 ( struct V_84 * V_42 , unsigned long V_135 )
{
struct V_39 * V_40 = (struct V_39 * ) V_135 ;
V_40 -> V_42 = V_42 ;
}
static void F_11 ( struct V_130 * V_131 )
{
struct V_39 * V_40 = V_35 ;
for (; ; ) {
if ( ! V_40 ) {
V_40 = F_32 ( sizeof( struct V_39 ) , V_136 ) ;
if ( ! V_40 )
break;
F_47 ( & V_40 -> V_43 , V_88 ) ;
V_40 -> V_83 = & V_137 ;
V_40 -> type = & V_138 ;
F_34 ( & V_40 -> V_52 ) ;
V_40 -> V_77 = V_101 ;
}
if ( F_69 ( V_34 ,
F_63 ,
F_68 ,
( unsigned long ) V_40 ,
V_136 ) < 0 )
break;
V_40 = NULL ;
}
V_35 = V_40 ;
}
static void V_32 ( struct V_84 * V_42 ,
unsigned long V_135 )
{
struct V_39 * V_40 = (struct V_39 * ) V_135 ;
F_16 ( & V_36 ) ;
V_40 -> V_42 = NULL ;
F_17 ( V_40 ) ;
}
static void V_31 ( struct V_128 * V_15 , struct V_84 * V_42 ,
unsigned long V_135 )
{
F_16 ( & V_36 ) ;
F_64 ( V_139 , & V_140 ) ;
}
static int F_70 ( struct V_39 * V_40 )
{
int V_5 ;
F_4 ( L_24 , V_40 -> V_62 ) ;
F_23 ( V_40 -> V_62 , < , 4 ) ;
V_5 = F_71 ( V_40 , & V_40 -> V_141 , 4 , true ) ;
if ( V_5 < 0 )
return V_5 ;
V_40 -> V_142 = F_72 ( V_40 -> V_141 ) ;
V_40 -> V_77 = V_102 ;
V_40 -> V_62 = 0 ;
if ( ! F_73 ( V_40 ) )
return - V_113 ;
return V_40 -> type -> V_108 ( V_40 ) ;
}
void F_74 ( struct V_39 * V_40 )
{
struct V_53 V_54 ;
F_4 ( L_1 ) ;
V_54 . V_92 = NULL ;
V_54 . V_93 = 0 ;
F_40 ( & V_54 . V_74 , V_75 | V_76 , NULL , 0 , 0 ) ;
V_54 . V_94 = NULL ;
V_54 . V_95 = 0 ;
V_54 . V_68 = 0 ;
V_40 -> V_77 = V_103 ;
switch ( F_41 ( V_34 , V_40 -> V_42 , & V_54 , 0 ) ) {
case 0 :
F_12 ( L_25 ) ;
return;
case - V_6 :
F_18 ( L_26 ) ;
F_51 ( V_34 , V_40 -> V_42 ,
V_99 , V_6 , L_27 ) ;
default:
F_30 ( V_40 ) ;
F_12 ( L_28 ) ;
return;
}
}
void F_75 ( struct V_39 * V_40 , const void * V_143 , T_2 V_144 )
{
struct V_53 V_54 ;
struct V_55 V_56 [ 1 ] ;
int V_60 ;
F_4 ( L_1 ) ;
V_56 [ 0 ] . V_72 = ( void * ) V_143 ;
V_56 [ 0 ] . V_73 = V_144 ;
V_54 . V_92 = NULL ;
V_54 . V_93 = 0 ;
F_40 ( & V_54 . V_74 , V_75 | V_76 , V_56 , 1 , V_144 ) ;
V_54 . V_94 = NULL ;
V_54 . V_95 = 0 ;
V_54 . V_68 = 0 ;
V_40 -> V_77 = V_103 ;
V_60 = F_41 ( V_34 , V_40 -> V_42 , & V_54 , V_144 ) ;
if ( V_60 >= 0 ) {
F_12 ( L_25 ) ;
return;
}
if ( V_60 == - V_6 ) {
F_18 ( L_26 ) ;
F_51 ( V_34 , V_40 -> V_42 ,
V_99 , V_6 , L_27 ) ;
}
F_30 ( V_40 ) ;
F_12 ( L_28 ) ;
}
int F_71 ( struct V_39 * V_40 , void * V_143 , T_2 V_59 ,
bool V_145 )
{
int V_5 ;
F_4 ( L_29 ,
V_40 -> type -> V_41 , V_40 -> V_62 , V_59 , V_145 ) ;
F_23 ( V_40 -> V_62 , <= , V_59 ) ;
V_5 = F_53 ( V_34 , V_40 -> V_42 ,
V_143 , V_59 , & V_40 -> V_62 ,
V_145 , & V_40 -> V_100 ) ;
if ( V_5 == 0 || V_5 == - V_105 )
return V_5 ;
if ( V_5 == 1 ) {
switch ( V_40 -> V_77 ) {
case V_78 :
V_40 -> V_77 = V_106 ;
break;
case V_102 :
V_40 -> V_77 = V_146 ;
break;
default:
break;
}
return 0 ;
}
if ( V_5 == - V_147 )
V_40 -> error = V_40 -> type -> V_148 ( V_40 -> V_100 ) ;
else
V_40 -> error = V_5 ;
V_40 -> V_77 = V_106 ;
return V_5 ;
}
