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
V_43 = 600 ;
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
L_19 , ( V_39 -> V_60 == V_61 ) ?
L_20 : L_21 ) ;
if ( V_42 > V_43 )
V_42 = V_43 ;
V_41 = F_34 ( V_35 , V_36 , V_37 , V_40 , V_42 ) ;
F_19 ( V_40 ) ;
return V_41 ;
}
static void F_35 ( T_5 * V_62 , struct V_63 * V_18 ,
struct V_63 * V_64 )
{
unsigned long V_65 ;
F_36 ( V_62 , V_65 ) ;
F_27 ( V_18 , V_64 ) ;
F_37 ( V_62 , V_65 ) ;
}
static struct V_66 * F_38 ( T_5 * V_62 ,
struct V_63 * V_64 )
{
struct V_66 * V_18 ;
unsigned long V_65 ;
F_36 ( V_62 , V_65 ) ;
if ( F_9 ( V_64 ) ) {
V_18 = NULL ;
goto V_67;
}
V_18 = F_39 ( V_64 , struct V_66 , V_18 ) ;
F_15 ( & V_18 -> V_18 ) ;
V_67:
F_37 ( V_62 , V_65 ) ;
return V_18 ;
}
static void F_40 ( struct V_14 * V_15 ,
unsigned int V_68 )
{
struct V_38 * V_39 = & V_15 -> V_69 [ V_68 ] ;
unsigned int V_70 , V_71 ;
T_6 V_72 = F_41 ( V_68 ) ;
unsigned int V_24 ;
F_42 ( V_15 -> V_73 [ V_72 ] . V_74 == NULL ) ;
if ( V_15 -> V_75 % V_76 && V_72 < V_15 -> V_75 % V_76 )
V_71 = V_15 -> V_75 / V_76 + 1 ;
else
V_71 = V_15 -> V_75 / V_76 ;
V_70 = ( unsigned int ) V_15 -> V_73 [ V_72 ] . V_77 / V_71 ;
V_39 -> V_78 = V_15 -> V_73 [ V_72 ] . V_74 +
( V_68 / V_76 * V_70 ) ;
V_70 -= sizeof( struct V_79 ) ;
V_39 -> V_51 = V_39 -> V_78 + 1 ;
V_39 -> V_80 = F_43 ( V_81 , V_70 / 2 ) ;
V_39 -> V_53 = V_70 / V_39 -> V_80 ;
V_39 -> V_52 = 0 ;
V_39 -> V_78 -> V_18 = V_39 -> V_53 - 1 ;
for ( V_24 = 0 ; V_24 < V_39 -> V_53 ; V_24 ++ ) {
void * V_82 = V_39 -> V_51 + V_39 -> V_80 * ( V_24 + 1 ) -
sizeof( struct V_83 ) ;
memset ( V_82 , 0 , sizeof( struct V_83 ) ) ;
}
V_39 -> V_46 = 0 ;
V_39 -> V_55 = 0 ;
V_39 -> V_58 = 0 ;
}
static void F_44 ( struct V_14 * V_15 , int V_84 )
{
struct V_85 * V_73 = & V_15 -> V_73 [ V_84 ] ;
struct V_8 * V_9 = F_25 ( V_15 -> V_31 ) ;
if ( ! V_73 -> V_74 )
return;
F_45 ( & V_9 -> V_2 , V_73 -> V_77 , V_73 -> V_74 , V_73 -> V_86 ) ;
V_73 -> V_74 = NULL ;
}
static int F_46 ( struct V_14 * V_15 , int V_84 , unsigned int V_77 )
{
struct V_85 * V_73 = & V_15 -> V_73 [ V_84 ] ;
struct V_8 * V_9 = F_25 ( V_15 -> V_31 ) ;
if ( V_73 -> V_77 == F_47 ( V_77 , 4096 ) )
return 0 ;
if ( V_73 -> V_77 != 0 )
F_44 ( V_15 , V_84 ) ;
V_73 -> V_77 = F_47 ( V_77 , 4096 ) ;
V_73 -> V_74 = F_48 ( & V_9 -> V_2 , V_73 -> V_77 , & V_73 -> V_86 ,
V_26 ) ;
if ( ! V_73 -> V_74 ) {
V_73 -> V_77 = 0 ;
F_14 ( & V_9 -> V_2 , L_22 ,
( int ) V_73 -> V_77 ) ;
return - V_27 ;
}
F_49 ( V_15 -> V_31 , V_84 , V_73 -> V_86 ) ;
return 0 ;
}
static void F_50 ( struct V_87 * V_88 )
{
struct V_38 * V_39 = F_4 ( V_88 ,
struct V_38 ,
V_89 ) ;
struct V_14 * V_15 = V_39 -> V_90 ;
struct V_8 * V_9 = F_25 ( V_15 -> V_31 ) ;
if ( V_39 -> V_60 == V_91 ) {
F_51 ( & V_39 -> V_92 ) ;
return;
}
if ( V_39 -> V_93 )
V_39 -> V_93 ( V_39 -> V_94 , V_91 ) ;
F_52 ( & V_9 -> V_2 , L_23 , V_39 -> V_68 ) ;
V_39 -> V_60 = V_91 ;
if ( V_15 -> V_95 == V_61 )
F_53 ( & V_39 -> V_92 ,
F_54 ( V_96 ) ) ;
}
static void F_55 ( struct V_38 * V_39 )
{
F_56 ( & V_39 -> V_89 ) ;
}
static void F_57 ( struct V_87 * V_88 )
{
struct V_14 * V_15 = F_4 ( V_88 , struct V_14 ,
V_89 ) ;
int V_24 ;
if ( V_15 -> V_95 == V_91 )
F_51 ( & V_15 -> V_92 ) ;
else
V_15 -> V_95 = V_91 ;
for ( V_24 = 0 ; V_24 < V_15 -> V_75 ; V_24 ++ )
if ( ! F_58 ( V_24 , & V_15 -> V_97 ) )
F_55 ( & V_15 -> V_69 [ V_24 ] ) ;
for ( V_24 = 0 ; V_24 < V_98 ; V_24 ++ )
F_59 ( V_15 -> V_31 , V_24 , 0 ) ;
}
static void F_60 ( void * V_99 , enum V_100 V_101 )
{
struct V_14 * V_15 = V_99 ;
switch ( V_101 ) {
case V_102 :
F_53 ( & V_15 -> V_92 , 0 ) ;
break;
case V_103 :
F_56 ( & V_15 -> V_89 ) ;
break;
default:
F_61 () ;
}
}
static void F_62 ( struct V_87 * V_88 )
{
struct V_14 * V_15 = F_4 ( V_88 , struct V_14 ,
V_92 . V_88 ) ;
struct V_104 * V_31 = V_15 -> V_31 ;
struct V_8 * V_9 = F_25 ( V_31 ) ;
T_7 V_105 ;
int V_11 , V_24 ;
for ( V_24 = 0 ; V_24 < V_76 ; V_24 ++ ) {
V_11 = F_63 ( V_31 , V_106 + ( V_24 * 2 ) ,
F_64 ( V_31 , V_24 ) >> 32 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_24 ,
( T_7 ) ( F_64 ( V_31 , V_24 ) >> 32 ) ,
V_106 + ( V_24 * 2 ) ) ;
goto V_67;
}
V_11 = F_63 ( V_31 , V_107 + ( V_24 * 2 ) ,
( T_7 ) F_64 ( V_31 , V_24 ) ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_24 ,
( T_7 ) F_64 ( V_31 , V_24 ) ,
V_107 + ( V_24 * 2 ) ) ;
goto V_67;
}
}
V_11 = F_63 ( V_31 , V_108 , V_76 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_25 ,
V_76 , V_108 ) ;
goto V_67;
}
V_11 = F_63 ( V_31 , V_109 , V_15 -> V_75 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_25 ,
V_15 -> V_75 , V_109 ) ;
goto V_67;
}
V_11 = F_63 ( V_31 , V_110 , V_111 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_25 ,
V_111 , V_110 ) ;
goto V_67;
}
V_11 = F_65 ( V_31 , V_110 , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_26 , V_110 ) ;
goto V_67;
}
if ( V_105 != V_111 )
goto V_67;
F_66 ( & V_9 -> V_2 , L_27 , V_105 ) ;
V_11 = F_65 ( V_31 , V_109 , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_26 , V_109 ) ;
goto V_67;
}
if ( V_105 != V_15 -> V_75 )
goto V_67;
F_66 ( & V_9 -> V_2 , L_28 , V_105 ) ;
V_11 = F_65 ( V_31 , V_108 , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_26 , V_108 ) ;
goto V_67;
}
if ( V_105 != V_76 )
goto V_67;
F_66 ( & V_9 -> V_2 , L_29 , V_105 ) ;
for ( V_24 = 0 ; V_24 < V_76 ; V_24 ++ ) {
T_8 V_112 ;
V_11 = F_65 ( V_31 , V_106 + ( V_24 * 2 ) , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_26 ,
V_106 + ( V_24 * 2 ) ) ;
goto V_113;
}
V_112 = ( T_8 ) V_105 << 32 ;
V_11 = F_65 ( V_31 , V_107 + ( V_24 * 2 ) , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_26 ,
V_107 + ( V_24 * 2 ) ) ;
goto V_113;
}
V_112 |= V_105 ;
F_66 ( & V_9 -> V_2 , L_30 , V_24 , V_112 ) ;
V_11 = F_46 ( V_15 , V_24 , V_112 ) ;
if ( V_11 )
goto V_113;
}
V_15 -> V_95 = V_61 ;
for ( V_24 = 0 ; V_24 < V_15 -> V_75 ; V_24 ++ ) {
struct V_38 * V_39 = & V_15 -> V_69 [ V_24 ] ;
F_40 ( V_15 , V_24 ) ;
if ( V_39 -> V_114 == V_61 )
F_53 ( & V_39 -> V_92 , 0 ) ;
}
return;
V_113:
for ( V_24 = 0 ; V_24 < V_76 ; V_24 ++ )
F_44 ( V_15 , V_24 ) ;
V_67:
if ( F_67 ( V_31 ) )
F_53 ( & V_15 -> V_92 ,
F_54 ( V_96 ) ) ;
}
static void F_68 ( struct V_87 * V_88 )
{
struct V_38 * V_39 = F_4 ( V_88 ,
struct V_38 ,
V_92 . V_88 ) ;
struct V_8 * V_9 = F_25 ( V_39 -> V_31 ) ;
struct V_14 * V_15 = V_39 -> V_90 ;
int V_11 , V_105 ;
F_42 ( V_15 -> V_95 != V_61 ) ;
V_11 = F_69 ( V_15 -> V_31 , V_115 , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_31 , V_115 ) ;
return;
}
V_11 = F_63 ( V_15 -> V_31 , V_115 , V_105 | 1 << V_39 -> V_68 ) ;
if ( V_11 )
F_14 ( & V_9 -> V_2 , L_25 ,
V_105 | 1 << V_39 -> V_68 , V_115 ) ;
V_11 = F_65 ( V_15 -> V_31 , V_115 , & V_105 ) ;
if ( V_11 )
F_14 ( & V_9 -> V_2 , L_26 , V_115 ) ;
F_66 ( & V_9 -> V_2 , L_32 , V_105 ) ;
if ( 1 << V_39 -> V_68 & V_105 ) {
V_39 -> V_60 = V_61 ;
F_52 ( & V_9 -> V_2 , L_33 , V_39 -> V_68 ) ;
if ( V_39 -> V_93 )
V_39 -> V_93 ( V_39 -> V_94 , V_61 ) ;
} else if ( V_15 -> V_95 == V_61 )
F_53 ( & V_39 -> V_92 ,
F_54 ( V_96 ) ) ;
}
static void F_70 ( struct V_14 * V_15 ,
unsigned int V_68 )
{
struct V_38 * V_39 ;
unsigned int V_71 , V_116 ;
T_6 V_72 = F_41 ( V_68 ) ;
V_39 = & V_15 -> V_69 [ V_68 ] ;
V_39 -> V_68 = V_68 ;
V_39 -> V_90 = V_15 ;
V_39 -> V_31 = V_15 -> V_31 ;
V_39 -> V_60 = V_91 ;
V_39 -> V_114 = V_91 ;
V_39 -> V_93 = NULL ;
if ( V_15 -> V_75 % V_76 && V_72 < V_15 -> V_75 % V_76 )
V_71 = V_15 -> V_75 / V_76 + 1 ;
else
V_71 = V_15 -> V_75 / V_76 ;
V_116 = ( unsigned int ) F_64 ( V_39 -> V_31 , V_72 ) / V_71 ;
V_39 -> V_117 = F_71 ( V_15 -> V_31 , V_72 ) +
( V_68 / V_76 * V_116 ) ;
V_116 -= sizeof( struct V_79 ) ;
V_39 -> V_57 = V_39 -> V_117 + 1 ;
V_39 -> V_118 = F_43 ( V_81 , V_116 / 2 ) ;
V_39 -> V_59 = V_116 / V_39 -> V_118 ;
if ( V_15 -> V_119 ) {
char V_120 [ 4 ] ;
snprintf ( V_120 , 4 , L_34 , V_68 ) ;
V_39 -> V_119 = F_72 ( V_120 ,
V_15 -> V_119 ) ;
V_39 -> V_121 = F_73 ( L_35 , V_122 ,
V_39 -> V_119 , V_39 ,
& V_123 ) ;
}
F_74 ( & V_39 -> V_92 , F_68 ) ;
F_75 ( & V_39 -> V_89 , F_50 ) ;
F_76 ( & V_39 -> V_124 ) ;
F_76 ( & V_39 -> V_125 ) ;
F_76 ( & V_39 -> V_126 ) ;
F_77 ( & V_39 -> V_127 ) ;
F_77 ( & V_39 -> V_128 ) ;
F_77 ( & V_39 -> V_129 ) ;
}
int F_78 ( struct V_8 * V_9 )
{
struct V_14 * V_15 ;
int V_11 , V_24 ;
V_15 = F_23 ( sizeof( struct V_14 ) , V_26 ) ;
if ( ! V_15 )
return - V_27 ;
if ( F_79 () )
V_15 -> V_119 = F_72 ( V_130 , NULL ) ;
else
V_15 -> V_119 = NULL ;
V_15 -> V_31 = F_80 ( V_9 , V_15 ) ;
if ( ! V_15 -> V_31 ) {
V_11 = - V_131 ;
goto V_28;
}
V_15 -> V_75 = F_43 ( V_15 -> V_31 -> V_132 , V_133 ) ;
V_15 -> V_69 = F_81 ( V_15 -> V_75 , sizeof( struct V_38 ) ,
V_26 ) ;
if ( ! V_15 -> V_69 ) {
V_11 = - V_27 ;
goto V_134;
}
V_15 -> V_97 = ( ( T_8 ) 1 << V_15 -> V_75 ) - 1 ;
for ( V_24 = 0 ; V_24 < V_15 -> V_75 ; V_24 ++ )
F_70 ( V_15 , V_24 ) ;
F_74 ( & V_15 -> V_92 , F_62 ) ;
F_75 ( & V_15 -> V_89 , F_57 ) ;
V_11 = F_82 ( V_15 -> V_31 ,
F_60 ) ;
if ( V_11 )
goto V_135;
F_77 ( & V_15 -> V_32 ) ;
V_11 = F_8 ( V_15 ) ;
if ( V_11 )
goto V_136;
if ( F_67 ( V_15 -> V_31 ) )
F_53 ( & V_15 -> V_92 , 0 ) ;
return 0 ;
V_136:
F_83 ( V_15 -> V_31 ) ;
V_135:
F_19 ( V_15 -> V_69 ) ;
V_134:
F_84 ( V_15 -> V_31 ) ;
V_28:
F_85 ( V_15 -> V_119 ) ;
F_19 ( V_15 ) ;
return V_11 ;
}
void F_86 ( void * V_90 )
{
struct V_14 * V_15 = V_90 ;
struct V_8 * V_9 ;
int V_24 ;
V_15 -> V_95 = V_91 ;
for ( V_24 = 0 ; V_24 < V_15 -> V_75 ; V_24 ++ )
if ( ! F_58 ( V_24 , & V_15 -> V_97 ) )
F_87 ( & V_15 -> V_69 [ V_24 ] ) ;
F_12 ( V_15 ) ;
F_51 ( & V_15 -> V_92 ) ;
F_85 ( V_15 -> V_119 ) ;
F_83 ( V_15 -> V_31 ) ;
V_9 = F_25 ( V_15 -> V_31 ) ;
for ( V_24 = 0 ; V_24 < V_76 ; V_24 ++ )
F_44 ( V_15 , V_24 ) ;
F_19 ( V_15 -> V_69 ) ;
F_84 ( V_15 -> V_31 ) ;
F_19 ( V_15 ) ;
}
static void F_88 ( struct V_38 * V_39 ,
struct V_66 * V_18 , void * V_82 )
{
void * V_94 = V_18 -> V_94 ;
unsigned int V_137 = V_18 -> V_137 ;
memcpy ( V_18 -> V_40 , V_82 , V_18 -> V_137 ) ;
F_35 ( & V_39 -> V_125 , & V_18 -> V_18 , & V_39 -> V_128 ) ;
if ( V_39 -> V_138 && V_39 -> V_114 == V_61 )
V_39 -> V_138 ( V_39 , V_39 -> V_94 , V_94 , V_137 ) ;
}
static int F_89 ( struct V_38 * V_39 )
{
struct V_83 * V_139 ;
struct V_66 * V_18 ;
void * V_82 ;
V_82 = V_39 -> V_51 + V_39 -> V_80 * V_39 -> V_52 ;
V_139 = V_82 + V_39 -> V_80 - sizeof( struct V_83 ) ;
V_18 = F_38 ( & V_39 -> V_124 , & V_39 -> V_127 ) ;
if ( ! V_18 ) {
F_66 ( & F_25 ( V_39 -> V_31 ) -> V_2 ,
L_36 ,
V_139 -> V_140 , V_139 -> V_137 , V_139 -> V_65 ) ;
V_39 -> V_48 ++ ;
return - V_27 ;
}
if ( ! ( V_139 -> V_65 & V_141 ) ) {
F_35 ( & V_39 -> V_124 , & V_18 -> V_18 ,
& V_39 -> V_127 ) ;
V_39 -> V_47 ++ ;
return - V_142 ;
}
if ( V_139 -> V_140 != ( T_7 ) V_39 -> V_46 ) {
F_66 ( & F_25 ( V_39 -> V_31 ) -> V_2 ,
L_37 ,
V_39 -> V_68 , V_39 -> V_46 , V_139 -> V_140 ) ;
F_35 ( & V_39 -> V_124 , & V_18 -> V_18 ,
& V_39 -> V_127 ) ;
V_39 -> V_50 ++ ;
return - V_131 ;
}
if ( V_139 -> V_65 & V_143 ) {
F_55 ( V_39 ) ;
F_35 ( & V_39 -> V_124 , & V_18 -> V_18 ,
& V_39 -> V_127 ) ;
goto V_67;
}
F_66 ( & F_25 ( V_39 -> V_31 ) -> V_2 ,
L_38 ,
V_39 -> V_52 , V_139 -> V_140 , V_139 -> V_137 , V_18 -> V_137 ) ;
if ( V_139 -> V_137 <= V_18 -> V_137 ) {
V_18 -> V_137 = V_139 -> V_137 ;
F_88 ( V_39 , V_18 , V_82 ) ;
} else {
F_35 ( & V_39 -> V_124 , & V_18 -> V_18 ,
& V_39 -> V_127 ) ;
V_39 -> V_49 ++ ;
F_66 ( & F_25 ( V_39 -> V_31 ) -> V_2 ,
L_39 ,
V_139 -> V_137 , V_18 -> V_137 ) ;
}
V_39 -> V_45 += V_139 -> V_137 ;
V_39 -> V_46 ++ ;
V_67:
F_90 () ;
V_139 -> V_65 = 0 ;
F_91 ( V_39 -> V_52 , & V_39 -> V_117 -> V_18 ) ;
V_39 -> V_52 ++ ;
V_39 -> V_52 %= V_39 -> V_53 ;
return 0 ;
}
static void F_92 ( unsigned long V_99 )
{
struct V_38 * V_39 = (struct V_38 * ) V_99 ;
int V_11 , V_24 ;
for ( V_24 = 0 ; V_24 < V_39 -> V_53 ; V_24 ++ ) {
V_11 = F_89 ( V_39 ) ;
if ( V_11 )
break;
}
}
static void F_93 ( void * V_99 , int V_144 )
{
struct V_38 * V_39 = V_99 ;
F_66 ( & F_25 ( V_39 -> V_31 ) -> V_2 , L_40 ,
V_145 , V_144 ) ;
F_94 ( & V_39 -> V_146 ) ;
}
static void F_95 ( struct V_38 * V_39 ,
struct V_66 * V_18 ,
void T_9 * V_82 )
{
struct V_83 T_9 * V_139 ;
F_96 ( V_82 , V_18 -> V_40 , V_18 -> V_137 ) ;
V_139 = V_82 + V_39 -> V_118 - sizeof( struct V_83 ) ;
F_91 ( V_18 -> V_137 , & V_139 -> V_137 ) ;
F_91 ( ( T_7 ) V_39 -> V_55 , & V_139 -> V_140 ) ;
F_90 () ;
F_91 ( V_18 -> V_65 | V_141 , & V_139 -> V_65 ) ;
F_97 ( V_39 -> V_31 , V_39 -> V_68 ) ;
if ( V_18 -> V_137 > 0 ) {
V_39 -> V_54 += V_18 -> V_137 ;
if ( V_39 -> V_147 )
V_39 -> V_147 ( V_39 , V_39 -> V_94 , V_18 -> V_94 ,
V_18 -> V_137 ) ;
}
F_35 ( & V_39 -> V_126 , & V_18 -> V_18 , & V_39 -> V_129 ) ;
}
static int F_98 ( struct V_38 * V_39 ,
struct V_66 * V_18 )
{
void T_9 * V_82 ;
V_82 = V_39 -> V_57 + V_39 -> V_118 * V_39 -> V_58 ;
F_66 ( & F_25 ( V_39 -> V_31 ) -> V_2 , L_41 ,
V_39 -> V_55 , V_82 , V_39 -> V_58 , V_18 -> V_137 , V_18 -> V_65 ,
V_18 -> V_40 ) ;
if ( V_39 -> V_58 == V_39 -> V_78 -> V_18 ) {
V_39 -> V_56 ++ ;
return - V_142 ;
}
if ( V_18 -> V_137 > V_39 -> V_118 - sizeof( struct V_83 ) ) {
if ( V_39 -> V_147 )
V_39 -> V_147 ( V_39 -> V_94 , V_39 , NULL , - V_131 ) ;
F_35 ( & V_39 -> V_126 , & V_18 -> V_18 ,
& V_39 -> V_129 ) ;
return 0 ;
}
F_95 ( V_39 , V_18 , V_82 ) ;
V_39 -> V_58 ++ ;
V_39 -> V_58 %= V_39 -> V_59 ;
V_39 -> V_55 ++ ;
return 0 ;
}
static void F_99 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = F_25 ( V_39 -> V_31 ) ;
struct V_66 * V_18 ;
int V_24 , V_11 ;
if ( V_39 -> V_60 == V_91 )
return;
V_39 -> V_60 = V_91 ;
F_52 ( & V_9 -> V_2 , L_23 , V_39 -> V_68 ) ;
for ( V_24 = 0 ; V_24 < V_96 ; V_24 ++ ) {
V_18 = F_38 ( & V_39 -> V_126 , & V_39 -> V_129 ) ;
if ( V_18 )
break;
F_100 ( 100 ) ;
}
if ( ! V_18 )
return;
V_18 -> V_94 = NULL ;
V_18 -> V_40 = NULL ;
V_18 -> V_137 = 0 ;
V_18 -> V_65 = V_143 ;
V_11 = F_98 ( V_39 , V_18 ) ;
if ( V_11 )
F_14 ( & V_9 -> V_2 , L_42 ,
V_39 -> V_68 ) ;
}
struct V_38 *
F_101 ( void * V_99 , struct V_8 * V_9 ,
const struct V_148 * V_149 )
{
struct V_66 * V_18 ;
struct V_38 * V_39 ;
struct V_14 * V_15 ;
unsigned int V_150 ;
int V_11 , V_24 ;
V_15 = F_102 ( V_9 ) ;
if ( ! V_15 )
goto V_28;
V_150 = F_103 ( V_15 -> V_97 ) ;
if ( ! V_150 )
goto V_28;
V_150 -- ;
F_104 ( V_150 , & V_15 -> V_97 ) ;
V_39 = & V_15 -> V_69 [ V_150 ] ;
V_39 -> V_94 = V_99 ;
V_39 -> V_138 = V_149 -> V_138 ;
V_39 -> V_147 = V_149 -> V_147 ;
V_39 -> V_93 = V_149 -> V_93 ;
for ( V_24 = 0 ; V_24 < V_151 ; V_24 ++ ) {
V_18 = F_23 ( sizeof( struct V_66 ) , V_152 ) ;
if ( ! V_18 )
goto V_134;
F_35 ( & V_39 -> V_125 , & V_18 -> V_18 ,
& V_39 -> V_128 ) ;
}
for ( V_24 = 0 ; V_24 < V_151 ; V_24 ++ ) {
V_18 = F_23 ( sizeof( struct V_66 ) , V_152 ) ;
if ( ! V_18 )
goto V_135;
F_35 ( & V_39 -> V_126 , & V_18 -> V_18 ,
& V_39 -> V_129 ) ;
}
F_105 ( & V_39 -> V_146 , F_92 , ( unsigned long ) V_39 ) ;
V_11 = F_106 ( V_39 -> V_31 , V_150 , V_39 ,
F_93 ) ;
if ( V_11 )
goto V_136;
F_52 ( & V_9 -> V_2 , L_43 , V_39 -> V_68 ) ;
return V_39 ;
V_136:
F_107 ( & V_39 -> V_146 ) ;
V_135:
while ( ( V_18 = F_38 ( & V_39 -> V_126 , & V_39 -> V_129 ) ) )
F_19 ( V_18 ) ;
V_134:
while ( ( V_18 = F_38 ( & V_39 -> V_125 , & V_39 -> V_128 ) ) )
F_19 ( V_18 ) ;
F_108 ( V_150 , & V_15 -> V_97 ) ;
V_28:
return NULL ;
}
void F_87 ( struct V_38 * V_39 )
{
struct V_8 * V_9 ;
struct V_66 * V_18 ;
if ( ! V_39 )
return;
V_9 = F_25 ( V_39 -> V_31 ) ;
F_51 ( & V_39 -> V_92 ) ;
F_109 ( V_39 -> V_31 , V_39 -> V_68 ) ;
F_107 ( & V_39 -> V_146 ) ;
while ( ( V_18 = F_38 ( & V_39 -> V_125 , & V_39 -> V_128 ) ) )
F_19 ( V_18 ) ;
while ( ( V_18 = F_38 ( & V_39 -> V_124 , & V_39 -> V_127 ) ) ) {
F_110 ( & V_9 -> V_2 , L_44 ) ;
F_19 ( V_18 ) ;
}
while ( ( V_18 = F_38 ( & V_39 -> V_126 , & V_39 -> V_129 ) ) )
F_19 ( V_18 ) ;
F_108 ( V_39 -> V_68 , & V_39 -> V_90 -> V_97 ) ;
F_52 ( & V_9 -> V_2 , L_45 , V_39 -> V_68 ) ;
}
void * F_111 ( struct V_38 * V_39 , unsigned int * V_137 )
{
struct V_66 * V_18 ;
void * V_40 ;
if ( ! V_39 || V_39 -> V_114 == V_61 )
return NULL ;
V_18 = F_38 ( & V_39 -> V_124 , & V_39 -> V_127 ) ;
if ( ! V_18 )
return NULL ;
V_40 = V_18 -> V_94 ;
* V_137 = V_18 -> V_137 ;
F_35 ( & V_39 -> V_125 , & V_18 -> V_18 , & V_39 -> V_128 ) ;
return V_40 ;
}
int F_112 ( struct V_38 * V_39 , void * V_153 , void * V_99 ,
unsigned int V_137 )
{
struct V_66 * V_18 ;
if ( ! V_39 )
return - V_12 ;
V_18 = F_38 ( & V_39 -> V_125 , & V_39 -> V_128 ) ;
if ( ! V_18 )
return - V_27 ;
V_18 -> V_94 = V_153 ;
V_18 -> V_40 = V_99 ;
V_18 -> V_137 = V_137 ;
F_35 ( & V_39 -> V_124 , & V_18 -> V_18 , & V_39 -> V_127 ) ;
return 0 ;
}
int F_113 ( struct V_38 * V_39 , void * V_153 , void * V_99 ,
unsigned int V_137 )
{
struct V_66 * V_18 ;
int V_11 ;
if ( ! V_39 || V_39 -> V_60 != V_61 || ! V_137 )
return - V_12 ;
V_18 = F_38 ( & V_39 -> V_126 , & V_39 -> V_129 ) ;
if ( ! V_18 )
return - V_27 ;
V_18 -> V_94 = V_153 ;
V_18 -> V_40 = V_99 ;
V_18 -> V_137 = V_137 ;
V_18 -> V_65 = 0 ;
V_11 = F_98 ( V_39 , V_18 ) ;
if ( V_11 )
F_35 ( & V_39 -> V_126 , & V_18 -> V_18 ,
& V_39 -> V_129 ) ;
return V_11 ;
}
void F_114 ( struct V_38 * V_39 )
{
if ( ! V_39 )
return;
V_39 -> V_114 = V_61 ;
if ( V_39 -> V_90 -> V_95 == V_61 )
F_53 ( & V_39 -> V_92 , 0 ) ;
}
void F_115 ( struct V_38 * V_39 )
{
struct V_8 * V_9 ;
int V_11 , V_105 ;
if ( ! V_39 )
return;
V_9 = F_25 ( V_39 -> V_31 ) ;
V_39 -> V_114 = V_91 ;
V_11 = F_69 ( V_39 -> V_31 , V_115 , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_31 , V_115 ) ;
return;
}
V_11 = F_63 ( V_39 -> V_31 , V_115 ,
V_105 & ~ ( 1 << V_39 -> V_68 ) ) ;
if ( V_11 )
F_14 ( & V_9 -> V_2 , L_25 ,
V_105 & ~ ( 1 << V_39 -> V_68 ) , V_115 ) ;
if ( V_39 -> V_60 == V_61 )
F_99 ( V_39 ) ;
else
F_51 ( & V_39 -> V_92 ) ;
}
bool F_116 ( struct V_38 * V_39 )
{
if ( ! V_39 )
return false ;
return V_39 -> V_60 == V_61 ;
}
unsigned char F_117 ( struct V_38 * V_39 )
{
if ( ! V_39 )
return 0 ;
return V_39 -> V_68 ;
}
unsigned int F_118 ( struct V_38 * V_39 )
{
if ( ! V_39 )
return 0 ;
return V_39 -> V_118 - sizeof( struct V_83 ) ;
}
