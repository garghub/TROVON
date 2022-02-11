int F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 ;
struct V_2 * V_7 ;
int V_8 = 0 ;
V_6 = F_2 ( V_1 -> V_9 , & V_1 -> V_10 ,
F_3 ( & V_1 -> V_11 ) ) ;
if ( V_4 < V_6 -> V_12 ) {
F_4 (e, &irq_rt->map[gsi], link) {
V_3 [ V_8 ] = * V_7 ;
++ V_8 ;
}
}
return V_8 ;
}
int F_5 ( struct V_1 * V_1 , unsigned V_13 , unsigned V_14 )
{
struct V_5 * V_6 ;
V_6 = F_6 ( V_1 -> V_9 , & V_1 -> V_10 ) ;
return V_6 -> V_15 [ V_13 ] [ V_14 ] ;
}
int F_7 ( struct V_1 * V_1 , struct V_16 * V_17 )
{
struct V_2 V_18 ;
if ( ! F_8 ( V_1 ) || V_17 -> V_19 != 0 )
return - V_20 ;
V_18 . V_17 . V_21 = V_17 -> V_21 ;
V_18 . V_17 . V_22 = V_17 -> V_22 ;
V_18 . V_17 . V_23 = V_17 -> V_23 ;
return F_9 ( & V_18 , V_1 , V_24 , 1 , false ) ;
}
int F_10 ( struct V_1 * V_1 , int V_25 , T_1 V_26 , int V_27 ,
bool V_28 )
{
struct V_2 V_29 [ V_30 ] ;
int V_31 = - 1 , V_32 , V_33 ;
F_11 ( V_26 , V_27 , V_25 ) ;
V_33 = F_12 ( & V_1 -> V_10 ) ;
V_32 = F_1 ( V_1 , V_29 , V_26 ) ;
F_13 ( & V_1 -> V_10 , V_33 ) ;
while ( V_32 -- ) {
int V_34 ;
V_34 = V_29 [ V_32 ] . F_14 ( & V_29 [ V_32 ] , V_1 , V_25 , V_27 ,
V_28 ) ;
if ( V_34 < 0 )
continue;
V_31 = V_34 + ( ( V_31 < 0 ) ? 0 : V_31 ) ;
}
return V_31 ;
}
static void F_15 ( struct V_5 * V_35 )
{
int V_32 ;
if ( ! V_35 )
return;
for ( V_32 = 0 ; V_32 < V_35 -> V_12 ; ++ V_32 ) {
struct V_2 * V_7 ;
struct V_36 * V_8 ;
F_16 (e, n, &rt->map[i], link) {
F_17 ( & V_7 -> V_37 ) ;
F_18 ( V_7 ) ;
}
}
F_18 ( V_35 ) ;
}
void F_19 ( struct V_1 * V_1 )
{
struct V_5 * V_35 = F_20 ( V_1 -> V_9 ) ;
F_15 ( V_35 ) ;
}
static int F_21 ( struct V_5 * V_35 ,
struct V_2 * V_7 ,
const struct V_38 * V_39 )
{
int V_34 = - V_20 ;
struct V_2 * V_40 ;
F_4 (ei, &rt->map[ue->gsi], link)
if ( V_40 -> type != V_41 ||
V_39 -> type != V_41 ||
V_39 -> V_42 . V_13 . V_13 == V_40 -> V_13 . V_13 )
return V_34 ;
V_7 -> V_4 = V_39 -> V_4 ;
V_7 -> type = V_39 -> type ;
V_34 = F_22 ( V_7 , V_39 ) ;
if ( V_34 )
goto V_43;
if ( V_7 -> type == V_41 )
V_35 -> V_15 [ V_7 -> V_13 . V_13 ] [ V_7 -> V_13 . V_14 ] = V_7 -> V_4 ;
F_23 ( & V_7 -> V_37 , & V_35 -> V_44 [ V_7 -> V_4 ] ) ;
V_34 = 0 ;
V_43:
return V_34 ;
}
int F_24 ( struct V_1 * V_1 ,
const struct V_38 * V_39 ,
unsigned V_45 ,
unsigned V_19 )
{
struct V_5 * V_46 , * V_47 ;
T_1 V_32 , V_48 , V_12 = 0 ;
int V_34 ;
for ( V_32 = 0 ; V_32 < V_45 ; ++ V_32 ) {
if ( V_39 [ V_32 ] . V_4 >= V_49 )
return - V_20 ;
V_12 = F_25 ( V_12 , V_39 [ V_32 ] . V_4 ) ;
}
V_12 += 1 ;
V_46 = F_26 ( sizeof( * V_46 ) + ( V_12 * sizeof( struct V_50 ) ) ,
V_51 ) ;
if ( ! V_46 )
return - V_52 ;
V_46 -> V_12 = V_12 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 ++ )
for ( V_48 = 0 ; V_48 < V_53 ; V_48 ++ )
V_46 -> V_15 [ V_32 ] [ V_48 ] = - 1 ;
for ( V_32 = 0 ; V_32 < V_45 ; ++ V_32 ) {
struct V_2 * V_7 ;
V_34 = - V_52 ;
V_7 = F_26 ( sizeof( * V_7 ) , V_51 ) ;
if ( ! V_7 )
goto V_43;
V_34 = - V_20 ;
if ( V_39 -> V_19 ) {
F_18 ( V_7 ) ;
goto V_43;
}
V_34 = F_21 ( V_46 , V_7 , V_39 ) ;
if ( V_34 ) {
F_18 ( V_7 ) ;
goto V_43;
}
++ V_39 ;
}
F_27 ( & V_1 -> V_11 ) ;
V_47 = V_1 -> V_9 ;
F_28 ( V_1 -> V_9 , V_46 ) ;
F_29 ( V_1 ) ;
F_30 ( V_1 ) ;
F_31 ( & V_1 -> V_11 ) ;
F_32 ( V_1 ) ;
F_33 ( & V_1 -> V_10 ) ;
V_46 = V_47 ;
V_34 = 0 ;
V_43:
F_15 ( V_46 ) ;
return V_34 ;
}
