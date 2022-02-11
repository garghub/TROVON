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
( * V_4 ) [ V_12 ] . V_21 = V_22 ;
V_12 ++ ;
}
if ( ! V_12 ) {
F_6 ( V_10 ) ;
F_7 ( L_5 , V_8 -> V_23 ) ;
F_8 ( * V_4 ) ;
* V_4 = NULL ;
return - V_24 ;
}
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_25 ;
int V_12 , V_26 , V_11 ;
const struct {
T_1 V_18 , V_17 ;
} * V_27 ;
const char * V_28 ;
if ( ! V_6 )
return 0 ;
V_25 = V_6 -> V_13 ;
if ( ! V_25 )
return 0 ;
V_27 = F_4 ( V_25 , L_6 , & V_26 ) ;
if ( ! V_27 )
return 0 ;
F_10 ( L_7 ,
V_25 -> V_23 ) ;
V_11 = V_26 / sizeof( V_27 [ 0 ] ) ;
* V_4 = F_3 ( V_11 * sizeof( * ( * V_4 ) ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_28 = F_4 ( V_25 , L_8 , & V_26 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
( * V_4 ) [ V_12 ] . V_18 = F_5 ( V_27 -> V_18 ) ;
( * V_4 ) [ V_12 ] . V_19 = F_5 ( V_27 -> V_17 ) & ~ 1 ;
if ( F_5 ( V_27 -> V_17 ) & 1 )
( * V_4 ) [ V_12 ] . V_21 = V_22 ;
if ( V_28 && ( V_26 > 0 ) ) {
int V_17 = strlen ( V_28 ) + 1 ;
( * V_4 ) [ V_12 ] . V_20 = ( char * ) V_28 ;
V_26 -= V_17 ;
V_28 += V_17 ;
} else {
( * V_4 ) [ V_12 ] . V_20 = L_9 ;
}
V_27 ++ ;
}
return V_11 ;
}
static int T_2 F_11 ( void )
{
int V_29 ;
V_29 = F_12 ( & V_30 ) ;
if ( V_29 )
goto V_31;
V_29 = F_12 ( & V_32 ) ;
if ( ! V_29 )
return 0 ;
F_13 ( & V_32 ) ;
V_31:
return V_29 ;
}
