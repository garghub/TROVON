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
static void T_4 F_16 ( struct V_44 * V_45 )
{
struct V_46 * V_11 ;
V_11 = F_17 ( V_45 ) ;
if ( V_11 != NULL ) {
F_18 ( V_45 , V_11 -> V_12 ) ;
F_19 ( V_45 , NULL ) ;
F_10 ( V_11 ) ;
F_20 ( V_45 , 1 ) ;
F_21 ( V_45 ) ;
}
}
static int F_22 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
return F_23 ( & V_11 -> V_51 , V_48 , V_50 ) ;
}
static void F_24 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
F_25 ( & V_11 -> V_51 , V_48 , V_50 ) ;
}
static int F_26 ( struct V_52 * V_53 , struct V_47 * V_48 )
{
int V_54 = V_48 -> V_55 ;
struct V_56 * V_57 ;
int V_58 = F_27 ( V_53 , V_48 ) ;
if ( V_58 == 0 ) {
V_57 = F_9 ( sizeof( struct V_56 ) , V_32 ) ;
if ( V_57 == NULL )
return - V_59 ;
if ( V_54 == V_60 )
V_57 -> V_2 = F_11 ( 0 , NULL ) ;
else
V_57 -> V_2 = F_11 ( 2 , NULL ) ;
if ( V_57 -> V_2 == NULL ) {
F_10 ( V_57 ) ;
return - V_61 ;
}
V_48 -> V_62 = V_57 ;
}
return V_58 ;
}
static void F_28 ( struct V_47 * V_48 )
{
struct V_56 * V_57 = V_48 -> V_62 ;
if ( V_57 == NULL )
return;
F_14 ( V_57 -> V_2 ) ;
F_10 ( V_57 ) ;
V_48 -> V_62 = NULL ;
}
static int F_29 ( struct V_47 * V_48 ,
const unsigned char * V_3 , int V_4 )
{
struct V_56 * V_57 = V_48 -> V_62 ;
if ( ( V_57 != NULL ) && ( V_57 -> V_2 != NULL ) ) {
F_1 ( V_57 -> V_2 , ( T_1 * ) V_3 , V_4 ) ;
return V_4 ;
}
else
return - V_63 ;
}
static int F_30 ( struct V_47 * V_48 )
{
return 2048 ;
}
static int F_31 ( struct V_64 * V_64 , struct V_49 * V_50 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( 0 , NULL ) ;
if ( V_2 == NULL )
return - V_59 ;
V_50 -> V_65 = V_2 ;
return 0 ;
}
static int F_32 ( struct V_64 * V_64 , struct V_49 * V_50 )
{
F_14 ( V_50 -> V_65 ) ;
V_50 -> V_65 = NULL ;
return 0 ;
}
static T_5 F_33 ( struct V_49 * V_50 , const char T_6 * V_66 ,
T_7 V_4 , T_8 * V_67 )
{
struct V_1 * V_2 ;
void * V_68 ;
const char T_6 * V_69 ;
T_7 V_70 = V_71 ;
T_7 V_72 = 0 ;
V_69 = V_66 ;
V_2 = V_50 -> V_65 ;
V_68 = F_9 ( V_70 , V_32 ) ;
if ( V_68 == NULL ) {
F_34 ( L_3 ,
V_73 , __LINE__ ) ;
return - V_59 ;
}
do {
if ( V_4 - V_72 > V_71 )
V_70 = V_71 ;
else
V_70 = V_4 - V_72 ;
if ( F_35 ( V_68 , V_69 , V_70 ) ) {
F_10 ( V_68 ) ;
return V_72 ? V_72 : - V_63 ;
}
F_1 ( V_2 , V_68 , V_70 ) ;
V_72 += V_70 ;
V_69 += V_70 ;
} while ( V_4 > V_72 );
F_10 ( V_68 ) ;
return V_4 ;
}
static void F_36 ( struct V_74 * V_75 , const char * V_3 , unsigned V_4 )
{
static struct V_1 V_2 = { . V_13 = V_76 ,
. V_14 = 0 } ;
V_2 . V_14 = V_77 ;
V_77 = ( V_77 + 1 ) & 0x7f ;
F_7 ( & V_2 , V_3 , V_4 ) ;
}
static struct V_52 * F_37 ( struct V_74 * V_75 , int * V_55 )
{
* V_55 = V_75 -> V_55 ;
return V_78 ;
}
static int F_38 ( struct V_74 * V_75 , char * V_79 )
{
V_77 = 0 ;
V_26 = 0 ;
return 0 ;
}
static int F_39 ( struct V_80 * V_51 , struct V_47 * V_48 )
{
if ( V_51 -> V_48 -> V_55 == V_60 )
F_40 ( & V_81 ) ;
return 0 ;
}
static void F_41 ( struct V_80 * V_51 )
{
if ( V_51 -> V_48 -> V_55 == V_60 )
F_42 ( & V_81 ) ;
}
static int T_9 F_43 ( struct V_44 * V_45 ,
const struct V_82 * V_83 )
{
int V_84 = - V_85 ;
int V_86 = 1 ;
F_44 ( & V_45 -> V_87 , L_4 , __FILE__ ,
V_73 , __LINE__ , V_45 -> V_88 , V_45 -> V_89 ) ;
V_84 = F_45 ( & V_90 ) ;
if ( V_84 ) {
F_34 ( L_5 ,
V_73 , __LINE__ ) ;
F_34 ( L_6 ,
V_73 , __LINE__ , V_84 ) ;
return V_84 ;
}
V_84 = F_46 ( V_45 ) ;
if ( V_84 != 0 ) {
F_47 ( & V_45 -> V_87 ,
L_7 ,
V_73 , V_84 ) ;
return V_84 ;
}
V_11 = F_48 ( sizeof( * V_11 ) , V_32 ) ;
if ( V_11 == NULL ) {
V_84 = - V_59 ;
F_47 ( & V_45 -> V_87 ,
L_8 ,
V_73 , __LINE__ ) ;
return V_84 ;
}
V_11 -> V_91 = F_49 ( V_45 , V_86 ) ;
V_84 = F_50 ( V_45 , V_86 , F_51 ( & V_45 -> V_87 ) ) ;
if ( V_84 != 0 ) {
F_47 ( & V_45 -> V_87 ,
L_9 ,
V_73 , __LINE__ , V_84 ) ;
F_10 ( V_11 ) ;
return V_84 ;
}
V_11 -> V_92 = V_11 -> V_91 + V_93 ;
V_11 -> V_12 =
F_52 ( ( T_2 ) V_11 -> V_92 ,
V_94 ) ;
if ( ! V_11 -> V_12 ) {
F_20 ( V_45 , V_86 ) ;
V_84 = - V_59 ;
F_10 ( V_11 ) ;
return V_84 ;
}
F_19 ( V_45 , V_11 ) ;
F_53 ( & V_11 -> V_51 ) ;
V_11 -> V_51 . V_95 = & V_96 ;
F_54 ( V_78 , 0 , & V_45 -> V_87 ) ;
F_54 ( V_78 , 1 , & V_45 -> V_87 ) ;
F_55 ( & V_81 ) ;
return V_84 ;
}
static int T_10 F_56 ( void )
{
int V_84 = - V_85 ;
V_78 = F_57 ( V_97 ) ;
if ( V_78 == NULL ) {
F_34 ( L_10 ,
V_73 , __LINE__ ) ;
return - V_59 ;
}
V_78 -> V_98 = V_99 ;
V_78 -> V_100 = V_101 ;
V_78 -> V_102 = 0 ;
V_78 -> V_103 = V_60 ;
V_78 -> type = V_104 ;
V_78 -> V_105 = V_106 ;
V_78 -> V_107 = V_108 |
V_109 ;
V_78 -> V_110 = V_111 ;
F_58 ( V_78 , & V_112 ) ;
V_84 = F_59 ( V_78 ) ;
if ( V_84 ) {
F_34 ( L_11 ,
V_73 , __LINE__ ) ;
F_34 ( L_6 ,
V_73 , __LINE__ , V_84 ) ;
V_78 = NULL ;
return V_84 ;
}
V_84 = F_60 ( & V_113 ) ;
if ( V_84 ) {
F_34 ( L_12 ,
V_73 , __LINE__ ) ;
F_34 ( L_6 ,
V_73 , __LINE__ , V_84 ) ;
F_61 ( V_78 ) ;
F_34 ( L_13 ,
V_73 , __LINE__ ) ;
V_78 = NULL ;
return V_84 ;
}
return V_84 ;
}
static void T_11 F_62 ( void )
{
int V_84 ;
F_63 ( V_78 , 0 ) ;
F_63 ( V_78 , 1 ) ;
V_84 = F_61 ( V_78 ) ;
if ( V_84 ) {
F_34 ( L_14 ,
V_73 , __LINE__ ) ;
F_34 ( L_6 ,
V_73 , __LINE__ , V_84 ) ;
}
F_64 ( & V_113 ) ;
V_84 = F_65 ( & V_90 ) ;
if ( V_84 ) {
F_34 ( L_15 ,
V_73 , __LINE__ ) ;
F_34 ( L_6 ,
V_73 , __LINE__ , V_84 ) ;
}
F_66 ( & V_81 ) ;
return;
}
