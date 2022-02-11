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
F_9 ( V_30 , L_2 ,
V_9 . V_25 , V_9 . V_31 ) ;
memcpy ( F_10 ( V_7 ) , & V_9 , sizeof( V_9 ) ) ;
V_11 = (struct V_10 * ) V_7 -> V_14 ;
V_12 = F_11 ( V_11 -> V_32 ) ;
V_13 = F_12 ( F_11 ( V_11 -> V_33 ) ) ;
if ( F_13 ( V_11 -> V_32 ) ) {
F_9 ( V_34 , L_3 ,
V_7 , V_7 -> V_35 , V_12 , V_13 ) ;
F_4 ( V_36 , L_4 ,
( char * ) V_7 -> V_14 , V_7 -> V_35 ) ;
} else {
F_9 ( V_30 , L_5 ,
V_7 , V_7 -> V_35 , V_12 , V_13 ) ;
F_4 ( V_16 , L_4 ,
( char * ) V_7 -> V_14 , V_7 -> V_35 ) ;
}
F_14 ( V_5 -> V_37 , V_7 ) ;
return 0 ;
}
static void F_15 ( struct V_38 * V_2 ,
V_15 V_39 ,
V_15 V_35 ,
T_1 V_40 )
{
V_2 -> V_17 . V_39 = V_39 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_2 -> V_17 . V_41 = V_2 -> V_17 . V_39 +
V_2 -> V_17 . V_18 ;
V_2 -> V_17 . V_19 = V_35 ;
V_2 -> V_17 . V_40 = V_40 ;
}
static inline struct V_42 * F_16 ( struct V_4 * V_5 ,
T_2 * V_43 )
{
struct V_42 * V_44 = NULL ;
struct V_45 * V_46 = NULL ;
F_17 (vif_priv, &wcn->vif_list, list) {
V_46 = F_18 ( ( void * ) V_44 ,
struct V_45 ,
V_47 ) ;
if ( memcmp ( V_46 -> V_43 , V_43 , V_48 ) == 0 )
return V_44 ;
}
F_19 ( L_6 , V_43 ) ;
return NULL ;
}
static void F_20 ( struct V_38 * V_2 ,
struct V_4 * V_5 ,
struct V_42 * * V_44 ,
struct V_49 * V_50 ,
struct V_10 * V_11 ,
bool V_51 )
{
struct V_45 * V_46 = NULL ;
struct V_42 * V_52 = NULL ;
V_2 -> V_53 = V_54 ;
if ( V_50 ) {
V_52 = V_50 -> V_46 ;
V_46 = F_18 ( ( void * ) V_52 ,
struct V_45 ,
V_47 ) ;
if ( V_46 -> type == V_55 ) {
V_2 -> V_56 = V_50 -> V_57 ;
V_2 -> V_58 = V_50 -> V_59 ;
} else if ( V_46 -> type == V_60 ||
V_46 -> type == V_61 ||
V_46 -> type == V_62 ) {
V_2 -> V_56 = V_50 -> V_56 ;
V_2 -> V_58 = V_50 -> V_63 ;
}
} else {
V_52 = F_16 ( V_5 , V_11 -> V_64 ) ;
V_2 -> V_56 = V_52 -> V_65 ;
V_2 -> V_58 = V_52 -> V_66 ;
}
V_2 -> V_67 = V_52 -> V_68 ;
if ( F_21 ( V_11 -> V_32 ) ||
( V_50 && ! V_50 -> V_69 ) )
V_2 -> V_70 = 1 ;
if ( V_51 ) {
V_2 -> V_71 = 1 ;
V_2 -> V_72 = 1 ;
}
* V_44 = V_52 ;
}
static void F_22 ( struct V_38 * V_2 ,
struct V_4 * V_5 ,
struct V_42 * * V_44 ,
struct V_10 * V_11 ,
bool V_51 )
{
struct V_42 * V_52 =
F_16 ( V_5 , V_11 -> V_64 ) ;
V_2 -> V_56 = V_52 -> V_65 ;
V_2 -> V_58 = V_52 -> V_66 ;
V_2 -> V_70 = 1 ;
if ( F_23 ( V_11 -> V_32 ) )
V_2 -> V_53 = ( F_8 ( V_5 ) == V_73 ) ?
V_74 :
V_75 ;
else if ( F_24 ( V_11 -> V_32 ) )
V_2 -> V_53 = V_74 ;
else
F_19 ( L_7 ) ;
if ( V_52 -> V_76 &&
F_25 ( V_11 -> V_32 ) )
V_51 = false ;
if ( V_51 ) {
V_2 -> V_71 = 1 ;
V_2 -> V_72 = 1 ;
V_2 -> V_77 = V_78 ;
} else
V_2 -> V_77 = V_79 ;
* V_44 = V_52 ;
}
int F_26 ( struct V_4 * V_5 ,
struct V_49 * V_50 ,
struct V_6 * V_7 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_14 ;
struct V_42 * V_44 = NULL ;
struct V_80 * V_81 = F_27 ( V_7 ) ;
unsigned long V_82 ;
bool V_83 = F_28 ( V_11 -> V_32 ) ;
bool V_51 = F_29 ( V_11 -> V_84 ) ||
F_30 ( V_11 -> V_84 ) ;
struct V_38 * V_2 = F_31 ( V_5 , V_83 ) ;
if ( ! V_2 ) {
F_32 ( L_8 ) ;
return - V_85 ;
}
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_9 ( V_86 ,
L_9 ,
V_7 , V_7 -> V_35 , F_11 ( V_11 -> V_32 ) ,
F_12 ( F_11 ( V_11 -> V_33 ) ) ,
V_83 ? L_10 : L_11 , V_51 ? L_12 : L_13 ) ;
F_4 ( V_87 , L_14 , V_7 -> V_14 , V_7 -> V_35 ) ;
V_2 -> V_88 = V_89 ;
V_2 -> V_90 = V_81 -> V_82 & V_91 ;
if ( V_2 -> V_90 ) {
F_9 ( V_92 , L_15 ) ;
F_33 ( & V_5 -> V_93 , V_82 ) ;
if ( V_5 -> V_94 ) {
F_34 ( & V_5 -> V_93 , V_82 ) ;
F_19 ( L_16 ) ;
return - V_85 ;
}
V_5 -> V_94 = V_7 ;
F_34 ( & V_5 -> V_93 , V_82 ) ;
F_35 ( V_5 -> V_37 ) ;
}
if ( V_83 ) {
F_20 ( V_2 , V_5 , & V_44 , V_50 , V_11 , V_51 ) ;
F_15 ( V_2 ,
F_36 ( V_11 -> V_32 ) ?
sizeof( struct V_95 ) :
sizeof( struct V_96 ) ,
V_7 -> V_35 , V_50 ? V_50 -> V_40 : 0 ) ;
} else {
F_22 ( V_2 , V_5 , & V_44 , V_11 , V_51 ) ;
F_15 ( V_2 ,
F_36 ( V_11 -> V_32 ) ?
sizeof( struct V_95 ) :
sizeof( struct V_96 ) ,
V_7 -> V_35 , V_97 ) ;
}
F_3 ( ( V_15 * ) V_2 , sizeof( * V_2 ) / sizeof( V_15 ) ) ;
V_2 -> V_98 = 0xbdbdbdbd ;
return F_37 ( V_5 , V_44 , V_7 , V_83 ) ;
}
