static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 ,
V_7 [ V_6 -> V_8 - 1 ] ) ;
}
static inline struct V_4 * F_4 ( struct V_1 * V_9 )
{
return F_2 ( V_9 , struct V_4 ,
V_10 [ V_9 -> V_8 ] ) ;
}
static inline int F_5 ( struct V_11 * V_12 , T_1 V_13 , T_1 V_14 )
{
return F_6 ( V_12 , V_13 , V_14 ) ;
}
static int F_7 ( struct V_11 * V_12 , T_1 V_13 , T_1 * V_15 )
{
T_2 V_16 ;
V_16 = F_8 ( V_12 , V_13 ) ;
if ( V_16 < 0 )
return - V_17 ;
* V_15 = V_16 ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , T_1 V_18 )
{
struct V_4 * V_19 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
int V_16 ;
T_1 V_20 ;
if ( V_18 == V_21 )
return 0 ;
if ( V_18 == V_22 )
V_18 = V_23 ;
V_16 = F_7 ( V_12 , V_24 , & V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
V_20 &= ~ ( V_6 -> V_25 ) ;
V_18 &= V_6 -> V_25 ;
V_20 |= V_18 ;
return F_5 ( V_12 , V_24 , V_20 ) ;
}
static int F_10 ( struct V_5 * V_26 , const T_1 * V_27 )
{
struct V_4 * V_19 = F_3 ( V_26 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
int V_16 ;
int V_28 ;
T_1 V_18 ;
V_16 = F_9 ( V_26 , V_23 ) ;
if ( V_16 )
return V_16 ;
F_11 ( 1000 , 2000 ) ;
V_16 = F_7 ( V_12 , V_24 , & V_18 ) ;
if ( V_16 )
return V_16 ;
F_5 ( V_12 , V_24 , V_23 ) ;
F_11 ( 1000 , 2000 ) ;
F_5 ( V_12 , V_24 , V_21 ) ;
F_11 ( 1000 , 2000 ) ;
V_28 = V_29 + V_26 -> V_30 * V_31 ;
F_12 ( V_12 ,
V_28 ,
V_31 ,
V_27 ) ;
return F_5 ( V_12 , V_24 , V_18 ) ;
}
static int F_13 ( struct V_4 * V_19 , int V_9 , T_1 V_32 )
{
return F_5 ( V_19 -> V_12 ,
V_33 + V_19 -> V_10 [ V_9 ] . V_34 ,
V_32 ) ;
}
static void F_14 ( struct V_4 * V_19 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < F_15 ( V_19 -> V_7 ) ; V_35 ++ ) {
V_19 -> V_7 [ V_35 ] . V_8 = V_35 + 1 ;
V_19 -> V_7 [ V_35 ] . V_25 = V_36 >> ( V_35 * 2 ) ;
V_19 -> V_7 [ V_35 ] . V_30 = V_35 ;
}
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_4 * V_19 = F_17 ( V_12 ) ;
int V_16 ;
T_1 V_37 ;
F_14 ( V_19 ) ;
V_16 = F_5 ( V_12 , V_24 , V_23 ) ;
V_37 = V_19 -> V_38 -> V_39 ?
: ( V_40 | V_41 | V_42 ) ;
V_16 |= F_5 ( V_12 , V_43 , V_37 ) ;
V_16 |= F_5 ( V_12 , V_44 , 0 ) ;
V_16 |= F_5 ( V_12 , V_45 , 0 ) ;
V_16 |= F_5 ( V_12 , V_46 , 0 ) ;
V_16 |= F_5 ( V_12 , V_47 ,
V_48 ) ;
F_11 ( 1000 , 2000 ) ;
return V_16 ;
}
static int F_18 ( struct V_4 * V_19 , char * V_15 )
{
int V_16 ;
T_1 V_49 ;
V_16 = F_7 ( V_19 -> V_12 , V_50 , & V_49 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_19 -> V_38 && V_19 -> V_38 -> V_51 == V_52 )
if ( ( V_49 & V_53 ) == 0 )
return - V_17 ;
return 0 ;
}
static void F_19 ( struct V_2 * V_3 ,
enum V_54 V_55 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
V_9 -> V_55 = ( T_1 ) V_55 ;
F_20 ( & V_9 -> V_56 ) ;
}
static void F_21 ( struct V_57 * V_58 )
{
struct V_1 * V_9 = F_2 ( V_58 ,
struct V_1 ,
V_56 ) ;
struct V_4 * V_19 = F_4 ( V_9 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
F_22 ( & V_19 -> V_59 ) ;
F_5 ( V_12 , V_60 + V_9 -> V_34 ,
V_9 -> V_55 ) ;
F_23 ( & V_19 -> V_59 ) ;
}
static int F_24 ( struct V_11 * V_12 )
{
int V_16 ;
T_1 V_15 ;
V_16 = F_5 ( V_12 , V_47 , V_61 ) ;
if ( V_16 )
return V_16 ;
F_11 ( 1000 , 2000 ) ;
V_16 = F_7 ( V_12 , V_47 , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 != V_61 )
return - V_62 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 , T_1 V_18 )
{
int V_16 = 0 ;
if ( V_18 == V_6 -> V_18 && V_18 != V_63 )
return 0 ;
if ( V_18 == V_63 ) {
V_16 = F_9 ( V_6 , V_63 ) ;
} else if ( V_18 == V_21 ) {
F_9 ( V_6 , V_22 ) ;
F_9 ( V_6 , V_21 ) ;
} else if ( V_18 == V_22 ) {
F_9 ( V_6 , V_22 ) ;
}
V_6 -> V_18 = V_18 ;
return V_16 ;
}
static int F_26 ( struct V_5 * V_6 ,
const char * V_15 , T_3 V_64 )
{
struct V_4 * V_19 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
int V_16 , V_65 , V_66 = 0 , V_35 = 0 ;
char V_67 [ 3 ] ;
unsigned V_68 ;
T_1 V_27 [ V_69 ] = { 0 } ;
while ( ( V_66 < V_64 - 1 ) && ( V_35 < V_69 ) ) {
V_16 = sscanf ( V_15 + V_66 , L_1 , V_67 , & V_65 ) ;
if ( V_16 != 2 )
goto V_70;
V_16 = sscanf ( V_67 , L_2 , & V_68 ) ;
if ( V_16 != 1 )
goto V_70;
V_27 [ V_35 ] = ( T_1 ) V_68 ;
V_66 += V_65 ;
V_35 ++ ;
}
if ( V_35 % 2 )
goto V_70;
F_22 ( & V_19 -> V_59 ) ;
if ( V_6 -> V_18 == V_21 )
V_16 = F_10 ( V_6 , V_27 ) ;
else
V_16 = - V_71 ;
F_23 ( & V_19 -> V_59 ) ;
if ( V_16 ) {
F_27 ( & V_12 -> V_72 , L_3 ) ;
return V_16 ;
}
return V_64 ;
V_70:
F_27 ( & V_12 -> V_72 , L_4 ) ;
return - V_71 ;
}
static T_4 F_28 ( struct V_73 * V_72 ,
struct V_74 * V_75 ,
const char * V_15 , T_3 V_64 , int V_76 )
{
struct V_11 * V_12 = F_29 ( V_72 ) ;
struct V_4 * V_19 = F_17 ( V_12 ) ;
return F_26 ( & V_19 -> V_7 [ V_76 - 1 ] , V_15 , V_64 ) ;
}
static T_4 F_30 ( struct V_73 * V_72 ,
struct V_74 * V_75 ,
char * V_15 , int V_76 )
{
struct V_11 * V_12 = F_29 ( V_72 ) ;
struct V_4 * V_19 = F_17 ( V_12 ) ;
switch ( V_19 -> V_7 [ V_76 - 1 ] . V_18 ) {
case V_63 :
return sprintf ( V_15 , L_5 ) ;
case V_21 :
return sprintf ( V_15 , L_6 ) ;
case V_22 :
return sprintf ( V_15 , L_7 ) ;
default:
return sprintf ( V_15 , L_7 ) ;
}
}
static T_4 F_31 ( struct V_73 * V_72 ,
struct V_74 * V_75 ,
const char * V_15 , T_3 V_64 , int V_76 )
{
struct V_11 * V_12 = F_29 ( V_72 ) ;
struct V_4 * V_19 = F_17 ( V_12 ) ;
struct V_5 * V_6 = & V_19 -> V_7 [ V_76 - 1 ] ;
F_22 ( & V_19 -> V_59 ) ;
if ( ! strncmp ( V_15 , L_8 , 3 ) )
F_25 ( V_6 , V_63 ) ;
else if ( ! strncmp ( V_15 , L_9 , 4 ) )
F_25 ( V_6 , V_21 ) ;
else if ( ! strncmp ( V_15 , L_10 , 8 ) )
F_25 ( V_6 , V_22 ) ;
F_23 ( & V_19 -> V_59 ) ;
return V_64 ;
}
static T_4 F_32 ( struct V_73 * V_72 ,
struct V_74 * V_75 ,
char * V_15 )
{
struct V_2 * V_77 = F_33 ( V_72 ) ;
struct V_1 * V_9 = F_1 ( V_77 ) ;
return sprintf ( V_15 , L_11 , V_9 -> V_78 ) ;
}
static T_4 F_34 ( struct V_73 * V_72 ,
struct V_74 * V_75 ,
char * V_15 )
{
struct V_2 * V_77 = F_33 ( V_72 ) ;
struct V_1 * V_9 = F_1 ( V_77 ) ;
return sprintf ( V_15 , L_11 , V_9 -> V_79 ) ;
}
static T_4 F_35 ( struct V_73 * V_72 ,
struct V_74 * V_75 ,
const char * V_15 , T_3 V_64 )
{
struct V_2 * V_77 = F_33 ( V_72 ) ;
struct V_1 * V_9 = F_1 ( V_77 ) ;
struct V_4 * V_19 = F_4 ( V_9 ) ;
T_4 V_16 ;
unsigned long V_32 ;
if ( F_36 ( V_15 , 0 , & V_32 ) )
return - V_71 ;
if ( V_32 > V_9 -> V_78 )
return - V_71 ;
F_22 ( & V_19 -> V_59 ) ;
V_16 = F_13 ( V_19 , V_9 -> V_8 , V_32 ) ;
F_23 ( & V_19 -> V_59 ) ;
if ( V_16 < 0 )
return V_16 ;
V_9 -> V_79 = ( T_1 ) V_32 ;
return V_64 ;
}
static T_4 F_37 ( struct V_73 * V_72 ,
struct V_74 * V_75 ,
char * V_15 )
{
struct V_11 * V_12 = F_29 ( V_72 ) ;
struct V_4 * V_19 = F_17 ( V_12 ) ;
int V_16 ;
F_22 ( & V_19 -> V_59 ) ;
V_16 = F_18 ( V_19 , V_15 ) ;
F_23 ( & V_19 -> V_59 ) ;
return sprintf ( V_15 , L_12 , V_16 ? L_13 : L_14 ) ;
}
static void F_38 ( struct V_11 * V_80 )
{
int V_35 ;
T_1 V_81 [] = {
V_82 ,
V_83 ,
V_84 ,
} ;
for ( V_35 = 0 ; V_35 < F_15 ( V_81 ) ; V_35 ++ ) {
F_5 ( V_80 , V_81 [ V_35 ] , 0 ) ;
F_5 ( V_80 , V_81 [ V_35 ] + 1 , 0 ) ;
}
}
static void F_39 ( struct V_11 * V_80 ,
T_1 V_85 , T_1 * V_86 , int V_87 )
{
int V_35 ;
if ( ! V_86 || V_87 <= 0 )
return;
for ( V_35 = 0 ; V_35 < V_87 ; V_35 ++ )
F_5 ( V_80 , V_85 + V_35 , * ( V_86 + V_35 ) ) ;
F_5 ( V_80 , V_85 + V_35 , 0 ) ;
F_5 ( V_80 , V_85 + V_35 + 1 , 0 ) ;
}
static inline struct V_88 * F_40
( struct V_4 * V_19 , T_1 V_66 )
{
struct V_88 * V_89 ;
V_89 = V_19 -> V_38 -> V_90 + ( V_66 - 1 ) ;
return V_89 ;
}
static void F_41 ( int V_18 , struct V_4 * V_19 )
{
struct V_88 * V_89 ;
struct V_11 * V_80 = V_19 -> V_12 ;
int V_91 = V_19 -> V_38 -> V_91 ;
if ( V_18 > V_91 || ! ( V_19 -> V_38 -> V_90 ) )
return;
if ( V_18 == V_92 ) {
F_5 ( V_80 , V_47 , V_61 ) ;
F_11 ( 1000 , 2000 ) ;
F_5 ( V_80 , V_24 , V_23 ) ;
} else {
V_89 = F_40 ( V_19 , V_18 ) ;
if ( ! V_89 )
return;
F_5 ( V_80 , V_24 , V_21 ) ;
F_11 ( 1000 , 2000 ) ;
F_38 ( V_80 ) ;
F_39 ( V_80 , V_82 ,
V_89 -> V_93 , V_89 -> V_94 ) ;
F_39 ( V_80 , V_83 ,
V_89 -> V_95 , V_89 -> V_96 ) ;
F_39 ( V_80 , V_84 ,
V_89 -> V_97 , V_89 -> V_98 ) ;
F_5 ( V_80 , V_24 , V_63 ) ;
F_11 ( 1000 , 2000 ) ;
F_5 ( V_80 , V_47 , V_48 ) ;
}
}
static T_4 F_42 ( struct V_73 * V_72 ,
struct V_74 * V_75 ,
const char * V_15 , T_3 V_64 )
{
struct V_4 * V_19 = F_17 ( F_29 ( V_72 ) ) ;
unsigned long V_99 ;
int V_16 ;
V_16 = F_43 ( V_15 , 16 , & V_99 ) ;
if ( V_16 )
return V_16 ;
F_41 ( V_99 , V_19 ) ;
return V_64 ;
}
static int F_44 ( struct V_11 * V_12 )
{
struct V_73 * V_72 = & V_12 -> V_72 ;
return F_45 ( & V_72 -> V_100 , & V_101 ) ;
}
static void F_46 ( struct V_11 * V_12 )
{
struct V_4 * V_19 = F_17 ( V_12 ) ;
struct V_73 * V_72 = & V_12 -> V_72 ;
int V_35 ;
F_47 ( & V_72 -> V_100 , & V_101 ) ;
for ( V_35 = 0 ; V_35 < V_19 -> V_102 ; V_35 ++ )
F_47 ( & V_19 -> V_10 [ V_35 ] . V_3 . V_72 -> V_100 ,
& V_103 ) ;
}
static int T_5 F_48 ( struct V_1 * V_9 ,
struct V_11 * V_12 ,
int V_104 , struct V_105 * V_38 )
{
struct V_73 * V_72 = & V_12 -> V_72 ;
char V_106 [ 32 ] ;
int V_107 ;
if ( V_104 >= V_108 )
return - V_71 ;
if ( V_38 -> V_109 [ V_104 ] . V_79 == 0 )
return 0 ;
V_9 -> V_79 = V_38 -> V_109 [ V_104 ] . V_79 ;
V_9 -> V_78 = V_38 -> V_109 [ V_104 ] . V_78 ;
V_9 -> V_34 = V_38 -> V_109 [ V_104 ] . V_34 ;
if ( V_9 -> V_34 >= V_108 ) {
F_27 ( V_72 , L_15 ,
V_108 - 1 ) ;
return - V_71 ;
}
V_9 -> V_3 . V_110 = F_19 ;
if ( V_38 -> V_109 [ V_104 ] . V_106 ) {
V_9 -> V_3 . V_106 = V_38 -> V_109 [ V_104 ] . V_106 ;
} else {
snprintf ( V_106 , sizeof( V_106 ) , L_16 ,
V_38 -> V_111 ? : V_12 -> V_106 , V_104 ) ;
V_9 -> V_3 . V_106 = V_106 ;
}
V_107 = F_49 ( V_72 , & V_9 -> V_3 ) ;
if ( V_107 < 0 ) {
F_27 ( V_72 , L_17 , V_104 ) ;
return V_107 ;
}
V_107 = F_45 ( & V_9 -> V_3 . V_72 -> V_100 ,
& V_103 ) ;
if ( V_107 < 0 ) {
F_27 ( V_72 , L_18 ) ;
F_50 ( & V_9 -> V_3 ) ;
return V_107 ;
}
return 0 ;
}
static int T_5 F_51 ( struct V_11 * V_12 ,
const struct V_112 * V_8 )
{
struct V_4 * V_19 ;
struct V_105 * V_38 ;
int V_16 , V_35 , V_9 ;
T_1 V_15 ;
V_19 = F_52 ( sizeof( * V_19 ) , V_113 ) ;
if ( ! V_19 )
return - V_114 ;
F_53 ( V_12 , V_19 ) ;
V_19 -> V_12 = V_12 ;
V_38 = V_12 -> V_72 . V_115 ;
if ( ! V_38 ) {
F_27 ( & V_12 -> V_72 , L_19 ) ;
V_16 = - V_71 ;
goto V_116;
}
F_54 ( & V_19 -> V_59 ) ;
V_19 -> V_38 = V_38 ;
if ( V_38 -> V_117 ) {
V_16 = V_38 -> V_117 () ;
if ( V_16 < 0 )
goto V_116;
}
if ( V_38 -> V_118 ) {
V_38 -> V_118 ( 0 ) ;
F_11 ( 1000 , 2000 ) ;
V_38 -> V_118 ( 1 ) ;
F_11 ( 1000 , 2000 ) ;
}
F_5 ( V_12 , V_119 , 0xff ) ;
F_11 ( 10000 , 20000 ) ;
V_16 = F_7 ( V_12 , V_120 , & V_15 ) ;
if ( V_16 || V_15 != V_121 ) {
F_27 ( & V_12 -> V_72 , L_20 ) ;
goto V_122;
}
F_11 ( 10000 , 20000 ) ;
V_16 = F_24 ( V_12 ) ;
if ( V_16 ) {
F_27 ( & V_12 -> V_72 , L_21 ) ;
goto V_122;
}
F_55 ( & V_12 -> V_72 , L_22 , V_8 -> V_106 ) ;
V_16 = F_16 ( V_12 ) ;
if ( V_16 < 0 ) {
F_27 ( & V_12 -> V_72 , L_23 ) ;
goto V_122;
}
V_19 -> V_123 = V_38 -> V_123 ;
V_19 -> V_102 = 0 ;
V_9 = 0 ;
for ( V_35 = 0 ; V_35 < V_38 -> V_123 ; V_35 ++ ) {
if ( V_38 -> V_109 [ V_35 ] . V_79 == 0 )
continue;
V_16 = F_48 ( & V_19 -> V_10 [ V_9 ] , V_12 , V_35 , V_38 ) ;
if ( V_16 ) {
F_27 ( & V_12 -> V_72 , L_24 ) ;
goto V_124;
}
V_19 -> V_102 ++ ;
V_19 -> V_10 [ V_9 ] . V_8 = V_9 ;
F_13 ( V_19 , V_9 ,
V_19 -> V_10 [ V_9 ] . V_79 ) ;
F_56 ( & ( V_19 -> V_10 [ V_9 ] . V_56 ) ,
F_21 ) ;
V_9 ++ ;
}
V_16 = F_44 ( V_12 ) ;
if ( V_16 ) {
F_27 ( & V_12 -> V_72 , L_25 ) ;
goto V_124;
}
return V_16 ;
V_124:
for ( V_35 = 0 ; V_35 < V_19 -> V_102 ; V_35 ++ ) {
F_50 ( & V_19 -> V_10 [ V_35 ] . V_3 ) ;
F_57 ( & V_19 -> V_10 [ V_35 ] . V_56 ) ;
}
V_122:
if ( V_38 -> V_118 )
V_38 -> V_118 ( 0 ) ;
if ( V_38 -> V_125 )
V_38 -> V_125 () ;
V_116:
F_58 ( V_19 ) ;
return V_16 ;
}
static int T_6 F_59 ( struct V_11 * V_12 )
{
struct V_4 * V_19 = F_17 ( V_12 ) ;
int V_35 ;
F_41 ( V_92 , V_19 ) ;
F_46 ( V_12 ) ;
for ( V_35 = 0 ; V_35 < V_19 -> V_102 ; V_35 ++ ) {
F_50 ( & V_19 -> V_10 [ V_35 ] . V_3 ) ;
F_57 ( & V_19 -> V_10 [ V_35 ] . V_56 ) ;
}
if ( V_19 -> V_38 -> V_118 )
V_19 -> V_38 -> V_118 ( 0 ) ;
if ( V_19 -> V_38 -> V_125 )
V_19 -> V_38 -> V_125 () ;
F_58 ( V_19 ) ;
return 0 ;
}
