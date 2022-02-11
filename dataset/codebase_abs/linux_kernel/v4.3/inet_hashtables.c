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
int F_31 ( struct V_7 * V_8 , struct V_7 * V_44 )
{
struct V_36 * V_45 = V_8 -> V_38 -> V_39 . V_37 ;
unsigned short V_27 = F_20 ( V_44 ) -> V_34 ;
const int V_40 = F_24 ( F_9 ( V_8 ) , V_27 ,
V_45 -> V_41 ) ;
struct V_21 * V_22 = & V_45 -> V_40 [ V_40 ] ;
struct V_18 * V_24 ;
F_25 ( & V_22 -> V_42 ) ;
V_24 = F_22 ( V_8 ) -> V_35 ;
if ( V_24 -> V_27 != V_27 ) {
F_32 (tb, &head->chain) {
if ( F_33 ( V_26 ( V_24 ) , F_9 ( V_8 ) ) &&
V_24 -> V_27 == V_27 )
break;
}
if ( ! V_24 ) {
V_24 = F_10 ( V_45 -> V_43 ,
F_9 ( V_8 ) , V_22 , V_27 ) ;
if ( ! V_24 ) {
F_27 ( & V_22 -> V_42 ) ;
return - V_46 ;
}
}
}
F_19 ( V_44 , V_24 , V_27 ) ;
F_27 ( & V_22 -> V_42 ) ;
return 0 ;
}
static inline int F_34 ( struct V_7 * V_8 , struct V_1 * V_1 ,
const unsigned short V_47 , const T_2 V_48 ,
const int V_49 )
{
int V_50 = - 1 ;
struct V_51 * V_52 = F_20 ( V_8 ) ;
if ( F_33 ( F_9 ( V_8 ) , V_1 ) && V_52 -> V_34 == V_47 &&
! F_35 ( V_8 ) ) {
T_2 V_53 = V_52 -> V_54 ;
V_50 = V_8 -> V_10 == V_55 ? 2 : 1 ;
if ( V_53 ) {
if ( V_53 != V_48 )
return - 1 ;
V_50 += 4 ;
}
if ( V_8 -> V_56 ) {
if ( V_8 -> V_56 != V_49 )
return - 1 ;
V_50 += 4 ;
}
}
return V_50 ;
}
struct V_7 * F_36 ( struct V_1 * V_1 ,
struct V_36 * V_37 ,
const T_2 V_57 , T_4 V_58 ,
const T_2 V_48 , const unsigned short V_47 ,
const int V_49 )
{
struct V_7 * V_8 , * V_59 ;
struct V_60 * V_32 ;
unsigned int V_61 = F_37 ( V_1 , V_47 ) ;
struct V_62 * V_63 = & V_37 -> V_64 [ V_61 ] ;
int V_50 , V_65 , V_66 = 0 , V_67 = 0 ;
T_1 V_68 = 0 ;
F_38 () ;
V_69:
V_59 = NULL ;
V_65 = 0 ;
F_39 (sk, node, &ilb->head) {
V_50 = F_34 ( V_8 , V_1 , V_47 , V_48 , V_49 ) ;
if ( V_50 > V_65 ) {
V_59 = V_8 ;
V_65 = V_50 ;
V_67 = V_8 -> V_70 ;
if ( V_67 ) {
V_68 = F_1 ( V_1 , V_48 , V_47 ,
V_57 , V_58 ) ;
V_66 = 1 ;
}
} else if ( V_50 == V_65 && V_67 ) {
V_66 ++ ;
if ( F_40 ( V_68 , V_66 ) == 0 )
V_59 = V_8 ;
V_68 = F_41 ( V_68 ) ;
}
}
if ( F_42 ( V_32 ) != V_61 + V_71 )
goto V_69;
if ( V_59 ) {
if ( F_43 ( ! F_44 ( & V_59 -> V_72 ) ) )
V_59 = NULL ;
else if ( F_43 ( F_34 ( V_59 , V_1 , V_47 , V_48 ,
V_49 ) < V_65 ) ) {
F_45 ( V_59 ) ;
goto V_69;
}
}
F_46 () ;
return V_59 ;
}
void F_47 ( struct V_7 * V_8 )
{
if ( ! F_48 ( & V_8 -> V_72 ) )
return;
if ( V_8 -> V_73 == V_74 )
F_49 ( F_50 ( V_8 ) ) ;
else if ( V_8 -> V_73 == V_75 )
F_51 ( F_52 ( V_8 ) ) ;
else
F_53 ( V_8 ) ;
}
void F_54 ( struct V_76 * V_77 )
{
F_47 ( V_77 -> V_8 ) ;
}
struct V_7 * F_55 ( struct V_1 * V_1 ,
struct V_36 * V_37 ,
const T_2 V_57 , const T_4 V_58 ,
const T_2 V_48 , const T_6 V_47 ,
const int V_49 )
{
F_56 ( V_78 , V_57 , V_48 ) ;
const T_7 V_79 = F_57 ( V_58 , V_47 ) ;
struct V_7 * V_8 ;
const struct V_60 * V_32 ;
unsigned int V_61 = F_1 ( V_1 , V_48 , V_47 , V_57 , V_58 ) ;
unsigned int V_80 = V_61 & V_37 -> V_81 ;
struct V_82 * V_22 = & V_37 -> V_83 [ V_80 ] ;
F_38 () ;
V_69:
F_39 (sk, node, &head->chain) {
if ( V_8 -> V_84 != V_61 )
continue;
if ( F_58 ( F_59 ( V_8 , V_1 , V_78 ,
V_57 , V_48 , V_79 , V_49 ) ) ) {
if ( F_43 ( ! F_44 ( & V_8 -> V_72 ) ) )
goto V_85;
if ( F_43 ( ! F_59 ( V_8 , V_1 , V_78 ,
V_57 , V_48 , V_79 , V_49 ) ) ) {
F_47 ( V_8 ) ;
goto V_69;
}
goto V_86;
}
}
if ( F_42 ( V_32 ) != V_80 )
goto V_69;
V_85:
V_8 = NULL ;
V_86:
F_46 () ;
return V_8 ;
}
static int F_60 ( struct V_87 * V_88 ,
struct V_7 * V_8 , T_3 V_3 ,
struct V_89 * * V_90 )
{
struct V_36 * V_91 = V_88 -> V_37 ;
struct V_51 * V_52 = F_20 ( V_8 ) ;
T_2 V_48 = V_52 -> V_54 ;
T_2 V_57 = V_52 -> V_92 ;
int V_49 = V_8 -> V_56 ;
F_56 ( V_78 , V_57 , V_48 ) ;
const T_7 V_79 = F_57 ( V_52 -> V_93 , V_3 ) ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
unsigned int V_61 = F_1 ( V_1 , V_48 , V_3 ,
V_57 , V_52 -> V_93 ) ;
struct V_82 * V_22 = V_82 ( V_91 , V_61 ) ;
T_8 * V_42 = F_61 ( V_91 , V_61 ) ;
struct V_7 * V_94 ;
const struct V_60 * V_32 ;
struct V_89 * V_95 = NULL ;
F_25 ( V_42 ) ;
F_62 (sk2, node, &head->chain) {
if ( V_94 -> V_84 != V_61 )
continue;
if ( F_58 ( F_59 ( V_94 , V_1 , V_78 ,
V_57 , V_48 , V_79 , V_49 ) ) ) {
if ( V_94 -> V_73 == V_74 ) {
V_95 = F_50 ( V_94 ) ;
if ( F_63 ( V_8 , V_94 , V_90 ) )
break;
}
goto V_96;
}
}
V_52 -> V_34 = V_3 ;
V_52 -> V_97 = F_64 ( V_3 ) ;
V_8 -> V_84 = V_61 ;
F_65 ( ! F_66 ( V_8 ) ) ;
F_67 ( V_8 , & V_22 -> V_33 ) ;
if ( V_95 ) {
F_68 ( (struct V_7 * ) V_95 ) ;
F_69 ( V_1 , V_98 ) ;
}
F_27 ( V_42 ) ;
F_70 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
if ( V_90 ) {
* V_90 = V_95 ;
} else if ( V_95 ) {
F_71 ( V_95 ) ;
}
return 0 ;
V_96:
F_27 ( V_42 ) ;
return - V_99 ;
}
static T_1 F_72 ( const struct V_7 * V_8 )
{
const struct V_51 * V_52 = F_20 ( V_8 ) ;
return F_73 ( V_52 -> V_54 ,
V_52 -> V_92 ,
V_52 -> V_93 ) ;
}
void F_74 ( struct V_7 * V_8 , struct V_7 * V_100 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
struct V_101 * V_102 ;
struct V_82 * V_22 ;
T_8 * V_42 ;
F_65 ( ! F_66 ( V_8 ) ) ;
V_8 -> V_84 = F_5 ( V_8 ) ;
V_22 = V_82 ( V_37 , V_8 -> V_84 ) ;
V_102 = & V_22 -> V_33 ;
V_42 = F_61 ( V_37 , V_8 -> V_84 ) ;
F_25 ( V_42 ) ;
F_67 ( V_8 , V_102 ) ;
if ( V_100 ) {
F_65 ( V_8 -> V_84 != V_100 -> V_84 ) ;
F_68 ( V_100 ) ;
}
F_27 ( V_42 ) ;
F_70 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
}
void F_75 ( struct V_7 * V_8 , struct V_7 * V_100 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
struct V_62 * V_63 ;
if ( V_8 -> V_73 != V_103 )
return F_74 ( V_8 , V_100 ) ;
F_65 ( ! F_66 ( V_8 ) ) ;
V_63 = & V_37 -> V_64 [ F_76 ( V_8 ) ] ;
F_25 ( & V_63 -> V_42 ) ;
F_67 ( V_8 , & V_63 -> V_22 ) ;
F_70 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
F_27 ( & V_63 -> V_42 ) ;
}
void F_77 ( struct V_7 * V_8 )
{
if ( V_8 -> V_73 != V_104 ) {
F_29 () ;
F_75 ( V_8 , NULL ) ;
F_30 () ;
}
}
void F_78 ( struct V_7 * V_8 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
T_8 * V_42 ;
int V_105 ;
if ( F_66 ( V_8 ) )
return;
if ( V_8 -> V_73 == V_103 )
V_42 = & V_37 -> V_64 [ F_76 ( V_8 ) ] . V_42 ;
else
V_42 = F_61 ( V_37 , V_8 -> V_84 ) ;
F_79 ( V_42 ) ;
V_105 = F_80 ( V_8 ) ;
if ( V_105 )
F_70 ( F_9 ( V_8 ) , V_8 -> V_38 , - 1 ) ;
F_81 ( V_42 ) ;
}
int F_82 ( struct V_87 * V_88 ,
struct V_7 * V_8 , T_1 V_106 ,
int (* F_83)( struct V_87 * ,
struct V_7 * , T_3 , struct V_89 * * ) )
{
struct V_36 * V_91 = V_88 -> V_37 ;
const unsigned short V_23 = F_20 ( V_8 ) -> V_34 ;
struct V_21 * V_22 ;
struct V_18 * V_24 ;
int V_107 ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
if ( ! V_23 ) {
int V_108 , V_109 , V_110 , V_111 , V_27 ;
static T_1 V_112 ;
T_1 V_113 = V_112 + V_106 ;
struct V_89 * V_95 = NULL ;
F_84 ( V_1 , & V_110 , & V_111 ) ;
V_109 = ( V_111 - V_110 ) + 1 ;
V_113 &= ~ 1 ;
F_29 () ;
for ( V_108 = 0 ; V_108 < V_109 ; V_108 ++ ) {
V_27 = V_110 + ( V_108 + V_113 ) % V_109 ;
if ( F_85 ( V_1 , V_27 ) )
continue;
V_22 = & V_91 -> V_40 [ F_24 ( V_1 , V_27 ,
V_91 -> V_41 ) ] ;
F_25 ( & V_22 -> V_42 ) ;
F_32 (tb, &head->chain) {
if ( F_33 ( V_26 ( V_24 ) , V_1 ) &&
V_24 -> V_27 == V_27 ) {
if ( V_24 -> V_28 >= 0 ||
V_24 -> V_29 >= 0 )
goto V_114;
F_65 ( F_16 ( & V_24 -> V_31 ) ) ;
if ( ! F_83 ( V_88 , V_8 ,
V_27 , & V_95 ) )
goto V_115;
goto V_114;
}
}
V_24 = F_10 ( V_91 -> V_43 ,
V_1 , V_22 , V_27 ) ;
if ( ! V_24 ) {
F_27 ( & V_22 -> V_42 ) ;
break;
}
V_24 -> V_28 = - 1 ;
V_24 -> V_29 = - 1 ;
goto V_115;
V_114:
F_27 ( & V_22 -> V_42 ) ;
}
F_30 () ;
return - V_99 ;
V_115:
V_112 += ( V_108 + 2 ) & ~ 1 ;
F_19 ( V_8 , V_24 , V_27 ) ;
if ( F_66 ( V_8 ) ) {
F_20 ( V_8 ) -> V_97 = F_64 ( V_27 ) ;
F_74 ( V_8 , (struct V_7 * ) V_95 ) ;
}
if ( V_95 )
F_86 ( V_95 , V_91 ) ;
F_27 ( & V_22 -> V_42 ) ;
if ( V_95 )
F_71 ( V_95 ) ;
V_107 = 0 ;
goto V_85;
}
V_22 = & V_91 -> V_40 [ F_24 ( V_1 , V_23 , V_91 -> V_41 ) ] ;
V_24 = F_22 ( V_8 ) -> V_35 ;
F_79 ( & V_22 -> V_42 ) ;
if ( F_87 ( & V_24 -> V_31 ) == V_8 && ! V_8 -> V_116 . V_117 ) {
F_74 ( V_8 , NULL ) ;
F_81 ( & V_22 -> V_42 ) ;
return 0 ;
} else {
F_27 ( & V_22 -> V_42 ) ;
V_107 = F_83 ( V_88 , V_8 , V_23 , NULL ) ;
V_85:
F_30 () ;
return V_107 ;
}
}
int F_88 ( struct V_87 * V_88 ,
struct V_7 * V_8 )
{
T_1 V_106 = 0 ;
if ( ! F_20 ( V_8 ) -> V_34 )
V_106 = F_72 ( V_8 ) ;
return F_82 ( V_88 , V_8 , V_106 ,
F_60 ) ;
}
void F_89 ( struct V_36 * V_39 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_118 ; V_108 ++ ) {
F_90 ( & V_39 -> V_64 [ V_108 ] . V_42 ) ;
F_91 ( & V_39 -> V_64 [ V_108 ] . V_22 ,
V_108 + V_71 ) ;
}
}
int F_92 ( struct V_36 * V_37 )
{
unsigned int V_119 = sizeof( T_8 ) ;
unsigned int V_108 , V_120 = 1 ;
if ( V_119 != 0 ) {
V_120 = F_93 ( 2U * V_121 / V_119 , 1U ) ;
V_120 = F_94 ( V_120 * F_95 () ) ;
V_120 = F_96 ( V_120 , V_37 -> V_81 + 1 ) ;
V_37 -> V_122 = F_97 ( V_120 , V_119 ,
V_123 | V_124 ) ;
if ( ! V_37 -> V_122 )
V_37 -> V_122 = F_98 ( V_120 * V_119 ) ;
if ( ! V_37 -> V_122 )
return - V_46 ;
for ( V_108 = 0 ; V_108 < V_120 ; V_108 ++ )
F_90 ( & V_37 -> V_122 [ V_108 ] ) ;
}
V_37 -> V_125 = V_120 - 1 ;
return 0 ;
}
