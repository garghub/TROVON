static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_9 ;
V_9 = F_3 ( V_8 -> V_10 , & V_8 -> V_11 ) ;
if ( V_9 < 0 )
goto V_12;
F_4 ( V_6 , V_8 -> V_13 ,
F_5 ( V_6 ) ) ;
V_12:
F_6 ( V_6 -> V_14 ) ;
return V_15 ;
}
static int F_7 ( struct V_7 * V_8 )
{
int V_16 ;
V_16 = F_8 ( V_8 -> V_17 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 /= 1000 ;
return V_16 ;
}
static int F_9 ( struct V_5 * V_6 ,
struct V_18 const * V_19 ,
int * V_20 ,
int * V_21 ,
long V_22 )
{
int V_9 = 0 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
switch ( V_22 ) {
case V_23 :
V_9 = F_10 ( V_6 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_8 -> V_10 , & V_8 -> V_11 ) ;
F_11 ( V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_20 = F_12 ( V_8 -> V_13 [ 0 ] ) ;
* V_20 = * V_20 >> V_19 -> V_24 . V_25 ;
* V_20 &= F_13 ( V_19 -> V_24 . V_26 - 1 , 0 ) ;
return V_27 ;
case V_28 :
V_9 = F_7 ( V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_20 = V_9 ;
* V_21 = V_19 -> V_24 . V_26 ;
return V_29 ;
}
return - V_30 ;
}
static int F_14 ( struct V_31 * V_10 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
const struct V_32 * V_33 ;
int V_9 ;
T_2 V_34 = 0 ;
V_6 = F_15 ( & V_10 -> V_35 , sizeof( * V_8 ) ) ;
if ( V_6 == NULL )
return - V_36 ;
V_8 = F_2 ( V_6 ) ;
F_16 ( V_10 , V_6 ) ;
V_8 -> V_10 = V_10 ;
V_33 = & V_32 [ F_17 ( V_10 ) -> V_37 ] ;
V_6 -> V_38 = F_17 ( V_10 ) -> V_38 ;
V_6 -> V_35 . V_39 = & V_10 -> V_35 ;
V_6 -> V_40 = V_41 ;
V_6 -> V_42 = V_33 -> V_42 ;
V_6 -> V_43 = V_33 -> V_43 ;
V_6 -> V_33 = & V_44 ;
F_18 ( V_10 , & V_34 , 1 ) ;
V_8 -> V_45 [ 0 ] . V_13 = & V_8 -> V_13 [ 0 ] ;
V_8 -> V_45 [ 0 ] . V_46 = 3 ;
V_8 -> V_45 [ 1 ] . V_47 = 3 ;
V_8 -> V_45 [ 2 ] . V_13 = & V_8 -> V_13 [ 0 ] ;
V_8 -> V_45 [ 2 ] . V_46 = 2 ;
F_19 ( & V_8 -> V_11 ,
V_8 -> V_45 , 3 ) ;
V_8 -> V_17 = F_20 ( & V_10 -> V_35 , L_1 ) ;
if ( F_21 ( V_8 -> V_17 ) )
return F_22 ( V_8 -> V_17 ) ;
V_9 = F_23 ( V_8 -> V_17 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_24 ( V_6 , NULL ,
& F_1 , NULL ) ;
if ( V_9 )
goto V_48;
V_9 = F_25 ( V_6 ) ;
if ( V_9 )
goto V_49;
return 0 ;
V_49:
F_26 ( V_6 ) ;
V_48:
F_27 ( V_8 -> V_17 ) ;
return V_9 ;
}
static int F_28 ( struct V_31 * V_10 )
{
struct V_5 * V_6 = F_29 ( V_10 ) ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
F_30 ( V_6 ) ;
F_26 ( V_6 ) ;
F_27 ( V_8 -> V_17 ) ;
return 0 ;
}
