static unsigned int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 |= F_2 ( V_2 -> V_4 [ V_5 ] ) ? ( 1 << 0 ) : 0 ;
V_3 |= F_2 ( V_2 -> V_4 [ V_6 ] ) ? ( 1 << 1 ) : 0 ;
V_3 |= F_2 ( V_2 -> V_4 [ V_7 ] ) ? ( 1 << 2 ) : 0 ;
return V_3 ;
}
static int F_3 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_5 ( & V_2 -> V_10 ) ;
F_6 ( V_2 -> V_4 [ V_11 ] , 1 ) ;
F_7 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_5 ( & V_2 -> V_10 ) ;
F_6 ( V_2 -> V_4 [ V_11 ] , 0 ) ;
F_7 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_5 ( & V_2 -> V_10 ) ;
F_6 ( V_2 -> V_4 [ V_12 ] , 0 ) ;
F_10 ( 10 ) ;
F_6 ( V_2 -> V_4 [ V_12 ] , 1 ) ;
F_7 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 ,
unsigned int V_13 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
if ( V_13 != 1 && V_13 != 30 ) {
F_12 ( V_9 -> V_14 , L_1 ) ;
return - V_15 ;
}
if ( V_13 == 30 && V_9 -> V_13 == 1 ) {
F_12 ( V_9 -> V_14 ,
L_2 ) ;
return - V_15 ;
}
F_5 ( & V_2 -> V_10 ) ;
if ( V_13 == 1 )
F_6 ( V_2 -> V_4 [ V_16 ] , 1 ) ;
else
F_6 ( V_2 -> V_4 [ V_16 ] , 0 ) ;
V_9 -> V_13 = V_13 ;
F_7 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_13 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
unsigned int V_3 = 0 ;
int V_21 ;
int V_22 ;
int V_23 ;
V_2 = F_14 ( & V_18 -> V_14 , sizeof( struct V_1 ) , V_24 ) ;
if ( ! V_2 )
return - V_25 ;
V_20 = V_18 -> V_14 . V_26 ;
V_21 = F_15 ( V_20 ) ;
if ( V_21 != V_27 ) {
F_12 ( & V_18 -> V_14 , L_3 ,
V_21 , V_27 ) ;
return - V_28 ;
}
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ ) {
int V_29 ;
V_29 = F_16 ( V_20 , V_23 ) ;
if ( V_29 < 0 )
return V_29 ;
V_2 -> V_4 [ V_23 ] = V_29 ;
}
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ ) {
V_22 = F_17 ( & V_18 -> V_14 , V_2 -> V_4 [ V_23 ] ,
L_4 ) ;
if ( V_22 )
return V_22 ;
if ( V_23 < V_5 )
V_22 = F_18 ( V_2 -> V_4 [ V_23 ] ,
F_2 ( V_2 -> V_4 [ V_23 ] ) ) ;
else
V_22 = F_19 ( V_2 -> V_4 [ V_23 ] ) ;
if ( V_22 )
return V_22 ;
}
F_20 ( & V_2 -> V_10 ) ;
F_21 ( & V_30 , 30 , & V_18 -> V_14 ) ;
F_22 ( & V_30 , V_31 ) ;
F_23 ( & V_30 , V_2 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 == 2 )
V_30 . V_32 |= V_33 ;
else if ( V_3 == 4 )
V_30 . V_32 |= V_34 ;
else if ( V_3 == 5 )
V_30 . V_32 |= V_35 ;
else if ( V_3 == 7 )
V_30 . V_32 |= V_36 ;
V_2 -> V_9 = V_30 ;
F_24 ( & V_18 -> V_14 , V_2 ) ;
V_22 = F_25 ( & V_30 ) ;
if ( V_22 ) {
F_12 ( & V_18 -> V_14 , L_5 ) ;
goto V_37;
}
F_26 ( & V_18 -> V_14 , L_6 ) ;
return 0 ;
V_37:
F_27 ( & V_2 -> V_10 ) ;
return V_22 ;
}
static int F_28 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_29 ( & V_18 -> V_14 ) ;
F_30 ( & V_18 -> V_14 ,
L_7 ) ;
F_31 ( & V_2 -> V_9 ) ;
F_27 ( & V_2 -> V_10 ) ;
return 0 ;
}
static void F_32 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_29 ( & V_18 -> V_14 ) ;
F_6 ( V_2 -> V_4 [ V_11 ] , 0 ) ;
}
