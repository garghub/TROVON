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
return V_16 ;
* V_15 = V_16 ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , T_1 V_17 )
{
struct V_4 * V_18 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_18 -> V_12 ;
int V_16 ;
T_1 V_19 ;
if ( V_17 == V_20 )
return 0 ;
if ( V_17 == V_21 )
V_17 = V_22 ;
V_16 = F_7 ( V_12 , V_23 , & V_19 ) ;
if ( V_16 < 0 )
return V_16 ;
V_19 &= ~ ( V_6 -> V_24 ) ;
V_17 &= V_6 -> V_24 ;
V_19 |= V_17 ;
return F_5 ( V_12 , V_23 , V_19 ) ;
}
static int F_10 ( struct V_5 * V_25 , const T_1 * V_26 )
{
struct V_4 * V_18 = F_3 ( V_25 ) ;
struct V_11 * V_12 = V_18 -> V_12 ;
int V_16 ;
int V_27 ;
T_1 V_17 ;
V_16 = F_9 ( V_25 , V_22 ) ;
if ( V_16 )
return V_16 ;
F_11 ( 1000 , 2000 ) ;
V_16 = F_7 ( V_12 , V_23 , & V_17 ) ;
if ( V_16 )
return V_16 ;
F_5 ( V_12 , V_23 , V_22 ) ;
F_11 ( 1000 , 2000 ) ;
F_5 ( V_12 , V_23 , V_20 ) ;
F_11 ( 1000 , 2000 ) ;
V_27 = V_28 + V_25 -> V_29 * V_30 ;
F_12 ( V_12 ,
V_27 ,
V_30 ,
V_26 ) ;
return F_5 ( V_12 , V_23 , V_17 ) ;
}
static int F_13 ( struct V_4 * V_18 , int V_9 , T_1 V_31 )
{
return F_5 ( V_18 -> V_12 ,
V_32 + V_18 -> V_10 [ V_9 ] . V_33 ,
V_31 ) ;
}
static void F_14 ( struct V_4 * V_18 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < F_15 ( V_18 -> V_7 ) ; V_34 ++ ) {
V_18 -> V_7 [ V_34 ] . V_8 = V_34 + 1 ;
V_18 -> V_7 [ V_34 ] . V_24 = V_35 >> ( V_34 * 2 ) ;
V_18 -> V_7 [ V_34 ] . V_29 = V_34 ;
}
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_4 * V_18 = F_17 ( V_12 ) ;
int V_16 ;
T_1 V_36 ;
F_14 ( V_18 ) ;
V_16 = F_5 ( V_12 , V_23 , V_22 ) ;
V_36 = V_18 -> V_37 -> V_38 ?
: ( V_39 | V_40 | V_41 ) ;
V_16 |= F_5 ( V_12 , V_42 , V_36 ) ;
V_16 |= F_5 ( V_12 , V_43 , 0 ) ;
V_16 |= F_5 ( V_12 , V_44 , 0 ) ;
V_16 |= F_5 ( V_12 , V_45 , 0 ) ;
V_16 |= F_5 ( V_12 , V_46 ,
V_47 ) ;
F_11 ( 1000 , 2000 ) ;
return V_16 ;
}
static int F_18 ( struct V_4 * V_18 , char * V_15 )
{
int V_16 ;
T_1 V_48 ;
V_16 = F_7 ( V_18 -> V_12 , V_49 , & V_48 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_18 -> V_37 && V_18 -> V_37 -> V_50 == V_51 )
if ( ( V_48 & V_52 ) == 0 )
return - V_53 ;
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
struct V_4 * V_18 = F_4 ( V_9 ) ;
struct V_11 * V_12 = V_18 -> V_12 ;
F_22 ( & V_18 -> V_59 ) ;
F_5 ( V_12 , V_60 + V_9 -> V_33 ,
V_9 -> V_55 ) ;
F_23 ( & V_18 -> V_59 ) ;
}
static int F_24 ( struct V_11 * V_12 )
{
int V_16 ;
T_1 V_15 ;
V_16 = F_5 ( V_12 , V_46 , V_61 ) ;
if ( V_16 )
return V_16 ;
F_11 ( 1000 , 2000 ) ;
V_16 = F_7 ( V_12 , V_46 , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 != V_61 )
return - V_62 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 , T_1 V_17 )
{
int V_16 = 0 ;
if ( V_17 == V_6 -> V_17 && V_17 != V_63 )
return 0 ;
if ( V_17 == V_63 ) {
V_16 = F_9 ( V_6 , V_63 ) ;
} else if ( V_17 == V_20 ) {
F_9 ( V_6 , V_21 ) ;
F_9 ( V_6 , V_20 ) ;
} else if ( V_17 == V_21 ) {
F_9 ( V_6 , V_21 ) ;
}
V_6 -> V_17 = V_17 ;
return V_16 ;
}
static int F_26 ( struct V_5 * V_6 ,
const char * V_15 , T_3 V_64 )
{
struct V_4 * V_18 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_18 -> V_12 ;
int V_16 , V_65 , V_66 = 0 , V_34 = 0 ;
char V_67 [ 3 ] ;
unsigned V_68 ;
T_1 V_26 [ V_69 ] = { 0 } ;
while ( ( V_66 < V_64 - 1 ) && ( V_34 < V_69 ) ) {
V_16 = sscanf ( V_15 + V_66 , L_1 , V_67 , & V_65 ) ;
if ( V_16 != 2 )
goto V_70;
V_16 = sscanf ( V_67 , L_2 , & V_68 ) ;
if ( V_16 != 1 )
goto V_70;
V_26 [ V_34 ] = ( T_1 ) V_68 ;
V_66 += V_65 ;
V_34 ++ ;
}
if ( V_34 % 2 )
goto V_70;
F_22 ( & V_18 -> V_59 ) ;
if ( V_6 -> V_17 == V_20 )
V_16 = F_10 ( V_6 , V_26 ) ;
else
V_16 = - V_71 ;
F_23 ( & V_18 -> V_59 ) ;
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
struct V_4 * V_18 = F_17 ( V_12 ) ;
return F_26 ( & V_18 -> V_7 [ V_76 - 1 ] , V_15 , V_64 ) ;
}
static T_4 F_30 ( struct V_73 * V_72 ,
struct V_74 * V_75 ,
char * V_15 , int V_76 )
{
struct V_11 * V_12 = F_29 ( V_72 ) ;
struct V_4 * V_18 = F_17 ( V_12 ) ;
switch ( V_18 -> V_7 [ V_76 - 1 ] . V_17 ) {
case V_63 :
return sprintf ( V_15 , L_5 ) ;
case V_20 :
return sprintf ( V_15 , L_6 ) ;
case V_21 :
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
struct V_4 * V_18 = F_17 ( V_12 ) ;
struct V_5 * V_6 = & V_18 -> V_7 [ V_76 - 1 ] ;
F_22 ( & V_18 -> V_59 ) ;
if ( ! strncmp ( V_15 , L_8 , 3 ) )
F_25 ( V_6 , V_63 ) ;
else if ( ! strncmp ( V_15 , L_9 , 4 ) )
F_25 ( V_6 , V_20 ) ;
else if ( ! strncmp ( V_15 , L_10 , 8 ) )
F_25 ( V_6 , V_21 ) ;
F_23 ( & V_18 -> V_59 ) ;
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
struct V_4 * V_18 = F_4 ( V_9 ) ;
T_4 V_16 ;
unsigned long V_31 ;
if ( F_36 ( V_15 , 0 , & V_31 ) )
return - V_71 ;
if ( V_31 > V_9 -> V_78 )
return - V_71 ;
F_22 ( & V_18 -> V_59 ) ;
V_16 = F_13 ( V_18 , V_9 -> V_8 , V_31 ) ;
F_23 ( & V_18 -> V_59 ) ;
if ( V_16 < 0 )
return V_16 ;
V_9 -> V_79 = ( T_1 ) V_31 ;
return V_64 ;
}
static T_4 F_37 ( struct V_73 * V_72 ,
struct V_74 * V_75 ,
char * V_15 )
{
struct V_11 * V_12 = F_29 ( V_72 ) ;
struct V_4 * V_18 = F_17 ( V_12 ) ;
int V_16 ;
F_22 ( & V_18 -> V_59 ) ;
V_16 = F_18 ( V_18 , V_15 ) ;
F_23 ( & V_18 -> V_59 ) ;
return sprintf ( V_15 , L_12 , V_16 ? L_13 : L_14 ) ;
}
static void F_38 ( struct V_11 * V_80 )
{
int V_34 ;
T_1 V_81 [] = {
V_82 ,
V_83 ,
V_84 ,
} ;
for ( V_34 = 0 ; V_34 < F_15 ( V_81 ) ; V_34 ++ ) {
F_5 ( V_80 , V_81 [ V_34 ] , 0 ) ;
F_5 ( V_80 , V_81 [ V_34 ] + 1 , 0 ) ;
}
}
static void F_39 ( struct V_11 * V_80 ,
T_1 V_85 , T_1 * V_86 , int V_87 )
{
int V_34 ;
if ( ! V_86 || V_87 <= 0 )
return;
for ( V_34 = 0 ; V_34 < V_87 ; V_34 ++ )
F_5 ( V_80 , V_85 + V_34 , * ( V_86 + V_34 ) ) ;
F_5 ( V_80 , V_85 + V_34 , 0 ) ;
F_5 ( V_80 , V_85 + V_34 + 1 , 0 ) ;
}
static inline struct V_88 * F_40
( struct V_4 * V_18 , T_1 V_66 )
{
struct V_88 * V_89 ;
V_89 = V_18 -> V_37 -> V_90 + ( V_66 - 1 ) ;
return V_89 ;
}
static void F_41 ( int V_17 , struct V_4 * V_18 )
{
struct V_88 * V_89 ;
struct V_11 * V_80 = V_18 -> V_12 ;
int V_91 = V_18 -> V_37 -> V_91 ;
if ( V_17 > V_91 || ! ( V_18 -> V_37 -> V_90 ) )
return;
if ( V_17 == V_92 ) {
F_5 ( V_80 , V_46 , V_61 ) ;
F_11 ( 1000 , 2000 ) ;
F_5 ( V_80 , V_23 , V_22 ) ;
} else {
V_89 = F_40 ( V_18 , V_17 ) ;
if ( ! V_89 )
return;
F_5 ( V_80 , V_23 , V_20 ) ;
F_11 ( 1000 , 2000 ) ;
F_38 ( V_80 ) ;
F_39 ( V_80 , V_82 ,
V_89 -> V_93 , V_89 -> V_94 ) ;
F_39 ( V_80 , V_83 ,
V_89 -> V_95 , V_89 -> V_96 ) ;
F_39 ( V_80 , V_84 ,
V_89 -> V_97 , V_89 -> V_98 ) ;
F_5 ( V_80 , V_23 , V_63 ) ;
F_11 ( 1000 , 2000 ) ;
F_5 ( V_80 , V_46 , V_47 ) ;
}
}
static T_4 F_42 ( struct V_73 * V_72 ,
struct V_74 * V_75 ,
const char * V_15 , T_3 V_64 )
{
struct V_4 * V_18 = F_17 ( F_29 ( V_72 ) ) ;
unsigned long V_99 ;
int V_16 ;
V_16 = F_36 ( V_15 , 16 , & V_99 ) ;
if ( V_16 )
return V_16 ;
F_41 ( V_99 , V_18 ) ;
return V_64 ;
}
static int F_43 ( struct V_11 * V_12 )
{
struct V_73 * V_72 = & V_12 -> V_72 ;
return F_44 ( & V_72 -> V_100 , & V_101 ) ;
}
static void F_45 ( struct V_11 * V_12 )
{
struct V_4 * V_18 = F_17 ( V_12 ) ;
struct V_73 * V_72 = & V_12 -> V_72 ;
int V_34 ;
F_46 ( & V_72 -> V_100 , & V_101 ) ;
for ( V_34 = 0 ; V_34 < V_18 -> V_102 ; V_34 ++ )
F_46 ( & V_18 -> V_10 [ V_34 ] . V_3 . V_72 -> V_100 ,
& V_103 ) ;
}
static int F_47 ( struct V_1 * V_9 ,
struct V_11 * V_12 ,
int V_104 , struct V_105 * V_37 )
{
struct V_73 * V_72 = & V_12 -> V_72 ;
char V_106 [ 32 ] ;
int V_107 ;
if ( V_104 >= V_108 )
return - V_71 ;
if ( V_37 -> V_109 [ V_104 ] . V_79 == 0 )
return 0 ;
V_9 -> V_79 = V_37 -> V_109 [ V_104 ] . V_79 ;
V_9 -> V_78 = V_37 -> V_109 [ V_104 ] . V_78 ;
V_9 -> V_33 = V_37 -> V_109 [ V_104 ] . V_33 ;
if ( V_9 -> V_33 >= V_108 ) {
F_27 ( V_72 , L_15 ,
V_108 - 1 ) ;
return - V_71 ;
}
V_9 -> V_3 . V_110 = F_19 ;
if ( V_37 -> V_109 [ V_104 ] . V_106 ) {
V_9 -> V_3 . V_106 = V_37 -> V_109 [ V_104 ] . V_106 ;
} else {
snprintf ( V_106 , sizeof( V_106 ) , L_16 ,
V_37 -> V_111 ? : V_12 -> V_106 , V_104 ) ;
V_9 -> V_3 . V_106 = V_106 ;
}
V_107 = F_48 ( V_72 , & V_9 -> V_3 ) ;
if ( V_107 < 0 ) {
F_27 ( V_72 , L_17 , V_104 ) ;
return V_107 ;
}
V_107 = F_44 ( & V_9 -> V_3 . V_72 -> V_100 ,
& V_103 ) ;
if ( V_107 < 0 ) {
F_27 ( V_72 , L_18 ) ;
F_49 ( & V_9 -> V_3 ) ;
return V_107 ;
}
return 0 ;
}
static int F_50 ( struct V_11 * V_12 ,
const struct V_112 * V_8 )
{
struct V_4 * V_18 ;
struct V_105 * V_37 ;
int V_16 , V_34 , V_9 ;
T_1 V_15 ;
V_18 = F_51 ( & V_12 -> V_72 , sizeof( * V_18 ) , V_113 ) ;
if ( ! V_18 )
return - V_114 ;
F_52 ( V_12 , V_18 ) ;
V_18 -> V_12 = V_12 ;
V_37 = V_12 -> V_72 . V_115 ;
if ( ! V_37 ) {
F_27 ( & V_12 -> V_72 , L_19 ) ;
return - V_71 ;
}
F_53 ( & V_18 -> V_59 ) ;
V_18 -> V_37 = V_37 ;
if ( V_37 -> V_116 ) {
V_16 = V_37 -> V_116 () ;
if ( V_16 < 0 )
return V_16 ;
}
if ( V_37 -> V_117 ) {
V_37 -> V_117 ( 0 ) ;
F_11 ( 1000 , 2000 ) ;
V_37 -> V_117 ( 1 ) ;
F_11 ( 1000 , 2000 ) ;
}
F_5 ( V_12 , V_118 , 0xff ) ;
F_11 ( 10000 , 20000 ) ;
V_16 = F_7 ( V_12 , V_119 , & V_15 ) ;
if ( V_16 ) {
F_27 ( & V_12 -> V_72 , L_20 ) ;
goto V_120;
}
if ( V_15 != V_121 ) {
F_27 ( & V_12 -> V_72 ,
L_21 ,
V_121 , V_15 ) ;
V_16 = - V_71 ;
goto V_120;
}
F_11 ( 10000 , 20000 ) ;
V_16 = F_24 ( V_12 ) ;
if ( V_16 ) {
F_27 ( & V_12 -> V_72 , L_22 ) ;
goto V_120;
}
F_54 ( & V_12 -> V_72 , L_23 , V_8 -> V_106 ) ;
V_16 = F_16 ( V_12 ) ;
if ( V_16 < 0 ) {
F_27 ( & V_12 -> V_72 , L_24 ) ;
goto V_122;
}
V_18 -> V_123 = V_37 -> V_123 ;
V_18 -> V_102 = 0 ;
V_9 = 0 ;
for ( V_34 = 0 ; V_34 < V_37 -> V_123 ; V_34 ++ ) {
if ( V_37 -> V_109 [ V_34 ] . V_79 == 0 )
continue;
V_16 = F_47 ( & V_18 -> V_10 [ V_9 ] , V_12 , V_34 , V_37 ) ;
if ( V_16 ) {
F_27 ( & V_12 -> V_72 , L_25 ) ;
goto V_120;
}
V_18 -> V_102 ++ ;
V_18 -> V_10 [ V_9 ] . V_8 = V_9 ;
F_13 ( V_18 , V_9 ,
V_18 -> V_10 [ V_9 ] . V_79 ) ;
F_55 ( & ( V_18 -> V_10 [ V_9 ] . V_56 ) ,
F_21 ) ;
V_9 ++ ;
}
V_16 = F_43 ( V_12 ) ;
if ( V_16 ) {
F_27 ( & V_12 -> V_72 , L_26 ) ;
goto V_120;
}
return V_16 ;
V_120:
for ( V_34 = 0 ; V_34 < V_18 -> V_102 ; V_34 ++ ) {
F_49 ( & V_18 -> V_10 [ V_34 ] . V_3 ) ;
F_56 ( & V_18 -> V_10 [ V_34 ] . V_56 ) ;
}
V_122:
if ( V_37 -> V_117 )
V_37 -> V_117 ( 0 ) ;
if ( V_37 -> V_124 )
V_37 -> V_124 () ;
return V_16 ;
}
static int F_57 ( struct V_11 * V_12 )
{
struct V_4 * V_18 = F_17 ( V_12 ) ;
int V_34 ;
F_41 ( V_92 , V_18 ) ;
F_45 ( V_12 ) ;
for ( V_34 = 0 ; V_34 < V_18 -> V_102 ; V_34 ++ ) {
F_49 ( & V_18 -> V_10 [ V_34 ] . V_3 ) ;
F_56 ( & V_18 -> V_10 [ V_34 ] . V_56 ) ;
}
if ( V_18 -> V_37 -> V_117 )
V_18 -> V_37 -> V_117 ( 0 ) ;
if ( V_18 -> V_37 -> V_124 )
V_18 -> V_37 -> V_124 () ;
return 0 ;
}
