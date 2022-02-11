static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( F_3 ( F_4 ( V_2 ) ) ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 ( F_3 ( F_4 ( V_2 ) ) ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short V_4 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 = 0 ;
T_1 * V_8 = ( T_1 * ) & V_3 ;
T_1 * V_9 = ( T_1 * ) & V_4 ;
T_1 V_10 [ 4 ] = {
V_8 [ 1 ] ,
V_8 [ 0 ] ,
V_9 [ 1 ] ,
V_9 [ 0 ]
} ;
V_7 = F_8 ( V_6 , V_10 , 4 ) ;
if ( V_7 < 0 )
F_9 ( & V_6 -> V_2 , L_1 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short * V_4 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 = 0 ;
T_1 * V_8 = ( T_1 * ) & V_3 ;
T_1 * V_9 = ( T_1 * ) V_4 ;
T_1 V_10 [ 2 ] = {
V_8 [ 1 ] ,
V_8 [ 0 ]
} ;
T_1 V_11 [ 2 ] ;
V_7 = F_8 ( V_6 , V_10 , 2 ) ;
if ( V_7 >= 0 )
V_7 = F_11 ( V_6 , V_11 , 2 ) ;
if ( F_12 ( V_7 < 0 ) ) {
F_9 ( & V_6 -> V_2 , L_2 ) ;
} else {
V_9 [ 0 ] = V_11 [ 1 ] ;
V_9 [ 1 ] = V_11 [ 0 ] ;
}
return V_7 ;
}
static int T_2 F_13 ( struct V_5 * V_6 ,
const struct V_12 * V_13 )
{
struct V_14 * V_15 ;
V_15 = F_14 ( & V_6 -> V_2 , V_16 , V_6 -> V_17 ,
F_10 , F_7 ) ;
if ( F_15 ( V_15 ) )
return F_16 ( V_15 ) ;
F_17 ( V_6 , V_15 ) ;
return 0 ;
}
static int T_3 F_18 ( struct V_5 * V_6 )
{
struct V_14 * V_15 = F_3 ( V_6 ) ;
F_19 ( V_15 ) ;
return 0 ;
}
static T_4 int F_20 ( void )
{
return F_21 ( & V_18 ) ;
}
static T_5 void F_22 ( void )
{
F_23 ( & V_18 ) ;
}
