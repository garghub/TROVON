static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , ! V_7 -> V_9 . V_10 . V_11 -> V_12 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 > 1 )
return - V_17 ;
if ( V_7 -> V_9 . V_10 . V_11 -> V_12 == V_16 )
V_15 = F_5 ( V_7 -> V_9 . V_10 . V_11 , V_16 ) ;
else
F_6 ( V_18 , L_2 ,
V_16 ) ;
return V_14 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
return sprintf ( V_5 , L_3 , V_10 -> V_20 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_15 ;
unsigned long V_16 ;
int V_21 , V_22 , V_23 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 < 1 || V_16 > V_24 )
return - V_17 ;
V_21 = V_16 - V_10 -> V_20 ;
V_23 = F_9 ( & V_25 ) ;
if ( V_21 > 0 && V_23 < V_26 ) {
if ( V_23 + V_21 > V_26 )
V_21 = V_26 - V_23 ;
V_22 = V_27 -> V_28 ( V_27 , V_21 ) ;
F_10 ( V_22 , & V_25 ) ;
}
F_11 ( & V_10 -> V_29 ) ;
V_10 -> V_20 = V_16 ;
F_12 ( & V_10 -> V_29 ) ;
return V_14 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
long V_16 ;
int V_30 ;
F_11 ( & V_10 -> V_29 ) ;
V_16 = V_10 -> V_31 ;
F_12 ( & V_10 -> V_29 ) ;
V_30 = 1 << 20 ;
return F_14 ( V_5 , V_32 , V_16 , V_30 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_15 ;
unsigned long V_33 ;
V_15 = F_4 ( V_13 , 10 , & V_33 ) ;
if ( V_15 )
return V_15 ;
V_33 *= 1 << ( 20 - V_34 ) ;
if ( V_33 <= 0 ||
V_33 > V_35 << ( 20 - V_34 ) ||
V_33 > V_36 / 4 )
return - V_17 ;
F_11 ( & V_10 -> V_29 ) ;
V_10 -> V_31 = ( V_37 ) ( V_33 << V_34 ) ;
F_16 ( V_10 ) ;
F_12 ( & V_10 -> V_29 ) ;
return V_14 ;
}
static int F_17 ( struct V_38 * V_39 , void * V_40 )
{
struct V_6 * V_7 = V_39 -> V_41 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_42 = 20 - V_34 ;
F_18 ( V_39 ,
L_4
L_5 ,
( F_9 ( & V_10 -> V_43 ) +
F_9 ( & V_10 -> V_44 ) ) >> V_42 ,
F_9 ( & V_10 -> V_44 ) ) ;
return 0 ;
}
static T_1 F_19 ( struct V_45 * V_45 ,
const char T_3 * V_13 ,
T_2 V_14 , T_4 * V_46 )
{
struct V_6 * V_7 = ( (struct V_38 * ) V_45 -> V_47 ) -> V_41 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_33 , V_30 , V_15 ;
char V_48 [ 128 ] ;
if ( V_14 >= sizeof( V_48 ) )
return - V_49 ;
if ( F_20 ( V_48 , V_13 , V_14 ) )
return - V_50 ;
V_48 [ V_14 ] = 0 ;
V_30 = 1 << ( 20 - V_34 ) ;
V_13 += F_21 ( V_48 , L_6 , & V_14 ) -
V_48 ;
V_15 = F_22 ( V_13 , V_14 , & V_33 , V_30 ) ;
if ( V_15 )
return V_15 ;
if ( V_33 < 0 )
return - V_17 ;
V_15 = F_9 ( & V_10 -> V_43 ) - V_33 ;
if ( V_15 > 0 ) {
struct V_51 * V_52 ;
int V_53 ;
V_52 = F_23 ( & V_53 ) ;
if ( ! F_24 ( V_52 ) ) {
( void ) F_25 ( V_52 , V_10 , V_15 , true ) ;
F_26 ( V_52 , & V_53 ) ;
}
}
return V_14 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_54 ;
F_11 ( & V_10 -> V_29 ) ;
V_54 = sprintf ( V_5 , L_7 , V_10 -> V_55 ) ;
F_12 ( & V_10 -> V_29 ) ;
return V_54 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_54 ;
F_11 ( & V_10 -> V_29 ) ;
V_54 = sprintf ( V_5 , L_7 , V_10 -> V_56 ) ;
F_12 ( & V_10 -> V_29 ) ;
return V_54 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_57 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_57 -> V_9 . V_10 ;
int V_15 ;
unsigned long long V_16 ;
V_15 = F_30 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
F_11 ( & V_10 -> V_29 ) ;
if ( V_16 >= V_10 -> V_56 ) {
F_12 ( & V_10 -> V_29 ) ;
return - V_49 ;
}
F_12 ( & V_10 -> V_29 ) ;
if ( V_10 -> V_11 -> V_58 == V_59 )
V_15 = F_31 ( V_10 , V_16 ) ;
if ( V_15 )
return V_15 ;
return V_14 ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_54 ;
F_11 ( & V_10 -> V_29 ) ;
V_54 = sprintf ( V_5 , L_7 , V_10 -> V_60 ) ;
F_12 ( & V_10 -> V_29 ) ;
return V_54 ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_57 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_57 -> V_9 . V_10 . V_61 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_57 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 <= 0 )
return - V_17 ;
V_57 -> V_9 . V_10 . V_61 = V_16 ;
return V_14 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_57 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_57 -> V_9 . V_10 . V_62 ? 1 : 0 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_57 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
V_57 -> V_9 . V_10 . V_62 = ( V_16 ? 1 : 0 ) ;
return V_14 ;
}
static int F_37 ( struct V_38 * V_39 , void * V_40 )
{
struct V_6 * V_57 = V_39 -> V_41 ;
int V_63 ;
V_64 ;
if ( ! V_57 )
return 0 ;
for ( V_63 = 0 ; V_63 < F_38 ( V_65 ) ; V_63 ++ ) {
if ( ( ( 1 << V_63 ) & V_57 -> V_9 . V_10 . V_66 ) == 0 )
continue;
if ( V_57 -> V_9 . V_10 . V_67 == ( 1 << V_63 ) )
F_18 ( V_39 , L_8 , V_65 [ V_63 ] ) ;
else
F_18 ( V_39 , L_9 , V_65 [ V_63 ] ) ;
}
F_39 ( V_39 , '\n' ) ;
return 0 ;
}
static T_1 F_40 ( struct V_45 * V_45 ,
const char T_3 * V_13 ,
T_2 V_14 , T_4 * V_46 )
{
struct V_6 * V_57 = ( (struct V_38 * ) V_45 -> V_47 ) -> V_41 ;
int V_63 ;
V_64 ;
char V_48 [ 10 ] ;
if ( ! V_57 )
return 0 ;
if ( V_14 > sizeof( V_48 ) - 1 )
return - V_49 ;
if ( F_20 ( V_48 , V_13 , V_14 ) )
return - V_50 ;
if ( V_14 > 0 && V_48 [ V_14 - 1 ] == '\n' )
V_48 [ V_14 - 1 ] = '\0' ;
else
V_48 [ V_14 ] = '\0' ;
for ( V_63 = 0 ; V_63 < F_38 ( V_65 ) ; V_63 ++ ) {
if ( ( ( 1 << V_63 ) & V_57 -> V_9 . V_10 . V_66 ) == 0 )
continue;
if ( ! strcmp ( V_48 , V_65 [ V_63 ] ) ) {
V_57 -> V_9 . V_10 . V_67 = 1 << V_63 ;
return V_14 ;
}
}
return - V_49 ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_57 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_3 , F_9 ( & V_57 -> V_9 . V_10 . V_68 ) ) ;
}
static T_1 F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_57 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
F_43 ( & V_57 -> V_9 . V_10 . V_68 , V_16 ) ;
return V_14 ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_57 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_69 * V_70 = F_45 ( V_57 ) ;
return sprintf ( V_5 , L_3 , V_70 -> V_71 ) ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_57 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_69 * V_70 = F_45 ( V_57 ) ;
int V_15 ;
int V_16 ;
V_15 = F_47 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 < 0 )
return - V_49 ;
V_70 -> V_71 = V_16 ;
return V_14 ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_57 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_69 * V_70 = F_45 ( V_57 ) ;
return sprintf ( V_5 , L_3 , V_70 -> V_72 ) ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_57 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_69 * V_70 = F_45 ( V_57 ) ;
int V_15 ;
unsigned int V_16 ;
V_15 = F_50 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
V_70 -> V_72 = V_16 ;
return V_14 ;
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_57 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_3 ,
F_9 ( & V_57 -> V_9 . V_10 . V_73 ) ) ;
}
static T_1 F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
return sprintf ( V_5 , L_1 , V_10 -> V_74 ) ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
struct V_75 * V_76 = & V_10 -> V_11 -> V_77 ;
int V_78 , V_15 ;
unsigned long long V_16 ;
V_15 = F_30 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 >= V_79 )
V_16 >>= V_34 ;
V_78 = ~ ( ( 1 << ( V_10 -> V_80 - V_34 ) ) - 1 ) ;
V_16 = ( V_16 + ~ V_78 ) & V_78 ;
if ( V_16 == 0 || V_16 > V_76 -> V_81 >> V_34 ) {
return - V_17 ;
}
F_11 ( & V_10 -> V_29 ) ;
V_10 -> V_74 = V_16 ;
F_12 ( & V_10 -> V_29 ) ;
return V_14 ;
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_82 , V_83 ;
V_82 = F_9 ( & V_10 -> V_84 ) ;
V_83 = ( V_82 * V_32 ) >> 20 ;
return sprintf ( V_5 , L_10
L_11 , V_82 , V_83 ) ;
}
static int F_55 ( struct V_38 * V_85 , void * V_40 )
{
struct V_86 V_87 ;
struct V_6 * V_7 = V_85 -> V_41 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
unsigned long V_88 = 0 , V_89 = 0 , V_90 , V_91 ;
int V_63 ;
F_56 ( & V_87 ) ;
F_11 ( & V_10 -> V_29 ) ;
F_18 ( V_85 , L_12 ,
( V_92 ) V_87 . V_93 , ( unsigned long ) V_87 . V_94 ) ;
F_18 ( V_85 , L_13 ,
V_10 -> V_95 ) ;
F_18 ( V_85 , L_14 ,
V_10 -> V_96 ) ;
F_18 ( V_85 , L_15 ,
F_9 ( & V_10 -> V_97 ) ) ;
F_18 ( V_85 , L_16 ,
F_9 ( & V_10 -> V_98 ) ) ;
F_57 ( V_85 , L_17 ) ;
F_57 ( V_85 , L_18 ) ;
F_57 ( V_85 , L_19 ) ;
V_88 = F_58 ( & V_10 -> V_99 ) ;
V_89 = F_58 ( & V_10 -> V_100 ) ;
V_90 = 0 ;
V_91 = 0 ;
for ( V_63 = 0 ; V_63 < V_101 ; V_63 ++ ) {
unsigned long V_102 = V_10 -> V_99 . V_103 [ V_63 ] ;
unsigned long V_104 = V_10 -> V_100 . V_103 [ V_63 ] ;
V_90 += V_102 ;
V_91 += V_104 ;
F_18 ( V_85 , L_20 ,
1 << V_63 , V_102 , F_59 ( V_102 , V_88 ) ,
F_59 ( V_90 , V_88 ) , V_104 ,
F_59 ( V_104 , V_89 ) ,
F_59 ( V_91 , V_89 ) ) ;
if ( V_90 == V_88 && V_91 == V_89 )
break;
}
F_57 ( V_85 , L_17 ) ;
F_57 ( V_85 , L_21 ) ;
F_57 ( V_85 , L_19 ) ;
V_88 = F_58 ( & V_10 -> V_105 ) ;
V_89 = F_58 ( & V_10 -> V_106 ) ;
V_90 = 0 ;
V_91 = 0 ;
for ( V_63 = 0 ; V_63 < V_101 ; V_63 ++ ) {
unsigned long V_102 = V_10 -> V_105 . V_103 [ V_63 ] ;
unsigned long V_104 = V_10 -> V_106 . V_103 [ V_63 ] ;
V_90 += V_102 ;
V_91 += V_104 ;
F_18 ( V_85 , L_20 ,
V_63 , V_102 , F_59 ( V_102 , V_88 ) ,
F_59 ( V_90 , V_88 ) , V_104 ,
F_59 ( V_104 , V_89 ) ,
F_59 ( V_91 , V_89 ) ) ;
if ( V_90 == V_88 && V_91 == V_89 )
break;
}
F_57 ( V_85 , L_17 ) ;
F_57 ( V_85 , L_22 ) ;
F_57 ( V_85 , L_19 ) ;
V_88 = F_58 ( & V_10 -> V_107 ) ;
V_89 = F_58 ( & V_10 -> V_108 ) ;
V_90 = 0 ;
V_91 = 0 ;
for ( V_63 = 0 ; V_63 < V_101 ; V_63 ++ ) {
unsigned long V_102 = V_10 -> V_107 . V_103 [ V_63 ] ;
unsigned long V_104 = V_10 -> V_108 . V_103 [ V_63 ] ;
V_90 += V_102 ;
V_91 += V_104 ;
F_18 ( V_85 , L_20 ,
( V_63 == 0 ) ? 0 : 1 << ( V_63 - 1 ) ,
V_102 , F_59 ( V_102 , V_88 ) , F_59 ( V_90 , V_88 ) ,
V_104 , F_59 ( V_104 , V_89 ) , F_59 ( V_91 , V_89 ) ) ;
if ( V_90 == V_88 && V_91 == V_89 )
break;
}
F_12 ( & V_10 -> V_29 ) ;
return 0 ;
}
static T_1 F_60 ( struct V_45 * V_45 ,
const char T_3 * V_5 ,
T_2 V_54 , T_4 * V_46 )
{
struct V_38 * V_85 = V_45 -> V_47 ;
struct V_6 * V_7 = V_85 -> V_41 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
F_61 ( & V_10 -> V_105 ) ;
F_61 ( & V_10 -> V_106 ) ;
F_61 ( & V_10 -> V_99 ) ;
F_61 ( & V_10 -> V_100 ) ;
F_61 ( & V_10 -> V_107 ) ;
F_61 ( & V_10 -> V_108 ) ;
return V_54 ;
}
static int F_62 ( struct V_38 * V_85 , void * V_40 )
{
struct V_86 V_87 ;
struct V_6 * V_7 = V_85 -> V_41 ;
struct V_109 * V_110 = & F_45 ( V_7 ) -> V_111 ;
F_56 ( & V_87 ) ;
F_18 ( V_85 , L_12 ,
( V_92 ) V_87 . V_93 , ( unsigned long ) V_87 . V_94 ) ;
F_18 ( V_85 , L_23 ,
V_110 -> V_112 ) ;
F_18 ( V_85 , L_24 ,
V_110 -> V_113 ) ;
F_18 ( V_85 , L_25 ,
V_110 -> V_114 ) ;
return 0 ;
}
static T_1 F_63 ( struct V_45 * V_45 ,
const char T_3 * V_5 ,
T_2 V_54 , T_4 * V_46 )
{
struct V_38 * V_85 = V_45 -> V_47 ;
struct V_6 * V_7 = V_85 -> V_41 ;
struct V_109 * V_110 = & F_45 ( V_7 ) -> V_111 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
return V_54 ;
}
int F_64 ( struct V_6 * V_7 )
{
int V_15 ;
V_15 = F_65 ( V_7 -> V_115 , L_26 , 0644 ,
& V_116 , V_7 ) ;
if ( V_15 == 0 )
V_15 = F_66 ( V_7 , L_27 , 0644 ,
& V_117 , V_7 ) ;
return V_15 ;
}
void F_67 ( struct V_118 * V_119 )
{
V_119 -> V_120 = & V_121 ;
V_119 -> V_122 = V_123 ;
}
