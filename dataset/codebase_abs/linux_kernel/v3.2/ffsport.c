int F_1 ( T_1 V_1 )
{
int V_2 = 0 ;
if ( V_1 >= 1 << 16 ) {
V_1 >>= 16 ;
V_2 += 16 ;
}
if ( V_1 >= 1 << 8 ) {
V_1 >>= 8 ;
V_2 += 8 ;
}
if ( V_1 >= 1 << 4 ) {
V_1 >>= 4 ;
V_2 += 4 ;
}
if ( V_1 >= 1 << 2 ) {
V_1 >>= 2 ;
V_2 += 2 ;
}
if ( V_1 >= 1 << 1 )
V_2 += 1 ;
return ( ( V_1 == 0 ) ? ( 0 ) : V_2 ) ;
}
T_2 F_2 ( T_2 V_3 , T_1 V_4 )
{
return ( T_2 ) ( V_3 >> F_1 ( V_4 ) ) ;
}
T_2 F_3 ( T_2 V_3 , T_1 V_5 )
{
T_2 V_6 = 0 ;
if ( V_5 == 1 ) {
V_6 = ( V_3 >> V_7 . V_8 ) ;
V_6 = V_6 * V_7 . V_9 ;
} else if ( V_5 == 2 ) {
V_6 = ( V_3 >> V_7 . V_10 ) ;
V_6 = V_6 * V_7 . V_11 ;
}
V_6 = V_3 - V_6 ;
return V_6 ;
}
static int F_4 ( void )
{
F_5 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
if ( V_14 == F_6 () ) {
F_7 ( V_15 L_2 ) ;
return - V_16 ;
}
#if V_17
if ( F_8 () )
return - V_18 ;
else
return 0 ;
#endif
return 0 ;
}
static int F_9 ( unsigned long V_19 )
{
T_3 * V_20 ;
struct V_21 V_22 ;
int V_6 = V_23 ;
if ( F_10 ( & V_22 , ( void V_24 * ) V_19 , sizeof( V_22 ) ) )
return - V_16 ;
V_20 = F_11 ( V_25 . V_26 , V_27 ) ;
if ( ! V_20 ) {
F_7 ( V_15 L_3
L_4 ) ;
return - V_28 ;
}
F_12 ( & V_29 ) ;
V_6 = F_13 ( V_20 ,
( T_2 ) V_22 . V_30 * V_25 . V_26 ) ;
F_14 ( & V_29 ) ;
if ( F_15 ( ( void V_24 * ) V_22 . V_31 , V_20 ,
V_25 . V_26 ) ) {
F_7 ( V_15 L_3
L_5 ) ;
F_16 ( V_20 ) ;
return - V_16 ;
}
F_16 ( V_20 ) ;
return V_6 ;
}
static int F_17 ( unsigned long V_19 )
{
T_3 * V_20 ;
struct V_21 V_22 ;
int V_6 = V_23 ;
if ( F_10 ( & V_22 , ( void V_24 * ) V_19 , sizeof( V_22 ) ) )
return - V_16 ;
V_20 = F_18 ( ( void V_24 * ) V_22 . V_31 ,
V_25 . V_26 ) ;
if ( F_19 ( V_20 ) ) {
F_7 ( V_15 L_6
L_5 ) ;
return F_20 ( V_20 ) ;
}
F_12 ( & V_29 ) ;
V_6 = F_21 ( V_20 ,
( T_2 ) V_22 . V_30 * V_25 . V_26 ) ;
F_14 ( & V_29 ) ;
F_16 ( V_20 ) ;
return V_6 ;
}
static int F_22 ( void )
{
return V_25 . V_32 / 10 ;
}
static int F_23 ( void )
{
T_1 V_33 , V_34 ;
V_34 = V_25 . V_26 *
V_25 . V_35 ;
V_33 = ( V_36 * 1024 * 1024 ) / V_34 ;
if ( ( V_33 < 1 ) || ( V_33 >= V_25 . V_32 ) )
V_33 = 1 ;
return V_33 ;
}
static int F_24 ( struct V_37 * V_38 , struct V_39 * V_40 )
{
T_2 V_41 , V_3 ;
T_1 V_42 , V_43 ;
T_1 V_44 , V_45 ;
T_1 V_46 , V_47 = 0 ;
char * V_20 ;
T_1 V_48 = V_25 . V_26 >> 9 ;
V_41 = ( T_2 ) ( F_25 ( V_40 ) ) << 9 ;
V_41 += V_25 . V_26 *
V_25 . V_35 *
V_49 ;
if ( V_40 -> V_50 & V_51 ) {
if ( F_4 () )
return - V_18 ;
else
return 0 ;
}
if ( V_40 -> V_50 != V_52 )
return - V_18 ;
if ( F_25 ( V_40 ) + F_26 ( V_40 ) > F_27 ( V_38 -> V_53 ) ) {
F_7 ( V_15 L_7
L_8
L_9 ,
( int ) F_25 ( V_40 ) ,
F_26 ( V_40 ) ,
( int ) F_27 ( V_38 -> V_53 ) ) ;
return - V_18 ;
}
V_42 = V_41 >> 9 ;
V_43 = V_42 / V_48 ;
V_46 = V_42 - V_43 * V_48 ;
V_3 = ( T_2 ) V_43 * V_48 * 512 ;
V_20 = V_40 -> V_54 ;
V_44 = F_26 ( V_40 ) ;
if ( V_46 )
V_47 = ( V_48 - V_46 ) < V_44 ? ( V_48 - V_46 ) : V_44 ;
switch ( F_28 ( V_40 ) ) {
case V_55 :
if ( V_46 ) {
if ( F_13 ( V_38 -> V_56 , V_3 ) ) {
F_7 ( V_15 L_10 ,
__FILE__ , __LINE__ ) ;
return - V_18 ;
}
memcpy ( V_20 , V_38 -> V_56 + ( V_46 << 9 ) , V_47 << 9 ) ;
V_3 += V_25 . V_26 ;
V_20 += V_47 << 9 ;
V_44 -= V_47 ;
}
for ( V_45 = V_44 / V_48 ; V_45 > 0 ; V_45 -- ) {
if ( F_13 ( V_20 , V_3 ) ) {
F_7 ( V_15 L_10 ,
__FILE__ , __LINE__ ) ;
return - V_18 ;
}
V_3 += V_25 . V_26 ;
V_20 += V_25 . V_26 ;
}
if ( V_44 % V_48 ) {
if ( F_13 ( V_38 -> V_56 , V_3 ) ) {
F_7 ( V_15 L_10 ,
__FILE__ , __LINE__ ) ;
return - V_18 ;
}
memcpy ( V_20 , V_38 -> V_56 , ( V_44 % V_48 ) << 9 ) ;
}
#if V_17
if ( F_8 () )
return - V_18 ;
else
return 0 ;
#endif
return 0 ;
case V_57 :
if ( V_46 ) {
if ( F_13 ( V_38 -> V_56 , V_3 ) ) {
F_7 ( V_15 L_10 ,
__FILE__ , __LINE__ ) ;
return - V_18 ;
}
memcpy ( V_38 -> V_56 + ( V_46 << 9 ) , V_20 , V_47 << 9 ) ;
if ( F_21 ( V_38 -> V_56 , V_3 ) ) {
F_7 ( V_15 L_10 ,
__FILE__ , __LINE__ ) ;
return - V_18 ;
}
V_3 += V_25 . V_26 ;
V_20 += V_47 << 9 ;
V_44 -= V_47 ;
}
for ( V_45 = V_44 / V_48 ; V_45 > 0 ; V_45 -- ) {
if ( F_21 ( V_20 , V_3 ) ) {
F_7 ( V_15 L_10 ,
__FILE__ , __LINE__ ) ;
return - V_18 ;
}
V_3 += V_25 . V_26 ;
V_20 += V_25 . V_26 ;
}
if ( V_44 % V_48 ) {
if ( F_13 ( V_38 -> V_56 , V_3 ) ) {
F_7 ( V_15 L_10 ,
__FILE__ , __LINE__ ) ;
return - V_18 ;
}
memcpy ( V_38 -> V_56 , V_20 , ( V_44 % V_48 ) << 9 ) ;
if ( F_21 ( V_38 -> V_56 , V_3 ) ) {
F_7 ( V_15 L_10 ,
__FILE__ , __LINE__ ) ;
return - V_18 ;
}
}
#if V_17
if ( F_8 () )
return - V_18 ;
else
return 0 ;
#endif
return 0 ;
default:
F_7 ( V_58 L_11 , F_28 ( V_40 ) ) ;
return - V_18 ;
}
}
static int F_29 ( void * V_19 )
{
struct V_37 * V_38 = V_19 ;
struct V_59 * V_60 = V_38 -> V_61 ;
struct V_39 * V_40 = NULL ;
V_62 -> V_63 |= V_64 ;
F_30 ( V_60 -> V_65 ) ;
while ( ! F_31 () ) {
int V_66 ;
if ( ! V_40 ) {
V_40 = F_32 ( V_60 ) ;
if ( ! V_40 ) {
F_33 ( V_67 ) ;
F_34 ( V_60 -> V_65 ) ;
F_35 () ;
F_30 ( V_60 -> V_65 ) ;
continue;
}
}
F_34 ( V_60 -> V_65 ) ;
F_12 ( & V_29 ) ;
V_66 = F_24 ( V_38 , V_40 ) ;
F_14 ( & V_29 ) ;
F_30 ( V_60 -> V_65 ) ;
if ( ! F_36 ( V_40 , V_66 ) )
V_40 = NULL ;
}
if ( V_40 )
F_37 ( V_40 , - V_18 ) ;
F_34 ( V_60 -> V_65 ) ;
return 0 ;
}
static void F_38 ( struct V_59 * V_60 )
{
struct V_37 * V_68 = V_60 -> V_69 ;
F_39 ( V_68 -> V_70 ) ;
}
static int F_40 ( struct V_71 * V_72 , T_4 V_73 )
{
F_5 ( V_74 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
return 0 ;
}
static int F_41 ( struct V_75 * V_76 , T_4 V_73 )
{
int V_77 ;
F_5 ( V_74 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
F_12 ( & V_29 ) ;
V_77 = F_4 () ;
F_14 ( & V_29 ) ;
return 0 ;
}
static int F_42 ( struct V_71 * V_72 , struct V_78 * V_79 )
{
V_79 -> V_80 = 4 ;
V_79 -> V_81 = 16 ;
V_79 -> V_82 = F_27 ( V_72 -> V_83 ) / ( 4 * 16 ) ;
F_5 ( V_12 ,
L_12 ,
V_79 -> V_80 , V_79 -> V_81 , V_79 -> V_82 ) ;
return 0 ;
}
int F_43 ( struct V_71 * V_72 , T_4 V_73 ,
unsigned int V_84 , unsigned long V_19 )
{
int V_77 ;
F_5 ( V_85 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
switch ( V_84 ) {
case V_86 :
F_5 ( V_12 ,
L_13
L_14 ) ;
if ( V_23 != F_44 () )
return - V_16 ;
return 0 ;
case V_87 :
F_5 ( V_12 ,
L_15
L_14 ) ;
if ( V_23 != F_45 () )
return - V_16 ;
return 0 ;
case V_88 :
F_5 ( V_12 , L_16
L_14 ) ;
if ( V_23 != F_46 () )
return - V_16 ;
return 0 ;
case V_89 :
F_5 ( V_12 , L_17
L_14 ) ;
F_12 ( & V_29 ) ;
V_77 = F_4 () ;
F_14 ( & V_29 ) ;
return V_77 ;
case V_90 :
F_5 ( V_12 , L_18
L_19 ) ;
if ( F_15 ( ( void V_24 * ) V_19 ,
F_47 () ,
F_48 () ) )
return - V_16 ;
return 0 ;
case V_91 :
F_5 ( V_12 , L_18
L_20 ) ;
if ( F_15 ( ( void V_24 * ) V_19 ,
F_49 () ,
F_50 () ) )
return - V_16 ;
return 0 ;
case V_92 :
F_5 ( V_12 , L_18
L_21 ) ;
if ( F_15 ( ( void V_24 * ) V_19 , & V_25 ,
sizeof( V_25 ) ) )
return - V_16 ;
return 0 ;
case V_93 :
F_5 ( V_12 , L_18
L_22 ) ;
return F_17 ( V_19 ) ;
case V_94 :
F_5 ( V_12 , L_18
L_23 ) ;
return F_9 ( V_19 ) ;
}
return - V_95 ;
}
int F_51 ( struct V_71 * V_72 , T_4 V_73 ,
unsigned int V_84 , unsigned long V_19 )
{
int V_77 ;
F_12 ( & V_96 ) ;
V_77 = F_43 ( V_72 , V_73 , V_84 , V_19 ) ;
F_14 ( & V_96 ) ;
return V_77 ;
}
static int F_52 ( struct V_37 * V_97 , int V_98 )
{
int V_33 ;
T_1 V_99 ;
F_5 ( V_85 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
memset ( V_97 , 0 , sizeof( struct V_37 ) ) ;
F_5 ( V_74 , L_24
L_25 ,
F_23 () ,
F_22 () ) ;
V_33 = F_22 () + F_23 () ;
V_97 -> V_100 = ( T_2 ) V_25 . V_26 *
V_25 . V_35 *
( V_25 . V_32 - V_33 ) ;
V_49 = F_23 () ;
F_53 ( & V_97 -> V_101 ) ;
V_97 -> V_56 = F_11 ( V_25 . V_26 , V_27 ) ;
if ( ! V_97 -> V_56 ) {
F_7 ( V_15 L_26 ,
__FILE__ , __LINE__ ) ;
goto V_102;
}
V_97 -> V_61 = F_54 ( F_38 , & V_97 -> V_101 ) ;
if ( V_97 -> V_61 == NULL ) {
F_7 ( V_15
L_27
L_28 ) ;
goto V_102;
}
V_97 -> V_61 -> V_69 = V_97 ;
F_55 ( V_97 -> V_61 , 512 ) ;
F_56 ( V_97 -> V_61 , V_51 ) ;
V_97 -> V_70 = F_57 ( F_29 , V_97 , L_29 ) ;
if ( F_19 ( V_97 -> V_70 ) ) {
F_58 ( V_97 -> V_61 ) ;
F_59 ( V_103 , V_104 ) ;
return F_20 ( V_97 -> V_70 ) ;
}
V_97 -> V_53 = F_60 ( V_105 ) ;
if ( ! V_97 -> V_53 ) {
F_7 ( V_15
L_30 ) ;
goto V_102;
}
V_97 -> V_53 -> V_106 = V_103 ;
V_97 -> V_53 -> V_107 = V_98 * V_105 ;
V_97 -> V_53 -> V_108 = & V_109 ;
V_97 -> V_53 -> V_61 = V_97 -> V_61 ;
V_97 -> V_53 -> V_110 = V_97 ;
snprintf ( V_97 -> V_53 -> V_111 , 32 , L_31 , V_104 , V_98 + 'a' ) ;
V_99 = V_97 -> V_100 >> 9 ;
F_5 ( V_74 , L_32 , V_99 ) ;
F_61 ( V_97 -> V_53 , V_99 ) ;
F_62 ( V_97 -> V_53 ) ;
return 0 ;
V_102:
return - V_28 ;
}
static void F_63 ( void * V_112 , T_5 V_113 )
{
int V_114 ;
if ( V_23 != F_64 ( & V_25 ) ) {
F_7 ( V_15 L_33
L_34 ) ;
return;
} else {
F_5 ( V_74 , L_35
L_36
L_37 ,
( int ) V_25 . V_115 ,
( int ) V_25 . V_35 ,
( int ) V_25 . V_26 ,
( int ) V_25 . V_116 ) ;
}
F_7 ( V_117 L_38 ) ;
if ( F_65 () != V_23 ) {
F_7 ( V_15 L_39
L_34 ) ;
goto V_118;
}
F_7 ( V_117 L_40 ) ;
V_103 = F_66 ( 0 , V_104 ) ;
if ( V_103 <= 0 ) {
F_7 ( V_15 L_41 ,
V_103 ) ;
goto V_118;
}
for ( V_114 = 0 ; V_114 < V_119 ; V_114 ++ )
if ( F_52 ( & V_120 [ V_114 ] , V_114 ) == - V_28 )
goto V_121;
F_5 ( V_12 ,
L_42 ,
V_103 ) ;
return;
V_121:
F_59 ( V_103 , V_104 ) ;
V_118:
F_67 () ;
F_7 ( V_15 L_43 ) ;
}
int F_68 ()
{
F_69 ( F_63 , NULL ) ;
return 0 ;
}
static int F_70 ( void )
{
F_7 ( V_117 L_44 , V_122 ) ;
F_71 ( & V_29 ) ;
if ( V_23 != F_72 () ) {
F_7 ( V_15 L_45
L_34 ) ;
return - V_123 ;
}
return 0 ;
}
static void T_6 F_73 ( void )
{
int V_114 ;
F_5 ( V_85 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
for ( V_114 = 0 ; V_114 < V_119 ; V_114 ++ ) {
struct V_37 * V_97 = & V_120 [ V_114 ] ;
if ( V_97 -> V_53 ) {
F_74 ( V_97 -> V_53 ) ;
F_75 ( V_97 -> V_53 ) ;
}
if ( V_97 -> V_61 )
F_58 ( V_97 -> V_61 ) ;
F_16 ( V_97 -> V_56 ) ;
}
F_59 ( V_103 , V_104 ) ;
F_12 ( & V_29 ) ;
F_4 () ;
F_14 ( & V_29 ) ;
F_67 () ;
F_76 () ;
F_5 ( V_12 ,
L_46 ,
V_103 ) ;
}
