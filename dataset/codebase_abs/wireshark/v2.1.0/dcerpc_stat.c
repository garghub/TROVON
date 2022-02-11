static char *
F_1 ( T_1 * V_1 )
{
char * V_2 ;
char * V_3 ;
V_3 = F_2 ( & V_4 ) ;
V_2 = F_3 ( L_1 , V_1 -> V_5 , V_1 -> V_6 , V_3 ) ;
F_4 ( V_3 ) ;
return V_2 ;
}
static void
F_5 ( T_1 * V_1 )
{
char * V_2 ;
V_2 = F_1 ( V_1 ) ;
F_6 ( F_7 ( V_1 -> V_7 . V_8 ) , V_2 ) ;
F_4 ( V_2 ) ;
}
static void
F_8 ( void * V_9 )
{
T_2 * V_10 = ( T_2 * ) V_9 ;
T_1 * V_1 = ( T_1 * ) V_10 -> V_11 ;
F_9 ( V_1 -> V_12 . V_13 , V_14 , & V_1 -> V_7 ) ;
F_5 ( V_1 ) ;
}
static void
F_10 ( void * V_9 )
{
T_3 V_15 = 0 ;
T_4 * V_16 ;
T_2 * V_10 = ( T_2 * ) V_9 ;
T_1 * V_1 = ( T_1 * ) V_10 -> V_11 ;
for ( V_15 = 0 ; V_15 < V_10 -> V_13 -> V_17 ; V_15 ++ )
{
V_16 = F_11 ( V_10 -> V_13 , T_4 * , V_15 ) ;
F_12 ( V_16 , & V_1 -> V_7 ) ;
}
}
static void
F_13 ( T_5 * V_8 V_18 , T_6 V_12 )
{
T_1 * V_1 = ( T_1 * ) V_12 ;
F_14 ( & V_1 -> V_12 ) ;
F_15 ( V_1 -> V_10 , V_1 -> V_12 . V_13 , V_19 , & V_1 -> V_7 ) ;
F_4 ( V_1 ) ;
}
static void
F_16 ( const char * V_20 , void * T_7 V_18 )
{
T_1 * V_1 ;
T_8 V_15 , V_21 ;
char * V_22 ;
char * V_23 ;
T_9 * V_24 ;
T_9 * V_25 ;
T_9 * V_26 ;
T_9 * V_27 ;
T_10 * V_28 ;
T_11 V_29 ;
T_3 V_30 , V_31 , V_32 , V_33 , V_34 , V_35 , V_36 , V_37 , V_38 , V_39 , V_40 ;
int V_41 , V_42 ;
T_12 V_6 ;
int V_43 = 0 ;
const char * V_44 = NULL ;
T_13 * V_45 ;
T_14 * V_46 ;
if( sscanf (
V_20 ,
L_2 ,
& V_30 , & V_31 , & V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 , & V_38 , & V_39 , & V_40 , & V_41 , & V_42 , & V_43 )
== 13 ) {
V_29 . V_47 = V_30 ;
V_29 . V_48 = V_31 ;
V_29 . V_49 = V_32 ;
V_29 . V_50 [ 0 ] = V_33 ;
V_29 . V_50 [ 1 ] = V_34 ;
V_29 . V_50 [ 2 ] = V_35 ;
V_29 . V_50 [ 3 ] = V_36 ;
V_29 . V_50 [ 4 ] = V_37 ;
V_29 . V_50 [ 5 ] = V_38 ;
V_29 . V_50 [ 6 ] = V_39 ;
V_29 . V_50 [ 7 ] = V_40 ;
if( V_43 ) {
V_44 = V_20 + V_43 ;
} else {
V_44 = NULL ;
}
} else {
fprintf ( V_51 , L_3 ) ;
exit ( 1 ) ;
}
if ( ( V_41 < 0 ) || ( V_41 > 65535 ) ) {
fprintf ( V_51 , L_4 , V_41 ) ;
exit ( 1 ) ;
}
if ( ( V_42 < 0 ) || ( V_42 > 65535 ) ) {
fprintf ( V_51 , L_5 , V_42 ) ;
exit ( 1 ) ;
}
V_6 = V_41 ;
V_1 = ( T_1 * ) F_17 ( sizeof( T_1 ) ) ;
V_1 -> V_5 = F_18 ( & V_29 , V_6 ) ;
if( ! V_1 -> V_5 ) {
F_4 ( V_1 ) ;
fprintf ( V_51 ,
L_6 ,
V_29 . V_47 , V_29 . V_48 , V_29 . V_49 , V_29 . V_50 [ 0 ] , V_29 . V_50 [ 1 ] , V_29 . V_50 [ 2 ] , V_29 . V_50 [ 3 ] , V_29 . V_50 [ 4 ] , V_29 . V_50 [ 5 ] , V_29 . V_50 [ 6 ] , V_29 . V_50 [ 7 ] , V_6 ) ;
exit ( 1 ) ;
}
V_28 = F_19 ( & V_29 , V_6 ) ;
V_1 -> V_6 = V_6 ;
V_1 -> V_7 . V_8 = F_20 ( L_7 ) ;
F_21 ( F_7 ( V_1 -> V_7 . V_8 ) , TRUE ) ;
F_5 ( V_1 ) ;
F_22 ( F_7 ( V_1 -> V_7 . V_8 ) , V_52 , V_53 ) ;
V_1 -> V_7 . V_54 = F_23 ( V_55 , 3 , FALSE ) ;
F_24 ( F_25 ( V_1 -> V_7 . V_8 ) , V_1 -> V_7 . V_54 ) ;
F_26 ( F_25 ( V_1 -> V_7 . V_54 ) , 12 ) ;
V_22 = F_1 ( V_1 ) ;
V_24 = F_27 ( V_22 ) ;
F_4 ( V_22 ) ;
F_28 ( F_29 ( V_1 -> V_7 . V_54 ) , V_24 , FALSE , FALSE , 0 ) ;
V_23 = F_3 ( L_8 , V_44 ? V_44 : L_9 ) ;
V_25 = F_27 ( V_23 ) ;
F_4 ( V_23 ) ;
F_30 ( F_31 ( V_25 ) , TRUE ) ;
F_28 ( F_29 ( V_1 -> V_7 . V_54 ) , V_25 , FALSE , FALSE , 0 ) ;
F_32 ( V_1 -> V_7 . V_8 ) ;
V_1 -> V_10 = F_33 ( L_10 ) ;
for( V_15 = 0 , V_21 = 0 ; V_28 [ V_15 ] . V_56 ; V_15 ++ ) {
if( V_28 [ V_15 ] . V_57 > V_21 ) {
V_21 = V_28 [ V_15 ] . V_57 ;
}
}
V_45 = F_34 ( T_13 , 1 ) ;
V_45 -> V_29 = V_29 ;
V_45 -> V_5 = F_18 ( & V_45 -> V_29 , V_6 ) ;
V_45 -> V_6 = V_6 ;
V_45 -> V_58 = V_21 + 1 ;
F_35 ( V_1 -> V_10 , V_45 ) ;
V_1 -> V_7 . V_59 = F_36 ( FALSE , TRUE , sizeof( V_60 * ) ) ;
V_1 -> V_12 . V_13 = F_36 ( FALSE , TRUE , sizeof( T_4 * ) ) ;
V_1 -> V_12 . V_11 = V_1 ;
F_37 ( V_1 -> V_10 , V_1 -> V_12 . V_13 , V_61 , & V_1 -> V_7 ) ;
V_46 = F_38 ( L_10 , & V_1 -> V_12 , V_44 , 0 , F_8 , F_39 ( V_1 -> V_10 ) , F_10 ) ;
if( V_46 ) {
F_40 ( V_62 , V_63 , L_11 , V_46 -> V_64 ) ;
F_41 ( V_46 , TRUE ) ;
F_15 ( V_1 -> V_10 , V_1 -> V_12 . V_13 , NULL , NULL ) ;
F_4 ( V_1 ) ;
return;
}
V_26 = F_42 ( V_65 , NULL ) ;
F_43 ( F_29 ( V_1 -> V_7 . V_54 ) , V_26 , FALSE , FALSE , 0 ) ;
V_27 = ( T_9 * ) F_44 ( F_45 ( V_26 ) , V_65 ) ;
F_46 ( V_1 -> V_7 . V_8 , V_27 , V_66 ) ;
F_47 ( V_1 -> V_7 . V_8 , L_12 , F_48 ( V_67 ) , NULL ) ;
F_47 ( V_1 -> V_7 . V_8 , L_13 , F_48 ( F_13 ) , V_1 ) ;
F_32 ( V_1 -> V_7 . V_8 ) ;
F_49 ( V_1 -> V_7 . V_8 ) ;
F_50 ( & V_4 ) ;
F_51 ( F_52 ( V_1 -> V_7 . V_8 ) ) ;
}
static void
F_53 ( T_9 * T_15 V_18 , T_6 V_12 V_18 )
{
T_14 * V_64 ;
const char * V_44 ;
if ( V_68 == NULL ) {
F_40 ( V_62 , V_63 , L_14 ) ;
return;
}
V_64 = F_54 ( L_15 ) ;
F_55 ( V_64 ,
L_16 ,
V_68 -> V_47 , V_68 -> V_48 ,
V_68 -> V_49 ,
V_68 -> V_50 [ 0 ] , V_68 -> V_50 [ 1 ] ,
V_68 -> V_50 [ 2 ] , V_68 -> V_50 [ 3 ] ,
V_68 -> V_50 [ 4 ] , V_68 -> V_50 [ 5 ] ,
V_68 -> V_50 [ 6 ] , V_68 -> V_50 [ 7 ] ,
V_69 , 0 ) ;
V_44 = F_56 ( F_57 ( V_70 ) ) ;
if( V_44 [ 0 ] != 0 ) {
F_55 ( V_64 , L_17 , V_44 ) ;
}
F_16 ( V_64 -> V_64 , NULL ) ;
F_41 ( V_64 , TRUE ) ;
}
static void
F_58 ( T_9 * V_71 , T_6 V_11 V_18 )
{
T_16 * V_72 ;
if ( ! F_59 ( F_60 ( V_71 ) , ( T_6 * ) & V_72 ) ) {
F_61 () ;
}
V_69 = V_72 -> V_6 ;
}
static void
F_62 ( T_6 * V_73 , T_6 * T_17 V_18 , T_6 V_11 )
{
T_16 * V_72 = ( T_16 * ) V_73 ;
T_9 * V_71 = ( T_9 * ) V_11 ;
char V_74 [ 5 ] ;
if( F_63 ( & ( V_72 -> V_75 ) , V_68 ) ) {
return;
}
F_64 ( V_74 , sizeof( V_74 ) , L_18 , V_72 -> V_6 ) ;
F_65 ( F_60 ( V_71 ) , V_74 , V_72 ) ;
}
static void
F_66 ( T_9 * V_76 , T_6 V_11 )
{
T_16 * V_72 ;
T_9 * V_71 ;
V_71 = ( T_9 * ) V_11 ;
if ( ! F_59 ( F_60 ( V_76 ) , ( T_6 * ) & V_72 ) ) {
F_61 () ;
}
F_67 ( V_71 , F_48 ( F_58 ) , NULL ) ;
F_68 ( F_60 ( V_71 ) ) ;
F_69 ( V_72 != NULL ) ;
V_68 = & ( V_72 -> V_75 ) ;
F_67 ( V_71 , F_48 ( F_58 ) , NULL ) ;
F_68 ( F_60 ( V_71 ) ) ;
F_70 ( V_77 , ( V_78 ) F_62 , V_71 ) ;
F_47 ( V_71 , L_19 , F_48 ( F_58 ) , NULL ) ;
F_71 ( F_60 ( V_71 ) , 0 ) ;
}
static T_18
F_72 ( T_16 * V_72 , T_19 * V_79 , T_9 * V_76 , int V_80 )
{
static T_18 V_81 ;
char V_64 [ 64 ] ;
switch( V_80 % 15 ) {
case 0 :
F_64 ( V_64 , sizeof( V_64 ) , L_20 , V_79 -> V_56 ) ;
V_81 = F_73 (
F_60 ( V_76 ) , NULL , V_64 , NULL , FALSE ) ;
break;
default:
break;
}
return F_73 (
F_60 ( V_76 ) , & V_81 , V_79 -> V_56 , V_72 , TRUE ) ;
}
static void
F_74 ( T_6 * V_73 , T_6 * T_17 , T_6 * V_11 V_18 )
{
T_16 * V_72 = ( T_16 * ) V_73 ;
T_19 * V_79 = ( T_19 * ) T_17 ;
if( ( V_82 == NULL ) && ( V_83 == NULL ) ) {
V_83 = V_72 ;
V_84 = V_79 ;
return;
}
if( V_82 == NULL ) {
if( strcmp ( V_84 -> V_56 , V_79 -> V_56 ) > 0 ) {
V_83 = V_72 ;
V_84 = V_79 ;
return;
}
return;
}
if( strcmp ( V_85 -> V_56 , V_79 -> V_56 ) >= 0 ) {
return;
}
if( V_83 == NULL ) {
V_83 = V_72 ;
V_84 = V_79 ;
return;
}
if( strcmp ( V_84 -> V_56 , V_79 -> V_56 ) > 0 ) {
V_83 = V_72 ;
V_84 = V_79 ;
return;
}
return;
}
static void
F_75 ( T_9 * T_20 V_18 , T_6 V_11 V_18 )
{
V_86 = NULL ;
}
void F_76 ( T_21 * T_22 V_18 , T_6 V_11 V_18 )
{
T_9 * V_87 ;
T_9 * V_88 , * V_89 , * V_76 ;
T_9 * V_90 , * V_71 ;
T_9 * V_91 , * V_92 ;
T_9 * V_26 , * V_93 , * V_94 ;
T_23 * V_95 ;
#if 0
GtkTreeIter program_first_item_iter;
#endif
const char * V_44 ;
int V_80 = 0 ;
static T_24 args = {
L_21 ,
FALSE ,
FALSE ,
FALSE
} ;
if( V_86 ) {
F_77 ( V_86 ) ;
return;
}
V_86 = F_20 ( L_22 ) ;
F_22 ( F_7 ( V_86 ) , 400 , - 1 ) ;
V_87 = F_23 ( V_55 , 10 , FALSE ) ;
F_26 ( F_25 ( V_87 ) , 10 ) ;
F_24 ( F_25 ( V_86 ) , V_87 ) ;
F_78 ( V_87 ) ;
V_88 = F_23 ( V_96 , 3 , FALSE ) ;
F_26 ( F_25 ( V_88 ) , 10 ) ;
V_89 = F_27 ( L_23 ) ;
F_28 ( F_29 ( V_88 ) , V_89 , FALSE , FALSE , 0 ) ;
F_78 ( V_89 ) ;
V_68 = NULL ;
V_76 = F_79 ( & V_95 ) ;
{
#if F_80 ( 3 , 0 , 0 )
T_25 * V_97 ;
T_26 * V_98 ;
V_97 = F_81 ( V_76 ) ;
F_82 ( V_97 , V_99 ,
L_24 , & V_98 ,
NULL ) ;
F_83 ( V_95 ,
L_25 , & V_98 ,
L_26 , TRUE ,
NULL ) ;
#else
T_27 * V_100 ;
V_100 = F_84 ( V_76 ) ;
F_83 ( V_95 ,
L_27 , & ( V_100 -> V_101 [ V_102 ] ) ,
L_26 , TRUE ,
NULL ) ;
#endif
}
V_82 = NULL ;
V_85 = NULL ;
do {
V_83 = NULL ;
V_84 = NULL ;
F_70 ( V_77 , ( V_78 ) F_74 , NULL ) ;
if( V_83 ) {
#if 0
GtkTreeIter tmp_iter;
tmp_iter = dcerpcstat_add_program_to_menu(new_uuid_key, new_uuid_value,
prog_combo_box, program_item_index);
if (program_item_index == 0)
program_first_item_iter = tmp_iter;
#else
F_72 ( V_83 , V_84 ,
V_76 , V_80 ) ;
#endif
V_80 += 1 ;
}
V_82 = V_83 ;
V_85 = V_84 ;
} while( V_83 != NULL );
F_28 ( F_29 ( V_88 ) , V_76 , TRUE , TRUE , 0 ) ;
F_78 ( V_76 ) ;
F_26 ( F_25 ( V_88 ) , 10 ) ;
V_90 = F_27 ( L_28 ) ;
F_28 ( F_29 ( V_88 ) , V_90 , FALSE , FALSE , 0 ) ;
F_78 ( V_90 ) ;
V_71 = F_85 () ;
F_28 ( F_29 ( V_88 ) , V_71 , TRUE , TRUE , 0 ) ;
F_78 ( V_71 ) ;
F_47 ( V_76 , L_19 , F_48 ( F_66 ) , V_71 ) ;
#if 0
ws_combo_box_set_active_iter(GTK_COMBO_BOX(prog_combo_box), &program_first_item_iter);
#endif
F_28 ( F_29 ( V_87 ) , V_88 , TRUE , TRUE , 0 ) ;
F_78 ( V_88 ) ;
V_91 = F_23 ( V_96 , 3 , FALSE ) ;
V_92 = F_86 ( V_103 ) ;
F_47 ( V_92 , L_29 , F_48 ( V_104 ) , & args ) ;
F_28 ( F_29 ( V_91 ) , V_92 , FALSE , FALSE , 0 ) ;
F_78 ( V_92 ) ;
V_70 = F_87 () ;
F_47 ( V_70 , L_19 , F_48 ( V_105 ) , NULL ) ;
F_88 ( F_45 ( V_91 ) , V_106 , NULL ) ;
F_47 ( V_70 , L_30 , F_48 ( V_107 ) , NULL ) ;
F_47 ( V_86 , L_30 , F_48 ( V_108 ) , NULL ) ;
F_28 ( F_29 ( V_91 ) , V_70 , TRUE , TRUE , 0 ) ;
V_44 = F_56 ( F_57 ( V_109 ) ) ;
if( V_44 ) {
F_89 ( F_57 ( V_70 ) , V_44 ) ;
} else {
F_90 ( V_70 ) ;
}
F_78 ( V_70 ) ;
F_28 ( F_29 ( V_87 ) , V_91 , TRUE , TRUE , 0 ) ;
F_78 ( V_91 ) ;
F_88 ( F_45 ( V_92 ) , V_110 , V_70 ) ;
V_26 = F_42 ( V_111 , V_112 , NULL ) ;
F_28 ( F_29 ( V_87 ) , V_26 , FALSE , FALSE , 0 ) ;
F_78 ( V_26 ) ;
V_93 = ( T_9 * ) F_44 ( F_45 ( V_26 ) , V_111 ) ;
F_91 ( V_93 , L_29 ,
F_48 ( F_53 ) , NULL ) ;
V_94 = ( T_9 * ) F_44 ( F_45 ( V_26 ) , V_112 ) ;
F_46 ( V_86 , V_94 , V_66 ) ;
F_47 ( V_86 , L_12 , F_48 ( V_67 ) , NULL ) ;
F_47 ( V_86 , L_13 , F_48 ( F_75 ) , NULL ) ;
F_92 ( V_70 , V_93 ) ;
F_93 ( V_93 ) ;
F_94 ( V_70 ) ;
F_32 ( V_86 ) ;
F_49 ( V_86 ) ;
}
void
F_95 ( void )
{
F_96 ( & V_113 , NULL ) ;
}
