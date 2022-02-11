void F_1 ( T_1 V_1 , union V_2 * V_3 )
{
T_1 V_4 ;
for ( V_4 = 0 ; V_4 < V_1 ; V_4 ++ ) {
switch ( V_3 [ V_4 ] . type ) {
case V_5 :
F_2 ( V_3 [ V_4 ] . V_6 . V_7 ) ;
break;
case V_8 :
F_1 ( V_3 [ V_4 ] . V_9 . V_1 ,
V_3 [ V_4 ] . V_9 . V_10 ) ;
F_2 ( V_3 [ V_4 ] . V_9 . V_10 ) ;
break;
default:
break;
}
}
}
static T_2
F_3 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
T_2 V_15 ;
struct V_16 V_17 ;
union V_2 V_18 [ V_19 + 1 ] ;
T_1 V_4 ;
F_4 ( V_20 ) ;
if ( V_21 && ! V_22 ) {
F_5 ( L_1 ) ;
}
V_17 . V_1 = 0 ;
V_17 . V_7 = NULL ;
if ( V_12 -> args && V_12 -> args [ 0 ] ) {
for ( V_4 = 0 ; ( V_12 -> args [ V_4 ] && * ( V_12 -> args [ V_4 ] ) ) ; V_4 ++ ) {
V_15 = F_6 ( V_12 -> V_23 [ V_4 ] ,
V_12 -> args [ V_4 ] ,
& V_18 [ V_4 ] ) ;
if ( F_7 ( V_15 ) ) {
F_8 ( ( V_24 , V_15 ,
L_2 ) ) ;
goto V_25;
}
}
V_17 . V_1 = V_4 ;
V_17 . V_7 = V_18 ;
}
V_14 -> V_7 = V_26 ;
V_14 -> V_27 = V_28 ;
V_29 = TRUE ;
V_15 = F_9 ( NULL , V_12 -> V_30 ,
& V_17 , V_14 ) ;
V_31 = FALSE ;
V_29 = FALSE ;
if ( F_7 ( V_15 ) ) {
if ( ( V_15 == V_32 ) || V_33 ) {
F_8 ( ( V_24 , V_15 ,
L_3 ) ) ;
V_33 = FALSE ;
V_15 = V_34 ;
goto V_25;
}
F_8 ( ( V_24 , V_15 ,
L_4 ,
V_12 -> V_30 ) ) ;
if ( V_15 == V_35 ) {
F_10 ( ( V_24 ,
L_5
L_6 ,
V_28 ,
( T_1 ) V_14 -> V_27 ) ) ;
}
}
V_25:
F_1 ( V_17 . V_1 , V_18 ) ;
F_11 ( V_15 ) ;
}
static T_2 F_12 ( struct V_11 * V_12 )
{
T_2 V_15 ;
F_13 ( V_36 ) ;
V_12 -> V_30 [ 0 ] = 0 ;
if ( ( V_12 -> V_37 [ 0 ] != '\\' ) && ( V_12 -> V_37 [ 0 ] != '/' ) ) {
if ( F_14 ( V_12 -> V_30 , sizeof( V_12 -> V_30 ) ,
V_38 ) ) {
V_15 = V_35 ;
goto V_39;
}
}
if ( F_14 ( V_12 -> V_30 , sizeof( V_12 -> V_30 ) ,
V_12 -> V_37 ) ) {
V_15 = V_35 ;
goto V_39;
}
F_15 ( V_12 -> V_30 ) ;
F_16 ( V_40 ) ;
F_5 ( L_7 , V_12 -> V_30 ) ;
if ( V_12 -> V_41 & V_42 ) {
V_31 = TRUE ;
F_16 ( V_43 ) ;
}
else {
F_16 ( V_44 ) ;
}
return ( V_34 ) ;
V_39:
F_8 ( ( V_24 , V_15 , L_8 ) ) ;
return ( V_15 ) ;
}
T_1 F_17 ( struct V_45 * V_46 )
{
return ( V_46 -> V_47 - V_46 -> V_48 -
V_46 -> V_49 ) ;
}
static T_1 F_18 ( void )
{
T_1 V_50 = 0 ;
#ifdef F_19
V_50 += F_17 ( V_51 ) ;
V_50 += F_17 ( V_52 ) ;
V_50 += F_17 ( V_53 ) ;
V_50 += F_17 ( V_54 ) ;
#endif
return ( V_50 ) ;
}
static T_2
F_20 ( T_3 V_55 ,
T_1 V_56 , void * V_57 , void * * V_58 )
{
union V_59 * V_60 ;
struct V_61 * V_62 =
(struct V_61 * ) V_55 ;
struct V_13 V_14 ;
T_2 V_15 ;
V_60 = F_21 ( V_62 ) ;
if ( V_60 -> V_63 . V_64 ) {
return ( V_34 ) ;
}
V_14 . V_7 = NULL ;
V_14 . V_27 = V_65 ;
F_22 ( V_62 , L_9 ) ;
F_5 ( L_10 ) ;
V_29 = TRUE ;
V_15 = F_9 ( V_62 , NULL , NULL , & V_14 ) ;
F_5 ( L_11 ,
F_23 ( V_62 ) ,
F_24 ( V_15 ) ) ;
V_29 = FALSE ;
return ( V_34 ) ;
}
void
F_25 ( char * V_37 , char * * args , T_4 * V_23 , T_1 V_41 )
{
T_2 V_15 ;
struct V_13 V_14 ;
char * V_66 ;
#ifdef F_26
T_1 V_67 ;
T_1 V_68 ;
#endif
if ( V_29 ) {
F_5 ( L_12 ) ;
return;
}
#ifdef F_26
V_67 = F_18 () ;
#endif
if ( * V_37 == '*' ) {
( void ) F_27 ( V_69 , V_70 ,
V_71 ,
F_20 , NULL , NULL ,
NULL ) ;
return;
}
V_66 = F_28 ( strlen ( V_37 ) + 1 ) ;
if ( ! V_66 ) {
return;
}
memset ( & V_72 , 0 , sizeof( struct V_11 ) ) ;
strcpy ( V_66 , V_37 ) ;
F_29 ( V_66 ) ;
if ( ! strncmp ( V_66 , L_13 , 6 ) ) {
F_30 () ;
F_2 ( V_66 ) ;
return;
}
V_72 . V_37 = V_66 ;
V_72 . args = args ;
V_72 . V_23 = V_23 ;
V_72 . V_41 = V_41 ;
V_14 . V_7 = NULL ;
V_14 . V_27 = V_65 ;
V_15 = F_12 ( & V_72 ) ;
if ( F_7 ( V_15 ) ) {
F_2 ( V_66 ) ;
return;
}
V_15 = F_31 ( NULL , V_72 . V_30 ,
& V_72 . V_63 ) ;
if ( F_32 ( V_15 ) ) {
V_15 = F_3 ( & V_72 ,
& V_14 ) ;
}
F_2 ( V_66 ) ;
F_33 ( ( V_73 ) 10 ) ;
#ifdef F_26
V_68 =
F_18 () - V_67 ;
F_16 ( V_40 ) ;
if ( V_68 > 0 ) {
F_5
( L_14 ,
V_68 , V_72 . V_30 ) ;
}
#endif
if ( F_7 ( V_15 ) ) {
F_5 ( L_15 ,
V_72 . V_30 ,
F_24 ( V_15 ) ) ;
} else {
if ( V_14 . V_27 ) {
F_5 ( L_16
L_17 ,
V_72 . V_30 ,
V_14 . V_7 ,
( T_1 ) V_14 . V_27 ) ;
F_34 ( V_14 . V_7 , 1 ) ;
if ( F_35
( ( F_36
( struct V_61 ,
V_72 . V_63 ) -> V_37 . V_74 ) ,
V_75 ) ) {
F_37 ( V_14 . V_7 ) ;
}
} else {
F_5
( L_18 ,
V_72 . V_30 ) ;
}
}
F_16 ( V_43 ) ;
}
static void T_5 F_38 ( void * V_57 )
{
T_2 V_15 ;
struct V_11 * V_12 = V_57 ;
struct V_11 V_76 ;
T_1 V_4 ;
T_6 V_77 ;
struct V_13 V_14 ;
( void ) F_39 ( V_12 -> V_78 , 1 , V_79 ) ;
if ( V_12 -> V_80 ) {
F_40 ( V_12 -> V_81 ,
V_12 -> V_82 ) ;
F_40 ( ( T_1 ) F_41 () ,
V_12 -> V_83 ) ;
}
if ( V_12 -> V_84 && ( V_12 -> V_81 < V_12 -> V_85 ) ) {
V_12 -> V_84 [ V_12 -> V_81 ++ ] = F_41 () ;
}
V_76 = * V_12 ;
V_76 . args = V_76 . V_86 ;
V_76 . V_86 [ 0 ] = V_76 . V_87 ;
V_76 . V_86 [ 1 ] = V_76 . V_83 ;
V_76 . V_86 [ 2 ] = V_76 . V_82 ;
V_76 . V_86 [ 3 ] = NULL ;
V_76 . V_23 = V_76 . V_88 ;
( void ) F_42 ( V_12 -> V_78 , 1 ) ;
for ( V_4 = 0 ; V_4 < V_12 -> V_89 ; V_4 ++ ) {
V_15 = F_3 ( & V_76 , & V_14 ) ;
if ( F_7 ( V_15 ) ) {
F_5
( L_19 ,
F_24 ( V_15 ) , V_12 -> V_30 , V_4 ) ;
if ( V_15 == V_32 ) {
break;
}
}
#if 0
if ((i % 100) == 0) {
acpi_os_printf("%u loops, Thread 0x%x\n",
i, acpi_os_get_thread_id());
}
if (return_obj.length) {
acpi_os_printf
("Evaluation of %s returned object %p Buflen %X\n",
info->pathname, return_obj.pointer,
(u32)return_obj.length);
acpi_db_dump_external_object(return_obj.pointer, 1);
}
#endif
}
V_77 = 0 ;
( void ) F_39 ( V_12 -> V_90 ,
1 , V_79 ) ;
V_12 -> V_91 ++ ;
if ( V_12 -> V_91 == V_12 -> V_85 ) {
V_77 = 1 ;
}
( void ) F_42 ( V_12 -> V_90 , 1 ) ;
if ( V_77 ) {
V_15 = F_42 ( V_12 -> V_92 , 1 ) ;
if ( F_7 ( V_15 ) ) {
F_5
( L_20 ,
F_24 ( V_15 ) ) ;
}
}
}
void
F_43 ( char * V_93 ,
char * V_94 , char * V_95 )
{
T_2 V_15 ;
T_1 V_85 ;
T_1 V_89 ;
T_1 V_4 ;
T_1 V_96 ;
T_7 V_92 ;
T_7 V_90 ;
T_7 V_78 ;
V_85 = strtoul ( V_93 , NULL , 0 ) ;
V_89 = strtoul ( V_94 , NULL , 0 ) ;
if ( ! V_85 || ! V_89 ) {
F_5 ( L_21 ,
V_85 , V_89 ) ;
return;
}
V_15 = F_44 ( 1 , 0 , & V_92 ) ;
if ( F_7 ( V_15 ) ) {
F_5 ( L_22
L_23 ,
F_24 ( V_15 ) ) ;
return;
}
V_15 = F_44 ( 1 , 1 , & V_90 ) ;
if ( F_7 ( V_15 ) ) {
F_5 ( L_22
L_24 ,
F_24 ( V_15 ) ) ;
( void ) F_45 ( V_92 ) ;
return;
}
V_15 = F_44 ( 1 , 1 , & V_78 ) ;
if ( F_7 ( V_15 ) ) {
F_5 ( L_22
L_25 ,
F_24 ( V_15 ) ) ;
( void ) F_45 ( V_90 ) ;
( void ) F_45 ( V_92 ) ;
return;
}
memset ( & V_72 , 0 , sizeof( struct V_11 ) ) ;
V_72 . V_85 = V_85 ;
V_96 = sizeof( V_97 ) * V_72 . V_85 ;
V_72 . V_84 = F_46 ( V_96 ) ;
if ( V_72 . V_84 == NULL ) {
F_5 ( L_26 ) ;
( void ) F_45 ( V_92 ) ;
( void ) F_45 ( V_90 ) ;
( void ) F_45 ( V_78 ) ;
return;
}
memset ( V_72 . V_84 , 0 , V_96 ) ;
V_72 . V_37 = V_95 ;
V_72 . V_41 = 0 ;
V_72 . V_89 = V_89 ;
V_72 . V_92 = V_92 ;
V_72 . V_90 = V_90 ;
V_72 . V_78 = V_78 ;
V_72 . V_80 = 1 ;
V_72 . args = V_72 . V_86 ;
V_72 . V_86 [ 0 ] =
V_72 . V_87 ;
V_72 . V_86 [ 1 ] =
V_72 . V_83 ;
V_72 . V_86 [ 2 ] =
V_72 . V_82 ;
V_72 . V_86 [ 3 ] = NULL ;
V_72 . V_23 = V_72 . V_88 ;
V_72 . V_88 [ 0 ] = V_98 ;
V_72 . V_88 [ 1 ] = V_98 ;
V_72 . V_88 [ 2 ] = V_98 ;
F_40 ( V_85 ,
V_72 . V_87 ) ;
V_15 = F_12 ( & V_72 ) ;
if ( F_7 ( V_15 ) ) {
goto V_99;
}
V_15 = F_31 ( NULL , V_72 . V_30 ,
& V_72 . V_63 ) ;
if ( F_7 ( V_15 ) ) {
F_5 ( L_27 ,
F_24 ( V_15 ) ,
V_72 . V_30 ) ;
goto V_99;
}
F_5 ( L_28 ,
V_85 , V_89 ) ;
for ( V_4 = 0 ; V_4 < ( V_85 ) ; V_4 ++ ) {
V_15 =
F_47 ( V_100 ,
F_38 ,
& V_72 ) ;
if ( F_7 ( V_15 ) ) {
break;
}
}
( void ) F_39 ( V_92 , 1 , V_79 ) ;
F_16 ( V_40 ) ;
F_5 ( L_29 , V_85 ) ;
F_16 ( V_43 ) ;
V_99:
( void ) F_45 ( V_92 ) ;
( void ) F_45 ( V_90 ) ;
( void ) F_45 ( V_78 ) ;
F_48 ( V_72 . V_84 ) ;
V_72 . V_84 = NULL ;
}
