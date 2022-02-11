static T_1 F_1 ( struct V_1 * V_2 , struct V_3
* V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 ) ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int * V_6 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_4 ) ;
unsigned int V_13 = V_12 -> V_14 ;
unsigned int V_15 [ 4 ] ;
int V_16 ;
V_16 = F_6 ( V_10 -> V_17 ,
V_18 ,
V_13 , V_15 ) ;
if ( V_16 )
return V_16 ;
V_13 &= 0x7 ;
* V_6 = ( V_15 [ V_13 % 4 ] >> ( V_13 > 3 ? 14 : 2 ) ) & 0x3ff ;
return 0 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
unsigned V_6 ;
int V_16 = F_2 ( V_2 , V_4 , & V_6 ) ;
if ( V_16 )
return V_16 ;
V_6 = F_8 ( V_6 * 9 , 4 ) + 2400 ;
return sprintf ( V_5 , L_2 , V_6 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
unsigned V_6 ;
int V_16 = F_2 ( V_2 , V_4 , & V_6 ) ;
if ( V_16 )
return V_16 ;
V_6 = F_8 ( V_6 * 9 , 4 ) ;
return sprintf ( V_5 , L_2 , V_6 ) ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
unsigned V_19 = F_11 ( V_10 -> V_17 ) ;
return V_19 & V_20 ;
}
static int T_2 F_12 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_16 ;
V_10 = F_13 ( sizeof( * V_10 ) , V_21 ) ;
if ( ! V_10 )
return - V_22 ;
V_10 -> V_17 = F_14 ( V_8 -> V_2 . V_23 ) ;
F_15 ( V_8 , V_10 ) ;
V_16 = F_16 ( & V_8 -> V_2 . V_24 , & V_25 ) ;
if ( V_16 )
goto V_26;
if ( ! F_10 ( V_8 ) ) {
V_16 = F_16 ( & V_8 -> V_2 . V_24 , & V_27 ) ;
if ( V_16 )
goto V_28;
}
V_10 -> V_29 = F_17 ( & V_8 -> V_2 ) ;
if ( F_18 ( V_10 -> V_29 ) ) {
V_16 = F_19 ( V_10 -> V_29 ) ;
F_20 ( & V_8 -> V_2 ,
L_3 , V_16 ) ;
goto V_30;
}
return 0 ;
V_30:
if ( ! F_10 ( V_8 ) )
F_21 ( & V_8 -> V_2 . V_24 , & V_27 ) ;
V_28:
F_21 ( & V_8 -> V_2 . V_24 , & V_25 ) ;
V_26:
F_15 ( V_8 , NULL ) ;
F_22 ( V_10 ) ;
return V_16 ;
}
static int T_3 F_23 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
F_24 ( V_10 -> V_29 ) ;
if ( ! F_10 ( V_8 ) )
F_21 ( & V_8 -> V_2 . V_24 , & V_27 ) ;
F_21 ( & V_8 -> V_2 . V_24 , & V_25 ) ;
F_15 ( V_8 , NULL ) ;
F_22 ( V_10 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_31 , F_12 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_31 ) ;
}
