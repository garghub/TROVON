static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return sprintf ( V_5 , L_1 , V_9 -> V_10 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_12 , V_13 , V_14 ;
V_12 = F_5 ( V_5 , NULL , 10 ) ;
if ( V_12 > 255 )
V_12 = 255 ;
else if ( V_12 < 0 )
V_12 = 0 ;
V_14 = V_9 -> V_10 ;
V_9 -> V_10 = V_12 ;
F_6 ( & V_9 -> V_15 -> V_2 , L_2 , V_9 -> V_10 ) ;
V_13 = F_7 ( V_9 -> V_15 , F_8 ( V_9 -> V_15 , 0 ) ,
0x01 ,
V_16 | V_17 | V_18 ,
V_9 -> V_10 ,
0 , NULL , 0 , V_19 ) ;
if ( V_13 ) {
V_9 -> V_10 = V_14 ;
F_6 ( & V_9 -> V_15 -> V_2 , L_3 , V_13 ) ;
return V_13 ;
}
return V_11 ;
}
static int F_9 ( struct V_6 * V_20 ,
const struct V_21 * V_22 )
{
struct V_23 * V_15 = F_10 ( V_20 ) ;
struct V_8 * V_2 ;
int V_13 ;
V_2 = F_11 ( sizeof( struct V_8 ) , V_24 ) ;
if ( ! V_2 ) {
V_13 = - V_25 ;
goto error;
}
V_2 -> V_15 = F_12 ( V_15 ) ;
F_13 ( V_20 , V_2 ) ;
V_13 = F_14 ( & V_20 -> V_2 , & V_26 ) ;
if ( V_13 )
goto V_27;
return 0 ;
V_27:
F_15 ( V_15 ) ;
F_13 ( V_20 , NULL ) ;
error:
F_16 ( V_2 ) ;
return V_13 ;
}
static void F_17 ( struct V_6 * V_20 )
{
struct V_8 * V_2 ;
V_2 = F_3 ( V_20 ) ;
F_18 ( & V_20 -> V_2 , & V_26 ) ;
F_13 ( V_20 , NULL ) ;
F_15 ( V_2 -> V_15 ) ;
F_16 ( V_2 ) ;
}
