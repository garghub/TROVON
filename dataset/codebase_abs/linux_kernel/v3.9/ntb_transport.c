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
int V_11 ;
if ( F_9 ( & V_16 ) )
return - V_24 ;
F_21 (nt, &ntb_transport_list, entry) {
struct V_1 * V_2 ;
V_20 = F_23 ( sizeof( struct V_19 ) ,
V_25 ) ;
if ( ! V_20 ) {
V_11 = - V_26 ;
goto V_27;
}
V_2 = & V_20 -> V_2 ;
F_24 ( V_2 , L_2 , V_22 ) ;
V_2 -> V_28 = & V_17 ;
V_2 -> V_29 = F_18 ;
V_2 -> V_10 = & F_25 ( V_15 -> V_30 ) -> V_2 ;
V_11 = F_26 ( V_2 ) ;
if ( V_11 ) {
F_19 ( V_20 ) ;
goto V_27;
}
F_27 ( & V_20 -> V_18 , & V_15 -> V_31 ) ;
}
return 0 ;
V_27:
F_20 ( V_22 ) ;
return V_11 ;
}
int F_28 ( struct V_6 * V_4 )
{
V_4 -> V_7 . V_28 = & V_17 ;
if ( F_9 ( & V_16 ) )
return - V_24 ;
return F_29 ( & V_4 -> V_7 ) ;
}
void F_30 ( struct V_6 * V_4 )
{
F_31 ( & V_4 -> V_7 ) ;
}
static T_1 F_32 ( struct V_32 * V_33 , char T_2 * V_34 , T_3 V_35 ,
T_4 * V_36 )
{
struct V_37 * V_38 ;
char * V_39 ;
T_1 V_40 , V_41 , V_42 ;
V_42 = 600 ;
V_39 = F_33 ( V_42 , V_25 ) ;
if ( ! V_39 )
return - V_26 ;
V_38 = V_33 -> V_43 ;
V_41 = 0 ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_3 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_4 , V_38 -> V_44 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_5 , V_38 -> V_45 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_6 , V_38 -> V_46 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_7 , V_38 -> V_47 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_8 , V_38 -> V_48 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_9 , V_38 -> V_49 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_10 , V_38 -> V_50 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_11 , V_38 -> V_51 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_12 , V_38 -> V_52 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_13 , V_38 -> V_53 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_14 , V_38 -> V_54 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_15 , V_38 -> V_55 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_16 , V_38 -> V_56 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_17 , V_38 -> V_57 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_18 , V_38 -> V_58 ) ;
V_41 += snprintf ( V_39 + V_41 , V_42 - V_41 ,
L_19 , ( V_38 -> V_59 == V_60 ) ?
L_20 : L_21 ) ;
if ( V_41 > V_42 )
V_41 = V_42 ;
V_40 = F_34 ( V_34 , V_35 , V_36 , V_39 , V_41 ) ;
F_19 ( V_39 ) ;
return V_40 ;
}
static void F_35 ( T_5 * V_61 , struct V_62 * V_18 ,
struct V_62 * V_63 )
{
unsigned long V_64 ;
F_36 ( V_61 , V_64 ) ;
F_27 ( V_18 , V_63 ) ;
F_37 ( V_61 , V_64 ) ;
}
static struct V_65 * F_38 ( T_5 * V_61 ,
struct V_62 * V_63 )
{
struct V_65 * V_18 ;
unsigned long V_64 ;
F_36 ( V_61 , V_64 ) ;
if ( F_9 ( V_63 ) ) {
V_18 = NULL ;
goto V_66;
}
V_18 = F_39 ( V_63 , struct V_65 , V_18 ) ;
F_15 ( & V_18 -> V_18 ) ;
V_66:
F_37 ( V_61 , V_64 ) ;
return V_18 ;
}
static void F_40 ( struct V_14 * V_15 ,
unsigned int V_67 )
{
struct V_37 * V_38 = & V_15 -> V_68 [ V_67 ] ;
unsigned int V_69 , V_70 ;
T_6 V_71 = F_41 ( V_67 ) ;
unsigned int V_72 ;
F_42 ( V_15 -> V_73 [ V_71 ] . V_74 == NULL ) ;
if ( V_15 -> V_75 % V_76 && V_71 < V_15 -> V_75 % V_76 )
V_70 = V_15 -> V_75 / V_76 + 1 ;
else
V_70 = V_15 -> V_75 / V_76 ;
V_69 = ( unsigned int ) V_15 -> V_73 [ V_71 ] . V_77 / V_70 ;
V_38 -> V_78 = V_15 -> V_73 [ V_71 ] . V_74 +
( V_67 / V_76 * V_69 ) ;
V_69 -= sizeof( struct V_79 ) ;
V_38 -> V_50 = V_38 -> V_78 + sizeof( struct V_79 ) ;
V_38 -> V_80 = F_43 ( V_81 , V_69 ) ;
V_38 -> V_52 = V_69 / V_38 -> V_80 ;
V_38 -> V_51 = 0 ;
V_38 -> V_78 -> V_18 = V_38 -> V_52 ;
for ( V_72 = 0 ; V_72 < V_38 -> V_52 ; V_72 ++ ) {
void * V_82 = V_38 -> V_50 + V_38 -> V_80 * ( V_72 + 1 ) -
sizeof( struct V_83 ) ;
memset ( V_82 , 0 , sizeof( struct V_83 ) ) ;
}
V_38 -> V_45 = 0 ;
V_38 -> V_54 = 0 ;
}
static int F_44 ( struct V_14 * V_15 , int V_84 , unsigned int V_77 )
{
struct V_85 * V_73 = & V_15 -> V_73 [ V_84 ] ;
struct V_8 * V_9 = F_25 ( V_15 -> V_30 ) ;
V_73 -> V_77 = F_45 ( V_77 , 4096 ) ;
V_73 -> V_74 = F_46 ( & V_9 -> V_2 , V_73 -> V_77 , & V_73 -> V_86 ,
V_25 ) ;
if ( ! V_73 -> V_74 ) {
F_14 ( & V_9 -> V_2 , L_22 ,
( int ) V_73 -> V_77 ) ;
return - V_26 ;
}
F_47 ( V_15 -> V_30 , V_84 , V_73 -> V_86 ) ;
return 0 ;
}
static void F_48 ( struct V_87 * V_88 )
{
struct V_37 * V_38 = F_4 ( V_88 ,
struct V_37 ,
V_89 ) ;
struct V_14 * V_15 = V_38 -> V_90 ;
struct V_8 * V_9 = F_25 ( V_15 -> V_30 ) ;
if ( V_38 -> V_59 == V_91 ) {
F_49 ( & V_38 -> V_92 ) ;
return;
}
if ( V_38 -> V_93 )
V_38 -> V_93 ( V_38 -> V_94 , V_91 ) ;
F_50 ( & V_9 -> V_2 , L_23 , V_38 -> V_67 ) ;
V_38 -> V_59 = V_91 ;
if ( V_15 -> V_95 == V_60 )
F_51 ( & V_38 -> V_92 ,
F_52 ( V_96 ) ) ;
}
static void F_53 ( struct V_37 * V_38 )
{
F_54 ( & V_38 -> V_89 ) ;
}
static void F_55 ( struct V_87 * V_88 )
{
struct V_14 * V_15 = F_4 ( V_88 , struct V_14 ,
V_89 ) ;
int V_72 ;
if ( V_15 -> V_95 == V_91 )
F_49 ( & V_15 -> V_92 ) ;
else
V_15 -> V_95 = V_91 ;
for ( V_72 = 0 ; V_72 < V_15 -> V_75 ; V_72 ++ )
if ( ! F_56 ( V_72 , & V_15 -> V_97 ) )
F_53 ( & V_15 -> V_68 [ V_72 ] ) ;
for ( V_72 = 0 ; V_72 < V_98 ; V_72 ++ )
F_57 ( V_15 -> V_30 , V_72 , 0 ) ;
}
static void F_58 ( void * V_99 , enum V_100 V_101 )
{
struct V_14 * V_15 = V_99 ;
switch ( V_101 ) {
case V_102 :
F_51 ( & V_15 -> V_92 , 0 ) ;
break;
case V_103 :
F_54 ( & V_15 -> V_89 ) ;
break;
default:
F_59 () ;
}
}
static void F_60 ( struct V_87 * V_88 )
{
struct V_14 * V_15 = F_4 ( V_88 , struct V_14 ,
V_92 . V_88 ) ;
struct V_104 * V_30 = V_15 -> V_30 ;
struct V_8 * V_9 = F_25 ( V_30 ) ;
T_7 V_105 ;
int V_11 , V_72 ;
V_11 = F_61 ( V_30 , V_106 , V_107 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_24 ,
0 , V_106 ) ;
goto V_66;
}
V_11 = F_61 ( V_30 , V_108 , F_62 ( V_30 , 0 ) ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_24 ,
( T_7 ) F_62 ( V_30 , 0 ) , V_108 ) ;
goto V_66;
}
V_11 = F_61 ( V_30 , V_109 , F_62 ( V_30 , 1 ) ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_24 ,
( T_7 ) F_62 ( V_30 , 1 ) , V_109 ) ;
goto V_66;
}
V_11 = F_61 ( V_30 , V_110 , V_15 -> V_75 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_24 ,
V_15 -> V_75 , V_110 ) ;
goto V_66;
}
V_11 = F_63 ( V_15 -> V_30 , V_111 , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_25 , V_111 ) ;
goto V_66;
}
V_11 = F_61 ( V_30 , V_111 , V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_24 ,
V_105 , V_111 ) ;
goto V_66;
}
V_11 = F_64 ( V_30 , V_106 , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_26 , V_106 ) ;
goto V_66;
}
if ( V_105 != V_107 )
goto V_66;
F_65 ( & V_9 -> V_2 , L_27 , V_105 ) ;
V_11 = F_64 ( V_30 , V_110 , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_26 , V_110 ) ;
goto V_66;
}
if ( V_105 != V_15 -> V_75 )
goto V_66;
F_65 ( & V_9 -> V_2 , L_28 , V_105 ) ;
V_11 = F_64 ( V_30 , V_108 , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_26 , V_108 ) ;
goto V_66;
}
if ( ! V_105 )
goto V_66;
F_65 ( & V_9 -> V_2 , L_29 , V_105 ) ;
V_11 = F_44 ( V_15 , 0 , V_105 ) ;
if ( V_11 )
goto V_66;
V_11 = F_64 ( V_30 , V_109 , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_26 , V_109 ) ;
goto V_66;
}
if ( ! V_105 )
goto V_66;
F_65 ( & V_9 -> V_2 , L_30 , V_105 ) ;
V_11 = F_44 ( V_15 , 1 , V_105 ) ;
if ( V_11 )
goto V_66;
V_15 -> V_95 = V_60 ;
for ( V_72 = 0 ; V_72 < V_15 -> V_75 ; V_72 ++ ) {
struct V_37 * V_38 = & V_15 -> V_68 [ V_72 ] ;
F_40 ( V_15 , V_72 ) ;
if ( V_38 -> V_112 == V_60 )
F_51 ( & V_38 -> V_92 , 0 ) ;
}
return;
V_66:
if ( F_66 ( V_30 ) )
F_51 ( & V_15 -> V_92 ,
F_52 ( V_96 ) ) ;
}
static void F_67 ( struct V_87 * V_88 )
{
struct V_37 * V_38 = F_4 ( V_88 ,
struct V_37 ,
V_92 . V_88 ) ;
struct V_8 * V_9 = F_25 ( V_38 -> V_30 ) ;
struct V_14 * V_15 = V_38 -> V_90 ;
int V_11 , V_105 ;
F_42 ( V_15 -> V_95 != V_60 ) ;
V_11 = F_63 ( V_15 -> V_30 , V_111 , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_25 , V_111 ) ;
return;
}
V_11 = F_61 ( V_15 -> V_30 , V_111 , V_105 | 1 << V_38 -> V_67 ) ;
if ( V_11 )
F_14 ( & V_9 -> V_2 , L_24 ,
V_105 | 1 << V_38 -> V_67 , V_111 ) ;
V_11 = F_64 ( V_15 -> V_30 , V_111 , & V_105 ) ;
if ( V_11 )
F_14 ( & V_9 -> V_2 , L_26 , V_111 ) ;
F_65 ( & V_9 -> V_2 , L_31 , V_105 ) ;
if ( 1 << V_38 -> V_67 & V_105 ) {
V_38 -> V_59 = V_60 ;
F_50 ( & V_9 -> V_2 , L_32 , V_38 -> V_67 ) ;
if ( V_38 -> V_93 )
V_38 -> V_93 ( V_38 -> V_94 , V_60 ) ;
} else if ( V_15 -> V_95 == V_60 )
F_51 ( & V_38 -> V_92 ,
F_52 ( V_96 ) ) ;
}
static void F_68 ( struct V_14 * V_15 ,
unsigned int V_67 )
{
struct V_37 * V_38 ;
unsigned int V_70 , V_113 ;
T_6 V_71 = F_41 ( V_67 ) ;
V_38 = & V_15 -> V_68 [ V_67 ] ;
V_38 -> V_67 = V_67 ;
V_38 -> V_90 = V_15 ;
V_38 -> V_30 = V_15 -> V_30 ;
V_38 -> V_59 = V_91 ;
V_38 -> V_112 = V_91 ;
V_38 -> V_93 = NULL ;
if ( V_15 -> V_75 % V_76 && V_71 < V_15 -> V_75 % V_76 )
V_70 = V_15 -> V_75 / V_76 + 1 ;
else
V_70 = V_15 -> V_75 / V_76 ;
V_113 = ( unsigned int ) F_62 ( V_38 -> V_30 , V_71 ) / V_70 ;
V_38 -> V_114 = F_69 ( V_15 -> V_30 , V_71 ) +
( V_67 / V_76 * V_113 ) ;
V_113 -= sizeof( struct V_79 ) ;
V_38 -> V_56 = V_38 -> V_114 + sizeof( struct V_79 ) ;
V_38 -> V_115 = F_43 ( V_81 , V_113 ) ;
V_38 -> V_58 = V_113 / V_38 -> V_115 ;
V_38 -> V_57 = 0 ;
if ( V_15 -> V_116 ) {
char V_117 [ 4 ] ;
snprintf ( V_117 , 4 , L_33 , V_67 ) ;
V_38 -> V_116 = F_70 ( V_117 ,
V_15 -> V_116 ) ;
V_38 -> V_118 = F_71 ( L_34 , V_119 ,
V_38 -> V_116 , V_38 ,
& V_120 ) ;
}
F_72 ( & V_38 -> V_92 , F_67 ) ;
F_73 ( & V_38 -> V_89 , F_48 ) ;
F_74 ( & V_38 -> V_121 ) ;
F_74 ( & V_38 -> V_122 ) ;
F_74 ( & V_38 -> V_123 ) ;
F_75 ( & V_38 -> V_124 ) ;
F_75 ( & V_38 -> V_125 ) ;
F_75 ( & V_38 -> V_126 ) ;
}
int F_76 ( struct V_8 * V_9 )
{
struct V_14 * V_15 ;
int V_11 , V_72 ;
V_15 = F_23 ( sizeof( struct V_14 ) , V_25 ) ;
if ( ! V_15 )
return - V_26 ;
if ( F_77 () )
V_15 -> V_116 = F_70 ( V_127 , NULL ) ;
else
V_15 -> V_116 = NULL ;
V_15 -> V_30 = F_78 ( V_9 , V_15 ) ;
if ( ! V_15 -> V_30 ) {
V_11 = - V_128 ;
goto V_27;
}
V_15 -> V_75 = F_43 ( V_15 -> V_30 -> V_129 , V_130 ) ;
V_15 -> V_68 = F_79 ( V_15 -> V_75 , sizeof( struct V_37 ) ,
V_25 ) ;
if ( ! V_15 -> V_68 ) {
V_11 = - V_26 ;
goto V_131;
}
V_15 -> V_97 = ( ( V_132 ) 1 << V_15 -> V_75 ) - 1 ;
for ( V_72 = 0 ; V_72 < V_15 -> V_75 ; V_72 ++ )
F_68 ( V_15 , V_72 ) ;
F_72 ( & V_15 -> V_92 , F_60 ) ;
F_73 ( & V_15 -> V_89 , F_55 ) ;
V_11 = F_80 ( V_15 -> V_30 ,
F_58 ) ;
if ( V_11 )
goto V_133;
F_75 ( & V_15 -> V_31 ) ;
V_11 = F_8 ( V_15 ) ;
if ( V_11 )
goto V_134;
if ( F_66 ( V_15 -> V_30 ) )
F_51 ( & V_15 -> V_92 , 0 ) ;
return 0 ;
V_134:
F_81 ( V_15 -> V_30 ) ;
V_133:
F_19 ( V_15 -> V_68 ) ;
V_131:
F_82 ( V_15 -> V_30 ) ;
V_27:
F_83 ( V_15 -> V_116 ) ;
F_19 ( V_15 ) ;
return V_11 ;
}
void F_84 ( void * V_90 )
{
struct V_14 * V_15 = V_90 ;
struct V_8 * V_9 ;
int V_72 ;
V_15 -> V_95 = V_91 ;
for ( V_72 = 0 ; V_72 < V_15 -> V_75 ; V_72 ++ )
if ( ! F_56 ( V_72 , & V_15 -> V_97 ) )
F_85 ( & V_15 -> V_68 [ V_72 ] ) ;
F_12 ( V_15 ) ;
F_49 ( & V_15 -> V_92 ) ;
F_83 ( V_15 -> V_116 ) ;
F_81 ( V_15 -> V_30 ) ;
V_9 = F_25 ( V_15 -> V_30 ) ;
for ( V_72 = 0 ; V_72 < V_76 ; V_72 ++ )
if ( V_15 -> V_73 [ V_72 ] . V_74 )
F_86 ( & V_9 -> V_2 , V_15 -> V_73 [ V_72 ] . V_77 ,
V_15 -> V_73 [ V_72 ] . V_74 ,
V_15 -> V_73 [ V_72 ] . V_86 ) ;
F_19 ( V_15 -> V_68 ) ;
F_82 ( V_15 -> V_30 ) ;
F_19 ( V_15 ) ;
}
static void F_87 ( struct V_37 * V_38 ,
struct V_65 * V_18 , void * V_82 )
{
void * V_94 = V_18 -> V_94 ;
unsigned int V_135 = V_18 -> V_135 ;
memcpy ( V_18 -> V_39 , V_82 , V_18 -> V_135 ) ;
F_35 ( & V_38 -> V_122 , & V_18 -> V_18 , & V_38 -> V_125 ) ;
if ( V_38 -> V_136 && V_38 -> V_112 == V_60 )
V_38 -> V_136 ( V_38 , V_38 -> V_94 , V_94 , V_135 ) ;
}
static int F_88 ( struct V_37 * V_38 )
{
struct V_83 * V_137 ;
struct V_65 * V_18 ;
void * V_82 ;
V_82 = V_38 -> V_50 + V_38 -> V_80 * V_38 -> V_51 ;
V_137 = V_82 + V_38 -> V_80 - sizeof( struct V_83 ) ;
V_18 = F_38 ( & V_38 -> V_121 , & V_38 -> V_124 ) ;
if ( ! V_18 ) {
F_65 ( & F_25 ( V_38 -> V_30 ) -> V_2 ,
L_35 ,
V_137 -> V_138 , V_137 -> V_135 , V_137 -> V_64 ) ;
V_38 -> V_47 ++ ;
return - V_26 ;
}
if ( ! ( V_137 -> V_64 & V_139 ) ) {
F_35 ( & V_38 -> V_121 , & V_18 -> V_18 ,
& V_38 -> V_124 ) ;
V_38 -> V_46 ++ ;
return - V_140 ;
}
if ( V_137 -> V_138 != ( T_7 ) V_38 -> V_45 ) {
F_65 ( & F_25 ( V_38 -> V_30 ) -> V_2 ,
L_36 ,
V_38 -> V_67 , V_38 -> V_45 , V_137 -> V_138 ) ;
F_35 ( & V_38 -> V_121 , & V_18 -> V_18 ,
& V_38 -> V_124 ) ;
V_38 -> V_49 ++ ;
return - V_128 ;
}
if ( V_137 -> V_64 & V_141 ) {
F_53 ( V_38 ) ;
F_35 ( & V_38 -> V_121 , & V_18 -> V_18 ,
& V_38 -> V_124 ) ;
goto V_66;
}
F_65 ( & F_25 ( V_38 -> V_30 ) -> V_2 ,
L_37 ,
V_38 -> V_51 , V_137 -> V_138 , V_137 -> V_135 , V_18 -> V_135 ) ;
if ( V_137 -> V_135 <= V_18 -> V_135 ) {
V_18 -> V_135 = V_137 -> V_135 ;
F_87 ( V_38 , V_18 , V_82 ) ;
} else {
F_35 ( & V_38 -> V_121 , & V_18 -> V_18 ,
& V_38 -> V_124 ) ;
V_38 -> V_48 ++ ;
F_65 ( & F_25 ( V_38 -> V_30 ) -> V_2 ,
L_38 ,
V_137 -> V_135 , V_18 -> V_135 ) ;
}
V_38 -> V_44 += V_137 -> V_135 ;
V_38 -> V_45 ++ ;
V_66:
F_89 () ;
V_137 -> V_64 = 0 ;
F_90 ( V_38 -> V_51 , & V_38 -> V_114 -> V_18 ) ;
V_38 -> V_51 ++ ;
V_38 -> V_51 %= V_38 -> V_52 ;
return 0 ;
}
static void F_91 ( unsigned long V_99 )
{
struct V_37 * V_38 = (struct V_37 * ) V_99 ;
int V_11 ;
do {
V_11 = F_88 ( V_38 ) ;
} while ( ! V_11 );
}
static void F_92 ( void * V_99 , int V_142 )
{
struct V_37 * V_38 = V_99 ;
F_65 ( & F_25 ( V_38 -> V_30 ) -> V_2 , L_39 ,
V_143 , V_142 ) ;
F_93 ( & V_38 -> V_144 ) ;
}
static void F_94 ( struct V_37 * V_38 ,
struct V_65 * V_18 ,
void T_8 * V_82 )
{
struct V_83 T_8 * V_137 ;
F_95 ( V_82 , V_18 -> V_39 , V_18 -> V_135 ) ;
V_137 = V_82 + V_38 -> V_115 - sizeof( struct V_83 ) ;
F_90 ( V_18 -> V_135 , & V_137 -> V_135 ) ;
F_90 ( ( T_7 ) V_38 -> V_54 , & V_137 -> V_138 ) ;
F_89 () ;
F_90 ( V_18 -> V_64 | V_139 , & V_137 -> V_64 ) ;
F_96 ( V_38 -> V_30 , V_38 -> V_67 ) ;
if ( V_18 -> V_135 > 0 ) {
V_38 -> V_53 += V_18 -> V_135 ;
if ( V_38 -> V_145 )
V_38 -> V_145 ( V_38 , V_38 -> V_94 , V_18 -> V_94 ,
V_18 -> V_135 ) ;
}
F_35 ( & V_38 -> V_123 , & V_18 -> V_18 , & V_38 -> V_126 ) ;
}
static int F_97 ( struct V_37 * V_38 ,
struct V_65 * V_18 )
{
void T_8 * V_82 ;
V_82 = V_38 -> V_56 + V_38 -> V_115 * V_38 -> V_57 ;
F_65 ( & F_25 ( V_38 -> V_30 ) -> V_2 , L_40 ,
V_38 -> V_54 , V_82 , V_38 -> V_57 , V_18 -> V_135 , V_18 -> V_64 ,
V_18 -> V_39 ) ;
if ( V_38 -> V_57 == V_38 -> V_78 -> V_18 ) {
V_38 -> V_55 ++ ;
return - V_140 ;
}
if ( V_18 -> V_135 > V_38 -> V_115 - sizeof( struct V_83 ) ) {
if ( V_38 -> V_145 )
V_38 -> V_145 ( V_38 -> V_94 , V_38 , NULL , - V_128 ) ;
F_35 ( & V_38 -> V_123 , & V_18 -> V_18 ,
& V_38 -> V_126 ) ;
return 0 ;
}
F_94 ( V_38 , V_18 , V_82 ) ;
V_38 -> V_57 ++ ;
V_38 -> V_57 %= V_38 -> V_58 ;
V_38 -> V_54 ++ ;
return 0 ;
}
static void F_98 ( struct V_37 * V_38 )
{
struct V_8 * V_9 = F_25 ( V_38 -> V_30 ) ;
struct V_65 * V_18 ;
int V_72 , V_11 ;
if ( V_38 -> V_59 == V_91 )
return;
V_38 -> V_59 = V_91 ;
F_50 ( & V_9 -> V_2 , L_23 , V_38 -> V_67 ) ;
for ( V_72 = 0 ; V_72 < V_96 ; V_72 ++ ) {
V_18 = F_38 ( & V_38 -> V_123 , & V_38 -> V_126 ) ;
if ( V_18 )
break;
F_99 ( 100 ) ;
}
if ( ! V_18 )
return;
V_18 -> V_94 = NULL ;
V_18 -> V_39 = NULL ;
V_18 -> V_135 = 0 ;
V_18 -> V_64 = V_141 ;
V_11 = F_97 ( V_38 , V_18 ) ;
if ( V_11 )
F_14 ( & V_9 -> V_2 , L_41 ,
V_38 -> V_67 ) ;
}
struct V_37 *
F_100 ( void * V_99 , struct V_8 * V_9 ,
const struct V_146 * V_147 )
{
struct V_65 * V_18 ;
struct V_37 * V_38 ;
struct V_14 * V_15 ;
unsigned int V_148 ;
int V_11 , V_72 ;
V_15 = F_101 ( V_9 ) ;
if ( ! V_15 )
goto V_27;
V_148 = F_102 ( V_15 -> V_97 ) ;
if ( ! V_148 )
goto V_27;
V_148 -- ;
F_103 ( V_148 , & V_15 -> V_97 ) ;
V_38 = & V_15 -> V_68 [ V_148 ] ;
V_38 -> V_94 = V_99 ;
V_38 -> V_136 = V_147 -> V_136 ;
V_38 -> V_145 = V_147 -> V_145 ;
V_38 -> V_93 = V_147 -> V_93 ;
for ( V_72 = 0 ; V_72 < V_149 ; V_72 ++ ) {
V_18 = F_23 ( sizeof( struct V_65 ) , V_150 ) ;
if ( ! V_18 )
goto V_131;
F_35 ( & V_38 -> V_122 , & V_18 -> V_18 ,
& V_38 -> V_125 ) ;
}
for ( V_72 = 0 ; V_72 < V_149 ; V_72 ++ ) {
V_18 = F_23 ( sizeof( struct V_65 ) , V_150 ) ;
if ( ! V_18 )
goto V_133;
F_35 ( & V_38 -> V_123 , & V_18 -> V_18 ,
& V_38 -> V_126 ) ;
}
F_104 ( & V_38 -> V_144 , F_91 , ( unsigned long ) V_38 ) ;
V_11 = F_105 ( V_38 -> V_30 , V_148 , V_38 ,
F_92 ) ;
if ( V_11 )
goto V_134;
F_50 ( & V_9 -> V_2 , L_42 , V_38 -> V_67 ) ;
return V_38 ;
V_134:
F_106 ( & V_38 -> V_144 ) ;
V_133:
while ( ( V_18 = F_38 ( & V_38 -> V_123 , & V_38 -> V_126 ) ) )
F_19 ( V_18 ) ;
V_131:
while ( ( V_18 = F_38 ( & V_38 -> V_122 , & V_38 -> V_125 ) ) )
F_19 ( V_18 ) ;
F_107 ( V_148 , & V_15 -> V_97 ) ;
V_27:
return NULL ;
}
void F_85 ( struct V_37 * V_38 )
{
struct V_8 * V_9 = F_25 ( V_38 -> V_30 ) ;
struct V_65 * V_18 ;
if ( ! V_38 )
return;
F_49 ( & V_38 -> V_92 ) ;
F_108 ( V_38 -> V_30 , V_38 -> V_67 ) ;
F_106 ( & V_38 -> V_144 ) ;
while ( ( V_18 = F_38 ( & V_38 -> V_122 , & V_38 -> V_125 ) ) )
F_19 ( V_18 ) ;
while ( ( V_18 = F_38 ( & V_38 -> V_121 , & V_38 -> V_124 ) ) ) {
F_109 ( & V_9 -> V_2 , L_43 ) ;
F_19 ( V_18 ) ;
}
while ( ( V_18 = F_38 ( & V_38 -> V_123 , & V_38 -> V_126 ) ) )
F_19 ( V_18 ) ;
F_107 ( V_38 -> V_67 , & V_38 -> V_90 -> V_97 ) ;
F_50 ( & V_9 -> V_2 , L_44 , V_38 -> V_67 ) ;
}
void * F_110 ( struct V_37 * V_38 , unsigned int * V_135 )
{
struct V_65 * V_18 ;
void * V_39 ;
if ( ! V_38 || V_38 -> V_112 == V_60 )
return NULL ;
V_18 = F_38 ( & V_38 -> V_121 , & V_38 -> V_124 ) ;
if ( ! V_18 )
return NULL ;
V_39 = V_18 -> V_94 ;
* V_135 = V_18 -> V_135 ;
F_35 ( & V_38 -> V_122 , & V_18 -> V_18 , & V_38 -> V_125 ) ;
return V_39 ;
}
int F_111 ( struct V_37 * V_38 , void * V_151 , void * V_99 ,
unsigned int V_135 )
{
struct V_65 * V_18 ;
if ( ! V_38 )
return - V_12 ;
V_18 = F_38 ( & V_38 -> V_122 , & V_38 -> V_125 ) ;
if ( ! V_18 )
return - V_26 ;
V_18 -> V_94 = V_151 ;
V_18 -> V_39 = V_99 ;
V_18 -> V_135 = V_135 ;
F_35 ( & V_38 -> V_121 , & V_18 -> V_18 , & V_38 -> V_124 ) ;
return 0 ;
}
int F_112 ( struct V_37 * V_38 , void * V_151 , void * V_99 ,
unsigned int V_135 )
{
struct V_65 * V_18 ;
int V_11 ;
if ( ! V_38 || V_38 -> V_59 != V_60 || ! V_135 )
return - V_12 ;
V_18 = F_38 ( & V_38 -> V_123 , & V_38 -> V_126 ) ;
if ( ! V_18 )
return - V_26 ;
V_18 -> V_94 = V_151 ;
V_18 -> V_39 = V_99 ;
V_18 -> V_135 = V_135 ;
V_18 -> V_64 = 0 ;
V_11 = F_97 ( V_38 , V_18 ) ;
if ( V_11 )
F_35 ( & V_38 -> V_123 , & V_18 -> V_18 ,
& V_38 -> V_126 ) ;
return V_11 ;
}
void F_113 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return;
V_38 -> V_112 = V_60 ;
if ( V_38 -> V_90 -> V_95 == V_60 )
F_51 ( & V_38 -> V_92 , 0 ) ;
}
void F_114 ( struct V_37 * V_38 )
{
struct V_8 * V_9 = F_25 ( V_38 -> V_30 ) ;
int V_11 , V_105 ;
if ( ! V_38 )
return;
V_38 -> V_112 = V_91 ;
V_11 = F_63 ( V_38 -> V_30 , V_111 , & V_105 ) ;
if ( V_11 ) {
F_14 ( & V_9 -> V_2 , L_25 , V_111 ) ;
return;
}
V_11 = F_61 ( V_38 -> V_30 , V_111 ,
V_105 & ~ ( 1 << V_38 -> V_67 ) ) ;
if ( V_11 )
F_14 ( & V_9 -> V_2 , L_24 ,
V_105 & ~ ( 1 << V_38 -> V_67 ) , V_111 ) ;
if ( V_38 -> V_59 == V_60 )
F_98 ( V_38 ) ;
else
F_49 ( & V_38 -> V_92 ) ;
}
bool F_115 ( struct V_37 * V_38 )
{
return V_38 -> V_59 == V_60 ;
}
unsigned char F_116 ( struct V_37 * V_38 )
{
return V_38 -> V_67 ;
}
unsigned int F_117 ( struct V_37 * V_38 )
{
return V_38 -> V_115 - sizeof( struct V_83 ) ;
}
