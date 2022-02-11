void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 . V_7 ;
T_1 V_8 = V_2 -> V_9 -> V_5 . V_10 . V_11 ;
if ( V_4 -> V_12 & V_13 ) {
unsigned long V_14 = V_4 -> V_15 ;
int V_16 ;
F_2 (lr, &eisr_bmap, kvm_vgic_global_state.nr_lr) {
T_1 V_17 ;
T_2 V_18 = V_4 -> V_19 [ V_16 ] ;
if ( V_8 == V_20 )
V_17 = V_18 & V_21 ;
else
V_17 = V_18 & V_22 ;
F_3 ( V_4 -> V_19 [ V_16 ] & V_23 ) ;
F_4 ( V_2 -> V_9 , 0 ,
V_17 - V_24 ) ;
}
V_4 -> V_15 = 0 ;
}
V_4 -> V_25 &= ~ V_26 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 . V_7 ;
V_4 -> V_25 |= V_26 ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 . V_7 ;
T_1 V_8 = V_2 -> V_9 -> V_5 . V_10 . V_11 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 . V_6 . V_27 ; V_16 ++ ) {
T_2 V_18 = V_4 -> V_19 [ V_16 ] ;
T_1 V_17 ;
struct V_28 * V_29 ;
if ( V_8 == V_20 )
V_17 = V_18 & V_21 ;
else
V_17 = V_18 & V_22 ;
V_29 = F_7 ( V_2 -> V_9 , V_2 , V_17 ) ;
if ( ! V_29 )
continue;
F_8 ( & V_29 -> V_30 ) ;
V_29 -> V_31 = ! ! ( V_18 & V_32 ) ;
if ( V_29 -> V_33 == V_34 &&
( V_18 & V_35 ) ) {
V_29 -> V_36 = true ;
if ( F_9 ( V_17 ) &&
V_8 == V_37 ) {
T_1 V_38 = V_18 & V_39 ;
V_38 >>= V_40 ;
V_29 -> V_41 |= ( 1 << V_38 ) ;
}
}
if ( V_29 -> V_33 == V_42 ) {
if ( ! ( V_18 & V_35 ) )
V_29 -> V_43 = false ;
V_29 -> V_36 = V_29 -> V_44 || V_29 -> V_43 ;
}
F_10 ( & V_29 -> V_30 ) ;
F_11 ( V_2 -> V_9 , V_29 ) ;
}
}
void F_12 ( struct V_1 * V_2 , struct V_28 * V_29 , int V_16 )
{
T_1 V_8 = V_2 -> V_9 -> V_5 . V_10 . V_11 ;
T_2 V_18 = V_29 -> V_17 ;
if ( V_29 -> V_36 ) {
V_18 |= V_35 ;
if ( V_29 -> V_33 == V_34 )
V_29 -> V_36 = false ;
if ( F_9 ( V_29 -> V_17 ) &&
V_8 == V_37 ) {
T_1 V_45 = F_13 ( V_29 -> V_41 ) ;
F_14 ( ! V_45 ) ;
V_18 |= ( V_45 - 1 ) << V_40 ;
V_29 -> V_41 &= ~ ( 1 << ( V_45 - 1 ) ) ;
if ( V_29 -> V_41 )
V_29 -> V_36 = true ;
}
}
if ( V_29 -> V_31 )
V_18 |= V_32 ;
if ( V_29 -> V_46 ) {
V_18 |= V_47 ;
V_18 |= ( ( T_2 ) V_29 -> V_48 ) << V_49 ;
} else {
if ( V_29 -> V_33 == V_42 )
V_18 |= V_50 ;
}
if ( V_8 == V_20 )
V_18 |= V_51 ;
V_18 |= ( T_2 ) V_29 -> V_52 << V_53 ;
V_2 -> V_5 . V_6 . V_7 . V_19 [ V_16 ] = V_18 ;
}
void F_15 ( struct V_1 * V_2 , int V_16 )
{
V_2 -> V_5 . V_6 . V_7 . V_19 [ V_16 ] = 0 ;
}
void F_16 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
T_1 V_56 ;
V_56 = ( V_55 -> V_57 << V_58 ) & V_59 ;
V_56 |= ( V_55 -> V_60 << V_61 ) & V_62 ;
V_56 |= ( V_55 -> V_63 << V_64 ) & V_65 ;
V_56 |= ( V_55 -> V_66 << V_67 ) & V_68 ;
V_2 -> V_5 . V_6 . V_7 . V_54 = V_56 ;
}
void F_17 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
T_1 V_56 = V_2 -> V_5 . V_6 . V_7 . V_54 ;
V_55 -> V_57 = ( V_56 & V_59 ) >> V_58 ;
V_55 -> V_60 = ( V_56 & V_62 ) >> V_61 ;
V_55 -> V_63 = ( V_56 & V_65 ) >> V_64 ;
V_55 -> V_66 = ( V_56 & V_68 ) >> V_67 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_7 = & V_2 -> V_5 . V_6 . V_7 ;
V_7 -> V_54 = 0 ;
V_7 -> V_69 = ~ 0 ;
if ( V_2 -> V_9 -> V_5 . V_10 . V_11 == V_20 ) {
V_7 -> V_70 = V_71 ;
V_2 -> V_5 . V_6 . V_72 = V_73 ;
} else {
V_7 -> V_70 = 0 ;
}
V_7 -> V_25 = V_74 ;
}
static bool F_19 ( struct V_9 * V_9 )
{
struct V_75 * V_76 = & V_9 -> V_5 . V_10 ;
T_3 V_77 = V_78 ;
V_77 *= F_20 ( & V_9 -> V_79 ) ;
if ( V_76 -> V_80 + V_81 < V_76 -> V_80 )
return false ;
if ( V_76 -> V_82 + V_77 < V_76 -> V_82 )
return false ;
if ( V_76 -> V_80 + V_81 <= V_76 -> V_82 )
return true ;
if ( V_76 -> V_82 + V_77 <= V_76 -> V_80 )
return true ;
return false ;
}
int F_21 ( struct V_9 * V_9 )
{
int V_83 = 0 ;
struct V_75 * V_84 = & V_9 -> V_5 . V_10 ;
if ( F_22 ( V_9 ) )
goto V_85;
if ( F_23 ( V_84 -> V_80 ) ||
F_23 ( V_84 -> V_82 ) ) {
F_24 ( L_1 ) ;
V_83 = - V_86 ;
goto V_85;
}
if ( ! F_19 ( V_9 ) ) {
F_24 ( L_2 ) ;
V_83 = - V_87 ;
goto V_85;
}
if ( ! F_25 ( V_9 ) ) {
V_83 = - V_88 ;
goto V_85;
}
V_83 = F_26 ( V_9 , V_84 -> V_80 , V_89 ) ;
if ( V_83 ) {
F_24 ( L_3 ) ;
goto V_85;
}
V_83 = F_27 ( V_9 , V_84 -> V_82 ) ;
if ( V_83 ) {
F_24 ( L_4 ) ;
goto V_85;
}
if ( F_28 ( V_9 ) ) {
V_83 = F_29 ( V_9 ) ;
if ( V_83 ) {
F_24 ( L_5 ) ;
goto V_85;
}
}
V_84 -> V_90 = true ;
V_85:
if ( V_83 )
F_30 ( V_9 ) ;
return V_83 ;
}
int F_31 ( const struct V_91 * V_92 )
{
T_1 V_93 = F_32 ( V_94 ) ;
int V_83 ;
V_95 . V_96 = ( V_93 & 0xf ) + 1 ;
V_95 . V_97 = false ;
if ( ! V_92 -> V_2 . V_98 ) {
F_33 ( L_6 ) ;
V_95 . V_99 = 0 ;
} else if ( ! F_34 ( V_92 -> V_2 . V_98 ) ) {
F_35 ( L_7 ,
( unsigned long long ) V_92 -> V_2 . V_98 ) ;
V_95 . V_99 = 0 ;
} else if ( ! F_34 ( F_36 ( & V_92 -> V_2 ) ) ) {
F_35 ( L_8 ,
( unsigned long long ) F_36 ( & V_92 -> V_2 ) ,
V_100 ) ;
V_95 . V_99 = 0 ;
} else {
V_95 . V_99 = V_92 -> V_2 . V_98 ;
V_95 . V_97 = true ;
V_83 = F_37 ( V_37 ) ;
if ( V_83 ) {
F_24 ( L_9 ) ;
return V_83 ;
}
F_33 ( L_10 , V_92 -> V_2 . V_98 ) ;
}
V_83 = F_37 ( V_20 ) ;
if ( V_83 ) {
F_24 ( L_11 ) ;
F_38 ( V_37 ) ;
return V_83 ;
}
if ( V_95 . V_99 == 0 )
F_33 ( L_12 ) ;
V_95 . V_101 = NULL ;
V_95 . type = V_89 ;
V_95 . V_102 = V_103 ;
return 0 ;
}
