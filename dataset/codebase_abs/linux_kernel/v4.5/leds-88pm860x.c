static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 = - V_6 ;
switch ( V_3 ) {
case 0 :
case 1 :
case 2 :
V_5 = V_4 ? F_2 ( V_2 , V_7 ) :
F_3 ( V_2 , V_7 ) ;
break;
case 3 :
case 4 :
case 5 :
V_5 = V_4 ? F_2 ( V_2 , V_8 ) :
F_3 ( V_2 , V_8 ) ;
break;
}
return V_5 ;
}
static int F_4 ( struct V_9 * V_10 ,
enum V_11 V_12 )
{
struct V_13 * V_14 = F_5 ( V_10 , struct V_13 , V_10 ) ;
struct V_1 * V_2 ;
unsigned char V_15 [ 3 ] ;
int V_5 ;
V_2 = V_14 -> V_2 ;
F_6 ( & V_14 -> V_16 ) ;
V_14 -> V_17 = V_12 >> 3 ;
if ( ( V_14 -> V_18 == 0 ) && V_14 -> V_17 ) {
F_1 ( V_2 , V_14 -> V_3 , 1 ) ;
if ( V_14 -> V_19 ) {
F_7 ( V_14 -> V_20 , V_14 -> V_21 ,
V_22 , V_14 -> V_19 ) ;
}
F_7 ( V_14 -> V_20 , V_14 -> V_23 ,
V_24 , V_25 ) ;
F_7 ( V_14 -> V_20 , V_26 , V_14 -> V_27 ,
V_14 -> V_27 ) ;
}
F_7 ( V_14 -> V_20 , V_14 -> V_21 , V_28 ,
V_14 -> V_17 ) ;
if ( V_14 -> V_17 == 0 ) {
F_8 ( V_14 -> V_20 , V_14 -> V_21 , 3 , V_15 ) ;
V_5 = V_15 [ 0 ] & V_28 ;
V_5 |= V_15 [ 1 ] & V_28 ;
V_5 |= V_15 [ 2 ] & V_28 ;
if ( V_5 == 0 ) {
F_7 ( V_14 -> V_20 , V_14 -> V_21 ,
V_22 , 0 ) ;
F_7 ( V_14 -> V_20 , V_26 ,
V_14 -> V_27 , 0 ) ;
F_1 ( V_2 , V_14 -> V_3 , 0 ) ;
}
}
V_14 -> V_18 = V_14 -> V_17 ;
F_9 ( V_2 -> V_29 , L_1 ,
V_14 -> V_21 , V_14 -> V_17 ) ;
F_10 ( & V_14 -> V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_30 * V_31 ,
struct V_13 * V_32 )
{
struct V_33 * V_34 , * V_35 ;
int V_19 = 0 ;
if ( ! V_31 -> V_29 . V_36 -> V_37 )
return - V_38 ;
V_34 = F_12 ( V_31 -> V_29 . V_36 -> V_37 , L_2 ) ;
if ( ! V_34 ) {
F_13 ( & V_31 -> V_29 , L_3 ) ;
return - V_38 ;
}
F_14 (nproot, np) {
if ( ! F_15 ( V_35 -> V_39 , V_32 -> V_39 ) ) {
F_16 ( V_35 , L_4 ,
& V_19 ) ;
V_32 -> V_19 = F_17 ( V_19 ) ;
F_18 ( V_35 ) ;
break;
}
}
F_18 ( V_34 ) ;
return 0 ;
}
static int F_19 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_20 ( V_31 -> V_29 . V_36 ) ;
struct V_40 * V_41 = F_21 ( & V_31 -> V_29 ) ;
struct V_13 * V_32 ;
struct V_42 * V_43 ;
int V_5 = 0 ;
V_32 = F_22 ( & V_31 -> V_29 , sizeof( struct V_13 ) , V_44 ) ;
if ( V_32 == NULL )
return - V_45 ;
V_43 = F_23 ( V_31 , V_46 , L_5 ) ;
if ( ! V_43 ) {
F_13 ( & V_31 -> V_29 , L_6 ) ;
return - V_47 ;
}
V_32 -> V_21 = V_43 -> V_48 ;
V_43 = F_23 ( V_31 , V_46 , L_7 ) ;
if ( ! V_43 ) {
F_13 ( & V_31 -> V_29 , L_8 ) ;
return - V_47 ;
}
V_32 -> V_23 = V_43 -> V_48 ;
memset ( V_32 -> V_39 , 0 , V_49 ) ;
switch ( V_31 -> V_50 ) {
case 0 :
V_32 -> V_27 = V_51 ;
sprintf ( V_32 -> V_39 , L_9 ) ;
break;
case 1 :
V_32 -> V_27 = V_51 ;
sprintf ( V_32 -> V_39 , L_10 ) ;
break;
case 2 :
V_32 -> V_27 = V_51 ;
sprintf ( V_32 -> V_39 , L_11 ) ;
break;
case 3 :
V_32 -> V_27 = V_52 ;
sprintf ( V_32 -> V_39 , L_12 ) ;
break;
case 4 :
V_32 -> V_27 = V_52 ;
sprintf ( V_32 -> V_39 , L_13 ) ;
break;
case 5 :
V_32 -> V_27 = V_52 ;
sprintf ( V_32 -> V_39 , L_14 ) ;
break;
}
F_24 ( V_31 , V_32 ) ;
V_32 -> V_2 = V_2 ;
V_32 -> V_20 = ( V_2 -> V_50 == V_53 ) ? V_2 -> V_54 : V_2 -> V_55 ;
V_32 -> V_3 = V_31 -> V_50 ;
if ( F_11 ( V_31 , V_32 ) )
if ( V_41 )
V_32 -> V_19 = V_41 -> V_19 ;
V_32 -> V_18 = 0 ;
V_32 -> V_10 . V_39 = V_32 -> V_39 ;
V_32 -> V_10 . V_56 = F_4 ;
F_25 ( & V_32 -> V_16 ) ;
V_5 = F_26 ( V_2 -> V_29 , & V_32 -> V_10 ) ;
if ( V_5 < 0 ) {
F_13 ( & V_31 -> V_29 , L_15 , V_5 ) ;
return V_5 ;
}
F_4 ( & V_32 -> V_10 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_30 * V_31 )
{
struct V_13 * V_32 = F_28 ( V_31 ) ;
F_29 ( & V_32 -> V_10 ) ;
return 0 ;
}
