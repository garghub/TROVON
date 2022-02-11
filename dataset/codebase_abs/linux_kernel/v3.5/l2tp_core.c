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
static struct V_7 * F_9 ( struct V_2 * V_2 , T_1 V_8 )
{
struct V_1 * V_9 = F_1 ( V_2 ) ;
struct V_10 * V_11 =
F_10 ( V_9 , V_8 ) ;
struct V_7 * V_12 ;
struct V_13 * V_14 ;
F_11 () ;
F_12 (session, walk, session_list, global_hlist) {
if ( V_12 -> V_8 == V_8 ) {
F_13 () ;
return V_12 ;
}
}
F_13 () ;
return NULL ;
}
static inline struct V_10 *
F_14 ( struct V_4 * V_5 , T_1 V_8 )
{
return & V_5 -> V_15 [ F_15 ( V_8 , V_16 ) ] ;
}
struct V_7 * F_16 ( struct V_2 * V_2 , struct V_4 * V_5 , T_1 V_8 )
{
struct V_10 * V_11 ;
struct V_7 * V_12 ;
struct V_13 * V_14 ;
if ( V_5 == NULL )
return F_9 ( V_2 , V_8 ) ;
V_11 = F_14 ( V_5 , V_8 ) ;
F_17 ( & V_5 -> V_17 ) ;
F_18 (session, walk, session_list, hlist) {
if ( V_12 -> V_8 == V_8 ) {
F_19 ( & V_5 -> V_17 ) ;
return V_12 ;
}
}
F_19 ( & V_5 -> V_17 ) ;
return NULL ;
}
struct V_7 * F_20 ( struct V_4 * V_5 , int V_18 )
{
int V_19 ;
struct V_13 * V_14 ;
struct V_7 * V_12 ;
int V_20 = 0 ;
F_17 ( & V_5 -> V_17 ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
F_18 (session, walk, &tunnel->session_hlist[hash], hlist) {
if ( ++ V_20 > V_18 ) {
F_19 ( & V_5 -> V_17 ) ;
return V_12 ;
}
}
}
F_19 ( & V_5 -> V_17 ) ;
return NULL ;
}
struct V_7 * F_21 ( struct V_2 * V_2 , char * V_22 )
{
struct V_1 * V_9 = F_1 ( V_2 ) ;
int V_19 ;
struct V_13 * V_14 ;
struct V_7 * V_12 ;
F_11 () ;
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ ) {
F_12 (session, walk, &pn->l2tp_session_hlist[hash], global_hlist) {
if ( ! strcmp ( V_12 -> V_22 , V_22 ) ) {
F_13 () ;
return V_12 ;
}
}
}
F_13 () ;
return NULL ;
}
struct V_4 * F_22 ( struct V_2 * V_2 , T_1 V_24 )
{
struct V_4 * V_5 ;
struct V_1 * V_9 = F_1 ( V_2 ) ;
F_11 () ;
F_23 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( V_5 -> V_24 == V_24 ) {
F_13 () ;
return V_5 ;
}
}
F_13 () ;
return NULL ;
}
struct V_4 * F_24 ( struct V_2 * V_2 , int V_18 )
{
struct V_1 * V_9 = F_1 ( V_2 ) ;
struct V_4 * V_5 ;
int V_20 = 0 ;
F_11 () ;
F_23 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( ++ V_20 > V_18 ) {
F_13 () ;
return V_5 ;
}
}
F_13 () ;
return NULL ;
}
static void F_25 ( struct V_7 * V_12 , struct V_25 * V_26 )
{
struct V_25 * V_27 ;
struct V_25 * V_28 ;
T_1 V_29 = F_26 ( V_26 ) -> V_29 ;
struct V_30 * V_31 ;
F_27 ( & V_12 -> V_32 . V_33 ) ;
V_31 = & V_12 -> V_34 ;
F_28 (&session->reorder_q, skbp, tmp) {
if ( F_26 ( V_27 ) -> V_29 > V_29 ) {
F_29 ( & V_12 -> V_32 , V_27 , V_26 ) ;
F_30 ( V_12 , V_35 ,
L_1 ,
V_12 -> V_36 , V_29 , F_26 ( V_27 ) -> V_29 ,
F_31 ( & V_12 -> V_32 ) ) ;
F_32 ( & V_31 -> V_37 ) ;
V_31 -> V_38 ++ ;
F_33 ( & V_31 -> V_37 ) ;
goto V_39;
}
}
F_34 ( & V_12 -> V_32 , V_26 ) ;
V_39:
F_35 ( & V_12 -> V_32 . V_33 ) ;
}
static void F_36 ( struct V_7 * V_12 , struct V_25 * V_26 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
int V_40 = F_26 ( V_26 ) -> V_40 ;
struct V_30 * V_41 , * V_31 ;
F_37 ( V_26 ) ;
V_41 = & V_5 -> V_34 ;
F_32 ( & V_41 -> V_37 ) ;
V_31 = & V_12 -> V_34 ;
F_32 ( & V_31 -> V_37 ) ;
V_41 -> V_42 ++ ;
V_41 -> V_43 += V_40 ;
V_31 -> V_42 ++ ;
V_31 -> V_43 += V_40 ;
F_33 ( & V_41 -> V_37 ) ;
F_33 ( & V_31 -> V_37 ) ;
if ( F_26 ( V_26 ) -> V_44 ) {
V_12 -> V_45 ++ ;
if ( V_5 -> V_46 == V_47 )
V_12 -> V_45 &= 0xffff ;
else
V_12 -> V_45 &= 0xffffff ;
F_30 ( V_12 , V_35 , L_2 ,
V_12 -> V_36 , V_12 -> V_45 ) ;
}
if ( V_12 -> V_48 != NULL )
(* V_12 -> V_48 )( V_12 , V_26 , F_26 ( V_26 ) -> V_40 ) ;
else
F_38 ( V_26 ) ;
if ( V_12 -> V_49 )
(* V_12 -> V_49 )( V_12 ) ;
}
static void F_39 ( struct V_7 * V_12 )
{
struct V_25 * V_26 ;
struct V_25 * V_28 ;
struct V_30 * V_31 ;
V_50:
F_27 ( & V_12 -> V_32 . V_33 ) ;
V_31 = & V_12 -> V_34 ;
F_28 (&session->reorder_q, skb, tmp) {
if ( F_40 ( V_51 , F_26 ( V_26 ) -> V_52 ) ) {
F_32 ( & V_31 -> V_37 ) ;
V_31 -> V_53 ++ ;
V_31 -> V_54 ++ ;
F_33 ( & V_31 -> V_37 ) ;
F_30 ( V_12 , V_35 ,
L_3 ,
V_12 -> V_36 , F_26 ( V_26 ) -> V_29 ,
F_26 ( V_26 ) -> V_40 , V_12 -> V_45 ,
F_31 ( & V_12 -> V_32 ) ) ;
V_12 -> V_55 = 1 ;
F_41 ( V_26 , & V_12 -> V_32 ) ;
F_38 ( V_26 ) ;
if ( V_12 -> V_49 )
(* V_12 -> V_49 )( V_12 ) ;
continue;
}
if ( F_26 ( V_26 ) -> V_44 ) {
if ( V_12 -> V_55 ) {
F_30 ( V_12 , V_35 ,
L_4 ,
V_12 -> V_36 , V_12 -> V_45 ,
F_26 ( V_26 ) -> V_29 ) ;
V_12 -> V_55 = 0 ;
V_12 -> V_45 = F_26 ( V_26 ) -> V_29 ;
}
if ( F_26 ( V_26 ) -> V_29 != V_12 -> V_45 ) {
F_30 ( V_12 , V_35 ,
L_5 ,
V_12 -> V_36 , F_26 ( V_26 ) -> V_29 ,
F_26 ( V_26 ) -> V_40 , V_12 -> V_45 ,
F_31 ( & V_12 -> V_32 ) ) ;
goto V_39;
}
}
F_41 ( V_26 , & V_12 -> V_32 ) ;
F_35 ( & V_12 -> V_32 . V_33 ) ;
F_36 ( V_12 , V_26 ) ;
goto V_50;
}
V_39:
F_35 ( & V_12 -> V_32 . V_33 ) ;
}
static inline int F_42 ( struct V_56 * V_57 ,
struct V_25 * V_26 )
{
struct V_58 * V_59 = F_43 ( V_26 ) ;
T_2 V_60 = F_44 ( V_59 -> V_61 ) ;
T_3 V_62 ;
if ( V_57 -> V_63 || F_45 ( V_26 ) )
return 0 ;
#if F_46 ( V_64 )
if ( V_57 -> V_65 == V_66 ) {
if ( ! V_59 -> V_67 ) {
F_47 ( V_68 L_6 ) ;
return 1 ;
}
if ( ( V_26 -> V_69 == V_70 ) &&
! F_48 ( & F_49 ( V_26 ) -> V_71 ,
& F_49 ( V_26 ) -> V_72 , V_60 ,
V_73 , V_26 -> V_74 ) ) {
V_26 -> V_69 = V_75 ;
return 0 ;
}
V_26 -> V_74 = ~ F_50 ( F_48 ( & F_49 ( V_26 ) -> V_71 ,
& F_49 ( V_26 ) -> V_72 ,
V_26 -> V_61 , V_73 ,
0 ) ) ;
} else
#endif
{
struct V_76 * V_77 ;
if ( ! V_59 -> V_67 )
return 0 ;
V_77 = F_51 ( V_57 ) ;
V_62 = F_52 ( V_77 -> V_78 , V_77 -> V_79 ,
V_60 , V_73 , 0 ) ;
if ( ( V_26 -> V_69 == V_70 ) &&
! F_53 ( F_54 ( V_62 , V_26 -> V_74 ) ) )
return 0 ;
V_26 -> V_74 = V_62 ;
}
return F_55 ( V_26 ) ;
}
void F_56 ( struct V_7 * V_12 , struct V_25 * V_26 ,
unsigned char * V_80 , unsigned char * V_81 , T_2 V_82 ,
int V_40 , int (* F_57)( struct V_25 * V_26 ) )
{
struct V_4 * V_5 = V_12 -> V_5 ;
int V_83 ;
T_1 V_29 , V_45 ;
struct V_30 * V_31 = & V_12 -> V_34 ;
F_58 ( V_12 ) ;
if ( V_12 -> V_84 )
(* V_12 -> V_84 )( V_12 ) ;
if ( V_12 -> V_85 > 0 ) {
if ( memcmp ( V_80 , & V_12 -> V_86 [ 0 ] , V_12 -> V_85 ) ) {
F_59 ( V_5 , V_87 ,
L_7 ,
V_5 -> V_36 , V_5 -> V_24 ,
V_12 -> V_8 ) ;
F_32 ( & V_31 -> V_37 ) ;
V_31 -> V_88 ++ ;
F_33 ( & V_31 -> V_37 ) ;
goto V_89;
}
V_80 += V_12 -> V_85 ;
}
V_29 = V_45 = 0 ;
F_26 ( V_26 ) -> V_44 = 0 ;
if ( V_5 -> V_46 == V_47 ) {
if ( V_82 & V_90 ) {
V_29 = F_44 ( * ( V_91 * ) V_80 ) ;
V_80 += 2 ;
V_45 = F_44 ( * ( V_91 * ) V_80 ) ;
V_80 += 2 ;
F_26 ( V_26 ) -> V_29 = V_29 ;
F_26 ( V_26 ) -> V_44 = 1 ;
F_30 ( V_12 , V_35 ,
L_8 ,
V_12 -> V_36 , V_29 , V_45 , V_12 -> V_45 ) ;
}
} else if ( V_12 -> V_92 == V_93 ) {
T_1 V_94 = F_60 ( * ( V_95 * ) V_80 ) ;
if ( V_94 & 0x40000000 ) {
V_29 = V_94 & 0x00ffffff ;
F_26 ( V_26 ) -> V_29 = V_29 ;
F_26 ( V_26 ) -> V_44 = 1 ;
F_30 ( V_12 , V_35 ,
L_9 ,
V_12 -> V_36 , V_29 , V_12 -> V_45 ) ;
}
}
V_80 += V_12 -> V_96 ;
if ( F_26 ( V_26 ) -> V_44 ) {
if ( ( ! V_12 -> V_97 ) && ( ! V_12 -> V_98 ) ) {
F_59 ( V_12 , V_35 ,
L_10 ,
V_12 -> V_36 ) ;
V_12 -> V_98 = - 1 ;
F_61 ( V_12 , V_5 -> V_46 ) ;
}
} else {
if ( V_12 -> V_99 ) {
F_62 ( V_12 , V_35 ,
L_11 ,
V_12 -> V_36 ) ;
F_32 ( & V_31 -> V_37 ) ;
V_31 -> V_53 ++ ;
F_33 ( & V_31 -> V_37 ) ;
goto V_89;
}
if ( ( ! V_12 -> V_97 ) && ( V_12 -> V_98 ) ) {
F_59 ( V_12 , V_35 ,
L_12 ,
V_12 -> V_36 ) ;
V_12 -> V_98 = 0 ;
F_61 ( V_12 , V_5 -> V_46 ) ;
} else if ( V_12 -> V_98 ) {
F_62 ( V_12 , V_35 ,
L_11 ,
V_12 -> V_36 ) ;
F_32 ( & V_31 -> V_37 ) ;
V_31 -> V_53 ++ ;
F_33 ( & V_31 -> V_37 ) ;
goto V_89;
}
}
if ( V_5 -> V_46 == V_47 ) {
if ( V_82 & V_100 ) {
V_83 = F_44 ( * ( V_91 * ) V_80 ) ;
V_80 += 2 + V_83 ;
}
} else
V_80 += V_12 -> V_83 ;
V_83 = V_80 - V_81 ;
if ( ! F_63 ( V_26 , V_83 ) )
goto V_89;
F_64 ( V_26 , V_83 ) ;
if ( F_57 )
if ( (* F_57)( V_26 ) )
goto V_89;
F_26 ( V_26 ) -> V_40 = V_40 ;
F_26 ( V_26 ) -> V_52 = V_51 +
( V_12 -> V_101 ? V_12 -> V_101 : V_102 ) ;
if ( F_26 ( V_26 ) -> V_44 ) {
if ( V_12 -> V_101 != 0 ) {
F_25 ( V_12 , V_26 ) ;
} else {
if ( F_26 ( V_26 ) -> V_29 != V_12 -> V_45 ) {
F_32 ( & V_31 -> V_37 ) ;
V_31 -> V_53 ++ ;
F_33 ( & V_31 -> V_37 ) ;
F_30 ( V_12 , V_35 ,
L_13 ,
V_12 -> V_36 , F_26 ( V_26 ) -> V_29 ,
F_26 ( V_26 ) -> V_40 , V_12 -> V_45 ,
F_31 ( & V_12 -> V_32 ) ) ;
goto V_89;
}
F_65 ( & V_12 -> V_32 , V_26 ) ;
}
} else {
F_65 ( & V_12 -> V_32 , V_26 ) ;
}
F_39 ( V_12 ) ;
F_66 ( V_12 ) ;
return;
V_89:
F_32 ( & V_31 -> V_37 ) ;
V_31 -> V_54 ++ ;
F_33 ( & V_31 -> V_37 ) ;
F_38 ( V_26 ) ;
if ( V_12 -> V_49 )
(* V_12 -> V_49 )( V_12 ) ;
F_66 ( V_12 ) ;
}
static int F_67 ( struct V_4 * V_5 , struct V_25 * V_26 ,
int (* F_57)( struct V_25 * V_26 ) )
{
struct V_7 * V_12 = NULL ;
unsigned char * V_80 , * V_81 ;
T_2 V_82 ;
T_1 V_24 , V_8 ;
T_2 V_46 ;
int V_40 ;
struct V_30 * V_41 ;
if ( V_5 -> V_56 && F_42 ( V_5 -> V_56 , V_26 ) )
goto V_103;
F_64 ( V_26 , sizeof( struct V_58 ) ) ;
if ( ! F_63 ( V_26 , V_104 ) ) {
F_59 ( V_5 , V_87 ,
L_14 ,
V_5 -> V_36 , V_26 -> V_61 ) ;
goto error;
}
if ( V_5 -> V_105 & V_87 ) {
V_40 = F_68 ( 32u , V_26 -> V_61 ) ;
if ( ! F_63 ( V_26 , V_40 ) )
goto error;
F_69 ( L_15 , V_5 -> V_36 ) ;
F_70 ( L_16 , V_106 , V_26 -> V_107 , V_40 ) ;
}
V_81 = V_80 = V_26 -> V_107 ;
V_82 = F_44 ( * ( V_91 * ) V_80 ) ;
V_46 = V_82 & V_108 ;
if ( V_46 != V_5 -> V_46 ) {
F_59 ( V_5 , V_87 ,
L_17 ,
V_5 -> V_36 , V_46 , V_5 -> V_46 ) ;
goto error;
}
V_40 = V_26 -> V_61 ;
if ( V_82 & V_109 ) {
F_30 ( V_5 , V_87 ,
L_18 ,
V_5 -> V_36 , V_40 ) ;
goto error;
}
V_80 += 2 ;
if ( V_5 -> V_46 == V_47 ) {
if ( V_82 & V_110 )
V_80 += 2 ;
V_24 = F_44 ( * ( V_91 * ) V_80 ) ;
V_80 += 2 ;
V_8 = F_44 ( * ( V_91 * ) V_80 ) ;
V_80 += 2 ;
} else {
V_80 += 2 ;
V_24 = V_5 -> V_24 ;
V_8 = F_60 ( * ( V_95 * ) V_80 ) ;
V_80 += 4 ;
}
V_12 = F_16 ( V_5 -> V_1 , V_5 , V_8 ) ;
if ( ! V_12 || ! V_12 -> V_48 ) {
F_59 ( V_5 , V_87 ,
L_19 ,
V_5 -> V_36 , V_24 , V_8 ) ;
goto error;
}
F_56 ( V_12 , V_26 , V_80 , V_81 , V_82 , V_40 , F_57 ) ;
return 0 ;
V_103:
F_47 ( L_20 , V_5 -> V_36 ) ;
F_71 ( V_5 -> V_1 , V_111 , 0 ) ;
V_41 = & V_5 -> V_34 ;
F_32 ( & V_41 -> V_37 ) ;
V_41 -> V_54 ++ ;
F_33 ( & V_41 -> V_37 ) ;
F_38 ( V_26 ) ;
return 0 ;
error:
F_72 ( V_26 , sizeof( struct V_58 ) ) ;
return 1 ;
}
int F_73 ( struct V_56 * V_57 , struct V_25 * V_26 )
{
struct V_4 * V_5 ;
V_5 = F_74 ( V_57 ) ;
if ( V_5 == NULL )
goto V_112;
F_30 ( V_5 , V_87 , L_21 ,
V_5 -> V_36 , V_26 -> V_61 ) ;
if ( F_67 ( V_5 , V_26 , V_5 -> V_113 ) )
goto V_114;
F_75 ( V_57 ) ;
return 0 ;
V_114:
F_75 ( V_57 ) ;
V_112:
return 1 ;
}
static int F_76 ( struct V_7 * V_12 , void * V_115 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
V_91 * V_116 = V_115 ;
V_91 * V_81 = V_115 ;
T_2 V_117 = V_47 ;
T_1 V_24 = V_5 -> V_118 ;
T_1 V_8 = V_12 -> V_119 ;
if ( V_12 -> V_98 )
V_117 |= V_90 ;
* V_116 ++ = F_77 ( V_117 ) ;
* V_116 ++ = F_77 ( V_24 ) ;
* V_116 ++ = F_77 ( V_8 ) ;
if ( V_12 -> V_98 ) {
* V_116 ++ = F_77 ( V_12 -> V_29 ) ;
* V_116 ++ = 0 ;
V_12 -> V_29 ++ ;
V_12 -> V_29 &= 0xffff ;
F_30 ( V_12 , V_35 , L_22 ,
V_12 -> V_36 , V_12 -> V_29 ) ;
}
return V_116 - V_81 ;
}
static int F_78 ( struct V_7 * V_12 , void * V_115 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
char * V_116 = V_115 ;
char * V_81 = V_116 ;
if ( V_5 -> V_120 == V_121 ) {
T_2 V_117 = V_122 ;
* ( ( V_91 * ) V_116 ) = F_77 ( V_117 ) ;
V_116 += 2 ;
* ( ( V_91 * ) V_116 ) = 0 ;
V_116 += 2 ;
}
* ( ( V_95 * ) V_116 ) = F_79 ( V_12 -> V_119 ) ;
V_116 += 4 ;
if ( V_12 -> V_123 ) {
memcpy ( V_116 , & V_12 -> V_124 [ 0 ] , V_12 -> V_123 ) ;
V_116 += V_12 -> V_123 ;
}
if ( V_12 -> V_96 ) {
if ( V_12 -> V_92 == V_93 ) {
T_1 V_94 = 0 ;
if ( V_12 -> V_98 ) {
V_94 = 0x40000000 | V_12 -> V_29 ;
V_12 -> V_29 ++ ;
V_12 -> V_29 &= 0xffffff ;
F_30 ( V_12 , V_35 ,
L_22 ,
V_12 -> V_36 , V_12 -> V_29 ) ;
}
* ( ( V_95 * ) V_116 ) = F_79 ( V_94 ) ;
}
V_116 += V_12 -> V_96 ;
}
if ( V_12 -> V_83 )
V_116 += V_12 -> V_83 ;
return V_116 - V_81 ;
}
static int F_80 ( struct V_7 * V_12 , struct V_25 * V_26 ,
struct V_125 * V_126 , T_4 V_127 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
unsigned int V_61 = V_26 -> V_61 ;
int error ;
struct V_30 * V_41 , * V_31 ;
if ( V_12 -> V_98 )
F_30 ( V_12 , V_87 , L_23 ,
V_12 -> V_36 , V_127 , V_12 -> V_29 - 1 ) ;
else
F_30 ( V_12 , V_87 , L_24 ,
V_12 -> V_36 , V_127 ) ;
if ( V_12 -> V_105 & V_87 ) {
int V_128 = ( V_5 -> V_120 == V_121 ) ? sizeof( struct V_58 ) : 0 ;
unsigned char * V_129 = V_26 -> V_107 + V_128 ;
F_69 ( L_25 , V_12 -> V_36 ) ;
F_70 ( L_16 , V_106 ,
V_129 , F_81 ( T_4 , 32 , V_61 - V_128 ) ) ;
}
V_26 -> V_130 = 1 ;
#if F_46 ( V_64 )
if ( V_26 -> V_57 -> V_65 == V_66 )
error = F_82 ( V_26 , NULL ) ;
else
#endif
error = F_83 ( V_26 , V_126 ) ;
V_41 = & V_5 -> V_34 ;
F_32 ( & V_41 -> V_37 ) ;
V_31 = & V_12 -> V_34 ;
F_32 ( & V_31 -> V_37 ) ;
if ( error >= 0 ) {
V_41 -> V_131 ++ ;
V_41 -> V_132 += V_61 ;
V_31 -> V_131 ++ ;
V_31 -> V_132 += V_61 ;
} else {
V_41 -> V_133 ++ ;
V_31 -> V_133 ++ ;
}
F_33 ( & V_41 -> V_37 ) ;
F_33 ( & V_31 -> V_37 ) ;
return 0 ;
}
static void F_84 ( struct V_25 * V_26 )
{
F_75 ( V_26 -> V_57 ) ;
}
static inline void F_85 ( struct V_25 * V_26 , struct V_56 * V_57 )
{
F_86 ( V_57 ) ;
V_26 -> V_57 = V_57 ;
V_26 -> V_134 = F_84 ;
}
static void F_87 ( struct V_56 * V_57 , struct V_25 * V_26 ,
int V_135 )
{
struct V_136 * V_137 = F_88 ( V_57 ) ;
struct V_58 * V_59 = F_43 ( V_26 ) ;
if ( ! F_89 ( V_26 ) || ! F_89 ( V_26 ) -> V_138 ||
! ( F_89 ( V_26 ) -> V_138 -> V_139 & V_140 ) ) {
T_3 V_74 = F_90 ( V_26 , 0 , V_135 , 0 ) ;
V_26 -> V_69 = V_75 ;
V_59 -> V_67 = F_48 ( & V_137 -> V_71 , & V_137 -> V_72 , V_135 ,
V_73 , V_74 ) ;
if ( V_59 -> V_67 == 0 )
V_59 -> V_67 = V_141 ;
} else {
V_26 -> V_69 = V_142 ;
V_26 -> V_143 = F_91 ( V_26 ) - V_26 -> V_144 ;
V_26 -> V_145 = F_92 ( struct V_58 , V_67 ) ;
V_59 -> V_67 = ~ F_48 ( & V_137 -> V_71 , & V_137 -> V_72 ,
V_135 , V_73 , 0 ) ;
}
}
int F_93 ( struct V_7 * V_12 , struct V_25 * V_26 , int V_146 )
{
int V_127 = V_26 -> V_61 ;
struct V_4 * V_5 = V_12 -> V_5 ;
struct V_56 * V_57 = V_5 -> V_56 ;
struct V_125 * V_126 ;
struct V_58 * V_59 ;
struct V_76 * V_77 ;
T_3 V_74 ;
int V_147 ;
int V_148 ;
int V_149 ;
int V_128 = ( V_5 -> V_120 == V_121 ) ? sizeof( struct V_58 ) : 0 ;
int V_135 ;
V_149 = V_150 + sizeof( struct V_151 ) +
V_128 + V_146 ;
V_147 = F_94 ( V_26 ) ;
if ( F_95 ( V_26 , V_149 ) ) {
F_96 ( V_26 ) ;
goto abort;
}
V_148 = F_94 ( V_26 ) ;
F_37 ( V_26 ) ;
V_26 -> V_152 += V_148 - V_147 ;
V_12 -> V_153 ( V_12 , F_72 ( V_26 , V_146 ) ) ;
memset ( & ( F_97 ( V_26 ) -> V_154 ) , 0 , sizeof( F_97 ( V_26 ) -> V_154 ) ) ;
F_97 ( V_26 ) -> V_117 &= ~ ( V_155 | V_156 |
V_157 ) ;
F_98 ( V_26 ) ;
F_99 ( V_57 ) ;
if ( F_100 ( V_57 ) ) {
F_96 ( V_26 ) ;
goto V_158;
}
F_101 ( V_26 ) ;
F_102 ( V_26 , F_103 ( F_104 ( V_57 , 0 ) ) ) ;
V_77 = F_51 ( V_57 ) ;
V_126 = & V_77 -> V_159 . V_126 ;
switch ( V_5 -> V_120 ) {
case V_121 :
F_72 ( V_26 , sizeof( * V_59 ) ) ;
F_105 ( V_26 ) ;
V_59 = F_43 ( V_26 ) ;
V_59 -> V_160 = V_77 -> V_161 ;
V_59 -> V_162 = V_77 -> V_163 ;
V_135 = V_128 + V_146 + V_127 ;
V_59 -> V_61 = F_77 ( V_135 ) ;
V_59 -> V_67 = 0 ;
#if F_46 ( V_64 )
if ( V_57 -> V_65 == V_66 )
F_87 ( V_57 , V_26 , V_135 ) ;
else
#endif
if ( V_57 -> V_63 == V_164 )
V_26 -> V_69 = V_165 ;
else if ( ( F_89 ( V_26 ) && F_89 ( V_26 ) -> V_138 ) &&
( ! ( F_89 ( V_26 ) -> V_138 -> V_139 & V_166 ) ) ) {
V_26 -> V_69 = V_70 ;
V_74 = F_90 ( V_26 , 0 , V_135 , 0 ) ;
V_59 -> V_67 = F_106 ( V_77 -> V_78 ,
V_77 -> V_79 ,
V_135 , V_73 , V_74 ) ;
if ( V_59 -> V_67 == 0 )
V_59 -> V_67 = V_141 ;
} else {
V_26 -> V_69 = V_142 ;
V_26 -> V_143 = F_91 ( V_26 ) - V_26 -> V_144 ;
V_26 -> V_145 = F_92 ( struct V_58 , V_67 ) ;
V_59 -> V_67 = ~ F_106 ( V_77 -> V_78 ,
V_77 -> V_79 ,
V_135 , V_73 , 0 ) ;
}
break;
case V_167 :
break;
}
F_85 ( V_26 , V_57 ) ;
F_80 ( V_12 , V_26 , V_126 , V_127 ) ;
V_158:
F_107 ( V_57 ) ;
abort:
return 0 ;
}
static void F_108 ( struct V_56 * V_57 )
{
struct V_4 * V_5 ;
V_5 = V_57 -> V_168 ;
if ( V_5 == NULL )
goto V_169;
F_59 ( V_5 , V_170 , L_26 , V_5 -> V_36 ) ;
F_109 ( V_5 ) ;
switch ( V_5 -> V_120 ) {
case V_121 :
( F_110 ( V_57 ) ) -> V_171 = 0 ;
( F_110 ( V_57 ) ) -> V_172 = NULL ;
break;
case V_167 :
break;
}
V_5 -> V_56 = NULL ;
V_57 -> V_173 = V_5 -> V_174 ;
V_57 -> V_168 = NULL ;
if ( V_57 -> V_173 )
(* V_57 -> V_173 )( V_57 ) ;
F_111 ( V_5 ) ;
V_169:
return;
}
static void F_109 ( struct V_4 * V_5 )
{
int V_19 ;
struct V_13 * V_14 ;
struct V_13 * V_28 ;
struct V_7 * V_12 ;
F_2 ( V_5 == NULL ) ;
F_59 ( V_5 , V_170 , L_27 ,
V_5 -> V_36 ) ;
F_112 ( & V_5 -> V_17 ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
V_175:
F_113 (walk, tmp, &tunnel->session_hlist[hash]) {
V_12 = F_114 ( V_14 , struct V_7 , V_176 ) ;
F_59 ( V_12 , V_170 ,
L_28 , V_12 -> V_36 ) ;
F_115 ( & V_12 -> V_176 ) ;
if ( V_12 -> V_84 != NULL )
(* V_12 -> V_84 )( V_12 ) ;
F_116 ( & V_5 -> V_17 ) ;
if ( V_5 -> V_46 != V_47 ) {
struct V_1 * V_9 = F_1 ( V_5 -> V_1 ) ;
F_27 ( & V_9 -> V_177 ) ;
F_117 ( & V_12 -> V_178 ) ;
F_35 ( & V_9 -> V_177 ) ;
F_118 () ;
}
if ( V_12 -> V_179 != NULL )
(* V_12 -> V_179 )( V_12 ) ;
if ( V_12 -> V_49 != NULL )
(* V_12 -> V_49 )( V_12 ) ;
F_112 ( & V_5 -> V_17 ) ;
goto V_175;
}
}
F_116 ( & V_5 -> V_17 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_9 = F_1 ( V_5 -> V_1 ) ;
F_2 ( F_119 ( & V_5 -> V_6 ) != 0 ) ;
F_2 ( V_5 -> V_56 != NULL ) ;
F_59 ( V_5 , V_170 , L_29 , V_5 -> V_36 ) ;
F_27 ( & V_9 -> V_180 ) ;
F_120 ( & V_5 -> V_181 ) ;
F_35 ( & V_9 -> V_180 ) ;
F_118 () ;
F_121 ( & V_182 ) ;
F_122 ( V_5 ) ;
}
static int F_123 ( T_1 V_24 , T_1 V_118 , struct V_183 * V_184 , struct V_185 * * V_186 )
{
int V_187 = - V_188 ;
struct V_189 V_190 ;
#if F_46 ( V_64 )
struct V_191 V_192 ;
struct V_193 V_194 ;
#endif
struct V_195 V_196 ;
struct V_185 * V_56 = NULL ;
switch ( V_184 -> V_120 ) {
case V_121 :
#if F_46 ( V_64 )
if ( V_184 -> V_197 && V_184 -> V_198 ) {
V_187 = F_124 ( V_199 , V_200 , 0 , V_186 ) ;
if ( V_187 < 0 )
goto V_39;
V_56 = * V_186 ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
V_192 . V_201 = V_199 ;
memcpy ( & V_192 . V_202 , V_184 -> V_197 ,
sizeof( V_192 . V_202 ) ) ;
V_192 . V_203 = F_77 ( V_184 -> V_204 ) ;
V_187 = F_125 ( V_56 , (struct V_205 * ) & V_192 ,
sizeof( V_192 ) ) ;
if ( V_187 < 0 )
goto V_39;
V_192 . V_201 = V_199 ;
memcpy ( & V_192 . V_202 , V_184 -> V_198 ,
sizeof( V_192 . V_202 ) ) ;
V_192 . V_203 = F_77 ( V_184 -> V_206 ) ;
V_187 = F_126 ( V_56 ,
(struct V_205 * ) & V_192 ,
sizeof( V_192 ) , 0 ) ;
if ( V_187 < 0 )
goto V_39;
} else
#endif
{
V_187 = F_124 ( V_207 , V_200 , 0 , V_186 ) ;
if ( V_187 < 0 )
goto V_39;
V_56 = * V_186 ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_190 . V_208 = V_207 ;
V_190 . V_209 = V_184 -> V_210 ;
V_190 . V_211 = F_77 ( V_184 -> V_204 ) ;
V_187 = F_125 ( V_56 , (struct V_205 * ) & V_190 ,
sizeof( V_190 ) ) ;
if ( V_187 < 0 )
goto V_39;
V_190 . V_208 = V_207 ;
V_190 . V_209 = V_184 -> V_212 ;
V_190 . V_211 = F_77 ( V_184 -> V_206 ) ;
V_187 = F_126 ( V_56 ,
(struct V_205 * ) & V_190 ,
sizeof( V_190 ) , 0 ) ;
if ( V_187 < 0 )
goto V_39;
}
if ( ! V_184 -> V_213 )
V_56 -> V_57 -> V_63 = V_164 ;
break;
case V_167 :
#if F_46 ( V_64 )
if ( V_184 -> V_197 && V_184 -> V_198 ) {
V_187 = F_124 ( V_199 , V_200 , V_214 ,
V_186 ) ;
if ( V_187 < 0 )
goto V_39;
V_56 = * V_186 ;
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
V_194 . V_215 = V_199 ;
memcpy ( & V_194 . V_216 , V_184 -> V_197 ,
sizeof( V_194 . V_216 ) ) ;
V_194 . V_217 = V_24 ;
V_187 = F_125 ( V_56 , (struct V_205 * ) & V_194 ,
sizeof( V_194 ) ) ;
if ( V_187 < 0 )
goto V_39;
V_194 . V_215 = V_199 ;
memcpy ( & V_194 . V_216 , V_184 -> V_198 ,
sizeof( V_194 . V_216 ) ) ;
V_194 . V_217 = V_118 ;
V_187 = F_126 ( V_56 ,
(struct V_205 * ) & V_194 ,
sizeof( V_194 ) , 0 ) ;
if ( V_187 < 0 )
goto V_39;
} else
#endif
{
V_187 = F_124 ( V_207 , V_200 , V_214 ,
V_186 ) ;
if ( V_187 < 0 )
goto V_39;
V_56 = * V_186 ;
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
V_196 . V_215 = V_207 ;
V_196 . V_216 = V_184 -> V_210 ;
V_196 . V_217 = V_24 ;
V_187 = F_125 ( V_56 , (struct V_205 * ) & V_196 ,
sizeof( V_196 ) ) ;
if ( V_187 < 0 )
goto V_39;
V_196 . V_215 = V_207 ;
V_196 . V_216 = V_184 -> V_212 ;
V_196 . V_217 = V_118 ;
V_187 = F_126 ( V_56 , (struct V_205 * ) & V_196 ,
sizeof( V_196 ) , 0 ) ;
if ( V_187 < 0 )
goto V_39;
}
break;
default:
goto V_39;
}
V_39:
if ( ( V_187 < 0 ) && V_56 ) {
F_127 ( V_56 ) ;
* V_186 = NULL ;
}
return V_187 ;
}
int F_128 ( struct V_2 * V_2 , int V_218 , int V_46 , T_1 V_24 , T_1 V_118 , struct V_183 * V_184 , struct V_4 * * V_219 )
{
struct V_4 * V_5 = NULL ;
int V_187 ;
struct V_185 * V_56 = NULL ;
struct V_56 * V_57 = NULL ;
struct V_1 * V_9 ;
enum V_220 V_120 = V_121 ;
if ( V_218 < 0 ) {
V_187 = F_123 ( V_24 , V_118 , V_184 , & V_56 ) ;
if ( V_187 < 0 )
goto V_187;
} else {
V_187 = - V_221 ;
V_56 = F_129 ( V_218 , & V_187 ) ;
if ( ! V_56 ) {
F_130 ( L_30 ,
V_24 , V_218 , V_187 ) ;
goto V_187;
}
}
V_57 = V_56 -> V_57 ;
if ( V_184 != NULL )
V_120 = V_184 -> V_120 ;
switch ( V_120 ) {
case V_121 :
V_187 = - V_222 ;
if ( V_57 -> V_223 != V_73 ) {
F_130 ( L_31 ,
V_24 , V_218 , V_57 -> V_223 , V_73 ) ;
goto V_187;
}
break;
case V_167 :
V_187 = - V_222 ;
if ( V_57 -> V_223 != V_214 ) {
F_130 ( L_31 ,
V_24 , V_218 , V_57 -> V_223 , V_214 ) ;
goto V_187;
}
break;
}
V_5 = (struct V_4 * ) V_57 -> V_168 ;
if ( V_5 != NULL ) {
V_187 = - V_224 ;
goto V_187;
}
V_5 = F_131 ( sizeof( struct V_4 ) , V_225 ) ;
if ( V_5 == NULL ) {
V_187 = - V_226 ;
goto V_187;
}
V_5 -> V_46 = V_46 ;
V_5 -> V_24 = V_24 ;
V_5 -> V_118 = V_118 ;
V_5 -> V_105 = V_227 ;
V_5 -> V_228 = V_229 ;
sprintf ( & V_5 -> V_36 [ 0 ] , L_32 , V_24 ) ;
F_132 ( & V_5 -> V_17 ) ;
V_5 -> V_1 = V_2 ;
V_9 = F_1 ( V_2 ) ;
if ( V_184 != NULL )
V_5 -> V_105 = V_184 -> V_105 ;
V_5 -> V_120 = V_120 ;
if ( V_120 == V_121 ) {
F_110 ( V_57 ) -> V_171 = V_230 ;
F_110 ( V_57 ) -> V_172 = F_73 ;
#if F_46 ( V_64 )
if ( V_57 -> V_65 == V_66 )
F_133 () ;
else
#endif
F_134 () ;
}
V_57 -> V_168 = V_5 ;
V_5 -> V_174 = V_57 -> V_173 ;
V_57 -> V_173 = & F_108 ;
V_5 -> V_56 = V_57 ;
V_57 -> V_231 = V_232 ;
F_135 ( & V_5 -> V_181 ) ;
F_5 ( & V_182 ) ;
F_136 ( V_5 ) ;
F_27 ( & V_9 -> V_180 ) ;
F_137 ( & V_5 -> V_181 , & V_9 -> V_233 ) ;
F_35 ( & V_9 -> V_180 ) ;
V_187 = 0 ;
V_187:
if ( V_219 )
* V_219 = V_5 ;
if ( V_56 && V_56 -> V_234 )
F_138 ( V_56 ) ;
return V_187 ;
}
int F_139 ( struct V_4 * V_5 )
{
int V_187 = 0 ;
struct V_185 * V_56 = V_5 -> V_56 ? V_5 -> V_56 -> V_235 : NULL ;
if ( V_56 != NULL ) {
V_187 = F_140 ( V_56 , 2 ) ;
if ( V_56 -> V_234 == NULL )
V_187 = F_141 ( V_56 ) ;
}
return V_187 ;
}
void F_142 ( struct V_7 * V_12 )
{
struct V_4 * V_5 ;
F_2 ( F_119 ( & V_12 -> V_6 ) != 0 ) ;
V_5 = V_12 -> V_5 ;
if ( V_5 != NULL ) {
F_2 ( V_5 -> V_228 != V_229 ) ;
F_112 ( & V_5 -> V_17 ) ;
F_115 ( & V_12 -> V_176 ) ;
F_116 ( & V_5 -> V_17 ) ;
if ( V_5 -> V_46 != V_47 ) {
struct V_1 * V_9 = F_1 ( V_5 -> V_1 ) ;
F_27 ( & V_9 -> V_177 ) ;
F_117 ( & V_12 -> V_178 ) ;
F_35 ( & V_9 -> V_177 ) ;
F_118 () ;
}
if ( V_12 -> V_8 != 0 )
F_121 ( & V_236 ) ;
F_75 ( V_5 -> V_56 ) ;
V_12 -> V_5 = NULL ;
F_111 ( V_5 ) ;
}
F_122 ( V_12 ) ;
return;
}
int F_143 ( struct V_7 * V_12 )
{
if ( V_12 -> V_179 != NULL )
(* V_12 -> V_179 )( V_12 ) ;
F_66 ( V_12 ) ;
return 0 ;
}
static void F_61 ( struct V_7 * V_12 , int V_46 )
{
if ( V_46 == V_47 ) {
V_12 -> V_146 = 6 ;
if ( V_12 -> V_98 )
V_12 -> V_146 += 4 ;
} else {
V_12 -> V_146 = 4 + V_12 -> V_123 + V_12 -> V_96 + V_12 -> V_83 ;
if ( V_12 -> V_5 -> V_120 == V_121 )
V_12 -> V_146 += 4 ;
}
}
struct V_7 * F_144 ( int V_237 , struct V_4 * V_5 , T_1 V_8 , T_1 V_119 , struct V_238 * V_184 )
{
struct V_7 * V_12 ;
V_12 = F_131 ( sizeof( struct V_7 ) + V_237 , V_225 ) ;
if ( V_12 != NULL ) {
V_12 -> V_228 = V_239 ;
V_12 -> V_5 = V_5 ;
V_12 -> V_8 = V_8 ;
V_12 -> V_119 = V_119 ;
V_12 -> V_45 = 0 ;
sprintf ( & V_12 -> V_36 [ 0 ] , L_33 ,
V_5 -> V_24 , V_12 -> V_8 ) ;
F_145 ( & V_12 -> V_32 ) ;
F_146 ( & V_12 -> V_176 ) ;
F_146 ( & V_12 -> V_178 ) ;
V_12 -> V_105 = V_5 -> V_105 ;
if ( V_184 ) {
V_12 -> V_240 = V_184 -> V_241 ;
V_12 -> V_105 = V_184 -> V_105 ;
V_12 -> V_242 = V_184 -> V_242 ;
V_12 -> V_243 = V_184 -> V_243 ;
V_12 -> V_98 = V_184 -> V_98 ;
V_12 -> V_99 = V_184 -> V_99 ;
V_12 -> V_97 = V_184 -> V_97 ;
V_12 -> V_101 = V_184 -> V_101 ;
V_12 -> V_83 = V_184 -> V_83 ;
V_12 -> V_92 = V_184 -> V_92 ;
V_12 -> V_96 = V_184 -> V_96 ;
V_12 -> V_123 = V_184 -> V_123 ;
memcpy ( & V_12 -> V_124 [ 0 ] , & V_184 -> V_124 [ 0 ] , V_184 -> V_123 ) ;
V_12 -> V_85 = V_184 -> V_85 ;
memcpy ( & V_12 -> V_86 [ 0 ] , & V_184 -> V_86 [ 0 ] , V_184 -> V_85 ) ;
}
if ( V_5 -> V_46 == V_47 )
V_12 -> V_153 = F_76 ;
else
V_12 -> V_153 = F_78 ;
F_61 ( V_12 , V_5 -> V_46 ) ;
F_58 ( V_12 ) ;
F_136 ( V_5 ) ;
F_86 ( V_5 -> V_56 ) ;
F_112 ( & V_5 -> V_17 ) ;
F_147 ( & V_12 -> V_176 ,
F_14 ( V_5 , V_8 ) ) ;
F_116 ( & V_5 -> V_17 ) ;
if ( V_5 -> V_46 != V_47 ) {
struct V_1 * V_9 = F_1 ( V_5 -> V_1 ) ;
F_27 ( & V_9 -> V_177 ) ;
F_148 ( & V_12 -> V_178 ,
F_10 ( V_9 , V_8 ) ) ;
F_35 ( & V_9 -> V_177 ) ;
}
if ( V_12 -> V_8 != 0 )
F_5 ( & V_236 ) ;
}
return V_12 ;
}
static T_5 int F_149 ( struct V_2 * V_2 )
{
struct V_1 * V_9 = F_3 ( V_2 , V_3 ) ;
int V_19 ;
F_135 ( & V_9 -> V_233 ) ;
F_150 ( & V_9 -> V_180 ) ;
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ )
F_151 ( & V_9 -> V_244 [ V_19 ] ) ;
F_150 ( & V_9 -> V_177 ) ;
return 0 ;
}
static int T_6 F_152 ( void )
{
int V_245 = 0 ;
V_245 = F_153 ( & V_246 ) ;
if ( V_245 )
goto V_39;
F_154 ( L_34 , V_247 ) ;
V_39:
return V_245 ;
}
static void T_7 F_155 ( void )
{
F_156 ( & V_246 ) ;
}
