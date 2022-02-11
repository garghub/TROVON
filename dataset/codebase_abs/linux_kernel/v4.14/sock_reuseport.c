static struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 = sizeof( struct V_1 ) +
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
if ( F_6 ( V_8 -> V_10 ,
F_7 ( & V_9 ) ) )
goto V_11;
V_5 = F_1 ( V_12 ) ;
if ( ! V_5 ) {
F_8 ( & V_9 ) ;
return - V_13 ;
}
V_5 -> V_14 [ 0 ] = V_8 ;
V_5 -> V_15 = 1 ;
F_9 ( V_8 -> V_10 , V_5 ) ;
V_11:
F_8 ( & V_9 ) ;
return 0 ;
}
static struct V_1 * F_10 ( struct V_1 * V_5 )
{
struct V_1 * V_16 ;
T_1 V_17 , V_18 ;
V_17 = V_5 -> V_2 * 2U ;
if ( V_17 > V_19 )
return NULL ;
V_16 = F_1 ( V_17 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_2 = V_17 ;
V_16 -> V_15 = V_5 -> V_15 ;
V_16 -> V_7 = V_5 -> V_7 ;
memcpy ( V_16 -> V_14 , V_5 -> V_14 ,
V_5 -> V_15 * sizeof( struct V_4 * ) ) ;
for ( V_18 = 0 ; V_18 < V_5 -> V_15 ; ++ V_18 )
F_9 ( V_5 -> V_14 [ V_18 ] -> V_10 ,
V_16 ) ;
F_11 ( V_5 , V_20 ) ;
return V_16 ;
}
int F_12 ( struct V_4 * V_8 , struct V_4 * V_21 )
{
struct V_1 * V_5 ;
if ( ! F_13 ( V_21 -> V_10 ) ) {
int V_22 = F_4 ( V_21 ) ;
if ( V_22 )
return V_22 ;
}
F_5 ( & V_9 ) ;
V_5 = F_6 ( V_21 -> V_10 ,
F_7 ( & V_9 ) ) ,
F_14 ( F_6 ( V_8 -> V_10 ,
F_7 ( & V_9 ) ) ,
L_1 ) ;
if ( V_5 -> V_15 == V_5 -> V_2 ) {
V_5 = F_10 ( V_5 ) ;
if ( ! V_5 ) {
F_8 ( & V_9 ) ;
return - V_13 ;
}
}
V_5 -> V_14 [ V_5 -> V_15 ] = V_8 ;
F_15 () ;
V_5 -> V_15 ++ ;
F_9 ( V_8 -> V_10 , V_5 ) ;
F_8 ( & V_9 ) ;
return 0 ;
}
static void F_16 ( struct V_23 * V_24 )
{
struct V_1 * V_5 ;
V_5 = F_17 ( V_24 , struct V_1 , V_20 ) ;
if ( V_5 -> V_7 )
F_18 ( V_5 -> V_7 ) ;
F_19 ( V_5 ) ;
}
void F_20 ( struct V_4 * V_8 )
{
struct V_1 * V_5 ;
int V_18 ;
F_5 ( & V_9 ) ;
V_5 = F_6 ( V_8 -> V_10 ,
F_7 ( & V_9 ) ) ;
F_9 ( V_8 -> V_10 , NULL ) ;
for ( V_18 = 0 ; V_18 < V_5 -> V_15 ; V_18 ++ ) {
if ( V_5 -> V_14 [ V_18 ] == V_8 ) {
V_5 -> V_14 [ V_18 ] = V_5 -> V_14 [ V_5 -> V_15 - 1 ] ;
V_5 -> V_15 -- ;
if ( V_5 -> V_15 == 0 )
F_21 ( & V_5 -> V_20 , F_16 ) ;
break;
}
}
F_8 ( & V_9 ) ;
}
static struct V_4 * F_22 ( struct V_1 * V_5 , T_2 V_14 ,
struct V_25 * V_7 , struct V_26 * V_27 ,
int V_28 )
{
struct V_26 * V_29 = NULL ;
T_1 V_30 ;
if ( F_23 ( V_27 ) ) {
V_29 = F_24 ( V_27 , V_6 ) ;
if ( ! V_29 )
return NULL ;
V_27 = V_29 ;
}
if ( ! F_25 ( V_27 , V_28 ) ) {
F_26 ( V_29 ) ;
return NULL ;
}
V_30 = F_27 ( V_7 , V_27 ) ;
F_28 ( V_27 , V_28 ) ;
F_29 ( V_29 ) ;
if ( V_30 >= V_14 )
return NULL ;
return V_5 -> V_14 [ V_30 ] ;
}
struct V_4 * F_30 ( struct V_4 * V_8 ,
T_1 V_31 ,
struct V_26 * V_27 ,
int V_28 )
{
struct V_1 * V_5 ;
struct V_25 * V_7 ;
struct V_4 * V_21 = NULL ;
T_2 V_14 ;
F_31 () ;
V_5 = F_32 ( V_8 -> V_10 ) ;
if ( ! V_5 )
goto V_11;
V_7 = F_32 ( V_5 -> V_7 ) ;
V_14 = F_33 ( V_5 -> V_15 ) ;
if ( F_34 ( V_14 ) ) {
F_35 () ;
if ( V_7 && V_27 )
V_21 = F_22 ( V_5 , V_14 , V_7 , V_27 , V_28 ) ;
else
V_21 = V_5 -> V_14 [ F_36 ( V_31 , V_14 ) ] ;
}
V_11:
F_37 () ;
return V_21 ;
}
struct V_25 *
F_38 ( struct V_4 * V_8 , struct V_25 * V_7 )
{
struct V_1 * V_5 ;
struct V_25 * V_32 ;
F_5 ( & V_9 ) ;
V_5 = F_6 ( V_8 -> V_10 ,
F_7 ( & V_9 ) ) ;
V_32 = F_6 ( V_5 -> V_7 ,
F_7 ( & V_9 ) ) ;
F_9 ( V_5 -> V_7 , V_7 ) ;
F_8 ( & V_9 ) ;
return V_32 ;
}
