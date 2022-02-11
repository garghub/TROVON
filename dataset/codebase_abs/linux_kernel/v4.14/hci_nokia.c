static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
if ( V_3 ) {
F_2 ( V_2 , true ) ;
F_3 ( V_2 , true ) ;
} else {
F_3 ( V_2 , false ) ;
F_2 ( V_2 , false ) ;
}
}
static T_1 F_4 ( int V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
struct V_8 * V_9 = & V_7 -> V_2 -> V_9 ;
int V_10 = F_5 ( V_7 -> V_11 ) ;
if ( V_7 -> V_12 == V_10 )
return V_13 ;
if ( V_10 )
F_6 ( V_9 ) ;
else
F_7 ( V_9 ) ;
V_7 -> V_12 = V_10 ;
return V_13 ;
}
static int F_8 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_16 ;
struct V_8 * V_9 = & V_7 -> V_2 -> V_9 ;
int V_17 ;
F_9 ( V_7 -> V_18 , 1 ) ;
F_9 ( V_7 -> V_19 , 1 ) ;
F_10 ( 100 ) ;
V_17 = F_11 ( V_7 -> V_11 ) ;
if ( V_17 == 1 ) {
F_12 ( V_9 , L_1 ) ;
return - V_20 ;
}
F_13 ( V_7 -> V_2 ) ;
F_1 ( V_7 -> V_2 , false ) ;
F_14 ( V_7 -> V_2 , V_21 ) ;
F_9 ( V_7 -> V_18 , 0 ) ;
V_17 = F_15 ( V_7 -> V_2 , true , 200 ) ;
if ( V_17 < 0 ) {
F_12 ( V_9 , L_2 , V_17 ) ;
return V_17 ;
}
F_1 ( V_7 -> V_2 , true ) ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_16 ;
struct V_8 * V_9 = & V_7 -> V_2 -> V_9 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 ;
F_17 ( & V_7 -> F_17 ) ;
V_28 = V_29 + sizeof( * V_23 ) + sizeof( * V_25 ) ;
V_27 = F_18 ( V_28 , V_30 ) ;
if ( ! V_27 )
return - V_31 ;
F_19 ( V_27 ) = V_32 ;
memset ( V_27 -> V_5 , 0x00 , V_28 ) ;
V_23 = F_20 ( V_27 , sizeof( * V_23 ) ) ;
V_23 -> V_33 = sizeof( * V_25 ) ;
V_25 = F_20 ( V_27 , sizeof( * V_25 ) ) ;
V_25 -> V_34 = V_35 ;
F_21 ( V_15 , V_27 ) ;
F_22 ( V_15 ) ;
F_23 ( V_9 , L_3 ) ;
if ( ! F_24 ( & V_7 -> F_17 ,
F_25 ( 1000 ) ) ) {
return - V_36 ;
}
if ( V_7 -> V_37 < 0 )
return V_7 -> V_37 ;
return 0 ;
}
static int F_26 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_16 ;
struct V_8 * V_9 = & V_7 -> V_2 -> V_9 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_26 * V_27 ;
int V_28 , V_17 ;
T_2 V_42 = F_27 ( V_7 -> V_43 * 10 , V_44 ) ;
int V_45 = V_7 -> V_43 / 1000 ;
V_28 = V_29 + sizeof( * V_41 ) + sizeof( * V_39 ) ;
V_27 = F_18 ( V_28 , V_30 ) ;
if ( ! V_27 )
return - V_31 ;
F_19 ( V_27 ) = V_46 ;
V_41 = F_20 ( V_27 , sizeof( * V_41 ) ) ;
V_41 -> V_33 = sizeof( * V_39 ) ;
V_39 = F_20 ( V_27 , sizeof( * V_39 ) ) ;
V_39 -> V_47 = V_48 ;
V_39 -> V_42 = F_28 ( V_42 ) ;
V_39 -> V_49 = 0x0000 ;
V_39 -> V_50 = V_51 ;
V_39 -> V_52 = F_28 ( V_45 ) ;
V_39 -> V_53 = 0x0000 ;
V_7 -> V_37 = 0 ;
F_17 ( & V_7 -> F_17 ) ;
F_21 ( V_15 , V_27 ) ;
F_22 ( V_15 ) ;
F_23 ( V_9 , L_4 ) ;
if ( ! F_24 ( & V_7 -> F_17 ,
F_25 ( 10000 ) ) ) {
return - V_36 ;
}
if ( V_7 -> V_37 < 0 )
return V_7 -> V_37 ;
F_1 ( V_7 -> V_2 , false ) ;
F_14 ( V_7 -> V_2 , V_44 ) ;
V_17 = F_15 ( V_7 -> V_2 , true , 200 ) ;
if ( V_17 < 0 ) {
F_12 ( V_9 , L_2 , V_17 ) ;
return V_17 ;
}
F_1 ( V_7 -> V_2 , true ) ;
F_23 ( V_9 , L_5 ) ;
return 0 ;
}
static int F_29 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_16 ;
struct V_8 * V_9 = & V_7 -> V_2 -> V_9 ;
const char * V_54 ;
const struct V_55 * V_56 ;
const T_3 * V_57 ;
T_4 V_58 ;
int V_17 ;
F_23 ( V_9 , L_6 ) ;
if ( V_7 -> V_59 == V_60 ) {
V_54 = V_61 ;
} else if ( V_7 -> V_59 == V_62 ) {
V_54 = V_63 ;
} else {
F_12 ( V_9 , L_7 ) ;
return - V_64 ;
}
V_17 = F_30 ( & V_56 , V_54 , V_9 ) ;
if ( V_17 < 0 ) {
F_12 ( V_9 , L_8 ,
V_15 -> V_65 -> V_66 , V_17 ) ;
return V_17 ;
}
V_57 = V_56 -> V_5 ;
V_58 = V_56 -> V_67 ;
while ( V_58 >= 4 ) {
T_2 V_68 = F_31 ( V_57 ) ;
T_3 V_69 = V_57 [ 2 ] ;
const struct V_70 * V_71 ;
T_2 V_72 ;
struct V_26 * V_27 ;
switch ( V_69 ) {
case V_73 :
V_71 = (struct V_70 * ) ( V_57 + 3 ) ;
V_72 = F_32 ( V_71 -> V_72 ) ;
V_27 = F_33 ( V_15 -> V_65 , V_72 , V_71 -> V_74 ,
V_57 + 3 + V_75 ,
V_76 ) ;
if ( F_34 ( V_27 ) ) {
V_17 = F_35 ( V_27 ) ;
F_12 ( V_9 , L_9 ,
V_15 -> V_65 -> V_66 , V_72 , V_17 ) ;
goto V_77;
}
F_36 ( V_27 ) ;
break;
case V_78 :
case V_46 :
case V_32 :
break;
}
V_57 += V_68 + 2 ;
V_58 -= V_68 + 2 ;
}
V_77:
F_37 ( V_56 ) ;
return V_17 ;
}
static int F_38 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_16 ;
struct V_8 * V_9 = & V_7 -> V_2 -> V_9 ;
int V_17 ;
V_7 -> V_79 = false ;
F_1 ( V_7 -> V_2 , false ) ;
F_39 ( V_9 ) ;
if ( V_7 -> V_80 ) {
F_9 ( V_7 -> V_19 , 0 ) ;
F_7 ( & V_7 -> V_2 -> V_9 ) ;
V_7 -> V_80 = false ;
}
F_23 ( V_9 , L_10 ) ;
V_17 = F_8 ( V_15 ) ;
if ( V_17 < 0 ) {
F_12 ( V_9 , L_11 , V_17 ) ;
goto V_81;
}
V_17 = F_26 ( V_15 ) ;
if ( V_17 < 0 ) {
F_12 ( V_9 , L_12 , V_17 ) ;
goto V_81;
}
V_17 = F_16 ( V_15 ) ;
if ( V_17 < 0 ) {
F_12 ( V_9 , L_13 , V_17 ) ;
goto V_81;
}
V_17 = F_29 ( V_15 ) ;
if ( V_17 < 0 ) {
F_12 ( V_9 , L_14 , V_17 ) ;
goto V_81;
}
F_1 ( V_7 -> V_2 , false ) ;
F_14 ( V_7 -> V_2 , V_82 ) ;
F_1 ( V_7 -> V_2 , true ) ;
if ( V_7 -> V_59 == V_60 ) {
V_15 -> V_65 -> V_83 = V_84 ;
F_40 ( V_85 , & V_15 -> V_65 -> V_86 ) ;
F_23 ( V_9 , L_15 ) ;
}
F_23 ( V_9 , L_16 ) ;
F_9 ( V_7 -> V_19 , 0 ) ;
F_7 ( V_9 ) ;
V_7 -> V_80 = false ;
V_7 -> V_79 = true ;
return 0 ;
V_81:
F_7 ( V_9 ) ;
return V_17 ;
}
static int F_41 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = & V_15 -> V_2 -> V_9 ;
F_23 ( V_9 , L_17 ) ;
F_42 ( V_15 -> V_2 ) ;
F_43 ( V_9 ) ;
return 0 ;
}
static int F_44 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_16 ;
F_23 ( & V_7 -> V_2 -> V_9 , L_18 ) ;
F_45 ( & V_7 -> V_87 ) ;
return 0 ;
}
static int F_46 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_16 ;
struct V_8 * V_9 = & V_7 -> V_2 -> V_9 ;
F_23 ( V_9 , L_19 ) ;
V_7 -> V_79 = false ;
F_45 ( & V_7 -> V_87 ) ;
F_36 ( V_7 -> V_88 ) ;
F_47 ( V_7 -> V_18 , 1 ) ;
F_47 ( V_7 -> V_19 , 0 ) ;
F_48 ( & V_7 -> V_2 -> V_9 ) ;
F_49 ( V_7 -> V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_14 * V_15 , struct V_26 * V_27 )
{
struct V_6 * V_7 = V_15 -> V_16 ;
int V_17 ;
memcpy ( F_50 ( V_27 , 1 ) , & F_51 ( V_27 ) -> V_69 , 1 ) ;
if ( V_27 -> V_28 % 2 ) {
V_17 = F_52 ( V_27 , 1 ) ;
if ( V_17 )
return V_17 ;
F_53 ( V_27 , 0x00 ) ;
}
F_54 ( & V_7 -> V_87 , V_27 ) ;
return 0 ;
}
static int F_55 ( struct V_89 * V_65 ,
struct V_26 * V_27 )
{
struct V_14 * V_15 = F_56 ( V_65 ) ;
struct V_6 * V_7 = V_15 -> V_16 ;
struct V_8 * V_9 = & V_7 -> V_2 -> V_9 ;
struct V_40 * V_23 ;
struct V_90 * V_91 ;
int V_92 = 0 ;
V_23 = (struct V_40 * ) V_27 -> V_5 ;
if ( V_23 -> V_33 != sizeof( * V_91 ) ) {
V_7 -> V_37 = - V_93 ;
V_92 = - V_93 ;
goto V_94;
}
V_91 = F_57 ( V_27 , sizeof( * V_23 ) ) ;
if ( V_91 -> V_47 != V_95 ) {
F_12 ( V_9 , L_20 ) ;
V_7 -> V_37 = - V_96 ;
V_92 = - V_96 ;
goto V_94;
}
V_7 -> V_59 = V_91 -> V_59 ;
V_7 -> V_97 = V_91 -> V_97 ;
F_23 ( V_9 , L_21 ,
V_91 -> V_42 , V_91 -> V_52 , V_91 -> V_59 , V_91 -> V_97 ) ;
V_94:
F_58 ( & V_7 -> F_17 ) ;
F_36 ( V_27 ) ;
return V_92 ;
}
static int F_59 ( struct V_89 * V_65 , struct V_26 * V_27 )
{
struct V_14 * V_15 = F_56 ( V_65 ) ;
struct V_6 * V_7 = V_15 -> V_16 ;
struct V_8 * V_9 = & V_7 -> V_2 -> V_9 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_92 = 0 ;
V_23 = (struct V_22 * ) V_27 -> V_5 ;
if ( V_23 -> V_33 != sizeof( * V_25 ) ) {
F_12 ( V_9 , L_22 ) ;
V_7 -> V_37 = - V_93 ;
V_92 = - V_93 ;
goto V_98;
}
V_25 = F_57 ( V_27 , sizeof( * V_23 ) ) ;
if ( V_25 -> V_34 != V_99 ) {
F_12 ( V_9 , L_23 ,
V_25 -> V_34 ) ;
V_7 -> V_37 = - V_96 ;
V_92 = - V_96 ;
goto V_98;
}
F_23 ( V_9 , L_24 ) ;
V_98:
F_58 ( & V_7 -> F_17 ) ;
F_36 ( V_27 ) ;
return V_92 ;
}
static int F_60 ( struct V_89 * V_65 , struct V_26 * V_27 )
{
F_19 ( V_27 ) = V_100 ;
return F_61 ( V_65 , V_27 ) ;
}
static int F_62 ( struct V_14 * V_15 , const void * V_5 , int V_101 )
{
struct V_6 * V_7 = V_15 -> V_16 ;
struct V_8 * V_9 = & V_7 -> V_2 -> V_9 ;
int V_17 ;
if ( ! F_63 ( V_102 , & V_15 -> V_103 ) )
return - V_104 ;
V_7 -> V_88 = F_64 ( V_15 -> V_65 , V_7 -> V_88 , V_5 , V_101 ,
V_105 , F_65 ( V_105 ) ) ;
if ( F_34 ( V_7 -> V_88 ) ) {
V_17 = F_35 ( V_7 -> V_88 ) ;
F_12 ( V_9 , L_25 , V_17 ) ;
V_7 -> V_88 = NULL ;
return V_17 ;
}
return V_101 ;
}
static struct V_26 * F_66 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_16 ;
struct V_8 * V_9 = & V_7 -> V_2 -> V_9 ;
struct V_26 * V_106 = F_67 ( & V_7 -> V_87 ) ;
if ( ! V_7 -> V_79 )
return V_106 ;
if ( V_7 -> V_80 == ! ! V_106 )
return V_106 ;
if ( V_106 ) {
F_39 ( V_9 ) ;
F_9 ( V_7 -> V_19 , 1 ) ;
} else {
F_68 ( V_7 -> V_2 , 0 ) ;
F_9 ( V_7 -> V_19 , 0 ) ;
F_7 ( V_9 ) ;
}
V_7 -> V_80 = ! ! V_106 ;
return V_106 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_6 * V_7 ;
struct V_107 * V_45 ;
int V_17 = 0 ;
V_7 = F_70 ( V_9 , sizeof( * V_7 ) , V_30 ) ;
if ( ! V_7 )
return - V_31 ;
V_7 -> V_15 . V_2 = V_7 -> V_2 = V_2 ;
F_71 ( V_2 , V_7 ) ;
V_7 -> V_18 = F_72 ( V_9 , L_26 , V_108 ) ;
if ( F_34 ( V_7 -> V_18 ) ) {
V_17 = F_35 ( V_7 -> V_18 ) ;
F_12 ( V_9 , L_27 , V_17 ) ;
return V_17 ;
}
V_7 -> V_11 = F_72 ( V_9 , L_28 , V_109 ) ;
if ( F_34 ( V_7 -> V_11 ) ) {
V_17 = F_35 ( V_7 -> V_11 ) ;
F_12 ( V_9 , L_29 , V_17 ) ;
return V_17 ;
}
V_7 -> V_110 = F_73 ( V_7 -> V_11 ) ;
V_17 = F_74 ( V_9 , V_7 -> V_110 , NULL ,
F_4 ,
V_111 | V_112 | V_113 ,
L_30 , V_7 ) ;
if ( V_17 ) {
F_12 ( V_9 , L_31 , V_17 ) ;
return V_17 ;
}
V_7 -> V_19 = F_72 ( V_9 , L_32 ,
V_114 ) ;
if ( F_34 ( V_7 -> V_19 ) ) {
V_17 = F_35 ( V_7 -> V_19 ) ;
F_12 ( V_9 , L_33 , V_17 ) ;
return V_17 ;
}
V_45 = F_75 ( V_9 , L_34 ) ;
if ( F_34 ( V_45 ) ) {
V_17 = F_35 ( V_45 ) ;
F_12 ( V_9 , L_35 , V_17 ) ;
return V_17 ;
}
F_76 ( V_45 ) ;
V_7 -> V_43 = F_77 ( V_45 ) ;
F_78 ( V_45 ) ;
F_79 ( & V_7 -> V_87 ) ;
V_7 -> V_15 . V_16 = V_7 ;
V_7 -> V_15 . V_115 = 2 ;
V_17 = F_80 ( & V_7 -> V_15 , & V_116 ) ;
if ( V_17 ) {
F_12 ( V_9 , L_36 , V_17 ) ;
return V_17 ;
}
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_82 ( V_2 ) ;
F_83 ( & V_7 -> V_15 ) ;
}
static int F_84 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_85 ( V_9 ) ;
F_1 ( V_2 , false ) ;
return 0 ;
}
static int F_86 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_85 ( V_9 ) ;
F_1 ( V_2 , true ) ;
return 0 ;
}
