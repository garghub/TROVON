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
struct V_1 * V_16 = V_6 -> V_7 . V_17 ;
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int V_20 = - V_21 ;
int V_22 ;
if ( V_6 -> V_7 . V_23 ) {
V_16 = F_16 ( sizeof( * V_16 ) , V_24 ) ;
if ( ! V_16 ) {
V_20 = - V_25 ;
F_17 ( & V_6 -> V_7 , L_1 ) ;
return V_20 ;
}
V_16 -> V_26 = V_6 -> V_7 . V_23 -> V_26 ;
V_16 -> V_27 = L_2 ;
}
if ( ! V_16 || ! V_16 -> V_26 || ! V_16 -> V_27 ) {
F_17 ( & V_6 -> V_7 , L_3 ) ;
goto V_28;
}
if ( V_16 -> V_29 || V_16 -> V_30 ||
V_16 -> V_31 & V_32 ) {
F_17 ( & V_6 -> V_7 , L_4 ) ;
goto V_28;
}
V_5 = F_16 ( sizeof( * V_5 ) , V_24 ) ;
if ( ! V_5 ) {
V_20 = - V_25 ;
F_17 ( & V_6 -> V_7 , L_1 ) ;
goto V_28;
}
V_5 -> V_16 = V_16 ;
F_18 ( & V_5 -> V_10 ) ;
V_5 -> V_12 = 0 ;
V_5 -> V_6 = V_6 ;
if ( ! V_16 -> V_8 ) {
V_20 = F_19 ( V_6 , 0 ) ;
V_16 -> V_8 = V_20 ;
if ( V_20 == - V_33 && V_6 -> V_7 . V_23 )
V_16 -> V_8 = V_34 ;
else if ( V_20 < 0 ) {
F_17 ( & V_6 -> V_7 , L_5 ) ;
goto V_35;
}
}
V_19 = & V_16 -> V_36 [ 0 ] ;
for ( V_22 = 0 ; V_22 < V_6 -> V_37 ; ++ V_22 ) {
struct V_38 * V_39 = & V_6 -> V_38 [ V_22 ] ;
if ( V_39 -> V_12 != V_40 )
continue;
if ( V_19 >= & V_16 -> V_36 [ V_41 ] ) {
F_20 ( & V_6 -> V_7 , L_6
F_21 ( V_41 )
L_7 ) ;
break;
}
V_19 -> V_42 = V_43 ;
V_19 -> V_44 = V_39 -> V_45 ;
V_19 -> V_46 = F_22 ( V_39 ) ;
V_19 -> V_26 = V_39 -> V_26 ;
++ V_19 ;
}
while ( V_19 < & V_16 -> V_36 [ V_41 ] ) {
V_19 -> V_46 = 0 ;
++ V_19 ;
}
V_16 -> V_29 = F_5 ;
V_16 -> V_30 = F_10 ;
V_16 -> V_47 = F_1 ;
V_16 -> V_48 = F_3 ;
V_16 -> V_5 = V_5 ;
F_23 ( & V_6 -> V_7 ) ;
V_20 = F_24 ( & V_6 -> V_7 , V_5 -> V_16 ) ;
if ( V_20 ) {
F_17 ( & V_6 -> V_7 , L_8 ) ;
goto V_49;
}
F_25 ( V_6 , V_5 ) ;
return 0 ;
V_49:
F_26 ( & V_6 -> V_7 ) ;
V_35:
F_27 ( V_5 ) ;
V_28:
if ( V_6 -> V_7 . V_23 )
F_27 ( V_16 ) ;
return V_20 ;
}
static int F_28 ( struct V_15 * V_6 )
{
struct V_4 * V_5 = F_29 ( V_6 ) ;
F_30 ( V_5 -> V_16 ) ;
F_26 ( & V_6 -> V_7 ) ;
V_5 -> V_16 -> V_29 = NULL ;
V_5 -> V_16 -> V_30 = NULL ;
if ( V_6 -> V_7 . V_23 )
F_27 ( V_5 -> V_16 ) ;
F_27 ( V_5 ) ;
return 0 ;
}
static int F_31 ( struct V_50 * V_7 )
{
return 0 ;
}
