static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned int V_4 ;
int V_5 = V_6 ;
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
F_5 ( 0 , V_3 -> V_7 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_3 * V_3 ;
struct V_10 * V_10 ;
int error , V_1 ;
V_3 = F_9 ( sizeof( struct V_3 ) , V_15 ) ;
V_10 = F_9 ( sizeof( struct V_10 ) , V_15 ) ;
if ( ! V_3 || ! V_10 ) {
error = - V_16 ;
goto V_17;
}
V_10 -> V_18 . type = V_19 ;
V_10 -> V_20 = F_4 ;
V_10 -> V_21 = F_6 ;
V_10 -> V_22 = F_7 ;
F_10 ( V_10 -> V_23 , F_11 ( & V_14 -> V_24 ) , sizeof( V_10 -> V_23 ) ) ;
F_10 ( V_10 -> V_25 , F_11 ( & V_14 -> V_24 ) , sizeof( V_10 -> V_25 ) ) ;
V_10 -> V_12 = V_3 ;
V_10 -> V_24 . V_26 = & V_14 -> V_24 ;
V_3 -> V_8 = V_10 ;
V_3 -> V_27 = F_12 ( V_14 , V_28 , 0 ) ;
if ( V_3 -> V_27 == NULL ) {
error = - V_29 ;
goto V_17;
}
V_1 = F_13 ( V_14 , 0 ) ;
if ( V_1 < 0 ) {
error = - V_30 ;
goto V_17;
}
V_3 -> V_1 = V_1 ;
if ( ! F_14 ( V_3 -> V_27 -> V_31 ,
F_15 ( V_3 -> V_27 ) , V_14 -> V_23 ) ) {
error = - V_32 ;
goto V_17;
}
V_3 -> V_7 = F_16 ( V_3 -> V_27 -> V_31 ,
F_15 ( V_3 -> V_27 ) ) ;
if ( ! V_3 -> V_7 ) {
error = - V_16 ;
goto V_33;
}
error = F_17 ( V_3 -> V_1 , F_1 , 0 , V_14 -> V_23 , V_3 ) ;
if ( error ) {
F_18 ( & V_14 -> V_24 , L_1 ,
V_3 -> V_1 , error ) ;
goto V_34;
}
F_19 ( & V_14 -> V_24 , L_2 , V_3 -> V_7 , V_3 -> V_1 ) ;
F_20 ( V_3 -> V_8 ) ;
F_21 ( V_14 , V_3 ) ;
return 0 ;
V_34:
F_22 ( V_3 -> V_7 ) ;
V_33:
F_23 ( V_3 -> V_27 -> V_31 ,
F_15 ( V_3 -> V_27 ) ) ;
V_17:
F_24 ( V_3 ) ;
F_24 ( V_10 ) ;
return error ;
}
static int F_25 ( struct V_13 * V_14 )
{
struct V_3 * V_3 = F_26 ( V_14 ) ;
F_21 ( V_14 , NULL ) ;
F_27 ( V_3 -> V_8 ) ;
F_28 ( V_3 -> V_1 , V_3 ) ;
F_22 ( V_3 -> V_7 ) ;
F_23 ( V_3 -> V_27 -> V_31 ,
F_15 ( V_3 -> V_27 ) ) ;
F_24 ( V_3 ) ;
return 0 ;
}
