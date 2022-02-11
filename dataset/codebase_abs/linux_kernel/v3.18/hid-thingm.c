static int F_1 ( struct V_1 * V_2 , T_1 V_3 [ V_4 ] )
{
int V_5 ;
F_2 ( V_2 -> V_6 , L_1 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] , V_3 [ 4 ] ,
V_3 [ 5 ] , V_3 [ 6 ] , V_3 [ 7 ] , V_3 [ 8 ] ) ;
V_5 = F_3 ( V_2 -> V_6 , V_3 [ 0 ] , V_3 , V_4 ,
V_7 , V_8 ) ;
return V_5 < 0 ? V_5 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 [ V_4 ] )
{
int V_5 ;
V_5 = F_3 ( V_2 -> V_6 , V_3 [ 0 ] , V_3 , V_4 ,
V_7 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
F_2 ( V_2 -> V_6 , L_2 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] , V_3 [ 4 ] ,
V_3 [ 5 ] , V_3 [ 6 ] , V_3 [ 7 ] , V_3 [ 8 ] ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_3 [ V_4 ] = { V_10 , 'v' , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_11 ;
V_11 = F_1 ( V_2 , V_3 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_4 ( V_2 , V_3 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_12 . V_13 = V_3 [ 3 ] ;
V_2 -> V_12 . V_14 = V_3 [ 4 ] ;
return 0 ;
}
static int F_6 ( struct V_15 * V_16 )
{
T_1 V_3 [ V_4 ] = { V_10 , 'c' , 0 , 0 , 0 , 0 , 0 , V_16 -> V_17 , 0 } ;
V_3 [ 2 ] = V_16 -> V_18 . V_19 . V_20 ;
V_3 [ 3 ] = V_16 -> V_21 . V_19 . V_20 ;
V_3 [ 4 ] = V_16 -> V_22 . V_19 . V_20 ;
return F_1 ( V_16 -> V_2 , V_3 ) ;
}
static void F_7 ( struct V_23 * V_24 )
{
struct V_15 * V_16 = F_8 ( V_24 , struct V_15 , V_24 ) ;
F_9 ( & V_16 -> V_2 -> V_25 ) ;
if ( F_6 ( V_16 ) )
F_10 ( V_16 -> V_2 -> V_6 , L_3 ) ;
F_11 ( & V_16 -> V_2 -> V_25 ) ;
}
static void F_12 ( struct V_26 * V_19 ,
enum V_27 V_20 )
{
struct V_28 * V_29 = F_8 ( V_19 , struct V_28 , V_19 ) ;
F_13 ( & V_29 -> V_16 -> V_24 ) ;
}
static int F_14 ( struct V_15 * V_16 )
{
const int V_14 = ( (struct V_30 * ) V_16 -> V_2 -> V_6 -> V_30 ) -> V_14 ;
int V_11 ;
snprintf ( V_16 -> V_18 . V_31 , sizeof( V_16 -> V_18 . V_31 ) ,
L_4 , V_14 , V_16 -> V_17 ) ;
V_16 -> V_18 . V_19 . V_31 = V_16 -> V_18 . V_31 ;
V_16 -> V_18 . V_19 . V_32 = 255 ;
V_16 -> V_18 . V_19 . V_33 = F_12 ;
V_16 -> V_18 . V_16 = V_16 ;
V_11 = F_15 ( & V_16 -> V_2 -> V_6 -> V_34 , & V_16 -> V_18 . V_19 ) ;
if ( V_11 )
return V_11 ;
snprintf ( V_16 -> V_21 . V_31 , sizeof( V_16 -> V_21 . V_31 ) ,
L_5 , V_14 , V_16 -> V_17 ) ;
V_16 -> V_21 . V_19 . V_31 = V_16 -> V_21 . V_31 ;
V_16 -> V_21 . V_19 . V_32 = 255 ;
V_16 -> V_21 . V_19 . V_33 = F_12 ;
V_16 -> V_21 . V_16 = V_16 ;
V_11 = F_15 ( & V_16 -> V_2 -> V_6 -> V_34 , & V_16 -> V_21 . V_19 ) ;
if ( V_11 )
goto V_35;
snprintf ( V_16 -> V_22 . V_31 , sizeof( V_16 -> V_22 . V_31 ) ,
L_6 , V_14 , V_16 -> V_17 ) ;
V_16 -> V_22 . V_19 . V_31 = V_16 -> V_22 . V_31 ;
V_16 -> V_22 . V_19 . V_32 = 255 ;
V_16 -> V_22 . V_19 . V_33 = F_12 ;
V_16 -> V_22 . V_16 = V_16 ;
V_11 = F_15 ( & V_16 -> V_2 -> V_6 -> V_34 , & V_16 -> V_22 . V_19 ) ;
if ( V_11 )
goto V_36;
F_16 ( & V_16 -> V_24 , F_7 ) ;
return 0 ;
V_36:
F_17 ( & V_16 -> V_21 . V_19 ) ;
V_35:
F_17 ( & V_16 -> V_18 . V_19 ) ;
return V_11 ;
}
static void F_18 ( struct V_15 * V_16 )
{
F_17 ( & V_16 -> V_18 . V_19 ) ;
F_17 ( & V_16 -> V_21 . V_19 ) ;
F_17 ( & V_16 -> V_22 . V_19 ) ;
F_19 ( & V_16 -> V_24 ) ;
}
static int F_20 ( struct V_37 * V_6 , const struct V_38 * V_39 )
{
struct V_1 * V_2 ;
int V_40 , V_11 ;
V_2 = F_21 ( & V_6 -> V_34 , sizeof( struct V_1 ) ,
V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_2 -> V_6 = V_6 ;
F_22 ( V_6 , V_2 ) ;
V_11 = F_23 ( V_6 ) ;
if ( V_11 )
goto error;
V_11 = F_24 ( V_6 , V_43 ) ;
if ( V_11 )
goto error;
F_25 ( & V_2 -> V_25 ) ;
V_11 = F_5 ( V_2 ) ;
if ( V_11 )
goto V_44;
F_2 ( V_6 , L_7 ,
V_2 -> V_12 . V_13 , V_2 -> V_12 . V_14 ) ;
for ( V_40 = 0 ; V_40 < F_26 ( V_45 ) && ! V_2 -> V_46 ; ++ V_40 )
if ( V_45 [ V_40 ] . V_13 == V_2 -> V_12 . V_13 )
V_2 -> V_46 = & V_45 [ V_40 ] ;
if ( ! V_2 -> V_46 ) {
F_10 ( V_6 , L_8 , V_2 -> V_12 . V_13 ) ;
V_11 = - V_47 ;
goto V_44;
}
V_2 -> V_16 = F_21 ( & V_6 -> V_34 ,
sizeof( struct V_15 ) * V_2 -> V_46 -> V_48 ,
V_41 ) ;
if ( ! V_2 -> V_16 ) {
V_11 = - V_42 ;
goto V_44;
}
for ( V_40 = 0 ; V_40 < V_2 -> V_46 -> V_48 ; ++ V_40 ) {
struct V_15 * V_16 = V_2 -> V_16 + V_40 ;
V_16 -> V_2 = V_2 ;
V_16 -> V_17 = V_2 -> V_46 -> V_49 + V_40 ;
V_11 = F_14 ( V_16 ) ;
if ( V_11 ) {
while ( -- V_40 >= 0 )
F_18 ( V_2 -> V_16 + V_40 ) ;
goto V_44;
}
}
return 0 ;
V_44:
F_27 ( V_6 ) ;
error:
return V_11 ;
}
static void F_28 ( struct V_37 * V_6 )
{
struct V_1 * V_2 = F_29 ( V_6 ) ;
int V_40 ;
F_27 ( V_6 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_46 -> V_48 ; ++ V_40 )
F_18 ( V_2 -> V_16 + V_40 ) ;
}
