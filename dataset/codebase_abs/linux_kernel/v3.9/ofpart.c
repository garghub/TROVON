static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
const char * V_9 ;
struct V_7 * V_10 ;
int V_11 , V_12 ;
if ( ! V_6 )
return 0 ;
V_8 = V_6 -> V_13 ;
if ( ! V_8 )
return 0 ;
V_10 = NULL ;
V_11 = 0 ;
while ( ( V_10 = F_2 ( V_8 , V_10 ) ) )
V_11 ++ ;
if ( V_11 == 0 )
return 0 ;
* V_4 = F_3 ( V_11 * sizeof( * * V_4 ) , V_14 ) ;
if ( ! * V_4 )
return - V_15 ;
V_10 = NULL ;
V_12 = 0 ;
while ( ( V_10 = F_2 ( V_8 , V_10 ) ) ) {
const T_1 * V_16 ;
int V_17 ;
V_16 = F_4 ( V_10 , L_1 , & V_17 ) ;
if ( ! V_16 ) {
V_11 -- ;
continue;
}
( * V_4 ) [ V_12 ] . V_18 = F_5 ( V_16 [ 0 ] ) ;
( * V_4 ) [ V_12 ] . V_19 = F_5 ( V_16 [ 1 ] ) ;
V_9 = F_4 ( V_10 , L_2 , & V_17 ) ;
if ( ! V_9 )
V_9 = F_4 ( V_10 , L_3 , & V_17 ) ;
( * V_4 ) [ V_12 ] . V_20 = ( char * ) V_9 ;
if ( F_4 ( V_10 , L_4 , & V_17 ) )
( * V_4 ) [ V_12 ] . V_21 |= V_22 ;
if ( F_4 ( V_10 , L_5 , & V_17 ) )
( * V_4 ) [ V_12 ] . V_21 |= V_23 ;
V_12 ++ ;
}
if ( ! V_12 ) {
F_6 ( V_10 ) ;
F_7 ( L_6 , V_8 -> V_24 ) ;
F_8 ( * V_4 ) ;
* V_4 = NULL ;
return - V_25 ;
}
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_26 ;
int V_12 , V_27 , V_11 ;
const struct {
T_1 V_18 , V_17 ;
} * V_28 ;
const char * V_29 ;
if ( ! V_6 )
return 0 ;
V_26 = V_6 -> V_13 ;
if ( ! V_26 )
return 0 ;
V_28 = F_4 ( V_26 , L_7 , & V_27 ) ;
if ( ! V_28 )
return 0 ;
F_10 ( L_8 ,
V_26 -> V_24 ) ;
V_11 = V_27 / sizeof( V_28 [ 0 ] ) ;
* V_4 = F_3 ( V_11 * sizeof( * ( * V_4 ) ) , V_14 ) ;
if ( ! * V_4 )
return - V_15 ;
V_29 = F_4 ( V_26 , L_9 , & V_27 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
( * V_4 ) [ V_12 ] . V_18 = F_5 ( V_28 -> V_18 ) ;
( * V_4 ) [ V_12 ] . V_19 = F_5 ( V_28 -> V_17 ) & ~ 1 ;
if ( F_5 ( V_28 -> V_17 ) & 1 )
( * V_4 ) [ V_12 ] . V_21 = V_22 ;
if ( V_29 && ( V_27 > 0 ) ) {
int V_17 = strlen ( V_29 ) + 1 ;
( * V_4 ) [ V_12 ] . V_20 = ( char * ) V_29 ;
V_27 -= V_17 ;
V_29 += V_17 ;
} else {
( * V_4 ) [ V_12 ] . V_20 = L_10 ;
}
V_28 ++ ;
}
return V_11 ;
}
static int T_2 F_11 ( void )
{
int V_30 ;
V_30 = F_12 ( & V_31 ) ;
if ( V_30 )
goto V_32;
V_30 = F_12 ( & V_33 ) ;
if ( ! V_30 )
return 0 ;
F_13 ( & V_33 ) ;
V_32:
return V_30 ;
}
static void T_3 F_14 ( void )
{
F_13 ( & V_31 ) ;
F_13 ( & V_33 ) ;
}
