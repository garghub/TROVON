static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 [ V_4 ] )
{
int V_5 ;
F_2 ( V_2 -> V_6 , L_1 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] , V_3 [ 4 ] ,
V_3 [ 5 ] , V_3 [ 6 ] , V_3 [ 7 ] , V_3 [ 8 ] ) ;
V_5 = F_3 ( V_2 -> V_6 , V_3 [ 0 ] , V_3 , V_4 ,
V_7 , V_8 ) ;
return V_5 < 0 ? V_5 : 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_3 [ V_4 ] = { 1 , 'n' , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( V_2 -> V_9 ) {
unsigned int V_10 = F_5 ( 255 , V_2 -> V_9 ) ;
V_3 [ 2 ] = F_5 ( F_6 ( V_2 -> V_11 ) , V_10 ) ;
V_3 [ 3 ] = F_5 ( F_7 ( V_2 -> V_11 ) , V_10 ) ;
V_3 [ 4 ] = F_5 ( F_8 ( V_2 -> V_11 ) , V_10 ) ;
}
if ( V_2 -> V_12 ) {
V_3 [ 1 ] = 'c' ;
V_3 [ 5 ] = ( V_2 -> V_12 & 0xFF00 ) >> 8 ;
V_3 [ 6 ] = ( V_2 -> V_12 & 0x00FF ) ;
}
return F_1 ( V_2 , V_3 ) ;
}
static void F_9 ( struct V_13 * V_14 ,
enum V_15 V_9 )
{
struct V_1 * V_2 = F_10 ( V_14 -> V_16 -> V_17 ) ;
V_2 -> V_9 = V_9 ;
if ( F_4 ( V_2 ) )
F_11 ( V_2 -> V_6 , L_2 ) ;
}
static enum V_15 F_12 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_10 ( V_14 -> V_16 -> V_17 ) ;
return V_2 -> V_9 ;
}
static T_2 F_13 ( struct V_18 * V_16 ,
struct V_19 * V_20 , char * V_3 )
{
struct V_1 * V_2 = F_10 ( V_16 -> V_17 ) ;
return sprintf ( V_3 , L_3 , V_2 -> V_11 ) ;
}
static T_2 F_14 ( struct V_18 * V_16 ,
struct V_19 * V_20 , const char * V_3 , T_3 V_21 )
{
struct V_1 * V_2 = F_10 ( V_16 -> V_17 ) ;
long unsigned int V_11 ;
int V_5 ;
V_5 = F_15 ( V_3 , 16 , & V_11 ) ;
if ( V_5 )
return V_5 ;
if ( V_11 > 0xFFFFFF )
return - V_22 ;
V_2 -> V_11 = V_11 ;
V_5 = F_4 ( V_2 ) ;
return V_5 ? V_5 : V_21 ;
}
static T_2 F_16 ( struct V_18 * V_16 ,
struct V_19 * V_20 , char * V_3 )
{
struct V_1 * V_2 = F_10 ( V_16 -> V_17 ) ;
return sprintf ( V_3 , L_4 , V_2 -> V_12 * 10 ) ;
}
static T_2 F_17 ( struct V_18 * V_16 ,
struct V_19 * V_20 , const char * V_3 , T_3 V_21 )
{
struct V_1 * V_2 = F_10 ( V_16 -> V_17 ) ;
long unsigned int V_12 ;
int V_5 ;
V_5 = F_15 ( V_3 , 10 , & V_12 ) ;
if ( V_5 )
return V_5 ;
V_12 = F_5 ( V_12 , 10 ) ;
if ( V_12 > 65535 )
return - V_22 ;
V_2 -> V_12 = V_12 ;
return V_21 ;
}
static T_2 F_18 ( struct V_18 * V_16 ,
struct V_19 * V_20 , char * V_3 )
{
struct V_1 * V_2 = F_10 ( V_16 -> V_17 ) ;
return sprintf ( V_3 , L_4 , V_2 -> V_23 ) ;
}
static T_2 F_19 ( struct V_18 * V_16 ,
struct V_19 * V_20 , const char * V_3 , T_3 V_21 )
{
struct V_1 * V_2 = F_10 ( V_16 -> V_17 ) ;
T_1 V_24 [ V_4 ] = { 1 , 'p' , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
long unsigned int V_23 ;
int V_5 ;
V_5 = F_15 ( V_3 , 10 , & V_23 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_23 = ! ! V_23 ;
V_24 [ 2 ] = V_2 -> V_23 ;
V_5 = F_1 ( V_2 , V_24 ) ;
return V_5 ? V_5 : V_21 ;
}
static int F_20 ( struct V_25 * V_6 , const struct V_26 * V_27 )
{
struct V_1 * V_2 ;
struct V_13 * V_28 ;
char V_29 [ 13 ] ;
int V_5 ;
V_2 = F_21 ( & V_6 -> V_16 , sizeof( struct V_1 ) , V_30 ) ;
if ( ! V_2 )
return - V_31 ;
F_22 ( V_6 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_11 = 0xFFFFFF ;
V_5 = F_23 ( V_6 ) ;
if ( V_5 )
goto error;
V_5 = F_24 ( V_6 , V_32 ) ;
if ( V_5 )
goto error;
V_28 = & V_2 -> V_14 ;
snprintf ( V_29 , sizeof( V_29 ) , L_5 , V_6 -> V_33 + 4 ) ;
V_28 -> V_34 = V_29 ;
V_28 -> V_35 = F_9 ;
V_28 -> V_36 = F_12 ;
V_5 = F_25 ( & V_6 -> V_16 , V_28 ) ;
if ( V_5 )
goto V_37;
V_5 = F_26 ( & V_28 -> V_16 -> V_38 , & V_39 ) ;
if ( V_5 )
goto V_40;
return 0 ;
V_40:
F_27 ( V_28 ) ;
V_37:
F_28 ( V_6 ) ;
error:
return V_5 ;
}
static void F_29 ( struct V_25 * V_6 )
{
struct V_1 * V_2 = F_30 ( V_6 ) ;
struct V_13 * V_28 = & V_2 -> V_14 ;
F_31 ( & V_28 -> V_16 -> V_38 , & V_39 ) ;
F_27 ( V_28 ) ;
F_28 ( V_6 ) ;
}
