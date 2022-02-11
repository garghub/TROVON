static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static inline struct V_5 * F_1 ( struct V_6 * V_6 )
{
F_2 ( ! V_6 ) ;
return F_3 ( V_6 , V_7 ) ;
}
static inline void F_4 ( struct V_1 * V_8 )
{
F_5 ( & V_8 -> V_9 ) ;
}
static inline void F_6 ( struct V_1 * V_8 )
{
if ( F_7 ( & V_8 -> V_9 ) )
F_8 ( V_8 ) ;
}
struct V_2 * F_9 ( struct V_1 * V_8 )
{
int V_10 = 0 ;
struct V_11 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
if ( ! V_8 )
goto V_12;
if ( V_8 -> V_13 >= 0 ) {
V_2 = F_10 ( V_8 -> V_13 , & V_10 ) ;
if ( V_2 )
V_3 = V_2 -> V_3 ;
} else {
V_3 = V_8 -> V_2 ;
F_11 ( V_3 ) ;
}
V_12:
return V_3 ;
}
void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_13 ( V_3 ) ;
if ( V_8 ) {
if ( V_8 -> V_13 >= 0 ) {
F_14 ( V_3 -> V_14 ) ;
}
F_15 ( V_3 ) ;
}
F_15 ( V_3 ) ;
}
static struct V_15 * F_16 ( struct V_6 * V_6 , T_1 V_16 )
{
struct V_5 * V_17 = F_1 ( V_6 ) ;
struct V_18 * V_19 =
F_17 ( V_17 , V_16 ) ;
struct V_15 * V_20 ;
F_18 () ;
F_19 (session, session_list, global_hlist) {
if ( V_20 -> V_16 == V_16 ) {
F_20 () ;
return V_20 ;
}
}
F_20 () ;
return NULL ;
}
static inline struct V_18 *
F_21 ( struct V_1 * V_8 , T_1 V_16 )
{
return & V_8 -> V_21 [ F_22 ( V_16 , V_22 ) ] ;
}
struct V_15 * F_23 ( struct V_6 * V_6 , struct V_1 * V_8 , T_1 V_16 )
{
struct V_18 * V_19 ;
struct V_15 * V_20 ;
if ( V_8 == NULL )
return F_16 ( V_6 , V_16 ) ;
V_19 = F_21 ( V_8 , V_16 ) ;
F_24 ( & V_8 -> V_23 ) ;
F_25 (session, session_list, hlist) {
if ( V_20 -> V_16 == V_16 ) {
F_26 ( & V_8 -> V_23 ) ;
return V_20 ;
}
}
F_26 ( & V_8 -> V_23 ) ;
return NULL ;
}
struct V_15 * F_27 ( struct V_1 * V_8 , int V_24 )
{
int V_25 ;
struct V_15 * V_20 ;
int V_26 = 0 ;
F_24 ( & V_8 -> V_23 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
F_25 (session, &tunnel->session_hlist[hash], hlist) {
if ( ++ V_26 > V_24 ) {
F_26 ( & V_8 -> V_23 ) ;
return V_20 ;
}
}
}
F_26 ( & V_8 -> V_23 ) ;
return NULL ;
}
struct V_15 * F_28 ( struct V_6 * V_6 , char * V_28 )
{
struct V_5 * V_17 = F_1 ( V_6 ) ;
int V_25 ;
struct V_15 * V_20 ;
F_18 () ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
F_19 (session, &pn->l2tp_session_hlist[hash], global_hlist) {
if ( ! strcmp ( V_20 -> V_28 , V_28 ) ) {
F_20 () ;
return V_20 ;
}
}
}
F_20 () ;
return NULL ;
}
struct V_1 * F_29 ( struct V_6 * V_6 , T_1 V_30 )
{
struct V_1 * V_8 ;
struct V_5 * V_17 = F_1 ( V_6 ) ;
F_18 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( V_8 -> V_30 == V_30 ) {
F_20 () ;
return V_8 ;
}
}
F_20 () ;
return NULL ;
}
struct V_1 * F_31 ( struct V_6 * V_6 , int V_24 )
{
struct V_5 * V_17 = F_1 ( V_6 ) ;
struct V_1 * V_8 ;
int V_26 = 0 ;
F_18 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( ++ V_26 > V_24 ) {
F_20 () ;
return V_8 ;
}
}
F_20 () ;
return NULL ;
}
static void F_32 ( struct V_15 * V_20 , struct V_31 * V_32 )
{
struct V_31 * V_33 ;
struct V_31 * V_34 ;
T_1 V_35 = F_33 ( V_32 ) -> V_35 ;
F_34 ( & V_20 -> V_36 . V_37 ) ;
F_35 (&session->reorder_q, skbp, tmp) {
if ( F_33 ( V_33 ) -> V_35 > V_35 ) {
F_36 ( & V_20 -> V_36 , V_33 , V_32 ) ;
F_37 ( V_20 , V_38 ,
L_1 ,
V_20 -> V_39 , V_35 , F_33 ( V_33 ) -> V_35 ,
F_38 ( & V_20 -> V_36 ) ) ;
F_39 ( & V_20 -> V_40 . V_41 ) ;
goto V_12;
}
}
F_40 ( & V_20 -> V_36 , V_32 ) ;
V_12:
F_41 ( & V_20 -> V_36 . V_37 ) ;
}
static void F_42 ( struct V_15 * V_20 , struct V_31 * V_32 )
{
struct V_1 * V_8 = V_20 -> V_8 ;
int V_42 = F_33 ( V_32 ) -> V_42 ;
F_43 ( V_32 ) ;
F_39 ( & V_8 -> V_40 . V_43 ) ;
F_44 ( V_42 , & V_8 -> V_40 . V_44 ) ;
F_39 ( & V_20 -> V_40 . V_43 ) ;
F_44 ( V_42 , & V_20 -> V_40 . V_44 ) ;
if ( F_33 ( V_32 ) -> V_45 ) {
V_20 -> V_46 ++ ;
V_20 -> V_46 &= V_20 -> V_47 ;
F_37 ( V_20 , V_38 , L_2 ,
V_20 -> V_39 , V_20 -> V_46 ) ;
}
if ( V_20 -> V_48 != NULL )
(* V_20 -> V_48 )( V_20 , V_32 , F_33 ( V_32 ) -> V_42 ) ;
else
F_45 ( V_32 ) ;
if ( V_20 -> V_49 )
(* V_20 -> V_49 )( V_20 ) ;
}
static void F_46 ( struct V_15 * V_20 )
{
struct V_31 * V_32 ;
struct V_31 * V_34 ;
V_50:
F_34 ( & V_20 -> V_36 . V_37 ) ;
F_35 (&session->reorder_q, skb, tmp) {
if ( F_47 ( V_51 , F_33 ( V_32 ) -> V_52 ) ) {
F_39 ( & V_20 -> V_40 . V_53 ) ;
F_39 ( & V_20 -> V_40 . V_54 ) ;
F_37 ( V_20 , V_38 ,
L_3 ,
V_20 -> V_39 , F_33 ( V_32 ) -> V_35 ,
F_33 ( V_32 ) -> V_42 , V_20 -> V_46 ,
F_38 ( & V_20 -> V_36 ) ) ;
V_20 -> V_55 = 1 ;
F_48 ( V_32 , & V_20 -> V_36 ) ;
F_45 ( V_32 ) ;
if ( V_20 -> V_49 )
(* V_20 -> V_49 )( V_20 ) ;
continue;
}
if ( F_33 ( V_32 ) -> V_45 ) {
if ( V_20 -> V_55 ) {
F_37 ( V_20 , V_38 ,
L_4 ,
V_20 -> V_39 , V_20 -> V_46 ,
F_33 ( V_32 ) -> V_35 ) ;
V_20 -> V_55 = 0 ;
V_20 -> V_46 = F_33 ( V_32 ) -> V_35 ;
}
if ( F_33 ( V_32 ) -> V_35 != V_20 -> V_46 ) {
F_37 ( V_20 , V_38 ,
L_5 ,
V_20 -> V_39 , F_33 ( V_32 ) -> V_35 ,
F_33 ( V_32 ) -> V_42 , V_20 -> V_46 ,
F_38 ( & V_20 -> V_36 ) ) ;
goto V_12;
}
}
F_48 ( V_32 , & V_20 -> V_36 ) ;
F_41 ( & V_20 -> V_36 . V_37 ) ;
F_42 ( V_20 , V_32 ) ;
goto V_50;
}
V_12:
F_41 ( & V_20 -> V_36 . V_37 ) ;
}
static inline int F_49 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
struct V_56 * V_57 = F_50 ( V_32 ) ;
T_2 V_58 = F_51 ( V_57 -> V_59 ) ;
T_3 V_60 ;
if ( V_3 -> V_61 || F_52 ( V_32 ) )
return 0 ;
#if F_53 ( V_62 )
if ( V_3 -> V_63 == V_64 && ! V_1 ( V_3 ) -> V_65 ) {
if ( ! V_57 -> V_66 ) {
F_54 ( V_67 L_6 ) ;
return 1 ;
}
if ( ( V_32 -> V_68 == V_69 ) &&
! F_55 ( & F_56 ( V_32 ) -> V_70 ,
& F_56 ( V_32 ) -> V_71 , V_58 ,
V_72 , V_32 -> V_73 ) ) {
V_32 -> V_68 = V_74 ;
return 0 ;
}
V_32 -> V_73 = ~ F_57 ( F_55 ( & F_56 ( V_32 ) -> V_70 ,
& F_56 ( V_32 ) -> V_71 ,
V_32 -> V_59 , V_72 ,
0 ) ) ;
} else
#endif
{
struct V_75 * V_76 ;
if ( ! V_57 -> V_66 )
return 0 ;
V_76 = F_58 ( V_3 ) ;
V_60 = F_59 ( V_76 -> V_77 , V_76 -> V_78 ,
V_58 , V_72 , 0 ) ;
if ( ( V_32 -> V_68 == V_69 ) &&
! F_60 ( F_61 ( V_60 , V_32 -> V_73 ) ) )
return 0 ;
V_32 -> V_73 = V_60 ;
}
return F_62 ( V_32 ) ;
}
static int F_63 ( struct V_15 * V_20 , T_1 V_46 )
{
T_1 V_79 ;
if ( V_46 >= V_20 -> V_46 )
V_79 = V_46 - V_20 -> V_46 ;
else
V_79 = ( V_20 -> V_47 + 1 ) - ( V_20 -> V_46 - V_46 ) ;
return V_79 < V_20 -> V_80 ;
}
static int F_64 ( struct V_15 * V_20 , struct V_31 * V_32 )
{
if ( ! F_63 ( V_20 , F_33 ( V_32 ) -> V_35 ) ) {
F_37 ( V_20 , V_38 ,
L_7 ,
V_20 -> V_39 , F_33 ( V_32 ) -> V_35 ,
F_33 ( V_32 ) -> V_42 , V_20 -> V_46 ) ;
goto V_81;
}
if ( V_20 -> V_82 != 0 ) {
F_32 ( V_20 , V_32 ) ;
goto V_12;
}
if ( F_33 ( V_32 ) -> V_35 == V_20 -> V_46 ) {
F_65 ( & V_20 -> V_36 , V_32 ) ;
} else {
T_1 V_83 = F_33 ( V_32 ) -> V_35 ;
T_1 V_84 = ( V_20 -> V_83 + 1 ) & V_20 -> V_47 ;
if ( V_83 == V_84 )
V_20 -> V_85 ++ ;
else
V_20 -> V_85 = 0 ;
V_20 -> V_83 = V_83 ;
if ( V_20 -> V_85 > V_20 -> V_86 ) {
V_20 -> V_55 = 1 ;
F_37 ( V_20 , V_38 ,
L_8 ,
V_20 -> V_39 , V_20 -> V_85 ) ;
}
if ( ! V_20 -> V_55 ) {
F_39 ( & V_20 -> V_40 . V_53 ) ;
F_37 ( V_20 , V_38 ,
L_9 ,
V_20 -> V_39 , F_33 ( V_32 ) -> V_35 ,
F_33 ( V_32 ) -> V_42 , V_20 -> V_46 ,
F_38 ( & V_20 -> V_36 ) ) ;
goto V_81;
}
F_65 ( & V_20 -> V_36 , V_32 ) ;
}
V_12:
return 0 ;
V_81:
return 1 ;
}
void F_66 ( struct V_15 * V_20 , struct V_31 * V_32 ,
unsigned char * V_87 , unsigned char * V_88 , T_2 V_89 ,
int V_42 , int (* F_67)( struct V_31 * V_32 ) )
{
struct V_1 * V_8 = V_20 -> V_8 ;
int V_90 ;
T_1 V_35 , V_46 ;
F_68 ( V_20 ) ;
if ( V_20 -> V_91 )
(* V_20 -> V_91 )( V_20 ) ;
if ( V_20 -> V_92 > 0 ) {
if ( memcmp ( V_87 , & V_20 -> V_93 [ 0 ] , V_20 -> V_92 ) ) {
F_69 ( V_8 , V_94 ,
L_10 ,
V_8 -> V_39 , V_8 -> V_30 ,
V_20 -> V_16 ) ;
F_39 ( & V_20 -> V_40 . V_95 ) ;
goto V_81;
}
V_87 += V_20 -> V_92 ;
}
V_35 = V_46 = 0 ;
F_33 ( V_32 ) -> V_45 = 0 ;
if ( V_8 -> V_96 == V_97 ) {
if ( V_89 & V_98 ) {
V_35 = F_51 ( * ( V_99 * ) V_87 ) ;
V_87 += 2 ;
V_46 = F_51 ( * ( V_99 * ) V_87 ) ;
V_87 += 2 ;
F_33 ( V_32 ) -> V_35 = V_35 ;
F_33 ( V_32 ) -> V_45 = 1 ;
F_37 ( V_20 , V_38 ,
L_11 ,
V_20 -> V_39 , V_35 , V_46 , V_20 -> V_46 ) ;
}
} else if ( V_20 -> V_100 == V_101 ) {
T_1 V_102 = F_70 ( * ( V_103 * ) V_87 ) ;
if ( V_102 & 0x40000000 ) {
V_35 = V_102 & 0x00ffffff ;
F_33 ( V_32 ) -> V_35 = V_35 ;
F_33 ( V_32 ) -> V_45 = 1 ;
F_37 ( V_20 , V_38 ,
L_12 ,
V_20 -> V_39 , V_35 , V_20 -> V_46 ) ;
}
}
V_87 += V_20 -> V_104 ;
if ( F_33 ( V_32 ) -> V_45 ) {
if ( ( ! V_20 -> V_105 ) && ( ! V_20 -> V_106 ) ) {
F_69 ( V_20 , V_38 ,
L_13 ,
V_20 -> V_39 ) ;
V_20 -> V_106 = - 1 ;
F_71 ( V_20 , V_8 -> V_96 ) ;
}
} else {
if ( V_20 -> V_107 ) {
F_72 ( V_20 , V_38 ,
L_14 ,
V_20 -> V_39 ) ;
F_39 ( & V_20 -> V_40 . V_53 ) ;
goto V_81;
}
if ( ( ! V_20 -> V_105 ) && ( V_20 -> V_106 ) ) {
F_69 ( V_20 , V_38 ,
L_15 ,
V_20 -> V_39 ) ;
V_20 -> V_106 = 0 ;
F_71 ( V_20 , V_8 -> V_96 ) ;
} else if ( V_20 -> V_106 ) {
F_72 ( V_20 , V_38 ,
L_14 ,
V_20 -> V_39 ) ;
F_39 ( & V_20 -> V_40 . V_53 ) ;
goto V_81;
}
}
if ( V_8 -> V_96 == V_97 ) {
if ( V_89 & V_108 ) {
V_90 = F_51 ( * ( V_99 * ) V_87 ) ;
V_87 += 2 + V_90 ;
}
} else
V_87 += V_20 -> V_90 ;
V_90 = V_87 - V_88 ;
if ( ! F_73 ( V_32 , V_90 ) )
goto V_81;
F_74 ( V_32 , V_90 ) ;
if ( F_67 )
if ( (* F_67)( V_32 ) )
goto V_81;
F_33 ( V_32 ) -> V_42 = V_42 ;
F_33 ( V_32 ) -> V_52 = V_51 +
( V_20 -> V_82 ? V_20 -> V_82 : V_109 ) ;
if ( F_33 ( V_32 ) -> V_45 ) {
if ( F_64 ( V_20 , V_32 ) )
goto V_81;
} else {
F_65 ( & V_20 -> V_36 , V_32 ) ;
}
F_46 ( V_20 ) ;
F_75 ( V_20 ) ;
return;
V_81:
F_39 ( & V_20 -> V_40 . V_54 ) ;
F_45 ( V_32 ) ;
if ( V_20 -> V_49 )
(* V_20 -> V_49 )( V_20 ) ;
F_75 ( V_20 ) ;
}
int F_76 ( struct V_15 * V_20 )
{
struct V_31 * V_32 = NULL ;
F_2 ( ! V_20 ) ;
F_2 ( V_20 -> V_110 != V_111 ) ;
while ( ( V_32 = F_77 ( & V_20 -> V_36 ) ) ) {
F_39 ( & V_20 -> V_40 . V_54 ) ;
F_45 ( V_32 ) ;
if ( V_20 -> V_49 )
(* V_20 -> V_49 )( V_20 ) ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_8 , struct V_31 * V_32 ,
int (* F_67)( struct V_31 * V_32 ) )
{
struct V_15 * V_20 = NULL ;
unsigned char * V_87 , * V_88 ;
T_2 V_89 ;
T_1 V_30 , V_16 ;
T_2 V_96 ;
int V_42 ;
if ( V_8 -> V_2 && F_49 ( V_8 -> V_2 , V_32 ) )
goto V_112;
F_74 ( V_32 , sizeof( struct V_56 ) ) ;
if ( ! F_73 ( V_32 , V_113 ) ) {
F_69 ( V_8 , V_94 ,
L_16 ,
V_8 -> V_39 , V_32 -> V_59 ) ;
goto error;
}
if ( V_8 -> V_114 & V_94 ) {
V_42 = F_79 ( 32u , V_32 -> V_59 ) ;
if ( ! F_73 ( V_32 , V_42 ) )
goto error;
F_80 ( L_17 , V_8 -> V_39 ) ;
F_81 ( L_18 , V_115 , V_32 -> V_116 , V_42 ) ;
}
V_88 = V_87 = V_32 -> V_116 ;
V_89 = F_51 ( * ( V_99 * ) V_87 ) ;
V_96 = V_89 & V_117 ;
if ( V_96 != V_8 -> V_96 ) {
F_69 ( V_8 , V_94 ,
L_19 ,
V_8 -> V_39 , V_96 , V_8 -> V_96 ) ;
goto error;
}
V_42 = V_32 -> V_59 ;
if ( V_89 & V_118 ) {
F_37 ( V_8 , V_94 ,
L_20 ,
V_8 -> V_39 , V_42 ) ;
goto error;
}
V_87 += 2 ;
if ( V_8 -> V_96 == V_97 ) {
if ( V_89 & V_119 )
V_87 += 2 ;
V_30 = F_51 ( * ( V_99 * ) V_87 ) ;
V_87 += 2 ;
V_16 = F_51 ( * ( V_99 * ) V_87 ) ;
V_87 += 2 ;
} else {
V_87 += 2 ;
V_30 = V_8 -> V_30 ;
V_16 = F_70 ( * ( V_103 * ) V_87 ) ;
V_87 += 4 ;
}
V_20 = F_23 ( V_8 -> V_5 , V_8 , V_16 ) ;
if ( ! V_20 || ! V_20 -> V_48 ) {
F_69 ( V_8 , V_94 ,
L_21 ,
V_8 -> V_39 , V_30 , V_16 ) ;
goto error;
}
F_66 ( V_20 , V_32 , V_87 , V_88 , V_89 , V_42 , F_67 ) ;
return 0 ;
V_112:
F_54 ( L_22 , V_8 -> V_39 ) ;
F_82 ( V_8 -> V_5 , V_120 , 0 ) ;
F_39 ( & V_8 -> V_40 . V_54 ) ;
F_45 ( V_32 ) ;
return 0 ;
error:
F_83 ( V_32 , sizeof( struct V_56 ) ) ;
return 1 ;
}
int F_84 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
struct V_1 * V_8 ;
V_8 = F_13 ( V_3 ) ;
if ( V_8 == NULL )
goto V_121;
F_37 ( V_8 , V_94 , L_23 ,
V_8 -> V_39 , V_32 -> V_59 ) ;
if ( F_78 ( V_8 , V_32 , V_8 -> V_122 ) )
goto V_123;
F_15 ( V_3 ) ;
return 0 ;
V_123:
F_15 ( V_3 ) ;
V_121:
return 1 ;
}
static int F_85 ( struct V_15 * V_20 , void * V_124 )
{
struct V_1 * V_8 = V_20 -> V_8 ;
V_99 * V_125 = V_124 ;
V_99 * V_88 = V_124 ;
T_2 V_126 = V_97 ;
T_1 V_30 = V_8 -> V_127 ;
T_1 V_16 = V_20 -> V_128 ;
if ( V_20 -> V_106 )
V_126 |= V_98 ;
* V_125 ++ = F_86 ( V_126 ) ;
* V_125 ++ = F_86 ( V_30 ) ;
* V_125 ++ = F_86 ( V_16 ) ;
if ( V_20 -> V_106 ) {
* V_125 ++ = F_86 ( V_20 -> V_35 ) ;
* V_125 ++ = 0 ;
V_20 -> V_35 ++ ;
V_20 -> V_35 &= 0xffff ;
F_37 ( V_20 , V_38 , L_24 ,
V_20 -> V_39 , V_20 -> V_35 ) ;
}
return V_125 - V_88 ;
}
static int F_87 ( struct V_15 * V_20 , void * V_124 )
{
struct V_1 * V_8 = V_20 -> V_8 ;
char * V_125 = V_124 ;
char * V_88 = V_125 ;
if ( V_8 -> V_129 == V_130 ) {
T_2 V_126 = V_131 ;
* ( ( V_99 * ) V_125 ) = F_86 ( V_126 ) ;
V_125 += 2 ;
* ( ( V_99 * ) V_125 ) = 0 ;
V_125 += 2 ;
}
* ( ( V_103 * ) V_125 ) = F_88 ( V_20 -> V_128 ) ;
V_125 += 4 ;
if ( V_20 -> V_132 ) {
memcpy ( V_125 , & V_20 -> V_133 [ 0 ] , V_20 -> V_132 ) ;
V_125 += V_20 -> V_132 ;
}
if ( V_20 -> V_104 ) {
if ( V_20 -> V_100 == V_101 ) {
T_1 V_102 = 0 ;
if ( V_20 -> V_106 ) {
V_102 = 0x40000000 | V_20 -> V_35 ;
V_20 -> V_35 ++ ;
V_20 -> V_35 &= 0xffffff ;
F_37 ( V_20 , V_38 ,
L_24 ,
V_20 -> V_39 , V_20 -> V_35 ) ;
}
* ( ( V_103 * ) V_125 ) = F_88 ( V_102 ) ;
}
V_125 += V_20 -> V_104 ;
}
if ( V_20 -> V_90 )
V_125 += V_20 -> V_90 ;
return V_125 - V_88 ;
}
static int F_89 ( struct V_15 * V_20 , struct V_31 * V_32 ,
struct V_134 * V_135 , T_4 V_136 )
{
struct V_1 * V_8 = V_20 -> V_8 ;
unsigned int V_59 = V_32 -> V_59 ;
int error ;
if ( V_20 -> V_106 )
F_37 ( V_20 , V_94 , L_25 ,
V_20 -> V_39 , V_136 , V_20 -> V_35 - 1 ) ;
else
F_37 ( V_20 , V_94 , L_26 ,
V_20 -> V_39 , V_136 ) ;
if ( V_20 -> V_114 & V_94 ) {
int V_137 = ( V_8 -> V_129 == V_130 ) ? sizeof( struct V_56 ) : 0 ;
unsigned char * V_138 = V_32 -> V_116 + V_137 ;
F_80 ( L_27 , V_20 -> V_39 ) ;
F_81 ( L_18 , V_115 ,
V_138 , F_90 ( T_4 , 32 , V_59 - V_137 ) ) ;
}
V_32 -> V_139 = 1 ;
#if F_53 ( V_62 )
if ( V_32 -> V_3 -> V_63 == V_64 && ! V_8 -> V_65 )
error = F_91 ( V_32 , NULL ) ;
else
#endif
error = F_92 ( V_32 , V_135 ) ;
if ( error >= 0 ) {
F_39 ( & V_8 -> V_40 . V_140 ) ;
F_44 ( V_59 , & V_8 -> V_40 . V_141 ) ;
F_39 ( & V_20 -> V_40 . V_140 ) ;
F_44 ( V_59 , & V_20 -> V_40 . V_141 ) ;
} else {
F_39 ( & V_8 -> V_40 . V_142 ) ;
F_39 ( & V_20 -> V_40 . V_142 ) ;
}
return 0 ;
}
static void F_93 ( struct V_31 * V_32 )
{
F_15 ( V_32 -> V_3 ) ;
}
static inline void F_94 ( struct V_31 * V_32 , struct V_2 * V_3 )
{
F_11 ( V_3 ) ;
V_32 -> V_3 = V_3 ;
V_32 -> V_143 = F_93 ;
}
static void F_95 ( struct V_2 * V_3 , struct V_31 * V_32 ,
int V_144 )
{
struct V_145 * V_146 = F_96 ( V_3 ) ;
struct V_56 * V_57 = F_50 ( V_32 ) ;
if ( ! F_97 ( V_32 ) || ! F_97 ( V_32 ) -> V_147 ||
! ( F_97 ( V_32 ) -> V_147 -> V_148 & V_149 ) ) {
T_3 V_73 = F_98 ( V_32 , 0 , V_144 , 0 ) ;
V_32 -> V_68 = V_74 ;
V_57 -> V_66 = F_55 ( & V_146 -> V_70 , & V_3 -> V_150 , V_144 ,
V_72 , V_73 ) ;
if ( V_57 -> V_66 == 0 )
V_57 -> V_66 = V_151 ;
} else {
V_32 -> V_68 = V_152 ;
V_32 -> V_153 = F_99 ( V_32 ) - V_32 -> V_154 ;
V_32 -> V_155 = F_100 ( struct V_56 , V_66 ) ;
V_57 -> V_66 = ~ F_55 ( & V_146 -> V_70 , & V_3 -> V_150 ,
V_144 , V_72 , 0 ) ;
}
}
int F_101 ( struct V_15 * V_20 , struct V_31 * V_32 , int V_156 )
{
int V_136 = V_32 -> V_59 ;
struct V_1 * V_8 = V_20 -> V_8 ;
struct V_2 * V_3 = V_8 -> V_2 ;
struct V_134 * V_135 ;
struct V_56 * V_57 ;
struct V_75 * V_76 ;
T_3 V_73 ;
int V_157 ;
int V_137 = ( V_8 -> V_129 == V_130 ) ? sizeof( struct V_56 ) : 0 ;
int V_144 ;
int V_158 = V_159 ;
V_157 = V_160 + sizeof( struct V_161 ) +
V_137 + V_156 ;
if ( F_102 ( V_32 , V_157 ) ) {
F_45 ( V_32 ) ;
return V_162 ;
}
F_43 ( V_32 ) ;
V_20 -> V_163 ( V_20 , F_83 ( V_32 , V_156 ) ) ;
memset ( & ( F_103 ( V_32 ) -> V_164 ) , 0 , sizeof( F_103 ( V_32 ) -> V_164 ) ) ;
F_103 ( V_32 ) -> V_126 &= ~ ( V_165 | V_166 |
V_167 ) ;
F_104 ( V_32 ) ;
F_105 ( V_3 ) ;
if ( F_106 ( V_3 ) ) {
F_45 ( V_32 ) ;
V_158 = V_162 ;
goto V_168;
}
F_107 ( V_32 ) ;
F_108 ( V_32 , F_109 ( F_110 ( V_3 , 0 ) ) ) ;
V_76 = F_58 ( V_3 ) ;
V_135 = & V_76 -> V_169 . V_135 ;
switch ( V_8 -> V_129 ) {
case V_130 :
F_83 ( V_32 , sizeof( * V_57 ) ) ;
F_111 ( V_32 ) ;
V_57 = F_50 ( V_32 ) ;
V_57 -> V_170 = V_76 -> V_171 ;
V_57 -> V_172 = V_76 -> V_173 ;
V_144 = V_137 + V_156 + V_136 ;
V_57 -> V_59 = F_86 ( V_144 ) ;
V_57 -> V_66 = 0 ;
#if F_53 ( V_62 )
if ( V_3 -> V_63 == V_64 && ! V_8 -> V_65 )
F_95 ( V_3 , V_32 , V_144 ) ;
else
#endif
if ( V_3 -> V_61 == V_174 )
V_32 -> V_68 = V_175 ;
else if ( ( F_97 ( V_32 ) && F_97 ( V_32 ) -> V_147 ) &&
( ! ( F_97 ( V_32 ) -> V_147 -> V_148 & V_176 ) ) ) {
V_32 -> V_68 = V_69 ;
V_73 = F_98 ( V_32 , 0 , V_144 , 0 ) ;
V_57 -> V_66 = F_112 ( V_76 -> V_77 ,
V_76 -> V_78 ,
V_144 , V_72 , V_73 ) ;
if ( V_57 -> V_66 == 0 )
V_57 -> V_66 = V_151 ;
} else {
V_32 -> V_68 = V_152 ;
V_32 -> V_153 = F_99 ( V_32 ) - V_32 -> V_154 ;
V_32 -> V_155 = F_100 ( struct V_56 , V_66 ) ;
V_57 -> V_66 = ~ F_112 ( V_76 -> V_77 ,
V_76 -> V_78 ,
V_144 , V_72 , 0 ) ;
}
break;
case V_177 :
break;
}
F_94 ( V_32 , V_3 ) ;
F_89 ( V_20 , V_32 , V_135 , V_136 ) ;
V_168:
F_113 ( V_3 ) ;
return V_158 ;
}
static void F_114 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = V_1 ( V_3 ) ;
struct V_5 * V_17 ;
if ( V_8 == NULL )
goto V_178;
F_69 ( V_8 , V_179 , L_28 , V_8 -> V_39 ) ;
switch ( V_8 -> V_129 ) {
case V_130 :
( F_115 ( V_3 ) ) -> V_180 = 0 ;
( F_115 ( V_3 ) ) -> V_181 = NULL ;
( F_115 ( V_3 ) ) -> V_182 = NULL ;
break;
case V_177 :
break;
}
V_3 -> V_183 = V_8 -> V_184 ;
V_3 -> V_4 = NULL ;
V_8 -> V_2 = NULL ;
V_17 = F_1 ( V_8 -> V_5 ) ;
F_34 ( & V_17 -> V_185 ) ;
F_116 ( & V_8 -> V_186 ) ;
F_41 ( & V_17 -> V_185 ) ;
F_117 ( & V_187 ) ;
F_118 ( V_8 ) ;
F_119 ( V_8 ) ;
if ( V_3 -> V_183 )
(* V_3 -> V_183 )( V_3 ) ;
V_178:
return;
}
void F_118 ( struct V_1 * V_8 )
{
int V_25 ;
struct V_188 * V_189 ;
struct V_188 * V_34 ;
struct V_15 * V_20 ;
F_2 ( V_8 == NULL ) ;
F_69 ( V_8 , V_179 , L_29 ,
V_8 -> V_39 ) ;
F_120 ( & V_8 -> V_23 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
V_190:
F_121 (walk, tmp, &tunnel->session_hlist[hash]) {
V_20 = F_122 ( V_189 , struct V_15 , V_191 ) ;
F_69 ( V_20 , V_179 ,
L_30 , V_20 -> V_39 ) ;
F_123 ( & V_20 -> V_191 ) ;
if ( V_20 -> V_91 != NULL )
(* V_20 -> V_91 )( V_20 ) ;
F_124 ( & V_8 -> V_23 ) ;
F_125 ( V_20 ) ;
F_76 ( V_20 ) ;
if ( V_20 -> V_192 != NULL )
(* V_20 -> V_192 )( V_20 ) ;
if ( V_20 -> V_49 != NULL )
(* V_20 -> V_49 )( V_20 ) ;
F_75 ( V_20 ) ;
F_120 ( & V_8 -> V_23 ) ;
goto V_190;
}
}
F_124 ( & V_8 -> V_23 ) ;
}
static void F_126 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_13 ( V_3 ) ;
if ( V_8 ) {
F_118 ( V_8 ) ;
F_15 ( V_3 ) ;
}
}
static void F_8 ( struct V_1 * V_8 )
{
F_2 ( F_127 ( & V_8 -> V_9 ) != 0 ) ;
F_2 ( V_8 -> V_2 != NULL ) ;
F_69 ( V_8 , V_179 , L_31 , V_8 -> V_39 ) ;
F_128 ( V_8 , V_193 ) ;
}
static void F_129 ( struct V_194 * V_195 )
{
struct V_1 * V_8 = NULL ;
struct V_11 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
V_8 = F_130 ( V_195 , struct V_1 , V_196 ) ;
V_3 = F_9 ( V_8 ) ;
if ( ! V_3 )
return;
V_2 = V_3 -> V_14 ;
if ( V_8 -> V_13 >= 0 ) {
if ( V_2 )
F_131 ( V_2 , 2 ) ;
} else {
if ( V_2 )
F_132 ( V_2 , V_197 ) ;
F_133 ( V_3 ) ;
}
F_12 ( V_3 ) ;
}
static int F_134 ( struct V_6 * V_6 ,
T_1 V_30 ,
T_1 V_127 ,
struct V_198 * V_199 ,
struct V_11 * * V_200 )
{
int V_10 = - V_201 ;
struct V_11 * V_2 = NULL ;
struct V_202 V_203 = { 0 } ;
struct V_204 V_205 = { 0 } ;
#if F_53 ( V_62 )
struct V_206 V_207 = { 0 } ;
struct V_208 V_209 = { 0 } ;
#endif
switch ( V_199 -> V_129 ) {
case V_130 :
#if F_53 ( V_62 )
if ( V_199 -> V_210 && V_199 -> V_211 ) {
V_10 = F_135 ( V_212 , V_213 , 0 , & V_2 ) ;
if ( V_10 < 0 )
goto V_12;
F_136 ( V_2 -> V_3 , V_6 ) ;
V_207 . V_214 = V_212 ;
memcpy ( & V_207 . V_215 , V_199 -> V_210 ,
sizeof( V_207 . V_215 ) ) ;
V_207 . V_216 = F_86 ( V_199 -> V_217 ) ;
V_10 = F_137 ( V_2 , (struct V_218 * ) & V_207 ,
sizeof( V_207 ) ) ;
if ( V_10 < 0 )
goto V_12;
V_207 . V_214 = V_212 ;
memcpy ( & V_207 . V_215 , V_199 -> V_211 ,
sizeof( V_207 . V_215 ) ) ;
V_207 . V_216 = F_86 ( V_199 -> V_219 ) ;
V_10 = F_138 ( V_2 ,
(struct V_218 * ) & V_207 ,
sizeof( V_207 ) , 0 ) ;
if ( V_10 < 0 )
goto V_12;
} else
#endif
{
V_10 = F_135 ( V_220 , V_213 , 0 , & V_2 ) ;
if ( V_10 < 0 )
goto V_12;
F_136 ( V_2 -> V_3 , V_6 ) ;
V_203 . V_221 = V_220 ;
V_203 . V_222 = V_199 -> V_223 ;
V_203 . V_224 = F_86 ( V_199 -> V_217 ) ;
V_10 = F_137 ( V_2 , (struct V_218 * ) & V_203 ,
sizeof( V_203 ) ) ;
if ( V_10 < 0 )
goto V_12;
V_203 . V_221 = V_220 ;
V_203 . V_222 = V_199 -> V_225 ;
V_203 . V_224 = F_86 ( V_199 -> V_219 ) ;
V_10 = F_138 ( V_2 ,
(struct V_218 * ) & V_203 ,
sizeof( V_203 ) , 0 ) ;
if ( V_10 < 0 )
goto V_12;
}
if ( ! V_199 -> V_226 )
V_2 -> V_3 -> V_61 = V_174 ;
break;
case V_177 :
#if F_53 ( V_62 )
if ( V_199 -> V_210 && V_199 -> V_211 ) {
V_10 = F_135 ( V_212 , V_213 ,
V_227 , & V_2 ) ;
if ( V_10 < 0 )
goto V_12;
F_136 ( V_2 -> V_3 , V_6 ) ;
V_209 . V_228 = V_212 ;
memcpy ( & V_209 . V_229 , V_199 -> V_210 ,
sizeof( V_209 . V_229 ) ) ;
V_209 . V_230 = V_30 ;
V_10 = F_137 ( V_2 , (struct V_218 * ) & V_209 ,
sizeof( V_209 ) ) ;
if ( V_10 < 0 )
goto V_12;
V_209 . V_228 = V_212 ;
memcpy ( & V_209 . V_229 , V_199 -> V_211 ,
sizeof( V_209 . V_229 ) ) ;
V_209 . V_230 = V_127 ;
V_10 = F_138 ( V_2 ,
(struct V_218 * ) & V_209 ,
sizeof( V_209 ) , 0 ) ;
if ( V_10 < 0 )
goto V_12;
} else
#endif
{
V_10 = F_135 ( V_220 , V_213 ,
V_227 , & V_2 ) ;
if ( V_10 < 0 )
goto V_12;
F_136 ( V_2 -> V_3 , V_6 ) ;
V_205 . V_228 = V_220 ;
V_205 . V_229 = V_199 -> V_223 ;
V_205 . V_230 = V_30 ;
V_10 = F_137 ( V_2 , (struct V_218 * ) & V_205 ,
sizeof( V_205 ) ) ;
if ( V_10 < 0 )
goto V_12;
V_205 . V_228 = V_220 ;
V_205 . V_229 = V_199 -> V_225 ;
V_205 . V_230 = V_127 ;
V_10 = F_138 ( V_2 , (struct V_218 * ) & V_205 ,
sizeof( V_205 ) , 0 ) ;
if ( V_10 < 0 )
goto V_12;
}
break;
default:
goto V_12;
}
V_12:
* V_200 = V_2 ;
if ( ( V_10 < 0 ) && V_2 ) {
F_132 ( V_2 , V_197 ) ;
F_133 ( V_2 -> V_3 ) ;
* V_200 = NULL ;
}
return V_10 ;
}
int F_139 ( struct V_6 * V_6 , int V_13 , int V_96 , T_1 V_30 , T_1 V_127 , struct V_198 * V_199 , struct V_1 * * V_231 )
{
struct V_1 * V_8 = NULL ;
int V_10 ;
struct V_11 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
struct V_5 * V_17 ;
enum V_232 V_129 = V_130 ;
if ( V_13 < 0 ) {
V_10 = F_134 ( V_6 , V_30 , V_127 ,
V_199 , & V_2 ) ;
if ( V_10 < 0 )
goto V_10;
} else {
V_2 = F_10 ( V_13 , & V_10 ) ;
if ( ! V_2 ) {
F_140 ( L_32 ,
V_30 , V_13 , V_10 ) ;
V_10 = - V_233 ;
goto V_10;
}
if ( ! F_141 ( F_142 ( V_2 -> V_3 ) , V_6 ) ) {
F_140 ( L_33 , V_30 ) ;
V_10 = - V_201 ;
goto V_10;
}
}
V_3 = V_2 -> V_3 ;
if ( V_199 != NULL )
V_129 = V_199 -> V_129 ;
switch ( V_129 ) {
case V_130 :
V_10 = - V_234 ;
if ( V_3 -> V_235 != V_72 ) {
F_140 ( L_34 ,
V_30 , V_13 , V_3 -> V_235 , V_72 ) ;
goto V_10;
}
break;
case V_177 :
V_10 = - V_234 ;
if ( V_3 -> V_235 != V_227 ) {
F_140 ( L_34 ,
V_30 , V_13 , V_3 -> V_235 , V_227 ) ;
goto V_10;
}
break;
}
V_8 = V_1 ( V_3 ) ;
if ( V_8 != NULL ) {
V_10 = - V_236 ;
goto V_10;
}
V_8 = F_143 ( sizeof( struct V_1 ) , V_237 ) ;
if ( V_8 == NULL ) {
V_10 = - V_238 ;
goto V_10;
}
V_8 -> V_96 = V_96 ;
V_8 -> V_30 = V_30 ;
V_8 -> V_127 = V_127 ;
V_8 -> V_114 = V_239 ;
V_8 -> V_110 = V_240 ;
sprintf ( & V_8 -> V_39 [ 0 ] , L_35 , V_30 ) ;
F_144 ( & V_8 -> V_23 ) ;
V_8 -> V_5 = V_6 ;
V_17 = F_1 ( V_6 ) ;
if ( V_199 != NULL )
V_8 -> V_114 = V_199 -> V_114 ;
#if F_53 ( V_62 )
if ( V_3 -> V_63 == V_64 ) {
struct V_145 * V_146 = F_96 ( V_3 ) ;
if ( F_145 ( & V_146 -> V_70 ) &&
F_145 ( & V_3 -> V_150 ) ) {
struct V_75 * V_76 = F_58 ( V_3 ) ;
V_8 -> V_65 = true ;
V_76 -> V_77 = V_146 -> V_70 . V_241 [ 3 ] ;
V_76 -> V_242 = V_3 -> V_243 . V_241 [ 3 ] ;
V_76 -> V_78 = V_3 -> V_150 . V_241 [ 3 ] ;
} else {
V_8 -> V_65 = false ;
}
}
#endif
V_8 -> V_129 = V_129 ;
if ( V_129 == V_130 ) {
F_115 ( V_3 ) -> V_180 = V_244 ;
F_115 ( V_3 ) -> V_181 = F_84 ;
F_115 ( V_3 ) -> V_182 = F_126 ;
#if F_53 ( V_62 )
if ( V_3 -> V_63 == V_64 && ! V_8 -> V_65 )
F_146 () ;
else
#endif
F_147 () ;
}
V_3 -> V_4 = V_8 ;
V_8 -> V_184 = V_3 -> V_183 ;
V_3 -> V_183 = & F_114 ;
V_8 -> V_2 = V_3 ;
V_8 -> V_13 = V_13 ;
F_148 ( & V_3 -> V_245 . V_246 , & V_247 , L_36 ) ;
V_3 -> V_248 = V_249 ;
F_149 ( & V_8 -> V_196 , F_129 ) ;
F_150 ( & V_8 -> V_186 ) ;
F_5 ( & V_187 ) ;
F_151 ( V_8 ) ;
F_34 ( & V_17 -> V_185 ) ;
F_152 ( & V_8 -> V_186 , & V_17 -> V_250 ) ;
F_41 ( & V_17 -> V_185 ) ;
V_10 = 0 ;
V_10:
if ( V_231 )
* V_231 = V_8 ;
if ( V_2 && V_2 -> V_251 )
F_14 ( V_2 ) ;
return V_10 ;
}
int F_153 ( struct V_1 * V_8 )
{
F_118 ( V_8 ) ;
return ( false == F_154 ( V_252 , & V_8 -> V_196 ) ) ;
}
void F_155 ( struct V_15 * V_20 )
{
struct V_1 * V_8 = V_20 -> V_8 ;
F_2 ( F_127 ( & V_20 -> V_9 ) != 0 ) ;
if ( V_8 ) {
F_2 ( V_8 -> V_110 != V_240 ) ;
if ( V_20 -> V_16 != 0 )
F_117 ( & V_253 ) ;
F_15 ( V_8 -> V_2 ) ;
V_20 -> V_8 = NULL ;
F_119 ( V_8 ) ;
}
F_156 ( V_20 ) ;
return;
}
void F_125 ( struct V_15 * V_20 )
{
struct V_1 * V_8 = V_20 -> V_8 ;
if ( V_8 ) {
F_120 ( & V_8 -> V_23 ) ;
F_123 ( & V_20 -> V_191 ) ;
F_124 ( & V_8 -> V_23 ) ;
if ( V_8 -> V_96 != V_97 ) {
struct V_5 * V_17 = F_1 ( V_8 -> V_5 ) ;
F_34 ( & V_17 -> V_254 ) ;
F_157 ( & V_20 -> V_255 ) ;
F_41 ( & V_17 -> V_254 ) ;
F_158 () ;
}
}
}
int F_159 ( struct V_15 * V_20 )
{
if ( V_20 -> V_91 )
(* V_20 -> V_91 )( V_20 ) ;
F_125 ( V_20 ) ;
F_76 ( V_20 ) ;
if ( V_20 -> V_192 != NULL )
(* V_20 -> V_192 )( V_20 ) ;
if ( V_20 -> V_49 )
(* V_20 -> V_49 )( V_20 ) ;
F_75 ( V_20 ) ;
return 0 ;
}
static void F_71 ( struct V_15 * V_20 , int V_96 )
{
if ( V_96 == V_97 ) {
V_20 -> V_156 = 6 ;
if ( V_20 -> V_106 )
V_20 -> V_156 += 4 ;
} else {
V_20 -> V_156 = 4 + V_20 -> V_132 + V_20 -> V_104 + V_20 -> V_90 ;
if ( V_20 -> V_8 -> V_129 == V_130 )
V_20 -> V_156 += 4 ;
}
}
struct V_15 * F_160 ( int V_256 , struct V_1 * V_8 , T_1 V_16 , T_1 V_128 , struct V_257 * V_199 )
{
struct V_15 * V_20 ;
V_20 = F_143 ( sizeof( struct V_15 ) + V_256 , V_237 ) ;
if ( V_20 != NULL ) {
V_20 -> V_110 = V_111 ;
V_20 -> V_8 = V_8 ;
V_20 -> V_16 = V_16 ;
V_20 -> V_128 = V_128 ;
V_20 -> V_46 = 0 ;
if ( V_8 -> V_96 == V_97 )
V_20 -> V_47 = 0xffff ;
else
V_20 -> V_47 = 0xffffff ;
V_20 -> V_80 = V_20 -> V_47 / 2 ;
V_20 -> V_86 = 4 ;
V_20 -> V_55 = 1 ;
sprintf ( & V_20 -> V_39 [ 0 ] , L_37 ,
V_8 -> V_30 , V_20 -> V_16 ) ;
F_161 ( & V_20 -> V_36 ) ;
F_162 ( & V_20 -> V_191 ) ;
F_162 ( & V_20 -> V_255 ) ;
V_20 -> V_114 = V_8 -> V_114 ;
if ( V_199 ) {
V_20 -> V_258 = V_199 -> V_259 ;
V_20 -> V_114 = V_199 -> V_114 ;
V_20 -> V_260 = V_199 -> V_260 ;
V_20 -> V_261 = V_199 -> V_261 ;
V_20 -> V_106 = V_199 -> V_106 ;
V_20 -> V_107 = V_199 -> V_107 ;
V_20 -> V_105 = V_199 -> V_105 ;
V_20 -> V_82 = V_199 -> V_82 ;
V_20 -> V_90 = V_199 -> V_90 ;
V_20 -> V_100 = V_199 -> V_100 ;
V_20 -> V_104 = V_199 -> V_104 ;
V_20 -> V_132 = V_199 -> V_132 ;
memcpy ( & V_20 -> V_133 [ 0 ] , & V_199 -> V_133 [ 0 ] , V_199 -> V_132 ) ;
V_20 -> V_92 = V_199 -> V_92 ;
memcpy ( & V_20 -> V_93 [ 0 ] , & V_199 -> V_93 [ 0 ] , V_199 -> V_92 ) ;
}
if ( V_8 -> V_96 == V_97 )
V_20 -> V_163 = F_85 ;
else
V_20 -> V_163 = F_87 ;
F_71 ( V_20 , V_8 -> V_96 ) ;
F_68 ( V_20 ) ;
F_151 ( V_8 ) ;
F_11 ( V_8 -> V_2 ) ;
F_120 ( & V_8 -> V_23 ) ;
F_163 ( & V_20 -> V_191 ,
F_21 ( V_8 , V_16 ) ) ;
F_124 ( & V_8 -> V_23 ) ;
if ( V_8 -> V_96 != V_97 ) {
struct V_5 * V_17 = F_1 ( V_8 -> V_5 ) ;
F_34 ( & V_17 -> V_254 ) ;
F_164 ( & V_20 -> V_255 ,
F_17 ( V_17 , V_16 ) ) ;
F_41 ( & V_17 -> V_254 ) ;
}
if ( V_20 -> V_16 != 0 )
F_5 ( & V_253 ) ;
}
return V_20 ;
}
static T_5 int F_165 ( struct V_6 * V_6 )
{
struct V_5 * V_17 = F_3 ( V_6 , V_7 ) ;
int V_25 ;
F_150 ( & V_17 -> V_250 ) ;
F_166 ( & V_17 -> V_185 ) ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ )
F_167 ( & V_17 -> V_262 [ V_25 ] ) ;
F_166 ( & V_17 -> V_254 ) ;
return 0 ;
}
static T_6 void F_168 ( struct V_6 * V_6 )
{
struct V_5 * V_17 = F_1 ( V_6 ) ;
struct V_1 * V_8 = NULL ;
F_18 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
( void ) F_153 ( V_8 ) ;
}
F_20 () ;
}
static int T_7 F_169 ( void )
{
int V_263 = 0 ;
V_263 = F_170 ( & V_264 ) ;
if ( V_263 )
goto V_12;
V_252 = F_171 ( L_38 , V_265 | V_266 , 0 ) ;
if ( ! V_252 ) {
F_140 ( L_39 ) ;
V_263 = - V_238 ;
goto V_12;
}
F_172 ( L_40 , V_267 ) ;
V_12:
return V_263 ;
}
static void T_8 F_173 ( void )
{
F_174 ( & V_264 ) ;
if ( V_252 ) {
F_175 ( V_252 ) ;
V_252 = NULL ;
}
}
