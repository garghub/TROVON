static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 ;
long V_4 ;
int V_5 ;
V_3 = F_2 ( V_2 , L_1 ) ;
if ( ! V_3 )
return 0 ;
V_5 = F_3 ( V_3 , 0 , & V_4 ) ;
if ( V_5 < 0 )
return 0 ;
return V_4 == 15 ;
}
static T_1 T_2 * F_4 ( struct V_1 * V_2 ,
const char * V_6 , int V_7 , int V_8 ,
unsigned long long V_9 , unsigned long V_10 ,
struct V_11 * * V_12 )
{
T_1 T_2 * V_13 ;
T_3 V_14 ;
int V_5 ;
V_14 = F_5 ( V_8 , V_15 , 0 , V_7 ) ;
* V_12 = F_6 ( V_2 , V_14 , V_6 , V_9 , V_10 ) ;
if ( ! * V_12 ) {
V_5 = - V_16 ;
goto V_17;
}
V_5 = F_7 ( * V_12 ) ;
if ( V_5 < 0 )
goto V_18;
V_13 = F_8 ( * V_12 ) ;
if ( ! V_13 ) {
V_5 = - V_16 ;
goto V_19;
}
return V_13 ;
V_19:
F_9 ( * V_12 ) ;
V_18:
F_10 ( * V_12 ) ;
V_17:
return ( T_1 T_2 * ) F_11 ( V_5 ) ;
}
static void
F_12 ( struct V_20 * V_21 , struct V_1 * V_2 , unsigned int V_22 )
{
struct V_23 * V_24 = & V_21 -> V_24 ;
T_1 V_25 [ V_26 ] ;
const char * V_27 ;
char V_6 [ 32 ] ;
if ( V_21 -> V_28 ) {
F_13 ( V_24 -> V_29 -> V_30 , V_21 -> V_28 -> V_25 ) ;
F_13 ( V_24 -> V_29 -> V_31 , V_21 -> V_28 -> V_25 ) ;
return;
}
snprintf ( V_6 , sizeof( V_6 ) , L_2 , V_22 ) ;
V_27 = F_2 ( V_2 , V_6 ) ;
if ( ! V_27 ) {
F_14 ( V_24 -> V_32 , L_3 ) ;
F_15 ( V_24 -> V_29 ) ;
return;
}
if ( sscanf ( V_27 , L_4 ,
& V_25 [ 0 ] , & V_25 [ 1 ] , & V_25 [ 2 ] ,
& V_25 [ 3 ] , & V_25 [ 4 ] , & V_25 [ 5 ] ) != 6 ) {
F_14 ( V_24 -> V_32 ,
L_5 , V_27 ) ;
F_15 ( V_24 -> V_29 ) ;
return;
}
F_13 ( V_24 -> V_29 -> V_30 , V_25 ) ;
F_13 ( V_24 -> V_29 -> V_31 , V_25 ) ;
}
static struct V_33 *
F_16 ( struct V_34 * V_35 , unsigned int V_22 )
{
int V_36 ;
for ( V_36 = 0 ; V_35 && V_36 < V_35 -> V_37 ; V_36 ++ )
if ( V_35 -> V_38 [ V_36 ] . V_39 == V_22 )
return & V_35 -> V_38 [ V_36 ] ;
return NULL ;
}
static unsigned int F_17 ( struct V_40 * V_41 )
{
char V_6 [ 256 ] ;
T_4 V_42 ;
int V_43 ;
int V_5 = 0 ;
T_5 V_44 ;
V_42 = F_18 ( V_41 -> V_2 ) ;
V_43 = F_19 ( V_42 ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_6 , V_43 ) ;
V_44 = F_20 ( V_41 -> V_2 , V_6 , & V_5 ) ;
if ( V_5 ) {
if ( V_5 != - V_45 )
F_21 ( V_41 -> V_2 , L_7 ) ;
V_44 = 1 ;
}
return V_44 ;
}
static unsigned int
F_22 ( struct V_40 * V_41 , void T_2 * V_46 ,
unsigned int V_47 , T_3 V_48 , T_3 V_49 )
{
unsigned int V_36 , V_50 , V_51 ;
V_50 = F_23 ( V_46 + V_48 ) ;
V_51 = V_50 ;
for ( V_36 = 0 ; V_36 < V_41 -> V_52 ; V_36 ++ ) {
if ( V_51 > F_23 ( V_46 + V_48 ) )
return 0 ;
V_51 = F_23 ( V_46 + V_48 ) ;
V_51 += F_23 ( V_46 + V_49 ) * V_47 ;
V_46 += V_53 ;
}
return V_51 - V_50 ;
}
static T_1 T_2 * F_24 ( struct V_40 * V_41 )
{
const struct V_54 * V_55 ;
T_1 T_2 * V_46 ;
char V_56 [ 256 ] ;
T_4 V_42 ;
int V_43 ;
V_42 = F_18 ( V_41 -> V_2 ) ;
V_43 = F_19 ( V_42 ) ;
snprintf ( V_56 , sizeof( V_56 ) , L_8 , V_43 ) ;
V_55 = F_25 ( V_41 -> V_2 , V_56 ) ;
if ( ! V_55 ) {
F_26 ( & V_41 -> V_57 -> V_32 ,
L_9 , V_56 ) ;
return NULL ;
}
if ( V_55 -> V_10 < V_41 -> V_52 * V_53 ) {
F_26 ( & V_41 -> V_57 -> V_32 ,
L_10 ,
V_41 -> V_52 ) ;
return NULL ;
}
V_46 = F_4 ( V_41 -> V_2 , L_11 ,
V_55 -> V_58 , V_55 -> V_8 ,
V_55 -> V_9 , V_55 -> V_10 ,
& V_41 -> V_59 ) ;
if ( F_27 ( V_46 ) ) {
F_26 ( & V_41 -> V_57 -> V_32 , L_12 ,
F_28 ( V_46 ) ) ;
return NULL ;
}
return V_46 ;
}
static void F_29 ( struct V_40 * V_41 )
{
struct V_20 * V_21 ;
while ( ! F_30 ( & V_41 -> V_38 ) ) {
V_21 = F_31 ( & V_41 -> V_38 , struct V_20 , V_60 ) ;
F_32 ( & V_21 -> V_60 ) ;
V_41 -> V_61 -- ;
F_33 ( V_21 ) ;
}
}
static struct V_20 *
F_34 ( struct V_40 * V_41 , void T_2 * V_46 ,
void T_2 * V_62 , void T_2 * V_63 ,
int V_47 , struct V_64 * V_65 ,
struct V_33 * V_28 )
{
T_3 V_66 , V_67 ;
struct V_20 * V_21 ;
V_66 = F_23 ( V_46 + V_68 ) ;
V_67 = F_23 ( V_46 + V_69 ) ;
V_21 = F_35 ( V_41 -> V_57 , V_66 , V_67 ) ;
if ( F_27 ( V_21 ) )
return V_21 ;
V_21 -> V_2 = V_41 -> V_2 ;
V_21 -> V_65 = * V_65 ;
V_21 -> V_24 . V_46 = V_46 ;
V_21 -> V_62 = V_62 ;
V_21 -> V_63 = V_63 ;
V_21 -> V_24 . V_70 = 0 ;
V_21 -> V_71 = V_47 ;
V_21 -> V_72 = V_47 ;
V_21 -> V_28 = V_28 ;
return V_21 ;
}
static int
F_36 ( struct V_40 * V_41 , struct V_20 * V_21 ,
unsigned int V_22 )
{
int V_5 ;
F_12 ( V_21 , V_41 -> V_2 , V_22 ) ;
V_21 -> V_73 = 1200 ;
V_5 = F_37 ( V_21 -> V_24 . V_29 ) ;
if ( V_5 )
return V_5 ;
F_38 ( V_21 , V_41 -> V_74 , V_22 ) ;
F_39 ( V_21 ) ;
return 0 ;
}
static int
F_40 ( struct V_40 * V_41 , void T_2 * V_46 ,
void T_2 * V_62 , void T_2 * V_63 ,
int V_47 , struct V_64 * V_65 )
{
T_3 V_75 , V_76 , V_77 , V_78 ;
struct V_33 * V_28 ;
struct V_20 * V_21 ;
unsigned int V_36 ;
int V_5 ;
V_75 = F_23 ( V_46 + V_79 ) ;
V_76 = F_23 ( V_46 + V_80 ) ;
for ( V_36 = 0 ; V_36 < V_41 -> V_52 ; V_36 ++ ) {
V_77 = F_23 ( V_46 + V_79 ) ;
V_78 = F_23 ( V_46 + V_80 ) ;
V_62 += ( V_77 - V_75 ) * V_81 ;
V_63 += ( V_78 - V_76 ) * V_81 ;
V_75 = V_77 ;
V_76 = V_78 ;
V_28 = F_16 ( V_41 -> V_35 , V_36 ) ;
if ( V_28 && V_28 -> V_82 ) {
F_41 ( V_41 -> V_2 , L_13 , V_36 ) ;
} else {
V_21 = F_34 ( V_41 , V_46 , V_62 ,
V_63 , V_47 ,
V_65 , V_28 ) ;
if ( F_27 ( V_21 ) ) {
V_5 = F_28 ( V_21 ) ;
goto V_83;
}
F_42 ( & V_21 -> V_60 , & V_41 -> V_38 ) ;
V_41 -> V_61 ++ ;
}
V_46 += V_53 ;
}
if ( F_30 ( & V_41 -> V_38 ) )
return - V_84 ;
return 0 ;
V_83:
F_29 ( V_41 ) ;
return V_5 ;
}
static int
F_43 ( struct V_40 * V_41 ,
void T_2 * V_46 , void T_2 * V_62 ,
void T_2 * V_63 , int V_47 ,
struct V_64 * V_65 )
{
unsigned int V_22 , V_85 , V_86 , V_87 , V_88 ;
struct V_20 * V_21 ;
int V_5 ;
V_5 = F_40 ( V_41 , V_46 , V_62 , V_63 ,
V_47 , V_65 ) ;
if ( V_5 )
return V_5 ;
V_85 = 0 ;
F_44 (nn, &pf->ports, port_list)
V_85 += V_89 + V_21 -> V_24 . V_90 ;
V_41 -> V_91 = F_45 ( V_85 , sizeof( * V_41 -> V_91 ) ,
V_92 ) ;
if ( ! V_41 -> V_91 ) {
V_5 = - V_93 ;
goto V_94;
}
V_86 = F_46 ( V_41 -> V_57 , V_41 -> V_91 ,
V_95 * V_41 -> V_61 ,
V_85 ) ;
if ( ! V_86 ) {
F_47 ( V_21 , L_14 ) ;
V_5 = - V_93 ;
goto V_96;
}
V_88 = V_86 ;
V_87 = V_41 -> V_61 ;
F_44 (nn, &pf->ports, port_list) {
unsigned int V_97 ;
V_97 = F_48 ( V_88 , V_87 ) ;
F_49 ( V_21 , & V_41 -> V_91 [ V_86 - V_88 ] ,
V_97 ) ;
V_88 -= V_97 ;
V_87 -- ;
}
V_22 = 0 ;
F_44 (nn, &pf->ports, port_list) {
V_5 = F_36 ( V_41 , V_21 , V_22 ) ;
if ( V_5 )
goto V_98;
V_22 ++ ;
}
return 0 ;
V_98:
F_50 (nn, &pf->ports, port_list) {
F_51 ( & V_21 -> V_99 ) ;
F_52 ( V_21 -> V_24 . V_29 ) ;
}
F_53 ( V_41 -> V_57 ) ;
V_96:
F_54 ( V_41 -> V_91 ) ;
V_94:
F_29 ( V_41 ) ;
return V_5 ;
}
static void F_55 ( struct V_40 * V_41 )
{
F_51 ( & V_41 -> V_74 ) ;
F_53 ( V_41 -> V_57 ) ;
F_54 ( V_41 -> V_91 ) ;
F_56 ( V_41 -> V_100 ) ;
F_56 ( V_41 -> V_101 ) ;
F_56 ( V_41 -> V_59 ) ;
}
static void F_57 ( struct V_102 * V_103 )
{
struct V_40 * V_41 = F_58 ( V_103 , struct V_40 ,
V_104 ) ;
struct V_34 * V_105 ;
struct V_20 * V_21 , * V_106 ;
F_59 ( & V_41 -> V_107 ) ;
if ( F_30 ( & V_41 -> V_38 ) )
goto V_108;
F_44 (nn, &pf->ports, port_list)
F_60 ( V_21 ) ;
V_105 = F_61 ( V_41 -> V_2 ) ;
if ( ! V_105 ) {
F_21 ( V_41 -> V_2 , L_15 ) ;
goto V_108;
}
F_62 () ;
F_44 (nn, &pf->ports, port_list) {
if ( ! V_21 -> V_28 )
continue;
V_21 -> V_28 = F_16 ( V_105 ,
V_21 -> V_28 -> V_39 ) ;
}
F_63 () ;
F_54 ( V_41 -> V_35 ) ;
V_41 -> V_35 = V_105 ;
F_64 (nn, next, &pf->ports, port_list) {
if ( ! V_21 -> V_28 ) {
F_41 ( V_41 -> V_2 , L_16 ) ;
continue;
}
if ( ! V_21 -> V_28 -> V_82 )
continue;
F_47 ( V_21 , L_17 ) ;
F_51 ( & V_21 -> V_99 ) ;
F_52 ( V_21 -> V_24 . V_29 ) ;
F_32 ( & V_21 -> V_60 ) ;
V_41 -> V_61 -- ;
F_33 ( V_21 ) ;
}
if ( F_30 ( & V_41 -> V_38 ) )
F_55 ( V_41 ) ;
V_108:
F_65 ( & V_41 -> V_107 ) ;
}
void F_66 ( struct V_20 * V_21 )
{
struct V_40 * V_41 = F_67 ( V_21 -> V_57 ) ;
F_68 ( & V_41 -> V_104 ) ;
}
int F_69 ( struct V_20 * V_21 )
{
struct V_33 * V_28 ;
struct V_34 * V_105 ;
V_105 = F_61 ( V_21 -> V_2 ) ;
if ( ! V_105 ) {
F_70 ( V_21 , L_18 ) ;
return - V_16 ;
}
V_28 = F_16 ( V_105 , V_21 -> V_28 -> V_39 ) ;
if ( ! V_28 ) {
F_70 ( V_21 , L_19 ) ;
F_54 ( V_105 ) ;
return - V_16 ;
}
memcpy ( V_21 -> V_28 , V_28 , sizeof( * V_28 ) ) ;
F_54 ( V_105 ) ;
return 0 ;
}
int F_71 ( struct V_40 * V_41 )
{
T_1 T_2 * V_46 , * V_62 , * V_63 ;
T_3 V_109 , V_110 ;
struct V_64 V_65 ;
T_3 V_111 , V_112 ;
T_3 V_113 ;
int V_47 ;
int V_5 ;
F_72 ( & V_41 -> V_104 , F_57 ) ;
F_73 ( & V_41 -> V_107 ) ;
if ( ! F_1 ( V_41 -> V_2 ) ) {
F_21 ( V_41 -> V_2 , L_20 ) ;
return - V_114 ;
}
F_59 ( & V_41 -> V_107 ) ;
V_41 -> V_52 = F_17 ( V_41 ) ;
V_46 = F_24 ( V_41 ) ;
if ( ! V_46 ) {
V_5 = V_41 -> V_115 ? - V_114 : - V_116 ;
goto V_117;
}
F_74 ( & V_65 , V_46 ) ;
if ( V_65 . V_118 || V_65 . V_119 != V_120 ) {
F_21 ( V_41 -> V_2 , L_21 ,
V_65 . V_118 , V_65 . V_119 , V_65 . V_121 , V_65 . V_122 ) ;
V_5 = - V_114 ;
goto V_123;
}
if ( F_75 ( & V_65 , 0 , 0 , 0 , 1 ) ) {
V_47 = 2 ;
F_41 ( V_41 -> V_2 , L_22 ) ;
} else {
switch ( V_65 . V_121 ) {
case 1 ... 4 :
V_47 = 4 ;
break;
default:
F_21 ( V_41 -> V_2 , L_23 ,
V_65 . V_118 , V_65 . V_119 ,
V_65 . V_121 , V_65 . V_122 ) ;
V_5 = - V_114 ;
goto V_123;
}
}
V_109 = F_22 ( V_41 , V_46 , V_47 ,
V_79 ,
V_68 ) ;
V_110 = F_22 ( V_41 , V_46 , V_47 ,
V_80 ,
V_69 ) ;
if ( ! V_109 || ! V_110 ) {
F_21 ( V_41 -> V_2 , L_24 ,
V_109 , V_110 ) ;
V_5 = - V_114 ;
goto V_123;
}
V_111 = V_81 * V_109 ;
V_112 = V_81 * V_110 ;
V_113 = F_23 ( V_46 + V_79 ) ;
V_62 = F_4 ( V_41 -> V_2 , L_25 , 0 , 0 ,
F_76 ( V_113 ) ,
V_111 , & V_41 -> V_101 ) ;
if ( F_27 ( V_62 ) ) {
F_21 ( V_41 -> V_2 , L_26 ) ;
V_5 = F_28 ( V_62 ) ;
goto V_123;
}
V_113 = F_23 ( V_46 + V_80 ) ;
V_63 = F_4 ( V_41 -> V_2 , L_27 , 0 , 0 ,
F_76 ( V_113 ) ,
V_112 , & V_41 -> V_100 ) ;
if ( F_27 ( V_63 ) ) {
F_21 ( V_41 -> V_2 , L_28 ) ;
V_5 = F_28 ( V_63 ) ;
goto V_124;
}
V_41 -> V_74 = F_77 ( V_41 -> V_57 ) ;
V_5 = F_43 ( V_41 , V_46 , V_62 , V_63 ,
V_47 , & V_65 ) ;
if ( V_5 )
goto V_125;
F_65 ( & V_41 -> V_107 ) ;
return 0 ;
V_125:
F_51 ( & V_41 -> V_74 ) ;
F_56 ( V_41 -> V_100 ) ;
V_124:
F_56 ( V_41 -> V_101 ) ;
V_123:
F_56 ( V_41 -> V_59 ) ;
V_117:
F_65 ( & V_41 -> V_107 ) ;
return V_5 ;
}
void F_78 ( struct V_40 * V_41 )
{
struct V_20 * V_21 ;
F_59 ( & V_41 -> V_107 ) ;
if ( F_30 ( & V_41 -> V_38 ) )
goto V_108;
F_44 (nn, &pf->ports, port_list) {
F_51 ( & V_21 -> V_99 ) ;
F_52 ( V_21 -> V_24 . V_29 ) ;
}
F_29 ( V_41 ) ;
F_55 ( V_41 ) ;
V_108:
F_65 ( & V_41 -> V_107 ) ;
F_79 ( & V_41 -> V_104 ) ;
}
