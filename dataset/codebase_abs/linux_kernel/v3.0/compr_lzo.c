static void F_1 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
}
static int T_1 F_3 ( void )
{
V_1 = F_4 ( V_3 ) ;
V_2 = F_4 ( F_5 ( V_4 ) ) ;
if ( ! V_1 || ! V_2 ) {
F_6 ( V_5 L_1 ) ;
F_1 () ;
return - V_6 ;
}
return 0 ;
}
static int F_7 ( unsigned char * V_7 , unsigned char * V_8 ,
T_2 * V_9 , T_2 * V_10 )
{
T_3 V_11 ;
int V_12 ;
F_8 ( & V_13 ) ;
V_12 = F_9 ( V_7 , * V_9 , V_2 , & V_11 , V_1 ) ;
if ( V_12 != V_14 )
goto V_15;
if ( V_11 > * V_10 )
goto V_15;
memcpy ( V_8 , V_2 , V_11 ) ;
F_10 ( & V_13 ) ;
* V_10 = V_11 ;
return 0 ;
V_15:
F_10 ( & V_13 ) ;
return - 1 ;
}
static int F_11 ( unsigned char * V_7 , unsigned char * V_8 ,
T_2 V_16 , T_2 V_17 )
{
T_3 V_18 = V_17 ;
int V_12 ;
V_12 = F_12 ( V_7 , V_16 , V_8 , & V_18 ) ;
if ( V_12 != V_14 || V_18 != V_17 )
return - 1 ;
return 0 ;
}
int T_1 F_13 ( void )
{
int V_12 ;
V_12 = F_3 () ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_14 ( & V_19 ) ;
if ( V_12 )
F_1 () ;
return V_12 ;
}
void F_15 ( void )
{
F_16 ( & V_19 ) ;
F_1 () ;
}
