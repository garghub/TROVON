static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_6 , V_5 -> V_7 [ V_3 ] ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_6 , V_5 -> V_8 ) ;
}
static int F_5 ( struct V_4 * V_5 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
int V_15 , V_16 , V_17 ;
struct V_11 * V_18 ;
struct V_19 * V_20 ;
if ( ! V_12 )
return 0 ;
V_5 -> V_21 = F_6 ( & V_10 -> V_13 , sizeof( * V_5 -> V_21 ) , V_22 ) ;
if ( ! V_5 -> V_21 )
return - V_23 ;
V_15 = F_7 ( V_12 , L_1 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_10 -> V_13 , L_2 ,
V_15 ) ;
return V_15 ;
}
V_5 -> V_21 -> V_24 = F_6 ( & V_10 -> V_13 ,
sizeof( * V_5 -> V_21 -> V_24 ) * V_15 ,
V_22 ) ;
if ( ! V_5 -> V_21 -> V_24 )
return - V_23 ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ ) {
V_17 = F_9 ( V_12 , L_1 , V_16 ,
& V_5 -> V_21 -> V_24 [ V_5 -> V_21 -> V_25 ] ) ;
if ( V_17 < 0 ) {
F_8 ( & V_10 -> V_13 , L_2 ,
V_17 ) ;
return V_17 ;
}
if ( ! strcmp ( V_5 -> V_21 -> V_24 [ V_5 -> V_21 -> V_25 ] ,
L_3 ) ) {
if ( V_16 != V_15 - 1 ) {
F_8 ( & V_10 -> V_13 ,
L_4 ) ;
return - V_26 ;
}
V_5 -> V_21 -> V_27 = L_3 ;
} else {
V_5 -> V_21 -> V_25 ++ ;
}
}
V_18 = F_10 ( V_12 , L_5 , 0 ) ;
if ( ! V_18 ) {
F_8 ( & V_10 -> V_13 , L_6 ) ;
return - V_28 ;
}
V_20 = F_11 ( V_18 ) ;
F_12 ( V_18 ) ;
if ( ! V_20 ) {
F_8 ( & V_10 -> V_13 , L_7 ) ;
return - V_29 ;
}
V_5 -> V_21 -> V_30 = F_13 ( V_20 ) ;
F_14 ( & V_20 -> V_13 ) ;
return 0 ;
}
static inline int F_5 ( struct V_4 * V_5 ,
struct V_9 * V_10 )
{
return 0 ;
}
static struct V_19 * F_15 (
struct V_31 * V_32 )
{
struct V_19 * V_33 = NULL ;
struct V_34 * V_35 ;
struct V_19 * V_36 ;
F_16 (setting, &state->settings, node) {
V_36 = F_17 ( V_35 -> V_37 -> V_13 ) ;
if ( ! V_36 )
return NULL ;
if ( ! V_33 )
V_33 = V_36 ;
else if ( V_33 != V_36 )
return NULL ;
}
return V_33 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_19 * V_33 ;
int V_16 , V_17 ;
V_5 = F_6 ( & V_10 -> V_13 , sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 ) {
V_17 = - V_23 ;
goto V_38;
}
V_5 -> V_21 = F_19 ( & V_10 -> V_13 ) ;
if ( ! V_5 -> V_21 ) {
V_17 = F_5 ( V_5 , V_10 ) ;
if ( V_17 < 0 )
goto V_38;
}
if ( ! V_5 -> V_21 ) {
F_8 ( & V_10 -> V_13 , L_8 ) ;
V_17 = - V_28 ;
goto V_38;
}
V_5 -> V_7 = F_6 ( & V_10 -> V_13 ,
sizeof( * V_5 -> V_7 ) * V_5 -> V_21 -> V_25 ,
V_22 ) ;
if ( ! V_5 -> V_7 ) {
F_8 ( & V_10 -> V_13 , L_9 ) ;
V_17 = - V_23 ;
goto V_38;
}
V_2 = F_20 ( NULL , & V_10 -> V_13 , V_5 -> V_21 -> V_25 , 0 , 0 ,
F_1 , NULL ) ;
if ( ! V_2 ) {
V_17 = - V_23 ;
goto V_38;
}
V_2 -> V_39 = V_5 ;
F_21 ( V_10 , V_2 ) ;
V_5 -> V_6 = F_22 ( & V_10 -> V_13 ) ;
if ( F_23 ( V_5 -> V_6 ) ) {
V_17 = F_24 ( V_5 -> V_6 ) ;
F_8 ( & V_10 -> V_13 , L_10 , V_17 ) ;
goto V_38;
}
for ( V_16 = 0 ; V_16 < V_5 -> V_21 -> V_25 ; V_16 ++ ) {
V_5 -> V_7 [ V_16 ] = F_25 ( V_5 -> V_6 ,
V_5 -> V_21 -> V_24 [ V_16 ] ) ;
if ( F_23 ( V_5 -> V_7 [ V_16 ] ) ) {
V_17 = F_24 ( V_5 -> V_7 [ V_16 ] ) ;
F_8 ( & V_10 -> V_13 ,
L_11 ,
V_5 -> V_21 -> V_24 [ V_16 ] , V_17 ) ;
goto V_38;
}
}
if ( V_5 -> V_21 -> V_27 ) {
V_5 -> V_8 = F_25 ( V_5 -> V_6 ,
V_5 -> V_21 -> V_27 ) ;
if ( F_23 ( V_5 -> V_8 ) ) {
V_17 = F_24 ( V_5 -> V_8 ) ;
F_8 ( & V_10 -> V_13 ,
L_11 ,
V_5 -> V_21 -> V_27 , V_17 ) ;
goto V_38;
}
V_2 -> V_40 = F_4 ;
}
V_2 -> V_41 = F_26 ( V_5 -> V_21 -> V_30 ) ;
if ( ! V_2 -> V_41 ) {
F_8 ( & V_10 -> V_13 , L_12 ,
V_5 -> V_21 -> V_30 ) ;
V_17 = - V_29 ;
goto V_38;
}
V_33 = F_17 ( & V_2 -> V_41 -> V_13 ) ;
V_2 -> V_42 = true ;
for ( V_16 = 0 ; V_16 < V_5 -> V_21 -> V_25 ; V_16 ++ ) {
if ( V_33 != F_15 ( V_5 -> V_7 [ V_16 ] ) ) {
V_2 -> V_42 = false ;
break;
}
}
if ( V_2 -> V_42 && V_5 -> V_21 -> V_27 &&
V_33 != F_15 ( V_5 -> V_8 ) )
V_2 -> V_42 = false ;
if ( V_2 -> V_42 )
F_27 ( & V_10 -> V_13 , L_13 ) ;
for ( V_16 = 0 ; V_16 < V_5 -> V_21 -> V_25 ; V_16 ++ ) {
T_1 V_43 = V_5 -> V_21 -> V_44 ?
( V_5 -> V_21 -> V_44 + V_16 ) : 0 ;
V_17 = F_28 ( V_2 , V_43 , V_16 , 0 ) ;
if ( V_17 )
goto V_45;
}
return 0 ;
V_45:
F_29 ( V_2 ) ;
F_30 ( V_2 -> V_41 ) ;
V_38:
return V_17 ;
}
static int F_31 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_32 ( V_10 ) ;
F_29 ( V_2 ) ;
F_30 ( V_2 -> V_41 ) ;
return 0 ;
}
