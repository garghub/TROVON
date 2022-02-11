static unsigned int F_1 ( const T_1 * V_1 , unsigned int V_2 )
{
if ( V_1 [ V_2 ] <= V_3 || V_1 [ V_2 + 1 ] == 0 )
return 1 ;
else
return V_1 [ V_2 + 1 ] ;
}
static void F_2 ( const struct V_4 * V_5 ,
struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_5 ) ;
T_2 * V_12 = & V_7 -> V_13 [ V_11 -> V_14 ] ;
unsigned int V_2 = 0 ;
int V_15 ;
V_15 = F_4 ( V_9 -> V_16 , & V_2 , V_11 -> type , NULL , NULL ) ;
if ( V_11 -> V_17 & V_18 ) {
* V_12 = ( V_15 >= 0 ) ;
return;
} else if ( V_15 < 0 ) {
goto V_15;
}
V_2 += V_11 -> V_2 ;
V_12 [ V_11 -> V_19 / V_20 ] = 0 ;
if ( F_5 ( V_9 -> V_16 , V_2 , V_12 , V_11 -> V_19 ) < 0 )
goto V_15;
return;
V_15:
V_7 -> V_21 . V_22 = V_23 ;
}
static void F_6 ( const struct V_4 * V_5 ,
struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
T_1 V_24 [ sizeof( struct V_25 ) + V_26 ] ;
struct V_10 * V_11 = F_3 ( V_5 ) ;
unsigned int V_27 , V_28 , V_29 , V_2 ;
T_2 * V_12 = & V_7 -> V_13 [ V_11 -> V_14 ] ;
struct V_25 * V_30 ;
T_1 * V_1 ;
if ( ! V_9 -> V_31 || V_9 -> V_32 != V_33 )
goto V_15;
V_30 = F_7 ( V_9 -> V_16 , V_9 -> V_34 . V_35 , sizeof( * V_30 ) , V_24 ) ;
if ( ! V_30 )
goto V_15;
V_29 = F_8 ( V_30 ) ;
if ( V_29 < sizeof( * V_30 ) )
goto V_15;
V_30 = F_7 ( V_9 -> V_16 , V_9 -> V_34 . V_35 , V_29 , V_24 ) ;
if ( ! V_30 )
goto V_15;
V_1 = ( T_1 * ) V_30 ;
for ( V_27 = sizeof( * V_30 ) ; V_27 < V_29 - 1 ; V_27 += V_28 ) {
V_28 = F_1 ( V_1 , V_27 ) ;
if ( V_11 -> type != V_1 [ V_27 ] )
continue;
if ( V_27 + V_28 > V_29 || V_11 -> V_19 + V_11 -> V_2 > V_28 )
goto V_15;
V_2 = V_27 + V_11 -> V_2 ;
if ( V_11 -> V_17 & V_18 ) {
* V_12 = 1 ;
} else {
V_12 [ V_11 -> V_19 / V_20 ] = 0 ;
memcpy ( V_12 , V_1 + V_2 , V_11 -> V_19 ) ;
}
return;
}
V_15:
if ( V_11 -> V_17 & V_18 )
* V_12 = 0 ;
else
V_7 -> V_21 . V_22 = V_23 ;
}
static int F_9 ( const struct V_36 * V_37 ,
const struct V_4 * V_5 ,
const struct V_38 * const V_39 [] )
{
struct V_10 * V_11 = F_3 ( V_5 ) ;
T_2 V_2 , V_19 , V_17 = 0 , V_40 = V_41 ;
int V_15 ;
if ( ! V_39 [ V_42 ] ||
! V_39 [ V_43 ] ||
! V_39 [ V_44 ] ||
! V_39 [ V_45 ] )
return - V_46 ;
V_15 = F_10 ( V_39 [ V_44 ] , V_47 , & V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_10 ( V_39 [ V_45 ] , V_47 , & V_19 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_39 [ V_48 ] ) {
V_15 = F_10 ( V_39 [ V_48 ] , V_47 , & V_17 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_17 & ~ V_18 )
return - V_46 ;
}
if ( V_39 [ V_49 ] ) {
V_15 = F_10 ( V_39 [ V_49 ] , V_47 , & V_40 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_11 -> type = F_11 ( V_39 [ V_43 ] ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_14 = F_12 ( V_39 [ V_42 ] ) ;
V_11 -> V_17 = V_17 ;
V_11 -> V_40 = V_40 ;
return F_13 ( V_37 , V_11 -> V_14 , NULL ,
V_50 , V_11 -> V_19 ) ;
}
static int F_14 ( struct V_51 * V_16 , const struct V_4 * V_5 )
{
const struct V_10 * V_11 = F_3 ( V_5 ) ;
if ( F_15 ( V_16 , V_42 , V_11 -> V_14 ) )
goto V_52;
if ( F_16 ( V_16 , V_43 , V_11 -> type ) )
goto V_52;
if ( F_17 ( V_16 , V_44 , F_18 ( V_11 -> V_2 ) ) )
goto V_52;
if ( F_17 ( V_16 , V_45 , F_18 ( V_11 -> V_19 ) ) )
goto V_52;
if ( F_17 ( V_16 , V_48 , F_18 ( V_11 -> V_17 ) ) )
goto V_52;
if ( F_17 ( V_16 , V_49 , F_18 ( V_11 -> V_40 ) ) )
goto V_52;
return 0 ;
V_52:
return - 1 ;
}
static const struct V_53 *
F_19 ( const struct V_36 * V_37 ,
const struct V_38 * const V_39 [] )
{
T_2 V_40 ;
if ( ! V_39 [ V_49 ] )
return & V_54 ;
V_40 = F_20 ( F_21 ( V_39 [ V_49 ] ) ) ;
switch ( V_40 ) {
case V_55 :
return & V_56 ;
case V_41 :
return & V_54 ;
}
return F_22 ( - V_57 ) ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_58 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_58 ) ;
}
