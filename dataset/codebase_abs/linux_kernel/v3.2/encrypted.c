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
static struct V_47 * F_18 ( const char * V_20 , T_3 * * V_48 ,
T_2 * V_49 )
{
struct V_50 * V_51 ;
struct V_47 * V_52 ;
V_52 = F_19 ( & V_53 , V_20 , NULL ) ;
if ( F_3 ( V_52 ) )
goto error;
F_20 ( & V_52 -> V_54 ) ;
V_51 = F_21 ( V_52 -> V_55 . V_56 ) ;
* V_48 = V_51 -> V_56 ;
* V_49 = V_51 -> V_46 ;
error:
return V_52 ;
}
static struct V_57 * F_22 ( struct V_58 * V_59 )
{
struct V_57 * V_57 ;
int V_60 ;
V_60 = sizeof( struct V_61 ) + F_23 ( V_59 ) ;
V_57 = F_16 ( V_60 , V_45 ) ;
if ( ! V_57 )
return F_24 ( - V_62 ) ;
V_57 -> V_63 . V_2 = V_59 ;
V_57 -> V_63 . V_64 = 0x0 ;
return V_57 ;
}
static int F_25 ( T_3 * V_65 , const T_3 * V_47 , unsigned int V_66 ,
const T_3 * V_67 , unsigned int V_68 )
{
struct V_57 * V_57 ;
int V_24 ;
V_57 = F_22 ( V_69 ) ;
if ( F_3 ( V_57 ) ) {
F_13 ( L_18 , V_70 ) ;
return F_5 ( V_57 ) ;
}
V_24 = F_26 ( V_69 , V_47 , V_66 ) ;
if ( ! V_24 )
V_24 = F_27 ( & V_57 -> V_63 , V_67 , V_68 , V_65 ) ;
F_28 ( V_57 ) ;
return V_24 ;
}
static int F_29 ( T_3 * V_65 , const T_3 * V_67 , unsigned int V_68 )
{
struct V_57 * V_57 ;
int V_24 ;
V_57 = F_22 ( V_71 ) ;
if ( F_3 ( V_57 ) ) {
F_13 ( L_18 , V_72 ) ;
return F_5 ( V_57 ) ;
}
V_24 = F_27 ( & V_57 -> V_63 , V_67 , V_68 , V_65 ) ;
F_28 ( V_57 ) ;
return V_24 ;
}
static int F_30 ( T_3 * V_73 , enum V_74 V_75 ,
const T_3 * V_48 , T_2 V_49 )
{
T_3 * V_76 ;
unsigned int V_77 ;
int V_24 ;
V_77 = strlen ( L_19 ) + 1 + V_49 ;
if ( V_77 < V_78 )
V_77 = V_78 ;
V_76 = F_31 ( V_77 , V_45 ) ;
if ( ! V_76 ) {
F_4 ( L_20 ) ;
return - V_62 ;
}
if ( V_75 )
strcpy ( V_76 , L_19 ) ;
else
strcpy ( V_76 , L_21 ) ;
memcpy ( V_76 + strlen ( V_76 ) + 1 , V_48 ,
V_49 ) ;
V_24 = F_29 ( V_73 , V_76 , V_77 ) ;
F_28 ( V_76 ) ;
return V_24 ;
}
static int F_32 ( struct V_79 * V_80 , const T_3 * V_47 ,
unsigned int V_81 , const T_3 * V_43 ,
unsigned int V_5 )
{
int V_24 ;
V_80 -> V_2 = F_2 ( V_3 , 0 , V_4 ) ;
if ( F_3 ( V_80 -> V_2 ) ) {
F_4 ( L_22 ,
V_3 , F_5 ( V_80 -> V_2 ) ) ;
return F_5 ( V_80 -> V_2 ) ;
}
V_80 -> V_64 = 0 ;
V_24 = F_33 ( V_80 -> V_2 , V_47 , V_81 ) ;
if ( V_24 < 0 ) {
F_4 ( L_23 , V_24 ) ;
F_8 ( V_80 -> V_2 ) ;
return V_24 ;
}
F_34 ( V_80 -> V_2 , V_43 , V_5 ) ;
return 0 ;
}
static struct V_47 * F_35 ( struct V_38 * V_39 ,
T_3 * * V_48 , T_2 * V_49 )
{
struct V_47 * V_82 = NULL ;
if ( ! strncmp ( V_39 -> V_20 , V_13 ,
V_14 ) ) {
V_82 = F_36 ( V_39 -> V_20 +
V_14 ,
V_48 , V_49 ) ;
} else if ( ! strncmp ( V_39 -> V_20 , V_16 ,
V_17 ) ) {
V_82 = F_18 ( V_39 -> V_20 +
V_17 ,
V_48 , V_49 ) ;
} else
goto V_15;
if ( F_3 ( V_82 ) ) {
int V_24 = F_5 ( V_82 ) ;
if ( V_24 == - V_83 )
F_13 ( L_24 ,
V_39 -> V_20 ) ;
else
F_13 ( L_25 ,
V_39 -> V_20 ) ;
goto V_15;
}
F_37 ( * V_48 , * V_49 ) ;
V_15:
return V_82 ;
}
static int F_38 ( struct V_38 * V_39 ,
const T_3 * V_73 ,
unsigned int V_84 )
{
struct V_85 V_86 [ 2 ] ;
struct V_85 V_87 [ 1 ] ;
struct V_79 V_80 ;
unsigned int V_88 ;
unsigned int V_89 ;
char V_90 [ 16 ] ;
int V_24 ;
V_88 = F_39 ( V_39 -> V_21 , V_6 ) ;
V_89 = V_88 - V_39 -> V_21 ;
V_24 = F_32 ( & V_80 , V_73 , V_84 ,
V_39 -> V_43 , V_5 ) ;
if ( V_24 < 0 )
goto V_15;
F_40 ( V_39 ) ;
memset ( V_90 , 0 , sizeof V_90 ) ;
F_41 ( V_86 , 2 ) ;
F_42 ( & V_86 [ 0 ] , V_39 -> V_91 ,
V_39 -> V_21 ) ;
F_42 ( & V_86 [ 1 ] , V_90 , V_89 ) ;
F_41 ( V_87 , 1 ) ;
F_42 ( V_87 , V_39 -> V_92 , V_88 ) ;
V_24 = F_43 ( & V_80 , V_87 , V_86 , V_88 ) ;
F_8 ( V_80 . V_2 ) ;
if ( V_24 < 0 )
F_4 ( L_26 , V_24 ) ;
else
F_44 ( V_39 , V_88 ) ;
V_15:
return V_24 ;
}
static int F_45 ( struct V_38 * V_39 ,
const T_3 * V_48 , T_2 V_49 )
{
T_3 V_73 [ V_78 ] ;
T_3 * V_65 ;
int V_24 ;
V_24 = F_30 ( V_73 , V_93 , V_48 , V_49 ) ;
if ( V_24 < 0 )
goto V_15;
V_65 = V_39 -> V_19 + V_39 -> V_94 ;
V_24 = F_25 ( V_65 , V_73 , sizeof V_73 ,
V_39 -> V_19 , V_39 -> V_94 ) ;
if ( ! V_24 )
F_46 ( NULL , V_65 , V_78 ) ;
V_15:
return V_24 ;
}
static int F_47 ( struct V_38 * V_39 ,
const T_3 * V_19 , const T_3 * V_48 ,
T_2 V_49 )
{
T_3 V_73 [ V_78 ] ;
T_3 V_65 [ V_78 ] ;
int V_24 ;
char * V_27 ;
unsigned short V_44 ;
V_24 = F_30 ( V_73 , V_93 , V_48 , V_49 ) ;
if ( V_24 < 0 )
goto V_15;
V_44 = V_39 -> V_94 ;
if ( ! V_19 ) {
V_27 = V_39 -> V_20 ;
V_44 -= strlen ( V_39 -> V_19 ) + 1 ;
} else
V_27 = V_39 -> V_19 ;
V_24 = F_25 ( V_65 , V_73 , sizeof V_73 , V_27 , V_44 ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = memcmp ( V_65 , V_39 -> V_19 + V_39 -> V_94 ,
sizeof V_65 ) ;
if ( V_24 ) {
V_24 = - V_10 ;
F_46 ( L_27 ,
V_39 -> V_19 + V_39 -> V_94 ,
V_78 ) ;
F_46 ( L_28 , V_65 , V_78 ) ;
}
V_15:
return V_24 ;
}
static int F_48 ( struct V_38 * V_39 ,
const T_3 * V_73 ,
unsigned int V_84 )
{
struct V_85 V_86 [ 1 ] ;
struct V_85 V_87 [ 2 ] ;
struct V_79 V_80 ;
unsigned int V_88 ;
char V_90 [ 16 ] ;
int V_24 ;
V_88 = F_39 ( V_39 -> V_21 , V_6 ) ;
V_24 = F_32 ( & V_80 , V_73 , V_84 ,
V_39 -> V_43 , V_5 ) ;
if ( V_24 < 0 )
goto V_15;
F_44 ( V_39 , V_88 ) ;
memset ( V_90 , 0 , sizeof V_90 ) ;
F_41 ( V_86 , 1 ) ;
F_41 ( V_87 , 2 ) ;
F_42 ( V_86 , V_39 -> V_92 , V_88 ) ;
F_42 ( & V_87 [ 0 ] , V_39 -> V_91 ,
V_39 -> V_21 ) ;
F_42 ( & V_87 [ 1 ] , V_90 , sizeof V_90 ) ;
V_24 = F_49 ( & V_80 , V_87 , V_86 , V_88 ) ;
F_8 ( V_80 . V_2 ) ;
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
unsigned short V_94 ;
unsigned short V_21 ;
unsigned short V_95 ;
unsigned int V_88 ;
unsigned int V_96 ;
long V_97 ;
int V_24 ;
V_24 = F_51 ( V_46 , 10 , & V_97 ) ;
if ( V_24 < 0 || V_97 < V_98 || V_97 > V_99 )
return F_24 ( - V_10 ) ;
V_96 = ( ! V_19 ) ? strlen ( V_100 ) : strlen ( V_19 ) ;
V_21 = V_97 ;
V_95 = V_21 ;
if ( V_19 && ! strcmp ( V_19 , V_101 ) ) {
if ( V_97 != V_102 ) {
F_4 ( L_29
L_30 ,
V_102 ) ;
return F_24 ( - V_10 ) ;
}
V_21 = V_102 ;
V_95 = sizeof( struct V_103 ) ;
}
V_88 = F_39 ( V_21 , V_6 ) ;
V_94 = V_96 + 1 + strlen ( V_20 ) + 1
+ strlen ( V_46 ) + 1 + V_5 + 1 + V_88 ;
V_24 = F_52 ( V_47 , V_95 + V_94
+ V_78 + 1 ) ;
if ( V_24 < 0 )
return F_24 ( V_24 ) ;
V_39 = F_31 ( sizeof( * V_39 ) + V_95 +
V_94 + V_78 + 1 , V_45 ) ;
if ( ! V_39 )
return F_24 ( - V_62 ) ;
V_39 -> V_95 = V_95 ;
V_39 -> V_21 = V_21 ;
V_39 -> V_94 = V_94 ;
return V_39 ;
}
static int F_53 ( struct V_38 * V_39 ,
const char * V_19 , const char * V_22 )
{
struct V_47 * V_82 ;
T_3 V_73 [ V_78 ] ;
T_3 * V_48 ;
T_3 * V_104 ;
const char * V_105 ;
unsigned int V_88 ;
T_2 V_49 ;
T_2 V_106 ;
int V_24 ;
V_88 = F_39 ( V_39 -> V_21 , V_6 ) ;
V_106 = ( V_5 + 1 + V_88 + V_78 ) * 2 ;
if ( strlen ( V_22 ) != V_106 )
return - V_10 ;
V_105 = V_22 + ( 2 * V_5 ) + 2 ;
V_24 = F_54 ( V_39 -> V_43 , V_22 , V_5 ) ;
if ( V_24 < 0 )
return - V_10 ;
V_24 = F_54 ( V_39 -> V_92 , V_105 ,
V_88 ) ;
if ( V_24 < 0 )
return - V_10 ;
V_104 = V_39 -> V_19 + V_39 -> V_94 ;
V_24 = F_54 ( V_104 , V_105 + ( V_88 * 2 ) ,
V_78 ) ;
if ( V_24 < 0 )
return - V_10 ;
V_82 = F_35 ( V_39 , & V_48 , & V_49 ) ;
if ( F_3 ( V_82 ) )
return F_5 ( V_82 ) ;
V_24 = F_47 ( V_39 , V_19 , V_48 , V_49 ) ;
if ( V_24 < 0 ) {
F_4 ( L_31 , V_24 ) ;
goto V_15;
}
V_24 = F_30 ( V_73 , V_107 , V_48 , V_49 ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_48 ( V_39 , V_73 , sizeof V_73 ) ;
if ( V_24 < 0 )
F_4 ( L_32 , V_24 ) ;
V_15:
F_55 ( & V_82 -> V_54 ) ;
F_56 ( V_82 ) ;
return V_24 ;
}
static void F_57 ( struct V_38 * V_39 ,
const char * V_19 , const char * V_20 ,
const char * V_46 )
{
unsigned int V_96 ;
V_96 = ( ! V_19 ) ? strlen ( V_100 ) : strlen ( V_19 ) ;
V_39 -> V_19 = V_39 -> V_108 + V_39 -> V_95 ;
V_39 -> V_20 = V_39 -> V_19 + V_96 + 1 ;
V_39 -> V_46 = V_39 -> V_20 + strlen ( V_20 ) + 1 ;
V_39 -> V_43 = V_39 -> V_46 + strlen ( V_46 ) + 1 ;
V_39 -> V_92 = V_39 -> V_43 + V_5 + 1 ;
V_39 -> V_91 = V_39 -> V_108 ;
if ( ! V_19 )
memcpy ( V_39 -> V_19 , V_100 , V_96 ) ;
else {
if ( ! strcmp ( V_19 , V_101 ) )
V_39 -> V_91 =
F_58 ( (struct V_103 * ) V_39 -> V_108 ) ;
memcpy ( V_39 -> V_19 , V_19 , V_96 ) ;
}
memcpy ( V_39 -> V_20 , V_20 , strlen ( V_20 ) ) ;
memcpy ( V_39 -> V_46 , V_46 , strlen ( V_46 ) ) ;
}
static int F_59 ( struct V_38 * V_39 ,
const char * V_109 , const char * V_19 ,
const char * V_20 , const char * V_46 ,
const char * V_22 )
{
int V_24 = 0 ;
if ( V_19 && ! strcmp ( V_19 , V_101 ) ) {
V_24 = F_9 ( V_109 ) ;
if ( V_24 < 0 )
return V_24 ;
F_60 ( (struct V_103 * ) V_39 -> V_108 ,
V_109 ) ;
}
F_57 ( V_39 , V_19 , V_20 , V_46 ) ;
if ( ! V_22 ) {
F_61 ( V_39 -> V_43 , V_5 ) ;
F_61 ( V_39 -> V_91 ,
V_39 -> V_21 ) ;
} else
V_24 = F_53 ( V_39 , V_19 , V_22 ) ;
return V_24 ;
}
static int F_62 ( struct V_47 * V_47 , const void * V_56 ,
T_2 V_46 )
{
struct V_38 * V_39 = NULL ;
char * V_18 = NULL ;
const char * V_19 = NULL ;
char * V_20 = NULL ;
char * V_21 = NULL ;
char * V_22 = NULL ;
int V_24 ;
if ( V_46 <= 0 || V_46 > 32767 || ! V_56 )
return - V_10 ;
V_18 = F_16 ( V_46 + 1 , V_45 ) ;
if ( ! V_18 )
return - V_62 ;
V_18 [ V_46 ] = 0 ;
memcpy ( V_18 , V_56 , V_46 ) ;
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
V_24 = F_59 ( V_39 , V_47 -> V_110 , V_19 , V_20 ,
V_21 , V_22 ) ;
if ( V_24 < 0 ) {
F_28 ( V_39 ) ;
goto V_15;
}
F_63 ( V_47 -> V_55 . V_56 , V_39 ) ;
V_15:
F_28 ( V_18 ) ;
return V_24 ;
}
static void F_64 ( struct V_111 * V_112 )
{
struct V_38 * V_39 ;
V_39 = F_65 ( V_112 , struct V_38 , V_112 ) ;
memset ( V_39 -> V_91 , 0 , V_39 -> V_21 ) ;
F_28 ( V_39 ) ;
}
static int F_66 ( struct V_47 * V_47 , const void * V_56 , T_2 V_46 )
{
struct V_38 * V_39 = V_47 -> V_55 . V_56 ;
struct V_38 * V_113 ;
char * V_67 ;
char * V_114 = NULL ;
const char * V_19 = NULL ;
int V_24 = 0 ;
if ( V_46 <= 0 || V_46 > 32767 || ! V_56 )
return - V_10 ;
V_67 = F_16 ( V_46 + 1 , V_45 ) ;
if ( ! V_67 )
return - V_62 ;
V_67 [ V_46 ] = 0 ;
memcpy ( V_67 , V_56 , V_46 ) ;
V_24 = F_11 ( V_67 , & V_19 , & V_114 , NULL , NULL ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_10 ( V_114 , V_39 -> V_20 ) ;
if ( V_24 < 0 )
goto V_15;
V_113 = F_50 ( V_47 , V_39 -> V_19 ,
V_114 , V_39 -> V_46 ) ;
if ( F_3 ( V_113 ) ) {
V_24 = F_5 ( V_113 ) ;
goto V_15;
}
F_57 ( V_113 , V_39 -> V_19 , V_114 ,
V_39 -> V_46 ) ;
memcpy ( V_113 -> V_43 , V_39 -> V_43 , V_5 ) ;
memcpy ( V_113 -> V_108 , V_39 -> V_108 ,
V_39 -> V_95 ) ;
F_63 ( V_47 -> V_55 . V_56 , V_113 ) ;
F_67 ( & V_39 -> V_112 , F_64 ) ;
V_15:
F_28 ( V_67 ) ;
return V_24 ;
}
static long F_68 ( const struct V_47 * V_47 , char T_4 * V_115 ,
T_2 V_68 )
{
struct V_38 * V_39 ;
struct V_47 * V_82 ;
T_3 * V_48 ;
T_2 V_49 ;
char V_73 [ V_78 ] ;
char * V_41 ;
T_2 V_40 ;
int V_24 ;
V_39 = F_69 ( V_47 ) ;
V_40 = V_39 -> V_94 + V_5 + 1
+ F_39 ( V_39 -> V_21 , V_6 )
+ ( V_78 * 2 ) ;
if ( ! V_115 || V_68 < V_40 )
return V_40 ;
V_82 = F_35 ( V_39 , & V_48 , & V_49 ) ;
if ( F_3 ( V_82 ) )
return F_5 ( V_82 ) ;
V_24 = F_30 ( V_73 , V_107 , V_48 , V_49 ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_38 ( V_39 , V_73 , sizeof V_73 ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_45 ( V_39 , V_48 , V_49 ) ;
if ( V_24 < 0 )
goto V_15;
V_41 = F_15 ( V_39 , V_40 ) ;
if ( ! V_41 ) {
V_24 = - V_62 ;
goto V_15;
}
F_55 ( & V_82 -> V_54 ) ;
F_56 ( V_82 ) ;
if ( F_70 ( V_115 , V_41 , V_40 ) != 0 )
V_24 = - V_116 ;
F_28 ( V_41 ) ;
return V_40 ;
V_15:
F_55 ( & V_82 -> V_54 ) ;
F_56 ( V_82 ) ;
return V_24 ;
}
static void F_71 ( struct V_47 * V_47 )
{
struct V_38 * V_39 = V_47 -> V_55 . V_56 ;
if ( ! V_39 )
return;
memset ( V_39 -> V_91 , 0 , V_39 -> V_21 ) ;
F_28 ( V_47 -> V_55 . V_56 ) ;
}
static void F_72 ( void )
{
if ( V_71 )
F_73 ( V_71 ) ;
if ( V_69 )
F_73 ( V_69 ) ;
}
static int T_5 F_74 ( void )
{
int V_24 ;
V_69 = F_75 ( V_70 , 0 , V_4 ) ;
if ( F_3 ( V_69 ) ) {
F_13 ( L_33 ,
V_70 ) ;
return F_5 ( V_69 ) ;
}
V_71 = F_75 ( V_72 , 0 , V_4 ) ;
if ( F_3 ( V_71 ) ) {
F_13 ( L_33 ,
V_72 ) ;
V_24 = F_5 ( V_71 ) ;
goto V_117;
}
return 0 ;
V_117:
F_73 ( V_69 ) ;
return V_24 ;
}
static int T_5 F_76 ( void )
{
int V_24 ;
V_24 = F_74 () ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_77 ( & V_118 ) ;
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
F_79 ( & V_118 ) ;
}
