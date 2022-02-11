static struct V_1 * F_1 ( T_1 V_2 )
{
T_2 V_3 = sizeof( struct V_1 ) +
sizeof( struct V_4 * ) * V_2 ;
struct V_1 * V_5 = F_2 ( V_3 , V_6 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_2 = V_2 ;
F_3 ( V_5 -> V_7 , NULL ) ;
return V_5 ;
}
int F_4 ( struct V_4 * V_8 )
{
struct V_1 * V_5 ;
F_5 ( & V_9 ) ;
F_6 ( F_7 ( V_8 -> V_10 ,
F_8 ( & V_9 ) ) ,
L_1 ) ;
V_5 = F_1 ( V_11 ) ;
if ( ! V_5 ) {
F_9 ( & V_9 ) ;
return - V_12 ;
}
V_5 -> V_13 [ 0 ] = V_8 ;
V_5 -> V_14 = 1 ;
F_10 ( V_8 -> V_10 , V_5 ) ;
F_9 ( & V_9 ) ;
return 0 ;
}
static struct V_1 * F_11 ( struct V_1 * V_5 )
{
struct V_1 * V_15 ;
T_3 V_16 , V_17 ;
V_16 = V_5 -> V_2 * 2U ;
if ( V_16 > V_18 )
return NULL ;
V_15 = F_1 ( V_16 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_2 = V_16 ;
V_15 -> V_14 = V_5 -> V_14 ;
V_15 -> V_7 = V_5 -> V_7 ;
memcpy ( V_15 -> V_13 , V_5 -> V_13 ,
V_5 -> V_14 * sizeof( struct V_4 * ) ) ;
for ( V_17 = 0 ; V_17 < V_5 -> V_14 ; ++ V_17 )
F_10 ( V_5 -> V_13 [ V_17 ] -> V_10 ,
V_15 ) ;
F_12 ( V_5 , V_19 ) ;
return V_15 ;
}
int F_13 ( struct V_4 * V_8 , struct V_4 * V_20 )
{
struct V_1 * V_5 ;
if ( ! F_14 ( V_20 -> V_10 ) ) {
int V_21 = F_4 ( V_20 ) ;
if ( V_21 )
return V_21 ;
}
F_5 ( & V_9 ) ;
V_5 = F_7 ( V_20 -> V_10 ,
F_8 ( & V_9 ) ) ,
F_6 ( F_7 ( V_8 -> V_10 ,
F_8 ( & V_9 ) ) ,
L_2 ) ;
if ( V_5 -> V_14 == V_5 -> V_2 ) {
V_5 = F_11 ( V_5 ) ;
if ( ! V_5 ) {
F_9 ( & V_9 ) ;
return - V_12 ;
}
}
V_5 -> V_13 [ V_5 -> V_14 ] = V_8 ;
F_15 () ;
V_5 -> V_14 ++ ;
F_10 ( V_8 -> V_10 , V_5 ) ;
F_9 ( & V_9 ) ;
return 0 ;
}
static void F_16 ( struct V_22 * V_23 )
{
struct V_1 * V_5 ;
V_5 = F_17 ( V_23 , struct V_1 , V_19 ) ;
if ( V_5 -> V_7 )
F_18 ( V_5 -> V_7 ) ;
F_19 ( V_5 ) ;
}
void F_20 ( struct V_4 * V_8 )
{
struct V_1 * V_5 ;
int V_17 ;
F_5 ( & V_9 ) ;
V_5 = F_7 ( V_8 -> V_10 ,
F_8 ( & V_9 ) ) ;
F_10 ( V_8 -> V_10 , NULL ) ;
for ( V_17 = 0 ; V_17 < V_5 -> V_14 ; V_17 ++ ) {
if ( V_5 -> V_13 [ V_17 ] == V_8 ) {
V_5 -> V_13 [ V_17 ] = V_5 -> V_13 [ V_5 -> V_14 - 1 ] ;
V_5 -> V_14 -- ;
if ( V_5 -> V_14 == 0 )
F_21 ( & V_5 -> V_19 , F_16 ) ;
break;
}
}
F_9 ( & V_9 ) ;
}
static struct V_4 * F_22 ( struct V_1 * V_5 , T_1 V_13 ,
struct V_24 * V_7 , struct V_25 * V_26 ,
int V_27 )
{
struct V_25 * V_28 = NULL ;
T_3 V_29 ;
if ( F_23 ( V_26 ) ) {
V_28 = F_24 ( V_26 , V_6 ) ;
if ( ! V_28 )
return NULL ;
V_26 = V_28 ;
}
if ( ! F_25 ( V_26 , V_27 ) ) {
F_26 ( V_28 ) ;
return NULL ;
}
V_29 = F_27 ( V_7 , V_26 ) ;
F_28 ( V_26 , V_27 ) ;
F_29 ( V_28 ) ;
if ( V_29 >= V_13 )
return NULL ;
return V_5 -> V_13 [ V_29 ] ;
}
struct V_4 * F_30 ( struct V_4 * V_8 ,
T_3 V_30 ,
struct V_25 * V_26 ,
int V_27 )
{
struct V_1 * V_5 ;
struct V_24 * V_7 ;
struct V_4 * V_20 = NULL ;
T_1 V_13 ;
F_31 () ;
V_5 = F_32 ( V_8 -> V_10 ) ;
if ( ! V_5 )
goto V_31;
V_7 = F_32 ( V_5 -> V_7 ) ;
V_13 = F_33 ( V_5 -> V_14 ) ;
if ( F_34 ( V_13 ) ) {
F_35 () ;
if ( V_7 && V_26 )
V_20 = F_22 ( V_5 , V_13 , V_7 , V_26 , V_27 ) ;
else
V_20 = V_5 -> V_13 [ F_36 ( V_30 , V_13 ) ] ;
}
V_31:
F_37 () ;
return V_20 ;
}
struct V_24 *
F_38 ( struct V_4 * V_8 , struct V_24 * V_7 )
{
struct V_1 * V_5 ;
struct V_24 * V_32 ;
F_5 ( & V_9 ) ;
V_5 = F_7 ( V_8 -> V_10 ,
F_8 ( & V_9 ) ) ;
V_32 = F_7 ( V_5 -> V_7 ,
F_8 ( & V_9 ) ) ;
F_10 ( V_5 -> V_7 , V_7 ) ;
F_9 ( & V_9 ) ;
return V_32 ;
}
