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
if ( V_24 -> V_42 )
V_24 -> V_42 ( V_9 , V_33 , V_24 -> V_43 ) ;
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
if ( V_24 -> V_35 & V_44 )
return F_35 ( V_9 , V_24 ) ;
F_19 () ;
return F_32 ( V_9 , V_24 ) ;
}
static T_1 F_36 ( const struct V_45 * V_46 )
{
switch ( V_46 -> V_31 ) {
case V_47 :
return sizeof( struct V_48 ) ;
case V_49 :
return sizeof( struct V_50 ) ;
case V_51 :
return sizeof( struct V_52 ) ;
default:
F_37 () ;
}
return 0 ;
}
static int F_38 ( struct V_8 * V_9 ,
const struct V_45 * V_46 ,
struct V_1 * V_2 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
int V_33 = - V_34 ;
if ( V_26 && V_26 -> V_53 )
return V_26 -> V_53 ( V_9 , V_46 , V_2 ) ;
F_30 (dev, lower_dev, iter) {
V_33 = F_38 ( V_27 , V_46 , V_2 ) ;
if ( V_33 )
break;
}
return V_33 ;
}
static int F_39 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
struct V_1 V_2 ;
int V_33 ;
F_19 () ;
F_10 ( & V_2 ) ;
V_2 . V_41 = true ;
V_33 = F_38 ( V_9 , V_46 , & V_2 ) ;
if ( V_33 ) {
if ( V_33 != - V_34 )
F_12 ( & V_2 ) ;
return V_33 ;
}
V_2 . V_41 = false ;
V_33 = F_38 ( V_9 , V_46 , & V_2 ) ;
F_14 ( V_33 , L_4 , V_9 -> V_10 , V_46 -> V_31 ) ;
F_13 ( V_9 , & V_2 ) ;
return V_33 ;
}
static void F_40 ( struct V_8 * V_9 ,
const void * V_3 )
{
const struct V_45 * V_46 = V_3 ;
int V_33 ;
V_33 = F_39 ( V_9 , V_46 ) ;
if ( V_33 && V_33 != - V_34 )
F_34 ( V_9 , L_5 ,
V_33 , V_46 -> V_31 ) ;
if ( V_46 -> V_42 )
V_46 -> V_42 ( V_9 , V_33 , V_46 -> V_43 ) ;
}
static int F_41 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
return F_25 ( V_9 , V_46 , F_36 ( V_46 ) ,
F_40 ) ;
}
int V_53 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
if ( V_46 -> V_35 & V_44 )
return F_41 ( V_9 , V_46 ) ;
F_19 () ;
return F_39 ( V_9 , V_46 ) ;
}
static int F_42 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
int V_33 = - V_34 ;
if ( V_26 && V_26 -> V_54 )
return V_26 -> V_54 ( V_9 , V_46 ) ;
F_30 (dev, lower_dev, iter) {
V_33 = F_42 ( V_27 , V_46 ) ;
if ( V_33 )
break;
}
return V_33 ;
}
static void F_43 ( struct V_8 * V_9 ,
const void * V_3 )
{
const struct V_45 * V_46 = V_3 ;
int V_33 ;
V_33 = F_42 ( V_9 , V_46 ) ;
if ( V_33 && V_33 != - V_34 )
F_34 ( V_9 , L_6 ,
V_33 , V_46 -> V_31 ) ;
if ( V_46 -> V_42 )
V_46 -> V_42 ( V_9 , V_33 , V_46 -> V_43 ) ;
}
static int F_44 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
return F_25 ( V_9 , V_46 , F_36 ( V_46 ) ,
F_43 ) ;
}
int V_54 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
if ( V_46 -> V_35 & V_44 )
return F_44 ( V_9 , V_46 ) ;
F_19 () ;
return F_42 ( V_9 , V_46 ) ;
}
int F_45 ( struct V_8 * V_9 , struct V_45 * V_46 ,
T_3 * V_55 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
int V_33 = - V_34 ;
F_19 () ;
if ( V_26 && V_26 -> F_45 )
return V_26 -> F_45 ( V_9 , V_46 , V_55 ) ;
F_30 (dev, lower_dev, iter) {
V_33 = F_45 ( V_27 , V_46 , V_55 ) ;
break;
}
return V_33 ;
}
int F_46 ( struct V_56 * V_57 )
{
return F_47 ( & V_58 , V_57 ) ;
}
int F_48 ( struct V_56 * V_57 )
{
return F_49 ( & V_58 , V_57 ) ;
}
int F_50 ( unsigned long V_59 , struct V_8 * V_9 ,
struct V_60 * V_61 )
{
V_61 -> V_9 = V_9 ;
return F_51 ( & V_58 , V_59 , V_61 ) ;
}
static int F_52 ( struct V_62 * V_63 )
{
struct V_64 V_65 ;
V_65 . V_35 = V_63 -> V_35 ;
if ( V_63 -> V_66 == 0 && V_63 -> V_67 == 0 ) {
return 0 ;
} else if ( V_63 -> V_66 == V_63 -> V_67 ) {
V_65 . V_68 = V_63 -> V_66 ;
if ( F_53 ( V_63 -> V_69 , V_70 ,
sizeof( V_65 ) , & V_65 ) )
return - V_71 ;
} else {
V_65 . V_68 = V_63 -> V_66 ;
V_65 . V_35 |= V_72 ;
if ( F_53 ( V_63 -> V_69 , V_70 ,
sizeof( V_65 ) , & V_65 ) )
return - V_71 ;
V_65 . V_68 = V_63 -> V_67 ;
V_65 . V_35 &= ~ V_72 ;
V_65 . V_35 |= V_73 ;
if ( F_53 ( V_63 -> V_69 , V_70 ,
sizeof( V_65 ) , & V_65 ) )
return - V_71 ;
}
return 0 ;
}
static int F_54 ( struct V_45 * V_46 )
{
struct V_48 * V_74 = F_55 ( V_46 ) ;
struct V_62 * V_63 =
F_56 ( V_74 , struct V_62 , V_74 ) ;
int V_33 = 0 ;
if ( V_74 -> V_75 > V_74 -> V_76 )
return - V_77 ;
if ( V_63 -> V_78 & V_79 ) {
V_63 -> V_35 = V_74 -> V_35 ;
for ( V_63 -> V_66 = V_63 -> V_67 = V_74 -> V_75 ;
V_63 -> V_66 <= V_74 -> V_76 ;
V_63 -> V_66 ++ , V_63 -> V_67 ++ ) {
V_33 = F_52 ( V_63 ) ;
if ( V_33 )
return V_33 ;
}
} else if ( V_63 -> V_78 & V_80 ) {
if ( V_63 -> V_66 > V_74 -> V_75 &&
V_63 -> V_66 >= V_74 -> V_76 ) {
if ( ( V_63 -> V_66 - 1 ) == V_74 -> V_76 &&
V_63 -> V_35 == V_74 -> V_35 ) {
V_63 -> V_66 = V_74 -> V_75 ;
} else {
V_33 = F_52 ( V_63 ) ;
V_63 -> V_35 = V_74 -> V_35 ;
V_63 -> V_66 = V_74 -> V_75 ;
V_63 -> V_67 = V_74 -> V_76 ;
}
} else if ( V_63 -> V_67 <= V_74 -> V_75 &&
V_63 -> V_67 < V_74 -> V_76 ) {
if ( ( V_63 -> V_67 + 1 ) == V_74 -> V_75 &&
V_63 -> V_35 == V_74 -> V_35 ) {
V_63 -> V_67 = V_74 -> V_76 ;
} else {
V_33 = F_52 ( V_63 ) ;
V_63 -> V_35 = V_74 -> V_35 ;
V_63 -> V_66 = V_74 -> V_75 ;
V_63 -> V_67 = V_74 -> V_76 ;
}
} else {
V_33 = - V_77 ;
}
}
return V_33 ;
}
static int F_57 ( struct V_81 * V_69 , struct V_8 * V_9 ,
T_4 V_78 )
{
struct V_62 V_63 = {
. V_74 . V_46 . V_82 = V_9 ,
. V_74 . V_46 . V_31 = V_47 ,
. V_69 = V_69 ,
. V_78 = V_78 ,
} ;
int V_33 = 0 ;
if ( ( V_78 & V_79 ) ||
( V_78 & V_80 ) ) {
V_33 = F_45 ( V_9 , & V_63 . V_74 . V_46 ,
F_54 ) ;
if ( V_33 )
goto V_83;
if ( V_78 & V_80 )
V_33 = F_52 ( & V_63 ) ;
}
V_83:
return V_33 == - V_34 ? 0 : V_33 ;
}
int F_58 ( struct V_81 * V_69 , T_4 V_84 , T_4 V_85 ,
struct V_8 * V_9 , T_4 V_78 ,
int V_86 )
{
struct V_23 V_24 = {
. V_82 = V_9 ,
. V_31 = V_87 ,
} ;
T_5 V_88 = V_89 ;
T_4 V_90 = V_91 | V_92 | V_93 ;
int V_33 ;
if ( ! F_59 ( V_9 ) )
return - V_34 ;
V_33 = F_29 ( V_9 , & V_24 ) ;
if ( V_33 && V_33 != - V_34 )
return V_33 ;
return F_60 ( V_69 , V_84 , V_85 , V_9 , V_88 ,
V_24 . V_94 . V_95 , V_90 , V_86 ,
V_78 , F_57 ) ;
}
static int F_61 ( struct V_8 * V_9 ,
struct V_96 * V_96 ,
unsigned long V_97 )
{
struct V_23 V_24 = {
. V_82 = V_9 ,
. V_31 = V_87 ,
} ;
T_6 V_98 = F_62 ( V_96 ) ;
int V_33 ;
V_33 = F_29 ( V_9 , & V_24 ) ;
if ( V_33 )
return V_33 ;
if ( V_98 )
V_24 . V_94 . V_95 |= V_97 ;
else
V_24 . V_94 . V_95 &= ~ V_97 ;
return V_38 ( V_9 , & V_24 ) ;
}
static int F_63 ( struct V_8 * V_9 ,
struct V_96 * V_99 )
{
struct V_96 * V_24 ;
int V_100 ;
int V_33 ;
V_33 = F_64 ( V_99 , V_101 ,
V_102 , NULL ) ;
if ( V_33 )
return V_33 ;
F_65 (attr, protinfo, rem) {
switch ( F_66 ( V_24 ) ) {
case V_103 :
V_33 = F_61 ( V_9 , V_24 ,
V_91 ) ;
break;
case V_104 :
V_33 = F_61 ( V_9 , V_24 ,
V_92 ) ;
break;
case V_105 :
V_33 = F_61 ( V_9 , V_24 , V_93 ) ;
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
static int F_67 ( struct V_8 * V_9 ,
struct V_96 * V_106 ,
int (* F_68)( struct V_8 * V_9 ,
const struct V_45 * V_46 ) )
{
struct V_96 * V_24 ;
struct V_64 * V_65 ;
struct V_48 V_74 = {
. V_46 . V_82 = V_9 ,
. V_46 . V_31 = V_47 ,
} ;
int V_100 ;
int V_33 ;
F_65 (attr, afspec, rem) {
if ( F_66 ( V_24 ) != V_70 )
continue;
if ( F_69 ( V_24 ) != sizeof( struct V_64 ) )
return - V_77 ;
V_65 = F_70 ( V_24 ) ;
if ( ! V_65 -> V_68 || V_65 -> V_68 >= V_107 )
return - V_77 ;
V_74 . V_35 = V_65 -> V_35 ;
if ( V_65 -> V_35 & V_72 ) {
if ( V_74 . V_75 )
return - V_77 ;
V_74 . V_75 = V_65 -> V_68 ;
if ( V_74 . V_35 & V_108 )
return - V_77 ;
} else if ( V_65 -> V_35 & V_73 ) {
if ( ! V_74 . V_75 )
return - V_77 ;
V_74 . V_76 = V_65 -> V_68 ;
if ( V_74 . V_76 <= V_74 . V_75 )
return - V_77 ;
V_33 = F_68 ( V_9 , & V_74 . V_46 ) ;
if ( V_33 )
return V_33 ;
V_74 . V_75 = 0 ;
} else {
if ( V_74 . V_75 )
return - V_77 ;
V_74 . V_75 = V_65 -> V_68 ;
V_74 . V_76 = V_65 -> V_68 ;
V_33 = F_68 ( V_9 , & V_74 . V_46 ) ;
if ( V_33 )
return V_33 ;
V_74 . V_75 = 0 ;
}
}
return 0 ;
}
int F_71 ( struct V_8 * V_9 ,
struct V_109 * V_110 , T_5 V_35 )
{
struct V_96 * V_99 ;
struct V_96 * V_106 ;
int V_33 = 0 ;
if ( ! F_59 ( V_9 ) )
return - V_34 ;
V_99 = F_72 ( V_110 , sizeof( struct V_111 ) ,
V_112 ) ;
if ( V_99 ) {
V_33 = F_63 ( V_9 , V_99 ) ;
if ( V_33 )
return V_33 ;
}
V_106 = F_72 ( V_110 , sizeof( struct V_111 ) ,
V_113 ) ;
if ( V_106 )
V_33 = F_67 ( V_9 , V_106 ,
V_53 ) ;
return V_33 ;
}
int F_73 ( struct V_8 * V_9 ,
struct V_109 * V_110 , T_5 V_35 )
{
struct V_96 * V_106 ;
if ( ! F_59 ( V_9 ) )
return - V_34 ;
V_106 = F_72 ( V_110 , sizeof( struct V_111 ) ,
V_113 ) ;
if ( V_106 )
return F_67 ( V_9 , V_106 ,
V_54 ) ;
return 0 ;
}
int F_74 ( struct V_114 * V_115 , struct V_96 * V_116 [] ,
struct V_8 * V_9 , const unsigned char * V_117 ,
T_5 V_68 , T_5 V_118 )
{
struct V_50 V_119 = {
. V_46 . V_82 = V_9 ,
. V_46 . V_31 = V_49 ,
. V_68 = V_68 ,
} ;
F_75 ( V_119 . V_117 , V_117 ) ;
return V_53 ( V_9 , & V_119 . V_46 ) ;
}
int F_76 ( struct V_114 * V_115 , struct V_96 * V_116 [] ,
struct V_8 * V_9 , const unsigned char * V_117 ,
T_5 V_68 )
{
struct V_50 V_119 = {
. V_46 . V_82 = V_9 ,
. V_46 . V_31 = V_49 ,
. V_68 = V_68 ,
} ;
F_75 ( V_119 . V_117 , V_117 ) ;
return V_54 ( V_9 , & V_119 . V_46 ) ;
}
static int F_77 ( struct V_45 * V_46 )
{
struct V_50 * V_119 = F_78 ( V_46 ) ;
struct V_120 * V_63 =
F_56 ( V_119 , struct V_120 , V_119 ) ;
T_4 V_121 = F_79 ( V_63 -> V_55 -> V_69 ) . V_121 ;
T_4 V_85 = V_63 -> V_55 -> V_110 -> V_122 ;
struct V_109 * V_110 ;
struct V_114 * V_115 ;
if ( V_63 -> V_123 < V_63 -> V_55 -> args [ 2 ] )
goto V_124;
V_110 = F_80 ( V_63 -> V_69 , V_121 , V_85 , V_125 ,
sizeof( * V_115 ) , V_126 ) ;
if ( ! V_110 )
return - V_71 ;
V_115 = F_81 ( V_110 ) ;
V_115 -> V_127 = V_128 ;
V_115 -> V_129 = 0 ;
V_115 -> V_130 = 0 ;
V_115 -> V_131 = V_132 ;
V_115 -> V_133 = 0 ;
V_115 -> V_134 = V_63 -> V_9 -> V_135 ;
V_115 -> V_136 = V_119 -> V_136 ;
if ( F_53 ( V_63 -> V_69 , V_137 , V_138 , V_119 -> V_117 ) )
goto V_139;
if ( V_119 -> V_68 && F_82 ( V_63 -> V_69 , V_140 , V_119 -> V_68 ) )
goto V_139;
F_83 ( V_63 -> V_69 , V_110 ) ;
V_124:
V_63 -> V_123 ++ ;
return 0 ;
V_139:
F_84 ( V_63 -> V_69 , V_110 ) ;
return - V_71 ;
}
int F_85 ( struct V_81 * V_69 , struct V_141 * V_55 ,
struct V_8 * V_9 ,
struct V_8 * V_142 , int * V_123 )
{
struct V_120 V_63 = {
. V_119 . V_46 . V_82 = V_9 ,
. V_119 . V_46 . V_31 = V_49 ,
. V_9 = V_9 ,
. V_69 = V_69 ,
. V_55 = V_55 ,
. V_123 = * V_123 ,
} ;
int V_33 ;
V_33 = F_45 ( V_9 , & V_63 . V_119 . V_46 ,
F_77 ) ;
* V_123 = V_63 . V_123 ;
return V_33 ;
}
bool F_86 ( struct V_8 * V_143 ,
struct V_8 * V_144 )
{
struct V_23 V_145 = {
. V_82 = V_143 ,
. V_31 = V_146 ,
} ;
struct V_23 V_147 = {
. V_82 = V_144 ,
. V_31 = V_146 ,
} ;
if ( F_29 ( V_143 , & V_145 ) ||
F_29 ( V_144 , & V_147 ) )
return false ;
return F_87 ( & V_145 . V_94 . V_148 , & V_147 . V_94 . V_148 ) ;
}
