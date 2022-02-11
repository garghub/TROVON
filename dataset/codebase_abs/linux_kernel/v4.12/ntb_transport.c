static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! strncmp ( F_2 ( V_2 ) , V_4 -> V_5 , strlen ( V_4 -> V_5 ) ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
const struct V_6 * V_7 ;
int V_8 = - V_9 ;
F_4 ( V_2 ) ;
V_7 = F_5 ( V_2 -> V_10 ) ;
V_8 = V_7 -> V_11 ( V_2 ) ;
if ( V_8 )
F_6 ( V_2 ) ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 )
{
const struct V_6 * V_7 ;
V_7 = F_5 ( V_2 -> V_10 ) ;
V_7 -> remove ( V_2 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_12 * V_13 )
{
F_9 ( & V_13 -> V_14 , & V_15 ) ;
return 0 ;
}
static void F_10 ( struct V_12 * V_13 )
{
struct V_16 * V_17 , * V_18 ;
F_11 (client_dev, cd, &nt->client_devs, entry) {
F_12 ( V_17 -> V_2 . V_19 , L_1 ,
F_2 ( & V_17 -> V_2 ) ) ;
F_13 ( & V_17 -> V_14 ) ;
F_14 ( & V_17 -> V_2 ) ;
}
F_13 ( & V_13 -> V_14 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_16 ( V_2 ) ;
F_17 ( V_17 ) ;
}
void F_18 ( char * V_20 )
{
struct V_16 * V_7 , * V_18 ;
struct V_12 * V_13 ;
F_19 (nt, &ntb_transport_list, entry)
F_11 (client, cd, &nt->client_devs, entry)
if ( ! strncmp ( F_2 ( & V_7 -> V_2 ) , V_20 ,
strlen ( V_20 ) ) ) {
F_13 ( & V_7 -> V_14 ) ;
F_14 ( & V_7 -> V_2 ) ;
}
}
int F_20 ( char * V_20 )
{
struct V_16 * V_17 ;
struct V_12 * V_13 ;
int V_21 ;
int V_8 , V_22 = 0 ;
if ( F_21 ( & V_15 ) )
return - V_23 ;
F_19 (nt, &ntb_transport_list, entry) {
struct V_1 * V_2 ;
V_21 = F_22 ( & V_13 -> V_24 -> V_2 ) ;
V_17 = F_23 ( sizeof( * V_17 ) ,
V_25 , V_21 ) ;
if ( ! V_17 ) {
V_8 = - V_26 ;
goto V_27;
}
V_2 = & V_17 -> V_2 ;
F_24 ( V_2 , L_2 , V_20 , V_22 ) ;
V_2 -> V_28 = & V_29 ;
V_2 -> V_30 = F_15 ;
V_2 -> V_19 = & V_13 -> V_24 -> V_2 ;
V_8 = F_25 ( V_2 ) ;
if ( V_8 ) {
F_17 ( V_17 ) ;
goto V_27;
}
F_9 ( & V_17 -> V_14 , & V_13 -> V_31 ) ;
V_22 ++ ;
}
return 0 ;
V_27:
F_18 ( V_20 ) ;
return V_8 ;
}
int F_26 ( struct V_6 * V_4 )
{
V_4 -> V_10 . V_28 = & V_29 ;
if ( F_21 ( & V_15 ) )
return - V_23 ;
return F_27 ( & V_4 -> V_10 ) ;
}
void F_28 ( struct V_6 * V_4 )
{
F_29 ( & V_4 -> V_10 ) ;
}
static T_1 F_30 ( struct V_32 * V_33 , char T_2 * V_34 , T_3 V_35 ,
T_4 * V_36 )
{
struct V_37 * V_38 ;
char * V_39 ;
T_1 V_40 , V_41 , V_42 ;
V_38 = V_33 -> V_43 ;
if ( ! V_38 || ! V_38 -> V_44 )
return 0 ;
V_42 = 1000 ;
V_39 = F_31 ( V_42 , V_25 ) ;
if ( ! V_39 )
return - V_26 ;
V_41 = 0 ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_3 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_4 , V_38 -> V_45 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_5 , V_38 -> V_46 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_6 , V_38 -> V_47 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_7 , V_38 -> V_48 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_8 , V_38 -> V_49 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_9 , V_38 -> V_50 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_10 , V_38 -> V_51 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_11 , V_38 -> V_52 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_12 , V_38 -> V_53 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_13 , V_38 -> V_54 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_14 , V_38 -> V_55 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_15 , V_38 -> V_56 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_16 , V_38 -> V_57 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_17 , V_38 -> V_58 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_18 , V_38 -> V_59 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_19 , V_38 -> V_60 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_20 , V_38 -> V_61 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_21 , V_38 -> V_62 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_22 , V_38 -> V_63 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_23 , V_38 -> V_64 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_24 ,
V_38 -> V_65 -> V_14 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_25 , V_38 -> V_66 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_26 ,
F_32 ( V_38 ) ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_27 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_28 ,
V_38 -> V_67 ? L_29 : L_30 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_31 ,
V_38 -> V_68 ? L_29 : L_30 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_32 ,
V_38 -> V_44 ? L_33 : L_34 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_27 ) ;
if ( V_41 > V_42 )
V_41 = V_42 ;
V_40 = F_33 ( V_34 , V_35 , V_36 , V_39 , V_41 ) ;
F_17 ( V_39 ) ;
return V_40 ;
}
static void F_34 ( T_5 * V_69 , struct V_70 * V_14 ,
struct V_70 * V_71 )
{
unsigned long V_72 ;
F_35 ( V_69 , V_72 ) ;
F_9 ( V_14 , V_71 ) ;
F_36 ( V_69 , V_72 ) ;
}
static struct V_73 * F_37 ( T_5 * V_69 ,
struct V_70 * V_71 )
{
struct V_73 * V_14 ;
unsigned long V_72 ;
F_35 ( V_69 , V_72 ) ;
if ( F_21 ( V_71 ) ) {
V_14 = NULL ;
goto V_74;
}
V_14 = F_38 ( V_71 , struct V_73 , V_14 ) ;
F_13 ( & V_14 -> V_14 ) ;
V_74:
F_36 ( V_69 , V_72 ) ;
return V_14 ;
}
static struct V_73 * F_39 ( T_5 * V_69 ,
struct V_70 * V_71 ,
struct V_70 * V_75 )
{
struct V_73 * V_14 ;
unsigned long V_72 ;
F_35 ( V_69 , V_72 ) ;
if ( F_21 ( V_71 ) ) {
V_14 = NULL ;
} else {
V_14 = F_38 ( V_71 , struct V_73 , V_14 ) ;
F_40 ( & V_14 -> V_14 , V_75 ) ;
}
F_36 ( V_69 , V_72 ) ;
return V_14 ;
}
static int F_41 ( struct V_12 * V_13 ,
unsigned int V_76 )
{
struct V_37 * V_38 = & V_13 -> V_77 [ V_76 ] ;
struct V_78 * V_79 ;
struct V_80 * V_24 = V_13 -> V_24 ;
struct V_73 * V_14 ;
unsigned int V_81 , V_82 ;
unsigned int V_83 , V_84 , V_85 ;
unsigned int V_22 ;
int V_21 ;
V_84 = V_13 -> V_84 ;
V_85 = V_13 -> V_85 ;
V_83 = F_42 ( V_13 , V_76 ) ;
V_79 = & V_13 -> V_86 [ V_83 ] ;
if ( ! V_79 -> V_87 )
return - V_26 ;
if ( V_83 < V_85 % V_84 )
V_82 = V_85 / V_84 + 1 ;
else
V_82 = V_85 / V_84 ;
V_81 = ( unsigned int ) V_79 -> V_88 / V_82 ;
V_38 -> V_53 = V_79 -> V_87 + V_81 * ( V_76 / V_84 ) ;
V_81 -= sizeof( struct V_89 ) ;
V_38 -> V_65 = V_38 -> V_53 + V_81 ;
V_38 -> V_90 = F_43 ( V_91 , V_81 / 2 ) ;
V_38 -> V_55 = V_81 / V_38 -> V_90 ;
V_38 -> V_54 = 0 ;
V_21 = F_22 ( & V_24 -> V_2 ) ;
for ( V_22 = V_38 -> V_56 ; V_22 < V_38 -> V_55 ; V_22 ++ ) {
V_14 = F_23 ( sizeof( * V_14 ) , V_92 , V_21 ) ;
if ( ! V_14 )
return - V_26 ;
V_14 -> V_38 = V_38 ;
F_34 ( & V_38 -> V_93 , & V_14 -> V_14 ,
& V_38 -> V_94 ) ;
V_38 -> V_56 ++ ;
}
V_38 -> V_65 -> V_14 = V_38 -> V_55 - 1 ;
for ( V_22 = 0 ; V_22 < V_38 -> V_55 ; V_22 ++ ) {
void * V_95 = ( V_38 -> V_53 + V_38 -> V_90 * ( V_22 + 1 ) -
sizeof( struct V_96 ) ) ;
memset ( V_95 , 0 , sizeof( struct V_96 ) ) ;
}
V_38 -> V_46 = 0 ;
V_38 -> V_58 = 0 ;
V_38 -> V_64 = 0 ;
return 0 ;
}
static void F_44 ( struct V_12 * V_13 , int V_97 )
{
struct V_78 * V_79 = & V_13 -> V_86 [ V_97 ] ;
struct V_98 * V_99 = V_13 -> V_24 -> V_99 ;
if ( ! V_79 -> V_87 )
return;
F_45 ( V_13 -> V_24 , V_97 ) ;
F_46 ( & V_99 -> V_2 , V_79 -> V_100 ,
V_79 -> V_87 , V_79 -> V_101 ) ;
V_79 -> V_88 = 0 ;
V_79 -> V_100 = 0 ;
V_79 -> V_87 = NULL ;
}
static int F_47 ( struct V_12 * V_13 , int V_97 ,
T_6 V_102 )
{
struct V_78 * V_79 = & V_13 -> V_86 [ V_97 ] ;
struct V_98 * V_99 = V_13 -> V_24 -> V_99 ;
T_3 V_88 , V_100 ;
int V_8 ;
if ( ! V_102 )
return - V_9 ;
V_88 = F_48 ( V_102 , V_79 -> V_103 ) ;
V_100 = F_48 ( V_102 , V_79 -> V_104 ) ;
if ( V_79 -> V_88 == V_88 )
return 0 ;
if ( V_79 -> V_100 )
F_44 ( V_13 , V_97 ) ;
V_79 -> V_88 = V_88 ;
V_79 -> V_100 = V_100 ;
V_79 -> V_87 = F_49 ( & V_99 -> V_2 , V_100 ,
& V_79 -> V_101 , V_25 ) ;
if ( ! V_79 -> V_87 ) {
V_79 -> V_88 = 0 ;
V_79 -> V_100 = 0 ;
F_12 ( & V_99 -> V_2 , L_35 ,
V_100 ) ;
return - V_26 ;
}
if ( ! F_50 ( V_79 -> V_101 , V_79 -> V_104 ) ) {
F_12 ( & V_99 -> V_2 , L_36 ,
& V_79 -> V_101 ) ;
F_44 ( V_13 , V_97 ) ;
return - V_26 ;
}
V_8 = F_51 ( V_13 -> V_24 , V_97 , V_79 -> V_101 , V_79 -> V_88 ) ;
if ( V_8 ) {
F_12 ( & V_99 -> V_2 , L_37 , V_97 ) ;
F_44 ( V_13 , V_97 ) ;
return - V_105 ;
}
return 0 ;
}
static void F_52 ( struct V_37 * V_38 )
{
V_38 -> V_44 = false ;
V_38 -> V_106 = false ;
V_38 -> V_64 = 0 ;
V_38 -> V_54 = 0 ;
V_38 -> V_45 = 0 ;
V_38 -> V_46 = 0 ;
V_38 -> V_49 = 0 ;
V_38 -> V_50 = 0 ;
V_38 -> V_51 = 0 ;
V_38 -> V_52 = 0 ;
V_38 -> V_47 = 0 ;
V_38 -> V_48 = 0 ;
V_38 -> V_57 = 0 ;
V_38 -> V_58 = 0 ;
V_38 -> V_61 = 0 ;
V_38 -> V_62 = 0 ;
V_38 -> V_59 = 0 ;
V_38 -> V_60 = 0 ;
}
static void F_53 ( struct V_37 * V_38 )
{
struct V_12 * V_13 = V_38 -> V_107 ;
struct V_98 * V_99 = V_13 -> V_24 -> V_99 ;
F_54 ( & V_99 -> V_2 , L_38 , V_38 -> V_76 ) ;
F_55 ( & V_38 -> V_108 ) ;
F_52 ( V_38 ) ;
if ( V_38 -> V_109 )
V_38 -> V_109 ( V_38 -> V_110 , V_38 -> V_44 ) ;
}
static void F_56 ( struct V_111 * V_112 )
{
struct V_37 * V_38 = F_57 ( V_112 ,
struct V_37 ,
V_113 ) ;
struct V_12 * V_13 = V_38 -> V_107 ;
F_53 ( V_38 ) ;
if ( V_13 -> V_44 )
F_58 ( & V_38 -> V_108 ,
F_59 ( V_114 ) ) ;
}
static void F_60 ( struct V_37 * V_38 )
{
F_61 ( & V_38 -> V_113 ) ;
}
static void F_62 ( struct V_12 * V_13 )
{
struct V_37 * V_38 ;
T_7 V_115 ;
unsigned int V_22 , V_35 ;
V_115 = V_13 -> V_116 & ~ V_13 -> V_117 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_85 ; V_22 ++ )
if ( V_115 & F_63 ( V_22 ) ) {
V_38 = & V_13 -> V_77 [ V_22 ] ;
F_53 ( V_38 ) ;
F_64 ( & V_38 -> V_113 ) ;
F_55 ( & V_38 -> V_108 ) ;
}
if ( ! V_13 -> V_44 )
F_55 ( & V_13 -> V_108 ) ;
V_35 = F_65 ( V_13 -> V_24 ) ;
for ( V_22 = 0 ; V_22 < V_35 ; V_22 ++ )
F_66 ( V_13 -> V_24 , V_22 , 0 ) ;
}
static void F_67 ( struct V_111 * V_112 )
{
struct V_12 * V_13 =
F_57 ( V_112 , struct V_12 , V_113 ) ;
F_62 ( V_13 ) ;
}
static void F_68 ( void * V_118 )
{
struct V_12 * V_13 = V_118 ;
if ( F_69 ( V_13 -> V_24 , NULL , NULL ) == 1 )
F_58 ( & V_13 -> V_108 , 0 ) ;
else
F_61 ( & V_13 -> V_113 ) ;
}
static void F_70 ( struct V_111 * V_112 )
{
struct V_12 * V_13 =
F_57 ( V_112 , struct V_12 , V_108 . V_112 ) ;
struct V_80 * V_24 = V_13 -> V_24 ;
struct V_98 * V_99 = V_24 -> V_99 ;
T_6 V_102 ;
T_8 V_119 ;
int V_8 = 0 , V_22 , V_120 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_84 ; V_22 ++ ) {
V_102 = V_13 -> V_86 [ V_22 ] . V_121 ;
if ( V_122 && V_102 > V_122 )
V_102 = V_122 ;
V_120 = V_123 + ( V_22 * 2 ) ;
F_71 ( V_24 , V_120 , F_72 ( V_102 ) ) ;
V_120 = V_124 + ( V_22 * 2 ) ;
F_71 ( V_24 , V_120 , F_73 ( V_102 ) ) ;
}
F_71 ( V_24 , V_125 , V_13 -> V_84 ) ;
F_71 ( V_24 , V_126 , V_13 -> V_85 ) ;
F_71 ( V_24 , V_127 , V_128 ) ;
V_119 = F_74 ( V_24 , V_127 ) ;
F_75 ( & V_99 -> V_2 , L_39 , V_119 ) ;
if ( V_119 != V_128 )
goto V_74;
V_119 = F_74 ( V_24 , V_126 ) ;
F_75 ( & V_99 -> V_2 , L_40 , V_119 ) ;
if ( V_119 != V_13 -> V_85 )
goto V_74;
V_119 = F_74 ( V_24 , V_125 ) ;
F_75 ( & V_99 -> V_2 , L_41 , V_119 ) ;
if ( V_119 != V_13 -> V_84 )
goto V_74;
for ( V_22 = 0 ; V_22 < V_13 -> V_84 ; V_22 ++ ) {
T_7 V_129 ;
V_119 = F_74 ( V_24 , V_123 + ( V_22 * 2 ) ) ;
V_129 = ( T_7 ) V_119 << 32 ;
V_119 = F_74 ( V_24 , V_124 + ( V_22 * 2 ) ) ;
V_129 |= V_119 ;
F_75 ( & V_99 -> V_2 , L_42 , V_22 , V_129 ) ;
V_8 = F_47 ( V_13 , V_22 , V_129 ) ;
if ( V_8 )
goto V_130;
}
V_13 -> V_44 = true ;
for ( V_22 = 0 ; V_22 < V_13 -> V_85 ; V_22 ++ ) {
struct V_37 * V_38 = & V_13 -> V_77 [ V_22 ] ;
F_41 ( V_13 , V_22 ) ;
if ( V_38 -> V_131 )
F_58 ( & V_38 -> V_108 , 0 ) ;
}
return;
V_130:
for ( V_22 = 0 ; V_22 < V_13 -> V_84 ; V_22 ++ )
F_44 ( V_13 , V_22 ) ;
if ( V_8 < 0 ) {
F_76 ( V_24 ) ;
return;
}
V_74:
if ( F_69 ( V_24 , NULL , NULL ) == 1 )
F_58 ( & V_13 -> V_108 ,
F_59 ( V_114 ) ) ;
}
static void F_77 ( struct V_111 * V_112 )
{
struct V_37 * V_38 = F_57 ( V_112 ,
struct V_37 ,
V_108 . V_112 ) ;
struct V_98 * V_99 = V_38 -> V_24 -> V_99 ;
struct V_12 * V_13 = V_38 -> V_107 ;
int V_119 ;
F_78 ( ! V_13 -> V_44 ) ;
V_119 = F_74 ( V_13 -> V_24 , V_132 ) ;
F_71 ( V_13 -> V_24 , V_132 , V_119 | F_79 ( V_38 -> V_76 ) ) ;
F_80 ( & V_99 -> V_2 , L_43 , V_119 ) ;
if ( V_119 & F_79 ( V_38 -> V_76 ) ) {
F_54 ( & V_99 -> V_2 , L_44 , V_38 -> V_76 ) ;
V_38 -> V_44 = true ;
V_38 -> V_106 = true ;
if ( V_38 -> V_109 )
V_38 -> V_109 ( V_38 -> V_110 , V_38 -> V_44 ) ;
if ( V_38 -> V_106 )
F_81 ( & V_38 -> V_133 ) ;
} else if ( V_13 -> V_44 )
F_58 ( & V_38 -> V_108 ,
F_59 ( V_114 ) ) ;
}
static int F_82 ( struct V_12 * V_13 ,
unsigned int V_76 )
{
struct V_37 * V_38 ;
T_9 V_134 ;
T_6 V_135 ;
unsigned int V_82 , V_136 ;
unsigned int V_83 , V_84 , V_85 ;
T_7 V_137 ;
V_84 = V_13 -> V_84 ;
V_85 = V_13 -> V_85 ;
V_83 = F_42 ( V_13 , V_76 ) ;
V_38 = & V_13 -> V_77 [ V_76 ] ;
V_38 -> V_76 = V_76 ;
V_38 -> V_107 = V_13 ;
V_38 -> V_24 = V_13 -> V_24 ;
V_38 -> V_131 = false ;
V_38 -> V_109 = NULL ;
F_52 ( V_38 ) ;
if ( V_83 < V_85 % V_84 )
V_82 = V_85 / V_84 + 1 ;
else
V_82 = V_85 / V_84 ;
V_134 = V_13 -> V_86 [ V_83 ] . V_138 ;
V_135 = V_13 -> V_86 [ V_83 ] . V_121 ;
V_136 = ( unsigned int ) V_135 / V_82 ;
V_137 = V_136 * ( V_76 / V_84 ) ;
V_38 -> V_63 = V_13 -> V_86 [ V_83 ] . V_139 + V_137 ;
if ( ! V_38 -> V_63 )
return - V_9 ;
V_38 -> V_140 = V_134 + V_137 ;
if ( ! V_38 -> V_140 )
return - V_9 ;
V_136 -= sizeof( struct V_89 ) ;
V_38 -> V_141 = V_38 -> V_63 + V_136 ;
V_38 -> V_142 = F_43 ( V_91 , V_136 / 2 ) ;
V_38 -> V_66 = V_136 / V_38 -> V_142 ;
if ( V_13 -> V_143 ) {
char V_144 [ 4 ] ;
snprintf ( V_144 , 4 , L_45 , V_76 ) ;
V_38 -> V_145 = F_83 ( V_144 ,
V_13 -> V_143 ) ;
V_38 -> V_146 = F_84 ( L_46 , V_147 ,
V_38 -> V_145 , V_38 ,
& V_148 ) ;
} else {
V_38 -> V_145 = NULL ;
V_38 -> V_146 = NULL ;
}
F_85 ( & V_38 -> V_108 , F_77 ) ;
F_86 ( & V_38 -> V_113 , F_56 ) ;
F_87 ( & V_38 -> V_93 ) ;
F_87 ( & V_38 -> V_149 ) ;
F_88 ( & V_38 -> V_150 ) ;
F_88 ( & V_38 -> V_151 ) ;
F_88 ( & V_38 -> V_94 ) ;
F_88 ( & V_38 -> V_152 ) ;
F_89 ( & V_38 -> V_133 , V_153 ,
( unsigned long ) V_38 ) ;
return 0 ;
}
static int F_90 ( struct V_154 * V_155 , struct V_80 * V_24 )
{
struct V_12 * V_13 ;
struct V_78 * V_79 ;
unsigned int V_84 , V_85 , V_156 , V_157 ;
T_7 V_116 ;
int V_21 ;
int V_8 , V_22 ;
V_84 = F_91 ( V_24 ) ;
if ( F_92 ( V_24 ) )
F_75 ( & V_24 -> V_2 ,
L_47 ) ;
if ( F_93 ( V_24 ) )
F_75 ( & V_24 -> V_2 ,
L_48 ) ;
V_21 = F_22 ( & V_24 -> V_2 ) ;
V_13 = F_23 ( sizeof( * V_13 ) , V_25 , V_21 ) ;
if ( ! V_13 )
return - V_26 ;
V_13 -> V_24 = V_24 ;
V_156 = F_65 ( V_24 ) ;
if ( V_156 < V_158 ) {
V_13 -> V_84 = 0 ;
V_8 = - V_9 ;
goto V_27;
}
V_157 = ( V_156 - V_123 ) / 2 ;
V_13 -> V_84 = F_43 ( V_84 , V_157 ) ;
V_13 -> V_86 = F_23 ( V_84 * sizeof( * V_13 -> V_86 ) ,
V_25 , V_21 ) ;
if ( ! V_13 -> V_86 ) {
V_8 = - V_26 ;
goto V_27;
}
for ( V_22 = 0 ; V_22 < V_84 ; V_22 ++ ) {
V_79 = & V_13 -> V_86 [ V_22 ] ;
V_8 = F_94 ( V_24 , V_22 , & V_79 -> V_138 , & V_79 -> V_121 ,
& V_79 -> V_104 , & V_79 -> V_103 ) ;
if ( V_8 )
goto V_159;
V_79 -> V_139 = F_95 ( V_79 -> V_138 , V_79 -> V_121 ) ;
if ( ! V_79 -> V_139 ) {
V_8 = - V_26 ;
goto V_159;
}
V_79 -> V_100 = 0 ;
V_79 -> V_88 = 0 ;
V_79 -> V_87 = NULL ;
V_79 -> V_101 = 0 ;
}
V_116 = F_96 ( V_24 ) ;
V_85 = F_97 ( V_116 ) ;
if ( V_160 && V_160 < V_85 )
V_85 = V_160 ;
else if ( V_13 -> V_84 < V_85 )
V_85 = V_13 -> V_84 ;
V_116 &= F_63 ( V_85 ) - 1 ;
V_13 -> V_85 = V_85 ;
V_13 -> V_116 = V_116 ;
V_13 -> V_117 = V_116 ;
V_13 -> V_77 = F_23 ( V_85 * sizeof( * V_13 -> V_77 ) ,
V_25 , V_21 ) ;
if ( ! V_13 -> V_77 ) {
V_8 = - V_26 ;
goto V_159;
}
if ( V_161 ) {
V_13 -> V_143 =
F_83 ( F_98 ( V_24 -> V_99 ) ,
V_161 ) ;
}
for ( V_22 = 0 ; V_22 < V_85 ; V_22 ++ ) {
V_8 = F_82 ( V_13 , V_22 ) ;
if ( V_8 )
goto V_162;
}
F_85 ( & V_13 -> V_108 , F_70 ) ;
F_86 ( & V_13 -> V_113 , F_67 ) ;
V_8 = F_99 ( V_24 , V_13 , & V_163 ) ;
if ( V_8 )
goto V_162;
F_88 ( & V_13 -> V_31 ) ;
V_8 = F_8 ( V_13 ) ;
if ( V_8 )
goto V_164;
V_13 -> V_44 = false ;
F_100 ( V_24 , V_165 , V_166 ) ;
F_101 ( V_24 ) ;
return 0 ;
V_164:
F_102 ( V_24 ) ;
V_162:
F_17 ( V_13 -> V_77 ) ;
V_159:
while ( V_22 -- ) {
V_79 = & V_13 -> V_86 [ V_22 ] ;
F_103 ( V_79 -> V_139 ) ;
}
F_17 ( V_13 -> V_86 ) ;
V_27:
F_17 ( V_13 ) ;
return V_8 ;
}
static void F_104 ( struct V_154 * V_155 , struct V_80 * V_24 )
{
struct V_12 * V_13 = V_24 -> V_167 ;
struct V_37 * V_38 ;
T_7 V_115 ;
int V_22 ;
F_62 ( V_13 ) ;
F_64 ( & V_13 -> V_113 ) ;
F_55 ( & V_13 -> V_108 ) ;
V_115 = V_13 -> V_116 & ~ V_13 -> V_117 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_85 ; V_22 ++ ) {
V_38 = & V_13 -> V_77 [ V_22 ] ;
if ( V_115 & F_63 ( V_22 ) )
F_105 ( V_38 ) ;
F_106 ( V_38 -> V_145 ) ;
}
F_76 ( V_24 ) ;
F_102 ( V_24 ) ;
F_10 ( V_13 ) ;
for ( V_22 = V_13 -> V_84 ; V_22 -- ; ) {
F_44 ( V_13 , V_22 ) ;
F_103 ( V_13 -> V_86 [ V_22 ] . V_139 ) ;
}
F_17 ( V_13 -> V_77 ) ;
F_17 ( V_13 -> V_86 ) ;
F_17 ( V_13 ) ;
}
static void F_107 ( struct V_37 * V_38 )
{
struct V_73 * V_14 ;
void * V_110 ;
unsigned int V_168 ;
unsigned long V_169 ;
F_35 ( & V_38 -> V_93 , V_169 ) ;
while ( ! F_21 ( & V_38 -> V_150 ) ) {
V_14 = F_38 ( & V_38 -> V_150 ,
struct V_73 , V_14 ) ;
if ( ! ( V_14 -> V_72 & V_170 ) )
break;
V_14 -> V_171 -> V_72 = 0 ;
F_108 ( V_14 -> V_54 , & V_38 -> V_141 -> V_14 ) ;
V_110 = V_14 -> V_110 ;
V_168 = V_14 -> V_168 ;
F_40 ( & V_14 -> V_14 , & V_38 -> V_94 ) ;
F_36 ( & V_38 -> V_93 , V_169 ) ;
if ( V_38 -> V_172 && V_38 -> V_131 )
V_38 -> V_172 ( V_38 , V_38 -> V_110 , V_110 , V_168 ) ;
F_35 ( & V_38 -> V_93 , V_169 ) ;
}
F_36 ( & V_38 -> V_93 , V_169 ) ;
}
static void F_109 ( void * V_118 ,
const struct V_173 * V_174 )
{
struct V_73 * V_14 = V_118 ;
if ( V_174 ) {
enum V_175 V_176 = V_174 -> V_177 ;
switch ( V_176 ) {
case V_178 :
case V_179 :
V_14 -> V_180 ++ ;
case V_181 :
{
struct V_37 * V_38 = V_14 -> V_38 ;
void * V_95 = V_38 -> V_53 + V_38 -> V_90 *
V_38 -> V_54 ;
F_110 ( V_14 , V_95 ) ;
V_38 -> V_47 ++ ;
return;
}
case V_182 :
default:
break;
}
}
V_14 -> V_72 |= V_170 ;
F_107 ( V_14 -> V_38 ) ;
}
static void F_110 ( struct V_73 * V_14 , void * V_95 )
{
void * V_39 = V_14 -> V_39 ;
T_3 V_168 = V_14 -> V_168 ;
memcpy ( V_39 , V_95 , V_168 ) ;
F_111 () ;
F_109 ( V_14 , NULL ) ;
}
static int F_112 ( struct V_73 * V_14 , void * V_95 )
{
struct V_183 * V_184 ;
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_185 * V_186 = V_38 -> V_68 ;
struct V_187 * V_1 ;
T_3 V_188 , V_189 , V_168 ;
struct V_190 * V_191 ;
T_10 V_192 ;
void * V_39 = V_14 -> V_39 ;
V_168 = V_14 -> V_168 ;
V_1 = V_186 -> V_1 ;
V_188 = ( T_3 ) V_95 & ~ V_193 ;
V_189 = ( T_3 ) V_39 & ~ V_193 ;
if ( ! F_113 ( V_1 , V_188 , V_189 , V_168 ) )
goto V_27;
V_191 = F_114 ( V_1 -> V_2 , 2 , V_194 ) ;
if ( ! V_191 )
goto V_27;
V_191 -> V_168 = V_168 ;
V_191 -> V_195 [ 0 ] = F_115 ( V_1 -> V_2 , F_116 ( V_95 ) ,
V_188 , V_168 , V_196 ) ;
if ( F_117 ( V_1 -> V_2 , V_191 -> V_195 [ 0 ] ) )
goto V_197;
V_191 -> V_198 = 1 ;
V_191 -> V_195 [ 1 ] = F_115 ( V_1 -> V_2 , F_116 ( V_39 ) ,
V_189 , V_168 , V_199 ) ;
if ( F_117 ( V_1 -> V_2 , V_191 -> V_195 [ 1 ] ) )
goto V_197;
V_191 -> V_200 = 1 ;
V_184 = V_1 -> V_201 ( V_186 , V_191 -> V_195 [ 1 ] ,
V_191 -> V_195 [ 0 ] , V_168 ,
V_202 ) ;
if ( ! V_184 )
goto V_197;
V_184 -> V_203 = F_109 ;
V_184 -> V_204 = V_14 ;
F_118 ( V_184 , V_191 ) ;
V_192 = F_119 ( V_184 ) ;
if ( F_120 ( V_192 ) )
goto V_205;
F_121 ( V_191 ) ;
V_38 -> V_206 = V_192 ;
V_38 -> V_48 ++ ;
return 0 ;
V_205:
F_121 ( V_191 ) ;
V_197:
F_121 ( V_191 ) ;
V_27:
return - V_207 ;
}
static void F_122 ( struct V_73 * V_14 , void * V_95 )
{
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_185 * V_186 = V_38 -> V_68 ;
int V_174 ;
if ( ! V_186 )
goto V_27;
if ( V_14 -> V_168 < V_208 )
goto V_27;
V_174 = F_112 ( V_14 , V_95 ) ;
if ( V_174 < 0 )
goto V_27;
if ( ! V_14 -> V_209 )
V_38 -> V_48 ++ ;
return;
V_27:
F_110 ( V_14 , V_95 ) ;
V_38 -> V_47 ++ ;
}
static int F_123 ( struct V_37 * V_38 )
{
struct V_96 * V_210 ;
struct V_73 * V_14 ;
void * V_95 ;
V_95 = V_38 -> V_53 + V_38 -> V_90 * V_38 -> V_54 ;
V_210 = V_95 + V_38 -> V_90 - sizeof( struct V_96 ) ;
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 , L_49 ,
V_38 -> V_76 , V_210 -> V_211 , V_210 -> V_168 , V_210 -> V_72 ) ;
if ( ! ( V_210 -> V_72 & V_170 ) ) {
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 , L_50 ) ;
V_38 -> V_49 ++ ;
return - V_212 ;
}
if ( V_210 -> V_72 & V_213 ) {
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 , L_51 ) ;
F_60 ( V_38 ) ;
V_210 -> V_72 = 0 ;
return - V_212 ;
}
if ( V_210 -> V_211 != ( T_8 ) V_38 -> V_46 ) {
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 ,
L_52 ,
V_38 -> V_46 , V_210 -> V_211 ) ;
V_38 -> V_52 ++ ;
return - V_105 ;
}
V_14 = F_39 ( & V_38 -> V_93 , & V_38 -> V_151 , & V_38 -> V_150 ) ;
if ( ! V_14 ) {
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 , L_53 ) ;
V_38 -> V_50 ++ ;
return - V_212 ;
}
V_14 -> V_171 = V_210 ;
V_14 -> V_54 = V_38 -> V_54 ;
if ( V_210 -> V_168 > V_14 -> V_168 ) {
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 ,
L_54 ,
V_210 -> V_168 , V_14 -> V_168 ) ;
V_38 -> V_51 ++ ;
V_14 -> V_168 = - V_105 ;
V_14 -> V_72 |= V_170 ;
F_107 ( V_38 ) ;
} else {
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 ,
L_55 ,
V_38 -> V_54 , V_210 -> V_211 , V_210 -> V_168 , V_14 -> V_168 ) ;
V_38 -> V_45 += V_210 -> V_168 ;
V_38 -> V_46 ++ ;
V_14 -> V_168 = V_210 -> V_168 ;
F_122 ( V_14 , V_95 ) ;
}
V_38 -> V_54 ++ ;
V_38 -> V_54 %= V_38 -> V_55 ;
return 0 ;
}
static void V_153 ( unsigned long V_118 )
{
struct V_37 * V_38 = ( void * ) V_118 ;
int V_8 , V_22 ;
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 , L_56 ,
V_214 , V_38 -> V_76 ) ;
for ( V_22 = 0 ; V_22 < V_38 -> V_55 ; V_22 ++ ) {
V_8 = F_123 ( V_38 ) ;
if ( V_8 )
break;
}
if ( V_22 && V_38 -> V_68 )
F_124 ( V_38 -> V_68 ) ;
if ( V_22 == V_38 -> V_55 ) {
if ( V_38 -> V_106 )
F_81 ( & V_38 -> V_133 ) ;
} else if ( F_125 ( V_38 -> V_24 ) & F_63 ( V_38 -> V_76 ) ) {
F_126 ( V_38 -> V_24 , F_63 ( V_38 -> V_76 ) ) ;
F_125 ( V_38 -> V_24 ) ;
if ( V_38 -> V_106 )
F_81 ( & V_38 -> V_133 ) ;
}
}
static void F_127 ( void * V_118 ,
const struct V_173 * V_174 )
{
struct V_73 * V_14 = V_118 ;
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_96 T_11 * V_210 = V_14 -> V_215 ;
if ( V_174 ) {
enum V_175 V_176 = V_174 -> V_177 ;
switch ( V_176 ) {
case V_178 :
case V_179 :
V_14 -> V_180 ++ ;
case V_181 :
{
void T_11 * V_95 =
V_38 -> V_63 + V_38 -> V_142 *
V_14 -> V_64 ;
F_128 ( V_14 , V_95 ) ;
V_38 -> V_59 ++ ;
return;
}
case V_182 :
default:
break;
}
}
F_108 ( V_14 -> V_72 | V_170 , & V_210 -> V_72 ) ;
F_129 ( V_38 -> V_24 , F_63 ( V_38 -> V_76 ) ) ;
if ( V_14 -> V_168 > 0 ) {
V_38 -> V_57 += V_14 -> V_168 ;
if ( V_38 -> V_216 )
V_38 -> V_216 ( V_38 , V_38 -> V_110 , V_14 -> V_110 ,
V_14 -> V_168 ) ;
}
F_34 ( & V_38 -> V_149 , & V_14 -> V_14 , & V_38 -> V_152 ) ;
}
static void F_128 ( struct V_73 * V_14 , void T_11 * V_95 )
{
#ifdef F_130
F_131 ( V_95 , V_14 -> V_39 , V_14 -> V_168 ) ;
#else
F_132 ( V_95 , V_14 -> V_39 , V_14 -> V_168 ) ;
#endif
F_111 () ;
F_127 ( V_14 , NULL ) ;
}
static int F_133 ( struct V_37 * V_38 ,
struct V_73 * V_14 )
{
struct V_183 * V_184 ;
struct V_185 * V_186 = V_38 -> V_67 ;
struct V_187 * V_1 ;
T_3 V_168 = V_14 -> V_168 ;
void * V_39 = V_14 -> V_39 ;
T_3 V_217 , V_189 ;
struct V_190 * V_191 ;
T_12 V_218 ;
T_10 V_192 ;
V_1 = V_186 -> V_1 ;
V_218 = V_38 -> V_140 + V_38 -> V_142 * V_14 -> V_64 ;
V_189 = ( T_3 ) V_39 & ~ V_193 ;
V_217 = ( T_3 ) V_218 & ~ V_193 ;
if ( ! F_113 ( V_1 , V_189 , V_217 , V_168 ) )
goto V_27;
V_191 = F_114 ( V_1 -> V_2 , 1 , V_194 ) ;
if ( ! V_191 )
goto V_27;
V_191 -> V_168 = V_168 ;
V_191 -> V_195 [ 0 ] = F_115 ( V_1 -> V_2 , F_116 ( V_39 ) ,
V_189 , V_168 , V_196 ) ;
if ( F_117 ( V_1 -> V_2 , V_191 -> V_195 [ 0 ] ) )
goto V_197;
V_191 -> V_198 = 1 ;
V_184 = V_1 -> V_201 ( V_186 , V_218 , V_191 -> V_195 [ 0 ] , V_168 ,
V_202 ) ;
if ( ! V_184 )
goto V_197;
V_184 -> V_203 = F_127 ;
V_184 -> V_204 = V_14 ;
F_118 ( V_184 , V_191 ) ;
V_192 = F_119 ( V_184 ) ;
if ( F_120 ( V_192 ) )
goto V_205;
F_121 ( V_191 ) ;
F_124 ( V_186 ) ;
return 0 ;
V_205:
F_121 ( V_191 ) ;
V_197:
F_121 ( V_191 ) ;
V_27:
return - V_207 ;
}
static void F_134 ( struct V_37 * V_38 ,
struct V_73 * V_14 )
{
struct V_96 T_11 * V_210 ;
struct V_185 * V_186 = V_38 -> V_67 ;
void T_11 * V_95 ;
int V_174 ;
V_14 -> V_64 = V_38 -> V_64 ;
V_95 = V_38 -> V_63 + V_38 -> V_142 * V_14 -> V_64 ;
V_210 = V_95 + V_38 -> V_142 - sizeof( struct V_96 ) ;
V_14 -> V_215 = V_210 ;
F_108 ( V_14 -> V_168 , & V_210 -> V_168 ) ;
F_108 ( ( T_8 ) V_38 -> V_58 , & V_210 -> V_211 ) ;
if ( ! V_186 )
goto V_27;
if ( V_14 -> V_168 < V_208 )
goto V_27;
V_174 = F_133 ( V_38 , V_14 ) ;
if ( V_174 < 0 )
goto V_27;
if ( ! V_14 -> V_209 )
V_38 -> V_60 ++ ;
return;
V_27:
F_128 ( V_14 , V_95 ) ;
V_38 -> V_59 ++ ;
}
static int F_135 ( struct V_37 * V_38 ,
struct V_73 * V_14 )
{
if ( V_38 -> V_64 == V_38 -> V_65 -> V_14 ) {
V_38 -> V_61 ++ ;
return - V_212 ;
}
if ( V_14 -> V_168 > V_38 -> V_142 - sizeof( struct V_96 ) ) {
if ( V_38 -> V_216 )
V_38 -> V_216 ( V_38 , V_38 -> V_110 , NULL , - V_105 ) ;
F_34 ( & V_38 -> V_149 , & V_14 -> V_14 ,
& V_38 -> V_152 ) ;
return 0 ;
}
F_134 ( V_38 , V_14 ) ;
V_38 -> V_64 ++ ;
V_38 -> V_64 %= V_38 -> V_66 ;
V_38 -> V_58 ++ ;
return 0 ;
}
static void F_136 ( struct V_37 * V_38 )
{
struct V_98 * V_99 = V_38 -> V_24 -> V_99 ;
struct V_73 * V_14 ;
int V_22 , V_8 ;
if ( ! V_38 -> V_44 )
return;
F_54 ( & V_99 -> V_2 , L_57 , V_38 -> V_76 ) ;
for ( V_22 = 0 ; V_22 < V_114 ; V_22 ++ ) {
V_14 = F_37 ( & V_38 -> V_149 , & V_38 -> V_152 ) ;
if ( V_14 )
break;
F_137 ( 100 ) ;
}
if ( ! V_14 )
return;
V_14 -> V_110 = NULL ;
V_14 -> V_39 = NULL ;
V_14 -> V_168 = 0 ;
V_14 -> V_72 = V_213 ;
V_8 = F_135 ( V_38 , V_14 ) ;
if ( V_8 )
F_12 ( & V_99 -> V_2 , L_58 ,
V_38 -> V_76 ) ;
F_52 ( V_38 ) ;
}
static bool F_138 ( struct V_185 * V_186 , void * V_21 )
{
return F_22 ( & V_186 -> V_2 -> V_1 ) == ( int ) ( unsigned long ) V_21 ;
}
struct V_37 *
F_139 ( void * V_118 , struct V_1 * V_17 ,
const struct V_219 * V_220 )
{
struct V_80 * V_24 ;
struct V_98 * V_99 ;
struct V_12 * V_13 ;
struct V_73 * V_14 ;
struct V_37 * V_38 ;
T_7 V_221 ;
unsigned int V_222 ;
T_13 V_223 ;
int V_21 ;
int V_22 ;
V_24 = F_140 ( V_17 -> V_19 ) ;
V_99 = V_24 -> V_99 ;
V_13 = V_24 -> V_167 ;
V_21 = F_22 ( & V_24 -> V_2 ) ;
V_222 = F_141 ( V_13 -> V_117 ) ;
if ( ! V_222 )
goto V_27;
V_222 -- ;
V_38 = & V_13 -> V_77 [ V_222 ] ;
V_221 = F_63 ( V_38 -> V_76 ) ;
V_13 -> V_117 &= ~ V_221 ;
V_38 -> V_110 = V_118 ;
V_38 -> V_172 = V_220 -> V_172 ;
V_38 -> V_216 = V_220 -> V_216 ;
V_38 -> V_109 = V_220 -> V_109 ;
F_142 ( V_223 ) ;
F_143 ( V_224 , V_223 ) ;
if ( V_225 ) {
V_38 -> V_67 =
F_144 ( V_223 , F_138 ,
( void * ) ( unsigned long ) V_21 ) ;
if ( ! V_38 -> V_67 )
F_54 ( & V_99 -> V_2 , L_59 ) ;
V_38 -> V_68 =
F_144 ( V_223 , F_138 ,
( void * ) ( unsigned long ) V_21 ) ;
if ( ! V_38 -> V_68 )
F_54 ( & V_99 -> V_2 , L_60 ) ;
} else {
V_38 -> V_67 = NULL ;
V_38 -> V_68 = NULL ;
}
F_75 ( & V_99 -> V_2 , L_61 ,
V_38 -> V_67 ? L_62 : L_63 ) ;
F_75 ( & V_99 -> V_2 , L_64 ,
V_38 -> V_68 ? L_62 : L_63 ) ;
for ( V_22 = 0 ; V_22 < V_226 ; V_22 ++ ) {
V_14 = F_23 ( sizeof( * V_14 ) , V_92 , V_21 ) ;
if ( ! V_14 )
goto V_159;
V_14 -> V_38 = V_38 ;
F_34 ( & V_38 -> V_93 , & V_14 -> V_14 ,
& V_38 -> V_94 ) ;
}
V_38 -> V_56 = V_226 ;
for ( V_22 = 0 ; V_22 < V_38 -> V_66 ; V_22 ++ ) {
V_14 = F_23 ( sizeof( * V_14 ) , V_92 , V_21 ) ;
if ( ! V_14 )
goto V_162;
V_14 -> V_38 = V_38 ;
F_34 ( & V_38 -> V_149 , & V_14 -> V_14 ,
& V_38 -> V_152 ) ;
}
F_126 ( V_38 -> V_24 , V_221 ) ;
F_145 ( V_38 -> V_24 , V_221 ) ;
F_54 ( & V_99 -> V_2 , L_65 , V_38 -> V_76 ) ;
return V_38 ;
V_162:
while ( ( V_14 = F_37 ( & V_38 -> V_149 , & V_38 -> V_152 ) ) )
F_17 ( V_14 ) ;
V_159:
V_38 -> V_56 = 0 ;
while ( ( V_14 = F_37 ( & V_38 -> V_93 , & V_38 -> V_94 ) ) )
F_17 ( V_14 ) ;
if ( V_38 -> V_67 )
F_146 ( V_38 -> V_67 ) ;
if ( V_38 -> V_68 )
F_146 ( V_38 -> V_68 ) ;
V_13 -> V_117 |= V_221 ;
V_27:
return NULL ;
}
void F_105 ( struct V_37 * V_38 )
{
struct V_98 * V_99 ;
struct V_73 * V_14 ;
T_7 V_221 ;
if ( ! V_38 )
return;
V_99 = V_38 -> V_24 -> V_99 ;
V_38 -> V_106 = false ;
if ( V_38 -> V_67 ) {
struct V_185 * V_186 = V_38 -> V_67 ;
V_38 -> V_67 = NULL ;
F_147 ( V_186 , V_38 -> V_206 ) ;
F_148 ( V_186 ) ;
F_146 ( V_186 ) ;
}
if ( V_38 -> V_68 ) {
struct V_185 * V_186 = V_38 -> V_68 ;
V_38 -> V_68 = NULL ;
F_147 ( V_186 , V_38 -> V_206 ) ;
F_148 ( V_186 ) ;
F_146 ( V_186 ) ;
}
V_221 = F_63 ( V_38 -> V_76 ) ;
F_149 ( V_38 -> V_24 , V_221 ) ;
F_150 ( & V_38 -> V_133 ) ;
F_55 ( & V_38 -> V_108 ) ;
V_38 -> V_110 = NULL ;
V_38 -> V_172 = NULL ;
V_38 -> V_216 = NULL ;
V_38 -> V_109 = NULL ;
while ( ( V_14 = F_37 ( & V_38 -> V_93 , & V_38 -> V_94 ) ) )
F_17 ( V_14 ) ;
while ( ( V_14 = F_37 ( & V_38 -> V_93 , & V_38 -> V_151 ) ) ) {
F_151 ( & V_99 -> V_2 , L_66 ) ;
F_17 ( V_14 ) ;
}
while ( ( V_14 = F_37 ( & V_38 -> V_93 , & V_38 -> V_150 ) ) ) {
F_151 ( & V_99 -> V_2 , L_67 ) ;
F_17 ( V_14 ) ;
}
while ( ( V_14 = F_37 ( & V_38 -> V_149 , & V_38 -> V_152 ) ) )
F_17 ( V_14 ) ;
V_38 -> V_107 -> V_117 |= V_221 ;
F_54 ( & V_99 -> V_2 , L_68 , V_38 -> V_76 ) ;
}
void * F_152 ( struct V_37 * V_38 , unsigned int * V_168 )
{
struct V_73 * V_14 ;
void * V_39 ;
if ( ! V_38 || V_38 -> V_131 )
return NULL ;
V_14 = F_37 ( & V_38 -> V_93 , & V_38 -> V_151 ) ;
if ( ! V_14 )
return NULL ;
V_39 = V_14 -> V_110 ;
* V_168 = V_14 -> V_168 ;
F_34 ( & V_38 -> V_93 , & V_14 -> V_14 , & V_38 -> V_94 ) ;
return V_39 ;
}
int F_153 ( struct V_37 * V_38 , void * V_227 , void * V_118 ,
unsigned int V_168 )
{
struct V_73 * V_14 ;
if ( ! V_38 )
return - V_9 ;
V_14 = F_37 ( & V_38 -> V_93 , & V_38 -> V_94 ) ;
if ( ! V_14 )
return - V_26 ;
V_14 -> V_110 = V_227 ;
V_14 -> V_39 = V_118 ;
V_14 -> V_168 = V_168 ;
V_14 -> V_72 = 0 ;
V_14 -> V_209 = 0 ;
V_14 -> V_180 = 0 ;
V_14 -> V_54 = 0 ;
F_34 ( & V_38 -> V_93 , & V_14 -> V_14 , & V_38 -> V_151 ) ;
if ( V_38 -> V_106 )
F_81 ( & V_38 -> V_133 ) ;
return 0 ;
}
int F_154 ( struct V_37 * V_38 , void * V_227 , void * V_118 ,
unsigned int V_168 )
{
struct V_73 * V_14 ;
int V_8 ;
if ( ! V_38 || ! V_38 -> V_44 || ! V_168 )
return - V_9 ;
V_14 = F_37 ( & V_38 -> V_149 , & V_38 -> V_152 ) ;
if ( ! V_14 ) {
V_38 -> V_62 ++ ;
return - V_228 ;
}
V_14 -> V_110 = V_227 ;
V_14 -> V_39 = V_118 ;
V_14 -> V_168 = V_168 ;
V_14 -> V_72 = 0 ;
V_14 -> V_180 = 0 ;
V_14 -> V_209 = 0 ;
V_14 -> V_64 = 0 ;
V_8 = F_135 ( V_38 , V_14 ) ;
if ( V_8 )
F_34 ( & V_38 -> V_149 , & V_14 -> V_14 ,
& V_38 -> V_152 ) ;
return V_8 ;
}
void F_155 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return;
V_38 -> V_131 = true ;
if ( V_38 -> V_107 -> V_44 )
F_58 ( & V_38 -> V_108 , 0 ) ;
}
void F_156 ( struct V_37 * V_38 )
{
int V_119 ;
if ( ! V_38 )
return;
V_38 -> V_131 = false ;
V_119 = F_74 ( V_38 -> V_24 , V_132 ) ;
F_71 ( V_38 -> V_24 , V_132 ,
V_119 & ~ F_79 ( V_38 -> V_76 ) ) ;
if ( V_38 -> V_44 )
F_136 ( V_38 ) ;
else
F_55 ( & V_38 -> V_108 ) ;
}
bool F_157 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return false ;
return V_38 -> V_44 ;
}
unsigned char F_158 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return 0 ;
return V_38 -> V_76 ;
}
unsigned int F_159 ( struct V_37 * V_38 )
{
unsigned int V_229 ;
unsigned int V_230 ;
struct V_185 * V_231 , * V_232 ;
if ( ! V_38 )
return 0 ;
V_231 = V_38 -> V_68 ;
V_232 = V_38 -> V_67 ;
V_230 = F_160 ( V_231 ? V_231 -> V_1 -> V_230 : 0 ,
V_232 ? V_232 -> V_1 -> V_230 : 0 ) ;
V_229 = V_38 -> V_142 - sizeof( struct V_96 ) ;
V_229 = F_161 ( V_229 , 1 << V_230 ) ;
return V_229 ;
}
unsigned int F_32 ( struct V_37 * V_38 )
{
unsigned int V_233 = V_38 -> V_64 ;
unsigned int V_234 = V_38 -> V_65 -> V_14 ;
return V_234 > V_233 ? V_234 - V_233 : V_38 -> V_66 + V_234 - V_233 ;
}
static void F_162 ( void * V_118 , int V_235 )
{
struct V_12 * V_13 = V_118 ;
struct V_37 * V_38 ;
T_7 V_236 ;
unsigned int V_76 ;
V_236 = ( V_13 -> V_116 & ~ V_13 -> V_117 &
F_163 ( V_13 -> V_24 , V_235 ) ) ;
while ( V_236 ) {
V_76 = F_164 ( V_236 ) ;
V_38 = & V_13 -> V_77 [ V_76 ] ;
if ( V_38 -> V_106 )
F_81 ( & V_38 -> V_133 ) ;
V_236 &= ~ F_63 ( V_76 ) ;
}
}
static int T_14 F_165 ( void )
{
int V_8 ;
F_166 ( L_69 , V_237 , V_238 ) ;
if ( F_167 () )
V_161 = F_83 ( V_239 , NULL ) ;
V_8 = F_168 ( & V_29 ) ;
if ( V_8 )
goto V_240;
V_8 = F_169 ( & V_6 ) ;
if ( V_8 )
goto V_241;
return 0 ;
V_241:
F_170 ( & V_29 ) ;
V_240:
F_106 ( V_161 ) ;
return V_8 ;
}
static void T_15 F_171 ( void )
{
F_172 ( & V_6 ) ;
F_170 ( & V_29 ) ;
F_106 ( V_161 ) ;
}
