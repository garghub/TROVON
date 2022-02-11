static int F_1 ( unsigned V_1 ,
unsigned V_2 , unsigned V_3 , unsigned V_4 ,
unsigned V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
struct V_10 T_1 * V_11 = V_9 -> V_11 ;
unsigned long V_12 ;
if ( V_1 >= 256 )
return 1 ;
V_2 >>= 8 ;
V_3 >>= 8 ;
V_4 >>= 8 ;
F_2 ( & V_9 -> V_13 , V_12 ) ;
F_3 ( ( V_1 << 16 ) , & V_11 -> V_14 ) ;
F_3 ( ( V_2 << 16 ) , & V_11 -> V_15 ) ;
F_3 ( ( V_3 << 16 ) , & V_11 -> V_15 ) ;
F_3 ( ( V_4 << 16 ) , & V_11 -> V_15 ) ;
F_4 ( & V_9 -> V_13 , V_12 ) ;
return 0 ;
}
static int
F_5 ( int V_16 , struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
struct V_10 T_1 * V_11 = V_9 -> V_11 ;
unsigned long V_12 ;
T_2 V_17 ;
F_2 ( & V_9 -> V_13 , V_12 ) ;
switch ( V_16 ) {
case V_18 :
V_17 = F_6 ( & V_11 -> V_19 ) ;
V_17 |= V_20 ;
F_3 ( V_17 , & V_11 -> V_19 ) ;
V_9 -> V_12 &= ~ V_21 ;
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
V_17 = F_6 ( & V_11 -> V_19 ) ;
V_17 &= ~ V_20 ;
F_3 ( V_17 , & V_11 -> V_19 ) ;
V_9 -> V_12 |= V_21 ;
break;
}
F_4 ( & V_9 -> V_13 , V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 , struct V_26 * V_27 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
return F_8 ( V_28 ,
V_7 -> V_29 . V_30 , V_7 -> V_29 . V_31 ,
V_9 -> V_32 , V_27 ) ;
}
static int F_9 ( struct V_6 * V_7 , unsigned int V_33 ,
unsigned long V_34 )
{
return F_10 ( V_33 , V_34 , V_7 ,
V_35 , 8 , V_7 -> V_29 . V_31 ) ;
}
static void F_11 ( struct V_6 * V_7 , int V_36 , struct V_37 * V_38 )
{
F_12 ( V_7 -> V_29 . V_39 , V_38 -> V_40 , sizeof( V_7 -> V_29 . V_39 ) ) ;
V_7 -> V_29 . type = V_41 ;
V_7 -> V_29 . V_42 = V_43 ;
V_7 -> V_29 . V_44 = V_36 ;
V_7 -> V_29 . V_45 = V_46 ;
}
static int F_13 ( struct V_47 * V_48 )
{
struct V_37 * V_38 = V_48 -> V_49 . V_50 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_36 , V_51 ;
V_7 = F_14 ( sizeof( struct V_8 ) , & V_48 -> V_49 ) ;
V_51 = - V_52 ;
if ( ! V_7 )
goto V_53;
V_9 = V_7 -> V_9 ;
F_15 ( & V_9 -> V_13 ) ;
V_7 -> V_29 . V_30 = V_48 -> V_54 [ 2 ] . V_55 ;
V_9 -> V_32 = V_48 -> V_54 [ 2 ] . V_12 & V_56 ;
F_16 ( & V_7 -> V_57 , V_38 , 8 ) ;
V_7 -> V_57 . V_2 . V_58 = 8 ;
V_7 -> V_57 . V_3 . V_58 = 8 ;
V_7 -> V_57 . V_4 . V_58 = 8 ;
V_36 = F_17 ( V_38 , L_1 , V_7 -> V_57 . V_59 ) ;
V_7 -> V_29 . V_31 = F_18 ( V_36 * V_7 -> V_57 . V_60 ) ;
V_9 -> V_11 = F_19 ( & V_48 -> V_54 [ 0 ] , 0 ,
sizeof( struct V_10 ) , L_2 ) ;
if ( ! V_9 -> V_11 )
goto V_61;
V_7 -> V_12 = V_62 ;
V_7 -> V_63 = & V_64 ;
V_7 -> V_65 = F_19 ( & V_48 -> V_54 [ 2 ] , 0 ,
V_7 -> V_29 . V_31 , L_3 ) ;
if ( ! V_7 -> V_65 )
goto V_66;
F_5 ( V_18 , V_7 ) ;
if ( F_20 ( & V_7 -> V_67 , 256 , 0 ) )
goto V_68;
F_11 ( V_7 , V_36 , V_38 ) ;
V_51 = F_21 ( V_7 ) ;
if ( V_51 < 0 )
goto V_69;
F_22 ( & V_7 -> V_67 , V_7 ) ;
F_23 ( & V_48 -> V_49 , V_7 ) ;
F_24 ( V_70 L_4 ,
V_38 -> V_71 ,
V_9 -> V_32 , V_7 -> V_29 . V_30 ) ;
return 0 ;
V_69:
F_25 ( & V_7 -> V_67 ) ;
V_68:
F_26 ( & V_48 -> V_54 [ 2 ] , V_7 -> V_65 , V_7 -> V_29 . V_31 ) ;
V_66:
F_26 ( & V_48 -> V_54 [ 0 ] , V_9 -> V_11 , sizeof( struct V_10 ) ) ;
V_61:
F_27 ( V_7 ) ;
V_53:
return V_51 ;
}
static int F_28 ( struct V_47 * V_48 )
{
struct V_6 * V_7 = F_29 ( & V_48 -> V_49 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_30 ( V_7 ) ;
F_25 ( & V_7 -> V_67 ) ;
F_26 ( & V_48 -> V_54 [ 0 ] , V_9 -> V_11 , sizeof( struct V_10 ) ) ;
F_26 ( & V_48 -> V_54 [ 2 ] , V_7 -> V_65 , V_7 -> V_29 . V_31 ) ;
F_27 ( V_7 ) ;
F_23 ( & V_48 -> V_49 , NULL ) ;
return 0 ;
}
static int T_3 F_31 ( void )
{
if ( F_32 ( L_5 , NULL ) )
return - V_72 ;
return F_33 ( & V_73 ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_73 ) ;
}
