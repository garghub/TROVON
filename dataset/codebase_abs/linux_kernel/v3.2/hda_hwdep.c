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
F_21 ( & V_2 -> V_22 , sizeof( struct V_44 ) , 32 ) ;
F_21 ( & V_2 -> V_23 , sizeof( struct V_25 ) , 32 ) ;
F_21 ( & V_2 -> V_28 , sizeof( struct V_45 ) , 16 ) ;
return 0 ;
}
static T_3 F_22 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_8 * V_29 = F_23 ( V_47 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
F_24 ( V_2 ) ;
return sprintf ( V_50 , L_2 , F_25 ( V_2 -> V_51 ) ) ;
}
static T_3 F_26 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_8 * V_29 = F_23 ( V_47 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
F_24 ( V_2 ) ;
return sprintf ( V_50 , L_2 , F_25 ( V_2 -> V_52 ) ) ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_8 * V_29 = V_2 -> V_29 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_28 ( V_53 ) ; V_21 ++ )
F_29 ( V_54 , V_29 -> V_34 ,
V_29 -> V_46 , & V_53 [ V_21 ] ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = F_31 ( V_2 ) ;
if ( V_31 < 0 ) {
F_32 ( V_55 L_3 ) ;
return V_31 ;
}
F_13 ( V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_31 ;
F_34 ( V_2 ) ;
F_32 ( V_56 L_4 ) ;
V_31 = F_31 ( V_2 ) ;
if ( V_31 < 0 ) {
F_32 ( V_55
L_5 ) ;
goto error;
}
V_31 = F_35 ( V_2 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_36 ( V_2 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_37 ( V_2 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_38 ( V_2 -> V_33 -> V_34 ) ;
error:
F_39 ( V_2 ) ;
return V_31 ;
}
static char * F_40 ( const char * V_57 , T_4 V_58 )
{
char * V_59 = F_41 ( V_57 , V_58 , V_60 ) ;
char * V_61 ;
if ( ! V_59 )
return NULL ;
V_61 = strchr ( V_59 , '\n' ) ;
if ( V_61 )
* V_61 = 0 ;
return V_59 ;
}
static T_3 F_42 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_8 * V_29 = F_23 ( V_47 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
int V_21 , V_58 = 0 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_24 ; V_21 ++ ) {
struct V_44 * V_62 = F_15 ( & V_2 -> V_22 , V_21 ) ;
V_58 += snprintf ( V_50 + V_58 , V_63 - V_58 ,
L_6 ,
V_62 -> V_64 , V_62 -> V_5 , V_62 -> V_65 ) ;
}
return V_58 ;
}
static int F_43 ( struct V_1 * V_2 , const char * V_50 )
{
struct V_44 * V_62 ;
int V_64 , V_5 , V_65 ;
if ( sscanf ( V_50 , L_7 , & V_64 , & V_5 , & V_65 ) != 3 )
return - V_66 ;
if ( ! V_64 || ! V_5 )
return - V_66 ;
V_62 = F_44 ( & V_2 -> V_22 ) ;
if ( ! V_62 )
return - V_67 ;
V_62 -> V_64 = V_64 ;
V_62 -> V_5 = V_5 ;
V_62 -> V_65 = V_65 ;
return 0 ;
}
static T_3 F_45 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
const char * V_50 , T_4 V_68 )
{
struct V_8 * V_29 = F_23 ( V_47 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
int V_31 = F_43 ( V_2 , V_50 ) ;
if ( V_31 < 0 )
return V_31 ;
return V_68 ;
}
static T_3 F_46 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_8 * V_29 = F_23 ( V_47 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
int V_21 , V_58 = 0 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_23 . V_24 ; V_21 ++ ) {
struct V_25 * V_26 = F_15 ( & V_2 -> V_23 , V_21 ) ;
V_58 += snprintf ( V_50 + V_58 , V_63 - V_58 ,
L_8 , V_26 -> V_27 , V_26 -> V_69 ) ;
}
return V_58 ;
}
static struct V_25 * F_47 ( struct V_1 * V_2 , const char * V_27 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_23 . V_24 ; V_21 ++ ) {
struct V_25 * V_26 = F_15 ( & V_2 -> V_23 , V_21 ) ;
if ( ! strcmp ( V_26 -> V_27 , V_27 ) )
return V_26 ;
}
return NULL ;
}
static void F_48 ( char * V_70 )
{
char * V_61 ;
if ( ! * V_70 )
return;
V_61 = V_70 + strlen ( V_70 ) - 1 ;
for (; isspace ( * V_61 ) ; V_61 -- ) {
* V_61 = 0 ;
if ( V_61 == V_70 )
return;
}
}
static int F_49 ( struct V_1 * V_2 , const char * V_50 )
{
char * V_27 , * V_69 ;
struct V_25 * V_26 ;
V_50 = F_50 ( V_50 ) ;
if ( ! * V_50 || * V_50 == '#' || * V_50 == '\n' )
return 0 ;
if ( * V_50 == '=' )
return - V_66 ;
V_27 = F_40 ( V_50 , 1024 ) ;
if ( ! V_27 )
return - V_67 ;
V_69 = strchr ( V_27 , '=' ) ;
if ( ! V_69 ) {
F_16 ( V_27 ) ;
return - V_66 ;
}
* V_69 ++ = 0 ;
V_69 = F_50 ( V_69 ) ;
F_48 ( V_27 ) ;
F_48 ( V_69 ) ;
V_26 = F_47 ( V_2 , V_27 ) ;
if ( V_26 ) {
F_16 ( V_26 -> V_27 ) ;
V_26 -> V_27 = V_27 ;
V_26 -> V_69 = V_69 ;
return 0 ;
}
if ( V_2 -> V_23 . V_24 >= V_71 )
V_26 = NULL ;
else
V_26 = F_44 ( & V_2 -> V_23 ) ;
if ( ! V_26 ) {
F_16 ( V_27 ) ;
return - V_67 ;
}
V_26 -> V_27 = V_27 ;
V_26 -> V_69 = V_69 ;
return 0 ;
}
static T_3 F_51 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
const char * V_50 , T_4 V_68 )
{
struct V_8 * V_29 = F_23 ( V_47 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
int V_31 = F_49 ( V_2 , V_50 ) ;
if ( V_31 < 0 )
return V_31 ;
return V_68 ;
}
static T_3 F_52 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
char * V_50 )
{
int V_21 , V_58 = 0 ;
for ( V_21 = 0 ; V_21 < V_73 -> V_24 ; V_21 ++ ) {
struct V_45 * V_74 = F_15 ( V_73 , V_21 ) ;
V_58 += sprintf ( V_50 + V_58 , L_9 ,
V_74 -> V_64 , V_74 -> V_75 ) ;
}
return V_58 ;
}
static T_3 F_53 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_8 * V_29 = F_23 ( V_47 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
return F_52 ( V_2 , & V_2 -> V_76 , V_50 ) ;
}
static T_3 F_54 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_8 * V_29 = F_23 ( V_47 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
return F_52 ( V_2 , & V_2 -> V_28 , V_50 ) ;
}
static T_3 F_55 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_8 * V_29 = F_23 ( V_47 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
return F_52 ( V_2 , & V_2 -> V_77 , V_50 ) ;
}
static int F_56 ( struct V_1 * V_2 , const char * V_50 )
{
int V_64 , V_75 ;
if ( sscanf ( V_50 , L_10 , & V_64 , & V_75 ) != 2 )
return - V_66 ;
if ( ! V_64 )
return - V_66 ;
return F_57 ( V_2 , & V_2 -> V_28 , V_64 , V_75 ) ;
}
static T_3 F_58 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
const char * V_50 , T_4 V_68 )
{
struct V_8 * V_29 = F_23 ( V_47 ) ;
struct V_1 * V_2 = V_29 -> V_12 ;
int V_31 = F_56 ( V_2 , V_50 ) ;
if ( V_31 < 0 )
return V_31 ;
return V_68 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_8 * V_29 = V_2 -> V_29 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_28 ( V_78 ) ; V_21 ++ )
F_29 ( V_54 , V_29 -> V_34 ,
V_29 -> V_46 , & V_78 [ V_21 ] ) ;
return 0 ;
}
const char * F_60 ( struct V_1 * V_2 , const char * V_27 )
{
struct V_25 * V_26 = F_47 ( V_2 , V_27 ) ;
return V_26 ? V_26 -> V_69 : NULL ;
}
int F_61 ( struct V_1 * V_2 , const char * V_27 )
{
const char * V_61 = F_60 ( V_2 , V_27 ) ;
if ( ! V_61 || ! * V_61 )
return - V_79 ;
switch ( toupper ( * V_61 ) ) {
case 'T' :
case 'Y' :
case '1' :
return 1 ;
}
return 0 ;
}
static inline int F_62 ( const char * V_80 , const char * V_81 )
{
return F_63 ( V_80 , V_81 , strlen ( V_81 ) ) == 0 ;
}
static void F_64 ( char * V_50 , struct V_82 * V_33 ,
struct V_1 * * V_83 )
{
int V_84 , V_85 , V_86 ;
struct V_1 * V_2 ;
* V_83 = NULL ;
if ( sscanf ( V_50 , L_7 , & V_84 , & V_85 , & V_86 ) == 3 ) {
F_65 (codec, &bus->codec_list, list) {
if ( ( V_84 <= 0 || V_2 -> V_87 == V_84 ) &&
( V_85 <= 0 || V_2 -> V_88 == V_85 ) &&
V_2 -> V_32 == V_86 ) {
* V_83 = V_2 ;
break;
}
}
}
}
static void F_66 ( char * V_50 , struct V_82 * V_33 ,
struct V_1 * * V_83 )
{
F_56 ( * V_83 , V_50 ) ;
}
static void F_67 ( char * V_50 , struct V_82 * V_33 ,
struct V_1 * * V_83 )
{
F_43 ( * V_83 , V_50 ) ;
}
static void F_68 ( char * V_50 , struct V_82 * V_33 ,
struct V_1 * * V_83 )
{
F_49 ( * V_83 , V_50 ) ;
}
static void F_69 ( char * V_50 , struct V_82 * V_33 ,
struct V_1 * * V_83 )
{
F_16 ( ( * V_83 ) -> V_89 ) ;
( * V_83 ) -> V_89 = F_70 ( V_50 , V_60 ) ;
}
static void F_71 ( char * V_50 , struct V_82 * V_33 ,
struct V_1 * * V_83 )
{
F_16 ( ( * V_83 ) -> V_90 ) ;
( * V_83 ) -> V_90 = F_70 ( V_50 , V_60 ) ;
}
static int F_72 ( char * V_50 , struct V_82 * V_33 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_28 ( V_91 ) ; V_21 ++ ) {
if ( ! V_91 [ V_21 ] . V_92 )
continue;
if ( F_62 ( V_50 , V_91 [ V_21 ] . V_92 ) )
return V_21 ;
}
return V_93 ;
}
static int F_73 ( char * V_50 , int V_94 , struct V_95 * V_96 )
{
int V_58 ;
const char * V_61 = V_96 -> V_97 ;
while ( isspace ( * V_61 ) && V_96 -> V_94 ) {
V_61 ++ ;
V_96 -> V_94 -- ;
}
if ( ! V_96 -> V_94 )
return 0 ;
for ( V_58 = 0 ; V_58 < V_96 -> V_94 ; V_58 ++ ) {
if ( ! * V_61 )
break;
if ( * V_61 == '\n' ) {
V_61 ++ ;
V_58 ++ ;
break;
}
if ( V_58 < V_94 )
* V_50 ++ = * V_61 ++ ;
}
* V_50 = 0 ;
V_96 -> V_94 -= V_58 ;
V_96 -> V_97 = V_61 ;
F_48 ( V_50 ) ;
return 1 ;
}
int F_74 ( struct V_82 * V_33 , const char * V_98 )
{
int V_31 ;
const struct V_95 * V_96 ;
struct V_95 V_99 ;
char V_50 [ 128 ] ;
struct V_1 * V_2 ;
int V_100 ;
struct V_46 * V_47 = V_33 -> V_34 -> V_47 ;
if ( F_75 ( ! V_47 ) )
return - V_101 ;
V_31 = F_76 ( & V_96 , V_98 , V_47 ) ;
if ( V_31 < 0 ) {
F_77 ( V_55 L_11 ,
V_98 ) ;
return V_31 ;
}
V_99 = * V_96 ;
V_100 = V_93 ;
V_2 = NULL ;
while ( F_73 ( V_50 , sizeof( V_50 ) - 1 , & V_99 ) ) {
if ( ! * V_50 || * V_50 == '#' || * V_50 == '\n' )
continue;
if ( * V_50 == '[' )
V_100 = F_72 ( V_50 , V_33 ) ;
else if ( V_91 [ V_100 ] . V_102 &&
( V_2 || ! V_91 [ V_100 ] . V_103 ) )
V_91 [ V_100 ] . V_102 ( V_50 , V_33 , & V_2 ) ;
}
F_78 ( V_96 ) ;
return 0 ;
}
