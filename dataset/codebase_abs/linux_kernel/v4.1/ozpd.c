void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
V_2 -> V_3 = V_3 ;
switch ( V_3 ) {
case V_4 :
F_2 ( V_2 , V_5 , L_1 ) ;
break;
case V_6 :
F_2 ( V_2 , V_5 , L_2 ) ;
break;
case V_7 :
F_2 ( V_2 , V_5 , L_3 ) ;
break;
case V_8 :
F_2 ( V_2 , V_5 , L_4 ) ;
break;
}
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_9 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( F_6 ( & V_2 -> V_9 ) )
F_7 ( V_2 ) ;
}
struct V_1 * F_8 ( const T_1 * V_10 )
{
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_9 ( sizeof( struct V_1 ) , V_12 ) ;
if ( ! V_2 )
return NULL ;
F_10 ( & V_2 -> V_9 , 2 ) ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
F_11 ( & V_2 -> V_14 [ V_11 ] ) ;
V_2 -> V_15 = 0xffffffff ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_16 = V_17 ;
F_12 ( V_2 -> V_10 , V_10 ) ;
F_13 ( & V_2 -> V_18 ) ;
F_11 ( & V_2 -> V_19 ) ;
F_14 ( & V_2 -> V_20 ) ;
F_14 ( & V_2 -> V_21 ) ;
V_2 -> V_22 = & V_2 -> V_20 ;
F_11 ( & V_2 -> V_23 ) ;
F_14 ( & V_2 -> V_24 ) ;
F_15 ( & V_2 -> V_25 , V_26 ,
( unsigned long ) V_2 ) ;
F_15 ( & V_2 -> V_27 , V_28 ,
( unsigned long ) V_2 ) ;
F_16 ( & V_2 -> V_29 , V_30 , V_31 ) ;
F_16 ( & V_2 -> V_32 , V_30 , V_31 ) ;
V_2 -> V_29 . V_33 = V_34 ;
V_2 -> V_32 . V_33 = V_35 ;
return V_2 ;
}
static void F_17 ( struct V_36 * V_37 )
{
struct V_38 * V_39 , * V_40 ;
struct V_1 * V_2 ;
F_2 ( V_2 , V_5 , L_5 ) ;
V_2 = F_18 ( V_37 , struct V_1 , V_41 ) ;
F_19 ( & V_2 -> V_25 ) ;
F_19 ( & V_2 -> V_27 ) ;
F_20 (e, n, &pd->stream_list)
F_21 ( F_22 ( V_39 , struct V_42 , V_43 ) ) ;
F_20 (e, n, &pd->tx_queue) {
struct V_44 * V_45 = F_22 ( V_39 , struct V_44 , V_43 ) ;
if ( V_45 -> V_46 != NULL )
F_23 ( V_45 -> V_46 ) ;
F_24 ( V_2 , V_45 ) ;
}
F_25 ( & V_2 -> V_18 ) ;
F_20 (e, n, &pd->farewell_list)
F_26 ( F_22 ( V_39 , struct V_47 , V_43 ) ) ;
if ( V_2 -> V_48 )
F_27 ( V_2 -> V_48 ) ;
F_26 ( V_2 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( F_28 ( & V_2 -> V_32 ) )
F_29 ( & V_2 -> V_32 ) ;
if ( F_28 ( & V_2 -> V_29 ) )
F_29 ( & V_2 -> V_29 ) ;
F_30 ( & V_2 -> V_41 , F_17 ) ;
if ( ! F_31 ( & V_2 -> V_41 ) )
F_2 ( V_2 , V_5 , L_6 ) ;
}
int F_32 ( struct V_1 * V_2 , T_2 V_49 , int V_50 )
{
int V_11 , V_51 = 0 ;
F_2 ( V_2 , V_5 , L_7 , V_52 , V_49 , V_50 ) ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
if ( V_53 [ V_11 ] . V_54 && ( V_49 & ( 1 << V_11 ) ) ) {
if ( V_53 [ V_11 ] . V_54 ( V_2 , V_50 ) ) {
V_51 = - 1 ;
F_2 ( V_2 , V_5 ,
L_8 , V_11 ) ;
break;
}
F_33 ( & V_55 ) ;
V_2 -> V_56 |= ( 1 << V_11 ) ;
if ( V_50 )
V_2 -> V_57 &= ~ ( 1 << V_11 ) ;
F_34 ( & V_55 ) ;
}
}
return V_51 ;
}
void F_35 ( struct V_1 * V_2 , T_2 V_49 , int V_58 )
{
int V_11 ;
F_2 ( V_2 , V_5 , L_9 , V_52 , V_49 , V_58 ) ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
if ( V_53 [ V_11 ] . V_59 && ( V_49 & ( 1 << V_11 ) ) ) {
F_33 ( & V_55 ) ;
if ( V_58 ) {
V_2 -> V_57 |= ( 1 << V_11 ) ;
} else {
V_2 -> V_56 &= ~ ( 1 << V_11 ) ;
V_2 -> V_57 &= ~ ( 1 << V_11 ) ;
}
F_34 ( & V_55 ) ;
V_53 [ V_11 ] . V_59 ( V_2 , V_58 ) ;
}
}
}
void F_36 ( struct V_1 * V_2 , T_2 V_49 )
{
int V_11 , V_60 = 0 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
if ( V_53 [ V_11 ] . V_29 && ( V_49 & ( 1 << V_11 ) ) ) {
if ( V_53 [ V_11 ] . V_29 ( V_2 ) )
V_60 = 1 ;
}
}
if ( ( ! V_60 ) && ( F_28 ( & V_2 -> V_29 ) ) )
F_29 ( & V_2 -> V_29 ) ;
if ( V_2 -> V_61 & V_62 ) {
int V_63 = 8 ;
while ( V_63 -- && ( F_37 ( V_2 ) >= 0 ) )
;
}
}
void F_38 ( struct V_1 * V_2 )
{
T_2 V_64 ;
F_39 ( V_5 , L_10 , V_2 -> V_3 ) ;
F_40 ( V_2 ) ;
F_33 ( & V_55 ) ;
V_64 = V_2 -> V_56 ;
V_2 -> V_56 = 0 ;
V_2 -> V_57 = 0 ;
F_34 ( & V_55 ) ;
F_35 ( V_2 , V_64 , 0 ) ;
F_33 ( & V_55 ) ;
F_1 ( V_2 , V_7 ) ;
F_41 ( & V_2 -> V_43 ) ;
F_34 ( & V_55 ) ;
F_39 ( V_5 , L_11 , F_42 ( & V_2 -> V_9 ) ) ;
F_5 ( V_2 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
int V_65 = 0 ;
T_2 V_64 ;
F_33 ( & V_55 ) ;
if ( V_2 -> V_3 & ( V_8 | V_7 ) ) {
F_34 ( & V_55 ) ;
return 0 ;
}
if ( V_2 -> V_66 && V_2 -> V_67 )
F_1 ( V_2 , V_8 ) ;
else
V_65 = 1 ;
V_64 = V_2 -> V_56 ;
F_34 ( & V_55 ) ;
if ( V_65 ) {
F_38 ( V_2 ) ;
} else {
F_35 ( V_2 , V_64 , 1 ) ;
F_44 ( V_2 , V_68 , V_2 -> V_66 ) ;
}
return V_65 ;
}
static struct V_44 * F_45 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
V_45 = F_46 ( V_69 , V_12 ) ;
if ( V_45 ) {
V_45 -> V_70 = sizeof( struct V_71 ) ;
F_14 ( & V_45 -> V_43 ) ;
F_14 ( & V_45 -> V_72 ) ;
}
return V_45 ;
}
static void F_47 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
V_2 -> V_73 -- ;
F_48 ( & V_45 -> V_43 ) ;
F_49 ( V_69 , V_45 ) ;
F_39 ( V_74 , L_12 ,
V_2 -> V_73 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
F_49 ( V_69 , V_45 ) ;
}
static void F_51 ( struct V_75 * V_46 )
{
struct V_71 * V_71 = (struct V_71 * ) F_52 ( V_46 ) ;
V_71 -> V_76 |= V_77 ;
}
static void F_53 ( struct V_1 * V_2 , struct V_75 * V_46 )
{
struct V_71 * V_71 = (struct V_71 * ) F_52 ( V_46 ) ;
V_71 -> V_78 = V_2 -> V_79 & V_80 ;
}
int F_54 ( struct V_1 * V_2 , int V_81 )
{
struct V_44 * V_45 ;
if ( ( V_2 -> V_61 & V_82 ) != V_83 )
return - 1 ;
if ( V_2 -> V_84 >= V_85 )
return - 1 ;
if ( ! V_81 && ! F_55 ( & V_2 -> V_18 ) )
return - 1 ;
V_45 = F_45 ( V_2 ) ;
if ( V_45 == NULL )
return - 1 ;
V_45 -> V_46 = NULL ;
V_45 -> V_86 . V_76 =
( V_87 << V_88 ) | V_89 ;
++ V_2 -> V_90 ;
F_56 ( F_57 ( V_2 -> V_90 ) , & V_45 -> V_86 . V_91 ) ;
if ( V_81 == 0 ) {
F_58 ( & V_2 -> V_18 , 0 , & V_45 -> V_70 ,
V_2 -> V_16 , & V_45 -> V_72 ) ;
}
F_59 ( & V_2 -> V_19 ) ;
F_60 ( & V_45 -> V_43 , & V_2 -> V_20 ) ;
V_2 -> V_84 ++ ;
F_61 ( & V_2 -> V_19 ) ;
return 0 ;
}
static struct V_75 * F_62 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_75 * V_46 ;
struct V_92 * V_93 = V_2 -> V_48 ;
struct V_71 * V_71 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
V_46 = F_63 ( V_45 -> V_70 + F_64 ( V_93 ) , V_12 ) ;
if ( V_46 == NULL )
return NULL ;
F_65 ( V_46 , F_66 ( V_93 ) ) ;
F_67 ( V_46 ) ;
V_46 -> V_93 = V_93 ;
V_46 -> V_98 = F_68 ( V_99 ) ;
if ( F_69 ( V_46 , V_93 , V_99 , V_2 -> V_10 ,
V_93 -> V_100 , V_46 -> V_101 ) < 0 )
goto V_102;
V_71 = (struct V_71 * ) F_70 ( V_46 , V_45 -> V_70 ) ;
V_45 -> V_86 . V_78 = V_2 -> V_79 & V_80 ;
memcpy ( V_71 , & V_45 -> V_86 , sizeof( struct V_71 ) ) ;
V_95 = (struct V_94 * ) ( V_71 + 1 ) ;
F_71 (ei, &f->elt_list, link) {
memcpy ( V_95 , V_97 -> V_103 , V_97 -> V_104 ) ;
V_95 = F_72 ( V_95 ) ;
}
return V_46 ;
V_102:
F_23 ( V_46 ) ;
return NULL ;
}
static void F_24 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_96 * V_97 , * V_40 ;
F_73 (ei, n, &f->elt_list, link) {
F_48 ( & V_97 -> V_43 ) ;
if ( V_97 -> V_105 )
V_97 -> V_105 ( V_2 , V_97 -> V_106 ) ;
F_33 ( & V_2 -> V_18 . V_107 ) ;
F_74 ( & V_2 -> V_18 , V_97 ) ;
F_34 ( & V_2 -> V_18 . V_107 ) ;
}
F_50 ( V_2 , V_45 ) ;
}
static int F_75 ( struct V_1 * V_2 , int V_108 )
{
struct V_75 * V_46 ;
struct V_44 * V_45 ;
struct V_38 * V_39 ;
F_59 ( & V_2 -> V_19 ) ;
V_39 = V_2 -> V_22 -> V_109 ;
if ( V_39 == & V_2 -> V_20 ) {
F_61 ( & V_2 -> V_19 ) ;
return - 1 ;
}
V_45 = F_22 ( V_39 , struct V_44 , V_43 ) ;
if ( V_45 -> V_46 != NULL ) {
V_46 = V_45 -> V_46 ;
F_47 ( V_2 , V_45 ) ;
F_61 ( & V_2 -> V_19 ) ;
if ( V_108 )
F_51 ( V_46 ) ;
F_53 ( V_2 , V_46 ) ;
if ( ( int ) F_42 ( & V_110 ) <
V_111 ) {
if ( F_76 ( V_46 ) < 0 ) {
F_39 ( V_74 , L_13 ) ;
return - 1 ;
}
F_4 ( & V_110 ) ;
F_39 ( V_74 , L_14 ,
V_2 -> V_73 ) ;
return 0 ;
}
F_23 ( V_46 ) ;
F_39 ( V_74 , L_15 ) ;
return - 1 ;
}
V_2 -> V_22 = V_39 ;
V_46 = F_62 ( V_2 , V_45 ) ;
F_61 ( & V_2 -> V_19 ) ;
if ( ! V_46 )
return - 1 ;
if ( V_108 )
F_51 ( V_46 ) ;
F_39 ( V_74 , L_16 , V_45 -> V_86 . V_91 ) ;
if ( F_76 ( V_46 ) < 0 )
return - 1 ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 , int V_112 )
{
while ( F_54 ( V_2 , 0 ) >= 0 )
V_112 ++ ;
switch ( V_2 -> V_61 & ( V_113 | V_62 ) ) {
case V_113 : {
V_112 += V_2 -> V_73 ;
if ( V_112 <= 0 )
goto V_114;
if ( V_112 > V_111 )
V_112 = V_111 ;
break;
}
case V_115 : {
if ( ( V_112 <= 0 ) && ( V_2 -> V_116 == 0 ) )
goto V_114;
break;
}
default: {
if ( V_112 <= 0 )
goto V_114;
break;
}
}
while ( V_112 -- ) {
if ( F_75 ( V_2 , V_112 ) < 0 )
break;
}
return;
V_114: F_54 ( V_2 , 1 ) ;
F_75 ( V_2 , 0 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_75 * V_46 ;
struct V_92 * V_93 = V_2 -> V_48 ;
struct V_71 * V_71 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
F_78 ( V_117 ) ;
int V_70 = sizeof( struct V_71 ) ;
F_58 ( & V_2 -> V_18 , 1 , & V_70 ,
V_2 -> V_16 , & V_117 ) ;
if ( F_79 ( & V_117 ) )
return 0 ;
V_46 = F_63 ( V_70 + F_64 ( V_93 ) , V_12 ) ;
if ( V_46 == NULL ) {
F_39 ( V_5 , L_17 ) ;
F_80 ( & V_2 -> V_18 , & V_117 ) ;
return - 1 ;
}
F_65 ( V_46 , F_66 ( V_93 ) ) ;
F_67 ( V_46 ) ;
V_46 -> V_93 = V_93 ;
V_46 -> V_98 = F_68 ( V_99 ) ;
if ( F_69 ( V_46 , V_93 , V_99 , V_2 -> V_10 ,
V_93 -> V_100 , V_46 -> V_101 ) < 0 ) {
F_23 ( V_46 ) ;
return - 1 ;
}
V_71 = (struct V_71 * ) F_70 ( V_46 , V_70 ) ;
V_71 -> V_76 = ( V_87 << V_88 ) | V_118 ;
V_71 -> V_78 = V_2 -> V_79 & V_80 ;
V_95 = (struct V_94 * ) ( V_71 + 1 ) ;
F_71 (ei, &list, link) {
memcpy ( V_95 , V_97 -> V_103 , V_97 -> V_104 ) ;
V_95 = F_72 ( V_95 ) ;
}
F_76 ( V_46 ) ;
F_80 ( & V_2 -> V_18 , & V_117 ) ;
return 0 ;
}
void F_81 ( struct V_1 * V_2 , T_1 V_119 )
{
struct V_44 * V_45 , * V_120 = NULL ;
T_1 V_121 ;
T_3 V_91 ;
F_78 ( V_117 ) ;
F_59 ( & V_2 -> V_19 ) ;
F_71 (f, &pd->tx_queue, link) {
V_91 = F_82 ( F_83 ( & V_45 -> V_86 . V_91 ) ) ;
V_121 = ( V_119 - ( V_91 & V_80 ) ) & V_80 ;
if ( ( V_121 > V_122 ) || ( V_91 == 0 ) )
break;
F_39 ( V_74 , L_18 ,
V_91 , V_2 -> V_84 ) ;
V_120 = V_45 ;
V_2 -> V_84 -- ;
}
if ( V_120 )
F_84 ( & V_117 , & V_2 -> V_20 , & V_120 -> V_43 ) ;
V_2 -> V_22 = & V_2 -> V_20 ;
F_61 ( & V_2 -> V_19 ) ;
F_73 (f, tmp, &list, link)
F_24 ( V_2 , V_45 ) ;
}
static struct V_42 * F_85 ( struct V_1 * V_2 , T_1 V_123 )
{
struct V_42 * V_124 ;
F_71 (st, &pd->stream_list, link) {
if ( V_124 -> V_123 == V_123 )
return V_124 ;
}
return NULL ;
}
int F_86 ( struct V_1 * V_2 , T_1 V_123 )
{
struct V_42 * V_124 ;
V_124 = F_9 ( sizeof( struct V_42 ) , V_12 ) ;
if ( ! V_124 )
return - V_125 ;
V_124 -> V_123 = V_123 ;
F_33 ( & V_2 -> V_23 ) ;
if ( ! F_85 ( V_2 , V_123 ) ) {
F_87 ( & V_124 -> V_43 , & V_2 -> V_24 ) ;
V_124 = NULL ;
}
F_34 ( & V_2 -> V_23 ) ;
F_26 ( V_124 ) ;
return 0 ;
}
static void F_21 ( struct V_42 * V_124 )
{
F_23 ( V_124 -> V_46 ) ;
F_26 ( V_124 ) ;
}
int F_88 ( struct V_1 * V_2 , T_1 V_123 )
{
struct V_42 * V_124 ;
F_33 ( & V_2 -> V_23 ) ;
V_124 = F_85 ( V_2 , V_123 ) ;
if ( V_124 )
F_41 ( & V_124 -> V_43 ) ;
F_34 ( & V_2 -> V_23 ) ;
if ( V_124 )
F_21 ( V_124 ) ;
return 0 ;
}
static void F_89 ( struct V_75 * V_46 )
{
F_90 ( & V_110 ) ;
}
int F_91 ( struct V_1 * V_2 , T_1 V_123 , const T_1 * V_103 , int V_101 )
{
struct V_92 * V_93 = V_2 -> V_48 ;
struct V_42 * V_124 ;
T_1 V_126 = 0 ;
struct V_75 * V_46 = NULL ;
struct V_71 * V_71 = NULL ;
int V_127 = 0 ;
F_33 ( & V_2 -> V_23 ) ;
V_124 = F_85 ( V_2 , V_123 ) ;
if ( V_124 ) {
V_46 = V_124 -> V_46 ;
V_124 -> V_46 = NULL ;
V_126 = V_124 -> V_126 ;
V_124 -> V_126 = 0 ;
V_71 = V_124 -> V_71 ;
V_127 = V_124 -> V_127 ;
}
F_34 ( & V_2 -> V_23 ) ;
if ( ! V_124 )
return 0 ;
if ( ! V_46 ) {
V_46 = F_63 ( V_2 -> V_16 + F_64 ( V_93 ) ,
V_12 ) ;
if ( V_46 == NULL )
return 0 ;
F_65 ( V_46 , F_66 ( V_93 ) ) ;
F_67 ( V_46 ) ;
V_46 -> V_93 = V_93 ;
V_46 -> V_98 = F_68 ( V_99 ) ;
V_46 -> V_128 = 0x7 ;
V_127 = sizeof( struct V_71 ) + sizeof( struct V_129 ) ;
V_71 = (struct V_71 * ) F_70 ( V_46 , V_127 ) ;
}
memcpy ( F_70 ( V_46 , V_101 ) , V_103 , V_101 ) ;
V_127 += V_101 ;
if ( ++ V_126 < V_2 -> V_130 ) {
F_33 ( & V_2 -> V_23 ) ;
V_124 -> V_46 = V_46 ;
V_124 -> V_126 = V_126 ;
V_124 -> V_71 = V_71 ;
V_124 -> V_127 = V_127 ;
F_34 ( & V_2 -> V_23 ) ;
} else {
struct V_71 V_131 ;
struct V_129 V_132 ;
F_33 ( & V_2 -> V_23 ) ;
V_132 . V_133 = V_124 -> V_134 ;
V_124 -> V_134 += V_126 ;
F_34 ( & V_2 -> V_23 ) ;
V_131 . V_76 =
( V_87 << V_88 ) | V_118 ;
V_131 . V_78 = V_2 -> V_79 & V_80 ;
V_131 . V_91 = 0 ;
V_132 . V_135 = V_123 ;
V_132 . V_136 = V_137 ;
V_132 . V_138 = V_126 ;
memcpy ( V_71 , & V_131 , sizeof( V_131 ) ) ;
memcpy ( V_71 + 1 , & V_132 , sizeof( V_132 ) ) ;
if ( F_69 ( V_46 , V_93 , V_99 , V_2 -> V_10 ,
V_93 -> V_100 , V_46 -> V_101 ) < 0 )
goto V_114;
V_46 -> V_139 = F_89 ;
if ( ! ( V_2 -> V_61 & V_62 ) ) {
struct V_44 * V_140 = NULL ;
int V_141 = V_2 -> V_73 ;
if ( V_141 >= V_2 -> V_142 ) {
struct V_44 * V_45 ;
F_39 ( V_74 , L_19 ,
V_141 ) ;
F_59 ( & V_2 -> V_19 ) ;
F_71 (f, &pd->tx_queue, link) {
if ( V_45 -> V_46 != NULL ) {
F_47 ( V_2 , V_45 ) ;
break;
}
}
F_61 ( & V_2 -> V_19 ) ;
}
V_140 = F_45 ( V_2 ) ;
if ( V_140 == NULL )
goto V_114;
V_140 -> V_86 = V_131 ;
V_140 -> V_46 = V_46 ;
F_33 ( & V_2 -> V_19 ) ;
F_60 ( & V_140 -> V_43 , & V_2 -> V_20 ) ;
V_2 -> V_73 ++ ;
F_34 ( & V_2 -> V_19 ) ;
F_39 ( V_74 ,
L_20 ,
V_2 -> V_73 , V_2 -> V_84 ) ;
return 0 ;
}
if ( F_42 ( & V_110 ) < V_111 ) {
F_4 ( & V_110 ) ;
if ( F_76 ( V_46 ) < 0 )
return - 1 ;
return 0 ;
}
V_114: F_23 ( V_46 ) ;
return - 1 ;
}
return 0 ;
}
void F_92 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
if ( V_53 [ V_11 ] . V_143 )
V_53 [ V_11 ] . V_143 () ;
}
}
void F_93 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
if ( V_53 [ V_11 ] . V_144 )
V_53 [ V_11 ] . V_144 () ;
}
}
void F_94 ( struct V_1 * V_2 , T_1 V_145 , struct V_94 * V_95 )
{
if ( V_145 < V_13 && V_53 [ V_145 ] . V_146 )
V_53 [ V_145 ] . V_146 ( V_2 , V_95 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_47 * V_45 ;
const struct V_147 * V_148 = & V_53 [ V_149 ] ;
while ( 1 ) {
F_33 ( & V_55 ) ;
if ( F_79 ( & V_2 -> V_21 ) ) {
F_34 ( & V_55 ) ;
break;
}
V_45 = F_95 ( & V_2 -> V_21 ,
struct V_47 , V_43 ) ;
F_41 ( & V_45 -> V_43 ) ;
F_34 ( & V_55 ) ;
if ( V_148 -> V_150 )
V_148 -> V_150 ( V_2 , V_45 -> V_123 , V_45 -> V_151 , V_45 -> V_101 ) ;
F_26 ( V_45 ) ;
}
}
