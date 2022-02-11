static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
F_2 ( V_5 ) ;
V_7 = F_3 ( V_2 , L_1 , ! V_5 -> V_8 . V_9 . V_10 -> V_11 ) ;
F_4 ( V_5 ) ;
return V_7 ;
}
static T_1 F_5 ( struct V_12 * V_12 , const char * V_13 ,
T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
int V_17 , V_7 ;
V_7 = F_6 ( V_13 , V_14 , & V_17 ) ;
if ( V_7 )
return V_7 ;
if ( V_17 < 0 || V_17 > 1 )
return - V_18 ;
if ( V_5 -> V_8 . V_9 . V_10 -> V_11 == V_17 )
V_7 = F_7 ( V_5 -> V_8 . V_9 . V_10 , V_17 ) ;
else
F_8 ( V_19 , L_2 , V_17 ) ;
return V_14 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_9 = & V_5 -> V_8 . V_9 ;
int V_7 ;
F_10 ( & V_9 -> V_21 ) ;
V_7 = F_3 ( V_2 , L_3 , V_9 -> V_22 ) ;
F_11 ( & V_9 -> V_21 ) ;
return V_7 ;
}
static T_1 F_12 ( struct V_12 * V_12 ,
const char * V_13 , T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
struct V_20 * V_9 = & V_5 -> V_8 . V_9 ;
struct V_23 * V_24 = V_9 -> V_10 -> V_25 ;
int V_17 , V_7 ;
V_7 = F_6 ( V_13 , V_14 , & V_17 ) ;
if ( V_7 )
return V_7 ;
if ( V_17 < 1 || V_17 > V_26 )
return - V_18 ;
F_2 ( V_5 ) ;
if ( V_24 && V_17 > V_9 -> V_22 )
V_24 -> V_27 ( V_24 , V_17 - V_9 -> V_22 ) ;
F_10 ( & V_9 -> V_21 ) ;
V_9 -> V_22 = V_17 ;
F_11 ( & V_9 -> V_21 ) ;
F_4 ( V_5 ) ;
return V_14 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_9 = & V_5 -> V_8 . V_9 ;
long V_17 ;
int V_28 ;
F_10 ( & V_9 -> V_21 ) ;
V_17 = V_9 -> V_29 ;
F_11 ( & V_9 -> V_21 ) ;
V_28 = 1 << 20 ;
return F_14 ( V_2 , V_17 , V_28 ) ;
}
static T_1 F_15 ( struct V_12 * V_12 , const char * V_13 ,
T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
struct V_20 * V_9 = & V_5 -> V_8 . V_9 ;
int V_30 , V_28 , V_7 ;
V_28 = 1 << ( 20 - V_31 ) ;
V_7 = F_16 ( V_13 , V_14 , & V_30 , V_28 ) ;
if ( V_7 )
return V_7 ;
if ( V_30 <= 0 ||
V_30 > V_32 << ( 20 - V_31 ) ||
V_30 > V_33 / 4 )
return - V_18 ;
F_10 ( & V_9 -> V_21 ) ;
V_9 -> V_29 = ( V_34 ) ( V_30 << V_31 ) ;
F_17 ( V_9 ) ;
F_11 ( & V_9 -> V_21 ) ;
return V_14 ;
}
static int F_18 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_9 = & V_5 -> V_8 . V_9 ;
int V_35 = 20 - V_31 ;
int V_7 ;
V_7 = F_3 ( V_2 ,
L_4
L_5 ,
( F_19 ( & V_9 -> V_36 ) +
F_19 ( & V_9 -> V_37 ) ) >> V_35 ,
F_19 ( & V_9 -> V_37 ) ) ;
return V_7 ;
}
static T_1 F_20 ( struct V_12 * V_12 , const char * V_13 ,
T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
struct V_20 * V_9 = & V_5 -> V_8 . V_9 ;
int V_30 , V_28 , V_7 ;
V_28 = 1 << ( 20 - V_31 ) ;
V_13 = F_21 ( V_13 , L_6 , & V_14 ) ;
V_7 = F_16 ( V_13 , V_14 , & V_30 , V_28 ) ;
if ( V_7 )
return V_7 ;
if ( V_30 < 0 )
return - V_18 ;
V_7 = F_19 ( & V_9 -> V_36 ) - V_30 ;
if ( V_7 > 0 )
( void ) F_22 ( V_9 , V_7 ) ;
return V_14 ;
}
static int F_23 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_9 = & V_5 -> V_8 . V_9 ;
int V_7 ;
F_10 ( & V_9 -> V_21 ) ;
V_7 = F_3 ( V_2 , L_7 , V_9 -> V_38 ) ;
F_11 ( & V_9 -> V_21 ) ;
return V_7 ;
}
static int F_24 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_9 = & V_5 -> V_8 . V_9 ;
int V_7 ;
F_10 ( & V_9 -> V_21 ) ;
V_7 = F_3 ( V_2 , L_7 , V_9 -> V_39 ) ;
F_11 ( & V_9 -> V_21 ) ;
return V_7 ;
}
static T_1 F_25 ( struct V_12 * V_12 , const char * V_13 ,
T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_40 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
struct V_20 * V_9 = & V_40 -> V_8 . V_9 ;
int V_7 ;
T_4 V_17 ;
if ( V_40 == NULL )
return 0 ;
V_7 = F_26 ( V_13 , V_14 , & V_17 ) ;
if ( V_7 )
return V_7 ;
F_10 ( & V_9 -> V_21 ) ;
if ( V_17 >= V_9 -> V_39 ) {
F_11 ( & V_9 -> V_21 ) ;
return 0 ;
}
F_11 ( & V_9 -> V_21 ) ;
F_2 ( V_40 ) ;
if ( V_9 -> V_10 -> V_41 == V_42 )
V_7 = F_27 ( V_9 , V_17 ) ;
F_4 ( V_40 ) ;
if ( V_7 )
return V_7 ;
return V_14 ;
}
static int F_28 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_9 = & V_5 -> V_8 . V_9 ;
int V_7 ;
F_10 ( & V_9 -> V_21 ) ;
V_7 = F_3 ( V_2 , L_7 , V_9 -> V_43 ) ;
F_11 ( & V_9 -> V_21 ) ;
return V_7 ;
}
static int F_29 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_40 = V_2 -> V_6 ;
if ( V_40 == NULL )
return 0 ;
return F_3 ( V_2 , L_1 ,
V_40 -> V_8 . V_9 . V_44 ) ;
}
static T_1 F_30 ( struct V_12 * V_12 ,
const char * V_13 , T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_40 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
int V_17 , V_7 ;
if ( V_40 == NULL )
return 0 ;
V_7 = F_6 ( V_13 , V_14 , & V_17 ) ;
if ( V_7 )
return V_7 ;
if ( V_17 <= 0 )
return - V_18 ;
V_40 -> V_8 . V_9 . V_44 = V_17 ;
return V_14 ;
}
static int F_31 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_40 = V_2 -> V_6 ;
if ( V_40 == NULL )
return 0 ;
return F_3 ( V_2 , L_1 ,
V_40 -> V_8 . V_9 . V_45 ? 1 : 0 ) ;
}
static T_1 F_32 ( struct V_12 * V_12 , const char * V_13 ,
T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_40 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
int V_17 , V_7 ;
if ( V_40 == NULL )
return 0 ;
V_7 = F_6 ( V_13 , V_14 , & V_17 ) ;
if ( V_7 )
return V_7 ;
V_40 -> V_8 . V_9 . V_45 = ( V_17 ? 1 : 0 ) ;
return V_14 ;
}
static int F_33 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_40 = V_2 -> V_6 ;
int V_46 ;
V_47 ;
if ( V_40 == NULL )
return 0 ;
for ( V_46 = 0 ; V_46 < F_34 ( V_48 ) ; V_46 ++ ) {
if ( ( ( 1 << V_46 ) & V_40 -> V_8 . V_9 . V_49 ) == 0 )
continue;
if ( V_40 -> V_8 . V_9 . V_50 == ( 1 << V_46 ) )
F_3 ( V_2 , L_8 , V_48 [ V_46 ] ) ;
else
F_3 ( V_2 , L_9 , V_48 [ V_46 ] ) ;
}
F_3 ( V_2 , L_10 ) ;
return 0 ;
}
static T_1 F_35 ( struct V_12 * V_12 , const char * V_13 ,
T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_40 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
int V_46 ;
V_47 ;
char V_51 [ 10 ] ;
if ( V_40 == NULL )
return 0 ;
if ( V_14 > sizeof( V_51 ) - 1 )
return - V_52 ;
if ( F_36 ( V_51 , V_13 , V_14 ) )
return - V_53 ;
if ( V_14 > 0 && V_51 [ V_14 - 1 ] == '\n' )
V_51 [ V_14 - 1 ] = '\0' ;
else
V_51 [ V_14 ] = '\0' ;
for ( V_46 = 0 ; V_46 < F_34 ( V_48 ) ; V_46 ++ ) {
if ( ( ( 1 << V_46 ) & V_40 -> V_8 . V_9 . V_49 ) == 0 )
continue;
if ( ! strcmp ( V_51 , V_48 [ V_46 ] ) ) {
V_40 -> V_8 . V_9 . V_50 = 1 << V_46 ;
return V_14 ;
}
}
return - V_52 ;
}
static int F_37 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_40 = V_2 -> V_6 ;
return F_3 ( V_2 , L_3 , F_19 ( & V_40 -> V_8 . V_9 . V_54 ) ) ;
}
static T_1 F_38 ( struct V_12 * V_12 , const char * V_13 ,
T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_40 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
int V_17 , V_7 ;
V_7 = F_6 ( V_13 , V_14 , & V_17 ) ;
if ( V_7 )
return V_7 ;
if ( V_17 < 0 )
return - V_52 ;
F_39 ( & V_40 -> V_8 . V_9 . V_54 , V_17 ) ;
return V_14 ;
}
static int F_40 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_40 = V_2 -> V_6 ;
struct V_55 * V_56 = F_41 ( V_40 ) ;
return F_3 ( V_2 , L_3 , V_56 -> V_57 ) ;
}
static T_1 F_42 ( struct V_12 * V_12 , const char * V_13 ,
T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_40 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
struct V_55 * V_56 = F_41 ( V_40 ) ;
return F_6 ( V_13 , V_14 , & V_56 -> V_57 ) ? :
V_14 ;
}
static int F_43 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_40 = V_2 -> V_6 ;
struct V_55 * V_56 = F_41 ( V_40 ) ;
return F_3 ( V_2 , L_3 , V_56 -> V_58 ) ;
}
static T_1 F_44 ( struct V_12 * V_12 , const char * V_13 ,
T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_40 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
struct V_55 * V_56 = F_41 ( V_40 ) ;
return F_6 ( V_13 , V_14 , & V_56 -> V_58 ) ? :
V_14 ;
}
static int F_45 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_40 = V_2 -> V_6 ;
return F_3 ( V_2 , L_3 ,
F_19 ( & V_40 -> V_8 . V_9 . V_59 ) ) ;
}
static int F_46 ( struct V_1 * V_2 , void * V_3 )
{
return F_47 ( V_2 , V_2 -> V_6 ) ;
}
static T_1 F_48 ( struct V_12 * V_12 ,
const char * V_13 , T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
struct V_20 * V_9 = & V_5 -> V_8 . V_9 ;
struct V_60 * V_61 = & V_9 -> V_10 -> V_62 ;
int V_63 , V_7 ;
T_4 V_17 ;
V_7 = F_26 ( V_13 , V_14 , & V_17 ) ;
if ( V_7 )
return V_7 ;
if ( V_17 >= V_64 )
V_17 >>= V_31 ;
F_2 ( V_5 ) ;
V_63 = ~ ( ( 1 << ( V_9 -> V_65 - V_31 ) ) - 1 ) ;
V_17 = ( V_17 + ~ V_63 ) & V_63 ;
if ( V_17 == 0 || V_17 > V_61 -> V_66 >> V_31 ) {
F_4 ( V_5 ) ;
return - V_18 ;
}
F_10 ( & V_9 -> V_21 ) ;
V_9 -> V_67 = V_17 ;
F_11 ( & V_9 -> V_21 ) ;
F_4 ( V_5 ) ;
return V_14 ;
}
static int F_49 ( struct V_1 * V_68 , void * V_3 )
{
struct V_69 V_70 ;
struct V_4 * V_5 = V_68 -> V_6 ;
struct V_20 * V_9 = & V_5 -> V_8 . V_9 ;
unsigned long V_71 = 0 , V_72 = 0 , V_73 , V_74 ;
int V_46 ;
F_50 ( & V_70 ) ;
F_10 ( & V_9 -> V_21 ) ;
F_3 ( V_68 , L_11 ,
V_70 . V_75 , V_70 . V_76 ) ;
F_3 ( V_68 , L_12 ,
V_9 -> V_77 ) ;
F_3 ( V_68 , L_13 ,
V_9 -> V_78 ) ;
F_3 ( V_68 , L_14 ,
F_19 ( & V_9 -> V_79 ) ) ;
F_3 ( V_68 , L_15 ,
F_19 ( & V_9 -> V_80 ) ) ;
F_3 ( V_68 , L_16 ) ;
F_3 ( V_68 , L_17 ) ;
F_3 ( V_68 , L_18 ) ;
V_71 = F_51 ( & V_9 -> V_81 ) ;
V_72 = F_51 ( & V_9 -> V_82 ) ;
V_73 = 0 ;
V_74 = 0 ;
for ( V_46 = 0 ; V_46 < V_83 ; V_46 ++ ) {
unsigned long V_84 = V_9 -> V_81 . V_85 [ V_46 ] ;
unsigned long V_86 = V_9 -> V_82 . V_85 [ V_46 ] ;
V_73 += V_84 ;
V_74 += V_86 ;
F_3 ( V_68 , L_19 ,
1 << V_46 , V_84 , F_52 ( V_84 , V_71 ) ,
F_52 ( V_73 , V_71 ) , V_86 ,
F_52 ( V_86 , V_72 ) ,
F_52 ( V_74 , V_72 ) ) ;
if ( V_73 == V_71 && V_74 == V_72 )
break;
}
F_3 ( V_68 , L_16 ) ;
F_3 ( V_68 , L_20 ) ;
F_3 ( V_68 , L_18 ) ;
V_71 = F_51 ( & V_9 -> V_87 ) ;
V_72 = F_51 ( & V_9 -> V_88 ) ;
V_73 = 0 ;
V_74 = 0 ;
for ( V_46 = 0 ; V_46 < V_83 ; V_46 ++ ) {
unsigned long V_84 = V_9 -> V_87 . V_85 [ V_46 ] ;
unsigned long V_86 = V_9 -> V_88 . V_85 [ V_46 ] ;
V_73 += V_84 ;
V_74 += V_86 ;
F_3 ( V_68 , L_19 ,
V_46 , V_84 , F_52 ( V_84 , V_71 ) ,
F_52 ( V_73 , V_71 ) , V_86 ,
F_52 ( V_86 , V_72 ) ,
F_52 ( V_74 , V_72 ) ) ;
if ( V_73 == V_71 && V_74 == V_72 )
break;
}
F_3 ( V_68 , L_16 ) ;
F_3 ( V_68 , L_21 ) ;
F_3 ( V_68 , L_18 ) ;
V_71 = F_51 ( & V_9 -> V_89 ) ;
V_72 = F_51 ( & V_9 -> V_90 ) ;
V_73 = 0 ;
V_74 = 0 ;
for ( V_46 = 0 ; V_46 < V_83 ; V_46 ++ ) {
unsigned long V_84 = V_9 -> V_89 . V_85 [ V_46 ] ;
unsigned long V_86 = V_9 -> V_90 . V_85 [ V_46 ] ;
V_73 += V_84 ;
V_74 += V_86 ;
F_3 ( V_68 , L_19 ,
( V_46 == 0 ) ? 0 : 1 << ( V_46 - 1 ) ,
V_84 , F_52 ( V_84 , V_71 ) , F_52 ( V_73 , V_71 ) ,
V_86 , F_52 ( V_86 , V_72 ) , F_52 ( V_74 , V_72 ) ) ;
if ( V_73 == V_71 && V_74 == V_72 )
break;
}
F_11 ( & V_9 -> V_21 ) ;
return 0 ;
}
static T_1 F_53 ( struct V_12 * V_12 , const char * V_91 ,
T_2 V_92 , T_3 * V_15 )
{
struct V_1 * V_68 = V_12 -> V_16 ;
struct V_4 * V_5 = V_68 -> V_6 ;
struct V_20 * V_9 = & V_5 -> V_8 . V_9 ;
F_54 ( & V_9 -> V_87 ) ;
F_54 ( & V_9 -> V_88 ) ;
F_54 ( & V_9 -> V_81 ) ;
F_54 ( & V_9 -> V_82 ) ;
F_54 ( & V_9 -> V_89 ) ;
F_54 ( & V_9 -> V_90 ) ;
return V_92 ;
}
static int F_55 ( struct V_1 * V_68 , void * V_3 )
{
struct V_69 V_70 ;
struct V_4 * V_5 = V_68 -> V_6 ;
struct V_93 * V_94 = & F_41 ( V_5 ) -> V_95 ;
F_50 ( & V_70 ) ;
F_3 ( V_68 , L_11 ,
V_70 . V_75 , V_70 . V_76 ) ;
F_3 ( V_68 , L_22 V_96 L_10 ,
V_94 -> V_97 ) ;
F_3 ( V_68 , L_23 V_96 L_10 ,
V_94 -> V_98 ) ;
F_3 ( V_68 , L_24 V_96 L_10 ,
V_94 -> V_99 ) ;
return 0 ;
}
static T_1 F_56 ( struct V_12 * V_12 , const char * V_91 ,
T_2 V_92 , T_3 * V_15 )
{
struct V_1 * V_68 = V_12 -> V_16 ;
struct V_4 * V_5 = V_68 -> V_6 ;
struct V_93 * V_94 = & F_41 ( V_5 ) -> V_95 ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
return V_92 ;
}
int F_57 ( struct V_4 * V_5 )
{
int V_7 ;
V_7 = F_58 ( V_5 -> V_100 , L_25 , 0644 ,
& V_101 , V_5 ) ;
if ( V_7 == 0 )
V_7 = F_59 ( V_5 , L_26 , 0644 ,
& V_102 , V_5 ) ;
return V_7 ;
}
void F_60 ( struct V_103 * V_104 )
{
V_104 -> V_105 = V_106 ;
V_104 -> V_107 = V_108 ;
}
