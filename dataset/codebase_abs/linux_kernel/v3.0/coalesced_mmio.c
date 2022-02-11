static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_3 ,
T_1 V_4 , int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned V_10 ;
int V_11 ;
V_9 = V_3 -> V_12 -> V_13 ;
V_10 = ( V_9 -> V_14 - V_9 -> V_15 - 1 ) % V_16 ;
if ( V_10 < V_17 ) {
return 0 ;
}
for ( V_11 = 0 ; V_11 < V_3 -> V_18 ; V_11 ++ ) {
V_7 = & V_3 -> V_7 [ V_11 ] ;
if ( V_7 -> V_4 <= V_4 &&
V_4 + V_5 <= V_7 -> V_4 + V_7 -> V_19 )
return 1 ;
}
return 0 ;
}
static int F_4 ( struct V_2 * V_20 ,
T_1 V_4 , int V_5 , const void * V_21 )
{
struct V_1 * V_3 = F_1 ( V_20 ) ;
struct V_8 * V_9 = V_3 -> V_12 -> V_13 ;
if ( ! F_3 ( V_3 , V_4 , V_5 ) )
return - V_22 ;
F_5 ( & V_3 -> V_23 ) ;
V_9 -> V_24 [ V_9 -> V_15 ] . V_25 = V_4 ;
V_9 -> V_24 [ V_9 -> V_15 ] . V_5 = V_5 ;
memcpy ( V_9 -> V_24 [ V_9 -> V_15 ] . V_26 , V_21 , V_5 ) ;
F_6 () ;
V_9 -> V_15 = ( V_9 -> V_15 + 1 ) % V_16 ;
F_7 ( & V_3 -> V_23 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_20 )
{
struct V_1 * V_3 = F_1 ( V_20 ) ;
F_9 ( V_3 ) ;
}
int F_10 ( struct V_12 * V_12 )
{
struct V_1 * V_3 ;
struct V_27 * V_27 ;
int V_28 ;
V_28 = - V_29 ;
V_27 = F_11 ( V_30 | V_31 ) ;
if ( ! V_27 )
goto V_32;
V_12 -> V_13 = F_12 ( V_27 ) ;
V_28 = - V_29 ;
V_3 = F_13 ( sizeof( struct V_1 ) , V_30 ) ;
if ( ! V_3 )
goto V_33;
F_14 ( & V_3 -> V_23 ) ;
F_15 ( & V_3 -> V_3 , & V_34 ) ;
V_3 -> V_12 = V_12 ;
V_12 -> V_35 = V_3 ;
F_16 ( & V_12 -> V_36 ) ;
V_28 = F_17 ( V_12 , V_37 , & V_3 -> V_3 ) ;
F_18 ( & V_12 -> V_36 ) ;
if ( V_28 < 0 )
goto V_38;
return V_28 ;
V_38:
V_12 -> V_35 = NULL ;
F_9 ( V_3 ) ;
V_33:
V_12 -> V_13 = NULL ;
F_19 ( V_27 ) ;
V_32:
return V_28 ;
}
void F_20 ( struct V_12 * V_12 )
{
if ( V_12 -> V_13 )
F_21 ( ( unsigned long ) V_12 -> V_13 ) ;
}
int F_22 ( struct V_12 * V_12 ,
struct V_6 * V_7 )
{
struct V_1 * V_3 = V_12 -> V_35 ;
if ( V_3 == NULL )
return - V_39 ;
F_16 ( & V_12 -> V_36 ) ;
if ( V_3 -> V_18 >= V_40 ) {
F_18 ( & V_12 -> V_36 ) ;
return - V_41 ;
}
V_3 -> V_7 [ V_3 -> V_18 ] = * V_7 ;
V_3 -> V_18 ++ ;
F_18 ( & V_12 -> V_36 ) ;
return 0 ;
}
int F_23 ( struct V_12 * V_12 ,
struct V_6 * V_7 )
{
int V_11 ;
struct V_1 * V_3 = V_12 -> V_35 ;
struct V_6 * V_42 ;
if ( V_3 == NULL )
return - V_39 ;
F_16 ( & V_12 -> V_36 ) ;
V_11 = V_3 -> V_18 ;
while ( V_11 ) {
V_42 = & V_3 -> V_7 [ V_11 - 1 ] ;
if ( V_7 -> V_4 <= V_42 -> V_4 &&
V_42 -> V_4 + V_42 -> V_19 <= V_7 -> V_4 + V_7 -> V_19 ) {
V_3 -> V_18 -- ;
* V_42 = V_3 -> V_7 [ V_3 -> V_18 ] ;
}
V_11 -- ;
}
F_18 ( & V_12 -> V_36 ) ;
return 0 ;
}
