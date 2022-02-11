static int F_1 ( T_1 V_1 )
{
int V_2 ;
V_1 = V_1 & V_3 ;
for ( V_2 = V_4 ; V_2 < V_5 ; V_2 <<= 1 ) {
F_2 ( V_2 ) ;
if ( ( F_3 ( V_6 ) & V_3 ) == V_1 )
return 0 ;
}
return - V_7 ;
}
static int F_4 ( T_1 V_8 )
{
int V_2 ;
for ( V_2 = V_4 ; V_2 < V_5 ; V_2 <<= 1 ) {
F_5 ( V_8 , V_6 ) ;
F_2 ( V_2 ) ;
if ( ( F_3 ( V_6 ) & V_3 ) == 0x0c )
return 0 ;
}
return - V_7 ;
}
static int F_6 ( const char * V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
F_5 ( V_9 [ V_10 ] , V_11 ) ;
if ( F_1 ( 0x04 ) )
return - V_7 ;
}
return 0 ;
}
static int F_7 ( T_1 V_8 , const char * V_9 , T_1 * V_12 , T_1 V_13 )
{
int V_10 ;
if ( F_4 ( V_8 ) || F_6 ( V_9 ) ) {
F_8 ( L_1 , V_9 ) ;
return - V_7 ;
}
F_5 ( V_13 , V_11 ) ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
if ( F_1 ( 0x05 ) ) {
F_8 ( L_2 , V_9 ) ;
return - V_7 ;
}
V_12 [ V_10 ] = F_3 ( V_11 ) ;
}
return 0 ;
}
static int F_9 ( T_1 V_8 , const char * V_9 , const T_1 * V_12 , T_1 V_13 )
{
int V_10 ;
if ( F_4 ( V_8 ) || F_6 ( V_9 ) ) {
F_8 ( L_3 , V_9 ) ;
return - V_7 ;
}
F_5 ( V_13 , V_11 ) ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
if ( F_1 ( 0x04 ) ) {
F_8 ( L_4 , V_9 ) ;
return - V_7 ;
}
F_5 ( V_12 [ V_10 ] , V_11 ) ;
}
return 0 ;
}
static int F_10 ( unsigned int * V_14 )
{
T_2 V_15 ;
int V_16 ;
V_16 = F_7 ( V_17 , V_18 , ( T_1 * ) & V_15 , 4 ) ;
if ( V_16 )
return V_16 ;
* V_14 = F_11 ( V_15 ) ;
return 0 ;
}
static int F_12 ( const struct V_19 * V_20 ,
T_1 * V_21 , T_1 V_13 )
{
int V_16 ;
if ( V_20 -> V_13 != V_13 )
return - V_22 ;
F_13 ( & V_23 . V_24 ) ;
V_16 = F_7 ( V_17 , V_20 -> V_9 , V_21 , V_13 ) ;
F_14 ( & V_23 . V_24 ) ;
return V_16 ;
}
static int F_15 ( const struct V_19 * V_20 ,
const T_1 * V_21 , T_1 V_13 )
{
int V_16 ;
if ( V_20 -> V_13 != V_13 )
return - V_22 ;
F_13 ( & V_23 . V_24 ) ;
V_16 = F_9 ( V_25 , V_20 -> V_9 , V_21 , V_13 ) ;
F_14 ( & V_23 . V_24 ) ;
return V_16 ;
}
static const struct V_19 * F_16 ( int V_26 )
{
struct V_19 * V_27 = & V_23 . V_27 [ V_26 ] ;
T_1 V_9 [ 4 ] , V_28 [ 6 ] ;
T_2 V_15 ;
int V_16 = 0 ;
if ( V_27 -> V_29 )
return V_27 ;
F_13 ( & V_23 . V_24 ) ;
if ( V_27 -> V_29 )
goto V_30;
V_15 = F_17 ( V_26 ) ;
V_16 = F_7 ( V_31 , ( T_1 * ) & V_15 , V_9 , 4 ) ;
if ( V_16 )
goto V_30;
V_16 = F_7 ( V_32 , V_9 , V_28 , 6 ) ;
if ( V_16 )
goto V_30;
memcpy ( V_27 -> V_9 , V_9 , 4 ) ;
V_27 -> V_13 = V_28 [ 0 ] ;
memcpy ( V_27 -> type , & V_28 [ 1 ] , 4 ) ;
V_27 -> V_33 = V_28 [ 5 ] ;
V_27 -> V_29 = 1 ;
V_30:
F_14 ( & V_23 . V_24 ) ;
if ( V_16 )
return F_18 ( V_16 ) ;
return V_27 ;
}
static int F_19 ( unsigned int * V_34 , const char * V_9 )
{
int V_35 = 0 , V_36 = V_23 . V_37 ;
const struct V_19 * V_20 ;
while ( V_35 != V_36 ) {
int V_38 = V_35 + ( V_36 - V_35 ) / 2 ;
V_20 = F_16 ( V_38 ) ;
if ( F_20 ( V_20 ) ) {
* V_34 = 0 ;
return F_21 ( V_20 ) ;
}
if ( strcmp ( V_20 -> V_9 , V_9 ) < 0 )
V_35 = V_38 + 1 ;
else
V_36 = V_38 ;
}
* V_34 = V_35 ;
return 0 ;
}
static int F_22 ( unsigned int * V_39 , const char * V_9 )
{
int V_35 = 0 , V_36 = V_23 . V_37 ;
const struct V_19 * V_20 ;
while ( V_35 != V_36 ) {
int V_38 = V_35 + ( V_36 - V_35 ) / 2 ;
V_20 = F_16 ( V_38 ) ;
if ( F_20 ( V_20 ) ) {
* V_39 = V_23 . V_37 ;
return F_21 ( V_20 ) ;
}
if ( strcmp ( V_9 , V_20 -> V_9 ) < 0 )
V_36 = V_38 ;
else
V_35 = V_38 + 1 ;
}
* V_39 = V_35 ;
return 0 ;
}
static const struct V_19 * F_23 ( const char * V_9 )
{
int V_35 , V_36 ;
int V_16 ;
V_16 = F_19 ( & V_35 , V_9 ) ;
if ( V_16 )
return F_18 ( V_16 ) ;
V_16 = F_22 ( & V_36 , V_9 ) ;
if ( V_16 )
return F_18 ( V_16 ) ;
if ( V_36 - V_35 != 1 )
return F_18 ( - V_22 ) ;
return F_16 ( V_35 ) ;
}
static int F_24 ( const char * V_9 , T_1 * V_12 , T_1 V_13 )
{
const struct V_19 * V_20 ;
V_20 = F_23 ( V_9 ) ;
if ( F_20 ( V_20 ) )
return F_21 ( V_20 ) ;
return F_12 ( V_20 , V_12 , V_13 ) ;
}
static int F_25 ( const char * V_9 , const T_1 * V_12 , T_1 V_13 )
{
const struct V_19 * V_20 ;
V_20 = F_23 ( V_9 ) ;
if ( F_20 ( V_20 ) )
return F_21 ( V_20 ) ;
return F_15 ( V_20 , V_12 , V_13 ) ;
}
static int F_26 ( const char * V_9 , bool * V_40 )
{
const struct V_19 * V_20 ;
V_20 = F_23 ( V_9 ) ;
if ( F_20 ( V_20 ) && F_21 ( V_20 ) != - V_22 )
return F_21 ( V_20 ) ;
* V_40 = ! F_20 ( V_20 ) ;
return 0 ;
}
static int F_27 ( int V_26 , T_3 * V_40 )
{
T_1 V_12 [ 2 ] ;
int V_16 ;
switch ( V_26 ) {
case V_41 :
V_16 = F_24 ( V_42 , V_12 , 2 ) ;
break;
case V_43 :
V_16 = F_24 ( V_44 , V_12 , 2 ) ;
break;
case V_45 :
V_16 = F_24 ( V_46 , V_12 , 2 ) ;
break;
default:
V_16 = - V_22 ;
}
* V_40 = ( ( T_3 ) V_12 [ 0 ] << 8 ) | V_12 [ 1 ] ;
return V_16 ;
}
static void F_28 ( void )
{
int V_47 ;
T_1 V_12 [ 2 ] ;
if ( ! V_23 . V_48 )
return;
for ( V_47 = V_49 ; V_47 > 0 ; V_47 -= V_50 ) {
if ( ! F_24 ( V_51 , V_12 , 2 ) &&
( V_12 [ 0 ] != 0x00 || V_12 [ 1 ] != 0x00 ) )
return;
V_12 [ 0 ] = 0xe0 ;
V_12 [ 1 ] = 0x00 ;
F_25 ( V_51 , V_12 , 2 ) ;
F_29 ( V_50 ) ;
}
F_8 ( L_5 ) ;
}
static int F_30 ( void )
{
struct V_52 * V_53 = & V_23 ;
bool V_54 , V_55 ;
T_1 V_56 [ 1 ] ;
int V_16 ;
if ( V_53 -> V_57 )
return 0 ;
V_16 = F_10 ( & V_53 -> V_37 ) ;
if ( V_16 )
return V_16 ;
if ( ! V_53 -> V_27 )
V_53 -> V_27 = F_31 ( V_53 -> V_37 , sizeof( * V_53 -> V_27 ) , V_58 ) ;
if ( ! V_53 -> V_27 )
return - V_59 ;
V_16 = F_24 ( V_60 , V_56 , 1 ) ;
if ( V_16 )
return V_16 ;
V_53 -> V_61 = V_56 [ 0 ] ;
V_16 = F_19 ( & V_53 -> V_62 , L_6 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_19 ( & V_53 -> V_63 , L_7 ) ;
if ( V_16 )
return V_16 ;
V_53 -> V_64 = V_53 -> V_63 - V_53 -> V_62 ;
V_16 = F_26 ( V_65 , & V_54 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_26 ( V_66 , & V_55 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_26 ( V_51 , & V_53 -> V_48 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_26 ( V_67 , & V_53 -> V_68 ) ;
if ( V_16 )
return V_16 ;
V_53 -> V_69 = V_54 + V_55 ;
V_53 -> V_57 = true ;
F_32 ( L_8 ,
V_53 -> V_37 , V_53 -> V_61 , V_53 -> V_64 ,
V_53 -> V_48 ,
V_53 -> V_69 ,
V_53 -> V_68 ) ;
return 0 ;
}
static int F_33 ( void )
{
int V_70 , V_16 ;
for ( V_70 = 0 ; V_70 < V_49 ; V_70 += V_50 ) {
V_16 = F_30 () ;
if ( ! V_16 ) {
if ( V_70 )
F_32 ( L_9 , V_70 ) ;
return 0 ;
}
F_29 ( V_50 ) ;
}
F_34 ( V_23 . V_27 ) ;
V_23 . V_27 = NULL ;
return V_16 ;
}
static void F_35 ( void )
{
F_34 ( V_23 . V_27 ) ;
V_23 . V_27 = NULL ;
V_23 . V_57 = false ;
}
static int F_36 ( struct V_71 * V_72 )
{
int V_16 ;
V_16 = F_33 () ;
if ( V_16 )
return V_16 ;
F_28 () ;
return 0 ;
}
static int F_37 ( struct V_73 * V_72 )
{
if ( V_23 . V_68 )
F_25 ( V_67 , V_74 , 2 ) ;
return 0 ;
}
static int F_38 ( struct V_73 * V_72 )
{
F_28 () ;
return F_37 ( V_72 ) ;
}
static void F_39 ( void )
{
F_27 ( V_41 , & V_75 ) ;
F_27 ( V_43 , & V_76 ) ;
V_75 = - V_75 ;
}
static void F_40 ( struct V_77 * V_72 )
{
struct V_78 * V_79 = V_72 -> V_80 ;
T_3 V_81 , V_82 ;
if ( F_27 ( V_41 , & V_81 ) )
return;
if ( F_27 ( V_43 , & V_82 ) )
return;
V_81 = - V_81 ;
F_41 ( V_79 , V_83 , V_81 - V_75 ) ;
F_41 ( V_79 , V_84 , V_82 - V_76 ) ;
F_42 ( V_79 ) ;
}
static T_4 F_43 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_21 )
{
return snprintf ( V_21 , V_87 , L_10 ) ;
}
static T_4 F_44 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_21 )
{
int V_16 ;
T_3 V_81 , V_82 , V_88 ;
V_16 = F_27 ( V_41 , & V_81 ) ;
if ( V_16 )
goto V_30;
V_16 = F_27 ( V_43 , & V_82 ) ;
if ( V_16 )
goto V_30;
V_16 = F_27 ( V_45 , & V_88 ) ;
if ( V_16 )
goto V_30;
V_30:
if ( V_16 )
return V_16 ;
else
return snprintf ( V_21 , V_87 , L_11 , V_81 , V_82 , V_88 ) ;
}
static T_4 F_45 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_89 )
{
const struct V_19 * V_20 ;
static int V_90 ;
int V_16 ;
T_1 V_91 = 0 , V_92 = 0 ;
T_1 V_12 [ 10 ] ;
if ( ! V_90 ) {
V_20 = F_23 ( V_65 ) ;
if ( F_20 ( V_20 ) )
return F_21 ( V_20 ) ;
if ( V_20 -> V_13 > 10 )
return - V_93 ;
V_90 = V_20 -> V_13 ;
F_32 ( L_12 , V_90 ) ;
}
V_16 = F_24 ( V_65 , V_12 , V_90 ) ;
if ( V_90 == 10 ) {
V_91 = F_46 ( * ( V_94 * ) ( V_12 + 6 ) ) >> 2 ;
goto V_30;
}
V_91 = V_12 [ 2 ] ;
if ( V_16 )
goto V_30;
V_16 = F_24 ( V_66 , V_12 , V_90 ) ;
V_92 = V_12 [ 2 ] ;
V_30:
if ( V_16 )
return V_16 ;
else
return snprintf ( V_89 , V_87 , L_13 , V_91 , V_92 ) ;
}
static T_4 F_47 ( struct V_73 * V_72 ,
struct V_85 * V_95 , char * V_89 )
{
int V_26 = V_23 . V_62 + F_48 ( V_95 ) ;
const struct V_19 * V_20 ;
V_20 = F_16 ( V_26 ) ;
if ( F_20 ( V_20 ) )
return F_21 ( V_20 ) ;
return snprintf ( V_89 , V_87 , L_14 , V_20 -> V_9 ) ;
}
static T_4 F_49 ( struct V_73 * V_72 ,
struct V_85 * V_95 , char * V_89 )
{
int V_26 = V_23 . V_62 + F_48 ( V_95 ) ;
const struct V_19 * V_20 ;
int V_16 ;
T_1 V_12 [ 2 ] ;
unsigned int V_96 ;
V_20 = F_16 ( V_26 ) ;
if ( F_20 ( V_20 ) )
return F_21 ( V_20 ) ;
if ( V_20 -> V_13 > 2 )
return - V_22 ;
V_16 = F_12 ( V_20 , V_12 , V_20 -> V_13 ) ;
if ( V_16 )
return V_16 ;
if ( V_20 -> V_13 == 2 ) {
V_96 = V_12 [ 0 ] * 1000 ;
V_96 += ( V_12 [ 1 ] >> 6 ) * 250 ;
} else {
V_96 = V_12 [ 0 ] * 4000 ;
}
return snprintf ( V_89 , V_87 , L_15 , V_96 ) ;
}
static T_4 F_50 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_89 )
{
int V_16 ;
unsigned int V_97 = 0 ;
char V_98 [ 5 ] ;
T_1 V_12 [ 2 ] ;
sprintf ( V_98 , V_99 [ F_51 ( V_86 ) ] , F_48 ( V_86 ) ) ;
V_16 = F_24 ( V_98 , V_12 , 2 ) ;
V_97 = ( ( V_12 [ 0 ] << 8 | V_12 [ 1 ] ) >> 2 ) ;
if ( V_16 )
return V_16 ;
else
return snprintf ( V_89 , V_87 , L_15 , V_97 ) ;
}
static T_4 F_52 ( struct V_73 * V_72 ,
struct V_85 * V_86 ,
const char * V_89 , T_5 V_14 )
{
int V_16 ;
unsigned long V_97 ;
char V_98 [ 5 ] ;
T_1 V_12 [ 2 ] ;
if ( F_53 ( V_89 , 10 , & V_97 ) < 0 || V_97 >= 0x4000 )
return - V_22 ;
sprintf ( V_98 , V_99 [ F_51 ( V_86 ) ] , F_48 ( V_86 ) ) ;
V_12 [ 0 ] = ( V_97 >> 6 ) & 0xff ;
V_12 [ 1 ] = ( V_97 << 2 ) & 0xff ;
V_16 = F_25 ( V_98 , V_12 , 2 ) ;
if ( V_16 )
return V_16 ;
else
return V_14 ;
}
static T_4 F_54 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_89 )
{
int V_16 ;
T_6 V_100 = 0 ;
T_1 V_12 [ 2 ] ;
V_16 = F_24 ( V_101 , V_12 , 2 ) ;
V_100 = ( ( V_12 [ 0 ] << 8 | V_12 [ 1 ] ) >> F_48 ( V_86 ) ) & 0x01 ;
if ( V_16 )
return V_16 ;
else
return snprintf ( V_89 , V_87 , L_16 , V_100 ) ;
}
static T_4 F_55 ( struct V_73 * V_72 ,
struct V_85 * V_86 ,
const char * V_89 , T_5 V_14 )
{
int V_16 ;
T_1 V_12 [ 2 ] ;
unsigned long V_80 ;
T_6 V_1 ;
if ( F_53 ( V_89 , 10 , & V_80 ) < 0 )
return - V_22 ;
V_16 = F_24 ( V_101 , V_12 , 2 ) ;
V_1 = ( V_12 [ 0 ] << 8 | V_12 [ 1 ] ) ;
if ( V_16 )
goto V_30;
if ( V_80 )
V_1 = V_1 | ( 0x01 << F_48 ( V_86 ) ) ;
else
V_1 = V_1 & ~ ( 0x01 << F_48 ( V_86 ) ) ;
V_12 [ 0 ] = ( V_1 >> 8 ) & 0xFF ;
V_12 [ 1 ] = V_1 & 0xFF ;
V_16 = F_25 ( V_101 , V_12 , 2 ) ;
V_30:
if ( V_16 )
return V_16 ;
else
return V_14 ;
}
static T_4 F_56 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_89 )
{
int V_16 ;
char V_98 [ 5 ] ;
T_1 V_12 [ 17 ] ;
sprintf ( V_98 , V_102 , F_48 ( V_86 ) ) ;
V_16 = F_24 ( V_98 , V_12 , 16 ) ;
V_12 [ 16 ] = 0 ;
if ( V_16 )
return V_16 ;
else
return snprintf ( V_89 , V_87 , L_14 , V_12 + 4 ) ;
}
static T_4 F_57 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_89 )
{
return snprintf ( V_89 , V_87 , L_13 , V_75 , V_76 ) ;
}
static T_4 F_58 ( struct V_73 * V_72 ,
struct V_85 * V_86 , const char * V_89 , T_5 V_14 )
{
F_39 () ;
return V_14 ;
}
static void F_59 ( struct V_103 * V_104 )
{
F_25 ( V_67 , V_74 , 2 ) ;
}
static void F_60 ( struct V_105 * V_106 ,
enum V_107 V_40 )
{
int V_16 ;
V_74 [ 0 ] = V_40 ;
V_16 = F_61 ( V_108 , & V_109 ) ;
if ( V_110 && ( ! V_16 ) )
F_62 ( V_111 L_17 ) ;
}
static T_4 F_63 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_89 )
{
int V_16 ;
T_1 V_12 [ 4 ] ;
T_7 V_14 ;
V_16 = F_24 ( V_18 , V_12 , 4 ) ;
V_14 = ( ( T_7 ) V_12 [ 0 ] << 24 ) + ( ( T_7 ) V_12 [ 1 ] << 16 ) +
( ( T_7 ) V_12 [ 2 ] << 8 ) + V_12 [ 3 ] ;
if ( V_16 )
return V_16 ;
else
return snprintf ( V_89 , V_87 , L_16 , V_14 ) ;
}
static T_4 F_64 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_89 )
{
const struct V_19 * V_20 ;
int V_16 ;
V_20 = F_16 ( V_112 ) ;
if ( F_20 ( V_20 ) )
return F_21 ( V_20 ) ;
V_16 = F_12 ( V_20 , V_89 , V_20 -> V_13 ) ;
if ( V_16 )
return V_16 ;
return V_20 -> V_13 ;
}
static T_4 F_65 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_89 )
{
const struct V_19 * V_20 ;
V_20 = F_16 ( V_112 ) ;
if ( F_20 ( V_20 ) )
return F_21 ( V_20 ) ;
return snprintf ( V_89 , V_87 , L_16 , V_20 -> V_13 ) ;
}
static T_4 F_66 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_89 )
{
const struct V_19 * V_20 ;
V_20 = F_16 ( V_112 ) ;
if ( F_20 ( V_20 ) )
return F_21 ( V_20 ) ;
return snprintf ( V_89 , V_87 , L_14 , V_20 -> type ) ;
}
static T_4 F_67 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_89 )
{
const struct V_19 * V_20 ;
V_20 = F_16 ( V_112 ) ;
if ( F_20 ( V_20 ) )
return F_21 ( V_20 ) ;
return snprintf ( V_89 , V_87 , L_14 , V_20 -> V_9 ) ;
}
static T_4 F_68 ( struct V_73 * V_72 ,
struct V_85 * V_86 , char * V_89 )
{
return snprintf ( V_89 , V_87 , L_16 , V_112 ) ;
}
static T_4 F_69 ( struct V_73 * V_72 ,
struct V_85 * V_86 , const char * V_89 , T_5 V_14 )
{
unsigned long V_98 ;
if ( F_53 ( V_89 , 10 , & V_98 ) < 0
|| V_98 >= V_23 . V_37 )
return - V_22 ;
V_112 = V_98 ;
return V_14 ;
}
static void F_70 ( struct V_113 * V_114 )
{
struct V_113 * V_115 ;
struct V_116 * V_117 ;
for ( V_115 = V_114 ; V_115 -> V_118 ; V_115 ++ ) {
for ( V_117 = V_115 -> V_118 ; V_117 -> V_119 . V_120 . V_86 . V_121 ; V_117 ++ )
F_71 ( & V_122 -> V_72 . V_123 ,
& V_117 -> V_119 . V_120 . V_86 ) ;
F_34 ( V_115 -> V_118 ) ;
V_115 -> V_118 = NULL ;
}
}
static int F_72 ( struct V_113 * V_114 , int V_124 )
{
struct V_113 * V_115 ;
struct V_116 * V_117 ;
struct V_125 * V_86 ;
int V_16 , V_10 ;
for ( V_115 = V_114 ; V_115 -> V_126 ; V_115 ++ ) {
V_115 -> V_118 = F_31 ( V_124 + 1 , sizeof( * V_117 ) , V_58 ) ;
if ( ! V_115 -> V_118 ) {
V_16 = - V_59 ;
goto V_30;
}
for ( V_10 = 0 ; V_10 < V_124 ; V_10 ++ ) {
V_117 = & V_115 -> V_118 [ V_10 ] ;
sprintf ( V_117 -> V_121 , V_115 -> V_126 , V_10 + 1 ) ;
V_117 -> V_119 . V_26 = ( V_115 -> V_127 << 16 ) | ( V_10 & 0xffff ) ;
V_117 -> V_119 . V_120 . V_128 = V_115 -> V_128 ;
V_117 -> V_119 . V_120 . V_129 = V_115 -> V_129 ;
V_86 = & V_117 -> V_119 . V_120 . V_86 ;
F_73 ( V_86 ) ;
V_86 -> V_121 = V_117 -> V_121 ;
V_86 -> V_130 = V_131 | ( V_115 -> V_129 ? V_132 : 0 ) ;
V_16 = F_74 ( & V_122 -> V_72 . V_123 , V_86 ) ;
if ( V_16 ) {
V_86 -> V_121 = NULL ;
goto V_30;
}
}
}
return 0 ;
V_30:
F_70 ( V_114 ) ;
return V_16 ;
}
static int F_75 ( void )
{
struct V_78 * V_79 ;
int V_16 ;
if ( ! V_23 . V_48 )
return 0 ;
V_16 = F_72 ( V_133 , 1 ) ;
if ( V_16 )
goto V_30;
V_134 = F_76 () ;
if ( ! V_134 ) {
V_16 = - V_59 ;
goto V_135;
}
V_134 -> V_136 = F_40 ;
V_134 -> V_137 = V_138 ;
F_39 () ;
V_79 = V_134 -> V_80 ;
V_79 -> V_121 = L_18 ;
V_79 -> V_139 . V_140 = V_141 ;
V_79 -> V_72 . V_142 = & V_122 -> V_72 ;
V_79 -> V_143 [ 0 ] = F_77 ( V_144 ) ;
F_78 ( V_79 , V_83 ,
- 256 , 256 , V_145 , V_146 ) ;
F_78 ( V_79 , V_84 ,
- 256 , 256 , V_145 , V_146 ) ;
V_16 = F_79 ( V_134 ) ;
if ( V_16 )
goto V_147;
return 0 ;
V_147:
F_80 ( V_134 ) ;
V_135:
F_70 ( V_133 ) ;
V_30:
F_8 ( L_19 , V_16 ) ;
return V_16 ;
}
static void F_81 ( void )
{
if ( ! V_23 . V_48 )
return;
F_82 ( V_134 ) ;
F_80 ( V_134 ) ;
F_70 ( V_133 ) ;
}
static int F_83 ( void )
{
if ( ! V_23 . V_69 )
return 0 ;
return F_72 ( V_148 , 1 ) ;
}
static void F_84 ( void )
{
if ( ! V_23 . V_69 )
return;
F_70 ( V_148 ) ;
}
static int F_85 ( void )
{
if ( ! V_23 . V_68 )
return 0 ;
V_108 = F_86 ( L_20 ) ;
if ( ! V_108 )
return - V_59 ;
return F_87 ( & V_122 -> V_72 , & V_149 ) ;
}
static void F_88 ( void )
{
if ( ! V_23 . V_68 )
return;
F_89 ( & V_149 ) ;
F_90 ( V_108 ) ;
}
static int F_91 ( const struct V_150 * V_139 )
{
return 1 ;
}
static int T_8 F_92 ( void )
{
int V_16 ;
if ( ! F_93 ( V_151 ) ) {
F_8 ( L_21 ) ;
V_16 = - V_152 ;
goto V_30;
}
if ( ! F_94 ( V_11 , V_153 ,
L_18 ) ) {
V_16 = - V_93 ;
goto V_30;
}
V_16 = F_95 ( & V_154 ) ;
if ( V_16 )
goto V_155;
V_122 = F_96 ( L_18 , V_11 ,
NULL , 0 ) ;
if ( F_20 ( V_122 ) ) {
V_16 = F_21 ( V_122 ) ;
goto V_156;
}
V_16 = F_33 () ;
if ( V_16 )
goto V_157;
V_16 = F_72 ( V_158 , 1 ) ;
if ( V_16 )
goto V_159;
V_16 = F_72 ( V_160 , V_23 . V_61 ) ;
if ( V_16 )
goto V_161;
V_16 = F_72 ( V_162 , V_23 . V_64 ) ;
if ( V_16 )
goto V_163;
V_16 = F_75 () ;
if ( V_16 )
goto V_164;
V_16 = F_83 () ;
if ( V_16 )
goto V_165;
V_16 = F_85 () ;
if ( V_16 )
goto V_166;
V_167 = F_97 ( & V_122 -> V_72 ) ;
if ( F_20 ( V_167 ) ) {
V_16 = F_21 ( V_167 ) ;
goto V_168;
}
return 0 ;
V_168:
F_88 () ;
V_166:
F_84 () ;
V_165:
F_81 () ;
V_164:
F_70 ( V_162 ) ;
V_163:
F_70 ( V_160 ) ;
V_161:
F_70 ( V_158 ) ;
V_159:
F_35 () ;
V_157:
F_98 ( V_122 ) ;
V_156:
F_99 ( & V_154 ) ;
V_155:
F_100 ( V_11 , V_153 ) ;
V_30:
F_8 ( L_19 , V_16 ) ;
return V_16 ;
}
static void T_9 F_101 ( void )
{
F_102 ( V_167 ) ;
F_88 () ;
F_84 () ;
F_81 () ;
F_70 ( V_162 ) ;
F_70 ( V_160 ) ;
F_70 ( V_158 ) ;
F_35 () ;
F_98 ( V_122 ) ;
F_99 ( & V_154 ) ;
F_100 ( V_11 , V_153 ) ;
}
