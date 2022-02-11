static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 -> V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = (struct V_7 * ) V_1 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_11 ;
BOOLEAN V_12 = FALSE ;
struct V_10 * V_13 = F_2 ( V_14 ) ;
if ( F_3 ( F_4 ( V_13 ) ) )
F_5 ( V_15 L_1 , V_13 -> V_16 -> V_17 , V_1 -> V_18 ) ;
if( V_1 -> V_18 != V_19 )
{
if( V_1 -> V_18 == - V_20 )
{
V_6 -> V_11 -> V_21 = TRUE ;
F_6 ( & V_6 -> V_11 -> V_22 ) ;
}
else
{
F_7 ( V_13 , V_23 , V_24 , V_25 , L_2 , V_1 -> V_18 ) ;
}
}
V_3 -> V_26 = FALSE ;
F_8 ( & V_6 -> V_27 ) ;
if( TRUE == V_11 -> V_28 )
{
if( ( ( V_8 -> V_29 [ 0 ] == V_30 ) &&
( V_8 -> V_29 [ 1 ] == V_31 ) ) )
{
V_12 = TRUE ;
if( V_1 -> V_18 != V_19 )
{
V_11 -> V_28 = FALSE ;
F_7 ( V_13 , V_23 , V_24 , V_25 , L_3 ) ;
F_6 ( & V_11 -> V_32 ) ;
F_9 ( V_6 ) ;
goto V_33;
}
if( V_11 -> V_34 == FALSE )
{
V_11 -> V_35 = TRUE ;
V_11 -> V_28 = FALSE ;
F_7 ( V_13 , V_23 , V_24 , V_25 , L_4 ) ;
F_6 ( & V_11 -> V_32 ) ;
}
}
else if( ( V_8 -> V_36 . V_37 == V_38 ) &&
( V_8 -> V_29 [ 0 ] == V_39 ) &&
( V_8 -> V_29 [ 1 ] == V_40 ) &&
( V_8 -> V_29 [ 2 ] == V_41 ) )
{
if( V_1 -> V_18 != V_19 )
{
V_11 -> V_28 = FALSE ;
F_7 ( V_13 , V_23 , V_24 , V_25 , L_5 ) ;
F_6 ( & V_11 -> V_32 ) ;
F_9 ( V_6 ) ;
goto V_33;
}
V_12 = TRUE ;
if( V_11 -> V_34 == FALSE )
{
V_11 -> V_42 = TRUE ;
V_11 -> V_28 = FALSE ;
F_7 ( V_13 , V_23 , V_24 , V_25 , L_6 ) ;
F_6 ( & V_11 -> V_32 ) ;
}
}
if( V_11 -> V_34 && V_12 )
{
F_7 ( V_13 , V_23 , V_24 , V_25 , L_7 ) ;
V_6 -> V_43 = TRUE ;
F_10 ( & V_6 -> V_44 ) ;
}
}
V_33 :
F_11 ( V_1 -> V_16 , V_1 -> V_45 ,
V_1 -> V_9 , V_1 -> V_46 ) ;
}
static struct V_2 * F_12 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = NULL ;
T_1 V_47 = 0 ;
if( ( F_13 ( & V_6 -> V_27 ) < V_48 ) &&
( V_6 -> V_11 -> V_49 == FALSE ) )
{
V_47 = F_13 ( & V_6 -> V_50 ) ;
V_3 = & V_6 -> V_51 [ V_47 ] ;
V_3 -> V_26 = TRUE ;
V_3 -> V_6 = V_6 ;
F_7 ( V_6 -> V_11 , V_23 , V_24 , V_25 , L_8 ,
V_47 , F_13 ( & V_6 -> V_27 ) ) ;
V_47 = ( V_47 + 1 ) % V_48 ;
F_14 ( & V_6 -> V_50 , V_47 ) ;
F_15 ( & V_6 -> V_27 ) ;
}
return V_3 ;
}
static int F_16 ( struct V_5 * V_6 , struct V_2 * V_3 , T_2 V_52 , int V_53 )
{
struct V_1 * V_1 = V_3 -> V_1 ;
int V_54 = 0 ;
V_1 -> V_9 = F_17 ( V_6 -> V_55 , V_53 ,
V_56 , & V_1 -> V_46 ) ;
if ( ! V_1 -> V_9 )
{
F_7 ( V_6 -> V_11 , V_57 , 0 , 0 , L_9 ) ;
return - V_58 ;
}
memcpy ( V_1 -> V_9 , V_52 , V_53 ) ;
V_1 -> V_45 = V_53 ;
F_7 ( V_6 -> V_11 , V_23 , V_24 , V_25 , L_10 ) ;
if( ( V_6 -> V_11 -> V_59 == V_60 ) && ( V_6 -> V_61 == TRUE ) )
{
F_18 ( V_1 , V_6 -> V_55 ,
V_6 -> V_62 . V_63 ,
V_1 -> V_9 , V_53 , F_1 , V_3 ,
V_6 -> V_62 . V_64 ) ;
}
else
{
F_19 ( V_1 , V_6 -> V_55 ,
V_6 -> V_62 . V_63 ,
V_1 -> V_9 , V_53 , F_1 , V_3 ) ;
}
V_1 -> V_65 |= V_66 ;
if( FALSE == V_6 -> V_11 -> V_67 &&
FALSE == V_6 -> V_11 -> V_21 &&
FALSE == V_6 -> V_68 &&
FALSE == V_6 -> V_43 )
{
V_54 = F_20 ( V_1 , V_56 ) ;
if ( V_54 )
{
F_7 ( V_6 -> V_11 , V_23 , V_24 , V_25 , L_11 , V_54 ) ;
if( V_54 == - V_20 )
{
V_6 -> V_11 -> V_21 = TRUE ;
F_6 ( & V_6 -> V_11 -> V_22 ) ;
}
}
}
return V_54 ;
}
int F_21 ( T_2 V_69 , T_2 V_52 , T_1 V_53 )
{
struct V_2 * V_3 = NULL ;
struct V_5 * V_6 = (struct V_5 * ) V_69 ;
V_3 = F_12 ( V_6 ) ;
if( V_3 == NULL )
{
F_7 ( V_6 -> V_11 , V_57 , 0 , 0 , L_12 ) ;
return - V_70 ;
}
return F_16 ( V_6 , V_3 , V_52 , V_53 ) ;
}
