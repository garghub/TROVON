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
V_16 = F_17 ( sizeof( * V_16 ) , V_23 ) ;
if ( ! V_16 ) {
V_19 = - V_24 ;
F_18 ( & V_6 -> V_7 , L_1 ) ;
return V_19 ;
}
V_16 -> V_25 = V_6 -> V_7 . V_22 -> V_25 ;
V_16 -> V_26 = L_2 ;
}
if ( ! V_16 || ! V_16 -> V_25 || ! V_16 -> V_26 ) {
F_18 ( & V_6 -> V_7 , L_3 ) ;
goto V_27;
}
if ( V_16 -> V_28 || V_16 -> V_29 ||
V_16 -> V_30 & V_31 ) {
F_18 ( & V_6 -> V_7 , L_4 ) ;
goto V_27;
}
V_5 = F_17 ( sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 ) {
V_19 = - V_24 ;
F_18 ( & V_6 -> V_7 , L_1 ) ;
goto V_27;
}
V_5 -> V_16 = V_16 ;
F_19 ( & V_5 -> V_10 ) ;
V_5 -> V_12 = 0 ;
V_5 -> V_6 = V_6 ;
if ( ! V_16 -> V_8 ) {
V_19 = F_20 ( V_6 , 0 ) ;
V_16 -> V_8 = V_19 ;
if ( V_19 == - V_32 && V_6 -> V_7 . V_22 )
V_16 -> V_8 = V_33 ;
else if ( V_19 < 0 ) {
F_18 ( & V_6 -> V_7 , L_5 ) ;
goto V_34;
}
}
V_18 = & V_16 -> V_35 [ 0 ] ;
for ( V_21 = 0 ; V_21 < V_6 -> V_36 ; ++ V_21 ) {
struct V_37 * V_38 = & V_6 -> V_37 [ V_21 ] ;
if ( V_38 -> V_12 != V_39 )
continue;
if ( V_18 >= & V_16 -> V_35 [ V_40 ] ) {
F_21 ( & V_6 -> V_7 , L_6
F_22 ( V_40 )
L_7 ) ;
break;
}
V_18 -> V_41 = V_42 ;
V_18 -> V_43 = V_38 -> V_44 ;
V_18 -> V_45 = F_23 ( V_38 ) ;
V_18 -> V_25 = V_38 -> V_25 ;
++ V_18 ;
}
while ( V_18 < & V_16 -> V_35 [ V_40 ] ) {
V_18 -> V_45 = 0 ;
++ V_18 ;
}
V_16 -> V_28 = F_5 ;
V_16 -> V_29 = F_10 ;
V_16 -> V_46 = F_1 ;
V_16 -> V_47 = F_3 ;
V_16 -> V_5 = V_5 ;
F_24 ( & V_6 -> V_7 ) ;
V_19 = F_25 ( & V_6 -> V_7 , V_5 -> V_16 ) ;
if ( V_19 ) {
F_18 ( & V_6 -> V_7 , L_8 ) ;
goto V_48;
}
F_26 ( V_6 , V_5 ) ;
return 0 ;
V_48:
F_27 ( & V_6 -> V_7 ) ;
V_34:
F_28 ( V_5 ) ;
V_27:
if ( V_6 -> V_7 . V_22 )
F_28 ( V_16 ) ;
return V_19 ;
}
static int F_29 ( struct V_15 * V_6 )
{
struct V_4 * V_5 = F_30 ( V_6 ) ;
F_31 ( V_5 -> V_16 ) ;
F_27 ( & V_6 -> V_7 ) ;
V_5 -> V_16 -> V_28 = NULL ;
V_5 -> V_16 -> V_29 = NULL ;
if ( V_6 -> V_7 . V_22 )
F_28 ( V_5 -> V_16 ) ;
F_28 ( V_5 ) ;
return 0 ;
}
static int F_32 ( struct V_49 * V_7 )
{
return 0 ;
}
