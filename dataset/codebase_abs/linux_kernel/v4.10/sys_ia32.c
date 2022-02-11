T_1 long F_1 ( const char T_2 * V_1 ,
unsigned long V_2 ,
unsigned long V_3 )
{
return F_2 ( V_1 , ( ( V_4 ) V_3 << 32 ) | V_2 ) ;
}
T_1 long F_3 ( unsigned int V_5 , unsigned long V_2 ,
unsigned long V_3 )
{
return F_4 ( V_5 , ( ( V_4 ) V_3 << 32 ) | V_2 ) ;
}
static int F_5 ( struct V_6 T_2 * V_7 , struct V_8 * V_9 )
{
F_6 (ubuf->st_uid) V_10 = 0 ;
F_6 (ubuf->st_gid) V_11 = 0 ;
F_7 ( V_10 , F_8 ( F_9 () , V_9 -> V_10 ) ) ;
F_10 ( V_11 , F_11 ( F_9 () , V_9 -> V_11 ) ) ;
if ( ! F_12 ( V_12 , V_7 , sizeof( struct V_6 ) ) ||
F_13 ( F_14 ( V_9 -> V_13 ) , & V_7 -> V_14 ) ||
F_13 ( V_9 -> V_15 , & V_7 -> V_16 ) ||
F_13 ( V_9 -> V_15 , & V_7 -> V_17 ) ||
F_13 ( V_9 -> V_18 , & V_7 -> V_19 ) ||
F_13 ( V_9 -> V_20 , & V_7 -> V_21 ) ||
F_13 ( V_10 , & V_7 -> V_22 ) ||
F_13 ( V_11 , & V_7 -> V_23 ) ||
F_13 ( F_14 ( V_9 -> V_24 ) , & V_7 -> V_25 ) ||
F_13 ( V_9 -> V_26 , & V_7 -> V_27 ) ||
F_13 ( V_9 -> V_28 . V_29 , & V_7 -> V_30 ) ||
F_13 ( V_9 -> V_28 . V_31 , & V_7 -> V_32 ) ||
F_13 ( V_9 -> V_33 . V_29 , & V_7 -> V_34 ) ||
F_13 ( V_9 -> V_33 . V_31 , & V_7 -> V_35 ) ||
F_13 ( V_9 -> ctime . V_29 , & V_7 -> V_36 ) ||
F_13 ( V_9 -> ctime . V_31 , & V_7 -> V_37 ) ||
F_13 ( V_9 -> V_38 , & V_7 -> V_39 ) ||
F_13 ( V_9 -> V_40 , & V_7 -> V_41 ) )
return - V_42 ;
return 0 ;
}
T_1 long F_15 ( const char T_2 * V_1 ,
struct V_6 T_2 * V_43 )
{
struct V_8 V_9 ;
int V_44 = F_16 ( V_1 , & V_9 ) ;
if ( ! V_44 )
V_44 = F_5 ( V_43 , & V_9 ) ;
return V_44 ;
}
T_1 long F_17 ( const char T_2 * V_1 ,
struct V_6 T_2 * V_43 )
{
struct V_8 V_9 ;
int V_44 = F_18 ( V_1 , & V_9 ) ;
if ( ! V_44 )
V_44 = F_5 ( V_43 , & V_9 ) ;
return V_44 ;
}
T_1 long F_19 ( unsigned int V_5 , struct V_6 T_2 * V_43 )
{
struct V_8 V_9 ;
int V_44 = F_20 ( V_5 , & V_9 ) ;
if ( ! V_44 )
V_44 = F_5 ( V_43 , & V_9 ) ;
return V_44 ;
}
T_1 long F_21 ( unsigned int V_45 , const char T_2 * V_1 ,
struct V_6 T_2 * V_43 , int V_46 )
{
struct V_8 V_9 ;
int error ;
error = F_22 ( V_45 , V_1 , & V_9 , V_46 ) ;
if ( error )
return error ;
return F_5 ( V_43 , & V_9 ) ;
}
T_1 long F_23 ( struct V_47 T_2 * V_48 )
{
struct V_47 V_49 ;
if ( F_24 ( & V_49 , V_48 , sizeof( V_49 ) ) )
return - V_42 ;
if ( V_49 . V_50 & ~ V_51 )
return - V_52 ;
return F_25 ( V_49 . V_53 , V_49 . V_54 , V_49 . V_55 , V_49 . V_56 , V_49 . V_5 ,
V_49 . V_50 >> V_57 ) ;
}
T_1 long F_26 ( T_3 V_58 , unsigned int T_2 * V_59 ,
int V_60 )
{
return F_27 ( V_58 , V_59 , V_60 , NULL ) ;
}
T_1 long F_28 ( unsigned int V_5 , char T_2 * V_7 , T_4 V_61 ,
T_4 V_62 , T_4 V_63 )
{
return F_29 ( V_5 , V_7 , V_61 ,
( ( V_4 ) F_30 ( V_63 ) << 32 ) | F_30 ( V_62 ) ) ;
}
T_1 long F_31 ( unsigned int V_5 , const char T_2 * V_7 ,
T_4 V_61 , T_4 V_62 , T_4 V_63 )
{
return F_32 ( V_5 , V_7 , V_61 ,
( ( V_4 ) F_30 ( V_63 ) << 32 ) | F_30 ( V_62 ) ) ;
}
long F_33 ( int V_5 , T_5 V_2 , T_5 V_3 ,
T_5 V_64 , T_5 V_65 , int V_66 )
{
return F_34 ( V_5 ,
( ( ( V_67 ) V_3 ) << 32 ) | V_2 ,
( ( ( V_67 ) V_65 ) << 32 ) | V_64 ,
V_66 ) ;
}
T_1 T_6 F_35 ( int V_5 , unsigned V_68 , unsigned V_69 ,
T_7 V_61 )
{
return F_36 ( V_5 , ( ( V_67 ) V_69 << 32 ) | V_68 , V_61 ) ;
}
T_1 long F_37 ( int V_5 , unsigned V_70 , unsigned V_69 ,
unsigned V_71 , unsigned V_72 , int V_56 )
{
return F_38 ( V_5 ,
( ( V_67 ) V_69 << 32 ) | V_70 ,
( ( V_67 ) V_72 << 32 ) | V_71 , V_56 ) ;
}
T_1 long F_39 ( int V_5 , unsigned V_73 , unsigned V_74 ,
T_7 V_54 , int V_66 )
{
return F_34 ( V_5 , ( ( V_67 ) V_74 << 32 ) | V_73 ,
V_54 , V_66 ) ;
}
T_1 long F_40 ( int V_5 , int V_18 , unsigned V_73 ,
unsigned V_74 , unsigned V_75 ,
unsigned V_76 )
{
return F_41 ( V_5 , V_18 , ( ( V_67 ) V_74 << 32 ) | V_73 ,
( ( V_67 ) V_76 << 32 ) | V_75 ) ;
}
