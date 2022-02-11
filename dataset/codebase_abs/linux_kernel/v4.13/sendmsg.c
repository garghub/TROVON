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
F_10 ( & V_4 -> V_17 ) ;
* V_5 = F_11 ( * V_5 ) ;
if ( F_12 ( & V_4 -> V_17 ) < 0 ) {
V_8 = F_8 ( * V_5 ) ;
break;
}
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
struct V_60 * V_61 = & V_2 -> V_61 ;
long V_5 ;
bool V_62 ;
int V_8 , V_63 ;
V_5 = F_39 ( V_61 , V_58 -> V_64 & V_65 ) ;
F_40 ( V_66 , V_61 ) ;
if ( V_61 -> V_67 || ( V_61 -> V_68 & V_69 ) )
return - V_70 ;
V_62 = V_58 -> V_64 & V_71 ;
if ( V_4 -> V_72 != - 1 ) {
if ( V_59 > V_4 -> V_72 )
return - V_73 ;
if ( ! V_62 && V_59 != V_4 -> V_72 )
return - V_73 ;
}
V_26 = V_4 -> V_74 ;
V_4 -> V_74 = NULL ;
F_41 ( V_26 , V_75 ) ;
V_63 = 0 ;
do {
if ( V_4 -> V_48 == V_76 )
F_42 ( V_4 , false ) ;
if ( ! V_26 ) {
T_4 V_77 , V_78 , V_79 , V_80 ;
F_27 ( L_7 ) ;
if ( V_4 -> V_10 - V_4 -> V_9 >=
F_6 (unsigned int, call->tx_winsize,
call->cong_cwnd + call->cong_extra) ) {
V_8 = - V_81 ;
if ( V_58 -> V_64 & V_65 )
goto V_82;
V_8 = F_1 ( V_2 , V_4 ,
& V_5 ) ;
if ( V_8 < 0 )
goto V_82;
}
V_79 = V_83 ;
V_79 -= V_4 -> V_84 -> V_85 ;
V_79 &= ~ ( V_4 -> V_84 -> V_86 - 1UL ) ;
V_78 = V_79 ;
if ( V_78 > F_43 ( V_58 ) && ! V_62 )
V_78 = F_43 ( V_58 ) ;
V_80 = V_78 + V_4 -> V_84 -> V_86 ;
V_80 &= ~ ( V_4 -> V_84 -> V_86 - 1UL ) ;
V_77 = V_80 + V_4 -> V_84 -> V_85 ;
F_27 ( L_8 , V_78 , V_80 , V_77 ) ;
V_26 = F_44 (
V_61 , V_77 , V_58 -> V_64 & V_65 , & V_8 ) ;
if ( ! V_26 )
goto V_82;
F_45 ( V_26 , V_87 ) ;
F_27 ( L_9 , V_26 ) ;
F_23 ( V_26 -> V_88 , == , 0 ) ;
F_27 ( L_10 , V_4 -> V_84 -> V_85 ) ;
F_46 ( V_26 , V_4 -> V_84 -> V_85 ) ;
V_26 -> V_59 += V_4 -> V_84 -> V_85 ;
V_29 = F_21 ( V_26 ) ;
V_29 -> V_89 = V_78 ;
if ( V_29 -> V_89 > F_47 ( V_26 ) )
V_29 -> V_89 = F_47 ( V_26 ) ;
F_22 ( L_11 ,
F_48 ( V_26 ) ,
F_47 ( V_26 ) ,
F_49 ( V_26 ) ,
V_29 -> V_89 ) ;
V_26 -> V_90 = V_91 ;
}
F_27 ( L_12 ) ;
V_29 = F_21 ( V_26 ) ;
if ( F_43 ( V_58 ) > 0 ) {
int V_92 = F_47 ( V_26 ) ;
F_23 ( V_92 , > , 0 ) ;
if ( V_92 > F_43 ( V_58 ) )
V_92 = F_43 ( V_58 ) ;
if ( V_92 > V_29 -> V_89 )
V_92 = V_29 -> V_89 ;
F_27 ( L_13 ) ;
V_8 = F_50 ( V_26 , & V_58 -> V_93 , V_92 ) ;
F_27 ( L_14 ) ;
if ( V_8 < 0 )
goto V_94;
V_29 -> V_89 -= V_92 ;
V_26 -> V_88 += V_92 ;
V_63 += V_92 ;
if ( V_4 -> V_72 != - 1 )
V_4 -> V_72 -= V_92 ;
}
if ( V_4 -> V_14 == V_15 )
goto V_95;
if ( V_29 -> V_89 <= 0 ||
( F_43 ( V_58 ) == 0 && ! V_62 ) ) {
struct V_96 * V_84 = V_4 -> V_84 ;
T_5 V_30 ;
T_4 V_97 ;
if ( V_84 -> V_98 ) {
V_97 = V_84 -> V_85 + V_26 -> V_88 ;
V_97 = V_84 -> V_86 - V_97 ;
V_97 &= V_84 -> V_86 - 1 ;
F_27 ( L_15 , V_97 ) ;
if ( V_97 )
F_51 ( V_26 , V_97 ) ;
}
V_30 = V_4 -> V_10 + 1 ;
V_29 -> V_31 . V_30 = V_30 ;
V_29 -> V_31 . V_99 = 0 ;
V_29 -> V_31 . V_100 = V_84 -> V_101 ;
if ( F_43 ( V_58 ) == 0 && ! V_62 )
V_29 -> V_31 . V_100 |= V_102 ;
else if ( V_4 -> V_10 - V_4 -> V_9 <
V_4 -> V_11 )
V_29 -> V_31 . V_100 |= V_103 ;
V_8 = V_84 -> V_104 -> V_105 (
V_4 , V_26 , V_26 -> V_88 , V_26 -> V_106 ) ;
if ( V_8 < 0 )
goto V_107;
F_20 ( V_4 , V_26 , ! F_43 ( V_58 ) && ! V_62 ) ;
V_26 = NULL ;
}
} while ( F_43 ( V_58 ) > 0 );
V_108:
V_8 = V_63 ;
V_107:
V_4 -> V_74 = V_26 ;
F_14 ( L_2 , V_8 ) ;
return V_8 ;
V_95:
F_37 ( V_26 , V_56 ) ;
F_14 ( L_2 , - V_4 -> error ) ;
return - V_4 -> error ;
V_82:
if ( V_63 )
goto V_108;
goto V_107;
V_94:
V_8 = - V_109 ;
goto V_107;
}
static int F_52 ( struct V_57 * V_58 , struct V_110 * V_111 )
{
struct V_112 * V_113 ;
bool V_114 = false ;
int V_59 ;
if ( V_58 -> V_115 == 0 )
return - V_116 ;
F_53 (cmsg, msg) {
if ( ! F_54 ( V_58 , V_113 ) )
return - V_116 ;
V_59 = V_113 -> V_117 - sizeof( struct V_112 ) ;
F_27 ( L_16 ,
V_113 -> V_118 , V_113 -> V_119 , V_59 ) ;
if ( V_113 -> V_118 != V_120 )
continue;
switch ( V_113 -> V_119 ) {
case V_121 :
if ( V_58 -> V_64 & V_122 ) {
if ( V_59 != sizeof( V_123 ) )
return - V_116 ;
V_111 -> V_124 = * ( V_123 * ) F_55 ( V_113 ) ;
} else {
if ( V_59 != sizeof( unsigned long ) )
return - V_116 ;
V_111 -> V_124 = * ( unsigned long * )
F_55 ( V_113 ) ;
}
V_114 = true ;
break;
case V_125 :
if ( V_111 -> V_126 != V_127 )
return - V_116 ;
V_111 -> V_126 = V_128 ;
if ( V_59 != sizeof( V_111 -> V_129 ) )
return - V_116 ;
V_111 -> V_129 = * ( unsigned int * ) F_55 ( V_113 ) ;
if ( V_111 -> V_129 == 0 )
return - V_116 ;
break;
case V_130 :
if ( V_111 -> V_126 != V_127 )
return - V_116 ;
V_111 -> V_126 = V_131 ;
if ( V_59 != 0 )
return - V_116 ;
break;
case V_132 :
V_111 -> V_133 = true ;
if ( V_59 != 0 )
return - V_116 ;
break;
case V_134 :
V_111 -> V_135 = true ;
if ( V_59 != 0 )
return - V_116 ;
break;
case V_136 :
if ( V_111 -> V_72 != - 1 || V_59 != sizeof( V_137 ) )
return - V_116 ;
V_111 -> V_72 = * ( V_137 * ) F_55 ( V_113 ) ;
if ( V_111 -> V_72 < 0 )
return - V_116 ;
break;
default:
return - V_116 ;
}
}
if ( ! V_114 )
return - V_116 ;
if ( V_111 -> V_72 != - 1 && V_111 -> V_126 != V_127 )
return - V_116 ;
F_14 ( L_17 ) ;
return 0 ;
}
static struct V_3 *
F_56 ( struct V_1 * V_2 , struct V_57 * V_58 ,
struct V_110 * V_111 )
__releases( &rx->sk.sk_lock.slock
int F_57 ( struct V_1 * V_2 , struct V_57 * V_58 , T_4 V_59 )
__releases( &rx->sk.sk_lock.slock
int F_58 ( struct V_138 * V_60 , struct V_3 * V_4 ,
struct V_57 * V_58 , T_4 V_59 )
{
int V_8 ;
F_3 ( L_18 , V_4 -> V_139 , V_140 [ V_4 -> V_14 ] ) ;
F_23 ( V_58 -> V_141 , == , NULL ) ;
F_23 ( V_58 -> V_142 , == , NULL ) ;
F_59 ( & V_4 -> V_17 ) ;
F_27 ( L_19 ,
V_4 -> V_139 , V_4 -> V_124 , V_4 -> V_14 , V_4 -> V_84 ) ;
switch ( F_60 ( V_4 -> V_14 ) ) {
case V_43 :
case V_41 :
case V_45 :
V_8 = F_38 ( F_61 ( V_60 -> V_61 ) , V_4 , V_58 , V_59 ) ;
break;
case V_15 :
F_62 ( & V_4 -> V_42 ) ;
V_8 = - V_4 -> error ;
F_63 ( & V_4 -> V_42 ) ;
break;
default:
F_64 ( V_4 , 0 , F_65 ( L_20 ) ) ;
V_8 = - V_143 ;
break;
}
F_10 ( & V_4 -> V_17 ) ;
F_14 ( L_2 , V_8 ) ;
return V_8 ;
}
bool F_66 ( struct V_138 * V_60 , struct V_3 * V_4 ,
V_123 V_129 , int error , const char * V_144 )
{
bool V_145 ;
F_3 ( L_21 , V_4 -> V_139 , V_129 , error , V_144 ) ;
F_59 ( & V_4 -> V_17 ) ;
V_145 = F_67 ( V_144 , V_4 , 0 , V_129 , error ) ;
if ( V_145 )
F_68 ( V_4 ) ;
F_10 ( & V_4 -> V_17 ) ;
return V_145 ;
}
void F_69 ( struct V_138 * V_60 , struct V_3 * V_4 ,
T_6 V_72 )
{
F_70 ( V_4 -> V_72 != - 1 ) ;
V_4 -> V_72 = V_72 ;
}
