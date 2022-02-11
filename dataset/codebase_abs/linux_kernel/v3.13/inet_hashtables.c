static unsigned int F_1 ( struct V_1 * V_1 , const T_1 V_2 ,
const T_2 V_3 , const T_1 V_4 ,
const T_3 V_5 )
{
static T_4 T_5 V_6 ;
F_2 ( & T_5 , sizeof( T_5 ) ) ;
return F_3 ( V_2 , V_3 , V_4 , V_5 ,
T_5 + F_4 ( V_1 ) ) ;
}
static unsigned int F_5 ( const struct V_7 * V_8 )
{
const struct V_9 * V_10 = F_6 ( V_8 ) ;
const T_1 V_2 = V_10 -> V_11 ;
const T_2 V_3 = V_10 -> V_12 ;
const T_1 V_4 = V_10 -> V_13 ;
const T_3 V_5 = V_10 -> V_14 ;
struct V_1 * V_1 = F_7 ( V_8 ) ;
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
}
struct V_15 * F_8 ( struct V_16 * V_17 ,
struct V_1 * V_1 ,
struct V_18 * V_19 ,
const unsigned short V_20 )
{
struct V_15 * V_21 = F_9 ( V_17 , V_22 ) ;
if ( V_21 != NULL ) {
F_10 ( & V_21 -> V_23 , F_11 ( V_1 ) ) ;
V_21 -> V_24 = V_20 ;
V_21 -> V_25 = 0 ;
V_21 -> V_26 = 0 ;
V_21 -> V_27 = 0 ;
F_12 ( & V_21 -> V_28 ) ;
F_13 ( & V_21 -> V_29 , & V_19 -> V_30 ) ;
}
return V_21 ;
}
void F_14 ( struct V_16 * V_17 , struct V_15 * V_21 )
{
if ( F_15 ( & V_21 -> V_28 ) ) {
F_16 ( & V_21 -> V_29 ) ;
F_17 ( V_23 ( V_21 ) ) ;
F_18 ( V_17 , V_21 ) ;
}
}
void F_19 ( struct V_7 * V_8 , struct V_15 * V_21 ,
const unsigned short V_20 )
{
struct V_31 * V_32 = V_8 -> V_33 -> V_34 . V_32 ;
F_20 ( & V_32 -> V_35 ) ;
F_6 ( V_8 ) -> V_12 = V_20 ;
F_21 ( V_8 , & V_21 -> V_28 ) ;
V_21 -> V_27 ++ ;
F_22 ( V_8 ) -> V_36 = V_21 ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = V_8 -> V_33 -> V_34 . V_32 ;
const int V_37 = F_24 ( F_7 ( V_8 ) , F_6 ( V_8 ) -> V_12 ,
V_32 -> V_38 ) ;
struct V_18 * V_19 = & V_32 -> V_37 [ V_37 ] ;
struct V_15 * V_21 ;
F_25 ( & V_32 -> V_35 ) ;
F_26 ( & V_19 -> V_39 ) ;
V_21 = F_22 ( V_8 ) -> V_36 ;
F_27 ( V_8 ) ;
V_21 -> V_27 -- ;
F_22 ( V_8 ) -> V_36 = NULL ;
F_6 ( V_8 ) -> V_12 = 0 ;
F_14 ( V_32 -> V_40 , V_21 ) ;
F_28 ( & V_19 -> V_39 ) ;
}
void F_29 ( struct V_7 * V_8 )
{
F_30 () ;
F_23 ( V_8 ) ;
F_31 () ;
}
int F_32 ( struct V_7 * V_8 , struct V_7 * V_41 )
{
struct V_31 * V_42 = V_8 -> V_33 -> V_34 . V_32 ;
unsigned short V_24 = F_6 ( V_41 ) -> V_12 ;
const int V_37 = F_24 ( F_7 ( V_8 ) , V_24 ,
V_42 -> V_38 ) ;
struct V_18 * V_19 = & V_42 -> V_37 [ V_37 ] ;
struct V_15 * V_21 ;
F_26 ( & V_19 -> V_39 ) ;
V_21 = F_22 ( V_8 ) -> V_36 ;
if ( V_21 -> V_24 != V_24 ) {
F_33 (tb, &head->chain) {
if ( F_34 ( V_23 ( V_21 ) , F_7 ( V_8 ) ) &&
V_21 -> V_24 == V_24 )
break;
}
if ( ! V_21 ) {
V_21 = F_8 ( V_42 -> V_40 ,
F_7 ( V_8 ) , V_19 , V_24 ) ;
if ( ! V_21 ) {
F_28 ( & V_19 -> V_39 ) ;
return - V_43 ;
}
}
}
F_19 ( V_41 , V_21 , V_24 ) ;
F_28 ( & V_19 -> V_39 ) ;
return 0 ;
}
static inline int F_35 ( struct V_7 * V_8 , struct V_1 * V_1 ,
const unsigned short V_44 , const T_1 V_45 ,
const int V_46 )
{
int V_47 = - 1 ;
struct V_9 * V_10 = F_6 ( V_8 ) ;
if ( F_34 ( F_7 ( V_8 ) , V_1 ) && V_10 -> V_12 == V_44 &&
! F_36 ( V_8 ) ) {
T_1 V_48 = V_10 -> V_11 ;
V_47 = V_8 -> V_49 == V_50 ? 2 : 1 ;
if ( V_48 ) {
if ( V_48 != V_45 )
return - 1 ;
V_47 += 4 ;
}
if ( V_8 -> V_51 ) {
if ( V_8 -> V_51 != V_46 )
return - 1 ;
V_47 += 4 ;
}
}
return V_47 ;
}
struct V_7 * F_37 ( struct V_1 * V_1 ,
struct V_31 * V_32 ,
const T_1 V_52 , T_3 V_53 ,
const T_1 V_45 , const unsigned short V_44 ,
const int V_46 )
{
struct V_7 * V_8 , * V_54 ;
struct V_55 * V_29 ;
unsigned int V_56 = F_38 ( V_1 , V_44 ) ;
struct V_57 * V_58 = & V_32 -> V_59 [ V_56 ] ;
int V_47 , V_60 , V_61 = 0 , V_62 = 0 ;
T_4 V_63 = 0 ;
F_39 () ;
V_64:
V_54 = NULL ;
V_60 = 0 ;
F_40 (sk, node, &ilb->head) {
V_47 = F_35 ( V_8 , V_1 , V_44 , V_45 , V_46 ) ;
if ( V_47 > V_60 ) {
V_54 = V_8 ;
V_60 = V_47 ;
V_62 = V_8 -> V_65 ;
if ( V_62 ) {
V_63 = F_1 ( V_1 , V_45 , V_44 ,
V_52 , V_53 ) ;
V_61 = 1 ;
}
} else if ( V_47 == V_60 && V_62 ) {
V_61 ++ ;
if ( ( ( V_66 ) V_63 * V_61 ) >> 32 == 0 )
V_54 = V_8 ;
V_63 = F_41 ( V_63 ) ;
}
}
if ( F_42 ( V_29 ) != V_56 + V_67 )
goto V_64;
if ( V_54 ) {
if ( F_43 ( ! F_44 ( & V_54 -> V_68 ) ) )
V_54 = NULL ;
else if ( F_43 ( F_35 ( V_54 , V_1 , V_44 , V_45 ,
V_46 ) < V_60 ) ) {
F_45 ( V_54 ) ;
goto V_64;
}
}
F_46 () ;
return V_54 ;
}
void F_47 ( struct V_7 * V_8 )
{
if ( ! F_48 ( & V_8 -> V_68 ) )
return;
if ( V_8 -> V_69 == V_70 )
F_49 ( F_50 ( V_8 ) ) ;
else
F_51 ( V_8 ) ;
}
struct V_7 * F_52 ( struct V_1 * V_1 ,
struct V_31 * V_32 ,
const T_1 V_52 , const T_3 V_53 ,
const T_1 V_45 , const T_6 V_44 ,
const int V_46 )
{
F_53 (acookie, saddr, daddr)
const T_7 V_71 = F_54 ( V_53 , V_44 ) ;
struct V_7 * V_8 ;
const struct V_55 * V_29 ;
unsigned int V_56 = F_1 ( V_1 , V_45 , V_44 , V_52 , V_53 ) ;
unsigned int V_72 = V_56 & V_32 -> V_73 ;
struct V_74 * V_19 = & V_32 -> V_75 [ V_72 ] ;
F_39 () ;
V_64:
F_40 (sk, node, &head->chain) {
if ( V_8 -> V_76 != V_56 )
continue;
if ( F_55 ( F_56 ( V_8 , V_1 , V_77 ,
V_52 , V_45 , V_71 , V_46 ) ) ) {
if ( F_43 ( ! F_44 ( & V_8 -> V_68 ) ) )
goto V_78;
if ( F_43 ( ! F_56 ( V_8 , V_1 , V_77 ,
V_52 , V_45 , V_71 , V_46 ) ) ) {
F_47 ( V_8 ) ;
goto V_64;
}
goto V_79;
}
}
if ( F_42 ( V_29 ) != V_72 )
goto V_64;
V_78:
V_8 = NULL ;
V_79:
F_46 () ;
return V_8 ;
}
static int F_57 ( struct V_80 * V_81 ,
struct V_7 * V_8 , T_2 V_3 ,
struct V_82 * * V_83 )
{
struct V_31 * V_84 = V_81 -> V_32 ;
struct V_9 * V_10 = F_6 ( V_8 ) ;
T_1 V_45 = V_10 -> V_11 ;
T_1 V_52 = V_10 -> V_13 ;
int V_46 = V_8 -> V_51 ;
F_53 (acookie, saddr, daddr)
const T_7 V_71 = F_54 ( V_10 -> V_14 , V_3 ) ;
struct V_1 * V_1 = F_7 ( V_8 ) ;
unsigned int V_56 = F_1 ( V_1 , V_45 , V_3 ,
V_52 , V_10 -> V_14 ) ;
struct V_74 * V_19 = V_74 ( V_84 , V_56 ) ;
T_8 * V_39 = F_58 ( V_84 , V_56 ) ;
struct V_7 * V_85 ;
const struct V_55 * V_29 ;
struct V_82 * V_86 = NULL ;
int V_87 = 0 ;
F_26 ( V_39 ) ;
F_59 (sk2, node, &head->chain) {
if ( V_85 -> V_76 != V_56 )
continue;
if ( F_55 ( F_56 ( V_85 , V_1 , V_77 ,
V_52 , V_45 , V_71 , V_46 ) ) ) {
if ( V_85 -> V_69 == V_70 ) {
V_86 = F_50 ( V_85 ) ;
if ( F_60 ( V_8 , V_85 , V_83 ) )
break;
}
goto V_88;
}
}
V_10 -> V_12 = V_3 ;
V_10 -> V_89 = F_61 ( V_3 ) ;
V_8 -> V_76 = V_56 ;
F_62 ( ! F_63 ( V_8 ) ) ;
F_64 ( V_8 , & V_19 -> V_30 ) ;
if ( V_86 ) {
V_87 = F_65 ( V_86 ) ;
F_66 ( V_1 , V_90 ) ;
}
F_28 ( V_39 ) ;
if ( V_87 )
F_67 ( V_86 ) ;
F_68 ( F_7 ( V_8 ) , V_8 -> V_33 , 1 ) ;
if ( V_83 ) {
* V_83 = V_86 ;
} else if ( V_86 ) {
F_69 ( V_86 , V_81 ) ;
F_67 ( V_86 ) ;
}
return 0 ;
V_88:
F_28 ( V_39 ) ;
return - V_91 ;
}
static inline T_4 F_70 ( const struct V_7 * V_8 )
{
const struct V_9 * V_10 = F_6 ( V_8 ) ;
return F_71 ( V_10 -> V_11 ,
V_10 -> V_13 ,
V_10 -> V_14 ) ;
}
int F_72 ( struct V_7 * V_8 , struct V_82 * V_86 )
{
struct V_31 * V_32 = V_8 -> V_33 -> V_34 . V_32 ;
struct V_92 * V_93 ;
T_8 * V_39 ;
struct V_74 * V_19 ;
int V_87 = 0 ;
F_62 ( ! F_63 ( V_8 ) ) ;
V_8 -> V_76 = F_5 ( V_8 ) ;
V_19 = V_74 ( V_32 , V_8 -> V_76 ) ;
V_93 = & V_19 -> V_30 ;
V_39 = F_58 ( V_32 , V_8 -> V_76 ) ;
F_26 ( V_39 ) ;
F_64 ( V_8 , V_93 ) ;
if ( V_86 ) {
F_62 ( V_8 -> V_76 != V_86 -> V_94 ) ;
V_87 = F_65 ( V_86 ) ;
}
F_28 ( V_39 ) ;
F_68 ( F_7 ( V_8 ) , V_8 -> V_33 , 1 ) ;
return V_87 ;
}
static void F_73 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = V_8 -> V_33 -> V_34 . V_32 ;
struct V_57 * V_58 ;
if ( V_8 -> V_69 != V_95 ) {
F_72 ( V_8 , NULL ) ;
return;
}
F_62 ( ! F_63 ( V_8 ) ) ;
V_58 = & V_32 -> V_59 [ F_74 ( V_8 ) ] ;
F_26 ( & V_58 -> V_39 ) ;
F_64 ( V_8 , & V_58 -> V_19 ) ;
F_68 ( F_7 ( V_8 ) , V_8 -> V_33 , 1 ) ;
F_28 ( & V_58 -> V_39 ) ;
}
void F_75 ( struct V_7 * V_8 )
{
if ( V_8 -> V_69 != V_96 ) {
F_30 () ;
F_73 ( V_8 ) ;
F_31 () ;
}
}
void F_76 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = V_8 -> V_33 -> V_34 . V_32 ;
T_8 * V_39 ;
int V_97 ;
if ( F_63 ( V_8 ) )
return;
if ( V_8 -> V_69 == V_95 )
V_39 = & V_32 -> V_59 [ F_74 ( V_8 ) ] . V_39 ;
else
V_39 = F_58 ( V_32 , V_8 -> V_76 ) ;
F_77 ( V_39 ) ;
V_97 = F_78 ( V_8 ) ;
if ( V_97 )
F_68 ( F_7 ( V_8 ) , V_8 -> V_33 , - 1 ) ;
F_79 ( V_39 ) ;
}
int F_80 ( struct V_80 * V_81 ,
struct V_7 * V_8 , T_4 V_98 ,
int (* F_81)( struct V_80 * ,
struct V_7 * , T_2 , struct V_82 * * ) ,
int (* V_56)( struct V_7 * V_8 , struct V_82 * V_83 ) )
{
struct V_31 * V_84 = V_81 -> V_32 ;
const unsigned short V_20 = F_6 ( V_8 ) -> V_12 ;
struct V_18 * V_19 ;
struct V_15 * V_21 ;
int V_99 ;
struct V_1 * V_1 = F_7 ( V_8 ) ;
int V_87 = 1 ;
if ( ! V_20 ) {
int V_100 , V_101 , V_102 , V_103 , V_24 ;
static T_4 V_104 ;
T_4 V_105 = V_104 + V_98 ;
struct V_82 * V_86 = NULL ;
F_82 ( V_1 , & V_102 , & V_103 ) ;
V_101 = ( V_103 - V_102 ) + 1 ;
F_30 () ;
for ( V_100 = 1 ; V_100 <= V_101 ; V_100 ++ ) {
V_24 = V_102 + ( V_100 + V_105 ) % V_101 ;
if ( F_83 ( V_24 ) )
continue;
V_19 = & V_84 -> V_37 [ F_24 ( V_1 , V_24 ,
V_84 -> V_38 ) ] ;
F_26 ( & V_19 -> V_39 ) ;
F_33 (tb, &head->chain) {
if ( F_34 ( V_23 ( V_21 ) , V_1 ) &&
V_21 -> V_24 == V_24 ) {
if ( V_21 -> V_25 >= 0 ||
V_21 -> V_26 >= 0 )
goto V_106;
F_62 ( F_15 ( & V_21 -> V_28 ) ) ;
if ( ! F_81 ( V_81 , V_8 ,
V_24 , & V_86 ) )
goto V_107;
goto V_106;
}
}
V_21 = F_8 ( V_84 -> V_40 ,
V_1 , V_19 , V_24 ) ;
if ( ! V_21 ) {
F_28 ( & V_19 -> V_39 ) ;
break;
}
V_21 -> V_25 = - 1 ;
V_21 -> V_26 = - 1 ;
goto V_107;
V_106:
F_28 ( & V_19 -> V_39 ) ;
}
F_31 () ;
return - V_91 ;
V_107:
V_104 += V_100 ;
F_19 ( V_8 , V_21 , V_24 ) ;
if ( F_63 ( V_8 ) ) {
F_6 ( V_8 ) -> V_89 = F_61 ( V_24 ) ;
V_87 += V_56 ( V_8 , V_86 ) ;
}
if ( V_86 )
V_87 += F_84 ( V_86 , V_84 ) ;
F_28 ( & V_19 -> V_39 ) ;
if ( V_86 ) {
F_69 ( V_86 , V_81 ) ;
while ( V_87 ) {
V_87 -- ;
F_67 ( V_86 ) ;
}
}
V_99 = 0 ;
goto V_78;
}
V_19 = & V_84 -> V_37 [ F_24 ( V_1 , V_20 , V_84 -> V_38 ) ] ;
V_21 = F_22 ( V_8 ) -> V_36 ;
F_77 ( & V_19 -> V_39 ) ;
if ( F_85 ( & V_21 -> V_28 ) == V_8 && ! V_8 -> V_108 . V_109 ) {
V_56 ( V_8 , NULL ) ;
F_79 ( & V_19 -> V_39 ) ;
return 0 ;
} else {
F_28 ( & V_19 -> V_39 ) ;
V_99 = F_81 ( V_81 , V_8 , V_20 , NULL ) ;
V_78:
F_31 () ;
return V_99 ;
}
}
int F_86 ( struct V_80 * V_81 ,
struct V_7 * V_8 )
{
return F_80 ( V_81 , V_8 , F_70 ( V_8 ) ,
F_57 , F_72 ) ;
}
void F_87 ( struct V_31 * V_34 )
{
int V_100 ;
F_88 ( & V_34 -> V_35 , 0 ) ;
for ( V_100 = 0 ; V_100 < V_110 ; V_100 ++ ) {
F_89 ( & V_34 -> V_59 [ V_100 ] . V_39 ) ;
F_90 ( & V_34 -> V_59 [ V_100 ] . V_19 ,
V_100 + V_67 ) ;
}
}
