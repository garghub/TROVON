int F_1 ( struct V_1 * V_2 ,
const unsigned long * V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 ;
unsigned int V_7 ;
unsigned int V_8 , V_9 ;
T_1 * V_10 , * V_11 ;
F_3 ( V_4 -> V_12 ) ;
F_3 ( V_4 -> V_13 ) ;
V_7 = V_2 -> V_14 / 2 ;
V_4 -> V_12 = F_4 ( V_7 + 1 , sizeof( * V_4 -> V_12 ) , V_15 ) ;
if ( ! V_4 -> V_12 )
return - V_16 ;
V_4 -> V_13 = F_5 ( V_2 -> V_14 * 2 , V_15 ) ;
if ( ! V_4 -> V_13 )
return - V_16 ;
V_11 = V_4 -> V_13 ;
V_10 = V_11 + V_2 -> V_14 ;
F_6 ( & V_4 -> V_17 ) ;
for ( V_9 = 0 ; V_9 <= V_7 ; V_9 ++ ) {
V_4 -> V_12 [ V_9 ] . V_18 = 8 ;
if ( V_9 != V_7 )
V_4 -> V_12 [ V_9 ] . V_19 = 1 ;
V_4 -> V_12 [ V_9 ] . V_20 = 2 ;
V_4 -> V_12 [ V_9 ] . V_21 = V_4 -> V_22 -> V_23 ;
if ( V_9 < V_7 )
V_4 -> V_12 [ V_9 ] . V_24 = & V_10 [ V_9 ] ;
if ( V_9 >= 1 )
V_4 -> V_12 [ V_9 ] . V_25 = & V_11 [ V_9 - 1 ] ;
F_7 ( & V_4 -> V_12 [ V_9 ] , & V_4 -> V_17 ) ;
}
V_6 = V_2 -> V_26 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_27 ; V_8 ++ , V_6 ++ ) {
if ( ! F_8 ( V_6 -> V_28 , V_3 ) )
continue;
if ( V_6 -> V_29 . V_30 == 32 )
* V_10 ++ = F_9 ( ( V_6 -> V_31 + 2 ) << 8 ) ;
* V_10 ++ = F_9 ( V_6 -> V_31 << 8 ) ;
}
return 0 ;
}
static T_2 F_10 ( int V_32 , void * V_33 )
{
struct V_34 * V_35 = V_33 ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_36 ;
if ( ! V_4 -> V_13 )
return - V_16 ;
if ( V_4 -> V_22 -> V_37 ) {
F_11 ( & V_4 -> V_38 ) ;
if ( V_4 -> V_39 != 0 ) {
V_4 -> V_10 [ 0 ] = F_12 ( V_40 ) ;
V_4 -> V_10 [ 1 ] = 0 ;
F_13 ( V_4 -> V_41 , V_4 -> V_10 , 2 ) ;
}
}
V_36 = F_14 ( V_4 -> V_41 , & V_4 -> V_17 ) ;
if ( V_36 )
F_15 ( & V_4 -> V_41 -> V_42 , L_1 , V_36 ) ;
if ( V_4 -> V_22 -> V_37 ) {
V_4 -> V_39 = 0 ;
F_16 ( & V_4 -> V_38 ) ;
}
if ( V_2 -> V_43 ) {
void * V_44 = V_4 -> V_13 + V_2 -> V_14 - sizeof( V_45 ) ;
* ( V_45 * ) V_44 = V_35 -> V_46 ;
}
F_17 ( V_2 , V_4 -> V_13 ) ;
F_18 ( V_2 -> V_47 ) ;
return V_48 ;
}
int F_19 ( struct V_4 * V_4 , struct V_1 * V_2 ,
T_2 (* F_20)( int , void * ) )
{
int V_36 ;
if ( ! F_20 )
F_20 = F_10 ;
V_36 = F_21 ( V_2 , & V_49 ,
F_20 , NULL ) ;
if ( V_36 )
return V_36 ;
if ( V_4 -> V_41 -> V_32 ) {
V_36 = F_22 ( V_4 , V_2 ) ;
if ( V_36 )
goto V_50;
}
return 0 ;
V_50:
F_23 ( V_2 ) ;
return V_36 ;
}
void F_24 ( struct V_4 * V_4 ,
struct V_1 * V_2 )
{
if ( V_4 -> V_41 -> V_32 )
F_25 ( V_4 ) ;
F_3 ( V_4 -> V_13 ) ;
F_3 ( V_4 -> V_12 ) ;
F_23 ( V_2 ) ;
}
