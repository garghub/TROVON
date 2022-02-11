static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
int type = V_2 -> V_6 -> V_7 ;
if ( F_3 ( & V_5 -> V_8 ) > 0 )
return - V_9 ;
if ( V_3 != V_10 ||
! ( type == V_11 ||
type == V_12 ||
type == V_13 ) ) {
V_5 -> V_14 . V_15 = V_16 ;
F_4 ( L_1
L_2 ) ;
return 0 ;
}
if ( V_5 -> V_14 . V_17 [ 0 ] == NULL ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
V_5 -> V_14 . V_17 [ V_18 ] =
F_5 ( V_20 , V_21 ) ;
if ( V_5 -> V_14 . V_17 [ V_18 ] == NULL ) {
while ( -- V_18 >= 0 ) {
F_6 ( V_5 -> V_14 . V_17 [ V_18 ] ) ;
V_5 -> V_14 . V_17 [ V_18 ] = NULL ;
}
V_5 -> V_14 . V_15 =
V_16 ;
F_7 ( L_3
L_4 ) ;
return - V_22 ;
}
}
}
V_5 -> V_14 . V_15 = V_3 ;
F_4 ( L_5
L_6 ) ;
if ( F_8 ( V_5 -> V_14 . V_23 ) == 0 ) {
if ( V_5 -> V_24 )
V_5 -> V_14 . V_23 -> V_25 =
V_26 ;
else
V_5 -> V_14 . V_23 -> V_25 = V_27 ;
F_9 ( V_5 -> V_14 . V_23 , V_5 -> V_28 ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
int V_29 = V_7 == V_30 ;
struct V_31 V_32 = {
. V_33 = V_34 ,
} ;
struct V_35 * V_3 = & V_32 . V_32 ;
V_3 -> V_36 = V_2 -> V_36 / ( V_29 ? 2 : 1 ) ;
V_3 -> V_37 = V_2 -> V_37 ;
V_3 -> V_38 = V_39 ;
F_11 ( V_5 -> V_40 , V_41 , V_42 , NULL , & V_32 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_43 )
{
static const T_1 V_44 [ 3 ] = { 44100 , 48000 , 32000 } ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( V_43 < F_13 ( V_44 ) )
F_14 ( V_5 , V_45 , V_46 , V_44 [ V_43 ] ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_5 -> V_47 = V_7 ;
return 0 ;
}
