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
F_1 () ;
return - V_5 ;
}
return 0 ;
}
static int F_6 ( unsigned char * V_6 , unsigned char * V_7 ,
T_2 * V_8 , T_2 * V_9 )
{
T_3 V_10 ;
int V_11 ;
F_7 ( & V_12 ) ;
V_11 = F_8 ( V_6 , * V_8 , V_2 , & V_10 , V_1 ) ;
if ( V_11 != V_13 )
goto V_14;
if ( V_10 > * V_9 )
goto V_14;
memcpy ( V_7 , V_2 , V_10 ) ;
F_9 ( & V_12 ) ;
* V_9 = V_10 ;
return 0 ;
V_14:
F_9 ( & V_12 ) ;
return - 1 ;
}
static int F_10 ( unsigned char * V_6 , unsigned char * V_7 ,
T_2 V_15 , T_2 V_16 )
{
T_3 V_17 = V_16 ;
int V_11 ;
V_11 = F_11 ( V_6 , V_15 , V_7 , & V_17 ) ;
if ( V_11 != V_13 || V_17 != V_16 )
return - 1 ;
return 0 ;
}
int T_1 F_12 ( void )
{
int V_11 ;
V_11 = F_3 () ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_13 ( & V_18 ) ;
if ( V_11 )
F_1 () ;
return V_11 ;
}
void F_14 ( void )
{
F_15 ( & V_18 ) ;
F_1 () ;
}
