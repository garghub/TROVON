static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 -> V_6 ) ;
T_2 V_7 ;
V_7 = F_4 ( V_8 ) >> V_4 -> V_9 ;
V_7 >>= V_4 -> V_9 ;
V_7 &= V_4 -> V_10 ;
if ( V_7 >= V_5 )
return - V_11 ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_13 = 0 ;
F_6 ( ( V_4 -> V_10 << V_4 -> V_9 ) ,
( V_12 << V_4 -> V_9 ) ) ;
return V_13 ;
}
struct V_6 * F_7 ( struct V_14 * V_15 , const char * V_16 ,
const char * * V_17 , T_1 V_5 ,
T_1 V_9 , T_2 V_10 )
{
struct V_3 * V_4 ;
struct V_6 * V_6 ;
struct V_18 V_19 ;
V_4 = F_8 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
return F_9 ( - V_21 ) ;
V_19 . V_16 = V_16 ;
V_19 . V_22 = & V_23 ;
V_19 . V_24 = V_25 ;
V_19 . V_17 = V_17 ;
V_19 . V_5 = V_5 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_2 . V_19 = & V_19 ;
V_6 = F_10 ( V_15 , & V_4 -> V_2 ) ;
return V_6 ;
}
static void F_11 ( struct V_26 * V_26 ,
int V_27 , int V_28 )
{
unsigned long V_24 = 0 ;
T_2 V_29 , div , V_30 ;
F_12 ( & V_26 -> V_31 , V_24 ) ;
V_29 = F_4 ( V_26 -> V_32 ) ;
div = ( ( V_29 >> V_27 ) & V_33 ) + 1 ;
V_30 = ( ( div + 1 ) / 2 ) - 1 ;
V_29 &= ~ ( V_33 << V_28 ) ;
V_29 |= ( V_30 << V_28 ) ;
F_13 ( V_29 , V_26 -> V_32 ) ;
F_14 ( & V_26 -> V_31 , V_24 ) ;
}
static int F_15 ( struct V_34 * V_35 ,
unsigned long V_36 , void * V_37 )
{
struct V_26 * V_26 = F_16 ( V_35 ) ;
if ( V_36 == V_38 ) {
F_11 ( V_26 ,
V_39 , V_40 ) ;
}
return V_41 ;
}
static int F_17 ( struct V_34 * V_35 ,
unsigned long V_36 , void * V_37 )
{
struct V_26 * V_26 = F_18 ( V_35 ) ;
if ( V_36 == V_38 ) {
F_11 ( V_26 ,
V_42 , V_43 ) ;
}
return V_41 ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_44 * V_45 = F_20 ( V_15 ) ;
struct V_26 * V_26 = F_21 ( V_45 ) ;
V_26 -> V_46 = F_4 ( V_26 -> V_32 ) ;
return 0 ;
}
static int F_22 ( struct V_14 * V_15 )
{
struct V_44 * V_45 = F_20 ( V_15 ) ;
struct V_26 * V_26 = F_21 ( V_45 ) ;
F_13 ( V_26 -> V_46 , V_26 -> V_32 ) ;
return 0 ;
}
static int F_23 ( struct V_44 * V_45 )
{
struct V_26 * V_26 ;
struct V_47 * V_48 ;
struct V_6 * * V_49 ;
struct V_50 * V_51 ;
int V_13 , V_52 ;
V_26 = F_24 ( & V_45 -> V_15 , sizeof( * V_26 ) ,
V_20 ) ;
if ( ! V_26 )
return - V_21 ;
V_26 -> V_15 = & V_45 -> V_15 ;
F_25 ( V_45 , V_26 ) ;
F_26 ( & V_26 -> V_31 ) ;
V_49 = F_24 ( & V_45 -> V_15 ,
sizeof( struct V_6 * ) * V_53 ,
V_20 ) ;
if ( ! V_49 )
return - V_21 ;
V_26 -> V_54 . V_55 = V_49 ;
V_26 -> V_54 . V_56 = V_53 ;
V_48 = F_27 ( V_45 , V_57 , 0 ) ;
V_26 -> V_32 = F_28 ( & V_45 -> V_15 , V_48 ) ;
if ( F_29 ( V_26 -> V_32 ) )
return F_30 ( V_26 -> V_32 ) ;
V_51 = (struct V_50 * )
F_31 ( V_45 ) -> V_58 ;
V_49 [ V_59 ] = F_32 ( & V_45 -> V_15 , L_1 ,
V_51 -> V_60 ,
V_51 -> V_61 , 0 ,
V_26 -> V_32 , 1 , 1 , 0 ,
& V_26 -> V_31 ) ;
V_49 [ V_62 ] = F_32 ( & V_45 -> V_15 , L_2 ,
V_51 -> V_60 ,
V_51 -> V_61 , 0 ,
V_26 -> V_32 , 17 , 1 , 0 ,
& V_26 -> V_31 ) ;
V_49 [ V_63 ] = F_33 ( & V_45 -> V_15 , L_3 ,
L_1 , 0 , V_26 -> V_32 ,
4 , 4 , 0 , & V_26 -> V_31 ) ;
V_49 [ V_64 ] = F_33 ( & V_45 -> V_15 , L_4 ,
L_2 , 0 , V_26 -> V_32 ,
20 , 4 , 0 , & V_26 -> V_31 ) ;
V_49 [ V_65 ] = F_34 ( & V_45 -> V_15 , L_5 ,
L_3 , V_66 ,
V_26 -> V_32 , 0 , 0 ,
& V_26 -> V_31 ) ;
V_49 [ V_67 ] = F_34 ( & V_45 -> V_15 , L_6 ,
L_4 , V_66 ,
V_26 -> V_32 , 16 , 0 ,
& V_26 -> V_31 ) ;
V_49 [ V_68 ] = F_7 ( & V_45 -> V_15 ,
L_7 , V_51 -> V_69 ,
V_51 -> V_70 , 4 , 7 ) ;
V_49 [ V_71 ] = F_7 ( & V_45 -> V_15 ,
L_8 , V_51 -> V_72 ,
V_51 -> V_73 , 8 , 7 ) ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ )
if ( F_29 ( V_49 [ V_52 ] ) ) {
F_35 ( & V_45 -> V_15 , L_9 , V_52 ) ;
V_13 = F_30 ( V_49 [ V_52 ] ) ;
goto V_74;
}
V_13 = F_36 ( V_49 [ V_59 ] , L_10 , NULL ) ;
if ( ! V_13 )
V_13 = F_36 ( V_49 [ V_62 ] , L_11 , NULL ) ;
if ( ! V_13 )
V_13 = F_36 ( V_49 [ V_68 ] ,
L_7 , NULL ) ;
if ( ! V_13 )
V_13 = F_36 ( V_49 [ V_71 ] ,
L_8 , NULL ) ;
if ( V_13 ) {
F_35 ( & V_45 -> V_15 , L_12 , V_13 ) ;
goto V_74;
}
V_26 -> V_75 . V_76 =
F_15 ;
V_26 -> V_77 . V_76 =
F_17 ;
V_13 = F_37 ( V_49 [ V_63 ] ,
& V_26 -> V_75 ) ;
if ( V_13 )
goto V_74;
V_13 = F_37 ( V_49 [ V_64 ] ,
& V_26 -> V_77 ) ;
if ( V_13 )
goto V_78;
return 0 ;
V_78:
F_38 ( V_49 [ V_63 ] ,
& V_26 -> V_75 ) ;
V_74:
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ )
if ( V_49 [ V_52 ] && ! F_29 ( V_49 [ V_52 ] ) )
F_39 ( V_49 [ V_52 ] ) ;
return V_13 ;
}
static int F_40 ( struct V_44 * V_45 )
{
struct V_26 * V_26 = F_21 ( V_45 ) ;
struct V_6 * * V_49 = V_26 -> V_54 . V_55 ;
int V_52 ;
F_38 ( V_49 [ V_64 ] ,
& V_26 -> V_77 ) ;
F_38 ( V_49 [ V_63 ] ,
& V_26 -> V_75 ) ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ )
F_39 ( V_49 [ V_52 ] ) ;
return 0 ;
}
