static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static enum V_3
F_3 ( struct V_1 * V_2 , bool V_4 )
{
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; ++ V_10 ) {
struct V_12 * V_13 = & V_14 [ V_10 ] ;
V_9 = F_5 ( V_7 , & V_13 -> V_9 ) ;
if ( ! V_9 ) {
F_6 ( L_1 ) ;
return 0 ;
}
F_7 ( V_2 , V_9 ) ;
}
return V_10 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
return V_15 ;
}
static void F_9 ( struct V_16 * V_17 )
{
F_10 ( V_17 ) ;
}
static int F_11 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; ++ V_10 ) {
struct V_12 * V_13 = & V_14 [ V_10 ] ;
if ( F_12 ( & V_19 -> V_9 , & V_13 -> V_9 ) )
return 0 ;
}
return - V_22 ;
}
static void F_13 ( struct V_16 * V_17 )
{
struct V_23 * V_23 =
F_14 ( V_17 ) ;
struct V_24 * V_25 = V_23 -> V_25 ;
F_15 ( V_25 -> V_26 , V_27 , 0 ) ;
F_15 ( V_25 -> V_26 , V_28 , 8 ) ;
}
static void F_16 ( struct V_16 * V_17 )
{
struct V_23 * V_23 =
F_14 ( V_17 ) ;
struct V_24 * V_25 = V_23 -> V_25 ;
F_17 ( F_18 ( 5 ) , 0 , V_25 -> V_29 + F_19 ( V_30 ) ) ;
if ( F_20 ( V_25 , L_2 ) )
F_15 ( V_25 -> V_26 , V_27 , 1 ) ;
else if ( F_20 ( V_25 , L_3 ) ||
F_20 ( V_25 , L_4 ) )
F_15 ( V_25 -> V_26 , V_27 , 0xf0001 ) ;
F_15 ( V_25 -> V_26 , V_28 , 0 ) ;
}
static void F_21 ( struct V_16 * V_17 ,
struct V_8 * V_9 ,
struct V_8 * V_31 )
{
struct V_23 * V_23 =
F_14 ( V_17 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; ++ V_10 ) {
struct V_12 * V_13 = & V_14 [ V_10 ] ;
if ( F_12 ( V_9 , & V_13 -> V_9 ) ) {
F_22 ( V_23 -> V_25 ,
V_13 -> V_32 ) ;
break;
}
}
}
static bool F_23 ( struct V_24 * V_25 )
{
struct V_33 * V_34 , * V_35 ;
V_34 = F_24 ( V_25 -> V_7 -> V_36 , 0 , 0 ) ;
if ( ! V_34 )
return false ;
V_35 = F_25 ( V_34 ) ;
if ( V_35 ) {
F_26 ( V_34 ) ;
return true ;
}
F_26 ( V_34 ) ;
F_26 ( V_35 ) ;
return false ;
}
int F_27 ( struct V_24 * V_25 )
{
struct V_6 * V_37 = V_25 -> V_37 ;
struct V_23 * V_23 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_38 ;
if ( ! F_23 ( V_25 ) ) {
F_28 ( V_37 -> V_7 , L_5 ) ;
return - V_39 ;
}
V_23 = F_29 ( V_25 -> V_7 , sizeof( * V_23 ) ,
V_40 ) ;
if ( ! V_23 )
return - V_41 ;
V_23 -> V_25 = V_25 ;
V_17 = & V_23 -> V_17 ;
V_2 = & V_23 -> V_2 ;
F_30 ( V_2 ,
& V_42 ) ;
V_38 = F_31 ( V_37 , V_2 , & V_43 ,
V_44 ) ;
if ( V_38 ) {
F_32 ( V_25 -> V_7 , L_6 ) ;
return V_38 ;
}
V_2 -> V_45 = 1 ;
F_33 ( V_17 , & V_46 ) ;
V_38 = F_34 ( V_37 , V_17 , & V_47 ,
V_48 , L_7 ) ;
if ( V_38 ) {
F_32 ( V_25 -> V_7 , L_8 ) ;
return V_38 ;
}
V_17 -> V_49 = F_18 ( 0 ) ;
F_35 ( V_2 , V_17 ) ;
return 0 ;
}
