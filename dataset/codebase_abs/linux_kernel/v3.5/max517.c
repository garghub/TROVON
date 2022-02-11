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
static int F_12 ( struct V_1 * V_2 )
{
T_3 V_14 = V_23 ;
return F_5 ( F_13 ( V_2 ) , & V_14 , 1 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_3 V_14 = 0 ;
return F_5 ( F_13 ( V_2 ) , & V_14 , 1 ) ;
}
static int F_15 ( struct V_12 * V_13 ,
const struct V_24 * V_25 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_26 * V_27 = V_13 -> V_2 . V_27 ;
int V_28 ;
V_9 = F_16 ( sizeof( * V_11 ) ) ;
if ( V_9 == NULL ) {
V_28 = - V_29 ;
goto exit;
}
V_11 = F_3 ( V_9 ) ;
F_17 ( V_13 , V_9 ) ;
V_11 -> V_13 = V_13 ;
V_9 -> V_2 . V_30 = & V_13 -> V_2 ;
if ( V_25 -> V_31 == V_32 )
V_9 -> V_33 = & V_34 ;
else
V_9 -> V_33 = & V_35 ;
V_9 -> V_36 = V_37 ;
if ( V_25 -> V_31 == V_38 || ! V_27 ) {
V_11 -> V_22 [ 0 ] = V_11 -> V_22 [ 1 ] = 5000 ;
} else {
V_11 -> V_22 [ 0 ] = V_27 -> V_22 [ 0 ] ;
V_11 -> V_22 [ 1 ] = V_27 -> V_22 [ 1 ] ;
}
V_28 = F_18 ( V_9 ) ;
if ( V_28 )
goto V_39;
F_19 ( & V_13 -> V_2 , L_2 ) ;
return 0 ;
V_39:
F_20 ( V_9 ) ;
exit:
return V_28 ;
}
static int F_21 ( struct V_12 * V_13 )
{
F_22 ( F_23 ( V_13 ) ) ;
F_20 ( F_23 ( V_13 ) ) ;
return 0 ;
}
