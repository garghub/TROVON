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
static void F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
unsigned char V_13 [ 3 ] ;
int V_5 ;
V_12 = F_5 ( V_10 , struct V_11 , V_10 ) ;
V_2 = V_12 -> V_2 ;
F_6 ( & V_12 -> V_14 ) ;
if ( ( V_12 -> V_15 == 0 ) && V_12 -> V_16 ) {
F_1 ( V_2 , V_12 -> V_3 , 1 ) ;
if ( V_12 -> V_17 ) {
F_7 ( V_12 -> V_18 , V_12 -> V_19 ,
V_20 , V_12 -> V_17 ) ;
}
F_7 ( V_12 -> V_18 , V_12 -> V_21 ,
V_22 , V_23 ) ;
F_7 ( V_12 -> V_18 , V_24 , V_12 -> V_25 ,
V_12 -> V_25 ) ;
}
F_7 ( V_12 -> V_18 , V_12 -> V_19 , V_26 ,
V_12 -> V_16 ) ;
if ( V_12 -> V_16 == 0 ) {
F_8 ( V_12 -> V_18 , V_12 -> V_19 , 3 , V_13 ) ;
V_5 = V_13 [ 0 ] & V_26 ;
V_5 |= V_13 [ 1 ] & V_26 ;
V_5 |= V_13 [ 2 ] & V_26 ;
if ( V_5 == 0 ) {
F_7 ( V_12 -> V_18 , V_12 -> V_19 ,
V_20 , 0 ) ;
F_7 ( V_12 -> V_18 , V_24 ,
V_12 -> V_25 , 0 ) ;
F_1 ( V_2 , V_12 -> V_3 , 0 ) ;
}
}
V_12 -> V_15 = V_12 -> V_16 ;
F_9 ( V_2 -> V_27 , L_1 ,
V_12 -> V_19 , V_12 -> V_16 ) ;
F_10 ( & V_12 -> V_14 ) ;
}
static void F_11 ( struct V_28 * V_29 ,
enum V_30 V_31 )
{
struct V_11 * V_32 = F_5 ( V_29 , struct V_11 , V_29 ) ;
V_32 -> V_16 = V_31 >> 3 ;
F_12 ( & V_32 -> V_10 ) ;
}
static int F_13 ( struct V_33 * V_34 ,
struct V_11 * V_32 )
{
struct V_35 * V_36 = V_34 -> V_27 . V_37 -> V_38 , * V_39 ;
int V_17 = 0 ;
if ( ! V_36 )
return - V_40 ;
V_36 = F_14 ( V_36 , L_2 ) ;
if ( ! V_36 ) {
F_15 ( & V_34 -> V_27 , L_3 ) ;
return - V_40 ;
}
F_16 (nproot, np) {
if ( ! F_17 ( V_39 -> V_41 , V_32 -> V_41 ) ) {
F_18 ( V_39 , L_4 ,
& V_17 ) ;
V_32 -> V_17 = F_19 ( V_17 ) ;
break;
}
}
return 0 ;
}
static int F_20 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_21 ( V_34 -> V_27 . V_37 ) ;
struct V_42 * V_43 = V_34 -> V_27 . V_44 ;
struct V_11 * V_32 ;
struct V_45 * V_46 ;
int V_5 = 0 ;
V_32 = F_22 ( & V_34 -> V_27 , sizeof( struct V_11 ) , V_47 ) ;
if ( V_32 == NULL )
return - V_48 ;
V_46 = F_23 ( V_34 , V_49 , L_5 ) ;
if ( ! V_46 ) {
F_15 ( & V_34 -> V_27 , L_6 ) ;
return - V_50 ;
}
V_32 -> V_19 = V_46 -> V_51 ;
V_46 = F_23 ( V_34 , V_49 , L_7 ) ;
if ( ! V_46 ) {
F_15 ( & V_34 -> V_27 , L_8 ) ;
return - V_50 ;
}
V_32 -> V_21 = V_46 -> V_51 ;
memset ( V_32 -> V_41 , 0 , V_52 ) ;
switch ( V_34 -> V_53 ) {
case 0 :
V_32 -> V_25 = V_54 ;
sprintf ( V_32 -> V_41 , L_9 ) ;
break;
case 1 :
V_32 -> V_25 = V_54 ;
sprintf ( V_32 -> V_41 , L_10 ) ;
break;
case 2 :
V_32 -> V_25 = V_54 ;
sprintf ( V_32 -> V_41 , L_11 ) ;
break;
case 3 :
V_32 -> V_25 = V_55 ;
sprintf ( V_32 -> V_41 , L_12 ) ;
break;
case 4 :
V_32 -> V_25 = V_55 ;
sprintf ( V_32 -> V_41 , L_13 ) ;
break;
case 5 :
V_32 -> V_25 = V_55 ;
sprintf ( V_32 -> V_41 , L_14 ) ;
break;
}
F_24 ( & V_34 -> V_27 , V_32 ) ;
V_32 -> V_2 = V_2 ;
V_32 -> V_18 = ( V_2 -> V_53 == V_56 ) ? V_2 -> V_57 : V_2 -> V_58 ;
V_32 -> V_3 = V_34 -> V_53 ;
if ( F_13 ( V_34 , V_32 ) )
if ( V_43 )
V_32 -> V_17 = V_43 -> V_17 ;
V_32 -> V_15 = 0 ;
V_32 -> V_29 . V_41 = V_32 -> V_41 ;
V_32 -> V_29 . V_59 = F_11 ;
F_25 ( & V_32 -> V_14 ) ;
F_26 ( & V_32 -> V_10 , F_4 ) ;
V_5 = F_27 ( V_2 -> V_27 , & V_32 -> V_29 ) ;
if ( V_5 < 0 ) {
F_15 ( & V_34 -> V_27 , L_15 , V_5 ) ;
return V_5 ;
}
F_11 ( & V_32 -> V_29 , 0 ) ;
return 0 ;
}
static int F_28 ( struct V_33 * V_34 )
{
struct V_11 * V_32 = F_29 ( V_34 ) ;
F_30 ( & V_32 -> V_29 ) ;
return 0 ;
}
