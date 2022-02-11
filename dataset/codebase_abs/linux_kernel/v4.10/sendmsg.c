static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
long * V_5 )
{
F_2 ( V_6 , V_7 ) ;
int V_8 ;
F_3 ( L_1 ,
V_4 -> V_9 , V_4 -> V_10 , V_4 -> V_11 ) ;
F_4 ( & V_4 -> V_12 , & V_6 ) ;
for (; ; ) {
F_5 ( V_13 ) ;
V_8 = 0 ;
if ( V_4 -> V_10 - V_4 -> V_9 <
F_6 (unsigned int, call->tx_winsize,
call->cong_cwnd + call->cong_extra) )
break;
if ( V_4 -> V_14 >= V_15 ) {
V_8 = - V_4 -> error ;
break;
}
if ( F_7 ( V_7 ) ) {
V_8 = F_8 ( * V_5 ) ;
break;
}
F_9 ( V_4 , V_16 ) ;
F_10 ( & V_2 -> V_17 ) ;
* V_5 = F_11 ( * V_5 ) ;
F_12 ( & V_2 -> V_17 ) ;
}
F_13 ( & V_4 -> V_12 , & V_6 ) ;
F_5 ( V_18 ) ;
F_14 ( L_2 , V_8 ) ;
return V_8 ;
}
static inline void F_15 ( struct V_3 * V_4 , int V_19 )
{
F_16 ( & V_4 -> V_20 ) ;
if ( V_4 -> V_14 < V_15 ) {
V_4 -> V_21 [ V_19 ] = V_22 ;
if ( ! F_17 ( V_23 , & V_4 -> V_24 ) )
F_18 ( V_4 ) ;
}
F_19 ( & V_4 -> V_20 ) ;
}
static void F_20 ( struct V_3 * V_4 , struct V_25 * V_26 ,
bool V_27 )
{
struct V_28 * V_29 = F_21 ( V_26 ) ;
T_1 V_30 = V_29 -> V_31 . V_30 ;
int V_8 , V_19 ;
T_2 V_32 = V_33 ;
F_22 ( L_3 , V_26 , V_30 ) ;
F_23 ( V_30 , == , V_4 -> V_10 + 1 ) ;
if ( V_27 )
V_32 |= V_34 ;
V_26 -> V_35 = F_24 () ;
V_19 = V_30 & V_36 ;
F_25 ( V_26 , V_37 ) ;
V_4 -> V_21 [ V_19 ] = V_32 ;
F_26 () ;
V_4 -> V_38 [ V_19 ] = V_26 ;
V_4 -> V_10 = V_30 ;
if ( V_27 )
F_9 ( V_4 , V_39 ) ;
else
F_9 ( V_4 , V_40 ) ;
if ( V_27 || V_4 -> V_14 == V_41 ) {
F_27 ( L_4 ) ;
F_28 ( & V_4 -> V_42 ) ;
switch ( V_4 -> V_14 ) {
case V_43 :
V_4 -> V_14 = V_44 ;
break;
case V_41 :
V_4 -> V_14 = V_45 ;
V_4 -> V_46 = V_4 -> V_47 ;
if ( V_4 -> V_48 == V_49 )
V_4 -> V_48 = 0 ;
F_29 ( V_4 , V_50 ,
F_24 () ) ;
if ( ! V_27 )
break;
case V_45 :
V_4 -> V_14 = V_51 ;
break;
default:
break;
}
F_30 ( & V_4 -> V_42 ) ;
}
if ( V_30 == 1 && F_31 ( V_4 ) )
F_32 ( V_4 ) ;
V_8 = F_33 ( V_4 , V_26 , false ) ;
if ( V_8 < 0 ) {
F_27 ( L_5 , V_8 ) ;
F_15 ( V_4 , V_19 ) ;
} else {
T_3 V_52 = F_24 () , V_53 ;
V_53 = F_34 ( V_52 , V_54 ) ;
if ( F_35 ( V_53 , V_4 -> V_53 ) ) {
V_4 -> V_53 = V_53 ;
F_36 ( V_4 , V_55 , V_52 ) ;
}
}
F_37 ( V_26 , V_56 ) ;
F_14 ( L_6 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_57 * V_58 , T_4 V_59 )
{
struct V_28 * V_29 ;
struct V_25 * V_26 ;
struct V_60 * V_17 = & V_2 -> V_17 ;
long V_5 ;
bool V_61 ;
int V_8 , V_62 ;
V_5 = F_39 ( V_17 , V_58 -> V_63 & V_64 ) ;
F_40 ( V_65 , V_17 ) ;
if ( V_17 -> V_66 || ( V_17 -> V_67 & V_68 ) )
return - V_69 ;
V_61 = V_58 -> V_63 & V_70 ;
V_26 = V_4 -> V_71 ;
V_4 -> V_71 = NULL ;
F_41 ( V_26 , V_72 ) ;
V_62 = 0 ;
do {
if ( V_4 -> V_48 == V_73 )
F_42 ( V_4 , false ) ;
if ( ! V_26 ) {
T_4 V_74 , V_75 , V_76 , V_77 ;
F_27 ( L_7 ) ;
if ( V_4 -> V_10 - V_4 -> V_9 >=
F_6 (unsigned int, call->tx_winsize,
call->cong_cwnd + call->cong_extra) ) {
V_8 = - V_78 ;
if ( V_58 -> V_63 & V_64 )
goto V_79;
V_8 = F_1 ( V_2 , V_4 ,
& V_5 ) ;
if ( V_8 < 0 )
goto V_79;
}
V_76 = V_80 ;
V_76 -= V_4 -> V_81 -> V_82 ;
V_76 &= ~ ( V_4 -> V_81 -> V_83 - 1UL ) ;
V_75 = V_76 ;
if ( V_75 > F_43 ( V_58 ) && ! V_61 )
V_75 = F_43 ( V_58 ) ;
V_77 = V_75 + V_4 -> V_81 -> V_83 ;
V_77 &= ~ ( V_4 -> V_81 -> V_83 - 1UL ) ;
V_74 = V_77 + V_4 -> V_81 -> V_82 ;
F_27 ( L_8 , V_75 , V_77 , V_74 ) ;
V_26 = F_44 (
V_17 , V_74 , V_58 -> V_63 & V_64 , & V_8 ) ;
if ( ! V_26 )
goto V_79;
F_45 ( V_26 , V_84 ) ;
F_27 ( L_9 , V_26 ) ;
F_23 ( V_26 -> V_85 , == , 0 ) ;
F_27 ( L_10 , V_4 -> V_81 -> V_82 ) ;
F_46 ( V_26 , V_4 -> V_81 -> V_82 ) ;
V_26 -> V_59 += V_4 -> V_81 -> V_82 ;
V_29 = F_21 ( V_26 ) ;
V_29 -> V_86 = V_75 ;
if ( V_29 -> V_86 > F_47 ( V_26 ) )
V_29 -> V_86 = F_47 ( V_26 ) ;
F_22 ( L_11 ,
F_48 ( V_26 ) ,
F_47 ( V_26 ) ,
F_49 ( V_26 ) ,
V_29 -> V_86 ) ;
V_26 -> V_87 = V_88 ;
}
F_27 ( L_12 ) ;
V_29 = F_21 ( V_26 ) ;
if ( F_43 ( V_58 ) > 0 ) {
int V_89 = F_47 ( V_26 ) ;
F_23 ( V_89 , > , 0 ) ;
if ( V_89 > F_43 ( V_58 ) )
V_89 = F_43 ( V_58 ) ;
if ( V_89 > V_29 -> V_86 )
V_89 = V_29 -> V_86 ;
F_27 ( L_13 ) ;
V_8 = F_50 ( V_26 , & V_58 -> V_90 , V_89 ) ;
F_27 ( L_14 ) ;
if ( V_8 < 0 )
goto V_91;
V_29 -> V_86 -= V_89 ;
V_26 -> V_85 += V_89 ;
V_62 += V_89 ;
}
if ( V_4 -> V_14 == V_15 )
goto V_92;
if ( V_29 -> V_86 <= 0 ||
( F_43 ( V_58 ) == 0 && ! V_61 ) ) {
struct V_93 * V_81 = V_4 -> V_81 ;
T_5 V_30 ;
T_4 V_94 ;
if ( V_81 -> V_95 ) {
V_94 = V_81 -> V_82 + V_26 -> V_85 ;
V_94 = V_81 -> V_83 - V_94 ;
V_94 &= V_81 -> V_83 - 1 ;
F_27 ( L_15 , V_94 ) ;
if ( V_94 )
memset ( F_51 ( V_26 , V_94 ) , 0 , V_94 ) ;
}
V_30 = V_4 -> V_10 + 1 ;
V_29 -> V_31 . V_30 = V_30 ;
V_29 -> V_31 . V_96 = 0 ;
V_29 -> V_31 . V_97 = V_81 -> V_98 ;
if ( F_43 ( V_58 ) == 0 && ! V_61 )
V_29 -> V_31 . V_97 |= V_99 ;
else if ( V_4 -> V_10 - V_4 -> V_9 <
V_4 -> V_11 )
V_29 -> V_31 . V_97 |= V_100 ;
V_8 = V_81 -> V_101 -> V_102 (
V_4 , V_26 , V_26 -> V_85 , V_26 -> V_103 ) ;
if ( V_8 < 0 )
goto V_104;
F_20 ( V_4 , V_26 , ! F_43 ( V_58 ) && ! V_61 ) ;
V_26 = NULL ;
}
} while ( F_43 ( V_58 ) > 0 );
V_105:
V_8 = V_62 ;
V_104:
V_4 -> V_71 = V_26 ;
F_14 ( L_2 , V_8 ) ;
return V_8 ;
V_92:
F_37 ( V_26 , V_56 ) ;
F_14 ( L_2 , - V_4 -> error ) ;
return - V_4 -> error ;
V_79:
if ( V_62 )
goto V_105;
goto V_104;
V_91:
V_8 = - V_106 ;
goto V_104;
}
static int F_52 ( struct V_57 * V_58 ,
unsigned long * V_107 ,
enum V_108 * V_109 ,
T_6 * V_110 ,
bool * V_111 )
{
struct V_112 * V_113 ;
bool V_114 = false ;
int V_59 ;
* V_109 = V_115 ;
if ( V_58 -> V_116 == 0 )
return - V_117 ;
F_53 (cmsg, msg) {
if ( ! F_54 ( V_58 , V_113 ) )
return - V_117 ;
V_59 = V_113 -> V_118 - F_55 ( sizeof( struct V_112 ) ) ;
F_27 ( L_16 ,
V_113 -> V_119 , V_113 -> V_120 , V_59 ) ;
if ( V_113 -> V_119 != V_121 )
continue;
switch ( V_113 -> V_120 ) {
case V_122 :
if ( V_58 -> V_63 & V_123 ) {
if ( V_59 != sizeof( T_6 ) )
return - V_117 ;
* V_107 = * ( T_6 * ) F_56 ( V_113 ) ;
} else {
if ( V_59 != sizeof( unsigned long ) )
return - V_117 ;
* V_107 = * ( unsigned long * )
F_56 ( V_113 ) ;
}
F_27 ( L_17 , * V_107 ) ;
V_114 = true ;
break;
case V_124 :
if ( * V_109 != V_115 )
return - V_117 ;
* V_109 = V_125 ;
if ( V_59 != sizeof( * V_110 ) )
return - V_117 ;
* V_110 = * ( unsigned int * ) F_56 ( V_113 ) ;
F_27 ( L_18 , * V_110 ) ;
if ( * V_110 == 0 )
return - V_117 ;
break;
case V_126 :
if ( * V_109 != V_115 )
return - V_117 ;
* V_109 = V_127 ;
if ( V_59 != 0 )
return - V_117 ;
break;
case V_128 :
* V_111 = true ;
if ( V_59 != 0 )
return - V_117 ;
break;
default:
return - V_117 ;
}
}
if ( ! V_114 )
return - V_117 ;
F_14 ( L_19 ) ;
return 0 ;
}
static struct V_3 *
F_57 ( struct V_1 * V_2 , struct V_57 * V_58 ,
unsigned long V_107 , bool V_129 )
{
struct V_130 V_131 ;
struct V_3 * V_4 ;
struct V_132 * V_132 ;
F_58 ( struct V_133 * , V_134 , V_58 -> V_135 ) ;
F_3 ( L_6 ) ;
if ( ! V_58 -> V_135 )
return F_59 ( - V_136 ) ;
V_132 = V_2 -> V_132 ;
if ( V_132 && ! V_2 -> V_132 -> V_137 . V_138 [ 0 ] )
V_132 = NULL ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_131 . V_139 = V_2 -> V_139 ;
V_131 . V_132 = V_2 -> V_132 ;
V_131 . V_140 = V_2 -> V_141 ;
V_131 . V_129 = V_2 -> V_129 | V_129 ;
V_131 . V_142 = V_134 -> V_143 ;
V_4 = F_60 ( V_2 , & V_131 , V_134 , V_107 , V_144 ) ;
F_14 ( L_20 , V_4 ) ;
return V_4 ;
}
int F_61 ( struct V_1 * V_2 , struct V_57 * V_58 , T_4 V_59 )
{
enum V_108 V_145 ;
struct V_3 * V_4 ;
unsigned long V_107 = 0 ;
bool V_129 = false ;
T_6 V_110 = 0 ;
int V_8 ;
F_3 ( L_6 ) ;
V_8 = F_52 ( V_58 , & V_107 , & V_145 , & V_110 ,
& V_129 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_145 == V_127 ) {
if ( V_2 -> V_17 . V_146 != V_147 )
return - V_117 ;
V_4 = F_62 ( V_2 , V_107 , NULL ) ;
if ( F_63 ( V_4 ) )
return F_64 ( V_4 ) ;
F_65 ( V_4 , V_148 ) ;
return 0 ;
}
V_4 = F_66 ( V_2 , V_107 ) ;
if ( ! V_4 ) {
if ( V_145 != V_115 )
return - V_149 ;
V_4 = F_57 ( V_2 , V_58 , V_107 ,
V_129 ) ;
if ( F_63 ( V_4 ) )
return F_64 ( V_4 ) ;
}
F_27 ( L_21 ,
V_4 -> V_150 , V_4 -> V_107 , V_4 -> V_14 , V_4 -> V_81 ) ;
if ( V_4 -> V_14 >= V_15 ) {
V_8 = - V_151 ;
} else if ( V_145 == V_125 ) {
V_8 = 0 ;
if ( F_67 ( L_22 , V_4 , 0 , V_110 , V_152 ) )
V_8 = F_68 ( V_4 ) ;
} else if ( V_145 != V_115 ) {
V_8 = - V_117 ;
} else if ( F_31 ( V_4 ) &&
V_4 -> V_14 != V_43 ) {
V_8 = - V_153 ;
} else if ( F_69 ( V_4 ) &&
V_4 -> V_14 != V_41 &&
V_4 -> V_14 != V_45 ) {
V_8 = - V_153 ;
} else {
V_8 = F_38 ( V_2 , V_4 , V_58 , V_59 ) ;
}
F_65 ( V_4 , V_148 ) ;
F_14 ( L_2 , V_8 ) ;
return V_8 ;
}
int F_70 ( struct V_154 * V_60 , struct V_3 * V_4 ,
struct V_57 * V_58 , T_4 V_59 )
{
int V_8 ;
F_3 ( L_23 , V_4 -> V_150 , V_155 [ V_4 -> V_14 ] ) ;
F_23 ( V_58 -> V_135 , == , NULL ) ;
F_23 ( V_58 -> V_156 , == , NULL ) ;
F_12 ( V_60 -> V_17 ) ;
F_27 ( L_21 ,
V_4 -> V_150 , V_4 -> V_107 , V_4 -> V_14 , V_4 -> V_81 ) ;
if ( V_4 -> V_14 >= V_15 ) {
V_8 = - V_151 ;
} else if ( V_4 -> V_14 != V_43 &&
V_4 -> V_14 != V_41 &&
V_4 -> V_14 != V_45 ) {
V_8 = - V_153 ;
} else {
V_8 = F_38 ( F_71 ( V_60 -> V_17 ) , V_4 , V_58 , V_59 ) ;
}
F_10 ( V_60 -> V_17 ) ;
F_14 ( L_2 , V_8 ) ;
return V_8 ;
}
void F_72 ( struct V_154 * V_60 , struct V_3 * V_4 ,
T_6 V_110 , int error , const char * V_157 )
{
F_3 ( L_24 , V_4 -> V_150 , V_110 , error , V_157 ) ;
F_12 ( V_60 -> V_17 ) ;
if ( F_67 ( V_157 , V_4 , 0 , V_110 , error ) )
F_68 ( V_4 ) ;
F_10 ( V_60 -> V_17 ) ;
F_14 ( L_6 ) ;
}
