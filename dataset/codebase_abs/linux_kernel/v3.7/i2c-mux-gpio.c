static void F_1 ( const struct V_1 * V_2 , unsigned V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
F_2 ( V_2 -> V_7 + V_2 -> V_5 . V_8 [ V_4 ] ,
V_3 & ( 1 << V_4 ) ) ;
}
static int F_3 ( struct V_9 * V_10 , void * V_5 , T_1 V_11 )
{
struct V_1 * V_2 = V_5 ;
F_1 ( V_2 , V_2 -> V_5 . V_12 [ V_11 ] ) ;
return 0 ;
}
static int F_4 ( struct V_9 * V_10 , void * V_5 , T_1 V_11 )
{
struct V_1 * V_2 = V_5 ;
F_1 ( V_2 , V_2 -> V_5 . V_13 ) ;
return 0 ;
}
static int T_2 F_5 ( struct V_14 * V_15 ,
void * V_5 )
{
return ! strcmp ( V_15 -> V_16 , V_5 ) ;
}
static int T_2 F_6 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
struct V_9 * V_21 ;
int (* F_7) ( struct V_9 * , void * , T_1 );
unsigned V_22 , V_7 ;
int V_4 , V_23 ;
V_20 = V_18 -> V_24 . V_25 ;
if ( ! V_20 ) {
F_8 ( & V_18 -> V_24 , L_1 ) ;
return - V_26 ;
}
if ( V_20 -> V_14 ) {
struct V_14 * V_27 ;
V_27 = F_9 ( V_20 -> V_14 ,
F_5 ) ;
if ( ! V_27 )
return - V_28 ;
V_7 = V_27 -> V_29 ;
} else {
V_7 = 0 ;
}
V_21 = F_10 ( V_20 -> V_21 ) ;
if ( ! V_21 ) {
F_8 ( & V_18 -> V_24 , L_2 ,
V_20 -> V_21 ) ;
return - V_26 ;
}
V_2 = F_11 ( & V_18 -> V_24 , sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 ) {
V_23 = - V_31 ;
goto V_32;
}
V_2 -> V_21 = V_21 ;
V_2 -> V_5 = * V_20 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_10 = F_11 ( & V_18 -> V_24 ,
sizeof( * V_2 -> V_10 ) * V_20 -> V_33 ,
V_30 ) ;
if ( ! V_2 -> V_10 ) {
V_23 = - V_31 ;
goto V_32;
}
if ( V_20 -> V_13 != V_34 ) {
V_22 = V_20 -> V_13 ;
F_7 = F_4 ;
} else {
V_22 = V_20 -> V_12 [ 0 ] ;
F_7 = NULL ;
}
for ( V_4 = 0 ; V_4 < V_20 -> V_6 ; V_4 ++ ) {
V_23 = F_12 ( V_7 + V_20 -> V_8 [ V_4 ] , L_3 ) ;
if ( V_23 )
goto V_35;
F_13 ( V_7 + V_20 -> V_8 [ V_4 ] ,
V_22 & ( 1 << V_4 ) ) ;
}
for ( V_4 = 0 ; V_4 < V_20 -> V_33 ; V_4 ++ ) {
T_1 V_36 = V_20 -> V_37 ? ( V_20 -> V_37 + V_4 ) : 0 ;
unsigned int V_38 = V_20 -> V_39 ? V_20 -> V_39 [ V_4 ] : 0 ;
V_2 -> V_10 [ V_4 ] = F_14 ( V_21 , & V_18 -> V_24 , V_2 , V_36 ,
V_4 , V_38 ,
F_3 , F_7 ) ;
if ( ! V_2 -> V_10 [ V_4 ] ) {
V_23 = - V_26 ;
F_8 ( & V_18 -> V_24 , L_4 , V_4 ) ;
goto V_40;
}
}
F_15 ( & V_18 -> V_24 , L_5 ,
V_20 -> V_33 , V_21 -> V_41 ) ;
F_16 ( V_18 , V_2 ) ;
return 0 ;
V_40:
for (; V_4 > 0 ; V_4 -- )
F_17 ( V_2 -> V_10 [ V_4 - 1 ] ) ;
V_4 = V_20 -> V_6 ;
V_35:
for (; V_4 > 0 ; V_4 -- )
F_18 ( V_7 + V_20 -> V_8 [ V_4 - 1 ] ) ;
V_32:
F_19 ( V_21 ) ;
return V_23 ;
}
static int T_3 F_20 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_21 ( V_18 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_33 ; V_4 ++ )
F_17 ( V_2 -> V_10 [ V_4 ] ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
F_18 ( V_2 -> V_7 + V_2 -> V_5 . V_8 [ V_4 ] ) ;
F_16 ( V_18 , NULL ) ;
F_19 ( V_2 -> V_21 ) ;
return 0 ;
}
