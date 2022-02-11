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
F_8 ( ( V_24 , V_15 ,
L_3 ,
V_12 -> V_30 ) ) ;
if ( V_15 == V_32 ) {
F_10 ( ( V_24 ,
L_4
L_5 ,
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
F_13 ( V_33 ) ;
V_12 -> V_30 [ 0 ] = 0 ;
if ( ( V_12 -> V_34 [ 0 ] != '\\' ) && ( V_12 -> V_34 [ 0 ] != '/' ) ) {
if ( F_14 ( V_12 -> V_30 , sizeof( V_12 -> V_30 ) ,
V_35 ) ) {
V_15 = V_32 ;
goto V_36;
}
}
if ( F_14 ( V_12 -> V_30 , sizeof( V_12 -> V_30 ) ,
V_12 -> V_34 ) ) {
V_15 = V_32 ;
goto V_36;
}
F_15 ( V_12 -> V_30 ) ;
F_16 ( V_37 ) ;
F_5 ( L_6 , V_12 -> V_30 ) ;
if ( V_12 -> V_38 & V_39 ) {
V_31 = TRUE ;
F_16 ( V_40 ) ;
}
else {
F_16 ( V_41 ) ;
}
return ( V_42 ) ;
V_36:
F_8 ( ( V_24 , V_15 , L_7 ) ) ;
return ( V_15 ) ;
}
T_1 F_17 ( struct V_43 * V_44 )
{
return ( V_44 -> V_45 - V_44 -> V_46 -
V_44 -> V_47 ) ;
}
static T_1 F_18 ( void )
{
T_1 V_48 = 0 ;
#ifdef F_19
V_48 += F_17 ( V_49 ) ;
V_48 += F_17 ( V_50 ) ;
V_48 += F_17 ( V_51 ) ;
V_48 += F_17 ( V_52 ) ;
#endif
return ( V_48 ) ;
}
static T_2
F_20 ( T_3 V_53 ,
T_1 V_54 , void * V_55 , void * * V_56 )
{
union V_57 * V_58 ;
struct V_59 * V_60 =
(struct V_59 * ) V_53 ;
struct V_13 V_14 ;
T_2 V_15 ;
V_58 = F_21 ( V_60 ) ;
if ( V_58 -> V_61 . V_62 ) {
return ( V_42 ) ;
}
V_14 . V_7 = NULL ;
V_14 . V_27 = V_63 ;
F_22 ( V_60 , L_8 ) ;
F_5 ( L_9 ) ;
V_29 = TRUE ;
V_15 = F_9 ( V_60 , NULL , NULL , & V_14 ) ;
F_5 ( L_10 ,
F_23 ( V_60 ) ,
F_24 ( V_15 ) ) ;
V_29 = FALSE ;
return ( V_42 ) ;
}
void
F_25 ( char * V_34 , char * * args , T_4 * V_23 , T_1 V_38 )
{
T_2 V_15 ;
struct V_13 V_14 ;
char * V_64 ;
#ifdef F_26
T_1 V_65 ;
T_1 V_66 ;
#endif
if ( V_29 ) {
F_5 ( L_11 ) ;
return;
}
#ifdef F_26
V_65 = F_18 () ;
#endif
if ( * V_34 == '*' ) {
( void ) F_27 ( V_67 , V_68 ,
V_69 ,
F_20 , NULL , NULL ,
NULL ) ;
return;
} else {
V_64 = F_28 ( strlen ( V_34 ) + 1 ) ;
if ( ! V_64 ) {
return;
}
memset ( & V_70 , 0 ,
sizeof( struct V_11 ) ) ;
strcpy ( V_64 , V_34 ) ;
F_29 ( V_64 ) ;
V_70 . V_34 = V_64 ;
V_70 . args = args ;
V_70 . V_23 = V_23 ;
V_70 . V_38 = V_38 ;
V_14 . V_7 = NULL ;
V_14 . V_27 = V_63 ;
V_15 = F_12 ( & V_70 ) ;
if ( F_7 ( V_15 ) ) {
F_2 ( V_64 ) ;
return;
}
V_15 = F_30 ( NULL , V_70 . V_30 ,
& V_70 . V_61 ) ;
if ( F_31 ( V_15 ) ) {
V_15 =
F_3 ( & V_70 ,
& V_14 ) ;
}
F_2 ( V_64 ) ;
}
F_32 ( ( V_71 ) 10 ) ;
#ifdef F_26
V_66 =
F_18 () - V_65 ;
F_16 ( V_37 ) ;
if ( V_66 > 0 ) {
F_5
( L_12 ,
V_66 , V_70 . V_30 ) ;
}
#endif
if ( F_7 ( V_15 ) ) {
F_5 ( L_13 ,
V_70 . V_30 ,
F_24 ( V_15 ) ) ;
} else {
if ( V_14 . V_27 ) {
F_5 ( L_14
L_15 ,
V_70 . V_30 ,
V_14 . V_7 ,
( T_1 ) V_14 . V_27 ) ;
F_33 ( V_14 . V_7 , 1 ) ;
if ( F_34
( ( F_35
( struct V_59 ,
V_70 . V_61 ) -> V_34 . V_72 ) ,
V_73 ) ) {
F_36 ( V_14 . V_7 ) ;
}
} else {
F_5
( L_16 ,
V_70 . V_30 ) ;
}
}
F_16 ( V_40 ) ;
}
static void T_5 F_37 ( void * V_55 )
{
T_2 V_15 ;
struct V_11 * V_12 = V_55 ;
struct V_11 V_74 ;
T_1 V_4 ;
T_6 V_75 ;
struct V_13 V_14 ;
( void ) F_38 ( V_12 -> V_76 , 1 , V_77 ) ;
if ( V_12 -> V_78 ) {
F_39 ( V_12 -> V_79 ,
V_12 -> V_80 ) ;
F_39 ( ( T_1 ) F_40 () ,
V_12 -> V_81 ) ;
}
if ( V_12 -> V_82 && ( V_12 -> V_79 < V_12 -> V_83 ) ) {
V_12 -> V_82 [ V_12 -> V_79 ++ ] = F_40 () ;
}
V_74 = * V_12 ;
V_74 . args = V_74 . V_84 ;
V_74 . V_84 [ 0 ] = V_74 . V_85 ;
V_74 . V_84 [ 1 ] = V_74 . V_81 ;
V_74 . V_84 [ 2 ] = V_74 . V_80 ;
V_74 . V_84 [ 3 ] = NULL ;
V_74 . V_23 = V_74 . V_86 ;
( void ) F_41 ( V_12 -> V_76 , 1 ) ;
for ( V_4 = 0 ; V_4 < V_12 -> V_87 ; V_4 ++ ) {
V_15 = F_3 ( & V_74 , & V_14 ) ;
if ( F_7 ( V_15 ) ) {
F_5
( L_17 ,
F_24 ( V_15 ) , V_12 -> V_30 , V_4 ) ;
if ( V_15 == V_88 ) {
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
V_75 = 0 ;
( void ) F_38 ( V_12 -> V_89 ,
1 , V_77 ) ;
V_12 -> V_90 ++ ;
if ( V_12 -> V_90 == V_12 -> V_83 ) {
V_75 = 1 ;
}
( void ) F_41 ( V_12 -> V_89 , 1 ) ;
if ( V_75 ) {
V_15 = F_41 ( V_12 -> V_91 , 1 ) ;
if ( F_7 ( V_15 ) ) {
F_5
( L_18 ,
F_24 ( V_15 ) ) ;
}
}
}
void
F_42 ( char * V_92 ,
char * V_93 , char * V_94 )
{
T_2 V_15 ;
T_1 V_83 ;
T_1 V_87 ;
T_1 V_4 ;
T_1 V_95 ;
T_7 V_91 ;
T_7 V_89 ;
T_7 V_76 ;
V_83 = strtoul ( V_92 , NULL , 0 ) ;
V_87 = strtoul ( V_93 , NULL , 0 ) ;
if ( ! V_83 || ! V_87 ) {
F_5 ( L_19 ,
V_83 , V_87 ) ;
return;
}
V_15 = F_43 ( 1 , 0 , & V_91 ) ;
if ( F_7 ( V_15 ) ) {
F_5 ( L_20
L_21 ,
F_24 ( V_15 ) ) ;
return;
}
V_15 = F_43 ( 1 , 1 , & V_89 ) ;
if ( F_7 ( V_15 ) ) {
F_5 ( L_20
L_22 ,
F_24 ( V_15 ) ) ;
( void ) F_44 ( V_91 ) ;
return;
}
V_15 = F_43 ( 1 , 1 , & V_76 ) ;
if ( F_7 ( V_15 ) ) {
F_5 ( L_20
L_23 ,
F_24 ( V_15 ) ) ;
( void ) F_44 ( V_89 ) ;
( void ) F_44 ( V_91 ) ;
return;
}
memset ( & V_70 , 0 , sizeof( struct V_11 ) ) ;
V_70 . V_83 = V_83 ;
V_95 = sizeof( V_96 ) * V_70 . V_83 ;
V_70 . V_82 = F_45 ( V_95 ) ;
if ( V_70 . V_82 == NULL ) {
F_5 ( L_24 ) ;
( void ) F_44 ( V_91 ) ;
( void ) F_44 ( V_89 ) ;
( void ) F_44 ( V_76 ) ;
return;
}
memset ( V_70 . V_82 , 0 , V_95 ) ;
V_70 . V_34 = V_94 ;
V_70 . V_38 = 0 ;
V_70 . V_87 = V_87 ;
V_70 . V_91 = V_91 ;
V_70 . V_89 = V_89 ;
V_70 . V_76 = V_76 ;
V_70 . V_78 = 1 ;
V_70 . args = V_70 . V_84 ;
V_70 . V_84 [ 0 ] =
V_70 . V_85 ;
V_70 . V_84 [ 1 ] =
V_70 . V_81 ;
V_70 . V_84 [ 2 ] =
V_70 . V_80 ;
V_70 . V_84 [ 3 ] = NULL ;
V_70 . V_23 = V_70 . V_86 ;
V_70 . V_86 [ 0 ] = V_97 ;
V_70 . V_86 [ 1 ] = V_97 ;
V_70 . V_86 [ 2 ] = V_97 ;
F_39 ( V_83 ,
V_70 . V_85 ) ;
V_15 = F_12 ( & V_70 ) ;
if ( F_7 ( V_15 ) ) {
goto V_98;
}
V_15 = F_30 ( NULL , V_70 . V_30 ,
& V_70 . V_61 ) ;
if ( F_7 ( V_15 ) ) {
F_5 ( L_25 ,
F_24 ( V_15 ) ,
V_70 . V_30 ) ;
goto V_98;
}
F_5 ( L_26 ,
V_83 , V_87 ) ;
for ( V_4 = 0 ; V_4 < ( V_83 ) ; V_4 ++ ) {
V_15 =
F_46 ( V_99 ,
F_37 ,
& V_70 ) ;
if ( F_7 ( V_15 ) ) {
break;
}
}
( void ) F_38 ( V_91 , 1 , V_77 ) ;
F_16 ( V_37 ) ;
F_5 ( L_27 , V_83 ) ;
F_16 ( V_40 ) ;
V_98:
( void ) F_44 ( V_91 ) ;
( void ) F_44 ( V_89 ) ;
( void ) F_44 ( V_76 ) ;
F_47 ( V_70 . V_82 ) ;
V_70 . V_82 = NULL ;
}
