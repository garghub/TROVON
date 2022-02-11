void F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 , struct V_5 * V_6 )
{
V_3 -> V_7 . V_8 = 0 ;
V_3 -> V_7 . V_9 = F_2 ( V_4 ) ;
if ( V_6 ) {
F_3 ( V_2 , & V_3 -> V_7 . V_10 , V_6 ) ;
V_3 -> V_11 = 6 + V_3 -> V_7 . V_10 . V_12 ;
} else {
memset ( & V_3 -> V_7 . V_10 , 0 , sizeof( struct V_13 ) ) ;
V_3 -> V_11 = 6 ;
}
}
static int F_4 ( T_3 * V_14 , T_2 V_15 , struct V_16 * V_16 )
{
T_4 V_17 = F_5 () ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
if ( F_6 ( V_16 -> V_18 ) ) {
V_14 -> type = V_19 ;
V_14 -> V_20 . V_21 = F_2 ( V_15 ) ;
V_14 -> V_20 . V_22 = V_17 ;
V_14 -> V_20 . V_23 = V_17 ;
V_14 -> V_20 . V_24 = 0 ;
V_14 -> V_20 . V_25 . V_26 = F_7 ( 0xff ) ;
return sizeof( struct V_27 ) ;
} else {
V_14 -> type = V_28 ;
V_14 -> V_29 . V_30 = V_31 | V_32 ;
if ( ! ( V_16 -> V_18 & V_33 ) )
V_14 -> V_29 . V_30 |= V_34 ;
V_14 -> V_29 . V_35 = F_2 ( V_15 ) ;
V_14 -> V_29 . V_22 = V_17 ;
V_14 -> V_29 . V_23 = V_17 ;
V_14 -> V_29 . V_24 = 0 ;
V_14 -> V_29 . V_36 . V_37 = F_8 ( V_16 -> V_38 ) -> V_39 ;
V_14 -> V_29 . V_36 . V_40 = F_8 ( V_16 -> V_38 ) -> V_41 ;
return sizeof( struct V_42 ) ;
}
}
static int F_9 ( struct V_1 * V_2 ,
T_3 * V_14 , int type ,
T_2 V_43 , struct V_5 * V_6 )
{
V_14 -> type = type ;
memset ( V_14 -> V_44 . V_8 , 0 , sizeof( V_14 -> V_44 . V_8 ) ) ;
V_14 -> V_44 . V_9 = F_2 ( V_43 ) ;
F_3 ( V_2 , & V_14 -> V_44 . V_10 , V_6 ) ;
return sizeof( struct V_45 ) ;
}
int F_10 ( T_2 V_15 , struct V_16 * V_20 , struct V_5 * V_46 , struct V_16 * V_16 )
{
struct V_47 V_48 ;
struct V_1 * V_2 ;
union T_3 V_49 ;
int V_50 ;
int V_51 ;
F_11 ( V_52 , L_1 ,
V_46 -> V_6 , V_15 , V_16 -> V_53 ) ;
if ( V_20 -> V_54 >= V_55 )
return - V_56 ;
V_2 = V_20 -> V_38 ;
V_51 = F_12 ( F_8 ( V_2 ) -> V_57 , & V_48 ) ;
if ( V_51 )
return V_51 ;
F_1 ( V_2 , V_48 . V_58 , V_15 , NULL ) ;
V_50 = F_9 ( V_2 , & V_49 , F_6 ( V_16 -> V_18 ) ?
V_59 : V_60 ,
V_20 -> V_61 , V_46 ) ;
V_51 = F_13 ( & V_48 ) ;
if ( V_51 != - V_62 ) {
if ( ! V_51 )
V_51 = - V_63 ;
goto V_64;
}
V_51 = F_14 ( & V_48 , & V_49 , V_50 ) ;
if ( V_51 )
goto V_64;
F_1 ( V_2 , V_48 . V_58 , V_20 -> V_61 , V_46 ) ;
V_50 = F_4 ( & V_49 , V_15 , V_16 ) ;
V_51 = F_13 ( & V_48 ) ;
if ( V_51 != - V_62 ) {
if ( ! V_51 )
V_51 = - V_63 ;
goto V_65;
}
V_51 = F_14 ( & V_48 , & V_49 , V_50 ) ;
if ( V_51 )
goto V_65;
V_20 -> V_54 ++ ;
V_20 -> V_66 = V_20 -> V_67 = V_68 ;
F_15 ( V_20 ) ;
F_16 ( & V_48 ) ;
return 0 ;
V_65:
F_1 ( V_2 , V_48 . V_58 , V_15 , NULL ) ;
if ( ! F_13 ( & V_48 ) )
F_17 ( & V_48 ) ;
V_64:
F_16 ( & V_48 ) ;
return V_51 ;
}
int F_18 ( const T_1 * V_69 , const T_1 * V_70 )
{
int V_71 ;
V_71 = F_19 ( V_69 -> V_7 . V_9 ) - F_19 ( V_70 -> V_7 . V_9 ) ;
if ( ! V_71 )
V_71 = F_20 ( V_69 -> V_7 . V_10 . V_6 , V_69 -> V_7 . V_10 . V_12 ,
V_70 -> V_7 . V_10 . V_6 , V_70 -> V_7 . V_10 . V_12 ) ;
return V_71 ;
}
int F_21 ( struct V_1 * V_2 , T_2 V_15 ,
struct V_47 * V_48 )
{
T_3 V_14 ;
int V_72 , V_12 , type ;
F_1 ( V_2 , V_48 -> V_58 , V_15 , NULL ) ;
V_72 = F_22 ( V_48 , & V_14 , sizeof( V_14 ) ) ;
if ( V_72 )
return V_72 ;
type = V_14 . type ;
if ( type != V_59 && type != V_60 ) {
F_23 ( L_2 ) ;
return - V_73 ;
}
V_48 -> V_58 -> V_7 . V_9 = V_14 . V_44 . V_9 ;
V_12 = V_48 -> V_58 -> V_7 . V_10 . V_12 = V_14 . V_44 . V_10 . V_12 ;
if ( V_12 > V_74 ) {
F_23 ( L_3 ) ;
return - V_73 ;
}
memcpy ( V_48 -> V_58 -> V_7 . V_10 . V_6 , V_14 . V_44 . V_10 . V_6 , V_12 ) ;
return F_13 ( V_48 ) ;
}
int F_24 ( T_2 V_15 , struct V_16 * V_20 , struct V_5 * V_46 )
{
struct V_1 * V_2 ;
struct V_47 V_48 ;
struct V_75 * V_76 ;
int V_72 , type ;
F_11 ( V_52 , L_4 , V_46 ? V_46 -> V_6 : NULL , V_15 ) ;
V_2 = V_20 -> V_38 ;
V_72 = F_12 ( F_8 ( V_2 ) -> V_57 , & V_48 ) ;
if ( V_72 )
return V_72 ;
F_1 ( V_2 , V_48 . V_58 , V_20 -> V_61 , V_46 ) ;
V_72 = F_13 ( & V_48 ) ;
if ( V_72 )
goto V_77;
type = F_25 ( V_48 . V_78 , V_48 . V_79 ) ;
if ( type == V_28 ) {
struct V_42 V_29 ;
F_26 ( V_48 . V_78 , & V_29 , V_48 . V_79 , sizeof( V_29 ) ) ;
if ( F_19 ( V_29 . V_35 ) == V_15 ) {
#if 0
hfs_free_fork(sb, &file, HFS_FK_DATA);
#endif
F_27 ( V_2 , & V_29 , V_80 ) ;
}
}
F_28 (pos, &HFS_I(dir)->open_dir_list) {
struct V_81 * V_82 =
F_29 ( V_76 , struct V_81 , V_83 ) ;
if ( V_48 . V_84 -> V_85 ( V_48 . V_58 , ( void * ) & V_82 -> V_3 ) < 0 )
V_82 -> V_29 -> V_86 -- ;
}
V_72 = F_17 ( & V_48 ) ;
if ( V_72 )
goto V_77;
F_1 ( V_2 , V_48 . V_58 , V_15 , NULL ) ;
V_72 = F_13 ( & V_48 ) ;
if ( ! V_72 ) {
V_72 = F_17 ( & V_48 ) ;
if ( V_72 )
goto V_77;
}
V_20 -> V_54 -- ;
V_20 -> V_66 = V_20 -> V_67 = V_68 ;
F_15 ( V_20 ) ;
V_72 = 0 ;
V_77:
F_16 ( & V_48 ) ;
return V_72 ;
}
int F_30 ( T_2 V_15 , struct V_16 * V_87 , struct V_5 * V_88 ,
struct V_16 * V_89 , struct V_5 * V_90 )
{
struct V_1 * V_2 ;
struct V_47 V_91 , V_92 ;
union T_3 V_49 ;
int V_50 , type ;
int V_51 ;
F_11 ( V_52 , L_5 ,
V_15 , V_87 -> V_61 , V_88 -> V_6 ,
V_89 -> V_61 , V_90 -> V_6 ) ;
V_2 = V_87 -> V_38 ;
V_51 = F_12 ( F_8 ( V_2 ) -> V_57 , & V_91 ) ;
if ( V_51 )
return V_51 ;
V_92 = V_91 ;
F_1 ( V_2 , V_91 . V_58 , V_87 -> V_61 , V_88 ) ;
V_51 = F_13 ( & V_91 ) ;
if ( V_51 )
goto V_77;
if ( V_91 . V_93 > sizeof( V_49 ) || V_91 . V_93 < 0 ) {
V_51 = - V_73 ;
goto V_77;
}
F_26 ( V_91 . V_78 , & V_49 , V_91 . V_79 ,
V_91 . V_93 ) ;
F_1 ( V_2 , V_92 . V_58 , V_89 -> V_61 , V_90 ) ;
V_51 = F_13 ( & V_92 ) ;
if ( V_51 != - V_62 ) {
if ( ! V_51 )
V_51 = - V_63 ;
goto V_77;
}
V_51 = F_14 ( & V_92 , & V_49 , V_91 . V_93 ) ;
if ( V_51 )
goto V_77;
V_89 -> V_54 ++ ;
V_89 -> V_66 = V_89 -> V_67 = V_68 ;
F_15 ( V_89 ) ;
F_1 ( V_2 , V_91 . V_58 , V_87 -> V_61 , V_88 ) ;
V_51 = F_13 ( & V_91 ) ;
if ( V_51 )
goto V_77;
V_51 = F_17 ( & V_91 ) ;
if ( V_51 )
goto V_77;
V_87 -> V_54 -- ;
V_87 -> V_66 = V_87 -> V_67 = V_68 ;
F_15 ( V_87 ) ;
type = V_49 . type ;
if ( type == V_28 && ! ( V_49 . V_29 . V_30 & V_32 ) )
goto V_77;
F_1 ( V_2 , V_91 . V_58 , V_15 , NULL ) ;
V_51 = F_13 ( & V_91 ) ;
if ( V_51 )
goto V_77;
V_51 = F_17 ( & V_91 ) ;
if ( V_51 )
goto V_77;
F_1 ( V_2 , V_92 . V_58 , V_15 , NULL ) ;
V_50 = F_9 ( V_2 , & V_49 , type == V_28 ? V_60 : V_59 ,
V_89 -> V_61 , V_90 ) ;
V_51 = F_13 ( & V_92 ) ;
if ( V_51 != - V_62 ) {
if ( ! V_51 )
V_51 = - V_63 ;
goto V_77;
}
V_51 = F_14 ( & V_92 , & V_49 , V_50 ) ;
V_77:
F_31 ( V_92 . V_78 ) ;
F_16 ( & V_91 ) ;
return V_51 ;
}
