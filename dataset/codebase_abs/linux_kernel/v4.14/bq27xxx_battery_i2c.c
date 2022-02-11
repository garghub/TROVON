static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 ) ;
return V_5 ;
}
static int F_3 ( struct V_3 * V_4 , T_2 V_6 ,
bool V_7 )
{
struct V_8 * V_9 = F_4 ( V_4 -> V_10 ) ;
struct V_11 V_12 [ 2 ] ;
T_2 V_2 [ 2 ] ;
int V_13 ;
if ( ! V_9 -> V_14 )
return - V_15 ;
V_12 [ 0 ] . V_16 = V_9 -> V_16 ;
V_12 [ 0 ] . V_17 = 0 ;
V_12 [ 0 ] . V_18 = & V_6 ;
V_12 [ 0 ] . V_19 = sizeof( V_6 ) ;
V_12 [ 1 ] . V_16 = V_9 -> V_16 ;
V_12 [ 1 ] . V_17 = V_20 ;
V_12 [ 1 ] . V_18 = V_2 ;
if ( V_7 )
V_12 [ 1 ] . V_19 = 1 ;
else
V_12 [ 1 ] . V_19 = 2 ;
V_13 = F_5 ( V_9 -> V_14 , V_12 , F_6 ( V_12 ) ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! V_7 )
V_13 = F_7 ( V_2 ) ;
else
V_13 = V_2 [ 0 ] ;
return V_13 ;
}
static int F_8 ( struct V_3 * V_4 , T_2 V_6 ,
int V_21 , bool V_7 )
{
struct V_8 * V_9 = F_4 ( V_4 -> V_10 ) ;
struct V_11 V_12 ;
T_2 V_2 [ 4 ] ;
int V_13 ;
if ( ! V_9 -> V_14 )
return - V_15 ;
V_2 [ 0 ] = V_6 ;
if ( V_7 ) {
V_2 [ 1 ] = ( T_2 ) V_21 ;
V_12 . V_19 = 2 ;
} else {
F_9 ( V_21 , & V_2 [ 1 ] ) ;
V_12 . V_19 = 3 ;
}
V_12 . V_18 = V_2 ;
V_12 . V_16 = V_9 -> V_16 ;
V_12 . V_17 = 0 ;
V_13 = F_5 ( V_9 -> V_14 , & V_12 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 != 1 )
return - V_22 ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 , T_2 V_6 ,
T_2 * V_2 , int V_19 )
{
struct V_8 * V_9 = F_4 ( V_4 -> V_10 ) ;
int V_13 ;
if ( ! V_9 -> V_14 )
return - V_15 ;
V_13 = F_11 ( V_9 , V_6 , V_19 , V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 != V_19 )
return - V_22 ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 ,
T_2 V_6 , T_2 * V_2 , int V_19 )
{
struct V_8 * V_9 = F_4 ( V_4 -> V_10 ) ;
struct V_11 V_12 ;
T_2 V_18 [ 33 ] ;
int V_13 ;
if ( ! V_9 -> V_14 )
return - V_15 ;
V_18 [ 0 ] = V_6 ;
memcpy ( & V_18 [ 1 ] , V_2 , V_19 ) ;
V_12 . V_18 = V_18 ;
V_12 . V_16 = V_9 -> V_16 ;
V_12 . V_17 = 0 ;
V_12 . V_19 = V_19 + 1 ;
V_13 = F_5 ( V_9 -> V_14 , & V_12 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 != 1 )
return - V_22 ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 ;
int V_13 ;
char * V_25 ;
int V_26 ;
F_14 ( & V_27 ) ;
V_26 = F_15 ( & V_28 , V_9 , 0 , 0 , V_29 ) ;
F_16 ( & V_27 ) ;
if ( V_26 < 0 )
return V_26 ;
V_25 = F_17 ( & V_9 -> V_10 , V_29 , L_1 , V_24 -> V_25 , V_26 ) ;
if ( ! V_25 )
goto V_30;
V_4 = F_18 ( & V_9 -> V_10 , sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
goto V_30;
V_4 -> V_24 = V_26 ;
V_4 -> V_10 = & V_9 -> V_10 ;
V_4 -> V_31 = V_24 -> V_32 ;
V_4 -> V_25 = V_25 ;
V_4 -> V_33 . V_34 = F_3 ;
V_4 -> V_33 . V_35 = F_8 ;
V_4 -> V_33 . V_36 = F_10 ;
V_4 -> V_33 . V_37 = F_12 ;
V_13 = F_19 ( V_4 ) ;
if ( V_13 )
goto V_38;
F_20 ( & V_4 -> V_39 , 60 * V_40 ) ;
F_21 ( V_9 , V_4 ) ;
if ( V_9 -> V_1 ) {
V_13 = F_22 ( & V_9 -> V_10 , V_9 -> V_1 ,
NULL , F_1 ,
V_41 ,
V_4 -> V_25 , V_4 ) ;
if ( V_13 ) {
F_23 ( & V_9 -> V_10 ,
L_2 ,
V_9 -> V_1 , V_13 ) ;
return V_13 ;
}
}
return 0 ;
V_30:
V_13 = - V_42 ;
V_38:
F_14 ( & V_27 ) ;
F_24 ( & V_28 , V_26 ) ;
F_16 ( & V_27 ) ;
return V_13 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_26 ( V_9 ) ;
F_27 ( V_4 ) ;
F_14 ( & V_27 ) ;
F_24 ( & V_28 , V_4 -> V_24 ) ;
F_16 ( & V_27 ) ;
return 0 ;
}
