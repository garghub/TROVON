static int F_1 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
T_2 V_5 , V_6 ;
if ( F_2 ( V_5 , & V_4 -> V_5 ) )
return - V_7 ;
V_6 = F_3 ( V_2 , V_5 >> 24 , 0 ,
( V_5 >> 8 ) & 0xffff , V_5 & 0xff ) ;
if ( F_4 ( V_6 , & V_4 -> V_6 ) )
return - V_7 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
T_2 V_5 , V_6 ;
if ( F_2 ( V_5 , & V_4 -> V_5 ) )
return - V_7 ;
V_6 = F_6 ( V_2 , V_5 >> 24 ) ;
if ( F_4 ( V_6 , & V_4 -> V_6 ) )
return - V_7 ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 , struct V_10 * V_10 ,
unsigned int V_11 , unsigned long V_4 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
void T_1 * V_13 = ( void T_1 * ) V_4 ;
switch ( V_11 ) {
case V_14 :
return F_4 ( V_15 , ( int T_1 * ) V_13 ) ;
case V_16 :
return F_1 ( V_2 , V_13 ) ;
case V_17 :
return F_5 ( V_2 , V_13 ) ;
}
return - V_18 ;
}
static int F_8 ( struct V_8 * V_9 , struct V_10 * V_10 ,
unsigned int V_11 , unsigned long V_4 )
{
return F_7 ( V_9 , V_10 , V_11 , ( unsigned long ) F_9 ( V_4 ) ) ;
}
static int F_10 ( struct V_8 * V_9 , struct V_10 * V_10 )
{
#ifndef F_11
if ( ! F_12 ( V_19 ) )
return - V_20 ;
#endif
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
int V_21 ;
F_14 ( & V_2 -> V_22 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_23 . V_24 ; V_21 ++ ) {
struct V_25 * V_26 = F_15 ( & V_2 -> V_23 , V_21 ) ;
F_16 ( V_26 -> V_27 ) ;
}
F_14 ( & V_2 -> V_23 ) ;
F_14 ( & V_2 -> V_28 ) ;
}
static void F_17 ( struct V_8 * V_29 )
{
F_13 ( V_29 -> V_12 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
char V_30 [ 16 ] ;
struct V_8 * V_29 ;
int V_31 ;
sprintf ( V_30 , L_1 , V_2 -> V_32 ) ;
V_31 = F_19 ( V_2 -> V_33 -> V_34 , V_30 , V_2 -> V_32 , & V_29 ) ;
if ( V_31 < 0 )
return V_31 ;
V_2 -> V_29 = V_29 ;
sprintf ( V_29 -> V_35 , L_1 , V_2 -> V_32 ) ;
V_29 -> V_36 = V_37 ;
V_29 -> V_12 = V_2 ;
V_29 -> V_38 = F_17 ;
V_29 -> V_39 = 1 ;
V_29 -> V_40 . V_41 = F_10 ;
V_29 -> V_40 . V_42 = F_7 ;
#ifdef F_20
V_29 -> V_40 . V_43 = F_8 ;
#endif
F_21 ( & V_2 -> V_44 ) ;
F_22 ( & V_2 -> V_22 , sizeof( struct V_45 ) , 32 ) ;
F_22 ( & V_2 -> V_23 , sizeof( struct V_25 ) , 32 ) ;
F_22 ( & V_2 -> V_28 , sizeof( struct V_46 ) , 16 ) ;
return 0 ;
}
static T_3 F_23 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
char * V_51 )
{
struct V_8 * V_29 = F_24 ( V_48 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
F_25 ( V_2 ) ;
return sprintf ( V_51 , L_2 , F_26 ( V_2 -> V_52 ) ) ;
}
static T_3 F_27 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
char * V_51 )
{
struct V_8 * V_29 = F_24 ( V_48 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
F_25 ( V_2 ) ;
return sprintf ( V_51 , L_2 , F_26 ( V_2 -> V_53 ) ) ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_8 * V_29 = V_2 -> V_29 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_29 ( V_54 ) ; V_21 ++ )
F_30 ( V_55 , V_29 -> V_34 ,
V_29 -> V_47 , & V_54 [ V_21 ] ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = F_32 ( V_2 ) ;
if ( V_31 < 0 ) {
F_33 ( V_56 L_3 ) ;
return V_31 ;
}
F_13 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_31 ;
F_35 ( V_2 ) ;
F_33 ( V_57 L_4 ) ;
V_31 = F_32 ( V_2 ) ;
if ( V_31 < 0 ) {
F_33 ( V_56
L_5 ) ;
goto error;
}
V_31 = F_36 ( V_2 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_37 ( V_2 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_38 ( V_2 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_39 ( V_2 -> V_33 -> V_34 ) ;
error:
F_40 ( V_2 ) ;
return V_31 ;
}
static char * F_41 ( const char * V_58 , T_4 V_59 )
{
char * V_60 = F_42 ( V_58 , V_59 , V_61 ) ;
char * V_62 ;
if ( ! V_60 )
return NULL ;
V_62 = strchr ( V_60 , '\n' ) ;
if ( V_62 )
* V_62 = 0 ;
return V_60 ;
}
static T_3 F_43 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
char * V_51 )
{
struct V_8 * V_29 = F_24 ( V_48 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
int V_21 , V_59 = 0 ;
F_44 ( & V_2 -> V_44 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_24 ; V_21 ++ ) {
struct V_45 * V_63 = F_15 ( & V_2 -> V_22 , V_21 ) ;
V_59 += snprintf ( V_51 + V_59 , V_64 - V_59 ,
L_6 ,
V_63 -> V_65 , V_63 -> V_5 , V_63 -> V_66 ) ;
}
F_45 ( & V_2 -> V_44 ) ;
return V_59 ;
}
static int F_46 ( struct V_1 * V_2 , const char * V_51 )
{
struct V_45 * V_63 ;
int V_65 , V_5 , V_66 ;
if ( sscanf ( V_51 , L_7 , & V_65 , & V_5 , & V_66 ) != 3 )
return - V_67 ;
if ( ! V_65 || ! V_5 )
return - V_67 ;
F_44 ( & V_2 -> V_44 ) ;
V_63 = F_47 ( & V_2 -> V_22 ) ;
if ( ! V_63 ) {
F_45 ( & V_2 -> V_44 ) ;
return - V_68 ;
}
V_63 -> V_65 = V_65 ;
V_63 -> V_5 = V_5 ;
V_63 -> V_66 = V_66 ;
F_45 ( & V_2 -> V_44 ) ;
return 0 ;
}
static T_3 F_48 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char * V_51 , T_4 V_69 )
{
struct V_8 * V_29 = F_24 ( V_48 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
int V_31 = F_46 ( V_2 , V_51 ) ;
if ( V_31 < 0 )
return V_31 ;
return V_69 ;
}
static T_3 F_49 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
char * V_51 )
{
struct V_8 * V_29 = F_24 ( V_48 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
int V_21 , V_59 = 0 ;
F_44 ( & V_2 -> V_44 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_23 . V_24 ; V_21 ++ ) {
struct V_25 * V_26 = F_15 ( & V_2 -> V_23 , V_21 ) ;
V_59 += snprintf ( V_51 + V_59 , V_64 - V_59 ,
L_8 , V_26 -> V_27 , V_26 -> V_70 ) ;
}
F_45 ( & V_2 -> V_44 ) ;
return V_59 ;
}
static struct V_25 * F_50 ( struct V_1 * V_2 , const char * V_27 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_23 . V_24 ; V_21 ++ ) {
struct V_25 * V_26 = F_15 ( & V_2 -> V_23 , V_21 ) ;
if ( ! strcmp ( V_26 -> V_27 , V_27 ) )
return V_26 ;
}
return NULL ;
}
static void F_51 ( char * V_71 )
{
char * V_62 ;
if ( ! * V_71 )
return;
V_62 = V_71 + strlen ( V_71 ) - 1 ;
for (; isspace ( * V_62 ) ; V_62 -- ) {
* V_62 = 0 ;
if ( V_62 == V_71 )
return;
}
}
static int F_52 ( struct V_1 * V_2 , const char * V_51 )
{
char * V_27 , * V_70 ;
struct V_25 * V_26 ;
int V_31 = 0 ;
V_51 = F_53 ( V_51 ) ;
if ( ! * V_51 || * V_51 == '#' || * V_51 == '\n' )
return 0 ;
if ( * V_51 == '=' )
return - V_67 ;
V_27 = F_41 ( V_51 , 1024 ) ;
if ( ! V_27 )
return - V_68 ;
V_70 = strchr ( V_27 , '=' ) ;
if ( ! V_70 ) {
F_16 ( V_27 ) ;
return - V_67 ;
}
* V_70 ++ = 0 ;
V_70 = F_53 ( V_70 ) ;
F_51 ( V_27 ) ;
F_51 ( V_70 ) ;
F_44 ( & V_2 -> V_44 ) ;
V_26 = F_50 ( V_2 , V_27 ) ;
if ( V_26 ) {
F_16 ( V_26 -> V_27 ) ;
V_26 -> V_27 = V_27 ;
V_26 -> V_70 = V_70 ;
goto V_72;
}
if ( V_2 -> V_23 . V_24 >= V_73 )
V_26 = NULL ;
else
V_26 = F_47 ( & V_2 -> V_23 ) ;
if ( V_26 ) {
V_26 -> V_27 = V_27 ;
V_26 -> V_70 = V_70 ;
} else {
V_31 = - V_68 ;
}
V_72:
F_45 ( & V_2 -> V_44 ) ;
if ( V_31 )
F_16 ( V_27 ) ;
return V_31 ;
}
static T_3 F_54 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char * V_51 , T_4 V_69 )
{
struct V_8 * V_29 = F_24 ( V_48 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
int V_31 = F_52 ( V_2 , V_51 ) ;
if ( V_31 < 0 )
return V_31 ;
return V_69 ;
}
static T_3 F_55 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
char * V_51 )
{
int V_21 , V_59 = 0 ;
F_44 ( & V_2 -> V_44 ) ;
for ( V_21 = 0 ; V_21 < V_75 -> V_24 ; V_21 ++ ) {
struct V_46 * V_76 = F_15 ( V_75 , V_21 ) ;
V_59 += sprintf ( V_51 + V_59 , L_9 ,
V_76 -> V_65 , V_76 -> V_77 ) ;
}
F_45 ( & V_2 -> V_44 ) ;
return V_59 ;
}
static T_3 F_56 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
char * V_51 )
{
struct V_8 * V_29 = F_24 ( V_48 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
return F_55 ( V_2 , & V_2 -> V_78 , V_51 ) ;
}
static T_3 F_57 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
char * V_51 )
{
struct V_8 * V_29 = F_24 ( V_48 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
return F_55 ( V_2 , & V_2 -> V_28 , V_51 ) ;
}
static T_3 F_58 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
char * V_51 )
{
struct V_8 * V_29 = F_24 ( V_48 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
return F_55 ( V_2 , & V_2 -> V_79 , V_51 ) ;
}
static int F_59 ( struct V_1 * V_2 , const char * V_51 )
{
int V_65 , V_77 , V_31 ;
if ( sscanf ( V_51 , L_10 , & V_65 , & V_77 ) != 2 )
return - V_67 ;
if ( ! V_65 )
return - V_67 ;
F_44 ( & V_2 -> V_44 ) ;
V_31 = F_60 ( V_2 , & V_2 -> V_28 , V_65 , V_77 ) ;
F_45 ( & V_2 -> V_44 ) ;
return V_31 ;
}
static T_3 F_61 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char * V_51 , T_4 V_69 )
{
struct V_8 * V_29 = F_24 ( V_48 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
int V_31 = F_59 ( V_2 , V_51 ) ;
if ( V_31 < 0 )
return V_31 ;
return V_69 ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_8 * V_29 = V_2 -> V_29 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_29 ( V_80 ) ; V_21 ++ )
F_30 ( V_55 , V_29 -> V_34 ,
V_29 -> V_47 , & V_80 [ V_21 ] ) ;
return 0 ;
}
const char * F_63 ( struct V_1 * V_2 , const char * V_27 )
{
struct V_25 * V_26 = F_50 ( V_2 , V_27 ) ;
return V_26 ? V_26 -> V_70 : NULL ;
}
int F_64 ( struct V_1 * V_2 , const char * V_27 )
{
const char * V_62 ;
int V_81 ;
F_44 ( & V_2 -> V_44 ) ;
V_62 = F_63 ( V_2 , V_27 ) ;
if ( ! V_62 || ! * V_62 )
V_81 = - V_82 ;
else {
switch ( toupper ( * V_62 ) ) {
case 'T' :
case 'Y' :
case '1' :
V_81 = 1 ;
break;
default:
V_81 = 0 ;
break;
}
}
F_45 ( & V_2 -> V_44 ) ;
return V_81 ;
}
int F_65 ( struct V_1 * V_2 , const char * V_27 , int * V_83 )
{
const char * V_62 ;
unsigned long V_70 ;
int V_81 ;
F_44 ( & V_2 -> V_44 ) ;
V_62 = F_63 ( V_2 , V_27 ) ;
if ( ! V_62 )
V_81 = - V_82 ;
else if ( F_66 ( V_62 , 0 , & V_70 ) )
V_81 = - V_67 ;
else {
* V_83 = V_70 ;
V_81 = 0 ;
}
F_45 ( & V_2 -> V_44 ) ;
return V_81 ;
}
static inline int F_67 ( const char * V_84 , const char * V_85 )
{
return F_68 ( V_84 , V_85 , strlen ( V_85 ) ) == 0 ;
}
static void F_69 ( char * V_51 , struct V_86 * V_33 ,
struct V_1 * * V_87 )
{
int V_88 , V_89 , V_90 ;
struct V_1 * V_2 ;
* V_87 = NULL ;
if ( sscanf ( V_51 , L_7 , & V_88 , & V_89 , & V_90 ) == 3 ) {
F_70 (codec, &bus->codec_list, list) {
if ( ( V_88 <= 0 || V_2 -> V_91 == V_88 ) &&
( V_89 <= 0 || V_2 -> V_92 == V_89 ) &&
V_2 -> V_32 == V_90 ) {
* V_87 = V_2 ;
break;
}
}
}
}
static void F_71 ( char * V_51 , struct V_86 * V_33 ,
struct V_1 * * V_87 )
{
F_59 ( * V_87 , V_51 ) ;
}
static void F_72 ( char * V_51 , struct V_86 * V_33 ,
struct V_1 * * V_87 )
{
F_46 ( * V_87 , V_51 ) ;
}
static void F_73 ( char * V_51 , struct V_86 * V_33 ,
struct V_1 * * V_87 )
{
F_52 ( * V_87 , V_51 ) ;
}
static void F_74 ( char * V_51 , struct V_86 * V_33 ,
struct V_1 * * V_87 )
{
F_16 ( ( * V_87 ) -> V_93 ) ;
( * V_87 ) -> V_93 = F_75 ( V_51 , V_61 ) ;
}
static void F_76 ( char * V_51 , struct V_86 * V_33 ,
struct V_1 * * V_87 )
{
F_16 ( ( * V_87 ) -> V_94 ) ;
( * V_87 ) -> V_94 = F_75 ( V_51 , V_61 ) ;
}
static int F_77 ( char * V_51 , struct V_86 * V_33 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_29 ( V_95 ) ; V_21 ++ ) {
if ( ! V_95 [ V_21 ] . V_96 )
continue;
if ( F_67 ( V_51 , V_95 [ V_21 ] . V_96 ) )
return V_21 ;
}
return V_97 ;
}
static int F_78 ( char * V_51 , int V_98 , T_4 * V_99 ,
const void * * V_100 )
{
int V_59 ;
T_4 V_101 = * V_99 ;
const char * V_62 = * V_100 ;
while ( isspace ( * V_62 ) && V_101 ) {
V_62 ++ ;
V_101 -- ;
}
if ( ! V_101 )
return 0 ;
for ( V_59 = 0 ; V_59 < V_101 ; V_59 ++ ) {
if ( ! * V_62 )
break;
if ( * V_62 == '\n' ) {
V_62 ++ ;
V_59 ++ ;
break;
}
if ( V_59 < V_98 )
* V_51 ++ = * V_62 ++ ;
}
* V_51 = 0 ;
* V_99 = V_101 - V_59 ;
* V_100 = V_62 ;
F_51 ( V_51 ) ;
return 1 ;
}
int F_79 ( struct V_86 * V_33 , T_4 V_101 , const void * V_102 )
{
char V_51 [ 128 ] ;
struct V_1 * V_2 ;
int V_103 ;
V_103 = V_97 ;
V_2 = NULL ;
while ( F_78 ( V_51 , sizeof( V_51 ) - 1 , & V_101 , & V_102 ) ) {
if ( ! * V_51 || * V_51 == '#' || * V_51 == '\n' )
continue;
if ( * V_51 == '[' )
V_103 = F_77 ( V_51 , V_33 ) ;
else if ( V_95 [ V_103 ] . V_104 &&
( V_2 || ! V_95 [ V_103 ] . V_105 ) )
V_95 [ V_103 ] . V_104 ( V_51 , V_33 , & V_2 ) ;
}
return 0 ;
}
