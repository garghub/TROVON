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
int V_13 ;
if ( ! strncmp ( V_11 , V_14 , V_15 ) )
V_13 = V_15 ;
else if ( ! strncmp ( V_11 , V_16 , V_17 ) )
V_13 = V_17 ;
else
return - V_10 ;
if ( ! V_11 [ V_13 ] )
return - V_10 ;
if ( V_12 && strncmp ( V_11 , V_12 , V_13 ) )
return - V_10 ;
return 0 ;
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
goto V_34;
}
if ( F_10 ( * V_20 , NULL ) < 0 ) {
F_13 ( L_9
L_10 , * V_20 ) ;
goto V_34;
}
if ( V_21 ) {
* V_21 = F_12 ( & V_18 , L_6 ) ;
if ( ! * V_21 ) {
F_13 ( L_11 ) ;
goto V_34;
}
}
switch ( V_25 ) {
case V_35 :
if ( ! V_21 ) {
F_13 ( L_12
L_13 , V_28 ) ;
break;
}
V_24 = 0 ;
break;
case V_36 :
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
case V_37 :
if ( V_21 ) {
F_13 ( L_12
L_15 ,
V_28 ) ;
break;
}
V_24 = 0 ;
break;
case V_38 :
F_13 ( L_16 ,
V_28 ) ;
break;
}
V_34:
return V_24 ;
}
static char * F_15 ( struct V_39 * V_40 ,
T_2 V_41 )
{
char * V_42 , * V_43 ;
T_3 * V_44 = V_40 -> V_44 ;
int V_45 ;
int V_8 ;
V_42 = F_16 ( V_41 + 1 , V_46 ) ;
if ( ! V_42 )
goto V_34;
V_42 [ V_41 ] = '\0' ;
V_45 = sprintf ( V_42 , L_17 , V_40 -> V_19 ,
V_40 -> V_20 , V_40 -> V_47 ) ;
V_43 = & V_42 [ V_45 ] ;
for ( V_8 = 0 ; V_8 < ( V_41 - V_45 ) / 2 ; V_8 ++ )
V_43 = F_17 ( V_43 , V_44 [ V_8 ] ) ;
V_34:
return V_42 ;
}
static struct V_48 * F_18 ( const char * V_20 , const T_3 * * V_49 ,
T_2 * V_50 )
{
const struct V_51 * V_52 ;
struct V_48 * V_53 ;
V_53 = F_19 ( & V_54 , V_20 , NULL ) ;
if ( F_3 ( V_53 ) )
goto error;
F_20 ( & V_53 -> V_55 ) ;
V_52 = F_21 ( V_53 ) ;
* V_49 = V_52 -> V_56 ;
* V_50 = V_52 -> V_47 ;
error:
return V_53 ;
}
static int F_22 ( struct V_57 * V_2 , T_3 * V_58 ,
const T_3 * V_59 , unsigned int V_60 )
{
F_23 ( V_61 , V_2 ) ;
int V_62 ;
V_61 -> V_2 = V_2 ;
V_61 -> V_63 = 0 ;
V_62 = F_24 ( V_61 , V_59 , V_60 , V_58 ) ;
F_25 ( V_61 ) ;
return V_62 ;
}
static int F_26 ( T_3 * V_58 , const T_3 * V_48 , unsigned int V_64 ,
const T_3 * V_59 , unsigned int V_60 )
{
struct V_57 * V_2 ;
int V_62 ;
V_2 = F_27 ( V_65 , 0 , V_4 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_18 ,
V_65 , F_5 ( V_2 ) ) ;
return F_5 ( V_2 ) ;
}
V_62 = F_28 ( V_2 , V_48 , V_64 ) ;
if ( ! V_62 )
V_62 = F_22 ( V_2 , V_58 , V_59 , V_60 ) ;
F_29 ( V_2 ) ;
return V_62 ;
}
static int F_30 ( T_3 * V_66 , enum V_67 V_68 ,
const T_3 * V_49 , T_2 V_50 )
{
T_3 * V_69 ;
unsigned int V_70 ;
int V_24 ;
V_70 = strlen ( L_19 ) + 1 + V_50 ;
if ( V_70 < V_71 )
V_70 = V_71 ;
V_69 = F_31 ( V_70 , V_46 ) ;
if ( ! V_69 )
return - V_72 ;
if ( V_68 )
strcpy ( V_69 , L_19 ) ;
else
strcpy ( V_69 , L_20 ) ;
memcpy ( V_69 + strlen ( V_69 ) + 1 , V_49 ,
V_50 ) ;
V_24 = F_22 ( V_73 , V_66 , V_69 , V_70 ) ;
F_32 ( V_69 ) ;
return V_24 ;
}
static struct V_74 * F_33 ( const T_3 * V_48 ,
unsigned int V_75 )
{
struct V_74 * V_76 ;
struct V_1 * V_2 ;
int V_24 ;
V_2 = F_2 ( V_3 , 0 , V_4 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_21 ,
V_3 , F_5 ( V_2 ) ) ;
return F_34 ( V_2 ) ;
}
V_24 = F_35 ( V_2 , V_48 , V_75 ) ;
if ( V_24 < 0 ) {
F_4 ( L_22 , V_24 ) ;
F_8 ( V_2 ) ;
return F_36 ( V_24 ) ;
}
V_76 = F_37 ( V_2 , V_46 ) ;
if ( ! V_76 ) {
F_4 ( L_23 ,
V_3 ) ;
F_8 ( V_2 ) ;
return F_36 ( - V_72 ) ;
}
F_38 ( V_76 , 0 , NULL , NULL ) ;
return V_76 ;
}
static struct V_48 * F_39 ( struct V_39 * V_40 ,
const T_3 * * V_49 , T_2 * V_50 )
{
struct V_48 * V_77 = F_36 ( - V_10 ) ;
if ( ! strncmp ( V_40 -> V_20 , V_14 ,
V_15 ) ) {
V_77 = F_40 ( V_40 -> V_20 +
V_15 ,
V_49 , V_50 ) ;
} else if ( ! strncmp ( V_40 -> V_20 , V_16 ,
V_17 ) ) {
V_77 = F_18 ( V_40 -> V_20 +
V_17 ,
V_49 , V_50 ) ;
} else
goto V_34;
if ( F_3 ( V_77 ) ) {
int V_24 = F_5 ( V_77 ) ;
if ( V_24 == - V_78 )
F_13 ( L_24 ,
V_40 -> V_20 ) ;
else
F_13 ( L_25 ,
V_40 -> V_20 ) ;
goto V_34;
}
F_41 ( * V_49 , * V_50 ) ;
V_34:
return V_77 ;
}
static int F_42 ( struct V_39 * V_40 ,
const T_3 * V_66 ,
unsigned int V_79 )
{
struct V_80 V_81 [ 2 ] ;
struct V_80 V_82 [ 1 ] ;
struct V_1 * V_2 ;
struct V_74 * V_76 ;
unsigned int V_83 ;
T_3 V_44 [ V_84 ] ;
int V_24 ;
V_83 = F_43 ( V_40 -> V_21 , V_6 ) ;
V_76 = F_33 ( V_66 , V_79 ) ;
V_24 = F_5 ( V_76 ) ;
if ( F_3 ( V_76 ) )
goto V_34;
F_44 ( V_40 ) ;
F_45 ( V_81 , 2 ) ;
F_46 ( & V_81 [ 0 ] , V_40 -> V_85 ,
V_40 -> V_21 ) ;
F_47 ( & V_81 [ 1 ] , F_48 ( 0 ) , V_84 , 0 ) ;
F_45 ( V_82 , 1 ) ;
F_46 ( V_82 , V_40 -> V_86 , V_83 ) ;
memcpy ( V_44 , V_40 -> V_44 , sizeof( V_44 ) ) ;
F_49 ( V_76 , V_81 , V_82 , V_83 , V_44 ) ;
V_24 = F_50 ( V_76 ) ;
V_2 = F_51 ( V_76 ) ;
F_52 ( V_76 ) ;
F_8 ( V_2 ) ;
if ( V_24 < 0 )
F_4 ( L_26 , V_24 ) ;
else
F_53 ( V_40 , V_83 ) ;
V_34:
return V_24 ;
}
static int F_54 ( struct V_39 * V_40 ,
const T_3 * V_49 , T_2 V_50 )
{
T_3 V_66 [ V_71 ] ;
T_3 * V_58 ;
int V_24 ;
V_24 = F_30 ( V_66 , V_87 , V_49 , V_50 ) ;
if ( V_24 < 0 )
goto V_34;
V_58 = V_40 -> V_19 + V_40 -> V_88 ;
V_24 = F_26 ( V_58 , V_66 , sizeof V_66 ,
V_40 -> V_19 , V_40 -> V_88 ) ;
if ( ! V_24 )
F_55 ( NULL , V_58 , V_71 ) ;
V_34:
F_56 ( V_66 , sizeof( V_66 ) ) ;
return V_24 ;
}
static int F_57 ( struct V_39 * V_40 ,
const T_3 * V_19 , const T_3 * V_49 ,
T_2 V_50 )
{
T_3 V_66 [ V_71 ] ;
T_3 V_58 [ V_71 ] ;
int V_24 ;
char * V_27 ;
unsigned short V_45 ;
V_24 = F_30 ( V_66 , V_87 , V_49 , V_50 ) ;
if ( V_24 < 0 )
goto V_34;
V_45 = V_40 -> V_88 ;
if ( ! V_19 ) {
V_27 = V_40 -> V_20 ;
V_45 -= strlen ( V_40 -> V_19 ) + 1 ;
} else
V_27 = V_40 -> V_19 ;
V_24 = F_26 ( V_58 , V_66 , sizeof V_66 , V_27 , V_45 ) ;
if ( V_24 < 0 )
goto V_34;
V_24 = F_58 ( V_58 , V_40 -> V_19 + V_40 -> V_88 ,
sizeof( V_58 ) ) ;
if ( V_24 ) {
V_24 = - V_10 ;
F_55 ( L_27 ,
V_40 -> V_19 + V_40 -> V_88 ,
V_71 ) ;
F_55 ( L_28 , V_58 , V_71 ) ;
}
V_34:
F_56 ( V_66 , sizeof( V_66 ) ) ;
return V_24 ;
}
static int F_59 ( struct V_39 * V_40 ,
const T_3 * V_66 ,
unsigned int V_79 )
{
struct V_80 V_81 [ 1 ] ;
struct V_80 V_82 [ 2 ] ;
struct V_1 * V_2 ;
struct V_74 * V_76 ;
unsigned int V_83 ;
T_3 V_44 [ V_84 ] ;
T_3 * V_89 ;
int V_24 ;
V_89 = F_16 ( V_84 , V_46 ) ;
if ( ! V_89 )
return - V_72 ;
V_83 = F_43 ( V_40 -> V_21 , V_6 ) ;
V_76 = F_33 ( V_66 , V_79 ) ;
V_24 = F_5 ( V_76 ) ;
if ( F_3 ( V_76 ) )
goto V_34;
F_53 ( V_40 , V_83 ) ;
F_45 ( V_81 , 1 ) ;
F_45 ( V_82 , 2 ) ;
F_46 ( V_81 , V_40 -> V_86 , V_83 ) ;
F_46 ( & V_82 [ 0 ] , V_40 -> V_85 ,
V_40 -> V_21 ) ;
F_46 ( & V_82 [ 1 ] , V_89 , V_84 ) ;
memcpy ( V_44 , V_40 -> V_44 , sizeof( V_44 ) ) ;
F_49 ( V_76 , V_81 , V_82 , V_83 , V_44 ) ;
V_24 = F_60 ( V_76 ) ;
V_2 = F_51 ( V_76 ) ;
F_52 ( V_76 ) ;
F_8 ( V_2 ) ;
if ( V_24 < 0 )
goto V_34;
F_44 ( V_40 ) ;
V_34:
F_61 ( V_89 ) ;
return V_24 ;
}
static struct V_39 * F_62 ( struct V_48 * V_48 ,
const char * V_19 ,
const char * V_20 ,
const char * V_47 )
{
struct V_39 * V_40 = NULL ;
unsigned short V_88 ;
unsigned short V_21 ;
unsigned short V_90 ;
unsigned int V_83 ;
unsigned int V_91 ;
long V_92 ;
int V_24 ;
V_24 = F_63 ( V_47 , 10 , & V_92 ) ;
if ( V_24 < 0 || V_92 < V_93 || V_92 > V_94 )
return F_36 ( - V_10 ) ;
V_91 = ( ! V_19 ) ? strlen ( V_95 ) : strlen ( V_19 ) ;
V_21 = V_92 ;
V_90 = V_21 ;
if ( V_19 && ! strcmp ( V_19 , V_96 ) ) {
if ( V_92 != V_97 ) {
F_4 ( L_29
L_30 ,
V_97 ) ;
return F_36 ( - V_10 ) ;
}
V_21 = V_97 ;
V_90 = sizeof( struct V_98 ) ;
}
V_83 = F_43 ( V_21 , V_6 ) ;
V_88 = V_91 + 1 + strlen ( V_20 ) + 1
+ strlen ( V_47 ) + 1 + V_5 + 1 + V_83 ;
V_24 = F_64 ( V_48 , V_90 + V_88
+ V_71 + 1 ) ;
if ( V_24 < 0 )
return F_36 ( V_24 ) ;
V_40 = F_31 ( sizeof( * V_40 ) + V_90 +
V_88 + V_71 + 1 , V_46 ) ;
if ( ! V_40 )
return F_36 ( - V_72 ) ;
V_40 -> V_90 = V_90 ;
V_40 -> V_21 = V_21 ;
V_40 -> V_88 = V_88 ;
return V_40 ;
}
static int F_65 ( struct V_39 * V_40 ,
const char * V_19 , const char * V_22 )
{
struct V_48 * V_77 ;
T_3 V_66 [ V_71 ] ;
const T_3 * V_49 ;
T_3 * V_99 ;
const char * V_100 ;
unsigned int V_83 ;
T_2 V_50 ;
T_2 V_101 ;
int V_24 ;
V_83 = F_43 ( V_40 -> V_21 , V_6 ) ;
V_101 = ( V_5 + 1 + V_83 + V_71 ) * 2 ;
if ( strlen ( V_22 ) != V_101 )
return - V_10 ;
V_100 = V_22 + ( 2 * V_5 ) + 2 ;
V_24 = F_66 ( V_40 -> V_44 , V_22 , V_5 ) ;
if ( V_24 < 0 )
return - V_10 ;
V_24 = F_66 ( V_40 -> V_86 , V_100 ,
V_83 ) ;
if ( V_24 < 0 )
return - V_10 ;
V_99 = V_40 -> V_19 + V_40 -> V_88 ;
V_24 = F_66 ( V_99 , V_100 + ( V_83 * 2 ) ,
V_71 ) ;
if ( V_24 < 0 )
return - V_10 ;
V_77 = F_39 ( V_40 , & V_49 , & V_50 ) ;
if ( F_3 ( V_77 ) )
return F_5 ( V_77 ) ;
V_24 = F_57 ( V_40 , V_19 , V_49 , V_50 ) ;
if ( V_24 < 0 ) {
F_4 ( L_31 , V_24 ) ;
goto V_34;
}
V_24 = F_30 ( V_66 , V_102 , V_49 , V_50 ) ;
if ( V_24 < 0 )
goto V_34;
V_24 = F_59 ( V_40 , V_66 , sizeof V_66 ) ;
if ( V_24 < 0 )
F_4 ( L_32 , V_24 ) ;
V_34:
F_67 ( & V_77 -> V_55 ) ;
F_68 ( V_77 ) ;
F_56 ( V_66 , sizeof( V_66 ) ) ;
return V_24 ;
}
static void F_69 ( struct V_39 * V_40 ,
const char * V_19 , const char * V_20 ,
const char * V_47 )
{
unsigned int V_91 ;
V_91 = ( ! V_19 ) ? strlen ( V_95 ) : strlen ( V_19 ) ;
V_40 -> V_19 = V_40 -> V_103 + V_40 -> V_90 ;
V_40 -> V_20 = V_40 -> V_19 + V_91 + 1 ;
V_40 -> V_47 = V_40 -> V_20 + strlen ( V_20 ) + 1 ;
V_40 -> V_44 = V_40 -> V_47 + strlen ( V_47 ) + 1 ;
V_40 -> V_86 = V_40 -> V_44 + V_5 + 1 ;
V_40 -> V_85 = V_40 -> V_103 ;
if ( ! V_19 )
memcpy ( V_40 -> V_19 , V_95 , V_91 ) ;
else {
if ( ! strcmp ( V_19 , V_96 ) )
V_40 -> V_85 =
F_70 ( (struct V_98 * ) V_40 -> V_103 ) ;
memcpy ( V_40 -> V_19 , V_19 , V_91 ) ;
}
memcpy ( V_40 -> V_20 , V_20 , strlen ( V_20 ) ) ;
memcpy ( V_40 -> V_47 , V_47 , strlen ( V_47 ) ) ;
}
static int F_71 ( struct V_39 * V_40 ,
const char * V_104 , const char * V_19 ,
const char * V_20 , const char * V_47 ,
const char * V_22 )
{
int V_24 = 0 ;
if ( V_19 && ! strcmp ( V_19 , V_96 ) ) {
V_24 = F_9 ( V_104 ) ;
if ( V_24 < 0 )
return V_24 ;
F_72 ( (struct V_98 * ) V_40 -> V_103 ,
V_104 ) ;
}
F_69 ( V_40 , V_19 , V_20 , V_47 ) ;
if ( ! V_22 ) {
F_73 ( V_40 -> V_44 , V_5 ) ;
F_73 ( V_40 -> V_85 ,
V_40 -> V_21 ) ;
} else
V_24 = F_65 ( V_40 , V_19 , V_22 ) ;
return V_24 ;
}
static int F_74 ( struct V_48 * V_48 ,
struct V_105 * V_106 )
{
struct V_39 * V_40 = NULL ;
char * V_18 = NULL ;
const char * V_19 = NULL ;
char * V_20 = NULL ;
char * V_21 = NULL ;
char * V_22 = NULL ;
T_2 V_47 = V_106 -> V_47 ;
int V_24 ;
if ( V_47 <= 0 || V_47 > 32767 || ! V_106 -> V_56 )
return - V_10 ;
V_18 = F_16 ( V_47 + 1 , V_46 ) ;
if ( ! V_18 )
return - V_72 ;
V_18 [ V_47 ] = 0 ;
memcpy ( V_18 , V_106 -> V_56 , V_47 ) ;
V_24 = F_11 ( V_18 , & V_19 , & V_20 ,
& V_21 , & V_22 ) ;
if ( V_24 < 0 )
goto V_34;
V_40 = F_62 ( V_48 , V_19 , V_20 ,
V_21 ) ;
if ( F_3 ( V_40 ) ) {
V_24 = F_5 ( V_40 ) ;
goto V_34;
}
V_24 = F_71 ( V_40 , V_48 -> V_107 , V_19 , V_20 ,
V_21 , V_22 ) ;
if ( V_24 < 0 ) {
F_32 ( V_40 ) ;
goto V_34;
}
F_75 ( V_48 , V_40 ) ;
V_34:
F_32 ( V_18 ) ;
return V_24 ;
}
static void F_76 ( struct V_108 * V_109 )
{
struct V_39 * V_40 ;
V_40 = F_77 ( V_109 , struct V_39 , V_109 ) ;
F_32 ( V_40 ) ;
}
static int F_78 ( struct V_48 * V_48 , struct V_105 * V_106 )
{
struct V_39 * V_40 = V_48 -> V_110 . V_56 [ 0 ] ;
struct V_39 * V_111 ;
char * V_59 ;
char * V_112 = NULL ;
const char * V_19 = NULL ;
T_2 V_47 = V_106 -> V_47 ;
int V_24 = 0 ;
if ( F_79 ( V_113 , & V_48 -> V_63 ) )
return - V_114 ;
if ( V_47 <= 0 || V_47 > 32767 || ! V_106 -> V_56 )
return - V_10 ;
V_59 = F_16 ( V_47 + 1 , V_46 ) ;
if ( ! V_59 )
return - V_72 ;
V_59 [ V_47 ] = 0 ;
memcpy ( V_59 , V_106 -> V_56 , V_47 ) ;
V_24 = F_11 ( V_59 , & V_19 , & V_112 , NULL , NULL ) ;
if ( V_24 < 0 )
goto V_34;
V_24 = F_10 ( V_112 , V_40 -> V_20 ) ;
if ( V_24 < 0 )
goto V_34;
V_111 = F_62 ( V_48 , V_40 -> V_19 ,
V_112 , V_40 -> V_47 ) ;
if ( F_3 ( V_111 ) ) {
V_24 = F_5 ( V_111 ) ;
goto V_34;
}
F_69 ( V_111 , V_40 -> V_19 , V_112 ,
V_40 -> V_47 ) ;
memcpy ( V_111 -> V_44 , V_40 -> V_44 , V_5 ) ;
memcpy ( V_111 -> V_103 , V_40 -> V_103 ,
V_40 -> V_90 ) ;
F_75 ( V_48 , V_111 ) ;
F_80 ( & V_40 -> V_109 , F_76 ) ;
V_34:
F_32 ( V_59 ) ;
return V_24 ;
}
static long F_81 ( const struct V_48 * V_48 , char T_4 * V_115 ,
T_2 V_60 )
{
struct V_39 * V_40 ;
struct V_48 * V_77 ;
const T_3 * V_49 ;
T_2 V_50 ;
char V_66 [ V_71 ] ;
char * V_42 ;
T_2 V_41 ;
int V_24 ;
V_40 = F_82 ( V_48 ) ;
V_41 = V_40 -> V_88 + V_5 + 1
+ F_43 ( V_40 -> V_21 , V_6 )
+ ( V_71 * 2 ) ;
if ( ! V_115 || V_60 < V_41 )
return V_41 ;
V_77 = F_39 ( V_40 , & V_49 , & V_50 ) ;
if ( F_3 ( V_77 ) )
return F_5 ( V_77 ) ;
V_24 = F_30 ( V_66 , V_102 , V_49 , V_50 ) ;
if ( V_24 < 0 )
goto V_34;
V_24 = F_42 ( V_40 , V_66 , sizeof V_66 ) ;
if ( V_24 < 0 )
goto V_34;
V_24 = F_54 ( V_40 , V_49 , V_50 ) ;
if ( V_24 < 0 )
goto V_34;
V_42 = F_15 ( V_40 , V_41 ) ;
if ( ! V_42 ) {
V_24 = - V_72 ;
goto V_34;
}
F_67 ( & V_77 -> V_55 ) ;
F_68 ( V_77 ) ;
F_56 ( V_66 , sizeof( V_66 ) ) ;
if ( F_83 ( V_115 , V_42 , V_41 ) != 0 )
V_24 = - V_116 ;
F_32 ( V_42 ) ;
return V_41 ;
V_34:
F_67 ( & V_77 -> V_55 ) ;
F_68 ( V_77 ) ;
F_56 ( V_66 , sizeof( V_66 ) ) ;
return V_24 ;
}
static void F_84 ( struct V_48 * V_48 )
{
F_32 ( V_48 -> V_110 . V_56 [ 0 ] ) ;
}
static int T_5 F_85 ( void )
{
int V_24 ;
V_73 = F_27 ( V_117 , 0 , V_4 ) ;
if ( F_3 ( V_73 ) ) {
F_4 ( L_33 ,
V_117 , F_5 ( V_73 ) ) ;
return F_5 ( V_73 ) ;
}
V_24 = F_1 () ;
if ( V_24 < 0 )
goto V_34;
V_24 = F_86 ( & V_118 ) ;
if ( V_24 < 0 )
goto V_34;
return 0 ;
V_34:
F_29 ( V_73 ) ;
return V_24 ;
}
static void T_6 F_87 ( void )
{
F_29 ( V_73 ) ;
F_88 ( & V_118 ) ;
}
