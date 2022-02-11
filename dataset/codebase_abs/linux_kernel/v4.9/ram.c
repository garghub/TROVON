static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = 0 ;
V_4 -> V_9 = 0 ;
return 0 ;
}
static struct V_10 *
F_2 ( struct V_10 * V_11 [] , T_1 * V_12 , T_1 V_13 ,
T_2 * V_14 ,
enum V_15 * V_16 , enum V_15 type ,
bool V_17 )
{
struct V_10 * V_18 ;
int V_19 = ( * V_12 ) ++ ;
if ( V_19 >= V_13 )
return NULL ;
V_18 = V_11 [ V_19 ] ;
if ( ! V_18 )
return NULL ;
if ( V_17 )
F_3 ( V_18 ) ;
if ( ! F_4 ( V_18 ) )
return NULL ;
* V_16 = type ;
* V_14 = V_19 ;
return V_18 ;
}
static int F_5 ( char * V_20 , struct V_21 * time ,
bool * V_22 )
{
char V_23 ;
int V_24 = 0 ;
if ( sscanf ( V_20 , V_25 L_1 , & time -> V_26 ,
& time -> V_27 , & V_23 , & V_24 ) == 3 ) {
if ( V_23 == 'C' )
* V_22 = true ;
else
* V_22 = false ;
} else if ( sscanf ( V_20 , V_25 L_2 ,
& time -> V_26 , & time -> V_27 , & V_24 ) == 2 ) {
* V_22 = false ;
} else {
time -> V_26 = 0 ;
time -> V_27 = 0 ;
* V_22 = false ;
}
return V_24 ;
}
static bool F_6 ( struct V_10 * V_18 )
{
return ! ! V_18 && ! ! ( F_4 ( V_18 ) +
F_7 ( V_18 , NULL , 0 ) ) ;
}
static T_3 F_8 ( T_2 * V_14 , enum V_15 * type ,
int * V_28 , struct V_21 * time ,
char * * V_29 , bool * V_22 ,
T_3 * V_30 ,
struct V_1 * V_2 )
{
T_3 V_31 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_18 = NULL ;
int V_24 = 0 ;
time -> V_26 = 0 ;
time -> V_27 = 0 ;
* V_22 = false ;
while ( V_4 -> V_6 < V_4 -> V_32 && ! V_18 ) {
V_18 = F_2 ( V_4 -> V_11 , & V_4 -> V_6 ,
V_4 -> V_32 , V_14 , type ,
V_33 , 1 ) ;
if ( ! F_6 ( V_18 ) )
continue;
V_24 = F_5 ( F_9 ( V_18 ) ,
time , V_22 ) ;
if ( ! V_24 ) {
F_10 ( V_18 ) ;
F_11 ( V_18 ) ;
V_18 = NULL ;
}
}
if ( ! F_6 ( V_18 ) )
V_18 = F_2 ( & V_4 -> V_34 , & V_4 -> V_7 ,
1 , V_14 , type , V_35 , 0 ) ;
if ( ! F_6 ( V_18 ) )
V_18 = F_2 ( & V_4 -> V_36 , & V_4 -> V_8 ,
1 , V_14 , type , V_37 , 0 ) ;
if ( ! F_6 ( V_18 ) )
V_18 = F_2 ( & V_4 -> V_38 , & V_4 -> V_9 ,
1 , V_14 , type , V_39 , 0 ) ;
if ( ! F_6 ( V_18 ) )
return 0 ;
V_31 = F_4 ( V_18 ) - V_24 ;
* V_30 = F_7 ( V_18 , NULL , 0 ) ;
* V_29 = F_12 ( V_31 + * V_30 + 1 , V_40 ) ;
if ( * V_29 == NULL )
return - V_41 ;
memcpy ( * V_29 , ( char * ) F_9 ( V_18 ) + V_24 , V_31 ) ;
F_7 ( V_18 , * V_29 + V_31 , * V_30 + 1 ) ;
return V_31 ;
}
static T_4 F_13 ( struct V_10 * V_18 ,
bool V_22 )
{
char * V_42 ;
struct V_21 V_43 ;
T_4 V_44 ;
if ( F_14 ( & V_43 ) ) {
V_43 . V_26 = 0 ;
V_43 . V_27 = 0 ;
}
V_42 = F_15 ( V_45 , V_25 L_3 ,
( long ) V_43 . V_26 , ( long ) ( V_43 . V_27 / 1000 ) ,
V_22 ? 'C' : 'D' ) ;
F_16 ( ! V_42 ) ;
V_44 = V_42 ? strlen ( V_42 ) : 0 ;
F_17 ( V_18 , V_42 , V_44 ) ;
F_18 ( V_42 ) ;
return V_44 ;
}
static int T_5 F_19 ( enum V_15 type ,
enum V_46 V_47 ,
T_2 * V_14 , unsigned int V_48 ,
const char * V_29 ,
bool V_22 , T_4 V_31 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_18 ;
T_4 V_49 ;
if ( type == V_35 ) {
if ( ! V_4 -> V_34 )
return - V_41 ;
F_17 ( V_4 -> V_34 , V_29 , V_31 ) ;
return 0 ;
} else if ( type == V_37 ) {
if ( ! V_4 -> V_36 )
return - V_41 ;
F_17 ( V_4 -> V_36 , V_29 , V_31 ) ;
return 0 ;
} else if ( type == V_39 ) {
if ( ! V_4 -> V_38 )
return - V_41 ;
F_17 ( V_4 -> V_38 , V_29 , V_31 ) ;
return 0 ;
}
if ( type != V_33 )
return - V_50 ;
if ( V_47 != V_51 &&
V_47 != V_52 )
return - V_50 ;
if ( V_47 == V_51 && ! V_4 -> V_53 )
return - V_50 ;
if ( V_48 != 1 )
return - V_54 ;
if ( ! V_4 -> V_11 )
return - V_54 ;
V_18 = V_4 -> V_11 [ V_4 -> V_55 ] ;
V_49 = F_13 ( V_18 , V_22 ) ;
if ( V_31 + V_49 > V_18 -> V_56 )
V_31 = V_18 -> V_56 - V_49 ;
F_17 ( V_18 , V_29 , V_31 ) ;
V_4 -> V_55 = ( V_4 -> V_55 + 1 ) % V_4 -> V_32 ;
return 0 ;
}
static int T_5 F_20 ( enum V_15 type ,
enum V_46 V_47 ,
T_2 * V_14 , unsigned int V_48 ,
const char T_6 * V_29 ,
bool V_22 , T_4 V_31 ,
struct V_1 * V_2 )
{
if ( type == V_39 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_38 )
return - V_41 ;
return F_21 ( V_4 -> V_38 , V_29 , V_31 ) ;
}
return - V_50 ;
}
static int F_22 ( enum V_15 type , T_2 V_14 , int V_28 ,
struct V_21 time , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_18 ;
switch ( type ) {
case V_33 :
if ( V_14 >= V_4 -> V_32 )
return - V_50 ;
V_18 = V_4 -> V_11 [ V_14 ] ;
break;
case V_35 :
V_18 = V_4 -> V_34 ;
break;
case V_37 :
V_18 = V_4 -> V_36 ;
break;
case V_39 :
V_18 = V_4 -> V_38 ;
break;
default:
return - V_50 ;
}
F_10 ( V_18 ) ;
F_11 ( V_18 ) ;
return 0 ;
}
static void F_23 ( struct V_3 * V_4 )
{
int V_19 ;
if ( ! V_4 -> V_11 )
return;
for ( V_19 = 0 ; V_19 < V_4 -> V_32 ; V_19 ++ )
F_24 ( V_4 -> V_11 [ V_19 ] ) ;
F_18 ( V_4 -> V_11 ) ;
V_4 -> V_32 = 0 ;
}
static int F_25 ( struct V_57 * V_58 , struct V_3 * V_4 ,
T_7 * V_59 , T_4 V_60 )
{
int V_61 = - V_41 ;
int V_19 ;
if ( ! V_4 -> V_62 )
return 0 ;
if ( * V_59 + V_60 - V_4 -> V_63 > V_4 -> V_31 ) {
F_26 ( V_58 , L_4 ) ;
return - V_41 ;
}
V_4 -> V_32 = V_60 / V_4 -> V_62 ;
if ( ! V_4 -> V_32 )
return - V_41 ;
V_4 -> V_11 = F_27 ( sizeof( * V_4 -> V_11 ) * V_4 -> V_32 ,
V_40 ) ;
if ( ! V_4 -> V_11 ) {
F_26 ( V_58 , L_5 ) ;
goto V_64;
}
for ( V_19 = 0 ; V_19 < V_4 -> V_32 ; V_19 ++ ) {
V_4 -> V_11 [ V_19 ] = F_28 ( * V_59 , V_4 -> V_62 , 0 ,
& V_4 -> V_65 ,
V_4 -> V_66 ) ;
if ( F_29 ( V_4 -> V_11 [ V_19 ] ) ) {
V_61 = F_30 ( V_4 -> V_11 [ V_19 ] ) ;
F_26 ( V_58 , L_6 ,
V_4 -> V_62 , ( unsigned long long ) * V_59 , V_61 ) ;
while ( V_19 > 0 ) {
V_19 -- ;
F_24 ( V_4 -> V_11 [ V_19 ] ) ;
}
goto V_67;
}
* V_59 += V_4 -> V_62 ;
}
return 0 ;
V_67:
F_18 ( V_4 -> V_11 ) ;
V_64:
V_4 -> V_32 = 0 ;
return V_61 ;
}
static int F_31 ( struct V_57 * V_58 , struct V_3 * V_4 ,
struct V_10 * * V_18 ,
T_7 * V_59 , T_4 V_68 , T_8 V_69 )
{
if ( ! V_68 )
return 0 ;
if ( * V_59 + V_68 - V_4 -> V_63 > V_4 -> V_31 ) {
F_26 ( V_58 , L_7 ,
V_68 , ( unsigned long long ) * V_59 ,
V_4 -> V_31 , ( unsigned long long ) V_4 -> V_63 ) ;
return - V_41 ;
}
* V_18 = F_28 ( * V_59 , V_68 , V_69 , & V_4 -> V_65 , V_4 -> V_66 ) ;
if ( F_29 ( * V_18 ) ) {
int V_61 = F_30 ( * V_18 ) ;
F_26 ( V_58 , L_6 ,
V_68 , ( unsigned long long ) * V_59 , V_61 ) ;
return V_61 ;
}
F_11 ( * V_18 ) ;
* V_59 += V_68 ;
return 0 ;
}
static int F_32 ( struct V_70 * V_71 ,
const char * V_72 , T_8 * V_73 )
{
T_8 V_74 = 0 ;
int V_75 ;
V_75 = F_33 ( V_71 -> V_58 . V_76 , V_72 , & V_74 ) ;
if ( V_75 < 0 && V_75 != - V_50 ) {
F_26 ( & V_71 -> V_58 , L_8 ,
V_72 , V_75 ) ;
return V_75 ;
}
if ( V_74 > V_77 ) {
F_26 ( & V_71 -> V_58 , L_9 , V_72 , V_74 ) ;
return - V_78 ;
}
* V_73 = V_74 ;
return 0 ;
}
static int F_34 ( struct V_70 * V_71 ,
struct V_79 * V_80 )
{
struct V_81 * V_76 = V_71 -> V_58 . V_76 ;
struct V_82 * V_83 ;
T_8 V_73 ;
int V_75 ;
F_35 ( & V_71 -> V_58 , L_10 ) ;
V_83 = F_36 ( V_71 , V_84 , 0 ) ;
if ( ! V_83 ) {
F_26 ( & V_71 -> V_58 ,
L_11 ) ;
return - V_50 ;
}
V_80 -> V_85 = F_37 ( V_83 ) ;
V_80 -> V_86 = V_83 -> V_87 ;
V_80 -> V_88 = F_38 ( V_76 , L_12 ) ;
V_80 -> V_53 = ! F_38 ( V_76 , L_13 ) ;
#define F_39 ( T_9 , T_10 ) { \
ret = ramoops_parse_dt_size(pdev, name, &value); \
if (ret < 0) \
return ret; \
field = value; \
}
F_39 ( L_14 , V_80 -> V_62 ) ;
F_39 ( L_15 , V_80 -> V_89 ) ;
F_39 ( L_16 , V_80 -> V_90 ) ;
F_39 ( L_17 , V_80 -> V_91 ) ;
F_39 ( L_18 , V_80 -> V_65 . V_92 ) ;
#undef F_39
return 0 ;
}
static int F_40 ( struct V_70 * V_71 )
{
struct V_57 * V_58 = & V_71 -> V_58 ;
struct V_79 * V_80 = V_58 -> V_93 ;
struct V_3 * V_4 = & V_94 ;
T_4 V_60 ;
T_7 V_59 ;
int V_61 = - V_50 ;
if ( F_41 ( V_58 ) && ! V_80 ) {
V_80 = F_42 ( & V_71 -> V_58 , sizeof( * V_80 ) , V_40 ) ;
if ( ! V_80 ) {
V_61 = - V_41 ;
goto V_95;
}
V_61 = F_34 ( V_71 , V_80 ) ;
if ( V_61 < 0 )
goto V_95;
}
if ( V_4 -> V_32 )
goto V_95;
if ( ! V_80 -> V_85 || ( ! V_80 -> V_62 && ! V_80 -> V_89 &&
! V_80 -> V_90 && ! V_80 -> V_91 ) ) {
F_43 ( L_19
L_20 ) ;
goto V_95;
}
if ( V_80 -> V_62 && ! F_44 ( V_80 -> V_62 ) )
V_80 -> V_62 = F_45 ( V_80 -> V_62 ) ;
if ( V_80 -> V_89 && ! F_44 ( V_80 -> V_89 ) )
V_80 -> V_89 = F_45 ( V_80 -> V_89 ) ;
if ( V_80 -> V_90 && ! F_44 ( V_80 -> V_90 ) )
V_80 -> V_90 = F_45 ( V_80 -> V_90 ) ;
if ( V_80 -> V_91 && ! F_44 ( V_80 -> V_91 ) )
V_80 -> V_91 = F_45 ( V_80 -> V_91 ) ;
V_4 -> V_31 = V_80 -> V_85 ;
V_4 -> V_63 = V_80 -> V_86 ;
V_4 -> V_66 = V_80 -> V_88 ;
V_4 -> V_62 = V_80 -> V_62 ;
V_4 -> V_89 = V_80 -> V_89 ;
V_4 -> V_90 = V_80 -> V_90 ;
V_4 -> V_91 = V_80 -> V_91 ;
V_4 -> V_53 = V_80 -> V_53 ;
V_4 -> V_65 = V_80 -> V_65 ;
V_59 = V_4 -> V_63 ;
V_60 = V_4 -> V_31 - V_4 -> V_89 - V_4 -> V_90
- V_4 -> V_91 ;
V_61 = F_25 ( V_58 , V_4 , & V_59 , V_60 ) ;
if ( V_61 )
goto V_95;
V_61 = F_31 ( V_58 , V_4 , & V_4 -> V_34 , & V_59 ,
V_4 -> V_89 , 0 ) ;
if ( V_61 )
goto V_96;
V_61 = F_31 ( V_58 , V_4 , & V_4 -> V_36 , & V_59 , V_4 -> V_90 ,
V_97 ) ;
if ( V_61 )
goto V_98;
V_61 = F_31 ( V_58 , V_4 , & V_4 -> V_38 , & V_59 , V_4 -> V_91 , 0 ) ;
if ( V_61 )
goto V_99;
V_4 -> V_100 . V_5 = V_4 ;
if ( V_4 -> V_89 )
V_4 -> V_100 . V_101 = 1024 ;
V_4 -> V_100 . V_101 = V_13 ( V_4 -> V_62 , V_4 -> V_100 . V_101 ) ;
V_4 -> V_100 . V_29 = F_12 ( V_4 -> V_100 . V_101 , V_40 ) ;
if ( ! V_4 -> V_100 . V_29 ) {
F_43 ( L_21 ) ;
V_61 = - V_41 ;
goto V_102;
}
F_46 ( & V_4 -> V_100 . V_103 ) ;
V_4 -> V_100 . V_104 = V_105 ;
if ( V_4 -> V_89 )
V_4 -> V_100 . V_104 |= V_106 ;
if ( V_4 -> V_90 )
V_4 -> V_100 . V_104 |= V_107 ;
if ( V_4 -> V_91 )
V_4 -> V_100 . V_104 |= V_108 ;
V_61 = F_47 ( & V_4 -> V_100 ) ;
if ( V_61 ) {
F_43 ( L_22 ) ;
goto V_109;
}
V_85 = V_80 -> V_85 ;
V_86 = V_80 -> V_86 ;
V_62 = V_80 -> V_62 ;
V_53 = V_80 -> V_53 ;
V_110 = V_80 -> V_89 ;
V_111 = V_80 -> V_91 ;
V_112 = V_80 -> V_90 ;
F_48 ( L_23 ,
V_4 -> V_31 , ( unsigned long long ) V_4 -> V_63 ,
V_4 -> V_65 . V_92 , V_4 -> V_65 . V_113 ) ;
return 0 ;
V_109:
F_18 ( V_4 -> V_100 . V_29 ) ;
V_102:
V_4 -> V_100 . V_101 = 0 ;
F_24 ( V_4 -> V_38 ) ;
V_99:
F_24 ( V_4 -> V_36 ) ;
V_98:
F_24 ( V_4 -> V_34 ) ;
V_96:
F_23 ( V_4 ) ;
V_95:
return V_61 ;
}
static int F_49 ( struct V_70 * V_71 )
{
struct V_3 * V_4 = & V_94 ;
F_50 ( & V_4 -> V_100 ) ;
F_18 ( V_4 -> V_100 . V_29 ) ;
V_4 -> V_100 . V_101 = 0 ;
F_24 ( V_4 -> V_38 ) ;
F_24 ( V_4 -> V_36 ) ;
F_24 ( V_4 -> V_34 ) ;
F_23 ( V_4 ) ;
return 0 ;
}
static void F_51 ( void )
{
if ( ! V_85 )
return;
F_48 ( L_24 ) ;
V_114 = F_27 ( sizeof( * V_114 ) , V_40 ) ;
if ( ! V_114 ) {
F_48 ( L_25 ) ;
return;
}
V_114 -> V_85 = V_85 ;
V_114 -> V_86 = V_86 ;
V_114 -> V_88 = V_88 ;
V_114 -> V_62 = V_62 ;
V_114 -> V_89 = V_110 ;
V_114 -> V_90 = V_112 ;
V_114 -> V_91 = V_111 ;
V_114 -> V_53 = V_53 ;
V_114 -> V_65 . V_92 = V_115 == 1 ? 16 : V_115 ;
V_116 = F_52 ( NULL , L_26 , - 1 ,
V_114 , sizeof( struct V_79 ) ) ;
if ( F_29 ( V_116 ) ) {
F_48 ( L_27 ,
F_30 ( V_116 ) ) ;
}
}
static int T_11 F_53 ( void )
{
F_51 () ;
return F_54 ( & V_117 ) ;
}
static void T_12 F_55 ( void )
{
F_56 ( & V_117 ) ;
F_57 ( V_116 ) ;
F_18 ( V_114 ) ;
}
