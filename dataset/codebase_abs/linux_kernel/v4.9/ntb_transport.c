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
L_27 ,
V_38 -> V_67 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_28 ,
V_38 -> V_68 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_29 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_30 ,
V_38 -> V_69 ? L_31 : L_32 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_33 ,
V_38 -> V_70 ? L_31 : L_32 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_34 ,
V_38 -> V_44 ? L_35 : L_36 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_29 ) ;
if ( V_41 > V_42 )
V_41 = V_42 ;
V_40 = F_33 ( V_34 , V_35 , V_36 , V_39 , V_41 ) ;
F_17 ( V_39 ) ;
return V_40 ;
}
static void F_34 ( T_5 * V_71 , struct V_72 * V_14 ,
struct V_72 * V_73 )
{
unsigned long V_74 ;
F_35 ( V_71 , V_74 ) ;
F_9 ( V_14 , V_73 ) ;
F_36 ( V_71 , V_74 ) ;
}
static struct V_75 * F_37 ( T_5 * V_71 ,
struct V_72 * V_73 )
{
struct V_75 * V_14 ;
unsigned long V_74 ;
F_35 ( V_71 , V_74 ) ;
if ( F_21 ( V_73 ) ) {
V_14 = NULL ;
goto V_76;
}
V_14 = F_38 ( V_73 , struct V_75 , V_14 ) ;
F_13 ( & V_14 -> V_14 ) ;
V_76:
F_36 ( V_71 , V_74 ) ;
return V_14 ;
}
static struct V_75 * F_39 ( T_5 * V_71 ,
struct V_72 * V_73 ,
struct V_72 * V_77 )
{
struct V_75 * V_14 ;
unsigned long V_74 ;
F_35 ( V_71 , V_74 ) ;
if ( F_21 ( V_73 ) ) {
V_14 = NULL ;
} else {
V_14 = F_38 ( V_73 , struct V_75 , V_14 ) ;
F_40 ( & V_14 -> V_14 , V_77 ) ;
}
F_36 ( V_71 , V_74 ) ;
return V_14 ;
}
static int F_41 ( struct V_12 * V_13 ,
unsigned int V_78 )
{
struct V_37 * V_38 = & V_13 -> V_79 [ V_78 ] ;
struct V_80 * V_81 ;
struct V_82 * V_24 = V_13 -> V_24 ;
struct V_75 * V_14 ;
unsigned int V_83 , V_84 ;
unsigned int V_85 , V_86 , V_87 ;
unsigned int V_22 ;
int V_21 ;
V_86 = V_13 -> V_86 ;
V_87 = V_13 -> V_87 ;
V_85 = F_42 ( V_13 , V_78 ) ;
V_81 = & V_13 -> V_88 [ V_85 ] ;
if ( ! V_81 -> V_89 )
return - V_26 ;
if ( V_87 % V_86 && V_85 + 1 < V_87 / V_86 )
V_84 = V_87 / V_86 + 1 ;
else
V_84 = V_87 / V_86 ;
V_83 = ( unsigned int ) V_81 -> V_90 / V_84 ;
V_38 -> V_53 = V_81 -> V_89 + V_83 * ( V_78 / V_86 ) ;
V_83 -= sizeof( struct V_91 ) ;
V_38 -> V_65 = V_38 -> V_53 + V_83 ;
V_38 -> V_92 = F_43 ( V_93 , V_83 / 2 ) ;
V_38 -> V_55 = V_83 / V_38 -> V_92 ;
V_38 -> V_54 = 0 ;
V_21 = F_22 ( & V_24 -> V_2 ) ;
for ( V_22 = V_38 -> V_56 ; V_22 < V_38 -> V_55 ; V_22 ++ ) {
V_14 = F_23 ( sizeof( * V_14 ) , V_94 , V_21 ) ;
if ( ! V_14 )
return - V_26 ;
V_14 -> V_38 = V_38 ;
F_34 ( & V_38 -> V_95 , & V_14 -> V_14 ,
& V_38 -> V_96 ) ;
V_38 -> V_56 ++ ;
}
V_38 -> V_65 -> V_14 = V_38 -> V_55 - 1 ;
for ( V_22 = 0 ; V_22 < V_38 -> V_55 ; V_22 ++ ) {
void * V_97 = ( V_38 -> V_53 + V_38 -> V_92 * ( V_22 + 1 ) -
sizeof( struct V_98 ) ) ;
memset ( V_97 , 0 , sizeof( struct V_98 ) ) ;
}
V_38 -> V_46 = 0 ;
V_38 -> V_58 = 0 ;
V_38 -> V_64 = 0 ;
return 0 ;
}
static void F_44 ( struct V_12 * V_13 , int V_99 )
{
struct V_80 * V_81 = & V_13 -> V_88 [ V_99 ] ;
struct V_100 * V_101 = V_13 -> V_24 -> V_101 ;
if ( ! V_81 -> V_89 )
return;
F_45 ( V_13 -> V_24 , V_99 ) ;
F_46 ( & V_101 -> V_2 , V_81 -> V_102 ,
V_81 -> V_89 , V_81 -> V_103 ) ;
V_81 -> V_90 = 0 ;
V_81 -> V_102 = 0 ;
V_81 -> V_89 = NULL ;
}
static int F_47 ( struct V_12 * V_13 , int V_99 ,
T_6 V_104 )
{
struct V_80 * V_81 = & V_13 -> V_88 [ V_99 ] ;
struct V_100 * V_101 = V_13 -> V_24 -> V_101 ;
T_3 V_90 , V_102 ;
int V_8 ;
if ( ! V_104 )
return - V_9 ;
V_90 = F_48 ( V_104 , V_81 -> V_105 ) ;
V_102 = F_48 ( V_104 , V_81 -> V_106 ) ;
if ( V_81 -> V_90 == V_90 )
return 0 ;
if ( V_81 -> V_102 )
F_44 ( V_13 , V_99 ) ;
V_81 -> V_90 = V_90 ;
V_81 -> V_102 = V_102 ;
V_81 -> V_89 = F_49 ( & V_101 -> V_2 , V_102 ,
& V_81 -> V_103 , V_25 ) ;
if ( ! V_81 -> V_89 ) {
V_81 -> V_90 = 0 ;
V_81 -> V_102 = 0 ;
F_12 ( & V_101 -> V_2 , L_37 ,
V_102 ) ;
return - V_26 ;
}
if ( ! F_50 ( V_81 -> V_103 , V_81 -> V_106 ) ) {
F_12 ( & V_101 -> V_2 , L_38 ,
& V_81 -> V_103 ) ;
F_44 ( V_13 , V_99 ) ;
return - V_26 ;
}
V_8 = F_51 ( V_13 -> V_24 , V_99 , V_81 -> V_103 , V_81 -> V_90 ) ;
if ( V_8 ) {
F_12 ( & V_101 -> V_2 , L_39 , V_99 ) ;
F_44 ( V_13 , V_99 ) ;
return - V_107 ;
}
return 0 ;
}
static void F_52 ( struct V_37 * V_38 )
{
V_38 -> V_44 = false ;
V_38 -> V_108 = false ;
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
V_38 -> V_67 = 0 ;
V_38 -> V_68 = 0 ;
}
static void F_53 ( struct V_37 * V_38 )
{
struct V_12 * V_13 = V_38 -> V_109 ;
struct V_100 * V_101 = V_13 -> V_24 -> V_101 ;
F_54 ( & V_101 -> V_2 , L_40 , V_38 -> V_78 ) ;
F_55 ( & V_38 -> V_110 ) ;
F_52 ( V_38 ) ;
if ( V_38 -> V_111 )
V_38 -> V_111 ( V_38 -> V_112 , V_38 -> V_44 ) ;
}
static void F_56 ( struct V_113 * V_114 )
{
struct V_37 * V_38 = F_57 ( V_114 ,
struct V_37 ,
V_115 ) ;
struct V_12 * V_13 = V_38 -> V_109 ;
F_53 ( V_38 ) ;
if ( V_13 -> V_44 )
F_58 ( & V_38 -> V_110 ,
F_59 ( V_116 ) ) ;
}
static void F_60 ( struct V_37 * V_38 )
{
F_61 ( & V_38 -> V_115 ) ;
}
static void F_62 ( struct V_12 * V_13 )
{
struct V_37 * V_38 ;
T_7 V_117 ;
int V_22 ;
V_117 = V_13 -> V_118 & ~ V_13 -> V_119 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_87 ; V_22 ++ )
if ( V_117 & F_63 ( V_22 ) ) {
V_38 = & V_13 -> V_79 [ V_22 ] ;
F_53 ( V_38 ) ;
F_64 ( & V_38 -> V_115 ) ;
F_55 ( & V_38 -> V_110 ) ;
}
if ( ! V_13 -> V_44 )
F_55 ( & V_13 -> V_110 ) ;
for ( V_22 = 0 ; V_22 < V_120 ; V_22 ++ )
F_65 ( V_13 -> V_24 , V_22 , 0 ) ;
}
static void F_66 ( struct V_113 * V_114 )
{
struct V_12 * V_13 =
F_57 ( V_114 , struct V_12 , V_115 ) ;
F_62 ( V_13 ) ;
}
static void F_67 ( void * V_121 )
{
struct V_12 * V_13 = V_121 ;
if ( F_68 ( V_13 -> V_24 , NULL , NULL ) == 1 )
F_58 ( & V_13 -> V_110 , 0 ) ;
else
F_61 ( & V_13 -> V_115 ) ;
}
static void F_69 ( struct V_113 * V_114 )
{
struct V_12 * V_13 =
F_57 ( V_114 , struct V_12 , V_110 . V_114 ) ;
struct V_82 * V_24 = V_13 -> V_24 ;
struct V_100 * V_101 = V_24 -> V_101 ;
T_6 V_104 ;
T_8 V_122 ;
int V_8 = 0 , V_22 , V_123 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_86 ; V_22 ++ ) {
V_104 = V_13 -> V_88 [ V_22 ] . V_124 ;
if ( V_125 && V_104 > V_125 )
V_104 = V_125 ;
V_123 = V_126 + ( V_22 * 2 ) ;
F_70 ( V_24 , V_123 , F_71 ( V_104 ) ) ;
V_123 = V_127 + ( V_22 * 2 ) ;
F_70 ( V_24 , V_123 , F_72 ( V_104 ) ) ;
}
F_70 ( V_24 , V_128 , V_13 -> V_86 ) ;
F_70 ( V_24 , V_129 , V_13 -> V_87 ) ;
F_70 ( V_24 , V_130 , V_131 ) ;
V_122 = F_73 ( V_24 , V_130 ) ;
F_74 ( & V_101 -> V_2 , L_41 , V_122 ) ;
if ( V_122 != V_131 )
goto V_76;
V_122 = F_73 ( V_24 , V_129 ) ;
F_74 ( & V_101 -> V_2 , L_42 , V_122 ) ;
if ( V_122 != V_13 -> V_87 )
goto V_76;
V_122 = F_73 ( V_24 , V_128 ) ;
F_74 ( & V_101 -> V_2 , L_43 , V_122 ) ;
if ( V_122 != V_13 -> V_86 )
goto V_76;
for ( V_22 = 0 ; V_22 < V_13 -> V_86 ; V_22 ++ ) {
T_7 V_132 ;
V_122 = F_73 ( V_24 , V_126 + ( V_22 * 2 ) ) ;
V_132 = ( T_7 ) V_122 << 32 ;
V_122 = F_73 ( V_24 , V_127 + ( V_22 * 2 ) ) ;
V_132 |= V_122 ;
F_74 ( & V_101 -> V_2 , L_44 , V_22 , V_132 ) ;
V_8 = F_47 ( V_13 , V_22 , V_132 ) ;
if ( V_8 )
goto V_133;
}
V_13 -> V_44 = true ;
for ( V_22 = 0 ; V_22 < V_13 -> V_87 ; V_22 ++ ) {
struct V_37 * V_38 = & V_13 -> V_79 [ V_22 ] ;
F_41 ( V_13 , V_22 ) ;
if ( V_38 -> V_134 )
F_58 ( & V_38 -> V_110 , 0 ) ;
}
return;
V_133:
for ( V_22 = 0 ; V_22 < V_13 -> V_86 ; V_22 ++ )
F_44 ( V_13 , V_22 ) ;
if ( V_8 < 0 ) {
F_75 ( V_24 ) ;
return;
}
V_76:
if ( F_68 ( V_24 , NULL , NULL ) == 1 )
F_58 ( & V_13 -> V_110 ,
F_59 ( V_116 ) ) ;
}
static void F_76 ( struct V_113 * V_114 )
{
struct V_37 * V_38 = F_57 ( V_114 ,
struct V_37 ,
V_110 . V_114 ) ;
struct V_100 * V_101 = V_38 -> V_24 -> V_101 ;
struct V_12 * V_13 = V_38 -> V_109 ;
int V_122 ;
F_77 ( ! V_13 -> V_44 ) ;
V_122 = F_73 ( V_13 -> V_24 , V_135 ) ;
F_70 ( V_13 -> V_24 , V_135 , V_122 | F_78 ( V_38 -> V_78 ) ) ;
F_79 ( V_13 -> V_24 , V_135 ) ;
F_80 ( & V_101 -> V_2 , L_45 , V_122 ) ;
if ( V_122 & F_78 ( V_38 -> V_78 ) ) {
F_54 ( & V_101 -> V_2 , L_46 , V_38 -> V_78 ) ;
V_38 -> V_44 = true ;
V_38 -> V_108 = true ;
if ( V_38 -> V_111 )
V_38 -> V_111 ( V_38 -> V_112 , V_38 -> V_44 ) ;
if ( V_38 -> V_108 )
F_81 ( & V_38 -> V_136 ) ;
} else if ( V_13 -> V_44 )
F_58 ( & V_38 -> V_110 ,
F_59 ( V_116 ) ) ;
}
static int F_82 ( struct V_12 * V_13 ,
unsigned int V_78 )
{
struct V_37 * V_38 ;
T_9 V_137 ;
T_6 V_138 ;
unsigned int V_84 , V_139 ;
unsigned int V_85 , V_86 , V_87 ;
T_7 V_140 ;
V_86 = V_13 -> V_86 ;
V_87 = V_13 -> V_87 ;
V_85 = F_42 ( V_13 , V_78 ) ;
V_38 = & V_13 -> V_79 [ V_78 ] ;
V_38 -> V_78 = V_78 ;
V_38 -> V_109 = V_13 ;
V_38 -> V_24 = V_13 -> V_24 ;
V_38 -> V_134 = false ;
V_38 -> V_111 = NULL ;
F_52 ( V_38 ) ;
if ( V_87 % V_86 && V_85 + 1 < V_87 / V_86 )
V_84 = V_87 / V_86 + 1 ;
else
V_84 = V_87 / V_86 ;
V_137 = V_13 -> V_88 [ V_85 ] . V_141 ;
V_138 = V_13 -> V_88 [ V_85 ] . V_124 ;
V_139 = ( unsigned int ) V_138 / V_84 ;
V_140 = V_139 * ( V_78 / V_86 ) ;
V_38 -> V_63 = V_13 -> V_88 [ V_85 ] . V_142 + V_140 ;
if ( ! V_38 -> V_63 )
return - V_9 ;
V_38 -> V_143 = V_137 + V_140 ;
if ( ! V_38 -> V_143 )
return - V_9 ;
V_139 -= sizeof( struct V_91 ) ;
V_38 -> V_144 = V_38 -> V_63 + V_139 ;
V_38 -> V_145 = F_43 ( V_93 , V_139 / 2 ) ;
V_38 -> V_66 = V_139 / V_38 -> V_145 ;
if ( V_13 -> V_146 ) {
char V_147 [ 4 ] ;
snprintf ( V_147 , 4 , L_47 , V_78 ) ;
V_38 -> V_148 = F_83 ( V_147 ,
V_13 -> V_146 ) ;
V_38 -> V_149 = F_84 ( L_48 , V_150 ,
V_38 -> V_148 , V_38 ,
& V_151 ) ;
} else {
V_38 -> V_148 = NULL ;
V_38 -> V_149 = NULL ;
}
F_85 ( & V_38 -> V_110 , F_76 ) ;
F_86 ( & V_38 -> V_115 , F_56 ) ;
F_87 ( & V_38 -> V_95 ) ;
F_87 ( & V_38 -> V_152 ) ;
F_88 ( & V_38 -> V_153 ) ;
F_88 ( & V_38 -> V_154 ) ;
F_88 ( & V_38 -> V_96 ) ;
F_88 ( & V_38 -> V_155 ) ;
F_89 ( & V_38 -> V_136 , V_156 ,
( unsigned long ) V_38 ) ;
return 0 ;
}
static int F_90 ( struct V_157 * V_158 , struct V_82 * V_24 )
{
struct V_12 * V_13 ;
struct V_80 * V_81 ;
unsigned int V_86 , V_87 ;
T_7 V_118 ;
int V_21 ;
int V_8 , V_22 ;
V_86 = F_91 ( V_24 ) ;
if ( F_92 ( V_24 ) < ( V_128 + 1 + V_86 * 2 ) ) {
F_12 ( & V_24 -> V_2 , L_49 ,
V_159 ) ;
return - V_107 ;
}
if ( F_93 ( V_24 ) )
F_74 ( & V_24 -> V_2 ,
L_50 ) ;
if ( F_94 ( V_24 ) )
F_74 ( & V_24 -> V_2 ,
L_51 ) ;
V_21 = F_22 ( & V_24 -> V_2 ) ;
V_13 = F_23 ( sizeof( * V_13 ) , V_25 , V_21 ) ;
if ( ! V_13 )
return - V_26 ;
V_13 -> V_24 = V_24 ;
V_13 -> V_86 = V_86 ;
V_13 -> V_88 = F_23 ( V_86 * sizeof( * V_13 -> V_88 ) ,
V_25 , V_21 ) ;
if ( ! V_13 -> V_88 ) {
V_8 = - V_26 ;
goto V_27;
}
for ( V_22 = 0 ; V_22 < V_86 ; V_22 ++ ) {
V_81 = & V_13 -> V_88 [ V_22 ] ;
V_8 = F_95 ( V_24 , V_22 , & V_81 -> V_141 , & V_81 -> V_124 ,
& V_81 -> V_106 , & V_81 -> V_105 ) ;
if ( V_8 )
goto V_160;
V_81 -> V_142 = F_96 ( V_81 -> V_141 , V_81 -> V_124 ) ;
if ( ! V_81 -> V_142 ) {
V_8 = - V_26 ;
goto V_160;
}
V_81 -> V_102 = 0 ;
V_81 -> V_90 = 0 ;
V_81 -> V_89 = NULL ;
V_81 -> V_103 = 0 ;
}
V_118 = F_97 ( V_24 ) ;
V_87 = F_98 ( V_118 ) ;
if ( V_161 && V_161 < V_87 )
V_87 = V_161 ;
else if ( V_86 < V_87 )
V_87 = V_86 ;
V_118 &= F_63 ( V_87 ) - 1 ;
V_13 -> V_87 = V_87 ;
V_13 -> V_118 = V_118 ;
V_13 -> V_119 = V_118 ;
V_13 -> V_79 = F_23 ( V_87 * sizeof( * V_13 -> V_79 ) ,
V_25 , V_21 ) ;
if ( ! V_13 -> V_79 ) {
V_8 = - V_26 ;
goto V_160;
}
if ( V_162 ) {
V_13 -> V_146 =
F_83 ( F_99 ( V_24 -> V_101 ) ,
V_162 ) ;
}
for ( V_22 = 0 ; V_22 < V_87 ; V_22 ++ ) {
V_8 = F_82 ( V_13 , V_22 ) ;
if ( V_8 )
goto V_163;
}
F_85 ( & V_13 -> V_110 , F_69 ) ;
F_86 ( & V_13 -> V_115 , F_66 ) ;
V_8 = F_100 ( V_24 , V_13 , & V_164 ) ;
if ( V_8 )
goto V_163;
F_88 ( & V_13 -> V_31 ) ;
V_8 = F_8 ( V_13 ) ;
if ( V_8 )
goto V_165;
V_13 -> V_44 = false ;
F_101 ( V_24 , V_166 , V_167 ) ;
F_102 ( V_24 ) ;
return 0 ;
V_165:
F_103 ( V_24 ) ;
V_163:
F_17 ( V_13 -> V_79 ) ;
V_160:
while ( V_22 -- ) {
V_81 = & V_13 -> V_88 [ V_22 ] ;
F_104 ( V_81 -> V_142 ) ;
}
F_17 ( V_13 -> V_88 ) ;
V_27:
F_17 ( V_13 ) ;
return V_8 ;
}
static void F_105 ( struct V_157 * V_158 , struct V_82 * V_24 )
{
struct V_12 * V_13 = V_24 -> V_168 ;
struct V_37 * V_38 ;
T_7 V_117 ;
int V_22 ;
F_62 ( V_13 ) ;
F_64 ( & V_13 -> V_115 ) ;
F_55 ( & V_13 -> V_110 ) ;
V_117 = V_13 -> V_118 & ~ V_13 -> V_119 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_87 ; V_22 ++ ) {
V_38 = & V_13 -> V_79 [ V_22 ] ;
if ( V_117 & F_63 ( V_22 ) )
F_106 ( V_38 ) ;
F_107 ( V_38 -> V_148 ) ;
}
F_75 ( V_24 ) ;
F_103 ( V_24 ) ;
F_10 ( V_13 ) ;
for ( V_22 = V_13 -> V_86 ; V_22 -- ; ) {
F_44 ( V_13 , V_22 ) ;
F_104 ( V_13 -> V_88 [ V_22 ] . V_142 ) ;
}
F_17 ( V_13 -> V_79 ) ;
F_17 ( V_13 -> V_88 ) ;
F_17 ( V_13 ) ;
}
static void F_108 ( struct V_37 * V_38 )
{
struct V_75 * V_14 ;
void * V_112 ;
unsigned int V_169 ;
unsigned long V_170 ;
F_35 ( & V_38 -> V_95 , V_170 ) ;
while ( ! F_21 ( & V_38 -> V_153 ) ) {
V_14 = F_38 ( & V_38 -> V_153 ,
struct V_75 , V_14 ) ;
if ( ! ( V_14 -> V_74 & V_171 ) )
break;
V_14 -> V_172 -> V_74 = 0 ;
F_109 ( V_14 -> V_54 , & V_38 -> V_144 -> V_14 ) ;
V_112 = V_14 -> V_112 ;
V_169 = V_14 -> V_169 ;
F_40 ( & V_14 -> V_14 , & V_38 -> V_96 ) ;
F_36 ( & V_38 -> V_95 , V_170 ) ;
if ( V_38 -> V_173 && V_38 -> V_134 )
V_38 -> V_173 ( V_38 , V_38 -> V_112 , V_112 , V_169 ) ;
F_35 ( & V_38 -> V_95 , V_170 ) ;
}
F_36 ( & V_38 -> V_95 , V_170 ) ;
}
static void F_110 ( void * V_121 ,
const struct V_174 * V_175 )
{
struct V_75 * V_14 = V_121 ;
if ( V_175 ) {
enum V_176 V_177 = V_175 -> V_178 ;
switch ( V_177 ) {
case V_179 :
case V_180 :
V_14 -> V_181 ++ ;
case V_182 :
{
struct V_37 * V_38 = V_14 -> V_38 ;
void * V_97 = V_38 -> V_53 + V_38 -> V_92 *
V_38 -> V_54 ;
F_111 ( V_14 , V_97 ) ;
V_38 -> V_47 ++ ;
return;
}
case V_183 :
default:
break;
}
}
V_14 -> V_74 |= V_171 ;
F_108 ( V_14 -> V_38 ) ;
}
static void F_111 ( struct V_75 * V_14 , void * V_97 )
{
void * V_39 = V_14 -> V_39 ;
T_3 V_169 = V_14 -> V_169 ;
memcpy ( V_39 , V_97 , V_169 ) ;
F_112 () ;
F_110 ( V_14 , NULL ) ;
}
static int F_113 ( struct V_75 * V_14 , void * V_97 )
{
struct V_184 * V_185 ;
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_186 * V_187 = V_38 -> V_70 ;
struct V_188 * V_1 ;
T_3 V_189 , V_190 , V_169 ;
struct V_191 * V_192 ;
T_10 V_193 ;
void * V_39 = V_14 -> V_39 ;
int V_194 = 0 ;
V_169 = V_14 -> V_169 ;
V_1 = V_187 -> V_1 ;
V_189 = ( T_3 ) V_97 & ~ V_195 ;
V_190 = ( T_3 ) V_39 & ~ V_195 ;
if ( ! F_114 ( V_1 , V_189 , V_190 , V_169 ) )
goto V_27;
V_192 = F_115 ( V_1 -> V_2 , 2 , V_196 ) ;
if ( ! V_192 )
goto V_27;
V_192 -> V_169 = V_169 ;
V_192 -> V_197 [ 0 ] = F_116 ( V_1 -> V_2 , F_117 ( V_97 ) ,
V_189 , V_169 , V_198 ) ;
if ( F_118 ( V_1 -> V_2 , V_192 -> V_197 [ 0 ] ) )
goto V_199;
V_192 -> V_200 = 1 ;
V_192 -> V_197 [ 1 ] = F_116 ( V_1 -> V_2 , F_117 ( V_39 ) ,
V_190 , V_169 , V_201 ) ;
if ( F_118 ( V_1 -> V_2 , V_192 -> V_197 [ 1 ] ) )
goto V_199;
V_192 -> V_202 = 1 ;
for ( V_194 = 0 ; V_194 < V_203 ; V_194 ++ ) {
V_185 = V_1 -> V_204 ( V_187 ,
V_192 -> V_197 [ 1 ] ,
V_192 -> V_197 [ 0 ] , V_169 ,
V_205 ) ;
if ( V_185 )
break;
F_119 ( V_206 ) ;
F_120 ( V_207 ) ;
}
if ( ! V_185 ) {
V_38 -> V_68 ++ ;
goto V_199;
}
V_185 -> V_208 = F_110 ;
V_185 -> V_209 = V_14 ;
F_121 ( V_185 , V_192 ) ;
V_193 = F_122 ( V_185 ) ;
if ( F_123 ( V_193 ) )
goto V_210;
F_124 ( V_192 ) ;
V_38 -> V_211 = V_193 ;
V_38 -> V_48 ++ ;
return 0 ;
V_210:
F_124 ( V_192 ) ;
V_199:
F_124 ( V_192 ) ;
V_27:
return - V_212 ;
}
static void F_125 ( struct V_75 * V_14 , void * V_97 )
{
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_186 * V_187 = V_38 -> V_70 ;
int V_175 ;
if ( ! V_187 )
goto V_27;
if ( V_14 -> V_169 < V_213 )
goto V_27;
V_175 = F_113 ( V_14 , V_97 ) ;
if ( V_175 < 0 )
goto V_27;
if ( ! V_14 -> V_194 )
V_38 -> V_48 ++ ;
return;
V_27:
F_111 ( V_14 , V_97 ) ;
V_38 -> V_47 ++ ;
}
static int F_126 ( struct V_37 * V_38 )
{
struct V_98 * V_214 ;
struct V_75 * V_14 ;
void * V_97 ;
V_97 = V_38 -> V_53 + V_38 -> V_92 * V_38 -> V_54 ;
V_214 = V_97 + V_38 -> V_92 - sizeof( struct V_98 ) ;
F_74 ( & V_38 -> V_24 -> V_101 -> V_2 , L_52 ,
V_38 -> V_78 , V_214 -> V_215 , V_214 -> V_169 , V_214 -> V_74 ) ;
if ( ! ( V_214 -> V_74 & V_171 ) ) {
F_74 ( & V_38 -> V_24 -> V_101 -> V_2 , L_53 ) ;
V_38 -> V_49 ++ ;
return - V_216 ;
}
if ( V_214 -> V_74 & V_217 ) {
F_74 ( & V_38 -> V_24 -> V_101 -> V_2 , L_54 ) ;
F_60 ( V_38 ) ;
V_214 -> V_74 = 0 ;
return - V_216 ;
}
if ( V_214 -> V_215 != ( T_8 ) V_38 -> V_46 ) {
F_74 ( & V_38 -> V_24 -> V_101 -> V_2 ,
L_55 ,
V_38 -> V_46 , V_214 -> V_215 ) ;
V_38 -> V_52 ++ ;
return - V_107 ;
}
V_14 = F_39 ( & V_38 -> V_95 , & V_38 -> V_154 , & V_38 -> V_153 ) ;
if ( ! V_14 ) {
F_74 ( & V_38 -> V_24 -> V_101 -> V_2 , L_56 ) ;
V_38 -> V_50 ++ ;
return - V_216 ;
}
V_14 -> V_172 = V_214 ;
V_14 -> V_54 = V_38 -> V_54 ;
if ( V_214 -> V_169 > V_14 -> V_169 ) {
F_74 ( & V_38 -> V_24 -> V_101 -> V_2 ,
L_57 ,
V_214 -> V_169 , V_14 -> V_169 ) ;
V_38 -> V_51 ++ ;
V_14 -> V_169 = - V_107 ;
V_14 -> V_74 |= V_171 ;
F_108 ( V_38 ) ;
} else {
F_74 ( & V_38 -> V_24 -> V_101 -> V_2 ,
L_58 ,
V_38 -> V_54 , V_214 -> V_215 , V_214 -> V_169 , V_14 -> V_169 ) ;
V_38 -> V_45 += V_214 -> V_169 ;
V_38 -> V_46 ++ ;
V_14 -> V_169 = V_214 -> V_169 ;
F_125 ( V_14 , V_97 ) ;
}
V_38 -> V_54 ++ ;
V_38 -> V_54 %= V_38 -> V_55 ;
return 0 ;
}
static void V_156 ( unsigned long V_121 )
{
struct V_37 * V_38 = ( void * ) V_121 ;
int V_8 , V_22 ;
F_74 ( & V_38 -> V_24 -> V_101 -> V_2 , L_59 ,
V_218 , V_38 -> V_78 ) ;
for ( V_22 = 0 ; V_22 < V_38 -> V_55 ; V_22 ++ ) {
V_8 = F_126 ( V_38 ) ;
if ( V_8 )
break;
}
if ( V_22 && V_38 -> V_70 )
F_127 ( V_38 -> V_70 ) ;
if ( V_22 == V_38 -> V_55 ) {
if ( V_38 -> V_108 )
F_81 ( & V_38 -> V_136 ) ;
} else if ( F_128 ( V_38 -> V_24 ) & F_63 ( V_38 -> V_78 ) ) {
F_129 ( V_38 -> V_24 , F_63 ( V_38 -> V_78 ) ) ;
F_128 ( V_38 -> V_24 ) ;
if ( V_38 -> V_108 )
F_81 ( & V_38 -> V_136 ) ;
}
}
static void F_130 ( void * V_121 ,
const struct V_174 * V_175 )
{
struct V_75 * V_14 = V_121 ;
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_98 T_11 * V_214 = V_14 -> V_219 ;
if ( V_175 ) {
enum V_176 V_177 = V_175 -> V_178 ;
switch ( V_177 ) {
case V_179 :
case V_180 :
V_14 -> V_181 ++ ;
case V_182 :
{
void T_11 * V_97 =
V_38 -> V_63 + V_38 -> V_145 *
V_14 -> V_64 ;
F_131 ( V_14 , V_97 ) ;
V_38 -> V_59 ++ ;
return;
}
case V_183 :
default:
break;
}
}
F_109 ( V_14 -> V_74 | V_171 , & V_214 -> V_74 ) ;
F_132 ( V_38 -> V_24 , F_63 ( V_38 -> V_78 ) ) ;
if ( V_14 -> V_169 > 0 ) {
V_38 -> V_57 += V_14 -> V_169 ;
if ( V_38 -> V_220 )
V_38 -> V_220 ( V_38 , V_38 -> V_112 , V_14 -> V_112 ,
V_14 -> V_169 ) ;
}
F_34 ( & V_38 -> V_152 , & V_14 -> V_14 , & V_38 -> V_155 ) ;
}
static void F_131 ( struct V_75 * V_14 , void T_11 * V_97 )
{
#ifdef F_133
F_134 ( V_97 , V_14 -> V_39 , V_14 -> V_169 ) ;
#else
F_135 ( V_97 , V_14 -> V_39 , V_14 -> V_169 ) ;
#endif
F_112 () ;
F_130 ( V_14 , NULL ) ;
}
static int F_136 ( struct V_37 * V_38 ,
struct V_75 * V_14 )
{
struct V_184 * V_185 ;
struct V_186 * V_187 = V_38 -> V_69 ;
struct V_188 * V_1 ;
T_3 V_169 = V_14 -> V_169 ;
void * V_39 = V_14 -> V_39 ;
T_3 V_221 , V_190 ;
struct V_191 * V_192 ;
T_12 V_222 ;
T_10 V_193 ;
int V_194 = 0 ;
V_1 = V_187 -> V_1 ;
V_222 = V_38 -> V_143 + V_38 -> V_145 * V_14 -> V_64 ;
V_190 = ( T_3 ) V_39 & ~ V_195 ;
V_221 = ( T_3 ) V_222 & ~ V_195 ;
if ( ! F_114 ( V_1 , V_190 , V_221 , V_169 ) )
goto V_27;
V_192 = F_115 ( V_1 -> V_2 , 1 , V_196 ) ;
if ( ! V_192 )
goto V_27;
V_192 -> V_169 = V_169 ;
V_192 -> V_197 [ 0 ] = F_116 ( V_1 -> V_2 , F_117 ( V_39 ) ,
V_190 , V_169 , V_198 ) ;
if ( F_118 ( V_1 -> V_2 , V_192 -> V_197 [ 0 ] ) )
goto V_199;
V_192 -> V_200 = 1 ;
for ( V_194 = 0 ; V_194 < V_203 ; V_194 ++ ) {
V_185 = V_1 -> V_204 ( V_187 , V_222 ,
V_192 -> V_197 [ 0 ] , V_169 ,
V_205 ) ;
if ( V_185 )
break;
F_119 ( V_206 ) ;
F_120 ( V_207 ) ;
}
if ( ! V_185 ) {
V_38 -> V_67 ++ ;
goto V_199;
}
V_185 -> V_208 = F_130 ;
V_185 -> V_209 = V_14 ;
F_121 ( V_185 , V_192 ) ;
V_193 = F_122 ( V_185 ) ;
if ( F_123 ( V_193 ) )
goto V_210;
F_124 ( V_192 ) ;
F_127 ( V_187 ) ;
return 0 ;
V_210:
F_124 ( V_192 ) ;
V_199:
F_124 ( V_192 ) ;
V_27:
return - V_212 ;
}
static void F_137 ( struct V_37 * V_38 ,
struct V_75 * V_14 )
{
struct V_98 T_11 * V_214 ;
struct V_186 * V_187 = V_38 -> V_69 ;
void T_11 * V_97 ;
int V_175 ;
V_14 -> V_64 = V_38 -> V_64 ;
V_97 = V_38 -> V_63 + V_38 -> V_145 * V_14 -> V_64 ;
V_214 = V_97 + V_38 -> V_145 - sizeof( struct V_98 ) ;
V_14 -> V_219 = V_214 ;
F_109 ( V_14 -> V_169 , & V_214 -> V_169 ) ;
F_109 ( ( T_8 ) V_38 -> V_58 , & V_214 -> V_215 ) ;
if ( ! V_187 )
goto V_27;
if ( V_14 -> V_169 < V_213 )
goto V_27;
V_175 = F_136 ( V_38 , V_14 ) ;
if ( V_175 < 0 )
goto V_27;
if ( ! V_14 -> V_194 )
V_38 -> V_60 ++ ;
return;
V_27:
F_131 ( V_14 , V_97 ) ;
V_38 -> V_59 ++ ;
}
static int F_138 ( struct V_37 * V_38 ,
struct V_75 * V_14 )
{
if ( V_38 -> V_64 == V_38 -> V_65 -> V_14 ) {
V_38 -> V_61 ++ ;
return - V_216 ;
}
if ( V_14 -> V_169 > V_38 -> V_145 - sizeof( struct V_98 ) ) {
if ( V_38 -> V_220 )
V_38 -> V_220 ( V_38 , V_38 -> V_112 , NULL , - V_107 ) ;
F_34 ( & V_38 -> V_152 , & V_14 -> V_14 ,
& V_38 -> V_155 ) ;
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
struct V_100 * V_101 = V_38 -> V_24 -> V_101 ;
struct V_75 * V_14 ;
int V_22 , V_8 ;
if ( ! V_38 -> V_44 )
return;
F_54 ( & V_101 -> V_2 , L_60 , V_38 -> V_78 ) ;
for ( V_22 = 0 ; V_22 < V_116 ; V_22 ++ ) {
V_14 = F_37 ( & V_38 -> V_152 , & V_38 -> V_155 ) ;
if ( V_14 )
break;
F_140 ( 100 ) ;
}
if ( ! V_14 )
return;
V_14 -> V_112 = NULL ;
V_14 -> V_39 = NULL ;
V_14 -> V_169 = 0 ;
V_14 -> V_74 = V_217 ;
V_8 = F_138 ( V_38 , V_14 ) ;
if ( V_8 )
F_12 ( & V_101 -> V_2 , L_61 ,
V_38 -> V_78 ) ;
F_52 ( V_38 ) ;
}
static bool F_141 ( struct V_186 * V_187 , void * V_21 )
{
return F_22 ( & V_187 -> V_2 -> V_1 ) == ( int ) ( unsigned long ) V_21 ;
}
struct V_37 *
F_142 ( void * V_121 , struct V_1 * V_17 ,
const struct V_223 * V_224 )
{
struct V_82 * V_24 ;
struct V_100 * V_101 ;
struct V_12 * V_13 ;
struct V_75 * V_14 ;
struct V_37 * V_38 ;
T_7 V_225 ;
unsigned int V_226 ;
T_13 V_227 ;
int V_21 ;
int V_22 ;
V_24 = F_143 ( V_17 -> V_19 ) ;
V_101 = V_24 -> V_101 ;
V_13 = V_24 -> V_168 ;
V_21 = F_22 ( & V_24 -> V_2 ) ;
V_226 = F_144 ( V_13 -> V_118 ) ;
if ( ! V_226 )
goto V_27;
V_226 -- ;
V_38 = & V_13 -> V_79 [ V_226 ] ;
V_225 = F_63 ( V_38 -> V_78 ) ;
V_13 -> V_119 &= ~ V_225 ;
V_38 -> V_112 = V_121 ;
V_38 -> V_173 = V_224 -> V_173 ;
V_38 -> V_220 = V_224 -> V_220 ;
V_38 -> V_111 = V_224 -> V_111 ;
F_145 ( V_227 ) ;
F_146 ( V_228 , V_227 ) ;
if ( V_229 ) {
V_38 -> V_69 =
F_147 ( V_227 , F_141 ,
( void * ) ( unsigned long ) V_21 ) ;
if ( ! V_38 -> V_69 )
F_54 ( & V_101 -> V_2 , L_62 ) ;
V_38 -> V_70 =
F_147 ( V_227 , F_141 ,
( void * ) ( unsigned long ) V_21 ) ;
if ( ! V_38 -> V_70 )
F_54 ( & V_101 -> V_2 , L_63 ) ;
} else {
V_38 -> V_69 = NULL ;
V_38 -> V_70 = NULL ;
}
F_74 ( & V_101 -> V_2 , L_64 ,
V_38 -> V_69 ? L_65 : L_66 ) ;
F_74 ( & V_101 -> V_2 , L_67 ,
V_38 -> V_70 ? L_65 : L_66 ) ;
for ( V_22 = 0 ; V_22 < V_230 ; V_22 ++ ) {
V_14 = F_23 ( sizeof( * V_14 ) , V_94 , V_21 ) ;
if ( ! V_14 )
goto V_160;
V_14 -> V_38 = V_38 ;
F_34 ( & V_38 -> V_95 , & V_14 -> V_14 ,
& V_38 -> V_96 ) ;
}
V_38 -> V_56 = V_230 ;
for ( V_22 = 0 ; V_22 < V_38 -> V_66 ; V_22 ++ ) {
V_14 = F_23 ( sizeof( * V_14 ) , V_94 , V_21 ) ;
if ( ! V_14 )
goto V_163;
V_14 -> V_38 = V_38 ;
F_34 ( & V_38 -> V_152 , & V_14 -> V_14 ,
& V_38 -> V_155 ) ;
}
F_129 ( V_38 -> V_24 , V_225 ) ;
F_148 ( V_38 -> V_24 , V_225 ) ;
F_54 ( & V_101 -> V_2 , L_68 , V_38 -> V_78 ) ;
return V_38 ;
V_163:
while ( ( V_14 = F_37 ( & V_38 -> V_152 , & V_38 -> V_155 ) ) )
F_17 ( V_14 ) ;
V_160:
V_38 -> V_56 = 0 ;
while ( ( V_14 = F_37 ( & V_38 -> V_95 , & V_38 -> V_96 ) ) )
F_17 ( V_14 ) ;
if ( V_38 -> V_69 )
F_149 ( V_38 -> V_69 ) ;
if ( V_38 -> V_70 )
F_149 ( V_38 -> V_70 ) ;
V_13 -> V_119 |= V_225 ;
V_27:
return NULL ;
}
void F_106 ( struct V_37 * V_38 )
{
struct V_100 * V_101 ;
struct V_75 * V_14 ;
T_7 V_225 ;
if ( ! V_38 )
return;
V_101 = V_38 -> V_24 -> V_101 ;
V_38 -> V_108 = false ;
if ( V_38 -> V_69 ) {
struct V_186 * V_187 = V_38 -> V_69 ;
V_38 -> V_69 = NULL ;
F_150 ( V_187 , V_38 -> V_211 ) ;
F_151 ( V_187 ) ;
F_149 ( V_187 ) ;
}
if ( V_38 -> V_70 ) {
struct V_186 * V_187 = V_38 -> V_70 ;
V_38 -> V_70 = NULL ;
F_150 ( V_187 , V_38 -> V_211 ) ;
F_151 ( V_187 ) ;
F_149 ( V_187 ) ;
}
V_225 = F_63 ( V_38 -> V_78 ) ;
F_152 ( V_38 -> V_24 , V_225 ) ;
F_153 ( & V_38 -> V_136 ) ;
F_55 ( & V_38 -> V_110 ) ;
V_38 -> V_112 = NULL ;
V_38 -> V_173 = NULL ;
V_38 -> V_220 = NULL ;
V_38 -> V_111 = NULL ;
while ( ( V_14 = F_37 ( & V_38 -> V_95 , & V_38 -> V_96 ) ) )
F_17 ( V_14 ) ;
while ( ( V_14 = F_37 ( & V_38 -> V_95 , & V_38 -> V_154 ) ) ) {
F_154 ( & V_101 -> V_2 , L_69 ) ;
F_17 ( V_14 ) ;
}
while ( ( V_14 = F_37 ( & V_38 -> V_95 , & V_38 -> V_153 ) ) ) {
F_154 ( & V_101 -> V_2 , L_70 ) ;
F_17 ( V_14 ) ;
}
while ( ( V_14 = F_37 ( & V_38 -> V_152 , & V_38 -> V_155 ) ) )
F_17 ( V_14 ) ;
V_38 -> V_109 -> V_119 |= V_225 ;
F_54 ( & V_101 -> V_2 , L_71 , V_38 -> V_78 ) ;
}
void * F_155 ( struct V_37 * V_38 , unsigned int * V_169 )
{
struct V_75 * V_14 ;
void * V_39 ;
if ( ! V_38 || V_38 -> V_134 )
return NULL ;
V_14 = F_37 ( & V_38 -> V_95 , & V_38 -> V_154 ) ;
if ( ! V_14 )
return NULL ;
V_39 = V_14 -> V_112 ;
* V_169 = V_14 -> V_169 ;
F_34 ( & V_38 -> V_95 , & V_14 -> V_14 , & V_38 -> V_96 ) ;
return V_39 ;
}
int F_156 ( struct V_37 * V_38 , void * V_231 , void * V_121 ,
unsigned int V_169 )
{
struct V_75 * V_14 ;
if ( ! V_38 )
return - V_9 ;
V_14 = F_37 ( & V_38 -> V_95 , & V_38 -> V_96 ) ;
if ( ! V_14 )
return - V_26 ;
V_14 -> V_112 = V_231 ;
V_14 -> V_39 = V_121 ;
V_14 -> V_169 = V_169 ;
V_14 -> V_74 = 0 ;
V_14 -> V_194 = 0 ;
V_14 -> V_181 = 0 ;
V_14 -> V_54 = 0 ;
F_34 ( & V_38 -> V_95 , & V_14 -> V_14 , & V_38 -> V_154 ) ;
if ( V_38 -> V_108 )
F_81 ( & V_38 -> V_136 ) ;
return 0 ;
}
int F_157 ( struct V_37 * V_38 , void * V_231 , void * V_121 ,
unsigned int V_169 )
{
struct V_75 * V_14 ;
int V_8 ;
if ( ! V_38 || ! V_38 -> V_44 || ! V_169 )
return - V_9 ;
V_14 = F_37 ( & V_38 -> V_152 , & V_38 -> V_155 ) ;
if ( ! V_14 ) {
V_38 -> V_62 ++ ;
return - V_232 ;
}
V_14 -> V_112 = V_231 ;
V_14 -> V_39 = V_121 ;
V_14 -> V_169 = V_169 ;
V_14 -> V_74 = 0 ;
V_14 -> V_181 = 0 ;
V_14 -> V_194 = 0 ;
V_14 -> V_64 = 0 ;
V_8 = F_138 ( V_38 , V_14 ) ;
if ( V_8 )
F_34 ( & V_38 -> V_152 , & V_14 -> V_14 ,
& V_38 -> V_155 ) ;
return V_8 ;
}
void F_158 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return;
V_38 -> V_134 = true ;
if ( V_38 -> V_109 -> V_44 )
F_58 ( & V_38 -> V_110 , 0 ) ;
}
void F_159 ( struct V_37 * V_38 )
{
int V_122 ;
if ( ! V_38 )
return;
V_38 -> V_134 = false ;
V_122 = F_73 ( V_38 -> V_24 , V_135 ) ;
F_70 ( V_38 -> V_24 , V_135 ,
V_122 & ~ F_78 ( V_38 -> V_78 ) ) ;
if ( V_38 -> V_44 )
F_139 ( V_38 ) ;
else
F_55 ( & V_38 -> V_110 ) ;
}
bool F_160 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return false ;
return V_38 -> V_44 ;
}
unsigned char F_161 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return 0 ;
return V_38 -> V_78 ;
}
unsigned int F_162 ( struct V_37 * V_38 )
{
unsigned int V_233 ;
unsigned int V_234 ;
struct V_186 * V_235 , * V_236 ;
if ( ! V_38 )
return 0 ;
V_235 = V_38 -> V_70 ;
V_236 = V_38 -> V_69 ;
V_234 = F_163 ( V_235 ? V_235 -> V_1 -> V_234 : 0 ,
V_236 ? V_236 -> V_1 -> V_234 : 0 ) ;
V_233 = V_38 -> V_145 - sizeof( struct V_98 ) ;
V_233 = F_164 ( V_233 , 1 << V_234 ) ;
return V_233 ;
}
unsigned int F_32 ( struct V_37 * V_38 )
{
unsigned int V_237 = V_38 -> V_64 ;
unsigned int V_238 = V_38 -> V_65 -> V_14 ;
return V_238 > V_237 ? V_238 - V_237 : V_38 -> V_66 + V_238 - V_237 ;
}
static void F_165 ( void * V_121 , int V_239 )
{
struct V_12 * V_13 = V_121 ;
struct V_37 * V_38 ;
T_7 V_240 ;
unsigned int V_78 ;
V_240 = ( V_13 -> V_118 & ~ V_13 -> V_119 &
F_166 ( V_13 -> V_24 , V_239 ) ) ;
while ( V_240 ) {
V_78 = F_167 ( V_240 ) ;
V_38 = & V_13 -> V_79 [ V_78 ] ;
if ( V_38 -> V_108 )
F_81 ( & V_38 -> V_136 ) ;
V_240 &= ~ F_63 ( V_78 ) ;
}
}
static int T_14 F_168 ( void )
{
int V_8 ;
F_169 ( L_72 , V_241 , V_242 ) ;
if ( F_170 () )
V_162 = F_83 ( V_243 , NULL ) ;
V_8 = F_171 ( & V_29 ) ;
if ( V_8 )
goto V_244;
V_8 = F_172 ( & V_6 ) ;
if ( V_8 )
goto V_245;
return 0 ;
V_245:
F_173 ( & V_29 ) ;
V_244:
F_107 ( V_162 ) ;
return V_8 ;
}
static void T_15 F_174 ( void )
{
F_107 ( V_162 ) ;
F_175 ( & V_6 ) ;
F_173 ( & V_29 ) ;
}
