void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 . V_8 )
F_4 ( V_6 -> V_7 . V_8 ) ;
F_5 ( V_9 L_1 , V_6 -> V_7 . V_10 [ 0 ] . V_11 ) ;
}
static int F_6 ( const char * V_12 , int V_13 , const char * V_14 , int V_15 )
{
int V_16 ;
int V_17 ;
V_16 = V_13 ;
if ( V_16 > V_15 )
V_16 = V_15 ;
V_17 = memcmp ( V_12 , V_14 , V_16 ) ;
if ( V_17 == 0 )
V_17 = V_13 - V_15 ;
return V_17 ;
}
static struct V_10 * F_7 ( struct V_18 * * V_19 ,
struct V_5 * V_6 , const char * V_20 , int V_21 )
{
struct V_18 * V_22 ;
struct V_10 * V_23 ;
struct V_24 * V_25 = V_6 -> V_26 . V_24 ;
while ( V_25 )
{
struct V_27 * V_27 ;
const char * V_11 ;
int V_17 ;
V_27 = F_8 ( V_25 , struct V_27 , V_25 ) ;
V_22 = V_27 -> V_7 ;
V_23 = & V_22 -> V_10 [ V_27 - V_22 -> V_25 ] ;
V_11 = V_23 -> V_11 ;
V_17 = F_6 ( V_20 , V_21 , V_11 , strlen ( V_11 ) ) ;
if ( V_17 < 0 )
V_25 = V_25 -> V_28 ;
else if ( V_17 > 0 )
V_25 = V_25 -> V_29 ;
else {
* V_19 = V_22 ;
return V_23 ;
}
}
return NULL ;
}
static int F_9 ( struct V_18 * V_22 , struct V_10 * V_23 )
{
struct V_24 * V_25 = & V_22 -> V_25 [ V_23 - V_22 -> V_10 ] . V_25 ;
struct V_24 * * V_30 = & V_22 -> V_8 -> V_26 . V_24 ;
struct V_24 * V_8 = NULL ;
const char * V_20 = V_23 -> V_11 ;
int V_21 = strlen ( V_20 ) ;
while ( * V_30 ) {
struct V_18 * V_31 ;
struct V_10 * V_32 ;
struct V_27 * V_33 ;
const char * V_34 ;
int V_17 ;
V_8 = * V_30 ;
V_33 = F_8 ( V_8 , struct V_27 , V_25 ) ;
V_31 = V_33 -> V_7 ;
V_32 = & V_31 -> V_10 [ V_33 - V_31 -> V_25 ] ;
V_34 = V_32 -> V_11 ;
V_17 = F_6 ( V_20 , V_21 , V_34 , strlen ( V_34 ) ) ;
if ( V_17 < 0 )
V_30 = & ( * V_30 ) -> V_28 ;
else if ( V_17 > 0 )
V_30 = & ( * V_30 ) -> V_29 ;
else {
F_5 ( V_35 L_2 ) ;
F_4 ( V_22 -> V_8 ) ;
F_5 ( V_9 L_3 , V_23 -> V_11 ) ;
return - V_36 ;
}
}
F_10 ( V_25 , V_8 , V_30 ) ;
return 0 ;
}
static void F_11 ( struct V_18 * V_22 , struct V_10 * V_23 )
{
struct V_24 * V_25 = & V_22 -> V_25 [ V_23 - V_22 -> V_10 ] . V_25 ;
F_12 ( V_25 , & V_22 -> V_8 -> V_26 ) ;
}
static void F_13 ( struct V_18 * V_22 ,
struct V_37 * V_26 , struct V_38 * V_39 ,
struct V_27 * V_25 , struct V_10 * V_40 )
{
V_22 -> V_10 = V_40 ;
V_22 -> V_41 = V_40 ;
V_22 -> V_42 = 0 ;
V_22 -> V_43 = 1 ;
V_22 -> V_44 = 1 ;
V_22 -> V_45 = NULL ;
V_22 -> V_26 = V_26 ;
V_22 -> V_39 = V_39 ;
V_22 -> V_8 = NULL ;
V_22 -> V_25 = V_25 ;
if ( V_25 ) {
struct V_10 * V_23 ;
for ( V_23 = V_40 ; V_23 -> V_11 ; V_23 ++ , V_25 ++ ) {
F_14 ( & V_25 -> V_25 ) ;
V_25 -> V_7 = V_22 ;
}
}
}
static void F_15 ( struct V_18 * V_22 )
{
struct V_10 * V_23 ;
for ( V_23 = V_22 -> V_10 ; V_23 -> V_11 ; V_23 ++ )
F_11 ( V_22 , V_23 ) ;
}
static int F_16 ( struct V_5 * V_6 , struct V_18 * V_7 )
{
struct V_10 * V_23 ;
int V_46 ;
V_6 -> V_7 . V_44 ++ ;
V_7 -> V_8 = V_6 ;
V_46 = F_17 ( V_7 ) ;
if ( V_46 )
goto V_47;
for ( V_23 = V_7 -> V_10 ; V_23 -> V_11 ; V_23 ++ ) {
V_46 = F_9 ( V_7 , V_23 ) ;
if ( V_46 )
goto V_48;
}
return 0 ;
V_48:
F_15 ( V_7 ) ;
F_18 ( V_7 ) ;
V_47:
V_7 -> V_8 = NULL ;
F_19 ( & V_6 -> V_7 ) ;
return V_46 ;
}
static int F_20 ( struct V_18 * V_30 )
{
if ( F_21 ( V_30 -> V_45 ) )
return 0 ;
V_30 -> V_42 ++ ;
return 1 ;
}
static void F_22 ( struct V_18 * V_30 )
{
if ( ! -- V_30 -> V_42 )
if ( F_21 ( V_30 -> V_45 ) )
F_23 ( V_30 -> V_45 ) ;
}
static void F_24 ( struct V_18 * V_30 )
{
if ( F_21 ( V_30 -> V_42 ) ) {
struct V_49 V_4 ;
F_25 ( & V_4 ) ;
V_30 -> V_45 = & V_4 ;
F_26 ( & V_50 ) ;
F_27 ( & V_4 ) ;
F_28 ( & V_50 ) ;
} else {
V_30 -> V_45 = F_29 ( - V_51 ) ;
}
F_15 ( V_30 ) ;
}
static void F_30 ( struct V_18 * V_22 )
{
F_28 ( & V_50 ) ;
V_22 -> V_43 ++ ;
F_26 ( & V_50 ) ;
}
void F_31 ( struct V_18 * V_22 )
{
F_28 ( & V_50 ) ;
if ( ! -- V_22 -> V_43 )
F_32 ( V_22 , V_52 ) ;
F_26 ( & V_50 ) ;
}
static struct V_18 * F_33 ( struct V_18 * V_22 )
{
if ( ! V_22 )
F_34 () ;
F_28 ( & V_50 ) ;
if ( ! F_20 ( V_22 ) )
V_22 = F_29 ( - V_53 ) ;
F_26 ( & V_50 ) ;
return V_22 ;
}
static void F_35 ( struct V_18 * V_22 )
{
if ( ! V_22 )
return;
F_28 ( & V_50 ) ;
F_22 ( V_22 ) ;
F_26 ( & V_50 ) ;
}
static struct V_38 *
F_36 ( struct V_37 * V_26 , struct V_54 * V_55 )
{
struct V_38 * V_39 = & V_26 -> V_56 ;
if ( V_26 -> V_57 )
V_39 = V_26 -> V_57 ( V_26 , V_55 ) ;
return V_39 ;
}
static struct V_10 * F_37 ( struct V_18 * * V_19 ,
struct V_5 * V_6 ,
const char * V_20 , int V_21 )
{
struct V_18 * V_22 ;
struct V_10 * V_23 ;
F_28 ( & V_50 ) ;
V_23 = F_7 ( & V_22 , V_6 , V_20 , V_21 ) ;
if ( V_23 && F_20 ( V_22 ) )
* V_19 = V_22 ;
else
V_23 = NULL ;
F_26 ( & V_50 ) ;
return V_23 ;
}
static struct V_27 * F_38 ( struct V_24 * V_25 )
{
struct V_27 * V_27 ;
for (; V_25 ; V_25 = F_39 ( V_25 ) ) {
V_27 = F_8 ( V_25 , struct V_27 , V_25 ) ;
if ( F_20 ( V_27 -> V_7 ) )
return V_27 ;
}
return NULL ;
}
static void F_40 ( struct V_5 * V_6 ,
struct V_18 * * V_19 , struct V_10 * * V_58 )
{
struct V_18 * V_22 = NULL ;
struct V_10 * V_23 = NULL ;
struct V_27 * V_27 ;
F_28 ( & V_50 ) ;
V_27 = F_38 ( F_41 ( & V_6 -> V_26 ) ) ;
F_26 ( & V_50 ) ;
if ( V_27 ) {
V_22 = V_27 -> V_7 ;
V_23 = & V_22 -> V_10 [ V_27 - V_22 -> V_25 ] ;
}
* V_19 = V_22 ;
* V_58 = V_23 ;
}
static void F_42 ( struct V_18 * * V_19 , struct V_10 * * V_58 )
{
struct V_18 * V_22 = * V_19 ;
struct V_10 * V_23 = * V_58 ;
struct V_27 * V_27 = & V_22 -> V_25 [ V_23 - V_22 -> V_10 ] ;
F_28 ( & V_50 ) ;
F_22 ( V_22 ) ;
V_27 = F_38 ( F_39 ( & V_27 -> V_25 ) ) ;
F_26 ( & V_50 ) ;
V_22 = NULL ;
if ( V_27 ) {
V_22 = V_27 -> V_7 ;
V_23 = & V_22 -> V_10 [ V_27 - V_22 -> V_25 ] ;
}
* V_19 = V_22 ;
* V_58 = V_23 ;
}
void F_43 ( struct V_37 * V_26 )
{
}
static int F_44 ( int V_59 , int V_60 )
{
if ( F_45 ( F_46 () , V_61 ) )
V_59 >>= 6 ;
else if ( F_47 ( V_62 ) )
V_59 >>= 3 ;
if ( ( V_60 & ~ V_59 & ( V_63 | V_64 | V_65 ) ) == 0 )
return 0 ;
return - V_66 ;
}
static int F_48 ( struct V_37 * V_26 , struct V_10 * V_40 , int V_60 )
{
int V_59 ;
if ( V_26 -> V_67 )
V_59 = V_26 -> V_67 ( V_26 , V_68 -> V_54 , V_40 ) ;
else
V_59 = V_40 -> V_59 ;
return F_44 ( V_59 , V_60 ) ;
}
static struct V_69 * F_49 ( struct V_70 * V_71 ,
struct V_18 * V_22 , struct V_10 * V_40 )
{
struct V_69 * V_69 ;
struct V_72 * V_73 ;
V_69 = F_50 ( V_71 ) ;
if ( ! V_69 )
goto V_74;
V_69 -> V_75 = F_51 () ;
F_30 ( V_22 ) ;
V_73 = F_52 ( V_69 ) ;
V_73 -> V_76 = V_22 ;
V_73 -> V_77 = V_40 ;
V_69 -> V_78 = V_69 -> V_79 = V_69 -> V_80 = V_81 ;
V_69 -> V_82 = V_40 -> V_59 ;
if ( ! F_53 ( V_40 -> V_59 ) ) {
V_69 -> V_82 |= V_83 ;
V_69 -> V_84 = & V_85 ;
V_69 -> V_86 = & V_87 ;
} else {
V_69 -> V_82 |= V_88 ;
V_69 -> V_84 = & V_89 ;
V_69 -> V_86 = & V_90 ;
}
V_74:
return V_69 ;
}
static struct V_18 * F_54 ( struct V_69 * V_69 )
{
struct V_18 * V_22 = F_52 ( V_69 ) -> V_76 ;
if ( ! V_22 )
V_22 = & V_91 . V_56 . V_6 . V_7 ;
return F_33 ( V_22 ) ;
}
static struct V_92 * F_55 ( struct V_69 * V_6 , struct V_92 * V_92 ,
unsigned int V_93 )
{
struct V_18 * V_22 = F_54 ( V_6 ) ;
struct V_18 * V_94 = NULL ;
struct V_95 * V_20 = & V_92 -> V_96 ;
struct V_10 * V_30 ;
struct V_69 * V_69 ;
struct V_92 * V_46 = F_29 ( - V_53 ) ;
struct V_5 * V_5 ;
int V_97 ;
if ( F_56 ( V_22 ) )
return F_57 ( V_22 ) ;
V_5 = F_58 ( V_22 , struct V_5 , V_7 ) ;
V_30 = F_37 ( & V_94 , V_5 , V_20 -> V_20 , V_20 -> V_98 ) ;
if ( ! V_30 )
goto V_74;
if ( F_59 ( V_30 -> V_59 ) ) {
V_97 = F_60 ( & V_94 , & V_30 , V_68 -> V_54 ) ;
V_46 = F_29 ( V_97 ) ;
if ( V_97 )
goto V_74;
}
V_46 = F_29 ( - V_99 ) ;
V_69 = F_49 ( V_6 -> V_100 , V_94 ? V_94 : V_22 , V_30 ) ;
if ( ! V_69 )
goto V_74;
V_46 = NULL ;
F_61 ( V_92 , & V_101 ) ;
F_62 ( V_92 , V_69 ) ;
V_74:
if ( V_94 )
F_35 ( V_94 ) ;
F_35 ( V_22 ) ;
return V_46 ;
}
static T_1 F_63 ( struct V_102 * V_103 , void T_2 * V_104 ,
T_3 V_43 , T_4 * V_105 , int V_106 )
{
struct V_69 * V_69 = V_103 -> V_107 . V_92 -> V_108 ;
struct V_18 * V_22 = F_54 ( V_69 ) ;
struct V_10 * V_40 = F_52 ( V_69 ) -> V_77 ;
T_1 error ;
T_3 V_109 ;
if ( F_56 ( V_22 ) )
return F_64 ( V_22 ) ;
error = - V_110 ;
if ( F_48 ( V_22 -> V_26 , V_40 , V_106 ? V_64 : V_63 ) )
goto V_74;
error = - V_51 ;
if ( ! V_40 -> V_111 )
goto V_74;
V_109 = V_43 ;
error = V_40 -> V_111 ( V_40 , V_106 , V_104 , & V_109 , V_105 ) ;
if ( ! error )
error = V_109 ;
V_74:
F_35 ( V_22 ) ;
return error ;
}
static T_1 F_65 ( struct V_102 * V_103 , char T_2 * V_104 ,
T_3 V_43 , T_4 * V_105 )
{
return F_63 ( V_103 , ( void T_2 * ) V_104 , V_43 , V_105 , 0 ) ;
}
static T_1 F_66 ( struct V_102 * V_103 , const char T_2 * V_104 ,
T_3 V_43 , T_4 * V_105 )
{
return F_63 ( V_103 , ( void T_2 * ) V_104 , V_43 , V_105 , 1 ) ;
}
static int F_67 ( struct V_69 * V_69 , struct V_102 * V_103 )
{
struct V_18 * V_22 = F_54 ( V_69 ) ;
struct V_10 * V_40 = F_52 ( V_69 ) -> V_77 ;
if ( F_56 ( V_22 ) )
return F_64 ( V_22 ) ;
if ( V_40 -> V_2 )
V_103 -> V_112 = F_68 ( V_40 -> V_2 ) ;
F_35 ( V_22 ) ;
return 0 ;
}
static unsigned int F_69 ( struct V_102 * V_103 , T_5 * V_4 )
{
struct V_69 * V_69 = V_103 -> V_107 . V_92 -> V_108 ;
struct V_18 * V_22 = F_54 ( V_69 ) ;
struct V_10 * V_40 = F_52 ( V_69 ) -> V_77 ;
unsigned int V_97 = V_113 ;
unsigned long V_3 ;
if ( F_56 ( V_22 ) )
return V_114 | V_115 ;
if ( ! V_40 -> V_111 )
goto V_74;
if ( ! V_40 -> V_2 )
goto V_74;
V_3 = ( unsigned long ) V_103 -> V_112 ;
F_70 ( V_103 , & V_40 -> V_2 -> V_4 , V_4 ) ;
if ( V_3 != F_71 ( & V_40 -> V_2 -> V_3 ) ) {
V_103 -> V_112 = F_68 ( V_40 -> V_2 ) ;
V_97 = V_116 | V_117 | V_114 | V_118 ;
}
V_74:
F_35 ( V_22 ) ;
return V_97 ;
}
static int F_72 ( struct V_102 * V_103 , void * V_119 ,
T_6 V_120 ,
struct V_18 * V_22 ,
struct V_10 * V_40 )
{
struct V_92 * V_121 , * V_6 = V_103 -> V_107 . V_92 ;
struct V_69 * V_69 ;
struct V_95 V_122 ;
T_7 V_123 = 0 ;
unsigned type = V_124 ;
V_122 . V_20 = V_40 -> V_11 ;
V_122 . V_98 = strlen ( V_40 -> V_11 ) ;
V_122 . V_125 = F_73 ( V_122 . V_20 , V_122 . V_98 ) ;
V_121 = F_74 ( V_6 , & V_122 ) ;
if ( ! V_121 ) {
V_121 = F_75 ( V_6 , & V_122 ) ;
if ( V_121 ) {
V_69 = F_49 ( V_6 -> V_126 , V_22 , V_40 ) ;
if ( ! V_69 ) {
F_76 ( V_121 ) ;
return - V_99 ;
} else {
F_61 ( V_121 , & V_101 ) ;
F_62 ( V_121 , V_69 ) ;
}
} else {
return - V_99 ;
}
}
V_69 = V_121 -> V_108 ;
V_123 = V_69 -> V_75 ;
type = V_69 -> V_82 >> 12 ;
F_76 ( V_121 ) ;
return ! ! V_120 ( V_119 , V_122 . V_20 , V_122 . V_98 , V_103 -> V_127 , V_123 , type ) ;
}
static int F_77 ( struct V_102 * V_103 , void * V_119 ,
T_6 V_120 ,
struct V_18 * V_22 ,
struct V_10 * V_40 )
{
int V_46 , V_97 = 0 ;
V_22 = F_33 ( V_22 ) ;
if ( F_59 ( V_40 -> V_59 ) ) {
V_46 = F_60 ( & V_22 , & V_40 , V_68 -> V_54 ) ;
if ( V_46 )
goto V_74;
}
V_97 = F_72 ( V_103 , V_119 , V_120 , V_22 , V_40 ) ;
V_74:
F_35 ( V_22 ) ;
return V_97 ;
}
static int F_78 ( struct V_18 * V_22 , V_10 * V_40 ,
unsigned long * V_128 , struct V_102 * V_102 ,
void * V_119 , T_6 V_120 )
{
int V_109 ;
if ( ( * V_128 ) ++ < V_102 -> V_127 )
return 0 ;
if ( F_21 ( F_59 ( V_40 -> V_59 ) ) )
V_109 = F_77 ( V_102 , V_119 , V_120 , V_22 , V_40 ) ;
else
V_109 = F_72 ( V_102 , V_119 , V_120 , V_22 , V_40 ) ;
if ( V_109 == 0 )
V_102 -> V_127 = * V_128 ;
return V_109 ;
}
static int F_79 ( struct V_102 * V_103 , void * V_119 , T_6 V_120 )
{
struct V_92 * V_92 = V_103 -> V_107 . V_92 ;
struct V_69 * V_69 = V_92 -> V_108 ;
struct V_18 * V_22 = F_54 ( V_69 ) ;
struct V_18 * V_94 = NULL ;
struct V_10 * V_23 ;
struct V_5 * V_5 ;
unsigned long V_128 ;
int V_97 = - V_51 ;
if ( F_56 ( V_22 ) )
return F_64 ( V_22 ) ;
V_5 = F_58 ( V_22 , struct V_5 , V_7 ) ;
V_97 = 0 ;
if ( V_103 -> V_127 == 0 ) {
if ( V_120 ( V_119 , L_4 , 1 , V_103 -> V_127 ,
V_69 -> V_75 , V_129 ) < 0 )
goto V_74;
V_103 -> V_127 ++ ;
}
if ( V_103 -> V_127 == 1 ) {
if ( V_120 ( V_119 , L_5 , 2 , V_103 -> V_127 ,
F_80 ( V_92 ) , V_129 ) < 0 )
goto V_74;
V_103 -> V_127 ++ ;
}
V_128 = 2 ;
for ( F_40 ( V_5 , & V_94 , & V_23 ) ; V_94 ; F_42 ( & V_94 , & V_23 ) ) {
V_97 = F_78 ( V_94 , V_23 , & V_128 , V_103 , V_119 , V_120 ) ;
if ( V_97 ) {
F_35 ( V_94 ) ;
break;
}
}
V_97 = 1 ;
V_74:
F_35 ( V_22 ) ;
return V_97 ;
}
static int F_81 ( struct V_69 * V_69 , int V_130 )
{
struct V_18 * V_22 ;
struct V_10 * V_40 ;
int error ;
if ( ( V_130 & V_65 ) && F_82 ( V_69 -> V_82 ) )
return - V_66 ;
V_22 = F_54 ( V_69 ) ;
if ( F_56 ( V_22 ) )
return F_64 ( V_22 ) ;
V_40 = F_52 ( V_69 ) -> V_77 ;
if ( ! V_40 )
error = V_130 & V_64 ? - V_66 : 0 ;
else
error = F_48 ( V_22 -> V_26 , V_40 , V_130 & ~ V_131 ) ;
F_35 ( V_22 ) ;
return error ;
}
static int F_83 ( struct V_92 * V_92 , struct V_132 * V_133 )
{
struct V_69 * V_69 = V_92 -> V_108 ;
int error ;
if ( V_133 -> V_134 & ( V_135 | V_136 | V_137 ) )
return - V_110 ;
error = F_84 ( V_69 , V_133 ) ;
if ( error )
return error ;
if ( ( V_133 -> V_134 & V_138 ) &&
V_133 -> V_139 != F_85 ( V_69 ) ) {
error = F_86 ( V_69 , V_133 -> V_139 ) ;
if ( error )
return error ;
}
F_87 ( V_69 , V_133 ) ;
F_88 ( V_69 ) ;
return 0 ;
}
static int F_89 ( struct V_140 * V_141 , struct V_92 * V_92 , struct V_142 * V_143 )
{
struct V_69 * V_69 = V_92 -> V_108 ;
struct V_18 * V_22 = F_54 ( V_69 ) ;
struct V_10 * V_40 = F_52 ( V_69 ) -> V_77 ;
if ( F_56 ( V_22 ) )
return F_64 ( V_22 ) ;
F_90 ( V_69 , V_143 ) ;
if ( V_40 )
V_143 -> V_59 = ( V_143 -> V_59 & V_144 ) | V_40 -> V_59 ;
F_35 ( V_22 ) ;
return 0 ;
}
static int F_91 ( struct V_92 * V_92 , unsigned int V_93 )
{
if ( V_93 & V_145 )
return - V_146 ;
return ! F_52 ( V_92 -> V_108 ) -> V_76 -> V_45 ;
}
static int F_92 ( const struct V_92 * V_92 )
{
return ! ! F_52 ( V_92 -> V_108 ) -> V_76 -> V_45 ;
}
static int F_93 ( struct V_18 * V_30 )
{
struct V_38 * V_39 = V_30 -> V_39 ;
int V_109 ;
F_28 ( & V_50 ) ;
if ( V_30 -> V_45 )
V_109 = 0 ;
else if ( ! V_39 -> V_147 )
V_109 = 1 ;
else
V_109 = V_39 -> V_147 ( V_39 ) ;
F_26 ( & V_50 ) ;
return V_109 ;
}
static int F_94 ( const struct V_92 * V_8 ,
const struct V_69 * V_148 ,
const struct V_92 * V_92 , const struct V_69 * V_69 ,
unsigned int V_98 , const char * V_149 , const struct V_95 * V_20 )
{
struct V_18 * V_22 ;
if ( ! V_69 )
return 1 ;
if ( V_20 -> V_98 != V_98 )
return 1 ;
if ( memcmp ( V_20 -> V_20 , V_149 , V_98 ) )
return 1 ;
V_22 = F_95 ( F_52 ( V_69 ) -> V_76 ) ;
return ! V_22 || ! F_93 ( V_22 ) ;
}
static struct V_5 * F_96 ( struct V_5 * V_6 ,
const char * V_20 , int V_21 )
{
struct V_18 * V_22 ;
struct V_10 * V_23 ;
V_23 = F_7 ( & V_22 , V_6 , V_20 , V_21 ) ;
if ( ! V_23 )
return F_29 ( - V_53 ) ;
if ( ! F_53 ( V_23 -> V_59 ) )
return F_29 ( - V_150 ) ;
return F_58 ( V_22 , struct V_5 , V_7 ) ;
}
static struct V_5 * F_97 ( struct V_38 * V_39 ,
const char * V_20 , int V_21 )
{
struct V_10 * V_40 ;
struct V_5 * V_151 ;
struct V_27 * V_25 ;
char * V_152 ;
V_151 = F_98 ( sizeof( * V_151 ) + sizeof( struct V_27 ) +
sizeof( struct V_10 ) * 2 + V_21 + 1 ,
V_153 ) ;
if ( ! V_151 )
return NULL ;
V_25 = (struct V_27 * ) ( V_151 + 1 ) ;
V_40 = (struct V_10 * ) ( V_25 + 1 ) ;
V_152 = ( char * ) ( V_40 + 2 ) ;
memcpy ( V_152 , V_20 , V_21 ) ;
V_152 [ V_21 ] = '\0' ;
V_40 [ 0 ] . V_11 = V_152 ;
V_40 [ 0 ] . V_59 = V_88 | V_154 | V_155 ;
F_13 ( & V_151 -> V_7 , V_39 -> V_6 . V_7 . V_26 , V_39 , V_25 , V_40 ) ;
return V_151 ;
}
static struct V_5 * F_99 ( struct V_5 * V_6 ,
const char * V_20 , int V_21 )
{
struct V_38 * V_39 = V_6 -> V_7 . V_39 ;
struct V_5 * V_156 , * V_151 = NULL ;
int V_46 ;
F_28 ( & V_50 ) ;
V_156 = F_96 ( V_6 , V_20 , V_21 ) ;
if ( ! F_56 ( V_156 ) )
goto V_157;
if ( F_64 ( V_156 ) != - V_53 )
goto V_158;
F_26 ( & V_50 ) ;
V_151 = F_97 ( V_39 , V_20 , V_21 ) ;
F_28 ( & V_50 ) ;
V_156 = F_29 ( - V_99 ) ;
if ( ! V_151 )
goto V_158;
V_156 = F_96 ( V_6 , V_20 , V_21 ) ;
if ( ! F_56 ( V_156 ) )
goto V_157;
if ( F_64 ( V_156 ) != - V_53 )
goto V_158;
V_46 = F_16 ( V_6 , & V_151 -> V_7 ) ;
V_156 = F_29 ( V_46 ) ;
if ( V_46 )
goto V_158;
V_156 = V_151 ;
V_157:
V_156 -> V_7 . V_44 ++ ;
V_158:
if ( F_21 ( F_56 ( V_156 ) ) ) {
F_5 ( V_35 L_6 ) ;
F_4 ( V_6 ) ;
F_5 ( V_9 L_7 ,
V_21 , V_21 , V_20 , F_64 ( V_156 ) ) ;
}
F_19 ( & V_6 -> V_7 ) ;
if ( V_151 )
F_19 ( & V_151 -> V_7 ) ;
F_26 ( & V_50 ) ;
return V_156 ;
}
static struct V_5 * F_100 ( struct V_38 * V_39 , struct V_5 * V_6 )
{
struct V_5 * V_8 ;
const char * V_11 ;
if ( ! V_6 -> V_7 . V_8 )
return & V_39 -> V_6 ;
V_8 = F_100 ( V_39 , V_6 -> V_7 . V_8 ) ;
if ( F_56 ( V_8 ) )
return V_8 ;
V_11 = V_6 -> V_7 . V_10 [ 0 ] . V_11 ;
return F_96 ( V_8 , V_11 , strlen ( V_11 ) ) ;
}
static int F_60 ( struct V_18 * * V_19 ,
struct V_10 * * V_58 , struct V_54 * V_55 )
{
struct V_18 * V_22 ;
struct V_37 * V_26 ;
struct V_38 * V_39 ;
struct V_10 * V_23 ;
struct V_5 * V_6 ;
int V_97 ;
V_97 = 0 ;
F_28 ( & V_50 ) ;
V_26 = ( * V_58 ) -> V_159 ;
V_39 = F_36 ( V_26 , V_55 ) ;
V_6 = F_100 ( V_39 , ( * V_19 ) -> V_8 ) ;
if ( F_56 ( V_6 ) )
V_97 = F_64 ( V_6 ) ;
else {
const char * V_11 = ( * V_58 ) -> V_11 ;
V_22 = NULL ;
V_23 = F_7 ( & V_22 , V_6 , V_11 , strlen ( V_11 ) ) ;
V_97 = - V_53 ;
if ( V_23 && F_20 ( V_22 ) ) {
F_22 ( * V_19 ) ;
* V_19 = V_22 ;
* V_58 = V_23 ;
V_97 = 0 ;
}
}
F_26 ( & V_50 ) ;
return V_97 ;
}
static int F_101 ( const char * V_160 , struct V_10 * V_40 , char * V_161 , ... )
{
struct V_162 V_163 ;
T_8 args ;
va_start ( args , V_161 ) ;
V_163 . V_161 = V_161 ;
V_163 . V_164 = & args ;
F_5 ( V_35 L_8 ,
V_160 , V_40 -> V_11 , & V_163 ) ;
va_end ( args ) ;
return - V_51 ;
}
static int F_102 ( const char * V_160 , struct V_10 * V_40 )
{
int V_46 = 0 ;
for (; V_40 -> V_11 ; V_40 ++ ) {
if ( V_40 -> V_121 )
V_46 = F_101 ( V_160 , V_40 , L_9 ) ;
if ( ( V_40 -> V_111 == V_165 ) ||
( V_40 -> V_111 == V_166 ) ||
( V_40 -> V_111 == V_167 ) ||
( V_40 -> V_111 == V_168 ) ||
( V_40 -> V_111 == V_169 ) ||
( V_40 -> V_111 == V_170 ) ||
( V_40 -> V_111 == V_171 ) ||
( V_40 -> V_111 == V_172 ) ) {
if ( ! V_40 -> V_159 )
V_46 = F_101 ( V_160 , V_40 , L_10 ) ;
if ( ! V_40 -> V_173 )
V_46 = F_101 ( V_160 , V_40 , L_11 ) ;
}
if ( ! V_40 -> V_111 )
V_46 = F_101 ( V_160 , V_40 , L_12 ) ;
if ( ( V_40 -> V_59 & ( V_154 | V_174 ) ) != V_40 -> V_59 )
V_46 = F_101 ( V_160 , V_40 , L_13 ,
V_40 -> V_59 ) ;
}
return V_46 ;
}
static struct V_18 * F_103 ( struct V_5 * V_6 , struct V_10 * V_40 ,
struct V_37 * V_175 )
{
struct V_10 * V_176 , * V_23 , * V_177 ;
struct V_18 * V_178 ;
struct V_27 * V_25 ;
char * V_179 ;
int V_180 , V_181 ;
V_181 = 0 ;
V_180 = 0 ;
for ( V_23 = V_40 ; V_23 -> V_11 ; V_23 ++ ) {
V_180 ++ ;
V_181 += strlen ( V_23 -> V_11 ) + 1 ;
}
V_178 = F_98 ( sizeof( struct V_18 ) +
sizeof( struct V_27 ) * V_180 +
sizeof( struct V_10 ) * ( V_180 + 1 ) +
V_181 ,
V_153 ) ;
if ( ! V_178 )
return NULL ;
V_25 = (struct V_27 * ) ( V_178 + 1 ) ;
V_176 = (struct V_10 * ) ( V_25 + V_180 ) ;
V_179 = ( char * ) & V_176 [ V_180 + 1 ] ;
for ( V_177 = V_176 , V_23 = V_40 ; V_23 -> V_11 ; V_177 ++ , V_23 ++ ) {
int V_98 = strlen ( V_23 -> V_11 ) + 1 ;
memcpy ( V_179 , V_23 -> V_11 , V_98 ) ;
V_177 -> V_11 = V_179 ;
V_177 -> V_59 = V_182 | V_183 ;
V_177 -> V_159 = V_175 ;
V_179 += V_98 ;
}
F_13 ( V_178 , V_6 -> V_7 . V_26 , V_6 -> V_7 . V_39 , V_25 , V_176 ) ;
V_178 -> V_44 = V_180 ;
return V_178 ;
}
static bool F_104 ( struct V_5 * V_6 ,
struct V_10 * V_40 , struct V_37 * V_175 )
{
struct V_18 * V_22 ;
struct V_10 * V_23 , * V_177 ;
for ( V_23 = V_40 ; V_23 -> V_11 ; V_23 ++ ) {
const char * V_11 = V_23 -> V_11 ;
V_177 = F_7 ( & V_22 , V_6 , V_11 , strlen ( V_11 ) ) ;
if ( ! V_177 )
return false ;
if ( F_53 ( V_177 -> V_59 ) && F_53 ( V_23 -> V_59 ) )
continue;
if ( F_59 ( V_177 -> V_59 ) && ( V_177 -> V_159 == V_175 ) )
continue;
return false ;
}
for ( V_23 = V_40 ; V_23 -> V_11 ; V_23 ++ ) {
const char * V_11 = V_23 -> V_11 ;
V_177 = F_7 ( & V_22 , V_6 , V_11 , strlen ( V_11 ) ) ;
V_22 -> V_44 ++ ;
}
return true ;
}
static int F_17 ( struct V_18 * V_22 )
{
struct V_38 * V_184 = & V_91 . V_56 ;
struct V_5 * V_185 = NULL ;
struct V_18 * V_178 ;
int V_46 ;
if ( V_22 -> V_39 == V_184 )
return 0 ;
V_185 = F_100 ( V_184 , V_22 -> V_8 ) ;
if ( F_56 ( V_185 ) )
return 0 ;
if ( F_104 ( V_185 , V_22 -> V_10 , V_22 -> V_26 ) )
return 0 ;
V_185 -> V_7 . V_44 ++ ;
F_26 ( & V_50 ) ;
V_178 = F_103 ( V_185 , V_22 -> V_10 , V_22 -> V_26 ) ;
F_28 ( & V_50 ) ;
V_46 = - V_99 ;
if ( ! V_178 )
goto V_74;
V_46 = 0 ;
if ( F_104 ( V_185 , V_22 -> V_10 , V_22 -> V_26 ) ) {
F_105 ( V_178 ) ;
goto V_74;
}
V_46 = F_16 ( V_185 , V_178 ) ;
if ( V_46 )
F_105 ( V_178 ) ;
V_74:
F_19 ( & V_185 -> V_7 ) ;
return V_46 ;
}
struct V_18 * F_106 (
struct V_38 * V_39 ,
const char * V_160 , struct V_10 * V_40 )
{
struct V_37 * V_26 = V_39 -> V_6 . V_7 . V_26 ;
struct V_18 * V_7 ;
const char * V_20 , * V_186 ;
struct V_5 * V_6 ;
struct V_10 * V_23 ;
struct V_27 * V_25 ;
int V_180 = 0 ;
for ( V_23 = V_40 ; V_23 -> V_11 ; V_23 ++ )
V_180 ++ ;
V_7 = F_98 ( sizeof( struct V_18 ) +
sizeof( struct V_27 ) * V_180 , V_153 ) ;
if ( ! V_7 )
return NULL ;
V_25 = (struct V_27 * ) ( V_7 + 1 ) ;
F_13 ( V_7 , V_26 , V_39 , V_25 , V_40 ) ;
if ( F_102 ( V_160 , V_40 ) )
goto V_48;
F_28 ( & V_50 ) ;
V_6 = & V_39 -> V_6 ;
V_6 -> V_7 . V_44 ++ ;
F_26 ( & V_50 ) ;
for ( V_20 = V_160 ; V_20 ; V_20 = V_186 ) {
int V_21 ;
V_186 = strchr ( V_20 , '/' ) ;
if ( V_186 ) {
V_21 = V_186 - V_20 ;
V_186 ++ ;
} else {
V_21 = strlen ( V_20 ) ;
}
if ( V_21 == 0 )
continue;
V_6 = F_99 ( V_6 , V_20 , V_21 ) ;
if ( F_56 ( V_6 ) )
goto V_48;
}
F_28 ( & V_50 ) ;
if ( F_16 ( V_6 , V_7 ) )
goto V_187;
F_19 ( & V_6 -> V_7 ) ;
F_26 ( & V_50 ) ;
return V_7 ;
V_187:
F_19 ( & V_6 -> V_7 ) ;
F_26 ( & V_50 ) ;
V_48:
F_105 ( V_7 ) ;
F_107 () ;
return NULL ;
}
struct V_18 * F_108 ( const char * V_160 , struct V_10 * V_40 )
{
return F_106 ( & V_91 . V_56 ,
V_160 , V_40 ) ;
}
static char * F_109 ( const char * V_160 , char * V_128 , const char * V_20 )
{
int V_21 ;
V_21 = strlen ( V_20 ) ;
if ( ( ( V_128 - V_160 ) + V_21 + 2 ) >= V_188 )
return NULL ;
memcpy ( V_128 , V_20 , V_21 ) ;
V_128 [ V_21 ] = '/' ;
V_128 [ V_21 + 1 ] = '\0' ;
V_128 += V_21 + 1 ;
return V_128 ;
}
static int F_110 ( struct V_10 * V_40 )
{
int V_189 = 0 ;
int V_190 = 0 ;
struct V_10 * V_23 ;
if ( ! V_40 || ! V_40 -> V_11 )
return 1 ;
for ( V_23 = V_40 ; V_23 -> V_11 ; V_23 ++ ) {
if ( V_23 -> V_121 )
V_190 += F_110 ( V_23 -> V_121 ) ;
else
V_189 = 1 ;
}
return V_190 + V_189 ;
}
static int F_111 ( const char * V_160 , char * V_128 ,
struct V_18 * * * V_191 , struct V_38 * V_39 ,
struct V_10 * V_40 )
{
struct V_10 * V_41 = NULL ;
struct V_10 * V_23 , * V_192 ;
int V_193 = 0 ;
int V_194 = 0 ;
int V_46 = - V_99 ;
for ( V_23 = V_40 ; V_23 -> V_11 ; V_23 ++ ) {
if ( V_23 -> V_121 )
V_194 ++ ;
else
V_193 ++ ;
}
V_192 = V_40 ;
if ( V_194 && V_193 ) {
struct V_10 * V_151 ;
V_192 = F_98 ( sizeof( struct V_10 ) * ( V_193 + 1 ) ,
V_153 ) ;
if ( ! V_192 )
goto V_74;
V_41 = V_192 ;
for ( V_151 = V_192 , V_23 = V_40 ; V_23 -> V_11 ; V_23 ++ ) {
if ( V_23 -> V_121 )
continue;
* V_151 = * V_23 ;
V_151 ++ ;
}
}
if ( V_193 || ! V_194 ) {
struct V_18 * V_7 ;
V_7 = F_106 ( V_39 , V_160 , V_192 ) ;
if ( ! V_7 ) {
F_105 ( V_41 ) ;
goto V_74;
}
V_7 -> V_41 = V_41 ;
* * V_191 = V_7 ;
( * V_191 ) ++ ;
}
for ( V_23 = V_40 ; V_23 -> V_11 ; V_23 ++ ) {
char * V_195 ;
if ( ! V_23 -> V_121 )
continue;
V_46 = - V_196 ;
V_195 = F_109 ( V_160 , V_128 , V_23 -> V_11 ) ;
if ( ! V_195 )
goto V_74;
V_46 = F_111 ( V_160 , V_195 , V_191 ,
V_39 , V_23 -> V_121 ) ;
V_128 [ 0 ] = '\0' ;
if ( V_46 )
goto V_74;
}
V_46 = 0 ;
V_74:
return V_46 ;
}
struct V_18 * F_112 (
struct V_38 * V_39 ,
const struct V_197 * V_160 , struct V_10 * V_40 )
{
struct V_10 * V_41 = V_40 ;
int V_190 = F_110 ( V_40 ) ;
struct V_18 * V_7 = NULL , * * V_198 , * * V_191 ;
const struct V_197 * V_199 ;
char * V_200 , * V_128 ;
V_128 = V_200 = F_113 ( V_188 , V_153 ) ;
if ( ! V_200 )
return NULL ;
V_128 [ 0 ] = '\0' ;
for ( V_199 = V_160 ; V_199 -> V_11 ; V_199 ++ ) {
V_128 = F_109 ( V_200 , V_128 , V_199 -> V_11 ) ;
if ( ! V_128 )
goto V_74;
}
while ( V_40 -> V_11 && V_40 -> V_121 && ! V_40 [ 1 ] . V_11 ) {
V_128 = F_109 ( V_200 , V_128 , V_40 -> V_11 ) ;
if ( ! V_128 )
goto V_74;
V_40 = V_40 -> V_121 ;
}
if ( V_190 == 1 ) {
V_7 = F_106 ( V_39 , V_200 , V_40 ) ;
if ( V_7 )
V_7 -> V_41 = V_41 ;
} else {
V_7 = F_98 ( sizeof( * V_7 ) +
sizeof( * V_198 ) * V_190 , V_153 ) ;
if ( ! V_7 )
goto V_74;
V_198 = (struct V_18 * * ) ( V_7 + 1 ) ;
V_191 = V_198 ;
V_7 -> V_41 = V_41 ;
if ( F_111 ( V_200 , V_128 , & V_191 ,
V_39 , V_40 ) )
goto V_201;
}
V_74:
F_105 ( V_200 ) ;
return V_7 ;
V_201:
while ( V_191 > V_198 ) {
struct V_18 * V_202 = * ( -- V_191 ) ;
struct V_10 * V_40 = V_202 -> V_41 ;
F_114 ( V_202 ) ;
F_105 ( V_40 ) ;
}
F_105 ( V_7 ) ;
V_7 = NULL ;
goto V_74;
}
struct V_18 * F_115 ( const struct V_197 * V_160 ,
struct V_10 * V_40 )
{
return F_112 ( & V_91 . V_56 ,
V_160 , V_40 ) ;
}
struct V_18 * F_116 ( struct V_10 * V_40 )
{
static const struct V_197 V_203 [] = { {} } ;
return F_115 ( V_203 , V_40 ) ;
}
static void F_18 ( struct V_18 * V_7 )
{
struct V_38 * V_184 = & V_91 . V_56 ;
struct V_37 * V_26 = V_7 -> V_26 ;
struct V_5 * V_8 = V_7 -> V_8 ;
struct V_5 * V_185 ;
struct V_10 * V_23 ;
if ( V_7 -> V_39 == V_184 )
return;
V_185 = F_100 ( V_184 , V_8 ) ;
if ( F_56 ( V_185 ) )
return;
for ( V_23 = V_7 -> V_10 ; V_23 -> V_11 ; V_23 ++ ) {
struct V_18 * V_204 ;
struct V_10 * V_177 ;
const char * V_20 = V_23 -> V_11 ;
V_177 = F_7 ( & V_204 , V_185 , V_20 , strlen ( V_20 ) ) ;
if ( V_177 &&
( ( F_53 ( V_177 -> V_59 ) && F_53 ( V_23 -> V_59 ) ) ||
( F_59 ( V_177 -> V_59 ) && ( V_177 -> V_159 == V_26 ) ) ) ) {
F_19 ( V_204 ) ;
}
else {
F_5 ( V_35 L_14 ) ;
F_4 ( V_8 ) ;
F_5 ( V_9 L_3 , V_20 ) ;
}
}
}
static void F_19 ( struct V_18 * V_7 )
{
struct V_5 * V_8 = V_7 -> V_8 ;
if ( -- V_7 -> V_44 )
return;
F_18 ( V_7 ) ;
F_24 ( V_7 ) ;
if ( ! -- V_7 -> V_43 )
F_32 ( V_7 , V_52 ) ;
if ( V_8 )
F_19 ( & V_8 -> V_7 ) ;
}
void F_114 ( struct V_18 * V_7 )
{
int V_190 ;
F_117 () ;
if ( V_7 == NULL )
return;
V_190 = F_110 ( V_7 -> V_41 ) ;
if ( F_21 ( V_190 > 1 ) ) {
struct V_18 * * V_198 ;
int V_205 ;
V_198 = (struct V_18 * * ) ( V_7 + 1 ) ;
for ( V_205 = V_190 - 1 ; V_205 >= 0 ; V_205 -- ) {
struct V_18 * V_202 = V_198 [ V_205 ] ;
struct V_10 * V_40 = V_202 -> V_41 ;
F_114 ( V_202 ) ;
F_105 ( V_40 ) ;
}
F_105 ( V_7 ) ;
return;
}
F_28 ( & V_50 ) ;
F_19 ( V_7 ) ;
F_26 ( & V_50 ) ;
}
void F_118 ( struct V_38 * V_39 ,
struct V_37 * V_26 ,
int (* V_147)( struct V_38 * ) )
{
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_147 = V_147 ;
F_13 ( & V_39 -> V_6 . V_7 , V_26 , V_39 , NULL , V_206 ) ;
}
void F_119 ( struct V_38 * V_39 )
{
F_120 ( ! F_121 ( & V_39 -> V_6 . V_26 ) ) ;
}
int T_9 F_122 ( void )
{
struct V_207 * V_208 ;
V_208 = F_123 ( L_15 , NULL ) ;
V_208 -> V_209 = & V_89 ;
V_208 -> V_210 = & V_90 ;
V_208 -> V_211 = 0 ;
return F_124 () ;
}
