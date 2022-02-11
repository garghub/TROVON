static inline int
F_1 ( const char * V_1 )
{
int V_2 , V_3 ;
V_2 = 0 ;
for ( V_3 = 0 ; ( V_3 < V_4 ) && * V_1 ; V_3 ++ , V_1 ++ )
V_2 += * V_1 ;
return V_2 & 0xff ;
}
static int T_1 F_2 ( char * V_5 )
{
static int V_3 V_6 ;
char * V_7 ;
while ( V_3 < V_8 ) {
V_7 = F_3 ( & V_5 , L_1 ) ;
if ( ! V_7 )
break;
V_9 [ V_3 ++ ] = V_7 ;
}
return 1 ;
}
static int T_1 F_4 ( char * V_10 , int * V_11 , int * V_12 , int * V_13 )
{
unsigned int V_14 ;
char * V_15 ;
if ( strncmp ( V_16 , V_10 , strlen ( V_16 ) ) == 0 ) {
if ( V_17 . type != V_18 ) {
F_5 ( L_2 ) ;
return - V_19 ;
}
* V_11 = 0 ;
* V_12 = V_17 . V_20 . V_21 . V_22 . V_23 ;
* V_13 = V_17 . V_20 . V_21 . V_22 . V_13 ;
return 0 ;
}
if ( ! F_6 ( V_10 , 16 , & V_14 ) ) {
* V_11 = * V_12 = 0 ;
if ( V_14 > 0xffff )
return - V_19 ;
* V_13 = V_14 ;
return 0 ;
}
V_15 = F_3 ( & V_10 , L_3 ) ;
if ( F_6 ( V_15 , 16 , & V_14 ) || V_14 > 0xff )
return - V_19 ;
* V_11 = V_14 ;
V_15 = F_3 ( & V_10 , L_3 ) ;
if ( F_6 ( V_15 , 16 , & V_14 ) || V_14 > 0xff )
return - V_19 ;
* V_12 = V_14 ;
V_15 = F_3 ( & V_10 , L_3 ) ;
if ( F_6 ( V_15 , 16 , & V_14 ) || V_14 > 0xffff )
return - V_19 ;
* V_13 = V_14 ;
return 0 ;
}
static int T_1 F_7 ( char * V_10 )
{
int V_24 , V_25 , V_26 ;
V_24 = 0 ;
V_26 = 0 ;
if ( ! V_10 )
return V_27 ;
while ( 1 ) {
for ( V_25 = 0 ;
V_10 [ V_25 ] && V_10 [ V_25 ] != ':' && V_10 [ V_25 ] != ')' ; V_25 ++ ) ;
if ( V_25 == 2 && ! strncmp ( V_10 , L_4 , 2 ) )
V_24 |= V_28 ;
else if ( V_25 == 4 && ! strncmp ( V_10 , L_5 , 4 ) )
V_24 |= V_29 ;
else if ( V_25 == 3 && ! strncmp ( V_10 , L_6 , 3 ) )
V_24 |= V_30 ;
else if ( V_25 == 6 && ! strncmp ( V_10 , L_7 , 6 ) )
V_24 |= V_31 ;
else if ( V_25 == 8 && ! strncmp ( V_10 , L_8 , 8 ) )
V_24 |= V_32 ;
else {
F_8 ( L_9 ,
V_25 , V_10 ) ;
V_26 = - V_19 ;
}
V_10 += V_25 ;
if ( * V_10 != ':' )
break;
V_10 ++ ;
}
return V_26 ? : V_24 ;
}
static int T_1 F_9 ( char * V_33 )
{
int V_34 = strlen ( V_33 ) ;
if ( strncmp ( L_10 , V_33 , V_34 ) == 0 ) {
V_35 = 1 ;
F_10 ( L_11 ) ;
return 0 ;
}
if ( strncmp ( L_12 , V_33 , V_34 ) == 0 ) {
V_36 = 1 ;
F_10 ( L_13 ) ;
return 0 ;
}
if ( strncmp ( L_14 , V_33 , V_34 ) == 0 ) {
if ( V_37 )
F_10 ( L_15 ) ;
else {
V_38 = 1 ;
F_10 ( L_16 ) ;
}
return 0 ;
}
if ( strncmp ( L_17 , V_33 , V_34 ) == 0 ) {
V_39 = 1 ;
F_10 ( L_18
L_19 ) ;
return 0 ;
}
if ( strncmp ( L_20 , V_33 , V_34 ) == 0 ) {
if ( V_40 )
return 0 ;
V_40 =
F_11 ( L_21 , V_41 ,
V_41 , V_42 ,
NULL ) ;
if ( ! V_40 )
F_12 ( V_43 , L_22 , L_23
L_24 ) ;
else
F_12 ( V_44 , L_22 ,
L_25 ) ;
return 0 ;
}
return - V_19 ;
}
static int T_1 F_13 ( char * V_45 , char * * V_46 ,
char * * V_47 , char * * V_48 )
{
int V_26 = 0 ;
if ( strchr ( V_45 , '-' ) ) {
* V_46 = F_3 ( & V_45 , L_26 ) ;
* V_47 = F_3 ( & V_45 , L_27 ) ;
* V_48 = F_3 ( & V_45 , L_28 ) ;
} else {
* V_46 = F_3 ( & V_45 , L_27 ) ;
* V_48 = F_3 ( & V_45 , L_28 ) ;
}
if ( * V_48 && ! V_45 ) {
F_8 ( L_29 ) ;
V_26 = - V_19 ;
}
return V_26 ;
}
static int T_1 F_14 ( const char * V_45 )
{
struct V_49 * V_50 ;
int V_51 , V_52 , V_53 ;
int V_54 , V_55 , V_56 ;
int V_24 ;
char V_1 [ V_4 + 1 ] ;
char * V_48 = NULL ;
char * V_46 = NULL ;
char * V_47 = NULL ;
int V_26 = 0 ;
char * V_7 ;
V_7 = F_15 ( V_45 , V_57 ) ;
if ( ! V_7 )
return - V_58 ;
if ( F_13 ( V_7 , & V_46 , & V_47 , & V_48 ) ) {
V_26 = - V_19 ;
goto V_59;
}
if ( F_4 ( V_46 , & V_52 , & V_53 , & V_51 ) ) {
V_26 = - V_19 ;
goto V_59;
}
V_54 = V_51 ;
V_55 = V_52 ;
V_56 = V_53 ;
if ( V_47 ) {
if ( F_4 ( V_47 , & V_55 , & V_56 , & V_54 ) ) {
V_26 = - V_19 ;
goto V_59;
}
if ( V_52 != V_55 || V_53 != V_56 || V_51 > V_54 ) {
F_5 ( L_30 , V_45 ) ;
V_26 = - V_19 ;
goto V_59;
}
}
V_24 = F_7 ( V_48 ) ;
if ( V_24 < 0 ) {
V_26 = - V_19 ;
goto V_59;
}
V_24 |= V_60 ;
while ( V_51 <= V_54 ) {
sprintf ( V_1 , L_31 , V_52 , V_53 , V_51 ++ ) ;
V_50 = F_16 ( V_1 , V_24 ) ;
if ( F_17 ( V_50 ) ) {
V_26 = F_18 ( V_50 ) ;
goto V_59;
}
}
V_59:
F_19 ( V_7 ) ;
return V_26 ;
}
int T_1 F_20 ( void )
{
int V_26 , V_3 ;
char * V_61 ;
V_26 = 0 ;
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ ) {
V_61 = V_9 [ V_3 ] ;
if ( ! V_61 )
break;
if ( * V_61 == '\0' )
continue;
V_26 = F_9 ( V_61 ) ;
if ( V_26 )
V_26 = F_14 ( V_61 ) ;
if ( V_26 )
break;
}
return V_26 ;
}
static struct V_49 *
F_16 ( const char * V_1 , int V_24 )
{
struct V_49 * V_50 , * V_62 , * V_7 ;
int V_2 ;
V_62 = F_21 ( sizeof( struct V_49 ) , V_57 ) ;
if ( ! V_62 )
return F_22 ( - V_58 ) ;
F_23 ( & V_63 ) ;
V_50 = NULL ;
V_2 = F_1 ( V_1 ) ;
F_24 (tmp, &dasd_hashlists[hash], list)
if ( strncmp ( V_7 -> V_1 , V_1 , V_4 ) == 0 ) {
V_50 = V_7 ;
break;
}
if ( ! V_50 ) {
V_62 -> V_64 = V_65 ++ ;
strncpy ( V_62 -> V_1 , V_1 , V_4 ) ;
V_62 -> V_24 = V_24 ;
V_62 -> V_66 = NULL ;
F_25 ( & V_62 -> V_67 , & V_68 [ V_2 ] ) ;
V_50 = V_62 ;
V_62 = NULL ;
}
F_26 ( & V_63 ) ;
F_19 ( V_62 ) ;
return V_50 ;
}
static struct V_49 *
F_27 ( const char * V_1 )
{
struct V_49 * V_50 , * V_7 ;
int V_2 ;
F_23 ( & V_63 ) ;
V_50 = F_22 ( - V_69 ) ;
V_2 = F_1 ( V_1 ) ;
F_24 (tmp, &dasd_hashlists[hash], list) {
if ( strncmp ( V_7 -> V_1 , V_1 , V_4 ) == 0 ) {
V_50 = V_7 ;
break;
}
}
F_26 ( & V_63 ) ;
return V_50 ;
}
int
F_28 ( const char * V_1 )
{
return F_17 ( F_27 ( V_1 ) ) ? - V_70 : 0 ;
}
static void
F_29 ( void )
{
struct V_49 * V_50 , * V_71 ;
int V_3 ;
F_23 ( & V_63 ) ;
for ( V_3 = 0 ; V_3 < 256 ; V_3 ++ ) {
F_30 (devmap, n, &dasd_hashlists[i], list) {
F_31 ( V_50 -> V_66 != NULL ) ;
F_32 ( & V_50 -> V_67 ) ;
F_19 ( V_50 ) ;
}
}
F_26 ( & V_63 ) ;
}
struct V_72 *
F_33 ( int V_64 )
{
struct V_49 * V_50 , * V_7 ;
struct V_72 * V_66 ;
int V_3 ;
F_23 ( & V_63 ) ;
V_50 = NULL ;
for ( V_3 = 0 ; ( V_3 < 256 ) && ! V_50 ; V_3 ++ )
F_24 (tmp, &dasd_hashlists[i], list)
if ( V_7 -> V_64 == V_64 ) {
V_50 = V_7 ;
break;
}
if ( V_50 && V_50 -> V_66 ) {
V_66 = V_50 -> V_66 ;
F_34 ( V_66 ) ;
} else
V_66 = F_22 ( - V_69 ) ;
F_26 ( & V_63 ) ;
return V_66 ;
}
static struct V_49 *
F_35 ( struct V_73 * V_74 )
{
struct V_49 * V_50 ;
V_50 = F_27 ( F_36 ( & V_74 -> V_75 ) ) ;
if ( F_17 ( V_50 ) )
V_50 = F_16 ( F_36 ( & V_74 -> V_75 ) ,
V_27 ) ;
return V_50 ;
}
struct V_72 *
F_37 ( struct V_73 * V_74 )
{
struct V_49 * V_50 ;
struct V_72 * V_66 ;
unsigned long V_76 ;
int V_26 ;
V_50 = F_35 ( V_74 ) ;
if ( F_17 ( V_50 ) )
return ( void * ) V_50 ;
V_66 = F_38 () ;
if ( F_17 ( V_66 ) )
return V_66 ;
F_39 ( & V_66 -> V_77 , 3 ) ;
F_23 ( & V_63 ) ;
if ( ! V_50 -> V_66 ) {
V_50 -> V_66 = V_66 ;
V_66 -> V_64 = V_50 -> V_64 ;
V_66 -> V_24 = V_50 -> V_24 ;
F_40 ( & V_74 -> V_75 ) ;
V_66 -> V_74 = V_74 ;
V_26 = 0 ;
} else
V_26 = - V_78 ;
F_26 ( & V_63 ) ;
if ( V_26 ) {
F_41 ( V_66 ) ;
return F_22 ( V_26 ) ;
}
F_42 ( F_43 ( V_74 ) , V_76 ) ;
F_44 ( & V_74 -> V_75 , V_66 ) ;
F_45 ( F_43 ( V_74 ) , V_76 ) ;
return V_66 ;
}
void
F_46 ( struct V_72 * V_66 )
{
struct V_73 * V_74 ;
struct V_49 * V_50 ;
unsigned long V_76 ;
V_50 = F_27 ( F_36 ( & V_66 -> V_74 -> V_75 ) ) ;
F_31 ( F_17 ( V_50 ) ) ;
F_23 ( & V_63 ) ;
if ( V_50 -> V_66 != V_66 ) {
F_26 ( & V_63 ) ;
F_47 ( V_66 ) ;
return;
}
V_50 -> V_66 = NULL ;
F_26 ( & V_63 ) ;
F_42 ( F_43 ( V_66 -> V_74 ) , V_76 ) ;
F_44 ( & V_66 -> V_74 -> V_75 , NULL ) ;
F_45 ( F_43 ( V_66 -> V_74 ) , V_76 ) ;
F_48 ( 3 , & V_66 -> V_77 ) ;
F_49 ( V_79 , F_50 ( & V_66 -> V_77 ) == 0 ) ;
F_51 ( V_66 ) ;
V_74 = V_66 -> V_74 ;
V_66 -> V_74 = NULL ;
F_52 ( & V_74 -> V_75 ) ;
F_41 ( V_66 ) ;
}
void
F_53 ( struct V_72 * V_66 )
{
F_54 ( & V_79 ) ;
}
struct V_72 *
F_55 ( struct V_73 * V_74 )
{
struct V_72 * V_66 = F_56 ( & V_74 -> V_75 ) ;
if ( ! V_66 )
return F_22 ( - V_69 ) ;
F_34 ( V_66 ) ;
return V_66 ;
}
struct V_72 *
F_57 ( struct V_73 * V_74 )
{
struct V_72 * V_66 ;
unsigned long V_76 ;
F_42 ( F_43 ( V_74 ) , V_76 ) ;
V_66 = F_55 ( V_74 ) ;
F_45 ( F_43 ( V_74 ) , V_76 ) ;
return V_66 ;
}
void F_58 ( struct V_80 * V_81 , struct V_72 * V_66 )
{
struct V_49 * V_50 ;
V_50 = F_27 ( F_36 ( & V_66 -> V_74 -> V_75 ) ) ;
if ( F_17 ( V_50 ) )
return;
F_23 ( & V_63 ) ;
V_81 -> V_82 = V_50 ;
F_26 ( & V_63 ) ;
}
struct V_72 * F_59 ( struct V_80 * V_81 )
{
struct V_72 * V_66 ;
struct V_49 * V_50 ;
if ( ! V_81 -> V_82 )
return NULL ;
V_66 = NULL ;
F_23 ( & V_63 ) ;
V_50 = V_81 -> V_82 ;
if ( V_50 && V_50 -> V_66 ) {
V_66 = V_50 -> V_66 ;
F_34 ( V_66 ) ;
}
F_26 ( & V_63 ) ;
return V_66 ;
}
static T_2 F_60 ( struct V_66 * V_75 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_49 * V_50 ;
int V_86 ;
V_50 = F_27 ( F_36 ( V_75 ) ) ;
if ( ! F_17 ( V_50 ) )
V_86 = ( V_50 -> V_24 & V_32 ) != 0 ;
else
V_86 = ( V_27 & V_32 ) != 0 ;
return snprintf ( V_85 , V_41 , V_86 ? L_32 : L_33 ) ;
}
static T_2 F_61 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
unsigned int V_14 ;
int V_26 ;
if ( F_6 ( V_85 , 0 , & V_14 ) || V_14 > 1 )
return - V_19 ;
V_26 = F_62 ( F_63 ( V_75 ) , V_32 , V_14 ) ;
return V_26 ? : V_87 ;
}
static T_2
F_64 ( struct V_66 * V_75 , struct V_83 * V_84 , char * V_85 )
{
struct V_49 * V_50 ;
struct V_72 * V_66 ;
int V_88 = 0 ;
V_50 = F_27 ( F_36 ( V_75 ) ) ;
if ( F_17 ( V_50 ) )
goto V_59;
V_88 = ! ! ( V_50 -> V_24 & V_28 ) ;
F_23 ( & V_63 ) ;
V_66 = V_50 -> V_66 ;
if ( V_66 )
V_88 |= F_65 ( V_89 , & V_66 -> V_76 ) ;
F_26 ( & V_63 ) ;
V_59:
return snprintf ( V_85 , V_41 , V_88 ? L_32 : L_33 ) ;
}
static T_2
F_66 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_73 * V_74 = F_63 ( V_75 ) ;
struct V_72 * V_66 ;
unsigned long V_76 ;
unsigned int V_14 ;
int V_26 ;
if ( F_6 ( V_85 , 0 , & V_14 ) || V_14 > 1 )
return - V_19 ;
V_26 = F_62 ( V_74 , V_28 , V_14 ) ;
if ( V_26 )
return V_26 ;
V_66 = F_57 ( V_74 ) ;
if ( F_17 ( V_66 ) )
return V_87 ;
F_42 ( F_43 ( V_74 ) , V_76 ) ;
V_14 = V_14 || F_65 ( V_89 , & V_66 -> V_76 ) ;
if ( ! V_66 -> V_90 || ! V_66 -> V_90 -> V_81 ||
F_65 ( V_91 , & V_66 -> V_76 ) ) {
F_45 ( F_43 ( V_74 ) , V_76 ) ;
goto V_59;
}
F_67 ( & V_66 -> V_90 -> V_92 ) ;
F_45 ( F_43 ( V_74 ) , V_76 ) ;
F_68 ( V_66 -> V_90 -> V_81 , V_14 ) ;
F_69 ( & V_66 -> V_90 -> V_92 ) ;
V_59:
F_47 ( V_66 ) ;
return V_87 ;
}
static T_2
F_70 ( struct V_66 * V_75 , struct V_83 * V_84 , char * V_85 )
{
struct V_49 * V_50 ;
int V_93 ;
V_50 = F_27 ( F_36 ( V_75 ) ) ;
if ( ! F_17 ( V_50 ) )
V_93 = ( V_50 -> V_24 & V_31 ) != 0 ;
else
V_93 = ( V_27 & V_31 ) != 0 ;
return snprintf ( V_85 , V_41 , V_93 ? L_32 : L_33 ) ;
}
static T_2
F_71 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
unsigned int V_14 ;
int V_26 ;
if ( F_6 ( V_85 , 0 , & V_14 ) || V_14 > 1 )
return - V_19 ;
V_26 = F_62 ( F_63 ( V_75 ) , V_31 , V_14 ) ;
return V_26 ? : V_87 ;
}
static T_2
F_72 ( struct V_66 * V_75 , struct V_83 * V_84 , char * V_85 )
{
struct V_49 * V_50 ;
int V_94 ;
V_50 = F_27 ( F_36 ( V_75 ) ) ;
if ( ! F_17 ( V_50 ) )
V_94 = ( V_50 -> V_24 & V_29 ) != 0 ;
else
V_94 = ( V_27 & V_29 ) != 0 ;
return sprintf ( V_85 , V_94 ? L_32 : L_33 ) ;
}
static T_2
F_73 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_49 * V_50 ;
unsigned int V_14 ;
T_2 V_26 ;
V_50 = F_35 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_50 ) )
return F_18 ( V_50 ) ;
if ( F_6 ( V_85 , 0 , & V_14 ) || V_14 > 1 )
return - V_19 ;
F_23 ( & V_63 ) ;
V_26 = V_87 ;
if ( ! V_50 -> V_66 && ! ( V_50 -> V_24 & V_30 ) ) {
if ( V_14 )
V_50 -> V_24 |= V_29 ;
else
V_50 -> V_24 &= ~ V_29 ;
} else
V_26 = - V_95 ;
F_26 ( & V_63 ) ;
return V_26 ;
}
static T_2
F_74 ( struct V_66 * V_75 , struct V_83 * V_84 , char * V_85 )
{
struct V_49 * V_50 ;
int V_96 ;
V_50 = F_27 ( F_36 ( V_75 ) ) ;
if ( ! F_17 ( V_50 ) )
V_96 = ( V_50 -> V_24 & V_30 ) != 0 ;
else
V_96 = ( V_27 & V_30 ) != 0 ;
return sprintf ( V_85 , V_96 ? L_32 : L_33 ) ;
}
static T_2
F_75 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_49 * V_50 ;
T_2 V_26 ;
unsigned long V_14 ;
V_50 = F_35 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_50 ) )
return F_18 ( V_50 ) ;
if ( ( F_76 ( V_85 , 10 , & V_14 ) != 0 ) || V_14 > 1 )
return - V_19 ;
F_23 ( & V_63 ) ;
V_26 = V_87 ;
if ( ! V_50 -> V_66 && ! ( V_50 -> V_24 & V_29 ) ) {
if ( V_14 )
V_50 -> V_24 |= V_30 ;
else
V_50 -> V_24 &= ~ V_30 ;
} else
V_26 = - V_95 ;
F_26 ( & V_63 ) ;
return V_26 ;
}
static T_2
F_77 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_73 * V_74 = F_63 ( V_75 ) ;
struct V_72 * V_66 ;
unsigned long V_76 ;
int V_26 ;
F_42 ( F_43 ( V_74 ) , V_76 ) ;
V_66 = F_55 ( V_74 ) ;
if ( F_17 ( V_66 ) ) {
V_26 = F_18 ( V_66 ) ;
F_45 ( F_43 ( V_74 ) , V_76 ) ;
goto V_59;
}
if ( F_65 ( V_91 , & V_66 -> V_76 ) ||
F_65 ( V_97 , & V_66 -> V_76 ) ) {
F_47 ( V_66 ) ;
F_45 ( F_43 ( V_74 ) , V_76 ) ;
V_26 = - V_78 ;
goto V_59;
}
F_78 ( V_98 , & V_66 -> V_76 ) ;
F_47 ( V_66 ) ;
F_45 ( F_43 ( V_74 ) , V_76 ) ;
V_26 = F_79 ( V_74 ) ;
V_59:
return V_26 ? V_26 : V_87 ;
}
static T_2
F_80 ( struct V_66 * V_75 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_73 * V_74 = F_63 ( V_75 ) ;
struct V_72 * V_66 ;
int V_87 ;
V_66 = F_57 ( V_74 ) ;
if ( F_17 ( V_66 ) )
return F_18 ( V_66 ) ;
if ( ! V_66 -> V_99 )
V_87 = - V_69 ;
else if ( ! V_66 -> V_99 -> V_100 )
V_87 = - V_101 ;
else
V_87 = V_66 -> V_99 -> V_100 ( V_66 ) ;
F_47 ( V_66 ) ;
if ( V_87 < 0 )
return V_87 ;
return sprintf ( V_85 , L_34 , V_87 ) ;
}
static T_2
F_81 ( struct V_66 * V_75 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_72 * V_66 ;
T_2 V_25 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
goto V_59;
else if ( ! V_66 -> V_99 ) {
F_47 ( V_66 ) ;
goto V_59;
} else {
V_25 = snprintf ( V_85 , V_41 , L_35 ,
V_66 -> V_99 -> V_102 ) ;
F_47 ( V_66 ) ;
return V_25 ;
}
V_59:
V_25 = snprintf ( V_85 , V_41 , L_36 ) ;
return V_25 ;
}
static T_2
F_82 ( struct V_66 * V_75 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_72 * V_66 ;
T_2 V_25 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( ! F_17 ( V_66 ) ) {
switch ( V_66 -> V_103 ) {
case V_104 :
V_25 = snprintf ( V_85 , V_41 , L_37 ) ;
break;
case V_105 :
V_25 = snprintf ( V_85 , V_41 , L_38 ) ;
break;
case V_106 :
V_25 = snprintf ( V_85 , V_41 , L_39 ) ;
break;
case V_107 :
V_25 = snprintf ( V_85 , V_41 , L_40 ) ;
break;
case V_108 :
V_25 = snprintf ( V_85 , V_41 , L_41 ) ;
break;
case V_109 :
V_25 = snprintf ( V_85 , V_41 , L_42 ) ;
break;
default:
V_25 = snprintf ( V_85 , V_41 , L_43 ) ;
break;
}
F_47 ( V_66 ) ;
} else
V_25 = snprintf ( V_85 , V_41 , L_44 ) ;
return V_25 ;
}
static T_2 F_83 ( struct V_66 * V_75 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_72 * V_66 ;
struct V_110 V_111 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return sprintf ( V_85 , L_33 ) ;
if ( V_66 -> V_99 && V_66 -> V_99 -> V_112 &&
! V_66 -> V_99 -> V_112 ( V_66 , & V_111 ) ) {
if ( V_111 . type == V_113 ||
V_111 . type == V_114 ) {
F_47 ( V_66 ) ;
return sprintf ( V_85 , L_32 ) ;
}
}
F_47 ( V_66 ) ;
return sprintf ( V_85 , L_33 ) ;
}
static T_2 F_84 ( struct V_66 * V_75 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_72 * V_66 ;
struct V_110 V_111 ;
char * V_115 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
V_115 = L_45 ;
if ( F_17 ( V_66 ) )
return snprintf ( V_85 , V_41 , L_35 , V_115 ) ;
if ( V_66 -> V_99 && V_66 -> V_99 -> V_112 &&
! V_66 -> V_99 -> V_112 ( V_66 , & V_111 ) )
V_115 = V_111 . V_115 ;
F_47 ( V_66 ) ;
return snprintf ( V_85 , V_41 , L_35 , V_115 ) ;
}
static T_2
F_85 ( struct V_66 * V_75 , struct V_83 * V_84 , char * V_85 )
{
struct V_72 * V_66 ;
struct V_110 V_111 ;
char V_116 [ V_117 ] ;
char V_118 [ 3 ] ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
V_116 [ 0 ] = 0 ;
if ( F_17 ( V_66 ) )
return snprintf ( V_85 , V_41 , L_35 , V_116 ) ;
if ( V_66 -> V_99 && V_66 -> V_99 -> V_112 &&
! V_66 -> V_99 -> V_112 ( V_66 , & V_111 ) ) {
switch ( V_111 . type ) {
case V_119 :
snprintf ( V_118 , sizeof( V_118 ) , L_46 ,
V_111 . V_120 ) ;
break;
case V_113 :
snprintf ( V_118 , sizeof( V_118 ) , L_46 ,
V_111 . V_121 ) ;
break;
case V_114 :
snprintf ( V_118 , sizeof( V_118 ) , L_47 ) ;
break;
default:
snprintf ( V_118 , sizeof( V_118 ) , L_46 ,
V_111 . V_120 ) ;
break;
}
if ( strlen ( V_111 . V_122 ) > 0 )
snprintf ( V_116 , sizeof( V_116 ) ,
L_48 ,
V_111 . V_115 , V_111 . V_123 , V_111 . V_23 , V_118 ,
V_111 . V_122 ) ;
else
snprintf ( V_116 , sizeof( V_116 ) ,
L_49 ,
V_111 . V_115 , V_111 . V_123 , V_111 . V_23 , V_118 ) ;
}
F_47 ( V_66 ) ;
return snprintf ( V_85 , V_41 , L_35 , V_116 ) ;
}
static T_2
F_86 ( struct V_66 * V_75 , struct V_83 * V_84 , char * V_85 )
{
struct V_49 * V_50 ;
int V_124 ;
V_50 = F_27 ( F_36 ( V_75 ) ) ;
if ( ! F_17 ( V_50 ) && V_50 -> V_66 )
V_124 = F_87 ( V_50 -> V_66 ) ;
else
V_124 = 0 ;
return snprintf ( V_85 , V_41 , V_124 ? L_32 : L_33 ) ;
}
static T_2
F_88 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_72 * V_66 ;
unsigned int V_14 ;
int V_26 = 0 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return F_18 ( V_66 ) ;
if ( F_6 ( V_85 , 0 , & V_14 ) || V_14 > 1 )
return - V_19 ;
if ( V_14 )
V_26 = F_89 ( V_66 ) ;
else
F_90 ( V_66 ) ;
F_47 ( V_66 ) ;
return V_26 ? : V_87 ;
}
static T_2
F_91 ( struct V_66 * V_75 , struct V_83 * V_84 , char * V_85 )
{
struct V_72 * V_66 ;
int V_25 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return - V_69 ;
V_25 = snprintf ( V_85 , V_41 , L_50 , V_66 -> V_125 ) ;
F_47 ( V_66 ) ;
return V_25 ;
}
static T_2
F_92 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_72 * V_66 ;
unsigned long V_14 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return - V_69 ;
if ( ( F_76 ( V_85 , 10 , & V_14 ) != 0 ) ||
( V_14 > V_126 ) || V_14 == 0 ) {
F_47 ( V_66 ) ;
return - V_19 ;
}
if ( V_14 )
V_66 -> V_125 = V_14 ;
F_47 ( V_66 ) ;
return V_87 ;
}
static T_2
F_93 ( struct V_66 * V_75 , struct V_83 * V_84 , char * V_85 )
{
struct V_72 * V_66 ;
int V_25 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return - V_69 ;
V_25 = snprintf ( V_85 , V_41 , L_50 , V_66 -> V_127 ) ;
F_47 ( V_66 ) ;
return V_25 ;
}
static T_2
F_94 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_72 * V_66 ;
unsigned long V_14 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return - V_69 ;
if ( ( F_76 ( V_85 , 10 , & V_14 ) != 0 ) ||
( V_14 > V_128 ) ) {
F_47 ( V_66 ) ;
return - V_19 ;
}
if ( V_14 )
V_66 -> V_127 = V_14 ;
F_47 ( V_66 ) ;
return V_87 ;
}
static T_2
F_95 ( struct V_66 * V_75 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_72 * V_66 ;
int V_25 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return - V_69 ;
V_25 = snprintf ( V_85 , V_41 , L_50 , V_66 -> V_129 ) ;
F_47 ( V_66 ) ;
return V_25 ;
}
static T_2
F_96 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_72 * V_66 ;
struct V_130 * V_131 ;
unsigned long V_14 , V_76 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) || ! V_66 -> V_90 )
return - V_69 ;
if ( ( F_76 ( V_85 , 10 , & V_14 ) != 0 ) ||
V_14 > V_132 / V_133 ) {
F_47 ( V_66 ) ;
return - V_19 ;
}
V_131 = V_66 -> V_90 -> V_130 ;
if ( ! V_131 ) {
F_47 ( V_66 ) ;
return - V_69 ;
}
F_42 ( & V_66 -> V_90 -> V_134 , V_76 ) ;
if ( ! V_14 )
F_97 ( V_131 , NULL ) ;
else
F_97 ( V_131 , V_135 ) ;
V_66 -> V_129 = V_14 ;
F_98 ( V_131 , V_66 -> V_129 * V_133 ) ;
F_45 ( & V_66 -> V_90 -> V_134 , V_76 ) ;
F_47 ( V_66 ) ;
return V_87 ;
}
static T_2
F_99 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_72 * V_66 ;
unsigned int V_14 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return - V_69 ;
if ( ( F_6 ( V_85 , 16 , & V_14 ) != 0 ) || V_14 > 0xff )
V_14 = 0 ;
if ( V_66 -> V_99 && V_66 -> V_99 -> V_136 )
V_66 -> V_99 -> V_136 ( V_66 , ( V_137 ) V_14 ) ;
F_47 ( V_66 ) ;
return V_87 ;
}
static T_2 F_100 ( struct V_66 * V_75 , struct V_83 * V_84 ,
char * V_85 )
{
struct V_72 * V_66 ;
int V_138 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return - V_69 ;
if ( ! V_66 -> V_99 || ! V_66 -> V_99 -> V_139 ) {
F_47 ( V_66 ) ;
return snprintf ( V_85 , V_41 , L_34 , V_39 ) ;
}
V_138 = V_66 -> V_99 -> V_139 ( V_66 ) ;
F_47 ( V_66 ) ;
return snprintf ( V_85 , V_41 , L_34 , V_138 ) ;
}
static T_2 F_101 ( struct V_66 * V_75 ,
struct V_83 * V_84 ,
char * V_85 )
{
struct V_49 * V_50 ;
int V_26 = 0 ;
V_50 = F_27 ( F_36 ( V_75 ) ) ;
if ( F_17 ( V_50 ) ) {
V_26 = snprintf ( V_85 , V_41 , L_51 ) ;
} else {
F_23 ( & V_63 ) ;
if ( V_50 -> V_24 & V_140 )
V_26 = snprintf ( V_85 , V_41 , L_52 ) ;
else
V_26 = snprintf ( V_85 , V_41 , L_51 ) ;
F_26 ( & V_63 ) ;
}
return V_26 ;
}
static T_2 F_102 ( struct V_66 * V_75 ,
struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_73 * V_74 = F_63 ( V_75 ) ;
int V_26 ;
if ( F_103 ( L_53 , V_85 ) )
V_26 = F_62 ( V_74 , V_140 , 0 ) ;
else if ( F_103 ( L_54 , V_85 ) )
V_26 = F_62 ( V_74 , V_140 , 1 ) ;
else
V_26 = - V_19 ;
return V_26 ? : V_87 ;
}
static T_2 F_104 ( struct V_66 * V_75 ,
struct V_83 * V_84 ,
char * V_85 )
{
struct V_72 * V_66 ;
int V_26 = 0 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return snprintf ( V_85 , V_41 , L_36 ) ;
if ( F_65 ( V_141 , & V_66 -> V_76 ) )
V_26 = snprintf ( V_85 , V_41 , L_55 ) ;
else if ( F_65 ( V_142 , & V_66 -> V_76 ) )
V_26 = snprintf ( V_85 , V_41 , L_56 ) ;
else
V_26 = snprintf ( V_85 , V_41 , L_36 ) ;
F_47 ( V_66 ) ;
return V_26 ;
}
static T_2 F_105 ( struct V_66 * V_75 ,
struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_72 * V_66 ;
int V_26 = 0 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return - V_69 ;
if ( F_103 ( L_57 , V_85 ) )
F_106 ( V_142 , & V_66 -> V_76 ) ;
else
V_26 = - V_19 ;
F_47 ( V_66 ) ;
if ( V_26 )
return V_26 ;
else
return V_87 ;
}
static T_2 F_107 ( struct V_66 * V_75 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_72 * V_66 ;
T_4 V_143 , V_144 , V_145 , V_146 , V_147 , V_148 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return sprintf ( V_85 , L_33 ) ;
V_143 = F_108 ( V_66 ) ;
V_144 = F_109 ( V_66 ) ;
V_145 = F_110 ( V_66 ) ;
V_146 = F_111 ( V_66 ) ;
V_147 = F_112 ( V_66 ) ;
V_148 = F_113 ( V_66 ) ;
F_47 ( V_66 ) ;
return sprintf ( V_85 , L_58 , V_143 , V_144 ,
V_145 , V_146 , V_147 , V_148 ) ;
}
static T_2
F_114 ( struct V_66 * V_75 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_72 * V_66 ;
int V_25 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return - V_69 ;
V_25 = snprintf ( V_85 , V_41 , L_50 , V_66 -> V_149 ) ;
F_47 ( V_66 ) ;
return V_25 ;
}
static T_2
F_115 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_72 * V_66 ;
unsigned long V_76 ;
unsigned long V_14 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return - V_69 ;
if ( F_76 ( V_85 , 10 , & V_14 ) != 0 || V_14 > V_150 ) {
F_47 ( V_66 ) ;
return - V_19 ;
}
F_42 ( F_43 ( F_63 ( V_75 ) ) , V_76 ) ;
V_66 -> V_149 = V_14 ;
F_45 ( F_43 ( F_63 ( V_75 ) ) , V_76 ) ;
F_47 ( V_66 ) ;
return V_87 ;
}
static T_2
F_116 ( struct V_66 * V_75 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_72 * V_66 ;
int V_25 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return - V_69 ;
V_25 = snprintf ( V_85 , V_41 , L_50 , V_66 -> V_151 ) ;
F_47 ( V_66 ) ;
return V_25 ;
}
static T_2
F_117 ( struct V_66 * V_75 , struct V_83 * V_84 ,
const char * V_85 , T_3 V_87 )
{
struct V_72 * V_66 ;
unsigned long V_76 ;
unsigned long V_14 ;
V_66 = F_57 ( F_63 ( V_75 ) ) ;
if ( F_17 ( V_66 ) )
return - V_69 ;
if ( ( F_76 ( V_85 , 10 , & V_14 ) != 0 ) ||
( V_14 > V_152 ) || V_14 == 0 ) {
F_47 ( V_66 ) ;
return - V_19 ;
}
F_42 ( F_43 ( F_63 ( V_75 ) ) , V_76 ) ;
if ( V_14 )
V_66 -> V_151 = V_14 ;
F_45 ( F_43 ( F_63 ( V_75 ) ) , V_76 ) ;
F_47 ( V_66 ) ;
return V_87 ;
}
int
F_118 ( struct V_73 * V_74 , int V_153 )
{
struct V_49 * V_50 ;
V_50 = F_27 ( F_36 ( & V_74 -> V_75 ) ) ;
if ( F_17 ( V_50 ) )
return F_18 ( V_50 ) ;
return ( ( V_50 -> V_24 & V_153 ) != 0 ) ;
}
int
F_62 ( struct V_73 * V_74 , int V_153 , int V_154 )
{
struct V_49 * V_50 ;
V_50 = F_35 ( V_74 ) ;
if ( F_17 ( V_50 ) )
return F_18 ( V_50 ) ;
F_23 ( & V_63 ) ;
if ( V_154 )
V_50 -> V_24 |= V_153 ;
else
V_50 -> V_24 &= ~ V_153 ;
if ( V_50 -> V_66 )
V_50 -> V_66 -> V_24 = V_50 -> V_24 ;
F_26 ( & V_63 ) ;
return 0 ;
}
int
F_119 ( struct V_73 * V_74 )
{
return F_120 ( & V_74 -> V_75 . V_155 , & V_156 ) ;
}
void
F_121 ( struct V_73 * V_74 )
{
F_122 ( & V_74 -> V_75 . V_155 , & V_156 ) ;
}
int
F_123 ( void )
{
int V_3 ;
V_65 = 0 ;
for ( V_3 = 0 ; V_3 < 256 ; V_3 ++ )
F_124 ( & V_68 [ V_3 ] ) ;
return 0 ;
}
void
F_125 ( void )
{
F_29 () ;
}
