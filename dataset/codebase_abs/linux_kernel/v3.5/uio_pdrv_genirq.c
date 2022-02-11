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
if ( ! F_6 ( 0 , & V_5 -> V_10 ) )
F_7 ( V_8 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_9 , T_2 V_12 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
unsigned long V_10 ;
F_9 ( & V_5 -> V_13 , V_10 ) ;
if ( V_12 ) {
if ( F_10 ( 0 , & V_5 -> V_10 ) )
F_11 ( V_9 -> V_8 ) ;
} else {
if ( ! F_6 ( 0 , & V_5 -> V_10 ) )
F_12 ( V_9 -> V_8 ) ;
}
F_13 ( & V_5 -> V_13 , V_10 ) ;
return 0 ;
}
static int F_14 ( struct V_14 * V_6 )
{
struct V_1 * V_15 = V_6 -> V_7 . V_16 ;
struct V_4 * V_5 ;
struct V_17 * V_18 ;
int V_19 = - V_20 ;
int V_21 ;
if ( ! V_15 ) {
int V_8 ;
V_15 = F_15 ( sizeof( * V_15 ) , V_22 ) ;
if ( ! V_15 ) {
V_19 = - V_23 ;
F_16 ( & V_6 -> V_7 , L_1 ) ;
goto V_24;
}
V_15 -> V_25 = V_6 -> V_7 . V_26 -> V_25 ;
V_15 -> V_27 = L_2 ;
V_8 = F_17 ( V_6 , 0 ) ;
if ( V_8 == - V_28 )
V_15 -> V_8 = V_29 ;
else
V_15 -> V_8 = V_8 ;
}
if ( ! V_15 || ! V_15 -> V_25 || ! V_15 -> V_27 ) {
F_16 ( & V_6 -> V_7 , L_3 ) ;
goto V_30;
}
if ( V_15 -> V_31 || V_15 -> V_32 ||
V_15 -> V_33 & V_34 ) {
F_16 ( & V_6 -> V_7 , L_4 ) ;
goto V_30;
}
V_5 = F_15 ( sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 ) {
V_19 = - V_23 ;
F_16 ( & V_6 -> V_7 , L_1 ) ;
goto V_30;
}
V_5 -> V_15 = V_15 ;
F_18 ( & V_5 -> V_13 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_6 = V_6 ;
if ( ! V_15 -> V_8 ) {
V_19 = F_17 ( V_6 , 0 ) ;
if ( V_19 < 0 ) {
F_16 ( & V_6 -> V_7 , L_5 ) ;
goto V_30;
}
V_15 -> V_8 = V_19 ;
}
V_18 = & V_15 -> V_35 [ 0 ] ;
for ( V_21 = 0 ; V_21 < V_6 -> V_36 ; ++ V_21 ) {
struct V_37 * V_38 = & V_6 -> V_37 [ V_21 ] ;
if ( V_38 -> V_10 != V_39 )
continue;
if ( V_18 >= & V_15 -> V_35 [ V_40 ] ) {
F_19 ( & V_6 -> V_7 , L_6
F_20 ( V_40 )
L_7 ) ;
break;
}
V_18 -> V_41 = V_42 ;
V_18 -> V_43 = V_38 -> V_44 ;
V_18 -> V_45 = F_21 ( V_38 ) ;
++ V_18 ;
}
while ( V_18 < & V_15 -> V_35 [ V_40 ] ) {
V_18 -> V_45 = 0 ;
++ V_18 ;
}
V_15 -> V_31 = F_5 ;
V_15 -> V_32 = F_8 ;
V_15 -> V_46 = F_1 ;
V_15 -> V_47 = F_3 ;
V_15 -> V_5 = V_5 ;
F_22 ( & V_6 -> V_7 ) ;
V_19 = F_23 ( & V_6 -> V_7 , V_5 -> V_15 ) ;
if ( V_19 ) {
F_16 ( & V_6 -> V_7 , L_8 ) ;
goto V_48;
}
F_24 ( V_6 , V_5 ) ;
return 0 ;
V_48:
F_25 ( V_5 ) ;
F_26 ( & V_6 -> V_7 ) ;
V_30:
if ( V_6 -> V_7 . V_26 )
F_25 ( V_15 ) ;
V_24:
return V_19 ;
}
static int F_27 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = F_28 ( V_6 ) ;
F_29 ( V_5 -> V_15 ) ;
F_26 ( & V_6 -> V_7 ) ;
V_5 -> V_15 -> V_31 = NULL ;
V_5 -> V_15 -> V_32 = NULL ;
if ( V_6 -> V_7 . V_26 )
F_25 ( V_5 -> V_15 ) ;
F_25 ( V_5 ) ;
return 0 ;
}
static int F_30 ( struct V_49 * V_7 )
{
return 0 ;
}
