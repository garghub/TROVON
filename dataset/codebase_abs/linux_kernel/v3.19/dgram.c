static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 )
{
F_4 ( & V_4 ) ;
F_5 ( V_3 , & V_5 ) ;
F_6 ( F_7 ( V_3 ) , V_3 -> V_6 , 1 ) ;
F_8 ( & V_4 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_4 ( & V_4 ) ;
if ( F_10 ( V_3 ) )
F_6 ( F_7 ( V_3 ) , V_3 -> V_6 , - 1 ) ;
F_8 ( & V_4 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_8 = 1 ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 , long V_9 )
{
F_13 ( V_3 ) ;
}
static int F_14 ( struct V_2 * V_3 , struct V_10 * V_11 , int V_12 )
{
struct V_13 * V_14 = (struct V_13 * ) V_11 ;
struct V_15 V_16 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_17 = - V_18 ;
struct V_19 * V_20 ;
F_15 ( V_3 ) ;
V_7 -> V_21 = 0 ;
if ( V_12 < sizeof( * V_14 ) )
goto V_22;
if ( V_14 -> V_23 != V_24 )
goto V_22;
F_16 ( & V_16 , & V_14 -> V_14 ) ;
V_20 = F_17 ( F_7 ( V_3 ) , & V_16 ) ;
if ( ! V_20 ) {
V_17 = - V_25 ;
goto V_22;
}
if ( V_20 -> type != V_26 ) {
V_17 = - V_25 ;
goto V_27;
}
V_7 -> V_28 = V_16 ;
V_7 -> V_21 = 1 ;
V_17 = 0 ;
V_27:
F_18 ( V_20 ) ;
V_22:
F_19 ( V_3 ) ;
return V_17 ;
}
static int F_20 ( struct V_2 * V_3 , int V_29 , unsigned long V_30 )
{
switch ( V_29 ) {
case V_31 :
{
int V_32 = F_21 ( V_3 ) ;
return F_22 ( V_32 , ( int V_33 * ) V_30 ) ;
}
case V_34 :
{
struct V_35 * V_36 ;
unsigned long V_32 ;
V_32 = 0 ;
F_23 ( & V_3 -> V_37 . V_38 ) ;
V_36 = F_24 ( & V_3 -> V_37 ) ;
if ( V_36 != NULL ) {
V_32 = V_36 -> V_12 - F_25 ( V_36 ) ;
}
F_26 ( & V_3 -> V_37 . V_38 ) ;
return F_22 ( V_32 , ( int V_33 * ) V_30 ) ;
}
}
return - V_39 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_10 * V_11 ,
int V_12 )
{
struct V_13 * V_14 = (struct V_13 * ) V_11 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_17 = 0 ;
if ( V_12 < sizeof( * V_14 ) )
return - V_18 ;
if ( V_14 -> V_23 != V_24 )
return - V_18 ;
F_15 ( V_3 ) ;
if ( ! V_7 -> V_21 ) {
V_17 = - V_40 ;
goto V_22;
}
F_16 ( & V_7 -> V_41 , & V_14 -> V_14 ) ;
V_7 -> V_42 = 1 ;
V_22:
F_19 ( V_3 ) ;
return V_17 ;
}
static int F_28 ( struct V_2 * V_3 , int V_43 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_15 ( V_3 ) ;
V_7 -> V_42 = 0 ;
F_19 ( V_3 ) ;
return 0 ;
}
static int F_29 ( struct V_44 * V_45 , struct V_2 * V_3 ,
struct V_46 * V_47 , T_1 V_48 )
{
struct V_19 * V_20 ;
unsigned int V_49 ;
struct V_35 * V_36 ;
struct V_50 * V_51 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_15 V_41 ;
int V_52 , V_53 ;
int V_17 ;
if ( V_47 -> V_54 & V_55 ) {
F_30 ( L_1 , V_47 -> V_54 ) ;
return - V_56 ;
}
if ( ! V_7 -> V_42 && ! V_47 -> V_57 )
return - V_58 ;
else if ( V_7 -> V_42 && V_47 -> V_57 )
return - V_59 ;
if ( ! V_7 -> V_21 )
V_20 = F_31 ( F_7 ( V_3 ) , V_26 ) ;
else
V_20 = F_17 ( F_7 ( V_3 ) , & V_7 -> V_28 ) ;
if ( ! V_20 ) {
F_30 ( L_2 ) ;
V_17 = - V_60 ;
goto V_22;
}
V_49 = V_20 -> V_49 ;
F_30 ( L_3 , V_20 -> V_61 , V_49 ) ;
if ( V_48 > V_49 ) {
F_30 ( L_4 , V_48 , V_49 ) ;
V_17 = - V_62 ;
goto V_63;
}
V_52 = F_32 ( V_20 ) ;
V_53 = V_20 -> V_64 ;
V_36 = F_33 ( V_3 , V_52 + V_53 + V_48 ,
V_47 -> V_54 & V_65 ,
& V_17 ) ;
if ( ! V_36 )
goto V_63;
F_34 ( V_36 , V_52 ) ;
F_35 ( V_36 ) ;
V_51 = F_36 ( V_36 ) ;
V_51 -> type = V_66 ;
V_51 -> V_67 = V_7 -> V_8 ;
if ( V_47 -> V_57 ) {
F_37 ( struct V_13 * ,
V_68 , V_47 -> V_57 ) ;
F_16 ( & V_41 , & V_68 -> V_14 ) ;
} else {
V_41 = V_7 -> V_41 ;
}
V_51 -> V_69 = V_7 -> V_69 ;
V_51 -> V_70 = V_7 -> V_70 ;
V_51 -> V_71 = V_7 -> V_71 ;
V_51 -> V_72 = V_7 -> V_72 ;
V_17 = F_38 ( V_36 , V_20 , V_73 , & V_41 ,
V_7 -> V_21 ? & V_7 -> V_28 : NULL , V_48 ) ;
if ( V_17 < 0 )
goto V_74;
V_17 = F_39 ( F_40 ( V_36 , V_48 ) , V_47 , V_48 ) ;
if ( V_17 < 0 )
goto V_74;
V_36 -> V_20 = V_20 ;
V_36 -> V_3 = V_3 ;
V_36 -> V_75 = F_41 ( V_73 ) ;
F_18 ( V_20 ) ;
V_17 = F_42 ( V_36 ) ;
if ( V_17 > 0 )
V_17 = F_43 ( V_17 ) ;
return V_17 ? : V_48 ;
V_74:
F_44 ( V_36 ) ;
V_63:
F_18 ( V_20 ) ;
V_22:
return V_17 ;
}
static int F_45 ( struct V_44 * V_45 , struct V_2 * V_3 ,
struct V_46 * V_47 , T_1 V_12 , int V_76 ,
int V_43 , int * V_77 )
{
T_1 V_78 = 0 ;
int V_17 = - V_56 ;
struct V_35 * V_36 ;
F_37 ( struct V_13 * , V_79 , V_47 -> V_57 ) ;
V_36 = F_46 ( V_3 , V_43 , V_76 , & V_17 ) ;
if ( ! V_36 )
goto V_22;
V_78 = V_36 -> V_12 ;
if ( V_12 < V_78 ) {
V_47 -> V_54 |= V_80 ;
V_78 = V_12 ;
}
V_17 = F_47 ( V_36 , 0 , V_47 , V_78 ) ;
if ( V_17 )
goto V_81;
F_48 ( V_47 , V_3 , V_36 ) ;
if ( V_79 ) {
V_79 -> V_23 = V_24 ;
F_49 ( & V_79 -> V_14 , & F_50 ( V_36 ) -> V_82 ) ;
* V_77 = sizeof( * V_79 ) ;
}
if ( V_43 & V_80 )
V_78 = V_36 -> V_12 ;
V_81:
F_51 ( V_3 , V_36 ) ;
V_22:
if ( V_17 )
return V_17 ;
return V_78 ;
}
static int F_52 ( struct V_2 * V_3 , struct V_35 * V_36 )
{
V_36 = F_53 ( V_36 , V_83 ) ;
if ( ! V_36 )
return V_84 ;
if ( F_54 ( V_3 , V_36 ) < 0 ) {
F_44 ( V_36 ) ;
return V_84 ;
}
return V_85 ;
}
static inline bool
F_55 ( T_2 V_86 , T_3 V_87 , T_3 V_88 ,
struct V_1 * V_7 )
{
if ( ! V_7 -> V_21 )
return true ;
if ( V_7 -> V_28 . V_89 == V_90 &&
V_86 == V_7 -> V_28 . V_91 )
return true ;
if ( V_7 -> V_28 . V_89 == V_92 &&
V_87 == V_7 -> V_28 . V_87 &&
V_88 == V_7 -> V_28 . V_88 )
return true ;
return false ;
}
int F_56 ( struct V_19 * V_20 , struct V_35 * V_36 )
{
struct V_2 * V_3 , * V_93 = NULL ;
int V_94 = V_85 ;
T_3 V_87 , V_88 ;
T_2 V_86 ;
F_57 ( V_20 -> type != V_26 ) ;
V_87 = F_58 ( V_20 ) -> F_59 ( V_20 ) ;
V_88 = F_58 ( V_20 ) -> F_60 ( V_20 ) ;
V_86 = F_61 ( V_20 -> V_95 ) ;
F_62 ( & V_4 ) ;
F_63 (sk, &dgram_head) {
if ( F_55 ( V_86 , V_87 , V_88 ,
F_1 ( V_3 ) ) ) {
if ( V_93 ) {
struct V_35 * V_96 ;
V_96 = F_64 ( V_36 , V_83 ) ;
if ( V_96 )
F_52 ( V_93 , V_96 ) ;
}
V_93 = V_3 ;
}
}
if ( V_93 ) {
F_52 ( V_93 , V_36 ) ;
} else {
F_44 ( V_36 ) ;
V_94 = V_84 ;
}
F_65 ( & V_4 ) ;
return V_94 ;
}
static int F_66 ( struct V_2 * V_3 , int V_97 , int V_98 ,
char V_33 * V_99 , int V_33 * V_100 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_101 , V_12 ;
if ( V_97 != V_102 )
return - V_56 ;
if ( F_67 ( V_12 , V_100 ) )
return - V_103 ;
V_12 = F_68 (unsigned int, len, sizeof(int)) ;
switch ( V_98 ) {
case V_104 :
V_101 = V_7 -> V_8 ;
break;
case V_105 :
if ( ! V_7 -> V_70 )
V_101 = V_106 ;
else if ( V_7 -> V_69 )
V_101 = V_107 ;
else
V_101 = V_108 ;
break;
case V_109 :
if ( ! V_7 -> V_72 )
V_101 = V_110 ;
else
V_101 = V_7 -> V_71 ;
break;
default:
return - V_111 ;
}
if ( F_22 ( V_12 , V_100 ) )
return - V_103 ;
if ( F_69 ( V_99 , & V_101 , V_12 ) )
return - V_103 ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , int V_97 , int V_98 ,
char V_33 * V_99 , unsigned int V_100 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_112 * V_112 = F_7 ( V_3 ) ;
int V_101 ;
int V_17 = 0 ;
if ( V_100 < sizeof( int ) )
return - V_18 ;
if ( F_67 ( V_101 , ( int V_33 * ) V_99 ) )
return - V_103 ;
F_15 ( V_3 ) ;
switch ( V_98 ) {
case V_104 :
V_7 -> V_8 = ! ! V_101 ;
break;
case V_105 :
if ( ! F_71 ( V_112 -> V_113 , V_114 ) &&
! F_71 ( V_112 -> V_113 , V_115 ) ) {
V_17 = - V_116 ;
break;
}
switch ( V_101 ) {
case V_106 :
V_7 -> V_70 = 0 ;
break;
case V_107 :
V_7 -> V_70 = 1 ;
V_7 -> V_69 = 1 ;
break;
case V_108 :
V_7 -> V_70 = 1 ;
V_7 -> V_69 = 0 ;
break;
default:
V_17 = - V_18 ;
break;
}
break;
case V_109 :
if ( ! F_71 ( V_112 -> V_113 , V_114 ) &&
! F_71 ( V_112 -> V_113 , V_115 ) ) {
V_17 = - V_116 ;
break;
}
if ( V_101 < V_110 ||
V_101 > V_117 ) {
V_17 = - V_18 ;
} else if ( V_101 == V_110 ) {
V_7 -> V_72 = 0 ;
} else {
V_7 -> V_72 = 1 ;
V_7 -> V_71 = V_101 ;
}
break;
default:
V_17 = - V_111 ;
break;
}
F_19 ( V_3 ) ;
return V_17 ;
}
