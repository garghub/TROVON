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
void F_7 ( void )
{
int V_16 ;
if ( V_17 & V_18 )
return;
V_16 = F_1 () ;
if ( V_16 && ! ( V_16 == V_6 &&
( V_17 & V_19 ) ) )
return;
if ( ! V_17 ) {
if ( F_8 () ) {
F_3 ( V_20 L_5
L_6 ) ;
V_17 |= V_21 ;
}
if ( F_9 () ) {
F_3 ( V_20 L_7
L_8
L_9
L_10
L_11 ) ;
V_17 |= V_22 ;
}
}
if ( ! ( V_17 & V_19 ) )
F_5 ( V_17 , V_23 ) ;
V_24 = V_17 ;
}
static int T_1 F_10 ( char * V_25 )
{
char * V_26 , * V_27 ;
int V_28 ;
for ( V_26 = V_25 ; V_26 ; V_26 = V_27 ) {
V_27 = strchr ( V_26 , ',' ) ;
if ( V_27 ) {
V_28 = V_27 - V_26 ;
V_27 ++ ;
} else {
V_28 = strlen ( V_26 ) ;
}
if ( ! strncmp ( V_26 , L_12 , V_28 ) )
V_17 |= V_29 ;
else if ( ! strncmp ( V_26 , L_13 , V_28 ) )
V_17 |= V_22 ;
else if ( ! strncmp ( V_26 , L_14 , V_28 ) )
V_17 |= V_30 ;
else if ( ! strncmp ( V_26 , L_15 , V_28 ) )
V_17 |= V_21 ;
else if ( ! strncmp ( V_26 , L_16 , V_28 ) )
V_17 |= V_19 ;
else if ( ! strncmp ( V_26 , L_17 , V_28 ) )
V_17 |= V_18 ;
else
F_3 ( V_14 L_18
L_19 , V_26 ) ;
}
return 0 ;
}
