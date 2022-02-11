static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 -> V_4 , L_1 , V_5 ) ;
V_3 = F_3 ( V_2 -> V_6 , V_7 ,
V_8 ,
V_9 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_4 ,
L_2 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_10 )
return 0 ;
F_2 ( V_2 -> V_4 , L_3 , V_5 ) ;
V_3 = F_6 ( V_2 -> V_6 , V_7 ,
V_11 ,
V_11 ,
V_9 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_4 ,
L_4 ,
V_5 , V_7 , V_3 ) ;
return V_3 ;
}
V_2 -> V_10 = 1 ;
return 0 ;
}
static int F_7 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
union V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
if ( V_15 == V_18 ) {
V_17 -> V_19 = V_2 -> V_10 ;
return 0 ;
}
return - V_20 ;
}
static T_1 F_9 ( int V_21 , void * V_4 )
{
int V_3 , V_17 ;
struct V_1 * V_2 = V_4 ;
V_2 -> V_22 = V_2 -> V_10 ;
V_3 = F_10 ( V_2 -> V_6 , V_23 , & V_17 ) ;
if ( V_3 < 0 ) {
F_4 ( V_2 -> V_4 , L_5 ,
V_5 , V_23 ) ;
return V_24 ;
}
F_2 ( V_2 -> V_4 , L_6 , V_5 , V_17 ) ;
if ( V_17 & V_25 ) {
V_3 = F_5 ( V_2 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_4 ,
L_7 , V_3 ) ;
return V_24 ;
}
} else {
V_2 -> V_10 = 0 ;
}
if ( V_2 -> V_22 != V_2 -> V_10 )
F_11 ( V_2 -> V_13 ) ;
V_3 = F_10 ( V_2 -> V_6 , V_26 , & V_17 ) ;
if ( V_3 < 0 ) {
F_4 ( V_2 -> V_4 , L_5 ,
V_5 , V_26 ) ;
return V_24 ;
}
if ( V_17 & V_27 )
F_2 ( V_2 -> V_4 , L_8 , V_5 ) ;
else
F_2 ( V_2 -> V_4 ,
L_9 , V_5 ) ;
return V_24 ;
}
static int F_12 ( void * V_28 )
{
F_13 () ;
while ( ! F_14 () ) {
F_15 ( V_29 ) ;
F_16 () ;
F_9 ( - 1 , V_28 ) ;
}
return 0 ;
}
static int F_17 ( struct V_30 * V_31 )
{
struct V_32 * V_6 = F_18 ( V_31 -> V_4 . V_33 ) ;
struct V_1 * V_2 ;
struct V_34 V_35 = {} ;
struct V_36 * V_37 ;
int V_21 [ V_38 ] ;
int V_3 ;
int V_39 ;
F_2 ( & V_31 -> V_4 , L_1 , V_5 ) ;
V_2 = F_19 ( & V_31 -> V_4 , sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return - V_41 ;
F_20 ( V_31 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_4 = & V_31 -> V_4 ;
V_35 . V_42 = V_31 -> V_4 . V_42 ;
V_35 . V_43 = V_2 ;
V_2 -> V_13 = F_21 ( & V_31 -> V_4 ,
& V_44 ,
& V_35 ) ;
if ( F_22 ( V_2 -> V_13 ) ) {
F_4 ( & V_31 -> V_4 , L_10 ) ;
return F_23 ( V_2 -> V_13 ) ;
}
V_21 [ 0 ] = F_24 ( V_31 , L_11 ) ;
V_21 [ 1 ] = F_24 ( V_31 , L_12 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_4 ( V_2 -> V_4 , L_13 , V_3 ) ;
return V_3 ;
}
if ( V_21 [ 0 ] < 0 || V_21 [ 1 ] < 0 ) {
V_37 = F_25 ( F_12 ,
V_2 , L_14 ) ;
if ( F_22 ( V_37 ) ) {
V_3 = F_23 ( V_37 ) ;
F_4 ( V_2 -> V_4 ,
L_15 , V_3 ) ;
return V_3 ;
}
V_2 -> V_37 = V_37 ;
return 0 ;
}
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ ) {
V_3 = F_26 ( & V_31 -> V_4 , V_21 [ V_39 ] , NULL ,
F_9 ,
0 , L_16 ,
V_2 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_4 ,
L_17 , V_21 [ V_39 ] ,
V_3 ) ;
return V_3 ;
}
F_9 ( - 1 , V_2 ) ;
}
return 0 ;
}
static int F_27 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_28 ( V_31 ) ;
if ( V_2 -> V_37 )
F_29 ( V_2 -> V_37 ) ;
return 0 ;
}
