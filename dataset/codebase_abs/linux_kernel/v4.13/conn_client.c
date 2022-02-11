static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 -> V_5 ;
int V_8 ;
F_2 ( L_1 ) ;
F_3 ( V_3 ) ;
F_4 ( & V_9 ) ;
V_8 = F_5 ( & V_10 , V_2 ,
1 , 0x40000000 , V_11 ) ;
if ( V_8 < 0 )
goto error;
F_6 ( & V_9 ) ;
F_7 () ;
V_2 -> V_12 . V_13 = V_5 -> V_13 ;
V_2 -> V_12 . V_14 = V_8 << V_15 ;
F_8 ( V_16 , & V_2 -> V_17 ) ;
F_9 ( L_2 , V_2 -> V_12 . V_14 ) ;
return 0 ;
error:
F_6 ( & V_9 ) ;
F_7 () ;
F_9 ( L_3 , V_8 ) ;
return V_8 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( F_11 ( V_16 , & V_2 -> V_17 ) ) {
F_4 ( & V_9 ) ;
F_12 ( & V_10 ,
V_2 -> V_12 . V_14 >> V_15 ) ;
F_6 ( & V_9 ) ;
}
}
void F_13 ( void )
{
struct V_1 * V_2 ;
int V_8 ;
if ( ! F_14 ( & V_10 ) ) {
F_15 (&rxrpc_client_conn_ids, conn, id) {
F_16 ( L_4 ,
V_2 , F_17 ( & V_2 -> V_18 ) ) ;
}
F_18 () ;
}
F_19 ( & V_10 ) ;
}
static struct V_1 *
F_20 ( struct V_19 * V_20 , T_1 V_3 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 = V_20 -> V_7 -> V_5 ;
int V_21 ;
F_2 ( L_1 ) ;
V_2 = F_21 ( V_3 ) ;
if ( ! V_2 ) {
F_9 ( L_5 ) ;
return F_22 ( - V_22 ) ;
}
F_23 ( & V_2 -> V_18 , 1 ) ;
if ( V_20 -> V_23 )
F_24 ( V_24 , & V_2 -> V_17 ) ;
if ( V_20 -> V_25 )
F_24 ( V_26 , & V_2 -> V_17 ) ;
V_2 -> V_6 = * V_20 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = V_20 -> V_31 ;
V_21 = F_1 ( V_2 , V_3 ) ;
if ( V_21 < 0 )
goto V_32;
V_21 = F_25 ( V_2 ) ;
if ( V_21 < 0 )
goto V_33;
V_21 = V_2 -> V_34 -> V_35 ( V_2 ) ;
if ( V_21 < 0 )
goto V_36;
F_26 ( & V_5 -> V_37 ) ;
F_27 ( & V_2 -> V_38 , & V_5 -> V_39 ) ;
F_28 ( & V_5 -> V_37 ) ;
V_20 -> V_40 = NULL ;
F_29 ( V_2 -> V_6 . V_7 ) ;
F_30 ( V_2 -> V_6 . V_41 ) ;
F_31 ( V_2 , V_42 , F_17 ( & V_2 -> V_18 ) ,
F_32 ( 0 ) ) ;
F_33 ( V_2 , - 1 , V_43 ) ;
F_9 ( L_6 , V_2 ) ;
return V_2 ;
V_36:
V_2 -> V_34 -> V_44 ( V_2 ) ;
V_33:
F_10 ( V_2 ) ;
V_32:
F_34 ( V_2 ) ;
F_9 ( L_3 , V_21 ) ;
return F_22 ( V_21 ) ;
}
static bool F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 -> V_5 ;
int V_45 , V_8 , V_46 , V_47 ;
if ( F_11 ( V_24 , & V_2 -> V_17 ) )
goto V_48;
if ( V_2 -> V_12 . V_13 != V_5 -> V_13 )
goto V_49;
V_45 = F_36 ( & V_10 ) ;
V_8 = V_2 -> V_12 . V_14 >> V_15 ;
V_46 = V_8 - V_45 ;
if ( V_46 < 0 )
V_46 = - V_46 ;
V_47 = F_37 ( V_50 * 4 , 1024U ) ;
if ( V_46 > V_47 )
goto V_49;
return true ;
V_49:
F_8 ( V_24 , & V_2 -> V_17 ) ;
V_48:
return false ;
}
static int F_38 ( struct V_51 * V_52 ,
struct V_19 * V_20 ,
struct V_53 * V_54 ,
T_1 V_3 )
{
struct V_1 * V_2 , * V_55 = NULL ;
struct V_56 * V_7 = V_20 -> V_7 ;
struct V_57 * V_58 , * * V_59 , * V_60 ;
long V_61 ;
int V_21 = - V_22 ;
F_2 ( L_7 , V_52 -> V_62 , V_52 -> V_63 ) ;
V_20 -> V_40 = F_39 ( V_20 -> V_7 , V_54 , V_3 ) ;
if ( ! V_20 -> V_40 )
goto error;
V_52 -> V_64 = V_20 -> V_40 -> V_64 ;
if ( V_52 -> V_64 >= V_52 -> V_65 )
V_52 -> V_66 = V_67 ;
else
V_52 -> V_66 = V_68 ;
if ( ! V_20 -> V_23 ) {
F_40 ( L_8 ) ;
F_4 ( & V_7 -> V_69 ) ;
V_58 = V_7 -> V_70 . V_57 ;
while ( V_58 ) {
V_2 = F_41 ( V_58 , struct V_1 , V_71 ) ;
#define F_42 ( T_2 ) ((long)conn->params.X - (long)cp->X)
V_61 = ( F_42 ( V_40 ) ? :
F_42 ( V_41 ) ? :
F_42 ( V_72 ) ? :
F_42 ( V_25 ) ) ;
#undef F_42
if ( V_61 < 0 ) {
V_58 = V_58 -> V_73 ;
} else if ( V_61 > 0 ) {
V_58 = V_58 -> V_74 ;
} else {
if ( F_35 ( V_2 ) &&
F_43 ( V_2 ) )
goto V_75;
break;
}
}
F_6 ( & V_7 -> V_69 ) ;
}
F_40 ( L_9 ) ;
V_55 = F_20 ( V_20 , V_3 ) ;
if ( F_44 ( V_55 ) ) {
V_21 = F_45 ( V_55 ) ;
goto V_76;
}
F_27 ( & V_52 -> V_77 , & V_55 -> V_78 ) ;
if ( V_20 -> V_23 ) {
V_52 -> V_2 = V_55 ;
V_52 -> V_79 = V_55 -> V_79 ;
V_52 -> V_31 = V_55 -> V_31 ;
F_9 ( L_10 , V_55 -> V_62 ) ;
return 0 ;
}
F_40 ( L_11 ) ;
F_4 ( & V_7 -> V_69 ) ;
V_59 = & V_7 -> V_70 . V_57 ;
V_60 = NULL ;
while ( * V_59 ) {
V_60 = * V_59 ;
V_2 = F_41 ( V_60 , struct V_1 , V_71 ) ;
#define F_42 ( T_2 ) ((long)conn->params.X - (long)candidate->params.X)
V_61 = ( F_42 ( V_40 ) ? :
F_42 ( V_41 ) ? :
F_42 ( V_72 ) ? :
F_42 ( V_25 ) ) ;
#undef F_42
if ( V_61 < 0 ) {
V_59 = & ( * V_59 ) -> V_73 ;
} else if ( V_61 > 0 ) {
V_59 = & ( * V_59 ) -> V_74 ;
} else {
if ( F_35 ( V_2 ) &&
F_43 ( V_2 ) )
goto V_75;
F_40 ( L_12 ) ;
F_46 ( V_80 , & V_2 -> V_17 ) ;
F_47 ( & V_2 -> V_71 ,
& V_55 -> V_71 ,
& V_7 -> V_70 ) ;
F_33 ( V_2 , - 1 , V_81 ) ;
goto V_82;
}
}
F_40 ( L_9 ) ;
F_48 ( & V_55 -> V_71 , V_60 , V_59 ) ;
F_49 ( & V_55 -> V_71 , & V_7 -> V_70 ) ;
V_82:
F_8 ( V_80 , & V_55 -> V_17 ) ;
V_52 -> V_2 = V_55 ;
V_52 -> V_79 = V_55 -> V_79 ;
V_52 -> V_31 = V_55 -> V_31 ;
F_6 ( & V_7 -> V_69 ) ;
F_9 ( L_13 , V_55 -> V_62 ) ;
return 0 ;
V_75:
F_40 ( L_14 ) ;
F_6 ( & V_7 -> V_69 ) ;
if ( V_55 ) {
F_33 ( V_55 , - 1 , V_83 ) ;
F_50 ( V_55 ) ;
V_55 = NULL ;
}
F_4 ( & V_2 -> V_84 ) ;
V_52 -> V_2 = V_2 ;
V_52 -> V_79 = V_2 -> V_79 ;
V_52 -> V_31 = V_2 -> V_31 ;
F_51 ( & V_52 -> V_77 , & V_2 -> V_78 ) ;
F_6 ( & V_2 -> V_84 ) ;
F_9 ( L_15 , V_2 -> V_62 ) ;
return 0 ;
V_76:
F_52 ( V_20 -> V_40 ) ;
V_20 -> V_40 = NULL ;
error:
F_9 ( L_3 , V_21 ) ;
return V_21 ;
}
static void F_53 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( F_11 ( V_26 , & V_2 -> V_17 ) ) {
F_33 ( V_2 , - 1 , V_85 ) ;
V_2 -> V_86 = V_87 ;
} else {
F_33 ( V_2 , - 1 , V_88 ) ;
V_2 -> V_86 = V_89 ;
}
V_5 -> V_90 ++ ;
F_54 ( & V_2 -> V_91 , & V_5 -> V_92 ) ;
}
static void F_55 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
unsigned int V_93 ;
F_2 ( L_16 , V_2 -> V_62 , V_2 -> V_86 ) ;
if ( V_2 -> V_86 == V_89 ||
V_2 -> V_86 == V_87 )
goto V_94;
F_4 ( & V_5 -> V_95 ) ;
V_93 = V_5 -> V_96 ;
if ( ! F_56 ( V_97 , & V_2 -> V_17 ) ) {
F_33 ( V_2 , - 1 , V_98 ) ;
V_5 -> V_96 = V_93 + 1 ;
}
switch ( V_2 -> V_86 ) {
case V_89 :
case V_87 :
case V_99 :
break;
case V_100 :
case V_101 :
case V_102 :
if ( V_93 >= V_50 )
goto V_103;
goto V_104;
default:
F_18 () ;
}
V_105:
F_6 ( & V_5 -> V_95 ) ;
V_94:
F_9 ( L_17 , V_2 -> V_86 ) ;
return;
V_104:
F_40 ( L_18 ) ;
F_53 ( V_5 , V_2 ) ;
goto V_105;
V_103:
F_40 ( L_19 ) ;
F_33 ( V_2 , - 1 , V_106 ) ;
V_2 -> V_86 = V_99 ;
F_54 ( & V_2 -> V_91 , & V_5 -> V_107 ) ;
goto V_105;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned int V_108 )
{
struct V_109 * V_110 = & V_2 -> V_111 [ V_108 ] ;
F_58 ( V_110 -> V_52 , NULL ) ;
V_2 -> V_112 &= ~ ( 1 << V_108 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
unsigned int V_108 )
{
struct V_109 * V_110 = & V_2 -> V_111 [ V_108 ] ;
struct V_51 * V_52 = F_60 ( V_2 -> V_78 . V_113 ,
struct V_51 , V_77 ) ;
T_3 V_114 = V_110 -> V_115 + 1 ;
F_33 ( V_2 , V_108 , V_116 ) ;
F_61 ( & V_52 -> V_117 ) ;
V_52 -> V_29 = V_118 ;
F_62 ( & V_52 -> V_117 ) ;
F_63 ( V_52 ) ;
F_64 ( & V_52 -> V_77 ) ;
V_2 -> V_112 |= 1 << V_108 ;
V_52 -> V_40 = F_65 ( V_2 -> V_6 . V_40 ) ;
V_52 -> V_14 = V_2 -> V_12 . V_14 | V_108 ;
V_52 -> V_114 = V_114 ;
F_66 ( V_52 ) ;
F_67 ( L_20 ,
V_52 -> V_14 , V_52 -> V_114 , V_52 -> V_62 , V_2 -> V_62 ) ;
F_68 () ;
V_110 -> V_114 = V_114 ;
F_58 ( V_110 -> V_52 , V_52 ) ;
F_69 ( & V_52 -> V_119 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
T_4 V_120 , V_121 ;
switch ( V_2 -> V_86 ) {
case V_89 :
V_121 = V_122 ;
break;
case V_87 :
V_121 = 0x01 ;
break;
default:
return;
}
while ( ! F_71 ( & V_2 -> V_78 ) &&
( V_120 = ~ V_2 -> V_112 ,
V_120 &= V_121 ,
V_120 != 0 ) )
F_59 ( V_2 , F_72 ( V_120 ) ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
F_2 ( L_21 , V_2 -> V_62 ) ;
F_33 ( V_2 , - 1 , V_123 ) ;
if ( V_2 -> V_112 == V_122 )
return;
F_4 ( & V_2 -> V_84 ) ;
F_70 ( V_2 ) ;
F_6 ( & V_2 -> V_84 ) ;
F_9 ( L_1 ) ;
}
static int F_74 ( struct V_51 * V_52 , T_1 V_3 )
{
int V_21 = 0 ;
F_2 ( L_21 , V_52 -> V_62 ) ;
if ( ! V_52 -> V_114 ) {
F_75 ( V_124 , V_125 ) ;
if ( ! F_76 ( V_3 ) ) {
V_21 = - V_126 ;
goto V_94;
}
F_77 ( & V_52 -> V_119 , & V_124 ) ;
for (; ; ) {
F_78 ( V_127 ) ;
if ( V_52 -> V_114 )
break;
if ( F_79 ( V_125 ) ) {
V_21 = - V_128 ;
break;
}
F_80 () ;
}
F_81 ( & V_52 -> V_119 , & V_124 ) ;
F_82 ( V_129 ) ;
}
F_83 () ;
V_94:
F_9 ( L_3 , V_21 ) ;
return V_21 ;
}
int F_84 ( struct V_51 * V_52 ,
struct V_19 * V_20 ,
struct V_53 * V_54 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_20 -> V_7 -> V_5 ;
int V_21 ;
F_2 ( L_7 , V_52 -> V_62 , V_52 -> V_63 ) ;
F_85 ( & V_5 -> V_130 . V_131 ) ;
F_86 ( V_5 ) ;
V_21 = F_38 ( V_52 , V_20 , V_54 , V_3 ) ;
if ( V_21 < 0 )
return V_21 ;
F_55 ( V_5 , V_52 -> V_2 ) ;
F_73 ( V_52 -> V_2 ) ;
V_21 = F_74 ( V_52 , V_3 ) ;
if ( V_21 < 0 )
F_87 ( V_52 ) ;
F_9 ( L_3 , V_21 ) ;
return V_21 ;
}
static void F_88 ( struct V_1 * V_2 ,
unsigned int V_108 )
{
if ( ! F_56 ( V_132 , & V_2 -> V_17 ) ) {
F_33 ( V_2 , V_108 , V_133 ) ;
F_89 ( V_2 ) ;
}
}
void F_90 ( struct V_51 * V_52 )
{
unsigned int V_108 = V_52 -> V_14 & V_134 ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_109 * V_110 = & V_2 -> V_111 [ V_108 ] ;
if ( ! F_56 ( V_135 , & V_52 -> V_17 ) ) {
V_110 -> V_115 ++ ;
if ( V_110 -> V_115 >= V_136 )
F_8 ( V_24 , & V_2 -> V_17 ) ;
F_88 ( V_2 , V_108 ) ;
}
}
void F_87 ( struct V_51 * V_52 )
{
unsigned int V_108 = V_52 -> V_14 & V_134 ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_109 * V_110 = & V_2 -> V_111 [ V_108 ] ;
struct V_4 * V_5 = V_4 ( F_91 ( & V_52 -> V_137 -> V_138 ) ) ;
F_33 ( V_2 , V_108 , V_139 ) ;
V_52 -> V_2 = NULL ;
F_4 ( & V_2 -> V_84 ) ;
if ( ! F_71 ( & V_52 -> V_77 ) ) {
F_40 ( L_22 ) ;
F_92 ( V_52 -> V_114 , == , 0 ) ;
ASSERT ( ! F_11 ( V_135 , & V_52 -> V_17 ) ) ;
F_64 ( & V_52 -> V_77 ) ;
F_33 ( V_2 , V_108 , V_140 ) ;
F_4 ( & V_5 -> V_95 ) ;
if ( V_2 -> V_86 == V_99 &&
F_71 ( & V_2 -> V_78 ) &&
! V_2 -> V_112 )
goto V_141;
goto V_94;
}
F_92 ( F_93 ( V_110 -> V_52 ) , == , V_52 ) ;
if ( F_11 ( V_135 , & V_52 -> V_17 ) ) {
F_40 ( L_23 , V_52 -> V_114 , V_52 -> V_142 ) ;
F_94 ( V_2 , V_52 ) ;
}
if ( V_2 -> V_86 == V_89 &&
! F_71 ( & V_2 -> V_78 ) ) {
F_33 ( V_2 , V_108 , V_143 ) ;
F_59 ( V_2 , V_108 ) ;
goto V_144;
}
F_4 ( & V_5 -> V_95 ) ;
switch ( V_2 -> V_86 ) {
case V_87 :
if ( F_11 ( V_132 , & V_2 -> V_17 ) ) {
F_46 ( V_26 , & V_2 -> V_17 ) ;
F_33 ( V_2 , V_108 , V_88 ) ;
V_2 -> V_86 = V_89 ;
F_70 ( V_2 ) ;
}
case V_89 :
if ( F_71 ( & V_2 -> V_78 ) ) {
F_57 ( V_2 , V_108 ) ;
if ( ! V_2 -> V_112 ) {
V_5 -> V_90 -- ;
goto V_141;
}
goto V_94;
}
F_33 ( V_2 , V_108 , V_143 ) ;
F_59 ( V_2 , V_108 ) ;
goto V_94;
case V_101 :
F_57 ( V_2 , V_108 ) ;
ASSERT ( F_71 ( & V_2 -> V_78 ) ) ;
if ( ! V_2 -> V_112 )
goto V_141;
goto V_94;
case V_99 :
F_57 ( V_2 , V_108 ) ;
goto V_94;
default:
F_18 () ;
}
V_94:
F_6 ( & V_5 -> V_95 ) ;
V_144:
F_6 ( & V_2 -> V_84 ) ;
F_50 ( V_2 ) ;
F_9 ( L_1 ) ;
return;
V_141:
if ( F_11 ( V_132 , & V_2 -> V_17 ) ) {
F_33 ( V_2 , V_108 , V_145 ) ;
V_2 -> V_146 = V_147 ;
V_2 -> V_86 = V_102 ;
F_54 ( & V_2 -> V_91 , & V_5 -> V_148 ) ;
if ( V_5 -> V_148 . V_113 == & V_2 -> V_91 &&
! V_5 -> V_149 )
F_95 ( V_150 ,
& V_5 -> V_130 ,
V_151 ) ;
} else {
F_33 ( V_2 , V_108 , V_152 ) ;
V_2 -> V_86 = V_100 ;
F_64 ( & V_2 -> V_91 ) ;
}
goto V_94;
}
static struct V_1 *
F_96 ( struct V_1 * V_2 )
{
struct V_1 * V_113 = NULL ;
struct V_56 * V_7 = V_2 -> V_6 . V_7 ;
struct V_4 * V_5 = V_7 -> V_5 ;
unsigned int V_93 ;
F_33 ( V_2 , - 1 , V_153 ) ;
if ( F_11 ( V_80 , & V_2 -> V_17 ) ) {
F_4 ( & V_7 -> V_69 ) ;
if ( F_97 ( V_80 ,
& V_2 -> V_17 ) )
F_98 ( & V_2 -> V_71 , & V_7 -> V_70 ) ;
F_6 ( & V_7 -> V_69 ) ;
}
F_10 ( V_2 ) ;
F_92 ( V_2 -> V_86 , == , V_100 ) ;
if ( F_11 ( V_97 , & V_2 -> V_17 ) ) {
F_33 ( V_2 , - 1 , V_154 ) ;
F_4 ( & V_5 -> V_95 ) ;
V_93 = -- V_5 -> V_96 ;
if ( V_93 < V_50 &&
! F_71 ( & V_5 -> V_107 ) ) {
V_113 = F_60 ( V_5 -> V_107 . V_113 ,
struct V_1 , V_91 ) ;
F_89 ( V_113 ) ;
F_53 ( V_5 , V_113 ) ;
}
F_6 ( & V_5 -> V_95 ) ;
}
F_99 ( V_2 ) ;
if ( V_113 )
F_73 ( V_113 ) ;
return V_113 ;
}
void F_100 ( struct V_1 * V_2 )
{
const void * V_155 = F_32 ( 0 ) ;
int V_156 ;
do {
V_156 = F_101 ( & V_2 -> V_18 ) ;
F_31 ( V_2 , V_157 , V_156 , V_155 ) ;
if ( V_156 > 0 )
return;
F_92 ( V_156 , >= , 0 ) ;
V_2 = F_96 ( V_2 ) ;
} while ( V_2 );
}
static void F_86 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
unsigned int V_93 = V_5 -> V_96 ;
unsigned int V_158 , V_47 ;
F_2 ( L_1 ) ;
F_92 ( V_93 , >= , 0 ) ;
if ( V_93 < V_50 ) {
F_9 ( L_24 ) ;
return;
}
V_47 = V_159 ;
F_4 ( & V_5 -> V_95 ) ;
V_158 = V_5 -> V_90 ;
while ( V_158 > V_47 ) {
ASSERT ( ! F_71 ( & V_5 -> V_92 ) ) ;
V_2 = F_60 ( V_5 -> V_92 . V_113 ,
struct V_1 , V_91 ) ;
F_102 ( V_2 -> V_86 != V_89 ,
V_2 -> V_86 , == , V_87 ) ;
if ( F_71 ( & V_2 -> V_78 ) ) {
F_33 ( V_2 , - 1 , V_160 ) ;
V_2 -> V_86 = V_101 ;
F_64 ( & V_2 -> V_91 ) ;
} else {
F_33 ( V_2 , - 1 , V_106 ) ;
V_2 -> V_86 = V_99 ;
F_54 ( & V_2 -> V_91 ,
& V_5 -> V_107 ) ;
}
V_158 -- ;
}
V_5 -> V_90 = V_158 ;
F_6 ( & V_5 -> V_95 ) ;
F_92 ( V_158 , >= , 0 ) ;
F_9 ( L_25 ) ;
}
void F_85 ( struct V_161 * V_131 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 =
F_103 ( F_104 ( V_131 ) ,
struct V_4 , V_130 ) ;
unsigned long V_162 , V_163 , V_164 ;
unsigned int V_93 ;
bool V_165 = false ;
F_2 ( L_1 ) ;
if ( F_71 ( & V_5 -> V_148 ) ) {
F_9 ( L_26 ) ;
return;
}
if ( ! F_105 ( & V_5 -> V_166 ) ) {
F_9 ( L_27 ) ;
return;
}
V_93 = V_5 -> V_96 ;
V_113:
F_4 ( & V_5 -> V_95 ) ;
if ( F_71 ( & V_5 -> V_148 ) )
goto V_94;
V_2 = F_60 ( V_5 -> V_148 . V_113 ,
struct V_1 , V_91 ) ;
ASSERT ( F_11 ( V_132 , & V_2 -> V_17 ) ) ;
if ( ! V_5 -> V_149 ) {
V_162 = V_151 ;
if ( V_93 > V_159 )
V_162 = V_167 ;
V_163 = V_2 -> V_146 + V_162 ;
V_164 = F_106 ( V_147 ) ;
if ( F_107 ( V_163 , V_164 ) )
goto V_168;
}
F_33 ( V_2 , - 1 , V_169 ) ;
if ( ! F_97 ( V_132 , & V_2 -> V_17 ) )
F_18 () ;
V_2 -> V_86 = V_100 ;
F_64 ( & V_2 -> V_91 ) ;
F_6 ( & V_5 -> V_95 ) ;
F_50 ( V_2 ) ;
V_165 = true ;
V_93 -- ;
goto V_113;
V_168:
F_40 ( L_28 ) ;
if ( ! V_5 -> V_149 )
F_95 ( V_150 ,
& V_5 -> V_130 ,
V_163 - V_164 ) ;
V_94:
F_6 ( & V_5 -> V_95 ) ;
F_6 ( & V_5 -> V_166 ) ;
F_9 ( L_1 ) ;
}
void F_108 ( struct V_4 * V_5 )
{
F_2 ( L_1 ) ;
F_4 ( & V_5 -> V_95 ) ;
V_5 -> V_149 = true ;
F_6 ( & V_5 -> V_95 ) ;
F_109 ( & V_5 -> V_130 ) ;
if ( ! F_95 ( V_150 , & V_5 -> V_130 , 0 ) )
F_40 ( L_29 ) ;
F_9 ( L_1 ) ;
}
