void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_5 += V_2 -> V_8 ;
F_3 ( & V_2 -> V_7 , V_6 ) ;
V_4 -> V_4 = F_4 ( V_5 ) ;
}
static struct V_9 * F_5 ( struct V_1 * V_2 ,
T_2 V_10 )
{
struct V_11 * V_12 = & V_2 -> V_13 ;
struct V_9 * V_14 ;
F_6 (list, skb) {
if ( F_7 ( V_14 ) -> V_15 . V_16 . V_10 == V_10 )
return V_14 ;
}
return NULL ;
}
void F_8 ( struct V_1 * V_2 , struct V_9 * V_14 )
{
struct V_11 * V_12 = & V_2 -> V_13 ;
struct V_9 * V_17 ;
unsigned long V_6 ;
V_17 = F_9 ( V_14 ) ;
if ( ! V_17 )
return;
F_7 ( V_17 ) -> V_18 = V_19 + V_20 ;
F_10 ( & V_12 -> V_21 , V_6 ) ;
V_14 = F_5 ( V_2 , F_7 ( V_17 ) -> V_15 . V_16 . V_10 ) ;
if ( ! V_14 ) {
F_11 ( V_17 ) -> V_22 |= V_23 ;
F_12 ( V_12 , V_17 ) ;
}
F_13 ( & V_12 -> V_21 , V_6 ) ;
if ( V_14 )
F_14 ( V_17 ) ;
}
void F_15 ( struct V_1 * V_2 , T_2 V_10 ,
T_1 V_5 )
{
struct V_3 V_24 ;
struct V_11 * V_12 = & V_2 -> V_13 ;
struct V_9 * V_14 ;
unsigned long V_6 ;
F_10 ( & V_12 -> V_21 , V_6 ) ;
V_14 = F_5 ( V_2 , V_10 ) ;
if ( V_14 )
F_16 ( V_14 , V_12 ) ;
F_13 ( & V_12 -> V_21 , V_6 ) ;
if ( ! V_14 )
return;
F_1 ( V_2 , & V_24 , V_5 ) ;
F_17 ( V_14 , & V_24 ) ;
F_18 ( V_14 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_13 ;
struct V_9 * V_14 , * V_25 ;
unsigned long V_6 ;
if ( F_20 ( V_26 , & V_2 -> V_27 ) ||
F_20 ( V_28 , & V_2 -> V_27 ) )
return;
F_10 ( & V_12 -> V_21 , V_6 ) ;
F_21 (list, skb, tmp) {
if ( ! F_22 ( F_7 ( V_14 ) -> V_18 ) )
continue;
F_16 ( V_14 , V_12 ) ;
F_23 ( V_14 ) ;
V_2 -> V_29 ++ ;
}
F_13 ( & V_12 -> V_21 , V_6 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
return V_31 -> V_32 . V_33 . V_34 ( V_31 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
T_3 V_35 = F_26 ( F_27 () ) ;
unsigned long V_6 ;
F_28 ( & V_2 -> V_7 , V_6 ) ;
V_2 -> V_8 = F_24 ( V_2 ) - V_35 ;
F_29 ( & V_2 -> V_7 , V_6 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_7 ) ;
F_32 ( & V_2 -> V_13 ) ;
F_25 ( V_2 ) ;
}
int F_33 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_34 ( V_37 ) ;
struct V_40 * V_41 = & V_2 -> V_42 ;
return F_35 ( V_39 -> V_43 , V_41 , sizeof( * V_41 ) ) ?
- V_44 : 0 ;
}
int F_36 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_34 ( V_37 ) ;
struct V_40 V_42 ;
if ( F_37 ( & V_42 , V_39 -> V_43 , sizeof( V_42 ) ) )
return - V_44 ;
if ( V_42 . V_6 )
return - V_45 ;
switch ( V_42 . V_46 ) {
case V_47 :
break;
case V_48 :
break;
default:
return - V_49 ;
}
switch ( V_42 . V_50 ) {
case V_51 :
V_2 -> V_6 &= ~ V_52 ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
V_2 -> V_6 |= V_52 ;
V_42 . V_50 = V_65 ;
break;
default:
return - V_49 ;
}
V_2 -> V_42 = V_42 ;
return F_35 ( V_39 -> V_43 , & V_42 , sizeof( V_42 ) ) ?
- V_44 : 0 ;
}
static int F_38 ( struct V_66 * V_67 , T_4 V_68 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 ;
int V_69 ;
V_2 = F_39 ( V_67 , struct V_1 , V_70 ) ;
V_31 = & V_2 -> V_31 ;
V_69 = V_31 -> V_32 . V_33 . V_71 ( V_31 , V_68 ) ;
return ( V_69 == V_72 ) ? - V_49 : V_69 ;
}
static int F_40 ( struct V_66 * V_67 , T_3 V_73 )
{
struct V_1 * V_2 ;
unsigned long V_6 ;
V_2 = F_39 ( V_67 , struct V_1 , V_70 ) ;
F_28 ( & V_2 -> V_7 , V_6 ) ;
V_2 -> V_8 += V_73 ;
F_29 ( & V_2 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_41 ( struct V_66 * V_67 , struct V_74 * V_75 )
{
struct V_1 * V_2 ;
unsigned long V_6 ;
T_1 V_76 ;
V_2 = F_39 ( V_67 , struct V_1 , V_70 ) ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_76 = F_24 ( V_2 ) + V_2 -> V_8 ;
F_3 ( & V_2 -> V_7 , V_6 ) ;
* V_75 = F_42 ( V_76 ) ;
return 0 ;
}
static int F_43 ( struct V_66 * V_67 ,
const struct V_74 * V_75 )
{
struct V_1 * V_2 ;
unsigned long V_6 ;
T_1 V_35 = F_44 ( V_75 ) ;
V_2 = F_39 ( V_67 , struct V_1 , V_70 ) ;
F_28 ( & V_2 -> V_7 , V_6 ) ;
V_2 -> V_8 = F_24 ( V_2 ) - V_35 ;
F_29 ( & V_2 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_45 ( struct V_66 * V_67 ,
struct V_77 * V_78 ,
int T_5 V_79 )
{
struct V_80 * V_81 = & V_78 -> V_82 . V_83 ;
struct V_1 * V_2 ;
struct V_30 * V_31 ;
T_1 V_83 ;
T_6 V_84 ;
if ( V_78 -> type != V_85 )
return - V_45 ;
if ( V_78 -> V_82 . V_86 >= V_67 -> V_87 )
return - V_45 ;
if ( V_81 -> V_88 > 4 || V_81 -> V_88 < 0 )
return - V_49 ;
V_2 = F_39 ( V_67 , struct V_1 , V_70 ) ;
V_31 = & V_2 -> V_31 ;
if ( ! V_31 -> V_89 )
return - V_90 ;
V_83 = V_81 -> V_88 * 1000000000LL + V_81 -> V_91 ;
V_84 = 2 * ( F_46 ( V_31 , V_92 ) &
V_93 ) ;
if ( ( V_83 && ( V_83 < V_84 ) ) || ( V_83 > V_94 ) )
return - V_49 ;
F_47 ( V_31 , F_48 ( V_78 -> V_82 . V_86 ) ,
( T_6 ) V_83 ) ;
return 0 ;
}
static int F_49 ( struct V_66 * V_67 , unsigned int V_95 ,
enum V_96 V_97 , unsigned int V_98 )
{
if ( V_95 >= V_67 -> V_99 || ! V_67 -> V_100 )
return - V_45 ;
if ( V_98 != V_67 -> V_100 [ V_95 ] . V_98 )
return - V_45 ;
if ( V_97 != V_67 -> V_100 [ V_95 ] . V_97 )
return - V_45 ;
return 0 ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_66 * V_70 = & V_2 -> V_70 ;
struct V_101 * V_102 = & V_2 -> V_103 -> V_102 ;
struct V_104 * V_104 ;
snprintf ( V_70 -> V_105 , sizeof( V_70 -> V_105 ) ,
L_1 , V_2 -> V_37 -> V_105 ) ;
V_70 -> V_106 = V_107 ;
V_70 -> V_108 = 976562 ;
V_70 -> V_109 = F_38 ;
V_70 -> V_110 = F_40 ;
V_70 -> V_111 = F_41 ;
V_70 -> V_112 = F_43 ;
if ( V_2 -> V_89 ) {
V_70 -> V_87 = 2 ;
V_70 -> V_113 = F_45 ;
V_70 -> V_114 = F_49 ;
V_70 -> V_99 = 2 ;
V_70 -> V_100 = V_115 ;
}
V_104 = F_51 ( V_70 , V_102 ) ;
if ( F_52 ( V_104 ) ) {
V_104 = NULL ;
F_53 ( V_102 , L_2 ) ;
} else {
F_54 ( V_102 , L_3 , V_70 -> V_105 ) ;
}
V_2 -> V_104 = V_104 ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_104 * V_104 = V_2 -> V_104 ;
struct V_101 * V_102 = & V_2 -> V_103 -> V_102 ;
if ( ! V_104 )
return;
V_2 -> V_104 = NULL ;
F_56 ( V_104 ) ;
F_54 ( V_102 , L_4 , V_2 -> V_70 . V_105 ) ;
}
