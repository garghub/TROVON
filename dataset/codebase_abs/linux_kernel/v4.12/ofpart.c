static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , L_1 , NULL ) ;
}
static int F_3 ( struct V_3 * V_4 ,
const struct V_5 * * V_6 ,
struct V_7 * V_8 )
{
struct V_5 * V_9 ;
struct V_1 * V_10 ;
struct V_1 * V_11 ;
const char * V_12 ;
struct V_1 * V_2 ;
int V_13 , V_14 , V_15 = 0 ;
bool V_16 = true ;
V_10 = F_4 ( V_4 ) ;
if ( ! V_10 )
return 0 ;
V_11 = F_5 ( V_10 , L_2 ) ;
if ( ! V_11 ) {
F_6 ( L_3 ,
V_4 -> V_17 , V_10 -> V_18 ) ;
V_11 = V_10 ;
V_16 = false ;
} else if ( ! F_7 ( V_11 , L_4 ) ) {
return 0 ;
}
V_13 = 0 ;
F_8 (ofpart_node, pp) {
if ( ! V_16 && F_1 ( V_2 ) )
continue;
V_13 ++ ;
}
if ( V_13 == 0 )
return 0 ;
V_9 = F_9 ( V_13 * sizeof( * V_9 ) , V_19 ) ;
if ( ! V_9 )
return - V_20 ;
V_14 = 0 ;
F_8 (ofpart_node, pp) {
const T_1 * V_21 ;
int V_22 ;
int V_23 , V_24 ;
if ( ! V_16 && F_1 ( V_2 ) )
continue;
V_21 = F_2 ( V_2 , L_5 , & V_22 ) ;
if ( ! V_21 ) {
if ( V_16 ) {
F_6 ( L_6 ,
V_4 -> V_17 , V_2 -> V_18 ,
V_10 -> V_18 ) ;
goto V_25;
} else {
V_13 -- ;
continue;
}
}
V_23 = F_10 ( V_2 ) ;
V_24 = F_11 ( V_2 ) ;
if ( V_22 / 4 != V_23 + V_24 ) {
F_6 ( L_7 ,
V_4 -> V_17 , V_2 -> V_18 ,
V_10 -> V_18 ) ;
goto V_25;
}
V_9 [ V_14 ] . V_26 = F_12 ( V_21 , V_23 ) ;
V_9 [ V_14 ] . V_27 = F_12 ( V_21 + V_23 , V_24 ) ;
V_9 [ V_14 ] . V_28 = V_2 ;
V_12 = F_2 ( V_2 , L_8 , & V_22 ) ;
if ( ! V_12 )
V_12 = F_2 ( V_2 , L_9 , & V_22 ) ;
V_9 [ V_14 ] . V_17 = V_12 ;
if ( F_2 ( V_2 , L_10 , & V_22 ) )
V_9 [ V_14 ] . V_29 |= V_30 ;
if ( F_2 ( V_2 , L_11 , & V_22 ) )
V_9 [ V_14 ] . V_29 |= V_31 ;
V_14 ++ ;
}
if ( ! V_13 )
goto V_32;
* V_6 = V_9 ;
return V_13 ;
V_25:
F_13 ( L_12 ,
V_4 -> V_17 , V_2 -> V_18 , V_10 -> V_18 ) ;
V_15 = - V_33 ;
V_32:
F_14 ( V_2 ) ;
F_15 ( V_9 ) ;
return V_15 ;
}
static int F_16 ( struct V_3 * V_4 ,
const struct V_5 * * V_6 ,
struct V_7 * V_8 )
{
struct V_5 * V_9 ;
struct V_1 * V_34 ;
int V_14 , V_35 , V_13 ;
const struct {
T_1 V_26 , V_22 ;
} * V_36 ;
const char * V_37 ;
V_34 = F_4 ( V_4 ) ;
if ( ! V_34 )
return 0 ;
V_36 = F_2 ( V_34 , L_2 , & V_35 ) ;
if ( ! V_36 )
return 0 ;
F_17 ( L_13 ,
V_34 -> V_18 ) ;
V_13 = V_35 / sizeof( V_36 [ 0 ] ) ;
V_9 = F_9 ( V_13 * sizeof( * V_9 ) , V_19 ) ;
if ( ! V_9 )
return - V_20 ;
V_37 = F_2 ( V_34 , L_14 , & V_35 ) ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
V_9 [ V_14 ] . V_26 = F_18 ( V_36 -> V_26 ) ;
V_9 [ V_14 ] . V_27 = F_18 ( V_36 -> V_22 ) & ~ 1 ;
if ( F_18 ( V_36 -> V_22 ) & 1 )
V_9 [ V_14 ] . V_29 = V_30 ;
if ( V_37 && ( V_35 > 0 ) ) {
int V_22 = strlen ( V_37 ) + 1 ;
V_9 [ V_14 ] . V_17 = V_37 ;
V_35 -= V_22 ;
V_37 += V_22 ;
} else {
V_9 [ V_14 ] . V_17 = L_15 ;
}
V_36 ++ ;
}
* V_6 = V_9 ;
return V_13 ;
}
static int T_2 F_19 ( void )
{
F_20 ( & V_38 ) ;
F_20 ( & V_39 ) ;
return 0 ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_38 ) ;
F_22 ( & V_39 ) ;
}
