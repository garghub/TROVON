static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_2 -> V_7 . V_8 = V_2 -> V_9 -> V_8 ;
V_2 -> V_7 . V_10 = V_2 -> V_9 -> V_10 ;
V_2 -> V_7 . V_11 =
( V_2 -> V_9 -> V_12 . V_13 & V_14 ) != 0 ;
F_3 ( V_2 ) ;
F_2 ( V_5 , L_2 , V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_15 * V_16 , * V_17 , * V_18 , * V_19 , * V_20 , * V_21 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
F_5 ( & V_2 -> V_26 ) ;
F_2 ( V_5 , L_3 , V_6 , V_2 -> V_27 ) ;
F_6 (c, n, &port->dmaqueue.list) {
V_23 = F_7 ( V_16 , struct V_22 , V_28 ) ;
F_8 ( V_16 ) ;
F_9 ( V_23 ) ;
}
F_2 ( V_5 , L_4 , V_6 , V_2 -> V_27 ) ;
F_6 (p, q, &port->list_buf_used.list) {
V_25 = F_7 ( V_18 , struct V_24 , V_28 ) ;
F_8 ( V_18 ) ;
F_10 ( V_25 ) ;
}
F_2 ( V_5 , L_5 , V_6 , V_2 -> V_27 ) ;
F_6 (l, v, &port->list_buf_free.list) {
V_25 = F_7 ( V_20 , struct V_24 , V_28 ) ;
F_8 ( V_20 ) ;
F_10 ( V_25 ) ;
}
F_11 ( & V_2 -> V_26 ) ;
F_2 ( V_5 , L_6 , V_6 , V_2 -> V_27 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_29 * V_30 = & V_2 -> V_31 ;
int V_32 = - V_33 , V_34 ;
int V_35 = 0 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_30 -> V_36 = 1440 ;
V_30 -> V_37 = 12 ;
V_30 -> V_37 = 18 ;
V_30 -> V_38 = 1600 ;
V_30 -> V_38 = 1440 ;
V_30 -> V_39 = 2 +
( ( V_30 -> V_37 * V_30 -> V_38 ) / V_40 ) ;
V_30 -> V_41 = 8 ;
V_30 -> V_42 = 0 ;
V_30 -> V_43 = NULL ;
V_30 -> V_44 = NULL ;
V_30 -> V_45 = V_2 -> V_46 . V_47 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_46 . V_47 ; V_34 ++ ) {
V_23 = F_13 ( V_2 ,
V_30 -> V_37 *
V_30 -> V_38 ) ;
if ( ! V_23 ) {
F_14 ( V_48 L_7 ,
V_6 , V_32 ) ;
V_32 = - V_49 ;
goto V_50;
} else {
F_5 ( & V_2 -> V_26 ) ;
F_15 ( & V_23 -> V_28 , & V_2 -> V_51 . V_28 ) ;
F_11 ( & V_2 -> V_26 ) ;
}
}
V_35 = V_30 -> V_37 * V_30 -> V_38 ;
if ( V_52 < 16 )
V_52 = 16 ;
if ( V_52 > 512 )
V_52 = 512 ;
for ( V_34 = 0 ; V_34 < V_52 ; V_34 ++ ) {
V_25 = F_16 ( V_4 , V_35 ) ;
if ( V_25 ) {
F_5 ( & V_2 -> V_26 ) ;
F_15 ( & V_25 -> V_28 , & V_2 -> V_53 . V_28 ) ;
F_11 ( & V_2 -> V_26 ) ;
}
}
V_32 = 0 ;
V_50:
return V_32 ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_54 * V_54 , void * V_55 , T_1 V_13 )
{
struct V_56 * V_57 = V_54 -> V_58 ;
return F_19 ( V_57 -> V_2 -> V_9 , V_13 ) ;
}
static int F_20 ( struct V_54 * V_54 , void * V_55 , T_1 * V_13 )
{
struct V_59 * V_57 = V_54 -> V_58 ;
return F_21 ( V_57 -> V_2 -> V_9 , V_13 ) ;
}
static int F_22 ( struct V_54 * V_54 , void * V_55 , unsigned int * V_34 )
{
struct V_56 * V_57 = V_54 -> V_58 ;
return F_23 ( V_57 -> V_2 -> V_9 , V_34 ) ;
}
static int F_24 ( struct V_54 * V_54 , void * V_55 , unsigned int V_34 )
{
struct V_56 * V_57 = V_54 -> V_58 ;
return F_25 ( V_57 -> V_2 -> V_9 , V_34 ) ;
}
static int F_26 ( struct V_54 * V_54 , void * V_55 ,
struct V_60 * V_61 )
{
struct V_56 * V_57 = V_54 -> V_58 ;
return F_27 ( V_57 -> V_2 -> V_9 , V_61 ) ;
}
static int F_28 ( struct V_54 * V_54 , void * V_55 ,
const struct V_60 * V_61 )
{
struct V_56 * V_57 = V_54 -> V_58 ;
int V_62 = F_29 ( V_57 -> V_2 -> V_9 , V_61 ) ;
if ( V_62 == 0 )
F_17 ( V_57 -> V_2 ) ;
return V_62 ;
}
static int F_30 ( struct V_54 * V_54 , void * V_55 ,
struct V_63 * V_64 )
{
struct V_56 * V_57 = V_54 -> V_58 ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
strcpy ( V_64 -> V_65 , V_4 -> V_66 ) ;
F_31 ( V_64 -> V_67 , V_68 [ V_4 -> V_69 ] . V_66 ,
sizeof( V_64 -> V_67 ) ) ;
sprintf ( V_64 -> V_70 , L_8 , F_32 ( V_4 -> V_71 ) ) ;
V_64 -> V_72 =
V_73 |
V_74 |
V_75 ;
V_64 -> V_76 = V_64 -> V_72 |
V_77 |
V_78 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_62 ;
V_62 = F_34 ( V_2 , V_79 ) ;
if ( ( V_62 != V_80 ) && ( V_62 != V_81 ) ) {
F_14 ( V_48 L_9 ,
V_6 , V_62 ) ;
V_62 = - V_82 ;
} else {
F_2 ( V_5 , L_10 , V_6 ) ;
V_62 = 0 ;
}
return V_62 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_62 ;
V_62 = F_34 ( V_2 , V_83 ) ;
if ( ( V_62 != V_80 ) && ( V_62 != V_81 ) ) {
F_14 ( V_48 L_11 ,
V_6 , V_62 ) ;
V_62 = - V_82 ;
} else {
F_2 ( V_5 , L_12 , V_6 ) ;
V_62 = 0 ;
}
return V_62 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_62 ;
V_62 = F_34 ( V_2 , V_84 ) ;
if ( ( V_62 != V_80 ) && ( V_62 != V_81 ) ) {
F_14 ( V_48 L_13 ,
V_6 , V_62 ) ;
V_62 = - V_82 ;
} else {
F_2 ( V_5 , L_14 , V_6 ) ;
V_62 = 0 ;
}
return V_62 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_15 * V_16 , * V_17 ;
int V_62 ;
F_2 ( V_5 , L_15 , V_6 , V_2 -> V_27 ) ;
V_62 = F_36 ( V_2 ) ;
V_62 = F_35 ( V_2 ) ;
V_62 = F_33 ( V_2 ) ;
F_2 ( V_5 , L_16 , V_6 ,
V_2 -> V_27 ) ;
F_5 ( & V_2 -> V_26 ) ;
F_6 (c, n, &port->dmaqueue.list) {
V_23 = F_7 ( V_16 , struct V_22 , V_28 ) ;
V_23 -> V_85 = V_86 ;
V_23 -> V_87 = 0 ;
}
F_6 (c, n, &port->list_buf_used.list) {
V_25 = F_7 ( V_16 , struct V_24 , V_28 ) ;
V_25 -> V_87 = 0 ;
F_38 ( & V_25 -> V_28 , & V_2 -> V_53 . V_28 ) ;
}
F_11 ( & V_2 -> V_26 ) ;
F_4 ( V_2 ) ;
F_2 ( V_5 , L_17 , V_6 , V_2 -> V_27 ) ;
return V_62 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_32 , V_62 = 0 ;
F_2 ( V_5 , L_15 , V_6 , V_2 -> V_27 ) ;
V_2 -> V_88 = 0 ;
F_12 ( V_2 ) ;
#if 0
saa7164_api_set_encoder(port);
saa7164_api_get_encoder(port);
#endif
F_40 ( V_2 ) ;
if ( F_41 ( V_2 ) != V_80 ) {
F_14 ( V_48 L_18 , V_6 ) ;
V_62 = - V_82 ;
goto V_89;
}
V_32 = F_34 ( V_2 , V_83 ) ;
if ( ( V_32 != V_80 ) && ( V_32 != V_81 ) ) {
F_14 ( V_48 L_19 ,
V_6 , V_32 ) ;
V_62 = - V_82 ;
goto V_89;
} else
F_2 ( V_5 , L_20 , V_6 ) ;
V_32 = F_34 ( V_2 , V_84 ) ;
if ( ( V_32 != V_80 ) && ( V_32 != V_81 ) ) {
F_14 ( V_48 L_21 ,
V_6 , V_32 ) ;
V_32 = F_33 ( V_2 ) ;
if ( V_32 != V_80 ) {
F_14 ( V_48 L_22 ,
V_6 , V_32 ) ;
}
V_62 = - V_82 ;
goto V_89;
} else
F_2 ( V_5 , L_14 , V_6 ) ;
V_32 = F_34 ( V_2 , V_90 ) ;
if ( ( V_32 != V_80 ) && ( V_32 != V_81 ) ) {
F_14 ( V_48 L_23 ,
V_6 , V_32 ) ;
V_32 = F_35 ( V_2 ) ;
V_32 = F_33 ( V_2 ) ;
if ( V_32 != V_80 ) {
F_14 ( V_48 L_24 ,
V_6 , V_32 ) ;
}
V_62 = - V_82 ;
} else
F_2 ( V_5 , L_25 , V_6 ) ;
V_89:
return V_62 ;
}
static int F_42 ( struct V_54 * V_54 , void * V_55 ,
struct V_91 * V_61 )
{
V_61 -> V_92 . V_93 . V_94 = 1440 ;
V_61 -> V_92 . V_93 . V_95 = 27000000 ;
V_61 -> V_92 . V_93 . V_96 = V_97 ;
V_61 -> V_92 . V_93 . V_98 = 0 ;
V_61 -> V_92 . V_93 . V_85 = 0 ;
V_61 -> V_92 . V_93 . V_99 [ 0 ] = 10 ;
V_61 -> V_92 . V_93 . V_100 [ 0 ] = 18 ;
V_61 -> V_92 . V_93 . V_99 [ 1 ] = 263 + 10 + 1 ;
V_61 -> V_92 . V_93 . V_100 [ 1 ] = 18 ;
memset ( V_61 -> V_92 . V_93 . V_101 , 0 , sizeof( V_61 -> V_92 . V_93 . V_101 ) ) ;
return 0 ;
}
static int F_43 ( struct V_54 * V_54 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_56 * V_57 ;
V_2 = (struct V_1 * ) F_44 ( F_45 ( V_54 ) ) ;
if ( ! V_2 )
return - V_33 ;
V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_57 = F_46 ( sizeof( * V_57 ) , V_102 ) ;
if ( NULL == V_57 )
return - V_49 ;
V_57 -> V_2 = V_2 ;
F_47 ( & V_57 -> V_57 , F_45 ( V_54 ) ) ;
F_48 ( & V_57 -> V_57 ) ;
V_54 -> V_58 = V_57 ;
return 0 ;
}
static int F_49 ( struct V_54 * V_54 )
{
struct V_56 * V_57 = V_54 -> V_58 ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( F_50 ( & V_57 -> V_103 , 1 , 0 ) == 1 ) {
if ( F_51 ( & V_2 -> V_104 ) == 0 ) {
F_37 ( V_2 ) ;
}
}
F_52 ( & V_57 -> V_57 ) ;
F_53 ( & V_57 -> V_57 ) ;
F_54 ( V_57 ) ;
return 0 ;
}
static struct
V_24 * F_55 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = NULL ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_105 ;
F_5 ( & V_2 -> V_26 ) ;
if ( ! F_56 ( & V_2 -> V_106 . V_28 ) ) {
V_25 = F_57 ( & V_2 -> V_106 . V_28 ,
struct V_24 , V_28 ) ;
if ( V_107 ) {
V_105 = F_58 ( 0 , V_25 -> V_108 , V_25 -> V_109 ) ;
if ( V_105 != V_25 -> V_105 ) {
F_14 ( V_48 L_26 ,
V_6 ,
V_25 , V_25 -> V_105 , V_105 ) ;
}
}
}
F_11 ( & V_2 -> V_26 ) ;
F_2 ( V_5 , L_27 , V_6 , V_25 ) ;
return V_25 ;
}
static T_3 F_59 ( struct V_54 * V_54 , char T_4 * V_110 ,
T_5 V_100 , T_6 * V_87 )
{
struct V_56 * V_57 = V_54 -> V_58 ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_24 * V_25 = NULL ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_62 = 0 ;
int V_111 , V_112 ;
T_7 * V_18 ;
V_2 -> V_113 = V_2 -> V_114 ;
V_2 -> V_114 = F_60 ( V_115 ) ;
V_2 -> V_113 = V_2 -> V_114 -
V_2 -> V_113 ;
F_61 ( & V_2 -> V_116 ,
V_2 -> V_113 ) ;
if ( * V_87 ) {
F_14 ( V_48 L_28 , V_6 ) ;
return - V_117 ;
}
if ( F_50 ( & V_57 -> V_103 , 0 , 1 ) == 0 ) {
if ( F_62 ( & V_2 -> V_104 ) == 1 ) {
if ( F_17 ( V_2 ) < 0 ) {
F_14 ( V_48 L_29 , V_6 ) ;
return - V_118 ;
}
F_39 ( V_2 ) ;
F_63 ( 200 ) ;
}
}
if ( ( V_54 -> V_119 & V_120 ) == 0 ) {
if ( F_64 ( V_2 -> V_121 ,
F_55 ( V_2 ) ) ) {
F_14 ( V_48 L_30 , V_6 ) ;
return - V_122 ;
}
}
V_25 = F_55 ( V_2 ) ;
while ( ( V_100 > 0 ) && V_25 ) {
V_111 = V_25 -> V_109 - V_25 -> V_87 ;
V_112 = V_111 > V_100 ? V_100 : V_111 ;
V_18 = V_25 -> V_108 + V_25 -> V_87 ;
F_2 ( V_5 ,
L_31 ,
V_6 , ( int ) V_100 , V_112 , V_111 , V_25 , V_25 -> V_87 ) ;
if ( F_65 ( V_110 , V_18 , V_112 ) ) {
F_14 ( V_48 L_32 , V_6 ) ;
if ( ! V_62 ) {
F_14 ( V_48 L_33 , V_6 ) ;
V_62 = - V_123 ;
}
goto V_124;
}
V_25 -> V_87 += V_112 ;
V_100 -= V_112 ;
V_110 += V_112 ;
V_62 += V_112 ;
if ( V_25 -> V_87 > V_25 -> V_109 )
F_14 ( V_48 L_34 ) ;
if ( V_25 -> V_87 == V_25 -> V_109 ) {
V_25 -> V_87 = 0 ;
F_5 ( & V_2 -> V_26 ) ;
F_38 ( & V_25 -> V_28 , & V_2 -> V_53 . V_28 ) ;
F_11 ( & V_2 -> V_26 ) ;
if ( ( V_54 -> V_119 & V_120 ) == 0 ) {
if ( F_64 ( V_2 -> V_121 ,
F_55 ( V_2 ) ) ) {
break;
}
}
V_25 = F_55 ( V_2 ) ;
}
}
V_124:
if ( ! V_62 && ! V_25 ) {
F_14 ( V_48 L_35 , V_6 ) ;
V_62 = - V_125 ;
}
return V_62 ;
}
static unsigned int F_66 ( struct V_54 * V_54 , T_8 * V_126 )
{
struct V_56 * V_57 = (struct V_56 * ) V_54 -> V_58 ;
struct V_1 * V_2 = V_57 -> V_2 ;
unsigned int V_127 = 0 ;
V_2 -> V_128 = V_2 -> V_129 ;
V_2 -> V_129 = F_60 ( V_115 ) ;
V_2 -> V_128 = V_2 -> V_129 -
V_2 -> V_128 ;
F_61 ( & V_2 -> V_130 ,
V_2 -> V_128 ) ;
if ( ! F_67 ( V_2 -> V_131 ) )
return - V_82 ;
if ( F_50 ( & V_57 -> V_103 , 0 , 1 ) == 0 ) {
if ( F_62 ( & V_2 -> V_104 ) == 1 ) {
if ( F_17 ( V_2 ) < 0 )
return - V_118 ;
F_39 ( V_2 ) ;
F_63 ( 200 ) ;
}
}
if ( ( V_54 -> V_119 & V_120 ) == 0 ) {
if ( F_64 ( V_2 -> V_121 ,
F_55 ( V_2 ) ) ) {
return - V_122 ;
}
}
if ( ! F_56 ( & V_2 -> V_106 . V_28 ) )
V_127 |= V_132 | V_133 ;
return V_127 ;
}
static struct V_134 * F_68 (
struct V_1 * V_2 ,
struct V_135 * V_71 ,
struct V_134 * V_136 ,
char * type )
{
struct V_134 * V_137 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_137 = F_69 () ;
if ( NULL == V_137 )
return NULL ;
* V_137 = * V_136 ;
snprintf ( V_137 -> V_66 , sizeof( V_137 -> V_66 ) , L_36 , V_4 -> V_66 ,
type , V_68 [ V_4 -> V_69 ] . V_66 ) ;
V_137 -> V_138 = & V_4 -> V_138 ;
V_137 -> V_139 = V_140 ;
return V_137 ;
}
int F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_32 = - V_33 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( V_2 -> type != V_141 )
F_71 () ;
if ( V_2 -> V_46 . V_142 == 0 ) {
F_14 ( V_48 L_37 ,
V_6 , V_32 ) ;
V_32 = - V_49 ;
goto V_50;
}
V_2 -> V_131 = F_68 ( V_2 ,
V_4 -> V_71 , & V_143 , L_38 ) ;
if ( ! V_2 -> V_131 ) {
F_14 ( V_144 L_39 ,
V_4 -> V_66 ) ;
V_32 = - V_49 ;
goto V_50;
}
V_2 -> V_9 = & V_4 -> V_145 [ V_2 -> V_27 - 2 ] ;
F_72 ( V_2 -> V_131 , V_2 ) ;
V_32 = F_73 ( V_2 -> V_131 ,
V_146 , - 1 ) ;
if ( V_32 < 0 ) {
F_14 ( V_144 L_40 ,
V_4 -> V_66 ) ;
goto V_50;
}
F_14 ( V_144 L_41 ,
V_4 -> V_66 , V_2 -> V_131 -> V_147 ) ;
V_32 = 0 ;
V_50:
return V_32 ;
}
void F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_15 , V_6 , V_2 -> V_27 ) ;
if ( V_2 -> type != V_141 )
F_71 () ;
if ( V_2 -> V_131 ) {
if ( V_2 -> V_131 -> V_148 != - 1 )
F_75 ( V_2 -> V_131 ) ;
else
V_140 ( V_2 -> V_131 ) ;
V_2 -> V_131 = NULL ;
}
}
