static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_5 * V_6 ;
int V_7 ;
memset ( & V_4 , 0x00 , sizeof( V_4 ) ) ;
V_6 = F_2 ( L_1 , 0 ) ;
if ( ! V_6 )
return - V_8 ;
V_2 -> V_9 = V_6 ;
V_4 . type = V_10 ;
V_7 = F_3 ( V_2 -> V_9 , & V_4 , sizeof( V_4 ) ) ;
if ( V_7 )
goto V_11;
V_6 = F_2 ( L_1 , 1 ) ;
if ( ! V_6 ) {
V_7 = - V_8 ;
goto V_11;
}
V_2 -> V_12 = V_6 ;
V_4 . type = V_13 ;
V_7 = F_3 ( V_2 -> V_12 , & V_4 , sizeof( V_4 ) ) ;
if ( V_7 )
goto V_14;
V_7 = F_4 ( V_2 -> V_9 ) ;
if ( V_7 )
goto V_14;
V_7 = F_4 ( V_2 -> V_12 ) ;
if ( V_7 )
goto V_15;
return 0 ;
V_15:
F_5 ( V_2 -> V_9 ) ;
V_14:
F_6 ( V_2 -> V_12 ) ;
V_11:
F_6 ( V_2 -> V_9 ) ;
return V_7 ;
}
static int F_7 ( struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
struct V_20 V_21 [ 2 ] ;
struct V_5 * V_22 ;
struct V_1 * V_2 ;
int V_7 = - V_8 ;
struct V_23 * V_24 = & V_17 -> V_24 ;
V_2 = F_8 ( V_24 , sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 ) {
F_9 ( V_24 , L_2 ) ;
return - V_8 ;
}
V_2 -> V_24 = V_24 ;
V_7 = F_10 ( V_17 ) ;
if ( V_7 ) {
F_9 ( V_24 , L_3 ) ;
return - V_26 ;
}
F_11 ( V_17 ) ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 ) {
F_9 ( V_24 , L_4 ) ;
return V_7 ;
}
V_22 = F_2 ( L_5 , V_27 ) ;
if ( ! V_22 ) {
F_9 ( V_24 , L_6 ) ;
V_7 = - V_8 ;
goto V_11;
}
memset ( V_21 , 0x00 , sizeof( struct V_20 ) * F_12 ( V_21 ) ) ;
V_21 [ 0 ] . V_28 = F_13 ( V_17 , 0 ) ;
V_21 [ 0 ] . V_29 = F_14 ( V_17 , 0 ) ;
V_21 [ 0 ] . V_30 = L_7 ;
V_21 [ 0 ] . V_31 = V_32 ;
V_21 [ 1 ] . V_28 = V_17 -> V_33 ;
V_21 [ 1 ] . V_30 = L_7 ;
V_21 [ 1 ] . V_31 = V_34 ;
V_7 = F_15 ( V_22 , V_21 , F_12 ( V_21 ) ) ;
if ( V_7 ) {
F_9 ( V_24 , L_8 ) ;
goto V_11;
}
F_16 ( V_17 , V_2 ) ;
F_17 ( & V_22 -> V_24 , V_24 -> V_35 ) ;
V_22 -> V_24 . V_36 = V_24 -> V_36 ;
V_22 -> V_24 . V_37 = V_24 -> V_37 ;
V_22 -> V_24 . V_38 = V_24 ;
V_2 -> V_22 = V_22 ;
V_7 = F_4 ( V_22 ) ;
if ( V_7 ) {
F_9 ( V_24 , L_9 ) ;
goto V_15;
}
return 0 ;
V_15:
F_6 ( V_22 ) ;
V_11:
F_18 ( V_17 ) ;
return V_7 ;
}
static void F_19 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_20 ( V_17 ) ;
F_21 ( V_2 -> V_22 ) ;
F_21 ( V_2 -> V_9 ) ;
F_21 ( V_2 -> V_12 ) ;
F_18 ( V_17 ) ;
}
static int F_22 ( struct V_23 * V_24 )
{
struct V_16 * V_17 = F_23 ( V_24 ) ;
F_18 ( V_17 ) ;
return 0 ;
}
static int F_24 ( struct V_23 * V_24 )
{
struct V_16 * V_17 = F_23 ( V_24 ) ;
int V_7 ;
V_7 = F_10 ( V_17 ) ;
if ( V_7 ) {
F_9 ( V_24 , L_10 , V_7 ) ;
return V_7 ;
}
F_11 ( V_17 ) ;
return 0 ;
}
