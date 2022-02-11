static int T_1 F_1 ( char * V_1 )
{
#ifdef F_2
V_2 = 1 ;
#endif
return 1 ;
}
static T_2 F_3 ( char T_3 * V_3 , T_4 V_4 ,
T_5 * V_5 , T_6 * V_6 )
{
char V_7 [ V_8 ] ;
T_2 V_9 ;
V_9 = F_4 ( V_7 , V_8 , L_1 , F_5 ( V_6 ) ) ;
return F_6 ( V_3 , V_4 , V_5 , V_7 , V_9 ) ;
}
static T_2 F_7 ( struct V_10 * V_11 ,
char T_3 * V_3 ,
T_4 V_4 , T_5 * V_5 )
{
return F_3 ( V_3 , V_4 , V_5 , & V_12 . V_13 ) ;
}
static T_2 F_8 ( struct V_10 * V_11 ,
char T_3 * V_3 ,
T_4 V_4 , T_5 * V_5 )
{
return F_3 ( V_3 , V_4 , V_5 , & V_12 . V_9 ) ;
}
static void * F_9 ( struct V_14 * V_15 , T_5 * V_16 )
{
T_5 V_17 = * V_16 ;
struct V_18 * V_19 ;
F_10 () ;
F_11 (qe, &ima_measurements, later) {
if ( ! V_17 -- ) {
F_12 () ;
return V_19 ;
}
}
F_12 () ;
return NULL ;
}
static void * F_13 ( struct V_14 * V_15 , void * V_20 , T_5 * V_16 )
{
struct V_18 * V_19 = V_20 ;
F_10 () ;
V_19 = F_14 ( V_19 -> V_21 . V_22 , struct V_18 , V_21 ) ;
F_12 () ;
( * V_16 ) ++ ;
return ( & V_19 -> V_21 == & V_23 ) ? NULL : V_19 ;
}
static void F_15 ( struct V_14 * V_15 , void * V_20 )
{
}
void F_16 ( struct V_14 * V_15 , void * V_24 , int V_25 )
{
while ( V_25 -- )
F_17 ( V_15 , * ( char * ) V_24 ++ ) ;
}
int F_18 ( struct V_14 * V_15 , void * V_20 )
{
struct V_18 * V_19 = V_20 ;
struct V_26 * V_27 ;
char * V_28 ;
T_7 V_29 , V_30 , V_31 ;
bool V_32 = false ;
int V_33 ;
V_27 = V_19 -> V_34 ;
if ( V_27 == NULL )
return - 1 ;
V_28 = ( V_27 -> V_35 -> V_36 [ 0 ] != '\0' ) ?
V_27 -> V_35 -> V_36 : V_27 -> V_35 -> V_37 ;
V_29 = ! V_2 ? V_27 -> V_29 : F_19 ( V_27 -> V_29 ) ;
F_16 ( V_15 , & V_29 , sizeof( V_27 -> V_29 ) ) ;
F_16 ( V_15 , V_27 -> V_38 , V_39 ) ;
V_30 = ! V_2 ? strlen ( V_28 ) :
F_19 ( strlen ( V_28 ) ) ;
F_16 ( V_15 , & V_30 , sizeof( V_30 ) ) ;
F_16 ( V_15 , V_28 , strlen ( V_28 ) ) ;
if ( strcmp ( V_28 , V_40 ) == 0 )
V_32 = true ;
if ( ! V_32 ) {
V_31 = ! V_2 ? V_27 -> V_31 :
F_19 ( V_27 -> V_31 ) ;
F_16 ( V_15 , & V_31 , sizeof( V_27 -> V_31 ) ) ;
}
for ( V_33 = 0 ; V_33 < V_27 -> V_35 -> V_41 ; V_33 ++ ) {
enum V_42 V_43 = V_44 ;
struct V_45 * V_46 = V_27 -> V_35 -> V_47 [ V_33 ] ;
if ( V_32 && strcmp ( V_46 -> V_48 , L_2 ) == 0 )
V_43 = V_49 ;
if ( V_32 && strcmp ( V_46 -> V_48 , L_3 ) == 0 )
V_43 = V_50 ;
V_46 -> V_51 ( V_15 , V_43 , & V_27 -> V_52 [ V_33 ] ) ;
}
return 0 ;
}
static int F_20 ( struct V_53 * V_53 , struct V_10 * V_10 )
{
return F_21 ( V_10 , & V_54 ) ;
}
void F_22 ( struct V_14 * V_15 , T_8 * V_38 , T_7 V_55 )
{
T_7 V_33 ;
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ )
F_23 ( V_15 , L_4 , * ( V_38 + V_33 ) ) ;
}
static int F_24 ( struct V_14 * V_15 , void * V_20 )
{
struct V_18 * V_19 = V_20 ;
struct V_26 * V_27 ;
char * V_28 ;
int V_33 ;
V_27 = V_19 -> V_34 ;
if ( V_27 == NULL )
return - 1 ;
V_28 = ( V_27 -> V_35 -> V_36 [ 0 ] != '\0' ) ?
V_27 -> V_35 -> V_36 : V_27 -> V_35 -> V_37 ;
F_23 ( V_15 , L_5 , V_27 -> V_29 ) ;
F_22 ( V_15 , V_27 -> V_38 , V_39 ) ;
F_23 ( V_15 , L_6 , V_28 ) ;
for ( V_33 = 0 ; V_33 < V_27 -> V_35 -> V_41 ; V_33 ++ ) {
F_25 ( V_15 , L_7 ) ;
if ( V_27 -> V_52 [ V_33 ] . V_9 == 0 )
continue;
V_27 -> V_35 -> V_47 [ V_33 ] -> V_51 ( V_15 , V_56 ,
& V_27 -> V_52 [ V_33 ] ) ;
}
F_25 ( V_15 , L_8 ) ;
return 0 ;
}
static int F_26 ( struct V_53 * V_53 , struct V_10 * V_10 )
{
return F_21 ( V_10 , & V_57 ) ;
}
static T_2 F_27 ( char * V_58 )
{
void * V_24 ;
char * V_59 ;
T_5 V_55 ;
int V_60 , V_61 = strlen ( V_58 ) ;
char * V_62 ;
V_59 = V_58 ;
F_28 ( & V_59 , L_8 ) ;
V_60 = F_29 ( V_58 , & V_24 , & V_55 , 0 , V_63 ) ;
if ( V_60 < 0 ) {
F_30 ( L_9 , V_58 , V_60 ) ;
return V_60 ;
}
V_59 = V_24 ;
while ( V_55 > 0 && ( V_62 = F_28 ( & V_59 , L_8 ) ) ) {
F_31 ( L_10 , V_62 ) ;
V_60 = F_32 ( V_62 ) ;
if ( V_60 < 0 )
break;
V_55 -= V_60 ;
}
F_33 ( V_24 ) ;
if ( V_60 < 0 )
return V_60 ;
else if ( V_55 )
return - V_64 ;
else
return V_61 ;
}
static T_2 F_34 ( struct V_10 * V_10 , const char T_3 * V_3 ,
T_4 V_25 , T_5 * V_5 )
{
char * V_24 ;
T_2 V_65 ;
if ( V_25 >= V_66 )
V_25 = V_66 - 1 ;
V_65 = - V_64 ;
if ( * V_5 != 0 )
goto V_67;
V_65 = - V_68 ;
V_24 = F_35 ( V_25 + 1 , V_69 ) ;
if ( ! V_24 )
goto V_67;
* ( V_24 + V_25 ) = '\0' ;
V_65 = - V_70 ;
if ( F_36 ( V_24 , V_3 , V_25 ) )
goto V_71;
V_65 = F_37 ( & V_72 ) ;
if ( V_65 < 0 )
goto V_71;
if ( V_24 [ 0 ] == '/' ) {
V_65 = F_27 ( V_24 ) ;
} else if ( V_73 & V_74 ) {
F_30 ( L_11 ) ;
F_38 ( V_75 , NULL , NULL ,
L_12 , L_13 ,
1 , 0 ) ;
if ( V_73 & V_76 )
V_65 = - V_77 ;
} else {
V_65 = F_32 ( V_24 ) ;
}
F_39 ( & V_72 ) ;
V_71:
F_40 ( V_24 ) ;
V_67:
if ( V_65 < 0 )
V_78 = 0 ;
return V_65 ;
}
static int F_41 ( struct V_53 * V_53 , struct V_10 * V_11 )
{
if ( ! ( V_11 -> V_79 & V_80 ) ) {
#ifndef F_42
return - V_77 ;
#else
if ( ( V_11 -> V_79 & V_81 ) != V_82 )
return - V_77 ;
if ( ! F_43 ( V_83 ) )
return - V_84 ;
return F_21 ( V_11 , & V_85 ) ;
#endif
}
if ( F_44 ( V_86 , & V_87 ) )
return - V_88 ;
return 0 ;
}
static int F_45 ( struct V_53 * V_53 , struct V_10 * V_10 )
{
const char * V_89 = V_78 ? L_14 : L_15 ;
if ( ( V_10 -> V_79 & V_81 ) == V_82 )
return F_46 ( V_53 , V_10 ) ;
if ( V_78 && F_47 () < 0 ) {
V_89 = L_15 ;
V_78 = 0 ;
}
F_48 ( L_16 , V_89 ) ;
F_38 ( V_75 , NULL , NULL ,
L_12 , V_89 , ! V_78 , 0 ) ;
if ( ! V_78 ) {
F_49 () ;
V_78 = 1 ;
F_50 ( V_86 , & V_87 ) ;
return 0 ;
}
F_51 () ;
#ifndef F_52
F_53 ( V_90 ) ;
V_90 = NULL ;
#else
F_50 ( V_86 , & V_87 ) ;
#endif
return 0 ;
}
int T_1 F_54 ( void )
{
V_91 = F_55 ( L_17 , NULL ) ;
if ( F_56 ( V_91 ) )
return - 1 ;
V_92 =
F_57 ( L_18 ,
V_93 | V_94 , V_91 , NULL ,
& V_95 ) ;
if ( F_56 ( V_92 ) )
goto V_67;
V_96 =
F_57 ( L_19 ,
V_93 | V_94 , V_91 , NULL ,
& V_97 ) ;
if ( F_56 ( V_96 ) )
goto V_67;
V_98 =
F_57 ( L_20 ,
V_93 | V_94 , V_91 , NULL ,
& V_99 ) ;
if ( F_56 ( V_98 ) )
goto V_67;
V_13 =
F_57 ( L_21 , V_93 | V_94 ,
V_91 , NULL , & V_100 ) ;
if ( F_56 ( V_13 ) )
goto V_67;
V_90 = F_57 ( L_22 , V_101 ,
V_91 , NULL ,
& V_102 ) ;
if ( F_56 ( V_90 ) )
goto V_67;
return 0 ;
V_67:
F_53 ( V_13 ) ;
F_53 ( V_98 ) ;
F_53 ( V_96 ) ;
F_53 ( V_92 ) ;
F_53 ( V_91 ) ;
F_53 ( V_90 ) ;
return - 1 ;
}
