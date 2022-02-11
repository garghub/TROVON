static T_1 F_1 ( unsigned int V_1 , int V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 , V_2 ) ;
if ( V_5 )
return V_5 -> V_6 ;
return 0 ;
}
static void F_3 ( unsigned int V_7 , int V_2 , int V_3 )
{
T_1 V_8 = V_7 | F_4 ( V_2 ) | ( V_3 << 12 ) ;
int V_9 = F_5 () ;
if ( V_8 != V_10 ||
V_9 != V_11 ) {
V_10 = V_8 ;
V_11 = V_9 ;
F_6 ( V_12 , V_8 ) ;
}
}
static int F_7 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , int V_13 , int V_14 , T_1 * V_15 )
{
unsigned long V_16 ;
T_1 V_7 ;
if ( ( V_2 > 255 ) || ( V_3 > 255 ) || ( V_13 > 4095 ) ) {
V_17: * V_15 = - 1 ;
return - V_18 ;
}
V_7 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( ! V_7 )
goto V_17;
F_8 ( & V_19 , V_16 ) ;
F_3 ( V_7 , V_2 , V_3 ) ;
switch ( V_14 ) {
case 1 :
* V_15 = F_9 ( V_20 + V_13 ) ;
break;
case 2 :
* V_15 = F_10 ( V_20 + V_13 ) ;
break;
case 4 :
* V_15 = F_11 ( V_20 + V_13 ) ;
break;
}
F_12 ( & V_19 , V_16 ) ;
return 0 ;
}
static int F_13 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , int V_13 , int V_14 , T_1 V_15 )
{
unsigned long V_16 ;
T_1 V_7 ;
if ( ( V_2 > 255 ) || ( V_3 > 255 ) || ( V_13 > 4095 ) )
return - V_18 ;
V_7 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( ! V_7 )
return - V_18 ;
F_8 ( & V_19 , V_16 ) ;
F_3 ( V_7 , V_2 , V_3 ) ;
switch ( V_14 ) {
case 1 :
F_14 ( V_20 + V_13 , V_15 ) ;
break;
case 2 :
F_15 ( V_20 + V_13 , V_15 ) ;
break;
case 4 :
F_16 ( V_20 + V_13 , V_15 ) ;
break;
}
F_12 ( & V_19 , V_16 ) ;
return 0 ;
}
int T_2 F_17 ( void )
{
F_18 ( V_21 L_1 ) ;
V_22 = & V_23 ;
return 1 ;
}
void T_2 F_19 ( void )
{
}
