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
V_19 = V_15 -> V_20 ? V_15 -> V_21 : V_22 ;
if ( V_15 -> V_23 )
V_19 |= V_24 ;
if ( V_15 -> V_25 )
V_19 |= V_26 ;
V_16 = V_17 & ~ V_27 ;
V_16 |= V_19 ;
if ( V_16 > V_17 ) {
V_16 >>= V_28 ;
V_16 -- ;
V_16 <<= V_28 ;
V_16 |= V_19 ;
}
return V_16 ;
}
static T_4 F_7 ( T_2 V_1 , T_2 V_2 , T_3 V_3 ,
T_3 V_4 , T_4 V_29 , T_4 V_30 )
{
T_1 V_5 = F_8 () ;
return ( F_1 ( V_1 , V_2 , V_3 , V_4 , 0 , 0 ) +
V_29 + ( V_5 << V_31 ) +
( ( F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , 1 ) + V_30 )
& V_32 ) ) ;
}
static T_4 F_9 ( T_4 V_33 , T_2 V_1 , T_2 V_2 ,
T_3 V_3 , T_3 V_4 , T_4 V_29 )
{
T_1 V_34 , V_5 = F_8 () ;
V_33 -= F_1 ( V_1 , V_2 , V_3 , V_4 , 0 , 0 ) + V_29 ;
V_34 = ( V_5 - ( V_33 >> V_31 ) ) & ( ( T_4 ) - 1 >> V_31 ) ;
if ( V_34 >= V_35 )
return ( T_4 ) - 1 ;
return ( V_33 -
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 - V_34 , 1 ) )
& V_32 ;
}
T_1 F_10 ( const struct V_36 * V_37 , const struct V_38 * V_39 ,
T_5 * V_40 )
{
int V_41 ;
const T_6 V_42 = * V_40 ;
for ( V_41 = F_11 ( V_43 ) - 1 ; V_41 ; V_41 -- )
if ( V_42 >= V_43 [ V_41 ] )
break;
* V_40 = V_43 [ V_41 ] ;
return F_7 ( V_37 -> V_1 , V_37 -> V_2 ,
V_39 -> V_44 , V_39 -> V_45 , F_12 ( V_39 -> V_46 ) ,
V_41 ) ;
}
T_4 F_13 ( struct V_47 * V_48 , const struct V_49 * V_50 ,
T_6 * V_40 )
{
const struct V_36 * V_37 = F_14 ( V_50 ) ;
const struct V_38 * V_39 = F_15 ( V_50 ) ;
F_16 ( V_48 ) ;
F_17 ( F_18 ( V_48 ) , V_51 ) ;
return F_10 ( V_37 , V_39 , V_40 ) ;
}
int F_19 ( const struct V_36 * V_37 , const struct V_38 * V_39 ,
T_1 V_33 )
{
T_4 V_46 = F_12 ( V_39 -> V_46 ) - 1 ;
T_4 V_41 = F_9 ( V_33 , V_37 -> V_1 , V_37 -> V_2 ,
V_39 -> V_44 , V_39 -> V_45 , V_46 ) ;
return V_41 < F_11 ( V_43 ) ? V_43 [ V_41 ] : 0 ;
}
static inline struct V_47 * F_20 ( struct V_47 * V_48 , struct V_49 * V_50 ,
struct V_12 * V_13 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_21 ( V_48 ) ;
struct V_47 * V_56 ;
V_56 = V_55 -> V_57 -> V_58 ( V_48 , V_50 , V_13 , V_53 ) ;
if ( V_56 )
F_22 ( V_48 , V_13 , V_56 ) ;
else
F_23 ( V_13 ) ;
return V_56 ;
}
bool F_24 ( struct V_59 * V_60 )
{
T_1 V_19 = V_60 -> V_61 ;
if ( ! V_60 -> V_62 ) {
F_25 ( V_60 ) ;
return true ;
}
if ( ! V_63 )
return false ;
V_60 -> V_23 = ( V_19 & V_24 ) ? V_64 : 0 ;
if ( V_60 -> V_23 && ! V_65 )
return false ;
if ( ( V_19 & V_22 ) == V_22 )
return true ;
V_60 -> V_20 = 1 ;
V_60 -> V_21 = V_19 & V_22 ;
return V_66 != 0 ;
}
bool F_26 ( const struct V_59 * V_60 ,
const struct V_67 * V_67 , const struct V_52 * V_53 )
{
bool V_25 = V_60 -> V_61 & V_26 ;
if ( ! V_25 )
return false ;
if ( V_67 -> V_68 . V_69 )
return true ;
return F_27 ( V_53 , V_70 ) ;
}
struct V_47 * F_28 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_71 * V_72 = & F_29 ( V_50 ) -> V_73 . V_74 . V_72 ;
struct V_59 V_60 ;
struct V_14 * V_15 ;
struct V_75 * V_76 ;
struct V_77 * V_78 = F_30 ( V_48 ) ;
const struct V_38 * V_39 = F_15 ( V_50 ) ;
T_4 V_33 = F_12 ( V_39 -> V_79 ) - 1 ;
struct V_47 * V_80 = V_48 ;
struct V_12 * V_13 ;
int V_42 ;
struct V_81 * V_82 ;
V_11 V_83 ;
struct V_84 V_85 ;
if ( ! V_86 || ! V_39 -> V_87 || V_39 -> V_88 )
goto V_89;
if ( F_31 ( V_48 ) )
goto V_89;
V_42 = F_19 ( F_14 ( V_50 ) , V_39 , V_33 ) ;
if ( V_42 == 0 ) {
F_17 ( F_18 ( V_48 ) , V_90 ) ;
goto V_89;
}
F_17 ( F_18 ( V_48 ) , V_91 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
F_32 ( V_50 , & V_60 , 0 , NULL ) ;
if ( ! F_24 ( & V_60 ) )
goto V_89;
V_80 = NULL ;
V_13 = F_33 ( & V_92 ) ;
if ( ! V_13 )
goto V_89;
V_15 = F_6 ( V_13 ) ;
V_76 = F_34 ( V_13 ) ;
V_76 -> V_93 = F_12 ( V_39 -> V_46 ) - 1 ;
V_76 -> V_94 = V_33 ;
V_13 -> V_42 = V_42 ;
V_15 -> V_95 = F_35 ( V_39 -> V_45 ) ;
V_15 -> V_96 = V_39 -> V_44 ;
V_15 -> V_97 = F_14 ( V_50 ) -> V_2 ;
V_15 -> V_98 = F_14 ( V_50 ) -> V_1 ;
V_15 -> V_99 = F_36 ( V_48 , V_50 ) ;
V_15 -> V_21 = V_60 . V_21 ;
V_15 -> V_23 = V_60 . V_23 ;
V_15 -> V_20 = V_60 . V_20 ;
V_15 -> V_100 = V_60 . V_62 ;
V_13 -> V_101 = V_60 . V_62 ? V_60 . V_102 : 0 ;
V_76 -> V_103 = V_60 . V_62 ? V_60 . V_61 : 0 ;
V_76 -> V_104 = NULL ;
V_15 -> V_72 = F_37 ( V_50 ) ;
if ( F_38 ( V_48 , V_50 , V_13 ) ) {
F_23 ( V_13 ) ;
goto V_89;
}
V_13 -> V_105 = 0UL ;
V_13 -> V_106 = 0 ;
F_39 ( & V_85 , V_48 -> V_107 , V_15 -> V_99 ,
F_40 ( V_48 ) , V_108 , V_109 ,
F_41 ( V_48 ) ,
V_72 -> V_110 ? V_72 -> V_111 : V_15 -> V_98 ,
V_15 -> V_97 , V_39 -> V_44 , V_39 -> V_45 ) ;
F_42 ( V_13 , F_43 ( & V_85 ) ) ;
V_82 = F_44 ( F_18 ( V_48 ) , & V_85 ) ;
if ( F_45 ( V_82 ) ) {
F_23 ( V_13 ) ;
goto V_89;
}
V_13 -> V_112 = V_78 -> V_112 ? : F_46 ( & V_82 -> V_53 , V_113 ) ;
F_47 ( F_48 ( V_48 ) , V_13 -> V_42 ,
& V_13 -> V_114 , & V_13 -> V_112 ,
V_15 -> V_20 , & V_83 ,
F_46 ( & V_82 -> V_53 , V_115 ) ) ;
V_15 -> V_83 = V_83 ;
V_15 -> V_25 = F_26 ( & V_60 , F_18 ( V_48 ) , & V_82 -> V_53 ) ;
V_80 = F_20 ( V_48 , V_50 , V_13 , & V_82 -> V_53 ) ;
if ( V_80 )
F_49 ( V_80 ) -> V_116 . V_117 . V_118 . V_119 = V_85 ;
V_89: return V_80 ;
}
