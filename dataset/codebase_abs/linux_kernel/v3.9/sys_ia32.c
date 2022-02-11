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
T_1 long F_26 ( unsigned long V_58 , T_3 V_54 ,
unsigned long V_55 )
{
return F_27 ( V_58 , V_54 , V_55 ) ;
}
T_1 long F_28 ( T_4 V_59 , unsigned int T_2 * V_60 ,
int V_61 )
{
return F_29 ( V_59 , V_60 , V_61 , NULL ) ;
}
T_1 long F_30 ( unsigned int V_5 , char T_2 * V_7 , T_5 V_62 ,
T_5 V_63 , T_5 V_64 )
{
return F_31 ( V_5 , V_7 , V_62 ,
( ( V_4 ) F_32 ( V_64 ) << 32 ) | F_32 ( V_63 ) ) ;
}
T_1 long F_33 ( unsigned int V_5 , const char T_2 * V_7 ,
T_5 V_62 , T_5 V_63 , T_5 V_64 )
{
return F_34 ( V_5 , V_7 , V_62 ,
( ( V_4 ) F_32 ( V_64 ) << 32 ) | F_32 ( V_63 ) ) ;
}
T_1 long F_35 ( int V_65 , int V_66 ,
T_6 T_2 * V_50 , T_7 V_62 )
{
T_8 V_67 = F_36 () ;
int V_44 ;
T_9 V_68 ;
if ( V_50 && F_37 ( V_68 , V_50 ) )
return - V_42 ;
F_38 ( V_69 ) ;
V_44 = F_39 ( V_65 , V_66 , V_50 ? ( T_9 T_2 * ) & V_68 : NULL ,
V_62 ) ;
F_38 ( V_67 ) ;
if ( V_50 && F_40 ( V_68 , V_50 ) )
return - V_42 ;
return V_44 ;
}
long F_41 ( int V_59 , int V_70 )
{
return F_42 ( V_59 , V_70 ) ;
}
long F_43 ( int V_5 , T_10 V_2 , T_10 V_3 ,
T_10 V_71 , T_10 V_72 , int V_73 )
{
return F_44 ( V_5 ,
( ( ( V_74 ) V_3 ) << 32 ) | V_2 ,
( ( ( V_74 ) V_72 ) << 32 ) | V_71 ,
V_73 ) ;
}
long F_45 ( void )
{
struct V_75 * V_76 = V_77 ;
static char V_78 [ sizeof( V_76 -> V_79 ) ] ;
if ( strncmp ( V_78 , V_76 -> V_79 , sizeof( V_78 ) ) ) {
F_46 ( V_80
L_1 ,
V_76 -> V_79 ) ;
strncpy ( V_78 , V_76 -> V_79 , sizeof( V_78 ) ) ;
}
return - V_81 ;
}
long F_47 ( T_5 V_82 , T_5 V_83 ,
char T_2 * V_84 , T_3 V_54 )
{
return F_48 ( ( ( V_74 ) V_83 << 32 ) | V_82 , V_84 , V_54 ) ;
}
T_1 T_11 F_49 ( int V_5 , unsigned V_85 , unsigned V_86 ,
T_3 V_62 )
{
return F_50 ( V_5 , ( ( V_74 ) V_86 << 32 ) | V_85 , V_62 ) ;
}
T_1 long F_51 ( int V_5 , unsigned V_87 , unsigned V_86 ,
unsigned V_88 , unsigned V_89 , int V_56 )
{
return F_52 ( V_5 ,
( ( V_74 ) V_86 << 32 ) | V_87 ,
( ( V_74 ) V_89 << 32 ) | V_88 , V_56 ) ;
}
T_1 long F_53 ( int V_5 , unsigned V_90 , unsigned V_91 ,
T_3 V_54 , int V_73 )
{
return F_44 ( V_5 , ( ( V_74 ) V_91 << 32 ) | V_90 ,
V_54 , V_73 ) ;
}
T_1 long F_54 ( int V_5 , int V_18 , unsigned V_90 ,
unsigned V_91 , unsigned V_92 ,
unsigned V_93 )
{
return F_55 ( V_5 , V_18 , ( ( V_74 ) V_91 << 32 ) | V_90 ,
( ( V_74 ) V_93 << 32 ) | V_92 ) ;
}
T_1 long F_56 ( int V_94 , unsigned int V_56 ,
T_5 V_95 , T_5 V_96 ,
int V_5 , const char T_2 * V_97 )
{
return F_57 ( V_94 , V_56 ,
( ( V_74 ) V_96 << 32 ) | V_95 ,
V_5 , V_97 ) ;
}
