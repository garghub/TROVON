static int F_1 ( void * V_1 , T_1 V_2 , T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = V_1 ;
V_6 -> V_7 [ 0 ] = V_2 ;
memcpy ( V_6 -> V_7 + 1 , V_3 , V_4 ) ;
return F_2 ( V_6 -> V_8 , V_6 -> V_7 , V_4 + 1 ) ;
}
static int F_3 ( void * V_1 , T_1 V_2 , T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = V_1 ;
T_1 V_9 = 0 ;
T_1 V_10 ;
V_10 = V_11 ;
V_9 = F_1 ( V_6 , V_2 , & V_10 , 1 ) ;
if ( V_9 == 2 )
V_9 = F_4 ( V_6 -> V_8 , V_3 , V_4 ) ;
return V_9 ;
}
static int F_5 ( void * V_1 , T_1 V_2 , T_1 * V_3 ,
int V_4 )
{
return F_1 ( V_1 , V_2 | V_12 , V_3 ,
V_4 ) ;
}
static int F_6 ( void * V_1 , T_1 V_2 , T_1 * V_3 ,
int V_4 )
{
return F_3 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_15 * V_8 = V_6 -> V_8 ;
int V_16 ;
int V_17 ;
V_14 = V_8 -> V_18 . V_19 ;
if ( ! V_14 ) {
F_8 ( & V_8 -> V_18 , L_1 ) ;
return - V_20 ;
}
V_16 = F_9 ( V_14 , L_2 , 0 ) ;
if ( V_16 < 0 ) {
F_8 ( & V_8 -> V_18 ,
L_3 ) ;
V_6 -> V_21 = - 1 ;
return 0 ;
}
V_17 = F_10 ( & V_8 -> V_18 , V_16 ,
V_22 , L_4 ) ;
if ( V_17 ) {
F_8 ( & V_8 -> V_18 , L_5 ) ;
return - V_20 ;
}
V_6 -> V_21 = V_16 ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
return - V_20 ;
}
static int F_11 ( struct V_15 * V_8 ,
struct V_5 * V_6 )
{
struct V_23 * V_24 ;
int V_17 ;
V_24 = V_8 -> V_18 . V_25 ;
if ( ! V_24 ) {
F_8 ( & V_8 -> V_18 , L_1 ) ;
return - V_20 ;
}
V_6 -> V_21 = V_24 -> V_21 ;
if ( F_12 ( V_24 -> V_21 ) ) {
V_17 = F_10 ( & V_8 -> V_18 ,
V_24 -> V_21 , V_22 ,
L_6 ) ;
if ( V_17 ) {
F_8 ( & V_8 -> V_18 , L_5 ) ;
return V_17 ;
}
}
return 0 ;
}
static int F_13 ( struct V_15 * V_8 ,
const struct V_26 * V_27 )
{
int V_17 ;
struct V_23 * V_24 ;
struct V_5 * V_6 ;
if ( ! V_8 ) {
F_14 ( L_7 ,
V_28 ) ;
return - V_20 ;
}
if ( ! F_15 ( V_8 -> V_29 , V_30 ) ) {
F_16 ( & V_8 -> V_18 , L_8 ) ;
return - V_20 ;
}
V_6 = F_17 ( & V_8 -> V_18 , sizeof( struct V_5 ) ,
V_31 ) ;
if ( ! V_6 )
return - V_32 ;
V_6 -> V_8 = V_8 ;
V_24 = V_8 -> V_18 . V_25 ;
if ( ! V_24 && V_8 -> V_18 . V_19 ) {
V_17 = F_7 ( V_6 ) ;
if ( V_17 )
return V_17 ;
} else if ( V_24 ) {
V_17 = F_11 ( V_8 , V_6 ) ;
if ( V_17 )
return V_17 ;
}
return F_18 ( V_6 , & V_33 , & V_8 -> V_18 , V_8 -> V_34 ,
V_6 -> V_21 ) ;
}
static int F_19 ( struct V_15 * V_8 )
{
struct V_35 * V_36 = F_20 ( V_8 ) ;
return F_21 ( V_36 ) ;
}
