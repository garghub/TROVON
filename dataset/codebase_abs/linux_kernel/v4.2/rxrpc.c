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
V_10 = F_8 ( & V_14 , V_15 , V_16 , V_17 , & V_9 ) ;
if ( V_10 < 0 ) {
F_9 ( V_12 ) ;
F_7 ( L_4 , V_10 ) ;
return V_10 ;
}
V_9 -> V_18 -> V_19 = V_20 ;
V_8 . V_21 = V_15 ;
V_8 . V_22 = V_23 ;
V_8 . V_24 = V_16 ;
V_8 . V_25 = sizeof( V_8 . V_26 . sin ) ;
V_8 . V_26 . sin . V_27 = V_28 ;
V_8 . V_26 . sin . V_29 = F_10 ( V_30 ) ;
memset ( & V_8 . V_26 . sin . V_31 , 0 ,
sizeof( V_8 . V_26 . sin . V_31 ) ) ;
V_10 = F_11 ( V_9 , (struct V_32 * ) & V_8 , sizeof( V_8 ) ) ;
if ( V_10 < 0 ) {
F_12 ( V_9 ) ;
F_9 ( V_12 ) ;
F_7 ( L_5 , V_10 ) ;
return V_10 ;
}
F_13 ( V_9 , V_33 ) ;
V_34 = V_9 ;
F_7 ( L_6 ) ;
return 0 ;
}
void F_14 ( void )
{
F_4 ( L_1 ) ;
F_12 ( V_34 ) ;
F_15 ( L_7 ) ;
F_9 ( V_12 ) ;
F_16 ( F_17 ( & V_35 ) , == , 0 ) ;
F_16 ( F_17 ( & V_36 ) , == , 0 ) ;
F_7 ( L_1 ) ;
}
static void F_18 ( struct V_37 * V_38 )
{
if ( ! V_38 ) {
F_15 ( L_8 , F_17 ( & V_35 ) ) ;
F_19 () ;
} else {
F_15 ( L_9 ,
V_38 , V_38 -> V_39 , F_17 ( & V_35 ) ) ;
if ( F_20 ( & V_35 ) == - 1 )
F_21 () ;
F_22 ( V_38 ) ;
}
}
static void F_23 ( struct V_37 * V_38 )
{
if ( ! V_38 ) {
F_15 ( L_10 , F_17 ( & V_35 ) ) ;
F_19 () ;
} else {
F_15 ( L_11 ,
V_38 , V_38 -> V_39 , F_17 ( & V_35 ) ) ;
if ( F_20 ( & V_35 ) == - 1 )
F_21 () ;
F_24 ( V_38 ) ;
}
}
static void F_25 ( struct V_3 * V_4 )
{
F_15 ( L_12 ,
V_4 , V_4 -> type -> V_40 , F_17 ( & V_36 ) ) ;
if ( F_20 ( & V_36 ) == - 1 )
F_21 () ;
F_16 ( V_4 -> V_41 , == , NULL ) ;
ASSERT ( ! F_26 ( & V_4 -> V_5 ) ) ;
ASSERT ( F_27 ( & V_4 -> V_42 ) ) ;
ASSERT ( V_4 -> type -> V_40 != NULL ) ;
F_28 ( V_4 -> V_43 ) ;
F_28 ( V_4 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
if ( V_4 -> V_41 ) {
F_30 ( V_4 -> V_41 ) ;
V_4 -> V_41 = NULL ;
}
if ( V_4 -> type -> V_44 )
V_4 -> type -> V_44 ( V_4 ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
F_29 ( V_4 ) ;
F_25 ( V_4 ) ;
}
struct V_3 * F_32 ( const struct V_45 * type ,
T_1 V_46 , T_1 V_47 )
{
struct V_3 * V_4 ;
V_4 = F_33 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
goto V_48;
F_15 ( L_13 ,
V_4 , type -> V_40 , F_17 ( & V_36 ) ) ;
F_34 ( & V_36 ) ;
V_4 -> type = type ;
V_4 -> V_46 = V_46 ;
V_4 -> V_49 = V_47 ;
if ( V_46 ) {
V_4 -> V_43 = F_35 ( V_46 , V_20 ) ;
if ( ! V_4 -> V_43 )
goto V_50;
}
if ( V_47 ) {
V_4 -> V_51 = F_35 ( V_47 , V_20 ) ;
if ( ! V_4 -> V_51 )
goto V_50;
}
F_36 ( & V_4 -> V_52 ) ;
F_5 ( & V_4 -> V_42 ) ;
return V_4 ;
V_50:
F_25 ( V_4 ) ;
V_48:
return NULL ;
}
void F_37 ( struct V_3 * V_4 )
{
F_4 ( L_1 ) ;
F_28 ( V_4 -> V_43 ) ;
V_4 -> V_43 = NULL ;
F_28 ( V_4 -> V_51 ) ;
V_4 -> V_51 = NULL ;
}
static int F_38 ( struct V_3 * V_4 , struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_57 * V_58 [ 8 ] ;
unsigned V_59 , V_60 , V_61 , V_62 , V_63 ;
T_2 V_64 = V_4 -> V_64 , V_65 = V_4 -> V_65 ;
int V_10 ;
F_4 ( L_1 ) ;
V_62 = V_4 -> V_66 ;
V_4 -> V_66 = 0 ;
do {
F_15 ( L_14 , V_64 , V_65 ) ;
V_59 = V_65 - V_64 + 1 ;
if ( V_59 > F_39 ( V_58 ) )
V_59 = F_39 ( V_58 ) ;
V_60 = F_40 ( V_4 -> V_67 , V_64 , V_59 , V_58 ) ;
F_16 ( V_60 , == , V_59 ) ;
V_61 = 0 ;
do {
V_54 -> V_68 = 0 ;
V_63 = V_69 ;
if ( V_64 + V_61 >= V_65 )
V_63 = V_4 -> V_70 ;
else
V_54 -> V_68 = V_71 ;
V_56 -> V_72 = F_41 ( V_58 [ V_61 ] ) + V_62 ;
V_56 -> V_73 = V_63 - V_62 ;
V_62 = 0 ;
F_15 ( L_15 ,
V_62 , V_63 , V_54 -> V_68 ? L_16 : L_1 ) ;
F_42 ( & V_54 -> V_74 , V_75 | V_76 ,
V_56 , 1 , V_63 - V_62 ) ;
if ( V_64 + V_61 >= V_65 )
V_4 -> V_77 = V_78 ;
V_10 = F_43 ( V_4 -> V_41 , V_54 ,
V_63 - V_62 ) ;
F_44 ( V_58 [ V_61 ] ) ;
if ( V_10 < 0 )
break;
} while ( ++ V_61 < V_59 );
V_64 += V_59 ;
for ( V_61 = 0 ; V_61 < V_59 ; V_61 ++ )
F_45 ( V_58 [ V_61 ] ) ;
if ( V_10 < 0 )
break;
} while ( V_64 <= V_65 );
F_7 ( L_17 , V_10 ) ;
return V_10 ;
}
int F_46 ( struct V_79 * V_80 , struct V_3 * V_4 , T_3 V_81 ,
const struct V_82 * V_83 )
{
struct V_7 V_8 ;
struct V_84 * V_41 ;
struct V_53 V_54 ;
struct V_55 V_56 [ 1 ] ;
int V_10 ;
struct V_37 * V_38 ;
F_4 ( L_18 , V_80 -> V_85 , F_47 ( V_4 -> V_86 ) ) ;
ASSERT ( V_4 -> type != NULL ) ;
ASSERT ( V_4 -> type -> V_40 != NULL ) ;
F_15 ( L_19 ,
V_4 , V_4 -> type -> V_40 , F_48 ( V_4 -> V_87 ) ,
F_17 ( & V_36 ) ) ;
V_4 -> V_83 = V_83 ;
V_4 -> V_6 = V_88 ;
F_49 ( & V_4 -> V_5 , F_1 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_21 = V_15 ;
V_8 . V_22 = V_4 -> V_89 ;
V_8 . V_24 = V_16 ;
V_8 . V_25 = sizeof( V_8 . V_26 . sin ) ;
V_8 . V_26 . sin . V_27 = V_28 ;
V_8 . V_26 . sin . V_29 = V_4 -> V_86 ;
memcpy ( & V_8 . V_26 . sin . V_31 , V_80 , 4 ) ;
V_41 = F_50 ( V_34 , & V_8 , V_4 -> V_87 ,
( unsigned long ) V_4 , V_81 ) ;
V_4 -> V_87 = NULL ;
if ( F_51 ( V_41 ) ) {
V_10 = F_52 ( V_41 ) ;
goto V_90;
}
V_4 -> V_41 = V_41 ;
V_56 [ 0 ] . V_72 = V_4 -> V_43 ;
V_56 [ 0 ] . V_73 = V_4 -> V_46 ;
V_54 . V_91 = NULL ;
V_54 . V_92 = 0 ;
F_42 ( & V_54 . V_74 , V_75 | V_76 , V_56 , 1 ,
V_4 -> V_46 ) ;
V_54 . V_93 = NULL ;
V_54 . V_94 = 0 ;
V_54 . V_68 = ( V_4 -> V_95 ? V_71 : 0 ) ;
if ( ! V_4 -> V_95 )
V_4 -> V_77 = V_78 ;
V_10 = F_43 ( V_41 , & V_54 , V_4 -> V_46 ) ;
if ( V_10 < 0 )
goto V_96;
if ( V_4 -> V_95 ) {
V_10 = F_38 ( V_4 , & V_54 , V_56 ) ;
if ( V_10 < 0 )
goto V_96;
}
return V_83 -> V_97 ( V_4 ) ;
V_96:
F_53 ( V_41 , V_98 ) ;
while ( ( V_38 = F_54 ( & V_4 -> V_42 ) ) )
F_23 ( V_38 ) ;
V_90:
F_31 ( V_4 ) ;
F_7 ( L_17 , V_10 ) ;
return V_10 ;
}
static void V_33 ( struct V_99 * V_18 , unsigned long V_100 ,
struct V_37 * V_38 )
{
struct V_3 * V_4 = (struct V_3 * ) V_100 ;
F_4 ( L_20 , V_4 , V_38 -> V_39 ) ;
F_15 ( L_21 ,
V_38 , V_38 -> V_39 , F_17 ( & V_35 ) ) ;
F_16 ( V_18 , == , V_34 -> V_18 ) ;
F_34 ( & V_35 ) ;
if ( ! V_4 ) {
F_55 ( & V_11 , V_38 ) ;
F_56 ( V_101 , & V_102 ) ;
} else {
F_55 ( & V_4 -> V_42 , V_38 ) ;
V_4 -> V_83 -> V_103 ( V_4 ) ;
}
F_7 ( L_1 ) ;
}
static void F_57 ( struct V_3 * V_4 )
{
struct V_37 * V_38 ;
bool V_65 ;
T_4 V_104 ;
int V_10 ;
F_4 ( L_1 ) ;
while ( ( V_4 -> V_77 == V_78 ||
V_4 -> V_77 == V_105 ||
V_4 -> V_77 == V_106 ||
V_4 -> V_77 == V_107 ) &&
( V_38 = F_54 ( & V_4 -> V_42 ) ) ) {
switch ( V_38 -> V_39 ) {
case V_108 :
F_15 ( L_22 ) ;
V_65 = F_58 ( V_38 ) ;
V_10 = V_4 -> type -> V_109 ( V_4 , V_38 , V_65 ) ;
switch ( V_10 ) {
case 0 :
if ( V_65 &&
V_4 -> V_77 == V_78 )
V_4 -> V_77 = V_110 ;
break;
case - V_111 :
V_104 = V_112 ;
goto V_113;
case - V_114 :
V_104 = V_115 ;
goto V_113;
default:
V_104 = V_116 ;
if ( V_4 -> V_77 != V_78 )
V_104 = V_117 ;
V_113:
F_53 ( V_4 -> V_41 ,
V_104 ) ;
V_4 -> error = V_10 ;
V_4 -> V_77 = V_118 ;
break;
}
F_18 ( V_38 ) ;
V_38 = NULL ;
continue;
case V_119 :
F_15 ( L_23 ) ;
V_4 -> V_77 = V_110 ;
break;
case V_120 :
F_15 ( L_24 ) ;
V_4 -> error = - V_121 ;
V_4 -> V_77 = V_122 ;
break;
case V_123 :
V_104 = F_59 ( V_38 ) ;
V_4 -> error = V_4 -> type -> V_124 ( V_104 ) ;
V_4 -> V_77 = V_125 ;
F_15 ( L_25 , V_104 , V_4 -> error ) ;
break;
case V_126 :
V_4 -> error = - F_60 ( V_38 ) ;
V_4 -> V_77 = V_118 ;
F_15 ( L_26 , V_4 -> error ) ;
break;
case V_127 :
V_4 -> error = - F_60 ( V_38 ) ;
V_4 -> V_77 = V_118 ;
F_15 ( L_27 , V_4 -> error ) ;
break;
default:
F_21 () ;
break;
}
F_23 ( V_38 ) ;
}
if ( V_4 -> V_77 >= V_110 ) {
while ( ( V_38 = F_54 ( & V_4 -> V_42 ) ) )
F_23 ( V_38 ) ;
if ( V_4 -> V_128 )
F_31 ( V_4 ) ;
}
F_7 ( L_1 ) ;
}
static int F_61 ( struct V_3 * V_4 )
{
struct V_37 * V_38 ;
int V_10 ;
F_62 ( V_129 , V_130 ) ;
F_4 ( L_1 ) ;
F_63 ( & V_4 -> V_52 , & V_129 ) ;
for (; ; ) {
F_64 ( V_131 ) ;
if ( ! F_27 ( & V_4 -> V_42 ) ) {
F_65 ( V_132 ) ;
F_57 ( V_4 ) ;
continue;
}
V_10 = V_4 -> error ;
if ( V_4 -> V_77 >= V_110 )
break;
V_10 = - V_133 ;
if ( F_66 ( V_130 ) )
break;
F_67 () ;
}
F_68 ( & V_4 -> V_52 , & V_129 ) ;
F_65 ( V_132 ) ;
if ( V_4 -> V_77 < V_110 ) {
F_15 ( L_28 ) ;
F_53 ( V_4 -> V_41 , V_112 ) ;
while ( ( V_38 = F_54 ( & V_4 -> V_42 ) ) )
F_23 ( V_38 ) ;
}
F_15 ( L_29 ) ;
F_31 ( V_4 ) ;
F_7 ( L_17 , V_10 ) ;
return V_10 ;
}
static void F_69 ( struct V_3 * V_4 )
{
F_70 ( & V_4 -> V_52 ) ;
}
static void F_71 ( struct V_3 * V_4 )
{
F_4 ( L_1 ) ;
F_56 ( V_12 , & V_4 -> V_5 ) ;
}
static int F_72 ( struct V_3 * V_4 )
{
F_4 ( L_1 ) ;
return - V_134 ;
}
static void F_73 ( struct V_3 * V_4 )
{
F_4 ( L_1 ) ;
F_25 ( V_4 ) ;
F_7 ( L_1 ) ;
}
static void V_88 ( struct V_3 * V_4 )
{
F_4 ( L_1 ) ;
if ( ! F_27 ( & V_4 -> V_42 ) )
F_57 ( V_4 ) ;
if ( V_4 -> V_77 >= V_110 && V_4 -> V_83 ) {
if ( V_4 -> V_83 -> V_135 )
V_4 -> V_83 -> V_135 ( V_4 -> V_136 ,
V_4 -> error ) ;
V_4 -> V_136 = NULL ;
F_29 ( V_4 ) ;
V_4 -> V_6 = F_73 ;
F_56 ( V_12 , & V_4 -> V_5 ) ;
}
F_7 ( L_1 ) ;
}
void F_74 ( struct V_3 * V_4 , struct V_37 * V_38 )
{
T_1 V_137 = V_38 -> V_137 ;
if ( F_75 ( V_38 , 0 , V_4 -> V_51 + V_4 -> V_47 , V_137 ) < 0 )
F_21 () ;
V_4 -> V_47 += V_137 ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_84 * V_41 ;
struct V_3 * V_4 = NULL ;
struct V_37 * V_38 ;
while ( ( V_38 = F_54 ( & V_11 ) ) ) {
F_15 ( L_30 ) ;
F_23 ( V_38 ) ;
if ( ! V_4 ) {
V_4 = F_33 ( sizeof( struct V_3 ) , V_138 ) ;
if ( ! V_4 ) {
F_77 ( V_34 ) ;
return;
}
V_4 -> V_6 = V_88 ;
F_49 ( & V_4 -> V_5 , F_1 ) ;
V_4 -> V_83 = & V_139 ;
V_4 -> type = & V_140 ;
F_36 ( & V_4 -> V_52 ) ;
F_5 ( & V_4 -> V_42 ) ;
V_4 -> V_77 = V_105 ;
F_15 ( L_13 ,
V_4 , V_4 -> type -> V_40 ,
F_17 ( & V_36 ) ) ;
F_34 ( & V_36 ) ;
}
V_41 = F_78 ( V_34 ,
( unsigned long ) V_4 ) ;
if ( ! F_51 ( V_41 ) ) {
V_4 -> V_41 = V_41 ;
V_4 = NULL ;
}
}
if ( V_4 )
F_25 ( V_4 ) ;
}
static int F_79 ( struct V_3 * V_4 , struct V_37 * V_38 ,
bool V_65 )
{
T_1 V_137 = V_38 -> V_137 ;
void * V_141 = ( void * ) & V_4 -> V_142 ;
F_4 ( L_31 , V_4 -> V_62 , V_137 , V_65 ) ;
F_16 ( V_4 -> V_62 , < , 4 ) ;
V_137 = F_80 ( T_1 , V_137 , 4 - V_4 -> V_62 ) ;
if ( F_75 ( V_38 , 0 , V_141 + V_4 -> V_62 , V_137 ) < 0 )
F_21 () ;
if ( ! F_81 ( V_38 , V_137 ) )
F_21 () ;
V_4 -> V_62 += V_137 ;
if ( V_4 -> V_62 < 4 ) {
if ( V_65 ) {
F_7 ( L_32 ) ;
return - V_143 ;
}
F_7 ( L_33 ) ;
return 0 ;
}
V_4 -> V_77 = V_106 ;
if ( ! F_82 ( V_4 ) )
return - V_114 ;
return V_4 -> type -> V_109 ( V_4 , V_38 , V_65 ) ;
}
void F_83 ( struct V_3 * V_4 )
{
struct V_53 V_54 ;
F_4 ( L_1 ) ;
V_54 . V_91 = NULL ;
V_54 . V_92 = 0 ;
F_42 ( & V_54 . V_74 , V_75 | V_76 , NULL , 0 , 0 ) ;
V_54 . V_93 = NULL ;
V_54 . V_94 = 0 ;
V_54 . V_68 = 0 ;
V_4 -> V_77 = V_107 ;
switch ( F_43 ( V_4 -> V_41 , & V_54 , 0 ) ) {
case 0 :
F_7 ( L_34 ) ;
return;
case - V_13 :
F_15 ( L_35 ) ;
F_53 ( V_4 -> V_41 , V_98 ) ;
default:
F_31 ( V_4 ) ;
F_7 ( L_36 ) ;
return;
}
}
void F_84 ( struct V_3 * V_4 , const void * V_144 , T_1 V_137 )
{
struct V_53 V_54 ;
struct V_55 V_56 [ 1 ] ;
int V_60 ;
F_4 ( L_1 ) ;
V_56 [ 0 ] . V_72 = ( void * ) V_144 ;
V_56 [ 0 ] . V_73 = V_137 ;
V_54 . V_91 = NULL ;
V_54 . V_92 = 0 ;
F_42 ( & V_54 . V_74 , V_75 | V_76 , V_56 , 1 , V_137 ) ;
V_54 . V_93 = NULL ;
V_54 . V_94 = 0 ;
V_54 . V_68 = 0 ;
V_4 -> V_77 = V_107 ;
V_60 = F_43 ( V_4 -> V_41 , & V_54 , V_137 ) ;
if ( V_60 >= 0 ) {
F_7 ( L_34 ) ;
return;
}
if ( V_60 == - V_13 ) {
F_15 ( L_35 ) ;
F_53 ( V_4 -> V_41 , V_98 ) ;
}
F_31 ( V_4 ) ;
F_7 ( L_36 ) ;
}
int F_85 ( struct V_3 * V_4 , struct V_37 * V_38 ,
bool V_65 , void * V_144 , T_1 V_59 )
{
T_1 V_137 = V_38 -> V_137 ;
F_4 ( L_37 , V_4 -> V_62 , V_137 , V_65 , V_59 ) ;
F_16 ( V_4 -> V_62 , < , V_59 ) ;
V_137 = F_80 ( T_1 , V_137 , V_59 - V_4 -> V_62 ) ;
if ( F_75 ( V_38 , 0 , V_144 + V_4 -> V_62 , V_137 ) < 0 ||
! F_81 ( V_38 , V_137 ) )
F_21 () ;
V_4 -> V_62 += V_137 ;
if ( V_4 -> V_62 < V_59 ) {
if ( V_65 ) {
F_7 ( L_38 , V_4 -> V_62 , V_59 ) ;
return - V_143 ;
}
F_7 ( L_39 ) ;
return - V_145 ;
}
return 0 ;
}
