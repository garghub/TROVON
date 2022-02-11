static int F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_6 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_5 ( V_5 , V_3 , V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned char V_3 , int V_7 ,
void * V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_7 ( V_5 , V_3 , V_7 , V_8 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned char V_3 , int V_7 ,
void * V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_9 ;
V_9 = F_9 ( V_5 , & V_3 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_10 ( V_5 , V_8 , V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 != V_7 )
return - V_10 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 ,
const struct V_11 * V_12 )
{
struct V_13 * V_14 ;
int error ;
error = F_12 ( V_5 -> V_15 ,
V_16 ) ;
if ( ! error ) {
F_13 ( & V_5 -> V_2 , L_1 ) ;
return - V_10 ;
}
V_14 = F_14 ( & V_5 -> V_2 , V_5 -> V_17 , false ,
F_12 ( V_5 -> V_15 ,
V_18 ) ?
& V_19 : & V_20 ) ;
if ( F_15 ( V_14 ) )
return F_16 ( V_14 ) ;
F_17 ( V_5 , V_14 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = F_19 ( V_5 ) ;
return F_20 ( V_14 ) ;
}
static int T_1 F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_13 * V_14 = F_19 ( V_5 ) ;
F_22 ( V_14 ) ;
return 0 ;
}
static int T_1 F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_13 * V_14 = F_19 ( V_5 ) ;
F_24 ( V_14 ) ;
return 0 ;
}
