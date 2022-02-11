static void F_1 ( struct V_1 * V_2 ,
void * V_3 , int V_4 )
{
char * * V_5 = V_3 ;
char * V_6 = * V_5 ;
char V_7 [] = L_1 ;
bool V_8 = F_2 ( V_2 , V_4 ) ;
unsigned long V_9 = ( unsigned long ) V_2 -> V_10 ;
if ( V_9 >= strlen ( V_6 ) )
V_6 = V_7 ;
else
V_6 = V_6 + V_9 ;
F_3 ( V_2 , V_8 ? V_11 :
V_12 ) ;
F_4 ( V_2 , V_6 , V_2 -> V_13 ) ;
}
static int F_5 ( struct V_1 * V_14 )
{
int V_15 ;
unsigned long V_9 ;
const char V_16 [] =
L_2
L_3
L_4
L_5
L_6 ;
if ( F_6 ( V_14 , L_7 , L_8 ) < 0 )
return - 1 ;
while ( 1 ) {
V_15 = F_7 ( V_14 , 0 ) ;
switch ( V_15 ) {
case V_17 :
V_9 = ( unsigned long ) V_14 -> V_10 ;
V_9 += 10 ;
V_14 -> V_10 = ( void * ) V_9 ;
continue;
case V_18 :
V_9 = ( unsigned long ) V_14 -> V_10 ;
if ( V_9 >= 10 )
V_9 -= 10 ;
V_14 -> V_10 = ( void * ) V_9 ;
continue;
case V_19 :
case 'h' :
case '?' :
F_8 ( V_14 , V_16 ) ;
continue;
case V_20 :
case 'q' :
case F_9 ( 'c' ) :
V_15 = - 1 ;
break;
default:
continue;
}
break;
}
F_10 ( V_14 ) ;
return V_15 ;
}
static int F_11 ( int V_21 , char * const V_22 [] )
{
struct V_1 V_14 = {
. V_23 = ( void * ) V_22 ,
. V_24 = V_25 ,
. V_26 = V_27 ,
. V_28 = F_1 ,
. V_29 = V_21 ,
} ;
return F_5 ( & V_14 ) ;
}
int F_12 ( struct V_30 * V_31 )
{
int V_32 , V_21 = 0 ;
char * * V_22 ;
struct V_33 * V_34 ;
char * V_35 , * V_36 ;
T_1 V_37 ;
T_2 * V_38 = F_13 ( & V_35 , & V_37 ) ;
V_34 = F_14 ( V_31 , struct V_33 , V_39 . V_31 ) ;
F_15 ( V_34 , V_38 , true ) ;
fclose ( V_38 ) ;
for ( V_36 = V_35 , V_21 = 0 ; ( V_36 = strchr ( V_36 , '\n' ) ) != NULL ; V_36 ++ )
V_21 ++ ;
V_22 = calloc ( V_21 + 1 , sizeof( * V_22 ) ) ;
if ( V_22 == NULL )
goto V_40;
V_22 [ 0 ] = V_36 = V_35 ;
for ( V_32 = 1 ; ( V_36 = strchr ( V_36 , '\n' ) ) != NULL ; V_32 ++ ) {
* V_36 ++ = '\0' ;
V_22 [ V_32 ] = V_36 ;
}
F_16 ( V_32 != V_21 + 1 ) ;
F_11 ( V_21 , V_22 ) ;
V_40:
free ( V_22 ) ;
free ( V_35 ) ;
return 0 ;
}
