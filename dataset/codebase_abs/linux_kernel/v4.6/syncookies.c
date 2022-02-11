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
T_4 F_13 ( const struct V_47 * V_48 , T_6 * V_40 )
{
const struct V_36 * V_37 = F_14 ( V_48 ) ;
const struct V_38 * V_39 = F_15 ( V_48 ) ;
return F_10 ( V_37 , V_39 , V_40 ) ;
}
int F_16 ( const struct V_36 * V_37 , const struct V_38 * V_39 ,
T_1 V_33 )
{
T_4 V_46 = F_12 ( V_39 -> V_46 ) - 1 ;
T_4 V_41 = F_9 ( V_33 , V_37 -> V_1 , V_37 -> V_2 ,
V_39 -> V_44 , V_39 -> V_45 , V_46 ) ;
return V_41 < F_11 ( V_43 ) ? V_43 [ V_41 ] : 0 ;
}
struct V_49 * F_17 ( struct V_49 * V_50 , struct V_47 * V_48 ,
struct V_12 * V_13 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 = F_18 ( V_50 ) ;
struct V_49 * V_55 ;
bool V_56 ;
V_55 = V_54 -> V_57 -> V_58 ( V_50 , V_48 , V_13 , V_52 ,
NULL , & V_56 ) ;
if ( V_55 ) {
F_19 ( & V_13 -> V_59 , 1 ) ;
F_20 ( V_55 , V_48 ) ;
F_21 ( V_50 , V_13 , V_55 ) ;
} else {
F_22 ( V_13 ) ;
}
return V_55 ;
}
bool F_23 ( struct V_60 * V_61 )
{
T_1 V_19 = V_61 -> V_62 ;
if ( ! V_61 -> V_63 ) {
F_24 ( V_61 ) ;
return true ;
}
if ( ! V_64 )
return false ;
V_61 -> V_23 = ( V_19 & V_24 ) ? V_65 : 0 ;
if ( V_61 -> V_23 && ! V_66 )
return false ;
if ( ( V_19 & V_22 ) == V_22 )
return true ;
V_61 -> V_20 = 1 ;
V_61 -> V_21 = V_19 & V_22 ;
return V_67 != 0 ;
}
bool F_25 ( const struct V_60 * V_61 ,
const struct V_68 * V_68 , const struct V_51 * V_52 )
{
bool V_25 = V_61 -> V_62 & V_26 ;
if ( ! V_25 )
return false ;
if ( V_68 -> V_69 . V_70 )
return true ;
return F_26 ( V_52 , V_71 ) ;
}
struct V_49 * F_27 ( struct V_49 * V_50 , struct V_47 * V_48 )
{
struct V_72 * V_73 = & F_28 ( V_48 ) -> V_74 . V_75 . V_73 ;
struct V_60 V_61 ;
struct V_14 * V_15 ;
struct V_76 * V_77 ;
struct V_78 * V_79 = F_29 ( V_50 ) ;
const struct V_38 * V_39 = F_15 ( V_48 ) ;
T_4 V_33 = F_12 ( V_39 -> V_80 ) - 1 ;
struct V_49 * V_81 = V_50 ;
struct V_12 * V_13 ;
int V_42 ;
struct V_82 * V_83 ;
V_11 V_84 ;
struct V_85 V_86 ;
if ( ! F_30 ( V_50 ) -> V_69 . V_87 || ! V_39 -> V_88 || V_39 -> V_89 )
goto V_90;
if ( F_31 ( V_50 ) )
goto V_90;
V_42 = F_16 ( F_14 ( V_48 ) , V_39 , V_33 ) ;
if ( V_42 == 0 ) {
F_32 ( F_30 ( V_50 ) , V_91 ) ;
goto V_90;
}
F_32 ( F_30 ( V_50 ) , V_92 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
F_33 ( V_48 , & V_61 , 0 , NULL ) ;
if ( ! F_23 ( & V_61 ) )
goto V_90;
V_81 = NULL ;
V_13 = F_34 ( & V_93 , V_50 , false ) ;
if ( ! V_13 )
goto V_90;
V_15 = F_6 ( V_13 ) ;
V_77 = F_35 ( V_13 ) ;
V_77 -> V_94 = F_12 ( V_39 -> V_46 ) - 1 ;
V_77 -> V_95 = V_33 ;
V_13 -> V_42 = V_42 ;
V_15 -> V_96 = F_36 ( V_39 -> V_45 ) ;
V_15 -> V_97 = V_39 -> V_44 ;
F_37 ( F_38 ( V_13 ) , F_14 ( V_48 ) -> V_2 ) ;
F_39 ( F_38 ( V_13 ) , F_14 ( V_48 ) -> V_1 ) ;
V_15 -> V_98 = F_40 ( V_50 , V_48 ) ;
V_15 -> V_21 = V_61 . V_21 ;
V_15 -> V_23 = V_61 . V_23 ;
V_15 -> V_20 = V_61 . V_20 ;
V_15 -> V_99 = V_61 . V_63 ;
V_13 -> V_100 = V_61 . V_63 ? V_61 . V_101 : 0 ;
V_77 -> V_102 . V_103 = 0 ;
V_77 -> V_104 = false ;
V_15 -> V_105 = F_41 ( V_50 , V_48 ) ;
V_15 -> V_73 = F_42 ( V_48 ) ;
if ( F_43 ( V_50 , V_48 , V_13 ) ) {
F_22 ( V_13 ) ;
goto V_90;
}
V_13 -> V_106 = 0 ;
F_44 ( & V_86 , V_15 -> V_105 , V_15 -> V_98 ,
F_45 ( V_50 ) , V_107 , V_108 ,
F_46 ( V_50 ) ,
V_73 -> V_109 ? V_73 -> V_110 : V_15 -> V_111 ,
V_15 -> V_112 , V_39 -> V_44 , V_39 -> V_45 ) ;
F_47 ( V_13 , F_48 ( & V_86 ) ) ;
V_83 = F_49 ( F_30 ( V_50 ) , & V_86 ) ;
if ( F_50 ( V_83 ) ) {
F_22 ( V_13 ) ;
goto V_90;
}
V_13 -> V_113 = V_79 -> V_114 ? : F_51 ( & V_83 -> V_52 , V_115 ) ;
F_52 ( F_53 ( V_50 ) , V_13 -> V_42 ,
& V_13 -> V_116 , & V_13 -> V_113 ,
V_15 -> V_20 , & V_84 ,
F_51 ( & V_83 -> V_52 , V_117 ) ) ;
V_15 -> V_84 = V_84 ;
V_15 -> V_25 = F_25 ( & V_61 , F_30 ( V_50 ) , & V_83 -> V_52 ) ;
V_81 = F_17 ( V_50 , V_48 , V_13 , & V_83 -> V_52 ) ;
if ( V_81 )
F_54 ( V_81 ) -> V_118 . V_119 . V_120 . V_121 = V_86 ;
V_90: return V_81 ;
}
