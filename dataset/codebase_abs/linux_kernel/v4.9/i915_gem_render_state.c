static const struct V_1 *
F_1 ( const struct V_2 * V_3 )
{
switch ( F_2 ( V_3 -> V_4 ) ) {
case 6 :
return & V_5 ;
case 7 :
return & V_6 ;
case 8 :
return & V_7 ;
case 9 :
return & V_8 ;
}
return NULL ;
}
static int F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 -> V_14 -> V_12 ;
const struct V_1 * V_15 = V_10 -> V_15 ;
const bool V_16 = F_2 ( V_12 ) >= 8 ;
unsigned int V_17 = 0 , V_18 = 0 ;
struct V_19 * V_19 ;
T_1 * V_20 ;
int V_21 ;
V_21 = F_4 ( V_10 -> V_13 -> V_22 , true ) ;
if ( V_21 )
return V_21 ;
V_19 = F_5 ( V_10 -> V_13 -> V_22 , 0 ) ;
V_20 = F_6 ( V_19 ) ;
while ( V_17 < V_15 -> V_23 ) {
T_1 V_24 = V_15 -> V_25 [ V_17 ] ;
if ( V_17 * 4 == V_15 -> V_26 [ V_18 ] ) {
T_2 V_27 = V_24 + V_10 -> V_13 -> V_28 . V_29 ;
V_24 = F_7 ( V_27 ) ;
if ( V_16 ) {
if ( V_17 + 1 >= V_15 -> V_23 ||
V_15 -> V_25 [ V_17 + 1 ] != 0 ) {
V_21 = - V_30 ;
goto V_31;
}
V_20 [ V_17 ++ ] = V_24 ;
V_24 = F_8 ( V_27 ) ;
}
V_18 ++ ;
}
V_20 [ V_17 ++ ] = V_24 ;
}
while ( V_17 % V_32 )
F_9 ( V_20 , V_17 , V_33 ) ;
V_10 -> V_34 = V_17 * sizeof( T_1 ) ;
if ( F_10 ( V_12 ) ) {
T_1 V_35 = 0x00777000 ;
F_9 ( V_20 , V_17 , V_36 ) ;
F_9 ( V_20 , V_17 , V_37 ) ;
F_9 ( V_20 , V_17 , V_35 ) ;
F_9 ( V_20 , V_17 , 0 ) ;
F_9 ( V_20 , V_17 , 0 ) ;
F_9 ( V_20 , V_17 , 0 ) ;
}
F_9 ( V_20 , V_17 , V_38 ) ;
V_10 -> V_39 = ( V_17 * sizeof( T_1 ) ) - V_10 -> V_34 ;
V_10 -> V_39 = F_11 ( V_10 -> V_39 , 8 ) ;
F_12 ( V_19 ) ;
V_21 = F_13 ( V_10 -> V_13 -> V_22 , false ) ;
if ( V_21 )
return V_21 ;
if ( V_15 -> V_26 [ V_18 ] != - 1 ) {
F_14 ( L_1 , V_18 ) ;
return - V_30 ;
}
return 0 ;
V_31:
F_12 ( V_19 ) ;
return V_21 ;
}
int F_15 ( struct V_2 * V_3 )
{
struct V_9 V_10 ;
struct V_40 * V_22 ;
int V_21 ;
if ( F_16 ( V_3 -> V_41 -> V_42 != V_43 ) )
return - V_44 ;
V_10 . V_15 = F_1 ( V_3 ) ;
if ( ! V_10 . V_15 )
return 0 ;
if ( V_10 . V_15 -> V_23 * 4 > 4096 )
return - V_30 ;
V_22 = F_17 ( & V_3 -> V_4 -> V_45 , 4096 ) ;
if ( F_18 ( V_22 ) )
return F_19 ( V_22 ) ;
V_10 . V_13 = F_20 ( V_22 , & V_3 -> V_4 -> V_46 . V_47 , NULL ) ;
if ( F_18 ( V_10 . V_13 ) ) {
V_21 = F_19 ( V_10 . V_13 ) ;
goto V_48;
}
V_21 = F_21 ( V_10 . V_13 , 0 , 0 , V_49 ) ;
if ( V_21 )
goto V_48;
V_21 = F_3 ( & V_10 ) ;
if ( V_21 )
goto V_50;
V_21 = V_3 -> V_41 -> V_51 ( V_3 , V_10 . V_13 -> V_28 . V_29 ,
V_10 . V_15 -> V_23 * 4 ,
V_52 ) ;
if ( V_21 )
goto V_50;
if ( V_10 . V_39 > 8 ) {
V_21 = V_3 -> V_41 -> V_51 ( V_3 ,
( V_10 . V_13 -> V_28 . V_29 +
V_10 . V_34 ) ,
V_10 . V_39 ,
V_52 ) ;
if ( V_21 )
goto V_50;
}
F_22 ( V_10 . V_13 , V_3 , 0 ) ;
V_50:
F_23 ( V_10 . V_13 ) ;
V_48:
F_24 ( V_22 ) ;
return V_21 ;
}
