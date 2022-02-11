static int
F_1 ( const char * string , const char * V_1 )
{
long V_2 ;
char * V_3 ;
V_2 = strtol ( string , & V_3 , 10 ) ;
if ( V_3 == string || * V_3 != '\0' ) {
fprintf ( V_4 , L_1 ,
V_1 , string ) ;
exit ( 1 ) ;
}
if ( V_2 < 0 ) {
fprintf ( V_4 , L_2 ,
V_1 ) ;
exit ( 1 ) ;
}
if ( V_2 > V_5 ) {
fprintf ( V_4 , L_3 ,
V_1 , V_5 ) ;
exit ( 1 ) ;
}
return ( int ) V_2 ;
}
static int
F_2 ( const char * string , const char * V_1 )
{
int V_2 ;
V_2 = F_1 ( string , V_1 ) ;
if ( V_2 == 0 ) {
fprintf ( V_4 , L_4 ,
V_1 ) ;
exit ( 1 ) ;
}
return V_2 ;
}
static void
F_3 ( void )
{
fprintf ( V_4 , L_5
#ifdef F_4
L_6 F_4 L_7 V_6 L_8
#endif
L_9 , V_7 ) ;
fprintf ( V_4 , L_10 ) ;
fprintf ( V_4 , L_11 ) ;
fprintf ( V_4 , L_9 ) ;
fprintf ( V_4 , L_12 ) ;
fprintf ( V_4 , L_9 ) ;
fprintf ( V_4 , L_13 ) ;
fprintf ( V_4 , L_14 ) ;
fprintf ( V_4 , L_15 ) ;
fprintf ( V_4 , L_16 ) ;
fprintf ( V_4 , L_17 ) ;
fprintf ( V_4 , L_18 ) ;
fprintf ( V_4 , L_19 ) ;
fprintf ( V_4 , L_20 ) ;
fprintf ( V_4 , L_21 ) ;
fprintf ( V_4 , L_22 ) ;
fprintf ( V_4 , L_9 ) ;
fprintf ( V_4 , L_23 ) ;
fprintf ( V_4 , L_24 ) ;
fprintf ( V_4 , L_25 ) ;
}
static T_1
F_5 ( T_2 V_8 , T_2 V_9 )
{
return strcmp ( ( ( const struct V_10 * ) V_8 ) -> V_11 ,
( ( const struct V_10 * ) V_9 ) -> V_11 ) ;
}
static void
F_6 ( T_3 V_12 , T_3 T_4 V_13 )
{
fprintf ( V_4 , L_26 ,
( (struct V_10 * ) V_12 ) -> V_11 ,
( (struct V_10 * ) V_12 ) -> V_14 ) ;
}
static void
F_7 ( void ) {
int V_15 ;
struct V_10 * V_16 ;
T_5 * V_17 = NULL ;
V_16 = F_8 ( struct V_10 , V_18 ) ;
fprintf ( V_4 , L_27 ) ;
for ( V_15 = 0 ; V_15 < V_18 ; V_15 ++ ) {
if ( F_9 ( V_15 ) ) {
V_16 [ V_15 ] . V_11 = F_10 ( V_15 ) ;
V_16 [ V_15 ] . V_14 = F_11 ( V_15 ) ;
V_17 = F_12 ( V_17 , & V_16 [ V_15 ] , F_5 ) ;
}
}
F_13 ( V_17 , F_6 , NULL ) ;
F_14 ( V_17 ) ;
F_15 ( V_16 ) ;
}
static void
F_16 ( void ) {
int V_15 ;
struct V_10 * V_19 ;
T_5 * V_17 = NULL ;
V_19 = F_8 ( struct V_10 , V_20 ) ;
fprintf ( V_4 , L_28 ) ;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
V_19 [ V_15 ] . V_11 = F_17 ( V_15 ) ;
if ( V_19 [ V_15 ] . V_11 != NULL ) {
V_19 [ V_15 ] . V_14 = F_18 ( V_15 ) ;
V_17 = F_12 ( V_17 , & V_19 [ V_15 ] , F_5 ) ;
}
}
F_13 ( V_17 , F_6 , NULL ) ;
F_14 ( V_17 ) ;
F_15 ( V_19 ) ;
}
int
main ( int V_21 , char * V_22 [] )
{
int V_23 ;
T_6 V_24 = FALSE ;
T_6 V_25 = FALSE ;
int V_26 = 0 ;
T_7 V_27 = 0 ;
#ifdef F_19
int V_28 = V_29 ;
#else
int V_28 = V_30 ;
#endif
int V_31 = - 2 ;
int V_32 ;
T_8 * V_33 = NULL , * V_34 ;
int V_15 ;
struct V_35 * V_36 , V_37 ;
T_9 * V_38 ;
int V_39 , V_40 = 0 , V_41 , V_42 ;
T_10 * V_43 ;
int V_44 ;
char * V_45 = NULL ;
T_6 V_46 = FALSE , V_47 = FALSE ;
int V_48 ;
#ifdef F_20
F_21 ( V_21 , V_22 ) ;
F_22 () ;
#endif
while ( ( V_23 = F_23 ( V_21 , V_22 , L_29 ) ) != - 1 ) {
switch ( V_23 ) {
case 'w' :
V_45 = V_49 ;
break;
case 'a' :
V_24 = ! V_24 ;
break;
case 'T' :
V_31 = F_24 ( V_49 ) ;
if ( V_31 < 0 ) {
fprintf ( V_4 , L_30 ,
V_49 ) ;
F_16 () ;
exit ( 1 ) ;
}
break;
case 'F' :
V_28 = F_25 ( V_49 ) ;
if ( V_28 < 0 ) {
fprintf ( V_4 , L_31 ,
V_49 ) ;
F_7 () ;
exit ( 1 ) ;
}
break;
case 'v' :
V_25 = TRUE ;
break;
case 's' :
V_27 = F_2 ( V_49 , L_32 ) ;
break;
case 'h' :
F_3 () ;
exit ( 0 ) ;
break;
case '?' :
switch( V_50 ) {
case 'F' :
F_7 () ;
break;
case 'T' :
F_16 () ;
break;
default:
F_3 () ;
}
exit ( 1 ) ;
break;
}
}
V_26 = V_21 - V_51 ;
if ( ! V_45 ) {
fprintf ( V_4 , L_33 ) ;
fprintf ( V_4 , L_34 ) ;
return 1 ;
}
if ( V_26 < 1 ) {
fprintf ( V_4 , L_35 ) ;
return 1 ;
}
if ( ! F_26 ( V_26 , & V_22 [ V_51 ] , & V_33 ,
& V_39 , & V_43 , & V_44 ) ) {
fprintf ( V_4 , L_36 , V_22 [ V_51 + V_44 ] ,
F_27 ( V_39 ) ) ;
switch ( V_39 ) {
case V_52 :
case V_53 :
case V_54 :
fprintf ( V_4 , L_37 , V_43 ) ;
F_15 ( V_43 ) ;
break;
}
return 2 ;
}
if ( V_25 ) {
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ )
fprintf ( V_4 , L_38 , V_22 [ V_51 + V_15 ] ,
F_11 ( F_28 ( V_33 [ V_15 ] . V_55 ) ) ) ;
}
if ( V_27 == 0 ) {
V_27 = F_29 ( V_26 , V_33 ) ;
}
if ( V_31 == - 2 ) {
V_31 = F_30 ( V_26 , V_33 ) ;
if ( V_25 ) {
if ( V_31 == V_56 ) {
int V_57 , V_58 ;
V_57 = F_31 ( V_33 [ 0 ] . V_55 ) ;
for ( V_15 = 1 ; V_15 < V_26 ; V_15 ++ ) {
V_58 = F_31 ( V_33 [ V_15 ] . V_55 ) ;
if ( V_57 != V_58 ) {
fprintf ( V_4 , L_39 ) ;
fprintf ( V_4 , L_40 ) ;
fprintf ( V_4 , L_41 ,
V_33 [ 0 ] . V_59 ,
F_18 ( V_57 ) ,
F_17 ( V_57 ) ) ;
fprintf ( V_4 , L_41 ,
V_33 [ V_15 ] . V_59 ,
F_18 ( V_58 ) ,
F_17 ( V_58 ) ) ;
break;
}
}
}
fprintf ( V_4 , L_42 ,
F_18 ( V_31 ) ,
F_17 ( V_31 ) ) ;
}
}
if ( strncmp ( V_45 , L_43 , 2 ) == 0 ) {
V_32 = 1 ;
} else {
V_32 = F_32 ( V_45 , V_60 | V_61 | V_62 | V_63 , 0644 ) ;
if ( V_32 == - 1 ) {
fprintf ( V_4 , L_44 ,
V_45 , F_33 ( V_64 ) ) ;
exit ( 1 ) ;
}
}
if( V_28 == V_29 ) {
T_11 * V_65 ;
T_12 * V_66 ;
V_65 = F_8 ( T_11 , 1 ) ;
V_66 = F_34 ( L_45 ) ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ ) {
F_35 ( V_66 , L_46 , V_15 + 1 , V_33 [ V_15 ] . V_59 ) ;
}
V_65 -> V_67 = - 1 ;
V_65 -> V_68 = V_66 -> V_69 ;
V_65 -> V_70 = NULL ;
V_65 -> V_71 = NULL ;
V_65 -> V_72 = L_47 ;
V_38 = F_36 ( V_32 , V_28 , V_31 , V_27 ,
FALSE , V_65 , NULL , & V_39 ) ;
F_37 ( V_66 , TRUE ) ;
} else{
V_38 = F_38 ( V_32 , V_28 , V_31 , V_27 , FALSE , & V_39 ) ;
}
if ( V_38 == NULL ) {
F_39 ( V_26 , V_33 ) ;
F_15 ( V_33 ) ;
fprintf ( V_4 , L_48 , V_45 ,
F_27 ( V_39 ) ) ;
exit ( 1 ) ;
}
V_48 = 1 ;
for (; ; ) {
if ( V_24 )
V_34 = F_40 ( V_26 , V_33 , & V_40 ,
& V_43 ) ;
else
V_34 = F_41 ( V_26 , V_33 , & V_40 ,
& V_43 ) ;
if ( V_34 == NULL ) {
break;
}
if ( V_40 != 0 ) {
V_46 = TRUE ;
break;
}
if ( V_25 )
fprintf ( V_4 , L_49 , V_48 ++ ) ;
V_36 = F_42 ( V_34 -> V_55 ) ;
if ( V_27 != 0 && V_36 -> V_73 > V_27 ) {
V_37 = * V_36 ;
V_37 . V_73 = V_27 ;
V_36 = & V_37 ;
}
if ( ! F_43 ( V_38 , V_36 , F_44 ( V_34 -> V_55 ) , & V_41 ) ) {
V_47 = TRUE ;
break;
}
}
F_39 ( V_26 , V_33 ) ;
if ( ! V_46 && ! V_47 ) {
if ( ! F_45 ( V_38 , & V_41 ) )
V_47 = TRUE ;
} else
F_45 ( V_38 , & V_42 ) ;
if ( V_46 ) {
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ ) {
if ( V_33 [ V_15 ] . V_74 == V_75 ) {
fprintf ( V_4 , L_50 ,
V_33 [ V_15 ] . V_59 , F_27 ( V_40 ) ) ;
switch ( V_40 ) {
case V_52 :
case V_53 :
case V_54 :
fprintf ( V_4 , L_37 , V_43 ) ;
F_15 ( V_43 ) ;
break;
}
}
}
}
if ( V_47 ) {
switch ( V_41 ) {
case V_53 :
fprintf ( V_4 , L_51 ,
V_34 -> V_76 , V_34 -> V_59 ) ;
break;
default:
fprintf ( V_4 , L_52 ,
F_27 ( V_41 ) ) ;
break;
}
}
F_15 ( V_33 ) ;
return ( ! V_46 && ! V_47 ) ? 0 : 2 ;
}
