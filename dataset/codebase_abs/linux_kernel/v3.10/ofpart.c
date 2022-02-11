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
int V_18 , V_19 ;
V_16 = F_4 ( V_10 , L_1 , & V_17 ) ;
if ( ! V_16 ) {
V_11 -- ;
continue;
}
V_18 = F_5 ( V_10 ) ;
V_19 = F_6 ( V_10 ) ;
( * V_4 ) [ V_12 ] . V_20 = F_7 ( V_16 , V_18 ) ;
( * V_4 ) [ V_12 ] . V_21 = F_7 ( V_16 + V_18 , V_19 ) ;
V_9 = F_4 ( V_10 , L_2 , & V_17 ) ;
if ( ! V_9 )
V_9 = F_4 ( V_10 , L_3 , & V_17 ) ;
( * V_4 ) [ V_12 ] . V_22 = ( char * ) V_9 ;
if ( F_4 ( V_10 , L_4 , & V_17 ) )
( * V_4 ) [ V_12 ] . V_23 |= V_24 ;
if ( F_4 ( V_10 , L_5 , & V_17 ) )
( * V_4 ) [ V_12 ] . V_23 |= V_25 ;
V_12 ++ ;
}
if ( ! V_12 ) {
F_8 ( V_10 ) ;
F_9 ( L_6 , V_8 -> V_26 ) ;
F_10 ( * V_4 ) ;
* V_4 = NULL ;
return - V_27 ;
}
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_28 ;
int V_12 , V_29 , V_11 ;
const struct {
T_1 V_20 , V_17 ;
} * V_30 ;
const char * V_31 ;
if ( ! V_6 )
return 0 ;
V_28 = V_6 -> V_13 ;
if ( ! V_28 )
return 0 ;
V_30 = F_4 ( V_28 , L_7 , & V_29 ) ;
if ( ! V_30 )
return 0 ;
F_12 ( L_8 ,
V_28 -> V_26 ) ;
V_11 = V_29 / sizeof( V_30 [ 0 ] ) ;
* V_4 = F_3 ( V_11 * sizeof( * ( * V_4 ) ) , V_14 ) ;
if ( ! * V_4 )
return - V_15 ;
V_31 = F_4 ( V_28 , L_9 , & V_29 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
( * V_4 ) [ V_12 ] . V_20 = F_13 ( V_30 -> V_20 ) ;
( * V_4 ) [ V_12 ] . V_21 = F_13 ( V_30 -> V_17 ) & ~ 1 ;
if ( F_13 ( V_30 -> V_17 ) & 1 )
( * V_4 ) [ V_12 ] . V_23 = V_24 ;
if ( V_31 && ( V_29 > 0 ) ) {
int V_17 = strlen ( V_31 ) + 1 ;
( * V_4 ) [ V_12 ] . V_22 = ( char * ) V_31 ;
V_29 -= V_17 ;
V_31 += V_17 ;
} else {
( * V_4 ) [ V_12 ] . V_22 = L_10 ;
}
V_30 ++ ;
}
return V_11 ;
}
static int T_2 F_14 ( void )
{
int V_32 ;
V_32 = F_15 ( & V_33 ) ;
if ( V_32 )
goto V_34;
V_32 = F_15 ( & V_35 ) ;
if ( ! V_32 )
return 0 ;
F_16 ( & V_35 ) ;
V_34:
return V_32 ;
}
static void T_3 F_17 ( void )
{
F_16 ( & V_33 ) ;
F_16 ( & V_35 ) ;
}
