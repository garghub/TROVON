static void F_1 ( struct V_1 V_2 , int V_3 )
{
F_2 ( V_2 ) -> V_4 = V_3 ;
}
int F_3 ( struct V_1 V_2 )
{
return ( F_2 ( V_2 ) ? F_2 ( V_2 ) -> V_4 : - V_5 ) ;
}
T_1 F_4 ( struct V_6 * V_7 )
{
struct V_1 V_2 ;
int V_8 ;
int V_9 ;
V_8 = 0 ;
F_5 ( & V_2 ) ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_8 <<= 1 ;
V_2 . V_10 = V_7 -> V_11 . V_12 . V_2 [ V_9 ] ;
if ( F_3 ( V_2 ) != 0 )
V_8 |= 1 ;
}
return V_8 ;
}
int F_6 ( struct V_1 V_2 )
{
return F_2 ( V_2 ) != NULL ;
}
static int F_7 ( struct V_1 V_2 , int V_13 )
{
char V_14 [ 15 ] ;
int V_15 ;
sprintf ( V_14 , V_13 ? L_1 : L_2 , V_2 . V_16 ,
V_2 . V_10 ) ;
F_8 ( 2 , V_14 ) ;
V_15 = F_3 ( V_2 ) ;
if ( ! V_13 && ! V_15 )
return 0 ;
F_1 ( V_2 , V_13 ) ;
F_9 ( V_2 , V_13 ) ;
return 0 ;
}
static T_2 F_10 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 , T_3 V_24 , T_4 V_25 )
{
struct V_26 * V_27 ;
struct V_28 * V_28 ;
V_28 = F_11 ( V_20 , struct V_28 , V_20 ) ;
V_27 = F_12 ( V_28 ) ;
if ( V_27 -> V_29 == - 1 )
return 0 ;
return F_13 ( V_23 , V_25 , & V_24 , & V_27 -> V_30 ,
sizeof( V_27 -> V_30 ) ) ;
}
static void F_14 ( struct V_31 * V_23 ,
struct V_32 * V_33 ,
struct V_1 V_2 )
{
void * V_34 ;
struct V_31 * V_35 , V_36 ;
int V_37 ;
if ( V_2 . V_10 < 128 ) {
V_34 = V_33 -> V_38 ;
V_37 = V_2 . V_10 ;
} else {
V_34 = V_33 -> V_39 ;
V_37 = V_2 . V_10 - 128 ;
}
V_35 = V_34 + ( V_37 * sizeof( struct V_31 ) ) ;
do {
memcpy ( V_23 , V_35 , sizeof( * V_35 ) ) ;
memcpy ( & V_36 , V_35 , sizeof( * V_35 ) ) ;
} while ( V_36 . V_40 [ 0 ] != V_23 -> V_40 [ 0 ] );
}
static T_2 F_15 ( struct V_17 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 , T_3 V_24 , T_4 V_25 )
{
struct V_26 * V_27 ;
struct V_32 * V_33 ;
struct V_28 * V_28 ;
unsigned int V_41 ;
V_28 = F_11 ( V_20 , struct V_28 , V_20 ) ;
V_27 = F_12 ( V_28 ) ;
V_33 = F_16 ( V_27 -> V_42 . V_43 ) ;
V_41 = sizeof( struct V_31 ) ;
if ( V_24 || V_25 < V_41 )
return 0 ;
F_14 ( (struct V_31 * ) V_23 , V_33 , V_27 -> V_2 ) ;
V_25 = V_41 ;
return V_25 ;
}
void F_17 ( struct V_26 * V_27 )
{
F_18 ( & V_27 -> V_42 , & V_44 ) ;
F_18 ( & V_27 -> V_42 , & V_45 ) ;
}
int F_19 ( struct V_26 * V_27 )
{
int V_46 ;
V_46 = F_20 ( & V_27 -> V_42 , & V_44 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_20 ( & V_27 -> V_42 , & V_45 ) ;
if ( V_46 )
F_18 ( & V_27 -> V_42 , & V_44 ) ;
return V_46 ;
}
static T_2 F_21 ( struct V_28 * V_42 ,
struct V_47 * V_48 , char * V_23 )
{
struct V_26 * V_27 = F_12 ( V_42 ) ;
int V_15 ;
F_22 ( & V_27 -> V_49 ) ;
V_15 = V_27 -> V_4 ;
F_23 ( & V_27 -> V_49 ) ;
return V_15 ? sprintf ( V_23 , L_3 ) : sprintf ( V_23 , L_4 ) ;
}
static T_2 F_24 ( struct V_28 * V_42 ,
struct V_47 * V_48 ,
const char * V_23 , T_4 V_25 )
{
struct V_26 * V_50 = F_12 ( V_42 ) ;
char V_51 [ 10 ] ;
int V_52 ;
int error ;
V_52 = sscanf ( V_23 , L_5 , V_51 ) ;
if ( ! V_52 )
return V_25 ;
if ( ! strncasecmp ( V_51 , L_6 , 2 ) || ! strcmp ( V_51 , L_7 ) ) {
F_22 ( & V_50 -> V_49 ) ;
error = F_7 ( V_50 -> V_2 , 1 ) ;
F_23 ( & V_50 -> V_49 ) ;
} else if ( ! strncasecmp ( V_51 , L_8 , 3 ) || ! strcmp ( V_51 , L_9 ) ) {
F_22 ( & V_50 -> V_49 ) ;
error = F_7 ( V_50 -> V_2 , 0 ) ;
F_23 ( & V_50 -> V_49 ) ;
} else
error = - V_53 ;
return error < 0 ? error : V_25 ;
}
static T_2 F_25 ( struct V_28 * V_42 ,
struct V_47 * V_48 , char * V_23 )
{
struct V_26 * V_50 ;
int V_15 ;
V_50 = F_12 ( V_42 ) ;
V_15 = F_26 ( V_50 -> V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
return snprintf ( V_23 , V_54 , L_10 , V_15 ) ;
}
static T_2 F_27 ( struct V_28 * V_42 ,
struct V_47 * V_48 ,
const char * V_23 , T_4 V_25 )
{
struct V_26 * V_50 ;
int V_55 ;
char V_56 ;
if ( sscanf ( V_23 , L_11 , & V_55 , & V_56 ) != 1 )
return - V_53 ;
if ( V_55 != 0 && V_55 != 1 )
return - V_53 ;
V_50 = F_12 ( V_42 ) ;
F_28 ( V_50 -> V_2 , V_55 ) ;
F_29 () ;
return V_25 ;
}
static T_2 F_30 ( struct V_28 * V_42 , struct V_47 * V_48 ,
char * V_23 )
{
struct V_26 * V_27 = F_12 ( V_42 ) ;
T_1 type ;
F_22 ( & V_27 -> V_49 ) ;
type = V_27 -> V_57 . V_57 ;
F_23 ( & V_27 -> V_49 ) ;
return sprintf ( V_23 , L_12 , type ) ;
}
static T_2 F_31 ( struct V_28 * V_42 , struct V_47 * V_48 ,
char * V_23 )
{
struct V_26 * V_27 = F_12 ( V_42 ) ;
if ( ! V_27 )
return 0 ;
if ( V_27 -> V_29 == - 1 )
return sprintf ( V_23 , L_13 ) ;
return sprintf ( V_23 , L_12 , V_27 -> V_29 ) ;
}
static T_2 F_32 ( struct V_28 * V_42 ,
struct V_47 * V_48 , char * V_23 )
{
struct V_26 * V_27 = F_12 ( V_42 ) ;
if ( ! V_27 )
return 0 ;
if ( V_27 -> V_58 == - 1 )
return sprintf ( V_23 , L_13 ) ;
return sprintf ( V_23 , L_12 , V_27 -> V_58 ) ;
}
static T_2 F_33 ( struct V_28 * V_42 , struct V_47 * V_48 ,
char * V_23 )
{
struct V_26 * V_27 = F_12 ( V_42 ) ;
T_2 V_59 ;
F_22 ( & V_27 -> V_49 ) ;
if ( V_27 -> V_60 . V_61 & 0x10 )
V_59 = sprintf ( V_23 , L_14 , V_27 -> V_60 . V_62 ) ;
else
V_59 = 0 ;
F_23 ( & V_27 -> V_49 ) ;
return V_59 ;
}
static T_2 F_34 ( struct V_28 * V_42 ,
struct V_47 * V_48 , char * V_23 )
{
struct V_26 * V_27 = F_12 ( V_42 ) ;
T_2 V_59 ;
F_22 ( & V_27 -> V_49 ) ;
if ( V_27 -> V_60 . V_61 & 0x10 )
V_59 = sprintf ( V_23 , L_12 , V_27 -> V_60 . V_61 & 0x8 ? 1 : 0 ) ;
else
V_59 = 0 ;
F_23 ( & V_27 -> V_49 ) ;
return V_59 ;
}
static void F_35 ( struct V_28 * V_42 )
{
struct V_26 * V_50 ;
V_50 = F_12 ( V_42 ) ;
F_36 ( V_50 ) ;
}
int F_37 ( struct V_26 * V_27 )
{
int V_59 ;
V_59 = F_38 ( V_27 -> V_2 , & V_27 -> V_57 ) ;
if ( V_59 )
return V_59 ;
F_39 ( V_27 -> V_2 , & V_27 -> V_60 ) ;
F_40 ( V_27 ) ;
return 0 ;
}
int F_41 ( struct V_1 V_2 )
{
struct V_32 * V_33 = F_42 ( V_2 . V_16 ) ;
struct V_26 * V_27 ;
int V_46 ;
if ( F_6 ( V_2 ) )
return 0 ;
V_27 = F_43 ( sizeof( struct V_26 ) , V_63 ) ;
if ( ! V_27 )
return - V_64 ;
V_27 -> V_2 = V_2 ;
V_27 -> V_4 = 1 ;
V_27 -> V_42 . V_43 = & V_33 -> V_28 ;
V_27 -> V_42 . V_65 = V_66 ;
V_27 -> V_42 . V_67 = F_35 ;
F_44 ( & V_27 -> V_49 ) ;
V_46 = F_37 ( V_27 ) ;
if ( V_46 )
goto V_68;
if ( ( V_27 -> V_57 . V_61 & 0x80 ) == 0 ) {
V_46 = - V_5 ;
goto V_68;
}
F_45 ( & V_27 -> V_42 , L_15 , V_2 . V_16 , V_2 . V_10 ) ;
V_46 = F_46 ( & V_27 -> V_42 ) ;
if ( V_46 ) {
F_47 ( 0 , L_16 ,
V_2 . V_16 , V_2 . V_10 , V_46 ) ;
F_48 ( & V_27 -> V_42 ) ;
goto V_69;
}
F_22 ( & V_33 -> V_70 ) ;
if ( V_33 -> V_71 ) {
V_46 = F_19 ( V_27 ) ;
if ( V_46 ) {
F_49 ( & V_27 -> V_42 ) ;
F_23 ( & V_33 -> V_70 ) ;
goto V_69;
}
}
V_33 -> V_72 [ V_2 . V_10 ] = V_27 ;
F_23 ( & V_33 -> V_70 ) ;
goto V_69;
V_68:
F_36 ( V_27 ) ;
V_69:
return V_46 ;
}
struct V_73 * F_50 ( struct V_1 V_2 )
{
struct V_26 * V_27 ;
struct V_73 * V_57 ;
V_27 = F_2 ( V_2 ) ;
if ( ! V_27 )
return NULL ;
V_57 = F_51 ( sizeof( struct V_73 ) , V_63 ) ;
if ( ! V_57 )
return NULL ;
F_22 ( & V_27 -> V_49 ) ;
memcpy ( V_57 , & V_27 -> V_57 , sizeof( struct V_73 ) ) ;
F_23 ( & V_27 -> V_49 ) ;
return V_57 ;
}
static void F_52 ( struct V_74 * V_75 , struct V_74 * V_76 ,
int V_77 )
{
struct V_1 V_2 ;
if ( V_77 ) {
F_53 () ;
return;
}
F_54 ( 2 , L_17
L_18 ,
V_75 -> V_78 , V_75 -> V_79 , V_75 -> V_80 , V_75 -> V_81 , V_75 -> V_82 ,
V_75 -> V_83 , V_75 -> V_84 ) ;
if ( V_75 -> V_78 ) {
F_54 ( 2 , L_19
L_20 , V_75 -> V_84 ) ;
return;
}
F_5 ( & V_2 ) ;
V_2 . V_10 = V_75 -> V_84 ;
switch ( V_75 -> V_83 ) {
case V_85 :
case V_86 :
if ( ! F_6 ( V_2 ) )
F_41 ( V_2 ) ;
F_55 ( V_2 ) ;
break;
case V_87 :
case V_88 :
F_56 ( V_2 ) ;
break;
default:
F_54 ( 2 , L_21 ,
V_75 -> V_83 ) ;
}
}
int F_57 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
int V_9 ;
int V_93 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_93 = 0x80 >> V_9 ;
if ( ! ( V_90 -> V_94 & V_93 ) )
continue;
if ( ! F_58 ( & V_90 -> V_2 [ V_9 ] , & V_92 -> V_2 ) )
continue;
if ( ( V_90 -> V_95 & V_93 ) &&
( ( V_90 -> V_96 [ V_9 ] & V_92 -> V_97 ) != V_92 -> V_96 ) )
continue;
return V_93 ;
}
return 0 ;
}
static inline int F_59 ( struct V_1 V_10 )
{
return V_10 . V_10 + V_10 . V_16 * ( V_98 + 1 ) ;
}
static void F_60 ( void )
{
F_22 ( & V_99 ) ;
V_100 = V_101 - 1 ;
F_23 ( & V_99 ) ;
}
static int F_61 ( void )
{
int V_59 ;
F_22 ( & V_99 ) ;
V_59 = 0 ;
if ( F_62 ( V_101 , V_100 ) ) {
V_59 = F_63 ( & V_102 ) ;
V_100 = V_101 + V_103 ;
}
F_23 ( & V_99 ) ;
return V_59 ;
}
int F_26 ( struct V_1 V_2 )
{
int V_59 ;
int V_104 ;
V_59 = F_61 () ;
if ( V_59 )
return V_59 ;
V_104 = F_59 ( V_2 ) ;
F_22 ( & V_99 ) ;
if ( ! F_64 ( V_102 . V_105 , V_104 ) )
V_59 = V_106 ;
else if ( F_64 ( V_102 . V_107 , V_104 ) )
V_59 = V_108 ;
else if ( F_64 ( V_102 . V_109 , V_104 ) )
V_59 = V_110 ;
else
V_59 = V_111 ;
F_23 ( & V_99 ) ;
return V_59 ;
}
static enum V_112 F_65 ( struct V_1 V_2 )
{
return V_113 [ V_2 . V_16 ] [ V_2 . V_10 ] ;
}
static void F_66 ( struct V_1 V_2 , enum V_112 V_114 )
{
V_113 [ V_2 . V_16 ] [ V_2 . V_10 ] = V_114 ;
}
static enum V_112 F_67 ( struct V_1 * V_2 )
{
enum V_112 V_115 = V_116 ;
F_68 (chpid) {
V_115 = F_65 ( * V_2 ) ;
if ( V_115 != V_116 )
break;
}
return V_115 ;
}
static void F_69 ( struct V_117 * V_118 )
{
struct V_1 V_2 ;
enum V_112 V_115 ;
int V_59 ;
F_70 ( & V_119 ) ;
V_115 = F_67 ( & V_2 ) ;
F_71 ( & V_119 ) ;
switch ( V_115 ) {
case V_120 :
V_59 = F_72 ( V_2 ) ;
if ( V_59 )
F_47 ( 2 , L_22
L_10 , V_2 . V_16 , V_2 . V_10 , V_59 ) ;
else {
F_60 () ;
F_55 ( V_2 ) ;
}
break;
case V_121 :
V_59 = F_73 ( V_2 ) ;
if ( V_59 )
F_47 ( 2 , L_23
L_10 , V_2 . V_16 , V_2 . V_10 , V_59 ) ;
else {
F_60 () ;
F_56 ( V_2 ) ;
}
break;
case V_116 :
F_61 () ;
F_74 ( & V_122 ) ;
return;
}
F_70 ( & V_119 ) ;
if ( V_115 == F_65 ( V_2 ) )
F_66 ( V_2 , V_116 ) ;
F_71 ( & V_119 ) ;
F_75 ( & V_123 ) ;
}
void F_28 ( struct V_1 V_2 , int V_124 )
{
F_47 ( 2 , L_24 , V_2 . V_16 , V_2 . V_10 ,
V_124 ) ;
F_70 ( & V_119 ) ;
F_66 ( V_2 , V_124 ? V_120 : V_121 ) ;
F_71 ( & V_119 ) ;
F_75 ( & V_123 ) ;
}
void F_76 ( struct V_1 V_2 )
{
F_47 ( 2 , L_25 , V_2 . V_16 , V_2 . V_10 ) ;
F_70 ( & V_119 ) ;
if ( F_65 ( V_2 ) == V_121 )
F_66 ( V_2 , V_116 ) ;
F_71 ( & V_119 ) ;
}
static bool F_77 ( void )
{
struct V_1 V_2 ;
enum V_112 V_115 ;
F_70 ( & V_119 ) ;
V_115 = F_67 ( & V_2 ) ;
F_71 ( & V_119 ) ;
return V_115 == V_116 ;
}
static int F_29 ( void )
{
if ( F_78 ( V_122 , F_77 () ) )
return - V_125 ;
return 0 ;
}
static int T_5 F_79 ( void )
{
struct V_1 V_2 ;
int V_4 , V_46 ;
V_46 = F_80 ( V_126 , F_52 ) ;
if ( V_46 )
return V_46 ;
F_81 ( & V_123 , F_69 ) ;
F_82 ( & V_122 ) ;
if ( F_61 () )
return 0 ;
F_68 (&chpid) {
V_4 = F_26 ( V_2 ) ;
if ( V_4 == V_108 ||
V_4 == V_110 )
F_41 ( V_2 ) ;
}
return 0 ;
}
