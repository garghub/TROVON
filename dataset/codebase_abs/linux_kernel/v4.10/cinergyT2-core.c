static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
int V_10 ;
F_2 ( & V_5 -> V_11 ) ;
V_8 -> V_12 [ 0 ] = V_13 ;
V_8 -> V_12 [ 1 ] = V_3 ? 1 : 0 ;
V_10 = F_3 ( V_5 , V_8 -> V_12 , 2 , V_8 -> V_12 , 64 , 0 ) ;
F_4 ( & V_5 -> V_11 ) ;
return V_10 ;
}
static int F_5 ( struct V_4 * V_5 , int V_3 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
int V_10 ;
F_2 ( & V_5 -> V_11 ) ;
V_8 -> V_12 [ 0 ] = V_14 ;
V_8 -> V_12 [ 1 ] = V_3 ? 0 : 1 ;
V_10 = F_3 ( V_5 , V_8 -> V_12 , 2 , V_8 -> V_12 , 3 , 0 ) ;
F_4 ( & V_5 -> V_11 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
int V_10 ;
V_2 -> V_15 [ 0 ] . V_16 = F_7 ( V_2 -> V_6 ) ;
F_2 ( & V_5 -> V_11 ) ;
V_8 -> V_12 [ 0 ] = V_17 ;
V_10 = F_3 ( V_5 , V_8 -> V_12 , 1 , V_8 -> V_12 , 3 , 0 ) ;
if ( V_10 < 0 ) {
F_8 ( L_1 ) ;
}
F_4 ( & V_5 -> V_11 ) ;
V_18 = V_2 -> V_6 ;
return V_10 ;
}
static int F_9 ( struct V_4 * V_5 , T_1 * V_19 , int * V_20 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
int V_21 , V_10 ;
* V_20 = V_22 ;
F_2 ( & V_5 -> V_11 ) ;
V_8 -> V_12 [ 0 ] = V_23 ;
V_10 = F_3 ( V_5 , V_8 -> V_12 , 1 , V_8 -> V_12 , 5 , 0 ) ;
if ( V_10 < 0 )
goto V_10;
if ( V_8 -> V_12 [ 4 ] == 0xff ) {
V_8 -> V_24 ++ ;
if ( V_8 -> V_24 > V_25 ) {
for ( V_21 = 0 ; V_21 < F_10 ( V_26 ) ; V_21 ++ ) {
if ( V_5 -> V_27 == V_26 [ V_21 ] ) {
* V_20 = V_28 ;
* V_19 = V_5 -> V_27 ;
F_8 ( L_2 ,
* V_19 ) ;
goto V_10;
}
}
F_8 ( L_3 ) ;
}
goto V_10;
}
V_8 -> V_12 [ 2 ] = ~ V_8 -> V_12 [ 1 ] ;
F_11 ( V_5 , V_8 -> V_12 , V_19 , V_20 ) ;
if ( V_8 -> V_12 [ 0 ] != 0 ) {
if ( * V_19 != V_5 -> V_27 )
V_8 -> V_24 = 0 ;
F_8 ( L_4 , 5 , V_8 -> V_12 ) ;
}
V_10:
F_4 ( & V_5 -> V_11 ) ;
return V_10 ;
}
static int F_12 ( struct V_29 * V_30 ,
const struct V_31 * V_32 )
{
return F_13 ( V_30 , & V_33 ,
V_34 , NULL , V_35 ) ;
}
