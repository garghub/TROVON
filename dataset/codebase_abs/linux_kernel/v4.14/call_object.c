static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( L_1 , V_3 -> V_4 ) ;
if ( V_3 -> V_5 < V_6 )
F_3 ( V_3 , V_7 , F_4 () ) ;
}
struct V_2 * F_5 ( struct V_8 * V_9 ,
unsigned long V_10 )
{
struct V_2 * V_3 ;
struct V_11 * V_12 ;
F_2 ( L_2 , V_9 , V_10 ) ;
F_6 ( & V_9 -> V_13 ) ;
V_12 = V_9 -> V_14 . V_11 ;
while ( V_12 ) {
V_3 = F_7 ( V_12 , struct V_2 , V_15 ) ;
if ( V_10 < V_3 -> V_10 )
V_12 = V_12 -> V_16 ;
else if ( V_10 > V_3 -> V_10 )
V_12 = V_12 -> V_17 ;
else
goto V_18;
}
F_8 ( & V_9 -> V_13 ) ;
F_9 ( L_3 ) ;
return NULL ;
V_18:
F_10 ( V_3 , V_19 ) ;
F_8 ( & V_9 -> V_13 ) ;
F_9 ( L_4 , V_3 , F_11 ( & V_3 -> V_20 ) ) ;
return V_3 ;
}
struct V_2 * F_12 ( T_1 V_21 )
{
struct V_2 * V_3 ;
V_3 = F_13 ( V_22 , V_21 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_23 = F_14 ( V_24 ,
sizeof( struct V_25 * ) ,
V_21 ) ;
if ( ! V_3 -> V_23 )
goto V_26;
V_3 -> V_27 = F_14 ( V_24 , sizeof( V_28 ) , V_21 ) ;
if ( ! V_3 -> V_27 )
goto V_29;
F_15 ( & V_3 -> V_30 ) ;
F_16 ( & V_3 -> V_31 , F_1 ,
( unsigned long ) V_3 ) ;
F_17 ( & V_3 -> V_32 , & V_33 ) ;
F_18 ( & V_3 -> V_34 ) ;
F_18 ( & V_3 -> V_35 ) ;
F_18 ( & V_3 -> V_36 ) ;
F_18 ( & V_3 -> V_37 ) ;
F_18 ( & V_3 -> V_38 ) ;
F_19 ( & V_3 -> V_39 ) ;
F_20 ( & V_3 -> V_40 ) ;
F_21 ( & V_3 -> V_41 ) ;
F_22 ( & V_3 -> V_20 , 1 ) ;
V_3 -> V_4 = F_23 ( & V_42 ) ;
V_3 -> V_43 = - 1 ;
memset ( & V_3 -> V_15 , 0xed , sizeof( V_3 -> V_15 ) ) ;
V_3 -> V_44 = V_45 ;
V_3 -> V_46 = 16 ;
V_3 -> V_47 = 1 ;
V_3 -> V_48 = 2 ;
V_3 -> V_49 = V_24 - 1 ;
return V_3 ;
V_29:
F_24 ( V_3 -> V_23 ) ;
V_26:
F_25 ( V_22 , V_3 ) ;
return NULL ;
}
static struct V_2 * F_26 ( struct V_50 * V_51 ,
T_1 V_21 )
{
struct V_2 * V_3 ;
T_2 V_52 ;
F_2 ( L_5 ) ;
V_3 = F_12 ( V_21 ) ;
if ( ! V_3 )
return F_27 ( - V_53 ) ;
V_3 -> V_5 = V_54 ;
V_3 -> V_55 = V_51 -> V_56 ;
V_3 -> V_57 = true ;
V_52 = F_4 () ;
V_3 -> V_58 = V_52 ;
V_3 -> V_59 = V_52 ;
F_9 ( L_6 , V_3 ) ;
return V_3 ;
}
static void F_28 ( struct V_2 * V_3 )
{
T_2 V_52 = F_4 () , V_60 ;
V_60 = F_29 ( V_52 , V_61 ) ;
V_3 -> V_60 = V_60 ;
V_3 -> V_62 = V_60 ;
V_3 -> V_63 = V_60 ;
V_3 -> V_64 = V_60 ;
V_3 -> V_31 . V_65 = V_66 + V_67 / 2 ;
F_3 ( V_3 , V_68 , V_52 ) ;
}
struct V_2 * F_30 ( struct V_8 * V_9 ,
struct V_69 * V_70 ,
struct V_50 * V_51 ,
unsigned long V_10 ,
T_3 V_43 ,
T_1 V_21 )
__releases( &rx->sk.sk_lock.slock
int F_31 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
struct V_69 * V_70 ,
struct V_50 * V_51 ,
T_1 V_21 )
{
const void * V_71 = F_32 ( 0 ) ;
int V_72 ;
V_72 = F_33 ( V_3 , V_70 , V_51 , V_21 ) ;
if ( V_72 < 0 )
goto error;
F_34 ( V_3 , V_73 , F_11 ( & V_3 -> V_20 ) ,
V_71 , NULL ) ;
F_28 ( V_3 ) ;
F_35 ( L_7 , V_3 -> V_4 , V_3 -> V_74 -> V_4 ) ;
if ( ! F_36 ( V_75 , & V_3 -> V_76 ) )
F_37 ( V_3 ) ;
F_9 ( L_8 ) ;
return 0 ;
error:
F_38 ( V_3 , V_77 ,
V_78 , V_72 ) ;
F_34 ( V_3 , V_79 , F_11 ( & V_3 -> V_20 ) ,
V_71 , F_27 ( V_72 ) ) ;
F_9 ( L_9 , V_72 ) ;
return V_72 ;
}
void F_39 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
struct V_25 * V_80 )
{
struct V_81 * V_74 = V_3 -> V_74 ;
struct V_82 * V_83 = F_40 ( V_80 ) ;
T_4 V_84 ;
F_2 ( L_10 , V_3 -> V_74 -> V_4 ) ;
F_41 ( V_3 -> V_85 , V_9 ) ;
V_3 -> V_86 = V_83 -> V_87 . V_88 ;
V_3 -> V_55 = V_83 -> V_87 . V_89 ;
V_3 -> V_90 = V_83 -> V_87 . V_90 ;
V_3 -> V_5 = V_91 ;
if ( V_83 -> V_87 . V_92 > 0 )
V_3 -> V_5 = V_93 ;
V_3 -> V_59 = V_80 -> V_94 ;
V_84 = V_83 -> V_87 . V_90 & V_95 ;
V_74 -> V_96 [ V_84 ] . V_97 = V_3 -> V_86 ;
V_74 -> V_96 [ V_84 ] . V_86 = V_3 -> V_86 ;
F_41 ( V_74 -> V_96 [ V_84 ] . V_3 , V_3 ) ;
F_42 ( & V_74 -> V_98 . V_99 -> V_40 ) ;
F_43 ( & V_3 -> V_100 , & V_74 -> V_98 . V_99 -> V_101 ) ;
F_44 ( & V_74 -> V_98 . V_99 -> V_40 ) ;
F_35 ( L_11 , V_3 -> V_4 , V_3 -> V_74 -> V_4 ) ;
F_28 ( V_3 ) ;
F_9 ( L_5 ) ;
}
bool F_37 ( struct V_2 * V_3 )
{
const void * V_71 = F_32 ( 0 ) ;
int V_102 = F_45 ( & V_3 -> V_20 , 1 , 0 ) ;
if ( V_102 == 0 )
return false ;
if ( F_46 ( & V_3 -> V_32 ) )
F_34 ( V_3 , V_103 , V_102 + 1 , V_71 , NULL ) ;
else
F_47 ( V_3 , V_104 ) ;
return true ;
}
bool F_48 ( struct V_2 * V_3 )
{
const void * V_71 = F_32 ( 0 ) ;
int V_102 = F_11 ( & V_3 -> V_20 ) ;
F_49 ( V_102 , >= , 1 ) ;
if ( F_46 ( & V_3 -> V_32 ) )
F_34 ( V_3 , V_105 , V_102 , V_71 , NULL ) ;
else
F_47 ( V_3 , V_104 ) ;
return true ;
}
void F_50 ( struct V_2 * V_3 )
{
const void * V_71 = F_32 ( 0 ) ;
if ( V_3 ) {
int V_102 = F_11 ( & V_3 -> V_20 ) ;
F_34 ( V_3 , V_106 , V_102 , V_71 , NULL ) ;
}
}
void F_10 ( struct V_2 * V_3 , enum V_107 V_108 )
{
const void * V_71 = F_32 ( 0 ) ;
int V_102 = F_23 ( & V_3 -> V_20 ) ;
F_34 ( V_3 , V_108 , V_102 , V_71 , NULL ) ;
}
void F_51 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
const void * V_71 = F_32 ( 0 ) ;
struct V_81 * V_74 = V_3 -> V_74 ;
bool V_109 = false ;
int V_110 ;
F_2 ( L_12 , V_3 -> V_4 , F_11 ( & V_3 -> V_20 ) ) ;
F_34 ( V_3 , V_111 , F_11 ( & V_3 -> V_20 ) ,
V_71 , ( const void * ) V_3 -> V_112 ) ;
F_49 ( V_3 -> V_5 , == , V_6 ) ;
F_52 ( & V_3 -> V_40 ) ;
if ( F_36 ( V_113 , & V_3 -> V_112 ) )
F_53 () ;
F_54 ( & V_3 -> V_40 ) ;
F_55 ( & V_3 -> V_31 ) ;
F_56 ( & V_9 -> V_114 ) ;
if ( ! F_57 ( & V_3 -> V_37 ) ) {
F_58 ( L_13 ,
V_3 , V_3 -> V_76 , V_3 -> V_112 ) ;
F_59 ( & V_3 -> V_37 ) ;
V_109 = true ;
}
V_3 -> V_37 . V_115 = NULL ;
V_3 -> V_37 . V_116 = NULL ;
F_60 ( & V_9 -> V_114 ) ;
if ( V_109 )
F_47 ( V_3 , V_117 ) ;
F_61 ( & V_9 -> V_13 ) ;
if ( F_62 ( V_118 , & V_3 -> V_112 ) ) {
F_63 ( & V_3 -> V_15 , & V_9 -> V_14 ) ;
memset ( & V_3 -> V_15 , 0xdd , sizeof( V_3 -> V_15 ) ) ;
F_47 ( V_3 , V_119 ) ;
}
F_59 ( & V_3 -> V_38 ) ;
F_64 ( & V_9 -> V_13 ) ;
F_58 ( L_14 , V_3 , V_3 -> V_4 , V_74 ) ;
if ( V_74 )
F_65 ( V_3 ) ;
for ( V_110 = 0 ; V_110 < V_24 ; V_110 ++ ) {
F_66 ( V_3 -> V_23 [ V_110 ] ,
( V_3 -> V_57 ? V_120 :
V_121 ) ) ;
V_3 -> V_23 [ V_110 ] = NULL ;
}
F_9 ( L_5 ) ;
}
int F_67 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
const void * V_71 = F_32 ( 0 ) ;
int V_110 ;
V_28 V_122 = 0 ;
F_2 ( L_12 , V_3 -> V_4 , F_11 ( & V_3 -> V_20 ) ) ;
F_34 ( V_3 , V_111 , F_11 ( & V_3 -> V_20 ) ,
V_71 , ( const void * ) V_3 -> V_112 ) ;
F_49 ( V_3 -> V_5 , == , V_6 ) ;
F_49 ( V_3 -> V_123 , != , V_124 ) ;
F_49 ( V_3 -> V_123 , != , V_125 ) ;
ASSERT ( F_57 ( & V_3 -> V_37 ) ) ;
F_55 ( & V_3 -> V_31 ) ;
F_58 ( L_14 , V_3 , V_3 -> V_4 , V_3 -> V_74 ) ;
if ( V_3 -> V_74 )
F_65 ( V_3 ) ;
if ( F_68 ( V_3 ) ||
! V_3 -> V_57 ||
V_3 -> V_126 != 0 ||
V_3 -> V_127 != 0 ||
V_3 -> V_128 != 0 )
return - V_129 ;
V_3 -> V_5 = V_130 ;
V_3 -> V_123 = V_131 ;
V_3 -> V_86 = 0 ;
V_3 -> V_90 = 0 ;
V_3 -> V_48 = 0 ;
V_3 -> V_132 = 0 ;
V_3 -> V_49 = 0 ;
V_3 -> V_133 = 0 ;
V_3 -> V_134 = 0 ;
V_3 -> V_135 = 0 ;
V_3 -> V_136 = 0 ;
for ( V_110 = 0 ; V_110 < V_24 ; V_110 ++ ) {
V_122 |= V_3 -> V_27 [ V_110 ] ;
V_3 -> V_27 [ V_110 ] &= V_137 ;
V_3 -> V_27 [ V_110 ] |= V_138 ;
}
F_9 ( L_8 ) ;
return 0 ;
}
void F_69 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
F_2 ( L_15 , V_9 ) ;
while ( ! F_57 ( & V_9 -> V_139 ) ) {
V_3 = F_70 ( V_9 -> V_139 . V_115 ,
struct V_2 , V_36 ) ;
F_59 ( & V_3 -> V_36 ) ;
F_71 ( L_16 , V_3 , 0 , V_78 , - V_140 ) ;
F_47 ( V_3 , V_117 ) ;
}
while ( ! F_57 ( & V_9 -> V_141 ) ) {
V_3 = F_70 ( V_9 -> V_141 . V_115 ,
struct V_2 , V_38 ) ;
F_10 ( V_3 , V_19 ) ;
F_71 ( L_17 , V_3 , 0 , V_78 , - V_140 ) ;
F_72 ( V_3 ) ;
F_51 ( V_9 , V_3 ) ;
F_47 ( V_3 , V_117 ) ;
}
F_9 ( L_5 ) ;
}
void F_47 ( struct V_2 * V_3 , enum V_107 V_108 )
{
struct V_142 * V_143 ;
const void * V_71 = F_32 ( 0 ) ;
int V_102 ;
ASSERT ( V_3 != NULL ) ;
V_102 = F_73 ( & V_3 -> V_20 ) ;
F_34 ( V_3 , V_108 , V_102 , V_71 , NULL ) ;
F_49 ( V_102 , >= , 0 ) ;
if ( V_102 == 0 ) {
F_58 ( L_18 , V_3 -> V_4 ) ;
F_49 ( V_3 -> V_5 , == , V_6 ) ;
if ( ! F_57 ( & V_3 -> V_34 ) ) {
V_143 = V_142 ( F_74 ( & V_3 -> V_85 -> V_144 ) ) ;
F_61 ( & V_143 -> V_13 ) ;
F_75 ( & V_3 -> V_34 ) ;
F_64 ( & V_143 -> V_13 ) ;
}
F_76 ( V_3 ) ;
}
}
static void F_77 ( struct V_145 * V_146 )
{
struct V_2 * V_3 = F_78 ( V_146 , struct V_2 , V_146 ) ;
F_79 ( V_3 -> V_99 ) ;
F_24 ( V_3 -> V_23 ) ;
F_24 ( V_3 -> V_27 ) ;
F_25 ( V_22 , V_3 ) ;
}
void F_76 ( struct V_2 * V_3 )
{
int V_110 ;
F_35 ( L_19 , V_3 -> V_4 ) ;
memset ( & V_3 -> V_15 , 0xcd , sizeof( V_3 -> V_15 ) ) ;
F_55 ( & V_3 -> V_31 ) ;
F_49 ( V_3 -> V_5 , == , V_6 ) ;
ASSERT ( F_80 ( V_113 , & V_3 -> V_112 ) ) ;
F_49 ( V_3 -> V_74 , == , NULL ) ;
for ( V_110 = 0 ; V_110 < V_24 ; V_110 ++ )
F_66 ( V_3 -> V_23 [ V_110 ] ,
( V_3 -> V_57 ? V_120 :
V_121 ) ) ;
F_66 ( V_3 -> V_147 , V_120 ) ;
F_81 ( & V_3 -> V_146 , F_77 ) ;
}
void F_82 ( struct V_142 * V_143 )
{
struct V_2 * V_3 ;
F_2 ( L_5 ) ;
if ( F_57 ( & V_143 -> V_14 ) )
return;
F_61 ( & V_143 -> V_13 ) ;
while ( ! F_57 ( & V_143 -> V_14 ) ) {
V_3 = F_70 ( V_143 -> V_14 . V_115 , struct V_2 , V_34 ) ;
F_58 ( L_20 , V_3 ) ;
F_50 ( V_3 ) ;
F_75 ( & V_3 -> V_34 ) ;
F_83 ( L_21 ,
V_3 , F_11 ( & V_3 -> V_20 ) ,
V_148 [ V_3 -> V_5 ] ,
V_3 -> V_112 , V_3 -> V_76 ) ;
F_64 ( & V_143 -> V_13 ) ;
F_84 () ;
F_61 ( & V_143 -> V_13 ) ;
}
F_64 ( & V_143 -> V_13 ) ;
}
