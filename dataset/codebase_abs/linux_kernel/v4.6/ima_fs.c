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
T_6 V_28 = V_29 ;
bool V_30 = false ;
int V_31 ;
V_25 = V_17 -> V_32 ;
if ( V_25 == NULL )
return - 1 ;
V_26 = ( V_25 -> V_33 -> V_34 [ 0 ] != '\0' ) ?
V_25 -> V_33 -> V_34 : V_25 -> V_33 -> V_35 ;
F_14 ( V_13 , & V_28 , sizeof( V_28 ) ) ;
F_14 ( V_13 , V_25 -> V_36 , V_37 ) ;
V_27 = strlen ( V_26 ) ;
F_14 ( V_13 , & V_27 , sizeof( V_27 ) ) ;
F_14 ( V_13 , V_26 , V_27 ) ;
if ( strcmp ( V_26 , V_38 ) == 0 )
V_30 = true ;
if ( ! V_30 )
F_14 ( V_13 , & V_25 -> V_39 ,
sizeof( V_25 -> V_39 ) ) ;
for ( V_31 = 0 ; V_31 < V_25 -> V_33 -> V_40 ; V_31 ++ ) {
enum V_41 V_42 = V_43 ;
struct V_44 * V_45 = V_25 -> V_33 -> V_46 [ V_31 ] ;
if ( V_30 && strcmp ( V_45 -> V_47 , L_2 ) == 0 )
V_42 = V_48 ;
if ( V_30 && strcmp ( V_45 -> V_47 , L_3 ) == 0 )
V_42 = V_49 ;
V_45 -> V_50 ( V_13 , V_42 , & V_25 -> V_51 [ V_31 ] ) ;
}
return 0 ;
}
static int F_17 ( struct V_52 * V_52 , struct V_8 * V_8 )
{
return F_18 ( V_8 , & V_53 ) ;
}
void F_19 ( struct V_12 * V_13 , T_7 * V_36 , T_6 V_54 )
{
T_6 V_31 ;
for ( V_31 = 0 ; V_31 < V_54 ; V_31 ++ )
F_20 ( V_13 , L_4 , * ( V_36 + V_31 ) ) ;
}
static int F_21 ( struct V_12 * V_13 , void * V_18 )
{
struct V_16 * V_17 = V_18 ;
struct V_24 * V_25 ;
char * V_26 ;
int V_31 ;
V_25 = V_17 -> V_32 ;
if ( V_25 == NULL )
return - 1 ;
V_26 = ( V_25 -> V_33 -> V_34 [ 0 ] != '\0' ) ?
V_25 -> V_33 -> V_34 : V_25 -> V_33 -> V_35 ;
F_20 ( V_13 , L_5 , V_29 ) ;
F_19 ( V_13 , V_25 -> V_36 , V_37 ) ;
F_20 ( V_13 , L_6 , V_26 ) ;
for ( V_31 = 0 ; V_31 < V_25 -> V_33 -> V_40 ; V_31 ++ ) {
F_22 ( V_13 , L_7 ) ;
if ( V_25 -> V_51 [ V_31 ] . V_7 == 0 )
continue;
V_25 -> V_33 -> V_46 [ V_31 ] -> V_50 ( V_13 , V_55 ,
& V_25 -> V_51 [ V_31 ] ) ;
}
F_22 ( V_13 , L_8 ) ;
return 0 ;
}
static int F_23 ( struct V_52 * V_52 , struct V_8 * V_8 )
{
return F_18 ( V_8 , & V_56 ) ;
}
static T_1 F_24 ( char * V_57 )
{
void * V_22 ;
char * V_58 ;
T_4 V_54 ;
int V_59 , V_60 = strlen ( V_57 ) ;
char * V_61 ;
V_58 = V_57 ;
F_25 ( & V_58 , L_8 ) ;
V_59 = F_26 ( V_57 , & V_22 , & V_54 , 0 , V_62 ) ;
if ( V_59 < 0 ) {
F_27 ( L_9 , V_57 , V_59 ) ;
return V_59 ;
}
V_58 = V_22 ;
while ( V_54 > 0 && ( V_61 = F_25 ( & V_58 , L_8 ) ) ) {
F_28 ( L_10 , V_61 ) ;
V_59 = F_29 ( V_61 ) ;
if ( V_59 < 0 )
break;
V_54 -= V_59 ;
}
F_30 ( V_22 ) ;
if ( V_59 < 0 )
return V_59 ;
else if ( V_54 )
return - V_63 ;
else
return V_60 ;
}
static T_1 F_31 ( struct V_8 * V_8 , const char T_2 * V_1 ,
T_3 V_23 , T_4 * V_3 )
{
char * V_22 ;
T_1 V_64 ;
if ( V_23 >= V_65 )
V_23 = V_65 - 1 ;
V_64 = - V_63 ;
if ( * V_3 != 0 )
goto V_66;
V_64 = - V_67 ;
V_22 = F_32 ( V_23 + 1 , V_68 ) ;
if ( ! V_22 )
goto V_66;
* ( V_22 + V_23 ) = '\0' ;
V_64 = - V_69 ;
if ( F_33 ( V_22 , V_1 , V_23 ) )
goto V_70;
V_64 = F_34 ( & V_71 ) ;
if ( V_64 < 0 )
goto V_70;
if ( V_22 [ 0 ] == '/' ) {
V_64 = F_24 ( V_22 ) ;
} else if ( V_72 & V_73 ) {
F_27 ( L_11 ) ;
F_35 ( V_74 , NULL , NULL ,
L_12 , L_13 ,
1 , 0 ) ;
if ( V_72 & V_75 )
V_64 = - V_76 ;
} else {
V_64 = F_29 ( V_22 ) ;
}
F_36 ( & V_71 ) ;
V_70:
F_37 ( V_22 ) ;
V_66:
if ( V_64 < 0 )
V_77 = 0 ;
return V_64 ;
}
static int F_38 ( struct V_52 * V_52 , struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_78 & V_79 ) ) {
#ifndef F_39
return - V_76 ;
#else
if ( ( V_9 -> V_78 & V_80 ) != V_81 )
return - V_76 ;
if ( ! F_40 ( V_82 ) )
return - V_83 ;
return F_18 ( V_9 , & V_84 ) ;
#endif
}
if ( F_41 ( V_85 , & V_86 ) )
return - V_87 ;
return 0 ;
}
static int F_42 ( struct V_52 * V_52 , struct V_8 * V_8 )
{
const char * V_88 = V_77 ? L_14 : L_15 ;
if ( ( V_8 -> V_78 & V_80 ) == V_81 )
return 0 ;
if ( V_77 && F_43 () < 0 ) {
V_88 = L_15 ;
V_77 = 0 ;
}
F_44 ( L_16 , V_88 ) ;
F_35 ( V_74 , NULL , NULL ,
L_12 , V_88 , ! V_77 , 0 ) ;
if ( ! V_77 ) {
F_45 () ;
V_77 = 1 ;
F_46 ( V_85 , & V_86 ) ;
return 0 ;
}
F_47 () ;
#ifndef F_48
F_49 ( V_89 ) ;
V_89 = NULL ;
#else
F_46 ( V_85 , & V_86 ) ;
#endif
return 0 ;
}
int T_8 F_50 ( void )
{
V_90 = F_51 ( L_17 , NULL ) ;
if ( F_52 ( V_90 ) )
return - 1 ;
V_91 =
F_53 ( L_18 ,
V_92 | V_93 , V_90 , NULL ,
& V_94 ) ;
if ( F_52 ( V_91 ) )
goto V_66;
V_95 =
F_53 ( L_19 ,
V_92 | V_93 , V_90 , NULL ,
& V_96 ) ;
if ( F_52 ( V_95 ) )
goto V_66;
V_97 =
F_53 ( L_20 ,
V_92 | V_93 , V_90 , NULL ,
& V_98 ) ;
if ( F_52 ( V_97 ) )
goto V_66;
V_11 =
F_53 ( L_21 , V_92 | V_93 ,
V_90 , NULL , & V_99 ) ;
if ( F_52 ( V_11 ) )
goto V_66;
V_89 = F_53 ( L_22 , V_100 ,
V_90 , NULL ,
& V_101 ) ;
if ( F_52 ( V_89 ) )
goto V_66;
return 0 ;
V_66:
F_49 ( V_11 ) ;
F_49 ( V_97 ) ;
F_49 ( V_95 ) ;
F_49 ( V_91 ) ;
F_49 ( V_90 ) ;
F_49 ( V_89 ) ;
return - 1 ;
}
