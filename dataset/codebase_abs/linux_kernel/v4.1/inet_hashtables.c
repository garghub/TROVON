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
struct V_34 * V_35 = V_8 -> V_36 -> V_37 . V_35 ;
F_20 ( & V_35 -> V_38 ) ;
F_21 ( V_8 ) -> V_39 = V_23 ;
F_22 ( V_8 , & V_24 -> V_31 ) ;
V_24 -> V_30 ++ ;
F_23 ( V_8 ) -> V_40 = V_24 ;
}
static void F_24 ( struct V_7 * V_8 )
{
struct V_34 * V_35 = V_8 -> V_36 -> V_37 . V_35 ;
const int V_41 = F_25 ( F_9 ( V_8 ) , F_21 ( V_8 ) -> V_39 ,
V_35 -> V_42 ) ;
struct V_21 * V_22 = & V_35 -> V_41 [ V_41 ] ;
struct V_18 * V_24 ;
F_26 ( & V_35 -> V_38 ) ;
F_27 ( & V_22 -> V_43 ) ;
V_24 = F_23 ( V_8 ) -> V_40 ;
F_28 ( V_8 ) ;
V_24 -> V_30 -- ;
F_23 ( V_8 ) -> V_40 = NULL ;
F_21 ( V_8 ) -> V_39 = 0 ;
F_15 ( V_35 -> V_44 , V_24 ) ;
F_29 ( & V_22 -> V_43 ) ;
}
void F_30 ( struct V_7 * V_8 )
{
F_31 () ;
F_24 ( V_8 ) ;
F_32 () ;
}
int F_33 ( struct V_7 * V_8 , struct V_7 * V_45 )
{
struct V_34 * V_46 = V_8 -> V_36 -> V_37 . V_35 ;
unsigned short V_27 = F_21 ( V_45 ) -> V_39 ;
const int V_41 = F_25 ( F_9 ( V_8 ) , V_27 ,
V_46 -> V_42 ) ;
struct V_21 * V_22 = & V_46 -> V_41 [ V_41 ] ;
struct V_18 * V_24 ;
F_27 ( & V_22 -> V_43 ) ;
V_24 = F_23 ( V_8 ) -> V_40 ;
if ( V_24 -> V_27 != V_27 ) {
F_34 (tb, &head->chain) {
if ( F_35 ( V_26 ( V_24 ) , F_9 ( V_8 ) ) &&
V_24 -> V_27 == V_27 )
break;
}
if ( ! V_24 ) {
V_24 = F_10 ( V_46 -> V_44 ,
F_9 ( V_8 ) , V_22 , V_27 ) ;
if ( ! V_24 ) {
F_29 ( & V_22 -> V_43 ) ;
return - V_47 ;
}
}
}
F_19 ( V_45 , V_24 , V_27 ) ;
F_29 ( & V_22 -> V_43 ) ;
return 0 ;
}
static inline int F_36 ( struct V_7 * V_8 , struct V_1 * V_1 ,
const unsigned short V_48 , const T_2 V_49 ,
const int V_50 )
{
int V_51 = - 1 ;
struct V_52 * V_53 = F_21 ( V_8 ) ;
if ( F_35 ( F_9 ( V_8 ) , V_1 ) && V_53 -> V_39 == V_48 &&
! F_37 ( V_8 ) ) {
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
}
return V_51 ;
}
struct V_7 * F_38 ( struct V_1 * V_1 ,
struct V_34 * V_35 ,
const T_2 V_58 , T_4 V_59 ,
const T_2 V_49 , const unsigned short V_48 ,
const int V_50 )
{
struct V_7 * V_8 , * V_60 ;
struct V_61 * V_32 ;
unsigned int V_62 = F_39 ( V_1 , V_48 ) ;
struct V_63 * V_64 = & V_35 -> V_65 [ V_62 ] ;
int V_51 , V_66 , V_67 = 0 , V_68 = 0 ;
T_1 V_69 = 0 ;
F_40 () ;
V_70:
V_60 = NULL ;
V_66 = 0 ;
F_41 (sk, node, &ilb->head) {
V_51 = F_36 ( V_8 , V_1 , V_48 , V_49 , V_50 ) ;
if ( V_51 > V_66 ) {
V_60 = V_8 ;
V_66 = V_51 ;
V_68 = V_8 -> V_71 ;
if ( V_68 ) {
V_69 = F_1 ( V_1 , V_49 , V_48 ,
V_58 , V_59 ) ;
V_67 = 1 ;
}
} else if ( V_51 == V_66 && V_68 ) {
V_67 ++ ;
if ( F_42 ( V_69 , V_67 ) == 0 )
V_60 = V_8 ;
V_69 = F_43 ( V_69 ) ;
}
}
if ( F_44 ( V_32 ) != V_62 + V_72 )
goto V_70;
if ( V_60 ) {
if ( F_45 ( ! F_46 ( & V_60 -> V_73 ) ) )
V_60 = NULL ;
else if ( F_45 ( F_36 ( V_60 , V_1 , V_48 , V_49 ,
V_50 ) < V_66 ) ) {
F_47 ( V_60 ) ;
goto V_70;
}
}
F_48 () ;
return V_60 ;
}
void F_49 ( struct V_7 * V_8 )
{
if ( ! F_50 ( & V_8 -> V_73 ) )
return;
if ( V_8 -> V_74 == V_75 )
F_51 ( F_52 ( V_8 ) ) ;
else if ( V_8 -> V_74 == V_76 )
F_53 ( F_54 ( V_8 ) ) ;
else
F_55 ( V_8 ) ;
}
void F_56 ( struct V_77 * V_78 )
{
F_49 ( V_78 -> V_8 ) ;
}
struct V_7 * F_57 ( struct V_1 * V_1 ,
struct V_34 * V_35 ,
const T_2 V_58 , const T_4 V_59 ,
const T_2 V_49 , const T_6 V_48 ,
const int V_50 )
{
F_58 ( V_79 , V_58 , V_49 ) ;
const T_7 V_80 = F_59 ( V_59 , V_48 ) ;
struct V_7 * V_8 ;
const struct V_61 * V_32 ;
unsigned int V_62 = F_1 ( V_1 , V_49 , V_48 , V_58 , V_59 ) ;
unsigned int V_81 = V_62 & V_35 -> V_82 ;
struct V_83 * V_22 = & V_35 -> V_84 [ V_81 ] ;
F_40 () ;
V_70:
F_41 (sk, node, &head->chain) {
if ( V_8 -> V_85 != V_62 )
continue;
if ( F_60 ( F_61 ( V_8 , V_1 , V_79 ,
V_58 , V_49 , V_80 , V_50 ) ) ) {
if ( F_45 ( ! F_46 ( & V_8 -> V_73 ) ) )
goto V_86;
if ( F_45 ( ! F_61 ( V_8 , V_1 , V_79 ,
V_58 , V_49 , V_80 , V_50 ) ) ) {
F_49 ( V_8 ) ;
goto V_70;
}
goto V_87;
}
}
if ( F_44 ( V_32 ) != V_81 )
goto V_70;
V_86:
V_8 = NULL ;
V_87:
F_48 () ;
return V_8 ;
}
static int F_62 ( struct V_88 * V_89 ,
struct V_7 * V_8 , T_3 V_3 ,
struct V_90 * * V_91 )
{
struct V_34 * V_92 = V_89 -> V_35 ;
struct V_52 * V_53 = F_21 ( V_8 ) ;
T_2 V_49 = V_53 -> V_55 ;
T_2 V_58 = V_53 -> V_93 ;
int V_50 = V_8 -> V_57 ;
F_58 ( V_79 , V_58 , V_49 ) ;
const T_7 V_80 = F_59 ( V_53 -> V_94 , V_3 ) ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
unsigned int V_62 = F_1 ( V_1 , V_49 , V_3 ,
V_58 , V_53 -> V_94 ) ;
struct V_83 * V_22 = V_83 ( V_92 , V_62 ) ;
T_8 * V_43 = F_63 ( V_92 , V_62 ) ;
struct V_7 * V_95 ;
const struct V_61 * V_32 ;
struct V_90 * V_96 = NULL ;
int V_97 = 0 ;
F_27 ( V_43 ) ;
F_64 (sk2, node, &head->chain) {
if ( V_95 -> V_85 != V_62 )
continue;
if ( F_60 ( F_61 ( V_95 , V_1 , V_79 ,
V_58 , V_49 , V_80 , V_50 ) ) ) {
if ( V_95 -> V_74 == V_75 ) {
V_96 = F_52 ( V_95 ) ;
if ( F_65 ( V_8 , V_95 , V_91 ) )
break;
}
goto V_98;
}
}
V_53 -> V_39 = V_3 ;
V_53 -> V_99 = F_66 ( V_3 ) ;
V_8 -> V_85 = V_62 ;
F_67 ( ! F_68 ( V_8 ) ) ;
F_69 ( V_8 , & V_22 -> V_33 ) ;
if ( V_96 ) {
V_97 = F_70 ( V_96 ) ;
F_71 ( V_1 , V_100 ) ;
}
F_29 ( V_43 ) ;
if ( V_97 )
F_72 ( V_96 ) ;
F_73 ( F_9 ( V_8 ) , V_8 -> V_36 , 1 ) ;
if ( V_91 ) {
* V_91 = V_96 ;
} else if ( V_96 ) {
F_74 ( V_96 ) ;
F_72 ( V_96 ) ;
}
return 0 ;
V_98:
F_29 ( V_43 ) ;
return - V_101 ;
}
static inline T_1 F_75 ( const struct V_7 * V_8 )
{
const struct V_52 * V_53 = F_21 ( V_8 ) ;
return F_76 ( V_53 -> V_55 ,
V_53 -> V_93 ,
V_53 -> V_94 ) ;
}
int F_77 ( struct V_7 * V_8 , struct V_90 * V_96 )
{
struct V_34 * V_35 = V_8 -> V_36 -> V_37 . V_35 ;
struct V_102 * V_103 ;
struct V_83 * V_22 ;
T_8 * V_43 ;
int V_97 = 0 ;
F_67 ( ! F_68 ( V_8 ) ) ;
V_8 -> V_85 = F_5 ( V_8 ) ;
V_22 = V_83 ( V_35 , V_8 -> V_85 ) ;
V_103 = & V_22 -> V_33 ;
V_43 = F_63 ( V_35 , V_8 -> V_85 ) ;
F_27 ( V_43 ) ;
F_69 ( V_8 , V_103 ) ;
if ( V_96 ) {
F_67 ( V_8 -> V_85 != V_96 -> V_104 ) ;
V_97 = F_70 ( V_96 ) ;
}
F_29 ( V_43 ) ;
F_73 ( F_9 ( V_8 ) , V_8 -> V_36 , 1 ) ;
return V_97 ;
}
int F_78 ( struct V_7 * V_8 , struct V_90 * V_96 )
{
struct V_34 * V_35 = V_8 -> V_36 -> V_37 . V_35 ;
struct V_63 * V_64 ;
if ( V_8 -> V_74 != V_105 )
return F_77 ( V_8 , V_96 ) ;
F_67 ( ! F_68 ( V_8 ) ) ;
V_64 = & V_35 -> V_65 [ F_79 ( V_8 ) ] ;
F_27 ( & V_64 -> V_43 ) ;
F_69 ( V_8 , & V_64 -> V_22 ) ;
F_73 ( F_9 ( V_8 ) , V_8 -> V_36 , 1 ) ;
F_29 ( & V_64 -> V_43 ) ;
return 0 ;
}
void F_80 ( struct V_7 * V_8 )
{
if ( V_8 -> V_74 != V_106 ) {
F_31 () ;
F_78 ( V_8 , NULL ) ;
F_32 () ;
}
}
void F_81 ( struct V_7 * V_8 )
{
struct V_34 * V_35 = V_8 -> V_36 -> V_37 . V_35 ;
T_8 * V_43 ;
int V_107 ;
if ( F_68 ( V_8 ) )
return;
if ( V_8 -> V_74 == V_105 )
V_43 = & V_35 -> V_65 [ F_79 ( V_8 ) ] . V_43 ;
else
V_43 = F_63 ( V_35 , V_8 -> V_85 ) ;
F_82 ( V_43 ) ;
V_107 = F_83 ( V_8 ) ;
if ( V_107 )
F_73 ( F_9 ( V_8 ) , V_8 -> V_36 , - 1 ) ;
F_84 ( V_43 ) ;
}
int F_85 ( struct V_88 * V_89 ,
struct V_7 * V_8 , T_1 V_108 ,
int (* F_86)( struct V_88 * ,
struct V_7 * , T_3 , struct V_90 * * ) )
{
struct V_34 * V_92 = V_89 -> V_35 ;
const unsigned short V_23 = F_21 ( V_8 ) -> V_39 ;
struct V_21 * V_22 ;
struct V_18 * V_24 ;
int V_109 ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
int V_97 = 1 ;
if ( ! V_23 ) {
int V_110 , V_111 , V_112 , V_113 , V_27 ;
static T_1 V_114 ;
T_1 V_115 = V_114 + V_108 ;
struct V_90 * V_96 = NULL ;
F_87 ( V_1 , & V_112 , & V_113 ) ;
V_111 = ( V_113 - V_112 ) + 1 ;
F_31 () ;
for ( V_110 = 1 ; V_110 <= V_111 ; V_110 ++ ) {
V_27 = V_112 + ( V_110 + V_115 ) % V_111 ;
if ( F_88 ( V_1 , V_27 ) )
continue;
V_22 = & V_92 -> V_41 [ F_25 ( V_1 , V_27 ,
V_92 -> V_42 ) ] ;
F_27 ( & V_22 -> V_43 ) ;
F_34 (tb, &head->chain) {
if ( F_35 ( V_26 ( V_24 ) , V_1 ) &&
V_24 -> V_27 == V_27 ) {
if ( V_24 -> V_28 >= 0 ||
V_24 -> V_29 >= 0 )
goto V_116;
F_67 ( F_16 ( & V_24 -> V_31 ) ) ;
if ( ! F_86 ( V_89 , V_8 ,
V_27 , & V_96 ) )
goto V_117;
goto V_116;
}
}
V_24 = F_10 ( V_92 -> V_44 ,
V_1 , V_22 , V_27 ) ;
if ( ! V_24 ) {
F_29 ( & V_22 -> V_43 ) ;
break;
}
V_24 -> V_28 = - 1 ;
V_24 -> V_29 = - 1 ;
goto V_117;
V_116:
F_29 ( & V_22 -> V_43 ) ;
}
F_32 () ;
return - V_101 ;
V_117:
V_114 += V_110 ;
F_19 ( V_8 , V_24 , V_27 ) ;
if ( F_68 ( V_8 ) ) {
F_21 ( V_8 ) -> V_99 = F_66 ( V_27 ) ;
V_97 += F_77 ( V_8 , V_96 ) ;
}
if ( V_96 )
V_97 += F_89 ( V_96 , V_92 ) ;
F_29 ( & V_22 -> V_43 ) ;
if ( V_96 ) {
F_74 ( V_96 ) ;
while ( V_97 ) {
V_97 -- ;
F_72 ( V_96 ) ;
}
}
V_109 = 0 ;
goto V_86;
}
V_22 = & V_92 -> V_41 [ F_25 ( V_1 , V_23 , V_92 -> V_42 ) ] ;
V_24 = F_23 ( V_8 ) -> V_40 ;
F_82 ( & V_22 -> V_43 ) ;
if ( F_90 ( & V_24 -> V_31 ) == V_8 && ! V_8 -> V_118 . V_119 ) {
F_77 ( V_8 , NULL ) ;
F_84 ( & V_22 -> V_43 ) ;
return 0 ;
} else {
F_29 ( & V_22 -> V_43 ) ;
V_109 = F_86 ( V_89 , V_8 , V_23 , NULL ) ;
V_86:
F_32 () ;
return V_109 ;
}
}
int F_91 ( struct V_88 * V_89 ,
struct V_7 * V_8 )
{
return F_85 ( V_89 , V_8 , F_75 ( V_8 ) ,
F_62 ) ;
}
void F_92 ( struct V_34 * V_37 )
{
int V_110 ;
F_93 ( & V_37 -> V_38 , 0 ) ;
for ( V_110 = 0 ; V_110 < V_120 ; V_110 ++ ) {
F_94 ( & V_37 -> V_65 [ V_110 ] . V_43 ) ;
F_95 ( & V_37 -> V_65 [ V_110 ] . V_22 ,
V_110 + V_72 ) ;
}
}
