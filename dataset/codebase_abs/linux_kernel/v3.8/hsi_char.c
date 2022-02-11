static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
unsigned long V_7 ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
F_3 ( & V_4 -> V_9 , V_6 ) ;
F_4 ( & V_2 -> V_8 , V_7 ) ;
}
static struct V_3 * F_5 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_3 * V_4 = NULL ;
unsigned long V_7 ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
if ( F_6 ( V_6 ) )
goto V_10;
V_4 = F_7 ( V_6 , struct V_3 , V_9 ) ;
F_8 ( & V_4 -> V_9 ) ;
V_10:
F_4 ( & V_2 -> V_8 , V_7 ) ;
return V_4 ;
}
static inline void F_9 ( struct V_3 * V_4 )
{
F_10 ( F_11 ( V_4 -> V_11 . V_12 ) ) ;
F_12 ( V_4 ) ;
}
static void F_13 ( struct V_5 * V_13 )
{
struct V_3 * V_4 , * V_14 ;
F_14 (msg, tmp, list, link) {
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_4 ) ;
}
}
static void F_15 ( struct V_1 * V_2 , struct V_5 * V_15 )
{
unsigned long V_7 ;
F_16 ( V_13 ) ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
F_17 ( V_15 , & V_13 ) ;
F_4 ( & V_2 -> V_8 , V_7 ) ;
F_13 ( & V_13 ) ;
}
static inline struct V_3 * F_18 ( unsigned int V_16 )
{
struct V_3 * V_4 ;
void * V_17 ;
V_4 = F_19 ( 1 , V_18 ) ;
if ( ! V_4 )
goto V_10;
V_17 = F_20 ( V_16 , V_18 ) ;
if ( ! V_17 ) {
F_12 ( V_4 ) ;
goto V_10;
}
F_21 ( V_4 -> V_11 . V_12 , V_17 , V_16 ) ;
F_22 ( V_17 ) ;
return V_4 ;
V_10:
return NULL ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
V_4 = F_18 ( V_21 ) ;
if ( ! V_4 )
goto V_10;
V_4 -> V_2 = V_2 -> V_22 ;
F_3 ( & V_4 -> V_9 , & V_2 -> V_23 ) ;
}
return 0 ;
V_10:
F_13 ( & V_2 -> V_23 ) ;
return - V_24 ;
}
static inline unsigned int F_24 ( struct V_3 * V_4 )
{
return V_4 -> V_11 . V_12 -> V_25 ;
}
static inline void F_25 ( struct V_3 * V_4 , unsigned int V_26 )
{
V_4 -> V_11 . V_12 -> V_25 = V_26 ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_27 * V_28 = F_27 ( V_4 -> V_29 ) ;
struct V_1 * V_2 = V_28 -> V_30 + V_4 -> V_2 ;
if ( F_28 ( V_31 , & V_2 -> V_7 ) ) {
F_1 ( V_2 , V_4 , & V_2 -> V_32 ) ;
F_29 ( & V_2 -> V_33 ) ;
} else {
F_1 ( V_2 , V_4 , & V_2 -> V_23 ) ;
}
}
static void F_30 ( struct V_3 * V_4 )
{
V_4 -> V_34 = V_35 ;
F_25 ( V_4 , 0 ) ;
F_26 ( V_4 ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
struct V_27 * V_28 = F_27 ( V_4 -> V_29 ) ;
struct V_1 * V_2 = V_28 -> V_30 + V_4 -> V_2 ;
if ( F_28 ( V_36 , & V_2 -> V_7 ) ) {
F_1 ( V_2 , V_4 , & V_2 -> V_37 ) ;
F_29 ( & V_2 -> V_38 ) ;
} else {
F_1 ( V_2 , V_4 , & V_2 -> V_23 ) ;
}
}
static void F_32 ( struct V_3 * V_4 )
{
V_4 -> V_34 = V_35 ;
F_25 ( V_4 , 0 ) ;
F_31 ( V_4 ) ;
}
static void F_33 ( struct V_3 * V_4 )
{
struct V_27 * V_28 = F_27 ( V_4 -> V_29 ) ;
F_12 ( V_4 ) ;
F_34 ( V_39 , & V_28 -> V_7 ) ;
}
static void F_35 ( struct V_3 * V_4 )
{
struct V_27 * V_28 = F_27 ( V_4 -> V_29 ) ;
struct V_1 * V_2 = V_28 -> V_30 ;
int V_19 , V_40 ;
for ( V_19 = 0 ; V_19 < V_41 ; V_19 ++ , V_2 ++ ) {
struct V_3 * V_42 ;
if ( ! F_28 ( V_31 , & V_2 -> V_7 ) )
continue;
V_42 = F_5 ( V_2 , & V_2 -> V_23 ) ;
if ( ! V_42 )
continue;
F_34 ( V_31 , & V_2 -> V_7 ) ;
F_25 ( V_42 , 0 ) ;
V_42 -> V_34 = V_43 ;
F_1 ( V_2 , V_42 , & V_2 -> V_32 ) ;
F_29 ( & V_2 -> V_33 ) ;
}
F_36 ( V_4 -> V_29 ) ;
V_40 = F_37 ( V_4 -> V_29 , V_4 ) ;
if ( V_40 < 0 )
F_33 ( V_4 ) ;
}
static int F_38 ( struct V_44 * V_29 )
{
struct V_27 * V_28 = F_27 ( V_29 ) ;
struct V_3 * V_4 ;
int V_40 ;
if ( F_39 ( V_39 , & V_28 -> V_7 ) )
return - V_45 ;
V_4 = F_19 ( 0 , V_18 ) ;
if ( ! V_4 ) {
F_34 ( V_39 , & V_28 -> V_7 ) ;
return - V_24 ;
}
V_4 -> V_46 = 1 ;
V_4 -> V_47 = F_35 ;
V_4 -> V_48 = F_33 ;
V_40 = F_37 ( V_29 , V_4 ) ;
if ( V_40 < 0 )
F_33 ( V_4 ) ;
return V_40 ;
}
static int F_40 ( struct V_44 * V_29 )
{
struct V_3 * V_4 ;
int V_40 ;
V_4 = F_19 ( 0 , V_49 ) ;
if ( ! V_4 )
return - V_24 ;
V_4 -> V_46 = 1 ;
V_4 -> V_47 = F_12 ;
V_4 -> V_48 = F_12 ;
V_40 = F_41 ( V_29 , V_4 ) ;
if ( V_40 < 0 )
F_12 ( V_4 ) ;
return V_40 ;
}
static int F_42 ( struct V_44 * V_29 , struct V_50 * V_51 )
{
struct V_52 V_14 ;
int V_40 ;
if ( ( V_51 -> V_53 != V_54 ) && ( V_51 -> V_53 != V_55 ) )
return - V_56 ;
if ( ( V_51 -> V_30 == 0 ) || ( V_51 -> V_30 > V_41 ) )
return - V_56 ;
if ( V_51 -> V_30 & ( V_51 -> V_30 - 1 ) )
return - V_56 ;
if ( ( V_51 -> V_57 != V_58 ) && ( V_51 -> V_57 != V_59 ) )
return - V_56 ;
V_14 = V_29 -> V_60 ;
V_29 -> V_60 . V_53 = V_51 -> V_53 ;
V_29 -> V_60 . V_30 = V_51 -> V_30 ;
V_29 -> V_60 . V_57 = V_51 -> V_57 ;
V_40 = F_43 ( V_29 ) ;
if ( V_40 < 0 ) {
V_29 -> V_60 = V_14 ;
return V_40 ;
}
if ( V_51 -> V_53 == V_55 )
F_38 ( V_29 ) ;
return V_40 ;
}
static inline void F_44 ( struct V_44 * V_29 , struct V_50 * V_51 )
{
V_51 -> V_53 = V_29 -> V_60 . V_53 ;
V_51 -> V_30 = V_29 -> V_60 . V_30 ;
V_51 -> V_57 = V_29 -> V_60 . V_57 ;
}
static int F_45 ( struct V_44 * V_29 , struct V_61 * V_62 )
{
struct V_52 V_14 ;
int V_40 ;
if ( ( V_62 -> V_53 != V_54 ) && ( V_62 -> V_53 != V_55 ) )
return - V_56 ;
if ( ( V_62 -> V_30 == 0 ) || ( V_62 -> V_30 > V_41 ) )
return - V_56 ;
if ( V_62 -> V_30 & ( V_62 -> V_30 - 1 ) )
return - V_56 ;
if ( ( V_62 -> V_63 != V_64 ) && ( V_62 -> V_63 != V_65 ) )
return - V_56 ;
V_14 = V_29 -> V_66 ;
V_29 -> V_66 . V_53 = V_62 -> V_53 ;
V_29 -> V_66 . V_30 = V_62 -> V_30 ;
V_29 -> V_66 . V_67 = V_62 -> V_67 ;
V_29 -> V_66 . V_63 = V_62 -> V_63 ;
V_40 = F_43 ( V_29 ) ;
if ( V_40 < 0 ) {
V_29 -> V_66 = V_14 ;
return V_40 ;
}
return V_40 ;
}
static inline void F_46 ( struct V_44 * V_29 , struct V_61 * V_62 )
{
V_62 -> V_53 = V_29 -> V_66 . V_53 ;
V_62 -> V_30 = V_29 -> V_66 . V_30 ;
V_62 -> V_67 = V_29 -> V_66 . V_67 ;
V_62 -> V_63 = V_29 -> V_66 . V_63 ;
}
static T_1 F_47 ( struct V_68 * V_68 , char T_2 * V_17 , T_3 V_26 ,
T_4 * T_5 V_69 )
{
struct V_1 * V_2 = V_68 -> V_70 ;
struct V_3 * V_4 ;
T_1 V_40 ;
if ( V_26 == 0 )
return 0 ;
if ( ! F_48 ( V_26 , sizeof( V_71 ) ) )
return - V_56 ;
if ( V_26 > V_21 )
V_26 = V_21 ;
if ( V_2 -> V_22 >= V_2 -> V_29 -> V_60 . V_30 )
return - V_72 ;
if ( F_39 ( V_31 , & V_2 -> V_7 ) )
return - V_45 ;
V_4 = F_5 ( V_2 , & V_2 -> V_23 ) ;
if ( ! V_4 ) {
V_40 = - V_73 ;
goto V_10;
}
F_25 ( V_4 , V_26 ) ;
V_4 -> V_47 = F_26 ;
V_4 -> V_48 = F_30 ;
V_40 = F_37 ( V_2 -> V_29 , V_4 ) ;
if ( V_40 < 0 ) {
F_1 ( V_2 , V_4 , & V_2 -> V_23 ) ;
goto V_10;
}
V_40 = F_49 ( V_2 -> V_33 ,
! F_6 ( & V_2 -> V_32 ) ) ;
if ( V_40 < 0 ) {
F_34 ( V_31 , & V_2 -> V_7 ) ;
F_36 ( V_2 -> V_29 ) ;
return - V_74 ;
}
V_4 = F_5 ( V_2 , & V_2 -> V_32 ) ;
if ( V_4 ) {
if ( V_4 -> V_34 != V_35 ) {
V_40 = F_50 ( ( void T_2 * ) V_17 ,
F_11 ( V_4 -> V_11 . V_12 ) , F_24 ( V_4 ) ) ;
if ( V_40 )
V_40 = - V_75 ;
else
V_40 = F_24 ( V_4 ) ;
} else {
V_40 = - V_76 ;
}
F_1 ( V_2 , V_4 , & V_2 -> V_23 ) ;
}
V_10:
F_34 ( V_31 , & V_2 -> V_7 ) ;
return V_40 ;
}
static T_1 F_51 ( struct V_68 * V_68 , const char T_2 * V_17 , T_3 V_26 ,
T_4 * T_5 V_69 )
{
struct V_1 * V_2 = V_68 -> V_70 ;
struct V_3 * V_4 ;
T_1 V_40 ;
if ( ( V_26 == 0 ) || ! F_48 ( V_26 , sizeof( V_71 ) ) )
return - V_56 ;
if ( V_26 > V_21 )
V_26 = V_21 ;
if ( V_2 -> V_22 >= V_2 -> V_29 -> V_66 . V_30 )
return - V_72 ;
if ( F_39 ( V_36 , & V_2 -> V_7 ) )
return - V_45 ;
V_4 = F_5 ( V_2 , & V_2 -> V_23 ) ;
if ( ! V_4 ) {
F_34 ( V_36 , & V_2 -> V_7 ) ;
return - V_73 ;
}
if ( F_52 ( F_11 ( V_4 -> V_11 . V_12 ) , ( void T_2 * ) V_17 , V_26 ) ) {
V_40 = - V_75 ;
goto V_10;
}
F_25 ( V_4 , V_26 ) ;
V_4 -> V_47 = F_31 ;
V_4 -> V_48 = F_32 ;
V_40 = F_41 ( V_2 -> V_29 , V_4 ) ;
if ( V_40 < 0 )
goto V_10;
V_40 = F_49 ( V_2 -> V_38 ,
! F_6 ( & V_2 -> V_37 ) ) ;
if ( V_40 < 0 ) {
F_34 ( V_36 , & V_2 -> V_7 ) ;
F_36 ( V_2 -> V_29 ) ;
return - V_74 ;
}
V_4 = F_5 ( V_2 , & V_2 -> V_37 ) ;
if ( V_4 ) {
if ( V_4 -> V_34 == V_35 )
V_40 = - V_76 ;
else
V_40 = F_24 ( V_4 ) ;
F_1 ( V_2 , V_4 , & V_2 -> V_23 ) ;
}
V_10:
F_34 ( V_36 , & V_2 -> V_7 ) ;
return V_40 ;
}
static long F_53 ( struct V_68 * V_68 , unsigned int V_77 , unsigned long V_78 )
{
struct V_1 * V_2 = V_68 -> V_70 ;
unsigned int V_79 ;
struct V_50 V_51 ;
struct V_61 V_62 ;
long V_40 = 0 ;
switch ( V_77 ) {
case V_80 :
F_36 ( V_2 -> V_29 ) ;
break;
case V_81 :
if ( F_52 ( & V_79 , ( void T_2 * ) V_78 , sizeof( V_79 ) ) )
return - V_75 ;
if ( V_79 == V_82 ) {
if ( F_39 ( V_83 , & V_2 -> V_7 ) )
return - V_56 ;
V_40 = F_54 ( V_2 -> V_29 ) ;
} else if ( V_79 == V_84 ) {
if ( ! F_55 ( V_83 , & V_2 -> V_7 ) )
return - V_56 ;
V_40 = F_56 ( V_2 -> V_29 ) ;
} else {
V_40 = - V_56 ;
}
break;
case V_85 :
return F_40 ( V_2 -> V_29 ) ;
case V_86 :
if ( F_52 ( & V_51 , ( void T_2 * ) V_78 , sizeof( V_51 ) ) )
return - V_75 ;
return F_42 ( V_2 -> V_29 , & V_51 ) ;
case V_87 :
F_44 ( V_2 -> V_29 , & V_51 ) ;
if ( F_50 ( ( void T_2 * ) V_78 , & V_51 , sizeof( V_51 ) ) )
return - V_75 ;
break;
case V_88 :
if ( F_52 ( & V_62 , ( void T_2 * ) V_78 , sizeof( V_62 ) ) )
return - V_75 ;
return F_45 ( V_2 -> V_29 , & V_62 ) ;
case V_89 :
F_46 ( V_2 -> V_29 , & V_62 ) ;
if ( F_50 ( ( void T_2 * ) V_78 , & V_62 , sizeof( V_62 ) ) )
return - V_75 ;
break;
default:
return - V_90 ;
}
return V_40 ;
}
static inline void F_57 ( struct V_27 * V_28 )
{
F_58 ( V_28 -> V_91 == 0 ) ;
if ( -- V_28 -> V_91 == 0 ) {
F_36 ( V_28 -> V_29 ) ;
F_59 ( V_28 -> V_29 ) ;
}
}
static int F_60 ( struct V_92 * V_92 , struct V_68 * V_68 )
{
struct V_27 * V_28 ;
struct V_1 * V_2 ;
int V_40 = 0 ;
F_61 ( L_1 , F_62 ( V_92 ) ) ;
V_28 = F_63 ( V_92 -> V_93 , struct V_27 , V_94 ) ;
F_64 ( & V_28 -> V_8 ) ;
V_2 = V_28 -> V_30 + ( F_62 ( V_92 ) & V_95 ) ;
if ( F_39 ( V_96 , & V_2 -> V_7 ) ) {
V_40 = - V_45 ;
goto V_10;
}
if ( V_28 -> V_91 == 0 ) {
V_40 = F_65 ( V_28 -> V_29 , 0 ) ;
if ( V_40 < 0 )
goto V_10;
F_43 ( V_28 -> V_29 ) ;
}
V_28 -> V_91 ++ ;
V_40 = F_23 ( V_2 ) ;
if ( V_40 < 0 ) {
F_57 ( V_28 ) ;
goto V_10;
}
V_68 -> V_70 = V_2 ;
F_66 ( & V_28 -> V_8 ) ;
return V_40 ;
V_10:
F_66 ( & V_28 -> V_8 ) ;
return V_40 ;
}
static int F_67 ( struct V_92 * V_92 V_69 , struct V_68 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_70 ;
struct V_27 * V_28 = V_2 -> V_28 ;
F_64 ( & V_28 -> V_8 ) ;
V_68 -> V_70 = NULL ;
if ( F_55 ( V_83 , & V_2 -> V_7 ) )
F_56 ( V_2 -> V_29 ) ;
F_57 ( V_28 ) ;
F_15 ( V_2 , & V_2 -> V_32 ) ;
F_15 ( V_2 , & V_2 -> V_37 ) ;
F_15 ( V_2 , & V_2 -> V_23 ) ;
F_34 ( V_31 , & V_2 -> V_7 ) ;
F_34 ( V_36 , & V_2 -> V_7 ) ;
F_34 ( V_96 , & V_2 -> V_7 ) ;
F_29 ( & V_2 -> V_33 ) ;
F_29 ( & V_2 -> V_38 ) ;
F_66 ( & V_28 -> V_8 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_69 ( & V_2 -> V_33 ) ;
F_69 ( & V_2 -> V_38 ) ;
F_70 ( & V_2 -> V_8 ) ;
F_71 ( & V_2 -> V_23 ) ;
F_71 ( & V_2 -> V_32 ) ;
F_71 ( & V_2 -> V_37 ) ;
}
static int F_72 ( struct V_97 * V_98 )
{
const char V_99 [] = L_2 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
struct V_44 * V_29 = F_73 ( V_98 ) ;
unsigned int V_100 ;
T_6 V_101 ;
int V_40 ;
int V_19 ;
V_28 = F_74 ( sizeof( * V_28 ) , V_18 ) ;
if ( ! V_28 ) {
F_75 ( V_98 , L_3 ) ;
return - V_24 ;
}
V_100 = F_76 ( F_77 ( V_29 ) , F_78 ( V_29 ) ) ;
if ( ! V_102 ) {
V_40 = F_79 ( & V_101 , V_100 ,
V_41 , V_99 ) ;
if ( V_40 > 0 )
V_102 = F_80 ( V_101 ) ;
} else {
V_101 = F_81 ( V_102 , V_100 ) ;
V_40 = F_82 ( V_101 , V_41 , V_99 ) ;
}
if ( V_40 < 0 ) {
F_75 ( V_98 , L_4 ,
V_102 ? L_5 : L_6 , V_40 ) ;
goto V_103;
}
F_83 ( & V_28 -> V_8 ) ;
F_84 ( V_29 , V_28 ) ;
F_85 ( & V_28 -> V_94 , & V_104 ) ;
V_28 -> V_94 . V_105 = V_106 ;
V_28 -> V_29 = V_29 ;
for ( V_19 = 0 , V_2 = V_28 -> V_30 ; V_19 < V_41 ; V_19 ++ , V_2 ++ ) {
F_68 ( V_2 ) ;
V_2 -> V_22 = V_19 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_28 = V_28 ;
}
V_40 = F_86 ( & V_28 -> V_94 , V_101 , V_41 ) ;
if ( V_40 ) {
F_75 ( V_98 , L_7 , V_40 ) ;
goto V_107;
}
return 0 ;
V_107:
F_87 ( V_101 , V_41 ) ;
V_103:
F_10 ( V_28 ) ;
return V_40 ;
}
static int F_88 ( struct V_97 * V_98 )
{
struct V_44 * V_29 = F_73 ( V_98 ) ;
struct V_27 * V_28 = F_27 ( V_29 ) ;
T_6 V_101 = V_28 -> V_94 . V_98 ;
F_89 ( & V_28 -> V_94 ) ;
F_87 ( V_101 , V_41 ) ;
F_84 ( V_29 , NULL ) ;
F_10 ( V_28 ) ;
return 0 ;
}
static int T_7 F_90 ( void )
{
int V_40 ;
if ( ( V_21 < 4 ) || ( V_21 > 0x10000 ) ||
( V_21 & ( V_21 - 1 ) ) ) {
F_91 ( L_8 ) ;
return - V_56 ;
}
V_40 = F_92 ( & V_108 ) ;
if ( V_40 ) {
F_91 ( L_9 , V_40 ) ;
return V_40 ;
}
F_93 ( L_10 ) ;
return 0 ;
}
static void T_8 F_94 ( void )
{
F_95 ( & V_108 ) ;
F_93 ( L_11 ) ;
}
