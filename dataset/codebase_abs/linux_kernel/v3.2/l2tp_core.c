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
static inline struct V_7 *
F_9 ( struct V_1 * V_8 , T_1 V_9 )
{
return & V_8 -> V_10 [ F_10 ( V_9 , V_11 ) ] ;
}
static struct V_12 * F_11 ( struct V_2 * V_2 , T_1 V_9 )
{
struct V_1 * V_8 = F_1 ( V_2 ) ;
struct V_7 * V_13 =
F_9 ( V_8 , V_9 ) ;
struct V_12 * V_14 ;
struct V_15 * V_16 ;
F_12 () ;
F_13 (session, walk, session_list, global_hlist) {
if ( V_14 -> V_9 == V_9 ) {
F_14 () ;
return V_14 ;
}
}
F_14 () ;
return NULL ;
}
static inline struct V_7 *
F_15 ( struct V_4 * V_5 , T_1 V_9 )
{
return & V_5 -> V_17 [ F_10 ( V_9 , V_18 ) ] ;
}
struct V_12 * F_16 ( struct V_2 * V_2 , struct V_4 * V_5 , T_1 V_9 )
{
struct V_7 * V_13 ;
struct V_12 * V_14 ;
struct V_15 * V_16 ;
if ( V_5 == NULL )
return F_11 ( V_2 , V_9 ) ;
V_13 = F_15 ( V_5 , V_9 ) ;
F_17 ( & V_5 -> V_19 ) ;
F_18 (session, walk, session_list, hlist) {
if ( V_14 -> V_9 == V_9 ) {
F_19 ( & V_5 -> V_19 ) ;
return V_14 ;
}
}
F_19 ( & V_5 -> V_19 ) ;
return NULL ;
}
struct V_12 * F_20 ( struct V_4 * V_5 , int V_20 )
{
int V_21 ;
struct V_15 * V_16 ;
struct V_12 * V_14 ;
int V_22 = 0 ;
F_17 ( & V_5 -> V_19 ) ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
F_18 (session, walk, &tunnel->session_hlist[hash], hlist) {
if ( ++ V_22 > V_20 ) {
F_19 ( & V_5 -> V_19 ) ;
return V_14 ;
}
}
}
F_19 ( & V_5 -> V_19 ) ;
return NULL ;
}
struct V_12 * F_21 ( struct V_2 * V_2 , char * V_24 )
{
struct V_1 * V_8 = F_1 ( V_2 ) ;
int V_21 ;
struct V_15 * V_16 ;
struct V_12 * V_14 ;
F_12 () ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
F_13 (session, walk, &pn->l2tp_session_hlist[hash], global_hlist) {
if ( ! strcmp ( V_14 -> V_24 , V_24 ) ) {
F_14 () ;
return V_14 ;
}
}
}
F_14 () ;
return NULL ;
}
struct V_4 * F_22 ( struct V_2 * V_2 , T_1 V_26 )
{
struct V_4 * V_5 ;
struct V_1 * V_8 = F_1 ( V_2 ) ;
F_12 () ;
F_23 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( V_5 -> V_26 == V_26 ) {
F_14 () ;
return V_5 ;
}
}
F_14 () ;
return NULL ;
}
struct V_4 * F_24 ( struct V_2 * V_2 , int V_20 )
{
struct V_1 * V_8 = F_1 ( V_2 ) ;
struct V_4 * V_5 ;
int V_22 = 0 ;
F_12 () ;
F_23 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( ++ V_22 > V_20 ) {
F_14 () ;
return V_5 ;
}
}
F_14 () ;
return NULL ;
}
static void F_25 ( struct V_12 * V_14 , struct V_27 * V_28 )
{
struct V_27 * V_29 ;
struct V_27 * V_30 ;
T_1 V_31 = F_26 ( V_28 ) -> V_31 ;
F_27 ( & V_14 -> V_32 . V_33 ) ;
F_28 (&session->reorder_q, skbp, tmp) {
if ( F_26 ( V_29 ) -> V_31 > V_31 ) {
F_29 ( & V_14 -> V_32 , V_29 , V_28 ) ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_1 ,
V_14 -> V_37 , V_31 , F_26 ( V_29 ) -> V_31 ,
F_31 ( & V_14 -> V_32 ) ) ;
V_14 -> V_38 . V_39 ++ ;
goto V_40;
}
}
F_32 ( & V_14 -> V_32 , V_28 ) ;
V_40:
F_33 ( & V_14 -> V_32 . V_33 ) ;
}
static void F_34 ( struct V_12 * V_14 , struct V_27 * V_28 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
int V_41 = F_26 ( V_28 ) -> V_41 ;
F_35 ( V_28 ) ;
V_5 -> V_38 . V_42 ++ ;
V_5 -> V_38 . V_43 += V_41 ;
V_14 -> V_38 . V_42 ++ ;
V_14 -> V_38 . V_43 += V_41 ;
if ( F_26 ( V_28 ) -> V_44 ) {
V_14 -> V_45 ++ ;
if ( V_5 -> V_46 == V_47 )
V_14 -> V_45 &= 0xffff ;
else
V_14 -> V_45 &= 0xffffff ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_2 , V_14 -> V_37 , V_14 -> V_45 ) ;
}
if ( V_14 -> V_48 != NULL )
(* V_14 -> V_48 )( V_14 , V_28 , F_26 ( V_28 ) -> V_41 ) ;
else
F_36 ( V_28 ) ;
if ( V_14 -> V_49 )
(* V_14 -> V_49 )( V_14 ) ;
}
static void F_37 ( struct V_12 * V_14 )
{
struct V_27 * V_28 ;
struct V_27 * V_30 ;
V_50:
F_27 ( & V_14 -> V_32 . V_33 ) ;
F_28 (&session->reorder_q, skb, tmp) {
if ( F_38 ( V_51 , F_26 ( V_28 ) -> V_52 ) ) {
V_14 -> V_38 . V_53 ++ ;
V_14 -> V_38 . V_54 ++ ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_3
L_4 ,
V_14 -> V_37 , F_26 ( V_28 ) -> V_31 ,
F_26 ( V_28 ) -> V_41 , V_14 -> V_45 ,
F_31 ( & V_14 -> V_32 ) ) ;
F_39 ( V_28 , & V_14 -> V_32 ) ;
F_36 ( V_28 ) ;
if ( V_14 -> V_49 )
(* V_14 -> V_49 )( V_14 ) ;
continue;
}
if ( F_26 ( V_28 ) -> V_44 ) {
if ( F_26 ( V_28 ) -> V_31 != V_14 -> V_45 ) {
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_5
L_4 ,
V_14 -> V_37 , F_26 ( V_28 ) -> V_31 ,
F_26 ( V_28 ) -> V_41 , V_14 -> V_45 ,
F_31 ( & V_14 -> V_32 ) ) ;
goto V_40;
}
}
F_39 ( V_28 , & V_14 -> V_32 ) ;
F_33 ( & V_14 -> V_32 . V_33 ) ;
F_34 ( V_14 , V_28 ) ;
goto V_50;
}
V_40:
F_33 ( & V_14 -> V_32 . V_33 ) ;
}
static inline int F_40 ( struct V_55 * V_56 ,
struct V_27 * V_28 )
{
struct V_57 * V_58 = F_41 ( V_28 ) ;
T_2 V_59 = F_42 ( V_58 -> V_60 ) ;
struct V_61 * V_62 ;
T_3 V_63 ;
if ( V_56 -> V_64 || F_43 ( V_28 ) || ! V_58 -> V_65 )
return 0 ;
V_62 = F_44 ( V_56 ) ;
V_63 = F_45 ( V_62 -> V_66 , V_62 -> V_67 , V_59 ,
V_68 , 0 ) ;
if ( ( V_28 -> V_69 == V_70 ) &&
! F_46 ( F_47 ( V_63 , V_28 -> V_71 ) ) )
return 0 ;
V_28 -> V_71 = V_63 ;
return F_48 ( V_28 ) ;
}
void F_49 ( struct V_12 * V_14 , struct V_27 * V_28 ,
unsigned char * V_72 , unsigned char * V_73 , T_2 V_74 ,
int V_41 , int (* F_50)( struct V_27 * V_28 ) )
{
struct V_4 * V_5 = V_14 -> V_5 ;
int V_75 ;
T_1 V_31 , V_45 ;
F_51 ( V_14 ) ;
if ( V_14 -> V_76 )
(* V_14 -> V_76 )( V_14 ) ;
if ( V_14 -> V_77 > 0 ) {
if ( memcmp ( V_72 , & V_14 -> V_78 [ 0 ] , V_14 -> V_77 ) ) {
F_30 ( V_5 -> V_34 , V_79 , V_80 ,
L_6 ,
V_5 -> V_37 , V_5 -> V_26 , V_14 -> V_9 ) ;
V_14 -> V_38 . V_81 ++ ;
goto V_82;
}
V_72 += V_14 -> V_77 ;
}
V_31 = V_45 = 0 ;
F_26 ( V_28 ) -> V_44 = 0 ;
if ( V_5 -> V_46 == V_47 ) {
if ( V_74 & V_83 ) {
V_31 = F_42 ( * ( V_84 * ) V_72 ) ;
V_72 += 2 ;
V_45 = F_42 ( * ( V_84 * ) V_72 ) ;
V_72 += 2 ;
F_26 ( V_28 ) -> V_31 = V_31 ;
F_26 ( V_28 ) -> V_44 = 1 ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_7 ,
V_14 -> V_37 , V_31 , V_45 , V_14 -> V_45 ) ;
}
} else if ( V_14 -> V_85 == V_86 ) {
T_1 V_87 = F_52 ( * ( V_88 * ) V_72 ) ;
if ( V_87 & 0x40000000 ) {
V_31 = V_87 & 0x00ffffff ;
F_26 ( V_28 ) -> V_31 = V_31 ;
F_26 ( V_28 ) -> V_44 = 1 ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_8 ,
V_14 -> V_37 , V_31 , V_14 -> V_45 ) ;
}
}
V_72 += V_14 -> V_89 ;
if ( F_26 ( V_28 ) -> V_44 ) {
if ( ( ! V_14 -> V_90 ) && ( ! V_14 -> V_91 ) ) {
F_30 ( V_14 -> V_34 , V_35 , V_80 ,
L_9 ,
V_14 -> V_37 ) ;
V_14 -> V_91 = - 1 ;
F_53 ( V_14 , V_5 -> V_46 ) ;
}
} else {
if ( V_14 -> V_92 ) {
F_30 ( V_14 -> V_34 , V_35 , V_93 ,
L_10
L_11 , V_14 -> V_37 ) ;
V_14 -> V_38 . V_53 ++ ;
goto V_82;
}
if ( ( ! V_14 -> V_90 ) && ( V_14 -> V_91 ) ) {
F_30 ( V_14 -> V_34 , V_35 , V_80 ,
L_12 ,
V_14 -> V_37 ) ;
V_14 -> V_91 = 0 ;
F_53 ( V_14 , V_5 -> V_46 ) ;
} else if ( V_14 -> V_91 ) {
F_30 ( V_14 -> V_34 , V_35 , V_93 ,
L_10
L_11 , V_14 -> V_37 ) ;
V_14 -> V_38 . V_53 ++ ;
goto V_82;
}
}
if ( V_5 -> V_46 == V_47 ) {
if ( V_74 & V_94 ) {
V_75 = F_42 ( * ( V_84 * ) V_72 ) ;
V_72 += 2 + V_75 ;
}
} else
V_72 += V_14 -> V_75 ;
V_75 = V_72 - V_73 ;
if ( ! F_54 ( V_28 , V_75 ) )
goto V_82;
F_55 ( V_28 , V_75 ) ;
if ( F_50 )
if ( (* F_50)( V_28 ) )
goto V_82;
F_26 ( V_28 ) -> V_41 = V_41 ;
F_26 ( V_28 ) -> V_52 = V_51 +
( V_14 -> V_95 ? V_14 -> V_95 : V_96 ) ;
if ( F_26 ( V_28 ) -> V_44 ) {
if ( V_14 -> V_95 != 0 ) {
F_25 ( V_14 , V_28 ) ;
} else {
if ( F_26 ( V_28 ) -> V_31 != V_14 -> V_45 ) {
V_14 -> V_38 . V_53 ++ ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_13
L_4 ,
V_14 -> V_37 , F_26 ( V_28 ) -> V_31 ,
F_26 ( V_28 ) -> V_41 , V_14 -> V_45 ,
F_31 ( & V_14 -> V_32 ) ) ;
goto V_82;
}
F_56 ( & V_14 -> V_32 , V_28 ) ;
}
} else {
F_56 ( & V_14 -> V_32 , V_28 ) ;
}
F_37 ( V_14 ) ;
F_57 ( V_14 ) ;
return;
V_82:
V_14 -> V_38 . V_54 ++ ;
F_36 ( V_28 ) ;
if ( V_14 -> V_49 )
(* V_14 -> V_49 )( V_14 ) ;
F_57 ( V_14 ) ;
}
static int F_58 ( struct V_4 * V_5 , struct V_27 * V_28 ,
int (* F_50)( struct V_27 * V_28 ) )
{
struct V_12 * V_14 = NULL ;
unsigned char * V_72 , * V_73 ;
T_2 V_74 ;
T_1 V_26 , V_9 ;
int V_75 ;
T_2 V_46 ;
int V_41 ;
if ( V_5 -> V_55 && F_40 ( V_5 -> V_55 , V_28 ) )
goto V_97;
F_55 ( V_28 , sizeof( struct V_57 ) ) ;
if ( ! F_54 ( V_28 , V_98 ) ) {
F_30 ( V_5 -> V_34 , V_79 , V_80 ,
L_14 , V_5 -> V_37 , V_28 -> V_60 ) ;
goto error;
}
if ( V_5 -> V_34 & V_79 ) {
V_41 = F_59 ( 32u , V_28 -> V_60 ) ;
if ( ! F_54 ( V_28 , V_41 ) )
goto error;
F_60 ( V_36 L_15 , V_5 -> V_37 ) ;
V_75 = 0 ;
do {
F_60 ( L_16 , V_28 -> V_99 [ V_75 ] ) ;
} while ( ++ V_75 < V_41 );
F_60 ( L_17 ) ;
}
V_73 = V_72 = V_28 -> V_99 ;
V_74 = F_42 ( * ( V_84 * ) V_72 ) ;
V_46 = V_74 & V_100 ;
if ( V_46 != V_5 -> V_46 ) {
F_30 ( V_5 -> V_34 , V_79 , V_80 ,
L_18 ,
V_5 -> V_37 , V_46 , V_5 -> V_46 ) ;
goto error;
}
V_41 = V_28 -> V_60 ;
if ( V_74 & V_101 ) {
F_30 ( V_5 -> V_34 , V_79 , V_36 ,
L_19 , V_5 -> V_37 , V_41 ) ;
goto error;
}
V_72 += 2 ;
if ( V_5 -> V_46 == V_47 ) {
if ( V_74 & V_102 )
V_72 += 2 ;
V_26 = F_42 ( * ( V_84 * ) V_72 ) ;
V_72 += 2 ;
V_9 = F_42 ( * ( V_84 * ) V_72 ) ;
V_72 += 2 ;
} else {
V_72 += 2 ;
V_26 = V_5 -> V_26 ;
V_9 = F_52 ( * ( V_88 * ) V_72 ) ;
V_72 += 4 ;
}
V_14 = F_16 ( V_5 -> V_1 , V_5 , V_9 ) ;
if ( ! V_14 || ! V_14 -> V_48 ) {
F_30 ( V_5 -> V_34 , V_79 , V_80 ,
L_20 ,
V_5 -> V_37 , V_26 , V_9 ) ;
goto error;
}
F_49 ( V_14 , V_28 , V_72 , V_73 , V_74 , V_41 , F_50 ) ;
return 0 ;
V_97:
F_61 ( L_21 , V_5 -> V_37 ) ;
F_62 ( V_5 -> V_1 , V_103 , 0 ) ;
V_5 -> V_38 . V_54 ++ ;
F_36 ( V_28 ) ;
return 0 ;
error:
F_63 ( V_28 , sizeof( struct V_57 ) ) ;
return 1 ;
}
int F_64 ( struct V_55 * V_56 , struct V_27 * V_28 )
{
struct V_4 * V_5 ;
V_5 = F_65 ( V_56 ) ;
if ( V_5 == NULL )
goto V_104;
F_30 ( V_5 -> V_34 , V_79 , V_36 ,
L_22 , V_5 -> V_37 , V_28 -> V_60 ) ;
if ( F_58 ( V_5 , V_28 , V_5 -> V_105 ) )
goto V_106;
F_66 ( V_56 ) ;
return 0 ;
V_106:
F_66 ( V_56 ) ;
V_104:
return 1 ;
}
static int F_67 ( struct V_12 * V_14 , void * V_107 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
V_84 * V_108 = V_107 ;
V_84 * V_73 = V_107 ;
T_2 V_109 = V_47 ;
T_1 V_26 = V_5 -> V_110 ;
T_1 V_9 = V_14 -> V_111 ;
if ( V_14 -> V_91 )
V_109 |= V_83 ;
* V_108 ++ = F_68 ( V_109 ) ;
* V_108 ++ = F_68 ( V_26 ) ;
* V_108 ++ = F_68 ( V_9 ) ;
if ( V_14 -> V_91 ) {
* V_108 ++ = F_68 ( V_14 -> V_31 ) ;
* V_108 ++ = 0 ;
V_14 -> V_31 ++ ;
V_14 -> V_31 &= 0xffff ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_23 , V_14 -> V_37 , V_14 -> V_31 ) ;
}
return V_108 - V_73 ;
}
static int F_69 ( struct V_12 * V_14 , void * V_107 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
char * V_108 = V_107 ;
char * V_73 = V_108 ;
if ( V_5 -> V_112 == V_113 ) {
T_2 V_109 = V_114 ;
* ( ( V_84 * ) V_108 ) = F_68 ( V_109 ) ;
V_108 += 2 ;
* ( ( V_84 * ) V_108 ) = 0 ;
V_108 += 2 ;
}
* ( ( V_88 * ) V_108 ) = F_70 ( V_14 -> V_111 ) ;
V_108 += 4 ;
if ( V_14 -> V_115 ) {
memcpy ( V_108 , & V_14 -> V_116 [ 0 ] , V_14 -> V_115 ) ;
V_108 += V_14 -> V_115 ;
}
if ( V_14 -> V_89 ) {
if ( V_14 -> V_85 == V_86 ) {
T_1 V_87 = 0 ;
if ( V_14 -> V_91 ) {
V_87 = 0x40000000 | V_14 -> V_31 ;
V_14 -> V_31 ++ ;
V_14 -> V_31 &= 0xffffff ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_23 , V_14 -> V_37 , V_14 -> V_31 ) ;
}
* ( ( V_88 * ) V_108 ) = F_70 ( V_87 ) ;
}
V_108 += V_14 -> V_89 ;
}
if ( V_14 -> V_75 )
V_108 += V_14 -> V_75 ;
return V_108 - V_73 ;
}
static int F_71 ( struct V_12 * V_14 , struct V_27 * V_28 ,
struct V_117 * V_118 , T_4 V_119 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
unsigned int V_60 = V_28 -> V_60 ;
int error ;
if ( V_14 -> V_91 )
F_30 ( V_14 -> V_34 , V_79 , V_36 ,
L_24 , V_14 -> V_37 ,
V_119 , V_14 -> V_31 - 1 ) ;
else
F_30 ( V_14 -> V_34 , V_79 , V_36 ,
L_25 , V_14 -> V_37 , V_119 ) ;
if ( V_14 -> V_34 & V_79 ) {
int V_120 ;
int V_121 = ( V_5 -> V_112 == V_113 ) ? sizeof( struct V_57 ) : 0 ;
unsigned char * V_122 = V_28 -> V_99 + V_121 ;
F_60 ( V_36 L_26 , V_14 -> V_37 ) ;
for ( V_120 = 0 ; V_120 < ( V_60 - V_121 ) ; V_120 ++ ) {
F_60 ( L_16 , * V_122 ++ ) ;
if ( V_120 == 31 ) {
F_60 ( L_27 ) ;
break;
}
}
F_60 ( L_17 ) ;
}
V_28 -> V_123 = 1 ;
error = F_72 ( V_28 , V_118 ) ;
if ( error >= 0 ) {
V_5 -> V_38 . V_124 ++ ;
V_5 -> V_38 . V_125 += V_60 ;
V_14 -> V_38 . V_124 ++ ;
V_14 -> V_38 . V_125 += V_60 ;
} else {
V_5 -> V_38 . V_126 ++ ;
V_14 -> V_38 . V_126 ++ ;
}
return 0 ;
}
static void F_73 ( struct V_27 * V_28 )
{
F_66 ( V_28 -> V_56 ) ;
}
static inline void F_74 ( struct V_27 * V_28 , struct V_55 * V_56 )
{
F_75 ( V_56 ) ;
V_28 -> V_56 = V_56 ;
V_28 -> V_127 = F_73 ;
}
int F_76 ( struct V_12 * V_14 , struct V_27 * V_28 , int V_128 )
{
int V_119 = V_28 -> V_60 ;
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_55 * V_56 = V_5 -> V_55 ;
struct V_117 * V_118 ;
struct V_57 * V_58 ;
struct V_61 * V_62 ;
T_3 V_71 ;
int V_129 ;
int V_130 ;
int V_131 ;
int V_121 = ( V_5 -> V_112 == V_113 ) ? sizeof( struct V_57 ) : 0 ;
int V_132 ;
V_131 = V_133 + sizeof( struct V_134 ) +
V_121 + V_128 ;
V_129 = F_77 ( V_28 ) ;
if ( F_78 ( V_28 , V_131 ) ) {
F_79 ( V_28 ) ;
goto abort;
}
V_130 = F_77 ( V_28 ) ;
F_35 ( V_28 ) ;
V_28 -> V_135 += V_130 - V_129 ;
V_14 -> V_136 ( V_14 , F_63 ( V_28 , V_128 ) ) ;
memset ( & ( F_80 ( V_28 ) -> V_137 ) , 0 , sizeof( F_80 ( V_28 ) -> V_137 ) ) ;
F_80 ( V_28 ) -> V_109 &= ~ ( V_138 | V_139 |
V_140 ) ;
F_81 ( V_28 ) ;
F_82 ( V_56 ) ;
if ( F_83 ( V_56 ) ) {
F_79 ( V_28 ) ;
goto V_141;
}
F_84 ( V_28 ) ;
F_85 ( V_28 , F_86 ( F_87 ( V_56 , 0 ) ) ) ;
V_62 = F_44 ( V_56 ) ;
V_118 = & V_62 -> V_142 . V_118 ;
switch ( V_5 -> V_112 ) {
case V_113 :
F_63 ( V_28 , sizeof( * V_58 ) ) ;
F_88 ( V_28 ) ;
V_58 = F_41 ( V_28 ) ;
V_58 -> V_143 = V_62 -> V_144 ;
V_58 -> V_145 = V_62 -> V_146 ;
V_132 = V_121 + V_128 + V_119 ;
V_58 -> V_60 = F_68 ( V_132 ) ;
V_58 -> V_65 = 0 ;
if ( V_56 -> V_64 == V_147 )
V_28 -> V_69 = V_148 ;
else if ( ( F_89 ( V_28 ) && F_89 ( V_28 ) -> V_149 ) &&
( ! ( F_89 ( V_28 ) -> V_149 -> V_150 & V_151 ) ) ) {
V_28 -> V_69 = V_70 ;
V_71 = F_90 ( V_28 , 0 , V_132 , 0 ) ;
V_58 -> V_65 = F_91 ( V_62 -> V_66 ,
V_62 -> V_67 ,
V_132 , V_68 , V_71 ) ;
if ( V_58 -> V_65 == 0 )
V_58 -> V_65 = V_152 ;
} else {
V_28 -> V_69 = V_153 ;
V_28 -> V_154 = F_92 ( V_28 ) - V_28 -> V_155 ;
V_28 -> V_156 = F_93 ( struct V_57 , V_65 ) ;
V_58 -> V_65 = ~ F_91 ( V_62 -> V_66 ,
V_62 -> V_67 ,
V_132 , V_68 , 0 ) ;
}
break;
case V_157 :
break;
}
F_74 ( V_28 , V_56 ) ;
F_71 ( V_14 , V_28 , V_118 , V_119 ) ;
V_141:
F_94 ( V_56 ) ;
abort:
return 0 ;
}
static void F_95 ( struct V_55 * V_56 )
{
struct V_4 * V_5 ;
V_5 = V_56 -> V_158 ;
if ( V_5 == NULL )
goto V_159;
F_30 ( V_5 -> V_34 , V_160 , V_80 ,
L_28 , V_5 -> V_37 ) ;
F_96 ( V_5 ) ;
switch ( V_5 -> V_112 ) {
case V_113 :
( F_97 ( V_56 ) ) -> V_161 = 0 ;
( F_97 ( V_56 ) ) -> V_162 = NULL ;
break;
case V_157 :
break;
}
V_5 -> V_55 = NULL ;
V_56 -> V_163 = V_5 -> V_164 ;
V_56 -> V_158 = NULL ;
if ( V_56 -> V_163 )
(* V_56 -> V_163 )( V_56 ) ;
F_98 ( V_5 ) ;
V_159:
return;
}
static void F_96 ( struct V_4 * V_5 )
{
int V_21 ;
struct V_15 * V_16 ;
struct V_15 * V_30 ;
struct V_12 * V_14 ;
F_2 ( V_5 == NULL ) ;
F_30 ( V_5 -> V_34 , V_160 , V_80 ,
L_29 , V_5 -> V_37 ) ;
F_99 ( & V_5 -> V_19 ) ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
V_165:
F_100 (walk, tmp, &tunnel->session_hlist[hash]) {
V_14 = F_101 ( V_16 , struct V_12 , V_166 ) ;
F_30 ( V_14 -> V_34 , V_160 , V_80 ,
L_30 , V_14 -> V_37 ) ;
F_102 ( & V_14 -> V_166 ) ;
if ( V_14 -> V_76 != NULL )
(* V_14 -> V_76 )( V_14 ) ;
F_103 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_46 != V_47 ) {
struct V_1 * V_8 = F_1 ( V_5 -> V_1 ) ;
F_27 ( & V_8 -> V_167 ) ;
F_104 ( & V_14 -> V_168 ) ;
F_33 ( & V_8 -> V_167 ) ;
F_105 () ;
}
if ( V_14 -> V_169 != NULL )
(* V_14 -> V_169 )( V_14 ) ;
if ( V_14 -> V_49 != NULL )
(* V_14 -> V_49 )( V_14 ) ;
F_99 ( & V_5 -> V_19 ) ;
goto V_165;
}
}
F_103 ( & V_5 -> V_19 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_5 -> V_1 ) ;
F_2 ( F_106 ( & V_5 -> V_6 ) != 0 ) ;
F_2 ( V_5 -> V_55 != NULL ) ;
F_30 ( V_5 -> V_34 , V_160 , V_80 ,
L_31 , V_5 -> V_37 ) ;
F_27 ( & V_8 -> V_170 ) ;
F_107 ( & V_5 -> V_171 ) ;
F_33 ( & V_8 -> V_170 ) ;
F_105 () ;
F_108 ( & V_172 ) ;
F_109 ( V_5 ) ;
}
static int F_110 ( T_1 V_26 , T_1 V_110 , struct V_173 * V_174 , struct V_175 * * V_176 )
{
int V_177 = - V_178 ;
struct V_179 V_180 ;
struct V_181 V_182 ;
struct V_175 * V_55 = NULL ;
switch ( V_174 -> V_112 ) {
case V_113 :
V_177 = F_111 ( V_183 , V_184 , 0 , V_176 ) ;
if ( V_177 < 0 )
goto V_40;
V_55 = * V_176 ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_180 . V_185 = V_183 ;
V_180 . V_186 = V_174 -> V_187 ;
V_180 . V_188 = F_68 ( V_174 -> V_189 ) ;
V_177 = F_112 ( V_55 , (struct V_190 * ) & V_180 , sizeof( V_180 ) ) ;
if ( V_177 < 0 )
goto V_40;
V_180 . V_185 = V_183 ;
V_180 . V_186 = V_174 -> V_191 ;
V_180 . V_188 = F_68 ( V_174 -> V_192 ) ;
V_177 = F_113 ( V_55 , (struct V_190 * ) & V_180 , sizeof( V_180 ) , 0 ) ;
if ( V_177 < 0 )
goto V_40;
if ( ! V_174 -> V_193 )
V_55 -> V_56 -> V_64 = V_147 ;
break;
case V_157 :
V_177 = F_111 ( V_183 , V_184 , V_194 , V_176 ) ;
if ( V_177 < 0 )
goto V_40;
V_55 = * V_176 ;
memset ( & V_182 , 0 , sizeof( V_182 ) ) ;
V_182 . V_195 = V_183 ;
V_182 . V_196 = V_174 -> V_187 ;
V_182 . V_197 = V_26 ;
V_177 = F_112 ( V_55 , (struct V_190 * ) & V_182 , sizeof( V_182 ) ) ;
if ( V_177 < 0 )
goto V_40;
V_182 . V_195 = V_183 ;
V_182 . V_196 = V_174 -> V_191 ;
V_182 . V_197 = V_110 ;
V_177 = F_113 ( V_55 , (struct V_190 * ) & V_182 , sizeof( V_182 ) , 0 ) ;
if ( V_177 < 0 )
goto V_40;
break;
default:
goto V_40;
}
V_40:
if ( ( V_177 < 0 ) && V_55 ) {
F_114 ( V_55 ) ;
* V_176 = NULL ;
}
return V_177 ;
}
int F_115 ( struct V_2 * V_2 , int V_198 , int V_46 , T_1 V_26 , T_1 V_110 , struct V_173 * V_174 , struct V_4 * * V_199 )
{
struct V_4 * V_5 = NULL ;
int V_177 ;
struct V_175 * V_55 = NULL ;
struct V_55 * V_56 = NULL ;
struct V_1 * V_8 ;
enum V_200 V_112 = V_113 ;
if ( V_198 < 0 ) {
V_177 = F_110 ( V_26 , V_110 , V_174 , & V_55 ) ;
if ( V_177 < 0 )
goto V_177;
} else {
V_177 = - V_201 ;
V_55 = F_116 ( V_198 , & V_177 ) ;
if ( ! V_55 ) {
F_60 ( V_202 L_32 ,
V_26 , V_198 , V_177 ) ;
goto V_177;
}
}
V_56 = V_55 -> V_56 ;
if ( V_174 != NULL )
V_112 = V_174 -> V_112 ;
switch ( V_112 ) {
case V_113 :
V_177 = - V_203 ;
if ( V_56 -> V_204 != V_68 ) {
F_60 ( V_202 L_33 ,
V_26 , V_198 , V_56 -> V_204 , V_68 ) ;
goto V_177;
}
break;
case V_157 :
V_177 = - V_203 ;
if ( V_56 -> V_204 != V_194 ) {
F_60 ( V_202 L_33 ,
V_26 , V_198 , V_56 -> V_204 , V_194 ) ;
goto V_177;
}
break;
}
V_5 = (struct V_4 * ) V_56 -> V_158 ;
if ( V_5 != NULL ) {
V_177 = - V_205 ;
goto V_177;
}
V_5 = F_117 ( sizeof( struct V_4 ) , V_206 ) ;
if ( V_5 == NULL ) {
V_177 = - V_207 ;
goto V_177;
}
V_5 -> V_46 = V_46 ;
V_5 -> V_26 = V_26 ;
V_5 -> V_110 = V_110 ;
V_5 -> V_34 = V_208 ;
V_5 -> V_209 = V_210 ;
sprintf ( & V_5 -> V_37 [ 0 ] , L_34 , V_26 ) ;
F_118 ( & V_5 -> V_19 ) ;
V_5 -> V_1 = V_2 ;
V_8 = F_1 ( V_2 ) ;
if ( V_174 != NULL )
V_5 -> V_34 = V_174 -> V_34 ;
V_5 -> V_112 = V_112 ;
if ( V_112 == V_113 ) {
F_97 ( V_56 ) -> V_161 = V_211 ;
F_97 ( V_56 ) -> V_162 = F_64 ;
}
V_56 -> V_158 = V_5 ;
V_5 -> V_164 = V_56 -> V_163 ;
V_56 -> V_163 = & F_95 ;
V_5 -> V_55 = V_56 ;
V_56 -> V_212 = V_213 ;
F_119 ( & V_5 -> V_171 ) ;
F_5 ( & V_172 ) ;
F_120 ( V_5 ) ;
F_27 ( & V_8 -> V_170 ) ;
F_121 ( & V_5 -> V_171 , & V_8 -> V_214 ) ;
F_33 ( & V_8 -> V_170 ) ;
V_177 = 0 ;
V_177:
if ( V_199 )
* V_199 = V_5 ;
if ( V_55 && V_55 -> V_215 )
F_122 ( V_55 ) ;
return V_177 ;
}
int F_123 ( struct V_4 * V_5 )
{
int V_177 = 0 ;
struct V_175 * V_55 = V_5 -> V_55 ? V_5 -> V_55 -> V_216 : NULL ;
if ( V_55 != NULL ) {
V_177 = F_124 ( V_55 , 2 ) ;
if ( V_55 -> V_215 == NULL )
V_177 = F_125 ( V_55 ) ;
}
return V_177 ;
}
void F_126 ( struct V_12 * V_14 )
{
struct V_4 * V_5 ;
F_2 ( F_106 ( & V_14 -> V_6 ) != 0 ) ;
V_5 = V_14 -> V_5 ;
if ( V_5 != NULL ) {
F_2 ( V_5 -> V_209 != V_210 ) ;
F_99 ( & V_5 -> V_19 ) ;
F_102 ( & V_14 -> V_166 ) ;
F_103 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_46 != V_47 ) {
struct V_1 * V_8 = F_1 ( V_5 -> V_1 ) ;
F_27 ( & V_8 -> V_167 ) ;
F_104 ( & V_14 -> V_168 ) ;
F_33 ( & V_8 -> V_167 ) ;
F_105 () ;
}
if ( V_14 -> V_9 != 0 )
F_108 ( & V_217 ) ;
F_66 ( V_5 -> V_55 ) ;
V_14 -> V_5 = NULL ;
F_98 ( V_5 ) ;
}
F_109 ( V_14 ) ;
return;
}
int F_127 ( struct V_12 * V_14 )
{
if ( V_14 -> V_169 != NULL )
(* V_14 -> V_169 )( V_14 ) ;
F_57 ( V_14 ) ;
return 0 ;
}
static void F_53 ( struct V_12 * V_14 , int V_46 )
{
if ( V_46 == V_47 ) {
V_14 -> V_128 = 6 ;
if ( V_14 -> V_91 )
V_14 -> V_128 += 4 ;
} else {
V_14 -> V_128 = 4 + V_14 -> V_115 + V_14 -> V_89 + V_14 -> V_75 ;
if ( V_14 -> V_5 -> V_112 == V_113 )
V_14 -> V_128 += 4 ;
}
}
struct V_12 * F_128 ( int V_218 , struct V_4 * V_5 , T_1 V_9 , T_1 V_111 , struct V_219 * V_174 )
{
struct V_12 * V_14 ;
V_14 = F_117 ( sizeof( struct V_12 ) + V_218 , V_206 ) ;
if ( V_14 != NULL ) {
V_14 -> V_209 = V_220 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_9 = V_9 ;
V_14 -> V_111 = V_111 ;
V_14 -> V_45 = 1 ;
sprintf ( & V_14 -> V_37 [ 0 ] , L_35 ,
V_5 -> V_26 , V_14 -> V_9 ) ;
F_129 ( & V_14 -> V_32 ) ;
F_130 ( & V_14 -> V_166 ) ;
F_130 ( & V_14 -> V_168 ) ;
V_14 -> V_34 = V_5 -> V_34 ;
if ( V_174 ) {
V_14 -> V_221 = V_174 -> V_222 ;
V_14 -> V_34 = V_174 -> V_34 ;
V_14 -> V_223 = V_174 -> V_223 ;
V_14 -> V_224 = V_174 -> V_224 ;
V_14 -> V_91 = V_174 -> V_91 ;
V_14 -> V_92 = V_174 -> V_92 ;
V_14 -> V_90 = V_174 -> V_90 ;
V_14 -> V_95 = V_174 -> V_95 ;
V_14 -> V_75 = V_174 -> V_75 ;
V_14 -> V_85 = V_174 -> V_85 ;
V_14 -> V_89 = V_174 -> V_89 ;
V_14 -> V_115 = V_174 -> V_115 ;
memcpy ( & V_14 -> V_116 [ 0 ] , & V_174 -> V_116 [ 0 ] , V_174 -> V_115 ) ;
V_14 -> V_77 = V_174 -> V_77 ;
memcpy ( & V_14 -> V_78 [ 0 ] , & V_174 -> V_78 [ 0 ] , V_174 -> V_77 ) ;
}
if ( V_5 -> V_46 == V_47 )
V_14 -> V_136 = F_67 ;
else
V_14 -> V_136 = F_69 ;
F_53 ( V_14 , V_5 -> V_46 ) ;
F_51 ( V_14 ) ;
F_120 ( V_5 ) ;
F_75 ( V_5 -> V_55 ) ;
F_99 ( & V_5 -> V_19 ) ;
F_131 ( & V_14 -> V_166 ,
F_15 ( V_5 , V_9 ) ) ;
F_103 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_46 != V_47 ) {
struct V_1 * V_8 = F_1 ( V_5 -> V_1 ) ;
F_27 ( & V_8 -> V_167 ) ;
F_132 ( & V_14 -> V_168 ,
F_9 ( V_8 , V_9 ) ) ;
F_33 ( & V_8 -> V_167 ) ;
}
if ( V_14 -> V_9 != 0 )
F_5 ( & V_217 ) ;
}
return V_14 ;
}
static T_5 int F_133 ( struct V_2 * V_2 )
{
struct V_1 * V_8 = F_3 ( V_2 , V_3 ) ;
int V_21 ;
F_119 ( & V_8 -> V_214 ) ;
F_134 ( & V_8 -> V_170 ) ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ )
F_135 ( & V_8 -> V_10 [ V_21 ] ) ;
F_134 ( & V_8 -> V_167 ) ;
return 0 ;
}
static int T_6 F_136 ( void )
{
int V_225 = 0 ;
V_225 = F_137 ( & V_226 ) ;
if ( V_225 )
goto V_40;
F_60 ( V_80 L_36 , V_227 ) ;
V_40:
return V_225 ;
}
static void T_7 F_138 ( void )
{
F_139 ( & V_226 ) ;
}
