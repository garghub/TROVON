static char *
F_1 ( const char * V_1 , const char * V_2 , char * V_3 , int V_4 , int V_5 )
{
int V_6 = 0 ;
int V_7 = 0 ;
int V_8 = 0 ;
const char * V_9 ;
if ( ! V_2 )
V_2 = V_1 + strlen ( V_1 ) ;
for ( V_9 = V_1 ; V_9 != V_2 ; V_9 ++ ) {
if ( V_6 == ( V_4 - 1 ) )
break;
switch ( * V_9 ) {
case 'L' :
if ( V_5 == V_10 || V_5 == V_11 ) {
if ( V_5 == V_11 ) {
if ( V_8 )
V_6 += F_2 ( V_3 + V_6 , V_4 - V_6 , L_1 ) ;
V_8 ++ ;
}
V_6 += F_2 ( V_3 + V_6 , V_4 - V_6 , L_2 ) ;
if ( V_5 == V_10 )
V_5 = V_12 ;
} else
V_3 [ V_6 ++ ] = * V_9 ;
break;
case 'B' :
case 'C' :
case 'D' :
case 'F' :
case 'I' :
case 'J' :
case 'S' :
case 'Z' :
if ( V_5 == V_13 ) {
if ( V_8 )
V_6 += F_2 ( V_3 + V_6 , V_4 - V_6 , L_1 ) ;
V_6 += F_2 ( V_3 + V_6 , V_4 - V_6 , L_3 , V_14 [ * V_9 - 'A' ] ) ;
while ( V_7 -- )
V_6 += F_2 ( V_3 + V_6 , V_4 - V_6 , L_4 ) ;
V_7 = 0 ;
V_8 ++ ;
} else
V_3 [ V_6 ++ ] = * V_9 ;
break;
case 'V' :
if ( V_5 == V_13 ) {
V_6 += F_2 ( V_3 + V_6 , V_4 - V_6 , L_5 ) ;
while ( V_7 -- )
V_6 += F_2 ( V_3 + V_6 , V_4 - V_6 , L_4 ) ;
V_7 = 0 ;
} else
V_3 [ V_6 ++ ] = * V_9 ;
break;
case '[' :
if ( V_5 != V_13 )
goto error;
V_7 ++ ;
break;
case '(' :
if ( V_5 != V_15 )
goto error;
V_3 [ V_6 ++ ] = * V_9 ;
V_5 = V_13 ;
break;
case ')' :
if ( V_5 != V_13 )
goto error;
V_3 [ V_6 ++ ] = * V_9 ;
V_8 = 0 ;
break;
case ';' :
if ( V_5 != V_12 && V_5 != V_11 )
goto error;
if ( isalpha ( * ( V_9 + 1 ) ) )
V_6 += F_2 ( V_3 + V_6 , V_4 - V_6 , L_6 ) ;
if ( V_5 == V_12 )
V_5 = V_15 ;
else if ( V_5 == V_11 )
V_5 = V_13 ;
break;
case '/' :
if ( V_5 != V_12 && V_5 != V_11 )
goto error;
V_6 += F_2 ( V_3 + V_6 , V_4 - V_6 , L_6 ) ;
break;
default :
V_3 [ V_6 ++ ] = * V_9 ;
}
}
V_3 [ V_6 ] = '\0' ;
return V_3 ;
error:
return NULL ;
}
char *
F_3 ( const char * V_1 , int V_16 )
{
char * V_3 , * V_17 ;
char * V_18 ;
T_1 V_19 , V_20 = 0 ;
if ( ! V_1 )
return NULL ;
V_18 = strrchr ( V_1 , ')' ) ;
if ( ! V_18 )
return NULL ;
V_19 = strlen ( V_1 ) * 3 + 1 ;
V_3 = malloc ( V_19 ) ;
if ( ! V_3 )
return NULL ;
V_3 [ 0 ] = '\0' ;
if ( ! ( V_16 & V_21 ) ) {
V_17 = F_1 ( V_18 + 1 , NULL , V_3 , V_19 , V_13 ) ;
if ( ! V_17 )
goto error;
V_20 = strlen ( V_3 ) ;
V_3 [ V_20 ++ ] = ' ' ;
}
V_17 = F_1 ( V_1 , V_18 + 1 , V_3 + V_20 , V_19 - V_20 , V_10 ) ;
if ( ! V_17 )
goto error;
return V_3 ;
error:
free ( V_3 ) ;
return NULL ;
}
