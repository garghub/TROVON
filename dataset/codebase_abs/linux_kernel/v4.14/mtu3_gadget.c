void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
__releases( V_2 -> V_6 -> V_7 )
__acquires( V_2 -> V_6 -> V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_6 ;
int V_11 = V_2 -> V_11 ;
V_9 = F_2 ( V_4 ) ;
F_3 ( & V_9 -> V_12 ) ;
if ( V_9 -> V_13 . V_5 == - V_14 )
V_9 -> V_13 . V_5 = V_5 ;
V_6 = V_9 -> V_6 ;
V_2 -> V_11 = 1 ;
F_4 ( & V_6 -> V_7 ) ;
if ( V_2 -> V_15 )
F_5 ( & V_6 -> V_16 , V_4 , V_2 -> V_17 ) ;
F_6 ( V_6 -> V_18 , L_1 , V_2 -> V_19 ,
V_4 , V_4 -> V_5 , V_9 -> V_13 . V_20 , V_9 -> V_13 . V_21 ) ;
F_7 ( & V_2 -> V_22 , & V_9 -> V_13 ) ;
F_8 ( & V_6 -> V_7 ) ;
V_2 -> V_11 = V_11 ;
}
static void F_9 ( struct V_1 * V_2 , const int V_5 )
{
struct V_8 * V_9 = NULL ;
V_2 -> V_11 = 1 ;
if ( F_10 ( & V_2 -> V_23 ) )
return;
F_6 ( V_2 -> V_6 -> V_18 , L_2 , V_2 -> V_19 , V_5 ) ;
if ( V_2 -> V_15 )
F_11 ( V_2 ) ;
while ( ! F_10 ( & V_2 -> V_23 ) ) {
V_9 = F_12 ( & V_2 -> V_23 ,
struct V_8 , V_12 ) ;
F_1 ( V_2 , & V_9 -> V_13 , V_5 ) ;
}
}
static int F_13 ( struct V_1 * V_2 )
{
const struct V_24 * V_25 ;
const struct V_26 * V_27 ;
struct V_10 * V_6 = V_2 -> V_6 ;
T_1 V_28 = 0 ;
T_1 V_29 = 0 ;
T_1 V_30 = 0 ;
int V_31 ;
int V_32 ;
V_25 = V_2 -> V_25 ;
V_27 = V_2 -> V_27 ;
V_2 -> type = F_14 ( V_25 ) ;
V_31 = F_15 ( V_25 ) ;
V_2 -> V_33 = V_31 & F_16 ( 10 , 0 ) ;
switch ( V_6 -> V_16 . V_34 ) {
case V_35 :
if ( F_17 ( V_25 ) ||
F_18 ( V_25 ) ) {
V_28 = V_25 -> V_36 ;
V_28 = F_19 ( V_28 , 1 , 16 ) - 1 ;
if ( F_18 ( V_25 ) && V_27 )
V_29 = V_27 -> V_37 ;
}
if ( V_27 )
V_30 = V_27 -> V_38 ;
break;
case V_39 :
if ( F_18 ( V_25 ) ||
F_17 ( V_25 ) ) {
V_28 = V_25 -> V_36 ;
V_28 = F_19 ( V_28 , 1 , 16 ) - 1 ;
V_30 = ( V_31 & F_16 ( 12 , 11 ) ) >> 11 ;
}
break;
default:
break;
}
F_6 ( V_6 -> V_18 , L_3 ,
V_40 , V_2 -> V_33 , V_28 , V_30 , V_29 ) ;
V_2 -> V_22 . V_41 = V_2 -> V_33 ;
V_2 -> V_22 . V_25 = V_25 ;
V_2 -> V_22 . V_27 = V_27 ;
V_2 -> V_42 = F_17 ( V_25 ) ? 0 : V_6 -> V_42 ;
V_32 = F_20 ( V_6 , V_2 , V_28 , V_30 , V_29 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_21 ( V_2 ) ;
if ( V_32 < 0 ) {
F_22 ( V_6 , V_2 ) ;
return V_32 ;
}
F_23 ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
F_25 ( V_2 ) ;
F_9 ( V_2 , - V_43 ) ;
F_22 ( V_6 , V_2 ) ;
F_26 ( V_2 ) ;
V_2 -> V_25 = NULL ;
V_2 -> V_22 . V_25 = NULL ;
V_2 -> V_27 = NULL ;
V_2 -> type = 0 ;
V_2 -> V_44 = 0 ;
return 0 ;
}
static int F_27 ( struct V_45 * V_22 ,
const struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_10 * V_6 ;
unsigned long V_44 ;
int V_32 = - V_46 ;
if ( ! V_22 || ! V_25 || V_25 -> V_47 != V_48 ) {
F_28 ( L_4 , V_40 ) ;
return - V_46 ;
}
if ( ! V_25 -> V_49 ) {
F_28 ( L_5 , V_40 ) ;
return - V_46 ;
}
V_2 = F_29 ( V_22 ) ;
V_6 = V_2 -> V_6 ;
if ( F_30 ( V_25 ) != V_2 -> V_15 )
return - V_46 ;
if ( ! ! F_31 ( V_25 ) ^ ! ! V_2 -> V_17 )
return - V_46 ;
F_6 ( V_6 -> V_18 , L_6 , V_40 , V_22 -> V_19 ) ;
if ( V_2 -> V_44 & V_50 ) {
F_32 ( V_6 -> V_18 , true , L_7 ,
V_2 -> V_19 ) ;
return 0 ;
}
F_33 ( & V_6 -> V_7 , V_44 ) ;
V_2 -> V_25 = V_25 ;
V_2 -> V_27 = V_22 -> V_27 ;
V_32 = F_13 ( V_2 ) ;
if ( V_32 )
goto error;
V_2 -> V_11 = 0 ;
V_2 -> V_51 = 0 ;
V_2 -> V_44 |= V_50 ;
V_6 -> V_52 ++ ;
error:
F_34 ( & V_6 -> V_7 , V_44 ) ;
F_6 ( V_6 -> V_18 , L_8 , V_40 , V_6 -> V_52 ) ;
return V_32 ;
}
static int F_35 ( struct V_45 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
unsigned long V_44 ;
F_6 ( V_6 -> V_18 , L_6 , V_40 , V_2 -> V_19 ) ;
if ( ! ( V_2 -> V_44 & V_50 ) ) {
F_36 ( V_6 -> V_18 , L_9 , V_2 -> V_19 ) ;
return 0 ;
}
F_33 ( & V_6 -> V_7 , V_44 ) ;
F_24 ( V_2 ) ;
V_2 -> V_44 &= ~ V_50 ;
V_6 -> V_52 -- ;
F_34 ( & ( V_6 -> V_7 ) , V_44 ) ;
F_6 ( V_6 -> V_18 , L_10 ,
V_40 , V_6 -> V_52 , V_6 -> V_53 ) ;
return 0 ;
}
struct V_3 * F_37 ( struct V_45 * V_22 , T_2 V_54 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_8 * V_9 ;
V_9 = F_38 ( sizeof( * V_9 ) , V_54 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_13 . V_55 = V_56 ;
V_9 -> V_15 = V_2 -> V_15 ;
V_9 -> V_2 = V_2 ;
return & V_9 -> V_13 ;
}
void F_39 ( struct V_45 * V_22 , struct V_3 * V_4 )
{
F_40 ( F_2 ( V_4 ) ) ;
}
static int F_41 ( struct V_45 * V_22 ,
struct V_3 * V_4 , T_2 V_54 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_10 * V_6 ;
unsigned long V_44 ;
int V_32 = 0 ;
if ( ! V_22 || ! V_4 )
return - V_46 ;
if ( ! V_4 -> V_57 )
return - V_58 ;
V_2 = F_29 ( V_22 ) ;
V_6 = V_2 -> V_6 ;
V_9 = F_2 ( V_4 ) ;
V_9 -> V_6 = V_6 ;
if ( V_9 -> V_2 != V_2 )
return - V_46 ;
F_6 ( V_6 -> V_18 , L_11 ,
V_40 , V_2 -> V_17 ? L_12 : L_13 , V_9 -> V_15 , V_22 -> V_19 ,
V_9 , V_22 -> V_41 , V_9 -> V_13 . V_21 ) ;
if ( V_4 -> V_21 > V_59 ) {
F_36 ( V_6 -> V_18 ,
L_14 ,
V_59 , V_4 -> V_21 ) ;
return - V_60 ;
}
if ( ! V_2 -> V_25 ) {
F_6 ( V_6 -> V_18 , L_15 ,
V_4 , V_22 -> V_19 ) ;
return - V_43 ;
}
V_9 -> V_13 . V_20 = 0 ;
V_9 -> V_13 . V_5 = - V_14 ;
V_32 = F_42 ( & V_6 -> V_16 , V_4 , V_2 -> V_17 ) ;
if ( V_32 ) {
F_43 ( V_6 -> V_18 , L_16 ) ;
return V_32 ;
}
F_33 ( & V_6 -> V_7 , V_44 ) ;
if ( F_44 ( V_2 ) ) {
V_32 = - V_61 ;
goto error;
}
F_45 ( & V_9 -> V_12 , & V_2 -> V_23 ) ;
F_46 ( V_2 , V_9 ) ;
F_47 ( V_2 ) ;
error:
F_34 ( & V_6 -> V_7 , V_44 ) ;
return V_32 ;
}
static int F_48 ( struct V_45 * V_22 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_8 * V_62 ;
unsigned long V_44 ;
int V_32 = 0 ;
struct V_10 * V_6 = V_2 -> V_6 ;
if ( ! V_22 || ! V_4 || V_9 -> V_2 != V_2 )
return - V_46 ;
F_6 ( V_6 -> V_18 , L_17 , V_40 , V_4 ) ;
F_33 ( & V_6 -> V_7 , V_44 ) ;
F_49 (r, &mep->req_list, list) {
if ( V_62 == V_9 )
break;
}
if ( V_62 != V_9 ) {
F_6 ( V_6 -> V_18 , L_18 , V_4 , V_22 -> V_19 ) ;
V_32 = - V_46 ;
goto V_63;
}
F_11 ( V_2 ) ;
F_1 ( V_2 , V_4 , - V_64 ) ;
F_23 ( V_2 ) ;
V_63:
F_34 ( & V_6 -> V_7 , V_44 ) ;
return V_32 ;
}
static int F_50 ( struct V_45 * V_22 , int V_65 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_8 * V_9 ;
unsigned long V_44 ;
int V_32 = 0 ;
if ( ! V_22 )
return - V_46 ;
F_6 ( V_6 -> V_18 , L_19 , V_40 , V_22 -> V_19 ) ;
F_33 ( & V_6 -> V_7 , V_44 ) ;
if ( V_2 -> type == V_66 ) {
V_32 = - V_46 ;
goto V_63;
}
V_9 = F_51 ( V_2 ) ;
if ( V_65 ) {
if ( V_9 ) {
F_6 ( V_6 -> V_18 , L_20 ,
V_22 -> V_19 ) ;
V_32 = - V_61 ;
goto V_63;
}
} else {
V_2 -> V_51 = 0 ;
}
F_6 ( V_6 -> V_18 , L_21 , V_22 -> V_19 , V_65 ? L_22 : L_23 ) ;
F_52 ( V_2 , V_65 ) ;
V_63:
F_34 ( & V_6 -> V_7 , V_44 ) ;
return V_32 ;
}
static int F_53 ( struct V_45 * V_22 )
{
struct V_1 * V_2 = F_29 ( V_22 ) ;
if ( ! V_22 )
return - V_46 ;
V_2 -> V_51 = 1 ;
return F_54 ( V_22 ) ;
}
static int F_55 ( struct V_67 * V_68 )
{
struct V_10 * V_6 = F_56 ( V_68 ) ;
return ( int ) F_57 ( V_6 -> V_69 , V_70 ) ;
}
static int F_58 ( struct V_67 * V_68 )
{
struct V_10 * V_6 = F_56 ( V_68 ) ;
unsigned long V_44 ;
F_6 ( V_6 -> V_18 , L_24 , V_40 ) ;
if ( ! V_6 -> V_71 )
return - V_60 ;
F_33 ( & V_6 -> V_7 , V_44 ) ;
if ( V_6 -> V_16 . V_34 == V_35 ) {
F_59 ( V_6 -> V_69 , V_72 , V_73 ) ;
} else {
F_59 ( V_6 -> V_69 , V_74 , V_75 ) ;
F_34 ( & V_6 -> V_7 , V_44 ) ;
F_60 ( 10000 , 11000 ) ;
F_33 ( & V_6 -> V_7 , V_44 ) ;
F_61 ( V_6 -> V_69 , V_74 , V_75 ) ;
}
F_34 ( & V_6 -> V_7 , V_44 ) ;
return 0 ;
}
static int F_62 ( struct V_67 * V_68 ,
int V_76 )
{
struct V_10 * V_6 = F_56 ( V_68 ) ;
V_6 -> V_77 = ! ! V_76 ;
return 0 ;
}
static int F_63 ( struct V_67 * V_68 , int V_78 )
{
struct V_10 * V_6 = F_56 ( V_68 ) ;
unsigned long V_44 ;
F_6 ( V_6 -> V_18 , L_25 , V_40 ,
V_78 ? L_26 : L_27 , V_6 -> V_53 ? L_28 : L_29 ) ;
F_33 ( & V_6 -> V_7 , V_44 ) ;
V_78 = ! ! V_78 ;
if ( ! V_6 -> V_53 ) {
V_6 -> V_79 = V_78 ;
} else if ( V_78 != V_6 -> V_79 ) {
V_6 -> V_79 = V_78 ;
F_64 ( V_6 , V_78 ) ;
}
F_34 ( & V_6 -> V_7 , V_44 ) ;
return 0 ;
}
static int F_65 ( struct V_67 * V_68 ,
struct V_80 * V_81 )
{
struct V_10 * V_6 = F_56 ( V_68 ) ;
unsigned long V_44 ;
if ( V_6 -> V_82 ) {
F_43 ( V_6 -> V_18 , L_30 ,
V_6 -> V_16 . V_19 , V_6 -> V_82 -> V_81 . V_19 ) ;
return - V_83 ;
}
F_6 ( V_6 -> V_18 , L_31 , V_81 -> V_84 ) ;
F_33 ( & V_6 -> V_7 , V_44 ) ;
V_6 -> V_79 = 0 ;
V_6 -> V_82 = V_81 ;
if ( V_6 -> V_85 -> V_86 == V_87 )
F_66 ( V_6 ) ;
F_34 ( & V_6 -> V_7 , V_44 ) ;
return 0 ;
}
static void F_67 ( struct V_10 * V_6 )
{
struct V_80 * V_81 = V_6 -> V_82 ;
int V_88 ;
if ( V_6 -> V_16 . V_34 == V_89 )
V_81 = NULL ;
else
V_6 -> V_16 . V_34 = V_89 ;
if ( V_6 -> V_79 ) {
V_6 -> V_79 = 0 ;
F_64 ( V_6 , 0 ) ;
}
F_9 ( V_6 -> V_90 , - V_43 ) ;
for ( V_88 = 1 ; V_88 < V_6 -> V_91 ; V_88 ++ ) {
F_9 ( V_6 -> V_92 + V_88 , - V_43 ) ;
F_9 ( V_6 -> V_93 + V_88 , - V_43 ) ;
}
if ( V_81 ) {
F_4 ( & V_6 -> V_7 ) ;
V_81 -> V_94 ( & V_6 -> V_16 ) ;
F_8 ( & V_6 -> V_7 ) ;
}
}
static int F_68 ( struct V_67 * V_16 )
{
struct V_10 * V_6 = F_56 ( V_16 ) ;
unsigned long V_44 ;
F_6 ( V_6 -> V_18 , L_24 , V_40 ) ;
F_33 ( & V_6 -> V_7 , V_44 ) ;
F_67 ( V_6 ) ;
V_6 -> V_82 = NULL ;
if ( V_6 -> V_85 -> V_86 == V_87 )
F_69 ( V_6 ) ;
F_34 ( & V_6 -> V_7 , V_44 ) ;
return 0 ;
}
static void F_70 ( struct V_10 * V_6 , struct V_1 * V_2 ,
T_1 V_15 , T_1 V_17 )
{
V_2 -> V_15 = V_15 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_17 = V_17 ;
F_71 ( & V_2 -> V_23 ) ;
sprintf ( V_2 -> V_19 , L_32 , V_15 ,
! V_15 ? L_28 : ( V_17 ? L_29 : L_33 ) ) ;
V_2 -> V_22 . V_19 = V_2 -> V_19 ;
F_71 ( & V_2 -> V_22 . V_95 ) ;
if ( ! V_15 ) {
F_72 ( & V_2 -> V_22 , 512 ) ;
V_2 -> V_22 . V_96 . V_97 = true ;
V_2 -> V_22 . V_98 = & V_99 ;
V_6 -> V_16 . V_90 = & V_2 -> V_22 ;
} else {
F_72 ( & V_2 -> V_22 , 1024 ) ;
V_2 -> V_22 . V_96 . V_100 = true ;
V_2 -> V_22 . V_96 . V_101 = true ;
V_2 -> V_22 . V_96 . V_102 = true ;
V_2 -> V_22 . V_98 = & V_103 ;
F_45 ( & V_2 -> V_22 . V_95 , & V_6 -> V_16 . V_95 ) ;
}
F_6 ( V_6 -> V_18 , L_34 , V_40 , V_2 -> V_22 . V_19 ,
V_2 -> V_22 . V_41 ) ;
if ( ! V_15 ) {
V_2 -> V_22 . V_96 . V_104 = true ;
V_2 -> V_22 . V_96 . V_105 = true ;
} else if ( V_17 ) {
V_2 -> V_22 . V_96 . V_104 = true ;
} else {
V_2 -> V_22 . V_96 . V_105 = true ;
}
}
static void F_73 ( struct V_10 * V_6 )
{
T_3 V_15 ;
F_71 ( & ( V_6 -> V_16 . V_95 ) ) ;
F_6 ( V_6 -> V_18 , L_35 ,
V_40 , V_6 -> V_91 ) ;
F_70 ( V_6 , V_6 -> V_90 , 0 , 0 ) ;
for ( V_15 = 1 ; V_15 < V_6 -> V_91 ; V_15 ++ ) {
F_70 ( V_6 , V_6 -> V_92 + V_15 , V_15 , 1 ) ;
F_70 ( V_6 , V_6 -> V_93 + V_15 , V_15 , 0 ) ;
}
}
int F_74 ( struct V_10 * V_6 )
{
int V_32 ;
V_6 -> V_16 . V_98 = & V_106 ;
V_6 -> V_16 . V_107 = V_6 -> V_107 ;
V_6 -> V_16 . V_34 = V_89 ;
V_6 -> V_16 . V_108 = 0 ;
V_6 -> V_16 . V_19 = V_109 ;
V_6 -> V_53 = 0 ;
V_6 -> V_110 = false ;
F_73 ( V_6 ) ;
V_32 = F_75 ( V_6 -> V_18 , & V_6 -> V_16 ) ;
if ( V_32 ) {
F_43 ( V_6 -> V_18 , L_36 ) ;
return V_32 ;
}
F_76 ( & V_6 -> V_16 , V_111 ) ;
return 0 ;
}
void F_77 ( struct V_10 * V_6 )
{
F_78 ( & V_6 -> V_16 ) ;
}
void F_79 ( struct V_10 * V_6 )
{
F_6 ( V_6 -> V_18 , L_37 ) ;
if ( V_6 -> V_82 && V_6 -> V_82 -> V_112 ) {
F_4 ( & V_6 -> V_7 ) ;
V_6 -> V_82 -> V_112 ( & V_6 -> V_16 ) ;
F_8 ( & V_6 -> V_7 ) ;
}
}
void F_80 ( struct V_10 * V_6 )
{
F_6 ( V_6 -> V_18 , L_38 ) ;
if ( V_6 -> V_82 && V_6 -> V_82 -> V_113 ) {
F_4 ( & V_6 -> V_7 ) ;
V_6 -> V_82 -> V_113 ( & V_6 -> V_16 ) ;
F_8 ( & V_6 -> V_7 ) ;
}
}
void F_81 ( struct V_10 * V_6 )
{
F_6 ( V_6 -> V_18 , L_39 ) ;
if ( V_6 -> V_82 && V_6 -> V_82 -> V_94 ) {
F_4 ( & V_6 -> V_7 ) ;
V_6 -> V_82 -> V_94 ( & V_6 -> V_16 ) ;
F_8 ( & V_6 -> V_7 ) ;
}
F_76 ( & V_6 -> V_16 , V_111 ) ;
}
void F_82 ( struct V_10 * V_6 )
{
F_6 ( V_6 -> V_18 , L_40 ) ;
if ( V_6 -> V_16 . V_34 != V_89 )
F_81 ( V_6 ) ;
V_6 -> V_114 = 0 ;
V_6 -> V_115 = V_116 ;
V_6 -> V_71 = 0 ;
V_6 -> V_117 = 0 ;
V_6 -> V_118 = 0 ;
V_6 -> V_110 = false ;
}
