static const struct V_1 *
F_1 ( const int V_2 )
{
switch ( V_2 ) {
case 6 :
return & V_3 ;
case 7 :
return & V_4 ;
case 8 :
return & V_5 ;
case 9 :
return & V_6 ;
}
return NULL ;
}
static int F_2 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_11 ;
V_8 -> V_2 = F_3 ( V_10 ) ;
V_8 -> V_12 = F_1 ( V_8 -> V_2 ) ;
if ( V_8 -> V_12 == NULL )
return 0 ;
if ( V_8 -> V_12 -> V_13 * 4 > 4096 )
return - V_14 ;
V_8 -> V_15 = F_4 ( & V_10 -> V_16 , 4096 ) ;
if ( F_5 ( V_8 -> V_15 ) )
return F_6 ( V_8 -> V_15 ) ;
V_11 = F_7 ( V_8 -> V_15 , 4096 , 0 ) ;
if ( V_11 )
goto V_17;
V_8 -> V_18 = F_8 ( V_8 -> V_15 ) ;
return 0 ;
V_17:
F_9 ( & V_8 -> V_15 -> V_19 ) ;
return V_11 ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_20 * V_21 = V_8 -> V_15 -> V_19 . V_21 ;
const struct V_1 * V_12 = V_8 -> V_12 ;
unsigned int V_22 = 0 , V_23 = 0 ;
struct V_24 * V_24 ;
T_1 * V_25 ;
int V_11 ;
V_11 = F_11 ( V_8 -> V_15 , true ) ;
if ( V_11 )
return V_11 ;
V_24 = F_12 ( V_8 -> V_15 , 0 ) ;
V_25 = F_13 ( V_24 ) ;
while ( V_22 < V_12 -> V_13 ) {
T_1 V_26 = V_12 -> V_27 [ V_22 ] ;
if ( V_22 * 4 == V_12 -> V_28 [ V_23 ] ) {
T_2 V_29 = V_26 + V_8 -> V_18 ;
V_26 = F_14 ( V_29 ) ;
if ( V_8 -> V_2 >= 8 ) {
if ( V_22 + 1 >= V_12 -> V_13 ||
V_12 -> V_27 [ V_22 + 1 ] != 0 ) {
V_11 = - V_14 ;
goto V_30;
}
V_25 [ V_22 ++ ] = V_26 ;
V_26 = F_15 ( V_29 ) ;
}
V_23 ++ ;
}
V_25 [ V_22 ++ ] = V_26 ;
}
while ( V_22 % V_31 )
F_16 ( V_25 , V_22 , V_32 ) ;
V_8 -> V_33 = V_22 * sizeof( T_1 ) ;
if ( F_17 ( V_21 ) ) {
T_1 V_34 = 0x00777000 ;
F_16 ( V_25 , V_22 , V_35 ) ;
F_16 ( V_25 , V_22 , V_36 ) ;
F_16 ( V_25 , V_22 , V_34 ) ;
F_16 ( V_25 , V_22 , 0 ) ;
F_16 ( V_25 , V_22 , 0 ) ;
F_16 ( V_25 , V_22 , 0 ) ;
}
F_16 ( V_25 , V_22 , V_37 ) ;
V_8 -> V_38 = ( V_22 * sizeof( T_1 ) ) - V_8 -> V_33 ;
V_8 -> V_38 = F_18 ( V_8 -> V_38 , 8 ) ;
F_19 ( V_24 ) ;
V_11 = F_20 ( V_8 -> V_15 , false ) ;
if ( V_11 )
return V_11 ;
if ( V_12 -> V_28 [ V_23 ] != - 1 ) {
F_21 ( L_1 , V_23 ) ;
return - V_14 ;
}
return 0 ;
V_30:
F_19 ( V_24 ) ;
return V_11 ;
}
void F_22 ( struct V_7 * V_8 )
{
F_23 ( V_8 -> V_15 ) ;
F_9 ( & V_8 -> V_15 -> V_19 ) ;
}
int F_24 ( struct V_39 * V_40 ,
struct V_7 * V_8 )
{
int V_11 ;
if ( F_25 ( V_40 -> V_41 != V_42 ) )
return - V_43 ;
V_11 = F_2 ( V_8 , V_40 -> V_44 ) ;
if ( V_11 )
return V_11 ;
if ( V_8 -> V_12 == NULL )
return 0 ;
V_11 = F_10 ( V_8 ) ;
if ( V_11 ) {
F_22 ( V_8 ) ;
return V_11 ;
}
return 0 ;
}
int F_26 ( struct V_45 * V_46 )
{
struct V_7 V_8 ;
int V_11 ;
V_11 = F_24 ( V_46 -> V_40 , & V_8 ) ;
if ( V_11 )
return V_11 ;
if ( V_8 . V_12 == NULL )
return 0 ;
V_11 = V_46 -> V_40 -> V_47 ( V_46 , V_8 . V_18 ,
V_8 . V_12 -> V_13 * 4 ,
V_48 ) ;
if ( V_11 )
goto V_49;
if ( V_8 . V_38 > 8 ) {
V_11 = V_46 -> V_40 -> V_47 ( V_46 ,
( V_8 . V_18 +
V_8 . V_33 ) ,
V_8 . V_38 ,
V_48 ) ;
if ( V_11 )
goto V_49;
}
F_27 ( F_28 ( V_8 . V_15 ) , V_46 ) ;
V_49:
F_22 ( & V_8 ) ;
return V_11 ;
}
