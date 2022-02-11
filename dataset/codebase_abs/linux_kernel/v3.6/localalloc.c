unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
unsigned int V_4 ;
unsigned int V_5 ;
unsigned int V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
V_4 = F_2 ( V_2 -> V_8 ,
8 * F_3 ( V_8 , 0 , V_2 -> V_9 ) ) ;
if ( ( V_8 -> V_10 == 512 && V_2 -> V_11 <= 8192 )
|| ( V_8 -> V_10 == 1024 && V_2 -> V_11 == 4096 ) )
return V_12 ;
V_4 -= 16 ;
V_4 &= 0xFFFFFFFB ;
V_3 = V_4 ;
if ( V_3 > V_13 ) {
if ( V_4 > ( 2 * V_13 ) )
V_3 = 256 ;
else {
unsigned int V_14 = V_4 ;
while ( V_14 > 256 )
V_14 = V_14 >> 1 ;
V_3 = V_14 ;
}
}
V_6 = V_2 -> V_15 / V_2 -> V_16 ;
V_6 = F_2 ( V_2 -> V_8 , V_6 ) ;
if ( V_6 < V_3 )
V_3 = V_6 ;
V_5 = F_2 ( V_2 -> V_8 ,
F_4 ( V_8 ) * 8 ) ;
if ( V_3 > V_5 )
V_3 = V_5 ;
return V_3 ;
}
void F_5 ( struct V_1 * V_2 , int V_17 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_18 = F_1 ( V_2 ) ;
unsigned int V_5 ;
V_5 = F_2 ( V_8 ,
F_4 ( V_8 ) * 8 ) ;
F_6 ( V_17 , V_5 , V_18 ) ;
if ( V_17 == - 1 ) {
V_2 -> V_19 =
F_7 ( V_8 , V_18 ) ;
} else if ( V_17 > V_5 ) {
V_2 -> V_19 =
F_7 ( V_8 , V_5 ) ;
} else {
V_2 -> V_19 =
F_7 ( V_8 , V_17 ) ;
}
V_2 -> V_20 = V_2 -> V_19 ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
return ( V_2 -> V_21 == V_22 ||
V_2 -> V_21 == V_23 ) ;
}
void F_9 ( struct V_1 * V_2 ,
unsigned int V_24 )
{
F_10 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_21 == V_26 ||
V_2 -> V_21 == V_22 )
if ( V_24 >= V_2 -> V_19 ) {
F_11 ( & V_2 -> V_27 ) ;
V_2 -> V_21 = V_23 ;
}
F_12 ( & V_2 -> V_25 ) ;
}
void F_13 ( struct V_28 * V_29 )
{
struct V_1 * V_2 =
F_14 ( V_29 , struct V_1 ,
V_27 . V_29 ) ;
F_10 ( & V_2 -> V_25 ) ;
V_2 -> V_21 = V_23 ;
F_12 ( & V_2 -> V_25 ) ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_30 )
{
int V_31 = 0 ;
int V_32 ;
F_10 ( & V_2 -> V_25 ) ;
V_32 = V_2 -> V_20 ;
if ( ! F_8 ( V_2 ) )
goto V_33;
if ( V_30 > ( V_32 / 2 ) )
goto V_33;
V_31 = 1 ;
V_33:
F_16 (
( unsigned long long ) V_30 , V_2 -> V_21 , V_32 , V_31 ) ;
F_12 ( & V_2 -> V_25 ) ;
return V_31 ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_34 = 0 ;
struct V_35 * V_36 = NULL ;
struct V_37 * V_38 = NULL ;
T_2 V_39 ;
struct V_40 * V_40 = NULL ;
struct V_41 * V_42 ;
if ( V_2 -> V_20 == 0 )
goto V_33;
if ( V_2 -> V_20 >= V_2 -> V_43 ) {
F_18 ( V_44 , L_1
L_2 ,
V_2 -> V_20 , ( V_2 -> V_43 - 1 ) ) ;
V_2 -> V_20 =
F_7 ( V_2 -> V_8 ,
F_1 ( V_2 ) ) ;
}
V_40 = F_19 ( V_2 , V_45 ,
V_2 -> V_46 ) ;
if ( ! V_40 ) {
V_34 = - V_47 ;
F_20 ( V_34 ) ;
goto V_33;
}
V_34 = F_21 ( V_40 , & V_38 ,
V_48 ) ;
if ( V_34 < 0 ) {
F_20 ( V_34 ) ;
goto V_33;
}
V_36 = (struct V_35 * ) V_38 -> V_49 ;
V_42 = F_22 ( V_36 ) ;
if ( ! ( F_23 ( V_36 -> V_50 ) &
( V_51 | V_52 ) ) ) {
F_18 ( V_53 , L_3 ,
( unsigned long long ) F_24 ( V_40 ) -> V_54 ) ;
V_34 = - V_47 ;
goto V_33;
}
if ( ( V_42 -> V_55 == 0 ) ||
( F_25 ( V_42 -> V_55 ) > F_4 ( V_40 -> V_56 ) ) ) {
F_18 ( V_53 , L_4 ,
F_25 ( V_42 -> V_55 ) ) ;
V_34 = - V_47 ;
goto V_33;
}
V_39 = F_26 ( V_36 ) ;
if ( V_39
|| V_36 -> V_57 . V_58 . V_59
|| V_36 -> V_57 . V_58 . V_60
|| V_42 -> V_61 )
F_18 ( V_53 , L_5
L_6 ,
V_39 , F_23 ( V_36 -> V_57 . V_58 . V_59 ) ,
F_23 ( V_36 -> V_57 . V_58 . V_60 ) ,
F_22 ( V_36 ) -> V_61 ) ;
V_2 -> V_62 = V_38 ;
V_2 -> V_21 = V_23 ;
V_33:
if ( V_34 < 0 )
F_27 ( V_38 ) ;
if ( V_40 )
F_28 ( V_40 ) ;
F_29 ( V_2 -> V_20 ) ;
if ( V_34 )
F_20 ( V_34 ) ;
return V_34 ;
}
void F_30 ( struct V_1 * V_2 )
{
int V_34 ;
T_3 * V_63 ;
struct V_40 * V_64 = NULL ;
struct V_37 * V_65 = NULL ;
struct V_37 * V_66 = NULL ;
struct V_40 * V_67 = NULL ;
struct V_35 * V_68 = NULL ;
struct V_35 * V_36 = NULL ;
F_11 ( & V_2 -> V_27 ) ;
F_31 ( V_69 ) ;
if ( V_2 -> V_21 == V_70 )
goto V_71;
V_64 =
F_19 ( V_2 ,
V_45 ,
V_2 -> V_46 ) ;
if ( ! V_64 ) {
V_34 = - V_72 ;
F_20 ( V_34 ) ;
goto V_71;
}
V_2 -> V_21 = V_26 ;
F_32 ( & V_2 -> V_73 ) ;
V_67 = F_19 ( V_2 ,
V_74 ,
V_75 ) ;
if ( ! V_67 ) {
V_34 = - V_47 ;
F_20 ( V_34 ) ;
goto V_71;
}
F_33 ( & V_67 -> V_76 ) ;
V_34 = F_34 ( V_67 , & V_66 , 1 ) ;
if ( V_34 < 0 ) {
F_20 ( V_34 ) ;
goto V_77;
}
V_63 = F_35 ( V_2 , V_78 ) ;
if ( F_36 ( V_63 ) ) {
F_20 ( F_37 ( V_63 ) ) ;
V_63 = NULL ;
goto V_79;
}
V_65 = V_2 -> V_62 ;
V_36 = (struct V_35 * ) V_65 -> V_49 ;
V_68 = F_38 ( V_65 -> V_80 , V_81 ) ;
if ( ! V_68 ) {
V_34 = - V_82 ;
goto V_83;
}
memcpy ( V_68 , V_36 , V_65 -> V_80 ) ;
V_34 = F_39 ( V_63 , F_40 ( V_64 ) ,
V_65 , V_84 ) ;
if ( V_34 < 0 ) {
F_20 ( V_34 ) ;
goto V_83;
}
F_41 ( V_36 ) ;
F_42 ( V_63 , V_65 ) ;
F_27 ( V_65 ) ;
V_2 -> V_62 = NULL ;
V_2 -> V_21 = V_70 ;
V_34 = F_43 ( V_2 , V_63 , V_68 ,
V_67 , V_66 ) ;
if ( V_34 < 0 )
F_20 ( V_34 ) ;
V_83:
F_44 ( V_2 , V_63 ) ;
V_79:
F_27 ( V_66 ) ;
F_45 ( V_67 , 1 ) ;
V_77:
F_46 ( & V_67 -> V_76 ) ;
F_28 ( V_67 ) ;
V_71:
if ( V_64 )
F_28 ( V_64 ) ;
if ( V_68 )
F_47 ( V_68 ) ;
}
int F_48 ( struct V_1 * V_2 ,
int V_46 ,
struct V_35 * * V_68 )
{
int V_34 = 0 ;
struct V_37 * V_38 = NULL ;
struct V_40 * V_40 = NULL ;
struct V_35 * V_36 ;
F_49 ( V_46 ) ;
* V_68 = NULL ;
V_40 = F_19 ( V_2 ,
V_45 ,
V_46 ) ;
if ( ! V_40 ) {
V_34 = - V_47 ;
F_20 ( V_34 ) ;
goto V_33;
}
F_33 ( & V_40 -> V_76 ) ;
V_34 = F_21 ( V_40 , & V_38 ,
V_48 ) ;
if ( V_34 < 0 ) {
F_20 ( V_34 ) ;
goto V_33;
}
* V_68 = F_38 ( V_38 -> V_80 , V_85 ) ;
if ( ! ( * V_68 ) ) {
V_34 = - V_82 ;
goto V_33;
}
memcpy ( ( * V_68 ) , V_38 -> V_49 , V_38 -> V_80 ) ;
V_36 = (struct V_35 * ) V_38 -> V_49 ;
F_41 ( V_36 ) ;
F_50 ( V_2 -> V_8 , V_38 -> V_49 , & V_36 -> V_86 ) ;
V_34 = F_51 ( V_2 , V_38 , F_40 ( V_40 ) ) ;
if ( V_34 < 0 )
F_20 ( V_34 ) ;
V_33:
if ( ( V_34 < 0 ) && ( * V_68 ) ) {
F_47 ( * V_68 ) ;
* V_68 = NULL ;
}
F_27 ( V_38 ) ;
if ( V_40 ) {
F_46 ( & V_40 -> V_76 ) ;
F_28 ( V_40 ) ;
}
if ( V_34 )
F_20 ( V_34 ) ;
return V_34 ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_34 ;
T_3 * V_63 ;
struct V_37 * V_66 = NULL ;
struct V_40 * V_67 ;
V_67 = F_19 ( V_2 ,
V_74 ,
V_75 ) ;
if ( ! V_67 ) {
V_34 = - V_47 ;
F_20 ( V_34 ) ;
goto V_71;
}
F_33 ( & V_67 -> V_76 ) ;
V_34 = F_34 ( V_67 , & V_66 , 1 ) ;
if ( V_34 < 0 ) {
F_20 ( V_34 ) ;
goto V_77;
}
V_63 = F_35 ( V_2 , V_78 ) ;
if ( F_36 ( V_63 ) ) {
V_34 = F_37 ( V_63 ) ;
V_63 = NULL ;
F_20 ( V_34 ) ;
goto V_79;
}
V_63 -> V_87 = 1 ;
V_34 = F_43 ( V_2 , V_63 , V_36 ,
V_67 , V_66 ) ;
if ( V_34 < 0 )
F_20 ( V_34 ) ;
F_44 ( V_2 , V_63 ) ;
V_79:
F_45 ( V_67 , 1 ) ;
V_77:
F_46 ( & V_67 -> V_76 ) ;
F_27 ( V_66 ) ;
F_28 ( V_67 ) ;
V_71:
if ( ! V_34 )
F_53 ( V_2 ) ;
if ( V_34 )
F_20 ( V_34 ) ;
return V_34 ;
}
int F_54 ( struct V_1 * V_2 ,
T_2 V_88 ,
struct V_89 * V_90 )
{
int V_34 ;
struct V_35 * V_36 ;
struct V_40 * V_64 ;
unsigned int V_91 ;
F_55 ( ! V_90 ) ;
V_64 =
F_19 ( V_2 ,
V_45 ,
V_2 -> V_46 ) ;
if ( ! V_64 ) {
V_34 = - V_72 ;
F_20 ( V_34 ) ;
goto V_33;
}
F_33 ( & V_64 -> V_76 ) ;
F_10 ( & V_2 -> V_25 ) ;
if ( ! F_8 ( V_2 ) ||
( V_88 > V_2 -> V_20 ) ) {
F_12 ( & V_2 -> V_25 ) ;
V_34 = - V_92 ;
goto V_33;
}
F_12 ( & V_2 -> V_25 ) ;
V_36 = (struct V_35 * ) V_2 -> V_62 -> V_49 ;
#ifdef F_56
if ( F_23 ( V_36 -> V_57 . V_58 . V_59 ) !=
F_26 ( V_36 ) ) {
F_57 ( V_2 -> V_8 , L_7
L_8 ,
( unsigned long long ) F_58 ( V_36 -> V_93 ) ,
F_23 ( V_36 -> V_57 . V_58 . V_59 ) ,
F_26 ( V_36 ) ) ;
V_34 = - V_94 ;
goto V_33;
}
#endif
V_91 = F_23 ( V_36 -> V_57 . V_58 . V_60 ) -
F_23 ( V_36 -> V_57 . V_58 . V_59 ) ;
if ( V_88 > V_91 ) {
V_34 =
F_59 ( V_2 , V_64 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_92 )
F_20 ( V_34 ) ;
goto V_33;
}
V_34 = - V_92 ;
if ( ! F_8 ( V_2 ) )
goto V_33;
V_91 = F_23 ( V_36 -> V_57 . V_58 . V_60 ) -
F_23 ( V_36 -> V_57 . V_58 . V_59 ) ;
if ( V_88 > V_91 )
goto V_33;
}
V_90 -> V_95 = V_64 ;
V_90 -> V_96 = V_2 -> V_46 ;
V_90 -> V_97 = V_98 ;
F_60 ( V_2 -> V_62 ) ;
V_90 -> V_99 = V_2 -> V_62 ;
V_34 = 0 ;
V_33:
if ( V_34 < 0 && V_64 ) {
F_46 ( & V_64 -> V_76 ) ;
F_28 ( V_64 ) ;
}
F_61 (
( unsigned long long ) V_90 -> V_100 ,
V_88 , V_2 -> V_46 , V_34 ) ;
if ( V_34 )
F_20 ( V_34 ) ;
return V_34 ;
}
int F_62 ( struct V_1 * V_2 ,
T_3 * V_63 ,
struct V_89 * V_90 ,
T_2 V_88 ,
T_2 * V_101 ,
T_2 * V_102 )
{
int V_34 , V_103 ;
struct V_40 * V_64 ;
void * V_104 ;
struct V_35 * V_36 ;
struct V_41 * V_42 ;
F_55 ( V_90 -> V_97 != V_98 ) ;
V_64 = V_90 -> V_95 ;
V_36 = (struct V_35 * ) V_2 -> V_62 -> V_49 ;
V_42 = F_22 ( V_36 ) ;
V_103 = F_63 ( V_2 , V_36 , & V_88 ,
V_90 -> V_105 ) ;
if ( V_103 == - 1 ) {
V_34 = - V_92 ;
F_20 ( V_34 ) ;
goto V_33;
}
V_104 = V_42 -> V_106 ;
* V_101 = F_23 ( V_42 -> V_61 ) + V_103 ;
* V_102 = V_88 ;
V_34 = F_39 ( V_63 ,
F_40 ( V_64 ) ,
V_2 -> V_62 ,
V_84 ) ;
if ( V_34 < 0 ) {
F_20 ( V_34 ) ;
goto V_33;
}
F_64 ( & V_2 -> V_73 , V_90 -> V_105 , V_103 ,
V_88 ) ;
while( V_88 -- )
F_65 ( V_103 ++ , V_104 ) ;
F_66 ( & V_36 -> V_57 . V_58 . V_59 , * V_102 ) ;
F_42 ( V_63 , V_2 -> V_62 ) ;
V_33:
if ( V_34 )
F_20 ( V_34 ) ;
return V_34 ;
}
static T_2 F_26 ( struct V_35 * V_36 )
{
T_2 V_107 ;
struct V_41 * V_42 = F_22 ( V_36 ) ;
V_107 = F_67 ( V_42 -> V_106 , F_25 ( V_42 -> V_55 ) ) ;
F_68 ( V_107 ) ;
return V_107 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
T_2 * V_108 ,
struct V_109 * V_110 )
{
int V_111 , V_112 , V_113 , V_114 , V_115 ;
int V_116 = 0 ;
struct V_109 V_117 ;
void * V_104 = NULL ;
struct V_118 * V_119 = & V_2 -> V_73 ;
if ( ! V_36 -> V_57 . V_58 . V_60 ) {
V_112 = - 1 ;
goto V_33;
}
if ( ! V_110 ) {
V_116 = 1 ;
F_69 ( & V_117 ) ;
F_70 ( & V_117 , V_120 ) ;
V_110 = & V_117 ;
}
V_111 = * V_108 ;
if ( F_71 ( V_119 , V_110 , & V_112 , & V_111 ) == 0 ) {
if ( V_111 < * V_108 )
* V_108 = V_111 ;
goto V_33;
}
F_55 ( V_2 -> V_121 != 0 ) ;
V_104 = F_22 ( V_36 ) -> V_106 ;
V_111 = V_112 = V_114 = 0 ;
V_115 = - 1 ;
V_113 = F_23 ( V_36 -> V_57 . V_58 . V_60 ) ;
while ( ( V_112 = F_72 ( V_104 , V_113 , V_114 ) ) != - 1 ) {
if ( V_112 == V_113 ) {
break;
}
if ( V_112 == V_114 ) {
V_111 ++ ;
V_114 ++ ;
} else {
V_111 = 1 ;
V_114 = V_112 + 1 ;
}
if ( V_111 == * V_108 ) {
break;
}
}
F_73 ( V_112 , V_111 ) ;
if ( V_111 == * V_108 )
V_112 = V_114 - V_111 ;
else
V_112 = - 1 ;
V_33:
if ( V_116 )
F_74 ( V_119 , V_110 ) ;
F_75 ( * V_108 ,
F_23 ( V_36 -> V_57 . V_58 . V_60 ) ,
V_112 , V_111 ) ;
return V_112 ;
}
static void F_41 ( struct V_35 * V_36 )
{
struct V_41 * V_42 = F_22 ( V_36 ) ;
int V_122 ;
V_36 -> V_57 . V_58 . V_60 = 0 ;
V_36 -> V_57 . V_58 . V_59 = 0 ;
V_42 -> V_61 = 0 ;
for( V_122 = 0 ; V_122 < F_25 ( V_42 -> V_55 ) ; V_122 ++ )
V_42 -> V_106 [ V_122 ] = 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
T_3 * V_63 ,
struct V_35 * V_36 ,
struct V_40 * V_67 ,
struct V_37 * V_66 )
{
int V_34 = 0 ;
int V_101 , V_113 , V_107 , V_103 ;
T_1 V_123 ;
T_1 V_124 ;
void * V_104 ;
struct V_41 * V_42 = F_22 ( V_36 ) ;
F_76 (
F_23 ( V_36 -> V_57 . V_58 . V_60 ) ,
F_23 ( V_36 -> V_57 . V_58 . V_59 ) ) ;
if ( ! V_36 -> V_57 . V_58 . V_60 ) {
goto V_33;
}
if ( F_23 ( V_36 -> V_57 . V_58 . V_59 ) ==
F_23 ( V_36 -> V_57 . V_58 . V_60 ) ) {
goto V_33;
}
V_123 = F_77 ( V_2 -> V_8 ,
F_23 ( V_42 -> V_61 ) ) ;
V_104 = V_42 -> V_106 ;
V_103 = V_107 = V_101 = 0 ;
V_113 = F_23 ( V_36 -> V_57 . V_58 . V_60 ) ;
while ( ( V_101 = F_72 ( V_104 , V_113 , V_103 ) )
!= - 1 ) {
if ( ( V_101 < V_113 ) && ( V_101 == V_103 ) ) {
V_107 ++ ;
V_103 ++ ;
continue;
}
if ( V_107 ) {
V_124 = V_123 +
F_77 ( V_2 -> V_8 ,
V_103 - V_107 ) ;
F_78 (
V_107 , V_103 - V_107 ,
( unsigned long long ) V_123 ,
( unsigned long long ) V_124 ) ;
V_34 = F_79 ( V_63 ,
V_67 ,
V_66 , V_124 ,
V_107 ) ;
if ( V_34 < 0 ) {
F_20 ( V_34 ) ;
goto V_33;
}
}
if ( V_101 >= V_113 )
break;
V_107 = 1 ;
V_103 = V_101 + 1 ;
}
V_33:
if ( V_34 )
F_20 ( V_34 ) ;
return V_34 ;
}
static int F_80 ( struct V_1 * V_2 ,
enum V_125 V_126 )
{
unsigned int V_30 ;
int V_127 ;
F_10 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_21 == V_26 ) {
F_81 ( V_2 -> V_21 == V_26 ) ;
goto V_79;
}
if ( V_126 == V_128 ||
V_126 == V_129 ) {
V_30 = V_2 -> V_20 >> 1 ;
if ( V_30 > F_7 ( V_2 -> V_8 , 1 ) ) {
V_2 -> V_21 = V_22 ;
V_2 -> V_20 = V_30 ;
} else {
V_2 -> V_21 = V_26 ;
}
F_82 ( V_69 , & V_2 -> V_27 ,
V_130 ) ;
goto V_79;
}
if ( V_2 -> V_21 != V_22 )
V_2 -> V_20 = V_2 -> V_19 ;
V_79:
V_127 = V_2 -> V_21 ;
F_12 ( & V_2 -> V_25 ) ;
return V_127 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_89 * * V_90 ,
struct V_40 * * V_131 ,
struct V_37 * * V_132 )
{
int V_34 ;
* V_90 = F_84 ( sizeof( struct V_89 ) , V_85 ) ;
if ( ! ( * V_90 ) ) {
V_34 = - V_82 ;
F_20 ( V_34 ) ;
goto V_33;
}
V_133:
( * V_90 ) -> V_134 = V_2 -> V_19 ;
V_34 = F_85 ( V_2 , * V_90 ) ;
if ( V_34 == - V_92 ) {
if ( F_80 ( V_2 , V_128 ) ==
V_26 )
goto V_33;
F_86 ( * V_90 ) ;
memset ( * V_90 , 0 , sizeof( struct V_89 ) ) ;
goto V_133;
}
if ( V_34 < 0 ) {
F_20 ( V_34 ) ;
goto V_33;
}
* V_131 = ( * V_90 ) -> V_95 ;
F_87 ( * V_131 ) ;
* V_132 = ( * V_90 ) -> V_99 ;
F_60 ( * V_132 ) ;
V_34 = 0 ;
V_33:
if ( ( V_34 < 0 ) && * V_90 ) {
F_88 ( * V_90 ) ;
* V_90 = NULL ;
}
if ( V_34 )
F_20 ( V_34 ) ;
return V_34 ;
}
static int F_89 ( struct V_1 * V_2 ,
T_3 * V_63 ,
struct V_89 * V_90 )
{
int V_34 = 0 ;
T_2 V_135 , V_136 ;
struct V_35 * V_36 = NULL ;
struct V_41 * V_42 ;
V_36 = (struct V_35 * ) V_2 -> V_62 -> V_49 ;
V_42 = F_22 ( V_36 ) ;
F_90 (
F_23 ( V_36 -> V_57 . V_58 . V_60 ) ,
V_2 -> V_20 ) ;
V_90 -> V_137 = V_2 -> V_138 ;
V_34 = F_91 ( V_63 , V_90 , V_2 -> V_20 ,
& V_135 , & V_136 ) ;
if ( V_34 == - V_92 ) {
V_133:
if ( F_80 ( V_2 , V_129 ) ==
V_26 )
goto V_33;
V_90 -> V_134 = V_2 -> V_19 ;
V_34 = F_91 ( V_63 , V_90 ,
V_2 -> V_20 ,
& V_135 ,
& V_136 ) ;
if ( V_34 == - V_92 )
goto V_133;
if ( V_34 == 0 ) {
F_10 ( & V_2 -> V_25 ) ;
V_2 -> V_20 = V_136 ;
F_12 ( & V_2 -> V_25 ) ;
}
}
if ( V_34 < 0 ) {
if ( V_34 != - V_92 )
F_20 ( V_34 ) ;
goto V_33;
}
V_2 -> V_138 = V_90 -> V_137 ;
V_42 -> V_61 = F_92 ( V_135 ) ;
V_36 -> V_57 . V_58 . V_60 = F_92 ( V_136 ) ;
V_36 -> V_57 . V_58 . V_59 = 0 ;
memset ( F_22 ( V_36 ) -> V_106 , 0 ,
F_25 ( V_42 -> V_55 ) ) ;
F_93 ( & V_2 -> V_73 , V_136 ,
F_22 ( V_36 ) -> V_106 ) ;
F_94 (
F_22 ( V_36 ) -> V_61 ,
F_23 ( V_36 -> V_57 . V_58 . V_60 ) ) ;
V_33:
if ( V_34 )
F_20 ( V_34 ) ;
return V_34 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_40 * V_64 )
{
int V_34 = 0 ;
struct V_37 * V_66 = NULL ;
struct V_40 * V_67 = NULL ;
T_3 * V_63 = NULL ;
struct V_35 * V_36 ;
struct V_35 * V_68 = NULL ;
struct V_89 * V_90 = NULL ;
F_80 ( V_2 , V_139 ) ;
V_34 = F_83 ( V_2 ,
& V_90 ,
& V_67 ,
& V_66 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_92 )
F_20 ( V_34 ) ;
goto V_33;
}
V_63 = F_35 ( V_2 , V_78 ) ;
if ( F_36 ( V_63 ) ) {
V_34 = F_37 ( V_63 ) ;
V_63 = NULL ;
F_20 ( V_34 ) ;
goto V_33;
}
V_36 = (struct V_35 * ) V_2 -> V_62 -> V_49 ;
V_68 = F_38 ( V_2 -> V_62 -> V_80 , V_81 ) ;
if ( ! V_68 ) {
V_34 = - V_82 ;
F_20 ( V_34 ) ;
goto V_33;
}
memcpy ( V_68 , V_36 , V_2 -> V_62 -> V_80 ) ;
V_34 = F_39 ( V_63 ,
F_40 ( V_64 ) ,
V_2 -> V_62 ,
V_84 ) ;
if ( V_34 < 0 ) {
F_20 ( V_34 ) ;
goto V_33;
}
F_41 ( V_36 ) ;
F_42 ( V_63 , V_2 -> V_62 ) ;
V_34 = F_43 ( V_2 , V_63 , V_68 ,
V_67 , V_66 ) ;
if ( V_34 < 0 ) {
F_20 ( V_34 ) ;
goto V_33;
}
V_34 = F_89 ( V_2 , V_63 , V_90 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_92 )
F_20 ( V_34 ) ;
goto V_33;
}
F_95 ( & V_2 -> V_140 . V_141 ) ;
V_33:
if ( V_63 )
F_44 ( V_2 , V_63 ) ;
F_27 ( V_66 ) ;
if ( V_67 )
F_28 ( V_67 ) ;
if ( V_68 )
F_47 ( V_68 ) ;
if ( V_90 )
F_88 ( V_90 ) ;
if ( V_34 )
F_20 ( V_34 ) ;
return V_34 ;
}
