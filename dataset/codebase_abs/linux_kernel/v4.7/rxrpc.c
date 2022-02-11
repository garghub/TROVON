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
V_13 = F_8 ( L_2 ) ;
if ( ! V_13 ) {
F_9 ( L_3 ) ;
return - V_14 ;
}
V_11 = F_10 ( & V_15 , V_16 , V_17 , V_18 , & V_10 ) ;
if ( V_11 < 0 ) {
F_11 ( V_13 ) ;
F_9 ( L_4 , V_11 ) ;
return V_11 ;
}
V_10 -> V_19 -> V_20 = V_21 ;
V_9 . V_22 = V_16 ;
V_9 . V_23 = V_24 ;
V_9 . V_25 = V_17 ;
V_9 . V_26 = sizeof( V_9 . V_27 . sin ) ;
V_9 . V_27 . sin . V_28 = V_29 ;
V_9 . V_27 . sin . V_30 = F_12 ( V_31 ) ;
memset ( & V_9 . V_27 . sin . V_32 , 0 ,
sizeof( V_9 . V_27 . sin . V_32 ) ) ;
V_11 = F_13 ( V_10 , (struct V_33 * ) & V_9 , sizeof( V_9 ) ) ;
if ( V_11 < 0 ) {
F_14 ( V_10 ) ;
F_11 ( V_13 ) ;
F_9 ( L_5 , V_11 ) ;
return V_11 ;
}
F_15 ( V_10 , V_34 ) ;
V_35 = V_10 ;
F_9 ( L_6 ) ;
return 0 ;
}
void F_16 ( void )
{
F_6 ( L_1 ) ;
F_17 ( & V_36 , F_3 ,
V_37 ) ;
F_18 ( L_7 ) ;
F_14 ( V_35 ) ;
F_18 ( L_8 ) ;
F_11 ( V_13 ) ;
F_19 ( F_20 ( & V_38 ) , == , 0 ) ;
F_9 ( L_1 ) ;
}
static void F_21 ( struct V_39 * V_40 )
{
if ( ! V_40 ) {
F_18 ( L_9 , F_20 ( & V_38 ) ) ;
F_22 () ;
} else {
F_18 ( L_10 ,
V_40 , V_40 -> V_41 , F_20 ( & V_38 ) ) ;
if ( F_23 ( & V_38 ) == - 1 )
F_24 () ;
F_25 ( V_40 ) ;
}
}
static void F_26 ( struct V_39 * V_40 )
{
if ( ! V_40 ) {
F_18 ( L_11 , F_20 ( & V_38 ) ) ;
F_22 () ;
} else {
F_18 ( L_12 ,
V_40 , V_40 -> V_41 , F_20 ( & V_38 ) ) ;
if ( F_23 ( & V_38 ) == - 1 )
F_24 () ;
F_27 ( V_40 ) ;
}
}
static void F_28 ( struct V_3 * V_4 )
{
F_18 ( L_13 ,
V_4 , V_4 -> type -> V_42 , F_20 ( & V_36 ) ) ;
F_19 ( V_4 -> V_43 , == , NULL ) ;
ASSERT ( ! F_29 ( & V_4 -> V_5 ) ) ;
ASSERT ( F_30 ( & V_4 -> V_44 ) ) ;
ASSERT ( V_4 -> type -> V_42 != NULL ) ;
F_31 ( V_4 -> V_45 ) ;
F_31 ( V_4 ) ;
if ( F_32 ( & V_36 ) )
F_33 ( & V_36 ) ;
}
static void F_34 ( struct V_3 * V_4 )
{
if ( V_4 -> V_43 ) {
F_35 ( V_4 -> V_43 ) ;
V_4 -> V_43 = NULL ;
}
if ( V_4 -> type -> V_46 )
V_4 -> type -> V_46 ( V_4 ) ;
}
static void F_36 ( struct V_3 * V_4 )
{
F_34 ( V_4 ) ;
F_28 ( V_4 ) ;
}
struct V_3 * F_37 ( const struct V_47 * type ,
T_2 V_48 , T_2 V_49 )
{
struct V_3 * V_4 ;
V_4 = F_38 ( sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 )
goto V_50;
F_18 ( L_14 ,
V_4 , type -> V_42 , F_20 ( & V_36 ) ) ;
F_39 ( & V_36 ) ;
V_4 -> type = type ;
V_4 -> V_48 = V_48 ;
V_4 -> V_51 = V_49 ;
if ( V_48 ) {
V_4 -> V_45 = F_40 ( V_48 , V_21 ) ;
if ( ! V_4 -> V_45 )
goto V_52;
}
if ( V_49 ) {
V_4 -> V_53 = F_40 ( V_49 , V_21 ) ;
if ( ! V_4 -> V_53 )
goto V_52;
}
F_41 ( & V_4 -> V_54 ) ;
F_7 ( & V_4 -> V_44 ) ;
return V_4 ;
V_52:
F_28 ( V_4 ) ;
V_50:
return NULL ;
}
void F_42 ( struct V_3 * V_4 )
{
F_6 ( L_1 ) ;
F_31 ( V_4 -> V_45 ) ;
V_4 -> V_45 = NULL ;
F_31 ( V_4 -> V_53 ) ;
V_4 -> V_53 = NULL ;
}
static int F_43 ( struct V_3 * V_4 , struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 [ 8 ] ;
unsigned V_61 , V_62 , V_63 , V_64 , V_65 ;
T_3 V_66 = V_4 -> V_66 , V_67 = V_4 -> V_67 ;
int V_11 ;
F_6 ( L_1 ) ;
V_64 = V_4 -> V_68 ;
V_4 -> V_68 = 0 ;
do {
F_18 ( L_15 , V_66 , V_67 ) ;
V_61 = V_67 - V_66 + 1 ;
if ( V_61 > F_44 ( V_60 ) )
V_61 = F_44 ( V_60 ) ;
V_62 = F_45 ( V_4 -> V_69 , V_66 , V_61 , V_60 ) ;
F_19 ( V_62 , == , V_61 ) ;
V_63 = 0 ;
do {
V_56 -> V_70 = 0 ;
V_65 = V_71 ;
if ( V_66 + V_63 >= V_67 )
V_65 = V_4 -> V_72 ;
else
V_56 -> V_70 = V_73 ;
V_58 -> V_74 = F_46 ( V_60 [ V_63 ] ) + V_64 ;
V_58 -> V_75 = V_65 - V_64 ;
V_64 = 0 ;
F_18 ( L_16 ,
V_64 , V_65 , V_56 -> V_70 ? L_17 : L_1 ) ;
F_47 ( & V_56 -> V_76 , V_77 | V_78 ,
V_58 , 1 , V_65 - V_64 ) ;
if ( V_66 + V_63 >= V_67 )
V_4 -> V_79 = V_80 ;
V_11 = F_48 ( V_4 -> V_43 , V_56 ,
V_65 - V_64 ) ;
F_49 ( V_60 [ V_63 ] ) ;
if ( V_11 < 0 )
break;
} while ( ++ V_63 < V_61 );
V_66 += V_61 ;
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ )
F_50 ( V_60 [ V_63 ] ) ;
if ( V_11 < 0 )
break;
} while ( V_66 <= V_67 );
F_9 ( L_18 , V_11 ) ;
return V_11 ;
}
int F_51 ( struct V_81 * V_82 , struct V_3 * V_4 , T_4 V_83 ,
const struct V_84 * V_85 )
{
struct V_8 V_9 ;
struct V_86 * V_43 ;
struct V_55 V_56 ;
struct V_57 V_58 [ 1 ] ;
int V_11 ;
struct V_39 * V_40 ;
F_6 ( L_19 , V_82 -> V_87 , F_52 ( V_4 -> V_88 ) ) ;
ASSERT ( V_4 -> type != NULL ) ;
ASSERT ( V_4 -> type -> V_42 != NULL ) ;
F_18 ( L_20 ,
V_4 , V_4 -> type -> V_42 , F_53 ( V_4 -> V_89 ) ,
F_20 ( & V_36 ) ) ;
V_4 -> V_85 = V_85 ;
V_4 -> V_6 = V_90 ;
F_54 ( & V_4 -> V_5 , F_1 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_22 = V_16 ;
V_9 . V_23 = V_4 -> V_91 ;
V_9 . V_25 = V_17 ;
V_9 . V_26 = sizeof( V_9 . V_27 . sin ) ;
V_9 . V_27 . sin . V_28 = V_29 ;
V_9 . V_27 . sin . V_30 = V_4 -> V_88 ;
memcpy ( & V_9 . V_27 . sin . V_32 , V_82 , 4 ) ;
V_43 = F_55 ( V_35 , & V_9 , V_4 -> V_89 ,
( unsigned long ) V_4 , V_83 ) ;
V_4 -> V_89 = NULL ;
if ( F_56 ( V_43 ) ) {
V_11 = F_57 ( V_43 ) ;
goto V_92;
}
V_4 -> V_43 = V_43 ;
V_58 [ 0 ] . V_74 = V_4 -> V_45 ;
V_58 [ 0 ] . V_75 = V_4 -> V_48 ;
V_56 . V_93 = NULL ;
V_56 . V_94 = 0 ;
F_47 ( & V_56 . V_76 , V_77 | V_78 , V_58 , 1 ,
V_4 -> V_48 ) ;
V_56 . V_95 = NULL ;
V_56 . V_96 = 0 ;
V_56 . V_70 = ( V_4 -> V_97 ? V_73 : 0 ) ;
if ( ! V_4 -> V_97 )
V_4 -> V_79 = V_80 ;
V_11 = F_48 ( V_43 , & V_56 , V_4 -> V_48 ) ;
if ( V_11 < 0 )
goto V_98;
if ( V_4 -> V_97 ) {
V_11 = F_43 ( V_4 , & V_56 , V_58 ) ;
if ( V_11 < 0 )
goto V_98;
}
return V_85 -> V_99 ( V_4 ) ;
V_98:
F_58 ( V_43 , V_100 ) ;
while ( ( V_40 = F_59 ( & V_4 -> V_44 ) ) )
F_26 ( V_40 ) ;
V_92:
F_36 ( V_4 ) ;
F_9 ( L_18 , V_11 ) ;
return V_11 ;
}
static void V_34 ( struct V_101 * V_19 , unsigned long V_102 ,
struct V_39 * V_40 )
{
struct V_3 * V_4 = (struct V_3 * ) V_102 ;
F_6 ( L_21 , V_4 , V_40 -> V_41 ) ;
F_18 ( L_22 ,
V_40 , V_40 -> V_41 , F_20 ( & V_38 ) ) ;
F_19 ( V_19 , == , V_35 -> V_19 ) ;
F_39 ( & V_38 ) ;
if ( ! V_4 ) {
F_60 ( & V_12 , V_40 ) ;
F_61 ( V_103 , & V_104 ) ;
} else {
F_60 ( & V_4 -> V_44 , V_40 ) ;
V_4 -> V_85 -> V_105 ( V_4 ) ;
}
F_9 ( L_1 ) ;
}
static void F_62 ( struct V_3 * V_4 )
{
struct V_39 * V_40 ;
bool V_67 ;
T_5 V_106 ;
int V_11 ;
F_6 ( L_1 ) ;
while ( ( V_4 -> V_79 == V_80 ||
V_4 -> V_79 == V_107 ||
V_4 -> V_79 == V_108 ||
V_4 -> V_79 == V_109 ) &&
( V_40 = F_59 ( & V_4 -> V_44 ) ) ) {
switch ( V_40 -> V_41 ) {
case V_110 :
F_18 ( L_23 ) ;
V_67 = F_63 ( V_40 ) ;
V_11 = V_4 -> type -> V_111 ( V_4 , V_40 , V_67 ) ;
switch ( V_11 ) {
case 0 :
if ( V_67 &&
V_4 -> V_79 == V_80 )
V_4 -> V_79 = V_112 ;
break;
case - V_113 :
V_106 = V_114 ;
goto V_115;
case - V_116 :
V_106 = V_117 ;
goto V_115;
default:
V_106 = V_118 ;
if ( V_4 -> V_79 != V_80 )
V_106 = V_119 ;
V_115:
F_58 ( V_4 -> V_43 ,
V_106 ) ;
V_4 -> error = V_11 ;
V_4 -> V_79 = V_120 ;
break;
}
F_21 ( V_40 ) ;
V_40 = NULL ;
continue;
case V_121 :
F_18 ( L_24 ) ;
V_4 -> V_79 = V_112 ;
break;
case V_122 :
F_18 ( L_25 ) ;
V_4 -> error = - V_123 ;
V_4 -> V_79 = V_124 ;
break;
case V_125 :
V_106 = F_64 ( V_40 ) ;
V_4 -> error = V_4 -> type -> V_126 ( V_106 ) ;
V_4 -> V_79 = V_127 ;
F_18 ( L_26 , V_106 , V_4 -> error ) ;
break;
case V_128 :
V_106 = F_64 ( V_40 ) ;
V_4 -> error = V_4 -> type -> V_126 ( V_106 ) ;
V_4 -> V_79 = V_127 ;
F_18 ( L_27 , V_106 , V_4 -> error ) ;
break;
case V_129 :
V_4 -> error = - F_65 ( V_40 ) ;
V_4 -> V_79 = V_120 ;
F_18 ( L_28 , V_4 -> error ) ;
break;
case V_130 :
V_4 -> error = - F_65 ( V_40 ) ;
V_4 -> V_79 = V_120 ;
F_18 ( L_29 , V_4 -> error ) ;
break;
default:
F_24 () ;
break;
}
F_26 ( V_40 ) ;
}
if ( V_4 -> V_79 >= V_112 ) {
while ( ( V_40 = F_59 ( & V_4 -> V_44 ) ) )
F_26 ( V_40 ) ;
if ( V_4 -> V_131 )
F_36 ( V_4 ) ;
}
F_9 ( L_1 ) ;
}
static int F_66 ( struct V_3 * V_4 )
{
struct V_39 * V_40 ;
int V_11 ;
F_67 ( V_132 , V_133 ) ;
F_6 ( L_1 ) ;
F_68 ( & V_4 -> V_54 , & V_132 ) ;
for (; ; ) {
F_69 ( V_134 ) ;
if ( ! F_30 ( & V_4 -> V_44 ) ) {
F_70 ( V_135 ) ;
F_62 ( V_4 ) ;
continue;
}
V_11 = V_4 -> error ;
if ( V_4 -> V_79 >= V_112 )
break;
V_11 = - V_136 ;
if ( F_71 ( V_133 ) )
break;
F_4 () ;
}
F_72 ( & V_4 -> V_54 , & V_132 ) ;
F_70 ( V_135 ) ;
if ( V_4 -> V_79 < V_112 ) {
F_18 ( L_30 ) ;
F_58 ( V_4 -> V_43 , V_114 ) ;
while ( ( V_40 = F_59 ( & V_4 -> V_44 ) ) )
F_26 ( V_40 ) ;
}
F_18 ( L_31 ) ;
F_36 ( V_4 ) ;
F_9 ( L_18 , V_11 ) ;
return V_11 ;
}
static void F_73 ( struct V_3 * V_4 )
{
F_74 ( & V_4 -> V_54 ) ;
}
static void F_75 ( struct V_3 * V_4 )
{
F_6 ( L_1 ) ;
F_61 ( V_13 , & V_4 -> V_5 ) ;
}
static int F_76 ( struct V_3 * V_4 )
{
F_6 ( L_1 ) ;
return - V_137 ;
}
static void F_77 ( struct V_3 * V_4 )
{
F_6 ( L_1 ) ;
F_28 ( V_4 ) ;
F_9 ( L_1 ) ;
}
static void V_90 ( struct V_3 * V_4 )
{
F_6 ( L_1 ) ;
if ( ! F_30 ( & V_4 -> V_44 ) )
F_62 ( V_4 ) ;
if ( V_4 -> V_79 >= V_112 && V_4 -> V_85 ) {
if ( V_4 -> V_85 -> V_138 )
V_4 -> V_85 -> V_138 ( V_4 -> V_139 ,
V_4 -> error ) ;
V_4 -> V_139 = NULL ;
F_34 ( V_4 ) ;
V_4 -> V_6 = F_77 ;
F_61 ( V_13 , & V_4 -> V_5 ) ;
}
F_9 ( L_1 ) ;
}
void F_78 ( struct V_3 * V_4 , struct V_39 * V_40 )
{
T_2 V_140 = V_40 -> V_140 ;
if ( F_79 ( V_40 , 0 , V_4 -> V_53 + V_4 -> V_49 , V_140 ) < 0 )
F_24 () ;
V_4 -> V_49 += V_140 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_86 * V_43 ;
struct V_3 * V_4 = NULL ;
struct V_39 * V_40 ;
while ( ( V_40 = F_59 ( & V_12 ) ) ) {
F_18 ( L_32 ) ;
F_26 ( V_40 ) ;
if ( ! V_4 ) {
V_4 = F_38 ( sizeof( struct V_3 ) , V_141 ) ;
if ( ! V_4 ) {
F_81 ( V_35 ) ;
return;
}
V_4 -> V_6 = V_90 ;
F_54 ( & V_4 -> V_5 , F_1 ) ;
V_4 -> V_85 = & V_142 ;
V_4 -> type = & V_143 ;
F_41 ( & V_4 -> V_54 ) ;
F_7 ( & V_4 -> V_44 ) ;
V_4 -> V_79 = V_107 ;
F_18 ( L_14 ,
V_4 , V_4 -> type -> V_42 ,
F_20 ( & V_36 ) ) ;
F_39 ( & V_36 ) ;
}
V_43 = F_82 ( V_35 ,
( unsigned long ) V_4 ) ;
if ( ! F_56 ( V_43 ) ) {
V_4 -> V_43 = V_43 ;
V_4 = NULL ;
}
}
if ( V_4 )
F_28 ( V_4 ) ;
}
static int F_83 ( struct V_3 * V_4 , struct V_39 * V_40 ,
bool V_67 )
{
T_2 V_140 = V_40 -> V_140 ;
void * V_144 = ( void * ) & V_4 -> V_145 ;
F_6 ( L_33 , V_4 -> V_64 , V_140 , V_67 ) ;
F_19 ( V_4 -> V_64 , < , 4 ) ;
V_140 = F_84 ( T_2 , V_140 , 4 - V_4 -> V_64 ) ;
if ( F_79 ( V_40 , 0 , V_144 + V_4 -> V_64 , V_140 ) < 0 )
F_24 () ;
if ( ! F_85 ( V_40 , V_140 ) )
F_24 () ;
V_4 -> V_64 += V_140 ;
if ( V_4 -> V_64 < 4 ) {
if ( V_67 ) {
F_9 ( L_34 ) ;
return - V_146 ;
}
F_9 ( L_35 ) ;
return 0 ;
}
V_4 -> V_79 = V_108 ;
if ( ! F_86 ( V_4 ) )
return - V_116 ;
return V_4 -> type -> V_111 ( V_4 , V_40 , V_67 ) ;
}
void F_87 ( struct V_3 * V_4 )
{
struct V_55 V_56 ;
F_6 ( L_1 ) ;
V_56 . V_93 = NULL ;
V_56 . V_94 = 0 ;
F_47 ( & V_56 . V_76 , V_77 | V_78 , NULL , 0 , 0 ) ;
V_56 . V_95 = NULL ;
V_56 . V_96 = 0 ;
V_56 . V_70 = 0 ;
V_4 -> V_79 = V_109 ;
switch ( F_48 ( V_4 -> V_43 , & V_56 , 0 ) ) {
case 0 :
F_9 ( L_36 ) ;
return;
case - V_14 :
F_18 ( L_37 ) ;
F_58 ( V_4 -> V_43 , V_100 ) ;
default:
F_36 ( V_4 ) ;
F_9 ( L_38 ) ;
return;
}
}
void F_88 ( struct V_3 * V_4 , const void * V_147 , T_2 V_140 )
{
struct V_55 V_56 ;
struct V_57 V_58 [ 1 ] ;
int V_62 ;
F_6 ( L_1 ) ;
V_58 [ 0 ] . V_74 = ( void * ) V_147 ;
V_58 [ 0 ] . V_75 = V_140 ;
V_56 . V_93 = NULL ;
V_56 . V_94 = 0 ;
F_47 ( & V_56 . V_76 , V_77 | V_78 , V_58 , 1 , V_140 ) ;
V_56 . V_95 = NULL ;
V_56 . V_96 = 0 ;
V_56 . V_70 = 0 ;
V_4 -> V_79 = V_109 ;
V_62 = F_48 ( V_4 -> V_43 , & V_56 , V_140 ) ;
if ( V_62 >= 0 ) {
F_9 ( L_36 ) ;
return;
}
if ( V_62 == - V_14 ) {
F_18 ( L_37 ) ;
F_58 ( V_4 -> V_43 , V_100 ) ;
}
F_36 ( V_4 ) ;
F_9 ( L_38 ) ;
}
int F_89 ( struct V_3 * V_4 , struct V_39 * V_40 ,
bool V_67 , void * V_147 , T_2 V_61 )
{
T_2 V_140 = V_40 -> V_140 ;
F_6 ( L_39 , V_4 -> V_64 , V_140 , V_67 , V_61 ) ;
F_19 ( V_4 -> V_64 , < , V_61 ) ;
V_140 = F_84 ( T_2 , V_140 , V_61 - V_4 -> V_64 ) ;
if ( F_79 ( V_40 , 0 , V_147 + V_4 -> V_64 , V_140 ) < 0 ||
! F_85 ( V_40 , V_140 ) )
F_24 () ;
V_4 -> V_64 += V_140 ;
if ( V_4 -> V_64 < V_61 ) {
if ( V_67 ) {
F_9 ( L_40 , V_4 -> V_64 , V_61 ) ;
return - V_146 ;
}
F_9 ( L_41 ) ;
return - V_148 ;
}
return 0 ;
}
