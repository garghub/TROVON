static inline char T_1 * F_1 ( unsigned int V_1 , unsigned int V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 , V_2 ) ;
if ( V_5 && V_5 -> V_6 )
return V_5 -> V_6 + ( F_3 ( V_2 ) | ( V_3 << 12 ) ) ;
return NULL ;
}
static int F_4 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , int V_7 , int V_8 , T_2 * V_9 )
{
char T_1 * V_10 ;
if ( F_5 ( ( V_2 > 255 ) || ( V_3 > 255 ) || ( V_7 > 4095 ) ) ) {
V_11: * V_9 = - 1 ;
return - V_12 ;
}
if ( F_5 ( V_2 == 0 && V_3 >= V_13 ) ) {
* V_9 = - 1 ;
return 0 ;
}
F_6 () ;
V_10 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( ! V_10 ) {
F_7 () ;
goto V_11;
}
switch ( V_8 ) {
case 1 :
* V_9 = F_8 ( V_10 + V_7 ) ;
break;
case 2 :
* V_9 = F_9 ( V_10 + V_7 ) ;
break;
case 4 :
* V_9 = F_10 ( V_10 + V_7 ) ;
break;
}
F_7 () ;
return 0 ;
}
static int F_11 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , int V_7 , int V_8 , T_2 V_9 )
{
char T_1 * V_10 ;
if ( F_5 ( ( V_2 > 255 ) || ( V_3 > 255 ) || ( V_7 > 4095 ) ) )
return - V_12 ;
if ( F_5 ( V_2 == 0 && V_3 >= V_13 ) )
return 0 ;
F_6 () ;
V_10 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( ! V_10 ) {
F_7 () ;
return - V_12 ;
}
switch ( V_8 ) {
case 1 :
F_12 ( V_10 + V_7 , V_9 ) ;
break;
case 2 :
F_13 ( V_10 + V_7 , V_9 ) ;
break;
case 4 :
F_14 ( V_10 + V_7 , V_9 ) ;
break;
}
F_7 () ;
return 0 ;
}
int T_3 F_15 ( void )
{
int V_14 = 0 ;
T_2 V_15 ;
V_14 = F_16 ( 0 , 0 , F_17 ( 0x18 , 0 ) , 0x60 , sizeof( V_15 ) , & V_15 ) ;
if ( V_14 )
goto V_16;
V_13 = F_17 ( 0x18 + ( ( V_15 >> 4 ) & 7 ) + 1 , 0 ) ;
V_17 = V_18 = & V_19 ;
V_16:
return V_14 ;
}
