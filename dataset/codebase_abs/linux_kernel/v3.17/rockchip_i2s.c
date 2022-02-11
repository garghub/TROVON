static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_5 ( V_4 -> V_5 ) ;
if ( V_6 ) {
F_6 ( V_4 -> V_2 , L_1 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static inline struct V_3 * F_7 ( struct V_7 * V_8 )
{
return F_8 ( V_8 ) ;
}
static void F_9 ( struct V_3 * V_4 , int V_9 )
{
unsigned int V_10 = 0 ;
int V_11 = 10 ;
if ( V_9 ) {
F_10 ( V_4 -> V_12 , V_13 ,
V_14 , V_14 ) ;
F_10 ( V_4 -> V_12 , V_15 ,
V_16 | V_17 ,
V_16 | V_17 ) ;
V_4 -> V_18 = true ;
} else {
V_4 -> V_18 = false ;
F_10 ( V_4 -> V_12 , V_13 ,
V_14 , V_19 ) ;
if ( ! V_4 -> V_20 ) {
F_10 ( V_4 -> V_12 , V_15 ,
V_16 |
V_17 ,
V_21 |
V_22 ) ;
F_10 ( V_4 -> V_12 , V_23 ,
V_24 | V_25 ,
V_24 | V_25 ) ;
F_11 ( V_4 -> V_12 , V_23 , & V_10 ) ;
while ( V_10 ) {
F_11 ( V_4 -> V_12 , V_23 , & V_10 ) ;
V_11 -- ;
if ( ! V_11 )
F_12 ( V_4 -> V_2 , L_2 ) ;
}
}
}
}
static void F_13 ( struct V_3 * V_4 , int V_9 )
{
unsigned int V_10 = 0 ;
int V_11 = 10 ;
if ( V_9 ) {
F_10 ( V_4 -> V_12 , V_13 ,
V_26 , V_26 ) ;
F_10 ( V_4 -> V_12 , V_15 ,
V_16 | V_17 ,
V_16 | V_17 ) ;
V_4 -> V_20 = true ;
} else {
V_4 -> V_20 = false ;
F_10 ( V_4 -> V_12 , V_13 ,
V_26 , V_27 ) ;
if ( ! V_4 -> V_18 ) {
F_10 ( V_4 -> V_12 , V_15 ,
V_16 |
V_17 ,
V_21 |
V_22 ) ;
F_10 ( V_4 -> V_12 , V_23 ,
V_24 | V_25 ,
V_24 | V_25 ) ;
F_11 ( V_4 -> V_12 , V_23 , & V_10 ) ;
while ( V_10 ) {
F_11 ( V_4 -> V_12 , V_23 , & V_10 ) ;
V_11 -- ;
if ( ! V_11 )
F_12 ( V_4 -> V_2 , L_2 ) ;
}
}
}
}
static int F_14 ( struct V_7 * V_28 ,
unsigned int V_29 )
{
struct V_3 * V_4 = F_7 ( V_28 ) ;
unsigned int V_30 = 0 , V_10 = 0 ;
V_30 = V_31 ;
switch ( V_29 & V_32 ) {
case V_33 :
V_10 = V_34 ;
break;
case V_35 :
V_10 = V_36 ;
break;
default:
return - V_37 ;
}
F_10 ( V_4 -> V_12 , V_38 , V_30 , V_10 ) ;
V_30 = V_39 ;
switch ( V_29 & V_40 ) {
case V_41 :
V_10 = V_42 ;
break;
case V_43 :
V_10 = V_44 ;
break;
case V_45 :
V_10 = V_46 ;
break;
default:
return - V_37 ;
}
F_10 ( V_4 -> V_12 , V_47 , V_30 , V_10 ) ;
V_30 = V_48 ;
switch ( V_29 & V_40 ) {
case V_41 :
V_10 = V_49 ;
break;
case V_43 :
V_10 = V_50 ;
break;
case V_45 :
V_10 = V_51 ;
break;
default:
return - V_37 ;
}
F_10 ( V_4 -> V_12 , V_52 , V_30 , V_10 ) ;
return 0 ;
}
static int F_15 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_7 ( V_8 ) ;
unsigned int V_10 = 0 ;
switch ( F_16 ( V_56 ) ) {
case V_57 :
V_10 |= F_17 ( 8 ) ;
break;
case V_58 :
V_10 |= F_17 ( 16 ) ;
break;
case V_59 :
V_10 |= F_17 ( 20 ) ;
break;
case V_60 :
V_10 |= F_17 ( 24 ) ;
break;
default:
return - V_37 ;
}
F_10 ( V_4 -> V_12 , V_47 , V_61 , V_10 ) ;
F_10 ( V_4 -> V_12 , V_52 , V_62 , V_10 ) ;
if ( V_54 -> V_63 == V_64 ) {
V_8 -> V_65 = & V_4 -> V_65 ;
F_10 ( V_4 -> V_12 , V_13 , V_66 ,
F_18 ( 1 ) | V_14 ) ;
} else {
V_8 -> V_67 = & V_4 -> V_67 ;
F_10 ( V_4 -> V_12 , V_13 , V_68 ,
F_19 ( 1 ) | V_26 ) ;
}
return 0 ;
}
static int F_20 ( struct V_53 * V_54 ,
int V_69 , struct V_7 * V_8 )
{
struct V_3 * V_4 = F_7 ( V_8 ) ;
int V_6 = 0 ;
switch ( V_69 ) {
case V_70 :
case V_71 :
case V_72 :
if ( V_54 -> V_63 == V_73 )
F_13 ( V_4 , 1 ) ;
else
F_9 ( V_4 , 1 ) ;
break;
case V_74 :
case V_75 :
case V_76 :
if ( V_54 -> V_63 == V_73 )
F_13 ( V_4 , 0 ) ;
else
F_9 ( V_4 , 0 ) ;
break;
default:
V_6 = - V_37 ;
break;
}
return V_6 ;
}
static int F_21 ( struct V_7 * V_28 , int V_77 ,
unsigned int V_78 , int V_79 )
{
struct V_3 * V_4 = F_7 ( V_28 ) ;
int V_6 ;
V_6 = F_22 ( V_4 -> V_5 , V_78 ) ;
if ( V_6 )
F_6 ( V_4 -> V_2 , L_3 , V_6 ) ;
return V_6 ;
}
static bool F_23 ( struct V_1 * V_2 , unsigned int V_80 )
{
switch ( V_80 ) {
case V_47 :
case V_52 :
case V_38 :
case V_13 :
case V_81 :
case V_15 :
case V_23 :
case V_82 :
return true ;
default:
return false ;
}
}
static bool F_24 ( struct V_1 * V_2 , unsigned int V_80 )
{
switch ( V_80 ) {
case V_47 :
case V_52 :
case V_38 :
case V_13 :
case V_81 :
case V_15 :
case V_23 :
case V_83 :
case V_84 :
case V_85 :
return true ;
default:
return false ;
}
}
static bool F_25 ( struct V_1 * V_2 , unsigned int V_80 )
{
switch ( V_80 ) {
case V_85 :
case V_23 :
return true ;
default:
return false ;
}
}
static bool F_26 ( struct V_1 * V_2 , unsigned int V_80 )
{
switch ( V_80 ) {
default:
return false ;
}
}
static int F_27 ( struct V_86 * V_87 )
{
struct V_3 * V_4 ;
struct V_88 * V_89 ;
void T_1 * V_90 ;
int V_6 ;
V_4 = F_28 ( & V_87 -> V_2 , sizeof( * V_4 ) , V_91 ) ;
if ( ! V_4 ) {
F_6 ( & V_87 -> V_2 , L_4 ) ;
return - V_92 ;
}
V_4 -> V_93 = F_29 ( & V_87 -> V_2 , L_5 ) ;
if ( F_30 ( V_4 -> V_93 ) ) {
F_6 ( & V_87 -> V_2 , L_6 ) ;
return F_31 ( V_4 -> V_93 ) ;
}
V_4 -> V_5 = F_29 ( & V_87 -> V_2 , L_7 ) ;
if ( F_30 ( V_4 -> V_5 ) ) {
F_6 ( & V_87 -> V_2 , L_8 ) ;
return F_31 ( V_4 -> V_5 ) ;
}
V_89 = F_32 ( V_87 , V_94 , 0 ) ;
V_90 = F_33 ( & V_87 -> V_2 , V_89 ) ;
if ( F_30 ( V_90 ) )
return F_31 ( V_90 ) ;
V_4 -> V_12 = F_34 ( & V_87 -> V_2 , V_90 ,
& V_95 ) ;
if ( F_30 ( V_4 -> V_12 ) ) {
F_6 ( & V_87 -> V_2 ,
L_9 ) ;
return F_31 ( V_4 -> V_12 ) ;
}
V_4 -> V_65 . V_96 = V_89 -> V_97 + V_82 ;
V_4 -> V_65 . V_98 = V_99 ;
V_4 -> V_65 . V_100 = 16 ;
V_4 -> V_67 . V_96 = V_89 -> V_97 + V_83 ;
V_4 -> V_67 . V_98 = V_99 ;
V_4 -> V_67 . V_100 = 16 ;
V_4 -> V_2 = & V_87 -> V_2 ;
F_35 ( & V_87 -> V_2 , V_4 ) ;
F_36 ( & V_87 -> V_2 ) ;
if ( ! F_37 ( & V_87 -> V_2 ) ) {
V_6 = F_4 ( & V_87 -> V_2 ) ;
if ( V_6 )
goto V_101;
}
V_6 = F_38 ( & V_87 -> V_2 ,
& V_102 ,
& V_103 , 1 ) ;
if ( V_6 ) {
F_6 ( & V_87 -> V_2 , L_10 ) ;
goto V_104;
}
V_6 = F_39 ( & V_87 -> V_2 , NULL , 0 ) ;
if ( V_6 ) {
F_6 ( & V_87 -> V_2 , L_11 ) ;
goto V_105;
}
return 0 ;
V_105:
F_40 ( & V_87 -> V_2 ) ;
V_104:
if ( ! F_41 ( & V_87 -> V_2 ) )
F_1 ( & V_87 -> V_2 ) ;
V_101:
F_42 ( & V_87 -> V_2 ) ;
return V_6 ;
}
static int F_43 ( struct V_86 * V_87 )
{
struct V_3 * V_4 = F_2 ( & V_87 -> V_2 ) ;
F_42 ( & V_87 -> V_2 ) ;
if ( ! F_41 ( & V_87 -> V_2 ) )
F_1 ( & V_87 -> V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_93 ) ;
F_40 ( & V_87 -> V_2 ) ;
F_44 ( & V_87 -> V_2 ) ;
return 0 ;
}
