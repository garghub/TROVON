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
struct V_20 * F_27 ( struct V_1 * V_8 , int V_26 )
{
int V_27 ;
struct V_20 * V_22 ;
int V_28 = 0 ;
F_24 ( & V_8 -> V_25 ) ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
F_25 (session, &tunnel->session_hlist[hash], hlist) {
if ( ++ V_28 > V_26 ) {
F_26 ( & V_8 -> V_25 ) ;
return V_22 ;
}
}
}
F_26 ( & V_8 -> V_25 ) ;
return NULL ;
}
struct V_20 * F_28 ( struct V_6 * V_6 , char * V_30 )
{
struct V_5 * V_11 = F_1 ( V_6 ) ;
int V_27 ;
struct V_20 * V_22 ;
F_19 () ;
for ( V_27 = 0 ; V_27 < V_31 ; V_27 ++ ) {
F_20 (session, &pn->l2tp_session_hlist[hash], global_hlist) {
if ( ! strcmp ( V_22 -> V_30 , V_30 ) ) {
F_21 () ;
return V_22 ;
}
}
}
F_21 () ;
return NULL ;
}
struct V_1 * F_29 ( struct V_6 * V_6 , T_1 V_32 )
{
struct V_1 * V_8 ;
struct V_5 * V_11 = F_1 ( V_6 ) ;
F_19 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( V_8 -> V_32 == V_32 ) {
F_21 () ;
return V_8 ;
}
}
F_21 () ;
return NULL ;
}
struct V_1 * F_31 ( struct V_6 * V_6 , int V_26 )
{
struct V_5 * V_11 = F_1 ( V_6 ) ;
struct V_1 * V_8 ;
int V_28 = 0 ;
F_19 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( ++ V_28 > V_26 ) {
F_21 () ;
return V_8 ;
}
}
F_21 () ;
return NULL ;
}
static void F_32 ( struct V_20 * V_22 , struct V_33 * V_34 )
{
struct V_33 * V_35 ;
struct V_33 * V_36 ;
T_1 V_37 = F_33 ( V_34 ) -> V_37 ;
F_34 ( & V_22 -> V_38 . V_39 ) ;
F_35 (&session->reorder_q, skbp, tmp) {
if ( F_33 ( V_35 ) -> V_37 > V_37 ) {
F_36 ( & V_22 -> V_38 , V_35 , V_34 ) ;
F_37 ( V_22 , V_40 ,
L_1 ,
V_22 -> V_41 , V_37 , F_33 ( V_35 ) -> V_37 ,
F_38 ( & V_22 -> V_38 ) ) ;
F_39 ( & V_22 -> V_42 . V_43 ) ;
goto V_17;
}
}
F_40 ( & V_22 -> V_38 , V_34 ) ;
V_17:
F_41 ( & V_22 -> V_38 . V_39 ) ;
}
static void F_42 ( struct V_20 * V_22 , struct V_33 * V_34 )
{
struct V_1 * V_8 = V_22 -> V_8 ;
int V_44 = F_33 ( V_34 ) -> V_44 ;
F_43 ( V_34 ) ;
F_39 ( & V_8 -> V_42 . V_45 ) ;
F_44 ( V_44 , & V_8 -> V_42 . V_46 ) ;
F_39 ( & V_22 -> V_42 . V_45 ) ;
F_44 ( V_44 , & V_22 -> V_42 . V_46 ) ;
if ( F_33 ( V_34 ) -> V_47 ) {
V_22 -> V_48 ++ ;
V_22 -> V_48 &= V_22 -> V_49 ;
F_37 ( V_22 , V_40 , L_2 ,
V_22 -> V_41 , V_22 -> V_48 ) ;
}
if ( V_22 -> V_50 != NULL )
(* V_22 -> V_50 )( V_22 , V_34 , F_33 ( V_34 ) -> V_44 ) ;
else
F_45 ( V_34 ) ;
if ( V_22 -> V_51 )
(* V_22 -> V_51 )( V_22 ) ;
}
static void F_46 ( struct V_20 * V_22 )
{
struct V_33 * V_34 ;
struct V_33 * V_36 ;
V_52:
F_34 ( & V_22 -> V_38 . V_39 ) ;
F_35 (&session->reorder_q, skb, tmp) {
if ( F_47 ( V_53 , F_33 ( V_34 ) -> V_54 ) ) {
F_39 ( & V_22 -> V_42 . V_55 ) ;
F_39 ( & V_22 -> V_42 . V_56 ) ;
F_37 ( V_22 , V_40 ,
L_3 ,
V_22 -> V_41 , F_33 ( V_34 ) -> V_37 ,
F_33 ( V_34 ) -> V_44 , V_22 -> V_48 ,
F_38 ( & V_22 -> V_38 ) ) ;
V_22 -> V_57 = 1 ;
F_48 ( V_34 , & V_22 -> V_38 ) ;
F_45 ( V_34 ) ;
if ( V_22 -> V_51 )
(* V_22 -> V_51 )( V_22 ) ;
continue;
}
if ( F_33 ( V_34 ) -> V_47 ) {
if ( V_22 -> V_57 ) {
F_37 ( V_22 , V_40 ,
L_4 ,
V_22 -> V_41 , V_22 -> V_48 ,
F_33 ( V_34 ) -> V_37 ) ;
V_22 -> V_57 = 0 ;
V_22 -> V_48 = F_33 ( V_34 ) -> V_37 ;
}
if ( F_33 ( V_34 ) -> V_37 != V_22 -> V_48 ) {
F_37 ( V_22 , V_40 ,
L_5 ,
V_22 -> V_41 , F_33 ( V_34 ) -> V_37 ,
F_33 ( V_34 ) -> V_44 , V_22 -> V_48 ,
F_38 ( & V_22 -> V_38 ) ) ;
goto V_17;
}
}
F_48 ( V_34 , & V_22 -> V_38 ) ;
F_41 ( & V_22 -> V_38 . V_39 ) ;
F_42 ( V_22 , V_34 ) ;
goto V_52;
}
V_17:
F_41 ( & V_22 -> V_38 . V_39 ) ;
}
static int F_49 ( struct V_20 * V_22 , T_1 V_48 )
{
T_1 V_58 ;
if ( V_48 >= V_22 -> V_48 )
V_58 = V_48 - V_22 -> V_48 ;
else
V_58 = ( V_22 -> V_49 + 1 ) - ( V_22 -> V_48 - V_48 ) ;
return V_58 < V_22 -> V_59 ;
}
static int F_50 ( struct V_20 * V_22 , struct V_33 * V_34 )
{
if ( ! F_49 ( V_22 , F_33 ( V_34 ) -> V_37 ) ) {
F_37 ( V_22 , V_40 ,
L_6 ,
V_22 -> V_41 , F_33 ( V_34 ) -> V_37 ,
F_33 ( V_34 ) -> V_44 , V_22 -> V_48 ) ;
goto V_60;
}
if ( V_22 -> V_61 != 0 ) {
F_32 ( V_22 , V_34 ) ;
goto V_17;
}
if ( F_33 ( V_34 ) -> V_37 == V_22 -> V_48 ) {
F_51 ( & V_22 -> V_38 , V_34 ) ;
} else {
T_1 V_62 = F_33 ( V_34 ) -> V_37 ;
T_1 V_63 = ( V_22 -> V_62 + 1 ) & V_22 -> V_49 ;
if ( V_62 == V_63 )
V_22 -> V_64 ++ ;
else
V_22 -> V_64 = 0 ;
V_22 -> V_62 = V_62 ;
if ( V_22 -> V_64 > V_22 -> V_65 ) {
V_22 -> V_57 = 1 ;
F_37 ( V_22 , V_40 ,
L_7 ,
V_22 -> V_41 , V_22 -> V_64 ) ;
}
if ( ! V_22 -> V_57 ) {
F_39 ( & V_22 -> V_42 . V_55 ) ;
F_37 ( V_22 , V_40 ,
L_8 ,
V_22 -> V_41 , F_33 ( V_34 ) -> V_37 ,
F_33 ( V_34 ) -> V_44 , V_22 -> V_48 ,
F_38 ( & V_22 -> V_38 ) ) ;
goto V_60;
}
F_51 ( & V_22 -> V_38 , V_34 ) ;
}
V_17:
return 0 ;
V_60:
return 1 ;
}
void F_52 ( struct V_20 * V_22 , struct V_33 * V_34 ,
unsigned char * V_66 , unsigned char * V_67 , T_2 V_68 ,
int V_44 , int (* F_53)( struct V_33 * V_34 ) )
{
struct V_1 * V_8 = V_22 -> V_8 ;
int V_69 ;
T_1 V_37 , V_48 ;
F_54 ( V_22 ) ;
if ( V_22 -> V_70 )
(* V_22 -> V_70 )( V_22 ) ;
if ( V_22 -> V_71 > 0 ) {
if ( memcmp ( V_66 , & V_22 -> V_72 [ 0 ] , V_22 -> V_71 ) ) {
F_55 ( V_8 , V_73 ,
L_9 ,
V_8 -> V_41 , V_8 -> V_32 ,
V_22 -> V_12 ) ;
F_39 ( & V_22 -> V_42 . V_74 ) ;
goto V_60;
}
V_66 += V_22 -> V_71 ;
}
V_37 = V_48 = 0 ;
F_33 ( V_34 ) -> V_47 = 0 ;
if ( V_8 -> V_75 == V_76 ) {
if ( V_68 & V_77 ) {
V_37 = F_56 ( * ( V_78 * ) V_66 ) ;
V_66 += 2 ;
V_48 = F_56 ( * ( V_78 * ) V_66 ) ;
V_66 += 2 ;
F_33 ( V_34 ) -> V_37 = V_37 ;
F_33 ( V_34 ) -> V_47 = 1 ;
F_37 ( V_22 , V_40 ,
L_10 ,
V_22 -> V_41 , V_37 , V_48 , V_22 -> V_48 ) ;
}
} else if ( V_22 -> V_79 == V_80 ) {
T_1 V_81 = F_57 ( * ( V_82 * ) V_66 ) ;
if ( V_81 & 0x40000000 ) {
V_37 = V_81 & 0x00ffffff ;
F_33 ( V_34 ) -> V_37 = V_37 ;
F_33 ( V_34 ) -> V_47 = 1 ;
F_37 ( V_22 , V_40 ,
L_11 ,
V_22 -> V_41 , V_37 , V_22 -> V_48 ) ;
}
}
V_66 += V_22 -> V_83 ;
if ( F_33 ( V_34 ) -> V_47 ) {
if ( ( ! V_22 -> V_84 ) && ( ! V_22 -> V_85 ) ) {
F_55 ( V_22 , V_40 ,
L_12 ,
V_22 -> V_41 ) ;
V_22 -> V_85 = - 1 ;
F_58 ( V_22 , V_8 -> V_75 ) ;
}
} else {
if ( V_22 -> V_86 ) {
F_59 ( V_22 , V_40 ,
L_13 ,
V_22 -> V_41 ) ;
F_39 ( & V_22 -> V_42 . V_55 ) ;
goto V_60;
}
if ( ( ! V_22 -> V_84 ) && ( V_22 -> V_85 ) ) {
F_55 ( V_22 , V_40 ,
L_14 ,
V_22 -> V_41 ) ;
V_22 -> V_85 = 0 ;
F_58 ( V_22 , V_8 -> V_75 ) ;
} else if ( V_22 -> V_85 ) {
F_59 ( V_22 , V_40 ,
L_13 ,
V_22 -> V_41 ) ;
F_39 ( & V_22 -> V_42 . V_55 ) ;
goto V_60;
}
}
if ( V_8 -> V_75 == V_76 ) {
if ( V_68 & V_87 ) {
V_69 = F_56 ( * ( V_78 * ) V_66 ) ;
V_66 += 2 + V_69 ;
}
} else
V_66 += V_22 -> V_69 ;
V_69 = V_66 - V_67 ;
if ( ! F_60 ( V_34 , V_69 ) )
goto V_60;
F_61 ( V_34 , V_69 ) ;
if ( F_53 )
if ( (* F_53)( V_34 ) )
goto V_60;
F_33 ( V_34 ) -> V_44 = V_44 ;
F_33 ( V_34 ) -> V_54 = V_53 +
( V_22 -> V_61 ? V_22 -> V_61 : V_88 ) ;
if ( F_33 ( V_34 ) -> V_47 ) {
if ( F_50 ( V_22 , V_34 ) )
goto V_60;
} else {
F_51 ( & V_22 -> V_38 , V_34 ) ;
}
F_46 ( V_22 ) ;
F_62 ( V_22 ) ;
return;
V_60:
F_39 ( & V_22 -> V_42 . V_56 ) ;
F_45 ( V_34 ) ;
if ( V_22 -> V_51 )
(* V_22 -> V_51 )( V_22 ) ;
F_62 ( V_22 ) ;
}
int F_63 ( struct V_20 * V_22 )
{
struct V_33 * V_34 = NULL ;
F_2 ( ! V_22 ) ;
F_2 ( V_22 -> V_89 != V_90 ) ;
while ( ( V_34 = F_64 ( & V_22 -> V_38 ) ) ) {
F_39 ( & V_22 -> V_42 . V_56 ) ;
F_45 ( V_34 ) ;
if ( V_22 -> V_51 )
(* V_22 -> V_51 )( V_22 ) ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_8 , struct V_33 * V_34 ,
int (* F_53)( struct V_33 * V_34 ) )
{
struct V_20 * V_22 = NULL ;
unsigned char * V_66 , * V_67 ;
T_2 V_68 ;
T_1 V_32 , V_12 ;
T_2 V_75 ;
int V_44 ;
F_61 ( V_34 , sizeof( struct V_91 ) ) ;
if ( ! F_60 ( V_34 , V_92 ) ) {
F_55 ( V_8 , V_73 ,
L_15 ,
V_8 -> V_41 , V_34 -> V_93 ) ;
goto error;
}
if ( V_8 -> V_94 & V_73 ) {
V_44 = F_66 ( 32u , V_34 -> V_93 ) ;
if ( ! F_60 ( V_34 , V_44 ) )
goto error;
F_67 ( L_16 , V_8 -> V_41 ) ;
F_68 ( L_17 , V_95 , V_34 -> V_96 , V_44 ) ;
}
V_67 = V_66 = V_34 -> V_96 ;
V_68 = F_56 ( * ( V_78 * ) V_66 ) ;
V_75 = V_68 & V_97 ;
if ( V_75 != V_8 -> V_75 ) {
F_55 ( V_8 , V_73 ,
L_18 ,
V_8 -> V_41 , V_75 , V_8 -> V_75 ) ;
goto error;
}
V_44 = V_34 -> V_93 ;
if ( V_68 & V_98 ) {
F_37 ( V_8 , V_73 ,
L_19 ,
V_8 -> V_41 , V_44 ) ;
goto error;
}
V_66 += 2 ;
if ( V_8 -> V_75 == V_76 ) {
if ( V_68 & V_99 )
V_66 += 2 ;
V_32 = F_56 ( * ( V_78 * ) V_66 ) ;
V_66 += 2 ;
V_12 = F_56 ( * ( V_78 * ) V_66 ) ;
V_66 += 2 ;
} else {
V_66 += 2 ;
V_32 = V_8 -> V_32 ;
V_12 = F_57 ( * ( V_82 * ) V_66 ) ;
V_66 += 4 ;
}
V_22 = F_23 ( V_8 -> V_5 , V_8 , V_12 ) ;
if ( ! V_22 || ! V_22 -> V_50 ) {
F_55 ( V_8 , V_73 ,
L_20 ,
V_8 -> V_41 , V_32 , V_12 ) ;
goto error;
}
F_52 ( V_22 , V_34 , V_66 , V_67 , V_68 , V_44 , F_53 ) ;
return 0 ;
error:
F_69 ( V_34 , sizeof( struct V_91 ) ) ;
return 1 ;
}
int F_70 ( struct V_2 * V_3 , struct V_33 * V_34 )
{
struct V_1 * V_8 ;
V_8 = F_15 ( V_3 ) ;
if ( V_8 == NULL )
goto V_100;
F_37 ( V_8 , V_73 , L_21 ,
V_8 -> V_41 , V_34 -> V_93 ) ;
if ( F_65 ( V_8 , V_34 , V_8 -> V_101 ) )
goto V_102;
F_17 ( V_3 ) ;
return 0 ;
V_102:
F_17 ( V_3 ) ;
V_100:
return 1 ;
}
static int F_71 ( struct V_20 * V_22 , void * V_103 )
{
struct V_1 * V_8 = V_22 -> V_8 ;
V_78 * V_104 = V_103 ;
V_78 * V_67 = V_103 ;
T_2 V_105 = V_76 ;
T_1 V_32 = V_8 -> V_106 ;
T_1 V_12 = V_22 -> V_107 ;
if ( V_22 -> V_85 )
V_105 |= V_77 ;
* V_104 ++ = F_72 ( V_105 ) ;
* V_104 ++ = F_72 ( V_32 ) ;
* V_104 ++ = F_72 ( V_12 ) ;
if ( V_22 -> V_85 ) {
* V_104 ++ = F_72 ( V_22 -> V_37 ) ;
* V_104 ++ = 0 ;
V_22 -> V_37 ++ ;
V_22 -> V_37 &= 0xffff ;
F_37 ( V_22 , V_40 , L_22 ,
V_22 -> V_41 , V_22 -> V_37 ) ;
}
return V_104 - V_67 ;
}
static int F_73 ( struct V_20 * V_22 , void * V_103 )
{
struct V_1 * V_8 = V_22 -> V_8 ;
char * V_104 = V_103 ;
char * V_67 = V_104 ;
if ( V_8 -> V_108 == V_109 ) {
T_2 V_105 = V_110 ;
* ( ( V_78 * ) V_104 ) = F_72 ( V_105 ) ;
V_104 += 2 ;
* ( ( V_78 * ) V_104 ) = 0 ;
V_104 += 2 ;
}
* ( ( V_82 * ) V_104 ) = F_74 ( V_22 -> V_107 ) ;
V_104 += 4 ;
if ( V_22 -> V_111 ) {
memcpy ( V_104 , & V_22 -> V_112 [ 0 ] , V_22 -> V_111 ) ;
V_104 += V_22 -> V_111 ;
}
if ( V_22 -> V_83 ) {
if ( V_22 -> V_79 == V_80 ) {
T_1 V_81 = 0 ;
if ( V_22 -> V_85 ) {
V_81 = 0x40000000 | V_22 -> V_37 ;
V_22 -> V_37 ++ ;
V_22 -> V_37 &= 0xffffff ;
F_37 ( V_22 , V_40 ,
L_22 ,
V_22 -> V_41 , V_22 -> V_37 ) ;
}
* ( ( V_82 * ) V_104 ) = F_74 ( V_81 ) ;
}
V_104 += V_22 -> V_83 ;
}
if ( V_22 -> V_69 )
V_104 += V_22 -> V_69 ;
return V_104 - V_67 ;
}
static int F_75 ( struct V_20 * V_22 , struct V_33 * V_34 ,
struct V_113 * V_114 , T_3 V_115 )
{
struct V_1 * V_8 = V_22 -> V_8 ;
unsigned int V_93 = V_34 -> V_93 ;
int error ;
if ( V_22 -> V_85 )
F_37 ( V_22 , V_73 , L_23 ,
V_22 -> V_41 , V_115 , V_22 -> V_37 - 1 ) ;
else
F_37 ( V_22 , V_73 , L_24 ,
V_22 -> V_41 , V_115 ) ;
if ( V_22 -> V_94 & V_73 ) {
int V_116 = ( V_8 -> V_108 == V_109 ) ? sizeof( struct V_91 ) : 0 ;
unsigned char * V_117 = V_34 -> V_96 + V_116 ;
F_67 ( L_25 , V_22 -> V_41 ) ;
F_68 ( L_17 , V_95 ,
V_117 , F_76 ( T_3 , 32 , V_93 - V_116 ) ) ;
}
V_34 -> V_118 = 1 ;
#if F_77 ( V_119 )
if ( V_8 -> V_2 -> V_120 == V_121 && ! V_8 -> V_122 )
error = F_78 ( V_8 -> V_2 , V_34 , NULL ) ;
else
#endif
error = F_79 ( V_8 -> V_2 , V_34 , V_114 ) ;
if ( error >= 0 ) {
F_39 ( & V_8 -> V_42 . V_123 ) ;
F_44 ( V_93 , & V_8 -> V_42 . V_124 ) ;
F_39 ( & V_22 -> V_42 . V_123 ) ;
F_44 ( V_93 , & V_22 -> V_42 . V_124 ) ;
} else {
F_39 ( & V_8 -> V_42 . V_125 ) ;
F_39 ( & V_22 -> V_42 . V_125 ) ;
}
return 0 ;
}
int F_80 ( struct V_20 * V_22 , struct V_33 * V_34 , int V_126 )
{
int V_115 = V_34 -> V_93 ;
struct V_1 * V_8 = V_22 -> V_8 ;
struct V_2 * V_3 = V_8 -> V_2 ;
struct V_113 * V_114 ;
struct V_91 * V_127 ;
struct V_128 * V_129 ;
int V_130 ;
int V_116 = ( V_8 -> V_108 == V_109 ) ? sizeof( struct V_91 ) : 0 ;
int V_131 ;
int V_132 = V_133 ;
V_130 = V_134 + sizeof( struct V_135 ) +
V_116 + V_126 ;
if ( F_81 ( V_34 , V_130 ) ) {
F_45 ( V_34 ) ;
return V_136 ;
}
V_22 -> V_137 ( V_22 , F_69 ( V_34 , V_126 ) ) ;
memset ( & ( F_82 ( V_34 ) -> V_138 ) , 0 , sizeof( F_82 ( V_34 ) -> V_138 ) ) ;
F_82 ( V_34 ) -> V_105 &= ~ ( V_139 | V_140 |
V_141 ) ;
F_83 ( V_34 ) ;
F_84 ( V_3 ) ;
if ( F_85 ( V_3 ) ) {
F_45 ( V_34 ) ;
V_132 = V_136 ;
goto V_142;
}
F_86 ( V_34 ) ;
F_87 ( V_34 , F_88 ( F_89 ( V_3 , 0 ) ) ) ;
V_129 = F_90 ( V_3 ) ;
V_114 = & V_129 -> V_143 . V_114 ;
switch ( V_8 -> V_108 ) {
case V_109 :
F_69 ( V_34 , sizeof( * V_127 ) ) ;
F_91 ( V_34 ) ;
V_127 = F_92 ( V_34 ) ;
V_127 -> V_144 = V_129 -> V_145 ;
V_127 -> V_146 = V_129 -> V_147 ;
V_131 = V_116 + V_126 + V_115 ;
V_127 -> V_93 = F_72 ( V_131 ) ;
#if F_77 ( V_119 )
if ( V_3 -> V_120 == V_121 && ! V_8 -> V_122 )
F_93 ( F_94 ( V_3 ) ,
V_34 , & F_95 ( V_3 ) -> V_148 ,
& V_3 -> V_149 , V_131 ) ;
else
#endif
F_96 ( V_3 -> V_150 , V_34 , V_129 -> V_151 ,
V_129 -> V_152 , V_131 ) ;
break;
case V_153 :
break;
}
F_75 ( V_22 , V_34 , V_114 , V_115 ) ;
V_142:
F_97 ( V_3 ) ;
return V_132 ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = V_1 ( V_3 ) ;
struct V_5 * V_11 ;
if ( V_8 == NULL )
goto V_154;
F_55 ( V_8 , V_155 , L_26 , V_8 -> V_41 ) ;
switch ( V_8 -> V_108 ) {
case V_109 :
( F_99 ( V_3 ) ) -> V_156 = 0 ;
( F_99 ( V_3 ) ) -> V_157 = NULL ;
( F_99 ( V_3 ) ) -> V_158 = NULL ;
break;
case V_153 :
break;
}
V_3 -> V_159 = V_8 -> V_160 ;
V_3 -> V_4 = NULL ;
V_8 -> V_2 = NULL ;
V_11 = F_1 ( V_8 -> V_5 ) ;
F_34 ( & V_11 -> V_161 ) ;
F_100 ( & V_8 -> V_162 ) ;
F_41 ( & V_11 -> V_161 ) ;
F_101 ( & V_163 ) ;
F_102 ( V_8 ) ;
F_103 ( V_8 ) ;
if ( V_3 -> V_159 )
(* V_3 -> V_159 )( V_3 ) ;
V_154:
return;
}
void F_102 ( struct V_1 * V_8 )
{
int V_27 ;
struct V_164 * V_165 ;
struct V_164 * V_36 ;
struct V_20 * V_22 ;
F_2 ( V_8 == NULL ) ;
F_55 ( V_8 , V_155 , L_27 ,
V_8 -> V_41 ) ;
F_104 ( & V_8 -> V_25 ) ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
V_166:
F_105 (walk, tmp, &tunnel->session_hlist[hash]) {
V_22 = F_106 ( V_165 , struct V_20 , V_167 ) ;
F_55 ( V_22 , V_155 ,
L_28 , V_22 -> V_41 ) ;
F_107 ( & V_22 -> V_167 ) ;
if ( V_22 -> V_70 != NULL )
(* V_22 -> V_70 )( V_22 ) ;
F_108 ( & V_8 -> V_25 ) ;
F_109 ( V_22 ) ;
F_63 ( V_22 ) ;
if ( V_22 -> V_168 != NULL )
(* V_22 -> V_168 )( V_22 ) ;
if ( V_22 -> V_51 != NULL )
(* V_22 -> V_51 )( V_22 ) ;
F_62 ( V_22 ) ;
F_104 ( & V_8 -> V_25 ) ;
goto V_166;
}
}
F_108 ( & V_8 -> V_25 ) ;
}
static void F_110 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_15 ( V_3 ) ;
if ( V_8 ) {
F_102 ( V_8 ) ;
F_17 ( V_3 ) ;
}
}
static void F_8 ( struct V_1 * V_8 )
{
F_2 ( F_111 ( & V_8 -> V_9 ) != 0 ) ;
F_2 ( V_8 -> V_2 != NULL ) ;
F_55 ( V_8 , V_155 , L_29 , V_8 -> V_41 ) ;
F_112 ( V_8 , V_169 ) ;
}
static void F_113 ( struct V_170 * V_171 )
{
struct V_1 * V_8 = NULL ;
struct V_16 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
V_8 = F_114 ( V_171 , struct V_1 , V_172 ) ;
V_3 = F_11 ( V_8 ) ;
if ( ! V_3 )
goto V_17;
V_2 = V_3 -> V_19 ;
if ( V_8 -> V_18 >= 0 ) {
if ( V_2 )
F_115 ( V_2 , 2 ) ;
} else {
if ( V_2 ) {
F_116 ( V_2 , V_173 ) ;
F_117 ( V_2 ) ;
}
}
F_14 ( V_3 ) ;
V_17:
F_103 ( V_8 ) ;
}
static int F_118 ( struct V_6 * V_6 ,
T_1 V_32 ,
T_1 V_106 ,
struct V_174 * V_175 ,
struct V_16 * * V_176 )
{
int V_15 = - V_177 ;
struct V_16 * V_2 = NULL ;
struct V_178 V_179 ;
switch ( V_175 -> V_108 ) {
case V_109 :
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
#if F_77 ( V_119 )
if ( V_175 -> V_180 && V_175 -> V_181 ) {
V_179 . V_182 = V_183 ;
memcpy ( & V_179 . V_180 , V_175 -> V_180 ,
sizeof( V_179 . V_180 ) ) ;
memcpy ( & V_179 . V_181 , V_175 -> V_181 ,
sizeof( V_179 . V_181 ) ) ;
V_179 . V_184 =
V_175 -> V_185 ;
V_179 . V_186 =
V_175 -> V_187 ;
} else
#endif
{
V_179 . V_182 = V_188 ;
V_179 . V_189 = V_175 -> V_189 ;
V_179 . V_190 = V_175 -> V_190 ;
V_179 . V_191 = V_175 -> V_191 ;
}
V_179 . V_192 = F_72 ( V_175 -> V_192 ) ;
V_179 . V_193 = F_72 ( V_175 -> V_193 ) ;
V_15 = F_119 ( V_6 , & V_179 , & V_2 ) ;
if ( V_15 < 0 )
goto V_17;
break;
case V_153 :
#if F_77 ( V_119 )
if ( V_175 -> V_180 && V_175 -> V_181 ) {
struct V_194 V_195 = { 0 } ;
V_15 = F_120 ( V_6 , V_183 , V_196 ,
V_197 , & V_2 ) ;
if ( V_15 < 0 )
goto V_17;
V_195 . V_198 = V_183 ;
memcpy ( & V_195 . V_199 , V_175 -> V_180 ,
sizeof( V_195 . V_199 ) ) ;
V_195 . V_200 = V_32 ;
V_15 = F_121 ( V_2 , (struct V_201 * ) & V_195 ,
sizeof( V_195 ) ) ;
if ( V_15 < 0 )
goto V_17;
V_195 . V_198 = V_183 ;
memcpy ( & V_195 . V_199 , V_175 -> V_181 ,
sizeof( V_195 . V_199 ) ) ;
V_195 . V_200 = V_106 ;
V_15 = F_122 ( V_2 ,
(struct V_201 * ) & V_195 ,
sizeof( V_195 ) , 0 ) ;
if ( V_15 < 0 )
goto V_17;
} else
#endif
{
struct V_202 V_203 = { 0 } ;
V_15 = F_120 ( V_6 , V_188 , V_196 ,
V_197 , & V_2 ) ;
if ( V_15 < 0 )
goto V_17;
V_203 . V_198 = V_188 ;
V_203 . V_199 = V_175 -> V_189 ;
V_203 . V_200 = V_32 ;
V_15 = F_121 ( V_2 , (struct V_201 * ) & V_203 ,
sizeof( V_203 ) ) ;
if ( V_15 < 0 )
goto V_17;
V_203 . V_198 = V_188 ;
V_203 . V_199 = V_175 -> V_190 ;
V_203 . V_200 = V_106 ;
V_15 = F_122 ( V_2 , (struct V_201 * ) & V_203 ,
sizeof( V_203 ) , 0 ) ;
if ( V_15 < 0 )
goto V_17;
}
break;
default:
goto V_17;
}
V_17:
* V_176 = V_2 ;
if ( ( V_15 < 0 ) && V_2 ) {
F_116 ( V_2 , V_173 ) ;
F_117 ( V_2 ) ;
* V_176 = NULL ;
}
return V_15 ;
}
int F_123 ( struct V_6 * V_6 , int V_18 , int V_75 , T_1 V_32 , T_1 V_106 , struct V_174 * V_175 , struct V_1 * * V_204 )
{
struct V_1 * V_8 = NULL ;
int V_15 ;
struct V_16 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
struct V_5 * V_11 ;
enum V_205 V_108 = V_109 ;
if ( V_18 < 0 ) {
V_15 = F_118 ( V_6 , V_32 , V_106 ,
V_175 , & V_2 ) ;
if ( V_15 < 0 )
goto V_15;
} else {
V_2 = F_12 ( V_18 , & V_15 ) ;
if ( ! V_2 ) {
F_124 ( L_30 ,
V_32 , V_18 , V_15 ) ;
V_15 = - V_206 ;
goto V_15;
}
if ( ! F_125 ( F_126 ( V_2 -> V_3 ) , V_6 ) ) {
F_124 ( L_31 , V_32 ) ;
V_15 = - V_177 ;
goto V_15;
}
}
V_3 = V_2 -> V_3 ;
if ( V_175 != NULL )
V_108 = V_175 -> V_108 ;
switch ( V_108 ) {
case V_109 :
V_15 = - V_207 ;
if ( V_3 -> V_208 != V_209 ) {
F_124 ( L_32 ,
V_32 , V_18 , V_3 -> V_208 , V_209 ) ;
goto V_15;
}
break;
case V_153 :
V_15 = - V_207 ;
if ( V_3 -> V_208 != V_197 ) {
F_124 ( L_32 ,
V_32 , V_18 , V_3 -> V_208 , V_197 ) ;
goto V_15;
}
break;
}
V_8 = V_1 ( V_3 ) ;
if ( V_8 != NULL ) {
V_15 = - V_210 ;
goto V_15;
}
V_8 = F_127 ( sizeof( struct V_1 ) , V_211 ) ;
if ( V_8 == NULL ) {
V_15 = - V_212 ;
goto V_15;
}
V_8 -> V_75 = V_75 ;
V_8 -> V_32 = V_32 ;
V_8 -> V_106 = V_106 ;
V_8 -> V_94 = V_213 ;
V_8 -> V_89 = V_214 ;
sprintf ( & V_8 -> V_41 [ 0 ] , L_33 , V_32 ) ;
F_128 ( & V_8 -> V_25 ) ;
V_8 -> V_5 = V_6 ;
V_11 = F_1 ( V_6 ) ;
if ( V_175 != NULL )
V_8 -> V_94 = V_175 -> V_94 ;
#if F_77 ( V_119 )
if ( V_3 -> V_120 == V_121 ) {
struct V_215 * V_216 = F_95 ( V_3 ) ;
if ( F_129 ( & V_216 -> V_148 ) &&
F_129 ( & V_3 -> V_149 ) ) {
struct V_128 * V_129 = F_90 ( V_3 ) ;
V_8 -> V_122 = true ;
V_129 -> V_151 = V_216 -> V_148 . V_217 [ 3 ] ;
V_129 -> V_218 = V_3 -> V_219 . V_217 [ 3 ] ;
V_129 -> V_152 = V_3 -> V_149 . V_217 [ 3 ] ;
} else {
V_8 -> V_122 = false ;
}
}
#endif
V_8 -> V_108 = V_108 ;
if ( V_108 == V_109 ) {
struct V_220 V_221 ;
V_221 . V_4 = V_8 ;
V_221 . V_156 = V_222 ;
V_221 . V_157 = F_70 ;
V_221 . V_158 = F_110 ;
F_130 ( V_6 , V_2 , & V_221 ) ;
} else {
V_3 -> V_4 = V_8 ;
}
V_8 -> V_160 = V_3 -> V_159 ;
V_3 -> V_159 = & F_98 ;
V_8 -> V_2 = V_3 ;
V_8 -> V_18 = V_18 ;
F_131 ( & V_3 -> V_223 . V_224 , & V_225 , L_34 ) ;
V_3 -> V_226 = V_227 ;
F_132 ( & V_8 -> V_172 , F_113 ) ;
F_133 ( & V_8 -> V_162 ) ;
F_5 ( & V_163 ) ;
F_134 ( V_8 ) ;
F_34 ( & V_11 -> V_161 ) ;
F_135 ( & V_8 -> V_162 , & V_11 -> V_228 ) ;
F_41 ( & V_11 -> V_161 ) ;
V_15 = 0 ;
V_15:
if ( V_204 )
* V_204 = V_8 ;
if ( V_2 && V_2 -> V_229 )
F_16 ( V_2 ) ;
return V_15 ;
}
int F_136 ( struct V_1 * V_8 )
{
F_134 ( V_8 ) ;
F_102 ( V_8 ) ;
if ( false == F_137 ( V_230 , & V_8 -> V_172 ) ) {
F_103 ( V_8 ) ;
return 1 ;
}
return 0 ;
}
void F_138 ( struct V_20 * V_22 )
{
struct V_1 * V_8 = V_22 -> V_8 ;
F_2 ( F_111 ( & V_22 -> V_9 ) != 0 ) ;
if ( V_8 ) {
F_2 ( V_8 -> V_89 != V_214 ) ;
if ( V_22 -> V_12 != 0 )
F_101 ( & V_231 ) ;
F_17 ( V_8 -> V_2 ) ;
V_22 -> V_8 = NULL ;
F_103 ( V_8 ) ;
}
F_139 ( V_22 ) ;
}
void F_109 ( struct V_20 * V_22 )
{
struct V_1 * V_8 = V_22 -> V_8 ;
if ( V_8 ) {
F_104 ( & V_8 -> V_25 ) ;
F_107 ( & V_22 -> V_167 ) ;
F_108 ( & V_8 -> V_25 ) ;
if ( V_8 -> V_75 != V_76 ) {
struct V_5 * V_11 = F_1 ( V_8 -> V_5 ) ;
F_34 ( & V_11 -> V_232 ) ;
F_140 ( & V_22 -> V_233 ) ;
F_41 ( & V_11 -> V_232 ) ;
F_141 () ;
}
}
}
int F_142 ( struct V_20 * V_22 )
{
if ( V_22 -> V_70 )
(* V_22 -> V_70 )( V_22 ) ;
F_109 ( V_22 ) ;
F_63 ( V_22 ) ;
if ( V_22 -> V_168 != NULL )
(* V_22 -> V_168 )( V_22 ) ;
if ( V_22 -> V_51 )
(* V_22 -> V_51 )( V_22 ) ;
F_62 ( V_22 ) ;
return 0 ;
}
void F_58 ( struct V_20 * V_22 , int V_75 )
{
if ( V_75 == V_76 ) {
V_22 -> V_126 = 6 ;
if ( V_22 -> V_85 )
V_22 -> V_126 += 4 ;
} else {
V_22 -> V_126 = 4 + V_22 -> V_111 + V_22 -> V_83 + V_22 -> V_69 ;
if ( V_22 -> V_8 -> V_108 == V_109 )
V_22 -> V_126 += 4 ;
}
}
struct V_20 * F_143 ( int V_234 , struct V_1 * V_8 , T_1 V_12 , T_1 V_107 , struct V_235 * V_175 )
{
struct V_20 * V_22 ;
V_22 = F_127 ( sizeof( struct V_20 ) + V_234 , V_211 ) ;
if ( V_22 != NULL ) {
V_22 -> V_89 = V_90 ;
V_22 -> V_8 = V_8 ;
V_22 -> V_12 = V_12 ;
V_22 -> V_107 = V_107 ;
V_22 -> V_48 = 0 ;
if ( V_8 -> V_75 == V_76 )
V_22 -> V_49 = 0xffff ;
else
V_22 -> V_49 = 0xffffff ;
V_22 -> V_59 = V_22 -> V_49 / 2 ;
V_22 -> V_65 = 4 ;
V_22 -> V_57 = 1 ;
sprintf ( & V_22 -> V_41 [ 0 ] , L_35 ,
V_8 -> V_32 , V_22 -> V_12 ) ;
F_144 ( & V_22 -> V_38 ) ;
F_145 ( & V_22 -> V_167 ) ;
F_145 ( & V_22 -> V_233 ) ;
V_22 -> V_94 = V_8 -> V_94 ;
if ( V_175 ) {
V_22 -> V_236 = V_175 -> V_237 ;
V_22 -> V_94 = V_175 -> V_94 ;
V_22 -> V_238 = V_175 -> V_238 ;
V_22 -> V_239 = V_175 -> V_239 ;
V_22 -> V_85 = V_175 -> V_85 ;
V_22 -> V_86 = V_175 -> V_86 ;
V_22 -> V_84 = V_175 -> V_84 ;
V_22 -> V_61 = V_175 -> V_61 ;
V_22 -> V_69 = V_175 -> V_69 ;
V_22 -> V_79 = V_175 -> V_79 ;
V_22 -> V_83 = V_175 -> V_83 ;
V_22 -> V_111 = V_175 -> V_111 ;
memcpy ( & V_22 -> V_112 [ 0 ] , & V_175 -> V_112 [ 0 ] , V_175 -> V_111 ) ;
V_22 -> V_71 = V_175 -> V_71 ;
memcpy ( & V_22 -> V_72 [ 0 ] , & V_175 -> V_72 [ 0 ] , V_175 -> V_71 ) ;
}
if ( V_8 -> V_75 == V_76 )
V_22 -> V_137 = F_71 ;
else
V_22 -> V_137 = F_73 ;
F_58 ( V_22 , V_8 -> V_75 ) ;
F_54 ( V_22 ) ;
F_134 ( V_8 ) ;
F_13 ( V_8 -> V_2 ) ;
F_104 ( & V_8 -> V_25 ) ;
F_146 ( & V_22 -> V_167 ,
F_22 ( V_8 , V_12 ) ) ;
F_108 ( & V_8 -> V_25 ) ;
if ( V_8 -> V_75 != V_76 ) {
struct V_5 * V_11 = F_1 ( V_8 -> V_5 ) ;
F_34 ( & V_11 -> V_232 ) ;
F_147 ( & V_22 -> V_233 ,
F_9 ( V_11 , V_12 ) ) ;
F_41 ( & V_11 -> V_232 ) ;
}
if ( V_22 -> V_12 != 0 )
F_5 ( & V_231 ) ;
}
return V_22 ;
}
static T_4 int F_148 ( struct V_6 * V_6 )
{
struct V_5 * V_11 = F_3 ( V_6 , V_7 ) ;
int V_27 ;
F_133 ( & V_11 -> V_228 ) ;
F_149 ( & V_11 -> V_161 ) ;
for ( V_27 = 0 ; V_27 < V_31 ; V_27 ++ )
F_150 ( & V_11 -> V_13 [ V_27 ] ) ;
F_149 ( & V_11 -> V_232 ) ;
return 0 ;
}
static T_5 void F_151 ( struct V_6 * V_6 )
{
struct V_5 * V_11 = F_1 ( V_6 ) ;
struct V_1 * V_8 = NULL ;
F_19 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
( void ) F_136 ( V_8 ) ;
}
F_21 () ;
}
static int T_6 F_152 ( void )
{
int V_240 = 0 ;
V_240 = F_153 ( & V_241 ) ;
if ( V_240 )
goto V_17;
V_230 = F_154 ( L_36 , V_242 , 0 ) ;
if ( ! V_230 ) {
F_124 ( L_37 ) ;
F_155 ( & V_241 ) ;
V_240 = - V_212 ;
goto V_17;
}
F_156 ( L_38 , V_243 ) ;
V_17:
return V_240 ;
}
static void T_7 F_157 ( void )
{
F_155 ( & V_241 ) ;
if ( V_230 ) {
F_158 ( V_230 ) ;
V_230 = NULL ;
}
}
