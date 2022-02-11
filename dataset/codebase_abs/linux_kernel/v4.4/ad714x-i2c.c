static int T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( F_3 ( F_4 ( V_2 ) ) ) ;
}
static int T_1 F_5 ( struct V_1 * V_2 )
{
return F_6 ( F_3 ( F_4 ( V_2 ) ) ) ;
}
static int F_7 ( struct V_3 * V_4 ,
unsigned short V_5 , unsigned short V_6 )
{
struct V_7 * V_8 = F_4 ( V_4 -> V_2 ) ;
int error ;
V_4 -> V_9 [ 0 ] = F_8 ( V_5 ) ;
V_4 -> V_9 [ 1 ] = F_8 ( V_6 ) ;
error = F_9 ( V_8 , ( V_10 * ) V_4 -> V_9 ,
2 * sizeof( * V_4 -> V_9 ) ) ;
if ( F_10 ( error < 0 ) ) {
F_11 ( & V_8 -> V_2 , L_1 , error ) ;
return error ;
}
return 0 ;
}
static int F_12 ( struct V_3 * V_4 ,
unsigned short V_5 , unsigned short * V_6 , T_2 V_11 )
{
struct V_7 * V_8 = F_4 ( V_4 -> V_2 ) ;
int V_12 ;
int error ;
V_4 -> V_9 [ 0 ] = F_8 ( V_5 ) ;
error = F_9 ( V_8 , ( V_10 * ) V_4 -> V_9 ,
sizeof( * V_4 -> V_9 ) ) ;
if ( error >= 0 )
error = F_13 ( V_8 , ( V_10 * ) V_4 -> V_9 ,
V_11 * sizeof( * V_4 -> V_9 ) ) ;
if ( F_10 ( error < 0 ) ) {
F_11 ( & V_8 -> V_2 , L_2 , error ) ;
return error ;
}
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_6 [ V_12 ] = F_14 ( V_4 -> V_9 [ V_12 ] ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 ,
const struct V_13 * V_14 )
{
struct V_3 * V_4 ;
V_4 = F_16 ( & V_8 -> V_2 , V_15 , V_8 -> V_16 ,
F_12 , F_7 ) ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
F_19 ( V_8 , V_4 ) ;
return 0 ;
}
