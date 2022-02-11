static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_2 ( & V_5 -> V_6 -> V_7 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_4 ( & V_5 -> V_6 -> V_7 ) ;
return 0 ;
}
static T_1 F_5 ( int V_8 , struct V_1 * V_9 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
F_6 ( & V_5 -> V_10 ) ;
if ( ! F_7 ( V_11 , & V_5 -> V_12 ) )
F_8 ( V_8 ) ;
F_9 ( & V_5 -> V_10 ) ;
return V_13 ;
}
static int F_10 ( struct V_1 * V_9 , T_2 V_14 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
unsigned long V_12 ;
F_11 ( & V_5 -> V_10 , V_12 ) ;
if ( V_14 ) {
if ( F_12 ( V_11 , & V_5 -> V_12 ) )
F_13 ( V_9 -> V_8 ) ;
} else {
if ( ! F_7 ( V_11 , & V_5 -> V_12 ) )
F_8 ( V_9 -> V_8 ) ;
}
F_14 ( & V_5 -> V_10 , V_12 ) ;
return 0 ;
}
static int F_15 ( struct V_15 * V_6 )
{
struct V_1 * V_16 = F_16 ( & V_6 -> V_7 ) ;
struct V_4 * V_5 ;
struct V_17 * V_18 ;
int V_19 = - V_20 ;
int V_21 ;
if ( V_6 -> V_7 . V_22 ) {
V_16 = F_17 ( & V_6 -> V_7 , sizeof( * V_16 ) ,
V_23 ) ;
if ( ! V_16 ) {
F_18 ( & V_6 -> V_7 , L_1 ) ;
return - V_24 ;
}
V_16 -> V_25 = V_6 -> V_7 . V_22 -> V_25 ;
V_16 -> V_26 = L_2 ;
}
if ( ! V_16 || ! V_16 -> V_25 || ! V_16 -> V_26 ) {
F_18 ( & V_6 -> V_7 , L_3 ) ;
return V_19 ;
}
if ( V_16 -> V_27 || V_16 -> V_28 ||
V_16 -> V_29 & V_30 ) {
F_18 ( & V_6 -> V_7 , L_4 ) ;
return V_19 ;
}
V_5 = F_17 ( & V_6 -> V_7 , sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 ) {
F_18 ( & V_6 -> V_7 , L_1 ) ;
return - V_24 ;
}
V_5 -> V_16 = V_16 ;
F_19 ( & V_5 -> V_10 ) ;
V_5 -> V_12 = 0 ;
V_5 -> V_6 = V_6 ;
if ( ! V_16 -> V_8 ) {
V_19 = F_20 ( V_6 , 0 ) ;
V_16 -> V_8 = V_19 ;
if ( V_19 == - V_31 && V_6 -> V_7 . V_22 )
V_16 -> V_8 = V_32 ;
else if ( V_19 < 0 ) {
F_18 ( & V_6 -> V_7 , L_5 ) ;
return V_19 ;
}
}
V_18 = & V_16 -> V_33 [ 0 ] ;
for ( V_21 = 0 ; V_21 < V_6 -> V_34 ; ++ V_21 ) {
struct V_35 * V_36 = & V_6 -> V_35 [ V_21 ] ;
if ( V_36 -> V_12 != V_37 )
continue;
if ( V_18 >= & V_16 -> V_33 [ V_38 ] ) {
F_21 ( & V_6 -> V_7 , L_6
F_22 ( V_38 )
L_7 ) ;
break;
}
V_18 -> V_39 = V_40 ;
V_18 -> V_41 = V_36 -> V_42 ;
V_18 -> V_43 = F_23 ( V_36 ) ;
V_18 -> V_25 = V_36 -> V_25 ;
++ V_18 ;
}
while ( V_18 < & V_16 -> V_33 [ V_38 ] ) {
V_18 -> V_43 = 0 ;
++ V_18 ;
}
V_16 -> V_27 = F_5 ;
V_16 -> V_28 = F_10 ;
V_16 -> V_44 = F_1 ;
V_16 -> V_45 = F_3 ;
V_16 -> V_5 = V_5 ;
F_24 ( & V_6 -> V_7 ) ;
V_19 = F_25 ( & V_6 -> V_7 , V_5 -> V_16 ) ;
if ( V_19 ) {
F_18 ( & V_6 -> V_7 , L_8 ) ;
F_26 ( & V_6 -> V_7 ) ;
return V_19 ;
}
F_27 ( V_6 , V_5 ) ;
return 0 ;
}
static int F_28 ( struct V_15 * V_6 )
{
struct V_4 * V_5 = F_29 ( V_6 ) ;
F_30 ( V_5 -> V_16 ) ;
F_26 ( & V_6 -> V_7 ) ;
V_5 -> V_16 -> V_27 = NULL ;
V_5 -> V_16 -> V_28 = NULL ;
return 0 ;
}
static int F_31 ( struct V_46 * V_7 )
{
return 0 ;
}
