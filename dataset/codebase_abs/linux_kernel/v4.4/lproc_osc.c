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
if ( V_15 > 0 )
( void ) F_23 ( V_10 , V_15 ) ;
return V_14 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_51 ;
F_11 ( & V_10 -> V_29 ) ;
V_51 = sprintf ( V_5 , L_7 , V_10 -> V_52 ) ;
F_12 ( & V_10 -> V_29 ) ;
return V_51 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_51 ;
F_11 ( & V_10 -> V_29 ) ;
V_51 = sprintf ( V_5 , L_7 , V_10 -> V_53 ) ;
F_12 ( & V_10 -> V_29 ) ;
return V_51 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_54 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_54 -> V_9 . V_10 ;
int V_15 ;
unsigned long long V_16 ;
V_15 = F_27 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
F_11 ( & V_10 -> V_29 ) ;
if ( V_16 >= V_10 -> V_53 ) {
F_12 ( & V_10 -> V_29 ) ;
return - V_49 ;
}
F_12 ( & V_10 -> V_29 ) ;
if ( V_10 -> V_11 -> V_55 == V_56 )
V_15 = F_28 ( V_10 , V_16 ) ;
if ( V_15 )
return V_15 ;
return V_14 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
int V_51 ;
F_11 ( & V_10 -> V_29 ) ;
V_51 = sprintf ( V_5 , L_7 , V_10 -> V_57 ) ;
F_12 ( & V_10 -> V_29 ) ;
return V_51 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_54 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_54 -> V_9 . V_10 . V_58 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_54 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 <= 0 )
return - V_17 ;
V_54 -> V_9 . V_10 . V_58 = V_16 ;
return V_14 ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_54 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_54 -> V_9 . V_10 . V_59 ? 1 : 0 ) ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_54 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
V_54 -> V_9 . V_10 . V_59 = ( V_16 ? 1 : 0 ) ;
return V_14 ;
}
static int F_34 ( struct V_38 * V_39 , void * V_40 )
{
struct V_6 * V_54 = V_39 -> V_41 ;
int V_60 ;
V_61 ;
if ( V_54 == NULL )
return 0 ;
for ( V_60 = 0 ; V_60 < F_35 ( V_62 ) ; V_60 ++ ) {
if ( ( ( 1 << V_60 ) & V_54 -> V_9 . V_10 . V_63 ) == 0 )
continue;
if ( V_54 -> V_9 . V_10 . V_64 == ( 1 << V_60 ) )
F_18 ( V_39 , L_8 , V_62 [ V_60 ] ) ;
else
F_18 ( V_39 , L_9 , V_62 [ V_60 ] ) ;
}
F_36 ( V_39 , '\n' ) ;
return 0 ;
}
static T_1 F_37 ( struct V_45 * V_45 ,
const char T_3 * V_13 ,
T_2 V_14 , T_4 * V_46 )
{
struct V_6 * V_54 = ( (struct V_38 * ) V_45 -> V_47 ) -> V_41 ;
int V_60 ;
V_61 ;
char V_48 [ 10 ] ;
if ( V_54 == NULL )
return 0 ;
if ( V_14 > sizeof( V_48 ) - 1 )
return - V_49 ;
if ( F_20 ( V_48 , V_13 , V_14 ) )
return - V_50 ;
if ( V_14 > 0 && V_48 [ V_14 - 1 ] == '\n' )
V_48 [ V_14 - 1 ] = '\0' ;
else
V_48 [ V_14 ] = '\0' ;
for ( V_60 = 0 ; V_60 < F_35 ( V_62 ) ; V_60 ++ ) {
if ( ( ( 1 << V_60 ) & V_54 -> V_9 . V_10 . V_63 ) == 0 )
continue;
if ( ! strcmp ( V_48 , V_62 [ V_60 ] ) ) {
V_54 -> V_9 . V_10 . V_64 = 1 << V_60 ;
return V_14 ;
}
}
return - V_49 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_54 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_3 , F_9 ( & V_54 -> V_9 . V_10 . V_65 ) ) ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_54 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_4 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
F_40 ( & V_54 -> V_9 . V_10 . V_65 , V_16 ) ;
return V_14 ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_54 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_66 * V_67 = F_42 ( V_54 ) ;
return sprintf ( V_5 , L_3 , V_67 -> V_68 ) ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_54 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_66 * V_67 = F_42 ( V_54 ) ;
return F_44 ( V_13 , V_14 , & V_67 -> V_68 ) ? :
V_14 ;
}
static T_1 F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_54 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_66 * V_67 = F_42 ( V_54 ) ;
return sprintf ( V_5 , L_3 , V_67 -> V_69 ) ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_54 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_66 * V_67 = F_42 ( V_54 ) ;
return F_44 ( V_13 , V_14 , & V_67 -> V_69 ) ? :
V_14 ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_54 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_3 ,
F_9 ( & V_54 -> V_9 . V_10 . V_70 ) ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
return sprintf ( V_5 , L_1 , V_10 -> V_71 ) ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
struct V_72 * V_73 = & V_10 -> V_11 -> V_74 ;
int V_75 , V_15 ;
unsigned long long V_16 ;
V_15 = F_27 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 >= V_76 )
V_16 >>= V_34 ;
V_75 = ~ ( ( 1 << ( V_10 -> V_77 - V_34 ) ) - 1 ) ;
V_16 = ( V_16 + ~ V_75 ) & V_75 ;
if ( V_16 == 0 || V_16 > V_73 -> V_78 >> V_34 ) {
return - V_17 ;
}
F_11 ( & V_10 -> V_29 ) ;
V_10 -> V_71 = V_16 ;
F_12 ( & V_10 -> V_29 ) ;
return V_14 ;
}
static int F_50 ( struct V_38 * V_79 , void * V_40 )
{
struct V_80 V_81 ;
struct V_6 * V_7 = V_79 -> V_41 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
unsigned long V_82 = 0 , V_83 = 0 , V_84 , V_85 ;
int V_60 ;
F_51 ( & V_81 ) ;
F_11 ( & V_10 -> V_29 ) ;
F_18 ( V_79 , L_10 ,
( V_86 ) V_81 . V_87 , ( unsigned long ) V_81 . V_88 ) ;
F_18 ( V_79 , L_11 ,
V_10 -> V_89 ) ;
F_18 ( V_79 , L_12 ,
V_10 -> V_90 ) ;
F_18 ( V_79 , L_13 ,
F_9 ( & V_10 -> V_91 ) ) ;
F_18 ( V_79 , L_14 ,
F_9 ( & V_10 -> V_92 ) ) ;
F_52 ( V_79 , L_15 ) ;
F_52 ( V_79 , L_16 ) ;
F_52 ( V_79 , L_17 ) ;
V_82 = F_53 ( & V_10 -> V_93 ) ;
V_83 = F_53 ( & V_10 -> V_94 ) ;
V_84 = 0 ;
V_85 = 0 ;
for ( V_60 = 0 ; V_60 < V_95 ; V_60 ++ ) {
unsigned long V_96 = V_10 -> V_93 . V_97 [ V_60 ] ;
unsigned long V_98 = V_10 -> V_94 . V_97 [ V_60 ] ;
V_84 += V_96 ;
V_85 += V_98 ;
F_18 ( V_79 , L_18 ,
1 << V_60 , V_96 , F_54 ( V_96 , V_82 ) ,
F_54 ( V_84 , V_82 ) , V_98 ,
F_54 ( V_98 , V_83 ) ,
F_54 ( V_85 , V_83 ) ) ;
if ( V_84 == V_82 && V_85 == V_83 )
break;
}
F_52 ( V_79 , L_15 ) ;
F_52 ( V_79 , L_19 ) ;
F_52 ( V_79 , L_17 ) ;
V_82 = F_53 ( & V_10 -> V_99 ) ;
V_83 = F_53 ( & V_10 -> V_100 ) ;
V_84 = 0 ;
V_85 = 0 ;
for ( V_60 = 0 ; V_60 < V_95 ; V_60 ++ ) {
unsigned long V_96 = V_10 -> V_99 . V_97 [ V_60 ] ;
unsigned long V_98 = V_10 -> V_100 . V_97 [ V_60 ] ;
V_84 += V_96 ;
V_85 += V_98 ;
F_18 ( V_79 , L_18 ,
V_60 , V_96 , F_54 ( V_96 , V_82 ) ,
F_54 ( V_84 , V_82 ) , V_98 ,
F_54 ( V_98 , V_83 ) ,
F_54 ( V_85 , V_83 ) ) ;
if ( V_84 == V_82 && V_85 == V_83 )
break;
}
F_52 ( V_79 , L_15 ) ;
F_52 ( V_79 , L_20 ) ;
F_52 ( V_79 , L_17 ) ;
V_82 = F_53 ( & V_10 -> V_101 ) ;
V_83 = F_53 ( & V_10 -> V_102 ) ;
V_84 = 0 ;
V_85 = 0 ;
for ( V_60 = 0 ; V_60 < V_95 ; V_60 ++ ) {
unsigned long V_96 = V_10 -> V_101 . V_97 [ V_60 ] ;
unsigned long V_98 = V_10 -> V_102 . V_97 [ V_60 ] ;
V_84 += V_96 ;
V_85 += V_98 ;
F_18 ( V_79 , L_18 ,
( V_60 == 0 ) ? 0 : 1 << ( V_60 - 1 ) ,
V_96 , F_54 ( V_96 , V_82 ) , F_54 ( V_84 , V_82 ) ,
V_98 , F_54 ( V_98 , V_83 ) , F_54 ( V_85 , V_83 ) ) ;
if ( V_84 == V_82 && V_85 == V_83 )
break;
}
F_12 ( & V_10 -> V_29 ) ;
return 0 ;
}
static T_1 F_55 ( struct V_45 * V_45 ,
const char T_3 * V_5 ,
T_2 V_51 , T_4 * V_46 )
{
struct V_38 * V_79 = V_45 -> V_47 ;
struct V_6 * V_7 = V_79 -> V_41 ;
struct V_19 * V_10 = & V_7 -> V_9 . V_10 ;
F_56 ( & V_10 -> V_99 ) ;
F_56 ( & V_10 -> V_100 ) ;
F_56 ( & V_10 -> V_93 ) ;
F_56 ( & V_10 -> V_94 ) ;
F_56 ( & V_10 -> V_101 ) ;
F_56 ( & V_10 -> V_102 ) ;
return V_51 ;
}
static int F_57 ( struct V_38 * V_79 , void * V_40 )
{
struct V_80 V_81 ;
struct V_6 * V_7 = V_79 -> V_41 ;
struct V_103 * V_104 = & F_42 ( V_7 ) -> V_105 ;
F_51 ( & V_81 ) ;
F_18 ( V_79 , L_10 ,
( V_86 ) V_81 . V_87 , ( unsigned long ) V_81 . V_88 ) ;
F_18 ( V_79 , L_21 ,
V_104 -> V_106 ) ;
F_18 ( V_79 , L_22 ,
V_104 -> V_107 ) ;
F_18 ( V_79 , L_23 ,
V_104 -> V_108 ) ;
return 0 ;
}
static T_1 F_58 ( struct V_45 * V_45 ,
const char T_3 * V_5 ,
T_2 V_51 , T_4 * V_46 )
{
struct V_38 * V_79 = V_45 -> V_47 ;
struct V_6 * V_7 = V_79 -> V_41 ;
struct V_103 * V_104 = & F_42 ( V_7 ) -> V_105 ;
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
return V_51 ;
}
int F_59 ( struct V_6 * V_7 )
{
int V_15 ;
V_15 = F_60 ( V_7 -> V_109 , L_24 , 0644 ,
& V_110 , V_7 ) ;
if ( V_15 == 0 )
V_15 = F_61 ( V_7 , L_25 , 0644 ,
& V_111 , V_7 ) ;
return V_15 ;
}
void F_62 ( struct V_112 * V_113 )
{
V_113 -> V_114 = & V_115 ;
V_113 -> V_116 = V_117 ;
}
