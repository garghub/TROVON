int F_1 ( void )
{
struct V_1 V_2 ;
struct V_3 * V_3 ;
int V_4 ;
F_2 ( L_1 ) ;
F_3 ( & V_5 ) ;
V_6 = F_4 ( L_2 ) ;
if ( ! V_6 ) {
F_5 ( L_3 ) ;
return - V_7 ;
}
V_4 = F_6 ( V_8 , V_9 , V_10 , & V_3 ) ;
if ( V_4 < 0 ) {
F_7 ( V_6 ) ;
F_5 ( L_4 , V_4 ) ;
return V_4 ;
}
V_3 -> V_11 -> V_12 = V_13 ;
V_2 . V_14 = V_8 ;
V_2 . V_15 = V_16 ;
V_2 . V_17 = V_9 ;
V_2 . V_18 = sizeof( V_2 . V_19 . sin ) ;
V_2 . V_19 . sin . V_20 = V_21 ;
V_2 . V_19 . sin . V_22 = F_8 ( V_23 ) ;
memset ( & V_2 . V_19 . sin . V_24 , 0 ,
sizeof( V_2 . V_19 . sin . V_24 ) ) ;
V_4 = F_9 ( V_3 , (struct V_25 * ) & V_2 , sizeof( V_2 ) ) ;
if ( V_4 < 0 ) {
F_10 ( V_3 ) ;
F_7 ( V_6 ) ;
F_5 ( L_5 , V_4 ) ;
return V_4 ;
}
F_11 ( V_3 , V_26 ) ;
V_27 = V_3 ;
F_5 ( L_6 ) ;
return 0 ;
}
void F_12 ( void )
{
F_2 ( L_1 ) ;
F_10 ( V_27 ) ;
F_13 ( L_7 ) ;
F_7 ( V_6 ) ;
F_14 ( F_15 ( & V_28 ) , == , 0 ) ;
F_14 ( F_15 ( & V_29 ) , == , 0 ) ;
F_5 ( L_1 ) ;
}
static void F_16 ( struct V_30 * V_31 )
{
if ( ! V_31 ) {
F_13 ( L_8 , F_15 ( & V_28 ) ) ;
F_17 () ;
} else {
F_13 ( L_9 ,
V_31 , V_31 -> V_32 , F_15 ( & V_28 ) ) ;
if ( F_18 ( & V_28 ) == - 1 )
F_19 () ;
F_20 ( V_31 ) ;
}
}
static void F_21 ( struct V_30 * V_31 )
{
if ( ! V_31 ) {
F_13 ( L_10 , F_15 ( & V_28 ) ) ;
F_17 () ;
} else {
F_13 ( L_11 ,
V_31 , V_31 -> V_32 , F_15 ( & V_28 ) ) ;
if ( F_18 ( & V_28 ) == - 1 )
F_19 () ;
F_22 ( V_31 ) ;
}
}
static void F_23 ( struct V_33 * V_34 )
{
F_13 ( L_12 ,
V_34 , V_34 -> type -> V_35 , F_15 ( & V_29 ) ) ;
if ( F_18 ( & V_29 ) == - 1 )
F_19 () ;
F_14 ( V_34 -> V_36 , == , NULL ) ;
ASSERT ( ! F_24 ( & V_34 -> V_37 ) ) ;
ASSERT ( F_25 ( & V_34 -> V_38 ) ) ;
ASSERT ( V_34 -> type -> V_35 != NULL ) ;
F_26 ( V_34 -> V_39 ) ;
F_26 ( V_34 ) ;
}
struct V_33 * F_27 ( const struct V_40 * type ,
T_1 V_41 , T_1 V_42 )
{
struct V_33 * V_34 ;
V_34 = F_28 ( sizeof( * V_34 ) , V_13 ) ;
if ( ! V_34 )
goto V_43;
F_13 ( L_13 ,
V_34 , type -> V_35 , F_15 ( & V_29 ) ) ;
F_29 ( & V_29 ) ;
V_34 -> type = type ;
V_34 -> V_41 = V_41 ;
V_34 -> V_44 = V_42 ;
if ( V_41 ) {
V_34 -> V_39 = F_30 ( V_41 , V_13 ) ;
if ( ! V_34 -> V_39 )
goto V_45;
}
if ( V_42 ) {
V_34 -> V_46 = F_30 ( V_42 , V_13 ) ;
if ( ! V_34 -> V_46 )
goto V_45;
}
F_31 ( & V_34 -> V_47 ) ;
F_3 ( & V_34 -> V_38 ) ;
return V_34 ;
V_45:
F_23 ( V_34 ) ;
V_43:
return NULL ;
}
void F_32 ( struct V_33 * V_34 )
{
F_2 ( L_1 ) ;
F_26 ( V_34 -> V_39 ) ;
V_34 -> V_39 = NULL ;
F_26 ( V_34 -> V_46 ) ;
V_34 -> V_46 = NULL ;
}
static int F_33 ( struct V_33 * V_34 , struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 [ 8 ] ;
unsigned V_54 , V_55 , V_56 , V_57 , V_58 ;
T_2 V_59 = V_34 -> V_59 , V_60 = V_34 -> V_60 ;
int V_4 ;
F_2 ( L_1 ) ;
V_57 = V_34 -> V_61 ;
V_34 -> V_61 = 0 ;
do {
F_13 ( L_14 , V_59 , V_60 ) ;
V_54 = V_60 - V_59 + 1 ;
if ( V_54 > F_34 ( V_53 ) )
V_54 = F_34 ( V_53 ) ;
V_55 = F_35 ( V_34 -> V_62 , V_59 , V_54 , V_53 ) ;
F_14 ( V_55 , == , V_54 ) ;
V_56 = 0 ;
do {
V_49 -> V_63 = 0 ;
V_58 = V_64 ;
if ( V_59 + V_56 >= V_60 )
V_58 = V_34 -> V_65 ;
else
V_49 -> V_63 = V_66 ;
V_51 -> V_67 = F_36 ( V_53 [ V_56 ] ) + V_57 ;
V_51 -> V_68 = V_58 - V_57 ;
V_57 = 0 ;
F_13 ( L_15 ,
V_57 , V_58 , V_49 -> V_63 ? L_16 : L_1 ) ;
V_49 -> V_69 = (struct V_70 * ) V_51 ;
V_49 -> V_71 = 1 ;
if ( V_59 + V_56 >= V_60 )
V_34 -> V_72 = V_73 ;
V_4 = F_37 ( V_34 -> V_36 , V_49 ,
V_58 - V_57 ) ;
F_38 ( V_53 [ V_56 ] ) ;
if ( V_4 < 0 )
break;
} while ( ++ V_56 < V_54 );
V_59 += V_54 ;
for ( V_56 = 0 ; V_56 < V_54 ; V_56 ++ )
F_39 ( V_53 [ V_56 ] ) ;
if ( V_4 < 0 )
break;
} while ( V_59 <= V_60 );
F_5 ( L_17 , V_4 ) ;
return V_4 ;
}
int F_40 ( struct V_74 * V_75 , struct V_33 * V_34 , T_3 V_76 ,
const struct V_77 * V_78 )
{
struct V_1 V_2 ;
struct V_79 * V_36 ;
struct V_48 V_49 ;
struct V_50 V_51 [ 1 ] ;
int V_4 ;
F_2 ( L_18 , V_75 -> V_80 , F_41 ( V_34 -> V_81 ) ) ;
ASSERT ( V_34 -> type != NULL ) ;
ASSERT ( V_34 -> type -> V_35 != NULL ) ;
F_13 ( L_19 ,
V_34 , V_34 -> type -> V_35 , F_42 ( V_34 -> V_82 ) ,
F_15 ( & V_29 ) ) ;
V_34 -> V_78 = V_78 ;
F_43 ( & V_34 -> V_37 , V_83 ) ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_14 = V_8 ;
V_2 . V_15 = V_34 -> V_84 ;
V_2 . V_17 = V_9 ;
V_2 . V_18 = sizeof( V_2 . V_19 . sin ) ;
V_2 . V_19 . sin . V_20 = V_21 ;
V_2 . V_19 . sin . V_22 = V_34 -> V_81 ;
memcpy ( & V_2 . V_19 . sin . V_24 , V_75 , 4 ) ;
V_36 = F_44 ( V_27 , & V_2 , V_34 -> V_82 ,
( unsigned long ) V_34 , V_76 ) ;
V_34 -> V_82 = NULL ;
if ( F_45 ( V_36 ) ) {
V_4 = F_46 ( V_36 ) ;
goto V_85;
}
V_34 -> V_36 = V_36 ;
V_51 [ 0 ] . V_67 = V_34 -> V_39 ;
V_51 [ 0 ] . V_68 = V_34 -> V_41 ;
V_49 . V_86 = NULL ;
V_49 . V_87 = 0 ;
V_49 . V_69 = (struct V_70 * ) V_51 ;
V_49 . V_71 = 1 ;
V_49 . V_88 = NULL ;
V_49 . V_89 = 0 ;
V_49 . V_63 = ( V_34 -> V_90 ? V_66 : 0 ) ;
if ( ! V_34 -> V_90 )
V_34 -> V_72 = V_73 ;
V_4 = F_37 ( V_36 , & V_49 , V_34 -> V_41 ) ;
if ( V_4 < 0 )
goto V_91;
if ( V_34 -> V_90 ) {
V_4 = F_33 ( V_34 , & V_49 , V_51 ) ;
if ( V_4 < 0 )
goto V_91;
}
return V_78 -> V_92 ( V_34 ) ;
V_91:
F_47 ( V_36 , V_93 ) ;
F_48 ( V_36 ) ;
V_34 -> V_36 = NULL ;
V_85:
V_34 -> type -> V_94 ( V_34 ) ;
F_23 ( V_34 ) ;
F_5 ( L_17 , V_4 ) ;
return V_4 ;
}
static void V_26 ( struct V_95 * V_11 , unsigned long V_96 ,
struct V_30 * V_31 )
{
struct V_33 * V_34 = (struct V_33 * ) V_96 ;
F_2 ( L_20 , V_34 , V_31 -> V_32 ) ;
F_13 ( L_21 ,
V_31 , V_31 -> V_32 , F_15 ( & V_28 ) ) ;
F_14 ( V_11 , == , V_27 -> V_11 ) ;
F_29 ( & V_28 ) ;
if ( ! V_34 ) {
F_49 ( & V_5 , V_31 ) ;
F_50 ( V_97 , & V_98 ) ;
} else {
F_49 ( & V_34 -> V_38 , V_31 ) ;
V_34 -> V_78 -> V_99 ( V_34 ) ;
}
F_5 ( L_1 ) ;
}
static void F_51 ( struct V_33 * V_34 )
{
struct V_30 * V_31 ;
bool V_60 ;
T_4 V_100 ;
int V_4 ;
F_2 ( L_1 ) ;
while ( ( V_34 -> V_72 == V_73 ||
V_34 -> V_72 == V_101 ||
V_34 -> V_72 == V_102 ||
V_34 -> V_72 == V_103 ) &&
( V_31 = F_52 ( & V_34 -> V_38 ) ) ) {
switch ( V_31 -> V_32 ) {
case V_104 :
F_13 ( L_22 ) ;
V_60 = F_53 ( V_31 ) ;
V_4 = V_34 -> type -> V_105 ( V_34 , V_31 , V_60 ) ;
switch ( V_4 ) {
case 0 :
if ( V_60 &&
V_34 -> V_72 == V_73 )
V_34 -> V_72 = V_106 ;
break;
case - V_107 :
V_100 = V_108 ;
goto V_109;
case - V_110 :
V_100 = V_111 ;
goto V_109;
default:
V_100 = V_112 ;
if ( V_34 -> V_72 != V_73 )
V_100 = V_113 ;
V_109:
F_47 ( V_34 -> V_36 ,
V_100 ) ;
V_34 -> error = V_4 ;
V_34 -> V_72 = V_114 ;
break;
}
F_16 ( V_31 ) ;
V_31 = NULL ;
continue;
case V_115 :
F_13 ( L_23 ) ;
V_34 -> V_72 = V_106 ;
break;
case V_116 :
F_13 ( L_24 ) ;
V_34 -> error = - V_117 ;
V_34 -> V_72 = V_118 ;
break;
case V_119 :
V_100 = F_54 ( V_31 ) ;
V_34 -> error = V_34 -> type -> V_120 ( V_100 ) ;
V_34 -> V_72 = V_121 ;
F_13 ( L_25 , V_100 , V_34 -> error ) ;
break;
case V_122 :
V_34 -> error = - F_55 ( V_31 ) ;
V_34 -> V_72 = V_114 ;
F_13 ( L_26 , V_34 -> error ) ;
break;
case V_123 :
V_34 -> error = - F_55 ( V_31 ) ;
V_34 -> V_72 = V_114 ;
F_13 ( L_27 , V_34 -> error ) ;
break;
default:
F_19 () ;
break;
}
F_21 ( V_31 ) ;
}
if ( V_34 -> V_72 >= V_106 ) {
while ( ( V_31 = F_52 ( & V_34 -> V_38 ) ) )
F_21 ( V_31 ) ;
if ( V_34 -> V_124 ) {
F_48 ( V_34 -> V_36 ) ;
V_34 -> V_36 = NULL ;
V_34 -> type -> V_94 ( V_34 ) ;
F_23 ( V_34 ) ;
}
}
F_5 ( L_1 ) ;
}
static int F_56 ( struct V_33 * V_34 )
{
struct V_30 * V_31 ;
int V_4 ;
F_57 ( V_125 , V_126 ) ;
F_2 ( L_1 ) ;
F_58 ( & V_34 -> V_47 , & V_125 ) ;
for (; ; ) {
F_59 ( V_127 ) ;
if ( ! F_25 ( & V_34 -> V_38 ) ) {
F_60 ( V_128 ) ;
F_51 ( V_34 ) ;
continue;
}
V_4 = V_34 -> error ;
if ( V_34 -> V_72 >= V_106 )
break;
V_4 = - V_129 ;
if ( F_61 ( V_126 ) )
break;
F_62 () ;
}
F_63 ( & V_34 -> V_47 , & V_125 ) ;
F_60 ( V_128 ) ;
if ( V_34 -> V_72 < V_106 ) {
F_13 ( L_28 ) ;
F_47 ( V_34 -> V_36 , V_108 ) ;
while ( ( V_31 = F_52 ( & V_34 -> V_38 ) ) )
F_21 ( V_31 ) ;
}
F_13 ( L_29 ) ;
F_48 ( V_34 -> V_36 ) ;
V_34 -> V_36 = NULL ;
V_34 -> type -> V_94 ( V_34 ) ;
F_23 ( V_34 ) ;
F_5 ( L_17 , V_4 ) ;
return V_4 ;
}
static void F_64 ( struct V_33 * V_34 )
{
F_65 ( & V_34 -> V_47 ) ;
}
static void F_66 ( struct V_33 * V_34 )
{
F_2 ( L_1 ) ;
F_50 ( V_6 , & V_34 -> V_37 ) ;
}
static int F_67 ( struct V_33 * V_34 )
{
F_2 ( L_1 ) ;
return - V_130 ;
}
static void F_68 ( struct V_131 * V_132 )
{
struct V_33 * V_34 =
F_69 ( V_132 , struct V_33 , V_37 ) ;
F_2 ( L_1 ) ;
F_23 ( V_34 ) ;
F_5 ( L_1 ) ;
}
static void V_83 ( struct V_131 * V_132 )
{
struct V_33 * V_34 =
F_69 ( V_132 , struct V_33 , V_37 ) ;
F_2 ( L_1 ) ;
if ( ! F_25 ( & V_34 -> V_38 ) )
F_51 ( V_34 ) ;
if ( V_34 -> V_72 >= V_106 && V_34 -> V_78 ) {
if ( V_34 -> V_78 -> V_133 )
V_34 -> V_78 -> V_133 ( V_34 -> V_134 ,
V_34 -> error ) ;
V_34 -> V_134 = NULL ;
F_48 ( V_34 -> V_36 ) ;
V_34 -> V_36 = NULL ;
if ( V_34 -> type -> V_94 )
V_34 -> type -> V_94 ( V_34 ) ;
F_70 ( & V_34 -> V_37 , F_68 ) ;
F_50 ( V_6 , & V_34 -> V_37 ) ;
}
F_5 ( L_1 ) ;
}
void F_71 ( struct V_33 * V_34 , struct V_30 * V_31 )
{
T_1 V_135 = V_31 -> V_135 ;
if ( F_72 ( V_31 , 0 , V_34 -> V_46 + V_34 -> V_42 , V_135 ) < 0 )
F_19 () ;
V_34 -> V_42 += V_135 ;
}
static void F_73 ( struct V_131 * V_132 )
{
struct V_79 * V_36 ;
struct V_33 * V_34 = NULL ;
struct V_30 * V_31 ;
while ( ( V_31 = F_52 ( & V_5 ) ) ) {
F_13 ( L_30 ) ;
F_21 ( V_31 ) ;
if ( ! V_34 ) {
V_34 = F_28 ( sizeof( struct V_33 ) , V_136 ) ;
if ( ! V_34 ) {
F_74 ( V_27 ) ;
return;
}
F_43 ( & V_34 -> V_37 , V_83 ) ;
V_34 -> V_78 = & V_137 ;
V_34 -> type = & V_138 ;
F_31 ( & V_34 -> V_47 ) ;
F_3 ( & V_34 -> V_38 ) ;
V_34 -> V_72 = V_101 ;
F_13 ( L_13 ,
V_34 , V_34 -> type -> V_35 ,
F_15 ( & V_29 ) ) ;
F_29 ( & V_29 ) ;
}
V_36 = F_75 ( V_27 ,
( unsigned long ) V_34 ) ;
if ( ! F_45 ( V_36 ) ) {
V_34 -> V_36 = V_36 ;
V_34 = NULL ;
}
}
if ( V_34 )
F_23 ( V_34 ) ;
}
static int F_76 ( struct V_33 * V_34 , struct V_30 * V_31 ,
bool V_60 )
{
T_1 V_135 = V_31 -> V_135 ;
void * V_139 = ( void * ) & V_34 -> V_140 ;
F_2 ( L_31 , V_34 -> V_57 , V_135 , V_60 ) ;
F_14 ( V_34 -> V_57 , < , 4 ) ;
V_135 = F_77 ( T_1 , V_135 , 4 - V_34 -> V_57 ) ;
if ( F_72 ( V_31 , 0 , V_139 + V_34 -> V_57 , V_135 ) < 0 )
F_19 () ;
if ( ! F_78 ( V_31 , V_135 ) )
F_19 () ;
V_34 -> V_57 += V_135 ;
if ( V_34 -> V_57 < 4 ) {
if ( V_60 ) {
F_5 ( L_32 ) ;
return - V_141 ;
}
F_5 ( L_33 ) ;
return 0 ;
}
V_34 -> V_72 = V_102 ;
if ( ! F_79 ( V_34 ) )
return - V_110 ;
return V_34 -> type -> V_105 ( V_34 , V_31 , V_60 ) ;
}
void F_80 ( struct V_33 * V_34 )
{
struct V_48 V_49 ;
struct V_70 V_51 [ 1 ] ;
F_2 ( L_1 ) ;
V_51 [ 0 ] . V_67 = NULL ;
V_51 [ 0 ] . V_68 = 0 ;
V_49 . V_86 = NULL ;
V_49 . V_87 = 0 ;
V_49 . V_69 = V_51 ;
V_49 . V_71 = 0 ;
V_49 . V_88 = NULL ;
V_49 . V_89 = 0 ;
V_49 . V_63 = 0 ;
V_34 -> V_72 = V_103 ;
switch ( F_37 ( V_34 -> V_36 , & V_49 , 0 ) ) {
case 0 :
F_5 ( L_34 ) ;
return;
case - V_7 :
F_13 ( L_35 ) ;
F_47 ( V_34 -> V_36 , V_93 ) ;
default:
F_48 ( V_34 -> V_36 ) ;
V_34 -> V_36 = NULL ;
V_34 -> type -> V_94 ( V_34 ) ;
F_23 ( V_34 ) ;
F_5 ( L_36 ) ;
return;
}
}
void F_81 ( struct V_33 * V_34 , const void * V_142 , T_1 V_135 )
{
struct V_48 V_49 ;
struct V_70 V_51 [ 1 ] ;
int V_55 ;
F_2 ( L_1 ) ;
V_51 [ 0 ] . V_67 = ( void * ) V_142 ;
V_51 [ 0 ] . V_68 = V_135 ;
V_49 . V_86 = NULL ;
V_49 . V_87 = 0 ;
V_49 . V_69 = V_51 ;
V_49 . V_71 = 1 ;
V_49 . V_88 = NULL ;
V_49 . V_89 = 0 ;
V_49 . V_63 = 0 ;
V_34 -> V_72 = V_103 ;
V_55 = F_37 ( V_34 -> V_36 , & V_49 , V_135 ) ;
if ( V_55 >= 0 ) {
F_5 ( L_34 ) ;
return;
}
if ( V_55 == - V_7 ) {
F_13 ( L_35 ) ;
F_47 ( V_34 -> V_36 , V_93 ) ;
}
F_48 ( V_34 -> V_36 ) ;
V_34 -> V_36 = NULL ;
V_34 -> type -> V_94 ( V_34 ) ;
F_23 ( V_34 ) ;
F_5 ( L_36 ) ;
}
int F_82 ( struct V_33 * V_34 , struct V_30 * V_31 ,
bool V_60 , void * V_142 , T_1 V_54 )
{
T_1 V_135 = V_31 -> V_135 ;
F_2 ( L_37 , V_34 -> V_57 , V_135 , V_60 , V_54 ) ;
F_14 ( V_34 -> V_57 , < , V_54 ) ;
V_135 = F_77 ( T_1 , V_135 , V_54 - V_34 -> V_57 ) ;
if ( F_72 ( V_31 , 0 , V_142 + V_34 -> V_57 , V_135 ) < 0 ||
! F_78 ( V_31 , V_135 ) )
F_19 () ;
V_34 -> V_57 += V_135 ;
if ( V_34 -> V_57 < V_54 ) {
if ( V_60 ) {
F_5 ( L_38 , V_34 -> V_57 , V_54 ) ;
return - V_141 ;
}
F_5 ( L_39 ) ;
return - V_143 ;
}
return 0 ;
}
