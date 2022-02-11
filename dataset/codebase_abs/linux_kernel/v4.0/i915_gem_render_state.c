static const struct V_1 *
F_1 ( struct V_2 * V_3 , const int V_4 )
{
switch ( V_4 ) {
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
static int F_2 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
int V_11 ;
V_10 -> V_4 = F_3 ( V_3 ) -> V_4 ;
V_10 -> V_12 = F_1 ( V_3 , V_10 -> V_4 ) ;
if ( V_10 -> V_12 == NULL )
return 0 ;
if ( V_10 -> V_12 -> V_13 * 4 > 4096 )
return - V_14 ;
V_10 -> V_15 = F_4 ( V_3 , 4096 ) ;
if ( V_10 -> V_15 == NULL )
return - V_16 ;
V_11 = F_5 ( V_10 -> V_15 , 4096 , 0 ) ;
if ( V_11 )
goto V_17;
V_10 -> V_18 = F_6 ( V_10 -> V_15 ) ;
return 0 ;
V_17:
F_7 ( & V_10 -> V_15 -> V_19 ) ;
return V_11 ;
}
static int F_8 ( struct V_9 * V_10 )
{
const struct V_1 * V_12 = V_10 -> V_12 ;
unsigned int V_20 = 0 , V_21 = 0 ;
struct V_22 * V_22 ;
T_1 * V_23 ;
int V_11 ;
V_11 = F_9 ( V_10 -> V_15 , true ) ;
if ( V_11 )
return V_11 ;
V_22 = F_10 ( V_10 -> V_15 -> V_24 -> V_25 ) ;
V_23 = F_11 ( V_22 ) ;
while ( V_20 < V_12 -> V_13 ) {
T_1 V_26 = V_12 -> V_27 [ V_20 ] ;
if ( V_20 * 4 == V_12 -> V_28 [ V_21 ] ) {
T_2 V_29 = V_26 + V_10 -> V_18 ;
V_26 = F_12 ( V_29 ) ;
if ( V_10 -> V_4 >= 8 ) {
if ( V_20 + 1 >= V_12 -> V_13 ||
V_12 -> V_27 [ V_20 + 1 ] != 0 )
return - V_14 ;
V_23 [ V_20 ++ ] = V_26 ;
V_26 = F_13 ( V_29 ) ;
}
V_21 ++ ;
}
V_23 [ V_20 ++ ] = V_26 ;
}
F_14 ( V_22 ) ;
V_11 = F_15 ( V_10 -> V_15 , false ) ;
if ( V_11 )
return V_11 ;
if ( V_12 -> V_28 [ V_21 ] != - 1 ) {
F_16 ( L_1 , V_21 ) ;
return - V_14 ;
}
return 0 ;
}
void F_17 ( struct V_9 * V_10 )
{
F_18 ( V_10 -> V_15 ) ;
F_7 ( & V_10 -> V_15 -> V_19 ) ;
}
int F_19 ( struct V_30 * V_31 ,
struct V_9 * V_10 )
{
int V_11 ;
if ( F_20 ( V_31 -> V_32 != V_33 ) )
return - V_34 ;
V_11 = F_2 ( V_10 , V_31 -> V_3 ) ;
if ( V_11 )
return V_11 ;
if ( V_10 -> V_12 == NULL )
return 0 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 ) {
F_17 ( V_10 ) ;
return V_11 ;
}
return 0 ;
}
int F_21 ( struct V_30 * V_31 )
{
struct V_9 V_10 ;
int V_11 ;
V_11 = F_19 ( V_31 , & V_10 ) ;
if ( V_11 )
return V_11 ;
if ( V_10 . V_12 == NULL )
return 0 ;
V_11 = V_31 -> V_35 ( V_31 ,
V_10 . V_18 ,
V_10 . V_12 -> V_13 * 4 ,
V_36 ) ;
if ( V_11 )
goto V_37;
F_22 ( F_23 ( V_10 . V_15 ) , V_31 ) ;
V_11 = F_24 ( V_31 , NULL , V_10 . V_15 ) ;
V_37:
F_17 ( & V_10 ) ;
return V_11 ;
}
