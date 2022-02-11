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
* V_2 = F_4 ( V_1 -> V_7 , V_3 ) ;
return - 1 ;
}
static T_5 F_5 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
char V_11 [ V_12 ] ;
T_4 V_13 , V_14 , V_5 , line ;
char V_4 ;
V_11 [ V_12 - 1 ] = 0 ;
for ( line = 0 ; line < V_15 ; line ++ ) {
if ( F_6 ( V_11 , V_12 , V_1 -> V_7 ) == NULL ) {
* V_2 = F_4 ( V_1 -> V_7 , V_3 ) ;
return FALSE ;
}
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
* V_2 = 0 ;
return FALSE ;
}
int F_7 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
if ( ! F_5 ( V_1 , V_2 , V_3 ) ) {
if ( * V_2 != 0 && * V_2 != V_18 )
return - 1 ;
return 0 ;
}
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = 0 ;
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
return 1 ;
}
static T_5 V_25 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_1 * V_30 )
{
T_1 V_31 ;
V_31 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_31 < 1 )
return FALSE ;
* V_30 = V_31 ;
return F_8 ( V_1 -> V_7 , & V_1 -> V_32 , V_1 -> V_33 ,
V_2 , V_3 ) ;
}
static T_5
V_27 ( T_2 * V_1 , T_1 V_34 ,
struct V_35 * V_32 , T_6 * V_11 , int T_7 V_36 ,
int * V_2 , T_3 * * V_3 )
{
if ( F_9 ( V_1 -> V_37 , V_34 - 1 , V_38 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_8 ( V_1 -> V_37 , V_32 , V_11 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_18 ;
return FALSE ;
}
return TRUE ;
}
static T_5
F_8 ( T_8 V_7 , struct V_35 * V_32 , T_6 * V_11 ,
int * V_2 , T_3 * * V_3 )
{
union V_39 * V_40 = & V_32 -> V_40 ;
char line [ V_12 ] ;
int V_41 ;
int V_42 , V_43 , V_44 , V_45 , V_46 , V_47 ;
char V_48 [ 10 ] , V_49 [ 10 ] ;
int V_13 , V_50 ;
T_9 * V_51 ;
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
V_41 = sscanf ( line , L_1 ,
& V_43 , & V_44 , & V_45 , & V_46 , & V_47 , V_48 , V_49 ) ;
if ( V_41 != 7 ) {
* V_2 = V_52 ;
* V_3 = F_10 ( L_2 ) ;
return FALSE ;
}
do {
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
line [ 16 ] = '\0' ;
} while ( strcmp ( line , L_3 ) != 0 );
V_41 = sscanf ( line + 64 , L_4 , & V_42 ) ;
if ( V_41 != 1 ) {
* V_2 = V_52 ;
* V_3 = F_10 ( L_5 ) ;
return FALSE ;
}
V_32 -> V_53 = V_54 | V_55 ;
V_32 -> V_56 . V_57 = V_44 * 3600 + V_45 * 60 + V_46 ;
V_32 -> V_56 . V_58 = V_47 * 10000000 ;
V_32 -> V_59 = V_42 ;
V_32 -> T_7 = V_42 ;
switch ( V_48 [ 0 ] ) {
case 'B' :
V_32 -> V_60 = V_61 ;
V_40 -> V_62 . V_63 = ( V_49 [ 0 ] == 'T' ) ;
V_40 -> V_62 . V_48 = ( T_9 )
strtol ( & V_48 [ 1 ] , NULL , 10 ) ;
break;
case 'D' :
V_32 -> V_60 = V_61 ;
V_40 -> V_62 . V_63 = ( V_49 [ 0 ] == 'T' ) ;
V_40 -> V_62 . V_48 = 0 ;
break;
default:
V_32 -> V_60 = V_64 ;
V_40 -> V_65 . V_66 = - 1 ;
break;
}
F_11 ( V_11 , V_67 ) ;
V_51 = F_12 ( V_11 ) ;
V_50 = V_42 / 16 + ( ( V_42 % 16 ) ? 1 : 0 ) ;
for ( V_13 = 0 ; V_13 < V_50 ; V_13 ++ ) {
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
if ( ! F_13 ( line , V_51 , V_13 * 16 ) ) {
* V_2 = V_52 ;
* V_3 = F_10 ( L_6 ) ;
return FALSE ;
}
}
return TRUE ;
}
static T_5
F_13 ( char * V_68 , T_9 * V_11 , T_4 V_69 ) {
int V_70 , V_13 ;
char * V_71 ;
unsigned long V_72 ;
T_10 V_73 ;
V_68 [ 4 ] = '\0' ;
V_71 = V_68 ;
V_72 = strtoul ( V_71 , NULL , 16 ) ;
if ( V_72 != V_69 ) {
return FALSE ;
}
for ( V_70 = V_74 ; V_70 < V_74 + V_75 ; V_70 ++ ) {
if ( V_68 [ V_70 ] == ' ' ) {
V_68 [ V_70 ] = '0' ;
}
}
V_70 = V_74 ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
V_68 [ V_70 + 4 ] = '\0' ;
V_73 = ( T_10 ) strtoul ( & V_68 [ V_70 ] , NULL , 16 ) ;
V_11 [ V_69 + V_13 * 2 + 0 ] = ( T_9 ) ( V_73 >> 8 ) ;
V_11 [ V_69 + V_13 * 2 + 1 ] = ( T_9 ) ( V_73 & 0x00ff ) ;
V_70 += 5 ;
}
return TRUE ;
}
