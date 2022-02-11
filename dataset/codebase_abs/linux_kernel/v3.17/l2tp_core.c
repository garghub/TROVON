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
static struct V_2 * F_9 ( struct V_1 * V_8 )
{
int V_10 = 0 ;
struct V_11 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
if ( ! V_8 )
goto V_12;
if ( V_8 -> V_13 >= 0 ) {
V_2 = F_10 ( V_8 -> V_13 , & V_10 ) ;
if ( V_2 )
V_3 = V_2 -> V_3 ;
} else {
V_3 = V_8 -> V_2 ;
F_11 ( V_3 ) ;
}
V_12:
return V_3 ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_13 ( V_3 ) ;
if ( V_8 ) {
if ( V_8 -> V_13 >= 0 ) {
F_14 ( V_3 -> V_14 ) ;
}
F_15 ( V_3 ) ;
}
F_15 ( V_3 ) ;
}
static struct V_15 * F_16 ( struct V_6 * V_6 , T_1 V_16 )
{
struct V_5 * V_17 = F_1 ( V_6 ) ;
struct V_18 * V_19 =
F_17 ( V_17 , V_16 ) ;
struct V_15 * V_20 ;
F_18 () ;
F_19 (session, session_list, global_hlist) {
if ( V_20 -> V_16 == V_16 ) {
F_20 () ;
return V_20 ;
}
}
F_20 () ;
return NULL ;
}
static inline struct V_18 *
F_21 ( struct V_1 * V_8 , T_1 V_16 )
{
return & V_8 -> V_21 [ F_22 ( V_16 , V_22 ) ] ;
}
struct V_15 * F_23 ( struct V_6 * V_6 , struct V_1 * V_8 , T_1 V_16 )
{
struct V_18 * V_19 ;
struct V_15 * V_20 ;
if ( V_8 == NULL )
return F_16 ( V_6 , V_16 ) ;
V_19 = F_21 ( V_8 , V_16 ) ;
F_24 ( & V_8 -> V_23 ) ;
F_25 (session, session_list, hlist) {
if ( V_20 -> V_16 == V_16 ) {
F_26 ( & V_8 -> V_23 ) ;
return V_20 ;
}
}
F_26 ( & V_8 -> V_23 ) ;
return NULL ;
}
struct V_15 * F_27 ( struct V_1 * V_8 , int V_24 )
{
int V_25 ;
struct V_15 * V_20 ;
int V_26 = 0 ;
F_24 ( & V_8 -> V_23 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
F_25 (session, &tunnel->session_hlist[hash], hlist) {
if ( ++ V_26 > V_24 ) {
F_26 ( & V_8 -> V_23 ) ;
return V_20 ;
}
}
}
F_26 ( & V_8 -> V_23 ) ;
return NULL ;
}
struct V_15 * F_28 ( struct V_6 * V_6 , char * V_28 )
{
struct V_5 * V_17 = F_1 ( V_6 ) ;
int V_25 ;
struct V_15 * V_20 ;
F_18 () ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
F_19 (session, &pn->l2tp_session_hlist[hash], global_hlist) {
if ( ! strcmp ( V_20 -> V_28 , V_28 ) ) {
F_20 () ;
return V_20 ;
}
}
}
F_20 () ;
return NULL ;
}
struct V_1 * F_29 ( struct V_6 * V_6 , T_1 V_30 )
{
struct V_1 * V_8 ;
struct V_5 * V_17 = F_1 ( V_6 ) ;
F_18 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( V_8 -> V_30 == V_30 ) {
F_20 () ;
return V_8 ;
}
}
F_20 () ;
return NULL ;
}
struct V_1 * F_31 ( struct V_6 * V_6 , int V_24 )
{
struct V_5 * V_17 = F_1 ( V_6 ) ;
struct V_1 * V_8 ;
int V_26 = 0 ;
F_18 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
if ( ++ V_26 > V_24 ) {
F_20 () ;
return V_8 ;
}
}
F_20 () ;
return NULL ;
}
static void F_32 ( struct V_15 * V_20 , struct V_31 * V_32 )
{
struct V_31 * V_33 ;
struct V_31 * V_34 ;
T_1 V_35 = F_33 ( V_32 ) -> V_35 ;
F_34 ( & V_20 -> V_36 . V_37 ) ;
F_35 (&session->reorder_q, skbp, tmp) {
if ( F_33 ( V_33 ) -> V_35 > V_35 ) {
F_36 ( & V_20 -> V_36 , V_33 , V_32 ) ;
F_37 ( V_20 , V_38 ,
L_1 ,
V_20 -> V_39 , V_35 , F_33 ( V_33 ) -> V_35 ,
F_38 ( & V_20 -> V_36 ) ) ;
F_39 ( & V_20 -> V_40 . V_41 ) ;
goto V_12;
}
}
F_40 ( & V_20 -> V_36 , V_32 ) ;
V_12:
F_41 ( & V_20 -> V_36 . V_37 ) ;
}
static void F_42 ( struct V_15 * V_20 , struct V_31 * V_32 )
{
struct V_1 * V_8 = V_20 -> V_8 ;
int V_42 = F_33 ( V_32 ) -> V_42 ;
F_43 ( V_32 ) ;
F_39 ( & V_8 -> V_40 . V_43 ) ;
F_44 ( V_42 , & V_8 -> V_40 . V_44 ) ;
F_39 ( & V_20 -> V_40 . V_43 ) ;
F_44 ( V_42 , & V_20 -> V_40 . V_44 ) ;
if ( F_33 ( V_32 ) -> V_45 ) {
V_20 -> V_46 ++ ;
V_20 -> V_46 &= V_20 -> V_47 ;
F_37 ( V_20 , V_38 , L_2 ,
V_20 -> V_39 , V_20 -> V_46 ) ;
}
if ( V_20 -> V_48 != NULL )
(* V_20 -> V_48 )( V_20 , V_32 , F_33 ( V_32 ) -> V_42 ) ;
else
F_45 ( V_32 ) ;
if ( V_20 -> V_49 )
(* V_20 -> V_49 )( V_20 ) ;
}
static void F_46 ( struct V_15 * V_20 )
{
struct V_31 * V_32 ;
struct V_31 * V_34 ;
V_50:
F_34 ( & V_20 -> V_36 . V_37 ) ;
F_35 (&session->reorder_q, skb, tmp) {
if ( F_47 ( V_51 , F_33 ( V_32 ) -> V_52 ) ) {
F_39 ( & V_20 -> V_40 . V_53 ) ;
F_39 ( & V_20 -> V_40 . V_54 ) ;
F_37 ( V_20 , V_38 ,
L_3 ,
V_20 -> V_39 , F_33 ( V_32 ) -> V_35 ,
F_33 ( V_32 ) -> V_42 , V_20 -> V_46 ,
F_38 ( & V_20 -> V_36 ) ) ;
V_20 -> V_55 = 1 ;
F_48 ( V_32 , & V_20 -> V_36 ) ;
F_45 ( V_32 ) ;
if ( V_20 -> V_49 )
(* V_20 -> V_49 )( V_20 ) ;
continue;
}
if ( F_33 ( V_32 ) -> V_45 ) {
if ( V_20 -> V_55 ) {
F_37 ( V_20 , V_38 ,
L_4 ,
V_20 -> V_39 , V_20 -> V_46 ,
F_33 ( V_32 ) -> V_35 ) ;
V_20 -> V_55 = 0 ;
V_20 -> V_46 = F_33 ( V_32 ) -> V_35 ;
}
if ( F_33 ( V_32 ) -> V_35 != V_20 -> V_46 ) {
F_37 ( V_20 , V_38 ,
L_5 ,
V_20 -> V_39 , F_33 ( V_32 ) -> V_35 ,
F_33 ( V_32 ) -> V_42 , V_20 -> V_46 ,
F_38 ( & V_20 -> V_36 ) ) ;
goto V_12;
}
}
F_48 ( V_32 , & V_20 -> V_36 ) ;
F_41 ( & V_20 -> V_36 . V_37 ) ;
F_42 ( V_20 , V_32 ) ;
goto V_50;
}
V_12:
F_41 ( & V_20 -> V_36 . V_37 ) ;
}
static int F_49 ( struct V_15 * V_20 , T_1 V_46 )
{
T_1 V_56 ;
if ( V_46 >= V_20 -> V_46 )
V_56 = V_46 - V_20 -> V_46 ;
else
V_56 = ( V_20 -> V_47 + 1 ) - ( V_20 -> V_46 - V_46 ) ;
return V_56 < V_20 -> V_57 ;
}
static int F_50 ( struct V_15 * V_20 , struct V_31 * V_32 )
{
if ( ! F_49 ( V_20 , F_33 ( V_32 ) -> V_35 ) ) {
F_37 ( V_20 , V_38 ,
L_6 ,
V_20 -> V_39 , F_33 ( V_32 ) -> V_35 ,
F_33 ( V_32 ) -> V_42 , V_20 -> V_46 ) ;
goto V_58;
}
if ( V_20 -> V_59 != 0 ) {
F_32 ( V_20 , V_32 ) ;
goto V_12;
}
if ( F_33 ( V_32 ) -> V_35 == V_20 -> V_46 ) {
F_51 ( & V_20 -> V_36 , V_32 ) ;
} else {
T_1 V_60 = F_33 ( V_32 ) -> V_35 ;
T_1 V_61 = ( V_20 -> V_60 + 1 ) & V_20 -> V_47 ;
if ( V_60 == V_61 )
V_20 -> V_62 ++ ;
else
V_20 -> V_62 = 0 ;
V_20 -> V_60 = V_60 ;
if ( V_20 -> V_62 > V_20 -> V_63 ) {
V_20 -> V_55 = 1 ;
F_37 ( V_20 , V_38 ,
L_7 ,
V_20 -> V_39 , V_20 -> V_62 ) ;
}
if ( ! V_20 -> V_55 ) {
F_39 ( & V_20 -> V_40 . V_53 ) ;
F_37 ( V_20 , V_38 ,
L_8 ,
V_20 -> V_39 , F_33 ( V_32 ) -> V_35 ,
F_33 ( V_32 ) -> V_42 , V_20 -> V_46 ,
F_38 ( & V_20 -> V_36 ) ) ;
goto V_58;
}
F_51 ( & V_20 -> V_36 , V_32 ) ;
}
V_12:
return 0 ;
V_58:
return 1 ;
}
void F_52 ( struct V_15 * V_20 , struct V_31 * V_32 ,
unsigned char * V_64 , unsigned char * V_65 , T_2 V_66 ,
int V_42 , int (* F_53)( struct V_31 * V_32 ) )
{
struct V_1 * V_8 = V_20 -> V_8 ;
int V_67 ;
T_1 V_35 , V_46 ;
F_54 ( V_20 ) ;
if ( V_20 -> V_68 )
(* V_20 -> V_68 )( V_20 ) ;
if ( V_20 -> V_69 > 0 ) {
if ( memcmp ( V_64 , & V_20 -> V_70 [ 0 ] , V_20 -> V_69 ) ) {
F_55 ( V_8 , V_71 ,
L_9 ,
V_8 -> V_39 , V_8 -> V_30 ,
V_20 -> V_16 ) ;
F_39 ( & V_20 -> V_40 . V_72 ) ;
goto V_58;
}
V_64 += V_20 -> V_69 ;
}
V_35 = V_46 = 0 ;
F_33 ( V_32 ) -> V_45 = 0 ;
if ( V_8 -> V_73 == V_74 ) {
if ( V_66 & V_75 ) {
V_35 = F_56 ( * ( V_76 * ) V_64 ) ;
V_64 += 2 ;
V_46 = F_56 ( * ( V_76 * ) V_64 ) ;
V_64 += 2 ;
F_33 ( V_32 ) -> V_35 = V_35 ;
F_33 ( V_32 ) -> V_45 = 1 ;
F_37 ( V_20 , V_38 ,
L_10 ,
V_20 -> V_39 , V_35 , V_46 , V_20 -> V_46 ) ;
}
} else if ( V_20 -> V_77 == V_78 ) {
T_1 V_79 = F_57 ( * ( V_80 * ) V_64 ) ;
if ( V_79 & 0x40000000 ) {
V_35 = V_79 & 0x00ffffff ;
F_33 ( V_32 ) -> V_35 = V_35 ;
F_33 ( V_32 ) -> V_45 = 1 ;
F_37 ( V_20 , V_38 ,
L_11 ,
V_20 -> V_39 , V_35 , V_20 -> V_46 ) ;
}
}
V_64 += V_20 -> V_81 ;
if ( F_33 ( V_32 ) -> V_45 ) {
if ( ( ! V_20 -> V_82 ) && ( ! V_20 -> V_83 ) ) {
F_55 ( V_20 , V_38 ,
L_12 ,
V_20 -> V_39 ) ;
V_20 -> V_83 = - 1 ;
F_58 ( V_20 , V_8 -> V_73 ) ;
}
} else {
if ( V_20 -> V_84 ) {
F_59 ( V_20 , V_38 ,
L_13 ,
V_20 -> V_39 ) ;
F_39 ( & V_20 -> V_40 . V_53 ) ;
goto V_58;
}
if ( ( ! V_20 -> V_82 ) && ( V_20 -> V_83 ) ) {
F_55 ( V_20 , V_38 ,
L_14 ,
V_20 -> V_39 ) ;
V_20 -> V_83 = 0 ;
F_58 ( V_20 , V_8 -> V_73 ) ;
} else if ( V_20 -> V_83 ) {
F_59 ( V_20 , V_38 ,
L_13 ,
V_20 -> V_39 ) ;
F_39 ( & V_20 -> V_40 . V_53 ) ;
goto V_58;
}
}
if ( V_8 -> V_73 == V_74 ) {
if ( V_66 & V_85 ) {
V_67 = F_56 ( * ( V_76 * ) V_64 ) ;
V_64 += 2 + V_67 ;
}
} else
V_64 += V_20 -> V_67 ;
V_67 = V_64 - V_65 ;
if ( ! F_60 ( V_32 , V_67 ) )
goto V_58;
F_61 ( V_32 , V_67 ) ;
if ( F_53 )
if ( (* F_53)( V_32 ) )
goto V_58;
F_33 ( V_32 ) -> V_42 = V_42 ;
F_33 ( V_32 ) -> V_52 = V_51 +
( V_20 -> V_59 ? V_20 -> V_59 : V_86 ) ;
if ( F_33 ( V_32 ) -> V_45 ) {
if ( F_50 ( V_20 , V_32 ) )
goto V_58;
} else {
F_51 ( & V_20 -> V_36 , V_32 ) ;
}
F_46 ( V_20 ) ;
F_62 ( V_20 ) ;
return;
V_58:
F_39 ( & V_20 -> V_40 . V_54 ) ;
F_45 ( V_32 ) ;
if ( V_20 -> V_49 )
(* V_20 -> V_49 )( V_20 ) ;
F_62 ( V_20 ) ;
}
int F_63 ( struct V_15 * V_20 )
{
struct V_31 * V_32 = NULL ;
F_2 ( ! V_20 ) ;
F_2 ( V_20 -> V_87 != V_88 ) ;
while ( ( V_32 = F_64 ( & V_20 -> V_36 ) ) ) {
F_39 ( & V_20 -> V_40 . V_54 ) ;
F_45 ( V_32 ) ;
if ( V_20 -> V_49 )
(* V_20 -> V_49 )( V_20 ) ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_8 , struct V_31 * V_32 ,
int (* F_53)( struct V_31 * V_32 ) )
{
struct V_15 * V_20 = NULL ;
unsigned char * V_64 , * V_65 ;
T_2 V_66 ;
T_1 V_30 , V_16 ;
T_2 V_73 ;
int V_42 ;
F_61 ( V_32 , sizeof( struct V_89 ) ) ;
if ( ! F_60 ( V_32 , V_90 ) ) {
F_55 ( V_8 , V_71 ,
L_15 ,
V_8 -> V_39 , V_32 -> V_91 ) ;
goto error;
}
if ( V_8 -> V_92 & V_71 ) {
V_42 = F_66 ( 32u , V_32 -> V_91 ) ;
if ( ! F_60 ( V_32 , V_42 ) )
goto error;
F_67 ( L_16 , V_8 -> V_39 ) ;
F_68 ( L_17 , V_93 , V_32 -> V_94 , V_42 ) ;
}
V_65 = V_64 = V_32 -> V_94 ;
V_66 = F_56 ( * ( V_76 * ) V_64 ) ;
V_73 = V_66 & V_95 ;
if ( V_73 != V_8 -> V_73 ) {
F_55 ( V_8 , V_71 ,
L_18 ,
V_8 -> V_39 , V_73 , V_8 -> V_73 ) ;
goto error;
}
V_42 = V_32 -> V_91 ;
if ( V_66 & V_96 ) {
F_37 ( V_8 , V_71 ,
L_19 ,
V_8 -> V_39 , V_42 ) ;
goto error;
}
V_64 += 2 ;
if ( V_8 -> V_73 == V_74 ) {
if ( V_66 & V_97 )
V_64 += 2 ;
V_30 = F_56 ( * ( V_76 * ) V_64 ) ;
V_64 += 2 ;
V_16 = F_56 ( * ( V_76 * ) V_64 ) ;
V_64 += 2 ;
} else {
V_64 += 2 ;
V_30 = V_8 -> V_30 ;
V_16 = F_57 ( * ( V_80 * ) V_64 ) ;
V_64 += 4 ;
}
V_20 = F_23 ( V_8 -> V_5 , V_8 , V_16 ) ;
if ( ! V_20 || ! V_20 -> V_48 ) {
F_55 ( V_8 , V_71 ,
L_20 ,
V_8 -> V_39 , V_30 , V_16 ) ;
goto error;
}
F_52 ( V_20 , V_32 , V_64 , V_65 , V_66 , V_42 , F_53 ) ;
return 0 ;
error:
F_69 ( V_32 , sizeof( struct V_89 ) ) ;
return 1 ;
}
int F_70 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
struct V_1 * V_8 ;
V_8 = F_13 ( V_3 ) ;
if ( V_8 == NULL )
goto V_98;
F_37 ( V_8 , V_71 , L_21 ,
V_8 -> V_39 , V_32 -> V_91 ) ;
if ( F_65 ( V_8 , V_32 , V_8 -> V_99 ) )
goto V_100;
F_15 ( V_3 ) ;
return 0 ;
V_100:
F_15 ( V_3 ) ;
V_98:
return 1 ;
}
static int F_71 ( struct V_15 * V_20 , void * V_101 )
{
struct V_1 * V_8 = V_20 -> V_8 ;
V_76 * V_102 = V_101 ;
V_76 * V_65 = V_101 ;
T_2 V_103 = V_74 ;
T_1 V_30 = V_8 -> V_104 ;
T_1 V_16 = V_20 -> V_105 ;
if ( V_20 -> V_83 )
V_103 |= V_75 ;
* V_102 ++ = F_72 ( V_103 ) ;
* V_102 ++ = F_72 ( V_30 ) ;
* V_102 ++ = F_72 ( V_16 ) ;
if ( V_20 -> V_83 ) {
* V_102 ++ = F_72 ( V_20 -> V_35 ) ;
* V_102 ++ = 0 ;
V_20 -> V_35 ++ ;
V_20 -> V_35 &= 0xffff ;
F_37 ( V_20 , V_38 , L_22 ,
V_20 -> V_39 , V_20 -> V_35 ) ;
}
return V_102 - V_65 ;
}
static int F_73 ( struct V_15 * V_20 , void * V_101 )
{
struct V_1 * V_8 = V_20 -> V_8 ;
char * V_102 = V_101 ;
char * V_65 = V_102 ;
if ( V_8 -> V_106 == V_107 ) {
T_2 V_103 = V_108 ;
* ( ( V_76 * ) V_102 ) = F_72 ( V_103 ) ;
V_102 += 2 ;
* ( ( V_76 * ) V_102 ) = 0 ;
V_102 += 2 ;
}
* ( ( V_80 * ) V_102 ) = F_74 ( V_20 -> V_105 ) ;
V_102 += 4 ;
if ( V_20 -> V_109 ) {
memcpy ( V_102 , & V_20 -> V_110 [ 0 ] , V_20 -> V_109 ) ;
V_102 += V_20 -> V_109 ;
}
if ( V_20 -> V_81 ) {
if ( V_20 -> V_77 == V_78 ) {
T_1 V_79 = 0 ;
if ( V_20 -> V_83 ) {
V_79 = 0x40000000 | V_20 -> V_35 ;
V_20 -> V_35 ++ ;
V_20 -> V_35 &= 0xffffff ;
F_37 ( V_20 , V_38 ,
L_22 ,
V_20 -> V_39 , V_20 -> V_35 ) ;
}
* ( ( V_80 * ) V_102 ) = F_74 ( V_79 ) ;
}
V_102 += V_20 -> V_81 ;
}
if ( V_20 -> V_67 )
V_102 += V_20 -> V_67 ;
return V_102 - V_65 ;
}
static int F_75 ( struct V_15 * V_20 , struct V_31 * V_32 ,
struct V_111 * V_112 , T_3 V_113 )
{
struct V_1 * V_8 = V_20 -> V_8 ;
unsigned int V_91 = V_32 -> V_91 ;
int error ;
if ( V_20 -> V_83 )
F_37 ( V_20 , V_71 , L_23 ,
V_20 -> V_39 , V_113 , V_20 -> V_35 - 1 ) ;
else
F_37 ( V_20 , V_71 , L_24 ,
V_20 -> V_39 , V_113 ) ;
if ( V_20 -> V_92 & V_71 ) {
int V_114 = ( V_8 -> V_106 == V_107 ) ? sizeof( struct V_89 ) : 0 ;
unsigned char * V_115 = V_32 -> V_94 + V_114 ;
F_67 ( L_25 , V_20 -> V_39 ) ;
F_68 ( L_17 , V_93 ,
V_115 , F_76 ( T_3 , 32 , V_91 - V_114 ) ) ;
}
V_32 -> V_116 = 1 ;
#if F_77 ( V_117 )
if ( V_8 -> V_2 -> V_118 == V_119 && ! V_8 -> V_120 )
error = F_78 ( V_8 -> V_2 , V_32 , NULL ) ;
else
#endif
error = F_79 ( V_8 -> V_2 , V_32 , V_112 ) ;
if ( error >= 0 ) {
F_39 ( & V_8 -> V_40 . V_121 ) ;
F_44 ( V_91 , & V_8 -> V_40 . V_122 ) ;
F_39 ( & V_20 -> V_40 . V_121 ) ;
F_44 ( V_91 , & V_20 -> V_40 . V_122 ) ;
} else {
F_39 ( & V_8 -> V_40 . V_123 ) ;
F_39 ( & V_20 -> V_40 . V_123 ) ;
}
return 0 ;
}
int F_80 ( struct V_15 * V_20 , struct V_31 * V_32 , int V_124 )
{
int V_113 = V_32 -> V_91 ;
struct V_1 * V_8 = V_20 -> V_8 ;
struct V_2 * V_3 = V_8 -> V_2 ;
struct V_111 * V_112 ;
struct V_89 * V_125 ;
struct V_126 * V_127 ;
int V_128 ;
int V_114 = ( V_8 -> V_106 == V_107 ) ? sizeof( struct V_89 ) : 0 ;
int V_129 ;
int V_130 = V_131 ;
V_128 = V_132 + sizeof( struct V_133 ) +
V_114 + V_124 ;
if ( F_81 ( V_32 , V_128 ) ) {
F_45 ( V_32 ) ;
return V_134 ;
}
V_20 -> V_135 ( V_20 , F_69 ( V_32 , V_124 ) ) ;
memset ( & ( F_82 ( V_32 ) -> V_136 ) , 0 , sizeof( F_82 ( V_32 ) -> V_136 ) ) ;
F_82 ( V_32 ) -> V_103 &= ~ ( V_137 | V_138 |
V_139 ) ;
F_83 ( V_32 ) ;
F_84 ( V_3 ) ;
if ( F_85 ( V_3 ) ) {
F_45 ( V_32 ) ;
V_130 = V_134 ;
goto V_140;
}
F_86 ( V_32 ) ;
F_87 ( V_32 , F_88 ( F_89 ( V_3 , 0 ) ) ) ;
V_127 = F_90 ( V_3 ) ;
V_112 = & V_127 -> V_141 . V_112 ;
switch ( V_8 -> V_106 ) {
case V_107 :
F_69 ( V_32 , sizeof( * V_125 ) ) ;
F_91 ( V_32 ) ;
V_125 = F_92 ( V_32 ) ;
V_125 -> V_142 = V_127 -> V_143 ;
V_125 -> V_144 = V_127 -> V_145 ;
V_129 = V_114 + V_124 + V_113 ;
V_125 -> V_91 = F_72 ( V_129 ) ;
#if F_77 ( V_117 )
if ( V_3 -> V_118 == V_119 && ! V_8 -> V_120 )
F_93 ( F_94 ( V_3 ) ,
V_32 , & F_95 ( V_3 ) -> V_146 ,
& V_3 -> V_147 , V_129 ) ;
else
#endif
F_96 ( V_3 -> V_148 , V_32 , V_127 -> V_149 ,
V_127 -> V_150 , V_129 ) ;
break;
case V_151 :
break;
}
F_75 ( V_20 , V_32 , V_112 , V_113 ) ;
V_140:
F_97 ( V_3 ) ;
return V_130 ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = V_1 ( V_3 ) ;
struct V_5 * V_17 ;
if ( V_8 == NULL )
goto V_152;
F_55 ( V_8 , V_153 , L_26 , V_8 -> V_39 ) ;
switch ( V_8 -> V_106 ) {
case V_107 :
( F_99 ( V_3 ) ) -> V_154 = 0 ;
( F_99 ( V_3 ) ) -> V_155 = NULL ;
( F_99 ( V_3 ) ) -> V_156 = NULL ;
break;
case V_151 :
break;
}
V_3 -> V_157 = V_8 -> V_158 ;
V_3 -> V_4 = NULL ;
V_8 -> V_2 = NULL ;
V_17 = F_1 ( V_8 -> V_5 ) ;
F_34 ( & V_17 -> V_159 ) ;
F_100 ( & V_8 -> V_160 ) ;
F_41 ( & V_17 -> V_159 ) ;
F_101 ( & V_161 ) ;
F_102 ( V_8 ) ;
F_103 ( V_8 ) ;
if ( V_3 -> V_157 )
(* V_3 -> V_157 )( V_3 ) ;
V_152:
return;
}
void F_102 ( struct V_1 * V_8 )
{
int V_25 ;
struct V_162 * V_163 ;
struct V_162 * V_34 ;
struct V_15 * V_20 ;
F_2 ( V_8 == NULL ) ;
F_55 ( V_8 , V_153 , L_27 ,
V_8 -> V_39 ) ;
F_104 ( & V_8 -> V_23 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
V_164:
F_105 (walk, tmp, &tunnel->session_hlist[hash]) {
V_20 = F_106 ( V_163 , struct V_15 , V_165 ) ;
F_55 ( V_20 , V_153 ,
L_28 , V_20 -> V_39 ) ;
F_107 ( & V_20 -> V_165 ) ;
if ( V_20 -> V_68 != NULL )
(* V_20 -> V_68 )( V_20 ) ;
F_108 ( & V_8 -> V_23 ) ;
F_109 ( V_20 ) ;
F_63 ( V_20 ) ;
if ( V_20 -> V_166 != NULL )
(* V_20 -> V_166 )( V_20 ) ;
if ( V_20 -> V_49 != NULL )
(* V_20 -> V_49 )( V_20 ) ;
F_62 ( V_20 ) ;
F_104 ( & V_8 -> V_23 ) ;
goto V_164;
}
}
F_108 ( & V_8 -> V_23 ) ;
}
static void F_110 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_13 ( V_3 ) ;
if ( V_8 ) {
F_102 ( V_8 ) ;
F_15 ( V_3 ) ;
}
}
static void F_8 ( struct V_1 * V_8 )
{
F_2 ( F_111 ( & V_8 -> V_9 ) != 0 ) ;
F_2 ( V_8 -> V_2 != NULL ) ;
F_55 ( V_8 , V_153 , L_29 , V_8 -> V_39 ) ;
F_112 ( V_8 , V_167 ) ;
}
static void F_113 ( struct V_168 * V_169 )
{
struct V_1 * V_8 = NULL ;
struct V_11 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
V_8 = F_114 ( V_169 , struct V_1 , V_170 ) ;
V_3 = F_9 ( V_8 ) ;
if ( ! V_3 )
return;
V_2 = V_3 -> V_14 ;
if ( V_8 -> V_13 >= 0 ) {
if ( V_2 )
F_115 ( V_2 , 2 ) ;
} else {
if ( V_2 )
F_116 ( V_2 , V_171 ) ;
F_117 ( V_3 ) ;
}
F_12 ( V_3 ) ;
}
static int F_118 ( struct V_6 * V_6 ,
T_1 V_30 ,
T_1 V_104 ,
struct V_172 * V_173 ,
struct V_11 * * V_174 )
{
int V_10 = - V_175 ;
struct V_11 * V_2 = NULL ;
struct V_176 V_177 ;
switch ( V_173 -> V_106 ) {
case V_107 :
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
#if F_77 ( V_117 )
if ( V_173 -> V_178 && V_173 -> V_179 ) {
V_177 . V_180 = V_181 ;
memcpy ( & V_177 . V_178 , V_173 -> V_178 ,
sizeof( V_177 . V_178 ) ) ;
memcpy ( & V_177 . V_179 , V_173 -> V_179 ,
sizeof( V_177 . V_179 ) ) ;
V_177 . V_182 =
V_173 -> V_183 ;
V_177 . V_184 =
V_173 -> V_185 ;
} else
#endif
{
V_177 . V_180 = V_186 ;
V_177 . V_187 = V_173 -> V_187 ;
V_177 . V_188 = V_173 -> V_188 ;
V_177 . V_189 = V_173 -> V_189 ;
}
V_177 . V_190 = F_72 ( V_173 -> V_190 ) ;
V_177 . V_191 = F_72 ( V_173 -> V_191 ) ;
V_10 = F_119 ( V_6 , & V_177 , & V_2 ) ;
if ( V_10 < 0 )
goto V_12;
break;
case V_151 :
#if F_77 ( V_117 )
if ( V_173 -> V_178 && V_173 -> V_179 ) {
struct V_192 V_193 = { 0 } ;
V_10 = F_120 ( V_181 , V_194 ,
V_195 , & V_2 ) ;
if ( V_10 < 0 )
goto V_12;
F_121 ( V_2 -> V_3 , V_6 ) ;
V_193 . V_196 = V_181 ;
memcpy ( & V_193 . V_197 , V_173 -> V_178 ,
sizeof( V_193 . V_197 ) ) ;
V_193 . V_198 = V_30 ;
V_10 = F_122 ( V_2 , (struct V_199 * ) & V_193 ,
sizeof( V_193 ) ) ;
if ( V_10 < 0 )
goto V_12;
V_193 . V_196 = V_181 ;
memcpy ( & V_193 . V_197 , V_173 -> V_179 ,
sizeof( V_193 . V_197 ) ) ;
V_193 . V_198 = V_104 ;
V_10 = F_123 ( V_2 ,
(struct V_199 * ) & V_193 ,
sizeof( V_193 ) , 0 ) ;
if ( V_10 < 0 )
goto V_12;
} else
#endif
{
struct V_200 V_201 = { 0 } ;
V_10 = F_120 ( V_186 , V_194 ,
V_195 , & V_2 ) ;
if ( V_10 < 0 )
goto V_12;
F_121 ( V_2 -> V_3 , V_6 ) ;
V_201 . V_196 = V_186 ;
V_201 . V_197 = V_173 -> V_187 ;
V_201 . V_198 = V_30 ;
V_10 = F_122 ( V_2 , (struct V_199 * ) & V_201 ,
sizeof( V_201 ) ) ;
if ( V_10 < 0 )
goto V_12;
V_201 . V_196 = V_186 ;
V_201 . V_197 = V_173 -> V_188 ;
V_201 . V_198 = V_104 ;
V_10 = F_123 ( V_2 , (struct V_199 * ) & V_201 ,
sizeof( V_201 ) , 0 ) ;
if ( V_10 < 0 )
goto V_12;
}
break;
default:
goto V_12;
}
V_12:
* V_174 = V_2 ;
if ( ( V_10 < 0 ) && V_2 ) {
F_116 ( V_2 , V_171 ) ;
F_117 ( V_2 -> V_3 ) ;
* V_174 = NULL ;
}
return V_10 ;
}
int F_124 ( struct V_6 * V_6 , int V_13 , int V_73 , T_1 V_30 , T_1 V_104 , struct V_172 * V_173 , struct V_1 * * V_202 )
{
struct V_1 * V_8 = NULL ;
int V_10 ;
struct V_11 * V_2 = NULL ;
struct V_2 * V_3 = NULL ;
struct V_5 * V_17 ;
enum V_203 V_106 = V_107 ;
if ( V_13 < 0 ) {
V_10 = F_118 ( V_6 , V_30 , V_104 ,
V_173 , & V_2 ) ;
if ( V_10 < 0 )
goto V_10;
} else {
V_2 = F_10 ( V_13 , & V_10 ) ;
if ( ! V_2 ) {
F_125 ( L_30 ,
V_30 , V_13 , V_10 ) ;
V_10 = - V_204 ;
goto V_10;
}
if ( ! F_126 ( F_127 ( V_2 -> V_3 ) , V_6 ) ) {
F_125 ( L_31 , V_30 ) ;
V_10 = - V_175 ;
goto V_10;
}
}
V_3 = V_2 -> V_3 ;
if ( V_173 != NULL )
V_106 = V_173 -> V_106 ;
switch ( V_106 ) {
case V_107 :
V_10 = - V_205 ;
if ( V_3 -> V_206 != V_207 ) {
F_125 ( L_32 ,
V_30 , V_13 , V_3 -> V_206 , V_207 ) ;
goto V_10;
}
break;
case V_151 :
V_10 = - V_205 ;
if ( V_3 -> V_206 != V_195 ) {
F_125 ( L_32 ,
V_30 , V_13 , V_3 -> V_206 , V_195 ) ;
goto V_10;
}
break;
}
V_8 = V_1 ( V_3 ) ;
if ( V_8 != NULL ) {
V_10 = - V_208 ;
goto V_10;
}
V_8 = F_128 ( sizeof( struct V_1 ) , V_209 ) ;
if ( V_8 == NULL ) {
V_10 = - V_210 ;
goto V_10;
}
V_8 -> V_73 = V_73 ;
V_8 -> V_30 = V_30 ;
V_8 -> V_104 = V_104 ;
V_8 -> V_92 = V_211 ;
V_8 -> V_87 = V_212 ;
sprintf ( & V_8 -> V_39 [ 0 ] , L_33 , V_30 ) ;
F_129 ( & V_8 -> V_23 ) ;
V_8 -> V_5 = V_6 ;
V_17 = F_1 ( V_6 ) ;
if ( V_173 != NULL )
V_8 -> V_92 = V_173 -> V_92 ;
#if F_77 ( V_117 )
if ( V_3 -> V_118 == V_119 ) {
struct V_213 * V_214 = F_95 ( V_3 ) ;
if ( F_130 ( & V_214 -> V_146 ) &&
F_130 ( & V_3 -> V_147 ) ) {
struct V_126 * V_127 = F_90 ( V_3 ) ;
V_8 -> V_120 = true ;
V_127 -> V_149 = V_214 -> V_146 . V_215 [ 3 ] ;
V_127 -> V_216 = V_3 -> V_217 . V_215 [ 3 ] ;
V_127 -> V_150 = V_3 -> V_147 . V_215 [ 3 ] ;
} else {
V_8 -> V_120 = false ;
}
}
#endif
V_8 -> V_106 = V_106 ;
if ( V_106 == V_107 ) {
F_99 ( V_3 ) -> V_154 = V_218 ;
F_99 ( V_3 ) -> V_155 = F_70 ;
F_99 ( V_3 ) -> V_156 = F_110 ;
#if F_77 ( V_117 )
if ( V_3 -> V_118 == V_119 && ! V_8 -> V_120 )
F_131 () ;
else
#endif
F_132 () ;
}
V_3 -> V_4 = V_8 ;
V_8 -> V_158 = V_3 -> V_157 ;
V_3 -> V_157 = & F_98 ;
V_8 -> V_2 = V_3 ;
V_8 -> V_13 = V_13 ;
F_133 ( & V_3 -> V_219 . V_220 , & V_221 , L_34 ) ;
V_3 -> V_222 = V_223 ;
F_134 ( & V_8 -> V_170 , F_113 ) ;
F_135 ( & V_8 -> V_160 ) ;
F_5 ( & V_161 ) ;
F_136 ( V_8 ) ;
F_34 ( & V_17 -> V_159 ) ;
F_137 ( & V_8 -> V_160 , & V_17 -> V_224 ) ;
F_41 ( & V_17 -> V_159 ) ;
V_10 = 0 ;
V_10:
if ( V_202 )
* V_202 = V_8 ;
if ( V_2 && V_2 -> V_225 )
F_14 ( V_2 ) ;
return V_10 ;
}
int F_138 ( struct V_1 * V_8 )
{
F_102 ( V_8 ) ;
return ( false == F_139 ( V_226 , & V_8 -> V_170 ) ) ;
}
void F_140 ( struct V_15 * V_20 )
{
struct V_1 * V_8 = V_20 -> V_8 ;
F_2 ( F_111 ( & V_20 -> V_9 ) != 0 ) ;
if ( V_8 ) {
F_2 ( V_8 -> V_87 != V_212 ) ;
if ( V_20 -> V_16 != 0 )
F_101 ( & V_227 ) ;
F_15 ( V_8 -> V_2 ) ;
V_20 -> V_8 = NULL ;
F_103 ( V_8 ) ;
}
F_141 ( V_20 ) ;
}
void F_109 ( struct V_15 * V_20 )
{
struct V_1 * V_8 = V_20 -> V_8 ;
if ( V_8 ) {
F_104 ( & V_8 -> V_23 ) ;
F_107 ( & V_20 -> V_165 ) ;
F_108 ( & V_8 -> V_23 ) ;
if ( V_8 -> V_73 != V_74 ) {
struct V_5 * V_17 = F_1 ( V_8 -> V_5 ) ;
F_34 ( & V_17 -> V_228 ) ;
F_142 ( & V_20 -> V_229 ) ;
F_41 ( & V_17 -> V_228 ) ;
F_143 () ;
}
}
}
int F_144 ( struct V_15 * V_20 )
{
if ( V_20 -> V_68 )
(* V_20 -> V_68 )( V_20 ) ;
F_109 ( V_20 ) ;
F_63 ( V_20 ) ;
if ( V_20 -> V_166 != NULL )
(* V_20 -> V_166 )( V_20 ) ;
if ( V_20 -> V_49 )
(* V_20 -> V_49 )( V_20 ) ;
F_62 ( V_20 ) ;
return 0 ;
}
void F_58 ( struct V_15 * V_20 , int V_73 )
{
if ( V_73 == V_74 ) {
V_20 -> V_124 = 6 ;
if ( V_20 -> V_83 )
V_20 -> V_124 += 4 ;
} else {
V_20 -> V_124 = 4 + V_20 -> V_109 + V_20 -> V_81 + V_20 -> V_67 ;
if ( V_20 -> V_8 -> V_106 == V_107 )
V_20 -> V_124 += 4 ;
}
}
struct V_15 * F_145 ( int V_230 , struct V_1 * V_8 , T_1 V_16 , T_1 V_105 , struct V_231 * V_173 )
{
struct V_15 * V_20 ;
V_20 = F_128 ( sizeof( struct V_15 ) + V_230 , V_209 ) ;
if ( V_20 != NULL ) {
V_20 -> V_87 = V_88 ;
V_20 -> V_8 = V_8 ;
V_20 -> V_16 = V_16 ;
V_20 -> V_105 = V_105 ;
V_20 -> V_46 = 0 ;
if ( V_8 -> V_73 == V_74 )
V_20 -> V_47 = 0xffff ;
else
V_20 -> V_47 = 0xffffff ;
V_20 -> V_57 = V_20 -> V_47 / 2 ;
V_20 -> V_63 = 4 ;
V_20 -> V_55 = 1 ;
sprintf ( & V_20 -> V_39 [ 0 ] , L_35 ,
V_8 -> V_30 , V_20 -> V_16 ) ;
F_146 ( & V_20 -> V_36 ) ;
F_147 ( & V_20 -> V_165 ) ;
F_147 ( & V_20 -> V_229 ) ;
V_20 -> V_92 = V_8 -> V_92 ;
if ( V_173 ) {
V_20 -> V_232 = V_173 -> V_233 ;
V_20 -> V_92 = V_173 -> V_92 ;
V_20 -> V_234 = V_173 -> V_234 ;
V_20 -> V_235 = V_173 -> V_235 ;
V_20 -> V_83 = V_173 -> V_83 ;
V_20 -> V_84 = V_173 -> V_84 ;
V_20 -> V_82 = V_173 -> V_82 ;
V_20 -> V_59 = V_173 -> V_59 ;
V_20 -> V_67 = V_173 -> V_67 ;
V_20 -> V_77 = V_173 -> V_77 ;
V_20 -> V_81 = V_173 -> V_81 ;
V_20 -> V_109 = V_173 -> V_109 ;
memcpy ( & V_20 -> V_110 [ 0 ] , & V_173 -> V_110 [ 0 ] , V_173 -> V_109 ) ;
V_20 -> V_69 = V_173 -> V_69 ;
memcpy ( & V_20 -> V_70 [ 0 ] , & V_173 -> V_70 [ 0 ] , V_173 -> V_69 ) ;
}
if ( V_8 -> V_73 == V_74 )
V_20 -> V_135 = F_71 ;
else
V_20 -> V_135 = F_73 ;
F_58 ( V_20 , V_8 -> V_73 ) ;
F_54 ( V_20 ) ;
F_136 ( V_8 ) ;
F_11 ( V_8 -> V_2 ) ;
F_104 ( & V_8 -> V_23 ) ;
F_148 ( & V_20 -> V_165 ,
F_21 ( V_8 , V_16 ) ) ;
F_108 ( & V_8 -> V_23 ) ;
if ( V_8 -> V_73 != V_74 ) {
struct V_5 * V_17 = F_1 ( V_8 -> V_5 ) ;
F_34 ( & V_17 -> V_228 ) ;
F_149 ( & V_20 -> V_229 ,
F_17 ( V_17 , V_16 ) ) ;
F_41 ( & V_17 -> V_228 ) ;
}
if ( V_20 -> V_16 != 0 )
F_5 ( & V_227 ) ;
}
return V_20 ;
}
static T_4 int F_150 ( struct V_6 * V_6 )
{
struct V_5 * V_17 = F_3 ( V_6 , V_7 ) ;
int V_25 ;
F_135 ( & V_17 -> V_224 ) ;
F_151 ( & V_17 -> V_159 ) ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ )
F_152 ( & V_17 -> V_236 [ V_25 ] ) ;
F_151 ( & V_17 -> V_228 ) ;
return 0 ;
}
static T_5 void F_153 ( struct V_6 * V_6 )
{
struct V_5 * V_17 = F_1 ( V_6 ) ;
struct V_1 * V_8 = NULL ;
F_18 () ;
F_30 (tunnel, &pn->l2tp_tunnel_list, list) {
( void ) F_138 ( V_8 ) ;
}
F_20 () ;
}
static int T_6 F_154 ( void )
{
int V_237 = 0 ;
V_237 = F_155 ( & V_238 ) ;
if ( V_237 )
goto V_12;
V_226 = F_156 ( L_36 , V_239 , 0 ) ;
if ( ! V_226 ) {
F_125 ( L_37 ) ;
V_237 = - V_210 ;
goto V_12;
}
F_157 ( L_38 , V_240 ) ;
V_12:
return V_237 ;
}
static void T_7 F_158 ( void )
{
F_159 ( & V_238 ) ;
if ( V_226 ) {
F_160 ( V_226 ) ;
V_226 = NULL ;
}
}
