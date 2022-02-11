static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static inline struct V_5 * F_1 ( const struct V_6 * V_6 )
{
F_2 ( ! V_6 ) ;
return F_3 ( V_6 , V_7 ) ;
}
static inline struct V_8 *
F_4 ( struct V_5 * V_9 , T_1 V_10 )
{
return & V_9 -> V_11 [ F_5 ( V_10 , V_12 ) ] ;
}
static struct V_2 * F_6 ( struct V_1 * V_13 )
{
int V_14 = 0 ;
struct V_15 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
if ( ! V_13 )
goto V_16;
if ( V_13 -> V_17 >= 0 ) {
V_2 = F_7 ( V_13 -> V_17 , & V_14 ) ;
if ( V_2 )
V_3 = V_2 -> V_3 ;
} else {
V_3 = V_13 -> V_2 ;
F_8 ( V_3 ) ;
}
V_16:
return V_3 ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_10 ( V_3 ) ;
if ( V_13 ) {
if ( V_13 -> V_17 >= 0 ) {
F_11 ( V_3 -> V_18 ) ;
}
F_12 ( V_3 ) ;
}
F_12 ( V_3 ) ;
}
static inline struct V_8 *
F_13 ( struct V_1 * V_13 , T_1 V_10 )
{
return & V_13 -> V_19 [ F_5 ( V_10 , V_20 ) ] ;
}
struct V_1 * F_14 ( const struct V_6 * V_6 , T_1 V_21 )
{
const struct V_5 * V_9 = F_1 ( V_6 ) ;
struct V_1 * V_13 ;
F_15 () ;
F_16 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( V_13 -> V_21 == V_21 ) {
F_17 ( V_13 ) ;
F_18 () ;
return V_13 ;
}
}
F_18 () ;
return NULL ;
}
struct V_22 * F_19 ( const struct V_6 * V_6 ,
struct V_1 * V_13 ,
T_1 V_10 , bool V_23 )
{
struct V_8 * V_24 ;
struct V_22 * V_25 ;
if ( ! V_13 ) {
struct V_5 * V_9 = F_1 ( V_6 ) ;
V_24 = F_4 ( V_9 , V_10 ) ;
F_15 () ;
F_20 (session, session_list, global_hlist) {
if ( V_25 -> V_10 == V_10 ) {
F_21 ( V_25 ) ;
if ( V_23 && V_25 -> V_26 )
V_25 -> V_26 ( V_25 ) ;
F_18 () ;
return V_25 ;
}
}
F_18 () ;
return NULL ;
}
V_24 = F_13 ( V_13 , V_10 ) ;
F_22 ( & V_13 -> V_27 ) ;
F_23 (session, session_list, hlist) {
if ( V_25 -> V_10 == V_10 ) {
F_21 ( V_25 ) ;
if ( V_23 && V_25 -> V_26 )
V_25 -> V_26 ( V_25 ) ;
F_24 ( & V_13 -> V_27 ) ;
return V_25 ;
}
}
F_24 ( & V_13 -> V_27 ) ;
return NULL ;
}
struct V_22 * F_25 ( struct V_1 * V_13 , int V_28 ,
bool V_23 )
{
int V_29 ;
struct V_22 * V_25 ;
int V_30 = 0 ;
F_22 ( & V_13 -> V_27 ) ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
F_23 (session, &tunnel->session_hlist[hash], hlist) {
if ( ++ V_30 > V_28 ) {
F_21 ( V_25 ) ;
if ( V_23 && V_25 -> V_26 )
V_25 -> V_26 ( V_25 ) ;
F_24 ( & V_13 -> V_27 ) ;
return V_25 ;
}
}
}
F_24 ( & V_13 -> V_27 ) ;
return NULL ;
}
struct V_22 * F_26 ( const struct V_6 * V_6 ,
const char * V_32 ,
bool V_23 )
{
struct V_5 * V_9 = F_1 ( V_6 ) ;
int V_29 ;
struct V_22 * V_25 ;
F_15 () ;
for ( V_29 = 0 ; V_29 < V_33 ; V_29 ++ ) {
F_20 (session, &pn->l2tp_session_hlist[hash], global_hlist) {
if ( ! strcmp ( V_25 -> V_32 , V_32 ) ) {
F_21 ( V_25 ) ;
if ( V_23 && V_25 -> V_26 )
V_25 -> V_26 ( V_25 ) ;
F_18 () ;
return V_25 ;
}
}
}
F_18 () ;
return NULL ;
}
static int F_27 ( struct V_1 * V_13 ,
struct V_22 * V_25 )
{
struct V_22 * V_34 ;
struct V_8 * V_35 ;
struct V_8 * V_36 ;
struct V_5 * V_9 ;
int V_14 ;
V_36 = F_13 ( V_13 , V_25 -> V_10 ) ;
F_28 ( & V_13 -> V_27 ) ;
if ( ! V_13 -> V_37 ) {
V_14 = - V_38 ;
goto V_39;
}
F_23 (session_walk, head, hlist)
if ( V_34 -> V_10 == V_25 -> V_10 ) {
V_14 = - V_40 ;
goto V_39;
}
if ( V_13 -> V_41 == V_42 ) {
V_9 = F_1 ( V_13 -> V_5 ) ;
V_35 = F_4 ( F_1 ( V_13 -> V_5 ) ,
V_25 -> V_10 ) ;
F_29 ( & V_9 -> V_43 ) ;
F_23 (session_walk, g_head, global_hlist)
if ( V_34 -> V_10 == V_25 -> V_10 ) {
V_14 = - V_40 ;
goto V_44;
}
F_17 ( V_13 ) ;
F_8 ( V_13 -> V_2 ) ;
F_30 ( & V_25 -> V_45 , V_35 ) ;
F_31 ( & V_9 -> V_43 ) ;
} else {
F_17 ( V_13 ) ;
F_8 ( V_13 -> V_2 ) ;
}
F_32 ( & V_25 -> V_46 , V_36 ) ;
F_33 ( & V_13 -> V_27 ) ;
return 0 ;
V_44:
F_31 ( & V_9 -> V_43 ) ;
V_39:
F_33 ( & V_13 -> V_27 ) ;
return V_14 ;
}
struct V_1 * F_34 ( const struct V_6 * V_6 , T_1 V_21 )
{
struct V_1 * V_13 ;
struct V_5 * V_9 = F_1 ( V_6 ) ;
F_15 () ;
F_16 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( V_13 -> V_21 == V_21 ) {
F_18 () ;
return V_13 ;
}
}
F_18 () ;
return NULL ;
}
struct V_1 * F_35 ( const struct V_6 * V_6 , int V_28 )
{
struct V_5 * V_9 = F_1 ( V_6 ) ;
struct V_1 * V_13 ;
int V_30 = 0 ;
F_15 () ;
F_16 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( ++ V_30 > V_28 ) {
F_18 () ;
return V_13 ;
}
}
F_18 () ;
return NULL ;
}
static void F_36 ( struct V_22 * V_25 , struct V_47 * V_48 )
{
struct V_47 * V_49 ;
struct V_47 * V_50 ;
T_1 V_51 = F_37 ( V_48 ) -> V_51 ;
F_29 ( & V_25 -> V_52 . V_53 ) ;
F_38 (&session->reorder_q, skbp, tmp) {
if ( F_37 ( V_49 ) -> V_51 > V_51 ) {
F_39 ( & V_25 -> V_52 , V_49 , V_48 ) ;
F_40 ( V_25 , V_54 ,
L_1 ,
V_25 -> V_55 , V_51 , F_37 ( V_49 ) -> V_51 ,
F_41 ( & V_25 -> V_52 ) ) ;
F_42 ( & V_25 -> V_56 . V_57 ) ;
goto V_16;
}
}
F_43 ( & V_25 -> V_52 , V_48 ) ;
V_16:
F_31 ( & V_25 -> V_52 . V_53 ) ;
}
static void F_44 ( struct V_22 * V_25 , struct V_47 * V_48 )
{
struct V_1 * V_13 = V_25 -> V_13 ;
int V_58 = F_37 ( V_48 ) -> V_58 ;
F_45 ( V_48 ) ;
F_42 ( & V_13 -> V_56 . V_59 ) ;
F_46 ( V_58 , & V_13 -> V_56 . V_60 ) ;
F_42 ( & V_25 -> V_56 . V_59 ) ;
F_46 ( V_58 , & V_25 -> V_56 . V_60 ) ;
if ( F_37 ( V_48 ) -> V_61 ) {
V_25 -> V_62 ++ ;
V_25 -> V_62 &= V_25 -> V_63 ;
F_40 ( V_25 , V_54 , L_2 ,
V_25 -> V_55 , V_25 -> V_62 ) ;
}
if ( V_25 -> V_64 != NULL )
(* V_25 -> V_64 )( V_25 , V_48 , F_37 ( V_48 ) -> V_58 ) ;
else
F_47 ( V_48 ) ;
if ( V_25 -> V_65 )
(* V_25 -> V_65 )( V_25 ) ;
}
static void F_48 ( struct V_22 * V_25 )
{
struct V_47 * V_48 ;
struct V_47 * V_50 ;
V_66:
F_29 ( & V_25 -> V_52 . V_53 ) ;
F_38 (&session->reorder_q, skb, tmp) {
if ( F_49 ( V_67 , F_37 ( V_48 ) -> V_68 ) ) {
F_42 ( & V_25 -> V_56 . V_69 ) ;
F_42 ( & V_25 -> V_56 . V_70 ) ;
F_40 ( V_25 , V_54 ,
L_3 ,
V_25 -> V_55 , F_37 ( V_48 ) -> V_51 ,
F_37 ( V_48 ) -> V_58 , V_25 -> V_62 ,
F_41 ( & V_25 -> V_52 ) ) ;
V_25 -> V_71 = 1 ;
F_50 ( V_48 , & V_25 -> V_52 ) ;
F_47 ( V_48 ) ;
if ( V_25 -> V_65 )
(* V_25 -> V_65 )( V_25 ) ;
continue;
}
if ( F_37 ( V_48 ) -> V_61 ) {
if ( V_25 -> V_71 ) {
F_40 ( V_25 , V_54 ,
L_4 ,
V_25 -> V_55 , V_25 -> V_62 ,
F_37 ( V_48 ) -> V_51 ) ;
V_25 -> V_71 = 0 ;
V_25 -> V_62 = F_37 ( V_48 ) -> V_51 ;
}
if ( F_37 ( V_48 ) -> V_51 != V_25 -> V_62 ) {
F_40 ( V_25 , V_54 ,
L_5 ,
V_25 -> V_55 , F_37 ( V_48 ) -> V_51 ,
F_37 ( V_48 ) -> V_58 , V_25 -> V_62 ,
F_41 ( & V_25 -> V_52 ) ) ;
goto V_16;
}
}
F_50 ( V_48 , & V_25 -> V_52 ) ;
F_31 ( & V_25 -> V_52 . V_53 ) ;
F_44 ( V_25 , V_48 ) ;
goto V_66;
}
V_16:
F_31 ( & V_25 -> V_52 . V_53 ) ;
}
static int F_51 ( struct V_22 * V_25 , T_1 V_62 )
{
T_1 V_72 ;
if ( V_62 >= V_25 -> V_62 )
V_72 = V_62 - V_25 -> V_62 ;
else
V_72 = ( V_25 -> V_63 + 1 ) - ( V_25 -> V_62 - V_62 ) ;
return V_72 < V_25 -> V_73 ;
}
static int F_52 ( struct V_22 * V_25 , struct V_47 * V_48 )
{
if ( ! F_51 ( V_25 , F_37 ( V_48 ) -> V_51 ) ) {
F_40 ( V_25 , V_54 ,
L_6 ,
V_25 -> V_55 , F_37 ( V_48 ) -> V_51 ,
F_37 ( V_48 ) -> V_58 , V_25 -> V_62 ) ;
goto V_74;
}
if ( V_25 -> V_75 != 0 ) {
F_36 ( V_25 , V_48 ) ;
goto V_16;
}
if ( F_37 ( V_48 ) -> V_51 == V_25 -> V_62 ) {
F_53 ( & V_25 -> V_52 , V_48 ) ;
} else {
T_1 V_76 = F_37 ( V_48 ) -> V_51 ;
T_1 V_77 = ( V_25 -> V_76 + 1 ) & V_25 -> V_63 ;
if ( V_76 == V_77 )
V_25 -> V_78 ++ ;
else
V_25 -> V_78 = 0 ;
V_25 -> V_76 = V_76 ;
if ( V_25 -> V_78 > V_25 -> V_79 ) {
V_25 -> V_71 = 1 ;
F_40 ( V_25 , V_54 ,
L_7 ,
V_25 -> V_55 , V_25 -> V_78 ) ;
}
if ( ! V_25 -> V_71 ) {
F_42 ( & V_25 -> V_56 . V_69 ) ;
F_40 ( V_25 , V_54 ,
L_8 ,
V_25 -> V_55 , F_37 ( V_48 ) -> V_51 ,
F_37 ( V_48 ) -> V_58 , V_25 -> V_62 ,
F_41 ( & V_25 -> V_52 ) ) ;
goto V_74;
}
F_53 ( & V_25 -> V_52 , V_48 ) ;
}
V_16:
return 0 ;
V_74:
return 1 ;
}
void F_54 ( struct V_22 * V_25 , struct V_47 * V_48 ,
unsigned char * V_80 , unsigned char * V_81 , T_2 V_82 ,
int V_58 , int (* F_55)( struct V_47 * V_48 ) )
{
struct V_1 * V_13 = V_25 -> V_13 ;
int V_83 ;
T_1 V_51 , V_62 ;
if ( V_25 -> V_84 > 0 ) {
if ( memcmp ( V_80 , & V_25 -> V_85 [ 0 ] , V_25 -> V_84 ) ) {
F_56 ( V_13 , V_86 ,
L_9 ,
V_13 -> V_55 , V_13 -> V_21 ,
V_25 -> V_10 ) ;
F_42 ( & V_25 -> V_56 . V_87 ) ;
goto V_74;
}
V_80 += V_25 -> V_84 ;
}
V_51 = V_62 = 0 ;
F_37 ( V_48 ) -> V_61 = 0 ;
if ( V_13 -> V_41 == V_88 ) {
if ( V_82 & V_89 ) {
V_51 = F_57 ( * ( V_90 * ) V_80 ) ;
V_80 += 2 ;
V_62 = F_57 ( * ( V_90 * ) V_80 ) ;
V_80 += 2 ;
F_37 ( V_48 ) -> V_51 = V_51 ;
F_37 ( V_48 ) -> V_61 = 1 ;
F_40 ( V_25 , V_54 ,
L_10 ,
V_25 -> V_55 , V_51 , V_62 , V_25 -> V_62 ) ;
}
} else if ( V_25 -> V_91 == V_92 ) {
T_1 V_93 = F_58 ( * ( V_94 * ) V_80 ) ;
if ( V_93 & 0x40000000 ) {
V_51 = V_93 & 0x00ffffff ;
F_37 ( V_48 ) -> V_51 = V_51 ;
F_37 ( V_48 ) -> V_61 = 1 ;
F_40 ( V_25 , V_54 ,
L_11 ,
V_25 -> V_55 , V_51 , V_25 -> V_62 ) ;
}
}
V_80 += V_25 -> V_95 ;
if ( F_37 ( V_48 ) -> V_61 ) {
if ( ( ! V_25 -> V_96 ) && ( ! V_25 -> V_97 ) ) {
F_56 ( V_25 , V_54 ,
L_12 ,
V_25 -> V_55 ) ;
V_25 -> V_97 = 1 ;
F_59 ( V_25 , V_13 -> V_41 ) ;
}
} else {
if ( V_25 -> V_98 ) {
F_60 ( V_25 , V_54 ,
L_13 ,
V_25 -> V_55 ) ;
F_42 ( & V_25 -> V_56 . V_69 ) ;
goto V_74;
}
if ( ( ! V_25 -> V_96 ) && ( V_25 -> V_97 ) ) {
F_56 ( V_25 , V_54 ,
L_14 ,
V_25 -> V_55 ) ;
V_25 -> V_97 = 0 ;
F_59 ( V_25 , V_13 -> V_41 ) ;
} else if ( V_25 -> V_97 ) {
F_60 ( V_25 , V_54 ,
L_13 ,
V_25 -> V_55 ) ;
F_42 ( & V_25 -> V_56 . V_69 ) ;
goto V_74;
}
}
if ( V_13 -> V_41 == V_88 ) {
if ( V_82 & V_99 ) {
V_83 = F_57 ( * ( V_90 * ) V_80 ) ;
V_80 += 2 + V_83 ;
}
} else
V_80 += V_25 -> V_83 ;
V_83 = V_80 - V_81 ;
if ( ! F_61 ( V_48 , V_83 ) )
goto V_74;
F_62 ( V_48 , V_83 ) ;
if ( F_55 )
if ( (* F_55)( V_48 ) )
goto V_74;
F_37 ( V_48 ) -> V_58 = V_58 ;
F_37 ( V_48 ) -> V_68 = V_67 +
( V_25 -> V_75 ? V_25 -> V_75 : V_100 ) ;
if ( F_37 ( V_48 ) -> V_61 ) {
if ( F_52 ( V_25 , V_48 ) )
goto V_74;
} else {
F_53 ( & V_25 -> V_52 , V_48 ) ;
}
F_48 ( V_25 ) ;
return;
V_74:
F_42 ( & V_25 -> V_56 . V_70 ) ;
F_47 ( V_48 ) ;
if ( V_25 -> V_65 )
(* V_25 -> V_65 )( V_25 ) ;
}
int F_63 ( struct V_22 * V_25 )
{
struct V_47 * V_48 = NULL ;
F_2 ( ! V_25 ) ;
F_2 ( V_25 -> V_101 != V_102 ) ;
while ( ( V_48 = F_64 ( & V_25 -> V_52 ) ) ) {
F_42 ( & V_25 -> V_56 . V_70 ) ;
F_47 ( V_48 ) ;
if ( V_25 -> V_65 )
(* V_25 -> V_65 )( V_25 ) ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_13 , struct V_47 * V_48 ,
int (* F_55)( struct V_47 * V_48 ) )
{
struct V_22 * V_25 = NULL ;
unsigned char * V_80 , * V_81 ;
T_2 V_82 ;
T_1 V_21 , V_10 ;
T_2 V_41 ;
int V_58 ;
F_62 ( V_48 , sizeof( struct V_103 ) ) ;
if ( ! F_61 ( V_48 , V_104 ) ) {
F_56 ( V_13 , V_86 ,
L_15 ,
V_13 -> V_55 , V_48 -> V_105 ) ;
goto error;
}
if ( V_13 -> V_106 & V_86 ) {
V_58 = F_66 ( 32u , V_48 -> V_105 ) ;
if ( ! F_61 ( V_48 , V_58 ) )
goto error;
F_67 ( L_16 , V_13 -> V_55 ) ;
F_68 ( L_17 , V_107 , V_48 -> V_108 , V_58 ) ;
}
V_81 = V_80 = V_48 -> V_108 ;
V_82 = F_57 ( * ( V_90 * ) V_80 ) ;
V_41 = V_82 & V_109 ;
if ( V_41 != V_13 -> V_41 ) {
F_56 ( V_13 , V_86 ,
L_18 ,
V_13 -> V_55 , V_41 , V_13 -> V_41 ) ;
goto error;
}
V_58 = V_48 -> V_105 ;
if ( V_82 & V_110 ) {
F_40 ( V_13 , V_86 ,
L_19 ,
V_13 -> V_55 , V_58 ) ;
goto error;
}
V_80 += 2 ;
if ( V_13 -> V_41 == V_88 ) {
if ( V_82 & V_111 )
V_80 += 2 ;
V_21 = F_57 ( * ( V_90 * ) V_80 ) ;
V_80 += 2 ;
V_10 = F_57 ( * ( V_90 * ) V_80 ) ;
V_80 += 2 ;
} else {
V_80 += 2 ;
V_21 = V_13 -> V_21 ;
V_10 = F_58 ( * ( V_94 * ) V_80 ) ;
V_80 += 4 ;
}
V_25 = F_19 ( V_13 -> V_5 , V_13 , V_10 , true ) ;
if ( ! V_25 || ! V_25 -> V_64 ) {
if ( V_25 ) {
if ( V_25 -> V_65 )
V_25 -> V_65 ( V_25 ) ;
F_69 ( V_25 ) ;
}
F_56 ( V_13 , V_86 ,
L_20 ,
V_13 -> V_55 , V_21 , V_10 ) ;
goto error;
}
F_54 ( V_25 , V_48 , V_80 , V_81 , V_82 , V_58 , F_55 ) ;
F_69 ( V_25 ) ;
return 0 ;
error:
F_70 ( V_48 , sizeof( struct V_103 ) ) ;
return 1 ;
}
int F_71 ( struct V_2 * V_3 , struct V_47 * V_48 )
{
struct V_1 * V_13 ;
V_13 = F_10 ( V_3 ) ;
if ( V_13 == NULL )
goto V_112;
F_40 ( V_13 , V_86 , L_21 ,
V_13 -> V_55 , V_48 -> V_105 ) ;
if ( F_65 ( V_13 , V_48 , V_13 -> V_113 ) )
goto V_114;
F_12 ( V_3 ) ;
return 0 ;
V_114:
F_12 ( V_3 ) ;
V_112:
return 1 ;
}
static int F_72 ( struct V_22 * V_25 , void * V_115 )
{
struct V_1 * V_13 = V_25 -> V_13 ;
V_90 * V_116 = V_115 ;
V_90 * V_81 = V_115 ;
T_2 V_117 = V_88 ;
T_1 V_21 = V_13 -> V_118 ;
T_1 V_10 = V_25 -> V_119 ;
if ( V_25 -> V_97 )
V_117 |= V_89 ;
* V_116 ++ = F_73 ( V_117 ) ;
* V_116 ++ = F_73 ( V_21 ) ;
* V_116 ++ = F_73 ( V_10 ) ;
if ( V_25 -> V_97 ) {
* V_116 ++ = F_73 ( V_25 -> V_51 ) ;
* V_116 ++ = 0 ;
V_25 -> V_51 ++ ;
V_25 -> V_51 &= 0xffff ;
F_40 ( V_25 , V_54 , L_22 ,
V_25 -> V_55 , V_25 -> V_51 ) ;
}
return V_116 - V_81 ;
}
static int F_74 ( struct V_22 * V_25 , void * V_115 )
{
struct V_1 * V_13 = V_25 -> V_13 ;
char * V_116 = V_115 ;
char * V_81 = V_116 ;
if ( V_13 -> V_120 == V_121 ) {
T_2 V_117 = V_42 ;
* ( ( V_90 * ) V_116 ) = F_73 ( V_117 ) ;
V_116 += 2 ;
* ( ( V_90 * ) V_116 ) = 0 ;
V_116 += 2 ;
}
* ( ( V_94 * ) V_116 ) = F_75 ( V_25 -> V_119 ) ;
V_116 += 4 ;
if ( V_25 -> V_122 ) {
memcpy ( V_116 , & V_25 -> V_123 [ 0 ] , V_25 -> V_122 ) ;
V_116 += V_25 -> V_122 ;
}
if ( V_25 -> V_95 ) {
if ( V_25 -> V_91 == V_92 ) {
T_1 V_93 = 0 ;
if ( V_25 -> V_97 ) {
V_93 = 0x40000000 | V_25 -> V_51 ;
V_25 -> V_51 ++ ;
V_25 -> V_51 &= 0xffffff ;
F_40 ( V_25 , V_54 ,
L_22 ,
V_25 -> V_55 , V_25 -> V_51 ) ;
}
* ( ( V_94 * ) V_116 ) = F_75 ( V_93 ) ;
}
V_116 += V_25 -> V_95 ;
}
if ( V_25 -> V_83 )
V_116 += V_25 -> V_83 ;
return V_116 - V_81 ;
}
static int F_76 ( struct V_22 * V_25 , struct V_47 * V_48 ,
struct V_124 * V_125 , T_3 V_126 )
{
struct V_1 * V_13 = V_25 -> V_13 ;
unsigned int V_105 = V_48 -> V_105 ;
int error ;
if ( V_25 -> V_97 )
F_40 ( V_25 , V_86 , L_23 ,
V_25 -> V_55 , V_126 , V_25 -> V_51 - 1 ) ;
else
F_40 ( V_25 , V_86 , L_24 ,
V_25 -> V_55 , V_126 ) ;
if ( V_25 -> V_106 & V_86 ) {
int V_127 = ( V_13 -> V_120 == V_121 ) ? sizeof( struct V_103 ) : 0 ;
unsigned char * V_128 = V_48 -> V_108 + V_127 ;
F_67 ( L_25 , V_25 -> V_55 ) ;
F_68 ( L_17 , V_107 ,
V_128 , F_77 ( T_3 , 32 , V_105 - V_127 ) ) ;
}
V_48 -> V_129 = 1 ;
#if F_78 ( V_130 )
if ( V_13 -> V_2 -> V_131 == V_132 && ! V_13 -> V_133 )
error = F_79 ( V_13 -> V_2 , V_48 , NULL ) ;
else
#endif
error = F_80 ( V_13 -> V_2 , V_48 , V_125 ) ;
if ( error >= 0 ) {
F_42 ( & V_13 -> V_56 . V_134 ) ;
F_46 ( V_105 , & V_13 -> V_56 . V_135 ) ;
F_42 ( & V_25 -> V_56 . V_134 ) ;
F_46 ( V_105 , & V_25 -> V_56 . V_135 ) ;
} else {
F_42 ( & V_13 -> V_56 . V_136 ) ;
F_42 ( & V_25 -> V_56 . V_136 ) ;
}
return 0 ;
}
int F_81 ( struct V_22 * V_25 , struct V_47 * V_48 , int V_137 )
{
int V_126 = V_48 -> V_105 ;
struct V_1 * V_13 = V_25 -> V_13 ;
struct V_2 * V_3 = V_13 -> V_2 ;
struct V_124 * V_125 ;
struct V_103 * V_138 ;
struct V_139 * V_140 ;
int V_141 ;
int V_127 = ( V_13 -> V_120 == V_121 ) ? sizeof( struct V_103 ) : 0 ;
int V_142 ;
int V_143 = V_144 ;
V_141 = V_145 + sizeof( struct V_146 ) +
V_127 + V_137 ;
if ( F_82 ( V_48 , V_141 ) ) {
F_47 ( V_48 ) ;
return V_147 ;
}
V_25 -> V_148 ( V_25 , F_70 ( V_48 , V_137 ) ) ;
memset ( & ( F_83 ( V_48 ) -> V_149 ) , 0 , sizeof( F_83 ( V_48 ) -> V_149 ) ) ;
F_83 ( V_48 ) -> V_117 &= ~ ( V_150 | V_151 |
V_152 ) ;
F_84 ( V_48 ) ;
F_85 ( V_3 ) ;
if ( F_86 ( V_3 ) ) {
F_47 ( V_48 ) ;
V_143 = V_147 ;
goto V_153;
}
F_87 ( V_48 ) ;
F_88 ( V_48 , F_89 ( F_90 ( V_3 , 0 ) ) ) ;
V_140 = F_91 ( V_3 ) ;
V_125 = & V_140 -> V_154 . V_125 ;
switch ( V_13 -> V_120 ) {
case V_121 :
F_70 ( V_48 , sizeof( * V_138 ) ) ;
F_92 ( V_48 ) ;
V_138 = F_93 ( V_48 ) ;
V_138 -> V_155 = V_140 -> V_156 ;
V_138 -> V_157 = V_140 -> V_158 ;
V_142 = V_127 + V_137 + V_126 ;
V_138 -> V_105 = F_73 ( V_142 ) ;
#if F_78 ( V_130 )
if ( V_3 -> V_131 == V_132 && ! V_13 -> V_133 )
F_94 ( F_95 ( V_3 ) ,
V_48 , & F_96 ( V_3 ) -> V_159 ,
& V_3 -> V_160 , V_142 ) ;
else
#endif
F_97 ( V_3 -> V_161 , V_48 , V_140 -> V_162 ,
V_140 -> V_163 , V_142 ) ;
break;
case V_164 :
break;
}
F_76 ( V_25 , V_48 , V_125 , V_126 ) ;
V_153:
F_98 ( V_3 ) ;
return V_143 ;
}
static void F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = V_1 ( V_3 ) ;
struct V_5 * V_9 ;
if ( V_13 == NULL )
goto V_165;
F_56 ( V_13 , V_166 , L_26 , V_13 -> V_55 ) ;
switch ( V_13 -> V_120 ) {
case V_121 :
( F_100 ( V_3 ) ) -> V_167 = 0 ;
( F_100 ( V_3 ) ) -> V_168 = NULL ;
( F_100 ( V_3 ) ) -> V_169 = NULL ;
break;
case V_164 :
break;
}
V_3 -> V_170 = V_13 -> V_171 ;
V_3 -> V_4 = NULL ;
V_9 = F_1 ( V_13 -> V_5 ) ;
F_29 ( & V_9 -> V_172 ) ;
F_101 ( & V_13 -> V_173 ) ;
F_31 ( & V_9 -> V_172 ) ;
F_102 ( & V_174 ) ;
F_103 ( V_13 ) ;
V_13 -> V_2 = NULL ;
F_104 ( V_13 ) ;
if ( V_3 -> V_170 )
(* V_3 -> V_170 )( V_3 ) ;
V_165:
return;
}
void F_103 ( struct V_1 * V_13 )
{
int V_29 ;
struct V_175 * V_176 ;
struct V_175 * V_50 ;
struct V_22 * V_25 ;
F_2 ( V_13 == NULL ) ;
F_56 ( V_13 , V_166 , L_27 ,
V_13 -> V_55 ) ;
F_28 ( & V_13 -> V_27 ) ;
V_13 -> V_37 = false ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
V_177:
F_105 (walk, tmp, &tunnel->session_hlist[hash]) {
V_25 = F_106 ( V_176 , struct V_22 , V_46 ) ;
F_56 ( V_25 , V_166 ,
L_28 , V_25 -> V_55 ) ;
F_107 ( & V_25 -> V_46 ) ;
if ( F_108 ( 0 , & V_25 -> V_178 ) )
goto V_177;
if ( V_25 -> V_26 != NULL )
(* V_25 -> V_26 )( V_25 ) ;
F_33 ( & V_13 -> V_27 ) ;
F_109 ( V_25 ) ;
F_63 ( V_25 ) ;
if ( V_25 -> V_179 != NULL )
(* V_25 -> V_179 )( V_25 ) ;
if ( V_25 -> V_65 != NULL )
(* V_25 -> V_65 )( V_25 ) ;
F_69 ( V_25 ) ;
F_28 ( & V_13 -> V_27 ) ;
goto V_177;
}
}
F_33 ( & V_13 -> V_27 ) ;
}
static void F_110 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_10 ( V_3 ) ;
if ( V_13 ) {
F_103 ( V_13 ) ;
F_12 ( V_3 ) ;
}
}
static void F_111 ( struct V_180 * V_181 )
{
struct V_1 * V_13 = NULL ;
struct V_15 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
V_13 = F_112 ( V_181 , struct V_1 , V_182 ) ;
F_103 ( V_13 ) ;
V_3 = F_6 ( V_13 ) ;
if ( ! V_3 )
goto V_16;
V_2 = V_3 -> V_18 ;
if ( V_13 -> V_17 >= 0 ) {
if ( V_2 )
F_113 ( V_2 , 2 ) ;
} else {
if ( V_2 ) {
F_114 ( V_2 , V_183 ) ;
F_115 ( V_2 ) ;
}
}
F_9 ( V_3 ) ;
V_16:
F_104 ( V_13 ) ;
}
static int F_116 ( struct V_6 * V_6 ,
T_1 V_21 ,
T_1 V_118 ,
struct V_184 * V_185 ,
struct V_15 * * V_186 )
{
int V_14 = - V_187 ;
struct V_15 * V_2 = NULL ;
struct V_188 V_189 ;
switch ( V_185 -> V_120 ) {
case V_121 :
memset ( & V_189 , 0 , sizeof( V_189 ) ) ;
#if F_78 ( V_130 )
if ( V_185 -> V_190 && V_185 -> V_191 ) {
V_189 . V_192 = V_193 ;
memcpy ( & V_189 . V_190 , V_185 -> V_190 ,
sizeof( V_189 . V_190 ) ) ;
memcpy ( & V_189 . V_191 , V_185 -> V_191 ,
sizeof( V_189 . V_191 ) ) ;
V_189 . V_194 =
! V_185 -> V_195 ;
V_189 . V_196 =
! V_185 -> V_197 ;
} else
#endif
{
V_189 . V_192 = V_198 ;
V_189 . V_199 = V_185 -> V_199 ;
V_189 . V_200 = V_185 -> V_200 ;
V_189 . V_201 = V_185 -> V_201 ;
}
V_189 . V_202 = F_73 ( V_185 -> V_202 ) ;
V_189 . V_203 = F_73 ( V_185 -> V_203 ) ;
V_14 = F_117 ( V_6 , & V_189 , & V_2 ) ;
if ( V_14 < 0 )
goto V_16;
break;
case V_164 :
#if F_78 ( V_130 )
if ( V_185 -> V_190 && V_185 -> V_191 ) {
struct V_204 V_205 = { 0 } ;
V_14 = F_118 ( V_6 , V_193 , V_206 ,
V_207 , & V_2 ) ;
if ( V_14 < 0 )
goto V_16;
V_205 . V_208 = V_193 ;
memcpy ( & V_205 . V_209 , V_185 -> V_190 ,
sizeof( V_205 . V_209 ) ) ;
V_205 . V_210 = V_21 ;
V_14 = F_119 ( V_2 , (struct V_211 * ) & V_205 ,
sizeof( V_205 ) ) ;
if ( V_14 < 0 )
goto V_16;
V_205 . V_208 = V_193 ;
memcpy ( & V_205 . V_209 , V_185 -> V_191 ,
sizeof( V_205 . V_209 ) ) ;
V_205 . V_210 = V_118 ;
V_14 = F_120 ( V_2 ,
(struct V_211 * ) & V_205 ,
sizeof( V_205 ) , 0 ) ;
if ( V_14 < 0 )
goto V_16;
} else
#endif
{
struct V_212 V_213 = { 0 } ;
V_14 = F_118 ( V_6 , V_198 , V_206 ,
V_207 , & V_2 ) ;
if ( V_14 < 0 )
goto V_16;
V_213 . V_208 = V_198 ;
V_213 . V_209 = V_185 -> V_199 ;
V_213 . V_210 = V_21 ;
V_14 = F_119 ( V_2 , (struct V_211 * ) & V_213 ,
sizeof( V_213 ) ) ;
if ( V_14 < 0 )
goto V_16;
V_213 . V_208 = V_198 ;
V_213 . V_209 = V_185 -> V_200 ;
V_213 . V_210 = V_118 ;
V_14 = F_120 ( V_2 , (struct V_211 * ) & V_213 ,
sizeof( V_213 ) , 0 ) ;
if ( V_14 < 0 )
goto V_16;
}
break;
default:
goto V_16;
}
V_16:
* V_186 = V_2 ;
if ( ( V_14 < 0 ) && V_2 ) {
F_114 ( V_2 , V_183 ) ;
F_115 ( V_2 ) ;
* V_186 = NULL ;
}
return V_14 ;
}
int F_121 ( struct V_6 * V_6 , int V_17 , int V_41 , T_1 V_21 , T_1 V_118 , struct V_184 * V_185 , struct V_1 * * V_214 )
{
struct V_1 * V_13 = NULL ;
int V_14 ;
struct V_15 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
struct V_5 * V_9 ;
enum V_215 V_120 = V_121 ;
if ( V_17 < 0 ) {
V_14 = F_116 ( V_6 , V_21 , V_118 ,
V_185 , & V_2 ) ;
if ( V_14 < 0 )
goto V_14;
} else {
V_2 = F_7 ( V_17 , & V_14 ) ;
if ( ! V_2 ) {
F_122 ( L_29 ,
V_21 , V_17 , V_14 ) ;
V_14 = - V_216 ;
goto V_14;
}
if ( ! F_123 ( F_124 ( V_2 -> V_3 ) , V_6 ) ) {
F_122 ( L_30 , V_21 ) ;
V_14 = - V_187 ;
goto V_14;
}
}
V_3 = V_2 -> V_3 ;
if ( V_185 != NULL )
V_120 = V_185 -> V_120 ;
switch ( V_120 ) {
case V_121 :
V_14 = - V_217 ;
if ( V_3 -> V_218 != V_219 ) {
F_122 ( L_31 ,
V_21 , V_17 , V_3 -> V_218 , V_219 ) ;
goto V_14;
}
break;
case V_164 :
V_14 = - V_217 ;
if ( V_3 -> V_218 != V_207 ) {
F_122 ( L_31 ,
V_21 , V_17 , V_3 -> V_218 , V_207 ) ;
goto V_14;
}
break;
}
V_13 = V_1 ( V_3 ) ;
if ( V_13 != NULL ) {
V_14 = - V_220 ;
goto V_14;
}
V_13 = F_125 ( sizeof( struct V_1 ) , V_221 ) ;
if ( V_13 == NULL ) {
V_14 = - V_222 ;
goto V_14;
}
V_13 -> V_41 = V_41 ;
V_13 -> V_21 = V_21 ;
V_13 -> V_118 = V_118 ;
V_13 -> V_106 = V_223 ;
V_13 -> V_101 = V_224 ;
sprintf ( & V_13 -> V_55 [ 0 ] , L_32 , V_21 ) ;
F_126 ( & V_13 -> V_27 ) ;
V_13 -> V_37 = true ;
V_13 -> V_5 = V_6 ;
V_9 = F_1 ( V_6 ) ;
if ( V_185 != NULL )
V_13 -> V_106 = V_185 -> V_106 ;
#if F_78 ( V_130 )
if ( V_3 -> V_131 == V_132 ) {
struct V_225 * V_226 = F_96 ( V_3 ) ;
if ( F_127 ( & V_226 -> V_159 ) &&
F_127 ( & V_3 -> V_160 ) ) {
struct V_139 * V_140 = F_91 ( V_3 ) ;
V_13 -> V_133 = true ;
V_140 -> V_162 = V_226 -> V_159 . V_227 [ 3 ] ;
V_140 -> V_228 = V_3 -> V_229 . V_227 [ 3 ] ;
V_140 -> V_163 = V_3 -> V_160 . V_227 [ 3 ] ;
} else {
V_13 -> V_133 = false ;
}
}
#endif
V_13 -> V_120 = V_120 ;
if ( V_120 == V_121 ) {
struct V_230 V_231 = { } ;
V_231 . V_4 = V_13 ;
V_231 . V_167 = V_232 ;
V_231 . V_168 = F_71 ;
V_231 . V_169 = F_110 ;
F_128 ( V_6 , V_2 , & V_231 ) ;
} else {
V_3 -> V_4 = V_13 ;
}
V_13 -> V_171 = V_3 -> V_170 ;
V_3 -> V_170 = & F_99 ;
V_13 -> V_2 = V_3 ;
V_13 -> V_17 = V_17 ;
F_129 ( & V_3 -> V_233 . V_234 , & V_235 , L_33 ) ;
V_3 -> V_236 = V_237 ;
F_130 ( & V_13 -> V_182 , F_111 ) ;
F_131 ( & V_13 -> V_173 ) ;
F_132 ( & V_174 ) ;
F_133 ( & V_13 -> V_238 , 1 ) ;
F_29 ( & V_9 -> V_172 ) ;
F_134 ( & V_13 -> V_173 , & V_9 -> V_239 ) ;
F_31 ( & V_9 -> V_172 ) ;
V_14 = 0 ;
V_14:
if ( V_214 )
* V_214 = V_13 ;
if ( V_2 && V_2 -> V_240 )
F_11 ( V_2 ) ;
return V_14 ;
}
void F_135 ( struct V_1 * V_13 )
{
if ( ! F_108 ( 0 , & V_13 -> V_178 ) ) {
F_17 ( V_13 ) ;
F_136 ( V_241 , & V_13 -> V_182 ) ;
}
}
void F_137 ( struct V_22 * V_25 )
{
struct V_1 * V_13 = V_25 -> V_13 ;
F_2 ( F_138 ( & V_25 -> V_238 ) != 0 ) ;
if ( V_13 ) {
F_2 ( V_13 -> V_101 != V_224 ) ;
if ( V_25 -> V_10 != 0 )
F_102 ( & V_242 ) ;
F_12 ( V_13 -> V_2 ) ;
V_25 -> V_13 = NULL ;
F_104 ( V_13 ) ;
}
F_139 ( V_25 ) ;
}
void F_109 ( struct V_22 * V_25 )
{
struct V_1 * V_13 = V_25 -> V_13 ;
if ( V_13 ) {
F_28 ( & V_13 -> V_27 ) ;
F_107 ( & V_25 -> V_46 ) ;
F_33 ( & V_13 -> V_27 ) ;
if ( V_13 -> V_41 != V_88 ) {
struct V_5 * V_9 = F_1 ( V_13 -> V_5 ) ;
F_29 ( & V_9 -> V_43 ) ;
F_140 ( & V_25 -> V_45 ) ;
F_31 ( & V_9 -> V_43 ) ;
F_141 () ;
}
}
}
int F_142 ( struct V_22 * V_25 )
{
if ( F_108 ( 0 , & V_25 -> V_178 ) )
return 0 ;
if ( V_25 -> V_26 )
(* V_25 -> V_26 )( V_25 ) ;
F_109 ( V_25 ) ;
F_63 ( V_25 ) ;
if ( V_25 -> V_179 != NULL )
(* V_25 -> V_179 )( V_25 ) ;
if ( V_25 -> V_65 )
(* V_25 -> V_65 )( V_25 ) ;
F_69 ( V_25 ) ;
return 0 ;
}
void F_59 ( struct V_22 * V_25 , int V_41 )
{
if ( V_41 == V_88 ) {
V_25 -> V_137 = 6 ;
if ( V_25 -> V_97 )
V_25 -> V_137 += 4 ;
} else {
V_25 -> V_137 = 4 + V_25 -> V_122 + V_25 -> V_95 + V_25 -> V_83 ;
if ( V_25 -> V_13 -> V_120 == V_121 )
V_25 -> V_137 += 4 ;
}
}
struct V_22 * F_143 ( int V_243 , struct V_1 * V_13 , T_1 V_10 , T_1 V_119 , struct V_244 * V_185 )
{
struct V_22 * V_25 ;
int V_14 ;
V_25 = F_125 ( sizeof( struct V_22 ) + V_243 , V_221 ) ;
if ( V_25 != NULL ) {
V_25 -> V_101 = V_102 ;
V_25 -> V_13 = V_13 ;
V_25 -> V_10 = V_10 ;
V_25 -> V_119 = V_119 ;
V_25 -> V_62 = 0 ;
if ( V_13 -> V_41 == V_88 )
V_25 -> V_63 = 0xffff ;
else
V_25 -> V_63 = 0xffffff ;
V_25 -> V_73 = V_25 -> V_63 / 2 ;
V_25 -> V_79 = 4 ;
V_25 -> V_71 = 1 ;
sprintf ( & V_25 -> V_55 [ 0 ] , L_34 ,
V_13 -> V_21 , V_25 -> V_10 ) ;
F_144 ( & V_25 -> V_52 ) ;
F_145 ( & V_25 -> V_46 ) ;
F_145 ( & V_25 -> V_45 ) ;
V_25 -> V_106 = V_13 -> V_106 ;
if ( V_185 ) {
V_25 -> V_245 = V_185 -> V_246 ;
V_25 -> V_106 = V_185 -> V_106 ;
V_25 -> V_247 = V_185 -> V_247 ;
V_25 -> V_248 = V_185 -> V_248 ;
V_25 -> V_97 = V_185 -> V_97 ;
V_25 -> V_98 = V_185 -> V_98 ;
V_25 -> V_96 = V_185 -> V_96 ;
V_25 -> V_75 = V_185 -> V_75 ;
V_25 -> V_83 = V_185 -> V_83 ;
V_25 -> V_91 = V_185 -> V_91 ;
V_25 -> V_95 = V_185 -> V_95 ;
V_25 -> V_122 = V_185 -> V_122 ;
memcpy ( & V_25 -> V_123 [ 0 ] , & V_185 -> V_123 [ 0 ] , V_185 -> V_122 ) ;
V_25 -> V_84 = V_185 -> V_84 ;
memcpy ( & V_25 -> V_85 [ 0 ] , & V_185 -> V_85 [ 0 ] , V_185 -> V_84 ) ;
}
if ( V_13 -> V_41 == V_88 )
V_25 -> V_148 = F_72 ;
else
V_25 -> V_148 = F_74 ;
F_59 ( V_25 , V_13 -> V_41 ) ;
F_133 ( & V_25 -> V_238 , 1 ) ;
V_14 = F_27 ( V_13 , V_25 ) ;
if ( V_14 ) {
F_139 ( V_25 ) ;
return F_146 ( V_14 ) ;
}
if ( V_25 -> V_10 != 0 )
F_132 ( & V_242 ) ;
return V_25 ;
}
return F_146 ( - V_222 ) ;
}
static T_4 int F_147 ( struct V_6 * V_6 )
{
struct V_5 * V_9 = F_3 ( V_6 , V_7 ) ;
int V_29 ;
F_131 ( & V_9 -> V_239 ) ;
F_148 ( & V_9 -> V_172 ) ;
for ( V_29 = 0 ; V_29 < V_33 ; V_29 ++ )
F_149 ( & V_9 -> V_11 [ V_29 ] ) ;
F_148 ( & V_9 -> V_43 ) ;
return 0 ;
}
static T_5 void F_150 ( struct V_6 * V_6 )
{
struct V_5 * V_9 = F_1 ( V_6 ) ;
struct V_1 * V_13 = NULL ;
F_15 () ;
F_16 (tunnel, &pn->l2tp_tunnel_list, list) {
( void ) F_135 ( V_13 ) ;
}
F_18 () ;
F_151 ( V_241 ) ;
F_152 () ;
}
static int T_6 F_153 ( void )
{
int V_249 = 0 ;
V_249 = F_154 ( & V_250 ) ;
if ( V_249 )
goto V_16;
V_241 = F_155 ( L_35 , V_251 , 0 ) ;
if ( ! V_241 ) {
F_122 ( L_36 ) ;
F_156 ( & V_250 ) ;
V_249 = - V_222 ;
goto V_16;
}
F_157 ( L_37 , V_252 ) ;
V_16:
return V_249 ;
}
static void T_7 F_158 ( void )
{
F_156 ( & V_250 ) ;
if ( V_241 ) {
F_159 ( V_241 ) ;
V_241 = NULL ;
}
}
