static struct V_1 * F_1 (
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 , V_11 , V_12 ;
unsigned int V_13 , V_14 , V_15 ;
const T_1 * V_16 ;
struct V_17 * V_18 ;
V_11 = F_2 ( V_5 , L_1 ,
& V_13 ) ;
if ( V_11 ) {
F_3 ( V_3 , L_2 ) ;
return NULL ;
}
V_11 = F_2 ( V_5 , L_3 ,
& V_14 ) ;
if ( V_11 ) {
F_3 ( V_3 , L_4 ) ;
return NULL ;
}
V_15 = sizeof( struct V_1 ) +
sizeof( struct V_7 ) * V_13 +
sizeof( struct V_17 ) * V_13 * V_14 ;
V_6 = F_4 ( V_15 , V_19 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_5 ( V_5 , L_5 ,
& V_6 -> V_20 ) ;
if ( V_11 ) {
F_3 ( V_3 , L_6 ) ;
goto V_21;
}
if ( F_6 ( V_5 , L_7 ) ) {
V_6 -> V_22 = 1 ;
} else {
F_7 ( V_3 , L_8 ) ;
F_7 ( V_3 , L_9 ) ;
}
V_6 -> V_13 = V_13 ;
V_6 -> V_8 = (struct V_7 * ) ( V_6 + 1 ) ;
V_16 = F_8 ( V_5 , L_10 , & V_12 ) ;
if ( V_16 == NULL ) {
F_3 ( V_3 , L_11 ) ;
goto V_21;
}
if ( V_12 != V_13 * V_14 * sizeof( T_1 ) * 4 ) {
F_3 ( V_3 , L_12 ) ;
goto V_21;
}
V_18 = (struct V_17 * ) ( V_6 -> V_8 + V_13 ) ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
V_8 = & V_6 -> V_8 [ V_9 ] ;
V_8 -> V_14 = V_14 ;
V_8 -> V_18 = & V_18 [ V_9 ] ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ ) {
int V_23 = ( ( V_9 * V_14 ) + V_10 ) * 4 ;
V_8 -> V_18 [ V_10 ] . V_24 = F_9 ( V_16 [ V_23 ] ) ;
V_8 -> V_18 [ V_10 ] . V_25 =
F_9 ( V_16 [ V_23 + 1 ] ) ;
V_8 -> V_18 [ V_10 ] . V_26 = ( V_27 )
F_10 ( F_9 ( V_16 [ V_23 + 2 ] ) ) ;
V_8 -> V_18 [ V_10 ] . V_28 = ( V_27 )
F_10 ( F_9 ( V_16 [ V_23 + 3 ] ) ) ;
}
}
return V_6 ;
V_21:
F_11 ( V_6 ) ;
return NULL ;
}
static int F_12 ( void * V_29 ,
T_1 V_30 )
{
int V_31 , V_9 ;
struct V_32 * V_33 = (struct V_32 * ) V_29 ;
int V_34 = 0 ;
struct V_7 * V_8 ;
T_1 V_35 ;
T_1 V_36 = ~ 0 ;
for ( V_9 = 0 ; V_9 < V_33 -> V_6 -> V_13 ; V_9 ++ ) {
V_8 = & V_33 -> V_6 -> V_8 [ V_9 ] ;
V_35 = F_13 ( V_8 -> V_18 [ 0 ] . V_28 , 1000 ) ;
if ( V_35 >= V_30 && V_35 < V_36 ) {
V_36 = V_35 ;
V_34 = V_9 ;
}
}
V_31 = F_14 ( V_33 -> V_37 , V_34 ) ;
if ( V_31 )
F_3 ( V_33 -> V_3 , L_13 ,
V_30 , V_34 , V_31 ) ;
else
F_7 ( V_33 -> V_3 , L_14 ,
V_30 , V_34 ) ;
return V_31 ;
}
static void F_15 ( void * V_29 )
{
struct V_32 * V_33 = (struct V_32 * ) V_29 ;
F_7 ( V_33 -> V_3 , L_15 ) ;
if ( V_33 -> V_37 )
F_16 ( V_33 -> V_37 ) ;
F_11 ( V_33 -> V_6 ) ;
F_11 ( V_33 ) ;
}
static int F_17 ( struct V_32 * V_33 ,
struct V_4 * V_38 )
{
V_33 -> V_6 = F_1 ( V_33 -> V_3 , V_38 ) ;
if ( ! V_33 -> V_6 ) {
F_3 ( V_33 -> V_3 , L_16 ) ;
return - V_39 ;
}
V_33 -> V_37 = F_18 ( V_33 -> V_6 ) ;
if ( ! V_33 -> V_37 ) {
F_3 ( V_33 -> V_3 , L_17 ) ;
return - V_39 ;
}
F_7 ( V_33 -> V_3 , L_18 ,
V_33 -> V_37 ) ;
return 0 ;
}
void * F_19 ( struct V_2 * V_3 , struct V_40 * V_41 )
{
struct V_4 * V_5 ;
struct V_32 * V_33 ;
int V_31 ;
V_5 = F_20 ( NULL , NULL , L_19 ) ;
if ( ! V_5 ) {
F_3 ( V_3 , L_20 ) ;
return NULL ;
}
V_33 = F_4 ( sizeof( * V_33 ) , V_19 ) ;
if ( ! V_33 )
return NULL ;
V_33 -> V_3 = V_3 ;
V_31 = F_17 ( V_33 , V_5 ) ;
if ( V_31 )
goto V_42;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_43 = F_12 ;
V_41 -> V_44 = F_15 ;
return ( void * ) V_33 ;
V_42:
F_11 ( V_33 ) ;
return NULL ;
}
