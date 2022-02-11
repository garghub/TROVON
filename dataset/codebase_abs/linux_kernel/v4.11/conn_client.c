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
V_41 = F_36 ( & V_6 ) ;
V_4 = V_2 -> V_8 . V_11 >> V_12 ;
V_42 = V_4 - V_41 ;
if ( V_42 < 0 )
V_42 = - V_42 ;
V_43 = F_37 ( V_46 * 4 , 1024U ) ;
if ( V_42 > V_43 )
goto V_45;
return true ;
V_45:
F_8 ( V_21 , & V_2 -> V_14 ) ;
V_44:
return false ;
}
static int F_38 ( struct V_47 * V_48 ,
struct V_16 * V_17 ,
struct V_49 * V_50 ,
T_1 V_3 )
{
struct V_1 * V_2 , * V_51 = NULL ;
struct V_52 * V_36 = V_17 -> V_36 ;
struct V_53 * V_54 , * * V_55 , * V_56 ;
long V_57 ;
int V_18 = - V_19 ;
F_2 ( L_7 , V_48 -> V_58 , V_48 -> V_59 ) ;
V_17 -> V_35 = F_39 ( V_17 -> V_36 , V_50 , V_3 ) ;
if ( ! V_17 -> V_35 )
goto error;
if ( ! V_17 -> V_20 ) {
F_40 ( L_8 ) ;
F_4 ( & V_36 -> V_60 ) ;
V_54 = V_36 -> V_61 . V_53 ;
while ( V_54 ) {
V_2 = F_41 ( V_54 , struct V_1 , V_62 ) ;
#define F_42 ( T_2 ) ((long)conn->params.X - (long)cp->X)
V_57 = ( F_42 ( V_35 ) ? :
F_42 ( V_37 ) ? :
F_42 ( V_63 ) ) ;
#undef F_42
if ( V_57 < 0 ) {
V_54 = V_54 -> V_64 ;
} else if ( V_57 > 0 ) {
V_54 = V_54 -> V_65 ;
} else {
if ( F_35 ( V_2 ) &&
F_43 ( V_2 ) )
goto V_66;
break;
}
}
F_6 ( & V_36 -> V_60 ) ;
}
F_40 ( L_9 ) ;
V_51 = F_20 ( V_17 , V_3 ) ;
if ( F_44 ( V_51 ) ) {
V_18 = F_45 ( V_51 ) ;
goto V_67;
}
F_27 ( & V_48 -> V_68 , & V_51 -> V_69 ) ;
if ( V_17 -> V_20 ) {
V_48 -> V_2 = V_51 ;
V_48 -> V_70 = V_51 -> V_70 ;
F_9 ( L_10 , V_51 -> V_58 ) ;
return 0 ;
}
F_40 ( L_11 ) ;
F_4 ( & V_36 -> V_60 ) ;
V_55 = & V_36 -> V_61 . V_53 ;
V_56 = NULL ;
while ( * V_55 ) {
V_56 = * V_55 ;
V_2 = F_41 ( V_56 , struct V_1 , V_62 ) ;
#define F_42 ( T_2 ) ((long)conn->params.X - (long)candidate->params.X)
V_57 = ( F_42 ( V_35 ) ? :
F_42 ( V_37 ) ? :
F_42 ( V_63 ) ) ;
#undef F_42
if ( V_57 < 0 ) {
V_55 = & ( * V_55 ) -> V_64 ;
} else if ( V_57 > 0 ) {
V_55 = & ( * V_55 ) -> V_65 ;
} else {
if ( F_35 ( V_2 ) &&
F_43 ( V_2 ) )
goto V_66;
F_40 ( L_12 ) ;
F_46 ( V_71 , & V_2 -> V_14 ) ;
F_47 ( & V_2 -> V_62 ,
& V_51 -> V_62 ,
& V_36 -> V_61 ) ;
F_33 ( V_2 , - 1 , V_72 ) ;
goto V_73;
}
}
F_40 ( L_9 ) ;
F_48 ( & V_51 -> V_62 , V_56 , V_55 ) ;
F_49 ( & V_51 -> V_62 , & V_36 -> V_61 ) ;
V_73:
F_8 ( V_71 , & V_51 -> V_14 ) ;
V_48 -> V_2 = V_51 ;
V_48 -> V_70 = V_51 -> V_70 ;
F_6 ( & V_36 -> V_60 ) ;
F_9 ( L_13 , V_51 -> V_58 ) ;
return 0 ;
V_66:
F_40 ( L_14 ) ;
F_6 ( & V_36 -> V_60 ) ;
if ( V_51 ) {
F_33 ( V_51 , - 1 , V_74 ) ;
F_50 ( V_51 ) ;
V_51 = NULL ;
}
F_4 ( & V_2 -> V_75 ) ;
V_48 -> V_2 = V_2 ;
V_48 -> V_70 = V_2 -> V_70 ;
F_51 ( & V_48 -> V_68 , & V_2 -> V_69 ) ;
F_6 ( & V_2 -> V_75 ) ;
F_9 ( L_15 , V_2 -> V_58 ) ;
return 0 ;
V_67:
F_52 ( V_17 -> V_35 ) ;
V_17 -> V_35 = NULL ;
error:
F_9 ( L_3 , V_18 ) ;
return V_18 ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_33 ( V_2 , - 1 , V_76 ) ;
V_2 -> V_77 = V_78 ;
V_79 ++ ;
F_54 ( & V_2 -> V_80 , & V_81 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned int V_82 ;
F_2 ( L_16 , V_2 -> V_58 , V_2 -> V_77 ) ;
if ( V_2 -> V_77 == V_78 )
goto V_83;
F_4 ( & V_84 ) ;
V_82 = V_85 ;
if ( ! F_56 ( V_86 , & V_2 -> V_14 ) ) {
F_33 ( V_2 , - 1 , V_87 ) ;
V_85 = V_82 + 1 ;
}
switch ( V_2 -> V_77 ) {
case V_78 :
case V_88 :
break;
case V_89 :
case V_90 :
case V_91 :
if ( V_82 >= V_46 )
goto V_92;
goto V_93;
default:
F_18 () ;
}
V_94:
F_6 ( & V_84 ) ;
V_83:
F_9 ( L_17 , V_2 -> V_77 ) ;
return;
V_93:
F_40 ( L_18 ) ;
F_53 ( V_2 ) ;
goto V_94;
V_92:
F_40 ( L_19 ) ;
F_33 ( V_2 , - 1 , V_95 ) ;
V_2 -> V_77 = V_88 ;
F_54 ( & V_2 -> V_80 , & V_96 ) ;
goto V_94;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned int V_97 )
{
struct V_98 * V_99 = & V_2 -> V_100 [ V_97 ] ;
F_58 ( V_99 -> V_48 , NULL ) ;
V_2 -> V_101 &= ~ ( 1 << V_97 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
unsigned int V_97 )
{
struct V_98 * V_99 = & V_2 -> V_100 [ V_97 ] ;
struct V_47 * V_48 = F_60 ( V_2 -> V_69 . V_102 ,
struct V_47 , V_68 ) ;
T_3 V_103 = V_99 -> V_104 + 1 ;
F_33 ( V_2 , V_97 , V_105 ) ;
F_61 ( & V_48 -> V_106 ) ;
V_48 -> V_25 = V_107 ;
F_62 ( & V_48 -> V_106 ) ;
F_63 ( V_48 ) ;
F_64 ( & V_48 -> V_68 ) ;
V_2 -> V_101 |= 1 << V_97 ;
V_48 -> V_35 = F_65 ( V_2 -> V_22 . V_35 ) ;
V_48 -> V_11 = V_2 -> V_8 . V_11 | V_97 ;
V_48 -> V_103 = V_103 ;
F_66 ( L_20 ,
V_48 -> V_11 , V_48 -> V_103 , V_48 -> V_58 , V_2 -> V_58 ) ;
F_67 () ;
V_99 -> V_103 = V_103 ;
F_58 ( V_99 -> V_48 , V_48 ) ;
F_68 ( & V_48 -> V_108 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_4 V_109 , V_110 ;
switch ( V_2 -> V_77 ) {
case V_78 :
V_110 = V_111 ;
break;
default:
return;
}
while ( ! F_70 ( & V_2 -> V_69 ) &&
( V_109 = ~ V_2 -> V_101 ,
V_109 &= V_110 ,
V_109 != 0 ) )
F_59 ( V_2 , F_71 ( V_109 ) ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_2 ( L_21 , V_2 -> V_58 ) ;
F_33 ( V_2 , - 1 , V_112 ) ;
if ( V_2 -> V_101 == V_111 )
return;
F_4 ( & V_2 -> V_75 ) ;
F_69 ( V_2 ) ;
F_6 ( & V_2 -> V_75 ) ;
F_9 ( L_1 ) ;
}
static int F_73 ( struct V_47 * V_48 , T_1 V_3 )
{
int V_18 = 0 ;
F_2 ( L_21 , V_48 -> V_58 ) ;
if ( ! V_48 -> V_103 ) {
F_74 ( V_113 , V_114 ) ;
if ( ! F_75 ( V_3 ) ) {
V_18 = - V_115 ;
goto V_83;
}
F_76 ( & V_48 -> V_108 , & V_113 ) ;
for (; ; ) {
F_77 ( V_116 ) ;
if ( V_48 -> V_103 )
break;
if ( F_78 ( V_114 ) ) {
V_18 = - V_117 ;
break;
}
F_79 () ;
}
F_80 ( & V_48 -> V_108 , & V_113 ) ;
F_81 ( V_118 ) ;
}
F_82 () ;
V_83:
F_9 ( L_3 , V_18 ) ;
return V_18 ;
}
int F_83 ( struct V_47 * V_48 ,
struct V_16 * V_17 ,
struct V_49 * V_50 ,
T_1 V_3 )
{
int V_18 ;
F_2 ( L_7 , V_48 -> V_58 , V_48 -> V_59 ) ;
F_84 ( NULL ) ;
F_85 () ;
V_18 = F_38 ( V_48 , V_17 , V_50 , V_3 ) ;
if ( V_18 < 0 )
return V_18 ;
F_55 ( V_48 -> V_2 ) ;
F_72 ( V_48 -> V_2 ) ;
V_18 = F_73 ( V_48 , V_3 ) ;
if ( V_18 < 0 )
F_86 ( V_48 ) ;
F_9 ( L_3 , V_18 ) ;
return V_18 ;
}
static void F_87 ( struct V_1 * V_2 ,
unsigned int V_97 )
{
if ( ! F_56 ( V_119 , & V_2 -> V_14 ) ) {
F_33 ( V_2 , V_97 , V_120 ) ;
F_88 ( V_2 ) ;
}
}
void F_89 ( struct V_47 * V_48 )
{
unsigned int V_97 = V_48 -> V_11 & V_121 ;
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_98 * V_99 = & V_2 -> V_100 [ V_97 ] ;
if ( ! F_56 ( V_122 , & V_48 -> V_14 ) ) {
V_99 -> V_104 ++ ;
if ( V_99 -> V_104 >= V_123 )
F_8 ( V_21 , & V_2 -> V_14 ) ;
F_87 ( V_2 , V_97 ) ;
}
}
void F_86 ( struct V_47 * V_48 )
{
unsigned int V_97 = V_48 -> V_11 & V_121 ;
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_98 * V_99 = & V_2 -> V_100 [ V_97 ] ;
F_33 ( V_2 , V_97 , V_124 ) ;
V_48 -> V_2 = NULL ;
F_4 ( & V_2 -> V_75 ) ;
if ( ! F_70 ( & V_48 -> V_68 ) ) {
F_40 ( L_22 ) ;
F_90 ( V_48 -> V_103 , == , 0 ) ;
ASSERT ( ! F_11 ( V_122 , & V_48 -> V_14 ) ) ;
F_64 ( & V_48 -> V_68 ) ;
F_33 ( V_2 , V_97 , V_125 ) ;
F_4 ( & V_84 ) ;
if ( V_2 -> V_77 == V_88 &&
F_70 ( & V_2 -> V_69 ) &&
! V_2 -> V_101 )
goto V_126;
goto V_83;
}
F_90 ( F_91 ( V_99 -> V_48 ) , == , V_48 ) ;
if ( F_11 ( V_122 , & V_48 -> V_14 ) ) {
F_40 ( L_23 , V_48 -> V_103 , V_48 -> V_127 ) ;
F_92 ( V_2 , V_48 ) ;
}
if ( V_2 -> V_77 == V_78 &&
! F_70 ( & V_2 -> V_69 ) ) {
F_33 ( V_2 , V_97 , V_128 ) ;
F_59 ( V_2 , V_97 ) ;
goto V_129;
}
F_4 ( & V_84 ) ;
switch ( V_2 -> V_77 ) {
case V_78 :
if ( F_70 ( & V_2 -> V_69 ) ) {
F_57 ( V_2 , V_97 ) ;
if ( ! V_2 -> V_101 ) {
V_79 -- ;
goto V_126;
}
goto V_83;
}
F_33 ( V_2 , V_97 , V_128 ) ;
F_59 ( V_2 , V_97 ) ;
goto V_83;
case V_90 :
F_57 ( V_2 , V_97 ) ;
ASSERT ( F_70 ( & V_2 -> V_69 ) ) ;
if ( ! V_2 -> V_101 )
goto V_126;
goto V_83;
case V_88 :
F_57 ( V_2 , V_97 ) ;
goto V_83;
default:
F_18 () ;
}
V_83:
F_6 ( & V_84 ) ;
V_129:
F_6 ( & V_2 -> V_75 ) ;
F_50 ( V_2 ) ;
F_9 ( L_1 ) ;
return;
V_126:
if ( F_11 ( V_119 , & V_2 -> V_14 ) ) {
F_33 ( V_2 , V_97 , V_130 ) ;
V_2 -> V_131 = V_132 ;
V_2 -> V_77 = V_91 ;
F_54 ( & V_2 -> V_80 , & V_133 ) ;
if ( V_133 . V_102 == & V_2 -> V_80 &&
! V_134 )
F_93 ( V_135 ,
& V_136 ,
V_137 ) ;
} else {
F_33 ( V_2 , V_97 , V_138 ) ;
V_2 -> V_77 = V_89 ;
F_64 ( & V_2 -> V_80 ) ;
}
goto V_83;
}
static struct V_1 *
F_94 ( struct V_1 * V_2 )
{
struct V_1 * V_102 = NULL ;
struct V_52 * V_36 = V_2 -> V_22 . V_36 ;
unsigned int V_82 ;
F_33 ( V_2 , - 1 , V_139 ) ;
if ( F_11 ( V_71 , & V_2 -> V_14 ) ) {
F_4 ( & V_36 -> V_60 ) ;
if ( F_95 ( V_71 ,
& V_2 -> V_14 ) )
F_96 ( & V_2 -> V_62 , & V_36 -> V_61 ) ;
F_6 ( & V_36 -> V_60 ) ;
}
F_10 ( V_2 ) ;
F_90 ( V_2 -> V_77 , == , V_89 ) ;
if ( F_11 ( V_86 , & V_2 -> V_14 ) ) {
F_33 ( V_2 , - 1 , V_140 ) ;
F_4 ( & V_84 ) ;
V_82 = -- V_85 ;
if ( V_82 < V_46 &&
! F_70 ( & V_96 ) ) {
V_102 = F_60 ( V_96 . V_102 ,
struct V_1 , V_80 ) ;
F_88 ( V_102 ) ;
F_53 ( V_102 ) ;
}
F_6 ( & V_84 ) ;
}
F_97 ( V_2 ) ;
if ( V_102 )
F_72 ( V_102 ) ;
return V_102 ;
}
void F_98 ( struct V_1 * V_2 )
{
const void * V_141 = F_32 ( 0 ) ;
int V_142 ;
do {
V_142 = F_99 ( & V_2 -> V_15 ) ;
F_31 ( V_2 , V_143 , V_142 , V_141 ) ;
if ( V_142 > 0 )
return;
F_90 ( V_142 , >= , 0 ) ;
V_2 = F_94 ( V_2 ) ;
} while ( V_2 );
}
static void F_85 ( void )
{
struct V_1 * V_2 ;
unsigned int V_82 = V_85 ;
unsigned int V_144 , V_43 ;
F_2 ( L_1 ) ;
F_90 ( V_82 , >= , 0 ) ;
if ( V_82 < V_46 ) {
F_9 ( L_24 ) ;
return;
}
V_43 = V_145 ;
F_4 ( & V_84 ) ;
V_144 = V_79 ;
while ( V_144 > V_43 ) {
ASSERT ( ! F_70 ( & V_81 ) ) ;
V_2 = F_60 ( V_81 . V_102 ,
struct V_1 , V_80 ) ;
F_90 ( V_2 -> V_77 , == , V_78 ) ;
if ( F_70 ( & V_2 -> V_69 ) ) {
F_33 ( V_2 , - 1 , V_146 ) ;
V_2 -> V_77 = V_90 ;
F_64 ( & V_2 -> V_80 ) ;
} else {
F_33 ( V_2 , - 1 , V_95 ) ;
V_2 -> V_77 = V_88 ;
F_54 ( & V_2 -> V_80 ,
& V_96 ) ;
}
V_144 -- ;
}
V_79 = V_144 ;
F_6 ( & V_84 ) ;
F_90 ( V_144 , >= , 0 ) ;
F_9 ( L_25 ) ;
}
static void F_84 ( struct V_147 * V_148 )
{
struct V_1 * V_2 ;
unsigned long V_149 , V_150 , V_151 ;
unsigned int V_82 ;
bool V_152 = false ;
F_2 ( L_26 , V_148 ? 'w' : 'n' ) ;
if ( F_70 ( & V_133 ) ) {
F_9 ( L_27 ) ;
return;
}
if ( ! F_100 ( & V_153 ) ) {
F_9 ( L_28 ) ;
return;
}
V_82 = V_85 ;
V_102:
F_4 ( & V_84 ) ;
if ( F_70 ( & V_133 ) )
goto V_83;
V_2 = F_60 ( V_133 . V_102 ,
struct V_1 , V_80 ) ;
ASSERT ( F_11 ( V_119 , & V_2 -> V_14 ) ) ;
if ( ! V_134 ) {
V_149 = V_137 ;
if ( V_82 > V_145 )
V_149 = V_154 ;
V_150 = V_2 -> V_131 + V_149 ;
V_151 = F_101 ( V_132 ) ;
if ( F_102 ( V_150 , V_151 ) )
goto V_155;
}
F_33 ( V_2 , - 1 , V_156 ) ;
if ( ! F_95 ( V_119 , & V_2 -> V_14 ) )
F_18 () ;
V_2 -> V_77 = V_89 ;
F_64 ( & V_2 -> V_80 ) ;
F_6 ( & V_84 ) ;
F_50 ( V_2 ) ;
V_152 = true ;
V_82 -- ;
goto V_102;
V_155:
F_40 ( L_29 ) ;
if ( ! V_134 )
F_93 ( V_135 ,
& V_136 ,
V_150 - V_151 ) ;
V_83:
F_6 ( & V_84 ) ;
F_6 ( & V_153 ) ;
F_9 ( L_1 ) ;
}
void T_5 F_103 ( void )
{
F_2 ( L_1 ) ;
F_4 ( & V_84 ) ;
V_134 = true ;
F_6 ( & V_84 ) ;
F_104 ( & V_136 ) ;
if ( ! F_93 ( V_135 , & V_136 , 0 ) )
F_40 ( L_30 ) ;
F_9 ( L_1 ) ;
}
