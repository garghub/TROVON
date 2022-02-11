static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_4 ( & V_8 -> V_9 ) ;
V_8 -> V_10 [ 2 ] = V_3 ;
V_4 = F_5 ( V_8 -> V_11 , V_8 -> V_10 , 3 ) ;
F_6 ( & V_8 -> V_9 ) ;
return V_4 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_2 * V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_4 ( & V_8 -> V_9 ) ;
V_4 = F_8 ( V_8 -> V_12 , V_8 -> V_10 , 3 ) ;
if ( V_4 == 0 )
* V_3 = ( ( V_8 -> V_10 [ 0 ] & 0x3 ) << 12 ) |
( V_8 -> V_10 [ 1 ] << 4 ) |
( ( V_8 -> V_10 [ 2 ] >> 4 ) & 0xF ) ;
F_6 ( & V_8 -> V_9 ) ;
return V_4 ;
}
static T_3 F_9 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
char * V_10 )
{
struct V_15 * V_16 = F_10 ( V_14 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_3 = 0 ;
T_3 V_4 ;
F_4 ( & V_6 -> V_17 ) ;
V_4 = F_1 ( V_2 , V_16 -> V_18 ) ;
if ( V_4 < 0 )
goto V_19;
V_4 = F_7 ( V_2 , & V_3 ) ;
V_19:
F_6 ( & V_6 -> V_17 ) ;
if ( V_4 == 0 )
return sprintf ( V_10 , L_1 , V_3 ) ;
else
return V_4 ;
}
static int T_4 F_11 ( struct V_20 * V_21 )
{
int V_4 , V_22 = 0 ;
struct V_7 * V_8 = F_12 ( sizeof *V_8 , V_23 ) ;
if ( ! V_8 ) {
V_4 = - V_24 ;
goto V_19;
}
F_13 ( V_21 , V_8 ) ;
V_8 -> V_12 = V_21 ;
F_14 ( & V_8 -> V_9 ) ;
V_8 -> V_6 = F_15 ( 0 ) ;
if ( V_8 -> V_6 == NULL ) {
V_4 = - V_24 ;
goto V_25;
}
V_8 -> V_6 -> V_2 . V_26 = & V_21 -> V_2 ;
V_8 -> V_6 -> V_27 = & V_28 ;
V_8 -> V_6 -> V_29 = ( void * ) ( V_8 ) ;
V_8 -> V_6 -> V_30 = V_31 ;
V_4 = F_16 ( V_8 -> V_6 ) ;
if ( V_4 )
goto V_32;
V_22 = 1 ;
V_33 = V_8 ;
return 0 ;
V_32:
if ( V_22 )
F_17 ( V_8 -> V_6 ) ;
else
F_18 ( V_8 -> V_6 ) ;
V_25:
F_19 ( V_8 ) ;
V_19:
return V_4 ;
}
static int F_20 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_21 ( V_21 ) ;
struct V_5 * V_6 = V_8 -> V_6 ;
F_17 ( V_6 ) ;
F_19 ( V_8 ) ;
return 0 ;
}
static int T_4 F_22 ( struct V_20 * V_21 )
{
int V_4 ;
struct V_7 * V_8 = V_33 ;
if ( ! V_8 ) {
V_4 = - V_34 ;
goto V_19;
}
F_13 ( V_21 , V_8 ) ;
V_8 -> V_11 = V_21 ;
return 0 ;
V_19:
return V_4 ;
}
static int F_23 ( struct V_20 * V_21 )
{
return 0 ;
}
static T_5 int F_24 ( void )
{
int V_4 ;
V_4 = F_25 ( & V_35 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_25 ( & V_36 ) ;
if ( V_4 < 0 ) {
F_26 ( & V_35 ) ;
return V_4 ;
}
return 0 ;
}
static T_6 void F_27 ( void )
{
F_26 ( & V_36 ) ;
F_26 ( & V_35 ) ;
}
