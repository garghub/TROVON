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
F_5 ( V_8 ) ;
F_6 ( V_8 ) ;
V_7 -> V_9 = NULL ;
}
F_7 ( V_7 -> V_12 ) ;
V_7 -> V_12 = NULL ;
V_7 -> V_13 = NULL ;
F_8 ( V_7 -> V_14 ) ;
V_7 -> V_14 = NULL ;
}
void F_9 ( struct V_6 * V_7 )
{
F_3 ( V_7 ) ;
F_8 ( V_7 ) ;
}
static T_2 F_10 ( struct V_15 * V_16 )
{
return ( T_2 ) F_11 ( V_16 -> V_17 ) * ( T_2 ) F_11 ( V_16 -> V_18 ) ;
}
static int F_12 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
int V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_22 -> V_26 ;
if ( ! F_13 ( V_25 ) ) {
F_14 ( L_1 ,
( unsigned long long ) V_22 -> V_27 , 7 ,
V_25 -> V_28 ) ;
}
if ( F_15 ( V_25 -> V_29 ) != V_22 -> V_27 ) {
F_14 ( L_2 ,
( unsigned long long ) V_22 -> V_27 ,
( unsigned long long ) F_15 ( V_25 -> V_29 ) ) ;
}
if ( F_16 ( V_25 -> V_30 ) != F_17 ( V_20 ) -> V_31 ) {
F_14 ( L_3 ,
( unsigned long long ) V_22 -> V_27 ,
F_16 ( V_25 -> V_30 ) ) ;
}
if ( F_11 ( V_25 -> V_32 ) > F_11 ( V_25 -> V_33 ) ) {
F_14 ( L_4 ,
( unsigned long long ) V_22 -> V_27 ,
F_11 ( V_25 -> V_33 ) ,
F_11 ( V_25 -> V_32 ) ) ;
}
if ( F_11 ( V_25 -> V_33 ) > ( 8 * F_11 ( V_25 -> V_34 ) ) ) {
F_14 ( L_5 ,
( unsigned long long ) V_22 -> V_27 ,
F_11 ( V_25 -> V_33 ) ,
8 * F_11 ( V_25 -> V_34 ) ) ;
}
return 0 ;
}
static int F_18 ( struct V_19 * V_20 ,
struct V_35 * V_36 ,
struct V_21 * V_22 ,
int V_23 )
{
unsigned int V_37 ;
struct V_24 * V_25 = (struct V_24 * ) V_22 -> V_26 ;
if ( V_36 -> V_38 != V_25 -> V_39 ) {
F_14 ( L_6 ,
( unsigned long long ) V_22 -> V_27 ,
( unsigned long long ) F_15 ( V_25 -> V_39 ) ,
( unsigned long long ) F_15 ( V_36 -> V_38 ) ) ;
}
V_37 = F_11 ( V_36 -> V_40 . V_41 . V_17 ) * F_11 ( V_36 -> V_40 . V_41 . V_18 ) ;
if ( F_11 ( V_25 -> V_33 ) > V_37 ) {
F_14 ( L_7 ,
( unsigned long long ) V_22 -> V_27 ,
F_11 ( V_25 -> V_33 ) ) ;
}
if ( ( F_11 ( V_25 -> V_42 ) >
F_11 ( V_36 -> V_40 . V_41 . V_43 ) ) ||
( ( F_11 ( V_25 -> V_42 ) ==
F_11 ( V_36 -> V_40 . V_41 . V_43 ) ) && ! V_23 ) ) {
F_14 ( L_8 ,
( unsigned long long ) V_22 -> V_27 ,
F_11 ( V_25 -> V_42 ) ) ;
}
return 0 ;
}
int F_19 ( struct V_19 * V_20 ,
struct V_35 * V_36 ,
struct V_21 * V_22 )
{
int V_44 ;
struct V_24 * V_25 = (struct V_24 * ) V_22 -> V_26 ;
F_20 ( ! F_21 ( V_22 ) ) ;
V_44 = F_22 ( V_20 , V_22 -> V_26 , & V_25 -> V_45 ) ;
if ( V_44 ) {
F_23 ( V_46 ,
L_9 ,
( unsigned long long ) V_22 -> V_27 ) ;
} else
V_44 = F_12 ( V_20 , V_22 , 1 ) ;
if ( ! V_44 )
V_44 = F_18 ( V_20 , V_36 , V_22 , 1 ) ;
return V_44 ;
}
static int F_24 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
int V_44 ;
struct V_24 * V_25 = (struct V_24 * ) V_22 -> V_26 ;
F_25 (
( unsigned long long ) V_22 -> V_27 ) ;
F_20 ( ! F_21 ( V_22 ) ) ;
V_44 = F_22 ( V_20 , V_22 -> V_26 , & V_25 -> V_45 ) ;
if ( V_44 )
return V_44 ;
return F_12 ( V_20 , V_22 , 0 ) ;
}
int F_26 ( struct V_8 * V_8 , struct V_35 * V_36 ,
T_1 V_47 , struct V_21 * * V_22 )
{
int V_44 ;
struct V_21 * V_48 = * V_22 ;
V_44 = F_27 ( F_28 ( V_8 ) , V_47 , & V_48 ,
F_24 ) ;
if ( V_44 )
goto V_49;
V_44 = F_18 ( V_8 -> V_50 , V_36 , V_48 , 0 ) ;
if ( V_44 ) {
F_7 ( V_48 ) ;
goto V_49;
}
if ( ! * V_22 )
* V_22 = V_48 ;
V_49:
return V_44 ;
}
static void F_29 ( struct V_51 * V_52 ,
struct V_24 * V_53 ,
struct V_15 * V_16 ,
T_1 V_54 , unsigned int V_55 )
{
struct V_56 * V_57 = & V_53 -> V_58 ;
struct V_59 * V_60 ;
F_20 ( ! F_30 ( V_52 ) ) ;
if ( ! V_57 -> V_61 )
V_57 -> V_62 = F_31 ( F_32 ( V_52 -> V_20 ) ) ;
V_60 = & V_57 -> V_63 [ F_11 ( V_57 -> V_61 ) ] ;
V_60 -> V_64 = F_33 ( V_54 ) ;
V_60 -> V_65 = F_34 ( F_11 ( V_53 -> V_33 ) /
F_11 ( V_16 -> V_18 ) ) ;
V_60 -> V_66 = F_31 ( V_55 ) ;
F_35 ( & V_53 -> V_33 , V_55 * F_11 ( V_16 -> V_18 ) ) ;
F_35 ( & V_53 -> V_32 ,
V_55 * F_11 ( V_16 -> V_18 ) ) ;
F_35 ( & V_57 -> V_61 , 1 ) ;
}
static int F_36 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_21 * V_69 ,
T_1 V_70 ,
unsigned int V_71 ,
T_4 V_72 ,
struct V_15 * V_16 )
{
int V_73 = 0 ;
struct V_51 * V_52 = F_17 ( V_68 -> V_50 ) ;
struct V_24 * V_53 = (struct V_24 * ) V_69 -> V_26 ;
struct V_19 * V_20 = V_68 -> V_50 ;
if ( ( ( unsigned long long ) V_69 -> V_27 ) != V_70 ) {
V_73 = F_37 ( V_68 -> V_50 ,
L_10 ,
( unsigned long long ) V_70 ,
( unsigned long long ) V_69 -> V_27 ) ;
goto V_74;
}
V_73 = F_38 ( V_67 ,
F_28 ( V_68 ) ,
V_69 ,
V_75 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
memset ( V_53 , 0 , V_20 -> V_76 ) ;
strcpy ( V_53 -> V_28 , V_77 ) ;
V_53 -> V_30 = F_34 ( F_17 ( V_20 ) -> V_31 ) ;
V_53 -> V_34 = F_31 ( F_40 ( V_20 , 1 ,
V_52 -> V_78 ) ) ;
V_53 -> V_42 = F_31 ( V_72 ) ;
V_53 -> V_79 = V_16 -> V_80 [ V_72 ] . V_81 ;
V_53 -> V_39 = F_33 ( F_41 ( V_68 ) -> V_82 ) ;
V_53 -> V_29 = F_33 ( V_70 ) ;
if ( V_71 == F_11 ( V_16 -> V_17 ) )
V_53 -> V_33 = F_31 ( F_10 ( V_16 ) ) ;
else
F_29 ( V_52 , V_53 , V_16 , V_70 ,
V_71 ) ;
F_42 ( 0 , ( unsigned long * ) V_53 -> V_83 ) ;
V_53 -> V_32 = F_31 ( F_11 ( V_53 -> V_33 ) - 1 ) ;
F_43 ( V_67 , V_69 ) ;
V_74:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
static inline T_4 F_44 ( struct V_15 * V_16 )
{
T_4 V_84 , V_85 ;
V_85 = V_84 = 0 ;
while ( V_84 < F_11 ( V_16 -> V_86 ) ) {
if ( F_16 ( V_16 -> V_80 [ V_85 ] . V_87 ) >
F_16 ( V_16 -> V_80 [ V_84 ] . V_87 ) )
V_85 = V_84 ;
V_84 ++ ;
}
return V_85 ;
}
static struct V_21 *
F_45 ( struct V_51 * V_52 , T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_6 * V_7 ,
struct V_15 * V_16 )
{
int V_73 ;
T_2 V_88 , V_89 ;
T_1 V_29 ;
struct V_21 * V_69 ;
unsigned int V_90 = F_44 ( V_16 ) ;
V_73 = F_46 ( V_67 , V_7 ,
F_11 ( V_16 -> V_17 ) , & V_88 ,
& V_89 ) ;
if ( V_73 < 0 ) {
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
V_29 = F_47 ( V_52 -> V_20 , V_88 ) ;
F_48 (
( unsigned long long ) V_29 , V_90 ) ;
V_69 = F_49 ( V_52 -> V_20 , V_29 ) ;
if ( ! V_69 ) {
V_73 = - V_92 ;
F_39 ( V_73 ) ;
goto V_74;
}
F_50 ( F_28 ( V_68 ) , V_69 ) ;
V_73 = F_36 ( V_67 , V_68 , V_69 ,
V_29 , V_89 , V_90 , V_16 ) ;
if ( V_73 < 0 ) {
F_7 ( V_69 ) ;
F_39 ( V_73 ) ;
}
V_74:
return V_73 ? F_51 ( V_73 ) : V_69 ;
}
static int F_52 ( struct V_51 * V_52 ,
T_3 * V_67 ,
struct V_6 * V_7 ,
unsigned int V_93 ,
T_2 * V_88 , T_2 * V_89 )
{
int V_73 = 0 ;
while ( V_93 ) {
V_73 = F_46 ( V_67 , V_7 , V_93 ,
V_88 , V_89 ) ;
if ( V_73 != - V_91 )
break;
V_93 >>= 1 ;
}
return V_73 ;
}
static int F_53 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_21 * V_69 ,
struct V_6 * V_7 ,
struct V_15 * V_16 ,
unsigned int V_93 )
{
int V_73 ;
struct V_51 * V_52 = F_17 ( V_68 -> V_50 ) ;
struct V_24 * V_53 =
(struct V_24 * ) V_69 -> V_26 ;
unsigned int V_94 = F_11 ( V_16 -> V_17 ) -
F_11 ( V_53 -> V_33 ) / F_11 ( V_16 -> V_18 ) ;
T_2 V_95 , V_55 ;
T_1 V_54 ;
struct V_56 * V_57 = & V_53 -> V_58 ;
V_73 = F_38 ( V_67 ,
F_28 ( V_68 ) ,
V_69 ,
V_75 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
while ( ( V_94 > 0 ) && ( F_11 ( V_57 -> V_61 ) <
F_11 ( V_57 -> V_62 ) ) ) {
if ( V_93 > V_94 )
V_93 = V_94 ;
V_73 = F_52 ( V_52 , V_67 , V_7 ,
V_93 , & V_95 ,
& V_55 ) ;
if ( V_73 < 0 ) {
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
V_54 = F_47 ( V_52 -> V_20 , V_95 ) ;
F_29 ( V_52 , V_53 , V_16 , V_54 ,
V_55 ) ;
V_93 = V_55 ;
V_94 = F_11 ( V_16 -> V_17 ) -
F_11 ( V_53 -> V_33 ) / F_11 ( V_16 -> V_18 ) ;
}
if ( V_94 > 0 ) {
V_73 = - V_91 ;
goto V_74;
}
F_43 ( V_67 , V_69 ) ;
V_74:
return V_73 ;
}
static void F_54 ( T_3 * V_67 ,
struct V_6 * V_96 ,
struct V_8 * V_68 ,
struct V_21 * V_69 )
{
int V_97 , V_98 ;
struct V_24 * V_53 ;
struct V_56 * V_57 ;
struct V_59 * V_60 ;
if ( ! V_69 )
return;
V_53 = (struct V_24 * ) V_69 -> V_26 ;
V_57 = & V_53 -> V_58 ;
for ( V_97 = 0 ; V_97 < F_11 ( V_57 -> V_61 ) ; V_97 ++ ) {
V_60 = & V_57 -> V_63 [ V_97 ] ;
V_98 = F_55 ( V_67 , V_96 -> V_9 ,
V_96 -> V_12 ,
F_15 ( V_60 -> V_64 ) ,
F_11 ( V_60 -> V_66 ) ) ;
if ( V_98 )
F_39 ( V_98 ) ;
}
F_56 ( F_28 ( V_68 ) , V_69 ) ;
F_7 ( V_69 ) ;
}
static struct V_21 *
F_57 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_6 * V_7 ,
struct V_15 * V_16 )
{
int V_73 ;
T_2 V_88 , V_89 ;
T_1 V_29 ;
unsigned int V_93 = F_11 ( V_16 -> V_17 ) >> 1 ;
struct V_21 * V_69 = NULL ;
unsigned int V_90 = F_44 ( V_16 ) ;
struct V_51 * V_52 = F_17 ( V_68 -> V_50 ) ;
if ( ! F_30 ( V_52 ) ) {
V_73 = - V_91 ;
goto V_74;
}
V_73 = F_58 ( V_67 ,
F_59 ( V_52 -> V_20 ) ) ;
if ( V_73 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_7 -> V_99 = 1 ;
V_73 = F_52 ( V_52 , V_67 , V_7 , V_93 ,
& V_88 , & V_89 ) ;
if ( V_73 < 0 ) {
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
V_93 = V_89 ;
V_29 = F_47 ( V_52 -> V_20 , V_88 ) ;
F_60 (
( unsigned long long ) V_29 , V_90 ) ;
V_69 = F_49 ( V_52 -> V_20 , V_29 ) ;
if ( ! V_69 ) {
V_73 = - V_92 ;
F_39 ( V_73 ) ;
goto V_74;
}
F_50 ( F_28 ( V_68 ) , V_69 ) ;
V_73 = F_36 ( V_67 , V_68 , V_69 ,
V_29 , V_89 , V_90 , V_16 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_73 = F_53 ( V_67 , V_68 ,
V_69 , V_7 , V_16 , V_93 ) ;
if ( V_73 )
F_39 ( V_73 ) ;
V_74:
if ( V_73 )
F_54 ( V_67 , V_7 , V_68 , V_69 ) ;
return V_73 ? F_51 ( V_73 ) : V_69 ;
}
static int F_61 ( struct V_51 * V_52 ,
struct V_8 * V_68 ,
struct V_21 * V_22 ,
T_1 V_100 ,
T_1 * V_101 ,
int V_102 )
{
int V_73 , V_103 ;
struct V_35 * V_104 = (struct V_35 * ) V_22 -> V_26 ;
struct V_15 * V_16 ;
struct V_6 * V_7 = NULL ;
T_3 * V_67 = NULL ;
T_4 V_90 ;
struct V_21 * V_69 = NULL ;
struct V_24 * V_53 ;
F_20 ( F_62 ( V_68 ) ) ;
V_16 = & V_104 -> V_40 . V_41 ;
V_73 = F_63 ( V_52 ,
F_11 ( V_16 -> V_17 ) ,
V_100 , V_102 , & V_7 ) ;
if ( V_73 < 0 ) {
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
V_103 = F_64 ( V_52 -> V_20 ,
F_11 ( V_16 -> V_17 ) ) ;
V_67 = F_65 ( V_52 , V_103 ) ;
if ( F_66 ( V_67 ) ) {
V_73 = F_67 ( V_67 ) ;
V_67 = NULL ;
F_39 ( V_73 ) ;
goto V_74;
}
if ( V_101 && * V_101 != 0 ) {
F_68 (
( unsigned long long ) * V_101 ) ;
V_7 -> V_105 = * V_101 ;
}
V_69 = F_45 ( V_52 , V_67 , V_68 ,
V_7 , V_16 ) ;
if ( F_66 ( V_69 ) && ( F_67 ( V_69 ) == - V_91 ) )
V_69 = F_57 ( V_67 ,
V_68 ,
V_7 , V_16 ) ;
if ( F_66 ( V_69 ) ) {
V_73 = F_67 ( V_69 ) ;
V_69 = NULL ;
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
V_53 = (struct V_24 * ) V_69 -> V_26 ;
V_73 = F_69 ( V_67 , F_28 ( V_68 ) ,
V_22 , V_106 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_90 = F_11 ( V_53 -> V_42 ) ;
F_70 ( & V_16 -> V_80 [ V_90 ] . V_107 ,
F_11 ( V_53 -> V_32 ) ) ;
F_70 ( & V_16 -> V_80 [ V_90 ] . V_87 ,
F_11 ( V_53 -> V_33 ) ) ;
V_16 -> V_80 [ V_90 ] . V_81 = V_53 -> V_29 ;
if ( F_11 ( V_16 -> V_43 ) < F_11 ( V_16 -> V_86 ) )
F_35 ( & V_16 -> V_43 , 1 ) ;
F_70 ( & V_104 -> V_108 . V_109 . V_110 , F_11 ( V_53 -> V_33 ) -
F_11 ( V_53 -> V_32 ) ) ;
F_70 ( & V_104 -> V_108 . V_109 . V_111 , F_11 ( V_53 -> V_33 ) ) ;
F_70 ( & V_104 -> V_112 , F_11 ( V_16 -> V_17 ) ) ;
F_43 ( V_67 , V_22 ) ;
F_71 ( & F_41 ( V_68 ) -> V_113 ) ;
F_41 ( V_68 ) -> V_114 = F_16 ( V_104 -> V_112 ) ;
V_104 -> V_115 = F_33 ( F_72 ( V_68 -> V_50 ,
F_16 ( V_104 -> V_112 ) ) ) ;
F_73 ( & F_41 ( V_68 ) -> V_113 ) ;
F_74 ( V_68 , F_15 ( V_104 -> V_115 ) ) ;
V_68 -> V_116 = F_75 ( V_68 ) ;
F_76 ( V_67 , V_68 , 0 ) ;
V_73 = 0 ;
if ( V_101 )
* V_101 = V_7 -> V_105 ;
V_74:
if ( V_67 )
F_77 ( V_52 , V_67 ) ;
if ( V_7 )
F_9 ( V_7 ) ;
F_7 ( V_69 ) ;
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
static int F_78 ( struct V_51 * V_52 ,
struct V_6 * V_7 ,
int type ,
T_2 V_117 ,
T_1 * V_101 ,
int V_102 )
{
int V_73 ;
T_2 V_118 = V_7 -> V_119 ;
struct V_8 * V_68 ;
struct V_21 * V_22 = NULL ;
struct V_35 * V_104 ;
T_2 V_120 ;
V_68 = F_79 ( V_52 , type , V_117 ) ;
if ( ! V_68 ) {
F_39 ( - V_121 ) ;
return - V_121 ;
}
F_80 ( V_68 ) ;
V_73 = F_81 ( V_68 , & V_22 , 1 ) ;
if ( V_73 < 0 ) {
F_5 ( V_68 ) ;
F_6 ( V_68 ) ;
F_39 ( V_73 ) ;
return V_73 ;
}
V_7 -> V_9 = V_68 ;
V_7 -> V_122 = V_117 ;
V_104 = (struct V_35 * ) V_22 -> V_26 ;
F_20 ( ! F_82 ( V_104 ) ) ;
if ( ! ( V_104 -> V_123 & F_34 ( V_124 ) ) ) {
V_73 = F_37 ( V_68 -> V_50 ,
L_11 ,
( unsigned long long ) F_15 ( V_104 -> V_38 ) ) ;
goto V_74;
}
V_120 = F_16 ( V_104 -> V_108 . V_109 . V_111 ) -
F_16 ( V_104 -> V_108 . V_109 . V_110 ) ;
if ( V_118 > V_120 ) {
if ( F_62 ( V_68 ) ) {
F_83 ( V_118 ,
V_120 ) ;
V_73 = - V_91 ;
goto V_74;
}
if ( ! ( V_102 & V_125 ) ) {
F_84 (
V_117 , V_118 , V_120 ) ;
V_73 = - V_91 ;
goto V_74;
}
V_73 = F_61 ( V_52 , V_68 , V_22 ,
V_7 -> V_126 ,
V_101 , V_102 ) ;
if ( V_73 < 0 ) {
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
F_85 ( & V_52 -> V_127 . V_128 ) ;
F_20 ( V_118 >
( F_16 ( V_104 -> V_108 . V_109 . V_111 )
- F_16 ( V_104 -> V_108 . V_109 . V_110 ) ) ) ;
}
F_86 ( V_22 ) ;
V_7 -> V_12 = V_22 ;
V_74:
F_7 ( V_22 ) ;
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
static void F_87 ( struct V_51 * V_52 )
{
F_71 ( & V_52 -> V_129 ) ;
V_52 -> V_130 = V_131 ;
F_73 ( & V_52 -> V_129 ) ;
F_88 ( & V_52 -> V_132 , 0 ) ;
}
static void F_89 ( struct V_51 * V_52 )
{
F_71 ( & V_52 -> V_129 ) ;
V_52 -> V_133 = V_131 ;
F_73 ( & V_52 -> V_129 ) ;
F_88 ( & V_52 -> V_134 , 0 ) ;
}
void F_90 ( struct V_51 * V_52 )
{
F_87 ( V_52 ) ;
F_89 ( V_52 ) ;
}
static void F_91 ( struct V_51 * V_52 , int V_117 , int type )
{
F_71 ( & V_52 -> V_129 ) ;
if ( type == V_135 )
V_52 -> V_130 = V_117 ;
else if ( type == V_136 )
V_52 -> V_133 = V_117 ;
F_73 ( & V_52 -> V_129 ) ;
}
static int F_92 ( struct V_51 * V_52 , int type )
{
int V_117 = V_131 ;
F_71 ( & V_52 -> V_129 ) ;
if ( type == V_135 )
V_117 = V_52 -> V_130 ;
else if ( type == V_136 )
V_117 = V_52 -> V_133 ;
F_73 ( & V_52 -> V_129 ) ;
return V_117 ;
}
static int F_93 ( struct V_51 * V_52 )
{
return F_92 ( V_52 , V_135 ) ;
}
static int F_94 ( struct V_51 * V_52 )
{
return F_92 ( V_52 , V_136 ) ;
}
static int F_95 ( struct V_51 * V_52 ,
struct V_6 * V_7 ,
int type )
{
int V_97 , V_73 = - V_91 ;
int V_117 = F_92 ( V_52 , type ) ;
if ( V_117 == V_131 )
V_117 = V_52 -> V_137 + 1 ;
for ( V_97 = 0 ; V_97 < V_52 -> V_138 ; V_97 ++ , V_117 ++ ) {
if ( V_117 == V_52 -> V_138 )
V_117 = 0 ;
if ( V_117 == V_52 -> V_137 )
continue;
V_73 = F_78 ( V_52 , V_7 ,
type ,
( T_2 ) V_117 , NULL ,
V_139 ) ;
if ( V_73 >= 0 ) {
F_91 ( V_52 , V_117 , type ) ;
break;
}
F_3 ( V_7 ) ;
}
return V_73 ;
}
static int F_96 ( struct V_51 * V_52 ,
struct V_6 * V_7 )
{
return F_95 ( V_52 , V_7 , V_135 ) ;
}
static int F_97 ( struct V_51 * V_52 ,
struct V_6 * V_7 )
{
return F_95 ( V_52 , V_7 , V_136 ) ;
}
int F_98 ( struct V_51 * V_52 ,
int V_140 ,
struct V_6 * * V_7 )
{
int V_73 ;
int V_117 = F_94 ( V_52 ) ;
* V_7 = F_99 ( sizeof( struct V_6 ) , V_141 ) ;
if ( ! ( * V_7 ) ) {
V_73 = - V_92 ;
F_39 ( V_73 ) ;
goto V_74;
}
( * V_7 ) -> V_119 = V_140 ;
( * V_7 ) -> V_10 = V_142 ;
( * V_7 ) -> V_143 = V_144 ;
if ( V_117 != V_131 &&
F_100 ( & V_52 -> V_134 ) < V_145 )
goto V_146;
F_88 ( & V_52 -> V_134 , 0 ) ;
V_73 = F_78 ( V_52 , ( * V_7 ) ,
V_136 ,
( T_2 ) V_52 -> V_137 , NULL ,
V_147 | V_125 ) ;
if ( V_73 >= 0 ) {
V_73 = 0 ;
if ( V_117 != V_131 )
F_89 ( V_52 ) ;
goto V_74;
} else if ( V_73 < 0 && V_73 != - V_91 ) {
F_39 ( V_73 ) ;
goto V_74;
}
F_3 ( * V_7 ) ;
V_146:
V_73 = F_97 ( V_52 , * V_7 ) ;
F_85 ( & V_52 -> V_134 ) ;
if ( V_73 < 0 ) {
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
V_73 = 0 ;
V_74:
if ( ( V_73 < 0 ) && * V_7 ) {
F_9 ( * V_7 ) ;
* V_7 = NULL ;
}
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_101 ( struct V_51 * V_52 ,
struct V_56 * V_148 ,
struct V_6 * * V_7 )
{
return F_98 ( V_52 ,
F_102 ( V_148 ) ,
V_7 ) ;
}
int F_103 ( struct V_51 * V_52 ,
struct V_6 * * V_7 )
{
int V_73 ;
int V_117 = F_93 ( V_52 ) ;
T_1 V_149 ;
* V_7 = F_99 ( sizeof( struct V_6 ) , V_141 ) ;
if ( ! ( * V_7 ) ) {
V_73 = - V_92 ;
F_39 ( V_73 ) ;
goto V_74;
}
( * V_7 ) -> V_119 = 1 ;
( * V_7 ) -> V_10 = V_150 ;
( * V_7 ) -> V_143 = V_144 ;
if ( ! ( V_52 -> V_151 & V_152 ) )
( * V_7 ) -> V_126 = ( T_2 ) ~ 0U ;
if ( V_117 != V_131 &&
F_100 ( & V_52 -> V_132 ) < V_145 )
goto V_153;
F_88 ( & V_52 -> V_132 , 0 ) ;
V_149 = V_52 -> V_154 ;
V_73 = F_78 ( V_52 , * V_7 ,
V_135 ,
( T_2 ) V_52 -> V_137 ,
& V_149 ,
V_125 |
V_147 ) ;
if ( V_73 >= 0 ) {
V_73 = 0 ;
F_71 ( & V_52 -> V_129 ) ;
V_52 -> V_154 = V_149 ;
F_73 ( & V_52 -> V_129 ) ;
F_104 (
( unsigned long long ) V_149 ) ;
if ( V_117 != V_131 )
F_87 ( V_52 ) ;
goto V_74;
} else if ( V_73 < 0 && V_73 != - V_91 ) {
F_39 ( V_73 ) ;
goto V_74;
}
F_3 ( * V_7 ) ;
V_153:
V_73 = F_96 ( V_52 , * V_7 ) ;
F_85 ( & V_52 -> V_132 ) ;
if ( V_73 < 0 ) {
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
V_73 = 0 ;
V_74:
if ( ( V_73 < 0 ) && * V_7 ) {
F_9 ( * V_7 ) ;
* V_7 = NULL ;
}
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_105 ( struct V_51 * V_52 ,
struct V_6 * V_7 )
{
int V_73 ;
V_7 -> V_10 = V_155 ;
V_7 -> V_143 = V_156 ;
V_73 = F_78 ( V_52 , V_7 ,
V_157 ,
V_131 , NULL ,
V_125 ) ;
if ( V_73 < 0 && V_73 != - V_91 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_74:
return V_73 ;
}
static int F_63 ( struct V_51 * V_52 ,
T_2 V_118 , T_1 V_100 ,
int V_102 ,
struct V_6 * * V_7 )
{
int V_73 , V_98 = 0 ;
int V_158 = 0 ;
* V_7 = F_99 ( sizeof( struct V_6 ) , V_141 ) ;
if ( ! ( * V_7 ) ) {
V_73 = - V_92 ;
F_39 ( V_73 ) ;
goto V_74;
}
( * V_7 ) -> V_119 = V_118 ;
( * V_7 ) -> V_126 = V_100 ;
V_73 = - V_91 ;
if ( ! ( V_102 & V_147 ) &&
F_106 ( V_52 , V_118 ) ) {
V_73 = F_107 ( V_52 ,
V_118 ,
* V_7 ) ;
if ( ( V_73 < 0 ) && ( V_73 != - V_91 ) ) {
F_39 ( V_73 ) ;
goto V_74;
}
}
if ( V_73 == - V_91 ) {
V_159:
V_73 = F_105 ( V_52 , * V_7 ) ;
if ( V_73 == - V_91 && ! V_158 ) {
V_158 = 1 ;
F_4 ( ( * V_7 ) -> V_9 , 1 ) ;
F_5 ( ( * V_7 ) -> V_9 ) ;
V_98 = F_108 ( V_52 , V_118 ) ;
if ( V_98 == 1 ) {
F_6 ( ( * V_7 ) -> V_9 ) ;
( * V_7 ) -> V_9 = NULL ;
goto V_159;
}
if ( V_98 < 0 )
F_39 ( V_98 ) ;
F_80 ( ( * V_7 ) -> V_9 ) ;
V_98 = F_81 ( ( * V_7 ) -> V_9 , NULL , 1 ) ;
if ( V_98 < 0 ) {
F_39 ( V_98 ) ;
F_5 ( ( * V_7 ) -> V_9 ) ;
F_6 ( ( * V_7 ) -> V_9 ) ;
( * V_7 ) -> V_9 = NULL ;
goto V_74;
}
}
if ( V_73 < 0 ) {
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
}
V_73 = 0 ;
V_74:
if ( ( V_73 < 0 ) && * V_7 ) {
F_9 ( * V_7 ) ;
* V_7 = NULL ;
}
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_109 ( struct V_51 * V_52 ,
T_2 V_118 ,
struct V_6 * * V_7 )
{
return F_63 ( V_52 , V_118 , 0 ,
V_125 , V_7 ) ;
}
static int F_110 ( struct V_21 * V_69 ,
int V_160 )
{
struct V_24 * V_53 = (struct V_24 * ) V_69 -> V_26 ;
int V_98 ;
if ( F_111 ( V_160 , ( unsigned long * ) V_53 -> V_83 ) )
return 0 ;
if ( ! F_112 ( V_69 ) )
return 1 ;
F_113 ( V_69 ) ;
V_53 = (struct V_24 * ) F_114 ( V_69 ) -> V_161 ;
if ( V_53 )
V_98 = ! F_111 ( V_160 , ( unsigned long * ) V_53 -> V_83 ) ;
else
V_98 = 1 ;
F_115 ( V_69 ) ;
return V_98 ;
}
static int F_116 ( struct V_51 * V_52 ,
struct V_21 * V_69 ,
unsigned int V_118 ,
unsigned int V_162 ,
struct V_1 * V_2 )
{
void * V_163 ;
T_4 V_164 , V_165 ;
int V_166 , V_167 , V_168 , V_73 = 0 ;
struct V_24 * V_53 = (struct V_24 * ) V_69 -> V_26 ;
F_20 ( ! F_13 ( V_53 ) ) ;
V_168 = V_167 = V_164 = V_165 = 0 ;
V_163 = V_53 -> V_83 ;
while( ( V_166 = F_117 ( V_163 , V_162 , V_167 ) ) != - 1 ) {
if ( V_166 == V_162 )
break;
if ( ! F_110 ( V_69 , V_166 ) ) {
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
if ( V_168 == V_118 ) {
break;
}
}
if ( V_165 ) {
V_2 -> V_5 = V_164 ;
V_2 -> V_169 = V_165 ;
} else {
V_73 = - V_91 ;
}
return V_73 ;
}
int F_118 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_24 * V_53 ,
struct V_21 * V_170 ,
unsigned int V_88 ,
unsigned int V_89 )
{
int V_73 ;
void * V_163 = V_53 -> V_83 ;
int V_171 = V_106 ;
F_20 ( ! F_13 ( V_53 ) ) ;
F_20 ( F_11 ( V_53 -> V_32 ) < V_89 ) ;
F_119 ( V_88 , V_89 ) ;
if ( F_62 ( V_68 ) )
V_171 = V_172 ;
V_73 = F_38 ( V_67 ,
F_28 ( V_68 ) ,
V_170 ,
V_171 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
F_35 ( & V_53 -> V_32 , - V_89 ) ;
if ( F_11 ( V_53 -> V_32 ) > F_11 ( V_53 -> V_33 ) ) {
return F_37 ( V_68 -> V_50 , L_12 ,
( unsigned long long ) F_15 ( V_53 -> V_29 ) ,
F_11 ( V_53 -> V_33 ) ,
F_11 ( V_53 -> V_32 ) ,
V_89 ) ;
}
while( V_89 -- )
F_42 ( V_88 ++ , V_163 ) ;
F_43 ( V_67 , V_170 ) ;
V_74:
return V_73 ;
}
static inline T_4 F_120 ( struct V_15 * V_16 )
{
T_4 V_84 , V_85 ;
F_20 ( ! V_16 -> V_43 ) ;
V_85 = V_84 = 0 ;
while ( V_84 < F_11 ( V_16 -> V_43 ) ) {
if ( F_16 ( V_16 -> V_80 [ V_84 ] . V_107 ) >
F_16 ( V_16 -> V_80 [ V_85 ] . V_107 ) )
V_85 = V_84 ;
V_84 ++ ;
}
F_20 ( V_85 >= F_11 ( V_16 -> V_43 ) ) ;
return V_85 ;
}
static int F_121 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_21 * V_173 ,
struct V_21 * V_69 ,
struct V_21 * V_174 ,
T_4 V_175 )
{
int V_73 ;
T_1 V_176 , V_177 ;
struct V_35 * V_104 = (struct V_35 * ) V_173 -> V_26 ;
struct V_24 * V_53 = (struct V_24 * ) V_69 -> V_26 ;
struct V_24 * V_178 = (struct V_24 * ) V_174 -> V_26 ;
F_20 ( ! F_13 ( V_53 ) ) ;
F_20 ( ! F_13 ( V_178 ) ) ;
F_122 (
( unsigned long long ) F_15 ( V_104 -> V_38 ) , V_175 ,
( unsigned long long ) F_15 ( V_53 -> V_29 ) ,
( unsigned long long ) F_15 ( V_178 -> V_29 ) ) ;
V_176 = F_15 ( V_53 -> V_79 ) ;
V_177 = F_15 ( V_178 -> V_79 ) ;
V_73 = F_38 ( V_67 , F_28 ( V_68 ) ,
V_174 ,
V_106 ) ;
if ( V_73 < 0 )
goto V_49;
V_178 -> V_79 = V_53 -> V_79 ;
F_43 ( V_67 , V_174 ) ;
V_73 = F_38 ( V_67 , F_28 ( V_68 ) ,
V_69 , V_106 ) ;
if ( V_73 < 0 )
goto V_179;
V_53 -> V_79 = V_104 -> V_40 . V_41 . V_80 [ V_175 ] . V_81 ;
F_43 ( V_67 , V_69 ) ;
V_73 = F_69 ( V_67 , F_28 ( V_68 ) ,
V_173 , V_106 ) ;
if ( V_73 < 0 )
goto V_180;
V_104 -> V_40 . V_41 . V_80 [ V_175 ] . V_81 = V_53 -> V_29 ;
F_43 ( V_67 , V_173 ) ;
V_49:
if ( V_73 < 0 )
F_39 ( V_73 ) ;
return V_73 ;
V_180:
V_53 -> V_79 = F_33 ( V_176 ) ;
V_179:
V_178 -> V_79 = F_33 ( V_177 ) ;
goto V_49;
}
static inline int F_123 ( struct V_24 * V_53 ,
T_2 V_181 )
{
return F_11 ( V_53 -> V_32 ) > V_181 ;
}
static int V_156 ( struct V_8 * V_8 ,
struct V_21 * V_170 ,
T_2 V_118 , T_2 V_93 ,
T_1 V_100 ,
struct V_1 * V_2 )
{
int V_182 = - V_91 ;
int V_98 ;
T_1 V_183 ;
struct V_24 * V_25 = (struct V_24 * ) V_170 -> V_26 ;
struct V_51 * V_52 = F_17 ( V_8 -> V_50 ) ;
unsigned int V_37 , V_184 ;
F_20 ( ! F_62 ( V_8 ) ) ;
if ( V_25 -> V_32 ) {
V_37 = F_11 ( V_25 -> V_33 ) ;
V_184 = F_124 ( V_8 -> V_50 ,
F_15 ( V_25 -> V_29 ) ) ;
if ( ( V_184 + V_37 ) >
F_41 ( V_8 ) -> V_114 ) {
V_37 = F_41 ( V_8 ) -> V_114 - V_184 ;
F_125 (
( unsigned long long ) F_15 ( V_25 -> V_29 ) ,
F_11 ( V_25 -> V_33 ) ,
F_41 ( V_8 ) -> V_114 , V_37 ) ;
}
V_98 = F_116 ( F_17 ( V_8 -> V_50 ) ,
V_170 , V_118 ,
V_37 , V_2 ) ;
if ( V_98 )
return V_98 ;
if ( V_100 ) {
V_183 = F_47 ( V_8 -> V_50 ,
V_184 +
V_2 -> V_5 +
V_2 -> V_169 ) ;
F_126 (
( unsigned long long ) V_183 ,
( unsigned long long ) V_100 ) ;
if ( V_183 > V_100 )
return - V_91 ;
}
if ( V_93 <= V_2 -> V_169 )
V_182 = 0 ;
else if ( V_2 -> V_169 ) {
F_127 ( V_52 , V_2 -> V_169 ) ;
}
}
return V_182 ;
}
static int V_144 ( struct V_8 * V_8 ,
struct V_21 * V_170 ,
T_2 V_118 , T_2 V_93 ,
T_1 V_100 ,
struct V_1 * V_2 )
{
int V_98 = - V_91 ;
T_1 V_183 ;
struct V_24 * V_53 = (struct V_24 * ) V_170 -> V_26 ;
F_20 ( V_93 != 1 ) ;
F_20 ( F_62 ( V_8 ) ) ;
if ( V_53 -> V_32 ) {
V_98 = F_116 ( F_17 ( V_8 -> V_50 ) ,
V_170 , V_118 ,
F_11 ( V_53 -> V_33 ) ,
V_2 ) ;
if ( ! V_98 && V_100 ) {
V_183 = F_15 ( V_53 -> V_29 ) +
V_2 -> V_5 + V_2 -> V_169 ;
F_128 (
( unsigned long long ) V_183 ,
( unsigned long long ) V_100 ) ;
if ( V_183 > V_100 )
V_98 = - V_91 ;
}
}
return V_98 ;
}
int F_129 ( struct V_8 * V_8 ,
T_3 * V_67 ,
struct V_21 * V_185 ,
T_2 V_89 ,
T_4 V_175 )
{
int V_98 ;
T_2 V_186 ;
struct V_35 * V_36 = (struct V_35 * ) V_185 -> V_26 ;
struct V_15 * V_16 = (struct V_15 * ) & V_36 -> V_40 . V_41 ;
V_98 = F_69 ( V_67 , F_28 ( V_8 ) , V_185 ,
V_106 ) ;
if ( V_98 < 0 ) {
F_39 ( V_98 ) ;
goto V_49;
}
V_186 = F_16 ( V_36 -> V_108 . V_109 . V_110 ) ;
V_36 -> V_108 . V_109 . V_110 = F_34 ( V_89 + V_186 ) ;
F_70 ( & V_16 -> V_80 [ V_175 ] . V_107 , - V_89 ) ;
F_43 ( V_67 , V_185 ) ;
V_49:
return V_98 ;
}
void F_130 ( struct V_8 * V_8 ,
struct V_21 * V_185 ,
T_2 V_89 ,
T_4 V_175 )
{
T_2 V_186 ;
struct V_35 * V_36 = (struct V_35 * ) V_185 -> V_26 ;
struct V_15 * V_16 ;
V_16 = (struct V_15 * ) & V_36 -> V_40 . V_41 ;
V_186 = F_16 ( V_36 -> V_108 . V_109 . V_110 ) ;
V_36 -> V_108 . V_109 . V_110 = F_34 ( V_186 - V_89 ) ;
F_70 ( & V_16 -> V_80 [ V_175 ] . V_107 , V_89 ) ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
struct V_15 * V_16 )
{
unsigned int V_187 = F_11 ( V_16 -> V_18 ) ;
unsigned int V_188 = F_16 ( V_60 -> V_65 ) * V_187 ;
unsigned int V_189 = F_11 ( V_60 -> V_66 ) * V_187 ;
if ( V_2 -> V_5 < V_188 )
return 0 ;
if ( V_2 -> V_5 >= ( V_188 + V_189 ) )
return 0 ;
V_2 -> V_3 = F_15 ( V_60 -> V_64 ) +
( V_2 -> V_5 - V_188 ) ;
if ( ( V_2 -> V_5 + V_2 -> V_169 ) > ( V_188 + V_189 ) )
V_2 -> V_169 = ( V_188 + V_189 ) - V_2 -> V_5 ;
return 1 ;
}
static void F_132 ( struct V_6 * V_7 ,
struct V_24 * V_53 ,
struct V_1 * V_2 )
{
int V_97 ;
T_1 V_29 = V_2 -> V_4 ;
struct V_59 * V_60 ;
struct V_35 * V_36 = (struct V_35 * ) V_7 -> V_12 -> V_26 ;
struct V_15 * V_16 = & V_36 -> V_40 . V_41 ;
if ( F_62 ( V_7 -> V_9 ) ) {
V_2 -> V_3 = 0 ;
return;
}
V_2 -> V_3 = V_2 -> V_4 + V_2 -> V_5 ;
V_2 -> V_4 = 0 ;
if ( ! F_30 ( F_17 ( V_7 -> V_9 -> V_50 ) ) ||
! V_53 -> V_58 . V_61 )
return;
for ( V_97 = 0 ; V_97 < F_11 ( V_53 -> V_58 . V_61 ) ; V_97 ++ ) {
V_60 = & V_53 -> V_58 . V_63 [ V_97 ] ;
if ( F_131 ( V_2 , V_60 , V_16 ) ) {
V_2 -> V_4 = V_29 ;
break;
}
}
}
static int F_133 ( struct V_6 * V_7 ,
T_3 * V_67 ,
T_2 V_118 ,
T_2 V_93 ,
struct V_1 * V_2 ,
T_4 * V_190 )
{
int V_98 ;
struct V_21 * V_170 = NULL ;
struct V_24 * V_25 ;
struct V_35 * V_36 = (struct V_35 * ) V_7 -> V_12 -> V_26 ;
struct V_8 * V_68 = V_7 -> V_9 ;
V_98 = F_26 ( V_68 , V_36 ,
V_2 -> V_4 , & V_170 ) ;
if ( V_98 < 0 ) {
F_39 ( V_98 ) ;
return V_98 ;
}
V_25 = (struct V_24 * ) V_170 -> V_26 ;
V_98 = V_7 -> V_143 ( V_68 , V_170 , V_118 , V_93 ,
V_7 -> V_126 , V_2 ) ;
if ( V_98 < 0 ) {
if ( V_98 != - V_91 )
F_39 ( V_98 ) ;
goto V_49;
}
if ( ! V_98 )
F_132 ( V_7 , V_25 , V_2 ) ;
V_2 -> V_191 = V_170 -> V_27 ;
if ( V_7 -> V_192 )
goto V_193;
V_98 = F_129 ( V_68 , V_67 , V_7 -> V_12 ,
V_2 -> V_169 ,
F_11 ( V_25 -> V_42 ) ) ;
if ( V_98 < 0 ) {
F_39 ( V_98 ) ;
goto V_49;
}
V_98 = F_118 ( V_67 , V_68 , V_25 , V_170 ,
V_2 -> V_5 , V_2 -> V_169 ) ;
if ( V_98 < 0 ) {
F_130 ( V_68 , V_7 -> V_12 ,
V_2 -> V_169 ,
F_11 ( V_25 -> V_42 ) ) ;
F_39 ( V_98 ) ;
}
V_193:
* V_190 = F_11 ( V_25 -> V_32 ) ;
V_49:
F_7 ( V_170 ) ;
return V_98 ;
}
static int F_134 ( struct V_6 * V_7 ,
T_3 * V_67 ,
T_2 V_118 ,
T_2 V_93 ,
struct V_1 * V_2 ,
T_4 * V_190 )
{
int V_73 ;
T_4 V_175 ;
T_1 V_194 ;
struct V_8 * V_68 = V_7 -> V_9 ;
struct V_21 * V_170 = NULL ;
struct V_21 * V_195 = NULL ;
struct V_35 * V_104 = (struct V_35 * ) V_7 -> V_12 -> V_26 ;
struct V_15 * V_16 = (struct V_15 * ) & V_104 -> V_40 . V_41 ;
struct V_24 * V_53 ;
V_175 = V_7 -> V_196 ;
F_135 (
( unsigned long long ) F_41 ( V_68 ) -> V_82 ,
V_118 , V_175 ) ;
V_73 = F_26 ( V_68 , V_104 ,
F_15 ( V_16 -> V_80 [ V_175 ] . V_81 ) ,
& V_170 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_53 = (struct V_24 * ) V_170 -> V_26 ;
V_73 = - V_91 ;
while ( ( V_73 = V_7 -> V_143 ( V_68 , V_170 ,
V_118 , V_93 ,
V_7 -> V_126 ,
V_2 ) ) == - V_91 ) {
if ( ! V_53 -> V_79 )
break;
F_7 ( V_195 ) ;
V_195 = NULL ;
V_194 = F_15 ( V_53 -> V_79 ) ;
V_195 = V_170 ;
V_170 = NULL ;
V_73 = F_26 ( V_68 , V_104 ,
V_194 , & V_170 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_53 = (struct V_24 * ) V_170 -> V_26 ;
}
if ( V_73 < 0 ) {
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
F_136 (
( unsigned long long ) F_15 ( V_53 -> V_29 ) , V_2 -> V_169 ) ;
V_2 -> V_4 = F_15 ( V_53 -> V_29 ) ;
F_20 ( V_2 -> V_169 == 0 ) ;
if ( ! V_73 )
F_132 ( V_7 , V_53 , V_2 ) ;
V_2 -> V_191 = V_170 -> V_27 ;
if ( ! V_7 -> V_99 &&
( V_195 ) &&
( F_123 ( V_53 , V_2 -> V_169 ) ) ) {
V_73 = F_121 ( V_67 , V_68 ,
V_7 -> V_12 , V_170 ,
V_195 , V_175 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
}
if ( V_7 -> V_192 )
goto V_193;
V_73 = F_129 ( V_68 , V_67 ,
V_7 -> V_12 , V_2 -> V_169 ,
V_175 ) ;
if ( V_73 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_73 = F_118 ( V_67 ,
V_68 ,
V_53 ,
V_170 ,
V_2 -> V_5 ,
V_2 -> V_169 ) ;
if ( V_73 < 0 ) {
F_130 ( V_68 ,
V_7 -> V_12 , V_2 -> V_169 , V_175 ) ;
F_39 ( V_73 ) ;
goto V_74;
}
F_137 (
( unsigned long long ) F_15 ( V_104 -> V_38 ) ,
V_2 -> V_169 ) ;
V_193:
* V_190 = F_11 ( V_53 -> V_32 ) ;
V_74:
F_7 ( V_170 ) ;
F_7 ( V_195 ) ;
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
static int F_138 ( struct V_6 * V_7 ,
T_3 * V_67 ,
T_2 V_118 ,
T_2 V_93 ,
struct V_1 * V_2 )
{
int V_73 ;
T_4 V_197 , V_97 ;
T_4 V_190 = 0 ;
T_1 V_198 = V_7 -> V_105 ;
struct V_15 * V_16 ;
struct V_35 * V_104 ;
F_20 ( V_7 -> V_199 >= V_7 -> V_119 ) ;
F_20 ( V_118 > ( V_7 -> V_119 - V_7 -> V_199 ) ) ;
F_20 ( ! V_7 -> V_12 ) ;
V_104 = (struct V_35 * ) V_7 -> V_12 -> V_26 ;
F_20 ( ! F_82 ( V_104 ) ) ;
if ( F_16 ( V_104 -> V_108 . V_109 . V_110 ) >=
F_16 ( V_104 -> V_108 . V_109 . V_111 ) ) {
V_73 = F_37 ( V_7 -> V_9 -> V_50 ,
L_13 ,
( unsigned long long ) F_15 ( V_104 -> V_38 ) ,
F_16 ( V_104 -> V_108 . V_109 . V_110 ) ,
F_16 ( V_104 -> V_108 . V_109 . V_111 ) ) ;
goto V_74;
}
V_2 -> V_4 = V_198 ;
if ( V_2 -> V_4 ) {
V_73 = F_133 ( V_7 , V_67 , V_118 ,
V_93 , V_2 , & V_190 ) ;
if ( ! V_73 )
goto V_200;
if ( V_73 < 0 && V_73 != - V_91 ) {
F_39 ( V_73 ) ;
goto V_74;
}
}
V_16 = (struct V_15 * ) & V_104 -> V_40 . V_41 ;
V_197 = F_120 ( V_16 ) ;
V_7 -> V_196 = V_197 ;
V_73 = F_134 ( V_7 , V_67 , V_118 , V_93 ,
V_2 , & V_190 ) ;
if ( ! V_73 ) {
if ( F_62 ( V_7 -> V_9 ) )
V_198 = V_2 -> V_4 ;
else
V_198 = F_1 ( V_2 ) ;
goto V_200;
}
if ( V_73 < 0 && V_73 != - V_91 ) {
F_39 ( V_73 ) ;
goto V_74;
}
F_139 ( V_197 ) ;
V_7 -> V_99 = 1 ;
for ( V_97 = 0 ; V_97 < F_11 ( V_16 -> V_43 ) ; V_97 ++ ) {
if ( V_97 == V_197 )
continue;
if ( ! V_16 -> V_80 [ V_97 ] . V_107 )
continue;
V_7 -> V_196 = V_97 ;
V_73 = F_134 ( V_7 , V_67 , V_118 , V_93 ,
V_2 , & V_190 ) ;
if ( ! V_73 ) {
V_198 = F_1 ( V_2 ) ;
break;
}
if ( V_73 < 0 && V_73 != - V_91 ) {
F_39 ( V_73 ) ;
goto V_74;
}
}
V_200:
if ( V_73 != - V_91 ) {
if ( V_190 < V_93 )
V_7 -> V_105 = 0 ;
else
V_7 -> V_105 = V_198 ;
}
V_74:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_140 ( T_3 * V_67 ,
struct V_6 * V_7 ,
T_2 V_118 ,
T_1 * V_201 ,
T_4 * V_202 ,
unsigned int * V_89 ,
T_1 * V_203 )
{
int V_73 ;
struct V_1 V_2 = { . V_3 = 0 , } ;
F_20 ( ! V_7 ) ;
F_20 ( V_7 -> V_119 < ( V_7 -> V_199 + V_118 ) ) ;
F_20 ( V_7 -> V_10 != V_142 ) ;
V_73 = F_138 ( V_7 ,
V_67 ,
V_118 ,
1 ,
& V_2 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
F_85 ( & F_17 ( V_7 -> V_9 -> V_50 ) -> V_127 . V_204 ) ;
* V_201 = V_2 . V_4 ;
* V_202 = V_2 . V_5 ;
* V_203 = V_2 . V_3 ;
V_7 -> V_199 += V_2 . V_169 ;
* V_89 = V_2 . V_169 ;
V_73 = 0 ;
V_74:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
static void F_141 ( struct V_8 * V_205 ,
struct V_21 * V_206 ,
struct V_6 * V_7 )
{
struct V_35 * V_36 = (struct V_35 * ) V_206 -> V_26 ;
if ( F_41 ( V_205 ) -> V_207 &&
F_41 ( V_205 ) -> V_208 == V_7 -> V_122 )
V_7 -> V_105 = F_41 ( V_205 ) -> V_207 ;
else if ( F_11 ( V_36 -> V_209 ) == V_7 -> V_122 ) {
if ( V_36 -> V_210 )
V_7 -> V_105 = F_15 ( V_36 -> V_210 ) ;
else
V_7 -> V_105 = F_2 (
F_15 ( V_36 -> V_38 ) ,
F_11 ( V_36 -> V_211 ) ) ;
}
}
static inline void F_142 ( struct V_8 * V_205 ,
struct V_6 * V_7 )
{
F_41 ( V_205 ) -> V_207 = V_7 -> V_105 ;
F_41 ( V_205 ) -> V_208 = V_7 -> V_122 ;
}
int F_143 ( struct V_8 * V_205 ,
struct V_21 * V_212 ,
struct V_6 * V_7 ,
T_1 * V_213 )
{
int V_98 ;
T_3 * V_67 = NULL ;
struct V_1 * V_2 ;
F_20 ( ! V_7 ) ;
F_20 ( V_7 -> V_199 != 0 ) ;
F_20 ( V_7 -> V_119 != 1 ) ;
F_20 ( V_7 -> V_10 != V_150 ) ;
V_2 = F_99 ( sizeof( * V_2 ) , V_214 ) ;
if ( V_2 == NULL ) {
V_98 = - V_92 ;
F_39 ( V_98 ) ;
goto V_49;
}
F_141 ( V_205 , V_212 , V_7 ) ;
V_67 = F_65 ( F_17 ( V_205 -> V_50 ) , V_215 ) ;
if ( F_66 ( V_67 ) ) {
V_98 = F_67 ( V_67 ) ;
V_67 = NULL ;
F_39 ( V_98 ) ;
goto V_49;
}
V_7 -> V_192 = 1 ;
V_98 = F_138 ( V_7 , V_67 , 1 , 1 , V_2 ) ;
if ( V_98 < 0 ) {
F_39 ( V_98 ) ;
goto V_49;
}
V_7 -> V_14 = V_2 ;
* V_213 = V_2 -> V_3 ;
F_76 ( V_67 , V_205 , 0 ) ;
V_49:
if ( V_67 )
F_77 ( F_17 ( V_205 -> V_50 ) , V_67 ) ;
if ( V_98 )
F_8 ( V_2 ) ;
return V_98 ;
}
int F_144 ( T_3 * V_67 ,
struct V_8 * V_205 ,
struct V_6 * V_7 ,
T_1 * V_201 ,
T_4 * V_216 ,
T_1 V_217 )
{
int V_98 ;
T_4 V_175 ;
struct V_1 * V_2 = V_7 -> V_14 ;
struct V_21 * V_69 = NULL ;
struct V_24 * V_53 ;
struct V_35 * V_36 = (struct V_35 * ) V_7 -> V_12 -> V_26 ;
F_20 ( V_2 -> V_3 != V_217 ) ;
V_98 = F_26 ( V_7 -> V_9 , V_36 ,
V_2 -> V_191 , & V_69 ) ;
if ( V_98 ) {
F_39 ( V_98 ) ;
goto V_49;
}
V_53 = (struct V_24 * ) V_69 -> V_26 ;
V_175 = F_11 ( V_53 -> V_42 ) ;
V_98 = F_129 ( V_7 -> V_9 , V_67 ,
V_7 -> V_12 , V_2 -> V_169 ,
V_175 ) ;
if ( V_98 ) {
F_39 ( V_98 ) ;
goto V_49;
}
V_98 = F_118 ( V_67 ,
V_7 -> V_9 ,
V_53 ,
V_69 ,
V_2 -> V_5 ,
V_2 -> V_169 ) ;
if ( V_98 < 0 ) {
F_130 ( V_7 -> V_9 ,
V_7 -> V_12 , V_2 -> V_169 , V_175 ) ;
F_39 ( V_98 ) ;
goto V_49;
}
F_145 ( ( unsigned long long ) V_217 ,
V_2 -> V_169 ) ;
F_85 ( & F_17 ( V_7 -> V_9 -> V_50 ) -> V_127 . V_204 ) ;
F_20 ( V_2 -> V_169 != 1 ) ;
* V_201 = V_2 -> V_4 ;
* V_216 = V_2 -> V_5 ;
V_7 -> V_199 ++ ;
F_142 ( V_205 , V_7 ) ;
V_49:
F_7 ( V_69 ) ;
return V_98 ;
}
int F_146 ( T_3 * V_67 ,
struct V_8 * V_205 ,
struct V_21 * V_212 ,
struct V_6 * V_7 ,
T_1 * V_201 ,
T_4 * V_216 ,
T_1 * V_213 )
{
int V_73 ;
struct V_1 V_2 ;
F_20 ( ! V_7 ) ;
F_20 ( V_7 -> V_199 != 0 ) ;
F_20 ( V_7 -> V_119 != 1 ) ;
F_20 ( V_7 -> V_10 != V_150 ) ;
F_141 ( V_205 , V_212 , V_7 ) ;
V_73 = F_138 ( V_7 ,
V_67 ,
1 ,
1 ,
& V_2 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
F_85 ( & F_17 ( V_7 -> V_9 -> V_50 ) -> V_127 . V_204 ) ;
F_20 ( V_2 . V_169 != 1 ) ;
* V_201 = V_2 . V_4 ;
* V_216 = V_2 . V_5 ;
* V_213 = V_2 . V_3 ;
V_7 -> V_199 ++ ;
F_142 ( V_205 , V_7 ) ;
V_73 = 0 ;
V_74:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
static inline T_2 F_147 ( struct V_8 * V_8 ,
T_1 V_29 ,
T_4 V_218 )
{
struct V_51 * V_52 = F_17 ( V_8 -> V_50 ) ;
T_2 V_219 = 0 ;
F_20 ( ! F_62 ( V_8 ) ) ;
if ( V_29 != V_52 -> V_220 )
V_219 = F_124 ( V_8 -> V_50 , V_29 ) ;
V_219 += ( T_2 ) V_218 ;
return V_219 ;
}
T_1 F_148 ( struct V_8 * V_8 , T_2 V_219 )
{
struct V_51 * V_52 = F_17 ( V_8 -> V_50 ) ;
T_2 V_221 ;
F_20 ( ! F_62 ( V_8 ) ) ;
V_221 = V_219 / V_52 -> V_222 ;
if ( ! V_221 )
return V_52 -> V_220 ;
return F_47 ( V_8 -> V_50 ,
V_221 * V_52 -> V_222 ) ;
}
static inline void F_149 ( struct V_8 * V_8 ,
T_1 V_223 ,
T_1 * V_29 ,
T_4 * V_218 )
{
struct V_51 * V_52 = F_17 ( V_8 -> V_50 ) ;
T_2 V_224 = F_124 ( V_52 -> V_20 , V_223 ) ;
F_20 ( ! F_62 ( V_8 ) ) ;
* V_29 = F_148 ( V_8 ,
V_224 ) ;
if ( * V_29 == V_52 -> V_220 )
* V_218 = ( T_4 ) V_224 ;
else
* V_218 = ( T_4 ) F_124 ( V_52 -> V_20 ,
V_223 - * V_29 ) ;
}
int F_150 ( T_3 * V_67 ,
struct V_6 * V_7 ,
T_2 V_225 ,
T_2 V_226 ,
T_2 * V_227 ,
T_2 * V_228 )
{
int V_73 ;
unsigned int V_118 = V_226 ;
struct V_1 V_2 = { . V_3 = 0 , } ;
struct V_51 * V_52 = F_17 ( V_7 -> V_9 -> V_50 ) ;
F_20 ( V_7 -> V_199 >= V_7 -> V_119 ) ;
F_20 ( V_7 -> V_10 != V_11
&& V_7 -> V_10 != V_155 ) ;
if ( V_7 -> V_10 == V_11 ) {
F_151 ( V_225 > 1 ) ;
V_73 = F_152 ( V_52 ,
V_67 ,
V_7 ,
V_118 ,
V_227 ,
V_228 ) ;
if ( ! V_73 )
F_85 ( & V_52 -> V_127 . V_229 ) ;
} else {
if ( V_225 > ( V_52 -> V_222 - 1 ) ) {
F_23 ( V_46 , L_14
L_15 , V_225 ,
V_52 -> V_222 ) ;
V_73 = - V_91 ;
goto V_74;
}
if ( V_118 > ( V_52 -> V_222 - 1 ) )
V_118 = V_52 -> V_222 - 1 ;
V_73 = F_138 ( V_7 ,
V_67 ,
V_118 ,
V_225 ,
& V_2 ) ;
if ( ! V_73 ) {
F_20 ( V_2 . V_3 ) ;
* V_227 =
F_147 ( V_7 -> V_9 ,
V_2 . V_4 ,
V_2 . V_5 ) ;
F_85 ( & V_52 -> V_127 . V_230 ) ;
* V_228 = V_2 . V_169 ;
}
}
if ( V_73 < 0 ) {
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
V_7 -> V_199 += * V_228 ;
V_74:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_46 ( T_3 * V_67 ,
struct V_6 * V_7 ,
T_2 V_225 ,
T_2 * V_227 ,
T_2 * V_228 )
{
unsigned int V_118 = V_7 -> V_119 - V_7 -> V_199 ;
return F_150 ( V_67 , V_7 , V_225 ,
V_118 , V_227 , V_228 ) ;
}
static int F_153 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_24 * V_53 ,
struct V_21 * V_170 ,
unsigned int V_88 ,
unsigned int V_89 ,
void (* F_154)( unsigned int V_231 ,
unsigned long * V_232 ) )
{
int V_73 ;
unsigned int V_48 ;
struct V_24 * V_233 = NULL ;
F_20 ( ! F_13 ( V_53 ) ) ;
F_155 ( V_88 , V_89 ) ;
F_20 ( F_154 && ! F_62 ( V_68 ) ) ;
V_73 = F_38 ( V_67 , F_28 ( V_68 ) ,
V_170 ,
F_154 ?
V_172 :
V_106 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
if ( F_154 ) {
F_113 ( V_170 ) ;
V_233 = (struct V_24 * )
F_114 ( V_170 ) -> V_161 ;
F_20 ( ! V_233 ) ;
}
V_48 = V_89 ;
while( V_48 -- ) {
F_156 ( ( V_88 + V_48 ) ,
( unsigned long * ) V_53 -> V_83 ) ;
if ( F_154 )
F_154 ( V_88 + V_48 ,
( unsigned long * ) V_233 -> V_83 ) ;
}
F_35 ( & V_53 -> V_32 , V_89 ) ;
if ( F_11 ( V_53 -> V_32 ) > F_11 ( V_53 -> V_33 ) ) {
return F_37 ( V_68 -> V_50 , L_12 ,
( unsigned long long ) F_15 ( V_53 -> V_29 ) ,
F_11 ( V_53 -> V_33 ) ,
F_11 ( V_53 -> V_32 ) ,
V_89 ) ;
}
if ( F_154 )
F_115 ( V_170 ) ;
F_43 ( V_67 , V_170 ) ;
V_74:
return V_73 ;
}
static int F_157 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_21 * V_234 ,
unsigned int V_235 ,
T_1 V_29 ,
unsigned int V_236 ,
void (* F_154)( unsigned int V_231 ,
unsigned long * V_163 ) )
{
int V_73 = 0 ;
T_2 V_186 ;
struct V_35 * V_104 = (struct V_35 * ) V_234 -> V_26 ;
struct V_15 * V_16 = & V_104 -> V_40 . V_41 ;
struct V_21 * V_170 = NULL ;
struct V_24 * V_237 ;
F_20 ( ! F_82 ( V_104 ) ) ;
F_20 ( ( V_236 + V_235 ) > F_10 ( V_16 ) ) ;
F_158 (
( unsigned long long ) F_41 ( V_68 ) -> V_82 ,
( unsigned long long ) V_29 ,
V_235 , V_236 ) ;
V_73 = F_26 ( V_68 , V_104 , V_29 ,
& V_170 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_237 = (struct V_24 * ) V_170 -> V_26 ;
F_20 ( ( V_236 + V_235 ) > F_11 ( V_237 -> V_33 ) ) ;
V_73 = F_153 ( V_67 , V_68 ,
V_237 , V_170 ,
V_235 , V_236 , F_154 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_73 = F_69 ( V_67 , F_28 ( V_68 ) ,
V_234 , V_106 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
F_118 ( V_67 , V_68 , V_237 , V_170 ,
V_235 , V_236 ) ;
goto V_74;
}
F_70 ( & V_16 -> V_80 [ F_11 ( V_237 -> V_42 ) ] . V_107 ,
V_236 ) ;
V_186 = F_16 ( V_104 -> V_108 . V_109 . V_110 ) ;
V_104 -> V_108 . V_109 . V_110 = F_34 ( V_186 - V_236 ) ;
F_43 ( V_67 , V_234 ) ;
V_74:
F_7 ( V_170 ) ;
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_159 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_21 * V_234 ,
unsigned int V_235 ,
T_1 V_29 ,
unsigned int V_236 )
{
return F_157 ( V_67 , V_68 , V_234 ,
V_235 , V_29 , V_236 , NULL ) ;
}
int F_160 ( T_3 * V_67 ,
struct V_8 * V_238 ,
struct V_21 * V_239 ,
struct V_35 * V_36 )
{
T_1 V_240 = F_15 ( V_36 -> V_38 ) ;
T_4 V_231 = F_11 ( V_36 -> V_211 ) ;
T_1 V_29 = F_2 ( V_240 , V_231 ) ;
if ( V_36 -> V_210 )
V_29 = F_15 ( V_36 -> V_210 ) ;
return F_159 ( V_67 , V_238 ,
V_239 , V_231 , V_29 , 1 ) ;
}
static int F_161 ( T_3 * V_67 ,
struct V_8 * V_241 ,
struct V_21 * V_242 ,
T_1 V_243 ,
unsigned int V_228 ,
void (* F_154)( unsigned int V_231 ,
unsigned long * V_163 ) )
{
int V_73 ;
T_4 V_244 ;
T_1 V_29 ;
struct V_35 * V_104 ;
F_20 ( V_243 != F_47 ( V_241 -> V_50 , F_124 ( V_241 -> V_50 , V_243 ) ) ) ;
V_104 = (struct V_35 * ) V_242 -> V_26 ;
F_149 ( V_241 , V_243 , & V_29 ,
& V_244 ) ;
F_162 ( ( unsigned long long ) V_29 ,
( unsigned long long ) V_243 ,
V_244 , V_228 ) ;
V_73 = F_157 ( V_67 , V_241 , V_242 ,
V_244 , V_29 ,
V_228 , F_154 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_49;
}
F_127 ( F_17 ( V_241 -> V_50 ) ,
V_228 ) ;
V_49:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_55 ( T_3 * V_67 ,
struct V_8 * V_241 ,
struct V_21 * V_242 ,
T_1 V_243 ,
unsigned int V_228 )
{
return F_161 ( V_67 , V_241 , V_242 ,
V_243 , V_228 ,
V_245 ) ;
}
int F_163 ( T_3 * V_67 ,
struct V_8 * V_241 ,
struct V_21 * V_242 ,
T_1 V_243 ,
unsigned int V_228 )
{
return F_161 ( V_67 , V_241 , V_242 ,
V_243 , V_228 ,
V_246 ) ;
}
static inline void F_164 ( struct V_24 * V_53 )
{
F_165 ( L_16 ) ;
F_165 ( L_17 , V_53 -> V_28 ) ;
F_165 ( L_18 , V_53 -> V_34 ) ;
F_165 ( L_19 , V_53 -> V_33 ) ;
F_165 ( L_20 , V_53 -> V_32 ) ;
F_165 ( L_21 , V_53 -> V_42 ) ;
F_165 ( L_22 , F_16 ( V_53 -> V_30 ) ) ;
F_165 ( L_23 ,
( unsigned long long ) V_53 -> V_79 ) ;
F_165 ( L_24 ,
( unsigned long long ) V_53 -> V_39 ) ;
F_165 ( L_25 ,
( unsigned long long ) V_53 -> V_29 ) ;
}
static inline void F_166 ( struct V_35 * V_104 )
{
int V_97 ;
F_165 ( L_26 , ( unsigned long long ) V_104 -> V_38 ) ;
F_165 ( L_27 , V_104 -> V_247 ) ;
F_165 ( L_28 ,
( unsigned long long ) V_104 -> V_115 ) ;
F_165 ( L_29 , V_104 -> V_112 ) ;
F_165 ( L_30 ,
F_16 ( V_104 -> V_248 ) ) ;
F_165 ( L_31 ,
F_16 ( V_104 -> V_108 . V_109 . V_110 ) ) ;
F_165 ( L_32 ,
F_16 ( V_104 -> V_108 . V_109 . V_111 ) ) ;
F_165 ( L_33 , V_104 -> V_40 . V_41 . V_17 ) ;
F_165 ( L_34 , V_104 -> V_40 . V_41 . V_18 ) ;
F_165 ( L_35 , V_104 -> V_40 . V_41 . V_86 ) ;
F_165 ( L_36 ,
V_104 -> V_40 . V_41 . V_43 ) ;
for( V_97 = 0 ; V_97 < V_104 -> V_40 . V_41 . V_43 ; V_97 ++ ) {
F_165 ( L_37 , V_97 ,
V_104 -> V_40 . V_41 . V_80 [ V_97 ] . V_107 ) ;
F_165 ( L_38 , V_97 ,
V_104 -> V_40 . V_41 . V_80 [ V_97 ] . V_87 ) ;
F_165 ( L_39 , V_97 ,
( unsigned long long ) V_104 -> V_40 . V_41 . V_80 [ V_97 ] . V_81 ) ;
}
}
int F_167 ( struct V_8 * V_8 ,
struct V_249 * V_250 ,
T_2 V_251 , T_2 V_252 ,
struct V_6 * * V_253 ,
struct V_6 * * V_254 )
{
int V_98 = 0 , V_255 ;
unsigned int V_256 = V_251 + 2 * V_252 ;
struct V_51 * V_52 = F_17 ( V_8 -> V_50 ) ;
* V_254 = NULL ;
if ( V_253 )
* V_253 = NULL ;
F_20 ( V_251 != 0 && V_253 == NULL ) ;
V_255 = F_168 ( V_250 ) ;
if ( V_255 < 0 ) {
V_98 = V_255 ;
F_39 ( V_98 ) ;
goto V_49;
}
if ( ! V_255 ||
( F_169 ( V_52 ) && V_255 < V_256 ) ) {
V_98 = F_101 ( V_52 , V_250 -> V_257 , V_254 ) ;
if ( V_98 < 0 ) {
if ( V_98 != - V_91 )
F_39 ( V_98 ) ;
goto V_49;
}
}
if ( V_251 == 0 )
goto V_49;
V_98 = F_109 ( V_52 , V_251 , V_253 ) ;
if ( V_98 < 0 ) {
if ( V_98 != - V_91 )
F_39 ( V_98 ) ;
goto V_49;
}
V_49:
if ( V_98 ) {
if ( * V_254 ) {
F_9 ( * V_254 ) ;
* V_254 = NULL ;
}
}
return V_98 ;
}
static int F_170 ( struct V_51 * V_52 , T_1 V_258 ,
T_4 * V_259 , T_1 * V_70 ,
T_4 * V_216 )
{
int V_73 ;
struct V_21 * V_260 = NULL ;
struct V_35 * V_261 ;
F_171 ( ( unsigned long long ) V_258 ) ;
V_73 = F_172 ( V_52 , V_258 , 1 , & V_260 ) ;
if ( V_73 < 0 ) {
F_23 ( V_46 , L_40 ,
( unsigned long long ) V_258 , V_73 ) ;
goto V_74;
}
V_261 = (struct V_35 * ) V_260 -> V_26 ;
if ( ! F_82 ( V_261 ) ) {
F_23 ( V_46 , L_41 ,
( unsigned long long ) V_258 ) ;
V_73 = - V_121 ;
goto V_74;
}
if ( F_11 ( V_261 -> V_209 ) != ( T_4 ) V_131 &&
( T_2 ) F_11 ( V_261 -> V_209 ) > V_52 -> V_138 - 1 ) {
F_23 ( V_46 , L_42 ,
( unsigned long long ) V_258 ,
( T_2 ) F_11 ( V_261 -> V_209 ) ) ;
V_73 = - V_121 ;
goto V_74;
}
if ( V_259 )
* V_259 = F_11 ( V_261 -> V_209 ) ;
if ( V_216 )
* V_216 = F_11 ( V_261 -> V_211 ) ;
if ( V_70 )
* V_70 = F_15 ( V_261 -> V_210 ) ;
V_74:
F_7 ( V_260 ) ;
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
static int F_173 ( struct V_51 * V_52 ,
struct V_8 * V_262 ,
struct V_21 * V_234 ,
T_1 V_70 , T_1 V_258 ,
T_4 V_231 , int * V_2 )
{
struct V_35 * V_263 ;
struct V_24 * V_237 ;
struct V_21 * V_170 = NULL ;
T_1 V_29 ;
int V_73 ;
F_174 ( ( unsigned long long ) V_258 ,
( unsigned int ) V_231 ) ;
V_263 = (struct V_35 * ) V_234 -> V_26 ;
if ( ( V_231 + 1 ) > F_10 ( & V_263 -> V_40 . V_41 ) ) {
F_23 ( V_46 , L_43 ,
( unsigned int ) V_231 ,
F_10 ( & V_263 -> V_40 . V_41 ) ) ;
V_73 = - V_121 ;
goto V_74;
}
V_29 = V_70 ? V_70 :
F_2 ( V_258 , V_231 ) ;
V_73 = F_26 ( V_262 , V_263 , V_29 ,
& V_170 ) ;
if ( V_73 < 0 ) {
F_23 ( V_46 , L_44 ,
( unsigned long long ) V_29 , V_73 ) ;
goto V_74;
}
V_237 = (struct V_24 * ) V_170 -> V_26 ;
* V_2 = F_111 ( V_231 , ( unsigned long * ) V_237 -> V_83 ) ;
V_74:
F_7 ( V_170 ) ;
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_175 ( struct V_51 * V_52 , T_1 V_258 , int * V_2 )
{
int V_73 ;
T_1 V_70 = 0 ;
T_4 V_216 = 0 , V_259 = 0 ;
struct V_8 * V_238 ;
struct V_21 * V_234 = NULL ;
F_176 ( ( unsigned long long ) V_258 ) ;
V_73 = F_170 ( V_52 , V_258 , & V_259 ,
& V_70 , & V_216 ) ;
if ( V_73 < 0 ) {
F_23 ( V_46 , L_45 , V_73 ) ;
goto V_74;
}
V_238 =
F_79 ( V_52 , V_135 ,
V_259 ) ;
if ( ! V_238 ) {
V_73 = - V_121 ;
F_23 ( V_46 , L_46 ,
( T_2 ) V_259 ) ;
goto V_74;
}
F_80 ( V_238 ) ;
V_73 = F_81 ( V_238 , & V_234 , 0 ) ;
if ( V_73 < 0 ) {
F_5 ( V_238 ) ;
F_6 ( V_238 ) ;
F_23 ( V_46 , L_47 ,
( T_2 ) V_259 , V_73 ) ;
goto V_74;
}
V_73 = F_173 ( V_52 , V_238 , V_234 ,
V_70 , V_258 , V_216 , V_2 ) ;
if ( V_73 < 0 )
F_23 ( V_46 , L_48 , V_73 ) ;
F_4 ( V_238 , 0 ) ;
F_5 ( V_238 ) ;
F_6 ( V_238 ) ;
F_7 ( V_234 ) ;
V_74:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
