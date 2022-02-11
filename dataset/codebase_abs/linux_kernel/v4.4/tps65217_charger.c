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
F_11 ( V_2 -> V_26 ) ;
V_3 = F_10 ( V_2 -> V_6 , V_27 , & V_17 ) ;
if ( V_3 < 0 ) {
F_4 ( V_2 -> V_4 , L_5 ,
V_5 , V_27 ) ;
return V_24 ;
}
if ( V_17 & V_28 )
F_2 ( V_2 -> V_4 , L_8 , V_5 ) ;
else
F_2 ( V_2 -> V_4 ,
L_9 , V_5 ) ;
return V_24 ;
}
static int F_12 ( void * V_29 )
{
F_13 () ;
while ( ! F_14 () ) {
F_15 ( V_30 ) ;
F_16 () ;
F_9 ( - 1 , V_29 ) ;
}
return 0 ;
}
static int F_17 ( struct V_31 * V_32 )
{
struct V_33 * V_6 = F_18 ( V_32 -> V_4 . V_34 ) ;
struct V_1 * V_2 ;
int V_3 ;
F_2 ( & V_32 -> V_4 , L_1 , V_5 ) ;
V_2 = F_19 ( & V_32 -> V_4 , sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_4 = & V_32 -> V_4 ;
V_2 -> V_26 = F_20 ( & V_32 -> V_4 ,
& V_37 ,
NULL ) ;
if ( F_21 ( V_2 -> V_26 ) ) {
F_4 ( & V_32 -> V_4 , L_10 ) ;
return F_22 ( V_2 -> V_26 ) ;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_4 ( V_2 -> V_4 , L_11 , V_3 ) ;
return V_3 ;
}
V_2 -> V_38 = F_23 ( F_12 ,
V_2 , L_12 ) ;
if ( F_21 ( V_2 -> V_38 ) ) {
V_3 = F_22 ( V_2 -> V_38 ) ;
F_4 ( V_2 -> V_4 , L_13 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static int F_24 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_25 ( V_32 ) ;
F_26 ( V_2 -> V_38 ) ;
return 0 ;
}
