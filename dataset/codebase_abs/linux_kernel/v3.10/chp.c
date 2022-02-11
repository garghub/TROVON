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
if ( ! V_27 -> V_29 )
return 0 ;
return F_13 ( V_23 , V_25 , & V_24 ,
V_27 -> V_29 , sizeof( struct V_29 ) ) ;
}
static void F_14 ( struct V_30 * V_23 ,
struct V_31 * V_32 ,
struct V_1 V_2 )
{
void * V_33 ;
struct V_30 * V_34 , V_35 ;
int V_36 ;
if ( V_2 . V_10 < 128 ) {
V_33 = V_32 -> V_37 ;
V_36 = V_2 . V_10 ;
} else {
V_33 = V_32 -> V_38 ;
V_36 = V_2 . V_10 - 128 ;
}
V_34 = V_33 + ( V_36 * sizeof( struct V_30 ) ) ;
do {
memcpy ( V_23 , V_34 , sizeof( * V_34 ) ) ;
memcpy ( & V_35 , V_34 , sizeof( * V_34 ) ) ;
} while ( V_35 . V_39 [ 0 ] != V_23 -> V_39 [ 0 ] );
}
static T_2 F_15 ( struct V_17 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 , T_3 V_24 , T_4 V_25 )
{
struct V_26 * V_27 ;
struct V_31 * V_32 ;
struct V_28 * V_28 ;
unsigned int V_40 ;
V_28 = F_11 ( V_20 , struct V_28 , V_20 ) ;
V_27 = F_12 ( V_28 ) ;
V_32 = F_16 ( V_27 -> V_41 . V_42 ) ;
V_40 = sizeof( struct V_30 ) ;
if ( V_24 || V_25 < V_40 )
return 0 ;
F_14 ( (struct V_30 * ) V_23 , V_32 , V_27 -> V_2 ) ;
V_25 = V_40 ;
return V_25 ;
}
void F_17 ( struct V_26 * V_27 )
{
F_18 ( & V_27 -> V_41 , & V_43 ) ;
F_18 ( & V_27 -> V_41 , & V_44 ) ;
}
int F_19 ( struct V_26 * V_27 )
{
int V_45 ;
V_45 = F_20 ( & V_27 -> V_41 , & V_43 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_20 ( & V_27 -> V_41 , & V_44 ) ;
if ( V_45 )
F_18 ( & V_27 -> V_41 , & V_43 ) ;
return V_45 ;
}
static T_2 F_21 ( struct V_28 * V_41 ,
struct V_46 * V_47 , char * V_23 )
{
struct V_26 * V_27 = F_12 ( V_41 ) ;
int V_15 ;
F_22 ( & V_27 -> V_48 ) ;
V_15 = V_27 -> V_4 ;
F_23 ( & V_27 -> V_48 ) ;
return V_15 ? sprintf ( V_23 , L_3 ) : sprintf ( V_23 , L_4 ) ;
}
static T_2 F_24 ( struct V_28 * V_41 ,
struct V_46 * V_47 ,
const char * V_23 , T_4 V_25 )
{
struct V_26 * V_49 = F_12 ( V_41 ) ;
char V_50 [ 10 ] ;
int V_51 ;
int error ;
V_51 = sscanf ( V_23 , L_5 , V_50 ) ;
if ( ! V_51 )
return V_25 ;
if ( ! F_25 ( V_50 , L_6 , 2 ) || ! strcmp ( V_50 , L_7 ) ) {
F_22 ( & V_49 -> V_48 ) ;
error = F_7 ( V_49 -> V_2 , 1 ) ;
F_23 ( & V_49 -> V_48 ) ;
} else if ( ! F_25 ( V_50 , L_8 , 3 ) || ! strcmp ( V_50 , L_9 ) ) {
F_22 ( & V_49 -> V_48 ) ;
error = F_7 ( V_49 -> V_2 , 0 ) ;
F_23 ( & V_49 -> V_48 ) ;
} else
error = - V_52 ;
return error < 0 ? error : V_25 ;
}
static T_2 F_26 ( struct V_28 * V_41 ,
struct V_46 * V_47 , char * V_23 )
{
struct V_26 * V_49 ;
int V_15 ;
V_49 = F_12 ( V_41 ) ;
V_15 = F_27 ( V_49 -> V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
return snprintf ( V_23 , V_53 , L_10 , V_15 ) ;
}
static T_2 F_28 ( struct V_28 * V_41 ,
struct V_46 * V_47 ,
const char * V_23 , T_4 V_25 )
{
struct V_26 * V_49 ;
int V_54 ;
char V_55 ;
if ( sscanf ( V_23 , L_11 , & V_54 , & V_55 ) != 1 )
return - V_52 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_52 ;
V_49 = F_12 ( V_41 ) ;
F_29 ( V_49 -> V_2 , V_54 ) ;
F_30 () ;
return V_25 ;
}
static T_2 F_31 ( struct V_28 * V_41 , struct V_46 * V_47 ,
char * V_23 )
{
struct V_26 * V_27 = F_12 ( V_41 ) ;
T_1 type ;
F_22 ( & V_27 -> V_48 ) ;
type = V_27 -> V_56 . V_56 ;
F_23 ( & V_27 -> V_48 ) ;
return sprintf ( V_23 , L_12 , type ) ;
}
static T_2 F_32 ( struct V_28 * V_41 , struct V_46 * V_47 ,
char * V_23 )
{
struct V_26 * V_27 = F_12 ( V_41 ) ;
if ( ! V_27 )
return 0 ;
if ( V_27 -> V_57 == - 1 )
return sprintf ( V_23 , L_13 ) ;
return sprintf ( V_23 , L_12 , V_27 -> V_57 ) ;
}
static T_2 F_33 ( struct V_28 * V_41 ,
struct V_46 * V_47 , char * V_23 )
{
struct V_26 * V_27 = F_12 ( V_41 ) ;
if ( ! V_27 )
return 0 ;
if ( V_27 -> V_58 == - 1 )
return sprintf ( V_23 , L_13 ) ;
return sprintf ( V_23 , L_12 , V_27 -> V_58 ) ;
}
static T_2 F_34 ( struct V_28 * V_41 , struct V_46 * V_47 ,
char * V_23 )
{
struct V_26 * V_27 = F_12 ( V_41 ) ;
T_2 V_59 ;
F_22 ( & V_27 -> V_48 ) ;
if ( V_27 -> V_60 . V_61 & 0x10 )
V_59 = sprintf ( V_23 , L_14 , V_27 -> V_60 . V_62 ) ;
else
V_59 = 0 ;
F_23 ( & V_27 -> V_48 ) ;
return V_59 ;
}
static T_2 F_35 ( struct V_28 * V_41 ,
struct V_46 * V_47 , char * V_23 )
{
struct V_26 * V_27 = F_12 ( V_41 ) ;
T_2 V_59 ;
F_22 ( & V_27 -> V_48 ) ;
if ( V_27 -> V_60 . V_61 & 0x10 )
V_59 = sprintf ( V_23 , L_12 , V_27 -> V_60 . V_61 & 0x8 ? 1 : 0 ) ;
else
V_59 = 0 ;
F_23 ( & V_27 -> V_48 ) ;
return V_59 ;
}
static void F_36 ( struct V_28 * V_41 )
{
struct V_26 * V_49 ;
V_49 = F_12 ( V_41 ) ;
F_37 ( V_49 ) ;
}
int F_38 ( struct V_26 * V_27 )
{
int V_59 ;
V_59 = F_39 ( V_27 -> V_2 , & V_27 -> V_56 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_40 ( V_27 -> V_2 , & V_27 -> V_60 ) ;
return V_59 ;
}
int F_41 ( struct V_1 V_2 )
{
struct V_26 * V_27 ;
int V_45 ;
if ( F_6 ( V_2 ) )
return 0 ;
V_27 = F_42 ( sizeof( struct V_26 ) , V_63 ) ;
if ( ! V_27 )
return - V_64 ;
V_27 -> V_2 = V_2 ;
V_27 -> V_4 = 1 ;
V_27 -> V_41 . V_42 = & V_65 [ V_2 . V_16 ] -> V_28 ;
V_27 -> V_41 . V_66 = V_67 ;
V_27 -> V_41 . V_68 = F_36 ;
F_43 ( & V_27 -> V_48 ) ;
V_45 = F_38 ( V_27 ) ;
if ( V_45 )
goto V_69;
if ( ( V_27 -> V_56 . V_61 & 0x80 ) == 0 ) {
V_45 = - V_5 ;
goto V_69;
}
if ( V_70 . V_71 && V_70 . V_72 ) {
V_45 = F_44 ( V_27 ) ;
if ( V_45 )
goto V_69;
} else {
V_27 -> V_57 = - 1 ;
}
F_45 ( & V_27 -> V_41 , L_15 , V_2 . V_16 , V_2 . V_10 ) ;
V_45 = F_46 ( & V_27 -> V_41 ) ;
if ( V_45 ) {
F_47 ( 0 , L_16 ,
V_2 . V_16 , V_2 . V_10 , V_45 ) ;
F_48 ( & V_27 -> V_41 ) ;
goto V_73;
}
F_22 ( & V_65 [ V_2 . V_16 ] -> V_74 ) ;
if ( V_65 [ V_2 . V_16 ] -> V_75 ) {
V_45 = F_19 ( V_27 ) ;
if ( V_45 ) {
F_49 ( & V_27 -> V_41 ) ;
F_23 ( & V_65 [ V_2 . V_16 ] -> V_74 ) ;
goto V_73;
}
}
V_65 [ V_2 . V_16 ] -> V_76 [ V_2 . V_10 ] = V_27 ;
F_23 ( & V_65 [ V_2 . V_16 ] -> V_74 ) ;
goto V_73;
V_69:
F_37 ( V_27 ) ;
V_73:
return V_45 ;
}
void * F_50 ( struct V_1 V_2 )
{
struct V_26 * V_27 ;
struct V_77 * V_56 ;
V_27 = F_2 ( V_2 ) ;
if ( ! V_27 )
return NULL ;
V_56 = F_51 ( sizeof( struct V_77 ) , V_63 ) ;
if ( ! V_56 )
return NULL ;
F_22 ( & V_27 -> V_48 ) ;
memcpy ( V_56 , & V_27 -> V_56 , sizeof( struct V_77 ) ) ;
F_23 ( & V_27 -> V_48 ) ;
return V_56 ;
}
static void F_52 ( struct V_78 * V_79 , struct V_78 * V_80 ,
int V_81 )
{
struct V_1 V_2 ;
if ( V_81 ) {
F_53 () ;
return;
}
F_54 ( 2 , L_17
L_18 ,
V_79 -> V_82 , V_79 -> V_83 , V_79 -> V_84 , V_79 -> V_85 , V_79 -> V_86 ,
V_79 -> V_87 , V_79 -> V_88 ) ;
if ( V_79 -> V_82 ) {
F_54 ( 2 , L_19
L_20 , V_79 -> V_88 ) ;
return;
}
F_5 ( & V_2 ) ;
V_2 . V_10 = V_79 -> V_88 ;
switch ( V_79 -> V_87 ) {
case V_89 :
if ( ! F_6 ( V_2 ) )
F_41 ( V_2 ) ;
F_55 ( V_2 ) ;
break;
case V_90 :
case V_91 :
F_56 ( V_2 ) ;
break;
default:
F_54 ( 2 , L_21 ,
V_79 -> V_87 ) ;
}
}
int F_57 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
int V_9 ;
int V_96 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_96 = 0x80 >> V_9 ;
if ( ! ( V_93 -> V_97 & V_96 ) )
continue;
if ( ! F_58 ( & V_93 -> V_2 [ V_9 ] , & V_95 -> V_2 ) )
continue;
if ( ( V_93 -> V_98 & V_96 ) &&
( ( V_93 -> V_99 [ V_9 ] & V_95 -> V_100 ) != V_95 -> V_99 ) )
continue;
return V_96 ;
}
return 0 ;
}
static inline int F_59 ( struct V_1 V_10 )
{
return V_10 . V_10 + V_10 . V_16 * ( V_101 + 1 ) ;
}
static void F_60 ( void )
{
F_22 ( & V_102 ) ;
V_103 = V_104 - 1 ;
F_23 ( & V_102 ) ;
}
static int F_61 ( void )
{
int V_59 ;
F_22 ( & V_102 ) ;
V_59 = 0 ;
if ( F_62 ( V_104 , V_103 ) ) {
V_59 = F_63 ( & V_105 ) ;
V_103 = V_104 + V_106 ;
}
F_23 ( & V_102 ) ;
return V_59 ;
}
int F_27 ( struct V_1 V_2 )
{
int V_59 ;
int V_107 ;
V_59 = F_61 () ;
if ( V_59 )
return V_59 ;
V_107 = F_59 ( V_2 ) ;
F_22 ( & V_102 ) ;
if ( ! F_64 ( V_105 . V_108 , V_107 ) )
V_59 = V_109 ;
else if ( F_64 ( V_105 . V_110 , V_107 ) )
V_59 = V_111 ;
else if ( F_64 ( V_105 . V_112 , V_107 ) )
V_59 = V_113 ;
else
V_59 = V_114 ;
F_23 ( & V_102 ) ;
return V_59 ;
}
static enum V_115 F_65 ( struct V_1 V_2 )
{
return V_116 [ V_2 . V_16 ] [ V_2 . V_10 ] ;
}
static void F_66 ( struct V_1 V_2 , enum V_115 V_117 )
{
V_116 [ V_2 . V_16 ] [ V_2 . V_10 ] = V_117 ;
}
static void F_67 ( struct V_118 * V_119 )
{
struct V_1 V_2 ;
enum V_115 V_120 ;
int V_59 ;
F_22 ( & V_121 ) ;
V_120 = V_122 ;
F_68 (&chpid) {
V_120 = F_65 ( V_2 ) ;
if ( V_120 != V_122 ) {
F_66 ( V_2 , V_122 ) ;
break;
}
}
F_23 ( & V_121 ) ;
switch ( V_120 ) {
case V_123 :
V_59 = F_69 ( V_2 ) ;
if ( V_59 )
F_47 ( 2 , L_22
L_10 , V_2 . V_16 , V_2 . V_10 , V_59 ) ;
else {
F_60 () ;
F_55 ( V_2 ) ;
}
break;
case V_124 :
V_59 = F_70 ( V_2 ) ;
if ( V_59 )
F_47 ( 2 , L_23
L_10 , V_2 . V_16 , V_2 . V_10 , V_59 ) ;
else {
F_60 () ;
F_56 ( V_2 ) ;
}
break;
case V_122 :
F_61 () ;
F_22 ( & V_121 ) ;
V_125 = 0 ;
F_23 ( & V_121 ) ;
F_71 ( & V_126 ) ;
return;
}
F_72 ( V_127 , & V_128 ) ;
}
void F_29 ( struct V_1 V_2 , int V_129 )
{
F_47 ( 2 , L_24 , V_2 . V_16 , V_2 . V_10 ,
V_129 ) ;
F_22 ( & V_121 ) ;
F_66 ( V_2 , V_129 ? V_123 : V_124 ) ;
V_125 = 1 ;
F_23 ( & V_121 ) ;
F_72 ( V_127 , & V_128 ) ;
}
void F_73 ( struct V_1 V_2 )
{
F_47 ( 2 , L_25 , V_2 . V_16 , V_2 . V_10 ) ;
F_22 ( & V_121 ) ;
if ( F_65 ( V_2 ) == V_124 )
F_66 ( V_2 , V_122 ) ;
F_23 ( & V_121 ) ;
}
static int F_30 ( void )
{
if ( F_74 ( V_126 , ! V_125 ) )
return - V_130 ;
return 0 ;
}
static int T_5 F_75 ( void )
{
struct V_1 V_2 ;
int V_45 ;
V_45 = F_76 ( V_131 , F_52 ) ;
if ( V_45 )
return V_45 ;
V_127 = F_77 ( L_26 ) ;
if ( ! V_127 ) {
F_78 ( V_131 ) ;
return - V_64 ;
}
F_79 ( & V_128 , F_67 ) ;
F_80 ( & V_126 ) ;
if ( F_61 () )
return 0 ;
F_68 (&chpid) {
if ( F_27 ( V_2 ) != V_109 )
F_41 ( V_2 ) ;
}
return 0 ;
}
