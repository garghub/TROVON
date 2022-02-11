void T_1 F_1 ( void )
{
F_2 ( & V_1 , V_2 , V_3 ,
V_4 - V_3 ) ;
if ( V_5 )
F_3 () ;
else
F_4 () ;
if ( V_6 )
F_5 () ;
if ( V_7 )
F_6 () ;
F_7 () ;
if ( F_8 ( V_8 , V_9 , 0 , L_1 ,
V_9 ) )
F_9 ( L_2 ) ;
}
void F_10 ( struct V_10 * V_11 )
{
int V_12 = V_11 -> V_12 ;
int V_13 = F_11 ( V_12 ) ;
switch( V_13 ) {
case 1 :
case 2 :
case 7 :
if ( V_5 )
F_12 ( V_12 ) ;
else
F_13 ( V_12 ) ;
break;
case 3 :
case 4 :
case 5 :
case 6 :
if ( V_6 )
F_14 ( V_12 ) ;
else if ( V_5 )
F_12 ( V_12 ) ;
break;
case 8 :
if ( V_7 )
F_15 ( V_12 ) ;
break;
}
}
void F_16 ( struct V_10 * V_11 )
{
int V_12 = V_11 -> V_12 ;
int V_13 = F_11 ( V_12 ) ;
switch( V_13 ) {
case 1 :
case 2 :
case 7 :
if ( V_5 )
F_17 ( V_12 ) ;
else
F_18 ( V_12 ) ;
break;
case 3 :
case 4 :
case 5 :
case 6 :
if ( V_6 )
F_19 ( V_12 ) ;
else if ( V_5 )
F_17 ( V_12 ) ;
break;
case 8 :
if ( V_7 )
F_20 ( V_12 ) ;
break;
}
}
static unsigned int F_21 ( struct V_10 * V_11 )
{
int V_12 = V_11 -> V_12 ;
if ( F_11 ( V_12 ) == 7 && ! V_5 )
F_22 ( V_12 ) ;
else
F_10 ( V_11 ) ;
return 0 ;
}
static void F_23 ( struct V_10 * V_11 )
{
int V_12 = V_11 -> V_12 ;
if ( F_11 ( V_12 ) == 7 && ! V_5 )
F_24 ( V_12 ) ;
else
F_16 ( V_11 ) ;
}
T_2 V_9 ( int V_12 , void * V_14 )
{
if ( V_15 )
return V_16 ;
V_15 = 1 ;
F_25 ( L_3 ) ;
F_26 ( F_27 () ) ;
V_15 = 0 ;
return V_16 ;
}
