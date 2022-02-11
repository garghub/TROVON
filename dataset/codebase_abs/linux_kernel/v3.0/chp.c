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
static void F_34 ( struct V_28 * V_41 )
{
struct V_26 * V_49 ;
V_49 = F_12 ( V_41 ) ;
F_35 ( V_49 ) ;
}
int F_36 ( struct V_1 V_2 )
{
struct V_26 * V_27 ;
int V_45 ;
if ( F_6 ( V_2 ) )
return 0 ;
V_27 = F_37 ( sizeof( struct V_26 ) , V_59 ) ;
if ( ! V_27 )
return - V_60 ;
V_27 -> V_2 = V_2 ;
V_27 -> V_4 = 1 ;
V_27 -> V_41 . V_42 = & V_61 [ V_2 . V_16 ] -> V_28 ;
V_27 -> V_41 . V_62 = F_34 ;
F_38 ( & V_27 -> V_48 ) ;
V_45 = F_39 ( V_2 , & V_27 -> V_56 ) ;
if ( V_45 )
goto V_63;
if ( ( V_27 -> V_56 . V_64 & 0x80 ) == 0 ) {
V_45 = - V_5 ;
goto V_63;
}
if ( V_65 . V_66 && V_65 . V_67 ) {
V_45 = F_40 ( V_27 ) ;
if ( V_45 )
goto V_63;
} else {
V_27 -> V_57 = - 1 ;
}
F_41 ( & V_27 -> V_41 , L_14 , V_2 . V_16 , V_2 . V_10 ) ;
V_45 = F_42 ( & V_27 -> V_41 ) ;
if ( V_45 ) {
F_43 ( 0 , L_15 ,
V_2 . V_16 , V_2 . V_10 , V_45 ) ;
F_44 ( & V_27 -> V_41 ) ;
goto V_68;
}
V_45 = F_45 ( & V_27 -> V_41 . V_20 , & V_69 ) ;
if ( V_45 ) {
F_46 ( & V_27 -> V_41 ) ;
goto V_68;
}
F_22 ( & V_61 [ V_2 . V_16 ] -> V_70 ) ;
if ( V_61 [ V_2 . V_16 ] -> V_71 ) {
V_45 = F_19 ( V_27 ) ;
if ( V_45 ) {
F_47 ( & V_27 -> V_41 . V_20 , & V_69 ) ;
F_46 ( & V_27 -> V_41 ) ;
F_23 ( & V_61 [ V_2 . V_16 ] -> V_70 ) ;
goto V_68;
}
}
V_61 [ V_2 . V_16 ] -> V_72 [ V_2 . V_10 ] = V_27 ;
F_23 ( & V_61 [ V_2 . V_16 ] -> V_70 ) ;
goto V_68;
V_63:
F_35 ( V_27 ) ;
V_68:
return V_45 ;
}
void * F_48 ( struct V_1 V_2 )
{
struct V_26 * V_27 ;
struct V_73 * V_56 ;
V_27 = F_2 ( V_2 ) ;
if ( ! V_27 )
return NULL ;
V_56 = F_49 ( sizeof( struct V_73 ) , V_59 ) ;
if ( ! V_56 )
return NULL ;
F_22 ( & V_27 -> V_48 ) ;
memcpy ( V_56 , & V_27 -> V_56 , sizeof( struct V_73 ) ) ;
F_23 ( & V_27 -> V_48 ) ;
return V_56 ;
}
static void F_50 ( struct V_74 * V_75 , struct V_74 * V_76 ,
int V_77 )
{
struct V_1 V_2 ;
if ( V_77 ) {
F_51 () ;
return;
}
F_52 ( 2 , L_16
L_17 ,
V_75 -> V_78 , V_75 -> V_79 , V_75 -> V_80 , V_75 -> V_81 , V_75 -> V_82 ,
V_75 -> V_83 , V_75 -> V_84 ) ;
if ( V_75 -> V_78 ) {
F_52 ( 2 , L_18
L_19 , V_75 -> V_84 ) ;
return;
}
F_5 ( & V_2 ) ;
V_2 . V_10 = V_75 -> V_84 ;
switch ( V_75 -> V_83 ) {
case V_85 :
if ( ! F_6 ( V_2 ) )
F_36 ( V_2 ) ;
F_53 ( V_2 ) ;
break;
case V_86 :
case V_87 :
F_54 ( V_2 ) ;
break;
default:
F_52 ( 2 , L_20 ,
V_75 -> V_83 ) ;
}
}
int F_55 ( struct V_88 * V_89 , struct V_90 * V_91 )
{
int V_9 ;
int V_92 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_92 = 0x80 >> V_9 ;
if ( ! ( V_89 -> V_93 & V_92 ) )
continue;
if ( ! F_56 ( & V_89 -> V_2 [ V_9 ] , & V_91 -> V_2 ) )
continue;
if ( ( V_89 -> V_94 & V_92 ) &&
( ( V_89 -> V_95 [ V_9 ] & V_91 -> V_96 ) != V_91 -> V_95 ) )
continue;
return V_92 ;
}
return 0 ;
}
static inline int F_57 ( struct V_1 V_10 )
{
return V_10 . V_10 + V_10 . V_16 * ( V_97 + 1 ) ;
}
static void F_58 ( void )
{
F_22 ( & V_98 ) ;
V_99 = V_100 - 1 ;
F_23 ( & V_98 ) ;
}
static int F_59 ( void )
{
int V_101 ;
F_22 ( & V_98 ) ;
V_101 = 0 ;
if ( F_60 ( V_100 , V_99 ) ) {
V_101 = F_61 ( & V_102 ) ;
V_99 = V_100 + V_103 ;
}
F_23 ( & V_98 ) ;
return V_101 ;
}
int F_27 ( struct V_1 V_2 )
{
int V_101 ;
int V_104 ;
V_101 = F_59 () ;
if ( V_101 )
return V_101 ;
V_104 = F_57 ( V_2 ) ;
F_22 ( & V_98 ) ;
if ( ! F_62 ( V_102 . V_105 , V_104 ) )
V_101 = V_106 ;
else if ( F_62 ( V_102 . V_107 , V_104 ) )
V_101 = V_108 ;
else if ( F_62 ( V_102 . V_109 , V_104 ) )
V_101 = V_110 ;
else
V_101 = V_111 ;
F_23 ( & V_98 ) ;
return V_101 ;
}
static enum V_112 F_63 ( struct V_1 V_2 )
{
return V_113 [ V_2 . V_16 ] [ V_2 . V_10 ] ;
}
static void F_64 ( struct V_1 V_2 , enum V_112 V_114 )
{
V_113 [ V_2 . V_16 ] [ V_2 . V_10 ] = V_114 ;
}
static void F_65 ( struct V_115 * V_116 )
{
struct V_1 V_2 ;
enum V_112 V_117 ;
int V_101 ;
F_22 ( & V_118 ) ;
V_117 = V_119 ;
F_66 (&chpid) {
V_117 = F_63 ( V_2 ) ;
if ( V_117 != V_119 ) {
F_64 ( V_2 , V_119 ) ;
break;
}
}
F_23 ( & V_118 ) ;
switch ( V_117 ) {
case V_120 :
V_101 = F_67 ( V_2 ) ;
if ( V_101 )
F_43 ( 2 , L_21
L_10 , V_2 . V_16 , V_2 . V_10 , V_101 ) ;
else {
F_58 () ;
F_53 ( V_2 ) ;
}
break;
case V_121 :
V_101 = F_68 ( V_2 ) ;
if ( V_101 )
F_43 ( 2 , L_22
L_10 , V_2 . V_16 , V_2 . V_10 , V_101 ) ;
else {
F_58 () ;
F_54 ( V_2 ) ;
}
break;
case V_119 :
F_59 () ;
F_22 ( & V_118 ) ;
V_122 = 0 ;
F_23 ( & V_118 ) ;
F_69 ( & V_123 ) ;
return;
}
F_70 ( V_124 , & V_125 ) ;
}
void F_29 ( struct V_1 V_2 , int V_126 )
{
F_43 ( 2 , L_23 , V_2 . V_16 , V_2 . V_10 ,
V_126 ) ;
F_22 ( & V_118 ) ;
F_64 ( V_2 , V_126 ? V_120 : V_121 ) ;
V_122 = 1 ;
F_23 ( & V_118 ) ;
F_70 ( V_124 , & V_125 ) ;
}
void F_71 ( struct V_1 V_2 )
{
F_43 ( 2 , L_24 , V_2 . V_16 , V_2 . V_10 ) ;
F_22 ( & V_118 ) ;
if ( F_63 ( V_2 ) == V_121 )
F_64 ( V_2 , V_119 ) ;
F_23 ( & V_118 ) ;
}
static int F_30 ( void )
{
if ( F_72 ( V_123 , ! V_122 ) )
return - V_127 ;
return 0 ;
}
static int T_5 F_73 ( void )
{
struct V_1 V_2 ;
int V_45 ;
V_45 = F_74 ( V_128 , F_50 ) ;
if ( V_45 )
return V_45 ;
V_124 = F_75 ( L_25 ) ;
if ( ! V_124 ) {
F_76 ( V_128 ) ;
return - V_60 ;
}
F_77 ( & V_125 , F_65 ) ;
F_78 ( & V_123 ) ;
if ( F_59 () )
return 0 ;
F_66 (&chpid) {
if ( F_27 ( V_2 ) != V_106 )
F_36 ( V_2 ) ;
}
return 0 ;
}
