static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 ;
V_5 = F_2 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( ! V_5 )
return - V_9 ;
if ( V_5 == V_4 ) {
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ,
V_5 -> V_10 ) ;
return 0 ;
}
while ( F_6 ( V_5 -> V_10 ) &&
F_6 ( V_5 -> V_10 ) != V_4 )
V_5 = F_2 ( V_5 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( F_6 ( V_5 -> V_10 ) ) {
F_5 ( V_5 -> V_10 , V_4 -> V_10 ) ;
return 0 ;
}
return - V_9 ;
}
struct V_3 * F_7 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_8 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_9 () ||
F_4 ( & V_2 -> V_8 ) ||
F_4 ( & V_2 -> V_13 ) ) ;
while ( V_4 ) {
if ( V_4 -> V_12 == V_12 &&
memcmp ( V_4 -> V_4 . V_7 , V_7 , V_14 ) == 0 )
break;
V_4 = F_8 ( V_4 -> V_10 ,
F_9 () ||
F_4 ( & V_2 -> V_8 ) ||
F_4 ( & V_2 -> V_13 ) ) ;
}
return V_4 ;
}
struct V_3 * F_10 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_8 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_9 () ||
F_4 ( & V_2 -> V_8 ) ||
F_4 ( & V_2 -> V_13 ) ) ;
while ( V_4 ) {
if ( ( V_4 -> V_12 == V_12 ||
( V_4 -> V_12 -> V_15 && V_4 -> V_12 -> V_15 == V_12 -> V_15 ) ) &&
memcmp ( V_4 -> V_4 . V_7 , V_7 , V_14 ) == 0 )
break;
V_4 = F_8 ( V_4 -> V_10 ,
F_9 () ||
F_4 ( & V_2 -> V_8 ) ||
F_4 ( & V_2 -> V_13 ) ) ;
}
return V_4 ;
}
struct V_3 * F_11 ( struct V_11 * V_12 ,
int V_16 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
int V_17 = 0 ;
F_12 (sta, &local->sta_list, list) {
if ( V_12 != V_4 -> V_12 )
continue;
if ( V_17 < V_16 ) {
++ V_17 ;
continue;
}
return V_4 ;
}
return NULL ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_18 ) {
F_14 ( V_4 ) ;
F_15 ( V_4 -> V_18 ) ;
}
#ifdef F_16
F_17 ( V_2 -> V_19 . V_20 , L_1 , V_4 -> V_4 . V_7 ) ;
#endif
F_18 ( V_4 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_10 = V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ;
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] , V_4 ) ;
}
static void F_20 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
V_4 = F_21 ( V_22 , struct V_3 , V_23 ) ;
if ( V_4 -> V_24 )
return;
if ( ! F_22 ( V_4 , V_25 ) )
F_23 ( V_4 ) ;
else if ( F_24 ( V_4 , V_26 ) ) {
F_25 ( V_4 , V_27 ) ;
F_26 ( V_4 ) ;
} else
F_25 ( V_4 , V_27 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_28 )
{
if ( V_2 -> V_19 . V_29 & V_30 )
return 0 ;
V_4 -> V_18 = F_28 ( V_2 -> V_18 ) ;
V_4 -> V_31 = F_29 ( V_4 -> V_18 ,
& V_4 -> V_4 , V_28 ) ;
if ( ! V_4 -> V_31 ) {
F_15 ( V_4 -> V_18 ) ;
return - V_32 ;
}
return 0 ;
}
struct V_3 * F_30 ( struct V_11 * V_12 ,
T_1 * V_7 , T_2 V_28 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
struct V_33 V_34 ;
int V_17 ;
V_4 = F_31 ( sizeof( * V_4 ) + V_2 -> V_19 . V_35 , V_28 ) ;
if ( ! V_4 )
return NULL ;
F_32 ( & V_4 -> V_36 ) ;
F_32 ( & V_4 -> V_37 ) ;
F_33 ( & V_4 -> V_23 , F_20 ) ;
F_33 ( & V_4 -> V_38 . V_39 , V_40 ) ;
F_34 ( & V_4 -> V_38 . V_41 ) ;
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_14 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_42 = V_43 ;
F_35 ( & V_34 ) ;
V_4 -> V_44 = V_34 . V_45 ;
F_36 ( & V_4 -> V_46 , 1024 , 8 ) ;
if ( F_27 ( V_2 , V_4 , V_28 ) ) {
F_18 ( V_4 ) ;
return NULL ;
}
for ( V_17 = 0 ; V_17 < V_47 ; V_17 ++ ) {
V_4 -> V_48 [ V_17 ] = V_17 ;
}
F_37 ( & V_4 -> V_49 ) ;
F_37 ( & V_4 -> V_50 ) ;
for ( V_17 = 0 ; V_17 < V_51 ; V_17 ++ )
V_4 -> V_52 [ V_17 ] = F_38 ( V_53 ) ;
#ifdef F_16
F_17 ( V_2 -> V_19 . V_20 , L_2 , V_4 -> V_4 . V_7 ) ;
#endif
#ifdef F_39
V_4 -> V_54 = V_55 ;
F_40 ( & V_4 -> V_56 ) ;
#endif
return V_4 ;
}
static int F_41 ( struct V_3 * V_4 , bool V_57 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_58 V_59 ;
unsigned long V_29 ;
int V_60 = 0 ;
F_42 ( & V_2 -> V_13 ) ;
if ( V_12 -> V_61 . type == V_62 )
V_12 = F_21 ( V_12 -> V_15 ,
struct V_11 ,
V_63 . V_64 ) ;
V_60 = F_43 ( V_2 , V_12 , & V_4 -> V_4 ) ;
if ( V_60 ) {
if ( ! V_57 )
return V_60 ;
F_44 ( V_65 L_3
L_4 ,
V_12 -> V_66 , V_4 -> V_4 . V_7 , V_60 ) ;
} else {
V_4 -> V_67 = true ;
#ifdef F_16
if ( V_57 )
F_17 ( V_2 -> V_19 . V_20 ,
L_5 ,
V_4 -> V_4 . V_7 ) ;
#endif
}
V_12 = V_4 -> V_12 ;
if ( ! V_57 ) {
V_2 -> V_68 ++ ;
V_2 -> V_69 ++ ;
F_45 () ;
F_46 ( & V_2 -> V_8 , V_29 ) ;
F_19 ( V_2 , V_4 ) ;
F_47 ( & V_2 -> V_8 , V_29 ) ;
}
F_48 ( & V_4 -> V_70 , & V_2 -> V_71 ) ;
F_49 ( V_4 ) ;
F_50 ( V_4 ) ;
V_59 . V_72 = 0 ;
V_59 . V_73 = V_2 -> V_69 ;
F_51 ( V_12 -> V_74 , V_4 -> V_4 . V_7 , & V_59 , V_75 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_29 ;
F_46 ( & V_2 -> V_8 , V_29 ) ;
while ( ! F_53 ( & V_2 -> V_76 ) ) {
V_4 = F_54 ( & V_2 -> V_76 ,
struct V_3 , V_70 ) ;
F_55 ( & V_4 -> V_70 ) ;
F_47 ( & V_2 -> V_8 , V_29 ) ;
F_41 ( V_4 , true ) ;
F_46 ( & V_2 -> V_8 , V_29 ) ;
}
F_47 ( & V_2 -> V_8 , V_29 ) ;
}
static void F_56 ( struct V_21 * V_39 )
{
struct V_1 * V_2 =
F_21 ( V_39 , struct V_1 , V_77 ) ;
F_57 ( & V_2 -> V_13 ) ;
F_52 ( V_2 ) ;
F_58 ( & V_2 -> V_13 ) ;
}
int F_59 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_12 = V_4 -> V_12 ;
unsigned long V_29 ;
int V_60 = 0 ;
if ( F_60 ( ! F_61 ( V_12 ) ) ) {
V_60 = - V_78 ;
F_62 () ;
goto V_79;
}
if ( F_63 ( F_64 ( V_4 -> V_4 . V_7 , V_12 -> V_61 . V_7 ) == 0 ||
F_65 ( V_4 -> V_4 . V_7 ) ) ) {
V_60 = - V_80 ;
F_62 () ;
goto V_79;
}
if ( V_12 -> V_61 . type == V_81 ) {
F_46 ( & V_2 -> V_8 , V_29 ) ;
if ( F_10 ( V_12 , V_4 -> V_4 . V_7 ) ) {
F_47 ( & V_2 -> V_8 , V_29 ) ;
F_62 () ;
V_60 = - V_82 ;
goto V_79;
}
V_2 -> V_68 ++ ;
V_2 -> V_69 ++ ;
F_45 () ;
F_19 ( V_2 , V_4 ) ;
F_66 ( & V_4 -> V_70 , & V_2 -> V_76 ) ;
F_62 () ;
F_47 ( & V_2 -> V_8 , V_29 ) ;
#ifdef F_16
F_17 ( V_2 -> V_19 . V_20 , L_6 ,
V_4 -> V_4 . V_7 ) ;
#endif
F_67 ( & V_2 -> V_19 , & V_2 -> V_77 ) ;
return 0 ;
}
F_68 () ;
F_57 ( & V_2 -> V_13 ) ;
F_46 ( & V_2 -> V_8 , V_29 ) ;
if ( F_10 ( V_12 , V_4 -> V_4 . V_7 ) ) {
F_47 ( & V_2 -> V_8 , V_29 ) ;
F_58 ( & V_2 -> V_13 ) ;
F_62 () ;
V_60 = - V_82 ;
goto V_79;
}
F_47 ( & V_2 -> V_8 , V_29 ) ;
V_60 = F_41 ( V_4 , false ) ;
if ( V_60 ) {
F_58 ( & V_2 -> V_13 ) ;
F_62 () ;
goto V_79;
}
#ifdef F_16
F_17 ( V_2 -> V_19 . V_20 , L_7 , V_4 -> V_4 . V_7 ) ;
#endif
F_62 () ;
F_58 ( & V_2 -> V_13 ) ;
if ( F_69 ( & V_12 -> V_61 ) )
F_70 ( V_12 ) ;
return 0 ;
V_79:
F_71 ( ! V_60 ) ;
F_13 ( V_2 , V_4 ) ;
return V_60 ;
}
int F_72 ( struct V_3 * V_4 )
{
int V_60 = F_59 ( V_4 ) ;
F_73 () ;
return V_60 ;
}
static inline void F_74 ( struct V_83 * V_15 , T_4 V_84 )
{
V_15 -> V_85 [ V_84 / 8 ] |= ( 1 << ( V_84 % 8 ) ) ;
}
static inline void F_75 ( struct V_83 * V_15 , T_4 V_84 )
{
V_15 -> V_85 [ V_84 / 8 ] &= ~ ( 1 << ( V_84 % 8 ) ) ;
}
static void F_76 ( struct V_83 * V_15 ,
struct V_3 * V_4 )
{
F_71 ( ! V_15 ) ;
F_74 ( V_15 , V_4 -> V_4 . V_84 ) ;
if ( V_4 -> V_2 -> V_86 -> V_87 ) {
V_4 -> V_2 -> V_88 = true ;
F_77 ( V_4 -> V_2 , & V_4 -> V_4 , true ) ;
V_4 -> V_2 -> V_88 = false ;
}
}
void F_78 ( struct V_3 * V_4 )
{
unsigned long V_29 ;
F_71 ( ! V_4 -> V_12 -> V_15 ) ;
F_46 ( & V_4 -> V_2 -> V_8 , V_29 ) ;
F_76 ( V_4 -> V_12 -> V_15 , V_4 ) ;
F_47 ( & V_4 -> V_2 -> V_8 , V_29 ) ;
}
static void F_79 ( struct V_83 * V_15 ,
struct V_3 * V_4 )
{
F_71 ( ! V_15 ) ;
F_75 ( V_15 , V_4 -> V_4 . V_84 ) ;
if ( V_4 -> V_2 -> V_86 -> V_87 ) {
V_4 -> V_2 -> V_88 = true ;
F_77 ( V_4 -> V_2 , & V_4 -> V_4 , false ) ;
V_4 -> V_2 -> V_88 = false ;
}
}
void F_80 ( struct V_3 * V_4 )
{
unsigned long V_29 ;
F_71 ( ! V_4 -> V_12 -> V_15 ) ;
F_46 ( & V_4 -> V_2 -> V_8 , V_29 ) ;
F_79 ( V_4 -> V_12 -> V_15 , V_4 ) ;
F_47 ( & V_4 -> V_2 -> V_8 , V_29 ) ;
}
static int F_81 ( struct V_3 * V_4 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 ;
int V_93 ;
if ( ! V_90 )
return 0 ;
V_92 = F_82 ( V_90 ) ;
V_93 = ( V_4 -> V_94 *
V_4 -> V_12 -> V_61 . V_95 . V_96 *
32 / 15625 ) * V_97 ;
if ( V_93 < V_98 )
V_93 = V_98 ;
return F_83 ( V_43 , V_92 -> V_99 . V_43 + V_93 ) ;
}
static bool F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_29 ;
struct V_89 * V_90 ;
if ( F_85 ( & V_4 -> V_49 ) )
return false ;
for (; ; ) {
F_46 ( & V_4 -> V_49 . V_36 , V_29 ) ;
V_90 = F_86 ( & V_4 -> V_49 ) ;
if ( F_81 ( V_4 , V_90 ) )
V_90 = F_87 ( & V_4 -> V_49 ) ;
else
V_90 = NULL ;
F_47 ( & V_4 -> V_49 . V_36 , V_29 ) ;
if ( ! V_90 )
break;
V_2 -> V_100 -- ;
#ifdef F_88
F_44 ( V_65 L_8 ,
V_4 -> V_4 . V_7 ) ;
#endif
F_89 ( V_90 ) ;
if ( F_85 ( & V_4 -> V_49 ) &&
! F_22 ( V_4 , V_101 ) )
F_80 ( V_4 ) ;
}
return true ;
}
static int T_5 F_90 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_89 * V_90 ;
unsigned long V_29 ;
int V_102 , V_17 ;
F_68 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_12 = V_4 -> V_12 ;
F_91 ( V_4 , V_103 ) ;
F_92 ( V_4 , true ) ;
F_46 ( & V_2 -> V_8 , V_29 ) ;
V_102 = F_1 ( V_2 , V_4 ) ;
if ( ! V_102 )
F_55 ( & V_4 -> V_70 ) ;
F_47 ( & V_2 -> V_8 , V_29 ) ;
if ( V_102 )
return V_102 ;
F_57 ( & V_2 -> V_104 ) ;
for ( V_17 = 0 ; V_17 < V_105 ; V_17 ++ )
F_93 ( F_94 ( V_2 , V_4 -> V_106 [ V_17 ] ) ) ;
if ( V_4 -> V_107 )
F_93 ( F_94 ( V_2 , V_4 -> V_107 ) ) ;
F_58 ( & V_2 -> V_104 ) ;
V_4 -> V_24 = true ;
if ( F_24 ( V_4 ,
V_25 | V_27 ) ) {
F_71 ( ! V_12 -> V_15 ) ;
F_95 ( & V_12 -> V_15 -> V_108 ) ;
F_79 ( V_12 -> V_15 , V_4 ) ;
}
V_2 -> V_68 -- ;
V_2 -> V_69 ++ ;
if ( V_12 -> V_61 . type == V_62 )
F_5 ( V_12 -> V_63 . V_109 . V_4 , NULL ) ;
if ( V_4 -> V_67 ) {
if ( V_12 -> V_61 . type == V_62 )
V_12 = F_21 ( V_12 -> V_15 ,
struct V_11 ,
V_63 . V_64 ) ;
F_96 ( V_2 , V_12 , & V_4 -> V_4 ) ;
V_12 = V_4 -> V_12 ;
}
F_97 () ;
#ifdef F_39
if ( F_69 ( & V_12 -> V_61 ) )
F_70 ( V_12 ) ;
#endif
#ifdef F_16
F_17 ( V_2 -> V_19 . V_20 , L_9 , V_4 -> V_4 . V_7 ) ;
#endif
F_98 ( & V_4 -> V_23 ) ;
F_99 ( V_12 -> V_74 , V_4 -> V_4 . V_7 , V_75 ) ;
F_100 ( V_4 ) ;
F_101 ( V_4 ) ;
#ifdef F_39
if ( F_69 ( & V_4 -> V_12 -> V_61 ) ) {
F_102 ( V_4 ) ;
F_103 ( & V_4 -> V_56 ) ;
}
#endif
while ( ( V_90 = F_104 ( & V_4 -> V_49 ) ) != NULL ) {
V_2 -> V_100 -- ;
F_105 ( V_90 ) ;
}
while ( ( V_90 = F_104 ( & V_4 -> V_50 ) ) != NULL )
F_105 ( V_90 ) ;
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
int F_106 ( struct V_11 * V_12 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_102 ;
F_57 ( & V_12 -> V_2 -> V_13 ) ;
V_4 = F_7 ( V_12 , V_7 ) ;
V_102 = F_90 ( V_4 ) ;
F_58 ( & V_12 -> V_2 -> V_13 ) ;
return V_102 ;
}
int F_107 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_102 ;
F_57 ( & V_12 -> V_2 -> V_13 ) ;
V_4 = F_10 ( V_12 , V_7 ) ;
V_102 = F_90 ( V_4 ) ;
F_58 ( & V_12 -> V_2 -> V_13 ) ;
return V_102 ;
}
static void F_108 ( unsigned long V_110 )
{
struct V_1 * V_2 = (struct V_1 * ) V_110 ;
struct V_3 * V_4 ;
bool V_111 = false ;
F_62 () ;
F_12 (sta, &local->sta_list, list)
if ( F_84 ( V_2 , V_4 ) )
V_111 = true ;
F_73 () ;
if ( V_2 -> V_112 )
return;
if ( ! V_111 )
return;
F_109 ( & V_2 -> V_113 ,
F_110 ( V_43 + V_114 ) ) ;
}
void F_111 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_8 ) ;
F_34 ( & V_2 -> V_13 ) ;
F_112 ( & V_2 -> V_71 ) ;
F_112 ( & V_2 -> V_76 ) ;
F_33 ( & V_2 -> V_77 , F_56 ) ;
F_113 ( & V_2 -> V_113 , F_108 ,
( unsigned long ) V_2 ) ;
}
void F_114 ( struct V_1 * V_2 )
{
F_115 ( & V_2 -> V_113 ) ;
F_116 ( V_2 , NULL ) ;
}
int F_116 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_3 * V_4 , * V_115 ;
int V_102 = 0 ;
F_68 () ;
F_57 ( & V_2 -> V_13 ) ;
F_52 ( V_2 ) ;
F_117 (sta, tmp, &local->sta_list, list) {
if ( ! V_12 || V_12 == V_4 -> V_12 )
F_63 ( F_90 ( V_4 ) ) ;
}
F_58 ( & V_2 -> V_13 ) ;
return V_102 ;
}
void F_118 ( struct V_11 * V_12 ,
unsigned long V_116 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 , * V_115 ;
F_57 ( & V_2 -> V_13 ) ;
F_117 (sta, tmp, &local->sta_list, list)
if ( F_83 ( V_43 , V_4 -> V_42 + V_116 ) ) {
#ifdef F_119
F_44 ( V_65 L_10 ,
V_12 -> V_66 , V_4 -> V_4 . V_7 ) ;
#endif
F_63 ( F_90 ( V_4 ) ) ;
}
F_58 ( & V_2 -> V_13 ) ;
}
struct V_117 * F_120 ( struct V_118 * V_19 ,
const T_1 * V_7 ,
const T_1 * V_119 )
{
struct V_3 * V_4 , * V_120 ;
F_121 (hw_to_local(hw), addr, sta, nxt) {
if ( V_119 &&
F_64 ( V_4 -> V_12 -> V_61 . V_7 , V_119 ) != 0 )
continue;
if ( ! V_4 -> V_67 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_117 * F_122 ( struct V_121 * V_61 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_61 )
return NULL ;
V_4 = F_10 ( F_123 ( V_61 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_67 )
return NULL ;
return & V_4 -> V_4 ;
}
static void F_124 ( void * V_122 )
{
struct V_3 * V_4 = V_122 ;
F_25 ( V_4 , V_27 | V_25 ) ;
}
void F_23 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
int V_123 , V_124 ;
F_25 ( V_4 , V_101 ) ;
if ( ! ( V_2 -> V_19 . V_29 & V_125 ) )
F_125 ( V_2 , V_12 , V_126 , & V_4 -> V_4 ) ;
if ( ! F_85 ( & V_4 -> V_49 ) )
F_80 ( V_4 ) ;
V_123 = F_126 ( V_2 , & V_4 -> V_50 ) ;
V_124 = F_127 ( V_2 , & V_4 -> V_49 ,
F_124 , V_4 ) ;
V_123 += V_124 ;
V_2 -> V_100 -= V_124 ;
#ifdef F_88
F_44 ( V_65 L_11
L_12 , V_12 -> V_66 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_84 , V_123 - V_124 , V_124 ) ;
#endif
}
void F_26 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_89 * V_90 ;
int V_127 ;
V_90 = F_104 ( & V_4 -> V_50 ) ;
if ( ! V_90 ) {
V_90 = F_104 ( & V_4 -> V_49 ) ;
if ( V_90 )
V_2 -> V_100 -- ;
}
V_127 = F_85 ( & V_4 -> V_50 ) &&
F_85 ( & V_4 -> V_49 ) ;
if ( V_90 ) {
struct V_91 * V_92 = F_82 ( V_90 ) ;
struct V_128 * V_129 =
(struct V_128 * ) V_90 -> V_110 ;
V_92 -> V_29 |= V_130 ;
#ifdef F_88
F_44 ( V_65 L_13 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_84 ,
F_128 ( & V_4 -> V_49 ) ) ;
#endif
if ( V_127 )
V_129 -> V_131 &= F_38 ( ~ V_132 ) ;
else
V_129 -> V_131 |= F_38 ( V_132 ) ;
F_129 ( V_2 , V_90 ) ;
if ( V_127 )
F_80 ( V_4 ) ;
#ifdef F_88
} else {
F_44 ( V_65 L_14
L_15 ,
V_12 -> V_66 , V_4 -> V_4 . V_7 ) ;
#endif
}
}
void F_130 ( struct V_118 * V_19 ,
struct V_117 * V_133 , bool V_134 )
{
struct V_3 * V_4 = F_21 ( V_133 , struct V_3 , V_4 ) ;
F_131 ( V_4 -> V_2 , V_133 , V_134 ) ;
if ( V_134 )
F_91 ( V_4 , V_27 ) ;
else if ( F_22 ( V_4 , V_27 ) )
F_67 ( V_19 , & V_4 -> V_23 ) ;
}
void F_132 ( struct V_117 * V_133 )
{
struct V_3 * V_4 = F_21 ( V_133 , struct V_3 , V_4 ) ;
F_91 ( V_4 , V_101 ) ;
F_78 ( V_4 ) ;
}
