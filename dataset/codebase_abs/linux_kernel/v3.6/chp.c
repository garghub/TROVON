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
V_27 -> V_41 . V_62 = V_63 ;
V_27 -> V_41 . V_64 = F_34 ;
F_38 ( & V_27 -> V_48 ) ;
V_45 = F_39 ( V_2 , & V_27 -> V_56 ) ;
if ( V_45 )
goto V_65;
if ( ( V_27 -> V_56 . V_66 & 0x80 ) == 0 ) {
V_45 = - V_5 ;
goto V_65;
}
if ( V_67 . V_68 && V_67 . V_69 ) {
V_45 = F_40 ( V_27 ) ;
if ( V_45 )
goto V_65;
} else {
V_27 -> V_57 = - 1 ;
}
F_41 ( & V_27 -> V_41 , L_14 , V_2 . V_16 , V_2 . V_10 ) ;
V_45 = F_42 ( & V_27 -> V_41 ) ;
if ( V_45 ) {
F_43 ( 0 , L_15 ,
V_2 . V_16 , V_2 . V_10 , V_45 ) ;
F_44 ( & V_27 -> V_41 ) ;
goto V_70;
}
F_22 ( & V_61 [ V_2 . V_16 ] -> V_71 ) ;
if ( V_61 [ V_2 . V_16 ] -> V_72 ) {
V_45 = F_19 ( V_27 ) ;
if ( V_45 ) {
F_45 ( & V_27 -> V_41 ) ;
F_23 ( & V_61 [ V_2 . V_16 ] -> V_71 ) ;
goto V_70;
}
}
V_61 [ V_2 . V_16 ] -> V_73 [ V_2 . V_10 ] = V_27 ;
F_23 ( & V_61 [ V_2 . V_16 ] -> V_71 ) ;
goto V_70;
V_65:
F_35 ( V_27 ) ;
V_70:
return V_45 ;
}
void * F_46 ( struct V_1 V_2 )
{
struct V_26 * V_27 ;
struct V_74 * V_56 ;
V_27 = F_2 ( V_2 ) ;
if ( ! V_27 )
return NULL ;
V_56 = F_47 ( sizeof( struct V_74 ) , V_59 ) ;
if ( ! V_56 )
return NULL ;
F_22 ( & V_27 -> V_48 ) ;
memcpy ( V_56 , & V_27 -> V_56 , sizeof( struct V_74 ) ) ;
F_23 ( & V_27 -> V_48 ) ;
return V_56 ;
}
static void F_48 ( struct V_75 * V_76 , struct V_75 * V_77 ,
int V_78 )
{
struct V_1 V_2 ;
if ( V_78 ) {
F_49 () ;
return;
}
F_50 ( 2 , L_16
L_17 ,
V_76 -> V_79 , V_76 -> V_80 , V_76 -> V_81 , V_76 -> V_82 , V_76 -> V_83 ,
V_76 -> V_84 , V_76 -> V_85 ) ;
if ( V_76 -> V_79 ) {
F_50 ( 2 , L_18
L_19 , V_76 -> V_85 ) ;
return;
}
F_5 ( & V_2 ) ;
V_2 . V_10 = V_76 -> V_85 ;
switch ( V_76 -> V_84 ) {
case V_86 :
if ( ! F_6 ( V_2 ) )
F_36 ( V_2 ) ;
F_51 ( V_2 ) ;
break;
case V_87 :
case V_88 :
F_52 ( V_2 ) ;
break;
default:
F_50 ( 2 , L_20 ,
V_76 -> V_84 ) ;
}
}
int F_53 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
int V_9 ;
int V_93 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_93 = 0x80 >> V_9 ;
if ( ! ( V_90 -> V_94 & V_93 ) )
continue;
if ( ! F_54 ( & V_90 -> V_2 [ V_9 ] , & V_92 -> V_2 ) )
continue;
if ( ( V_90 -> V_95 & V_93 ) &&
( ( V_90 -> V_96 [ V_9 ] & V_92 -> V_97 ) != V_92 -> V_96 ) )
continue;
return V_93 ;
}
return 0 ;
}
static inline int F_55 ( struct V_1 V_10 )
{
return V_10 . V_10 + V_10 . V_16 * ( V_98 + 1 ) ;
}
static void F_56 ( void )
{
F_22 ( & V_99 ) ;
V_100 = V_101 - 1 ;
F_23 ( & V_99 ) ;
}
static int F_57 ( void )
{
int V_102 ;
F_22 ( & V_99 ) ;
V_102 = 0 ;
if ( F_58 ( V_101 , V_100 ) ) {
V_102 = F_59 ( & V_103 ) ;
V_100 = V_101 + V_104 ;
}
F_23 ( & V_99 ) ;
return V_102 ;
}
int F_27 ( struct V_1 V_2 )
{
int V_102 ;
int V_105 ;
V_102 = F_57 () ;
if ( V_102 )
return V_102 ;
V_105 = F_55 ( V_2 ) ;
F_22 ( & V_99 ) ;
if ( ! F_60 ( V_103 . V_106 , V_105 ) )
V_102 = V_107 ;
else if ( F_60 ( V_103 . V_108 , V_105 ) )
V_102 = V_109 ;
else if ( F_60 ( V_103 . V_110 , V_105 ) )
V_102 = V_111 ;
else
V_102 = V_112 ;
F_23 ( & V_99 ) ;
return V_102 ;
}
static enum V_113 F_61 ( struct V_1 V_2 )
{
return V_114 [ V_2 . V_16 ] [ V_2 . V_10 ] ;
}
static void F_62 ( struct V_1 V_2 , enum V_113 V_115 )
{
V_114 [ V_2 . V_16 ] [ V_2 . V_10 ] = V_115 ;
}
static void F_63 ( struct V_116 * V_117 )
{
struct V_1 V_2 ;
enum V_113 V_118 ;
int V_102 ;
F_22 ( & V_119 ) ;
V_118 = V_120 ;
F_64 (&chpid) {
V_118 = F_61 ( V_2 ) ;
if ( V_118 != V_120 ) {
F_62 ( V_2 , V_120 ) ;
break;
}
}
F_23 ( & V_119 ) ;
switch ( V_118 ) {
case V_121 :
V_102 = F_65 ( V_2 ) ;
if ( V_102 )
F_43 ( 2 , L_21
L_10 , V_2 . V_16 , V_2 . V_10 , V_102 ) ;
else {
F_56 () ;
F_51 ( V_2 ) ;
}
break;
case V_122 :
V_102 = F_66 ( V_2 ) ;
if ( V_102 )
F_43 ( 2 , L_22
L_10 , V_2 . V_16 , V_2 . V_10 , V_102 ) ;
else {
F_56 () ;
F_52 ( V_2 ) ;
}
break;
case V_120 :
F_57 () ;
F_22 ( & V_119 ) ;
V_123 = 0 ;
F_23 ( & V_119 ) ;
F_67 ( & V_124 ) ;
return;
}
F_68 ( V_125 , & V_126 ) ;
}
void F_29 ( struct V_1 V_2 , int V_127 )
{
F_43 ( 2 , L_23 , V_2 . V_16 , V_2 . V_10 ,
V_127 ) ;
F_22 ( & V_119 ) ;
F_62 ( V_2 , V_127 ? V_121 : V_122 ) ;
V_123 = 1 ;
F_23 ( & V_119 ) ;
F_68 ( V_125 , & V_126 ) ;
}
void F_69 ( struct V_1 V_2 )
{
F_43 ( 2 , L_24 , V_2 . V_16 , V_2 . V_10 ) ;
F_22 ( & V_119 ) ;
if ( F_61 ( V_2 ) == V_122 )
F_62 ( V_2 , V_120 ) ;
F_23 ( & V_119 ) ;
}
static int F_30 ( void )
{
if ( F_70 ( V_124 , ! V_123 ) )
return - V_128 ;
return 0 ;
}
static int T_5 F_71 ( void )
{
struct V_1 V_2 ;
int V_45 ;
V_45 = F_72 ( V_129 , F_48 ) ;
if ( V_45 )
return V_45 ;
V_125 = F_73 ( L_25 ) ;
if ( ! V_125 ) {
F_74 ( V_129 ) ;
return - V_60 ;
}
F_75 ( & V_126 , F_63 ) ;
F_76 ( & V_124 ) ;
if ( F_57 () )
return 0 ;
F_64 (&chpid) {
if ( F_27 ( V_2 ) != V_107 )
F_36 ( V_2 ) ;
}
return 0 ;
}
