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
V_9 . V_20 = 10 ;
V_9 . V_21 = F_7 ( V_5 ) ;
V_9 . V_22 = F_8 ( V_5 ) ;
V_9 . signal = - F_1 ( V_2 ) ;
V_9 . V_23 = 1 ;
V_9 . V_24 = 1 ;
V_9 . V_25 = 0 ;
V_9 . V_26 = 0 ;
V_9 . V_25 |= V_27 |
V_28 |
V_29 ;
F_9 ( V_30 , L_2 , V_9 . V_25 ) ;
memcpy ( F_10 ( V_7 ) , & V_9 , sizeof( V_9 ) ) ;
V_11 = (struct V_10 * ) V_7 -> V_14 ;
V_12 = F_11 ( V_11 -> V_31 ) ;
V_13 = F_12 ( F_11 ( V_11 -> V_32 ) ) ;
if ( F_13 ( V_11 -> V_31 ) ) {
F_9 ( V_33 , L_3 ,
V_7 , V_7 -> V_34 , V_12 , V_13 ) ;
F_4 ( V_35 , L_4 ,
( char * ) V_7 -> V_14 , V_7 -> V_34 ) ;
} else {
F_9 ( V_30 , L_5 ,
V_7 , V_7 -> V_34 , V_12 , V_13 ) ;
F_4 ( V_16 , L_4 ,
( char * ) V_7 -> V_14 , V_7 -> V_34 ) ;
}
F_14 ( V_5 -> V_36 , V_7 ) ;
return 0 ;
}
static void F_15 ( struct V_37 * V_2 ,
V_15 V_38 ,
V_15 V_34 ,
T_1 V_39 )
{
V_2 -> V_17 . V_38 = V_38 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_2 -> V_17 . V_40 = V_2 -> V_17 . V_38 +
V_2 -> V_17 . V_18 ;
V_2 -> V_17 . V_19 = V_34 ;
V_2 -> V_17 . V_39 = V_39 ;
V_2 -> V_17 . V_41 = V_42 ;
}
static inline struct V_43 * F_16 ( struct V_4 * V_5 ,
T_2 * V_44 )
{
struct V_43 * V_45 = NULL ;
struct V_46 * V_47 = NULL ;
F_17 (vif_priv, &wcn->vif_list, list) {
V_47 = F_18 ( V_45 ) ;
if ( memcmp ( V_47 -> V_44 , V_44 , V_48 ) == 0 )
return V_45 ;
}
F_19 ( L_6 , V_44 ) ;
return NULL ;
}
static void F_20 ( struct V_4 * V_5 ,
struct V_49 * V_50 ,
struct V_6 * V_7 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_51 * V_52 ;
T_2 * V_53 , V_39 ;
if ( ! F_21 ( & V_5 -> V_36 -> V_54 ) )
return;
V_52 = F_22 ( V_50 ) ;
if ( F_23 ( ! F_24 ( V_11 -> V_31 ) ) )
return;
if ( F_25 ( V_7 ) == V_55 )
return;
V_53 = F_26 ( V_11 ) ;
V_39 = V_53 [ 0 ] & V_56 ;
F_27 ( & V_50 -> V_57 ) ;
if ( V_50 -> V_58 [ V_39 ] != V_59 )
goto V_60;
if ( V_50 -> V_61 ++ >= V_62 ) {
V_50 -> V_58 [ V_39 ] = V_63 ;
V_50 -> V_61 = 0 ;
F_28 ( V_52 , V_39 , 0 ) ;
}
V_60:
F_29 ( & V_50 -> V_57 ) ;
}
static void F_30 ( struct V_37 * V_2 ,
struct V_4 * V_5 ,
struct V_43 * * V_45 ,
struct V_49 * V_50 ,
struct V_6 * V_7 ,
bool V_64 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_46 * V_47 = NULL ;
struct V_43 * V_65 = NULL ;
bool V_66 ;
V_2 -> V_67 = V_68 ;
if ( V_50 ) {
V_65 = V_50 -> V_47 ;
V_47 = F_18 ( V_65 ) ;
V_2 -> V_69 = V_50 -> V_70 ;
if ( V_47 -> type == V_71 ) {
V_2 -> V_72 = V_50 -> V_73 ;
V_2 -> V_74 = V_50 -> V_75 ;
} else if ( V_47 -> type == V_76 ||
V_47 -> type == V_77 ||
V_47 -> type == V_78 ) {
V_2 -> V_72 = V_50 -> V_72 ;
V_2 -> V_74 = V_50 -> V_79 ;
}
} else {
V_65 = F_16 ( V_5 , V_11 -> V_80 ) ;
V_2 -> V_72 = V_65 -> V_81 ;
V_2 -> V_74 = V_65 -> V_82 ;
V_2 -> V_69 = V_65 -> V_83 ;
}
if ( F_31 ( V_11 -> V_31 ) ||
( V_50 && ! V_50 -> V_84 ) )
V_2 -> V_85 = 1 ;
if ( V_64 ) {
V_2 -> V_86 = 1 ;
V_2 -> V_87 = 1 ;
}
* V_45 = V_65 ;
V_66 = F_24 ( V_11 -> V_31 ) ;
F_15 ( V_2 ,
V_66 ?
sizeof( struct V_88 ) :
sizeof( struct V_89 ) ,
V_7 -> V_34 , V_50 ? V_50 -> V_39 : 0 ) ;
if ( V_50 && V_66 )
F_20 ( V_5 , V_50 , V_7 ) ;
}
static void F_32 ( struct V_37 * V_2 ,
struct V_4 * V_5 ,
struct V_43 * * V_45 ,
struct V_6 * V_7 ,
bool V_64 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_43 * V_65 =
F_16 ( V_5 , V_11 -> V_80 ) ;
V_2 -> V_72 = V_65 -> V_81 ;
V_2 -> V_74 = V_65 -> V_82 ;
V_2 -> V_85 = 1 ;
if ( F_33 ( V_11 -> V_31 ) )
V_2 -> V_67 = ( F_8 ( V_5 ) == V_90 ) ?
V_91 :
V_92 ;
else if ( F_34 ( V_11 -> V_31 ) )
V_2 -> V_67 = V_91 ;
else
F_19 ( L_7 ) ;
if ( V_65 -> V_93 &&
F_35 ( V_11 -> V_31 ) )
V_64 = false ;
if ( V_64 ) {
V_2 -> V_86 = 1 ;
V_2 -> V_87 = 1 ;
V_2 -> V_94 = V_95 ;
} else
V_2 -> V_94 = V_96 ;
* V_45 = V_65 ;
F_15 ( V_2 ,
F_24 ( V_11 -> V_31 ) ?
sizeof( struct V_88 ) :
sizeof( struct V_89 ) ,
V_7 -> V_34 , V_97 ) ;
}
int F_36 ( struct V_4 * V_5 ,
struct V_49 * V_50 ,
struct V_6 * V_7 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_43 * V_45 = NULL ;
struct V_98 * V_99 = F_37 ( V_7 ) ;
unsigned long V_100 ;
bool V_101 = F_38 ( V_11 -> V_31 ) ;
bool V_64 = F_39 ( V_11 -> V_102 ) ||
F_40 ( V_11 -> V_102 ) ;
struct V_37 * V_2 = F_41 ( V_5 , V_101 ) ;
if ( ! V_2 ) {
F_42 ( L_8 ) ;
return - V_103 ;
}
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_9 ( V_104 ,
L_9 ,
V_7 , V_7 -> V_34 , F_11 ( V_11 -> V_31 ) ,
F_12 ( F_11 ( V_11 -> V_32 ) ) ,
V_101 ? L_10 : L_11 , V_64 ? L_12 : L_13 ) ;
F_4 ( V_105 , L_14 , V_7 -> V_14 , V_7 -> V_34 ) ;
V_2 -> V_106 = V_107 ;
V_2 -> V_108 = ! ! ( V_99 -> V_100 & V_109 ) ;
if ( V_2 -> V_108 ) {
F_9 ( V_110 , L_15 ) ;
F_43 ( & V_5 -> V_111 , V_100 ) ;
if ( V_5 -> V_112 ) {
F_44 ( & V_5 -> V_111 , V_100 ) ;
F_19 ( L_16 ) ;
return - V_103 ;
}
V_5 -> V_112 = V_7 ;
F_44 ( & V_5 -> V_111 , V_100 ) ;
F_45 ( V_5 -> V_36 ) ;
}
if ( V_101 )
F_30 ( V_2 , V_5 , & V_45 , V_50 , V_7 , V_64 ) ;
else
F_32 ( V_2 , V_5 , & V_45 , V_7 , V_64 ) ;
F_3 ( ( V_15 * ) V_2 , sizeof( * V_2 ) / sizeof( V_15 ) ) ;
V_2 -> V_113 = 0xbdbdbdbd ;
return F_46 ( V_5 , V_45 , V_7 , V_101 ) ;
}
