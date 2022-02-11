static T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
int V_4 ;
T_4 V_5 = 0 ;
T_1 V_6 ;
while ( ( V_4 = F_2 ( V_1 -> V_7 ) ) != V_8 ) {
if ( V_4 == V_9 [ V_5 ] ) {
V_5 ++ ;
if ( V_5 >= V_10 ) {
V_6 = F_3 ( V_1 -> V_7 ) ;
if ( V_6 == - 1 ) {
* V_2 = F_4 ( V_1 -> V_7 , V_3 ) ;
return - 1 ;
}
return V_6 + 1 ;
}
} else {
V_5 = 0 ;
}
}
if ( F_5 ( V_1 -> V_7 ) ) {
* V_2 = 0 ;
} else {
* V_2 = F_4 ( V_1 -> V_7 , V_3 ) ;
}
return - 1 ;
}
static T_5 F_6 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
char V_11 [ V_12 ] ;
T_4 V_13 , V_14 , V_5 , line ;
char V_4 ;
V_11 [ V_12 - 1 ] = 0 ;
for ( line = 0 ; line < V_15 ; line ++ ) {
if ( F_7 ( V_11 , V_12 , V_1 -> V_7 ) != NULL ) {
V_14 = ( T_4 ) strlen ( V_11 ) ;
if ( V_14 < V_16 ) {
continue;
}
V_5 = 0 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_4 = V_11 [ V_13 ] ;
if ( V_4 == V_17 [ V_5 ] ) {
V_5 ++ ;
if ( V_5 >= V_16 ) {
return TRUE ;
}
}
else {
V_5 = 0 ;
}
}
}
else {
if ( F_5 ( V_1 -> V_7 ) )
* V_2 = 0 ;
else
* V_2 = F_4 ( V_1 -> V_7 , V_3 ) ;
return FALSE ;
}
}
* V_2 = 0 ;
return FALSE ;
}
int F_8 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
if ( ! F_6 ( V_1 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
return 0 ;
else
return - 1 ;
}
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = 0 ;
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
return 1 ;
}
static T_5 V_24 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_1 * V_29 )
{
T_1 V_30 ;
T_6 * V_11 ;
int V_31 ;
V_30 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_30 < 1 )
return FALSE ;
V_31 = F_9 ( V_1 , V_1 -> V_7 , & V_1 -> V_32 ,
V_2 , V_3 ) ;
if ( V_31 == - 1 )
return FALSE ;
F_10 ( V_1 -> V_33 , V_34 ) ;
V_11 = F_11 ( V_1 -> V_33 ) ;
if ( ! F_12 ( V_1 -> V_7 , V_31 , V_11 , V_2 , V_3 ) )
return FALSE ;
* V_29 = V_30 ;
return TRUE ;
}
static T_5
V_26 ( T_2 * V_1 , T_1 V_35 ,
union V_36 * V_32 , T_6 * V_37 , int V_38 ,
int * V_2 , T_3 * * V_3 )
{
int V_31 ;
if ( F_13 ( V_1 -> V_39 , V_35 - 1 , V_40 , V_2 ) == - 1 )
return FALSE ;
V_31 = F_9 ( NULL , V_1 -> V_39 , V_32 ,
V_2 , V_3 ) ;
if ( V_31 != V_38 ) {
if ( V_31 != - 1 ) {
* V_2 = V_41 ;
* V_3 = F_14 ( L_1 ,
V_38 , V_31 ) ;
}
return FALSE ;
}
return F_12 ( V_1 -> V_39 , V_31 , V_37 , V_2 , V_3 ) ;
}
static int
F_9 ( T_2 * V_1 , T_7 V_7 ,
union V_36 * V_32 , int * V_2 , T_3 * * V_3 )
{
char line [ V_12 ] ;
int V_42 ;
int V_31 , V_43 , V_44 , V_45 , V_46 , V_47 ;
char V_48 [ 10 ] , V_49 [ 10 ] ;
if ( F_7 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_50 ;
}
return - 1 ;
}
V_42 = sscanf ( line , L_2 ,
& V_43 , & V_44 , & V_45 , & V_46 , & V_47 , V_48 , V_49 ) ;
if ( V_42 != 7 ) {
* V_2 = V_41 ;
* V_3 = F_15 ( L_3 ) ;
return - 1 ;
}
do {
if ( F_7 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_50 ;
}
return - 1 ;
}
line [ 16 ] = '\0' ;
} while ( strcmp ( line , L_4 ) != 0 );
V_42 = sscanf ( line + 64 , L_5 , & V_31 ) ;
if ( V_42 != 1 ) {
* V_2 = V_41 ;
* V_3 = F_15 ( L_6 ) ;
return - 1 ;
}
if ( V_1 ) {
V_1 -> V_51 . V_52 = V_53 | V_54 ;
V_1 -> V_51 . V_55 . V_56 = V_44 * 3600 + V_45 * 60 + V_46 ;
V_1 -> V_51 . V_55 . V_57 = V_47 * 10000000 ;
V_1 -> V_51 . V_58 = V_31 ;
V_1 -> V_51 . V_38 = V_31 ;
}
switch ( V_48 [ 0 ] ) {
case 'B' :
if ( V_1 )
V_1 -> V_51 . V_59 = V_60 ;
V_32 -> V_61 . V_62 = ( V_49 [ 0 ] == 'T' ) ;
V_32 -> V_61 . V_48 = ( T_6 )
strtol ( & V_48 [ 1 ] , NULL , 10 ) ;
break;
case 'D' :
if ( V_1 )
V_1 -> V_51 . V_59 = V_60 ;
V_32 -> V_61 . V_62 = ( V_49 [ 0 ] == 'T' ) ;
V_32 -> V_61 . V_48 = 0 ;
break;
default:
if ( V_1 )
V_1 -> V_51 . V_59 = V_63 ;
V_32 -> V_64 . V_65 = - 1 ;
break;
}
return V_31 ;
}
static T_5
F_12 ( T_7 V_7 , int V_31 , T_6 * V_11 , int * V_2 ,
T_3 * * V_3 )
{
char line [ V_12 ] ;
int V_13 , V_66 ;
V_66 = V_31 / 16 + ( ( V_31 % 16 ) ? 1 : 0 ) ;
for ( V_13 = 0 ; V_13 < V_66 ; V_13 ++ ) {
if ( F_7 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_50 ;
}
return FALSE ;
}
if ( ! F_16 ( line , V_11 , V_13 * 16 ) ) {
* V_2 = V_41 ;
* V_3 = F_15 ( L_7 ) ;
return FALSE ;
}
}
return TRUE ;
}
static T_5
F_16 ( char * V_67 , T_6 * V_11 , T_4 V_68 ) {
int V_69 , V_13 ;
char * V_70 ;
unsigned long V_71 ;
T_8 V_72 ;
V_67 [ 4 ] = '\0' ;
V_70 = V_67 ;
V_71 = strtoul ( V_70 , NULL , 16 ) ;
if ( V_71 != V_68 ) {
return FALSE ;
}
for ( V_69 = V_73 ; V_69 < V_73 + V_74 ; V_69 ++ ) {
if ( V_67 [ V_69 ] == ' ' ) {
V_67 [ V_69 ] = '0' ;
}
}
V_69 = V_73 ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
V_67 [ V_69 + 4 ] = '\0' ;
V_72 = ( T_8 ) strtoul ( & V_67 [ V_69 ] , NULL , 16 ) ;
V_11 [ V_68 + V_13 * 2 + 0 ] = ( T_6 ) ( V_72 >> 8 ) ;
V_11 [ V_68 + V_13 * 2 + 1 ] = ( T_6 ) ( V_72 & 0x00ff ) ;
V_69 += 5 ;
}
return TRUE ;
}
