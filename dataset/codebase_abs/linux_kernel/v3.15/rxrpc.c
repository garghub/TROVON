static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
V_4 -> V_6 ( V_4 ) ;
}
int F_3 ( void )
{
struct V_7 V_8 ;
struct V_9 * V_9 ;
int V_10 ;
F_4 ( L_1 ) ;
F_5 ( & V_11 ) ;
V_12 = F_6 ( L_2 ) ;
if ( ! V_12 ) {
F_7 ( L_3 ) ;
return - V_13 ;
}
V_10 = F_8 ( V_14 , V_15 , V_16 , & V_9 ) ;
if ( V_10 < 0 ) {
F_9 ( V_12 ) ;
F_7 ( L_4 , V_10 ) ;
return V_10 ;
}
V_9 -> V_17 -> V_18 = V_19 ;
V_8 . V_20 = V_14 ;
V_8 . V_21 = V_22 ;
V_8 . V_23 = V_15 ;
V_8 . V_24 = sizeof( V_8 . V_25 . sin ) ;
V_8 . V_25 . sin . V_26 = V_27 ;
V_8 . V_25 . sin . V_28 = F_10 ( V_29 ) ;
memset ( & V_8 . V_25 . sin . V_30 , 0 ,
sizeof( V_8 . V_25 . sin . V_30 ) ) ;
V_10 = F_11 ( V_9 , (struct V_31 * ) & V_8 , sizeof( V_8 ) ) ;
if ( V_10 < 0 ) {
F_12 ( V_9 ) ;
F_9 ( V_12 ) ;
F_7 ( L_5 , V_10 ) ;
return V_10 ;
}
F_13 ( V_9 , V_32 ) ;
V_33 = V_9 ;
F_7 ( L_6 ) ;
return 0 ;
}
void F_14 ( void )
{
F_4 ( L_1 ) ;
F_12 ( V_33 ) ;
F_15 ( L_7 ) ;
F_9 ( V_12 ) ;
F_16 ( F_17 ( & V_34 ) , == , 0 ) ;
F_16 ( F_17 ( & V_35 ) , == , 0 ) ;
F_7 ( L_1 ) ;
}
static void F_18 ( struct V_36 * V_37 )
{
if ( ! V_37 ) {
F_15 ( L_8 , F_17 ( & V_34 ) ) ;
F_19 () ;
} else {
F_15 ( L_9 ,
V_37 , V_37 -> V_38 , F_17 ( & V_34 ) ) ;
if ( F_20 ( & V_34 ) == - 1 )
F_21 () ;
F_22 ( V_37 ) ;
}
}
static void F_23 ( struct V_36 * V_37 )
{
if ( ! V_37 ) {
F_15 ( L_10 , F_17 ( & V_34 ) ) ;
F_19 () ;
} else {
F_15 ( L_11 ,
V_37 , V_37 -> V_38 , F_17 ( & V_34 ) ) ;
if ( F_20 ( & V_34 ) == - 1 )
F_21 () ;
F_24 ( V_37 ) ;
}
}
static void F_25 ( struct V_3 * V_4 )
{
F_15 ( L_12 ,
V_4 , V_4 -> type -> V_39 , F_17 ( & V_35 ) ) ;
if ( F_20 ( & V_35 ) == - 1 )
F_21 () ;
F_16 ( V_4 -> V_40 , == , NULL ) ;
ASSERT ( ! F_26 ( & V_4 -> V_5 ) ) ;
ASSERT ( F_27 ( & V_4 -> V_41 ) ) ;
ASSERT ( V_4 -> type -> V_39 != NULL ) ;
F_28 ( V_4 -> V_42 ) ;
F_28 ( V_4 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
if ( V_4 -> V_40 ) {
F_30 ( V_4 -> V_40 ) ;
V_4 -> V_40 = NULL ;
}
if ( V_4 -> type -> V_43 )
V_4 -> type -> V_43 ( V_4 ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
F_29 ( V_4 ) ;
F_25 ( V_4 ) ;
}
struct V_3 * F_32 ( const struct V_44 * type ,
T_1 V_45 , T_1 V_46 )
{
struct V_3 * V_4 ;
V_4 = F_33 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
goto V_47;
F_15 ( L_13 ,
V_4 , type -> V_39 , F_17 ( & V_35 ) ) ;
F_34 ( & V_35 ) ;
V_4 -> type = type ;
V_4 -> V_45 = V_45 ;
V_4 -> V_48 = V_46 ;
if ( V_45 ) {
V_4 -> V_42 = F_35 ( V_45 , V_19 ) ;
if ( ! V_4 -> V_42 )
goto V_49;
}
if ( V_46 ) {
V_4 -> V_50 = F_35 ( V_46 , V_19 ) ;
if ( ! V_4 -> V_50 )
goto V_49;
}
F_36 ( & V_4 -> V_51 ) ;
F_5 ( & V_4 -> V_41 ) ;
return V_4 ;
V_49:
F_25 ( V_4 ) ;
V_47:
return NULL ;
}
void F_37 ( struct V_3 * V_4 )
{
F_4 ( L_1 ) ;
F_28 ( V_4 -> V_42 ) ;
V_4 -> V_42 = NULL ;
F_28 ( V_4 -> V_50 ) ;
V_4 -> V_50 = NULL ;
}
static int F_38 ( struct V_3 * V_4 , struct V_52 * V_53 ,
struct V_54 * V_55 )
{
struct V_56 * V_57 [ 8 ] ;
unsigned V_58 , V_59 , V_60 , V_61 , V_62 ;
T_2 V_63 = V_4 -> V_63 , V_64 = V_4 -> V_64 ;
int V_10 ;
F_4 ( L_1 ) ;
V_61 = V_4 -> V_65 ;
V_4 -> V_65 = 0 ;
do {
F_15 ( L_14 , V_63 , V_64 ) ;
V_58 = V_64 - V_63 + 1 ;
if ( V_58 > F_39 ( V_57 ) )
V_58 = F_39 ( V_57 ) ;
V_59 = F_40 ( V_4 -> V_66 , V_63 , V_58 , V_57 ) ;
F_16 ( V_59 , == , V_58 ) ;
V_60 = 0 ;
do {
V_53 -> V_67 = 0 ;
V_62 = V_68 ;
if ( V_63 + V_60 >= V_64 )
V_62 = V_4 -> V_69 ;
else
V_53 -> V_67 = V_70 ;
V_55 -> V_71 = F_41 ( V_57 [ V_60 ] ) + V_61 ;
V_55 -> V_72 = V_62 - V_61 ;
V_61 = 0 ;
F_15 ( L_15 ,
V_61 , V_62 , V_53 -> V_67 ? L_16 : L_1 ) ;
V_53 -> V_73 = (struct V_74 * ) V_55 ;
V_53 -> V_75 = 1 ;
if ( V_63 + V_60 >= V_64 )
V_4 -> V_76 = V_77 ;
V_10 = F_42 ( V_4 -> V_40 , V_53 ,
V_62 - V_61 ) ;
F_43 ( V_57 [ V_60 ] ) ;
if ( V_10 < 0 )
break;
} while ( ++ V_60 < V_58 );
V_63 += V_58 ;
for ( V_60 = 0 ; V_60 < V_58 ; V_60 ++ )
F_44 ( V_57 [ V_60 ] ) ;
if ( V_10 < 0 )
break;
} while ( V_63 <= V_64 );
F_7 ( L_17 , V_10 ) ;
return V_10 ;
}
int F_45 ( struct V_78 * V_79 , struct V_3 * V_4 , T_3 V_80 ,
const struct V_81 * V_82 )
{
struct V_7 V_8 ;
struct V_83 * V_40 ;
struct V_52 V_53 ;
struct V_54 V_55 [ 1 ] ;
int V_10 ;
struct V_36 * V_37 ;
F_4 ( L_18 , V_79 -> V_84 , F_46 ( V_4 -> V_85 ) ) ;
ASSERT ( V_4 -> type != NULL ) ;
ASSERT ( V_4 -> type -> V_39 != NULL ) ;
F_15 ( L_19 ,
V_4 , V_4 -> type -> V_39 , F_47 ( V_4 -> V_86 ) ,
F_17 ( & V_35 ) ) ;
V_4 -> V_82 = V_82 ;
V_4 -> V_6 = V_87 ;
F_48 ( & V_4 -> V_5 , F_1 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_20 = V_14 ;
V_8 . V_21 = V_4 -> V_88 ;
V_8 . V_23 = V_15 ;
V_8 . V_24 = sizeof( V_8 . V_25 . sin ) ;
V_8 . V_25 . sin . V_26 = V_27 ;
V_8 . V_25 . sin . V_28 = V_4 -> V_85 ;
memcpy ( & V_8 . V_25 . sin . V_30 , V_79 , 4 ) ;
V_40 = F_49 ( V_33 , & V_8 , V_4 -> V_86 ,
( unsigned long ) V_4 , V_80 ) ;
V_4 -> V_86 = NULL ;
if ( F_50 ( V_40 ) ) {
V_10 = F_51 ( V_40 ) ;
goto V_89;
}
V_4 -> V_40 = V_40 ;
V_55 [ 0 ] . V_71 = V_4 -> V_42 ;
V_55 [ 0 ] . V_72 = V_4 -> V_45 ;
V_53 . V_90 = NULL ;
V_53 . V_91 = 0 ;
V_53 . V_73 = (struct V_74 * ) V_55 ;
V_53 . V_75 = 1 ;
V_53 . V_92 = NULL ;
V_53 . V_93 = 0 ;
V_53 . V_67 = ( V_4 -> V_94 ? V_70 : 0 ) ;
if ( ! V_4 -> V_94 )
V_4 -> V_76 = V_77 ;
V_10 = F_42 ( V_40 , & V_53 , V_4 -> V_45 ) ;
if ( V_10 < 0 )
goto V_95;
if ( V_4 -> V_94 ) {
V_10 = F_38 ( V_4 , & V_53 , V_55 ) ;
if ( V_10 < 0 )
goto V_95;
}
return V_82 -> V_96 ( V_4 ) ;
V_95:
F_52 ( V_40 , V_97 ) ;
while ( ( V_37 = F_53 ( & V_4 -> V_41 ) ) )
F_23 ( V_37 ) ;
V_89:
F_31 ( V_4 ) ;
F_7 ( L_17 , V_10 ) ;
return V_10 ;
}
static void V_32 ( struct V_98 * V_17 , unsigned long V_99 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = (struct V_3 * ) V_99 ;
F_4 ( L_20 , V_4 , V_37 -> V_38 ) ;
F_15 ( L_21 ,
V_37 , V_37 -> V_38 , F_17 ( & V_34 ) ) ;
F_16 ( V_17 , == , V_33 -> V_17 ) ;
F_34 ( & V_34 ) ;
if ( ! V_4 ) {
F_54 ( & V_11 , V_37 ) ;
F_55 ( V_100 , & V_101 ) ;
} else {
F_54 ( & V_4 -> V_41 , V_37 ) ;
V_4 -> V_82 -> V_102 ( V_4 ) ;
}
F_7 ( L_1 ) ;
}
static void F_56 ( struct V_3 * V_4 )
{
struct V_36 * V_37 ;
bool V_64 ;
T_4 V_103 ;
int V_10 ;
F_4 ( L_1 ) ;
while ( ( V_4 -> V_76 == V_77 ||
V_4 -> V_76 == V_104 ||
V_4 -> V_76 == V_105 ||
V_4 -> V_76 == V_106 ) &&
( V_37 = F_53 ( & V_4 -> V_41 ) ) ) {
switch ( V_37 -> V_38 ) {
case V_107 :
F_15 ( L_22 ) ;
V_64 = F_57 ( V_37 ) ;
V_10 = V_4 -> type -> V_108 ( V_4 , V_37 , V_64 ) ;
switch ( V_10 ) {
case 0 :
if ( V_64 &&
V_4 -> V_76 == V_77 )
V_4 -> V_76 = V_109 ;
break;
case - V_110 :
V_103 = V_111 ;
goto V_112;
case - V_113 :
V_103 = V_114 ;
goto V_112;
default:
V_103 = V_115 ;
if ( V_4 -> V_76 != V_77 )
V_103 = V_116 ;
V_112:
F_52 ( V_4 -> V_40 ,
V_103 ) ;
V_4 -> error = V_10 ;
V_4 -> V_76 = V_117 ;
break;
}
F_18 ( V_37 ) ;
V_37 = NULL ;
continue;
case V_118 :
F_15 ( L_23 ) ;
V_4 -> V_76 = V_109 ;
break;
case V_119 :
F_15 ( L_24 ) ;
V_4 -> error = - V_120 ;
V_4 -> V_76 = V_121 ;
break;
case V_122 :
V_103 = F_58 ( V_37 ) ;
V_4 -> error = V_4 -> type -> V_123 ( V_103 ) ;
V_4 -> V_76 = V_124 ;
F_15 ( L_25 , V_103 , V_4 -> error ) ;
break;
case V_125 :
V_4 -> error = - F_59 ( V_37 ) ;
V_4 -> V_76 = V_117 ;
F_15 ( L_26 , V_4 -> error ) ;
break;
case V_126 :
V_4 -> error = - F_59 ( V_37 ) ;
V_4 -> V_76 = V_117 ;
F_15 ( L_27 , V_4 -> error ) ;
break;
default:
F_21 () ;
break;
}
F_23 ( V_37 ) ;
}
if ( V_4 -> V_76 >= V_109 ) {
while ( ( V_37 = F_53 ( & V_4 -> V_41 ) ) )
F_23 ( V_37 ) ;
if ( V_4 -> V_127 )
F_31 ( V_4 ) ;
}
F_7 ( L_1 ) ;
}
static int F_60 ( struct V_3 * V_4 )
{
struct V_36 * V_37 ;
int V_10 ;
F_61 ( V_128 , V_129 ) ;
F_4 ( L_1 ) ;
F_62 ( & V_4 -> V_51 , & V_128 ) ;
for (; ; ) {
F_63 ( V_130 ) ;
if ( ! F_27 ( & V_4 -> V_41 ) ) {
F_64 ( V_131 ) ;
F_56 ( V_4 ) ;
continue;
}
V_10 = V_4 -> error ;
if ( V_4 -> V_76 >= V_109 )
break;
V_10 = - V_132 ;
if ( F_65 ( V_129 ) )
break;
F_66 () ;
}
F_67 ( & V_4 -> V_51 , & V_128 ) ;
F_64 ( V_131 ) ;
if ( V_4 -> V_76 < V_109 ) {
F_15 ( L_28 ) ;
F_52 ( V_4 -> V_40 , V_111 ) ;
while ( ( V_37 = F_53 ( & V_4 -> V_41 ) ) )
F_23 ( V_37 ) ;
}
F_15 ( L_29 ) ;
F_31 ( V_4 ) ;
F_7 ( L_17 , V_10 ) ;
return V_10 ;
}
static void F_68 ( struct V_3 * V_4 )
{
F_69 ( & V_4 -> V_51 ) ;
}
static void F_70 ( struct V_3 * V_4 )
{
F_4 ( L_1 ) ;
F_55 ( V_12 , & V_4 -> V_5 ) ;
}
static int F_71 ( struct V_3 * V_4 )
{
F_4 ( L_1 ) ;
return - V_133 ;
}
static void F_72 ( struct V_3 * V_4 )
{
F_4 ( L_1 ) ;
F_25 ( V_4 ) ;
F_7 ( L_1 ) ;
}
static void V_87 ( struct V_3 * V_4 )
{
F_4 ( L_1 ) ;
if ( ! F_27 ( & V_4 -> V_41 ) )
F_56 ( V_4 ) ;
if ( V_4 -> V_76 >= V_109 && V_4 -> V_82 ) {
if ( V_4 -> V_82 -> V_134 )
V_4 -> V_82 -> V_134 ( V_4 -> V_135 ,
V_4 -> error ) ;
V_4 -> V_135 = NULL ;
F_29 ( V_4 ) ;
V_4 -> V_6 = F_72 ;
F_55 ( V_12 , & V_4 -> V_5 ) ;
}
F_7 ( L_1 ) ;
}
void F_73 ( struct V_3 * V_4 , struct V_36 * V_37 )
{
T_1 V_136 = V_37 -> V_136 ;
if ( F_74 ( V_37 , 0 , V_4 -> V_50 + V_4 -> V_46 , V_136 ) < 0 )
F_21 () ;
V_4 -> V_46 += V_136 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_83 * V_40 ;
struct V_3 * V_4 = NULL ;
struct V_36 * V_37 ;
while ( ( V_37 = F_53 ( & V_11 ) ) ) {
F_15 ( L_30 ) ;
F_23 ( V_37 ) ;
if ( ! V_4 ) {
V_4 = F_33 ( sizeof( struct V_3 ) , V_137 ) ;
if ( ! V_4 ) {
F_76 ( V_33 ) ;
return;
}
V_4 -> V_6 = V_87 ;
F_48 ( & V_4 -> V_5 , F_1 ) ;
V_4 -> V_82 = & V_138 ;
V_4 -> type = & V_139 ;
F_36 ( & V_4 -> V_51 ) ;
F_5 ( & V_4 -> V_41 ) ;
V_4 -> V_76 = V_104 ;
F_15 ( L_13 ,
V_4 , V_4 -> type -> V_39 ,
F_17 ( & V_35 ) ) ;
F_34 ( & V_35 ) ;
}
V_40 = F_77 ( V_33 ,
( unsigned long ) V_4 ) ;
if ( ! F_50 ( V_40 ) ) {
V_4 -> V_40 = V_40 ;
V_4 = NULL ;
}
}
if ( V_4 )
F_25 ( V_4 ) ;
}
static int F_78 ( struct V_3 * V_4 , struct V_36 * V_37 ,
bool V_64 )
{
T_1 V_136 = V_37 -> V_136 ;
void * V_140 = ( void * ) & V_4 -> V_141 ;
F_4 ( L_31 , V_4 -> V_61 , V_136 , V_64 ) ;
F_16 ( V_4 -> V_61 , < , 4 ) ;
V_136 = F_79 ( T_1 , V_136 , 4 - V_4 -> V_61 ) ;
if ( F_74 ( V_37 , 0 , V_140 + V_4 -> V_61 , V_136 ) < 0 )
F_21 () ;
if ( ! F_80 ( V_37 , V_136 ) )
F_21 () ;
V_4 -> V_61 += V_136 ;
if ( V_4 -> V_61 < 4 ) {
if ( V_64 ) {
F_7 ( L_32 ) ;
return - V_142 ;
}
F_7 ( L_33 ) ;
return 0 ;
}
V_4 -> V_76 = V_105 ;
if ( ! F_81 ( V_4 ) )
return - V_113 ;
return V_4 -> type -> V_108 ( V_4 , V_37 , V_64 ) ;
}
void F_82 ( struct V_3 * V_4 )
{
struct V_52 V_53 ;
struct V_74 V_55 [ 1 ] ;
F_4 ( L_1 ) ;
V_55 [ 0 ] . V_71 = NULL ;
V_55 [ 0 ] . V_72 = 0 ;
V_53 . V_90 = NULL ;
V_53 . V_91 = 0 ;
V_53 . V_73 = V_55 ;
V_53 . V_75 = 0 ;
V_53 . V_92 = NULL ;
V_53 . V_93 = 0 ;
V_53 . V_67 = 0 ;
V_4 -> V_76 = V_106 ;
switch ( F_42 ( V_4 -> V_40 , & V_53 , 0 ) ) {
case 0 :
F_7 ( L_34 ) ;
return;
case - V_13 :
F_15 ( L_35 ) ;
F_52 ( V_4 -> V_40 , V_97 ) ;
default:
F_31 ( V_4 ) ;
F_7 ( L_36 ) ;
return;
}
}
void F_83 ( struct V_3 * V_4 , const void * V_143 , T_1 V_136 )
{
struct V_52 V_53 ;
struct V_74 V_55 [ 1 ] ;
int V_59 ;
F_4 ( L_1 ) ;
V_55 [ 0 ] . V_71 = ( void * ) V_143 ;
V_55 [ 0 ] . V_72 = V_136 ;
V_53 . V_90 = NULL ;
V_53 . V_91 = 0 ;
V_53 . V_73 = V_55 ;
V_53 . V_75 = 1 ;
V_53 . V_92 = NULL ;
V_53 . V_93 = 0 ;
V_53 . V_67 = 0 ;
V_4 -> V_76 = V_106 ;
V_59 = F_42 ( V_4 -> V_40 , & V_53 , V_136 ) ;
if ( V_59 >= 0 ) {
F_7 ( L_34 ) ;
return;
}
if ( V_59 == - V_13 ) {
F_15 ( L_35 ) ;
F_52 ( V_4 -> V_40 , V_97 ) ;
}
F_31 ( V_4 ) ;
F_7 ( L_36 ) ;
}
int F_84 ( struct V_3 * V_4 , struct V_36 * V_37 ,
bool V_64 , void * V_143 , T_1 V_58 )
{
T_1 V_136 = V_37 -> V_136 ;
F_4 ( L_37 , V_4 -> V_61 , V_136 , V_64 , V_58 ) ;
F_16 ( V_4 -> V_61 , < , V_58 ) ;
V_136 = F_79 ( T_1 , V_136 , V_58 - V_4 -> V_61 ) ;
if ( F_74 ( V_37 , 0 , V_143 + V_4 -> V_61 , V_136 ) < 0 ||
! F_80 ( V_37 , V_136 ) )
F_21 () ;
V_4 -> V_61 += V_136 ;
if ( V_4 -> V_61 < V_58 ) {
if ( V_64 ) {
F_7 ( L_38 , V_4 -> V_61 , V_58 ) ;
return - V_142 ;
}
F_7 ( L_39 ) ;
return - V_144 ;
}
return 0 ;
}
