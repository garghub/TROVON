static struct V_1 * F_1 ( struct V_2 * V_2 ,
T_1 V_3 ,
enum V_4 V_5 )
{
return & V_2 -> V_6 . V_7 [ V_5 ] [ V_3 ] ;
}
static struct V_8 * F_2 ( struct V_2 * V_2 ,
T_1 V_9 , T_1 V_10 ,
enum V_4 V_5 )
{
return & V_2 -> V_6 . V_11 [ V_9 ] . V_12 [ V_5 ] [ V_10 ] ;
}
static struct V_13 * F_3 ( struct V_2 * V_2 ,
T_1 V_9 , T_1 V_3 ,
enum V_4 V_5 )
{
return & V_2 -> V_6 . V_11 [ V_9 ] . V_14 [ V_5 ] [ V_3 ] ;
}
static int F_4 ( struct V_2 * V_2 , T_1 V_3 ,
enum V_4 V_5 ,
enum V_15 V_16 , T_2 V_17 )
{
char V_18 [ V_19 ] ;
struct V_1 * V_20 ;
int V_21 ;
F_5 ( V_18 , V_3 , V_5 , V_16 , V_17 ) ;
V_21 = F_6 ( V_2 -> V_22 , F_7 ( V_23 ) , V_18 ) ;
if ( V_21 )
return V_21 ;
V_20 = F_1 ( V_2 , V_3 , V_5 ) ;
V_20 -> V_16 = V_16 ;
V_20 -> V_17 = V_17 ;
return 0 ;
}
static int F_8 ( struct V_2 * V_2 , T_1 V_9 ,
T_1 V_10 , enum V_4 V_5 ,
T_2 V_24 , T_2 V_25 , T_1 V_3 )
{
char V_26 [ V_27 ] ;
int V_21 ;
F_9 ( V_26 , V_9 , V_10 , V_5 ,
V_24 , V_25 , V_3 ) ;
V_21 = F_6 ( V_2 -> V_22 , F_7 ( V_28 ) , V_26 ) ;
if ( V_21 )
return V_21 ;
if ( V_10 < V_29 ) {
struct V_8 * V_30 ;
V_30 = F_2 ( V_2 , V_9 , V_10 , V_5 ) ;
V_30 -> V_24 = V_24 ;
V_30 -> V_25 = V_25 ;
V_30 -> V_3 = V_3 ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_2 , T_1 V_9 ,
T_1 V_3 , enum V_4 V_5 ,
T_2 V_24 , T_2 V_25 )
{
char V_31 [ V_32 ] ;
struct V_13 * V_33 ;
int V_21 ;
F_11 ( V_31 , V_9 , V_3 , V_5 , false ,
V_24 , V_25 ) ;
V_21 = F_6 ( V_2 -> V_22 , F_7 ( V_34 ) , V_31 ) ;
if ( V_21 )
return V_21 ;
V_33 = F_3 ( V_2 , V_9 , V_3 , V_5 ) ;
V_33 -> V_24 = V_24 ;
V_33 -> V_25 = V_25 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_2 , T_1 V_9 ,
T_1 V_3 , enum V_4 V_5 ,
struct V_35 * V_36 )
{
char V_31 [ V_32 ] ;
F_11 ( V_31 , V_9 , V_3 , V_5 , true , 0 , 0 ) ;
return F_13 ( V_2 -> V_22 , F_7 ( V_34 ) , V_31 ,
V_36 , NULL , 0 ) ;
}
static void F_14 ( struct V_37 * V_37 ,
char * V_31 , T_3 V_38 ,
unsigned long V_39 )
{
struct V_13 * V_33 = (struct V_13 * ) V_39 ;
F_15 ( V_31 , & V_33 -> V_40 . V_41 , & V_33 -> V_40 . V_42 ) ;
}
static int F_16 ( struct V_2 * V_2 , T_1 V_9 ,
T_1 V_3 , enum V_4 V_5 ,
struct V_35 * V_36 )
{
char V_31 [ V_32 ] ;
struct V_13 * V_33 ;
V_33 = F_3 ( V_2 , V_9 , V_3 , V_5 ) ;
F_11 ( V_31 , V_9 , V_3 , V_5 , false , 0 , 0 ) ;
return F_13 ( V_2 -> V_22 , F_7 ( V_34 ) , V_31 ,
V_36 ,
F_14 ,
( unsigned long ) V_33 ) ;
}
static int F_17 ( struct V_43 * V_43 )
{
struct V_2 * V_2 = V_43 -> V_2 ;
char V_44 [ V_45 ] ;
int V_46 ;
F_18 ( V_44 , V_43 -> V_9 ,
0xffff , 0xffff / 2 ) ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
T_4 V_17 = F_19 ( V_2 , V_48 [ V_46 ] ) ;
if ( V_46 == V_49 )
continue;
F_20 ( V_44 , V_46 , V_17 ) ;
}
F_20 ( V_44 ,
V_50 , 0 ) ;
return F_6 ( V_2 -> V_22 , F_7 ( V_51 ) , V_44 ) ;
}
static int F_21 ( struct V_43 * V_43 )
{
char V_52 [ V_53 ] ;
int V_46 ;
F_22 ( V_52 , V_43 -> V_9 ) ;
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ )
F_23 ( V_52 , V_46 , 0 ) ;
return F_6 ( V_43 -> V_2 -> V_22 , F_7 ( V_55 ) ,
V_52 ) ;
}
static int F_24 ( struct V_43 * V_43 )
{
int V_21 ;
V_21 = F_17 ( V_43 ) ;
if ( V_21 )
return V_21 ;
return F_21 ( V_43 ) ;
}
static int F_25 ( struct V_2 * V_2 )
{
unsigned int V_56 = F_26 ( V_2 -> V_22 ) ;
V_2 -> V_6 . V_11 = F_27 ( V_56 , sizeof( struct V_57 ) ,
V_58 ) ;
if ( ! V_2 -> V_6 . V_11 )
return - V_59 ;
return 0 ;
}
static void F_28 ( struct V_2 * V_2 )
{
F_29 ( V_2 -> V_6 . V_11 ) ;
}
static int F_30 ( struct V_2 * V_2 ,
enum V_4 V_5 ,
const struct V_1 * V_7 ,
T_3 V_60 )
{
int V_46 ;
int V_21 ;
for ( V_46 = 0 ; V_46 < V_60 ; V_46 ++ ) {
T_2 V_17 = F_19 ( V_2 , V_7 [ V_46 ] . V_17 ) ;
V_21 = F_4 ( V_2 , V_46 , V_5 , V_7 [ V_46 ] . V_16 , V_17 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_31 ( struct V_2 * V_2 )
{
int V_21 ;
V_21 = F_30 ( V_2 , V_61 ,
V_62 ,
V_63 ) ;
if ( V_21 )
return V_21 ;
return F_30 ( V_2 , V_64 ,
V_65 ,
V_66 ) ;
}
static int F_32 ( struct V_2 * V_2 , T_1 V_9 ,
enum V_4 V_5 ,
const struct V_8 * V_12 ,
T_3 V_67 )
{
int V_46 ;
int V_21 ;
for ( V_46 = 0 ; V_46 < V_67 ; V_46 ++ ) {
const struct V_8 * V_30 ;
T_2 V_24 ;
if ( V_46 == 8 && V_5 == V_61 )
continue;
V_30 = & V_12 [ V_46 ] ;
V_24 = F_19 ( V_2 , V_30 -> V_24 ) ;
V_21 = F_8 ( V_2 , V_9 , V_46 , V_5 ,
V_24 , V_30 -> V_25 , V_30 -> V_3 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_33 ( struct V_43 * V_43 )
{
int V_21 ;
V_21 = F_32 ( V_43 -> V_2 ,
V_43 -> V_9 ,
V_61 ,
V_68 ,
V_69 ) ;
if ( V_21 )
return V_21 ;
return F_32 ( V_43 -> V_2 ,
V_43 -> V_9 ,
V_64 ,
V_70 ,
V_71 ) ;
}
static int F_34 ( struct V_2 * V_2 )
{
return F_32 ( V_2 , 0 , V_64 ,
V_72 ,
V_73 ) ;
}
static int F_35 ( struct V_2 * V_2 , T_1 V_9 ,
enum V_4 V_5 ,
const struct V_13 * V_14 ,
T_3 V_74 )
{
int V_46 ;
int V_21 ;
for ( V_46 = 0 ; V_46 < V_74 ; V_46 ++ ) {
const struct V_13 * V_33 ;
V_33 = & V_14 [ V_46 ] ;
V_21 = F_10 ( V_2 , V_9 , V_46 , V_5 ,
V_33 -> V_24 , V_33 -> V_25 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_36 ( struct V_43 * V_43 )
{
int V_21 ;
V_21 = F_35 ( V_43 -> V_2 ,
V_43 -> V_9 ,
V_61 ,
V_75 ,
V_76 ) ;
if ( V_21 )
return V_21 ;
return F_35 ( V_43 -> V_2 ,
V_43 -> V_9 ,
V_64 ,
V_77 ,
V_78 ) ;
}
static int F_37 ( struct V_2 * V_2 )
{
char V_79 [ V_80 ] ;
int V_46 ;
int V_21 ;
for ( V_46 = 0 ; V_46 < V_81 ; V_46 ++ ) {
const struct V_82 * V_83 ;
T_2 V_24 ;
V_83 = & V_84 [ V_46 ] ;
V_24 = F_19 ( V_2 , V_83 -> V_24 ) ;
F_38 ( V_79 , V_46 , V_24 , V_83 -> V_25 ,
V_83 -> V_3 ) ;
V_21 = F_6 ( V_2 -> V_22 , F_7 ( V_85 ) , V_79 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
int F_39 ( struct V_2 * V_2 )
{
T_5 V_86 ;
int V_21 ;
if ( ! F_40 ( V_2 -> V_22 , V_87 ) )
return - V_88 ;
V_2 -> V_6 . V_89 = F_41 ( V_2 -> V_22 , V_87 ) ;
if ( ! F_40 ( V_2 -> V_22 , V_90 ) )
return - V_88 ;
V_86 = F_41 ( V_2 -> V_22 , V_90 ) ;
V_21 = F_25 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_31 ( V_2 ) ;
if ( V_21 )
goto V_91;
V_21 = F_34 ( V_2 ) ;
if ( V_21 )
goto V_92;
V_21 = F_37 ( V_2 ) ;
if ( V_21 )
goto V_93;
V_21 = F_42 ( F_43 ( V_2 -> V_22 ) , 0 , V_86 ,
V_94 ,
V_94 ,
V_29 ,
V_29 ) ;
if ( V_21 )
goto V_95;
return 0 ;
V_95:
V_93:
V_92:
V_91:
F_28 ( V_2 ) ;
return V_21 ;
}
void F_44 ( struct V_2 * V_2 )
{
F_45 ( F_43 ( V_2 -> V_22 ) , 0 ) ;
F_28 ( V_2 ) ;
}
int F_46 ( struct V_43 * V_43 )
{
int V_21 ;
V_21 = F_24 ( V_43 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_33 ( V_43 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_36 ( V_43 ) ;
return V_21 ;
}
static T_1 F_47 ( T_4 V_96 )
{
return V_96 % V_94 ;
}
static T_4 F_48 ( T_1 V_3 , enum V_4 V_5 )
{
T_4 V_96 ;
V_96 = V_3 ;
if ( V_5 == V_64 )
V_96 += V_94 ;
return V_96 ;
}
static enum V_4 F_49 ( T_4 V_96 )
{
return V_96 < V_94 ?
V_61 : V_64 ;
}
int F_50 ( struct V_37 * V_37 ,
unsigned int V_97 , T_4 V_96 ,
struct V_98 * V_99 )
{
struct V_2 * V_2 = F_51 ( V_37 ) ;
T_1 V_3 = F_47 ( V_96 ) ;
enum V_4 V_5 = F_49 ( V_96 ) ;
struct V_1 * V_20 = F_1 ( V_2 , V_3 , V_5 ) ;
V_99 -> V_100 = (enum V_101 ) V_5 ;
V_99 -> V_17 = F_52 ( V_2 , V_20 -> V_17 ) ;
V_99 -> V_102 = (enum V_103 ) V_20 -> V_16 ;
return 0 ;
}
int F_53 ( struct V_37 * V_37 ,
unsigned int V_97 , T_4 V_96 , T_2 V_17 ,
enum V_103 V_102 )
{
struct V_2 * V_2 = F_51 ( V_37 ) ;
T_2 V_104 = F_19 ( V_2 , V_17 ) ;
T_1 V_3 = F_47 ( V_96 ) ;
enum V_4 V_5 = F_49 ( V_96 ) ;
enum V_15 V_16 ;
if ( V_17 > F_41 ( V_2 -> V_22 , V_90 ) )
return - V_105 ;
V_16 = (enum V_15 ) V_102 ;
return F_4 ( V_2 , V_3 , V_5 , V_16 , V_104 ) ;
}
static T_2 F_54 ( struct V_2 * V_2 , T_1 V_3 ,
enum V_4 V_5 , T_2 V_25 )
{
struct V_1 * V_20 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_20 -> V_16 == V_106 )
return V_25 - V_107 ;
return F_52 ( V_2 , V_25 ) ;
}
static int F_55 ( struct V_2 * V_2 , T_1 V_3 ,
enum V_4 V_5 , T_2 V_108 ,
T_2 * V_109 )
{
struct V_1 * V_20 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_20 -> V_16 == V_106 ) {
int V_110 ;
V_110 = V_108 + V_107 ;
if ( V_110 < V_111 ||
V_110 > V_112 )
return - V_105 ;
* V_109 = V_110 ;
} else {
* V_109 = F_19 ( V_2 , V_108 ) ;
}
return 0 ;
}
int F_56 ( struct V_113 * V_113 ,
unsigned int V_97 , T_4 V_96 ,
T_2 * V_114 )
{
struct V_43 * V_43 =
F_57 ( V_113 ) ;
struct V_2 * V_2 = V_43 -> V_2 ;
T_1 V_9 = V_43 -> V_9 ;
T_1 V_3 = F_47 ( V_96 ) ;
enum V_4 V_5 = F_49 ( V_96 ) ;
struct V_13 * V_33 = F_3 ( V_2 , V_9 ,
V_3 , V_5 ) ;
* V_114 = F_54 ( V_2 , V_3 , V_5 ,
V_33 -> V_25 ) ;
return 0 ;
}
int F_58 ( struct V_113 * V_113 ,
unsigned int V_97 , T_4 V_96 ,
T_2 V_108 )
{
struct V_43 * V_43 =
F_57 ( V_113 ) ;
struct V_2 * V_2 = V_43 -> V_2 ;
T_1 V_9 = V_43 -> V_9 ;
T_1 V_3 = F_47 ( V_96 ) ;
enum V_4 V_5 = F_49 ( V_96 ) ;
T_2 V_25 ;
int V_21 ;
V_21 = F_55 ( V_2 , V_3 , V_5 ,
V_108 , & V_25 ) ;
if ( V_21 )
return V_21 ;
return F_10 ( V_2 , V_9 , V_3 , V_5 ,
0 , V_25 ) ;
}
int F_59 ( struct V_113 * V_113 ,
unsigned int V_97 , T_4 V_115 ,
enum V_101 V_100 ,
T_4 * V_116 , T_2 * V_114 )
{
struct V_43 * V_43 =
F_57 ( V_113 ) ;
struct V_2 * V_2 = V_43 -> V_2 ;
T_1 V_9 = V_43 -> V_9 ;
T_1 V_10 = V_115 ;
enum V_4 V_5 = (enum V_4 ) V_100 ;
struct V_8 * V_30 = F_2 ( V_2 , V_9 ,
V_10 , V_5 ) ;
* V_114 = F_54 ( V_2 , V_30 -> V_3 , V_5 ,
V_30 -> V_25 ) ;
* V_116 = F_48 ( V_30 -> V_3 , V_5 ) ;
return 0 ;
}
int F_60 ( struct V_113 * V_113 ,
unsigned int V_97 , T_4 V_115 ,
enum V_101 V_100 ,
T_4 V_96 , T_2 V_108 )
{
struct V_43 * V_43 =
F_57 ( V_113 ) ;
struct V_2 * V_2 = V_43 -> V_2 ;
T_1 V_9 = V_43 -> V_9 ;
T_1 V_10 = V_115 ;
enum V_4 V_5 = (enum V_4 ) V_100 ;
T_1 V_3 = F_47 ( V_96 ) ;
T_2 V_25 ;
int V_21 ;
if ( V_5 != F_49 ( V_96 ) )
return - V_105 ;
V_21 = F_55 ( V_2 , V_3 , V_5 ,
V_108 , & V_25 ) ;
if ( V_21 )
return V_21 ;
return F_8 ( V_2 , V_9 , V_10 , V_5 ,
0 , V_25 , V_3 ) ;
}
static void F_61 ( struct V_37 * V_37 ,
char * V_117 , T_3 V_118 ,
unsigned long V_39 )
{
struct V_2 * V_2 = F_51 ( V_37 ) ;
struct V_119 V_120 ;
T_1 V_121 ;
T_1 V_9 ;
int V_122 = 0 ;
struct V_8 * V_30 ;
int V_46 ;
memcpy ( & V_120 , & V_39 , sizeof( V_120 ) ) ;
V_121 = 0 ;
for ( V_9 = V_120 . V_123 ;
V_9 < F_26 ( V_37 ) ; V_9 ++ ) {
if ( ! V_2 -> V_11 [ V_9 ] )
continue;
for ( V_46 = 0 ; V_46 < V_29 ; V_46 ++ ) {
V_30 = F_2 ( V_2 , V_9 , V_46 ,
V_61 ) ;
F_62 ( V_117 , V_122 ++ ,
& V_30 -> V_40 . V_41 , & V_30 -> V_40 . V_42 ) ;
}
if ( ++ V_121 == V_120 . V_121 )
break;
}
V_121 = 0 ;
for ( V_9 = V_120 . V_123 ;
V_9 < F_26 ( V_37 ) ; V_9 ++ ) {
if ( ! V_2 -> V_11 [ V_9 ] )
continue;
for ( V_46 = 0 ; V_46 < V_29 ; V_46 ++ ) {
V_30 = F_2 ( V_2 , V_9 , V_46 ,
V_64 ) ;
F_62 ( V_117 , V_122 ++ ,
& V_30 -> V_40 . V_41 , & V_30 -> V_40 . V_42 ) ;
}
if ( ++ V_121 == V_120 . V_121 )
break;
}
}
int F_63 ( struct V_37 * V_37 ,
unsigned int V_97 )
{
struct V_2 * V_2 = F_51 ( V_37 ) ;
struct V_119 V_120 ;
unsigned long V_39 ;
F_64 ( V_36 ) ;
char * V_117 ;
T_1 V_121 ;
T_1 V_123 ;
T_1 V_9 = 0 ;
int V_46 ;
int V_21 ;
int V_124 ;
V_117 = F_65 ( V_125 , V_58 ) ;
if ( ! V_117 )
return - V_59 ;
V_126:
V_9 ++ ;
V_123 = V_9 ;
V_121 = 0 ;
F_66 ( V_117 , false ) ;
for ( V_46 = 0 ; V_46 < V_29 ; V_46 ++ ) {
F_67 ( V_117 , V_46 , 1 ) ;
F_68 ( V_117 , V_46 , 1 ) ;
}
for (; V_9 < F_26 ( V_37 ) ; V_9 ++ ) {
if ( ! V_2 -> V_11 [ V_9 ] )
continue;
F_69 ( V_117 , V_9 , 1 ) ;
F_70 ( V_117 , V_9 , 1 ) ;
for ( V_46 = 0 ; V_46 < V_94 ; V_46 ++ ) {
V_21 = F_16 ( V_2 , V_9 , V_46 ,
V_61 ,
& V_36 ) ;
if ( V_21 )
goto V_127;
V_21 = F_16 ( V_2 , V_9 , V_46 ,
V_64 ,
& V_36 ) ;
if ( V_21 )
goto V_127;
}
if ( ++ V_121 == V_128 )
goto V_129;
}
V_129:
V_120 . V_121 = V_121 ;
V_120 . V_123 = V_123 ;
memcpy ( & V_39 , & V_120 , sizeof( V_120 ) ) ;
V_21 = F_13 ( V_37 , F_7 ( V_130 ) , V_117 ,
& V_36 , F_61 ,
V_39 ) ;
if ( V_21 )
goto V_127;
if ( V_9 < F_26 ( V_37 ) )
goto V_126;
V_127:
V_124 = F_71 ( & V_36 ) ;
if ( ! V_21 )
V_21 = V_124 ;
F_29 ( V_117 ) ;
return V_21 ;
}
int F_72 ( struct V_37 * V_37 ,
unsigned int V_97 )
{
struct V_2 * V_2 = F_51 ( V_37 ) ;
F_64 ( V_36 ) ;
char * V_117 ;
unsigned int V_121 ;
T_1 V_9 = 0 ;
int V_46 ;
int V_21 ;
int V_124 ;
V_117 = F_65 ( V_125 , V_58 ) ;
if ( ! V_117 )
return - V_59 ;
V_126:
V_9 ++ ;
V_121 = 0 ;
F_66 ( V_117 , true ) ;
for ( V_46 = 0 ; V_46 < V_29 ; V_46 ++ ) {
F_67 ( V_117 , V_46 , 1 ) ;
F_68 ( V_117 , V_46 , 1 ) ;
}
for (; V_9 < F_26 ( V_37 ) ; V_9 ++ ) {
if ( ! V_2 -> V_11 [ V_9 ] )
continue;
F_69 ( V_117 , V_9 , 1 ) ;
F_70 ( V_117 , V_9 , 1 ) ;
for ( V_46 = 0 ; V_46 < V_94 ; V_46 ++ ) {
V_21 = F_12 ( V_2 , V_9 , V_46 ,
V_61 ,
& V_36 ) ;
if ( V_21 )
goto V_127;
V_21 = F_12 ( V_2 , V_9 , V_46 ,
V_64 ,
& V_36 ) ;
if ( V_21 )
goto V_127;
}
if ( ++ V_121 == V_128 )
goto V_129;
}
V_129:
V_21 = F_13 ( V_37 , F_7 ( V_130 ) , V_117 ,
& V_36 , NULL , 0 ) ;
if ( V_21 )
goto V_127;
if ( V_9 < F_26 ( V_37 ) )
goto V_126;
V_127:
V_124 = F_71 ( & V_36 ) ;
if ( ! V_21 )
V_21 = V_124 ;
F_29 ( V_117 ) ;
return V_21 ;
}
int F_73 ( struct V_113 * V_113 ,
unsigned int V_97 , T_4 V_96 ,
T_2 * V_131 , T_2 * V_132 )
{
struct V_43 * V_43 =
F_57 ( V_113 ) ;
struct V_2 * V_2 = V_43 -> V_2 ;
T_1 V_9 = V_43 -> V_9 ;
T_1 V_3 = F_47 ( V_96 ) ;
enum V_4 V_5 = F_49 ( V_96 ) ;
struct V_13 * V_33 = F_3 ( V_2 , V_9 ,
V_3 , V_5 ) ;
* V_131 = F_52 ( V_2 , V_33 -> V_40 . V_41 ) ;
* V_132 = F_52 ( V_2 , V_33 -> V_40 . V_42 ) ;
return 0 ;
}
int F_74 ( struct V_113 * V_113 ,
unsigned int V_97 , T_4 V_115 ,
enum V_101 V_100 ,
T_2 * V_131 , T_2 * V_132 )
{
struct V_43 * V_43 =
F_57 ( V_113 ) ;
struct V_2 * V_2 = V_43 -> V_2 ;
T_1 V_9 = V_43 -> V_9 ;
T_1 V_10 = V_115 ;
enum V_4 V_5 = (enum V_4 ) V_100 ;
struct V_8 * V_30 = F_2 ( V_2 , V_9 ,
V_10 , V_5 ) ;
* V_131 = F_52 ( V_2 , V_30 -> V_40 . V_41 ) ;
* V_132 = F_52 ( V_2 , V_30 -> V_40 . V_42 ) ;
return 0 ;
}
