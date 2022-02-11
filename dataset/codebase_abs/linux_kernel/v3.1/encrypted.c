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
static int F_9 ( const char * V_7 )
{
int V_8 ;
if ( strlen ( V_7 ) != V_9 ) {
F_4 ( L_2
L_3 , V_9 ) ;
return - V_10 ;
}
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
if ( ! isxdigit ( V_7 [ V_8 ] ) ) {
F_4 ( L_4
L_5 ) ;
return - V_10 ;
}
}
return 0 ;
}
static int F_10 ( const char * V_11 , const char * V_12 )
{
if ( ! memcmp ( V_11 , V_13 , V_14 ) ) {
if ( strlen ( V_11 ) == V_14 )
goto V_15;
if ( V_12 )
if ( memcmp ( V_11 , V_12 , V_14 ) )
goto V_15;
} else if ( ! memcmp ( V_11 , V_16 , V_17 ) ) {
if ( strlen ( V_11 ) == V_17 )
goto V_15;
if ( V_12 )
if ( memcmp ( V_11 , V_12 , V_17 ) )
goto V_15;
} else
goto V_15;
return 0 ;
V_15:
return - V_10 ;
}
static int F_11 ( char * V_18 , const char * * V_19 ,
char * * V_20 , char * * V_21 ,
char * * V_22 )
{
T_1 args [ V_23 ] ;
int V_24 = - V_10 ;
int V_25 ;
int V_26 ;
char * V_27 , * V_28 ;
V_28 = F_12 ( & V_18 , L_6 ) ;
if ( ! V_28 ) {
F_13 ( L_7 ) ;
return V_24 ;
}
V_25 = F_14 ( V_28 , V_29 , args ) ;
V_27 = F_12 ( & V_18 , L_6 ) ;
if ( ! V_27 ) {
F_4 ( L_7 ) ;
return V_24 ;
}
V_26 = F_14 ( V_27 , V_30 , args ) ;
switch ( V_26 ) {
case V_31 :
case V_32 :
* V_19 = V_27 ;
* V_20 = F_12 ( & V_18 , L_6 ) ;
break;
case V_33 :
* V_20 = V_27 ;
break;
}
if ( ! * V_20 ) {
F_13 ( L_8 ) ;
goto V_15;
}
if ( F_10 ( * V_20 , NULL ) < 0 ) {
F_13 ( L_9
L_10 , * V_20 ) ;
goto V_15;
}
if ( V_21 ) {
* V_21 = F_12 ( & V_18 , L_6 ) ;
if ( ! * V_21 ) {
F_13 ( L_11 ) ;
goto V_15;
}
}
switch ( V_25 ) {
case V_34 :
if ( ! V_21 ) {
F_13 ( L_12
L_13 , V_28 ) ;
break;
}
V_24 = 0 ;
break;
case V_35 :
if ( ! V_21 ) {
F_13 ( L_12
L_13 , V_28 ) ;
break;
}
* V_22 = F_12 ( & V_18 , L_6 ) ;
if ( ! * V_22 ) {
F_13 ( L_14 ) ;
break;
}
V_24 = 0 ;
break;
case V_36 :
if ( V_21 ) {
F_13 ( L_12
L_15 ,
V_28 ) ;
break;
}
V_24 = 0 ;
break;
case V_37 :
F_13 ( L_16 ,
V_28 ) ;
break;
}
V_15:
return V_24 ;
}
static char * F_15 ( struct V_38 * V_39 ,
T_2 V_40 )
{
char * V_41 , * V_42 ;
T_3 * V_43 = V_39 -> V_43 ;
int V_44 ;
int V_8 ;
V_41 = F_16 ( V_40 + 1 , V_45 ) ;
if ( ! V_41 )
goto V_15;
V_41 [ V_40 ] = '\0' ;
V_44 = sprintf ( V_41 , L_17 , V_39 -> V_19 ,
V_39 -> V_20 , V_39 -> V_46 ) ;
V_42 = & V_41 [ V_44 ] ;
for ( V_8 = 0 ; V_8 < ( V_40 - V_44 ) / 2 ; V_8 ++ )
V_42 = F_17 ( V_42 , V_43 [ V_8 ] ) ;
V_15:
return V_41 ;
}
static struct V_47 * F_18 ( const char * V_48 ,
T_3 * * V_49 , T_2 * V_50 )
{
struct V_51 * V_52 ;
struct V_47 * V_53 ;
V_53 = F_19 ( & V_54 , V_48 , NULL ) ;
if ( F_3 ( V_53 ) )
goto error;
F_20 ( & V_53 -> V_55 ) ;
V_52 = F_21 ( V_53 -> V_56 . V_57 ) ;
* V_49 = V_52 -> V_47 ;
* V_50 = V_52 -> V_58 ;
error:
return V_53 ;
}
static struct V_47 * F_22 ( const char * V_20 , T_3 * * V_49 ,
T_2 * V_50 )
{
struct V_59 * V_60 ;
struct V_47 * V_61 ;
V_61 = F_19 ( & V_62 , V_20 , NULL ) ;
if ( F_3 ( V_61 ) )
goto error;
F_20 ( & V_61 -> V_55 ) ;
V_60 = F_21 ( V_61 -> V_56 . V_57 ) ;
* V_49 = V_60 -> V_57 ;
* V_50 = V_60 -> V_46 ;
error:
return V_61 ;
}
static struct V_63 * F_23 ( struct V_64 * V_65 )
{
struct V_63 * V_63 ;
int V_66 ;
V_66 = sizeof( struct V_67 ) + F_24 ( V_65 ) ;
V_63 = F_16 ( V_66 , V_45 ) ;
if ( ! V_63 )
return F_25 ( - V_68 ) ;
V_63 -> V_69 . V_2 = V_65 ;
V_63 -> V_69 . V_70 = 0x0 ;
return V_63 ;
}
static int F_26 ( T_3 * V_71 , const T_3 * V_47 , unsigned int V_72 ,
const T_3 * V_73 , unsigned int V_74 )
{
struct V_63 * V_63 ;
int V_24 ;
V_63 = F_23 ( V_75 ) ;
if ( F_3 ( V_63 ) ) {
F_13 ( L_18 , V_76 ) ;
return F_5 ( V_63 ) ;
}
V_24 = F_27 ( V_75 , V_47 , V_72 ) ;
if ( ! V_24 )
V_24 = F_28 ( & V_63 -> V_69 , V_73 , V_74 , V_71 ) ;
F_29 ( V_63 ) ;
return V_24 ;
}
static int F_30 ( T_3 * V_71 , const T_3 * V_73 , unsigned int V_74 )
{
struct V_63 * V_63 ;
int V_24 ;
V_63 = F_23 ( V_77 ) ;
if ( F_3 ( V_63 ) ) {
F_13 ( L_18 , V_78 ) ;
return F_5 ( V_63 ) ;
}
V_24 = F_28 ( & V_63 -> V_69 , V_73 , V_74 , V_71 ) ;
F_29 ( V_63 ) ;
return V_24 ;
}
static int F_31 ( T_3 * V_79 , enum V_80 V_81 ,
const T_3 * V_49 , T_2 V_50 )
{
T_3 * V_82 ;
unsigned int V_83 ;
int V_24 ;
V_83 = strlen ( L_19 ) + 1 + V_50 ;
if ( V_83 < V_84 )
V_83 = V_84 ;
V_82 = F_32 ( V_83 , V_45 ) ;
if ( ! V_82 ) {
F_4 ( L_20 ) ;
return - V_68 ;
}
if ( V_81 )
strcpy ( V_82 , L_19 ) ;
else
strcpy ( V_82 , L_21 ) ;
memcpy ( V_82 + strlen ( V_82 ) + 1 , V_49 ,
V_50 ) ;
V_24 = F_30 ( V_79 , V_82 , V_83 ) ;
F_29 ( V_82 ) ;
return V_24 ;
}
static int F_33 ( struct V_85 * V_86 , const T_3 * V_47 ,
unsigned int V_58 , const T_3 * V_43 ,
unsigned int V_5 )
{
int V_24 ;
V_86 -> V_2 = F_2 ( V_3 , 0 , V_4 ) ;
if ( F_3 ( V_86 -> V_2 ) ) {
F_4 ( L_22 ,
V_3 , F_5 ( V_86 -> V_2 ) ) ;
return F_5 ( V_86 -> V_2 ) ;
}
V_86 -> V_70 = 0 ;
V_24 = F_34 ( V_86 -> V_2 , V_47 , V_58 ) ;
if ( V_24 < 0 ) {
F_4 ( L_23 , V_24 ) ;
F_8 ( V_86 -> V_2 ) ;
return V_24 ;
}
F_35 ( V_86 -> V_2 , V_43 , V_5 ) ;
return 0 ;
}
static struct V_47 * F_36 ( struct V_38 * V_39 ,
T_3 * * V_49 , T_2 * V_50 )
{
struct V_47 * V_87 = NULL ;
if ( ! strncmp ( V_39 -> V_20 , V_13 ,
V_14 ) ) {
V_87 = F_18 ( V_39 -> V_20 +
V_14 ,
V_49 , V_50 ) ;
} else if ( ! strncmp ( V_39 -> V_20 , V_16 ,
V_17 ) ) {
V_87 = F_22 ( V_39 -> V_20 +
V_17 ,
V_49 , V_50 ) ;
} else
goto V_15;
if ( F_3 ( V_87 ) ) {
F_13 ( L_24 ,
V_39 -> V_20 ) ;
goto V_15;
}
F_37 ( * V_49 , * V_50 ) ;
V_15:
return V_87 ;
}
static int F_38 ( struct V_38 * V_39 ,
const T_3 * V_79 ,
unsigned int V_88 )
{
struct V_89 V_90 [ 2 ] ;
struct V_89 V_91 [ 1 ] ;
struct V_85 V_86 ;
unsigned int V_92 ;
unsigned int V_93 ;
char V_94 [ 16 ] ;
int V_24 ;
V_92 = F_39 ( V_39 -> V_21 , V_6 ) ;
V_93 = V_92 - V_39 -> V_21 ;
V_24 = F_33 ( & V_86 , V_79 , V_88 ,
V_39 -> V_43 , V_5 ) ;
if ( V_24 < 0 )
goto V_15;
F_40 ( V_39 ) ;
memset ( V_94 , 0 , sizeof V_94 ) ;
F_41 ( V_90 , 2 ) ;
F_42 ( & V_90 [ 0 ] , V_39 -> V_95 ,
V_39 -> V_21 ) ;
F_42 ( & V_90 [ 1 ] , V_94 , V_93 ) ;
F_41 ( V_91 , 1 ) ;
F_42 ( V_91 , V_39 -> V_96 , V_92 ) ;
V_24 = F_43 ( & V_86 , V_91 , V_90 , V_92 ) ;
F_8 ( V_86 . V_2 ) ;
if ( V_24 < 0 )
F_4 ( L_25 , V_24 ) ;
else
F_44 ( V_39 , V_92 ) ;
V_15:
return V_24 ;
}
static int F_45 ( struct V_38 * V_39 ,
const T_3 * V_49 , T_2 V_50 )
{
T_3 V_79 [ V_84 ] ;
T_3 * V_71 ;
int V_24 ;
V_24 = F_31 ( V_79 , V_97 , V_49 , V_50 ) ;
if ( V_24 < 0 )
goto V_15;
V_71 = V_39 -> V_19 + V_39 -> V_98 ;
V_24 = F_26 ( V_71 , V_79 , sizeof V_79 ,
V_39 -> V_19 , V_39 -> V_98 ) ;
if ( ! V_24 )
F_46 ( NULL , V_71 , V_84 ) ;
V_15:
return V_24 ;
}
static int F_47 ( struct V_38 * V_39 ,
const T_3 * V_19 , const T_3 * V_49 ,
T_2 V_50 )
{
T_3 V_79 [ V_84 ] ;
T_3 V_71 [ V_84 ] ;
int V_24 ;
char * V_27 ;
unsigned short V_44 ;
V_24 = F_31 ( V_79 , V_97 , V_49 , V_50 ) ;
if ( V_24 < 0 )
goto V_15;
V_44 = V_39 -> V_98 ;
if ( ! V_19 ) {
V_27 = V_39 -> V_20 ;
V_44 -= strlen ( V_39 -> V_19 ) + 1 ;
} else
V_27 = V_39 -> V_19 ;
V_24 = F_26 ( V_71 , V_79 , sizeof V_79 , V_27 , V_44 ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = memcmp ( V_71 , V_39 -> V_19 + V_39 -> V_98 ,
sizeof V_71 ) ;
if ( V_24 ) {
V_24 = - V_10 ;
F_46 ( L_26 ,
V_39 -> V_19 + V_39 -> V_98 ,
V_84 ) ;
F_46 ( L_27 , V_71 , V_84 ) ;
}
V_15:
return V_24 ;
}
static int F_48 ( struct V_38 * V_39 ,
const T_3 * V_79 ,
unsigned int V_88 )
{
struct V_89 V_90 [ 1 ] ;
struct V_89 V_91 [ 2 ] ;
struct V_85 V_86 ;
unsigned int V_92 ;
char V_94 [ 16 ] ;
int V_24 ;
V_92 = F_39 ( V_39 -> V_21 , V_6 ) ;
V_24 = F_33 ( & V_86 , V_79 , V_88 ,
V_39 -> V_43 , V_5 ) ;
if ( V_24 < 0 )
goto V_15;
F_44 ( V_39 , V_92 ) ;
memset ( V_94 , 0 , sizeof V_94 ) ;
F_41 ( V_90 , 1 ) ;
F_41 ( V_91 , 2 ) ;
F_42 ( V_90 , V_39 -> V_96 , V_92 ) ;
F_42 ( & V_91 [ 0 ] , V_39 -> V_95 ,
V_39 -> V_21 ) ;
F_42 ( & V_91 [ 1 ] , V_94 , sizeof V_94 ) ;
V_24 = F_49 ( & V_86 , V_91 , V_90 , V_92 ) ;
F_8 ( V_86 . V_2 ) ;
if ( V_24 < 0 )
goto V_15;
F_40 ( V_39 ) ;
V_15:
return V_24 ;
}
static struct V_38 * F_50 ( struct V_47 * V_47 ,
const char * V_19 ,
const char * V_20 ,
const char * V_46 )
{
struct V_38 * V_39 = NULL ;
unsigned short V_98 ;
unsigned short V_21 ;
unsigned short V_99 ;
unsigned int V_92 ;
unsigned int V_100 ;
long V_101 ;
int V_24 ;
V_24 = F_51 ( V_46 , 10 , & V_101 ) ;
if ( V_24 < 0 || V_101 < V_102 || V_101 > V_103 )
return F_25 ( - V_10 ) ;
V_100 = ( ! V_19 ) ? strlen ( V_104 ) : strlen ( V_19 ) ;
V_21 = V_101 ;
V_99 = V_21 ;
if ( V_19 && ! strcmp ( V_19 , V_105 ) ) {
if ( V_101 != V_106 ) {
F_4 ( L_28
L_29 ,
V_106 ) ;
return F_25 ( - V_10 ) ;
}
V_21 = V_106 ;
V_99 = sizeof( struct V_107 ) ;
}
V_92 = F_39 ( V_21 , V_6 ) ;
V_98 = V_100 + 1 + strlen ( V_20 ) + 1
+ strlen ( V_46 ) + 1 + V_5 + 1 + V_92 ;
V_24 = F_52 ( V_47 , V_99 + V_98
+ V_84 + 1 ) ;
if ( V_24 < 0 )
return F_25 ( V_24 ) ;
V_39 = F_32 ( sizeof( * V_39 ) + V_99 +
V_98 + V_84 + 1 , V_45 ) ;
if ( ! V_39 )
return F_25 ( - V_68 ) ;
V_39 -> V_99 = V_99 ;
V_39 -> V_21 = V_21 ;
V_39 -> V_98 = V_98 ;
return V_39 ;
}
static int F_53 ( struct V_38 * V_39 ,
const char * V_19 , const char * V_22 )
{
struct V_47 * V_87 ;
T_3 V_79 [ V_84 ] ;
T_3 * V_49 ;
T_3 * V_108 ;
const char * V_109 ;
unsigned int V_92 ;
T_2 V_50 ;
T_2 V_110 ;
int V_24 ;
V_92 = F_39 ( V_39 -> V_21 , V_6 ) ;
V_110 = ( V_5 + 1 + V_92 + V_84 ) * 2 ;
if ( strlen ( V_22 ) != V_110 )
return - V_10 ;
V_109 = V_22 + ( 2 * V_5 ) + 2 ;
F_54 ( V_39 -> V_43 , V_22 , V_5 ) ;
F_54 ( V_39 -> V_96 , V_109 , V_92 ) ;
V_108 = V_39 -> V_19 + V_39 -> V_98 ;
F_54 ( V_108 , V_109 + ( V_92 * 2 ) , V_84 ) ;
V_87 = F_36 ( V_39 , & V_49 , & V_50 ) ;
if ( F_3 ( V_87 ) )
return F_5 ( V_87 ) ;
V_24 = F_47 ( V_39 , V_19 , V_49 , V_50 ) ;
if ( V_24 < 0 ) {
F_4 ( L_30 , V_24 ) ;
goto V_15;
}
V_24 = F_31 ( V_79 , V_111 , V_49 , V_50 ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_48 ( V_39 , V_79 , sizeof V_79 ) ;
if ( V_24 < 0 )
F_4 ( L_31 , V_24 ) ;
V_15:
F_55 ( & V_87 -> V_55 ) ;
F_56 ( V_87 ) ;
return V_24 ;
}
static void F_57 ( struct V_38 * V_39 ,
const char * V_19 , const char * V_20 ,
const char * V_46 )
{
unsigned int V_100 ;
V_100 = ( ! V_19 ) ? strlen ( V_104 ) : strlen ( V_19 ) ;
V_39 -> V_19 = V_39 -> V_112 + V_39 -> V_99 ;
V_39 -> V_20 = V_39 -> V_19 + V_100 + 1 ;
V_39 -> V_46 = V_39 -> V_20 + strlen ( V_20 ) + 1 ;
V_39 -> V_43 = V_39 -> V_46 + strlen ( V_46 ) + 1 ;
V_39 -> V_96 = V_39 -> V_43 + V_5 + 1 ;
V_39 -> V_95 = V_39 -> V_112 ;
if ( ! V_19 )
memcpy ( V_39 -> V_19 , V_104 , V_100 ) ;
else {
if ( ! strcmp ( V_19 , V_105 ) )
V_39 -> V_95 =
F_58 ( (struct V_107 * ) V_39 -> V_112 ) ;
memcpy ( V_39 -> V_19 , V_19 , V_100 ) ;
}
memcpy ( V_39 -> V_20 , V_20 , strlen ( V_20 ) ) ;
memcpy ( V_39 -> V_46 , V_46 , strlen ( V_46 ) ) ;
}
static int F_59 ( struct V_38 * V_39 ,
const char * V_113 , const char * V_19 ,
const char * V_20 , const char * V_46 ,
const char * V_22 )
{
int V_24 = 0 ;
if ( V_19 && ! strcmp ( V_19 , V_105 ) ) {
V_24 = F_9 ( V_113 ) ;
if ( V_24 < 0 )
return V_24 ;
F_60 ( (struct V_107 * ) V_39 -> V_112 ,
V_113 ) ;
}
F_57 ( V_39 , V_19 , V_20 , V_46 ) ;
if ( ! V_22 ) {
F_61 ( V_39 -> V_43 , V_5 ) ;
F_61 ( V_39 -> V_95 ,
V_39 -> V_21 ) ;
} else
V_24 = F_53 ( V_39 , V_19 , V_22 ) ;
return V_24 ;
}
static int F_62 ( struct V_47 * V_47 , const void * V_57 ,
T_2 V_46 )
{
struct V_38 * V_39 = NULL ;
char * V_18 = NULL ;
const char * V_19 = NULL ;
char * V_20 = NULL ;
char * V_21 = NULL ;
char * V_22 = NULL ;
int V_24 ;
if ( V_46 <= 0 || V_46 > 32767 || ! V_57 )
return - V_10 ;
V_18 = F_16 ( V_46 + 1 , V_45 ) ;
if ( ! V_18 )
return - V_68 ;
V_18 [ V_46 ] = 0 ;
memcpy ( V_18 , V_57 , V_46 ) ;
V_24 = F_11 ( V_18 , & V_19 , & V_20 ,
& V_21 , & V_22 ) ;
if ( V_24 < 0 )
goto V_15;
V_39 = F_50 ( V_47 , V_19 , V_20 ,
V_21 ) ;
if ( F_3 ( V_39 ) ) {
V_24 = F_5 ( V_39 ) ;
goto V_15;
}
V_24 = F_59 ( V_39 , V_47 -> V_114 , V_19 , V_20 ,
V_21 , V_22 ) ;
if ( V_24 < 0 ) {
F_29 ( V_39 ) ;
goto V_15;
}
F_63 ( V_47 -> V_56 . V_57 , V_39 ) ;
V_15:
F_29 ( V_18 ) ;
return V_24 ;
}
static void F_64 ( struct V_115 * V_116 )
{
struct V_38 * V_39 ;
V_39 = F_65 ( V_116 , struct V_38 , V_116 ) ;
memset ( V_39 -> V_95 , 0 , V_39 -> V_21 ) ;
F_29 ( V_39 ) ;
}
static int F_66 ( struct V_47 * V_47 , const void * V_57 , T_2 V_46 )
{
struct V_38 * V_39 = V_47 -> V_56 . V_57 ;
struct V_38 * V_117 ;
char * V_73 ;
char * V_118 = NULL ;
const char * V_19 = NULL ;
int V_24 = 0 ;
if ( V_46 <= 0 || V_46 > 32767 || ! V_57 )
return - V_10 ;
V_73 = F_16 ( V_46 + 1 , V_45 ) ;
if ( ! V_73 )
return - V_68 ;
V_73 [ V_46 ] = 0 ;
memcpy ( V_73 , V_57 , V_46 ) ;
V_24 = F_11 ( V_73 , & V_19 , & V_118 , NULL , NULL ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_10 ( V_118 , V_39 -> V_20 ) ;
if ( V_24 < 0 )
goto V_15;
V_117 = F_50 ( V_47 , V_39 -> V_19 ,
V_118 , V_39 -> V_46 ) ;
if ( F_3 ( V_117 ) ) {
V_24 = F_5 ( V_117 ) ;
goto V_15;
}
F_57 ( V_117 , V_39 -> V_19 , V_118 ,
V_39 -> V_46 ) ;
memcpy ( V_117 -> V_43 , V_39 -> V_43 , V_5 ) ;
memcpy ( V_117 -> V_112 , V_39 -> V_112 ,
V_39 -> V_99 ) ;
F_63 ( V_47 -> V_56 . V_57 , V_117 ) ;
F_67 ( & V_39 -> V_116 , F_64 ) ;
V_15:
F_29 ( V_73 ) ;
return V_24 ;
}
static long F_68 ( const struct V_47 * V_47 , char T_4 * V_119 ,
T_2 V_74 )
{
struct V_38 * V_39 ;
struct V_47 * V_87 ;
T_3 * V_49 ;
T_2 V_50 ;
char V_79 [ V_84 ] ;
char * V_41 ;
T_2 V_40 ;
int V_24 ;
V_39 = F_69 ( V_47 ) ;
V_40 = V_39 -> V_98 + V_5 + 1
+ F_39 ( V_39 -> V_21 , V_6 )
+ ( V_84 * 2 ) ;
if ( ! V_119 || V_74 < V_40 )
return V_40 ;
V_87 = F_36 ( V_39 , & V_49 , & V_50 ) ;
if ( F_3 ( V_87 ) )
return F_5 ( V_87 ) ;
V_24 = F_31 ( V_79 , V_111 , V_49 , V_50 ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_38 ( V_39 , V_79 , sizeof V_79 ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_45 ( V_39 , V_49 , V_50 ) ;
if ( V_24 < 0 )
goto V_15;
V_41 = F_15 ( V_39 , V_40 ) ;
if ( ! V_41 ) {
V_24 = - V_68 ;
goto V_15;
}
F_55 ( & V_87 -> V_55 ) ;
F_56 ( V_87 ) ;
if ( F_70 ( V_119 , V_41 , V_40 ) != 0 )
V_24 = - V_120 ;
F_29 ( V_41 ) ;
return V_40 ;
V_15:
F_55 ( & V_87 -> V_55 ) ;
F_56 ( V_87 ) ;
return V_24 ;
}
static void F_71 ( struct V_47 * V_47 )
{
struct V_38 * V_39 = V_47 -> V_56 . V_57 ;
if ( ! V_39 )
return;
memset ( V_39 -> V_95 , 0 , V_39 -> V_21 ) ;
F_29 ( V_47 -> V_56 . V_57 ) ;
}
static void F_72 ( void )
{
if ( V_77 )
F_73 ( V_77 ) ;
if ( V_75 )
F_73 ( V_75 ) ;
}
static int T_5 F_74 ( void )
{
int V_24 ;
V_75 = F_75 ( V_76 , 0 , V_4 ) ;
if ( F_3 ( V_75 ) ) {
F_13 ( L_32 ,
V_76 ) ;
return F_5 ( V_75 ) ;
}
V_77 = F_75 ( V_78 , 0 , V_4 ) ;
if ( F_3 ( V_77 ) ) {
F_13 ( L_32 ,
V_78 ) ;
V_24 = F_5 ( V_77 ) ;
goto V_121;
}
return 0 ;
V_121:
F_73 ( V_75 ) ;
return V_24 ;
}
static int T_5 F_76 ( void )
{
int V_24 ;
V_24 = F_74 () ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_77 ( & V_122 ) ;
if ( V_24 < 0 )
goto V_15;
return F_1 () ;
V_15:
F_72 () ;
return V_24 ;
}
static void T_6 F_78 ( void )
{
F_72 () ;
F_79 ( & V_122 ) ;
}
