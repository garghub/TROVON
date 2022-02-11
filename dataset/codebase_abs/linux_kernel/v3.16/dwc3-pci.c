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
V_4 . V_11 = - 1 ;
V_7 = F_3 ( V_2 -> V_9 , & V_4 , sizeof( V_4 ) ) ;
if ( V_7 )
goto V_12;
V_6 = F_2 ( L_1 , 1 ) ;
if ( ! V_6 ) {
V_7 = - V_8 ;
goto V_12;
}
V_2 -> V_13 = V_6 ;
V_4 . type = V_14 ;
V_7 = F_3 ( V_2 -> V_13 , & V_4 , sizeof( V_4 ) ) ;
if ( V_7 )
goto V_15;
V_7 = F_4 ( V_2 -> V_9 ) ;
if ( V_7 )
goto V_15;
V_7 = F_4 ( V_2 -> V_13 ) ;
if ( V_7 )
goto V_16;
return 0 ;
V_16:
F_5 ( V_2 -> V_9 ) ;
V_15:
F_6 ( V_2 -> V_13 ) ;
V_12:
F_6 ( V_2 -> V_9 ) ;
return V_7 ;
}
static int F_7 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
struct V_21 V_22 [ 2 ] ;
struct V_5 * V_23 ;
struct V_1 * V_2 ;
int V_7 ;
struct V_24 * V_25 = & V_18 -> V_25 ;
V_2 = F_8 ( V_25 , sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 ) {
F_9 ( V_25 , L_2 ) ;
return - V_8 ;
}
V_2 -> V_25 = V_25 ;
V_7 = F_10 ( V_18 ) ;
if ( V_7 ) {
F_9 ( V_25 , L_3 ) ;
return - V_27 ;
}
F_11 ( V_18 ) ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 ) {
F_9 ( V_25 , L_4 ) ;
return V_7 ;
}
V_23 = F_2 ( L_5 , V_28 ) ;
if ( ! V_23 ) {
F_9 ( V_25 , L_6 ) ;
return - V_8 ;
}
memset ( V_22 , 0x00 , sizeof( struct V_21 ) * F_12 ( V_22 ) ) ;
V_22 [ 0 ] . V_29 = F_13 ( V_18 , 0 ) ;
V_22 [ 0 ] . V_30 = F_14 ( V_18 , 0 ) ;
V_22 [ 0 ] . V_31 = L_7 ;
V_22 [ 0 ] . V_32 = V_33 ;
V_22 [ 1 ] . V_29 = V_18 -> V_34 ;
V_22 [ 1 ] . V_31 = L_7 ;
V_22 [ 1 ] . V_32 = V_35 ;
V_7 = F_15 ( V_23 , V_22 , F_12 ( V_22 ) ) ;
if ( V_7 ) {
F_9 ( V_25 , L_8 ) ;
return V_7 ;
}
F_16 ( V_18 , V_2 ) ;
F_17 ( & V_23 -> V_25 , V_25 -> V_36 ) ;
V_23 -> V_25 . V_37 = V_25 -> V_37 ;
V_23 -> V_25 . V_38 = V_25 -> V_38 ;
V_23 -> V_25 . V_39 = V_25 ;
V_2 -> V_23 = V_23 ;
V_7 = F_4 ( V_23 ) ;
if ( V_7 ) {
F_9 ( V_25 , L_9 ) ;
goto V_16;
}
return 0 ;
V_16:
F_6 ( V_23 ) ;
return V_7 ;
}
static void F_18 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_19 ( V_18 ) ;
F_20 ( V_2 -> V_23 ) ;
F_20 ( V_2 -> V_9 ) ;
F_20 ( V_2 -> V_13 ) ;
}
static int F_21 ( struct V_24 * V_25 )
{
struct V_17 * V_18 = F_22 ( V_25 ) ;
F_23 ( V_18 ) ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 )
{
struct V_17 * V_18 = F_22 ( V_25 ) ;
int V_7 ;
V_7 = F_25 ( V_18 ) ;
if ( V_7 ) {
F_9 ( V_25 , L_10 , V_7 ) ;
return V_7 ;
}
F_11 ( V_18 ) ;
return 0 ;
}
