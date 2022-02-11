static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 ) ;
F_3 ( V_2 , L_1 , ! V_5 -> V_7 . V_8 . V_9 -> V_10 ) ;
F_4 ( V_5 ) ;
return 0 ;
}
static T_1 F_5 ( struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_6 ;
int V_16 , V_17 ;
V_17 = F_6 ( V_12 , V_13 , & V_16 ) ;
if ( V_17 )
return V_17 ;
if ( V_16 < 0 || V_16 > 1 )
return - V_18 ;
if ( V_5 -> V_7 . V_8 . V_9 -> V_10 == V_16 )
V_17 = F_7 ( V_5 -> V_7 . V_8 . V_9 , V_16 ) ;
else
F_8 ( V_19 , L_2 , V_16 ) ;
return V_13 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_8 = & V_5 -> V_7 . V_8 ;
F_10 ( & V_8 -> V_21 ) ;
F_3 ( V_2 , L_3 , V_8 -> V_22 ) ;
F_11 ( & V_8 -> V_21 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_6 ;
struct V_20 * V_8 = & V_5 -> V_7 . V_8 ;
struct V_23 * V_24 = V_8 -> V_9 -> V_25 ;
int V_16 , V_17 ;
V_17 = F_6 ( V_12 , V_13 , & V_16 ) ;
if ( V_17 )
return V_17 ;
if ( V_16 < 1 || V_16 > V_26 )
return - V_18 ;
F_2 ( V_5 ) ;
if ( V_24 && V_16 > V_8 -> V_22 )
V_24 -> V_27 ( V_24 , V_16 - V_8 -> V_22 ) ;
F_10 ( & V_8 -> V_21 ) ;
V_8 -> V_22 = V_16 ;
F_11 ( & V_8 -> V_21 ) ;
F_4 ( V_5 ) ;
return V_13 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_8 = & V_5 -> V_7 . V_8 ;
long V_16 ;
int V_28 ;
F_10 ( & V_8 -> V_21 ) ;
V_16 = V_8 -> V_29 ;
F_11 ( & V_8 -> V_21 ) ;
V_28 = 1 << 20 ;
return F_14 ( V_2 , V_16 , V_28 ) ;
}
static T_1 F_15 ( struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_6 ;
struct V_20 * V_8 = & V_5 -> V_7 . V_8 ;
int V_30 , V_28 , V_17 ;
V_28 = 1 << ( 20 - V_31 ) ;
V_17 = F_16 ( V_12 , V_13 , & V_30 , V_28 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 <= 0 ||
V_30 > V_32 << ( 20 - V_31 ) ||
V_30 > V_33 / 4 )
return - V_18 ;
F_10 ( & V_8 -> V_21 ) ;
V_8 -> V_29 = ( V_34 ) ( V_30 << V_31 ) ;
F_17 ( V_8 ) ;
F_11 ( & V_8 -> V_21 ) ;
return V_13 ;
}
static int F_18 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_8 = & V_5 -> V_7 . V_8 ;
int V_35 = 20 - V_31 ;
F_3 ( V_2 ,
L_4
L_5 ,
( F_19 ( & V_8 -> V_36 ) +
F_19 ( & V_8 -> V_37 ) ) >> V_35 ,
F_19 ( & V_8 -> V_37 ) ) ;
return 0 ;
}
static T_1 F_20 ( struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_6 ;
struct V_20 * V_8 = & V_5 -> V_7 . V_8 ;
int V_30 , V_28 , V_17 ;
char V_38 [ 128 ] ;
if ( V_13 >= sizeof( V_38 ) )
return - V_39 ;
if ( F_21 ( V_38 , V_12 , V_13 ) )
return - V_40 ;
V_38 [ V_13 ] = 0 ;
V_28 = 1 << ( 20 - V_31 ) ;
V_12 += F_22 ( V_38 , L_6 , & V_13 ) -
V_38 ;
V_17 = F_16 ( V_12 , V_13 , & V_30 , V_28 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 < 0 )
return - V_18 ;
V_17 = F_19 ( & V_8 -> V_36 ) - V_30 ;
if ( V_17 > 0 )
( void ) F_23 ( V_8 , V_17 ) ;
return V_13 ;
}
static int F_24 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_8 = & V_5 -> V_7 . V_8 ;
F_10 ( & V_8 -> V_21 ) ;
F_3 ( V_2 , L_7 , V_8 -> V_41 ) ;
F_11 ( & V_8 -> V_21 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_8 = & V_5 -> V_7 . V_8 ;
F_10 ( & V_8 -> V_21 ) ;
F_3 ( V_2 , L_7 , V_8 -> V_42 ) ;
F_11 ( & V_8 -> V_21 ) ;
return 0 ;
}
static T_1 F_26 ( struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_43 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_6 ;
struct V_20 * V_8 = & V_43 -> V_7 . V_8 ;
int V_17 ;
T_5 V_16 ;
if ( V_43 == NULL )
return 0 ;
V_17 = F_27 ( V_12 , V_13 , & V_16 ) ;
if ( V_17 )
return V_17 ;
F_10 ( & V_8 -> V_21 ) ;
if ( V_16 >= V_8 -> V_42 ) {
F_11 ( & V_8 -> V_21 ) ;
return 0 ;
}
F_11 ( & V_8 -> V_21 ) ;
F_2 ( V_43 ) ;
if ( V_8 -> V_9 -> V_44 == V_45 )
V_17 = F_28 ( V_8 , V_16 ) ;
F_4 ( V_43 ) ;
if ( V_17 )
return V_17 ;
return V_13 ;
}
static int F_29 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_8 = & V_5 -> V_7 . V_8 ;
F_10 ( & V_8 -> V_21 ) ;
F_3 ( V_2 , L_7 , V_8 -> V_46 ) ;
F_11 ( & V_8 -> V_21 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_43 = V_2 -> V_6 ;
if ( V_43 == NULL )
return 0 ;
F_3 ( V_2 , L_1 , V_43 -> V_7 . V_8 . V_47 ) ;
return 0 ;
}
static T_1 F_31 ( struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_43 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_6 ;
int V_16 , V_17 ;
if ( V_43 == NULL )
return 0 ;
V_17 = F_6 ( V_12 , V_13 , & V_16 ) ;
if ( V_17 )
return V_17 ;
if ( V_16 <= 0 )
return - V_18 ;
V_43 -> V_7 . V_8 . V_47 = V_16 ;
return V_13 ;
}
static int F_32 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_43 = V_2 -> V_6 ;
if ( V_43 == NULL )
return 0 ;
F_3 ( V_2 , L_1 , V_43 -> V_7 . V_8 . V_48 ? 1 : 0 ) ;
return 0 ;
}
static T_1 F_33 ( struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_43 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_6 ;
int V_16 , V_17 ;
if ( V_43 == NULL )
return 0 ;
V_17 = F_6 ( V_12 , V_13 , & V_16 ) ;
if ( V_17 )
return V_17 ;
V_43 -> V_7 . V_8 . V_48 = ( V_16 ? 1 : 0 ) ;
return V_13 ;
}
static int F_34 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_43 = V_2 -> V_6 ;
int V_49 ;
V_50 ;
if ( V_43 == NULL )
return 0 ;
for ( V_49 = 0 ; V_49 < F_35 ( V_51 ) ; V_49 ++ ) {
if ( ( ( 1 << V_49 ) & V_43 -> V_7 . V_8 . V_52 ) == 0 )
continue;
if ( V_43 -> V_7 . V_8 . V_53 == ( 1 << V_49 ) )
F_3 ( V_2 , L_8 , V_51 [ V_49 ] ) ;
else
F_3 ( V_2 , L_9 , V_51 [ V_49 ] ) ;
}
F_36 ( V_2 , '\n' ) ;
return 0 ;
}
static T_1 F_37 ( struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_43 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_6 ;
int V_49 ;
V_50 ;
char V_38 [ 10 ] ;
if ( V_43 == NULL )
return 0 ;
if ( V_13 > sizeof( V_38 ) - 1 )
return - V_39 ;
if ( F_21 ( V_38 , V_12 , V_13 ) )
return - V_40 ;
if ( V_13 > 0 && V_38 [ V_13 - 1 ] == '\n' )
V_38 [ V_13 - 1 ] = '\0' ;
else
V_38 [ V_13 ] = '\0' ;
for ( V_49 = 0 ; V_49 < F_35 ( V_51 ) ; V_49 ++ ) {
if ( ( ( 1 << V_49 ) & V_43 -> V_7 . V_8 . V_52 ) == 0 )
continue;
if ( ! strcmp ( V_38 , V_51 [ V_49 ] ) ) {
V_43 -> V_7 . V_8 . V_53 = 1 << V_49 ;
return V_13 ;
}
}
return - V_39 ;
}
static int F_38 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_43 = V_2 -> V_6 ;
F_3 ( V_2 , L_3 , F_19 ( & V_43 -> V_7 . V_8 . V_54 ) ) ;
return 0 ;
}
static T_1 F_39 ( struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_43 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_6 ;
int V_16 , V_17 ;
V_17 = F_6 ( V_12 , V_13 , & V_16 ) ;
if ( V_17 )
return V_17 ;
if ( V_16 < 0 )
return - V_39 ;
F_40 ( & V_43 -> V_7 . V_8 . V_54 , V_16 ) ;
return V_13 ;
}
static int F_41 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_43 = V_2 -> V_6 ;
struct V_55 * V_56 = F_42 ( V_43 ) ;
F_3 ( V_2 , L_3 , V_56 -> V_57 ) ;
return 0 ;
}
static T_1 F_43 ( struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_43 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_6 ;
struct V_55 * V_56 = F_42 ( V_43 ) ;
return F_6 ( V_12 , V_13 , & V_56 -> V_57 ) ? :
V_13 ;
}
static int F_44 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_43 = V_2 -> V_6 ;
struct V_55 * V_56 = F_42 ( V_43 ) ;
F_3 ( V_2 , L_3 , V_56 -> V_58 ) ;
return 0 ;
}
static T_1 F_45 ( struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_43 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_6 ;
struct V_55 * V_56 = F_42 ( V_43 ) ;
return F_6 ( V_12 , V_13 , & V_56 -> V_58 ) ? :
V_13 ;
}
static int F_46 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_43 = V_2 -> V_6 ;
F_3 ( V_2 , L_3 , F_19 ( & V_43 -> V_7 . V_8 . V_59 ) ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , void * V_3 )
{
return F_48 ( V_2 , V_2 -> V_6 ) ;
}
static T_1 F_49 ( struct V_11 * V_11 ,
const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_6 ;
struct V_20 * V_8 = & V_5 -> V_7 . V_8 ;
struct V_60 * V_61 = & V_8 -> V_9 -> V_62 ;
int V_63 , V_17 ;
T_5 V_16 ;
V_17 = F_27 ( V_12 , V_13 , & V_16 ) ;
if ( V_17 )
return V_17 ;
if ( V_16 >= V_64 )
V_16 >>= V_31 ;
F_2 ( V_5 ) ;
V_63 = ~ ( ( 1 << ( V_8 -> V_65 - V_31 ) ) - 1 ) ;
V_16 = ( V_16 + ~ V_63 ) & V_63 ;
if ( V_16 == 0 || V_16 > V_61 -> V_66 >> V_31 ) {
F_4 ( V_5 ) ;
return - V_18 ;
}
F_10 ( & V_8 -> V_21 ) ;
V_8 -> V_67 = V_16 ;
F_11 ( & V_8 -> V_21 ) ;
F_4 ( V_5 ) ;
return V_13 ;
}
static int F_50 ( struct V_1 * V_68 , void * V_3 )
{
struct V_69 V_70 ;
struct V_4 * V_5 = V_68 -> V_6 ;
struct V_20 * V_8 = & V_5 -> V_7 . V_8 ;
unsigned long V_71 = 0 , V_72 = 0 , V_73 , V_74 ;
int V_49 ;
F_51 ( & V_70 ) ;
F_10 ( & V_8 -> V_21 ) ;
F_3 ( V_68 , L_10 ,
V_70 . V_75 , ( unsigned long ) V_70 . V_76 ) ;
F_3 ( V_68 , L_11 ,
V_8 -> V_77 ) ;
F_3 ( V_68 , L_12 ,
V_8 -> V_78 ) ;
F_3 ( V_68 , L_13 ,
F_19 ( & V_8 -> V_79 ) ) ;
F_3 ( V_68 , L_14 ,
F_19 ( & V_8 -> V_80 ) ) ;
F_52 ( V_68 , L_15 ) ;
F_52 ( V_68 , L_16 ) ;
F_52 ( V_68 , L_17 ) ;
V_71 = F_53 ( & V_8 -> V_81 ) ;
V_72 = F_53 ( & V_8 -> V_82 ) ;
V_73 = 0 ;
V_74 = 0 ;
for ( V_49 = 0 ; V_49 < V_83 ; V_49 ++ ) {
unsigned long V_84 = V_8 -> V_81 . V_85 [ V_49 ] ;
unsigned long V_86 = V_8 -> V_82 . V_85 [ V_49 ] ;
V_73 += V_84 ;
V_74 += V_86 ;
F_3 ( V_68 , L_18 ,
1 << V_49 , V_84 , F_54 ( V_84 , V_71 ) ,
F_54 ( V_73 , V_71 ) , V_86 ,
F_54 ( V_86 , V_72 ) ,
F_54 ( V_74 , V_72 ) ) ;
if ( V_73 == V_71 && V_74 == V_72 )
break;
}
F_52 ( V_68 , L_15 ) ;
F_52 ( V_68 , L_19 ) ;
F_52 ( V_68 , L_17 ) ;
V_71 = F_53 ( & V_8 -> V_87 ) ;
V_72 = F_53 ( & V_8 -> V_88 ) ;
V_73 = 0 ;
V_74 = 0 ;
for ( V_49 = 0 ; V_49 < V_83 ; V_49 ++ ) {
unsigned long V_84 = V_8 -> V_87 . V_85 [ V_49 ] ;
unsigned long V_86 = V_8 -> V_88 . V_85 [ V_49 ] ;
V_73 += V_84 ;
V_74 += V_86 ;
F_3 ( V_68 , L_18 ,
V_49 , V_84 , F_54 ( V_84 , V_71 ) ,
F_54 ( V_73 , V_71 ) , V_86 ,
F_54 ( V_86 , V_72 ) ,
F_54 ( V_74 , V_72 ) ) ;
if ( V_73 == V_71 && V_74 == V_72 )
break;
}
F_52 ( V_68 , L_15 ) ;
F_52 ( V_68 , L_20 ) ;
F_52 ( V_68 , L_17 ) ;
V_71 = F_53 ( & V_8 -> V_89 ) ;
V_72 = F_53 ( & V_8 -> V_90 ) ;
V_73 = 0 ;
V_74 = 0 ;
for ( V_49 = 0 ; V_49 < V_83 ; V_49 ++ ) {
unsigned long V_84 = V_8 -> V_89 . V_85 [ V_49 ] ;
unsigned long V_86 = V_8 -> V_90 . V_85 [ V_49 ] ;
V_73 += V_84 ;
V_74 += V_86 ;
F_3 ( V_68 , L_18 ,
( V_49 == 0 ) ? 0 : 1 << ( V_49 - 1 ) ,
V_84 , F_54 ( V_84 , V_71 ) , F_54 ( V_73 , V_71 ) ,
V_86 , F_54 ( V_86 , V_72 ) , F_54 ( V_74 , V_72 ) ) ;
if ( V_73 == V_71 && V_74 == V_72 )
break;
}
F_11 ( & V_8 -> V_21 ) ;
return 0 ;
}
static T_1 F_55 ( struct V_11 * V_11 ,
const char T_2 * V_91 ,
T_3 V_92 , T_4 * V_14 )
{
struct V_1 * V_68 = V_11 -> V_15 ;
struct V_4 * V_5 = V_68 -> V_6 ;
struct V_20 * V_8 = & V_5 -> V_7 . V_8 ;
F_56 ( & V_8 -> V_87 ) ;
F_56 ( & V_8 -> V_88 ) ;
F_56 ( & V_8 -> V_81 ) ;
F_56 ( & V_8 -> V_82 ) ;
F_56 ( & V_8 -> V_89 ) ;
F_56 ( & V_8 -> V_90 ) ;
return V_92 ;
}
static int F_57 ( struct V_1 * V_68 , void * V_3 )
{
struct V_69 V_70 ;
struct V_4 * V_5 = V_68 -> V_6 ;
struct V_93 * V_94 = & F_42 ( V_5 ) -> V_95 ;
F_51 ( & V_70 ) ;
F_3 ( V_68 , L_10 ,
V_70 . V_75 , ( unsigned long ) V_70 . V_76 ) ;
F_3 ( V_68 , L_21 ,
V_94 -> V_96 ) ;
F_3 ( V_68 , L_22 ,
V_94 -> V_97 ) ;
F_3 ( V_68 , L_23 ,
V_94 -> V_98 ) ;
return 0 ;
}
static T_1 F_58 ( struct V_11 * V_11 ,
const char T_2 * V_91 ,
T_3 V_92 , T_4 * V_14 )
{
struct V_1 * V_68 = V_11 -> V_15 ;
struct V_4 * V_5 = V_68 -> V_6 ;
struct V_93 * V_94 = & F_42 ( V_5 ) -> V_95 ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
return V_92 ;
}
int F_59 ( struct V_4 * V_5 )
{
int V_17 ;
V_17 = F_60 ( V_5 -> V_99 , L_24 , 0644 ,
& V_100 , V_5 ) ;
if ( V_17 == 0 )
V_17 = F_61 ( V_5 , L_25 , 0644 ,
& V_101 , V_5 ) ;
return V_17 ;
}
void F_62 ( struct V_102 * V_103 )
{
V_103 -> V_104 = V_105 ;
V_103 -> V_106 = V_107 ;
}
