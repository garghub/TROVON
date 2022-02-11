static inline int F_1 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
return ( V_1 ^ ( V_2 << 2 ) ^ ( V_3 << 4 ) ) & ( V_4 - 1 ) ;
}
static void F_2 ( struct V_5 * V_6 , T_2 V_3 , T_1 V_7 )
{
const char * * V_8 ;
int V_9 , V_10 ;
if ( V_7 == 0 ) {
F_3 ( V_6 , L_1 ) ;
return;
}
F_4 ( ! V_3 || V_3 >= F_5 ( V_11 ) ) ;
V_8 = V_11 [ V_3 - 1 ] . V_8 ;
F_3 ( V_6 , L_2 ) ;
V_9 = 0 ;
V_10 = 1 ;
while ( V_9 < ( sizeof( V_7 ) * 8 ) ) {
if ( ( V_10 & V_7 ) && V_8 [ V_9 ] ) {
F_3 ( V_6 , L_3 , V_8 [ V_9 ] ) ;
V_7 &= ~ V_10 ;
}
V_9 ++ ;
V_10 <<= 1 ;
}
if ( V_7 )
F_3 ( V_6 , L_4 , V_7 ) ;
F_3 ( V_6 , L_5 ) ;
}
static void F_6 ( struct V_5 * V_6 , T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
int V_12 ;
char * V_13 ;
T_1 V_14 ;
V_12 = F_7 ( V_1 , & V_13 , & V_14 ) ;
if ( V_12 )
F_3 ( V_6 , L_6 , V_1 ) ;
else {
F_3 ( V_6 , L_7 , V_13 ) ;
F_8 ( V_13 ) ;
}
V_12 = F_7 ( V_2 , & V_13 , & V_14 ) ;
if ( V_12 )
F_3 ( V_6 , L_8 , V_2 ) ;
else {
F_3 ( V_6 , L_9 , V_13 ) ;
F_8 ( V_13 ) ;
}
F_4 ( ! V_3 || V_3 >= F_5 ( V_11 ) ) ;
F_3 ( V_6 , L_10 , V_11 [ V_3 - 1 ] . V_15 ) ;
}
void T_3 F_9 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
F_10 ( & V_16 . V_17 [ V_9 ] ) ;
F_11 ( & V_16 . V_18 [ V_9 ] ) ;
}
F_12 ( & V_16 . V_19 , 0 ) ;
F_12 ( & V_16 . V_20 , 0 ) ;
V_21 = F_13 ( L_11 , sizeof( struct V_22 ) ,
0 , V_23 , NULL ) ;
V_24 = F_13 ( L_12 ,
sizeof( struct V_25 ) ,
0 , V_23 , NULL ) ;
V_26 = F_13 (
L_13 ,
sizeof( struct V_27 ) ,
0 , V_23 , NULL ) ;
V_28 = F_13 ( L_14 ,
sizeof( struct V_29 ) ,
0 , V_23 , NULL ) ;
}
int F_14 ( char * V_30 )
{
int V_9 , V_31 , V_32 , V_33 ;
struct V_22 * V_34 ;
struct V_35 * V_36 ;
F_15 () ;
V_33 = 0 ;
V_32 = 0 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
V_36 = & V_16 . V_17 [ V_9 ] ;
if ( ! F_16 ( V_36 ) ) {
V_33 ++ ;
V_31 = 0 ;
F_17 (node, head, list)
V_31 ++ ;
if ( V_31 > V_32 )
V_32 = V_31 ;
}
}
F_18 () ;
return F_19 ( V_30 , V_37 , L_15
L_16 ,
F_20 ( & V_16 . V_19 ) ,
V_33 , V_4 , V_32 ) ;
}
static struct V_38 * F_21 ( T_4 V_39 ,
struct V_25 * V_40 )
{
struct V_27 * V_41 ;
F_22 (xpd_node, &xp_node->xpd_head, xpd_list) {
if ( V_41 -> V_42 . V_39 == V_39 )
return & V_41 -> V_42 ;
}
return NULL ;
}
static inline unsigned int
F_23 ( struct V_38 * V_42 ,
T_4 V_10 , T_4 V_43 )
{
unsigned int V_12 = 0 ;
if ( ( V_43 == V_44 ) &&
( V_42 -> V_45 & V_44 ) )
V_12 = F_24 ( V_42 -> V_46 -> V_47 , V_10 ) ;
else if ( ( V_43 == V_48 ) &&
( V_42 -> V_45 & V_48 ) )
V_12 = F_24 ( V_42 -> V_49 -> V_47 , V_10 ) ;
else if ( ( V_43 == V_50 ) &&
( V_42 -> V_45 & V_50 ) )
V_12 = F_24 ( V_42 -> V_51 -> V_47 , V_10 ) ;
return V_12 ;
}
static void F_25 ( struct V_25 * V_40 ,
T_4 V_39 , T_4 V_10 )
{
struct V_38 * V_42 ;
F_26 ( V_40 -> V_52 . V_53 . V_47 , V_39 ) ;
V_42 = F_21 ( V_39 , V_40 ) ;
if ( V_42 && V_42 -> V_46 )
F_26 ( V_42 -> V_46 -> V_47 , V_10 ) ;
}
static void F_27 ( struct V_27 * V_41 )
{
struct V_38 * V_42 ;
V_42 = & V_41 -> V_42 ;
if ( V_42 -> V_46 )
F_28 ( V_28 , V_42 -> V_46 ) ;
if ( V_42 -> V_49 )
F_28 ( V_28 , V_42 -> V_49 ) ;
if ( V_42 -> V_51 )
F_28 ( V_28 , V_42 -> V_51 ) ;
F_28 ( V_26 , V_41 ) ;
}
static void F_29 ( struct V_25 * V_40 )
{
struct V_27 * V_41 , * V_54 ;
if ( ! V_40 )
return;
F_30 (xpd_node, tmp, &xp_node->xpd_head, xpd_list) {
F_31 ( & V_41 -> V_55 ) ;
F_27 ( V_41 ) ;
}
F_28 ( V_24 , V_40 ) ;
}
static void F_32 ( struct V_38 * V_56 ,
struct V_38 * V_57 )
{
V_56 -> V_39 = V_57 -> V_39 ;
V_56 -> V_45 = V_57 -> V_45 ;
if ( V_56 -> V_45 & V_44 )
memcpy ( V_56 -> V_46 -> V_47 , V_57 -> V_46 -> V_47 ,
sizeof( V_57 -> V_46 -> V_47 ) ) ;
if ( V_56 -> V_45 & V_48 )
memcpy ( V_56 -> V_49 -> V_47 , V_57 -> V_49 -> V_47 ,
sizeof( V_57 -> V_49 -> V_47 ) ) ;
if ( V_56 -> V_45 & V_50 )
memcpy ( V_56 -> V_51 -> V_47 , V_57 -> V_51 -> V_47 ,
sizeof( V_57 -> V_51 -> V_47 ) ) ;
}
static inline void F_33 ( T_4 V_10 ,
struct V_38 * V_56 ,
struct V_38 * V_57 )
{
T_4 V_9 = V_10 >> 5 ;
V_56 -> V_45 = V_57 -> V_45 ;
if ( V_56 -> V_45 & V_44 )
V_56 -> V_46 -> V_47 [ V_9 ] = V_57 -> V_46 -> V_47 [ V_9 ] ;
if ( V_56 -> V_45 & V_48 )
V_56 -> V_49 -> V_47 [ V_9 ] = V_57 -> V_49 -> V_47 [ V_9 ] ;
if ( V_56 -> V_45 & V_50 )
V_56 -> V_51 -> V_47 [ V_9 ] = V_57 -> V_51 -> V_47 [ V_9 ] ;
}
static struct V_27
* F_34 ( T_4 V_43 )
{
struct V_27 * V_41 ;
struct V_38 * V_42 ;
V_41 = F_35 ( V_26 , V_58 ) ;
if ( ! V_41 )
return NULL ;
V_42 = & V_41 -> V_42 ;
if ( V_43 & V_44 ) {
V_42 -> V_46 = F_35 ( V_28 ,
V_58 ) ;
if ( ! V_42 -> V_46 )
goto error;
}
if ( V_43 & V_48 ) {
V_42 -> V_49 = F_35 ( V_28 ,
V_58 ) ;
if ( ! V_42 -> V_49 )
goto error;
}
if ( V_43 & V_50 ) {
V_42 -> V_51 = F_35 ( V_28 ,
V_58 ) ;
if ( ! V_42 -> V_51 )
goto error;
}
return V_41 ;
error:
F_27 ( V_41 ) ;
return NULL ;
}
static int F_36 ( struct V_22 * V_34 ,
struct V_38 * V_57 )
{
struct V_27 * V_59 ;
V_34 -> V_60 . V_40 -> V_52 . V_61 ++ ;
V_59 = F_34 ( V_57 -> V_45 ) ;
if ( ! V_59 )
return - V_62 ;
F_32 ( & V_59 -> V_42 , V_57 ) ;
F_37 ( & V_59 -> V_55 , & V_34 -> V_60 . V_40 -> V_63 ) ;
return 0 ;
}
static struct V_25 * F_38 ( void )
{
struct V_25 * V_40 ;
V_40 = F_35 ( V_24 , V_58 ) ;
if ( ! V_40 )
return V_40 ;
F_39 ( & V_40 -> V_63 ) ;
return V_40 ;
}
static int F_40 ( struct V_22 * V_34 ,
struct V_25 * V_57 )
{
struct V_25 * V_56 ;
struct V_27 * V_59 ;
struct V_27 * V_64 ;
if ( V_57 -> V_52 . V_61 == 0 )
return 0 ;
V_56 = F_38 () ;
if ( ! V_56 )
return - V_62 ;
memcpy ( V_56 -> V_52 . V_53 . V_47 , V_57 -> V_52 . V_53 . V_47 , sizeof( V_56 -> V_52 . V_53 . V_47 ) ) ;
V_56 -> V_52 . V_61 = V_57 -> V_52 . V_61 ;
F_22 (src_xpd, &src->xpd_head, xpd_list) {
V_59 = F_34 ( V_64 -> V_42 . V_45 ) ;
if ( ! V_59 )
goto error;
F_32 ( & V_59 -> V_42 , & V_64 -> V_42 ) ;
F_37 ( & V_59 -> V_55 , & V_56 -> V_63 ) ;
}
V_34 -> V_60 . V_40 = V_56 ;
return 0 ;
error:
F_29 ( V_56 ) ;
return - V_62 ;
}
static inline T_1 F_41 ( T_1 V_65 ,
struct V_66 * V_67 ,
struct V_38 * V_42 ,
T_4 V_10 ,
int V_68 ,
T_1 * V_69 )
{
T_1 V_70 , V_71 ;
V_70 = V_65 & ~ V_67 -> V_46 ;
if ( F_42 ( V_70 ) ) {
V_71 = V_70 & V_67 -> V_72 ;
if ( V_71 && V_42 ) {
if ( F_23 ( V_42 , V_10 , V_50 ) )
V_71 &= ~ V_65 ;
}
} else if ( V_68 ) {
V_71 = V_70 = V_65 ;
} else {
V_71 = V_65 & V_67 -> V_49 ;
if ( V_71 && V_42 ) {
if ( ! F_23 ( V_42 , V_10 , V_48 ) )
V_71 &= ~ V_65 ;
}
}
* V_69 = V_70 ;
return V_71 ;
}
static inline int F_43 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_65 , struct V_66 * V_67 ,
struct V_38 * V_42 ,
T_4 V_10 , int V_68 ,
struct V_73 * V_74 )
{
T_1 V_71 , V_70 ;
V_71 = F_41 (
V_65 , V_67 , V_42 , V_10 , V_68 , & V_70 ) ;
if ( F_44 ( ! V_71 ) )
return 0 ;
return F_45 ( V_1 , V_2 , V_3 , V_65 ,
V_71 , V_70 , V_68 , V_74 , 0 ) ;
}
static void F_46 ( struct V_75 * V_76 )
{
struct V_22 * V_34 = F_47 ( V_76 , struct V_22 , V_76 ) ;
F_29 ( V_34 -> V_60 . V_40 ) ;
F_28 ( V_21 , V_34 ) ;
F_48 ( V_77 ) ;
}
static void F_49 ( struct V_22 * V_34 )
{
F_50 ( & V_34 -> V_78 ) ;
F_51 ( & V_34 -> V_76 , F_46 ) ;
F_52 ( & V_16 . V_19 ) ;
}
static void F_53 ( struct V_22 * V_34 )
{
F_29 ( V_34 -> V_60 . V_40 ) ;
F_28 ( V_21 , V_34 ) ;
F_48 ( V_77 ) ;
F_52 ( & V_16 . V_19 ) ;
}
static void F_54 ( struct V_22 * V_79 , struct V_22 * V_80 )
{
F_55 ( & V_80 -> V_78 , & V_79 -> V_78 ) ;
F_51 ( & V_80 -> V_76 , F_46 ) ;
F_52 ( & V_16 . V_19 ) ;
}
static inline int F_56 ( void )
{
struct V_22 * V_34 ;
int V_81 , V_82 , V_83 ;
unsigned long V_84 ;
struct V_35 * V_36 ;
T_5 * V_85 ;
for ( V_82 = 0 , V_83 = 0 ; V_82 < V_4 ; V_82 ++ ) {
V_81 = F_57 ( & V_16 . V_20 ) & ( V_4 - 1 ) ;
V_36 = & V_16 . V_17 [ V_81 ] ;
V_85 = & V_16 . V_18 [ V_81 ] ;
if ( ! F_58 ( V_85 , V_84 ) )
continue;
F_15 () ;
F_59 (node, head, list) {
F_49 ( V_34 ) ;
F_48 ( V_86 ) ;
V_83 ++ ;
if ( V_83 >= V_87 ) {
F_18 () ;
F_60 ( V_85 , V_84 ) ;
goto V_88;
}
}
F_18 () ;
F_60 ( V_85 , V_84 ) ;
}
V_88:
return V_83 ;
}
static struct V_22 * F_61 ( void )
{
struct V_22 * V_34 ;
V_34 = F_35 ( V_21 , V_58 ) ;
if ( ! V_34 )
goto V_88;
F_62 ( & V_34 -> V_78 ) ;
F_48 ( V_89 ) ;
if ( F_57 ( & V_16 . V_19 ) > V_90 )
F_56 () ;
V_88:
return V_34 ;
}
static void F_63 ( struct V_22 * V_34 , T_1 V_1 , T_1 V_2 , T_2 V_3 , struct V_66 * V_67 )
{
V_34 -> V_60 . V_1 = V_1 ;
V_34 -> V_60 . V_2 = V_2 ;
V_34 -> V_60 . V_3 = V_3 ;
memcpy ( & V_34 -> V_60 . V_67 , V_67 , sizeof( V_34 -> V_60 . V_67 ) ) ;
}
static inline struct V_22 * F_64 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_22 * V_34 , * V_91 = NULL ;
int V_81 ;
struct V_35 * V_36 ;
V_81 = F_1 ( V_1 , V_2 , V_3 ) ;
V_36 = & V_16 . V_17 [ V_81 ] ;
F_17 (node, head, list) {
if ( V_1 == V_34 -> V_60 . V_1 &&
V_3 == V_34 -> V_60 . V_3 &&
V_2 == V_34 -> V_60 . V_2 ) {
V_91 = V_34 ;
break;
}
}
return V_91 ;
}
static struct V_22 * F_65 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_22 * V_34 ;
F_48 ( V_92 ) ;
V_34 = F_64 ( V_1 , V_2 , V_3 ) ;
if ( V_34 )
return V_34 ;
F_48 ( V_93 ) ;
return NULL ;
}
static int F_66 ( int V_94 , int V_95 )
{
int V_91 = 0 ;
static F_67 ( V_96 ) ;
unsigned long V_97 ;
F_68 ( & V_96 , V_97 ) ;
if ( V_95 ) {
if ( V_94 < V_16 . V_98 ) {
F_69 ( V_99 L_17 ,
V_94 , V_16 . V_98 ) ;
V_91 = - V_100 ;
}
} else {
if ( V_94 > V_16 . V_98 )
V_16 . V_98 = V_94 ;
}
F_60 ( & V_96 , V_97 ) ;
return V_91 ;
}
static struct V_22 * F_70 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
struct V_66 * V_67 ,
struct V_25 * V_40 )
{
struct V_22 * V_101 , * V_34 = NULL ;
int V_81 ;
unsigned long V_97 ;
if ( F_66 ( V_67 -> V_94 , 1 ) )
goto V_88;
V_34 = F_61 () ;
if ( V_34 ) {
struct V_35 * V_36 ;
T_5 * V_85 ;
int V_12 = 0 ;
V_81 = F_1 ( V_1 , V_2 , V_3 ) ;
F_63 ( V_34 , V_1 , V_2 , V_3 , V_67 ) ;
V_12 = F_40 ( V_34 , V_40 ) ;
if ( V_12 ) {
F_28 ( V_21 , V_34 ) ;
return NULL ;
}
V_36 = & V_16 . V_17 [ V_81 ] ;
V_85 = & V_16 . V_18 [ V_81 ] ;
F_68 ( V_85 , V_97 ) ;
F_59 (pos, head, list) {
if ( V_101 -> V_60 . V_1 == V_1 &&
V_101 -> V_60 . V_2 == V_2 &&
V_101 -> V_60 . V_3 == V_3 ) {
F_54 ( V_34 , V_101 ) ;
goto V_102;
}
}
F_71 ( & V_34 -> V_78 , V_36 ) ;
V_102:
F_60 ( V_85 , V_97 ) ;
}
V_88:
return V_34 ;
}
static void F_72 ( struct V_5 * V_6 , void * V_103 )
{
struct V_73 * V_74 = V_103 ;
F_3 ( V_6 , L_18 ,
V_74 -> V_104 -> V_70 ? L_19 : L_20 ) ;
F_2 ( V_6 , V_74 -> V_104 -> V_3 ,
V_74 -> V_104 -> V_71 ) ;
F_3 ( V_6 , L_21 ) ;
}
static void F_73 ( struct V_5 * V_6 , void * V_103 )
{
struct V_73 * V_74 = V_103 ;
F_3 ( V_6 , L_22 ) ;
F_6 ( V_6 , V_74 -> V_104 -> V_1 ,
V_74 -> V_104 -> V_2 ,
V_74 -> V_104 -> V_3 ) ;
if ( V_74 -> V_104 -> V_70 ) {
F_3 ( V_6 , L_23 ,
V_74 -> V_104 -> V_68 ? 0 : 1 ) ;
}
}
T_6 int F_45 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_65 , T_1 V_71 , T_1 V_70 , int V_68 ,
struct V_73 * V_103 ,
unsigned V_84 )
{
struct V_73 V_105 ;
struct V_104 V_106 ;
if ( ! V_103 ) {
V_103 = & V_105 ;
V_103 -> type = V_107 ;
}
if ( ( V_103 -> type == V_108 ) &&
( V_84 & V_109 ) )
return - V_110 ;
V_106 . V_3 = V_3 ;
V_106 . V_65 = V_65 ;
V_106 . V_1 = V_1 ;
V_106 . V_2 = V_2 ;
V_106 . V_71 = V_71 ;
V_106 . V_70 = V_70 ;
V_106 . V_68 = V_68 ;
V_103 -> V_104 = & V_106 ;
F_74 ( V_103 , F_72 , F_73 ) ;
return 0 ;
}
int T_3 F_75 ( int (* F_76)( T_1 V_111 ) , T_1 V_112 )
{
struct V_113 * V_114 ;
int V_12 = 0 ;
V_114 = F_77 ( sizeof( * V_114 ) , V_115 ) ;
if ( ! V_114 ) {
V_12 = - V_62 ;
goto V_88;
}
V_114 -> F_76 = F_76 ;
V_114 -> V_112 = V_112 ;
V_114 -> V_116 = V_117 ;
V_117 = V_114 ;
V_88:
return V_12 ;
}
static int F_78 ( T_1 V_111 , T_1 V_8 , T_4 V_39 , T_4 V_118 , T_1 V_1 ,
T_1 V_2 , T_2 V_3 , T_1 V_94 ,
struct V_38 * V_42 ,
T_1 V_84 )
{
int V_81 , V_12 = 0 ;
unsigned long V_97 ;
struct V_22 * V_101 , * V_34 , * V_119 = NULL ;
struct V_35 * V_36 ;
T_5 * V_85 ;
V_34 = F_61 () ;
if ( ! V_34 ) {
V_12 = - V_62 ;
goto V_88;
}
V_81 = F_1 ( V_1 , V_2 , V_3 ) ;
V_36 = & V_16 . V_17 [ V_81 ] ;
V_85 = & V_16 . V_18 [ V_81 ] ;
F_68 ( V_85 , V_97 ) ;
F_59 (pos, head, list) {
if ( V_1 == V_101 -> V_60 . V_1 &&
V_2 == V_101 -> V_60 . V_2 &&
V_3 == V_101 -> V_60 . V_3 &&
V_94 == V_101 -> V_60 . V_67 . V_94 ) {
V_119 = V_101 ;
break;
}
}
if ( ! V_119 ) {
V_12 = - V_120 ;
F_53 ( V_34 ) ;
goto V_121;
}
F_63 ( V_34 , V_1 , V_2 , V_3 , & V_119 -> V_60 . V_67 ) ;
if ( V_119 -> V_60 . V_40 ) {
V_12 = F_40 ( V_34 , V_119 -> V_60 . V_40 ) ;
if ( V_12 ) {
F_28 ( V_21 , V_34 ) ;
goto V_121;
}
}
switch ( V_111 ) {
case V_122 :
V_34 -> V_60 . V_67 . V_46 |= V_8 ;
if ( V_34 -> V_60 . V_40 && ( V_84 & V_123 ) )
F_25 ( V_34 -> V_60 . V_40 , V_39 , V_118 ) ;
break;
case V_124 :
case V_125 :
V_34 -> V_60 . V_67 . V_46 &= ~ V_8 ;
break;
case V_126 :
V_34 -> V_60 . V_67 . V_49 |= V_8 ;
break;
case V_127 :
V_34 -> V_60 . V_67 . V_49 &= ~ V_8 ;
break;
case V_128 :
V_34 -> V_60 . V_67 . V_72 |= V_8 ;
break;
case V_129 :
V_34 -> V_60 . V_67 . V_72 &= ~ V_8 ;
break;
case V_130 :
F_36 ( V_34 , V_42 ) ;
break;
}
F_54 ( V_34 , V_119 ) ;
V_121:
F_60 ( V_85 , V_97 ) ;
V_88:
return V_12 ;
}
static void F_79 ( void )
{
struct V_35 * V_36 ;
struct V_22 * V_34 ;
T_5 * V_85 ;
unsigned long V_97 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
V_36 = & V_16 . V_17 [ V_9 ] ;
V_85 = & V_16 . V_18 [ V_9 ] ;
F_68 ( V_85 , V_97 ) ;
F_15 () ;
F_59 (node, head, list)
F_49 ( V_34 ) ;
F_18 () ;
F_60 ( V_85 , V_97 ) ;
}
}
int F_80 ( T_1 V_94 )
{
struct V_113 * V_114 ;
int V_12 = 0 , V_131 ;
F_79 () ;
for ( V_114 = V_117 ; V_114 ; V_114 = V_114 -> V_116 ) {
if ( V_114 -> V_112 & V_132 ) {
V_131 = V_114 -> F_76 ( V_132 ) ;
if ( ! V_12 )
V_12 = V_131 ;
}
}
F_66 ( V_94 , 0 ) ;
return V_12 ;
}
static T_6 int F_81 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 , T_1 V_65 ,
T_4 V_39 , T_4 V_118 , unsigned V_84 ,
struct V_66 * V_67 )
{
if ( V_84 & V_133 )
return - V_134 ;
if ( V_135 && ! ( V_67 -> V_84 & V_136 ) )
return - V_134 ;
F_78 ( V_122 , V_65 , V_39 , V_118 , V_1 ,
V_2 , V_3 , V_67 -> V_94 , NULL , V_84 ) ;
return 0 ;
}
int F_82 ( T_1 V_1 , T_1 V_2 , T_2 V_3 , T_1 V_65 ,
T_4 V_39 , T_4 V_118 , struct V_73 * V_74 )
{
struct V_22 * V_34 ;
struct V_66 V_67 ;
T_1 V_70 ;
struct V_38 V_137 ;
struct V_38 * V_42 = NULL ;
struct V_29 V_46 ;
struct V_29 V_49 ;
struct V_29 V_51 ;
struct V_25 V_138 ;
struct V_25 * V_40 ;
int V_12 = 0 , V_139 ;
V_40 = & V_138 ;
F_4 ( ! V_65 ) ;
F_15 () ;
V_34 = F_65 ( V_1 , V_2 , V_3 ) ;
if ( F_42 ( ! V_34 ) ) {
V_34 = F_83 ( V_1 , V_2 , V_3 , & V_67 , V_40 ) ;
} else {
memcpy ( & V_67 , & V_34 -> V_60 . V_67 , sizeof( V_67 ) ) ;
V_40 = V_34 -> V_60 . V_40 ;
}
if ( ! V_40 || ! V_40 -> V_52 . V_61 )
goto V_140;
V_137 . V_46 = & V_46 ;
V_137 . V_49 = & V_49 ;
V_137 . V_51 = & V_51 ;
V_42 = F_21 ( V_39 , V_40 ) ;
if ( F_42 ( ! V_42 ) ) {
if ( ! F_24 ( V_40 -> V_52 . V_53 . V_47 , V_39 ) ) {
V_67 . V_46 &= ~ V_65 ;
goto V_140;
}
F_18 () ;
F_84 ( V_1 , V_2 , V_3 , V_39 ,
& V_137 ) ;
F_15 () ;
F_78 ( V_130 , V_65 , V_39 , V_118 ,
V_1 , V_2 , V_3 , V_67 . V_94 , & V_137 , 0 ) ;
} else {
F_33 ( V_118 , & V_137 , V_42 ) ;
}
V_42 = & V_137 ;
if ( ! F_23 ( V_42 , V_118 , V_44 ) )
V_67 . V_46 &= ~ V_65 ;
V_140:
V_70 = V_65 & ~ ( V_67 . V_46 ) ;
if ( F_42 ( V_70 ) )
V_12 = F_81 ( V_1 , V_2 , V_3 , V_65 , V_39 , V_118 ,
V_123 , & V_67 ) ;
F_18 () ;
V_139 = F_43 ( V_1 , V_2 , V_3 , V_65 ,
& V_67 , V_42 , V_118 , V_12 , V_74 ) ;
if ( V_139 )
return V_139 ;
return V_12 ;
}
inline int F_85 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 , T_1 V_65 ,
unsigned V_84 ,
struct V_66 * V_67 )
{
struct V_22 * V_34 ;
struct V_25 V_40 ;
int V_12 = 0 ;
T_1 V_70 ;
F_4 ( ! V_65 ) ;
F_15 () ;
V_34 = F_65 ( V_1 , V_2 , V_3 ) ;
if ( F_42 ( ! V_34 ) )
V_34 = F_83 ( V_1 , V_2 , V_3 , V_67 , & V_40 ) ;
else
memcpy ( V_67 , & V_34 -> V_60 . V_67 , sizeof( * V_67 ) ) ;
V_70 = V_65 & ~ ( V_67 -> V_46 ) ;
if ( F_42 ( V_70 ) )
V_12 = F_81 ( V_1 , V_2 , V_3 , V_65 , 0 , 0 , V_84 , V_67 ) ;
F_18 () ;
return V_12 ;
}
int F_86 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_65 , struct V_73 * V_141 )
{
struct V_66 V_67 ;
int V_12 , V_139 ;
V_12 = F_85 ( V_1 , V_2 , V_3 , V_65 , 0 , & V_67 ) ;
V_139 = F_87 ( V_1 , V_2 , V_3 , V_65 , & V_67 , V_12 , V_141 , 0 ) ;
if ( V_139 )
return V_139 ;
return V_12 ;
}
int F_88 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_65 , struct V_73 * V_141 ,
int V_84 )
{
struct V_66 V_67 ;
int V_12 , V_139 ;
V_12 = F_85 ( V_1 , V_2 , V_3 , V_65 , 0 , & V_67 ) ;
V_139 = F_87 ( V_1 , V_2 , V_3 , V_65 , & V_67 , V_12 ,
V_141 , V_84 ) ;
if ( V_139 )
return V_139 ;
return V_12 ;
}
T_1 F_89 ( void )
{
return V_16 . V_98 ;
}
void F_90 ( void )
{
if ( V_21 ) {
F_79 () ;
}
}
