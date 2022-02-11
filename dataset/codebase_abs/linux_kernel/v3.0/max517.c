static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 , int V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
T_3 V_14 [ 4 ] ;
int V_15 = 0 ;
int V_16 ;
long V_17 ;
V_16 = F_4 ( V_5 , 10 , & V_17 ) ;
if ( V_16 )
return V_16 ;
if ( V_17 < 0 || V_17 > 255 )
return - V_18 ;
if ( V_7 & 1 ) {
V_14 [ V_15 ++ ] = V_19 ;
V_14 [ V_15 ++ ] = V_17 ;
}
if ( V_7 & 2 ) {
V_14 [ V_15 ++ ] = V_20 ;
V_14 [ V_15 ++ ] = V_17 ;
}
V_16 = F_5 ( V_13 , V_14 , V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_6 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
return F_1 ( V_2 , V_4 , V_5 , V_6 , 1 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
return F_1 ( V_2 , V_4 , V_5 , V_6 , 2 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
return F_1 ( V_2 , V_4 , V_5 , V_6 , 3 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 , int V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
unsigned int V_21 = ( V_11 -> V_22 [ V_7 - 1 ] * 1000 ) >> 8 ;
return sprintf ( V_5 , L_1 , V_21 / 1000 , V_21 % 1000 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_9 ( V_2 , V_4 , V_5 , 1 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_9 ( V_2 , V_4 , V_5 , 2 ) ;
}
static int F_12 ( struct V_12 * V_13 , T_4 V_23 )
{
T_3 V_14 = V_24 ;
return F_5 ( V_13 , & V_14 , 1 ) ;
}
static int F_13 ( struct V_12 * V_13 )
{
T_3 V_14 = 0 ;
return F_5 ( V_13 , & V_14 , 1 ) ;
}
static int F_14 ( struct V_12 * V_13 ,
const struct V_25 * V_26 )
{
struct V_10 * V_11 ;
struct V_27 * V_28 = V_13 -> V_2 . V_28 ;
int V_29 ;
V_11 = F_15 ( sizeof( struct V_10 ) , V_30 ) ;
if ( ! V_11 ) {
V_29 = - V_31 ;
goto exit;
}
F_16 ( V_13 , V_11 ) ;
V_11 -> V_13 = V_13 ;
V_11 -> V_32 = F_17 ( 0 ) ;
if ( V_11 -> V_32 == NULL ) {
V_29 = - V_31 ;
goto V_33;
}
V_11 -> V_32 -> V_2 . V_34 = & V_13 -> V_2 ;
if ( V_26 -> V_35 == V_36 )
V_11 -> V_32 -> V_37 = & V_38 ;
else
V_11 -> V_32 -> V_37 = & V_39 ;
V_11 -> V_32 -> V_40 = ( void * ) ( V_11 ) ;
V_11 -> V_32 -> V_41 = V_42 ;
if ( V_26 -> V_35 == V_43 || ! V_28 ) {
V_11 -> V_22 [ 0 ] = V_11 -> V_22 [ 1 ] = 5000 ;
} else {
V_11 -> V_22 [ 0 ] = V_28 -> V_22 [ 0 ] ;
V_11 -> V_22 [ 1 ] = V_28 -> V_22 [ 1 ] ;
}
V_29 = F_18 ( V_11 -> V_32 ) ;
if ( V_29 )
goto V_44;
V_9 ( & V_13 -> V_2 , L_2 ) ;
return 0 ;
V_44:
F_19 ( V_11 -> V_32 ) ;
V_33:
F_20 ( V_11 ) ;
exit:
return V_29 ;
}
static int F_21 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = F_22 ( V_13 ) ;
F_19 ( V_11 -> V_32 ) ;
F_20 ( V_11 ) ;
return 0 ;
}
static int T_5 F_23 ( void )
{
return F_24 ( & V_45 ) ;
}
static void T_6 F_25 ( void )
{
F_26 ( & V_45 ) ;
}
