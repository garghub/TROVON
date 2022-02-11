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
F_45 ( V_13 -> V_24 , V_100 , V_97 ) ;
F_46 ( & V_99 -> V_2 , V_79 -> V_101 ,
V_79 -> V_87 , V_79 -> V_102 ) ;
V_79 -> V_88 = 0 ;
V_79 -> V_101 = 0 ;
V_79 -> V_87 = NULL ;
}
static int F_47 ( struct V_12 * V_13 , int V_97 ,
T_6 V_103 )
{
struct V_78 * V_79 = & V_13 -> V_86 [ V_97 ] ;
struct V_98 * V_99 = V_13 -> V_24 -> V_99 ;
T_3 V_88 , V_101 ;
int V_8 ;
if ( ! V_103 )
return - V_9 ;
V_88 = F_48 ( V_103 , V_79 -> V_104 ) ;
V_101 = F_48 ( V_103 , V_79 -> V_105 ) ;
if ( V_79 -> V_88 == V_88 )
return 0 ;
if ( V_79 -> V_101 )
F_44 ( V_13 , V_97 ) ;
V_79 -> V_88 = V_88 ;
V_79 -> V_101 = V_101 ;
V_79 -> V_87 = F_49 ( & V_99 -> V_2 , V_101 ,
& V_79 -> V_102 , V_25 ) ;
if ( ! V_79 -> V_87 ) {
V_79 -> V_88 = 0 ;
V_79 -> V_101 = 0 ;
F_12 ( & V_99 -> V_2 , L_35 ,
V_101 ) ;
return - V_26 ;
}
if ( ! F_50 ( V_79 -> V_102 , V_79 -> V_105 ) ) {
F_12 ( & V_99 -> V_2 , L_36 ,
& V_79 -> V_102 ) ;
F_44 ( V_13 , V_97 ) ;
return - V_26 ;
}
V_8 = F_51 ( V_13 -> V_24 , V_100 , V_97 , V_79 -> V_102 ,
V_79 -> V_88 ) ;
if ( V_8 ) {
F_12 ( & V_99 -> V_2 , L_37 , V_97 ) ;
F_44 ( V_13 , V_97 ) ;
return - V_106 ;
}
return 0 ;
}
static void F_52 ( struct V_37 * V_38 )
{
V_38 -> V_44 = false ;
V_38 -> V_107 = false ;
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
struct V_12 * V_13 = V_38 -> V_108 ;
struct V_98 * V_99 = V_13 -> V_24 -> V_99 ;
F_54 ( & V_99 -> V_2 , L_38 , V_38 -> V_76 ) ;
F_55 ( & V_38 -> V_109 ) ;
F_52 ( V_38 ) ;
if ( V_38 -> V_110 )
V_38 -> V_110 ( V_38 -> V_111 , V_38 -> V_44 ) ;
}
static void F_56 ( struct V_112 * V_113 )
{
struct V_37 * V_38 = F_57 ( V_113 ,
struct V_37 ,
V_114 ) ;
struct V_12 * V_13 = V_38 -> V_108 ;
F_53 ( V_38 ) ;
if ( V_13 -> V_44 )
F_58 ( & V_38 -> V_109 ,
F_59 ( V_115 ) ) ;
}
static void F_60 ( struct V_37 * V_38 )
{
F_61 ( & V_38 -> V_114 ) ;
}
static void F_62 ( struct V_12 * V_13 )
{
struct V_37 * V_38 ;
T_7 V_116 ;
unsigned int V_22 , V_35 ;
V_116 = V_13 -> V_117 & ~ V_13 -> V_118 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_85 ; V_22 ++ )
if ( V_116 & F_63 ( V_22 ) ) {
V_38 = & V_13 -> V_77 [ V_22 ] ;
F_53 ( V_38 ) ;
F_64 ( & V_38 -> V_114 ) ;
F_55 ( & V_38 -> V_109 ) ;
}
if ( ! V_13 -> V_44 )
F_55 ( & V_13 -> V_109 ) ;
V_35 = F_65 ( V_13 -> V_24 ) ;
for ( V_22 = 0 ; V_22 < V_35 ; V_22 ++ )
F_66 ( V_13 -> V_24 , V_22 , 0 ) ;
}
static void F_67 ( struct V_112 * V_113 )
{
struct V_12 * V_13 =
F_57 ( V_113 , struct V_12 , V_114 ) ;
F_62 ( V_13 ) ;
}
static void F_68 ( void * V_119 )
{
struct V_12 * V_13 = V_119 ;
if ( F_69 ( V_13 -> V_24 , NULL , NULL ) == 1 )
F_58 ( & V_13 -> V_109 , 0 ) ;
else
F_61 ( & V_13 -> V_114 ) ;
}
static void F_70 ( struct V_112 * V_113 )
{
struct V_12 * V_13 =
F_57 ( V_113 , struct V_12 , V_109 . V_113 ) ;
struct V_80 * V_24 = V_13 -> V_24 ;
struct V_98 * V_99 = V_24 -> V_99 ;
T_6 V_103 ;
T_8 V_120 ;
int V_8 = 0 , V_22 , V_121 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_84 ; V_22 ++ ) {
V_103 = V_13 -> V_86 [ V_22 ] . V_122 ;
if ( V_123 && V_103 > V_123 )
V_103 = V_123 ;
V_121 = V_124 + ( V_22 * 2 ) ;
F_71 ( V_24 , V_100 , V_121 , F_72 ( V_103 ) ) ;
V_121 = V_125 + ( V_22 * 2 ) ;
F_71 ( V_24 , V_100 , V_121 , F_73 ( V_103 ) ) ;
}
F_71 ( V_24 , V_100 , V_126 , V_13 -> V_84 ) ;
F_71 ( V_24 , V_100 , V_127 , V_13 -> V_85 ) ;
F_71 ( V_24 , V_100 , V_128 , V_129 ) ;
V_120 = F_74 ( V_24 , V_128 ) ;
F_75 ( & V_99 -> V_2 , L_39 , V_120 ) ;
if ( V_120 != V_129 )
goto V_74;
V_120 = F_74 ( V_24 , V_127 ) ;
F_75 ( & V_99 -> V_2 , L_40 , V_120 ) ;
if ( V_120 != V_13 -> V_85 )
goto V_74;
V_120 = F_74 ( V_24 , V_126 ) ;
F_75 ( & V_99 -> V_2 , L_41 , V_120 ) ;
if ( V_120 != V_13 -> V_84 )
goto V_74;
for ( V_22 = 0 ; V_22 < V_13 -> V_84 ; V_22 ++ ) {
T_7 V_130 ;
V_120 = F_74 ( V_24 , V_124 + ( V_22 * 2 ) ) ;
V_130 = ( T_7 ) V_120 << 32 ;
V_120 = F_74 ( V_24 , V_125 + ( V_22 * 2 ) ) ;
V_130 |= V_120 ;
F_75 ( & V_99 -> V_2 , L_42 , V_22 , V_130 ) ;
V_8 = F_47 ( V_13 , V_22 , V_130 ) ;
if ( V_8 )
goto V_131;
}
V_13 -> V_44 = true ;
for ( V_22 = 0 ; V_22 < V_13 -> V_85 ; V_22 ++ ) {
struct V_37 * V_38 = & V_13 -> V_77 [ V_22 ] ;
F_41 ( V_13 , V_22 ) ;
if ( V_38 -> V_132 )
F_58 ( & V_38 -> V_109 , 0 ) ;
}
return;
V_131:
for ( V_22 = 0 ; V_22 < V_13 -> V_84 ; V_22 ++ )
F_44 ( V_13 , V_22 ) ;
if ( V_8 < 0 )
return;
V_74:
if ( F_69 ( V_24 , NULL , NULL ) == 1 )
F_58 ( & V_13 -> V_109 ,
F_59 ( V_115 ) ) ;
}
static void F_76 ( struct V_112 * V_113 )
{
struct V_37 * V_38 = F_57 ( V_113 ,
struct V_37 ,
V_109 . V_113 ) ;
struct V_98 * V_99 = V_38 -> V_24 -> V_99 ;
struct V_12 * V_13 = V_38 -> V_108 ;
int V_120 ;
F_77 ( ! V_13 -> V_44 ) ;
V_120 = F_74 ( V_13 -> V_24 , V_133 ) ;
F_71 ( V_13 -> V_24 , V_100 , V_133 , V_120 | F_78 ( V_38 -> V_76 ) ) ;
F_79 ( & V_99 -> V_2 , L_43 , V_120 ) ;
if ( V_120 & F_78 ( V_38 -> V_76 ) ) {
F_54 ( & V_99 -> V_2 , L_44 , V_38 -> V_76 ) ;
V_38 -> V_44 = true ;
V_38 -> V_107 = true ;
if ( V_38 -> V_110 )
V_38 -> V_110 ( V_38 -> V_111 , V_38 -> V_44 ) ;
if ( V_38 -> V_107 )
F_80 ( & V_38 -> V_134 ) ;
} else if ( V_13 -> V_44 )
F_58 ( & V_38 -> V_109 ,
F_59 ( V_115 ) ) ;
}
static int F_81 ( struct V_12 * V_13 ,
unsigned int V_76 )
{
struct V_37 * V_38 ;
T_9 V_135 ;
T_6 V_136 ;
unsigned int V_82 , V_137 ;
unsigned int V_83 , V_84 , V_85 ;
T_7 V_138 ;
V_84 = V_13 -> V_84 ;
V_85 = V_13 -> V_85 ;
V_83 = F_42 ( V_13 , V_76 ) ;
V_38 = & V_13 -> V_77 [ V_76 ] ;
V_38 -> V_76 = V_76 ;
V_38 -> V_108 = V_13 ;
V_38 -> V_24 = V_13 -> V_24 ;
V_38 -> V_132 = false ;
V_38 -> V_110 = NULL ;
F_52 ( V_38 ) ;
if ( V_83 < V_85 % V_84 )
V_82 = V_85 / V_84 + 1 ;
else
V_82 = V_85 / V_84 ;
V_135 = V_13 -> V_86 [ V_83 ] . V_139 ;
V_136 = V_13 -> V_86 [ V_83 ] . V_122 ;
V_137 = ( unsigned int ) V_136 / V_82 ;
V_138 = V_137 * ( V_76 / V_84 ) ;
V_38 -> V_63 = V_13 -> V_86 [ V_83 ] . V_140 + V_138 ;
if ( ! V_38 -> V_63 )
return - V_9 ;
V_38 -> V_141 = V_135 + V_138 ;
if ( ! V_38 -> V_141 )
return - V_9 ;
V_137 -= sizeof( struct V_89 ) ;
V_38 -> V_142 = V_38 -> V_63 + V_137 ;
V_38 -> V_143 = F_43 ( V_91 , V_137 / 2 ) ;
V_38 -> V_66 = V_137 / V_38 -> V_143 ;
if ( V_13 -> V_144 ) {
char V_145 [ 4 ] ;
snprintf ( V_145 , 4 , L_45 , V_76 ) ;
V_38 -> V_146 = F_82 ( V_145 ,
V_13 -> V_144 ) ;
V_38 -> V_147 = F_83 ( L_46 , V_148 ,
V_38 -> V_146 , V_38 ,
& V_149 ) ;
} else {
V_38 -> V_146 = NULL ;
V_38 -> V_147 = NULL ;
}
F_84 ( & V_38 -> V_109 , F_76 ) ;
F_85 ( & V_38 -> V_114 , F_56 ) ;
F_86 ( & V_38 -> V_93 ) ;
F_86 ( & V_38 -> V_150 ) ;
F_87 ( & V_38 -> V_151 ) ;
F_87 ( & V_38 -> V_152 ) ;
F_87 ( & V_38 -> V_94 ) ;
F_87 ( & V_38 -> V_153 ) ;
F_88 ( & V_38 -> V_134 , V_154 ,
( unsigned long ) V_38 ) ;
return 0 ;
}
static int F_89 ( struct V_155 * V_156 , struct V_80 * V_24 )
{
struct V_12 * V_13 ;
struct V_78 * V_79 ;
unsigned int V_84 , V_85 , V_157 , V_158 ;
T_7 V_117 ;
int V_21 ;
int V_8 , V_22 ;
V_84 = F_90 ( V_24 ) ;
if ( ! V_24 -> V_159 -> V_160 ) {
F_12 ( & V_24 -> V_2 , L_47 ) ;
return - V_9 ;
}
if ( F_91 ( V_24 ) )
F_75 ( & V_24 -> V_2 ,
L_48 ) ;
if ( F_92 ( V_24 ) )
F_75 ( & V_24 -> V_2 ,
L_49 ) ;
if ( F_93 ( V_24 ) != V_161 )
F_94 ( & V_24 -> V_2 , L_50 ) ;
V_21 = F_22 ( & V_24 -> V_2 ) ;
V_13 = F_23 ( sizeof( * V_13 ) , V_25 , V_21 ) ;
if ( ! V_13 )
return - V_26 ;
V_13 -> V_24 = V_24 ;
V_157 = F_65 ( V_24 ) ;
if ( V_157 < V_162 ) {
V_13 -> V_84 = 0 ;
V_8 = - V_9 ;
goto V_27;
}
V_158 = ( V_157 - V_124 ) / 2 ;
V_13 -> V_84 = F_43 ( V_84 , V_158 ) ;
V_13 -> V_86 = F_23 ( V_84 * sizeof( * V_13 -> V_86 ) ,
V_25 , V_21 ) ;
if ( ! V_13 -> V_86 ) {
V_8 = - V_26 ;
goto V_27;
}
for ( V_22 = 0 ; V_22 < V_84 ; V_22 ++ ) {
V_79 = & V_13 -> V_86 [ V_22 ] ;
V_8 = F_95 ( V_24 , V_100 , V_22 , & V_79 -> V_105 ,
& V_79 -> V_104 , NULL ) ;
if ( V_8 )
goto V_163;
V_8 = F_96 ( V_24 , V_22 , & V_79 -> V_139 ,
& V_79 -> V_122 ) ;
if ( V_8 )
goto V_163;
V_79 -> V_140 = F_97 ( V_79 -> V_139 , V_79 -> V_122 ) ;
if ( ! V_79 -> V_140 ) {
V_8 = - V_26 ;
goto V_163;
}
V_79 -> V_101 = 0 ;
V_79 -> V_88 = 0 ;
V_79 -> V_87 = NULL ;
V_79 -> V_102 = 0 ;
}
V_117 = F_98 ( V_24 ) ;
V_85 = F_99 ( V_117 ) ;
if ( V_164 && V_164 < V_85 )
V_85 = V_164 ;
else if ( V_13 -> V_84 < V_85 )
V_85 = V_13 -> V_84 ;
V_117 &= F_63 ( V_85 ) - 1 ;
V_13 -> V_85 = V_85 ;
V_13 -> V_117 = V_117 ;
V_13 -> V_118 = V_117 ;
V_13 -> V_77 = F_23 ( V_85 * sizeof( * V_13 -> V_77 ) ,
V_25 , V_21 ) ;
if ( ! V_13 -> V_77 ) {
V_8 = - V_26 ;
goto V_163;
}
if ( V_165 ) {
V_13 -> V_144 =
F_82 ( F_100 ( V_24 -> V_99 ) ,
V_165 ) ;
}
for ( V_22 = 0 ; V_22 < V_85 ; V_22 ++ ) {
V_8 = F_81 ( V_13 , V_22 ) ;
if ( V_8 )
goto V_166;
}
F_84 ( & V_13 -> V_109 , F_70 ) ;
F_85 ( & V_13 -> V_114 , F_67 ) ;
V_8 = F_101 ( V_24 , V_13 , & V_167 ) ;
if ( V_8 )
goto V_166;
F_87 ( & V_13 -> V_31 ) ;
V_8 = F_8 ( V_13 ) ;
if ( V_8 )
goto V_168;
V_13 -> V_44 = false ;
F_102 ( V_24 , V_169 , V_170 ) ;
F_103 ( V_24 ) ;
return 0 ;
V_168:
F_104 ( V_24 ) ;
V_166:
F_17 ( V_13 -> V_77 ) ;
V_163:
while ( V_22 -- ) {
V_79 = & V_13 -> V_86 [ V_22 ] ;
F_105 ( V_79 -> V_140 ) ;
}
F_17 ( V_13 -> V_86 ) ;
V_27:
F_17 ( V_13 ) ;
return V_8 ;
}
static void F_106 ( struct V_155 * V_156 , struct V_80 * V_24 )
{
struct V_12 * V_13 = V_24 -> V_171 ;
struct V_37 * V_38 ;
T_7 V_116 ;
int V_22 ;
F_62 ( V_13 ) ;
F_64 ( & V_13 -> V_114 ) ;
F_55 ( & V_13 -> V_109 ) ;
V_116 = V_13 -> V_117 & ~ V_13 -> V_118 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_85 ; V_22 ++ ) {
V_38 = & V_13 -> V_77 [ V_22 ] ;
if ( V_116 & F_63 ( V_22 ) )
F_107 ( V_38 ) ;
F_108 ( V_38 -> V_146 ) ;
}
F_109 ( V_24 ) ;
F_104 ( V_24 ) ;
F_10 ( V_13 ) ;
for ( V_22 = V_13 -> V_84 ; V_22 -- ; ) {
F_44 ( V_13 , V_22 ) ;
F_105 ( V_13 -> V_86 [ V_22 ] . V_140 ) ;
}
F_17 ( V_13 -> V_77 ) ;
F_17 ( V_13 -> V_86 ) ;
F_17 ( V_13 ) ;
}
static void F_110 ( struct V_37 * V_38 )
{
struct V_73 * V_14 ;
void * V_111 ;
unsigned int V_172 ;
unsigned long V_173 ;
F_35 ( & V_38 -> V_93 , V_173 ) ;
while ( ! F_21 ( & V_38 -> V_151 ) ) {
V_14 = F_38 ( & V_38 -> V_151 ,
struct V_73 , V_14 ) ;
if ( ! ( V_14 -> V_72 & V_174 ) )
break;
V_14 -> V_175 -> V_72 = 0 ;
F_111 ( V_14 -> V_54 , & V_38 -> V_142 -> V_14 ) ;
V_111 = V_14 -> V_111 ;
V_172 = V_14 -> V_172 ;
F_40 ( & V_14 -> V_14 , & V_38 -> V_94 ) ;
F_36 ( & V_38 -> V_93 , V_173 ) ;
if ( V_38 -> V_176 && V_38 -> V_132 )
V_38 -> V_176 ( V_38 , V_38 -> V_111 , V_111 , V_172 ) ;
F_35 ( & V_38 -> V_93 , V_173 ) ;
}
F_36 ( & V_38 -> V_93 , V_173 ) ;
}
static void F_112 ( void * V_119 ,
const struct V_177 * V_178 )
{
struct V_73 * V_14 = V_119 ;
if ( V_178 ) {
enum V_179 V_180 = V_178 -> V_181 ;
switch ( V_180 ) {
case V_182 :
case V_183 :
V_14 -> V_184 ++ ;
case V_185 :
{
struct V_37 * V_38 = V_14 -> V_38 ;
void * V_95 = V_38 -> V_53 + V_38 -> V_90 *
V_38 -> V_54 ;
F_113 ( V_14 , V_95 ) ;
V_38 -> V_47 ++ ;
return;
}
case V_186 :
default:
break;
}
}
V_14 -> V_72 |= V_174 ;
F_110 ( V_14 -> V_38 ) ;
}
static void F_113 ( struct V_73 * V_14 , void * V_95 )
{
void * V_39 = V_14 -> V_39 ;
T_3 V_172 = V_14 -> V_172 ;
memcpy ( V_39 , V_95 , V_172 ) ;
F_114 () ;
F_112 ( V_14 , NULL ) ;
}
static int F_115 ( struct V_73 * V_14 , void * V_95 )
{
struct V_187 * V_188 ;
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_189 * V_190 = V_38 -> V_68 ;
struct V_191 * V_1 ;
T_3 V_192 , V_193 , V_172 ;
struct V_194 * V_195 ;
T_10 V_196 ;
void * V_39 = V_14 -> V_39 ;
V_172 = V_14 -> V_172 ;
V_1 = V_190 -> V_1 ;
V_192 = ( T_3 ) V_95 & ~ V_197 ;
V_193 = ( T_3 ) V_39 & ~ V_197 ;
if ( ! F_116 ( V_1 , V_192 , V_193 , V_172 ) )
goto V_27;
V_195 = F_117 ( V_1 -> V_2 , 2 , V_198 ) ;
if ( ! V_195 )
goto V_27;
V_195 -> V_172 = V_172 ;
V_195 -> V_199 [ 0 ] = F_118 ( V_1 -> V_2 , F_119 ( V_95 ) ,
V_192 , V_172 , V_200 ) ;
if ( F_120 ( V_1 -> V_2 , V_195 -> V_199 [ 0 ] ) )
goto V_201;
V_195 -> V_202 = 1 ;
V_195 -> V_199 [ 1 ] = F_118 ( V_1 -> V_2 , F_119 ( V_39 ) ,
V_193 , V_172 , V_203 ) ;
if ( F_120 ( V_1 -> V_2 , V_195 -> V_199 [ 1 ] ) )
goto V_201;
V_195 -> V_204 = 1 ;
V_188 = V_1 -> V_205 ( V_190 , V_195 -> V_199 [ 1 ] ,
V_195 -> V_199 [ 0 ] , V_172 ,
V_206 ) ;
if ( ! V_188 )
goto V_201;
V_188 -> V_207 = F_112 ;
V_188 -> V_208 = V_14 ;
F_121 ( V_188 , V_195 ) ;
V_196 = F_122 ( V_188 ) ;
if ( F_123 ( V_196 ) )
goto V_209;
F_124 ( V_195 ) ;
V_38 -> V_210 = V_196 ;
V_38 -> V_48 ++ ;
return 0 ;
V_209:
F_124 ( V_195 ) ;
V_201:
F_124 ( V_195 ) ;
V_27:
return - V_211 ;
}
static void F_125 ( struct V_73 * V_14 , void * V_95 )
{
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_189 * V_190 = V_38 -> V_68 ;
int V_178 ;
if ( ! V_190 )
goto V_27;
if ( V_14 -> V_172 < V_212 )
goto V_27;
V_178 = F_115 ( V_14 , V_95 ) ;
if ( V_178 < 0 )
goto V_27;
if ( ! V_14 -> V_213 )
V_38 -> V_48 ++ ;
return;
V_27:
F_113 ( V_14 , V_95 ) ;
V_38 -> V_47 ++ ;
}
static int F_126 ( struct V_37 * V_38 )
{
struct V_96 * V_214 ;
struct V_73 * V_14 ;
void * V_95 ;
V_95 = V_38 -> V_53 + V_38 -> V_90 * V_38 -> V_54 ;
V_214 = V_95 + V_38 -> V_90 - sizeof( struct V_96 ) ;
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 , L_51 ,
V_38 -> V_76 , V_214 -> V_215 , V_214 -> V_172 , V_214 -> V_72 ) ;
if ( ! ( V_214 -> V_72 & V_174 ) ) {
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 , L_52 ) ;
V_38 -> V_49 ++ ;
return - V_216 ;
}
if ( V_214 -> V_72 & V_217 ) {
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 , L_53 ) ;
F_60 ( V_38 ) ;
V_214 -> V_72 = 0 ;
return - V_216 ;
}
if ( V_214 -> V_215 != ( T_8 ) V_38 -> V_46 ) {
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 ,
L_54 ,
V_38 -> V_46 , V_214 -> V_215 ) ;
V_38 -> V_52 ++ ;
return - V_106 ;
}
V_14 = F_39 ( & V_38 -> V_93 , & V_38 -> V_152 , & V_38 -> V_151 ) ;
if ( ! V_14 ) {
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 , L_55 ) ;
V_38 -> V_50 ++ ;
return - V_216 ;
}
V_14 -> V_175 = V_214 ;
V_14 -> V_54 = V_38 -> V_54 ;
if ( V_214 -> V_172 > V_14 -> V_172 ) {
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 ,
L_56 ,
V_214 -> V_172 , V_14 -> V_172 ) ;
V_38 -> V_51 ++ ;
V_14 -> V_172 = - V_106 ;
V_14 -> V_72 |= V_174 ;
F_110 ( V_38 ) ;
} else {
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 ,
L_57 ,
V_38 -> V_54 , V_214 -> V_215 , V_214 -> V_172 , V_14 -> V_172 ) ;
V_38 -> V_45 += V_214 -> V_172 ;
V_38 -> V_46 ++ ;
V_14 -> V_172 = V_214 -> V_172 ;
F_125 ( V_14 , V_95 ) ;
}
V_38 -> V_54 ++ ;
V_38 -> V_54 %= V_38 -> V_55 ;
return 0 ;
}
static void V_154 ( unsigned long V_119 )
{
struct V_37 * V_38 = ( void * ) V_119 ;
int V_8 , V_22 ;
F_75 ( & V_38 -> V_24 -> V_99 -> V_2 , L_58 ,
V_218 , V_38 -> V_76 ) ;
for ( V_22 = 0 ; V_22 < V_38 -> V_55 ; V_22 ++ ) {
V_8 = F_126 ( V_38 ) ;
if ( V_8 )
break;
}
if ( V_22 && V_38 -> V_68 )
F_127 ( V_38 -> V_68 ) ;
if ( V_22 == V_38 -> V_55 ) {
if ( V_38 -> V_107 )
F_80 ( & V_38 -> V_134 ) ;
} else if ( F_128 ( V_38 -> V_24 ) & F_63 ( V_38 -> V_76 ) ) {
F_129 ( V_38 -> V_24 , F_63 ( V_38 -> V_76 ) ) ;
F_128 ( V_38 -> V_24 ) ;
if ( V_38 -> V_107 )
F_80 ( & V_38 -> V_134 ) ;
}
}
static void F_130 ( void * V_119 ,
const struct V_177 * V_178 )
{
struct V_73 * V_14 = V_119 ;
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_96 T_11 * V_214 = V_14 -> V_219 ;
if ( V_178 ) {
enum V_179 V_180 = V_178 -> V_181 ;
switch ( V_180 ) {
case V_182 :
case V_183 :
V_14 -> V_184 ++ ;
case V_185 :
{
void T_11 * V_95 =
V_38 -> V_63 + V_38 -> V_143 *
V_14 -> V_64 ;
F_131 ( V_14 , V_95 ) ;
V_38 -> V_59 ++ ;
return;
}
case V_186 :
default:
break;
}
}
F_111 ( V_14 -> V_72 | V_174 , & V_214 -> V_72 ) ;
F_132 ( V_38 -> V_24 , F_63 ( V_38 -> V_76 ) ) ;
if ( V_14 -> V_172 > 0 ) {
V_38 -> V_57 += V_14 -> V_172 ;
if ( V_38 -> V_220 )
V_38 -> V_220 ( V_38 , V_38 -> V_111 , V_14 -> V_111 ,
V_14 -> V_172 ) ;
}
F_34 ( & V_38 -> V_150 , & V_14 -> V_14 , & V_38 -> V_153 ) ;
}
static void F_131 ( struct V_73 * V_14 , void T_11 * V_95 )
{
#ifdef F_133
F_134 ( V_95 , V_14 -> V_39 , V_14 -> V_172 ) ;
#else
F_135 ( V_95 , V_14 -> V_39 , V_14 -> V_172 ) ;
#endif
F_114 () ;
F_130 ( V_14 , NULL ) ;
}
static int F_136 ( struct V_37 * V_38 ,
struct V_73 * V_14 )
{
struct V_187 * V_188 ;
struct V_189 * V_190 = V_38 -> V_67 ;
struct V_191 * V_1 ;
T_3 V_172 = V_14 -> V_172 ;
void * V_39 = V_14 -> V_39 ;
T_3 V_221 , V_193 ;
struct V_194 * V_195 ;
T_12 V_222 ;
T_10 V_196 ;
V_1 = V_190 -> V_1 ;
V_222 = V_38 -> V_141 + V_38 -> V_143 * V_14 -> V_64 ;
V_193 = ( T_3 ) V_39 & ~ V_197 ;
V_221 = ( T_3 ) V_222 & ~ V_197 ;
if ( ! F_116 ( V_1 , V_193 , V_221 , V_172 ) )
goto V_27;
V_195 = F_117 ( V_1 -> V_2 , 1 , V_198 ) ;
if ( ! V_195 )
goto V_27;
V_195 -> V_172 = V_172 ;
V_195 -> V_199 [ 0 ] = F_118 ( V_1 -> V_2 , F_119 ( V_39 ) ,
V_193 , V_172 , V_200 ) ;
if ( F_120 ( V_1 -> V_2 , V_195 -> V_199 [ 0 ] ) )
goto V_201;
V_195 -> V_202 = 1 ;
V_188 = V_1 -> V_205 ( V_190 , V_222 , V_195 -> V_199 [ 0 ] , V_172 ,
V_206 ) ;
if ( ! V_188 )
goto V_201;
V_188 -> V_207 = F_130 ;
V_188 -> V_208 = V_14 ;
F_121 ( V_188 , V_195 ) ;
V_196 = F_122 ( V_188 ) ;
if ( F_123 ( V_196 ) )
goto V_209;
F_124 ( V_195 ) ;
F_127 ( V_190 ) ;
return 0 ;
V_209:
F_124 ( V_195 ) ;
V_201:
F_124 ( V_195 ) ;
V_27:
return - V_211 ;
}
static void F_137 ( struct V_37 * V_38 ,
struct V_73 * V_14 )
{
struct V_96 T_11 * V_214 ;
struct V_189 * V_190 = V_38 -> V_67 ;
void T_11 * V_95 ;
int V_178 ;
V_14 -> V_64 = V_38 -> V_64 ;
V_95 = V_38 -> V_63 + V_38 -> V_143 * V_14 -> V_64 ;
V_214 = V_95 + V_38 -> V_143 - sizeof( struct V_96 ) ;
V_14 -> V_219 = V_214 ;
F_111 ( V_14 -> V_172 , & V_214 -> V_172 ) ;
F_111 ( ( T_8 ) V_38 -> V_58 , & V_214 -> V_215 ) ;
if ( ! V_190 )
goto V_27;
if ( V_14 -> V_172 < V_212 )
goto V_27;
V_178 = F_136 ( V_38 , V_14 ) ;
if ( V_178 < 0 )
goto V_27;
if ( ! V_14 -> V_213 )
V_38 -> V_60 ++ ;
return;
V_27:
F_131 ( V_14 , V_95 ) ;
V_38 -> V_59 ++ ;
}
static int F_138 ( struct V_37 * V_38 ,
struct V_73 * V_14 )
{
if ( V_38 -> V_64 == V_38 -> V_65 -> V_14 ) {
V_38 -> V_61 ++ ;
return - V_216 ;
}
if ( V_14 -> V_172 > V_38 -> V_143 - sizeof( struct V_96 ) ) {
if ( V_38 -> V_220 )
V_38 -> V_220 ( V_38 , V_38 -> V_111 , NULL , - V_106 ) ;
F_34 ( & V_38 -> V_150 , & V_14 -> V_14 ,
& V_38 -> V_153 ) ;
return 0 ;
}
F_137 ( V_38 , V_14 ) ;
V_38 -> V_64 ++ ;
V_38 -> V_64 %= V_38 -> V_66 ;
V_38 -> V_58 ++ ;
return 0 ;
}
static void F_139 ( struct V_37 * V_38 )
{
struct V_98 * V_99 = V_38 -> V_24 -> V_99 ;
struct V_73 * V_14 ;
int V_22 , V_8 ;
if ( ! V_38 -> V_44 )
return;
F_54 ( & V_99 -> V_2 , L_59 , V_38 -> V_76 ) ;
for ( V_22 = 0 ; V_22 < V_115 ; V_22 ++ ) {
V_14 = F_37 ( & V_38 -> V_150 , & V_38 -> V_153 ) ;
if ( V_14 )
break;
F_140 ( 100 ) ;
}
if ( ! V_14 )
return;
V_14 -> V_111 = NULL ;
V_14 -> V_39 = NULL ;
V_14 -> V_172 = 0 ;
V_14 -> V_72 = V_217 ;
V_8 = F_138 ( V_38 , V_14 ) ;
if ( V_8 )
F_12 ( & V_99 -> V_2 , L_60 ,
V_38 -> V_76 ) ;
F_52 ( V_38 ) ;
}
static bool F_141 ( struct V_189 * V_190 , void * V_21 )
{
return F_22 ( & V_190 -> V_2 -> V_1 ) == ( int ) ( unsigned long ) V_21 ;
}
struct V_37 *
F_142 ( void * V_119 , struct V_1 * V_17 ,
const struct V_223 * V_224 )
{
struct V_80 * V_24 ;
struct V_98 * V_99 ;
struct V_12 * V_13 ;
struct V_73 * V_14 ;
struct V_37 * V_38 ;
T_7 V_225 ;
unsigned int V_226 ;
T_13 V_227 ;
int V_21 ;
int V_22 ;
V_24 = F_143 ( V_17 -> V_19 ) ;
V_99 = V_24 -> V_99 ;
V_13 = V_24 -> V_171 ;
V_21 = F_22 ( & V_24 -> V_2 ) ;
V_226 = F_144 ( V_13 -> V_118 ) ;
if ( ! V_226 )
goto V_27;
V_226 -- ;
V_38 = & V_13 -> V_77 [ V_226 ] ;
V_225 = F_63 ( V_38 -> V_76 ) ;
V_13 -> V_118 &= ~ V_225 ;
V_38 -> V_111 = V_119 ;
V_38 -> V_176 = V_224 -> V_176 ;
V_38 -> V_220 = V_224 -> V_220 ;
V_38 -> V_110 = V_224 -> V_110 ;
F_145 ( V_227 ) ;
F_146 ( V_228 , V_227 ) ;
if ( V_229 ) {
V_38 -> V_67 =
F_147 ( V_227 , F_141 ,
( void * ) ( unsigned long ) V_21 ) ;
if ( ! V_38 -> V_67 )
F_54 ( & V_99 -> V_2 , L_61 ) ;
V_38 -> V_68 =
F_147 ( V_227 , F_141 ,
( void * ) ( unsigned long ) V_21 ) ;
if ( ! V_38 -> V_68 )
F_54 ( & V_99 -> V_2 , L_62 ) ;
} else {
V_38 -> V_67 = NULL ;
V_38 -> V_68 = NULL ;
}
F_75 ( & V_99 -> V_2 , L_63 ,
V_38 -> V_67 ? L_64 : L_65 ) ;
F_75 ( & V_99 -> V_2 , L_66 ,
V_38 -> V_68 ? L_64 : L_65 ) ;
for ( V_22 = 0 ; V_22 < V_230 ; V_22 ++ ) {
V_14 = F_23 ( sizeof( * V_14 ) , V_92 , V_21 ) ;
if ( ! V_14 )
goto V_163;
V_14 -> V_38 = V_38 ;
F_34 ( & V_38 -> V_93 , & V_14 -> V_14 ,
& V_38 -> V_94 ) ;
}
V_38 -> V_56 = V_230 ;
for ( V_22 = 0 ; V_22 < V_38 -> V_66 ; V_22 ++ ) {
V_14 = F_23 ( sizeof( * V_14 ) , V_92 , V_21 ) ;
if ( ! V_14 )
goto V_166;
V_14 -> V_38 = V_38 ;
F_34 ( & V_38 -> V_150 , & V_14 -> V_14 ,
& V_38 -> V_153 ) ;
}
F_129 ( V_38 -> V_24 , V_225 ) ;
F_148 ( V_38 -> V_24 , V_225 ) ;
F_54 ( & V_99 -> V_2 , L_67 , V_38 -> V_76 ) ;
return V_38 ;
V_166:
while ( ( V_14 = F_37 ( & V_38 -> V_150 , & V_38 -> V_153 ) ) )
F_17 ( V_14 ) ;
V_163:
V_38 -> V_56 = 0 ;
while ( ( V_14 = F_37 ( & V_38 -> V_93 , & V_38 -> V_94 ) ) )
F_17 ( V_14 ) ;
if ( V_38 -> V_67 )
F_149 ( V_38 -> V_67 ) ;
if ( V_38 -> V_68 )
F_149 ( V_38 -> V_68 ) ;
V_13 -> V_118 |= V_225 ;
V_27:
return NULL ;
}
void F_107 ( struct V_37 * V_38 )
{
struct V_98 * V_99 ;
struct V_73 * V_14 ;
T_7 V_225 ;
if ( ! V_38 )
return;
V_99 = V_38 -> V_24 -> V_99 ;
V_38 -> V_107 = false ;
if ( V_38 -> V_67 ) {
struct V_189 * V_190 = V_38 -> V_67 ;
V_38 -> V_67 = NULL ;
F_150 ( V_190 , V_38 -> V_210 ) ;
F_151 ( V_190 ) ;
F_149 ( V_190 ) ;
}
if ( V_38 -> V_68 ) {
struct V_189 * V_190 = V_38 -> V_68 ;
V_38 -> V_68 = NULL ;
F_150 ( V_190 , V_38 -> V_210 ) ;
F_151 ( V_190 ) ;
F_149 ( V_190 ) ;
}
V_225 = F_63 ( V_38 -> V_76 ) ;
F_152 ( V_38 -> V_24 , V_225 ) ;
F_153 ( & V_38 -> V_134 ) ;
F_55 ( & V_38 -> V_109 ) ;
V_38 -> V_111 = NULL ;
V_38 -> V_176 = NULL ;
V_38 -> V_220 = NULL ;
V_38 -> V_110 = NULL ;
while ( ( V_14 = F_37 ( & V_38 -> V_93 , & V_38 -> V_94 ) ) )
F_17 ( V_14 ) ;
while ( ( V_14 = F_37 ( & V_38 -> V_93 , & V_38 -> V_152 ) ) ) {
F_94 ( & V_99 -> V_2 , L_68 ) ;
F_17 ( V_14 ) ;
}
while ( ( V_14 = F_37 ( & V_38 -> V_93 , & V_38 -> V_151 ) ) ) {
F_94 ( & V_99 -> V_2 , L_69 ) ;
F_17 ( V_14 ) ;
}
while ( ( V_14 = F_37 ( & V_38 -> V_150 , & V_38 -> V_153 ) ) )
F_17 ( V_14 ) ;
V_38 -> V_108 -> V_118 |= V_225 ;
F_54 ( & V_99 -> V_2 , L_70 , V_38 -> V_76 ) ;
}
void * F_154 ( struct V_37 * V_38 , unsigned int * V_172 )
{
struct V_73 * V_14 ;
void * V_39 ;
if ( ! V_38 || V_38 -> V_132 )
return NULL ;
V_14 = F_37 ( & V_38 -> V_93 , & V_38 -> V_152 ) ;
if ( ! V_14 )
return NULL ;
V_39 = V_14 -> V_111 ;
* V_172 = V_14 -> V_172 ;
F_34 ( & V_38 -> V_93 , & V_14 -> V_14 , & V_38 -> V_94 ) ;
return V_39 ;
}
int F_155 ( struct V_37 * V_38 , void * V_231 , void * V_119 ,
unsigned int V_172 )
{
struct V_73 * V_14 ;
if ( ! V_38 )
return - V_9 ;
V_14 = F_37 ( & V_38 -> V_93 , & V_38 -> V_94 ) ;
if ( ! V_14 )
return - V_26 ;
V_14 -> V_111 = V_231 ;
V_14 -> V_39 = V_119 ;
V_14 -> V_172 = V_172 ;
V_14 -> V_72 = 0 ;
V_14 -> V_213 = 0 ;
V_14 -> V_184 = 0 ;
V_14 -> V_54 = 0 ;
F_34 ( & V_38 -> V_93 , & V_14 -> V_14 , & V_38 -> V_152 ) ;
if ( V_38 -> V_107 )
F_80 ( & V_38 -> V_134 ) ;
return 0 ;
}
int F_156 ( struct V_37 * V_38 , void * V_231 , void * V_119 ,
unsigned int V_172 )
{
struct V_73 * V_14 ;
int V_8 ;
if ( ! V_38 || ! V_38 -> V_44 || ! V_172 )
return - V_9 ;
V_14 = F_37 ( & V_38 -> V_150 , & V_38 -> V_153 ) ;
if ( ! V_14 ) {
V_38 -> V_62 ++ ;
return - V_232 ;
}
V_14 -> V_111 = V_231 ;
V_14 -> V_39 = V_119 ;
V_14 -> V_172 = V_172 ;
V_14 -> V_72 = 0 ;
V_14 -> V_184 = 0 ;
V_14 -> V_213 = 0 ;
V_14 -> V_64 = 0 ;
V_8 = F_138 ( V_38 , V_14 ) ;
if ( V_8 )
F_34 ( & V_38 -> V_150 , & V_14 -> V_14 ,
& V_38 -> V_153 ) ;
return V_8 ;
}
void F_157 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return;
V_38 -> V_132 = true ;
if ( V_38 -> V_108 -> V_44 )
F_58 ( & V_38 -> V_109 , 0 ) ;
}
void F_158 ( struct V_37 * V_38 )
{
int V_120 ;
if ( ! V_38 )
return;
V_38 -> V_132 = false ;
V_120 = F_74 ( V_38 -> V_24 , V_133 ) ;
F_71 ( V_38 -> V_24 , V_100 , V_133 , V_120 & ~ F_78 ( V_38 -> V_76 ) ) ;
if ( V_38 -> V_44 )
F_139 ( V_38 ) ;
else
F_55 ( & V_38 -> V_109 ) ;
}
bool F_159 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return false ;
return V_38 -> V_44 ;
}
unsigned char F_160 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return 0 ;
return V_38 -> V_76 ;
}
unsigned int F_161 ( struct V_37 * V_38 )
{
unsigned int V_233 ;
unsigned int V_234 ;
struct V_189 * V_235 , * V_236 ;
if ( ! V_38 )
return 0 ;
V_235 = V_38 -> V_68 ;
V_236 = V_38 -> V_67 ;
V_234 = F_162 ( V_235 ? V_235 -> V_1 -> V_234 : 0 ,
V_236 ? V_236 -> V_1 -> V_234 : 0 ) ;
V_233 = V_38 -> V_143 - sizeof( struct V_96 ) ;
V_233 = F_163 ( V_233 , 1 << V_234 ) ;
return V_233 ;
}
unsigned int F_32 ( struct V_37 * V_38 )
{
unsigned int V_237 = V_38 -> V_64 ;
unsigned int V_238 = V_38 -> V_65 -> V_14 ;
return V_238 > V_237 ? V_238 - V_237 : V_38 -> V_66 + V_238 - V_237 ;
}
static void F_164 ( void * V_119 , int V_239 )
{
struct V_12 * V_13 = V_119 ;
struct V_37 * V_38 ;
T_7 V_240 ;
unsigned int V_76 ;
V_240 = ( V_13 -> V_117 & ~ V_13 -> V_118 &
F_165 ( V_13 -> V_24 , V_239 ) ) ;
while ( V_240 ) {
V_76 = F_166 ( V_240 ) ;
V_38 = & V_13 -> V_77 [ V_76 ] ;
if ( V_38 -> V_107 )
F_80 ( & V_38 -> V_134 ) ;
V_240 &= ~ F_63 ( V_76 ) ;
}
}
static int T_14 F_167 ( void )
{
int V_8 ;
F_168 ( L_71 , V_241 , V_242 ) ;
if ( F_169 () )
V_165 = F_82 ( V_243 , NULL ) ;
V_8 = F_170 ( & V_29 ) ;
if ( V_8 )
goto V_244;
V_8 = F_171 ( & V_6 ) ;
if ( V_8 )
goto V_245;
return 0 ;
V_245:
F_172 ( & V_29 ) ;
V_244:
F_108 ( V_165 ) ;
return V_8 ;
}
static void T_15 F_173 ( void )
{
F_174 ( & V_6 ) ;
F_172 ( & V_29 ) ;
F_108 ( V_165 ) ;
}
