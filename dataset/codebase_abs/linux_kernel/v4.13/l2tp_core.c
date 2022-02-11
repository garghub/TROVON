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
V_36 = F_13 ( V_13 , V_25 -> V_10 ) ;
F_28 ( & V_13 -> V_27 ) ;
F_23 (session_walk, head, hlist)
if ( V_34 -> V_10 == V_25 -> V_10 )
goto V_37;
if ( V_13 -> V_38 == V_39 ) {
V_9 = F_1 ( V_13 -> V_5 ) ;
V_35 = F_4 ( F_1 ( V_13 -> V_5 ) ,
V_25 -> V_10 ) ;
F_29 ( & V_9 -> V_40 ) ;
F_23 (session_walk, g_head, global_hlist)
if ( V_34 -> V_10 == V_25 -> V_10 )
goto V_41;
F_30 ( & V_25 -> V_42 , V_35 ) ;
F_31 ( & V_9 -> V_40 ) ;
}
F_32 ( & V_25 -> V_43 , V_36 ) ;
F_33 ( & V_13 -> V_27 ) ;
return 0 ;
V_41:
F_31 ( & V_9 -> V_40 ) ;
V_37:
F_33 ( & V_13 -> V_27 ) ;
return - V_44 ;
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
static void F_36 ( struct V_22 * V_25 , struct V_45 * V_46 )
{
struct V_45 * V_47 ;
struct V_45 * V_48 ;
T_1 V_49 = F_37 ( V_46 ) -> V_49 ;
F_29 ( & V_25 -> V_50 . V_51 ) ;
F_38 (&session->reorder_q, skbp, tmp) {
if ( F_37 ( V_47 ) -> V_49 > V_49 ) {
F_39 ( & V_25 -> V_50 , V_47 , V_46 ) ;
F_40 ( V_25 , V_52 ,
L_1 ,
V_25 -> V_53 , V_49 , F_37 ( V_47 ) -> V_49 ,
F_41 ( & V_25 -> V_50 ) ) ;
F_42 ( & V_25 -> V_54 . V_55 ) ;
goto V_16;
}
}
F_43 ( & V_25 -> V_50 , V_46 ) ;
V_16:
F_31 ( & V_25 -> V_50 . V_51 ) ;
}
static void F_44 ( struct V_22 * V_25 , struct V_45 * V_46 )
{
struct V_1 * V_13 = V_25 -> V_13 ;
int V_56 = F_37 ( V_46 ) -> V_56 ;
F_45 ( V_46 ) ;
F_42 ( & V_13 -> V_54 . V_57 ) ;
F_46 ( V_56 , & V_13 -> V_54 . V_58 ) ;
F_42 ( & V_25 -> V_54 . V_57 ) ;
F_46 ( V_56 , & V_25 -> V_54 . V_58 ) ;
if ( F_37 ( V_46 ) -> V_59 ) {
V_25 -> V_60 ++ ;
V_25 -> V_60 &= V_25 -> V_61 ;
F_40 ( V_25 , V_52 , L_2 ,
V_25 -> V_53 , V_25 -> V_60 ) ;
}
if ( V_25 -> V_62 != NULL )
(* V_25 -> V_62 )( V_25 , V_46 , F_37 ( V_46 ) -> V_56 ) ;
else
F_47 ( V_46 ) ;
if ( V_25 -> V_63 )
(* V_25 -> V_63 )( V_25 ) ;
}
static void F_48 ( struct V_22 * V_25 )
{
struct V_45 * V_46 ;
struct V_45 * V_48 ;
V_64:
F_29 ( & V_25 -> V_50 . V_51 ) ;
F_38 (&session->reorder_q, skb, tmp) {
if ( F_49 ( V_65 , F_37 ( V_46 ) -> V_66 ) ) {
F_42 ( & V_25 -> V_54 . V_67 ) ;
F_42 ( & V_25 -> V_54 . V_68 ) ;
F_40 ( V_25 , V_52 ,
L_3 ,
V_25 -> V_53 , F_37 ( V_46 ) -> V_49 ,
F_37 ( V_46 ) -> V_56 , V_25 -> V_60 ,
F_41 ( & V_25 -> V_50 ) ) ;
V_25 -> V_69 = 1 ;
F_50 ( V_46 , & V_25 -> V_50 ) ;
F_47 ( V_46 ) ;
if ( V_25 -> V_63 )
(* V_25 -> V_63 )( V_25 ) ;
continue;
}
if ( F_37 ( V_46 ) -> V_59 ) {
if ( V_25 -> V_69 ) {
F_40 ( V_25 , V_52 ,
L_4 ,
V_25 -> V_53 , V_25 -> V_60 ,
F_37 ( V_46 ) -> V_49 ) ;
V_25 -> V_69 = 0 ;
V_25 -> V_60 = F_37 ( V_46 ) -> V_49 ;
}
if ( F_37 ( V_46 ) -> V_49 != V_25 -> V_60 ) {
F_40 ( V_25 , V_52 ,
L_5 ,
V_25 -> V_53 , F_37 ( V_46 ) -> V_49 ,
F_37 ( V_46 ) -> V_56 , V_25 -> V_60 ,
F_41 ( & V_25 -> V_50 ) ) ;
goto V_16;
}
}
F_50 ( V_46 , & V_25 -> V_50 ) ;
F_31 ( & V_25 -> V_50 . V_51 ) ;
F_44 ( V_25 , V_46 ) ;
goto V_64;
}
V_16:
F_31 ( & V_25 -> V_50 . V_51 ) ;
}
static int F_51 ( struct V_22 * V_25 , T_1 V_60 )
{
T_1 V_70 ;
if ( V_60 >= V_25 -> V_60 )
V_70 = V_60 - V_25 -> V_60 ;
else
V_70 = ( V_25 -> V_61 + 1 ) - ( V_25 -> V_60 - V_60 ) ;
return V_70 < V_25 -> V_71 ;
}
static int F_52 ( struct V_22 * V_25 , struct V_45 * V_46 )
{
if ( ! F_51 ( V_25 , F_37 ( V_46 ) -> V_49 ) ) {
F_40 ( V_25 , V_52 ,
L_6 ,
V_25 -> V_53 , F_37 ( V_46 ) -> V_49 ,
F_37 ( V_46 ) -> V_56 , V_25 -> V_60 ) ;
goto V_72;
}
if ( V_25 -> V_73 != 0 ) {
F_36 ( V_25 , V_46 ) ;
goto V_16;
}
if ( F_37 ( V_46 ) -> V_49 == V_25 -> V_60 ) {
F_53 ( & V_25 -> V_50 , V_46 ) ;
} else {
T_1 V_74 = F_37 ( V_46 ) -> V_49 ;
T_1 V_75 = ( V_25 -> V_74 + 1 ) & V_25 -> V_61 ;
if ( V_74 == V_75 )
V_25 -> V_76 ++ ;
else
V_25 -> V_76 = 0 ;
V_25 -> V_74 = V_74 ;
if ( V_25 -> V_76 > V_25 -> V_77 ) {
V_25 -> V_69 = 1 ;
F_40 ( V_25 , V_52 ,
L_7 ,
V_25 -> V_53 , V_25 -> V_76 ) ;
}
if ( ! V_25 -> V_69 ) {
F_42 ( & V_25 -> V_54 . V_67 ) ;
F_40 ( V_25 , V_52 ,
L_8 ,
V_25 -> V_53 , F_37 ( V_46 ) -> V_49 ,
F_37 ( V_46 ) -> V_56 , V_25 -> V_60 ,
F_41 ( & V_25 -> V_50 ) ) ;
goto V_72;
}
F_53 ( & V_25 -> V_50 , V_46 ) ;
}
V_16:
return 0 ;
V_72:
return 1 ;
}
void F_54 ( struct V_22 * V_25 , struct V_45 * V_46 ,
unsigned char * V_78 , unsigned char * V_79 , T_2 V_80 ,
int V_56 , int (* F_55)( struct V_45 * V_46 ) )
{
struct V_1 * V_13 = V_25 -> V_13 ;
int V_81 ;
T_1 V_49 , V_60 ;
if ( V_25 -> V_82 > 0 ) {
if ( memcmp ( V_78 , & V_25 -> V_83 [ 0 ] , V_25 -> V_82 ) ) {
F_56 ( V_13 , V_84 ,
L_9 ,
V_13 -> V_53 , V_13 -> V_21 ,
V_25 -> V_10 ) ;
F_42 ( & V_25 -> V_54 . V_85 ) ;
goto V_72;
}
V_78 += V_25 -> V_82 ;
}
V_49 = V_60 = 0 ;
F_37 ( V_46 ) -> V_59 = 0 ;
if ( V_13 -> V_38 == V_86 ) {
if ( V_80 & V_87 ) {
V_49 = F_57 ( * ( V_88 * ) V_78 ) ;
V_78 += 2 ;
V_60 = F_57 ( * ( V_88 * ) V_78 ) ;
V_78 += 2 ;
F_37 ( V_46 ) -> V_49 = V_49 ;
F_37 ( V_46 ) -> V_59 = 1 ;
F_40 ( V_25 , V_52 ,
L_10 ,
V_25 -> V_53 , V_49 , V_60 , V_25 -> V_60 ) ;
}
} else if ( V_25 -> V_89 == V_90 ) {
T_1 V_91 = F_58 ( * ( V_92 * ) V_78 ) ;
if ( V_91 & 0x40000000 ) {
V_49 = V_91 & 0x00ffffff ;
F_37 ( V_46 ) -> V_49 = V_49 ;
F_37 ( V_46 ) -> V_59 = 1 ;
F_40 ( V_25 , V_52 ,
L_11 ,
V_25 -> V_53 , V_49 , V_25 -> V_60 ) ;
}
}
V_78 += V_25 -> V_93 ;
if ( F_37 ( V_46 ) -> V_59 ) {
if ( ( ! V_25 -> V_94 ) && ( ! V_25 -> V_95 ) ) {
F_56 ( V_25 , V_52 ,
L_12 ,
V_25 -> V_53 ) ;
V_25 -> V_95 = 1 ;
F_59 ( V_25 , V_13 -> V_38 ) ;
}
} else {
if ( V_25 -> V_96 ) {
F_60 ( V_25 , V_52 ,
L_13 ,
V_25 -> V_53 ) ;
F_42 ( & V_25 -> V_54 . V_67 ) ;
goto V_72;
}
if ( ( ! V_25 -> V_94 ) && ( V_25 -> V_95 ) ) {
F_56 ( V_25 , V_52 ,
L_14 ,
V_25 -> V_53 ) ;
V_25 -> V_95 = 0 ;
F_59 ( V_25 , V_13 -> V_38 ) ;
} else if ( V_25 -> V_95 ) {
F_60 ( V_25 , V_52 ,
L_13 ,
V_25 -> V_53 ) ;
F_42 ( & V_25 -> V_54 . V_67 ) ;
goto V_72;
}
}
if ( V_13 -> V_38 == V_86 ) {
if ( V_80 & V_97 ) {
V_81 = F_57 ( * ( V_88 * ) V_78 ) ;
V_78 += 2 + V_81 ;
}
} else
V_78 += V_25 -> V_81 ;
V_81 = V_78 - V_79 ;
if ( ! F_61 ( V_46 , V_81 ) )
goto V_72;
F_62 ( V_46 , V_81 ) ;
if ( F_55 )
if ( (* F_55)( V_46 ) )
goto V_72;
F_37 ( V_46 ) -> V_56 = V_56 ;
F_37 ( V_46 ) -> V_66 = V_65 +
( V_25 -> V_73 ? V_25 -> V_73 : V_98 ) ;
if ( F_37 ( V_46 ) -> V_59 ) {
if ( F_52 ( V_25 , V_46 ) )
goto V_72;
} else {
F_53 ( & V_25 -> V_50 , V_46 ) ;
}
F_48 ( V_25 ) ;
return;
V_72:
F_42 ( & V_25 -> V_54 . V_68 ) ;
F_47 ( V_46 ) ;
if ( V_25 -> V_63 )
(* V_25 -> V_63 )( V_25 ) ;
}
int F_63 ( struct V_22 * V_25 )
{
struct V_45 * V_46 = NULL ;
F_2 ( ! V_25 ) ;
F_2 ( V_25 -> V_99 != V_100 ) ;
while ( ( V_46 = F_64 ( & V_25 -> V_50 ) ) ) {
F_42 ( & V_25 -> V_54 . V_68 ) ;
F_47 ( V_46 ) ;
if ( V_25 -> V_63 )
(* V_25 -> V_63 )( V_25 ) ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_13 , struct V_45 * V_46 ,
int (* F_55)( struct V_45 * V_46 ) )
{
struct V_22 * V_25 = NULL ;
unsigned char * V_78 , * V_79 ;
T_2 V_80 ;
T_1 V_21 , V_10 ;
T_2 V_38 ;
int V_56 ;
F_62 ( V_46 , sizeof( struct V_101 ) ) ;
if ( ! F_61 ( V_46 , V_102 ) ) {
F_56 ( V_13 , V_84 ,
L_15 ,
V_13 -> V_53 , V_46 -> V_103 ) ;
goto error;
}
if ( V_13 -> V_104 & V_84 ) {
V_56 = F_66 ( 32u , V_46 -> V_103 ) ;
if ( ! F_61 ( V_46 , V_56 ) )
goto error;
F_67 ( L_16 , V_13 -> V_53 ) ;
F_68 ( L_17 , V_105 , V_46 -> V_106 , V_56 ) ;
}
V_79 = V_78 = V_46 -> V_106 ;
V_80 = F_57 ( * ( V_88 * ) V_78 ) ;
V_38 = V_80 & V_107 ;
if ( V_38 != V_13 -> V_38 ) {
F_56 ( V_13 , V_84 ,
L_18 ,
V_13 -> V_53 , V_38 , V_13 -> V_38 ) ;
goto error;
}
V_56 = V_46 -> V_103 ;
if ( V_80 & V_108 ) {
F_40 ( V_13 , V_84 ,
L_19 ,
V_13 -> V_53 , V_56 ) ;
goto error;
}
V_78 += 2 ;
if ( V_13 -> V_38 == V_86 ) {
if ( V_80 & V_109 )
V_78 += 2 ;
V_21 = F_57 ( * ( V_88 * ) V_78 ) ;
V_78 += 2 ;
V_10 = F_57 ( * ( V_88 * ) V_78 ) ;
V_78 += 2 ;
} else {
V_78 += 2 ;
V_21 = V_13 -> V_21 ;
V_10 = F_58 ( * ( V_92 * ) V_78 ) ;
V_78 += 4 ;
}
V_25 = F_19 ( V_13 -> V_5 , V_13 , V_10 , true ) ;
if ( ! V_25 || ! V_25 -> V_62 ) {
if ( V_25 ) {
if ( V_25 -> V_63 )
V_25 -> V_63 ( V_25 ) ;
F_69 ( V_25 ) ;
}
F_56 ( V_13 , V_84 ,
L_20 ,
V_13 -> V_53 , V_21 , V_10 ) ;
goto error;
}
F_54 ( V_25 , V_46 , V_78 , V_79 , V_80 , V_56 , F_55 ) ;
F_69 ( V_25 ) ;
return 0 ;
error:
F_70 ( V_46 , sizeof( struct V_101 ) ) ;
return 1 ;
}
int F_71 ( struct V_2 * V_3 , struct V_45 * V_46 )
{
struct V_1 * V_13 ;
V_13 = F_10 ( V_3 ) ;
if ( V_13 == NULL )
goto V_110;
F_40 ( V_13 , V_84 , L_21 ,
V_13 -> V_53 , V_46 -> V_103 ) ;
if ( F_65 ( V_13 , V_46 , V_13 -> V_111 ) )
goto V_112;
F_12 ( V_3 ) ;
return 0 ;
V_112:
F_12 ( V_3 ) ;
V_110:
return 1 ;
}
static int F_72 ( struct V_22 * V_25 , void * V_113 )
{
struct V_1 * V_13 = V_25 -> V_13 ;
V_88 * V_114 = V_113 ;
V_88 * V_79 = V_113 ;
T_2 V_115 = V_86 ;
T_1 V_21 = V_13 -> V_116 ;
T_1 V_10 = V_25 -> V_117 ;
if ( V_25 -> V_95 )
V_115 |= V_87 ;
* V_114 ++ = F_73 ( V_115 ) ;
* V_114 ++ = F_73 ( V_21 ) ;
* V_114 ++ = F_73 ( V_10 ) ;
if ( V_25 -> V_95 ) {
* V_114 ++ = F_73 ( V_25 -> V_49 ) ;
* V_114 ++ = 0 ;
V_25 -> V_49 ++ ;
V_25 -> V_49 &= 0xffff ;
F_40 ( V_25 , V_52 , L_22 ,
V_25 -> V_53 , V_25 -> V_49 ) ;
}
return V_114 - V_79 ;
}
static int F_74 ( struct V_22 * V_25 , void * V_113 )
{
struct V_1 * V_13 = V_25 -> V_13 ;
char * V_114 = V_113 ;
char * V_79 = V_114 ;
if ( V_13 -> V_118 == V_119 ) {
T_2 V_115 = V_39 ;
* ( ( V_88 * ) V_114 ) = F_73 ( V_115 ) ;
V_114 += 2 ;
* ( ( V_88 * ) V_114 ) = 0 ;
V_114 += 2 ;
}
* ( ( V_92 * ) V_114 ) = F_75 ( V_25 -> V_117 ) ;
V_114 += 4 ;
if ( V_25 -> V_120 ) {
memcpy ( V_114 , & V_25 -> V_121 [ 0 ] , V_25 -> V_120 ) ;
V_114 += V_25 -> V_120 ;
}
if ( V_25 -> V_93 ) {
if ( V_25 -> V_89 == V_90 ) {
T_1 V_91 = 0 ;
if ( V_25 -> V_95 ) {
V_91 = 0x40000000 | V_25 -> V_49 ;
V_25 -> V_49 ++ ;
V_25 -> V_49 &= 0xffffff ;
F_40 ( V_25 , V_52 ,
L_22 ,
V_25 -> V_53 , V_25 -> V_49 ) ;
}
* ( ( V_92 * ) V_114 ) = F_75 ( V_91 ) ;
}
V_114 += V_25 -> V_93 ;
}
if ( V_25 -> V_81 )
V_114 += V_25 -> V_81 ;
return V_114 - V_79 ;
}
static int F_76 ( struct V_22 * V_25 , struct V_45 * V_46 ,
struct V_122 * V_123 , T_3 V_124 )
{
struct V_1 * V_13 = V_25 -> V_13 ;
unsigned int V_103 = V_46 -> V_103 ;
int error ;
if ( V_25 -> V_95 )
F_40 ( V_25 , V_84 , L_23 ,
V_25 -> V_53 , V_124 , V_25 -> V_49 - 1 ) ;
else
F_40 ( V_25 , V_84 , L_24 ,
V_25 -> V_53 , V_124 ) ;
if ( V_25 -> V_104 & V_84 ) {
int V_125 = ( V_13 -> V_118 == V_119 ) ? sizeof( struct V_101 ) : 0 ;
unsigned char * V_126 = V_46 -> V_106 + V_125 ;
F_67 ( L_25 , V_25 -> V_53 ) ;
F_68 ( L_17 , V_105 ,
V_126 , F_77 ( T_3 , 32 , V_103 - V_125 ) ) ;
}
V_46 -> V_127 = 1 ;
#if F_78 ( V_128 )
if ( V_13 -> V_2 -> V_129 == V_130 && ! V_13 -> V_131 )
error = F_79 ( V_13 -> V_2 , V_46 , NULL ) ;
else
#endif
error = F_80 ( V_13 -> V_2 , V_46 , V_123 ) ;
if ( error >= 0 ) {
F_42 ( & V_13 -> V_54 . V_132 ) ;
F_46 ( V_103 , & V_13 -> V_54 . V_133 ) ;
F_42 ( & V_25 -> V_54 . V_132 ) ;
F_46 ( V_103 , & V_25 -> V_54 . V_133 ) ;
} else {
F_42 ( & V_13 -> V_54 . V_134 ) ;
F_42 ( & V_25 -> V_54 . V_134 ) ;
}
return 0 ;
}
int F_81 ( struct V_22 * V_25 , struct V_45 * V_46 , int V_135 )
{
int V_124 = V_46 -> V_103 ;
struct V_1 * V_13 = V_25 -> V_13 ;
struct V_2 * V_3 = V_13 -> V_2 ;
struct V_122 * V_123 ;
struct V_101 * V_136 ;
struct V_137 * V_138 ;
int V_139 ;
int V_125 = ( V_13 -> V_118 == V_119 ) ? sizeof( struct V_101 ) : 0 ;
int V_140 ;
int V_141 = V_142 ;
V_139 = V_143 + sizeof( struct V_144 ) +
V_125 + V_135 ;
if ( F_82 ( V_46 , V_139 ) ) {
F_47 ( V_46 ) ;
return V_145 ;
}
V_25 -> V_146 ( V_25 , F_70 ( V_46 , V_135 ) ) ;
memset ( & ( F_83 ( V_46 ) -> V_147 ) , 0 , sizeof( F_83 ( V_46 ) -> V_147 ) ) ;
F_83 ( V_46 ) -> V_115 &= ~ ( V_148 | V_149 |
V_150 ) ;
F_84 ( V_46 ) ;
F_85 ( V_3 ) ;
if ( F_86 ( V_3 ) ) {
F_47 ( V_46 ) ;
V_141 = V_145 ;
goto V_151;
}
F_87 ( V_46 ) ;
F_88 ( V_46 , F_89 ( F_90 ( V_3 , 0 ) ) ) ;
V_138 = F_91 ( V_3 ) ;
V_123 = & V_138 -> V_152 . V_123 ;
switch ( V_13 -> V_118 ) {
case V_119 :
F_70 ( V_46 , sizeof( * V_136 ) ) ;
F_92 ( V_46 ) ;
V_136 = F_93 ( V_46 ) ;
V_136 -> V_153 = V_138 -> V_154 ;
V_136 -> V_155 = V_138 -> V_156 ;
V_140 = V_125 + V_135 + V_124 ;
V_136 -> V_103 = F_73 ( V_140 ) ;
#if F_78 ( V_128 )
if ( V_3 -> V_129 == V_130 && ! V_13 -> V_131 )
F_94 ( F_95 ( V_3 ) ,
V_46 , & F_96 ( V_3 ) -> V_157 ,
& V_3 -> V_158 , V_140 ) ;
else
#endif
F_97 ( V_3 -> V_159 , V_46 , V_138 -> V_160 ,
V_138 -> V_161 , V_140 ) ;
break;
case V_162 :
break;
}
F_76 ( V_25 , V_46 , V_123 , V_124 ) ;
V_151:
F_98 ( V_3 ) ;
return V_141 ;
}
static void F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = V_1 ( V_3 ) ;
struct V_5 * V_9 ;
if ( V_13 == NULL )
goto V_163;
F_56 ( V_13 , V_164 , L_26 , V_13 -> V_53 ) ;
switch ( V_13 -> V_118 ) {
case V_119 :
( F_100 ( V_3 ) ) -> V_165 = 0 ;
( F_100 ( V_3 ) ) -> V_166 = NULL ;
( F_100 ( V_3 ) ) -> V_167 = NULL ;
break;
case V_162 :
break;
}
V_3 -> V_168 = V_13 -> V_169 ;
V_3 -> V_4 = NULL ;
V_13 -> V_2 = NULL ;
V_9 = F_1 ( V_13 -> V_5 ) ;
F_29 ( & V_9 -> V_170 ) ;
F_101 ( & V_13 -> V_171 ) ;
F_31 ( & V_9 -> V_170 ) ;
F_102 ( & V_172 ) ;
F_103 ( V_13 ) ;
F_104 ( V_13 ) ;
if ( V_3 -> V_168 )
(* V_3 -> V_168 )( V_3 ) ;
V_163:
return;
}
void F_103 ( struct V_1 * V_13 )
{
int V_29 ;
struct V_173 * V_174 ;
struct V_173 * V_48 ;
struct V_22 * V_25 ;
F_2 ( V_13 == NULL ) ;
F_56 ( V_13 , V_164 , L_27 ,
V_13 -> V_53 ) ;
F_28 ( & V_13 -> V_27 ) ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
V_175:
F_105 (walk, tmp, &tunnel->session_hlist[hash]) {
V_25 = F_106 ( V_174 , struct V_22 , V_43 ) ;
F_56 ( V_25 , V_164 ,
L_28 , V_25 -> V_53 ) ;
F_107 ( & V_25 -> V_43 ) ;
if ( V_25 -> V_26 != NULL )
(* V_25 -> V_26 )( V_25 ) ;
F_33 ( & V_13 -> V_27 ) ;
F_108 ( V_25 ) ;
F_63 ( V_25 ) ;
if ( V_25 -> V_176 != NULL )
(* V_25 -> V_176 )( V_25 ) ;
if ( V_25 -> V_63 != NULL )
(* V_25 -> V_63 )( V_25 ) ;
F_69 ( V_25 ) ;
F_28 ( & V_13 -> V_27 ) ;
goto V_175;
}
}
F_33 ( & V_13 -> V_27 ) ;
}
static void F_109 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_10 ( V_3 ) ;
if ( V_13 ) {
F_103 ( V_13 ) ;
F_12 ( V_3 ) ;
}
}
static void F_110 ( struct V_177 * V_178 )
{
struct V_1 * V_13 = NULL ;
struct V_15 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
V_13 = F_111 ( V_178 , struct V_1 , V_179 ) ;
F_103 ( V_13 ) ;
V_3 = F_6 ( V_13 ) ;
if ( ! V_3 )
goto V_16;
V_2 = V_3 -> V_18 ;
if ( V_13 -> V_17 >= 0 ) {
if ( V_2 )
F_112 ( V_2 , 2 ) ;
} else {
if ( V_2 ) {
F_113 ( V_2 , V_180 ) ;
F_114 ( V_2 ) ;
}
}
F_9 ( V_3 ) ;
V_16:
F_104 ( V_13 ) ;
}
static int F_115 ( struct V_6 * V_6 ,
T_1 V_21 ,
T_1 V_116 ,
struct V_181 * V_182 ,
struct V_15 * * V_183 )
{
int V_14 = - V_184 ;
struct V_15 * V_2 = NULL ;
struct V_185 V_186 ;
switch ( V_182 -> V_118 ) {
case V_119 :
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
#if F_78 ( V_128 )
if ( V_182 -> V_187 && V_182 -> V_188 ) {
V_186 . V_189 = V_190 ;
memcpy ( & V_186 . V_187 , V_182 -> V_187 ,
sizeof( V_186 . V_187 ) ) ;
memcpy ( & V_186 . V_188 , V_182 -> V_188 ,
sizeof( V_186 . V_188 ) ) ;
V_186 . V_191 =
! V_182 -> V_192 ;
V_186 . V_193 =
! V_182 -> V_194 ;
} else
#endif
{
V_186 . V_189 = V_195 ;
V_186 . V_196 = V_182 -> V_196 ;
V_186 . V_197 = V_182 -> V_197 ;
V_186 . V_198 = V_182 -> V_198 ;
}
V_186 . V_199 = F_73 ( V_182 -> V_199 ) ;
V_186 . V_200 = F_73 ( V_182 -> V_200 ) ;
V_14 = F_116 ( V_6 , & V_186 , & V_2 ) ;
if ( V_14 < 0 )
goto V_16;
break;
case V_162 :
#if F_78 ( V_128 )
if ( V_182 -> V_187 && V_182 -> V_188 ) {
struct V_201 V_202 = { 0 } ;
V_14 = F_117 ( V_6 , V_190 , V_203 ,
V_204 , & V_2 ) ;
if ( V_14 < 0 )
goto V_16;
V_202 . V_205 = V_190 ;
memcpy ( & V_202 . V_206 , V_182 -> V_187 ,
sizeof( V_202 . V_206 ) ) ;
V_202 . V_207 = V_21 ;
V_14 = F_118 ( V_2 , (struct V_208 * ) & V_202 ,
sizeof( V_202 ) ) ;
if ( V_14 < 0 )
goto V_16;
V_202 . V_205 = V_190 ;
memcpy ( & V_202 . V_206 , V_182 -> V_188 ,
sizeof( V_202 . V_206 ) ) ;
V_202 . V_207 = V_116 ;
V_14 = F_119 ( V_2 ,
(struct V_208 * ) & V_202 ,
sizeof( V_202 ) , 0 ) ;
if ( V_14 < 0 )
goto V_16;
} else
#endif
{
struct V_209 V_210 = { 0 } ;
V_14 = F_117 ( V_6 , V_195 , V_203 ,
V_204 , & V_2 ) ;
if ( V_14 < 0 )
goto V_16;
V_210 . V_205 = V_195 ;
V_210 . V_206 = V_182 -> V_196 ;
V_210 . V_207 = V_21 ;
V_14 = F_118 ( V_2 , (struct V_208 * ) & V_210 ,
sizeof( V_210 ) ) ;
if ( V_14 < 0 )
goto V_16;
V_210 . V_205 = V_195 ;
V_210 . V_206 = V_182 -> V_197 ;
V_210 . V_207 = V_116 ;
V_14 = F_119 ( V_2 , (struct V_208 * ) & V_210 ,
sizeof( V_210 ) , 0 ) ;
if ( V_14 < 0 )
goto V_16;
}
break;
default:
goto V_16;
}
V_16:
* V_183 = V_2 ;
if ( ( V_14 < 0 ) && V_2 ) {
F_113 ( V_2 , V_180 ) ;
F_114 ( V_2 ) ;
* V_183 = NULL ;
}
return V_14 ;
}
int F_120 ( struct V_6 * V_6 , int V_17 , int V_38 , T_1 V_21 , T_1 V_116 , struct V_181 * V_182 , struct V_1 * * V_211 )
{
struct V_1 * V_13 = NULL ;
int V_14 ;
struct V_15 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
struct V_5 * V_9 ;
enum V_212 V_118 = V_119 ;
if ( V_17 < 0 ) {
V_14 = F_115 ( V_6 , V_21 , V_116 ,
V_182 , & V_2 ) ;
if ( V_14 < 0 )
goto V_14;
} else {
V_2 = F_7 ( V_17 , & V_14 ) ;
if ( ! V_2 ) {
F_121 ( L_29 ,
V_21 , V_17 , V_14 ) ;
V_14 = - V_213 ;
goto V_14;
}
if ( ! F_122 ( F_123 ( V_2 -> V_3 ) , V_6 ) ) {
F_121 ( L_30 , V_21 ) ;
V_14 = - V_184 ;
goto V_14;
}
}
V_3 = V_2 -> V_3 ;
if ( V_182 != NULL )
V_118 = V_182 -> V_118 ;
switch ( V_118 ) {
case V_119 :
V_14 = - V_214 ;
if ( V_3 -> V_215 != V_216 ) {
F_121 ( L_31 ,
V_21 , V_17 , V_3 -> V_215 , V_216 ) ;
goto V_14;
}
break;
case V_162 :
V_14 = - V_214 ;
if ( V_3 -> V_215 != V_204 ) {
F_121 ( L_31 ,
V_21 , V_17 , V_3 -> V_215 , V_204 ) ;
goto V_14;
}
break;
}
V_13 = V_1 ( V_3 ) ;
if ( V_13 != NULL ) {
V_14 = - V_217 ;
goto V_14;
}
V_13 = F_124 ( sizeof( struct V_1 ) , V_218 ) ;
if ( V_13 == NULL ) {
V_14 = - V_219 ;
goto V_14;
}
V_13 -> V_38 = V_38 ;
V_13 -> V_21 = V_21 ;
V_13 -> V_116 = V_116 ;
V_13 -> V_104 = V_220 ;
V_13 -> V_99 = V_221 ;
sprintf ( & V_13 -> V_53 [ 0 ] , L_32 , V_21 ) ;
F_125 ( & V_13 -> V_27 ) ;
V_13 -> V_5 = V_6 ;
V_9 = F_1 ( V_6 ) ;
if ( V_182 != NULL )
V_13 -> V_104 = V_182 -> V_104 ;
#if F_78 ( V_128 )
if ( V_3 -> V_129 == V_130 ) {
struct V_222 * V_223 = F_96 ( V_3 ) ;
if ( F_126 ( & V_223 -> V_157 ) &&
F_126 ( & V_3 -> V_158 ) ) {
struct V_137 * V_138 = F_91 ( V_3 ) ;
V_13 -> V_131 = true ;
V_138 -> V_160 = V_223 -> V_157 . V_224 [ 3 ] ;
V_138 -> V_225 = V_3 -> V_226 . V_224 [ 3 ] ;
V_138 -> V_161 = V_3 -> V_158 . V_224 [ 3 ] ;
} else {
V_13 -> V_131 = false ;
}
}
#endif
V_13 -> V_118 = V_118 ;
if ( V_118 == V_119 ) {
struct V_227 V_228 = { } ;
V_228 . V_4 = V_13 ;
V_228 . V_165 = V_229 ;
V_228 . V_166 = F_71 ;
V_228 . V_167 = F_109 ;
F_127 ( V_6 , V_2 , & V_228 ) ;
} else {
V_3 -> V_4 = V_13 ;
}
V_13 -> V_169 = V_3 -> V_168 ;
V_3 -> V_168 = & F_99 ;
V_13 -> V_2 = V_3 ;
V_13 -> V_17 = V_17 ;
F_128 ( & V_3 -> V_230 . V_231 , & V_232 , L_33 ) ;
V_3 -> V_233 = V_234 ;
F_129 ( & V_13 -> V_179 , F_110 ) ;
F_130 ( & V_13 -> V_171 ) ;
F_131 ( & V_172 ) ;
F_132 ( & V_13 -> V_235 , 1 ) ;
F_29 ( & V_9 -> V_170 ) ;
F_133 ( & V_13 -> V_171 , & V_9 -> V_236 ) ;
F_31 ( & V_9 -> V_170 ) ;
V_14 = 0 ;
V_14:
if ( V_211 )
* V_211 = V_13 ;
if ( V_2 && V_2 -> V_237 )
F_11 ( V_2 ) ;
return V_14 ;
}
int F_134 ( struct V_1 * V_13 )
{
F_17 ( V_13 ) ;
if ( false == F_135 ( V_238 , & V_13 -> V_179 ) ) {
F_104 ( V_13 ) ;
return 1 ;
}
return 0 ;
}
void F_136 ( struct V_22 * V_25 )
{
struct V_1 * V_13 = V_25 -> V_13 ;
F_2 ( F_137 ( & V_25 -> V_235 ) != 0 ) ;
if ( V_13 ) {
F_2 ( V_13 -> V_99 != V_221 ) ;
if ( V_25 -> V_10 != 0 )
F_102 ( & V_239 ) ;
F_12 ( V_13 -> V_2 ) ;
V_25 -> V_13 = NULL ;
F_104 ( V_13 ) ;
}
F_138 ( V_25 ) ;
}
void F_108 ( struct V_22 * V_25 )
{
struct V_1 * V_13 = V_25 -> V_13 ;
if ( V_13 ) {
F_28 ( & V_13 -> V_27 ) ;
F_107 ( & V_25 -> V_43 ) ;
F_33 ( & V_13 -> V_27 ) ;
if ( V_13 -> V_38 != V_86 ) {
struct V_5 * V_9 = F_1 ( V_13 -> V_5 ) ;
F_29 ( & V_9 -> V_40 ) ;
F_139 ( & V_25 -> V_42 ) ;
F_31 ( & V_9 -> V_40 ) ;
F_140 () ;
}
}
}
int F_141 ( struct V_22 * V_25 )
{
if ( V_25 -> V_26 )
(* V_25 -> V_26 )( V_25 ) ;
F_108 ( V_25 ) ;
F_63 ( V_25 ) ;
if ( V_25 -> V_176 != NULL )
(* V_25 -> V_176 )( V_25 ) ;
if ( V_25 -> V_63 )
(* V_25 -> V_63 )( V_25 ) ;
F_69 ( V_25 ) ;
return 0 ;
}
void F_59 ( struct V_22 * V_25 , int V_38 )
{
if ( V_38 == V_86 ) {
V_25 -> V_135 = 6 ;
if ( V_25 -> V_95 )
V_25 -> V_135 += 4 ;
} else {
V_25 -> V_135 = 4 + V_25 -> V_120 + V_25 -> V_93 + V_25 -> V_81 ;
if ( V_25 -> V_13 -> V_118 == V_119 )
V_25 -> V_135 += 4 ;
}
}
struct V_22 * F_142 ( int V_240 , struct V_1 * V_13 , T_1 V_10 , T_1 V_117 , struct V_241 * V_182 )
{
struct V_22 * V_25 ;
int V_14 ;
V_25 = F_124 ( sizeof( struct V_22 ) + V_240 , V_218 ) ;
if ( V_25 != NULL ) {
V_25 -> V_99 = V_100 ;
V_25 -> V_13 = V_13 ;
V_25 -> V_10 = V_10 ;
V_25 -> V_117 = V_117 ;
V_25 -> V_60 = 0 ;
if ( V_13 -> V_38 == V_86 )
V_25 -> V_61 = 0xffff ;
else
V_25 -> V_61 = 0xffffff ;
V_25 -> V_71 = V_25 -> V_61 / 2 ;
V_25 -> V_77 = 4 ;
V_25 -> V_69 = 1 ;
sprintf ( & V_25 -> V_53 [ 0 ] , L_34 ,
V_13 -> V_21 , V_25 -> V_10 ) ;
F_143 ( & V_25 -> V_50 ) ;
F_144 ( & V_25 -> V_43 ) ;
F_144 ( & V_25 -> V_42 ) ;
V_25 -> V_104 = V_13 -> V_104 ;
if ( V_182 ) {
V_25 -> V_242 = V_182 -> V_243 ;
V_25 -> V_104 = V_182 -> V_104 ;
V_25 -> V_244 = V_182 -> V_244 ;
V_25 -> V_245 = V_182 -> V_245 ;
V_25 -> V_95 = V_182 -> V_95 ;
V_25 -> V_96 = V_182 -> V_96 ;
V_25 -> V_94 = V_182 -> V_94 ;
V_25 -> V_73 = V_182 -> V_73 ;
V_25 -> V_81 = V_182 -> V_81 ;
V_25 -> V_89 = V_182 -> V_89 ;
V_25 -> V_93 = V_182 -> V_93 ;
V_25 -> V_120 = V_182 -> V_120 ;
memcpy ( & V_25 -> V_121 [ 0 ] , & V_182 -> V_121 [ 0 ] , V_182 -> V_120 ) ;
V_25 -> V_82 = V_182 -> V_82 ;
memcpy ( & V_25 -> V_83 [ 0 ] , & V_182 -> V_83 [ 0 ] , V_182 -> V_82 ) ;
}
if ( V_13 -> V_38 == V_86 )
V_25 -> V_146 = F_72 ;
else
V_25 -> V_146 = F_74 ;
F_59 ( V_25 , V_13 -> V_38 ) ;
F_132 ( & V_25 -> V_235 , 1 ) ;
V_14 = F_27 ( V_13 , V_25 ) ;
if ( V_14 ) {
F_138 ( V_25 ) ;
return F_145 ( V_14 ) ;
}
F_17 ( V_13 ) ;
F_8 ( V_13 -> V_2 ) ;
if ( V_25 -> V_10 != 0 )
F_131 ( & V_239 ) ;
return V_25 ;
}
return F_145 ( - V_219 ) ;
}
static T_4 int F_146 ( struct V_6 * V_6 )
{
struct V_5 * V_9 = F_3 ( V_6 , V_7 ) ;
int V_29 ;
F_130 ( & V_9 -> V_236 ) ;
F_147 ( & V_9 -> V_170 ) ;
for ( V_29 = 0 ; V_29 < V_33 ; V_29 ++ )
F_148 ( & V_9 -> V_11 [ V_29 ] ) ;
F_147 ( & V_9 -> V_40 ) ;
return 0 ;
}
static T_5 void F_149 ( struct V_6 * V_6 )
{
struct V_5 * V_9 = F_1 ( V_6 ) ;
struct V_1 * V_13 = NULL ;
F_15 () ;
F_16 (tunnel, &pn->l2tp_tunnel_list, list) {
( void ) F_134 ( V_13 ) ;
}
F_18 () ;
F_150 ( V_238 ) ;
F_151 () ;
}
static int T_6 F_152 ( void )
{
int V_246 = 0 ;
V_246 = F_153 ( & V_247 ) ;
if ( V_246 )
goto V_16;
V_238 = F_154 ( L_35 , V_248 , 0 ) ;
if ( ! V_238 ) {
F_121 ( L_36 ) ;
F_155 ( & V_247 ) ;
V_246 = - V_219 ;
goto V_16;
}
F_156 ( L_37 , V_249 ) ;
V_16:
return V_246 ;
}
static void T_7 F_157 ( void )
{
F_155 ( & V_247 ) ;
if ( V_238 ) {
F_158 ( V_238 ) ;
V_238 = NULL ;
}
}
