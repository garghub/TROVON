int F_1 ( T_1 V_1 , T_1 V_2 )
{
V_3 = F_2 ( V_2 ) ;
V_4 = V_1 ;
return 0 ;
}
int F_3 ( struct V_5 * V_6 )
{
if ( ! V_3 )
return - 1 ;
return (* V_3) ( ( V_7 ) V_4 , ( V_7 ) V_6 ) ;
}
int F_4 ( int V_1 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_9 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = V_1 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = 0 ;
F_3 ( & V_6 ) ;
return V_6 . V_10 ;
}
int F_5 ( int V_14 , void (* F_6) ( void ) , long V_15 , long V_16 , long V_17 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_18 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_19 ) ;
V_6 . V_20 . V_19 . V_21 = V_14 ;
V_6 . V_20 . V_19 . V_22 = V_23 ;
V_6 . V_20 . V_19 . V_24 = V_16 ;
V_6 . V_20 . V_19 . V_25 = V_15 ;
V_6 . V_20 . V_19 . V_26 = V_17 ;
V_6 . V_20 . V_19 . V_27 = ( long ) F_6 ;
F_3 ( & V_6 ) ;
return V_6 . V_10 ;
}
int F_7 ( int V_14 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_18 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_19 ) ;
V_6 . V_20 . V_19 . V_21 = V_14 ;
V_6 . V_20 . V_19 . V_22 = V_28 ;
F_3 ( & V_6 ) ;
return V_6 . V_10 ;
}
int F_8 ( int V_29 , char * V_30 , int V_31 , char * V_32 , int V_33 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_34 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_35 ) ;
V_6 . V_20 . V_35 . V_36 = V_29 ;
V_6 . V_20 . V_35 . V_37 = F_9 ( V_30 ) ;
V_6 . V_20 . V_35 . V_38 = V_31 ;
V_6 . V_20 . V_35 . V_39 = F_9 ( V_32 ) ;
V_6 . V_20 . V_35 . V_40 = V_33 ;
F_3 ( & V_6 ) ;
return V_6 . V_10 ;
}
int
F_10 ( int V_29 , int V_41 , T_1 * V_42 , T_1 * V_43 , T_1 * type )
{
struct V_5 V_6 ;
V_6 . V_8 = V_44 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = V_41 ;
V_6 . V_13 = sizeof( struct V_45 ) ;
V_6 . V_20 . V_45 . V_46 = V_29 ;
F_3 ( & V_6 ) ;
if ( V_6 . V_10 < 0 )
return V_6 . V_10 ;
* V_42 = V_6 . V_20 . V_45 . V_47 ;
* V_43 = V_6 . V_20 . V_45 . V_48 ;
* type = V_6 . V_20 . V_45 . V_49 ;
return 0 ;
}
int F_11 ( int V_50 , int V_51 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_52 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = V_50 ? V_53 : 0 ;
V_6 . V_13 = sizeof( struct V_54 ) ;
V_6 . V_20 . V_54 . V_51 = V_51 ;
F_3 ( & V_6 ) ;
return V_6 . V_10 ;
}
int F_12 ( int V_55 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_56 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = V_55 ;
V_6 . V_13 = 0 ;
F_3 ( & V_6 ) ;
return V_6 . V_10 ;
}
int F_13 ( char * V_30 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_57 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_58 ) ;
V_6 . V_20 . V_58 . V_59 = 0 ;
V_6 . V_20 . V_58 . V_60 = F_9 ( V_30 ) ;
V_6 . V_20 . V_58 . V_61 = strlen ( V_30 ) ;
F_3 ( & V_6 ) ;
if ( V_6 . V_10 < 0 )
return V_6 . V_10 ;
return V_6 . V_20 . V_58 . V_62 ;
}
int F_14 ( char * V_30 , char * V_63 , int V_64 )
{
struct V_5 V_6 ;
* V_63 = 0 ;
V_6 . V_8 = V_65 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_35 ) ;
V_6 . V_20 . V_35 . V_36 = 0 ;
V_6 . V_20 . V_35 . V_37 = F_9 ( V_30 ) ;
V_6 . V_20 . V_35 . V_38 = strlen ( V_30 ) ;
V_6 . V_20 . V_35 . V_39 = F_9 ( V_63 ) ;
V_6 . V_20 . V_35 . V_40 = V_64 ;
F_3 ( & V_6 ) ;
return V_6 . V_10 ;
}
int F_15 ( T_2 * V_66 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_67 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_68 ) ;
F_3 ( & V_6 ) ;
if ( V_6 . V_10 < 0 )
return V_6 . V_10 ;
V_66 -> V_69 = V_6 . V_20 . V_68 . V_69 ;
V_66 -> V_70 = V_6 . V_20 . V_68 . V_70 ;
V_66 -> V_71 = V_6 . V_20 . V_68 . V_71 ;
V_66 -> V_72 = V_6 . V_20 . V_68 . V_72 ;
V_66 -> V_73 = V_6 . V_20 . V_68 . V_73 ;
V_66 -> V_74 = V_6 . V_20 . V_68 . V_74 ;
V_66 -> V_75 =
V_6 . V_20 . V_68 . V_75 ;
#if 0
info->fwi_reserved1 = xiocb.plist.xiocb_fwinfo.fwi_reserved1;
info->fwi_reserved2 = xiocb.plist.xiocb_fwinfo.fwi_reserved2;
info->fwi_reserved3 = xiocb.plist.xiocb_fwinfo.fwi_reserved3;
#endif
return 0 ;
}
int F_16 ( int V_55 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_76 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = V_55 ;
V_6 . V_13 = 0 ;
F_3 ( & V_6 ) ;
if ( V_6 . V_10 < 0 )
return V_6 . V_10 ;
return V_6 . V_11 ;
}
T_3
F_17 ( void )
{
struct V_5 V_6 ;
V_6 . V_8 = V_77 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_78 ) ;
V_6 . V_20 . V_78 . V_79 = 0 ;
F_3 ( & V_6 ) ;
return V_6 . V_20 . V_78 . V_79 ;
}
int F_18 ( int V_1 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_80 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = V_1 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_81 ) ;
V_6 . V_20 . V_81 . V_82 = 0 ;
F_3 ( & V_6 ) ;
if ( V_6 . V_10 < 0 )
return V_6 . V_10 ;
return V_6 . V_20 . V_81 . V_82 ;
}
int
F_19 ( int V_1 , unsigned int V_83 , unsigned char * V_84 ,
int V_43 , int * V_85 , T_1 V_86 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_87 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = V_1 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_58 ) ;
V_6 . V_20 . V_58 . V_59 = V_86 ;
V_6 . V_20 . V_58 . V_62 = V_83 ;
V_6 . V_20 . V_58 . V_60 = F_9 ( V_84 ) ;
V_6 . V_20 . V_58 . V_61 = V_43 ;
F_3 ( & V_6 ) ;
if ( V_85 )
* V_85 = V_6 . V_20 . V_58 . V_88 ;
return V_6 . V_10 ;
}
int F_20 ( char * V_30 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_89 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_58 ) ;
V_6 . V_20 . V_58 . V_59 = 0 ;
V_6 . V_20 . V_58 . V_60 = F_9 ( V_30 ) ;
V_6 . V_20 . V_58 . V_61 = strlen ( V_30 ) ;
F_3 ( & V_6 ) ;
if ( V_6 . V_10 < 0 )
return V_6 . V_10 ;
return V_6 . V_11 ;
}
int F_21 ( int V_1 , unsigned char * V_84 , int V_43 )
{
return F_22 ( V_1 , 0 , V_84 , V_43 ) ;
}
int F_22 ( int V_1 , T_4 V_86 , unsigned char * V_84 , int V_43 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_90 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = V_1 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_58 ) ;
V_6 . V_20 . V_58 . V_59 = V_86 ;
V_6 . V_20 . V_58 . V_60 = F_9 ( V_84 ) ;
V_6 . V_20 . V_58 . V_61 = V_43 ;
F_3 ( & V_6 ) ;
if ( V_6 . V_10 < 0 )
return V_6 . V_10 ;
return V_6 . V_20 . V_58 . V_88 ;
}
int F_23 ( char * V_30 , char * V_32 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_34 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_35 ) ;
V_6 . V_20 . V_35 . V_36 = 0 ;
V_6 . V_20 . V_35 . V_37 = F_9 ( V_30 ) ;
V_6 . V_20 . V_35 . V_38 = strlen ( V_30 ) ;
V_6 . V_20 . V_35 . V_39 = F_9 ( V_32 ) ;
V_6 . V_20 . V_35 . V_40 = strlen ( V_32 ) ;
F_3 ( & V_6 ) ;
return V_6 . V_10 ;
}
int F_24 ( int V_1 , unsigned char * V_84 , int V_43 )
{
return F_25 ( V_1 , 0 , V_84 , V_43 ) ;
}
int F_25 ( int V_1 , T_4 V_86 , unsigned char * V_84 , int V_43 )
{
struct V_5 V_6 ;
V_6 . V_8 = V_91 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = V_1 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = sizeof( struct V_58 ) ;
V_6 . V_20 . V_58 . V_59 = V_86 ;
V_6 . V_20 . V_58 . V_60 = F_9 ( V_84 ) ;
V_6 . V_20 . V_58 . V_61 = V_43 ;
F_3 ( & V_6 ) ;
if ( V_6 . V_10 < 0 )
return V_6 . V_10 ;
return V_6 . V_20 . V_58 . V_88 ;
}
