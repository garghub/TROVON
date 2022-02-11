static int T_1 F_1 ( unsigned long V_1 ,
const char * V_2 , int V_3 , void * V_4 )
{
if ( F_2 ( V_1 , V_5 ) ) {
T_2 V_6 ;
T_3 * V_7 = F_3 ( V_1 , L_1 , NULL ) ;
if ( F_4 ( ! V_7 ) )
return - V_8 ;
V_6 = F_5 ( V_7 ) ;
V_9 = V_10 ;
V_11 . V_12 = F_6 ( V_6 ) ;
F_7 ( & V_11 , 1 ) ;
V_13 = F_8 ( V_6 , V_14 ) ;
if ( F_4 ( ! V_13 ) )
return - V_15 ;
}
return 0 ;
}
void T_1 F_9 ( void )
{
if ( V_16 )
F_4 ( F_10 ( F_1 , NULL ) ) ;
}
static int T_1 F_11 ( unsigned long V_1 , const char * V_2 ,
int V_3 , void * V_4 )
{
static int V_17 = - 1 ;
static int V_18 = - 1 ;
if ( V_17 > V_3 && V_18 > 0 )
return V_18 ;
if ( V_18 < 0 && strcmp ( V_2 , L_2 ) == 0 )
V_18 = 0 ;
if ( V_18 >= 0 ) {
const char * V_19 = F_3 ( V_1 ,
L_3 , NULL ) ;
if ( V_19 && strcmp ( V_19 , L_4 ) == 0 )
V_18 ++ ;
}
V_17 = V_3 ;
return 0 ;
}
static void T_1 F_12 ( void )
{
int V_20 = 0 , V_21 ;
switch ( V_9 ) {
case V_22 :
V_20 = F_10 ( F_11 , NULL ) ;
break;
case V_10 :
V_20 = F_13 ( V_13 ) ;
break;
default:
F_4 ( 1 ) ;
break;
}
if ( V_20 < 2 )
return;
if ( V_20 > V_23 ) {
F_14 ( L_5 ,
V_20 , V_23 ) ;
V_20 = V_23 ;
}
for ( V_21 = 0 ; V_21 < V_20 ; ++ V_21 )
F_15 ( V_21 , true ) ;
}
static void T_1 F_16 ( unsigned int V_24 )
{
int V_21 ;
switch ( V_9 ) {
case V_22 :
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ )
F_17 ( V_21 , true ) ;
break;
case V_10 :
F_18 ( V_13 ) ;
break;
default:
F_4 ( 1 ) ;
break;
}
}
static void T_1 F_12 ( void )
{
F_4 ( 1 ) ;
}
void T_1 F_16 ( unsigned int V_24 )
{
F_4 ( 1 ) ;
}
static void T_1 F_19 ( void )
{
if ( V_25 )
V_25 -> V_26 () ;
else
F_12 () ;
}
static void T_1 F_20 ( unsigned int V_24 )
{
if ( V_25 )
V_25 -> V_27 ( V_24 ) ;
else
F_16 ( V_24 ) ;
F_21 ( F_22 ( V_28 ) ) ;
}
