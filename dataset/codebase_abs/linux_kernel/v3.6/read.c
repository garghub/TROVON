struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_3 , V_4 ) ;
if ( V_2 ) {
struct V_5 * V_6 = & V_2 -> V_7 ;
F_3 ( & V_6 -> V_8 ) ;
F_3 ( & V_6 -> V_9 ) ;
F_4 ( & V_6 -> V_10 ) ;
F_5 ( & V_6 -> V_11 , 0 ) ;
}
return V_2 ;
}
static struct V_12 * F_6 ( struct V_5 * V_6 ,
unsigned int V_13 )
{
struct V_12 * V_14 , * V_15 ;
V_15 = & F_7 ( V_6 , struct V_1 , V_7 ) -> V_16 ;
if ( V_15 -> V_7 == NULL )
V_14 = V_15 ;
else
V_14 = F_8 ( sizeof( * V_14 ) , V_4 ) ;
if ( ! V_14 )
goto V_17;
if ( F_9 ( & V_14 -> V_8 , V_13 ) ) {
V_14 -> V_7 = V_6 ;
F_10 ( & V_6 -> V_11 ) ;
} else {
if ( V_14 != V_15 )
F_11 ( V_14 ) ;
V_14 = NULL ;
}
V_17:
return V_14 ;
}
void F_12 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 , struct V_1 , V_7 ) ;
F_13 ( V_3 , V_2 ) ;
}
void F_14 ( struct V_12 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_7 ;
struct V_1 * V_19 = F_7 ( V_6 , struct V_1 , V_7 ) ;
F_15 ( V_18 -> args . V_20 ) ;
if ( V_18 -> V_8 . V_21 != V_18 -> V_8 . V_22 )
F_11 ( V_18 -> V_8 . V_21 ) ;
if ( V_18 != & V_19 -> V_16 )
F_11 ( V_18 ) ;
else
V_18 -> V_7 = NULL ;
if ( F_16 ( & V_6 -> V_11 ) )
V_6 -> V_23 -> V_24 ( V_6 ) ;
}
static
int F_17 ( struct V_25 * V_25 )
{
F_18 ( V_25 , 0 , V_26 ) ;
F_19 ( V_25 ) ;
F_20 ( V_25 ) ;
return 0 ;
}
void F_21 ( struct V_27 * V_28 ,
struct V_29 * V_29 ,
const struct V_30 * V_31 )
{
F_22 ( V_28 , V_29 , & V_32 , V_31 ,
F_23 ( V_29 ) -> V_33 , 0 ) ;
}
void F_24 ( struct V_27 * V_28 )
{
V_28 -> V_34 = & V_32 ;
V_28 -> V_35 = F_23 ( V_28 -> V_36 ) -> V_33 ;
}
int F_25 ( struct V_37 * V_38 , struct V_29 * V_29 ,
struct V_25 * V_25 )
{
struct V_39 * V_40 ;
unsigned int V_41 ;
struct V_27 V_28 ;
V_41 = F_26 ( V_25 ) ;
if ( V_41 == 0 )
return F_17 ( V_25 ) ;
V_40 = F_27 ( V_38 , V_29 , V_25 , 0 , V_41 ) ;
if ( F_28 ( V_40 ) ) {
F_20 ( V_25 ) ;
return F_29 ( V_40 ) ;
}
if ( V_41 < V_26 )
F_30 ( V_25 , V_41 , V_26 ) ;
F_31 ( V_29 ) -> F_32 ( & V_28 , V_29 , & V_42 ) ;
F_33 ( & V_28 , V_40 ) ;
F_34 ( & V_28 ) ;
F_35 ( V_29 ) -> V_43 += V_28 . V_44 ;
return 0 ;
}
static void F_36 ( struct V_39 * V_45 )
{
struct V_29 * V_46 = V_45 -> V_47 -> V_48 -> V_46 ;
if ( F_37 ( V_45 -> V_49 ) )
F_38 ( V_46 , V_45 -> V_49 , 0 ) ;
F_20 ( V_45 -> V_49 ) ;
F_39 ( L_1 ,
V_45 -> V_47 -> V_48 -> V_46 -> V_50 -> V_51 ,
( long long ) F_40 ( V_45 -> V_47 -> V_48 -> V_46 ) ,
V_45 -> V_52 ,
( long long ) F_41 ( V_45 ) ) ;
F_42 ( V_45 ) ;
}
static void F_43 ( struct V_5 * V_6 )
{
unsigned long V_53 = 0 ;
if ( F_44 ( V_54 , & V_6 -> V_55 ) )
goto V_17;
while ( ! F_45 ( & V_6 -> V_8 ) ) {
struct V_39 * V_45 = F_46 ( V_6 -> V_8 . V_56 ) ;
struct V_25 * V_25 = V_45 -> V_49 ;
if ( F_44 ( V_57 , & V_6 -> V_55 ) ) {
if ( V_53 > V_6 -> V_58 )
F_18 ( V_25 , 0 , V_59 ) ;
else if ( V_6 -> V_58 - V_53 < V_59 )
F_30 ( V_25 ,
V_6 -> V_58 & ~ V_60 ,
V_59 ) ;
}
V_53 += V_45 -> V_52 ;
if ( F_44 ( V_61 , & V_6 -> V_55 ) ) {
if ( V_53 <= V_6 -> V_58 )
F_19 ( V_25 ) ;
} else
F_19 ( V_25 ) ;
F_47 ( V_45 ) ;
F_36 ( V_45 ) ;
}
V_17:
V_6 -> V_62 ( V_6 ) ;
}
int F_48 ( struct V_63 * V_64 ,
struct V_12 * V_14 ,
const struct V_65 * V_66 , int V_55 )
{
struct V_29 * V_29 = V_14 -> V_7 -> V_29 ;
int V_67 = F_49 ( V_29 ) ? V_68 : 0 ;
struct V_69 * V_70 ;
struct V_71 V_72 = {
. V_73 = & V_14 -> args ,
. V_74 = & V_14 -> V_75 ,
. V_76 = V_14 -> V_7 -> V_77 ,
} ;
struct V_78 V_79 = {
. V_70 = & V_14 -> V_70 ,
. V_80 = V_64 ,
. V_71 = & V_72 ,
. V_81 = V_66 ,
. V_82 = V_14 ,
. V_83 = V_84 ,
. V_55 = V_85 | V_67 | V_55 ,
} ;
F_31 ( V_29 ) -> F_50 ( V_14 , & V_72 ) ;
F_39 ( L_2
L_3 ,
V_14 -> V_70 . V_86 ,
V_29 -> V_50 -> V_51 ,
( long long ) F_40 ( V_29 ) ,
V_14 -> args . V_87 ,
( unsigned long long ) V_14 -> args . V_88 ) ;
V_70 = F_51 ( & V_79 ) ;
if ( F_28 ( V_70 ) )
return F_29 ( V_70 ) ;
F_52 ( V_70 ) ;
return 0 ;
}
static void F_53 ( struct V_12 * V_14 ,
unsigned int V_87 , unsigned int V_88 )
{
struct V_39 * V_45 = V_14 -> V_7 -> V_45 ;
V_14 -> args . V_89 = F_54 ( V_14 -> V_7 -> V_29 ) ;
V_14 -> args . V_88 = F_41 ( V_45 ) + V_88 ;
V_14 -> args . V_90 = V_45 -> V_91 + V_88 ;
V_14 -> args . V_8 = V_14 -> V_8 . V_21 ;
V_14 -> args . V_87 = V_87 ;
V_14 -> args . V_20 = F_55 ( V_45 -> V_47 ) ;
V_14 -> args . V_92 = V_45 -> V_93 ;
V_14 -> V_75 . V_94 = & V_14 -> V_94 ;
V_14 -> V_75 . V_87 = V_87 ;
V_14 -> V_75 . V_95 = 0 ;
F_56 ( & V_14 -> V_94 ) ;
}
static int F_57 ( struct V_12 * V_14 ,
const struct V_65 * V_66 )
{
struct V_29 * V_29 = V_14 -> V_7 -> V_29 ;
return F_48 ( F_58 ( V_29 ) , V_14 , V_66 , 0 ) ;
}
static int
F_59 ( struct V_96 * V_97 ,
const struct V_65 * V_66 )
{
struct V_12 * V_14 ;
int V_98 = 0 ;
while ( ! F_45 ( V_97 ) ) {
int V_99 ;
V_14 = F_60 ( V_97 , struct V_12 , V_100 ) ;
F_61 ( & V_14 -> V_100 ) ;
V_99 = F_57 ( V_14 , V_66 ) ;
if ( V_98 == 0 )
V_98 = V_99 ;
}
return V_98 ;
}
static void
F_62 ( struct V_96 * V_97 )
{
struct V_39 * V_45 ;
while ( ! F_45 ( V_97 ) ) {
V_45 = F_46 ( V_97 -> V_56 ) ;
F_47 ( V_45 ) ;
F_36 ( V_45 ) ;
}
}
static void F_63 ( struct V_27 * V_101 ,
struct V_5 * V_6 )
{
F_64 ( V_54 , & V_6 -> V_55 ) ;
while ( ! F_45 ( & V_6 -> V_9 ) ) {
struct V_12 * V_14 = F_60 ( & V_6 -> V_9 ,
struct V_12 , V_100 ) ;
F_65 ( & V_14 -> V_100 ) ;
F_14 ( V_14 ) ;
}
V_101 -> V_102 -> V_103 ( & V_101 -> V_104 ) ;
}
static int F_66 ( struct V_27 * V_101 ,
struct V_5 * V_6 )
{
struct V_39 * V_45 = V_6 -> V_45 ;
struct V_25 * V_25 = V_45 -> V_49 ;
struct V_12 * V_14 ;
T_1 V_33 = V_101 -> V_35 , V_105 ;
unsigned int V_88 ;
V_88 = 0 ;
V_105 = V_101 -> V_106 ;
do {
T_1 V_41 = F_67 ( V_105 , V_33 ) ;
V_14 = F_6 ( V_6 , 1 ) ;
if ( ! V_14 ) {
F_63 ( V_101 , V_6 ) ;
return - V_107 ;
}
V_14 -> V_8 . V_21 [ 0 ] = V_25 ;
F_53 ( V_14 , V_41 , V_88 ) ;
F_68 ( & V_14 -> V_100 , & V_6 -> V_9 ) ;
V_105 -= V_41 ;
V_88 += V_41 ;
} while ( V_105 != 0 );
F_47 ( V_45 ) ;
F_69 ( V_45 , & V_6 -> V_8 ) ;
V_101 -> V_108 = & V_109 ;
return 0 ;
}
static int F_70 ( struct V_27 * V_101 ,
struct V_5 * V_6 )
{
struct V_39 * V_45 ;
struct V_25 * * V_8 ;
struct V_12 * V_14 ;
struct V_96 * V_97 = & V_101 -> V_104 ;
V_14 = F_6 ( V_6 , F_71 ( V_101 -> V_110 ,
V_101 -> V_106 ) ) ;
if ( ! V_14 ) {
F_63 ( V_101 , V_6 ) ;
return - V_107 ;
}
V_8 = V_14 -> V_8 . V_21 ;
while ( ! F_45 ( V_97 ) ) {
V_45 = F_46 ( V_97 -> V_56 ) ;
F_47 ( V_45 ) ;
F_69 ( V_45 , & V_6 -> V_8 ) ;
* V_8 ++ = V_45 -> V_49 ;
}
F_53 ( V_14 , V_101 -> V_106 , 0 ) ;
F_68 ( & V_14 -> V_100 , & V_6 -> V_9 ) ;
V_101 -> V_108 = & V_109 ;
return 0 ;
}
int F_72 ( struct V_27 * V_101 ,
struct V_5 * V_6 )
{
if ( V_101 -> V_35 < V_26 )
return F_66 ( V_101 , V_6 ) ;
return F_70 ( V_101 , V_6 ) ;
}
static int F_73 ( struct V_27 * V_101 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_98 ;
V_2 = F_1 () ;
if ( ! V_2 ) {
V_101 -> V_102 -> V_103 ( & V_101 -> V_104 ) ;
return - V_107 ;
}
V_6 = & V_2 -> V_7 ;
F_74 ( V_101 , V_6 , F_12 ) ;
F_10 ( & V_6 -> V_11 ) ;
V_98 = F_72 ( V_101 , V_6 ) ;
if ( V_98 == 0 )
V_98 = F_59 ( & V_6 -> V_9 ,
V_101 -> V_108 ) ;
if ( F_16 ( & V_6 -> V_11 ) )
V_6 -> V_23 -> V_24 ( V_6 ) ;
return V_98 ;
}
int F_75 ( struct V_69 * V_70 , struct V_12 * V_14 )
{
struct V_29 * V_29 = V_14 -> V_7 -> V_29 ;
int V_111 ;
F_39 ( L_4 , V_112 , V_70 -> V_86 ,
V_70 -> V_113 ) ;
V_111 = F_31 ( V_29 ) -> F_76 ( V_70 , V_14 ) ;
if ( V_111 != 0 )
return V_111 ;
F_77 ( V_29 , V_114 , V_14 -> V_75 . V_87 ) ;
if ( V_70 -> V_113 == - V_115 ) {
F_64 ( V_116 , & F_35 ( V_29 ) -> V_55 ) ;
F_78 ( V_29 ) ;
}
return 0 ;
}
static void F_79 ( struct V_69 * V_70 , struct V_12 * V_14 )
{
struct V_117 * V_118 = & V_14 -> args ;
struct V_119 * V_120 = & V_14 -> V_75 ;
F_80 ( V_14 -> V_7 -> V_29 , V_121 ) ;
if ( V_120 -> V_87 == 0 ) {
F_81 ( V_14 -> V_7 , - V_122 , V_118 -> V_88 ) ;
return;
}
V_14 -> V_123 += V_120 -> V_87 ;
V_118 -> V_88 += V_120 -> V_87 ;
V_118 -> V_90 += V_120 -> V_87 ;
V_118 -> V_87 -= V_120 -> V_87 ;
F_82 ( V_70 ) ;
}
static void F_83 ( struct V_69 * V_70 , void * V_124 )
{
struct V_12 * V_14 = V_124 ;
struct V_5 * V_6 = V_14 -> V_7 ;
if ( F_75 ( V_70 , V_14 ) != 0 )
return;
if ( V_70 -> V_113 < 0 )
F_81 ( V_6 , V_70 -> V_113 , V_14 -> args . V_88 ) ;
else if ( V_14 -> V_75 . V_95 ) {
T_2 V_125 ;
V_125 = V_14 -> args . V_88 + V_14 -> V_75 . V_87 ;
F_84 ( & V_6 -> V_10 ) ;
if ( V_125 < V_6 -> V_126 + V_6 -> V_58 ) {
F_64 ( V_57 , & V_6 -> V_55 ) ;
F_85 ( V_61 , & V_6 -> V_55 ) ;
V_6 -> V_58 = V_125 - V_6 -> V_126 ;
}
F_86 ( & V_6 -> V_10 ) ;
} else if ( V_14 -> V_75 . V_87 != V_14 -> args . V_87 )
F_79 ( V_70 , V_14 ) ;
}
static void F_87 ( void * V_124 )
{
F_14 ( V_124 ) ;
}
void F_88 ( struct V_69 * V_70 , void * V_124 )
{
struct V_12 * V_14 = V_124 ;
F_31 ( V_14 -> V_7 -> V_29 ) -> F_89 ( V_70 , V_14 ) ;
}
int F_90 ( struct V_127 * V_127 , struct V_25 * V_25 )
{
struct V_37 * V_38 ;
struct V_29 * V_29 = F_91 ( V_25 ) -> V_128 ;
int error ;
F_39 ( L_5 ,
V_25 , V_26 , F_92 ( V_25 ) ) ;
F_80 ( V_29 , V_129 ) ;
F_77 ( V_29 , V_130 , 1 ) ;
error = F_93 ( V_29 , V_25 ) ;
if ( error )
goto V_131;
if ( F_37 ( V_25 ) )
goto V_131;
error = - V_115 ;
if ( F_94 ( V_29 ) )
goto V_131;
if ( V_127 == NULL ) {
error = - V_132 ;
V_38 = F_95 ( V_29 , NULL , V_133 ) ;
if ( V_38 == NULL )
goto V_131;
} else
V_38 = F_55 ( F_96 ( V_127 ) ) ;
if ( ! F_97 ( V_29 ) ) {
error = F_98 ( V_38 , V_29 , V_25 ) ;
if ( error == 0 )
goto V_17;
}
error = F_25 ( V_38 , V_29 , V_25 ) ;
V_17:
F_15 ( V_38 ) ;
return error ;
V_131:
F_20 ( V_25 ) ;
return error ;
}
static int
F_99 ( void * V_14 , struct V_25 * V_25 )
{
struct V_134 * V_101 = (struct V_134 * ) V_14 ;
struct V_29 * V_29 = F_91 ( V_25 ) -> V_128 ;
struct V_39 * V_40 ;
unsigned int V_41 ;
int error ;
V_41 = F_26 ( V_25 ) ;
if ( V_41 == 0 )
return F_17 ( V_25 ) ;
V_40 = F_27 ( V_101 -> V_38 , V_29 , V_25 , 0 , V_41 ) ;
if ( F_28 ( V_40 ) )
goto V_135;
if ( V_41 < V_26 )
F_30 ( V_25 , V_41 , V_26 ) ;
if ( ! F_33 ( V_101 -> V_28 , V_40 ) ) {
error = V_101 -> V_28 -> V_136 ;
goto V_131;
}
return 0 ;
V_135:
error = F_29 ( V_40 ) ;
V_131:
F_20 ( V_25 ) ;
return error ;
}
int F_100 ( struct V_127 * V_137 , struct V_138 * V_139 ,
struct V_96 * V_8 , unsigned V_140 )
{
struct V_27 V_28 ;
struct V_134 V_101 = {
. V_28 = & V_28 ,
} ;
struct V_29 * V_29 = V_139 -> V_128 ;
unsigned long V_141 ;
int V_98 = - V_115 ;
F_39 ( L_6 ,
V_29 -> V_50 -> V_51 ,
( long long ) F_40 ( V_29 ) ,
V_140 ) ;
F_80 ( V_29 , V_142 ) ;
if ( F_94 ( V_29 ) )
goto V_17;
if ( V_137 == NULL ) {
V_101 . V_38 = F_95 ( V_29 , NULL , V_133 ) ;
if ( V_101 . V_38 == NULL )
return - V_132 ;
} else
V_101 . V_38 = F_55 ( F_96 ( V_137 ) ) ;
V_98 = F_101 ( V_101 . V_38 , V_29 , V_139 ,
V_8 , & V_140 ) ;
if ( V_98 == 0 )
goto V_143;
F_31 ( V_29 ) -> F_32 ( & V_28 , V_29 , & V_42 ) ;
V_98 = F_102 ( V_139 , V_8 , F_99 , & V_101 ) ;
F_34 ( & V_28 ) ;
F_35 ( V_29 ) -> V_43 += V_28 . V_44 ;
V_141 = ( V_28 . V_44 + V_26 - 1 ) >> V_144 ;
F_77 ( V_29 , V_130 , V_141 ) ;
V_143:
F_15 ( V_101 . V_38 ) ;
V_17:
return V_98 ;
}
int T_3 F_103 ( void )
{
V_3 = F_104 ( L_7 ,
sizeof( struct V_1 ) ,
0 , V_145 ,
NULL ) ;
if ( V_3 == NULL )
return - V_107 ;
return 0 ;
}
void F_105 ( void )
{
F_106 ( V_3 ) ;
}
