static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 ;
F_2 ( V_5 , L_1 ) ;
V_4 = V_2 ;
F_3 ( V_4 -> V_6 , & V_4 -> V_7 ) ;
return V_8 ;
}
static struct V_9 * F_4 ( struct V_3 * V_4 )
{
return V_4 -> V_10 ;
}
static void F_5 ( struct V_3 * V_4 )
{
T_2 * V_11 ;
struct V_12 V_13 ;
struct V_14 V_15 ;
V_11 = F_6 ( V_16 , V_17 ) ;
if ( ! V_11 ) {
F_7 ( L_2 ) ;
return;
}
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
F_8 ( & V_15 ) ;
memset ( V_11 , 0xff , V_16 ) ;
V_13 . V_18 = V_11 ;
V_13 . V_19 = V_16 ;
F_9 ( & V_13 , & V_15 ) ;
F_10 ( F_4 ( V_4 ) , & V_15 ) ;
F_11 ( V_20 , L_3 , V_11 , V_16 ) ;
F_12 ( V_11 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
T_2 V_21 [ V_22 ] , * V_11 ;
struct V_12 V_13 ;
struct V_14 V_15 ;
V_11 = F_6 ( V_16 , V_17 ) ;
if ( ! V_11 ) {
F_7 ( L_4 ) ;
return;
}
memset ( V_21 , 0 , sizeof( V_21 ) ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
F_8 ( & V_15 ) ;
V_11 [ 2 ] = 0xff ;
V_11 [ 3 ] = 0xff ;
V_11 [ 1 ] = V_23 | V_24 ;
V_11 [ 0 ] = 0 ;
V_11 [ 7 ] = 0 ;
V_11 [ 6 ] |= V_25 << 3 ;
V_11 [ 6 ] |= V_26 & V_27 ;
if ( V_26 == 0 )
V_11 [ 5 ] |= V_28 ;
else
V_11 [ 5 ] |= V_29 ;
V_11 [ 5 ] |= V_30 | V_31 | V_32
| V_33 | V_34 ;
V_21 [ 0 ] = V_11 [ 1 ] ;
V_21 [ 1 ] = V_11 [ 0 ] ;
V_21 [ 2 ] = V_11 [ 7 ] ;
V_21 [ 3 ] = V_11 [ 6 ] ;
V_21 [ 4 ] = V_11 [ 5 ] ;
V_11 [ 4 ] |= F_14 ( 0 , V_21 , V_22 ) << 1 ;
V_11 [ 4 ] |= V_35 ;
V_13 . V_18 = V_11 ;
V_13 . V_19 = V_16 ;
F_9 ( & V_13 , & V_15 ) ;
F_10 ( F_4 ( V_4 ) , & V_15 ) ;
F_11 ( V_20 , L_5 , V_11 , V_16 ) ;
F_12 ( V_11 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
F_5 ( V_4 ) ;
F_13 ( V_4 ) ;
}
static void F_16 ( struct V_3 * V_4 , int V_36 , void * V_37 ,
T_3 V_19 )
{
struct V_12 V_13 [ 3 ] ;
struct V_14 V_15 ;
T_2 * V_38 ;
T_4 * V_11 ;
V_11 = & V_4 -> V_39 ;
V_38 = V_4 -> V_40 ;
* V_11 = 0 ;
* V_11 |= V_41 ;
* V_11 |= ( V_19 << V_42 ) & V_43 ;
* V_11 |= V_36 & V_44 ;
F_8 ( & V_15 ) ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
V_13 [ 0 ] . V_18 = V_11 ;
V_13 [ 0 ] . V_19 = 4 ;
F_9 ( & V_13 [ 0 ] , & V_15 ) ;
V_13 [ 1 ] . V_45 = V_38 ;
V_13 [ 1 ] . V_19 = V_46 ;
F_9 ( & V_13 [ 1 ] , & V_15 ) ;
V_13 [ 2 ] . V_45 = V_37 ;
V_13 [ 2 ] . V_19 = V_19 ;
F_9 ( & V_13 [ 2 ] , & V_15 ) ;
F_10 ( F_4 ( V_4 ) , & V_15 ) ;
F_11 ( V_20 , L_6 , V_11 , sizeof( * V_11 ) ) ;
F_11 ( V_20 , L_7 , V_37 , V_19 ) ;
}
static void F_17 ( struct V_3 * V_4 , int V_36 , void * V_37 ,
T_3 V_19 )
{
struct V_12 V_13 [ 2 ] ;
struct V_14 V_15 ;
T_4 * V_11 ;
V_11 = & V_4 -> V_39 ;
* V_11 = 0 ;
* V_11 |= V_47 ;
* V_11 |= ( V_19 << V_42 ) & V_43 ;
* V_11 |= V_36 & V_44 ;
F_8 ( & V_15 ) ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
V_13 [ 0 ] . V_18 = V_11 ;
V_13 [ 0 ] . V_19 = sizeof( * V_11 ) ;
F_9 ( & V_13 [ 0 ] , & V_15 ) ;
V_13 [ 1 ] . V_18 = V_37 ;
V_13 [ 1 ] . V_19 = V_19 ;
F_9 ( & V_13 [ 1 ] , & V_15 ) ;
F_10 ( F_4 ( V_4 ) , & V_15 ) ;
F_11 ( V_20 , L_8 , V_11 , sizeof( * V_11 ) ) ;
F_11 ( V_20 , L_9 , V_37 , V_19 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
return F_19 ( V_4 -> V_1 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
return F_21 ( V_4 -> V_1 ) ;
}
static int F_22 ( struct V_3 * V_4 , bool V_48 )
{
if ( F_23 ( V_4 -> V_49 ) )
F_24 ( V_4 -> V_49 , V_48 ) ;
return 0 ;
}
static int F_25 ( struct V_9 * V_50 )
{
struct V_51 * V_52 = F_26 ( & V_50 -> V_53 ) ;
struct V_54 * V_55 = V_50 -> V_53 . V_56 ;
struct V_57 * V_6 ;
struct V_3 * V_4 ;
int V_58 ;
if ( ! V_55 && ! V_52 ) {
F_7 ( L_10 ) ;
return - V_59 ;
}
V_6 = F_27 () ;
if ( F_28 ( V_6 ) )
return F_29 ( V_6 ) ;
V_4 = V_6 -> V_60 ;
F_30 ( V_6 , & V_50 -> V_53 ) ;
F_31 ( V_50 , V_4 ) ;
V_4 -> V_10 = V_50 ;
V_4 -> V_61 = & V_62 ;
V_50 -> V_63 = 32 ;
V_58 = F_32 ( V_50 ) ;
if ( V_58 < 0 ) {
F_7 ( L_11 ) ;
goto V_64;
}
if ( V_55 ) {
V_4 -> V_65 = F_33 ( V_55 , L_12 ) ;
V_4 -> V_49 = F_34 ( V_55 , L_13 , 0 ) ;
} else if ( V_52 ) {
V_4 -> V_49 = V_52 -> V_49 ;
V_4 -> V_65 = V_52 -> V_65 ;
}
if ( V_4 -> V_49 == - V_66 ) {
V_58 = - V_66 ;
goto V_64;
}
if ( F_23 ( V_4 -> V_49 ) ) {
V_58 = F_35 ( & V_50 -> V_53 , V_4 -> V_49 ,
V_67 , L_14 ) ;
if ( V_58 ) {
F_7 ( L_15 , V_58 ) ;
goto V_64;
}
} else {
F_7 ( L_16 ) ;
V_58 = - V_59 ;
goto V_64;
}
V_4 -> V_1 = V_50 -> V_1 ;
if ( V_4 -> V_1 < 0 ) {
F_7 ( L_17 ) ;
V_58 = - V_59 ;
goto V_64;
}
F_36 ( V_4 -> V_1 , V_68 ) ;
V_58 = F_37 ( & V_50 -> V_53 , V_4 -> V_1 , F_1 , 0 ,
V_69 , V_4 ) ;
if ( V_58 < 0 ) {
F_7 ( L_18 , V_58 ) ;
goto V_64;
}
F_38 ( V_4 -> V_1 , V_70 ) ;
V_4 -> V_71 = F_39 ( & V_50 -> V_53 , L_19 ) ;
if ( F_28 ( V_4 -> V_71 ) ) {
V_58 = F_29 ( V_4 -> V_71 ) ;
F_7 ( L_20 , V_58 ) ;
goto V_64;
}
V_58 = F_40 ( V_4 -> V_71 ) ;
if ( V_58 )
goto V_64;
V_58 = F_41 ( V_4 ) ;
if ( V_58 )
goto V_72;
return 0 ;
V_72:
F_42 ( V_4 -> V_71 ) ;
V_64:
F_43 ( V_6 ) ;
return V_58 ;
}
static int F_44 ( struct V_9 * V_50 )
{
struct V_3 * V_4 = F_45 ( V_50 ) ;
F_46 ( V_4 -> V_1 , V_4 ) ;
F_47 ( V_4 ) ;
F_42 ( V_4 -> V_71 ) ;
return 0 ;
}
