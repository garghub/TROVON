static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
T_2 V_6 ;
V_6 = F_4 ( V_7 ) >> V_4 -> V_8 ;
V_6 >>= V_4 -> V_8 ;
V_6 &= V_4 -> V_9 ;
if ( V_6 >= V_5 )
return - V_10 ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( ( V_4 -> V_9 << V_4 -> V_8 ) ,
( V_11 << V_4 -> V_8 ) ) ;
return 0 ;
}
static struct V_12 * F_7 ( struct V_13 * V_14 , const char * V_15 ,
const char * * V_16 , T_1 V_5 ,
T_1 V_8 , T_2 V_9 )
{
struct V_3 * V_4 ;
struct V_12 * V_12 ;
struct V_17 V_18 ;
V_4 = F_8 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return F_9 ( - V_20 ) ;
V_18 . V_15 = V_15 ;
V_18 . V_21 = & V_22 ;
V_18 . V_23 = V_24 ;
V_18 . V_16 = V_16 ;
V_18 . V_5 = V_5 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_2 . V_18 = & V_18 ;
V_12 = F_10 ( V_14 , & V_4 -> V_2 ) ;
return V_12 ;
}
static void F_11 ( struct V_25 * V_25 ,
int V_26 , int V_27 )
{
unsigned long V_23 = 0 ;
T_2 V_28 , div , V_29 ;
F_12 ( & V_25 -> V_30 , V_23 ) ;
V_28 = F_4 ( V_25 -> V_31 ) ;
div = ( ( V_28 >> V_26 ) & V_32 ) + 1 ;
V_29 = ( ( div + 1 ) / 2 ) - 1 ;
V_28 &= ~ ( V_32 << V_27 ) ;
V_28 |= ( V_29 << V_27 ) ;
F_13 ( V_28 , V_25 -> V_31 ) ;
F_14 ( & V_25 -> V_30 , V_23 ) ;
}
static int F_15 ( struct V_33 * V_34 ,
unsigned long V_35 , void * V_36 )
{
struct V_25 * V_25 = F_16 ( V_34 ) ;
if ( V_35 == V_37 ) {
F_11 ( V_25 ,
V_38 , V_39 ) ;
}
return V_40 ;
}
static int F_17 ( struct V_33 * V_34 ,
unsigned long V_35 , void * V_36 )
{
struct V_25 * V_25 = F_18 ( V_34 ) ;
if ( V_35 == V_37 ) {
F_11 ( V_25 ,
V_41 , V_42 ) ;
}
return V_40 ;
}
static int F_19 ( struct V_13 * V_14 )
{
struct V_43 * V_44 = F_20 ( V_14 ) ;
struct V_25 * V_25 = F_21 ( V_44 ) ;
V_25 -> V_45 = F_4 ( V_25 -> V_31 ) ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 )
{
struct V_43 * V_44 = F_20 ( V_14 ) ;
struct V_25 * V_25 = F_21 ( V_44 ) ;
F_13 ( V_25 -> V_45 , V_25 -> V_31 ) ;
return 0 ;
}
static int F_23 ( struct V_43 * V_44 )
{
struct V_25 * V_25 ;
struct V_46 * V_47 ;
struct V_12 * * V_48 ;
struct V_49 * V_50 ;
int V_51 , V_52 ;
V_25 = F_24 ( & V_44 -> V_14 , sizeof( * V_25 ) ,
V_19 ) ;
if ( ! V_25 )
return - V_20 ;
V_25 -> V_14 = & V_44 -> V_14 ;
F_25 ( V_44 , V_25 ) ;
F_26 ( & V_25 -> V_30 ) ;
V_48 = F_24 ( & V_44 -> V_14 ,
sizeof( struct V_12 * ) * V_53 ,
V_19 ) ;
if ( ! V_48 )
return - V_20 ;
V_25 -> V_54 . V_55 = V_48 ;
V_25 -> V_54 . V_56 = V_53 ;
V_47 = F_27 ( V_44 , V_57 , 0 ) ;
V_25 -> V_31 = F_28 ( & V_44 -> V_14 , V_47 ) ;
if ( F_29 ( V_25 -> V_31 ) )
return F_30 ( V_25 -> V_31 ) ;
V_50 = (struct V_49 * )
F_31 ( V_44 ) -> V_58 ;
V_48 [ V_59 ] = F_32 ( & V_44 -> V_14 , L_1 ,
V_50 -> V_60 ,
V_50 -> V_61 , 0 ,
V_25 -> V_31 , 1 , 1 , 0 ,
& V_25 -> V_30 ) ;
V_48 [ V_62 ] = F_32 ( & V_44 -> V_14 , L_2 ,
V_50 -> V_60 ,
V_50 -> V_61 , 0 ,
V_25 -> V_31 , 17 , 1 , 0 ,
& V_25 -> V_30 ) ;
V_48 [ V_63 ] = F_33 ( & V_44 -> V_14 , L_3 ,
L_1 , 0 , V_25 -> V_31 ,
4 , 4 , 0 , & V_25 -> V_30 ) ;
V_48 [ V_64 ] = F_33 ( & V_44 -> V_14 , L_4 ,
L_2 , 0 , V_25 -> V_31 ,
20 , 4 , 0 , & V_25 -> V_30 ) ;
V_48 [ V_65 ] = F_34 ( & V_44 -> V_14 , L_5 ,
L_3 , V_66 ,
V_25 -> V_31 , 0 , 0 ,
& V_25 -> V_30 ) ;
V_48 [ V_67 ] = F_34 ( & V_44 -> V_14 , L_6 ,
L_4 , V_66 ,
V_25 -> V_31 , 16 , 0 ,
& V_25 -> V_30 ) ;
V_48 [ V_68 ] = F_7 ( & V_44 -> V_14 ,
L_7 , V_50 -> V_69 ,
V_50 -> V_70 , 4 , 7 ) ;
V_48 [ V_71 ] = F_7 ( & V_44 -> V_14 ,
L_8 , V_50 -> V_72 ,
V_50 -> V_73 , 8 , 7 ) ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ )
if ( F_29 ( V_48 [ V_52 ] ) ) {
F_35 ( & V_44 -> V_14 , L_9 , V_52 ) ;
V_51 = F_30 ( V_48 [ V_52 ] ) ;
goto V_74;
}
V_51 = F_36 ( V_48 [ V_59 ] , L_10 , NULL ) ;
if ( ! V_51 )
V_51 = F_36 ( V_48 [ V_62 ] , L_11 , NULL ) ;
if ( ! V_51 )
V_51 = F_36 ( V_48 [ V_68 ] ,
L_7 , NULL ) ;
if ( ! V_51 )
V_51 = F_36 ( V_48 [ V_71 ] ,
L_8 , NULL ) ;
if ( V_51 ) {
F_35 ( & V_44 -> V_14 , L_12 , V_51 ) ;
goto V_74;
}
V_25 -> V_75 . V_76 =
F_15 ;
V_25 -> V_77 . V_76 =
F_17 ;
V_51 = F_37 ( V_48 [ V_63 ] ,
& V_25 -> V_75 ) ;
if ( V_51 )
goto V_74;
V_51 = F_37 ( V_48 [ V_64 ] ,
& V_25 -> V_77 ) ;
if ( V_51 )
goto V_78;
return 0 ;
V_78:
F_38 ( V_48 [ V_63 ] ,
& V_25 -> V_75 ) ;
V_74:
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ )
if ( V_48 [ V_52 ] && ! F_29 ( V_48 [ V_52 ] ) )
F_39 ( V_48 [ V_52 ] ) ;
return V_51 ;
}
static int F_40 ( struct V_43 * V_44 )
{
struct V_25 * V_25 = F_21 ( V_44 ) ;
struct V_12 * * V_48 = V_25 -> V_54 . V_55 ;
int V_52 ;
F_38 ( V_48 [ V_64 ] ,
& V_25 -> V_77 ) ;
F_38 ( V_48 [ V_63 ] ,
& V_25 -> V_75 ) ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ )
F_39 ( V_48 [ V_52 ] ) ;
return 0 ;
}
