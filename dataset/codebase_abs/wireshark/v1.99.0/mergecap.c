static void
F_1 ( T_1 * V_1 , T_1 * V_2 )
{
printf ( L_1
L_2
L_3
L_2
L_3
L_2
L_3 ,
F_2 () , F_3 () ,
V_1 -> V_3 , V_2 -> V_3 ) ;
}
static void
F_4 ( T_2 * V_4 )
{
fprintf ( V_4 , L_2 ) ;
fprintf ( V_4 , L_4 ) ;
fprintf ( V_4 , L_2 ) ;
fprintf ( V_4 , L_5 ) ;
fprintf ( V_4 , L_6 ) ;
fprintf ( V_4 , L_7 ) ;
fprintf ( V_4 , L_8 ) ;
fprintf ( V_4 , L_9 ) ;
fprintf ( V_4 , L_10 ) ;
fprintf ( V_4 , L_11 ) ;
fprintf ( V_4 , L_12 ) ;
fprintf ( V_4 , L_13 ) ;
fprintf ( V_4 , L_14 ) ;
fprintf ( V_4 , L_2 ) ;
fprintf ( V_4 , L_15 ) ;
fprintf ( V_4 , L_16 ) ;
fprintf ( V_4 , L_17 ) ;
}
static void
F_5 ( const char * V_5 , T_3 V_6 )
{
fprintf ( V_7 , L_18 ) ;
vfprintf ( V_7 , V_5 , V_6 ) ;
fprintf ( V_7 , L_2 ) ;
}
static void
F_6 ( const char * V_5 , T_3 V_6 )
{
vfprintf ( V_7 , V_5 , V_6 ) ;
fprintf ( V_7 , L_2 ) ;
}
static T_4
F_7 ( T_5 V_8 , T_5 V_9 )
{
return strcmp ( ( ( const struct V_10 * ) V_8 ) -> V_11 ,
( ( const struct V_10 * ) V_9 ) -> V_11 ) ;
}
static T_4
F_8 ( T_5 V_8 , T_5 V_9 )
{
return F_9 ( ( ( const struct V_10 * ) V_8 ) -> V_11 ,
( ( const struct V_10 * ) V_9 ) -> V_11 ) ;
}
static void
F_10 ( T_6 V_12 , T_6 T_7 V_13 )
{
fprintf ( V_7 , L_19 , ( (struct V_10 * ) V_12 ) -> V_11 ,
( (struct V_10 * ) V_12 ) -> V_14 ) ;
}
static void
F_11 ( void ) {
int V_15 ;
struct V_10 * V_16 ;
T_8 * V_17 = NULL ;
V_16 = F_12 ( struct V_10 , V_18 ) ;
fprintf ( V_7 , L_20 ) ;
for ( V_15 = 0 ; V_15 < V_18 ; V_15 ++ ) {
if ( F_13 ( V_15 ) ) {
V_16 [ V_15 ] . V_11 = F_14 ( V_15 ) ;
V_16 [ V_15 ] . V_14 = F_15 ( V_15 ) ;
V_17 = F_16 ( V_17 , & V_16 [ V_15 ] , F_7 ) ;
}
}
F_17 ( V_17 , F_10 , NULL ) ;
F_18 ( V_17 ) ;
F_19 ( V_16 ) ;
}
static void
F_20 ( void ) {
int V_15 ;
struct V_10 * V_19 ;
T_8 * V_17 = NULL ;
V_19 = F_12 ( struct V_10 , V_20 ) ;
fprintf ( V_7 , L_21 ) ;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
V_19 [ V_15 ] . V_11 = F_21 ( V_15 ) ;
if ( V_19 [ V_15 ] . V_11 != NULL ) {
V_19 [ V_15 ] . V_14 = F_22 ( V_15 ) ;
V_17 = F_16 ( V_17 , & V_19 [ V_15 ] , F_8 ) ;
}
}
F_17 ( V_17 , F_10 , NULL ) ;
F_18 ( V_17 ) ;
F_19 ( V_19 ) ;
}
static void
F_23 ( T_1 * V_3 )
{
F_24 ( V_3 , L_22 ) ;
#ifdef F_25
F_24 ( V_3 , L_23 ) ;
#ifdef F_26
F_24 ( V_3 , F_26 ) ;
#else
F_24 ( V_3 , L_24 ) ;
#endif
#else
F_24 ( V_3 , L_25 ) ;
#endif
}
static void
F_27 ( T_1 * V_3 )
{
#if F_28 ( F_25 ) && ! F_28 ( V_21 )
F_29 ( V_3 , L_26 , F_30 () ) ;
#endif
}
int
main ( int V_22 , char * V_23 [] )
{
T_1 * V_1 ;
T_1 * V_2 ;
int V_24 ;
static const struct V_25 V_26 [] = {
{ ( char * ) L_27 , V_27 , NULL , 'h' } ,
{ ( char * ) L_28 , V_27 , NULL , 'V' } ,
{ 0 , 0 , 0 , 0 }
} ;
T_9 V_28 = FALSE ;
T_9 V_29 = FALSE ;
int V_30 = 0 ;
T_10 V_31 = 0 ;
#ifdef F_31
int V_32 = V_33 ;
#else
int V_32 = V_34 ;
#endif
int V_35 = - 2 ;
int V_36 ;
T_11 * V_37 = NULL , * V_38 ;
int V_15 ;
struct V_39 * V_40 , V_41 ;
T_12 * V_42 ;
int V_43 , V_44 = 0 , V_45 , V_46 ;
T_13 * V_47 ;
int V_48 ;
char * V_49 = NULL ;
T_9 V_50 = FALSE , V_51 = FALSE ;
int V_52 ;
F_32 ( F_5 , F_6 ) ;
#ifdef V_21
F_33 ( V_22 , V_23 ) ;
F_34 () ;
#endif
V_1 = F_35 ( L_29 ) ;
F_36 ( V_1 , NULL , F_23 ) ;
V_2 = F_35 ( L_30 ) ;
F_37 ( V_2 , F_27 ) ;
F_38 ( L_1
L_2
L_3
L_2
L_3 ,
F_2 () , V_1 -> V_3 , V_2 -> V_3 ) ;
while ( ( V_24 = F_39 ( V_22 , V_23 , L_31 , V_26 , NULL ) ) != - 1 ) {
switch ( V_24 ) {
case 'a' :
V_28 = ! V_28 ;
break;
case 'F' :
V_32 = F_40 ( V_53 ) ;
if ( V_32 < 0 ) {
fprintf ( V_7 , L_32 ,
V_53 ) ;
F_11 () ;
exit ( 1 ) ;
}
break;
case 'h' :
printf ( L_1
L_33
L_34 ,
F_2 () ) ;
F_4 ( stdout ) ;
exit ( 0 ) ;
break;
case 's' :
V_31 = F_41 ( V_53 , L_35 ) ;
break;
case 'T' :
V_35 = F_42 ( V_53 ) ;
if ( V_35 < 0 ) {
fprintf ( V_7 , L_36 ,
V_53 ) ;
F_20 () ;
exit ( 1 ) ;
}
break;
case 'v' :
V_29 = TRUE ;
break;
case 'V' :
F_1 ( V_1 , V_2 ) ;
F_43 ( V_1 , TRUE ) ;
F_43 ( V_2 , TRUE ) ;
exit ( 0 ) ;
break;
case 'w' :
V_49 = V_53 ;
break;
case '?' :
switch( V_54 ) {
case 'F' :
F_11 () ;
break;
case 'T' :
F_20 () ;
break;
default:
F_4 ( V_7 ) ;
}
exit ( 1 ) ;
break;
}
}
V_30 = V_22 - V_55 ;
if ( ! V_49 ) {
fprintf ( V_7 , L_37 ) ;
fprintf ( V_7 , L_38 ) ;
return 1 ;
}
if ( V_30 < 1 ) {
fprintf ( V_7 , L_39 ) ;
return 1 ;
}
if ( ! F_44 ( V_30 , & V_23 [ V_55 ] , & V_37 ,
& V_43 , & V_47 , & V_48 ) ) {
fprintf ( V_7 , L_40 , V_23 [ V_55 + V_48 ] ,
F_45 ( V_43 ) ) ;
switch ( V_43 ) {
case V_56 :
case V_57 :
case V_58 :
fprintf ( V_7 , L_41 , V_47 ) ;
F_19 ( V_47 ) ;
break;
}
return 2 ;
}
if ( V_29 ) {
for ( V_15 = 0 ; V_15 < V_30 ; V_15 ++ )
fprintf ( V_7 , L_42 , V_23 [ V_55 + V_15 ] ,
F_15 ( F_46 ( V_37 [ V_15 ] . V_59 ) ) ) ;
}
if ( V_31 == 0 ) {
V_31 = F_47 ( V_30 , V_37 ) ;
}
if ( V_35 == - 2 ) {
V_35 = F_48 ( V_30 , V_37 ) ;
if ( V_29 ) {
if ( V_35 == V_60 ) {
int V_61 , V_62 ;
V_61 = F_49 ( V_37 [ 0 ] . V_59 ) ;
for ( V_15 = 1 ; V_15 < V_30 ; V_15 ++ ) {
V_62 = F_49 ( V_37 [ V_15 ] . V_59 ) ;
if ( V_61 != V_62 ) {
fprintf ( V_7 , L_43 ) ;
fprintf ( V_7 , L_44 ) ;
fprintf ( V_7 , L_45 ,
V_37 [ 0 ] . V_63 ,
F_22 ( V_61 ) ,
F_21 ( V_61 ) ) ;
fprintf ( V_7 , L_45 ,
V_37 [ V_15 ] . V_63 ,
F_22 ( V_62 ) ,
F_21 ( V_62 ) ) ;
break;
}
}
}
fprintf ( V_7 , L_46 ,
F_22 ( V_35 ) ,
F_21 ( V_35 ) ) ;
}
}
if ( strncmp ( V_49 , L_47 , 2 ) == 0 ) {
V_36 = 1 ;
} else {
V_36 = F_50 ( V_49 , V_64 | V_65 | V_66 | V_67 , 0644 ) ;
if ( V_36 == - 1 ) {
fprintf ( V_7 , L_48 ,
V_49 , F_51 ( V_68 ) ) ;
exit ( 1 ) ;
}
}
if( V_32 == V_33 ) {
T_14 * V_69 ;
T_1 * V_70 ;
V_69 = F_12 ( T_14 , 1 ) ;
V_70 = F_35 ( L_49 ) ;
for ( V_15 = 0 ; V_15 < V_30 ; V_15 ++ ) {
F_29 ( V_70 , L_50 , V_15 + 1 , V_37 [ V_15 ] . V_63 ) ;
}
V_69 -> V_71 = - 1 ;
V_69 -> V_72 = V_70 -> V_3 ;
V_69 -> V_73 = NULL ;
V_69 -> V_74 = NULL ;
V_69 -> V_75 = F_52 ( L_51 ) ;
V_42 = F_53 ( V_36 , V_32 , V_35 , V_31 ,
FALSE , V_69 , NULL , & V_43 ) ;
F_43 ( V_70 , TRUE ) ;
} else {
V_42 = F_54 ( V_36 , V_32 , V_35 , V_31 , FALSE , & V_43 ) ;
}
if ( V_42 == NULL ) {
F_55 ( V_30 , V_37 ) ;
F_19 ( V_37 ) ;
fprintf ( V_7 , L_52 , V_49 ,
F_45 ( V_43 ) ) ;
exit ( 1 ) ;
}
V_52 = 1 ;
for (; ; ) {
if ( V_28 )
V_38 = F_56 ( V_30 , V_37 , & V_44 ,
& V_47 ) ;
else
V_38 = F_57 ( V_30 , V_37 , & V_44 ,
& V_47 ) ;
if ( V_38 == NULL ) {
break;
}
if ( V_44 != 0 ) {
V_50 = TRUE ;
break;
}
if ( V_29 )
fprintf ( V_7 , L_53 , V_52 ++ ) ;
V_40 = F_58 ( V_38 -> V_59 ) ;
if ( V_31 != 0 && V_40 -> V_76 > V_31 ) {
V_41 = * V_40 ;
V_41 . V_76 = V_31 ;
V_40 = & V_41 ;
}
if ( ! F_59 ( V_42 , V_40 , F_60 ( V_38 -> V_59 ) , & V_45 ) ) {
V_51 = TRUE ;
break;
}
}
F_55 ( V_30 , V_37 ) ;
if ( ! V_51 ) {
if ( ! F_61 ( V_42 , & V_45 ) )
V_51 = TRUE ;
} else {
( void ) F_61 ( V_42 , & V_46 ) ;
}
if ( V_50 ) {
for ( V_15 = 0 ; V_15 < V_30 ; V_15 ++ ) {
if ( V_37 [ V_15 ] . V_77 == V_78 ) {
fprintf ( V_7 , L_54 ,
V_37 [ V_15 ] . V_63 , F_45 ( V_44 ) ) ;
switch ( V_44 ) {
case V_56 :
case V_57 :
case V_58 :
fprintf ( V_7 , L_41 , V_47 ) ;
F_19 ( V_47 ) ;
break;
}
}
}
}
if ( V_51 ) {
switch ( V_45 ) {
case V_57 :
fprintf ( V_7 , L_55 ,
V_38 ? V_38 -> V_79 : 0 , V_38 ? V_38 -> V_63 : L_56 ,
F_15 ( V_32 ) ) ;
break;
case V_80 :
fprintf ( V_7 , L_57 ,
V_38 ? V_38 -> V_79 : 0 , V_38 ? V_38 -> V_63 : L_56 ,
F_15 ( V_32 ) ) ;
break;
default:
fprintf ( V_7 , L_58 ,
F_45 ( V_45 ) ) ;
break;
}
}
F_19 ( V_37 ) ;
return ( ! V_50 && ! V_51 ) ? 0 : 2 ;
}
