void F_1 ( unsigned long V_1 )
{
int V_2 ;
int V_3 = 0 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_4 ) ; V_2 ++ ) {
if ( V_1 & V_4 [ V_2 ] . V_5 ) {
if ( V_3 )
fprintf ( stdout , L_1 ) ;
fprintf ( stdout , L_2 , V_4 [ V_2 ] . V_6 ) ;
V_3 ++ ;
}
}
}
int F_3 ( const char * V_7 )
{
struct V_8 V_9 ;
char * V_10 ;
int V_11 ;
int V_12 ;
int V_2 ;
V_12 = F_4 ( & V_10 , L_3 , V_7 ) ;
if ( V_12 < 0 )
return - V_13 ;
V_11 = F_5 ( V_10 , 0 ) ;
if ( V_11 == - 1 ) {
V_12 = - V_14 ;
fprintf ( V_15 , L_4 , V_10 ) ;
goto V_16;
}
V_12 = F_6 ( V_11 , V_17 , & V_9 ) ;
if ( V_12 == - 1 ) {
V_12 = - V_14 ;
perror ( L_5 ) ;
goto V_16;
}
fprintf ( stdout , L_6 ,
V_9 . V_6 , V_9 . V_18 , V_9 . V_19 ) ;
for ( V_2 = 0 ; V_2 < V_9 . V_19 ; V_2 ++ ) {
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_22 = V_2 ;
V_12 = F_6 ( V_11 , V_23 , & V_21 ) ;
if ( V_12 == - 1 ) {
V_12 = - V_14 ;
perror ( L_7 ) ;
goto V_16;
}
fprintf ( stdout , L_8 , V_21 . V_22 ) ;
if ( V_21 . V_6 [ 0 ] )
fprintf ( stdout , L_9 , V_21 . V_6 ) ;
else
fprintf ( stdout , L_10 ) ;
if ( V_21 . V_24 [ 0 ] )
fprintf ( stdout , L_9 , V_21 . V_24 ) ;
else
fprintf ( stdout , L_11 ) ;
if ( V_21 . V_1 ) {
fprintf ( stdout , L_12 ) ;
F_1 ( V_21 . V_1 ) ;
fprintf ( stdout , L_13 ) ;
}
fprintf ( stdout , L_14 ) ;
}
V_16:
if ( F_7 ( V_11 ) == - 1 )
perror ( L_15 ) ;
free ( V_10 ) ;
return V_12 ;
}
void F_8 ( void )
{
fprintf ( V_15 , L_16
L_17
L_18
L_19
) ;
}
int main ( int V_25 , char * * V_26 )
{
const char * V_7 = NULL ;
int V_12 ;
int V_27 ;
while ( ( V_27 = F_9 ( V_25 , V_26 , L_20 ) ) != - 1 ) {
switch ( V_27 ) {
case 'n' :
V_7 = V_28 ;
break;
case '?' :
F_8 () ;
return - 1 ;
}
}
if ( V_7 )
V_12 = F_3 ( V_7 ) ;
else {
const struct V_29 * V_30 ;
T_1 * V_31 ;
V_31 = F_10 ( L_21 ) ;
if ( ! V_31 ) {
V_12 = - V_14 ;
goto V_32;
}
V_12 = - V_33 ;
while ( V_30 = F_11 ( V_31 ) , V_30 ) {
if ( F_12 ( V_30 -> V_34 , L_22 ) ) {
V_12 = F_3 ( V_30 -> V_34 ) ;
if ( V_12 )
break;
}
}
V_12 = 0 ;
if ( F_13 ( V_31 ) == - 1 ) {
perror ( L_23 ) ;
V_12 = - V_14 ;
}
}
V_32:
return V_12 ;
}
