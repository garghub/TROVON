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
F_6 ( void ) {
int V_12 ;
struct V_7 * V_13 ;
T_7 * V_14 = NULL ;
V_13 = F_7 ( struct V_7 , V_15 ) ;
fprintf ( V_4 , L_17 ) ;
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ ) {
if ( F_8 ( V_12 ) ) {
V_13 [ V_12 ] . V_8 = F_9 ( V_12 ) ;
V_13 [ V_12 ] . V_11 = F_10 ( V_12 ) ;
V_14 = F_11 ( V_14 , & V_13 [ V_12 ] , F_4 ) ;
}
}
F_12 ( V_14 , F_5 , NULL ) ;
F_13 ( V_14 ) ;
F_14 ( V_13 ) ;
}
static void
F_15 ( void ) {
int V_12 ;
fprintf ( V_4 , L_18 ) ;
for ( V_12 = 0 ; V_12 < V_16 ; V_12 ++ ) {
fprintf ( V_4 , L_19 , F_16 ( V_12 ) ) ;
}
}
static void
F_17 ( T_8 * V_17 )
{
F_18 ( V_17 , L_20 ) ;
#ifdef F_19
F_18 ( V_17 , L_21 ) ;
#ifdef F_20
F_18 ( V_17 , F_20 ) ;
#else
F_18 ( V_17 , L_22 ) ;
#endif
#else
F_18 ( V_17 , L_23 ) ;
#endif
}
static void
F_21 ( T_8 * V_17 )
{
#if F_22 ( F_19 ) && ! F_22 ( V_18 )
F_23 ( V_17 , L_24 , F_24 () ) ;
#endif
}
static T_9
F_25 ( T_10 V_19 , int V_20 ,
const T_11 V_21 [] , const T_12 V_22 ,
void * V_9 V_10 )
{
T_12 V_12 ;
switch ( V_19 ) {
case V_23 :
for ( V_12 = 0 ; V_12 < V_22 ; V_12 ++ ) {
fprintf ( V_4 , L_25 , V_21 [ V_12 ] . V_24 ,
F_10 ( F_26 ( V_21 [ V_12 ] . V_25 ) ) ) ;
}
break;
case V_26 :
if ( V_20 == V_27 ) {
int V_28 , V_29 ;
V_28 = F_27 ( V_21 [ 0 ] . V_25 ) ;
for ( V_12 = 1 ; V_12 < V_22 ; V_12 ++ ) {
V_29 = F_27 ( V_21 [ V_12 ] . V_25 ) ;
if ( V_28 != V_29 ) {
fprintf ( V_4 , L_26 ) ;
fprintf ( V_4 , L_27 ) ;
fprintf ( V_4 , L_28 ,
V_21 [ 0 ] . V_24 ,
F_28 ( V_28 ) ,
F_29 ( V_28 ) ) ;
fprintf ( V_4 , L_28 ,
V_21 [ V_12 ] . V_24 ,
F_28 ( V_29 ) ,
F_29 ( V_29 ) ) ;
break;
}
}
}
fprintf ( V_4 , L_29 ,
F_28 ( V_20 ) ,
F_29 ( V_20 ) ) ;
break;
case V_30 :
fprintf ( V_4 , L_30 ) ;
break;
case V_31 :
fprintf ( V_4 , L_31 , V_20 ) ;
break;
case V_32 :
fprintf ( V_4 , L_32 ) ;
break;
}
return FALSE ;
}
int
main ( int V_33 , char * V_34 [] )
{
T_8 * V_35 ;
T_8 * V_36 ;
int V_37 ;
F_30 (cast-qual)
static const struct V_38 V_39 [] = {
{ ( char * ) L_33 , V_40 , NULL , 'h' } ,
{ ( char * ) L_34 , V_40 , NULL , 'V' } ,
{ 0 , 0 , 0 , 0 }
} ;
F_31 (cast-qual)
T_9 V_41 = FALSE ;
T_9 V_42 = FALSE ;
int V_22 = 0 ;
T_12 V_43 = 0 ;
#ifdef F_32
int V_44 = V_45 ;
#else
int V_44 = V_46 ;
#endif
int V_47 ;
int V_48 = 0 ;
T_13 * V_49 = NULL ;
int V_50 ;
char * V_51 = NULL ;
T_14 V_52 ;
T_15 V_53 = V_16 ;
T_9 V_54 = FALSE ;
T_16 V_55 ;
F_33 ( F_2 , F_3 ) ;
#ifdef V_18
F_34 ( V_33 , V_34 ) ;
F_35 () ;
#endif
V_35 = F_36 ( NULL , F_17 ) ;
V_36 = F_37 ( F_21 ) ;
F_38 ( L_35
L_1
L_36
L_1
L_36 ,
F_39 () , V_35 -> V_17 , V_36 -> V_17 ) ;
while ( ( V_37 = F_40 ( V_33 , V_34 , L_37 , V_39 , NULL ) ) != - 1 ) {
switch ( V_37 ) {
case 'a' :
V_41 = ! V_41 ;
break;
case 'F' :
V_44 = F_41 ( V_56 ) ;
if ( V_44 < 0 ) {
fprintf ( V_4 , L_38 ,
V_56 ) ;
F_6 () ;
exit ( 1 ) ;
}
break;
case 'h' :
printf ( L_35
L_39
L_40 ,
F_39 () ) ;
F_1 ( stdout ) ;
exit ( 0 ) ;
break;
case 'I' :
V_53 = F_42 ( V_56 ) ;
if ( V_53 == V_16 ) {
fprintf ( V_4 , L_41 ,
V_56 ) ;
F_15 () ;
exit ( 1 ) ;
}
break;
case 's' :
V_43 = F_43 ( V_56 , L_42 ) ;
break;
case 'v' :
V_42 = TRUE ;
break;
case 'V' :
F_44 ( L_43 , V_35 , V_36 ) ;
F_45 ( V_35 , TRUE ) ;
F_45 ( V_36 , TRUE ) ;
exit ( 0 ) ;
break;
case 'w' :
V_51 = V_56 ;
break;
case '?' :
switch( V_57 ) {
case 'F' :
F_6 () ;
break;
case 'I' :
F_15 () ;
break;
default:
F_1 ( V_4 ) ;
}
exit ( 1 ) ;
break;
}
}
V_55 . V_58 = F_25 ;
V_55 . V_9 = NULL ;
V_22 = V_33 - V_59 ;
if ( ! V_51 ) {
fprintf ( V_4 , L_44 ) ;
fprintf ( V_4 , L_45 ) ;
return 1 ;
}
if ( V_22 < 1 ) {
fprintf ( V_4 , L_46 ) ;
return 1 ;
}
if ( V_53 != V_16 && V_44 != V_45 ) {
fprintf ( V_4 , L_47 ) ;
return 1 ;
}
if ( V_53 == V_16 ) {
V_53 = V_60 ;
}
if ( strncmp ( V_51 , L_48 , 2 ) == 0 ) {
V_54 = TRUE ;
V_47 = 1 ;
} else {
V_47 = F_46 ( V_51 , V_61 | V_62 | V_63 | V_64 , 0644 ) ;
if ( V_47 == - 1 ) {
fprintf ( V_4 , L_49 ,
V_51 , F_47 ( V_65 ) ) ;
exit ( 1 ) ;
}
}
V_52 = F_48 ( V_47 , V_51 , V_44 ,
( const char * const * ) & V_34 [ V_59 ] , V_22 ,
V_41 , V_53 , V_43 , L_50 , V_42 ? & V_55 : NULL ,
& V_48 , & V_49 , & V_50 ) ;
switch ( V_52 ) {
case V_66 :
break;
case V_67 :
F_49 ( FALSE ) ;
break;
case V_68 :
fprintf ( V_4 , L_51 , V_34 [ V_59 + V_50 ] ,
F_50 ( V_48 ) , V_49 ? V_49 : L_52 ) ;
break;
case V_69 :
fprintf ( V_4 , L_53 , V_51 ,
F_50 ( V_48 ) ) ;
if ( ! V_54 )
F_51 ( V_47 ) ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
default:
fprintf ( V_4 , L_54 , V_49 ? V_49 : L_55 ) ;
break;
}
F_14 ( V_49 ) ;
return ( V_52 == V_66 ) ? 0 : 2 ;
}
