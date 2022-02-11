static int F_1 ( char * V_1 , const char * V_2 , T_1 args [] )
{
char * V_3 ;
int V_4 = 0 ;
if ( ! V_2 )
return 1 ;
while( 1 ) {
int V_5 = - 1 ;
V_3 = strchr ( V_2 , '%' ) ;
if ( ! V_3 )
return strcmp ( V_2 , V_1 ) == 0 ;
if ( strncmp ( V_2 , V_1 , V_3 - V_2 ) )
return 0 ;
V_1 += V_3 - V_2 ;
V_2 = V_3 + 1 ;
if ( isdigit ( * V_2 ) )
V_5 = F_2 ( V_2 , ( char * * ) & V_2 , 10 ) ;
else if ( * V_2 == '%' ) {
if ( * V_1 ++ != '%' )
return 0 ;
V_2 ++ ;
continue;
}
if ( V_4 >= V_6 )
return 0 ;
args [ V_4 ] . V_7 = V_1 ;
switch ( * V_2 ++ ) {
case 's' : {
T_2 V_8 = strlen ( V_1 ) ;
if ( V_8 == 0 )
return 0 ;
if ( V_5 == - 1 || V_5 > V_8 )
V_5 = V_8 ;
args [ V_4 ] . V_9 = V_1 + V_5 ;
break;
}
case 'd' :
F_3 ( V_1 , & args [ V_4 ] . V_9 , 0 ) ;
goto V_10;
case 'u' :
F_2 ( V_1 , & args [ V_4 ] . V_9 , 0 ) ;
goto V_10;
case 'o' :
F_2 ( V_1 , & args [ V_4 ] . V_9 , 8 ) ;
goto V_10;
case 'x' :
F_2 ( V_1 , & args [ V_4 ] . V_9 , 16 ) ;
V_10:
if ( args [ V_4 ] . V_9 == args [ V_4 ] . V_7 )
return 0 ;
break;
default:
return 0 ;
}
V_1 = args [ V_4 ] . V_9 ;
V_4 ++ ;
}
}
int F_4 ( char * V_1 , const T_3 V_11 , T_1 args [] )
{
const struct F_4 * V_2 ;
for ( V_2 = V_11 ; ! F_1 ( V_1 , V_2 -> V_12 , args ) ; V_2 ++ )
;
return V_2 -> V_13 ;
}
static int F_5 ( T_1 * V_1 , int * V_14 , int V_15 )
{
char * V_16 ;
char * V_17 ;
int V_18 ;
long V_19 ;
T_2 V_5 = V_1 -> V_9 - V_1 -> V_7 ;
V_17 = F_6 ( V_5 + 1 , V_20 ) ;
if ( ! V_17 )
return - V_21 ;
memcpy ( V_17 , V_1 -> V_7 , V_5 ) ;
V_17 [ V_5 ] = '\0' ;
V_18 = 0 ;
V_19 = F_3 ( V_17 , & V_16 , V_15 ) ;
if ( V_16 == V_17 )
V_18 = - V_22 ;
else if ( V_19 < ( long ) V_23 || V_19 > ( long ) V_24 )
V_18 = - V_25 ;
else
* V_14 = ( int ) V_19 ;
F_7 ( V_17 ) ;
return V_18 ;
}
static int F_8 ( T_1 * V_1 , T_4 * V_14 , int V_15 )
{
char * V_17 ;
int V_18 ;
T_4 V_19 ;
T_2 V_5 = V_1 -> V_9 - V_1 -> V_7 ;
V_17 = F_6 ( V_5 + 1 , V_20 ) ;
if ( ! V_17 )
return - V_21 ;
memcpy ( V_17 , V_1 -> V_7 , V_5 ) ;
V_17 [ V_5 ] = '\0' ;
V_18 = F_9 ( V_17 , V_15 , & V_19 ) ;
if ( ! V_18 )
* V_14 = V_19 ;
F_7 ( V_17 ) ;
return V_18 ;
}
int F_10 ( T_1 * V_1 , int * V_14 )
{
return F_5 ( V_1 , V_14 , 0 ) ;
}
int F_11 ( T_1 * V_1 , T_4 * V_14 )
{
return F_8 ( V_1 , V_14 , 0 ) ;
}
int F_12 ( T_1 * V_1 , int * V_14 )
{
return F_5 ( V_1 , V_14 , 8 ) ;
}
int F_13 ( T_1 * V_1 , int * V_14 )
{
return F_5 ( V_1 , V_14 , 16 ) ;
}
bool F_14 ( const char * V_12 , const char * V_26 )
{
const char * V_1 = V_26 ;
const char * V_2 = V_12 ;
bool V_27 = false ;
while ( * V_1 ) {
switch ( * V_2 ) {
case '?' :
V_1 ++ ;
V_2 ++ ;
break;
case '*' :
V_27 = true ;
V_26 = V_1 ;
if ( ! * ++ V_2 )
return true ;
V_12 = V_2 ;
break;
default:
if ( * V_1 == * V_2 ) {
V_1 ++ ;
V_2 ++ ;
} else {
if ( ! V_27 )
return false ;
V_26 ++ ;
V_1 = V_26 ;
V_2 = V_12 ;
}
break;
}
}
if ( * V_2 == '*' )
++ V_2 ;
return ! * V_2 ;
}
T_2 F_15 ( char * V_28 , const T_1 * V_29 , T_2 V_30 )
{
T_2 V_18 = V_29 -> V_9 - V_29 -> V_7 ;
if ( V_30 ) {
T_2 V_5 = V_18 >= V_30 ? V_30 - 1 : V_18 ;
memcpy ( V_28 , V_29 -> V_7 , V_5 ) ;
V_28 [ V_5 ] = '\0' ;
}
return V_18 ;
}
char * F_16 ( const T_1 * V_1 )
{
T_2 V_31 = V_1 -> V_9 - V_1 -> V_7 + 1 ;
char * V_2 = F_6 ( V_31 , V_20 ) ;
if ( V_2 )
F_15 ( V_2 , V_1 , V_31 ) ;
return V_2 ;
}
