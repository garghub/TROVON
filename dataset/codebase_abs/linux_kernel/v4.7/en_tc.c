static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 * V_4 , T_1 * V_5 ,
T_1 V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 ;
struct V_11 V_12 = { 0 } ;
struct V_13 * V_14 = NULL ;
struct V_1 * V_15 ;
bool V_16 = false ;
if ( V_6 & V_17 ) {
V_12 . type = V_18 ;
V_12 . V_19 = V_3 -> V_20 . V_21 . V_19 . V_22 ;
} else {
V_14 = F_2 ( V_9 , true ) ;
if ( F_3 ( V_14 ) )
return F_4 ( V_14 ) ;
V_12 . type = V_23 ;
V_12 . V_14 = V_14 ;
}
if ( F_5 ( V_3 -> V_20 . V_24 . V_22 ) ) {
V_3 -> V_20 . V_24 . V_22 =
F_6 ( V_3 -> V_20 . V_25 ,
V_26 ,
V_27 ,
V_28 ,
0 ) ;
if ( F_3 ( V_3 -> V_20 . V_24 . V_22 ) ) {
F_7 ( V_3 -> V_29 ,
L_1 ) ;
V_15 = F_4 ( V_3 -> V_20 . V_24 . V_22 ) ;
goto V_30;
}
V_16 = true ;
}
V_15 = F_8 ( V_3 -> V_20 . V_24 . V_22 , V_31 ,
V_4 , V_5 ,
V_6 , V_7 ,
& V_12 ) ;
if ( F_3 ( V_15 ) )
goto V_32;
return V_15 ;
V_32:
if ( V_16 ) {
F_9 ( V_3 -> V_20 . V_24 . V_22 ) ;
V_3 -> V_20 . V_24 . V_22 = NULL ;
}
V_30:
F_10 ( V_9 , V_14 ) ;
return V_15 ;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_1 * V_15 )
{
struct V_13 * V_14 = NULL ;
V_14 = F_12 ( V_15 ) ;
F_13 ( V_15 ) ;
F_10 ( V_3 -> V_10 , V_14 ) ;
if ( ! F_14 ( V_3 ) ) {
F_9 ( V_3 -> V_20 . V_24 . V_22 ) ;
V_3 -> V_20 . V_24 . V_22 = NULL ;
}
}
static int F_15 ( struct V_2 * V_3 ,
T_1 * V_4 , T_1 * V_5 ,
struct V_33 * V_34 )
{
void * V_35 = F_16 ( V_36 , V_4 , V_37 ) ;
void * V_38 = F_16 ( V_36 , V_5 , V_37 ) ;
T_2 V_39 = 0 ;
T_3 V_40 = 0 ;
if ( V_34 -> V_41 -> V_42 &
~ ( F_17 ( V_43 ) |
F_17 ( V_44 ) |
F_17 ( V_45 ) |
F_17 ( V_46 ) |
F_17 ( V_47 ) |
F_17 ( V_48 ) ) ) {
F_18 ( V_3 -> V_29 , L_2 ,
V_34 -> V_41 -> V_42 ) ;
return - V_49 ;
}
if ( F_19 ( V_34 -> V_41 , V_43 ) ) {
struct V_50 * V_51 =
F_20 ( V_34 -> V_41 ,
V_44 ,
V_34 -> V_51 ) ;
V_39 = V_51 -> V_39 ;
}
if ( F_19 ( V_34 -> V_41 , V_44 ) ) {
struct V_52 * V_51 =
F_20 ( V_34 -> V_41 ,
V_44 ,
V_34 -> V_51 ) ;
struct V_52 * V_53 =
F_20 ( V_34 -> V_41 ,
V_44 ,
V_34 -> V_53 ) ;
V_40 = V_51 -> V_40 ;
F_21 ( V_54 , V_35 , V_55 ,
F_22 ( V_53 -> V_56 ) ) ;
F_21 ( V_54 , V_38 , V_55 ,
F_22 ( V_51 -> V_56 ) ) ;
F_21 ( V_54 , V_35 , V_57 ,
V_53 -> V_40 ) ;
F_21 ( V_54 , V_38 , V_57 ,
V_51 -> V_40 ) ;
}
if ( F_19 ( V_34 -> V_41 , V_45 ) ) {
struct V_58 * V_51 =
F_20 ( V_34 -> V_41 ,
V_45 ,
V_34 -> V_51 ) ;
struct V_58 * V_53 =
F_20 ( V_34 -> V_41 ,
V_45 ,
V_34 -> V_53 ) ;
F_23 ( F_16 ( V_54 , V_35 ,
V_59 ) ,
V_53 -> V_60 ) ;
F_23 ( F_16 ( V_54 , V_38 ,
V_59 ) ,
V_51 -> V_60 ) ;
F_23 ( F_16 ( V_54 , V_35 ,
V_61 ) ,
V_53 -> V_62 ) ;
F_23 ( F_16 ( V_54 , V_38 ,
V_61 ) ,
V_51 -> V_62 ) ;
}
if ( V_39 == V_46 ) {
struct V_63 * V_51 =
F_20 ( V_34 -> V_41 ,
V_46 ,
V_34 -> V_51 ) ;
struct V_63 * V_53 =
F_20 ( V_34 -> V_41 ,
V_46 ,
V_34 -> V_53 ) ;
memcpy ( F_16 ( V_54 , V_35 ,
V_64 . V_65 . V_66 ) ,
& V_53 -> V_62 , sizeof( V_53 -> V_62 ) ) ;
memcpy ( F_16 ( V_54 , V_38 ,
V_64 . V_65 . V_66 ) ,
& V_51 -> V_62 , sizeof( V_51 -> V_62 ) ) ;
memcpy ( F_16 ( V_54 , V_35 ,
V_67 . V_65 . V_66 ) ,
& V_53 -> V_60 , sizeof( V_53 -> V_60 ) ) ;
memcpy ( F_16 ( V_54 , V_38 ,
V_67 . V_65 . V_66 ) ,
& V_51 -> V_60 , sizeof( V_51 -> V_60 ) ) ;
}
if ( V_39 == V_47 ) {
struct V_68 * V_51 =
F_20 ( V_34 -> V_41 ,
V_47 ,
V_34 -> V_51 ) ;
struct V_68 * V_53 =
F_20 ( V_34 -> V_41 ,
V_47 ,
V_34 -> V_53 ) ;
memcpy ( F_16 ( V_54 , V_35 ,
V_64 . V_69 . V_70 ) ,
& V_53 -> V_62 , sizeof( V_53 -> V_62 ) ) ;
memcpy ( F_16 ( V_54 , V_38 ,
V_64 . V_69 . V_70 ) ,
& V_51 -> V_62 , sizeof( V_51 -> V_62 ) ) ;
memcpy ( F_16 ( V_54 , V_35 ,
V_67 . V_69 . V_70 ) ,
& V_53 -> V_60 , sizeof( V_53 -> V_60 ) ) ;
memcpy ( F_16 ( V_54 , V_38 ,
V_67 . V_69 . V_70 ) ,
& V_51 -> V_60 , sizeof( V_51 -> V_60 ) ) ;
}
if ( F_19 ( V_34 -> V_41 , V_48 ) ) {
struct V_71 * V_51 =
F_20 ( V_34 -> V_41 ,
V_48 ,
V_34 -> V_51 ) ;
struct V_71 * V_53 =
F_20 ( V_34 -> V_41 ,
V_48 ,
V_34 -> V_53 ) ;
switch ( V_40 ) {
case V_72 :
F_21 ( V_54 , V_35 ,
V_73 , F_22 ( V_53 -> V_62 ) ) ;
F_21 ( V_54 , V_38 ,
V_73 , F_22 ( V_51 -> V_62 ) ) ;
F_21 ( V_54 , V_35 ,
V_74 , F_22 ( V_53 -> V_60 ) ) ;
F_21 ( V_54 , V_38 ,
V_74 , F_22 ( V_51 -> V_60 ) ) ;
break;
case V_75 :
F_21 ( V_54 , V_35 ,
V_76 , F_22 ( V_53 -> V_62 ) ) ;
F_21 ( V_54 , V_38 ,
V_76 , F_22 ( V_51 -> V_62 ) ) ;
F_21 ( V_54 , V_35 ,
V_77 , F_22 ( V_53 -> V_60 ) ) ;
F_21 ( V_54 , V_38 ,
V_77 , F_22 ( V_51 -> V_60 ) ) ;
break;
default:
F_7 ( V_3 -> V_29 ,
L_3 ) ;
return - V_78 ;
}
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_79 * V_80 ,
T_1 * V_6 , T_1 * V_7 )
{
const struct V_81 * V_82 ;
if ( F_25 ( V_80 ) )
return - V_78 ;
* V_7 = V_83 ;
* V_6 = 0 ;
F_26 (a, exts) {
if ( * V_6 )
return - V_78 ;
if ( F_27 ( V_82 ) ) {
* V_6 |= V_84 ;
if ( F_28 ( V_3 -> V_10 ,
V_85 . V_86 ) )
* V_6 |= V_87 ;
continue;
}
if ( F_29 ( V_82 ) ) {
T_1 V_88 = F_30 ( V_82 ) ;
if ( V_88 & ~ V_89 ) {
F_18 ( V_3 -> V_29 , L_4 ,
V_88 ) ;
return - V_78 ;
}
* V_7 = V_88 ;
* V_6 |= V_17 ;
continue;
}
return - V_78 ;
}
return 0 ;
}
int F_31 ( struct V_2 * V_3 , T_4 V_90 ,
struct V_33 * V_34 )
{
struct V_91 * V_24 = & V_3 -> V_20 . V_24 ;
T_1 * V_4 ;
T_1 * V_5 ;
int V_92 = 0 ;
T_1 V_7 ;
T_1 V_6 ;
struct V_93 * V_94 ;
struct V_1 * V_95 = NULL ;
V_94 = F_32 ( & V_24 -> V_96 , & V_34 -> V_97 ,
V_24 -> V_98 ) ;
if ( V_94 )
V_95 = V_94 -> V_15 ;
else
V_94 = F_33 ( sizeof( * V_94 ) , V_99 ) ;
V_4 = F_33 ( F_34 ( V_36 ) , V_99 ) ;
V_5 = F_33 ( F_34 ( V_36 ) , V_99 ) ;
if ( ! V_4 || ! V_5 || ! V_94 ) {
V_92 = - V_100 ;
goto V_101;
}
V_94 -> V_97 = V_34 -> V_97 ;
V_92 = F_15 ( V_3 , V_4 , V_5 , V_34 ) ;
if ( V_92 < 0 )
goto V_101;
V_92 = F_24 ( V_3 , V_34 -> V_80 , & V_6 , & V_7 ) ;
if ( V_92 < 0 )
goto V_101;
V_92 = F_35 ( & V_24 -> V_96 , & V_94 -> V_102 ,
V_24 -> V_98 ) ;
if ( V_92 )
goto V_101;
V_94 -> V_15 = F_1 ( V_3 , V_4 , V_5 , V_6 ,
V_7 ) ;
if ( F_3 ( V_94 -> V_15 ) ) {
V_92 = F_36 ( V_94 -> V_15 ) ;
goto V_103;
}
if ( V_95 )
F_11 ( V_3 , V_95 ) ;
goto V_104;
V_103:
F_37 ( & V_24 -> V_96 , & V_94 -> V_102 , V_24 -> V_98 ) ;
V_101:
if ( ! V_95 )
F_38 ( V_94 ) ;
V_104:
F_38 ( V_4 ) ;
F_38 ( V_5 ) ;
return V_92 ;
}
int F_39 ( struct V_2 * V_3 ,
struct V_33 * V_34 )
{
struct V_93 * V_94 ;
struct V_91 * V_24 = & V_3 -> V_20 . V_24 ;
V_94 = F_32 ( & V_24 -> V_96 , & V_34 -> V_97 ,
V_24 -> V_98 ) ;
if ( ! V_94 )
return - V_78 ;
F_37 ( & V_24 -> V_96 , & V_94 -> V_102 , V_24 -> V_98 ) ;
F_11 ( V_3 , V_94 -> V_15 ) ;
F_38 ( V_94 ) ;
return 0 ;
}
int F_40 ( struct V_2 * V_3 ,
struct V_33 * V_34 )
{
struct V_91 * V_24 = & V_3 -> V_20 . V_24 ;
struct V_93 * V_94 ;
struct V_81 * V_82 ;
struct V_13 * V_14 ;
T_5 V_105 ;
T_5 V_106 ;
T_5 V_107 ;
V_94 = F_32 ( & V_24 -> V_96 , & V_34 -> V_97 ,
V_24 -> V_98 ) ;
if ( ! V_94 )
return - V_78 ;
V_14 = F_12 ( V_94 -> V_15 ) ;
if ( ! V_14 )
return 0 ;
F_41 ( V_14 , & V_105 , & V_106 , & V_107 ) ;
F_26 (a, f->exts)
F_42 ( V_82 , V_105 , V_106 , V_107 ) ;
return 0 ;
}
int F_43 ( struct V_2 * V_3 )
{
struct V_91 * V_24 = & V_3 -> V_20 . V_24 ;
V_24 -> V_98 = V_108 ;
return F_44 ( & V_24 -> V_96 , & V_24 -> V_98 ) ;
}
static void F_45 ( void * V_109 , void * V_110 )
{
struct V_93 * V_94 = V_109 ;
struct V_2 * V_3 = V_110 ;
F_11 ( V_3 , V_94 -> V_15 ) ;
F_38 ( V_94 ) ;
}
void F_46 ( struct V_2 * V_3 )
{
struct V_91 * V_24 = & V_3 -> V_20 . V_24 ;
F_47 ( & V_24 -> V_96 , F_45 , V_3 ) ;
if ( ! F_5 ( V_24 -> V_22 ) ) {
F_9 ( V_24 -> V_22 ) ;
V_24 -> V_22 = NULL ;
}
}
