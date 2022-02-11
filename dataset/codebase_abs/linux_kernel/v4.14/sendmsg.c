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
V_8 = V_4 -> error ;
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
static void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_25 )
{
if ( V_25 )
V_25 ( & V_2 -> V_26 , V_4 , V_4 -> V_27 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_28 * V_29 , bool V_30 ,
T_1 V_25 )
{
struct V_31 * V_32 = F_22 ( V_29 ) ;
T_2 V_33 = V_32 -> V_34 . V_33 ;
int V_8 , V_19 ;
T_3 V_35 = V_36 ;
F_23 ( L_3 , V_29 , V_33 ) ;
F_24 ( V_33 , == , V_4 -> V_10 + 1 ) ;
if ( V_30 ) {
V_35 |= V_37 ;
F_25 ( V_38 , & V_4 -> V_39 ) ;
}
V_29 -> V_40 = F_26 () ;
V_19 = V_33 & V_41 ;
F_27 ( V_29 , V_42 ) ;
V_4 -> V_21 [ V_19 ] = V_35 ;
F_28 () ;
V_4 -> V_43 [ V_19 ] = V_29 ;
V_4 -> V_10 = V_33 ;
if ( V_30 )
F_9 ( V_4 , V_44 ) ;
else
F_9 ( V_4 , V_45 ) ;
if ( V_30 || V_4 -> V_14 == V_46 ) {
F_29 ( L_4 ) ;
F_30 ( & V_4 -> V_47 ) ;
switch ( V_4 -> V_14 ) {
case V_48 :
V_4 -> V_14 = V_49 ;
F_20 ( V_2 , V_4 , V_25 ) ;
break;
case V_46 :
V_4 -> V_14 = V_50 ;
V_4 -> V_51 = V_4 -> V_52 ;
if ( V_4 -> V_53 == V_54 )
V_4 -> V_53 = 0 ;
F_31 ( V_4 , V_55 ,
F_26 () ) ;
if ( ! V_30 )
break;
case V_50 :
V_4 -> V_14 = V_56 ;
F_20 ( V_2 , V_4 , V_25 ) ;
break;
default:
break;
}
F_32 ( & V_4 -> V_47 ) ;
}
if ( V_33 == 1 && F_33 ( V_4 ) )
F_34 ( V_4 ) ;
V_8 = F_35 ( V_4 , V_29 , false ) ;
if ( V_8 < 0 ) {
F_29 ( L_5 , V_8 ) ;
F_15 ( V_4 , V_19 ) ;
} else {
T_4 V_57 = F_26 () , V_58 ;
V_58 = F_36 ( V_57 , V_59 ) ;
if ( F_37 ( V_58 , V_4 -> V_58 ) ) {
V_4 -> V_58 = V_58 ;
F_38 ( V_4 , V_60 , V_57 ) ;
}
}
F_39 ( V_29 , V_61 ) ;
F_14 ( L_6 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_62 * V_63 , T_5 V_64 ,
T_1 V_25 )
{
struct V_31 * V_32 ;
struct V_28 * V_29 ;
struct V_65 * V_26 = & V_2 -> V_26 ;
long V_5 ;
bool V_66 ;
int V_8 , V_67 ;
V_5 = F_41 ( V_26 , V_63 -> V_68 & V_69 ) ;
F_42 ( V_70 , V_26 ) ;
if ( V_26 -> V_71 || ( V_26 -> V_72 & V_73 ) )
return - V_74 ;
V_66 = V_63 -> V_68 & V_75 ;
if ( V_4 -> V_76 != - 1 ) {
if ( V_64 > V_4 -> V_76 )
return - V_77 ;
if ( ! V_66 && V_64 != V_4 -> V_76 )
return - V_77 ;
}
V_29 = V_4 -> V_78 ;
V_4 -> V_78 = NULL ;
F_43 ( V_29 , V_79 ) ;
V_67 = 0 ;
do {
if ( V_4 -> V_53 == V_80 )
F_44 ( V_4 , false ) ;
if ( ! V_29 ) {
T_5 V_81 , V_82 , V_83 , V_84 ;
F_29 ( L_7 ) ;
if ( V_4 -> V_10 - V_4 -> V_9 >=
F_6 (unsigned int, call->tx_winsize,
call->cong_cwnd + call->cong_extra) ) {
V_8 = - V_85 ;
if ( V_63 -> V_68 & V_69 )
goto V_86;
V_8 = F_1 ( V_2 , V_4 ,
& V_5 ) ;
if ( V_8 < 0 )
goto V_86;
}
V_83 = V_87 ;
V_83 -= V_4 -> V_88 -> V_89 ;
V_83 &= ~ ( V_4 -> V_88 -> V_90 - 1UL ) ;
V_82 = V_83 ;
if ( V_82 > F_45 ( V_63 ) && ! V_66 )
V_82 = F_45 ( V_63 ) ;
V_84 = V_82 + V_4 -> V_88 -> V_90 ;
V_84 &= ~ ( V_4 -> V_88 -> V_90 - 1UL ) ;
V_81 = V_84 + V_4 -> V_88 -> V_89 ;
F_29 ( L_8 , V_82 , V_84 , V_81 ) ;
V_29 = F_46 (
V_26 , V_81 , V_63 -> V_68 & V_69 , & V_8 ) ;
if ( ! V_29 )
goto V_86;
F_47 ( V_29 , V_91 ) ;
F_29 ( L_9 , V_29 ) ;
F_24 ( V_29 -> V_92 , == , 0 ) ;
F_29 ( L_10 , V_4 -> V_88 -> V_89 ) ;
F_48 ( V_29 , V_4 -> V_88 -> V_89 ) ;
V_29 -> V_64 += V_4 -> V_88 -> V_89 ;
V_32 = F_22 ( V_29 ) ;
V_32 -> V_93 = V_82 ;
if ( V_32 -> V_93 > F_49 ( V_29 ) )
V_32 -> V_93 = F_49 ( V_29 ) ;
F_23 ( L_11 ,
F_50 ( V_29 ) ,
F_49 ( V_29 ) ,
F_51 ( V_29 ) ,
V_32 -> V_93 ) ;
V_29 -> V_94 = V_95 ;
}
F_29 ( L_12 ) ;
V_32 = F_22 ( V_29 ) ;
if ( F_45 ( V_63 ) > 0 ) {
int V_96 = F_49 ( V_29 ) ;
F_24 ( V_96 , > , 0 ) ;
if ( V_96 > F_45 ( V_63 ) )
V_96 = F_45 ( V_63 ) ;
if ( V_96 > V_32 -> V_93 )
V_96 = V_32 -> V_93 ;
F_29 ( L_13 ) ;
V_8 = F_52 ( V_29 , & V_63 -> V_97 , V_96 ) ;
F_29 ( L_14 ) ;
if ( V_8 < 0 )
goto V_98;
V_32 -> V_93 -= V_96 ;
V_29 -> V_92 += V_96 ;
V_67 += V_96 ;
if ( V_4 -> V_76 != - 1 )
V_4 -> V_76 -= V_96 ;
}
if ( V_32 -> V_93 <= 0 ||
( F_45 ( V_63 ) == 0 && ! V_66 ) ) {
struct V_99 * V_88 = V_4 -> V_88 ;
T_6 V_33 ;
T_5 V_100 ;
if ( V_88 -> V_101 ) {
V_100 = V_88 -> V_89 + V_29 -> V_92 ;
V_100 = V_88 -> V_90 - V_100 ;
V_100 &= V_88 -> V_90 - 1 ;
F_29 ( L_15 , V_100 ) ;
if ( V_100 )
F_53 ( V_29 , V_100 ) ;
}
V_33 = V_4 -> V_10 + 1 ;
V_32 -> V_34 . V_33 = V_33 ;
V_32 -> V_34 . V_102 = 0 ;
V_32 -> V_34 . V_39 = V_88 -> V_103 ;
if ( F_45 ( V_63 ) == 0 && ! V_66 )
V_32 -> V_34 . V_39 |= V_104 ;
else if ( V_4 -> V_10 - V_4 -> V_9 <
V_4 -> V_11 )
V_32 -> V_34 . V_39 |= V_105 ;
V_8 = V_88 -> V_106 -> V_107 (
V_4 , V_29 , V_29 -> V_92 , V_29 -> V_108 ) ;
if ( V_8 < 0 )
goto V_109;
F_21 ( V_2 , V_4 , V_29 ,
! F_45 ( V_63 ) && ! V_66 ,
V_25 ) ;
V_29 = NULL ;
}
if ( V_4 -> V_14 == V_15 ) {
V_8 = V_4 -> error ;
goto V_109;
}
} while ( F_45 ( V_63 ) > 0 );
V_110:
V_8 = V_67 ;
V_109:
V_4 -> V_78 = V_29 ;
F_14 ( L_2 , V_8 ) ;
return V_8 ;
V_86:
if ( V_67 )
goto V_110;
goto V_109;
V_98:
V_8 = - V_111 ;
goto V_109;
}
static int F_54 ( struct V_62 * V_63 , struct V_112 * V_113 )
{
struct V_114 * V_115 ;
bool V_116 = false ;
int V_64 ;
if ( V_63 -> V_117 == 0 )
return - V_118 ;
F_55 (cmsg, msg) {
if ( ! F_56 ( V_63 , V_115 ) )
return - V_118 ;
V_64 = V_115 -> V_119 - sizeof( struct V_114 ) ;
F_29 ( L_16 ,
V_115 -> V_120 , V_115 -> V_121 , V_64 ) ;
if ( V_115 -> V_120 != V_122 )
continue;
switch ( V_115 -> V_121 ) {
case V_123 :
if ( V_63 -> V_68 & V_124 ) {
if ( V_64 != sizeof( V_125 ) )
return - V_118 ;
V_113 -> V_27 = * ( V_125 * ) F_57 ( V_115 ) ;
} else {
if ( V_64 != sizeof( unsigned long ) )
return - V_118 ;
V_113 -> V_27 = * ( unsigned long * )
F_57 ( V_115 ) ;
}
V_116 = true ;
break;
case V_126 :
if ( V_113 -> V_127 != V_128 )
return - V_118 ;
V_113 -> V_127 = V_129 ;
if ( V_64 != sizeof( V_113 -> V_130 ) )
return - V_118 ;
V_113 -> V_130 = * ( unsigned int * ) F_57 ( V_115 ) ;
if ( V_113 -> V_130 == 0 )
return - V_118 ;
break;
case V_131 :
if ( V_113 -> V_127 != V_128 )
return - V_118 ;
V_113 -> V_127 = V_132 ;
if ( V_64 != 0 )
return - V_118 ;
break;
case V_133 :
V_113 -> V_134 = true ;
if ( V_64 != 0 )
return - V_118 ;
break;
case V_135 :
V_113 -> V_136 = true ;
if ( V_64 != 0 )
return - V_118 ;
break;
case V_137 :
if ( V_113 -> V_76 != - 1 || V_64 != sizeof( V_138 ) )
return - V_118 ;
V_113 -> V_76 = * ( V_138 * ) F_57 ( V_115 ) ;
if ( V_113 -> V_76 < 0 )
return - V_118 ;
break;
default:
return - V_118 ;
}
}
if ( ! V_116 )
return - V_118 ;
if ( V_113 -> V_76 != - 1 && V_113 -> V_127 != V_128 )
return - V_118 ;
F_14 ( L_17 ) ;
return 0 ;
}
static struct V_3 *
F_58 ( struct V_1 * V_2 , struct V_62 * V_63 ,
struct V_112 * V_113 )
__releases( &rx->sk.sk_lock.slock
int F_59 ( struct V_1 * V_2 , struct V_62 * V_63 , T_5 V_64 )
__releases( &rx->sk.sk_lock.slock
int F_60 ( struct V_139 * V_65 , struct V_3 * V_4 ,
struct V_62 * V_63 , T_5 V_64 ,
T_1 V_25 )
{
int V_8 ;
F_3 ( L_18 , V_4 -> V_140 , V_141 [ V_4 -> V_14 ] ) ;
F_24 ( V_63 -> V_142 , == , NULL ) ;
F_24 ( V_63 -> V_143 , == , NULL ) ;
F_61 ( & V_4 -> V_17 ) ;
F_29 ( L_19 ,
V_4 -> V_140 , V_4 -> V_27 , V_4 -> V_14 , V_4 -> V_88 ) ;
switch ( F_62 ( V_4 -> V_14 ) ) {
case V_48 :
case V_46 :
case V_50 :
V_8 = F_40 ( F_63 ( V_65 -> V_26 ) , V_4 , V_63 , V_64 ,
V_25 ) ;
break;
case V_15 :
F_64 ( & V_4 -> V_47 ) ;
V_8 = V_4 -> error ;
F_65 ( & V_4 -> V_47 ) ;
break;
default:
F_66 ( V_4 , 0 , F_67 ( L_20 ) ) ;
V_8 = - V_144 ;
break;
}
F_10 ( & V_4 -> V_17 ) ;
F_14 ( L_2 , V_8 ) ;
return V_8 ;
}
bool F_68 ( struct V_139 * V_65 , struct V_3 * V_4 ,
V_125 V_130 , int error , const char * V_145 )
{
bool V_146 ;
F_3 ( L_21 , V_4 -> V_140 , V_130 , error , V_145 ) ;
F_61 ( & V_4 -> V_17 ) ;
V_146 = F_69 ( V_145 , V_4 , 0 , V_130 , error ) ;
if ( V_146 )
F_70 ( V_4 ) ;
F_10 ( & V_4 -> V_17 ) ;
return V_146 ;
}
void F_71 ( struct V_139 * V_65 , struct V_3 * V_4 ,
T_7 V_76 )
{
F_72 ( V_4 -> V_76 != - 1 ) ;
V_4 -> V_76 = V_76 ;
}
