static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
unsigned long V_4 = F_2 ( F_3 ( V_3 ) ) ;
return ( void * ) F_4 ( ( V_5 * ) F_5 ( V_3 ) , V_4 + 1 ) ;
}
static void F_6 ( struct V_6 * V_3 , int V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 ;
if ( V_7 == - V_11 )
return;
V_9 -> V_7 = V_7 ;
F_7 ( & V_9 -> V_12 ) ;
}
static int F_8 ( struct V_13 * V_14 , const V_5 * V_15 ,
unsigned int V_16 )
{
struct V_17 * V_18 = F_9 ( V_14 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_21 * V_22 = V_18 -> V_22 ;
struct {
T_1 V_23 ;
V_5 V_24 [ 8 ] ;
struct V_8 V_9 ;
struct V_25 V_26 [ 1 ] ;
struct V_27 V_3 ;
} * V_10 ;
int V_7 ;
F_10 ( V_22 , V_28 ) ;
F_11 ( V_22 , F_12 ( V_14 ) &
V_28 ) ;
V_7 = F_13 ( V_22 , V_15 , V_16 ) ;
if ( V_7 )
return V_7 ;
F_14 ( V_14 , F_15 ( V_22 ) &
V_29 ) ;
V_10 = F_16 ( sizeof( * V_10 ) + F_17 ( V_22 ) ,
V_30 ) ;
if ( ! V_10 )
return - V_31 ;
F_18 ( & V_10 -> V_9 . V_12 ) ;
F_19 ( V_10 -> V_26 , & V_10 -> V_23 , sizeof( V_10 -> V_23 ) ) ;
F_20 ( & V_10 -> V_3 , V_22 ) ;
F_21 ( & V_10 -> V_3 , V_32 |
V_33 ,
F_6 ,
& V_10 -> V_9 ) ;
F_22 ( & V_10 -> V_3 , V_10 -> V_26 , V_10 -> V_26 ,
sizeof( V_10 -> V_23 ) , V_10 -> V_24 ) ;
V_7 = F_23 ( & V_10 -> V_3 ) ;
if ( V_7 == - V_11 || V_7 == - V_34 ) {
V_7 = F_24 (
& V_10 -> V_9 . V_12 ) ;
if ( ! V_7 )
V_7 = V_10 -> V_9 . V_7 ;
}
if ( V_7 )
goto V_35;
F_25 ( V_20 , V_28 ) ;
F_26 ( V_20 , F_12 ( V_14 ) &
V_28 ) ;
V_7 = F_27 ( V_20 , ( V_5 * ) & V_10 -> V_23 , sizeof( T_1 ) ) ;
F_14 ( V_14 , F_28 ( V_20 ) &
V_29 ) ;
V_35:
F_29 ( V_10 ) ;
return V_7 ;
}
static int F_30 ( struct V_13 * V_36 ,
unsigned int V_37 )
{
switch ( V_37 ) {
case 4 :
case 8 :
case 12 :
case 13 :
case 14 :
case 15 :
case 16 :
break;
default:
return - V_38 ;
}
return 0 ;
}
static void F_31 ( struct V_27 * V_39 ,
struct V_2 * V_3 ,
unsigned int V_40 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_17 * V_18 = F_9 ( V_14 ) ;
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_25 * V_42 ;
T_2 V_43 = F_32 ( 1 ) ;
memset ( V_41 -> V_44 , 0 , sizeof( V_41 -> V_44 ) ) ;
memcpy ( V_3 -> V_24 + 12 , & V_43 , 4 ) ;
F_33 ( V_41 -> V_45 , 2 ) ;
F_34 ( V_41 -> V_45 , V_41 -> V_44 , sizeof( V_41 -> V_44 ) ) ;
F_35 ( V_41 -> V_45 , 2 , V_3 -> V_45 ) ;
V_42 = V_41 -> V_45 ;
if ( V_3 -> V_45 != V_3 -> V_42 ) {
F_33 ( V_41 -> V_42 , 2 ) ;
F_34 ( V_41 -> V_42 , V_41 -> V_44 , sizeof( V_41 -> V_44 ) ) ;
F_35 ( V_41 -> V_42 , 2 , V_3 -> V_42 ) ;
V_42 = V_41 -> V_42 ;
}
F_20 ( V_39 , V_18 -> V_22 ) ;
F_22 ( V_39 , V_41 -> V_45 , V_42 ,
V_40 + sizeof( V_41 -> V_44 ) ,
V_3 -> V_24 ) ;
}
static inline unsigned int F_36 ( unsigned int V_46 )
{
V_46 &= 0xfU ;
return V_46 ? 16 - V_46 : 0 ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_1 * V_41 ,
T_3 F_7 ,
struct V_25 * V_45 ,
unsigned int V_46 )
{
struct V_47 * V_48 = & V_41 -> V_49 . V_48 ;
F_38 ( V_48 , F_39 ( V_3 ) ,
F_7 , V_3 ) ;
F_40 ( V_48 , V_45 , NULL , V_46 ) ;
return F_41 ( V_48 ) ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_1 * V_41 ,
unsigned int V_50 ,
T_3 F_7 )
{
struct V_47 * V_48 = & V_41 -> V_49 . V_48 ;
F_38 ( V_48 , F_39 ( V_3 ) ,
F_7 , V_3 ) ;
F_19 ( V_41 -> V_45 , V_51 , V_50 ) ;
F_40 ( V_48 , V_41 -> V_45 , NULL , V_50 ) ;
return F_41 ( V_48 ) ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_1 * V_41 )
{
struct V_47 * V_48 = & V_41 -> V_49 . V_48 ;
struct V_52 * V_53 = & V_41 -> V_54 ;
T_4 V_55 ;
V_55 . V_56 = F_44 ( V_3 -> V_57 * 8 ) ;
V_55 . V_58 = F_44 ( V_53 -> V_40 * 8 ) ;
memcpy ( V_41 -> V_59 , & V_55 , 16 ) ;
F_19 ( V_41 -> V_45 , V_41 -> V_59 , 16 ) ;
F_38 ( V_48 , F_39 ( V_3 ) ,
V_60 , V_3 ) ;
F_40 ( V_48 , V_41 -> V_45 ,
NULL , sizeof( V_55 ) ) ;
return F_41 ( V_48 ) ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_1 * V_41 )
{
struct V_47 * V_48 = & V_41 -> V_49 . V_48 ;
F_38 ( V_48 , F_39 ( V_3 ) ,
V_61 , V_3 ) ;
F_40 ( V_48 , NULL , V_41 -> V_59 , 0 ) ;
return F_46 ( V_48 ) ;
}
static void F_47 ( struct V_2 * V_3 , int V_7 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_52 * V_53 = & V_41 -> V_54 ;
if ( ! V_7 )
F_48 ( V_41 -> V_44 , V_41 -> V_59 , 16 ) ;
V_53 -> F_7 ( V_3 , V_7 ) ;
}
static void V_61 ( struct V_6 * V_62 , int V_7 )
{
struct V_2 * V_3 = V_62 -> V_10 ;
F_47 ( V_3 , V_7 ) ;
}
static void F_49 ( struct V_2 * V_3 , int V_7 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_7 = F_45 ( V_3 , V_41 ) ;
if ( V_7 == - V_11 || V_7 == - V_34 )
return;
}
F_47 ( V_3 , V_7 ) ;
}
static void V_60 ( struct V_6 * V_62 , int V_7 )
{
struct V_2 * V_3 = V_62 -> V_10 ;
F_49 ( V_3 , V_7 ) ;
}
static void F_50 ( struct V_2 * V_3 , int V_7 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_7 = F_43 ( V_3 , V_41 ) ;
if ( V_7 == - V_11 || V_7 == - V_34 )
return;
}
F_49 ( V_3 , V_7 ) ;
}
static void F_51 ( struct V_6 * V_62 ,
int V_7 )
{
struct V_2 * V_3 = V_62 -> V_10 ;
F_50 ( V_3 , V_7 ) ;
}
static void F_52 ( struct V_2 * V_3 , int V_7 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_52 * V_53 = & V_41 -> V_54 ;
unsigned int V_50 ;
if ( ! V_7 ) {
V_50 = F_36 ( V_53 -> V_40 ) ;
F_53 ( ! V_50 ) ;
V_7 = F_42 ( V_3 , V_41 , V_50 ,
F_51 ) ;
if ( V_7 == - V_11 || V_7 == - V_34 )
return;
}
F_50 ( V_3 , V_7 ) ;
}
static void F_54 ( struct V_6 * V_62 , int V_7 )
{
struct V_2 * V_3 = V_62 -> V_10 ;
F_52 ( V_3 , V_7 ) ;
}
static void F_55 ( struct V_2 * V_3 , int V_7 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_52 * V_53 = & V_41 -> V_54 ;
T_3 F_7 ;
unsigned int V_50 = 0 ;
if ( ! V_7 && V_53 -> V_40 ) {
V_50 = F_36 ( V_53 -> V_40 ) ;
F_7 = V_50 ? F_54 :
F_51 ;
V_7 = F_37 ( V_3 , V_41 , F_7 ,
V_53 -> V_45 , V_53 -> V_40 ) ;
if ( V_7 == - V_11 || V_7 == - V_34 )
return;
}
if ( V_50 )
F_52 ( V_3 , V_7 ) ;
else
F_50 ( V_3 , V_7 ) ;
}
static void F_56 ( struct V_6 * V_62 ,
int V_7 )
{
struct V_2 * V_3 = V_62 -> V_10 ;
F_55 ( V_3 , V_7 ) ;
}
static void F_57 ( struct V_2 * V_3 , int V_7 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
unsigned int V_50 ;
if ( ! V_7 ) {
V_50 = F_36 ( V_3 -> V_57 ) ;
F_53 ( ! V_50 ) ;
V_7 = F_42 ( V_3 , V_41 , V_50 ,
F_56 ) ;
if ( V_7 == - V_11 || V_7 == - V_34 )
return;
}
F_55 ( V_3 , V_7 ) ;
}
static void F_58 ( struct V_6 * V_62 , int V_7 )
{
struct V_2 * V_3 = V_62 -> V_10 ;
F_57 ( V_3 , V_7 ) ;
}
static void F_59 ( struct V_2 * V_3 , int V_7 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
T_3 F_7 ;
unsigned int V_50 = 0 ;
if ( ! V_7 && V_3 -> V_57 ) {
V_50 = F_36 ( V_3 -> V_57 ) ;
F_7 = V_50 ? F_58 :
F_56 ;
V_7 = F_37 ( V_3 , V_41 , F_7 ,
V_3 -> V_63 , V_3 -> V_57 ) ;
if ( V_7 == - V_11 || V_7 == - V_34 )
return;
}
if ( V_50 )
F_57 ( V_3 , V_7 ) ;
else
F_55 ( V_3 , V_7 ) ;
}
static void F_60 ( struct V_6 * V_62 , int V_7 )
{
struct V_2 * V_3 = V_62 -> V_10 ;
F_59 ( V_3 , V_7 ) ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_1 * V_41 )
{
struct V_47 * V_48 = & V_41 -> V_49 . V_48 ;
struct V_52 * V_53 = & V_41 -> V_54 ;
struct V_17 * V_18 = F_62 ( V_3 -> V_64 . V_36 ) ;
unsigned int V_50 ;
T_3 F_7 ;
int V_7 ;
F_63 ( V_48 , V_18 -> V_20 ) ;
F_38 ( V_48 , F_39 ( V_3 ) ,
F_60 , V_3 ) ;
V_7 = F_64 ( V_48 ) ;
if ( V_7 )
return V_7 ;
V_50 = F_36 ( V_3 -> V_57 ) ;
F_7 = V_50 ? F_58 : F_56 ;
V_7 = F_37 ( V_3 , V_41 , F_7 , V_3 -> V_63 , V_3 -> V_57 ) ;
if ( V_7 )
return V_7 ;
if ( V_50 ) {
V_7 = F_42 ( V_3 , V_41 , V_50 ,
F_56 ) ;
if ( V_7 )
return V_7 ;
}
V_50 = F_36 ( V_53 -> V_40 ) ;
F_7 = V_50 ? F_54 : F_51 ;
V_7 = F_37 ( V_3 , V_41 , F_7 , V_53 -> V_45 , V_53 -> V_40 ) ;
if ( V_7 )
return V_7 ;
if ( V_50 ) {
V_7 = F_42 ( V_3 , V_41 , V_50 ,
F_51 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_43 ( V_3 , V_41 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_45 ( V_3 , V_41 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static void F_65 ( struct V_2 * V_3 ,
struct V_1 * V_41 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
V_5 * V_44 = V_41 -> V_44 ;
F_66 ( V_44 , V_3 -> V_42 , V_3 -> V_40 ,
F_67 ( V_14 ) , 1 ) ;
}
static void F_68 ( struct V_2 * V_3 , int V_7 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
if ( ! V_7 )
F_65 ( V_3 , V_41 ) ;
F_69 ( V_3 , V_7 ) ;
}
static void F_70 ( struct V_6 * V_62 , int V_7 )
{
struct V_2 * V_3 = V_62 -> V_10 ;
struct V_1 * V_41 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_7 = F_61 ( V_3 , V_41 ) ;
if ( V_7 == - V_11 || V_7 == - V_34 )
return;
else if ( ! V_7 ) {
F_48 ( V_41 -> V_44 , V_41 -> V_59 , 16 ) ;
F_65 ( V_3 , V_41 ) ;
}
}
F_69 ( V_3 , V_7 ) ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_27 * V_65 = & V_41 -> V_49 . V_65 ;
struct V_52 * V_53 = & V_41 -> V_54 ;
int V_7 ;
F_31 ( V_65 , V_3 , V_3 -> V_40 ) ;
F_21 ( V_65 , F_39 ( V_3 ) ,
F_70 , V_3 ) ;
V_53 -> V_45 = V_3 -> V_42 ;
V_53 -> V_40 = V_3 -> V_40 ;
V_53 -> F_7 = F_68 ;
V_7 = F_23 ( V_65 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_61 ( V_3 , V_41 ) ;
if ( V_7 )
return V_7 ;
F_48 ( V_41 -> V_44 , V_41 -> V_59 , 16 ) ;
F_65 ( V_3 , V_41 ) ;
return 0 ;
}
static int F_72 ( struct V_2 * V_3 ,
struct V_1 * V_41 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
V_5 * V_44 = V_41 -> V_44 ;
V_5 * V_59 = V_41 -> V_59 ;
unsigned int V_37 = F_67 ( V_14 ) ;
unsigned int V_40 = V_3 -> V_40 - V_37 ;
F_48 ( V_44 , V_59 , 16 ) ;
F_66 ( V_59 , V_3 -> V_45 , V_40 , V_37 , 0 ) ;
return F_73 ( V_59 , V_44 , V_37 ) ? - V_66 : 0 ;
}
static void F_74 ( struct V_6 * V_62 , int V_7 )
{
struct V_2 * V_3 = V_62 -> V_10 ;
struct V_1 * V_41 = F_1 ( V_3 ) ;
if ( ! V_7 )
V_7 = F_72 ( V_3 , V_41 ) ;
F_69 ( V_3 , V_7 ) ;
}
static void F_75 ( struct V_2 * V_3 , int V_7 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_27 * V_65 = & V_41 -> V_49 . V_65 ;
struct V_52 * V_53 = & V_41 -> V_54 ;
if ( ! V_7 ) {
F_21 ( V_65 , F_39 ( V_3 ) ,
F_74 , V_3 ) ;
F_31 ( V_65 , V_3 , V_53 -> V_40 ) ;
V_7 = F_76 ( V_65 ) ;
if ( V_7 == - V_11 || V_7 == - V_34 )
return;
else if ( ! V_7 )
V_7 = F_72 ( V_3 , V_41 ) ;
}
F_69 ( V_3 , V_7 ) ;
}
static int F_77 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_27 * V_65 = & V_41 -> V_49 . V_65 ;
struct V_52 * V_53 = & V_41 -> V_54 ;
unsigned int V_37 = F_67 ( V_14 ) ;
unsigned int V_40 = V_3 -> V_40 ;
int V_7 ;
if ( V_40 < V_37 )
return - V_38 ;
V_40 -= V_37 ;
V_53 -> V_45 = V_3 -> V_45 ;
V_53 -> V_40 = V_40 ;
V_53 -> F_7 = F_75 ;
V_7 = F_61 ( V_3 , V_41 ) ;
if ( V_7 )
return V_7 ;
F_21 ( V_65 , F_39 ( V_3 ) ,
F_74 , V_3 ) ;
F_31 ( V_65 , V_3 , V_40 ) ;
V_7 = F_76 ( V_65 ) ;
if ( V_7 )
return V_7 ;
return F_72 ( V_3 , V_41 ) ;
}
static int F_78 ( struct V_67 * V_36 )
{
struct V_68 * V_69 = ( void * ) V_36 -> V_70 ;
struct V_71 * V_72 = F_79 ( V_69 ) ;
struct V_17 * V_18 = F_62 ( V_36 ) ;
struct V_21 * V_22 ;
struct V_19 * V_20 ;
unsigned long V_4 ;
int V_7 ;
V_20 = F_80 ( & V_72 -> V_20 ) ;
if ( F_81 ( V_20 ) )
return F_82 ( V_20 ) ;
V_22 = F_83 ( & V_72 -> V_22 ) ;
V_7 = F_82 ( V_22 ) ;
if ( F_81 ( V_22 ) )
goto V_73;
V_18 -> V_22 = V_22 ;
V_18 -> V_20 = V_20 ;
V_4 = F_84 ( V_36 ) ;
V_4 &= ~ ( F_85 () - 1 ) ;
V_36 -> V_74 . V_75 = V_4 +
F_86 ( struct V_1 , V_49 ) +
F_87 ( sizeof( struct V_27 ) +
F_17 ( V_22 ) ,
sizeof( struct V_47 ) +
F_88 ( V_20 ) ) ;
return 0 ;
V_73:
F_89 ( V_20 ) ;
return V_7 ;
}
static void F_90 ( struct V_67 * V_36 )
{
struct V_17 * V_18 = F_62 ( V_36 ) ;
F_89 ( V_18 -> V_20 ) ;
F_91 ( V_18 -> V_22 ) ;
}
static struct V_68 * F_92 ( struct V_76 * * V_77 ,
const char * V_78 ,
const char * V_79 ,
const char * V_80 )
{
struct V_81 * V_82 ;
struct V_68 * V_69 ;
struct V_83 * V_22 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_71 * V_18 ;
int V_7 ;
V_82 = F_93 ( V_77 ) ;
if ( F_81 ( V_82 ) )
return F_94 ( V_82 ) ;
if ( ( V_82 -> type ^ V_87 ) & V_82 -> V_88 )
return F_95 ( - V_38 ) ;
V_84 = F_96 ( V_80 , & V_89 ,
V_90 ,
V_91 ) ;
if ( F_81 ( V_84 ) )
return F_94 ( V_84 ) ;
V_7 = - V_31 ;
V_69 = F_16 ( sizeof( * V_69 ) + sizeof( * V_18 ) , V_30 ) ;
if ( ! V_69 )
goto V_92;
V_18 = F_79 ( V_69 ) ;
V_86 = F_97 ( V_84 , struct V_85 , V_93 . V_64 ) ;
V_7 = F_98 ( & V_18 -> V_20 , & V_86 -> V_93 ,
V_69 ) ;
if ( V_7 )
goto V_94;
F_99 ( & V_18 -> V_22 , V_69 ) ;
V_7 = F_100 ( & V_18 -> V_22 , V_79 , 0 ,
F_101 ( V_82 -> type ,
V_82 -> V_88 ) ) ;
if ( V_7 )
goto V_95;
V_22 = F_102 ( & V_18 -> V_22 ) ;
if ( V_22 -> V_96 . V_97 != 16 )
goto V_98;
V_7 = - V_38 ;
if ( V_22 -> V_99 != 1 )
goto V_98;
V_7 = - V_100 ;
if ( snprintf ( V_69 -> V_101 . V_102 , V_103 ,
L_1 , V_22 -> V_102 ,
V_84 -> V_102 ) >=
V_103 )
goto V_98;
memcpy ( V_69 -> V_101 . V_104 , V_78 , V_103 ) ;
V_69 -> V_101 . V_105 = V_87 ;
V_69 -> V_101 . V_105 |= V_22 -> V_105 & V_106 ;
V_69 -> V_101 . V_107 = V_22 -> V_107 ;
V_69 -> V_101 . V_99 = 1 ;
V_69 -> V_101 . V_108 = V_22 -> V_108 | ( F_103 ( V_109 ) - 1 ) ;
V_69 -> V_101 . V_110 = & V_111 ;
V_69 -> V_101 . V_112 . V_97 = 16 ;
V_69 -> V_101 . V_112 . V_113 = 16 ;
V_69 -> V_101 . V_114 = sizeof( struct V_17 ) ;
V_69 -> V_101 . V_115 = F_78 ;
V_69 -> V_101 . V_116 = F_90 ;
V_69 -> V_101 . V_112 . V_117 = F_8 ;
V_69 -> V_101 . V_112 . V_118 = F_30 ;
V_69 -> V_101 . V_112 . V_119 = F_71 ;
V_69 -> V_101 . V_112 . V_120 = F_77 ;
V_35:
F_104 ( V_84 ) ;
return V_69 ;
V_98:
F_105 ( & V_18 -> V_22 ) ;
V_95:
F_106 ( & V_18 -> V_20 ) ;
V_94:
F_29 ( V_69 ) ;
V_92:
V_69 = F_95 ( V_7 ) ;
goto V_35;
}
static struct V_68 * F_107 ( struct V_76 * * V_77 )
{
const char * V_121 ;
char V_79 [ V_103 ] ;
char V_78 [ V_103 ] ;
V_121 = F_108 ( V_77 [ 1 ] ) ;
if ( F_81 ( V_121 ) )
return F_94 ( V_121 ) ;
if ( snprintf ( V_79 , V_103 , L_2 , V_121 ) >=
V_103 )
return F_95 ( - V_100 ) ;
if ( snprintf ( V_78 , V_103 , L_3 , V_121 ) >=
V_103 )
return F_95 ( - V_100 ) ;
return F_92 ( V_77 , V_78 , V_79 , L_4 ) ;
}
static void F_109 ( struct V_68 * V_69 )
{
struct V_71 * V_18 = F_79 ( V_69 ) ;
F_105 ( & V_18 -> V_22 ) ;
F_106 ( & V_18 -> V_20 ) ;
F_29 ( V_69 ) ;
}
static struct V_68 * F_110 ( struct V_76 * * V_77 )
{
const char * V_79 ;
const char * V_80 ;
char V_78 [ V_103 ] ;
V_79 = F_108 ( V_77 [ 1 ] ) ;
if ( F_81 ( V_79 ) )
return F_94 ( V_79 ) ;
V_80 = F_108 ( V_77 [ 2 ] ) ;
if ( F_81 ( V_80 ) )
return F_94 ( V_80 ) ;
if ( snprintf ( V_78 , V_103 , L_1 ,
V_79 , V_80 ) >= V_103 )
return F_95 ( - V_100 ) ;
return F_92 ( V_77 , V_78 , V_79 , V_80 ) ;
}
static int F_111 ( struct V_13 * V_122 , const V_5 * V_15 ,
unsigned int V_16 )
{
struct V_123 * V_18 = F_9 ( V_122 ) ;
struct V_13 * V_124 = V_18 -> V_124 ;
int V_7 ;
if ( V_16 < 4 )
return - V_38 ;
V_16 -= 4 ;
memcpy ( V_18 -> V_125 , V_15 + V_16 , 4 ) ;
F_112 ( V_124 , V_28 ) ;
F_14 ( V_124 , F_12 ( V_122 ) &
V_28 ) ;
V_7 = F_113 ( V_124 , V_15 , V_16 ) ;
F_14 ( V_122 , F_12 ( V_124 ) &
V_29 ) ;
return V_7 ;
}
static int F_114 ( struct V_13 * V_122 ,
unsigned int V_37 )
{
struct V_123 * V_18 = F_9 ( V_122 ) ;
switch ( V_37 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_38 ;
}
return F_115 ( V_18 -> V_124 , V_37 ) ;
}
static struct V_2 * F_116 ( struct V_2 * V_3 )
{
struct V_2 * V_126 = F_5 ( V_3 ) ;
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_123 * V_18 = F_9 ( V_14 ) ;
struct V_13 * V_124 = V_18 -> V_124 ;
V_5 * V_24 = F_4 ( ( V_5 * ) ( V_126 + 1 ) + F_117 ( V_124 ) ,
F_2 ( V_124 ) + 1 ) ;
memcpy ( V_24 , V_18 -> V_125 , 4 ) ;
memcpy ( V_24 + 4 , V_3 -> V_24 , 8 ) ;
F_118 ( V_126 , V_124 ) ;
F_119 ( V_126 , V_3 -> V_64 . V_127 , V_3 -> V_64 . F_7 ,
V_3 -> V_64 . V_10 ) ;
F_120 ( V_126 , V_3 -> V_45 , V_3 -> V_42 , V_3 -> V_40 , V_24 ) ;
F_121 ( V_126 , V_3 -> V_63 , V_3 -> V_57 ) ;
return V_126 ;
}
static int F_122 ( struct V_2 * V_3 )
{
V_3 = F_116 ( V_3 ) ;
return F_123 ( V_3 ) ;
}
static int F_124 ( struct V_2 * V_3 )
{
V_3 = F_116 ( V_3 ) ;
return F_125 ( V_3 ) ;
}
static int F_126 ( struct V_67 * V_36 )
{
struct V_68 * V_69 = ( void * ) V_36 -> V_70 ;
struct V_128 * V_129 = F_79 ( V_69 ) ;
struct V_123 * V_18 = F_62 ( V_36 ) ;
struct V_13 * V_14 ;
unsigned long V_4 ;
V_14 = F_127 ( V_129 ) ;
if ( F_81 ( V_14 ) )
return F_82 ( V_14 ) ;
V_18 -> V_124 = V_14 ;
V_4 = F_2 ( V_14 ) ;
V_4 &= ~ ( F_85 () - 1 ) ;
V_36 -> V_74 . V_75 = sizeof( struct V_2 ) +
F_128 ( F_117 ( V_14 ) ,
F_85 () ) +
V_4 + 16 ;
return 0 ;
}
static void F_129 ( struct V_67 * V_36 )
{
struct V_123 * V_18 = F_62 ( V_36 ) ;
F_130 ( V_18 -> V_124 ) ;
}
static struct V_68 * F_131 ( struct V_76 * * V_77 )
{
struct V_81 * V_82 ;
struct V_68 * V_69 ;
struct V_128 * V_129 ;
struct V_83 * V_101 ;
const char * V_130 ;
int V_7 ;
V_82 = F_93 ( V_77 ) ;
if ( F_81 ( V_82 ) )
return F_94 ( V_82 ) ;
if ( ( V_82 -> type ^ V_87 ) & V_82 -> V_88 )
return F_95 ( - V_38 ) ;
V_130 = F_108 ( V_77 [ 1 ] ) ;
if ( F_81 ( V_130 ) )
return F_94 ( V_130 ) ;
V_69 = F_16 ( sizeof( * V_69 ) + sizeof( * V_129 ) , V_30 ) ;
if ( ! V_69 )
return F_95 ( - V_31 ) ;
V_129 = F_79 ( V_69 ) ;
F_132 ( V_129 , V_69 ) ;
V_7 = F_133 ( V_129 , V_130 , 0 ,
F_101 ( V_82 -> type , V_82 -> V_88 ) ) ;
if ( V_7 )
goto V_131;
V_101 = F_134 ( V_129 ) ;
V_7 = - V_38 ;
if ( V_101 -> V_112 . V_97 != 16 )
goto V_132;
if ( V_101 -> V_99 != 1 )
goto V_132;
V_7 = - V_100 ;
if ( snprintf ( V_69 -> V_101 . V_104 , V_103 ,
L_5 , V_101 -> V_104 ) >= V_103 ||
snprintf ( V_69 -> V_101 . V_102 , V_103 ,
L_5 , V_101 -> V_102 ) >=
V_103 )
goto V_132;
V_69 -> V_101 . V_105 = V_87 ;
V_69 -> V_101 . V_105 |= V_101 -> V_105 & V_106 ;
V_69 -> V_101 . V_107 = V_101 -> V_107 ;
V_69 -> V_101 . V_99 = 1 ;
V_69 -> V_101 . V_108 = V_101 -> V_108 ;
V_69 -> V_101 . V_110 = & V_133 ;
V_69 -> V_101 . V_112 . V_97 = 8 ;
V_69 -> V_101 . V_112 . V_113 = 16 ;
V_69 -> V_101 . V_114 = sizeof( struct V_123 ) ;
V_69 -> V_101 . V_115 = F_126 ;
V_69 -> V_101 . V_116 = F_129 ;
V_69 -> V_101 . V_112 . V_117 = F_111 ;
V_69 -> V_101 . V_112 . V_118 = F_114 ;
V_69 -> V_101 . V_112 . V_119 = F_122 ;
V_69 -> V_101 . V_112 . V_120 = F_124 ;
V_69 -> V_101 . V_112 . V_134 = L_6 ;
V_35:
return V_69 ;
V_132:
F_135 ( V_129 ) ;
V_131:
F_29 ( V_69 ) ;
V_69 = F_95 ( V_7 ) ;
goto V_35;
}
static void F_136 ( struct V_68 * V_69 )
{
F_137 ( F_79 ( V_69 ) ) ;
F_29 ( V_69 ) ;
}
static inline struct V_135 * F_138 (
struct V_2 * V_3 )
{
unsigned long V_4 = F_2 ( F_3 ( V_3 ) ) ;
return ( void * ) F_4 ( ( V_5 * ) F_5 ( V_3 ) , V_4 + 1 ) ;
}
static int F_139 ( struct V_13 * V_122 , const V_5 * V_15 ,
unsigned int V_16 )
{
struct V_136 * V_18 = F_9 ( V_122 ) ;
struct V_13 * V_124 = V_18 -> V_124 ;
int V_7 ;
if ( V_16 < 4 )
return - V_38 ;
V_16 -= 4 ;
memcpy ( V_18 -> V_125 , V_15 + V_16 , 4 ) ;
F_112 ( V_124 , V_28 ) ;
F_14 ( V_124 , F_12 ( V_122 ) &
V_28 ) ;
V_7 = F_113 ( V_124 , V_15 , V_16 ) ;
F_14 ( V_122 , F_12 ( V_124 ) &
V_29 ) ;
return V_7 ;
}
static int F_140 ( struct V_13 * V_122 ,
unsigned int V_37 )
{
struct V_136 * V_18 = F_9 ( V_122 ) ;
if ( V_37 != 16 )
return - V_38 ;
return F_115 ( V_18 -> V_124 , V_37 ) ;
}
static void F_141 ( struct V_6 * V_62 , int V_7 )
{
struct V_2 * V_3 = V_62 -> V_10 ;
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_135 * V_137 = F_138 ( V_3 ) ;
if ( ! V_7 ) {
F_66 ( V_137 -> V_44 , V_3 -> V_42 ,
V_3 -> V_40 ,
F_67 ( V_14 ) , 1 ) ;
}
F_69 ( V_3 , V_7 ) ;
}
static struct V_2 * F_142 ( struct V_2 * V_3 ,
bool V_138 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_136 * V_18 = F_9 ( V_14 ) ;
struct V_135 * V_137 = F_138 ( V_3 ) ;
struct V_2 * V_126 = & V_137 -> V_126 ;
struct V_25 * V_45 = V_3 -> V_45 ;
struct V_25 * V_139 = V_137 -> V_139 ;
struct V_25 * V_140 = V_137 -> V_140 ;
struct V_25 * V_63 = V_137 -> V_63 ;
unsigned int V_37 = F_67 ( V_14 ) ;
unsigned int V_57 = V_3 -> V_57 ;
struct V_141 * V_142 ;
V_5 * V_143 ;
V_5 * V_24 = F_4 ( ( V_5 * ) ( V_137 + 1 ) + F_117 ( V_18 -> V_124 ) ,
F_2 ( V_18 -> V_124 ) + 1 ) ;
memcpy ( V_24 , V_18 -> V_125 , 4 ) ;
memcpy ( V_24 + 4 , V_3 -> V_24 , 8 ) ;
if ( V_138 )
memset ( V_137 -> V_44 , 0 , V_37 ) ;
else
F_66 ( V_137 -> V_44 , V_45 ,
V_3 -> V_40 - V_37 ,
V_37 , 0 ) ;
F_19 ( V_139 , V_137 -> V_44 , V_37 ) ;
V_142 = F_143 ( V_45 ) ;
V_143 = F_144 ( V_142 ) ? NULL : F_145 ( V_142 ) + V_45 -> V_144 ;
F_33 ( V_140 , 2 ) ;
F_34 ( V_140 , V_3 -> V_24 , 8 ) ;
F_146 ( V_140 , V_45 , V_143 == V_3 -> V_24 + 8 , 2 ) ;
V_57 += 8 + V_3 -> V_40 - ( V_138 ? 0 : V_37 ) ;
if ( V_3 -> V_63 -> V_145 == V_3 -> V_57 ) {
F_33 ( V_63 , 2 ) ;
F_147 ( V_63 , F_143 ( V_3 -> V_63 ) , V_3 -> V_63 -> V_145 ,
V_3 -> V_63 -> V_144 ) ;
} else {
F_53 ( V_3 -> V_57 > sizeof( V_137 -> V_146 ) ) ;
F_66 ( V_137 -> V_146 , V_3 -> V_63 , 0 ,
V_3 -> V_57 , 0 ) ;
F_33 ( V_63 , 2 ) ;
F_34 ( V_63 , V_137 -> V_146 , V_3 -> V_57 ) ;
}
F_146 ( V_63 , V_140 , 0 , 2 ) ;
F_118 ( V_126 , V_18 -> V_124 ) ;
F_119 ( V_126 , V_3 -> V_64 . V_127 , F_141 ,
V_3 ) ;
F_120 ( V_126 , V_139 , V_139 , V_138 ? 0 : V_37 , V_24 ) ;
F_121 ( V_126 , V_63 , V_57 ) ;
return V_126 ;
}
static int F_148 ( struct V_2 * V_3 , bool V_138 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_136 * V_18 = F_9 ( V_14 ) ;
unsigned int V_37 = F_67 ( V_14 ) ;
unsigned int V_147 = V_3 -> V_40 - ( V_138 ? 0 : V_37 ) ;
struct V_148 V_149 = {
. V_36 = V_18 -> null ,
} ;
return F_149 ( & V_149 , V_3 -> V_42 , V_3 -> V_45 , V_147 ) ;
}
static int F_150 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_3 ( V_3 ) ;
struct V_135 * V_137 = F_138 ( V_3 ) ;
struct V_2 * V_126 ;
int V_7 ;
if ( V_3 -> V_45 != V_3 -> V_42 ) {
V_7 = F_148 ( V_3 , true ) ;
if ( V_7 )
return V_7 ;
}
V_126 = F_142 ( V_3 , true ) ;
V_7 = F_123 ( V_126 ) ;
if ( V_7 )
return V_7 ;
F_66 ( V_137 -> V_44 , V_3 -> V_42 , V_3 -> V_40 ,
F_67 ( V_14 ) , 1 ) ;
return 0 ;
}
static int F_151 ( struct V_2 * V_3 )
{
int V_7 ;
if ( V_3 -> V_45 != V_3 -> V_42 ) {
V_7 = F_148 ( V_3 , false ) ;
if ( V_7 )
return V_7 ;
}
V_3 = F_142 ( V_3 , false ) ;
return F_125 ( V_3 ) ;
}
static int F_152 ( struct V_67 * V_36 )
{
struct V_68 * V_69 = ( void * ) V_36 -> V_70 ;
struct V_150 * V_72 = F_79 ( V_69 ) ;
struct V_128 * V_129 = & V_72 -> V_14 ;
struct V_136 * V_18 = F_62 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_151 * null ;
unsigned long V_4 ;
int V_7 = 0 ;
V_14 = F_127 ( V_129 ) ;
if ( F_81 ( V_14 ) )
return F_82 ( V_14 ) ;
null = F_153 ( & V_72 -> null . V_64 ) ;
V_7 = F_82 ( null ) ;
if ( F_81 ( null ) )
goto V_152;
V_18 -> V_124 = V_14 ;
V_18 -> null = null ;
V_4 = F_2 ( V_14 ) ;
V_4 &= ~ ( F_85 () - 1 ) ;
V_36 -> V_74 . V_75 = sizeof( struct V_135 ) +
F_128 ( F_117 ( V_14 ) ,
F_85 () ) +
V_4 + 16 ;
return 0 ;
V_152:
F_130 ( V_14 ) ;
return V_7 ;
}
static void F_154 ( struct V_67 * V_36 )
{
struct V_136 * V_18 = F_62 ( V_36 ) ;
F_130 ( V_18 -> V_124 ) ;
F_155 ( V_18 -> null ) ;
}
static struct V_68 * F_156 ( struct V_76 * * V_77 )
{
struct V_81 * V_82 ;
struct V_68 * V_69 ;
struct V_128 * V_129 ;
struct V_83 * V_101 ;
struct V_150 * V_18 ;
const char * V_130 ;
int V_7 ;
V_82 = F_93 ( V_77 ) ;
if ( F_81 ( V_82 ) )
return F_94 ( V_82 ) ;
if ( ( V_82 -> type ^ V_87 ) & V_82 -> V_88 )
return F_95 ( - V_38 ) ;
V_130 = F_108 ( V_77 [ 1 ] ) ;
if ( F_81 ( V_130 ) )
return F_94 ( V_130 ) ;
V_69 = F_16 ( sizeof( * V_69 ) + sizeof( * V_18 ) , V_30 ) ;
if ( ! V_69 )
return F_95 ( - V_31 ) ;
V_18 = F_79 ( V_69 ) ;
V_129 = & V_18 -> V_14 ;
F_132 ( V_129 , V_69 ) ;
V_7 = F_133 ( V_129 , V_130 , 0 ,
F_101 ( V_82 -> type , V_82 -> V_88 ) ) ;
if ( V_7 )
goto V_131;
V_101 = F_134 ( V_129 ) ;
F_99 ( & V_18 -> null , V_69 ) ;
V_7 = F_100 ( & V_18 -> null , L_7 , 0 ,
V_106 ) ;
if ( V_7 )
goto V_132;
F_102 ( & V_18 -> null ) ;
V_7 = - V_38 ;
if ( V_101 -> V_112 . V_97 != 16 )
goto V_153;
if ( V_101 -> V_99 != 1 )
goto V_153;
V_7 = - V_100 ;
if ( snprintf ( V_69 -> V_101 . V_104 , V_103 ,
L_8 , V_101 -> V_104 ) >= V_103 ||
snprintf ( V_69 -> V_101 . V_102 , V_103 ,
L_8 , V_101 -> V_102 ) >=
V_103 )
goto V_153;
V_69 -> V_101 . V_105 = V_87 ;
V_69 -> V_101 . V_105 |= V_101 -> V_105 & V_106 ;
V_69 -> V_101 . V_107 = V_101 -> V_107 ;
V_69 -> V_101 . V_99 = 1 ;
V_69 -> V_101 . V_108 = V_101 -> V_108 ;
V_69 -> V_101 . V_110 = & V_133 ;
V_69 -> V_101 . V_112 . V_97 = 8 ;
V_69 -> V_101 . V_112 . V_113 = 16 ;
V_69 -> V_101 . V_114 = sizeof( struct V_136 ) ;
V_69 -> V_101 . V_115 = F_152 ;
V_69 -> V_101 . V_116 = F_154 ;
V_69 -> V_101 . V_112 . V_117 = F_139 ;
V_69 -> V_101 . V_112 . V_118 = F_140 ;
V_69 -> V_101 . V_112 . V_119 = F_150 ;
V_69 -> V_101 . V_112 . V_120 = F_151 ;
V_69 -> V_101 . V_112 . V_134 = L_6 ;
V_35:
return V_69 ;
V_153:
F_105 ( & V_18 -> null ) ;
V_132:
F_135 ( V_129 ) ;
V_131:
F_29 ( V_69 ) ;
V_69 = F_95 ( V_7 ) ;
goto V_35;
}
static void F_157 ( struct V_68 * V_69 )
{
struct V_150 * V_18 = F_79 ( V_69 ) ;
F_135 ( & V_18 -> V_14 ) ;
F_105 ( & V_18 -> null ) ;
F_29 ( V_69 ) ;
}
static int T_5 F_158 ( void )
{
int V_7 ;
V_51 = F_16 ( 16 , V_30 ) ;
if ( ! V_51 )
return - V_31 ;
V_7 = F_159 ( & V_154 ) ;
if ( V_7 )
goto V_35;
V_7 = F_159 ( & V_155 ) ;
if ( V_7 )
goto V_156;
V_7 = F_159 ( & V_157 ) ;
if ( V_7 )
goto V_158;
V_7 = F_159 ( & V_159 ) ;
if ( V_7 )
goto V_160;
return 0 ;
V_160:
F_160 ( & V_157 ) ;
V_158:
F_160 ( & V_155 ) ;
V_156:
F_160 ( & V_154 ) ;
V_35:
F_29 ( V_51 ) ;
return V_7 ;
}
static void T_6 F_161 ( void )
{
F_29 ( V_51 ) ;
F_160 ( & V_159 ) ;
F_160 ( & V_157 ) ;
F_160 ( & V_155 ) ;
F_160 ( & V_154 ) ;
}
