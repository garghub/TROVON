static T_1
F_1 ( const T_2 * line , int V_1 , T_3 * V_2 , T_4 * V_3 )
{
char * args ;
char * V_4 ;
T_2 V_5 ;
int V_6 ;
int V_7 [ 4 ] , V_8 [ 2 ] ;
T_1 V_9 = FALSE ;
args = F_2 ( line , V_1 ) ;
V_4 = args ;
for (; ; ) {
while ( ( V_5 = * V_4 ) != '\0' && ! isdigit ( V_5 ) )
V_4 ++ ;
if ( * V_4 == '\0' ) {
break;
}
V_6 = sscanf ( V_4 , L_1 ,
& V_7 [ 0 ] , & V_7 [ 1 ] , & V_7 [ 2 ] , & V_7 [ 3 ] ,
& V_8 [ 0 ] , & V_8 [ 1 ] ) ;
if ( V_6 == 6 ) {
* V_3 = ( ( V_8 [ 0 ] & 0xFF ) << 8 ) | ( V_8 [ 1 ] & 0xFF ) ;
* V_2 = F_3 ( ( V_7 [ 0 ] << 24 ) | ( V_7 [ 1 ] << 16 ) | ( V_7 [ 2 ] << 8 ) | V_7 [ 3 ] ) ;
V_9 = TRUE ;
break;
}
while ( ( V_5 = * V_4 ) != '\0' && isdigit ( V_5 ) )
V_4 ++ ;
}
return V_9 ;
}
static T_1
F_4 ( const T_2 * line , int V_1 , T_4 * V_3 )
{
int V_10 ;
char * args ;
char * V_4 ;
T_2 V_5 ;
T_1 V_9 = FALSE ;
T_1 V_11 = FALSE ;
args = F_2 ( line , V_1 ) ;
V_4 = args ;
for (; ! V_11 ; ) {
T_2 V_12 = '\0' ;
while ( ( V_5 = * V_4 ) != '\0' && ( V_5 != '(' ) )
V_4 ++ ;
if ( * V_4 == '\0' ) {
return FALSE ;
}
V_4 ++ ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ ) {
if ( ( V_5 = * V_4 ) != '\0' ) {
if ( V_12 == '\0' ) {
V_12 = V_5 ;
}
if ( V_5 != V_12 ) {
break;
}
V_4 ++ ;
}
else {
break;
}
}
V_11 = TRUE ;
}
if ( * V_4 != '\0' ) {
* V_3 = atoi ( V_4 ) ;
V_9 = TRUE ;
}
return V_9 ;
}
static void
F_5 ( T_5 * V_13 , T_6 * V_14 , T_7 * V_15 )
{
T_1 V_16 ;
T_7 * V_17 = NULL ;
T_7 * V_18 = NULL ;
T_8 * V_19 , * V_20 ;
T_9 V_21 = 0 ;
const T_2 * line ;
T_3 V_22 ;
T_10 V_23 [ 4 ] ;
T_1 V_24 = FALSE ;
T_1 V_25 = FALSE ;
T_1 V_26 = FALSE ;
T_9 V_27 ;
int V_1 ;
int V_28 ;
const T_2 * V_29 ;
T_3 V_30 ;
T_3 V_2 ;
T_4 V_3 ;
T_11 V_31 ;
T_1 V_32 ;
T_12 * V_33 ;
V_31 = V_14 -> V_34 ;
if ( V_14 -> V_35 == V_14 -> V_36 )
V_16 = TRUE ;
else
V_16 = FALSE ;
F_6 ( V_14 -> V_37 , V_38 , L_2 ) ;
V_1 = F_7 ( V_13 , V_21 , - 1 , & V_27 , FALSE ) ;
line = F_8 ( V_13 , V_21 , V_1 ) ;
F_9 ( V_14 -> V_37 , V_39 , L_3 ,
V_16 ? L_4 : L_5 ,
F_10 ( line , V_1 ) ) ;
if ( V_15 ) {
V_19 = F_11 ( V_15 , V_40 , V_13 , V_21 , - 1 , V_41 ) ;
V_17 = F_12 ( V_19 , V_42 ) ;
if ( V_16 ) {
V_20 = F_13 ( V_17 ,
V_43 , V_13 , 0 , 0 , TRUE ) ;
F_14 ( V_20 ) ;
V_20 = F_13 ( V_17 ,
V_44 , V_13 , 0 , 0 , FALSE ) ;
F_14 ( V_20 ) ;
} else {
V_20 = F_13 ( V_17 ,
V_43 , V_13 , 0 , 0 , FALSE ) ;
F_14 ( V_20 ) ;
V_20 = F_13 ( V_17 ,
V_44 , V_13 , 0 , 0 , TRUE ) ;
F_14 ( V_20 ) ;
}
V_19 = F_15 ( V_17 , V_13 , V_21 ,
V_27 - V_21 , L_6 ,
F_16 ( V_13 , V_21 , V_27 - V_21 ) ) ;
V_18 = F_12 ( V_19 , V_45 ) ;
}
if ( V_16 ) {
V_28 = F_17 ( line , line + V_1 , & V_29 ) ;
if ( V_28 != 0 ) {
if ( V_15 ) {
F_11 ( V_18 ,
V_46 , V_13 , V_21 ,
V_28 , V_47 | V_41 ) ;
}
if ( strncmp ( line , L_7 , V_28 ) == 0 )
V_24 = TRUE ;
}
} else {
if ( V_1 >= 3 && isdigit ( line [ 0 ] ) && isdigit ( line [ 1 ] )
&& isdigit ( line [ 2 ] ) ) {
F_18 ( V_13 , V_21 , sizeof( V_23 ) , V_23 ) ;
V_22 = strtoul ( V_23 , NULL , 10 ) ;
if ( V_15 ) {
F_19 ( V_18 ,
V_48 , V_13 , V_21 , 3 , V_22 ) ;
}
if ( V_22 == 227 )
V_25 = TRUE ;
if ( V_22 == 229 )
V_26 = TRUE ;
if ( V_1 >= 4 )
V_29 = line + 4 ;
else
V_29 = line + V_1 ;
} else {
V_29 = line ;
}
}
V_21 += ( T_9 ) ( V_29 - line ) ;
V_1 -= ( int ) ( V_29 - line ) ;
line = V_29 ;
if ( V_15 ) {
if ( V_1 != 0 ) {
if ( V_16 ) {
F_11 ( V_18 ,
V_49 , V_13 , V_21 ,
V_1 , V_47 | V_41 ) ;
} else {
F_11 ( V_18 ,
V_50 , V_13 , V_21 ,
V_1 , V_47 | V_41 ) ;
}
}
V_21 = V_27 ;
}
if ( V_24 ) {
if ( F_1 ( line , V_1 , & V_2 , & V_3 ) ) {
if ( V_15 ) {
F_20 ( V_18 ,
V_51 , V_13 , 0 , 0 ,
V_2 ) ;
F_19 ( V_18 ,
V_52 , V_13 , 0 , 0 ,
V_3 ) ;
}
F_21 ( & V_31 , V_53 , 4 , ( const V_54 * ) & V_2 ) ;
V_32 = ! F_22 ( & V_14 -> V_34 , & V_31 ) ;
if ( V_32 ) {
if ( V_15 ) {
F_13 (
V_18 ,
V_55 , V_13 ,
0 , 0 , V_32 ) ;
}
}
}
}
if ( V_25 ) {
if ( V_1 != 0 ) {
if ( F_1 ( line , V_1 , & V_30 , & V_3 ) ) {
if ( V_15 ) {
F_20 ( V_18 ,
V_56 , V_13 , 0 , 0 , V_30 ) ;
F_19 ( V_18 ,
V_57 , V_13 , 0 , 0 ,
V_3 ) ;
}
F_21 ( & V_31 , V_53 , 4 ,
( const V_54 * ) & V_30 ) ;
V_32 = ! F_22 ( & V_14 -> V_34 , & V_31 ) ;
if ( V_32 ) {
if ( V_15 ) {
F_13 ( V_18 ,
V_58 , V_13 , 0 , 0 ,
V_32 ) ;
}
}
V_33 = F_23 ( V_14 -> V_59 -> V_60 , & V_31 ,
& V_14 -> V_61 , V_62 , V_3 , 0 ,
V_63 ) ;
if ( V_33 == NULL ) {
V_33 = F_24 (
V_14 -> V_59 -> V_60 , & V_31 , & V_14 -> V_61 ,
V_62 , V_3 , 0 , V_64 ) ;
F_25 ( V_33 , V_65 ) ;
}
}
}
}
if ( V_26 ) {
if ( V_1 != 0 ) {
if ( F_4 ( line , V_1 , & V_3 ) ) {
if ( V_15 ) {
F_19 ( V_18 ,
V_57 , V_13 , 0 , 0 ,
V_3 ) ;
}
V_33 = F_23 ( V_14 -> V_59 -> V_60 , & V_14 -> V_34 ,
& V_14 -> V_61 , V_62 , V_3 , 0 ,
V_63 ) ;
if ( V_33 == NULL ) {
V_33 = F_24 (
V_14 -> V_59 -> V_60 , & V_14 -> V_34 , & V_14 -> V_61 ,
V_62 , V_3 , 0 , V_64 ) ;
F_25 ( V_33 ,
V_65 ) ;
}
}
}
}
if ( V_15 ) {
while ( F_26 ( V_13 , V_21 ) ) {
F_7 ( V_13 , V_21 , - 1 , & V_27 , FALSE ) ;
F_15 ( V_17 , V_13 , V_21 ,
V_27 - V_21 , L_6 ,
F_16 ( V_13 , V_21 , V_27 - V_21 ) ) ;
V_21 = V_27 ;
}
}
}
static void
F_27 ( T_5 * V_13 , T_6 * V_14 , T_7 * V_15 )
{
T_7 * V_19 , * V_66 ;
int V_67 ;
F_6 ( V_14 -> V_37 , V_38 , L_8 ) ;
F_9 ( V_14 -> V_37 , V_39 , L_9 ,
F_28 ( V_13 ) ) ;
if ( V_15 ) {
V_67 = F_29 ( V_13 ) ;
V_19 = F_11 ( V_15 , V_68 , V_13 , 0 , - 1 ,
V_41 ) ;
V_66 = F_12 ( V_19 , V_69 ) ;
F_15 ( V_66 , V_13 , 0 , V_67 ,
L_10 , F_16 ( V_13 , 0 , V_67 ) ) ;
}
}
void
F_30 ( void )
{
static T_13 V_70 [] = {
{ & V_44 ,
{ L_5 , L_11 ,
V_71 , V_72 , NULL , 0x0 ,
L_12 , V_73 } } ,
{ & V_43 ,
{ L_4 , L_13 ,
V_71 , V_72 , NULL , 0x0 ,
L_14 , V_73 } } ,
{ & V_46 ,
{ L_15 , L_16 ,
V_74 , V_72 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_49 ,
{ L_17 , L_18 ,
V_74 , V_72 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_48 ,
{ L_19 , L_20 ,
V_75 , V_76 | V_77 , & V_78 , 0x0 ,
NULL , V_73 } } ,
{ & V_50 ,
{ L_21 , L_22 ,
V_74 , V_72 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_56 ,
{ L_23 , L_24 ,
V_79 , V_72 , NULL , 0x0 ,
L_25 , V_73 } } ,
{ & V_57 ,
{ L_26 , L_27 ,
V_80 , V_76 , NULL , 0x0 ,
L_28 , V_73 } } ,
{ & V_58 ,
{ L_29 , L_30 ,
V_71 , V_72 , NULL , 0x0 ,
L_31 , V_73 } } ,
{ & V_51 ,
{ L_32 , L_33 ,
V_79 , V_72 , NULL , 0x0 ,
L_34 , V_73 } } ,
{ & V_52 ,
{ L_35 , L_36 ,
V_80 , V_76 , NULL , 0x0 ,
L_37 , V_73 } } ,
{ & V_55 ,
{ L_38 , L_39 ,
V_71 , V_72 , NULL , 0x0 ,
L_40 , V_73 } }
} ;
static T_9 * V_81 [] = {
& V_42 ,
& V_45 ,
& V_69 ,
} ;
V_40 = F_31 ( L_41 , L_2 ,
L_42 ) ;
F_32 ( L_42 , F_5 , V_40 ) ;
V_68 = F_31 ( L_43 , L_8 , L_44 ) ;
F_32 ( L_44 , F_27 , V_68 ) ;
F_33 ( V_40 , V_70 , F_34 ( V_70 ) ) ;
F_35 ( V_81 , F_34 ( V_81 ) ) ;
}
void
F_36 ( void )
{
T_14 V_82 ;
V_65 = F_37 ( L_44 ) ;
F_38 ( L_45 , V_83 , V_65 ) ;
V_82 = F_37 ( L_42 ) ;
F_38 ( L_45 , V_84 , V_82 ) ;
}
