static T_1 F_1 ( T_2 V_1 , T_2 V_2 , T_3 V_3 , T_3 V_4 ,
T_1 V_5 , int V_6 )
{
F_2 ( V_7 , sizeof( V_7 ) ) ;
return F_3 ( ( V_8 T_1 ) V_1 , ( V_8 T_1 ) V_2 ,
( V_8 T_1 ) V_3 << 16 | ( V_8 T_1 ) V_4 ,
V_5 , & V_7 [ V_6 ] ) ;
}
T_4 F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
T_1 V_13 , V_14 = V_15 ;
T_1 V_16 = 0 ;
V_12 = F_5 ( V_10 ) ;
V_16 = V_12 -> V_17 ? V_12 -> V_18 : V_19 ;
if ( V_12 -> V_20 )
V_16 |= V_21 ;
if ( V_12 -> V_22 )
V_16 |= V_23 ;
V_13 = V_14 & ~ V_24 ;
V_13 |= V_16 ;
if ( V_13 > V_14 ) {
V_13 >>= V_25 ;
V_13 -- ;
V_13 <<= V_25 ;
V_13 |= V_16 ;
}
return V_13 ;
}
static T_4 F_6 ( T_2 V_1 , T_2 V_2 , T_3 V_3 ,
T_3 V_4 , T_4 V_26 , T_4 V_27 )
{
T_1 V_5 = F_7 () ;
return ( F_1 ( V_1 , V_2 , V_3 , V_4 , 0 , 0 ) +
V_26 + ( V_5 << V_28 ) +
( ( F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , 1 ) + V_27 )
& V_29 ) ) ;
}
static T_4 F_8 ( T_4 V_30 , T_2 V_1 , T_2 V_2 ,
T_3 V_3 , T_3 V_4 , T_4 V_26 )
{
T_1 V_31 , V_5 = F_7 () ;
V_30 -= F_1 ( V_1 , V_2 , V_3 , V_4 , 0 , 0 ) + V_26 ;
V_31 = ( V_5 - ( V_30 >> V_28 ) ) & ( ( T_4 ) - 1 >> V_28 ) ;
if ( V_31 >= V_32 )
return ( T_4 ) - 1 ;
return ( V_30 -
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 - V_31 , 1 ) )
& V_29 ;
}
T_1 F_9 ( const struct V_33 * V_34 , const struct V_35 * V_36 ,
T_5 * V_37 )
{
int V_38 ;
const T_6 V_39 = * V_37 ;
for ( V_38 = F_10 ( V_40 ) - 1 ; V_38 ; V_38 -- )
if ( V_39 >= V_40 [ V_38 ] )
break;
* V_37 = V_40 [ V_38 ] ;
return F_6 ( V_34 -> V_1 , V_34 -> V_2 ,
V_36 -> V_41 , V_36 -> V_42 , F_11 ( V_36 -> V_43 ) ,
V_38 ) ;
}
T_4 F_12 ( const struct V_44 * V_45 , T_6 * V_37 )
{
const struct V_33 * V_34 = F_13 ( V_45 ) ;
const struct V_35 * V_36 = F_14 ( V_45 ) ;
return F_9 ( V_34 , V_36 , V_37 ) ;
}
int F_15 ( const struct V_33 * V_34 , const struct V_35 * V_36 ,
T_1 V_30 )
{
T_4 V_43 = F_11 ( V_36 -> V_43 ) - 1 ;
T_4 V_38 = F_8 ( V_30 , V_34 -> V_1 , V_34 -> V_2 ,
V_36 -> V_41 , V_36 -> V_42 , V_43 ) ;
return V_38 < F_10 ( V_40 ) ? V_40 [ V_38 ] : 0 ;
}
struct V_46 * F_16 ( struct V_46 * V_47 , struct V_44 * V_45 ,
struct V_9 * V_10 ,
struct V_48 * V_49 , T_1 V_50 )
{
struct V_51 * V_52 = F_17 ( V_47 ) ;
struct V_46 * V_53 ;
bool V_54 ;
V_53 = V_52 -> V_55 -> V_56 ( V_47 , V_45 , V_10 , V_49 ,
NULL , & V_54 ) ;
if ( V_53 ) {
F_18 ( & V_10 -> V_57 , 1 ) ;
F_19 ( V_53 ) -> V_58 = V_50 ;
F_20 ( V_53 , V_45 ) ;
F_21 ( V_47 , V_10 , V_53 ) ;
} else {
F_22 ( V_10 ) ;
}
return V_53 ;
}
bool F_23 ( struct V_59 * V_60 )
{
T_1 V_16 = V_60 -> V_61 ;
if ( ! V_60 -> V_62 ) {
F_24 ( V_60 ) ;
return true ;
}
if ( ! V_63 )
return false ;
V_60 -> V_20 = ( V_16 & V_21 ) ? V_64 : 0 ;
if ( V_60 -> V_20 && ! V_65 )
return false ;
if ( ( V_16 & V_19 ) == V_19 )
return true ;
V_60 -> V_17 = 1 ;
V_60 -> V_18 = V_16 & V_19 ;
return V_66 != 0 ;
}
bool F_25 ( const struct V_59 * V_60 ,
const struct V_67 * V_67 , const struct V_48 * V_49 )
{
bool V_22 = V_60 -> V_61 & V_23 ;
if ( ! V_22 )
return false ;
if ( V_67 -> V_68 . V_69 )
return true ;
return F_26 ( V_49 , V_70 ) ;
}
struct V_46 * F_27 ( struct V_46 * V_47 , struct V_44 * V_45 )
{
struct V_71 * V_72 = & F_28 ( V_45 ) -> V_73 . V_74 . V_72 ;
struct V_59 V_60 ;
struct V_11 * V_12 ;
struct V_75 * V_76 ;
struct V_77 * V_78 = F_19 ( V_47 ) ;
const struct V_35 * V_36 = F_14 ( V_45 ) ;
T_4 V_30 = F_11 ( V_36 -> V_79 ) - 1 ;
struct V_46 * V_80 = V_47 ;
struct V_9 * V_10 ;
int V_39 ;
struct V_81 * V_82 ;
T_7 V_83 ;
struct V_84 V_85 ;
T_1 V_50 = 0 ;
if ( ! F_29 ( V_47 ) -> V_68 . V_86 || ! V_36 -> V_87 || V_36 -> V_88 )
goto V_89;
if ( F_30 ( V_47 ) )
goto V_89;
V_39 = F_15 ( F_13 ( V_45 ) , V_36 , V_30 ) ;
if ( V_39 == 0 ) {
F_31 ( F_29 ( V_47 ) , V_90 ) ;
goto V_89;
}
F_31 ( F_29 ( V_47 ) , V_91 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
F_32 ( V_45 , & V_60 , 0 , NULL ) ;
if ( V_60 . V_62 && V_60 . V_61 ) {
V_50 = F_33 ( F_13 ( V_45 ) -> V_2 , F_13 ( V_45 ) -> V_1 ) ;
V_60 . V_61 -= V_50 ;
}
if ( ! F_23 ( & V_60 ) )
goto V_89;
V_80 = NULL ;
V_10 = F_34 ( & V_92 , V_47 , false ) ;
if ( ! V_10 )
goto V_89;
V_12 = F_5 ( V_10 ) ;
V_76 = F_35 ( V_10 ) ;
V_76 -> V_93 = F_11 ( V_36 -> V_43 ) - 1 ;
V_76 -> V_94 = V_30 ;
V_76 -> V_95 = 0 ;
V_10 -> V_39 = V_39 ;
V_12 -> V_96 = F_36 ( V_36 -> V_42 ) ;
V_12 -> V_97 = V_36 -> V_41 ;
F_37 ( F_38 ( V_10 ) , F_13 ( V_45 ) -> V_2 ) ;
F_39 ( F_38 ( V_10 ) , F_13 ( V_45 ) -> V_1 ) ;
V_12 -> V_98 = F_40 ( V_47 , V_45 ) ;
V_12 -> V_18 = V_60 . V_18 ;
V_12 -> V_20 = V_60 . V_20 ;
V_12 -> V_17 = V_60 . V_17 ;
V_12 -> V_99 = V_60 . V_62 ;
V_10 -> V_100 = V_60 . V_62 ? V_60 . V_101 : 0 ;
V_76 -> V_102 . V_103 = 0 ;
V_76 -> V_104 = false ;
V_12 -> V_105 = F_41 ( V_47 , V_45 ) ;
V_12 -> V_72 = F_42 ( V_45 ) ;
if ( F_43 ( V_47 , V_45 , V_10 ) ) {
F_22 ( V_10 ) ;
goto V_89;
}
V_10 -> V_106 = 0 ;
F_44 ( & V_85 , V_12 -> V_105 , V_12 -> V_98 ,
F_45 ( V_47 ) , V_107 , V_108 ,
F_46 ( V_47 ) ,
V_72 -> V_109 ? V_72 -> V_110 : V_12 -> V_111 ,
V_12 -> V_112 , V_36 -> V_41 , V_36 -> V_42 , V_47 -> V_113 ) ;
F_47 ( V_10 , F_48 ( & V_85 ) ) ;
V_82 = F_49 ( F_29 ( V_47 ) , & V_85 ) ;
if ( F_50 ( V_82 ) ) {
F_22 ( V_10 ) ;
goto V_89;
}
V_10 -> V_114 = V_78 -> V_115 ? : F_51 ( & V_82 -> V_49 , V_116 ) ;
F_52 ( F_53 ( V_47 ) , V_10 -> V_39 ,
& V_10 -> V_117 , & V_10 -> V_114 ,
V_12 -> V_17 , & V_83 ,
F_51 ( & V_82 -> V_49 , V_118 ) ) ;
V_12 -> V_83 = V_83 ;
V_12 -> V_22 = F_25 ( & V_60 , F_29 ( V_47 ) , & V_82 -> V_49 ) ;
V_80 = F_16 ( V_47 , V_45 , V_10 , & V_82 -> V_49 , V_50 ) ;
if ( V_80 )
F_54 ( V_80 ) -> V_119 . V_120 . V_121 . V_122 = V_85 ;
V_89: return V_80 ;
}
