int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
unsigned int V_7 ;
int V_8 , V_9 = 0 ;
V_4 =
F_2 ( & V_2 -> V_10 , sizeof( struct V_3 ) , V_11 ) ;
if ( ! V_4 )
return - V_12 ;
V_6 = F_3 ( V_2 , & V_13 ) ;
if ( F_4 ( V_6 ) ) {
V_9 = F_5 ( V_6 ) ;
F_6 ( & V_2 -> V_10 , L_1 ,
V_9 ) ;
return V_9 ;
}
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_6 ;
V_4 -> V_14 = V_2 -> V_14 ;
V_4 -> V_10 = & V_2 -> V_10 ;
F_7 ( V_4 -> V_10 , V_4 ) ;
F_8 ( V_4 -> V_2 , V_4 ) ;
V_9 = F_9 ( V_4 -> V_5 , V_15 , & V_7 ) ;
if ( V_9 < 0 ) {
F_6 ( V_4 -> V_10 , L_2 , V_9 ) ;
return V_9 ;
}
for ( V_8 = 0 ; V_8 < F_10 ( V_16 ) ; V_8 ++ ) {
if ( V_16 [ V_8 ] . V_17 == F_11 ( V_7 ) ) {
V_4 -> type = V_16 [ V_8 ] . type ;
break;
}
}
if ( V_8 == F_10 ( V_16 ) ) {
F_6 ( V_4 -> V_10 ,
L_3 , V_7 ) ;
return - V_18 ;
}
F_12 ( & V_2 -> V_10 , 1 ) ;
if ( ! V_19 )
V_19 = V_4 ;
else {
V_4 -> V_20 = V_19 -> V_2 ;
V_19 -> V_20 = V_4 -> V_2 ;
}
return 0 ;
}
int F_13 ( void )
{
if ( V_19 -> V_20 )
V_19 -> V_20 = NULL ;
else
V_19 = NULL ;
return 0 ;
}
static int F_14 ( struct V_21 * V_10 )
{
struct V_1 * V_2 = F_15 ( V_10 , struct V_1 , V_10 ) ;
struct V_3 * V_4 = F_16 ( V_2 ) ;
if ( V_4 && V_4 -> V_22 )
if ( F_17 ( V_4 -> V_10 ) )
F_18 ( V_4 -> V_14 ) ;
return 0 ;
}
static int F_19 ( struct V_21 * V_10 )
{
struct V_1 * V_2 = F_15 ( V_10 , struct V_1 , V_10 ) ;
struct V_3 * V_4 = F_16 ( V_2 ) ;
if ( V_4 && V_4 -> V_22 )
if ( F_17 ( V_4 -> V_10 ) )
F_20 ( V_4 -> V_14 ) ;
return 0 ;
}
