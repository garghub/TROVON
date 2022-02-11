void
F_1 ( char * V_1 ,
struct V_2 * V_3 ,
union V_4 * V_5 )
{
T_1 V_6 ;
T_1 V_7 ;
if ( ! V_5 ) {
F_2 ( L_1 ) ;
return;
}
V_6 = strtoul ( V_1 , NULL , 16 ) ;
V_7 = ( T_1 ) F_3 ( V_5 -> V_8 . V_9 ,
V_3 -> V_10 . V_11 ) ;
if ( V_6 <= V_7 ) {
F_2 ( L_2 ,
V_6 , V_7 ) ;
}
V_3 -> V_12 = V_6 ;
F_2 ( L_3 , V_6 ) ;
}
void F_4 ( union V_4 * V_5 )
{
if ( ! V_5 ) {
F_2 ( L_1 ) ;
return;
}
V_13 = TRUE ;
}
void F_5 ( char * V_14 , char * V_15 , char * V_16 )
{
char type ;
T_1 V_17 ;
T_1 V_18 ;
struct V_2 * V_3 ;
union V_19 * V_20 ;
T_2 V_21 ;
struct V_22 * V_23 ;
F_6 ( V_14 ) ;
type = V_14 [ 0 ] ;
if ( ( type != 'L' ) && ( type != 'A' ) && ( type != 'N' ) ) {
F_2 ( L_4 , V_14 ) ;
return;
}
V_18 = strtoul ( V_16 , NULL , 16 ) ;
if ( type == 'N' ) {
V_23 = F_7 ( V_15 ) ;
if ( ! V_23 ) {
return;
}
if ( V_23 -> type != V_24 ) {
F_2 ( L_5 ) ;
return;
}
V_20 = V_23 -> V_25 ;
V_20 -> integer . V_18 = V_18 ;
return;
}
V_17 = strtoul ( V_15 , NULL , 16 ) ;
V_3 = F_8 ( V_26 ) ;
if ( ! V_3 ) {
F_2 ( L_1 ) ;
return;
}
V_20 = F_9 ( ( V_27 ) V_18 ) ;
if ( ! V_20 ) {
F_2 ( L_6 ) ;
return;
}
switch ( type ) {
case 'A' :
if ( V_17 > V_28 ) {
F_2 ( L_7 ,
V_17 ) ;
goto V_29;
}
V_21 = F_10 ( V_30 ,
V_17 , V_20 ,
V_3 ) ;
if ( F_11 ( V_21 ) ) {
goto V_29;
}
V_20 = V_3 -> V_31 [ V_17 ] . V_25 ;
F_2 ( L_8 , V_17 ) ;
F_12 ( V_20 , V_3 ) ;
break;
case 'L' :
if ( V_17 > V_32 ) {
F_2
( L_9 , V_17 ) ;
goto V_29;
}
V_21 = F_10 ( V_33 ,
V_17 , V_20 ,
V_3 ) ;
if ( F_11 ( V_21 ) ) {
goto V_29;
}
V_20 = V_3 -> V_34 [ V_17 ] . V_25 ;
F_2 ( L_10 , V_17 ) ;
F_12 ( V_20 , V_3 ) ;
break;
default:
break;
}
V_29:
F_13 ( V_20 ) ;
}
void F_14 ( char * V_35 , union V_4 * V_5 )
{
T_1 V_36 = 8 ;
if ( ! V_5 ) {
F_2 ( L_1 ) ;
return;
}
if ( V_35 ) {
V_36 = strtoul ( V_35 , NULL , 0 ) ;
}
#ifdef F_15
F_16 ( NULL , V_5 , V_36 ) ;
#endif
}
T_2 F_17 ( char * V_37 )
{
T_2 V_21 ;
union V_4 * V_5 ;
struct V_2 * V_3 ;
union V_19 * V_20 ;
struct V_22 * V_38 ;
V_38 = F_7 ( V_37 ) ;
if ( ! V_38 ) {
return ( V_39 ) ;
}
if ( V_38 -> type != V_40 ) {
F_18 ( ( V_41 , L_11 ,
V_37 , F_19 ( V_38 -> type ) ) ) ;
return ( V_39 ) ;
}
V_20 = V_38 -> V_25 ;
V_5 = F_20 ( V_20 -> V_38 . V_11 ) ;
if ( ! V_5 ) {
return ( V_42 ) ;
}
V_3 = F_21 ( 0 , V_5 , NULL , NULL ) ;
if ( ! V_3 ) {
return ( V_42 ) ;
}
V_21 = F_22 ( V_3 , V_5 , NULL ,
V_20 -> V_38 . V_11 ,
V_20 -> V_38 . V_43 , NULL ,
V_44 ) ;
if ( F_11 ( V_21 ) ) {
return ( V_21 ) ;
}
V_21 = F_23 ( & V_20 -> V_38 . V_45 ) ;
V_3 -> V_45 = V_20 -> V_38 . V_45 ;
V_21 = F_24 ( V_38 , V_38 -> type , V_3 ) ;
if ( F_11 ( V_21 ) ) {
return ( V_21 ) ;
}
V_3 -> V_46 &= ~ V_47 ;
V_3 -> V_46 |= V_48 ;
V_21 = F_25 ( V_3 ) ;
#ifdef F_15
( void ) F_26 ( V_5 ) ;
V_49 = FALSE ;
F_16 ( NULL , V_5 , 0 ) ;
V_49 = TRUE ;
#endif
F_27 ( V_5 ) ;
F_28 ( V_38 ) ;
F_29 ( V_20 -> V_38 . V_45 ) ;
F_30 ( & V_20 -> V_38 . V_45 ) ;
return ( V_50 ) ;
}
static T_2
F_31 ( T_3 V_51 ,
T_1 V_52 , void * V_53 , void * * V_54 )
{
struct V_22 * V_23 =
(struct V_22 * ) V_51 ;
struct V_55 * V_56 =
(struct V_55 * ) V_53 ;
struct V_57 V_58 ;
T_2 V_21 ;
char * V_59 ;
T_1 V_60 ;
struct V_61 * V_62 ;
struct V_63 V_64 ;
union V_65 V_66 [ V_67 ] ;
const union V_68 * V_69 ;
V_69 = F_32 ( V_23 -> V_37 . V_70 ) ;
if ( ! V_69 ) {
return ( V_50 ) ;
}
if ( V_23 -> type == V_71 ) {
return ( V_50 ) ;
}
V_59 = F_33 ( V_23 ) ;
if ( ! V_59 ) {
return ( V_50 ) ;
}
V_21 = F_34 ( V_51 , & V_62 ) ;
if ( F_11 ( V_21 ) ) {
F_35 ( V_59 ) ;
return ( V_21 ) ;
}
V_64 . V_72 = NULL ;
V_64 . V_73 = 0 ;
if ( V_62 -> type == V_40 ) {
for ( V_60 = 0 ; V_60 < V_62 -> V_74 ; V_60 ++ ) {
V_66 [ V_60 ] . type = V_24 ;
V_66 [ V_60 ] . integer . V_18 = 1 ;
}
V_64 . V_72 = V_66 ;
V_64 . V_73 = V_62 -> V_74 ;
}
F_35 ( V_62 ) ;
V_58 . V_72 = NULL ;
V_58 . V_75 = V_76 ;
V_77 = TRUE ;
V_21 = F_36 ( V_23 , NULL , & V_64 , & V_58 ) ;
F_2 ( L_12 , V_59 ,
F_37 ( V_21 ) ) ;
V_77 = FALSE ;
F_35 ( V_59 ) ;
V_21 = V_50 ;
V_56 -> V_73 ++ ;
if ( V_56 -> V_73 >= V_56 -> V_78 ) {
V_21 = V_79 ;
}
return ( V_21 ) ;
}
void F_38 ( void )
{
struct V_55 V_56 ;
V_56 . V_73 = 0 ;
V_56 . V_78 = V_80 ;
( void ) F_39 ( V_81 , V_82 ,
V_80 , F_31 ,
NULL , ( void * ) & V_56 , NULL ) ;
F_2 ( L_13 ,
V_56 . V_73 ) ;
}
