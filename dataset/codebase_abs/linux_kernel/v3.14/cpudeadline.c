static inline int F_1 ( int V_1 )
{
return ( V_1 - 1 ) >> 1 ;
}
static inline int F_2 ( int V_1 )
{
return ( V_1 << 1 ) + 1 ;
}
static inline int F_3 ( int V_1 )
{
return ( V_1 << 1 ) + 2 ;
}
static inline int F_4 ( T_1 V_2 , T_1 V_3 )
{
return ( V_4 ) ( V_2 - V_3 ) < 0 ;
}
static void F_5 ( struct V_5 * V_6 , int V_2 , int V_3 )
{
int V_7 = V_6 -> V_8 [ V_2 ] . V_9 , V_10 = V_6 -> V_8 [ V_3 ] . V_9 ;
F_6 ( V_6 -> V_8 [ V_2 ] , V_6 -> V_8 [ V_3 ] ) ;
F_6 ( V_6 -> V_11 [ V_7 ] , V_6 -> V_11 [ V_10 ] ) ;
}
static void F_7 ( struct V_5 * V_6 , int V_12 )
{
int V_13 , V_14 , V_15 ;
while( 1 ) {
V_13 = F_2 ( V_12 ) ;
V_14 = F_3 ( V_12 ) ;
V_15 = V_12 ;
if ( ( V_13 < V_6 -> V_16 ) && F_4 ( V_6 -> V_8 [ V_12 ] . V_17 ,
V_6 -> V_8 [ V_13 ] . V_17 ) )
V_15 = V_13 ;
if ( ( V_14 < V_6 -> V_16 ) && F_4 ( V_6 -> V_8 [ V_15 ] . V_17 ,
V_6 -> V_8 [ V_14 ] . V_17 ) )
V_15 = V_14 ;
if ( V_15 == V_12 )
break;
F_5 ( V_6 , V_15 , V_12 ) ;
V_12 = V_15 ;
}
}
static void F_8 ( struct V_5 * V_6 , int V_12 , T_1 V_18 )
{
F_9 ( V_12 == V_19 || ! F_10 ( V_12 ) ) ;
if ( F_4 ( V_18 , V_6 -> V_8 [ V_12 ] . V_17 ) ) {
V_6 -> V_8 [ V_12 ] . V_17 = V_18 ;
F_7 ( V_6 , V_12 ) ;
} else {
V_6 -> V_8 [ V_12 ] . V_17 = V_18 ;
while ( V_12 > 0 && F_4 ( V_6 -> V_8 [ F_1 ( V_12 ) ] . V_17 ,
V_6 -> V_8 [ V_12 ] . V_17 ) ) {
F_5 ( V_6 , V_12 , F_1 ( V_12 ) ) ;
V_12 = F_1 ( V_12 ) ;
}
}
}
static inline int F_11 ( struct V_5 * V_6 )
{
return V_6 -> V_8 [ 0 ] . V_9 ;
}
int F_12 ( struct V_5 * V_6 , struct V_20 * V_21 ,
struct V_22 * V_23 )
{
int V_24 = - 1 ;
const struct V_25 * V_26 = & V_21 -> V_17 ;
if ( V_23 && F_13 ( V_23 , V_6 -> V_27 ,
& V_21 -> V_28 ) && F_13 ( V_23 ,
V_23 , V_29 ) ) {
V_24 = F_14 ( V_23 ) ;
goto V_30;
} else if ( F_15 ( F_11 ( V_6 ) , & V_21 -> V_28 ) &&
F_4 ( V_26 -> V_31 , V_6 -> V_8 [ 0 ] . V_17 ) ) {
V_24 = F_11 ( V_6 ) ;
if ( V_23 )
F_16 ( V_24 , V_23 ) ;
}
V_30:
F_9 ( V_24 != - 1 && ! F_10 ( V_24 ) ) ;
return V_24 ;
}
void F_17 ( struct V_5 * V_6 , int V_9 , T_1 V_17 , int V_32 )
{
int V_33 , V_34 ;
unsigned long V_35 ;
F_9 ( ! F_10 ( V_9 ) ) ;
F_18 ( & V_6 -> V_36 , V_35 ) ;
V_33 = V_6 -> V_11 [ V_9 ] ;
if ( ! V_32 ) {
if ( V_33 == V_19 ) {
goto V_30;
}
V_34 = V_6 -> V_8 [ V_6 -> V_16 - 1 ] . V_9 ;
V_6 -> V_8 [ V_33 ] . V_17 = V_6 -> V_8 [ V_6 -> V_16 - 1 ] . V_17 ;
V_6 -> V_8 [ V_33 ] . V_9 = V_34 ;
V_6 -> V_16 -- ;
V_6 -> V_11 [ V_34 ] = V_33 ;
V_6 -> V_11 [ V_9 ] = V_19 ;
while ( V_33 > 0 && F_4 (
V_6 -> V_8 [ F_1 ( V_33 ) ] . V_17 ,
V_6 -> V_8 [ V_33 ] . V_17 ) ) {
F_5 ( V_6 , V_33 , F_1 ( V_33 ) ) ;
V_33 = F_1 ( V_33 ) ;
}
F_16 ( V_9 , V_6 -> V_27 ) ;
F_7 ( V_6 , V_33 ) ;
goto V_30;
}
if ( V_33 == V_19 ) {
V_6 -> V_16 ++ ;
V_6 -> V_8 [ V_6 -> V_16 - 1 ] . V_17 = 0 ;
V_6 -> V_8 [ V_6 -> V_16 - 1 ] . V_9 = V_9 ;
V_6 -> V_11 [ V_9 ] = V_6 -> V_16 - 1 ;
F_8 ( V_6 , V_6 -> V_16 - 1 , V_17 ) ;
F_19 ( V_9 , V_6 -> V_27 ) ;
} else {
F_8 ( V_6 , V_33 , V_17 ) ;
}
V_30:
F_20 ( & V_6 -> V_36 , V_35 ) ;
}
int F_21 ( struct V_5 * V_6 )
{
int V_1 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_22 ( & V_6 -> V_36 ) ;
V_6 -> V_16 = 0 ;
for ( V_1 = 0 ; V_1 < V_37 ; V_1 ++ )
V_6 -> V_11 [ V_1 ] = V_19 ;
if ( ! F_23 ( & V_6 -> V_27 , V_38 ) )
return - V_39 ;
F_24 ( V_6 -> V_27 ) ;
return 0 ;
}
void F_25 ( struct V_5 * V_6 )
{
}
