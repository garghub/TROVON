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
F_14 ( V_30 -> V_31 , V_32 , V_33 , L_15 ) ;
}
int F_15 ( char * V_34 )
{
int V_9 , V_35 , V_36 , V_37 ;
struct V_22 * V_38 ;
struct V_39 * V_40 ;
F_16 () ;
V_37 = 0 ;
V_36 = 0 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
V_40 = & V_16 . V_17 [ V_9 ] ;
if ( ! F_17 ( V_40 ) ) {
V_37 ++ ;
V_35 = 0 ;
F_18 (node, head, list)
V_35 ++ ;
if ( V_35 > V_36 )
V_36 = V_35 ;
}
}
F_19 () ;
return F_20 ( V_34 , V_41 , L_16
L_17 ,
F_21 ( & V_16 . V_19 ) ,
V_37 , V_4 , V_36 ) ;
}
static struct V_42 * F_22 ( T_4 V_43 ,
struct V_25 * V_44 )
{
struct V_27 * V_45 ;
F_23 (xpd_node, &xp_node->xpd_head, xpd_list) {
if ( V_45 -> V_46 . V_43 == V_43 )
return & V_45 -> V_46 ;
}
return NULL ;
}
static inline unsigned int
F_24 ( struct V_42 * V_46 ,
T_4 V_10 , T_4 V_47 )
{
unsigned int V_12 = 0 ;
if ( ( V_47 == V_48 ) &&
( V_46 -> V_49 & V_48 ) )
V_12 = F_25 ( V_46 -> V_50 -> V_51 , V_10 ) ;
else if ( ( V_47 == V_52 ) &&
( V_46 -> V_49 & V_52 ) )
V_12 = F_25 ( V_46 -> V_53 -> V_51 , V_10 ) ;
else if ( ( V_47 == V_54 ) &&
( V_46 -> V_49 & V_54 ) )
V_12 = F_25 ( V_46 -> V_55 -> V_51 , V_10 ) ;
return V_12 ;
}
static void F_26 ( struct V_25 * V_44 ,
T_4 V_43 , T_4 V_10 )
{
struct V_42 * V_46 ;
F_27 ( V_44 -> V_56 . V_57 . V_51 , V_43 ) ;
V_46 = F_22 ( V_43 , V_44 ) ;
if ( V_46 && V_46 -> V_50 )
F_27 ( V_46 -> V_50 -> V_51 , V_10 ) ;
}
static void F_28 ( struct V_27 * V_45 )
{
struct V_42 * V_46 ;
V_46 = & V_45 -> V_46 ;
if ( V_46 -> V_50 )
F_29 ( V_28 , V_46 -> V_50 ) ;
if ( V_46 -> V_53 )
F_29 ( V_28 , V_46 -> V_53 ) ;
if ( V_46 -> V_55 )
F_29 ( V_28 , V_46 -> V_55 ) ;
F_29 ( V_26 , V_45 ) ;
}
static void F_30 ( struct V_25 * V_44 )
{
struct V_27 * V_45 , * V_58 ;
if ( ! V_44 )
return;
F_31 (xpd_node, tmp, &xp_node->xpd_head, xpd_list) {
F_32 ( & V_45 -> V_59 ) ;
F_28 ( V_45 ) ;
}
F_29 ( V_24 , V_44 ) ;
}
static void F_33 ( struct V_42 * V_60 ,
struct V_42 * V_61 )
{
V_60 -> V_43 = V_61 -> V_43 ;
V_60 -> V_49 = V_61 -> V_49 ;
if ( V_60 -> V_49 & V_48 )
memcpy ( V_60 -> V_50 -> V_51 , V_61 -> V_50 -> V_51 ,
sizeof( V_61 -> V_50 -> V_51 ) ) ;
if ( V_60 -> V_49 & V_52 )
memcpy ( V_60 -> V_53 -> V_51 , V_61 -> V_53 -> V_51 ,
sizeof( V_61 -> V_53 -> V_51 ) ) ;
if ( V_60 -> V_49 & V_54 )
memcpy ( V_60 -> V_55 -> V_51 , V_61 -> V_55 -> V_51 ,
sizeof( V_61 -> V_55 -> V_51 ) ) ;
}
static inline void F_34 ( T_4 V_10 ,
struct V_42 * V_60 ,
struct V_42 * V_61 )
{
T_4 V_9 = V_10 >> 5 ;
V_60 -> V_49 = V_61 -> V_49 ;
if ( V_60 -> V_49 & V_48 )
V_60 -> V_50 -> V_51 [ V_9 ] = V_61 -> V_50 -> V_51 [ V_9 ] ;
if ( V_60 -> V_49 & V_52 )
V_60 -> V_53 -> V_51 [ V_9 ] = V_61 -> V_53 -> V_51 [ V_9 ] ;
if ( V_60 -> V_49 & V_54 )
V_60 -> V_55 -> V_51 [ V_9 ] = V_61 -> V_55 -> V_51 [ V_9 ] ;
}
static struct V_27
* F_35 ( T_4 V_47 )
{
struct V_27 * V_45 ;
struct V_42 * V_46 ;
V_45 = F_36 ( V_26 ,
V_62 | V_63 ) ;
if ( ! V_45 )
return NULL ;
V_46 = & V_45 -> V_46 ;
if ( V_47 & V_48 ) {
V_46 -> V_50 = F_36 ( V_28 ,
V_62 | V_63 ) ;
if ( ! V_46 -> V_50 )
goto error;
}
if ( V_47 & V_52 ) {
V_46 -> V_53 = F_36 ( V_28 ,
V_62 | V_63 ) ;
if ( ! V_46 -> V_53 )
goto error;
}
if ( V_47 & V_54 ) {
V_46 -> V_55 = F_36 ( V_28 ,
V_62 | V_63 ) ;
if ( ! V_46 -> V_55 )
goto error;
}
return V_45 ;
error:
F_28 ( V_45 ) ;
return NULL ;
}
static int F_37 ( struct V_22 * V_38 ,
struct V_42 * V_61 )
{
struct V_27 * V_64 ;
V_38 -> V_65 . V_44 -> V_56 . V_66 ++ ;
V_64 = F_35 ( V_61 -> V_49 ) ;
if ( ! V_64 )
return - V_67 ;
F_33 ( & V_64 -> V_46 , V_61 ) ;
F_38 ( & V_64 -> V_59 , & V_38 -> V_65 . V_44 -> V_68 ) ;
return 0 ;
}
static struct V_25 * F_39 ( void )
{
struct V_25 * V_44 ;
V_44 = F_36 ( V_24 ,
V_62 | V_63 ) ;
if ( ! V_44 )
return V_44 ;
F_40 ( & V_44 -> V_68 ) ;
return V_44 ;
}
static int F_41 ( struct V_22 * V_38 ,
struct V_25 * V_61 )
{
struct V_25 * V_60 ;
struct V_27 * V_64 ;
struct V_27 * V_69 ;
if ( V_61 -> V_56 . V_66 == 0 )
return 0 ;
V_60 = F_39 () ;
if ( ! V_60 )
return - V_67 ;
memcpy ( V_60 -> V_56 . V_57 . V_51 , V_61 -> V_56 . V_57 . V_51 , sizeof( V_60 -> V_56 . V_57 . V_51 ) ) ;
V_60 -> V_56 . V_66 = V_61 -> V_56 . V_66 ;
F_23 (src_xpd, &src->xpd_head, xpd_list) {
V_64 = F_35 ( V_69 -> V_46 . V_49 ) ;
if ( ! V_64 )
goto error;
F_33 ( & V_64 -> V_46 , & V_69 -> V_46 ) ;
F_38 ( & V_64 -> V_59 , & V_60 -> V_68 ) ;
}
V_38 -> V_65 . V_44 = V_60 ;
return 0 ;
error:
F_30 ( V_60 ) ;
return - V_67 ;
}
static inline T_1 F_42 ( T_1 V_70 ,
struct V_71 * V_72 ,
struct V_42 * V_46 ,
T_4 V_10 ,
int V_73 ,
T_1 * V_74 )
{
T_1 V_75 , V_76 ;
V_75 = V_70 & ~ V_72 -> V_50 ;
if ( F_43 ( V_75 ) ) {
V_76 = V_75 & V_72 -> V_77 ;
if ( V_76 && V_46 ) {
if ( F_24 ( V_46 , V_10 , V_54 ) )
V_76 &= ~ V_70 ;
}
} else if ( V_73 ) {
V_76 = V_75 = V_70 ;
} else {
V_76 = V_70 & V_72 -> V_53 ;
if ( V_76 && V_46 ) {
if ( ! F_24 ( V_46 , V_10 , V_52 ) )
V_76 &= ~ V_70 ;
}
}
* V_74 = V_75 ;
return V_76 ;
}
static inline int F_44 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_70 , struct V_71 * V_72 ,
struct V_42 * V_46 ,
T_4 V_10 , int V_73 ,
struct V_78 * V_79 )
{
T_1 V_76 , V_75 ;
V_76 = F_42 (
V_70 , V_72 , V_46 , V_10 , V_73 , & V_75 ) ;
if ( F_45 ( ! V_76 ) )
return 0 ;
return F_46 ( V_1 , V_2 , V_3 , V_70 ,
V_76 , V_75 , V_73 , V_79 , 0 ) ;
}
static void F_47 ( struct V_80 * V_81 )
{
struct V_22 * V_38 = F_48 ( V_81 , struct V_22 , V_81 ) ;
F_30 ( V_38 -> V_65 . V_44 ) ;
F_29 ( V_21 , V_38 ) ;
F_49 ( V_82 ) ;
}
static void F_50 ( struct V_22 * V_38 )
{
F_51 ( & V_38 -> V_83 ) ;
F_52 ( & V_38 -> V_81 , F_47 ) ;
F_53 ( & V_16 . V_19 ) ;
}
static void F_54 ( struct V_22 * V_38 )
{
F_30 ( V_38 -> V_65 . V_44 ) ;
F_29 ( V_21 , V_38 ) ;
F_49 ( V_82 ) ;
F_53 ( & V_16 . V_19 ) ;
}
static void F_55 ( struct V_22 * V_84 , struct V_22 * V_85 )
{
F_56 ( & V_85 -> V_83 , & V_84 -> V_83 ) ;
F_52 ( & V_85 -> V_81 , F_47 ) ;
F_53 ( & V_16 . V_19 ) ;
}
static inline int F_57 ( void )
{
struct V_22 * V_38 ;
int V_86 , V_87 , V_88 ;
unsigned long V_89 ;
struct V_39 * V_40 ;
T_5 * V_90 ;
for ( V_87 = 0 , V_88 = 0 ; V_87 < V_4 ; V_87 ++ ) {
V_86 = F_58 ( & V_16 . V_20 ) & ( V_4 - 1 ) ;
V_40 = & V_16 . V_17 [ V_86 ] ;
V_90 = & V_16 . V_18 [ V_86 ] ;
if ( ! F_59 ( V_90 , V_89 ) )
continue;
F_16 () ;
F_60 (node, head, list) {
F_50 ( V_38 ) ;
F_49 ( V_91 ) ;
V_88 ++ ;
if ( V_88 >= V_92 ) {
F_19 () ;
F_61 ( V_90 , V_89 ) ;
goto V_93;
}
}
F_19 () ;
F_61 ( V_90 , V_89 ) ;
}
V_93:
return V_88 ;
}
static struct V_22 * F_62 ( void )
{
struct V_22 * V_38 ;
V_38 = F_36 ( V_21 , V_62 | V_63 ) ;
if ( ! V_38 )
goto V_93;
F_63 ( & V_38 -> V_83 ) ;
F_49 ( V_94 ) ;
if ( F_58 ( & V_16 . V_19 ) > V_95 )
F_57 () ;
V_93:
return V_38 ;
}
static void F_64 ( struct V_22 * V_38 , T_1 V_1 , T_1 V_2 , T_2 V_3 , struct V_71 * V_72 )
{
V_38 -> V_65 . V_1 = V_1 ;
V_38 -> V_65 . V_2 = V_2 ;
V_38 -> V_65 . V_3 = V_3 ;
memcpy ( & V_38 -> V_65 . V_72 , V_72 , sizeof( V_38 -> V_65 . V_72 ) ) ;
}
static inline struct V_22 * F_65 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_22 * V_38 , * V_96 = NULL ;
int V_86 ;
struct V_39 * V_40 ;
V_86 = F_1 ( V_1 , V_2 , V_3 ) ;
V_40 = & V_16 . V_17 [ V_86 ] ;
F_18 (node, head, list) {
if ( V_1 == V_38 -> V_65 . V_1 &&
V_3 == V_38 -> V_65 . V_3 &&
V_2 == V_38 -> V_65 . V_2 ) {
V_96 = V_38 ;
break;
}
}
return V_96 ;
}
static struct V_22 * F_66 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_22 * V_38 ;
F_49 ( V_97 ) ;
V_38 = F_65 ( V_1 , V_2 , V_3 ) ;
if ( V_38 )
return V_38 ;
F_49 ( V_98 ) ;
return NULL ;
}
static int F_67 ( int V_99 , int V_100 )
{
int V_96 = 0 ;
static F_68 ( V_101 ) ;
unsigned long V_102 ;
F_69 ( & V_101 , V_102 ) ;
if ( V_100 ) {
if ( V_99 < V_16 . V_103 ) {
F_70 ( V_104 L_18 ,
V_99 , V_16 . V_103 ) ;
V_96 = - V_105 ;
}
} else {
if ( V_99 > V_16 . V_103 )
V_16 . V_103 = V_99 ;
}
F_61 ( & V_101 , V_102 ) ;
return V_96 ;
}
static struct V_22 * F_71 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
struct V_71 * V_72 ,
struct V_25 * V_44 )
{
struct V_22 * V_106 , * V_38 = NULL ;
int V_86 ;
unsigned long V_102 ;
if ( F_67 ( V_72 -> V_99 , 1 ) )
goto V_93;
V_38 = F_62 () ;
if ( V_38 ) {
struct V_39 * V_40 ;
T_5 * V_90 ;
int V_12 = 0 ;
V_86 = F_1 ( V_1 , V_2 , V_3 ) ;
F_64 ( V_38 , V_1 , V_2 , V_3 , V_72 ) ;
V_12 = F_41 ( V_38 , V_44 ) ;
if ( V_12 ) {
F_29 ( V_21 , V_38 ) ;
return NULL ;
}
V_40 = & V_16 . V_17 [ V_86 ] ;
V_90 = & V_16 . V_18 [ V_86 ] ;
F_69 ( V_90 , V_102 ) ;
F_60 (pos, head, list) {
if ( V_106 -> V_65 . V_1 == V_1 &&
V_106 -> V_65 . V_2 == V_2 &&
V_106 -> V_65 . V_3 == V_3 ) {
F_55 ( V_38 , V_106 ) ;
goto V_107;
}
}
F_72 ( & V_38 -> V_83 , V_40 ) ;
V_107:
F_61 ( V_90 , V_102 ) ;
}
V_93:
return V_38 ;
}
static void F_73 ( struct V_5 * V_6 , void * V_108 )
{
struct V_78 * V_79 = V_108 ;
F_3 ( V_6 , L_19 ,
V_79 -> V_109 -> V_75 ? L_20 : L_21 ) ;
F_2 ( V_6 , V_79 -> V_109 -> V_3 ,
V_79 -> V_109 -> V_76 ) ;
F_3 ( V_6 , L_22 ) ;
}
static void F_74 ( struct V_5 * V_6 , void * V_108 )
{
struct V_78 * V_79 = V_108 ;
F_3 ( V_6 , L_23 ) ;
F_6 ( V_6 , V_79 -> V_109 -> V_1 ,
V_79 -> V_109 -> V_2 ,
V_79 -> V_109 -> V_3 ) ;
if ( V_79 -> V_109 -> V_75 ) {
F_3 ( V_6 , L_24 ,
V_79 -> V_109 -> V_73 ? 0 : 1 ) ;
}
}
T_6 int F_46 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_70 , T_1 V_76 , T_1 V_75 , int V_73 ,
struct V_78 * V_108 ,
unsigned V_89 )
{
struct V_78 V_110 ;
struct V_109 V_111 ;
if ( ! V_108 ) {
V_108 = & V_110 ;
V_108 -> type = V_112 ;
}
if ( ( V_108 -> type == V_113 ) &&
( V_89 & V_114 ) )
return - V_115 ;
V_111 . V_3 = V_3 ;
V_111 . V_70 = V_70 ;
V_111 . V_1 = V_1 ;
V_111 . V_2 = V_2 ;
V_111 . V_76 = V_76 ;
V_111 . V_75 = V_75 ;
V_111 . V_73 = V_73 ;
V_108 -> V_109 = & V_111 ;
F_75 ( V_108 , F_73 , F_74 ) ;
return 0 ;
}
int T_3 F_76 ( int (* F_77)( T_1 V_116 ) , T_1 V_117 )
{
struct V_118 * V_119 ;
int V_12 = 0 ;
V_119 = F_78 ( sizeof( * V_119 ) , V_32 ) ;
if ( ! V_119 ) {
V_12 = - V_67 ;
goto V_93;
}
V_119 -> F_77 = F_77 ;
V_119 -> V_117 = V_117 ;
V_119 -> V_120 = V_121 ;
V_121 = V_119 ;
V_93:
return V_12 ;
}
static int F_79 ( T_1 V_116 , T_1 V_8 , T_4 V_43 , T_4 V_122 , T_1 V_1 ,
T_1 V_2 , T_2 V_3 , T_1 V_99 ,
struct V_42 * V_46 ,
T_1 V_89 )
{
int V_86 , V_12 = 0 ;
unsigned long V_102 ;
struct V_22 * V_106 , * V_38 , * V_123 = NULL ;
struct V_39 * V_40 ;
T_5 * V_90 ;
V_38 = F_62 () ;
if ( ! V_38 ) {
V_12 = - V_67 ;
goto V_93;
}
V_86 = F_1 ( V_1 , V_2 , V_3 ) ;
V_40 = & V_16 . V_17 [ V_86 ] ;
V_90 = & V_16 . V_18 [ V_86 ] ;
F_69 ( V_90 , V_102 ) ;
F_60 (pos, head, list) {
if ( V_1 == V_106 -> V_65 . V_1 &&
V_2 == V_106 -> V_65 . V_2 &&
V_3 == V_106 -> V_65 . V_3 &&
V_99 == V_106 -> V_65 . V_72 . V_99 ) {
V_123 = V_106 ;
break;
}
}
if ( ! V_123 ) {
V_12 = - V_124 ;
F_54 ( V_38 ) ;
goto V_125;
}
F_64 ( V_38 , V_1 , V_2 , V_3 , & V_123 -> V_65 . V_72 ) ;
if ( V_123 -> V_65 . V_44 ) {
V_12 = F_41 ( V_38 , V_123 -> V_65 . V_44 ) ;
if ( V_12 ) {
F_29 ( V_21 , V_38 ) ;
goto V_125;
}
}
switch ( V_116 ) {
case V_126 :
V_38 -> V_65 . V_72 . V_50 |= V_8 ;
if ( V_38 -> V_65 . V_44 && ( V_89 & V_127 ) )
F_26 ( V_38 -> V_65 . V_44 , V_43 , V_122 ) ;
break;
case V_128 :
case V_129 :
V_38 -> V_65 . V_72 . V_50 &= ~ V_8 ;
break;
case V_130 :
V_38 -> V_65 . V_72 . V_53 |= V_8 ;
break;
case V_131 :
V_38 -> V_65 . V_72 . V_53 &= ~ V_8 ;
break;
case V_132 :
V_38 -> V_65 . V_72 . V_77 |= V_8 ;
break;
case V_133 :
V_38 -> V_65 . V_72 . V_77 &= ~ V_8 ;
break;
case V_134 :
F_37 ( V_38 , V_46 ) ;
break;
}
F_55 ( V_38 , V_123 ) ;
V_125:
F_61 ( V_90 , V_102 ) ;
V_93:
return V_12 ;
}
static void F_80 ( void )
{
struct V_39 * V_40 ;
struct V_22 * V_38 ;
T_5 * V_90 ;
unsigned long V_102 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
V_40 = & V_16 . V_17 [ V_9 ] ;
V_90 = & V_16 . V_18 [ V_9 ] ;
F_69 ( V_90 , V_102 ) ;
F_16 () ;
F_60 (node, head, list)
F_50 ( V_38 ) ;
F_19 () ;
F_61 ( V_90 , V_102 ) ;
}
}
int F_81 ( T_1 V_99 )
{
struct V_118 * V_119 ;
int V_12 = 0 , V_135 ;
F_80 () ;
for ( V_119 = V_121 ; V_119 ; V_119 = V_119 -> V_120 ) {
if ( V_119 -> V_117 & V_136 ) {
V_135 = V_119 -> F_77 ( V_136 ) ;
if ( ! V_12 )
V_12 = V_135 ;
}
}
F_67 ( V_99 , 0 ) ;
return V_12 ;
}
static T_6 int F_82 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 , T_1 V_70 ,
T_4 V_43 , T_4 V_122 , unsigned V_89 ,
struct V_71 * V_72 )
{
if ( V_89 & V_137 )
return - V_138 ;
if ( V_139 && ! ( V_72 -> V_89 & V_140 ) )
return - V_138 ;
F_79 ( V_126 , V_70 , V_43 , V_122 , V_1 ,
V_2 , V_3 , V_72 -> V_99 , NULL , V_89 ) ;
return 0 ;
}
int F_83 ( T_1 V_1 , T_1 V_2 , T_2 V_3 , T_1 V_70 ,
T_4 V_43 , T_4 V_122 , struct V_78 * V_79 )
{
struct V_22 * V_38 ;
struct V_71 V_72 ;
T_1 V_75 ;
struct V_42 V_141 ;
struct V_42 * V_46 = NULL ;
struct V_29 V_50 ;
struct V_29 V_53 ;
struct V_29 V_55 ;
struct V_25 V_142 ;
struct V_25 * V_44 ;
int V_12 = 0 , V_143 ;
V_44 = & V_142 ;
F_4 ( ! V_70 ) ;
F_16 () ;
V_38 = F_66 ( V_1 , V_2 , V_3 ) ;
if ( F_43 ( ! V_38 ) ) {
V_38 = F_84 ( V_1 , V_2 , V_3 , & V_72 , V_44 ) ;
} else {
memcpy ( & V_72 , & V_38 -> V_65 . V_72 , sizeof( V_72 ) ) ;
V_44 = V_38 -> V_65 . V_44 ;
}
if ( ! V_44 || ! V_44 -> V_56 . V_66 )
goto V_144;
V_141 . V_50 = & V_50 ;
V_141 . V_53 = & V_53 ;
V_141 . V_55 = & V_55 ;
V_46 = F_22 ( V_43 , V_44 ) ;
if ( F_43 ( ! V_46 ) ) {
if ( ! F_25 ( V_44 -> V_56 . V_57 . V_51 , V_43 ) ) {
V_72 . V_50 &= ~ V_70 ;
goto V_144;
}
F_19 () ;
F_85 ( V_1 , V_2 , V_3 , V_43 ,
& V_141 ) ;
F_16 () ;
F_79 ( V_134 , V_70 , V_43 , V_122 ,
V_1 , V_2 , V_3 , V_72 . V_99 , & V_141 , 0 ) ;
} else {
F_34 ( V_122 , & V_141 , V_46 ) ;
}
V_46 = & V_141 ;
if ( ! F_24 ( V_46 , V_122 , V_48 ) )
V_72 . V_50 &= ~ V_70 ;
V_144:
V_75 = V_70 & ~ ( V_72 . V_50 ) ;
if ( F_43 ( V_75 ) )
V_12 = F_82 ( V_1 , V_2 , V_3 , V_70 , V_43 , V_122 ,
V_127 , & V_72 ) ;
F_19 () ;
V_143 = F_44 ( V_1 , V_2 , V_3 , V_70 ,
& V_72 , V_46 , V_122 , V_12 , V_79 ) ;
if ( V_143 )
return V_143 ;
return V_12 ;
}
inline int F_86 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 , T_1 V_70 ,
unsigned V_89 ,
struct V_71 * V_72 )
{
struct V_22 * V_38 ;
struct V_25 V_44 ;
int V_12 = 0 ;
T_1 V_75 ;
F_4 ( ! V_70 ) ;
F_16 () ;
V_38 = F_66 ( V_1 , V_2 , V_3 ) ;
if ( F_43 ( ! V_38 ) )
V_38 = F_84 ( V_1 , V_2 , V_3 , V_72 , & V_44 ) ;
else
memcpy ( V_72 , & V_38 -> V_65 . V_72 , sizeof( * V_72 ) ) ;
V_75 = V_70 & ~ ( V_72 -> V_50 ) ;
if ( F_43 ( V_75 ) )
V_12 = F_82 ( V_1 , V_2 , V_3 , V_70 , 0 , 0 , V_89 , V_72 ) ;
F_19 () ;
return V_12 ;
}
int F_87 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_70 , struct V_78 * V_145 )
{
struct V_71 V_72 ;
int V_12 , V_143 ;
V_12 = F_86 ( V_1 , V_2 , V_3 , V_70 , 0 , & V_72 ) ;
V_143 = F_88 ( V_1 , V_2 , V_3 , V_70 , & V_72 , V_12 , V_145 , 0 ) ;
if ( V_143 )
return V_143 ;
return V_12 ;
}
int F_89 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_70 , struct V_78 * V_145 ,
int V_89 )
{
struct V_71 V_72 ;
int V_12 , V_143 ;
V_12 = F_86 ( V_1 , V_2 , V_3 , V_70 , 0 , & V_72 ) ;
V_143 = F_88 ( V_1 , V_2 , V_3 , V_70 , & V_72 , V_12 ,
V_145 , V_89 ) ;
if ( V_143 )
return V_143 ;
return V_12 ;
}
T_1 F_90 ( void )
{
return V_16 . V_103 ;
}
void F_91 ( void )
{
if ( V_21 ) {
F_80 () ;
}
}
