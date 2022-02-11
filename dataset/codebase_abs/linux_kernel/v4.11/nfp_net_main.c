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
F_12 ( struct V_20 * V_21 , struct V_1 * V_2 ,
unsigned int V_22 )
{
T_1 V_23 [ V_24 ] ;
const char * V_25 ;
char V_6 [ 32 ] ;
snprintf ( V_6 , sizeof( V_6 ) , L_2 , V_22 ) ;
V_25 = F_2 ( V_2 , V_6 ) ;
if ( ! V_25 ) {
F_13 ( & V_21 -> V_26 -> V_27 ,
L_3 ) ;
F_14 ( V_21 -> V_28 ) ;
return;
}
if ( sscanf ( V_25 , L_4 ,
& V_23 [ 0 ] , & V_23 [ 1 ] , & V_23 [ 2 ] ,
& V_23 [ 3 ] , & V_23 [ 4 ] , & V_23 [ 5 ] ) != 6 ) {
F_13 ( & V_21 -> V_26 -> V_27 ,
L_5 , V_25 ) ;
F_14 ( V_21 -> V_28 ) ;
return;
}
F_15 ( V_21 -> V_28 -> V_29 , V_23 ) ;
F_15 ( V_21 -> V_28 -> V_30 , V_23 ) ;
}
static void
F_16 ( struct V_20 * V_21 , struct V_31 * V_32 , unsigned int V_22 )
{
int V_33 ;
for ( V_33 = 0 ; V_32 -> V_34 && V_33 < V_32 -> V_34 -> V_35 ; V_33 ++ )
if ( V_32 -> V_34 -> V_36 [ V_33 ] . V_37 == V_22 ) {
const T_1 * V_23 = V_32 -> V_34 -> V_36 [ V_33 ] . V_23 ;
F_15 ( V_21 -> V_28 -> V_29 , V_23 ) ;
F_15 ( V_21 -> V_28 -> V_30 , V_23 ) ;
return;
}
F_12 ( V_21 , V_32 -> V_2 , V_22 ) ;
}
static unsigned int F_17 ( struct V_31 * V_32 )
{
char V_6 [ 256 ] ;
T_4 V_38 ;
int V_39 ;
int V_5 = 0 ;
T_5 V_40 ;
V_38 = F_18 ( V_32 -> V_2 ) ;
V_39 = F_19 ( V_38 ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_6 , V_39 ) ;
V_40 = F_20 ( V_32 -> V_2 , V_6 , & V_5 ) ;
if ( V_5 ) {
if ( V_5 != - V_41 )
F_21 ( V_32 -> V_2 , L_7 ) ;
V_40 = 1 ;
}
return V_40 ;
}
static unsigned int
F_22 ( struct V_31 * V_32 , void T_2 * V_42 ,
unsigned int V_43 , T_3 V_44 , T_3 V_45 )
{
unsigned int V_33 , V_46 , V_47 ;
V_46 = F_23 ( V_42 + V_44 ) ;
V_47 = V_46 ;
for ( V_33 = 0 ; V_33 < V_32 -> V_48 ; V_33 ++ ) {
if ( V_47 > F_23 ( V_42 + V_44 ) )
return 0 ;
V_47 = F_23 ( V_42 + V_44 ) ;
V_47 += F_23 ( V_42 + V_45 ) * V_43 ;
V_42 += V_49 ;
}
return V_47 - V_46 ;
}
static T_1 T_2 * F_24 ( struct V_31 * V_32 )
{
const struct V_50 * V_51 ;
T_1 T_2 * V_42 ;
char V_52 [ 256 ] ;
T_4 V_38 ;
int V_39 ;
V_38 = F_18 ( V_32 -> V_2 ) ;
V_39 = F_19 ( V_38 ) ;
snprintf ( V_52 , sizeof( V_52 ) , L_8 , V_39 ) ;
V_51 = F_25 ( V_32 -> V_2 , V_52 ) ;
if ( ! V_51 ) {
F_26 ( & V_32 -> V_26 -> V_27 ,
L_9 , V_52 ) ;
return NULL ;
}
if ( V_51 -> V_10 < V_32 -> V_48 * V_49 ) {
F_26 ( & V_32 -> V_26 -> V_27 ,
L_10 ,
V_32 -> V_48 ) ;
return NULL ;
}
V_42 = F_4 ( V_32 -> V_2 , L_11 ,
V_51 -> V_53 , V_51 -> V_8 ,
V_51 -> V_9 , V_51 -> V_10 ,
& V_32 -> V_54 ) ;
if ( F_27 ( V_42 ) ) {
F_26 ( & V_32 -> V_26 -> V_27 , L_12 ,
F_28 ( V_42 ) ) ;
return NULL ;
}
return V_42 ;
}
static void F_29 ( struct V_31 * V_32 )
{
struct V_20 * V_21 ;
while ( ! F_30 ( & V_32 -> V_36 ) ) {
V_21 = F_31 ( & V_32 -> V_36 , struct V_20 , V_55 ) ;
F_32 ( & V_21 -> V_55 ) ;
F_33 ( V_21 ) ;
}
}
static struct V_20 *
F_34 ( struct V_31 * V_32 , void T_2 * V_42 ,
void T_2 * V_56 , void T_2 * V_57 ,
int V_43 , struct V_58 * V_59 )
{
T_3 V_60 , V_61 ;
struct V_20 * V_21 ;
V_60 = F_23 ( V_42 + V_62 ) ;
V_61 = F_23 ( V_42 + V_63 ) ;
V_21 = F_35 ( V_32 -> V_26 , V_60 , V_61 ) ;
if ( F_27 ( V_21 ) )
return V_21 ;
V_21 -> V_2 = V_32 -> V_2 ;
V_21 -> V_59 = * V_59 ;
V_21 -> V_42 = V_42 ;
V_21 -> V_56 = V_56 ;
V_21 -> V_57 = V_57 ;
V_21 -> V_64 = 0 ;
V_21 -> V_65 = V_43 ;
V_21 -> V_66 = V_43 ;
return V_21 ;
}
static int
F_36 ( struct V_31 * V_32 , struct V_20 * V_21 ,
unsigned int V_22 )
{
int V_5 ;
F_16 ( V_21 , V_32 , V_22 ) ;
V_21 -> V_67 = 1200 ;
V_5 = F_37 ( V_21 -> V_28 ) ;
if ( V_5 )
return V_5 ;
F_38 ( V_21 , V_32 -> V_68 , V_22 ) ;
F_39 ( V_21 ) ;
return 0 ;
}
static int
F_40 ( struct V_31 * V_32 , void T_2 * V_42 ,
void T_2 * V_56 , void T_2 * V_57 ,
int V_43 , struct V_58 * V_59 )
{
T_3 V_69 , V_70 , V_71 , V_72 ;
struct V_20 * V_21 ;
unsigned int V_33 ;
int V_5 ;
V_69 = F_23 ( V_42 + V_73 ) ;
V_70 = F_23 ( V_42 + V_74 ) ;
for ( V_33 = 0 ; V_33 < V_32 -> V_48 ; V_33 ++ ) {
V_71 = F_23 ( V_42 + V_73 ) ;
V_72 = F_23 ( V_42 + V_74 ) ;
V_56 += ( V_71 - V_69 ) * V_75 ;
V_57 += ( V_72 - V_70 ) * V_75 ;
V_69 = V_71 ;
V_70 = V_72 ;
V_21 = F_34 ( V_32 , V_42 , V_56 , V_57 ,
V_43 , V_59 ) ;
if ( F_27 ( V_21 ) ) {
V_5 = F_28 ( V_21 ) ;
goto V_76;
}
F_41 ( & V_21 -> V_55 , & V_32 -> V_36 ) ;
V_42 += V_49 ;
}
return 0 ;
V_76:
F_29 ( V_32 ) ;
return V_5 ;
}
static int
F_42 ( struct V_31 * V_32 ,
void T_2 * V_42 , void T_2 * V_56 ,
void T_2 * V_57 , int V_43 ,
struct V_58 * V_59 )
{
unsigned int V_22 , V_77 , V_78 , V_79 , V_80 ;
struct V_20 * V_21 ;
int V_5 ;
V_5 = F_40 ( V_32 , V_42 , V_56 , V_57 ,
V_43 , V_59 ) ;
if ( V_5 )
return V_5 ;
V_77 = 0 ;
F_43 (nn, &pf->ports, port_list)
V_77 += V_81 + V_21 -> V_82 ;
V_32 -> V_83 = F_44 ( V_77 , sizeof( * V_32 -> V_83 ) ,
V_84 ) ;
if ( ! V_32 -> V_83 ) {
V_5 = - V_85 ;
goto V_86;
}
V_78 = F_45 ( V_32 -> V_26 , V_32 -> V_83 ,
V_87 * V_32 -> V_48 ,
V_77 ) ;
if ( ! V_78 ) {
F_46 ( V_21 , L_13 ) ;
V_5 = - V_85 ;
goto V_88;
}
V_80 = V_78 ;
V_79 = V_32 -> V_48 ;
F_43 (nn, &pf->ports, port_list) {
unsigned int V_89 ;
V_89 = F_47 ( V_80 , V_79 ) ;
F_48 ( V_21 , & V_32 -> V_83 [ V_78 - V_80 ] ,
V_89 ) ;
V_80 -= V_89 ;
V_79 -- ;
}
V_22 = 0 ;
F_43 (nn, &pf->ports, port_list) {
V_5 = F_36 ( V_32 , V_21 , V_22 ) ;
if ( V_5 )
goto V_90;
V_22 ++ ;
}
return 0 ;
V_90:
F_49 (nn, &pf->ports, port_list) {
F_50 ( & V_21 -> V_91 ) ;
F_51 ( V_21 -> V_28 ) ;
}
F_52 ( V_32 -> V_26 ) ;
V_88:
F_53 ( V_32 -> V_83 ) ;
V_86:
F_29 ( V_32 ) ;
return V_5 ;
}
int F_54 ( struct V_31 * V_32 )
{
T_1 T_2 * V_42 , * V_56 , * V_57 ;
T_3 V_92 , V_93 ;
struct V_58 V_59 ;
T_3 V_94 , V_95 ;
T_3 V_96 ;
int V_43 ;
int V_5 ;
if ( ! F_1 ( V_32 -> V_2 ) ) {
F_21 ( V_32 -> V_2 , L_14 ) ;
return - V_97 ;
}
V_32 -> V_48 = F_17 ( V_32 ) ;
V_42 = F_24 ( V_32 ) ;
if ( ! V_42 )
return V_32 -> V_98 ? - V_97 : - V_99 ;
F_55 ( & V_59 , V_42 ) ;
if ( V_59 . V_100 || V_59 . V_101 != V_102 ) {
F_21 ( V_32 -> V_2 , L_15 ,
V_59 . V_100 , V_59 . V_101 , V_59 . V_103 , V_59 . V_104 ) ;
V_5 = - V_97 ;
goto V_105;
}
if ( F_56 ( & V_59 , 0 , 0 , 0 , 1 ) ) {
V_43 = 2 ;
F_57 ( V_32 -> V_2 , L_16 ) ;
} else {
switch ( V_59 . V_103 ) {
case 1 ... 4 :
V_43 = 4 ;
break;
default:
F_21 ( V_32 -> V_2 , L_17 ,
V_59 . V_100 , V_59 . V_101 ,
V_59 . V_103 , V_59 . V_104 ) ;
V_5 = - V_97 ;
goto V_105;
}
}
V_92 = F_22 ( V_32 , V_42 , V_43 ,
V_73 ,
V_62 ) ;
V_93 = F_22 ( V_32 , V_42 , V_43 ,
V_74 ,
V_63 ) ;
if ( ! V_92 || ! V_93 ) {
F_21 ( V_32 -> V_2 , L_18 ,
V_92 , V_93 ) ;
V_5 = - V_97 ;
goto V_105;
}
V_94 = V_75 * V_92 ;
V_95 = V_75 * V_93 ;
V_96 = F_23 ( V_42 + V_73 ) ;
V_56 = F_4 ( V_32 -> V_2 , L_19 , 0 , 0 ,
F_58 ( V_96 ) ,
V_94 , & V_32 -> V_106 ) ;
if ( F_27 ( V_56 ) ) {
F_21 ( V_32 -> V_2 , L_20 ) ;
V_5 = F_28 ( V_56 ) ;
goto V_105;
}
V_96 = F_23 ( V_42 + V_74 ) ;
V_57 = F_4 ( V_32 -> V_2 , L_21 , 0 , 0 ,
F_58 ( V_96 ) ,
V_95 , & V_32 -> V_107 ) ;
if ( F_27 ( V_57 ) ) {
F_21 ( V_32 -> V_2 , L_22 ) ;
V_5 = F_28 ( V_57 ) ;
goto V_108;
}
V_32 -> V_68 = F_59 ( V_32 -> V_26 ) ;
V_5 = F_42 ( V_32 , V_42 , V_56 , V_57 ,
V_43 , & V_59 ) ;
if ( V_5 )
goto V_109;
return 0 ;
V_109:
F_50 ( & V_32 -> V_68 ) ;
F_60 ( V_32 -> V_107 ) ;
V_108:
F_60 ( V_32 -> V_106 ) ;
V_105:
F_60 ( V_32 -> V_54 ) ;
return V_5 ;
}
void F_61 ( struct V_31 * V_32 )
{
struct V_20 * V_21 ;
F_43 (nn, &pf->ports, port_list) {
F_50 ( & V_21 -> V_91 ) ;
F_51 ( V_21 -> V_28 ) ;
}
F_29 ( V_32 ) ;
F_50 ( & V_32 -> V_68 ) ;
F_52 ( V_32 -> V_26 ) ;
F_53 ( V_32 -> V_83 ) ;
F_60 ( V_32 -> V_107 ) ;
F_60 ( V_32 -> V_106 ) ;
F_60 ( V_32 -> V_54 ) ;
}
