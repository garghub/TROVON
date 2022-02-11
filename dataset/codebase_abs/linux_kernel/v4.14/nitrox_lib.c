static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 ;
V_5 = ( V_4 -> V_6 ) * V_2 -> V_7 ;
V_2 -> V_8 = F_2 ( F_3 ( V_4 ) ,
( V_5 + V_9 ) ,
& V_2 -> V_10 ,
V_11 ) ;
if ( ! V_2 -> V_8 )
return - V_12 ;
V_2 -> V_13 = F_4 ( V_2 -> V_8 , V_9 ) ;
V_2 -> V_14 = F_4 ( V_2 -> V_10 , V_9 ) ;
V_2 -> V_5 = ( V_5 + V_9 ) ;
F_5 ( & V_2 -> V_15 ) ;
F_5 ( & V_2 -> V_16 ) ;
F_5 ( & V_2 -> V_17 ) ;
F_6 ( & V_2 -> V_18 ) ;
F_6 ( & V_2 -> V_19 ) ;
F_7 ( & V_2 -> V_20 , V_21 ) ;
F_8 ( & V_2 -> V_22 , 0 ) ;
F_8 ( & V_2 -> V_23 , 0 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_10 ( & V_2 -> V_20 ) ;
F_11 ( F_3 ( V_4 ) , V_2 -> V_5 ,
V_2 -> V_8 , V_2 -> V_10 ) ;
F_8 ( & V_2 -> V_22 , 0 ) ;
F_8 ( & V_2 -> V_23 , 0 ) ;
V_2 -> V_24 = NULL ;
V_2 -> V_13 = NULL ;
V_2 -> V_14 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_7 = 0 ;
}
static void F_12 ( struct V_3 * V_4 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_4 -> V_26 ; V_25 ++ ) {
struct V_1 * V_2 = & V_4 -> V_27 [ V_25 ] ;
F_9 ( V_2 ) ;
}
F_13 ( V_4 -> V_27 ) ;
V_4 -> V_27 = NULL ;
}
static int F_14 ( struct V_3 * V_4 )
{
int V_25 , V_28 , V_29 ;
V_29 = V_4 -> V_26 * sizeof( struct V_1 ) ;
V_4 -> V_27 = F_15 ( V_29 , V_11 ) ;
if ( ! V_4 -> V_27 )
return - V_12 ;
for ( V_25 = 0 ; V_25 < V_4 -> V_26 ; V_25 ++ ) {
struct V_1 * V_2 ;
T_2 V_30 ;
V_2 = & V_4 -> V_27 [ V_25 ] ;
V_2 -> V_4 = V_4 ;
V_2 -> V_31 = V_25 ;
V_2 -> V_7 = sizeof( struct V_32 ) ;
V_30 = F_16 ( V_25 ) ;
V_2 -> V_24 = F_17 ( V_4 , V_30 ) ;
V_28 = F_1 ( V_2 ) ;
if ( V_28 )
goto V_33;
}
return 0 ;
V_33:
F_12 ( V_4 ) ;
return V_28 ;
}
static int F_18 ( struct V_3 * V_4 )
{
T_3 V_29 ;
V_29 = V_34 + sizeof( struct V_35 ) ;
V_4 -> V_36 = F_19 ( L_1 ,
F_3 ( V_4 ) , V_29 , 16 , 0 ) ;
if ( ! V_4 -> V_36 )
return - V_12 ;
return 0 ;
}
static void F_20 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_36 )
return;
F_21 ( V_4 -> V_36 ) ;
V_4 -> V_36 = NULL ;
}
void * F_22 ( struct V_3 * V_4 )
{
struct V_35 * V_37 ;
void * V_38 ;
T_4 V_14 ;
V_38 = F_23 ( V_4 -> V_36 , ( V_39 | V_40 ) , & V_14 ) ;
if ( ! V_38 )
return NULL ;
V_37 = V_38 ;
V_37 -> V_41 = V_4 -> V_36 ;
V_37 -> V_14 = V_14 ;
V_37 -> V_42 = V_14 + sizeof( struct V_35 ) ;
return ( ( V_43 * ) V_38 + sizeof( struct V_35 ) ) ;
}
void F_24 ( void * V_37 )
{
struct V_35 * V_44 ;
if ( ! V_37 )
return;
V_44 = (struct V_35 * ) ( ( V_43 * ) V_37 - sizeof( struct V_35 ) ) ;
F_25 ( V_44 -> V_41 , V_44 , V_44 -> V_14 ) ;
}
int F_26 ( struct V_3 * V_4 )
{
int V_28 = 0 ;
V_28 = F_18 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_14 ( V_4 ) ;
if ( V_28 )
F_20 ( V_4 ) ;
return V_28 ;
}
void F_27 ( struct V_3 * V_4 )
{
F_12 ( V_4 ) ;
F_20 ( V_4 ) ;
}
