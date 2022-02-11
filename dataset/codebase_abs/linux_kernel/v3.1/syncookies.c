static T_1 int F_1 ( void )
{
F_2 ( V_1 , sizeof( V_1 ) ) ;
return 0 ;
}
static T_2 F_3 ( T_3 V_2 , T_3 V_3 , T_4 V_4 , T_4 V_5 ,
T_2 V_6 , int V_7 )
{
T_5 * V_8 = F_4 ( V_9 ) ;
memcpy ( V_8 + 4 , V_1 [ V_7 ] , sizeof( V_1 [ V_7 ] ) ) ;
V_8 [ 0 ] = ( V_10 T_2 ) V_2 ;
V_8 [ 1 ] = ( V_10 T_2 ) V_3 ;
V_8 [ 2 ] = ( ( V_10 T_2 ) V_4 << 16 ) + ( V_10 T_2 ) V_5 ;
V_8 [ 3 ] = V_6 ;
F_5 ( V_8 + 16 , ( V_11 * ) V_8 , V_8 + 16 + 5 ) ;
return V_8 [ 17 ] ;
}
T_5 F_6 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
T_2 V_16 , V_17 = V_18 ;
T_2 V_19 = 0 ;
V_15 = F_7 ( V_13 ) ;
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
static T_5 F_8 ( T_3 V_2 , T_3 V_3 , T_4 V_4 ,
T_4 V_5 , T_5 V_26 , T_5 V_6 ,
T_5 V_27 )
{
return ( F_3 ( V_2 , V_3 , V_4 , V_5 , 0 , 0 ) +
V_26 + ( V_6 << V_28 ) +
( ( F_3 ( V_2 , V_3 , V_4 , V_5 , V_6 , 1 ) + V_27 )
& V_29 ) ) ;
}
static T_5 F_9 ( T_5 V_30 , T_3 V_2 , T_3 V_3 ,
T_4 V_4 , T_4 V_5 , T_5 V_26 ,
T_5 V_6 , T_5 V_31 )
{
T_5 V_32 ;
V_30 -= F_3 ( V_2 , V_3 , V_4 , V_5 , 0 , 0 ) + V_26 ;
V_32 = ( V_6 - ( V_30 >> V_28 ) ) & ( ( T_5 ) - 1 >> V_28 ) ;
if ( V_32 >= V_31 )
return ( T_5 ) - 1 ;
return ( V_30 -
F_3 ( V_2 , V_3 , V_4 , V_5 , V_6 - V_32 , 1 ) )
& V_29 ;
}
T_5 F_10 ( struct V_33 * V_34 , struct V_35 * V_36 , T_6 * V_37 )
{
const struct V_38 * V_39 = F_11 ( V_36 ) ;
const struct V_40 * V_41 = F_12 ( V_36 ) ;
int V_42 ;
const T_6 V_43 = * V_37 ;
F_13 ( V_34 ) ;
for ( V_42 = F_14 ( V_44 ) - 1 ; V_42 ; V_42 -- )
if ( V_43 >= V_44 [ V_42 ] )
break;
* V_37 = V_44 [ V_42 ] ;
F_15 ( F_16 ( V_34 ) , V_45 ) ;
return F_8 ( V_39 -> V_2 , V_39 -> V_3 ,
V_41 -> V_46 , V_41 -> V_47 , F_17 ( V_41 -> V_48 ) ,
V_49 / ( V_50 * 60 ) , V_42 ) ;
}
static inline int F_18 ( struct V_35 * V_36 , T_5 V_30 )
{
const struct V_38 * V_39 = F_11 ( V_36 ) ;
const struct V_40 * V_41 = F_12 ( V_36 ) ;
T_5 V_48 = F_17 ( V_41 -> V_48 ) - 1 ;
T_5 V_42 = F_9 ( V_30 , V_39 -> V_2 , V_39 -> V_3 ,
V_41 -> V_46 , V_41 -> V_47 , V_48 ,
V_49 / ( V_50 * 60 ) ,
V_51 ) ;
return V_42 < F_14 ( V_44 ) ? V_44 [ V_42 ] : 0 ;
}
static inline struct V_33 * F_19 ( struct V_33 * V_34 , struct V_35 * V_36 ,
struct V_12 * V_13 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_20 ( V_34 ) ;
struct V_33 * V_56 ;
V_56 = V_55 -> V_57 -> V_58 ( V_34 , V_36 , V_13 , V_53 ) ;
if ( V_56 )
F_21 ( V_34 , V_13 , V_56 ) ;
else
F_22 ( V_13 ) ;
return V_56 ;
}
bool F_23 ( struct V_59 * V_60 , bool * V_23 )
{
T_2 V_19 = V_60 -> V_61 & V_24 ;
if ( ! V_60 -> V_62 ) {
F_24 ( V_60 ) ;
return true ;
}
if ( ! V_63 )
return false ;
V_60 -> V_22 = ( V_19 >> 4 ) & 0x1 ;
* V_23 = ( V_19 >> 5 ) & 1 ;
if ( * V_23 && ! V_64 )
return false ;
if ( V_60 -> V_22 && ! V_65 )
return false ;
if ( ( V_19 & 0xf ) == 0xf )
return true ;
V_60 -> V_20 = 1 ;
V_60 -> V_21 = V_19 & 0xf ;
return V_66 != 0 ;
}
struct V_33 * F_25 ( struct V_33 * V_34 , struct V_35 * V_36 ,
struct V_67 * V_68 )
{
struct V_59 V_60 ;
T_7 * V_69 ;
struct V_14 * V_15 ;
struct V_70 * V_71 ;
struct V_72 * V_73 = F_26 ( V_34 ) ;
const struct V_40 * V_41 = F_12 ( V_36 ) ;
T_5 V_30 = F_17 ( V_41 -> V_74 ) - 1 ;
struct V_33 * V_75 = V_34 ;
struct V_12 * V_13 ;
int V_43 ;
struct V_76 * V_77 ;
V_11 V_78 ;
bool V_23 = false ;
if ( ! V_79 || ! V_41 -> V_80 || V_41 -> V_81 )
goto V_82;
if ( F_27 ( V_34 ) ||
( V_43 = F_18 ( V_36 , V_30 ) ) == 0 ) {
F_15 ( F_16 ( V_34 ) , V_83 ) ;
goto V_82;
}
F_15 ( F_16 ( V_34 ) , V_84 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
F_28 ( V_36 , & V_60 , & V_69 , 0 ) ;
if ( ! F_23 ( & V_60 , & V_23 ) )
goto V_82;
V_75 = NULL ;
V_13 = F_29 ( & V_85 ) ;
if ( ! V_13 )
goto V_82;
V_15 = F_7 ( V_13 ) ;
V_71 = F_30 ( V_13 ) ;
V_71 -> V_86 = F_17 ( V_41 -> V_48 ) - 1 ;
V_71 -> V_87 = V_30 ;
V_13 -> V_43 = V_43 ;
V_15 -> V_88 = V_41 -> V_47 ;
V_15 -> V_89 = V_41 -> V_46 ;
V_15 -> V_90 = F_11 ( V_36 ) -> V_3 ;
V_15 -> V_91 = F_11 ( V_36 ) -> V_2 ;
V_15 -> V_23 = V_23 ;
V_15 -> V_21 = V_60 . V_21 ;
V_15 -> V_22 = V_60 . V_22 ;
V_15 -> V_20 = V_60 . V_20 ;
V_15 -> V_92 = V_60 . V_62 ;
V_13 -> V_93 = V_60 . V_62 ? V_60 . V_94 : 0 ;
V_71 -> V_95 = V_60 . V_62 ? V_60 . V_61 : 0 ;
if ( V_68 && V_68 -> V_96 ) {
int V_97 = sizeof( struct V_98 ) + V_68 -> V_96 ;
V_15 -> V_68 = F_31 ( V_97 , V_99 ) ;
if ( V_15 -> V_68 != NULL && F_32 ( & V_15 -> V_68 -> V_68 , V_36 ) ) {
F_33 ( V_15 -> V_68 ) ;
V_15 -> V_68 = NULL ;
}
}
if ( F_34 ( V_34 , V_36 , V_13 ) ) {
F_22 ( V_13 ) ;
goto V_82;
}
V_13 -> V_100 = 0UL ;
V_13 -> V_101 = 0 ;
{
struct V_102 V_103 ;
F_35 ( & V_103 , 0 , V_34 -> V_104 , F_36 ( V_34 ) ,
V_105 , V_106 ,
F_37 ( V_34 ) ,
( V_68 && V_68 -> V_107 ) ? V_68 -> V_108 : V_15 -> V_91 ,
V_15 -> V_90 , V_41 -> V_46 , V_41 -> V_47 ) ;
F_38 ( V_13 , F_39 ( & V_103 ) ) ;
V_77 = F_40 ( F_16 ( V_34 ) , & V_103 ) ;
if ( F_41 ( V_77 ) ) {
F_22 ( V_13 ) ;
goto V_82;
}
}
V_13 -> V_109 = V_73 -> V_109 ? : F_42 ( & V_77 -> V_53 , V_110 ) ;
F_43 ( F_44 ( V_34 ) , V_13 -> V_43 ,
& V_13 -> V_111 , & V_13 -> V_109 ,
V_15 -> V_20 , & V_78 ,
F_42 ( & V_77 -> V_53 , V_112 ) ) ;
V_15 -> V_78 = V_78 ;
V_75 = F_19 ( V_34 , V_36 , V_13 , & V_77 -> V_53 ) ;
V_82: return V_75 ;
}
