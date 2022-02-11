static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 [ 0 ] . V_4 == V_5 ;
}
static void F_2 ( struct V_6 * V_7 )
{
V_7 -> V_8 . V_3 [ 0 ] . V_4 = V_5 ;
}
static void F_3 ( struct V_6 * V_7 )
{
V_7 -> V_8 . V_3 [ 0 ] . V_4 = NULL ;
}
void F_4 ( struct V_9 * V_10 )
{
if ( ! V_10 )
return;
F_5 ( & V_10 -> V_11 ) ;
F_6 ( & V_10 -> V_12 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_13 )
F_7 ( V_7 -> V_8 . V_13 ) ;
F_8 ( L_1 , V_7 -> V_8 . V_3 [ 0 ] . V_14 ) ;
}
static int F_9 ( const char * V_15 , int V_16 , const char * V_17 , int V_18 )
{
int V_19 ;
int V_20 ;
V_19 = V_16 ;
if ( V_19 > V_18 )
V_19 = V_18 ;
V_20 = memcmp ( V_15 , V_17 , V_19 ) ;
if ( V_20 == 0 )
V_20 = V_16 - V_18 ;
return V_20 ;
}
static struct V_3 * F_10 ( struct V_1 * * V_21 ,
struct V_6 * V_7 , const char * V_22 , int V_23 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 ;
struct V_25 * V_26 = V_7 -> V_27 . V_25 ;
while ( V_26 )
{
struct V_28 * V_28 ;
const char * V_14 ;
int V_20 ;
V_28 = F_11 ( V_26 , struct V_28 , V_26 ) ;
V_2 = V_28 -> V_8 ;
V_24 = & V_2 -> V_3 [ V_28 - V_2 -> V_26 ] ;
V_14 = V_24 -> V_14 ;
V_20 = F_9 ( V_22 , V_23 , V_14 , strlen ( V_14 ) ) ;
if ( V_20 < 0 )
V_26 = V_26 -> V_29 ;
else if ( V_20 > 0 )
V_26 = V_26 -> V_30 ;
else {
* V_21 = V_2 ;
return V_24 ;
}
}
return NULL ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_24 )
{
struct V_25 * V_26 = & V_2 -> V_26 [ V_24 - V_2 -> V_3 ] . V_26 ;
struct V_25 * * V_31 = & V_2 -> V_13 -> V_27 . V_25 ;
struct V_25 * V_13 = NULL ;
const char * V_22 = V_24 -> V_14 ;
int V_23 = strlen ( V_22 ) ;
while ( * V_31 ) {
struct V_1 * V_32 ;
struct V_3 * V_33 ;
struct V_28 * V_34 ;
const char * V_35 ;
int V_20 ;
V_13 = * V_31 ;
V_34 = F_11 ( V_13 , struct V_28 , V_26 ) ;
V_32 = V_34 -> V_8 ;
V_33 = & V_32 -> V_3 [ V_34 - V_32 -> V_26 ] ;
V_35 = V_33 -> V_14 ;
V_20 = F_9 ( V_22 , V_23 , V_35 , strlen ( V_35 ) ) ;
if ( V_20 < 0 )
V_31 = & ( * V_31 ) -> V_29 ;
else if ( V_20 > 0 )
V_31 = & ( * V_31 ) -> V_30 ;
else {
F_13 ( L_2 ) ;
F_7 ( V_2 -> V_13 ) ;
F_8 ( L_3 , V_24 -> V_14 ) ;
return - V_36 ;
}
}
F_14 ( V_26 , V_13 , V_31 ) ;
F_15 ( V_26 , & V_2 -> V_13 -> V_27 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_24 )
{
struct V_25 * V_26 = & V_2 -> V_26 [ V_24 - V_2 -> V_3 ] . V_26 ;
F_17 ( V_26 , & V_2 -> V_13 -> V_27 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_37 * V_27 , struct V_38 * V_39 ,
struct V_28 * V_26 , struct V_3 * V_40 )
{
V_2 -> V_3 = V_40 ;
V_2 -> V_41 = V_40 ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 1 ;
V_2 -> V_44 = 1 ;
V_2 -> V_45 = NULL ;
V_2 -> V_27 = V_27 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_13 = NULL ;
V_2 -> V_26 = V_26 ;
if ( V_26 ) {
struct V_3 * V_24 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ , V_26 ++ )
V_26 -> V_8 = V_2 ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_24 ;
for ( V_24 = V_2 -> V_3 ; V_24 -> V_14 ; V_24 ++ )
F_16 ( V_2 , V_24 ) ;
}
static int F_20 ( struct V_6 * V_7 , struct V_1 * V_8 )
{
struct V_3 * V_24 ;
int V_46 ;
if ( F_1 ( & V_7 -> V_8 ) )
return - V_47 ;
if ( V_8 -> V_3 == V_5 ) {
if ( ! F_21 ( & V_7 -> V_27 ) )
return - V_48 ;
F_2 ( V_7 ) ;
}
V_7 -> V_8 . V_44 ++ ;
V_8 -> V_13 = V_7 ;
V_46 = F_22 ( V_8 ) ;
if ( V_46 )
goto V_49;
for ( V_24 = V_8 -> V_3 ; V_24 -> V_14 ; V_24 ++ ) {
V_46 = F_12 ( V_8 , V_24 ) ;
if ( V_46 )
goto V_50;
}
return 0 ;
V_50:
F_19 ( V_8 ) ;
F_23 ( V_8 ) ;
V_49:
if ( V_8 -> V_3 == V_5 )
F_3 ( V_7 ) ;
V_8 -> V_13 = NULL ;
F_24 ( & V_7 -> V_8 ) ;
return V_46 ;
}
static int F_25 ( struct V_1 * V_31 )
{
if ( F_26 ( V_31 -> V_45 ) )
return 0 ;
V_31 -> V_42 ++ ;
return 1 ;
}
static void F_27 ( struct V_1 * V_31 )
{
if ( ! -- V_31 -> V_42 )
if ( F_26 ( V_31 -> V_45 ) )
F_28 ( V_31 -> V_45 ) ;
}
static void F_29 ( struct V_1 * V_31 )
{
if ( F_26 ( V_31 -> V_42 ) ) {
struct V_51 V_12 ;
F_30 ( & V_12 ) ;
V_31 -> V_45 = & V_12 ;
F_31 ( & V_52 ) ;
F_32 ( & V_12 ) ;
F_33 ( & V_52 ) ;
} else {
V_31 -> V_45 = F_34 ( - V_48 ) ;
}
F_19 ( V_31 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_33 ( & V_52 ) ;
V_2 -> V_43 ++ ;
F_31 ( & V_52 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_33 ( & V_52 ) ;
if ( ! -- V_2 -> V_43 )
F_37 ( V_2 , V_53 ) ;
F_31 ( & V_52 ) ;
}
static struct V_1 * F_38 ( struct V_1 * V_2 )
{
F_39 ( ! V_2 ) ;
F_33 ( & V_52 ) ;
if ( ! F_25 ( V_2 ) )
V_2 = F_34 ( - V_54 ) ;
F_31 ( & V_52 ) ;
return V_2 ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_33 ( & V_52 ) ;
F_27 ( V_2 ) ;
F_31 ( & V_52 ) ;
}
static struct V_38 *
F_41 ( struct V_37 * V_27 , struct V_55 * V_56 )
{
struct V_38 * V_39 = & V_27 -> V_57 ;
if ( V_27 -> V_58 )
V_39 = V_27 -> V_58 ( V_27 , V_56 ) ;
return V_39 ;
}
static struct V_3 * F_42 ( struct V_1 * * V_21 ,
struct V_6 * V_7 ,
const char * V_22 , int V_23 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 ;
F_33 ( & V_52 ) ;
V_24 = F_10 ( & V_2 , V_7 , V_22 , V_23 ) ;
if ( V_24 && F_25 ( V_2 ) )
* V_21 = V_2 ;
else
V_24 = NULL ;
F_31 ( & V_52 ) ;
return V_24 ;
}
static struct V_28 * F_43 ( struct V_25 * V_26 )
{
struct V_28 * V_28 ;
for (; V_26 ; V_26 = F_44 ( V_26 ) ) {
V_28 = F_11 ( V_26 , struct V_28 , V_26 ) ;
if ( F_25 ( V_28 -> V_8 ) )
return V_28 ;
}
return NULL ;
}
static void F_45 ( struct V_6 * V_7 ,
struct V_1 * * V_21 , struct V_3 * * V_59 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_24 = NULL ;
struct V_28 * V_28 ;
F_33 ( & V_52 ) ;
V_28 = F_43 ( F_46 ( & V_7 -> V_27 ) ) ;
F_31 ( & V_52 ) ;
if ( V_28 ) {
V_2 = V_28 -> V_8 ;
V_24 = & V_2 -> V_3 [ V_28 - V_2 -> V_26 ] ;
}
* V_21 = V_2 ;
* V_59 = V_24 ;
}
static void F_47 ( struct V_1 * * V_21 , struct V_3 * * V_59 )
{
struct V_1 * V_2 = * V_21 ;
struct V_3 * V_24 = * V_59 ;
struct V_28 * V_28 = & V_2 -> V_26 [ V_24 - V_2 -> V_3 ] ;
F_33 ( & V_52 ) ;
F_27 ( V_2 ) ;
V_28 = F_43 ( F_44 ( & V_28 -> V_26 ) ) ;
F_31 ( & V_52 ) ;
V_2 = NULL ;
if ( V_28 ) {
V_2 = V_28 -> V_8 ;
V_24 = & V_2 -> V_3 [ V_28 - V_2 -> V_26 ] ;
}
* V_21 = V_2 ;
* V_59 = V_24 ;
}
void F_48 ( struct V_37 * V_27 )
{
}
static int F_49 ( int V_60 , int V_61 )
{
if ( F_50 ( F_51 () , V_62 ) )
V_60 >>= 6 ;
else if ( F_52 ( V_63 ) )
V_60 >>= 3 ;
if ( ( V_61 & ~ V_60 & ( V_64 | V_65 | V_66 ) ) == 0 )
return 0 ;
return - V_67 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_3 * V_40 , int V_61 )
{
struct V_37 * V_27 = V_2 -> V_27 ;
int V_60 ;
if ( V_27 -> V_68 )
V_60 = V_27 -> V_68 ( V_2 , V_40 ) ;
else
V_60 = V_40 -> V_60 ;
return F_49 ( V_60 , V_61 ) ;
}
static struct V_69 * F_54 ( struct V_70 * V_71 ,
struct V_1 * V_2 , struct V_3 * V_40 )
{
struct V_69 * V_69 ;
struct V_72 * V_73 ;
V_69 = F_55 ( V_71 ) ;
if ( ! V_69 )
goto V_74;
V_69 -> V_75 = F_56 () ;
F_35 ( V_2 ) ;
V_73 = F_57 ( V_69 ) ;
V_73 -> V_76 = V_2 ;
V_73 -> V_77 = V_40 ;
V_69 -> V_78 = V_69 -> V_79 = V_69 -> V_80 = V_81 ;
V_69 -> V_82 = V_40 -> V_60 ;
if ( ! F_58 ( V_40 -> V_60 ) ) {
V_69 -> V_82 |= V_83 ;
V_69 -> V_84 = & V_85 ;
V_69 -> V_86 = & V_87 ;
} else {
V_69 -> V_82 |= V_88 ;
V_69 -> V_84 = & V_89 ;
V_69 -> V_86 = & V_90 ;
if ( F_1 ( V_2 ) )
F_59 ( V_69 ) ;
}
V_74:
return V_69 ;
}
static struct V_1 * F_60 ( struct V_69 * V_69 )
{
struct V_1 * V_2 = F_57 ( V_69 ) -> V_76 ;
if ( ! V_2 )
V_2 = & V_91 . V_57 . V_7 . V_8 ;
return F_38 ( V_2 ) ;
}
static struct V_92 * F_61 ( struct V_69 * V_7 , struct V_92 * V_92 ,
unsigned int V_93 )
{
struct V_1 * V_2 = F_60 ( V_7 ) ;
struct V_1 * V_94 = NULL ;
struct V_95 * V_22 = & V_92 -> V_96 ;
struct V_3 * V_31 ;
struct V_69 * V_69 ;
struct V_92 * V_46 = F_34 ( - V_54 ) ;
struct V_6 * V_6 ;
int V_97 ;
if ( F_62 ( V_2 ) )
return F_63 ( V_2 ) ;
V_6 = F_64 ( V_2 , struct V_6 , V_8 ) ;
V_31 = F_42 ( & V_94 , V_6 , V_22 -> V_22 , V_22 -> V_98 ) ;
if ( ! V_31 )
goto V_74;
if ( F_65 ( V_31 -> V_60 ) ) {
V_97 = F_66 ( & V_94 , & V_31 , V_99 -> V_55 ) ;
V_46 = F_34 ( V_97 ) ;
if ( V_97 )
goto V_74;
}
V_46 = F_34 ( - V_100 ) ;
V_69 = F_54 ( V_7 -> V_101 , V_94 ? V_94 : V_2 , V_31 ) ;
if ( ! V_69 )
goto V_74;
V_46 = NULL ;
F_67 ( V_92 , & V_102 ) ;
F_68 ( V_92 , V_69 ) ;
V_74:
if ( V_94 )
F_40 ( V_94 ) ;
F_40 ( V_2 ) ;
return V_46 ;
}
static T_1 F_69 ( struct V_103 * V_104 , void T_2 * V_105 ,
T_3 V_43 , T_4 * V_106 , int V_107 )
{
struct V_69 * V_69 = F_70 ( V_104 ) ;
struct V_1 * V_2 = F_60 ( V_69 ) ;
struct V_3 * V_40 = F_57 ( V_69 ) -> V_77 ;
T_1 error ;
T_3 V_108 ;
if ( F_62 ( V_2 ) )
return F_71 ( V_2 ) ;
error = - V_109 ;
if ( F_53 ( V_2 , V_40 , V_107 ? V_65 : V_64 ) )
goto V_74;
error = - V_48 ;
if ( ! V_40 -> V_110 )
goto V_74;
V_108 = V_43 ;
error = V_40 -> V_110 ( V_40 , V_107 , V_105 , & V_108 , V_106 ) ;
if ( ! error )
error = V_108 ;
V_74:
F_40 ( V_2 ) ;
return error ;
}
static T_1 F_72 ( struct V_103 * V_104 , char T_2 * V_105 ,
T_3 V_43 , T_4 * V_106 )
{
return F_69 ( V_104 , ( void T_2 * ) V_105 , V_43 , V_106 , 0 ) ;
}
static T_1 F_73 ( struct V_103 * V_104 , const char T_2 * V_105 ,
T_3 V_43 , T_4 * V_106 )
{
return F_69 ( V_104 , ( void T_2 * ) V_105 , V_43 , V_106 , 1 ) ;
}
static int F_74 ( struct V_69 * V_69 , struct V_103 * V_104 )
{
struct V_1 * V_2 = F_60 ( V_69 ) ;
struct V_3 * V_40 = F_57 ( V_69 ) -> V_77 ;
if ( F_62 ( V_2 ) )
return F_71 ( V_2 ) ;
if ( V_40 -> V_10 )
V_104 -> V_111 = F_75 ( V_40 -> V_10 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static unsigned int F_76 ( struct V_103 * V_104 , T_5 * V_12 )
{
struct V_69 * V_69 = F_70 ( V_104 ) ;
struct V_1 * V_2 = F_60 ( V_69 ) ;
struct V_3 * V_40 = F_57 ( V_69 ) -> V_77 ;
unsigned int V_97 = V_112 ;
unsigned long V_11 ;
if ( F_62 ( V_2 ) )
return V_113 | V_114 ;
if ( ! V_40 -> V_110 )
goto V_74;
if ( ! V_40 -> V_10 )
goto V_74;
V_11 = ( unsigned long ) V_104 -> V_111 ;
F_77 ( V_104 , & V_40 -> V_10 -> V_12 , V_12 ) ;
if ( V_11 != F_78 ( & V_40 -> V_10 -> V_11 ) ) {
V_104 -> V_111 = F_75 ( V_40 -> V_10 ) ;
V_97 = V_115 | V_116 | V_113 | V_117 ;
}
V_74:
F_40 ( V_2 ) ;
return V_97 ;
}
static bool F_79 ( struct V_103 * V_103 ,
struct V_118 * V_119 ,
struct V_1 * V_2 ,
struct V_3 * V_40 )
{
struct V_92 * V_4 , * V_7 = V_103 -> V_120 . V_92 ;
struct V_69 * V_69 ;
struct V_95 V_121 ;
T_6 V_122 = 0 ;
unsigned type = V_123 ;
V_121 . V_22 = V_40 -> V_14 ;
V_121 . V_98 = strlen ( V_40 -> V_14 ) ;
V_121 . V_124 = F_80 ( V_121 . V_22 , V_121 . V_98 ) ;
V_4 = F_81 ( V_7 , & V_121 ) ;
if ( ! V_4 ) {
F_82 ( V_125 ) ;
V_4 = F_83 ( V_7 , & V_121 , & V_125 ) ;
if ( F_62 ( V_4 ) )
return false ;
if ( F_84 ( V_4 ) ) {
V_69 = F_54 ( V_7 -> V_126 , V_2 , V_40 ) ;
if ( ! V_69 ) {
F_85 ( V_4 ) ;
F_86 ( V_4 ) ;
return false ;
}
F_67 ( V_4 , & V_102 ) ;
F_68 ( V_4 , V_69 ) ;
}
}
V_69 = F_87 ( V_4 ) ;
V_122 = V_69 -> V_75 ;
type = V_69 -> V_82 >> 12 ;
F_86 ( V_4 ) ;
return F_88 ( V_119 , V_121 . V_22 , V_121 . V_98 , V_122 , type ) ;
}
static bool F_89 ( struct V_103 * V_103 ,
struct V_118 * V_119 ,
struct V_1 * V_2 ,
struct V_3 * V_40 )
{
bool V_97 = true ;
V_2 = F_38 ( V_2 ) ;
if ( F_65 ( V_40 -> V_60 ) ) {
int V_46 = F_66 ( & V_2 , & V_40 , V_99 -> V_55 ) ;
if ( V_46 )
goto V_74;
}
V_97 = F_79 ( V_103 , V_119 , V_2 , V_40 ) ;
V_74:
F_40 ( V_2 ) ;
return V_97 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_3 * V_40 ,
unsigned long * V_127 , struct V_103 * V_103 ,
struct V_118 * V_119 )
{
bool V_108 ;
if ( ( * V_127 ) ++ < V_119 -> V_127 )
return true ;
if ( F_26 ( F_65 ( V_40 -> V_60 ) ) )
V_108 = F_89 ( V_103 , V_119 , V_2 , V_40 ) ;
else
V_108 = F_79 ( V_103 , V_119 , V_2 , V_40 ) ;
if ( V_108 )
V_119 -> V_127 = * V_127 ;
return V_108 ;
}
static int F_91 ( struct V_103 * V_103 , struct V_118 * V_119 )
{
struct V_1 * V_2 = F_60 ( F_70 ( V_103 ) ) ;
struct V_1 * V_94 = NULL ;
struct V_3 * V_24 ;
struct V_6 * V_6 ;
unsigned long V_127 ;
if ( F_62 ( V_2 ) )
return F_71 ( V_2 ) ;
V_6 = F_64 ( V_2 , struct V_6 , V_8 ) ;
if ( ! F_92 ( V_103 , V_119 ) )
return 0 ;
V_127 = 2 ;
for ( F_45 ( V_6 , & V_94 , & V_24 ) ; V_94 ; F_47 ( & V_94 , & V_24 ) ) {
if ( ! F_90 ( V_94 , V_24 , & V_127 , V_103 , V_119 ) ) {
F_40 ( V_94 ) ;
break;
}
}
F_40 ( V_2 ) ;
return 0 ;
}
static int F_93 ( struct V_69 * V_69 , int V_128 )
{
struct V_1 * V_2 ;
struct V_3 * V_40 ;
int error ;
if ( ( V_128 & V_66 ) && F_94 ( V_69 -> V_82 ) )
return - V_67 ;
V_2 = F_60 ( V_69 ) ;
if ( F_62 ( V_2 ) )
return F_71 ( V_2 ) ;
V_40 = F_57 ( V_69 ) -> V_77 ;
if ( ! V_40 )
error = V_128 & V_65 ? - V_67 : 0 ;
else
error = F_53 ( V_2 , V_40 , V_128 & ~ V_129 ) ;
F_40 ( V_2 ) ;
return error ;
}
static int F_95 ( struct V_92 * V_92 , struct V_130 * V_131 )
{
struct V_69 * V_69 = F_87 ( V_92 ) ;
int error ;
if ( V_131 -> V_132 & ( V_133 | V_134 | V_135 ) )
return - V_109 ;
error = F_96 ( V_69 , V_131 ) ;
if ( error )
return error ;
F_97 ( V_69 , V_131 ) ;
F_98 ( V_69 ) ;
return 0 ;
}
static int F_99 ( struct V_136 * V_137 , struct V_92 * V_92 , struct V_138 * V_139 )
{
struct V_69 * V_69 = F_87 ( V_92 ) ;
struct V_1 * V_2 = F_60 ( V_69 ) ;
struct V_3 * V_40 = F_57 ( V_69 ) -> V_77 ;
if ( F_62 ( V_2 ) )
return F_71 ( V_2 ) ;
F_100 ( V_69 , V_139 ) ;
if ( V_40 )
V_139 -> V_60 = ( V_139 -> V_60 & V_140 ) | V_40 -> V_60 ;
F_40 ( V_2 ) ;
return 0 ;
}
static int F_101 ( struct V_92 * V_92 , unsigned int V_93 )
{
if ( V_93 & V_141 )
return - V_142 ;
return ! F_57 ( F_87 ( V_92 ) ) -> V_76 -> V_45 ;
}
static int F_102 ( const struct V_92 * V_92 )
{
return ! ! F_57 ( F_87 ( V_92 ) ) -> V_76 -> V_45 ;
}
static int F_103 ( struct V_1 * V_31 )
{
struct V_38 * V_39 = V_31 -> V_39 ;
int V_108 ;
F_33 ( & V_52 ) ;
if ( V_31 -> V_45 )
V_108 = 0 ;
else if ( ! V_39 -> V_143 )
V_108 = 1 ;
else
V_108 = V_39 -> V_143 ( V_39 ) ;
F_31 ( & V_52 ) ;
return V_108 ;
}
static int F_104 ( const struct V_92 * V_13 , const struct V_92 * V_92 ,
unsigned int V_98 , const char * V_144 , const struct V_95 * V_22 )
{
struct V_1 * V_2 ;
struct V_69 * V_69 ;
V_69 = F_105 ( V_92 ) ;
if ( ! V_69 )
return 1 ;
if ( V_22 -> V_98 != V_98 )
return 1 ;
if ( memcmp ( V_22 -> V_22 , V_144 , V_98 ) )
return 1 ;
V_2 = F_106 ( F_57 ( V_69 ) -> V_76 ) ;
return ! V_2 || ! F_103 ( V_2 ) ;
}
static struct V_6 * F_107 ( struct V_6 * V_7 ,
const char * V_22 , int V_23 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 ;
V_24 = F_10 ( & V_2 , V_7 , V_22 , V_23 ) ;
if ( ! V_24 )
return F_34 ( - V_54 ) ;
if ( ! F_58 ( V_24 -> V_60 ) )
return F_34 ( - V_145 ) ;
return F_64 ( V_2 , struct V_6 , V_8 ) ;
}
static struct V_6 * F_108 ( struct V_38 * V_39 ,
const char * V_22 , int V_23 )
{
struct V_3 * V_40 ;
struct V_6 * V_146 ;
struct V_28 * V_26 ;
char * V_147 ;
V_146 = F_109 ( sizeof( * V_146 ) + sizeof( struct V_28 ) +
sizeof( struct V_3 ) * 2 + V_23 + 1 ,
V_148 ) ;
if ( ! V_146 )
return NULL ;
V_26 = (struct V_28 * ) ( V_146 + 1 ) ;
V_40 = (struct V_3 * ) ( V_26 + 1 ) ;
V_147 = ( char * ) ( V_40 + 2 ) ;
memcpy ( V_147 , V_22 , V_23 ) ;
V_147 [ V_23 ] = '\0' ;
V_40 [ 0 ] . V_14 = V_147 ;
V_40 [ 0 ] . V_60 = V_88 | V_149 | V_150 ;
F_18 ( & V_146 -> V_8 , V_39 -> V_7 . V_8 . V_27 , V_39 , V_26 , V_40 ) ;
return V_146 ;
}
static struct V_6 * F_110 ( struct V_6 * V_7 ,
const char * V_22 , int V_23 )
{
struct V_38 * V_39 = V_7 -> V_8 . V_39 ;
struct V_6 * V_151 , * V_146 = NULL ;
int V_46 ;
F_33 ( & V_52 ) ;
V_151 = F_107 ( V_7 , V_22 , V_23 ) ;
if ( ! F_62 ( V_151 ) )
goto V_152;
if ( F_71 ( V_151 ) != - V_54 )
goto V_153;
F_31 ( & V_52 ) ;
V_146 = F_108 ( V_39 , V_22 , V_23 ) ;
F_33 ( & V_52 ) ;
V_151 = F_34 ( - V_100 ) ;
if ( ! V_146 )
goto V_153;
V_151 = F_107 ( V_7 , V_22 , V_23 ) ;
if ( ! F_62 ( V_151 ) )
goto V_152;
if ( F_71 ( V_151 ) != - V_54 )
goto V_153;
V_46 = F_20 ( V_7 , & V_146 -> V_8 ) ;
V_151 = F_34 ( V_46 ) ;
if ( V_46 )
goto V_153;
V_151 = V_146 ;
V_152:
V_151 -> V_8 . V_44 ++ ;
V_153:
if ( F_62 ( V_151 ) ) {
F_13 ( L_4 ) ;
F_7 ( V_7 ) ;
F_8 ( L_5 ,
V_23 , V_23 , V_22 , F_71 ( V_151 ) ) ;
}
F_24 ( & V_7 -> V_8 ) ;
if ( V_146 )
F_24 ( & V_146 -> V_8 ) ;
F_31 ( & V_52 ) ;
return V_151 ;
}
static struct V_6 * F_111 ( struct V_38 * V_39 , struct V_6 * V_7 )
{
struct V_6 * V_13 ;
const char * V_14 ;
if ( ! V_7 -> V_8 . V_13 )
return & V_39 -> V_7 ;
V_13 = F_111 ( V_39 , V_7 -> V_8 . V_13 ) ;
if ( F_62 ( V_13 ) )
return V_13 ;
V_14 = V_7 -> V_8 . V_3 [ 0 ] . V_14 ;
return F_107 ( V_13 , V_14 , strlen ( V_14 ) ) ;
}
static int F_66 ( struct V_1 * * V_21 ,
struct V_3 * * V_59 , struct V_55 * V_56 )
{
struct V_1 * V_2 ;
struct V_37 * V_27 ;
struct V_38 * V_39 ;
struct V_3 * V_24 ;
struct V_6 * V_7 ;
int V_97 ;
V_97 = 0 ;
F_33 ( & V_52 ) ;
V_27 = ( * V_59 ) -> V_154 ;
V_39 = F_41 ( V_27 , V_56 ) ;
V_7 = F_111 ( V_39 , ( * V_21 ) -> V_13 ) ;
if ( F_62 ( V_7 ) )
V_97 = F_71 ( V_7 ) ;
else {
const char * V_14 = ( * V_59 ) -> V_14 ;
V_2 = NULL ;
V_24 = F_10 ( & V_2 , V_7 , V_14 , strlen ( V_14 ) ) ;
V_97 = - V_54 ;
if ( V_24 && F_25 ( V_2 ) ) {
F_27 ( * V_21 ) ;
* V_21 = V_2 ;
* V_59 = V_24 ;
V_97 = 0 ;
}
}
F_31 ( & V_52 ) ;
return V_97 ;
}
static int F_112 ( const char * V_155 , struct V_3 * V_40 , char * V_156 , ... )
{
struct V_157 V_158 ;
T_7 args ;
va_start ( args , V_156 ) ;
V_158 . V_156 = V_156 ;
V_158 . V_159 = & args ;
F_13 ( L_6 ,
V_155 , V_40 -> V_14 , & V_158 ) ;
va_end ( args ) ;
return - V_48 ;
}
static int F_113 ( const char * V_155 , struct V_3 * V_40 )
{
int V_46 = 0 ;
for (; V_40 -> V_14 ; V_40 ++ ) {
if ( V_40 -> V_4 )
V_46 = F_112 ( V_155 , V_40 , L_7 ) ;
if ( ( V_40 -> V_110 == V_160 ) ||
( V_40 -> V_110 == V_161 ) ||
( V_40 -> V_110 == V_162 ) ||
( V_40 -> V_110 == V_163 ) ||
( V_40 -> V_110 == V_164 ) ||
( V_40 -> V_110 == V_165 ) ||
( V_40 -> V_110 == V_166 ) ||
( V_40 -> V_110 == V_167 ) ) {
if ( ! V_40 -> V_154 )
V_46 = F_112 ( V_155 , V_40 , L_8 ) ;
if ( ! V_40 -> V_168 )
V_46 = F_112 ( V_155 , V_40 , L_9 ) ;
}
if ( ! V_40 -> V_110 )
V_46 = F_112 ( V_155 , V_40 , L_10 ) ;
if ( ( V_40 -> V_60 & ( V_149 | V_169 ) ) != V_40 -> V_60 )
V_46 = F_112 ( V_155 , V_40 , L_11 ,
V_40 -> V_60 ) ;
}
return V_46 ;
}
static struct V_1 * F_114 ( struct V_6 * V_7 , struct V_3 * V_40 ,
struct V_37 * V_170 )
{
struct V_3 * V_171 , * V_24 , * V_172 ;
struct V_1 * V_173 ;
struct V_28 * V_26 ;
char * V_174 ;
int V_175 , V_176 ;
V_176 = 0 ;
V_175 = 0 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
V_175 ++ ;
V_176 += strlen ( V_24 -> V_14 ) + 1 ;
}
V_173 = F_109 ( sizeof( struct V_1 ) +
sizeof( struct V_28 ) * V_175 +
sizeof( struct V_3 ) * ( V_175 + 1 ) +
V_176 ,
V_148 ) ;
if ( ! V_173 )
return NULL ;
V_26 = (struct V_28 * ) ( V_173 + 1 ) ;
V_171 = (struct V_3 * ) ( V_26 + V_175 ) ;
V_174 = ( char * ) & V_171 [ V_175 + 1 ] ;
for ( V_172 = V_171 , V_24 = V_40 ; V_24 -> V_14 ; V_172 ++ , V_24 ++ ) {
int V_98 = strlen ( V_24 -> V_14 ) + 1 ;
memcpy ( V_174 , V_24 -> V_14 , V_98 ) ;
V_172 -> V_14 = V_174 ;
V_172 -> V_60 = V_177 | V_178 ;
V_172 -> V_154 = V_170 ;
V_174 += V_98 ;
}
F_18 ( V_173 , V_7 -> V_8 . V_27 , V_7 -> V_8 . V_39 , V_26 , V_171 ) ;
V_173 -> V_44 = V_175 ;
return V_173 ;
}
static bool F_115 ( struct V_6 * V_7 ,
struct V_3 * V_40 , struct V_37 * V_170 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 , * V_172 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
const char * V_14 = V_24 -> V_14 ;
V_172 = F_10 ( & V_2 , V_7 , V_14 , strlen ( V_14 ) ) ;
if ( ! V_172 )
return false ;
if ( F_58 ( V_172 -> V_60 ) && F_58 ( V_24 -> V_60 ) )
continue;
if ( F_65 ( V_172 -> V_60 ) && ( V_172 -> V_154 == V_170 ) )
continue;
return false ;
}
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
const char * V_14 = V_24 -> V_14 ;
V_172 = F_10 ( & V_2 , V_7 , V_14 , strlen ( V_14 ) ) ;
V_2 -> V_44 ++ ;
}
return true ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_38 * V_179 = & V_91 . V_57 ;
struct V_6 * V_180 = NULL ;
struct V_1 * V_173 ;
int V_46 ;
if ( V_2 -> V_39 == V_179 )
return 0 ;
V_180 = F_111 ( V_179 , V_2 -> V_13 ) ;
if ( F_62 ( V_180 ) )
return 0 ;
if ( F_115 ( V_180 , V_2 -> V_3 , V_2 -> V_27 ) )
return 0 ;
V_180 -> V_8 . V_44 ++ ;
F_31 ( & V_52 ) ;
V_173 = F_114 ( V_180 , V_2 -> V_3 , V_2 -> V_27 ) ;
F_33 ( & V_52 ) ;
V_46 = - V_100 ;
if ( ! V_173 )
goto V_74;
V_46 = 0 ;
if ( F_115 ( V_180 , V_2 -> V_3 , V_2 -> V_27 ) ) {
F_116 ( V_173 ) ;
goto V_74;
}
V_46 = F_20 ( V_180 , V_173 ) ;
if ( V_46 )
F_116 ( V_173 ) ;
V_74:
F_24 ( & V_180 -> V_8 ) ;
return V_46 ;
}
struct V_1 * F_117 (
struct V_38 * V_39 ,
const char * V_155 , struct V_3 * V_40 )
{
struct V_37 * V_27 = V_39 -> V_7 . V_8 . V_27 ;
struct V_1 * V_8 ;
const char * V_22 , * V_181 ;
struct V_6 * V_7 ;
struct V_3 * V_24 ;
struct V_28 * V_26 ;
int V_175 = 0 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ )
V_175 ++ ;
V_8 = F_109 ( sizeof( struct V_1 ) +
sizeof( struct V_28 ) * V_175 , V_148 ) ;
if ( ! V_8 )
return NULL ;
V_26 = (struct V_28 * ) ( V_8 + 1 ) ;
F_18 ( V_8 , V_27 , V_39 , V_26 , V_40 ) ;
if ( F_113 ( V_155 , V_40 ) )
goto V_50;
F_33 ( & V_52 ) ;
V_7 = & V_39 -> V_7 ;
V_7 -> V_8 . V_44 ++ ;
F_31 ( & V_52 ) ;
for ( V_22 = V_155 ; V_22 ; V_22 = V_181 ) {
int V_23 ;
V_181 = strchr ( V_22 , '/' ) ;
if ( V_181 ) {
V_23 = V_181 - V_22 ;
V_181 ++ ;
} else {
V_23 = strlen ( V_22 ) ;
}
if ( V_23 == 0 )
continue;
V_7 = F_110 ( V_7 , V_22 , V_23 ) ;
if ( F_62 ( V_7 ) )
goto V_50;
}
F_33 ( & V_52 ) ;
if ( F_20 ( V_7 , V_8 ) )
goto V_182;
F_24 ( & V_7 -> V_8 ) ;
F_31 ( & V_52 ) ;
return V_8 ;
V_182:
F_24 ( & V_7 -> V_8 ) ;
F_31 ( & V_52 ) ;
V_50:
F_116 ( V_8 ) ;
F_118 () ;
return NULL ;
}
struct V_1 * F_119 ( const char * V_155 , struct V_3 * V_40 )
{
return F_117 ( & V_91 . V_57 ,
V_155 , V_40 ) ;
}
static char * F_120 ( const char * V_155 , char * V_127 , const char * V_22 )
{
int V_23 ;
V_23 = strlen ( V_22 ) ;
if ( ( ( V_127 - V_155 ) + V_23 + 2 ) >= V_183 )
return NULL ;
memcpy ( V_127 , V_22 , V_23 ) ;
V_127 [ V_23 ] = '/' ;
V_127 [ V_23 + 1 ] = '\0' ;
V_127 += V_23 + 1 ;
return V_127 ;
}
static int F_121 ( struct V_3 * V_40 )
{
int V_184 = 0 ;
int V_185 = 0 ;
struct V_3 * V_24 ;
if ( ! V_40 || ! V_40 -> V_14 )
return 1 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
if ( V_24 -> V_4 )
V_185 += F_121 ( V_24 -> V_4 ) ;
else
V_184 = 1 ;
}
return V_185 + V_184 ;
}
static int F_122 ( const char * V_155 , char * V_127 ,
struct V_1 * * * V_186 , struct V_38 * V_39 ,
struct V_3 * V_40 )
{
struct V_3 * V_41 = NULL ;
struct V_3 * V_24 , * V_187 ;
int V_188 = 0 ;
int V_189 = 0 ;
int V_46 = - V_100 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
if ( V_24 -> V_4 )
V_189 ++ ;
else
V_188 ++ ;
}
V_187 = V_40 ;
if ( V_189 && V_188 ) {
struct V_3 * V_146 ;
V_187 = F_109 ( sizeof( struct V_3 ) * ( V_188 + 1 ) ,
V_148 ) ;
if ( ! V_187 )
goto V_74;
V_41 = V_187 ;
for ( V_146 = V_187 , V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
if ( V_24 -> V_4 )
continue;
* V_146 = * V_24 ;
V_146 ++ ;
}
}
if ( V_188 || ! V_189 ) {
struct V_1 * V_8 ;
V_8 = F_117 ( V_39 , V_155 , V_187 ) ;
if ( ! V_8 ) {
F_116 ( V_41 ) ;
goto V_74;
}
V_8 -> V_41 = V_41 ;
* * V_186 = V_8 ;
( * V_186 ) ++ ;
}
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
char * V_190 ;
if ( ! V_24 -> V_4 )
continue;
V_46 = - V_191 ;
V_190 = F_120 ( V_155 , V_127 , V_24 -> V_14 ) ;
if ( ! V_190 )
goto V_74;
V_46 = F_122 ( V_155 , V_190 , V_186 ,
V_39 , V_24 -> V_4 ) ;
V_127 [ 0 ] = '\0' ;
if ( V_46 )
goto V_74;
}
V_46 = 0 ;
V_74:
return V_46 ;
}
struct V_1 * F_123 (
struct V_38 * V_39 ,
const struct V_192 * V_155 , struct V_3 * V_40 )
{
struct V_3 * V_41 = V_40 ;
int V_185 = F_121 ( V_40 ) ;
struct V_1 * V_8 = NULL , * * V_193 , * * V_186 ;
const struct V_192 * V_194 ;
char * V_195 , * V_127 ;
V_127 = V_195 = F_124 ( V_183 , V_148 ) ;
if ( ! V_195 )
return NULL ;
V_127 [ 0 ] = '\0' ;
for ( V_194 = V_155 ; V_194 -> V_14 ; V_194 ++ ) {
V_127 = F_120 ( V_195 , V_127 , V_194 -> V_14 ) ;
if ( ! V_127 )
goto V_74;
}
while ( V_40 -> V_14 && V_40 -> V_4 && ! V_40 [ 1 ] . V_14 ) {
V_127 = F_120 ( V_195 , V_127 , V_40 -> V_14 ) ;
if ( ! V_127 )
goto V_74;
V_40 = V_40 -> V_4 ;
}
if ( V_185 == 1 ) {
V_8 = F_117 ( V_39 , V_195 , V_40 ) ;
if ( V_8 )
V_8 -> V_41 = V_41 ;
} else {
V_8 = F_109 ( sizeof( * V_8 ) +
sizeof( * V_193 ) * V_185 , V_148 ) ;
if ( ! V_8 )
goto V_74;
V_193 = (struct V_1 * * ) ( V_8 + 1 ) ;
V_186 = V_193 ;
V_8 -> V_41 = V_41 ;
if ( F_122 ( V_195 , V_127 , & V_186 ,
V_39 , V_40 ) )
goto V_196;
}
V_74:
F_116 ( V_195 ) ;
return V_8 ;
V_196:
while ( V_186 > V_193 ) {
struct V_1 * V_197 = * ( -- V_186 ) ;
struct V_3 * V_40 = V_197 -> V_41 ;
F_125 ( V_197 ) ;
F_116 ( V_40 ) ;
}
F_116 ( V_8 ) ;
V_8 = NULL ;
goto V_74;
}
struct V_1 * F_126 ( const struct V_192 * V_155 ,
struct V_3 * V_40 )
{
return F_123 ( & V_91 . V_57 ,
V_155 , V_40 ) ;
}
struct V_1 * F_127 ( struct V_3 * V_40 )
{
static const struct V_192 V_198 [] = { {} } ;
return F_126 ( V_198 , V_40 ) ;
}
static void F_23 ( struct V_1 * V_8 )
{
struct V_38 * V_179 = & V_91 . V_57 ;
struct V_37 * V_27 = V_8 -> V_27 ;
struct V_6 * V_13 = V_8 -> V_13 ;
struct V_6 * V_180 ;
struct V_3 * V_24 ;
if ( V_8 -> V_39 == V_179 )
return;
V_180 = F_111 ( V_179 , V_13 ) ;
if ( F_62 ( V_180 ) )
return;
for ( V_24 = V_8 -> V_3 ; V_24 -> V_14 ; V_24 ++ ) {
struct V_1 * V_199 ;
struct V_3 * V_172 ;
const char * V_22 = V_24 -> V_14 ;
V_172 = F_10 ( & V_199 , V_180 , V_22 , strlen ( V_22 ) ) ;
if ( V_172 &&
( ( F_58 ( V_172 -> V_60 ) && F_58 ( V_24 -> V_60 ) ) ||
( F_65 ( V_172 -> V_60 ) && ( V_172 -> V_154 == V_27 ) ) ) ) {
F_24 ( V_199 ) ;
}
else {
F_13 ( L_12 ) ;
F_7 ( V_13 ) ;
F_8 ( L_3 , V_22 ) ;
}
}
}
static void F_24 ( struct V_1 * V_8 )
{
struct V_6 * V_13 = V_8 -> V_13 ;
if ( -- V_8 -> V_44 )
return;
F_23 ( V_8 ) ;
F_29 ( V_8 ) ;
if ( ! -- V_8 -> V_43 )
F_37 ( V_8 , V_53 ) ;
if ( V_13 )
F_24 ( & V_13 -> V_8 ) ;
}
void F_125 ( struct V_1 * V_8 )
{
int V_185 ;
F_128 () ;
if ( V_8 == NULL )
return;
V_185 = F_121 ( V_8 -> V_41 ) ;
if ( F_26 ( V_185 > 1 ) ) {
struct V_1 * * V_193 ;
int V_200 ;
V_193 = (struct V_1 * * ) ( V_8 + 1 ) ;
for ( V_200 = V_185 - 1 ; V_200 >= 0 ; V_200 -- ) {
struct V_1 * V_197 = V_193 [ V_200 ] ;
struct V_3 * V_40 = V_197 -> V_41 ;
F_125 ( V_197 ) ;
F_116 ( V_40 ) ;
}
F_116 ( V_8 ) ;
return;
}
F_33 ( & V_52 ) ;
F_24 ( V_8 ) ;
F_31 ( & V_52 ) ;
}
void F_129 ( struct V_38 * V_39 ,
struct V_37 * V_27 ,
int (* V_143)( struct V_38 * ) )
{
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_143 = V_143 ;
F_18 ( & V_39 -> V_7 . V_8 , V_27 , V_39 , NULL , V_201 ) ;
}
void F_130 ( struct V_38 * V_39 )
{
F_131 ( ! F_21 ( & V_39 -> V_7 . V_27 ) ) ;
}
int T_8 F_132 ( void )
{
struct V_202 * V_203 ;
V_203 = F_133 ( L_13 , NULL ) ;
V_203 -> V_204 = & V_89 ;
V_203 -> V_205 = & V_90 ;
V_203 -> V_206 = 0 ;
return F_134 () ;
}
