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
case V_53 :
return sizeof( struct V_54 ) ;
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
if ( V_26 && V_26 -> V_55 )
return V_26 -> V_55 ( V_9 , V_46 , V_2 ) ;
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
int V_55 ( struct V_8 * V_9 ,
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
if ( V_26 && V_26 -> V_56 )
return V_26 -> V_56 ( V_9 , V_46 ) ;
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
int V_56 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
if ( V_46 -> V_35 & V_44 )
return F_44 ( V_9 , V_46 ) ;
F_19 () ;
return F_42 ( V_9 , V_46 ) ;
}
int F_45 ( struct V_8 * V_9 , struct V_45 * V_46 ,
T_3 * V_57 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
int V_33 = - V_34 ;
F_19 () ;
if ( V_26 && V_26 -> F_45 )
return V_26 -> F_45 ( V_9 , V_46 , V_57 ) ;
F_30 (dev, lower_dev, iter) {
V_33 = F_45 ( V_27 , V_46 , V_57 ) ;
break;
}
return V_33 ;
}
int F_46 ( struct V_58 * V_59 )
{
int V_33 ;
F_23 () ;
V_33 = F_47 ( & V_60 , V_59 ) ;
F_24 () ;
return V_33 ;
}
int F_48 ( struct V_58 * V_59 )
{
int V_33 ;
F_23 () ;
V_33 = F_49 ( & V_60 , V_59 ) ;
F_24 () ;
return V_33 ;
}
int F_50 ( unsigned long V_61 , struct V_8 * V_9 ,
struct V_62 * V_63 )
{
int V_33 ;
F_19 () ;
V_63 -> V_9 = V_9 ;
V_33 = F_51 ( & V_60 , V_61 , V_63 ) ;
return V_33 ;
}
static int F_52 ( struct V_64 * V_65 )
{
struct V_66 V_67 ;
V_67 . V_35 = V_65 -> V_35 ;
if ( V_65 -> V_68 == 0 && V_65 -> V_69 == 0 ) {
return 0 ;
} else if ( V_65 -> V_68 == V_65 -> V_69 ) {
V_67 . V_70 = V_65 -> V_68 ;
if ( F_53 ( V_65 -> V_71 , V_72 ,
sizeof( V_67 ) , & V_67 ) )
return - V_73 ;
} else {
V_67 . V_70 = V_65 -> V_68 ;
V_67 . V_35 |= V_74 ;
if ( F_53 ( V_65 -> V_71 , V_72 ,
sizeof( V_67 ) , & V_67 ) )
return - V_73 ;
V_67 . V_70 = V_65 -> V_69 ;
V_67 . V_35 &= ~ V_74 ;
V_67 . V_35 |= V_75 ;
if ( F_53 ( V_65 -> V_71 , V_72 ,
sizeof( V_67 ) , & V_67 ) )
return - V_73 ;
}
return 0 ;
}
static int F_54 ( struct V_45 * V_46 )
{
struct V_48 * V_76 = F_55 ( V_46 ) ;
struct V_64 * V_65 =
F_56 ( V_76 , struct V_64 , V_76 ) ;
int V_33 = 0 ;
if ( V_76 -> V_77 > V_76 -> V_78 )
return - V_79 ;
if ( V_65 -> V_80 & V_81 ) {
V_65 -> V_35 = V_76 -> V_35 ;
for ( V_65 -> V_68 = V_65 -> V_69 = V_76 -> V_77 ;
V_65 -> V_68 <= V_76 -> V_78 ;
V_65 -> V_68 ++ , V_65 -> V_69 ++ ) {
V_33 = F_52 ( V_65 ) ;
if ( V_33 )
return V_33 ;
}
} else if ( V_65 -> V_80 & V_82 ) {
if ( V_65 -> V_68 > V_76 -> V_77 &&
V_65 -> V_68 >= V_76 -> V_78 ) {
if ( ( V_65 -> V_68 - 1 ) == V_76 -> V_78 &&
V_65 -> V_35 == V_76 -> V_35 ) {
V_65 -> V_68 = V_76 -> V_77 ;
} else {
V_33 = F_52 ( V_65 ) ;
V_65 -> V_35 = V_76 -> V_35 ;
V_65 -> V_68 = V_76 -> V_77 ;
V_65 -> V_69 = V_76 -> V_78 ;
}
} else if ( V_65 -> V_69 <= V_76 -> V_77 &&
V_65 -> V_69 < V_76 -> V_78 ) {
if ( ( V_65 -> V_69 + 1 ) == V_76 -> V_77 &&
V_65 -> V_35 == V_76 -> V_35 ) {
V_65 -> V_69 = V_76 -> V_78 ;
} else {
V_33 = F_52 ( V_65 ) ;
V_65 -> V_35 = V_76 -> V_35 ;
V_65 -> V_68 = V_76 -> V_77 ;
V_65 -> V_69 = V_76 -> V_78 ;
}
} else {
V_33 = - V_79 ;
}
}
return V_33 ;
}
static int F_57 ( struct V_83 * V_71 , struct V_8 * V_9 ,
T_4 V_80 )
{
struct V_64 V_65 = {
. V_76 . V_46 . V_84 = V_9 ,
. V_76 . V_46 . V_31 = V_47 ,
. V_71 = V_71 ,
. V_80 = V_80 ,
} ;
int V_33 = 0 ;
if ( ( V_80 & V_81 ) ||
( V_80 & V_82 ) ) {
V_33 = F_45 ( V_9 , & V_65 . V_76 . V_46 ,
F_54 ) ;
if ( V_33 )
goto V_85;
if ( V_80 & V_82 )
V_33 = F_52 ( & V_65 ) ;
}
V_85:
return V_33 == - V_34 ? 0 : V_33 ;
}
int F_58 ( struct V_83 * V_71 , T_4 V_86 , T_4 V_87 ,
struct V_8 * V_9 , T_4 V_80 ,
int V_88 )
{
struct V_23 V_24 = {
. V_84 = V_9 ,
. V_31 = V_89 ,
} ;
T_5 V_90 = V_91 ;
T_4 V_92 = V_93 | V_94 | V_95 ;
int V_33 ;
V_33 = F_29 ( V_9 , & V_24 ) ;
if ( V_33 && V_33 != - V_34 )
return V_33 ;
return F_59 ( V_71 , V_86 , V_87 , V_9 , V_90 ,
V_24 . V_96 . V_97 , V_92 , V_88 ,
V_80 , F_57 ) ;
}
static int F_60 ( struct V_8 * V_9 ,
struct V_98 * V_98 ,
unsigned long V_99 )
{
struct V_23 V_24 = {
. V_84 = V_9 ,
. V_31 = V_89 ,
} ;
T_6 V_100 = F_61 ( V_98 ) ;
int V_33 ;
V_33 = F_29 ( V_9 , & V_24 ) ;
if ( V_33 )
return V_33 ;
if ( V_100 )
V_24 . V_96 . V_97 |= V_99 ;
else
V_24 . V_96 . V_97 &= ~ V_99 ;
return V_38 ( V_9 , & V_24 ) ;
}
static int F_62 ( struct V_8 * V_9 ,
struct V_98 * V_101 )
{
struct V_98 * V_24 ;
int V_102 ;
int V_33 ;
V_33 = F_63 ( V_101 , V_103 ,
V_104 ) ;
if ( V_33 )
return V_33 ;
F_64 (attr, protinfo, rem) {
switch ( F_65 ( V_24 ) ) {
case V_105 :
V_33 = F_60 ( V_9 , V_24 ,
V_93 ) ;
break;
case V_106 :
V_33 = F_60 ( V_9 , V_24 ,
V_94 ) ;
break;
case V_107 :
V_33 = F_60 ( V_9 , V_24 , V_95 ) ;
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
static int F_66 ( struct V_8 * V_9 ,
struct V_98 * V_108 ,
int (* F_67)( struct V_8 * V_9 ,
const struct V_45 * V_46 ) )
{
struct V_98 * V_24 ;
struct V_66 * V_67 ;
struct V_48 V_76 = {
. V_46 . V_84 = V_9 ,
. V_46 . V_31 = V_47 ,
} ;
int V_102 ;
int V_33 ;
F_64 (attr, afspec, rem) {
if ( F_65 ( V_24 ) != V_72 )
continue;
if ( F_68 ( V_24 ) != sizeof( struct V_66 ) )
return - V_79 ;
V_67 = F_69 ( V_24 ) ;
if ( ! V_67 -> V_70 || V_67 -> V_70 >= V_109 )
return - V_79 ;
V_76 . V_35 = V_67 -> V_35 ;
if ( V_67 -> V_35 & V_74 ) {
if ( V_76 . V_77 )
return - V_79 ;
V_76 . V_77 = V_67 -> V_70 ;
if ( V_76 . V_35 & V_110 )
return - V_79 ;
} else if ( V_67 -> V_35 & V_75 ) {
if ( ! V_76 . V_77 )
return - V_79 ;
V_76 . V_78 = V_67 -> V_70 ;
if ( V_76 . V_78 <= V_76 . V_77 )
return - V_79 ;
V_33 = F_67 ( V_9 , & V_76 . V_46 ) ;
if ( V_33 )
return V_33 ;
V_76 . V_77 = 0 ;
} else {
if ( V_76 . V_77 )
return - V_79 ;
V_76 . V_77 = V_67 -> V_70 ;
V_76 . V_78 = V_67 -> V_70 ;
V_33 = F_67 ( V_9 , & V_76 . V_46 ) ;
if ( V_33 )
return V_33 ;
V_76 . V_77 = 0 ;
}
}
return 0 ;
}
int F_70 ( struct V_8 * V_9 ,
struct V_111 * V_112 , T_5 V_35 )
{
struct V_98 * V_101 ;
struct V_98 * V_108 ;
int V_33 = 0 ;
V_101 = F_71 ( V_112 , sizeof( struct V_113 ) ,
V_114 ) ;
if ( V_101 ) {
V_33 = F_62 ( V_9 , V_101 ) ;
if ( V_33 )
return V_33 ;
}
V_108 = F_71 ( V_112 , sizeof( struct V_113 ) ,
V_115 ) ;
if ( V_108 )
V_33 = F_66 ( V_9 , V_108 ,
V_55 ) ;
return V_33 ;
}
int F_72 ( struct V_8 * V_9 ,
struct V_111 * V_112 , T_5 V_35 )
{
struct V_98 * V_108 ;
V_108 = F_71 ( V_112 , sizeof( struct V_113 ) ,
V_115 ) ;
if ( V_108 )
return F_66 ( V_9 , V_108 ,
V_56 ) ;
return 0 ;
}
int F_73 ( struct V_116 * V_117 , struct V_98 * V_118 [] ,
struct V_8 * V_9 , const unsigned char * V_119 ,
T_5 V_70 , T_5 V_120 )
{
struct V_52 V_121 = {
. V_46 . V_84 = V_9 ,
. V_46 . V_31 = V_51 ,
. V_70 = V_70 ,
} ;
F_74 ( V_121 . V_119 , V_119 ) ;
return V_55 ( V_9 , & V_121 . V_46 ) ;
}
int F_75 ( struct V_116 * V_117 , struct V_98 * V_118 [] ,
struct V_8 * V_9 , const unsigned char * V_119 ,
T_5 V_70 )
{
struct V_52 V_121 = {
. V_46 . V_84 = V_9 ,
. V_46 . V_31 = V_51 ,
. V_70 = V_70 ,
} ;
F_74 ( V_121 . V_119 , V_119 ) ;
return V_56 ( V_9 , & V_121 . V_46 ) ;
}
static int F_76 ( struct V_45 * V_46 )
{
struct V_52 * V_121 = F_77 ( V_46 ) ;
struct V_122 * V_65 =
F_56 ( V_121 , struct V_122 , V_121 ) ;
T_4 V_123 = F_78 ( V_65 -> V_57 -> V_71 ) . V_123 ;
T_4 V_87 = V_65 -> V_57 -> V_112 -> V_124 ;
struct V_111 * V_112 ;
struct V_116 * V_117 ;
if ( V_65 -> V_125 < V_65 -> V_57 -> args [ 0 ] )
goto V_126;
V_112 = F_79 ( V_65 -> V_71 , V_123 , V_87 , V_127 ,
sizeof( * V_117 ) , V_128 ) ;
if ( ! V_112 )
return - V_73 ;
V_117 = F_80 ( V_112 ) ;
V_117 -> V_129 = V_130 ;
V_117 -> V_131 = 0 ;
V_117 -> V_132 = 0 ;
V_117 -> V_133 = V_134 ;
V_117 -> V_135 = 0 ;
V_117 -> V_136 = V_65 -> V_9 -> V_137 ;
V_117 -> V_138 = V_121 -> V_138 ;
if ( F_53 ( V_65 -> V_71 , V_139 , V_140 , V_121 -> V_119 ) )
goto V_141;
if ( V_121 -> V_70 && F_81 ( V_65 -> V_71 , V_142 , V_121 -> V_70 ) )
goto V_141;
F_82 ( V_65 -> V_71 , V_112 ) ;
V_126:
V_65 -> V_125 ++ ;
return 0 ;
V_141:
F_83 ( V_65 -> V_71 , V_112 ) ;
return - V_73 ;
}
int F_84 ( struct V_83 * V_71 , struct V_143 * V_57 ,
struct V_8 * V_9 ,
struct V_8 * V_144 , int V_125 )
{
struct V_122 V_65 = {
. V_121 . V_46 . V_84 = V_9 ,
. V_121 . V_46 . V_31 = V_51 ,
. V_9 = V_9 ,
. V_71 = V_71 ,
. V_57 = V_57 ,
. V_125 = V_125 ,
} ;
int V_33 ;
V_33 = F_45 ( V_9 , & V_65 . V_121 . V_46 ,
F_76 ) ;
V_57 -> args [ 1 ] = V_33 ;
return V_65 . V_125 ;
}
static struct V_8 * F_85 ( struct V_8 * V_9 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_8 * V_145 ;
struct V_28 * V_29 ;
if ( V_26 && V_26 -> F_29 )
return V_9 ;
F_30 (dev, lower_dev, iter) {
V_145 = F_85 ( V_27 ) ;
if ( V_145 )
return V_145 ;
}
return NULL ;
}
static struct V_8 * F_86 ( struct V_146 * V_147 )
{
struct V_23 V_24 = {
. V_31 = V_148 ,
} ;
struct V_23 V_149 ;
struct V_8 * V_9 = NULL ;
int V_150 ;
F_19 () ;
for ( V_150 = 0 ; V_150 < V_147 -> V_151 ; V_150 ++ ) {
const struct V_152 * V_153 = & V_147 -> V_152 [ V_150 ] ;
if ( ! V_153 -> V_154 )
return NULL ;
V_9 = F_85 ( V_153 -> V_154 ) ;
if ( ! V_9 )
return NULL ;
V_24 . V_84 = V_9 ;
if ( F_29 ( V_9 , & V_24 ) )
return NULL ;
if ( V_150 > 0 &&
! F_87 ( & V_149 . V_96 . V_155 , & V_24 . V_96 . V_155 ) )
return NULL ;
V_149 = V_24 ;
}
return V_9 ;
}
int F_88 ( T_4 V_156 , int V_157 , struct V_146 * V_147 ,
T_6 V_158 , T_6 type , T_4 V_88 , T_4 V_159 )
{
struct V_50 V_160 = {
. V_46 . V_31 = V_49 ,
. V_156 = V_156 ,
. V_157 = V_157 ,
. V_147 = V_147 ,
. V_158 = V_158 ,
. type = type ,
. V_88 = V_88 ,
. V_159 = V_159 ,
} ;
struct V_8 * V_9 ;
int V_33 = 0 ;
#ifdef F_89
if ( V_147 -> V_161 -> V_162 . V_163 )
return 0 ;
#endif
if ( V_147 -> V_161 -> V_162 . V_164 )
return 0 ;
V_9 = F_86 ( V_147 ) ;
if ( ! V_9 )
return 0 ;
V_160 . V_46 . V_84 = V_9 ;
V_33 = V_55 ( V_9 , & V_160 . V_46 ) ;
if ( ! V_33 )
V_147 -> V_165 |= V_166 ;
return V_33 == - V_34 ? 0 : V_33 ;
}
int F_90 ( T_4 V_156 , int V_157 , struct V_146 * V_147 ,
T_6 V_158 , T_6 type , T_4 V_159 )
{
struct V_50 V_160 = {
. V_46 . V_31 = V_49 ,
. V_156 = V_156 ,
. V_157 = V_157 ,
. V_147 = V_147 ,
. V_158 = V_158 ,
. type = type ,
. V_88 = 0 ,
. V_159 = V_159 ,
} ;
struct V_8 * V_9 ;
int V_33 = 0 ;
if ( ! ( V_147 -> V_165 & V_166 ) )
return 0 ;
V_9 = F_86 ( V_147 ) ;
if ( ! V_9 )
return 0 ;
V_160 . V_46 . V_84 = V_9 ;
V_33 = V_56 ( V_9 , & V_160 . V_46 ) ;
if ( ! V_33 )
V_147 -> V_165 &= ~ V_166 ;
return V_33 == - V_34 ? 0 : V_33 ;
}
void F_91 ( struct V_146 * V_147 )
{
F_92 ( V_147 -> V_161 ) ;
V_147 -> V_161 -> V_162 . V_164 = true ;
}
static bool F_93 ( struct V_8 * V_167 ,
struct V_8 * V_168 )
{
struct V_23 V_169 = {
. V_84 = V_167 ,
. V_31 = V_148 ,
. V_35 = V_36 ,
} ;
struct V_23 V_170 = {
. V_84 = V_168 ,
. V_31 = V_148 ,
. V_35 = V_36 ,
} ;
if ( F_29 ( V_167 , & V_169 ) ||
F_29 ( V_168 , & V_170 ) )
return false ;
return F_87 ( & V_169 . V_96 . V_155 , & V_170 . V_96 . V_155 ) ;
}
static T_4 F_94 ( struct V_8 * V_9 ,
struct V_8 * V_171 )
{
struct V_8 * V_27 ;
struct V_28 * V_29 ;
F_30 (group_dev, lower_dev, iter) {
if ( V_27 == V_9 )
continue;
if ( F_93 ( V_9 , V_27 ) )
return V_27 -> V_172 ;
return F_94 ( V_9 , V_27 ) ;
}
return V_9 -> V_137 ;
}
static void F_95 ( struct V_8 * V_171 ,
T_4 V_173 , T_4 * V_174 )
{
struct V_8 * V_27 ;
struct V_28 * V_29 ;
F_30 (group_dev, lower_dev, iter) {
if ( V_27 -> V_172 == V_173 ) {
if ( ! * V_174 )
* V_174 = V_27 -> V_137 ;
V_27 -> V_172 = * V_174 ;
}
F_95 ( V_27 , V_173 , V_174 ) ;
}
}
void F_96 ( struct V_8 * V_9 ,
struct V_8 * V_171 ,
bool V_175 )
{
T_4 V_176 = V_9 -> V_137 ;
T_4 V_174 = 0 ;
if ( V_171 ) {
F_19 () ;
if ( V_175 )
V_176 = F_94 ( V_9 , V_171 ) ;
else if ( V_9 -> V_172 == V_176 )
F_95 ( V_171 , V_176 ,
& V_174 ) ;
}
V_9 -> V_172 = V_176 ;
}
