static void
F_1 ( T_1 * V_1 )
{
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_2 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_3 ) ;
fprintf ( V_1 , L_4 ) ;
fprintf ( V_1 , L_5 ) ;
fprintf ( V_1 , L_6 ) ;
fprintf ( V_1 , L_7 ) ;
fprintf ( V_1 , L_8 ) ;
fprintf ( V_1 , L_9 ) ;
fprintf ( V_1 , L_10 ) ;
fprintf ( V_1 , L_11 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_12 ) ;
fprintf ( V_1 , L_13 ) ;
fprintf ( V_1 , L_14 ) ;
}
static void
F_2 ( const char * V_2 , T_2 V_3 )
{
fprintf ( V_4 , L_15 ) ;
vfprintf ( V_4 , V_2 , V_3 ) ;
fprintf ( V_4 , L_1 ) ;
}
static void
F_3 ( const char * V_2 , T_2 V_3 )
{
vfprintf ( V_4 , V_2 , V_3 ) ;
fprintf ( V_4 , L_1 ) ;
}
static T_3
F_4 ( T_4 V_5 , T_4 V_6 )
{
return strcmp ( ( ( const struct V_7 * ) V_5 ) -> V_8 ,
( ( const struct V_7 * ) V_6 ) -> V_8 ) ;
}
static void
F_5 ( T_5 V_9 , T_5 T_6 V_10 )
{
fprintf ( V_4 , L_16 , ( (struct V_7 * ) V_9 ) -> V_8 ,
( (struct V_7 * ) V_9 ) -> V_11 ) ;
}
static void
F_6 ( const char * T_7 V_10 , T_2 V_3 V_10 )
{
return;
}
static void
F_7 ( void ) {
int V_12 ;
struct V_7 * V_13 ;
T_8 * V_14 = NULL ;
V_13 = F_8 ( struct V_7 , V_15 ) ;
fprintf ( V_4 , L_17 ) ;
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ ) {
if ( F_9 ( V_12 ) ) {
V_13 [ V_12 ] . V_8 = F_10 ( V_12 ) ;
V_13 [ V_12 ] . V_11 = F_11 ( V_12 ) ;
V_14 = F_12 ( V_14 , & V_13 [ V_12 ] , F_4 ) ;
}
}
F_13 ( V_14 , F_5 , NULL ) ;
F_14 ( V_14 ) ;
F_15 ( V_13 ) ;
}
static void
F_16 ( void ) {
int V_12 ;
fprintf ( V_4 , L_18 ) ;
for ( V_12 = 0 ; V_12 < V_16 ; V_12 ++ ) {
fprintf ( V_4 , L_19 , F_17 ( V_12 ) ) ;
}
}
static T_9
F_18 ( T_10 V_17 , int V_18 ,
const T_11 V_19 [] , const T_12 V_20 ,
void * V_9 V_10 )
{
T_12 V_12 ;
switch ( V_17 ) {
case V_21 :
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ ) {
fprintf ( V_4 , L_20 , V_19 [ V_12 ] . V_22 ,
F_11 ( F_19 ( V_19 [ V_12 ] . V_23 ) ) ) ;
}
break;
case V_24 :
if ( V_18 == V_25 ) {
int V_26 , V_27 ;
V_26 = F_20 ( V_19 [ 0 ] . V_23 ) ;
for ( V_12 = 1 ; V_12 < V_20 ; V_12 ++ ) {
V_27 = F_20 ( V_19 [ V_12 ] . V_23 ) ;
if ( V_26 != V_27 ) {
fprintf ( V_4 , L_21 ) ;
fprintf ( V_4 , L_22 ) ;
fprintf ( V_4 , L_23 ,
V_19 [ 0 ] . V_22 ,
F_21 ( V_26 ) ,
F_22 ( V_26 ) ) ;
fprintf ( V_4 , L_23 ,
V_19 [ V_12 ] . V_22 ,
F_21 ( V_27 ) ,
F_22 ( V_27 ) ) ;
break;
}
}
}
fprintf ( V_4 , L_24 ,
F_21 ( V_18 ) ,
F_22 ( V_18 ) ) ;
break;
case V_28 :
fprintf ( V_4 , L_25 ) ;
break;
case V_29 :
fprintf ( V_4 , L_26 , V_18 ) ;
break;
case V_30 :
fprintf ( V_4 , L_27 ) ;
break;
}
return FALSE ;
}
int
main ( int V_31 , char * V_32 [] )
{
T_13 * V_33 ;
T_13 * V_34 ;
int V_35 ;
static const struct V_36 V_37 [] = {
{ L_28 , V_38 , NULL , 'h' } ,
{ L_29 , V_38 , NULL , 'V' } ,
{ 0 , 0 , 0 , 0 }
} ;
T_9 V_39 = FALSE ;
T_9 V_40 = FALSE ;
int V_20 = 0 ;
T_12 V_41 = 0 ;
#ifdef F_23
int V_42 = V_43 ;
#else
int V_42 = V_44 ;
#endif
int V_45 ;
int V_46 = 0 ;
T_14 * V_47 = NULL ;
int V_48 ;
char * V_49 = NULL ;
T_15 V_50 ;
T_16 V_51 = V_16 ;
T_9 V_52 = FALSE ;
T_17 V_53 ;
#ifdef F_24
char * V_54 ;
#endif
F_25 ( F_2 , F_3 ) ;
#ifdef F_26
F_27 ( V_31 , V_32 ) ;
F_28 () ;
#endif
V_33 = F_29 ( NULL , NULL ) ;
V_34 = F_30 ( NULL ) ;
F_31 ( L_30
L_1
L_31
L_1
L_31 ,
F_32 () , V_33 -> V_55 , V_34 -> V_55 ) ;
F_33 () ;
F_34 () ;
#ifdef F_24
if ( ( V_54 = F_35 ( V_32 [ 0 ] , main ) ) ) {
F_36 ( L_32 , V_54 ) ;
F_15 ( V_54 ) ;
} else {
F_37 () ;
F_38 ( F_6 , NULL , NULL , NULL ) ;
F_39 () ;
F_40 () ;
}
#endif
while ( ( V_35 = F_41 ( V_31 , V_32 , L_33 , V_37 , NULL ) ) != - 1 ) {
switch ( V_35 ) {
case 'a' :
V_39 = ! V_39 ;
break;
case 'F' :
V_42 = F_42 ( V_56 ) ;
if ( V_42 < 0 ) {
fprintf ( V_4 , L_34 ,
V_56 ) ;
F_7 () ;
exit ( 1 ) ;
}
break;
case 'h' :
printf ( L_30
L_35
L_36 ,
F_32 () ) ;
F_1 ( stdout ) ;
exit ( 0 ) ;
break;
case 'I' :
V_51 = F_43 ( V_56 ) ;
if ( V_51 == V_16 ) {
fprintf ( V_4 , L_37 ,
V_56 ) ;
F_16 () ;
exit ( 1 ) ;
}
break;
case 's' :
V_41 = F_44 ( V_56 , L_38 ) ;
break;
case 'v' :
V_40 = TRUE ;
break;
case 'V' :
F_45 ( L_39 , V_33 , V_34 ) ;
F_46 ( V_33 , TRUE ) ;
F_46 ( V_34 , TRUE ) ;
exit ( 0 ) ;
break;
case 'w' :
V_49 = V_56 ;
break;
case '?' :
switch( V_57 ) {
case 'F' :
F_7 () ;
break;
case 'I' :
F_16 () ;
break;
default:
F_1 ( V_4 ) ;
}
exit ( 1 ) ;
break;
}
}
V_53 . V_58 = F_18 ;
V_53 . V_9 = NULL ;
V_20 = V_31 - V_59 ;
if ( ! V_49 ) {
fprintf ( V_4 , L_40 ) ;
fprintf ( V_4 , L_41 ) ;
return 1 ;
}
if ( V_20 < 1 ) {
fprintf ( V_4 , L_42 ) ;
return 1 ;
}
if ( V_51 != V_16 && V_42 != V_43 ) {
fprintf ( V_4 , L_43 ) ;
return 1 ;
}
if ( V_51 == V_16 ) {
V_51 = V_60 ;
}
if ( strcmp ( V_49 , L_44 ) == 0 ) {
V_52 = TRUE ;
V_45 = 1 ;
} else {
V_45 = F_47 ( V_49 , V_61 | V_62 | V_63 | V_64 , 0644 ) ;
if ( V_45 == - 1 ) {
fprintf ( V_4 , L_45 ,
V_49 , F_48 ( V_65 ) ) ;
exit ( 1 ) ;
}
}
V_50 = F_49 ( V_45 , V_49 , V_42 ,
( const char * const * ) & V_32 [ V_59 ] , V_20 ,
V_39 , V_51 , V_41 , L_46 , V_40 ? & V_53 : NULL ,
& V_46 , & V_47 , & V_48 ) ;
switch ( V_50 ) {
case V_66 :
break;
case V_67 :
F_50 ( FALSE ) ;
break;
case V_68 :
fprintf ( V_4 , L_47 , V_32 [ V_59 + V_48 ] ,
F_51 ( V_46 ) , V_47 ? V_47 : L_48 ) ;
break;
case V_69 :
fprintf ( V_4 , L_49 , V_49 ,
F_51 ( V_46 ) ) ;
if ( ! V_52 )
F_52 ( V_45 ) ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
default:
fprintf ( V_4 , L_50 , V_47 ? V_47 : L_51 ) ;
break;
}
F_15 ( V_47 ) ;
return ( V_50 == V_66 ) ? 0 : 2 ;
}
