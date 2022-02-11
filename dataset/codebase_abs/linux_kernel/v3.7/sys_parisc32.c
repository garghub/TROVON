T_1 int F_1 ( struct V_1 * V_2 )
{
int error ;
struct V_3 * V_3 ;
F_2 ( ( L_1 , V_2 , V_2 -> V_4 [ 26 ] ) ) ;
V_3 = F_3 ( ( const char V_5 * ) V_2 -> V_4 [ 26 ] ) ;
error = F_4 ( V_3 ) ;
if ( F_5 ( V_3 ) )
goto V_6;
error = F_6 ( V_3 -> V_7 , F_7 ( V_2 -> V_4 [ 25 ] ) ,
F_7 ( V_2 -> V_4 [ 24 ] ) , V_2 ) ;
F_8 ( V_3 ) ;
V_6:
return error ;
}
T_1 long F_9 ( int V_8 , int V_9 , int V_10 , int V_11 ,
int V_12 , int V_13 , int V_14 )
{
F_10 ( V_15 L_2 ,
V_16 -> V_17 , V_16 -> V_18 , V_14 ) ;
return - V_19 ;
}
T_1 long F_11 ( T_2 V_18 ,
struct V_20 V_5 * V_21 )
{
struct V_22 V_23 ;
int V_24 ;
F_12 ( V_24 , V_25 , V_18 , (struct V_22 V_5 * ) & V_23 ) ;
if ( F_13 ( & V_23 , V_21 ) )
return - V_26 ;
return V_24 ;
}
T_1 long F_14 ( int V_27 ,
struct V_28 V_5 * V_29 ,
T_3 V_30 , int V_31 )
{
struct V_32 * V_33 ;
struct V_28 V_34 ;
int V_35 ;
if ( ( V_33 = F_15 ( V_30 + sizeof *V_33 + 4 , V_36 ) ) == NULL )
return - V_37 ;
V_35 = F_16 ( V_34 . V_38 , & V_29 -> V_38 ) ;
V_33 -> V_38 = V_34 . V_38 ;
V_35 |= F_17 ( V_33 -> V_39 , & V_29 -> V_39 , V_30 ) ;
if ( V_35 )
V_35 = - V_26 ;
else
F_12 ( V_35 , V_40 , V_27 , (struct V_32 V_5 * ) V_33 , V_30 , V_31 ) ;
F_18 ( V_33 ) ;
return V_35 ;
}
T_1 long F_19 ( int V_27 ,
struct V_28 V_5 * V_29 ,
T_3 V_30 , long V_41 , int V_31 )
{
struct V_32 * V_33 ;
struct V_28 V_34 ;
int V_35 , V_42 ;
if ( ( V_33 = F_15 ( V_30 + sizeof *V_33 + 4 , V_36 ) ) == NULL )
return - V_37 ;
F_12 ( V_35 , V_43 , V_27 , (struct V_32 V_5 * ) V_33 , V_30 , V_41 , V_31 ) ;
if ( V_35 >= 0 ) {
V_42 = V_35 ;
V_34 . V_38 = V_33 -> V_38 ;
V_35 = F_20 ( V_34 . V_38 , & V_29 -> V_38 ) ;
V_35 |= F_21 ( & V_29 -> V_39 , V_33 -> V_39 , V_42 ) ;
if ( V_35 )
V_35 = - V_26 ;
else
V_35 = V_42 ;
}
F_18 ( V_33 ) ;
return V_35 ;
}
T_1 int F_22 ( int V_44 , int V_45 , T_4 V_5 * V_46 , T_5 V_47 )
{
T_6 V_48 = F_23 () ;
int V_24 ;
T_7 V_49 ;
if ( V_46 && F_16 ( V_49 , V_46 ) )
return - V_26 ;
F_24 ( V_50 ) ;
V_24 = F_25 ( V_44 , V_45 , V_46 ? ( T_7 V_5 * ) & V_49 : NULL , V_47 ) ;
F_24 ( V_48 ) ;
if ( V_46 && F_20 ( V_49 , V_46 ) )
return - V_26 ;
return V_24 ;
}
T_1 int F_26 ( int V_44 , int V_45 , T_8 V_5 * V_46 , T_5 V_47 )
{
T_6 V_48 = F_23 () ;
int V_24 ;
T_9 V_51 ;
if ( V_46 && F_16 ( V_51 , V_46 ) )
return - V_26 ;
F_24 ( V_50 ) ;
V_24 = F_27 ( V_44 , V_45 , V_46 ? ( T_9 V_5 * ) & V_51 : NULL , V_47 ) ;
F_24 ( V_48 ) ;
if ( V_46 && F_20 ( V_51 , V_46 ) )
return - V_26 ;
return V_24 ;
}
T_1 int F_28 ( unsigned int V_52 , int V_46 , unsigned int V_53 )
{
return F_29 ( V_52 , V_46 , V_53 ) ;
}
T_1 long F_30 ( int V_54 , int V_55 , int V_56 , union V_57 V_58 )
{
union V_57 V_59 ;
if ( V_56 == V_60 ) {
V_59 . V_61 = * ( ( int * ) & V_58 + 1 ) ;
return F_31 ( V_54 , V_55 , V_56 , V_59 ) ;
}
return F_31 ( V_54 , V_55 , V_56 , V_58 ) ;
}
long F_32 ( T_10 V_62 , T_10 V_63 , char V_5 * V_64 ,
T_3 V_42 )
{
return F_33 ( ( V_65 ) V_62 << 32 | V_63 ,
V_64 , V_42 ) ;
}
T_1 long F_34 ( int V_52 , int V_66 , T_10 V_67 , T_10 V_68 ,
T_10 V_69 , T_10 V_70 )
{
return F_35 ( V_52 , V_66 , ( ( T_9 ) V_67 << 32 ) | V_68 ,
( ( T_9 ) V_69 << 32 ) | V_70 ) ;
}
T_1 long F_36 ( int V_71 , int V_72 , T_10 V_73 ,
T_10 V_74 , int V_52 ,
const char V_5 * V_75 )
{
return F_37 ( V_71 , V_72 , ( ( V_65 ) V_73 << 32 ) | V_74 ,
V_52 , V_75 ) ;
}
