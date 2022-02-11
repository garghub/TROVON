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
V_47 = F_18 ( ( void * ) V_45 ,
struct V_46 ,
V_48 ) ;
if ( memcmp ( V_47 -> V_44 , V_44 , V_49 ) == 0 )
return V_45 ;
}
F_19 ( L_6 , V_44 ) ;
return NULL ;
}
static void F_20 ( struct V_4 * V_5 ,
struct V_50 * V_51 ,
struct V_6 * V_7 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_52 * V_53 ;
T_2 * V_54 , V_39 ;
if ( ! F_21 ( & V_5 -> V_36 -> V_55 ) )
return;
V_53 = F_22 ( V_51 ) ;
if ( F_23 ( ! F_24 ( V_11 -> V_31 ) ) )
return;
if ( F_25 ( V_7 ) == V_56 )
return;
V_54 = F_26 ( V_11 ) ;
V_39 = V_54 [ 0 ] & V_57 ;
F_27 ( & V_51 -> V_58 ) ;
if ( V_51 -> V_59 [ V_39 ] != V_60 )
goto V_61;
if ( V_51 -> V_62 ++ >= V_63 ) {
V_51 -> V_59 [ V_39 ] = V_64 ;
V_51 -> V_62 = 0 ;
F_28 ( V_53 , V_39 , 0 ) ;
}
V_61:
F_29 ( & V_51 -> V_58 ) ;
}
static void F_30 ( struct V_37 * V_2 ,
struct V_4 * V_5 ,
struct V_43 * * V_45 ,
struct V_50 * V_51 ,
struct V_6 * V_7 ,
bool V_65 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_46 * V_47 = NULL ;
struct V_43 * V_66 = NULL ;
bool V_67 ;
V_2 -> V_68 = V_69 ;
if ( V_51 ) {
V_66 = V_51 -> V_47 ;
V_47 = F_18 ( ( void * ) V_66 ,
struct V_46 ,
V_48 ) ;
V_2 -> V_70 = V_51 -> V_71 ;
if ( V_47 -> type == V_72 ) {
V_2 -> V_73 = V_51 -> V_74 ;
V_2 -> V_75 = V_51 -> V_76 ;
} else if ( V_47 -> type == V_77 ||
V_47 -> type == V_78 ||
V_47 -> type == V_79 ) {
V_2 -> V_73 = V_51 -> V_73 ;
V_2 -> V_75 = V_51 -> V_80 ;
}
} else {
V_66 = F_16 ( V_5 , V_11 -> V_81 ) ;
V_2 -> V_73 = V_66 -> V_82 ;
V_2 -> V_75 = V_66 -> V_83 ;
V_2 -> V_70 = V_66 -> V_84 ;
}
if ( F_31 ( V_11 -> V_31 ) ||
( V_51 && ! V_51 -> V_85 ) )
V_2 -> V_86 = 1 ;
if ( V_65 ) {
V_2 -> V_87 = 1 ;
V_2 -> V_88 = 1 ;
}
* V_45 = V_66 ;
V_67 = F_24 ( V_11 -> V_31 ) ;
F_15 ( V_2 ,
V_67 ?
sizeof( struct V_89 ) :
sizeof( struct V_90 ) ,
V_7 -> V_34 , V_51 ? V_51 -> V_39 : 0 ) ;
if ( V_51 && V_67 )
F_20 ( V_5 , V_51 , V_7 ) ;
}
static void F_32 ( struct V_37 * V_2 ,
struct V_4 * V_5 ,
struct V_43 * * V_45 ,
struct V_6 * V_7 ,
bool V_65 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_43 * V_66 =
F_16 ( V_5 , V_11 -> V_81 ) ;
V_2 -> V_73 = V_66 -> V_82 ;
V_2 -> V_75 = V_66 -> V_83 ;
V_2 -> V_86 = 1 ;
if ( F_33 ( V_11 -> V_31 ) )
V_2 -> V_68 = ( F_8 ( V_5 ) == V_91 ) ?
V_92 :
V_93 ;
else if ( F_34 ( V_11 -> V_31 ) )
V_2 -> V_68 = V_92 ;
else
F_19 ( L_7 ) ;
if ( V_66 -> V_94 &&
F_35 ( V_11 -> V_31 ) )
V_65 = false ;
if ( V_65 ) {
V_2 -> V_87 = 1 ;
V_2 -> V_88 = 1 ;
V_2 -> V_95 = V_96 ;
} else
V_2 -> V_95 = V_97 ;
* V_45 = V_66 ;
F_15 ( V_2 ,
F_24 ( V_11 -> V_31 ) ?
sizeof( struct V_89 ) :
sizeof( struct V_90 ) ,
V_7 -> V_34 , V_98 ) ;
}
int F_36 ( struct V_4 * V_5 ,
struct V_50 * V_51 ,
struct V_6 * V_7 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_43 * V_45 = NULL ;
struct V_99 * V_100 = F_37 ( V_7 ) ;
unsigned long V_101 ;
bool V_102 = F_38 ( V_11 -> V_31 ) ;
bool V_65 = F_39 ( V_11 -> V_103 ) ||
F_40 ( V_11 -> V_103 ) ;
struct V_37 * V_2 = F_41 ( V_5 , V_102 ) ;
if ( ! V_2 ) {
F_42 ( L_8 ) ;
return - V_104 ;
}
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_9 ( V_105 ,
L_9 ,
V_7 , V_7 -> V_34 , F_11 ( V_11 -> V_31 ) ,
F_12 ( F_11 ( V_11 -> V_32 ) ) ,
V_102 ? L_10 : L_11 , V_65 ? L_12 : L_13 ) ;
F_4 ( V_106 , L_14 , V_7 -> V_14 , V_7 -> V_34 ) ;
V_2 -> V_107 = V_108 ;
V_2 -> V_109 = ! ! ( V_100 -> V_101 & V_110 ) ;
if ( V_2 -> V_109 ) {
F_9 ( V_111 , L_15 ) ;
F_43 ( & V_5 -> V_112 , V_101 ) ;
if ( V_5 -> V_113 ) {
F_44 ( & V_5 -> V_112 , V_101 ) ;
F_19 ( L_16 ) ;
return - V_104 ;
}
V_5 -> V_113 = V_7 ;
F_44 ( & V_5 -> V_112 , V_101 ) ;
F_45 ( V_5 -> V_36 ) ;
}
if ( V_102 )
F_30 ( V_2 , V_5 , & V_45 , V_51 , V_7 , V_65 ) ;
else
F_32 ( V_2 , V_5 , & V_45 , V_7 , V_65 ) ;
F_3 ( ( V_15 * ) V_2 , sizeof( * V_2 ) / sizeof( V_15 ) ) ;
V_2 -> V_114 = 0xbdbdbdbd ;
return F_46 ( V_5 , V_45 , V_7 , V_102 ) ;
}
