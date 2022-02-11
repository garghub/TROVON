T_1 long F_1 ( int V_1 , int V_2 , int V_3 , int V_4 ,
int V_5 , int V_6 , int V_7 )
{
F_2 ( V_8 L_1 ,
V_9 -> V_10 , V_9 -> V_11 , V_7 ) ;
return - V_12 ;
}
T_1 long F_3 ( T_2 V_11 ,
struct V_13 T_3 * V_14 )
{
struct V_15 V_16 ;
int V_17 ;
F_4 ( V_17 , V_18 , V_11 , (struct V_15 T_3 * ) & V_16 ) ;
if ( F_5 ( & V_16 , V_14 ) )
return - V_19 ;
return V_17 ;
}
T_1 long F_6 ( int V_20 ,
struct V_21 T_3 * V_22 ,
T_4 V_23 , int V_24 )
{
struct V_25 * V_26 ;
struct V_21 V_27 ;
int V_28 ;
if ( ( V_26 = F_7 ( V_23 + sizeof *V_26 + 4 , V_29 ) ) == NULL )
return - V_30 ;
V_28 = F_8 ( V_27 . V_31 , & V_22 -> V_31 ) ;
V_26 -> V_31 = V_27 . V_31 ;
V_28 |= F_9 ( V_26 -> V_32 , & V_22 -> V_32 , V_23 ) ;
if ( V_28 )
V_28 = - V_19 ;
else
F_4 ( V_28 , V_33 , V_20 , (struct V_25 T_3 * ) V_26 , V_23 , V_24 ) ;
F_10 ( V_26 ) ;
return V_28 ;
}
T_1 long F_11 ( int V_20 ,
struct V_21 T_3 * V_22 ,
T_4 V_23 , long V_34 , int V_24 )
{
struct V_25 * V_26 ;
struct V_21 V_27 ;
int V_28 , V_35 ;
if ( ( V_26 = F_7 ( V_23 + sizeof *V_26 + 4 , V_29 ) ) == NULL )
return - V_30 ;
F_4 ( V_28 , V_36 , V_20 , (struct V_25 T_3 * ) V_26 , V_23 , V_34 , V_24 ) ;
if ( V_28 >= 0 ) {
V_35 = V_28 ;
V_27 . V_31 = V_26 -> V_31 ;
V_28 = F_12 ( V_27 . V_31 , & V_22 -> V_31 ) ;
V_28 |= F_13 ( & V_22 -> V_32 , V_26 -> V_32 , V_35 ) ;
if ( V_28 )
V_28 = - V_19 ;
else
V_28 = V_35 ;
}
F_10 ( V_26 ) ;
return V_28 ;
}
T_1 int F_14 ( int V_37 , int V_38 , T_5 T_3 * V_39 , T_6 V_40 )
{
T_7 V_41 = F_15 () ;
int V_17 ;
T_8 V_42 ;
if ( V_39 && F_8 ( V_42 , V_39 ) )
return - V_19 ;
F_16 ( V_43 ) ;
V_17 = F_17 ( V_37 , V_38 , V_39 ? ( T_8 T_3 * ) & V_42 : NULL , V_40 ) ;
F_16 ( V_41 ) ;
if ( V_39 && F_12 ( V_42 , V_39 ) )
return - V_19 ;
return V_17 ;
}
T_1 int F_18 ( int V_37 , int V_38 , T_9 T_3 * V_39 , T_6 V_40 )
{
T_7 V_41 = F_15 () ;
int V_17 ;
T_10 V_44 ;
if ( V_39 && F_8 ( V_44 , V_39 ) )
return - V_19 ;
F_16 ( V_43 ) ;
V_17 = F_19 ( V_37 , V_38 , V_39 ? ( T_10 T_3 * ) & V_44 : NULL , V_40 ) ;
F_16 ( V_41 ) ;
if ( V_39 && F_12 ( V_44 , V_39 ) )
return - V_19 ;
return V_17 ;
}
T_1 int F_20 ( unsigned int V_45 , int V_39 , unsigned int V_46 )
{
return F_21 ( V_45 , V_39 , V_46 ) ;
}
T_1 long F_22 ( int V_47 , int V_48 , int V_49 , union V_50 V_51 )
{
union V_50 V_52 ;
if ( V_49 == V_53 ) {
V_52 . V_54 = * ( ( int * ) & V_51 + 1 ) ;
return F_23 ( V_47 , V_48 , V_49 , V_52 ) ;
}
return F_23 ( V_47 , V_48 , V_49 , V_51 ) ;
}
long F_24 ( T_11 V_55 , T_11 V_56 , char T_3 * V_57 ,
T_4 V_35 )
{
return F_25 ( ( V_58 ) V_55 << 32 | V_56 ,
V_57 , V_35 ) ;
}
T_1 long F_26 ( int V_45 , int V_59 , T_11 V_60 , T_11 V_61 ,
T_11 V_62 , T_11 V_63 )
{
return F_27 ( V_45 , V_59 , ( ( T_10 ) V_60 << 32 ) | V_61 ,
( ( T_10 ) V_62 << 32 ) | V_63 ) ;
}
T_1 long F_28 ( int V_64 , int V_65 , T_11 V_66 ,
T_11 V_67 , int V_45 ,
const char T_3 * V_68 )
{
return F_29 ( V_64 , V_65 , ( ( V_58 ) V_66 << 32 ) | V_67 ,
V_45 , V_68 ) ;
}
