int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = 0 ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return 0 ;
if ( F_2 ( V_8 , & V_2 -> V_7 ) ) {
if ( F_3 ( & V_4 -> V_9 ) )
F_4 ( & V_4 -> V_9 , & V_2 -> V_10 ) ;
} else
V_5 = F_5 ( V_2 -> V_11 . V_12 , & V_4 -> V_13 ) ;
return V_5 ;
}
static int F_6 ( int V_14 , unsigned long * V_15 ,
struct V_3 * V_13 ,
struct V_1 * V_2 )
{
int V_5 = 0 ;
if ( ! F_7 ( V_14 , V_15 ) ) {
unsigned long V_16 ;
F_8 ( & V_2 -> V_17 , V_16 ) ;
V_5 = F_1 ( V_2 , V_13 ) ;
F_9 ( & V_2 -> V_17 , V_16 ) ;
}
return V_5 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_11 . V_12 -> V_20 ;
struct V_3 * V_4 , * V_21 ;
F_11 ( V_8 , & V_2 -> V_7 ) ;
F_12 ( & V_2 -> V_17 ) ;
F_13 ( & V_2 -> V_17 ) ;
F_14 ( V_19 ) ;
F_12 ( & V_2 -> V_17 ) ;
F_15 ( V_8 , & V_2 -> V_7 ) ;
F_16 (sw, _sw, &ha->defer_q, drain_node) {
F_17 ( & V_4 -> V_9 ) ;
F_1 ( V_2 , V_4 ) ;
}
F_13 ( & V_2 -> V_17 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_19 ( & V_2 -> V_23 ) ;
if ( V_22 )
return V_22 ;
if ( F_2 ( V_6 , & V_2 -> V_7 ) )
F_10 ( V_2 ) ;
F_20 ( & V_2 -> V_23 ) ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_24 ) ;
F_11 ( V_25 , & V_2 -> V_7 ) ;
F_20 ( & V_2 -> V_24 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
int V_26 ;
F_22 ( & V_2 -> V_24 ) ;
F_15 ( V_25 , & V_2 -> V_7 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_27 ; V_26 ++ ) {
struct V_28 * V_29 = V_2 -> V_30 [ V_26 ] ;
const int V_31 = V_32 ;
struct V_33 * V_34 = & V_29 -> V_35 ;
if ( ! F_24 ( V_31 , & V_34 -> V_15 ) )
continue;
F_6 ( V_31 , & V_34 -> V_15 , & V_34 -> V_36 [ V_31 ] . V_13 , V_2 ) ;
}
F_20 ( & V_2 -> V_24 ) ;
}
static int F_25 ( struct V_1 * V_37 , enum V_38 V_14 )
{
F_26 ( V_14 >= V_39 ) ;
return F_6 ( V_14 , & V_37 -> V_15 ,
& V_37 -> V_40 [ V_14 ] . V_13 , V_37 ) ;
}
static int F_27 ( struct V_41 * V_42 , enum V_43 V_14 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
F_26 ( V_14 >= V_44 ) ;
return F_6 ( V_14 , & V_42 -> V_45 ,
& V_42 -> V_46 [ V_14 ] . V_13 , V_2 ) ;
}
int F_28 ( struct V_41 * V_42 , enum V_47 V_14 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
F_26 ( V_14 >= V_48 ) ;
return F_6 ( V_14 , & V_42 -> V_49 ,
& V_42 -> V_50 [ V_14 ] . V_13 , V_2 ) ;
}
int F_29 ( struct V_1 * V_37 )
{
static const T_1 V_51 [ V_39 ] = {
[ V_52 ] = V_53 ,
} ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_39 ; V_26 ++ ) {
F_30 ( & V_37 -> V_40 [ V_26 ] . V_13 , V_51 [ V_26 ] ) ;
V_37 -> V_40 [ V_26 ] . V_2 = V_37 ;
}
V_37 -> F_25 = F_25 ;
V_37 -> F_27 = F_27 ;
V_37 -> V_54 = F_28 ;
return 0 ;
}
