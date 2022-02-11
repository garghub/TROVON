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
if ( V_5 -> V_46 == V_47 )
V_19 -> V_45 &= 0xffff ;
else
V_19 -> V_45 &= 0xffffff ;
F_37 ( V_19 , V_37 , L_2 ,
V_19 -> V_38 , V_19 -> V_45 ) ;
}
if ( V_19 -> V_48 != NULL )
(* V_19 -> V_48 )( V_19 , V_31 , F_33 ( V_31 ) -> V_41 ) ;
else
F_45 ( V_31 ) ;
if ( V_19 -> V_49 )
(* V_19 -> V_49 )( V_19 ) ;
}
static void F_46 ( struct V_14 * V_19 )
{
struct V_30 * V_31 ;
struct V_30 * V_33 ;
V_50:
F_34 ( & V_19 -> V_35 . V_36 ) ;
F_35 (&session->reorder_q, skb, tmp) {
if ( F_47 ( V_51 , F_33 ( V_31 ) -> V_52 ) ) {
F_39 ( & V_19 -> V_39 . V_53 ) ;
F_39 ( & V_19 -> V_39 . V_54 ) ;
F_37 ( V_19 , V_37 ,
L_3 ,
V_19 -> V_38 , F_33 ( V_31 ) -> V_34 ,
F_33 ( V_31 ) -> V_41 , V_19 -> V_45 ,
F_38 ( & V_19 -> V_35 ) ) ;
V_19 -> V_55 = 1 ;
F_48 ( V_31 , & V_19 -> V_35 ) ;
F_45 ( V_31 ) ;
if ( V_19 -> V_49 )
(* V_19 -> V_49 )( V_19 ) ;
continue;
}
if ( F_33 ( V_31 ) -> V_44 ) {
if ( V_19 -> V_55 ) {
F_37 ( V_19 , V_37 ,
L_4 ,
V_19 -> V_38 , V_19 -> V_45 ,
F_33 ( V_31 ) -> V_34 ) ;
V_19 -> V_55 = 0 ;
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
goto V_50;
}
V_11:
F_41 ( & V_19 -> V_35 . V_36 ) ;
}
static inline int F_49 ( struct V_7 * V_10 ,
struct V_30 * V_31 )
{
struct V_56 * V_57 = F_50 ( V_31 ) ;
T_2 V_58 = F_51 ( V_57 -> V_59 ) ;
T_3 V_60 ;
if ( V_10 -> V_61 || F_52 ( V_31 ) )
return 0 ;
#if F_53 ( V_62 )
if ( V_10 -> V_63 == V_64 ) {
if ( ! V_57 -> V_65 ) {
F_54 ( V_66 L_6 ) ;
return 1 ;
}
if ( ( V_31 -> V_67 == V_68 ) &&
! F_55 ( & F_56 ( V_31 ) -> V_69 ,
& F_56 ( V_31 ) -> V_70 , V_58 ,
V_71 , V_31 -> V_72 ) ) {
V_31 -> V_67 = V_73 ;
return 0 ;
}
V_31 -> V_72 = ~ F_57 ( F_55 ( & F_56 ( V_31 ) -> V_69 ,
& F_56 ( V_31 ) -> V_70 ,
V_31 -> V_59 , V_71 ,
0 ) ) ;
} else
#endif
{
struct V_74 * V_75 ;
if ( ! V_57 -> V_65 )
return 0 ;
V_75 = F_58 ( V_10 ) ;
V_60 = F_59 ( V_75 -> V_76 , V_75 -> V_77 ,
V_58 , V_71 , 0 ) ;
if ( ( V_31 -> V_67 == V_68 ) &&
! F_60 ( F_61 ( V_60 , V_31 -> V_72 ) ) )
return 0 ;
V_31 -> V_72 = V_60 ;
}
return F_62 ( V_31 ) ;
}
void F_63 ( struct V_14 * V_19 , struct V_30 * V_31 ,
unsigned char * V_78 , unsigned char * V_79 , T_2 V_80 ,
int V_41 , int (* F_64)( struct V_30 * V_31 ) )
{
struct V_4 * V_5 = V_19 -> V_5 ;
int V_81 ;
T_1 V_34 , V_45 ;
F_65 ( V_19 ) ;
if ( V_19 -> V_82 )
(* V_19 -> V_82 )( V_19 ) ;
if ( V_19 -> V_83 > 0 ) {
if ( memcmp ( V_78 , & V_19 -> V_84 [ 0 ] , V_19 -> V_83 ) ) {
F_66 ( V_5 , V_85 ,
L_7 ,
V_5 -> V_38 , V_5 -> V_29 ,
V_19 -> V_15 ) ;
F_39 ( & V_19 -> V_39 . V_86 ) ;
goto V_87;
}
V_78 += V_19 -> V_83 ;
}
V_34 = V_45 = 0 ;
F_33 ( V_31 ) -> V_44 = 0 ;
if ( V_5 -> V_46 == V_47 ) {
if ( V_80 & V_88 ) {
V_34 = F_51 ( * ( V_89 * ) V_78 ) ;
V_78 += 2 ;
V_45 = F_51 ( * ( V_89 * ) V_78 ) ;
V_78 += 2 ;
F_33 ( V_31 ) -> V_34 = V_34 ;
F_33 ( V_31 ) -> V_44 = 1 ;
F_37 ( V_19 , V_37 ,
L_8 ,
V_19 -> V_38 , V_34 , V_45 , V_19 -> V_45 ) ;
}
} else if ( V_19 -> V_90 == V_91 ) {
T_1 V_92 = F_67 ( * ( V_93 * ) V_78 ) ;
if ( V_92 & 0x40000000 ) {
V_34 = V_92 & 0x00ffffff ;
F_33 ( V_31 ) -> V_34 = V_34 ;
F_33 ( V_31 ) -> V_44 = 1 ;
F_37 ( V_19 , V_37 ,
L_9 ,
V_19 -> V_38 , V_34 , V_19 -> V_45 ) ;
}
}
V_78 += V_19 -> V_94 ;
if ( F_33 ( V_31 ) -> V_44 ) {
if ( ( ! V_19 -> V_95 ) && ( ! V_19 -> V_96 ) ) {
F_66 ( V_19 , V_37 ,
L_10 ,
V_19 -> V_38 ) ;
V_19 -> V_96 = - 1 ;
F_68 ( V_19 , V_5 -> V_46 ) ;
}
} else {
if ( V_19 -> V_97 ) {
F_69 ( V_19 , V_37 ,
L_11 ,
V_19 -> V_38 ) ;
F_39 ( & V_19 -> V_39 . V_53 ) ;
goto V_87;
}
if ( ( ! V_19 -> V_95 ) && ( V_19 -> V_96 ) ) {
F_66 ( V_19 , V_37 ,
L_12 ,
V_19 -> V_38 ) ;
V_19 -> V_96 = 0 ;
F_68 ( V_19 , V_5 -> V_46 ) ;
} else if ( V_19 -> V_96 ) {
F_69 ( V_19 , V_37 ,
L_11 ,
V_19 -> V_38 ) ;
F_39 ( & V_19 -> V_39 . V_53 ) ;
goto V_87;
}
}
if ( V_5 -> V_46 == V_47 ) {
if ( V_80 & V_98 ) {
V_81 = F_51 ( * ( V_89 * ) V_78 ) ;
V_78 += 2 + V_81 ;
}
} else
V_78 += V_19 -> V_81 ;
V_81 = V_78 - V_79 ;
if ( ! F_70 ( V_31 , V_81 ) )
goto V_87;
F_71 ( V_31 , V_81 ) ;
if ( F_64 )
if ( (* F_64)( V_31 ) )
goto V_87;
F_33 ( V_31 ) -> V_41 = V_41 ;
F_33 ( V_31 ) -> V_52 = V_51 +
( V_19 -> V_99 ? V_19 -> V_99 : V_100 ) ;
if ( F_33 ( V_31 ) -> V_44 ) {
if ( V_19 -> V_99 != 0 ) {
F_32 ( V_19 , V_31 ) ;
} else {
if ( F_33 ( V_31 ) -> V_34 != V_19 -> V_45 ) {
F_39 ( & V_19 -> V_39 . V_53 ) ;
F_37 ( V_19 , V_37 ,
L_13 ,
V_19 -> V_38 , F_33 ( V_31 ) -> V_34 ,
F_33 ( V_31 ) -> V_41 , V_19 -> V_45 ,
F_38 ( & V_19 -> V_35 ) ) ;
goto V_87;
}
F_72 ( & V_19 -> V_35 , V_31 ) ;
}
} else {
F_72 ( & V_19 -> V_35 , V_31 ) ;
}
F_46 ( V_19 ) ;
F_73 ( V_19 ) ;
return;
V_87:
F_39 ( & V_19 -> V_39 . V_54 ) ;
F_45 ( V_31 ) ;
if ( V_19 -> V_49 )
(* V_19 -> V_49 )( V_19 ) ;
F_73 ( V_19 ) ;
}
int F_74 ( struct V_14 * V_19 )
{
struct V_30 * V_31 = NULL ;
F_2 ( ! V_19 ) ;
F_2 ( V_19 -> V_101 != V_102 ) ;
while ( ( V_31 = F_75 ( & V_19 -> V_35 ) ) ) {
F_39 ( & V_19 -> V_39 . V_54 ) ;
F_45 ( V_31 ) ;
if ( V_19 -> V_49 )
(* V_19 -> V_49 )( V_19 ) ;
}
return 0 ;
}
static int F_76 ( struct V_4 * V_5 , struct V_30 * V_31 ,
int (* F_64)( struct V_30 * V_31 ) )
{
struct V_14 * V_19 = NULL ;
unsigned char * V_78 , * V_79 ;
T_2 V_80 ;
T_1 V_29 , V_15 ;
T_2 V_46 ;
int V_41 ;
if ( V_5 -> V_7 && F_49 ( V_5 -> V_7 , V_31 ) )
goto V_103;
F_71 ( V_31 , sizeof( struct V_56 ) ) ;
if ( ! F_70 ( V_31 , V_104 ) ) {
F_66 ( V_5 , V_85 ,
L_14 ,
V_5 -> V_38 , V_31 -> V_59 ) ;
goto error;
}
if ( V_5 -> V_105 & V_85 ) {
V_41 = F_77 ( 32u , V_31 -> V_59 ) ;
if ( ! F_70 ( V_31 , V_41 ) )
goto error;
F_78 ( L_15 , V_5 -> V_38 ) ;
F_79 ( L_16 , V_106 , V_31 -> V_107 , V_41 ) ;
}
V_79 = V_78 = V_31 -> V_107 ;
V_80 = F_51 ( * ( V_89 * ) V_78 ) ;
V_46 = V_80 & V_108 ;
if ( V_46 != V_5 -> V_46 ) {
F_66 ( V_5 , V_85 ,
L_17 ,
V_5 -> V_38 , V_46 , V_5 -> V_46 ) ;
goto error;
}
V_41 = V_31 -> V_59 ;
if ( V_80 & V_109 ) {
F_37 ( V_5 , V_85 ,
L_18 ,
V_5 -> V_38 , V_41 ) ;
goto error;
}
V_78 += 2 ;
if ( V_5 -> V_46 == V_47 ) {
if ( V_80 & V_110 )
V_78 += 2 ;
V_29 = F_51 ( * ( V_89 * ) V_78 ) ;
V_78 += 2 ;
V_15 = F_51 ( * ( V_89 * ) V_78 ) ;
V_78 += 2 ;
} else {
V_78 += 2 ;
V_29 = V_5 -> V_29 ;
V_15 = F_67 ( * ( V_93 * ) V_78 ) ;
V_78 += 4 ;
}
V_19 = F_23 ( V_5 -> V_1 , V_5 , V_15 ) ;
if ( ! V_19 || ! V_19 -> V_48 ) {
F_66 ( V_5 , V_85 ,
L_19 ,
V_5 -> V_38 , V_29 , V_15 ) ;
goto error;
}
F_63 ( V_19 , V_31 , V_78 , V_79 , V_80 , V_41 , F_64 ) ;
return 0 ;
V_103:
F_54 ( L_20 , V_5 -> V_38 ) ;
F_80 ( V_5 -> V_1 , V_111 , 0 ) ;
F_39 ( & V_5 -> V_39 . V_54 ) ;
F_45 ( V_31 ) ;
return 0 ;
error:
F_81 ( V_31 , sizeof( struct V_56 ) ) ;
return 1 ;
}
int F_82 ( struct V_7 * V_10 , struct V_30 * V_31 )
{
struct V_4 * V_5 ;
V_5 = F_13 ( V_10 ) ;
if ( V_5 == NULL )
goto V_112;
F_37 ( V_5 , V_85 , L_21 ,
V_5 -> V_38 , V_31 -> V_59 ) ;
if ( F_76 ( V_5 , V_31 , V_5 -> V_113 ) )
goto V_114;
F_15 ( V_10 ) ;
return 0 ;
V_114:
F_15 ( V_10 ) ;
V_112:
return 1 ;
}
static int F_83 ( struct V_14 * V_19 , void * V_115 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
V_89 * V_116 = V_115 ;
V_89 * V_79 = V_115 ;
T_2 V_117 = V_47 ;
T_1 V_29 = V_5 -> V_118 ;
T_1 V_15 = V_19 -> V_119 ;
if ( V_19 -> V_96 )
V_117 |= V_88 ;
* V_116 ++ = F_84 ( V_117 ) ;
* V_116 ++ = F_84 ( V_29 ) ;
* V_116 ++ = F_84 ( V_15 ) ;
if ( V_19 -> V_96 ) {
* V_116 ++ = F_84 ( V_19 -> V_34 ) ;
* V_116 ++ = 0 ;
V_19 -> V_34 ++ ;
V_19 -> V_34 &= 0xffff ;
F_37 ( V_19 , V_37 , L_22 ,
V_19 -> V_38 , V_19 -> V_34 ) ;
}
return V_116 - V_79 ;
}
static int F_85 ( struct V_14 * V_19 , void * V_115 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
char * V_116 = V_115 ;
char * V_79 = V_116 ;
if ( V_5 -> V_120 == V_121 ) {
T_2 V_117 = V_122 ;
* ( ( V_89 * ) V_116 ) = F_84 ( V_117 ) ;
V_116 += 2 ;
* ( ( V_89 * ) V_116 ) = 0 ;
V_116 += 2 ;
}
* ( ( V_93 * ) V_116 ) = F_86 ( V_19 -> V_119 ) ;
V_116 += 4 ;
if ( V_19 -> V_123 ) {
memcpy ( V_116 , & V_19 -> V_124 [ 0 ] , V_19 -> V_123 ) ;
V_116 += V_19 -> V_123 ;
}
if ( V_19 -> V_94 ) {
if ( V_19 -> V_90 == V_91 ) {
T_1 V_92 = 0 ;
if ( V_19 -> V_96 ) {
V_92 = 0x40000000 | V_19 -> V_34 ;
V_19 -> V_34 ++ ;
V_19 -> V_34 &= 0xffffff ;
F_37 ( V_19 , V_37 ,
L_22 ,
V_19 -> V_38 , V_19 -> V_34 ) ;
}
* ( ( V_93 * ) V_116 ) = F_86 ( V_92 ) ;
}
V_116 += V_19 -> V_94 ;
}
if ( V_19 -> V_81 )
V_116 += V_19 -> V_81 ;
return V_116 - V_79 ;
}
static int F_87 ( struct V_14 * V_19 , struct V_30 * V_31 ,
struct V_125 * V_126 , T_4 V_127 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
unsigned int V_59 = V_31 -> V_59 ;
int error ;
if ( V_19 -> V_96 )
F_37 ( V_19 , V_85 , L_23 ,
V_19 -> V_38 , V_127 , V_19 -> V_34 - 1 ) ;
else
F_37 ( V_19 , V_85 , L_24 ,
V_19 -> V_38 , V_127 ) ;
if ( V_19 -> V_105 & V_85 ) {
int V_128 = ( V_5 -> V_120 == V_121 ) ? sizeof( struct V_56 ) : 0 ;
unsigned char * V_129 = V_31 -> V_107 + V_128 ;
F_78 ( L_25 , V_19 -> V_38 ) ;
F_79 ( L_16 , V_106 ,
V_129 , F_88 ( T_4 , 32 , V_59 - V_128 ) ) ;
}
V_31 -> V_130 = 1 ;
#if F_53 ( V_62 )
if ( V_31 -> V_10 -> V_63 == V_64 )
error = F_89 ( V_31 , NULL ) ;
else
#endif
error = F_90 ( V_31 , V_126 ) ;
if ( error >= 0 ) {
F_39 ( & V_5 -> V_39 . V_131 ) ;
F_44 ( V_59 , & V_5 -> V_39 . V_132 ) ;
F_39 ( & V_19 -> V_39 . V_131 ) ;
F_44 ( V_59 , & V_19 -> V_39 . V_132 ) ;
} else {
F_39 ( & V_5 -> V_39 . V_133 ) ;
F_39 ( & V_19 -> V_39 . V_133 ) ;
}
return 0 ;
}
static void F_91 ( struct V_30 * V_31 )
{
F_15 ( V_31 -> V_10 ) ;
}
static inline void F_92 ( struct V_30 * V_31 , struct V_7 * V_10 )
{
F_11 ( V_10 ) ;
V_31 -> V_10 = V_10 ;
V_31 -> V_134 = F_91 ;
}
static void F_93 ( struct V_7 * V_10 , struct V_30 * V_31 ,
int V_135 )
{
struct V_136 * V_137 = F_94 ( V_10 ) ;
struct V_56 * V_57 = F_50 ( V_31 ) ;
if ( ! F_95 ( V_31 ) || ! F_95 ( V_31 ) -> V_138 ||
! ( F_95 ( V_31 ) -> V_138 -> V_139 & V_140 ) ) {
T_3 V_72 = F_96 ( V_31 , 0 , V_135 , 0 ) ;
V_31 -> V_67 = V_73 ;
V_57 -> V_65 = F_55 ( & V_137 -> V_69 , & V_137 -> V_70 , V_135 ,
V_71 , V_72 ) ;
if ( V_57 -> V_65 == 0 )
V_57 -> V_65 = V_141 ;
} else {
V_31 -> V_67 = V_142 ;
V_31 -> V_143 = F_97 ( V_31 ) - V_31 -> V_144 ;
V_31 -> V_145 = F_98 ( struct V_56 , V_65 ) ;
V_57 -> V_65 = ~ F_55 ( & V_137 -> V_69 , & V_137 -> V_70 ,
V_135 , V_71 , 0 ) ;
}
}
int F_99 ( struct V_14 * V_19 , struct V_30 * V_31 , int V_146 )
{
int V_127 = V_31 -> V_59 ;
struct V_4 * V_5 = V_19 -> V_5 ;
struct V_7 * V_10 = V_5 -> V_7 ;
struct V_125 * V_126 ;
struct V_56 * V_57 ;
struct V_74 * V_75 ;
T_3 V_72 ;
int V_147 ;
int V_128 = ( V_5 -> V_120 == V_121 ) ? sizeof( struct V_56 ) : 0 ;
int V_135 ;
int V_148 = V_149 ;
V_147 = V_150 + sizeof( struct V_151 ) +
V_128 + V_146 ;
if ( F_100 ( V_31 , V_147 ) ) {
F_45 ( V_31 ) ;
return V_152 ;
}
F_43 ( V_31 ) ;
V_19 -> V_153 ( V_19 , F_81 ( V_31 , V_146 ) ) ;
memset ( & ( F_101 ( V_31 ) -> V_154 ) , 0 , sizeof( F_101 ( V_31 ) -> V_154 ) ) ;
F_101 ( V_31 ) -> V_117 &= ~ ( V_155 | V_156 |
V_157 ) ;
F_102 ( V_31 ) ;
F_103 ( V_10 ) ;
if ( F_104 ( V_10 ) ) {
F_45 ( V_31 ) ;
V_148 = V_152 ;
goto V_158;
}
F_105 ( V_31 ) ;
F_106 ( V_31 , F_107 ( F_108 ( V_10 , 0 ) ) ) ;
V_75 = F_58 ( V_10 ) ;
V_126 = & V_75 -> V_159 . V_126 ;
switch ( V_5 -> V_120 ) {
case V_121 :
F_81 ( V_31 , sizeof( * V_57 ) ) ;
F_109 ( V_31 ) ;
V_57 = F_50 ( V_31 ) ;
V_57 -> V_160 = V_75 -> V_161 ;
V_57 -> V_162 = V_75 -> V_163 ;
V_135 = V_128 + V_146 + V_127 ;
V_57 -> V_59 = F_84 ( V_135 ) ;
V_57 -> V_65 = 0 ;
#if F_53 ( V_62 )
if ( V_10 -> V_63 == V_64 )
F_93 ( V_10 , V_31 , V_135 ) ;
else
#endif
if ( V_10 -> V_61 == V_164 )
V_31 -> V_67 = V_165 ;
else if ( ( F_95 ( V_31 ) && F_95 ( V_31 ) -> V_138 ) &&
( ! ( F_95 ( V_31 ) -> V_138 -> V_139 & V_166 ) ) ) {
V_31 -> V_67 = V_68 ;
V_72 = F_96 ( V_31 , 0 , V_135 , 0 ) ;
V_57 -> V_65 = F_110 ( V_75 -> V_76 ,
V_75 -> V_77 ,
V_135 , V_71 , V_72 ) ;
if ( V_57 -> V_65 == 0 )
V_57 -> V_65 = V_141 ;
} else {
V_31 -> V_67 = V_142 ;
V_31 -> V_143 = F_97 ( V_31 ) - V_31 -> V_144 ;
V_31 -> V_145 = F_98 ( struct V_56 , V_65 ) ;
V_57 -> V_65 = ~ F_110 ( V_75 -> V_76 ,
V_75 -> V_77 ,
V_135 , V_71 , 0 ) ;
}
break;
case V_167 :
break;
}
F_92 ( V_31 , V_10 ) ;
F_87 ( V_19 , V_31 , V_126 , V_127 ) ;
V_158:
F_111 ( V_10 ) ;
return V_148 ;
}
static void F_112 ( struct V_7 * V_10 )
{
struct V_4 * V_5 ;
struct V_1 * V_16 ;
V_5 = V_10 -> V_168 ;
if ( V_5 == NULL )
goto V_169;
F_66 ( V_5 , V_170 , L_26 , V_5 -> V_38 ) ;
switch ( V_5 -> V_120 ) {
case V_121 :
( F_113 ( V_10 ) ) -> V_171 = 0 ;
( F_113 ( V_10 ) ) -> V_172 = NULL ;
( F_113 ( V_10 ) ) -> V_173 = NULL ;
break;
case V_167 :
break;
}
V_10 -> V_174 = V_5 -> V_175 ;
V_10 -> V_168 = NULL ;
V_5 -> V_7 = NULL ;
V_16 = F_1 ( V_5 -> V_1 ) ;
F_34 ( & V_16 -> V_176 ) ;
F_114 ( & V_5 -> V_177 ) ;
F_41 ( & V_16 -> V_176 ) ;
F_115 ( & V_178 ) ;
F_116 ( V_5 ) ;
F_117 ( V_5 ) ;
if ( V_10 -> V_174 )
(* V_10 -> V_174 )( V_10 ) ;
V_169:
return;
}
void F_116 ( struct V_4 * V_5 )
{
int V_24 ;
struct V_179 * V_180 ;
struct V_179 * V_33 ;
struct V_14 * V_19 ;
F_2 ( V_5 == NULL ) ;
F_66 ( V_5 , V_170 , L_27 ,
V_5 -> V_38 ) ;
F_118 ( & V_5 -> V_22 ) ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
V_181:
F_119 (walk, tmp, &tunnel->session_hlist[hash]) {
V_19 = F_120 ( V_180 , struct V_14 , V_182 ) ;
F_66 ( V_19 , V_170 ,
L_28 , V_19 -> V_38 ) ;
F_121 ( & V_19 -> V_182 ) ;
if ( V_19 -> V_82 != NULL )
(* V_19 -> V_82 )( V_19 ) ;
F_122 ( & V_5 -> V_22 ) ;
F_123 ( V_19 ) ;
F_74 ( V_19 ) ;
if ( V_19 -> V_183 != NULL )
(* V_19 -> V_183 )( V_19 ) ;
if ( V_19 -> V_49 != NULL )
(* V_19 -> V_49 )( V_19 ) ;
F_73 ( V_19 ) ;
F_118 ( & V_5 -> V_22 ) ;
goto V_181;
}
}
F_122 ( & V_5 -> V_22 ) ;
}
static void F_124 ( struct V_7 * V_10 )
{
struct V_4 * V_5 = F_13 ( V_10 ) ;
if ( V_5 ) {
F_116 ( V_5 ) ;
F_15 ( V_10 ) ;
}
}
static void F_8 ( struct V_4 * V_5 )
{
F_2 ( F_125 ( & V_5 -> V_6 ) != 0 ) ;
F_2 ( V_5 -> V_7 != NULL ) ;
F_66 ( V_5 , V_170 , L_29 , V_5 -> V_38 ) ;
F_126 ( V_5 , V_184 ) ;
}
static void F_127 ( struct V_185 * V_186 )
{
struct V_4 * V_5 = NULL ;
struct V_9 * V_7 = NULL ;
struct V_7 * V_10 = NULL ;
V_5 = F_128 ( V_186 , struct V_4 , V_187 ) ;
V_10 = F_9 ( V_5 ) ;
if ( ! V_10 )
return;
V_7 = V_10 -> V_13 ;
if ( V_5 -> V_12 >= 0 ) {
if ( V_7 )
F_129 ( V_7 , 2 ) ;
} else {
if ( V_7 )
F_130 ( V_7 , V_188 ) ;
F_131 ( V_10 ) ;
}
F_12 ( V_10 ) ;
}
static int F_132 ( struct V_2 * V_2 ,
T_1 V_29 ,
T_1 V_118 ,
struct V_189 * V_190 ,
struct V_9 * * V_191 )
{
int V_8 = - V_192 ;
struct V_9 * V_7 = NULL ;
struct V_193 V_194 = { 0 } ;
struct V_195 V_196 = { 0 } ;
#if F_53 ( V_62 )
struct V_197 V_198 = { 0 } ;
struct V_199 V_200 = { 0 } ;
#endif
switch ( V_190 -> V_120 ) {
case V_121 :
#if F_53 ( V_62 )
if ( V_190 -> V_201 && V_190 -> V_202 ) {
V_8 = F_133 ( V_203 , V_204 , 0 , & V_7 ) ;
if ( V_8 < 0 )
goto V_11;
F_134 ( V_7 -> V_10 , V_2 ) ;
V_198 . V_205 = V_203 ;
memcpy ( & V_198 . V_206 , V_190 -> V_201 ,
sizeof( V_198 . V_206 ) ) ;
V_198 . V_207 = F_84 ( V_190 -> V_208 ) ;
V_8 = F_135 ( V_7 , (struct V_209 * ) & V_198 ,
sizeof( V_198 ) ) ;
if ( V_8 < 0 )
goto V_11;
V_198 . V_205 = V_203 ;
memcpy ( & V_198 . V_206 , V_190 -> V_202 ,
sizeof( V_198 . V_206 ) ) ;
V_198 . V_207 = F_84 ( V_190 -> V_210 ) ;
V_8 = F_136 ( V_7 ,
(struct V_209 * ) & V_198 ,
sizeof( V_198 ) , 0 ) ;
if ( V_8 < 0 )
goto V_11;
} else
#endif
{
V_8 = F_133 ( V_211 , V_204 , 0 , & V_7 ) ;
if ( V_8 < 0 )
goto V_11;
F_134 ( V_7 -> V_10 , V_2 ) ;
V_194 . V_212 = V_211 ;
V_194 . V_213 = V_190 -> V_214 ;
V_194 . V_215 = F_84 ( V_190 -> V_208 ) ;
V_8 = F_135 ( V_7 , (struct V_209 * ) & V_194 ,
sizeof( V_194 ) ) ;
if ( V_8 < 0 )
goto V_11;
V_194 . V_212 = V_211 ;
V_194 . V_213 = V_190 -> V_216 ;
V_194 . V_215 = F_84 ( V_190 -> V_210 ) ;
V_8 = F_136 ( V_7 ,
(struct V_209 * ) & V_194 ,
sizeof( V_194 ) , 0 ) ;
if ( V_8 < 0 )
goto V_11;
}
if ( ! V_190 -> V_217 )
V_7 -> V_10 -> V_61 = V_164 ;
break;
case V_167 :
#if F_53 ( V_62 )
if ( V_190 -> V_201 && V_190 -> V_202 ) {
V_8 = F_133 ( V_203 , V_204 ,
V_218 , & V_7 ) ;
if ( V_8 < 0 )
goto V_11;
F_134 ( V_7 -> V_10 , V_2 ) ;
V_200 . V_219 = V_203 ;
memcpy ( & V_200 . V_220 , V_190 -> V_201 ,
sizeof( V_200 . V_220 ) ) ;
V_200 . V_221 = V_29 ;
V_8 = F_135 ( V_7 , (struct V_209 * ) & V_200 ,
sizeof( V_200 ) ) ;
if ( V_8 < 0 )
goto V_11;
V_200 . V_219 = V_203 ;
memcpy ( & V_200 . V_220 , V_190 -> V_202 ,
sizeof( V_200 . V_220 ) ) ;
V_200 . V_221 = V_118 ;
V_8 = F_136 ( V_7 ,
(struct V_209 * ) & V_200 ,
sizeof( V_200 ) , 0 ) ;
if ( V_8 < 0 )
goto V_11;
} else
#endif
{
V_8 = F_133 ( V_211 , V_204 ,
V_218 , & V_7 ) ;
if ( V_8 < 0 )
goto V_11;
F_134 ( V_7 -> V_10 , V_2 ) ;
V_196 . V_219 = V_211 ;
V_196 . V_220 = V_190 -> V_214 ;
V_196 . V_221 = V_29 ;
V_8 = F_135 ( V_7 , (struct V_209 * ) & V_196 ,
sizeof( V_196 ) ) ;
if ( V_8 < 0 )
goto V_11;
V_196 . V_219 = V_211 ;
V_196 . V_220 = V_190 -> V_216 ;
V_196 . V_221 = V_118 ;
V_8 = F_136 ( V_7 , (struct V_209 * ) & V_196 ,
sizeof( V_196 ) , 0 ) ;
if ( V_8 < 0 )
goto V_11;
}
break;
default:
goto V_11;
}
V_11:
* V_191 = V_7 ;
if ( ( V_8 < 0 ) && V_7 ) {
F_130 ( V_7 , V_188 ) ;
F_131 ( V_7 -> V_10 ) ;
* V_191 = NULL ;
}
return V_8 ;
}
int F_137 ( struct V_2 * V_2 , int V_12 , int V_46 , T_1 V_29 , T_1 V_118 , struct V_189 * V_190 , struct V_4 * * V_222 )
{
struct V_4 * V_5 = NULL ;
int V_8 ;
struct V_9 * V_7 = NULL ;
struct V_7 * V_10 = NULL ;
struct V_1 * V_16 ;
enum V_223 V_120 = V_121 ;
if ( V_12 < 0 ) {
V_8 = F_132 ( V_2 , V_29 , V_118 ,
V_190 , & V_7 ) ;
if ( V_8 < 0 )
goto V_8;
} else {
V_7 = F_10 ( V_12 , & V_8 ) ;
if ( ! V_7 ) {
F_138 ( L_30 ,
V_29 , V_12 , V_8 ) ;
V_8 = - V_224 ;
goto V_8;
}
if ( ! F_139 ( F_140 ( V_7 -> V_10 ) , V_2 ) ) {
F_138 ( L_31 , V_29 ) ;
V_8 = - V_192 ;
goto V_8;
}
}
V_10 = V_7 -> V_10 ;
if ( V_190 != NULL )
V_120 = V_190 -> V_120 ;
switch ( V_120 ) {
case V_121 :
V_8 = - V_225 ;
if ( V_10 -> V_226 != V_71 ) {
F_138 ( L_32 ,
V_29 , V_12 , V_10 -> V_226 , V_71 ) ;
goto V_8;
}
break;
case V_167 :
V_8 = - V_225 ;
if ( V_10 -> V_226 != V_218 ) {
F_138 ( L_32 ,
V_29 , V_12 , V_10 -> V_226 , V_218 ) ;
goto V_8;
}
break;
}
V_5 = (struct V_4 * ) V_10 -> V_168 ;
if ( V_5 != NULL ) {
V_8 = - V_227 ;
goto V_8;
}
V_5 = F_141 ( sizeof( struct V_4 ) , V_228 ) ;
if ( V_5 == NULL ) {
V_8 = - V_229 ;
goto V_8;
}
V_5 -> V_46 = V_46 ;
V_5 -> V_29 = V_29 ;
V_5 -> V_118 = V_118 ;
V_5 -> V_105 = V_230 ;
V_5 -> V_101 = V_231 ;
sprintf ( & V_5 -> V_38 [ 0 ] , L_33 , V_29 ) ;
F_142 ( & V_5 -> V_22 ) ;
V_5 -> V_1 = V_2 ;
V_16 = F_1 ( V_2 ) ;
if ( V_190 != NULL )
V_5 -> V_105 = V_190 -> V_105 ;
V_5 -> V_120 = V_120 ;
if ( V_120 == V_121 ) {
F_113 ( V_10 ) -> V_171 = V_232 ;
F_113 ( V_10 ) -> V_172 = F_82 ;
F_113 ( V_10 ) -> V_173 = F_124 ;
#if F_53 ( V_62 )
if ( V_10 -> V_63 == V_64 )
F_143 () ;
else
#endif
F_144 () ;
}
V_10 -> V_168 = V_5 ;
V_5 -> V_175 = V_10 -> V_174 ;
V_10 -> V_174 = & F_112 ;
V_5 -> V_7 = V_10 ;
V_5 -> V_12 = V_12 ;
F_145 ( & V_10 -> V_233 . V_234 , & V_235 , L_34 ) ;
V_10 -> V_236 = V_237 ;
F_146 ( & V_5 -> V_187 , F_127 ) ;
F_147 ( & V_5 -> V_177 ) ;
F_5 ( & V_178 ) ;
F_148 ( V_5 ) ;
F_34 ( & V_16 -> V_176 ) ;
F_149 ( & V_5 -> V_177 , & V_16 -> V_238 ) ;
F_41 ( & V_16 -> V_176 ) ;
V_8 = 0 ;
V_8:
if ( V_222 )
* V_222 = V_5 ;
if ( V_7 && V_7 -> V_239 )
F_14 ( V_7 ) ;
return V_8 ;
}
int F_150 ( struct V_4 * V_5 )
{
F_116 ( V_5 ) ;
return ( false == F_151 ( V_240 , & V_5 -> V_187 ) ) ;
}
void F_152 ( struct V_14 * V_19 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
F_2 ( F_125 ( & V_19 -> V_6 ) != 0 ) ;
if ( V_5 ) {
F_2 ( V_5 -> V_101 != V_231 ) ;
if ( V_19 -> V_15 != 0 )
F_115 ( & V_241 ) ;
F_15 ( V_5 -> V_7 ) ;
V_19 -> V_5 = NULL ;
F_117 ( V_5 ) ;
}
F_153 ( V_19 ) ;
return;
}
void F_123 ( struct V_14 * V_19 )
{
struct V_4 * V_5 = V_19 -> V_5 ;
if ( V_5 ) {
F_118 ( & V_5 -> V_22 ) ;
F_121 ( & V_19 -> V_182 ) ;
F_122 ( & V_5 -> V_22 ) ;
if ( V_5 -> V_46 != V_47 ) {
struct V_1 * V_16 = F_1 ( V_5 -> V_1 ) ;
F_34 ( & V_16 -> V_242 ) ;
F_154 ( & V_19 -> V_243 ) ;
F_41 ( & V_16 -> V_242 ) ;
F_155 () ;
}
}
}
int F_156 ( struct V_14 * V_19 )
{
if ( V_19 -> V_82 )
(* V_19 -> V_82 )( V_19 ) ;
F_123 ( V_19 ) ;
F_74 ( V_19 ) ;
if ( V_19 -> V_183 != NULL )
(* V_19 -> V_183 )( V_19 ) ;
if ( V_19 -> V_49 )
(* V_19 -> V_82 )( V_19 ) ;
F_73 ( V_19 ) ;
return 0 ;
}
static void F_68 ( struct V_14 * V_19 , int V_46 )
{
if ( V_46 == V_47 ) {
V_19 -> V_146 = 6 ;
if ( V_19 -> V_96 )
V_19 -> V_146 += 4 ;
} else {
V_19 -> V_146 = 4 + V_19 -> V_123 + V_19 -> V_94 + V_19 -> V_81 ;
if ( V_19 -> V_5 -> V_120 == V_121 )
V_19 -> V_146 += 4 ;
}
}
struct V_14 * F_157 ( int V_244 , struct V_4 * V_5 , T_1 V_15 , T_1 V_119 , struct V_245 * V_190 )
{
struct V_14 * V_19 ;
V_19 = F_141 ( sizeof( struct V_14 ) + V_244 , V_228 ) ;
if ( V_19 != NULL ) {
V_19 -> V_101 = V_102 ;
V_19 -> V_5 = V_5 ;
V_19 -> V_15 = V_15 ;
V_19 -> V_119 = V_119 ;
V_19 -> V_45 = 0 ;
sprintf ( & V_19 -> V_38 [ 0 ] , L_35 ,
V_5 -> V_29 , V_19 -> V_15 ) ;
F_158 ( & V_19 -> V_35 ) ;
F_159 ( & V_19 -> V_182 ) ;
F_159 ( & V_19 -> V_243 ) ;
V_19 -> V_105 = V_5 -> V_105 ;
if ( V_190 ) {
V_19 -> V_246 = V_190 -> V_247 ;
V_19 -> V_105 = V_190 -> V_105 ;
V_19 -> V_248 = V_190 -> V_248 ;
V_19 -> V_249 = V_190 -> V_249 ;
V_19 -> V_96 = V_190 -> V_96 ;
V_19 -> V_97 = V_190 -> V_97 ;
V_19 -> V_95 = V_190 -> V_95 ;
V_19 -> V_99 = V_190 -> V_99 ;
V_19 -> V_81 = V_190 -> V_81 ;
V_19 -> V_90 = V_190 -> V_90 ;
V_19 -> V_94 = V_190 -> V_94 ;
V_19 -> V_123 = V_190 -> V_123 ;
memcpy ( & V_19 -> V_124 [ 0 ] , & V_190 -> V_124 [ 0 ] , V_190 -> V_123 ) ;
V_19 -> V_83 = V_190 -> V_83 ;
memcpy ( & V_19 -> V_84 [ 0 ] , & V_190 -> V_84 [ 0 ] , V_190 -> V_83 ) ;
}
if ( V_5 -> V_46 == V_47 )
V_19 -> V_153 = F_83 ;
else
V_19 -> V_153 = F_85 ;
F_68 ( V_19 , V_5 -> V_46 ) ;
F_65 ( V_19 ) ;
F_148 ( V_5 ) ;
F_11 ( V_5 -> V_7 ) ;
F_118 ( & V_5 -> V_22 ) ;
F_160 ( & V_19 -> V_182 ,
F_21 ( V_5 , V_15 ) ) ;
F_122 ( & V_5 -> V_22 ) ;
if ( V_5 -> V_46 != V_47 ) {
struct V_1 * V_16 = F_1 ( V_5 -> V_1 ) ;
F_34 ( & V_16 -> V_242 ) ;
F_161 ( & V_19 -> V_243 ,
F_17 ( V_16 , V_15 ) ) ;
F_41 ( & V_16 -> V_242 ) ;
}
if ( V_19 -> V_15 != 0 )
F_5 ( & V_241 ) ;
}
return V_19 ;
}
static T_5 int F_162 ( struct V_2 * V_2 )
{
struct V_1 * V_16 = F_3 ( V_2 , V_3 ) ;
int V_24 ;
F_147 ( & V_16 -> V_238 ) ;
F_163 ( & V_16 -> V_176 ) ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ )
F_164 ( & V_16 -> V_250 [ V_24 ] ) ;
F_163 ( & V_16 -> V_242 ) ;
return 0 ;
}
static T_6 void F_165 ( struct V_2 * V_2 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
struct V_4 * V_5 = NULL ;
F_18 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
( void ) F_150 ( V_5 ) ;
}
F_20 () ;
}
static int T_7 F_166 ( void )
{
int V_251 = 0 ;
V_251 = F_167 ( & V_252 ) ;
if ( V_251 )
goto V_11;
V_240 = F_168 ( L_36 , V_253 | V_254 , 0 ) ;
if ( ! V_240 ) {
F_138 ( L_37 ) ;
V_251 = - V_229 ;
goto V_11;
}
F_169 ( L_38 , V_255 ) ;
V_11:
return V_251 ;
}
static void T_8 F_170 ( void )
{
F_171 ( & V_252 ) ;
if ( V_240 ) {
F_172 ( V_240 ) ;
V_240 = NULL ;
}
}
