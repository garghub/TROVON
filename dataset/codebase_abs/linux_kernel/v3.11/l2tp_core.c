static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
F_2 ( ! V_2 ) ;
return F_3 ( V_2 , V_3 ) ;
}
static inline void F_4 ( struct V_4 * V_5 )
{
F_5 ( & V_5 -> V_6 ) ;
}
static inline void F_6 ( struct V_4 * V_5 )
{
if ( F_7 ( & V_5 -> V_6 ) )
F_8 ( V_5 ) ;
}
struct V_7 * F_9 ( struct V_4 * V_5 )
{
int V_8 = 0 ;
struct V_9 * V_7 = NULL ;
struct V_7 * V_10 = NULL ;
if ( ! V_5 )
goto V_11;
if ( V_5 -> V_12 >= 0 ) {
V_7 = F_10 ( V_5 -> V_12 , & V_8 ) ;
if ( V_7 )
V_10 = V_7 -> V_10 ;
} else {
V_10 = V_5 -> V_7 ;
F_11 ( V_10 ) ;
}
V_11:
return V_10 ;
}
void F_12 ( struct V_7 * V_10 )
{
struct V_4 * V_5 = F_13 ( V_10 ) ;
if ( V_5 ) {
if ( V_5 -> V_12 >= 0 ) {
F_14 ( V_10 -> V_13 ) ;
}
F_15 ( V_10 ) ;
}
F_15 ( V_10 ) ;
}
static struct V_14 * F_16 ( struct V_2 * V_2 , T_1 V_15 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
struct V_17 * V_18 =
F_17 ( V_16 , V_15 ) ;
struct V_14 * V_19 ;
F_18 () ;
F_19 (session, session_list, global_hlist) {
if ( V_19 -> V_15 == V_15 ) {
F_20 () ;
return V_19 ;
}
}
F_20 () ;
return NULL ;
}
static inline struct V_17 *
F_21 ( struct V_4 * V_5 , T_1 V_15 )
{
return & V_5 -> V_20 [ F_22 ( V_15 , V_21 ) ] ;
}
struct V_14 * F_23 ( struct V_2 * V_2 , struct V_4 * V_5 , T_1 V_15 )
{
struct V_17 * V_18 ;
struct V_14 * V_19 ;
if ( V_5 == NULL )
return F_16 ( V_2 , V_15 ) ;
V_18 = F_21 ( V_5 , V_15 ) ;
F_24 ( & V_5 -> V_22 ) ;
F_25 (session, session_list, hlist) {
if ( V_19 -> V_15 == V_15 ) {
F_26 ( & V_5 -> V_22 ) ;
return V_19 ;
}
}
F_26 ( & V_5 -> V_22 ) ;
return NULL ;
}
struct V_14 * F_27 ( struct V_4 * V_5 , int V_23 )
{
int V_24 ;
struct V_14 * V_19 ;
int V_25 = 0 ;
F_24 ( & V_5 -> V_22 ) ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
F_25 (session, &tunnel->session_hlist[hash], hlist) {
if ( ++ V_25 > V_23 ) {
F_26 ( & V_5 -> V_22 ) ;
return V_19 ;
}
}
}
F_26 ( & V_5 -> V_22 ) ;
return NULL ;
}
struct V_14 * F_28 ( struct V_2 * V_2 , char * V_27 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
int V_24 ;
struct V_14 * V_19 ;
F_18 () ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ ) {
F_19 (session, &pn->l2tp_session_hlist[hash], global_hlist) {
if ( ! strcmp ( V_19 -> V_27 , V_27 ) ) {
F_20 () ;
return V_19 ;
}
}
}
F_20 () ;
return NULL ;
}
struct V_4 * F_29 ( struct V_2 * V_2 , T_1 V_29 )
{
struct V_4 * V_5 ;
struct V_1 * V_16 = F_1 ( V_2 ) ;
F_18 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( V_5 -> V_29 == V_29 ) {
F_20 () ;
return V_5 ;
}
}
F_20 () ;
return NULL ;
}
struct V_4 * F_31 ( struct V_2 * V_2 , int V_23 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
struct V_4 * V_5 ;
int V_25 = 0 ;
F_18 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( ++ V_25 > V_23 ) {
F_20 () ;
return V_5 ;
}
}
F_20 () ;
return NULL ;
}
static void F_32 ( struct V_14 * V_19 , struct V_30 * V_31 )
{
struct V_30 * V_32 ;
struct V_30 * V_33 ;
T_1 V_34 = F_33 ( V_31 ) -> V_34 ;
F_34 ( & V_19 -> V_35 . V_36 ) ;
F_35 (&session->reorder_q, skbp, tmp) {
if ( F_33 ( V_32 ) -> V_34 > V_34 ) {
F_36 ( & V_19 -> V_35 , V_32 , V_31 ) ;
F_37 ( V_19 , V_37 ,
L_1 ,
V_19 -> V_38 , V_34 , F_33 ( V_32 ) -> V_34 ,
F_38 ( & V_19 -> V_35 ) ) ;
F_39 ( & V_19 -> V_39 . V_40 ) ;
goto V_11;
}
}
F_40 ( & V_19 -> V_35 , V_31 ) ;
V_11:
F_41 ( & V_19 -> V_35 . V_36 ) ;
}
static void F_42 ( struct V_14 * V_19 , struct V_30 * V_31 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
int V_41 = F_33 ( V_31 ) -> V_41 ;
F_43 ( V_31 ) ;
F_39 ( & V_5 -> V_39 . V_42 ) ;
F_44 ( V_41 , & V_5 -> V_39 . V_43 ) ;
F_39 ( & V_19 -> V_39 . V_42 ) ;
F_44 ( V_41 , & V_19 -> V_39 . V_43 ) ;
if ( F_33 ( V_31 ) -> V_44 ) {
V_19 -> V_45 ++ ;
V_19 -> V_45 &= V_19 -> V_46 ;
F_37 ( V_19 , V_37 , L_2 ,
V_19 -> V_38 , V_19 -> V_45 ) ;
}
if ( V_19 -> V_47 != NULL )
(* V_19 -> V_47 )( V_19 , V_31 , F_33 ( V_31 ) -> V_41 ) ;
else
F_45 ( V_31 ) ;
if ( V_19 -> V_48 )
(* V_19 -> V_48 )( V_19 ) ;
}
static void F_46 ( struct V_14 * V_19 )
{
struct V_30 * V_31 ;
struct V_30 * V_33 ;
V_49:
F_34 ( & V_19 -> V_35 . V_36 ) ;
F_35 (&session->reorder_q, skb, tmp) {
if ( F_47 ( V_50 , F_33 ( V_31 ) -> V_51 ) ) {
F_39 ( & V_19 -> V_39 . V_52 ) ;
F_39 ( & V_19 -> V_39 . V_53 ) ;
F_37 ( V_19 , V_37 ,
L_3 ,
V_19 -> V_38 , F_33 ( V_31 ) -> V_34 ,
F_33 ( V_31 ) -> V_41 , V_19 -> V_45 ,
F_38 ( & V_19 -> V_35 ) ) ;
V_19 -> V_54 = 1 ;
F_48 ( V_31 , & V_19 -> V_35 ) ;
F_45 ( V_31 ) ;
if ( V_19 -> V_48 )
(* V_19 -> V_48 )( V_19 ) ;
continue;
}
if ( F_33 ( V_31 ) -> V_44 ) {
if ( V_19 -> V_54 ) {
F_37 ( V_19 , V_37 ,
L_4 ,
V_19 -> V_38 , V_19 -> V_45 ,
F_33 ( V_31 ) -> V_34 ) ;
V_19 -> V_54 = 0 ;
V_19 -> V_45 = F_33 ( V_31 ) -> V_34 ;
}
if ( F_33 ( V_31 ) -> V_34 != V_19 -> V_45 ) {
F_37 ( V_19 , V_37 ,
L_5 ,
V_19 -> V_38 , F_33 ( V_31 ) -> V_34 ,
F_33 ( V_31 ) -> V_41 , V_19 -> V_45 ,
F_38 ( & V_19 -> V_35 ) ) ;
goto V_11;
}
}
F_48 ( V_31 , & V_19 -> V_35 ) ;
F_41 ( & V_19 -> V_35 . V_36 ) ;
F_42 ( V_19 , V_31 ) ;
goto V_49;
}
V_11:
F_41 ( & V_19 -> V_35 . V_36 ) ;
}
static inline int F_49 ( struct V_7 * V_10 ,
struct V_30 * V_31 )
{
struct V_55 * V_56 = F_50 ( V_31 ) ;
T_2 V_57 = F_51 ( V_56 -> V_58 ) ;
T_3 V_59 ;
if ( V_10 -> V_60 || F_52 ( V_31 ) )
return 0 ;
#if F_53 ( V_61 )
if ( V_10 -> V_62 == V_63 ) {
if ( ! V_56 -> V_64 ) {
F_54 ( V_65 L_6 ) ;
return 1 ;
}
if ( ( V_31 -> V_66 == V_67 ) &&
! F_55 ( & F_56 ( V_31 ) -> V_68 ,
& F_56 ( V_31 ) -> V_69 , V_57 ,
V_70 , V_31 -> V_71 ) ) {
V_31 -> V_66 = V_72 ;
return 0 ;
}
V_31 -> V_71 = ~ F_57 ( F_55 ( & F_56 ( V_31 ) -> V_68 ,
& F_56 ( V_31 ) -> V_69 ,
V_31 -> V_58 , V_70 ,
0 ) ) ;
} else
#endif
{
struct V_73 * V_74 ;
if ( ! V_56 -> V_64 )
return 0 ;
V_74 = F_58 ( V_10 ) ;
V_59 = F_59 ( V_74 -> V_75 , V_74 -> V_76 ,
V_57 , V_70 , 0 ) ;
if ( ( V_31 -> V_66 == V_67 ) &&
! F_60 ( F_61 ( V_59 , V_31 -> V_71 ) ) )
return 0 ;
V_31 -> V_71 = V_59 ;
}
return F_62 ( V_31 ) ;
}
static int F_63 ( struct V_14 * V_19 , T_1 V_45 )
{
T_1 V_77 ;
if ( V_45 >= V_19 -> V_45 )
V_77 = V_45 - V_19 -> V_45 ;
else
V_77 = ( V_19 -> V_46 + 1 ) - ( V_19 -> V_45 - V_45 ) ;
return V_77 < V_19 -> V_78 ;
}
static int F_64 ( struct V_14 * V_19 , struct V_30 * V_31 )
{
if ( ! F_63 ( V_19 , F_33 ( V_31 ) -> V_34 ) ) {
F_37 ( V_19 , V_37 ,
L_7 ,
V_19 -> V_38 , F_33 ( V_31 ) -> V_34 ,
F_33 ( V_31 ) -> V_41 , V_19 -> V_45 ) ;
goto V_79;
}
if ( V_19 -> V_80 != 0 ) {
F_32 ( V_19 , V_31 ) ;
goto V_11;
}
if ( F_33 ( V_31 ) -> V_34 == V_19 -> V_45 ) {
F_65 ( & V_19 -> V_35 , V_31 ) ;
} else {
T_1 V_81 = F_33 ( V_31 ) -> V_34 ;
T_1 V_82 = ( V_19 -> V_81 + 1 ) & V_19 -> V_46 ;
if ( V_81 == V_82 )
V_19 -> V_83 ++ ;
else
V_19 -> V_83 = 0 ;
V_19 -> V_81 = V_81 ;
if ( V_19 -> V_83 > V_19 -> V_84 ) {
V_19 -> V_54 = 1 ;
F_37 ( V_19 , V_37 ,
L_8 ,
V_19 -> V_38 , V_19 -> V_83 ) ;
}
if ( ! V_19 -> V_54 ) {
F_39 ( & V_19 -> V_39 . V_52 ) ;
F_37 ( V_19 , V_37 ,
L_9 ,
V_19 -> V_38 , F_33 ( V_31 ) -> V_34 ,
F_33 ( V_31 ) -> V_41 , V_19 -> V_45 ,
F_38 ( & V_19 -> V_35 ) ) ;
goto V_79;
}
F_65 ( & V_19 -> V_35 , V_31 ) ;
}
V_11:
return 0 ;
V_79:
return 1 ;
}
void F_66 ( struct V_14 * V_19 , struct V_30 * V_31 ,
unsigned char * V_85 , unsigned char * V_86 , T_2 V_87 ,
int V_41 , int (* F_67)( struct V_30 * V_31 ) )
{
struct V_4 * V_5 = V_19 -> V_5 ;
int V_88 ;
T_1 V_34 , V_45 ;
F_68 ( V_19 ) ;
if ( V_19 -> V_89 )
(* V_19 -> V_89 )( V_19 ) ;
if ( V_19 -> V_90 > 0 ) {
if ( memcmp ( V_85 , & V_19 -> V_91 [ 0 ] , V_19 -> V_90 ) ) {
F_69 ( V_5 , V_92 ,
L_10 ,
V_5 -> V_38 , V_5 -> V_29 ,
V_19 -> V_15 ) ;
F_39 ( & V_19 -> V_39 . V_93 ) ;
goto V_79;
}
V_85 += V_19 -> V_90 ;
}
V_34 = V_45 = 0 ;
F_33 ( V_31 ) -> V_44 = 0 ;
if ( V_5 -> V_94 == V_95 ) {
if ( V_87 & V_96 ) {
V_34 = F_51 ( * ( V_97 * ) V_85 ) ;
V_85 += 2 ;
V_45 = F_51 ( * ( V_97 * ) V_85 ) ;
V_85 += 2 ;
F_33 ( V_31 ) -> V_34 = V_34 ;
F_33 ( V_31 ) -> V_44 = 1 ;
F_37 ( V_19 , V_37 ,
L_11 ,
V_19 -> V_38 , V_34 , V_45 , V_19 -> V_45 ) ;
}
} else if ( V_19 -> V_98 == V_99 ) {
T_1 V_100 = F_70 ( * ( V_101 * ) V_85 ) ;
if ( V_100 & 0x40000000 ) {
V_34 = V_100 & 0x00ffffff ;
F_33 ( V_31 ) -> V_34 = V_34 ;
F_33 ( V_31 ) -> V_44 = 1 ;
F_37 ( V_19 , V_37 ,
L_12 ,
V_19 -> V_38 , V_34 , V_19 -> V_45 ) ;
}
}
V_85 += V_19 -> V_102 ;
if ( F_33 ( V_31 ) -> V_44 ) {
if ( ( ! V_19 -> V_103 ) && ( ! V_19 -> V_104 ) ) {
F_69 ( V_19 , V_37 ,
L_13 ,
V_19 -> V_38 ) ;
V_19 -> V_104 = - 1 ;
F_71 ( V_19 , V_5 -> V_94 ) ;
}
} else {
if ( V_19 -> V_105 ) {
F_72 ( V_19 , V_37 ,
L_14 ,
V_19 -> V_38 ) ;
F_39 ( & V_19 -> V_39 . V_52 ) ;
goto V_79;
}
if ( ( ! V_19 -> V_103 ) && ( V_19 -> V_104 ) ) {
F_69 ( V_19 , V_37 ,
L_15 ,
V_19 -> V_38 ) ;
V_19 -> V_104 = 0 ;
F_71 ( V_19 , V_5 -> V_94 ) ;
} else if ( V_19 -> V_104 ) {
F_72 ( V_19 , V_37 ,
L_14 ,
V_19 -> V_38 ) ;
F_39 ( & V_19 -> V_39 . V_52 ) ;
goto V_79;
}
}
if ( V_5 -> V_94 == V_95 ) {
if ( V_87 & V_106 ) {
V_88 = F_51 ( * ( V_97 * ) V_85 ) ;
V_85 += 2 + V_88 ;
}
} else
V_85 += V_19 -> V_88 ;
V_88 = V_85 - V_86 ;
if ( ! F_73 ( V_31 , V_88 ) )
goto V_79;
F_74 ( V_31 , V_88 ) ;
if ( F_67 )
if ( (* F_67)( V_31 ) )
goto V_79;
F_33 ( V_31 ) -> V_41 = V_41 ;
F_33 ( V_31 ) -> V_51 = V_50 +
( V_19 -> V_80 ? V_19 -> V_80 : V_107 ) ;
if ( F_33 ( V_31 ) -> V_44 ) {
if ( F_64 ( V_19 , V_31 ) )
goto V_79;
} else {
F_65 ( & V_19 -> V_35 , V_31 ) ;
}
F_46 ( V_19 ) ;
F_75 ( V_19 ) ;
return;
V_79:
F_39 ( & V_19 -> V_39 . V_53 ) ;
F_45 ( V_31 ) ;
if ( V_19 -> V_48 )
(* V_19 -> V_48 )( V_19 ) ;
F_75 ( V_19 ) ;
}
int F_76 ( struct V_14 * V_19 )
{
struct V_30 * V_31 = NULL ;
F_2 ( ! V_19 ) ;
F_2 ( V_19 -> V_108 != V_109 ) ;
while ( ( V_31 = F_77 ( & V_19 -> V_35 ) ) ) {
F_39 ( & V_19 -> V_39 . V_53 ) ;
F_45 ( V_31 ) ;
if ( V_19 -> V_48 )
(* V_19 -> V_48 )( V_19 ) ;
}
return 0 ;
}
static int F_78 ( struct V_4 * V_5 , struct V_30 * V_31 ,
int (* F_67)( struct V_30 * V_31 ) )
{
struct V_14 * V_19 = NULL ;
unsigned char * V_85 , * V_86 ;
T_2 V_87 ;
T_1 V_29 , V_15 ;
T_2 V_94 ;
int V_41 ;
if ( V_5 -> V_7 && F_49 ( V_5 -> V_7 , V_31 ) )
goto V_110;
F_74 ( V_31 , sizeof( struct V_55 ) ) ;
if ( ! F_73 ( V_31 , V_111 ) ) {
F_69 ( V_5 , V_92 ,
L_16 ,
V_5 -> V_38 , V_31 -> V_58 ) ;
goto error;
}
if ( V_5 -> V_112 & V_92 ) {
V_41 = F_79 ( 32u , V_31 -> V_58 ) ;
if ( ! F_73 ( V_31 , V_41 ) )
goto error;
F_80 ( L_17 , V_5 -> V_38 ) ;
F_81 ( L_18 , V_113 , V_31 -> V_114 , V_41 ) ;
}
V_86 = V_85 = V_31 -> V_114 ;
V_87 = F_51 ( * ( V_97 * ) V_85 ) ;
V_94 = V_87 & V_115 ;
if ( V_94 != V_5 -> V_94 ) {
F_69 ( V_5 , V_92 ,
L_19 ,
V_5 -> V_38 , V_94 , V_5 -> V_94 ) ;
goto error;
}
V_41 = V_31 -> V_58 ;
if ( V_87 & V_116 ) {
F_37 ( V_5 , V_92 ,
L_20 ,
V_5 -> V_38 , V_41 ) ;
goto error;
}
V_85 += 2 ;
if ( V_5 -> V_94 == V_95 ) {
if ( V_87 & V_117 )
V_85 += 2 ;
V_29 = F_51 ( * ( V_97 * ) V_85 ) ;
V_85 += 2 ;
V_15 = F_51 ( * ( V_97 * ) V_85 ) ;
V_85 += 2 ;
} else {
V_85 += 2 ;
V_29 = V_5 -> V_29 ;
V_15 = F_70 ( * ( V_101 * ) V_85 ) ;
V_85 += 4 ;
}
V_19 = F_23 ( V_5 -> V_1 , V_5 , V_15 ) ;
if ( ! V_19 || ! V_19 -> V_47 ) {
F_69 ( V_5 , V_92 ,
L_21 ,
V_5 -> V_38 , V_29 , V_15 ) ;
goto error;
}
F_66 ( V_19 , V_31 , V_85 , V_86 , V_87 , V_41 , F_67 ) ;
return 0 ;
V_110:
F_54 ( L_22 , V_5 -> V_38 ) ;
F_82 ( V_5 -> V_1 , V_118 , 0 ) ;
F_39 ( & V_5 -> V_39 . V_53 ) ;
F_45 ( V_31 ) ;
return 0 ;
error:
F_83 ( V_31 , sizeof( struct V_55 ) ) ;
return 1 ;
}
int F_84 ( struct V_7 * V_10 , struct V_30 * V_31 )
{
struct V_4 * V_5 ;
V_5 = F_13 ( V_10 ) ;
if ( V_5 == NULL )
goto V_119;
F_37 ( V_5 , V_92 , L_23 ,
V_5 -> V_38 , V_31 -> V_58 ) ;
if ( F_78 ( V_5 , V_31 , V_5 -> V_120 ) )
goto V_121;
F_15 ( V_10 ) ;
return 0 ;
V_121:
F_15 ( V_10 ) ;
V_119:
return 1 ;
}
static int F_85 ( struct V_14 * V_19 , void * V_122 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
V_97 * V_123 = V_122 ;
V_97 * V_86 = V_122 ;
T_2 V_124 = V_95 ;
T_1 V_29 = V_5 -> V_125 ;
T_1 V_15 = V_19 -> V_126 ;
if ( V_19 -> V_104 )
V_124 |= V_96 ;
* V_123 ++ = F_86 ( V_124 ) ;
* V_123 ++ = F_86 ( V_29 ) ;
* V_123 ++ = F_86 ( V_15 ) ;
if ( V_19 -> V_104 ) {
* V_123 ++ = F_86 ( V_19 -> V_34 ) ;
* V_123 ++ = 0 ;
V_19 -> V_34 ++ ;
V_19 -> V_34 &= 0xffff ;
F_37 ( V_19 , V_37 , L_24 ,
V_19 -> V_38 , V_19 -> V_34 ) ;
}
return V_123 - V_86 ;
}
static int F_87 ( struct V_14 * V_19 , void * V_122 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
char * V_123 = V_122 ;
char * V_86 = V_123 ;
if ( V_5 -> V_127 == V_128 ) {
T_2 V_124 = V_129 ;
* ( ( V_97 * ) V_123 ) = F_86 ( V_124 ) ;
V_123 += 2 ;
* ( ( V_97 * ) V_123 ) = 0 ;
V_123 += 2 ;
}
* ( ( V_101 * ) V_123 ) = F_88 ( V_19 -> V_126 ) ;
V_123 += 4 ;
if ( V_19 -> V_130 ) {
memcpy ( V_123 , & V_19 -> V_131 [ 0 ] , V_19 -> V_130 ) ;
V_123 += V_19 -> V_130 ;
}
if ( V_19 -> V_102 ) {
if ( V_19 -> V_98 == V_99 ) {
T_1 V_100 = 0 ;
if ( V_19 -> V_104 ) {
V_100 = 0x40000000 | V_19 -> V_34 ;
V_19 -> V_34 ++ ;
V_19 -> V_34 &= 0xffffff ;
F_37 ( V_19 , V_37 ,
L_24 ,
V_19 -> V_38 , V_19 -> V_34 ) ;
}
* ( ( V_101 * ) V_123 ) = F_88 ( V_100 ) ;
}
V_123 += V_19 -> V_102 ;
}
if ( V_19 -> V_88 )
V_123 += V_19 -> V_88 ;
return V_123 - V_86 ;
}
static int F_89 ( struct V_14 * V_19 , struct V_30 * V_31 ,
struct V_132 * V_133 , T_4 V_134 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
unsigned int V_58 = V_31 -> V_58 ;
int error ;
if ( V_19 -> V_104 )
F_37 ( V_19 , V_92 , L_25 ,
V_19 -> V_38 , V_134 , V_19 -> V_34 - 1 ) ;
else
F_37 ( V_19 , V_92 , L_26 ,
V_19 -> V_38 , V_134 ) ;
if ( V_19 -> V_112 & V_92 ) {
int V_135 = ( V_5 -> V_127 == V_128 ) ? sizeof( struct V_55 ) : 0 ;
unsigned char * V_136 = V_31 -> V_114 + V_135 ;
F_80 ( L_27 , V_19 -> V_38 ) ;
F_81 ( L_18 , V_113 ,
V_136 , F_90 ( T_4 , 32 , V_58 - V_135 ) ) ;
}
V_31 -> V_137 = 1 ;
#if F_53 ( V_61 )
if ( V_31 -> V_10 -> V_62 == V_63 )
error = F_91 ( V_31 , NULL ) ;
else
#endif
error = F_92 ( V_31 , V_133 ) ;
if ( error >= 0 ) {
F_39 ( & V_5 -> V_39 . V_138 ) ;
F_44 ( V_58 , & V_5 -> V_39 . V_139 ) ;
F_39 ( & V_19 -> V_39 . V_138 ) ;
F_44 ( V_58 , & V_19 -> V_39 . V_139 ) ;
} else {
F_39 ( & V_5 -> V_39 . V_140 ) ;
F_39 ( & V_19 -> V_39 . V_140 ) ;
}
return 0 ;
}
static void F_93 ( struct V_30 * V_31 )
{
F_15 ( V_31 -> V_10 ) ;
}
static inline void F_94 ( struct V_30 * V_31 , struct V_7 * V_10 )
{
F_11 ( V_10 ) ;
V_31 -> V_10 = V_10 ;
V_31 -> V_141 = F_93 ;
}
static void F_95 ( struct V_7 * V_10 , struct V_30 * V_31 ,
int V_142 )
{
struct V_143 * V_144 = F_96 ( V_10 ) ;
struct V_55 * V_56 = F_50 ( V_31 ) ;
if ( ! F_97 ( V_31 ) || ! F_97 ( V_31 ) -> V_145 ||
! ( F_97 ( V_31 ) -> V_145 -> V_146 & V_147 ) ) {
T_3 V_71 = F_98 ( V_31 , 0 , V_142 , 0 ) ;
V_31 -> V_66 = V_72 ;
V_56 -> V_64 = F_55 ( & V_144 -> V_68 , & V_144 -> V_69 , V_142 ,
V_70 , V_71 ) ;
if ( V_56 -> V_64 == 0 )
V_56 -> V_64 = V_148 ;
} else {
V_31 -> V_66 = V_149 ;
V_31 -> V_150 = F_99 ( V_31 ) - V_31 -> V_151 ;
V_31 -> V_152 = F_100 ( struct V_55 , V_64 ) ;
V_56 -> V_64 = ~ F_55 ( & V_144 -> V_68 , & V_144 -> V_69 ,
V_142 , V_70 , 0 ) ;
}
}
int F_101 ( struct V_14 * V_19 , struct V_30 * V_31 , int V_153 )
{
int V_134 = V_31 -> V_58 ;
struct V_4 * V_5 = V_19 -> V_5 ;
struct V_7 * V_10 = V_5 -> V_7 ;
struct V_132 * V_133 ;
struct V_55 * V_56 ;
struct V_73 * V_74 ;
T_3 V_71 ;
int V_154 ;
int V_135 = ( V_5 -> V_127 == V_128 ) ? sizeof( struct V_55 ) : 0 ;
int V_142 ;
int V_155 = V_156 ;
V_154 = V_157 + sizeof( struct V_158 ) +
V_135 + V_153 ;
if ( F_102 ( V_31 , V_154 ) ) {
F_45 ( V_31 ) ;
return V_159 ;
}
F_43 ( V_31 ) ;
V_19 -> V_160 ( V_19 , F_83 ( V_31 , V_153 ) ) ;
memset ( & ( F_103 ( V_31 ) -> V_161 ) , 0 , sizeof( F_103 ( V_31 ) -> V_161 ) ) ;
F_103 ( V_31 ) -> V_124 &= ~ ( V_162 | V_163 |
V_164 ) ;
F_104 ( V_31 ) ;
F_105 ( V_10 ) ;
if ( F_106 ( V_10 ) ) {
F_45 ( V_31 ) ;
V_155 = V_159 ;
goto V_165;
}
F_107 ( V_31 ) ;
F_108 ( V_31 , F_109 ( F_110 ( V_10 , 0 ) ) ) ;
V_74 = F_58 ( V_10 ) ;
V_133 = & V_74 -> V_166 . V_133 ;
switch ( V_5 -> V_127 ) {
case V_128 :
F_83 ( V_31 , sizeof( * V_56 ) ) ;
F_111 ( V_31 ) ;
V_56 = F_50 ( V_31 ) ;
V_56 -> V_167 = V_74 -> V_168 ;
V_56 -> V_169 = V_74 -> V_170 ;
V_142 = V_135 + V_153 + V_134 ;
V_56 -> V_58 = F_86 ( V_142 ) ;
V_56 -> V_64 = 0 ;
#if F_53 ( V_61 )
if ( V_10 -> V_62 == V_63 )
F_95 ( V_10 , V_31 , V_142 ) ;
else
#endif
if ( V_10 -> V_60 == V_171 )
V_31 -> V_66 = V_172 ;
else if ( ( F_97 ( V_31 ) && F_97 ( V_31 ) -> V_145 ) &&
( ! ( F_97 ( V_31 ) -> V_145 -> V_146 & V_173 ) ) ) {
V_31 -> V_66 = V_67 ;
V_71 = F_98 ( V_31 , 0 , V_142 , 0 ) ;
V_56 -> V_64 = F_112 ( V_74 -> V_75 ,
V_74 -> V_76 ,
V_142 , V_70 , V_71 ) ;
if ( V_56 -> V_64 == 0 )
V_56 -> V_64 = V_148 ;
} else {
V_31 -> V_66 = V_149 ;
V_31 -> V_150 = F_99 ( V_31 ) - V_31 -> V_151 ;
V_31 -> V_152 = F_100 ( struct V_55 , V_64 ) ;
V_56 -> V_64 = ~ F_112 ( V_74 -> V_75 ,
V_74 -> V_76 ,
V_142 , V_70 , 0 ) ;
}
break;
case V_174 :
break;
}
F_94 ( V_31 , V_10 ) ;
F_89 ( V_19 , V_31 , V_133 , V_134 ) ;
V_165:
F_113 ( V_10 ) ;
return V_155 ;
}
static void F_114 ( struct V_7 * V_10 )
{
struct V_4 * V_5 ;
struct V_1 * V_16 ;
V_5 = V_10 -> V_175 ;
if ( V_5 == NULL )
goto V_176;
F_69 ( V_5 , V_177 , L_28 , V_5 -> V_38 ) ;
switch ( V_5 -> V_127 ) {
case V_128 :
( F_115 ( V_10 ) ) -> V_178 = 0 ;
( F_115 ( V_10 ) ) -> V_179 = NULL ;
( F_115 ( V_10 ) ) -> V_180 = NULL ;
break;
case V_174 :
break;
}
V_10 -> V_181 = V_5 -> V_182 ;
V_10 -> V_175 = NULL ;
V_5 -> V_7 = NULL ;
V_16 = F_1 ( V_5 -> V_1 ) ;
F_34 ( & V_16 -> V_183 ) ;
F_116 ( & V_5 -> V_184 ) ;
F_41 ( & V_16 -> V_183 ) ;
F_117 ( & V_185 ) ;
F_118 ( V_5 ) ;
F_119 ( V_5 ) ;
if ( V_10 -> V_181 )
(* V_10 -> V_181 )( V_10 ) ;
V_176:
return;
}
void F_118 ( struct V_4 * V_5 )
{
int V_24 ;
struct V_186 * V_187 ;
struct V_186 * V_33 ;
struct V_14 * V_19 ;
F_2 ( V_5 == NULL ) ;
F_69 ( V_5 , V_177 , L_29 ,
V_5 -> V_38 ) ;
F_120 ( & V_5 -> V_22 ) ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
V_188:
F_121 (walk, tmp, &tunnel->session_hlist[hash]) {
V_19 = F_122 ( V_187 , struct V_14 , V_189 ) ;
F_69 ( V_19 , V_177 ,
L_30 , V_19 -> V_38 ) ;
F_123 ( & V_19 -> V_189 ) ;
if ( V_19 -> V_89 != NULL )
(* V_19 -> V_89 )( V_19 ) ;
F_124 ( & V_5 -> V_22 ) ;
F_125 ( V_19 ) ;
F_76 ( V_19 ) ;
if ( V_19 -> V_190 != NULL )
(* V_19 -> V_190 )( V_19 ) ;
if ( V_19 -> V_48 != NULL )
(* V_19 -> V_48 )( V_19 ) ;
F_75 ( V_19 ) ;
F_120 ( & V_5 -> V_22 ) ;
goto V_188;
}
}
F_124 ( & V_5 -> V_22 ) ;
}
static void F_126 ( struct V_7 * V_10 )
{
struct V_4 * V_5 = F_13 ( V_10 ) ;
if ( V_5 ) {
F_118 ( V_5 ) ;
F_15 ( V_10 ) ;
}
}
static void F_8 ( struct V_4 * V_5 )
{
F_2 ( F_127 ( & V_5 -> V_6 ) != 0 ) ;
F_2 ( V_5 -> V_7 != NULL ) ;
F_69 ( V_5 , V_177 , L_31 , V_5 -> V_38 ) ;
F_128 ( V_5 , V_191 ) ;
}
static void F_129 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = NULL ;
struct V_9 * V_7 = NULL ;
struct V_7 * V_10 = NULL ;
V_5 = F_130 ( V_193 , struct V_4 , V_194 ) ;
V_10 = F_9 ( V_5 ) ;
if ( ! V_10 )
return;
V_7 = V_10 -> V_13 ;
if ( V_5 -> V_12 >= 0 ) {
if ( V_7 )
F_131 ( V_7 , 2 ) ;
} else {
if ( V_7 )
F_132 ( V_7 , V_195 ) ;
F_133 ( V_10 ) ;
}
F_12 ( V_10 ) ;
}
static int F_134 ( struct V_2 * V_2 ,
T_1 V_29 ,
T_1 V_125 ,
struct V_196 * V_197 ,
struct V_9 * * V_198 )
{
int V_8 = - V_199 ;
struct V_9 * V_7 = NULL ;
struct V_200 V_201 = { 0 } ;
struct V_202 V_203 = { 0 } ;
#if F_53 ( V_61 )
struct V_204 V_205 = { 0 } ;
struct V_206 V_207 = { 0 } ;
#endif
switch ( V_197 -> V_127 ) {
case V_128 :
#if F_53 ( V_61 )
if ( V_197 -> V_208 && V_197 -> V_209 ) {
V_8 = F_135 ( V_210 , V_211 , 0 , & V_7 ) ;
if ( V_8 < 0 )
goto V_11;
F_136 ( V_7 -> V_10 , V_2 ) ;
V_205 . V_212 = V_210 ;
memcpy ( & V_205 . V_213 , V_197 -> V_208 ,
sizeof( V_205 . V_213 ) ) ;
V_205 . V_214 = F_86 ( V_197 -> V_215 ) ;
V_8 = F_137 ( V_7 , (struct V_216 * ) & V_205 ,
sizeof( V_205 ) ) ;
if ( V_8 < 0 )
goto V_11;
V_205 . V_212 = V_210 ;
memcpy ( & V_205 . V_213 , V_197 -> V_209 ,
sizeof( V_205 . V_213 ) ) ;
V_205 . V_214 = F_86 ( V_197 -> V_217 ) ;
V_8 = F_138 ( V_7 ,
(struct V_216 * ) & V_205 ,
sizeof( V_205 ) , 0 ) ;
if ( V_8 < 0 )
goto V_11;
} else
#endif
{
V_8 = F_135 ( V_218 , V_211 , 0 , & V_7 ) ;
if ( V_8 < 0 )
goto V_11;
F_136 ( V_7 -> V_10 , V_2 ) ;
V_201 . V_219 = V_218 ;
V_201 . V_220 = V_197 -> V_221 ;
V_201 . V_222 = F_86 ( V_197 -> V_215 ) ;
V_8 = F_137 ( V_7 , (struct V_216 * ) & V_201 ,
sizeof( V_201 ) ) ;
if ( V_8 < 0 )
goto V_11;
V_201 . V_219 = V_218 ;
V_201 . V_220 = V_197 -> V_223 ;
V_201 . V_222 = F_86 ( V_197 -> V_217 ) ;
V_8 = F_138 ( V_7 ,
(struct V_216 * ) & V_201 ,
sizeof( V_201 ) , 0 ) ;
if ( V_8 < 0 )
goto V_11;
}
if ( ! V_197 -> V_224 )
V_7 -> V_10 -> V_60 = V_171 ;
break;
case V_174 :
#if F_53 ( V_61 )
if ( V_197 -> V_208 && V_197 -> V_209 ) {
V_8 = F_135 ( V_210 , V_211 ,
V_225 , & V_7 ) ;
if ( V_8 < 0 )
goto V_11;
F_136 ( V_7 -> V_10 , V_2 ) ;
V_207 . V_226 = V_210 ;
memcpy ( & V_207 . V_227 , V_197 -> V_208 ,
sizeof( V_207 . V_227 ) ) ;
V_207 . V_228 = V_29 ;
V_8 = F_137 ( V_7 , (struct V_216 * ) & V_207 ,
sizeof( V_207 ) ) ;
if ( V_8 < 0 )
goto V_11;
V_207 . V_226 = V_210 ;
memcpy ( & V_207 . V_227 , V_197 -> V_209 ,
sizeof( V_207 . V_227 ) ) ;
V_207 . V_228 = V_125 ;
V_8 = F_138 ( V_7 ,
(struct V_216 * ) & V_207 ,
sizeof( V_207 ) , 0 ) ;
if ( V_8 < 0 )
goto V_11;
} else
#endif
{
V_8 = F_135 ( V_218 , V_211 ,
V_225 , & V_7 ) ;
if ( V_8 < 0 )
goto V_11;
F_136 ( V_7 -> V_10 , V_2 ) ;
V_203 . V_226 = V_218 ;
V_203 . V_227 = V_197 -> V_221 ;
V_203 . V_228 = V_29 ;
V_8 = F_137 ( V_7 , (struct V_216 * ) & V_203 ,
sizeof( V_203 ) ) ;
if ( V_8 < 0 )
goto V_11;
V_203 . V_226 = V_218 ;
V_203 . V_227 = V_197 -> V_223 ;
V_203 . V_228 = V_125 ;
V_8 = F_138 ( V_7 , (struct V_216 * ) & V_203 ,
sizeof( V_203 ) , 0 ) ;
if ( V_8 < 0 )
goto V_11;
}
break;
default:
goto V_11;
}
V_11:
* V_198 = V_7 ;
if ( ( V_8 < 0 ) && V_7 ) {
F_132 ( V_7 , V_195 ) ;
F_133 ( V_7 -> V_10 ) ;
* V_198 = NULL ;
}
return V_8 ;
}
int F_139 ( struct V_2 * V_2 , int V_12 , int V_94 , T_1 V_29 , T_1 V_125 , struct V_196 * V_197 , struct V_4 * * V_229 )
{
struct V_4 * V_5 = NULL ;
int V_8 ;
struct V_9 * V_7 = NULL ;
struct V_7 * V_10 = NULL ;
struct V_1 * V_16 ;
enum V_230 V_127 = V_128 ;
if ( V_12 < 0 ) {
V_8 = F_134 ( V_2 , V_29 , V_125 ,
V_197 , & V_7 ) ;
if ( V_8 < 0 )
goto V_8;
} else {
V_7 = F_10 ( V_12 , & V_8 ) ;
if ( ! V_7 ) {
F_140 ( L_32 ,
V_29 , V_12 , V_8 ) ;
V_8 = - V_231 ;
goto V_8;
}
if ( ! F_141 ( F_142 ( V_7 -> V_10 ) , V_2 ) ) {
F_140 ( L_33 , V_29 ) ;
V_8 = - V_199 ;
goto V_8;
}
}
V_10 = V_7 -> V_10 ;
if ( V_197 != NULL )
V_127 = V_197 -> V_127 ;
switch ( V_127 ) {
case V_128 :
V_8 = - V_232 ;
if ( V_10 -> V_233 != V_70 ) {
F_140 ( L_34 ,
V_29 , V_12 , V_10 -> V_233 , V_70 ) ;
goto V_8;
}
break;
case V_174 :
V_8 = - V_232 ;
if ( V_10 -> V_233 != V_225 ) {
F_140 ( L_34 ,
V_29 , V_12 , V_10 -> V_233 , V_225 ) ;
goto V_8;
}
break;
}
V_5 = (struct V_4 * ) V_10 -> V_175 ;
if ( V_5 != NULL ) {
V_8 = - V_234 ;
goto V_8;
}
V_5 = F_143 ( sizeof( struct V_4 ) , V_235 ) ;
if ( V_5 == NULL ) {
V_8 = - V_236 ;
goto V_8;
}
V_5 -> V_94 = V_94 ;
V_5 -> V_29 = V_29 ;
V_5 -> V_125 = V_125 ;
V_5 -> V_112 = V_237 ;
V_5 -> V_108 = V_238 ;
sprintf ( & V_5 -> V_38 [ 0 ] , L_35 , V_29 ) ;
F_144 ( & V_5 -> V_22 ) ;
V_5 -> V_1 = V_2 ;
V_16 = F_1 ( V_2 ) ;
if ( V_197 != NULL )
V_5 -> V_112 = V_197 -> V_112 ;
V_5 -> V_127 = V_127 ;
if ( V_127 == V_128 ) {
F_115 ( V_10 ) -> V_178 = V_239 ;
F_115 ( V_10 ) -> V_179 = F_84 ;
F_115 ( V_10 ) -> V_180 = F_126 ;
#if F_53 ( V_61 )
if ( V_10 -> V_62 == V_63 )
F_145 () ;
else
#endif
F_146 () ;
}
V_10 -> V_175 = V_5 ;
V_5 -> V_182 = V_10 -> V_181 ;
V_10 -> V_181 = & F_114 ;
V_5 -> V_7 = V_10 ;
V_5 -> V_12 = V_12 ;
F_147 ( & V_10 -> V_240 . V_241 , & V_242 , L_36 ) ;
V_10 -> V_243 = V_244 ;
F_148 ( & V_5 -> V_194 , F_129 ) ;
F_149 ( & V_5 -> V_184 ) ;
F_5 ( & V_185 ) ;
F_150 ( V_5 ) ;
F_34 ( & V_16 -> V_183 ) ;
F_151 ( & V_5 -> V_184 , & V_16 -> V_245 ) ;
F_41 ( & V_16 -> V_183 ) ;
V_8 = 0 ;
V_8:
if ( V_229 )
* V_229 = V_5 ;
if ( V_7 && V_7 -> V_246 )
F_14 ( V_7 ) ;
return V_8 ;
}
int F_152 ( struct V_4 * V_5 )
{
F_118 ( V_5 ) ;
return ( false == F_153 ( V_247 , & V_5 -> V_194 ) ) ;
}
void F_154 ( struct V_14 * V_19 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
F_2 ( F_127 ( & V_19 -> V_6 ) != 0 ) ;
if ( V_5 ) {
F_2 ( V_5 -> V_108 != V_238 ) ;
if ( V_19 -> V_15 != 0 )
F_117 ( & V_248 ) ;
F_15 ( V_5 -> V_7 ) ;
V_19 -> V_5 = NULL ;
F_119 ( V_5 ) ;
}
F_155 ( V_19 ) ;
return;
}
void F_125 ( struct V_14 * V_19 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
if ( V_5 ) {
F_120 ( & V_5 -> V_22 ) ;
F_123 ( & V_19 -> V_189 ) ;
F_124 ( & V_5 -> V_22 ) ;
if ( V_5 -> V_94 != V_95 ) {
struct V_1 * V_16 = F_1 ( V_5 -> V_1 ) ;
F_34 ( & V_16 -> V_249 ) ;
F_156 ( & V_19 -> V_250 ) ;
F_41 ( & V_16 -> V_249 ) ;
F_157 () ;
}
}
}
int F_158 ( struct V_14 * V_19 )
{
if ( V_19 -> V_89 )
(* V_19 -> V_89 )( V_19 ) ;
F_125 ( V_19 ) ;
F_76 ( V_19 ) ;
if ( V_19 -> V_190 != NULL )
(* V_19 -> V_190 )( V_19 ) ;
if ( V_19 -> V_48 )
(* V_19 -> V_48 )( V_19 ) ;
F_75 ( V_19 ) ;
return 0 ;
}
static void F_71 ( struct V_14 * V_19 , int V_94 )
{
if ( V_94 == V_95 ) {
V_19 -> V_153 = 6 ;
if ( V_19 -> V_104 )
V_19 -> V_153 += 4 ;
} else {
V_19 -> V_153 = 4 + V_19 -> V_130 + V_19 -> V_102 + V_19 -> V_88 ;
if ( V_19 -> V_5 -> V_127 == V_128 )
V_19 -> V_153 += 4 ;
}
}
struct V_14 * F_159 ( int V_251 , struct V_4 * V_5 , T_1 V_15 , T_1 V_126 , struct V_252 * V_197 )
{
struct V_14 * V_19 ;
V_19 = F_143 ( sizeof( struct V_14 ) + V_251 , V_235 ) ;
if ( V_19 != NULL ) {
V_19 -> V_108 = V_109 ;
V_19 -> V_5 = V_5 ;
V_19 -> V_15 = V_15 ;
V_19 -> V_126 = V_126 ;
V_19 -> V_45 = 0 ;
if ( V_5 -> V_94 == V_95 )
V_19 -> V_46 = 0xffff ;
else
V_19 -> V_46 = 0xffffff ;
V_19 -> V_78 = V_19 -> V_46 / 2 ;
V_19 -> V_84 = 4 ;
V_19 -> V_54 = 1 ;
sprintf ( & V_19 -> V_38 [ 0 ] , L_37 ,
V_5 -> V_29 , V_19 -> V_15 ) ;
F_160 ( & V_19 -> V_35 ) ;
F_161 ( & V_19 -> V_189 ) ;
F_161 ( & V_19 -> V_250 ) ;
V_19 -> V_112 = V_5 -> V_112 ;
if ( V_197 ) {
V_19 -> V_253 = V_197 -> V_254 ;
V_19 -> V_112 = V_197 -> V_112 ;
V_19 -> V_255 = V_197 -> V_255 ;
V_19 -> V_256 = V_197 -> V_256 ;
V_19 -> V_104 = V_197 -> V_104 ;
V_19 -> V_105 = V_197 -> V_105 ;
V_19 -> V_103 = V_197 -> V_103 ;
V_19 -> V_80 = V_197 -> V_80 ;
V_19 -> V_88 = V_197 -> V_88 ;
V_19 -> V_98 = V_197 -> V_98 ;
V_19 -> V_102 = V_197 -> V_102 ;
V_19 -> V_130 = V_197 -> V_130 ;
memcpy ( & V_19 -> V_131 [ 0 ] , & V_197 -> V_131 [ 0 ] , V_197 -> V_130 ) ;
V_19 -> V_90 = V_197 -> V_90 ;
memcpy ( & V_19 -> V_91 [ 0 ] , & V_197 -> V_91 [ 0 ] , V_197 -> V_90 ) ;
}
if ( V_5 -> V_94 == V_95 )
V_19 -> V_160 = F_85 ;
else
V_19 -> V_160 = F_87 ;
F_71 ( V_19 , V_5 -> V_94 ) ;
F_68 ( V_19 ) ;
F_150 ( V_5 ) ;
F_11 ( V_5 -> V_7 ) ;
F_120 ( & V_5 -> V_22 ) ;
F_162 ( & V_19 -> V_189 ,
F_21 ( V_5 , V_15 ) ) ;
F_124 ( & V_5 -> V_22 ) ;
if ( V_5 -> V_94 != V_95 ) {
struct V_1 * V_16 = F_1 ( V_5 -> V_1 ) ;
F_34 ( & V_16 -> V_249 ) ;
F_163 ( & V_19 -> V_250 ,
F_17 ( V_16 , V_15 ) ) ;
F_41 ( & V_16 -> V_249 ) ;
}
if ( V_19 -> V_15 != 0 )
F_5 ( & V_248 ) ;
}
return V_19 ;
}
static T_5 int F_164 ( struct V_2 * V_2 )
{
struct V_1 * V_16 = F_3 ( V_2 , V_3 ) ;
int V_24 ;
F_149 ( & V_16 -> V_245 ) ;
F_165 ( & V_16 -> V_183 ) ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ )
F_166 ( & V_16 -> V_257 [ V_24 ] ) ;
F_165 ( & V_16 -> V_249 ) ;
return 0 ;
}
static T_6 void F_167 ( struct V_2 * V_2 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
struct V_4 * V_5 = NULL ;
F_18 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
( void ) F_152 ( V_5 ) ;
}
F_20 () ;
}
static int T_7 F_168 ( void )
{
int V_258 = 0 ;
V_258 = F_169 ( & V_259 ) ;
if ( V_258 )
goto V_11;
V_247 = F_170 ( L_38 , V_260 | V_261 , 0 ) ;
if ( ! V_247 ) {
F_140 ( L_39 ) ;
V_258 = - V_236 ;
goto V_11;
}
F_171 ( L_40 , V_262 ) ;
V_11:
return V_258 ;
}
static void T_8 F_172 ( void )
{
F_173 ( & V_259 ) ;
if ( V_247 ) {
F_174 ( V_247 ) ;
V_247 = NULL ;
}
}
