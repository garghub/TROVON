static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = V_3 ;
V_9 -> V_11 [ 1 ] = V_4 ;
V_5 = F_5 ( V_9 -> V_12 , V_9 -> V_11 , 2 ) ;
F_6 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = V_13 | V_3 ;
if ( V_9 -> V_14 )
V_5 = F_8 ( V_9 -> V_12 , V_9 -> V_11 , 4 ) ;
else
V_5 = F_8 ( V_9 -> V_12 , V_9 -> V_11 , 3 ) ;
if ( V_5 == 0 ) {
if ( V_9 -> V_14 )
* V_4 = ( V_9 -> V_11 [ 1 ] << 16 ) |
( V_9 -> V_11 [ 2 ] << 8 ) |
V_9 -> V_11 [ 3 ] ;
else
* V_4 = ( V_9 -> V_11 [ 1 ] << 8 ) | V_9 -> V_11 [ 2 ] ;
}
F_6 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static T_3 F_9 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_11 )
{
struct V_17 * V_18 = F_10 ( V_16 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_4 ;
T_3 V_5 ;
F_4 ( & V_7 -> V_19 ) ;
V_5 = F_7 ( V_2 , V_18 -> V_20 , & V_4 ) ;
F_6 ( & V_7 -> V_19 ) ;
if ( V_5 == 0 )
return sprintf ( V_11 , L_1 , V_4 ) ;
else
return V_5 ;
}
static T_3 F_11 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_14 == 1 )
return sprintf ( V_11 , L_2 ) ;
else
return sprintf ( V_11 , L_3 ) ;
}
static T_3 F_12 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_11 ,
T_4 V_21 )
{
int V_5 ;
T_1 V_4 ;
if ( F_13 ( V_11 , L_4 ) )
V_4 = 0 ;
else if ( F_13 ( V_11 , L_5 ) )
V_4 = 1 ;
else
return - V_22 ;
V_5 = F_1 ( V_2 , V_23 , V_4 ) ;
return V_5 ? V_5 : V_21 ;
}
static int T_5 F_14 ( struct V_24 * V_25 )
{
int V_5 ;
struct V_8 * V_9 = F_15 ( sizeof *V_9 , V_26 ) ;
if ( ! V_9 ) {
V_5 = - V_27 ;
goto V_28;
}
F_16 ( V_25 , V_9 ) ;
V_9 -> V_12 = V_25 ;
F_17 ( & V_9 -> V_10 ) ;
V_9 -> V_7 = F_18 ( 0 ) ;
if ( V_9 -> V_7 == NULL ) {
V_5 = - V_27 ;
goto V_29;
}
V_9 -> V_7 -> V_30 = V_25 -> V_2 . V_31 -> V_30 ;
V_9 -> V_7 -> V_2 . V_32 = & V_25 -> V_2 ;
V_9 -> V_7 -> V_33 = & V_34 ;
V_9 -> V_7 -> V_35 = ( void * ) ( V_9 ) ;
V_9 -> V_7 -> V_36 = V_37 ;
V_9 -> V_14 = 1 ;
V_5 = F_19 ( V_9 -> V_7 ) ;
if ( V_5 )
goto V_38;
return 0 ;
V_38:
F_20 ( V_9 -> V_7 ) ;
V_29:
F_21 ( V_9 ) ;
V_28:
return V_5 ;
}
static int F_22 ( struct V_24 * V_25 )
{
struct V_8 * V_9 = F_23 ( V_25 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
F_24 ( V_7 ) ;
F_21 ( V_9 ) ;
return 0 ;
}
static T_6 int F_25 ( void )
{
return F_26 ( & V_39 ) ;
}
static T_7 void F_27 ( void )
{
F_28 ( & V_39 ) ;
}
