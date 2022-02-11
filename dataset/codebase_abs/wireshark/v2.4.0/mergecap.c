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
F_6 ( const char * V_12 , T_2 V_3 )
{
fprintf ( V_4 , L_15 ) ;
vfprintf ( V_4 , V_12 , V_3 ) ;
fprintf ( V_4 , L_1 ) ;
}
static void
F_7 ( void ) {
int V_13 ;
struct V_7 * V_14 ;
T_7 * V_15 = NULL ;
V_14 = F_8 ( struct V_7 , V_16 ) ;
fprintf ( V_4 , L_17 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( F_9 ( V_13 ) ) {
V_14 [ V_13 ] . V_8 = F_10 ( V_13 ) ;
V_14 [ V_13 ] . V_11 = F_11 ( V_13 ) ;
V_15 = F_12 ( V_15 , & V_14 [ V_13 ] , F_4 ) ;
}
}
F_13 ( V_15 , F_5 , NULL ) ;
F_14 ( V_15 ) ;
F_15 ( V_14 ) ;
}
static void
F_16 ( void ) {
int V_13 ;
fprintf ( V_4 , L_18 ) ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
fprintf ( V_4 , L_19 , F_17 ( V_13 ) ) ;
}
}
static T_8
F_18 ( T_9 V_18 , int V_19 ,
const T_10 V_20 [] , const T_11 V_21 ,
void * V_9 V_10 )
{
T_11 V_13 ;
switch ( V_18 ) {
case V_22 :
for ( V_13 = 0 ; V_13 < V_21 ; V_13 ++ ) {
fprintf ( V_4 , L_20 , V_20 [ V_13 ] . V_23 ,
F_11 ( F_19 ( V_20 [ V_13 ] . V_24 ) ) ) ;
}
break;
case V_25 :
if ( V_19 == V_26 ) {
int V_27 , V_28 ;
V_27 = F_20 ( V_20 [ 0 ] . V_24 ) ;
for ( V_13 = 1 ; V_13 < V_21 ; V_13 ++ ) {
V_28 = F_20 ( V_20 [ V_13 ] . V_24 ) ;
if ( V_27 != V_28 ) {
fprintf ( V_4 , L_21 ) ;
fprintf ( V_4 , L_22 ) ;
fprintf ( V_4 , L_23 ,
V_20 [ 0 ] . V_23 ,
F_21 ( V_27 ) ,
F_22 ( V_27 ) ) ;
fprintf ( V_4 , L_23 ,
V_20 [ V_13 ] . V_23 ,
F_21 ( V_28 ) ,
F_22 ( V_28 ) ) ;
break;
}
}
}
fprintf ( V_4 , L_24 ,
F_21 ( V_19 ) ,
F_22 ( V_19 ) ) ;
break;
case V_29 :
fprintf ( V_4 , L_25 ) ;
break;
case V_30 :
fprintf ( V_4 , L_26 , V_19 ) ;
break;
case V_31 :
fprintf ( V_4 , L_27 ) ;
break;
}
return FALSE ;
}
int
main ( int V_32 , char * V_33 [] )
{
T_12 * V_34 ;
T_12 * V_35 ;
char * V_36 ;
int V_37 ;
static const struct V_38 V_39 [] = {
{ L_28 , V_40 , NULL , 'h' } ,
{ L_29 , V_40 , NULL , 'V' } ,
{ 0 , 0 , 0 , 0 }
} ;
T_8 V_41 = FALSE ;
T_8 V_42 = FALSE ;
int V_21 = 0 ;
T_13 V_43 = 0 ;
#ifdef F_23
int V_44 = V_45 ;
#else
int V_44 = V_46 ;
#endif
int V_47 = 0 ;
T_14 * V_48 = NULL ;
int V_49 ;
T_13 V_50 ;
char * V_51 = NULL ;
T_15 V_52 = V_53 ;
T_16 V_54 = V_17 ;
T_17 V_55 ;
F_24 ( F_2 , F_3 ) ;
#ifdef F_25
F_26 ( V_32 , V_33 ) ;
F_27 () ;
#endif
V_34 = F_28 ( NULL , NULL ) ;
V_35 = F_29 ( NULL ) ;
F_30 ( L_30
L_1
L_31
L_1
L_31 ,
F_31 () , V_34 -> V_56 , V_35 -> V_56 ) ;
F_32 ( V_34 , TRUE ) ;
F_32 ( V_35 , TRUE ) ;
F_33 () ;
V_36 = F_34 ( V_33 [ 0 ] , main ) ;
if ( V_36 != NULL ) {
fprintf ( V_4 ,
L_32 ,
V_36 ) ;
F_15 ( V_36 ) ;
}
F_35 () ;
#ifdef F_36
F_37 ( F_6 , F_6 ,
NULL , NULL , NULL ) ;
F_38 ( V_57 ) ;
F_39 () ;
#endif
while ( ( V_37 = F_40 ( V_32 , V_33 , L_33 , V_39 , NULL ) ) != - 1 ) {
switch ( V_37 ) {
case 'a' :
V_41 = ! V_41 ;
break;
case 'F' :
V_44 = F_41 ( V_58 ) ;
if ( V_44 < 0 ) {
fprintf ( V_4 , L_34 ,
V_58 ) ;
F_7 () ;
V_52 = V_59 ;
goto V_60;
}
break;
case 'h' :
printf ( L_30
L_35
L_36 ,
F_31 () ) ;
F_1 ( stdout ) ;
goto V_60;
break;
case 'I' :
V_54 = F_42 ( V_58 ) ;
if ( V_54 == V_17 ) {
fprintf ( V_4 , L_37 ,
V_58 ) ;
F_16 () ;
V_52 = V_59 ;
goto V_60;
}
break;
case 's' :
V_43 = F_43 ( V_58 , L_38 ) ;
break;
case 'v' :
V_42 = TRUE ;
break;
case 'V' :
V_34 = F_28 ( NULL , NULL ) ;
V_35 = F_29 ( NULL ) ;
F_44 ( L_39 , V_34 , V_35 ) ;
F_32 ( V_34 , TRUE ) ;
F_32 ( V_35 , TRUE ) ;
goto V_60;
break;
case 'w' :
V_51 = V_58 ;
break;
case '?' :
switch( V_61 ) {
case 'F' :
F_7 () ;
break;
case 'I' :
F_16 () ;
break;
default:
F_1 ( V_4 ) ;
}
V_52 = V_59 ;
goto V_60;
break;
}
}
V_55 . V_62 = F_18 ;
V_55 . V_9 = NULL ;
V_21 = V_32 - V_63 ;
if ( ! V_51 ) {
fprintf ( V_4 , L_40 ) ;
fprintf ( V_4 , L_41 ) ;
V_52 = V_59 ;
goto V_60;
}
if ( V_21 < 1 ) {
fprintf ( V_4 , L_42 ) ;
return 1 ;
}
if ( V_54 != V_17 && V_44 != V_45 ) {
fprintf ( V_4 , L_43 ) ;
V_52 = V_59 ;
goto V_60;
}
if ( V_54 == V_17 ) {
V_54 = V_64 ;
}
if ( strcmp ( V_51 , L_44 ) == 0 ) {
V_52 = F_45 ( V_44 ,
( const char * const * ) & V_33 [ V_63 ] ,
V_21 , V_41 , V_54 , V_43 ,
L_45 , V_42 ? & V_55 : NULL ,
& V_47 , & V_48 , & V_49 , & V_50 ) ;
} else {
V_52 = F_46 ( V_51 , V_44 ,
( const char * const * ) & V_33 [ V_63 ] , V_21 ,
V_41 , V_54 , V_43 , L_45 , V_42 ? & V_55 : NULL ,
& V_47 , & V_48 , & V_49 , & V_50 ) ;
}
switch ( V_52 ) {
case V_53 :
break;
case V_65 :
F_47 ( FALSE ) ;
break;
case V_66 :
F_48 ( L_45 , V_33 [ V_63 + V_49 ] ,
V_47 , V_48 ) ;
break;
case V_67 :
F_49 ( L_45 , V_51 , V_47 , V_44 ) ;
break;
case V_68 :
F_50 ( L_45 , V_33 [ V_63 + V_49 ] ,
V_47 , V_48 ) ;
break;
case V_69 :
F_51 ( L_46 ,
V_50 , V_33 [ V_63 + V_49 ] ) ;
break;
case V_70 :
F_52 ( L_45 , V_33 [ V_63 + V_49 ] ,
V_51 , V_47 , V_48 , V_50 ,
V_44 ) ;
break;
case V_71 :
F_53 ( V_51 , V_47 ) ;
break;
default:
F_51 ( L_47 , V_52 ) ;
break;
}
V_60:
F_54 () ;
F_55 () ;
#ifdef F_36
F_56 () ;
#endif
return ( V_52 == V_53 ) ? 0 : 2 ;
}
