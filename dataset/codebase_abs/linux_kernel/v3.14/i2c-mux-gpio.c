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
F_1 ( V_2 , V_11 ) ;
return 0 ;
}
static int F_4 ( struct V_9 * V_10 , void * V_5 , T_1 V_11 )
{
struct V_1 * V_2 = V_5 ;
F_1 ( V_2 , V_2 -> V_5 . V_12 ) ;
return 0 ;
}
static int F_5 ( struct V_13 * V_14 ,
void * V_5 )
{
return ! strcmp ( V_14 -> V_15 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 . V_21 ;
struct V_18 * V_22 , * V_23 ;
struct V_9 * V_24 ;
unsigned * V_25 , * V_8 ;
int V_4 = 0 , V_26 ;
if ( ! V_19 )
return - V_27 ;
V_22 = F_7 ( V_19 , L_1 , 0 ) ;
if ( ! V_22 ) {
F_8 ( & V_17 -> V_20 , L_2 ) ;
return - V_27 ;
}
V_24 = F_9 ( V_22 ) ;
if ( ! V_24 ) {
F_8 ( & V_17 -> V_20 , L_3 ) ;
return - V_28 ;
}
V_2 -> V_5 . V_29 = F_10 ( V_24 ) ;
F_11 ( & V_24 -> V_20 ) ;
V_2 -> V_5 . V_30 = F_12 ( V_19 ) ;
V_25 = F_13 ( & V_17 -> V_20 ,
sizeof( * V_2 -> V_5 . V_25 ) * V_2 -> V_5 . V_30 ,
V_31 ) ;
if ( ! V_25 ) {
F_8 ( & V_17 -> V_20 , L_4 ) ;
return - V_32 ;
}
F_14 (np, child) {
F_15 ( V_23 , L_5 , V_25 + V_4 ) ;
V_4 ++ ;
}
V_2 -> V_5 . V_25 = V_25 ;
if ( F_15 ( V_19 , L_6 , & V_2 -> V_5 . V_12 ) )
V_2 -> V_5 . V_12 = V_33 ;
V_2 -> V_5 . V_6 = F_16 ( V_19 , L_7 ) ;
if ( V_2 -> V_5 . V_6 < 0 ) {
F_8 ( & V_17 -> V_20 , L_8 ) ;
return - V_34 ;
}
V_8 = F_13 ( & V_17 -> V_20 ,
sizeof( * V_2 -> V_5 . V_8 ) * V_2 -> V_5 . V_6 , V_31 ) ;
if ( ! V_8 ) {
F_8 ( & V_17 -> V_20 , L_9 ) ;
return - V_32 ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ ) {
V_26 = F_17 ( V_19 , L_7 , V_4 ) ;
if ( V_26 < 0 )
return V_26 ;
V_8 [ V_4 ] = V_26 ;
}
V_2 -> V_5 . V_8 = V_8 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
return 0 ;
}
static int F_18 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_9 * V_29 ;
int (* F_19) ( struct V_9 * , void * , T_1 );
unsigned V_35 , V_7 ;
int V_4 , V_26 ;
V_2 = F_13 ( & V_17 -> V_20 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 ) {
F_8 ( & V_17 -> V_20 , L_10 ) ;
return - V_32 ;
}
F_20 ( V_17 , V_2 ) ;
if ( ! F_21 ( & V_17 -> V_20 ) ) {
V_26 = F_6 ( V_2 , V_17 ) ;
if ( V_26 < 0 )
return V_26 ;
} else {
memcpy ( & V_2 -> V_5 , F_21 ( & V_17 -> V_20 ) ,
sizeof( V_2 -> V_5 ) ) ;
}
if ( V_2 -> V_5 . V_13 ) {
struct V_13 * V_36 ;
V_36 = F_22 ( V_2 -> V_5 . V_13 ,
F_5 ) ;
if ( ! V_36 )
return - V_28 ;
V_7 = V_36 -> V_37 ;
} else {
V_7 = 0 ;
}
V_29 = F_23 ( V_2 -> V_5 . V_29 ) ;
if ( ! V_29 ) {
F_8 ( & V_17 -> V_20 , L_11 ,
V_2 -> V_5 . V_29 ) ;
return - V_28 ;
}
V_2 -> V_29 = V_29 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_10 = F_13 ( & V_17 -> V_20 ,
sizeof( * V_2 -> V_10 ) * V_2 -> V_5 . V_30 ,
V_31 ) ;
if ( ! V_2 -> V_10 ) {
F_8 ( & V_17 -> V_20 , L_12 ) ;
V_26 = - V_32 ;
goto V_38;
}
if ( V_2 -> V_5 . V_12 != V_33 ) {
V_35 = V_2 -> V_5 . V_12 ;
F_19 = F_4 ;
} else {
V_35 = V_2 -> V_5 . V_25 [ 0 ] ;
F_19 = NULL ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ ) {
V_26 = F_24 ( V_7 + V_2 -> V_5 . V_8 [ V_4 ] , L_13 ) ;
if ( V_26 ) {
F_8 ( & V_17 -> V_20 , L_14 ,
V_2 -> V_5 . V_8 [ V_4 ] ) ;
goto V_39;
}
V_26 = F_25 ( V_7 + V_2 -> V_5 . V_8 [ V_4 ] ,
V_35 & ( 1 << V_4 ) ) ;
if ( V_26 ) {
F_8 ( & V_17 -> V_20 ,
L_15 ,
V_2 -> V_5 . V_8 [ V_4 ] ) ;
V_4 ++ ;
goto V_39;
}
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_30 ; V_4 ++ ) {
T_1 V_40 = V_2 -> V_5 . V_41 ? ( V_2 -> V_5 . V_41 + V_4 ) : 0 ;
unsigned int V_42 = V_2 -> V_5 . V_43 ? V_2 -> V_5 . V_43 [ V_4 ] : 0 ;
V_2 -> V_10 [ V_4 ] = F_26 ( V_29 , & V_17 -> V_20 , V_2 , V_40 ,
V_2 -> V_5 . V_25 [ V_4 ] , V_42 ,
F_3 , F_19 ) ;
if ( ! V_2 -> V_10 [ V_4 ] ) {
V_26 = - V_27 ;
F_8 ( & V_17 -> V_20 , L_16 , V_4 ) ;
goto V_44;
}
}
F_27 ( & V_17 -> V_20 , L_17 ,
V_2 -> V_5 . V_30 , V_29 -> V_45 ) ;
return 0 ;
V_44:
for (; V_4 > 0 ; V_4 -- )
F_28 ( V_2 -> V_10 [ V_4 - 1 ] ) ;
V_4 = V_2 -> V_5 . V_6 ;
V_39:
for (; V_4 > 0 ; V_4 -- )
F_29 ( V_7 + V_2 -> V_5 . V_8 [ V_4 - 1 ] ) ;
V_38:
F_30 ( V_29 ) ;
return V_26 ;
}
static int F_31 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_32 ( V_17 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_30 ; V_4 ++ )
F_28 ( V_2 -> V_10 [ V_4 ] ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
F_29 ( V_2 -> V_7 + V_2 -> V_5 . V_8 [ V_4 ] ) ;
F_30 ( V_2 -> V_29 ) ;
return 0 ;
}
