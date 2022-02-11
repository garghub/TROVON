static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
V_4 -> V_6 ( V_4 ) ;
}
static int F_3 ( T_1 * V_7 )
{
F_4 () ;
return 0 ;
}
int F_5 ( void )
{
struct V_8 V_9 ;
struct V_10 * V_10 ;
int V_11 ;
F_6 ( L_1 ) ;
F_7 ( & V_12 ) ;
V_11 = - V_13 ;
V_14 = F_8 ( L_2 ) ;
if ( ! V_14 )
goto V_15;
V_11 = F_9 ( & V_16 , V_17 , V_18 , V_19 , & V_10 ) ;
if ( V_11 < 0 )
goto V_20;
V_10 -> V_21 -> V_22 = V_23 ;
V_9 . V_24 = V_17 ;
V_9 . V_25 = V_26 ;
V_9 . V_27 = V_18 ;
V_9 . V_28 = sizeof( V_9 . V_29 . sin ) ;
V_9 . V_29 . sin . V_30 = V_31 ;
V_9 . V_29 . sin . V_32 = F_10 ( V_33 ) ;
memset ( & V_9 . V_29 . sin . V_34 , 0 ,
sizeof( V_9 . V_29 . sin . V_34 ) ) ;
V_11 = F_11 ( V_10 , (struct V_35 * ) & V_9 , sizeof( V_9 ) ) ;
if ( V_11 < 0 )
goto V_36;
V_11 = F_12 ( V_10 , V_37 ) ;
if ( V_11 < 0 )
goto V_36;
F_13 ( V_10 , V_38 ) ;
V_39 = V_10 ;
F_14 ( L_3 ) ;
return 0 ;
V_36:
F_15 ( V_10 ) ;
V_20:
F_16 ( V_14 ) ;
V_15:
F_14 ( L_4 , V_11 ) ;
return V_11 ;
}
void F_17 ( void )
{
F_6 ( L_1 ) ;
F_18 ( & V_40 , F_3 ,
V_41 ) ;
F_19 ( L_5 ) ;
F_15 ( V_39 ) ;
F_19 ( L_6 ) ;
F_16 ( V_14 ) ;
F_20 ( F_21 ( & V_42 ) , == , 0 ) ;
F_14 ( L_1 ) ;
}
void F_22 ( struct V_3 * V_4 , struct V_43 * V_44 )
{
if ( ! V_44 ) {
F_19 ( L_7 , F_21 ( & V_42 ) ) ;
F_23 () ;
} else {
F_19 ( L_8 ,
V_44 , V_44 -> V_45 , F_21 ( & V_42 ) ) ;
F_24 ( V_4 -> V_46 , V_44 ) ;
}
}
static void F_25 ( struct V_43 * V_44 )
{
if ( ! V_44 ) {
F_19 ( L_9 , F_21 ( & V_42 ) ) ;
F_23 () ;
} else {
F_19 ( L_10 ,
V_44 , V_44 -> V_45 , F_21 ( & V_42 ) ) ;
if ( F_26 ( & V_42 ) == - 1 )
F_27 () ;
F_28 ( V_44 ) ;
}
}
static void F_29 ( struct V_3 * V_4 )
{
F_19 ( L_11 ,
V_4 , V_4 -> type -> V_47 , F_21 ( & V_40 ) ) ;
F_20 ( V_4 -> V_46 , == , NULL ) ;
ASSERT ( ! F_30 ( & V_4 -> V_5 ) ) ;
ASSERT ( F_31 ( & V_4 -> V_48 ) ) ;
ASSERT ( V_4 -> type -> V_47 != NULL ) ;
F_32 ( V_4 -> V_49 ) ;
F_32 ( V_4 ) ;
if ( F_33 ( & V_40 ) )
F_34 ( & V_40 ) ;
}
static void F_35 ( struct V_3 * V_4 )
{
if ( V_4 -> V_46 ) {
F_36 ( V_4 -> V_46 ) ;
V_4 -> V_46 = NULL ;
}
if ( V_4 -> type -> V_50 )
V_4 -> type -> V_50 ( V_4 ) ;
}
static void F_37 ( struct V_3 * V_4 )
{
F_35 ( V_4 ) ;
F_29 ( V_4 ) ;
}
struct V_3 * F_38 ( const struct V_51 * type ,
T_2 V_52 , T_2 V_53 )
{
struct V_3 * V_4 ;
V_4 = F_39 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
goto V_54;
F_19 ( L_12 ,
V_4 , type -> V_47 , F_21 ( & V_40 ) ) ;
F_40 ( & V_40 ) ;
V_4 -> type = type ;
V_4 -> V_52 = V_52 ;
V_4 -> V_55 = V_53 ;
if ( V_52 ) {
V_4 -> V_49 = F_41 ( V_52 , V_23 ) ;
if ( ! V_4 -> V_49 )
goto V_56;
}
if ( V_53 ) {
V_4 -> V_57 = F_41 ( V_53 , V_23 ) ;
if ( ! V_4 -> V_57 )
goto V_56;
}
F_42 ( & V_4 -> V_58 ) ;
F_7 ( & V_4 -> V_48 ) ;
return V_4 ;
V_56:
F_29 ( V_4 ) ;
V_54:
return NULL ;
}
void F_43 ( struct V_3 * V_4 )
{
F_6 ( L_1 ) ;
F_32 ( V_4 -> V_49 ) ;
V_4 -> V_49 = NULL ;
F_32 ( V_4 -> V_57 ) ;
V_4 -> V_57 = NULL ;
}
static int F_44 ( struct V_3 * V_4 , struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 [ 8 ] ;
unsigned V_65 , V_66 , V_67 , V_68 , V_69 ;
T_3 V_70 = V_4 -> V_70 , V_71 = V_4 -> V_71 ;
int V_11 ;
F_6 ( L_1 ) ;
V_68 = V_4 -> V_72 ;
V_4 -> V_72 = 0 ;
do {
F_19 ( L_13 , V_70 , V_71 ) ;
V_65 = V_71 - V_70 + 1 ;
if ( V_65 > F_45 ( V_64 ) )
V_65 = F_45 ( V_64 ) ;
V_66 = F_46 ( V_4 -> V_73 , V_70 , V_65 , V_64 ) ;
F_20 ( V_66 , == , V_65 ) ;
V_67 = 0 ;
do {
V_60 -> V_74 = 0 ;
V_69 = V_75 ;
if ( V_70 + V_67 >= V_71 )
V_69 = V_4 -> V_76 ;
else
V_60 -> V_74 = V_77 ;
V_62 -> V_78 = F_47 ( V_64 [ V_67 ] ) + V_68 ;
V_62 -> V_79 = V_69 - V_68 ;
V_68 = 0 ;
F_19 ( L_14 ,
V_68 , V_69 , V_60 -> V_74 ? L_15 : L_1 ) ;
F_48 ( & V_60 -> V_80 , V_81 | V_82 ,
V_62 , 1 , V_69 - V_68 ) ;
if ( V_70 + V_67 >= V_71 )
V_4 -> V_83 = V_84 ;
V_11 = F_49 ( V_4 -> V_46 , V_60 ,
V_69 - V_68 ) ;
F_50 ( V_64 [ V_67 ] ) ;
if ( V_11 < 0 )
break;
} while ( ++ V_67 < V_65 );
V_70 += V_65 ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ )
F_51 ( V_64 [ V_67 ] ) ;
if ( V_11 < 0 )
break;
} while ( V_70 <= V_71 );
F_14 ( L_4 , V_11 ) ;
return V_11 ;
}
int F_52 ( struct V_85 * V_86 , struct V_3 * V_4 , T_4 V_87 ,
const struct V_88 * V_89 )
{
struct V_8 V_9 ;
struct V_90 * V_46 ;
struct V_59 V_60 ;
struct V_61 V_62 [ 1 ] ;
int V_11 ;
struct V_43 * V_44 ;
F_6 ( L_16 , V_86 -> V_91 , F_53 ( V_4 -> V_92 ) ) ;
ASSERT ( V_4 -> type != NULL ) ;
ASSERT ( V_4 -> type -> V_47 != NULL ) ;
F_19 ( L_17 ,
V_4 , V_4 -> type -> V_47 , F_54 ( V_4 -> V_93 ) ,
F_21 ( & V_40 ) ) ;
V_4 -> V_89 = V_89 ;
V_4 -> V_6 = V_94 ;
F_55 ( & V_4 -> V_5 , F_1 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_24 = V_17 ;
V_9 . V_25 = V_4 -> V_95 ;
V_9 . V_27 = V_18 ;
V_9 . V_28 = sizeof( V_9 . V_29 . sin ) ;
V_9 . V_29 . sin . V_30 = V_31 ;
V_9 . V_29 . sin . V_32 = V_4 -> V_92 ;
memcpy ( & V_9 . V_29 . sin . V_34 , V_86 , 4 ) ;
V_46 = F_56 ( V_39 , & V_9 , V_4 -> V_93 ,
( unsigned long ) V_4 , V_87 ) ;
V_4 -> V_93 = NULL ;
if ( F_57 ( V_46 ) ) {
V_11 = F_58 ( V_46 ) ;
goto V_96;
}
V_4 -> V_46 = V_46 ;
V_62 [ 0 ] . V_78 = V_4 -> V_49 ;
V_62 [ 0 ] . V_79 = V_4 -> V_52 ;
V_60 . V_97 = NULL ;
V_60 . V_98 = 0 ;
F_48 ( & V_60 . V_80 , V_81 | V_82 , V_62 , 1 ,
V_4 -> V_52 ) ;
V_60 . V_99 = NULL ;
V_60 . V_100 = 0 ;
V_60 . V_74 = ( V_4 -> V_101 ? V_77 : 0 ) ;
if ( ! V_4 -> V_101 )
V_4 -> V_83 = V_84 ;
V_11 = F_49 ( V_46 , & V_60 , V_4 -> V_52 ) ;
if ( V_11 < 0 )
goto V_102;
if ( V_4 -> V_101 ) {
V_11 = F_44 ( V_4 , & V_60 , V_62 ) ;
if ( V_11 < 0 )
goto V_102;
}
return V_89 -> V_103 ( V_4 ) ;
V_102:
F_59 ( V_46 , V_104 ) ;
while ( ( V_44 = F_60 ( & V_4 -> V_48 ) ) )
F_25 ( V_44 ) ;
V_96:
F_37 ( V_4 ) ;
F_14 ( L_4 , V_11 ) ;
return V_11 ;
}
static void V_38 ( struct V_105 * V_21 , unsigned long V_106 ,
struct V_43 * V_44 )
{
struct V_3 * V_4 = (struct V_3 * ) V_106 ;
F_6 ( L_18 , V_4 , V_44 -> V_45 ) ;
F_19 ( L_19 ,
V_44 , V_44 -> V_45 , F_21 ( & V_42 ) ) ;
F_20 ( V_21 , == , V_39 -> V_21 ) ;
F_40 ( & V_42 ) ;
if ( ! V_4 ) {
F_61 ( & V_12 , V_44 ) ;
F_62 ( V_107 , & V_108 ) ;
} else {
F_61 ( & V_4 -> V_48 , V_44 ) ;
V_4 -> V_89 -> V_109 ( V_4 ) ;
}
F_14 ( L_1 ) ;
}
static void F_63 ( struct V_3 * V_4 )
{
struct V_43 * V_44 ;
bool V_71 ;
T_5 V_110 ;
int V_11 ;
F_6 ( L_1 ) ;
while ( ( V_4 -> V_83 == V_84 ||
V_4 -> V_83 == V_111 ||
V_4 -> V_83 == V_112 ||
V_4 -> V_83 == V_113 ) &&
( V_44 = F_60 ( & V_4 -> V_48 ) ) ) {
switch ( V_44 -> V_45 ) {
case V_114 :
F_19 ( L_20 ) ;
V_71 = F_64 ( V_44 ) ;
V_11 = V_4 -> type -> V_115 ( V_4 , V_44 , V_71 ) ;
switch ( V_11 ) {
case - V_116 :
if ( V_71 ) {
F_19 ( L_21 ) ;
goto V_117;
}
break;
case 0 :
ASSERT ( V_71 ) ;
if ( V_4 -> V_83 == V_84 )
V_4 -> V_83 = V_118 ;
break;
case - V_119 :
V_110 = V_120 ;
goto V_121;
case - V_122 :
V_110 = V_123 ;
goto V_121;
default:
V_117:
V_110 = V_124 ;
if ( V_4 -> V_83 != V_84 )
V_110 = V_125 ;
V_121:
F_59 ( V_4 -> V_46 ,
V_110 ) ;
V_4 -> error = V_11 ;
V_4 -> V_83 = V_126 ;
break;
}
break;
case V_127 :
F_19 ( L_22 ) ;
V_4 -> V_83 = V_118 ;
break;
case V_128 :
F_19 ( L_23 ) ;
V_4 -> error = - V_129 ;
V_4 -> V_83 = V_130 ;
break;
case V_131 :
V_110 = F_65 ( V_44 ) ;
V_4 -> error = V_4 -> type -> V_132 ( V_110 ) ;
V_4 -> V_83 = V_133 ;
F_19 ( L_24 , V_110 , V_4 -> error ) ;
break;
case V_134 :
V_110 = F_65 ( V_44 ) ;
V_4 -> error = V_4 -> type -> V_132 ( V_110 ) ;
V_4 -> V_83 = V_133 ;
F_19 ( L_25 , V_110 , V_4 -> error ) ;
break;
case V_135 :
V_4 -> error = - F_66 ( V_44 ) ;
V_4 -> V_83 = V_126 ;
F_19 ( L_26 , V_4 -> error ) ;
break;
case V_136 :
V_4 -> error = - F_66 ( V_44 ) ;
V_4 -> V_83 = V_126 ;
F_19 ( L_27 , V_4 -> error ) ;
break;
default:
F_27 () ;
break;
}
F_25 ( V_44 ) ;
}
if ( V_4 -> V_83 >= V_118 ) {
while ( ( V_44 = F_60 ( & V_4 -> V_48 ) ) )
F_25 ( V_44 ) ;
if ( V_4 -> V_137 )
F_37 ( V_4 ) ;
}
F_14 ( L_1 ) ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_43 * V_44 ;
int V_11 ;
F_68 ( V_138 , V_139 ) ;
F_6 ( L_1 ) ;
F_69 ( & V_4 -> V_58 , & V_138 ) ;
for (; ; ) {
F_70 ( V_140 ) ;
if ( ! F_31 ( & V_4 -> V_48 ) ) {
F_71 ( V_141 ) ;
F_63 ( V_4 ) ;
continue;
}
V_11 = V_4 -> error ;
if ( V_4 -> V_83 >= V_118 )
break;
V_11 = - V_142 ;
if ( F_72 ( V_139 ) )
break;
F_4 () ;
}
F_73 ( & V_4 -> V_58 , & V_138 ) ;
F_71 ( V_141 ) ;
if ( V_4 -> V_83 < V_118 ) {
F_19 ( L_28 ) ;
F_59 ( V_4 -> V_46 , V_120 ) ;
while ( ( V_44 = F_60 ( & V_4 -> V_48 ) ) )
F_25 ( V_44 ) ;
}
F_19 ( L_29 ) ;
F_37 ( V_4 ) ;
F_14 ( L_4 , V_11 ) ;
return V_11 ;
}
static void F_74 ( struct V_3 * V_4 )
{
F_75 ( & V_4 -> V_58 ) ;
}
static void F_76 ( struct V_3 * V_4 )
{
F_6 ( L_1 ) ;
F_62 ( V_14 , & V_4 -> V_5 ) ;
}
static int F_77 ( struct V_3 * V_4 )
{
F_6 ( L_1 ) ;
return - V_143 ;
}
static void F_78 ( struct V_3 * V_4 )
{
F_6 ( L_1 ) ;
F_29 ( V_4 ) ;
F_14 ( L_1 ) ;
}
static void V_94 ( struct V_3 * V_4 )
{
F_6 ( L_1 ) ;
if ( ! F_31 ( & V_4 -> V_48 ) )
F_63 ( V_4 ) ;
if ( V_4 -> V_83 >= V_118 && V_4 -> V_89 ) {
if ( V_4 -> V_89 -> V_144 )
V_4 -> V_89 -> V_144 ( V_4 -> V_145 ,
V_4 -> error ) ;
V_4 -> V_145 = NULL ;
F_35 ( V_4 ) ;
V_4 -> V_6 = F_78 ;
F_62 ( V_14 , & V_4 -> V_5 ) ;
}
F_14 ( L_1 ) ;
}
int F_79 ( struct V_3 * V_4 , struct V_43 * V_44 , bool V_71 )
{
T_2 V_146 = V_44 -> V_146 ;
if ( V_146 > V_4 -> V_55 - V_4 -> V_53 ) {
F_14 ( L_30 ,
V_146 , V_4 -> V_55 - V_4 -> V_53 ) ;
return - V_147 ;
}
if ( V_146 > 0 ) {
if ( F_80 ( V_44 , 0 , V_4 -> V_57 + V_4 -> V_53 ,
V_146 ) < 0 )
F_27 () ;
V_4 -> V_53 += V_146 ;
}
F_22 ( V_4 , V_44 ) ;
if ( ! V_71 )
return - V_116 ;
if ( V_4 -> V_53 != V_4 -> V_55 ) {
F_14 ( L_31 ,
V_4 -> V_53 , V_4 -> V_55 ) ;
return - V_147 ;
}
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_90 * V_46 ;
struct V_3 * V_4 = NULL ;
struct V_43 * V_44 ;
while ( ( V_44 = F_60 ( & V_12 ) ) ) {
F_19 ( L_32 ) ;
F_25 ( V_44 ) ;
if ( ! V_4 ) {
V_4 = F_39 ( sizeof( struct V_3 ) , V_148 ) ;
if ( ! V_4 ) {
F_82 ( V_39 ) ;
return;
}
V_4 -> V_6 = V_94 ;
F_55 ( & V_4 -> V_5 , F_1 ) ;
V_4 -> V_89 = & V_149 ;
V_4 -> type = & V_150 ;
F_42 ( & V_4 -> V_58 ) ;
F_7 ( & V_4 -> V_48 ) ;
V_4 -> V_83 = V_111 ;
F_19 ( L_12 ,
V_4 , V_4 -> type -> V_47 ,
F_21 ( & V_40 ) ) ;
F_40 ( & V_40 ) ;
}
V_46 = F_83 ( V_39 ,
( unsigned long ) V_4 ) ;
if ( ! F_57 ( V_46 ) ) {
V_4 -> V_46 = V_46 ;
V_4 = NULL ;
}
}
if ( V_4 )
F_29 ( V_4 ) ;
}
static int F_84 ( struct V_3 * V_4 , struct V_43 * V_44 ,
bool V_71 )
{
T_2 V_146 = V_44 -> V_146 ;
void * V_151 = ( void * ) & V_4 -> V_152 ;
F_6 ( L_33 , V_4 -> V_68 , V_146 , V_71 ) ;
F_20 ( V_4 -> V_68 , < , 4 ) ;
V_146 = F_85 ( T_2 , V_146 , 4 - V_4 -> V_68 ) ;
if ( F_80 ( V_44 , 0 , V_151 + V_4 -> V_68 , V_146 ) < 0 )
F_27 () ;
if ( ! F_86 ( V_44 , V_146 ) )
F_27 () ;
V_4 -> V_68 += V_146 ;
if ( V_4 -> V_68 < 4 ) {
F_22 ( V_4 , V_44 ) ;
F_14 ( L_34 ) ;
return - V_116 ;
}
V_4 -> V_83 = V_112 ;
if ( ! F_87 ( V_4 ) )
return - V_122 ;
return V_4 -> type -> V_115 ( V_4 , V_44 , V_71 ) ;
}
void F_88 ( struct V_3 * V_4 )
{
struct V_59 V_60 ;
F_6 ( L_1 ) ;
V_60 . V_97 = NULL ;
V_60 . V_98 = 0 ;
F_48 ( & V_60 . V_80 , V_81 | V_82 , NULL , 0 , 0 ) ;
V_60 . V_99 = NULL ;
V_60 . V_100 = 0 ;
V_60 . V_74 = 0 ;
V_4 -> V_83 = V_113 ;
switch ( F_49 ( V_4 -> V_46 , & V_60 , 0 ) ) {
case 0 :
F_14 ( L_35 ) ;
return;
case - V_13 :
F_19 ( L_36 ) ;
F_59 ( V_4 -> V_46 , V_104 ) ;
default:
F_37 ( V_4 ) ;
F_14 ( L_37 ) ;
return;
}
}
void F_89 ( struct V_3 * V_4 , const void * V_153 , T_2 V_146 )
{
struct V_59 V_60 ;
struct V_61 V_62 [ 1 ] ;
int V_66 ;
F_6 ( L_1 ) ;
V_62 [ 0 ] . V_78 = ( void * ) V_153 ;
V_62 [ 0 ] . V_79 = V_146 ;
V_60 . V_97 = NULL ;
V_60 . V_98 = 0 ;
F_48 ( & V_60 . V_80 , V_81 | V_82 , V_62 , 1 , V_146 ) ;
V_60 . V_99 = NULL ;
V_60 . V_100 = 0 ;
V_60 . V_74 = 0 ;
V_4 -> V_83 = V_113 ;
V_66 = F_49 ( V_4 -> V_46 , & V_60 , V_146 ) ;
if ( V_66 >= 0 ) {
F_14 ( L_35 ) ;
return;
}
if ( V_66 == - V_13 ) {
F_19 ( L_36 ) ;
F_59 ( V_4 -> V_46 , V_104 ) ;
}
F_37 ( V_4 ) ;
F_14 ( L_37 ) ;
}
int F_90 ( struct V_3 * V_4 , struct V_43 * V_44 ,
bool V_71 , void * V_153 , T_2 V_65 )
{
T_2 V_146 = V_44 -> V_146 ;
F_6 ( L_38 , V_4 -> V_68 , V_146 , V_71 , V_65 ) ;
F_20 ( V_4 -> V_68 , < , V_65 ) ;
V_146 = F_85 ( T_2 , V_146 , V_65 - V_4 -> V_68 ) ;
if ( F_80 ( V_44 , 0 , V_153 + V_4 -> V_68 , V_146 ) < 0 ||
! F_86 ( V_44 , V_146 ) )
F_27 () ;
V_4 -> V_68 += V_146 ;
if ( V_4 -> V_68 < V_65 ) {
F_22 ( V_4 , V_44 ) ;
F_14 ( L_34 ) ;
return - V_116 ;
}
return 0 ;
}
