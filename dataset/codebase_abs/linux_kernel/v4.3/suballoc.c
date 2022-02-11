static T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 0 )
return 0 ;
if ( V_2 -> V_4 )
return V_2 -> V_4 ;
return F_2 ( V_2 -> V_3 , V_2 -> V_5 ) ;
}
void F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = V_7 -> V_9 ;
if ( V_8 ) {
if ( V_7 -> V_10 != V_11 )
F_4 ( V_8 , 1 ) ;
F_5 ( & V_8 -> V_12 ) ;
F_6 ( V_8 ) ;
V_7 -> V_9 = NULL ;
}
F_7 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
V_7 -> V_14 = NULL ;
F_8 ( V_7 -> V_15 ) ;
V_7 -> V_15 = NULL ;
}
void F_9 ( struct V_6 * V_7 )
{
F_3 ( V_7 ) ;
F_8 ( V_7 ) ;
}
static T_2 F_10 ( struct V_16 * V_17 )
{
return ( T_2 ) F_11 ( V_17 -> V_18 ) * ( T_2 ) F_11 ( V_17 -> V_19 ) ;
}
static int F_12 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
int V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_23 -> V_27 ;
if ( ! F_13 ( V_26 ) ) {
F_14 ( L_1 ,
( unsigned long long ) V_23 -> V_28 , 7 ,
V_26 -> V_29 ) ;
}
if ( F_15 ( V_26 -> V_30 ) != V_23 -> V_28 ) {
F_14 ( L_2 ,
( unsigned long long ) V_23 -> V_28 ,
( unsigned long long ) F_15 ( V_26 -> V_30 ) ) ;
}
if ( F_16 ( V_26 -> V_31 ) != F_17 ( V_21 ) -> V_32 ) {
F_14 ( L_3 ,
( unsigned long long ) V_23 -> V_28 ,
F_16 ( V_26 -> V_31 ) ) ;
}
if ( F_11 ( V_26 -> V_33 ) > F_11 ( V_26 -> V_34 ) ) {
F_14 ( L_4 ,
( unsigned long long ) V_23 -> V_28 ,
F_11 ( V_26 -> V_34 ) ,
F_11 ( V_26 -> V_33 ) ) ;
}
if ( F_11 ( V_26 -> V_34 ) > ( 8 * F_11 ( V_26 -> V_35 ) ) ) {
F_14 ( L_5 ,
( unsigned long long ) V_23 -> V_28 ,
F_11 ( V_26 -> V_34 ) ,
8 * F_11 ( V_26 -> V_35 ) ) ;
}
return 0 ;
}
static int F_18 ( struct V_20 * V_21 ,
struct V_36 * V_37 ,
struct V_22 * V_23 ,
int V_24 )
{
unsigned int V_38 ;
struct V_25 * V_26 = (struct V_25 * ) V_23 -> V_27 ;
if ( V_37 -> V_39 != V_26 -> V_40 ) {
F_14 ( L_6 ,
( unsigned long long ) V_23 -> V_28 ,
( unsigned long long ) F_15 ( V_26 -> V_40 ) ,
( unsigned long long ) F_15 ( V_37 -> V_39 ) ) ;
}
V_38 = F_11 ( V_37 -> V_41 . V_42 . V_18 ) * F_11 ( V_37 -> V_41 . V_42 . V_19 ) ;
if ( F_11 ( V_26 -> V_34 ) > V_38 ) {
F_14 ( L_7 ,
( unsigned long long ) V_23 -> V_28 ,
F_11 ( V_26 -> V_34 ) ) ;
}
if ( ( F_11 ( V_26 -> V_43 ) >
F_11 ( V_37 -> V_41 . V_42 . V_44 ) ) ||
( ( F_11 ( V_26 -> V_43 ) ==
F_11 ( V_37 -> V_41 . V_42 . V_44 ) ) && ! V_24 ) ) {
F_14 ( L_8 ,
( unsigned long long ) V_23 -> V_28 ,
F_11 ( V_26 -> V_43 ) ) ;
}
return 0 ;
}
int F_19 ( struct V_20 * V_21 ,
struct V_36 * V_37 ,
struct V_22 * V_23 )
{
int V_45 ;
struct V_25 * V_26 = (struct V_25 * ) V_23 -> V_27 ;
F_20 ( ! F_21 ( V_23 ) ) ;
V_45 = F_22 ( V_21 , V_23 -> V_27 , & V_26 -> V_46 ) ;
if ( V_45 ) {
F_23 ( V_47 ,
L_9 ,
( unsigned long long ) V_23 -> V_28 ) ;
} else
V_45 = F_12 ( V_21 , V_23 , 1 ) ;
if ( ! V_45 )
V_45 = F_18 ( V_21 , V_37 , V_23 , 1 ) ;
return V_45 ;
}
static int F_24 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
int V_45 ;
struct V_25 * V_26 = (struct V_25 * ) V_23 -> V_27 ;
F_25 (
( unsigned long long ) V_23 -> V_28 ) ;
F_20 ( ! F_21 ( V_23 ) ) ;
V_45 = F_22 ( V_21 , V_23 -> V_27 , & V_26 -> V_46 ) ;
if ( V_45 )
return V_45 ;
return F_12 ( V_21 , V_23 , 0 ) ;
}
int F_26 ( struct V_8 * V_8 , struct V_36 * V_37 ,
T_1 V_48 , struct V_22 * * V_23 )
{
int V_45 ;
struct V_22 * V_49 = * V_23 ;
V_45 = F_27 ( F_28 ( V_8 ) , V_48 , & V_49 ,
F_24 ) ;
if ( V_45 )
goto V_50;
V_45 = F_18 ( V_8 -> V_51 , V_37 , V_49 , 0 ) ;
if ( V_45 ) {
F_7 ( V_49 ) ;
goto V_50;
}
if ( ! * V_23 )
* V_23 = V_49 ;
V_50:
return V_45 ;
}
static void F_29 ( struct V_52 * V_53 ,
struct V_25 * V_54 ,
struct V_16 * V_17 ,
T_1 V_55 , unsigned int V_56 )
{
struct V_57 * V_58 = & V_54 -> V_59 ;
struct V_60 * V_61 ;
F_20 ( ! F_30 ( V_53 ) ) ;
if ( ! V_58 -> V_62 )
V_58 -> V_63 = F_31 ( F_32 ( V_53 -> V_21 ) ) ;
V_61 = & V_58 -> V_64 [ F_11 ( V_58 -> V_62 ) ] ;
V_61 -> V_65 = F_33 ( V_55 ) ;
V_61 -> V_66 = F_34 ( F_11 ( V_54 -> V_34 ) /
F_11 ( V_17 -> V_19 ) ) ;
V_61 -> V_67 = F_31 ( V_56 ) ;
F_35 ( & V_54 -> V_34 , V_56 * F_11 ( V_17 -> V_19 ) ) ;
F_35 ( & V_54 -> V_33 ,
V_56 * F_11 ( V_17 -> V_19 ) ) ;
F_35 ( & V_58 -> V_62 , 1 ) ;
}
static int F_36 ( T_3 * V_68 ,
struct V_8 * V_69 ,
struct V_22 * V_70 ,
T_1 V_71 ,
unsigned int V_72 ,
T_4 V_73 ,
struct V_16 * V_17 )
{
int V_74 = 0 ;
struct V_52 * V_53 = F_17 ( V_69 -> V_51 ) ;
struct V_25 * V_54 = (struct V_25 * ) V_70 -> V_27 ;
struct V_20 * V_21 = V_69 -> V_51 ;
if ( ( ( unsigned long long ) V_70 -> V_28 ) != V_71 ) {
V_74 = F_37 ( V_69 -> V_51 ,
L_10 ,
( unsigned long long ) V_71 ,
( unsigned long long ) V_70 -> V_28 ) ;
goto V_75;
}
V_74 = F_38 ( V_68 ,
F_28 ( V_69 ) ,
V_70 ,
V_76 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
memset ( V_54 , 0 , V_21 -> V_77 ) ;
strcpy ( V_54 -> V_29 , V_78 ) ;
V_54 -> V_31 = F_34 ( F_17 ( V_21 ) -> V_32 ) ;
V_54 -> V_35 = F_31 ( F_40 ( V_21 , 1 ,
V_53 -> V_79 ) ) ;
V_54 -> V_43 = F_31 ( V_73 ) ;
V_54 -> V_80 = V_17 -> V_81 [ V_73 ] . V_82 ;
V_54 -> V_40 = F_33 ( F_41 ( V_69 ) -> V_83 ) ;
V_54 -> V_30 = F_33 ( V_71 ) ;
if ( V_72 == F_11 ( V_17 -> V_18 ) )
V_54 -> V_34 = F_31 ( F_10 ( V_17 ) ) ;
else
F_29 ( V_53 , V_54 , V_17 , V_71 ,
V_72 ) ;
F_42 ( 0 , ( unsigned long * ) V_54 -> V_84 ) ;
V_54 -> V_33 = F_31 ( F_11 ( V_54 -> V_34 ) - 1 ) ;
F_43 ( V_68 , V_70 ) ;
V_75:
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
static inline T_4 F_44 ( struct V_16 * V_17 )
{
T_4 V_85 , V_86 ;
V_86 = V_85 = 0 ;
while ( V_85 < F_11 ( V_17 -> V_87 ) ) {
if ( F_16 ( V_17 -> V_81 [ V_86 ] . V_88 ) >
F_16 ( V_17 -> V_81 [ V_85 ] . V_88 ) )
V_86 = V_85 ;
V_85 ++ ;
}
return V_86 ;
}
static struct V_22 *
F_45 ( struct V_52 * V_53 , T_3 * V_68 ,
struct V_8 * V_69 ,
struct V_6 * V_7 ,
struct V_16 * V_17 )
{
int V_74 ;
T_2 V_89 , V_90 ;
T_1 V_30 ;
struct V_22 * V_70 ;
unsigned int V_91 = F_44 ( V_17 ) ;
V_74 = F_46 ( V_68 , V_7 ,
F_11 ( V_17 -> V_18 ) , & V_89 ,
& V_90 ) ;
if ( V_74 < 0 ) {
if ( V_74 != - V_92 )
F_39 ( V_74 ) ;
goto V_75;
}
V_30 = F_47 ( V_53 -> V_21 , V_89 ) ;
F_48 (
( unsigned long long ) V_30 , V_91 ) ;
V_70 = F_49 ( V_53 -> V_21 , V_30 ) ;
if ( ! V_70 ) {
V_74 = - V_93 ;
F_39 ( V_74 ) ;
goto V_75;
}
F_50 ( F_28 ( V_69 ) , V_70 ) ;
V_74 = F_36 ( V_68 , V_69 , V_70 ,
V_30 , V_90 , V_91 , V_17 ) ;
if ( V_74 < 0 ) {
F_7 ( V_70 ) ;
F_39 ( V_74 ) ;
}
V_75:
return V_74 ? F_51 ( V_74 ) : V_70 ;
}
static int F_52 ( struct V_52 * V_53 ,
T_3 * V_68 ,
struct V_6 * V_7 ,
unsigned int V_94 ,
T_2 * V_89 , T_2 * V_90 )
{
int V_74 = 0 ;
while ( V_94 ) {
V_74 = F_46 ( V_68 , V_7 , V_94 ,
V_89 , V_90 ) ;
if ( V_74 != - V_92 )
break;
V_94 >>= 1 ;
}
return V_74 ;
}
static int F_53 ( T_3 * V_68 ,
struct V_8 * V_69 ,
struct V_22 * V_70 ,
struct V_6 * V_7 ,
struct V_16 * V_17 ,
unsigned int V_94 )
{
int V_74 ;
struct V_52 * V_53 = F_17 ( V_69 -> V_51 ) ;
struct V_25 * V_54 =
(struct V_25 * ) V_70 -> V_27 ;
unsigned int V_95 = F_11 ( V_17 -> V_18 ) -
F_11 ( V_54 -> V_34 ) / F_11 ( V_17 -> V_19 ) ;
T_2 V_96 , V_56 ;
T_1 V_55 ;
struct V_57 * V_58 = & V_54 -> V_59 ;
V_74 = F_38 ( V_68 ,
F_28 ( V_69 ) ,
V_70 ,
V_76 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
while ( ( V_95 > 0 ) && ( F_11 ( V_58 -> V_62 ) <
F_11 ( V_58 -> V_63 ) ) ) {
if ( V_94 > V_95 )
V_94 = V_95 ;
V_74 = F_52 ( V_53 , V_68 , V_7 ,
V_94 , & V_96 ,
& V_56 ) ;
if ( V_74 < 0 ) {
if ( V_74 != - V_92 )
F_39 ( V_74 ) ;
goto V_75;
}
V_55 = F_47 ( V_53 -> V_21 , V_96 ) ;
F_29 ( V_53 , V_54 , V_17 , V_55 ,
V_56 ) ;
V_94 = V_56 ;
V_95 = F_11 ( V_17 -> V_18 ) -
F_11 ( V_54 -> V_34 ) / F_11 ( V_17 -> V_19 ) ;
}
if ( V_95 > 0 ) {
V_74 = - V_92 ;
goto V_75;
}
F_43 ( V_68 , V_70 ) ;
V_75:
return V_74 ;
}
static void F_54 ( T_3 * V_68 ,
struct V_6 * V_97 ,
struct V_8 * V_69 ,
struct V_22 * V_70 )
{
int V_98 , V_99 ;
struct V_25 * V_54 ;
struct V_57 * V_58 ;
struct V_60 * V_61 ;
if ( ! V_70 )
return;
V_54 = (struct V_25 * ) V_70 -> V_27 ;
V_58 = & V_54 -> V_59 ;
for ( V_98 = 0 ; V_98 < F_11 ( V_58 -> V_62 ) ; V_98 ++ ) {
V_61 = & V_58 -> V_64 [ V_98 ] ;
V_99 = F_55 ( V_68 , V_97 -> V_9 ,
V_97 -> V_13 ,
F_15 ( V_61 -> V_65 ) ,
F_11 ( V_61 -> V_67 ) ) ;
if ( V_99 )
F_39 ( V_99 ) ;
}
F_56 ( F_28 ( V_69 ) , V_70 ) ;
F_7 ( V_70 ) ;
}
static struct V_22 *
F_57 ( T_3 * V_68 ,
struct V_8 * V_69 ,
struct V_6 * V_7 ,
struct V_16 * V_17 )
{
int V_74 ;
T_2 V_89 , V_90 ;
T_1 V_30 ;
unsigned int V_94 = F_11 ( V_17 -> V_18 ) >> 1 ;
struct V_22 * V_70 = NULL ;
unsigned int V_91 = F_44 ( V_17 ) ;
struct V_52 * V_53 = F_17 ( V_69 -> V_51 ) ;
if ( ! F_30 ( V_53 ) ) {
V_74 = - V_92 ;
goto V_75;
}
V_74 = F_58 ( V_68 ,
F_59 ( V_53 -> V_21 ) ) ;
if ( V_74 ) {
F_39 ( V_74 ) ;
goto V_75;
}
V_7 -> V_100 = 1 ;
V_74 = F_52 ( V_53 , V_68 , V_7 , V_94 ,
& V_89 , & V_90 ) ;
if ( V_74 < 0 ) {
if ( V_74 != - V_92 )
F_39 ( V_74 ) ;
goto V_75;
}
V_94 = V_90 ;
V_30 = F_47 ( V_53 -> V_21 , V_89 ) ;
F_60 (
( unsigned long long ) V_30 , V_91 ) ;
V_70 = F_49 ( V_53 -> V_21 , V_30 ) ;
if ( ! V_70 ) {
V_74 = - V_93 ;
F_39 ( V_74 ) ;
goto V_75;
}
F_50 ( F_28 ( V_69 ) , V_70 ) ;
V_74 = F_36 ( V_68 , V_69 , V_70 ,
V_30 , V_90 , V_91 , V_17 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
V_74 = F_53 ( V_68 , V_69 ,
V_70 , V_7 , V_17 , V_94 ) ;
if ( V_74 )
F_39 ( V_74 ) ;
V_75:
if ( V_74 )
F_54 ( V_68 , V_7 , V_69 , V_70 ) ;
return V_74 ? F_51 ( V_74 ) : V_70 ;
}
static int F_61 ( struct V_52 * V_53 ,
struct V_8 * V_69 ,
struct V_22 * V_23 ,
T_1 V_101 ,
T_1 * V_102 ,
int V_103 )
{
int V_74 , V_104 ;
struct V_36 * V_105 = (struct V_36 * ) V_23 -> V_27 ;
struct V_16 * V_17 ;
struct V_6 * V_7 = NULL ;
T_3 * V_68 = NULL ;
T_4 V_91 ;
struct V_22 * V_70 = NULL ;
struct V_25 * V_54 ;
F_20 ( F_62 ( V_69 ) ) ;
V_17 = & V_105 -> V_41 . V_42 ;
V_74 = F_63 ( V_53 ,
F_11 ( V_17 -> V_18 ) ,
V_101 , V_103 , & V_7 ) ;
if ( V_74 < 0 ) {
if ( V_74 != - V_92 )
F_39 ( V_74 ) ;
goto V_75;
}
V_104 = F_64 ( V_53 -> V_21 ,
F_11 ( V_17 -> V_18 ) ) ;
V_68 = F_65 ( V_53 , V_104 ) ;
if ( F_66 ( V_68 ) ) {
V_74 = F_67 ( V_68 ) ;
V_68 = NULL ;
F_39 ( V_74 ) ;
goto V_75;
}
if ( V_102 && * V_102 != 0 ) {
F_68 (
( unsigned long long ) * V_102 ) ;
V_7 -> V_106 = * V_102 ;
}
V_70 = F_45 ( V_53 , V_68 , V_69 ,
V_7 , V_17 ) ;
if ( F_66 ( V_70 ) && ( F_67 ( V_70 ) == - V_92 ) )
V_70 = F_57 ( V_68 ,
V_69 ,
V_7 , V_17 ) ;
if ( F_66 ( V_70 ) ) {
V_74 = F_67 ( V_70 ) ;
V_70 = NULL ;
if ( V_74 != - V_92 )
F_39 ( V_74 ) ;
goto V_75;
}
V_54 = (struct V_25 * ) V_70 -> V_27 ;
V_74 = F_69 ( V_68 , F_28 ( V_69 ) ,
V_23 , V_107 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
V_91 = F_11 ( V_54 -> V_43 ) ;
F_70 ( & V_17 -> V_81 [ V_91 ] . V_108 ,
F_11 ( V_54 -> V_33 ) ) ;
F_70 ( & V_17 -> V_81 [ V_91 ] . V_88 ,
F_11 ( V_54 -> V_34 ) ) ;
V_17 -> V_81 [ V_91 ] . V_82 = V_54 -> V_30 ;
if ( F_11 ( V_17 -> V_44 ) < F_11 ( V_17 -> V_87 ) )
F_35 ( & V_17 -> V_44 , 1 ) ;
F_70 ( & V_105 -> V_109 . V_110 . V_111 , F_11 ( V_54 -> V_34 ) -
F_11 ( V_54 -> V_33 ) ) ;
F_70 ( & V_105 -> V_109 . V_110 . V_112 , F_11 ( V_54 -> V_34 ) ) ;
F_70 ( & V_105 -> V_113 , F_11 ( V_17 -> V_18 ) ) ;
F_43 ( V_68 , V_23 ) ;
F_71 ( & F_41 ( V_69 ) -> V_114 ) ;
F_41 ( V_69 ) -> V_115 = F_16 ( V_105 -> V_113 ) ;
V_105 -> V_116 = F_33 ( F_72 ( V_69 -> V_51 ,
F_16 ( V_105 -> V_113 ) ) ) ;
F_73 ( & F_41 ( V_69 ) -> V_114 ) ;
F_74 ( V_69 , F_15 ( V_105 -> V_116 ) ) ;
V_69 -> V_117 = F_75 ( V_69 ) ;
F_76 ( V_68 , V_69 , 0 ) ;
V_74 = 0 ;
if ( V_102 )
* V_102 = V_7 -> V_106 ;
V_75:
if ( V_68 )
F_77 ( V_53 , V_68 ) ;
if ( V_7 )
F_9 ( V_7 ) ;
F_7 ( V_70 ) ;
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
static int F_78 ( struct V_52 * V_53 ,
struct V_6 * V_7 ,
int type ,
T_2 V_118 ,
T_1 * V_102 ,
int V_103 )
{
int V_74 ;
T_2 V_119 = V_7 -> V_120 ;
struct V_8 * V_69 ;
struct V_22 * V_23 = NULL ;
struct V_36 * V_105 ;
T_2 V_121 ;
V_69 = F_79 ( V_53 , type , V_118 ) ;
if ( ! V_69 ) {
F_39 ( - V_122 ) ;
return - V_122 ;
}
F_80 ( & V_69 -> V_12 ) ;
V_74 = F_81 ( V_69 , & V_23 , 1 ) ;
if ( V_74 < 0 ) {
F_5 ( & V_69 -> V_12 ) ;
F_6 ( V_69 ) ;
F_39 ( V_74 ) ;
return V_74 ;
}
V_7 -> V_9 = V_69 ;
V_7 -> V_123 = V_118 ;
V_105 = (struct V_36 * ) V_23 -> V_27 ;
F_20 ( ! F_82 ( V_105 ) ) ;
if ( ! ( V_105 -> V_124 & F_34 ( V_125 ) ) ) {
V_74 = F_37 ( V_69 -> V_51 ,
L_11 ,
( unsigned long long ) F_15 ( V_105 -> V_39 ) ) ;
goto V_75;
}
V_121 = F_16 ( V_105 -> V_109 . V_110 . V_112 ) -
F_16 ( V_105 -> V_109 . V_110 . V_111 ) ;
if ( V_119 > V_121 ) {
if ( F_62 ( V_69 ) ) {
F_83 ( V_119 ,
V_121 ) ;
V_74 = - V_92 ;
goto V_75;
}
if ( ! ( V_103 & V_126 ) ) {
F_84 (
V_118 , V_119 , V_121 ) ;
V_74 = - V_92 ;
goto V_75;
}
V_74 = F_61 ( V_53 , V_69 , V_23 ,
V_7 -> V_127 ,
V_102 , V_103 ) ;
if ( V_74 < 0 ) {
if ( V_74 != - V_92 )
F_39 ( V_74 ) ;
goto V_75;
}
F_85 ( & V_53 -> V_128 . V_129 ) ;
F_20 ( V_119 >
( F_16 ( V_105 -> V_109 . V_110 . V_112 )
- F_16 ( V_105 -> V_109 . V_110 . V_111 ) ) ) ;
}
F_86 ( V_23 ) ;
V_7 -> V_13 = V_23 ;
V_75:
F_7 ( V_23 ) ;
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
static void F_87 ( struct V_52 * V_53 )
{
F_71 ( & V_53 -> V_130 ) ;
V_53 -> V_131 = V_132 ;
F_73 ( & V_53 -> V_130 ) ;
F_88 ( & V_53 -> V_133 , 0 ) ;
}
static void F_89 ( struct V_52 * V_53 )
{
F_71 ( & V_53 -> V_130 ) ;
V_53 -> V_134 = V_132 ;
F_73 ( & V_53 -> V_130 ) ;
F_88 ( & V_53 -> V_135 , 0 ) ;
}
void F_90 ( struct V_52 * V_53 )
{
F_87 ( V_53 ) ;
F_89 ( V_53 ) ;
}
static void F_91 ( struct V_52 * V_53 , int V_118 , int type )
{
F_71 ( & V_53 -> V_130 ) ;
if ( type == V_136 )
V_53 -> V_131 = V_118 ;
else if ( type == V_137 )
V_53 -> V_134 = V_118 ;
F_73 ( & V_53 -> V_130 ) ;
}
static int F_92 ( struct V_52 * V_53 , int type )
{
int V_118 = V_132 ;
F_71 ( & V_53 -> V_130 ) ;
if ( type == V_136 )
V_118 = V_53 -> V_131 ;
else if ( type == V_137 )
V_118 = V_53 -> V_134 ;
F_73 ( & V_53 -> V_130 ) ;
return V_118 ;
}
static int F_93 ( struct V_52 * V_53 )
{
return F_92 ( V_53 , V_136 ) ;
}
static int F_94 ( struct V_52 * V_53 )
{
return F_92 ( V_53 , V_137 ) ;
}
static int F_95 ( struct V_52 * V_53 ,
struct V_6 * V_7 ,
int type )
{
int V_98 , V_74 = - V_92 ;
int V_118 = F_92 ( V_53 , type ) ;
if ( V_118 == V_132 )
V_118 = V_53 -> V_138 + 1 ;
for ( V_98 = 0 ; V_98 < V_53 -> V_139 ; V_98 ++ , V_118 ++ ) {
if ( V_118 == V_53 -> V_139 )
V_118 = 0 ;
if ( V_118 == V_53 -> V_138 )
continue;
V_74 = F_78 ( V_53 , V_7 ,
type ,
( T_2 ) V_118 , NULL ,
V_140 ) ;
if ( V_74 >= 0 ) {
F_91 ( V_53 , V_118 , type ) ;
break;
}
F_3 ( V_7 ) ;
}
return V_74 ;
}
static int F_96 ( struct V_52 * V_53 ,
struct V_6 * V_7 )
{
return F_95 ( V_53 , V_7 , V_136 ) ;
}
static int F_97 ( struct V_52 * V_53 ,
struct V_6 * V_7 )
{
return F_95 ( V_53 , V_7 , V_137 ) ;
}
int F_98 ( struct V_52 * V_53 ,
int V_141 ,
struct V_6 * * V_7 )
{
int V_74 ;
int V_118 = F_94 ( V_53 ) ;
* V_7 = F_99 ( sizeof( struct V_6 ) , V_142 ) ;
if ( ! ( * V_7 ) ) {
V_74 = - V_93 ;
F_39 ( V_74 ) ;
goto V_75;
}
( * V_7 ) -> V_120 = V_141 ;
( * V_7 ) -> V_10 = V_143 ;
( * V_7 ) -> V_144 = V_145 ;
if ( V_118 != V_132 &&
F_100 ( & V_53 -> V_135 ) < V_146 )
goto V_147;
F_88 ( & V_53 -> V_135 , 0 ) ;
V_74 = F_78 ( V_53 , ( * V_7 ) ,
V_137 ,
( T_2 ) V_53 -> V_138 , NULL ,
V_148 | V_126 ) ;
if ( V_74 >= 0 ) {
V_74 = 0 ;
if ( V_118 != V_132 )
F_89 ( V_53 ) ;
goto V_75;
} else if ( V_74 < 0 && V_74 != - V_92 ) {
F_39 ( V_74 ) ;
goto V_75;
}
F_3 ( * V_7 ) ;
V_147:
V_74 = F_97 ( V_53 , * V_7 ) ;
F_85 ( & V_53 -> V_135 ) ;
if ( V_74 < 0 ) {
if ( V_74 != - V_92 )
F_39 ( V_74 ) ;
goto V_75;
}
V_74 = 0 ;
V_75:
if ( ( V_74 < 0 ) && * V_7 ) {
F_9 ( * V_7 ) ;
* V_7 = NULL ;
}
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
int F_101 ( struct V_52 * V_53 ,
struct V_57 * V_149 ,
struct V_6 * * V_7 )
{
return F_98 ( V_53 ,
F_102 ( V_149 ) ,
V_7 ) ;
}
int F_103 ( struct V_52 * V_53 ,
struct V_6 * * V_7 )
{
int V_74 ;
int V_118 = F_93 ( V_53 ) ;
T_1 V_150 ;
* V_7 = F_99 ( sizeof( struct V_6 ) , V_142 ) ;
if ( ! ( * V_7 ) ) {
V_74 = - V_93 ;
F_39 ( V_74 ) ;
goto V_75;
}
( * V_7 ) -> V_120 = 1 ;
( * V_7 ) -> V_10 = V_151 ;
( * V_7 ) -> V_144 = V_145 ;
if ( ! ( V_53 -> V_152 & V_153 ) )
( * V_7 ) -> V_127 = ( T_2 ) ~ 0U ;
if ( V_118 != V_132 &&
F_100 ( & V_53 -> V_133 ) < V_146 )
goto V_154;
F_88 ( & V_53 -> V_133 , 0 ) ;
V_150 = V_53 -> V_155 ;
V_74 = F_78 ( V_53 , * V_7 ,
V_136 ,
( T_2 ) V_53 -> V_138 ,
& V_150 ,
V_126 |
V_148 ) ;
if ( V_74 >= 0 ) {
V_74 = 0 ;
F_71 ( & V_53 -> V_130 ) ;
V_53 -> V_155 = V_150 ;
F_73 ( & V_53 -> V_130 ) ;
F_104 (
( unsigned long long ) V_150 ) ;
if ( V_118 != V_132 )
F_87 ( V_53 ) ;
goto V_75;
} else if ( V_74 < 0 && V_74 != - V_92 ) {
F_39 ( V_74 ) ;
goto V_75;
}
F_3 ( * V_7 ) ;
V_154:
V_74 = F_96 ( V_53 , * V_7 ) ;
F_85 ( & V_53 -> V_133 ) ;
if ( V_74 < 0 ) {
if ( V_74 != - V_92 )
F_39 ( V_74 ) ;
goto V_75;
}
V_74 = 0 ;
V_75:
if ( ( V_74 < 0 ) && * V_7 ) {
F_9 ( * V_7 ) ;
* V_7 = NULL ;
}
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
int F_105 ( struct V_52 * V_53 ,
struct V_6 * V_7 )
{
int V_74 ;
V_7 -> V_10 = V_156 ;
V_7 -> V_144 = V_157 ;
V_74 = F_78 ( V_53 , V_7 ,
V_158 ,
V_132 , NULL ,
V_126 ) ;
if ( V_74 < 0 && V_74 != - V_92 ) {
F_39 ( V_74 ) ;
goto V_75;
}
V_75:
return V_74 ;
}
static int F_63 ( struct V_52 * V_53 ,
T_2 V_119 , T_1 V_101 ,
int V_103 ,
struct V_6 * * V_7 )
{
int V_74 ;
* V_7 = F_99 ( sizeof( struct V_6 ) , V_142 ) ;
if ( ! ( * V_7 ) ) {
V_74 = - V_93 ;
F_39 ( V_74 ) ;
goto V_75;
}
( * V_7 ) -> V_120 = V_119 ;
( * V_7 ) -> V_127 = V_101 ;
V_74 = - V_92 ;
if ( ! ( V_103 & V_148 ) &&
F_106 ( V_53 , V_119 ) ) {
V_74 = F_107 ( V_53 ,
V_119 ,
* V_7 ) ;
if ( ( V_74 < 0 ) && ( V_74 != - V_92 ) ) {
F_39 ( V_74 ) ;
goto V_75;
}
}
if ( V_74 == - V_92 ) {
V_74 = F_105 ( V_53 , * V_7 ) ;
if ( V_74 < 0 ) {
if ( V_74 != - V_92 )
F_39 ( V_74 ) ;
goto V_75;
}
}
V_74 = 0 ;
V_75:
if ( ( V_74 < 0 ) && * V_7 ) {
F_9 ( * V_7 ) ;
* V_7 = NULL ;
}
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
int F_108 ( struct V_52 * V_53 ,
T_2 V_119 ,
struct V_6 * * V_7 )
{
return F_63 ( V_53 , V_119 , 0 ,
V_126 , V_7 ) ;
}
static int F_109 ( struct V_22 * V_70 ,
int V_159 )
{
struct V_25 * V_54 = (struct V_25 * ) V_70 -> V_27 ;
int V_99 ;
if ( F_110 ( V_159 , ( unsigned long * ) V_54 -> V_84 ) )
return 0 ;
if ( ! F_111 ( V_70 ) )
return 1 ;
F_112 ( V_70 ) ;
V_54 = (struct V_25 * ) F_113 ( V_70 ) -> V_160 ;
if ( V_54 )
V_99 = ! F_110 ( V_159 , ( unsigned long * ) V_54 -> V_84 ) ;
else
V_99 = 1 ;
F_114 ( V_70 ) ;
return V_99 ;
}
static int F_115 ( struct V_52 * V_53 ,
struct V_22 * V_70 ,
unsigned int V_119 ,
unsigned int V_161 ,
struct V_1 * V_2 )
{
void * V_162 ;
T_4 V_163 , V_164 ;
int V_165 , V_166 , V_167 , V_74 = 0 ;
struct V_25 * V_54 = (struct V_25 * ) V_70 -> V_27 ;
F_20 ( ! F_13 ( V_54 ) ) ;
V_167 = V_166 = V_163 = V_164 = 0 ;
V_162 = V_54 -> V_84 ;
while( ( V_165 = F_116 ( V_162 , V_161 , V_166 ) ) != - 1 ) {
if ( V_165 == V_161 )
break;
if ( ! F_109 ( V_70 , V_165 ) ) {
V_167 = 0 ;
V_166 = V_165 + 1 ;
} else if ( V_165 == V_166 ) {
V_167 ++ ;
V_166 ++ ;
} else {
V_167 = 1 ;
V_166 = V_165 + 1 ;
}
if ( V_167 > V_164 ) {
V_164 = V_167 ;
V_163 = V_166 - V_167 ;
}
if ( V_167 == V_119 ) {
break;
}
}
if ( V_164 ) {
V_2 -> V_5 = V_163 ;
V_2 -> V_168 = V_164 ;
} else {
V_74 = - V_92 ;
}
return V_74 ;
}
int F_117 ( T_3 * V_68 ,
struct V_8 * V_69 ,
struct V_25 * V_54 ,
struct V_22 * V_169 ,
unsigned int V_89 ,
unsigned int V_90 )
{
int V_74 ;
void * V_162 = V_54 -> V_84 ;
int V_170 = V_107 ;
F_20 ( ! F_13 ( V_54 ) ) ;
F_20 ( F_11 ( V_54 -> V_33 ) < V_90 ) ;
F_118 ( V_89 , V_90 ) ;
if ( F_62 ( V_69 ) )
V_170 = V_171 ;
V_74 = F_38 ( V_68 ,
F_28 ( V_69 ) ,
V_169 ,
V_170 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
F_35 ( & V_54 -> V_33 , - V_90 ) ;
if ( F_11 ( V_54 -> V_33 ) > F_11 ( V_54 -> V_34 ) ) {
return F_37 ( V_69 -> V_51 , L_12 ,
( unsigned long long ) F_15 ( V_54 -> V_30 ) ,
F_11 ( V_54 -> V_34 ) ,
F_11 ( V_54 -> V_33 ) ,
V_90 ) ;
}
while( V_90 -- )
F_42 ( V_89 ++ , V_162 ) ;
F_43 ( V_68 , V_169 ) ;
V_75:
return V_74 ;
}
static inline T_4 F_119 ( struct V_16 * V_17 )
{
T_4 V_85 , V_86 ;
F_20 ( ! V_17 -> V_44 ) ;
V_86 = V_85 = 0 ;
while ( V_85 < F_11 ( V_17 -> V_44 ) ) {
if ( F_16 ( V_17 -> V_81 [ V_85 ] . V_108 ) >
F_16 ( V_17 -> V_81 [ V_86 ] . V_108 ) )
V_86 = V_85 ;
V_85 ++ ;
}
F_20 ( V_86 >= F_11 ( V_17 -> V_44 ) ) ;
return V_86 ;
}
static int F_120 ( T_3 * V_68 ,
struct V_8 * V_69 ,
struct V_22 * V_172 ,
struct V_22 * V_70 ,
struct V_22 * V_173 ,
T_4 V_174 )
{
int V_74 ;
T_1 V_175 , V_176 ;
struct V_36 * V_105 = (struct V_36 * ) V_172 -> V_27 ;
struct V_25 * V_54 = (struct V_25 * ) V_70 -> V_27 ;
struct V_25 * V_177 = (struct V_25 * ) V_173 -> V_27 ;
F_20 ( ! F_13 ( V_54 ) ) ;
F_20 ( ! F_13 ( V_177 ) ) ;
F_121 (
( unsigned long long ) F_15 ( V_105 -> V_39 ) , V_174 ,
( unsigned long long ) F_15 ( V_54 -> V_30 ) ,
( unsigned long long ) F_15 ( V_177 -> V_30 ) ) ;
V_175 = F_15 ( V_54 -> V_80 ) ;
V_176 = F_15 ( V_177 -> V_80 ) ;
V_74 = F_38 ( V_68 , F_28 ( V_69 ) ,
V_173 ,
V_107 ) ;
if ( V_74 < 0 )
goto V_50;
V_177 -> V_80 = V_54 -> V_80 ;
F_43 ( V_68 , V_173 ) ;
V_74 = F_38 ( V_68 , F_28 ( V_69 ) ,
V_70 , V_107 ) ;
if ( V_74 < 0 )
goto V_178;
V_54 -> V_80 = V_105 -> V_41 . V_42 . V_81 [ V_174 ] . V_82 ;
F_43 ( V_68 , V_70 ) ;
V_74 = F_69 ( V_68 , F_28 ( V_69 ) ,
V_172 , V_107 ) ;
if ( V_74 < 0 )
goto V_179;
V_105 -> V_41 . V_42 . V_81 [ V_174 ] . V_82 = V_54 -> V_30 ;
F_43 ( V_68 , V_172 ) ;
V_50:
if ( V_74 < 0 )
F_39 ( V_74 ) ;
return V_74 ;
V_179:
V_54 -> V_80 = F_33 ( V_175 ) ;
V_178:
V_177 -> V_80 = F_33 ( V_176 ) ;
goto V_50;
}
static inline int F_122 ( struct V_25 * V_54 ,
T_2 V_180 )
{
return F_11 ( V_54 -> V_33 ) > V_180 ;
}
static int V_157 ( struct V_8 * V_8 ,
struct V_22 * V_169 ,
T_2 V_119 , T_2 V_94 ,
T_1 V_101 ,
struct V_1 * V_2 )
{
int V_181 = - V_92 ;
int V_99 ;
T_1 V_182 ;
struct V_25 * V_26 = (struct V_25 * ) V_169 -> V_27 ;
struct V_52 * V_53 = F_17 ( V_8 -> V_51 ) ;
unsigned int V_38 , V_183 ;
F_20 ( ! F_62 ( V_8 ) ) ;
if ( V_26 -> V_33 ) {
V_38 = F_11 ( V_26 -> V_34 ) ;
V_183 = F_123 ( V_8 -> V_51 ,
F_15 ( V_26 -> V_30 ) ) ;
if ( ( V_183 + V_38 ) >
F_41 ( V_8 ) -> V_115 ) {
V_38 = F_41 ( V_8 ) -> V_115 - V_183 ;
F_124 (
( unsigned long long ) F_15 ( V_26 -> V_30 ) ,
F_11 ( V_26 -> V_34 ) ,
F_41 ( V_8 ) -> V_115 , V_38 ) ;
}
V_99 = F_115 ( F_17 ( V_8 -> V_51 ) ,
V_169 , V_119 ,
V_38 , V_2 ) ;
if ( V_99 )
return V_99 ;
if ( V_101 ) {
V_182 = F_47 ( V_8 -> V_51 ,
V_183 +
V_2 -> V_5 +
V_2 -> V_168 ) ;
F_125 (
( unsigned long long ) V_182 ,
( unsigned long long ) V_101 ) ;
if ( V_182 > V_101 )
return - V_92 ;
}
if ( V_94 <= V_2 -> V_168 )
V_181 = 0 ;
else if ( V_2 -> V_168 ) {
F_126 ( V_53 , V_2 -> V_168 ) ;
}
}
return V_181 ;
}
static int V_145 ( struct V_8 * V_8 ,
struct V_22 * V_169 ,
T_2 V_119 , T_2 V_94 ,
T_1 V_101 ,
struct V_1 * V_2 )
{
int V_99 = - V_92 ;
T_1 V_182 ;
struct V_25 * V_54 = (struct V_25 * ) V_169 -> V_27 ;
F_20 ( V_94 != 1 ) ;
F_20 ( F_62 ( V_8 ) ) ;
if ( V_54 -> V_33 ) {
V_99 = F_115 ( F_17 ( V_8 -> V_51 ) ,
V_169 , V_119 ,
F_11 ( V_54 -> V_34 ) ,
V_2 ) ;
if ( ! V_99 && V_101 ) {
V_182 = F_15 ( V_54 -> V_30 ) +
V_2 -> V_5 + V_2 -> V_168 ;
F_127 (
( unsigned long long ) V_182 ,
( unsigned long long ) V_101 ) ;
if ( V_182 > V_101 )
V_99 = - V_92 ;
}
}
return V_99 ;
}
int F_128 ( struct V_8 * V_8 ,
T_3 * V_68 ,
struct V_22 * V_184 ,
T_2 V_90 ,
T_4 V_174 )
{
int V_99 ;
T_2 V_185 ;
struct V_36 * V_37 = (struct V_36 * ) V_184 -> V_27 ;
struct V_16 * V_17 = (struct V_16 * ) & V_37 -> V_41 . V_42 ;
V_99 = F_69 ( V_68 , F_28 ( V_8 ) , V_184 ,
V_107 ) ;
if ( V_99 < 0 ) {
F_39 ( V_99 ) ;
goto V_50;
}
V_185 = F_16 ( V_37 -> V_109 . V_110 . V_111 ) ;
V_37 -> V_109 . V_110 . V_111 = F_34 ( V_90 + V_185 ) ;
F_70 ( & V_17 -> V_81 [ V_174 ] . V_108 , - V_90 ) ;
F_43 ( V_68 , V_184 ) ;
V_50:
return V_99 ;
}
void F_129 ( struct V_8 * V_8 ,
struct V_22 * V_184 ,
T_2 V_90 ,
T_4 V_174 )
{
T_2 V_185 ;
struct V_36 * V_37 = (struct V_36 * ) V_184 -> V_27 ;
struct V_16 * V_17 ;
V_17 = (struct V_16 * ) & V_37 -> V_41 . V_42 ;
V_185 = F_16 ( V_37 -> V_109 . V_110 . V_111 ) ;
V_37 -> V_109 . V_110 . V_111 = F_34 ( V_185 - V_90 ) ;
F_70 ( & V_17 -> V_81 [ V_174 ] . V_108 , V_90 ) ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_60 * V_61 ,
struct V_16 * V_17 )
{
unsigned int V_186 = F_11 ( V_17 -> V_19 ) ;
unsigned int V_187 = F_16 ( V_61 -> V_66 ) * V_186 ;
unsigned int V_188 = F_11 ( V_61 -> V_67 ) * V_186 ;
if ( V_2 -> V_5 < V_187 )
return 0 ;
if ( V_2 -> V_5 >= ( V_187 + V_188 ) )
return 0 ;
V_2 -> V_3 = F_15 ( V_61 -> V_65 ) +
( V_2 -> V_5 - V_187 ) ;
if ( ( V_2 -> V_5 + V_2 -> V_168 ) > ( V_187 + V_188 ) )
V_2 -> V_168 = ( V_187 + V_188 ) - V_2 -> V_5 ;
return 1 ;
}
static void F_131 ( struct V_6 * V_7 ,
struct V_25 * V_54 ,
struct V_1 * V_2 )
{
int V_98 ;
T_1 V_30 = V_2 -> V_4 ;
struct V_60 * V_61 ;
struct V_36 * V_37 = (struct V_36 * ) V_7 -> V_13 -> V_27 ;
struct V_16 * V_17 = & V_37 -> V_41 . V_42 ;
if ( F_62 ( V_7 -> V_9 ) ) {
V_2 -> V_3 = 0 ;
return;
}
V_2 -> V_3 = V_2 -> V_4 + V_2 -> V_5 ;
V_2 -> V_4 = 0 ;
if ( ! F_30 ( F_17 ( V_7 -> V_9 -> V_51 ) ) ||
! V_54 -> V_59 . V_62 )
return;
for ( V_98 = 0 ; V_98 < F_11 ( V_54 -> V_59 . V_62 ) ; V_98 ++ ) {
V_61 = & V_54 -> V_59 . V_64 [ V_98 ] ;
if ( F_130 ( V_2 , V_61 , V_17 ) ) {
V_2 -> V_4 = V_30 ;
break;
}
}
}
static int F_132 ( struct V_6 * V_7 ,
T_3 * V_68 ,
T_2 V_119 ,
T_2 V_94 ,
struct V_1 * V_2 ,
T_4 * V_189 )
{
int V_99 ;
struct V_22 * V_169 = NULL ;
struct V_25 * V_26 ;
struct V_36 * V_37 = (struct V_36 * ) V_7 -> V_13 -> V_27 ;
struct V_8 * V_69 = V_7 -> V_9 ;
V_99 = F_26 ( V_69 , V_37 ,
V_2 -> V_4 , & V_169 ) ;
if ( V_99 < 0 ) {
F_39 ( V_99 ) ;
return V_99 ;
}
V_26 = (struct V_25 * ) V_169 -> V_27 ;
V_99 = V_7 -> V_144 ( V_69 , V_169 , V_119 , V_94 ,
V_7 -> V_127 , V_2 ) ;
if ( V_99 < 0 ) {
if ( V_99 != - V_92 )
F_39 ( V_99 ) ;
goto V_50;
}
if ( ! V_99 )
F_131 ( V_7 , V_26 , V_2 ) ;
V_2 -> V_190 = V_169 -> V_28 ;
if ( V_7 -> V_191 )
goto V_192;
V_99 = F_128 ( V_69 , V_68 , V_7 -> V_13 ,
V_2 -> V_168 ,
F_11 ( V_26 -> V_43 ) ) ;
if ( V_99 < 0 ) {
F_39 ( V_99 ) ;
goto V_50;
}
V_99 = F_117 ( V_68 , V_69 , V_26 , V_169 ,
V_2 -> V_5 , V_2 -> V_168 ) ;
if ( V_99 < 0 ) {
F_129 ( V_69 , V_7 -> V_13 ,
V_2 -> V_168 ,
F_11 ( V_26 -> V_43 ) ) ;
F_39 ( V_99 ) ;
}
V_192:
* V_189 = F_11 ( V_26 -> V_33 ) ;
V_50:
F_7 ( V_169 ) ;
return V_99 ;
}
static int F_133 ( struct V_6 * V_7 ,
T_3 * V_68 ,
T_2 V_119 ,
T_2 V_94 ,
struct V_1 * V_2 ,
T_4 * V_189 )
{
int V_74 ;
T_4 V_174 ;
T_1 V_193 ;
struct V_8 * V_69 = V_7 -> V_9 ;
struct V_22 * V_169 = NULL ;
struct V_22 * V_194 = NULL ;
struct V_36 * V_105 = (struct V_36 * ) V_7 -> V_13 -> V_27 ;
struct V_16 * V_17 = (struct V_16 * ) & V_105 -> V_41 . V_42 ;
struct V_25 * V_54 ;
V_174 = V_7 -> V_195 ;
F_134 (
( unsigned long long ) F_41 ( V_69 ) -> V_83 ,
V_119 , V_174 ) ;
V_74 = F_26 ( V_69 , V_105 ,
F_15 ( V_17 -> V_81 [ V_174 ] . V_82 ) ,
& V_169 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
V_54 = (struct V_25 * ) V_169 -> V_27 ;
V_74 = - V_92 ;
while ( ( V_74 = V_7 -> V_144 ( V_69 , V_169 ,
V_119 , V_94 ,
V_7 -> V_127 ,
V_2 ) ) == - V_92 ) {
if ( ! V_54 -> V_80 )
break;
F_7 ( V_194 ) ;
V_194 = NULL ;
V_193 = F_15 ( V_54 -> V_80 ) ;
V_194 = V_169 ;
V_169 = NULL ;
V_74 = F_26 ( V_69 , V_105 ,
V_193 , & V_169 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
V_54 = (struct V_25 * ) V_169 -> V_27 ;
}
if ( V_74 < 0 ) {
if ( V_74 != - V_92 )
F_39 ( V_74 ) ;
goto V_75;
}
F_135 (
( unsigned long long ) F_15 ( V_54 -> V_30 ) , V_2 -> V_168 ) ;
V_2 -> V_4 = F_15 ( V_54 -> V_30 ) ;
F_20 ( V_2 -> V_168 == 0 ) ;
if ( ! V_74 )
F_131 ( V_7 , V_54 , V_2 ) ;
V_2 -> V_190 = V_169 -> V_28 ;
if ( ! V_7 -> V_100 &&
( V_194 ) &&
( F_122 ( V_54 , V_2 -> V_168 ) ) ) {
V_74 = F_120 ( V_68 , V_69 ,
V_7 -> V_13 , V_169 ,
V_194 , V_174 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
}
if ( V_7 -> V_191 )
goto V_192;
V_74 = F_128 ( V_69 , V_68 ,
V_7 -> V_13 , V_2 -> V_168 ,
V_174 ) ;
if ( V_74 ) {
F_39 ( V_74 ) ;
goto V_75;
}
V_74 = F_117 ( V_68 ,
V_69 ,
V_54 ,
V_169 ,
V_2 -> V_5 ,
V_2 -> V_168 ) ;
if ( V_74 < 0 ) {
F_129 ( V_69 ,
V_7 -> V_13 , V_2 -> V_168 , V_174 ) ;
F_39 ( V_74 ) ;
goto V_75;
}
F_136 (
( unsigned long long ) F_15 ( V_105 -> V_39 ) ,
V_2 -> V_168 ) ;
V_192:
* V_189 = F_11 ( V_54 -> V_33 ) ;
V_75:
F_7 ( V_169 ) ;
F_7 ( V_194 ) ;
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
static int F_137 ( struct V_6 * V_7 ,
T_3 * V_68 ,
T_2 V_119 ,
T_2 V_94 ,
struct V_1 * V_2 )
{
int V_74 ;
T_4 V_196 , V_98 ;
T_4 V_189 = 0 ;
T_1 V_197 = V_7 -> V_106 ;
struct V_16 * V_17 ;
struct V_36 * V_105 ;
F_20 ( V_7 -> V_198 >= V_7 -> V_120 ) ;
F_20 ( V_119 > ( V_7 -> V_120 - V_7 -> V_198 ) ) ;
F_20 ( ! V_7 -> V_13 ) ;
V_105 = (struct V_36 * ) V_7 -> V_13 -> V_27 ;
F_20 ( ! F_82 ( V_105 ) ) ;
if ( F_16 ( V_105 -> V_109 . V_110 . V_111 ) >=
F_16 ( V_105 -> V_109 . V_110 . V_112 ) ) {
V_74 = F_37 ( V_7 -> V_9 -> V_51 ,
L_13 ,
( unsigned long long ) F_15 ( V_105 -> V_39 ) ,
F_16 ( V_105 -> V_109 . V_110 . V_111 ) ,
F_16 ( V_105 -> V_109 . V_110 . V_112 ) ) ;
goto V_75;
}
V_2 -> V_4 = V_197 ;
if ( V_2 -> V_4 ) {
V_74 = F_132 ( V_7 , V_68 , V_119 ,
V_94 , V_2 , & V_189 ) ;
if ( ! V_74 )
goto V_199;
if ( V_74 < 0 && V_74 != - V_92 ) {
F_39 ( V_74 ) ;
goto V_75;
}
}
V_17 = (struct V_16 * ) & V_105 -> V_41 . V_42 ;
V_196 = F_119 ( V_17 ) ;
V_7 -> V_195 = V_196 ;
V_74 = F_133 ( V_7 , V_68 , V_119 , V_94 ,
V_2 , & V_189 ) ;
if ( ! V_74 ) {
V_197 = F_1 ( V_2 ) ;
goto V_199;
}
if ( V_74 < 0 && V_74 != - V_92 ) {
F_39 ( V_74 ) ;
goto V_75;
}
F_138 ( V_196 ) ;
V_7 -> V_100 = 1 ;
for ( V_98 = 0 ; V_98 < F_11 ( V_17 -> V_44 ) ; V_98 ++ ) {
if ( V_98 == V_196 )
continue;
if ( ! V_17 -> V_81 [ V_98 ] . V_108 )
continue;
V_7 -> V_195 = V_98 ;
V_74 = F_133 ( V_7 , V_68 , V_119 , V_94 ,
V_2 , & V_189 ) ;
if ( ! V_74 ) {
V_197 = F_1 ( V_2 ) ;
break;
}
if ( V_74 < 0 && V_74 != - V_92 ) {
F_39 ( V_74 ) ;
goto V_75;
}
}
V_199:
if ( V_74 != - V_92 ) {
if ( V_189 < V_94 )
V_7 -> V_106 = 0 ;
else
V_7 -> V_106 = V_197 ;
}
V_75:
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
int F_139 ( T_3 * V_68 ,
struct V_6 * V_7 ,
T_2 V_119 ,
T_1 * V_200 ,
T_4 * V_201 ,
unsigned int * V_90 ,
T_1 * V_202 )
{
int V_74 ;
struct V_1 V_2 = { . V_3 = 0 , } ;
F_20 ( ! V_7 ) ;
F_20 ( V_7 -> V_120 < ( V_7 -> V_198 + V_119 ) ) ;
F_20 ( V_7 -> V_10 != V_143 ) ;
V_74 = F_137 ( V_7 ,
V_68 ,
V_119 ,
1 ,
& V_2 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
F_85 ( & F_17 ( V_7 -> V_9 -> V_51 ) -> V_128 . V_203 ) ;
* V_200 = V_2 . V_4 ;
* V_201 = V_2 . V_5 ;
* V_202 = V_2 . V_3 ;
V_7 -> V_198 += V_2 . V_168 ;
* V_90 = V_2 . V_168 ;
V_74 = 0 ;
V_75:
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
static void F_140 ( struct V_8 * V_204 ,
struct V_22 * V_205 ,
struct V_6 * V_7 )
{
struct V_36 * V_37 = (struct V_36 * ) V_205 -> V_27 ;
if ( F_41 ( V_204 ) -> V_206 &&
F_41 ( V_204 ) -> V_207 == V_7 -> V_123 )
V_7 -> V_106 = F_41 ( V_204 ) -> V_206 ;
else if ( F_11 ( V_37 -> V_208 ) == V_7 -> V_123 ) {
if ( V_37 -> V_209 )
V_7 -> V_106 = F_15 ( V_37 -> V_209 ) ;
else
V_7 -> V_106 = F_2 (
F_15 ( V_37 -> V_39 ) ,
F_11 ( V_37 -> V_210 ) ) ;
}
}
static inline void F_141 ( struct V_8 * V_204 ,
struct V_6 * V_7 )
{
F_41 ( V_204 ) -> V_206 = V_7 -> V_106 ;
F_41 ( V_204 ) -> V_207 = V_7 -> V_123 ;
}
int F_142 ( struct V_8 * V_204 ,
struct V_22 * V_211 ,
struct V_6 * V_7 ,
T_1 * V_212 )
{
int V_99 ;
T_3 * V_68 = NULL ;
struct V_1 * V_2 ;
F_20 ( ! V_7 ) ;
F_20 ( V_7 -> V_198 != 0 ) ;
F_20 ( V_7 -> V_120 != 1 ) ;
F_20 ( V_7 -> V_10 != V_151 ) ;
V_2 = F_99 ( sizeof( * V_2 ) , V_213 ) ;
if ( V_2 == NULL ) {
V_99 = - V_93 ;
F_39 ( V_99 ) ;
goto V_50;
}
F_140 ( V_204 , V_211 , V_7 ) ;
V_68 = F_65 ( F_17 ( V_204 -> V_51 ) , V_214 ) ;
if ( F_66 ( V_68 ) ) {
V_99 = F_67 ( V_68 ) ;
V_68 = NULL ;
F_39 ( V_99 ) ;
goto V_50;
}
V_7 -> V_191 = 1 ;
V_99 = F_137 ( V_7 , V_68 , 1 , 1 , V_2 ) ;
if ( V_99 < 0 ) {
F_39 ( V_99 ) ;
goto V_50;
}
V_7 -> V_15 = V_2 ;
* V_212 = V_2 -> V_3 ;
F_76 ( V_68 , V_204 , 0 ) ;
V_50:
if ( V_68 )
F_77 ( F_17 ( V_204 -> V_51 ) , V_68 ) ;
if ( V_99 )
F_8 ( V_2 ) ;
return V_99 ;
}
int F_143 ( T_3 * V_68 ,
struct V_8 * V_204 ,
struct V_6 * V_7 ,
T_1 * V_200 ,
T_4 * V_215 ,
T_1 V_216 )
{
int V_99 ;
T_4 V_174 ;
struct V_1 * V_2 = V_7 -> V_15 ;
struct V_22 * V_70 = NULL ;
struct V_25 * V_54 ;
struct V_36 * V_37 = (struct V_36 * ) V_7 -> V_13 -> V_27 ;
F_20 ( V_2 -> V_3 != V_216 ) ;
V_99 = F_26 ( V_7 -> V_9 , V_37 ,
V_2 -> V_190 , & V_70 ) ;
if ( V_99 ) {
F_39 ( V_99 ) ;
goto V_50;
}
V_54 = (struct V_25 * ) V_70 -> V_27 ;
V_174 = F_11 ( V_54 -> V_43 ) ;
V_99 = F_128 ( V_7 -> V_9 , V_68 ,
V_7 -> V_13 , V_2 -> V_168 ,
V_174 ) ;
if ( V_99 ) {
F_39 ( V_99 ) ;
goto V_50;
}
V_99 = F_117 ( V_68 ,
V_7 -> V_9 ,
V_54 ,
V_70 ,
V_2 -> V_5 ,
V_2 -> V_168 ) ;
if ( V_99 < 0 ) {
F_129 ( V_7 -> V_9 ,
V_7 -> V_13 , V_2 -> V_168 , V_174 ) ;
F_39 ( V_99 ) ;
goto V_50;
}
F_144 ( ( unsigned long long ) V_216 ,
V_2 -> V_168 ) ;
F_85 ( & F_17 ( V_7 -> V_9 -> V_51 ) -> V_128 . V_203 ) ;
F_20 ( V_2 -> V_168 != 1 ) ;
* V_200 = V_2 -> V_4 ;
* V_215 = V_2 -> V_5 ;
V_7 -> V_198 ++ ;
F_141 ( V_204 , V_7 ) ;
V_50:
F_7 ( V_70 ) ;
return V_99 ;
}
int F_145 ( T_3 * V_68 ,
struct V_8 * V_204 ,
struct V_22 * V_211 ,
struct V_6 * V_7 ,
T_1 * V_200 ,
T_4 * V_215 ,
T_1 * V_212 )
{
int V_74 ;
struct V_1 V_2 ;
F_20 ( ! V_7 ) ;
F_20 ( V_7 -> V_198 != 0 ) ;
F_20 ( V_7 -> V_120 != 1 ) ;
F_20 ( V_7 -> V_10 != V_151 ) ;
F_140 ( V_204 , V_211 , V_7 ) ;
V_74 = F_137 ( V_7 ,
V_68 ,
1 ,
1 ,
& V_2 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
F_85 ( & F_17 ( V_7 -> V_9 -> V_51 ) -> V_128 . V_203 ) ;
F_20 ( V_2 . V_168 != 1 ) ;
* V_200 = V_2 . V_4 ;
* V_215 = V_2 . V_5 ;
* V_212 = V_2 . V_3 ;
V_7 -> V_198 ++ ;
F_141 ( V_204 , V_7 ) ;
V_74 = 0 ;
V_75:
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
static inline T_2 F_146 ( struct V_8 * V_8 ,
T_1 V_30 ,
T_4 V_217 )
{
struct V_52 * V_53 = F_17 ( V_8 -> V_51 ) ;
T_2 V_218 = 0 ;
F_20 ( ! F_62 ( V_8 ) ) ;
if ( V_30 != V_53 -> V_219 )
V_218 = F_123 ( V_8 -> V_51 , V_30 ) ;
V_218 += ( T_2 ) V_217 ;
return V_218 ;
}
T_1 F_147 ( struct V_8 * V_8 , T_2 V_218 )
{
struct V_52 * V_53 = F_17 ( V_8 -> V_51 ) ;
T_2 V_220 ;
F_20 ( ! F_62 ( V_8 ) ) ;
V_220 = V_218 / V_53 -> V_221 ;
if ( ! V_220 )
return V_53 -> V_219 ;
return F_47 ( V_8 -> V_51 ,
V_220 * V_53 -> V_221 ) ;
}
static inline void F_148 ( struct V_8 * V_8 ,
T_1 V_222 ,
T_1 * V_30 ,
T_4 * V_217 )
{
struct V_52 * V_53 = F_17 ( V_8 -> V_51 ) ;
T_2 V_223 = F_123 ( V_53 -> V_21 , V_222 ) ;
F_20 ( ! F_62 ( V_8 ) ) ;
* V_30 = F_147 ( V_8 ,
V_223 ) ;
if ( * V_30 == V_53 -> V_219 )
* V_217 = ( T_4 ) V_223 ;
else
* V_217 = ( T_4 ) F_123 ( V_53 -> V_21 ,
V_222 - * V_30 ) ;
}
int F_149 ( T_3 * V_68 ,
struct V_6 * V_7 ,
T_2 V_224 ,
T_2 V_225 ,
T_2 * V_226 ,
T_2 * V_227 )
{
int V_74 ;
unsigned int V_119 = V_225 ;
struct V_1 V_2 = { . V_3 = 0 , } ;
struct V_52 * V_53 = F_17 ( V_7 -> V_9 -> V_51 ) ;
F_20 ( V_7 -> V_198 >= V_7 -> V_120 ) ;
F_20 ( V_7 -> V_10 != V_11
&& V_7 -> V_10 != V_156 ) ;
if ( V_7 -> V_10 == V_11 ) {
F_150 ( V_224 > 1 ) ;
V_74 = F_151 ( V_53 ,
V_68 ,
V_7 ,
V_119 ,
V_226 ,
V_227 ) ;
if ( ! V_74 )
F_85 ( & V_53 -> V_128 . V_228 ) ;
} else {
if ( V_224 > ( V_53 -> V_221 - 1 ) ) {
F_23 ( V_47 , L_14
L_15 , V_224 ,
V_53 -> V_221 ) ;
V_74 = - V_92 ;
goto V_75;
}
if ( V_119 > ( V_53 -> V_221 - 1 ) )
V_119 = V_53 -> V_221 - 1 ;
V_74 = F_137 ( V_7 ,
V_68 ,
V_119 ,
V_224 ,
& V_2 ) ;
if ( ! V_74 ) {
F_20 ( V_2 . V_3 ) ;
* V_226 =
F_146 ( V_7 -> V_9 ,
V_2 . V_4 ,
V_2 . V_5 ) ;
F_85 ( & V_53 -> V_128 . V_229 ) ;
* V_227 = V_2 . V_168 ;
}
}
if ( V_74 < 0 ) {
if ( V_74 != - V_92 )
F_39 ( V_74 ) ;
goto V_75;
}
V_7 -> V_198 += * V_227 ;
V_75:
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
int F_46 ( T_3 * V_68 ,
struct V_6 * V_7 ,
T_2 V_224 ,
T_2 * V_226 ,
T_2 * V_227 )
{
unsigned int V_119 = V_7 -> V_120 - V_7 -> V_198 ;
return F_149 ( V_68 , V_7 , V_224 ,
V_119 , V_226 , V_227 ) ;
}
static int F_152 ( T_3 * V_68 ,
struct V_8 * V_69 ,
struct V_25 * V_54 ,
struct V_22 * V_169 ,
unsigned int V_89 ,
unsigned int V_90 ,
void (* F_153)( unsigned int V_230 ,
unsigned long * V_231 ) )
{
int V_74 ;
unsigned int V_49 ;
struct V_25 * V_232 = NULL ;
F_20 ( ! F_13 ( V_54 ) ) ;
F_154 ( V_89 , V_90 ) ;
F_20 ( F_153 && ! F_62 ( V_69 ) ) ;
V_74 = F_38 ( V_68 , F_28 ( V_69 ) ,
V_169 ,
F_153 ?
V_171 :
V_107 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
if ( F_153 ) {
F_112 ( V_169 ) ;
V_232 = (struct V_25 * )
F_113 ( V_169 ) -> V_160 ;
F_20 ( ! V_232 ) ;
}
V_49 = V_90 ;
while( V_49 -- ) {
F_155 ( ( V_89 + V_49 ) ,
( unsigned long * ) V_54 -> V_84 ) ;
if ( F_153 )
F_153 ( V_89 + V_49 ,
( unsigned long * ) V_232 -> V_84 ) ;
}
F_35 ( & V_54 -> V_33 , V_90 ) ;
if ( F_11 ( V_54 -> V_33 ) > F_11 ( V_54 -> V_34 ) ) {
return F_37 ( V_69 -> V_51 , L_12 ,
( unsigned long long ) F_15 ( V_54 -> V_30 ) ,
F_11 ( V_54 -> V_34 ) ,
F_11 ( V_54 -> V_33 ) ,
V_90 ) ;
}
if ( F_153 )
F_114 ( V_169 ) ;
F_43 ( V_68 , V_169 ) ;
V_75:
return V_74 ;
}
static int F_156 ( T_3 * V_68 ,
struct V_8 * V_69 ,
struct V_22 * V_233 ,
unsigned int V_234 ,
T_1 V_30 ,
unsigned int V_235 ,
void (* F_153)( unsigned int V_230 ,
unsigned long * V_162 ) )
{
int V_74 = 0 ;
T_2 V_185 ;
struct V_36 * V_105 = (struct V_36 * ) V_233 -> V_27 ;
struct V_16 * V_17 = & V_105 -> V_41 . V_42 ;
struct V_22 * V_169 = NULL ;
struct V_25 * V_236 ;
F_20 ( ! F_82 ( V_105 ) ) ;
F_20 ( ( V_235 + V_234 ) > F_10 ( V_17 ) ) ;
F_157 (
( unsigned long long ) F_41 ( V_69 ) -> V_83 ,
( unsigned long long ) V_30 ,
V_234 , V_235 ) ;
V_74 = F_26 ( V_69 , V_105 , V_30 ,
& V_169 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
V_236 = (struct V_25 * ) V_169 -> V_27 ;
F_20 ( ( V_235 + V_234 ) > F_11 ( V_236 -> V_34 ) ) ;
V_74 = F_152 ( V_68 , V_69 ,
V_236 , V_169 ,
V_234 , V_235 , F_153 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_75;
}
V_74 = F_69 ( V_68 , F_28 ( V_69 ) ,
V_233 , V_107 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
F_117 ( V_68 , V_69 , V_236 , V_169 ,
V_234 , V_235 ) ;
goto V_75;
}
F_70 ( & V_17 -> V_81 [ F_11 ( V_236 -> V_43 ) ] . V_108 ,
V_235 ) ;
V_185 = F_16 ( V_105 -> V_109 . V_110 . V_111 ) ;
V_105 -> V_109 . V_110 . V_111 = F_34 ( V_185 - V_235 ) ;
F_43 ( V_68 , V_233 ) ;
V_75:
F_7 ( V_169 ) ;
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
int F_158 ( T_3 * V_68 ,
struct V_8 * V_69 ,
struct V_22 * V_233 ,
unsigned int V_234 ,
T_1 V_30 ,
unsigned int V_235 )
{
return F_156 ( V_68 , V_69 , V_233 ,
V_234 , V_30 , V_235 , NULL ) ;
}
int F_159 ( T_3 * V_68 ,
struct V_8 * V_237 ,
struct V_22 * V_238 ,
struct V_36 * V_37 )
{
T_1 V_239 = F_15 ( V_37 -> V_39 ) ;
T_4 V_230 = F_11 ( V_37 -> V_210 ) ;
T_1 V_30 = F_2 ( V_239 , V_230 ) ;
if ( V_37 -> V_209 )
V_30 = F_15 ( V_37 -> V_209 ) ;
return F_158 ( V_68 , V_237 ,
V_238 , V_230 , V_30 , 1 ) ;
}
static int F_160 ( T_3 * V_68 ,
struct V_8 * V_240 ,
struct V_22 * V_241 ,
T_1 V_242 ,
unsigned int V_227 ,
void (* F_153)( unsigned int V_230 ,
unsigned long * V_162 ) )
{
int V_74 ;
T_4 V_243 ;
T_1 V_30 ;
struct V_36 * V_105 ;
F_20 ( V_242 != F_47 ( V_240 -> V_51 , F_123 ( V_240 -> V_51 , V_242 ) ) ) ;
V_105 = (struct V_36 * ) V_241 -> V_27 ;
F_148 ( V_240 , V_242 , & V_30 ,
& V_243 ) ;
F_161 ( ( unsigned long long ) V_30 ,
( unsigned long long ) V_242 ,
V_243 , V_227 ) ;
V_74 = F_156 ( V_68 , V_240 , V_241 ,
V_243 , V_30 ,
V_227 , F_153 ) ;
if ( V_74 < 0 ) {
F_39 ( V_74 ) ;
goto V_50;
}
F_126 ( F_17 ( V_240 -> V_51 ) ,
V_227 ) ;
V_50:
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
int F_55 ( T_3 * V_68 ,
struct V_8 * V_240 ,
struct V_22 * V_241 ,
T_1 V_242 ,
unsigned int V_227 )
{
return F_160 ( V_68 , V_240 , V_241 ,
V_242 , V_227 ,
V_244 ) ;
}
int F_162 ( T_3 * V_68 ,
struct V_8 * V_240 ,
struct V_22 * V_241 ,
T_1 V_242 ,
unsigned int V_227 )
{
return F_160 ( V_68 , V_240 , V_241 ,
V_242 , V_227 ,
V_245 ) ;
}
static inline void F_163 ( struct V_25 * V_54 )
{
F_164 ( L_16 ) ;
F_164 ( L_17 , V_54 -> V_29 ) ;
F_164 ( L_18 , V_54 -> V_35 ) ;
F_164 ( L_19 , V_54 -> V_34 ) ;
F_164 ( L_20 , V_54 -> V_33 ) ;
F_164 ( L_21 , V_54 -> V_43 ) ;
F_164 ( L_22 , F_16 ( V_54 -> V_31 ) ) ;
F_164 ( L_23 ,
( unsigned long long ) V_54 -> V_80 ) ;
F_164 ( L_24 ,
( unsigned long long ) V_54 -> V_40 ) ;
F_164 ( L_25 ,
( unsigned long long ) V_54 -> V_30 ) ;
}
static inline void F_165 ( struct V_36 * V_105 )
{
int V_98 ;
F_164 ( L_26 , ( unsigned long long ) V_105 -> V_39 ) ;
F_164 ( L_27 , V_105 -> V_246 ) ;
F_164 ( L_28 ,
( unsigned long long ) V_105 -> V_116 ) ;
F_164 ( L_29 , V_105 -> V_113 ) ;
F_164 ( L_30 ,
F_16 ( V_105 -> V_247 ) ) ;
F_164 ( L_31 ,
F_16 ( V_105 -> V_109 . V_110 . V_111 ) ) ;
F_164 ( L_32 ,
F_16 ( V_105 -> V_109 . V_110 . V_112 ) ) ;
F_164 ( L_33 , V_105 -> V_41 . V_42 . V_18 ) ;
F_164 ( L_34 , V_105 -> V_41 . V_42 . V_19 ) ;
F_164 ( L_35 , V_105 -> V_41 . V_42 . V_87 ) ;
F_164 ( L_36 ,
V_105 -> V_41 . V_42 . V_44 ) ;
for( V_98 = 0 ; V_98 < V_105 -> V_41 . V_42 . V_44 ; V_98 ++ ) {
F_164 ( L_37 , V_98 ,
V_105 -> V_41 . V_42 . V_81 [ V_98 ] . V_108 ) ;
F_164 ( L_38 , V_98 ,
V_105 -> V_41 . V_42 . V_81 [ V_98 ] . V_88 ) ;
F_164 ( L_39 , V_98 ,
( unsigned long long ) V_105 -> V_41 . V_42 . V_81 [ V_98 ] . V_82 ) ;
}
}
int F_166 ( struct V_8 * V_8 ,
struct V_248 * V_249 ,
T_2 V_250 , T_2 V_251 ,
struct V_6 * * V_252 ,
struct V_6 * * V_253 )
{
int V_99 = 0 , V_254 ;
unsigned int V_255 = V_250 + 2 * V_251 ;
struct V_52 * V_53 = F_17 ( V_8 -> V_51 ) ;
* V_253 = NULL ;
if ( V_252 )
* V_252 = NULL ;
F_20 ( V_250 != 0 && V_252 == NULL ) ;
V_254 = F_167 ( V_53 , V_249 ) ;
if ( V_254 < 0 ) {
V_99 = V_254 ;
F_39 ( V_99 ) ;
goto V_50;
}
if ( ! V_254 ||
( F_168 ( V_53 ) && V_254 < V_255 ) ) {
V_99 = F_101 ( V_53 , V_249 -> V_256 , V_253 ) ;
if ( V_99 < 0 ) {
if ( V_99 != - V_92 )
F_39 ( V_99 ) ;
goto V_50;
}
}
if ( V_250 == 0 )
goto V_50;
V_99 = F_108 ( V_53 , V_250 , V_252 ) ;
if ( V_99 < 0 ) {
if ( V_99 != - V_92 )
F_39 ( V_99 ) ;
goto V_50;
}
V_50:
if ( V_99 ) {
if ( * V_253 ) {
F_9 ( * V_253 ) ;
* V_253 = NULL ;
}
}
return V_99 ;
}
static int F_169 ( struct V_52 * V_53 , T_1 V_257 ,
T_4 * V_258 , T_1 * V_71 ,
T_4 * V_215 )
{
int V_74 ;
struct V_22 * V_259 = NULL ;
struct V_36 * V_260 ;
F_170 ( ( unsigned long long ) V_257 ) ;
V_74 = F_171 ( V_53 , V_257 , 1 , & V_259 ) ;
if ( V_74 < 0 ) {
F_23 ( V_47 , L_40 ,
( unsigned long long ) V_257 , V_74 ) ;
goto V_75;
}
V_260 = (struct V_36 * ) V_259 -> V_27 ;
if ( ! F_82 ( V_260 ) ) {
F_23 ( V_47 , L_41 ,
( unsigned long long ) V_257 ) ;
V_74 = - V_122 ;
goto V_75;
}
if ( F_11 ( V_260 -> V_208 ) != ( T_4 ) V_132 &&
( T_2 ) F_11 ( V_260 -> V_208 ) > V_53 -> V_139 - 1 ) {
F_23 ( V_47 , L_42 ,
( unsigned long long ) V_257 ,
( T_2 ) F_11 ( V_260 -> V_208 ) ) ;
V_74 = - V_122 ;
goto V_75;
}
if ( V_258 )
* V_258 = F_11 ( V_260 -> V_208 ) ;
if ( V_215 )
* V_215 = F_11 ( V_260 -> V_210 ) ;
if ( V_71 )
* V_71 = F_15 ( V_260 -> V_209 ) ;
V_75:
F_7 ( V_259 ) ;
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
static int F_172 ( struct V_52 * V_53 ,
struct V_8 * V_261 ,
struct V_22 * V_233 ,
T_1 V_71 , T_1 V_257 ,
T_4 V_230 , int * V_2 )
{
struct V_36 * V_262 ;
struct V_25 * V_236 ;
struct V_22 * V_169 = NULL ;
T_1 V_30 ;
int V_74 ;
F_173 ( ( unsigned long long ) V_257 ,
( unsigned int ) V_230 ) ;
V_262 = (struct V_36 * ) V_233 -> V_27 ;
if ( ( V_230 + 1 ) > F_10 ( & V_262 -> V_41 . V_42 ) ) {
F_23 ( V_47 , L_43 ,
( unsigned int ) V_230 ,
F_10 ( & V_262 -> V_41 . V_42 ) ) ;
V_74 = - V_122 ;
goto V_75;
}
V_30 = V_71 ? V_71 :
F_2 ( V_257 , V_230 ) ;
V_74 = F_26 ( V_261 , V_262 , V_30 ,
& V_169 ) ;
if ( V_74 < 0 ) {
F_23 ( V_47 , L_44 ,
( unsigned long long ) V_30 , V_74 ) ;
goto V_75;
}
V_236 = (struct V_25 * ) V_169 -> V_27 ;
* V_2 = F_110 ( V_230 , ( unsigned long * ) V_236 -> V_84 ) ;
V_75:
F_7 ( V_169 ) ;
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
int F_174 ( struct V_52 * V_53 , T_1 V_257 , int * V_2 )
{
int V_74 ;
T_1 V_71 = 0 ;
T_4 V_215 = 0 , V_258 = 0 ;
struct V_8 * V_237 ;
struct V_22 * V_233 = NULL ;
F_175 ( ( unsigned long long ) V_257 ) ;
V_74 = F_169 ( V_53 , V_257 , & V_258 ,
& V_71 , & V_215 ) ;
if ( V_74 < 0 ) {
F_23 ( V_47 , L_45 , V_74 ) ;
goto V_75;
}
V_237 =
F_79 ( V_53 , V_136 ,
V_258 ) ;
if ( ! V_237 ) {
V_74 = - V_122 ;
F_23 ( V_47 , L_46 ,
( T_2 ) V_258 ) ;
goto V_75;
}
F_80 ( & V_237 -> V_12 ) ;
V_74 = F_81 ( V_237 , & V_233 , 0 ) ;
if ( V_74 < 0 ) {
F_5 ( & V_237 -> V_12 ) ;
F_6 ( V_237 ) ;
F_23 ( V_47 , L_47 ,
( T_2 ) V_258 , V_74 ) ;
goto V_75;
}
V_74 = F_172 ( V_53 , V_237 , V_233 ,
V_71 , V_257 , V_215 , V_2 ) ;
if ( V_74 < 0 )
F_23 ( V_47 , L_48 , V_74 ) ;
F_4 ( V_237 , 0 ) ;
F_5 ( & V_237 -> V_12 ) ;
F_6 ( V_237 ) ;
F_7 ( V_233 ) ;
V_75:
if ( V_74 )
F_39 ( V_74 ) ;
return V_74 ;
}
