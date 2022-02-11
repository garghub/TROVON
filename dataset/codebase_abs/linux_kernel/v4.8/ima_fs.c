static T_1 F_1 ( char T_2 * V_1 , T_3 V_2 ,
T_4 * V_3 , T_5 * V_4 )
{
char V_5 [ V_6 ] ;
T_1 V_7 ;
V_7 = F_2 ( V_5 , V_6 , L_1 , F_3 ( V_4 ) ) ;
return F_4 ( V_1 , V_2 , V_3 , V_5 , V_7 ) ;
}
static T_1 F_5 ( struct V_8 * V_9 ,
char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , & V_10 . V_11 ) ;
}
static T_1 F_6 ( struct V_8 * V_9 ,
char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , & V_10 . V_7 ) ;
}
static void * F_7 ( struct V_12 * V_13 , T_4 * V_14 )
{
T_4 V_15 = * V_14 ;
struct V_16 * V_17 ;
F_8 () ;
F_9 (qe, &ima_measurements, later) {
if ( ! V_15 -- ) {
F_10 () ;
return V_17 ;
}
}
F_10 () ;
return NULL ;
}
static void * F_11 ( struct V_12 * V_13 , void * V_18 , T_4 * V_14 )
{
struct V_16 * V_17 = V_18 ;
F_8 () ;
V_17 = F_12 ( V_17 -> V_19 . V_20 , struct V_16 , V_19 ) ;
F_10 () ;
( * V_14 ) ++ ;
return ( & V_17 -> V_19 == & V_21 ) ? NULL : V_17 ;
}
static void F_13 ( struct V_12 * V_13 , void * V_18 )
{
}
void F_14 ( struct V_12 * V_13 , void * V_22 , int V_23 )
{
while ( V_23 -- )
F_15 ( V_13 , * ( char * ) V_22 ++ ) ;
}
static int F_16 ( struct V_12 * V_13 , void * V_18 )
{
struct V_16 * V_17 = V_18 ;
struct V_24 * V_25 ;
char * V_26 ;
int V_27 ;
bool V_28 = false ;
int V_29 ;
V_25 = V_17 -> V_30 ;
if ( V_25 == NULL )
return - 1 ;
V_26 = ( V_25 -> V_31 -> V_32 [ 0 ] != '\0' ) ?
V_25 -> V_31 -> V_32 : V_25 -> V_31 -> V_33 ;
F_14 ( V_13 , & V_25 -> V_34 , sizeof( V_25 -> V_34 ) ) ;
F_14 ( V_13 , V_25 -> V_35 , V_36 ) ;
V_27 = strlen ( V_26 ) ;
F_14 ( V_13 , & V_27 , sizeof( V_27 ) ) ;
F_14 ( V_13 , V_26 , V_27 ) ;
if ( strcmp ( V_26 , V_37 ) == 0 )
V_28 = true ;
if ( ! V_28 )
F_14 ( V_13 , & V_25 -> V_38 ,
sizeof( V_25 -> V_38 ) ) ;
for ( V_29 = 0 ; V_29 < V_25 -> V_31 -> V_39 ; V_29 ++ ) {
enum V_40 V_41 = V_42 ;
struct V_43 * V_44 = V_25 -> V_31 -> V_45 [ V_29 ] ;
if ( V_28 && strcmp ( V_44 -> V_46 , L_2 ) == 0 )
V_41 = V_47 ;
if ( V_28 && strcmp ( V_44 -> V_46 , L_3 ) == 0 )
V_41 = V_48 ;
V_44 -> V_49 ( V_13 , V_41 , & V_25 -> V_50 [ V_29 ] ) ;
}
return 0 ;
}
static int F_17 ( struct V_51 * V_51 , struct V_8 * V_8 )
{
return F_18 ( V_8 , & V_52 ) ;
}
void F_19 ( struct V_12 * V_13 , T_6 * V_35 , T_7 V_53 )
{
T_7 V_29 ;
for ( V_29 = 0 ; V_29 < V_53 ; V_29 ++ )
F_20 ( V_13 , L_4 , * ( V_35 + V_29 ) ) ;
}
static int F_21 ( struct V_12 * V_13 , void * V_18 )
{
struct V_16 * V_17 = V_18 ;
struct V_24 * V_25 ;
char * V_26 ;
int V_29 ;
V_25 = V_17 -> V_30 ;
if ( V_25 == NULL )
return - 1 ;
V_26 = ( V_25 -> V_31 -> V_32 [ 0 ] != '\0' ) ?
V_25 -> V_31 -> V_32 : V_25 -> V_31 -> V_33 ;
F_20 ( V_13 , L_5 , V_25 -> V_34 ) ;
F_19 ( V_13 , V_25 -> V_35 , V_36 ) ;
F_20 ( V_13 , L_6 , V_26 ) ;
for ( V_29 = 0 ; V_29 < V_25 -> V_31 -> V_39 ; V_29 ++ ) {
F_22 ( V_13 , L_7 ) ;
if ( V_25 -> V_50 [ V_29 ] . V_7 == 0 )
continue;
V_25 -> V_31 -> V_45 [ V_29 ] -> V_49 ( V_13 , V_54 ,
& V_25 -> V_50 [ V_29 ] ) ;
}
F_22 ( V_13 , L_8 ) ;
return 0 ;
}
static int F_23 ( struct V_51 * V_51 , struct V_8 * V_8 )
{
return F_18 ( V_8 , & V_55 ) ;
}
static T_1 F_24 ( char * V_56 )
{
void * V_22 ;
char * V_57 ;
T_4 V_53 ;
int V_58 , V_59 = strlen ( V_56 ) ;
char * V_60 ;
V_57 = V_56 ;
F_25 ( & V_57 , L_8 ) ;
V_58 = F_26 ( V_56 , & V_22 , & V_53 , 0 , V_61 ) ;
if ( V_58 < 0 ) {
F_27 ( L_9 , V_56 , V_58 ) ;
return V_58 ;
}
V_57 = V_22 ;
while ( V_53 > 0 && ( V_60 = F_25 ( & V_57 , L_8 ) ) ) {
F_28 ( L_10 , V_60 ) ;
V_58 = F_29 ( V_60 ) ;
if ( V_58 < 0 )
break;
V_53 -= V_58 ;
}
F_30 ( V_22 ) ;
if ( V_58 < 0 )
return V_58 ;
else if ( V_53 )
return - V_62 ;
else
return V_59 ;
}
static T_1 F_31 ( struct V_8 * V_8 , const char T_2 * V_1 ,
T_3 V_23 , T_4 * V_3 )
{
char * V_22 ;
T_1 V_63 ;
if ( V_23 >= V_64 )
V_23 = V_64 - 1 ;
V_63 = - V_62 ;
if ( * V_3 != 0 )
goto V_65;
V_63 = - V_66 ;
V_22 = F_32 ( V_23 + 1 , V_67 ) ;
if ( ! V_22 )
goto V_65;
* ( V_22 + V_23 ) = '\0' ;
V_63 = - V_68 ;
if ( F_33 ( V_22 , V_1 , V_23 ) )
goto V_69;
V_63 = F_34 ( & V_70 ) ;
if ( V_63 < 0 )
goto V_69;
if ( V_22 [ 0 ] == '/' ) {
V_63 = F_24 ( V_22 ) ;
} else if ( V_71 & V_72 ) {
F_27 ( L_11 ) ;
F_35 ( V_73 , NULL , NULL ,
L_12 , L_13 ,
1 , 0 ) ;
if ( V_71 & V_74 )
V_63 = - V_75 ;
} else {
V_63 = F_29 ( V_22 ) ;
}
F_36 ( & V_70 ) ;
V_69:
F_37 ( V_22 ) ;
V_65:
if ( V_63 < 0 )
V_76 = 0 ;
return V_63 ;
}
static int F_38 ( struct V_51 * V_51 , struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_77 & V_78 ) ) {
#ifndef F_39
return - V_75 ;
#else
if ( ( V_9 -> V_77 & V_79 ) != V_80 )
return - V_75 ;
if ( ! F_40 ( V_81 ) )
return - V_82 ;
return F_18 ( V_9 , & V_83 ) ;
#endif
}
if ( F_41 ( V_84 , & V_85 ) )
return - V_86 ;
return 0 ;
}
static int F_42 ( struct V_51 * V_51 , struct V_8 * V_8 )
{
const char * V_87 = V_76 ? L_14 : L_15 ;
if ( ( V_8 -> V_77 & V_79 ) == V_80 )
return 0 ;
if ( V_76 && F_43 () < 0 ) {
V_87 = L_15 ;
V_76 = 0 ;
}
F_44 ( L_16 , V_87 ) ;
F_35 ( V_73 , NULL , NULL ,
L_12 , V_87 , ! V_76 , 0 ) ;
if ( ! V_76 ) {
F_45 () ;
V_76 = 1 ;
F_46 ( V_84 , & V_85 ) ;
return 0 ;
}
F_47 () ;
#ifndef F_48
F_49 ( V_88 ) ;
V_88 = NULL ;
#else
F_46 ( V_84 , & V_85 ) ;
#endif
return 0 ;
}
int T_8 F_50 ( void )
{
V_89 = F_51 ( L_17 , NULL ) ;
if ( F_52 ( V_89 ) )
return - 1 ;
V_90 =
F_53 ( L_18 ,
V_91 | V_92 , V_89 , NULL ,
& V_93 ) ;
if ( F_52 ( V_90 ) )
goto V_65;
V_94 =
F_53 ( L_19 ,
V_91 | V_92 , V_89 , NULL ,
& V_95 ) ;
if ( F_52 ( V_94 ) )
goto V_65;
V_96 =
F_53 ( L_20 ,
V_91 | V_92 , V_89 , NULL ,
& V_97 ) ;
if ( F_52 ( V_96 ) )
goto V_65;
V_11 =
F_53 ( L_21 , V_91 | V_92 ,
V_89 , NULL , & V_98 ) ;
if ( F_52 ( V_11 ) )
goto V_65;
V_88 = F_53 ( L_22 , V_99 ,
V_89 , NULL ,
& V_100 ) ;
if ( F_52 ( V_88 ) )
goto V_65;
return 0 ;
V_65:
F_49 ( V_11 ) ;
F_49 ( V_96 ) ;
F_49 ( V_94 ) ;
F_49 ( V_90 ) ;
F_49 ( V_89 ) ;
F_49 ( V_88 ) ;
return - 1 ;
}
