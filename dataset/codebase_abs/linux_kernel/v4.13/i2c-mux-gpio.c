static void F_1 ( const struct V_1 * V_2 , unsigned V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
V_2 -> V_7 [ V_4 ] = ( V_3 >> V_4 ) & 1 ;
F_2 ( V_2 -> V_5 . V_6 ,
V_2 -> V_8 , V_2 -> V_7 ) ;
}
static int F_3 ( struct V_9 * V_10 , T_1 V_11 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
F_1 ( V_2 , V_11 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 , T_1 V_11 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
F_1 ( V_2 , V_2 -> V_5 . V_12 ) ;
return 0 ;
}
static int F_6 ( struct V_13 * V_14 ,
void * V_5 )
{
return ! strcmp ( V_14 -> V_15 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 . V_21 ;
struct V_18 * V_22 , * V_23 ;
struct V_24 * V_25 ;
unsigned * V_7 , * V_8 ;
int V_4 = 0 , V_26 ;
if ( ! V_19 )
return - V_27 ;
V_22 = F_8 ( V_19 , L_1 , 0 ) ;
if ( ! V_22 ) {
F_9 ( & V_17 -> V_20 , L_2 ) ;
return - V_27 ;
}
V_25 = F_10 ( V_22 ) ;
F_11 ( V_22 ) ;
if ( ! V_25 )
return - V_28 ;
V_2 -> V_5 . V_29 = F_12 ( V_25 ) ;
F_13 ( & V_25 -> V_20 ) ;
V_2 -> V_5 . V_30 = F_14 ( V_19 ) ;
V_7 = F_15 ( & V_17 -> V_20 ,
sizeof( * V_2 -> V_5 . V_7 ) * V_2 -> V_5 . V_30 ,
V_31 ) ;
if ( ! V_7 ) {
F_9 ( & V_17 -> V_20 , L_3 ) ;
return - V_32 ;
}
F_16 (np, child) {
F_17 ( V_23 , L_4 , V_7 + V_4 ) ;
V_4 ++ ;
}
V_2 -> V_5 . V_7 = V_7 ;
if ( F_17 ( V_19 , L_5 , & V_2 -> V_5 . V_12 ) )
V_2 -> V_5 . V_12 = V_33 ;
V_2 -> V_5 . V_6 = F_18 ( V_19 , L_6 ) ;
if ( V_2 -> V_5 . V_6 < 0 ) {
F_9 ( & V_17 -> V_20 , L_7 ) ;
return - V_34 ;
}
V_8 = F_15 ( & V_17 -> V_20 ,
sizeof( * V_2 -> V_5 . V_8 ) * V_2 -> V_5 . V_6 , V_31 ) ;
if ( ! V_8 ) {
F_9 ( & V_17 -> V_20 , L_8 ) ;
return - V_32 ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ ) {
V_26 = F_19 ( V_19 , L_6 , V_4 ) ;
if ( V_26 < 0 )
return V_26 ;
V_8 [ V_4 ] = V_26 ;
}
V_2 -> V_5 . V_8 = V_8 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
return 0 ;
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_24 * V_29 ;
struct V_24 * V_35 ;
unsigned V_36 , V_37 ;
int V_4 , V_26 ;
V_2 = F_15 ( & V_17 -> V_20 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
return - V_32 ;
if ( ! F_21 ( & V_17 -> V_20 ) ) {
V_26 = F_7 ( V_2 , V_17 ) ;
if ( V_26 < 0 )
return V_26 ;
} else {
memcpy ( & V_2 -> V_5 , F_21 ( & V_17 -> V_20 ) ,
sizeof( V_2 -> V_5 ) ) ;
}
if ( V_2 -> V_5 . V_13 ) {
struct V_13 * V_38 ;
V_38 = F_22 ( V_2 -> V_5 . V_13 ,
F_6 ) ;
if ( ! V_38 )
return - V_28 ;
V_37 = V_38 -> V_39 ;
} else {
V_37 = 0 ;
}
V_29 = F_23 ( V_2 -> V_5 . V_29 ) ;
if ( ! V_29 )
return - V_28 ;
V_10 = F_24 ( V_29 , & V_17 -> V_20 , V_2 -> V_5 . V_30 ,
V_2 -> V_5 . V_6 * sizeof( * V_2 -> V_8 ) +
V_2 -> V_5 . V_6 * sizeof( * V_2 -> V_7 ) , 0 ,
F_3 , NULL ) ;
if ( ! V_10 ) {
V_26 = - V_32 ;
goto V_40;
}
V_2 -> V_8 = V_10 -> V_41 ;
V_2 -> V_7 = ( int * ) ( V_2 -> V_8 + V_2 -> V_5 . V_6 ) ;
V_10 -> V_41 = V_2 ;
F_25 ( V_17 , V_10 ) ;
V_35 = F_26 ( & V_29 -> V_20 ) ;
V_10 -> V_42 = true ;
V_2 -> V_37 = V_37 ;
if ( V_2 -> V_5 . V_12 != V_33 ) {
V_36 = V_2 -> V_5 . V_12 ;
V_10 -> V_43 = F_5 ;
} else {
V_36 = V_2 -> V_5 . V_7 [ 0 ] ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ ) {
struct V_44 * V_45 ;
struct V_46 * V_46 ;
V_26 = F_27 ( V_37 + V_2 -> V_5 . V_8 [ V_4 ] , L_9 ) ;
if ( V_26 ) {
F_9 ( & V_17 -> V_20 , L_10 ,
V_2 -> V_5 . V_8 [ V_4 ] ) ;
goto V_47;
}
V_26 = F_28 ( V_37 + V_2 -> V_5 . V_8 [ V_4 ] ,
V_36 & ( 1 << V_4 ) ) ;
if ( V_26 ) {
F_9 ( & V_17 -> V_20 ,
L_11 ,
V_2 -> V_5 . V_8 [ V_4 ] ) ;
V_4 ++ ;
goto V_47;
}
V_46 = F_29 ( V_37 + V_2 -> V_5 . V_8 [ V_4 ] ) ;
V_2 -> V_8 [ V_4 ] = V_46 ;
if ( ! V_10 -> V_42 )
continue;
V_45 = & V_46 -> V_48 -> V_20 ;
V_10 -> V_42 = F_26 ( V_45 ) == V_35 ;
}
if ( V_10 -> V_42 )
F_30 ( & V_17 -> V_20 , L_12 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_30 ; V_4 ++ ) {
T_1 V_49 = V_2 -> V_5 . V_50 ? ( V_2 -> V_5 . V_50 + V_4 ) : 0 ;
unsigned int V_51 = V_2 -> V_5 . V_52 ? V_2 -> V_5 . V_52 [ V_4 ] : 0 ;
V_26 = F_31 ( V_10 , V_49 , V_2 -> V_5 . V_7 [ V_4 ] , V_51 ) ;
if ( V_26 )
goto V_53;
}
F_30 ( & V_17 -> V_20 , L_13 ,
V_2 -> V_5 . V_30 , V_29 -> V_54 ) ;
return 0 ;
V_53:
F_32 ( V_10 ) ;
V_4 = V_2 -> V_5 . V_6 ;
V_47:
for (; V_4 > 0 ; V_4 -- )
F_33 ( V_37 + V_2 -> V_5 . V_8 [ V_4 - 1 ] ) ;
V_40:
F_34 ( V_29 ) ;
return V_26 ;
}
static int F_35 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_36 ( V_17 ) ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
int V_4 ;
F_32 ( V_10 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
F_33 ( V_2 -> V_37 + V_2 -> V_5 . V_8 [ V_4 ] ) ;
F_34 ( V_10 -> V_29 ) ;
return 0 ;
}
