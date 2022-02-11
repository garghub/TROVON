static int F_1 ( int V_1 )
{
return ( V_1 > 0 ) && ( ( V_1 & ( V_1 - 1 ) ) == 0 ) ;
}
static void F_2 ( struct V_2 * V_3 , const char * V_4 )
{
struct V_2 * V_5 ;
const char * V_6 ;
V_3 -> V_7 = F_3 ( V_4 , V_3 -> V_8 ) ;
V_6 = strchr ( V_3 -> V_8 , '@' ) ;
if ( V_6 )
V_3 -> V_9 = V_6 - V_3 -> V_8 ;
else
V_3 -> V_9 = strlen ( V_3 -> V_8 ) ;
F_4 (tree, child)
F_2 ( V_5 , V_3 -> V_7 ) ;
}
static const char * F_5 ( const char * V_10 , const char * V_11 )
{
const char * V_12 ;
V_12 = strrchr ( V_10 , '.' ) ;
if ( V_12 == NULL )
return V_11 ;
if ( ! strcasecmp ( V_12 , L_1 ) )
return L_2 ;
if ( ! strcasecmp ( V_12 , L_3 ) )
return L_4 ;
return V_11 ;
}
static const char * F_6 ( const char * V_10 , const char * V_11 )
{
struct V_13 V_14 ;
T_1 V_15 ;
T_2 * V_16 ;
if ( V_13 ( V_10 , & V_14 ) != 0 )
return V_11 ;
if ( F_7 ( V_14 . V_17 ) )
return L_5 ;
if ( ! F_8 ( V_14 . V_17 ) )
return V_11 ;
V_16 = fopen ( V_10 , L_6 ) ;
if ( V_16 == NULL )
return V_11 ;
if ( fread ( & V_15 , 4 , 1 , V_16 ) != 1 ) {
fclose ( V_16 ) ;
return V_11 ;
}
fclose ( V_16 ) ;
V_15 = F_9 ( V_15 ) ;
if ( V_15 == V_18 )
return L_4 ;
return F_5 ( V_10 , V_11 ) ;
}
int main ( int V_19 , char * V_20 [] )
{
struct V_21 * V_22 ;
const char * V_23 = NULL ;
const char * V_24 = NULL ;
const char * V_25 = L_7 ;
const char * V_26 = NULL ;
bool V_27 = false , V_28 = false ;
const char * V_29 ;
int V_30 ;
T_2 * V_31 = NULL ;
int V_32 = V_33 ;
long long V_34 = - 1 ;
V_35 = 0 ;
V_36 = 0 ;
V_37 = 0 ;
V_38 = 0 ;
V_39 = 0 ;
while ( ( V_30 = F_10 () ) != V_40 ) {
switch ( V_30 ) {
case 'I' :
V_23 = V_41 ;
break;
case 'O' :
V_24 = V_41 ;
break;
case 'o' :
V_25 = V_41 ;
break;
case 'V' :
V_32 = strtol ( V_41 , NULL , 0 ) ;
break;
case 'd' :
V_26 = V_41 ;
break;
case 'R' :
V_36 = strtol ( V_41 , NULL , 0 ) ;
break;
case 'S' :
V_37 = strtol ( V_41 , NULL , 0 ) ;
break;
case 'p' :
V_38 = strtol ( V_41 , NULL , 0 ) ;
break;
case 'a' :
V_39 = strtol ( V_41 , NULL , 0 ) ;
if ( ! F_1 ( V_39 ) )
F_11 ( L_8 ,
V_41 ) ;
break;
case 'f' :
V_27 = true ;
break;
case 'q' :
V_35 ++ ;
break;
case 'b' :
V_34 = strtoll ( V_41 , NULL , 0 ) ;
break;
case 'i' :
F_12 ( V_41 ) ;
break;
case 'v' :
F_13 () ;
case 'H' :
if ( F_14 ( V_41 , L_9 ) )
V_42 = V_43 ;
else if ( F_14 ( V_41 , L_10 ) )
V_42 = V_44 ;
else if ( F_14 ( V_41 , L_11 ) )
V_42 = V_45 ;
else
F_11 ( L_12 ,
V_41 ) ;
break;
case 's' :
V_28 = true ;
break;
case 'W' :
F_15 ( true , false , V_41 ) ;
break;
case 'E' :
F_15 ( false , true , V_41 ) ;
break;
case '@' :
V_46 = 1 ;
break;
case 'A' :
V_47 = 1 ;
break;
case 'h' :
F_16 ( NULL ) ;
default:
F_16 ( L_13 ) ;
}
}
if ( V_19 > ( V_48 + 1 ) )
F_16 ( L_14 ) ;
else if ( V_19 < ( V_48 + 1 ) )
V_29 = L_7 ;
else
V_29 = V_20 [ V_48 ] ;
if ( V_37 && V_38 )
F_11 ( L_15 ) ;
if ( V_26 ) {
V_49 = fopen ( V_26 , L_16 ) ;
if ( ! V_49 )
F_11 ( L_17 , V_26 ,
strerror ( V_50 ) ) ;
fprintf ( V_49 , L_18 , V_25 ) ;
}
if ( V_23 == NULL )
V_23 = F_6 ( V_29 , L_2 ) ;
if ( V_24 == NULL ) {
V_24 = F_5 ( V_25 , NULL ) ;
if ( V_24 == NULL ) {
if ( F_14 ( V_23 , L_2 ) )
V_24 = L_4 ;
else
V_24 = L_2 ;
}
}
if ( F_14 ( V_23 , L_2 ) )
V_22 = F_17 ( V_29 ) ;
else if ( F_14 ( V_23 , L_5 ) )
V_22 = F_18 ( V_29 ) ;
else if( F_14 ( V_23 , L_4 ) )
V_22 = F_19 ( V_29 ) ;
else
F_11 ( L_19 , V_23 ) ;
if ( V_49 ) {
fputc ( '\n' , V_49 ) ;
fclose ( V_49 ) ;
}
if ( V_34 != - 1 )
V_22 -> V_51 = V_34 ;
F_2 ( V_22 -> V_52 , L_20 ) ;
F_20 ( V_27 , V_22 ) ;
if ( V_22 -> V_53 & V_54 ) {
V_55 = 1 ;
}
if ( V_47 )
F_21 ( V_22 , L_21 , false ) ;
if ( V_46 )
F_21 ( V_22 , L_22 , true ) ;
if ( V_55 ) {
F_22 ( V_22 , L_23 ) ;
F_23 ( V_22 , L_24 ) ;
}
if ( V_28 )
F_24 ( V_22 ) ;
if ( F_14 ( V_25 , L_7 ) ) {
V_31 = stdout ;
} else {
V_31 = fopen ( V_25 , L_25 ) ;
if ( ! V_31 )
F_11 ( L_26 ,
V_25 , strerror ( V_50 ) ) ;
}
if ( F_14 ( V_24 , L_2 ) ) {
F_25 ( V_31 , V_22 ) ;
} else if ( F_14 ( V_24 , L_4 ) ) {
F_26 ( V_31 , V_22 , V_32 ) ;
} else if ( F_14 ( V_24 , L_27 ) ) {
F_27 ( V_31 , V_22 , V_32 ) ;
} else if ( F_14 ( V_24 , L_28 ) ) {
} else {
F_11 ( L_29 , V_24 ) ;
}
exit ( 0 ) ;
}
