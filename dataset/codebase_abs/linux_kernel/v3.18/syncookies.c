static T_1 F_1 ( T_2 V_1 , T_2 V_2 , T_3 V_3 , T_3 V_4 ,
T_1 V_5 , int V_6 )
{
T_4 * V_7 ;
F_2 ( V_8 , sizeof( V_8 ) ) ;
V_7 = F_3 ( V_9 ) ;
memcpy ( V_7 + 4 , V_8 [ V_6 ] , sizeof( V_8 [ V_6 ] ) ) ;
V_7 [ 0 ] = ( V_10 T_1 ) V_1 ;
V_7 [ 1 ] = ( V_10 T_1 ) V_2 ;
V_7 [ 2 ] = ( ( V_10 T_1 ) V_3 << 16 ) + ( V_10 T_1 ) V_4 ;
V_7 [ 3 ] = V_5 ;
F_4 ( V_7 + 16 , ( V_11 * ) V_7 , V_7 + 16 + 5 ) ;
return V_7 [ 17 ] ;
}
T_4 F_5 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
T_1 V_16 , V_17 = V_18 ;
T_1 V_19 = 0 ;
V_15 = F_6 ( V_13 ) ;
V_19 = V_15 -> V_20 ? V_15 -> V_21 : 0xf ;
V_19 |= V_15 -> V_22 << 4 ;
V_19 |= V_15 -> V_23 << 5 ;
V_16 = V_17 & ~ V_24 ;
V_16 |= V_19 ;
if ( V_16 > V_17 ) {
V_16 >>= V_25 ;
V_16 -- ;
V_16 <<= V_25 ;
V_16 |= V_19 ;
}
return V_16 ;
}
static T_4 F_7 ( T_2 V_1 , T_2 V_2 , T_3 V_3 ,
T_3 V_4 , T_4 V_26 , T_4 V_27 )
{
T_1 V_5 = F_8 () ;
return ( F_1 ( V_1 , V_2 , V_3 , V_4 , 0 , 0 ) +
V_26 + ( V_5 << V_28 ) +
( ( F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , 1 ) + V_27 )
& V_29 ) ) ;
}
static T_4 F_9 ( T_4 V_30 , T_2 V_1 , T_2 V_2 ,
T_3 V_3 , T_3 V_4 , T_4 V_26 )
{
T_1 V_31 , V_5 = F_8 () ;
V_30 -= F_1 ( V_1 , V_2 , V_3 , V_4 , 0 , 0 ) + V_26 ;
V_31 = ( V_5 - ( V_30 >> V_28 ) ) & ( ( T_4 ) - 1 >> V_28 ) ;
if ( V_31 >= V_32 )
return ( T_4 ) - 1 ;
return ( V_30 -
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 - V_31 , 1 ) )
& V_29 ;
}
T_1 F_10 ( const struct V_33 * V_34 , const struct V_35 * V_36 ,
T_5 * V_37 )
{
int V_38 ;
const T_6 V_39 = * V_37 ;
for ( V_38 = F_11 ( V_40 ) - 1 ; V_38 ; V_38 -- )
if ( V_39 >= V_40 [ V_38 ] )
break;
* V_37 = V_40 [ V_38 ] ;
return F_7 ( V_34 -> V_1 , V_34 -> V_2 ,
V_36 -> V_41 , V_36 -> V_42 , F_12 ( V_36 -> V_43 ) ,
V_38 ) ;
}
T_4 F_13 ( struct V_44 * V_45 , const struct V_46 * V_47 ,
T_6 * V_37 )
{
const struct V_33 * V_34 = F_14 ( V_47 ) ;
const struct V_35 * V_36 = F_15 ( V_47 ) ;
F_16 ( V_45 ) ;
F_17 ( F_18 ( V_45 ) , V_48 ) ;
return F_10 ( V_34 , V_36 , V_37 ) ;
}
int F_19 ( const struct V_33 * V_34 , const struct V_35 * V_36 ,
T_1 V_30 )
{
T_4 V_43 = F_12 ( V_36 -> V_43 ) - 1 ;
T_4 V_38 = F_9 ( V_30 , V_34 -> V_1 , V_34 -> V_2 ,
V_36 -> V_41 , V_36 -> V_42 , V_43 ) ;
return V_38 < F_11 ( V_40 ) ? V_40 [ V_38 ] : 0 ;
}
static inline struct V_44 * F_20 ( struct V_44 * V_45 , struct V_46 * V_47 ,
struct V_12 * V_13 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = F_21 ( V_45 ) ;
struct V_44 * V_53 ;
V_53 = V_52 -> V_54 -> V_55 ( V_45 , V_47 , V_13 , V_50 ) ;
if ( V_53 )
F_22 ( V_45 , V_13 , V_53 ) ;
else
F_23 ( V_13 ) ;
return V_53 ;
}
bool F_24 ( struct V_56 * V_57 ,
struct V_58 * V_58 , bool * V_23 )
{
T_1 V_19 = V_57 -> V_59 & V_24 ;
if ( ! V_57 -> V_60 ) {
F_25 ( V_57 ) ;
return true ;
}
if ( ! V_61 )
return false ;
V_57 -> V_22 = ( V_19 & ( 1 << 4 ) ) ? V_62 : 0 ;
* V_23 = ( V_19 >> 5 ) & 1 ;
if ( * V_23 && ! V_58 -> V_63 . V_64 )
return false ;
if ( V_57 -> V_22 && ! V_65 )
return false ;
if ( ( V_19 & 0xf ) == 0xf )
return true ;
V_57 -> V_20 = 1 ;
V_57 -> V_21 = V_19 & 0xf ;
return V_66 != 0 ;
}
struct V_44 * F_26 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
struct V_67 * V_68 = & F_27 ( V_47 ) -> V_69 . V_70 . V_68 ;
struct V_56 V_57 ;
struct V_14 * V_15 ;
struct V_71 * V_72 ;
struct V_73 * V_74 = F_28 ( V_45 ) ;
const struct V_35 * V_36 = F_15 ( V_47 ) ;
T_4 V_30 = F_12 ( V_36 -> V_75 ) - 1 ;
struct V_44 * V_76 = V_45 ;
struct V_12 * V_13 ;
int V_39 ;
struct V_77 * V_78 ;
V_11 V_79 ;
bool V_23 = false ;
struct V_80 V_81 ;
if ( ! V_82 || ! V_36 -> V_83 || V_36 -> V_84 )
goto V_85;
if ( F_29 ( V_45 ) ||
( V_39 = F_19 ( F_14 ( V_47 ) , V_36 , V_30 ) ) == 0 ) {
F_17 ( F_18 ( V_45 ) , V_86 ) ;
goto V_85;
}
F_17 ( F_18 ( V_45 ) , V_87 ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
F_30 ( V_47 , & V_57 , 0 , NULL ) ;
if ( ! F_24 ( & V_57 , F_18 ( V_45 ) , & V_23 ) )
goto V_85;
V_76 = NULL ;
V_13 = F_31 ( & V_88 ) ;
if ( ! V_13 )
goto V_85;
V_15 = F_6 ( V_13 ) ;
V_72 = F_32 ( V_13 ) ;
V_72 -> V_89 = F_12 ( V_36 -> V_43 ) - 1 ;
V_72 -> V_90 = V_30 ;
V_13 -> V_39 = V_39 ;
V_15 -> V_91 = F_33 ( V_36 -> V_42 ) ;
V_15 -> V_92 = V_36 -> V_41 ;
V_15 -> V_93 = F_14 ( V_47 ) -> V_2 ;
V_15 -> V_94 = F_14 ( V_47 ) -> V_1 ;
V_15 -> V_95 = F_34 ( V_45 , V_47 ) ;
V_15 -> V_23 = V_23 ;
V_15 -> V_21 = V_57 . V_21 ;
V_15 -> V_22 = V_57 . V_22 ;
V_15 -> V_20 = V_57 . V_20 ;
V_15 -> V_96 = V_57 . V_60 ;
V_13 -> V_97 = V_57 . V_60 ? V_57 . V_98 : 0 ;
V_72 -> V_99 = V_57 . V_60 ? V_57 . V_59 : 0 ;
V_72 -> V_100 = NULL ;
V_15 -> V_68 = F_35 ( V_47 ) ;
if ( F_36 ( V_45 , V_47 , V_13 ) ) {
F_23 ( V_13 ) ;
goto V_85;
}
V_13 -> V_101 = 0UL ;
V_13 -> V_102 = 0 ;
F_37 ( & V_81 , V_45 -> V_103 , V_15 -> V_95 ,
F_38 ( V_45 ) , V_104 , V_105 ,
F_39 ( V_45 ) ,
V_68 -> V_106 ? V_68 -> V_107 : V_15 -> V_94 ,
V_15 -> V_93 , V_36 -> V_41 , V_36 -> V_42 ) ;
F_40 ( V_13 , F_41 ( & V_81 ) ) ;
V_78 = F_42 ( F_18 ( V_45 ) , & V_81 ) ;
if ( F_43 ( V_78 ) ) {
F_23 ( V_13 ) ;
goto V_85;
}
V_13 -> V_108 = V_74 -> V_108 ? : F_44 ( & V_78 -> V_50 , V_109 ) ;
F_45 ( F_46 ( V_45 ) , V_13 -> V_39 ,
& V_13 -> V_110 , & V_13 -> V_108 ,
V_15 -> V_20 , & V_79 ,
F_44 ( & V_78 -> V_50 , V_111 ) ) ;
V_15 -> V_79 = V_79 ;
V_76 = F_20 ( V_45 , V_47 , V_13 , & V_78 -> V_50 ) ;
if ( V_76 )
F_47 ( V_76 ) -> V_112 . V_113 . V_114 . V_115 = V_81 ;
V_85: return V_76 ;
}
