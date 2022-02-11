static int F_1 ( struct V_1 * V_2 , unsigned int type , unsigned int V_3 , int V_4 )
{
unsigned int V_5 = 0 ;
if ( type != V_6 )
return - 1 ;
switch ( V_3 ) {
case V_7 : if ( V_4 ) V_4 = 1000 ;
case V_8 : break;
default: return - 1 ;
}
if ( V_4 > 20 && V_4 < 32767 )
V_5 = 1193182 / V_4 ;
F_2 ( V_5 , - 1 ) ;
return 0 ;
}
static int T_1 F_3 ( struct V_9 * V_2 )
{
struct V_1 * V_1 ;
int V_10 ;
V_1 = F_4 () ;
if ( ! V_1 )
return - V_11 ;
V_1 -> V_12 = L_1 ;
V_1 -> V_13 = L_2 ;
V_1 -> V_14 . V_15 = V_16 ;
V_1 -> V_14 . V_17 = 0x001f ;
V_1 -> V_14 . V_18 = 0x0001 ;
V_1 -> V_14 . V_19 = 0x0100 ;
V_1 -> V_2 . V_20 = & V_2 -> V_2 ;
V_1 -> V_21 [ 0 ] = F_5 ( V_6 ) ;
V_1 -> V_22 [ 0 ] = F_5 ( V_7 ) | F_5 ( V_8 ) ;
V_1 -> V_23 = F_1 ;
V_10 = F_6 ( V_1 ) ;
if ( V_10 ) {
F_7 ( V_1 ) ;
return V_10 ;
}
F_8 ( V_2 , V_1 ) ;
return 0 ;
}
static int T_2 F_9 ( struct V_9 * V_2 )
{
struct V_1 * V_1 = F_10 ( V_2 ) ;
F_11 ( V_1 ) ;
F_8 ( V_2 , NULL ) ;
F_1 ( NULL , V_6 , V_7 , 0 ) ;
return 0 ;
}
static void F_12 ( struct V_9 * V_2 )
{
F_1 ( NULL , V_6 , V_7 , 0 ) ;
}
static int T_3 F_13 ( void )
{
int V_10 ;
if ( ! F_2 ) {
F_14 ( V_24 L_3 ) ;
return - V_25 ;
}
V_10 = F_15 ( & V_26 ) ;
if ( V_10 )
return V_10 ;
V_27 = F_16 ( L_4 , - 1 ) ;
if ( ! V_27 ) {
V_10 = - V_11 ;
goto V_28;
}
V_10 = F_17 ( V_27 ) ;
if ( V_10 )
goto V_29;
return 0 ;
V_29:
F_18 ( V_27 ) ;
V_28:
F_19 ( & V_26 ) ;
return V_10 ;
}
static void T_4 F_20 ( void )
{
F_21 ( V_27 ) ;
F_19 ( & V_26 ) ;
}
