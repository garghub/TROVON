static T_1 F_1 ( const struct V_1 * V_1 , const T_2 V_2 ,
const T_3 V_3 , const T_2 V_4 ,
const T_4 V_5 )
{
static T_1 T_5 V_6 ;
F_2 ( & T_5 , sizeof( T_5 ) ) ;
return F_3 ( V_2 , V_3 , V_4 , V_5 ,
T_5 + F_4 ( V_1 ) ) ;
}
T_1 F_5 ( const struct V_7 * V_8 )
{
#if F_6 ( V_9 )
if ( V_8 -> V_10 == V_11 &&
! F_7 ( & V_8 -> V_12 ) )
return F_8 ( F_9 ( V_8 ) ,
& V_8 -> V_13 , V_8 -> V_14 ,
& V_8 -> V_12 , V_8 -> V_15 ) ;
#endif
return F_1 ( F_9 ( V_8 ) ,
V_8 -> V_16 , V_8 -> V_14 ,
V_8 -> V_17 , V_8 -> V_15 ) ;
}
struct V_18 * F_10 ( struct V_19 * V_20 ,
struct V_1 * V_1 ,
struct V_21 * V_22 ,
const unsigned short V_23 )
{
struct V_18 * V_24 = F_11 ( V_20 , V_25 ) ;
if ( V_24 ) {
F_12 ( & V_24 -> V_26 , V_1 ) ;
V_24 -> V_27 = V_23 ;
V_24 -> V_28 = 0 ;
V_24 -> V_29 = 0 ;
V_24 -> V_30 = 0 ;
F_13 ( & V_24 -> V_31 ) ;
F_14 ( & V_24 -> V_32 , & V_22 -> V_33 ) ;
}
return V_24 ;
}
void F_15 ( struct V_19 * V_20 , struct V_18 * V_24 )
{
if ( F_16 ( & V_24 -> V_31 ) ) {
F_17 ( & V_24 -> V_32 ) ;
F_18 ( V_20 , V_24 ) ;
}
}
void F_19 ( struct V_7 * V_8 , struct V_18 * V_24 ,
const unsigned short V_23 )
{
F_20 ( V_8 ) -> V_34 = V_23 ;
F_21 ( V_8 , & V_24 -> V_31 ) ;
V_24 -> V_30 ++ ;
F_22 ( V_8 ) -> V_35 = V_24 ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
const int V_40 = F_24 ( F_9 ( V_8 ) , F_20 ( V_8 ) -> V_34 ,
V_37 -> V_41 ) ;
struct V_21 * V_22 = & V_37 -> V_40 [ V_40 ] ;
struct V_18 * V_24 ;
F_25 ( & V_22 -> V_42 ) ;
V_24 = F_22 ( V_8 ) -> V_35 ;
F_26 ( V_8 ) ;
V_24 -> V_30 -- ;
F_22 ( V_8 ) -> V_35 = NULL ;
F_20 ( V_8 ) -> V_34 = 0 ;
F_15 ( V_37 -> V_43 , V_24 ) ;
F_27 ( & V_22 -> V_42 ) ;
}
void F_28 ( struct V_7 * V_8 )
{
F_29 () ;
F_23 ( V_8 ) ;
F_30 () ;
}
int F_31 ( const struct V_7 * V_8 , struct V_7 * V_44 )
{
struct V_36 * V_45 = V_8 -> V_38 -> V_39 . V_37 ;
unsigned short V_27 = F_20 ( V_44 ) -> V_34 ;
const int V_40 = F_24 ( F_9 ( V_8 ) , V_27 ,
V_45 -> V_41 ) ;
struct V_21 * V_22 = & V_45 -> V_40 [ V_40 ] ;
struct V_18 * V_24 ;
F_25 ( & V_22 -> V_42 ) ;
V_24 = F_22 ( V_8 ) -> V_35 ;
if ( F_32 ( ! V_24 ) ) {
F_27 ( & V_22 -> V_42 ) ;
return - V_46 ;
}
if ( V_24 -> V_27 != V_27 ) {
F_33 (tb, &head->chain) {
if ( F_34 ( V_26 ( V_24 ) , F_9 ( V_8 ) ) &&
V_24 -> V_27 == V_27 )
break;
}
if ( ! V_24 ) {
V_24 = F_10 ( V_45 -> V_43 ,
F_9 ( V_8 ) , V_22 , V_27 ) ;
if ( ! V_24 ) {
F_27 ( & V_22 -> V_42 ) ;
return - V_47 ;
}
}
}
F_19 ( V_44 , V_24 , V_27 ) ;
F_27 ( & V_22 -> V_42 ) ;
return 0 ;
}
static inline int F_35 ( struct V_7 * V_8 , struct V_1 * V_1 ,
const unsigned short V_48 , const T_2 V_49 ,
const int V_50 )
{
int V_51 = - 1 ;
struct V_52 * V_53 = F_20 ( V_8 ) ;
if ( F_34 ( F_9 ( V_8 ) , V_1 ) && V_53 -> V_34 == V_48 &&
! F_36 ( V_8 ) ) {
T_2 V_54 = V_53 -> V_55 ;
V_51 = V_8 -> V_10 == V_56 ? 2 : 1 ;
if ( V_54 ) {
if ( V_54 != V_49 )
return - 1 ;
V_51 += 4 ;
}
if ( V_8 -> V_57 ) {
if ( V_8 -> V_57 != V_50 )
return - 1 ;
V_51 += 4 ;
}
if ( V_8 -> V_58 == F_37 () )
V_51 ++ ;
}
return V_51 ;
}
struct V_7 * F_38 ( struct V_1 * V_1 ,
struct V_36 * V_37 ,
const T_2 V_59 , T_4 V_60 ,
const T_2 V_49 , const unsigned short V_48 ,
const int V_50 )
{
struct V_7 * V_8 , * V_61 ;
struct V_62 * V_32 ;
unsigned int V_63 = F_39 ( V_1 , V_48 ) ;
struct V_64 * V_65 = & V_37 -> V_66 [ V_63 ] ;
int V_51 , V_67 , V_68 = 0 , V_69 = 0 ;
T_1 V_70 = 0 ;
F_40 () ;
V_71:
V_61 = NULL ;
V_67 = 0 ;
F_41 (sk, node, &ilb->head) {
V_51 = F_35 ( V_8 , V_1 , V_48 , V_49 , V_50 ) ;
if ( V_51 > V_67 ) {
V_61 = V_8 ;
V_67 = V_51 ;
V_69 = V_8 -> V_72 ;
if ( V_69 ) {
V_70 = F_1 ( V_1 , V_49 , V_48 ,
V_59 , V_60 ) ;
V_68 = 1 ;
}
} else if ( V_51 == V_67 && V_69 ) {
V_68 ++ ;
if ( F_42 ( V_70 , V_68 ) == 0 )
V_61 = V_8 ;
V_70 = F_43 ( V_70 ) ;
}
}
if ( F_44 ( V_32 ) != V_63 + V_73 )
goto V_71;
if ( V_61 ) {
if ( F_32 ( ! F_45 ( & V_61 -> V_74 ) ) )
V_61 = NULL ;
else if ( F_32 ( F_35 ( V_61 , V_1 , V_48 , V_49 ,
V_50 ) < V_67 ) ) {
F_46 ( V_61 ) ;
goto V_71;
}
}
F_47 () ;
return V_61 ;
}
void F_48 ( struct V_7 * V_8 )
{
if ( ! F_49 ( & V_8 -> V_74 ) )
return;
if ( V_8 -> V_75 == V_76 )
F_50 ( F_51 ( V_8 ) ) ;
else if ( V_8 -> V_75 == V_77 )
F_52 ( F_53 ( V_8 ) ) ;
else
F_54 ( V_8 ) ;
}
void F_55 ( struct V_78 * V_79 )
{
F_48 ( V_79 -> V_8 ) ;
}
struct V_7 * F_56 ( struct V_1 * V_1 ,
struct V_36 * V_37 ,
const T_2 V_59 , const T_4 V_60 ,
const T_2 V_49 , const T_6 V_48 ,
const int V_50 )
{
F_57 ( V_80 , V_59 , V_49 ) ;
const T_7 V_81 = F_58 ( V_60 , V_48 ) ;
struct V_7 * V_8 ;
const struct V_62 * V_32 ;
unsigned int V_63 = F_1 ( V_1 , V_49 , V_48 , V_59 , V_60 ) ;
unsigned int V_82 = V_63 & V_37 -> V_83 ;
struct V_84 * V_22 = & V_37 -> V_85 [ V_82 ] ;
F_40 () ;
V_71:
F_41 (sk, node, &head->chain) {
if ( V_8 -> V_86 != V_63 )
continue;
if ( F_59 ( F_60 ( V_8 , V_1 , V_80 ,
V_59 , V_49 , V_81 , V_50 ) ) ) {
if ( F_32 ( ! F_45 ( & V_8 -> V_74 ) ) )
goto V_87;
if ( F_32 ( ! F_60 ( V_8 , V_1 , V_80 ,
V_59 , V_49 , V_81 , V_50 ) ) ) {
F_48 ( V_8 ) ;
goto V_71;
}
goto V_88;
}
}
if ( F_44 ( V_32 ) != V_82 )
goto V_71;
V_87:
V_8 = NULL ;
V_88:
F_47 () ;
return V_8 ;
}
static int F_61 ( struct V_89 * V_90 ,
struct V_7 * V_8 , T_3 V_3 ,
struct V_91 * * V_92 )
{
struct V_36 * V_93 = V_90 -> V_37 ;
struct V_52 * V_53 = F_20 ( V_8 ) ;
T_2 V_49 = V_53 -> V_55 ;
T_2 V_59 = V_53 -> V_94 ;
int V_50 = V_8 -> V_57 ;
F_57 ( V_80 , V_59 , V_49 ) ;
const T_7 V_81 = F_58 ( V_53 -> V_95 , V_3 ) ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
unsigned int V_63 = F_1 ( V_1 , V_49 , V_3 ,
V_59 , V_53 -> V_95 ) ;
struct V_84 * V_22 = V_84 ( V_93 , V_63 ) ;
T_8 * V_42 = F_62 ( V_93 , V_63 ) ;
struct V_7 * V_96 ;
const struct V_62 * V_32 ;
struct V_91 * V_97 = NULL ;
F_25 ( V_42 ) ;
F_63 (sk2, node, &head->chain) {
if ( V_96 -> V_86 != V_63 )
continue;
if ( F_59 ( F_60 ( V_96 , V_1 , V_80 ,
V_59 , V_49 , V_81 , V_50 ) ) ) {
if ( V_96 -> V_75 == V_76 ) {
V_97 = F_51 ( V_96 ) ;
if ( F_64 ( V_8 , V_96 , V_92 ) )
break;
}
goto V_98;
}
}
V_53 -> V_34 = V_3 ;
V_53 -> V_99 = F_65 ( V_3 ) ;
V_8 -> V_86 = V_63 ;
F_66 ( ! F_67 ( V_8 ) ) ;
F_68 ( V_8 , & V_22 -> V_33 ) ;
if ( V_97 ) {
F_69 ( (struct V_7 * ) V_97 ) ;
F_70 ( V_1 , V_100 ) ;
}
F_27 ( V_42 ) ;
F_71 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
if ( V_92 ) {
* V_92 = V_97 ;
} else if ( V_97 ) {
F_72 ( V_97 ) ;
}
return 0 ;
V_98:
F_27 ( V_42 ) ;
return - V_101 ;
}
static T_1 F_73 ( const struct V_7 * V_8 )
{
const struct V_52 * V_53 = F_20 ( V_8 ) ;
return F_74 ( V_53 -> V_55 ,
V_53 -> V_94 ,
V_53 -> V_95 ) ;
}
bool F_75 ( struct V_7 * V_8 , struct V_7 * V_102 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
struct V_103 * V_104 ;
struct V_84 * V_22 ;
T_8 * V_42 ;
bool V_105 = true ;
F_76 ( ! F_67 ( V_8 ) ) ;
V_8 -> V_86 = F_5 ( V_8 ) ;
V_22 = V_84 ( V_37 , V_8 -> V_86 ) ;
V_104 = & V_22 -> V_33 ;
V_42 = F_62 ( V_37 , V_8 -> V_86 ) ;
F_25 ( V_42 ) ;
if ( V_102 ) {
F_76 ( V_8 -> V_86 != V_102 -> V_86 ) ;
V_105 = F_69 ( V_102 ) ;
}
if ( V_105 )
F_68 ( V_8 , V_104 ) ;
F_27 ( V_42 ) ;
return V_105 ;
}
bool F_77 ( struct V_7 * V_8 , struct V_7 * V_102 )
{
bool V_106 = F_75 ( V_8 , V_102 ) ;
if ( V_106 ) {
F_71 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
} else {
F_78 ( V_8 -> V_38 -> V_107 ) ;
V_8 -> V_75 = V_108 ;
F_79 ( V_8 , V_109 ) ;
F_80 ( V_8 ) ;
}
return V_106 ;
}
void F_81 ( struct V_7 * V_8 , struct V_7 * V_102 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
struct V_64 * V_65 ;
if ( V_8 -> V_75 != V_110 ) {
F_77 ( V_8 , V_102 ) ;
return;
}
F_66 ( ! F_67 ( V_8 ) ) ;
V_65 = & V_37 -> V_66 [ F_82 ( V_8 ) ] ;
F_25 ( & V_65 -> V_42 ) ;
F_68 ( V_8 , & V_65 -> V_22 ) ;
F_71 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
F_27 ( & V_65 -> V_42 ) ;
}
void F_83 ( struct V_7 * V_8 )
{
if ( V_8 -> V_75 != V_108 ) {
F_29 () ;
F_81 ( V_8 , NULL ) ;
F_30 () ;
}
}
void F_84 ( struct V_7 * V_8 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
T_8 * V_42 ;
int V_111 ;
if ( F_67 ( V_8 ) )
return;
if ( V_8 -> V_75 == V_110 )
V_42 = & V_37 -> V_66 [ F_82 ( V_8 ) ] . V_42 ;
else
V_42 = F_62 ( V_37 , V_8 -> V_86 ) ;
F_85 ( V_42 ) ;
V_111 = F_86 ( V_8 ) ;
if ( V_111 )
F_71 ( F_9 ( V_8 ) , V_8 -> V_38 , - 1 ) ;
F_87 ( V_42 ) ;
}
int F_88 ( struct V_89 * V_90 ,
struct V_7 * V_8 , T_1 V_112 ,
int (* F_89)( struct V_89 * ,
struct V_7 * , T_3 , struct V_91 * * ) )
{
struct V_36 * V_93 = V_90 -> V_37 ;
const unsigned short V_23 = F_20 ( V_8 ) -> V_34 ;
struct V_21 * V_22 ;
struct V_18 * V_24 ;
int V_105 ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
if ( ! V_23 ) {
int V_113 , V_114 , V_115 , V_116 , V_27 ;
static T_1 V_117 ;
T_1 V_118 = V_117 + V_112 ;
struct V_91 * V_97 = NULL ;
F_90 ( V_1 , & V_115 , & V_116 ) ;
V_114 = ( V_116 - V_115 ) + 1 ;
V_118 &= ~ 1 ;
F_29 () ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ ) {
V_27 = V_115 + ( V_113 + V_118 ) % V_114 ;
if ( F_91 ( V_1 , V_27 ) )
continue;
V_22 = & V_93 -> V_40 [ F_24 ( V_1 , V_27 ,
V_93 -> V_41 ) ] ;
F_25 ( & V_22 -> V_42 ) ;
F_33 (tb, &head->chain) {
if ( F_34 ( V_26 ( V_24 ) , V_1 ) &&
V_24 -> V_27 == V_27 ) {
if ( V_24 -> V_28 >= 0 ||
V_24 -> V_29 >= 0 )
goto V_119;
F_66 ( F_16 ( & V_24 -> V_31 ) ) ;
if ( ! F_89 ( V_90 , V_8 ,
V_27 , & V_97 ) )
goto V_106;
goto V_119;
}
}
V_24 = F_10 ( V_93 -> V_43 ,
V_1 , V_22 , V_27 ) ;
if ( ! V_24 ) {
F_27 ( & V_22 -> V_42 ) ;
break;
}
V_24 -> V_28 = - 1 ;
V_24 -> V_29 = - 1 ;
goto V_106;
V_119:
F_27 ( & V_22 -> V_42 ) ;
}
F_30 () ;
return - V_101 ;
V_106:
V_117 += ( V_113 + 2 ) & ~ 1 ;
F_19 ( V_8 , V_24 , V_27 ) ;
if ( F_67 ( V_8 ) ) {
F_20 ( V_8 ) -> V_99 = F_65 ( V_27 ) ;
F_77 ( V_8 , (struct V_7 * ) V_97 ) ;
}
if ( V_97 )
F_92 ( V_97 , V_93 ) ;
F_27 ( & V_22 -> V_42 ) ;
if ( V_97 )
F_72 ( V_97 ) ;
V_105 = 0 ;
goto V_87;
}
V_22 = & V_93 -> V_40 [ F_24 ( V_1 , V_23 , V_93 -> V_41 ) ] ;
V_24 = F_22 ( V_8 ) -> V_35 ;
F_85 ( & V_22 -> V_42 ) ;
if ( F_93 ( & V_24 -> V_31 ) == V_8 && ! V_8 -> V_120 . V_121 ) {
F_77 ( V_8 , NULL ) ;
F_87 ( & V_22 -> V_42 ) ;
return 0 ;
} else {
F_27 ( & V_22 -> V_42 ) ;
V_105 = F_89 ( V_90 , V_8 , V_23 , NULL ) ;
V_87:
F_30 () ;
return V_105 ;
}
}
int F_94 ( struct V_89 * V_90 ,
struct V_7 * V_8 )
{
T_1 V_112 = 0 ;
if ( ! F_20 ( V_8 ) -> V_34 )
V_112 = F_73 ( V_8 ) ;
return F_88 ( V_90 , V_8 , V_112 ,
F_61 ) ;
}
void F_95 ( struct V_36 * V_39 )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < V_122 ; V_113 ++ ) {
F_96 ( & V_39 -> V_66 [ V_113 ] . V_42 ) ;
F_97 ( & V_39 -> V_66 [ V_113 ] . V_22 ,
V_113 + V_73 ) ;
}
}
int F_98 ( struct V_36 * V_37 )
{
unsigned int V_123 = sizeof( T_8 ) ;
unsigned int V_113 , V_124 = 1 ;
if ( V_123 != 0 ) {
V_124 = F_99 ( 2U * V_125 / V_123 , 1U ) ;
V_124 = F_100 ( V_124 * F_101 () ) ;
V_124 = F_102 ( V_124 , V_37 -> V_83 + 1 ) ;
V_37 -> V_126 = F_103 ( V_124 , V_123 ,
V_127 | V_128 ) ;
if ( ! V_37 -> V_126 )
V_37 -> V_126 = F_104 ( V_124 * V_123 ) ;
if ( ! V_37 -> V_126 )
return - V_47 ;
for ( V_113 = 0 ; V_113 < V_124 ; V_113 ++ )
F_96 ( & V_37 -> V_126 [ V_113 ] ) ;
}
V_37 -> V_129 = V_124 - 1 ;
return 0 ;
}
