int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_2 -> V_5 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_3 ( V_2 -> V_6 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_7 , L_1 ) ;
goto V_8;
}
return 0 ;
V_8:
F_5 ( V_2 -> V_4 , V_2 -> V_5 ) ;
return V_3 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_6 ) ;
F_5 ( V_2 -> V_4 , V_2 -> V_5 ) ;
}
static int F_8 ( struct V_9 * V_10 )
{
const struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
int V_3 ;
int V_15 ;
V_2 = F_9 ( & V_10 -> V_7 , sizeof( struct V_1 ) , V_16 ) ;
if ( ! V_2 )
return - V_17 ;
V_12 = F_10 ( & V_10 -> V_7 ) ;
V_14 = F_11 ( V_10 -> V_7 . V_18 ) ;
V_2 -> V_6 = F_12 ( & V_10 -> V_7 , L_2 ) ;
if ( F_13 ( V_2 -> V_6 ) ) {
if ( F_14 ( V_2 -> V_6 ) != - V_19 )
F_4 ( & V_10 -> V_7 , L_3 ) ;
return F_14 ( V_2 -> V_6 ) ;
}
V_2 -> V_4 = V_12 -> V_4 ;
V_2 -> V_5 = F_15 ( & V_10 -> V_7 ,
V_2 -> V_4 ,
sizeof( struct V_20 ) ,
V_16 ) ;
if ( ! V_2 -> V_5 )
return - V_17 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_4 ; V_15 ++ )
V_2 -> V_5 [ V_15 ] . V_21 = V_12 -> V_5 [ V_15 ] . V_22 ;
V_3 = F_16 ( & V_10 -> V_7 , V_2 -> V_4 , V_2 -> V_5 ) ;
if ( V_3 ) {
F_4 ( & V_10 -> V_7 , L_4 ) ;
return V_3 ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_4 ; V_15 ++ ) {
if ( V_12 -> V_5 [ V_15 ] . V_23 )
F_17 ( V_2 -> V_5 [ V_15 ] . V_24 ,
V_12 -> V_5 [ V_15 ] . V_25 ,
V_12 -> V_5 [ V_15 ] . V_23 ) ;
if ( V_12 -> V_5 [ V_15 ] . V_26 )
F_18 ( V_2 -> V_5 [ V_15 ] . V_24 ,
V_12 -> V_5 [ V_15 ] . V_26 ) ;
}
F_19 ( V_14 , V_2 , V_12 -> V_27 ) ;
return 0 ;
}
static int F_20 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = F_11 ( V_10 -> V_7 . V_18 ) ;
F_19 ( V_14 , NULL , false ) ;
return 0 ;
}
