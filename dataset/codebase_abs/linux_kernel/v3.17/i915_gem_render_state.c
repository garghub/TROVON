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
}
return NULL ;
}
static int F_2 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
int V_10 ;
V_9 -> V_4 = F_3 ( V_3 ) -> V_4 ;
V_9 -> V_11 = F_1 ( V_3 , V_9 -> V_4 ) ;
if ( V_9 -> V_11 == NULL )
return 0 ;
if ( V_9 -> V_11 -> V_12 * 4 > 4096 )
return - V_13 ;
V_9 -> V_14 = F_4 ( V_3 , 4096 ) ;
if ( V_9 -> V_14 == NULL )
return - V_15 ;
V_10 = F_5 ( V_9 -> V_14 , 4096 , 0 ) ;
if ( V_10 )
goto V_16;
V_9 -> V_17 = F_6 ( V_9 -> V_14 ) ;
return 0 ;
V_16:
F_7 ( & V_9 -> V_14 -> V_18 ) ;
return V_10 ;
}
static int F_8 ( struct V_8 * V_9 )
{
const struct V_1 * V_11 = V_9 -> V_11 ;
unsigned int V_19 = 0 , V_20 = 0 ;
struct V_21 * V_21 ;
T_1 * V_22 ;
int V_10 ;
V_10 = F_9 ( V_9 -> V_14 , true ) ;
if ( V_10 )
return V_10 ;
V_21 = F_10 ( V_9 -> V_14 -> V_23 -> V_24 ) ;
V_22 = F_11 ( V_21 ) ;
while ( V_19 < V_11 -> V_12 ) {
T_1 V_25 = V_11 -> V_26 [ V_19 ] ;
if ( V_19 * 4 == V_11 -> V_27 [ V_20 ] ) {
T_2 V_28 = V_25 + V_9 -> V_17 ;
V_25 = F_12 ( V_28 ) ;
if ( V_9 -> V_4 >= 8 ) {
if ( V_19 + 1 >= V_11 -> V_12 ||
V_11 -> V_26 [ V_19 + 1 ] != 0 )
return - V_13 ;
V_22 [ V_19 ++ ] = V_25 ;
V_25 = F_13 ( V_28 ) ;
}
V_20 ++ ;
}
V_22 [ V_19 ++ ] = V_25 ;
}
F_14 ( V_21 ) ;
V_10 = F_15 ( V_9 -> V_14 , false ) ;
if ( V_10 )
return V_10 ;
if ( V_11 -> V_27 [ V_20 ] != - 1 ) {
F_16 ( L_1 , V_20 ) ;
return - V_13 ;
}
return 0 ;
}
static void F_17 ( struct V_8 * V_9 )
{
F_18 ( V_9 -> V_14 ) ;
F_7 ( & V_9 -> V_14 -> V_18 ) ;
}
int F_19 ( struct V_29 * V_30 )
{
struct V_8 V_9 ;
int V_10 ;
if ( F_20 ( V_30 -> V_31 != V_32 ) )
return - V_33 ;
V_10 = F_2 ( & V_9 , V_30 -> V_3 ) ;
if ( V_10 )
return V_10 ;
if ( V_9 . V_11 == NULL )
return 0 ;
V_10 = F_8 ( & V_9 ) ;
if ( V_10 )
goto V_34;
V_10 = V_30 -> V_35 ( V_30 ,
V_9 . V_17 ,
V_9 . V_11 -> V_12 * 4 ,
V_36 ) ;
if ( V_10 )
goto V_34;
F_21 ( F_22 ( V_9 . V_14 ) , V_30 ) ;
V_10 = F_23 ( V_30 , NULL , V_9 . V_14 , NULL ) ;
V_34:
F_17 ( & V_9 ) ;
return V_10 ;
}
