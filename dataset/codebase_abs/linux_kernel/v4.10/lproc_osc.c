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
F_12 ( V_10 ) ;
F_13 ( & V_10 -> V_29 ) ;
return V_14 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
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
F_13 ( & V_10 -> V_29 ) ;
V_30 = 1 << ( 20 - V_32 ) ;
return F_15 ( V_5 , V_33 , V_16 , V_30 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_15 ;
unsigned long V_34 ;
V_15 = F_4 ( V_13 , 10 , & V_34 ) ;
if ( V_15 )
return V_15 ;
V_34 *= 1 << ( 20 - V_32 ) ;
if ( V_34 <= 0 ||
V_34 >= V_35 << ( 20 - V_32 ) ||
V_34 > V_36 / 4 )
return - V_17 ;
F_11 ( & V_10 -> V_29 ) ;
V_10 -> V_31 = V_34 ;
F_17 ( V_10 ) ;
F_13 ( & V_10 -> V_29 ) ;
return V_14 ;
}
static int F_18 ( struct V_37 * V_38 , void * V_39 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_41 = 20 - V_32 ;
F_19 ( V_38 ,
L_4
L_5
L_6 ,
( F_20 ( & V_10 -> V_42 ) +
F_20 ( & V_10 -> V_43 ) ) >> V_41 ,
F_20 ( & V_10 -> V_43 ) ,
V_10 -> V_44 ) ;
return 0 ;
}
static T_1 F_21 ( struct V_45 * V_45 ,
const char T_3 * V_13 ,
T_2 V_14 , T_4 * V_46 )
{
struct V_6 * V_7 = ( (struct V_37 * ) V_45 -> V_47 ) -> V_40 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
long V_34 , V_15 ;
char V_48 [ 128 ] ;
int V_30 ;
T_5 V_16 ;
if ( V_14 >= sizeof( V_48 ) )
return - V_49 ;
if ( F_22 ( V_48 , V_13 , V_14 ) )
return - V_50 ;
V_48 [ V_14 ] = 0 ;
V_30 = 1 << ( 20 - V_32 ) ;
V_13 += F_23 ( V_48 , L_7 , & V_14 ) -
V_48 ;
V_15 = F_24 ( V_13 , V_14 , & V_16 , V_30 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 > V_51 )
return - V_17 ;
V_34 = ( long ) V_16 ;
if ( V_34 < 0 )
return - V_17 ;
V_15 = F_20 ( & V_10 -> V_42 ) - V_34 ;
if ( V_15 > 0 ) {
struct V_52 * V_53 ;
int V_54 ;
V_53 = F_25 ( & V_54 ) ;
if ( ! F_26 ( V_53 ) ) {
( void ) F_27 ( V_53 , V_10 , V_15 , true ) ;
F_28 ( V_53 , & V_54 ) ;
}
}
return V_14 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_55 ;
F_11 ( & V_10 -> V_29 ) ;
V_55 = sprintf ( V_5 , L_8 , V_10 -> V_56 << V_32 ) ;
F_13 ( & V_10 -> V_29 ) ;
return V_55 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_55 ;
F_11 ( & V_10 -> V_29 ) ;
V_55 = sprintf ( V_5 , L_8 , V_10 -> V_57 ) ;
F_13 ( & V_10 -> V_29 ) ;
return V_55 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_58 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_58 -> V_9 . V_10 ;
int V_15 ;
unsigned long long V_16 ;
V_15 = F_32 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
F_11 ( & V_10 -> V_29 ) ;
if ( V_16 >= V_10 -> V_57 ) {
F_13 ( & V_10 -> V_29 ) ;
return - V_49 ;
}
F_13 ( & V_10 -> V_29 ) ;
if ( V_10 -> V_11 -> V_59 == V_60 )
V_15 = F_33 ( V_10 , V_16 ) ;
if ( V_15 )
return V_15 ;
return V_14 ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_55 ;
F_11 ( & V_10 -> V_29 ) ;
V_55 = sprintf ( V_5 , L_8 , V_10 -> V_61 ) ;
F_13 ( & V_10 -> V_29 ) ;
return V_55 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_58 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_58 -> V_9 . V_10 . V_62 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_58 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 <= 0 )
return - V_17 ;
V_58 -> V_9 . V_10 . V_62 = V_16 ;
return V_14 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_58 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_58 -> V_9 . V_10 . V_63 ? 1 : 0 ) ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_58 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
V_58 -> V_9 . V_10 . V_63 = ( V_16 ? 1 : 0 ) ;
return V_14 ;
}
static int F_39 ( struct V_37 * V_38 , void * V_39 )
{
struct V_6 * V_58 = V_38 -> V_40 ;
int V_64 ;
V_65 ;
if ( ! V_58 )
return 0 ;
for ( V_64 = 0 ; V_64 < F_40 ( V_66 ) ; V_64 ++ ) {
if ( ( ( 1 << V_64 ) & V_58 -> V_9 . V_10 . V_67 ) == 0 )
continue;
if ( V_58 -> V_9 . V_10 . V_68 == ( 1 << V_64 ) )
F_19 ( V_38 , L_9 , V_66 [ V_64 ] ) ;
else
F_19 ( V_38 , L_10 , V_66 [ V_64 ] ) ;
}
F_41 ( V_38 , '\n' ) ;
return 0 ;
}
static T_1 F_42 ( struct V_45 * V_45 ,
const char T_3 * V_13 ,
T_2 V_14 , T_4 * V_46 )
{
struct V_6 * V_58 = ( (struct V_37 * ) V_45 -> V_47 ) -> V_40 ;
int V_64 ;
V_65 ;
char V_48 [ 10 ] ;
if ( ! V_58 )
return 0 ;
if ( V_14 > sizeof( V_48 ) - 1 )
return - V_49 ;
if ( F_22 ( V_48 , V_13 , V_14 ) )
return - V_50 ;
if ( V_14 > 0 && V_48 [ V_14 - 1 ] == '\n' )
V_48 [ V_14 - 1 ] = '\0' ;
else
V_48 [ V_14 ] = '\0' ;
for ( V_64 = 0 ; V_64 < F_40 ( V_66 ) ; V_64 ++ ) {
if ( ( ( 1 << V_64 ) & V_58 -> V_9 . V_10 . V_67 ) == 0 )
continue;
if ( ! strcmp ( V_48 , V_66 [ V_64 ] ) ) {
V_58 -> V_9 . V_10 . V_68 = 1 << V_64 ;
return V_14 ;
}
}
return - V_49 ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_58 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_3 , F_9 ( & V_58 -> V_9 . V_10 . V_69 ) ) ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_58 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
F_45 ( & V_58 -> V_9 . V_10 . V_69 , V_16 ) ;
return V_14 ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_58 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_70 * V_71 = F_47 ( V_58 ) ;
return sprintf ( V_5 , L_3 , V_71 -> V_72 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_58 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_70 * V_71 = F_47 ( V_58 ) ;
int V_15 ;
int V_16 ;
V_15 = F_49 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 < 0 )
return - V_49 ;
V_71 -> V_72 = V_16 ;
return V_14 ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_58 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_70 * V_71 = F_47 ( V_58 ) ;
return sprintf ( V_5 , L_3 , V_71 -> V_73 ) ;
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_58 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_70 * V_71 = F_47 ( V_58 ) ;
int V_15 ;
unsigned int V_16 ;
V_15 = F_52 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
V_71 -> V_73 = V_16 ;
return V_14 ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_58 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_3 ,
F_9 ( & V_58 -> V_9 . V_10 . V_74 ) ) ;
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
return sprintf ( V_5 , L_1 , V_10 -> V_75 ) ;
}
static T_1 F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
struct V_76 * V_77 = & V_10 -> V_11 -> V_78 ;
int V_79 , V_15 ;
unsigned long long V_16 ;
V_15 = F_32 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 >= V_80 )
V_16 >>= V_32 ;
V_79 = ~ ( ( 1 << ( V_10 -> V_81 - V_32 ) ) - 1 ) ;
V_16 = ( V_16 + ~ V_79 ) & V_79 ;
if ( ! V_16 || ( V_77 -> V_82 &&
V_16 > V_77 -> V_82 >> V_32 ) ) {
return - V_17 ;
}
F_11 ( & V_10 -> V_29 ) ;
V_10 -> V_75 = V_16 ;
F_12 ( V_10 ) ;
F_13 ( & V_10 -> V_29 ) ;
return V_14 ;
}
static T_1 F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
long V_83 ;
int V_84 ;
V_83 = F_20 ( & V_10 -> V_85 ) ;
V_84 = ( V_83 * V_33 ) >> 20 ;
return sprintf ( V_5 , L_11
L_12 , V_83 , V_84 ) ;
}
static int F_57 ( struct V_37 * V_86 , void * V_39 )
{
struct V_87 V_88 ;
struct V_6 * V_7 = V_86 -> V_40 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
unsigned long V_89 = 0 , V_90 = 0 , V_91 , V_92 ;
int V_64 ;
F_58 ( & V_88 ) ;
F_11 ( & V_10 -> V_29 ) ;
F_19 ( V_86 , L_13 ,
( V_93 ) V_88 . V_94 , ( unsigned long ) V_88 . V_95 ) ;
F_19 ( V_86 , L_14 ,
V_10 -> V_96 ) ;
F_19 ( V_86 , L_15 ,
V_10 -> V_97 ) ;
F_19 ( V_86 , L_16 ,
F_9 ( & V_10 -> V_98 ) ) ;
F_19 ( V_86 , L_17 ,
F_9 ( & V_10 -> V_99 ) ) ;
F_59 ( V_86 , L_18 ) ;
F_59 ( V_86 , L_19 ) ;
F_59 ( V_86 , L_20 ) ;
V_89 = F_60 ( & V_10 -> V_100 ) ;
V_90 = F_60 ( & V_10 -> V_101 ) ;
V_91 = 0 ;
V_92 = 0 ;
for ( V_64 = 0 ; V_64 < V_102 ; V_64 ++ ) {
unsigned long V_103 = V_10 -> V_100 . V_104 [ V_64 ] ;
unsigned long V_105 = V_10 -> V_101 . V_104 [ V_64 ] ;
V_91 += V_103 ;
V_92 += V_105 ;
F_19 ( V_86 , L_21 ,
1 << V_64 , V_103 , F_61 ( V_103 , V_89 ) ,
F_61 ( V_91 , V_89 ) , V_105 ,
F_61 ( V_105 , V_90 ) ,
F_61 ( V_92 , V_90 ) ) ;
if ( V_91 == V_89 && V_92 == V_90 )
break;
}
F_59 ( V_86 , L_18 ) ;
F_59 ( V_86 , L_22 ) ;
F_59 ( V_86 , L_20 ) ;
V_89 = F_60 ( & V_10 -> V_106 ) ;
V_90 = F_60 ( & V_10 -> V_107 ) ;
V_91 = 0 ;
V_92 = 0 ;
for ( V_64 = 0 ; V_64 < V_102 ; V_64 ++ ) {
unsigned long V_103 = V_10 -> V_106 . V_104 [ V_64 ] ;
unsigned long V_105 = V_10 -> V_107 . V_104 [ V_64 ] ;
V_91 += V_103 ;
V_92 += V_105 ;
F_19 ( V_86 , L_21 ,
V_64 , V_103 , F_61 ( V_103 , V_89 ) ,
F_61 ( V_91 , V_89 ) , V_105 ,
F_61 ( V_105 , V_90 ) ,
F_61 ( V_92 , V_90 ) ) ;
if ( V_91 == V_89 && V_92 == V_90 )
break;
}
F_59 ( V_86 , L_18 ) ;
F_59 ( V_86 , L_23 ) ;
F_59 ( V_86 , L_20 ) ;
V_89 = F_60 ( & V_10 -> V_108 ) ;
V_90 = F_60 ( & V_10 -> V_109 ) ;
V_91 = 0 ;
V_92 = 0 ;
for ( V_64 = 0 ; V_64 < V_102 ; V_64 ++ ) {
unsigned long V_103 = V_10 -> V_108 . V_104 [ V_64 ] ;
unsigned long V_105 = V_10 -> V_109 . V_104 [ V_64 ] ;
V_91 += V_103 ;
V_92 += V_105 ;
F_19 ( V_86 , L_21 ,
( V_64 == 0 ) ? 0 : 1 << ( V_64 - 1 ) ,
V_103 , F_61 ( V_103 , V_89 ) , F_61 ( V_91 , V_89 ) ,
V_105 , F_61 ( V_105 , V_90 ) , F_61 ( V_92 , V_90 ) ) ;
if ( V_91 == V_89 && V_92 == V_90 )
break;
}
F_13 ( & V_10 -> V_29 ) ;
return 0 ;
}
static T_1 F_62 ( struct V_45 * V_45 ,
const char T_3 * V_5 ,
T_2 V_55 , T_4 * V_46 )
{
struct V_37 * V_86 = V_45 -> V_47 ;
struct V_6 * V_7 = V_86 -> V_40 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
F_63 ( & V_10 -> V_106 ) ;
F_63 ( & V_10 -> V_107 ) ;
F_63 ( & V_10 -> V_100 ) ;
F_63 ( & V_10 -> V_101 ) ;
F_63 ( & V_10 -> V_108 ) ;
F_63 ( & V_10 -> V_109 ) ;
return V_55 ;
}
static int F_64 ( struct V_37 * V_86 , void * V_39 )
{
struct V_87 V_88 ;
struct V_6 * V_7 = V_86 -> V_40 ;
struct V_110 * V_111 = & F_47 ( V_7 ) -> V_112 ;
F_58 ( & V_88 ) ;
F_19 ( V_86 , L_13 ,
( V_93 ) V_88 . V_94 , ( unsigned long ) V_88 . V_95 ) ;
F_19 ( V_86 , L_24 ,
V_111 -> V_113 ) ;
F_19 ( V_86 , L_25 ,
V_111 -> V_114 ) ;
F_19 ( V_86 , L_26 ,
V_111 -> V_115 ) ;
return 0 ;
}
static T_1 F_65 ( struct V_45 * V_45 ,
const char T_3 * V_5 ,
T_2 V_55 , T_4 * V_46 )
{
struct V_37 * V_86 = V_45 -> V_47 ;
struct V_6 * V_7 = V_86 -> V_40 ;
struct V_110 * V_111 = & F_47 ( V_7 ) -> V_112 ;
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
return V_55 ;
}
int F_66 ( struct V_6 * V_7 )
{
int V_15 ;
V_15 = F_67 ( V_7 -> V_116 , L_27 , 0644 ,
& V_117 , V_7 ) ;
if ( V_15 == 0 )
V_15 = F_68 ( V_7 , L_28 , 0644 ,
& V_118 , V_7 ) ;
return V_15 ;
}
void F_69 ( struct V_119 * V_120 )
{
V_120 -> V_121 = & V_122 ;
V_120 -> V_123 = V_124 ;
}
