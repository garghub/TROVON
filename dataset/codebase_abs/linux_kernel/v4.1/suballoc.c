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
if ( V_7 -> V_15 ) {
F_8 ( V_7 -> V_15 ) ;
V_7 -> V_15 = NULL ;
}
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
return - V_30 ;
}
if ( F_15 ( V_26 -> V_31 ) != V_23 -> V_28 ) {
F_14 ( L_2
L_3 ,
( unsigned long long ) V_23 -> V_28 ,
( unsigned long long ) F_15 ( V_26 -> V_31 ) ) ;
return - V_30 ;
}
if ( F_16 ( V_26 -> V_32 ) != F_17 ( V_21 ) -> V_33 ) {
F_14 ( L_4
L_5 ,
( unsigned long long ) V_23 -> V_28 ,
F_16 ( V_26 -> V_32 ) ) ;
return - V_30 ;
}
if ( F_11 ( V_26 -> V_34 ) > F_11 ( V_26 -> V_35 ) ) {
F_14 ( L_6
L_7 ,
( unsigned long long ) V_23 -> V_28 ,
F_11 ( V_26 -> V_35 ) ,
F_11 ( V_26 -> V_34 ) ) ;
return - V_30 ;
}
if ( F_11 ( V_26 -> V_35 ) > ( 8 * F_11 ( V_26 -> V_36 ) ) ) {
F_14 ( L_6
L_8 ,
( unsigned long long ) V_23 -> V_28 ,
F_11 ( V_26 -> V_35 ) ,
8 * F_11 ( V_26 -> V_36 ) ) ;
return - V_30 ;
}
return 0 ;
}
static int F_18 ( struct V_20 * V_21 ,
struct V_37 * V_38 ,
struct V_22 * V_23 ,
int V_24 )
{
unsigned int V_39 ;
struct V_25 * V_26 = (struct V_25 * ) V_23 -> V_27 ;
if ( V_38 -> V_40 != V_26 -> V_41 ) {
F_14 ( L_9
L_10 ,
( unsigned long long ) V_23 -> V_28 ,
( unsigned long long ) F_15 ( V_26 -> V_41 ) ,
( unsigned long long ) F_15 ( V_38 -> V_40 ) ) ;
return - V_30 ;
}
V_39 = F_11 ( V_38 -> V_42 . V_43 . V_18 ) * F_11 ( V_38 -> V_42 . V_43 . V_19 ) ;
if ( F_11 ( V_26 -> V_35 ) > V_39 ) {
F_14 ( L_11 ,
( unsigned long long ) V_23 -> V_28 ,
F_11 ( V_26 -> V_35 ) ) ;
return - V_30 ;
}
if ( ( F_11 ( V_26 -> V_44 ) >
F_11 ( V_38 -> V_42 . V_43 . V_45 ) ) ||
( ( F_11 ( V_26 -> V_44 ) ==
F_11 ( V_38 -> V_42 . V_43 . V_45 ) ) && ! V_24 ) ) {
F_14 ( L_12 ,
( unsigned long long ) V_23 -> V_28 ,
F_11 ( V_26 -> V_44 ) ) ;
return - V_30 ;
}
return 0 ;
}
int F_19 ( struct V_20 * V_21 ,
struct V_37 * V_38 ,
struct V_22 * V_23 )
{
int V_46 ;
struct V_25 * V_26 = (struct V_25 * ) V_23 -> V_27 ;
F_20 ( ! F_21 ( V_23 ) ) ;
V_46 = F_22 ( V_21 , V_23 -> V_27 , & V_26 -> V_47 ) ;
if ( V_46 ) {
F_23 ( V_48 ,
L_13 ,
( unsigned long long ) V_23 -> V_28 ) ;
} else
V_46 = F_12 ( V_21 , V_23 , 1 ) ;
if ( ! V_46 )
V_46 = F_18 ( V_21 , V_38 , V_23 , 1 ) ;
return V_46 ;
}
static int F_24 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
int V_46 ;
struct V_25 * V_26 = (struct V_25 * ) V_23 -> V_27 ;
F_25 (
( unsigned long long ) V_23 -> V_28 ) ;
F_20 ( ! F_21 ( V_23 ) ) ;
V_46 = F_22 ( V_21 , V_23 -> V_27 , & V_26 -> V_47 ) ;
if ( V_46 )
return V_46 ;
return F_12 ( V_21 , V_23 , 0 ) ;
}
int F_26 ( struct V_8 * V_8 , struct V_37 * V_38 ,
T_1 V_49 , struct V_22 * * V_23 )
{
int V_46 ;
struct V_22 * V_50 = * V_23 ;
V_46 = F_27 ( F_28 ( V_8 ) , V_49 , & V_50 ,
F_24 ) ;
if ( V_46 )
goto V_51;
V_46 = F_18 ( V_8 -> V_52 , V_38 , V_50 , 0 ) ;
if ( V_46 ) {
F_7 ( V_50 ) ;
goto V_51;
}
if ( ! * V_23 )
* V_23 = V_50 ;
V_51:
return V_46 ;
}
static void F_29 ( struct V_53 * V_54 ,
struct V_25 * V_55 ,
struct V_16 * V_17 ,
T_1 V_56 , unsigned int V_57 )
{
struct V_58 * V_59 = & V_55 -> V_60 ;
struct V_61 * V_62 ;
F_20 ( ! F_30 ( V_54 ) ) ;
if ( ! V_59 -> V_63 )
V_59 -> V_64 = F_31 ( F_32 ( V_54 -> V_21 ) ) ;
V_62 = & V_59 -> V_65 [ F_11 ( V_59 -> V_63 ) ] ;
V_62 -> V_66 = F_33 ( V_56 ) ;
V_62 -> V_67 = F_34 ( F_11 ( V_55 -> V_35 ) /
F_11 ( V_17 -> V_19 ) ) ;
V_62 -> V_68 = F_31 ( V_57 ) ;
F_35 ( & V_55 -> V_35 , V_57 * F_11 ( V_17 -> V_19 ) ) ;
F_35 ( & V_55 -> V_34 ,
V_57 * F_11 ( V_17 -> V_19 ) ) ;
F_35 ( & V_59 -> V_63 , 1 ) ;
}
static int F_36 ( T_3 * V_69 ,
struct V_8 * V_70 ,
struct V_22 * V_71 ,
T_1 V_72 ,
unsigned int V_73 ,
T_4 V_74 ,
struct V_16 * V_17 )
{
int V_75 = 0 ;
struct V_53 * V_54 = F_17 ( V_70 -> V_52 ) ;
struct V_25 * V_55 = (struct V_25 * ) V_71 -> V_27 ;
struct V_20 * V_21 = V_70 -> V_52 ;
if ( ( ( unsigned long long ) V_71 -> V_28 ) != V_72 ) {
F_37 ( V_70 -> V_52 , L_14
L_15 ,
( unsigned long long ) V_72 ,
( unsigned long long ) V_71 -> V_28 ) ;
V_75 = - V_76 ;
goto V_77;
}
V_75 = F_38 ( V_69 ,
F_28 ( V_70 ) ,
V_71 ,
V_78 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
memset ( V_55 , 0 , V_21 -> V_79 ) ;
strcpy ( V_55 -> V_29 , V_80 ) ;
V_55 -> V_32 = F_34 ( F_17 ( V_21 ) -> V_33 ) ;
V_55 -> V_36 = F_31 ( F_40 ( V_21 , 1 ,
V_54 -> V_81 ) ) ;
V_55 -> V_44 = F_31 ( V_74 ) ;
V_55 -> V_82 = V_17 -> V_83 [ V_74 ] . V_84 ;
V_55 -> V_41 = F_33 ( F_41 ( V_70 ) -> V_85 ) ;
V_55 -> V_31 = F_33 ( V_72 ) ;
if ( V_73 == F_11 ( V_17 -> V_18 ) )
V_55 -> V_35 = F_31 ( F_10 ( V_17 ) ) ;
else
F_29 ( V_54 , V_55 , V_17 , V_72 ,
V_73 ) ;
F_42 ( 0 , ( unsigned long * ) V_55 -> V_86 ) ;
V_55 -> V_34 = F_31 ( F_11 ( V_55 -> V_35 ) - 1 ) ;
F_43 ( V_69 , V_71 ) ;
V_77:
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
static inline T_4 F_44 ( struct V_16 * V_17 )
{
T_4 V_87 , V_88 ;
V_88 = V_87 = 0 ;
while ( V_87 < F_11 ( V_17 -> V_89 ) ) {
if ( F_16 ( V_17 -> V_83 [ V_88 ] . V_90 ) >
F_16 ( V_17 -> V_83 [ V_87 ] . V_90 ) )
V_88 = V_87 ;
V_87 ++ ;
}
return V_88 ;
}
static struct V_22 *
F_45 ( struct V_53 * V_54 , T_3 * V_69 ,
struct V_8 * V_70 ,
struct V_6 * V_7 ,
struct V_16 * V_17 )
{
int V_75 ;
T_2 V_91 , V_92 ;
T_1 V_31 ;
struct V_22 * V_71 ;
unsigned int V_93 = F_44 ( V_17 ) ;
V_75 = F_46 ( V_69 , V_7 ,
F_11 ( V_17 -> V_18 ) , & V_91 ,
& V_92 ) ;
if ( V_75 < 0 ) {
if ( V_75 != - V_94 )
F_39 ( V_75 ) ;
goto V_77;
}
V_31 = F_47 ( V_54 -> V_21 , V_91 ) ;
F_48 (
( unsigned long long ) V_31 , V_93 ) ;
V_71 = F_49 ( V_54 -> V_21 , V_31 ) ;
if ( ! V_71 ) {
V_75 = - V_95 ;
F_39 ( V_75 ) ;
goto V_77;
}
F_50 ( F_28 ( V_70 ) , V_71 ) ;
V_75 = F_36 ( V_69 , V_70 , V_71 ,
V_31 , V_92 , V_93 , V_17 ) ;
if ( V_75 < 0 ) {
F_7 ( V_71 ) ;
F_39 ( V_75 ) ;
}
V_77:
return V_75 ? F_51 ( V_75 ) : V_71 ;
}
static int F_52 ( struct V_53 * V_54 ,
T_3 * V_69 ,
struct V_6 * V_7 ,
unsigned int V_96 ,
T_2 * V_91 , T_2 * V_92 )
{
int V_75 = 0 ;
while ( V_96 ) {
V_75 = F_46 ( V_69 , V_7 , V_96 ,
V_91 , V_92 ) ;
if ( V_75 != - V_94 )
break;
V_96 >>= 1 ;
}
return V_75 ;
}
static int F_53 ( T_3 * V_69 ,
struct V_8 * V_70 ,
struct V_22 * V_71 ,
struct V_6 * V_7 ,
struct V_16 * V_17 ,
unsigned int V_96 )
{
int V_75 ;
struct V_53 * V_54 = F_17 ( V_70 -> V_52 ) ;
struct V_25 * V_55 =
(struct V_25 * ) V_71 -> V_27 ;
unsigned int V_97 = F_11 ( V_17 -> V_18 ) -
F_11 ( V_55 -> V_35 ) / F_11 ( V_17 -> V_19 ) ;
T_2 V_98 , V_57 ;
T_1 V_56 ;
struct V_58 * V_59 = & V_55 -> V_60 ;
V_75 = F_38 ( V_69 ,
F_28 ( V_70 ) ,
V_71 ,
V_78 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
while ( ( V_97 > 0 ) && ( F_11 ( V_59 -> V_63 ) <
F_11 ( V_59 -> V_64 ) ) ) {
if ( V_96 > V_97 )
V_96 = V_97 ;
V_75 = F_52 ( V_54 , V_69 , V_7 ,
V_96 , & V_98 ,
& V_57 ) ;
if ( V_75 < 0 ) {
if ( V_75 != - V_94 )
F_39 ( V_75 ) ;
goto V_77;
}
V_56 = F_47 ( V_54 -> V_21 , V_98 ) ;
F_29 ( V_54 , V_55 , V_17 , V_56 ,
V_57 ) ;
V_96 = V_57 ;
V_97 = F_11 ( V_17 -> V_18 ) -
F_11 ( V_55 -> V_35 ) / F_11 ( V_17 -> V_19 ) ;
}
if ( V_97 > 0 ) {
V_75 = - V_94 ;
goto V_77;
}
F_43 ( V_69 , V_71 ) ;
V_77:
return V_75 ;
}
static void F_54 ( T_3 * V_69 ,
struct V_6 * V_99 ,
struct V_8 * V_70 ,
struct V_22 * V_71 )
{
int V_100 , V_101 ;
struct V_25 * V_55 ;
struct V_58 * V_59 ;
struct V_61 * V_62 ;
if ( ! V_71 )
return;
V_55 = (struct V_25 * ) V_71 -> V_27 ;
V_59 = & V_55 -> V_60 ;
for ( V_100 = 0 ; V_100 < F_11 ( V_59 -> V_63 ) ; V_100 ++ ) {
V_62 = & V_59 -> V_65 [ V_100 ] ;
V_101 = F_55 ( V_69 , V_99 -> V_9 ,
V_99 -> V_13 ,
F_15 ( V_62 -> V_66 ) ,
F_11 ( V_62 -> V_68 ) ) ;
if ( V_101 )
F_39 ( V_101 ) ;
}
F_56 ( F_28 ( V_70 ) , V_71 ) ;
F_7 ( V_71 ) ;
}
static struct V_22 *
F_57 ( T_3 * V_69 ,
struct V_8 * V_70 ,
struct V_6 * V_7 ,
struct V_16 * V_17 )
{
int V_75 ;
T_2 V_91 , V_92 ;
T_1 V_31 ;
unsigned int V_96 = F_11 ( V_17 -> V_18 ) >> 1 ;
struct V_22 * V_71 = NULL ;
unsigned int V_93 = F_44 ( V_17 ) ;
struct V_53 * V_54 = F_17 ( V_70 -> V_52 ) ;
if ( ! F_30 ( V_54 ) ) {
V_75 = - V_94 ;
goto V_77;
}
V_75 = F_58 ( V_69 ,
F_59 ( V_54 -> V_21 ) ) ;
if ( V_75 ) {
F_39 ( V_75 ) ;
goto V_77;
}
V_7 -> V_102 = 1 ;
V_75 = F_52 ( V_54 , V_69 , V_7 , V_96 ,
& V_91 , & V_92 ) ;
if ( V_75 < 0 ) {
if ( V_75 != - V_94 )
F_39 ( V_75 ) ;
goto V_77;
}
V_96 = V_92 ;
V_31 = F_47 ( V_54 -> V_21 , V_91 ) ;
F_60 (
( unsigned long long ) V_31 , V_93 ) ;
V_71 = F_49 ( V_54 -> V_21 , V_31 ) ;
if ( ! V_71 ) {
V_75 = - V_95 ;
F_39 ( V_75 ) ;
goto V_77;
}
F_50 ( F_28 ( V_70 ) , V_71 ) ;
V_75 = F_36 ( V_69 , V_70 , V_71 ,
V_31 , V_92 , V_93 , V_17 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
V_75 = F_53 ( V_69 , V_70 ,
V_71 , V_7 , V_17 , V_96 ) ;
if ( V_75 )
F_39 ( V_75 ) ;
V_77:
if ( V_75 )
F_54 ( V_69 , V_7 , V_70 , V_71 ) ;
return V_75 ? F_51 ( V_75 ) : V_71 ;
}
static int F_61 ( struct V_53 * V_54 ,
struct V_8 * V_70 ,
struct V_22 * V_23 ,
T_1 V_103 ,
T_1 * V_104 ,
int V_105 )
{
int V_75 , V_106 ;
struct V_37 * V_107 = (struct V_37 * ) V_23 -> V_27 ;
struct V_16 * V_17 ;
struct V_6 * V_7 = NULL ;
T_3 * V_69 = NULL ;
T_4 V_93 ;
struct V_22 * V_71 = NULL ;
struct V_25 * V_55 ;
F_20 ( F_62 ( V_70 ) ) ;
V_17 = & V_107 -> V_42 . V_43 ;
V_75 = F_63 ( V_54 ,
F_11 ( V_17 -> V_18 ) ,
V_103 , V_105 , & V_7 ) ;
if ( V_75 < 0 ) {
if ( V_75 != - V_94 )
F_39 ( V_75 ) ;
goto V_77;
}
V_106 = F_64 ( V_54 -> V_21 ,
F_11 ( V_17 -> V_18 ) ) ;
V_69 = F_65 ( V_54 , V_106 ) ;
if ( F_66 ( V_69 ) ) {
V_75 = F_67 ( V_69 ) ;
V_69 = NULL ;
F_39 ( V_75 ) ;
goto V_77;
}
if ( V_104 && * V_104 != 0 ) {
F_68 (
( unsigned long long ) * V_104 ) ;
V_7 -> V_108 = * V_104 ;
}
V_71 = F_45 ( V_54 , V_69 , V_70 ,
V_7 , V_17 ) ;
if ( F_66 ( V_71 ) && ( F_67 ( V_71 ) == - V_94 ) )
V_71 = F_57 ( V_69 ,
V_70 ,
V_7 , V_17 ) ;
if ( F_66 ( V_71 ) ) {
V_75 = F_67 ( V_71 ) ;
V_71 = NULL ;
if ( V_75 != - V_94 )
F_39 ( V_75 ) ;
goto V_77;
}
V_55 = (struct V_25 * ) V_71 -> V_27 ;
V_75 = F_69 ( V_69 , F_28 ( V_70 ) ,
V_23 , V_109 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
V_93 = F_11 ( V_55 -> V_44 ) ;
F_70 ( & V_17 -> V_83 [ V_93 ] . V_110 ,
F_11 ( V_55 -> V_34 ) ) ;
F_70 ( & V_17 -> V_83 [ V_93 ] . V_90 ,
F_11 ( V_55 -> V_35 ) ) ;
V_17 -> V_83 [ V_93 ] . V_84 = V_55 -> V_31 ;
if ( F_11 ( V_17 -> V_45 ) < F_11 ( V_17 -> V_89 ) )
F_35 ( & V_17 -> V_45 , 1 ) ;
F_70 ( & V_107 -> V_111 . V_112 . V_113 , F_11 ( V_55 -> V_35 ) -
F_11 ( V_55 -> V_34 ) ) ;
F_70 ( & V_107 -> V_111 . V_112 . V_114 , F_11 ( V_55 -> V_35 ) ) ;
F_70 ( & V_107 -> V_115 , F_11 ( V_17 -> V_18 ) ) ;
F_43 ( V_69 , V_23 ) ;
F_71 ( & F_41 ( V_70 ) -> V_116 ) ;
F_41 ( V_70 ) -> V_117 = F_16 ( V_107 -> V_115 ) ;
V_107 -> V_118 = F_33 ( F_72 ( V_70 -> V_52 ,
F_16 ( V_107 -> V_115 ) ) ) ;
F_73 ( & F_41 ( V_70 ) -> V_116 ) ;
F_74 ( V_70 , F_15 ( V_107 -> V_118 ) ) ;
V_70 -> V_119 = F_75 ( V_70 ) ;
F_76 ( V_69 , V_70 , 0 ) ;
V_75 = 0 ;
if ( V_104 )
* V_104 = V_7 -> V_108 ;
V_77:
if ( V_69 )
F_77 ( V_54 , V_69 ) ;
if ( V_7 )
F_9 ( V_7 ) ;
F_7 ( V_71 ) ;
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
static int F_78 ( struct V_53 * V_54 ,
struct V_6 * V_7 ,
int type ,
T_2 V_120 ,
T_1 * V_104 ,
int V_105 )
{
int V_75 ;
T_2 V_121 = V_7 -> V_122 ;
struct V_8 * V_70 ;
struct V_22 * V_23 = NULL ;
struct V_37 * V_107 ;
T_2 V_123 ;
V_70 = F_79 ( V_54 , type , V_120 ) ;
if ( ! V_70 ) {
F_39 ( - V_30 ) ;
return - V_30 ;
}
F_80 ( & V_70 -> V_12 ) ;
V_75 = F_81 ( V_70 , & V_23 , 1 ) ;
if ( V_75 < 0 ) {
F_5 ( & V_70 -> V_12 ) ;
F_6 ( V_70 ) ;
F_39 ( V_75 ) ;
return V_75 ;
}
V_7 -> V_9 = V_70 ;
V_7 -> V_124 = V_120 ;
V_107 = (struct V_37 * ) V_23 -> V_27 ;
F_20 ( ! F_82 ( V_107 ) ) ;
if ( ! ( V_107 -> V_125 & F_34 ( V_126 ) ) ) {
F_37 ( V_70 -> V_52 , L_16 ,
( unsigned long long ) F_15 ( V_107 -> V_40 ) ) ;
V_75 = - V_76 ;
goto V_77;
}
V_123 = F_16 ( V_107 -> V_111 . V_112 . V_114 ) -
F_16 ( V_107 -> V_111 . V_112 . V_113 ) ;
if ( V_121 > V_123 ) {
if ( F_62 ( V_70 ) ) {
F_83 ( V_121 ,
V_123 ) ;
V_75 = - V_94 ;
goto V_77;
}
if ( ! ( V_105 & V_127 ) ) {
F_84 (
V_120 , V_121 , V_123 ) ;
V_75 = - V_94 ;
goto V_77;
}
V_75 = F_61 ( V_54 , V_70 , V_23 ,
V_7 -> V_128 ,
V_104 , V_105 ) ;
if ( V_75 < 0 ) {
if ( V_75 != - V_94 )
F_39 ( V_75 ) ;
goto V_77;
}
F_85 ( & V_54 -> V_129 . V_130 ) ;
F_20 ( V_121 >
( F_16 ( V_107 -> V_111 . V_112 . V_114 )
- F_16 ( V_107 -> V_111 . V_112 . V_113 ) ) ) ;
}
F_86 ( V_23 ) ;
V_7 -> V_13 = V_23 ;
V_77:
F_7 ( V_23 ) ;
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
static void F_87 ( struct V_53 * V_54 )
{
F_71 ( & V_54 -> V_131 ) ;
V_54 -> V_132 = V_133 ;
F_73 ( & V_54 -> V_131 ) ;
F_88 ( & V_54 -> V_134 , 0 ) ;
}
static void F_89 ( struct V_53 * V_54 )
{
F_71 ( & V_54 -> V_131 ) ;
V_54 -> V_135 = V_133 ;
F_73 ( & V_54 -> V_131 ) ;
F_88 ( & V_54 -> V_136 , 0 ) ;
}
void F_90 ( struct V_53 * V_54 )
{
F_87 ( V_54 ) ;
F_89 ( V_54 ) ;
}
static void F_91 ( struct V_53 * V_54 , int V_120 , int type )
{
F_71 ( & V_54 -> V_131 ) ;
if ( type == V_137 )
V_54 -> V_132 = V_120 ;
else if ( type == V_138 )
V_54 -> V_135 = V_120 ;
F_73 ( & V_54 -> V_131 ) ;
}
static int F_92 ( struct V_53 * V_54 , int type )
{
int V_120 = V_133 ;
F_71 ( & V_54 -> V_131 ) ;
if ( type == V_137 )
V_120 = V_54 -> V_132 ;
else if ( type == V_138 )
V_120 = V_54 -> V_135 ;
F_73 ( & V_54 -> V_131 ) ;
return V_120 ;
}
static int F_93 ( struct V_53 * V_54 )
{
return F_92 ( V_54 , V_137 ) ;
}
static int F_94 ( struct V_53 * V_54 )
{
return F_92 ( V_54 , V_138 ) ;
}
static int F_95 ( struct V_53 * V_54 ,
struct V_6 * V_7 ,
int type )
{
int V_100 , V_75 = - V_94 ;
int V_120 = F_92 ( V_54 , type ) ;
if ( V_120 == V_133 )
V_120 = V_54 -> V_139 + 1 ;
for ( V_100 = 0 ; V_100 < V_54 -> V_140 ; V_100 ++ , V_120 ++ ) {
if ( V_120 == V_54 -> V_140 )
V_120 = 0 ;
if ( V_120 == V_54 -> V_139 )
continue;
V_75 = F_78 ( V_54 , V_7 ,
type ,
( T_2 ) V_120 , NULL ,
V_141 ) ;
if ( V_75 >= 0 ) {
F_91 ( V_54 , V_120 , type ) ;
break;
}
F_3 ( V_7 ) ;
}
return V_75 ;
}
static int F_96 ( struct V_53 * V_54 ,
struct V_6 * V_7 )
{
return F_95 ( V_54 , V_7 , V_137 ) ;
}
static int F_97 ( struct V_53 * V_54 ,
struct V_6 * V_7 )
{
return F_95 ( V_54 , V_7 , V_138 ) ;
}
int F_98 ( struct V_53 * V_54 ,
int V_142 ,
struct V_6 * * V_7 )
{
int V_75 ;
int V_120 = F_94 ( V_54 ) ;
* V_7 = F_99 ( sizeof( struct V_6 ) , V_143 ) ;
if ( ! ( * V_7 ) ) {
V_75 = - V_95 ;
F_39 ( V_75 ) ;
goto V_77;
}
( * V_7 ) -> V_122 = V_142 ;
( * V_7 ) -> V_10 = V_144 ;
( * V_7 ) -> V_145 = V_146 ;
if ( V_120 != V_133 &&
F_100 ( & V_54 -> V_136 ) < V_147 )
goto V_148;
F_88 ( & V_54 -> V_136 , 0 ) ;
V_75 = F_78 ( V_54 , ( * V_7 ) ,
V_138 ,
( T_2 ) V_54 -> V_139 , NULL ,
V_149 | V_127 ) ;
if ( V_75 >= 0 ) {
V_75 = 0 ;
if ( V_120 != V_133 )
F_89 ( V_54 ) ;
goto V_77;
} else if ( V_75 < 0 && V_75 != - V_94 ) {
F_39 ( V_75 ) ;
goto V_77;
}
F_3 ( * V_7 ) ;
V_148:
V_75 = F_97 ( V_54 , * V_7 ) ;
F_85 ( & V_54 -> V_136 ) ;
if ( V_75 < 0 ) {
if ( V_75 != - V_94 )
F_39 ( V_75 ) ;
goto V_77;
}
V_75 = 0 ;
V_77:
if ( ( V_75 < 0 ) && * V_7 ) {
F_9 ( * V_7 ) ;
* V_7 = NULL ;
}
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
int F_101 ( struct V_53 * V_54 ,
struct V_58 * V_150 ,
struct V_6 * * V_7 )
{
return F_98 ( V_54 ,
F_102 ( V_150 ) ,
V_7 ) ;
}
int F_103 ( struct V_53 * V_54 ,
struct V_6 * * V_7 )
{
int V_75 ;
int V_120 = F_93 ( V_54 ) ;
T_1 V_151 ;
* V_7 = F_99 ( sizeof( struct V_6 ) , V_143 ) ;
if ( ! ( * V_7 ) ) {
V_75 = - V_95 ;
F_39 ( V_75 ) ;
goto V_77;
}
( * V_7 ) -> V_122 = 1 ;
( * V_7 ) -> V_10 = V_152 ;
( * V_7 ) -> V_145 = V_146 ;
if ( ! ( V_54 -> V_153 & V_154 ) )
( * V_7 ) -> V_128 = ( T_2 ) ~ 0U ;
if ( V_120 != V_133 &&
F_100 ( & V_54 -> V_134 ) < V_147 )
goto V_155;
F_88 ( & V_54 -> V_134 , 0 ) ;
V_151 = V_54 -> V_156 ;
V_75 = F_78 ( V_54 , * V_7 ,
V_137 ,
( T_2 ) V_54 -> V_139 ,
& V_151 ,
V_127 |
V_149 ) ;
if ( V_75 >= 0 ) {
V_75 = 0 ;
F_71 ( & V_54 -> V_131 ) ;
V_54 -> V_156 = V_151 ;
F_73 ( & V_54 -> V_131 ) ;
F_104 (
( unsigned long long ) V_151 ) ;
if ( V_120 != V_133 )
F_87 ( V_54 ) ;
goto V_77;
} else if ( V_75 < 0 && V_75 != - V_94 ) {
F_39 ( V_75 ) ;
goto V_77;
}
F_3 ( * V_7 ) ;
V_155:
V_75 = F_96 ( V_54 , * V_7 ) ;
F_85 ( & V_54 -> V_134 ) ;
if ( V_75 < 0 ) {
if ( V_75 != - V_94 )
F_39 ( V_75 ) ;
goto V_77;
}
V_75 = 0 ;
V_77:
if ( ( V_75 < 0 ) && * V_7 ) {
F_9 ( * V_7 ) ;
* V_7 = NULL ;
}
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
int F_105 ( struct V_53 * V_54 ,
struct V_6 * V_7 )
{
int V_75 ;
V_7 -> V_10 = V_157 ;
V_7 -> V_145 = V_158 ;
V_75 = F_78 ( V_54 , V_7 ,
V_159 ,
V_133 , NULL ,
V_127 ) ;
if ( V_75 < 0 && V_75 != - V_94 ) {
F_39 ( V_75 ) ;
goto V_77;
}
V_77:
return V_75 ;
}
static int F_63 ( struct V_53 * V_54 ,
T_2 V_121 , T_1 V_103 ,
int V_105 ,
struct V_6 * * V_7 )
{
int V_75 ;
* V_7 = F_99 ( sizeof( struct V_6 ) , V_143 ) ;
if ( ! ( * V_7 ) ) {
V_75 = - V_95 ;
F_39 ( V_75 ) ;
goto V_77;
}
( * V_7 ) -> V_122 = V_121 ;
( * V_7 ) -> V_128 = V_103 ;
V_75 = - V_94 ;
if ( ! ( V_105 & V_149 ) &&
F_106 ( V_54 , V_121 ) ) {
V_75 = F_107 ( V_54 ,
V_121 ,
* V_7 ) ;
if ( ( V_75 < 0 ) && ( V_75 != - V_94 ) ) {
F_39 ( V_75 ) ;
goto V_77;
}
}
if ( V_75 == - V_94 ) {
V_75 = F_105 ( V_54 , * V_7 ) ;
if ( V_75 < 0 ) {
if ( V_75 != - V_94 )
F_39 ( V_75 ) ;
goto V_77;
}
}
V_75 = 0 ;
V_77:
if ( ( V_75 < 0 ) && * V_7 ) {
F_9 ( * V_7 ) ;
* V_7 = NULL ;
}
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
int F_108 ( struct V_53 * V_54 ,
T_2 V_121 ,
struct V_6 * * V_7 )
{
return F_63 ( V_54 , V_121 , 0 ,
V_127 , V_7 ) ;
}
static int F_109 ( struct V_22 * V_71 ,
int V_160 )
{
struct V_25 * V_55 = (struct V_25 * ) V_71 -> V_27 ;
int V_101 ;
if ( F_110 ( V_160 , ( unsigned long * ) V_55 -> V_86 ) )
return 0 ;
if ( ! F_111 ( V_71 ) )
return 1 ;
F_112 ( V_71 ) ;
V_55 = (struct V_25 * ) F_113 ( V_71 ) -> V_161 ;
if ( V_55 )
V_101 = ! F_110 ( V_160 , ( unsigned long * ) V_55 -> V_86 ) ;
else
V_101 = 1 ;
F_114 ( V_71 ) ;
return V_101 ;
}
static int F_115 ( struct V_53 * V_54 ,
struct V_22 * V_71 ,
unsigned int V_121 ,
unsigned int V_162 ,
struct V_1 * V_2 )
{
void * V_163 ;
T_4 V_164 , V_165 ;
int V_166 , V_167 , V_168 , V_75 = 0 ;
struct V_25 * V_55 = (struct V_25 * ) V_71 -> V_27 ;
F_20 ( ! F_13 ( V_55 ) ) ;
V_168 = V_167 = V_164 = V_165 = 0 ;
V_163 = V_55 -> V_86 ;
while( ( V_166 = F_116 ( V_163 , V_162 , V_167 ) ) != - 1 ) {
if ( V_166 == V_162 )
break;
if ( ! F_109 ( V_71 , V_166 ) ) {
V_168 = 0 ;
V_167 = V_166 + 1 ;
} else if ( V_166 == V_167 ) {
V_168 ++ ;
V_167 ++ ;
} else {
V_168 = 1 ;
V_167 = V_166 + 1 ;
}
if ( V_168 > V_165 ) {
V_165 = V_168 ;
V_164 = V_167 - V_168 ;
}
if ( V_168 == V_121 ) {
break;
}
}
if ( V_165 ) {
V_2 -> V_5 = V_164 ;
V_2 -> V_169 = V_165 ;
} else {
V_75 = - V_94 ;
}
return V_75 ;
}
int F_117 ( T_3 * V_69 ,
struct V_8 * V_70 ,
struct V_25 * V_55 ,
struct V_22 * V_170 ,
unsigned int V_91 ,
unsigned int V_92 )
{
int V_75 ;
void * V_163 = V_55 -> V_86 ;
int V_171 = V_109 ;
F_20 ( ! F_13 ( V_55 ) ) ;
F_20 ( F_11 ( V_55 -> V_34 ) < V_92 ) ;
F_118 ( V_91 , V_92 ) ;
if ( F_62 ( V_70 ) )
V_171 = V_172 ;
V_75 = F_38 ( V_69 ,
F_28 ( V_70 ) ,
V_170 ,
V_171 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
F_35 ( & V_55 -> V_34 , - V_92 ) ;
if ( F_11 ( V_55 -> V_34 ) > F_11 ( V_55 -> V_35 ) ) {
F_37 ( V_70 -> V_52 , L_17
L_18 ,
( unsigned long long ) F_15 ( V_55 -> V_31 ) ,
F_11 ( V_55 -> V_35 ) ,
F_11 ( V_55 -> V_34 ) , V_92 ) ;
return - V_173 ;
}
while( V_92 -- )
F_42 ( V_91 ++ , V_163 ) ;
F_43 ( V_69 , V_170 ) ;
V_77:
return V_75 ;
}
static inline T_4 F_119 ( struct V_16 * V_17 )
{
T_4 V_87 , V_88 ;
F_20 ( ! V_17 -> V_45 ) ;
V_88 = V_87 = 0 ;
while ( V_87 < F_11 ( V_17 -> V_45 ) ) {
if ( F_16 ( V_17 -> V_83 [ V_87 ] . V_110 ) >
F_16 ( V_17 -> V_83 [ V_88 ] . V_110 ) )
V_88 = V_87 ;
V_87 ++ ;
}
F_20 ( V_88 >= F_11 ( V_17 -> V_45 ) ) ;
return V_88 ;
}
static int F_120 ( T_3 * V_69 ,
struct V_8 * V_70 ,
struct V_22 * V_174 ,
struct V_22 * V_71 ,
struct V_22 * V_175 ,
T_4 V_176 )
{
int V_75 ;
T_1 V_177 , V_178 ;
struct V_37 * V_107 = (struct V_37 * ) V_174 -> V_27 ;
struct V_25 * V_55 = (struct V_25 * ) V_71 -> V_27 ;
struct V_25 * V_179 = (struct V_25 * ) V_175 -> V_27 ;
F_20 ( ! F_13 ( V_55 ) ) ;
F_20 ( ! F_13 ( V_179 ) ) ;
F_121 (
( unsigned long long ) F_15 ( V_107 -> V_40 ) , V_176 ,
( unsigned long long ) F_15 ( V_55 -> V_31 ) ,
( unsigned long long ) F_15 ( V_179 -> V_31 ) ) ;
V_177 = F_15 ( V_55 -> V_82 ) ;
V_178 = F_15 ( V_179 -> V_82 ) ;
V_75 = F_38 ( V_69 , F_28 ( V_70 ) ,
V_175 ,
V_109 ) ;
if ( V_75 < 0 )
goto V_51;
V_179 -> V_82 = V_55 -> V_82 ;
F_43 ( V_69 , V_175 ) ;
V_75 = F_38 ( V_69 , F_28 ( V_70 ) ,
V_71 , V_109 ) ;
if ( V_75 < 0 )
goto V_180;
V_55 -> V_82 = V_107 -> V_42 . V_43 . V_83 [ V_176 ] . V_84 ;
F_43 ( V_69 , V_71 ) ;
V_75 = F_69 ( V_69 , F_28 ( V_70 ) ,
V_174 , V_109 ) ;
if ( V_75 < 0 )
goto V_181;
V_107 -> V_42 . V_43 . V_83 [ V_176 ] . V_84 = V_55 -> V_31 ;
F_43 ( V_69 , V_174 ) ;
V_51:
if ( V_75 < 0 )
F_39 ( V_75 ) ;
return V_75 ;
V_181:
V_55 -> V_82 = F_33 ( V_177 ) ;
V_180:
V_179 -> V_82 = F_33 ( V_178 ) ;
goto V_51;
}
static inline int F_122 ( struct V_25 * V_55 ,
T_2 V_182 )
{
return F_11 ( V_55 -> V_34 ) > V_182 ;
}
static int V_158 ( struct V_8 * V_8 ,
struct V_22 * V_170 ,
T_2 V_121 , T_2 V_96 ,
T_1 V_103 ,
struct V_1 * V_2 )
{
int V_183 = - V_94 ;
int V_101 ;
T_1 V_184 ;
struct V_25 * V_26 = (struct V_25 * ) V_170 -> V_27 ;
struct V_53 * V_54 = F_17 ( V_8 -> V_52 ) ;
unsigned int V_39 , V_185 ;
F_20 ( ! F_62 ( V_8 ) ) ;
if ( V_26 -> V_34 ) {
V_39 = F_11 ( V_26 -> V_35 ) ;
V_185 = F_123 ( V_8 -> V_52 ,
F_15 ( V_26 -> V_31 ) ) ;
if ( ( V_185 + V_39 ) >
F_41 ( V_8 ) -> V_117 ) {
V_39 = F_41 ( V_8 ) -> V_117 - V_185 ;
F_124 (
( unsigned long long ) F_15 ( V_26 -> V_31 ) ,
F_11 ( V_26 -> V_35 ) ,
F_41 ( V_8 ) -> V_117 , V_39 ) ;
}
V_101 = F_115 ( F_17 ( V_8 -> V_52 ) ,
V_170 , V_121 ,
V_39 , V_2 ) ;
if ( V_101 )
return V_101 ;
if ( V_103 ) {
V_184 = F_47 ( V_8 -> V_52 ,
V_185 +
V_2 -> V_5 +
V_2 -> V_169 ) ;
F_125 (
( unsigned long long ) V_184 ,
( unsigned long long ) V_103 ) ;
if ( V_184 > V_103 )
return - V_94 ;
}
if ( V_96 <= V_2 -> V_169 )
V_183 = 0 ;
else if ( V_2 -> V_169 ) {
F_126 ( V_54 , V_2 -> V_169 ) ;
}
}
return V_183 ;
}
static int V_146 ( struct V_8 * V_8 ,
struct V_22 * V_170 ,
T_2 V_121 , T_2 V_96 ,
T_1 V_103 ,
struct V_1 * V_2 )
{
int V_101 = - V_94 ;
T_1 V_184 ;
struct V_25 * V_55 = (struct V_25 * ) V_170 -> V_27 ;
F_20 ( V_96 != 1 ) ;
F_20 ( F_62 ( V_8 ) ) ;
if ( V_55 -> V_34 ) {
V_101 = F_115 ( F_17 ( V_8 -> V_52 ) ,
V_170 , V_121 ,
F_11 ( V_55 -> V_35 ) ,
V_2 ) ;
if ( ! V_101 && V_103 ) {
V_184 = F_15 ( V_55 -> V_31 ) +
V_2 -> V_5 + V_2 -> V_169 ;
F_127 (
( unsigned long long ) V_184 ,
( unsigned long long ) V_103 ) ;
if ( V_184 > V_103 )
V_101 = - V_94 ;
}
}
return V_101 ;
}
int F_128 ( struct V_8 * V_8 ,
T_3 * V_69 ,
struct V_22 * V_186 ,
T_2 V_92 ,
T_4 V_176 )
{
int V_101 ;
T_2 V_187 ;
struct V_37 * V_38 = (struct V_37 * ) V_186 -> V_27 ;
struct V_16 * V_17 = (struct V_16 * ) & V_38 -> V_42 . V_43 ;
V_101 = F_69 ( V_69 , F_28 ( V_8 ) , V_186 ,
V_109 ) ;
if ( V_101 < 0 ) {
F_39 ( V_101 ) ;
goto V_51;
}
V_187 = F_16 ( V_38 -> V_111 . V_112 . V_113 ) ;
V_38 -> V_111 . V_112 . V_113 = F_34 ( V_92 + V_187 ) ;
F_70 ( & V_17 -> V_83 [ V_176 ] . V_110 , - V_92 ) ;
F_43 ( V_69 , V_186 ) ;
V_51:
return V_101 ;
}
void F_129 ( struct V_8 * V_8 ,
struct V_22 * V_186 ,
T_2 V_92 ,
T_4 V_176 )
{
T_2 V_187 ;
struct V_37 * V_38 = (struct V_37 * ) V_186 -> V_27 ;
struct V_16 * V_17 ;
V_17 = (struct V_16 * ) & V_38 -> V_42 . V_43 ;
V_187 = F_16 ( V_38 -> V_111 . V_112 . V_113 ) ;
V_38 -> V_111 . V_112 . V_113 = F_34 ( V_187 - V_92 ) ;
F_70 ( & V_17 -> V_83 [ V_176 ] . V_110 , V_92 ) ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
struct V_16 * V_17 )
{
unsigned int V_188 = F_11 ( V_17 -> V_19 ) ;
unsigned int V_189 = F_16 ( V_62 -> V_67 ) * V_188 ;
unsigned int V_190 = F_11 ( V_62 -> V_68 ) * V_188 ;
if ( V_2 -> V_5 < V_189 )
return 0 ;
if ( V_2 -> V_5 >= ( V_189 + V_190 ) )
return 0 ;
V_2 -> V_3 = F_15 ( V_62 -> V_66 ) +
( V_2 -> V_5 - V_189 ) ;
if ( ( V_2 -> V_5 + V_2 -> V_169 ) > ( V_189 + V_190 ) )
V_2 -> V_169 = ( V_189 + V_190 ) - V_2 -> V_5 ;
return 1 ;
}
static void F_131 ( struct V_6 * V_7 ,
struct V_25 * V_55 ,
struct V_1 * V_2 )
{
int V_100 ;
T_1 V_31 = V_2 -> V_4 ;
struct V_61 * V_62 ;
struct V_37 * V_38 = (struct V_37 * ) V_7 -> V_13 -> V_27 ;
struct V_16 * V_17 = & V_38 -> V_42 . V_43 ;
if ( F_62 ( V_7 -> V_9 ) ) {
V_2 -> V_3 = 0 ;
return;
}
V_2 -> V_3 = V_2 -> V_4 + V_2 -> V_5 ;
V_2 -> V_4 = 0 ;
if ( ! F_30 ( F_17 ( V_7 -> V_9 -> V_52 ) ) ||
! V_55 -> V_60 . V_63 )
return;
for ( V_100 = 0 ; V_100 < F_11 ( V_55 -> V_60 . V_63 ) ; V_100 ++ ) {
V_62 = & V_55 -> V_60 . V_65 [ V_100 ] ;
if ( F_130 ( V_2 , V_62 , V_17 ) ) {
V_2 -> V_4 = V_31 ;
break;
}
}
}
static int F_132 ( struct V_6 * V_7 ,
T_3 * V_69 ,
T_2 V_121 ,
T_2 V_96 ,
struct V_1 * V_2 ,
T_4 * V_191 )
{
int V_101 ;
struct V_22 * V_170 = NULL ;
struct V_25 * V_26 ;
struct V_37 * V_38 = (struct V_37 * ) V_7 -> V_13 -> V_27 ;
struct V_8 * V_70 = V_7 -> V_9 ;
V_101 = F_26 ( V_70 , V_38 ,
V_2 -> V_4 , & V_170 ) ;
if ( V_101 < 0 ) {
F_39 ( V_101 ) ;
return V_101 ;
}
V_26 = (struct V_25 * ) V_170 -> V_27 ;
V_101 = V_7 -> V_145 ( V_70 , V_170 , V_121 , V_96 ,
V_7 -> V_128 , V_2 ) ;
if ( V_101 < 0 ) {
if ( V_101 != - V_94 )
F_39 ( V_101 ) ;
goto V_51;
}
if ( ! V_101 )
F_131 ( V_7 , V_26 , V_2 ) ;
V_2 -> V_192 = V_170 -> V_28 ;
if ( V_7 -> V_193 )
goto V_194;
V_101 = F_128 ( V_70 , V_69 , V_7 -> V_13 ,
V_2 -> V_169 ,
F_11 ( V_26 -> V_44 ) ) ;
if ( V_101 < 0 ) {
F_39 ( V_101 ) ;
goto V_51;
}
V_101 = F_117 ( V_69 , V_70 , V_26 , V_170 ,
V_2 -> V_5 , V_2 -> V_169 ) ;
if ( V_101 < 0 ) {
F_129 ( V_70 , V_7 -> V_13 ,
V_2 -> V_169 ,
F_11 ( V_26 -> V_44 ) ) ;
F_39 ( V_101 ) ;
}
V_194:
* V_191 = F_11 ( V_26 -> V_34 ) ;
V_51:
F_7 ( V_170 ) ;
return V_101 ;
}
static int F_133 ( struct V_6 * V_7 ,
T_3 * V_69 ,
T_2 V_121 ,
T_2 V_96 ,
struct V_1 * V_2 ,
T_4 * V_191 )
{
int V_75 ;
T_4 V_176 ;
T_1 V_195 ;
struct V_8 * V_70 = V_7 -> V_9 ;
struct V_22 * V_170 = NULL ;
struct V_22 * V_196 = NULL ;
struct V_37 * V_107 = (struct V_37 * ) V_7 -> V_13 -> V_27 ;
struct V_16 * V_17 = (struct V_16 * ) & V_107 -> V_42 . V_43 ;
struct V_25 * V_55 ;
V_176 = V_7 -> V_197 ;
F_134 (
( unsigned long long ) F_41 ( V_70 ) -> V_85 ,
V_121 , V_176 ) ;
V_75 = F_26 ( V_70 , V_107 ,
F_15 ( V_17 -> V_83 [ V_176 ] . V_84 ) ,
& V_170 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
V_55 = (struct V_25 * ) V_170 -> V_27 ;
V_75 = - V_94 ;
while ( ( V_75 = V_7 -> V_145 ( V_70 , V_170 ,
V_121 , V_96 ,
V_7 -> V_128 ,
V_2 ) ) == - V_94 ) {
if ( ! V_55 -> V_82 )
break;
F_7 ( V_196 ) ;
V_196 = NULL ;
V_195 = F_15 ( V_55 -> V_82 ) ;
V_196 = V_170 ;
V_170 = NULL ;
V_75 = F_26 ( V_70 , V_107 ,
V_195 , & V_170 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
V_55 = (struct V_25 * ) V_170 -> V_27 ;
}
if ( V_75 < 0 ) {
if ( V_75 != - V_94 )
F_39 ( V_75 ) ;
goto V_77;
}
F_135 (
( unsigned long long ) F_15 ( V_55 -> V_31 ) , V_2 -> V_169 ) ;
V_2 -> V_4 = F_15 ( V_55 -> V_31 ) ;
F_20 ( V_2 -> V_169 == 0 ) ;
if ( ! V_75 )
F_131 ( V_7 , V_55 , V_2 ) ;
V_2 -> V_192 = V_170 -> V_28 ;
if ( ! V_7 -> V_102 &&
( V_196 ) &&
( F_122 ( V_55 , V_2 -> V_169 ) ) ) {
V_75 = F_120 ( V_69 , V_70 ,
V_7 -> V_13 , V_170 ,
V_196 , V_176 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
}
if ( V_7 -> V_193 )
goto V_194;
V_75 = F_128 ( V_70 , V_69 ,
V_7 -> V_13 , V_2 -> V_169 ,
V_176 ) ;
if ( V_75 ) {
F_39 ( V_75 ) ;
goto V_77;
}
V_75 = F_117 ( V_69 ,
V_70 ,
V_55 ,
V_170 ,
V_2 -> V_5 ,
V_2 -> V_169 ) ;
if ( V_75 < 0 ) {
F_129 ( V_70 ,
V_7 -> V_13 , V_2 -> V_169 , V_176 ) ;
F_39 ( V_75 ) ;
goto V_77;
}
F_136 (
( unsigned long long ) F_15 ( V_107 -> V_40 ) ,
V_2 -> V_169 ) ;
V_194:
* V_191 = F_11 ( V_55 -> V_34 ) ;
V_77:
F_7 ( V_170 ) ;
F_7 ( V_196 ) ;
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
static int F_137 ( struct V_6 * V_7 ,
T_3 * V_69 ,
T_2 V_121 ,
T_2 V_96 ,
struct V_1 * V_2 )
{
int V_75 ;
T_4 V_198 , V_100 ;
T_4 V_191 = 0 ;
T_1 V_199 = V_7 -> V_108 ;
struct V_16 * V_17 ;
struct V_37 * V_107 ;
F_20 ( V_7 -> V_200 >= V_7 -> V_122 ) ;
F_20 ( V_121 > ( V_7 -> V_122 - V_7 -> V_200 ) ) ;
F_20 ( ! V_7 -> V_13 ) ;
V_107 = (struct V_37 * ) V_7 -> V_13 -> V_27 ;
F_20 ( ! F_82 ( V_107 ) ) ;
if ( F_16 ( V_107 -> V_111 . V_112 . V_113 ) >=
F_16 ( V_107 -> V_111 . V_112 . V_114 ) ) {
F_37 ( V_7 -> V_9 -> V_52 ,
L_19
L_20 ,
( unsigned long long ) F_15 ( V_107 -> V_40 ) ,
F_16 ( V_107 -> V_111 . V_112 . V_113 ) ,
F_16 ( V_107 -> V_111 . V_112 . V_114 ) ) ;
V_75 = - V_76 ;
goto V_77;
}
V_2 -> V_4 = V_199 ;
if ( V_2 -> V_4 ) {
V_75 = F_132 ( V_7 , V_69 , V_121 ,
V_96 , V_2 , & V_191 ) ;
if ( ! V_75 )
goto V_201;
if ( V_75 < 0 && V_75 != - V_94 ) {
F_39 ( V_75 ) ;
goto V_77;
}
}
V_17 = (struct V_16 * ) & V_107 -> V_42 . V_43 ;
V_198 = F_119 ( V_17 ) ;
V_7 -> V_197 = V_198 ;
V_75 = F_133 ( V_7 , V_69 , V_121 , V_96 ,
V_2 , & V_191 ) ;
if ( ! V_75 ) {
V_199 = F_1 ( V_2 ) ;
goto V_201;
}
if ( V_75 < 0 && V_75 != - V_94 ) {
F_39 ( V_75 ) ;
goto V_77;
}
F_138 ( V_198 ) ;
V_7 -> V_102 = 1 ;
for ( V_100 = 0 ; V_100 < F_11 ( V_17 -> V_45 ) ; V_100 ++ ) {
if ( V_100 == V_198 )
continue;
if ( ! V_17 -> V_83 [ V_100 ] . V_110 )
continue;
V_7 -> V_197 = V_100 ;
V_75 = F_133 ( V_7 , V_69 , V_121 , V_96 ,
V_2 , & V_191 ) ;
if ( ! V_75 ) {
V_199 = F_1 ( V_2 ) ;
break;
}
if ( V_75 < 0 && V_75 != - V_94 ) {
F_39 ( V_75 ) ;
goto V_77;
}
}
V_201:
if ( V_75 != - V_94 ) {
if ( V_191 < V_96 )
V_7 -> V_108 = 0 ;
else
V_7 -> V_108 = V_199 ;
}
V_77:
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
int F_139 ( T_3 * V_69 ,
struct V_6 * V_7 ,
T_2 V_121 ,
T_1 * V_202 ,
T_4 * V_203 ,
unsigned int * V_92 ,
T_1 * V_204 )
{
int V_75 ;
struct V_1 V_2 = { . V_3 = 0 , } ;
F_20 ( ! V_7 ) ;
F_20 ( V_7 -> V_122 < ( V_7 -> V_200 + V_121 ) ) ;
F_20 ( V_7 -> V_10 != V_144 ) ;
V_75 = F_137 ( V_7 ,
V_69 ,
V_121 ,
1 ,
& V_2 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
F_85 ( & F_17 ( V_7 -> V_9 -> V_52 ) -> V_129 . V_205 ) ;
* V_202 = V_2 . V_4 ;
* V_203 = V_2 . V_5 ;
* V_204 = V_2 . V_3 ;
V_7 -> V_200 += V_2 . V_169 ;
* V_92 = V_2 . V_169 ;
V_75 = 0 ;
V_77:
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
static void F_140 ( struct V_8 * V_206 ,
struct V_22 * V_207 ,
struct V_6 * V_7 )
{
struct V_37 * V_38 = (struct V_37 * ) V_207 -> V_27 ;
if ( F_41 ( V_206 ) -> V_208 &&
F_41 ( V_206 ) -> V_209 == V_7 -> V_124 )
V_7 -> V_108 = F_41 ( V_206 ) -> V_208 ;
else if ( F_11 ( V_38 -> V_210 ) == V_7 -> V_124 ) {
if ( V_38 -> V_211 )
V_7 -> V_108 = F_15 ( V_38 -> V_211 ) ;
else
V_7 -> V_108 = F_2 (
F_15 ( V_38 -> V_40 ) ,
F_11 ( V_38 -> V_212 ) ) ;
}
}
static inline void F_141 ( struct V_8 * V_206 ,
struct V_6 * V_7 )
{
F_41 ( V_206 ) -> V_208 = V_7 -> V_108 ;
F_41 ( V_206 ) -> V_209 = V_7 -> V_124 ;
}
int F_142 ( struct V_8 * V_206 ,
struct V_22 * V_213 ,
struct V_6 * V_7 ,
T_1 * V_214 )
{
int V_101 ;
T_3 * V_69 = NULL ;
struct V_1 * V_2 ;
F_20 ( ! V_7 ) ;
F_20 ( V_7 -> V_200 != 0 ) ;
F_20 ( V_7 -> V_122 != 1 ) ;
F_20 ( V_7 -> V_10 != V_152 ) ;
V_2 = F_99 ( sizeof( * V_2 ) , V_215 ) ;
if ( V_2 == NULL ) {
V_101 = - V_95 ;
F_39 ( V_101 ) ;
goto V_51;
}
F_140 ( V_206 , V_213 , V_7 ) ;
V_69 = F_65 ( F_17 ( V_206 -> V_52 ) , V_216 ) ;
if ( F_66 ( V_69 ) ) {
V_101 = F_67 ( V_69 ) ;
V_69 = NULL ;
F_39 ( V_101 ) ;
goto V_51;
}
V_7 -> V_193 = 1 ;
V_101 = F_137 ( V_7 , V_69 , 1 , 1 , V_2 ) ;
if ( V_101 < 0 ) {
F_39 ( V_101 ) ;
goto V_51;
}
V_7 -> V_15 = V_2 ;
* V_214 = V_2 -> V_3 ;
F_76 ( V_69 , V_206 , 0 ) ;
V_51:
if ( V_69 )
F_77 ( F_17 ( V_206 -> V_52 ) , V_69 ) ;
if ( V_101 )
F_8 ( V_2 ) ;
return V_101 ;
}
int F_143 ( T_3 * V_69 ,
struct V_8 * V_206 ,
struct V_6 * V_7 ,
T_1 * V_202 ,
T_4 * V_217 ,
T_1 V_218 )
{
int V_101 ;
T_4 V_176 ;
struct V_1 * V_2 = V_7 -> V_15 ;
struct V_22 * V_71 = NULL ;
struct V_25 * V_55 ;
struct V_37 * V_38 = (struct V_37 * ) V_7 -> V_13 -> V_27 ;
F_20 ( V_2 -> V_3 != V_218 ) ;
V_101 = F_26 ( V_7 -> V_9 , V_38 ,
V_2 -> V_192 , & V_71 ) ;
if ( V_101 ) {
F_39 ( V_101 ) ;
goto V_51;
}
V_55 = (struct V_25 * ) V_71 -> V_27 ;
V_176 = F_11 ( V_55 -> V_44 ) ;
V_101 = F_128 ( V_7 -> V_9 , V_69 ,
V_7 -> V_13 , V_2 -> V_169 ,
V_176 ) ;
if ( V_101 ) {
F_39 ( V_101 ) ;
goto V_51;
}
V_101 = F_117 ( V_69 ,
V_7 -> V_9 ,
V_55 ,
V_71 ,
V_2 -> V_5 ,
V_2 -> V_169 ) ;
if ( V_101 < 0 ) {
F_129 ( V_7 -> V_9 ,
V_7 -> V_13 , V_2 -> V_169 , V_176 ) ;
F_39 ( V_101 ) ;
goto V_51;
}
F_144 ( ( unsigned long long ) V_218 ,
V_2 -> V_169 ) ;
F_85 ( & F_17 ( V_7 -> V_9 -> V_52 ) -> V_129 . V_205 ) ;
F_20 ( V_2 -> V_169 != 1 ) ;
* V_202 = V_2 -> V_4 ;
* V_217 = V_2 -> V_5 ;
V_7 -> V_200 ++ ;
F_141 ( V_206 , V_7 ) ;
V_51:
F_7 ( V_71 ) ;
return V_101 ;
}
int F_145 ( T_3 * V_69 ,
struct V_8 * V_206 ,
struct V_22 * V_213 ,
struct V_6 * V_7 ,
T_1 * V_202 ,
T_4 * V_217 ,
T_1 * V_214 )
{
int V_75 ;
struct V_1 V_2 ;
F_20 ( ! V_7 ) ;
F_20 ( V_7 -> V_200 != 0 ) ;
F_20 ( V_7 -> V_122 != 1 ) ;
F_20 ( V_7 -> V_10 != V_152 ) ;
F_140 ( V_206 , V_213 , V_7 ) ;
V_75 = F_137 ( V_7 ,
V_69 ,
1 ,
1 ,
& V_2 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
F_85 ( & F_17 ( V_7 -> V_9 -> V_52 ) -> V_129 . V_205 ) ;
F_20 ( V_2 . V_169 != 1 ) ;
* V_202 = V_2 . V_4 ;
* V_217 = V_2 . V_5 ;
* V_214 = V_2 . V_3 ;
V_7 -> V_200 ++ ;
F_141 ( V_206 , V_7 ) ;
V_75 = 0 ;
V_77:
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
static inline T_2 F_146 ( struct V_8 * V_8 ,
T_1 V_31 ,
T_4 V_219 )
{
struct V_53 * V_54 = F_17 ( V_8 -> V_52 ) ;
T_2 V_220 = 0 ;
F_20 ( ! F_62 ( V_8 ) ) ;
if ( V_31 != V_54 -> V_221 )
V_220 = F_123 ( V_8 -> V_52 , V_31 ) ;
V_220 += ( T_2 ) V_219 ;
return V_220 ;
}
T_1 F_147 ( struct V_8 * V_8 , T_2 V_220 )
{
struct V_53 * V_54 = F_17 ( V_8 -> V_52 ) ;
T_2 V_222 ;
F_20 ( ! F_62 ( V_8 ) ) ;
V_222 = V_220 / V_54 -> V_223 ;
if ( ! V_222 )
return V_54 -> V_221 ;
return F_47 ( V_8 -> V_52 ,
V_222 * V_54 -> V_223 ) ;
}
static inline void F_148 ( struct V_8 * V_8 ,
T_1 V_224 ,
T_1 * V_31 ,
T_4 * V_219 )
{
struct V_53 * V_54 = F_17 ( V_8 -> V_52 ) ;
T_2 V_225 = F_123 ( V_54 -> V_21 , V_224 ) ;
F_20 ( ! F_62 ( V_8 ) ) ;
* V_31 = F_147 ( V_8 ,
V_225 ) ;
if ( * V_31 == V_54 -> V_221 )
* V_219 = ( T_4 ) V_225 ;
else
* V_219 = ( T_4 ) F_123 ( V_54 -> V_21 ,
V_224 - * V_31 ) ;
}
int F_149 ( T_3 * V_69 ,
struct V_6 * V_7 ,
T_2 V_226 ,
T_2 V_227 ,
T_2 * V_228 ,
T_2 * V_229 )
{
int V_75 ;
unsigned int V_121 = V_227 ;
struct V_1 V_2 = { . V_3 = 0 , } ;
struct V_53 * V_54 = F_17 ( V_7 -> V_9 -> V_52 ) ;
F_20 ( V_7 -> V_200 >= V_7 -> V_122 ) ;
F_20 ( V_7 -> V_10 != V_11
&& V_7 -> V_10 != V_157 ) ;
if ( V_7 -> V_10 == V_11 ) {
F_150 ( V_226 > 1 ) ;
V_75 = F_151 ( V_54 ,
V_69 ,
V_7 ,
V_121 ,
V_228 ,
V_229 ) ;
if ( ! V_75 )
F_85 ( & V_54 -> V_129 . V_230 ) ;
} else {
if ( V_226 > ( V_54 -> V_223 - 1 ) ) {
F_23 ( V_48 , L_21
L_22 , V_226 ,
V_54 -> V_223 ) ;
V_75 = - V_94 ;
goto V_77;
}
if ( V_121 > ( V_54 -> V_223 - 1 ) )
V_121 = V_54 -> V_223 - 1 ;
V_75 = F_137 ( V_7 ,
V_69 ,
V_121 ,
V_226 ,
& V_2 ) ;
if ( ! V_75 ) {
F_20 ( V_2 . V_3 ) ;
* V_228 =
F_146 ( V_7 -> V_9 ,
V_2 . V_4 ,
V_2 . V_5 ) ;
F_85 ( & V_54 -> V_129 . V_231 ) ;
* V_229 = V_2 . V_169 ;
}
}
if ( V_75 < 0 ) {
if ( V_75 != - V_94 )
F_39 ( V_75 ) ;
goto V_77;
}
V_7 -> V_200 += * V_229 ;
V_77:
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
int F_46 ( T_3 * V_69 ,
struct V_6 * V_7 ,
T_2 V_226 ,
T_2 * V_228 ,
T_2 * V_229 )
{
unsigned int V_121 = V_7 -> V_122 - V_7 -> V_200 ;
return F_149 ( V_69 , V_7 , V_226 ,
V_121 , V_228 , V_229 ) ;
}
static int F_152 ( T_3 * V_69 ,
struct V_8 * V_70 ,
struct V_25 * V_55 ,
struct V_22 * V_170 ,
unsigned int V_91 ,
unsigned int V_92 ,
void (* F_153)( unsigned int V_232 ,
unsigned long * V_233 ) )
{
int V_75 ;
unsigned int V_50 ;
struct V_25 * V_234 = NULL ;
F_20 ( ! F_13 ( V_55 ) ) ;
F_154 ( V_91 , V_92 ) ;
F_20 ( F_153 && ! F_62 ( V_70 ) ) ;
V_75 = F_38 ( V_69 , F_28 ( V_70 ) ,
V_170 ,
F_153 ?
V_172 :
V_109 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
if ( F_153 ) {
F_112 ( V_170 ) ;
V_234 = (struct V_25 * )
F_113 ( V_170 ) -> V_161 ;
F_20 ( ! V_234 ) ;
}
V_50 = V_92 ;
while( V_50 -- ) {
F_155 ( ( V_91 + V_50 ) ,
( unsigned long * ) V_55 -> V_86 ) ;
if ( F_153 )
F_153 ( V_91 + V_50 ,
( unsigned long * ) V_234 -> V_86 ) ;
}
F_35 ( & V_55 -> V_34 , V_92 ) ;
if ( F_11 ( V_55 -> V_34 ) > F_11 ( V_55 -> V_35 ) ) {
F_37 ( V_70 -> V_52 , L_17
L_18 ,
( unsigned long long ) F_15 ( V_55 -> V_31 ) ,
F_11 ( V_55 -> V_35 ) ,
F_11 ( V_55 -> V_34 ) , V_92 ) ;
return - V_173 ;
}
if ( F_153 )
F_114 ( V_170 ) ;
F_43 ( V_69 , V_170 ) ;
V_77:
return V_75 ;
}
static int F_156 ( T_3 * V_69 ,
struct V_8 * V_70 ,
struct V_22 * V_235 ,
unsigned int V_236 ,
T_1 V_31 ,
unsigned int V_237 ,
void (* F_153)( unsigned int V_232 ,
unsigned long * V_163 ) )
{
int V_75 = 0 ;
T_2 V_187 ;
struct V_37 * V_107 = (struct V_37 * ) V_235 -> V_27 ;
struct V_16 * V_17 = & V_107 -> V_42 . V_43 ;
struct V_22 * V_170 = NULL ;
struct V_25 * V_238 ;
F_20 ( ! F_82 ( V_107 ) ) ;
F_20 ( ( V_237 + V_236 ) > F_10 ( V_17 ) ) ;
F_157 (
( unsigned long long ) F_41 ( V_70 ) -> V_85 ,
( unsigned long long ) V_31 ,
V_236 , V_237 ) ;
V_75 = F_26 ( V_70 , V_107 , V_31 ,
& V_170 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
V_238 = (struct V_25 * ) V_170 -> V_27 ;
F_20 ( ( V_237 + V_236 ) > F_11 ( V_238 -> V_35 ) ) ;
V_75 = F_152 ( V_69 , V_70 ,
V_238 , V_170 ,
V_236 , V_237 , F_153 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_77;
}
V_75 = F_69 ( V_69 , F_28 ( V_70 ) ,
V_235 , V_109 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
F_117 ( V_69 , V_70 , V_238 , V_170 ,
V_236 , V_237 ) ;
goto V_77;
}
F_70 ( & V_17 -> V_83 [ F_11 ( V_238 -> V_44 ) ] . V_110 ,
V_237 ) ;
V_187 = F_16 ( V_107 -> V_111 . V_112 . V_113 ) ;
V_107 -> V_111 . V_112 . V_113 = F_34 ( V_187 - V_237 ) ;
F_43 ( V_69 , V_235 ) ;
V_77:
F_7 ( V_170 ) ;
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
int F_158 ( T_3 * V_69 ,
struct V_8 * V_70 ,
struct V_22 * V_235 ,
unsigned int V_236 ,
T_1 V_31 ,
unsigned int V_237 )
{
return F_156 ( V_69 , V_70 , V_235 ,
V_236 , V_31 , V_237 , NULL ) ;
}
int F_159 ( T_3 * V_69 ,
struct V_8 * V_239 ,
struct V_22 * V_240 ,
struct V_37 * V_38 )
{
T_1 V_241 = F_15 ( V_38 -> V_40 ) ;
T_4 V_232 = F_11 ( V_38 -> V_212 ) ;
T_1 V_31 = F_2 ( V_241 , V_232 ) ;
if ( V_38 -> V_211 )
V_31 = F_15 ( V_38 -> V_211 ) ;
return F_158 ( V_69 , V_239 ,
V_240 , V_232 , V_31 , 1 ) ;
}
static int F_160 ( T_3 * V_69 ,
struct V_8 * V_242 ,
struct V_22 * V_243 ,
T_1 V_244 ,
unsigned int V_229 ,
void (* F_153)( unsigned int V_232 ,
unsigned long * V_163 ) )
{
int V_75 ;
T_4 V_245 ;
T_1 V_31 ;
struct V_37 * V_107 ;
F_20 ( V_244 != F_47 ( V_242 -> V_52 , F_123 ( V_242 -> V_52 , V_244 ) ) ) ;
V_107 = (struct V_37 * ) V_243 -> V_27 ;
F_148 ( V_242 , V_244 , & V_31 ,
& V_245 ) ;
F_161 ( ( unsigned long long ) V_31 ,
( unsigned long long ) V_244 ,
V_245 , V_229 ) ;
V_75 = F_156 ( V_69 , V_242 , V_243 ,
V_245 , V_31 ,
V_229 , F_153 ) ;
if ( V_75 < 0 ) {
F_39 ( V_75 ) ;
goto V_51;
}
F_126 ( F_17 ( V_242 -> V_52 ) ,
V_229 ) ;
V_51:
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
int F_55 ( T_3 * V_69 ,
struct V_8 * V_242 ,
struct V_22 * V_243 ,
T_1 V_244 ,
unsigned int V_229 )
{
return F_160 ( V_69 , V_242 , V_243 ,
V_244 , V_229 ,
V_246 ) ;
}
int F_162 ( T_3 * V_69 ,
struct V_8 * V_242 ,
struct V_22 * V_243 ,
T_1 V_244 ,
unsigned int V_229 )
{
return F_160 ( V_69 , V_242 , V_243 ,
V_244 , V_229 ,
V_247 ) ;
}
static inline void F_163 ( struct V_25 * V_55 )
{
F_164 ( L_23 ) ;
F_164 ( L_24 , V_55 -> V_29 ) ;
F_164 ( L_25 , V_55 -> V_36 ) ;
F_164 ( L_26 , V_55 -> V_35 ) ;
F_164 ( L_27 , V_55 -> V_34 ) ;
F_164 ( L_28 , V_55 -> V_44 ) ;
F_164 ( L_29 , F_16 ( V_55 -> V_32 ) ) ;
F_164 ( L_30 ,
( unsigned long long ) V_55 -> V_82 ) ;
F_164 ( L_31 ,
( unsigned long long ) V_55 -> V_41 ) ;
F_164 ( L_32 ,
( unsigned long long ) V_55 -> V_31 ) ;
}
static inline void F_165 ( struct V_37 * V_107 )
{
int V_100 ;
F_164 ( L_33 , ( unsigned long long ) V_107 -> V_40 ) ;
F_164 ( L_34 , V_107 -> V_248 ) ;
F_164 ( L_35 ,
( unsigned long long ) V_107 -> V_118 ) ;
F_164 ( L_36 , V_107 -> V_115 ) ;
F_164 ( L_37 ,
F_16 ( V_107 -> V_249 ) ) ;
F_164 ( L_38 ,
F_16 ( V_107 -> V_111 . V_112 . V_113 ) ) ;
F_164 ( L_39 ,
F_16 ( V_107 -> V_111 . V_112 . V_114 ) ) ;
F_164 ( L_40 , V_107 -> V_42 . V_43 . V_18 ) ;
F_164 ( L_41 , V_107 -> V_42 . V_43 . V_19 ) ;
F_164 ( L_42 , V_107 -> V_42 . V_43 . V_89 ) ;
F_164 ( L_43 ,
V_107 -> V_42 . V_43 . V_45 ) ;
for( V_100 = 0 ; V_100 < V_107 -> V_42 . V_43 . V_45 ; V_100 ++ ) {
F_164 ( L_44 , V_100 ,
V_107 -> V_42 . V_43 . V_83 [ V_100 ] . V_110 ) ;
F_164 ( L_45 , V_100 ,
V_107 -> V_42 . V_43 . V_83 [ V_100 ] . V_90 ) ;
F_164 ( L_46 , V_100 ,
( unsigned long long ) V_107 -> V_42 . V_43 . V_83 [ V_100 ] . V_84 ) ;
}
}
int F_166 ( struct V_8 * V_8 ,
struct V_250 * V_251 ,
T_2 V_252 , T_2 V_253 ,
struct V_6 * * V_254 ,
struct V_6 * * V_255 )
{
int V_101 = 0 , V_256 ;
unsigned int V_257 = V_252 + 2 * V_253 ;
struct V_53 * V_54 = F_17 ( V_8 -> V_52 ) ;
* V_255 = NULL ;
if ( V_254 )
* V_254 = NULL ;
F_20 ( V_252 != 0 && V_254 == NULL ) ;
V_256 = F_167 ( V_54 , V_251 ) ;
if ( V_256 < 0 ) {
V_101 = V_256 ;
F_39 ( V_101 ) ;
goto V_51;
}
if ( ! V_256 ||
( F_168 ( V_54 ) && V_256 < V_257 ) ) {
V_101 = F_101 ( V_54 , V_251 -> V_258 , V_255 ) ;
if ( V_101 < 0 ) {
if ( V_101 != - V_94 )
F_39 ( V_101 ) ;
goto V_51;
}
}
if ( V_252 == 0 )
goto V_51;
V_101 = F_108 ( V_54 , V_252 , V_254 ) ;
if ( V_101 < 0 ) {
if ( V_101 != - V_94 )
F_39 ( V_101 ) ;
goto V_51;
}
V_51:
if ( V_101 ) {
if ( * V_255 ) {
F_9 ( * V_255 ) ;
* V_255 = NULL ;
}
}
return V_101 ;
}
static int F_169 ( struct V_53 * V_54 , T_1 V_259 ,
T_4 * V_260 , T_1 * V_72 ,
T_4 * V_217 )
{
int V_75 ;
struct V_22 * V_261 = NULL ;
struct V_37 * V_262 ;
F_170 ( ( unsigned long long ) V_259 ) ;
V_75 = F_171 ( V_54 , V_259 , 1 , & V_261 ) ;
if ( V_75 < 0 ) {
F_23 ( V_48 , L_47 ,
( unsigned long long ) V_259 , V_75 ) ;
goto V_77;
}
V_262 = (struct V_37 * ) V_261 -> V_27 ;
if ( ! F_82 ( V_262 ) ) {
F_23 ( V_48 , L_48 ,
( unsigned long long ) V_259 ) ;
V_75 = - V_30 ;
goto V_77;
}
if ( F_11 ( V_262 -> V_210 ) != ( T_4 ) V_133 &&
( T_2 ) F_11 ( V_262 -> V_210 ) > V_54 -> V_140 - 1 ) {
F_23 ( V_48 , L_49 ,
( unsigned long long ) V_259 ,
( T_2 ) F_11 ( V_262 -> V_210 ) ) ;
V_75 = - V_30 ;
goto V_77;
}
if ( V_260 )
* V_260 = F_11 ( V_262 -> V_210 ) ;
if ( V_217 )
* V_217 = F_11 ( V_262 -> V_212 ) ;
if ( V_72 )
* V_72 = F_15 ( V_262 -> V_211 ) ;
V_77:
F_7 ( V_261 ) ;
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
static int F_172 ( struct V_53 * V_54 ,
struct V_8 * V_263 ,
struct V_22 * V_235 ,
T_1 V_72 , T_1 V_259 ,
T_4 V_232 , int * V_2 )
{
struct V_37 * V_264 ;
struct V_25 * V_238 ;
struct V_22 * V_170 = NULL ;
T_1 V_31 ;
int V_75 ;
F_173 ( ( unsigned long long ) V_259 ,
( unsigned int ) V_232 ) ;
V_264 = (struct V_37 * ) V_235 -> V_27 ;
if ( ( V_232 + 1 ) > F_10 ( & V_264 -> V_42 . V_43 ) ) {
F_23 ( V_48 , L_50 ,
( unsigned int ) V_232 ,
F_10 ( & V_264 -> V_42 . V_43 ) ) ;
V_75 = - V_30 ;
goto V_77;
}
V_31 = V_72 ? V_72 :
F_2 ( V_259 , V_232 ) ;
V_75 = F_26 ( V_263 , V_264 , V_31 ,
& V_170 ) ;
if ( V_75 < 0 ) {
F_23 ( V_48 , L_51 ,
( unsigned long long ) V_31 , V_75 ) ;
goto V_77;
}
V_238 = (struct V_25 * ) V_170 -> V_27 ;
* V_2 = F_110 ( V_232 , ( unsigned long * ) V_238 -> V_86 ) ;
V_77:
F_7 ( V_170 ) ;
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
int F_174 ( struct V_53 * V_54 , T_1 V_259 , int * V_2 )
{
int V_75 ;
T_1 V_72 = 0 ;
T_4 V_217 = 0 , V_260 = 0 ;
struct V_8 * V_239 ;
struct V_22 * V_235 = NULL ;
F_175 ( ( unsigned long long ) V_259 ) ;
V_75 = F_169 ( V_54 , V_259 , & V_260 ,
& V_72 , & V_217 ) ;
if ( V_75 < 0 ) {
F_23 ( V_48 , L_52 , V_75 ) ;
goto V_77;
}
V_239 =
F_79 ( V_54 , V_137 ,
V_260 ) ;
if ( ! V_239 ) {
V_75 = - V_30 ;
F_23 ( V_48 , L_53 ,
( T_2 ) V_260 ) ;
goto V_77;
}
F_80 ( & V_239 -> V_12 ) ;
V_75 = F_81 ( V_239 , & V_235 , 0 ) ;
if ( V_75 < 0 ) {
F_5 ( & V_239 -> V_12 ) ;
F_6 ( V_239 ) ;
F_23 ( V_48 , L_54 ,
( T_2 ) V_260 , V_75 ) ;
goto V_77;
}
V_75 = F_172 ( V_54 , V_239 , V_235 ,
V_72 , V_259 , V_217 , V_2 ) ;
if ( V_75 < 0 )
F_23 ( V_48 , L_55 , V_75 ) ;
F_4 ( V_239 , 0 ) ;
F_5 ( & V_239 -> V_12 ) ;
F_6 ( V_239 ) ;
F_7 ( V_235 ) ;
V_77:
if ( V_75 )
F_39 ( V_75 ) ;
return V_75 ;
}
