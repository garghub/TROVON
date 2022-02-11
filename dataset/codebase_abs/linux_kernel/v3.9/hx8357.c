static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_2 V_4 ,
T_1 * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 V_10 ;
struct V_11 V_12 [ 2 ] ;
T_2 * V_13 = NULL ;
int V_14 = 0 ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
F_3 ( & V_10 ) ;
if ( V_4 ) {
int V_15 ;
V_13 = F_4 ( V_4 , sizeof( * V_13 ) , V_16 ) ;
if ( ! V_13 )
return - V_17 ;
for ( V_15 = 0 ; V_15 < V_4 ; V_15 ++ ) {
V_13 [ V_15 ] = V_3 [ V_15 ] ;
if ( V_15 > 0 )
V_13 [ V_15 ] |= 1 << 8 ;
}
V_12 [ 0 ] . V_18 = 2 * V_4 ;
V_12 [ 0 ] . V_19 = 9 ;
V_12 [ 0 ] . V_20 = V_13 ;
F_5 ( & V_12 [ 0 ] , & V_10 ) ;
}
if ( V_6 ) {
V_12 [ 1 ] . V_18 = V_6 ;
V_12 [ 1 ] . V_19 = 8 ;
V_12 [ 1 ] . V_21 = V_5 ;
F_5 ( & V_12 [ 1 ] , & V_10 ) ;
}
V_14 = F_6 ( V_8 -> V_22 , & V_10 ) ;
if ( V_14 < 0 )
F_7 ( & V_2 -> V_23 , L_1 ) ;
if ( V_4 )
F_8 ( V_13 ) ;
return V_14 ;
}
static inline int F_9 ( struct V_1 * V_2 ,
T_1 * V_24 , T_1 V_18 )
{
return F_1 ( V_2 , V_24 , V_18 , NULL , 0 ) ;
}
static inline int F_10 ( struct V_1 * V_2 ,
T_1 V_24 )
{
return F_1 ( V_2 , & V_24 , 1 , NULL , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_10 ( V_2 , V_25 ) ;
if ( V_14 < 0 )
return V_14 ;
F_12 ( 10000 , 12000 ) ;
V_14 = F_10 ( V_2 , V_26 ) ;
if ( V_14 < 0 )
return V_14 ;
F_13 ( 120 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_10 ( V_2 , V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
F_13 ( 120 ) ;
V_14 = F_10 ( V_2 , V_28 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_14 ;
F_16 ( V_8 -> V_29 [ 0 ] , 1 ) ;
F_16 ( V_8 -> V_29 [ 1 ] , 0 ) ;
F_16 ( V_8 -> V_29 [ 2 ] , 1 ) ;
F_17 ( V_8 -> V_30 , 1 ) ;
F_12 ( 10000 , 12000 ) ;
F_17 ( V_8 -> V_30 , 0 ) ;
F_12 ( 10000 , 12000 ) ;
F_17 ( V_8 -> V_30 , 1 ) ;
F_13 ( 120 ) ;
V_14 = F_9 ( V_2 , V_31 ,
F_18 ( V_31 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_32 ,
F_18 ( V_32 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_33 ,
F_18 ( V_33 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_34 ,
F_18 ( V_34 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_35 ,
F_18 ( V_35 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_36 ,
F_18 ( V_36 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_37 ,
F_18 ( V_37 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_38 ,
F_18 ( V_38 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_39 ,
F_18 ( V_39 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_40 ,
F_18 ( V_40 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_41 ,
F_18 ( V_41 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_42 ,
F_18 ( V_42 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_43 ,
F_18 ( V_43 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_44 ,
F_18 ( V_44 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_45 ,
F_18 ( V_45 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_10 ( V_2 , V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
F_13 ( 120 ) ;
V_14 = F_10 ( V_2 , V_28 ) ;
if ( V_14 < 0 )
return V_14 ;
F_12 ( 5000 , 7000 ) ;
V_14 = F_10 ( V_2 , V_46 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_47 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_14 = 0 ;
if ( F_20 ( V_47 ) && ! F_20 ( V_8 -> V_48 ) )
V_14 = F_14 ( V_2 ) ;
else if ( ! F_20 ( V_47 ) && F_20 ( V_8 -> V_48 ) )
V_14 = F_11 ( V_2 ) ;
if ( V_14 == 0 )
V_8 -> V_48 = V_47 ;
else
F_21 ( & V_2 -> V_23 , L_2 , V_47 ) ;
return V_14 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_48 ;
}
static int F_23 ( struct V_49 * V_22 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_15 , V_14 ;
V_8 = F_24 ( & V_22 -> V_23 , sizeof( * V_8 ) , V_16 ) ;
if ( ! V_8 ) {
F_7 ( & V_22 -> V_23 , L_3 ) ;
return - V_17 ;
}
V_14 = F_25 ( V_22 ) ;
if ( V_14 < 0 ) {
F_7 ( & V_22 -> V_23 , L_4 ) ;
return V_14 ;
}
V_8 -> V_22 = V_22 ;
V_8 -> V_30 = F_26 ( V_22 -> V_23 . V_50 , L_5 , 0 ) ;
if ( ! F_27 ( V_8 -> V_30 ) ) {
F_7 ( & V_22 -> V_23 , L_6 ) ;
return - V_51 ;
}
V_14 = F_28 ( & V_22 -> V_23 , V_8 -> V_30 ,
V_52 ,
L_7 ) ;
if ( V_14 ) {
F_7 ( & V_22 -> V_23 ,
L_8 ,
V_8 -> V_30 , V_14 ) ;
return - V_51 ;
}
for ( V_15 = 0 ; V_15 < V_53 ; V_15 ++ ) {
V_8 -> V_29 [ V_15 ] = F_26 ( V_22 -> V_23 . V_50 ,
L_9 , V_15 ) ;
if ( V_8 -> V_29 [ V_15 ] == - V_54 ) {
F_29 ( & V_22 -> V_23 , L_10 ) ;
return - V_54 ;
}
if ( ! F_27 ( V_8 -> V_29 [ V_15 ] ) ) {
F_7 ( & V_22 -> V_23 , L_11 ) ;
return - V_51 ;
}
V_14 = F_28 ( & V_22 -> V_23 , V_8 -> V_29 [ V_15 ] ,
V_55 , L_12 ) ;
if ( V_14 ) {
F_7 ( & V_22 -> V_23 , L_8 ,
V_8 -> V_29 [ V_15 ] , V_14 ) ;
return - V_51 ;
}
}
V_2 = F_30 ( L_13 , & V_22 -> V_23 , V_8 , & V_56 ) ;
if ( F_31 ( V_2 ) ) {
V_14 = F_32 ( V_2 ) ;
return V_14 ;
}
F_33 ( V_22 , V_2 ) ;
V_14 = F_15 ( V_2 ) ;
if ( V_14 ) {
F_7 ( & V_22 -> V_23 , L_14 ) ;
goto V_57;
}
F_29 ( & V_22 -> V_23 , L_15 ) ;
return 0 ;
V_57:
F_34 ( V_2 ) ;
return V_14 ;
}
static int F_35 ( struct V_49 * V_22 )
{
struct V_1 * V_2 = F_36 ( V_22 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
