static char * F_1 ( char * V_1 , ... )
{
char * * V_2 , * V_3 ;
T_1 V_4 ;
va_start ( V_4 , V_1 ) ;
while ( ( V_2 = va_arg ( V_4 , char * * ) ) != NULL ) {
if ( * V_1 == '\0' ) {
va_end ( V_4 ) ;
return NULL ;
}
V_3 = strchr ( V_1 , ',' ) ;
if ( V_3 != V_1 )
* V_2 = V_1 ;
if ( V_3 == NULL ) {
va_end ( V_4 ) ;
return NULL ;
}
* V_3 ++ = '\0' ;
V_1 = V_3 ;
}
va_end ( V_4 ) ;
return V_1 ;
}
static void F_2 ( struct V_5 * V_6 , char * V_1 )
{
unsigned char * V_7 = V_6 -> V_8 ;
if ( V_1 == NULL )
goto V_9;
if ( ! F_3 ( V_1 , V_7 ) ) {
F_4 ( L_1 ,
V_6 -> V_10 , V_1 ) ;
goto V_9;
}
if ( F_5 ( V_7 ) ) {
F_4 ( L_2 ,
V_6 -> V_10 ) ;
goto V_9;
}
if ( ! F_6 ( V_7 ) ) {
F_4 ( L_3 ,
V_6 -> V_10 ) ;
goto V_9;
}
if ( ! F_7 ( V_7 ) )
F_8 ( L_4 ,
V_6 -> V_10 ) ;
return;
V_9:
F_9 ( L_5 ,
V_6 -> V_10 ) ;
F_10 ( V_6 ) ;
}
static int F_11 ( struct V_11 * V_12 )
{
struct V_13 V_14 ;
char * V_15 = V_12 -> V_16 . V_17 . V_18 . V_15 ;
int V_19 = - V_20 ;
int V_21 ;
V_21 = F_12 ( L_6 , 02 , 0 ) ;
if ( V_21 < 0 ) {
F_4 ( L_7 ,
V_12 -> V_6 -> V_10 , V_21 , V_22 ) ;
return V_21 ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_23 = V_24 | V_25 ;
F_13 ( V_14 . V_26 , V_15 , sizeof( V_14 . V_26 ) ) ;
V_19 = F_14 ( V_21 , V_27 , & V_14 ) ;
if ( V_19 < 0 ) {
F_4 ( L_8 ,
V_12 -> V_6 -> V_10 , V_15 , V_19 , V_22 ) ;
F_15 ( V_21 ) ;
return V_19 ;
}
V_12 -> V_16 . V_17 . V_18 . V_21 = V_21 ;
return V_19 ;
}
static void F_16 ( struct V_11 * V_12 )
{
F_15 ( V_12 -> V_16 . V_17 . V_18 . V_21 ) ;
V_12 -> V_16 . V_17 . V_18 . V_21 = - 1 ;
}
static int F_17 ( struct V_11 * V_12 , struct V_28 * * V_29 )
{
return F_18 ( V_12 -> V_16 . V_17 . V_18 . V_21 ,
( * V_29 ) -> V_30 , ( * V_29 ) -> V_6 -> V_31 + V_32 ) ;
}
static int F_19 ( struct V_11 * V_12 , struct V_28 * * V_29 )
{
return F_20 ( V_12 -> V_16 . V_17 . V_18 . V_21 , ( * V_29 ) -> V_30 , ( * V_29 ) -> V_33 ) ;
}
unsigned short F_21 ( struct V_28 * V_29 )
{
return F_22 ( V_29 , V_29 -> V_6 ) ;
}
static int F_23 ( struct V_11 * V_12 )
{
return F_24 ( V_12 -> V_16 . V_17 . V_18 . V_21 ) ;
}
static int F_25 ( struct V_11 * V_12 , int V_34 , char * V_35 )
{
struct V_5 * V_6 = V_12 -> V_6 ;
char * V_15 = NULL , * V_36 = NULL , * V_37 = NULL ;
if ( strncmp ( V_35 , V_38 ,
sizeof( V_38 ) - 1 ) )
return 0 ;
V_35 += sizeof( V_38 ) - 1 ;
if ( * V_35 == ',' ) {
V_37 = F_1 ( V_35 + 1 , & V_36 , & V_15 ) ;
if ( V_37 != NULL ) {
F_4 ( L_9 ,
V_6 -> V_10 , V_37 ) ;
return 0 ;
}
} else if ( * V_35 != '\0' ) {
F_4 ( L_10 ,
V_6 -> V_10 , V_35 ) ;
return 0 ;
}
if ( ! V_15 ) {
F_4 ( L_11 , V_6 -> V_10 ) ;
return 0 ;
}
F_13 ( V_12 -> V_16 . V_17 . V_18 . V_15 , V_15 ,
sizeof( V_12 -> V_16 . V_17 . V_18 . V_15 ) ) ;
F_2 ( V_6 , V_36 ) ;
V_12 -> V_31 = V_39 ;
V_12 -> V_16 . V_17 . V_18 . V_21 = - 1 ;
V_12 -> V_16 . V_40 = F_11 ;
V_12 -> V_16 . V_41 = F_16 ;
V_12 -> V_16 . V_42 = F_17 ;
V_12 -> V_16 . V_43 = F_19 ;
V_12 -> V_16 . V_44 = F_21 ;
V_12 -> V_16 . V_45 = F_23 ;
return 1 ;
}
static int F_26 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_27 ( V_6 ) ;
int V_46 ;
struct V_28 * V_29 ;
if ( V_12 -> V_16 . V_45 ( V_12 ) == 0 )
return 0 ;
V_29 = F_28 ( V_6 -> V_31 + 2 + V_32 ) ;
if ( V_29 == NULL ) {
V_12 -> V_47 . V_48 ++ ;
return 0 ;
}
F_29 ( V_29 , 2 ) ;
V_29 -> V_6 = V_6 ;
F_30 ( V_29 ) ;
V_46 = V_12 -> V_16 . V_42 ( V_12 , & V_29 ) ;
F_31 ( V_29 , V_46 ) ;
if ( V_46 > 0 ) {
F_32 ( V_29 , V_46 ) ;
V_29 -> V_44 = V_12 -> V_16 . V_44 ( V_29 ) ;
V_12 -> V_47 . V_49 += V_29 -> V_33 ;
V_12 -> V_47 . V_50 ++ ;
F_33 ( V_29 ) ;
return V_46 ;
}
F_34 ( V_29 ) ;
return V_46 ;
}
static int F_35 ( void )
{
struct V_51 * V_52 ;
int V_19 , V_53 = 0 ;
F_36 ( & V_54 ) ;
F_37 (ele, &opened) {
struct V_11 * V_12 ;
V_12 = F_38 ( V_52 , struct V_11 , V_55 ) ;
if ( ! F_39 ( V_12 -> V_6 ) )
break;
F_36 ( & V_12 -> V_56 ) ;
while ( ( V_19 = F_26 ( V_12 -> V_6 ) ) > 0 )
V_53 ++ ;
F_40 ( & V_12 -> V_56 ) ;
if ( V_19 < 0 ) {
F_4 ( L_12 ,
V_12 -> V_6 -> V_10 , V_19 ) ;
F_41 ( V_12 -> V_6 ) ;
} else {
}
}
F_40 ( & V_54 ) ;
return V_53 ;
}
static void F_42 ( unsigned long V_57 )
{
struct V_11 * V_12 = (struct V_11 * ) V_57 ;
F_35 () ;
F_36 ( & V_12 -> V_56 ) ;
F_43 ( & V_12 -> V_58 , V_59 + V_12 -> V_60 ) ;
F_40 ( & V_12 -> V_56 ) ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_27 ( V_6 ) ;
int V_19 ;
F_45 ( & V_12 -> V_56 ) ;
V_19 = V_12 -> V_16 . V_40 ( V_12 ) ;
if ( V_19 < 0 )
goto V_61;
F_46 ( V_6 ) ;
while ( ( V_19 = F_26 ( V_6 ) ) > 0 )
;
F_47 ( & V_12 -> V_56 ) ;
F_45 ( & V_54 ) ;
F_48 ( & V_12 -> V_55 , & V_62 ) ;
F_47 ( & V_54 ) ;
F_45 ( & V_12 -> V_56 ) ;
F_49 ( & V_12 -> V_58 ) ;
V_12 -> V_60 = V_63 ;
V_12 -> V_58 . V_30 = ( unsigned long ) V_12 ;
V_12 -> V_58 . V_64 = F_42 ;
F_43 ( & V_12 -> V_58 , V_59 + V_12 -> V_60 ) ;
V_61:
F_47 ( & V_12 -> V_56 ) ;
return V_19 ;
}
static int F_50 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_27 ( V_6 ) ;
F_51 ( V_6 ) ;
F_45 ( & V_12 -> V_56 ) ;
F_36 ( & V_54 ) ;
F_52 ( & V_62 ) ;
F_40 ( & V_54 ) ;
F_53 ( & V_12 -> V_58 ) ;
V_12 -> V_16 . V_41 ( V_12 ) ;
F_47 ( & V_12 -> V_56 ) ;
return 0 ;
}
static int F_54 ( struct V_28 * V_29 , struct V_5 * V_6 )
{
struct V_11 * V_12 = F_27 ( V_6 ) ;
int V_33 ;
F_51 ( V_6 ) ;
F_45 ( & V_12 -> V_56 ) ;
V_33 = V_12 -> V_16 . V_43 ( V_12 , & V_29 ) ;
if ( V_33 == V_29 -> V_33 ) {
V_12 -> V_47 . V_65 ++ ;
V_12 -> V_47 . V_66 += V_29 -> V_33 ;
F_55 ( V_6 ) ;
F_46 ( V_6 ) ;
F_56 ( V_6 ) ;
} else if ( V_33 == 0 ) {
F_46 ( V_6 ) ;
V_12 -> V_47 . V_67 ++ ;
} else {
F_46 ( V_6 ) ;
F_4 ( L_13 , V_6 -> V_10 , V_68 , V_33 ) ;
}
F_47 ( & V_12 -> V_56 ) ;
F_57 ( V_29 ) ;
return V_69 ;
}
static struct V_70 * F_58 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_27 ( V_6 ) ;
return & V_12 -> V_47 ;
}
static void F_59 ( struct V_5 * V_6 )
{
}
static void F_60 ( struct V_5 * V_6 )
{
}
static int F_61 ( struct V_5 * V_6 , void * V_7 )
{
struct V_11 * V_12 = F_27 ( V_6 ) ;
struct V_71 * V_72 = V_7 ;
if ( ! F_6 ( V_72 -> V_73 ) )
return - V_74 ;
F_45 ( & V_12 -> V_56 ) ;
memcpy ( V_6 -> V_8 , V_72 -> V_73 , V_75 ) ;
F_47 ( & V_12 -> V_56 ) ;
return 0 ;
}
static int F_62 ( struct V_5 * V_6 , int V_76 )
{
return - V_20 ;
}
void F_63 ( unsigned long V_77 )
{
}
static int F_64 ( int V_34 , char * V_35 )
{
struct V_5 * V_6 ;
struct V_11 * V_12 ;
int V_19 ;
V_6 = F_65 ( sizeof( * V_12 ) ) ;
if ( V_6 == NULL ) {
F_4 ( L_14 ) ;
return 1 ;
}
V_12 = F_27 ( V_6 ) ;
* V_12 = (struct V_11 ) {
. V_78 = F_66 ( V_12 -> V_78 ) ,
. V_55 = F_66 ( V_12 -> V_55 ) ,
. V_6 = V_6 ,
. V_34 = V_34 ,
} ;
F_67 ( & V_12 -> V_56 ) ;
snprintf ( V_6 -> V_10 , sizeof( V_6 -> V_10 ) , L_15 , V_34 ) ;
if ( ! F_25 ( V_12 , V_34 , V_35 ) ) {
F_4 ( L_16 ,
V_6 -> V_10 ) ;
goto V_79;
}
F_9 ( L_17 , V_34 , V_6 -> V_8 ) ;
if ( ! V_80 ) {
F_68 ( & V_81 ) ;
V_80 = 1 ;
}
F_36 ( & V_82 ) ;
F_48 ( & V_12 -> V_78 , & V_83 ) ;
F_40 ( & V_82 ) ;
V_12 -> V_84 . V_85 = V_34 ;
V_12 -> V_84 . V_10 = V_86 ;
F_69 ( & V_12 -> V_84 ) ;
F_70 ( V_6 , & V_12 -> V_84 . V_6 ) ;
V_6 -> V_87 = & V_88 ;
V_6 -> V_31 = V_12 -> V_31 ;
V_6 -> V_89 = ( V_90 >> 1 ) ;
V_6 -> V_91 = - 1 ;
F_71 () ;
V_19 = F_72 ( V_6 ) ;
F_73 () ;
if ( V_19 ) {
F_4 ( L_18 , V_6 -> V_10 ) ;
F_74 ( V_6 ) ;
return 1 ;
}
F_49 ( & V_12 -> V_92 ) ;
V_12 -> V_92 . V_64 = F_63 ;
return 0 ;
V_79:
return - V_93 ;
}
static int T_2 F_75 ( char * V_1 )
{
struct V_11 * V_94 = NULL ;
struct V_95 * V_96 ;
struct V_51 * V_52 ;
char * V_3 ;
int V_97 ;
unsigned V_98 ;
V_3 = strchr ( V_1 , '=' ) ;
if ( ! V_3 ) {
F_76 ( V_99 L_19 ) ;
return 1 ;
}
* V_3 = 0 ;
V_97 = F_77 ( V_1 , 0 , & V_98 ) ;
* V_3 = '=' ;
if ( V_97 < 0 ) {
F_76 ( V_99 L_20 , V_1 ) ;
return 1 ;
}
V_1 = V_3 ;
F_36 ( & V_82 ) ;
F_37 (ele, &devices) {
V_94 = F_38 ( V_52 , struct V_11 , V_78 ) ;
if ( V_94 -> V_34 == V_98 )
break;
}
F_40 ( & V_82 ) ;
if ( V_94 && V_94 -> V_34 == V_98 ) {
F_76 ( V_99 L_21 , V_98 ) ;
return 1 ;
}
V_96 = F_78 ( sizeof( * V_96 ) ) ;
if ( V_96 == NULL ) {
F_76 ( V_99 L_22 ) ;
return 1 ;
}
F_79 ( & V_96 -> V_100 ) ;
V_96 -> V_34 = V_98 ;
V_96 -> V_35 = V_1 + 1 ;
F_80 ( & V_96 -> V_100 , & V_101 ) ;
return 1 ;
}
static int V_95 ( void )
{
struct V_51 * V_52 , * V_102 ;
F_81 (ele, next, &eth_cmd_line) {
struct V_95 * V_103 ;
V_103 = F_38 ( V_52 , struct V_95 , V_100 ) ;
F_64 ( V_103 -> V_34 , V_103 -> V_35 ) ;
}
return 1 ;
}
