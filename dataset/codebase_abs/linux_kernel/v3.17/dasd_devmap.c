static inline int
F_1 ( const char * V_1 )
{
int V_2 , V_3 ;
V_2 = 0 ;
for ( V_3 = 0 ; ( V_3 < V_4 ) && * V_1 ; V_3 ++ , V_1 ++ )
V_2 += * V_1 ;
return V_2 & 0xff ;
}
static int T_1
F_2 ( char * V_5 )
{
static int V_6 = 0 ;
if ( V_6 < 256 )
V_7 [ V_6 ++ ] = V_5 ;
return 1 ;
}
static int
F_3 ( char * * V_5 , int * V_8 , int * V_9 , int * V_10 )
{
int V_11 , V_12 ;
if ( strncmp ( V_13 , * V_5 , strlen ( V_13 ) ) == 0 ) {
if ( V_14 . type != V_15 ) {
F_4 ( L_1 ) ;
return - V_16 ;
}
* V_8 = 0 ;
* V_9 = V_14 . V_17 . V_18 . V_19 . V_20 ;
* V_10 = V_14 . V_17 . V_18 . V_19 . V_10 ;
* V_5 += strlen ( V_13 ) ;
return 0 ;
}
V_12 = 0 ;
if ( ( * V_5 ) [ 0 ] == '0' && ( * V_5 ) [ 1 ] == 'x' ) {
* V_5 += 2 ;
V_12 = 1 ;
}
if ( ! isxdigit ( ( * V_5 ) [ 0 ] ) )
return - V_16 ;
V_11 = F_5 ( * V_5 , V_5 , 16 ) ;
if ( V_12 || ( * V_5 ) [ 0 ] != '.' ) {
* V_8 = * V_9 = 0 ;
if ( V_11 < 0 || V_11 > 0xffff )
return - V_16 ;
* V_10 = V_11 ;
return 0 ;
}
if ( V_11 < 0 || V_11 > 0xff )
return - V_16 ;
* V_8 = V_11 ;
( * V_5 ) ++ ;
if ( ! isxdigit ( ( * V_5 ) [ 0 ] ) )
return - V_16 ;
V_11 = F_5 ( * V_5 , V_5 , 16 ) ;
if ( V_11 < 0 || V_11 > 0xff || ( * V_5 ) ++ [ 0 ] != '.' )
return - V_16 ;
* V_9 = V_11 ;
if ( ! isxdigit ( ( * V_5 ) [ 0 ] ) )
return - V_16 ;
V_11 = F_5 ( * V_5 , V_5 , 16 ) ;
if ( V_11 < 0 || V_11 > 0xffff )
return - V_16 ;
* V_10 = V_11 ;
return 0 ;
}
static int
F_6 ( char * V_5 , char * * V_21 )
{
int V_22 , V_23 , V_24 ;
V_24 = 0 ;
if ( * V_5 != '(' ) {
* V_21 = V_5 ;
return V_25 ;
}
V_5 ++ ;
V_22 = 0 ;
while ( 1 ) {
for ( V_23 = 0 ;
V_5 [ V_23 ] && V_5 [ V_23 ] != ':' && V_5 [ V_23 ] != ')' ; V_23 ++ ) ;
if ( V_23 == 2 && ! strncmp ( V_5 , L_2 , 2 ) )
V_22 |= V_26 ;
else if ( V_23 == 4 && ! strncmp ( V_5 , L_3 , 4 ) )
V_22 |= V_27 ;
else if ( V_23 == 3 && ! strncmp ( V_5 , L_4 , 3 ) )
V_22 |= V_28 ;
else if ( V_23 == 6 && ! strncmp ( V_5 , L_5 , 6 ) )
V_22 |= V_29 ;
else if ( V_23 == 8 && ! strncmp ( V_5 , L_6 , 8 ) )
V_22 |= V_30 ;
else {
F_7 ( L_7 ,
V_23 , V_5 ) ;
V_24 = - V_16 ;
}
V_5 += V_23 ;
if ( * V_5 != ':' )
break;
V_5 ++ ;
}
if ( * V_5 != ')' ) {
F_7 ( L_8
L_9 ) ;
V_24 = - V_16 ;
} else
V_5 ++ ;
* V_21 = V_5 ;
if ( V_24 != 0 )
return V_24 ;
return V_22 ;
}
static char *
F_8 ( char * V_31 ) {
char * V_32 , * V_33 ;
int V_34 ;
V_32 = strchr ( V_31 , ',' ) ;
if ( V_32 ) {
V_34 = V_32 - V_31 ;
V_33 = V_32 + 1 ;
} else {
V_34 = strlen ( V_31 ) ;
V_33 = V_31 + V_34 ;
}
if ( strncmp ( L_10 , V_31 , V_34 ) == 0 ) {
V_35 = 1 ;
F_9 ( L_11 ) ;
return V_33 ;
}
if ( strncmp ( L_12 , V_31 , V_34 ) == 0 ) {
V_36 = 1 ;
F_9 ( L_13 ) ;
return V_33 ;
}
if ( strncmp ( L_14 , V_31 , V_34 ) == 0 ) {
if ( V_37 )
F_9 ( L_15 ) ;
else {
V_38 = 1 ;
F_9 ( L_16 ) ;
}
return V_33 ;
}
if ( strncmp ( L_17 , V_31 , V_34 ) == 0 ) {
V_39 = 1 ;
F_9 ( L_18
L_19 ) ;
return V_33 ;
}
if ( strncmp ( L_20 , V_31 , V_34 ) == 0 ) {
if ( V_40 )
return V_33 ;
V_40 =
F_10 ( L_21 , V_41 ,
V_41 , V_42 ,
NULL ) ;
if ( ! V_40 )
F_11 ( V_43 , L_22 , L_23
L_24 ) ;
else
F_11 ( V_44 , L_22 ,
L_25 ) ;
return V_33 ;
}
return F_12 ( - V_16 ) ;
}
static char *
F_13 ( char * V_31 ) {
struct V_45 * V_46 ;
int V_47 , V_48 , V_49 ;
int V_50 , V_51 , V_52 ;
int V_22 , V_24 ;
char V_1 [ V_4 + 1 ] , * V_5 ;
V_5 = V_31 ;
V_24 = F_3 ( & V_5 , & V_48 , & V_49 , & V_47 ) ;
if ( V_24 == 0 ) {
V_50 = V_47 ;
V_51 = V_48 ;
V_52 = V_49 ;
if ( * V_5 == '-' ) {
V_5 ++ ;
V_24 = F_3 ( & V_5 , & V_51 , & V_52 , & V_50 ) ;
}
}
if ( V_24 == 0 &&
( V_48 != V_51 || V_49 != V_52 || V_47 > V_50 ) )
V_24 = - V_16 ;
if ( V_24 ) {
F_4 ( L_26 , V_31 ) ;
return F_12 ( V_24 ) ;
}
V_22 = F_6 ( V_5 , & V_5 ) ;
if ( V_22 < 0 )
return F_12 ( - V_16 ) ;
V_22 |= V_53 ;
while ( V_47 <= V_50 ) {
sprintf ( V_1 , L_27 ,
V_48 , V_49 , V_47 ++ ) ;
V_46 = F_14 ( V_1 , V_22 ) ;
if ( F_15 ( V_46 ) )
return ( char * ) V_46 ;
}
if ( * V_5 == ',' )
return V_5 + 1 ;
if ( * V_5 == '\0' )
return V_5 ;
F_7 ( L_28 ,
V_5 ) ;
return F_12 ( - V_16 ) ;
}
static char *
F_16 ( char * V_31 ) {
char * V_33 ;
V_33 = F_8 ( V_31 ) ;
if ( ! F_15 ( V_33 ) )
return V_33 ;
V_33 = F_13 ( V_31 ) ;
return V_33 ;
}
int
F_17 ( void )
{
int V_24 , V_3 ;
char * V_31 ;
V_24 = 0 ;
for ( V_3 = 0 ; V_3 < 256 ; V_3 ++ ) {
if ( V_7 [ V_3 ] == NULL )
break;
V_31 = V_7 [ V_3 ] ;
while ( * V_31 ) {
V_31 = F_16 ( V_31 ) ;
if( F_15 ( V_31 ) ) {
V_24 = F_18 ( V_31 ) ;
break;
}
}
if ( V_24 ) {
F_11 ( V_54 , L_22 , L_29 ) ;
break;
}
}
return V_24 ;
}
static struct V_45 *
F_14 ( const char * V_1 , int V_22 )
{
struct V_45 * V_46 , * V_55 , * V_56 ;
int V_2 ;
V_55 = F_19 ( sizeof( struct V_45 ) , V_57 ) ;
if ( ! V_55 )
return F_12 ( - V_58 ) ;
F_20 ( & V_59 ) ;
V_46 = NULL ;
V_2 = F_1 ( V_1 ) ;
F_21 (tmp, &dasd_hashlists[hash], list)
if ( strncmp ( V_56 -> V_1 , V_1 , V_4 ) == 0 ) {
V_46 = V_56 ;
break;
}
if ( ! V_46 ) {
V_55 -> V_60 = V_61 ++ ;
strncpy ( V_55 -> V_1 , V_1 , V_4 ) ;
V_55 -> V_22 = V_22 ;
V_55 -> V_62 = NULL ;
F_22 ( & V_55 -> V_63 , & V_64 [ V_2 ] ) ;
V_46 = V_55 ;
V_55 = NULL ;
}
F_23 ( & V_59 ) ;
F_24 ( V_55 ) ;
return V_46 ;
}
static struct V_45 *
F_25 ( const char * V_1 )
{
struct V_45 * V_46 , * V_56 ;
int V_2 ;
F_20 ( & V_59 ) ;
V_46 = F_12 ( - V_65 ) ;
V_2 = F_1 ( V_1 ) ;
F_21 (tmp, &dasd_hashlists[hash], list) {
if ( strncmp ( V_56 -> V_1 , V_1 , V_4 ) == 0 ) {
V_46 = V_56 ;
break;
}
}
F_23 ( & V_59 ) ;
return V_46 ;
}
int
F_26 ( const char * V_1 )
{
return F_15 ( F_25 ( V_1 ) ) ? - V_66 : 0 ;
}
static void
F_27 ( void )
{
struct V_45 * V_46 , * V_67 ;
int V_3 ;
F_20 ( & V_59 ) ;
for ( V_3 = 0 ; V_3 < 256 ; V_3 ++ ) {
F_28 (devmap, n, &dasd_hashlists[i], list) {
F_29 ( V_46 -> V_62 != NULL ) ;
F_30 ( & V_46 -> V_63 ) ;
F_24 ( V_46 ) ;
}
}
F_23 ( & V_59 ) ;
}
struct V_68 *
F_31 ( int V_60 )
{
struct V_45 * V_46 , * V_56 ;
struct V_68 * V_62 ;
int V_3 ;
F_20 ( & V_59 ) ;
V_46 = NULL ;
for ( V_3 = 0 ; ( V_3 < 256 ) && ! V_46 ; V_3 ++ )
F_21 (tmp, &dasd_hashlists[i], list)
if ( V_56 -> V_60 == V_60 ) {
V_46 = V_56 ;
break;
}
if ( V_46 && V_46 -> V_62 ) {
V_62 = V_46 -> V_62 ;
F_32 ( V_62 ) ;
} else
V_62 = F_12 ( - V_65 ) ;
F_23 ( & V_59 ) ;
return V_62 ;
}
static struct V_45 *
F_33 ( struct V_69 * V_70 )
{
struct V_45 * V_46 ;
V_46 = F_25 ( F_34 ( & V_70 -> V_71 ) ) ;
if ( F_15 ( V_46 ) )
V_46 = F_14 ( F_34 ( & V_70 -> V_71 ) ,
V_25 ) ;
return V_46 ;
}
struct V_68 *
F_35 ( struct V_69 * V_70 )
{
struct V_45 * V_46 ;
struct V_68 * V_62 ;
unsigned long V_72 ;
int V_24 ;
V_46 = F_33 ( V_70 ) ;
if ( F_15 ( V_46 ) )
return ( void * ) V_46 ;
V_62 = F_36 () ;
if ( F_15 ( V_62 ) )
return V_62 ;
F_37 ( & V_62 -> V_73 , 3 ) ;
F_20 ( & V_59 ) ;
if ( ! V_46 -> V_62 ) {
V_46 -> V_62 = V_62 ;
V_62 -> V_60 = V_46 -> V_60 ;
V_62 -> V_22 = V_46 -> V_22 ;
F_38 ( & V_70 -> V_71 ) ;
V_62 -> V_70 = V_70 ;
V_24 = 0 ;
} else
V_24 = - V_74 ;
F_23 ( & V_59 ) ;
if ( V_24 ) {
F_39 ( V_62 ) ;
return F_12 ( V_24 ) ;
}
F_40 ( F_41 ( V_70 ) , V_72 ) ;
F_42 ( & V_70 -> V_71 , V_62 ) ;
F_43 ( F_41 ( V_70 ) , V_72 ) ;
return V_62 ;
}
void
F_44 ( struct V_68 * V_62 )
{
struct V_69 * V_70 ;
struct V_45 * V_46 ;
unsigned long V_72 ;
V_46 = F_25 ( F_34 ( & V_62 -> V_70 -> V_71 ) ) ;
F_29 ( F_15 ( V_46 ) ) ;
F_20 ( & V_59 ) ;
if ( V_46 -> V_62 != V_62 ) {
F_23 ( & V_59 ) ;
F_45 ( V_62 ) ;
return;
}
V_46 -> V_62 = NULL ;
F_23 ( & V_59 ) ;
F_40 ( F_41 ( V_62 -> V_70 ) , V_72 ) ;
F_42 ( & V_62 -> V_70 -> V_71 , NULL ) ;
F_43 ( F_41 ( V_62 -> V_70 ) , V_72 ) ;
F_46 ( 3 , & V_62 -> V_73 ) ;
F_47 ( V_75 , F_48 ( & V_62 -> V_73 ) == 0 ) ;
V_70 = V_62 -> V_70 ;
V_62 -> V_70 = NULL ;
F_49 ( & V_70 -> V_71 ) ;
F_39 ( V_62 ) ;
}
void
F_50 ( struct V_68 * V_62 )
{
F_51 ( & V_75 ) ;
}
struct V_68 *
F_52 ( struct V_69 * V_70 )
{
struct V_68 * V_62 = F_53 ( & V_70 -> V_71 ) ;
if ( ! V_62 )
return F_12 ( - V_65 ) ;
F_32 ( V_62 ) ;
return V_62 ;
}
struct V_68 *
F_54 ( struct V_69 * V_70 )
{
struct V_68 * V_62 ;
unsigned long V_72 ;
F_40 ( F_41 ( V_70 ) , V_72 ) ;
V_62 = F_52 ( V_70 ) ;
F_43 ( F_41 ( V_70 ) , V_72 ) ;
return V_62 ;
}
void F_55 ( struct V_76 * V_77 , struct V_68 * V_62 )
{
struct V_45 * V_46 ;
V_46 = F_25 ( F_34 ( & V_62 -> V_70 -> V_71 ) ) ;
if ( F_15 ( V_46 ) )
return;
F_20 ( & V_59 ) ;
V_77 -> V_78 = V_46 ;
F_23 ( & V_59 ) ;
}
struct V_68 * F_56 ( struct V_76 * V_77 )
{
struct V_68 * V_62 ;
struct V_45 * V_46 ;
if ( ! V_77 -> V_78 )
return NULL ;
V_62 = NULL ;
F_20 ( & V_59 ) ;
V_46 = V_77 -> V_78 ;
if ( V_46 && V_46 -> V_62 ) {
V_62 = V_46 -> V_62 ;
F_32 ( V_62 ) ;
}
F_23 ( & V_59 ) ;
return V_62 ;
}
static T_2 F_57 ( struct V_62 * V_71 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_45 * V_46 ;
int V_82 ;
V_46 = F_25 ( F_34 ( V_71 ) ) ;
if ( ! F_15 ( V_46 ) )
V_82 = ( V_46 -> V_22 & V_30 ) != 0 ;
else
V_82 = ( V_25 & V_30 ) != 0 ;
return snprintf ( V_81 , V_41 , V_82 ? L_30 : L_31 ) ;
}
static T_2 F_58 ( struct V_62 * V_71 , struct V_79 * V_80 ,
const char * V_81 , T_3 V_6 )
{
struct V_45 * V_46 ;
int V_11 ;
char * V_21 ;
V_46 = F_33 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_46 ) )
return F_18 ( V_46 ) ;
V_11 = F_5 ( V_81 , & V_21 , 0 ) ;
if ( ( ( V_21 + 1 ) < ( V_81 + V_6 ) ) || ( V_11 > 1 ) )
return - V_16 ;
F_20 ( & V_59 ) ;
if ( V_11 )
V_46 -> V_22 |= V_30 ;
else
V_46 -> V_22 &= ~ V_30 ;
if ( V_46 -> V_62 )
V_46 -> V_62 -> V_22 = V_46 -> V_22 ;
F_23 ( & V_59 ) ;
return V_6 ;
}
static T_2
F_60 ( struct V_62 * V_71 , struct V_79 * V_80 , char * V_81 )
{
struct V_45 * V_46 ;
int V_83 ;
V_46 = F_25 ( F_34 ( V_71 ) ) ;
if ( ! F_15 ( V_46 ) )
V_83 = ( V_46 -> V_22 & V_26 ) != 0 ;
else
V_83 = ( V_25 & V_26 ) != 0 ;
return snprintf ( V_81 , V_41 , V_83 ? L_30 : L_31 ) ;
}
static T_2
F_61 ( struct V_62 * V_71 , struct V_79 * V_80 ,
const char * V_81 , T_3 V_6 )
{
struct V_45 * V_46 ;
struct V_68 * V_62 ;
int V_11 ;
char * V_21 ;
V_46 = F_33 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_46 ) )
return F_18 ( V_46 ) ;
V_11 = F_5 ( V_81 , & V_21 , 0 ) ;
if ( ( ( V_21 + 1 ) < ( V_81 + V_6 ) ) || ( V_11 > 1 ) )
return - V_16 ;
F_20 ( & V_59 ) ;
if ( V_11 )
V_46 -> V_22 |= V_26 ;
else
V_46 -> V_22 &= ~ V_26 ;
V_62 = V_46 -> V_62 ;
if ( V_62 ) {
V_62 -> V_22 = V_46 -> V_22 ;
V_11 = V_11 || F_62 ( V_84 , & V_62 -> V_72 ) ;
}
F_23 ( & V_59 ) ;
if ( V_62 && V_62 -> V_85 && V_62 -> V_85 -> V_77 )
F_63 ( V_62 -> V_85 -> V_77 , V_11 ) ;
return V_6 ;
}
static T_2
F_64 ( struct V_62 * V_71 , struct V_79 * V_80 , char * V_81 )
{
struct V_45 * V_46 ;
int V_86 ;
V_46 = F_25 ( F_34 ( V_71 ) ) ;
if ( ! F_15 ( V_46 ) )
V_86 = ( V_46 -> V_22 & V_29 ) != 0 ;
else
V_86 = ( V_25 & V_29 ) != 0 ;
return snprintf ( V_81 , V_41 , V_86 ? L_30 : L_31 ) ;
}
static T_2
F_65 ( struct V_62 * V_71 , struct V_79 * V_80 ,
const char * V_81 , T_3 V_6 )
{
struct V_45 * V_46 ;
int V_11 ;
char * V_21 ;
V_46 = F_33 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_46 ) )
return F_18 ( V_46 ) ;
V_11 = F_5 ( V_81 , & V_21 , 0 ) ;
if ( ( ( V_21 + 1 ) < ( V_81 + V_6 ) ) || ( V_11 > 1 ) )
return - V_16 ;
F_20 ( & V_59 ) ;
if ( V_11 )
V_46 -> V_22 |= V_29 ;
else
V_46 -> V_22 &= ~ V_29 ;
if ( V_46 -> V_62 )
V_46 -> V_62 -> V_22 = V_46 -> V_22 ;
F_23 ( & V_59 ) ;
return V_6 ;
}
static T_2
F_66 ( struct V_62 * V_71 , struct V_79 * V_80 , char * V_81 )
{
struct V_45 * V_46 ;
int V_87 ;
V_46 = F_25 ( F_34 ( V_71 ) ) ;
if ( ! F_15 ( V_46 ) )
V_87 = ( V_46 -> V_22 & V_27 ) != 0 ;
else
V_87 = ( V_25 & V_27 ) != 0 ;
return sprintf ( V_81 , V_87 ? L_30 : L_31 ) ;
}
static T_2
F_67 ( struct V_62 * V_71 , struct V_79 * V_80 ,
const char * V_81 , T_3 V_6 )
{
struct V_45 * V_46 ;
T_2 V_24 ;
int V_11 ;
char * V_21 ;
V_46 = F_33 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_46 ) )
return F_18 ( V_46 ) ;
V_11 = F_5 ( V_81 , & V_21 , 0 ) ;
if ( ( ( V_21 + 1 ) < ( V_81 + V_6 ) ) || ( V_11 > 1 ) )
return - V_16 ;
F_20 ( & V_59 ) ;
V_24 = V_6 ;
if ( ! V_46 -> V_62 && ! ( V_46 -> V_22 & V_28 ) ) {
if ( V_11 )
V_46 -> V_22 |= V_27 ;
else
V_46 -> V_22 &= ~ V_27 ;
} else
V_24 = - V_88 ;
F_23 ( & V_59 ) ;
return V_24 ;
}
static T_2
F_68 ( struct V_62 * V_71 , struct V_79 * V_80 , char * V_81 )
{
struct V_45 * V_46 ;
int V_89 ;
V_46 = F_25 ( F_34 ( V_71 ) ) ;
if ( ! F_15 ( V_46 ) )
V_89 = ( V_46 -> V_22 & V_28 ) != 0 ;
else
V_89 = ( V_25 & V_28 ) != 0 ;
return sprintf ( V_81 , V_89 ? L_30 : L_31 ) ;
}
static T_2
F_69 ( struct V_62 * V_71 , struct V_79 * V_80 ,
const char * V_81 , T_3 V_6 )
{
struct V_45 * V_46 ;
T_2 V_24 ;
unsigned long V_11 ;
V_46 = F_33 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_46 ) )
return F_18 ( V_46 ) ;
if ( ( F_70 ( V_81 , 10 , & V_11 ) != 0 ) || V_11 > 1 )
return - V_16 ;
F_20 ( & V_59 ) ;
V_24 = V_6 ;
if ( ! V_46 -> V_62 && ! ( V_46 -> V_22 & V_27 ) ) {
if ( V_11 )
V_46 -> V_22 |= V_28 ;
else
V_46 -> V_22 &= ~ V_28 ;
} else
V_24 = - V_88 ;
F_23 ( & V_59 ) ;
return V_24 ;
}
static T_2
F_71 ( struct V_62 * V_71 , struct V_79 * V_80 ,
const char * V_81 , T_3 V_6 )
{
struct V_69 * V_70 = F_59 ( V_71 ) ;
struct V_68 * V_62 ;
int V_24 ;
V_62 = F_54 ( V_70 ) ;
if ( F_15 ( V_62 ) ) {
V_24 = F_18 ( V_62 ) ;
goto V_90;
}
if ( F_62 ( V_91 , & V_62 -> V_72 ) ||
F_62 ( V_92 , & V_62 -> V_72 ) ) {
F_45 ( V_62 ) ;
V_24 = - V_74 ;
goto V_90;
}
F_72 ( V_93 , & V_62 -> V_72 ) ;
F_45 ( V_62 ) ;
V_24 = F_73 ( V_70 ) ;
V_90:
return V_24 ? V_24 : V_6 ;
}
static T_2
F_74 ( struct V_62 * V_71 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_68 * V_62 ;
T_2 V_23 ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_62 ) )
goto V_90;
else if ( ! V_62 -> V_94 ) {
F_45 ( V_62 ) ;
goto V_90;
} else {
V_23 = snprintf ( V_81 , V_41 , L_32 ,
V_62 -> V_94 -> V_95 ) ;
F_45 ( V_62 ) ;
return V_23 ;
}
V_90:
V_23 = snprintf ( V_81 , V_41 , L_33 ) ;
return V_23 ;
}
static T_2
F_75 ( struct V_62 * V_71 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_68 * V_62 ;
T_2 V_23 ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
if ( ! F_15 ( V_62 ) ) {
switch ( V_62 -> V_96 ) {
case V_97 :
V_23 = snprintf ( V_81 , V_41 , L_34 ) ;
break;
case V_98 :
V_23 = snprintf ( V_81 , V_41 , L_35 ) ;
break;
case V_99 :
V_23 = snprintf ( V_81 , V_41 , L_36 ) ;
break;
case V_100 :
V_23 = snprintf ( V_81 , V_41 , L_37 ) ;
break;
case V_101 :
V_23 = snprintf ( V_81 , V_41 , L_38 ) ;
break;
case V_102 :
V_23 = snprintf ( V_81 , V_41 , L_39 ) ;
break;
default:
V_23 = snprintf ( V_81 , V_41 , L_40 ) ;
break;
}
F_45 ( V_62 ) ;
} else
V_23 = snprintf ( V_81 , V_41 , L_41 ) ;
return V_23 ;
}
static T_2 F_76 ( struct V_62 * V_71 ,
struct V_79 * V_80 , char * V_81 )
{
struct V_68 * V_62 ;
struct V_103 V_104 ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_62 ) )
return sprintf ( V_81 , L_31 ) ;
if ( V_62 -> V_94 && V_62 -> V_94 -> V_105 &&
! V_62 -> V_94 -> V_105 ( V_62 , & V_104 ) ) {
if ( V_104 . type == V_106 ||
V_104 . type == V_107 ) {
F_45 ( V_62 ) ;
return sprintf ( V_81 , L_30 ) ;
}
}
F_45 ( V_62 ) ;
return sprintf ( V_81 , L_31 ) ;
}
static T_2 F_77 ( struct V_62 * V_71 ,
struct V_79 * V_80 , char * V_81 )
{
struct V_68 * V_62 ;
struct V_103 V_104 ;
char * V_108 ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
V_108 = L_42 ;
if ( F_15 ( V_62 ) )
return snprintf ( V_81 , V_41 , L_32 , V_108 ) ;
if ( V_62 -> V_94 && V_62 -> V_94 -> V_105 &&
! V_62 -> V_94 -> V_105 ( V_62 , & V_104 ) )
V_108 = V_104 . V_108 ;
F_45 ( V_62 ) ;
return snprintf ( V_81 , V_41 , L_32 , V_108 ) ;
}
static T_2
F_78 ( struct V_62 * V_71 , struct V_79 * V_80 , char * V_81 )
{
struct V_68 * V_62 ;
struct V_103 V_104 ;
char V_109 [ V_110 ] ;
char V_111 [ 3 ] ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
V_109 [ 0 ] = 0 ;
if ( F_15 ( V_62 ) )
return snprintf ( V_81 , V_41 , L_32 , V_109 ) ;
if ( V_62 -> V_94 && V_62 -> V_94 -> V_105 &&
! V_62 -> V_94 -> V_105 ( V_62 , & V_104 ) ) {
switch ( V_104 . type ) {
case V_112 :
snprintf ( V_111 , sizeof( V_111 ) , L_43 ,
V_104 . V_113 ) ;
break;
case V_106 :
snprintf ( V_111 , sizeof( V_111 ) , L_43 ,
V_104 . V_114 ) ;
break;
case V_107 :
snprintf ( V_111 , sizeof( V_111 ) , L_44 ) ;
break;
default:
snprintf ( V_111 , sizeof( V_111 ) , L_43 ,
V_104 . V_113 ) ;
break;
}
if ( strlen ( V_104 . V_115 ) > 0 )
snprintf ( V_109 , sizeof( V_109 ) ,
L_45 ,
V_104 . V_108 , V_104 . V_116 , V_104 . V_20 , V_111 ,
V_104 . V_115 ) ;
else
snprintf ( V_109 , sizeof( V_109 ) ,
L_46 ,
V_104 . V_108 , V_104 . V_116 , V_104 . V_20 , V_111 ) ;
}
F_45 ( V_62 ) ;
return snprintf ( V_81 , V_41 , L_32 , V_109 ) ;
}
static T_2
F_79 ( struct V_62 * V_71 , struct V_79 * V_80 , char * V_81 )
{
struct V_45 * V_46 ;
int V_117 ;
V_46 = F_25 ( F_34 ( V_71 ) ) ;
if ( ! F_15 ( V_46 ) && V_46 -> V_62 )
V_117 = F_80 ( V_46 -> V_62 ) ;
else
V_117 = 0 ;
return snprintf ( V_81 , V_41 , V_117 ? L_30 : L_31 ) ;
}
static T_2
F_81 ( struct V_62 * V_71 , struct V_79 * V_80 ,
const char * V_81 , T_3 V_6 )
{
struct V_45 * V_46 ;
int V_11 , V_24 ;
char * V_21 ;
V_46 = F_33 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_46 ) )
return F_18 ( V_46 ) ;
if ( ! V_46 -> V_62 )
return - V_65 ;
V_11 = F_5 ( V_81 , & V_21 , 0 ) ;
if ( ( ( V_21 + 1 ) < ( V_81 + V_6 ) ) || ( V_11 > 1 ) )
return - V_16 ;
if ( V_11 ) {
V_24 = F_82 ( V_46 -> V_62 ) ;
if ( V_24 )
return V_24 ;
} else
F_83 ( V_46 -> V_62 ) ;
return V_6 ;
}
static T_2
F_84 ( struct V_62 * V_71 , struct V_79 * V_80 , char * V_81 )
{
struct V_68 * V_62 ;
int V_23 ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_62 ) )
return - V_65 ;
V_23 = snprintf ( V_81 , V_41 , L_47 , V_62 -> V_118 ) ;
F_45 ( V_62 ) ;
return V_23 ;
}
static T_2
F_85 ( struct V_62 * V_71 , struct V_79 * V_80 ,
const char * V_81 , T_3 V_6 )
{
struct V_68 * V_62 ;
unsigned long V_11 ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_62 ) )
return - V_65 ;
if ( ( F_70 ( V_81 , 10 , & V_11 ) != 0 ) ||
( V_11 > V_119 ) || V_11 == 0 ) {
F_45 ( V_62 ) ;
return - V_16 ;
}
if ( V_11 )
V_62 -> V_118 = V_11 ;
F_45 ( V_62 ) ;
return V_6 ;
}
static T_2
F_86 ( struct V_62 * V_71 , struct V_79 * V_80 , char * V_81 )
{
struct V_68 * V_62 ;
int V_23 ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_62 ) )
return - V_65 ;
V_23 = snprintf ( V_81 , V_41 , L_47 , V_62 -> V_120 ) ;
F_45 ( V_62 ) ;
return V_23 ;
}
static T_2
F_87 ( struct V_62 * V_71 , struct V_79 * V_80 ,
const char * V_81 , T_3 V_6 )
{
struct V_68 * V_62 ;
unsigned long V_11 ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_62 ) )
return - V_65 ;
if ( ( F_70 ( V_81 , 10 , & V_11 ) != 0 ) ||
( V_11 > V_121 ) ) {
F_45 ( V_62 ) ;
return - V_16 ;
}
if ( V_11 )
V_62 -> V_120 = V_11 ;
F_45 ( V_62 ) ;
return V_6 ;
}
static T_2
F_88 ( struct V_62 * V_71 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_68 * V_62 ;
int V_23 ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_62 ) )
return - V_65 ;
V_23 = snprintf ( V_81 , V_41 , L_47 , V_62 -> V_122 ) ;
F_45 ( V_62 ) ;
return V_23 ;
}
static T_2
F_89 ( struct V_62 * V_71 , struct V_79 * V_80 ,
const char * V_81 , T_3 V_6 )
{
struct V_68 * V_62 ;
struct V_123 * V_124 ;
unsigned long V_11 , V_72 ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_62 ) || ! V_62 -> V_85 )
return - V_65 ;
if ( ( F_70 ( V_81 , 10 , & V_11 ) != 0 ) ||
V_11 > V_125 / V_126 ) {
F_45 ( V_62 ) ;
return - V_16 ;
}
V_124 = V_62 -> V_85 -> V_123 ;
if ( ! V_124 ) {
F_45 ( V_62 ) ;
return - V_65 ;
}
F_40 ( & V_62 -> V_85 -> V_127 , V_72 ) ;
if ( ! V_11 )
F_90 ( V_124 , NULL ) ;
else
F_90 ( V_124 , V_128 ) ;
V_62 -> V_122 = V_11 ;
F_91 ( V_124 , V_62 -> V_122 * V_126 ) ;
F_43 ( & V_62 -> V_85 -> V_127 , V_72 ) ;
F_45 ( V_62 ) ;
return V_6 ;
}
static T_2 F_92 ( struct V_62 * V_71 ,
struct V_79 * V_80 ,
char * V_81 )
{
struct V_45 * V_46 ;
int V_24 = 0 ;
V_46 = F_25 ( F_34 ( V_71 ) ) ;
if ( F_15 ( V_46 ) ) {
V_24 = snprintf ( V_81 , V_41 , L_48 ) ;
} else {
F_20 ( & V_59 ) ;
if ( V_46 -> V_22 & V_129 )
V_24 = snprintf ( V_81 , V_41 , L_49 ) ;
else
V_24 = snprintf ( V_81 , V_41 , L_48 ) ;
F_23 ( & V_59 ) ;
}
return V_24 ;
}
static T_2 F_93 ( struct V_62 * V_71 ,
struct V_79 * V_80 ,
const char * V_81 , T_3 V_6 )
{
struct V_45 * V_46 ;
int V_24 ;
V_46 = F_33 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_46 ) )
return F_18 ( V_46 ) ;
V_24 = 0 ;
F_20 ( & V_59 ) ;
if ( F_94 ( L_50 , V_81 ) )
V_46 -> V_22 &= ~ V_129 ;
else if ( F_94 ( L_51 , V_81 ) )
V_46 -> V_22 |= V_129 ;
else
V_24 = - V_16 ;
if ( V_46 -> V_62 )
V_46 -> V_62 -> V_22 = V_46 -> V_22 ;
F_23 ( & V_59 ) ;
if ( V_24 )
return V_24 ;
else
return V_6 ;
}
static T_2 F_95 ( struct V_62 * V_71 ,
struct V_79 * V_80 ,
char * V_81 )
{
struct V_68 * V_62 ;
int V_24 = 0 ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_62 ) )
return snprintf ( V_81 , V_41 , L_33 ) ;
if ( F_62 ( V_130 , & V_62 -> V_72 ) )
V_24 = snprintf ( V_81 , V_41 , L_52 ) ;
else if ( F_62 ( V_131 , & V_62 -> V_72 ) )
V_24 = snprintf ( V_81 , V_41 , L_53 ) ;
else
V_24 = snprintf ( V_81 , V_41 , L_33 ) ;
F_45 ( V_62 ) ;
return V_24 ;
}
static T_2 F_96 ( struct V_62 * V_71 ,
struct V_79 * V_80 ,
const char * V_81 , T_3 V_6 )
{
struct V_68 * V_62 ;
int V_24 = 0 ;
V_62 = F_54 ( F_59 ( V_71 ) ) ;
if ( F_15 ( V_62 ) )
return - V_65 ;
if ( F_94 ( L_54 , V_81 ) )
F_97 ( V_131 , & V_62 -> V_72 ) ;
else
V_24 = - V_16 ;
F_45 ( V_62 ) ;
if ( V_24 )
return V_24 ;
else
return V_6 ;
}
int
F_98 ( struct V_69 * V_70 , int V_132 )
{
struct V_45 * V_46 ;
V_46 = F_25 ( F_34 ( & V_70 -> V_71 ) ) ;
if ( F_15 ( V_46 ) )
return F_18 ( V_46 ) ;
return ( ( V_46 -> V_22 & V_132 ) != 0 ) ;
}
int
F_99 ( struct V_69 * V_70 , int V_132 , int V_133 )
{
struct V_45 * V_46 ;
V_46 = F_25 ( F_34 ( & V_70 -> V_71 ) ) ;
if ( F_15 ( V_46 ) )
return F_18 ( V_46 ) ;
F_20 ( & V_59 ) ;
if ( V_133 )
V_46 -> V_22 |= V_132 ;
else
V_46 -> V_22 &= ~ V_132 ;
if ( V_46 -> V_62 )
V_46 -> V_62 -> V_22 = V_46 -> V_22 ;
F_23 ( & V_59 ) ;
return 0 ;
}
int
F_100 ( struct V_69 * V_70 )
{
return F_101 ( & V_70 -> V_71 . V_134 , & V_135 ) ;
}
void
F_102 ( struct V_69 * V_70 )
{
F_103 ( & V_70 -> V_71 . V_134 , & V_135 ) ;
}
int
F_104 ( void )
{
int V_3 ;
V_61 = 0 ;
for ( V_3 = 0 ; V_3 < 256 ; V_3 ++ )
F_105 ( & V_64 [ V_3 ] ) ;
return 0 ;
}
void
F_106 ( void )
{
F_27 () ;
}
