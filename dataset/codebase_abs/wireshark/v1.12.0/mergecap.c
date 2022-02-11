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
fprintf ( V_4 , L_2 , V_1 ) ;
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
fprintf ( V_4 , L_4 , V_1 ) ;
exit ( 1 ) ;
}
return V_2 ;
}
static void
F_3 ( T_1 V_6 )
{
T_2 * V_7 ;
if ( ! V_6 ) {
V_7 = stdout ;
}
else {
V_7 = V_4 ;
}
fprintf ( V_7 , L_5
#ifdef F_4
L_6 F_4 L_7 V_8 L_8
#endif
L_9 , V_9 ) ;
fprintf ( V_7 , L_10 ) ;
fprintf ( V_7 , L_11 ) ;
fprintf ( V_7 , L_9 ) ;
fprintf ( V_7 , L_12 ) ;
fprintf ( V_7 , L_9 ) ;
fprintf ( V_7 , L_13 ) ;
fprintf ( V_7 , L_14 ) ;
fprintf ( V_7 , L_15 ) ;
fprintf ( V_7 , L_16 ) ;
fprintf ( V_7 , L_17 ) ;
fprintf ( V_7 , L_18 ) ;
fprintf ( V_7 , L_19 ) ;
fprintf ( V_7 , L_20 ) ;
fprintf ( V_7 , L_21 ) ;
fprintf ( V_7 , L_22 ) ;
fprintf ( V_7 , L_9 ) ;
fprintf ( V_7 , L_23 ) ;
fprintf ( V_7 , L_24 ) ;
fprintf ( V_7 , L_25 ) ;
}
static T_3
F_5 ( T_4 V_10 , T_4 V_11 )
{
return strcmp ( ( ( const struct V_12 * ) V_10 ) -> V_13 ,
( ( const struct V_12 * ) V_11 ) -> V_13 ) ;
}
static T_3
F_6 ( T_4 V_10 , T_4 V_11 )
{
return F_7 ( ( ( const struct V_12 * ) V_10 ) -> V_13 ,
( ( const struct V_12 * ) V_11 ) -> V_13 ) ;
}
static void
F_8 ( T_5 V_14 , T_5 T_6 V_15 )
{
fprintf ( V_4 , L_26 , ( (struct V_12 * ) V_14 ) -> V_13 ,
( (struct V_12 * ) V_14 ) -> V_16 ) ;
}
static void
F_9 ( void ) {
int V_17 ;
struct V_12 * V_18 ;
T_7 * V_19 = NULL ;
V_18 = F_10 ( struct V_12 , V_20 ) ;
fprintf ( V_4 , L_27 ) ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ ) {
if ( F_11 ( V_17 ) ) {
V_18 [ V_17 ] . V_13 = F_12 ( V_17 ) ;
V_18 [ V_17 ] . V_16 = F_13 ( V_17 ) ;
V_19 = F_14 ( V_19 , & V_18 [ V_17 ] , F_5 ) ;
}
}
F_15 ( V_19 , F_8 , NULL ) ;
F_16 ( V_19 ) ;
F_17 ( V_18 ) ;
}
static void
F_18 ( void ) {
int V_17 ;
struct V_12 * V_21 ;
T_7 * V_19 = NULL ;
V_21 = F_10 ( struct V_12 , V_22 ) ;
fprintf ( V_4 , L_28 ) ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ ) {
V_21 [ V_17 ] . V_13 = F_19 ( V_17 ) ;
if ( V_21 [ V_17 ] . V_13 != NULL ) {
V_21 [ V_17 ] . V_16 = F_20 ( V_17 ) ;
V_19 = F_14 ( V_19 , & V_21 [ V_17 ] , F_6 ) ;
}
}
F_15 ( V_19 , F_8 , NULL ) ;
F_16 ( V_19 ) ;
F_17 ( V_21 ) ;
}
int
main ( int V_23 , char * V_24 [] )
{
int V_25 ;
T_1 V_26 = FALSE ;
T_1 V_27 = FALSE ;
int V_28 = 0 ;
T_8 V_29 = 0 ;
#ifdef F_21
int V_30 = V_31 ;
#else
int V_30 = V_32 ;
#endif
int V_33 = - 2 ;
int V_34 ;
T_9 * V_35 = NULL , * V_36 ;
int V_17 ;
struct V_37 * V_38 , V_39 ;
T_10 * V_40 ;
int V_41 , V_42 = 0 , V_43 , V_44 ;
T_11 * V_45 ;
int V_46 ;
char * V_47 = NULL ;
T_1 V_48 = FALSE , V_49 = FALSE ;
int V_50 ;
#ifdef F_22
F_23 ( V_23 , V_24 ) ;
F_24 () ;
#endif
while ( ( V_25 = F_25 ( V_23 , V_24 , L_29 ) ) != - 1 ) {
switch ( V_25 ) {
case 'a' :
V_26 = ! V_26 ;
break;
case 'F' :
V_30 = F_26 ( V_51 ) ;
if ( V_30 < 0 ) {
fprintf ( V_4 , L_30 ,
V_51 ) ;
F_9 () ;
exit ( 1 ) ;
}
break;
case 'h' :
F_3 ( FALSE ) ;
exit ( 0 ) ;
break;
case 's' :
V_29 = F_2 ( V_51 , L_31 ) ;
break;
case 'T' :
V_33 = F_27 ( V_51 ) ;
if ( V_33 < 0 ) {
fprintf ( V_4 , L_32 ,
V_51 ) ;
F_18 () ;
exit ( 1 ) ;
}
break;
case 'v' :
V_27 = TRUE ;
break;
case 'w' :
V_47 = V_51 ;
break;
case '?' :
switch( V_52 ) {
case 'F' :
F_9 () ;
break;
case 'T' :
F_18 () ;
break;
default:
F_3 ( TRUE ) ;
}
exit ( 1 ) ;
break;
}
}
V_28 = V_23 - V_53 ;
if ( ! V_47 ) {
fprintf ( V_4 , L_33 ) ;
fprintf ( V_4 , L_34 ) ;
return 1 ;
}
if ( V_28 < 1 ) {
fprintf ( V_4 , L_35 ) ;
return 1 ;
}
if ( ! F_28 ( V_28 , & V_24 [ V_53 ] , & V_35 ,
& V_41 , & V_45 , & V_46 ) ) {
fprintf ( V_4 , L_36 , V_24 [ V_53 + V_46 ] ,
F_29 ( V_41 ) ) ;
switch ( V_41 ) {
case V_54 :
case V_55 :
case V_56 :
fprintf ( V_4 , L_37 , V_45 ) ;
F_17 ( V_45 ) ;
break;
}
return 2 ;
}
if ( V_27 ) {
for ( V_17 = 0 ; V_17 < V_28 ; V_17 ++ )
fprintf ( V_4 , L_38 , V_24 [ V_53 + V_17 ] ,
F_13 ( F_30 ( V_35 [ V_17 ] . V_57 ) ) ) ;
}
if ( V_29 == 0 ) {
V_29 = F_31 ( V_28 , V_35 ) ;
}
if ( V_33 == - 2 ) {
V_33 = F_32 ( V_28 , V_35 ) ;
if ( V_27 ) {
if ( V_33 == V_58 ) {
int V_59 , V_60 ;
V_59 = F_33 ( V_35 [ 0 ] . V_57 ) ;
for ( V_17 = 1 ; V_17 < V_28 ; V_17 ++ ) {
V_60 = F_33 ( V_35 [ V_17 ] . V_57 ) ;
if ( V_59 != V_60 ) {
fprintf ( V_4 , L_39 ) ;
fprintf ( V_4 , L_40 ) ;
fprintf ( V_4 , L_41 ,
V_35 [ 0 ] . V_61 ,
F_20 ( V_59 ) ,
F_19 ( V_59 ) ) ;
fprintf ( V_4 , L_41 ,
V_35 [ V_17 ] . V_61 ,
F_20 ( V_60 ) ,
F_19 ( V_60 ) ) ;
break;
}
}
}
fprintf ( V_4 , L_42 ,
F_20 ( V_33 ) ,
F_19 ( V_33 ) ) ;
}
}
if ( strncmp ( V_47 , L_43 , 2 ) == 0 ) {
V_34 = 1 ;
} else {
V_34 = F_34 ( V_47 , V_62 | V_63 | V_64 | V_65 , 0644 ) ;
if ( V_34 == - 1 ) {
fprintf ( V_4 , L_44 ,
V_47 , F_35 ( V_66 ) ) ;
exit ( 1 ) ;
}
}
if( V_30 == V_31 ) {
T_12 * V_67 ;
T_13 * V_68 ;
V_67 = F_10 ( T_12 , 1 ) ;
V_68 = F_36 ( L_45 ) ;
for ( V_17 = 0 ; V_17 < V_28 ; V_17 ++ ) {
F_37 ( V_68 , L_46 , V_17 + 1 , V_35 [ V_17 ] . V_61 ) ;
}
V_67 -> V_69 = - 1 ;
V_67 -> V_70 = V_68 -> V_71 ;
V_67 -> V_72 = NULL ;
V_67 -> V_73 = NULL ;
V_67 -> V_74 = L_47 ;
V_40 = F_38 ( V_34 , V_30 , V_33 , V_29 ,
FALSE , V_67 , NULL , & V_41 ) ;
F_39 ( V_68 , TRUE ) ;
} else {
V_40 = F_40 ( V_34 , V_30 , V_33 , V_29 , FALSE , & V_41 ) ;
}
if ( V_40 == NULL ) {
F_41 ( V_28 , V_35 ) ;
F_17 ( V_35 ) ;
fprintf ( V_4 , L_48 , V_47 ,
F_29 ( V_41 ) ) ;
exit ( 1 ) ;
}
V_50 = 1 ;
for (; ; ) {
if ( V_26 )
V_36 = F_42 ( V_28 , V_35 , & V_42 ,
& V_45 ) ;
else
V_36 = F_43 ( V_28 , V_35 , & V_42 ,
& V_45 ) ;
if ( V_36 == NULL ) {
break;
}
if ( V_42 != 0 ) {
V_48 = TRUE ;
break;
}
if ( V_27 )
fprintf ( V_4 , L_49 , V_50 ++ ) ;
V_38 = F_44 ( V_36 -> V_57 ) ;
if ( V_29 != 0 && V_38 -> V_75 > V_29 ) {
V_39 = * V_38 ;
V_39 . V_75 = V_29 ;
V_38 = & V_39 ;
}
if ( ! F_45 ( V_40 , V_38 , F_46 ( V_36 -> V_57 ) , & V_43 ) ) {
V_49 = TRUE ;
break;
}
}
F_41 ( V_28 , V_35 ) ;
if ( ! V_49 ) {
if ( ! F_47 ( V_40 , & V_43 ) )
V_49 = TRUE ;
} else {
( void ) F_47 ( V_40 , & V_44 ) ;
}
if ( V_48 ) {
for ( V_17 = 0 ; V_17 < V_28 ; V_17 ++ ) {
if ( V_35 [ V_17 ] . V_76 == V_77 ) {
fprintf ( V_4 , L_50 ,
V_35 [ V_17 ] . V_61 , F_29 ( V_42 ) ) ;
switch ( V_42 ) {
case V_54 :
case V_55 :
case V_56 :
fprintf ( V_4 , L_37 , V_45 ) ;
F_17 ( V_45 ) ;
break;
}
}
}
}
if ( V_49 ) {
switch ( V_43 ) {
case V_55 :
fprintf ( V_4 , L_51 ,
V_36 ? V_36 -> V_78 : 0 , V_36 ? V_36 -> V_61 : L_52 ,
F_13 ( V_30 ) ) ;
break;
case V_79 :
fprintf ( V_4 , L_53 ,
V_36 ? V_36 -> V_78 : 0 , V_36 ? V_36 -> V_61 : L_52 ,
F_13 ( V_30 ) ) ;
break;
default:
fprintf ( V_4 , L_54 ,
F_29 ( V_43 ) ) ;
break;
}
}
F_17 ( V_35 ) ;
return ( ! V_48 && ! V_49 ) ? 0 : 2 ;
}
