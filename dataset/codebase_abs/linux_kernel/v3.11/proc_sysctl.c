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
F_5 ( L_1 , V_6 -> V_7 . V_9 [ 0 ] . V_10 ) ;
}
static int F_6 ( const char * V_11 , int V_12 , const char * V_13 , int V_14 )
{
int V_15 ;
int V_16 ;
V_15 = V_12 ;
if ( V_15 > V_14 )
V_15 = V_14 ;
V_16 = memcmp ( V_11 , V_13 , V_15 ) ;
if ( V_16 == 0 )
V_16 = V_12 - V_14 ;
return V_16 ;
}
static struct V_9 * F_7 ( struct V_17 * * V_18 ,
struct V_5 * V_6 , const char * V_19 , int V_20 )
{
struct V_17 * V_21 ;
struct V_9 * V_22 ;
struct V_23 * V_24 = V_6 -> V_25 . V_23 ;
while ( V_24 )
{
struct V_26 * V_26 ;
const char * V_10 ;
int V_16 ;
V_26 = F_8 ( V_24 , struct V_26 , V_24 ) ;
V_21 = V_26 -> V_7 ;
V_22 = & V_21 -> V_9 [ V_26 - V_21 -> V_24 ] ;
V_10 = V_22 -> V_10 ;
V_16 = F_6 ( V_19 , V_20 , V_10 , strlen ( V_10 ) ) ;
if ( V_16 < 0 )
V_24 = V_24 -> V_27 ;
else if ( V_16 > 0 )
V_24 = V_24 -> V_28 ;
else {
* V_18 = V_21 ;
return V_22 ;
}
}
return NULL ;
}
static int F_9 ( struct V_17 * V_21 , struct V_9 * V_22 )
{
struct V_23 * V_24 = & V_21 -> V_24 [ V_22 - V_21 -> V_9 ] . V_24 ;
struct V_23 * * V_29 = & V_21 -> V_8 -> V_25 . V_23 ;
struct V_23 * V_8 = NULL ;
const char * V_19 = V_22 -> V_10 ;
int V_20 = strlen ( V_19 ) ;
while ( * V_29 ) {
struct V_17 * V_30 ;
struct V_9 * V_31 ;
struct V_26 * V_32 ;
const char * V_33 ;
int V_16 ;
V_8 = * V_29 ;
V_32 = F_8 ( V_8 , struct V_26 , V_24 ) ;
V_30 = V_32 -> V_7 ;
V_31 = & V_30 -> V_9 [ V_32 - V_30 -> V_24 ] ;
V_33 = V_31 -> V_10 ;
V_16 = F_6 ( V_19 , V_20 , V_33 , strlen ( V_33 ) ) ;
if ( V_16 < 0 )
V_29 = & ( * V_29 ) -> V_27 ;
else if ( V_16 > 0 )
V_29 = & ( * V_29 ) -> V_28 ;
else {
F_10 ( L_2 ) ;
F_4 ( V_21 -> V_8 ) ;
F_5 ( L_3 , V_22 -> V_10 ) ;
return - V_34 ;
}
}
F_11 ( V_24 , V_8 , V_29 ) ;
F_12 ( V_24 , & V_21 -> V_8 -> V_25 ) ;
return 0 ;
}
static void F_13 ( struct V_17 * V_21 , struct V_9 * V_22 )
{
struct V_23 * V_24 = & V_21 -> V_24 [ V_22 - V_21 -> V_9 ] . V_24 ;
F_14 ( V_24 , & V_21 -> V_8 -> V_25 ) ;
}
static void F_15 ( struct V_17 * V_21 ,
struct V_35 * V_25 , struct V_36 * V_37 ,
struct V_26 * V_24 , struct V_9 * V_38 )
{
V_21 -> V_9 = V_38 ;
V_21 -> V_39 = V_38 ;
V_21 -> V_40 = 0 ;
V_21 -> V_41 = 1 ;
V_21 -> V_42 = 1 ;
V_21 -> V_43 = NULL ;
V_21 -> V_25 = V_25 ;
V_21 -> V_37 = V_37 ;
V_21 -> V_8 = NULL ;
V_21 -> V_24 = V_24 ;
if ( V_24 ) {
struct V_9 * V_22 ;
for ( V_22 = V_38 ; V_22 -> V_10 ; V_22 ++ , V_24 ++ )
V_24 -> V_7 = V_21 ;
}
}
static void F_16 ( struct V_17 * V_21 )
{
struct V_9 * V_22 ;
for ( V_22 = V_21 -> V_9 ; V_22 -> V_10 ; V_22 ++ )
F_13 ( V_21 , V_22 ) ;
}
static int F_17 ( struct V_5 * V_6 , struct V_17 * V_7 )
{
struct V_9 * V_22 ;
int V_44 ;
V_6 -> V_7 . V_42 ++ ;
V_7 -> V_8 = V_6 ;
V_44 = F_18 ( V_7 ) ;
if ( V_44 )
goto V_45;
for ( V_22 = V_7 -> V_9 ; V_22 -> V_10 ; V_22 ++ ) {
V_44 = F_9 ( V_7 , V_22 ) ;
if ( V_44 )
goto V_46;
}
return 0 ;
V_46:
F_16 ( V_7 ) ;
F_19 ( V_7 ) ;
V_45:
V_7 -> V_8 = NULL ;
F_20 ( & V_6 -> V_7 ) ;
return V_44 ;
}
static int F_21 ( struct V_17 * V_29 )
{
if ( F_22 ( V_29 -> V_43 ) )
return 0 ;
V_29 -> V_40 ++ ;
return 1 ;
}
static void F_23 ( struct V_17 * V_29 )
{
if ( ! -- V_29 -> V_40 )
if ( F_22 ( V_29 -> V_43 ) )
F_24 ( V_29 -> V_43 ) ;
}
static void F_25 ( struct V_17 * V_29 )
{
if ( F_22 ( V_29 -> V_40 ) ) {
struct V_47 V_4 ;
F_26 ( & V_4 ) ;
V_29 -> V_43 = & V_4 ;
F_27 ( & V_48 ) ;
F_28 ( & V_4 ) ;
F_29 ( & V_48 ) ;
} else {
V_29 -> V_43 = F_30 ( - V_49 ) ;
}
F_16 ( V_29 ) ;
}
static void F_31 ( struct V_17 * V_21 )
{
F_29 ( & V_48 ) ;
V_21 -> V_41 ++ ;
F_27 ( & V_48 ) ;
}
void F_32 ( struct V_17 * V_21 )
{
F_29 ( & V_48 ) ;
if ( ! -- V_21 -> V_41 )
F_33 ( V_21 , V_50 ) ;
F_27 ( & V_48 ) ;
}
static struct V_17 * F_34 ( struct V_17 * V_21 )
{
F_35 ( ! V_21 ) ;
F_29 ( & V_48 ) ;
if ( ! F_21 ( V_21 ) )
V_21 = F_30 ( - V_51 ) ;
F_27 ( & V_48 ) ;
return V_21 ;
}
static void F_36 ( struct V_17 * V_21 )
{
if ( ! V_21 )
return;
F_29 ( & V_48 ) ;
F_23 ( V_21 ) ;
F_27 ( & V_48 ) ;
}
static struct V_36 *
F_37 ( struct V_35 * V_25 , struct V_52 * V_53 )
{
struct V_36 * V_37 = & V_25 -> V_54 ;
if ( V_25 -> V_55 )
V_37 = V_25 -> V_55 ( V_25 , V_53 ) ;
return V_37 ;
}
static struct V_9 * F_38 ( struct V_17 * * V_18 ,
struct V_5 * V_6 ,
const char * V_19 , int V_20 )
{
struct V_17 * V_21 ;
struct V_9 * V_22 ;
F_29 ( & V_48 ) ;
V_22 = F_7 ( & V_21 , V_6 , V_19 , V_20 ) ;
if ( V_22 && F_21 ( V_21 ) )
* V_18 = V_21 ;
else
V_22 = NULL ;
F_27 ( & V_48 ) ;
return V_22 ;
}
static struct V_26 * F_39 ( struct V_23 * V_24 )
{
struct V_26 * V_26 ;
for (; V_24 ; V_24 = F_40 ( V_24 ) ) {
V_26 = F_8 ( V_24 , struct V_26 , V_24 ) ;
if ( F_21 ( V_26 -> V_7 ) )
return V_26 ;
}
return NULL ;
}
static void F_41 ( struct V_5 * V_6 ,
struct V_17 * * V_18 , struct V_9 * * V_56 )
{
struct V_17 * V_21 = NULL ;
struct V_9 * V_22 = NULL ;
struct V_26 * V_26 ;
F_29 ( & V_48 ) ;
V_26 = F_39 ( F_42 ( & V_6 -> V_25 ) ) ;
F_27 ( & V_48 ) ;
if ( V_26 ) {
V_21 = V_26 -> V_7 ;
V_22 = & V_21 -> V_9 [ V_26 - V_21 -> V_24 ] ;
}
* V_18 = V_21 ;
* V_56 = V_22 ;
}
static void F_43 ( struct V_17 * * V_18 , struct V_9 * * V_56 )
{
struct V_17 * V_21 = * V_18 ;
struct V_9 * V_22 = * V_56 ;
struct V_26 * V_26 = & V_21 -> V_24 [ V_22 - V_21 -> V_9 ] ;
F_29 ( & V_48 ) ;
F_23 ( V_21 ) ;
V_26 = F_39 ( F_40 ( & V_26 -> V_24 ) ) ;
F_27 ( & V_48 ) ;
V_21 = NULL ;
if ( V_26 ) {
V_21 = V_26 -> V_7 ;
V_22 = & V_21 -> V_9 [ V_26 - V_21 -> V_24 ] ;
}
* V_18 = V_21 ;
* V_56 = V_22 ;
}
void F_44 ( struct V_35 * V_25 )
{
}
static int F_45 ( int V_57 , int V_58 )
{
if ( F_46 ( F_47 () , V_59 ) )
V_57 >>= 6 ;
else if ( F_48 ( V_60 ) )
V_57 >>= 3 ;
if ( ( V_58 & ~ V_57 & ( V_61 | V_62 | V_63 ) ) == 0 )
return 0 ;
return - V_64 ;
}
static int F_49 ( struct V_17 * V_21 , struct V_9 * V_38 , int V_58 )
{
struct V_35 * V_25 = V_21 -> V_25 ;
int V_57 ;
if ( V_25 -> V_65 )
V_57 = V_25 -> V_65 ( V_21 , V_38 ) ;
else
V_57 = V_38 -> V_57 ;
return F_45 ( V_57 , V_58 ) ;
}
static struct V_66 * F_50 ( struct V_67 * V_68 ,
struct V_17 * V_21 , struct V_9 * V_38 )
{
struct V_66 * V_66 ;
struct V_69 * V_70 ;
V_66 = F_51 ( V_68 ) ;
if ( ! V_66 )
goto V_71;
V_66 -> V_72 = F_52 () ;
F_31 ( V_21 ) ;
V_70 = F_53 ( V_66 ) ;
V_70 -> V_73 = V_21 ;
V_70 -> V_74 = V_38 ;
V_66 -> V_75 = V_66 -> V_76 = V_66 -> V_77 = V_78 ;
V_66 -> V_79 = V_38 -> V_57 ;
if ( ! F_54 ( V_38 -> V_57 ) ) {
V_66 -> V_79 |= V_80 ;
V_66 -> V_81 = & V_82 ;
V_66 -> V_83 = & V_84 ;
} else {
V_66 -> V_79 |= V_85 ;
V_66 -> V_81 = & V_86 ;
V_66 -> V_83 = & V_87 ;
}
V_71:
return V_66 ;
}
static struct V_17 * F_55 ( struct V_66 * V_66 )
{
struct V_17 * V_21 = F_53 ( V_66 ) -> V_73 ;
if ( ! V_21 )
V_21 = & V_88 . V_54 . V_6 . V_7 ;
return F_34 ( V_21 ) ;
}
static struct V_89 * F_56 ( struct V_66 * V_6 , struct V_89 * V_89 ,
unsigned int V_90 )
{
struct V_17 * V_21 = F_55 ( V_6 ) ;
struct V_17 * V_91 = NULL ;
struct V_92 * V_19 = & V_89 -> V_93 ;
struct V_9 * V_29 ;
struct V_66 * V_66 ;
struct V_89 * V_44 = F_30 ( - V_51 ) ;
struct V_5 * V_5 ;
int V_94 ;
if ( F_57 ( V_21 ) )
return F_58 ( V_21 ) ;
V_5 = F_59 ( V_21 , struct V_5 , V_7 ) ;
V_29 = F_38 ( & V_91 , V_5 , V_19 -> V_19 , V_19 -> V_95 ) ;
if ( ! V_29 )
goto V_71;
if ( F_60 ( V_29 -> V_57 ) ) {
V_94 = F_61 ( & V_91 , & V_29 , V_96 -> V_52 ) ;
V_44 = F_30 ( V_94 ) ;
if ( V_94 )
goto V_71;
}
V_44 = F_30 ( - V_97 ) ;
V_66 = F_50 ( V_6 -> V_98 , V_91 ? V_91 : V_21 , V_29 ) ;
if ( ! V_66 )
goto V_71;
V_44 = NULL ;
F_62 ( V_89 , & V_99 ) ;
F_63 ( V_89 , V_66 ) ;
V_71:
if ( V_91 )
F_36 ( V_91 ) ;
F_36 ( V_21 ) ;
return V_44 ;
}
static T_1 F_64 ( struct V_100 * V_101 , void T_2 * V_102 ,
T_3 V_41 , T_4 * V_103 , int V_104 )
{
struct V_66 * V_66 = F_65 ( V_101 ) ;
struct V_17 * V_21 = F_55 ( V_66 ) ;
struct V_9 * V_38 = F_53 ( V_66 ) -> V_74 ;
T_1 error ;
T_3 V_105 ;
if ( F_57 ( V_21 ) )
return F_66 ( V_21 ) ;
error = - V_106 ;
if ( F_49 ( V_21 , V_38 , V_104 ? V_62 : V_61 ) )
goto V_71;
error = - V_49 ;
if ( ! V_38 -> V_107 )
goto V_71;
V_105 = V_41 ;
error = V_38 -> V_107 ( V_38 , V_104 , V_102 , & V_105 , V_103 ) ;
if ( ! error )
error = V_105 ;
V_71:
F_36 ( V_21 ) ;
return error ;
}
static T_1 F_67 ( struct V_100 * V_101 , char T_2 * V_102 ,
T_3 V_41 , T_4 * V_103 )
{
return F_64 ( V_101 , ( void T_2 * ) V_102 , V_41 , V_103 , 0 ) ;
}
static T_1 F_68 ( struct V_100 * V_101 , const char T_2 * V_102 ,
T_3 V_41 , T_4 * V_103 )
{
return F_64 ( V_101 , ( void T_2 * ) V_102 , V_41 , V_103 , 1 ) ;
}
static int F_69 ( struct V_66 * V_66 , struct V_100 * V_101 )
{
struct V_17 * V_21 = F_55 ( V_66 ) ;
struct V_9 * V_38 = F_53 ( V_66 ) -> V_74 ;
if ( F_57 ( V_21 ) )
return F_66 ( V_21 ) ;
if ( V_38 -> V_2 )
V_101 -> V_108 = F_70 ( V_38 -> V_2 ) ;
F_36 ( V_21 ) ;
return 0 ;
}
static unsigned int F_71 ( struct V_100 * V_101 , T_5 * V_4 )
{
struct V_66 * V_66 = F_65 ( V_101 ) ;
struct V_17 * V_21 = F_55 ( V_66 ) ;
struct V_9 * V_38 = F_53 ( V_66 ) -> V_74 ;
unsigned int V_94 = V_109 ;
unsigned long V_3 ;
if ( F_57 ( V_21 ) )
return V_110 | V_111 ;
if ( ! V_38 -> V_107 )
goto V_71;
if ( ! V_38 -> V_2 )
goto V_71;
V_3 = ( unsigned long ) V_101 -> V_108 ;
F_72 ( V_101 , & V_38 -> V_2 -> V_4 , V_4 ) ;
if ( V_3 != F_73 ( & V_38 -> V_2 -> V_3 ) ) {
V_101 -> V_108 = F_70 ( V_38 -> V_2 ) ;
V_94 = V_112 | V_113 | V_110 | V_114 ;
}
V_71:
F_36 ( V_21 ) ;
return V_94 ;
}
static bool F_74 ( struct V_100 * V_100 ,
struct V_115 * V_116 ,
struct V_17 * V_21 ,
struct V_9 * V_38 )
{
struct V_89 * V_117 , * V_6 = V_100 -> V_118 . V_89 ;
struct V_66 * V_66 ;
struct V_92 V_119 ;
T_6 V_120 = 0 ;
unsigned type = V_121 ;
V_119 . V_19 = V_38 -> V_10 ;
V_119 . V_95 = strlen ( V_38 -> V_10 ) ;
V_119 . V_122 = F_75 ( V_119 . V_19 , V_119 . V_95 ) ;
V_117 = F_76 ( V_6 , & V_119 ) ;
if ( ! V_117 ) {
V_117 = F_77 ( V_6 , & V_119 ) ;
if ( V_117 ) {
V_66 = F_50 ( V_6 -> V_123 , V_21 , V_38 ) ;
if ( ! V_66 ) {
F_78 ( V_117 ) ;
return false ;
} else {
F_62 ( V_117 , & V_99 ) ;
F_63 ( V_117 , V_66 ) ;
}
} else {
return false ;
}
}
V_66 = V_117 -> V_124 ;
V_120 = V_66 -> V_72 ;
type = V_66 -> V_79 >> 12 ;
F_78 ( V_117 ) ;
return F_79 ( V_116 , V_119 . V_19 , V_119 . V_95 , V_120 , type ) ;
}
static bool F_80 ( struct V_100 * V_100 ,
struct V_115 * V_116 ,
struct V_17 * V_21 ,
struct V_9 * V_38 )
{
bool V_94 = true ;
V_21 = F_34 ( V_21 ) ;
if ( F_60 ( V_38 -> V_57 ) ) {
int V_44 = F_61 ( & V_21 , & V_38 , V_96 -> V_52 ) ;
if ( V_44 )
goto V_71;
}
V_94 = F_74 ( V_100 , V_116 , V_21 , V_38 ) ;
V_71:
F_36 ( V_21 ) ;
return V_94 ;
}
static int F_81 ( struct V_17 * V_21 , V_9 * V_38 ,
unsigned long * V_125 , struct V_100 * V_100 ,
struct V_115 * V_116 )
{
bool V_105 ;
if ( ( * V_125 ) ++ < V_116 -> V_125 )
return true ;
if ( F_22 ( F_60 ( V_38 -> V_57 ) ) )
V_105 = F_80 ( V_100 , V_116 , V_21 , V_38 ) ;
else
V_105 = F_74 ( V_100 , V_116 , V_21 , V_38 ) ;
if ( V_105 )
V_116 -> V_125 = * V_125 ;
return V_105 ;
}
static int F_82 ( struct V_100 * V_100 , struct V_115 * V_116 )
{
struct V_17 * V_21 = F_55 ( F_65 ( V_100 ) ) ;
struct V_17 * V_91 = NULL ;
struct V_9 * V_22 ;
struct V_5 * V_5 ;
unsigned long V_125 ;
if ( F_57 ( V_21 ) )
return F_66 ( V_21 ) ;
V_5 = F_59 ( V_21 , struct V_5 , V_7 ) ;
if ( ! F_83 ( V_100 , V_116 ) )
return 0 ;
V_125 = 2 ;
for ( F_41 ( V_5 , & V_91 , & V_22 ) ; V_91 ; F_43 ( & V_91 , & V_22 ) ) {
if ( ! F_81 ( V_91 , V_22 , & V_125 , V_100 , V_116 ) ) {
F_36 ( V_91 ) ;
break;
}
}
F_36 ( V_21 ) ;
return 0 ;
}
static int F_84 ( struct V_66 * V_66 , int V_126 )
{
struct V_17 * V_21 ;
struct V_9 * V_38 ;
int error ;
if ( ( V_126 & V_63 ) && F_85 ( V_66 -> V_79 ) )
return - V_64 ;
V_21 = F_55 ( V_66 ) ;
if ( F_57 ( V_21 ) )
return F_66 ( V_21 ) ;
V_38 = F_53 ( V_66 ) -> V_74 ;
if ( ! V_38 )
error = V_126 & V_62 ? - V_64 : 0 ;
else
error = F_49 ( V_21 , V_38 , V_126 & ~ V_127 ) ;
F_36 ( V_21 ) ;
return error ;
}
static int F_86 ( struct V_89 * V_89 , struct V_128 * V_129 )
{
struct V_66 * V_66 = V_89 -> V_124 ;
int error ;
if ( V_129 -> V_130 & ( V_131 | V_132 | V_133 ) )
return - V_106 ;
error = F_87 ( V_66 , V_129 ) ;
if ( error )
return error ;
F_88 ( V_66 , V_129 ) ;
F_89 ( V_66 ) ;
return 0 ;
}
static int F_90 ( struct V_134 * V_135 , struct V_89 * V_89 , struct V_136 * V_137 )
{
struct V_66 * V_66 = V_89 -> V_124 ;
struct V_17 * V_21 = F_55 ( V_66 ) ;
struct V_9 * V_38 = F_53 ( V_66 ) -> V_74 ;
if ( F_57 ( V_21 ) )
return F_66 ( V_21 ) ;
F_91 ( V_66 , V_137 ) ;
if ( V_38 )
V_137 -> V_57 = ( V_137 -> V_57 & V_138 ) | V_38 -> V_57 ;
F_36 ( V_21 ) ;
return 0 ;
}
static int F_92 ( struct V_89 * V_89 , unsigned int V_90 )
{
if ( V_90 & V_139 )
return - V_140 ;
return ! F_53 ( V_89 -> V_124 ) -> V_73 -> V_43 ;
}
static int F_93 ( const struct V_89 * V_89 )
{
return ! ! F_53 ( V_89 -> V_124 ) -> V_73 -> V_43 ;
}
static int F_94 ( struct V_17 * V_29 )
{
struct V_36 * V_37 = V_29 -> V_37 ;
int V_105 ;
F_29 ( & V_48 ) ;
if ( V_29 -> V_43 )
V_105 = 0 ;
else if ( ! V_37 -> V_141 )
V_105 = 1 ;
else
V_105 = V_37 -> V_141 ( V_37 ) ;
F_27 ( & V_48 ) ;
return V_105 ;
}
static int F_95 ( const struct V_89 * V_8 , const struct V_89 * V_89 ,
unsigned int V_95 , const char * V_142 , const struct V_92 * V_19 )
{
struct V_17 * V_21 ;
struct V_66 * V_66 ;
V_66 = F_96 ( V_89 -> V_124 ) ;
if ( ! V_66 )
return 1 ;
if ( V_19 -> V_95 != V_95 )
return 1 ;
if ( memcmp ( V_19 -> V_19 , V_142 , V_95 ) )
return 1 ;
V_21 = F_97 ( F_53 ( V_66 ) -> V_73 ) ;
return ! V_21 || ! F_94 ( V_21 ) ;
}
static struct V_5 * F_98 ( struct V_5 * V_6 ,
const char * V_19 , int V_20 )
{
struct V_17 * V_21 ;
struct V_9 * V_22 ;
V_22 = F_7 ( & V_21 , V_6 , V_19 , V_20 ) ;
if ( ! V_22 )
return F_30 ( - V_51 ) ;
if ( ! F_54 ( V_22 -> V_57 ) )
return F_30 ( - V_143 ) ;
return F_59 ( V_21 , struct V_5 , V_7 ) ;
}
static struct V_5 * F_99 ( struct V_36 * V_37 ,
const char * V_19 , int V_20 )
{
struct V_9 * V_38 ;
struct V_5 * V_144 ;
struct V_26 * V_24 ;
char * V_145 ;
V_144 = F_100 ( sizeof( * V_144 ) + sizeof( struct V_26 ) +
sizeof( struct V_9 ) * 2 + V_20 + 1 ,
V_146 ) ;
if ( ! V_144 )
return NULL ;
V_24 = (struct V_26 * ) ( V_144 + 1 ) ;
V_38 = (struct V_9 * ) ( V_24 + 1 ) ;
V_145 = ( char * ) ( V_38 + 2 ) ;
memcpy ( V_145 , V_19 , V_20 ) ;
V_145 [ V_20 ] = '\0' ;
V_38 [ 0 ] . V_10 = V_145 ;
V_38 [ 0 ] . V_57 = V_85 | V_147 | V_148 ;
F_15 ( & V_144 -> V_7 , V_37 -> V_6 . V_7 . V_25 , V_37 , V_24 , V_38 ) ;
return V_144 ;
}
static struct V_5 * F_101 ( struct V_5 * V_6 ,
const char * V_19 , int V_20 )
{
struct V_36 * V_37 = V_6 -> V_7 . V_37 ;
struct V_5 * V_149 , * V_144 = NULL ;
int V_44 ;
F_29 ( & V_48 ) ;
V_149 = F_98 ( V_6 , V_19 , V_20 ) ;
if ( ! F_57 ( V_149 ) )
goto V_150;
if ( F_66 ( V_149 ) != - V_51 )
goto V_151;
F_27 ( & V_48 ) ;
V_144 = F_99 ( V_37 , V_19 , V_20 ) ;
F_29 ( & V_48 ) ;
V_149 = F_30 ( - V_97 ) ;
if ( ! V_144 )
goto V_151;
V_149 = F_98 ( V_6 , V_19 , V_20 ) ;
if ( ! F_57 ( V_149 ) )
goto V_150;
if ( F_66 ( V_149 ) != - V_51 )
goto V_151;
V_44 = F_17 ( V_6 , & V_144 -> V_7 ) ;
V_149 = F_30 ( V_44 ) ;
if ( V_44 )
goto V_151;
V_149 = V_144 ;
V_150:
V_149 -> V_7 . V_42 ++ ;
V_151:
if ( F_22 ( F_57 ( V_149 ) ) ) {
F_10 ( L_4 ) ;
F_4 ( V_6 ) ;
F_5 ( L_5 ,
V_20 , V_20 , V_19 , F_66 ( V_149 ) ) ;
}
F_20 ( & V_6 -> V_7 ) ;
if ( V_144 )
F_20 ( & V_144 -> V_7 ) ;
F_27 ( & V_48 ) ;
return V_149 ;
}
static struct V_5 * F_102 ( struct V_36 * V_37 , struct V_5 * V_6 )
{
struct V_5 * V_8 ;
const char * V_10 ;
if ( ! V_6 -> V_7 . V_8 )
return & V_37 -> V_6 ;
V_8 = F_102 ( V_37 , V_6 -> V_7 . V_8 ) ;
if ( F_57 ( V_8 ) )
return V_8 ;
V_10 = V_6 -> V_7 . V_9 [ 0 ] . V_10 ;
return F_98 ( V_8 , V_10 , strlen ( V_10 ) ) ;
}
static int F_61 ( struct V_17 * * V_18 ,
struct V_9 * * V_56 , struct V_52 * V_53 )
{
struct V_17 * V_21 ;
struct V_35 * V_25 ;
struct V_36 * V_37 ;
struct V_9 * V_22 ;
struct V_5 * V_6 ;
int V_94 ;
V_94 = 0 ;
F_29 ( & V_48 ) ;
V_25 = ( * V_56 ) -> V_152 ;
V_37 = F_37 ( V_25 , V_53 ) ;
V_6 = F_102 ( V_37 , ( * V_18 ) -> V_8 ) ;
if ( F_57 ( V_6 ) )
V_94 = F_66 ( V_6 ) ;
else {
const char * V_10 = ( * V_56 ) -> V_10 ;
V_21 = NULL ;
V_22 = F_7 ( & V_21 , V_6 , V_10 , strlen ( V_10 ) ) ;
V_94 = - V_51 ;
if ( V_22 && F_21 ( V_21 ) ) {
F_23 ( * V_18 ) ;
* V_18 = V_21 ;
* V_56 = V_22 ;
V_94 = 0 ;
}
}
F_27 ( & V_48 ) ;
return V_94 ;
}
static int F_103 ( const char * V_153 , struct V_9 * V_38 , char * V_154 , ... )
{
struct V_155 V_156 ;
T_7 args ;
va_start ( args , V_154 ) ;
V_156 . V_154 = V_154 ;
V_156 . V_157 = & args ;
F_10 ( L_6 ,
V_153 , V_38 -> V_10 , & V_156 ) ;
va_end ( args ) ;
return - V_49 ;
}
static int F_104 ( const char * V_153 , struct V_9 * V_38 )
{
int V_44 = 0 ;
for (; V_38 -> V_10 ; V_38 ++ ) {
if ( V_38 -> V_117 )
V_44 = F_103 ( V_153 , V_38 , L_7 ) ;
if ( ( V_38 -> V_107 == V_158 ) ||
( V_38 -> V_107 == V_159 ) ||
( V_38 -> V_107 == V_160 ) ||
( V_38 -> V_107 == V_161 ) ||
( V_38 -> V_107 == V_162 ) ||
( V_38 -> V_107 == V_163 ) ||
( V_38 -> V_107 == V_164 ) ||
( V_38 -> V_107 == V_165 ) ) {
if ( ! V_38 -> V_152 )
V_44 = F_103 ( V_153 , V_38 , L_8 ) ;
if ( ! V_38 -> V_166 )
V_44 = F_103 ( V_153 , V_38 , L_9 ) ;
}
if ( ! V_38 -> V_107 )
V_44 = F_103 ( V_153 , V_38 , L_10 ) ;
if ( ( V_38 -> V_57 & ( V_147 | V_167 ) ) != V_38 -> V_57 )
V_44 = F_103 ( V_153 , V_38 , L_11 ,
V_38 -> V_57 ) ;
}
return V_44 ;
}
static struct V_17 * F_105 ( struct V_5 * V_6 , struct V_9 * V_38 ,
struct V_35 * V_168 )
{
struct V_9 * V_169 , * V_22 , * V_170 ;
struct V_17 * V_171 ;
struct V_26 * V_24 ;
char * V_172 ;
int V_173 , V_174 ;
V_174 = 0 ;
V_173 = 0 ;
for ( V_22 = V_38 ; V_22 -> V_10 ; V_22 ++ ) {
V_173 ++ ;
V_174 += strlen ( V_22 -> V_10 ) + 1 ;
}
V_171 = F_100 ( sizeof( struct V_17 ) +
sizeof( struct V_26 ) * V_173 +
sizeof( struct V_9 ) * ( V_173 + 1 ) +
V_174 ,
V_146 ) ;
if ( ! V_171 )
return NULL ;
V_24 = (struct V_26 * ) ( V_171 + 1 ) ;
V_169 = (struct V_9 * ) ( V_24 + V_173 ) ;
V_172 = ( char * ) & V_169 [ V_173 + 1 ] ;
for ( V_170 = V_169 , V_22 = V_38 ; V_22 -> V_10 ; V_170 ++ , V_22 ++ ) {
int V_95 = strlen ( V_22 -> V_10 ) + 1 ;
memcpy ( V_172 , V_22 -> V_10 , V_95 ) ;
V_170 -> V_10 = V_172 ;
V_170 -> V_57 = V_175 | V_176 ;
V_170 -> V_152 = V_168 ;
V_172 += V_95 ;
}
F_15 ( V_171 , V_6 -> V_7 . V_25 , V_6 -> V_7 . V_37 , V_24 , V_169 ) ;
V_171 -> V_42 = V_173 ;
return V_171 ;
}
static bool F_106 ( struct V_5 * V_6 ,
struct V_9 * V_38 , struct V_35 * V_168 )
{
struct V_17 * V_21 ;
struct V_9 * V_22 , * V_170 ;
for ( V_22 = V_38 ; V_22 -> V_10 ; V_22 ++ ) {
const char * V_10 = V_22 -> V_10 ;
V_170 = F_7 ( & V_21 , V_6 , V_10 , strlen ( V_10 ) ) ;
if ( ! V_170 )
return false ;
if ( F_54 ( V_170 -> V_57 ) && F_54 ( V_22 -> V_57 ) )
continue;
if ( F_60 ( V_170 -> V_57 ) && ( V_170 -> V_152 == V_168 ) )
continue;
return false ;
}
for ( V_22 = V_38 ; V_22 -> V_10 ; V_22 ++ ) {
const char * V_10 = V_22 -> V_10 ;
V_170 = F_7 ( & V_21 , V_6 , V_10 , strlen ( V_10 ) ) ;
V_21 -> V_42 ++ ;
}
return true ;
}
static int F_18 ( struct V_17 * V_21 )
{
struct V_36 * V_177 = & V_88 . V_54 ;
struct V_5 * V_178 = NULL ;
struct V_17 * V_171 ;
int V_44 ;
if ( V_21 -> V_37 == V_177 )
return 0 ;
V_178 = F_102 ( V_177 , V_21 -> V_8 ) ;
if ( F_57 ( V_178 ) )
return 0 ;
if ( F_106 ( V_178 , V_21 -> V_9 , V_21 -> V_25 ) )
return 0 ;
V_178 -> V_7 . V_42 ++ ;
F_27 ( & V_48 ) ;
V_171 = F_105 ( V_178 , V_21 -> V_9 , V_21 -> V_25 ) ;
F_29 ( & V_48 ) ;
V_44 = - V_97 ;
if ( ! V_171 )
goto V_71;
V_44 = 0 ;
if ( F_106 ( V_178 , V_21 -> V_9 , V_21 -> V_25 ) ) {
F_107 ( V_171 ) ;
goto V_71;
}
V_44 = F_17 ( V_178 , V_171 ) ;
if ( V_44 )
F_107 ( V_171 ) ;
V_71:
F_20 ( & V_178 -> V_7 ) ;
return V_44 ;
}
struct V_17 * F_108 (
struct V_36 * V_37 ,
const char * V_153 , struct V_9 * V_38 )
{
struct V_35 * V_25 = V_37 -> V_6 . V_7 . V_25 ;
struct V_17 * V_7 ;
const char * V_19 , * V_179 ;
struct V_5 * V_6 ;
struct V_9 * V_22 ;
struct V_26 * V_24 ;
int V_173 = 0 ;
for ( V_22 = V_38 ; V_22 -> V_10 ; V_22 ++ )
V_173 ++ ;
V_7 = F_100 ( sizeof( struct V_17 ) +
sizeof( struct V_26 ) * V_173 , V_146 ) ;
if ( ! V_7 )
return NULL ;
V_24 = (struct V_26 * ) ( V_7 + 1 ) ;
F_15 ( V_7 , V_25 , V_37 , V_24 , V_38 ) ;
if ( F_104 ( V_153 , V_38 ) )
goto V_46;
F_29 ( & V_48 ) ;
V_6 = & V_37 -> V_6 ;
V_6 -> V_7 . V_42 ++ ;
F_27 ( & V_48 ) ;
for ( V_19 = V_153 ; V_19 ; V_19 = V_179 ) {
int V_20 ;
V_179 = strchr ( V_19 , '/' ) ;
if ( V_179 ) {
V_20 = V_179 - V_19 ;
V_179 ++ ;
} else {
V_20 = strlen ( V_19 ) ;
}
if ( V_20 == 0 )
continue;
V_6 = F_101 ( V_6 , V_19 , V_20 ) ;
if ( F_57 ( V_6 ) )
goto V_46;
}
F_29 ( & V_48 ) ;
if ( F_17 ( V_6 , V_7 ) )
goto V_180;
F_20 ( & V_6 -> V_7 ) ;
F_27 ( & V_48 ) ;
return V_7 ;
V_180:
F_20 ( & V_6 -> V_7 ) ;
F_27 ( & V_48 ) ;
V_46:
F_107 ( V_7 ) ;
F_109 () ;
return NULL ;
}
struct V_17 * F_110 ( const char * V_153 , struct V_9 * V_38 )
{
return F_108 ( & V_88 . V_54 ,
V_153 , V_38 ) ;
}
static char * F_111 ( const char * V_153 , char * V_125 , const char * V_19 )
{
int V_20 ;
V_20 = strlen ( V_19 ) ;
if ( ( ( V_125 - V_153 ) + V_20 + 2 ) >= V_181 )
return NULL ;
memcpy ( V_125 , V_19 , V_20 ) ;
V_125 [ V_20 ] = '/' ;
V_125 [ V_20 + 1 ] = '\0' ;
V_125 += V_20 + 1 ;
return V_125 ;
}
static int F_112 ( struct V_9 * V_38 )
{
int V_182 = 0 ;
int V_183 = 0 ;
struct V_9 * V_22 ;
if ( ! V_38 || ! V_38 -> V_10 )
return 1 ;
for ( V_22 = V_38 ; V_22 -> V_10 ; V_22 ++ ) {
if ( V_22 -> V_117 )
V_183 += F_112 ( V_22 -> V_117 ) ;
else
V_182 = 1 ;
}
return V_183 + V_182 ;
}
static int F_113 ( const char * V_153 , char * V_125 ,
struct V_17 * * * V_184 , struct V_36 * V_37 ,
struct V_9 * V_38 )
{
struct V_9 * V_39 = NULL ;
struct V_9 * V_22 , * V_185 ;
int V_186 = 0 ;
int V_187 = 0 ;
int V_44 = - V_97 ;
for ( V_22 = V_38 ; V_22 -> V_10 ; V_22 ++ ) {
if ( V_22 -> V_117 )
V_187 ++ ;
else
V_186 ++ ;
}
V_185 = V_38 ;
if ( V_187 && V_186 ) {
struct V_9 * V_144 ;
V_185 = F_100 ( sizeof( struct V_9 ) * ( V_186 + 1 ) ,
V_146 ) ;
if ( ! V_185 )
goto V_71;
V_39 = V_185 ;
for ( V_144 = V_185 , V_22 = V_38 ; V_22 -> V_10 ; V_22 ++ ) {
if ( V_22 -> V_117 )
continue;
* V_144 = * V_22 ;
V_144 ++ ;
}
}
if ( V_186 || ! V_187 ) {
struct V_17 * V_7 ;
V_7 = F_108 ( V_37 , V_153 , V_185 ) ;
if ( ! V_7 ) {
F_107 ( V_39 ) ;
goto V_71;
}
V_7 -> V_39 = V_39 ;
* * V_184 = V_7 ;
( * V_184 ) ++ ;
}
for ( V_22 = V_38 ; V_22 -> V_10 ; V_22 ++ ) {
char * V_188 ;
if ( ! V_22 -> V_117 )
continue;
V_44 = - V_189 ;
V_188 = F_111 ( V_153 , V_125 , V_22 -> V_10 ) ;
if ( ! V_188 )
goto V_71;
V_44 = F_113 ( V_153 , V_188 , V_184 ,
V_37 , V_22 -> V_117 ) ;
V_125 [ 0 ] = '\0' ;
if ( V_44 )
goto V_71;
}
V_44 = 0 ;
V_71:
return V_44 ;
}
struct V_17 * F_114 (
struct V_36 * V_37 ,
const struct V_190 * V_153 , struct V_9 * V_38 )
{
struct V_9 * V_39 = V_38 ;
int V_183 = F_112 ( V_38 ) ;
struct V_17 * V_7 = NULL , * * V_191 , * * V_184 ;
const struct V_190 * V_192 ;
char * V_193 , * V_125 ;
V_125 = V_193 = F_115 ( V_181 , V_146 ) ;
if ( ! V_193 )
return NULL ;
V_125 [ 0 ] = '\0' ;
for ( V_192 = V_153 ; V_192 -> V_10 ; V_192 ++ ) {
V_125 = F_111 ( V_193 , V_125 , V_192 -> V_10 ) ;
if ( ! V_125 )
goto V_71;
}
while ( V_38 -> V_10 && V_38 -> V_117 && ! V_38 [ 1 ] . V_10 ) {
V_125 = F_111 ( V_193 , V_125 , V_38 -> V_10 ) ;
if ( ! V_125 )
goto V_71;
V_38 = V_38 -> V_117 ;
}
if ( V_183 == 1 ) {
V_7 = F_108 ( V_37 , V_193 , V_38 ) ;
if ( V_7 )
V_7 -> V_39 = V_39 ;
} else {
V_7 = F_100 ( sizeof( * V_7 ) +
sizeof( * V_191 ) * V_183 , V_146 ) ;
if ( ! V_7 )
goto V_71;
V_191 = (struct V_17 * * ) ( V_7 + 1 ) ;
V_184 = V_191 ;
V_7 -> V_39 = V_39 ;
if ( F_113 ( V_193 , V_125 , & V_184 ,
V_37 , V_38 ) )
goto V_194;
}
V_71:
F_107 ( V_193 ) ;
return V_7 ;
V_194:
while ( V_184 > V_191 ) {
struct V_17 * V_195 = * ( -- V_184 ) ;
struct V_9 * V_38 = V_195 -> V_39 ;
F_116 ( V_195 ) ;
F_107 ( V_38 ) ;
}
F_107 ( V_7 ) ;
V_7 = NULL ;
goto V_71;
}
struct V_17 * F_117 ( const struct V_190 * V_153 ,
struct V_9 * V_38 )
{
return F_114 ( & V_88 . V_54 ,
V_153 , V_38 ) ;
}
struct V_17 * F_118 ( struct V_9 * V_38 )
{
static const struct V_190 V_196 [] = { {} } ;
return F_117 ( V_196 , V_38 ) ;
}
static void F_19 ( struct V_17 * V_7 )
{
struct V_36 * V_177 = & V_88 . V_54 ;
struct V_35 * V_25 = V_7 -> V_25 ;
struct V_5 * V_8 = V_7 -> V_8 ;
struct V_5 * V_178 ;
struct V_9 * V_22 ;
if ( V_7 -> V_37 == V_177 )
return;
V_178 = F_102 ( V_177 , V_8 ) ;
if ( F_57 ( V_178 ) )
return;
for ( V_22 = V_7 -> V_9 ; V_22 -> V_10 ; V_22 ++ ) {
struct V_17 * V_197 ;
struct V_9 * V_170 ;
const char * V_19 = V_22 -> V_10 ;
V_170 = F_7 ( & V_197 , V_178 , V_19 , strlen ( V_19 ) ) ;
if ( V_170 &&
( ( F_54 ( V_170 -> V_57 ) && F_54 ( V_22 -> V_57 ) ) ||
( F_60 ( V_170 -> V_57 ) && ( V_170 -> V_152 == V_25 ) ) ) ) {
F_20 ( V_197 ) ;
}
else {
F_10 ( L_12 ) ;
F_4 ( V_8 ) ;
F_5 ( L_3 , V_19 ) ;
}
}
}
static void F_20 ( struct V_17 * V_7 )
{
struct V_5 * V_8 = V_7 -> V_8 ;
if ( -- V_7 -> V_42 )
return;
F_19 ( V_7 ) ;
F_25 ( V_7 ) ;
if ( ! -- V_7 -> V_41 )
F_33 ( V_7 , V_50 ) ;
if ( V_8 )
F_20 ( & V_8 -> V_7 ) ;
}
void F_116 ( struct V_17 * V_7 )
{
int V_183 ;
F_119 () ;
if ( V_7 == NULL )
return;
V_183 = F_112 ( V_7 -> V_39 ) ;
if ( F_22 ( V_183 > 1 ) ) {
struct V_17 * * V_191 ;
int V_198 ;
V_191 = (struct V_17 * * ) ( V_7 + 1 ) ;
for ( V_198 = V_183 - 1 ; V_198 >= 0 ; V_198 -- ) {
struct V_17 * V_195 = V_191 [ V_198 ] ;
struct V_9 * V_38 = V_195 -> V_39 ;
F_116 ( V_195 ) ;
F_107 ( V_38 ) ;
}
F_107 ( V_7 ) ;
return;
}
F_29 ( & V_48 ) ;
F_20 ( V_7 ) ;
F_27 ( & V_48 ) ;
}
void F_120 ( struct V_36 * V_37 ,
struct V_35 * V_25 ,
int (* V_141)( struct V_36 * ) )
{
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_141 = V_141 ;
F_15 ( & V_37 -> V_6 . V_7 , V_25 , V_37 , NULL , V_199 ) ;
}
void F_121 ( struct V_36 * V_37 )
{
F_122 ( ! F_123 ( & V_37 -> V_6 . V_25 ) ) ;
}
int T_8 F_124 ( void )
{
struct V_200 * V_201 ;
V_201 = F_125 ( L_13 , NULL ) ;
V_201 -> V_202 = & V_86 ;
V_201 -> V_203 = & V_87 ;
V_201 -> V_204 = 0 ;
return F_126 () ;
}
