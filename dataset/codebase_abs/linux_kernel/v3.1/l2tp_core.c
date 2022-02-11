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
F_27 ( & V_14 -> V_32 . V_33 ) ;
F_28 (&session->reorder_q, skb, tmp) {
if ( F_38 ( V_50 , F_26 ( V_28 ) -> V_51 ) ) {
V_14 -> V_38 . V_52 ++ ;
V_14 -> V_38 . V_53 ++ ;
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
F_27 ( & V_14 -> V_32 . V_33 ) ;
}
V_40:
F_33 ( & V_14 -> V_32 . V_33 ) ;
}
static inline int F_40 ( struct V_54 * V_55 ,
struct V_27 * V_28 )
{
struct V_56 * V_57 = F_41 ( V_28 ) ;
T_2 V_58 = F_42 ( V_57 -> V_59 ) ;
struct V_60 * V_61 ;
T_3 V_62 ;
if ( V_55 -> V_63 || F_43 ( V_28 ) || ! V_57 -> V_64 )
return 0 ;
V_61 = F_44 ( V_55 ) ;
V_62 = F_45 ( V_61 -> V_65 , V_61 -> V_66 , V_58 ,
V_67 , 0 ) ;
if ( ( V_28 -> V_68 == V_69 ) &&
! F_46 ( F_47 ( V_62 , V_28 -> V_70 ) ) )
return 0 ;
V_28 -> V_70 = V_62 ;
return F_48 ( V_28 ) ;
}
void F_49 ( struct V_12 * V_14 , struct V_27 * V_28 ,
unsigned char * V_71 , unsigned char * V_72 , T_2 V_73 ,
int V_41 , int (* F_50)( struct V_27 * V_28 ) )
{
struct V_4 * V_5 = V_14 -> V_5 ;
int V_74 ;
T_1 V_31 , V_45 ;
F_51 ( V_14 ) ;
if ( V_14 -> V_75 )
(* V_14 -> V_75 )( V_14 ) ;
if ( V_14 -> V_76 > 0 ) {
if ( memcmp ( V_71 , & V_14 -> V_77 [ 0 ] , V_14 -> V_76 ) ) {
F_30 ( V_5 -> V_34 , V_78 , V_79 ,
L_6 ,
V_5 -> V_37 , V_5 -> V_26 , V_14 -> V_9 ) ;
V_14 -> V_38 . V_80 ++ ;
goto V_81;
}
V_71 += V_14 -> V_76 ;
}
V_31 = V_45 = 0 ;
F_26 ( V_28 ) -> V_44 = 0 ;
if ( V_5 -> V_46 == V_47 ) {
if ( V_73 & V_82 ) {
V_31 = F_42 ( * ( V_83 * ) V_71 ) ;
V_71 += 2 ;
V_45 = F_42 ( * ( V_83 * ) V_71 ) ;
V_71 += 2 ;
F_26 ( V_28 ) -> V_31 = V_31 ;
F_26 ( V_28 ) -> V_44 = 1 ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_7 ,
V_14 -> V_37 , V_31 , V_45 , V_14 -> V_45 ) ;
}
} else if ( V_14 -> V_84 == V_85 ) {
T_1 V_86 = F_52 ( * ( V_87 * ) V_71 ) ;
if ( V_86 & 0x40000000 ) {
V_31 = V_86 & 0x00ffffff ;
F_26 ( V_28 ) -> V_31 = V_31 ;
F_26 ( V_28 ) -> V_44 = 1 ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_8 ,
V_14 -> V_37 , V_31 , V_14 -> V_45 ) ;
}
}
V_71 += V_14 -> V_88 ;
if ( F_26 ( V_28 ) -> V_44 ) {
if ( ( ! V_14 -> V_89 ) && ( ! V_14 -> V_90 ) ) {
F_30 ( V_14 -> V_34 , V_35 , V_79 ,
L_9 ,
V_14 -> V_37 ) ;
V_14 -> V_90 = - 1 ;
F_53 ( V_14 , V_5 -> V_46 ) ;
}
} else {
if ( V_14 -> V_91 ) {
F_30 ( V_14 -> V_34 , V_35 , V_92 ,
L_10
L_11 , V_14 -> V_37 ) ;
V_14 -> V_38 . V_52 ++ ;
goto V_81;
}
if ( ( ! V_14 -> V_89 ) && ( V_14 -> V_90 ) ) {
F_30 ( V_14 -> V_34 , V_35 , V_79 ,
L_12 ,
V_14 -> V_37 ) ;
V_14 -> V_90 = 0 ;
F_53 ( V_14 , V_5 -> V_46 ) ;
} else if ( V_14 -> V_90 ) {
F_30 ( V_14 -> V_34 , V_35 , V_92 ,
L_10
L_11 , V_14 -> V_37 ) ;
V_14 -> V_38 . V_52 ++ ;
goto V_81;
}
}
if ( V_5 -> V_46 == V_47 ) {
if ( V_73 & V_93 ) {
V_74 = F_42 ( * ( V_83 * ) V_71 ) ;
V_71 += 2 + V_74 ;
}
} else
V_71 += V_14 -> V_74 ;
V_74 = V_71 - V_72 ;
if ( ! F_54 ( V_28 , V_74 ) )
goto V_81;
F_55 ( V_28 , V_74 ) ;
if ( F_50 )
if ( (* F_50)( V_28 ) )
goto V_81;
F_26 ( V_28 ) -> V_41 = V_41 ;
F_26 ( V_28 ) -> V_51 = V_50 +
( V_14 -> V_94 ? V_14 -> V_94 : V_95 ) ;
if ( F_26 ( V_28 ) -> V_44 ) {
if ( V_14 -> V_94 != 0 ) {
F_25 ( V_14 , V_28 ) ;
} else {
if ( F_26 ( V_28 ) -> V_31 != V_14 -> V_45 ) {
V_14 -> V_38 . V_52 ++ ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_13
L_4 ,
V_14 -> V_37 , F_26 ( V_28 ) -> V_31 ,
F_26 ( V_28 ) -> V_41 , V_14 -> V_45 ,
F_31 ( & V_14 -> V_32 ) ) ;
goto V_81;
}
F_56 ( & V_14 -> V_32 , V_28 ) ;
}
} else {
F_56 ( & V_14 -> V_32 , V_28 ) ;
}
F_37 ( V_14 ) ;
F_57 ( V_14 ) ;
return;
V_81:
V_14 -> V_38 . V_53 ++ ;
F_36 ( V_28 ) ;
if ( V_14 -> V_49 )
(* V_14 -> V_49 )( V_14 ) ;
F_57 ( V_14 ) ;
}
static int F_58 ( struct V_4 * V_5 , struct V_27 * V_28 ,
int (* F_50)( struct V_27 * V_28 ) )
{
struct V_12 * V_14 = NULL ;
unsigned char * V_71 , * V_72 ;
T_2 V_73 ;
T_1 V_26 , V_9 ;
int V_74 ;
T_2 V_46 ;
int V_41 ;
if ( V_5 -> V_54 && F_40 ( V_5 -> V_54 , V_28 ) )
goto V_96;
F_55 ( V_28 , sizeof( struct V_56 ) ) ;
if ( ! F_54 ( V_28 , V_97 ) ) {
F_30 ( V_5 -> V_34 , V_78 , V_79 ,
L_14 , V_5 -> V_37 , V_28 -> V_59 ) ;
goto error;
}
V_72 = V_71 = V_28 -> V_98 ;
if ( V_5 -> V_34 & V_78 ) {
V_41 = F_59 ( 32u , V_28 -> V_59 ) ;
if ( ! F_54 ( V_28 , V_41 ) )
goto error;
F_60 ( V_36 L_15 , V_5 -> V_37 ) ;
V_74 = 0 ;
do {
F_60 ( L_16 , V_71 [ V_74 ] ) ;
} while ( ++ V_74 < V_41 );
F_60 ( L_17 ) ;
}
V_73 = F_42 ( * ( V_83 * ) V_71 ) ;
V_46 = V_73 & V_99 ;
if ( V_46 != V_5 -> V_46 ) {
F_30 ( V_5 -> V_34 , V_78 , V_79 ,
L_18 ,
V_5 -> V_37 , V_46 , V_5 -> V_46 ) ;
goto error;
}
V_41 = V_28 -> V_59 ;
if ( V_73 & V_100 ) {
F_30 ( V_5 -> V_34 , V_78 , V_36 ,
L_19 , V_5 -> V_37 , V_41 ) ;
goto error;
}
V_71 += 2 ;
if ( V_5 -> V_46 == V_47 ) {
if ( V_73 & V_101 )
V_71 += 2 ;
V_26 = F_42 ( * ( V_83 * ) V_71 ) ;
V_71 += 2 ;
V_9 = F_42 ( * ( V_83 * ) V_71 ) ;
V_71 += 2 ;
} else {
V_71 += 2 ;
V_26 = V_5 -> V_26 ;
V_9 = F_52 ( * ( V_87 * ) V_71 ) ;
V_71 += 4 ;
}
V_14 = F_16 ( V_5 -> V_1 , V_5 , V_9 ) ;
if ( ! V_14 || ! V_14 -> V_48 ) {
F_30 ( V_5 -> V_34 , V_78 , V_79 ,
L_20 ,
V_5 -> V_37 , V_26 , V_9 ) ;
goto error;
}
F_49 ( V_14 , V_28 , V_71 , V_72 , V_73 , V_41 , F_50 ) ;
return 0 ;
V_96:
F_61 ( L_21 , V_5 -> V_37 ) ;
F_62 ( V_5 -> V_1 , V_102 , 0 ) ;
V_5 -> V_38 . V_53 ++ ;
F_36 ( V_28 ) ;
return 0 ;
error:
F_63 ( V_28 , sizeof( struct V_56 ) ) ;
return 1 ;
}
int F_64 ( struct V_54 * V_55 , struct V_27 * V_28 )
{
struct V_4 * V_5 ;
V_5 = F_65 ( V_55 ) ;
if ( V_5 == NULL )
goto V_103;
F_30 ( V_5 -> V_34 , V_78 , V_36 ,
L_22 , V_5 -> V_37 , V_28 -> V_59 ) ;
if ( F_58 ( V_5 , V_28 , V_5 -> V_104 ) )
goto V_105;
F_66 ( V_55 ) ;
return 0 ;
V_105:
F_66 ( V_55 ) ;
V_103:
return 1 ;
}
static int F_67 ( struct V_12 * V_14 , void * V_106 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
V_83 * V_107 = V_106 ;
V_83 * V_72 = V_106 ;
T_2 V_108 = V_47 ;
T_1 V_26 = V_5 -> V_109 ;
T_1 V_9 = V_14 -> V_110 ;
if ( V_14 -> V_90 )
V_108 |= V_82 ;
* V_107 ++ = F_68 ( V_108 ) ;
* V_107 ++ = F_68 ( V_26 ) ;
* V_107 ++ = F_68 ( V_9 ) ;
if ( V_14 -> V_90 ) {
* V_107 ++ = F_68 ( V_14 -> V_31 ) ;
* V_107 ++ = 0 ;
V_14 -> V_31 ++ ;
V_14 -> V_31 &= 0xffff ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_23 , V_14 -> V_37 , V_14 -> V_31 ) ;
}
return V_107 - V_72 ;
}
static int F_69 ( struct V_12 * V_14 , void * V_106 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
char * V_107 = V_106 ;
char * V_72 = V_107 ;
if ( V_5 -> V_111 == V_112 ) {
T_2 V_108 = V_113 ;
* ( ( V_83 * ) V_107 ) = F_68 ( V_108 ) ;
V_107 += 2 ;
* ( ( V_83 * ) V_107 ) = 0 ;
V_107 += 2 ;
}
* ( ( V_87 * ) V_107 ) = F_70 ( V_14 -> V_110 ) ;
V_107 += 4 ;
if ( V_14 -> V_114 ) {
memcpy ( V_107 , & V_14 -> V_115 [ 0 ] , V_14 -> V_114 ) ;
V_107 += V_14 -> V_114 ;
}
if ( V_14 -> V_88 ) {
if ( V_14 -> V_84 == V_85 ) {
T_1 V_86 = 0 ;
if ( V_14 -> V_90 ) {
V_86 = 0x40000000 | V_14 -> V_31 ;
V_14 -> V_31 ++ ;
V_14 -> V_31 &= 0xffffff ;
F_30 ( V_14 -> V_34 , V_35 , V_36 ,
L_23 , V_14 -> V_37 , V_14 -> V_31 ) ;
}
* ( ( V_87 * ) V_107 ) = F_70 ( V_86 ) ;
}
V_107 += V_14 -> V_88 ;
}
if ( V_14 -> V_74 )
V_107 += V_14 -> V_74 ;
return V_107 - V_72 ;
}
static int F_71 ( struct V_12 * V_14 , struct V_27 * V_28 ,
struct V_116 * V_117 , T_4 V_118 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
unsigned int V_59 = V_28 -> V_59 ;
int error ;
if ( V_14 -> V_90 )
F_30 ( V_14 -> V_34 , V_78 , V_36 ,
L_24 , V_14 -> V_37 ,
V_118 , V_14 -> V_31 - 1 ) ;
else
F_30 ( V_14 -> V_34 , V_78 , V_36 ,
L_25 , V_14 -> V_37 , V_118 ) ;
if ( V_14 -> V_34 & V_78 ) {
int V_119 ;
int V_120 = ( V_5 -> V_111 == V_112 ) ? sizeof( struct V_56 ) : 0 ;
unsigned char * V_121 = V_28 -> V_98 + V_120 ;
F_60 ( V_36 L_26 , V_14 -> V_37 ) ;
for ( V_119 = 0 ; V_119 < ( V_59 - V_120 ) ; V_119 ++ ) {
F_60 ( L_16 , * V_121 ++ ) ;
if ( V_119 == 31 ) {
F_60 ( L_27 ) ;
break;
}
}
F_60 ( L_17 ) ;
}
V_28 -> V_122 = 1 ;
error = F_72 ( V_28 , V_117 ) ;
if ( error >= 0 ) {
V_5 -> V_38 . V_123 ++ ;
V_5 -> V_38 . V_124 += V_59 ;
V_14 -> V_38 . V_123 ++ ;
V_14 -> V_38 . V_124 += V_59 ;
} else {
V_5 -> V_38 . V_125 ++ ;
V_14 -> V_38 . V_125 ++ ;
}
return 0 ;
}
static void F_73 ( struct V_27 * V_28 )
{
F_66 ( V_28 -> V_55 ) ;
}
static inline void F_74 ( struct V_27 * V_28 , struct V_54 * V_55 )
{
F_75 ( V_55 ) ;
V_28 -> V_55 = V_55 ;
V_28 -> V_126 = F_73 ;
}
int F_76 ( struct V_12 * V_14 , struct V_27 * V_28 , int V_127 )
{
int V_118 = V_28 -> V_59 ;
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_54 * V_55 = V_5 -> V_54 ;
struct V_116 * V_117 ;
struct V_56 * V_57 ;
struct V_60 * V_61 ;
T_3 V_70 ;
int V_128 ;
int V_129 ;
int V_130 ;
int V_120 = ( V_5 -> V_111 == V_112 ) ? sizeof( struct V_56 ) : 0 ;
int V_131 ;
V_130 = V_132 + sizeof( struct V_133 ) +
V_120 + V_127 ;
V_128 = F_77 ( V_28 ) ;
if ( F_78 ( V_28 , V_130 ) ) {
F_79 ( V_28 ) ;
goto abort;
}
V_129 = F_77 ( V_28 ) ;
F_35 ( V_28 ) ;
V_28 -> V_134 += V_129 - V_128 ;
V_14 -> V_135 ( V_14 , F_63 ( V_28 , V_127 ) ) ;
memset ( & ( F_80 ( V_28 ) -> V_136 ) , 0 , sizeof( F_80 ( V_28 ) -> V_136 ) ) ;
F_80 ( V_28 ) -> V_108 &= ~ ( V_137 | V_138 |
V_139 ) ;
F_81 ( V_28 ) ;
F_82 ( V_55 ) ;
if ( F_83 ( V_55 ) ) {
F_79 ( V_28 ) ;
goto V_140;
}
F_84 ( V_28 ) ;
F_85 ( V_28 , F_86 ( F_87 ( V_55 ) ) ) ;
V_61 = F_44 ( V_55 ) ;
V_117 = & V_61 -> V_141 . V_117 ;
switch ( V_5 -> V_111 ) {
case V_112 :
F_63 ( V_28 , sizeof( * V_57 ) ) ;
F_88 ( V_28 ) ;
V_57 = F_41 ( V_28 ) ;
V_57 -> V_142 = V_61 -> V_143 ;
V_57 -> V_144 = V_61 -> V_145 ;
V_131 = V_120 + V_127 + V_118 ;
V_57 -> V_59 = F_68 ( V_131 ) ;
V_57 -> V_64 = 0 ;
if ( V_55 -> V_63 == V_146 )
V_28 -> V_68 = V_147 ;
else if ( ( F_89 ( V_28 ) && F_89 ( V_28 ) -> V_148 ) &&
( ! ( F_89 ( V_28 ) -> V_148 -> V_149 & V_150 ) ) ) {
V_28 -> V_68 = V_69 ;
V_70 = F_90 ( V_28 , 0 , V_131 , 0 ) ;
V_57 -> V_64 = F_91 ( V_61 -> V_65 ,
V_61 -> V_66 ,
V_131 , V_67 , V_70 ) ;
if ( V_57 -> V_64 == 0 )
V_57 -> V_64 = V_151 ;
} else {
V_28 -> V_68 = V_152 ;
V_28 -> V_153 = F_92 ( V_28 ) - V_28 -> V_154 ;
V_28 -> V_155 = F_93 ( struct V_56 , V_64 ) ;
V_57 -> V_64 = ~ F_91 ( V_61 -> V_65 ,
V_61 -> V_66 ,
V_131 , V_67 , 0 ) ;
}
break;
case V_156 :
break;
}
F_74 ( V_28 , V_55 ) ;
F_71 ( V_14 , V_28 , V_117 , V_118 ) ;
V_140:
F_94 ( V_55 ) ;
abort:
return 0 ;
}
static void F_95 ( struct V_54 * V_55 )
{
struct V_4 * V_5 ;
V_5 = V_55 -> V_157 ;
if ( V_5 == NULL )
goto V_158;
F_30 ( V_5 -> V_34 , V_159 , V_79 ,
L_28 , V_5 -> V_37 ) ;
F_96 ( V_5 ) ;
switch ( V_5 -> V_111 ) {
case V_112 :
( F_97 ( V_55 ) ) -> V_160 = 0 ;
( F_97 ( V_55 ) ) -> V_161 = NULL ;
break;
case V_156 :
break;
}
V_5 -> V_54 = NULL ;
V_55 -> V_162 = V_5 -> V_163 ;
V_55 -> V_157 = NULL ;
if ( V_55 -> V_162 )
(* V_55 -> V_162 )( V_55 ) ;
F_98 ( V_5 ) ;
V_158:
return;
}
static void F_96 ( struct V_4 * V_5 )
{
int V_21 ;
struct V_15 * V_16 ;
struct V_15 * V_30 ;
struct V_12 * V_14 ;
F_2 ( V_5 == NULL ) ;
F_30 ( V_5 -> V_34 , V_159 , V_79 ,
L_29 , V_5 -> V_37 ) ;
F_99 ( & V_5 -> V_19 ) ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
V_164:
F_100 (walk, tmp, &tunnel->session_hlist[hash]) {
V_14 = F_101 ( V_16 , struct V_12 , V_165 ) ;
F_30 ( V_14 -> V_34 , V_159 , V_79 ,
L_30 , V_14 -> V_37 ) ;
F_102 ( & V_14 -> V_165 ) ;
if ( V_14 -> V_75 != NULL )
(* V_14 -> V_75 )( V_14 ) ;
F_103 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_46 != V_47 ) {
struct V_1 * V_8 = F_1 ( V_5 -> V_1 ) ;
F_27 ( & V_8 -> V_166 ) ;
F_104 ( & V_14 -> V_167 ) ;
F_33 ( & V_8 -> V_166 ) ;
F_105 () ;
}
if ( V_14 -> V_168 != NULL )
(* V_14 -> V_168 )( V_14 ) ;
if ( V_14 -> V_49 != NULL )
(* V_14 -> V_49 )( V_14 ) ;
F_99 ( & V_5 -> V_19 ) ;
goto V_164;
}
}
F_103 ( & V_5 -> V_19 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_5 -> V_1 ) ;
F_2 ( F_106 ( & V_5 -> V_6 ) != 0 ) ;
F_2 ( V_5 -> V_54 != NULL ) ;
F_30 ( V_5 -> V_34 , V_159 , V_79 ,
L_31 , V_5 -> V_37 ) ;
F_27 ( & V_8 -> V_169 ) ;
F_107 ( & V_5 -> V_170 ) ;
F_33 ( & V_8 -> V_169 ) ;
F_105 () ;
F_108 ( & V_171 ) ;
F_109 ( V_5 ) ;
}
static int F_110 ( T_1 V_26 , T_1 V_109 , struct V_172 * V_173 , struct V_174 * * V_175 )
{
int V_176 = - V_177 ;
struct V_178 V_179 ;
struct V_180 V_181 ;
struct V_174 * V_54 = NULL ;
switch ( V_173 -> V_111 ) {
case V_112 :
V_176 = F_111 ( V_182 , V_183 , 0 , V_175 ) ;
if ( V_176 < 0 )
goto V_40;
V_54 = * V_175 ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_179 . V_184 = V_182 ;
V_179 . V_185 = V_173 -> V_186 ;
V_179 . V_187 = F_68 ( V_173 -> V_188 ) ;
V_176 = F_112 ( V_54 , (struct V_189 * ) & V_179 , sizeof( V_179 ) ) ;
if ( V_176 < 0 )
goto V_40;
V_179 . V_184 = V_182 ;
V_179 . V_185 = V_173 -> V_190 ;
V_179 . V_187 = F_68 ( V_173 -> V_191 ) ;
V_176 = F_113 ( V_54 , (struct V_189 * ) & V_179 , sizeof( V_179 ) , 0 ) ;
if ( V_176 < 0 )
goto V_40;
if ( ! V_173 -> V_192 )
V_54 -> V_55 -> V_63 = V_146 ;
break;
case V_156 :
V_176 = F_111 ( V_182 , V_183 , V_193 , V_175 ) ;
if ( V_176 < 0 )
goto V_40;
V_54 = * V_175 ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
V_181 . V_194 = V_182 ;
V_181 . V_195 = V_173 -> V_186 ;
V_181 . V_196 = V_26 ;
V_176 = F_112 ( V_54 , (struct V_189 * ) & V_181 , sizeof( V_181 ) ) ;
if ( V_176 < 0 )
goto V_40;
V_181 . V_194 = V_182 ;
V_181 . V_195 = V_173 -> V_190 ;
V_181 . V_196 = V_109 ;
V_176 = F_113 ( V_54 , (struct V_189 * ) & V_181 , sizeof( V_181 ) , 0 ) ;
if ( V_176 < 0 )
goto V_40;
break;
default:
goto V_40;
}
V_40:
if ( ( V_176 < 0 ) && V_54 ) {
F_114 ( V_54 ) ;
* V_175 = NULL ;
}
return V_176 ;
}
int F_115 ( struct V_2 * V_2 , int V_197 , int V_46 , T_1 V_26 , T_1 V_109 , struct V_172 * V_173 , struct V_4 * * V_198 )
{
struct V_4 * V_5 = NULL ;
int V_176 ;
struct V_174 * V_54 = NULL ;
struct V_54 * V_55 = NULL ;
struct V_1 * V_8 ;
enum V_199 V_111 = V_112 ;
if ( V_197 < 0 ) {
V_176 = F_110 ( V_26 , V_109 , V_173 , & V_54 ) ;
if ( V_176 < 0 )
goto V_176;
} else {
V_176 = - V_200 ;
V_54 = F_116 ( V_197 , & V_176 ) ;
if ( ! V_54 ) {
F_60 ( V_201 L_32 ,
V_26 , V_197 , V_176 ) ;
goto V_176;
}
}
V_55 = V_54 -> V_55 ;
if ( V_173 != NULL )
V_111 = V_173 -> V_111 ;
switch ( V_111 ) {
case V_112 :
V_176 = - V_202 ;
if ( V_55 -> V_203 != V_67 ) {
F_60 ( V_201 L_33 ,
V_26 , V_197 , V_55 -> V_203 , V_67 ) ;
goto V_176;
}
break;
case V_156 :
V_176 = - V_202 ;
if ( V_55 -> V_203 != V_193 ) {
F_60 ( V_201 L_33 ,
V_26 , V_197 , V_55 -> V_203 , V_193 ) ;
goto V_176;
}
break;
}
V_5 = (struct V_4 * ) V_55 -> V_157 ;
if ( V_5 != NULL ) {
V_176 = - V_204 ;
goto V_176;
}
V_5 = F_117 ( sizeof( struct V_4 ) , V_205 ) ;
if ( V_5 == NULL ) {
V_176 = - V_206 ;
goto V_176;
}
V_5 -> V_46 = V_46 ;
V_5 -> V_26 = V_26 ;
V_5 -> V_109 = V_109 ;
V_5 -> V_34 = V_207 ;
V_5 -> V_208 = V_209 ;
sprintf ( & V_5 -> V_37 [ 0 ] , L_34 , V_26 ) ;
F_118 ( & V_5 -> V_19 ) ;
V_5 -> V_1 = V_2 ;
V_8 = F_1 ( V_2 ) ;
if ( V_173 != NULL )
V_5 -> V_34 = V_173 -> V_34 ;
V_5 -> V_111 = V_111 ;
if ( V_111 == V_112 ) {
F_97 ( V_55 ) -> V_160 = V_210 ;
F_97 ( V_55 ) -> V_161 = F_64 ;
}
V_55 -> V_157 = V_5 ;
V_5 -> V_163 = V_55 -> V_162 ;
V_55 -> V_162 = & F_95 ;
V_5 -> V_54 = V_55 ;
V_55 -> V_211 = V_212 ;
F_119 ( & V_5 -> V_170 ) ;
F_5 ( & V_171 ) ;
F_120 ( V_5 ) ;
F_27 ( & V_8 -> V_169 ) ;
F_121 ( & V_5 -> V_170 , & V_8 -> V_213 ) ;
F_33 ( & V_8 -> V_169 ) ;
V_176 = 0 ;
V_176:
if ( V_198 )
* V_198 = V_5 ;
if ( V_54 && V_54 -> V_214 )
F_122 ( V_54 ) ;
return V_176 ;
}
int F_123 ( struct V_4 * V_5 )
{
int V_176 = 0 ;
struct V_174 * V_54 = V_5 -> V_54 ? V_5 -> V_54 -> V_215 : NULL ;
if ( V_54 != NULL ) {
V_176 = F_124 ( V_54 , 2 ) ;
if ( V_54 -> V_214 == NULL )
V_176 = F_125 ( V_54 ) ;
}
return V_176 ;
}
void F_126 ( struct V_12 * V_14 )
{
struct V_4 * V_5 ;
F_2 ( F_106 ( & V_14 -> V_6 ) != 0 ) ;
V_5 = V_14 -> V_5 ;
if ( V_5 != NULL ) {
F_2 ( V_5 -> V_208 != V_209 ) ;
F_99 ( & V_5 -> V_19 ) ;
F_102 ( & V_14 -> V_165 ) ;
F_103 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_46 != V_47 ) {
struct V_1 * V_8 = F_1 ( V_5 -> V_1 ) ;
F_27 ( & V_8 -> V_166 ) ;
F_104 ( & V_14 -> V_167 ) ;
F_33 ( & V_8 -> V_166 ) ;
F_105 () ;
}
if ( V_14 -> V_9 != 0 )
F_108 ( & V_216 ) ;
F_66 ( V_5 -> V_54 ) ;
V_14 -> V_5 = NULL ;
F_98 ( V_5 ) ;
}
F_109 ( V_14 ) ;
return;
}
int F_127 ( struct V_12 * V_14 )
{
if ( V_14 -> V_168 != NULL )
(* V_14 -> V_168 )( V_14 ) ;
F_57 ( V_14 ) ;
return 0 ;
}
static void F_53 ( struct V_12 * V_14 , int V_46 )
{
if ( V_46 == V_47 ) {
V_14 -> V_127 = 6 ;
if ( V_14 -> V_90 )
V_14 -> V_127 += 4 ;
} else {
V_14 -> V_127 = 4 + V_14 -> V_114 + V_14 -> V_88 + V_14 -> V_74 ;
if ( V_14 -> V_5 -> V_111 == V_112 )
V_14 -> V_127 += 4 ;
}
}
struct V_12 * F_128 ( int V_217 , struct V_4 * V_5 , T_1 V_9 , T_1 V_110 , struct V_218 * V_173 )
{
struct V_12 * V_14 ;
V_14 = F_117 ( sizeof( struct V_12 ) + V_217 , V_205 ) ;
if ( V_14 != NULL ) {
V_14 -> V_208 = V_219 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_9 = V_9 ;
V_14 -> V_110 = V_110 ;
V_14 -> V_45 = 1 ;
sprintf ( & V_14 -> V_37 [ 0 ] , L_35 ,
V_5 -> V_26 , V_14 -> V_9 ) ;
F_129 ( & V_14 -> V_32 ) ;
F_130 ( & V_14 -> V_165 ) ;
F_130 ( & V_14 -> V_167 ) ;
V_14 -> V_34 = V_5 -> V_34 ;
if ( V_173 ) {
V_14 -> V_220 = V_173 -> V_221 ;
V_14 -> V_34 = V_173 -> V_34 ;
V_14 -> V_222 = V_173 -> V_222 ;
V_14 -> V_223 = V_173 -> V_223 ;
V_14 -> V_90 = V_173 -> V_90 ;
V_14 -> V_91 = V_173 -> V_91 ;
V_14 -> V_89 = V_173 -> V_89 ;
V_14 -> V_94 = V_173 -> V_94 ;
V_14 -> V_74 = V_173 -> V_74 ;
V_14 -> V_84 = V_173 -> V_84 ;
V_14 -> V_88 = V_173 -> V_88 ;
V_14 -> V_114 = V_173 -> V_114 ;
memcpy ( & V_14 -> V_115 [ 0 ] , & V_173 -> V_115 [ 0 ] , V_173 -> V_114 ) ;
V_14 -> V_76 = V_173 -> V_76 ;
memcpy ( & V_14 -> V_77 [ 0 ] , & V_173 -> V_77 [ 0 ] , V_173 -> V_76 ) ;
}
if ( V_5 -> V_46 == V_47 )
V_14 -> V_135 = F_67 ;
else
V_14 -> V_135 = F_69 ;
F_53 ( V_14 , V_5 -> V_46 ) ;
F_51 ( V_14 ) ;
F_120 ( V_5 ) ;
F_75 ( V_5 -> V_54 ) ;
F_99 ( & V_5 -> V_19 ) ;
F_131 ( & V_14 -> V_165 ,
F_15 ( V_5 , V_9 ) ) ;
F_103 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_46 != V_47 ) {
struct V_1 * V_8 = F_1 ( V_5 -> V_1 ) ;
F_27 ( & V_8 -> V_166 ) ;
F_132 ( & V_14 -> V_167 ,
F_9 ( V_8 , V_9 ) ) ;
F_33 ( & V_8 -> V_166 ) ;
}
if ( V_14 -> V_9 != 0 )
F_5 ( & V_216 ) ;
}
return V_14 ;
}
static T_5 int F_133 ( struct V_2 * V_2 )
{
struct V_1 * V_8 = F_3 ( V_2 , V_3 ) ;
int V_21 ;
F_119 ( & V_8 -> V_213 ) ;
F_134 ( & V_8 -> V_169 ) ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ )
F_135 ( & V_8 -> V_10 [ V_21 ] ) ;
F_134 ( & V_8 -> V_166 ) ;
return 0 ;
}
static int T_6 F_136 ( void )
{
int V_224 = 0 ;
V_224 = F_137 ( & V_225 ) ;
if ( V_224 )
goto V_40;
F_60 ( V_79 L_36 , V_226 ) ;
V_40:
return V_224 ;
}
static void T_7 F_138 ( void )
{
F_139 ( & V_225 ) ;
}
