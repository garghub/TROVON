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
int V_73 ;
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
V_73 = F_105 ( V_52 , * V_7 ) ;
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
int F_108 ( struct V_51 * V_52 ,
T_2 V_118 ,
struct V_6 * * V_7 )
{
return F_63 ( V_52 , V_118 , 0 ,
V_125 , V_7 ) ;
}
static int F_109 ( struct V_21 * V_69 ,
int V_158 )
{
struct V_24 * V_53 = (struct V_24 * ) V_69 -> V_26 ;
int V_98 ;
if ( F_110 ( V_158 , ( unsigned long * ) V_53 -> V_83 ) )
return 0 ;
if ( ! F_111 ( V_69 ) )
return 1 ;
F_112 ( V_69 ) ;
V_53 = (struct V_24 * ) F_113 ( V_69 ) -> V_159 ;
if ( V_53 )
V_98 = ! F_110 ( V_158 , ( unsigned long * ) V_53 -> V_83 ) ;
else
V_98 = 1 ;
F_114 ( V_69 ) ;
return V_98 ;
}
static int F_115 ( struct V_51 * V_52 ,
struct V_21 * V_69 ,
unsigned int V_118 ,
unsigned int V_160 ,
struct V_1 * V_2 )
{
void * V_161 ;
T_4 V_162 , V_163 ;
int V_164 , V_165 , V_166 , V_73 = 0 ;
struct V_24 * V_53 = (struct V_24 * ) V_69 -> V_26 ;
F_20 ( ! F_13 ( V_53 ) ) ;
V_166 = V_165 = V_162 = V_163 = 0 ;
V_161 = V_53 -> V_83 ;
while( ( V_164 = F_116 ( V_161 , V_160 , V_165 ) ) != - 1 ) {
if ( V_164 == V_160 )
break;
if ( ! F_109 ( V_69 , V_164 ) ) {
V_166 = 0 ;
V_165 = V_164 + 1 ;
} else if ( V_164 == V_165 ) {
V_166 ++ ;
V_165 ++ ;
} else {
V_166 = 1 ;
V_165 = V_164 + 1 ;
}
if ( V_166 > V_163 ) {
V_163 = V_166 ;
V_162 = V_165 - V_166 ;
}
if ( V_166 == V_118 ) {
break;
}
}
if ( V_163 ) {
V_2 -> V_5 = V_162 ;
V_2 -> V_167 = V_163 ;
} else {
V_73 = - V_91 ;
}
return V_73 ;
}
int F_117 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_24 * V_53 ,
struct V_21 * V_168 ,
unsigned int V_88 ,
unsigned int V_89 )
{
int V_73 ;
void * V_161 = V_53 -> V_83 ;
int V_169 = V_106 ;
F_20 ( ! F_13 ( V_53 ) ) ;
F_20 ( F_11 ( V_53 -> V_32 ) < V_89 ) ;
F_118 ( V_88 , V_89 ) ;
if ( F_62 ( V_68 ) )
V_169 = V_170 ;
V_73 = F_38 ( V_67 ,
F_28 ( V_68 ) ,
V_168 ,
V_169 ) ;
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
F_42 ( V_88 ++ , V_161 ) ;
F_43 ( V_67 , V_168 ) ;
V_74:
return V_73 ;
}
static inline T_4 F_119 ( struct V_15 * V_16 )
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
static int F_120 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_21 * V_171 ,
struct V_21 * V_69 ,
struct V_21 * V_172 ,
T_4 V_173 )
{
int V_73 ;
T_1 V_174 , V_175 ;
struct V_35 * V_104 = (struct V_35 * ) V_171 -> V_26 ;
struct V_24 * V_53 = (struct V_24 * ) V_69 -> V_26 ;
struct V_24 * V_176 = (struct V_24 * ) V_172 -> V_26 ;
F_20 ( ! F_13 ( V_53 ) ) ;
F_20 ( ! F_13 ( V_176 ) ) ;
F_121 (
( unsigned long long ) F_15 ( V_104 -> V_38 ) , V_173 ,
( unsigned long long ) F_15 ( V_53 -> V_29 ) ,
( unsigned long long ) F_15 ( V_176 -> V_29 ) ) ;
V_174 = F_15 ( V_53 -> V_79 ) ;
V_175 = F_15 ( V_176 -> V_79 ) ;
V_73 = F_38 ( V_67 , F_28 ( V_68 ) ,
V_172 ,
V_106 ) ;
if ( V_73 < 0 )
goto V_49;
V_176 -> V_79 = V_53 -> V_79 ;
F_43 ( V_67 , V_172 ) ;
V_73 = F_38 ( V_67 , F_28 ( V_68 ) ,
V_69 , V_106 ) ;
if ( V_73 < 0 )
goto V_177;
V_53 -> V_79 = V_104 -> V_40 . V_41 . V_80 [ V_173 ] . V_81 ;
F_43 ( V_67 , V_69 ) ;
V_73 = F_69 ( V_67 , F_28 ( V_68 ) ,
V_171 , V_106 ) ;
if ( V_73 < 0 )
goto V_178;
V_104 -> V_40 . V_41 . V_80 [ V_173 ] . V_81 = V_53 -> V_29 ;
F_43 ( V_67 , V_171 ) ;
V_49:
if ( V_73 < 0 )
F_39 ( V_73 ) ;
return V_73 ;
V_178:
V_53 -> V_79 = F_33 ( V_174 ) ;
V_177:
V_176 -> V_79 = F_33 ( V_175 ) ;
goto V_49;
}
static inline int F_122 ( struct V_24 * V_53 ,
T_2 V_179 )
{
return F_11 ( V_53 -> V_32 ) > V_179 ;
}
static int V_156 ( struct V_8 * V_8 ,
struct V_21 * V_168 ,
T_2 V_118 , T_2 V_93 ,
T_1 V_100 ,
struct V_1 * V_2 )
{
int V_180 = - V_91 ;
int V_98 ;
T_1 V_181 ;
struct V_24 * V_25 = (struct V_24 * ) V_168 -> V_26 ;
struct V_51 * V_52 = F_17 ( V_8 -> V_50 ) ;
unsigned int V_37 , V_182 ;
F_20 ( ! F_62 ( V_8 ) ) ;
if ( V_25 -> V_32 ) {
V_37 = F_11 ( V_25 -> V_33 ) ;
V_182 = F_123 ( V_8 -> V_50 ,
F_15 ( V_25 -> V_29 ) ) ;
if ( ( V_182 + V_37 ) >
F_41 ( V_8 ) -> V_114 ) {
V_37 = F_41 ( V_8 ) -> V_114 - V_182 ;
F_124 (
( unsigned long long ) F_15 ( V_25 -> V_29 ) ,
F_11 ( V_25 -> V_33 ) ,
F_41 ( V_8 ) -> V_114 , V_37 ) ;
}
V_98 = F_115 ( F_17 ( V_8 -> V_50 ) ,
V_168 , V_118 ,
V_37 , V_2 ) ;
if ( V_98 )
return V_98 ;
if ( V_100 ) {
V_181 = F_47 ( V_8 -> V_50 ,
V_182 +
V_2 -> V_5 +
V_2 -> V_167 ) ;
F_125 (
( unsigned long long ) V_181 ,
( unsigned long long ) V_100 ) ;
if ( V_181 > V_100 )
return - V_91 ;
}
if ( V_93 <= V_2 -> V_167 )
V_180 = 0 ;
else if ( V_2 -> V_167 ) {
F_126 ( V_52 , V_2 -> V_167 ) ;
}
}
return V_180 ;
}
static int V_144 ( struct V_8 * V_8 ,
struct V_21 * V_168 ,
T_2 V_118 , T_2 V_93 ,
T_1 V_100 ,
struct V_1 * V_2 )
{
int V_98 = - V_91 ;
T_1 V_181 ;
struct V_24 * V_53 = (struct V_24 * ) V_168 -> V_26 ;
F_20 ( V_93 != 1 ) ;
F_20 ( F_62 ( V_8 ) ) ;
if ( V_53 -> V_32 ) {
V_98 = F_115 ( F_17 ( V_8 -> V_50 ) ,
V_168 , V_118 ,
F_11 ( V_53 -> V_33 ) ,
V_2 ) ;
if ( ! V_98 && V_100 ) {
V_181 = F_15 ( V_53 -> V_29 ) +
V_2 -> V_5 + V_2 -> V_167 ;
F_127 (
( unsigned long long ) V_181 ,
( unsigned long long ) V_100 ) ;
if ( V_181 > V_100 )
V_98 = - V_91 ;
}
}
return V_98 ;
}
int F_128 ( struct V_8 * V_8 ,
T_3 * V_67 ,
struct V_21 * V_183 ,
T_2 V_89 ,
T_4 V_173 )
{
int V_98 ;
T_2 V_184 ;
struct V_35 * V_36 = (struct V_35 * ) V_183 -> V_26 ;
struct V_15 * V_16 = (struct V_15 * ) & V_36 -> V_40 . V_41 ;
V_98 = F_69 ( V_67 , F_28 ( V_8 ) , V_183 ,
V_106 ) ;
if ( V_98 < 0 ) {
F_39 ( V_98 ) ;
goto V_49;
}
V_184 = F_16 ( V_36 -> V_108 . V_109 . V_110 ) ;
V_36 -> V_108 . V_109 . V_110 = F_34 ( V_89 + V_184 ) ;
F_70 ( & V_16 -> V_80 [ V_173 ] . V_107 , - V_89 ) ;
F_43 ( V_67 , V_183 ) ;
V_49:
return V_98 ;
}
void F_129 ( struct V_8 * V_8 ,
struct V_21 * V_183 ,
T_2 V_89 ,
T_4 V_173 )
{
T_2 V_184 ;
struct V_35 * V_36 = (struct V_35 * ) V_183 -> V_26 ;
struct V_15 * V_16 ;
V_16 = (struct V_15 * ) & V_36 -> V_40 . V_41 ;
V_184 = F_16 ( V_36 -> V_108 . V_109 . V_110 ) ;
V_36 -> V_108 . V_109 . V_110 = F_34 ( V_184 - V_89 ) ;
F_70 ( & V_16 -> V_80 [ V_173 ] . V_107 , V_89 ) ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
struct V_15 * V_16 )
{
unsigned int V_185 = F_11 ( V_16 -> V_18 ) ;
unsigned int V_186 = F_16 ( V_60 -> V_65 ) * V_185 ;
unsigned int V_187 = F_11 ( V_60 -> V_66 ) * V_185 ;
if ( V_2 -> V_5 < V_186 )
return 0 ;
if ( V_2 -> V_5 >= ( V_186 + V_187 ) )
return 0 ;
V_2 -> V_3 = F_15 ( V_60 -> V_64 ) +
( V_2 -> V_5 - V_186 ) ;
if ( ( V_2 -> V_5 + V_2 -> V_167 ) > ( V_186 + V_187 ) )
V_2 -> V_167 = ( V_186 + V_187 ) - V_2 -> V_5 ;
return 1 ;
}
static void F_131 ( struct V_6 * V_7 ,
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
if ( F_130 ( V_2 , V_60 , V_16 ) ) {
V_2 -> V_4 = V_29 ;
break;
}
}
}
static int F_132 ( struct V_6 * V_7 ,
T_3 * V_67 ,
T_2 V_118 ,
T_2 V_93 ,
struct V_1 * V_2 ,
T_4 * V_188 )
{
int V_98 ;
struct V_21 * V_168 = NULL ;
struct V_24 * V_25 ;
struct V_35 * V_36 = (struct V_35 * ) V_7 -> V_12 -> V_26 ;
struct V_8 * V_68 = V_7 -> V_9 ;
V_98 = F_26 ( V_68 , V_36 ,
V_2 -> V_4 , & V_168 ) ;
if ( V_98 < 0 ) {
F_39 ( V_98 ) ;
return V_98 ;
}
V_25 = (struct V_24 * ) V_168 -> V_26 ;
V_98 = V_7 -> V_143 ( V_68 , V_168 , V_118 , V_93 ,
V_7 -> V_126 , V_2 ) ;
if ( V_98 < 0 ) {
if ( V_98 != - V_91 )
F_39 ( V_98 ) ;
goto V_49;
}
if ( ! V_98 )
F_131 ( V_7 , V_25 , V_2 ) ;
V_2 -> V_189 = V_168 -> V_27 ;
if ( V_7 -> V_190 )
goto V_191;
V_98 = F_128 ( V_68 , V_67 , V_7 -> V_12 ,
V_2 -> V_167 ,
F_11 ( V_25 -> V_42 ) ) ;
if ( V_98 < 0 ) {
F_39 ( V_98 ) ;
goto V_49;
}
V_98 = F_117 ( V_67 , V_68 , V_25 , V_168 ,
V_2 -> V_5 , V_2 -> V_167 ) ;
if ( V_98 < 0 ) {
F_129 ( V_68 , V_7 -> V_12 ,
V_2 -> V_167 ,
F_11 ( V_25 -> V_42 ) ) ;
F_39 ( V_98 ) ;
}
V_191:
* V_188 = F_11 ( V_25 -> V_32 ) ;
V_49:
F_7 ( V_168 ) ;
return V_98 ;
}
static int F_133 ( struct V_6 * V_7 ,
T_3 * V_67 ,
T_2 V_118 ,
T_2 V_93 ,
struct V_1 * V_2 ,
T_4 * V_188 )
{
int V_73 ;
T_4 V_173 ;
T_1 V_192 ;
struct V_8 * V_68 = V_7 -> V_9 ;
struct V_21 * V_168 = NULL ;
struct V_21 * V_193 = NULL ;
struct V_35 * V_104 = (struct V_35 * ) V_7 -> V_12 -> V_26 ;
struct V_15 * V_16 = (struct V_15 * ) & V_104 -> V_40 . V_41 ;
struct V_24 * V_53 ;
V_173 = V_7 -> V_194 ;
F_134 (
( unsigned long long ) F_41 ( V_68 ) -> V_82 ,
V_118 , V_173 ) ;
V_73 = F_26 ( V_68 , V_104 ,
F_15 ( V_16 -> V_80 [ V_173 ] . V_81 ) ,
& V_168 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_53 = (struct V_24 * ) V_168 -> V_26 ;
V_73 = - V_91 ;
while ( ( V_73 = V_7 -> V_143 ( V_68 , V_168 ,
V_118 , V_93 ,
V_7 -> V_126 ,
V_2 ) ) == - V_91 ) {
if ( ! V_53 -> V_79 )
break;
F_7 ( V_193 ) ;
V_193 = NULL ;
V_192 = F_15 ( V_53 -> V_79 ) ;
V_193 = V_168 ;
V_168 = NULL ;
V_73 = F_26 ( V_68 , V_104 ,
V_192 , & V_168 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_53 = (struct V_24 * ) V_168 -> V_26 ;
}
if ( V_73 < 0 ) {
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
F_135 (
( unsigned long long ) F_15 ( V_53 -> V_29 ) , V_2 -> V_167 ) ;
V_2 -> V_4 = F_15 ( V_53 -> V_29 ) ;
F_20 ( V_2 -> V_167 == 0 ) ;
if ( ! V_73 )
F_131 ( V_7 , V_53 , V_2 ) ;
V_2 -> V_189 = V_168 -> V_27 ;
if ( ! V_7 -> V_99 &&
( V_193 ) &&
( F_122 ( V_53 , V_2 -> V_167 ) ) ) {
V_73 = F_120 ( V_67 , V_68 ,
V_7 -> V_12 , V_168 ,
V_193 , V_173 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
}
if ( V_7 -> V_190 )
goto V_191;
V_73 = F_128 ( V_68 , V_67 ,
V_7 -> V_12 , V_2 -> V_167 ,
V_173 ) ;
if ( V_73 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_73 = F_117 ( V_67 ,
V_68 ,
V_53 ,
V_168 ,
V_2 -> V_5 ,
V_2 -> V_167 ) ;
if ( V_73 < 0 ) {
F_129 ( V_68 ,
V_7 -> V_12 , V_2 -> V_167 , V_173 ) ;
F_39 ( V_73 ) ;
goto V_74;
}
F_136 (
( unsigned long long ) F_15 ( V_104 -> V_38 ) ,
V_2 -> V_167 ) ;
V_191:
* V_188 = F_11 ( V_53 -> V_32 ) ;
V_74:
F_7 ( V_168 ) ;
F_7 ( V_193 ) ;
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
static int F_137 ( struct V_6 * V_7 ,
T_3 * V_67 ,
T_2 V_118 ,
T_2 V_93 ,
struct V_1 * V_2 )
{
int V_73 ;
T_4 V_195 , V_97 ;
T_4 V_188 = 0 ;
T_1 V_196 = V_7 -> V_105 ;
struct V_15 * V_16 ;
struct V_35 * V_104 ;
F_20 ( V_7 -> V_197 >= V_7 -> V_119 ) ;
F_20 ( V_118 > ( V_7 -> V_119 - V_7 -> V_197 ) ) ;
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
V_2 -> V_4 = V_196 ;
if ( V_2 -> V_4 ) {
V_73 = F_132 ( V_7 , V_67 , V_118 ,
V_93 , V_2 , & V_188 ) ;
if ( ! V_73 )
goto V_198;
if ( V_73 < 0 && V_73 != - V_91 ) {
F_39 ( V_73 ) ;
goto V_74;
}
}
V_16 = (struct V_15 * ) & V_104 -> V_40 . V_41 ;
V_195 = F_119 ( V_16 ) ;
V_7 -> V_194 = V_195 ;
V_73 = F_133 ( V_7 , V_67 , V_118 , V_93 ,
V_2 , & V_188 ) ;
if ( ! V_73 ) {
if ( F_62 ( V_7 -> V_9 ) )
V_196 = V_2 -> V_4 ;
else
V_196 = F_1 ( V_2 ) ;
goto V_198;
}
if ( V_73 < 0 && V_73 != - V_91 ) {
F_39 ( V_73 ) ;
goto V_74;
}
F_138 ( V_195 ) ;
V_7 -> V_99 = 1 ;
for ( V_97 = 0 ; V_97 < F_11 ( V_16 -> V_43 ) ; V_97 ++ ) {
if ( V_97 == V_195 )
continue;
if ( ! V_16 -> V_80 [ V_97 ] . V_107 )
continue;
V_7 -> V_194 = V_97 ;
V_73 = F_133 ( V_7 , V_67 , V_118 , V_93 ,
V_2 , & V_188 ) ;
if ( ! V_73 ) {
V_196 = F_1 ( V_2 ) ;
break;
}
if ( V_73 < 0 && V_73 != - V_91 ) {
F_39 ( V_73 ) ;
goto V_74;
}
}
V_198:
if ( V_73 != - V_91 ) {
if ( V_188 < V_93 )
V_7 -> V_105 = 0 ;
else
V_7 -> V_105 = V_196 ;
}
V_74:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_139 ( T_3 * V_67 ,
struct V_6 * V_7 ,
T_2 V_118 ,
T_1 * V_199 ,
T_4 * V_200 ,
unsigned int * V_89 ,
T_1 * V_201 )
{
int V_73 ;
struct V_1 V_2 = { . V_3 = 0 , } ;
F_20 ( ! V_7 ) ;
F_20 ( V_7 -> V_119 < ( V_7 -> V_197 + V_118 ) ) ;
F_20 ( V_7 -> V_10 != V_142 ) ;
V_73 = F_137 ( V_7 ,
V_67 ,
V_118 ,
1 ,
& V_2 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
F_85 ( & F_17 ( V_7 -> V_9 -> V_50 ) -> V_127 . V_202 ) ;
* V_199 = V_2 . V_4 ;
* V_200 = V_2 . V_5 ;
* V_201 = V_2 . V_3 ;
V_7 -> V_197 += V_2 . V_167 ;
* V_89 = V_2 . V_167 ;
V_73 = 0 ;
V_74:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
static void F_140 ( struct V_8 * V_203 ,
struct V_21 * V_204 ,
struct V_6 * V_7 )
{
struct V_35 * V_36 = (struct V_35 * ) V_204 -> V_26 ;
if ( F_41 ( V_203 ) -> V_205 &&
F_41 ( V_203 ) -> V_206 == V_7 -> V_122 )
V_7 -> V_105 = F_41 ( V_203 ) -> V_205 ;
else if ( F_11 ( V_36 -> V_207 ) == V_7 -> V_122 ) {
if ( V_36 -> V_208 )
V_7 -> V_105 = F_15 ( V_36 -> V_208 ) ;
else
V_7 -> V_105 = F_2 (
F_15 ( V_36 -> V_38 ) ,
F_11 ( V_36 -> V_209 ) ) ;
}
}
static inline void F_141 ( struct V_8 * V_203 ,
struct V_6 * V_7 )
{
F_41 ( V_203 ) -> V_205 = V_7 -> V_105 ;
F_41 ( V_203 ) -> V_206 = V_7 -> V_122 ;
}
int F_142 ( struct V_8 * V_203 ,
struct V_21 * V_210 ,
struct V_6 * V_7 ,
T_1 * V_211 )
{
int V_98 ;
T_3 * V_67 = NULL ;
struct V_1 * V_2 ;
F_20 ( ! V_7 ) ;
F_20 ( V_7 -> V_197 != 0 ) ;
F_20 ( V_7 -> V_119 != 1 ) ;
F_20 ( V_7 -> V_10 != V_150 ) ;
V_2 = F_99 ( sizeof( * V_2 ) , V_212 ) ;
if ( V_2 == NULL ) {
V_98 = - V_92 ;
F_39 ( V_98 ) ;
goto V_49;
}
F_140 ( V_203 , V_210 , V_7 ) ;
V_67 = F_65 ( F_17 ( V_203 -> V_50 ) , V_213 ) ;
if ( F_66 ( V_67 ) ) {
V_98 = F_67 ( V_67 ) ;
V_67 = NULL ;
F_39 ( V_98 ) ;
goto V_49;
}
V_7 -> V_190 = 1 ;
V_98 = F_137 ( V_7 , V_67 , 1 , 1 , V_2 ) ;
if ( V_98 < 0 ) {
F_39 ( V_98 ) ;
goto V_49;
}
V_7 -> V_14 = V_2 ;
* V_211 = V_2 -> V_3 ;
F_76 ( V_67 , V_203 , 0 ) ;
V_49:
if ( V_67 )
F_77 ( F_17 ( V_203 -> V_50 ) , V_67 ) ;
if ( V_98 )
F_8 ( V_2 ) ;
return V_98 ;
}
int F_143 ( T_3 * V_67 ,
struct V_8 * V_203 ,
struct V_6 * V_7 ,
T_1 * V_199 ,
T_4 * V_214 ,
T_1 V_215 )
{
int V_98 ;
T_4 V_173 ;
struct V_1 * V_2 = V_7 -> V_14 ;
struct V_21 * V_69 = NULL ;
struct V_24 * V_53 ;
struct V_35 * V_36 = (struct V_35 * ) V_7 -> V_12 -> V_26 ;
F_20 ( V_2 -> V_3 != V_215 ) ;
V_98 = F_26 ( V_7 -> V_9 , V_36 ,
V_2 -> V_189 , & V_69 ) ;
if ( V_98 ) {
F_39 ( V_98 ) ;
goto V_49;
}
V_53 = (struct V_24 * ) V_69 -> V_26 ;
V_173 = F_11 ( V_53 -> V_42 ) ;
V_98 = F_128 ( V_7 -> V_9 , V_67 ,
V_7 -> V_12 , V_2 -> V_167 ,
V_173 ) ;
if ( V_98 ) {
F_39 ( V_98 ) ;
goto V_49;
}
V_98 = F_117 ( V_67 ,
V_7 -> V_9 ,
V_53 ,
V_69 ,
V_2 -> V_5 ,
V_2 -> V_167 ) ;
if ( V_98 < 0 ) {
F_129 ( V_7 -> V_9 ,
V_7 -> V_12 , V_2 -> V_167 , V_173 ) ;
F_39 ( V_98 ) ;
goto V_49;
}
F_144 ( ( unsigned long long ) V_215 ,
V_2 -> V_167 ) ;
F_85 ( & F_17 ( V_7 -> V_9 -> V_50 ) -> V_127 . V_202 ) ;
F_20 ( V_2 -> V_167 != 1 ) ;
* V_199 = V_2 -> V_4 ;
* V_214 = V_2 -> V_5 ;
V_7 -> V_197 ++ ;
F_141 ( V_203 , V_7 ) ;
V_49:
F_7 ( V_69 ) ;
return V_98 ;
}
int F_145 ( T_3 * V_67 ,
struct V_8 * V_203 ,
struct V_21 * V_210 ,
struct V_6 * V_7 ,
T_1 * V_199 ,
T_4 * V_214 ,
T_1 * V_211 )
{
int V_73 ;
struct V_1 V_2 ;
F_20 ( ! V_7 ) ;
F_20 ( V_7 -> V_197 != 0 ) ;
F_20 ( V_7 -> V_119 != 1 ) ;
F_20 ( V_7 -> V_10 != V_150 ) ;
F_140 ( V_203 , V_210 , V_7 ) ;
V_73 = F_137 ( V_7 ,
V_67 ,
1 ,
1 ,
& V_2 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
F_85 ( & F_17 ( V_7 -> V_9 -> V_50 ) -> V_127 . V_202 ) ;
F_20 ( V_2 . V_167 != 1 ) ;
* V_199 = V_2 . V_4 ;
* V_214 = V_2 . V_5 ;
* V_211 = V_2 . V_3 ;
V_7 -> V_197 ++ ;
F_141 ( V_203 , V_7 ) ;
V_73 = 0 ;
V_74:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
static inline T_2 F_146 ( struct V_8 * V_8 ,
T_1 V_29 ,
T_4 V_216 )
{
struct V_51 * V_52 = F_17 ( V_8 -> V_50 ) ;
T_2 V_217 = 0 ;
F_20 ( ! F_62 ( V_8 ) ) ;
if ( V_29 != V_52 -> V_218 )
V_217 = F_123 ( V_8 -> V_50 , V_29 ) ;
V_217 += ( T_2 ) V_216 ;
return V_217 ;
}
T_1 F_147 ( struct V_8 * V_8 , T_2 V_217 )
{
struct V_51 * V_52 = F_17 ( V_8 -> V_50 ) ;
T_2 V_219 ;
F_20 ( ! F_62 ( V_8 ) ) ;
V_219 = V_217 / V_52 -> V_220 ;
if ( ! V_219 )
return V_52 -> V_218 ;
return F_47 ( V_8 -> V_50 ,
V_219 * V_52 -> V_220 ) ;
}
static inline void F_148 ( struct V_8 * V_8 ,
T_1 V_221 ,
T_1 * V_29 ,
T_4 * V_216 )
{
struct V_51 * V_52 = F_17 ( V_8 -> V_50 ) ;
T_2 V_222 = F_123 ( V_52 -> V_20 , V_221 ) ;
F_20 ( ! F_62 ( V_8 ) ) ;
* V_29 = F_147 ( V_8 ,
V_222 ) ;
if ( * V_29 == V_52 -> V_218 )
* V_216 = ( T_4 ) V_222 ;
else
* V_216 = ( T_4 ) F_123 ( V_52 -> V_20 ,
V_221 - * V_29 ) ;
}
int F_149 ( T_3 * V_67 ,
struct V_6 * V_7 ,
T_2 V_223 ,
T_2 V_224 ,
T_2 * V_225 ,
T_2 * V_226 )
{
int V_73 ;
unsigned int V_118 = V_224 ;
struct V_1 V_2 = { . V_3 = 0 , } ;
struct V_51 * V_52 = F_17 ( V_7 -> V_9 -> V_50 ) ;
F_20 ( V_7 -> V_197 >= V_7 -> V_119 ) ;
F_20 ( V_7 -> V_10 != V_11
&& V_7 -> V_10 != V_155 ) ;
if ( V_7 -> V_10 == V_11 ) {
F_150 ( V_223 > 1 ) ;
V_73 = F_151 ( V_52 ,
V_67 ,
V_7 ,
V_118 ,
V_225 ,
V_226 ) ;
if ( ! V_73 )
F_85 ( & V_52 -> V_127 . V_227 ) ;
} else {
if ( V_223 > ( V_52 -> V_220 - 1 ) ) {
F_23 ( V_46 , L_14
L_15 , V_223 ,
V_52 -> V_220 ) ;
V_73 = - V_91 ;
goto V_74;
}
if ( V_118 > ( V_52 -> V_220 - 1 ) )
V_118 = V_52 -> V_220 - 1 ;
V_73 = F_137 ( V_7 ,
V_67 ,
V_118 ,
V_223 ,
& V_2 ) ;
if ( ! V_73 ) {
F_20 ( V_2 . V_3 ) ;
* V_225 =
F_146 ( V_7 -> V_9 ,
V_2 . V_4 ,
V_2 . V_5 ) ;
F_85 ( & V_52 -> V_127 . V_228 ) ;
* V_226 = V_2 . V_167 ;
}
}
if ( V_73 < 0 ) {
if ( V_73 != - V_91 )
F_39 ( V_73 ) ;
goto V_74;
}
V_7 -> V_197 += * V_226 ;
V_74:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_46 ( T_3 * V_67 ,
struct V_6 * V_7 ,
T_2 V_223 ,
T_2 * V_225 ,
T_2 * V_226 )
{
unsigned int V_118 = V_7 -> V_119 - V_7 -> V_197 ;
return F_149 ( V_67 , V_7 , V_223 ,
V_118 , V_225 , V_226 ) ;
}
static int F_152 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_24 * V_53 ,
struct V_21 * V_168 ,
unsigned int V_88 ,
unsigned int V_89 ,
void (* F_153)( unsigned int V_229 ,
unsigned long * V_230 ) )
{
int V_73 ;
unsigned int V_48 ;
struct V_24 * V_231 = NULL ;
F_20 ( ! F_13 ( V_53 ) ) ;
F_154 ( V_88 , V_89 ) ;
F_20 ( F_153 && ! F_62 ( V_68 ) ) ;
V_73 = F_38 ( V_67 , F_28 ( V_68 ) ,
V_168 ,
F_153 ?
V_170 :
V_106 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
if ( F_153 ) {
F_112 ( V_168 ) ;
V_231 = (struct V_24 * )
F_113 ( V_168 ) -> V_159 ;
F_20 ( ! V_231 ) ;
}
V_48 = V_89 ;
while( V_48 -- ) {
F_155 ( ( V_88 + V_48 ) ,
( unsigned long * ) V_53 -> V_83 ) ;
if ( F_153 )
F_153 ( V_88 + V_48 ,
( unsigned long * ) V_231 -> V_83 ) ;
}
F_35 ( & V_53 -> V_32 , V_89 ) ;
if ( F_11 ( V_53 -> V_32 ) > F_11 ( V_53 -> V_33 ) ) {
return F_37 ( V_68 -> V_50 , L_12 ,
( unsigned long long ) F_15 ( V_53 -> V_29 ) ,
F_11 ( V_53 -> V_33 ) ,
F_11 ( V_53 -> V_32 ) ,
V_89 ) ;
}
if ( F_153 )
F_114 ( V_168 ) ;
F_43 ( V_67 , V_168 ) ;
V_74:
return V_73 ;
}
static int F_156 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_21 * V_232 ,
unsigned int V_233 ,
T_1 V_29 ,
unsigned int V_234 ,
void (* F_153)( unsigned int V_229 ,
unsigned long * V_161 ) )
{
int V_73 = 0 ;
T_2 V_184 ;
struct V_35 * V_104 = (struct V_35 * ) V_232 -> V_26 ;
struct V_15 * V_16 = & V_104 -> V_40 . V_41 ;
struct V_21 * V_168 = NULL ;
struct V_24 * V_235 ;
F_20 ( ! F_82 ( V_104 ) ) ;
F_20 ( ( V_234 + V_233 ) > F_10 ( V_16 ) ) ;
F_157 (
( unsigned long long ) F_41 ( V_68 ) -> V_82 ,
( unsigned long long ) V_29 ,
V_233 , V_234 ) ;
V_73 = F_26 ( V_68 , V_104 , V_29 ,
& V_168 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_235 = (struct V_24 * ) V_168 -> V_26 ;
F_20 ( ( V_234 + V_233 ) > F_11 ( V_235 -> V_33 ) ) ;
V_73 = F_152 ( V_67 , V_68 ,
V_235 , V_168 ,
V_233 , V_234 , F_153 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_74;
}
V_73 = F_69 ( V_67 , F_28 ( V_68 ) ,
V_232 , V_106 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
F_117 ( V_67 , V_68 , V_235 , V_168 ,
V_233 , V_234 ) ;
goto V_74;
}
F_70 ( & V_16 -> V_80 [ F_11 ( V_235 -> V_42 ) ] . V_107 ,
V_234 ) ;
V_184 = F_16 ( V_104 -> V_108 . V_109 . V_110 ) ;
V_104 -> V_108 . V_109 . V_110 = F_34 ( V_184 - V_234 ) ;
F_43 ( V_67 , V_232 ) ;
V_74:
F_7 ( V_168 ) ;
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_158 ( T_3 * V_67 ,
struct V_8 * V_68 ,
struct V_21 * V_232 ,
unsigned int V_233 ,
T_1 V_29 ,
unsigned int V_234 )
{
return F_156 ( V_67 , V_68 , V_232 ,
V_233 , V_29 , V_234 , NULL ) ;
}
int F_159 ( T_3 * V_67 ,
struct V_8 * V_236 ,
struct V_21 * V_237 ,
struct V_35 * V_36 )
{
T_1 V_238 = F_15 ( V_36 -> V_38 ) ;
T_4 V_229 = F_11 ( V_36 -> V_209 ) ;
T_1 V_29 = F_2 ( V_238 , V_229 ) ;
if ( V_36 -> V_208 )
V_29 = F_15 ( V_36 -> V_208 ) ;
return F_158 ( V_67 , V_236 ,
V_237 , V_229 , V_29 , 1 ) ;
}
static int F_160 ( T_3 * V_67 ,
struct V_8 * V_239 ,
struct V_21 * V_240 ,
T_1 V_241 ,
unsigned int V_226 ,
void (* F_153)( unsigned int V_229 ,
unsigned long * V_161 ) )
{
int V_73 ;
T_4 V_242 ;
T_1 V_29 ;
struct V_35 * V_104 ;
F_20 ( V_241 != F_47 ( V_239 -> V_50 , F_123 ( V_239 -> V_50 , V_241 ) ) ) ;
V_104 = (struct V_35 * ) V_240 -> V_26 ;
F_148 ( V_239 , V_241 , & V_29 ,
& V_242 ) ;
F_161 ( ( unsigned long long ) V_29 ,
( unsigned long long ) V_241 ,
V_242 , V_226 ) ;
V_73 = F_156 ( V_67 , V_239 , V_240 ,
V_242 , V_29 ,
V_226 , F_153 ) ;
if ( V_73 < 0 ) {
F_39 ( V_73 ) ;
goto V_49;
}
F_126 ( F_17 ( V_239 -> V_50 ) ,
V_226 ) ;
V_49:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_55 ( T_3 * V_67 ,
struct V_8 * V_239 ,
struct V_21 * V_240 ,
T_1 V_241 ,
unsigned int V_226 )
{
return F_160 ( V_67 , V_239 , V_240 ,
V_241 , V_226 ,
V_243 ) ;
}
int F_162 ( T_3 * V_67 ,
struct V_8 * V_239 ,
struct V_21 * V_240 ,
T_1 V_241 ,
unsigned int V_226 )
{
return F_160 ( V_67 , V_239 , V_240 ,
V_241 , V_226 ,
V_244 ) ;
}
static inline void F_163 ( struct V_24 * V_53 )
{
F_164 ( L_16 ) ;
F_164 ( L_17 , V_53 -> V_28 ) ;
F_164 ( L_18 , V_53 -> V_34 ) ;
F_164 ( L_19 , V_53 -> V_33 ) ;
F_164 ( L_20 , V_53 -> V_32 ) ;
F_164 ( L_21 , V_53 -> V_42 ) ;
F_164 ( L_22 , F_16 ( V_53 -> V_30 ) ) ;
F_164 ( L_23 ,
( unsigned long long ) V_53 -> V_79 ) ;
F_164 ( L_24 ,
( unsigned long long ) V_53 -> V_39 ) ;
F_164 ( L_25 ,
( unsigned long long ) V_53 -> V_29 ) ;
}
static inline void F_165 ( struct V_35 * V_104 )
{
int V_97 ;
F_164 ( L_26 , ( unsigned long long ) V_104 -> V_38 ) ;
F_164 ( L_27 , V_104 -> V_245 ) ;
F_164 ( L_28 ,
( unsigned long long ) V_104 -> V_115 ) ;
F_164 ( L_29 , V_104 -> V_112 ) ;
F_164 ( L_30 ,
F_16 ( V_104 -> V_246 ) ) ;
F_164 ( L_31 ,
F_16 ( V_104 -> V_108 . V_109 . V_110 ) ) ;
F_164 ( L_32 ,
F_16 ( V_104 -> V_108 . V_109 . V_111 ) ) ;
F_164 ( L_33 , V_104 -> V_40 . V_41 . V_17 ) ;
F_164 ( L_34 , V_104 -> V_40 . V_41 . V_18 ) ;
F_164 ( L_35 , V_104 -> V_40 . V_41 . V_86 ) ;
F_164 ( L_36 ,
V_104 -> V_40 . V_41 . V_43 ) ;
for( V_97 = 0 ; V_97 < V_104 -> V_40 . V_41 . V_43 ; V_97 ++ ) {
F_164 ( L_37 , V_97 ,
V_104 -> V_40 . V_41 . V_80 [ V_97 ] . V_107 ) ;
F_164 ( L_38 , V_97 ,
V_104 -> V_40 . V_41 . V_80 [ V_97 ] . V_87 ) ;
F_164 ( L_39 , V_97 ,
( unsigned long long ) V_104 -> V_40 . V_41 . V_80 [ V_97 ] . V_81 ) ;
}
}
int F_166 ( struct V_8 * V_8 ,
struct V_247 * V_248 ,
T_2 V_249 , T_2 V_250 ,
struct V_6 * * V_251 ,
struct V_6 * * V_252 )
{
int V_98 = 0 , V_253 ;
unsigned int V_254 = V_249 + 2 * V_250 ;
struct V_51 * V_52 = F_17 ( V_8 -> V_50 ) ;
* V_252 = NULL ;
if ( V_251 )
* V_251 = NULL ;
F_20 ( V_249 != 0 && V_251 == NULL ) ;
V_253 = F_167 ( V_52 , V_248 ) ;
if ( V_253 < 0 ) {
V_98 = V_253 ;
F_39 ( V_98 ) ;
goto V_49;
}
if ( ! V_253 ||
( F_168 ( V_52 ) && V_253 < V_254 ) ) {
V_98 = F_101 ( V_52 , V_248 -> V_255 , V_252 ) ;
if ( V_98 < 0 ) {
if ( V_98 != - V_91 )
F_39 ( V_98 ) ;
goto V_49;
}
}
if ( V_249 == 0 )
goto V_49;
V_98 = F_108 ( V_52 , V_249 , V_251 ) ;
if ( V_98 < 0 ) {
if ( V_98 != - V_91 )
F_39 ( V_98 ) ;
goto V_49;
}
V_49:
if ( V_98 ) {
if ( * V_252 ) {
F_9 ( * V_252 ) ;
* V_252 = NULL ;
}
}
return V_98 ;
}
static int F_169 ( struct V_51 * V_52 , T_1 V_256 ,
T_4 * V_257 , T_1 * V_70 ,
T_4 * V_214 )
{
int V_73 ;
struct V_21 * V_258 = NULL ;
struct V_35 * V_259 ;
F_170 ( ( unsigned long long ) V_256 ) ;
V_73 = F_171 ( V_52 , V_256 , 1 , & V_258 ) ;
if ( V_73 < 0 ) {
F_23 ( V_46 , L_40 ,
( unsigned long long ) V_256 , V_73 ) ;
goto V_74;
}
V_259 = (struct V_35 * ) V_258 -> V_26 ;
if ( ! F_82 ( V_259 ) ) {
F_23 ( V_46 , L_41 ,
( unsigned long long ) V_256 ) ;
V_73 = - V_121 ;
goto V_74;
}
if ( F_11 ( V_259 -> V_207 ) != ( T_4 ) V_131 &&
( T_2 ) F_11 ( V_259 -> V_207 ) > V_52 -> V_138 - 1 ) {
F_23 ( V_46 , L_42 ,
( unsigned long long ) V_256 ,
( T_2 ) F_11 ( V_259 -> V_207 ) ) ;
V_73 = - V_121 ;
goto V_74;
}
if ( V_257 )
* V_257 = F_11 ( V_259 -> V_207 ) ;
if ( V_214 )
* V_214 = F_11 ( V_259 -> V_209 ) ;
if ( V_70 )
* V_70 = F_15 ( V_259 -> V_208 ) ;
V_74:
F_7 ( V_258 ) ;
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
static int F_172 ( struct V_51 * V_52 ,
struct V_8 * V_260 ,
struct V_21 * V_232 ,
T_1 V_70 , T_1 V_256 ,
T_4 V_229 , int * V_2 )
{
struct V_35 * V_261 ;
struct V_24 * V_235 ;
struct V_21 * V_168 = NULL ;
T_1 V_29 ;
int V_73 ;
F_173 ( ( unsigned long long ) V_256 ,
( unsigned int ) V_229 ) ;
V_261 = (struct V_35 * ) V_232 -> V_26 ;
if ( ( V_229 + 1 ) > F_10 ( & V_261 -> V_40 . V_41 ) ) {
F_23 ( V_46 , L_43 ,
( unsigned int ) V_229 ,
F_10 ( & V_261 -> V_40 . V_41 ) ) ;
V_73 = - V_121 ;
goto V_74;
}
V_29 = V_70 ? V_70 :
F_2 ( V_256 , V_229 ) ;
V_73 = F_26 ( V_260 , V_261 , V_29 ,
& V_168 ) ;
if ( V_73 < 0 ) {
F_23 ( V_46 , L_44 ,
( unsigned long long ) V_29 , V_73 ) ;
goto V_74;
}
V_235 = (struct V_24 * ) V_168 -> V_26 ;
* V_2 = F_110 ( V_229 , ( unsigned long * ) V_235 -> V_83 ) ;
V_74:
F_7 ( V_168 ) ;
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
int F_174 ( struct V_51 * V_52 , T_1 V_256 , int * V_2 )
{
int V_73 ;
T_1 V_70 = 0 ;
T_4 V_214 = 0 , V_257 = 0 ;
struct V_8 * V_236 ;
struct V_21 * V_232 = NULL ;
F_175 ( ( unsigned long long ) V_256 ) ;
V_73 = F_169 ( V_52 , V_256 , & V_257 ,
& V_70 , & V_214 ) ;
if ( V_73 < 0 ) {
F_23 ( V_46 , L_45 , V_73 ) ;
goto V_74;
}
V_236 =
F_79 ( V_52 , V_135 ,
V_257 ) ;
if ( ! V_236 ) {
V_73 = - V_121 ;
F_23 ( V_46 , L_46 ,
( T_2 ) V_257 ) ;
goto V_74;
}
F_80 ( V_236 ) ;
V_73 = F_81 ( V_236 , & V_232 , 0 ) ;
if ( V_73 < 0 ) {
F_5 ( V_236 ) ;
F_6 ( V_236 ) ;
F_23 ( V_46 , L_47 ,
( T_2 ) V_257 , V_73 ) ;
goto V_74;
}
V_73 = F_172 ( V_52 , V_236 , V_232 ,
V_70 , V_256 , V_214 , V_2 ) ;
if ( V_73 < 0 )
F_23 ( V_46 , L_48 , V_73 ) ;
F_4 ( V_236 , 0 ) ;
F_5 ( V_236 ) ;
F_6 ( V_236 ) ;
F_7 ( V_232 ) ;
V_74:
if ( V_73 )
F_39 ( V_73 ) ;
return V_73 ;
}
