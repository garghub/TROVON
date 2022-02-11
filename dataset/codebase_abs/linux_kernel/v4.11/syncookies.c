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
struct V_48 * V_49 )
{
struct V_50 * V_51 = F_17 ( V_47 ) ;
struct V_46 * V_52 ;
bool V_53 ;
V_52 = V_51 -> V_54 -> V_55 ( V_47 , V_45 , V_10 , V_49 ,
NULL , & V_53 ) ;
if ( V_52 ) {
F_18 ( & V_10 -> V_56 , 1 ) ;
F_19 ( V_52 , V_45 ) ;
F_20 ( V_47 , V_10 , V_52 ) ;
} else {
F_21 ( V_10 ) ;
}
return V_52 ;
}
bool F_22 ( struct V_57 * V_58 )
{
T_1 V_16 = V_58 -> V_59 ;
if ( ! V_58 -> V_60 ) {
F_23 ( V_58 ) ;
return true ;
}
if ( ! V_61 )
return false ;
V_58 -> V_20 = ( V_16 & V_21 ) ? V_62 : 0 ;
if ( V_58 -> V_20 && ! V_63 )
return false ;
if ( ( V_16 & V_19 ) == V_19 )
return true ;
V_58 -> V_17 = 1 ;
V_58 -> V_18 = V_16 & V_19 ;
return V_64 != 0 ;
}
bool F_24 ( const struct V_57 * V_58 ,
const struct V_65 * V_65 , const struct V_48 * V_49 )
{
bool V_22 = V_58 -> V_59 & V_23 ;
if ( ! V_22 )
return false ;
if ( V_65 -> V_66 . V_67 )
return true ;
return F_25 ( V_49 , V_68 ) ;
}
struct V_46 * F_26 ( struct V_46 * V_47 , struct V_44 * V_45 )
{
struct V_69 * V_70 = & F_27 ( V_45 ) -> V_71 . V_72 . V_70 ;
struct V_57 V_58 ;
struct V_11 * V_12 ;
struct V_73 * V_74 ;
struct V_75 * V_76 = F_28 ( V_47 ) ;
const struct V_35 * V_36 = F_14 ( V_45 ) ;
T_4 V_30 = F_11 ( V_36 -> V_77 ) - 1 ;
struct V_46 * V_78 = V_47 ;
struct V_9 * V_10 ;
int V_39 ;
struct V_79 * V_80 ;
T_7 V_81 ;
struct V_82 V_83 ;
if ( ! F_29 ( V_47 ) -> V_66 . V_84 || ! V_36 -> V_85 || V_36 -> V_86 )
goto V_87;
if ( F_30 ( V_47 ) )
goto V_87;
V_39 = F_15 ( F_13 ( V_45 ) , V_36 , V_30 ) ;
if ( V_39 == 0 ) {
F_31 ( F_29 ( V_47 ) , V_88 ) ;
goto V_87;
}
F_31 ( F_29 ( V_47 ) , V_89 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
F_32 ( V_45 , & V_58 , 0 , NULL ) ;
if ( ! F_22 ( & V_58 ) )
goto V_87;
V_78 = NULL ;
V_10 = F_33 ( & V_90 , V_47 , false ) ;
if ( ! V_10 )
goto V_87;
V_12 = F_5 ( V_10 ) ;
V_74 = F_34 ( V_10 ) ;
V_74 -> V_91 = F_11 ( V_36 -> V_43 ) - 1 ;
V_74 -> V_92 = V_30 ;
V_74 -> V_93 = 0 ;
V_10 -> V_39 = V_39 ;
V_12 -> V_94 = F_35 ( V_36 -> V_42 ) ;
V_12 -> V_95 = V_36 -> V_41 ;
F_36 ( F_37 ( V_10 ) , F_13 ( V_45 ) -> V_2 ) ;
F_38 ( F_37 ( V_10 ) , F_13 ( V_45 ) -> V_1 ) ;
V_12 -> V_96 = F_39 ( V_47 , V_45 ) ;
V_12 -> V_18 = V_58 . V_18 ;
V_12 -> V_20 = V_58 . V_20 ;
V_12 -> V_17 = V_58 . V_17 ;
V_12 -> V_97 = V_58 . V_60 ;
V_10 -> V_98 = V_58 . V_60 ? V_58 . V_99 : 0 ;
V_74 -> V_100 . V_101 = 0 ;
V_74 -> V_102 = false ;
V_12 -> V_103 = F_40 ( V_47 , V_45 ) ;
V_12 -> V_70 = F_41 ( V_45 ) ;
if ( F_42 ( V_47 , V_45 , V_10 ) ) {
F_21 ( V_10 ) ;
goto V_87;
}
V_10 -> V_104 = 0 ;
F_43 ( & V_83 , V_12 -> V_103 , V_12 -> V_96 ,
F_44 ( V_47 ) , V_105 , V_106 ,
F_45 ( V_47 ) ,
V_70 -> V_107 ? V_70 -> V_108 : V_12 -> V_109 ,
V_12 -> V_110 , V_36 -> V_41 , V_36 -> V_42 , V_47 -> V_111 ) ;
F_46 ( V_10 , F_47 ( & V_83 ) ) ;
V_80 = F_48 ( F_29 ( V_47 ) , & V_83 ) ;
if ( F_49 ( V_80 ) ) {
F_21 ( V_10 ) ;
goto V_87;
}
V_10 -> V_112 = V_76 -> V_113 ? : F_50 ( & V_80 -> V_49 , V_114 ) ;
F_51 ( F_52 ( V_47 ) , V_10 -> V_39 ,
& V_10 -> V_115 , & V_10 -> V_112 ,
V_12 -> V_17 , & V_81 ,
F_50 ( & V_80 -> V_49 , V_116 ) ) ;
V_12 -> V_81 = V_81 ;
V_12 -> V_22 = F_24 ( & V_58 , F_29 ( V_47 ) , & V_80 -> V_49 ) ;
V_78 = F_16 ( V_47 , V_45 , V_10 , & V_80 -> V_49 ) ;
if ( V_78 )
F_53 ( V_78 ) -> V_117 . V_118 . V_119 . V_120 = V_83 ;
V_87: return V_78 ;
}
