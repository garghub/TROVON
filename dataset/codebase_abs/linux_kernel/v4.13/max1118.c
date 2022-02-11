static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 V_9 [] = {
{
. V_10 = 0 ,
. V_11 = 1 ,
. V_12 = 1 ,
} ,
{
. V_10 = 0 ,
. V_11 = 8 ,
} ,
{
. V_13 = & V_7 -> V_14 ,
. V_10 = 1 ,
} ,
} ;
int V_15 ;
if ( V_3 == 0 )
V_15 = F_4 ( V_2 , V_9 + 1 , 2 ) ;
else
V_15 = F_4 ( V_2 , V_9 , 3 ) ;
if ( V_15 )
return V_15 ;
return V_7 -> V_14 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
const struct V_16 * V_17 = F_6 ( V_2 ) ;
int V_18 ;
switch ( V_17 -> V_19 ) {
case V_20 :
return 2048 ;
case V_21 :
return 4096 ;
case V_6 :
V_18 = F_7 ( V_7 -> V_22 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_18 / 1000 ;
}
return - V_23 ;
}
static int F_8 ( struct V_4 * V_5 ,
struct V_24 const * V_25 ,
int * V_26 , int * V_27 , long V_28 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
switch ( V_28 ) {
case V_29 :
F_9 ( & V_7 -> V_30 ) ;
* V_26 = F_1 ( V_7 -> V_2 , V_25 -> V_3 ) ;
F_10 ( & V_7 -> V_30 ) ;
if ( * V_26 < 0 )
return * V_26 ;
return V_31 ;
case V_32 :
* V_26 = F_5 ( V_7 -> V_2 ) ;
if ( * V_26 < 0 )
return * V_26 ;
* V_27 = 8 ;
return V_33 ;
}
return - V_34 ;
}
static T_1 F_11 ( int V_35 , void * V_36 )
{
struct V_37 * V_38 = V_36 ;
struct V_4 * V_5 = V_38 -> V_5 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_2 V_14 [ 16 ] = { } ;
int V_39 ;
int V_40 = 0 ;
F_9 ( & V_7 -> V_30 ) ;
F_12 (scan_index, indio_dev->active_scan_mask,
indio_dev->masklength) {
const struct V_24 * V_41 =
& V_5 -> V_42 [ V_39 ] ;
int V_15 = F_1 ( V_7 -> V_2 , V_41 -> V_3 ) ;
if ( V_15 < 0 ) {
F_13 ( & V_7 -> V_2 -> V_43 ,
L_1 ) ;
goto V_44;
}
V_14 [ V_40 ] = V_15 ;
V_40 ++ ;
}
F_14 ( V_5 , V_14 ,
F_15 ( V_5 ) ) ;
V_44:
F_10 ( & V_7 -> V_30 ) ;
F_16 ( V_5 -> V_45 ) ;
return V_46 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
const struct V_16 * V_17 = F_6 ( V_2 ) ;
int V_15 ;
V_5 = F_18 ( & V_2 -> V_43 , sizeof( * V_7 ) ) ;
if ( ! V_5 )
return - V_47 ;
V_7 = F_3 ( V_5 ) ;
V_7 -> V_2 = V_2 ;
F_19 ( & V_7 -> V_30 ) ;
if ( V_17 -> V_19 == V_6 ) {
V_7 -> V_22 = F_20 ( & V_2 -> V_43 , L_2 ) ;
if ( F_21 ( V_7 -> V_22 ) ) {
F_22 ( & V_2 -> V_43 , L_3 ) ;
return F_23 ( V_7 -> V_22 ) ;
}
V_15 = F_24 ( V_7 -> V_22 ) ;
if ( V_15 )
return V_15 ;
}
F_25 ( V_2 , V_5 ) ;
V_5 -> V_48 = F_6 ( V_2 ) -> V_48 ;
V_5 -> V_43 . V_49 = & V_2 -> V_43 ;
V_5 -> V_50 = & V_51 ;
V_5 -> V_52 = V_53 ;
V_5 -> V_42 = V_54 ;
V_5 -> V_55 = F_26 ( V_54 ) ;
F_1 ( V_2 , 0 ) ;
V_15 = F_27 ( V_5 , NULL ,
F_11 , NULL ) ;
if ( V_15 )
goto V_56;
V_15 = F_28 ( V_5 ) ;
if ( V_15 )
goto V_57;
return 0 ;
V_57:
F_29 ( V_5 ) ;
V_56:
if ( V_17 -> V_19 == V_6 )
F_30 ( V_7 -> V_22 ) ;
return V_15 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
const struct V_16 * V_17 = F_6 ( V_2 ) ;
F_32 ( V_5 ) ;
F_29 ( V_5 ) ;
if ( V_17 -> V_19 == V_6 )
return F_30 ( V_7 -> V_22 ) ;
return 0 ;
}
