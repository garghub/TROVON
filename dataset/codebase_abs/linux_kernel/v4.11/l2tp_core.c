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
static inline struct V_10 *
F_9 ( struct V_5 * V_11 , T_1 V_12 )
{
return & V_11 -> V_13 [ F_10 ( V_12 , V_14 ) ] ;
}
static struct V_2 * F_11 ( struct V_1 * V_8 )
{
int V_15 = 0 ;
struct V_16 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
if ( ! V_8 )
goto V_17;
if ( V_8 -> V_18 >= 0 ) {
V_2 = F_12 ( V_8 -> V_18 , & V_15 ) ;
if ( V_2 )
V_3 = V_2 -> V_3 ;
} else {
V_3 = V_8 -> V_2 ;
F_13 ( V_3 ) ;
}
V_17:
return V_3 ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_15 ( V_3 ) ;
if ( V_8 ) {
if ( V_8 -> V_18 >= 0 ) {
F_16 ( V_3 -> V_19 ) ;
}
F_17 ( V_3 ) ;
}
F_17 ( V_3 ) ;
}
static struct V_20 * F_18 ( struct V_6 * V_6 , T_1 V_12 )
{
struct V_5 * V_11 = F_1 ( V_6 ) ;
struct V_10 * V_21 =
F_9 ( V_11 , V_12 ) ;
struct V_20 * V_22 ;
F_19 () ;
F_20 (session, session_list, global_hlist) {
if ( V_22 -> V_12 == V_12 ) {
F_21 () ;
return V_22 ;
}
}
F_21 () ;
return NULL ;
}
static inline struct V_10 *
F_22 ( struct V_1 * V_8 , T_1 V_12 )
{
return & V_8 -> V_23 [ F_10 ( V_12 , V_24 ) ] ;
}
struct V_20 * F_23 ( struct V_6 * V_6 , struct V_1 * V_8 , T_1 V_12 )
{
struct V_10 * V_21 ;
struct V_20 * V_22 ;
if ( V_8 == NULL )
return F_18 ( V_6 , V_12 ) ;
V_21 = F_22 ( V_8 , V_12 ) ;
F_24 ( & V_8 -> V_25 ) ;
F_25 (session, session_list, hlist) {
if ( V_22 -> V_12 == V_12 ) {
F_26 ( & V_8 -> V_25 ) ;
return V_22 ;
}
}
F_26 ( & V_8 -> V_25 ) ;
return NULL ;
}
struct V_20 * F_27 ( struct V_6 * V_6 ,
struct V_1 * V_8 ,
T_1 V_12 , bool V_26 )
{
struct V_10 * V_21 ;
struct V_20 * V_22 ;
if ( ! V_8 ) {
struct V_5 * V_11 = F_1 ( V_6 ) ;
V_21 = F_9 ( V_11 , V_12 ) ;
F_19 () ;
F_20 (session, session_list, global_hlist) {
if ( V_22 -> V_12 == V_12 ) {
F_28 ( V_22 ) ;
if ( V_26 && V_22 -> V_27 )
V_22 -> V_27 ( V_22 ) ;
F_21 () ;
return V_22 ;
}
}
F_21 () ;
return NULL ;
}
V_21 = F_22 ( V_8 , V_12 ) ;
F_24 ( & V_8 -> V_25 ) ;
F_25 (session, session_list, hlist) {
if ( V_22 -> V_12 == V_12 ) {
F_28 ( V_22 ) ;
if ( V_26 && V_22 -> V_27 )
V_22 -> V_27 ( V_22 ) ;
F_26 ( & V_8 -> V_25 ) ;
return V_22 ;
}
}
F_26 ( & V_8 -> V_25 ) ;
return NULL ;
}
struct V_20 * F_29 ( struct V_1 * V_8 , int V_28 ,
bool V_26 )
{
int V_29 ;
struct V_20 * V_22 ;
int V_30 = 0 ;
F_24 ( & V_8 -> V_25 ) ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
F_25 (session, &tunnel->session_hlist[hash], hlist) {
if ( ++ V_30 > V_28 ) {
F_28 ( V_22 ) ;
if ( V_26 && V_22 -> V_27 )
V_22 -> V_27 ( V_22 ) ;
F_26 ( & V_8 -> V_25 ) ;
return V_22 ;
}
}
}
F_26 ( & V_8 -> V_25 ) ;
return NULL ;
}
struct V_20 * F_30 ( struct V_6 * V_6 , char * V_32 ,
bool V_26 )
{
struct V_5 * V_11 = F_1 ( V_6 ) ;
int V_29 ;
struct V_20 * V_22 ;
F_19 () ;
for ( V_29 = 0 ; V_29 < V_33 ; V_29 ++ ) {
F_20 (session, &pn->l2tp_session_hlist[hash], global_hlist) {
if ( ! strcmp ( V_22 -> V_32 , V_32 ) ) {
F_28 ( V_22 ) ;
if ( V_26 && V_22 -> V_27 )
V_22 -> V_27 ( V_22 ) ;
F_21 () ;
return V_22 ;
}
}
}
F_21 () ;
return NULL ;
}
static int F_31 ( struct V_1 * V_8 ,
struct V_20 * V_22 )
{
struct V_20 * V_34 ;
struct V_10 * V_35 ;
struct V_10 * V_36 ;
struct V_5 * V_11 ;
V_36 = F_22 ( V_8 , V_22 -> V_12 ) ;
F_32 ( & V_8 -> V_25 ) ;
F_25 (session_walk, head, hlist)
if ( V_34 -> V_12 == V_22 -> V_12 )
goto V_37;
if ( V_8 -> V_38 == V_39 ) {
V_11 = F_1 ( V_8 -> V_5 ) ;
V_35 = F_9 ( F_1 ( V_8 -> V_5 ) ,
V_22 -> V_12 ) ;
F_33 ( & V_11 -> V_40 ) ;
F_25 (session_walk, g_head, global_hlist)
if ( V_34 -> V_12 == V_22 -> V_12 )
goto V_41;
F_34 ( & V_22 -> V_42 , V_35 ) ;
F_35 ( & V_11 -> V_40 ) ;
}
F_36 ( & V_22 -> V_43 , V_36 ) ;
F_37 ( & V_8 -> V_25 ) ;
return 0 ;
V_41:
F_35 ( & V_11 -> V_40 ) ;
V_37:
F_37 ( & V_8 -> V_25 ) ;
return - V_44 ;
}
struct V_1 * F_38 ( struct V_6 * V_6 , T_1 V_45 )
{
struct V_1 * V_8 ;
struct V_5 * V_11 = F_1 ( V_6 ) ;
F_19 () ;
F_39 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( V_8 -> V_45 == V_45 ) {
F_21 () ;
return V_8 ;
}
}
F_21 () ;
return NULL ;
}
struct V_1 * F_40 ( struct V_6 * V_6 , int V_28 )
{
struct V_5 * V_11 = F_1 ( V_6 ) ;
struct V_1 * V_8 ;
int V_30 = 0 ;
F_19 () ;
F_39 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( ++ V_30 > V_28 ) {
F_21 () ;
return V_8 ;
}
}
F_21 () ;
return NULL ;
}
static void F_41 ( struct V_20 * V_22 , struct V_46 * V_47 )
{
struct V_46 * V_48 ;
struct V_46 * V_49 ;
T_1 V_50 = F_42 ( V_47 ) -> V_50 ;
F_33 ( & V_22 -> V_51 . V_52 ) ;
F_43 (&session->reorder_q, skbp, tmp) {
if ( F_42 ( V_48 ) -> V_50 > V_50 ) {
F_44 ( & V_22 -> V_51 , V_48 , V_47 ) ;
F_45 ( V_22 , V_53 ,
L_1 ,
V_22 -> V_54 , V_50 , F_42 ( V_48 ) -> V_50 ,
F_46 ( & V_22 -> V_51 ) ) ;
F_47 ( & V_22 -> V_55 . V_56 ) ;
goto V_17;
}
}
F_48 ( & V_22 -> V_51 , V_47 ) ;
V_17:
F_35 ( & V_22 -> V_51 . V_52 ) ;
}
static void F_49 ( struct V_20 * V_22 , struct V_46 * V_47 )
{
struct V_1 * V_8 = V_22 -> V_8 ;
int V_57 = F_42 ( V_47 ) -> V_57 ;
F_50 ( V_47 ) ;
F_47 ( & V_8 -> V_55 . V_58 ) ;
F_51 ( V_57 , & V_8 -> V_55 . V_59 ) ;
F_47 ( & V_22 -> V_55 . V_58 ) ;
F_51 ( V_57 , & V_22 -> V_55 . V_59 ) ;
if ( F_42 ( V_47 ) -> V_60 ) {
V_22 -> V_61 ++ ;
V_22 -> V_61 &= V_22 -> V_62 ;
F_45 ( V_22 , V_53 , L_2 ,
V_22 -> V_54 , V_22 -> V_61 ) ;
}
if ( V_22 -> V_63 != NULL )
(* V_22 -> V_63 )( V_22 , V_47 , F_42 ( V_47 ) -> V_57 ) ;
else
F_52 ( V_47 ) ;
if ( V_22 -> V_64 )
(* V_22 -> V_64 )( V_22 ) ;
}
static void F_53 ( struct V_20 * V_22 )
{
struct V_46 * V_47 ;
struct V_46 * V_49 ;
V_65:
F_33 ( & V_22 -> V_51 . V_52 ) ;
F_43 (&session->reorder_q, skb, tmp) {
if ( F_54 ( V_66 , F_42 ( V_47 ) -> V_67 ) ) {
F_47 ( & V_22 -> V_55 . V_68 ) ;
F_47 ( & V_22 -> V_55 . V_69 ) ;
F_45 ( V_22 , V_53 ,
L_3 ,
V_22 -> V_54 , F_42 ( V_47 ) -> V_50 ,
F_42 ( V_47 ) -> V_57 , V_22 -> V_61 ,
F_46 ( & V_22 -> V_51 ) ) ;
V_22 -> V_70 = 1 ;
F_55 ( V_47 , & V_22 -> V_51 ) ;
F_52 ( V_47 ) ;
if ( V_22 -> V_64 )
(* V_22 -> V_64 )( V_22 ) ;
continue;
}
if ( F_42 ( V_47 ) -> V_60 ) {
if ( V_22 -> V_70 ) {
F_45 ( V_22 , V_53 ,
L_4 ,
V_22 -> V_54 , V_22 -> V_61 ,
F_42 ( V_47 ) -> V_50 ) ;
V_22 -> V_70 = 0 ;
V_22 -> V_61 = F_42 ( V_47 ) -> V_50 ;
}
if ( F_42 ( V_47 ) -> V_50 != V_22 -> V_61 ) {
F_45 ( V_22 , V_53 ,
L_5 ,
V_22 -> V_54 , F_42 ( V_47 ) -> V_50 ,
F_42 ( V_47 ) -> V_57 , V_22 -> V_61 ,
F_46 ( & V_22 -> V_51 ) ) ;
goto V_17;
}
}
F_55 ( V_47 , & V_22 -> V_51 ) ;
F_35 ( & V_22 -> V_51 . V_52 ) ;
F_49 ( V_22 , V_47 ) ;
goto V_65;
}
V_17:
F_35 ( & V_22 -> V_51 . V_52 ) ;
}
static int F_56 ( struct V_20 * V_22 , T_1 V_61 )
{
T_1 V_71 ;
if ( V_61 >= V_22 -> V_61 )
V_71 = V_61 - V_22 -> V_61 ;
else
V_71 = ( V_22 -> V_62 + 1 ) - ( V_22 -> V_61 - V_61 ) ;
return V_71 < V_22 -> V_72 ;
}
static int F_57 ( struct V_20 * V_22 , struct V_46 * V_47 )
{
if ( ! F_56 ( V_22 , F_42 ( V_47 ) -> V_50 ) ) {
F_45 ( V_22 , V_53 ,
L_6 ,
V_22 -> V_54 , F_42 ( V_47 ) -> V_50 ,
F_42 ( V_47 ) -> V_57 , V_22 -> V_61 ) ;
goto V_73;
}
if ( V_22 -> V_74 != 0 ) {
F_41 ( V_22 , V_47 ) ;
goto V_17;
}
if ( F_42 ( V_47 ) -> V_50 == V_22 -> V_61 ) {
F_58 ( & V_22 -> V_51 , V_47 ) ;
} else {
T_1 V_75 = F_42 ( V_47 ) -> V_50 ;
T_1 V_76 = ( V_22 -> V_75 + 1 ) & V_22 -> V_62 ;
if ( V_75 == V_76 )
V_22 -> V_77 ++ ;
else
V_22 -> V_77 = 0 ;
V_22 -> V_75 = V_75 ;
if ( V_22 -> V_77 > V_22 -> V_78 ) {
V_22 -> V_70 = 1 ;
F_45 ( V_22 , V_53 ,
L_7 ,
V_22 -> V_54 , V_22 -> V_77 ) ;
}
if ( ! V_22 -> V_70 ) {
F_47 ( & V_22 -> V_55 . V_68 ) ;
F_45 ( V_22 , V_53 ,
L_8 ,
V_22 -> V_54 , F_42 ( V_47 ) -> V_50 ,
F_42 ( V_47 ) -> V_57 , V_22 -> V_61 ,
F_46 ( & V_22 -> V_51 ) ) ;
goto V_73;
}
F_58 ( & V_22 -> V_51 , V_47 ) ;
}
V_17:
return 0 ;
V_73:
return 1 ;
}
void F_59 ( struct V_20 * V_22 , struct V_46 * V_47 ,
unsigned char * V_79 , unsigned char * V_80 , T_2 V_81 ,
int V_57 , int (* F_60)( struct V_46 * V_47 ) )
{
struct V_1 * V_8 = V_22 -> V_8 ;
int V_82 ;
T_1 V_50 , V_61 ;
if ( V_22 -> V_83 > 0 ) {
if ( memcmp ( V_79 , & V_22 -> V_84 [ 0 ] , V_22 -> V_83 ) ) {
F_61 ( V_8 , V_85 ,
L_9 ,
V_8 -> V_54 , V_8 -> V_45 ,
V_22 -> V_12 ) ;
F_47 ( & V_22 -> V_55 . V_86 ) ;
goto V_73;
}
V_79 += V_22 -> V_83 ;
}
V_50 = V_61 = 0 ;
F_42 ( V_47 ) -> V_60 = 0 ;
if ( V_8 -> V_38 == V_87 ) {
if ( V_81 & V_88 ) {
V_50 = F_62 ( * ( V_89 * ) V_79 ) ;
V_79 += 2 ;
V_61 = F_62 ( * ( V_89 * ) V_79 ) ;
V_79 += 2 ;
F_42 ( V_47 ) -> V_50 = V_50 ;
F_42 ( V_47 ) -> V_60 = 1 ;
F_45 ( V_22 , V_53 ,
L_10 ,
V_22 -> V_54 , V_50 , V_61 , V_22 -> V_61 ) ;
}
} else if ( V_22 -> V_90 == V_91 ) {
T_1 V_92 = F_63 ( * ( V_93 * ) V_79 ) ;
if ( V_92 & 0x40000000 ) {
V_50 = V_92 & 0x00ffffff ;
F_42 ( V_47 ) -> V_50 = V_50 ;
F_42 ( V_47 ) -> V_60 = 1 ;
F_45 ( V_22 , V_53 ,
L_11 ,
V_22 -> V_54 , V_50 , V_22 -> V_61 ) ;
}
}
V_79 += V_22 -> V_94 ;
if ( F_42 ( V_47 ) -> V_60 ) {
if ( ( ! V_22 -> V_95 ) && ( ! V_22 -> V_96 ) ) {
F_61 ( V_22 , V_53 ,
L_12 ,
V_22 -> V_54 ) ;
V_22 -> V_96 = 1 ;
F_64 ( V_22 , V_8 -> V_38 ) ;
}
} else {
if ( V_22 -> V_97 ) {
F_65 ( V_22 , V_53 ,
L_13 ,
V_22 -> V_54 ) ;
F_47 ( & V_22 -> V_55 . V_68 ) ;
goto V_73;
}
if ( ( ! V_22 -> V_95 ) && ( V_22 -> V_96 ) ) {
F_61 ( V_22 , V_53 ,
L_14 ,
V_22 -> V_54 ) ;
V_22 -> V_96 = 0 ;
F_64 ( V_22 , V_8 -> V_38 ) ;
} else if ( V_22 -> V_96 ) {
F_65 ( V_22 , V_53 ,
L_13 ,
V_22 -> V_54 ) ;
F_47 ( & V_22 -> V_55 . V_68 ) ;
goto V_73;
}
}
if ( V_8 -> V_38 == V_87 ) {
if ( V_81 & V_98 ) {
V_82 = F_62 ( * ( V_89 * ) V_79 ) ;
V_79 += 2 + V_82 ;
}
} else
V_79 += V_22 -> V_82 ;
V_82 = V_79 - V_80 ;
if ( ! F_66 ( V_47 , V_82 ) )
goto V_73;
F_67 ( V_47 , V_82 ) ;
if ( F_60 )
if ( (* F_60)( V_47 ) )
goto V_73;
F_42 ( V_47 ) -> V_57 = V_57 ;
F_42 ( V_47 ) -> V_67 = V_66 +
( V_22 -> V_74 ? V_22 -> V_74 : V_99 ) ;
if ( F_42 ( V_47 ) -> V_60 ) {
if ( F_57 ( V_22 , V_47 ) )
goto V_73;
} else {
F_58 ( & V_22 -> V_51 , V_47 ) ;
}
F_53 ( V_22 ) ;
return;
V_73:
F_47 ( & V_22 -> V_55 . V_69 ) ;
F_52 ( V_47 ) ;
if ( V_22 -> V_64 )
(* V_22 -> V_64 )( V_22 ) ;
}
int F_68 ( struct V_20 * V_22 )
{
struct V_46 * V_47 = NULL ;
F_2 ( ! V_22 ) ;
F_2 ( V_22 -> V_100 != V_101 ) ;
while ( ( V_47 = F_69 ( & V_22 -> V_51 ) ) ) {
F_47 ( & V_22 -> V_55 . V_69 ) ;
F_52 ( V_47 ) ;
if ( V_22 -> V_64 )
(* V_22 -> V_64 )( V_22 ) ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_8 , struct V_46 * V_47 ,
int (* F_60)( struct V_46 * V_47 ) )
{
struct V_20 * V_22 = NULL ;
unsigned char * V_79 , * V_80 ;
T_2 V_81 ;
T_1 V_45 , V_12 ;
T_2 V_38 ;
int V_57 ;
F_67 ( V_47 , sizeof( struct V_102 ) ) ;
if ( ! F_66 ( V_47 , V_103 ) ) {
F_61 ( V_8 , V_85 ,
L_15 ,
V_8 -> V_54 , V_47 -> V_104 ) ;
goto error;
}
if ( V_8 -> V_105 & V_85 ) {
V_57 = F_71 ( 32u , V_47 -> V_104 ) ;
if ( ! F_66 ( V_47 , V_57 ) )
goto error;
F_72 ( L_16 , V_8 -> V_54 ) ;
F_73 ( L_17 , V_106 , V_47 -> V_107 , V_57 ) ;
}
V_80 = V_79 = V_47 -> V_107 ;
V_81 = F_62 ( * ( V_89 * ) V_79 ) ;
V_38 = V_81 & V_108 ;
if ( V_38 != V_8 -> V_38 ) {
F_61 ( V_8 , V_85 ,
L_18 ,
V_8 -> V_54 , V_38 , V_8 -> V_38 ) ;
goto error;
}
V_57 = V_47 -> V_104 ;
if ( V_81 & V_109 ) {
F_45 ( V_8 , V_85 ,
L_19 ,
V_8 -> V_54 , V_57 ) ;
goto error;
}
V_79 += 2 ;
if ( V_8 -> V_38 == V_87 ) {
if ( V_81 & V_110 )
V_79 += 2 ;
V_45 = F_62 ( * ( V_89 * ) V_79 ) ;
V_79 += 2 ;
V_12 = F_62 ( * ( V_89 * ) V_79 ) ;
V_79 += 2 ;
} else {
V_79 += 2 ;
V_45 = V_8 -> V_45 ;
V_12 = F_63 ( * ( V_93 * ) V_79 ) ;
V_79 += 4 ;
}
V_22 = F_27 ( V_8 -> V_5 , V_8 , V_12 , true ) ;
if ( ! V_22 || ! V_22 -> V_63 ) {
if ( V_22 ) {
if ( V_22 -> V_64 )
V_22 -> V_64 ( V_22 ) ;
F_74 ( V_22 ) ;
}
F_61 ( V_8 , V_85 ,
L_20 ,
V_8 -> V_54 , V_45 , V_12 ) ;
goto error;
}
F_59 ( V_22 , V_47 , V_79 , V_80 , V_81 , V_57 , F_60 ) ;
F_74 ( V_22 ) ;
return 0 ;
error:
F_75 ( V_47 , sizeof( struct V_102 ) ) ;
return 1 ;
}
int F_76 ( struct V_2 * V_3 , struct V_46 * V_47 )
{
struct V_1 * V_8 ;
V_8 = F_15 ( V_3 ) ;
if ( V_8 == NULL )
goto V_111;
F_45 ( V_8 , V_85 , L_21 ,
V_8 -> V_54 , V_47 -> V_104 ) ;
if ( F_70 ( V_8 , V_47 , V_8 -> V_112 ) )
goto V_113;
F_17 ( V_3 ) ;
return 0 ;
V_113:
F_17 ( V_3 ) ;
V_111:
return 1 ;
}
static int F_77 ( struct V_20 * V_22 , void * V_114 )
{
struct V_1 * V_8 = V_22 -> V_8 ;
V_89 * V_115 = V_114 ;
V_89 * V_80 = V_114 ;
T_2 V_116 = V_87 ;
T_1 V_45 = V_8 -> V_117 ;
T_1 V_12 = V_22 -> V_118 ;
if ( V_22 -> V_96 )
V_116 |= V_88 ;
* V_115 ++ = F_78 ( V_116 ) ;
* V_115 ++ = F_78 ( V_45 ) ;
* V_115 ++ = F_78 ( V_12 ) ;
if ( V_22 -> V_96 ) {
* V_115 ++ = F_78 ( V_22 -> V_50 ) ;
* V_115 ++ = 0 ;
V_22 -> V_50 ++ ;
V_22 -> V_50 &= 0xffff ;
F_45 ( V_22 , V_53 , L_22 ,
V_22 -> V_54 , V_22 -> V_50 ) ;
}
return V_115 - V_80 ;
}
static int F_79 ( struct V_20 * V_22 , void * V_114 )
{
struct V_1 * V_8 = V_22 -> V_8 ;
char * V_115 = V_114 ;
char * V_80 = V_115 ;
if ( V_8 -> V_119 == V_120 ) {
T_2 V_116 = V_39 ;
* ( ( V_89 * ) V_115 ) = F_78 ( V_116 ) ;
V_115 += 2 ;
* ( ( V_89 * ) V_115 ) = 0 ;
V_115 += 2 ;
}
* ( ( V_93 * ) V_115 ) = F_80 ( V_22 -> V_118 ) ;
V_115 += 4 ;
if ( V_22 -> V_121 ) {
memcpy ( V_115 , & V_22 -> V_122 [ 0 ] , V_22 -> V_121 ) ;
V_115 += V_22 -> V_121 ;
}
if ( V_22 -> V_94 ) {
if ( V_22 -> V_90 == V_91 ) {
T_1 V_92 = 0 ;
if ( V_22 -> V_96 ) {
V_92 = 0x40000000 | V_22 -> V_50 ;
V_22 -> V_50 ++ ;
V_22 -> V_50 &= 0xffffff ;
F_45 ( V_22 , V_53 ,
L_22 ,
V_22 -> V_54 , V_22 -> V_50 ) ;
}
* ( ( V_93 * ) V_115 ) = F_80 ( V_92 ) ;
}
V_115 += V_22 -> V_94 ;
}
if ( V_22 -> V_82 )
V_115 += V_22 -> V_82 ;
return V_115 - V_80 ;
}
static int F_81 ( struct V_20 * V_22 , struct V_46 * V_47 ,
struct V_123 * V_124 , T_3 V_125 )
{
struct V_1 * V_8 = V_22 -> V_8 ;
unsigned int V_104 = V_47 -> V_104 ;
int error ;
if ( V_22 -> V_96 )
F_45 ( V_22 , V_85 , L_23 ,
V_22 -> V_54 , V_125 , V_22 -> V_50 - 1 ) ;
else
F_45 ( V_22 , V_85 , L_24 ,
V_22 -> V_54 , V_125 ) ;
if ( V_22 -> V_105 & V_85 ) {
int V_126 = ( V_8 -> V_119 == V_120 ) ? sizeof( struct V_102 ) : 0 ;
unsigned char * V_127 = V_47 -> V_107 + V_126 ;
F_72 ( L_25 , V_22 -> V_54 ) ;
F_73 ( L_17 , V_106 ,
V_127 , F_82 ( T_3 , 32 , V_104 - V_126 ) ) ;
}
V_47 -> V_128 = 1 ;
#if F_83 ( V_129 )
if ( V_8 -> V_2 -> V_130 == V_131 && ! V_8 -> V_132 )
error = F_84 ( V_8 -> V_2 , V_47 , NULL ) ;
else
#endif
error = F_85 ( V_8 -> V_2 , V_47 , V_124 ) ;
if ( error >= 0 ) {
F_47 ( & V_8 -> V_55 . V_133 ) ;
F_51 ( V_104 , & V_8 -> V_55 . V_134 ) ;
F_47 ( & V_22 -> V_55 . V_133 ) ;
F_51 ( V_104 , & V_22 -> V_55 . V_134 ) ;
} else {
F_47 ( & V_8 -> V_55 . V_135 ) ;
F_47 ( & V_22 -> V_55 . V_135 ) ;
}
return 0 ;
}
int F_86 ( struct V_20 * V_22 , struct V_46 * V_47 , int V_136 )
{
int V_125 = V_47 -> V_104 ;
struct V_1 * V_8 = V_22 -> V_8 ;
struct V_2 * V_3 = V_8 -> V_2 ;
struct V_123 * V_124 ;
struct V_102 * V_137 ;
struct V_138 * V_139 ;
int V_140 ;
int V_126 = ( V_8 -> V_119 == V_120 ) ? sizeof( struct V_102 ) : 0 ;
int V_141 ;
int V_142 = V_143 ;
V_140 = V_144 + sizeof( struct V_145 ) +
V_126 + V_136 ;
if ( F_87 ( V_47 , V_140 ) ) {
F_52 ( V_47 ) ;
return V_146 ;
}
V_22 -> V_147 ( V_22 , F_75 ( V_47 , V_136 ) ) ;
memset ( & ( F_88 ( V_47 ) -> V_148 ) , 0 , sizeof( F_88 ( V_47 ) -> V_148 ) ) ;
F_88 ( V_47 ) -> V_116 &= ~ ( V_149 | V_150 |
V_151 ) ;
F_89 ( V_47 ) ;
F_90 ( V_3 ) ;
if ( F_91 ( V_3 ) ) {
F_52 ( V_47 ) ;
V_142 = V_146 ;
goto V_152;
}
F_92 ( V_47 ) ;
F_93 ( V_47 , F_94 ( F_95 ( V_3 , 0 ) ) ) ;
V_139 = F_96 ( V_3 ) ;
V_124 = & V_139 -> V_153 . V_124 ;
switch ( V_8 -> V_119 ) {
case V_120 :
F_75 ( V_47 , sizeof( * V_137 ) ) ;
F_97 ( V_47 ) ;
V_137 = F_98 ( V_47 ) ;
V_137 -> V_154 = V_139 -> V_155 ;
V_137 -> V_156 = V_139 -> V_157 ;
V_141 = V_126 + V_136 + V_125 ;
V_137 -> V_104 = F_78 ( V_141 ) ;
#if F_83 ( V_129 )
if ( V_3 -> V_130 == V_131 && ! V_8 -> V_132 )
F_99 ( F_100 ( V_3 ) ,
V_47 , & F_101 ( V_3 ) -> V_158 ,
& V_3 -> V_159 , V_141 ) ;
else
#endif
F_102 ( V_3 -> V_160 , V_47 , V_139 -> V_161 ,
V_139 -> V_162 , V_141 ) ;
break;
case V_163 :
break;
}
F_81 ( V_22 , V_47 , V_124 , V_125 ) ;
V_152:
F_103 ( V_3 ) ;
return V_142 ;
}
static void F_104 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = V_1 ( V_3 ) ;
struct V_5 * V_11 ;
if ( V_8 == NULL )
goto V_164;
F_61 ( V_8 , V_165 , L_26 , V_8 -> V_54 ) ;
switch ( V_8 -> V_119 ) {
case V_120 :
( F_105 ( V_3 ) ) -> V_166 = 0 ;
( F_105 ( V_3 ) ) -> V_167 = NULL ;
( F_105 ( V_3 ) ) -> V_168 = NULL ;
break;
case V_163 :
break;
}
V_3 -> V_169 = V_8 -> V_170 ;
V_3 -> V_4 = NULL ;
V_8 -> V_2 = NULL ;
V_11 = F_1 ( V_8 -> V_5 ) ;
F_33 ( & V_11 -> V_171 ) ;
F_106 ( & V_8 -> V_172 ) ;
F_35 ( & V_11 -> V_171 ) ;
F_107 ( & V_173 ) ;
F_108 ( V_8 ) ;
F_109 ( V_8 ) ;
if ( V_3 -> V_169 )
(* V_3 -> V_169 )( V_3 ) ;
V_164:
return;
}
void F_108 ( struct V_1 * V_8 )
{
int V_29 ;
struct V_174 * V_175 ;
struct V_174 * V_49 ;
struct V_20 * V_22 ;
F_2 ( V_8 == NULL ) ;
F_61 ( V_8 , V_165 , L_27 ,
V_8 -> V_54 ) ;
F_32 ( & V_8 -> V_25 ) ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
V_176:
F_110 (walk, tmp, &tunnel->session_hlist[hash]) {
V_22 = F_111 ( V_175 , struct V_20 , V_43 ) ;
F_61 ( V_22 , V_165 ,
L_28 , V_22 -> V_54 ) ;
F_112 ( & V_22 -> V_43 ) ;
if ( V_22 -> V_27 != NULL )
(* V_22 -> V_27 )( V_22 ) ;
F_37 ( & V_8 -> V_25 ) ;
F_113 ( V_22 ) ;
F_68 ( V_22 ) ;
if ( V_22 -> V_177 != NULL )
(* V_22 -> V_177 )( V_22 ) ;
if ( V_22 -> V_64 != NULL )
(* V_22 -> V_64 )( V_22 ) ;
F_74 ( V_22 ) ;
F_32 ( & V_8 -> V_25 ) ;
goto V_176;
}
}
F_37 ( & V_8 -> V_25 ) ;
}
static void F_114 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_15 ( V_3 ) ;
if ( V_8 ) {
F_108 ( V_8 ) ;
F_17 ( V_3 ) ;
}
}
static void F_8 ( struct V_1 * V_8 )
{
F_2 ( F_115 ( & V_8 -> V_9 ) != 0 ) ;
F_2 ( V_8 -> V_2 != NULL ) ;
F_61 ( V_8 , V_165 , L_29 , V_8 -> V_54 ) ;
F_116 ( V_8 , V_178 ) ;
}
static void F_117 ( struct V_179 * V_180 )
{
struct V_1 * V_8 = NULL ;
struct V_16 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
V_8 = F_118 ( V_180 , struct V_1 , V_181 ) ;
F_108 ( V_8 ) ;
V_3 = F_11 ( V_8 ) ;
if ( ! V_3 )
goto V_17;
V_2 = V_3 -> V_19 ;
if ( V_8 -> V_18 >= 0 ) {
if ( V_2 )
F_119 ( V_2 , 2 ) ;
} else {
if ( V_2 ) {
F_120 ( V_2 , V_182 ) ;
F_121 ( V_2 ) ;
}
}
F_14 ( V_3 ) ;
V_17:
F_109 ( V_8 ) ;
}
static int F_122 ( struct V_6 * V_6 ,
T_1 V_45 ,
T_1 V_117 ,
struct V_183 * V_184 ,
struct V_16 * * V_185 )
{
int V_15 = - V_186 ;
struct V_16 * V_2 = NULL ;
struct V_187 V_188 ;
switch ( V_184 -> V_119 ) {
case V_120 :
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
#if F_83 ( V_129 )
if ( V_184 -> V_189 && V_184 -> V_190 ) {
V_188 . V_191 = V_192 ;
memcpy ( & V_188 . V_189 , V_184 -> V_189 ,
sizeof( V_188 . V_189 ) ) ;
memcpy ( & V_188 . V_190 , V_184 -> V_190 ,
sizeof( V_188 . V_190 ) ) ;
V_188 . V_193 =
! V_184 -> V_194 ;
V_188 . V_195 =
! V_184 -> V_196 ;
} else
#endif
{
V_188 . V_191 = V_197 ;
V_188 . V_198 = V_184 -> V_198 ;
V_188 . V_199 = V_184 -> V_199 ;
V_188 . V_200 = V_184 -> V_200 ;
}
V_188 . V_201 = F_78 ( V_184 -> V_201 ) ;
V_188 . V_202 = F_78 ( V_184 -> V_202 ) ;
V_15 = F_123 ( V_6 , & V_188 , & V_2 ) ;
if ( V_15 < 0 )
goto V_17;
break;
case V_163 :
#if F_83 ( V_129 )
if ( V_184 -> V_189 && V_184 -> V_190 ) {
struct V_203 V_204 = { 0 } ;
V_15 = F_124 ( V_6 , V_192 , V_205 ,
V_206 , & V_2 ) ;
if ( V_15 < 0 )
goto V_17;
V_204 . V_207 = V_192 ;
memcpy ( & V_204 . V_208 , V_184 -> V_189 ,
sizeof( V_204 . V_208 ) ) ;
V_204 . V_209 = V_45 ;
V_15 = F_125 ( V_2 , (struct V_210 * ) & V_204 ,
sizeof( V_204 ) ) ;
if ( V_15 < 0 )
goto V_17;
V_204 . V_207 = V_192 ;
memcpy ( & V_204 . V_208 , V_184 -> V_190 ,
sizeof( V_204 . V_208 ) ) ;
V_204 . V_209 = V_117 ;
V_15 = F_126 ( V_2 ,
(struct V_210 * ) & V_204 ,
sizeof( V_204 ) , 0 ) ;
if ( V_15 < 0 )
goto V_17;
} else
#endif
{
struct V_211 V_212 = { 0 } ;
V_15 = F_124 ( V_6 , V_197 , V_205 ,
V_206 , & V_2 ) ;
if ( V_15 < 0 )
goto V_17;
V_212 . V_207 = V_197 ;
V_212 . V_208 = V_184 -> V_198 ;
V_212 . V_209 = V_45 ;
V_15 = F_125 ( V_2 , (struct V_210 * ) & V_212 ,
sizeof( V_212 ) ) ;
if ( V_15 < 0 )
goto V_17;
V_212 . V_207 = V_197 ;
V_212 . V_208 = V_184 -> V_199 ;
V_212 . V_209 = V_117 ;
V_15 = F_126 ( V_2 , (struct V_210 * ) & V_212 ,
sizeof( V_212 ) , 0 ) ;
if ( V_15 < 0 )
goto V_17;
}
break;
default:
goto V_17;
}
V_17:
* V_185 = V_2 ;
if ( ( V_15 < 0 ) && V_2 ) {
F_120 ( V_2 , V_182 ) ;
F_121 ( V_2 ) ;
* V_185 = NULL ;
}
return V_15 ;
}
int F_127 ( struct V_6 * V_6 , int V_18 , int V_38 , T_1 V_45 , T_1 V_117 , struct V_183 * V_184 , struct V_1 * * V_213 )
{
struct V_1 * V_8 = NULL ;
int V_15 ;
struct V_16 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
struct V_5 * V_11 ;
enum V_214 V_119 = V_120 ;
if ( V_18 < 0 ) {
V_15 = F_122 ( V_6 , V_45 , V_117 ,
V_184 , & V_2 ) ;
if ( V_15 < 0 )
goto V_15;
} else {
V_2 = F_12 ( V_18 , & V_15 ) ;
if ( ! V_2 ) {
F_128 ( L_30 ,
V_45 , V_18 , V_15 ) ;
V_15 = - V_215 ;
goto V_15;
}
if ( ! F_129 ( F_130 ( V_2 -> V_3 ) , V_6 ) ) {
F_128 ( L_31 , V_45 ) ;
V_15 = - V_186 ;
goto V_15;
}
}
V_3 = V_2 -> V_3 ;
if ( V_184 != NULL )
V_119 = V_184 -> V_119 ;
switch ( V_119 ) {
case V_120 :
V_15 = - V_216 ;
if ( V_3 -> V_217 != V_218 ) {
F_128 ( L_32 ,
V_45 , V_18 , V_3 -> V_217 , V_218 ) ;
goto V_15;
}
break;
case V_163 :
V_15 = - V_216 ;
if ( V_3 -> V_217 != V_206 ) {
F_128 ( L_32 ,
V_45 , V_18 , V_3 -> V_217 , V_206 ) ;
goto V_15;
}
break;
}
V_8 = V_1 ( V_3 ) ;
if ( V_8 != NULL ) {
V_15 = - V_219 ;
goto V_15;
}
V_8 = F_131 ( sizeof( struct V_1 ) , V_220 ) ;
if ( V_8 == NULL ) {
V_15 = - V_221 ;
goto V_15;
}
V_8 -> V_38 = V_38 ;
V_8 -> V_45 = V_45 ;
V_8 -> V_117 = V_117 ;
V_8 -> V_105 = V_222 ;
V_8 -> V_100 = V_223 ;
sprintf ( & V_8 -> V_54 [ 0 ] , L_33 , V_45 ) ;
F_132 ( & V_8 -> V_25 ) ;
V_8 -> V_5 = V_6 ;
V_11 = F_1 ( V_6 ) ;
if ( V_184 != NULL )
V_8 -> V_105 = V_184 -> V_105 ;
#if F_83 ( V_129 )
if ( V_3 -> V_130 == V_131 ) {
struct V_224 * V_225 = F_101 ( V_3 ) ;
if ( F_133 ( & V_225 -> V_158 ) &&
F_133 ( & V_3 -> V_159 ) ) {
struct V_138 * V_139 = F_96 ( V_3 ) ;
V_8 -> V_132 = true ;
V_139 -> V_161 = V_225 -> V_158 . V_226 [ 3 ] ;
V_139 -> V_227 = V_3 -> V_228 . V_226 [ 3 ] ;
V_139 -> V_162 = V_3 -> V_159 . V_226 [ 3 ] ;
} else {
V_8 -> V_132 = false ;
}
}
#endif
V_8 -> V_119 = V_119 ;
if ( V_119 == V_120 ) {
struct V_229 V_230 = { } ;
V_230 . V_4 = V_8 ;
V_230 . V_166 = V_231 ;
V_230 . V_167 = F_76 ;
V_230 . V_168 = F_114 ;
F_134 ( V_6 , V_2 , & V_230 ) ;
} else {
V_3 -> V_4 = V_8 ;
}
V_8 -> V_170 = V_3 -> V_169 ;
V_3 -> V_169 = & F_104 ;
V_8 -> V_2 = V_3 ;
V_8 -> V_18 = V_18 ;
F_135 ( & V_3 -> V_232 . V_233 , & V_234 , L_34 ) ;
V_3 -> V_235 = V_236 ;
F_136 ( & V_8 -> V_181 , F_117 ) ;
F_137 ( & V_8 -> V_172 ) ;
F_5 ( & V_173 ) ;
F_138 ( V_8 ) ;
F_33 ( & V_11 -> V_171 ) ;
F_139 ( & V_8 -> V_172 , & V_11 -> V_237 ) ;
F_35 ( & V_11 -> V_171 ) ;
V_15 = 0 ;
V_15:
if ( V_213 )
* V_213 = V_8 ;
if ( V_2 && V_2 -> V_238 )
F_16 ( V_2 ) ;
return V_15 ;
}
int F_140 ( struct V_1 * V_8 )
{
F_138 ( V_8 ) ;
if ( false == F_141 ( V_239 , & V_8 -> V_181 ) ) {
F_109 ( V_8 ) ;
return 1 ;
}
return 0 ;
}
void F_142 ( struct V_20 * V_22 )
{
struct V_1 * V_8 = V_22 -> V_8 ;
F_2 ( F_115 ( & V_22 -> V_9 ) != 0 ) ;
if ( V_8 ) {
F_2 ( V_8 -> V_100 != V_223 ) ;
if ( V_22 -> V_12 != 0 )
F_107 ( & V_240 ) ;
F_17 ( V_8 -> V_2 ) ;
V_22 -> V_8 = NULL ;
F_109 ( V_8 ) ;
}
F_143 ( V_22 ) ;
}
void F_113 ( struct V_20 * V_22 )
{
struct V_1 * V_8 = V_22 -> V_8 ;
if ( V_8 ) {
F_32 ( & V_8 -> V_25 ) ;
F_112 ( & V_22 -> V_43 ) ;
F_37 ( & V_8 -> V_25 ) ;
if ( V_8 -> V_38 != V_87 ) {
struct V_5 * V_11 = F_1 ( V_8 -> V_5 ) ;
F_33 ( & V_11 -> V_40 ) ;
F_144 ( & V_22 -> V_42 ) ;
F_35 ( & V_11 -> V_40 ) ;
F_145 () ;
}
}
}
int F_146 ( struct V_20 * V_22 )
{
if ( V_22 -> V_27 )
(* V_22 -> V_27 )( V_22 ) ;
F_113 ( V_22 ) ;
F_68 ( V_22 ) ;
if ( V_22 -> V_177 != NULL )
(* V_22 -> V_177 )( V_22 ) ;
if ( V_22 -> V_64 )
(* V_22 -> V_64 )( V_22 ) ;
F_74 ( V_22 ) ;
return 0 ;
}
void F_64 ( struct V_20 * V_22 , int V_38 )
{
if ( V_38 == V_87 ) {
V_22 -> V_136 = 6 ;
if ( V_22 -> V_96 )
V_22 -> V_136 += 4 ;
} else {
V_22 -> V_136 = 4 + V_22 -> V_121 + V_22 -> V_94 + V_22 -> V_82 ;
if ( V_22 -> V_8 -> V_119 == V_120 )
V_22 -> V_136 += 4 ;
}
}
struct V_20 * F_147 ( int V_241 , struct V_1 * V_8 , T_1 V_12 , T_1 V_118 , struct V_242 * V_184 )
{
struct V_20 * V_22 ;
int V_15 ;
V_22 = F_131 ( sizeof( struct V_20 ) + V_241 , V_220 ) ;
if ( V_22 != NULL ) {
V_22 -> V_100 = V_101 ;
V_22 -> V_8 = V_8 ;
V_22 -> V_12 = V_12 ;
V_22 -> V_118 = V_118 ;
V_22 -> V_61 = 0 ;
if ( V_8 -> V_38 == V_87 )
V_22 -> V_62 = 0xffff ;
else
V_22 -> V_62 = 0xffffff ;
V_22 -> V_72 = V_22 -> V_62 / 2 ;
V_22 -> V_78 = 4 ;
V_22 -> V_70 = 1 ;
sprintf ( & V_22 -> V_54 [ 0 ] , L_35 ,
V_8 -> V_45 , V_22 -> V_12 ) ;
F_148 ( & V_22 -> V_51 ) ;
F_149 ( & V_22 -> V_43 ) ;
F_149 ( & V_22 -> V_42 ) ;
V_22 -> V_105 = V_8 -> V_105 ;
if ( V_184 ) {
V_22 -> V_243 = V_184 -> V_244 ;
V_22 -> V_105 = V_184 -> V_105 ;
V_22 -> V_245 = V_184 -> V_245 ;
V_22 -> V_246 = V_184 -> V_246 ;
V_22 -> V_96 = V_184 -> V_96 ;
V_22 -> V_97 = V_184 -> V_97 ;
V_22 -> V_95 = V_184 -> V_95 ;
V_22 -> V_74 = V_184 -> V_74 ;
V_22 -> V_82 = V_184 -> V_82 ;
V_22 -> V_90 = V_184 -> V_90 ;
V_22 -> V_94 = V_184 -> V_94 ;
V_22 -> V_121 = V_184 -> V_121 ;
memcpy ( & V_22 -> V_122 [ 0 ] , & V_184 -> V_122 [ 0 ] , V_184 -> V_121 ) ;
V_22 -> V_83 = V_184 -> V_83 ;
memcpy ( & V_22 -> V_84 [ 0 ] , & V_184 -> V_84 [ 0 ] , V_184 -> V_83 ) ;
}
if ( V_8 -> V_38 == V_87 )
V_22 -> V_147 = F_77 ;
else
V_22 -> V_147 = F_79 ;
F_64 ( V_22 , V_8 -> V_38 ) ;
V_15 = F_31 ( V_8 , V_22 ) ;
if ( V_15 ) {
F_143 ( V_22 ) ;
return F_150 ( V_15 ) ;
}
F_28 ( V_22 ) ;
F_138 ( V_8 ) ;
F_13 ( V_8 -> V_2 ) ;
if ( V_22 -> V_12 != 0 )
F_5 ( & V_240 ) ;
return V_22 ;
}
return F_150 ( - V_221 ) ;
}
static T_4 int F_151 ( struct V_6 * V_6 )
{
struct V_5 * V_11 = F_3 ( V_6 , V_7 ) ;
int V_29 ;
F_137 ( & V_11 -> V_237 ) ;
F_152 ( & V_11 -> V_171 ) ;
for ( V_29 = 0 ; V_29 < V_33 ; V_29 ++ )
F_153 ( & V_11 -> V_13 [ V_29 ] ) ;
F_152 ( & V_11 -> V_40 ) ;
return 0 ;
}
static T_5 void F_154 ( struct V_6 * V_6 )
{
struct V_5 * V_11 = F_1 ( V_6 ) ;
struct V_1 * V_8 = NULL ;
F_19 () ;
F_39 (tunnel, &pn->l2tp_tunnel_list, list) {
( void ) F_140 ( V_8 ) ;
}
F_21 () ;
F_155 ( V_239 ) ;
F_156 () ;
}
static int T_6 F_157 ( void )
{
int V_247 = 0 ;
V_247 = F_158 ( & V_248 ) ;
if ( V_247 )
goto V_17;
V_239 = F_159 ( L_36 , V_249 , 0 ) ;
if ( ! V_239 ) {
F_128 ( L_37 ) ;
F_160 ( & V_248 ) ;
V_247 = - V_221 ;
goto V_17;
}
F_161 ( L_38 , V_250 ) ;
V_17:
return V_247 ;
}
static void T_7 F_162 ( void )
{
F_160 ( & V_248 ) ;
if ( V_239 ) {
F_163 ( V_239 ) ;
V_239 = NULL ;
}
}
