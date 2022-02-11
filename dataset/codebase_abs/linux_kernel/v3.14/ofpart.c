static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , L_1 , NULL ) ;
}
static int F_3 ( struct V_3 * V_4 ,
struct V_5 * * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_9 ;
const char * V_10 ;
struct V_1 * V_2 ;
int V_11 , V_12 ;
if ( ! V_8 )
return 0 ;
V_9 = V_8 -> V_13 ;
if ( ! V_9 )
return 0 ;
V_11 = 0 ;
F_4 (node, pp) {
if ( F_1 ( V_2 ) )
continue;
V_11 ++ ;
}
if ( V_11 == 0 )
return 0 ;
* V_6 = F_5 ( V_11 * sizeof( * * V_6 ) , V_14 ) ;
if ( ! * V_6 )
return - V_15 ;
V_12 = 0 ;
F_4 (node, pp) {
const T_1 * V_16 ;
int V_17 ;
int V_18 , V_19 ;
if ( F_1 ( V_2 ) )
continue;
V_16 = F_2 ( V_2 , L_2 , & V_17 ) ;
if ( ! V_16 ) {
V_11 -- ;
continue;
}
V_18 = F_6 ( V_2 ) ;
V_19 = F_7 ( V_2 ) ;
( * V_6 ) [ V_12 ] . V_20 = F_8 ( V_16 , V_18 ) ;
( * V_6 ) [ V_12 ] . V_21 = F_8 ( V_16 + V_18 , V_19 ) ;
V_10 = F_2 ( V_2 , L_3 , & V_17 ) ;
if ( ! V_10 )
V_10 = F_2 ( V_2 , L_4 , & V_17 ) ;
( * V_6 ) [ V_12 ] . V_22 = V_10 ;
if ( F_2 ( V_2 , L_5 , & V_17 ) )
( * V_6 ) [ V_12 ] . V_23 |= V_24 ;
if ( F_2 ( V_2 , L_6 , & V_17 ) )
( * V_6 ) [ V_12 ] . V_23 |= V_25 ;
V_12 ++ ;
}
if ( ! V_12 ) {
F_9 ( V_2 ) ;
F_10 ( L_7 , V_9 -> V_26 ) ;
F_11 ( * V_6 ) ;
* V_6 = NULL ;
return - V_27 ;
}
return V_11 ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_5 * * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_28 ;
int V_12 , V_29 , V_11 ;
const struct {
T_1 V_20 , V_17 ;
} * V_30 ;
const char * V_31 ;
if ( ! V_8 )
return 0 ;
V_28 = V_8 -> V_13 ;
if ( ! V_28 )
return 0 ;
V_30 = F_2 ( V_28 , L_8 , & V_29 ) ;
if ( ! V_30 )
return 0 ;
F_13 ( L_9 ,
V_28 -> V_26 ) ;
V_11 = V_29 / sizeof( V_30 [ 0 ] ) ;
* V_6 = F_5 ( V_11 * sizeof( * ( * V_6 ) ) , V_14 ) ;
if ( ! * V_6 )
return - V_15 ;
V_31 = F_2 ( V_28 , L_10 , & V_29 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
( * V_6 ) [ V_12 ] . V_20 = F_14 ( V_30 -> V_20 ) ;
( * V_6 ) [ V_12 ] . V_21 = F_14 ( V_30 -> V_17 ) & ~ 1 ;
if ( F_14 ( V_30 -> V_17 ) & 1 )
( * V_6 ) [ V_12 ] . V_23 = V_24 ;
if ( V_31 && ( V_29 > 0 ) ) {
int V_17 = strlen ( V_31 ) + 1 ;
( * V_6 ) [ V_12 ] . V_22 = V_31 ;
V_29 -= V_17 ;
V_31 += V_17 ;
} else {
( * V_6 ) [ V_12 ] . V_22 = L_11 ;
}
V_30 ++ ;
}
return V_11 ;
}
static int T_2 F_15 ( void )
{
F_16 ( & V_32 ) ;
F_16 ( & V_33 ) ;
return 0 ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_32 ) ;
F_18 ( & V_33 ) ;
}
