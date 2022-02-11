void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! F_2 ( V_5 , & V_2 -> V_6 ) )
return;
if ( F_2 ( V_7 , & V_2 -> V_6 ) ) {
if ( F_3 ( & V_4 -> V_8 ) )
F_4 ( & V_4 -> V_8 , & V_2 -> V_9 ) ;
} else
F_5 ( V_2 -> V_10 . V_11 , & V_4 -> V_12 ) ;
}
static void F_6 ( int V_13 , unsigned long * V_14 ,
struct V_3 * V_12 ,
struct V_1 * V_2 )
{
if ( ! F_7 ( V_13 , V_14 ) ) {
unsigned long V_15 ;
F_8 ( & V_2 -> V_16 , V_15 ) ;
F_1 ( V_2 , V_12 ) ;
F_9 ( & V_2 -> V_16 , V_15 ) ;
}
}
void F_10 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_10 . V_11 -> V_19 ;
struct V_3 * V_4 , * V_20 ;
F_11 ( V_7 , & V_2 -> V_6 ) ;
F_12 ( & V_2 -> V_16 ) ;
F_13 ( & V_2 -> V_16 ) ;
F_14 ( V_18 ) ;
F_12 ( & V_2 -> V_16 ) ;
F_15 ( V_7 , & V_2 -> V_6 ) ;
F_16 (sw, _sw, &ha->defer_q, drain_node) {
F_17 ( & V_4 -> V_8 ) ;
F_1 ( V_2 , V_4 ) ;
}
F_13 ( & V_2 -> V_16 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_21 ;
V_21 = F_19 ( & V_2 -> V_22 ) ;
if ( V_21 )
return V_21 ;
if ( F_2 ( V_5 , & V_2 -> V_6 ) )
F_10 ( V_2 ) ;
F_20 ( & V_2 -> V_22 ) ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_23 ) ;
F_11 ( V_24 , & V_2 -> V_6 ) ;
F_20 ( & V_2 -> V_23 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
int V_25 ;
F_22 ( & V_2 -> V_23 ) ;
F_15 ( V_24 , & V_2 -> V_6 ) ;
for ( V_25 = 0 ; V_25 < V_2 -> V_26 ; V_25 ++ ) {
struct V_27 * V_28 = V_2 -> V_29 [ V_25 ] ;
const int V_30 = V_31 ;
struct V_32 * V_33 = & V_28 -> V_34 ;
if ( ! F_24 ( V_30 , & V_33 -> V_14 ) )
continue;
F_6 ( V_30 , & V_33 -> V_14 , & V_33 -> V_35 [ V_30 ] . V_12 , V_2 ) ;
}
F_20 ( & V_2 -> V_23 ) ;
}
static void F_25 ( struct V_1 * V_36 , enum V_37 V_13 )
{
F_26 ( V_13 >= V_38 ) ;
F_6 ( V_13 , & V_36 -> V_14 ,
& V_36 -> V_39 [ V_13 ] . V_12 , V_36 ) ;
}
static void F_27 ( struct V_40 * V_41 , enum V_42 V_13 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
F_26 ( V_13 >= V_43 ) ;
F_6 ( V_13 , & V_41 -> V_44 ,
& V_41 -> V_45 [ V_13 ] . V_12 , V_2 ) ;
}
static void F_28 ( struct V_40 * V_41 , enum V_46 V_13 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
F_26 ( V_13 >= V_47 ) ;
F_6 ( V_13 , & V_41 -> V_48 ,
& V_41 -> V_49 [ V_13 ] . V_12 , V_2 ) ;
}
int F_29 ( struct V_1 * V_36 )
{
static const T_1 V_50 [ V_38 ] = {
[ V_51 ] = V_52 ,
} ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_38 ; V_25 ++ ) {
F_30 ( & V_36 -> V_39 [ V_25 ] . V_12 , V_50 [ V_25 ] ) ;
V_36 -> V_39 [ V_25 ] . V_2 = V_36 ;
}
V_36 -> F_25 = F_25 ;
V_36 -> F_27 = F_27 ;
V_36 -> F_28 = F_28 ;
return 0 ;
}
