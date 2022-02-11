static int F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_3 , 0 , V_4 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_1 ,
F_5 ( V_2 ) ) ;
return F_5 ( V_2 ) ;
}
V_5 = F_6 ( V_2 ) ;
V_6 = F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_9 ( const char * V_7 , const char * V_8 )
{
if ( ! memcmp ( V_7 , V_9 , V_10 ) ) {
if ( strlen ( V_7 ) == V_10 )
goto V_11;
if ( V_8 )
if ( memcmp ( V_7 , V_8 , V_10 ) )
goto V_11;
} else if ( ! memcmp ( V_7 , V_12 , V_13 ) ) {
if ( strlen ( V_7 ) == V_13 )
goto V_11;
if ( V_8 )
if ( memcmp ( V_7 , V_8 , V_13 ) )
goto V_11;
} else
goto V_11;
return 0 ;
V_11:
return - V_14 ;
}
static int F_10 ( char * V_15 , char * * V_16 ,
char * * V_17 , char * * V_18 )
{
T_1 args [ V_19 ] ;
int V_20 = - V_14 ;
int V_21 ;
char * V_22 ;
V_22 = F_11 ( & V_15 , L_2 ) ;
if ( ! V_22 )
return V_20 ;
V_21 = F_12 ( V_22 , V_23 , args ) ;
* V_16 = F_11 ( & V_15 , L_2 ) ;
if ( ! * V_16 )
goto V_11;
if ( F_9 ( * V_16 , NULL ) < 0 )
goto V_11;
if ( V_17 ) {
* V_17 = F_11 ( & V_15 , L_2 ) ;
if ( ! * V_17 )
goto V_11;
}
switch ( V_21 ) {
case V_24 :
if ( ! V_17 )
break;
V_20 = 0 ;
break;
case V_25 :
if ( ! V_17 )
break;
* V_18 = F_11 ( & V_15 , L_2 ) ;
if ( ! * V_18 )
break;
V_20 = 0 ;
break;
case V_26 :
if ( V_17 )
break;
V_20 = 0 ;
break;
case V_27 :
break;
}
V_11:
return V_20 ;
}
static char * F_13 ( struct V_28 * V_29 ,
T_2 V_30 )
{
char * V_31 , * V_32 ;
T_3 * V_33 = V_29 -> V_33 ;
int V_34 ;
int V_35 ;
V_31 = F_14 ( V_30 + 1 , V_36 ) ;
if ( ! V_31 )
goto V_11;
V_31 [ V_30 ] = '\0' ;
V_34 = sprintf ( V_31 , L_3 , V_29 -> V_16 ,
V_29 -> V_37 ) ;
V_32 = & V_31 [ V_34 ] ;
for ( V_35 = 0 ; V_35 < ( V_30 - V_34 ) / 2 ; V_35 ++ )
V_32 = F_15 ( V_32 , V_33 [ V_35 ] ) ;
V_11:
return V_31 ;
}
static struct V_38 * F_16 ( const char * V_39 ,
T_3 * * V_40 , T_2 * V_41 )
{
struct V_42 * V_43 ;
struct V_38 * V_44 ;
V_44 = F_17 ( & V_45 , V_39 , NULL ) ;
if ( F_3 ( V_44 ) )
goto error;
F_18 ( & V_44 -> V_46 ) ;
V_43 = F_19 ( V_44 -> V_47 . V_48 ) ;
* V_40 = V_43 -> V_38 ;
* V_41 = V_43 -> V_49 ;
error:
return V_44 ;
}
static struct V_38 * F_20 ( const char * V_16 , T_3 * * V_40 ,
T_2 * V_41 )
{
struct V_50 * V_51 ;
struct V_38 * V_52 ;
V_52 = F_17 ( & V_53 , V_16 , NULL ) ;
if ( F_3 ( V_52 ) )
goto error;
F_18 ( & V_52 -> V_46 ) ;
V_51 = F_19 ( V_52 -> V_47 . V_48 ) ;
* V_40 = V_51 -> V_48 ;
* V_41 = V_51 -> V_37 ;
error:
return V_52 ;
}
static struct V_54 * F_21 ( struct V_55 * V_56 )
{
struct V_54 * V_54 ;
int V_57 ;
V_57 = sizeof( struct V_58 ) + F_22 ( V_56 ) ;
V_54 = F_14 ( V_57 , V_36 ) ;
if ( ! V_54 )
return F_23 ( - V_59 ) ;
V_54 -> V_60 . V_2 = V_56 ;
V_54 -> V_60 . V_61 = 0x0 ;
return V_54 ;
}
static int F_24 ( T_3 * V_62 , const T_3 * V_38 , unsigned int V_63 ,
const T_3 * V_64 , unsigned int V_65 )
{
struct V_54 * V_54 ;
int V_20 ;
V_54 = F_21 ( V_66 ) ;
if ( F_3 ( V_54 ) ) {
F_25 ( L_4 , V_67 ) ;
return F_5 ( V_54 ) ;
}
V_20 = F_26 ( V_66 , V_38 , V_63 ) ;
if ( ! V_20 )
V_20 = F_27 ( & V_54 -> V_60 , V_64 , V_65 , V_62 ) ;
F_28 ( V_54 ) ;
return V_20 ;
}
static int F_29 ( T_3 * V_62 , const T_3 * V_64 , unsigned int V_65 )
{
struct V_54 * V_54 ;
int V_20 ;
V_54 = F_21 ( V_68 ) ;
if ( F_3 ( V_54 ) ) {
F_25 ( L_4 , V_69 ) ;
return F_5 ( V_54 ) ;
}
V_20 = F_27 ( & V_54 -> V_60 , V_64 , V_65 , V_62 ) ;
F_28 ( V_54 ) ;
return V_20 ;
}
static int F_30 ( T_3 * V_70 , enum V_71 V_72 ,
const T_3 * V_40 , T_2 V_41 )
{
T_3 * V_73 ;
unsigned int V_74 ;
int V_20 ;
V_74 = strlen ( L_5 ) + 1 + V_41 ;
if ( V_74 < V_75 )
V_74 = V_75 ;
V_73 = F_31 ( V_74 , V_36 ) ;
if ( ! V_73 ) {
F_4 ( L_6 ) ;
return - V_59 ;
}
if ( V_72 )
strcpy ( V_73 , L_5 ) ;
else
strcpy ( V_73 , L_7 ) ;
memcpy ( V_73 + strlen ( V_73 ) + 1 , V_40 ,
V_41 ) ;
V_20 = F_29 ( V_70 , V_73 , V_74 ) ;
F_28 ( V_73 ) ;
return V_20 ;
}
static int F_32 ( struct V_76 * V_77 , const T_3 * V_38 ,
unsigned int V_49 , const T_3 * V_33 ,
unsigned int V_5 )
{
int V_20 ;
V_77 -> V_2 = F_2 ( V_3 , 0 , V_4 ) ;
if ( F_3 ( V_77 -> V_2 ) ) {
F_4 ( L_8 ,
V_3 , F_5 ( V_77 -> V_2 ) ) ;
return F_5 ( V_77 -> V_2 ) ;
}
V_77 -> V_61 = 0 ;
V_20 = F_33 ( V_77 -> V_2 , V_38 , V_49 ) ;
if ( V_20 < 0 ) {
F_4 ( L_9 , V_20 ) ;
F_8 ( V_77 -> V_2 ) ;
return V_20 ;
}
F_34 ( V_77 -> V_2 , V_33 , V_5 ) ;
return 0 ;
}
static struct V_38 * F_35 ( struct V_28 * V_29 ,
T_3 * * V_40 , T_2 * V_41 )
{
struct V_38 * V_78 = NULL ;
if ( ! strncmp ( V_29 -> V_16 , V_9 ,
V_10 ) ) {
V_78 = F_16 ( V_29 -> V_16 +
V_10 ,
V_40 , V_41 ) ;
} else if ( ! strncmp ( V_29 -> V_16 , V_12 ,
V_13 ) ) {
V_78 = F_20 ( V_29 -> V_16 +
V_13 ,
V_40 , V_41 ) ;
} else
goto V_11;
if ( F_3 ( V_78 ) )
F_25 ( L_10 ,
V_29 -> V_16 ) ;
if ( V_78 )
F_36 ( * V_40 , * V_41 ) ;
V_11:
return V_78 ;
}
static int F_37 ( struct V_28 * V_29 ,
const T_3 * V_70 ,
unsigned int V_79 )
{
struct V_80 V_81 [ 2 ] ;
struct V_80 V_82 [ 1 ] ;
struct V_76 V_77 ;
unsigned int V_83 ;
unsigned int V_84 ;
char V_85 [ 16 ] ;
int V_20 ;
V_83 = F_38 ( V_29 -> V_17 , V_6 ) ;
V_84 = V_83 - V_29 -> V_17 ;
V_20 = F_32 ( & V_77 , V_70 , V_79 ,
V_29 -> V_33 , V_5 ) ;
if ( V_20 < 0 )
goto V_11;
F_39 ( V_29 ) ;
memset ( V_85 , 0 , sizeof V_85 ) ;
F_40 ( V_81 , 2 ) ;
F_41 ( & V_81 [ 0 ] , V_29 -> V_86 ,
V_29 -> V_17 ) ;
F_41 ( & V_81 [ 1 ] , V_85 , V_84 ) ;
F_40 ( V_82 , 1 ) ;
F_41 ( V_82 , V_29 -> V_87 , V_83 ) ;
V_20 = F_42 ( & V_77 , V_82 , V_81 , V_83 ) ;
F_8 ( V_77 . V_2 ) ;
if ( V_20 < 0 )
F_4 ( L_11 , V_20 ) ;
else
F_43 ( V_29 , V_83 ) ;
V_11:
return V_20 ;
}
static int F_44 ( struct V_28 * V_29 ,
const T_3 * V_40 , T_2 V_41 )
{
T_3 V_70 [ V_75 ] ;
T_3 * V_62 ;
int V_20 ;
V_20 = F_30 ( V_70 , V_88 , V_40 , V_41 ) ;
if ( V_20 < 0 )
goto V_11;
V_62 = V_29 -> V_16 + V_29 -> V_89 ;
V_20 = F_24 ( V_62 , V_70 , sizeof V_70 ,
V_29 -> V_16 , V_29 -> V_89 ) ;
if ( ! V_20 )
F_45 ( NULL , V_62 , V_75 ) ;
V_11:
return V_20 ;
}
static int F_46 ( struct V_28 * V_29 ,
const T_3 * V_40 , T_2 V_41 )
{
T_3 V_70 [ V_75 ] ;
T_3 V_62 [ V_75 ] ;
int V_20 ;
V_20 = F_30 ( V_70 , V_88 , V_40 , V_41 ) ;
if ( V_20 < 0 )
goto V_11;
V_20 = F_24 ( V_62 , V_70 , sizeof V_70 ,
V_29 -> V_16 , V_29 -> V_89 ) ;
if ( V_20 < 0 )
goto V_11;
V_20 = memcmp ( V_62 , V_29 -> V_16 + V_29 -> V_89 ,
sizeof V_62 ) ;
if ( V_20 ) {
V_20 = - V_14 ;
F_45 ( L_12 ,
V_29 -> V_16 + V_29 -> V_89 ,
V_75 ) ;
F_45 ( L_13 , V_62 , V_75 ) ;
}
V_11:
return V_20 ;
}
static int F_47 ( struct V_28 * V_29 ,
const T_3 * V_70 ,
unsigned int V_79 )
{
struct V_80 V_81 [ 1 ] ;
struct V_80 V_82 [ 2 ] ;
struct V_76 V_77 ;
unsigned int V_83 ;
char V_85 [ 16 ] ;
int V_20 ;
V_83 = F_38 ( V_29 -> V_17 , V_6 ) ;
V_20 = F_32 ( & V_77 , V_70 , V_79 ,
V_29 -> V_33 , V_5 ) ;
if ( V_20 < 0 )
goto V_11;
F_43 ( V_29 , V_83 ) ;
memset ( V_85 , 0 , sizeof V_85 ) ;
F_40 ( V_81 , 1 ) ;
F_40 ( V_82 , 2 ) ;
F_41 ( V_81 , V_29 -> V_87 , V_83 ) ;
F_41 ( & V_82 [ 0 ] , V_29 -> V_86 ,
V_29 -> V_17 ) ;
F_41 ( & V_82 [ 1 ] , V_85 , sizeof V_85 ) ;
V_20 = F_48 ( & V_77 , V_82 , V_81 , V_83 ) ;
F_8 ( V_77 . V_2 ) ;
if ( V_20 < 0 )
goto V_11;
F_39 ( V_29 ) ;
V_11:
return V_20 ;
}
static struct V_28 * F_49 ( struct V_38 * V_38 ,
const char * V_16 ,
const char * V_37 )
{
struct V_28 * V_29 = NULL ;
unsigned short V_89 ;
unsigned short V_17 ;
unsigned int V_83 ;
long V_90 ;
int V_20 ;
V_20 = F_50 ( V_37 , 10 , & V_90 ) ;
if ( V_20 < 0 || V_90 < V_91 || V_90 > V_92 )
return F_23 ( - V_14 ) ;
V_17 = V_90 ;
V_83 = F_38 ( V_17 , V_6 ) ;
V_89 = strlen ( V_16 ) + 1 + strlen ( V_37 ) + 1
+ V_5 + 1 + V_83 ;
V_20 = F_51 ( V_38 , V_17 + V_89
+ V_75 + 1 ) ;
if ( V_20 < 0 )
return F_23 ( V_20 ) ;
V_29 = F_31 ( sizeof( * V_29 ) + V_17 +
V_89 + V_75 + 1 , V_36 ) ;
if ( ! V_29 )
return F_23 ( - V_59 ) ;
V_29 -> V_17 = V_17 ;
V_29 -> V_89 = V_89 ;
return V_29 ;
}
static int F_52 ( struct V_28 * V_29 ,
const char * V_18 )
{
struct V_38 * V_78 ;
T_3 V_70 [ V_75 ] ;
T_3 * V_40 ;
T_3 * V_93 ;
const char * V_94 ;
unsigned int V_83 ;
T_2 V_41 ;
T_2 V_95 ;
int V_20 ;
V_83 = F_38 ( V_29 -> V_17 , V_6 ) ;
V_95 = ( V_5 + 1 + V_83 + V_75 ) * 2 ;
if ( strlen ( V_18 ) != V_95 )
return - V_14 ;
V_94 = V_18 + ( 2 * V_5 ) + 2 ;
F_53 ( V_29 -> V_33 , V_18 , V_5 ) ;
F_53 ( V_29 -> V_87 , V_94 , V_83 ) ;
V_93 = V_29 -> V_16 + V_29 -> V_89 ;
F_53 ( V_93 , V_94 + ( V_83 * 2 ) , V_75 ) ;
V_78 = F_35 ( V_29 , & V_40 , & V_41 ) ;
if ( F_3 ( V_78 ) )
return F_5 ( V_78 ) ;
V_20 = F_46 ( V_29 , V_40 , V_41 ) ;
if ( V_20 < 0 ) {
F_4 ( L_14 , V_20 ) ;
goto V_11;
}
V_20 = F_30 ( V_70 , V_96 , V_40 , V_41 ) ;
if ( V_20 < 0 )
goto V_11;
V_20 = F_47 ( V_29 , V_70 , sizeof V_70 ) ;
if ( V_20 < 0 )
F_4 ( L_15 , V_20 ) ;
V_11:
F_54 ( & V_78 -> V_46 ) ;
F_55 ( V_78 ) ;
return V_20 ;
}
static void F_56 ( struct V_28 * V_29 ,
const char * V_16 , const char * V_37 )
{
V_29 -> V_16 = V_29 -> V_86
+ V_29 -> V_17 ;
V_29 -> V_37 = V_29 -> V_16 + strlen ( V_16 ) + 1 ;
V_29 -> V_33 = V_29 -> V_37 + strlen ( V_37 ) + 1 ;
V_29 -> V_87 = V_29 -> V_33 + V_5 + 1 ;
memcpy ( V_29 -> V_16 , V_16 , strlen ( V_16 ) ) ;
memcpy ( V_29 -> V_37 , V_37 , strlen ( V_37 ) ) ;
}
static int F_57 ( struct V_28 * V_29 ,
const char * V_16 , const char * V_37 ,
const char * V_18 )
{
int V_20 = 0 ;
F_56 ( V_29 , V_16 , V_37 ) ;
if ( ! V_18 ) {
F_58 ( V_29 -> V_33 , V_5 ) ;
F_58 ( V_29 -> V_86 ,
V_29 -> V_17 ) ;
} else
V_20 = F_52 ( V_29 , V_18 ) ;
return V_20 ;
}
static int F_59 ( struct V_38 * V_38 , const void * V_48 ,
T_2 V_37 )
{
struct V_28 * V_29 = NULL ;
char * V_15 = NULL ;
char * V_16 = NULL ;
char * V_17 = NULL ;
char * V_18 = NULL ;
int V_20 ;
if ( V_37 <= 0 || V_37 > 32767 || ! V_48 )
return - V_14 ;
V_15 = F_14 ( V_37 + 1 , V_36 ) ;
if ( ! V_15 )
return - V_59 ;
V_15 [ V_37 ] = 0 ;
memcpy ( V_15 , V_48 , V_37 ) ;
V_20 = F_10 ( V_15 , & V_16 , & V_17 ,
& V_18 ) ;
if ( V_20 < 0 )
goto V_11;
V_29 = F_49 ( V_38 , V_16 , V_17 ) ;
if ( F_3 ( V_29 ) ) {
V_20 = F_5 ( V_29 ) ;
goto V_11;
}
V_20 = F_57 ( V_29 , V_16 , V_17 ,
V_18 ) ;
if ( V_20 < 0 ) {
F_28 ( V_29 ) ;
goto V_11;
}
F_60 ( V_38 -> V_47 . V_48 , V_29 ) ;
V_11:
F_28 ( V_15 ) ;
return V_20 ;
}
static void F_61 ( struct V_97 * V_98 )
{
struct V_28 * V_29 ;
V_29 = F_62 ( V_98 , struct V_28 , V_98 ) ;
memset ( V_29 -> V_86 , 0 , V_29 -> V_17 ) ;
F_28 ( V_29 ) ;
}
static int F_63 ( struct V_38 * V_38 , const void * V_48 , T_2 V_37 )
{
struct V_28 * V_29 = V_38 -> V_47 . V_48 ;
struct V_28 * V_99 ;
char * V_64 ;
char * V_100 = NULL ;
int V_20 = 0 ;
if ( V_37 <= 0 || V_37 > 32767 || ! V_48 )
return - V_14 ;
V_64 = F_14 ( V_37 + 1 , V_36 ) ;
if ( ! V_64 )
return - V_59 ;
V_64 [ V_37 ] = 0 ;
memcpy ( V_64 , V_48 , V_37 ) ;
V_20 = F_10 ( V_64 , & V_100 , NULL , NULL ) ;
if ( V_20 < 0 )
goto V_11;
V_20 = F_9 ( V_100 , V_29 -> V_16 ) ;
if ( V_20 < 0 )
goto V_11;
V_99 = F_49 ( V_38 , V_100 ,
V_29 -> V_37 ) ;
if ( F_3 ( V_99 ) ) {
V_20 = F_5 ( V_99 ) ;
goto V_11;
}
F_56 ( V_99 , V_100 , V_29 -> V_37 ) ;
memcpy ( V_99 -> V_33 , V_29 -> V_33 , V_5 ) ;
memcpy ( V_99 -> V_86 , V_29 -> V_86 ,
V_29 -> V_17 ) ;
F_60 ( V_38 -> V_47 . V_48 , V_99 ) ;
F_64 ( & V_29 -> V_98 , F_61 ) ;
V_11:
F_28 ( V_64 ) ;
return V_20 ;
}
static long F_65 ( const struct V_38 * V_38 , char T_4 * V_101 ,
T_2 V_65 )
{
struct V_28 * V_29 ;
struct V_38 * V_78 ;
T_3 * V_40 ;
T_2 V_41 ;
char V_70 [ V_75 ] ;
char * V_31 ;
T_2 V_30 ;
int V_20 ;
V_29 = F_66 ( V_38 ) ;
V_30 = V_29 -> V_89 + V_5 + 1
+ F_38 ( V_29 -> V_17 , V_6 )
+ ( V_75 * 2 ) ;
if ( ! V_101 || V_65 < V_30 )
return V_30 ;
V_78 = F_35 ( V_29 , & V_40 , & V_41 ) ;
if ( F_3 ( V_78 ) )
return F_5 ( V_78 ) ;
V_20 = F_30 ( V_70 , V_96 , V_40 , V_41 ) ;
if ( V_20 < 0 )
goto V_11;
V_20 = F_37 ( V_29 , V_70 , sizeof V_70 ) ;
if ( V_20 < 0 )
goto V_11;
V_20 = F_44 ( V_29 , V_40 , V_41 ) ;
if ( V_20 < 0 )
goto V_11;
V_31 = F_13 ( V_29 , V_30 ) ;
if ( ! V_31 ) {
V_20 = - V_59 ;
goto V_11;
}
F_54 ( & V_78 -> V_46 ) ;
F_55 ( V_78 ) ;
if ( F_67 ( V_101 , V_31 , V_30 ) != 0 )
V_20 = - V_102 ;
F_28 ( V_31 ) ;
return V_30 ;
V_11:
F_54 ( & V_78 -> V_46 ) ;
F_55 ( V_78 ) ;
return V_20 ;
}
static void F_68 ( struct V_38 * V_38 )
{
struct V_28 * V_29 = V_38 -> V_47 . V_48 ;
if ( ! V_29 )
return;
memset ( V_29 -> V_86 , 0 , V_29 -> V_17 ) ;
F_28 ( V_38 -> V_47 . V_48 ) ;
}
static void F_69 ( void )
{
if ( V_68 )
F_70 ( V_68 ) ;
if ( V_66 )
F_70 ( V_66 ) ;
}
static int T_5 F_71 ( void )
{
int V_20 ;
V_66 = F_72 ( V_67 , 0 , V_4 ) ;
if ( F_3 ( V_66 ) ) {
F_25 ( L_16 ,
V_67 ) ;
return F_5 ( V_66 ) ;
}
V_68 = F_72 ( V_69 , 0 , V_4 ) ;
if ( F_3 ( V_68 ) ) {
F_25 ( L_16 ,
V_69 ) ;
V_20 = F_5 ( V_68 ) ;
goto V_103;
}
return 0 ;
V_103:
F_70 ( V_66 ) ;
return V_20 ;
}
static int T_5 F_73 ( void )
{
int V_20 ;
V_20 = F_71 () ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_74 ( & V_104 ) ;
if ( V_20 < 0 )
goto V_11;
return F_1 () ;
V_11:
F_69 () ;
return V_20 ;
}
static void T_6 F_75 ( void )
{
F_69 () ;
F_76 ( & V_104 ) ;
}
