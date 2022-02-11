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
static void F_4 ( struct V_1 * V_2 )
{
struct V_1 V_16 = { . V_13 = V_17 ,
. V_14 = 0 } ;
const char * V_18 = L_1 ;
T_1 V_19 [ V_20 ] ;
char V_21 [ V_22 ] ;
if ( ! F_5 () )
F_6 ( V_21 , V_23 ) ;
else
strncpy ( V_21 , L_2 , V_22 ) ;
V_21 [ V_22 - 1 ] = 0 ;
V_16 . V_14 = V_24 ;
V_24 = ( V_24 + 1 ) & 0x7f ;
snprintf ( V_19 , V_20 , V_18 , V_2 -> V_13 ,
V_2 -> V_14 , V_21 ) ;
F_1 ( & V_16 , V_19 , strlen ( V_19 ) ) ;
}
static void F_7 ( struct V_1 * V_2 ,
const unsigned char * V_3 ,
int V_4 )
{
F_4 ( V_2 ) ;
F_1 ( V_2 , ( T_1 * ) V_3 , V_4 ) ;
}
static struct V_1 * F_8 ( T_1 * V_25 , int V_26 , int V_27 )
{
struct V_1 * V_2 ;
int V_7 , V_28 , V_29 ;
V_2 = F_9 ( sizeof( struct V_1 ) , V_30 ) ;
if ( V_2 == NULL )
return NULL ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ )
if ( V_25 [ V_7 ] != 0xff )
break;
if ( V_7 == V_26 ) {
F_10 ( V_2 ) ;
return NULL ;
}
V_29 = 0x80 ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
if ( ( V_25 [ V_7 ] & V_29 ) == 0 )
break;
V_29 >>= 1 ;
}
V_25 [ V_7 ] |= V_29 ;
V_2 -> V_13 = V_27 ;
V_2 -> V_14 = ( ( V_7 & 0xf ) << 3 ) + V_28 ;
F_4 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_11 ( T_1 type )
{
struct V_1 * V_2 ;
F_12 ( & V_31 ) ;
switch ( type ) {
case 0 :
V_2 = F_8 ( V_11 -> V_32 , V_33 , V_34 ) ;
break;
case 1 :
V_2 = F_8 ( V_11 -> V_35 , V_36 , V_37 ) ;
break;
case 2 :
V_2 = F_8 ( V_11 -> V_38 , V_39 , V_40 ) ;
break;
default:
V_2 = NULL ;
}
F_13 ( & V_31 ) ;
return V_2 ;
}
void F_14 ( struct V_1 * V_2 )
{
T_1 V_13 , V_14 , V_7 ;
F_12 ( & V_31 ) ;
if ( V_2 ) {
V_13 = V_2 -> V_13 ;
V_14 = V_2 -> V_14 ;
if ( V_13 == V_34 ) {
V_7 = V_14 >> 3 ;
V_11 -> V_32 [ V_7 ] &= ~ ( 0x80 >> ( V_14 & 0x7 ) ) ;
} else if ( V_13 == V_37 ) {
V_7 = V_14 >> 3 ;
V_11 -> V_35 [ V_7 ] &= ~ ( 0x80 >> ( V_14 & 0x7 ) ) ;
} else {
V_7 = V_14 >> 3 ;
V_11 -> V_38 [ V_7 ] &= ~ ( 0x80 >> ( V_14 & 0x7 ) ) ;
}
F_10 ( V_2 ) ;
}
F_13 ( & V_31 ) ;
}
void F_15 ( struct V_1 * V_2 , T_1 * V_3 , int V_41 )
{
if ( ( V_2 != NULL ) && ( V_3 != NULL ) && ( V_41 > 0 ) )
F_1 ( V_2 , V_3 , V_41 ) ;
return;
}
static void T_4 F_16 ( struct V_42 * V_43 )
{
struct V_44 * V_11 ;
V_11 = F_17 ( V_43 ) ;
if ( V_11 != NULL ) {
F_18 ( V_43 , V_11 -> V_12 ) ;
F_19 ( V_43 , NULL ) ;
F_10 ( V_11 ) ;
F_20 ( V_43 , 1 ) ;
F_21 ( V_43 ) ;
}
}
static int F_22 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
return F_23 ( & V_11 -> V_49 , V_46 , V_48 ) ;
}
static void F_24 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
F_25 ( & V_11 -> V_49 , V_46 , V_48 ) ;
}
static int F_26 ( struct V_50 * V_51 , struct V_45 * V_46 )
{
int V_52 = V_46 -> V_53 ;
struct V_54 * V_55 ;
int V_56 = F_27 ( V_46 ) ;
if ( V_56 == 0 ) {
F_28 ( V_51 ) ;
V_46 -> V_41 ++ ;
V_51 -> V_57 [ V_52 ] = V_46 ;
V_55 = F_9 ( sizeof( struct V_54 ) , V_30 ) ;
if ( V_55 == NULL )
return - V_58 ;
if ( V_52 == V_59 )
V_55 -> V_2 = F_11 ( 0 ) ;
else
V_55 -> V_2 = F_11 ( 2 ) ;
if ( V_55 -> V_2 == NULL ) {
F_10 ( V_55 ) ;
return - V_60 ;
}
V_46 -> V_61 = V_55 ;
}
return V_56 ;
}
static void F_29 ( struct V_45 * V_46 )
{
struct V_54 * V_55 = V_46 -> V_61 ;
if ( V_55 == NULL )
return;
F_14 ( V_55 -> V_2 ) ;
F_10 ( V_55 ) ;
V_46 -> V_61 = NULL ;
}
static int F_30 ( struct V_45 * V_46 ,
const unsigned char * V_3 , int V_4 )
{
struct V_54 * V_55 = V_46 -> V_61 ;
if ( ( V_55 != NULL ) && ( V_55 -> V_2 != NULL ) ) {
F_1 ( V_55 -> V_2 , ( T_1 * ) V_3 , V_4 ) ;
return V_4 ;
}
else
return - V_62 ;
}
static int F_31 ( struct V_45 * V_46 )
{
return 2048 ;
}
static int F_32 ( struct V_63 * V_63 , struct V_47 * V_48 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( 0 ) ;
if ( V_2 == NULL )
return - V_58 ;
V_48 -> V_64 = V_2 ;
return 0 ;
}
static int F_33 ( struct V_63 * V_63 , struct V_47 * V_48 )
{
F_14 ( V_48 -> V_64 ) ;
V_48 -> V_64 = NULL ;
return 0 ;
}
static T_5 F_34 ( struct V_47 * V_48 , const char T_6 * V_65 ,
T_7 V_4 , T_8 * V_66 )
{
struct V_1 * V_2 ;
void * V_67 ;
const char T_6 * V_68 ;
T_7 V_69 = V_70 ;
T_7 V_71 = 0 ;
V_68 = V_65 ;
V_2 = V_48 -> V_64 ;
V_67 = F_9 ( V_69 , V_30 ) ;
if ( V_67 == NULL ) {
F_35 ( L_3 ,
V_72 , __LINE__ ) ;
return - V_58 ;
}
do {
if ( V_4 - V_71 > V_70 )
V_69 = V_70 ;
else
V_69 = V_4 - V_71 ;
if ( F_36 ( V_67 , V_68 , V_69 ) ) {
F_10 ( V_67 ) ;
return V_71 ? V_71 : - V_62 ;
}
F_1 ( V_2 , V_67 , V_69 ) ;
V_71 += V_69 ;
V_68 += V_69 ;
} while ( V_4 > V_71 );
F_10 ( V_67 ) ;
return V_4 ;
}
static void F_37 ( struct V_73 * V_74 , const char * V_3 , unsigned V_4 )
{
static struct V_1 V_2 = { . V_13 = V_75 ,
. V_14 = 0 } ;
V_2 . V_14 = V_76 ;
V_76 = ( V_76 + 1 ) & 0x7f ;
F_7 ( & V_2 , V_3 , V_4 ) ;
}
static struct V_50 * F_38 ( struct V_73 * V_74 , int * V_53 )
{
* V_53 = V_74 -> V_53 ;
return V_77 ;
}
static int F_39 ( struct V_73 * V_74 , char * V_78 )
{
V_76 = 0 ;
V_24 = 0 ;
return 0 ;
}
static int F_40 ( struct V_79 * V_49 , struct V_45 * V_46 )
{
if ( V_49 -> V_46 -> V_53 == V_59 )
F_41 ( & V_80 ) ;
return 0 ;
}
static void F_42 ( struct V_79 * V_49 )
{
if ( V_49 -> V_46 -> V_53 == V_59 )
F_43 ( & V_80 ) ;
}
static int T_9 F_44 ( struct V_42 * V_43 ,
const struct V_81 * V_82 )
{
int V_83 = - V_84 ;
int V_85 = 1 ;
F_45 ( & V_43 -> V_86 , L_4 , __FILE__ ,
V_72 , __LINE__ , V_43 -> V_87 , V_43 -> V_88 ) ;
V_83 = F_46 ( & V_89 ) ;
if ( V_83 ) {
F_35 ( L_5 ,
V_72 , __LINE__ ) ;
F_35 ( L_6 ,
V_72 , __LINE__ , V_83 ) ;
return V_83 ;
}
V_83 = F_47 ( V_43 ) ;
if ( V_83 != 0 ) {
F_48 ( & V_43 -> V_86 ,
L_7 ,
V_72 , V_83 ) ;
return V_83 ;
}
V_11 = F_49 ( sizeof( * V_11 ) , V_30 ) ;
if ( V_11 == NULL ) {
V_83 = - V_58 ;
F_48 ( & V_43 -> V_86 ,
L_8 ,
V_72 , __LINE__ ) ;
return V_83 ;
}
V_11 -> V_90 = F_50 ( V_43 , V_85 ) ;
V_83 = F_51 ( V_43 , V_85 , F_52 ( & V_43 -> V_86 ) ) ;
if ( V_83 != 0 ) {
F_48 ( & V_43 -> V_86 ,
L_9 ,
V_72 , __LINE__ , V_83 ) ;
F_10 ( V_11 ) ;
return V_83 ;
}
V_11 -> V_91 = V_11 -> V_90 + V_92 ;
V_11 -> V_12 =
F_53 ( ( T_2 ) V_11 -> V_91 ,
V_93 ) ;
if ( ! V_11 -> V_12 ) {
F_20 ( V_43 , V_85 ) ;
V_83 = - V_58 ;
F_10 ( V_11 ) ;
return V_83 ;
}
F_19 ( V_43 , V_11 ) ;
F_54 ( & V_11 -> V_49 ) ;
V_11 -> V_49 . V_94 = & V_95 ;
F_55 ( V_77 , 0 , & V_43 -> V_86 ) ;
F_55 ( V_77 , 1 , & V_43 -> V_86 ) ;
F_56 ( & V_80 ) ;
return V_83 ;
}
static int T_10 F_57 ( void )
{
int V_83 = - V_84 ;
V_77 = F_58 ( 1 ) ;
if ( V_77 == NULL ) {
F_35 ( L_10 ,
V_72 , __LINE__ ) ;
return - V_58 ;
}
V_77 -> V_96 = V_97 ;
V_77 -> V_98 = V_99 ;
V_77 -> V_100 = V_101 ;
V_77 -> V_102 = V_103 ;
V_77 -> V_104 = 0 ;
V_77 -> V_105 = V_59 ;
V_77 -> V_106 = V_107 ;
V_77 -> V_108 = V_107 ;
V_77 -> type = V_109 ;
V_77 -> V_110 = V_111 ;
V_77 -> V_112 = V_113 |
V_114 ;
V_77 -> V_115 = V_116 ;
F_59 ( V_77 , & V_117 ) ;
V_83 = F_60 ( V_77 ) ;
if ( V_83 ) {
F_35 ( L_11 ,
V_72 , __LINE__ ) ;
F_35 ( L_6 ,
V_72 , __LINE__ , V_83 ) ;
V_77 = NULL ;
return V_83 ;
}
V_83 = F_61 ( & V_118 ) ;
if ( V_83 ) {
F_35 ( L_12 ,
V_72 , __LINE__ ) ;
F_35 ( L_6 ,
V_72 , __LINE__ , V_83 ) ;
F_62 ( V_77 ) ;
F_35 ( L_13 ,
V_72 , __LINE__ ) ;
V_77 = NULL ;
return V_83 ;
}
return V_83 ;
}
static void T_11 F_63 ( void )
{
int V_83 ;
F_64 ( V_77 , 0 ) ;
F_64 ( V_77 , 1 ) ;
V_83 = F_62 ( V_77 ) ;
if ( V_83 ) {
F_35 ( L_14 ,
V_72 , __LINE__ ) ;
F_35 ( L_6 ,
V_72 , __LINE__ , V_83 ) ;
}
F_65 ( & V_118 ) ;
V_83 = F_66 ( & V_89 ) ;
if ( V_83 ) {
F_35 ( L_15 ,
V_72 , __LINE__ ) ;
F_35 ( L_6 ,
V_72 , __LINE__ , V_83 ) ;
}
F_67 ( & V_80 ) ;
return;
}
