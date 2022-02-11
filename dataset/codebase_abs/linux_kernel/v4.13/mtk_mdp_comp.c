int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 V_6 )
{
int V_7 = F_2 ( V_4 , V_8 [ V_6 ] ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_10 ) ; V_9 ++ ) {
if ( V_6 == V_10 [ V_9 ] . type &&
V_7 == V_10 [ V_9 ] . V_11 )
return V_9 ;
}
F_4 ( V_2 , L_1 , V_6 , V_7 ) ;
return - V_12 ;
}
void F_5 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
int V_9 , V_15 ;
if ( V_14 -> V_16 ) {
V_15 = F_6 ( V_14 -> V_16 ) ;
if ( V_15 )
F_4 ( V_2 ,
L_2 ,
V_15 , V_14 -> type , V_14 -> V_7 ) ;
}
for ( V_9 = 0 ; V_9 < F_3 ( V_14 -> V_17 ) ; V_9 ++ ) {
if ( ! V_14 -> V_17 [ V_9 ] )
continue;
V_15 = F_7 ( V_14 -> V_17 [ V_9 ] ) ;
if ( V_15 )
F_4 ( V_2 ,
L_3 ,
V_15 , V_14 -> type , V_14 -> V_7 , V_9 ) ;
}
}
void F_8 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_14 -> V_17 ) ; V_9 ++ ) {
if ( ! V_14 -> V_17 [ V_9 ] )
continue;
F_9 ( V_14 -> V_17 [ V_9 ] ) ;
}
if ( V_14 -> V_16 )
F_10 ( V_14 -> V_16 ) ;
}
int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_13 * V_14 , enum V_18 V_19 )
{
struct V_3 * V_20 ;
struct V_21 * V_22 ;
int V_9 ;
if ( V_19 < 0 || V_19 >= V_23 ) {
F_4 ( V_2 , L_4 , V_19 ) ;
return - V_12 ;
}
V_14 -> V_24 = F_12 ( V_4 ) ;
V_14 -> V_7 = V_19 ;
V_14 -> type = V_10 [ V_19 ] . type ;
V_14 -> V_25 = F_13 ( V_4 , 0 ) ;
for ( V_9 = 0 ; V_9 < F_3 ( V_14 -> V_17 ) ; V_9 ++ ) {
V_14 -> V_17 [ V_9 ] = F_14 ( V_4 , V_9 ) ;
if ( V_14 -> type != V_26 )
break;
}
V_14 -> V_16 = NULL ;
if ( V_14 -> type != V_26 &&
V_14 -> type != V_27 &&
V_14 -> type != V_28 )
return 0 ;
V_20 = F_15 ( V_4 , L_5 , 0 ) ;
if ( ! V_20 ) {
F_4 ( V_2 ,
L_6 ,
V_4 -> V_29 ) ;
return - V_12 ;
}
V_22 = F_16 ( V_20 ) ;
if ( ! V_22 ) {
F_17 ( V_2 , L_7 ,
V_20 -> V_29 ) ;
F_18 ( V_20 ) ;
return - V_30 ;
}
F_18 ( V_20 ) ;
V_14 -> V_16 = & V_22 -> V_2 ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
F_18 ( V_14 -> V_24 ) ;
}
