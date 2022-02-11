static int F_1 ( void )
{
short V_1 ;
char V_2 ;
V_1 = F_2 ( V_3 ) ;
if ( V_1 != V_4 ) {
F_3 ( V_5 L_1 ) ;
return V_6 ;
}
V_2 = F_4 ( V_7 ) ;
F_3 ( V_8 L_2 ,
V_2 ) ;
switch ( V_2 ) {
case 1 :
F_5 ( V_9 , V_10 ) ;
F_6 ( V_11 , V_12 ) ;
if ( F_2 ( V_3 ) != V_4 ) {
F_3 ( V_5 L_3 ) ;
return V_13 ;
}
break;
default:
F_3 ( V_14 L_4 ) ;
return V_15 ;
}
return 0 ;
}
bool F_7 ( void )
{
if ( ! F_8 () )
return false ;
if ( F_9 () )
return true ;
if ( V_16 == 0 )
return false ;
if ( V_16 & V_17 )
return false ;
if ( V_16 & V_18 )
return true ;
if ( V_16 & V_19 )
return true ;
return false ;
}
static bool F_10 ( int V_20 )
{
if ( F_11 () && ( V_16 & V_20 ) )
return true ;
return F_7 () ;
}
bool F_12 ( void )
{
return F_10 ( V_21 | V_18 ) ;
}
bool F_13 ( void )
{
return F_10 ( V_22 |
V_23 | V_18 ) ;
}
bool F_14 ( void )
{
if ( ! F_8 () )
return false ;
if ( F_9 () )
return false ;
if ( V_16 & V_19 )
return true ;
return false ;
}
void F_15 ( void )
{
int V_24 ;
if ( V_25 & V_17 )
return;
V_24 = F_1 () ;
if ( V_24 && ! ( V_24 == V_6 &&
( V_25 & V_19 ) ) )
return;
if ( ! V_25 ) {
if ( F_16 () ) {
F_3 ( V_26 L_5
L_6 ) ;
V_25 |= V_21 ;
}
if ( F_17 () ) {
F_3 ( V_26 L_7
L_8
L_9
L_10
L_11 ) ;
V_25 |= V_22 ;
}
}
if ( ! ( V_25 & V_19 ) )
F_5 ( V_25 , V_27 ) ;
V_16 = V_25 ;
}
static int T_1 F_18 ( char * V_28 )
{
char * V_29 , * V_30 ;
int V_31 ;
for ( V_29 = V_28 ; V_29 ; V_29 = V_30 ) {
V_30 = strchr ( V_29 , ',' ) ;
if ( V_30 ) {
V_31 = V_30 - V_29 ;
V_30 ++ ;
} else {
V_31 = strlen ( V_29 ) ;
}
if ( ! strncmp ( V_29 , L_12 , V_31 ) )
V_25 |= V_18 ;
else if ( ! strncmp ( V_29 , L_13 , V_31 ) )
V_25 |= V_22 ;
else if ( ! strncmp ( V_29 , L_14 , V_31 ) )
V_25 |= V_23 ;
else if ( ! strncmp ( V_29 , L_15 , V_31 ) )
V_25 |= V_21 ;
else if ( ! strncmp ( V_29 , L_16 , V_31 ) )
V_25 |= V_19 ;
else if ( ! strncmp ( V_29 , L_17 , V_31 ) )
V_25 |= V_17 ;
else
F_3 ( V_14 L_18
L_19 , V_29 ) ;
}
return 0 ;
}
