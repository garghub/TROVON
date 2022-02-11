static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 ;
F_2 ( L_1 ) ;
F_3 ( V_3 ) ;
F_4 ( & V_5 ) ;
V_4 = F_5 ( & V_6 , V_2 ,
1 , 0x40000000 , V_7 ) ;
if ( V_4 < 0 )
goto error;
F_6 ( & V_5 ) ;
F_7 () ;
V_2 -> V_8 . V_9 = V_10 ;
V_2 -> V_8 . V_11 = V_4 << V_12 ;
F_8 ( V_13 , & V_2 -> V_14 ) ;
F_9 ( L_2 , V_2 -> V_8 . V_11 ) ;
return 0 ;
error:
F_6 ( & V_5 ) ;
F_7 () ;
F_9 ( L_3 , V_4 ) ;
return V_4 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( F_11 ( V_13 , & V_2 -> V_14 ) ) {
F_4 ( & V_5 ) ;
F_12 ( & V_6 ,
V_2 -> V_8 . V_11 >> V_12 ) ;
F_6 ( & V_5 ) ;
}
}
void F_13 ( void )
{
struct V_1 * V_2 ;
int V_4 ;
if ( ! F_14 ( & V_6 ) ) {
F_15 (&rxrpc_client_conn_ids, conn, id) {
F_16 ( L_4 ,
V_2 , F_17 ( & V_2 -> V_15 ) ) ;
}
F_18 () ;
}
F_19 ( & V_6 ) ;
}
static struct V_1 *
F_20 ( struct V_16 * V_17 , T_1 V_3 )
{
struct V_1 * V_2 ;
int V_18 ;
F_2 ( L_1 ) ;
V_2 = F_21 ( V_3 ) ;
if ( ! V_2 ) {
F_9 ( L_5 ) ;
return F_22 ( - V_19 ) ;
}
F_23 ( & V_2 -> V_15 , 1 ) ;
if ( V_17 -> V_20 )
F_24 ( V_21 , & V_2 -> V_14 ) ;
V_2 -> V_22 = * V_17 ;
V_2 -> V_23 = V_24 ;
V_2 -> V_25 = V_26 ;
V_18 = F_1 ( V_2 , V_3 ) ;
if ( V_18 < 0 )
goto V_27;
V_18 = F_25 ( V_2 ) ;
if ( V_18 < 0 )
goto V_28;
V_18 = V_2 -> V_29 -> V_30 ( V_2 ) ;
if ( V_18 < 0 )
goto V_31;
F_26 ( & V_32 ) ;
F_27 ( & V_2 -> V_33 , & V_34 ) ;
F_28 ( & V_32 ) ;
V_17 -> V_35 = NULL ;
F_29 ( V_2 -> V_22 . V_36 ) ;
F_30 ( V_2 -> V_22 . V_37 ) ;
F_31 ( V_2 , V_38 , F_17 ( & V_2 -> V_15 ) ,
F_32 ( 0 ) ) ;
F_33 ( V_2 , - 1 , V_39 ) ;
F_9 ( L_6 , V_2 ) ;
return V_2 ;
V_31:
V_2 -> V_29 -> V_40 ( V_2 ) ;
V_28:
F_10 ( V_2 ) ;
V_27:
F_34 ( V_2 ) ;
F_9 ( L_3 , V_18 ) ;
return F_22 ( V_18 ) ;
}
static bool F_35 ( struct V_1 * V_2 )
{
int V_41 , V_4 , V_42 , V_43 ;
if ( F_11 ( V_21 , & V_2 -> V_14 ) )
goto V_44;
if ( V_2 -> V_8 . V_9 != V_10 )
goto V_45;
V_41 = F_36 ( V_6 . V_46 ) ;
V_4 = V_2 -> V_8 . V_11 >> V_12 ;
V_42 = V_4 - V_41 ;
if ( V_42 < 0 )
V_42 = - V_42 ;
V_43 = F_37 ( V_47 , V_48 ) * 4 ;
if ( V_42 > V_43 )
goto V_45;
return true ;
V_45:
F_8 ( V_21 , & V_2 -> V_14 ) ;
V_44:
return false ;
}
static int F_38 ( struct V_49 * V_50 ,
struct V_16 * V_17 ,
struct V_51 * V_52 ,
T_1 V_3 )
{
struct V_1 * V_2 , * V_53 = NULL ;
struct V_54 * V_36 = V_17 -> V_36 ;
struct V_55 * V_56 , * * V_57 , * V_58 ;
long V_59 ;
int V_18 = - V_19 ;
F_2 ( L_7 , V_50 -> V_60 , V_50 -> V_61 ) ;
V_17 -> V_35 = F_39 ( V_17 -> V_36 , V_52 , V_3 ) ;
if ( ! V_17 -> V_35 )
goto error;
if ( ! V_17 -> V_20 ) {
F_40 ( L_8 ) ;
F_4 ( & V_36 -> V_62 ) ;
V_56 = V_36 -> V_63 . V_55 ;
while ( V_56 ) {
V_2 = F_41 ( V_56 , struct V_1 , V_64 ) ;
#define F_42 ( T_2 ) ((long)conn->params.X - (long)cp->X)
V_59 = ( F_42 ( V_35 ) ? :
F_42 ( V_37 ) ? :
F_42 ( V_65 ) ) ;
#undef F_42
if ( V_59 < 0 ) {
V_56 = V_56 -> V_66 ;
} else if ( V_59 > 0 ) {
V_56 = V_56 -> V_67 ;
} else {
if ( F_35 ( V_2 ) &&
F_43 ( V_2 ) )
goto V_68;
break;
}
}
F_6 ( & V_36 -> V_62 ) ;
}
F_40 ( L_9 ) ;
V_53 = F_20 ( V_17 , V_3 ) ;
if ( F_44 ( V_53 ) ) {
V_18 = F_45 ( V_53 ) ;
goto V_69;
}
F_27 ( & V_50 -> V_70 , & V_53 -> V_71 ) ;
if ( V_17 -> V_20 ) {
V_50 -> V_2 = V_53 ;
V_50 -> V_72 = V_53 -> V_72 ;
F_9 ( L_10 , V_53 -> V_60 ) ;
return 0 ;
}
F_40 ( L_11 ) ;
F_4 ( & V_36 -> V_62 ) ;
V_57 = & V_36 -> V_63 . V_55 ;
V_58 = NULL ;
while ( * V_57 ) {
V_58 = * V_57 ;
V_2 = F_41 ( V_58 , struct V_1 , V_64 ) ;
#define F_42 ( T_2 ) ((long)conn->params.X - (long)candidate->params.X)
V_59 = ( F_42 ( V_35 ) ? :
F_42 ( V_37 ) ? :
F_42 ( V_65 ) ) ;
#undef F_42
if ( V_59 < 0 ) {
V_57 = & ( * V_57 ) -> V_66 ;
} else if ( V_59 > 0 ) {
V_57 = & ( * V_57 ) -> V_67 ;
} else {
if ( F_35 ( V_2 ) &&
F_43 ( V_2 ) )
goto V_68;
F_40 ( L_12 ) ;
F_46 ( V_73 , & V_2 -> V_14 ) ;
F_47 ( & V_2 -> V_64 ,
& V_53 -> V_64 ,
& V_36 -> V_63 ) ;
F_33 ( V_2 , - 1 , V_74 ) ;
goto V_75;
}
}
F_40 ( L_9 ) ;
F_48 ( & V_53 -> V_64 , V_58 , V_57 ) ;
F_49 ( & V_53 -> V_64 , & V_36 -> V_63 ) ;
V_75:
F_8 ( V_73 , & V_53 -> V_14 ) ;
V_50 -> V_2 = V_53 ;
V_50 -> V_72 = V_53 -> V_72 ;
F_6 ( & V_36 -> V_62 ) ;
F_9 ( L_13 , V_53 -> V_60 ) ;
return 0 ;
V_68:
F_40 ( L_14 ) ;
F_6 ( & V_36 -> V_62 ) ;
if ( V_53 ) {
F_33 ( V_53 , - 1 , V_76 ) ;
F_50 ( V_53 ) ;
V_53 = NULL ;
}
F_4 ( & V_2 -> V_77 ) ;
V_50 -> V_2 = V_2 ;
V_50 -> V_72 = V_2 -> V_72 ;
F_51 ( & V_50 -> V_70 , & V_2 -> V_71 ) ;
F_6 ( & V_2 -> V_77 ) ;
F_9 ( L_15 , V_2 -> V_60 ) ;
return 0 ;
V_69:
F_52 ( V_17 -> V_35 ) ;
V_17 -> V_35 = NULL ;
error:
F_9 ( L_3 , V_18 ) ;
return V_18 ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_33 ( V_2 , - 1 , V_78 ) ;
V_2 -> V_79 = V_80 ;
V_81 ++ ;
F_54 ( & V_2 -> V_82 , & V_83 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned int V_84 ;
F_2 ( L_16 , V_2 -> V_60 , V_2 -> V_79 ) ;
if ( V_2 -> V_79 == V_80 )
goto V_85;
F_4 ( & V_86 ) ;
V_84 = V_87 ;
if ( ! F_56 ( V_88 , & V_2 -> V_14 ) ) {
F_33 ( V_2 , - 1 , V_89 ) ;
V_87 = V_84 + 1 ;
}
switch ( V_2 -> V_79 ) {
case V_80 :
case V_90 :
break;
case V_91 :
case V_92 :
case V_93 :
if ( V_84 >= V_47 )
goto V_94;
goto V_95;
default:
F_18 () ;
}
V_96:
F_6 ( & V_86 ) ;
V_85:
F_9 ( L_17 , V_2 -> V_79 ) ;
return;
V_95:
F_40 ( L_18 ) ;
F_53 ( V_2 ) ;
goto V_96;
V_94:
F_40 ( L_19 ) ;
F_33 ( V_2 , - 1 , V_97 ) ;
V_2 -> V_79 = V_90 ;
F_54 ( & V_2 -> V_82 , & V_98 ) ;
goto V_96;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned int V_99 )
{
struct V_100 * V_101 = & V_2 -> V_102 [ V_99 ] ;
F_58 ( V_101 -> V_50 , NULL ) ;
V_2 -> V_103 &= ~ ( 1 << V_99 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
unsigned int V_99 )
{
struct V_100 * V_101 = & V_2 -> V_102 [ V_99 ] ;
struct V_49 * V_50 = F_60 ( V_2 -> V_71 . V_104 ,
struct V_49 , V_70 ) ;
T_3 V_105 = V_101 -> V_106 + 1 ;
F_33 ( V_2 , V_99 , V_107 ) ;
F_61 ( & V_50 -> V_108 ) ;
V_50 -> V_25 = V_109 ;
F_62 ( & V_50 -> V_108 ) ;
F_63 ( V_50 ) ;
F_64 ( & V_50 -> V_70 ) ;
V_2 -> V_103 |= 1 << V_99 ;
V_50 -> V_35 = F_65 ( V_2 -> V_22 . V_35 ) ;
V_50 -> V_11 = V_2 -> V_8 . V_11 | V_99 ;
V_50 -> V_105 = V_105 ;
F_66 ( L_20 ,
V_50 -> V_11 , V_50 -> V_105 , V_50 -> V_60 , V_2 -> V_60 ) ;
F_67 () ;
V_101 -> V_105 = V_105 ;
F_58 ( V_101 -> V_50 , V_50 ) ;
F_68 ( & V_50 -> V_110 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_4 V_111 , V_112 ;
switch ( V_2 -> V_79 ) {
case V_80 :
V_112 = V_113 ;
break;
default:
return;
}
while ( ! F_70 ( & V_2 -> V_71 ) &&
( V_111 = ~ V_2 -> V_103 ,
V_111 &= V_112 ,
V_111 != 0 ) )
F_59 ( V_2 , F_71 ( V_111 ) ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_2 ( L_21 , V_2 -> V_60 ) ;
F_33 ( V_2 , - 1 , V_114 ) ;
if ( V_2 -> V_103 == V_113 )
return;
F_4 ( & V_2 -> V_77 ) ;
F_69 ( V_2 ) ;
F_6 ( & V_2 -> V_77 ) ;
F_9 ( L_1 ) ;
}
static int F_73 ( struct V_49 * V_50 , T_1 V_3 )
{
int V_18 = 0 ;
F_2 ( L_21 , V_50 -> V_60 ) ;
if ( ! V_50 -> V_105 ) {
F_74 ( V_115 , V_116 ) ;
if ( ! F_75 ( V_3 ) ) {
V_18 = - V_117 ;
goto V_85;
}
F_76 ( & V_50 -> V_110 , & V_115 ) ;
for (; ; ) {
F_77 ( V_118 ) ;
if ( V_50 -> V_105 )
break;
if ( F_78 ( V_116 ) ) {
V_18 = - V_119 ;
break;
}
F_79 () ;
}
F_80 ( & V_50 -> V_110 , & V_115 ) ;
F_81 ( V_120 ) ;
}
F_82 () ;
V_85:
F_9 ( L_3 , V_18 ) ;
return V_18 ;
}
int F_83 ( struct V_49 * V_50 ,
struct V_16 * V_17 ,
struct V_51 * V_52 ,
T_1 V_3 )
{
int V_18 ;
F_2 ( L_7 , V_50 -> V_60 , V_50 -> V_61 ) ;
F_84 ( NULL ) ;
F_85 () ;
V_18 = F_38 ( V_50 , V_17 , V_52 , V_3 ) ;
if ( V_18 < 0 )
return V_18 ;
F_55 ( V_50 -> V_2 ) ;
F_72 ( V_50 -> V_2 ) ;
V_18 = F_73 ( V_50 , V_3 ) ;
if ( V_18 < 0 )
F_86 ( V_50 ) ;
F_9 ( L_3 , V_18 ) ;
return V_18 ;
}
static void F_87 ( struct V_1 * V_2 ,
unsigned int V_99 )
{
if ( ! F_56 ( V_121 , & V_2 -> V_14 ) ) {
F_33 ( V_2 , V_99 , V_122 ) ;
F_88 ( V_2 ) ;
}
}
void F_89 ( struct V_49 * V_50 )
{
unsigned int V_99 = V_50 -> V_11 & V_123 ;
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_100 * V_101 = & V_2 -> V_102 [ V_99 ] ;
if ( ! F_56 ( V_124 , & V_50 -> V_14 ) ) {
V_101 -> V_106 ++ ;
if ( V_101 -> V_106 >= V_125 )
F_8 ( V_21 , & V_2 -> V_14 ) ;
F_87 ( V_2 , V_99 ) ;
}
}
void F_86 ( struct V_49 * V_50 )
{
unsigned int V_99 = V_50 -> V_11 & V_123 ;
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_100 * V_101 = & V_2 -> V_102 [ V_99 ] ;
F_33 ( V_2 , V_99 , V_126 ) ;
V_50 -> V_2 = NULL ;
F_4 ( & V_2 -> V_77 ) ;
if ( ! F_70 ( & V_50 -> V_70 ) ) {
F_40 ( L_22 ) ;
F_90 ( V_50 -> V_105 , == , 0 ) ;
ASSERT ( ! F_11 ( V_124 , & V_50 -> V_14 ) ) ;
F_64 ( & V_50 -> V_70 ) ;
F_33 ( V_2 , V_99 , V_127 ) ;
F_4 ( & V_86 ) ;
if ( V_2 -> V_79 == V_90 &&
F_70 ( & V_2 -> V_71 ) &&
! V_2 -> V_103 )
goto V_128;
goto V_85;
}
F_90 ( F_91 ( V_101 -> V_50 ) , == , V_50 ) ;
if ( F_11 ( V_124 , & V_50 -> V_14 ) ) {
F_40 ( L_23 , V_50 -> V_105 , V_50 -> V_129 ) ;
F_92 ( V_2 , V_50 ) ;
}
if ( V_2 -> V_79 == V_80 &&
! F_70 ( & V_2 -> V_71 ) ) {
F_33 ( V_2 , V_99 , V_130 ) ;
F_59 ( V_2 , V_99 ) ;
goto V_131;
}
F_4 ( & V_86 ) ;
switch ( V_2 -> V_79 ) {
case V_80 :
if ( F_70 ( & V_2 -> V_71 ) ) {
F_57 ( V_2 , V_99 ) ;
if ( ! V_2 -> V_103 ) {
V_81 -- ;
goto V_128;
}
goto V_85;
}
F_33 ( V_2 , V_99 , V_130 ) ;
F_59 ( V_2 , V_99 ) ;
goto V_85;
case V_92 :
F_57 ( V_2 , V_99 ) ;
ASSERT ( F_70 ( & V_2 -> V_71 ) ) ;
if ( ! V_2 -> V_103 )
goto V_128;
goto V_85;
case V_90 :
F_57 ( V_2 , V_99 ) ;
goto V_85;
default:
F_18 () ;
}
V_85:
F_6 ( & V_86 ) ;
V_131:
F_6 ( & V_2 -> V_77 ) ;
F_50 ( V_2 ) ;
F_9 ( L_1 ) ;
return;
V_128:
if ( F_11 ( V_121 , & V_2 -> V_14 ) ) {
F_33 ( V_2 , V_99 , V_132 ) ;
V_2 -> V_133 = V_134 ;
V_2 -> V_79 = V_93 ;
F_54 ( & V_2 -> V_82 , & V_135 ) ;
if ( V_135 . V_104 == & V_2 -> V_82 &&
! V_136 )
F_93 ( V_137 ,
& V_138 ,
V_139 ) ;
} else {
F_33 ( V_2 , V_99 , V_140 ) ;
V_2 -> V_79 = V_91 ;
F_64 ( & V_2 -> V_82 ) ;
}
goto V_85;
}
static struct V_1 *
F_94 ( struct V_1 * V_2 )
{
struct V_1 * V_104 = NULL ;
struct V_54 * V_36 = V_2 -> V_22 . V_36 ;
unsigned int V_84 ;
F_33 ( V_2 , - 1 , V_141 ) ;
if ( F_11 ( V_73 , & V_2 -> V_14 ) ) {
F_4 ( & V_36 -> V_62 ) ;
if ( F_95 ( V_73 ,
& V_2 -> V_14 ) )
F_96 ( & V_2 -> V_64 , & V_36 -> V_63 ) ;
F_6 ( & V_36 -> V_62 ) ;
}
F_10 ( V_2 ) ;
F_90 ( V_2 -> V_79 , == , V_91 ) ;
if ( F_11 ( V_88 , & V_2 -> V_14 ) ) {
F_33 ( V_2 , - 1 , V_142 ) ;
F_4 ( & V_86 ) ;
V_84 = -- V_87 ;
if ( V_84 < V_47 &&
! F_70 ( & V_98 ) ) {
V_104 = F_60 ( V_98 . V_104 ,
struct V_1 , V_82 ) ;
F_88 ( V_104 ) ;
F_53 ( V_104 ) ;
}
F_6 ( & V_86 ) ;
}
F_97 ( V_2 ) ;
if ( V_104 )
F_72 ( V_104 ) ;
return V_104 ;
}
void F_98 ( struct V_1 * V_2 )
{
const void * V_143 = F_32 ( 0 ) ;
int V_144 ;
do {
V_144 = F_99 ( & V_2 -> V_15 ) ;
F_31 ( V_2 , V_145 , V_144 , V_143 ) ;
if ( V_144 > 0 )
return;
F_90 ( V_144 , >= , 0 ) ;
V_2 = F_94 ( V_2 ) ;
} while ( V_2 );
}
static void F_85 ( void )
{
struct V_1 * V_2 ;
unsigned int V_84 = V_87 ;
unsigned int V_146 , V_43 ;
F_2 ( L_1 ) ;
F_90 ( V_84 , >= , 0 ) ;
if ( V_84 < V_47 ) {
F_9 ( L_24 ) ;
return;
}
V_43 = V_147 ;
F_4 ( & V_86 ) ;
V_146 = V_81 ;
while ( V_146 > V_43 ) {
ASSERT ( ! F_70 ( & V_83 ) ) ;
V_2 = F_60 ( V_83 . V_104 ,
struct V_1 , V_82 ) ;
F_90 ( V_2 -> V_79 , == , V_80 ) ;
if ( F_70 ( & V_2 -> V_71 ) ) {
F_33 ( V_2 , - 1 , V_148 ) ;
V_2 -> V_79 = V_92 ;
F_64 ( & V_2 -> V_82 ) ;
} else {
F_33 ( V_2 , - 1 , V_97 ) ;
V_2 -> V_79 = V_90 ;
F_54 ( & V_2 -> V_82 ,
& V_98 ) ;
}
V_146 -- ;
}
V_81 = V_146 ;
F_6 ( & V_86 ) ;
F_90 ( V_146 , >= , 0 ) ;
F_9 ( L_25 ) ;
}
static void F_84 ( struct V_149 * V_150 )
{
struct V_1 * V_2 ;
unsigned long V_151 , V_152 , V_153 ;
unsigned int V_84 ;
bool V_154 = false ;
F_2 ( L_26 , V_150 ? 'w' : 'n' ) ;
if ( F_70 ( & V_135 ) ) {
F_9 ( L_27 ) ;
return;
}
if ( ! F_100 ( & V_155 ) ) {
F_9 ( L_28 ) ;
return;
}
V_84 = V_87 ;
V_104:
F_4 ( & V_86 ) ;
if ( F_70 ( & V_135 ) )
goto V_85;
V_2 = F_60 ( V_135 . V_104 ,
struct V_1 , V_82 ) ;
ASSERT ( F_11 ( V_121 , & V_2 -> V_14 ) ) ;
if ( ! V_136 ) {
V_151 = V_139 ;
if ( V_84 > V_147 )
V_151 = V_156 ;
V_152 = V_2 -> V_133 + V_151 ;
V_153 = F_36 ( V_134 ) ;
if ( F_101 ( V_152 , V_153 ) )
goto V_157;
}
F_33 ( V_2 , - 1 , V_158 ) ;
if ( ! F_95 ( V_121 , & V_2 -> V_14 ) )
F_18 () ;
V_2 -> V_79 = V_91 ;
F_64 ( & V_2 -> V_82 ) ;
F_6 ( & V_86 ) ;
F_50 ( V_2 ) ;
V_154 = true ;
V_84 -- ;
goto V_104;
V_157:
F_40 ( L_29 ) ;
if ( ! V_136 )
F_93 ( V_137 ,
& V_138 ,
V_152 - V_153 ) ;
V_85:
F_6 ( & V_86 ) ;
F_6 ( & V_155 ) ;
F_9 ( L_1 ) ;
}
void T_5 F_102 ( void )
{
F_2 ( L_1 ) ;
F_4 ( & V_86 ) ;
V_136 = true ;
F_6 ( & V_86 ) ;
F_103 ( & V_138 ) ;
if ( ! F_93 ( V_137 , & V_138 , 0 ) )
F_40 ( L_30 ) ;
F_9 ( L_1 ) ;
}
