static int F_1 ( struct V_1 * V_2 ,
const unsigned long * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 , V_8 ;
V_8 = 0 ;
F_3 (i, active_scan_mask, indio_dev->num_channels) {
V_7 = V_9 | F_4 ( V_6 ) | V_5 -> V_10 ;
V_5 -> V_11 [ V_8 ++ ] = F_5 ( V_7 ) ;
}
V_8 += 2 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
if ( ( V_6 + 2 ) < V_8 )
V_5 -> V_12 [ V_6 ] . V_11 = & V_5 -> V_11 [ V_6 ] ;
if ( V_6 >= 2 )
V_5 -> V_12 [ V_6 ] . V_13 = & V_5 -> V_13 [ V_6 - 2 ] ;
V_5 -> V_12 [ V_6 ] . V_8 = 2 ;
V_5 -> V_12 [ V_6 ] . V_14 = 1 ;
}
V_5 -> V_12 [ V_8 - 1 ] . V_14 = 0 ;
F_6 ( & V_5 -> V_15 , V_5 -> V_12 , V_8 ) ;
return 0 ;
}
static T_1 F_7 ( int V_16 , void * V_17 )
{
struct V_18 * V_19 = V_17 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_20 ;
V_20 = F_8 ( V_5 -> V_21 , & V_5 -> V_15 ) ;
if ( V_20 < 0 )
goto V_22;
F_9 ( V_2 , V_5 -> V_13 ,
F_10 ( V_2 ) ) ;
V_22:
F_11 ( V_2 -> V_23 ) ;
return V_24 ;
}
static int F_12 ( struct V_4 * V_5 , unsigned int V_25 )
{
int V_20 , V_7 ;
V_7 = V_9 | F_4 ( V_25 ) | V_5 -> V_10 ;
V_5 -> V_11 [ 0 ] = F_5 ( V_7 ) ;
V_20 = F_8 ( V_5 -> V_21 , & V_5 -> V_26 ) ;
if ( V_20 )
return V_20 ;
return F_13 ( V_5 -> V_13 [ 0 ] ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
int V_27 ;
V_27 = F_15 ( V_5 -> V_28 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 /= 1000 ;
if ( V_5 -> V_10 & V_29 )
V_27 *= 2 ;
return V_27 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_30 const * V_31 ,
int * V_32 , int * V_33 , long V_34 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_20 ;
switch ( V_34 ) {
case V_35 :
V_20 = F_17 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_12 ( V_5 , V_31 -> V_36 ) ;
F_18 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_31 -> V_36 != F_19 ( V_20 , 12 , 4 ) )
return - V_37 ;
* V_32 = F_19 ( V_20 , V_31 -> V_38 . V_39 ,
V_31 -> V_38 . V_40 ) ;
return V_41 ;
case V_42 :
V_20 = F_14 ( V_5 ) ;
if ( V_20 < 0 )
return V_20 ;
* V_32 = V_20 ;
* V_33 = ( 1 << V_31 -> V_38 . V_40 ) - 1 ;
return V_43 ;
}
return - V_44 ;
}
static int F_20 ( struct V_45 * V_21 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
const struct V_46 * V_47 ;
int V_20 ;
V_2 = F_21 ( & V_21 -> V_48 , sizeof( * V_5 ) ) ;
if ( ! V_2 )
return - V_49 ;
V_5 = F_2 ( V_2 ) ;
F_22 ( V_21 , V_2 ) ;
V_5 -> V_21 = V_21 ;
V_5 -> V_10 = V_50 | V_29 ;
V_47 = & V_46 [ F_23 ( V_21 ) -> V_51 ] ;
V_2 -> V_52 = F_23 ( V_21 ) -> V_52 ;
V_2 -> V_48 . V_53 = & V_21 -> V_48 ;
V_2 -> V_54 = V_55 ;
V_2 -> V_56 = V_47 -> V_56 ;
V_2 -> V_57 = V_47 -> V_57 ;
V_2 -> V_47 = & V_58 ;
V_5 -> V_59 [ 0 ] . V_11 = & V_5 -> V_11 [ 0 ] ;
V_5 -> V_59 [ 0 ] . V_8 = 2 ;
V_5 -> V_59 [ 0 ] . V_14 = 1 ;
V_5 -> V_59 [ 1 ] . V_11 = & V_5 -> V_11 [ 0 ] ;
V_5 -> V_59 [ 1 ] . V_8 = 2 ;
V_5 -> V_59 [ 1 ] . V_14 = 1 ;
V_5 -> V_59 [ 2 ] . V_13 = & V_5 -> V_13 [ 0 ] ;
V_5 -> V_59 [ 2 ] . V_8 = 2 ;
F_6 ( & V_5 -> V_26 ,
V_5 -> V_59 , 3 ) ;
V_5 -> V_28 = F_24 ( & V_21 -> V_48 , L_1 ) ;
if ( F_25 ( V_5 -> V_28 ) ) {
F_26 ( & V_21 -> V_48 , L_2 ) ;
return F_27 ( V_5 -> V_28 ) ;
}
V_20 = F_28 ( V_5 -> V_28 ) ;
if ( V_20 ) {
F_26 ( & V_21 -> V_48 , L_3 ) ;
return V_20 ;
}
V_20 = F_29 ( V_2 , NULL ,
& F_7 , NULL ) ;
if ( V_20 ) {
F_26 ( & V_21 -> V_48 , L_4 ) ;
goto V_60;
}
V_20 = F_30 ( V_2 ) ;
if ( V_20 ) {
F_26 ( & V_21 -> V_48 , L_5 ) ;
goto V_61;
}
return 0 ;
V_61:
F_31 ( V_2 ) ;
V_60:
F_32 ( V_5 -> V_28 ) ;
return V_20 ;
}
static int F_33 ( struct V_45 * V_21 )
{
struct V_1 * V_2 = F_34 ( V_21 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_35 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_5 -> V_28 ) ;
return 0 ;
}
