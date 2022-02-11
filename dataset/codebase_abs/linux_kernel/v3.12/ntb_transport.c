static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return ! strncmp ( F_2 ( V_2 ) , V_4 -> V_5 , strlen ( V_4 -> V_5 ) ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
const struct V_6 * V_4 = F_4 ( V_2 -> V_7 ,
struct V_6 , V_7 ) ;
struct V_8 * V_9 = F_4 ( V_2 -> V_10 , struct V_8 , V_2 ) ;
int V_11 = - V_12 ;
F_5 ( V_2 ) ;
if ( V_4 && V_4 -> V_13 )
V_11 = V_4 -> V_13 ( V_9 ) ;
if ( V_11 )
F_6 ( V_2 ) ;
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 )
{
const struct V_6 * V_4 = F_4 ( V_2 -> V_7 ,
struct V_6 , V_7 ) ;
struct V_8 * V_9 = F_4 ( V_2 -> V_10 , struct V_8 , V_2 ) ;
if ( V_4 && V_4 -> remove )
V_4 -> remove ( V_9 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 )
{
if ( F_9 ( & V_16 ) ) {
int V_11 = F_10 ( & V_17 ) ;
if ( V_11 )
return V_11 ;
}
F_11 ( & V_15 -> V_18 , & V_16 ) ;
return 0 ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_19 * V_20 , * V_21 ;
F_13 (client_dev, cd, &nt->client_devs, entry) {
F_14 ( V_20 -> V_2 . V_10 , L_1 ,
F_2 ( & V_20 -> V_2 ) ) ;
F_15 ( & V_20 -> V_18 ) ;
F_16 ( & V_20 -> V_2 ) ;
}
F_15 ( & V_15 -> V_18 ) ;
if ( F_9 ( & V_16 ) )
F_17 ( & V_17 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
V_20 = F_4 ( V_2 , struct V_19 , V_2 ) ;
F_19 ( V_20 ) ;
}
void F_20 ( char * V_22 )
{
struct V_19 * V_23 , * V_21 ;
struct V_14 * V_15 ;
F_21 (nt, &ntb_transport_list, entry)
F_13 (client, cd, &nt->client_devs, entry)
if ( ! strncmp ( F_2 ( & V_23 -> V_2 ) , V_22 ,
strlen ( V_22 ) ) ) {
F_15 ( & V_23 -> V_18 ) ;
F_16 ( & V_23 -> V_2 ) ;
}
}
int F_22 ( char * V_22 )
{
struct V_19 * V_20 ;
struct V_14 * V_15 ;
int V_11 , V_24 = 0 ;
if ( F_9 ( & V_16 ) )
return - V_25 ;
F_21 (nt, &ntb_transport_list, entry) {
struct V_1 * V_2 ;
V_20 = F_23 ( sizeof( struct V_19 ) ,
V_26 ) ;
if ( ! V_20 ) {
V_11 = - V_27 ;
goto V_28;
}
V_2 = & V_20 -> V_2 ;
F_24 ( V_2 , L_2 , V_22 , V_24 ) ;
V_2 -> V_29 = & V_17 ;
V_2 -> V_30 = F_18 ;
V_2 -> V_10 = & F_25 ( V_15 -> V_31 ) -> V_2 ;
V_11 = F_26 ( V_2 ) ;
if ( V_11 ) {
F_19 ( V_20 ) ;
goto V_28;
}
F_27 ( & V_20 -> V_18 , & V_15 -> V_32 ) ;
V_24 ++ ;
}
return 0 ;
V_28:
F_20 ( V_22 ) ;
return V_11 ;
}
int F_28 ( struct V_6 * V_4 )
{
V_4 -> V_7 . V_29 = & V_17 ;
if ( F_9 ( & V_16 ) )
return - V_25 ;
return F_29 ( & V_4 -> V_7 ) ;
}
void F_30 ( struct V_6 * V_4 )
{
F_31 ( & V_4 -> V_7 ) ;
}
static T_1 F_32 ( struct V_33 * V_34 , char T_2 * V_35 , T_3 V_36 ,
T_4 * V_37 )
{
struct V_38 * V_39 ;
char * V_40 ;
T_1 V_41 , V_42 , V_43 ;
V_43 = 1000 ;
V_40 = F_33 ( V_43 , V_26 ) ;
if ( ! V_40 )
return - V_27 ;
V_39 = V_34 -> V_44 ;
V_42 = 0 ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_3 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_4 , V_39 -> V_45 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_5 , V_39 -> V_46 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_6 , V_39 -> V_47 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_7 , V_39 -> V_48 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_8 , V_39 -> V_49 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_9 , V_39 -> V_50 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_10 , V_39 -> V_51 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_11 , V_39 -> V_52 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_12 , V_39 -> V_53 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_13 , V_39 -> V_54 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_14 , V_39 -> V_55 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_15 , V_39 -> V_56 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_16 , V_39 -> V_57 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_17 , V_39 -> V_58 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_18 , V_39 -> V_59 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_19 , V_39 -> V_60 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_20 , V_39 -> V_61 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_21 , V_39 -> V_62 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_22 , V_39 -> V_63 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_23 , V_39 -> V_64 ) ;
V_42 += snprintf ( V_40 + V_42 , V_43 - V_42 ,
L_24 , ( V_39 -> V_65 == V_66 ) ?
L_25 : L_26 ) ;
if ( V_42 > V_43 )
V_42 = V_43 ;
V_41 = F_34 ( V_35 , V_36 , V_37 , V_40 , V_42 ) ;
F_19 ( V_40 ) ;
return V_41 ;
}
static void F_35 ( T_5 * V_67 , struct V_68 * V_18 ,
struct V_68 * V_69 )
{
unsigned long V_70 ;
F_36 ( V_67 , V_70 ) ;
F_27 ( V_18 , V_69 ) ;
F_37 ( V_67 , V_70 ) ;
}
static struct V_71 * F_38 ( T_5 * V_67 ,
struct V_68 * V_69 )
{
struct V_71 * V_18 ;
unsigned long V_70 ;
F_36 ( V_67 , V_70 ) ;
if ( F_9 ( V_69 ) ) {
V_18 = NULL ;
goto V_72;
}
V_18 = F_39 ( V_69 , struct V_71 , V_18 ) ;
F_15 ( & V_18 -> V_18 ) ;
V_72:
F_37 ( V_67 , V_70 ) ;
return V_18 ;
}
static void F_40 ( struct V_14 * V_15 ,
unsigned int V_73 )
{
struct V_38 * V_39 = & V_15 -> V_74 [ V_73 ] ;
unsigned int V_75 , V_76 ;
T_6 V_77 , V_78 ;
unsigned int V_24 ;
V_78 = F_41 ( V_15 -> V_31 ) ;
V_77 = F_42 ( V_15 -> V_31 , V_73 ) ;
F_43 ( V_15 -> V_79 [ V_77 ] . V_80 == NULL ) ;
if ( V_15 -> V_81 % V_78 && V_77 < V_15 -> V_81 % V_78 )
V_76 = V_15 -> V_81 / V_78 + 1 ;
else
V_76 = V_15 -> V_81 / V_78 ;
V_75 = ( unsigned int ) V_15 -> V_79 [ V_77 ] . V_82 / V_76 ;
V_39 -> V_53 = V_15 -> V_79 [ V_77 ] . V_80 + V_73 / V_78 * V_75 ;
V_75 -= sizeof( struct V_83 ) ;
V_39 -> V_84 = V_39 -> V_53 + V_75 ;
V_39 -> V_85 = F_44 ( V_86 , V_75 / 2 ) ;
V_39 -> V_55 = V_75 / V_39 -> V_85 ;
V_39 -> V_54 = 0 ;
V_39 -> V_84 -> V_18 = V_39 -> V_55 - 1 ;
for ( V_24 = 0 ; V_24 < V_39 -> V_55 ; V_24 ++ ) {
void * V_87 = V_39 -> V_53 + V_39 -> V_85 * ( V_24 + 1 ) -
sizeof( struct V_88 ) ;
memset ( V_87 , 0 , sizeof( struct V_88 ) ) ;
}
V_39 -> V_46 = 0 ;
V_39 -> V_57 = 0 ;
V_39 -> V_63 = 0 ;
}
static void F_45 ( struct V_14 * V_15 , int V_89 )
{
struct V_90 * V_79 = & V_15 -> V_79 [ V_89 ] ;
struct V_8 * V_9 = F_25 ( V_15 -> V_31 ) ;
if ( ! V_79 -> V_80 )
return;
F_46 ( & V_9 -> V_2 , V_79 -> V_82 , V_79 -> V_80 , V_79 -> V_91 ) ;
V_79 -> V_80 = NULL ;
}
static int F_47 ( struct V_14 * V_15 , int V_89 , unsigned int V_82 )
{
struct V_90 * V_79 = & V_15 -> V_79 [ V_89 ] ;
struct V_8 * V_9 = F_25 ( V_15 -> V_31 ) ;
if ( V_79 -> V_82 == F_48 ( V_82 , 4096 ) )
return 0 ;
if ( V_79 -> V_82 != 0 )
F_45 ( V_15 , V_89 ) ;
V_79 -> V_82 = F_48 ( V_82 , 4096 ) ;
V_79 -> V_80 = F_49 ( & V_9 -> V_2 , V_79 -> V_82 , & V_79 -> V_91 ,
V_26 ) ;
if ( ! V_79 -> V_80 ) {
V_79 -> V_82 = 0 ;
F_14 ( & V_9 -> V_2 , L_27 ,
( int ) V_79 -> V_82 ) ;
return - V_27 ;
}
F_50 ( V_15 -> V_31 , V_89 , V_79 -> V_91 ) ;
return 0 ;
}
static void F_51 ( struct V_92 * V_93 )
{
struct V_38 * V_39 = F_4 ( V_93 ,
struct V_38 ,
V_94 ) ;
struct V_14 * V_15 = V_39 -> V_95 ;
struct V_8 * V_9 = F_25 ( V_15 -> V_31 ) ;
if ( V_39 -> V_65 == V_96 ) {
F_52 ( & V_39 -> V_97 ) ;
return;
}
if ( V_39 -> V_98 )
V_39 -> V_98 ( V_39 -> V_99 , V_96 ) ;
F_53 ( & V_9 -> V_2 , L_28 , V_39 -> V_73 ) ;
V_39 -> V_65 = V_96 ;
if ( V_15 -> V_100 == V_66 )
F_54 ( & V_39 -> V_97 ,
F_55 ( V_101 ) ) ;
}
static void F_56 ( struct V_38 * V_39 )
{
F_57 ( & V_39 -> V_94 ) ;
}
static void F_58 ( struct V_92 * V_93 )
{
struct V_14 * V_15 = F_4 ( V_93 , struct V_14 ,
V_94 ) ;
int V_24 ;
if ( V_15 -> V_100 == V_96 )
F_52 ( & V_15 -> V_97 ) ;
else
V_15 -> V_100 = V_96 ;
for ( V_24 = 0 ; V_24 < V_15 -> V_81 ; V_24 ++ )
if ( ! F_59 ( V_24 , & V_15 -> V_102 ) )
F_56 ( & V_15 -> V_74 [ V_24 ] ) ;
for ( V_24 = 0 ; V_24 < V_103 ; V_24 ++ )
F_60 ( V_15 -> V_31 , V_24 , 0 ) ;
}
static void F_61 ( void * V_104 , enum V_105 V_106 )
{
struct V_14 * V_15 = V_104 ;
switch ( V_106 ) {
case V_107 :
F_54 ( & V_15 -> V_97 , 0 ) ;
break;
case V_108 :
F_57 ( & V_15 -> V_94 ) ;
break;
default:
F_62 () ;
}
}
static void F_63 ( struct V_92 * V_93 )
{
struct V_14 * V_15 = F_4 ( V_93 , struct V_14 ,
V_97 . V_93 ) ;
struct V_109 * V_31 = V_15 -> V_31 ;
struct V_8 * V_9 = F_25 ( V_31 ) ;
T_7 V_110 ;
int V_11 , V_24 ;
for ( V_24 = 0 ; V_24 < F_41 ( V_31 ) ; V_24 ++ ) {
V_11 = F_64 ( V_31 , V_111 + ( V_24 * 2 ) ,
F_65 ( V_31 , V_24 ) >> 32 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_29 ,
( T_7 ) ( F_65 ( V_31 , V_24 ) >> 32 ) ,
V_111 + ( V_24 * 2 ) ) ;
goto V_72;
}
V_11 = F_64 ( V_31 , V_112 + ( V_24 * 2 ) ,
( T_7 ) F_65 ( V_31 , V_24 ) ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_29 ,
( T_7 ) F_65 ( V_31 , V_24 ) ,
V_112 + ( V_24 * 2 ) ) ;
goto V_72;
}
}
V_11 = F_64 ( V_31 , V_113 , F_41 ( V_31 ) ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_30 ,
F_41 ( V_31 ) , V_113 ) ;
goto V_72;
}
V_11 = F_64 ( V_31 , V_114 , V_15 -> V_81 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_30 ,
V_15 -> V_81 , V_114 ) ;
goto V_72;
}
V_11 = F_64 ( V_31 , V_115 , V_116 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_30 ,
V_116 , V_115 ) ;
goto V_72;
}
V_11 = F_66 ( V_31 , V_115 , & V_110 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_31 , V_115 ) ;
goto V_72;
}
if ( V_110 != V_116 )
goto V_72;
F_67 ( & V_9 -> V_2 , L_32 , V_110 ) ;
V_11 = F_66 ( V_31 , V_114 , & V_110 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_31 , V_114 ) ;
goto V_72;
}
if ( V_110 != V_15 -> V_81 )
goto V_72;
F_67 ( & V_9 -> V_2 , L_33 , V_110 ) ;
V_11 = F_66 ( V_31 , V_113 , & V_110 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_31 , V_113 ) ;
goto V_72;
}
if ( V_110 != F_41 ( V_31 ) )
goto V_72;
F_67 ( & V_9 -> V_2 , L_34 , V_110 ) ;
for ( V_24 = 0 ; V_24 < F_41 ( V_31 ) ; V_24 ++ ) {
T_8 V_117 ;
V_11 = F_66 ( V_31 , V_111 + ( V_24 * 2 ) , & V_110 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_31 ,
V_111 + ( V_24 * 2 ) ) ;
goto V_118;
}
V_117 = ( T_8 ) V_110 << 32 ;
V_11 = F_66 ( V_31 , V_112 + ( V_24 * 2 ) , & V_110 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_31 ,
V_112 + ( V_24 * 2 ) ) ;
goto V_118;
}
V_117 |= V_110 ;
F_67 ( & V_9 -> V_2 , L_35 , V_24 , V_117 ) ;
V_11 = F_47 ( V_15 , V_24 , V_117 ) ;
if ( V_11 )
goto V_118;
}
V_15 -> V_100 = V_66 ;
for ( V_24 = 0 ; V_24 < V_15 -> V_81 ; V_24 ++ ) {
struct V_38 * V_39 = & V_15 -> V_74 [ V_24 ] ;
F_40 ( V_15 , V_24 ) ;
if ( V_39 -> V_119 == V_66 )
F_54 ( & V_39 -> V_97 , 0 ) ;
}
return;
V_118:
for ( V_24 = 0 ; V_24 < F_41 ( V_31 ) ; V_24 ++ )
F_45 ( V_15 , V_24 ) ;
V_72:
if ( F_68 ( V_31 ) )
F_54 ( & V_15 -> V_97 ,
F_55 ( V_101 ) ) ;
}
static void F_69 ( struct V_92 * V_93 )
{
struct V_38 * V_39 = F_4 ( V_93 ,
struct V_38 ,
V_97 . V_93 ) ;
struct V_8 * V_9 = F_25 ( V_39 -> V_31 ) ;
struct V_14 * V_15 = V_39 -> V_95 ;
int V_11 , V_110 ;
F_43 ( V_15 -> V_100 != V_66 ) ;
V_11 = F_70 ( V_15 -> V_31 , V_120 , & V_110 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_36 , V_120 ) ;
return;
}
V_11 = F_64 ( V_15 -> V_31 , V_120 , V_110 | 1 << V_39 -> V_73 ) ;
if ( V_11 )
F_14 ( & V_9 -> V_2 , L_30 ,
V_110 | 1 << V_39 -> V_73 , V_120 ) ;
V_11 = F_66 ( V_15 -> V_31 , V_120 , & V_110 ) ;
if ( V_11 )
F_14 ( & V_9 -> V_2 , L_31 , V_120 ) ;
F_67 ( & V_9 -> V_2 , L_37 , V_110 ) ;
if ( 1 << V_39 -> V_73 & V_110 ) {
V_39 -> V_65 = V_66 ;
F_53 ( & V_9 -> V_2 , L_38 , V_39 -> V_73 ) ;
if ( V_39 -> V_98 )
V_39 -> V_98 ( V_39 -> V_99 , V_66 ) ;
} else if ( V_15 -> V_100 == V_66 )
F_54 ( & V_39 -> V_97 ,
F_55 ( V_101 ) ) ;
}
static int F_71 ( struct V_14 * V_15 ,
unsigned int V_73 )
{
struct V_38 * V_39 ;
unsigned int V_76 , V_121 ;
T_6 V_77 , V_78 ;
T_8 V_122 ;
V_78 = F_41 ( V_15 -> V_31 ) ;
V_77 = F_42 ( V_15 -> V_31 , V_73 ) ;
V_39 = & V_15 -> V_74 [ V_73 ] ;
V_39 -> V_73 = V_73 ;
V_39 -> V_95 = V_15 ;
V_39 -> V_31 = V_15 -> V_31 ;
V_39 -> V_65 = V_96 ;
V_39 -> V_119 = V_96 ;
V_39 -> V_98 = NULL ;
if ( V_15 -> V_81 % V_78 && V_77 < V_15 -> V_81 % V_78 )
V_76 = V_15 -> V_81 / V_78 + 1 ;
else
V_76 = V_15 -> V_81 / V_78 ;
V_121 = ( unsigned int ) F_65 ( V_39 -> V_31 , V_77 ) / V_76 ;
V_122 = V_73 / V_78 * V_121 ;
V_39 -> V_62 = F_72 ( V_15 -> V_31 , V_77 ) + V_122 ;
if ( ! V_39 -> V_62 )
return - V_12 ;
V_39 -> V_123 = F_73 ( V_39 -> V_31 , V_77 ) + V_122 ;
if ( ! V_39 -> V_123 )
return - V_12 ;
V_121 -= sizeof( struct V_83 ) ;
V_39 -> V_124 = V_39 -> V_62 + V_121 ;
V_39 -> V_125 = F_44 ( V_86 , V_121 / 2 ) ;
V_39 -> V_64 = V_121 / V_39 -> V_125 ;
if ( F_74 ( V_15 -> V_31 ) ) {
char V_126 [ 4 ] ;
snprintf ( V_126 , 4 , L_39 , V_73 ) ;
V_39 -> V_127 = F_75 ( V_126 ,
F_74 ( V_15 -> V_31 ) ) ;
V_39 -> V_128 = F_76 ( L_40 , V_129 ,
V_39 -> V_127 , V_39 ,
& V_130 ) ;
}
F_77 ( & V_39 -> V_97 , F_69 ) ;
F_78 ( & V_39 -> V_94 , F_51 ) ;
F_79 ( & V_39 -> V_131 ) ;
F_79 ( & V_39 -> V_132 ) ;
F_79 ( & V_39 -> V_133 ) ;
F_80 ( & V_39 -> V_134 ) ;
F_80 ( & V_39 -> V_135 ) ;
F_80 ( & V_39 -> V_136 ) ;
return 0 ;
}
int F_81 ( struct V_8 * V_9 )
{
struct V_14 * V_15 ;
int V_11 , V_24 ;
V_15 = F_23 ( sizeof( struct V_14 ) , V_26 ) ;
if ( ! V_15 )
return - V_27 ;
V_15 -> V_31 = F_82 ( V_9 , V_15 ) ;
if ( ! V_15 -> V_31 ) {
V_11 = - V_137 ;
goto V_28;
}
V_15 -> V_79 = F_83 ( F_41 ( V_15 -> V_31 ) , sizeof( struct V_90 ) ,
V_26 ) ;
if ( ! V_15 -> V_79 ) {
V_11 = - V_27 ;
goto V_138;
}
if ( V_139 )
V_15 -> V_81 = F_44 ( F_84 ( V_15 -> V_31 ) , V_139 ) ;
else
V_15 -> V_81 = F_44 ( F_84 ( V_15 -> V_31 ) , F_41 ( V_15 -> V_31 ) ) ;
V_15 -> V_74 = F_83 ( V_15 -> V_81 , sizeof( struct V_38 ) ,
V_26 ) ;
if ( ! V_15 -> V_74 ) {
V_11 = - V_27 ;
goto V_140;
}
V_15 -> V_102 = ( ( T_8 ) 1 << V_15 -> V_81 ) - 1 ;
for ( V_24 = 0 ; V_24 < V_15 -> V_81 ; V_24 ++ ) {
V_11 = F_71 ( V_15 , V_24 ) ;
if ( V_11 )
goto V_141;
}
F_77 ( & V_15 -> V_97 , F_63 ) ;
F_78 ( & V_15 -> V_94 , F_58 ) ;
V_11 = F_85 ( V_15 -> V_31 ,
F_61 ) ;
if ( V_11 )
goto V_141;
F_80 ( & V_15 -> V_32 ) ;
V_11 = F_8 ( V_15 ) ;
if ( V_11 )
goto V_142;
if ( F_68 ( V_15 -> V_31 ) )
F_54 ( & V_15 -> V_97 , 0 ) ;
return 0 ;
V_142:
F_86 ( V_15 -> V_31 ) ;
V_141:
F_19 ( V_15 -> V_74 ) ;
V_140:
F_19 ( V_15 -> V_79 ) ;
V_138:
F_87 ( V_15 -> V_31 ) ;
V_28:
F_19 ( V_15 ) ;
return V_11 ;
}
void F_88 ( void * V_95 )
{
struct V_14 * V_15 = V_95 ;
struct V_109 * V_31 = V_15 -> V_31 ;
int V_24 ;
V_15 -> V_100 = V_96 ;
for ( V_24 = 0 ; V_24 < V_15 -> V_81 ; V_24 ++ ) {
if ( ! F_59 ( V_24 , & V_15 -> V_102 ) )
F_89 ( & V_15 -> V_74 [ V_24 ] ) ;
F_90 ( V_15 -> V_74 [ V_24 ] . V_127 ) ;
}
F_12 ( V_15 ) ;
F_52 ( & V_15 -> V_97 ) ;
F_86 ( V_31 ) ;
for ( V_24 = 0 ; V_24 < F_41 ( V_31 ) ; V_24 ++ )
F_45 ( V_15 , V_24 ) ;
F_19 ( V_15 -> V_74 ) ;
F_19 ( V_15 -> V_79 ) ;
F_87 ( V_31 ) ;
F_19 ( V_15 ) ;
}
static void F_91 ( void * V_104 )
{
struct V_71 * V_18 = V_104 ;
struct V_38 * V_39 = V_18 -> V_39 ;
void * V_99 = V_18 -> V_99 ;
unsigned int V_143 = V_18 -> V_143 ;
struct V_88 * V_144 = V_18 -> V_145 ;
F_92 () ;
V_144 -> V_70 = 0 ;
F_93 ( V_18 -> V_146 , & V_39 -> V_124 -> V_18 ) ;
F_35 ( & V_39 -> V_132 , & V_18 -> V_18 , & V_39 -> V_135 ) ;
if ( V_39 -> V_147 && V_39 -> V_119 == V_66 )
V_39 -> V_147 ( V_39 , V_39 -> V_99 , V_99 , V_143 ) ;
}
static void F_94 ( struct V_71 * V_18 , void * V_87 )
{
void * V_40 = V_18 -> V_40 ;
T_3 V_143 = V_18 -> V_143 ;
memcpy ( V_40 , V_87 , V_143 ) ;
F_91 ( V_18 ) ;
}
static void F_95 ( struct V_71 * V_18 , void * V_87 ,
T_3 V_143 )
{
struct V_148 * V_149 ;
struct V_38 * V_39 = V_18 -> V_39 ;
struct V_150 * V_151 = V_39 -> V_150 ;
struct V_152 * V_1 ;
T_3 V_153 , V_154 ;
T_9 V_155 , V_156 ;
T_10 V_157 ;
void * V_40 = V_18 -> V_40 ;
unsigned long V_70 ;
V_18 -> V_143 = V_143 ;
if ( ! V_151 )
goto V_28;
if ( V_143 < V_158 )
goto V_138;
V_1 = V_151 -> V_1 ;
V_153 = ( T_3 ) V_87 & ~ V_159 ;
V_154 = ( T_3 ) V_40 & ~ V_159 ;
if ( ! F_96 ( V_1 , V_153 , V_154 , V_143 ) )
goto V_138;
V_156 = F_97 ( V_1 -> V_2 , V_40 , V_143 , V_160 ) ;
if ( F_98 ( V_1 -> V_2 , V_156 ) )
goto V_138;
V_155 = F_97 ( V_1 -> V_2 , V_87 , V_143 , V_161 ) ;
if ( F_98 ( V_1 -> V_2 , V_155 ) )
goto V_140;
V_70 = V_162 | V_163 |
V_164 ;
V_149 = V_1 -> V_165 ( V_151 , V_156 , V_155 , V_143 , V_70 ) ;
if ( ! V_149 )
goto V_141;
V_149 -> V_166 = F_91 ;
V_149 -> V_167 = V_18 ;
V_157 = F_99 ( V_149 ) ;
if ( F_100 ( V_157 ) )
goto V_141;
V_39 -> V_168 = V_157 ;
V_39 -> V_48 ++ ;
return;
V_141:
F_101 ( V_1 -> V_2 , V_155 , V_143 , V_161 ) ;
V_140:
F_101 ( V_1 -> V_2 , V_156 , V_143 , V_160 ) ;
V_138:
F_102 ( V_151 , V_39 -> V_168 ) ;
V_28:
F_94 ( V_18 , V_87 ) ;
V_39 -> V_47 ++ ;
}
static int F_103 ( struct V_38 * V_39 )
{
struct V_88 * V_144 ;
struct V_71 * V_18 ;
void * V_87 ;
V_87 = V_39 -> V_53 + V_39 -> V_85 * V_39 -> V_54 ;
V_144 = V_87 + V_39 -> V_85 - sizeof( struct V_88 ) ;
V_18 = F_38 ( & V_39 -> V_131 , & V_39 -> V_134 ) ;
if ( ! V_18 ) {
F_67 ( & F_25 ( V_39 -> V_31 ) -> V_2 ,
L_41 ,
V_144 -> V_169 , V_144 -> V_143 , V_144 -> V_70 ) ;
V_39 -> V_50 ++ ;
return - V_27 ;
}
if ( ! ( V_144 -> V_70 & V_170 ) ) {
F_35 ( & V_39 -> V_131 , & V_18 -> V_18 ,
& V_39 -> V_134 ) ;
V_39 -> V_49 ++ ;
return - V_171 ;
}
if ( V_144 -> V_169 != ( T_7 ) V_39 -> V_46 ) {
F_67 ( & F_25 ( V_39 -> V_31 ) -> V_2 ,
L_42 ,
V_39 -> V_73 , V_39 -> V_46 , V_144 -> V_169 ) ;
F_35 ( & V_39 -> V_131 , & V_18 -> V_18 ,
& V_39 -> V_134 ) ;
V_39 -> V_52 ++ ;
return - V_137 ;
}
if ( V_144 -> V_70 & V_172 ) {
F_56 ( V_39 ) ;
goto V_28;
}
F_67 ( & F_25 ( V_39 -> V_31 ) -> V_2 ,
L_43 ,
V_39 -> V_54 , V_144 -> V_169 , V_144 -> V_143 , V_18 -> V_143 ) ;
V_39 -> V_45 += V_144 -> V_143 ;
V_39 -> V_46 ++ ;
if ( V_144 -> V_143 > V_18 -> V_143 ) {
V_39 -> V_51 ++ ;
F_67 ( & F_25 ( V_39 -> V_31 ) -> V_2 ,
L_44 ,
V_144 -> V_143 , V_18 -> V_143 ) ;
goto V_28;
}
V_18 -> V_146 = V_39 -> V_54 ;
V_18 -> V_145 = V_144 ;
F_95 ( V_18 , V_87 , V_144 -> V_143 ) ;
V_72:
V_39 -> V_54 ++ ;
V_39 -> V_54 %= V_39 -> V_55 ;
return 0 ;
V_28:
F_35 ( & V_39 -> V_131 , & V_18 -> V_18 ,
& V_39 -> V_134 ) ;
F_92 () ;
V_144 -> V_70 = 0 ;
F_93 ( V_39 -> V_54 , & V_39 -> V_124 -> V_18 ) ;
goto V_72;
}
static void F_104 ( unsigned long V_104 )
{
struct V_38 * V_39 = (struct V_38 * ) V_104 ;
int V_11 , V_24 ;
for ( V_24 = 0 ; V_24 < V_39 -> V_55 ; V_24 ++ ) {
V_11 = F_103 ( V_39 ) ;
if ( V_11 )
break;
}
if ( V_39 -> V_150 )
F_105 ( V_39 -> V_150 ) ;
}
static void F_106 ( void * V_104 , int V_173 )
{
struct V_38 * V_39 = V_104 ;
F_67 ( & F_25 ( V_39 -> V_31 ) -> V_2 , L_45 ,
V_174 , V_173 ) ;
F_107 ( & V_39 -> V_175 ) ;
}
static void F_108 ( void * V_104 )
{
struct V_71 * V_18 = V_104 ;
struct V_38 * V_39 = V_18 -> V_39 ;
struct V_88 T_11 * V_144 = V_18 -> V_176 ;
F_92 () ;
F_93 ( V_18 -> V_70 | V_170 , & V_144 -> V_70 ) ;
F_109 ( V_39 -> V_31 , V_39 -> V_73 ) ;
if ( V_18 -> V_143 > 0 ) {
V_39 -> V_56 += V_18 -> V_143 ;
if ( V_39 -> V_177 )
V_39 -> V_177 ( V_39 , V_39 -> V_99 , V_18 -> V_99 ,
V_18 -> V_143 ) ;
}
F_35 ( & V_39 -> V_133 , & V_18 -> V_18 , & V_39 -> V_136 ) ;
}
static void F_110 ( struct V_71 * V_18 , void T_11 * V_87 )
{
F_111 ( V_87 , V_18 -> V_40 , V_18 -> V_143 ) ;
F_108 ( V_18 ) ;
}
static void F_112 ( struct V_38 * V_39 ,
struct V_71 * V_18 )
{
struct V_88 T_11 * V_144 ;
struct V_148 * V_149 ;
struct V_150 * V_151 = V_39 -> V_150 ;
struct V_152 * V_1 ;
T_3 V_178 , V_154 ;
T_9 V_155 , V_156 ;
T_10 V_157 ;
void T_11 * V_87 ;
T_3 V_143 = V_18 -> V_143 ;
void * V_40 = V_18 -> V_40 ;
unsigned long V_70 ;
V_87 = V_39 -> V_62 + V_39 -> V_125 * V_39 -> V_63 ;
V_144 = V_87 + V_39 -> V_125 - sizeof( struct V_88 ) ;
V_18 -> V_176 = V_144 ;
F_93 ( V_18 -> V_143 , & V_144 -> V_143 ) ;
F_93 ( ( T_7 ) V_39 -> V_57 , & V_144 -> V_169 ) ;
if ( ! V_151 )
goto V_28;
if ( V_143 < V_158 )
goto V_28;
V_1 = V_151 -> V_1 ;
V_156 = V_39 -> V_123 + V_39 -> V_125 * V_39 -> V_63 ;
V_154 = ( T_3 ) V_40 & ~ V_159 ;
V_178 = ( T_3 ) V_156 & ~ V_159 ;
if ( ! F_96 ( V_1 , V_154 , V_178 , V_143 ) )
goto V_28;
V_155 = F_97 ( V_1 -> V_2 , V_40 , V_143 , V_161 ) ;
if ( F_98 ( V_1 -> V_2 , V_155 ) )
goto V_28;
V_70 = V_163 | V_164 ;
V_149 = V_1 -> V_165 ( V_151 , V_156 , V_155 , V_143 , V_70 ) ;
if ( ! V_149 )
goto V_138;
V_149 -> V_166 = F_108 ;
V_149 -> V_167 = V_18 ;
V_157 = F_99 ( V_149 ) ;
if ( F_100 ( V_157 ) )
goto V_138;
F_105 ( V_151 ) ;
V_39 -> V_59 ++ ;
return;
V_138:
F_101 ( V_1 -> V_2 , V_155 , V_143 , V_161 ) ;
V_28:
F_110 ( V_18 , V_87 ) ;
V_39 -> V_58 ++ ;
}
static int F_113 ( struct V_38 * V_39 ,
struct V_71 * V_18 )
{
F_67 ( & F_25 ( V_39 -> V_31 ) -> V_2 , L_46 ,
V_39 -> V_57 , V_39 -> V_63 , V_18 -> V_143 , V_18 -> V_70 ,
V_18 -> V_40 ) ;
if ( V_39 -> V_63 == V_39 -> V_84 -> V_18 ) {
V_39 -> V_60 ++ ;
return - V_171 ;
}
if ( V_18 -> V_143 > V_39 -> V_125 - sizeof( struct V_88 ) ) {
if ( V_39 -> V_177 )
V_39 -> V_177 ( V_39 -> V_99 , V_39 , NULL , - V_137 ) ;
F_35 ( & V_39 -> V_133 , & V_18 -> V_18 ,
& V_39 -> V_136 ) ;
return 0 ;
}
F_112 ( V_39 , V_18 ) ;
V_39 -> V_63 ++ ;
V_39 -> V_63 %= V_39 -> V_64 ;
V_39 -> V_57 ++ ;
return 0 ;
}
static void F_114 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = F_25 ( V_39 -> V_31 ) ;
struct V_71 * V_18 ;
int V_24 , V_11 ;
if ( V_39 -> V_65 == V_96 )
return;
V_39 -> V_65 = V_96 ;
F_53 ( & V_9 -> V_2 , L_28 , V_39 -> V_73 ) ;
for ( V_24 = 0 ; V_24 < V_101 ; V_24 ++ ) {
V_18 = F_38 ( & V_39 -> V_133 , & V_39 -> V_136 ) ;
if ( V_18 )
break;
F_115 ( 100 ) ;
}
if ( ! V_18 )
return;
V_18 -> V_99 = NULL ;
V_18 -> V_40 = NULL ;
V_18 -> V_143 = 0 ;
V_18 -> V_70 = V_172 ;
V_11 = F_113 ( V_39 , V_18 ) ;
if ( V_11 )
F_14 ( & V_9 -> V_2 , L_47 ,
V_39 -> V_73 ) ;
}
struct V_38 *
F_116 ( void * V_104 , struct V_8 * V_9 ,
const struct V_179 * V_180 )
{
struct V_71 * V_18 ;
struct V_38 * V_39 ;
struct V_14 * V_15 ;
unsigned int V_181 ;
int V_11 , V_24 ;
V_15 = F_117 ( V_9 ) ;
if ( ! V_15 )
goto V_28;
V_181 = F_118 ( V_15 -> V_102 ) ;
if ( ! V_181 )
goto V_28;
V_181 -- ;
F_119 ( V_181 , & V_15 -> V_102 ) ;
V_39 = & V_15 -> V_74 [ V_181 ] ;
V_39 -> V_99 = V_104 ;
V_39 -> V_147 = V_180 -> V_147 ;
V_39 -> V_177 = V_180 -> V_177 ;
V_39 -> V_98 = V_180 -> V_98 ;
V_39 -> V_150 = F_120 ( V_182 ) ;
if ( ! V_39 -> V_150 )
F_53 ( & V_9 -> V_2 , L_48 ) ;
else
F_121 () ;
for ( V_24 = 0 ; V_24 < V_183 ; V_24 ++ ) {
V_18 = F_23 ( sizeof( struct V_71 ) , V_184 ) ;
if ( ! V_18 )
goto V_138;
V_18 -> V_39 = V_39 ;
F_35 ( & V_39 -> V_132 , & V_18 -> V_18 ,
& V_39 -> V_135 ) ;
}
for ( V_24 = 0 ; V_24 < V_183 ; V_24 ++ ) {
V_18 = F_23 ( sizeof( struct V_71 ) , V_184 ) ;
if ( ! V_18 )
goto V_140;
V_18 -> V_39 = V_39 ;
F_35 ( & V_39 -> V_133 , & V_18 -> V_18 ,
& V_39 -> V_136 ) ;
}
F_122 ( & V_39 -> V_175 , F_104 , ( unsigned long ) V_39 ) ;
V_11 = F_123 ( V_39 -> V_31 , V_181 , V_39 ,
F_106 ) ;
if ( V_11 )
goto V_141;
F_53 ( & V_9 -> V_2 , L_49 , V_39 -> V_73 ) ;
return V_39 ;
V_141:
F_124 ( & V_39 -> V_175 ) ;
V_140:
while ( ( V_18 = F_38 ( & V_39 -> V_133 , & V_39 -> V_136 ) ) )
F_19 ( V_18 ) ;
V_138:
while ( ( V_18 = F_38 ( & V_39 -> V_132 , & V_39 -> V_135 ) ) )
F_19 ( V_18 ) ;
F_125 ( V_181 , & V_15 -> V_102 ) ;
V_28:
return NULL ;
}
void F_89 ( struct V_38 * V_39 )
{
struct V_8 * V_9 ;
struct V_71 * V_18 ;
if ( ! V_39 )
return;
V_9 = F_25 ( V_39 -> V_31 ) ;
if ( V_39 -> V_150 ) {
struct V_150 * V_151 = V_39 -> V_150 ;
V_39 -> V_150 = NULL ;
F_102 ( V_151 , V_39 -> V_168 ) ;
F_126 ( V_151 ) ;
F_127 () ;
}
F_128 ( V_39 -> V_31 , V_39 -> V_73 ) ;
F_124 ( & V_39 -> V_175 ) ;
F_52 ( & V_39 -> V_97 ) ;
while ( ( V_18 = F_38 ( & V_39 -> V_132 , & V_39 -> V_135 ) ) )
F_19 ( V_18 ) ;
while ( ( V_18 = F_38 ( & V_39 -> V_131 , & V_39 -> V_134 ) ) ) {
F_129 ( & V_9 -> V_2 , L_50 ) ;
F_19 ( V_18 ) ;
}
while ( ( V_18 = F_38 ( & V_39 -> V_133 , & V_39 -> V_136 ) ) )
F_19 ( V_18 ) ;
F_125 ( V_39 -> V_73 , & V_39 -> V_95 -> V_102 ) ;
F_53 ( & V_9 -> V_2 , L_51 , V_39 -> V_73 ) ;
}
void * F_130 ( struct V_38 * V_39 , unsigned int * V_143 )
{
struct V_71 * V_18 ;
void * V_40 ;
if ( ! V_39 || V_39 -> V_119 == V_66 )
return NULL ;
V_18 = F_38 ( & V_39 -> V_131 , & V_39 -> V_134 ) ;
if ( ! V_18 )
return NULL ;
V_40 = V_18 -> V_99 ;
* V_143 = V_18 -> V_143 ;
F_35 ( & V_39 -> V_132 , & V_18 -> V_18 , & V_39 -> V_135 ) ;
return V_40 ;
}
int F_131 ( struct V_38 * V_39 , void * V_185 , void * V_104 ,
unsigned int V_143 )
{
struct V_71 * V_18 ;
if ( ! V_39 )
return - V_12 ;
V_18 = F_38 ( & V_39 -> V_132 , & V_39 -> V_135 ) ;
if ( ! V_18 )
return - V_27 ;
V_18 -> V_99 = V_185 ;
V_18 -> V_40 = V_104 ;
V_18 -> V_143 = V_143 ;
F_35 ( & V_39 -> V_131 , & V_18 -> V_18 , & V_39 -> V_134 ) ;
return 0 ;
}
int F_132 ( struct V_38 * V_39 , void * V_185 , void * V_104 ,
unsigned int V_143 )
{
struct V_71 * V_18 ;
int V_11 ;
if ( ! V_39 || V_39 -> V_65 != V_66 || ! V_143 )
return - V_12 ;
V_18 = F_38 ( & V_39 -> V_133 , & V_39 -> V_136 ) ;
if ( ! V_18 ) {
V_39 -> V_61 ++ ;
return - V_27 ;
}
V_18 -> V_99 = V_185 ;
V_18 -> V_40 = V_104 ;
V_18 -> V_143 = V_143 ;
V_18 -> V_70 = 0 ;
V_11 = F_113 ( V_39 , V_18 ) ;
if ( V_11 )
F_35 ( & V_39 -> V_133 , & V_18 -> V_18 ,
& V_39 -> V_136 ) ;
return V_11 ;
}
void F_133 ( struct V_38 * V_39 )
{
if ( ! V_39 )
return;
V_39 -> V_119 = V_66 ;
if ( V_39 -> V_95 -> V_100 == V_66 )
F_54 ( & V_39 -> V_97 , 0 ) ;
}
void F_134 ( struct V_38 * V_39 )
{
struct V_8 * V_9 ;
int V_11 , V_110 ;
if ( ! V_39 )
return;
V_9 = F_25 ( V_39 -> V_31 ) ;
V_39 -> V_119 = V_96 ;
V_11 = F_70 ( V_39 -> V_31 , V_120 , & V_110 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_36 , V_120 ) ;
return;
}
V_11 = F_64 ( V_39 -> V_31 , V_120 ,
V_110 & ~ ( 1 << V_39 -> V_73 ) ) ;
if ( V_11 )
F_14 ( & V_9 -> V_2 , L_30 ,
V_110 & ~ ( 1 << V_39 -> V_73 ) , V_120 ) ;
if ( V_39 -> V_65 == V_66 )
F_114 ( V_39 ) ;
else
F_52 ( & V_39 -> V_97 ) ;
}
bool F_135 ( struct V_38 * V_39 )
{
if ( ! V_39 )
return false ;
return V_39 -> V_65 == V_66 ;
}
unsigned char F_136 ( struct V_38 * V_39 )
{
if ( ! V_39 )
return 0 ;
return V_39 -> V_73 ;
}
unsigned int F_137 ( struct V_38 * V_39 )
{
unsigned int V_186 ;
if ( ! V_39 )
return 0 ;
if ( ! V_39 -> V_150 )
return V_39 -> V_125 - sizeof( struct V_88 ) ;
V_186 = V_39 -> V_125 - sizeof( struct V_88 ) ;
V_186 -= V_186 % ( 1 << V_39 -> V_150 -> V_1 -> V_187 ) ;
return V_186 ;
}
