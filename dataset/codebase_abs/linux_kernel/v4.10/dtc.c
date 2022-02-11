static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_1 * V_4 ;
const char * V_5 ;
V_2 -> V_6 = F_2 ( V_3 , V_2 -> V_7 ) ;
V_5 = strchr ( V_2 -> V_7 , '@' ) ;
if ( V_5 )
V_2 -> V_8 = V_5 - V_2 -> V_7 ;
else
V_2 -> V_8 = strlen ( V_2 -> V_7 ) ;
F_3 (tree, child)
F_1 ( V_4 , V_2 -> V_6 ) ;
}
static const char * F_4 ( const char * V_9 , const char * V_10 )
{
const char * V_11 ;
V_11 = strrchr ( V_9 , '.' ) ;
if ( V_11 == NULL )
return V_10 ;
if ( ! strcasecmp ( V_11 , L_1 ) )
return L_2 ;
if ( ! strcasecmp ( V_11 , L_3 ) )
return L_4 ;
return V_10 ;
}
static const char * F_5 ( const char * V_9 , const char * V_10 )
{
struct V_12 V_13 ;
T_1 V_14 ;
T_2 * V_15 ;
if ( V_12 ( V_9 , & V_13 ) != 0 )
return V_10 ;
if ( F_6 ( V_13 . V_16 ) )
return L_5 ;
if ( ! F_7 ( V_13 . V_16 ) )
return V_10 ;
V_15 = fopen ( V_9 , L_6 ) ;
if ( V_15 == NULL )
return V_10 ;
if ( fread ( & V_14 , 4 , 1 , V_15 ) != 1 ) {
fclose ( V_15 ) ;
return V_10 ;
}
fclose ( V_15 ) ;
V_14 = F_8 ( V_14 ) ;
if ( V_14 == V_17 )
return L_4 ;
return F_4 ( V_9 , V_10 ) ;
}
int main ( int V_18 , char * V_19 [] )
{
struct V_20 * V_21 ;
const char * V_22 = NULL ;
const char * V_23 = NULL ;
const char * V_24 = L_7 ;
const char * V_25 = NULL ;
bool V_26 = false , V_27 = false ;
const char * V_28 ;
int V_29 ;
T_2 * V_30 = NULL ;
int V_31 = V_32 ;
long long V_33 = - 1 ;
V_34 = 0 ;
V_35 = 0 ;
V_36 = 0 ;
V_37 = 0 ;
while ( ( V_29 = F_9 () ) != V_38 ) {
switch ( V_29 ) {
case 'I' :
V_22 = V_39 ;
break;
case 'O' :
V_23 = V_39 ;
break;
case 'o' :
V_24 = V_39 ;
break;
case 'V' :
V_31 = strtol ( V_39 , NULL , 0 ) ;
break;
case 'd' :
V_25 = V_39 ;
break;
case 'R' :
V_35 = strtol ( V_39 , NULL , 0 ) ;
break;
case 'S' :
V_36 = strtol ( V_39 , NULL , 0 ) ;
break;
case 'p' :
V_37 = strtol ( V_39 , NULL , 0 ) ;
break;
case 'f' :
V_26 = true ;
break;
case 'q' :
V_34 ++ ;
break;
case 'b' :
V_33 = strtoll ( V_39 , NULL , 0 ) ;
break;
case 'i' :
F_10 ( V_39 ) ;
break;
case 'v' :
F_11 () ;
case 'H' :
if ( F_12 ( V_39 , L_8 ) )
V_40 = V_41 ;
else if ( F_12 ( V_39 , L_9 ) )
V_40 = V_42 ;
else if ( F_12 ( V_39 , L_10 ) )
V_40 = V_43 ;
else
F_13 ( L_11 ,
V_39 ) ;
break;
case 's' :
V_27 = true ;
break;
case 'W' :
F_14 ( true , false , V_39 ) ;
break;
case 'E' :
F_14 ( false , true , V_39 ) ;
break;
case 'h' :
F_15 ( NULL ) ;
default:
F_15 ( L_12 ) ;
}
}
if ( V_18 > ( V_44 + 1 ) )
F_15 ( L_13 ) ;
else if ( V_18 < ( V_44 + 1 ) )
V_28 = L_7 ;
else
V_28 = V_19 [ V_44 ] ;
if ( V_36 && V_37 )
F_13 ( L_14 ) ;
if ( V_25 ) {
V_45 = fopen ( V_25 , L_15 ) ;
if ( ! V_45 )
F_13 ( L_16 , V_25 ,
strerror ( V_46 ) ) ;
fprintf ( V_45 , L_17 , V_24 ) ;
}
if ( V_22 == NULL )
V_22 = F_5 ( V_28 , L_2 ) ;
if ( V_23 == NULL ) {
V_23 = F_4 ( V_24 , NULL ) ;
if ( V_23 == NULL ) {
if ( F_12 ( V_22 , L_2 ) )
V_23 = L_4 ;
else
V_23 = L_2 ;
}
}
if ( F_12 ( V_22 , L_2 ) )
V_21 = F_16 ( V_28 ) ;
else if ( F_12 ( V_22 , L_5 ) )
V_21 = F_17 ( V_28 ) ;
else if( F_12 ( V_22 , L_4 ) )
V_21 = F_18 ( V_28 ) ;
else
F_13 ( L_18 , V_22 ) ;
if ( V_45 ) {
fputc ( '\n' , V_45 ) ;
fclose ( V_45 ) ;
}
if ( V_33 != - 1 )
V_21 -> V_47 = V_33 ;
F_1 ( V_21 -> V_48 , L_19 ) ;
F_19 ( V_26 , V_21 ) ;
if ( V_27 )
F_20 ( V_21 ) ;
if ( F_12 ( V_24 , L_7 ) ) {
V_30 = stdout ;
} else {
V_30 = fopen ( V_24 , L_20 ) ;
if ( ! V_30 )
F_13 ( L_21 ,
V_24 , strerror ( V_46 ) ) ;
}
if ( F_12 ( V_23 , L_2 ) ) {
F_21 ( V_30 , V_21 ) ;
} else if ( F_12 ( V_23 , L_4 ) ) {
F_22 ( V_30 , V_21 , V_31 ) ;
} else if ( F_12 ( V_23 , L_22 ) ) {
F_23 ( V_30 , V_21 , V_31 ) ;
} else if ( F_12 ( V_23 , L_23 ) ) {
} else {
F_13 ( L_24 , V_23 ) ;
}
exit ( 0 ) ;
}
