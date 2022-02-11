static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned int V_4 ;
T_1 V_5 = V_6 ;
while ( ( V_4 = F_2 ( V_3 -> V_7 ) ) & 0xffff0000 ) {
F_3 ( V_3 -> V_8 , V_4 & 0xff , 0 ) ;
V_5 = V_9 ;
}
return V_5 ;
}
static int F_4 ( struct V_10 * V_8 , unsigned char V_11 )
{
struct V_3 * V_3 = V_8 -> V_12 ;
F_5 ( V_11 , V_3 -> V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_10 * V_8 )
{
struct V_3 * V_3 = V_8 -> V_12 ;
while ( F_2 ( V_3 -> V_7 ) & 0xffff0000 )
;
F_5 ( 1 , V_3 -> V_7 + 4 ) ;
return 0 ;
}
static void F_7 ( struct V_10 * V_8 )
{
struct V_3 * V_3 = V_8 -> V_12 ;
F_5 ( 0 , V_3 -> V_7 + 4 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_3 * V_3 ;
struct V_15 * V_16 ;
struct V_10 * V_10 ;
int error , V_1 ;
V_3 = F_9 ( & V_14 -> V_17 , sizeof( struct V_3 ) , V_18 ) ;
if ( ! V_3 )
return - V_19 ;
V_16 = F_10 ( V_14 , V_20 , 0 ) ;
V_3 -> V_7 = F_11 ( & V_14 -> V_17 , V_16 ) ;
if ( F_12 ( V_3 -> V_7 ) )
return F_13 ( V_3 -> V_7 ) ;
V_1 = F_14 ( V_14 , 0 ) ;
if ( V_1 < 0 )
return - V_21 ;
error = F_15 ( & V_14 -> V_17 , V_1 , F_1 , 0 ,
V_14 -> V_22 , V_3 ) ;
if ( error ) {
F_16 ( & V_14 -> V_17 , L_1 , V_1 ) ;
return error ;
}
V_10 = F_17 ( sizeof( struct V_10 ) , V_18 ) ;
if ( ! V_10 )
return - V_19 ;
V_10 -> V_23 . type = V_24 ;
V_10 -> V_25 = F_4 ;
V_10 -> V_26 = F_6 ;
V_10 -> V_27 = F_7 ;
F_18 ( V_10 -> V_22 , F_19 ( & V_14 -> V_17 ) , sizeof( V_10 -> V_22 ) ) ;
F_18 ( V_10 -> V_28 , F_19 ( & V_14 -> V_17 ) , sizeof( V_10 -> V_28 ) ) ;
V_10 -> V_12 = V_3 ;
V_10 -> V_17 . V_29 = & V_14 -> V_17 ;
V_3 -> V_8 = V_10 ;
F_20 ( & V_14 -> V_17 , L_2 , V_3 -> V_7 , V_1 ) ;
F_21 ( V_3 -> V_8 ) ;
F_22 ( V_14 , V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_13 * V_14 )
{
struct V_3 * V_3 = F_24 ( V_14 ) ;
F_25 ( V_3 -> V_8 ) ;
return 0 ;
}
