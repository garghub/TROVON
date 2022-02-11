static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = & V_5 -> V_7 ;
struct V_8 * V_9 = & V_5 -> V_6 ;
V_6 -> V_10 = V_9 -> V_11 + V_9 -> V_12 +
V_9 -> V_13 + V_9 -> V_14 + V_9 -> V_15 ;
V_6 -> V_16 = V_9 -> V_17 ;
V_6 -> V_18 = V_9 -> V_19 ;
V_6 -> V_20 = V_9 -> V_20 ;
V_6 -> V_21 = V_9 -> V_11 ;
V_6 -> V_22 = V_9 -> V_23 ;
V_6 -> V_24 = V_9 -> V_13 ;
return V_6 ;
}
int F_3 ( struct V_2 * V_3 )
{
int V_25 = 0 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_4 ( & V_5 -> V_26 ) ;
V_25 = F_5 ( V_3 -> V_27 , V_28 , V_29 ,
V_3 -> V_30 , V_3 ) ;
if ( V_25 ) {
F_6 ( & V_5 -> V_31 -> V_32 , L_1 ,
V_3 -> V_27 ) ;
return V_25 ;
}
F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
F_9 ( V_5 ) ;
V_5 -> V_33 |= V_34 ;
F_10 ( V_3 ) ;
return V_25 ;
}
int F_11 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_12 ( V_3 ) ;
F_13 ( V_5 ) ;
F_14 ( V_5 ) ;
F_15 ( V_5 ) ;
V_5 -> V_33 &= ~ V_34 ;
F_16 ( V_3 -> V_27 , V_3 ) ;
F_17 ( & V_5 -> V_26 ) ;
return 0 ;
}
int F_18 ( struct V_2 * V_3 , struct V_35 * V_36 , int V_37 )
{
int V_38 = 0 ;
struct V_4 * V_39 = F_2 ( V_3 ) ;
struct V_40 * V_41 = F_19 ( V_36 ) ;
switch ( V_37 ) {
case V_42 :
V_41 -> V_43 = V_39 -> V_6 . V_44 ;
break;
case V_45 :
if ( ! F_20 ( V_46 ) )
V_38 = - V_47 ;
else
V_38 = F_21 ( V_39 ,
V_41 -> V_48 , & V_41 -> V_49 ) ;
break;
case V_50 :
if ( ! F_20 ( V_46 ) )
V_38 = - V_47 ;
else
V_38 = F_22 ( V_39 , V_41 -> V_48 ,
V_41 -> V_51 ) ;
break;
default:
V_38 = - V_52 ;
}
return V_38 ;
}
int F_23 ( struct V_2 * V_3 , struct V_35 * V_36 , int V_37 )
{
int V_38 = 0 ;
switch ( V_37 ) {
case V_42 :
case V_45 :
case V_50 :
V_38 = F_18 ( V_3 , V_36 , V_37 ) ;
break;
default:
V_38 = - V_52 ;
}
return V_38 ;
}
int F_24 ( struct V_4 * V_5 )
{
int V_38 = 0 ;
T_1 V_53 = V_5 -> V_54 ;
T_2 V_55 ;
T_2 V_56 ;
V_55 = F_25 ( & V_5 -> V_57 -> V_58 . V_55 ) ;
V_56 = F_25 ( & V_5 -> V_57 -> V_58 . V_56 ) ;
V_55 |= 0x04 ;
if ( ( V_53 & V_59 ) || V_53 == 0 )
V_56 &= ~ 7 ;
else {
if ( V_53 & V_60 )
V_56 &= ~ 2 ;
else {
F_26 ( V_5 ) ;
V_56 |= 2 ;
V_55 &= ~ 0x04 ;
}
if ( V_53 & V_61 ) {
F_27 ( V_5 ) ;
V_56 |= 4 ;
V_55 &= ~ 0x04 ;
}
if ( V_53 & V_62 ) {
V_56 |= 1 ;
V_55 &= ~ 0x04 ;
} else
V_56 &= ~ 1 ;
F_28 ( V_56 , & V_5 -> V_57 -> V_58 . V_56 ) ;
F_28 ( V_55 , & V_5 -> V_57 -> V_58 . V_55 ) ;
}
return V_38 ;
}
void F_29 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 V_54 = 0 ;
unsigned long V_33 ;
struct V_63 * V_64 ;
int V_65 ;
F_30 ( & V_5 -> V_66 , V_33 ) ;
V_54 = V_5 -> V_54 ;
V_54 &= ~ V_67 ;
if ( V_3 -> V_33 & V_68 )
V_5 -> V_54 |= V_59 ;
else
V_5 -> V_54 &= ~ V_59 ;
if ( V_3 -> V_33 & V_69 )
V_5 -> V_54 |= V_60 ;
if ( F_31 ( V_3 ) > V_70 )
V_5 -> V_54 |= V_60 ;
if ( F_31 ( V_3 ) < 1 ) {
V_5 -> V_54 &= ~ V_60 ;
V_5 -> V_54 &= ~ V_67 ;
} else
V_5 -> V_54 |= V_67 ;
V_65 = 0 ;
F_32 (ha, netdev) {
if ( V_65 == V_70 )
break;
memcpy ( V_5 -> V_71 [ V_65 ++ ] , V_64 -> V_72 , V_73 ) ;
}
V_5 -> V_74 = V_65 ;
if ( V_54 != V_5 -> V_54 ) {
F_24 ( V_5 ) ;
}
F_33 ( & V_5 -> V_66 , V_33 ) ;
}
int F_34 ( struct V_75 * V_76 , struct V_2 * V_3 )
{
int V_38 = 0 ;
V_3 -> V_77 = V_78 ;
V_38 = F_35 ( V_76 , V_3 ) ;
if ( V_38 != 0 ) {
if ( V_38 == - V_79 ) {
F_12 ( V_3 ) ;
V_38 = V_80 ;
} else {
V_38 = V_81 ;
}
}
return V_38 ;
}
void F_36 ( struct V_2 * V_3 )
{
struct V_4 * V_39 = F_2 ( V_3 ) ;
struct V_82 * V_82 ;
unsigned long V_33 ;
if ( V_39 -> V_33 & V_83 )
return;
if ( V_39 -> V_33 & V_84 ) {
F_6 ( & V_39 -> V_31 -> V_32 , L_2 ) ;
return;
}
F_30 ( & V_39 -> V_85 , V_33 ) ;
V_82 = V_39 -> V_86 . V_87 ;
if ( V_82 != NULL ) {
V_82 -> V_88 ++ ;
if ( V_82 -> V_88 > V_89 ) {
F_33 ( & V_39 -> V_85 ,
V_33 ) ;
F_37 ( & V_39 -> V_31 -> V_32 ,
L_3 ,
V_82 -> V_90 ,
V_82 -> V_33 ) ;
F_11 ( V_3 ) ;
F_3 ( V_3 ) ;
return;
}
}
F_33 ( & V_39 -> V_85 , V_33 ) ;
}
int F_38 ( struct V_2 * V_3 , int V_91 )
{
int V_25 = 0 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_91 < 64 || V_91 > 9216 )
return - V_92 ;
F_12 ( V_3 ) ;
F_13 ( V_5 ) ;
F_14 ( V_5 ) ;
F_15 ( V_5 ) ;
F_39 ( V_5 ) ;
F_40 ( V_5 ) ;
V_3 -> V_93 = V_91 ;
F_41 ( V_5 ) ;
V_5 -> V_94 = V_91 + 14 ;
F_42 ( V_5 ) ;
V_25 = F_43 ( V_5 ) ;
if ( V_25 != 0 ) {
F_37 ( & V_5 -> V_31 -> V_32 ,
L_4 ) ;
return V_25 ;
}
F_44 ( V_5 ) ;
F_45 ( V_5 ) ;
memcpy ( V_3 -> V_95 , V_5 -> V_72 , V_73 ) ;
F_46 ( V_5 ) ;
if ( V_5 -> V_33 & V_34 )
F_9 ( V_5 ) ;
F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
F_47 ( V_3 ) ;
return V_25 ;
}
int F_48 ( struct V_2 * V_3 , void * V_96 )
{
int V_25 = 0 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_97 * V_98 = V_96 ;
if ( V_5 == NULL )
return - V_99 ;
if ( ! F_49 ( V_98 -> V_100 ) )
return - V_92 ;
F_12 ( V_3 ) ;
F_13 ( V_5 ) ;
F_14 ( V_5 ) ;
F_15 ( V_5 ) ;
F_39 ( V_5 ) ;
F_40 ( V_5 ) ;
memcpy ( V_3 -> V_95 , V_98 -> V_100 , V_3 -> V_101 ) ;
F_50 ( V_102 L_5 ,
V_3 -> V_30 , V_3 -> V_95 ) ;
F_41 ( V_5 ) ;
F_42 ( V_5 ) ;
V_25 = F_43 ( V_5 ) ;
if ( V_25 != 0 ) {
F_6 ( & V_5 -> V_31 -> V_32 ,
L_6 ) ;
return V_25 ;
}
F_44 ( V_5 ) ;
F_45 ( V_5 ) ;
F_46 ( V_5 ) ;
if ( V_5 -> V_33 & V_34 )
F_9 ( V_5 ) ;
F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
F_47 ( V_3 ) ;
return V_25 ;
}
struct V_2 * F_51 ( void )
{
struct V_2 * V_3 ;
V_3 = F_52 ( sizeof( struct V_4 ) ) ;
if ( V_3 == NULL ) {
F_50 ( V_103 L_7 ) ;
return NULL ;
}
V_3 -> V_104 = V_105 ;
V_3 -> V_106 = & V_107 ;
return V_3 ;
}
