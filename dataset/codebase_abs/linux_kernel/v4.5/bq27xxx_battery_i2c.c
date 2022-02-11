static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 ) ;
return V_5 ;
}
static int F_3 ( struct V_3 * V_4 , T_2 V_6 ,
bool V_7 )
{
struct V_8 * V_9 = F_4 ( V_4 -> V_10 ) ;
struct V_11 V_12 [ 2 ] ;
unsigned char V_2 [ 2 ] ;
int V_13 ;
if ( ! V_9 -> V_14 )
return - V_15 ;
V_12 [ 0 ] . V_16 = V_9 -> V_16 ;
V_12 [ 0 ] . V_17 = 0 ;
V_12 [ 0 ] . V_18 = & V_6 ;
V_12 [ 0 ] . V_19 = sizeof( V_6 ) ;
V_12 [ 1 ] . V_16 = V_9 -> V_16 ;
V_12 [ 1 ] . V_17 = V_20 ;
V_12 [ 1 ] . V_18 = V_2 ;
if ( V_7 )
V_12 [ 1 ] . V_19 = 1 ;
else
V_12 [ 1 ] . V_19 = 2 ;
V_13 = F_5 ( V_9 -> V_14 , V_12 , F_6 ( V_12 ) ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! V_7 )
V_13 = F_7 ( V_2 ) ;
else
V_13 = V_2 [ 0 ] ;
return V_13 ;
}
static int F_8 ( struct V_8 * V_9 ,
const struct V_21 * V_22 )
{
struct V_3 * V_4 ;
int V_13 ;
char * V_23 ;
int V_24 ;
F_9 ( & V_25 ) ;
V_24 = F_10 ( & V_26 , V_9 , 0 , 0 , V_27 ) ;
F_11 ( & V_25 ) ;
if ( V_24 < 0 )
return V_24 ;
V_23 = F_12 ( & V_9 -> V_10 , V_27 , L_1 , V_22 -> V_23 , V_24 ) ;
if ( ! V_23 )
goto V_28;
V_4 = F_13 ( & V_9 -> V_10 , sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
goto V_28;
V_4 -> V_22 = V_24 ;
V_4 -> V_10 = & V_9 -> V_10 ;
V_4 -> V_29 = V_22 -> V_30 ;
V_4 -> V_23 = V_23 ;
V_4 -> V_31 . V_32 = F_3 ;
V_13 = F_14 ( V_4 ) ;
if ( V_13 )
goto V_33;
F_15 ( & V_4 -> V_34 , 60 * V_35 ) ;
F_16 ( V_9 , V_4 ) ;
if ( V_9 -> V_1 ) {
V_13 = F_17 ( & V_9 -> V_10 , V_9 -> V_1 ,
NULL , F_1 ,
V_36 ,
V_4 -> V_23 , V_4 ) ;
if ( V_13 ) {
F_18 ( & V_9 -> V_10 ,
L_2 ,
V_9 -> V_1 , V_13 ) ;
return V_13 ;
}
}
return 0 ;
V_28:
V_13 = - V_37 ;
V_33:
F_9 ( & V_25 ) ;
F_19 ( & V_26 , V_24 ) ;
F_11 ( & V_25 ) ;
return V_13 ;
}
static int F_20 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_21 ( V_9 ) ;
F_22 ( V_4 ) ;
F_9 ( & V_25 ) ;
F_19 ( & V_26 , V_4 -> V_22 ) ;
F_11 ( & V_25 ) ;
return 0 ;
}
