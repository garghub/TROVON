void F_1 ( char * V_1 )
{
T_1 V_2 ;
struct V_3 * V_4 ;
if ( ! V_1 || V_1 [ 0 ] == 0 ) {
F_2 ( L_1 , V_5 ) ;
return;
}
F_3 ( V_1 ) ;
if ( F_4 ( V_1 [ 0 ] ) ) {
V_2 = F_5 ( V_6 , V_1 ,
V_7 , & V_4 ) ;
if ( F_6 ( V_2 ) ) {
goto V_8;
}
V_5 [ 0 ] = 0 ;
} else {
V_2 = F_5 ( V_9 , V_1 ,
V_7 , & V_4 ) ;
if ( F_6 ( V_2 ) ) {
goto V_8;
}
}
if ( F_7
( V_5 , sizeof( V_5 ) , V_1 ) ) {
V_2 = V_10 ;
goto V_8;
}
if ( F_7
( V_5 , sizeof( V_5 ) , L_2 ) ) {
V_2 = V_10 ;
goto V_8;
}
V_9 = V_4 ;
F_2 ( L_3 , V_5 ) ;
return;
V_8:
F_2 ( L_4 ,
V_1 , F_8 ( V_2 ) ) ;
}
void F_9 ( char * V_11 , char * V_12 )
{
T_2 V_13 = V_6 ;
T_3 V_14 = V_15 ;
if ( V_11 ) {
V_13 = F_10 ( V_11 ) ;
if ( ! V_13 ) {
return;
}
if ( V_12 ) {
V_14 = strtoul ( V_12 , NULL , 0 ) ;
}
}
F_11 ( V_16 ) ;
F_2 ( L_5 ,
( (struct V_3 * ) V_13 ) -> V_1 .
V_17 , V_13 ) ;
F_11 ( V_18 ) ;
F_12 ( V_19 , V_20 , V_14 ,
V_21 , V_13 ) ;
F_11 ( V_22 ) ;
}
void F_13 ( void )
{
F_11 ( V_16 ) ;
F_2 ( L_6 ) ;
F_11 ( V_18 ) ;
F_14 ( V_19 , V_20 ,
V_15 , V_21 ,
V_6 ) ;
F_11 ( V_22 ) ;
}
void F_15 ( char * V_23 , char * V_12 )
{
T_2 V_13 = V_6 ;
T_3 V_14 = V_15 ;
T_4 V_24 ;
V_24 = ( T_4 ) strtoul ( V_23 , NULL , 0 ) ;
if ( V_12 ) {
V_14 = strtoul ( V_12 , NULL , 0 ) ;
}
F_11 ( V_16 ) ;
F_2 ( L_7 , V_24 ) ;
F_11 ( V_18 ) ;
F_12 ( V_19 , V_20 , V_14 ,
V_24 , V_13 ) ;
F_11 ( V_22 ) ;
}
static T_1
F_16 ( T_2 V_25 ,
T_3 V_26 ,
void * V_27 , void * * V_28 )
{
T_1 V_2 ;
char * V_29 = ( char * ) V_27 ;
T_3 V_30 ;
struct V_31 V_32 ;
struct V_33 V_34 ;
for ( V_30 = 0 ; V_30 < 4 ; V_30 ++ ) {
if ( ( V_29 [ V_30 ] != '?' ) &&
( V_29 [ V_30 ] != ( (struct V_3 * )
V_25 ) -> V_1 . V_17 [ V_30 ] ) ) {
return ( V_35 ) ;
}
}
V_32 . V_36 = V_37 ;
V_2 = F_17 ( V_25 , & V_32 , TRUE ) ;
if ( F_6 ( V_2 ) ) {
F_2 ( L_8 ,
V_25 ) ;
} else {
V_34 . V_24 = V_21 ;
V_34 . V_38 = V_15 ;
V_34 . V_39 = V_20 | V_40 ;
F_2 ( L_9 , ( char * ) V_32 . V_41 ) ;
( void ) F_18 ( V_25 , V_26 , & V_34 ,
NULL ) ;
F_19 ( V_32 . V_41 ) ;
}
return ( V_35 ) ;
}
T_1 F_20 ( char * V_42 )
{
char V_43 [ 5 ] = L_10 ;
char * V_44 = V_43 ;
if ( strlen ( V_42 ) > V_45 ) {
F_2 ( L_11 ) ;
return ( V_35 ) ;
}
F_21 ( V_42 ) ;
while ( * V_42 ) {
* V_44 = * V_42 ;
V_44 ++ ;
V_42 ++ ;
}
( void ) F_22 ( V_19 , V_46 ,
V_15 , F_16 ,
NULL , V_43 , NULL ) ;
F_11 ( V_22 ) ;
return ( V_35 ) ;
}
static T_1
F_23 ( T_2 V_25 ,
T_3 V_26 ,
void * V_27 , void * * V_28 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_25 ;
T_3 * V_47 = ( T_3 * ) V_27 ;
const union V_48 * V_49 ;
const union V_48 * V_50 = NULL ;
char * V_51 ;
char V_52 [ 48 ] ;
V_49 = F_24 ( V_4 -> V_1 . V_17 ) ;
if ( ! V_49 ) {
return ( V_35 ) ;
}
V_51 = F_25 ( V_4 ) ;
if ( ! V_51 ) {
return ( V_35 ) ;
}
if ( V_49 -> V_34 . V_53 & V_54 ) {
V_50 = V_49 + 1 ;
}
F_26 ( V_52 ,
V_49 -> V_34 . V_53 ) ;
F_2 ( L_12 , V_51 ,
F_27 ( V_49 -> V_34 . V_55 ) ,
V_52 ) ;
if ( V_50 ) {
F_2 ( L_13 ,
V_50 -> V_56 . type ,
V_50 -> V_56 . V_57 ,
V_50 -> V_56 . V_58 ) ;
}
F_2 ( L_14 ) ;
F_28 ( V_51 , V_4 , V_49 ) ;
F_19 ( V_51 ) ;
( * V_47 ) ++ ;
return ( V_35 ) ;
}
void F_29 ( void )
{
T_3 V_47 = 0 ;
( void ) F_22 ( V_19 , V_46 ,
V_15 ,
F_23 , NULL ,
( void * ) & V_47 , NULL ) ;
F_2 ( L_15 , V_47 ) ;
}
static T_1
F_30 ( T_2 V_25 ,
T_3 V_26 ,
void * V_27 , void * * V_28 )
{
struct V_59 * V_34 = (struct V_59 * ) V_27 ;
struct V_3 * V_4 =
(struct V_3 * ) V_25 ;
if ( V_4 -> type > V_60 ) {
F_2 ( L_16 ,
V_4 -> V_1 . V_17 , V_4 -> type ) ;
} else {
V_34 -> V_61 [ V_4 -> type ] ++ ;
}
return ( V_35 ) ;
}
static T_1
F_31 ( T_2 V_25 ,
T_3 V_26 ,
void * V_27 , void * * V_28 )
{
struct V_33 * V_34 = (struct V_33 * ) V_27 ;
struct V_31 V_32 ;
T_1 V_2 ;
V_34 -> V_47 ++ ;
V_32 . V_36 = V_37 ;
V_2 = F_17 ( V_25 , & V_32 , TRUE ) ;
if ( F_6 ( V_2 ) ) {
F_2 ( L_8 ,
V_25 ) ;
return ( V_35 ) ;
}
F_2 ( L_9 , ( char * ) V_32 . V_41 ) ;
F_19 ( V_32 . V_41 ) ;
( void ) F_18 ( V_25 , V_26 , V_34 , NULL ) ;
return ( V_35 ) ;
}
T_1 F_32 ( char * V_62 , char * V_63 )
{
struct V_33 V_34 ;
T_5 type ;
struct V_59 * V_64 ;
T_3 V_30 ;
T_3 V_65 = 0 ;
if ( ! V_62 ) {
V_64 =
F_33 ( sizeof( struct V_59 ) ) ;
( void ) F_22 ( V_19 , V_46 ,
V_15 ,
F_30 , NULL ,
( void * ) V_64 , NULL ) ;
F_2 ( L_17 ) ;
for ( V_30 = 0 ; V_30 < V_66 ; V_30 ++ ) {
F_2 ( L_18 , V_64 -> V_61 [ V_30 ] ,
F_34 ( V_30 ) ) ;
V_65 += V_64 -> V_61 [ V_30 ] ;
}
F_2 ( L_19 ,
V_65 ) ;
F_19 ( V_64 ) ;
return ( V_35 ) ;
}
type = F_35 ( V_62 , V_67 ) ;
if ( type == V_68 ) {
F_2 ( L_20 ) ;
return ( V_35 ) ;
}
F_11 ( V_16 ) ;
F_2
( L_21 ,
F_34 ( type ) ) ;
F_11 ( V_18 ) ;
V_34 . V_47 = 0 ;
V_34 . V_24 = V_21 ;
V_34 . V_38 = V_15 ;
V_34 . V_39 = V_20 | V_40 ;
( void ) F_22 ( type , V_46 , V_15 ,
F_31 , NULL ,
( void * ) & V_34 , NULL ) ;
F_2
( L_22 ,
V_34 . V_47 , F_34 ( type ) ) ;
F_11 ( V_22 ) ;
return ( V_35 ) ;
}
static T_1
F_36 ( T_2 V_25 ,
T_3 V_26 , void * V_27 , void * * V_28 )
{
struct V_69 * V_34 =
(struct V_69 * ) V_27 ;
struct V_3 * V_4 =
(struct V_3 * ) V_25 ;
union V_70 * V_71 ;
T_6 V_72 = TRUE ;
V_34 -> V_73 ++ ;
while ( V_72 ) {
if ( F_37 ( V_4 ) != V_74 ) {
F_2
( L_23
L_24 , V_4 ,
F_38 ( V_4 ) ,
F_37 ( V_4 ) ,
V_74 ) ;
return ( V_35 ) ;
}
if ( ( V_4 -> type == V_75 ) ||
( V_4 -> type == V_76 ) ) {
V_4 = (struct V_3 * ) V_4 -> V_71 ;
} else {
V_72 = FALSE ;
}
}
if ( V_4 -> type > V_77 ) {
F_2 ( L_25 ,
V_4 , V_4 -> type ) ;
return ( V_35 ) ;
}
if ( ! F_39 ( V_4 -> V_1 . V_17 ) ) {
F_2 ( L_26 , V_4 ) ;
return ( V_35 ) ;
}
V_71 = F_40 ( V_4 ) ;
if ( V_71 ) {
V_34 -> V_78 ++ ;
if ( F_37 ( V_71 ) != V_79 ) {
F_2
( L_27 ,
V_71 , F_38 ( V_71 ) ) ;
}
}
return ( V_35 ) ;
}
void F_41 ( void )
{
struct V_69 V_34 = { 0 , 0 } ;
( void ) F_22 ( V_19 , V_46 ,
V_15 , F_36 , NULL ,
( void * ) & V_34 , NULL ) ;
F_2 ( L_28 ,
V_34 . V_73 , V_34 . V_78 ) ;
}
static T_1
F_42 ( T_2 V_25 ,
T_3 V_26 ,
void * V_27 , void * * V_28 )
{
union V_70 * V_80 =
(union V_70 * ) V_27 ;
struct V_3 * V_4 =
(struct V_3 * ) V_25 ;
if ( V_4 == ( void * ) V_80 ) {
F_2 ( L_29 ,
F_43 ( V_4 ) ) ;
}
if ( F_40 ( V_4 ) == V_80 ) {
F_2 ( L_30 ,
V_4 , F_43 ( V_4 ) ) ;
}
return ( V_35 ) ;
}
void F_44 ( char * V_81 )
{
union V_70 * V_80 ;
T_7 V_82 ;
V_82 = strtoul ( V_81 , NULL , 16 ) ;
V_80 = F_45 ( V_82 ) ;
( void ) F_22 ( V_19 , V_46 ,
V_15 , F_42 ,
NULL , ( void * ) V_80 , NULL ) ;
}
static T_1
F_46 ( T_2 V_25 ,
T_3 V_26 , void * V_27 , void * * V_28 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_25 ;
T_1 V_2 ;
struct V_31 V_32 ;
struct V_3 * V_83 ;
struct V_84 * V_34 ;
T_3 V_30 ;
if ( ( V_4 -> type != V_85 ) &&
( V_4 -> type != V_86 ) ) {
return ( V_35 ) ;
}
V_2 = F_47 ( V_4 , V_87 ,
F_48 ( T_2 , & V_83 ) ) ;
if ( F_6 ( V_2 ) ) {
return ( V_35 ) ;
}
V_32 . V_36 = V_37 ;
V_2 = F_17 ( V_25 , & V_32 , TRUE ) ;
if ( F_6 ( V_2 ) ) {
F_2 ( L_8 ,
V_25 ) ;
return ( V_35 ) ;
}
V_2 = F_49 ( V_25 , & V_34 ) ;
if ( F_6 ( V_2 ) ) {
return ( V_35 ) ;
}
F_2 ( L_31 , ( char * ) V_32 . V_41 , V_4 -> type ) ;
F_19 ( V_32 . V_41 ) ;
if ( V_34 -> V_88 & V_89 ) {
F_2 ( L_32 ) ;
}
F_2 ( L_14 ) ;
F_2 ( L_33 , V_83 ) ;
if ( V_34 -> V_90 & V_91 ) {
F_2 ( L_34 ,
F_50 ( V_34 -> V_82 ) ) ;
} else {
F_2 ( L_35 ) ;
}
if ( V_34 -> V_90 & V_92 ) {
F_2 ( L_36 , V_34 -> V_93 . string ) ;
} else {
F_2 ( L_37 ) ;
}
if ( V_34 -> V_90 & V_94 ) {
F_2 ( L_38 , V_34 -> V_95 . string ) ;
} else {
F_2 ( L_39 ) ;
}
if ( V_34 -> V_90 & V_96 ) {
for ( V_30 = 0 ; V_30 < V_34 -> V_97 . V_47 ; V_30 ++ ) {
F_2 ( L_40 ,
V_34 -> V_97 . V_98 [ V_30 ] . string ) ;
}
} else {
F_2 ( L_41 ) ;
}
F_19 ( V_34 ) ;
return ( V_35 ) ;
}
void F_51 ( void )
{
( void ) F_22 ( V_19 , V_46 ,
V_15 , F_46 , NULL , NULL ,
NULL ) ;
}
