static int F_1 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_3 ;
return F_2 ( V_6 -> V_7 , V_6 -> V_8 [ V_4 ] ) ;
}
static int F_3 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_3 ;
return F_2 ( V_6 -> V_7 , V_6 -> V_9 ) ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 . V_15 ;
int V_16 , V_17 , V_18 ;
struct V_12 * V_19 ;
struct V_1 * V_20 ;
if ( ! V_13 )
return 0 ;
V_6 -> V_21 = F_5 ( & V_11 -> V_14 , sizeof( * V_6 -> V_21 ) , V_22 ) ;
if ( ! V_6 -> V_21 ) {
F_6 ( V_6 -> V_14 ,
L_1 ) ;
return - V_23 ;
}
V_16 = F_7 ( V_13 , L_2 ) ;
if ( V_16 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_16 ) ;
return V_16 ;
}
V_6 -> V_21 -> V_24 = F_5 ( & V_11 -> V_14 ,
sizeof( * V_6 -> V_21 -> V_24 ) * V_16 ,
V_22 ) ;
if ( ! V_6 -> V_21 -> V_24 ) {
F_6 ( V_6 -> V_14 , L_4 ) ;
return - V_23 ;
}
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
V_18 = F_8 ( V_13 , L_2 , V_17 ,
& V_6 -> V_21 -> V_24 [ V_6 -> V_21 -> V_25 ] ) ;
if ( V_18 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_18 ) ;
return V_18 ;
}
if ( ! strcmp ( V_6 -> V_21 -> V_24 [ V_6 -> V_21 -> V_25 ] ,
L_5 ) ) {
if ( V_17 != V_16 - 1 ) {
F_6 ( V_6 -> V_14 , L_6 ) ;
return - V_26 ;
}
V_6 -> V_21 -> V_27 = L_5 ;
} else {
V_6 -> V_21 -> V_25 ++ ;
}
}
V_19 = F_9 ( V_13 , L_7 , 0 ) ;
if ( ! V_19 ) {
F_6 ( V_6 -> V_14 , L_8 ) ;
return - V_28 ;
}
V_20 = F_10 ( V_19 ) ;
F_11 ( V_19 ) ;
if ( ! V_20 ) {
F_6 ( V_6 -> V_14 , L_9 ) ;
return - V_29 ;
}
V_6 -> V_21 -> V_30 = F_12 ( V_20 ) ;
F_13 ( & V_20 -> V_14 ) ;
return 0 ;
}
static inline int F_4 ( struct V_5 * V_6 ,
struct V_10 * V_11 )
{
return 0 ;
}
static int F_14 ( struct V_10 * V_11 )
{
struct V_5 * V_6 ;
int (* F_15)( struct V_1 * , void * , T_1 );
int V_17 , V_18 ;
V_6 = F_5 ( & V_11 -> V_14 , sizeof( * V_6 ) , V_22 ) ;
if ( ! V_6 ) {
F_6 ( & V_11 -> V_14 , L_10 ) ;
V_18 = - V_23 ;
goto V_31;
}
F_16 ( V_11 , V_6 ) ;
V_6 -> V_14 = & V_11 -> V_14 ;
V_6 -> V_21 = F_17 ( & V_11 -> V_14 ) ;
if ( ! V_6 -> V_21 ) {
V_18 = F_4 ( V_6 , V_11 ) ;
if ( V_18 < 0 )
goto V_31;
}
if ( ! V_6 -> V_21 ) {
F_6 ( & V_11 -> V_14 , L_11 ) ;
V_18 = - V_28 ;
goto V_31;
}
V_6 -> V_8 = F_5 ( & V_11 -> V_14 ,
sizeof( * V_6 -> V_8 ) * V_6 -> V_21 -> V_25 ,
V_22 ) ;
if ( ! V_6 -> V_8 ) {
F_6 ( & V_11 -> V_14 , L_12 ) ;
V_18 = - V_23 ;
goto V_31;
}
V_6 -> V_32 = F_5 ( & V_11 -> V_14 ,
sizeof( * V_6 -> V_32 ) * V_6 -> V_21 -> V_25 ,
V_22 ) ;
if ( ! V_6 -> V_32 ) {
F_6 ( & V_11 -> V_14 , L_13 ) ;
V_18 = - V_23 ;
goto V_31;
}
V_6 -> V_7 = F_18 ( & V_11 -> V_14 ) ;
if ( F_19 ( V_6 -> V_7 ) ) {
V_18 = F_20 ( V_6 -> V_7 ) ;
F_6 ( & V_11 -> V_14 , L_14 , V_18 ) ;
goto V_31;
}
for ( V_17 = 0 ; V_17 < V_6 -> V_21 -> V_25 ; V_17 ++ ) {
V_6 -> V_8 [ V_17 ] = F_21 ( V_6 -> V_7 ,
V_6 -> V_21 -> V_24 [ V_17 ] ) ;
if ( F_19 ( V_6 -> V_8 [ V_17 ] ) ) {
V_18 = F_20 ( V_6 -> V_8 [ V_17 ] ) ;
F_6 ( & V_11 -> V_14 ,
L_15 ,
V_6 -> V_21 -> V_24 [ V_17 ] , V_18 ) ;
goto V_31;
}
}
if ( V_6 -> V_21 -> V_27 ) {
V_6 -> V_9 = F_21 ( V_6 -> V_7 ,
V_6 -> V_21 -> V_27 ) ;
if ( F_19 ( V_6 -> V_9 ) ) {
V_18 = F_20 ( V_6 -> V_9 ) ;
F_6 ( & V_11 -> V_14 ,
L_15 ,
V_6 -> V_21 -> V_27 , V_18 ) ;
goto V_31;
}
F_15 = F_3 ;
} else {
F_15 = NULL ;
}
V_6 -> V_33 = F_22 ( V_6 -> V_21 -> V_30 ) ;
if ( ! V_6 -> V_33 ) {
F_6 ( & V_11 -> V_14 , L_16 ,
V_6 -> V_21 -> V_30 ) ;
V_18 = - V_29 ;
goto V_31;
}
for ( V_17 = 0 ; V_17 < V_6 -> V_21 -> V_25 ; V_17 ++ ) {
T_1 V_34 = V_6 -> V_21 -> V_35 ?
( V_6 -> V_21 -> V_35 + V_17 ) : 0 ;
V_6 -> V_32 [ V_17 ] = F_23 ( V_6 -> V_33 , & V_11 -> V_14 ,
V_6 , V_34 , V_17 , 0 ,
F_1 ,
F_15 ) ;
if ( ! V_6 -> V_32 [ V_17 ] ) {
V_18 = - V_28 ;
F_6 ( & V_11 -> V_14 , L_17 , V_17 ) ;
goto V_36;
}
}
return 0 ;
V_36:
for (; V_17 > 0 ; V_17 -- )
F_24 ( V_6 -> V_32 [ V_17 - 1 ] ) ;
F_25 ( V_6 -> V_33 ) ;
V_31:
return V_18 ;
}
static int F_26 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = F_27 ( V_11 ) ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_6 -> V_21 -> V_25 ; V_17 ++ )
F_24 ( V_6 -> V_32 [ V_17 ] ) ;
F_25 ( V_6 -> V_33 ) ;
return 0 ;
}
