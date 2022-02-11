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
V_26 = V_4 -> V_72 ;
V_4 -> V_72 = NULL ;
F_41 ( V_26 , V_73 ) ;
V_63 = 0 ;
do {
if ( V_4 -> V_48 == V_74 )
F_42 ( V_4 , false ) ;
if ( ! V_26 ) {
T_4 V_75 , V_76 , V_77 , V_78 ;
F_27 ( L_7 ) ;
if ( V_4 -> V_10 - V_4 -> V_9 >=
F_6 (unsigned int, call->tx_winsize,
call->cong_cwnd + call->cong_extra) ) {
V_8 = - V_79 ;
if ( V_58 -> V_64 & V_65 )
goto V_80;
V_8 = F_1 ( V_2 , V_4 ,
& V_5 ) ;
if ( V_8 < 0 )
goto V_80;
}
V_77 = V_81 ;
V_77 -= V_4 -> V_82 -> V_83 ;
V_77 &= ~ ( V_4 -> V_82 -> V_84 - 1UL ) ;
V_76 = V_77 ;
if ( V_76 > F_43 ( V_58 ) && ! V_62 )
V_76 = F_43 ( V_58 ) ;
V_78 = V_76 + V_4 -> V_82 -> V_84 ;
V_78 &= ~ ( V_4 -> V_82 -> V_84 - 1UL ) ;
V_75 = V_78 + V_4 -> V_82 -> V_83 ;
F_27 ( L_8 , V_76 , V_78 , V_75 ) ;
V_26 = F_44 (
V_61 , V_75 , V_58 -> V_64 & V_65 , & V_8 ) ;
if ( ! V_26 )
goto V_80;
F_45 ( V_26 , V_85 ) ;
F_27 ( L_9 , V_26 ) ;
F_23 ( V_26 -> V_86 , == , 0 ) ;
F_27 ( L_10 , V_4 -> V_82 -> V_83 ) ;
F_46 ( V_26 , V_4 -> V_82 -> V_83 ) ;
V_26 -> V_59 += V_4 -> V_82 -> V_83 ;
V_29 = F_21 ( V_26 ) ;
V_29 -> V_87 = V_76 ;
if ( V_29 -> V_87 > F_47 ( V_26 ) )
V_29 -> V_87 = F_47 ( V_26 ) ;
F_22 ( L_11 ,
F_48 ( V_26 ) ,
F_47 ( V_26 ) ,
F_49 ( V_26 ) ,
V_29 -> V_87 ) ;
V_26 -> V_88 = V_89 ;
}
F_27 ( L_12 ) ;
V_29 = F_21 ( V_26 ) ;
if ( F_43 ( V_58 ) > 0 ) {
int V_90 = F_47 ( V_26 ) ;
F_23 ( V_90 , > , 0 ) ;
if ( V_90 > F_43 ( V_58 ) )
V_90 = F_43 ( V_58 ) ;
if ( V_90 > V_29 -> V_87 )
V_90 = V_29 -> V_87 ;
F_27 ( L_13 ) ;
V_8 = F_50 ( V_26 , & V_58 -> V_91 , V_90 ) ;
F_27 ( L_14 ) ;
if ( V_8 < 0 )
goto V_92;
V_29 -> V_87 -= V_90 ;
V_26 -> V_86 += V_90 ;
V_63 += V_90 ;
}
if ( V_4 -> V_14 == V_15 )
goto V_93;
if ( V_29 -> V_87 <= 0 ||
( F_43 ( V_58 ) == 0 && ! V_62 ) ) {
struct V_94 * V_82 = V_4 -> V_82 ;
T_5 V_30 ;
T_4 V_95 ;
if ( V_82 -> V_96 ) {
V_95 = V_82 -> V_83 + V_26 -> V_86 ;
V_95 = V_82 -> V_84 - V_95 ;
V_95 &= V_82 -> V_84 - 1 ;
F_27 ( L_15 , V_95 ) ;
if ( V_95 )
memset ( F_51 ( V_26 , V_95 ) , 0 , V_95 ) ;
}
V_30 = V_4 -> V_10 + 1 ;
V_29 -> V_31 . V_30 = V_30 ;
V_29 -> V_31 . V_97 = 0 ;
V_29 -> V_31 . V_98 = V_82 -> V_99 ;
if ( F_43 ( V_58 ) == 0 && ! V_62 )
V_29 -> V_31 . V_98 |= V_100 ;
else if ( V_4 -> V_10 - V_4 -> V_9 <
V_4 -> V_11 )
V_29 -> V_31 . V_98 |= V_101 ;
V_8 = V_82 -> V_102 -> V_103 (
V_4 , V_26 , V_26 -> V_86 , V_26 -> V_104 ) ;
if ( V_8 < 0 )
goto V_105;
F_20 ( V_4 , V_26 , ! F_43 ( V_58 ) && ! V_62 ) ;
V_26 = NULL ;
}
} while ( F_43 ( V_58 ) > 0 );
V_106:
V_8 = V_63 ;
V_105:
V_4 -> V_72 = V_26 ;
F_14 ( L_2 , V_8 ) ;
return V_8 ;
V_93:
F_37 ( V_26 , V_56 ) ;
F_14 ( L_2 , - V_4 -> error ) ;
return - V_4 -> error ;
V_80:
if ( V_63 )
goto V_106;
goto V_105;
V_92:
V_8 = - V_107 ;
goto V_105;
}
static int F_52 ( struct V_57 * V_58 ,
unsigned long * V_108 ,
enum V_109 * V_110 ,
T_6 * V_111 ,
bool * V_112 )
{
struct V_113 * V_114 ;
bool V_115 = false ;
int V_59 ;
* V_110 = V_116 ;
if ( V_58 -> V_117 == 0 )
return - V_118 ;
F_53 (cmsg, msg) {
if ( ! F_54 ( V_58 , V_114 ) )
return - V_118 ;
V_59 = V_114 -> V_119 - sizeof( struct V_113 ) ;
F_27 ( L_16 ,
V_114 -> V_120 , V_114 -> V_121 , V_59 ) ;
if ( V_114 -> V_120 != V_122 )
continue;
switch ( V_114 -> V_121 ) {
case V_123 :
if ( V_58 -> V_64 & V_124 ) {
if ( V_59 != sizeof( T_6 ) )
return - V_118 ;
* V_108 = * ( T_6 * ) F_55 ( V_114 ) ;
} else {
if ( V_59 != sizeof( unsigned long ) )
return - V_118 ;
* V_108 = * ( unsigned long * )
F_55 ( V_114 ) ;
}
F_27 ( L_17 , * V_108 ) ;
V_115 = true ;
break;
case V_125 :
if ( * V_110 != V_116 )
return - V_118 ;
* V_110 = V_126 ;
if ( V_59 != sizeof( * V_111 ) )
return - V_118 ;
* V_111 = * ( unsigned int * ) F_55 ( V_114 ) ;
F_27 ( L_18 , * V_111 ) ;
if ( * V_111 == 0 )
return - V_118 ;
break;
case V_127 :
if ( * V_110 != V_116 )
return - V_118 ;
* V_110 = V_128 ;
if ( V_59 != 0 )
return - V_118 ;
break;
case V_129 :
* V_112 = true ;
if ( V_59 != 0 )
return - V_118 ;
break;
default:
return - V_118 ;
}
}
if ( ! V_115 )
return - V_118 ;
F_14 ( L_19 ) ;
return 0 ;
}
static struct V_3 *
F_56 ( struct V_1 * V_2 , struct V_57 * V_58 ,
unsigned long V_108 , bool V_130 )
__releases( &rx->sk.sk_lock.slock
int F_57 ( struct V_1 * V_2 , struct V_57 * V_58 , T_4 V_59 )
__releases( &rx->sk.sk_lock.slock
int F_58 ( struct V_131 * V_60 , struct V_3 * V_4 ,
struct V_57 * V_58 , T_4 V_59 )
{
int V_8 ;
F_3 ( L_20 , V_4 -> V_132 , V_133 [ V_4 -> V_14 ] ) ;
F_23 ( V_58 -> V_134 , == , NULL ) ;
F_23 ( V_58 -> V_135 , == , NULL ) ;
F_59 ( & V_4 -> V_17 ) ;
F_27 ( L_21 ,
V_4 -> V_132 , V_4 -> V_108 , V_4 -> V_14 , V_4 -> V_82 ) ;
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
V_8 = - V_136 ;
break;
}
F_10 ( & V_4 -> V_17 ) ;
F_14 ( L_2 , V_8 ) ;
return V_8 ;
}
void F_64 ( struct V_131 * V_60 , struct V_3 * V_4 ,
T_6 V_111 , int error , const char * V_137 )
{
F_3 ( L_22 , V_4 -> V_132 , V_111 , error , V_137 ) ;
F_59 ( & V_4 -> V_17 ) ;
if ( F_65 ( V_137 , V_4 , 0 , V_111 , error ) )
F_66 ( V_4 ) ;
F_10 ( & V_4 -> V_17 ) ;
F_14 ( L_6 ) ;
}
