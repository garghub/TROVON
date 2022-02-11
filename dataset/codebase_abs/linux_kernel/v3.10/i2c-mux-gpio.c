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
static int F_5 ( struct V_14 * V_15 ,
void * V_5 )
{
return ! strcmp ( V_15 -> V_16 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 . V_22 ;
struct V_19 * V_23 , * V_24 ;
struct V_9 * V_25 ;
unsigned * V_12 , * V_8 ;
int V_4 = 0 ;
if ( ! V_20 )
return - V_26 ;
V_23 = F_7 ( V_20 , L_1 , 0 ) ;
if ( ! V_23 ) {
F_8 ( & V_18 -> V_21 , L_2 ) ;
return - V_26 ;
}
V_25 = F_9 ( V_23 ) ;
if ( ! V_25 ) {
F_8 ( & V_18 -> V_21 , L_3 ) ;
return - V_26 ;
}
V_2 -> V_5 . V_27 = F_10 ( V_25 ) ;
F_11 ( & V_25 -> V_21 ) ;
V_2 -> V_5 . V_28 = F_12 ( V_20 ) ;
V_12 = F_13 ( & V_18 -> V_21 ,
sizeof( * V_2 -> V_5 . V_12 ) * V_2 -> V_5 . V_28 ,
V_29 ) ;
if ( ! V_12 ) {
F_8 ( & V_18 -> V_21 , L_4 ) ;
return - V_30 ;
}
F_14 (np, child) {
F_15 ( V_24 , L_5 , V_12 + V_4 ) ;
V_4 ++ ;
}
V_2 -> V_5 . V_12 = V_12 ;
if ( F_15 ( V_20 , L_6 , & V_2 -> V_5 . V_13 ) )
V_2 -> V_5 . V_13 = V_31 ;
V_2 -> V_5 . V_6 = F_16 ( V_20 , L_7 ) ;
if ( V_2 -> V_5 . V_6 < 0 ) {
F_8 ( & V_18 -> V_21 , L_8 ) ;
return - V_32 ;
}
V_8 = F_13 ( & V_18 -> V_21 ,
sizeof( * V_2 -> V_5 . V_8 ) * V_2 -> V_5 . V_6 , V_29 ) ;
if ( ! V_8 ) {
F_8 ( & V_18 -> V_21 , L_9 ) ;
return - V_30 ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
V_8 [ V_4 ] = F_17 ( V_20 , L_7 , V_4 ) ;
V_2 -> V_5 . V_8 = V_8 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
return 0 ;
}
static int F_18 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_9 * V_27 ;
int (* F_19) ( struct V_9 * , void * , T_1 );
unsigned V_33 , V_7 ;
int V_4 , V_34 ;
V_2 = F_13 ( & V_18 -> V_21 , sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 ) {
F_8 ( & V_18 -> V_21 , L_10 ) ;
return - V_30 ;
}
F_20 ( V_18 , V_2 ) ;
if ( ! V_18 -> V_21 . V_35 ) {
V_34 = F_6 ( V_2 , V_18 ) ;
if ( V_34 < 0 )
return V_34 ;
} else
memcpy ( & V_2 -> V_5 , V_18 -> V_21 . V_35 , sizeof( V_2 -> V_5 ) ) ;
if ( V_2 -> V_5 . V_14 ) {
struct V_14 * V_36 ;
V_36 = F_21 ( V_2 -> V_5 . V_14 ,
F_5 ) ;
if ( ! V_36 )
return - V_37 ;
V_7 = V_36 -> V_38 ;
} else {
V_7 = 0 ;
}
V_27 = F_22 ( V_2 -> V_5 . V_27 ) ;
if ( ! V_27 ) {
F_8 ( & V_18 -> V_21 , L_11 ,
V_2 -> V_5 . V_27 ) ;
return - V_26 ;
}
V_2 -> V_27 = V_27 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_10 = F_13 ( & V_18 -> V_21 ,
sizeof( * V_2 -> V_10 ) * V_2 -> V_5 . V_28 ,
V_29 ) ;
if ( ! V_2 -> V_10 ) {
F_8 ( & V_18 -> V_21 , L_12 ) ;
V_34 = - V_30 ;
goto V_39;
}
if ( V_2 -> V_5 . V_13 != V_31 ) {
V_33 = V_2 -> V_5 . V_13 ;
F_19 = F_4 ;
} else {
V_33 = V_2 -> V_5 . V_12 [ 0 ] ;
F_19 = NULL ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ ) {
V_34 = F_23 ( V_7 + V_2 -> V_5 . V_8 [ V_4 ] , L_13 ) ;
if ( V_34 ) {
F_8 ( & V_18 -> V_21 , L_14 ,
V_2 -> V_5 . V_8 [ V_4 ] ) ;
goto V_40;
}
V_34 = F_24 ( V_7 + V_2 -> V_5 . V_8 [ V_4 ] ,
V_33 & ( 1 << V_4 ) ) ;
if ( V_34 ) {
F_8 ( & V_18 -> V_21 ,
L_15 ,
V_2 -> V_5 . V_8 [ V_4 ] ) ;
V_4 ++ ;
goto V_40;
}
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_28 ; V_4 ++ ) {
T_1 V_41 = V_2 -> V_5 . V_42 ? ( V_2 -> V_5 . V_42 + V_4 ) : 0 ;
unsigned int V_43 = V_2 -> V_5 . V_44 ? V_2 -> V_5 . V_44 [ V_4 ] : 0 ;
V_2 -> V_10 [ V_4 ] = F_25 ( V_27 , & V_18 -> V_21 , V_2 , V_41 ,
V_4 , V_43 ,
F_3 , F_19 ) ;
if ( ! V_2 -> V_10 [ V_4 ] ) {
V_34 = - V_26 ;
F_8 ( & V_18 -> V_21 , L_16 , V_4 ) ;
goto V_45;
}
}
F_26 ( & V_18 -> V_21 , L_17 ,
V_2 -> V_5 . V_28 , V_27 -> V_46 ) ;
return 0 ;
V_45:
for (; V_4 > 0 ; V_4 -- )
F_27 ( V_2 -> V_10 [ V_4 - 1 ] ) ;
V_4 = V_2 -> V_5 . V_6 ;
V_40:
for (; V_4 > 0 ; V_4 -- )
F_28 ( V_7 + V_2 -> V_5 . V_8 [ V_4 - 1 ] ) ;
V_39:
F_29 ( V_27 ) ;
return V_34 ;
}
static int F_30 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_31 ( V_18 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_28 ; V_4 ++ )
F_27 ( V_2 -> V_10 [ V_4 ] ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
F_28 ( V_2 -> V_7 + V_2 -> V_5 . V_8 [ V_4 ] ) ;
F_29 ( V_2 -> V_27 ) ;
return 0 ;
}
