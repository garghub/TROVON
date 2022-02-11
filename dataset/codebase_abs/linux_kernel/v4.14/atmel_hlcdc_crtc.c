static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 *
F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_4 ) ;
}
static void F_4 ( struct V_6 * V_8 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 -> V_11 -> V_9 ;
struct V_12 * V_13 = & V_8 -> V_3 -> V_14 ;
struct V_1 * V_3 ;
unsigned long V_15 ;
struct V_16 V_17 ;
unsigned long V_18 ;
unsigned int V_19 ;
int div ;
V_17 . V_20 = V_13 -> V_21 - V_13 -> V_22 ;
V_17 . V_23 = V_13 -> V_24 - V_13 -> V_25 ;
V_17 . V_26 = V_13 -> V_25 - V_13 -> V_21 ;
V_17 . V_27 = V_13 -> V_28 - V_13 -> V_29 ;
V_17 . V_30 = V_13 -> V_31 - V_13 -> V_32 ;
V_17 . V_33 = V_13 -> V_32 - V_13 -> V_28 ;
F_5 ( V_9 , F_6 ( 1 ) ,
( V_17 . V_33 - 1 ) | ( ( V_17 . V_26 - 1 ) << 16 ) ) ;
F_5 ( V_9 , F_6 ( 2 ) ,
( V_17 . V_20 - 1 ) | ( V_17 . V_23 << 16 ) ) ;
F_5 ( V_9 , F_6 ( 3 ) ,
( V_17 . V_27 - 1 ) | ( ( V_17 . V_30 - 1 ) << 16 ) ) ;
F_5 ( V_9 , F_6 ( 4 ) ,
( V_13 -> V_29 - 1 ) |
( ( V_13 -> V_22 - 1 ) << 16 ) ) ;
V_19 = 0 ;
V_18 = F_7 ( V_7 -> V_10 -> V_11 -> V_34 ) ;
V_15 = V_13 -> V_35 * 1000 ;
if ( ( V_18 / 2 ) < V_15 ) {
V_18 *= 2 ;
V_19 |= V_36 ;
}
div = F_8 ( V_18 , V_15 ) ;
if ( div < 2 )
div = 2 ;
V_19 |= F_9 ( div ) ;
F_10 ( V_9 , F_6 ( 0 ) ,
V_36 | V_37 |
V_38 , V_19 ) ;
V_19 = 0 ;
if ( V_13 -> V_39 & V_40 )
V_19 |= V_41 ;
if ( V_13 -> V_39 & V_42 )
V_19 |= V_43 ;
V_3 = F_1 ( V_8 -> V_3 ) ;
V_19 |= V_3 -> V_44 << 8 ;
F_10 ( V_9 , F_6 ( 5 ) ,
V_43 | V_41 |
V_45 | V_46 |
V_47 | V_48 |
V_49 | V_50 |
V_51 | V_52 ,
V_19 ) ;
}
static enum V_53
F_11 ( struct V_6 * V_8 ,
const struct V_12 * V_54 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
return F_12 ( V_7 -> V_10 , V_54 ) ;
}
static void F_13 ( struct V_6 * V_8 ,
struct V_2 * V_55 )
{
struct V_56 * V_57 = V_8 -> V_57 ;
struct V_5 * V_7 = F_3 ( V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 -> V_11 -> V_9 ;
unsigned int V_58 ;
F_14 ( V_8 ) ;
F_15 ( V_57 -> V_57 ) ;
F_5 ( V_9 , V_59 , V_60 ) ;
while ( ! F_16 ( V_9 , V_61 , & V_58 ) &&
( V_58 & V_60 ) )
F_17 () ;
F_5 ( V_9 , V_59 , V_62 ) ;
while ( ! F_16 ( V_9 , V_61 , & V_58 ) &&
( V_58 & V_62 ) )
F_17 () ;
F_5 ( V_9 , V_59 , V_63 ) ;
while ( ! F_16 ( V_9 , V_61 , & V_58 ) &&
( V_58 & V_63 ) )
F_17 () ;
F_18 ( V_7 -> V_10 -> V_11 -> V_34 ) ;
F_19 ( V_57 -> V_57 ) ;
F_20 ( V_57 -> V_57 ) ;
F_21 ( V_57 -> V_57 ) ;
}
static void F_22 ( struct V_6 * V_8 ,
struct V_2 * V_55 )
{
struct V_56 * V_57 = V_8 -> V_57 ;
struct V_5 * V_7 = F_3 ( V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 -> V_11 -> V_9 ;
unsigned int V_58 ;
F_15 ( V_57 -> V_57 ) ;
F_23 ( V_57 -> V_57 ) ;
F_24 ( V_57 -> V_57 ) ;
F_25 ( V_7 -> V_10 -> V_11 -> V_34 ) ;
F_5 ( V_9 , V_64 , V_63 ) ;
while ( ! F_16 ( V_9 , V_61 , & V_58 ) &&
! ( V_58 & V_63 ) )
F_17 () ;
F_5 ( V_9 , V_64 , V_62 ) ;
while ( ! F_16 ( V_9 , V_61 , & V_58 ) &&
! ( V_58 & V_62 ) )
F_17 () ;
F_5 ( V_9 , V_64 , V_60 ) ;
while ( ! F_16 ( V_9 , V_61 , & V_58 ) &&
! ( V_58 & V_60 ) )
F_17 () ;
F_21 ( V_57 -> V_57 ) ;
F_26 ( V_8 ) ;
}
static int F_27 ( struct V_2 * V_3 )
{
unsigned int V_65 = V_66 ;
struct V_1 * V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_5 * V_7 ;
int V_72 ;
V_7 = F_3 ( V_3 -> V_7 ) ;
F_28 (state->state, connector, cstate, i) {
struct V_73 * V_74 = & V_71 -> V_75 ;
unsigned int V_76 = 0 ;
int V_77 ;
if ( ! V_69 -> V_7 )
continue;
for ( V_77 = 0 ; V_77 < V_74 -> V_78 ; V_77 ++ ) {
switch ( V_74 -> V_79 [ V_77 ] ) {
case V_80 :
V_76 |= V_81 ;
break;
case V_82 :
V_76 |= V_83 ;
break;
case V_84 :
V_76 |= V_85 ;
break;
case V_86 :
V_76 |= V_87 ;
break;
default:
break;
}
}
if ( V_7 -> V_10 -> V_88 -> V_89 )
V_65 &= V_76 ;
else
V_65 |= V_76 ;
}
if ( ! V_65 )
return - V_90 ;
V_67 = F_1 ( V_3 ) ;
V_67 -> V_44 = F_29 ( V_65 ) - 1 ;
return 0 ;
}
static int F_30 ( struct V_6 * V_8 ,
struct V_2 * V_91 )
{
int V_92 ;
V_92 = F_27 ( V_91 ) ;
if ( V_92 )
return V_92 ;
V_92 = F_31 ( V_91 ) ;
if ( V_92 )
return V_92 ;
return F_32 ( V_91 ) ;
}
static void F_33 ( struct V_6 * V_8 ,
struct V_2 * V_93 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
if ( V_8 -> V_3 -> V_94 ) {
V_8 -> V_3 -> V_94 -> V_95 = F_34 ( V_8 ) ;
F_35 ( F_36 ( V_8 ) != 0 ) ;
V_7 -> V_94 = V_8 -> V_3 -> V_94 ;
V_8 -> V_3 -> V_94 = NULL ;
}
}
static void F_37 ( struct V_6 * V_7 ,
struct V_2 * V_93 )
{
}
static void F_38 ( struct V_6 * V_8 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
F_39 ( V_8 ) ;
F_40 ( V_7 ) ;
}
static void F_41 ( struct V_5 * V_7 )
{
struct V_56 * V_57 = V_7 -> V_4 . V_57 ;
unsigned long V_39 ;
F_42 ( & V_57 -> V_96 , V_39 ) ;
if ( V_7 -> V_94 ) {
F_43 ( & V_7 -> V_4 , V_7 -> V_94 ) ;
F_44 ( & V_7 -> V_4 ) ;
V_7 -> V_94 = NULL ;
}
F_45 ( & V_57 -> V_96 , V_39 ) ;
}
void F_46 ( struct V_6 * V_8 )
{
F_47 ( V_8 ) ;
F_41 ( F_3 ( V_8 ) ) ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_1 * V_3 ;
if ( V_7 -> V_3 ) {
F_49 ( V_7 -> V_3 ) ;
V_3 = F_1 ( V_7 -> V_3 ) ;
F_40 ( V_3 ) ;
V_7 -> V_3 = NULL ;
}
V_3 = F_50 ( sizeof( * V_3 ) , V_97 ) ;
if ( V_3 ) {
V_7 -> V_3 = & V_3 -> V_4 ;
V_7 -> V_3 -> V_7 = V_7 ;
}
}
static struct V_2 *
F_51 ( struct V_6 * V_7 )
{
struct V_1 * V_3 , * V_98 ;
if ( F_35 ( ! V_7 -> V_3 ) )
return NULL ;
V_3 = F_52 ( sizeof( * V_3 ) , V_97 ) ;
if ( ! V_3 )
return NULL ;
F_53 ( V_7 , & V_3 -> V_4 ) ;
V_98 = F_1 ( V_7 -> V_3 ) ;
V_3 -> V_44 = V_98 -> V_44 ;
return & V_3 -> V_4 ;
}
static void F_54 ( struct V_6 * V_7 ,
struct V_2 * V_91 )
{
struct V_1 * V_3 ;
V_3 = F_1 ( V_91 ) ;
F_49 ( V_91 ) ;
F_40 ( V_3 ) ;
}
static int F_55 ( struct V_6 * V_8 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 -> V_11 -> V_9 ;
F_5 ( V_9 , V_99 , V_100 ) ;
return 0 ;
}
static void F_56 ( struct V_6 * V_8 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 -> V_11 -> V_9 ;
F_5 ( V_9 , V_101 , V_100 ) ;
}
int F_57 ( struct V_56 * V_57 )
{
struct V_102 * V_103 = NULL , * V_104 = NULL ;
struct V_105 * V_10 = V_57 -> V_106 ;
struct V_5 * V_7 ;
int V_92 ;
int V_72 ;
V_7 = F_50 ( sizeof( * V_7 ) , V_97 ) ;
if ( ! V_7 )
return - V_107 ;
V_7 -> V_10 = V_10 ;
for ( V_72 = 0 ; V_72 < V_108 ; V_72 ++ ) {
if ( ! V_10 -> V_109 [ V_72 ] )
continue;
switch ( V_10 -> V_109 [ V_72 ] -> V_88 -> type ) {
case V_110 :
V_103 = F_58 ( V_10 -> V_109 [ V_72 ] ) ;
break;
case V_111 :
V_104 = F_58 ( V_10 -> V_109 [ V_72 ] ) ;
break;
default:
break;
}
}
V_92 = F_59 ( V_57 , & V_7 -> V_4 , & V_103 -> V_4 ,
& V_104 -> V_4 , & V_112 ,
NULL ) ;
if ( V_92 < 0 )
goto V_113;
V_7 -> V_114 = F_34 ( & V_7 -> V_4 ) ;
for ( V_72 = 0 ; V_72 < V_108 ; V_72 ++ ) {
struct V_102 * V_115 ;
if ( V_10 -> V_109 [ V_72 ] &&
V_10 -> V_109 [ V_72 ] -> V_88 -> type == V_116 ) {
V_115 = F_58 ( V_10 -> V_109 [ V_72 ] ) ;
V_115 -> V_4 . V_117 = 1 << V_7 -> V_114 ;
}
}
F_60 ( & V_7 -> V_4 , & V_118 ) ;
F_61 ( & V_7 -> V_4 ) ;
F_62 ( & V_7 -> V_4 , V_119 ) ;
F_63 ( & V_7 -> V_4 , 0 , false ,
V_119 ) ;
V_10 -> V_7 = & V_7 -> V_4 ;
return 0 ;
V_113:
F_38 ( & V_7 -> V_4 ) ;
return V_92 ;
}
