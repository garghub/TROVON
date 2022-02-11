static int F_1 ( struct V_1 * V_2 ,
const unsigned long * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 , V_8 ;
V_8 = 0 ;
F_3 (i, active_scan_mask, AD7923_MAX_CHAN) {
V_7 = V_9 | F_4 ( V_6 ) |
F_5 ( V_10 ) |
V_5 -> V_11 ;
V_7 <<= V_12 ;
V_5 -> V_13 [ V_8 ++ ] = F_6 ( V_7 ) ;
}
V_5 -> V_14 [ 0 ] . V_13 = & V_5 -> V_13 [ 0 ] ;
V_5 -> V_14 [ 0 ] . V_8 = V_8 ;
V_5 -> V_14 [ 0 ] . V_15 = 1 ;
F_7 ( & V_5 -> V_16 ) ;
F_8 ( & V_5 -> V_14 [ 0 ] , & V_5 -> V_16 ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
V_5 -> V_14 [ V_6 + 1 ] . V_17 = & V_5 -> V_17 [ V_6 ] ;
V_5 -> V_14 [ V_6 + 1 ] . V_8 = 2 ;
V_5 -> V_14 [ V_6 + 1 ] . V_15 = 1 ;
F_8 ( & V_5 -> V_14 [ V_6 + 1 ] , & V_5 -> V_16 ) ;
}
V_5 -> V_14 [ V_6 + 1 ] . V_15 = 0 ;
return 0 ;
}
static T_1 F_9 ( int V_18 , void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_22 ;
V_22 = F_10 ( V_5 -> V_23 , & V_5 -> V_16 ) ;
if ( V_22 )
goto V_24;
F_11 ( V_2 , V_5 -> V_17 ,
F_12 () ) ;
V_24:
F_13 ( V_2 -> V_25 ) ;
return V_26 ;
}
static int F_14 ( struct V_4 * V_5 , unsigned V_27 )
{
int V_28 , V_7 ;
V_7 = V_9 | F_4 ( V_27 ) |
F_5 ( V_10 ) |
V_5 -> V_11 ;
V_7 <<= V_12 ;
V_5 -> V_13 [ 0 ] = F_6 ( V_7 ) ;
V_28 = F_10 ( V_5 -> V_23 , & V_5 -> V_29 ) ;
if ( V_28 )
return V_28 ;
return F_15 ( V_5 -> V_17 [ 0 ] ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
int V_30 ;
V_30 = F_17 ( V_5 -> V_31 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 /= 1000 ;
if ( ! ( V_5 -> V_11 & V_32 ) )
V_30 *= 2 ;
return V_30 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_33 const * V_34 ,
int * V_35 ,
int * V_36 ,
long V_37 )
{
int V_28 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_37 ) {
case V_38 :
F_19 ( & V_2 -> V_39 ) ;
if ( F_20 ( V_2 ) )
V_28 = - V_40 ;
else
V_28 = F_14 ( V_5 , V_34 -> V_41 ) ;
F_21 ( & V_2 -> V_39 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_34 -> V_41 == F_22 ( V_28 , 12 , 4 ) )
* V_35 = F_22 ( V_28 , 0 , 12 ) ;
else
return - V_42 ;
return V_43 ;
case V_44 :
V_28 = F_16 ( V_5 ) ;
if ( V_28 < 0 )
return V_28 ;
* V_35 = V_28 ;
* V_36 = V_34 -> V_45 . V_46 ;
return V_47 ;
}
return - V_48 ;
}
static int F_23 ( struct V_49 * V_23 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
const struct V_50 * V_51 ;
int V_28 ;
V_2 = F_24 ( & V_23 -> V_52 , sizeof( * V_5 ) ) ;
if ( V_2 == NULL )
return - V_53 ;
V_5 = F_2 ( V_2 ) ;
F_25 ( V_23 , V_2 ) ;
V_5 -> V_23 = V_23 ;
V_5 -> V_11 = V_54 | V_32 |
F_26 ( V_55 ) ;
V_51 = & V_50 [ F_27 ( V_23 ) -> V_56 ] ;
V_2 -> V_57 = F_27 ( V_23 ) -> V_57 ;
V_2 -> V_52 . V_58 = & V_23 -> V_52 ;
V_2 -> V_59 = V_60 ;
V_2 -> V_61 = V_51 -> V_61 ;
V_2 -> V_62 = V_51 -> V_62 ;
V_2 -> V_51 = & V_63 ;
V_5 -> V_64 [ 0 ] . V_13 = & V_5 -> V_13 [ 0 ] ;
V_5 -> V_64 [ 0 ] . V_8 = 2 ;
V_5 -> V_64 [ 0 ] . V_15 = 1 ;
V_5 -> V_64 [ 1 ] . V_17 = & V_5 -> V_17 [ 0 ] ;
V_5 -> V_64 [ 1 ] . V_8 = 2 ;
F_7 ( & V_5 -> V_29 ) ;
F_8 ( & V_5 -> V_64 [ 0 ] , & V_5 -> V_29 ) ;
F_8 ( & V_5 -> V_64 [ 1 ] , & V_5 -> V_29 ) ;
V_5 -> V_31 = F_28 ( & V_23 -> V_52 , L_1 ) ;
if ( F_29 ( V_5 -> V_31 ) )
return F_30 ( V_5 -> V_31 ) ;
V_28 = F_31 ( V_5 -> V_31 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_32 ( V_2 , NULL ,
& F_9 , NULL ) ;
if ( V_28 )
goto V_65;
V_28 = F_33 ( V_2 ) ;
if ( V_28 )
goto V_66;
return 0 ;
V_66:
F_34 ( V_2 ) ;
V_65:
F_35 ( V_5 -> V_31 ) ;
return V_28 ;
}
static int F_36 ( struct V_49 * V_23 )
{
struct V_1 * V_2 = F_37 ( V_23 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_38 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_5 -> V_31 ) ;
return 0 ;
}
