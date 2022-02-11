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
if ( V_16 < 0 || V_16 > 1 )
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
struct V_21 * V_22 = V_10 -> V_11 -> V_23 ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 < 1 || V_16 > V_24 )
return - V_17 ;
if ( V_22 && V_16 > V_10 -> V_20 )
V_22 -> V_25 ( V_22 , V_16 - V_10 -> V_20 ) ;
F_9 ( & V_10 -> V_26 ) ;
V_10 -> V_20 = V_16 ;
F_10 ( & V_10 -> V_26 ) ;
return V_14 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
long V_16 ;
int V_27 ;
F_9 ( & V_10 -> V_26 ) ;
V_16 = V_10 -> V_28 ;
F_10 ( & V_10 -> V_26 ) ;
V_27 = 1 << 20 ;
return F_12 ( V_5 , V_29 , V_16 , V_27 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_15 ;
unsigned long V_30 ;
V_15 = F_4 ( V_13 , 10 , & V_30 ) ;
if ( V_15 )
return V_15 ;
V_30 *= 1 << ( 20 - V_31 ) ;
if ( V_30 <= 0 ||
V_30 > V_32 << ( 20 - V_31 ) ||
V_30 > V_33 / 4 )
return - V_17 ;
F_9 ( & V_10 -> V_26 ) ;
V_10 -> V_28 = ( V_34 ) ( V_30 << V_31 ) ;
F_14 ( V_10 ) ;
F_10 ( & V_10 -> V_26 ) ;
return V_14 ;
}
static int F_15 ( struct V_35 * V_36 , void * V_37 )
{
struct V_6 * V_7 = V_36 -> V_38 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_39 = 20 - V_31 ;
F_16 ( V_36 ,
L_4
L_5 ,
( F_17 ( & V_10 -> V_40 ) +
F_17 ( & V_10 -> V_41 ) ) >> V_39 ,
F_17 ( & V_10 -> V_41 ) ) ;
return 0 ;
}
static T_1 F_18 ( struct V_42 * V_42 ,
const char T_3 * V_13 ,
T_2 V_14 , T_4 * V_43 )
{
struct V_6 * V_7 = ( (struct V_35 * ) V_42 -> V_44 ) -> V_38 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_30 , V_27 , V_15 ;
char V_45 [ 128 ] ;
if ( V_14 >= sizeof( V_45 ) )
return - V_46 ;
if ( F_19 ( V_45 , V_13 , V_14 ) )
return - V_47 ;
V_45 [ V_14 ] = 0 ;
V_27 = 1 << ( 20 - V_31 ) ;
V_13 += F_20 ( V_45 , L_6 , & V_14 ) -
V_45 ;
V_15 = F_21 ( V_13 , V_14 , & V_30 , V_27 ) ;
if ( V_15 )
return V_15 ;
if ( V_30 < 0 )
return - V_17 ;
V_15 = F_17 ( & V_10 -> V_40 ) - V_30 ;
if ( V_15 > 0 )
( void ) F_22 ( V_10 , V_15 ) ;
return V_14 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_48 ;
F_9 ( & V_10 -> V_26 ) ;
V_48 = sprintf ( V_5 , L_7 , V_10 -> V_49 ) ;
F_10 ( & V_10 -> V_26 ) ;
return V_48 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_48 ;
F_9 ( & V_10 -> V_26 ) ;
V_48 = sprintf ( V_5 , L_7 , V_10 -> V_50 ) ;
F_10 ( & V_10 -> V_26 ) ;
return V_48 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_51 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_51 -> V_9 . V_10 ;
int V_15 ;
unsigned long long V_16 ;
V_15 = F_26 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
F_9 ( & V_10 -> V_26 ) ;
if ( V_16 >= V_10 -> V_50 ) {
F_10 ( & V_10 -> V_26 ) ;
return - V_46 ;
}
F_10 ( & V_10 -> V_26 ) ;
if ( V_10 -> V_11 -> V_52 == V_53 )
V_15 = F_27 ( V_10 , V_16 ) ;
if ( V_15 )
return V_15 ;
return V_14 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_48 ;
F_9 ( & V_10 -> V_26 ) ;
V_48 = sprintf ( V_5 , L_7 , V_10 -> V_54 ) ;
F_10 ( & V_10 -> V_26 ) ;
return V_48 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_51 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_51 -> V_9 . V_10 . V_55 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_51 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 <= 0 )
return - V_17 ;
V_51 -> V_9 . V_10 . V_55 = V_16 ;
return V_14 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_51 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_51 -> V_9 . V_10 . V_56 ? 1 : 0 ) ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_51 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
V_51 -> V_9 . V_10 . V_56 = ( V_16 ? 1 : 0 ) ;
return V_14 ;
}
static int F_33 ( struct V_35 * V_36 , void * V_37 )
{
struct V_6 * V_51 = V_36 -> V_38 ;
int V_57 ;
V_58 ;
if ( V_51 == NULL )
return 0 ;
for ( V_57 = 0 ; V_57 < F_34 ( V_59 ) ; V_57 ++ ) {
if ( ( ( 1 << V_57 ) & V_51 -> V_9 . V_10 . V_60 ) == 0 )
continue;
if ( V_51 -> V_9 . V_10 . V_61 == ( 1 << V_57 ) )
F_16 ( V_36 , L_8 , V_59 [ V_57 ] ) ;
else
F_16 ( V_36 , L_9 , V_59 [ V_57 ] ) ;
}
F_35 ( V_36 , '\n' ) ;
return 0 ;
}
static T_1 F_36 ( struct V_42 * V_42 ,
const char T_3 * V_13 ,
T_2 V_14 , T_4 * V_43 )
{
struct V_6 * V_51 = ( (struct V_35 * ) V_42 -> V_44 ) -> V_38 ;
int V_57 ;
V_58 ;
char V_45 [ 10 ] ;
if ( V_51 == NULL )
return 0 ;
if ( V_14 > sizeof( V_45 ) - 1 )
return - V_46 ;
if ( F_19 ( V_45 , V_13 , V_14 ) )
return - V_47 ;
if ( V_14 > 0 && V_45 [ V_14 - 1 ] == '\n' )
V_45 [ V_14 - 1 ] = '\0' ;
else
V_45 [ V_14 ] = '\0' ;
for ( V_57 = 0 ; V_57 < F_34 ( V_59 ) ; V_57 ++ ) {
if ( ( ( 1 << V_57 ) & V_51 -> V_9 . V_10 . V_60 ) == 0 )
continue;
if ( ! strcmp ( V_45 , V_59 [ V_57 ] ) ) {
V_51 -> V_9 . V_10 . V_61 = 1 << V_57 ;
return V_14 ;
}
}
return - V_46 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_51 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_3 , F_17 ( & V_51 -> V_9 . V_10 . V_62 ) ) ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_51 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 < 0 )
return - V_46 ;
F_39 ( & V_51 -> V_9 . V_10 . V_62 , V_16 ) ;
return V_14 ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_51 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_63 * V_64 = F_41 ( V_51 ) ;
return sprintf ( V_5 , L_3 , V_64 -> V_65 ) ;
}
static T_1 F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_51 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_63 * V_64 = F_41 ( V_51 ) ;
return F_43 ( V_13 , V_14 , & V_64 -> V_65 ) ? :
V_14 ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_51 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_63 * V_64 = F_41 ( V_51 ) ;
return sprintf ( V_5 , L_3 , V_64 -> V_66 ) ;
}
static T_1 F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_51 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_63 * V_64 = F_41 ( V_51 ) ;
return F_43 ( V_13 , V_14 , & V_64 -> V_66 ) ? :
V_14 ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_51 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_3 ,
F_17 ( & V_51 -> V_9 . V_10 . V_67 ) ) ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
return sprintf ( V_5 , L_1 , V_10 -> V_68 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
struct V_69 * V_70 = & V_10 -> V_11 -> V_71 ;
int V_72 , V_15 ;
unsigned long long V_16 ;
V_15 = F_26 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 >= V_73 )
V_16 >>= V_31 ;
V_72 = ~ ( ( 1 << ( V_10 -> V_74 - V_31 ) ) - 1 ) ;
V_16 = ( V_16 + ~ V_72 ) & V_72 ;
if ( V_16 == 0 || V_16 > V_70 -> V_75 >> V_31 ) {
return - V_17 ;
}
F_9 ( & V_10 -> V_26 ) ;
V_10 -> V_68 = V_16 ;
F_10 ( & V_10 -> V_26 ) ;
return V_14 ;
}
static int F_49 ( struct V_35 * V_76 , void * V_37 )
{
struct V_77 V_78 ;
struct V_6 * V_7 = V_76 -> V_38 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
unsigned long V_79 = 0 , V_80 = 0 , V_81 , V_82 ;
int V_57 ;
F_50 ( & V_78 ) ;
F_9 ( & V_10 -> V_26 ) ;
F_16 ( V_76 , L_10 ,
V_78 . V_83 , ( unsigned long ) V_78 . V_84 ) ;
F_16 ( V_76 , L_11 ,
V_10 -> V_85 ) ;
F_16 ( V_76 , L_12 ,
V_10 -> V_86 ) ;
F_16 ( V_76 , L_13 ,
F_17 ( & V_10 -> V_87 ) ) ;
F_16 ( V_76 , L_14 ,
F_17 ( & V_10 -> V_88 ) ) ;
F_51 ( V_76 , L_15 ) ;
F_51 ( V_76 , L_16 ) ;
F_51 ( V_76 , L_17 ) ;
V_79 = F_52 ( & V_10 -> V_89 ) ;
V_80 = F_52 ( & V_10 -> V_90 ) ;
V_81 = 0 ;
V_82 = 0 ;
for ( V_57 = 0 ; V_57 < V_91 ; V_57 ++ ) {
unsigned long V_92 = V_10 -> V_89 . V_93 [ V_57 ] ;
unsigned long V_94 = V_10 -> V_90 . V_93 [ V_57 ] ;
V_81 += V_92 ;
V_82 += V_94 ;
F_16 ( V_76 , L_18 ,
1 << V_57 , V_92 , F_53 ( V_92 , V_79 ) ,
F_53 ( V_81 , V_79 ) , V_94 ,
F_53 ( V_94 , V_80 ) ,
F_53 ( V_82 , V_80 ) ) ;
if ( V_81 == V_79 && V_82 == V_80 )
break;
}
F_51 ( V_76 , L_15 ) ;
F_51 ( V_76 , L_19 ) ;
F_51 ( V_76 , L_17 ) ;
V_79 = F_52 ( & V_10 -> V_95 ) ;
V_80 = F_52 ( & V_10 -> V_96 ) ;
V_81 = 0 ;
V_82 = 0 ;
for ( V_57 = 0 ; V_57 < V_91 ; V_57 ++ ) {
unsigned long V_92 = V_10 -> V_95 . V_93 [ V_57 ] ;
unsigned long V_94 = V_10 -> V_96 . V_93 [ V_57 ] ;
V_81 += V_92 ;
V_82 += V_94 ;
F_16 ( V_76 , L_18 ,
V_57 , V_92 , F_53 ( V_92 , V_79 ) ,
F_53 ( V_81 , V_79 ) , V_94 ,
F_53 ( V_94 , V_80 ) ,
F_53 ( V_82 , V_80 ) ) ;
if ( V_81 == V_79 && V_82 == V_80 )
break;
}
F_51 ( V_76 , L_15 ) ;
F_51 ( V_76 , L_20 ) ;
F_51 ( V_76 , L_17 ) ;
V_79 = F_52 ( & V_10 -> V_97 ) ;
V_80 = F_52 ( & V_10 -> V_98 ) ;
V_81 = 0 ;
V_82 = 0 ;
for ( V_57 = 0 ; V_57 < V_91 ; V_57 ++ ) {
unsigned long V_92 = V_10 -> V_97 . V_93 [ V_57 ] ;
unsigned long V_94 = V_10 -> V_98 . V_93 [ V_57 ] ;
V_81 += V_92 ;
V_82 += V_94 ;
F_16 ( V_76 , L_18 ,
( V_57 == 0 ) ? 0 : 1 << ( V_57 - 1 ) ,
V_92 , F_53 ( V_92 , V_79 ) , F_53 ( V_81 , V_79 ) ,
V_94 , F_53 ( V_94 , V_80 ) , F_53 ( V_82 , V_80 ) ) ;
if ( V_81 == V_79 && V_82 == V_80 )
break;
}
F_10 ( & V_10 -> V_26 ) ;
return 0 ;
}
static T_1 F_54 ( struct V_42 * V_42 ,
const char T_3 * V_5 ,
T_2 V_48 , T_4 * V_43 )
{
struct V_35 * V_76 = V_42 -> V_44 ;
struct V_6 * V_7 = V_76 -> V_38 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
F_55 ( & V_10 -> V_95 ) ;
F_55 ( & V_10 -> V_96 ) ;
F_55 ( & V_10 -> V_89 ) ;
F_55 ( & V_10 -> V_90 ) ;
F_55 ( & V_10 -> V_97 ) ;
F_55 ( & V_10 -> V_98 ) ;
return V_48 ;
}
static int F_56 ( struct V_35 * V_76 , void * V_37 )
{
struct V_77 V_78 ;
struct V_6 * V_7 = V_76 -> V_38 ;
struct V_99 * V_100 = & F_41 ( V_7 ) -> V_101 ;
F_50 ( & V_78 ) ;
F_16 ( V_76 , L_10 ,
V_78 . V_83 , ( unsigned long ) V_78 . V_84 ) ;
F_16 ( V_76 , L_21 ,
V_100 -> V_102 ) ;
F_16 ( V_76 , L_22 ,
V_100 -> V_103 ) ;
F_16 ( V_76 , L_23 ,
V_100 -> V_104 ) ;
return 0 ;
}
static T_1 F_57 ( struct V_42 * V_42 ,
const char T_3 * V_5 ,
T_2 V_48 , T_4 * V_43 )
{
struct V_35 * V_76 = V_42 -> V_44 ;
struct V_6 * V_7 = V_76 -> V_38 ;
struct V_99 * V_100 = & F_41 ( V_7 ) -> V_101 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
return V_48 ;
}
int F_58 ( struct V_6 * V_7 )
{
int V_15 ;
V_15 = F_59 ( V_7 -> V_105 , L_24 , 0644 ,
& V_106 , V_7 ) ;
if ( V_15 == 0 )
V_15 = F_60 ( V_7 , L_25 , 0644 ,
& V_107 , V_7 ) ;
return V_15 ;
}
void F_61 ( struct V_108 * V_109 )
{
V_109 -> V_110 = & V_111 ;
V_109 -> V_112 = V_113 ;
}
