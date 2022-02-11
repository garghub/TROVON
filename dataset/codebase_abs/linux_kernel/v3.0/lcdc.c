static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
F_3 ( V_5 ) ;
if ( V_6 && V_6 -> V_7 )
V_6 -> V_7 ( 0 ) ;
if ( V_6 && V_6 -> V_8 )
V_3 = V_6 -> V_8 ( 0 ) ;
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_9 * V_10 ;
unsigned long V_11 , V_12 ;
V_10 = F_5 ( V_2 ) ;
V_11 = V_10 -> V_13 -> V_14 . V_15 ;
if ( V_11 > 58000000 )
V_12 = V_11 / 1000 ;
else
V_12 = 58000 ;
V_10 = F_5 ( V_2 ) ;
F_6 ( V_4 ) ;
F_6 ( V_5 ) ;
if ( V_6 && V_6 -> V_7 )
V_6 -> V_7 ( 1 ) ;
if ( V_6 && V_6 -> V_8 )
V_3 = V_6 -> V_8 ( 1 ) ;
F_7 ( V_4 , V_10 -> V_13 -> V_14 . V_15 ) ;
F_7 ( V_5 , V_10 -> V_13 -> V_14 . V_15 ) ;
V_16 = F_8 ( V_4 ) ;
V_17 = F_8 ( V_5 ) ;
V_3 = F_9 ( V_2 ) ;
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_18 * V_13 ;
struct V_1 * V_19 = NULL ;
struct V_20 * V_21 = NULL ;
int V_22 ;
if ( V_2 -> V_23 == 0 ) {
V_6 = V_2 -> V_24 . V_25 ;
return 0 ;
}
V_10 = F_5 ( V_2 ) ;
if ( ! V_10 )
return - V_26 ;
if ( V_10 -> V_27 != V_28 )
return - V_29 ;
if ( V_30 >= V_31 )
return - V_32 ;
V_19 = F_11 ( L_1 , V_2 -> V_23 ) ;
if ( ! V_19 )
return - V_32 ;
V_10 -> V_2 = V_19 ;
V_10 -> V_33 = V_34 ;
if ( F_12
( V_19 , V_2 -> V_24 . V_25 ,
sizeof( struct V_20 ) ) ) {
F_13 ( V_35 L_2 ) ;
F_14 ( V_19 ) ;
return - V_32 ;
}
V_21 = (struct V_20 * ) V_19 -> V_24 . V_25 ;
V_21 -> V_36 = F_4 ;
V_21 -> V_37 = F_1 ;
V_21 -> V_38 = V_2 ;
V_10 -> V_39 = V_21 -> V_39 ;
V_10 -> V_40 = V_41 ;
V_13 = V_10 -> V_13 ;
V_13 -> V_14 . V_15 = V_10 -> V_39 . V_42 ;
V_13 -> V_14 . V_43 = V_10 -> V_39 . V_44 . V_45 ;
V_13 -> V_14 . V_46 = V_10 -> V_39 . V_44 . V_47 ;
V_13 -> V_14 . V_48 = V_10 -> V_39 . V_44 . V_49 ;
V_13 -> V_14 . V_50 = V_10 -> V_39 . V_44 . V_51 ;
V_13 -> V_14 . V_52 = V_10 -> V_39 . V_44 . V_53 ;
V_13 -> V_14 . V_54 = V_10 -> V_39 . V_44 . V_55 ;
F_15 ( V_19 , V_10 ) ;
V_22 = F_16 ( V_19 ) ;
if ( V_22 )
goto V_56;
V_57 [ V_30 ++ ] = V_2 ;
return 0 ;
V_56:
F_14 ( V_19 ) ;
return V_22 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_18 ( void )
{
return F_19 ( & V_58 ) ;
}
static int T_1 F_20 ( void )
{
V_4 = F_21 ( NULL , L_3 ) ;
if ( F_22 ( V_4 ) ) {
F_13 ( V_35 L_4 ) ;
return F_23 ( V_4 ) ;
}
V_5 = F_21 ( NULL , L_5 ) ;
if ( F_22 ( V_5 ) ) {
F_13 ( V_35 L_6 ) ;
return F_23 ( V_5 ) ;
}
return F_18 () ;
}
