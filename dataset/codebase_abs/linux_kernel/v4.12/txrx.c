static inline int F_1 ( struct V_1 * V_2 )
{
return 100 - ( ( V_2 -> V_3 >> 24 ) & 0xff ) ;
}
int F_2 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 V_9 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
T_1 V_12 , V_13 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_2 = (struct V_1 * ) V_7 -> V_14 ;
F_3 ( ( V_15 * ) V_2 , sizeof( * V_2 ) / sizeof( V_15 ) ) ;
F_4 ( V_16 ,
L_1 , ( char * ) V_2 ,
sizeof( struct V_1 ) ) ;
F_5 ( V_7 , V_2 -> V_17 . V_18 + V_2 -> V_17 . V_19 ) ;
F_6 ( V_7 , V_2 -> V_17 . V_18 ) ;
V_11 = (struct V_10 * ) V_7 -> V_14 ;
V_12 = F_7 ( V_11 -> V_20 ) ;
V_13 = F_8 ( F_7 ( V_11 -> V_21 ) ) ;
if ( F_9 ( V_11 -> V_20 ) && V_5 -> V_22 ) {
V_9 . V_23 = V_5 -> V_22 ;
V_9 . V_24 = V_5 -> V_25 ;
} else {
V_9 . V_23 = F_10 ( V_5 ) ;
V_9 . V_24 = F_11 ( V_5 ) ;
}
V_9 . V_26 = 10 ;
V_9 . signal = - F_1 ( V_2 ) ;
V_9 . V_27 = 1 ;
V_9 . V_28 = 1 ;
V_9 . V_29 = 0 ;
V_9 . V_30 = 0 ;
V_9 . V_29 |= V_31 |
V_32 |
V_33 ;
F_12 ( V_34 , L_2 , V_9 . V_29 ) ;
memcpy ( F_13 ( V_7 ) , & V_9 , sizeof( V_9 ) ) ;
if ( F_9 ( V_11 -> V_20 ) ) {
F_12 ( V_35 , L_3 ,
V_7 , V_7 -> V_36 , V_12 , V_13 ) ;
F_4 ( V_37 , L_4 ,
( char * ) V_7 -> V_14 , V_7 -> V_36 ) ;
} else {
F_12 ( V_34 , L_5 ,
V_7 , V_7 -> V_36 , V_12 , V_13 ) ;
F_4 ( V_16 , L_4 ,
( char * ) V_7 -> V_14 , V_7 -> V_36 ) ;
}
F_14 ( V_5 -> V_38 , V_7 ) ;
return 0 ;
}
static void F_15 ( struct V_39 * V_2 ,
V_15 V_40 ,
V_15 V_36 ,
T_1 V_41 )
{
V_2 -> V_17 . V_40 = V_40 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_2 -> V_17 . V_42 = V_2 -> V_17 . V_40 +
V_2 -> V_17 . V_18 ;
V_2 -> V_17 . V_19 = V_36 ;
V_2 -> V_17 . V_41 = V_41 ;
V_2 -> V_17 . V_43 = V_44 ;
}
static inline struct V_45 * F_16 ( struct V_4 * V_5 ,
T_2 * V_46 )
{
struct V_45 * V_47 = NULL ;
struct V_48 * V_49 = NULL ;
F_17 (vif_priv, &wcn->vif_list, list) {
V_49 = F_18 ( V_47 ) ;
if ( memcmp ( V_49 -> V_46 , V_46 , V_50 ) == 0 )
return V_47 ;
}
F_19 ( L_6 , V_46 ) ;
return NULL ;
}
static void F_20 ( struct V_4 * V_5 ,
struct V_51 * V_52 ,
struct V_6 * V_7 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_53 * V_54 ;
T_2 * V_55 , V_41 ;
if ( ! F_21 ( & V_5 -> V_38 -> V_56 ) )
return;
V_54 = F_22 ( V_52 ) ;
if ( F_23 ( ! F_24 ( V_11 -> V_20 ) ) )
return;
if ( F_25 ( V_7 ) == V_57 )
return;
V_55 = F_26 ( V_11 ) ;
V_41 = V_55 [ 0 ] & V_58 ;
F_27 ( & V_52 -> V_59 ) ;
if ( V_52 -> V_60 [ V_41 ] != V_61 )
goto V_62;
if ( V_52 -> V_63 ++ >= V_64 ) {
V_52 -> V_60 [ V_41 ] = V_65 ;
V_52 -> V_63 = 0 ;
F_28 ( V_54 , V_41 , 0 ) ;
}
V_62:
F_29 ( & V_52 -> V_59 ) ;
}
static void F_30 ( struct V_39 * V_2 ,
struct V_4 * V_5 ,
struct V_45 * * V_47 ,
struct V_51 * V_52 ,
struct V_6 * V_7 ,
bool V_66 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_48 * V_49 = NULL ;
struct V_45 * V_67 = NULL ;
bool V_68 ;
V_2 -> V_69 = V_70 ;
if ( V_52 ) {
V_67 = V_52 -> V_49 ;
V_49 = F_18 ( V_67 ) ;
V_2 -> V_71 = V_52 -> V_72 ;
if ( V_49 -> type == V_73 ) {
V_2 -> V_74 = V_52 -> V_75 ;
V_2 -> V_76 = V_52 -> V_77 ;
} else if ( V_49 -> type == V_78 ||
V_49 -> type == V_79 ||
V_49 -> type == V_80 ) {
V_2 -> V_74 = V_52 -> V_74 ;
V_2 -> V_76 = V_52 -> V_81 ;
}
} else {
V_67 = F_16 ( V_5 , V_11 -> V_82 ) ;
V_2 -> V_74 = V_67 -> V_83 ;
V_2 -> V_76 = V_67 -> V_84 ;
V_2 -> V_71 = V_67 -> V_85 ;
}
if ( F_31 ( V_11 -> V_20 ) ||
( V_52 && ! V_52 -> V_86 ) )
V_2 -> V_87 = 1 ;
if ( V_66 ) {
V_2 -> V_88 = 1 ;
V_2 -> V_89 = 1 ;
}
* V_47 = V_67 ;
V_68 = F_24 ( V_11 -> V_20 ) ;
F_15 ( V_2 ,
V_68 ?
sizeof( struct V_90 ) :
sizeof( struct V_91 ) ,
V_7 -> V_36 , V_52 ? V_52 -> V_41 : 0 ) ;
if ( V_52 && V_68 )
F_20 ( V_5 , V_52 , V_7 ) ;
}
static void F_32 ( struct V_39 * V_2 ,
struct V_4 * V_5 ,
struct V_45 * * V_47 ,
struct V_6 * V_7 ,
bool V_66 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_45 * V_67 =
F_16 ( V_5 , V_11 -> V_82 ) ;
V_2 -> V_74 = V_67 -> V_83 ;
V_2 -> V_76 = V_67 -> V_84 ;
V_2 -> V_87 = 1 ;
if ( F_33 ( V_11 -> V_20 ) )
V_2 -> V_69 = ( F_11 ( V_5 ) == V_92 ) ?
V_93 :
V_94 ;
else if ( F_34 ( V_11 -> V_20 ) )
V_2 -> V_69 = V_93 ;
else
F_19 ( L_7 ) ;
if ( V_67 -> V_95 &&
F_35 ( V_11 -> V_20 ) )
V_66 = false ;
if ( V_66 ) {
V_2 -> V_88 = 1 ;
V_2 -> V_89 = 1 ;
V_2 -> V_96 = V_97 ;
} else
V_2 -> V_96 = V_98 ;
* V_47 = V_67 ;
F_15 ( V_2 ,
F_24 ( V_11 -> V_20 ) ?
sizeof( struct V_90 ) :
sizeof( struct V_91 ) ,
V_7 -> V_36 , V_99 ) ;
}
int F_36 ( struct V_4 * V_5 ,
struct V_51 * V_52 ,
struct V_6 * V_7 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_45 * V_47 = NULL ;
struct V_100 * V_101 = F_37 ( V_7 ) ;
unsigned long V_102 ;
bool V_103 = F_38 ( V_11 -> V_20 ) ;
bool V_66 = F_39 ( V_11 -> V_104 ) ||
F_40 ( V_11 -> V_104 ) ;
struct V_39 * V_2 = F_41 ( V_5 , V_103 ) ;
if ( ! V_2 ) {
F_42 ( L_8 ) ;
return - V_105 ;
}
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_12 ( V_106 ,
L_9 ,
V_7 , V_7 -> V_36 , F_7 ( V_11 -> V_20 ) ,
F_8 ( F_7 ( V_11 -> V_21 ) ) ,
V_103 ? L_10 : L_11 , V_66 ? L_12 : L_13 ) ;
F_4 ( V_107 , L_14 , V_7 -> V_14 , V_7 -> V_36 ) ;
V_2 -> V_108 = V_109 ;
V_2 -> V_110 = ! ! ( V_101 -> V_102 & V_111 ) ;
if ( V_2 -> V_110 ) {
F_12 ( V_112 , L_15 ) ;
F_43 ( & V_5 -> V_113 , V_102 ) ;
if ( V_5 -> V_114 ) {
F_44 ( & V_5 -> V_113 , V_102 ) ;
F_19 ( L_16 ) ;
return - V_105 ;
}
V_5 -> V_114 = V_7 ;
F_44 ( & V_5 -> V_113 , V_102 ) ;
F_45 ( V_5 -> V_38 ) ;
}
if ( V_103 )
F_30 ( V_2 , V_5 , & V_47 , V_52 , V_7 , V_66 ) ;
else
F_32 ( V_2 , V_5 , & V_47 , V_7 , V_66 ) ;
F_3 ( ( V_15 * ) V_2 , sizeof( * V_2 ) / sizeof( V_15 ) ) ;
V_2 -> V_115 = 0xbdbdbdbd ;
return F_46 ( V_5 , V_47 , V_7 , V_103 ) ;
}
