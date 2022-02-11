static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
int V_10 ;
V_4 = F_2 ( & V_2 -> V_11 , sizeof( struct V_3 ) ,
V_12 ) ;
if ( ! V_4 )
return - V_13 ;
V_6 = & V_4 -> V_6 ;
V_8 = F_3 ( V_2 , V_14 , 0 ) ;
if ( ! V_8 ) {
F_4 ( & V_2 -> V_11 , L_1 ) ;
return - V_15 ;
}
V_6 -> V_16 = F_5 ( & V_2 -> V_11 , V_8 ) ;
if ( F_6 ( V_6 -> V_16 ) ) {
F_4 ( & V_2 -> V_11 , L_2 ) ;
return F_7 ( V_6 -> V_16 ) ;
}
V_6 -> V_17 = F_8 ( V_2 , 0 ) ;
if ( V_6 -> V_17 < 0 ) {
F_4 ( & V_2 -> V_11 , L_3 ) ;
return V_6 -> V_17 ;
}
V_4 -> V_18 = F_9 ( & V_2 -> V_11 , NULL ) ;
if ( F_6 ( V_4 -> V_18 ) )
return F_7 ( V_4 -> V_18 ) ;
V_9 = F_10 ( V_4 -> V_18 ) ;
if ( V_9 )
return V_9 ;
V_6 -> V_19 = V_2 -> V_20 ;
V_6 -> V_21 = F_11 ( V_4 -> V_18 ) ;
F_12 ( & V_2 -> V_11 , L_4 , & V_6 -> V_22 ) ;
V_10 = 4 ;
F_12 ( & V_2 -> V_11 , L_5 , & V_10 ) ;
V_6 -> V_10 = V_10 ;
if ( V_2 -> V_11 . V_23 ) {
int V_24 ;
for ( V_24 = 0 ; V_24 < V_6 -> V_10 ; V_24 ++ ) {
int V_25 = F_13 ( V_2 -> V_11 . V_23 ,
L_6 , V_24 ) ;
if ( V_25 == - V_26 ) {
V_9 = V_25 ;
goto V_27;
}
if ( F_14 ( V_25 ) ) {
V_9 = F_15 ( & V_2 -> V_11 , V_25 ,
F_16 ( & V_2 -> V_11 ) ) ;
if ( V_9 )
goto V_27;
}
}
}
V_9 = F_17 ( & V_2 -> V_11 , V_6 ) ;
if ( V_9 )
goto V_27;
F_18 ( V_2 , V_4 ) ;
return 0 ;
V_27:
F_19 ( V_4 -> V_18 ) ;
return V_9 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_21 ( V_2 ) ;
F_19 ( V_4 -> V_18 ) ;
F_22 ( & V_4 -> V_6 ) ;
return 0 ;
}
