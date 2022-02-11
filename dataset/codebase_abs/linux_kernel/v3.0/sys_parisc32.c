T_1 int F_1 ( struct V_1 * V_2 )
{
int error ;
char * V_3 ;
F_2 ( ( L_1 , V_2 , V_2 -> V_4 [ 26 ] ) ) ;
V_3 = F_3 ( ( const char V_5 * ) V_2 -> V_4 [ 26 ] ) ;
error = F_4 ( V_3 ) ;
if ( F_5 ( V_3 ) )
goto V_6;
error = F_6 ( V_3 , F_7 ( V_2 -> V_4 [ 25 ] ) ,
F_7 ( V_2 -> V_4 [ 24 ] ) , V_2 ) ;
F_8 ( V_3 ) ;
V_6:
return error ;
}
T_1 long F_9 ( int V_7 , int V_8 , int V_9 , int V_10 ,
int V_11 , int V_12 , int V_13 )
{
F_10 ( V_14 L_2 ,
V_15 -> V_16 , V_15 -> V_17 , V_13 ) ;
return - V_18 ;
}
T_1 long F_11 ( T_2 V_17 ,
struct V_19 V_5 * V_20 )
{
struct V_21 V_22 ;
int V_23 ;
F_12 ( V_23 , V_24 , V_17 , (struct V_21 V_5 * ) & V_22 ) ;
if ( F_13 ( & V_22 , V_20 ) )
return - V_25 ;
return V_23 ;
}
T_1 long F_14 ( int V_26 ,
struct V_27 V_5 * V_28 ,
T_3 V_29 , int V_30 )
{
struct V_31 * V_32 ;
struct V_27 V_33 ;
int V_34 ;
if ( ( V_32 = F_15 ( V_29 + sizeof *V_32 + 4 , V_35 ) ) == NULL )
return - V_36 ;
V_34 = F_16 ( V_33 . V_37 , & V_28 -> V_37 ) ;
V_32 -> V_37 = V_33 . V_37 ;
V_34 |= F_17 ( V_32 -> V_38 , & V_28 -> V_38 , V_29 ) ;
if ( V_34 )
V_34 = - V_25 ;
else
F_12 ( V_34 , V_39 , V_26 , (struct V_31 V_5 * ) V_32 , V_29 , V_30 ) ;
F_18 ( V_32 ) ;
return V_34 ;
}
T_1 long F_19 ( int V_26 ,
struct V_27 V_5 * V_28 ,
T_3 V_29 , long V_40 , int V_30 )
{
struct V_31 * V_32 ;
struct V_27 V_33 ;
int V_34 , V_41 ;
if ( ( V_32 = F_15 ( V_29 + sizeof *V_32 + 4 , V_35 ) ) == NULL )
return - V_36 ;
F_12 ( V_34 , V_42 , V_26 , (struct V_31 V_5 * ) V_32 , V_29 , V_40 , V_30 ) ;
if ( V_34 >= 0 ) {
V_41 = V_34 ;
V_33 . V_37 = V_32 -> V_37 ;
V_34 = F_20 ( V_33 . V_37 , & V_28 -> V_37 ) ;
V_34 |= F_21 ( & V_28 -> V_38 , V_32 -> V_38 , V_41 ) ;
if ( V_34 )
V_34 = - V_25 ;
else
V_34 = V_41 ;
}
F_18 ( V_32 ) ;
return V_34 ;
}
T_1 int F_22 ( int V_43 , int V_44 , T_4 V_5 * V_45 , T_5 V_46 )
{
T_6 V_47 = F_23 () ;
int V_23 ;
T_7 V_48 ;
if ( V_45 && F_16 ( V_48 , V_45 ) )
return - V_25 ;
F_24 ( V_49 ) ;
V_23 = F_25 ( V_43 , V_44 , V_45 ? ( T_7 V_5 * ) & V_48 : NULL , V_46 ) ;
F_24 ( V_47 ) ;
if ( V_45 && F_20 ( V_48 , V_45 ) )
return - V_25 ;
return V_23 ;
}
T_1 int F_26 ( int V_43 , int V_44 , T_8 V_5 * V_45 , T_5 V_46 )
{
T_6 V_47 = F_23 () ;
int V_23 ;
T_9 V_50 ;
if ( V_45 && F_16 ( V_50 , V_45 ) )
return - V_25 ;
F_24 ( V_49 ) ;
V_23 = F_27 ( V_43 , V_44 , V_45 ? ( T_9 V_5 * ) & V_50 : NULL , V_46 ) ;
F_24 ( V_47 ) ;
if ( V_45 && F_20 ( V_50 , V_45 ) )
return - V_25 ;
return V_23 ;
}
T_1 int F_28 ( unsigned int V_51 , int V_45 , unsigned int V_52 )
{
return F_29 ( V_51 , V_45 , V_52 ) ;
}
T_1 long F_30 ( int V_53 , int V_54 , int V_55 , union V_56 V_57 )
{
union V_56 V_58 ;
if ( V_55 == V_59 ) {
V_58 . V_60 = * ( ( int * ) & V_57 + 1 ) ;
return F_31 ( V_53 , V_54 , V_55 , V_58 ) ;
}
return F_31 ( V_53 , V_54 , V_55 , V_57 ) ;
}
long F_32 ( T_10 V_61 , T_10 V_62 , char V_5 * V_63 ,
T_3 V_41 )
{
return F_33 ( ( V_64 ) V_61 << 32 | V_62 ,
V_63 , V_41 ) ;
}
T_1 long F_34 ( int V_51 , int V_65 , T_10 V_66 , T_10 V_67 ,
T_10 V_68 , T_10 V_69 )
{
return F_35 ( V_51 , V_65 , ( ( T_9 ) V_66 << 32 ) | V_67 ,
( ( T_9 ) V_68 << 32 ) | V_69 ) ;
}
T_1 long F_36 ( int V_70 , int V_71 , T_10 V_72 ,
T_10 V_73 , int V_51 ,
const char V_5 * V_74 )
{
return F_37 ( V_70 , V_71 , ( ( V_64 ) V_72 << 32 ) | V_73 ,
V_51 , V_74 ) ;
}
