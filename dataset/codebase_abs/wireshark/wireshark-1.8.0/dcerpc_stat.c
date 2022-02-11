static T_1
F_1 ( T_2 * V_1 , T_2 * V_2 )
{
if( ( V_1 -> V_3 != V_2 -> V_3 )
|| ( V_1 -> V_4 != V_2 -> V_4 )
|| ( V_1 -> V_5 != V_2 -> V_5 )
|| ( V_1 -> V_6 [ 0 ] != V_2 -> V_6 [ 0 ] )
|| ( V_1 -> V_6 [ 1 ] != V_2 -> V_6 [ 1 ] )
|| ( V_1 -> V_6 [ 2 ] != V_2 -> V_6 [ 2 ] )
|| ( V_1 -> V_6 [ 3 ] != V_2 -> V_6 [ 3 ] )
|| ( V_1 -> V_6 [ 4 ] != V_2 -> V_6 [ 4 ] )
|| ( V_1 -> V_6 [ 5 ] != V_2 -> V_6 [ 5 ] )
|| ( V_1 -> V_6 [ 6 ] != V_2 -> V_6 [ 6 ] )
|| ( V_1 -> V_6 [ 7 ] != V_2 -> V_6 [ 7 ] ) ) {
return FALSE ;
}
return TRUE ;
}
static char *
F_2 ( T_3 * V_7 )
{
char * V_8 ;
char * V_9 ;
V_9 = F_3 ( & V_10 ) ;
V_8 = F_4 ( L_1 , V_7 -> V_11 , V_7 -> V_12 , V_9 ) ;
F_5 ( V_9 ) ;
return V_8 ;
}
static void
F_6 ( T_3 * V_7 )
{
char * V_8 ;
V_8 = F_2 ( V_7 ) ;
F_7 ( F_8 ( V_7 -> V_13 ) , V_8 ) ;
F_5 ( V_8 ) ;
}
static void
F_9 ( void * V_14 )
{
T_3 * V_7 = V_14 ;
F_10 ( & V_7 -> V_15 ) ;
F_6 ( V_7 ) ;
}
static T_1
F_11 ( void * V_14 , T_4 * V_16 , T_5 * T_6 V_17 , const void * V_18 )
{
T_3 * V_7 = V_14 ;
const T_7 * V_19 = V_18 ;
if( ! V_19 -> V_20 ) {
return FALSE ;
}
if( ! V_19 -> V_20 -> V_21 ) {
return FALSE ;
}
if( V_19 -> V_20 -> V_22 >= V_7 -> V_23 ) {
return FALSE ;
}
if( V_19 -> V_24 != V_25 ) {
return FALSE ;
}
if( ( ! F_1 ( ( & V_19 -> V_20 -> V_26 ) , ( & V_7 -> V_26 ) ) )
|| ( V_19 -> V_20 -> V_12 != V_7 -> V_12 ) ) {
return FALSE ;
}
F_12 ( & V_7 -> V_15 , V_19 -> V_20 -> V_22 , & V_19 -> V_20 -> V_27 , V_16 ) ;
return TRUE ;
}
static void
F_13 ( void * V_14 )
{
T_3 * V_7 = V_14 ;
F_14 ( & V_7 -> V_15 ) ;
}
static void
F_15 ( T_8 * V_13 V_17 , T_9 V_28 )
{
T_3 * V_7 = ( T_3 * ) V_28 ;
F_16 () ;
F_17 ( V_7 ) ;
F_18 () ;
F_19 ( & V_7 -> V_15 ) ;
F_5 ( V_7 ) ;
}
static void
F_20 ( const char * V_29 , void * T_10 V_17 )
{
T_3 * V_7 ;
T_11 V_30 , V_31 ;
char * V_32 ;
char * V_33 ;
T_12 * V_34 ;
T_12 * V_35 ;
T_12 * V_36 ;
T_12 * V_37 ;
T_12 * V_38 ;
T_13 * V_39 ;
T_2 V_26 ;
T_14 V_40 , V_41 , V_42 , V_43 , V_44 , V_45 , V_46 , V_47 , V_48 , V_49 , V_50 ;
int V_51 , V_52 ;
T_15 V_12 ;
int V_53 = 0 ;
const char * V_54 = NULL ;
T_16 * V_55 ;
int V_56 ;
if( sscanf (
V_29 ,
L_2 ,
& V_40 , & V_41 , & V_42 , & V_43 , & V_44 , & V_45 , & V_46 , & V_47 , & V_48 , & V_49 , & V_50 , & V_51 , & V_52 , & V_53 )
== 13 ) {
V_26 . V_3 = V_40 ;
V_26 . V_4 = V_41 ;
V_26 . V_5 = V_42 ;
V_26 . V_6 [ 0 ] = V_43 ;
V_26 . V_6 [ 1 ] = V_44 ;
V_26 . V_6 [ 2 ] = V_45 ;
V_26 . V_6 [ 3 ] = V_46 ;
V_26 . V_6 [ 4 ] = V_47 ;
V_26 . V_6 [ 5 ] = V_48 ;
V_26 . V_6 [ 6 ] = V_49 ;
V_26 . V_6 [ 7 ] = V_50 ;
if( V_53 ) {
V_54 = V_29 + V_53 ;
} else {
V_54 = NULL ;
}
} else {
fprintf ( V_57 , L_3 ) ;
exit ( 1 ) ;
}
if ( ( V_51 < 0 ) || ( V_51 > 65535 ) ) {
fprintf ( V_57 , L_4 , V_51 ) ;
exit ( 1 ) ;
}
if ( ( V_52 < 0 ) || ( V_52 > 65535 ) ) {
fprintf ( V_57 , L_5 , V_52 ) ;
exit ( 1 ) ;
}
V_12 = V_51 ;
V_7 = F_21 ( sizeof( T_3 ) ) ;
V_7 -> V_11 = F_22 ( & V_26 , V_12 ) ;
if( ! V_7 -> V_11 ) {
F_5 ( V_7 ) ;
fprintf ( V_57 ,
L_6 ,
V_26 . V_3 , V_26 . V_4 , V_26 . V_5 , V_26 . V_6 [ 0 ] , V_26 . V_6 [ 1 ] , V_26 . V_6 [ 2 ] , V_26 . V_6 [ 3 ] , V_26 . V_6 [ 4 ] , V_26 . V_6 [ 5 ] , V_26 . V_6 [ 6 ] , V_26 . V_6 [ 7 ] , V_12 ) ;
exit ( 1 ) ;
}
V_56 = F_23 ( & V_26 , V_12 ) ;
V_39 = F_24 ( & V_26 , V_12 ) ;
V_7 -> V_26 = V_26 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_13 = F_25 ( L_7 ) ;
F_26 ( F_8 ( V_7 -> V_13 ) , TRUE ) ;
F_6 ( V_7 ) ;
F_27 ( F_8 ( V_7 -> V_13 ) , 550 , 400 ) ;
V_34 = F_28 ( V_58 , 3 , FALSE ) ;
F_29 ( F_30 ( V_7 -> V_13 ) , V_34 ) ;
F_31 ( F_30 ( V_34 ) , 12 ) ;
V_32 = F_2 ( V_7 ) ;
V_35 = F_32 ( V_32 ) ;
F_5 ( V_32 ) ;
F_33 ( F_34 ( V_34 ) , V_35 , FALSE , FALSE , 0 ) ;
V_33 = F_4 ( L_8 , V_54 ? V_54 : L_9 ) ;
V_36 = F_32 ( V_33 ) ;
F_5 ( V_33 ) ;
F_35 ( F_36 ( V_36 ) , TRUE ) ;
F_33 ( F_34 ( V_34 ) , V_36 , FALSE , FALSE , 0 ) ;
for( V_30 = 0 , V_31 = 0 ; V_39 [ V_30 ] . V_59 ; V_30 ++ ) {
if( V_39 [ V_30 ] . V_60 > V_31 ) {
V_31 = V_39 [ V_30 ] . V_60 ;
}
}
V_7 -> V_23 = V_31 + 1 ;
F_37 ( V_7 -> V_13 ) ;
if( V_56 != - 1 ) {
F_38 ( & V_7 -> V_15 , V_31 + 1 , V_34 , F_39 ( V_56 ) -> V_61 ) ;
} else {
F_38 ( & V_7 -> V_15 , V_31 + 1 , V_34 , NULL ) ;
}
for( V_30 = 0 ; V_30 < ( V_31 + 1 ) ; V_30 ++ ) {
int V_62 ;
const char * V_63 ;
V_63 = L_10 ;
for( V_62 = 0 ; V_39 [ V_62 ] . V_59 ; V_62 ++ ) {
if ( V_39 [ V_62 ] . V_60 == V_30 ) {
V_63 = V_39 [ V_62 ] . V_59 ;
}
}
F_40 ( & V_7 -> V_15 , V_30 , V_63 ) ;
}
V_55 = F_41 ( L_11 , V_7 , V_54 , 0 , F_9 , F_11 , F_13 ) ;
if( V_55 ) {
F_42 ( V_64 , V_65 , L_12 , V_55 -> V_66 ) ;
F_43 ( V_55 , TRUE ) ;
F_19 ( & V_7 -> V_15 ) ;
F_5 ( V_7 ) ;
return;
}
V_37 = F_44 ( V_67 , NULL ) ;
F_45 ( F_34 ( V_34 ) , V_37 , FALSE , FALSE , 0 ) ;
V_38 = F_46 ( F_47 ( V_37 ) , V_67 ) ;
F_48 ( V_7 -> V_13 , V_38 , V_68 ) ;
F_49 ( V_7 -> V_13 , L_13 , F_50 ( V_69 ) , NULL ) ;
F_49 ( V_7 -> V_13 , L_14 , F_50 ( F_15 ) , V_7 ) ;
F_37 ( V_7 -> V_13 ) ;
F_51 ( V_7 -> V_13 ) ;
F_52 ( & V_10 ) ;
F_53 ( F_54 ( V_7 -> V_13 ) ) ;
}
static void
F_55 ( T_12 * T_17 V_17 , T_9 V_28 V_17 )
{
T_16 * V_66 ;
const char * V_54 ;
if ( V_70 == NULL ) {
F_42 ( V_64 , V_65 , L_15 ) ;
return;
}
V_66 = F_56 ( L_16 ) ;
F_57 ( V_66 ,
L_17 ,
V_70 -> V_3 , V_70 -> V_4 ,
V_70 -> V_5 ,
V_70 -> V_6 [ 0 ] , V_70 -> V_6 [ 1 ] ,
V_70 -> V_6 [ 2 ] , V_70 -> V_6 [ 3 ] ,
V_70 -> V_6 [ 4 ] , V_70 -> V_6 [ 5 ] ,
V_70 -> V_6 [ 6 ] , V_70 -> V_6 [ 7 ] ,
V_71 , 0 ) ;
V_54 = F_58 ( F_59 ( V_72 ) ) ;
if( V_54 [ 0 ] != 0 ) {
F_57 ( V_66 , L_18 , V_54 ) ;
}
F_20 ( V_66 -> V_66 , NULL ) ;
F_43 ( V_66 , TRUE ) ;
}
static void
F_60 ( T_12 * V_73 , T_9 T_18 V_17 )
{
T_19 * V_74 ;
if ( ! F_61 ( F_62 ( V_73 ) , ( T_9 ) & V_74 ) ) {
F_63 () ;
}
V_71 = V_74 -> V_12 ;
}
static void
F_64 ( T_9 * V_75 , T_9 * T_20 V_17 , T_9 T_18 )
{
T_19 * V_74 = ( T_19 * ) V_75 ;
T_12 * V_73 = T_18 ;
char V_76 [ 5 ] ;
if( ! F_1 ( & ( V_74 -> V_26 ) , V_70 ) ) {
return;
}
F_65 ( V_76 , sizeof( V_76 ) , L_19 , V_74 -> V_12 ) ;
F_66 ( F_62 ( V_73 ) , V_76 , V_74 ) ;
}
static void
F_67 ( T_12 * V_77 , T_9 T_18 )
{
T_19 * V_74 ;
T_12 * V_73 ;
V_73 = T_18 ;
if ( ! F_61 ( F_62 ( V_77 ) , ( T_9 ) & V_74 ) ) {
F_63 () ;
}
F_68 ( V_73 , F_50 ( F_60 ) , NULL ) ;
F_69 ( F_62 ( V_73 ) ) ;
F_70 ( ( V_74 != NULL ) && L_20 ) ;
V_70 = & ( V_74 -> V_26 ) ;
F_68 ( V_73 , F_50 ( F_60 ) , NULL ) ;
F_69 ( F_62 ( V_73 ) ) ;
F_71 ( V_78 , ( V_79 ) F_64 , V_73 ) ;
F_49 ( V_73 , L_21 , F_50 ( F_60 ) , NULL ) ;
F_72 ( F_62 ( V_73 ) , 0 ) ;
}
static T_21
F_73 ( T_19 * V_74 , T_22 * V_80 , T_12 * V_77 , int V_81 )
{
static T_21 V_82 ;
char V_66 [ 64 ] ;
switch( V_81 % 15 ) {
case 0 :
F_65 ( V_66 , sizeof( V_66 ) , L_22 , V_80 -> V_59 ) ;
V_82 = F_74 (
F_62 ( V_77 ) , NULL , V_66 , NULL , FALSE ) ;
break;
default:
break;
}
return F_74 (
F_62 ( V_77 ) , & V_82 , V_80 -> V_59 , V_74 , TRUE ) ;
}
static void
F_75 ( T_9 * V_75 , T_9 * T_20 , T_9 * T_18 V_17 )
{
T_19 * V_74 = ( T_19 * ) V_75 ;
T_22 * V_80 = ( T_22 * ) T_20 ;
if( ( V_83 == NULL ) && ( V_84 == NULL ) ) {
V_84 = V_74 ;
V_85 = V_80 ;
return;
}
if( V_83 == NULL ) {
if( strcmp ( V_85 -> V_59 , V_80 -> V_59 ) > 0 ) {
V_84 = V_74 ;
V_85 = V_80 ;
return;
}
return;
}
if( strcmp ( V_86 -> V_59 , V_80 -> V_59 ) >= 0 ) {
return;
}
if( V_84 == NULL ) {
V_84 = V_74 ;
V_85 = V_80 ;
return;
}
if( strcmp ( V_85 -> V_59 , V_80 -> V_59 ) > 0 ) {
V_84 = V_74 ;
V_85 = V_80 ;
return;
}
return;
}
static void
F_76 ( T_12 * T_23 V_17 , T_9 T_18 V_17 )
{
V_87 = NULL ;
}
void F_77 ( T_24 * T_25 V_17 , T_9 T_18 V_17 )
{
T_12 * V_88 ;
T_12 * V_89 , * V_90 , * V_77 ;
T_12 * V_91 , * V_73 ;
T_12 * V_92 , * V_93 ;
T_12 * V_37 , * V_94 , * V_95 ;
T_26 * V_96 ;
#if 0
GtkTreeIter program_first_item_iter;
#endif
const char * V_54 ;
int V_81 = 0 ;
static T_27 args = {
L_23 ,
FALSE ,
FALSE ,
FALSE
} ;
if( V_87 ) {
F_78 ( V_87 ) ;
return;
}
V_87 = F_25 ( L_24 ) ;
F_27 ( F_8 ( V_87 ) , 400 , - 1 ) ;
V_88 = F_28 ( V_58 , 10 , FALSE ) ;
F_31 ( F_30 ( V_88 ) , 10 ) ;
F_29 ( F_30 ( V_87 ) , V_88 ) ;
F_79 ( V_88 ) ;
V_89 = F_28 ( V_97 , 3 , FALSE ) ;
F_31 ( F_30 ( V_89 ) , 10 ) ;
V_90 = F_32 ( L_25 ) ;
F_33 ( F_34 ( V_89 ) , V_90 , FALSE , FALSE , 0 ) ;
F_79 ( V_90 ) ;
V_70 = NULL ;
V_77 = F_80 ( & V_96 ) ;
{
#if F_81 ( 3 , 0 , 0 )
T_28 * V_98 ;
T_29 * V_99 ;
V_98 = F_82 ( V_77 ) ;
F_83 ( V_98 , V_100 ,
L_26 , & V_99 ,
NULL ) ;
F_84 ( V_96 ,
L_27 , & V_99 ,
L_28 , TRUE ,
NULL ) ;
#else
T_30 * V_101 ;
V_101 = F_85 ( V_77 ) ;
F_84 ( V_96 ,
L_29 , & ( V_101 -> V_102 [ V_100 ] ) ,
L_28 , TRUE ,
NULL ) ;
#endif
}
V_83 = NULL ;
V_86 = NULL ;
do {
V_84 = NULL ;
V_85 = NULL ;
F_71 ( V_78 , ( V_79 ) F_75 , NULL ) ;
if( V_84 ) {
#if 0
GtkTreeIter tmp_iter;
tmp_iter = dcerpcstat_add_program_to_menu(new_uuid_key, new_uuid_value,
prog_combo_box, program_item_index);
if (program_item_index == 0)
program_first_item_iter = tmp_iter;
#else
F_73 ( V_84 , V_85 ,
V_77 , V_81 ) ;
#endif
V_81 += 1 ;
}
V_83 = V_84 ;
V_86 = V_85 ;
} while( V_84 != NULL );
F_33 ( F_34 ( V_89 ) , V_77 , TRUE , TRUE , 0 ) ;
F_79 ( V_77 ) ;
F_31 ( F_30 ( V_89 ) , 10 ) ;
V_91 = F_32 ( L_30 ) ;
F_33 ( F_34 ( V_89 ) , V_91 , FALSE , FALSE , 0 ) ;
F_79 ( V_91 ) ;
V_73 = F_86 () ;
F_33 ( F_34 ( V_89 ) , V_73 , TRUE , TRUE , 0 ) ;
F_79 ( V_73 ) ;
F_49 ( V_77 , L_21 , F_50 ( F_67 ) , V_73 ) ;
#if 0
ws_combo_box_set_active_iter(GTK_COMBO_BOX(prog_combo_box), &program_first_item_iter);
#endif
F_33 ( F_34 ( V_88 ) , V_89 , TRUE , TRUE , 0 ) ;
F_79 ( V_89 ) ;
V_92 = F_28 ( V_97 , 3 , FALSE ) ;
V_93 = F_87 ( V_103 ) ;
F_49 ( V_93 , L_31 , F_50 ( V_104 ) , & args ) ;
F_33 ( F_34 ( V_92 ) , V_93 , FALSE , FALSE , 0 ) ;
F_79 ( V_93 ) ;
V_72 = F_88 () ;
F_49 ( V_72 , L_21 , F_50 ( V_105 ) , NULL ) ;
F_89 ( F_47 ( V_92 ) , V_106 , NULL ) ;
F_49 ( V_72 , L_32 , F_50 ( V_107 ) , NULL ) ;
F_49 ( V_87 , L_32 , F_50 ( V_108 ) , NULL ) ;
F_33 ( F_34 ( V_92 ) , V_72 , TRUE , TRUE , 0 ) ;
V_54 = F_58 ( F_59 ( V_109 ) ) ;
if( V_54 ) {
F_90 ( F_59 ( V_72 ) , V_54 ) ;
} else {
F_91 ( V_72 ) ;
}
F_79 ( V_72 ) ;
F_33 ( F_34 ( V_88 ) , V_92 , TRUE , TRUE , 0 ) ;
F_79 ( V_92 ) ;
F_89 ( F_47 ( V_93 ) , V_110 , V_72 ) ;
V_37 = F_44 ( V_111 , V_112 , NULL ) ;
F_33 ( F_34 ( V_88 ) , V_37 , FALSE , FALSE , 0 ) ;
F_79 ( V_37 ) ;
V_94 = F_46 ( F_47 ( V_37 ) , V_111 ) ;
F_92 ( V_94 , L_31 ,
F_50 ( F_55 ) , NULL ) ;
V_95 = F_46 ( F_47 ( V_37 ) , V_112 ) ;
F_48 ( V_87 , V_95 , V_68 ) ;
F_49 ( V_87 , L_13 , F_50 ( V_69 ) , NULL ) ;
F_49 ( V_87 , L_14 , F_50 ( F_76 ) , NULL ) ;
F_93 ( V_72 , V_94 ) ;
F_94 ( V_94 ) ;
F_95 ( V_72 ) ;
F_37 ( V_87 ) ;
F_51 ( V_87 ) ;
}
void
F_96 ( void )
{
F_97 ( L_33 , F_20 , NULL ) ;
}
