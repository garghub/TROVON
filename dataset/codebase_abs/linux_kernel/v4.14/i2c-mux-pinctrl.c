static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_6 , V_5 -> V_7 [ V_3 ] ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_1 ( V_2 , V_2 -> V_8 ) ;
}
static struct V_9 * F_5 (
struct V_10 * V_11 )
{
struct V_9 * V_12 = NULL ;
struct V_13 * V_14 ;
struct V_9 * V_15 ;
F_6 (setting, &state->settings, node) {
V_15 = F_7 ( V_14 -> V_16 -> V_17 ) ;
if ( ! V_15 )
return NULL ;
if ( ! V_12 )
V_12 = V_15 ;
else if ( V_12 != V_15 )
return NULL ;
}
return V_12 ;
}
static struct V_9 * F_8 ( struct V_18 * V_17 )
{
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_19 * V_22 ;
struct V_9 * V_23 ;
V_22 = F_9 ( V_20 , L_1 , 0 ) ;
if ( ! V_22 ) {
F_10 ( V_17 , L_2 ) ;
return F_11 ( - V_24 ) ;
}
V_23 = F_12 ( V_22 ) ;
F_13 ( V_22 ) ;
if ( ! V_23 )
return F_11 ( - V_25 ) ;
return V_23 ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_18 * V_17 = & V_27 -> V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_9 * V_23 ;
struct V_9 * V_12 ;
int V_28 , V_29 , V_30 ;
const char * V_31 ;
V_28 = F_15 ( V_20 , L_3 ) ;
if ( V_28 < 0 ) {
F_10 ( V_17 , L_4 ,
V_28 ) ;
return V_28 ;
}
V_23 = F_8 ( V_17 ) ;
if ( F_16 ( V_23 ) )
return F_17 ( V_23 ) ;
V_2 = F_18 ( V_23 , V_17 , V_28 ,
sizeof( * V_5 ) + V_28 * sizeof( * V_5 -> V_7 ) ,
0 , F_1 , NULL ) ;
if ( ! V_2 ) {
V_30 = - V_32 ;
goto V_33;
}
V_5 = F_2 ( V_2 ) ;
V_5 -> V_7 = (struct V_10 * * ) ( V_5 + 1 ) ;
F_19 ( V_27 , V_2 ) ;
V_5 -> V_6 = F_20 ( V_17 ) ;
if ( F_16 ( V_5 -> V_6 ) ) {
V_30 = F_17 ( V_5 -> V_6 ) ;
F_10 ( V_17 , L_5 , V_30 ) ;
goto V_33;
}
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
V_30 = F_21 ( V_20 , L_3 , V_29 ,
& V_31 ) ;
if ( V_30 < 0 ) {
F_10 ( V_17 , L_4 , V_30 ) ;
goto V_33;
}
V_5 -> V_7 [ V_29 ] = F_22 ( V_5 -> V_6 , V_31 ) ;
if ( F_16 ( V_5 -> V_7 [ V_29 ] ) ) {
V_30 = F_17 ( V_5 -> V_7 [ V_29 ] ) ;
F_10 ( V_17 , L_6 ,
V_31 , V_30 ) ;
goto V_33;
}
if ( strcmp ( V_31 , L_7 ) )
continue;
if ( V_29 != V_28 - 1 ) {
F_10 ( V_17 , L_8 ) ;
V_30 = - V_34 ;
goto V_33;
}
V_2 -> V_35 = F_4 ;
}
V_12 = F_7 ( & V_2 -> V_23 -> V_17 ) ;
V_2 -> V_36 = true ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
if ( V_12 != F_5 ( V_5 -> V_7 [ V_29 ] ) ) {
V_2 -> V_36 = false ;
break;
}
}
if ( V_2 -> V_36 )
F_23 ( V_17 , L_9 ) ;
for ( V_29 = 0 ; V_29 < V_28 - ! ! V_2 -> V_35 ; V_29 ++ ) {
V_30 = F_24 ( V_2 , 0 , V_29 , 0 ) ;
if ( V_30 )
goto V_37;
}
return 0 ;
V_37:
F_25 ( V_2 ) ;
V_33:
F_26 ( V_23 ) ;
return V_30 ;
}
static int F_27 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_28 ( V_27 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 -> V_23 ) ;
return 0 ;
}
