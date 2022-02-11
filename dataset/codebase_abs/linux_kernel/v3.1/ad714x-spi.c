static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( F_3 ( F_4 ( V_2 ) ) ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 ( F_3 ( F_4 ( V_2 ) ) ) ;
}
static int F_7 ( struct V_3 * V_4 ,
unsigned short V_5 , unsigned short * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = F_4 ( V_4 -> V_2 ) ;
struct V_10 V_11 ;
struct V_12 V_13 [ 2 ] ;
int V_14 ;
int error ;
F_8 ( & V_11 ) ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
V_4 -> V_15 [ 0 ] = F_9 ( V_16 |
V_17 | V_5 ) ;
V_13 [ 0 ] . V_18 = & V_4 -> V_15 [ 0 ] ;
V_13 [ 0 ] . V_7 = sizeof( V_4 -> V_15 [ 0 ] ) ;
F_10 ( & V_13 [ 0 ] , & V_11 ) ;
V_13 [ 1 ] . V_19 = & V_4 -> V_15 [ 1 ] ;
V_13 [ 1 ] . V_7 = sizeof( V_4 -> V_15 [ 1 ] ) * V_7 ;
F_10 ( & V_13 [ 1 ] , & V_11 ) ;
error = F_11 ( V_9 , & V_11 ) ;
if ( F_12 ( error ) ) {
F_13 ( V_4 -> V_2 , L_1 , error ) ;
return error ;
}
for ( V_14 = 0 ; V_14 < V_7 ; V_14 ++ )
V_6 [ V_14 ] = F_14 ( V_4 -> V_15 [ V_14 + 1 ] ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 ,
unsigned short V_5 , unsigned short V_6 )
{
struct V_8 * V_9 = F_4 ( V_4 -> V_2 ) ;
int error ;
V_4 -> V_15 [ 0 ] = F_9 ( V_16 | V_5 ) ;
V_4 -> V_15 [ 1 ] = F_9 ( V_6 ) ;
error = F_16 ( V_9 , ( V_20 * ) V_4 -> V_15 ,
2 * sizeof( * V_4 -> V_15 ) ) ;
if ( F_12 ( error ) ) {
F_13 ( V_4 -> V_2 , L_2 , error ) ;
return error ;
}
return 0 ;
}
static int T_2 F_17 ( struct V_8 * V_9 )
{
struct V_3 * V_4 ;
int V_21 ;
V_9 -> V_22 = 8 ;
V_21 = F_18 ( V_9 ) ;
if ( V_21 < 0 )
return V_21 ;
V_4 = F_19 ( & V_9 -> V_2 , V_23 , V_9 -> V_24 ,
F_7 , F_15 ) ;
if ( F_20 ( V_4 ) )
return F_21 ( V_4 ) ;
F_22 ( V_9 , V_4 ) ;
return 0 ;
}
static int T_3 F_23 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
F_24 ( V_4 ) ;
F_22 ( V_9 , NULL ) ;
return 0 ;
}
static T_4 int F_25 ( void )
{
return F_26 ( & V_25 ) ;
}
static T_5 void F_27 ( void )
{
F_28 ( & V_25 ) ;
}
