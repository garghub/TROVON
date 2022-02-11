static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
int V_7 ;
V_7 = F_2 ( V_4 , V_8 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_4 , & V_6 ) ;
if ( V_7 )
return V_7 ;
return V_6 == V_8 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
int V_7 ;
V_7 = F_3 ( V_4 , & V_6 ) ;
if ( V_7 ) {
F_5 ( L_1 , V_9 ) ;
return;
}
if ( V_6 != V_8 ) {
F_5 ( L_2 ,
V_9 , V_6 ) ;
}
V_7 = F_2 ( V_4 , 0 ) ;
if ( V_7 )
F_5 ( L_3 , V_9 ) ;
}
static int F_6 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 V_4 ;
struct V_17 * V_17 ;
T_2 V_18 ;
T_1 V_19 ;
T_1 V_20 ;
int V_7 ;
int V_21 ;
V_15 = F_7 ( V_11 -> V_22 . V_23 , L_4 , 0 ) ;
if ( ! V_15 ) {
F_8 ( & V_11 -> V_22 , L_5 ) ;
return - V_24 ;
}
V_17 = F_9 ( V_15 ) ;
F_10 ( V_15 ) ;
if ( F_11 ( V_17 ) )
return F_12 ( V_17 ) ;
V_7 = F_13 ( V_11 -> V_22 . V_23 , L_4 , 1 , & V_20 ) ;
if ( V_7 < 0 ) {
F_8 ( & V_11 -> V_22 , L_6 ) ;
return - V_25 ;
}
V_7 = F_13 ( V_11 -> V_22 . V_23 , L_4 , 2 , & V_19 ) ;
if ( V_7 < 0 ) {
F_8 ( & V_11 -> V_22 , L_7 ) ;
return - V_25 ;
}
V_18 = V_26 * sizeof( struct V_1 ) ;
V_13 = F_14 ( & V_11 -> V_22 , sizeof( * V_13 ) + V_18 , V_27 ) ;
if ( ! V_13 )
return - V_28 ;
F_15 ( V_11 , V_13 ) ;
for ( V_21 = 0 ; V_21 < V_26 ; V_21 ++ ) {
V_4 . V_29 = V_20 + V_21 * V_19 ;
V_4 . V_30 = 0 ;
V_4 . V_31 = 31 ;
V_13 -> V_2 [ V_21 ] . V_5 = F_16 ( & V_11 -> V_22 ,
V_17 , V_4 ) ;
}
F_17 ( & V_11 -> V_22 ) ;
V_7 = F_18 ( V_13 , & V_11 -> V_22 , & V_32 ,
0 , V_26 ) ;
if ( V_7 )
F_19 ( & V_11 -> V_22 ) ;
return V_7 ;
}
static int F_20 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_21 ( V_11 ) ;
int V_7 ;
V_7 = F_22 ( V_13 ) ;
if ( V_7 ) {
F_8 ( & V_11 -> V_22 , L_8 , V_9 , V_7 ) ;
return V_7 ;
}
F_19 ( & V_11 -> V_22 ) ;
return 0 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_33 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_33 ) ;
}
