static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_9 V_10 ;
T_1 V_11 , V_12 ;
int V_13 ;
if ( ! V_7 -> V_14 )
return - V_15 ;
V_13 = F_2 ( V_2 , 0 , V_16 , 0xff , & V_10 ) ;
if ( V_13 == 0 ) {
V_13 = V_7 -> V_14 ( V_2 , V_10 . line , & V_11 , & V_12 ) ;
if ( V_13 == 0 ) {
V_11 = F_3 ( V_11 , V_12 ) ;
if ( V_4 -> V_17 <= V_18 || ( V_10 . log [ 0 ] & 1 ) )
V_12 = V_11 - V_12 ;
return ( V_12 * 100 ) / V_11 ;
}
return F_4 ( V_2 , V_10 . V_19 ) * 100 ;
}
return - V_15 ;
}
static int
F_5 ( struct V_1 * V_2 , int V_20 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_9 V_10 ;
T_1 V_11 , V_12 ;
int V_13 ;
if ( ! V_7 -> V_21 )
return - V_15 ;
V_13 = F_2 ( V_2 , 0 , V_16 , 0xff , & V_10 ) ;
if ( V_13 == 0 ) {
V_11 = V_7 -> V_22 ;
if ( V_7 -> V_23 . V_24 ) {
V_11 = 135000 / V_7 -> V_23 . V_24 ;
if ( V_4 -> V_25 < 0xa3 )
V_11 /= 4 ;
}
V_12 = ( ( V_11 * V_20 ) + 99 ) / 100 ;
if ( V_4 -> V_17 <= V_18 || ( V_10 . log [ 0 ] & 1 ) )
V_12 = V_11 - V_12 ;
return V_7 -> V_21 ( V_2 , V_10 . line , V_11 , V_12 ) ;
}
return - V_15 ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_26 * V_27 ,
struct V_26 * V_28 , struct V_26 * V_29 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
int V_13 ;
if ( V_28 -> V_30 && V_29 -> V_30 && V_29 -> V_30 > V_28 -> V_30 ) {
V_13 = F_5 ( V_2 , V_27 -> V_30 ) ;
if ( V_13 && V_13 != - V_15 ) {
F_7 ( V_2 , L_1 , V_13 ) ;
return V_13 ;
}
}
if ( V_7 -> V_31 . V_32 && V_7 -> V_33 ) {
if ( V_27 -> V_34 && V_29 -> V_34 > V_28 -> V_34 ) {
V_13 = V_7 -> V_33 ( V_2 , V_27 -> V_34 ) ;
if ( V_13 ) {
F_7 ( V_2 , L_2 , V_13 ) ;
return V_13 ;
}
}
}
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
void * V_35 ;
int V_13 ;
if ( V_27 == V_7 -> V_36 )
return 0 ;
V_13 = F_6 ( V_2 , V_27 , V_7 -> V_36 , V_27 ) ;
if ( V_13 )
return V_13 ;
V_35 = V_7 -> V_37 ( V_2 , V_27 ) ;
if ( F_9 ( V_35 ) )
return F_10 ( V_35 ) ;
V_7 -> V_38 ( V_2 , V_35 ) ;
V_13 = F_6 ( V_2 , V_27 , V_27 , V_7 -> V_36 ) ;
if ( V_13 )
return V_13 ;
V_7 -> V_36 = V_27 ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 , const char * V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_26 * V_27 = NULL ;
if ( V_40 != 7777 )
return - V_41 ;
if ( ! strncmp ( V_39 , L_3 , 4 ) )
V_27 = & V_7 -> V_42 ;
else {
int V_43 = F_12 ( V_39 , NULL , 10 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_45 ; V_44 ++ ) {
if ( V_7 -> V_27 [ V_44 ] . V_46 == V_43 ) {
V_27 = & V_7 -> V_27 [ V_44 ] ;
break;
}
}
if ( ! V_27 )
return - V_47 ;
}
F_13 ( V_2 , L_4 , V_39 ) ;
return F_8 ( V_2 , V_27 ) ;
}
static int
F_14 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
int V_13 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_13 = V_7 -> V_48 ( V_2 , V_27 ) ;
if ( V_13 )
return V_13 ;
if ( V_7 -> V_31 . V_32 && V_7 -> V_49 ) {
V_13 = V_7 -> V_49 ( V_2 ) ;
if ( V_13 > 0 ) {
V_27 -> V_34 = V_13 ;
V_27 -> V_50 = V_13 ;
}
}
V_13 = F_1 ( V_2 ) ;
if ( V_13 > 0 )
V_27 -> V_30 = V_13 ;
return 0 ;
}
static void
F_15 ( struct V_26 * V_27 , char * V_51 , int V_52 )
{
char V_53 [ 16 ] , V_54 [ 16 ] , V_55 [ 32 ] , V_56 [ 16 ] , V_57 [ 16 ] , V_58 [ 16 ] ;
V_53 [ 0 ] = '\0' ;
if ( V_27 -> V_59 )
snprintf ( V_53 , sizeof( V_53 ) , L_5 , V_27 -> V_59 / 1000 ) ;
V_54 [ 0 ] = '\0' ;
if ( V_27 -> V_60 )
snprintf ( V_54 , sizeof( V_54 ) , L_6 , V_27 -> V_60 / 1000 ) ;
V_58 [ 0 ] = '\0' ;
if ( V_27 -> V_61 )
snprintf ( V_58 , sizeof( V_58 ) , L_7 , V_27 -> V_61 / 1000 ) ;
V_55 [ 0 ] = '\0' ;
if ( V_27 -> V_34 && V_27 -> V_34 != V_27 -> V_50 ) {
snprintf ( V_55 , sizeof( V_55 ) , L_8 ,
V_27 -> V_34 / 1000 , V_27 -> V_50 / 1000 ) ;
} else
if ( V_27 -> V_34 ) {
snprintf ( V_55 , sizeof( V_55 ) , L_9 ,
V_27 -> V_34 / 1000 ) ;
}
V_56 [ 0 ] = '\0' ;
if ( V_27 -> V_30 )
snprintf ( V_56 , sizeof( V_56 ) , L_10 , V_27 -> V_30 ) ;
V_57 [ 0 ] = '\0' ;
if ( V_27 -> V_62 )
snprintf ( V_57 , sizeof( V_57 ) , L_11 , V_27 -> V_62 -> V_46 ) ;
snprintf ( V_51 , V_52 , L_12 , V_53 , V_54 , V_58 , V_57 , V_55 , V_56 ) ;
}
static T_2
F_16 ( struct V_63 * V_64 ,
struct V_65 * V_28 , char * V_66 )
{
struct V_26 * V_27 = (struct V_26 * ) V_28 ;
char * V_51 = V_66 ;
int V_52 = V_67 ;
snprintf ( V_51 , V_52 , L_13 , V_27 -> V_46 ) ;
V_51 += strlen ( V_66 ) ;
V_52 -= strlen ( V_66 ) ;
F_15 ( V_27 , V_51 , V_52 ) ;
return strlen ( V_66 ) ;
}
static T_2
F_17 ( struct V_63 * V_64 , struct V_65 * V_28 , char * V_66 )
{
struct V_1 * V_2 = F_18 ( F_19 ( V_64 ) ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_26 V_36 ;
int V_52 = V_67 , V_13 ;
char * V_51 = V_66 ;
if ( ! V_7 -> V_36 )
snprintf ( V_51 , V_52 , L_14 ) ;
else if ( V_7 -> V_36 == & V_7 -> V_42 )
snprintf ( V_51 , V_52 , L_15 ) ;
else
snprintf ( V_51 , V_52 , L_16 , V_7 -> V_36 -> V_46 ) ;
V_51 += strlen ( V_66 ) ;
V_52 -= strlen ( V_66 ) ;
V_13 = F_14 ( V_2 , & V_36 ) ;
if ( V_13 == 0 )
F_15 ( & V_36 , V_51 , V_52 ) ;
return strlen ( V_66 ) ;
}
static T_2
F_20 ( struct V_63 * V_64 , struct V_65 * V_28 ,
const char * V_66 , T_3 V_68 )
{
struct V_1 * V_2 = F_18 ( F_19 ( V_64 ) ) ;
int V_13 ;
V_13 = F_11 ( V_2 , V_66 ) ;
if ( V_13 )
return V_13 ;
return strlen ( V_66 ) ;
}
static int
F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_63 * V_64 = & V_2 -> V_69 -> V_2 ;
int V_13 , V_44 ;
V_13 = F_22 ( V_64 , & V_70 ) ;
if ( V_13 )
return V_13 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_45 ; V_44 ++ ) {
struct V_26 * V_27 = & V_7 -> V_27 [ V_44 ] ;
V_27 -> V_71 . V_72 . V_73 = V_27 -> V_73 ;
V_27 -> V_71 . V_72 . V_74 = V_75 ;
V_27 -> V_71 . V_76 = F_16 ;
V_27 -> V_71 . V_77 = NULL ;
F_23 ( & V_27 -> V_71 . V_72 ) ;
V_13 = F_22 ( V_64 , & V_27 -> V_71 ) ;
if ( V_13 ) {
F_7 ( V_2 , L_17 ,
V_27 -> V_46 , V_44 ) ;
V_27 -> V_71 . V_72 . V_73 = NULL ;
F_24 ( V_2 ) ;
return V_13 ;
}
}
return 0 ;
}
static void
F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_63 * V_64 = & V_2 -> V_69 -> V_2 ;
int V_44 ;
F_26 ( V_64 , & V_70 ) ;
for ( V_44 = 0 ; V_44 < V_7 -> V_45 ; V_44 ++ ) {
struct V_26 * V_43 = & V_7 -> V_27 [ V_44 ] ;
if ( ! V_43 -> V_71 . V_72 . V_73 )
break;
F_26 ( V_64 , & V_43 -> V_71 ) ;
}
}
static T_2
F_27 ( struct V_63 * V_64 , struct V_65 * V_28 , char * V_66 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
return snprintf ( V_66 , V_67 , L_18 , V_7 -> V_78 ( V_2 ) * 1000 ) ;
}
static T_2
F_29 ( struct V_63 * V_64 , struct V_65 * V_28 , char * V_66 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_79 * V_80 = & V_7 -> V_81 ;
return snprintf ( V_66 , V_67 , L_18 , V_80 -> V_82 * 1000 ) ;
}
static T_2
F_30 ( struct V_63 * V_64 , struct V_65 * V_28 ,
const char * V_66 , T_3 V_68 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_79 * V_80 = & V_7 -> V_81 ;
long V_83 ;
if ( F_31 ( V_66 , 10 , & V_83 ) == - V_47 )
return V_68 ;
V_80 -> V_82 = V_83 / 1000 ;
F_32 ( V_2 ) ;
return V_68 ;
}
static T_2
F_33 ( struct V_63 * V_64 , struct V_65 * V_28 ,
char * V_66 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_79 * V_80 = & V_7 -> V_81 ;
return snprintf ( V_66 , V_67 , L_18 , V_80 -> V_84 * 1000 ) ;
}
static T_2
F_34 ( struct V_63 * V_64 , struct V_65 * V_28 ,
const char * V_66 ,
T_3 V_68 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_79 * V_80 = & V_7 -> V_81 ;
long V_83 ;
if ( F_31 ( V_66 , 10 , & V_83 ) == - V_47 )
return V_68 ;
V_80 -> V_84 = V_83 / 1000 ;
F_32 ( V_2 ) ;
return V_68 ;
}
static T_2 F_35 ( struct V_63 * V_2 ,
struct V_65 * V_72 ,
char * V_66 )
{
return sprintf ( V_66 , L_19 ) ;
}
static T_2 F_36 ( struct V_63 * V_2 ,
struct V_65 * V_72 ,
char * V_66 )
{
return sprintf ( V_66 , L_20 ) ;
}
static T_2
F_37 ( struct V_63 * V_64 , struct V_65 * V_72 ,
char * V_66 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_85 * V_86 = & V_4 -> V_8 . V_87 ;
struct V_9 V_10 ;
T_1 V_88 , V_36 , V_89 ;
T_4 V_90 ;
int V_13 ;
V_13 = F_2 ( V_2 , 0 , V_91 , 0xff , & V_10 ) ;
if ( V_13 )
return V_13 ;
V_90 = V_86 -> V_92 ( V_2 ) ;
V_89 = F_38 ( V_2 , 0 , V_10 . line ) ;
V_88 = 0 ;
do {
V_36 = F_38 ( V_2 , 0 , V_10 . line ) ;
if ( V_89 != V_36 ) {
V_88 ++ ;
V_89 = V_36 ;
}
F_39 ( 500 , 1000 ) ;
} while ( V_86 -> V_92 ( V_2 ) - V_90 < 250000000 );
return sprintf ( V_66 , L_21 , V_88 / 4 * 4 * 60 ) ;
}
static T_2
F_40 ( struct V_63 * V_64 , struct V_65 * V_28 , char * V_66 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
int V_13 ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_66 , L_21 , V_13 ) ;
}
static T_2
F_41 ( struct V_63 * V_64 , struct V_65 * V_28 ,
const char * V_66 , T_3 V_68 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
int V_13 = - V_15 ;
long V_83 ;
if ( V_40 != 7777 )
return - V_41 ;
if ( F_31 ( V_66 , 10 , & V_83 ) == - V_47 )
return - V_47 ;
if ( V_83 < V_7 -> V_23 . V_93 )
V_83 = V_7 -> V_23 . V_93 ;
if ( V_83 > V_7 -> V_23 . V_94 )
V_83 = V_7 -> V_23 . V_94 ;
V_13 = F_5 ( V_2 , V_83 ) ;
if ( V_13 )
return V_13 ;
return V_68 ;
}
static T_2
F_42 ( struct V_63 * V_64 ,
struct V_65 * V_28 , char * V_66 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
return sprintf ( V_66 , L_21 , V_7 -> V_23 . V_93 ) ;
}
static T_2
F_43 ( struct V_63 * V_64 , struct V_65 * V_28 ,
const char * V_66 , T_3 V_68 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
long V_83 ;
if ( F_31 ( V_66 , 10 , & V_83 ) == - V_47 )
return - V_47 ;
if ( V_83 < 0 )
V_83 = 0 ;
if ( V_7 -> V_23 . V_94 - V_83 < 10 )
V_83 = V_7 -> V_23 . V_94 - 10 ;
if ( V_83 < 10 )
V_7 -> V_23 . V_93 = 10 ;
else
V_7 -> V_23 . V_93 = V_83 ;
return V_68 ;
}
static T_2
F_44 ( struct V_63 * V_64 ,
struct V_65 * V_28 , char * V_66 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
return sprintf ( V_66 , L_21 , V_7 -> V_23 . V_94 ) ;
}
static T_2
F_45 ( struct V_63 * V_64 , struct V_65 * V_28 ,
const char * V_66 , T_3 V_68 )
{
struct V_1 * V_2 = F_28 ( V_64 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
long V_83 ;
if ( F_31 ( V_66 , 10 , & V_83 ) == - V_47 )
return - V_47 ;
if ( V_83 < 0 )
V_83 = 0 ;
if ( V_83 - V_7 -> V_23 . V_93 < 10 )
V_83 = V_7 -> V_23 . V_93 + 10 ;
if ( V_83 > 100 )
V_7 -> V_23 . V_94 = 100 ;
else
V_7 -> V_23 . V_94 = V_83 ;
return V_68 ;
}
static int
F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
#if F_47 ( V_95 ) || ( F_47 ( V_96 ) && F_47 ( V_97 ) )
struct V_63 * V_98 ;
int V_13 = 0 ;
if ( ! V_7 -> V_78 )
return - V_15 ;
V_98 = F_48 ( & V_2 -> V_69 -> V_2 ) ;
if ( F_9 ( V_98 ) ) {
V_13 = F_10 ( V_98 ) ;
F_7 ( V_2 ,
L_22 , V_13 ) ;
return V_13 ;
}
F_49 ( V_98 , V_2 ) ;
V_13 = F_50 ( & V_2 -> V_69 -> V_2 . V_99 , & V_100 ) ;
if ( V_13 ) {
if ( V_13 )
goto error;
}
if ( F_1 ( V_2 ) >= 0 ) {
V_13 = F_50 ( & V_2 -> V_69 -> V_2 . V_99 ,
& V_101 ) ;
if ( V_13 )
goto error;
}
if ( F_51 ( V_2 , V_91 ) ) {
V_13 = F_50 ( & V_2 -> V_69 -> V_2 . V_99 ,
& V_102 ) ;
if ( V_13 )
goto error;
}
V_7 -> V_103 = V_98 ;
return 0 ;
error:
F_7 ( V_2 , L_23 , V_13 ) ;
F_52 ( V_98 ) ;
V_7 -> V_103 = NULL ;
return V_13 ;
#else
V_7 -> V_103 = NULL ;
return 0 ;
#endif
}
static void
F_53 ( struct V_1 * V_2 )
{
#if F_47 ( V_95 ) || ( F_47 ( V_96 ) && F_47 ( V_97 ) )
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
if ( V_7 -> V_103 ) {
F_54 ( & V_2 -> V_69 -> V_2 . V_99 , & V_100 ) ;
F_54 ( & V_2 -> V_69 -> V_2 . V_99 , & V_101 ) ;
F_54 ( & V_2 -> V_69 -> V_2 . V_99 , & V_102 ) ;
F_52 ( V_7 -> V_103 ) ;
}
#endif
}
static int
F_55 ( struct V_104 * V_105 , unsigned long V_106 , void * V_107 )
{
struct V_3 * V_4 =
F_56 ( V_105 , struct V_3 , V_8 . V_7 . V_108 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_109 * V_110 = (struct V_109 * ) V_107 ;
if ( strcmp ( V_110 -> V_111 , L_24 ) == 0 ) {
bool V_112 = F_57 () ;
F_58 ( V_2 , L_25 , V_112 ? L_26 : L_27 ) ;
}
return V_113 ;
}
int
F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
char V_114 [ 256 ] ;
int V_13 , V_44 ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_13 ( V_2 , L_28 , V_7 -> V_45 ) ;
for ( V_44 = 0 ; V_44 < V_7 -> V_45 ; V_44 ++ ) {
F_15 ( & V_7 -> V_27 [ V_44 ] , V_114 , sizeof( V_114 ) ) ;
F_13 ( V_2 , L_29 , V_7 -> V_27 [ V_44 ] . V_46 , V_114 ) ;
}
V_13 = F_14 ( V_2 , & V_7 -> V_42 ) ;
if ( V_13 == 0 ) {
strncpy ( V_7 -> V_42 . V_73 , L_3 , 4 ) ;
V_7 -> V_36 = & V_7 -> V_42 ;
F_15 ( & V_7 -> V_42 , V_114 , sizeof( V_114 ) ) ;
F_13 ( V_2 , L_30 , V_114 ) ;
}
if ( V_115 != NULL ) {
V_13 = F_11 ( V_2 , V_115 ) ;
if ( V_13 ) {
F_7 ( V_2 , L_31 ,
V_115 , V_13 ) ;
}
}
F_21 ( V_2 ) ;
F_46 ( V_2 ) ;
#if F_47 ( V_116 ) && F_47 ( V_117 )
V_7 -> V_108 . V_118 = F_55 ;
F_64 ( & V_7 -> V_108 ) ;
#endif
return 0 ;
}
void
F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
if ( V_7 -> V_36 != & V_7 -> V_42 )
F_8 ( V_2 , & V_7 -> V_42 ) ;
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
#if F_47 ( V_116 ) && F_47 ( V_117 )
F_69 ( & V_7 -> V_108 ) ;
#endif
F_53 ( V_2 ) ;
F_25 ( V_2 ) ;
}
void
F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_26 * V_27 ;
if ( ! V_7 -> V_36 || V_7 -> V_36 == & V_7 -> V_42 )
return;
V_27 = V_7 -> V_36 ;
V_7 -> V_36 = & V_7 -> V_42 ;
F_8 ( V_2 , V_27 ) ;
}
