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
V_4 -> V_17 , V_10 ) ;
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
V_9 = F_9 ( V_13 * sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 )
return - V_19 ;
V_14 = 0 ;
F_8 (ofpart_node, pp) {
const T_1 * V_20 ;
int V_21 ;
int V_22 , V_23 ;
if ( ! V_16 && F_1 ( V_2 ) )
continue;
V_20 = F_2 ( V_2 , L_5 , & V_21 ) ;
if ( ! V_20 ) {
if ( V_16 ) {
F_6 ( L_6 ,
V_4 -> V_17 , V_2 ,
V_10 ) ;
goto V_24;
} else {
V_13 -- ;
continue;
}
}
V_22 = F_10 ( V_2 ) ;
V_23 = F_11 ( V_2 ) ;
if ( V_21 / 4 != V_22 + V_23 ) {
F_6 ( L_7 ,
V_4 -> V_17 , V_2 ,
V_10 ) ;
goto V_24;
}
V_9 [ V_14 ] . V_25 = F_12 ( V_20 , V_22 ) ;
V_9 [ V_14 ] . V_26 = F_12 ( V_20 + V_22 , V_23 ) ;
V_9 [ V_14 ] . V_27 = V_2 ;
V_12 = F_2 ( V_2 , L_8 , & V_21 ) ;
if ( ! V_12 )
V_12 = F_2 ( V_2 , L_9 , & V_21 ) ;
V_9 [ V_14 ] . V_17 = V_12 ;
if ( F_2 ( V_2 , L_10 , & V_21 ) )
V_9 [ V_14 ] . V_28 |= V_29 ;
if ( F_2 ( V_2 , L_11 , & V_21 ) )
V_9 [ V_14 ] . V_28 |= V_30 ;
V_14 ++ ;
}
if ( ! V_13 )
goto V_31;
* V_6 = V_9 ;
return V_13 ;
V_24:
F_13 ( L_12 ,
V_4 -> V_17 , V_2 , V_10 ) ;
V_15 = - V_32 ;
V_31:
F_14 ( V_2 ) ;
F_15 ( V_9 ) ;
return V_15 ;
}
static int F_16 ( struct V_3 * V_4 ,
const struct V_5 * * V_6 ,
struct V_7 * V_8 )
{
struct V_5 * V_9 ;
struct V_1 * V_33 ;
int V_14 , V_34 , V_13 ;
const struct {
T_1 V_25 , V_21 ;
} * V_35 ;
const char * V_36 ;
V_33 = F_4 ( V_4 ) ;
if ( ! V_33 )
return 0 ;
V_35 = F_2 ( V_33 , L_2 , & V_34 ) ;
if ( ! V_35 )
return 0 ;
F_17 ( L_13 , V_33 ) ;
V_13 = V_34 / sizeof( V_35 [ 0 ] ) ;
V_9 = F_9 ( V_13 * sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 )
return - V_19 ;
V_36 = F_2 ( V_33 , L_14 , & V_34 ) ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
V_9 [ V_14 ] . V_25 = F_18 ( V_35 -> V_25 ) ;
V_9 [ V_14 ] . V_26 = F_18 ( V_35 -> V_21 ) & ~ 1 ;
if ( F_18 ( V_35 -> V_21 ) & 1 )
V_9 [ V_14 ] . V_28 = V_29 ;
if ( V_36 && ( V_34 > 0 ) ) {
int V_21 = strlen ( V_36 ) + 1 ;
V_9 [ V_14 ] . V_17 = V_36 ;
V_34 -= V_21 ;
V_36 += V_21 ;
} else {
V_9 [ V_14 ] . V_17 = L_15 ;
}
V_35 ++ ;
}
* V_6 = V_9 ;
return V_13 ;
}
static int T_2 F_19 ( void )
{
F_20 ( & V_37 ) ;
F_20 ( & V_38 ) ;
return 0 ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_37 ) ;
F_22 ( & V_38 ) ;
}
