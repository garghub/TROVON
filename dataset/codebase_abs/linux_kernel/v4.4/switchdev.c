void F_1 ( struct V_1 * V_2 ,
void * V_3 , void (* F_2)( void const * ) ,
struct V_4 * V_5 )
{
V_5 -> V_3 = V_3 ;
V_5 -> F_2 = F_2 ;
F_3 ( & V_5 -> V_6 , & V_2 -> V_7 ) ;
}
static struct V_4 *
F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( F_5 ( & V_2 -> V_7 ) )
return NULL ;
V_5 = F_6 ( & V_2 -> V_7 ,
struct V_4 , V_6 ) ;
F_7 ( & V_5 -> V_6 ) ;
return V_5 ;
}
void * F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_4 ( V_2 ) ;
F_9 ( ! V_5 ) ;
return V_5 -> V_3 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
while ( ( V_5 = F_4 ( V_2 ) ) )
V_5 -> F_2 ( V_5 -> V_3 ) ;
}
static void F_13 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
F_14 ( ! F_5 ( & V_2 -> V_7 ) , L_1 ,
V_9 -> V_10 ) ;
F_12 ( V_2 ) ;
}
static struct V_11 * F_15 ( void )
{
struct V_11 * V_12 ;
F_16 ( & V_13 ) ;
if ( F_5 ( & V_14 ) ) {
V_12 = NULL ;
goto V_15;
}
V_12 = F_6 ( & V_14 ,
struct V_11 , V_6 ) ;
F_7 ( & V_12 -> V_6 ) ;
V_15:
F_17 ( & V_13 ) ;
return V_12 ;
}
void F_18 ( void )
{
struct V_11 * V_12 ;
F_19 () ;
while ( ( V_12 = F_15 () ) ) {
V_12 -> V_16 ( V_12 -> V_9 , V_12 -> V_3 ) ;
F_20 ( V_12 -> V_9 ) ;
F_21 ( V_12 ) ;
}
}
static void F_22 ( struct V_17 * V_18 )
{
F_23 () ;
F_18 () ;
F_24 () ;
}
static int F_25 ( struct V_8 * V_9 ,
const void * V_3 , T_1 V_19 ,
T_2 * V_16 )
{
struct V_11 * V_12 ;
V_12 = F_26 ( sizeof( * V_12 ) + V_19 , V_20 ) ;
if ( ! V_12 )
return - V_21 ;
V_12 -> V_9 = V_9 ;
V_12 -> V_16 = V_16 ;
memcpy ( V_12 -> V_3 , V_3 , V_19 ) ;
F_27 ( V_9 ) ;
F_16 ( & V_13 ) ;
F_3 ( & V_12 -> V_6 , & V_14 ) ;
F_17 ( & V_13 ) ;
F_28 ( & V_22 ) ;
return 0 ;
}
int F_29 ( struct V_8 * V_9 , struct V_23 * V_24 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
struct V_23 V_30 = {
. V_31 = V_32
} ;
int V_33 = - V_34 ;
if ( V_26 && V_26 -> F_29 )
return V_26 -> F_29 ( V_9 , V_24 ) ;
if ( V_24 -> V_35 & V_36 )
return V_33 ;
F_30 (dev, lower_dev, iter) {
V_33 = F_29 ( V_27 , V_24 ) ;
if ( V_33 )
break;
if ( V_30 . V_31 == V_32 )
V_30 = * V_24 ;
else if ( memcmp ( & V_30 , V_24 , sizeof( * V_24 ) ) )
return - V_37 ;
}
return V_33 ;
}
static int F_31 ( struct V_8 * V_9 ,
const struct V_23 * V_24 ,
struct V_1 * V_2 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
int V_33 = - V_34 ;
if ( V_26 && V_26 -> V_38 ) {
V_33 = V_26 -> V_38 ( V_9 , V_24 , V_2 ) ;
goto V_39;
}
if ( V_24 -> V_35 & V_36 )
goto V_39;
F_30 (dev, lower_dev, iter) {
V_33 = F_31 ( V_27 , V_24 , V_2 ) ;
if ( V_33 )
break;
}
V_39:
if ( V_33 == - V_34 && V_24 -> V_35 & V_40 )
V_33 = 0 ;
return V_33 ;
}
static int F_32 ( struct V_8 * V_9 ,
const struct V_23 * V_24 )
{
struct V_1 V_2 ;
int V_33 ;
F_10 ( & V_2 ) ;
V_2 . V_41 = true ;
V_33 = F_31 ( V_9 , V_24 , & V_2 ) ;
if ( V_33 ) {
if ( V_33 != - V_34 )
F_12 ( & V_2 ) ;
return V_33 ;
}
V_2 . V_41 = false ;
V_33 = F_31 ( V_9 , V_24 , & V_2 ) ;
F_14 ( V_33 , L_2 ,
V_9 -> V_10 , V_24 -> V_31 ) ;
F_13 ( V_9 , & V_2 ) ;
return V_33 ;
}
static void F_33 ( struct V_8 * V_9 ,
const void * V_3 )
{
const struct V_23 * V_24 = V_3 ;
int V_33 ;
V_33 = F_32 ( V_9 , V_24 ) ;
if ( V_33 && V_33 != - V_34 )
F_34 ( V_9 , L_3 ,
V_33 , V_24 -> V_31 ) ;
}
static int F_35 ( struct V_8 * V_9 ,
const struct V_23 * V_24 )
{
return F_25 ( V_9 , V_24 , sizeof( * V_24 ) ,
F_33 ) ;
}
int V_38 ( struct V_8 * V_9 ,
const struct V_23 * V_24 )
{
if ( V_24 -> V_35 & V_42 )
return F_35 ( V_9 , V_24 ) ;
F_19 () ;
return F_32 ( V_9 , V_24 ) ;
}
static T_1 F_36 ( const struct V_43 * V_44 )
{
switch ( V_44 -> V_31 ) {
case V_45 :
return sizeof( struct V_46 ) ;
case V_47 :
return sizeof( struct V_48 ) ;
case V_49 :
return sizeof( struct V_50 ) ;
default:
F_37 () ;
}
return 0 ;
}
static int F_38 ( struct V_8 * V_9 ,
const struct V_43 * V_44 ,
struct V_1 * V_2 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
int V_33 = - V_34 ;
if ( V_26 && V_26 -> V_51 )
return V_26 -> V_51 ( V_9 , V_44 , V_2 ) ;
F_30 (dev, lower_dev, iter) {
V_33 = F_38 ( V_27 , V_44 , V_2 ) ;
if ( V_33 )
break;
}
return V_33 ;
}
static int F_39 ( struct V_8 * V_9 ,
const struct V_43 * V_44 )
{
struct V_1 V_2 ;
int V_33 ;
F_19 () ;
F_10 ( & V_2 ) ;
V_2 . V_41 = true ;
V_33 = F_38 ( V_9 , V_44 , & V_2 ) ;
if ( V_33 ) {
if ( V_33 != - V_34 )
F_12 ( & V_2 ) ;
return V_33 ;
}
V_2 . V_41 = false ;
V_33 = F_38 ( V_9 , V_44 , & V_2 ) ;
F_14 ( V_33 , L_4 , V_9 -> V_10 , V_44 -> V_31 ) ;
F_13 ( V_9 , & V_2 ) ;
return V_33 ;
}
static void F_40 ( struct V_8 * V_9 ,
const void * V_3 )
{
const struct V_43 * V_44 = V_3 ;
int V_33 ;
V_33 = F_39 ( V_9 , V_44 ) ;
if ( V_33 && V_33 != - V_34 )
F_34 ( V_9 , L_5 ,
V_33 , V_44 -> V_31 ) ;
}
static int F_41 ( struct V_8 * V_9 ,
const struct V_43 * V_44 )
{
return F_25 ( V_9 , V_44 , F_36 ( V_44 ) ,
F_40 ) ;
}
int V_51 ( struct V_8 * V_9 ,
const struct V_43 * V_44 )
{
if ( V_44 -> V_35 & V_42 )
return F_41 ( V_9 , V_44 ) ;
F_19 () ;
return F_39 ( V_9 , V_44 ) ;
}
static int F_42 ( struct V_8 * V_9 ,
const struct V_43 * V_44 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
int V_33 = - V_34 ;
if ( V_26 && V_26 -> V_52 )
return V_26 -> V_52 ( V_9 , V_44 ) ;
F_30 (dev, lower_dev, iter) {
V_33 = F_42 ( V_27 , V_44 ) ;
if ( V_33 )
break;
}
return V_33 ;
}
static void F_43 ( struct V_8 * V_9 ,
const void * V_3 )
{
const struct V_43 * V_44 = V_3 ;
int V_33 ;
V_33 = F_42 ( V_9 , V_44 ) ;
if ( V_33 && V_33 != - V_34 )
F_34 ( V_9 , L_6 ,
V_33 , V_44 -> V_31 ) ;
}
static int F_44 ( struct V_8 * V_9 ,
const struct V_43 * V_44 )
{
return F_25 ( V_9 , V_44 , F_36 ( V_44 ) ,
F_43 ) ;
}
int V_52 ( struct V_8 * V_9 ,
const struct V_43 * V_44 )
{
if ( V_44 -> V_35 & V_42 )
return F_44 ( V_9 , V_44 ) ;
F_19 () ;
return F_42 ( V_9 , V_44 ) ;
}
int F_45 ( struct V_8 * V_9 , struct V_43 * V_44 ,
T_3 * V_53 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
int V_33 = - V_34 ;
F_19 () ;
if ( V_26 && V_26 -> F_45 )
return V_26 -> F_45 ( V_9 , V_44 , V_53 ) ;
F_30 (dev, lower_dev, iter) {
V_33 = F_45 ( V_27 , V_44 , V_53 ) ;
break;
}
return V_33 ;
}
int F_46 ( struct V_54 * V_55 )
{
int V_33 ;
F_47 ( & V_56 ) ;
V_33 = F_48 ( & V_57 , V_55 ) ;
F_49 ( & V_56 ) ;
return V_33 ;
}
int F_50 ( struct V_54 * V_55 )
{
int V_33 ;
F_47 ( & V_56 ) ;
V_33 = F_51 ( & V_57 , V_55 ) ;
F_49 ( & V_56 ) ;
return V_33 ;
}
int F_52 ( unsigned long V_58 , struct V_8 * V_9 ,
struct V_59 * V_60 )
{
int V_33 ;
V_60 -> V_9 = V_9 ;
F_47 ( & V_56 ) ;
V_33 = F_53 ( & V_57 , V_58 , V_60 ) ;
F_49 ( & V_56 ) ;
return V_33 ;
}
static int F_54 ( struct V_61 * V_62 )
{
struct V_63 V_64 ;
V_64 . V_35 = V_62 -> V_35 ;
if ( V_62 -> V_65 == 0 && V_62 -> V_66 == 0 ) {
return 0 ;
} else if ( V_62 -> V_65 == V_62 -> V_66 ) {
V_64 . V_67 = V_62 -> V_65 ;
if ( F_55 ( V_62 -> V_68 , V_69 ,
sizeof( V_64 ) , & V_64 ) )
return - V_70 ;
} else {
V_64 . V_67 = V_62 -> V_65 ;
V_64 . V_35 |= V_71 ;
if ( F_55 ( V_62 -> V_68 , V_69 ,
sizeof( V_64 ) , & V_64 ) )
return - V_70 ;
V_64 . V_67 = V_62 -> V_66 ;
V_64 . V_35 &= ~ V_71 ;
V_64 . V_35 |= V_72 ;
if ( F_55 ( V_62 -> V_68 , V_69 ,
sizeof( V_64 ) , & V_64 ) )
return - V_70 ;
}
return 0 ;
}
static int F_56 ( struct V_43 * V_44 )
{
struct V_46 * V_73 = F_57 ( V_44 ) ;
struct V_61 * V_62 =
F_58 ( V_73 , struct V_61 , V_73 ) ;
int V_33 = 0 ;
if ( V_73 -> V_74 > V_73 -> V_75 )
return - V_76 ;
if ( V_62 -> V_77 & V_78 ) {
V_62 -> V_35 = V_73 -> V_35 ;
for ( V_62 -> V_65 = V_62 -> V_66 = V_73 -> V_74 ;
V_62 -> V_65 <= V_73 -> V_75 ;
V_62 -> V_65 ++ , V_62 -> V_66 ++ ) {
V_33 = F_54 ( V_62 ) ;
if ( V_33 )
return V_33 ;
}
} else if ( V_62 -> V_77 & V_79 ) {
if ( V_62 -> V_65 > V_73 -> V_74 &&
V_62 -> V_65 >= V_73 -> V_75 ) {
if ( ( V_62 -> V_65 - 1 ) == V_73 -> V_75 &&
V_62 -> V_35 == V_73 -> V_35 ) {
V_62 -> V_65 = V_73 -> V_74 ;
} else {
V_33 = F_54 ( V_62 ) ;
V_62 -> V_35 = V_73 -> V_35 ;
V_62 -> V_65 = V_73 -> V_74 ;
V_62 -> V_66 = V_73 -> V_75 ;
}
} else if ( V_62 -> V_66 <= V_73 -> V_74 &&
V_62 -> V_66 < V_73 -> V_75 ) {
if ( ( V_62 -> V_66 + 1 ) == V_73 -> V_74 &&
V_62 -> V_35 == V_73 -> V_35 ) {
V_62 -> V_66 = V_73 -> V_75 ;
} else {
V_33 = F_54 ( V_62 ) ;
V_62 -> V_35 = V_73 -> V_35 ;
V_62 -> V_65 = V_73 -> V_74 ;
V_62 -> V_66 = V_73 -> V_75 ;
}
} else {
V_33 = - V_76 ;
}
}
return V_33 ;
}
static int F_59 ( struct V_80 * V_68 , struct V_8 * V_9 ,
T_4 V_77 )
{
struct V_61 V_62 = {
. V_73 . V_44 . V_31 = V_45 ,
. V_68 = V_68 ,
. V_77 = V_77 ,
} ;
int V_33 = 0 ;
if ( ( V_77 & V_78 ) ||
( V_77 & V_79 ) ) {
V_33 = F_45 ( V_9 , & V_62 . V_73 . V_44 ,
F_56 ) ;
if ( V_33 )
goto V_81;
if ( V_77 & V_79 )
V_33 = F_54 ( & V_62 ) ;
}
V_81:
return V_33 == - V_34 ? 0 : V_33 ;
}
int F_60 ( struct V_80 * V_68 , T_4 V_82 , T_4 V_83 ,
struct V_8 * V_9 , T_4 V_77 ,
int V_84 )
{
struct V_23 V_24 = {
. V_31 = V_85 ,
} ;
T_5 V_86 = V_87 ;
T_4 V_88 = V_89 | V_90 | V_91 ;
int V_33 ;
V_33 = F_29 ( V_9 , & V_24 ) ;
if ( V_33 && V_33 != - V_34 )
return V_33 ;
return F_61 ( V_68 , V_82 , V_83 , V_9 , V_86 ,
V_24 . V_92 . V_93 , V_88 , V_84 ,
V_77 , F_59 ) ;
}
static int F_62 ( struct V_8 * V_9 ,
struct V_94 * V_94 ,
unsigned long V_95 )
{
struct V_23 V_24 = {
. V_31 = V_85 ,
} ;
T_6 V_96 = F_63 ( V_94 ) ;
int V_33 ;
V_33 = F_29 ( V_9 , & V_24 ) ;
if ( V_33 )
return V_33 ;
if ( V_96 )
V_24 . V_92 . V_93 |= V_95 ;
else
V_24 . V_92 . V_93 &= ~ V_95 ;
return V_38 ( V_9 , & V_24 ) ;
}
static int F_64 ( struct V_8 * V_9 ,
struct V_94 * V_97 )
{
struct V_94 * V_24 ;
int V_98 ;
int V_33 ;
V_33 = F_65 ( V_97 , V_99 ,
V_100 ) ;
if ( V_33 )
return V_33 ;
F_66 (attr, protinfo, rem) {
switch ( F_67 ( V_24 ) ) {
case V_101 :
V_33 = F_62 ( V_9 , V_24 ,
V_89 ) ;
break;
case V_102 :
V_33 = F_62 ( V_9 , V_24 ,
V_90 ) ;
break;
case V_103 :
V_33 = F_62 ( V_9 , V_24 , V_91 ) ;
break;
default:
V_33 = - V_34 ;
break;
}
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int F_68 ( struct V_8 * V_9 ,
struct V_94 * V_104 ,
int (* F_69)( struct V_8 * V_9 ,
const struct V_43 * V_44 ) )
{
struct V_94 * V_24 ;
struct V_63 * V_64 ;
struct V_46 V_73 = {
. V_44 . V_31 = V_45 ,
} ;
int V_98 ;
int V_33 ;
F_66 (attr, afspec, rem) {
if ( F_67 ( V_24 ) != V_69 )
continue;
if ( F_70 ( V_24 ) != sizeof( struct V_63 ) )
return - V_76 ;
V_64 = F_71 ( V_24 ) ;
if ( ! V_64 -> V_67 || V_64 -> V_67 >= V_105 )
return - V_76 ;
V_73 . V_35 = V_64 -> V_35 ;
if ( V_64 -> V_35 & V_71 ) {
if ( V_73 . V_74 )
return - V_76 ;
V_73 . V_74 = V_64 -> V_67 ;
if ( V_73 . V_35 & V_106 )
return - V_76 ;
} else if ( V_64 -> V_35 & V_72 ) {
if ( ! V_73 . V_74 )
return - V_76 ;
V_73 . V_75 = V_64 -> V_67 ;
if ( V_73 . V_75 <= V_73 . V_74 )
return - V_76 ;
V_33 = F_69 ( V_9 , & V_73 . V_44 ) ;
if ( V_33 )
return V_33 ;
V_73 . V_74 = 0 ;
} else {
if ( V_73 . V_74 )
return - V_76 ;
V_73 . V_74 = V_64 -> V_67 ;
V_73 . V_75 = V_64 -> V_67 ;
V_33 = F_69 ( V_9 , & V_73 . V_44 ) ;
if ( V_33 )
return V_33 ;
V_73 . V_74 = 0 ;
}
}
return 0 ;
}
int F_72 ( struct V_8 * V_9 ,
struct V_107 * V_108 , T_5 V_35 )
{
struct V_94 * V_97 ;
struct V_94 * V_104 ;
int V_33 = 0 ;
V_97 = F_73 ( V_108 , sizeof( struct V_109 ) ,
V_110 ) ;
if ( V_97 ) {
V_33 = F_64 ( V_9 , V_97 ) ;
if ( V_33 )
return V_33 ;
}
V_104 = F_73 ( V_108 , sizeof( struct V_109 ) ,
V_111 ) ;
if ( V_104 )
V_33 = F_68 ( V_9 , V_104 ,
V_51 ) ;
return V_33 ;
}
int F_74 ( struct V_8 * V_9 ,
struct V_107 * V_108 , T_5 V_35 )
{
struct V_94 * V_104 ;
V_104 = F_73 ( V_108 , sizeof( struct V_109 ) ,
V_111 ) ;
if ( V_104 )
return F_68 ( V_9 , V_104 ,
V_52 ) ;
return 0 ;
}
int F_75 ( struct V_112 * V_113 , struct V_94 * V_114 [] ,
struct V_8 * V_9 , const unsigned char * V_115 ,
T_5 V_67 , T_5 V_116 )
{
struct V_50 V_117 = {
. V_44 . V_31 = V_49 ,
. V_67 = V_67 ,
} ;
F_76 ( V_117 . V_115 , V_115 ) ;
return V_51 ( V_9 , & V_117 . V_44 ) ;
}
int F_77 ( struct V_112 * V_113 , struct V_94 * V_114 [] ,
struct V_8 * V_9 , const unsigned char * V_115 ,
T_5 V_67 )
{
struct V_50 V_117 = {
. V_44 . V_31 = V_49 ,
. V_67 = V_67 ,
} ;
F_76 ( V_117 . V_115 , V_115 ) ;
return V_52 ( V_9 , & V_117 . V_44 ) ;
}
static int F_78 ( struct V_43 * V_44 )
{
struct V_50 * V_117 = F_79 ( V_44 ) ;
struct V_118 * V_62 =
F_58 ( V_117 , struct V_118 , V_117 ) ;
T_4 V_119 = F_80 ( V_62 -> V_53 -> V_68 ) . V_119 ;
T_4 V_83 = V_62 -> V_53 -> V_108 -> V_120 ;
struct V_107 * V_108 ;
struct V_112 * V_113 ;
if ( V_62 -> V_121 < V_62 -> V_53 -> args [ 0 ] )
goto V_122;
V_108 = F_81 ( V_62 -> V_68 , V_119 , V_83 , V_123 ,
sizeof( * V_113 ) , V_124 ) ;
if ( ! V_108 )
return - V_70 ;
V_113 = F_82 ( V_108 ) ;
V_113 -> V_125 = V_126 ;
V_113 -> V_127 = 0 ;
V_113 -> V_128 = 0 ;
V_113 -> V_129 = V_130 ;
V_113 -> V_131 = 0 ;
V_113 -> V_132 = V_62 -> V_9 -> V_133 ;
V_113 -> V_134 = V_117 -> V_134 ;
if ( F_55 ( V_62 -> V_68 , V_135 , V_136 , V_117 -> V_115 ) )
goto V_137;
if ( V_117 -> V_67 && F_83 ( V_62 -> V_68 , V_138 , V_117 -> V_67 ) )
goto V_137;
F_84 ( V_62 -> V_68 , V_108 ) ;
V_122:
V_62 -> V_121 ++ ;
return 0 ;
V_137:
F_85 ( V_62 -> V_68 , V_108 ) ;
return - V_70 ;
}
int F_86 ( struct V_80 * V_68 , struct V_139 * V_53 ,
struct V_8 * V_9 ,
struct V_8 * V_140 , int V_121 )
{
struct V_118 V_62 = {
. V_117 . V_44 . V_31 = V_49 ,
. V_9 = V_9 ,
. V_68 = V_68 ,
. V_53 = V_53 ,
. V_121 = V_121 ,
} ;
F_45 ( V_9 , & V_62 . V_117 . V_44 , F_78 ) ;
return V_62 . V_121 ;
}
static struct V_8 * F_87 ( struct V_8 * V_9 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_8 * V_141 ;
struct V_28 * V_29 ;
if ( V_26 && V_26 -> F_29 )
return V_9 ;
F_30 (dev, lower_dev, iter) {
V_141 = F_87 ( V_27 ) ;
if ( V_141 )
return V_141 ;
}
return NULL ;
}
static struct V_8 * F_88 ( struct V_142 * V_143 )
{
struct V_23 V_24 = {
. V_31 = V_144 ,
} ;
struct V_23 V_145 ;
struct V_8 * V_9 = NULL ;
int V_146 ;
F_19 () ;
for ( V_146 = 0 ; V_146 < V_143 -> V_147 ; V_146 ++ ) {
const struct V_148 * V_149 = & V_143 -> V_148 [ V_146 ] ;
if ( ! V_149 -> V_150 )
return NULL ;
V_9 = F_87 ( V_149 -> V_150 ) ;
if ( ! V_9 )
return NULL ;
if ( F_29 ( V_9 , & V_24 ) )
return NULL ;
if ( V_146 > 0 &&
! F_89 ( & V_145 . V_92 . V_151 , & V_24 . V_92 . V_151 ) )
return NULL ;
V_145 = V_24 ;
}
return V_9 ;
}
int F_90 ( T_4 V_152 , int V_153 , struct V_142 * V_143 ,
T_6 V_154 , T_6 type , T_4 V_84 , T_4 V_155 )
{
struct V_48 V_156 = {
. V_44 . V_31 = V_47 ,
. V_152 = V_152 ,
. V_153 = V_153 ,
. V_154 = V_154 ,
. type = type ,
. V_84 = V_84 ,
. V_155 = V_155 ,
} ;
struct V_8 * V_9 ;
int V_33 = 0 ;
memcpy ( & V_156 . V_143 , V_143 , sizeof( V_156 . V_143 ) ) ;
#ifdef F_91
if ( V_143 -> V_157 -> V_158 . V_159 )
return 0 ;
#endif
if ( V_143 -> V_157 -> V_158 . V_160 )
return 0 ;
V_9 = F_88 ( V_143 ) ;
if ( ! V_9 )
return 0 ;
V_33 = V_51 ( V_9 , & V_156 . V_44 ) ;
if ( ! V_33 )
V_143 -> V_161 |= V_162 ;
return V_33 == - V_34 ? 0 : V_33 ;
}
int F_92 ( T_4 V_152 , int V_153 , struct V_142 * V_143 ,
T_6 V_154 , T_6 type , T_4 V_155 )
{
struct V_48 V_156 = {
. V_44 . V_31 = V_47 ,
. V_152 = V_152 ,
. V_153 = V_153 ,
. V_154 = V_154 ,
. type = type ,
. V_84 = 0 ,
. V_155 = V_155 ,
} ;
struct V_8 * V_9 ;
int V_33 = 0 ;
memcpy ( & V_156 . V_143 , V_143 , sizeof( V_156 . V_143 ) ) ;
if ( ! ( V_143 -> V_161 & V_162 ) )
return 0 ;
V_9 = F_88 ( V_143 ) ;
if ( ! V_9 )
return 0 ;
V_33 = V_52 ( V_9 , & V_156 . V_44 ) ;
if ( ! V_33 )
V_143 -> V_161 &= ~ V_162 ;
return V_33 == - V_34 ? 0 : V_33 ;
}
void F_93 ( struct V_142 * V_143 )
{
F_94 ( V_143 -> V_157 ) ;
V_143 -> V_157 -> V_158 . V_160 = true ;
}
static bool F_95 ( struct V_8 * V_163 ,
struct V_8 * V_164 )
{
struct V_23 V_165 = {
. V_31 = V_144 ,
. V_35 = V_36 ,
} ;
struct V_23 V_166 = {
. V_31 = V_144 ,
. V_35 = V_36 ,
} ;
if ( F_29 ( V_163 , & V_165 ) ||
F_29 ( V_164 , & V_166 ) )
return false ;
return F_89 ( & V_165 . V_92 . V_151 , & V_166 . V_92 . V_151 ) ;
}
static T_4 F_96 ( struct V_8 * V_9 ,
struct V_8 * V_167 )
{
struct V_8 * V_27 ;
struct V_28 * V_29 ;
F_30 (group_dev, lower_dev, iter) {
if ( V_27 == V_9 )
continue;
if ( F_95 ( V_9 , V_27 ) )
return V_27 -> V_168 ;
return F_96 ( V_9 , V_27 ) ;
}
return V_9 -> V_133 ;
}
static void F_97 ( struct V_8 * V_167 ,
T_4 V_169 , T_4 * V_170 )
{
struct V_8 * V_27 ;
struct V_28 * V_29 ;
F_30 (group_dev, lower_dev, iter) {
if ( V_27 -> V_168 == V_169 ) {
if ( ! * V_170 )
* V_170 = V_27 -> V_133 ;
V_27 -> V_168 = * V_170 ;
}
F_97 ( V_27 , V_169 , V_170 ) ;
}
}
void F_98 ( struct V_8 * V_9 ,
struct V_8 * V_167 ,
bool V_171 )
{
T_4 V_172 = V_9 -> V_133 ;
T_4 V_170 = 0 ;
if ( V_167 ) {
F_19 () ;
if ( V_171 )
V_172 = F_96 ( V_9 , V_167 ) ;
else if ( V_9 -> V_168 == V_172 )
F_97 ( V_167 , V_172 ,
& V_170 ) ;
}
V_9 -> V_168 = V_172 ;
}
