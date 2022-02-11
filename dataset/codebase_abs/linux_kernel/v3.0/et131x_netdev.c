struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( struct V_3 ) ) ;
if ( V_2 == NULL ) {
F_3 ( V_4 L_1 ) ;
return NULL ;
}
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = & V_8 ;
return V_2 ;
}
struct V_9 * F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_10 = F_5 ( V_2 ) ;
struct V_9 * V_11 = & V_10 -> V_12 ;
T_1 * V_13 = & V_10 -> V_14 ;
V_11 -> V_15 = V_13 -> V_16 ;
V_11 -> V_17 = V_13 -> V_18 ;
V_11 -> V_19 = V_13 -> V_20 + V_13 -> V_21 +
V_13 -> V_22 + V_13 -> V_23 + V_13 -> V_24 ;
V_11 -> V_25 = V_13 -> V_26 ;
V_11 -> V_27 = V_13 -> V_28 ;
V_11 -> V_29 = V_13 -> V_29 ;
V_11 -> V_30 = V_13 -> V_20 ;
V_11 -> V_31 = V_13 -> V_32 ;
V_11 -> V_33 = V_13 -> V_22 ;
return V_11 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_34 = 0 ;
struct V_3 * V_10 = F_5 ( V_2 ) ;
F_7 ( & V_10 -> V_35 ) ;
V_34 = F_8 ( V_2 -> V_36 , V_37 , V_38 ,
V_2 -> V_39 , V_2 ) ;
if ( V_34 ) {
F_9 ( & V_10 -> V_40 -> V_41 , L_2 ,
V_2 -> V_36 ) ;
return V_34 ;
}
F_10 ( V_10 ) ;
F_11 ( V_10 ) ;
F_12 ( V_10 ) ;
V_10 -> V_42 |= V_43 ;
F_13 ( V_2 ) ;
return V_34 ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_10 = F_5 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( V_10 ) ;
F_17 ( V_10 ) ;
F_18 ( V_10 ) ;
V_10 -> V_42 &= ~ V_43 ;
F_19 ( V_2 -> V_36 , V_2 ) ;
F_20 ( & V_10 -> V_35 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , struct V_44 * V_45 , int V_46 )
{
int V_47 = 0 ;
struct V_3 * V_48 = F_5 ( V_2 ) ;
struct V_49 * V_50 = F_22 ( V_45 ) ;
switch ( V_46 ) {
case V_51 :
V_50 -> V_52 = V_48 -> V_14 . V_53 ;
break;
case V_54 :
if ( ! F_23 ( V_55 ) )
V_47 = - V_56 ;
else
V_47 = F_24 ( V_48 ,
V_50 -> V_57 , & V_50 -> V_58 ) ;
break;
case V_59 :
if ( ! F_23 ( V_55 ) )
V_47 = - V_56 ;
else
V_47 = F_25 ( V_48 , V_50 -> V_57 ,
V_50 -> V_60 ) ;
break;
default:
V_47 = - V_61 ;
}
return V_47 ;
}
int F_26 ( struct V_1 * V_2 , struct V_44 * V_45 , int V_46 )
{
int V_47 = 0 ;
switch ( V_46 ) {
case V_51 :
case V_54 :
case V_59 :
V_47 = F_21 ( V_2 , V_45 , V_46 ) ;
break;
default:
V_47 = - V_61 ;
}
return V_47 ;
}
int F_27 ( struct V_3 * V_10 )
{
int V_47 = 0 ;
T_2 V_62 = V_10 -> V_63 ;
T_3 V_64 ;
T_3 V_65 ;
V_64 = F_28 ( & V_10 -> V_66 -> V_67 . V_64 ) ;
V_65 = F_28 ( & V_10 -> V_66 -> V_67 . V_65 ) ;
V_64 |= 0x04 ;
if ( ( V_62 & V_68 ) || V_62 == 0 )
V_65 &= ~ 7 ;
else {
if ( V_62 & V_69 )
V_65 &= ~ 2 ;
else {
F_29 ( V_10 ) ;
V_65 |= 2 ;
V_64 &= ~ 0x04 ;
}
if ( V_62 & V_70 ) {
F_30 ( V_10 ) ;
V_65 |= 4 ;
V_64 &= ~ 0x04 ;
}
if ( V_62 & V_71 ) {
V_65 |= 1 ;
V_64 &= ~ 0x04 ;
} else
V_65 &= ~ 1 ;
F_31 ( V_65 , & V_10 -> V_66 -> V_67 . V_65 ) ;
F_31 ( V_64 , & V_10 -> V_66 -> V_67 . V_64 ) ;
}
return V_47 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_10 = F_5 ( V_2 ) ;
T_2 V_63 = 0 ;
unsigned long V_72 ;
struct V_73 * V_74 ;
int V_75 ;
F_33 ( & V_10 -> V_76 , V_72 ) ;
V_63 = V_10 -> V_63 ;
V_63 &= ~ V_77 ;
if ( V_2 -> V_72 & V_78 )
V_10 -> V_63 |= V_68 ;
else
V_10 -> V_63 &= ~ V_68 ;
if ( V_2 -> V_72 & V_79 )
V_10 -> V_63 |= V_69 ;
if ( F_34 ( V_2 ) > V_80 )
V_10 -> V_63 |= V_69 ;
if ( F_34 ( V_2 ) < 1 ) {
V_10 -> V_63 &= ~ V_69 ;
V_10 -> V_63 &= ~ V_77 ;
} else
V_10 -> V_63 |= V_77 ;
V_75 = 0 ;
F_35 (ha, netdev) {
if ( V_75 == V_80 )
break;
memcpy ( V_10 -> V_81 [ V_75 ++ ] , V_74 -> V_82 , V_83 ) ;
}
V_10 -> V_84 = V_75 ;
if ( V_63 != V_10 -> V_63 ) {
F_27 ( V_10 ) ;
}
F_36 ( & V_10 -> V_76 , V_72 ) ;
}
int F_37 ( struct V_85 * V_86 , struct V_1 * V_2 )
{
int V_47 = 0 ;
V_2 -> V_87 = V_88 ;
V_47 = F_38 ( V_86 , V_2 ) ;
if ( V_47 != 0 ) {
if ( V_47 == - V_89 ) {
F_15 ( V_2 ) ;
V_47 = V_90 ;
} else {
V_47 = V_91 ;
}
}
return V_47 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_48 = F_5 ( V_2 ) ;
struct V_92 * V_92 ;
unsigned long V_72 ;
if ( V_48 -> V_42 & V_93 )
return;
if ( V_48 -> V_42 & V_94 )
return;
if ( V_48 -> V_42 & V_95 ) {
F_9 ( & V_48 -> V_40 -> V_41 , L_3 ) ;
return;
}
F_33 ( & V_48 -> V_96 , V_72 ) ;
V_92 = V_48 -> V_97 . V_98 ;
if ( V_92 != NULL ) {
V_92 -> V_99 ++ ;
if ( V_92 -> V_99 > V_100 ) {
F_36 ( & V_48 -> V_96 ,
V_72 ) ;
F_40 ( & V_48 -> V_40 -> V_41 ,
L_4 ,
V_92 -> V_101 ,
V_92 -> V_72 ) ;
F_14 ( V_2 ) ;
F_6 ( V_2 ) ;
return;
}
}
F_36 ( & V_48 -> V_96 , V_72 ) ;
}
int F_41 ( struct V_1 * V_2 , int V_102 )
{
int V_34 = 0 ;
struct V_3 * V_10 = F_5 ( V_2 ) ;
if ( V_102 < 64 || V_102 > 9216 )
return - V_103 ;
F_15 ( V_2 ) ;
F_16 ( V_10 ) ;
F_17 ( V_10 ) ;
F_18 ( V_10 ) ;
F_42 ( V_10 ) ;
F_43 ( V_10 ) ;
V_2 -> V_104 = V_102 ;
F_44 ( V_10 ) ;
V_10 -> V_105 = V_102 + 14 ;
F_45 ( V_10 ) ;
V_34 = F_46 ( V_10 ) ;
if ( V_34 != 0 ) {
F_40 ( & V_10 -> V_40 -> V_41 ,
L_5 ) ;
return V_34 ;
}
F_47 ( V_10 ) ;
F_48 ( V_10 ) ;
memcpy ( V_2 -> V_106 , V_10 -> V_82 , V_83 ) ;
F_49 ( V_10 ) ;
if ( V_10 -> V_42 & V_43 )
F_12 ( V_10 ) ;
F_10 ( V_10 ) ;
F_11 ( V_10 ) ;
F_50 ( V_2 ) ;
return V_34 ;
}
int F_51 ( struct V_1 * V_2 , void * V_107 )
{
int V_34 = 0 ;
struct V_3 * V_10 = F_5 ( V_2 ) ;
struct V_108 * V_109 = V_107 ;
if ( V_10 == NULL )
return - V_110 ;
if ( ! F_52 ( V_109 -> V_111 ) )
return - V_103 ;
F_15 ( V_2 ) ;
F_16 ( V_10 ) ;
F_17 ( V_10 ) ;
F_18 ( V_10 ) ;
F_42 ( V_10 ) ;
F_43 ( V_10 ) ;
memcpy ( V_2 -> V_106 , V_109 -> V_111 , V_2 -> V_112 ) ;
F_3 ( V_113 L_6 ,
V_2 -> V_39 , V_2 -> V_106 ) ;
F_44 ( V_10 ) ;
F_45 ( V_10 ) ;
V_34 = F_46 ( V_10 ) ;
if ( V_34 != 0 ) {
F_9 ( & V_10 -> V_40 -> V_41 ,
L_7 ) ;
return V_34 ;
}
F_47 ( V_10 ) ;
F_48 ( V_10 ) ;
F_49 ( V_10 ) ;
if ( V_10 -> V_42 & V_43 )
F_12 ( V_10 ) ;
F_10 ( V_10 ) ;
F_11 ( V_10 ) ;
F_50 ( V_2 ) ;
return V_34 ;
}
