static void F_1 ( struct V_1 * V_2 ,
T_1 * V_3 ,
int V_4 )
{
int V_5 ;
int V_6 ;
int V_7 ;
T_2 V_8 ;
T_2 T_3 * V_9 ;
T_1 * V_10 = V_3 ;
V_9 = V_11 -> V_12 + ( V_2 -> V_13 << 15 )
+ ( V_2 -> V_14 << 8 ) ;
V_5 = V_4 >> 2 ;
V_6 = V_4 - ( V_5 << 2 ) ;
if ( V_6 == 0 && V_5 != 0 ) {
V_6 += 4 ;
V_5 -- ;
}
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ ) {
V_8 = F_2 ( * ( T_2 * ) V_10 ) ;
V_10 += 4 ;
F_3 ( V_8 , V_9 ) ;
}
V_9 += V_15 ;
V_8 = 0 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
V_8 |= * V_10 ++ << ( 24 - ( 8 * V_7 ) ) ;
F_3 ( V_8 , V_9 ) ;
return;
}
static void F_4 ( struct V_1 * V_2 ,
const char * V_16 )
{
char V_17 [ V_18 ] ;
struct V_1 V_19 = { . V_13 = V_20 ,
. V_14 = 0 } ;
const char * V_21 ;
const char * V_22 = L_1 ;
T_1 V_23 [ V_24 ] ;
if ( ! V_16 ) {
if ( ! F_5 () )
F_6 ( V_17 , V_25 ) ;
else
strncpy ( V_17 , L_2 , V_18 ) ;
V_17 [ V_18 - 1 ] = 0 ;
V_21 = V_17 ;
} else {
V_21 = V_16 ;
}
V_19 . V_14 = V_26 ;
V_26 = ( V_26 + 1 ) & 0x7f ;
snprintf ( V_23 , V_24 , V_22 , V_2 -> V_13 ,
V_2 -> V_14 , V_21 ) ;
F_1 ( & V_19 , V_23 , strlen ( V_23 ) ) ;
}
static void F_7 ( struct V_1 * V_2 ,
const unsigned char * V_3 ,
int V_4 )
{
F_4 ( V_2 , NULL ) ;
F_1 ( V_2 , ( T_1 * ) V_3 , V_4 ) ;
}
static struct V_1 * F_8 ( T_1 * V_27 ,
int V_28 ,
int V_29 ,
const char * V_16 )
{
struct V_1 * V_2 ;
int V_7 , V_30 , V_31 ;
V_2 = F_9 ( sizeof( struct V_1 ) , V_32 ) ;
if ( V_2 == NULL )
return NULL ;
for ( V_7 = 0 ; V_7 < V_28 ; V_7 ++ )
if ( V_27 [ V_7 ] != 0xff )
break;
if ( V_7 == V_28 ) {
F_10 ( V_2 ) ;
return NULL ;
}
V_31 = 0x80 ;
for ( V_30 = 0 ; V_30 < 8 ; V_30 ++ ) {
if ( ( V_27 [ V_7 ] & V_31 ) == 0 )
break;
V_31 >>= 1 ;
}
V_27 [ V_7 ] |= V_31 ;
V_2 -> V_13 = V_29 ;
V_2 -> V_14 = ( ( V_7 & 0xf ) << 3 ) + V_30 ;
F_4 ( V_2 , V_16 ) ;
return V_2 ;
}
struct V_1 * F_11 ( T_1 type ,
const char * V_16 )
{
struct V_1 * V_2 ;
F_12 ( & V_33 ) ;
switch ( type ) {
case 0 :
V_2 = F_8 ( V_11 -> V_34 , V_35 ,
V_36 , V_16 ) ;
break;
case 1 :
V_2 = F_8 ( V_11 -> V_37 , V_38 ,
V_39 , V_16 ) ;
break;
case 2 :
V_2 = F_8 ( V_11 -> V_40 , V_41 ,
V_42 , V_16 ) ;
break;
default:
V_2 = NULL ;
}
F_13 ( & V_33 ) ;
return V_2 ;
}
void F_14 ( struct V_1 * V_2 )
{
T_1 V_13 , V_14 , V_7 ;
F_12 ( & V_33 ) ;
if ( V_2 ) {
V_13 = V_2 -> V_13 ;
V_14 = V_2 -> V_14 ;
if ( V_13 == V_36 ) {
V_7 = V_14 >> 3 ;
V_11 -> V_34 [ V_7 ] &= ~ ( 0x80 >> ( V_14 & 0x7 ) ) ;
} else if ( V_13 == V_39 ) {
V_7 = V_14 >> 3 ;
V_11 -> V_37 [ V_7 ] &= ~ ( 0x80 >> ( V_14 & 0x7 ) ) ;
} else {
V_7 = V_14 >> 3 ;
V_11 -> V_40 [ V_7 ] &= ~ ( 0x80 >> ( V_14 & 0x7 ) ) ;
}
F_10 ( V_2 ) ;
}
F_13 ( & V_33 ) ;
}
void F_15 ( struct V_1 * V_2 , T_1 * V_3 , int V_43 )
{
if ( ( V_2 != NULL ) && ( V_3 != NULL ) && ( V_43 > 0 ) )
F_1 ( V_2 , V_3 , V_43 ) ;
return;
}
static int F_16 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
return F_17 ( V_45 -> V_48 , V_45 , V_47 ) ;
}
static void F_18 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
F_19 ( V_45 -> V_48 , V_45 , V_47 ) ;
}
static int F_20 ( struct V_49 * V_50 , struct V_44 * V_45 )
{
int V_51 = V_45 -> V_52 ;
struct V_53 * V_54 ;
int V_55 = F_21 ( V_50 , V_45 ) ;
if ( V_55 == 0 ) {
V_54 = F_9 ( sizeof( struct V_53 ) , V_32 ) ;
if ( V_54 == NULL )
return - V_56 ;
if ( V_51 == V_57 )
V_54 -> V_2 = F_11 ( 0 , NULL ) ;
else
V_54 -> V_2 = F_11 ( 2 , NULL ) ;
if ( V_54 -> V_2 == NULL ) {
F_10 ( V_54 ) ;
return - V_58 ;
}
V_45 -> V_59 = V_54 ;
}
return V_55 ;
}
static void F_22 ( struct V_44 * V_45 )
{
struct V_53 * V_54 = V_45 -> V_59 ;
if ( V_54 == NULL )
return;
F_14 ( V_54 -> V_2 ) ;
F_10 ( V_54 ) ;
V_45 -> V_59 = NULL ;
}
static int F_23 ( struct V_44 * V_45 ,
const unsigned char * V_3 , int V_4 )
{
struct V_53 * V_54 = V_45 -> V_59 ;
if ( ( V_54 != NULL ) && ( V_54 -> V_2 != NULL ) ) {
F_1 ( V_54 -> V_2 , ( T_1 * ) V_3 , V_4 ) ;
return V_4 ;
}
else
return - V_60 ;
}
static int F_24 ( struct V_44 * V_45 )
{
return 2048 ;
}
static int F_25 ( struct V_61 * V_61 , struct V_46 * V_47 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( 0 , NULL ) ;
if ( V_2 == NULL )
return - V_56 ;
V_47 -> V_62 = V_2 ;
return 0 ;
}
static int F_26 ( struct V_61 * V_61 , struct V_46 * V_47 )
{
F_14 ( V_47 -> V_62 ) ;
V_47 -> V_62 = NULL ;
return 0 ;
}
static T_4 F_27 ( struct V_46 * V_47 , const char T_5 * V_63 ,
T_6 V_4 , T_7 * V_64 )
{
struct V_1 * V_2 ;
void * V_65 ;
const char T_5 * V_66 ;
T_6 V_67 = V_68 ;
T_6 V_69 = 0 ;
V_66 = V_63 ;
V_2 = V_47 -> V_62 ;
V_65 = F_9 ( V_67 , V_32 ) ;
if ( V_65 == NULL ) {
F_28 ( L_3 ,
V_70 , __LINE__ ) ;
return - V_56 ;
}
do {
if ( V_4 - V_69 > V_68 )
V_67 = V_68 ;
else
V_67 = V_4 - V_69 ;
if ( F_29 ( V_65 , V_66 , V_67 ) ) {
F_10 ( V_65 ) ;
return V_69 ? V_69 : - V_60 ;
}
F_1 ( V_2 , V_65 , V_67 ) ;
V_69 += V_67 ;
V_66 += V_67 ;
} while ( V_4 > V_69 );
F_10 ( V_65 ) ;
return V_4 ;
}
static void F_30 ( struct V_71 * V_72 , const char * V_3 , unsigned V_4 )
{
static struct V_1 V_2 = { . V_13 = V_73 ,
. V_14 = 0 } ;
V_2 . V_14 = V_74 ;
V_74 = ( V_74 + 1 ) & 0x7f ;
F_7 ( & V_2 , V_3 , V_4 ) ;
}
static struct V_49 * F_31 ( struct V_71 * V_72 , int * V_52 )
{
* V_52 = V_72 -> V_52 ;
return V_75 ;
}
static int F_32 ( struct V_71 * V_72 , char * V_76 )
{
V_74 = 0 ;
V_26 = 0 ;
return 0 ;
}
static int F_33 ( struct V_77 * V_48 , struct V_44 * V_45 )
{
if ( V_48 -> V_45 -> V_52 == V_57 )
F_34 ( & V_78 ) ;
return 0 ;
}
static void F_35 ( struct V_77 * V_48 )
{
if ( V_48 -> V_45 -> V_52 == V_57 )
F_36 ( & V_78 ) ;
}
static int F_37 ( struct V_79 * V_80 ,
const struct V_81 * V_82 )
{
unsigned int V_83 ;
int V_84 = - V_85 ;
int V_86 = 1 ;
F_38 ( & V_80 -> V_87 , L_4 , __FILE__ ,
V_70 , __LINE__ , V_80 -> V_88 , V_80 -> V_89 ) ;
V_84 = F_39 ( & V_90 ) ;
if ( V_84 ) {
F_28 ( L_5 ,
V_70 , __LINE__ ) ;
F_28 ( L_6 ,
V_70 , __LINE__ , V_84 ) ;
goto V_91;
}
V_84 = F_40 ( V_80 ) ;
if ( V_84 != 0 ) {
F_41 ( & V_80 -> V_87 ,
L_7 ,
V_70 , V_84 ) ;
goto V_92;
}
V_11 = F_42 ( sizeof( * V_11 ) , V_32 ) ;
if ( V_11 == NULL ) {
V_84 = - V_56 ;
F_41 ( & V_80 -> V_87 ,
L_8 ,
V_70 , __LINE__ ) ;
goto V_93;
}
V_11 -> V_94 = F_43 ( V_80 , V_86 ) ;
V_84 = F_44 ( V_80 , V_86 , F_45 ( & V_80 -> V_87 ) ) ;
if ( V_84 != 0 ) {
F_41 ( & V_80 -> V_87 ,
L_9 ,
V_70 , __LINE__ , V_84 ) ;
goto V_95;
}
V_11 -> V_96 = V_11 -> V_94 + V_97 ;
V_11 -> V_12 =
F_46 ( ( T_2 ) V_11 -> V_96 ,
V_98 ) ;
if ( ! V_11 -> V_12 ) {
V_84 = - V_56 ;
goto V_99;
}
F_47 ( V_80 , V_11 ) ;
for ( V_83 = 0 ; V_83 < V_100 ; V_83 ++ ) {
struct V_77 * V_48 = & V_11 -> V_48 [ V_83 ] ;
F_48 ( V_48 ) ;
V_48 -> V_101 = & V_102 ;
F_49 ( V_48 , V_75 , V_83 , & V_80 -> V_87 ) ;
}
F_50 ( & V_78 ) ;
return 0 ;
V_99:
F_51 ( V_80 , V_86 ) ;
V_95:
F_10 ( V_11 ) ;
V_93:
F_52 ( V_80 ) ;
V_92:
F_53 ( & V_90 ) ;
V_91:
return V_84 ;
}
static void F_54 ( struct V_79 * V_80 )
{
struct V_103 * V_11 = F_55 ( V_80 ) ;
unsigned int V_83 ;
F_56 ( & V_78 ) ;
for ( V_83 = 0 ; V_83 < V_100 ; V_83 ++ ) {
F_57 ( V_75 , V_83 ) ;
F_58 ( & V_11 -> V_48 [ V_83 ] ) ;
}
F_59 ( V_11 -> V_12 ) ;
F_47 ( V_80 , NULL ) ;
F_10 ( V_11 ) ;
F_51 ( V_80 , 1 ) ;
F_52 ( V_80 ) ;
F_53 ( & V_90 ) ;
}
static int T_8 F_60 ( void )
{
int V_84 = - V_85 ;
V_75 = F_61 ( V_100 ) ;
if ( V_75 == NULL ) {
F_28 ( L_10 ,
V_70 , __LINE__ ) ;
return - V_56 ;
}
V_75 -> V_104 = V_105 ;
V_75 -> V_106 = V_107 ;
V_75 -> V_108 = 0 ;
V_75 -> V_109 = V_57 ;
V_75 -> type = V_110 ;
V_75 -> V_111 = V_112 ;
V_75 -> V_113 = V_114 |
V_115 ;
V_75 -> V_116 = V_117 ;
F_62 ( V_75 , & V_118 ) ;
V_84 = F_63 ( V_75 ) ;
if ( V_84 ) {
F_28 ( L_11 ,
V_70 , __LINE__ ) ;
F_28 ( L_6 ,
V_70 , __LINE__ , V_84 ) ;
goto V_119;
}
V_84 = F_64 ( & V_120 ) ;
if ( V_84 ) {
F_28 ( L_12 ,
V_70 , __LINE__ ) ;
F_28 ( L_6 ,
V_70 , __LINE__ , V_84 ) ;
goto V_121;
}
return 0 ;
V_121:
F_65 ( V_75 ) ;
V_119:
F_66 ( V_75 ) ;
V_75 = NULL ;
return V_84 ;
}
static void T_9 F_67 ( void )
{
F_65 ( V_75 ) ;
F_68 ( & V_120 ) ;
F_66 ( V_75 ) ;
}
