static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_4 )
return V_3 ;
V_3 = F_2 ( V_2 -> V_5 ) ;
if ( V_3 != 0 ) {
F_3 ( V_2 -> V_6 . V_7 , L_1 , V_3 ) ;
return V_3 ;
}
V_3 = F_2 ( V_2 -> V_8 ) ;
if ( V_3 != 0 ) {
F_3 ( V_2 -> V_6 . V_7 , L_2 , V_3 ) ;
F_4 ( V_2 -> V_5 ) ;
return V_3 ;
}
V_2 -> V_4 = 1 ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( ! V_2 -> V_4 )
return V_3 ;
V_3 = F_4 ( V_2 -> V_8 ) ;
if ( V_3 != 0 ) {
F_3 ( V_2 -> V_6 . V_7 , L_3 , V_3 ) ;
return V_3 ;
}
V_3 = F_4 ( V_2 -> V_5 ) ;
if ( V_3 != 0 ) {
F_3 ( V_2 -> V_6 . V_7 , L_4 , V_3 ) ;
V_3 = F_2 ( V_2 -> V_8 ) ;
if ( V_3 != 0 )
F_3 ( V_2 -> V_6 . V_7 , L_5 ,
V_3 ) ;
return V_3 ;
}
V_2 -> V_4 = 0 ;
return V_3 ;
}
static int F_6 ( struct V_9 * V_10 ,
enum V_11 V_12 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
unsigned long V_13 ;
int V_3 ;
int V_14 ;
V_2 -> V_12 = V_12 ;
F_8 ( & V_2 -> V_15 , V_13 ) ;
if ( V_2 -> V_12 == V_16 ) {
F_9 ( & V_2 -> V_15 , V_13 ) ;
return F_5 ( V_2 ) ;
}
V_14 = ( V_2 -> V_17 * V_2 -> V_12 ) / V_18 ;
F_9 ( & V_2 -> V_15 , V_13 ) ;
F_10 ( V_14 >= F_11 ( V_19 ) ) ;
V_3 = F_12 ( V_2 -> V_5 , V_19 [ V_14 ] ,
V_19 [ V_14 ] ) ;
if ( V_3 != 0 ) {
F_3 ( V_2 -> V_6 . V_7 , L_6 ,
V_19 [ V_14 ] , V_3 ) ;
return V_3 ;
}
return F_1 ( V_2 ) ;
}
static void F_13 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
V_2 -> V_12 = V_16 ;
F_5 ( V_2 ) ;
}
static int F_15 ( struct V_20 * V_21 )
{
struct V_22 * V_5 , * V_8 ;
struct V_1 * V_2 ;
struct V_23 * V_24 = F_16 ( & V_21 -> V_7 ) ;
int V_25 ;
if ( V_24 == NULL ) {
F_3 ( & V_21 -> V_7 , L_7 ) ;
return - V_26 ;
}
if ( V_24 -> V_27 < V_19 [ 0 ] ) {
F_3 ( & V_21 -> V_7 , L_8 ,
V_24 -> V_27 ) ;
return - V_28 ;
}
V_5 = F_17 ( & V_21 -> V_7 , L_9 ) ;
if ( F_18 ( V_5 ) ) {
F_3 ( & V_21 -> V_7 , L_10 , V_29 ) ;
return F_19 ( V_5 ) ;
}
V_8 = F_17 ( & V_21 -> V_7 , L_11 ) ;
if ( F_18 ( V_8 ) ) {
F_3 ( & V_21 -> V_7 , L_12 , V_29 ) ;
return F_19 ( V_8 ) ;
}
V_2 = F_20 ( & V_21 -> V_7 , sizeof( * V_2 ) , V_30 ) ;
if ( V_2 == NULL )
return - V_31 ;
V_2 -> V_6 . V_32 = F_6 ;
V_2 -> V_6 . V_33 = V_24 -> V_33 ;
V_2 -> V_6 . V_34 = V_24 -> V_34 ;
V_2 -> V_6 . V_13 |= V_35 ;
V_2 -> V_4 = F_21 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_8 = V_8 ;
for ( V_25 = 0 ; V_25 < F_11 ( V_19 ) - 1 ; V_25 ++ )
if ( V_19 [ V_25 ] >= V_24 -> V_27 )
break;
V_2 -> V_17 = V_25 ;
if ( V_24 -> V_27 != V_19 [ V_25 ] )
F_22 ( & V_21 -> V_7 ,
L_13
L_14 ,
V_24 -> V_27 ) ;
F_23 ( & V_2 -> V_15 ) ;
V_2 -> V_12 = V_16 ;
F_24 ( V_21 , V_2 ) ;
return F_25 ( & V_21 -> V_7 , & V_2 -> V_6 ) ;
}
static int F_26 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
F_27 ( & V_2 -> V_6 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
