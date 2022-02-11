int F_1 ( const char * V_1 ,
unsigned int line ,
T_1 V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
struct V_5 V_6 ;
struct V_7 V_8 ;
char * V_9 ;
int V_10 ;
int V_11 ;
int V_12 = 0 ;
V_11 = F_2 ( & V_9 , L_1 , V_1 ) ;
if ( V_11 < 0 )
return - V_13 ;
V_10 = F_3 ( V_9 , 0 ) ;
if ( V_10 == - 1 ) {
V_11 = - V_14 ;
fprintf ( V_15 , L_2 , V_9 ) ;
goto V_16;
}
V_6 . V_17 = line ;
V_6 . V_2 = V_2 ;
V_6 . V_3 = V_3 ;
strcpy ( V_6 . V_18 , L_3 ) ;
V_11 = F_4 ( V_10 , V_19 , & V_6 ) ;
if ( V_11 == - 1 ) {
V_11 = - V_14 ;
fprintf ( V_15 , L_4
L_5 ,
V_11 ) ;
goto V_16;
}
V_11 = F_4 ( V_6 . V_10 , V_20 , & V_8 ) ;
if ( V_11 == - 1 ) {
V_11 = - V_14 ;
fprintf ( V_15 , L_6
L_7 ,
V_11 ) ;
goto V_16;
}
fprintf ( stdout , L_8 , line , V_1 ) ;
fprintf ( stdout , L_9 , V_8 . V_21 [ 0 ] ) ;
while ( 1 ) {
struct V_22 V_23 ;
V_11 = F_5 ( V_6 . V_10 , & V_23 , sizeof( V_23 ) ) ;
if ( V_11 == - 1 ) {
if ( V_14 == - V_24 ) {
fprintf ( V_15 , L_10 ) ;
continue;
} else {
V_11 = - V_14 ;
fprintf ( V_15 , L_11 ,
V_11 ) ;
break;
}
}
if ( V_11 != sizeof( V_23 ) ) {
fprintf ( V_15 , L_12 ) ;
V_11 = - V_25 ;
break;
}
fprintf ( stdout , L_13 V_26 L_14 , V_23 . V_27 ) ;
switch ( V_23 . V_28 ) {
case V_29 :
fprintf ( stdout , L_15 ) ;
break;
case V_30 :
fprintf ( stdout , L_16 ) ;
break;
default:
fprintf ( stdout , L_17 ) ;
}
fprintf ( stdout , L_18 ) ;
V_12 ++ ;
if ( V_12 == V_4 )
break;
}
V_16:
if ( F_6 ( V_10 ) == - 1 )
perror ( L_19 ) ;
free ( V_9 ) ;
return V_11 ;
}
void F_7 ( void )
{
fprintf ( V_15 , L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_18
L_30
L_31
) ;
}
int main ( int V_31 , char * * V_32 )
{
const char * V_1 = NULL ;
unsigned int line = - 1 ;
unsigned int V_4 = 0 ;
T_1 V_2 = V_33 ;
T_1 V_3 = 0 ;
int V_34 ;
while ( ( V_34 = F_8 ( V_31 , V_32 , L_32 ) ) != - 1 ) {
switch ( V_34 ) {
case 'c' :
V_4 = strtoul ( V_35 , NULL , 10 ) ;
break;
case 'n' :
V_1 = V_35 ;
break;
case 'o' :
line = strtoul ( V_35 , NULL , 10 ) ;
break;
case 'd' :
V_2 |= V_36 ;
break;
case 's' :
V_2 |= V_37 ;
break;
case 'r' :
V_3 |= V_38 ;
break;
case 'f' :
V_3 |= V_39 ;
break;
case '?' :
F_7 () ;
return - 1 ;
}
}
if ( ! V_1 || line == - 1 ) {
F_7 () ;
return - 1 ;
}
if ( ! V_3 ) {
printf ( L_33
L_34 ) ;
V_3 = V_40 ;
}
return F_1 ( V_1 , line , V_2 ,
V_3 , V_4 ) ;
}
