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
}
V_11:
return V_10 ;
}
void F_11 ( struct V_7 * V_10 )
{
struct V_4 * V_5 = F_12 ( V_10 ) ;
if ( V_5 ) {
if ( V_5 -> V_12 >= 0 ) {
F_13 ( V_10 -> V_13 ) ;
}
F_14 ( V_10 ) ;
}
}
static struct V_14 * F_15 ( struct V_2 * V_2 , T_1 V_15 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
struct V_17 * V_18 =
F_16 ( V_16 , V_15 ) ;
struct V_14 * V_19 ;
struct V_20 * V_21 ;
F_17 () ;
F_18 (session, walk, session_list, global_hlist) {
if ( V_19 -> V_15 == V_15 ) {
F_19 () ;
return V_19 ;
}
}
F_19 () ;
return NULL ;
}
static inline struct V_17 *
F_20 ( struct V_4 * V_5 , T_1 V_15 )
{
return & V_5 -> V_22 [ F_21 ( V_15 , V_23 ) ] ;
}
struct V_14 * F_22 ( struct V_2 * V_2 , struct V_4 * V_5 , T_1 V_15 )
{
struct V_17 * V_18 ;
struct V_14 * V_19 ;
struct V_20 * V_21 ;
if ( V_5 == NULL )
return F_15 ( V_2 , V_15 ) ;
V_18 = F_20 ( V_5 , V_15 ) ;
F_23 ( & V_5 -> V_24 ) ;
F_24 (session, walk, session_list, hlist) {
if ( V_19 -> V_15 == V_15 ) {
F_25 ( & V_5 -> V_24 ) ;
return V_19 ;
}
}
F_25 ( & V_5 -> V_24 ) ;
return NULL ;
}
struct V_14 * F_26 ( struct V_4 * V_5 , int V_25 )
{
int V_26 ;
struct V_20 * V_21 ;
struct V_14 * V_19 ;
int V_27 = 0 ;
F_23 ( & V_5 -> V_24 ) ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
F_24 (session, walk, &tunnel->session_hlist[hash], hlist) {
if ( ++ V_27 > V_25 ) {
F_25 ( & V_5 -> V_24 ) ;
return V_19 ;
}
}
}
F_25 ( & V_5 -> V_24 ) ;
return NULL ;
}
struct V_14 * F_27 ( struct V_2 * V_2 , char * V_29 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
int V_26 ;
struct V_20 * V_21 ;
struct V_14 * V_19 ;
F_17 () ;
for ( V_26 = 0 ; V_26 < V_30 ; V_26 ++ ) {
F_18 (session, walk, &pn->l2tp_session_hlist[hash], global_hlist) {
if ( ! strcmp ( V_19 -> V_29 , V_29 ) ) {
F_19 () ;
return V_19 ;
}
}
}
F_19 () ;
return NULL ;
}
struct V_4 * F_28 ( struct V_2 * V_2 , T_1 V_31 )
{
struct V_4 * V_5 ;
struct V_1 * V_16 = F_1 ( V_2 ) ;
F_17 () ;
F_29 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( V_5 -> V_31 == V_31 ) {
F_19 () ;
return V_5 ;
}
}
F_19 () ;
return NULL ;
}
struct V_4 * F_30 ( struct V_2 * V_2 , int V_25 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
struct V_4 * V_5 ;
int V_27 = 0 ;
F_17 () ;
F_29 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( ++ V_27 > V_25 ) {
F_19 () ;
return V_5 ;
}
}
F_19 () ;
return NULL ;
}
static void F_31 ( struct V_14 * V_19 , struct V_32 * V_33 )
{
struct V_32 * V_34 ;
struct V_32 * V_35 ;
T_1 V_36 = F_32 ( V_33 ) -> V_36 ;
struct V_37 * V_38 ;
F_33 ( & V_19 -> V_39 . V_40 ) ;
V_38 = & V_19 -> V_41 ;
F_34 (&session->reorder_q, skbp, tmp) {
if ( F_32 ( V_34 ) -> V_36 > V_36 ) {
F_35 ( & V_19 -> V_39 , V_34 , V_33 ) ;
F_36 ( V_19 , V_42 ,
L_1 ,
V_19 -> V_43 , V_36 , F_32 ( V_34 ) -> V_36 ,
F_37 ( & V_19 -> V_39 ) ) ;
F_38 ( & V_38 -> V_44 ) ;
V_38 -> V_45 ++ ;
F_39 ( & V_38 -> V_44 ) ;
goto V_11;
}
}
F_40 ( & V_19 -> V_39 , V_33 ) ;
V_11:
F_41 ( & V_19 -> V_39 . V_40 ) ;
}
static void F_42 ( struct V_14 * V_19 , struct V_32 * V_33 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
int V_46 = F_32 ( V_33 ) -> V_46 ;
struct V_37 * V_47 , * V_38 ;
F_43 ( V_33 ) ;
V_47 = & V_5 -> V_41 ;
F_38 ( & V_47 -> V_44 ) ;
V_38 = & V_19 -> V_41 ;
F_38 ( & V_38 -> V_44 ) ;
V_47 -> V_48 ++ ;
V_47 -> V_49 += V_46 ;
V_38 -> V_48 ++ ;
V_38 -> V_49 += V_46 ;
F_39 ( & V_47 -> V_44 ) ;
F_39 ( & V_38 -> V_44 ) ;
if ( F_32 ( V_33 ) -> V_50 ) {
V_19 -> V_51 ++ ;
if ( V_5 -> V_52 == V_53 )
V_19 -> V_51 &= 0xffff ;
else
V_19 -> V_51 &= 0xffffff ;
F_36 ( V_19 , V_42 , L_2 ,
V_19 -> V_43 , V_19 -> V_51 ) ;
}
if ( V_19 -> V_54 != NULL )
(* V_19 -> V_54 )( V_19 , V_33 , F_32 ( V_33 ) -> V_46 ) ;
else
F_44 ( V_33 ) ;
if ( V_19 -> V_55 )
(* V_19 -> V_55 )( V_19 ) ;
}
static void F_45 ( struct V_14 * V_19 )
{
struct V_32 * V_33 ;
struct V_32 * V_35 ;
struct V_37 * V_38 ;
V_56:
F_33 ( & V_19 -> V_39 . V_40 ) ;
V_38 = & V_19 -> V_41 ;
F_34 (&session->reorder_q, skb, tmp) {
if ( F_46 ( V_57 , F_32 ( V_33 ) -> V_58 ) ) {
F_38 ( & V_38 -> V_44 ) ;
V_38 -> V_59 ++ ;
V_38 -> V_60 ++ ;
F_39 ( & V_38 -> V_44 ) ;
F_36 ( V_19 , V_42 ,
L_3 ,
V_19 -> V_43 , F_32 ( V_33 ) -> V_36 ,
F_32 ( V_33 ) -> V_46 , V_19 -> V_51 ,
F_37 ( & V_19 -> V_39 ) ) ;
V_19 -> V_61 = 1 ;
F_47 ( V_33 , & V_19 -> V_39 ) ;
F_44 ( V_33 ) ;
if ( V_19 -> V_55 )
(* V_19 -> V_55 )( V_19 ) ;
continue;
}
if ( F_32 ( V_33 ) -> V_50 ) {
if ( V_19 -> V_61 ) {
F_36 ( V_19 , V_42 ,
L_4 ,
V_19 -> V_43 , V_19 -> V_51 ,
F_32 ( V_33 ) -> V_36 ) ;
V_19 -> V_61 = 0 ;
V_19 -> V_51 = F_32 ( V_33 ) -> V_36 ;
}
if ( F_32 ( V_33 ) -> V_36 != V_19 -> V_51 ) {
F_36 ( V_19 , V_42 ,
L_5 ,
V_19 -> V_43 , F_32 ( V_33 ) -> V_36 ,
F_32 ( V_33 ) -> V_46 , V_19 -> V_51 ,
F_37 ( & V_19 -> V_39 ) ) ;
goto V_11;
}
}
F_47 ( V_33 , & V_19 -> V_39 ) ;
F_41 ( & V_19 -> V_39 . V_40 ) ;
F_42 ( V_19 , V_33 ) ;
goto V_56;
}
V_11:
F_41 ( & V_19 -> V_39 . V_40 ) ;
}
static inline int F_48 ( struct V_7 * V_10 ,
struct V_32 * V_33 )
{
struct V_62 * V_63 = F_49 ( V_33 ) ;
T_2 V_64 = F_50 ( V_63 -> V_65 ) ;
T_3 V_66 ;
if ( V_10 -> V_67 || F_51 ( V_33 ) )
return 0 ;
#if F_52 ( V_68 )
if ( V_10 -> V_69 == V_70 ) {
if ( ! V_63 -> V_71 ) {
F_53 ( V_72 L_6 ) ;
return 1 ;
}
if ( ( V_33 -> V_73 == V_74 ) &&
! F_54 ( & F_55 ( V_33 ) -> V_75 ,
& F_55 ( V_33 ) -> V_76 , V_64 ,
V_77 , V_33 -> V_78 ) ) {
V_33 -> V_73 = V_79 ;
return 0 ;
}
V_33 -> V_78 = ~ F_56 ( F_54 ( & F_55 ( V_33 ) -> V_75 ,
& F_55 ( V_33 ) -> V_76 ,
V_33 -> V_65 , V_77 ,
0 ) ) ;
} else
#endif
{
struct V_80 * V_81 ;
if ( ! V_63 -> V_71 )
return 0 ;
V_81 = F_57 ( V_10 ) ;
V_66 = F_58 ( V_81 -> V_82 , V_81 -> V_83 ,
V_64 , V_77 , 0 ) ;
if ( ( V_33 -> V_73 == V_74 ) &&
! F_59 ( F_60 ( V_66 , V_33 -> V_78 ) ) )
return 0 ;
V_33 -> V_78 = V_66 ;
}
return F_61 ( V_33 ) ;
}
void F_62 ( struct V_14 * V_19 , struct V_32 * V_33 ,
unsigned char * V_84 , unsigned char * V_85 , T_2 V_86 ,
int V_46 , int (* F_63)( struct V_32 * V_33 ) )
{
struct V_4 * V_5 = V_19 -> V_5 ;
int V_87 ;
T_1 V_36 , V_51 ;
struct V_37 * V_38 = & V_19 -> V_41 ;
F_64 ( V_19 ) ;
if ( V_19 -> V_88 )
(* V_19 -> V_88 )( V_19 ) ;
if ( V_19 -> V_89 > 0 ) {
if ( memcmp ( V_84 , & V_19 -> V_90 [ 0 ] , V_19 -> V_89 ) ) {
F_65 ( V_5 , V_91 ,
L_7 ,
V_5 -> V_43 , V_5 -> V_31 ,
V_19 -> V_15 ) ;
F_38 ( & V_38 -> V_44 ) ;
V_38 -> V_92 ++ ;
F_39 ( & V_38 -> V_44 ) ;
goto V_93;
}
V_84 += V_19 -> V_89 ;
}
V_36 = V_51 = 0 ;
F_32 ( V_33 ) -> V_50 = 0 ;
if ( V_5 -> V_52 == V_53 ) {
if ( V_86 & V_94 ) {
V_36 = F_50 ( * ( V_95 * ) V_84 ) ;
V_84 += 2 ;
V_51 = F_50 ( * ( V_95 * ) V_84 ) ;
V_84 += 2 ;
F_32 ( V_33 ) -> V_36 = V_36 ;
F_32 ( V_33 ) -> V_50 = 1 ;
F_36 ( V_19 , V_42 ,
L_8 ,
V_19 -> V_43 , V_36 , V_51 , V_19 -> V_51 ) ;
}
} else if ( V_19 -> V_96 == V_97 ) {
T_1 V_98 = F_66 ( * ( V_99 * ) V_84 ) ;
if ( V_98 & 0x40000000 ) {
V_36 = V_98 & 0x00ffffff ;
F_32 ( V_33 ) -> V_36 = V_36 ;
F_32 ( V_33 ) -> V_50 = 1 ;
F_36 ( V_19 , V_42 ,
L_9 ,
V_19 -> V_43 , V_36 , V_19 -> V_51 ) ;
}
}
V_84 += V_19 -> V_100 ;
if ( F_32 ( V_33 ) -> V_50 ) {
if ( ( ! V_19 -> V_101 ) && ( ! V_19 -> V_102 ) ) {
F_65 ( V_19 , V_42 ,
L_10 ,
V_19 -> V_43 ) ;
V_19 -> V_102 = - 1 ;
F_67 ( V_19 , V_5 -> V_52 ) ;
}
} else {
if ( V_19 -> V_103 ) {
F_68 ( V_19 , V_42 ,
L_11 ,
V_19 -> V_43 ) ;
F_38 ( & V_38 -> V_44 ) ;
V_38 -> V_59 ++ ;
F_39 ( & V_38 -> V_44 ) ;
goto V_93;
}
if ( ( ! V_19 -> V_101 ) && ( V_19 -> V_102 ) ) {
F_65 ( V_19 , V_42 ,
L_12 ,
V_19 -> V_43 ) ;
V_19 -> V_102 = 0 ;
F_67 ( V_19 , V_5 -> V_52 ) ;
} else if ( V_19 -> V_102 ) {
F_68 ( V_19 , V_42 ,
L_11 ,
V_19 -> V_43 ) ;
F_38 ( & V_38 -> V_44 ) ;
V_38 -> V_59 ++ ;
F_39 ( & V_38 -> V_44 ) ;
goto V_93;
}
}
if ( V_5 -> V_52 == V_53 ) {
if ( V_86 & V_104 ) {
V_87 = F_50 ( * ( V_95 * ) V_84 ) ;
V_84 += 2 + V_87 ;
}
} else
V_84 += V_19 -> V_87 ;
V_87 = V_84 - V_85 ;
if ( ! F_69 ( V_33 , V_87 ) )
goto V_93;
F_70 ( V_33 , V_87 ) ;
if ( F_63 )
if ( (* F_63)( V_33 ) )
goto V_93;
F_32 ( V_33 ) -> V_46 = V_46 ;
F_32 ( V_33 ) -> V_58 = V_57 +
( V_19 -> V_105 ? V_19 -> V_105 : V_106 ) ;
if ( F_32 ( V_33 ) -> V_50 ) {
if ( V_19 -> V_105 != 0 ) {
F_31 ( V_19 , V_33 ) ;
} else {
if ( F_32 ( V_33 ) -> V_36 != V_19 -> V_51 ) {
F_38 ( & V_38 -> V_44 ) ;
V_38 -> V_59 ++ ;
F_39 ( & V_38 -> V_44 ) ;
F_36 ( V_19 , V_42 ,
L_13 ,
V_19 -> V_43 , F_32 ( V_33 ) -> V_36 ,
F_32 ( V_33 ) -> V_46 , V_19 -> V_51 ,
F_37 ( & V_19 -> V_39 ) ) ;
goto V_93;
}
F_71 ( & V_19 -> V_39 , V_33 ) ;
}
} else {
F_71 ( & V_19 -> V_39 , V_33 ) ;
}
F_45 ( V_19 ) ;
F_72 ( V_19 ) ;
return;
V_93:
F_38 ( & V_38 -> V_44 ) ;
V_38 -> V_60 ++ ;
F_39 ( & V_38 -> V_44 ) ;
F_44 ( V_33 ) ;
if ( V_19 -> V_55 )
(* V_19 -> V_55 )( V_19 ) ;
F_72 ( V_19 ) ;
}
static int F_73 ( struct V_4 * V_5 , struct V_32 * V_33 ,
int (* F_63)( struct V_32 * V_33 ) )
{
struct V_14 * V_19 = NULL ;
unsigned char * V_84 , * V_85 ;
T_2 V_86 ;
T_1 V_31 , V_15 ;
T_2 V_52 ;
int V_46 ;
struct V_37 * V_47 ;
if ( V_5 -> V_7 && F_48 ( V_5 -> V_7 , V_33 ) )
goto V_107;
F_70 ( V_33 , sizeof( struct V_62 ) ) ;
if ( ! F_69 ( V_33 , V_108 ) ) {
F_65 ( V_5 , V_91 ,
L_14 ,
V_5 -> V_43 , V_33 -> V_65 ) ;
goto error;
}
if ( V_5 -> V_109 & V_91 ) {
V_46 = F_74 ( 32u , V_33 -> V_65 ) ;
if ( ! F_69 ( V_33 , V_46 ) )
goto error;
F_75 ( L_15 , V_5 -> V_43 ) ;
F_76 ( L_16 , V_110 , V_33 -> V_111 , V_46 ) ;
}
V_85 = V_84 = V_33 -> V_111 ;
V_86 = F_50 ( * ( V_95 * ) V_84 ) ;
V_52 = V_86 & V_112 ;
if ( V_52 != V_5 -> V_52 ) {
F_65 ( V_5 , V_91 ,
L_17 ,
V_5 -> V_43 , V_52 , V_5 -> V_52 ) ;
goto error;
}
V_46 = V_33 -> V_65 ;
if ( V_86 & V_113 ) {
F_36 ( V_5 , V_91 ,
L_18 ,
V_5 -> V_43 , V_46 ) ;
goto error;
}
V_84 += 2 ;
if ( V_5 -> V_52 == V_53 ) {
if ( V_86 & V_114 )
V_84 += 2 ;
V_31 = F_50 ( * ( V_95 * ) V_84 ) ;
V_84 += 2 ;
V_15 = F_50 ( * ( V_95 * ) V_84 ) ;
V_84 += 2 ;
} else {
V_84 += 2 ;
V_31 = V_5 -> V_31 ;
V_15 = F_66 ( * ( V_99 * ) V_84 ) ;
V_84 += 4 ;
}
V_19 = F_22 ( V_5 -> V_1 , V_5 , V_15 ) ;
if ( ! V_19 || ! V_19 -> V_54 ) {
F_65 ( V_5 , V_91 ,
L_19 ,
V_5 -> V_43 , V_31 , V_15 ) ;
goto error;
}
F_62 ( V_19 , V_33 , V_84 , V_85 , V_86 , V_46 , F_63 ) ;
return 0 ;
V_107:
F_53 ( L_20 , V_5 -> V_43 ) ;
F_77 ( V_5 -> V_1 , V_115 , 0 ) ;
V_47 = & V_5 -> V_41 ;
F_38 ( & V_47 -> V_44 ) ;
V_47 -> V_60 ++ ;
F_39 ( & V_47 -> V_44 ) ;
F_44 ( V_33 ) ;
return 0 ;
error:
F_78 ( V_33 , sizeof( struct V_62 ) ) ;
return 1 ;
}
int F_79 ( struct V_7 * V_10 , struct V_32 * V_33 )
{
struct V_4 * V_5 ;
V_5 = F_12 ( V_10 ) ;
if ( V_5 == NULL )
goto V_116;
F_36 ( V_5 , V_91 , L_21 ,
V_5 -> V_43 , V_33 -> V_65 ) ;
if ( F_73 ( V_5 , V_33 , V_5 -> V_117 ) )
goto V_118;
F_14 ( V_10 ) ;
return 0 ;
V_118:
F_14 ( V_10 ) ;
V_116:
return 1 ;
}
static int F_80 ( struct V_14 * V_19 , void * V_119 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
V_95 * V_120 = V_119 ;
V_95 * V_85 = V_119 ;
T_2 V_121 = V_53 ;
T_1 V_31 = V_5 -> V_122 ;
T_1 V_15 = V_19 -> V_123 ;
if ( V_19 -> V_102 )
V_121 |= V_94 ;
* V_120 ++ = F_81 ( V_121 ) ;
* V_120 ++ = F_81 ( V_31 ) ;
* V_120 ++ = F_81 ( V_15 ) ;
if ( V_19 -> V_102 ) {
* V_120 ++ = F_81 ( V_19 -> V_36 ) ;
* V_120 ++ = 0 ;
V_19 -> V_36 ++ ;
V_19 -> V_36 &= 0xffff ;
F_36 ( V_19 , V_42 , L_22 ,
V_19 -> V_43 , V_19 -> V_36 ) ;
}
return V_120 - V_85 ;
}
static int F_82 ( struct V_14 * V_19 , void * V_119 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
char * V_120 = V_119 ;
char * V_85 = V_120 ;
if ( V_5 -> V_124 == V_125 ) {
T_2 V_121 = V_126 ;
* ( ( V_95 * ) V_120 ) = F_81 ( V_121 ) ;
V_120 += 2 ;
* ( ( V_95 * ) V_120 ) = 0 ;
V_120 += 2 ;
}
* ( ( V_99 * ) V_120 ) = F_83 ( V_19 -> V_123 ) ;
V_120 += 4 ;
if ( V_19 -> V_127 ) {
memcpy ( V_120 , & V_19 -> V_128 [ 0 ] , V_19 -> V_127 ) ;
V_120 += V_19 -> V_127 ;
}
if ( V_19 -> V_100 ) {
if ( V_19 -> V_96 == V_97 ) {
T_1 V_98 = 0 ;
if ( V_19 -> V_102 ) {
V_98 = 0x40000000 | V_19 -> V_36 ;
V_19 -> V_36 ++ ;
V_19 -> V_36 &= 0xffffff ;
F_36 ( V_19 , V_42 ,
L_22 ,
V_19 -> V_43 , V_19 -> V_36 ) ;
}
* ( ( V_99 * ) V_120 ) = F_83 ( V_98 ) ;
}
V_120 += V_19 -> V_100 ;
}
if ( V_19 -> V_87 )
V_120 += V_19 -> V_87 ;
return V_120 - V_85 ;
}
static int F_84 ( struct V_14 * V_19 , struct V_32 * V_33 ,
struct V_129 * V_130 , T_4 V_131 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
unsigned int V_65 = V_33 -> V_65 ;
int error ;
struct V_37 * V_47 , * V_38 ;
if ( V_19 -> V_102 )
F_36 ( V_19 , V_91 , L_23 ,
V_19 -> V_43 , V_131 , V_19 -> V_36 - 1 ) ;
else
F_36 ( V_19 , V_91 , L_24 ,
V_19 -> V_43 , V_131 ) ;
if ( V_19 -> V_109 & V_91 ) {
int V_132 = ( V_5 -> V_124 == V_125 ) ? sizeof( struct V_62 ) : 0 ;
unsigned char * V_133 = V_33 -> V_111 + V_132 ;
F_75 ( L_25 , V_19 -> V_43 ) ;
F_76 ( L_16 , V_110 ,
V_133 , F_85 ( T_4 , 32 , V_65 - V_132 ) ) ;
}
V_33 -> V_134 = 1 ;
#if F_52 ( V_68 )
if ( V_33 -> V_10 -> V_69 == V_70 )
error = F_86 ( V_33 , NULL ) ;
else
#endif
error = F_87 ( V_33 , V_130 ) ;
V_47 = & V_5 -> V_41 ;
F_38 ( & V_47 -> V_44 ) ;
V_38 = & V_19 -> V_41 ;
F_38 ( & V_38 -> V_44 ) ;
if ( error >= 0 ) {
V_47 -> V_135 ++ ;
V_47 -> V_136 += V_65 ;
V_38 -> V_135 ++ ;
V_38 -> V_136 += V_65 ;
} else {
V_47 -> V_137 ++ ;
V_38 -> V_137 ++ ;
}
F_39 ( & V_47 -> V_44 ) ;
F_39 ( & V_38 -> V_44 ) ;
return 0 ;
}
static void F_88 ( struct V_32 * V_33 )
{
F_14 ( V_33 -> V_10 ) ;
}
static inline void F_89 ( struct V_32 * V_33 , struct V_7 * V_10 )
{
F_90 ( V_10 ) ;
V_33 -> V_10 = V_10 ;
V_33 -> V_138 = F_88 ;
}
static void F_91 ( struct V_7 * V_10 , struct V_32 * V_33 ,
int V_139 )
{
struct V_140 * V_141 = F_92 ( V_10 ) ;
struct V_62 * V_63 = F_49 ( V_33 ) ;
if ( ! F_93 ( V_33 ) || ! F_93 ( V_33 ) -> V_142 ||
! ( F_93 ( V_33 ) -> V_142 -> V_143 & V_144 ) ) {
T_3 V_78 = F_94 ( V_33 , 0 , V_139 , 0 ) ;
V_33 -> V_73 = V_79 ;
V_63 -> V_71 = F_54 ( & V_141 -> V_75 , & V_141 -> V_76 , V_139 ,
V_77 , V_78 ) ;
if ( V_63 -> V_71 == 0 )
V_63 -> V_71 = V_145 ;
} else {
V_33 -> V_73 = V_146 ;
V_33 -> V_147 = F_95 ( V_33 ) - V_33 -> V_148 ;
V_33 -> V_149 = F_96 ( struct V_62 , V_71 ) ;
V_63 -> V_71 = ~ F_54 ( & V_141 -> V_75 , & V_141 -> V_76 ,
V_139 , V_77 , 0 ) ;
}
}
int F_97 ( struct V_14 * V_19 , struct V_32 * V_33 , int V_150 )
{
int V_131 = V_33 -> V_65 ;
struct V_4 * V_5 = V_19 -> V_5 ;
struct V_7 * V_10 = V_5 -> V_7 ;
struct V_129 * V_130 ;
struct V_62 * V_63 ;
struct V_80 * V_81 ;
T_3 V_78 ;
int V_151 ;
int V_132 = ( V_5 -> V_124 == V_125 ) ? sizeof( struct V_62 ) : 0 ;
int V_139 ;
int V_152 = V_153 ;
V_151 = V_154 + sizeof( struct V_155 ) +
V_132 + V_150 ;
if ( F_98 ( V_33 , V_151 ) ) {
F_44 ( V_33 ) ;
return V_156 ;
}
F_43 ( V_33 ) ;
V_19 -> V_157 ( V_19 , F_78 ( V_33 , V_150 ) ) ;
memset ( & ( F_99 ( V_33 ) -> V_158 ) , 0 , sizeof( F_99 ( V_33 ) -> V_158 ) ) ;
F_99 ( V_33 ) -> V_121 &= ~ ( V_159 | V_160 |
V_161 ) ;
F_100 ( V_33 ) ;
F_101 ( V_10 ) ;
if ( F_102 ( V_10 ) ) {
F_44 ( V_33 ) ;
V_152 = V_156 ;
goto V_162;
}
F_103 ( V_33 ) ;
F_104 ( V_33 , F_105 ( F_106 ( V_10 , 0 ) ) ) ;
V_81 = F_57 ( V_10 ) ;
V_130 = & V_81 -> V_163 . V_130 ;
switch ( V_5 -> V_124 ) {
case V_125 :
F_78 ( V_33 , sizeof( * V_63 ) ) ;
F_107 ( V_33 ) ;
V_63 = F_49 ( V_33 ) ;
V_63 -> V_164 = V_81 -> V_165 ;
V_63 -> V_166 = V_81 -> V_167 ;
V_139 = V_132 + V_150 + V_131 ;
V_63 -> V_65 = F_81 ( V_139 ) ;
V_63 -> V_71 = 0 ;
#if F_52 ( V_68 )
if ( V_10 -> V_69 == V_70 )
F_91 ( V_10 , V_33 , V_139 ) ;
else
#endif
if ( V_10 -> V_67 == V_168 )
V_33 -> V_73 = V_169 ;
else if ( ( F_93 ( V_33 ) && F_93 ( V_33 ) -> V_142 ) &&
( ! ( F_93 ( V_33 ) -> V_142 -> V_143 & V_170 ) ) ) {
V_33 -> V_73 = V_74 ;
V_78 = F_94 ( V_33 , 0 , V_139 , 0 ) ;
V_63 -> V_71 = F_108 ( V_81 -> V_82 ,
V_81 -> V_83 ,
V_139 , V_77 , V_78 ) ;
if ( V_63 -> V_71 == 0 )
V_63 -> V_71 = V_145 ;
} else {
V_33 -> V_73 = V_146 ;
V_33 -> V_147 = F_95 ( V_33 ) - V_33 -> V_148 ;
V_33 -> V_149 = F_96 ( struct V_62 , V_71 ) ;
V_63 -> V_71 = ~ F_108 ( V_81 -> V_82 ,
V_81 -> V_83 ,
V_139 , V_77 , 0 ) ;
}
break;
case V_171 :
break;
}
F_89 ( V_33 , V_10 ) ;
F_84 ( V_19 , V_33 , V_130 , V_131 ) ;
V_162:
F_109 ( V_10 ) ;
return V_152 ;
}
static void F_110 ( struct V_7 * V_10 )
{
struct V_4 * V_5 ;
V_5 = V_10 -> V_172 ;
if ( V_5 == NULL )
goto V_173;
F_65 ( V_5 , V_174 , L_26 , V_5 -> V_43 ) ;
F_111 ( V_5 ) ;
switch ( V_5 -> V_124 ) {
case V_125 :
( F_112 ( V_10 ) ) -> V_175 = 0 ;
( F_112 ( V_10 ) ) -> V_176 = NULL ;
break;
case V_171 :
break;
}
V_5 -> V_7 = NULL ;
V_10 -> V_177 = V_5 -> V_178 ;
V_10 -> V_172 = NULL ;
if ( V_10 -> V_177 )
(* V_10 -> V_177 )( V_10 ) ;
F_113 ( V_5 ) ;
V_173:
return;
}
static void F_111 ( struct V_4 * V_5 )
{
int V_26 ;
struct V_20 * V_21 ;
struct V_20 * V_35 ;
struct V_14 * V_19 ;
F_2 ( V_5 == NULL ) ;
F_65 ( V_5 , V_174 , L_27 ,
V_5 -> V_43 ) ;
F_114 ( & V_5 -> V_24 ) ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
V_179:
F_115 (walk, tmp, &tunnel->session_hlist[hash]) {
V_19 = F_116 ( V_21 , struct V_14 , V_180 ) ;
F_65 ( V_19 , V_174 ,
L_28 , V_19 -> V_43 ) ;
F_117 ( & V_19 -> V_180 ) ;
if ( V_19 -> V_88 != NULL )
(* V_19 -> V_88 )( V_19 ) ;
F_118 ( & V_5 -> V_24 ) ;
if ( V_5 -> V_52 != V_53 ) {
struct V_1 * V_16 = F_1 ( V_5 -> V_1 ) ;
F_33 ( & V_16 -> V_181 ) ;
F_119 ( & V_19 -> V_182 ) ;
F_41 ( & V_16 -> V_181 ) ;
F_120 () ;
}
if ( V_19 -> V_183 != NULL )
(* V_19 -> V_183 )( V_19 ) ;
if ( V_19 -> V_55 != NULL )
(* V_19 -> V_55 )( V_19 ) ;
F_114 ( & V_5 -> V_24 ) ;
goto V_179;
}
}
F_118 ( & V_5 -> V_24 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_16 = F_1 ( V_5 -> V_1 ) ;
F_2 ( F_121 ( & V_5 -> V_6 ) != 0 ) ;
F_2 ( V_5 -> V_7 != NULL ) ;
F_65 ( V_5 , V_174 , L_29 , V_5 -> V_43 ) ;
F_33 ( & V_16 -> V_184 ) ;
F_122 ( & V_5 -> V_185 ) ;
F_123 ( V_5 , V_186 ) ;
F_41 ( & V_16 -> V_184 ) ;
F_124 ( & V_187 ) ;
}
static int F_125 ( T_1 V_31 , T_1 V_122 , struct V_188 * V_189 , struct V_9 * * V_190 )
{
int V_8 = - V_191 ;
struct V_192 V_193 ;
#if F_52 ( V_68 )
struct V_194 V_195 ;
struct V_196 V_197 ;
#endif
struct V_198 V_199 ;
struct V_9 * V_7 = NULL ;
switch ( V_189 -> V_124 ) {
case V_125 :
#if F_52 ( V_68 )
if ( V_189 -> V_200 && V_189 -> V_201 ) {
V_8 = F_126 ( V_202 , V_203 , 0 , V_190 ) ;
if ( V_8 < 0 )
goto V_11;
V_7 = * V_190 ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_204 = V_202 ;
memcpy ( & V_195 . V_205 , V_189 -> V_200 ,
sizeof( V_195 . V_205 ) ) ;
V_195 . V_206 = F_81 ( V_189 -> V_207 ) ;
V_8 = F_127 ( V_7 , (struct V_208 * ) & V_195 ,
sizeof( V_195 ) ) ;
if ( V_8 < 0 )
goto V_11;
V_195 . V_204 = V_202 ;
memcpy ( & V_195 . V_205 , V_189 -> V_201 ,
sizeof( V_195 . V_205 ) ) ;
V_195 . V_206 = F_81 ( V_189 -> V_209 ) ;
V_8 = F_128 ( V_7 ,
(struct V_208 * ) & V_195 ,
sizeof( V_195 ) , 0 ) ;
if ( V_8 < 0 )
goto V_11;
} else
#endif
{
V_8 = F_126 ( V_210 , V_203 , 0 , V_190 ) ;
if ( V_8 < 0 )
goto V_11;
V_7 = * V_190 ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
V_193 . V_211 = V_210 ;
V_193 . V_212 = V_189 -> V_213 ;
V_193 . V_214 = F_81 ( V_189 -> V_207 ) ;
V_8 = F_127 ( V_7 , (struct V_208 * ) & V_193 ,
sizeof( V_193 ) ) ;
if ( V_8 < 0 )
goto V_11;
V_193 . V_211 = V_210 ;
V_193 . V_212 = V_189 -> V_215 ;
V_193 . V_214 = F_81 ( V_189 -> V_209 ) ;
V_8 = F_128 ( V_7 ,
(struct V_208 * ) & V_193 ,
sizeof( V_193 ) , 0 ) ;
if ( V_8 < 0 )
goto V_11;
}
if ( ! V_189 -> V_216 )
V_7 -> V_10 -> V_67 = V_168 ;
break;
case V_171 :
#if F_52 ( V_68 )
if ( V_189 -> V_200 && V_189 -> V_201 ) {
V_8 = F_126 ( V_202 , V_203 , V_217 ,
V_190 ) ;
if ( V_8 < 0 )
goto V_11;
V_7 = * V_190 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_197 . V_218 = V_202 ;
memcpy ( & V_197 . V_219 , V_189 -> V_200 ,
sizeof( V_197 . V_219 ) ) ;
V_197 . V_220 = V_31 ;
V_8 = F_127 ( V_7 , (struct V_208 * ) & V_197 ,
sizeof( V_197 ) ) ;
if ( V_8 < 0 )
goto V_11;
V_197 . V_218 = V_202 ;
memcpy ( & V_197 . V_219 , V_189 -> V_201 ,
sizeof( V_197 . V_219 ) ) ;
V_197 . V_220 = V_122 ;
V_8 = F_128 ( V_7 ,
(struct V_208 * ) & V_197 ,
sizeof( V_197 ) , 0 ) ;
if ( V_8 < 0 )
goto V_11;
} else
#endif
{
V_8 = F_126 ( V_210 , V_203 , V_217 ,
V_190 ) ;
if ( V_8 < 0 )
goto V_11;
V_7 = * V_190 ;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
V_199 . V_218 = V_210 ;
V_199 . V_219 = V_189 -> V_213 ;
V_199 . V_220 = V_31 ;
V_8 = F_127 ( V_7 , (struct V_208 * ) & V_199 ,
sizeof( V_199 ) ) ;
if ( V_8 < 0 )
goto V_11;
V_199 . V_218 = V_210 ;
V_199 . V_219 = V_189 -> V_215 ;
V_199 . V_220 = V_122 ;
V_8 = F_128 ( V_7 , (struct V_208 * ) & V_199 ,
sizeof( V_199 ) , 0 ) ;
if ( V_8 < 0 )
goto V_11;
}
break;
default:
goto V_11;
}
V_11:
if ( ( V_8 < 0 ) && V_7 ) {
F_129 ( V_7 ) ;
* V_190 = NULL ;
}
return V_8 ;
}
int F_130 ( struct V_2 * V_2 , int V_12 , int V_52 , T_1 V_31 , T_1 V_122 , struct V_188 * V_189 , struct V_4 * * V_221 )
{
struct V_4 * V_5 = NULL ;
int V_8 ;
struct V_9 * V_7 = NULL ;
struct V_7 * V_10 = NULL ;
struct V_1 * V_16 ;
enum V_222 V_124 = V_125 ;
if ( V_12 < 0 ) {
V_8 = F_125 ( V_31 , V_122 , V_189 , & V_7 ) ;
if ( V_8 < 0 )
goto V_8;
} else {
V_8 = - V_223 ;
V_7 = F_10 ( V_12 , & V_8 ) ;
if ( ! V_7 ) {
F_131 ( L_30 ,
V_31 , V_12 , V_8 ) ;
goto V_8;
}
}
V_10 = V_7 -> V_10 ;
if ( V_189 != NULL )
V_124 = V_189 -> V_124 ;
switch ( V_124 ) {
case V_125 :
V_8 = - V_224 ;
if ( V_10 -> V_225 != V_77 ) {
F_131 ( L_31 ,
V_31 , V_12 , V_10 -> V_225 , V_77 ) ;
goto V_8;
}
break;
case V_171 :
V_8 = - V_224 ;
if ( V_10 -> V_225 != V_217 ) {
F_131 ( L_31 ,
V_31 , V_12 , V_10 -> V_225 , V_217 ) ;
goto V_8;
}
break;
}
V_5 = (struct V_4 * ) V_10 -> V_172 ;
if ( V_5 != NULL ) {
V_8 = - V_226 ;
goto V_8;
}
V_5 = F_132 ( sizeof( struct V_4 ) , V_227 ) ;
if ( V_5 == NULL ) {
V_8 = - V_228 ;
goto V_8;
}
V_5 -> V_52 = V_52 ;
V_5 -> V_31 = V_31 ;
V_5 -> V_122 = V_122 ;
V_5 -> V_109 = V_229 ;
V_5 -> V_230 = V_231 ;
sprintf ( & V_5 -> V_43 [ 0 ] , L_32 , V_31 ) ;
F_133 ( & V_5 -> V_24 ) ;
V_5 -> V_1 = V_2 ;
V_16 = F_1 ( V_2 ) ;
if ( V_189 != NULL )
V_5 -> V_109 = V_189 -> V_109 ;
V_5 -> V_124 = V_124 ;
if ( V_124 == V_125 ) {
F_112 ( V_10 ) -> V_175 = V_232 ;
F_112 ( V_10 ) -> V_176 = F_79 ;
#if F_52 ( V_68 )
if ( V_10 -> V_69 == V_70 )
F_134 () ;
else
#endif
F_135 () ;
}
V_10 -> V_172 = V_5 ;
V_5 -> V_178 = V_10 -> V_177 ;
V_10 -> V_177 = & F_110 ;
V_5 -> V_7 = V_10 ;
V_5 -> V_12 = V_12 ;
F_136 ( & V_10 -> V_233 . V_234 , & V_235 , L_33 ) ;
V_10 -> V_236 = V_237 ;
F_137 ( & V_5 -> V_185 ) ;
F_5 ( & V_187 ) ;
F_138 ( V_5 ) ;
F_33 ( & V_16 -> V_184 ) ;
F_139 ( & V_5 -> V_185 , & V_16 -> V_238 ) ;
F_41 ( & V_16 -> V_184 ) ;
V_8 = 0 ;
V_8:
if ( V_221 )
* V_221 = V_5 ;
if ( V_7 && V_7 -> V_239 )
F_13 ( V_7 ) ;
return V_8 ;
}
int F_140 ( struct V_4 * V_5 )
{
int V_8 = - V_223 ;
struct V_9 * V_7 = NULL ;
struct V_7 * V_10 = NULL ;
V_10 = F_9 ( V_5 ) ;
if ( ! V_10 )
goto V_11;
V_7 = V_10 -> V_13 ;
F_2 ( ! V_7 ) ;
V_8 = F_141 ( V_7 , 2 ) ;
if ( V_7 -> V_239 == NULL )
V_8 = F_142 ( V_7 ) ;
F_11 ( V_10 ) ;
V_11:
return V_8 ;
}
void F_143 ( struct V_14 * V_19 )
{
struct V_4 * V_5 ;
F_2 ( F_121 ( & V_19 -> V_6 ) != 0 ) ;
V_5 = V_19 -> V_5 ;
if ( V_5 != NULL ) {
F_2 ( V_5 -> V_230 != V_231 ) ;
F_114 ( & V_5 -> V_24 ) ;
F_117 ( & V_19 -> V_180 ) ;
F_118 ( & V_5 -> V_24 ) ;
if ( V_5 -> V_52 != V_53 ) {
struct V_1 * V_16 = F_1 ( V_5 -> V_1 ) ;
F_33 ( & V_16 -> V_181 ) ;
F_119 ( & V_19 -> V_182 ) ;
F_41 ( & V_16 -> V_181 ) ;
F_120 () ;
}
if ( V_19 -> V_15 != 0 )
F_124 ( & V_240 ) ;
F_14 ( V_5 -> V_7 ) ;
V_19 -> V_5 = NULL ;
F_113 ( V_5 ) ;
}
F_144 ( V_19 ) ;
return;
}
int F_145 ( struct V_14 * V_19 )
{
if ( V_19 -> V_183 != NULL )
(* V_19 -> V_183 )( V_19 ) ;
F_72 ( V_19 ) ;
return 0 ;
}
static void F_67 ( struct V_14 * V_19 , int V_52 )
{
if ( V_52 == V_53 ) {
V_19 -> V_150 = 6 ;
if ( V_19 -> V_102 )
V_19 -> V_150 += 4 ;
} else {
V_19 -> V_150 = 4 + V_19 -> V_127 + V_19 -> V_100 + V_19 -> V_87 ;
if ( V_19 -> V_5 -> V_124 == V_125 )
V_19 -> V_150 += 4 ;
}
}
struct V_14 * F_146 ( int V_241 , struct V_4 * V_5 , T_1 V_15 , T_1 V_123 , struct V_242 * V_189 )
{
struct V_14 * V_19 ;
V_19 = F_132 ( sizeof( struct V_14 ) + V_241 , V_227 ) ;
if ( V_19 != NULL ) {
V_19 -> V_230 = V_243 ;
V_19 -> V_5 = V_5 ;
V_19 -> V_15 = V_15 ;
V_19 -> V_123 = V_123 ;
V_19 -> V_51 = 0 ;
sprintf ( & V_19 -> V_43 [ 0 ] , L_34 ,
V_5 -> V_31 , V_19 -> V_15 ) ;
F_147 ( & V_19 -> V_39 ) ;
F_148 ( & V_19 -> V_180 ) ;
F_148 ( & V_19 -> V_182 ) ;
V_19 -> V_109 = V_5 -> V_109 ;
if ( V_189 ) {
V_19 -> V_244 = V_189 -> V_245 ;
V_19 -> V_109 = V_189 -> V_109 ;
V_19 -> V_246 = V_189 -> V_246 ;
V_19 -> V_247 = V_189 -> V_247 ;
V_19 -> V_102 = V_189 -> V_102 ;
V_19 -> V_103 = V_189 -> V_103 ;
V_19 -> V_101 = V_189 -> V_101 ;
V_19 -> V_105 = V_189 -> V_105 ;
V_19 -> V_87 = V_189 -> V_87 ;
V_19 -> V_96 = V_189 -> V_96 ;
V_19 -> V_100 = V_189 -> V_100 ;
V_19 -> V_127 = V_189 -> V_127 ;
memcpy ( & V_19 -> V_128 [ 0 ] , & V_189 -> V_128 [ 0 ] , V_189 -> V_127 ) ;
V_19 -> V_89 = V_189 -> V_89 ;
memcpy ( & V_19 -> V_90 [ 0 ] , & V_189 -> V_90 [ 0 ] , V_189 -> V_89 ) ;
}
if ( V_5 -> V_52 == V_53 )
V_19 -> V_157 = F_80 ;
else
V_19 -> V_157 = F_82 ;
F_67 ( V_19 , V_5 -> V_52 ) ;
F_64 ( V_19 ) ;
F_138 ( V_5 ) ;
F_90 ( V_5 -> V_7 ) ;
F_114 ( & V_5 -> V_24 ) ;
F_149 ( & V_19 -> V_180 ,
F_20 ( V_5 , V_15 ) ) ;
F_118 ( & V_5 -> V_24 ) ;
if ( V_5 -> V_52 != V_53 ) {
struct V_1 * V_16 = F_1 ( V_5 -> V_1 ) ;
F_33 ( & V_16 -> V_181 ) ;
F_150 ( & V_19 -> V_182 ,
F_16 ( V_16 , V_15 ) ) ;
F_41 ( & V_16 -> V_181 ) ;
}
if ( V_19 -> V_15 != 0 )
F_5 ( & V_240 ) ;
}
return V_19 ;
}
static T_5 int F_151 ( struct V_2 * V_2 )
{
struct V_1 * V_16 = F_3 ( V_2 , V_3 ) ;
int V_26 ;
F_137 ( & V_16 -> V_238 ) ;
F_152 ( & V_16 -> V_184 ) ;
for ( V_26 = 0 ; V_26 < V_30 ; V_26 ++ )
F_153 ( & V_16 -> V_248 [ V_26 ] ) ;
F_152 ( & V_16 -> V_181 ) ;
return 0 ;
}
static int T_6 F_154 ( void )
{
int V_249 = 0 ;
V_249 = F_155 ( & V_250 ) ;
if ( V_249 )
goto V_11;
F_156 ( L_35 , V_251 ) ;
V_11:
return V_249 ;
}
static void T_7 F_157 ( void )
{
F_158 ( & V_250 ) ;
}
