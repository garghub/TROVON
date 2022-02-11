static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , L_1 , NULL ) ;
}
static int F_3 ( struct V_3 * V_4 ,
struct V_5 * * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_9 ;
struct V_1 * V_10 ;
const char * V_11 ;
struct V_1 * V_2 ;
int V_12 , V_13 , V_14 = 0 ;
bool V_15 = true ;
if ( ! V_8 )
return 0 ;
V_9 = V_8 -> V_16 ;
if ( ! V_9 )
return 0 ;
V_10 = F_4 ( V_9 , L_2 ) ;
if ( ! V_10 ) {
F_5 ( L_3 ,
V_4 -> V_17 , V_9 -> V_18 ) ;
V_10 = V_9 ;
V_15 = false ;
} else if ( ! F_6 ( V_10 , L_4 ) ) {
return 0 ;
}
V_12 = 0 ;
F_7 (ofpart_node, pp) {
if ( ! V_15 && F_1 ( V_2 ) )
continue;
V_12 ++ ;
}
if ( V_12 == 0 )
return 0 ;
* V_6 = F_8 ( V_12 * sizeof( * * V_6 ) , V_19 ) ;
if ( ! * V_6 )
return - V_20 ;
V_13 = 0 ;
F_7 (ofpart_node, pp) {
const T_1 * V_21 ;
int V_22 ;
int V_23 , V_24 ;
if ( ! V_15 && F_1 ( V_2 ) )
continue;
V_21 = F_2 ( V_2 , L_5 , & V_22 ) ;
if ( ! V_21 ) {
if ( V_15 ) {
F_5 ( L_6 ,
V_4 -> V_17 , V_2 -> V_18 ,
V_9 -> V_18 ) ;
goto V_25;
} else {
V_12 -- ;
continue;
}
}
V_23 = F_9 ( V_2 ) ;
V_24 = F_10 ( V_2 ) ;
if ( V_22 / 4 != V_23 + V_24 ) {
F_5 ( L_7 ,
V_4 -> V_17 , V_2 -> V_18 ,
V_9 -> V_18 ) ;
goto V_25;
}
( * V_6 ) [ V_13 ] . V_26 = F_11 ( V_21 , V_23 ) ;
( * V_6 ) [ V_13 ] . V_27 = F_11 ( V_21 + V_23 , V_24 ) ;
V_11 = F_2 ( V_2 , L_8 , & V_22 ) ;
if ( ! V_11 )
V_11 = F_2 ( V_2 , L_9 , & V_22 ) ;
( * V_6 ) [ V_13 ] . V_17 = V_11 ;
if ( F_2 ( V_2 , L_10 , & V_22 ) )
( * V_6 ) [ V_13 ] . V_28 |= V_29 ;
if ( F_2 ( V_2 , L_11 , & V_22 ) )
( * V_6 ) [ V_13 ] . V_28 |= V_30 ;
V_13 ++ ;
}
if ( ! V_12 )
goto V_31;
return V_12 ;
V_25:
F_12 ( L_12 ,
V_4 -> V_17 , V_2 -> V_18 , V_9 -> V_18 ) ;
V_14 = - V_32 ;
V_31:
F_13 ( V_2 ) ;
F_14 ( * V_6 ) ;
* V_6 = NULL ;
return V_14 ;
}
static int F_15 ( struct V_3 * V_4 ,
struct V_5 * * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_33 ;
int V_13 , V_34 , V_12 ;
const struct {
T_1 V_26 , V_22 ;
} * V_35 ;
const char * V_36 ;
if ( ! V_8 )
return 0 ;
V_33 = V_8 -> V_16 ;
if ( ! V_33 )
return 0 ;
V_35 = F_2 ( V_33 , L_2 , & V_34 ) ;
if ( ! V_35 )
return 0 ;
F_16 ( L_13 ,
V_33 -> V_18 ) ;
V_12 = V_34 / sizeof( V_35 [ 0 ] ) ;
* V_6 = F_8 ( V_12 * sizeof( * ( * V_6 ) ) , V_19 ) ;
if ( ! * V_6 )
return - V_20 ;
V_36 = F_2 ( V_33 , L_14 , & V_34 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
( * V_6 ) [ V_13 ] . V_26 = F_17 ( V_35 -> V_26 ) ;
( * V_6 ) [ V_13 ] . V_27 = F_17 ( V_35 -> V_22 ) & ~ 1 ;
if ( F_17 ( V_35 -> V_22 ) & 1 )
( * V_6 ) [ V_13 ] . V_28 = V_29 ;
if ( V_36 && ( V_34 > 0 ) ) {
int V_22 = strlen ( V_36 ) + 1 ;
( * V_6 ) [ V_13 ] . V_17 = V_36 ;
V_34 -= V_22 ;
V_36 += V_22 ;
} else {
( * V_6 ) [ V_13 ] . V_17 = L_15 ;
}
V_35 ++ ;
}
return V_12 ;
}
static int T_2 F_18 ( void )
{
F_19 ( & V_37 ) ;
F_19 ( & V_38 ) ;
return 0 ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_37 ) ;
F_21 ( & V_38 ) ;
}
