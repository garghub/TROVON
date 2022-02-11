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
static int F_20 ( enum V_15 type , T_2 V_14 , int V_28 ,
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
static void F_21 ( struct V_3 * V_4 )
{
int V_19 ;
V_4 -> V_32 = 0 ;
if ( ! V_4 -> V_11 )
return;
for ( V_19 = 0 ; ! F_22 ( V_4 -> V_11 [ V_19 ] ) ; V_19 ++ )
F_23 ( V_4 -> V_11 [ V_19 ] ) ;
F_18 ( V_4 -> V_11 ) ;
}
static int F_24 ( struct V_57 * V_58 , struct V_3 * V_4 ,
T_6 * V_59 , T_4 V_60 )
{
int V_61 = - V_41 ;
int V_19 ;
if ( ! V_4 -> V_62 )
return 0 ;
if ( * V_59 + V_60 - V_4 -> V_63 > V_4 -> V_31 ) {
F_25 ( V_58 , L_4 ) ;
return - V_41 ;
}
V_4 -> V_32 = V_60 / V_4 -> V_62 ;
if ( ! V_4 -> V_32 )
return - V_41 ;
V_4 -> V_11 = F_26 ( sizeof( * V_4 -> V_11 ) * V_4 -> V_32 ,
V_40 ) ;
if ( ! V_4 -> V_11 ) {
F_25 ( V_58 , L_5 ) ;
goto V_64;
}
for ( V_19 = 0 ; V_19 < V_4 -> V_32 ; V_19 ++ ) {
V_4 -> V_11 [ V_19 ] = F_27 ( * V_59 , V_4 -> V_62 , 0 ,
& V_4 -> V_65 ,
V_4 -> V_66 ) ;
if ( F_28 ( V_4 -> V_11 [ V_19 ] ) ) {
V_61 = F_29 ( V_4 -> V_11 [ V_19 ] ) ;
F_25 ( V_58 , L_6 ,
V_4 -> V_62 , ( unsigned long long ) * V_59 , V_61 ) ;
goto V_64;
}
* V_59 += V_4 -> V_62 ;
}
return 0 ;
V_64:
F_21 ( V_4 ) ;
return V_61 ;
}
static int F_30 ( struct V_57 * V_58 , struct V_3 * V_4 ,
struct V_10 * * V_18 ,
T_6 * V_59 , T_4 V_67 , T_7 V_68 )
{
if ( ! V_67 )
return 0 ;
if ( * V_59 + V_67 - V_4 -> V_63 > V_4 -> V_31 ) {
F_25 ( V_58 , L_7 ,
V_67 , ( unsigned long long ) * V_59 ,
V_4 -> V_31 , ( unsigned long long ) V_4 -> V_63 ) ;
return - V_41 ;
}
* V_18 = F_27 ( * V_59 , V_67 , V_68 , & V_4 -> V_65 , V_4 -> V_66 ) ;
if ( F_28 ( * V_18 ) ) {
int V_61 = F_29 ( * V_18 ) ;
F_25 ( V_58 , L_6 ,
V_67 , ( unsigned long long ) * V_59 , V_61 ) ;
return V_61 ;
}
F_11 ( * V_18 ) ;
* V_59 += V_67 ;
return 0 ;
}
static int F_31 ( struct V_69 * V_70 ,
const char * V_71 , T_7 * V_72 )
{
T_7 V_73 = 0 ;
int V_74 ;
V_74 = F_32 ( V_70 -> V_58 . V_75 , V_71 , & V_73 ) ;
if ( V_74 < 0 && V_74 != - V_50 ) {
F_25 ( & V_70 -> V_58 , L_8 ,
V_71 , V_74 ) ;
return V_74 ;
}
if ( V_73 > V_76 ) {
F_25 ( & V_70 -> V_58 , L_9 , V_71 , V_73 ) ;
return - V_77 ;
}
* V_72 = V_73 ;
return 0 ;
}
static int F_33 ( struct V_69 * V_70 ,
struct V_78 * V_79 )
{
struct V_80 * V_75 = V_70 -> V_58 . V_75 ;
struct V_81 * V_82 ;
T_7 V_72 ;
int V_74 ;
F_34 ( & V_70 -> V_58 , L_10 ) ;
V_82 = F_35 ( V_70 , V_83 , 0 ) ;
if ( ! V_82 ) {
F_25 ( & V_70 -> V_58 ,
L_11 ) ;
return - V_50 ;
}
V_79 -> V_84 = F_36 ( V_82 ) ;
V_79 -> V_85 = V_82 -> V_86 ;
V_79 -> V_87 = F_37 ( V_75 , L_12 ) ;
V_79 -> V_53 = ! F_37 ( V_75 , L_13 ) ;
#define F_38 ( T_8 , T_9 ) { \
ret = ramoops_parse_dt_size(pdev, name, &value); \
if (ret < 0) \
return ret; \
field = value; \
}
F_38 ( L_14 , V_79 -> V_62 ) ;
F_38 ( L_15 , V_79 -> V_88 ) ;
F_38 ( L_16 , V_79 -> V_89 ) ;
F_38 ( L_17 , V_79 -> V_90 ) ;
F_38 ( L_18 , V_79 -> V_65 . V_91 ) ;
#undef F_38
return 0 ;
}
static int F_39 ( struct V_69 * V_70 )
{
struct V_57 * V_58 = & V_70 -> V_58 ;
struct V_78 * V_79 = V_58 -> V_92 ;
struct V_3 * V_4 = & V_93 ;
T_4 V_60 ;
T_6 V_59 ;
int V_61 = - V_50 ;
if ( F_40 ( V_58 ) && ! V_79 ) {
V_79 = F_41 ( & V_70 -> V_58 , sizeof( * V_79 ) , V_40 ) ;
if ( ! V_79 ) {
V_61 = - V_41 ;
goto V_94;
}
V_61 = F_33 ( V_70 , V_79 ) ;
if ( V_61 < 0 )
goto V_94;
}
if ( V_4 -> V_32 )
goto V_94;
if ( ! V_79 -> V_84 || ( ! V_79 -> V_62 && ! V_79 -> V_88 &&
! V_79 -> V_89 && ! V_79 -> V_90 ) ) {
F_42 ( L_19
L_20 ) ;
goto V_94;
}
if ( V_79 -> V_62 && ! F_43 ( V_79 -> V_62 ) )
V_79 -> V_62 = F_44 ( V_79 -> V_62 ) ;
if ( V_79 -> V_88 && ! F_43 ( V_79 -> V_88 ) )
V_79 -> V_88 = F_44 ( V_79 -> V_88 ) ;
if ( V_79 -> V_89 && ! F_43 ( V_79 -> V_89 ) )
V_79 -> V_89 = F_44 ( V_79 -> V_89 ) ;
if ( V_79 -> V_90 && ! F_43 ( V_79 -> V_90 ) )
V_79 -> V_90 = F_44 ( V_79 -> V_90 ) ;
V_4 -> V_31 = V_79 -> V_84 ;
V_4 -> V_63 = V_79 -> V_85 ;
V_4 -> V_66 = V_79 -> V_87 ;
V_4 -> V_62 = V_79 -> V_62 ;
V_4 -> V_88 = V_79 -> V_88 ;
V_4 -> V_89 = V_79 -> V_89 ;
V_4 -> V_90 = V_79 -> V_90 ;
V_4 -> V_53 = V_79 -> V_53 ;
V_4 -> V_65 = V_79 -> V_65 ;
V_59 = V_4 -> V_63 ;
V_60 = V_4 -> V_31 - V_4 -> V_88 - V_4 -> V_89
- V_4 -> V_90 ;
V_61 = F_24 ( V_58 , V_4 , & V_59 , V_60 ) ;
if ( V_61 )
goto V_94;
V_61 = F_30 ( V_58 , V_4 , & V_4 -> V_34 , & V_59 ,
V_4 -> V_88 , 0 ) ;
if ( V_61 )
goto V_95;
V_61 = F_30 ( V_58 , V_4 , & V_4 -> V_36 , & V_59 , V_4 -> V_89 ,
V_96 ) ;
if ( V_61 )
goto V_97;
V_61 = F_30 ( V_58 , V_4 , & V_4 -> V_38 , & V_59 , V_4 -> V_90 , 0 ) ;
if ( V_61 )
goto V_98;
V_4 -> V_99 . V_5 = V_4 ;
if ( V_4 -> V_88 )
V_4 -> V_99 . V_100 = 1024 ;
V_4 -> V_99 . V_100 = V_13 ( V_4 -> V_62 , V_4 -> V_99 . V_100 ) ;
V_4 -> V_99 . V_29 = F_12 ( V_4 -> V_99 . V_100 , V_40 ) ;
F_45 ( & V_4 -> V_99 . V_101 ) ;
if ( ! V_4 -> V_99 . V_29 ) {
F_42 ( L_21 ) ;
V_61 = - V_41 ;
goto V_102;
}
V_61 = F_46 ( & V_4 -> V_99 ) ;
if ( V_61 ) {
F_42 ( L_22 ) ;
goto V_103;
}
V_84 = V_79 -> V_84 ;
V_85 = V_79 -> V_85 ;
V_62 = V_79 -> V_62 ;
V_53 = V_79 -> V_53 ;
V_104 = V_79 -> V_88 ;
V_105 = V_79 -> V_90 ;
V_106 = V_79 -> V_89 ;
F_47 ( L_23 ,
V_4 -> V_31 , ( unsigned long long ) V_4 -> V_63 ,
V_4 -> V_65 . V_91 , V_4 -> V_65 . V_107 ) ;
return 0 ;
V_103:
F_18 ( V_4 -> V_99 . V_29 ) ;
V_102:
V_4 -> V_99 . V_100 = 0 ;
F_23 ( V_4 -> V_38 ) ;
V_98:
F_23 ( V_4 -> V_36 ) ;
V_97:
F_23 ( V_4 -> V_34 ) ;
V_95:
F_21 ( V_4 ) ;
V_94:
return V_61 ;
}
static int F_48 ( struct V_69 * V_70 )
{
struct V_3 * V_4 = & V_93 ;
F_49 ( & V_4 -> V_99 ) ;
V_4 -> V_32 = 0 ;
F_18 ( V_4 -> V_99 . V_29 ) ;
V_4 -> V_99 . V_100 = 0 ;
F_23 ( V_4 -> V_38 ) ;
F_23 ( V_4 -> V_36 ) ;
F_23 ( V_4 -> V_34 ) ;
F_21 ( V_4 ) ;
return 0 ;
}
static void F_50 ( void )
{
if ( ! V_84 )
return;
F_47 ( L_24 ) ;
V_108 = F_26 ( sizeof( * V_108 ) , V_40 ) ;
if ( ! V_108 ) {
F_47 ( L_25 ) ;
return;
}
V_108 -> V_84 = V_84 ;
V_108 -> V_85 = V_85 ;
V_108 -> V_87 = V_87 ;
V_108 -> V_62 = V_62 ;
V_108 -> V_88 = V_104 ;
V_108 -> V_89 = V_106 ;
V_108 -> V_90 = V_105 ;
V_108 -> V_53 = V_53 ;
V_108 -> V_65 . V_91 = V_109 == 1 ? 16 : V_109 ;
V_110 = F_51 ( NULL , L_26 , - 1 ,
V_108 , sizeof( struct V_78 ) ) ;
if ( F_28 ( V_110 ) ) {
F_47 ( L_27 ,
F_29 ( V_110 ) ) ;
}
}
static int T_10 F_52 ( void )
{
F_50 () ;
return F_53 ( & V_111 ) ;
}
static void T_11 F_54 ( void )
{
F_55 ( & V_111 ) ;
F_56 ( V_110 ) ;
F_18 ( V_108 ) ;
}
