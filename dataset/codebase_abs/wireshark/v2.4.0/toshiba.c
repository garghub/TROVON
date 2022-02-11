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
T_6 F_7 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
if ( ! F_5 ( V_1 , V_2 , V_3 ) ) {
if ( * V_2 != 0 && * V_2 != V_18 )
return V_19 ;
return V_20 ;
}
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = 0 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_31 ;
return V_32 ;
}
static T_5 V_27 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_1 * V_33 )
{
T_1 V_34 ;
V_34 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_34 < 1 )
return FALSE ;
* V_33 = V_34 ;
return F_8 ( V_1 -> V_7 , & V_1 -> V_35 , V_1 -> V_36 ,
V_2 , V_3 ) ;
}
static T_5
V_29 ( T_2 * V_1 , T_1 V_37 ,
struct V_38 * V_35 , T_7 * V_11 ,
int * V_2 , T_3 * * V_3 )
{
if ( F_9 ( V_1 -> V_39 , V_37 - 1 , V_40 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_8 ( V_1 -> V_39 , V_35 , V_11 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_18 ;
return FALSE ;
}
return TRUE ;
}
static T_5
F_8 ( T_8 V_7 , struct V_38 * V_35 , T_7 * V_11 ,
int * V_2 , T_3 * * V_3 )
{
union V_41 * V_42 = & V_35 -> V_42 ;
char line [ V_12 ] ;
int V_43 ;
int V_44 , V_45 , V_46 , V_47 , V_48 , V_49 ;
char V_50 [ 10 ] , V_51 [ 10 ] ;
int V_13 , V_52 ;
T_9 * V_53 ;
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
V_43 = sscanf ( line , L_1 ,
& V_45 , & V_46 , & V_47 , & V_48 , & V_49 , V_50 , V_51 ) ;
if ( V_43 != 7 ) {
* V_2 = V_54 ;
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
V_43 = sscanf ( line + 64 , L_4 , & V_44 ) ;
if ( V_43 != 1 ) {
* V_2 = V_54 ;
* V_3 = F_10 ( L_5 ) ;
return FALSE ;
}
if ( V_44 < 0 ) {
* V_2 = V_54 ;
* V_3 = F_10 ( L_6 ) ;
return FALSE ;
}
if ( V_44 > V_55 ) {
* V_2 = V_54 ;
* V_3 = F_11 ( L_7 ,
V_44 , V_55 ) ;
return FALSE ;
}
V_35 -> V_56 = V_57 ;
V_35 -> V_58 = V_59 | V_60 ;
V_35 -> V_61 . V_62 = V_46 * 3600 + V_47 * 60 + V_48 ;
V_35 -> V_61 . V_63 = V_49 * 10000000 ;
V_35 -> V_64 = V_44 ;
V_35 -> V_65 = V_44 ;
switch ( V_50 [ 0 ] ) {
case 'B' :
V_35 -> V_66 = V_67 ;
V_42 -> V_68 . V_69 = ( V_51 [ 0 ] == 'T' ) ;
V_42 -> V_68 . V_50 = ( T_9 )
strtol ( & V_50 [ 1 ] , NULL , 10 ) ;
break;
case 'D' :
V_35 -> V_66 = V_67 ;
V_42 -> V_68 . V_69 = ( V_51 [ 0 ] == 'T' ) ;
V_42 -> V_68 . V_50 = 0 ;
break;
default:
V_35 -> V_66 = V_70 ;
V_42 -> V_71 . V_72 = - 1 ;
break;
}
F_12 ( V_11 , V_44 ) ;
V_53 = F_13 ( V_11 ) ;
V_52 = V_44 / 16 + ( ( V_44 % 16 ) ? 1 : 0 ) ;
for ( V_13 = 0 ; V_13 < V_52 ; V_13 ++ ) {
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
if ( ! F_14 ( line , V_53 , V_13 * 16 ) ) {
* V_2 = V_54 ;
* V_3 = F_10 ( L_8 ) ;
return FALSE ;
}
}
return TRUE ;
}
static T_5
F_14 ( char * V_73 , T_9 * V_11 , T_4 V_74 ) {
int V_75 , V_13 ;
char * V_76 ;
unsigned long V_77 ;
T_10 V_78 ;
V_73 [ 4 ] = '\0' ;
V_76 = V_73 ;
V_77 = strtoul ( V_76 , NULL , 16 ) ;
if ( V_77 != V_74 ) {
return FALSE ;
}
for ( V_75 = V_79 ; V_75 < V_79 + V_80 ; V_75 ++ ) {
if ( V_73 [ V_75 ] == ' ' ) {
V_73 [ V_75 ] = '0' ;
}
}
V_75 = V_79 ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
V_73 [ V_75 + 4 ] = '\0' ;
V_78 = ( T_10 ) strtoul ( & V_73 [ V_75 ] , NULL , 16 ) ;
V_11 [ V_74 + V_13 * 2 + 0 ] = ( T_9 ) ( V_78 >> 8 ) ;
V_11 [ V_74 + V_13 * 2 + 1 ] = ( T_9 ) ( V_78 & 0x00ff ) ;
V_75 += 5 ;
}
return TRUE ;
}
