int F_1 ( T_1 V_1 , T_1 V_2 ,
T_1 V_3 , T_1 V_4 ,
const struct V_5 * V_6 )
{
unsigned int V_7 , V_8 ;
V_7 = V_6 -> V_9 << 16 ;
V_8 = V_6 -> V_10 << 16 ;
if ( V_3 > V_7 ||
V_1 > V_7 - V_3 ||
V_4 > V_8 ||
V_2 > V_8 - V_4 ) {
F_2 ( L_1
L_2 ,
V_3 >> 16 , ( ( V_3 & 0xffff ) * 15625 ) >> 10 ,
V_4 >> 16 , ( ( V_4 & 0xffff ) * 15625 ) >> 10 ,
V_1 >> 16 , ( ( V_1 & 0xffff ) * 15625 ) >> 10 ,
V_2 >> 16 , ( ( V_2 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_11 ;
}
return 0 ;
}
int F_3 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_14 ;
struct V_19 V_20 = {} ;
int V_21 ;
V_20 . V_22 = V_18 -> V_22 ;
V_20 . V_9 = V_18 -> V_9 ;
V_20 . V_10 = V_18 -> V_10 ;
V_20 . V_23 [ 0 ] = V_18 -> V_24 ;
V_20 . V_25 = F_4 ( V_18 -> V_26 , V_18 -> V_27 ) ;
V_20 . V_28 [ 0 ] = V_18 -> V_29 ;
V_21 = F_5 ( V_13 , & V_20 , V_16 ) ;
if ( V_21 )
return V_21 ;
V_18 -> V_22 = V_20 . V_22 ;
return 0 ;
}
static int F_6 ( int V_9 ,
const struct V_30 * V_31 , int V_32 )
{
if ( V_32 == 0 )
return V_9 ;
return F_7 ( V_9 , V_31 -> V_33 ) ;
}
static int F_8 ( int V_10 ,
const struct V_30 * V_31 , int V_32 )
{
if ( V_32 == 0 )
return V_10 ;
return F_7 ( V_10 , V_31 -> V_34 ) ;
}
static int F_9 ( struct V_12 * V_13 ,
const struct V_19 * V_20 )
{
const struct V_30 * V_35 ;
int V_36 ;
V_35 = F_10 ( V_20 -> V_25 & ~ V_37 ) ;
if ( ! V_35 ) {
struct V_38 V_39 ;
F_2 ( L_3 ,
F_11 ( V_20 -> V_25 ,
& V_39 ) ) ;
return - V_40 ;
}
V_35 = F_12 ( V_13 , V_20 ) ;
if ( V_20 -> V_9 == 0 ) {
F_2 ( L_4 , V_20 -> V_9 ) ;
return - V_40 ;
}
if ( V_20 -> V_10 == 0 ) {
F_2 ( L_5 , V_20 -> V_10 ) ;
return - V_40 ;
}
for ( V_36 = 0 ; V_36 < V_35 -> V_41 ; V_36 ++ ) {
unsigned int V_9 = F_6 ( V_20 -> V_9 , V_35 , V_36 ) ;
unsigned int V_10 = F_8 ( V_20 -> V_10 , V_35 , V_36 ) ;
unsigned int V_42 = V_35 -> V_42 [ V_36 ] ;
if ( ! V_20 -> V_28 [ V_36 ] ) {
F_2 ( L_6 , V_36 ) ;
return - V_40 ;
}
if ( ( V_43 ) V_9 * V_42 > V_44 )
return - V_45 ;
if ( ( V_43 ) V_10 * V_20 -> V_23 [ V_36 ] + V_20 -> V_46 [ V_36 ] > V_44 )
return - V_45 ;
if ( V_20 -> V_23 [ V_36 ] < V_9 * V_42 ) {
F_2 ( L_7 , V_20 -> V_23 [ V_36 ] , V_36 ) ;
return - V_40 ;
}
if ( V_20 -> V_47 [ V_36 ] && ! ( V_20 -> V_48 & V_49 ) ) {
F_2 ( L_8 ,
V_20 -> V_47 [ V_36 ] , V_36 ) ;
return - V_40 ;
}
if ( V_20 -> V_48 & V_49 &&
V_20 -> V_47 [ V_36 ] != V_20 -> V_47 [ 0 ] ) {
F_2 ( L_8 ,
V_20 -> V_47 [ V_36 ] , V_36 ) ;
return - V_40 ;
}
switch ( V_20 -> V_47 [ V_36 ] ) {
case V_50 :
if ( V_20 -> V_25 != V_51 ||
V_9 % 128 || V_10 % 32 ||
V_20 -> V_23 [ V_36 ] % 128 ) {
F_2 ( L_9 , V_36 ) ;
return - V_40 ;
}
break;
default:
break;
}
}
for ( V_36 = V_35 -> V_41 ; V_36 < 4 ; V_36 ++ ) {
if ( V_20 -> V_47 [ V_36 ] ) {
F_2 ( L_10 , V_36 ) ;
return - V_40 ;
}
if ( ! ( V_20 -> V_48 & V_49 ) )
continue;
if ( V_20 -> V_28 [ V_36 ] ) {
F_2 ( L_11 , V_36 ) ;
return - V_40 ;
}
if ( V_20 -> V_23 [ V_36 ] ) {
F_2 ( L_12 , V_36 ) ;
return - V_40 ;
}
if ( V_20 -> V_46 [ V_36 ] ) {
F_2 ( L_13 , V_36 ) ;
return - V_40 ;
}
}
return 0 ;
}
struct V_5 *
F_13 ( struct V_12 * V_13 ,
const struct V_19 * V_20 ,
struct V_15 * V_16 )
{
struct V_52 * V_53 = & V_13 -> V_54 ;
struct V_5 * V_6 ;
int V_21 ;
if ( V_20 -> V_48 & ~ ( V_55 | V_49 ) ) {
F_2 ( L_14 , V_20 -> V_48 ) ;
return F_14 ( - V_40 ) ;
}
if ( ( V_53 -> V_56 > V_20 -> V_9 ) || ( V_20 -> V_9 > V_53 -> V_57 ) ) {
F_2 ( L_15 ,
V_20 -> V_9 , V_53 -> V_56 , V_53 -> V_57 ) ;
return F_14 ( - V_40 ) ;
}
if ( ( V_53 -> V_58 > V_20 -> V_10 ) || ( V_20 -> V_10 > V_53 -> V_59 ) ) {
F_2 ( L_16 ,
V_20 -> V_10 , V_53 -> V_58 , V_53 -> V_59 ) ;
return F_14 ( - V_40 ) ;
}
if ( V_20 -> V_48 & V_49 &&
! V_13 -> V_54 . V_60 ) {
F_2 ( L_17 ) ;
return F_14 ( - V_40 ) ;
}
V_21 = F_9 ( V_13 , V_20 ) ;
if ( V_21 )
return F_14 ( V_21 ) ;
V_6 = V_13 -> V_54 . V_61 -> V_62 ( V_13 , V_16 , V_20 ) ;
if ( F_15 ( V_6 ) ) {
F_2 ( L_18 ) ;
return V_6 ;
}
return V_6 ;
}
int F_5 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_19 * V_20 = V_14 ;
struct V_5 * V_6 ;
if ( ! F_16 ( V_13 , V_63 ) )
return - V_40 ;
V_6 = F_13 ( V_13 , V_20 , V_16 ) ;
if ( F_15 ( V_6 ) )
return F_17 ( V_6 ) ;
F_2 ( L_19 , V_6 -> V_64 . V_65 ) ;
V_20 -> V_22 = V_6 -> V_64 . V_65 ;
F_18 ( & V_16 -> V_66 ) ;
F_19 ( & V_6 -> V_67 , & V_16 -> V_68 ) ;
F_20 ( & V_16 -> V_66 ) ;
return 0 ;
}
static void F_21 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = F_22 ( V_70 , F_23 ( * V_72 ) , V_73 ) ;
while ( ! F_24 ( & V_72 -> V_68 ) ) {
struct V_5 * V_6 =
F_25 ( & V_72 -> V_68 , F_23 ( * V_6 ) , V_67 ) ;
F_26 ( & V_6 -> V_67 ) ;
F_27 ( V_6 ) ;
}
}
int F_28 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_5 * V_6 = NULL ;
struct V_5 * V_74 = NULL ;
T_1 * V_65 = V_14 ;
int V_75 = 0 ;
if ( ! F_16 ( V_13 , V_63 ) )
return - V_40 ;
V_6 = F_29 ( V_13 , * V_65 ) ;
if ( ! V_6 )
return - V_76 ;
F_18 ( & V_16 -> V_66 ) ;
F_30 (fbl, &file_priv->fbs, filp_head)
if ( V_6 == V_74 )
V_75 = 1 ;
if ( ! V_75 ) {
F_20 ( & V_16 -> V_66 ) ;
goto V_77;
}
F_26 ( & V_6 -> V_67 ) ;
F_20 ( & V_16 -> V_66 ) ;
F_31 ( V_6 ) ;
if ( F_32 ( V_6 ) > 1 ) {
struct V_71 V_72 ;
F_33 ( & V_72 . V_73 , F_21 ) ;
F_34 ( & V_72 . V_68 ) ;
F_35 ( & V_6 -> V_67 , & V_72 . V_68 ) ;
F_36 ( & V_72 . V_73 ) ;
F_37 ( & V_72 . V_73 ) ;
F_38 ( & V_72 . V_73 ) ;
} else
F_31 ( V_6 ) ;
return 0 ;
V_77:
F_31 ( V_6 ) ;
return - V_76 ;
}
int F_39 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_20 = V_14 ;
struct V_5 * V_6 ;
int V_21 ;
if ( ! F_16 ( V_13 , V_63 ) )
return - V_40 ;
V_6 = F_29 ( V_13 , V_20 -> V_22 ) ;
if ( ! V_6 )
return - V_76 ;
V_20 -> V_10 = V_6 -> V_10 ;
V_20 -> V_9 = V_6 -> V_9 ;
V_20 -> V_27 = V_6 -> V_31 -> V_27 ;
V_20 -> V_26 = V_6 -> V_31 -> V_42 [ 0 ] * 8 ;
V_20 -> V_24 = V_6 -> V_23 [ 0 ] ;
if ( V_6 -> V_61 -> V_78 ) {
if ( F_40 ( V_16 ) || F_41 ( V_79 ) ||
F_42 ( V_16 ) ) {
V_21 = V_6 -> V_61 -> V_78 ( V_6 , V_16 ,
& V_20 -> V_29 ) ;
} else {
V_20 -> V_29 = 0 ;
V_21 = 0 ;
}
} else {
V_21 = - V_80 ;
}
F_31 ( V_6 ) ;
return V_21 ;
}
int F_43 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_81 T_2 * V_82 ;
struct V_81 * V_83 = NULL ;
struct V_84 * V_20 = V_14 ;
struct V_5 * V_6 ;
unsigned V_48 ;
int V_85 ;
int V_21 ;
if ( ! F_16 ( V_13 , V_63 ) )
return - V_40 ;
V_6 = F_29 ( V_13 , V_20 -> V_22 ) ;
if ( ! V_6 )
return - V_76 ;
V_85 = V_20 -> V_85 ;
V_82 = (struct V_81 T_2 * ) ( unsigned long ) V_20 -> V_82 ;
if ( ! V_85 != ! V_82 ) {
V_21 = - V_40 ;
goto V_86;
}
V_48 = V_87 & V_20 -> V_48 ;
if ( V_48 & V_88 && ( V_85 % 2 ) ) {
V_21 = - V_40 ;
goto V_86;
}
if ( V_85 && V_82 ) {
if ( V_85 < 0 || V_85 > V_89 ) {
V_21 = - V_40 ;
goto V_86;
}
V_83 = F_44 ( V_85 , sizeof( * V_83 ) , V_90 ) ;
if ( ! V_83 ) {
V_21 = - V_91 ;
goto V_86;
}
V_21 = F_45 ( V_83 , V_82 ,
V_85 * sizeof( * V_83 ) ) ;
if ( V_21 ) {
V_21 = - V_92 ;
goto V_93;
}
}
if ( V_6 -> V_61 -> V_94 ) {
V_21 = V_6 -> V_61 -> V_94 ( V_6 , V_16 , V_48 , V_20 -> V_95 ,
V_83 , V_85 ) ;
} else {
V_21 = - V_96 ;
}
V_93:
F_46 ( V_83 ) ;
V_86:
F_31 ( V_6 ) ;
return V_21 ;
}
void F_47 ( struct V_15 * V_97 )
{
struct V_5 * V_6 , * V_98 ;
struct V_71 V_72 ;
F_34 ( & V_72 . V_68 ) ;
F_48 (fb, tfb, &priv->fbs, filp_head) {
if ( F_32 ( V_6 ) > 1 ) {
F_49 ( & V_6 -> V_67 , & V_72 . V_68 ) ;
} else {
F_26 ( & V_6 -> V_67 ) ;
F_31 ( V_6 ) ;
}
}
if ( ! F_24 ( & V_72 . V_68 ) ) {
F_33 ( & V_72 . V_73 , F_21 ) ;
F_36 ( & V_72 . V_73 ) ;
F_37 ( & V_72 . V_73 ) ;
F_38 ( & V_72 . V_73 ) ;
}
}
void F_50 ( struct V_99 * V_99 )
{
struct V_5 * V_6 =
F_22 ( V_99 , struct V_5 , V_64 . V_100 ) ;
struct V_12 * V_13 = V_6 -> V_13 ;
F_51 ( V_13 , & V_6 -> V_64 ) ;
V_6 -> V_61 -> V_101 ( V_6 ) ;
}
int F_52 ( struct V_12 * V_13 , struct V_5 * V_6 ,
const struct V_102 * V_61 )
{
int V_21 ;
if ( F_53 ( V_6 -> V_13 != V_13 || ! V_6 -> V_31 ) )
return - V_40 ;
F_34 ( & V_6 -> V_67 ) ;
V_6 -> V_61 = V_61 ;
V_21 = F_54 ( V_13 , & V_6 -> V_64 , V_103 ,
false , F_50 ) ;
if ( V_21 )
goto V_104;
F_18 ( & V_13 -> V_54 . V_105 ) ;
V_13 -> V_54 . V_106 ++ ;
F_19 ( & V_6 -> V_107 , & V_13 -> V_54 . V_108 ) ;
F_20 ( & V_13 -> V_54 . V_105 ) ;
F_55 ( V_13 , & V_6 -> V_64 ) ;
V_104:
return V_21 ;
}
struct V_5 * F_29 ( struct V_12 * V_13 ,
T_1 V_65 )
{
struct V_109 * V_110 ;
struct V_5 * V_6 = NULL ;
V_110 = F_56 ( V_13 , V_65 , V_103 ) ;
if ( V_110 )
V_6 = F_57 ( V_110 ) ;
return V_6 ;
}
void F_58 ( struct V_5 * V_6 )
{
struct V_12 * V_13 ;
if ( ! V_6 )
return;
V_13 = V_6 -> V_13 ;
F_51 ( V_13 , & V_6 -> V_64 ) ;
}
void F_59 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = V_6 -> V_13 ;
F_18 ( & V_13 -> V_54 . V_105 ) ;
F_60 ( & V_6 -> V_107 ) ;
V_13 -> V_54 . V_106 -- ;
F_20 ( & V_13 -> V_54 . V_105 ) ;
}
static int F_61 ( struct V_5 * V_6 )
{
struct V_111 V_112 ;
struct V_12 * V_13 = V_6 -> V_13 ;
struct V_113 * V_114 ;
struct V_115 * V_32 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
int V_36 , V_21 = 0 ;
unsigned V_120 ;
V_114 = F_62 ( V_13 ) ;
if ( ! V_114 )
return - V_91 ;
F_63 ( & V_112 , 0 ) ;
V_114 -> V_121 = & V_112 ;
V_122:
V_120 = 0 ;
V_21 = F_64 ( V_13 , & V_112 ) ;
if ( V_21 )
goto V_123;
F_65 (plane, dev) {
struct V_124 * V_125 ;
if ( V_32 -> V_114 -> V_6 != V_6 )
continue;
V_125 = F_66 ( V_114 , V_32 ) ;
if ( F_15 ( V_125 ) ) {
V_21 = F_17 ( V_125 ) ;
goto V_123;
}
if ( V_125 -> V_126 -> V_127 == V_32 ) {
struct V_128 * V_129 ;
V_129 = F_67 ( V_114 , V_125 -> V_126 ) ;
V_21 = F_68 ( V_114 , V_125 -> V_126 ) ;
if ( V_21 )
goto V_123;
V_129 -> V_130 = false ;
V_21 = F_69 ( V_129 , NULL ) ;
if ( V_21 )
goto V_123;
}
F_70 ( V_125 , NULL ) ;
V_21 = F_71 ( V_125 , NULL ) ;
if ( V_21 )
goto V_123;
V_120 |= F_72 ( F_73 ( V_32 ) ) ;
V_32 -> V_131 = V_32 -> V_6 ;
}
F_74 (state, conn, conn_state, i) {
V_21 = F_75 ( V_119 , NULL ) ;
if ( V_21 )
goto V_123;
}
if ( V_120 )
V_21 = F_76 ( V_114 ) ;
V_123:
if ( V_120 )
F_77 ( V_13 , V_120 , V_21 ) ;
if ( V_21 == - V_132 ) {
F_78 ( & V_112 ) ;
goto V_122;
}
F_79 ( V_114 ) ;
F_80 ( & V_112 ) ;
F_81 ( & V_112 ) ;
return V_21 ;
}
static void F_82 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = V_6 -> V_13 ;
struct V_133 * V_126 ;
struct V_115 * V_32 ;
F_83 ( V_13 ) ;
F_84 (crtc, dev) {
if ( V_126 -> V_127 -> V_6 == V_6 ) {
if ( F_85 ( V_126 ) )
F_86 ( L_20 , V_126 ) ;
}
}
F_65 (plane, dev) {
if ( V_32 -> V_6 == V_6 )
F_87 ( V_32 ) ;
}
F_88 ( V_13 ) ;
}
void F_27 ( struct V_5 * V_6 )
{
struct V_12 * V_13 ;
if ( ! V_6 )
return;
V_13 = V_6 -> V_13 ;
F_89 ( ! F_24 ( & V_6 -> V_67 ) ) ;
if ( F_32 ( V_6 ) > 1 ) {
if ( F_90 ( V_13 ) ) {
int V_21 = F_61 ( V_6 ) ;
F_91 ( V_21 , L_21 , V_21 ) ;
} else
F_82 ( V_6 ) ;
}
F_31 ( V_6 ) ;
}
int F_92 ( int V_9 ,
const struct V_5 * V_6 , int V_32 )
{
if ( V_32 >= V_6 -> V_31 -> V_41 )
return 0 ;
return F_6 ( V_9 , V_6 -> V_31 , V_32 ) ;
}
int F_93 ( int V_10 ,
const struct V_5 * V_6 , int V_32 )
{
if ( V_32 >= V_6 -> V_31 -> V_41 )
return 0 ;
return F_8 ( V_10 , V_6 -> V_31 , V_32 ) ;
}
