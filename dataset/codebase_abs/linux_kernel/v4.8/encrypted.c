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
static struct V_47 * F_18 ( const char * V_20 , const T_3 * * V_48 ,
T_2 * V_49 )
{
const struct V_50 * V_51 ;
struct V_47 * V_52 ;
V_52 = F_19 ( & V_53 , V_20 , NULL ) ;
if ( F_3 ( V_52 ) )
goto error;
F_20 ( & V_52 -> V_54 ) ;
V_51 = V_50 ( V_52 ) ;
* V_48 = V_51 -> V_55 ;
* V_49 = V_51 -> V_46 ;
error:
return V_52 ;
}
static struct V_56 * F_21 ( struct V_57 * V_58 )
{
struct V_56 * V_56 ;
int V_59 ;
V_59 = sizeof( struct V_60 ) + F_22 ( V_58 ) ;
V_56 = F_16 ( V_59 , V_45 ) ;
if ( ! V_56 )
return F_23 ( - V_61 ) ;
V_56 -> V_62 . V_2 = V_58 ;
V_56 -> V_62 . V_63 = 0x0 ;
return V_56 ;
}
static int F_24 ( T_3 * V_64 , const T_3 * V_47 , unsigned int V_65 ,
const T_3 * V_66 , unsigned int V_67 )
{
struct V_56 * V_56 ;
int V_24 ;
V_56 = F_21 ( V_68 ) ;
if ( F_3 ( V_56 ) ) {
F_13 ( L_18 , V_69 ) ;
return F_5 ( V_56 ) ;
}
V_24 = F_25 ( V_68 , V_47 , V_65 ) ;
if ( ! V_24 )
V_24 = F_26 ( & V_56 -> V_62 , V_66 , V_67 , V_64 ) ;
F_27 ( V_56 ) ;
return V_24 ;
}
static int F_28 ( T_3 * V_64 , const T_3 * V_66 , unsigned int V_67 )
{
struct V_56 * V_56 ;
int V_24 ;
V_56 = F_21 ( V_70 ) ;
if ( F_3 ( V_56 ) ) {
F_13 ( L_18 , V_71 ) ;
return F_5 ( V_56 ) ;
}
V_24 = F_26 ( & V_56 -> V_62 , V_66 , V_67 , V_64 ) ;
F_27 ( V_56 ) ;
return V_24 ;
}
static int F_29 ( T_3 * V_72 , enum V_73 V_74 ,
const T_3 * V_48 , T_2 V_49 )
{
T_3 * V_75 ;
unsigned int V_76 ;
int V_24 ;
V_76 = strlen ( L_19 ) + 1 + V_49 ;
if ( V_76 < V_77 )
V_76 = V_77 ;
V_75 = F_30 ( V_76 , V_45 ) ;
if ( ! V_75 ) {
F_4 ( L_20 ) ;
return - V_61 ;
}
if ( V_74 )
strcpy ( V_75 , L_19 ) ;
else
strcpy ( V_75 , L_21 ) ;
memcpy ( V_75 + strlen ( V_75 ) + 1 , V_48 ,
V_49 ) ;
V_24 = F_28 ( V_72 , V_75 , V_76 ) ;
F_27 ( V_75 ) ;
return V_24 ;
}
static struct V_78 * F_31 ( const T_3 * V_47 ,
unsigned int V_79 )
{
struct V_78 * V_80 ;
struct V_1 * V_2 ;
int V_24 ;
V_2 = F_2 ( V_3 , 0 , V_4 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_22 ,
V_3 , F_5 ( V_2 ) ) ;
return F_32 ( V_2 ) ;
}
V_24 = F_33 ( V_2 , V_47 , V_79 ) ;
if ( V_24 < 0 ) {
F_4 ( L_23 , V_24 ) ;
F_8 ( V_2 ) ;
return F_23 ( V_24 ) ;
}
V_80 = F_34 ( V_2 , V_45 ) ;
if ( ! V_80 ) {
F_4 ( L_24 ,
V_3 ) ;
F_8 ( V_2 ) ;
return F_23 ( - V_61 ) ;
}
F_35 ( V_80 , 0 , NULL , NULL ) ;
return V_80 ;
}
static struct V_47 * F_36 ( struct V_38 * V_39 ,
const T_3 * * V_48 , T_2 * V_49 )
{
struct V_47 * V_81 = NULL ;
if ( ! strncmp ( V_39 -> V_20 , V_13 ,
V_14 ) ) {
V_81 = F_37 ( V_39 -> V_20 +
V_14 ,
V_48 , V_49 ) ;
} else if ( ! strncmp ( V_39 -> V_20 , V_16 ,
V_17 ) ) {
V_81 = F_18 ( V_39 -> V_20 +
V_17 ,
V_48 , V_49 ) ;
} else
goto V_15;
if ( F_3 ( V_81 ) ) {
int V_24 = F_5 ( V_81 ) ;
if ( V_24 == - V_82 )
F_13 ( L_25 ,
V_39 -> V_20 ) ;
else
F_13 ( L_26 ,
V_39 -> V_20 ) ;
goto V_15;
}
F_38 ( * V_48 , * V_49 ) ;
V_15:
return V_81 ;
}
static int F_39 ( struct V_38 * V_39 ,
const T_3 * V_72 ,
unsigned int V_83 )
{
struct V_84 V_85 [ 2 ] ;
struct V_84 V_86 [ 1 ] ;
struct V_1 * V_2 ;
struct V_78 * V_80 ;
unsigned int V_87 ;
T_3 V_43 [ V_88 ] ;
unsigned int V_89 ;
char V_90 [ 16 ] ;
int V_24 ;
V_87 = F_40 ( V_39 -> V_21 , V_6 ) ;
V_89 = V_87 - V_39 -> V_21 ;
V_80 = F_31 ( V_72 , V_83 ) ;
V_24 = F_5 ( V_80 ) ;
if ( F_3 ( V_80 ) )
goto V_15;
F_41 ( V_39 ) ;
memset ( V_90 , 0 , sizeof V_90 ) ;
F_42 ( V_85 , 2 ) ;
F_43 ( & V_85 [ 0 ] , V_39 -> V_91 ,
V_39 -> V_21 ) ;
F_43 ( & V_85 [ 1 ] , V_90 , V_89 ) ;
F_42 ( V_86 , 1 ) ;
F_43 ( V_86 , V_39 -> V_92 , V_87 ) ;
memcpy ( V_43 , V_39 -> V_43 , sizeof( V_43 ) ) ;
F_44 ( V_80 , V_85 , V_86 , V_87 , V_43 ) ;
V_24 = F_45 ( V_80 ) ;
V_2 = F_46 ( V_80 ) ;
F_47 ( V_80 ) ;
F_8 ( V_2 ) ;
if ( V_24 < 0 )
F_4 ( L_27 , V_24 ) ;
else
F_48 ( V_39 , V_87 ) ;
V_15:
return V_24 ;
}
static int F_49 ( struct V_38 * V_39 ,
const T_3 * V_48 , T_2 V_49 )
{
T_3 V_72 [ V_77 ] ;
T_3 * V_64 ;
int V_24 ;
V_24 = F_29 ( V_72 , V_93 , V_48 , V_49 ) ;
if ( V_24 < 0 )
goto V_15;
V_64 = V_39 -> V_19 + V_39 -> V_94 ;
V_24 = F_24 ( V_64 , V_72 , sizeof V_72 ,
V_39 -> V_19 , V_39 -> V_94 ) ;
if ( ! V_24 )
F_50 ( NULL , V_64 , V_77 ) ;
V_15:
return V_24 ;
}
static int F_51 ( struct V_38 * V_39 ,
const T_3 * V_19 , const T_3 * V_48 ,
T_2 V_49 )
{
T_3 V_72 [ V_77 ] ;
T_3 V_64 [ V_77 ] ;
int V_24 ;
char * V_27 ;
unsigned short V_44 ;
V_24 = F_29 ( V_72 , V_93 , V_48 , V_49 ) ;
if ( V_24 < 0 )
goto V_15;
V_44 = V_39 -> V_94 ;
if ( ! V_19 ) {
V_27 = V_39 -> V_20 ;
V_44 -= strlen ( V_39 -> V_19 ) + 1 ;
} else
V_27 = V_39 -> V_19 ;
V_24 = F_24 ( V_64 , V_72 , sizeof V_72 , V_27 , V_44 ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = memcmp ( V_64 , V_39 -> V_19 + V_39 -> V_94 ,
sizeof V_64 ) ;
if ( V_24 ) {
V_24 = - V_10 ;
F_50 ( L_28 ,
V_39 -> V_19 + V_39 -> V_94 ,
V_77 ) ;
F_50 ( L_29 , V_64 , V_77 ) ;
}
V_15:
return V_24 ;
}
static int F_52 ( struct V_38 * V_39 ,
const T_3 * V_72 ,
unsigned int V_83 )
{
struct V_84 V_85 [ 1 ] ;
struct V_84 V_86 [ 2 ] ;
struct V_1 * V_2 ;
struct V_78 * V_80 ;
unsigned int V_87 ;
T_3 V_43 [ V_88 ] ;
char V_90 [ 16 ] ;
int V_24 ;
V_87 = F_40 ( V_39 -> V_21 , V_6 ) ;
V_80 = F_31 ( V_72 , V_83 ) ;
V_24 = F_5 ( V_80 ) ;
if ( F_3 ( V_80 ) )
goto V_15;
F_48 ( V_39 , V_87 ) ;
memset ( V_90 , 0 , sizeof V_90 ) ;
F_42 ( V_85 , 1 ) ;
F_42 ( V_86 , 2 ) ;
F_43 ( V_85 , V_39 -> V_92 , V_87 ) ;
F_43 ( & V_86 [ 0 ] , V_39 -> V_91 ,
V_39 -> V_21 ) ;
F_43 ( & V_86 [ 1 ] , V_90 , sizeof V_90 ) ;
memcpy ( V_43 , V_39 -> V_43 , sizeof( V_43 ) ) ;
F_44 ( V_80 , V_85 , V_86 , V_87 , V_43 ) ;
V_24 = F_53 ( V_80 ) ;
V_2 = F_46 ( V_80 ) ;
F_47 ( V_80 ) ;
F_8 ( V_2 ) ;
if ( V_24 < 0 )
goto V_15;
F_41 ( V_39 ) ;
V_15:
return V_24 ;
}
static struct V_38 * F_54 ( struct V_47 * V_47 ,
const char * V_19 ,
const char * V_20 ,
const char * V_46 )
{
struct V_38 * V_39 = NULL ;
unsigned short V_94 ;
unsigned short V_21 ;
unsigned short V_95 ;
unsigned int V_87 ;
unsigned int V_96 ;
long V_97 ;
int V_24 ;
V_24 = F_55 ( V_46 , 10 , & V_97 ) ;
if ( V_24 < 0 || V_97 < V_98 || V_97 > V_99 )
return F_23 ( - V_10 ) ;
V_96 = ( ! V_19 ) ? strlen ( V_100 ) : strlen ( V_19 ) ;
V_21 = V_97 ;
V_95 = V_21 ;
if ( V_19 && ! strcmp ( V_19 , V_101 ) ) {
if ( V_97 != V_102 ) {
F_4 ( L_30
L_31 ,
V_102 ) ;
return F_23 ( - V_10 ) ;
}
V_21 = V_102 ;
V_95 = sizeof( struct V_103 ) ;
}
V_87 = F_40 ( V_21 , V_6 ) ;
V_94 = V_96 + 1 + strlen ( V_20 ) + 1
+ strlen ( V_46 ) + 1 + V_5 + 1 + V_87 ;
V_24 = F_56 ( V_47 , V_95 + V_94
+ V_77 + 1 ) ;
if ( V_24 < 0 )
return F_23 ( V_24 ) ;
V_39 = F_30 ( sizeof( * V_39 ) + V_95 +
V_94 + V_77 + 1 , V_45 ) ;
if ( ! V_39 )
return F_23 ( - V_61 ) ;
V_39 -> V_95 = V_95 ;
V_39 -> V_21 = V_21 ;
V_39 -> V_94 = V_94 ;
return V_39 ;
}
static int F_57 ( struct V_38 * V_39 ,
const char * V_19 , const char * V_22 )
{
struct V_47 * V_81 ;
T_3 V_72 [ V_77 ] ;
const T_3 * V_48 ;
T_3 * V_104 ;
const char * V_105 ;
unsigned int V_87 ;
T_2 V_49 ;
T_2 V_106 ;
int V_24 ;
V_87 = F_40 ( V_39 -> V_21 , V_6 ) ;
V_106 = ( V_5 + 1 + V_87 + V_77 ) * 2 ;
if ( strlen ( V_22 ) != V_106 )
return - V_10 ;
V_105 = V_22 + ( 2 * V_5 ) + 2 ;
V_24 = F_58 ( V_39 -> V_43 , V_22 , V_5 ) ;
if ( V_24 < 0 )
return - V_10 ;
V_24 = F_58 ( V_39 -> V_92 , V_105 ,
V_87 ) ;
if ( V_24 < 0 )
return - V_10 ;
V_104 = V_39 -> V_19 + V_39 -> V_94 ;
V_24 = F_58 ( V_104 , V_105 + ( V_87 * 2 ) ,
V_77 ) ;
if ( V_24 < 0 )
return - V_10 ;
V_81 = F_36 ( V_39 , & V_48 , & V_49 ) ;
if ( F_3 ( V_81 ) )
return F_5 ( V_81 ) ;
V_24 = F_51 ( V_39 , V_19 , V_48 , V_49 ) ;
if ( V_24 < 0 ) {
F_4 ( L_32 , V_24 ) ;
goto V_15;
}
V_24 = F_29 ( V_72 , V_107 , V_48 , V_49 ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_52 ( V_39 , V_72 , sizeof V_72 ) ;
if ( V_24 < 0 )
F_4 ( L_33 , V_24 ) ;
V_15:
F_59 ( & V_81 -> V_54 ) ;
F_60 ( V_81 ) ;
return V_24 ;
}
static void F_61 ( struct V_38 * V_39 ,
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
F_62 ( (struct V_103 * ) V_39 -> V_108 ) ;
memcpy ( V_39 -> V_19 , V_19 , V_96 ) ;
}
memcpy ( V_39 -> V_20 , V_20 , strlen ( V_20 ) ) ;
memcpy ( V_39 -> V_46 , V_46 , strlen ( V_46 ) ) ;
}
static int F_63 ( struct V_38 * V_39 ,
const char * V_109 , const char * V_19 ,
const char * V_20 , const char * V_46 ,
const char * V_22 )
{
int V_24 = 0 ;
if ( V_19 && ! strcmp ( V_19 , V_101 ) ) {
V_24 = F_9 ( V_109 ) ;
if ( V_24 < 0 )
return V_24 ;
F_64 ( (struct V_103 * ) V_39 -> V_108 ,
V_109 ) ;
}
F_61 ( V_39 , V_19 , V_20 , V_46 ) ;
if ( ! V_22 ) {
F_65 ( V_39 -> V_43 , V_5 ) ;
F_65 ( V_39 -> V_91 ,
V_39 -> V_21 ) ;
} else
V_24 = F_57 ( V_39 , V_19 , V_22 ) ;
return V_24 ;
}
static int F_66 ( struct V_47 * V_47 ,
struct V_110 * V_111 )
{
struct V_38 * V_39 = NULL ;
char * V_18 = NULL ;
const char * V_19 = NULL ;
char * V_20 = NULL ;
char * V_21 = NULL ;
char * V_22 = NULL ;
T_2 V_46 = V_111 -> V_46 ;
int V_24 ;
if ( V_46 <= 0 || V_46 > 32767 || ! V_111 -> V_55 )
return - V_10 ;
V_18 = F_16 ( V_46 + 1 , V_45 ) ;
if ( ! V_18 )
return - V_61 ;
V_18 [ V_46 ] = 0 ;
memcpy ( V_18 , V_111 -> V_55 , V_46 ) ;
V_24 = F_11 ( V_18 , & V_19 , & V_20 ,
& V_21 , & V_22 ) ;
if ( V_24 < 0 )
goto V_15;
V_39 = F_54 ( V_47 , V_19 , V_20 ,
V_21 ) ;
if ( F_3 ( V_39 ) ) {
V_24 = F_5 ( V_39 ) ;
goto V_15;
}
V_24 = F_63 ( V_39 , V_47 -> V_112 , V_19 , V_20 ,
V_21 , V_22 ) ;
if ( V_24 < 0 ) {
F_27 ( V_39 ) ;
goto V_15;
}
F_67 ( V_47 , V_39 ) ;
V_15:
F_27 ( V_18 ) ;
return V_24 ;
}
static void F_68 ( struct V_113 * V_114 )
{
struct V_38 * V_39 ;
V_39 = F_69 ( V_114 , struct V_38 , V_114 ) ;
memset ( V_39 -> V_91 , 0 , V_39 -> V_21 ) ;
F_27 ( V_39 ) ;
}
static int F_70 ( struct V_47 * V_47 , struct V_110 * V_111 )
{
struct V_38 * V_39 = V_47 -> V_115 . V_55 [ 0 ] ;
struct V_38 * V_116 ;
char * V_66 ;
char * V_117 = NULL ;
const char * V_19 = NULL ;
T_2 V_46 = V_111 -> V_46 ;
int V_24 = 0 ;
if ( F_71 ( V_118 , & V_47 -> V_63 ) )
return - V_119 ;
if ( V_46 <= 0 || V_46 > 32767 || ! V_111 -> V_55 )
return - V_10 ;
V_66 = F_16 ( V_46 + 1 , V_45 ) ;
if ( ! V_66 )
return - V_61 ;
V_66 [ V_46 ] = 0 ;
memcpy ( V_66 , V_111 -> V_55 , V_46 ) ;
V_24 = F_11 ( V_66 , & V_19 , & V_117 , NULL , NULL ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_10 ( V_117 , V_39 -> V_20 ) ;
if ( V_24 < 0 )
goto V_15;
V_116 = F_54 ( V_47 , V_39 -> V_19 ,
V_117 , V_39 -> V_46 ) ;
if ( F_3 ( V_116 ) ) {
V_24 = F_5 ( V_116 ) ;
goto V_15;
}
F_61 ( V_116 , V_39 -> V_19 , V_117 ,
V_39 -> V_46 ) ;
memcpy ( V_116 -> V_43 , V_39 -> V_43 , V_5 ) ;
memcpy ( V_116 -> V_108 , V_39 -> V_108 ,
V_39 -> V_95 ) ;
F_67 ( V_47 , V_116 ) ;
F_72 ( & V_39 -> V_114 , F_68 ) ;
V_15:
F_27 ( V_66 ) ;
return V_24 ;
}
static long F_73 ( const struct V_47 * V_47 , char T_4 * V_120 ,
T_2 V_67 )
{
struct V_38 * V_39 ;
struct V_47 * V_81 ;
const T_3 * V_48 ;
T_2 V_49 ;
char V_72 [ V_77 ] ;
char * V_41 ;
T_2 V_40 ;
int V_24 ;
V_39 = F_74 ( V_47 ) ;
V_40 = V_39 -> V_94 + V_5 + 1
+ F_40 ( V_39 -> V_21 , V_6 )
+ ( V_77 * 2 ) ;
if ( ! V_120 || V_67 < V_40 )
return V_40 ;
V_81 = F_36 ( V_39 , & V_48 , & V_49 ) ;
if ( F_3 ( V_81 ) )
return F_5 ( V_81 ) ;
V_24 = F_29 ( V_72 , V_107 , V_48 , V_49 ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_39 ( V_39 , V_72 , sizeof V_72 ) ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_49 ( V_39 , V_48 , V_49 ) ;
if ( V_24 < 0 )
goto V_15;
V_41 = F_15 ( V_39 , V_40 ) ;
if ( ! V_41 ) {
V_24 = - V_61 ;
goto V_15;
}
F_59 ( & V_81 -> V_54 ) ;
F_60 ( V_81 ) ;
if ( F_75 ( V_120 , V_41 , V_40 ) != 0 )
V_24 = - V_121 ;
F_27 ( V_41 ) ;
return V_40 ;
V_15:
F_59 ( & V_81 -> V_54 ) ;
F_60 ( V_81 ) ;
return V_24 ;
}
static void F_76 ( struct V_47 * V_47 )
{
struct V_38 * V_39 = V_47 -> V_115 . V_55 [ 0 ] ;
if ( ! V_39 )
return;
memset ( V_39 -> V_91 , 0 , V_39 -> V_21 ) ;
F_27 ( V_47 -> V_115 . V_55 [ 0 ] ) ;
}
static void F_77 ( void )
{
if ( V_70 )
F_78 ( V_70 ) ;
if ( V_68 )
F_78 ( V_68 ) ;
}
static int T_5 F_79 ( void )
{
int V_24 ;
V_68 = F_80 ( V_69 , 0 , V_4 ) ;
if ( F_3 ( V_68 ) ) {
F_13 ( L_34 ,
V_69 ) ;
return F_5 ( V_68 ) ;
}
V_70 = F_80 ( V_71 , 0 , V_4 ) ;
if ( F_3 ( V_70 ) ) {
F_13 ( L_34 ,
V_71 ) ;
V_24 = F_5 ( V_70 ) ;
goto V_122;
}
return 0 ;
V_122:
F_78 ( V_68 ) ;
return V_24 ;
}
static int T_5 F_81 ( void )
{
int V_24 ;
V_24 = F_79 () ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_1 () ;
if ( V_24 < 0 )
goto V_15;
V_24 = F_82 ( & V_123 ) ;
if ( V_24 < 0 )
goto V_15;
return 0 ;
V_15:
F_77 () ;
return V_24 ;
}
static void T_6 F_83 ( void )
{
F_77 () ;
F_84 ( & V_123 ) ;
}
