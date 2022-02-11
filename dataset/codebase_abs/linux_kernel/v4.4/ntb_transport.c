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
L_23 ,
V_38 -> V_64 -> V_14 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_24 , V_38 -> V_65 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_25 ,
F_32 ( V_38 ) ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_26 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_27 ,
V_38 -> V_66 ? L_28 : L_29 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_30 ,
V_38 -> V_67 ? L_28 : L_29 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_31 ,
V_38 -> V_44 ? L_32 : L_33 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_26 ) ;
if ( V_41 > V_42 )
V_41 = V_42 ;
V_40 = F_33 ( V_34 , V_35 , V_36 , V_39 , V_41 ) ;
F_17 ( V_39 ) ;
return V_40 ;
}
static void F_34 ( T_5 * V_68 , struct V_69 * V_14 ,
struct V_69 * V_70 )
{
unsigned long V_71 ;
F_35 ( V_68 , V_71 ) ;
F_9 ( V_14 , V_70 ) ;
F_36 ( V_68 , V_71 ) ;
}
static struct V_72 * F_37 ( T_5 * V_68 ,
struct V_69 * V_70 )
{
struct V_72 * V_14 ;
unsigned long V_71 ;
F_35 ( V_68 , V_71 ) ;
if ( F_21 ( V_70 ) ) {
V_14 = NULL ;
goto V_73;
}
V_14 = F_38 ( V_70 , struct V_72 , V_14 ) ;
F_13 ( & V_14 -> V_14 ) ;
V_73:
F_36 ( V_68 , V_71 ) ;
return V_14 ;
}
static struct V_72 * F_39 ( T_5 * V_68 ,
struct V_69 * V_70 ,
struct V_69 * V_74 )
{
struct V_72 * V_14 ;
unsigned long V_71 ;
F_35 ( V_68 , V_71 ) ;
if ( F_21 ( V_70 ) ) {
V_14 = NULL ;
} else {
V_14 = F_38 ( V_70 , struct V_72 , V_14 ) ;
F_40 ( & V_14 -> V_14 , V_74 ) ;
}
F_36 ( V_68 , V_71 ) ;
return V_14 ;
}
static int F_41 ( struct V_12 * V_13 ,
unsigned int V_75 )
{
struct V_37 * V_38 = & V_13 -> V_76 [ V_75 ] ;
struct V_77 * V_78 ;
unsigned int V_79 , V_80 ;
unsigned int V_81 , V_82 , V_83 ;
unsigned int V_22 ;
V_82 = V_13 -> V_82 ;
V_83 = V_13 -> V_83 ;
V_81 = F_42 ( V_13 , V_75 ) ;
V_78 = & V_13 -> V_84 [ V_81 ] ;
if ( ! V_78 -> V_85 )
return - V_26 ;
if ( V_83 % V_82 && V_81 + 1 < V_83 / V_82 )
V_80 = V_83 / V_82 + 1 ;
else
V_80 = V_83 / V_82 ;
V_79 = ( unsigned int ) V_78 -> V_86 / V_80 ;
V_38 -> V_53 = V_78 -> V_85 + V_79 * ( V_75 / V_82 ) ;
V_79 -= sizeof( struct V_87 ) ;
V_38 -> V_64 = V_38 -> V_53 + V_79 ;
V_38 -> V_88 = F_43 ( V_89 , V_79 / 2 ) ;
V_38 -> V_55 = V_79 / V_38 -> V_88 ;
V_38 -> V_54 = 0 ;
V_38 -> V_64 -> V_14 = V_38 -> V_55 - 1 ;
for ( V_22 = 0 ; V_22 < V_38 -> V_55 ; V_22 ++ ) {
void * V_90 = ( V_38 -> V_53 + V_38 -> V_88 * ( V_22 + 1 ) -
sizeof( struct V_91 ) ) ;
memset ( V_90 , 0 , sizeof( struct V_91 ) ) ;
}
V_38 -> V_46 = 0 ;
V_38 -> V_57 = 0 ;
V_38 -> V_63 = 0 ;
return 0 ;
}
static void F_44 ( struct V_12 * V_13 , int V_92 )
{
struct V_77 * V_78 = & V_13 -> V_84 [ V_92 ] ;
struct V_93 * V_94 = V_13 -> V_24 -> V_94 ;
if ( ! V_78 -> V_85 )
return;
F_45 ( V_13 -> V_24 , V_92 ) ;
F_46 ( & V_94 -> V_2 , V_78 -> V_95 ,
V_78 -> V_85 , V_78 -> V_96 ) ;
V_78 -> V_86 = 0 ;
V_78 -> V_95 = 0 ;
V_78 -> V_85 = NULL ;
}
static int F_47 ( struct V_12 * V_13 , int V_92 ,
T_6 V_97 )
{
struct V_77 * V_78 = & V_13 -> V_84 [ V_92 ] ;
struct V_93 * V_94 = V_13 -> V_24 -> V_94 ;
T_3 V_86 , V_95 ;
int V_8 ;
if ( ! V_97 )
return - V_9 ;
V_86 = F_48 ( V_97 , V_78 -> V_98 ) ;
V_95 = F_48 ( V_97 , V_78 -> V_99 ) ;
if ( V_78 -> V_86 == V_86 )
return 0 ;
if ( V_78 -> V_95 )
F_44 ( V_13 , V_92 ) ;
V_78 -> V_86 = V_86 ;
V_78 -> V_95 = V_95 ;
V_78 -> V_85 = F_49 ( & V_94 -> V_2 , V_95 ,
& V_78 -> V_96 , V_25 ) ;
if ( ! V_78 -> V_85 ) {
V_78 -> V_86 = 0 ;
V_78 -> V_95 = 0 ;
F_12 ( & V_94 -> V_2 , L_34 ,
V_95 ) ;
return - V_26 ;
}
if ( ! F_50 ( V_78 -> V_96 , V_78 -> V_99 ) ) {
F_12 ( & V_94 -> V_2 , L_35 ,
& V_78 -> V_96 ) ;
F_44 ( V_13 , V_92 ) ;
return - V_26 ;
}
V_8 = F_51 ( V_13 -> V_24 , V_92 , V_78 -> V_96 , V_78 -> V_86 ) ;
if ( V_8 ) {
F_12 ( & V_94 -> V_2 , L_36 , V_92 ) ;
F_44 ( V_13 , V_92 ) ;
return - V_100 ;
}
return 0 ;
}
static void F_52 ( struct V_37 * V_38 )
{
V_38 -> V_44 = false ;
V_38 -> V_63 = 0 ;
V_38 -> V_54 = 0 ;
V_38 -> V_45 = 0 ;
V_38 -> V_46 = 0 ;
V_38 -> V_49 = 0 ;
V_38 -> V_50 = 0 ;
V_38 -> V_51 = 0 ;
V_38 -> V_52 = 0 ;
V_38 -> V_47 = 0 ;
V_38 -> V_48 = 0 ;
V_38 -> V_56 = 0 ;
V_38 -> V_57 = 0 ;
V_38 -> V_60 = 0 ;
V_38 -> V_61 = 0 ;
V_38 -> V_58 = 0 ;
V_38 -> V_59 = 0 ;
}
static void F_53 ( struct V_37 * V_38 )
{
struct V_12 * V_13 = V_38 -> V_101 ;
struct V_93 * V_94 = V_13 -> V_24 -> V_94 ;
F_54 ( & V_94 -> V_2 , L_37 , V_38 -> V_75 ) ;
F_55 ( & V_38 -> V_102 ) ;
F_52 ( V_38 ) ;
if ( V_38 -> V_103 )
V_38 -> V_103 ( V_38 -> V_104 , V_38 -> V_44 ) ;
}
static void F_56 ( struct V_105 * V_106 )
{
struct V_37 * V_38 = F_57 ( V_106 ,
struct V_37 ,
V_107 ) ;
struct V_12 * V_13 = V_38 -> V_101 ;
F_53 ( V_38 ) ;
if ( V_13 -> V_44 )
F_58 ( & V_38 -> V_102 ,
F_59 ( V_108 ) ) ;
}
static void F_60 ( struct V_37 * V_38 )
{
F_61 ( & V_38 -> V_107 ) ;
}
static void F_62 ( struct V_12 * V_13 )
{
struct V_37 * V_38 ;
T_7 V_109 ;
int V_22 ;
V_109 = V_13 -> V_110 & ~ V_13 -> V_111 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_83 ; V_22 ++ )
if ( V_109 & F_63 ( V_22 ) ) {
V_38 = & V_13 -> V_76 [ V_22 ] ;
F_53 ( V_38 ) ;
F_64 ( & V_38 -> V_107 ) ;
F_55 ( & V_38 -> V_102 ) ;
}
if ( ! V_13 -> V_44 )
F_55 ( & V_13 -> V_102 ) ;
for ( V_22 = 0 ; V_22 < V_112 ; V_22 ++ )
F_65 ( V_13 -> V_24 , V_22 , 0 ) ;
}
static void F_66 ( struct V_105 * V_106 )
{
struct V_12 * V_13 =
F_57 ( V_106 , struct V_12 , V_107 ) ;
F_62 ( V_13 ) ;
}
static void F_67 ( void * V_113 )
{
struct V_12 * V_13 = V_113 ;
if ( F_68 ( V_13 -> V_24 , NULL , NULL ) == 1 )
F_58 ( & V_13 -> V_102 , 0 ) ;
else
F_61 ( & V_13 -> V_107 ) ;
}
static void F_69 ( struct V_105 * V_106 )
{
struct V_12 * V_13 =
F_57 ( V_106 , struct V_12 , V_102 . V_106 ) ;
struct V_114 * V_24 = V_13 -> V_24 ;
struct V_93 * V_94 = V_24 -> V_94 ;
T_6 V_97 ;
T_8 V_115 ;
int V_8 , V_22 , V_116 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_82 ; V_22 ++ ) {
V_97 = V_13 -> V_84 [ V_22 ] . V_117 ;
if ( V_118 && V_97 > V_118 )
V_97 = V_118 ;
V_116 = V_119 + ( V_22 * 2 ) ;
F_70 ( V_24 , V_116 , F_71 ( V_97 ) ) ;
V_116 = V_120 + ( V_22 * 2 ) ;
F_70 ( V_24 , V_116 , F_72 ( V_97 ) ) ;
}
F_70 ( V_24 , V_121 , V_13 -> V_82 ) ;
F_70 ( V_24 , V_122 , V_13 -> V_83 ) ;
F_70 ( V_24 , V_123 , V_124 ) ;
V_115 = F_73 ( V_24 , V_123 ) ;
F_74 ( & V_94 -> V_2 , L_38 , V_115 ) ;
if ( V_115 != V_124 )
goto V_73;
V_115 = F_73 ( V_24 , V_122 ) ;
F_74 ( & V_94 -> V_2 , L_39 , V_115 ) ;
if ( V_115 != V_13 -> V_83 )
goto V_73;
V_115 = F_73 ( V_24 , V_121 ) ;
F_74 ( & V_94 -> V_2 , L_40 , V_115 ) ;
if ( V_115 != V_13 -> V_82 )
goto V_73;
for ( V_22 = 0 ; V_22 < V_13 -> V_82 ; V_22 ++ ) {
T_7 V_125 ;
V_115 = F_73 ( V_24 , V_119 + ( V_22 * 2 ) ) ;
V_125 = ( T_7 ) V_115 << 32 ;
V_115 = F_73 ( V_24 , V_120 + ( V_22 * 2 ) ) ;
V_125 |= V_115 ;
F_74 ( & V_94 -> V_2 , L_41 , V_22 , V_125 ) ;
V_8 = F_47 ( V_13 , V_22 , V_125 ) ;
if ( V_8 )
goto V_126;
}
V_13 -> V_44 = true ;
for ( V_22 = 0 ; V_22 < V_13 -> V_83 ; V_22 ++ ) {
struct V_37 * V_38 = & V_13 -> V_76 [ V_22 ] ;
F_41 ( V_13 , V_22 ) ;
if ( V_38 -> V_127 )
F_58 ( & V_38 -> V_102 , 0 ) ;
}
return;
V_126:
for ( V_22 = 0 ; V_22 < V_13 -> V_82 ; V_22 ++ )
F_44 ( V_13 , V_22 ) ;
V_73:
if ( F_68 ( V_24 , NULL , NULL ) == 1 )
F_58 ( & V_13 -> V_102 ,
F_59 ( V_108 ) ) ;
}
static void F_75 ( struct V_105 * V_106 )
{
struct V_37 * V_38 = F_57 ( V_106 ,
struct V_37 ,
V_102 . V_106 ) ;
struct V_93 * V_94 = V_38 -> V_24 -> V_94 ;
struct V_12 * V_13 = V_38 -> V_101 ;
int V_115 ;
F_76 ( ! V_13 -> V_44 ) ;
V_115 = F_73 ( V_13 -> V_24 , V_128 ) ;
F_70 ( V_13 -> V_24 , V_128 , V_115 | F_77 ( V_38 -> V_75 ) ) ;
F_78 ( V_13 -> V_24 , V_128 ) ;
F_79 ( & V_94 -> V_2 , L_42 , V_115 ) ;
if ( V_115 & F_77 ( V_38 -> V_75 ) ) {
F_54 ( & V_94 -> V_2 , L_43 , V_38 -> V_75 ) ;
V_38 -> V_44 = true ;
if ( V_38 -> V_103 )
V_38 -> V_103 ( V_38 -> V_104 , V_38 -> V_44 ) ;
F_80 ( & V_38 -> V_129 ) ;
} else if ( V_13 -> V_44 )
F_58 ( & V_38 -> V_102 ,
F_59 ( V_108 ) ) ;
}
static int F_81 ( struct V_12 * V_13 ,
unsigned int V_75 )
{
struct V_37 * V_38 ;
T_9 V_130 ;
T_6 V_131 ;
unsigned int V_80 , V_132 ;
unsigned int V_81 , V_82 , V_83 ;
T_7 V_133 ;
V_82 = V_13 -> V_82 ;
V_83 = V_13 -> V_83 ;
V_81 = F_42 ( V_13 , V_75 ) ;
V_38 = & V_13 -> V_76 [ V_75 ] ;
V_38 -> V_75 = V_75 ;
V_38 -> V_101 = V_13 ;
V_38 -> V_24 = V_13 -> V_24 ;
V_38 -> V_127 = false ;
V_38 -> V_103 = NULL ;
F_52 ( V_38 ) ;
if ( V_83 % V_82 && V_81 + 1 < V_83 / V_82 )
V_80 = V_83 / V_82 + 1 ;
else
V_80 = V_83 / V_82 ;
V_130 = V_13 -> V_84 [ V_81 ] . V_134 ;
V_131 = V_13 -> V_84 [ V_81 ] . V_117 ;
V_132 = ( unsigned int ) V_131 / V_80 ;
V_133 = V_132 * ( V_75 / V_82 ) ;
V_38 -> V_62 = V_13 -> V_84 [ V_81 ] . V_135 + V_133 ;
if ( ! V_38 -> V_62 )
return - V_9 ;
V_38 -> V_136 = V_130 + V_133 ;
if ( ! V_38 -> V_136 )
return - V_9 ;
V_132 -= sizeof( struct V_87 ) ;
V_38 -> V_137 = V_38 -> V_62 + V_132 ;
V_38 -> V_138 = F_43 ( V_89 , V_132 / 2 ) ;
V_38 -> V_65 = V_132 / V_38 -> V_138 ;
if ( V_13 -> V_139 ) {
char V_140 [ 4 ] ;
snprintf ( V_140 , 4 , L_44 , V_75 ) ;
V_38 -> V_141 = F_82 ( V_140 ,
V_13 -> V_139 ) ;
V_38 -> V_142 = F_83 ( L_45 , V_143 ,
V_38 -> V_141 , V_38 ,
& V_144 ) ;
} else {
V_38 -> V_141 = NULL ;
V_38 -> V_142 = NULL ;
}
F_84 ( & V_38 -> V_102 , F_75 ) ;
F_85 ( & V_38 -> V_107 , F_56 ) ;
F_86 ( & V_38 -> V_145 ) ;
F_86 ( & V_38 -> V_146 ) ;
F_87 ( & V_38 -> V_147 ) ;
F_87 ( & V_38 -> V_148 ) ;
F_87 ( & V_38 -> V_149 ) ;
F_87 ( & V_38 -> V_150 ) ;
F_88 ( & V_38 -> V_129 , V_151 ,
( unsigned long ) V_38 ) ;
return 0 ;
}
static int F_89 ( struct V_152 * V_153 , struct V_114 * V_24 )
{
struct V_12 * V_13 ;
struct V_77 * V_78 ;
unsigned int V_82 , V_83 ;
T_7 V_110 ;
int V_21 ;
int V_8 , V_22 ;
if ( F_90 ( V_24 ) )
F_74 ( & V_24 -> V_2 ,
L_46 ) ;
if ( F_91 ( V_24 ) )
F_74 ( & V_24 -> V_2 ,
L_47 ) ;
V_21 = F_22 ( & V_24 -> V_2 ) ;
V_13 = F_23 ( sizeof( * V_13 ) , V_25 , V_21 ) ;
if ( ! V_13 )
return - V_26 ;
V_13 -> V_24 = V_24 ;
V_82 = F_92 ( V_24 ) ;
V_13 -> V_82 = V_82 ;
V_13 -> V_84 = F_23 ( V_82 * sizeof( * V_13 -> V_84 ) ,
V_25 , V_21 ) ;
if ( ! V_13 -> V_84 ) {
V_8 = - V_26 ;
goto V_27;
}
for ( V_22 = 0 ; V_22 < V_82 ; V_22 ++ ) {
V_78 = & V_13 -> V_84 [ V_22 ] ;
V_8 = F_93 ( V_24 , V_22 , & V_78 -> V_134 , & V_78 -> V_117 ,
& V_78 -> V_99 , & V_78 -> V_98 ) ;
if ( V_8 )
goto V_154;
V_78 -> V_135 = F_94 ( V_78 -> V_134 , V_78 -> V_117 ) ;
if ( ! V_78 -> V_135 ) {
V_8 = - V_26 ;
goto V_154;
}
V_78 -> V_95 = 0 ;
V_78 -> V_86 = 0 ;
V_78 -> V_85 = NULL ;
V_78 -> V_96 = 0 ;
}
V_110 = F_95 ( V_24 ) ;
V_83 = F_96 ( V_110 ) ;
if ( V_155 && V_155 < V_83 )
V_83 = V_155 ;
else if ( V_82 < V_83 )
V_83 = V_82 ;
V_110 &= F_63 ( V_83 ) - 1 ;
V_13 -> V_83 = V_83 ;
V_13 -> V_110 = V_110 ;
V_13 -> V_111 = V_110 ;
V_13 -> V_76 = F_23 ( V_83 * sizeof( * V_13 -> V_76 ) ,
V_25 , V_21 ) ;
if ( ! V_13 -> V_76 ) {
V_8 = - V_26 ;
goto V_154;
}
if ( V_156 ) {
V_13 -> V_139 =
F_82 ( F_97 ( V_24 -> V_94 ) ,
V_156 ) ;
}
for ( V_22 = 0 ; V_22 < V_83 ; V_22 ++ ) {
V_8 = F_81 ( V_13 , V_22 ) ;
if ( V_8 )
goto V_157;
}
F_84 ( & V_13 -> V_102 , F_69 ) ;
F_85 ( & V_13 -> V_107 , F_66 ) ;
V_8 = F_98 ( V_24 , V_13 , & V_158 ) ;
if ( V_8 )
goto V_157;
F_87 ( & V_13 -> V_31 ) ;
V_8 = F_8 ( V_13 ) ;
if ( V_8 )
goto V_159;
V_13 -> V_44 = false ;
F_99 ( V_24 , V_160 , V_161 ) ;
F_100 ( V_24 ) ;
return 0 ;
V_159:
F_101 ( V_24 ) ;
V_157:
F_17 ( V_13 -> V_76 ) ;
V_154:
while ( V_22 -- ) {
V_78 = & V_13 -> V_84 [ V_22 ] ;
F_102 ( V_78 -> V_135 ) ;
}
F_17 ( V_13 -> V_84 ) ;
V_27:
F_17 ( V_13 ) ;
return V_8 ;
}
static void F_103 ( struct V_152 * V_153 , struct V_114 * V_24 )
{
struct V_12 * V_13 = V_24 -> V_162 ;
struct V_37 * V_38 ;
T_7 V_109 ;
int V_22 ;
F_62 ( V_13 ) ;
F_64 ( & V_13 -> V_107 ) ;
F_55 ( & V_13 -> V_102 ) ;
V_109 = V_13 -> V_110 & ~ V_13 -> V_111 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_83 ; V_22 ++ ) {
V_38 = & V_13 -> V_76 [ V_22 ] ;
if ( V_109 & F_63 ( V_22 ) )
F_104 ( V_38 ) ;
F_105 ( V_38 -> V_141 ) ;
}
F_106 ( V_24 ) ;
F_101 ( V_24 ) ;
F_10 ( V_13 ) ;
for ( V_22 = V_13 -> V_82 ; V_22 -- ; ) {
F_44 ( V_13 , V_22 ) ;
F_102 ( V_13 -> V_84 [ V_22 ] . V_135 ) ;
}
F_17 ( V_13 -> V_76 ) ;
F_17 ( V_13 -> V_84 ) ;
F_17 ( V_13 ) ;
}
static void F_107 ( struct V_37 * V_38 )
{
struct V_72 * V_14 ;
void * V_104 ;
unsigned int V_163 ;
unsigned long V_164 ;
F_35 ( & V_38 -> V_145 , V_164 ) ;
while ( ! F_21 ( & V_38 -> V_147 ) ) {
V_14 = F_38 ( & V_38 -> V_147 ,
struct V_72 , V_14 ) ;
if ( ! ( V_14 -> V_71 & V_165 ) )
break;
V_14 -> V_166 -> V_71 = 0 ;
F_108 ( V_14 -> V_167 , & V_38 -> V_137 -> V_14 ) ;
V_104 = V_14 -> V_104 ;
V_163 = V_14 -> V_163 ;
F_40 ( & V_14 -> V_14 , & V_38 -> V_149 ) ;
F_36 ( & V_38 -> V_145 , V_164 ) ;
if ( V_38 -> V_168 && V_38 -> V_127 )
V_38 -> V_168 ( V_38 , V_38 -> V_104 , V_104 , V_163 ) ;
F_35 ( & V_38 -> V_145 , V_164 ) ;
}
F_36 ( & V_38 -> V_145 , V_164 ) ;
}
static void F_109 ( void * V_113 )
{
struct V_72 * V_14 = V_113 ;
V_14 -> V_71 |= V_165 ;
F_107 ( V_14 -> V_38 ) ;
}
static void F_110 ( struct V_72 * V_14 , void * V_90 )
{
void * V_39 = V_14 -> V_39 ;
T_3 V_163 = V_14 -> V_163 ;
memcpy ( V_39 , V_90 , V_163 ) ;
F_111 () ;
F_109 ( V_14 ) ;
}
static void F_112 ( struct V_72 * V_14 , void * V_90 )
{
struct V_169 * V_170 ;
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_171 * V_172 = V_38 -> V_67 ;
struct V_173 * V_1 ;
T_3 V_174 , V_175 , V_163 ;
struct V_176 * V_177 ;
T_10 V_178 ;
void * V_39 = V_14 -> V_39 ;
V_163 = V_14 -> V_163 ;
if ( ! V_172 )
goto V_27;
if ( V_163 < V_179 )
goto V_27;
V_1 = V_172 -> V_1 ;
V_174 = ( T_3 ) V_90 & ~ V_180 ;
V_175 = ( T_3 ) V_39 & ~ V_180 ;
if ( ! F_113 ( V_1 , V_174 , V_175 , V_163 ) )
goto V_27;
V_177 = F_114 ( V_1 -> V_2 , 2 , V_181 ) ;
if ( ! V_177 )
goto V_27;
V_177 -> V_163 = V_163 ;
V_177 -> V_182 [ 0 ] = F_115 ( V_1 -> V_2 , F_116 ( V_90 ) ,
V_174 , V_163 , V_183 ) ;
if ( F_117 ( V_1 -> V_2 , V_177 -> V_182 [ 0 ] ) )
goto V_184;
V_177 -> V_185 = 1 ;
V_177 -> V_182 [ 1 ] = F_115 ( V_1 -> V_2 , F_116 ( V_39 ) ,
V_175 , V_163 , V_186 ) ;
if ( F_117 ( V_1 -> V_2 , V_177 -> V_182 [ 1 ] ) )
goto V_184;
V_177 -> V_187 = 1 ;
V_170 = V_1 -> V_188 ( V_172 , V_177 -> V_182 [ 1 ] ,
V_177 -> V_182 [ 0 ] , V_163 ,
V_189 ) ;
if ( ! V_170 )
goto V_184;
V_170 -> V_190 = F_109 ;
V_170 -> V_191 = V_14 ;
F_118 ( V_170 , V_177 ) ;
V_178 = F_119 ( V_170 ) ;
if ( F_120 ( V_178 ) )
goto V_192;
F_121 ( V_177 ) ;
V_38 -> V_193 = V_178 ;
V_38 -> V_48 ++ ;
return;
V_192:
F_121 ( V_177 ) ;
V_184:
F_121 ( V_177 ) ;
V_27:
F_110 ( V_14 , V_90 ) ;
V_38 -> V_47 ++ ;
}
static int F_122 ( struct V_37 * V_38 )
{
struct V_91 * V_194 ;
struct V_72 * V_14 ;
void * V_90 ;
V_90 = V_38 -> V_53 + V_38 -> V_88 * V_38 -> V_54 ;
V_194 = V_90 + V_38 -> V_88 - sizeof( struct V_91 ) ;
F_74 ( & V_38 -> V_24 -> V_94 -> V_2 , L_48 ,
V_38 -> V_75 , V_194 -> V_195 , V_194 -> V_163 , V_194 -> V_71 ) ;
if ( ! ( V_194 -> V_71 & V_165 ) ) {
F_74 ( & V_38 -> V_24 -> V_94 -> V_2 , L_49 ) ;
V_38 -> V_49 ++ ;
return - V_196 ;
}
if ( V_194 -> V_71 & V_197 ) {
F_74 ( & V_38 -> V_24 -> V_94 -> V_2 , L_50 ) ;
F_60 ( V_38 ) ;
V_194 -> V_71 = 0 ;
return - V_196 ;
}
if ( V_194 -> V_195 != ( T_8 ) V_38 -> V_46 ) {
F_74 ( & V_38 -> V_24 -> V_94 -> V_2 ,
L_51 ,
V_38 -> V_46 , V_194 -> V_195 ) ;
V_38 -> V_52 ++ ;
return - V_100 ;
}
V_14 = F_39 ( & V_38 -> V_145 , & V_38 -> V_148 , & V_38 -> V_147 ) ;
if ( ! V_14 ) {
F_74 ( & V_38 -> V_24 -> V_94 -> V_2 , L_52 ) ;
V_38 -> V_50 ++ ;
return - V_196 ;
}
V_14 -> V_166 = V_194 ;
V_14 -> V_167 = V_38 -> V_54 ;
if ( V_194 -> V_163 > V_14 -> V_163 ) {
F_74 ( & V_38 -> V_24 -> V_94 -> V_2 ,
L_53 ,
V_194 -> V_163 , V_14 -> V_163 ) ;
V_38 -> V_51 ++ ;
V_14 -> V_163 = - V_100 ;
V_14 -> V_71 |= V_165 ;
F_107 ( V_38 ) ;
} else {
F_74 ( & V_38 -> V_24 -> V_94 -> V_2 ,
L_54 ,
V_38 -> V_54 , V_194 -> V_195 , V_194 -> V_163 , V_14 -> V_163 ) ;
V_38 -> V_45 += V_194 -> V_163 ;
V_38 -> V_46 ++ ;
V_14 -> V_163 = V_194 -> V_163 ;
F_112 ( V_14 , V_90 ) ;
}
V_38 -> V_54 ++ ;
V_38 -> V_54 %= V_38 -> V_55 ;
return 0 ;
}
static void V_151 ( unsigned long V_113 )
{
struct V_37 * V_38 = ( void * ) V_113 ;
int V_8 , V_22 ;
F_74 ( & V_38 -> V_24 -> V_94 -> V_2 , L_55 ,
V_198 , V_38 -> V_75 ) ;
for ( V_22 = 0 ; V_22 < V_38 -> V_55 ; V_22 ++ ) {
V_8 = F_122 ( V_38 ) ;
if ( V_8 )
break;
}
if ( V_22 && V_38 -> V_67 )
F_123 ( V_38 -> V_67 ) ;
if ( V_22 == V_38 -> V_55 ) {
F_80 ( & V_38 -> V_129 ) ;
} else if ( F_124 ( V_38 -> V_24 ) & F_63 ( V_38 -> V_75 ) ) {
F_125 ( V_38 -> V_24 , F_63 ( V_38 -> V_75 ) ) ;
F_124 ( V_38 -> V_24 ) ;
F_80 ( & V_38 -> V_129 ) ;
}
}
static void F_126 ( void * V_113 )
{
struct V_72 * V_14 = V_113 ;
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_91 T_11 * V_194 = V_14 -> V_199 ;
F_108 ( V_14 -> V_71 | V_165 , & V_194 -> V_71 ) ;
F_127 ( V_38 -> V_24 , F_63 ( V_38 -> V_75 ) ) ;
if ( V_14 -> V_163 > 0 ) {
V_38 -> V_56 += V_14 -> V_163 ;
if ( V_38 -> V_200 )
V_38 -> V_200 ( V_38 , V_38 -> V_104 , V_14 -> V_104 ,
V_14 -> V_163 ) ;
}
F_34 ( & V_38 -> V_146 , & V_14 -> V_14 , & V_38 -> V_150 ) ;
}
static void F_128 ( struct V_72 * V_14 , void T_11 * V_90 )
{
#ifdef F_129
F_130 ( V_90 , V_14 -> V_39 , V_14 -> V_163 ) ;
#else
F_131 ( V_90 , V_14 -> V_39 , V_14 -> V_163 ) ;
#endif
F_111 () ;
F_126 ( V_14 ) ;
}
static void F_132 ( struct V_37 * V_38 ,
struct V_72 * V_14 )
{
struct V_91 T_11 * V_194 ;
struct V_169 * V_170 ;
struct V_171 * V_172 = V_38 -> V_66 ;
struct V_173 * V_1 ;
T_3 V_201 , V_175 ;
struct V_176 * V_177 ;
T_12 V_202 ;
T_10 V_178 ;
void T_11 * V_90 ;
T_3 V_163 = V_14 -> V_163 ;
void * V_39 = V_14 -> V_39 ;
V_90 = V_38 -> V_62 + V_38 -> V_138 * V_38 -> V_63 ;
V_194 = V_90 + V_38 -> V_138 - sizeof( struct V_91 ) ;
V_14 -> V_199 = V_194 ;
F_108 ( V_14 -> V_163 , & V_194 -> V_163 ) ;
F_108 ( ( T_8 ) V_38 -> V_57 , & V_194 -> V_195 ) ;
if ( ! V_172 )
goto V_27;
if ( V_163 < V_179 )
goto V_27;
V_1 = V_172 -> V_1 ;
V_202 = V_38 -> V_136 + V_38 -> V_138 * V_38 -> V_63 ;
V_175 = ( T_3 ) V_39 & ~ V_180 ;
V_201 = ( T_3 ) V_202 & ~ V_180 ;
if ( ! F_113 ( V_1 , V_175 , V_201 , V_163 ) )
goto V_27;
V_177 = F_114 ( V_1 -> V_2 , 1 , V_181 ) ;
if ( ! V_177 )
goto V_27;
V_177 -> V_163 = V_163 ;
V_177 -> V_182 [ 0 ] = F_115 ( V_1 -> V_2 , F_116 ( V_39 ) ,
V_175 , V_163 , V_183 ) ;
if ( F_117 ( V_1 -> V_2 , V_177 -> V_182 [ 0 ] ) )
goto V_184;
V_177 -> V_185 = 1 ;
V_170 = V_1 -> V_188 ( V_172 , V_202 , V_177 -> V_182 [ 0 ] , V_163 ,
V_189 ) ;
if ( ! V_170 )
goto V_184;
V_170 -> V_190 = F_126 ;
V_170 -> V_191 = V_14 ;
F_118 ( V_170 , V_177 ) ;
V_178 = F_119 ( V_170 ) ;
if ( F_120 ( V_178 ) )
goto V_192;
F_121 ( V_177 ) ;
F_123 ( V_172 ) ;
V_38 -> V_59 ++ ;
return;
V_192:
F_121 ( V_177 ) ;
V_184:
F_121 ( V_177 ) ;
V_27:
F_128 ( V_14 , V_90 ) ;
V_38 -> V_58 ++ ;
}
static int F_133 ( struct V_37 * V_38 ,
struct V_72 * V_14 )
{
if ( V_38 -> V_63 == V_38 -> V_64 -> V_14 ) {
V_38 -> V_60 ++ ;
return - V_196 ;
}
if ( V_14 -> V_163 > V_38 -> V_138 - sizeof( struct V_91 ) ) {
if ( V_38 -> V_200 )
V_38 -> V_200 ( V_38 -> V_104 , V_38 , NULL , - V_100 ) ;
F_34 ( & V_38 -> V_146 , & V_14 -> V_14 ,
& V_38 -> V_150 ) ;
return 0 ;
}
F_132 ( V_38 , V_14 ) ;
V_38 -> V_63 ++ ;
V_38 -> V_63 %= V_38 -> V_65 ;
V_38 -> V_57 ++ ;
return 0 ;
}
static void F_134 ( struct V_37 * V_38 )
{
struct V_93 * V_94 = V_38 -> V_24 -> V_94 ;
struct V_72 * V_14 ;
int V_22 , V_8 ;
if ( ! V_38 -> V_44 )
return;
F_54 ( & V_94 -> V_2 , L_56 , V_38 -> V_75 ) ;
for ( V_22 = 0 ; V_22 < V_108 ; V_22 ++ ) {
V_14 = F_37 ( & V_38 -> V_146 , & V_38 -> V_150 ) ;
if ( V_14 )
break;
F_135 ( 100 ) ;
}
if ( ! V_14 )
return;
V_14 -> V_104 = NULL ;
V_14 -> V_39 = NULL ;
V_14 -> V_163 = 0 ;
V_14 -> V_71 = V_197 ;
V_8 = F_133 ( V_38 , V_14 ) ;
if ( V_8 )
F_12 ( & V_94 -> V_2 , L_57 ,
V_38 -> V_75 ) ;
F_52 ( V_38 ) ;
}
static bool F_136 ( struct V_171 * V_172 , void * V_21 )
{
return F_22 ( & V_172 -> V_2 -> V_1 ) == ( int ) ( unsigned long ) V_21 ;
}
struct V_37 *
F_137 ( void * V_113 , struct V_1 * V_17 ,
const struct V_203 * V_204 )
{
struct V_114 * V_24 ;
struct V_93 * V_94 ;
struct V_12 * V_13 ;
struct V_72 * V_14 ;
struct V_37 * V_38 ;
T_7 V_205 ;
unsigned int V_206 ;
T_13 V_207 ;
int V_21 ;
int V_22 ;
V_24 = F_138 ( V_17 -> V_19 ) ;
V_94 = V_24 -> V_94 ;
V_13 = V_24 -> V_162 ;
V_21 = F_22 ( & V_24 -> V_2 ) ;
V_206 = F_139 ( V_13 -> V_110 ) ;
if ( ! V_206 )
goto V_27;
V_206 -- ;
V_38 = & V_13 -> V_76 [ V_206 ] ;
V_205 = F_63 ( V_38 -> V_75 ) ;
V_13 -> V_111 &= ~ V_205 ;
V_38 -> V_104 = V_113 ;
V_38 -> V_168 = V_204 -> V_168 ;
V_38 -> V_200 = V_204 -> V_200 ;
V_38 -> V_103 = V_204 -> V_103 ;
F_140 ( V_207 ) ;
F_141 ( V_208 , V_207 ) ;
if ( V_209 ) {
V_38 -> V_66 =
F_142 ( V_207 , F_136 ,
( void * ) ( unsigned long ) V_21 ) ;
if ( ! V_38 -> V_66 )
F_54 ( & V_94 -> V_2 , L_58 ) ;
V_38 -> V_67 =
F_142 ( V_207 , F_136 ,
( void * ) ( unsigned long ) V_21 ) ;
if ( ! V_38 -> V_67 )
F_54 ( & V_94 -> V_2 , L_59 ) ;
} else {
V_38 -> V_66 = NULL ;
V_38 -> V_67 = NULL ;
}
F_74 ( & V_94 -> V_2 , L_60 ,
V_38 -> V_66 ? L_61 : L_62 ) ;
F_74 ( & V_94 -> V_2 , L_63 ,
V_38 -> V_67 ? L_61 : L_62 ) ;
for ( V_22 = 0 ; V_22 < V_210 ; V_22 ++ ) {
V_14 = F_23 ( sizeof( * V_14 ) , V_211 , V_21 ) ;
if ( ! V_14 )
goto V_154;
V_14 -> V_38 = V_38 ;
F_34 ( & V_38 -> V_145 , & V_14 -> V_14 ,
& V_38 -> V_149 ) ;
}
for ( V_22 = 0 ; V_22 < V_210 ; V_22 ++ ) {
V_14 = F_23 ( sizeof( * V_14 ) , V_211 , V_21 ) ;
if ( ! V_14 )
goto V_157;
V_14 -> V_38 = V_38 ;
F_34 ( & V_38 -> V_146 , & V_14 -> V_14 ,
& V_38 -> V_150 ) ;
}
F_125 ( V_38 -> V_24 , V_205 ) ;
F_143 ( V_38 -> V_24 , V_205 ) ;
F_54 ( & V_94 -> V_2 , L_64 , V_38 -> V_75 ) ;
return V_38 ;
V_157:
while ( ( V_14 = F_37 ( & V_38 -> V_146 , & V_38 -> V_150 ) ) )
F_17 ( V_14 ) ;
V_154:
while ( ( V_14 = F_37 ( & V_38 -> V_145 , & V_38 -> V_149 ) ) )
F_17 ( V_14 ) ;
if ( V_38 -> V_66 )
F_144 ( V_38 -> V_66 ) ;
if ( V_38 -> V_67 )
F_144 ( V_38 -> V_67 ) ;
V_13 -> V_111 |= V_205 ;
V_27:
return NULL ;
}
void F_104 ( struct V_37 * V_38 )
{
struct V_93 * V_94 ;
struct V_72 * V_14 ;
T_7 V_205 ;
if ( ! V_38 )
return;
V_94 = V_38 -> V_24 -> V_94 ;
if ( V_38 -> V_66 ) {
struct V_171 * V_172 = V_38 -> V_66 ;
V_38 -> V_66 = NULL ;
F_145 ( V_172 , V_38 -> V_193 ) ;
F_146 ( V_172 ) ;
F_144 ( V_172 ) ;
}
if ( V_38 -> V_67 ) {
struct V_171 * V_172 = V_38 -> V_67 ;
V_38 -> V_67 = NULL ;
F_145 ( V_172 , V_38 -> V_193 ) ;
F_146 ( V_172 ) ;
F_144 ( V_172 ) ;
}
V_205 = F_63 ( V_38 -> V_75 ) ;
F_147 ( V_38 -> V_24 , V_205 ) ;
F_148 ( & V_38 -> V_129 ) ;
F_55 ( & V_38 -> V_102 ) ;
V_38 -> V_104 = NULL ;
V_38 -> V_168 = NULL ;
V_38 -> V_200 = NULL ;
V_38 -> V_103 = NULL ;
while ( ( V_14 = F_37 ( & V_38 -> V_145 , & V_38 -> V_149 ) ) )
F_17 ( V_14 ) ;
while ( ( V_14 = F_37 ( & V_38 -> V_145 , & V_38 -> V_148 ) ) ) {
F_149 ( & V_94 -> V_2 , L_65 ) ;
F_17 ( V_14 ) ;
}
while ( ( V_14 = F_37 ( & V_38 -> V_145 , & V_38 -> V_147 ) ) ) {
F_149 ( & V_94 -> V_2 , L_66 ) ;
F_17 ( V_14 ) ;
}
while ( ( V_14 = F_37 ( & V_38 -> V_146 , & V_38 -> V_150 ) ) )
F_17 ( V_14 ) ;
V_38 -> V_101 -> V_111 |= V_205 ;
F_54 ( & V_94 -> V_2 , L_67 , V_38 -> V_75 ) ;
}
void * F_150 ( struct V_37 * V_38 , unsigned int * V_163 )
{
struct V_72 * V_14 ;
void * V_39 ;
if ( ! V_38 || V_38 -> V_127 )
return NULL ;
V_14 = F_37 ( & V_38 -> V_145 , & V_38 -> V_148 ) ;
if ( ! V_14 )
return NULL ;
V_39 = V_14 -> V_104 ;
* V_163 = V_14 -> V_163 ;
F_34 ( & V_38 -> V_145 , & V_14 -> V_14 , & V_38 -> V_149 ) ;
return V_39 ;
}
int F_151 ( struct V_37 * V_38 , void * V_212 , void * V_113 ,
unsigned int V_163 )
{
struct V_72 * V_14 ;
if ( ! V_38 )
return - V_9 ;
V_14 = F_37 ( & V_38 -> V_145 , & V_38 -> V_149 ) ;
if ( ! V_14 )
return - V_26 ;
V_14 -> V_104 = V_212 ;
V_14 -> V_39 = V_113 ;
V_14 -> V_163 = V_163 ;
V_14 -> V_71 = 0 ;
F_34 ( & V_38 -> V_145 , & V_14 -> V_14 , & V_38 -> V_148 ) ;
F_80 ( & V_38 -> V_129 ) ;
return 0 ;
}
int F_152 ( struct V_37 * V_38 , void * V_212 , void * V_113 ,
unsigned int V_163 )
{
struct V_72 * V_14 ;
int V_8 ;
if ( ! V_38 || ! V_38 -> V_44 || ! V_163 )
return - V_9 ;
V_14 = F_37 ( & V_38 -> V_146 , & V_38 -> V_150 ) ;
if ( ! V_14 ) {
V_38 -> V_61 ++ ;
return - V_213 ;
}
V_14 -> V_104 = V_212 ;
V_14 -> V_39 = V_113 ;
V_14 -> V_163 = V_163 ;
V_14 -> V_71 = 0 ;
V_8 = F_133 ( V_38 , V_14 ) ;
if ( V_8 )
F_34 ( & V_38 -> V_146 , & V_14 -> V_14 ,
& V_38 -> V_150 ) ;
return V_8 ;
}
void F_153 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return;
V_38 -> V_127 = true ;
if ( V_38 -> V_101 -> V_44 )
F_58 ( & V_38 -> V_102 , 0 ) ;
}
void F_154 ( struct V_37 * V_38 )
{
int V_115 ;
if ( ! V_38 )
return;
V_38 -> V_127 = false ;
V_115 = F_73 ( V_38 -> V_24 , V_128 ) ;
F_70 ( V_38 -> V_24 , V_128 ,
V_115 & ~ F_77 ( V_38 -> V_75 ) ) ;
if ( V_38 -> V_44 )
F_134 ( V_38 ) ;
else
F_55 ( & V_38 -> V_102 ) ;
}
bool F_155 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return false ;
return V_38 -> V_44 ;
}
unsigned char F_156 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return 0 ;
return V_38 -> V_75 ;
}
unsigned int F_157 ( struct V_37 * V_38 )
{
unsigned int V_214 ;
unsigned int V_215 ;
struct V_171 * V_216 , * V_217 ;
if ( ! V_38 )
return 0 ;
V_216 = V_38 -> V_67 ;
V_217 = V_38 -> V_66 ;
V_215 = F_158 ( V_216 ? V_216 -> V_1 -> V_215 : 0 ,
V_217 ? V_217 -> V_1 -> V_215 : 0 ) ;
V_214 = V_38 -> V_138 - sizeof( struct V_91 ) ;
V_214 = F_159 ( V_214 , 1 << V_215 ) ;
return V_214 ;
}
unsigned int F_32 ( struct V_37 * V_38 )
{
unsigned int V_218 = V_38 -> V_63 ;
unsigned int V_219 = V_38 -> V_64 -> V_14 ;
return V_219 > V_218 ? V_219 - V_218 : V_38 -> V_65 + V_219 - V_218 ;
}
static void F_160 ( void * V_113 , int V_220 )
{
struct V_12 * V_13 = V_113 ;
struct V_37 * V_38 ;
T_7 V_221 ;
unsigned int V_75 ;
V_221 = ( V_13 -> V_110 & ~ V_13 -> V_111 &
F_161 ( V_13 -> V_24 , V_220 ) ) ;
while ( V_221 ) {
V_75 = F_162 ( V_221 ) ;
V_38 = & V_13 -> V_76 [ V_75 ] ;
F_80 ( & V_38 -> V_129 ) ;
V_221 &= ~ F_63 ( V_75 ) ;
}
}
static int T_14 F_163 ( void )
{
int V_8 ;
F_164 ( L_68 , V_222 , V_223 ) ;
if ( F_165 () )
V_156 = F_82 ( V_224 , NULL ) ;
V_8 = F_166 ( & V_29 ) ;
if ( V_8 )
goto V_225;
V_8 = F_167 ( & V_6 ) ;
if ( V_8 )
goto V_226;
return 0 ;
V_226:
F_168 ( & V_29 ) ;
V_225:
F_105 ( V_156 ) ;
return V_8 ;
}
static void T_15 F_169 ( void )
{
F_105 ( V_156 ) ;
F_170 ( & V_6 ) ;
F_168 ( & V_29 ) ;
}
