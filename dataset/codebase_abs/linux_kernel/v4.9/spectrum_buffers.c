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
char V_44 [ V_45 ] ;
int V_46 ;
F_18 ( V_44 , V_43 -> V_9 ,
0xffff , 0xffff / 2 ) ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
if ( V_46 == V_48 )
continue;
F_19 ( V_44 , V_46 , V_49 [ V_46 ] ) ;
}
F_19 ( V_44 ,
V_50 , 0 ) ;
return F_6 ( V_43 -> V_2 -> V_22 ,
F_7 ( V_51 ) , V_44 ) ;
}
static int F_20 ( struct V_43 * V_43 )
{
char V_52 [ V_53 ] ;
int V_46 ;
F_21 ( V_52 , V_43 -> V_9 ) ;
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ )
F_22 ( V_52 , V_46 , 0 ) ;
return F_6 ( V_43 -> V_2 -> V_22 , F_7 ( V_55 ) ,
V_52 ) ;
}
static int F_23 ( struct V_43 * V_43 )
{
int V_21 ;
V_21 = F_17 ( V_43 ) ;
if ( V_21 )
return V_21 ;
return F_20 ( V_43 ) ;
}
static int F_24 ( struct V_2 * V_2 ,
enum V_4 V_5 ,
const struct V_1 * V_7 ,
T_3 V_56 )
{
int V_46 ;
int V_21 ;
for ( V_46 = 0 ; V_46 < V_56 ; V_46 ++ ) {
const struct V_1 * V_20 ;
V_20 = & V_7 [ V_46 ] ;
V_21 = F_4 ( V_2 , V_46 , V_5 ,
V_20 -> V_16 , V_20 -> V_17 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_25 ( struct V_2 * V_2 )
{
int V_21 ;
V_21 = F_24 ( V_2 , V_57 ,
V_58 ,
V_59 ) ;
if ( V_21 )
return V_21 ;
return F_24 ( V_2 , V_60 ,
V_61 ,
V_62 ) ;
}
static int F_26 ( struct V_2 * V_2 , T_1 V_9 ,
enum V_4 V_5 ,
const struct V_8 * V_12 ,
T_3 V_63 )
{
int V_46 ;
int V_21 ;
for ( V_46 = 0 ; V_46 < V_63 ; V_46 ++ ) {
const struct V_8 * V_30 ;
if ( V_46 == 8 && V_5 == V_57 )
continue;
V_30 = & V_12 [ V_46 ] ;
V_21 = F_8 ( V_2 , V_9 , V_46 , V_5 ,
V_30 -> V_24 , V_30 -> V_25 ,
V_30 -> V_3 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_27 ( struct V_43 * V_43 )
{
int V_21 ;
V_21 = F_26 ( V_43 -> V_2 ,
V_43 -> V_9 ,
V_57 ,
V_64 ,
V_65 ) ;
if ( V_21 )
return V_21 ;
return F_26 ( V_43 -> V_2 ,
V_43 -> V_9 ,
V_60 ,
V_66 ,
V_67 ) ;
}
static int F_28 ( struct V_2 * V_2 )
{
return F_26 ( V_2 , 0 , V_60 ,
V_68 ,
V_69 ) ;
}
static int F_29 ( struct V_2 * V_2 , T_1 V_9 ,
enum V_4 V_5 ,
const struct V_13 * V_14 ,
T_3 V_70 )
{
int V_46 ;
int V_21 ;
for ( V_46 = 0 ; V_46 < V_70 ; V_46 ++ ) {
const struct V_13 * V_33 ;
V_33 = & V_14 [ V_46 ] ;
V_21 = F_10 ( V_2 , V_9 , V_46 , V_5 ,
V_33 -> V_24 , V_33 -> V_25 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_30 ( struct V_43 * V_43 )
{
int V_21 ;
V_21 = F_29 ( V_43 -> V_2 ,
V_43 -> V_9 ,
V_57 ,
V_71 ,
V_72 ) ;
if ( V_21 )
return V_21 ;
return F_29 ( V_43 -> V_2 ,
V_43 -> V_9 ,
V_60 ,
V_73 ,
V_74 ) ;
}
static int F_31 ( struct V_2 * V_2 )
{
char V_75 [ V_76 ] ;
int V_46 ;
int V_21 ;
for ( V_46 = 0 ; V_46 < V_77 ; V_46 ++ ) {
const struct V_78 * V_79 ;
V_79 = & V_80 [ V_46 ] ;
F_32 ( V_75 , V_46 , V_79 -> V_24 ,
V_79 -> V_25 , V_79 -> V_3 ) ;
V_21 = F_6 ( V_2 -> V_22 , F_7 ( V_81 ) , V_75 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
int F_33 ( struct V_2 * V_2 )
{
int V_21 ;
V_21 = F_25 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_28 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_31 ( V_2 ) ;
if ( V_21 )
return V_21 ;
return F_34 ( F_35 ( V_2 -> V_22 ) , 0 ,
V_82 ,
V_83 ,
V_83 ,
V_29 ,
V_29 ) ;
}
void F_36 ( struct V_2 * V_2 )
{
F_37 ( F_35 ( V_2 -> V_22 ) , 0 ) ;
}
int F_38 ( struct V_43 * V_43 )
{
int V_21 ;
V_21 = F_23 ( V_43 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_27 ( V_43 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_30 ( V_43 ) ;
return V_21 ;
}
static T_1 F_39 ( T_4 V_84 )
{
return V_84 % V_83 ;
}
static T_4 F_40 ( T_1 V_3 , enum V_4 V_5 )
{
T_4 V_84 ;
V_84 = V_3 ;
if ( V_5 == V_60 )
V_84 += V_83 ;
return V_84 ;
}
static enum V_4 F_41 ( T_4 V_84 )
{
return V_84 < V_83 ?
V_57 : V_60 ;
}
int F_42 ( struct V_37 * V_37 ,
unsigned int V_85 , T_4 V_84 ,
struct V_86 * V_87 )
{
struct V_2 * V_2 = F_43 ( V_37 ) ;
T_1 V_3 = F_39 ( V_84 ) ;
enum V_4 V_5 = F_41 ( V_84 ) ;
struct V_1 * V_20 = F_1 ( V_2 , V_3 , V_5 ) ;
V_87 -> V_88 = (enum V_89 ) V_5 ;
V_87 -> V_17 = F_44 ( V_20 -> V_17 ) ;
V_87 -> V_90 = (enum V_91 ) V_20 -> V_16 ;
return 0 ;
}
int F_45 ( struct V_37 * V_37 ,
unsigned int V_85 , T_4 V_84 , T_2 V_17 ,
enum V_91 V_90 )
{
struct V_2 * V_2 = F_43 ( V_37 ) ;
T_1 V_3 = F_39 ( V_84 ) ;
enum V_4 V_5 = F_41 ( V_84 ) ;
T_2 V_92 = F_46 ( V_17 ) ;
enum V_15 V_16 ;
V_16 = (enum V_15 ) V_90 ;
return F_4 ( V_2 , V_3 , V_5 , V_16 , V_92 ) ;
}
static T_2 F_47 ( struct V_2 * V_2 , T_1 V_3 ,
enum V_4 V_5 , T_2 V_25 )
{
struct V_1 * V_20 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_20 -> V_16 == V_93 )
return V_25 - V_94 ;
return F_44 ( V_25 ) ;
}
static int F_48 ( struct V_2 * V_2 , T_1 V_3 ,
enum V_4 V_5 , T_2 V_95 ,
T_2 * V_96 )
{
struct V_1 * V_20 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_20 -> V_16 == V_93 ) {
int V_97 ;
V_97 = V_95 + V_94 ;
if ( V_97 < V_98 ||
V_97 > V_99 )
return - V_100 ;
* V_96 = V_97 ;
} else {
* V_96 = F_46 ( V_95 ) ;
}
return 0 ;
}
int F_49 ( struct V_101 * V_101 ,
unsigned int V_85 , T_4 V_84 ,
T_2 * V_102 )
{
struct V_43 * V_43 =
F_50 ( V_101 ) ;
struct V_2 * V_2 = V_43 -> V_2 ;
T_1 V_9 = V_43 -> V_9 ;
T_1 V_3 = F_39 ( V_84 ) ;
enum V_4 V_5 = F_41 ( V_84 ) ;
struct V_13 * V_33 = F_3 ( V_2 , V_9 ,
V_3 , V_5 ) ;
* V_102 = F_47 ( V_2 , V_3 , V_5 ,
V_33 -> V_25 ) ;
return 0 ;
}
int F_51 ( struct V_101 * V_101 ,
unsigned int V_85 , T_4 V_84 ,
T_2 V_95 )
{
struct V_43 * V_43 =
F_50 ( V_101 ) ;
struct V_2 * V_2 = V_43 -> V_2 ;
T_1 V_9 = V_43 -> V_9 ;
T_1 V_3 = F_39 ( V_84 ) ;
enum V_4 V_5 = F_41 ( V_84 ) ;
T_2 V_25 ;
int V_21 ;
V_21 = F_48 ( V_2 , V_3 , V_5 ,
V_95 , & V_25 ) ;
if ( V_21 )
return V_21 ;
return F_10 ( V_2 , V_9 , V_3 , V_5 ,
0 , V_25 ) ;
}
int F_52 ( struct V_101 * V_101 ,
unsigned int V_85 , T_4 V_103 ,
enum V_89 V_88 ,
T_4 * V_104 , T_2 * V_102 )
{
struct V_43 * V_43 =
F_50 ( V_101 ) ;
struct V_2 * V_2 = V_43 -> V_2 ;
T_1 V_9 = V_43 -> V_9 ;
T_1 V_10 = V_103 ;
enum V_4 V_5 = (enum V_4 ) V_88 ;
struct V_8 * V_30 = F_2 ( V_2 , V_9 ,
V_10 , V_5 ) ;
* V_102 = F_47 ( V_2 , V_30 -> V_3 , V_5 ,
V_30 -> V_25 ) ;
* V_104 = F_40 ( V_30 -> V_3 , V_5 ) ;
return 0 ;
}
int F_53 ( struct V_101 * V_101 ,
unsigned int V_85 , T_4 V_103 ,
enum V_89 V_88 ,
T_4 V_84 , T_2 V_95 )
{
struct V_43 * V_43 =
F_50 ( V_101 ) ;
struct V_2 * V_2 = V_43 -> V_2 ;
T_1 V_9 = V_43 -> V_9 ;
T_1 V_10 = V_103 ;
enum V_4 V_5 = (enum V_4 ) V_88 ;
T_1 V_3 = F_39 ( V_84 ) ;
T_2 V_25 ;
int V_21 ;
if ( V_5 != F_41 ( V_84 ) )
return - V_100 ;
V_21 = F_48 ( V_2 , V_3 , V_5 ,
V_95 , & V_25 ) ;
if ( V_21 )
return V_21 ;
return F_8 ( V_2 , V_9 , V_10 , V_5 ,
0 , V_25 , V_3 ) ;
}
static void F_54 ( struct V_37 * V_37 ,
char * V_105 , T_3 V_106 ,
unsigned long V_39 )
{
struct V_2 * V_2 = F_43 ( V_37 ) ;
struct V_107 V_108 ;
T_1 V_109 ;
T_1 V_9 ;
int V_110 = 0 ;
struct V_8 * V_30 ;
int V_46 ;
memcpy ( & V_108 , & V_39 , sizeof( V_108 ) ) ;
V_109 = 0 ;
for ( V_9 = V_108 . V_111 ;
V_9 < V_112 ; V_9 ++ ) {
if ( ! V_2 -> V_11 [ V_9 ] )
continue;
for ( V_46 = 0 ; V_46 < V_29 ; V_46 ++ ) {
V_30 = F_2 ( V_2 , V_9 , V_46 ,
V_57 ) ;
F_55 ( V_105 , V_110 ++ ,
& V_30 -> V_40 . V_41 , & V_30 -> V_40 . V_42 ) ;
}
if ( ++ V_109 == V_108 . V_109 )
break;
}
V_109 = 0 ;
for ( V_9 = V_108 . V_111 ;
V_9 < V_112 ; V_9 ++ ) {
if ( ! V_2 -> V_11 [ V_9 ] )
continue;
for ( V_46 = 0 ; V_46 < V_29 ; V_46 ++ ) {
V_30 = F_2 ( V_2 , V_9 , V_46 ,
V_60 ) ;
F_55 ( V_105 , V_110 ++ ,
& V_30 -> V_40 . V_41 , & V_30 -> V_40 . V_42 ) ;
}
if ( ++ V_109 == V_108 . V_109 )
break;
}
}
int F_56 ( struct V_37 * V_37 ,
unsigned int V_85 )
{
struct V_2 * V_2 = F_43 ( V_37 ) ;
struct V_107 V_108 ;
unsigned long V_39 ;
F_57 ( V_36 ) ;
char * V_105 ;
T_1 V_109 ;
T_1 V_111 ;
T_1 V_9 = 0 ;
int V_46 ;
int V_21 ;
int V_113 ;
V_105 = F_58 ( V_114 , V_115 ) ;
if ( ! V_105 )
return - V_116 ;
V_117:
V_9 ++ ;
V_111 = V_9 ;
V_109 = 0 ;
F_59 ( V_105 , false ) ;
for ( V_46 = 0 ; V_46 < V_29 ; V_46 ++ ) {
F_60 ( V_105 , V_46 , 1 ) ;
F_61 ( V_105 , V_46 , 1 ) ;
}
for (; V_9 < V_112 ; V_9 ++ ) {
if ( ! V_2 -> V_11 [ V_9 ] )
continue;
F_62 ( V_105 , V_9 , 1 ) ;
F_63 ( V_105 , V_9 , 1 ) ;
for ( V_46 = 0 ; V_46 < V_83 ; V_46 ++ ) {
V_21 = F_16 ( V_2 , V_9 , V_46 ,
V_57 ,
& V_36 ) ;
if ( V_21 )
goto V_118;
V_21 = F_16 ( V_2 , V_9 , V_46 ,
V_60 ,
& V_36 ) ;
if ( V_21 )
goto V_118;
}
if ( ++ V_109 == V_119 )
goto V_120;
}
V_120:
V_108 . V_109 = V_109 ;
V_108 . V_111 = V_111 ;
memcpy ( & V_39 , & V_108 , sizeof( V_108 ) ) ;
V_21 = F_13 ( V_37 , F_7 ( V_121 ) , V_105 ,
& V_36 , F_54 ,
V_39 ) ;
if ( V_21 )
goto V_118;
if ( V_9 < V_112 )
goto V_117;
V_118:
V_113 = F_64 ( & V_36 ) ;
if ( ! V_21 )
V_21 = V_113 ;
F_65 ( V_105 ) ;
return V_21 ;
}
int F_66 ( struct V_37 * V_37 ,
unsigned int V_85 )
{
struct V_2 * V_2 = F_43 ( V_37 ) ;
F_57 ( V_36 ) ;
char * V_105 ;
unsigned int V_109 ;
T_1 V_9 = 0 ;
int V_46 ;
int V_21 ;
int V_113 ;
V_105 = F_58 ( V_114 , V_115 ) ;
if ( ! V_105 )
return - V_116 ;
V_117:
V_9 ++ ;
V_109 = 0 ;
F_59 ( V_105 , true ) ;
for ( V_46 = 0 ; V_46 < V_29 ; V_46 ++ ) {
F_60 ( V_105 , V_46 , 1 ) ;
F_61 ( V_105 , V_46 , 1 ) ;
}
for (; V_9 < V_112 ; V_9 ++ ) {
if ( ! V_2 -> V_11 [ V_9 ] )
continue;
F_62 ( V_105 , V_9 , 1 ) ;
F_63 ( V_105 , V_9 , 1 ) ;
for ( V_46 = 0 ; V_46 < V_83 ; V_46 ++ ) {
V_21 = F_12 ( V_2 , V_9 , V_46 ,
V_57 ,
& V_36 ) ;
if ( V_21 )
goto V_118;
V_21 = F_12 ( V_2 , V_9 , V_46 ,
V_60 ,
& V_36 ) ;
if ( V_21 )
goto V_118;
}
if ( ++ V_109 == V_119 )
goto V_120;
}
V_120:
V_21 = F_13 ( V_37 , F_7 ( V_121 ) , V_105 ,
& V_36 , NULL , 0 ) ;
if ( V_21 )
goto V_118;
if ( V_9 < V_112 )
goto V_117;
V_118:
V_113 = F_64 ( & V_36 ) ;
if ( ! V_21 )
V_21 = V_113 ;
F_65 ( V_105 ) ;
return V_21 ;
}
int F_67 ( struct V_101 * V_101 ,
unsigned int V_85 , T_4 V_84 ,
T_2 * V_122 , T_2 * V_123 )
{
struct V_43 * V_43 =
F_50 ( V_101 ) ;
struct V_2 * V_2 = V_43 -> V_2 ;
T_1 V_9 = V_43 -> V_9 ;
T_1 V_3 = F_39 ( V_84 ) ;
enum V_4 V_5 = F_41 ( V_84 ) ;
struct V_13 * V_33 = F_3 ( V_2 , V_9 ,
V_3 , V_5 ) ;
* V_122 = F_44 ( V_33 -> V_40 . V_41 ) ;
* V_123 = F_44 ( V_33 -> V_40 . V_42 ) ;
return 0 ;
}
int F_68 ( struct V_101 * V_101 ,
unsigned int V_85 , T_4 V_103 ,
enum V_89 V_88 ,
T_2 * V_122 , T_2 * V_123 )
{
struct V_43 * V_43 =
F_50 ( V_101 ) ;
struct V_2 * V_2 = V_43 -> V_2 ;
T_1 V_9 = V_43 -> V_9 ;
T_1 V_10 = V_103 ;
enum V_4 V_5 = (enum V_4 ) V_88 ;
struct V_8 * V_30 = F_2 ( V_2 , V_9 ,
V_10 , V_5 ) ;
* V_122 = F_44 ( V_30 -> V_40 . V_41 ) ;
* V_123 = F_44 ( V_30 -> V_40 . V_42 ) ;
return 0 ;
}
