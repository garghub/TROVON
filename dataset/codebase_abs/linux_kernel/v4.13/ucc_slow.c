T_1 F_1 ( int V_1 )
{
switch ( V_1 ) {
case 0 : return V_2 ;
case 1 : return V_3 ;
case 2 : return V_4 ;
case 3 : return V_5 ;
case 4 : return V_6 ;
case 5 : return V_7 ;
case 6 : return V_8 ;
case 7 : return V_9 ;
default: return V_10 ;
}
}
void F_2 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
T_1 V_15 ;
V_15 = F_1 ( V_14 -> V_16 ) ;
F_3 ( V_17 , V_15 ,
V_18 , 0 ) ;
}
void F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
T_1 V_15 ;
V_15 = F_1 ( V_14 -> V_16 ) ;
F_3 ( V_19 , V_15 , V_18 , 0 ) ;
}
void F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
T_1 V_15 ;
V_15 = F_1 ( V_14 -> V_16 ) ;
F_3 ( V_20 , V_15 , V_18 , 0 ) ;
}
void F_6 ( struct V_11 * V_12 , enum V_21 V_22 )
{
struct V_23 * V_24 ;
T_1 V_25 ;
V_24 = V_12 -> V_24 ;
V_25 = F_7 ( & V_24 -> V_25 ) ;
if ( V_22 & V_26 ) {
V_25 |= V_27 ;
V_12 -> V_28 = 1 ;
}
if ( V_22 & V_29 ) {
V_25 |= V_30 ;
V_12 -> V_31 = 1 ;
}
F_8 ( & V_24 -> V_25 , V_25 ) ;
}
void F_9 ( struct V_11 * V_12 , enum V_21 V_22 )
{
struct V_23 * V_24 ;
T_1 V_25 ;
V_24 = V_12 -> V_24 ;
V_25 = F_7 ( & V_24 -> V_25 ) ;
if ( V_22 & V_26 ) {
V_25 &= ~ V_27 ;
V_12 -> V_28 = 0 ;
}
if ( V_22 & V_29 ) {
V_25 &= ~ V_30 ;
V_12 -> V_31 = 0 ;
}
F_8 ( & V_24 -> V_25 , V_25 ) ;
}
int F_10 ( struct V_13 * V_14 , struct V_11 * * V_32 )
{
struct V_11 * V_12 ;
T_1 V_33 ;
struct V_23 T_2 * V_24 ;
T_1 V_34 ;
struct V_35 * V_36 ;
T_1 V_15 ;
T_1 V_37 ;
int V_38 = 0 ;
if ( ! V_14 )
return - V_39 ;
if ( ( V_14 -> V_16 < 0 ) || ( V_14 -> V_16 > V_40 - 1 ) ) {
F_11 ( V_41 L_1 , V_42 ) ;
return - V_39 ;
}
if ( ( ! V_14 -> V_43 ) &&
( V_14 -> V_44 & ( V_45 - 1 ) ) ) {
F_11 ( V_41 L_2 ) ;
return - V_39 ;
}
V_12 = F_12 ( sizeof( struct V_11 ) , V_46 ) ;
if ( ! V_12 ) {
F_11 ( V_41 L_3 ,
V_42 ) ;
return - V_47 ;
}
V_12 -> V_14 = V_14 ;
V_12 -> V_24 = F_13 ( V_14 -> V_48 , sizeof( struct V_23 ) ) ;
if ( V_12 -> V_24 == NULL ) {
F_11 ( V_41 L_4 , V_42 ) ;
F_14 ( V_12 ) ;
return - V_47 ;
}
V_12 -> V_49 = 0 ;
V_12 -> V_50 = 0 ;
V_24 = V_12 -> V_24 ;
V_12 -> V_51 = ( V_52 * ) & ( V_24 -> V_53 ) ;
V_12 -> V_54 = ( V_52 * ) & ( V_24 -> V_55 ) ;
#ifdef F_15
V_12 -> V_56 = 0 ;
V_12 -> V_57 = 0 ;
V_12 -> V_58 = 0 ;
#endif
V_12 -> V_59 =
F_16 ( V_60 , V_61 ) ;
if ( F_17 ( V_12 -> V_59 ) ) {
F_11 ( V_41 L_5 , V_42 ) ;
F_18 ( V_12 ) ;
return - V_47 ;
}
V_15 = F_1 ( V_14 -> V_16 ) ;
F_3 ( V_62 , V_15 , V_14 -> V_63 ,
V_12 -> V_59 ) ;
V_12 -> V_64 = F_19 ( V_12 -> V_59 ) ;
V_38 = F_20 ( V_14 -> V_16 , V_65 ) ;
if ( V_38 ) {
F_11 ( V_41 L_6 , V_42 ) ;
F_18 ( V_12 ) ;
return V_38 ;
}
F_21 ( & V_12 -> V_64 -> V_66 , V_14 -> V_44 ) ;
F_22 ( & V_12 -> V_67 ) ;
V_12 -> V_68 =
F_16 ( V_14 -> V_69 * sizeof( struct V_35 ) ,
V_70 ) ;
if ( F_17 ( V_12 -> V_68 ) ) {
F_11 ( V_41 L_7 , V_42 ,
V_14 -> V_69 ) ;
V_12 -> V_68 = 0 ;
F_18 ( V_12 ) ;
return - V_47 ;
}
V_12 -> V_71 =
F_16 ( V_14 -> V_72 * sizeof( struct V_35 ) ,
V_70 ) ;
if ( F_17 ( V_12 -> V_71 ) ) {
F_11 ( V_41 L_8 , V_42 ) ;
V_12 -> V_71 = 0 ;
F_18 ( V_12 ) ;
return - V_47 ;
}
V_36 = V_12 -> V_73 = V_12 -> V_74 = F_19 ( V_12 -> V_71 ) ;
for ( V_33 = 0 ; V_33 < V_14 -> V_72 - 1 ; V_33 ++ ) {
F_8 ( & V_36 -> V_75 , 0 ) ;
F_8 ( ( T_1 * ) V_36 , 0 ) ;
V_36 ++ ;
}
F_8 ( & V_36 -> V_75 , 0 ) ;
F_8 ( ( T_1 * ) V_36 , F_23 ( V_76 ) ) ;
V_36 = V_12 -> V_77 = F_19 ( V_12 -> V_68 ) ;
for ( V_33 = 0 ; V_33 < V_14 -> V_69 - 1 ; V_33 ++ ) {
F_8 ( ( T_1 * ) V_36 , 0 ) ;
F_8 ( & V_36 -> V_75 , 0 ) ;
V_36 ++ ;
}
F_8 ( ( T_1 * ) V_36 , F_23 ( V_78 ) ) ;
F_8 ( & V_36 -> V_75 , 0 ) ;
V_34 = V_14 -> V_79 ;
if ( V_14 -> V_80 )
V_34 |= V_81 ;
if ( V_14 -> V_82 )
V_34 |= V_83 ;
if ( V_14 -> V_84 )
V_34 |= V_85 ;
if ( V_14 -> V_86 )
V_34 |= V_87 ;
if ( V_14 -> V_88 )
V_34 |= V_89 ;
if ( V_14 -> V_43 )
V_34 |= V_90 ;
if ( V_14 -> V_91 )
V_34 |= V_92 ;
if ( V_14 -> V_93 )
V_34 |= V_94 ;
F_8 ( & V_24 -> V_95 , V_34 ) ;
V_34 = V_14 -> V_96 | V_14 -> V_97 | V_14 -> V_98 | V_14 -> V_99 |
V_14 -> V_100 | V_14 -> V_22 ;
if ( V_14 -> V_101 )
V_34 |= V_102 ;
if ( V_14 -> V_103 )
V_34 |= V_104 ;
if ( V_14 -> V_105 )
V_34 |= V_106 ;
if ( V_14 -> V_107 )
V_34 |= V_108 ;
F_8 ( & V_24 -> V_25 , V_34 ) ;
V_12 -> V_64 -> V_109 = V_110 ;
V_12 -> V_64 -> V_111 = V_110 ;
F_21 ( & V_12 -> V_64 -> V_112 , V_12 -> V_68 ) ;
F_21 ( & V_12 -> V_64 -> V_113 , V_12 -> V_71 ) ;
F_24 ( V_14 -> V_16 , V_14 -> V_114 ) ;
F_25 ( V_14 -> V_16 , V_14 -> V_115 ) ;
F_26 ( V_14 -> V_16 , V_14 -> V_116 ) ;
if ( ! V_14 -> V_116 ) {
if ( F_27 ( V_14 -> V_16 , V_14 -> V_117 ,
V_29 ) ) {
F_11 ( V_41 L_9 ,
V_42 ) ;
F_18 ( V_12 ) ;
return - V_39 ;
}
if ( F_27 ( V_14 -> V_16 , V_14 -> V_118 ,
V_26 ) ) {
F_11 ( V_41 L_10 ,
V_42 ) ;
F_18 ( V_12 ) ;
return - V_39 ;
}
}
F_21 ( & V_24 -> V_55 , V_14 -> V_119 ) ;
F_21 ( & V_24 -> V_53 , 0xffff ) ;
if ( V_14 -> V_120 && V_14 -> V_121 )
V_37 = V_122 ;
else if ( V_14 -> V_120 )
V_37 = V_123 ;
else
V_37 = V_124 ;
F_3 ( V_37 , V_15 , V_14 -> V_63 , 0 ) ;
* V_32 = V_12 ;
return 0 ;
}
void F_18 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
if ( V_12 -> V_68 )
F_28 ( V_12 -> V_68 ) ;
if ( V_12 -> V_71 )
F_28 ( V_12 -> V_71 ) ;
if ( V_12 -> V_64 )
F_28 ( V_12 -> V_59 ) ;
if ( V_12 -> V_24 )
F_29 ( V_12 -> V_24 ) ;
F_14 ( V_12 ) ;
}
