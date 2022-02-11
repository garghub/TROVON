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
static bool F_11 ( struct V_6 * V_8 ,
const struct V_12 * V_53 ,
struct V_12 * V_14 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
return F_12 ( V_7 -> V_10 , V_14 ) == V_54 ;
}
static void F_13 ( struct V_6 * V_8 )
{
struct V_55 * V_56 = V_8 -> V_56 ;
struct V_5 * V_7 = F_3 ( V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 -> V_11 -> V_9 ;
unsigned int V_57 ;
if ( ! V_7 -> V_58 )
return;
F_14 ( V_8 ) ;
F_15 ( V_56 -> V_56 ) ;
F_5 ( V_9 , V_59 , V_60 ) ;
while ( ! F_16 ( V_9 , V_61 , & V_57 ) &&
( V_57 & V_60 ) )
F_17 () ;
F_5 ( V_9 , V_59 , V_62 ) ;
while ( ! F_16 ( V_9 , V_61 , & V_57 ) &&
( V_57 & V_62 ) )
F_17 () ;
F_5 ( V_9 , V_59 , V_63 ) ;
while ( ! F_16 ( V_9 , V_61 , & V_57 ) &&
( V_57 & V_63 ) )
F_17 () ;
F_18 ( V_7 -> V_10 -> V_11 -> V_34 ) ;
F_19 ( V_56 -> V_56 ) ;
F_20 ( V_56 -> V_56 ) ;
F_21 ( V_56 -> V_56 ) ;
V_7 -> V_58 = false ;
}
static void F_22 ( struct V_6 * V_8 )
{
struct V_55 * V_56 = V_8 -> V_56 ;
struct V_5 * V_7 = F_3 ( V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 -> V_11 -> V_9 ;
unsigned int V_57 ;
if ( V_7 -> V_58 )
return;
F_15 ( V_56 -> V_56 ) ;
F_23 ( V_56 -> V_56 ) ;
F_24 ( V_56 -> V_56 ) ;
F_25 ( V_7 -> V_10 -> V_11 -> V_34 ) ;
F_5 ( V_9 , V_64 , V_63 ) ;
while ( ! F_16 ( V_9 , V_61 , & V_57 ) &&
! ( V_57 & V_63 ) )
F_17 () ;
F_5 ( V_9 , V_64 , V_62 ) ;
while ( ! F_16 ( V_9 , V_61 , & V_57 ) &&
! ( V_57 & V_62 ) )
F_17 () ;
F_5 ( V_9 , V_64 , V_60 ) ;
while ( ! F_16 ( V_9 , V_61 , & V_57 ) &&
! ( V_57 & V_60 ) )
F_17 () ;
F_21 ( V_56 -> V_56 ) ;
F_26 ( V_8 ) ;
V_7 -> V_58 = true ;
}
void F_27 ( struct V_6 * V_8 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
if ( V_7 -> V_58 ) {
F_13 ( V_8 ) ;
V_7 -> V_58 = true ;
}
}
void F_28 ( struct V_6 * V_8 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
if ( V_7 -> V_58 ) {
V_7 -> V_58 = false ;
F_22 ( V_8 ) ;
}
}
static int F_29 ( struct V_2 * V_3 )
{
unsigned int V_65 = V_66 ;
struct V_1 * V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_5 * V_7 ;
int V_72 ;
V_7 = F_3 ( V_3 -> V_7 ) ;
F_30 (state->state, connector, cstate, i) {
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
V_67 -> V_44 = F_31 ( V_65 ) - 1 ;
return 0 ;
}
static int F_32 ( struct V_6 * V_8 ,
struct V_2 * V_91 )
{
int V_92 ;
V_92 = F_29 ( V_91 ) ;
if ( V_92 )
return V_92 ;
V_92 = F_33 ( V_91 ) ;
if ( V_92 )
return V_92 ;
return F_34 ( V_91 ) ;
}
static void F_35 ( struct V_6 * V_8 ,
struct V_2 * V_93 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
if ( V_8 -> V_3 -> V_94 ) {
V_8 -> V_3 -> V_94 -> V_95 = F_36 ( V_8 ) ;
F_37 ( F_38 ( V_8 ) != 0 ) ;
V_7 -> V_94 = V_8 -> V_3 -> V_94 ;
V_8 -> V_3 -> V_94 = NULL ;
}
}
static void F_39 ( struct V_6 * V_7 ,
struct V_2 * V_93 )
{
}
static void F_40 ( struct V_6 * V_8 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
F_41 ( V_8 ) ;
F_42 ( V_7 ) ;
}
static void F_43 ( struct V_5 * V_7 )
{
struct V_55 * V_56 = V_7 -> V_4 . V_56 ;
unsigned long V_39 ;
F_44 ( & V_56 -> V_96 , V_39 ) ;
if ( V_7 -> V_94 ) {
F_45 ( V_56 , V_7 -> V_97 , V_7 -> V_94 ) ;
F_46 ( V_56 , V_7 -> V_97 ) ;
V_7 -> V_94 = NULL ;
}
F_47 ( & V_56 -> V_96 , V_39 ) ;
}
void F_48 ( struct V_6 * V_8 )
{
F_49 ( V_8 -> V_56 , 0 ) ;
F_43 ( F_3 ( V_8 ) ) ;
}
void F_50 ( struct V_6 * V_7 )
{
struct V_1 * V_3 ;
if ( V_7 -> V_3 ) {
F_51 ( V_7 -> V_3 ) ;
V_3 = F_1 ( V_7 -> V_3 ) ;
F_42 ( V_3 ) ;
V_7 -> V_3 = NULL ;
}
V_3 = F_52 ( sizeof( * V_3 ) , V_98 ) ;
if ( V_3 ) {
V_7 -> V_3 = & V_3 -> V_4 ;
V_7 -> V_3 -> V_7 = V_7 ;
}
}
static struct V_2 *
F_53 ( struct V_6 * V_7 )
{
struct V_1 * V_3 , * V_99 ;
if ( F_37 ( ! V_7 -> V_3 ) )
return NULL ;
V_3 = F_54 ( sizeof( * V_3 ) , V_98 ) ;
if ( ! V_3 )
return NULL ;
F_55 ( V_7 , & V_3 -> V_4 ) ;
V_99 = F_1 ( V_7 -> V_3 ) ;
V_3 -> V_44 = V_99 -> V_44 ;
return & V_3 -> V_4 ;
}
static void F_56 ( struct V_6 * V_7 ,
struct V_2 * V_91 )
{
struct V_1 * V_3 ;
V_3 = F_1 ( V_91 ) ;
F_51 ( V_91 ) ;
F_42 ( V_3 ) ;
}
int F_57 ( struct V_55 * V_56 )
{
struct V_100 * V_10 = V_56 -> V_101 ;
struct V_102 * V_103 = V_10 -> V_103 ;
struct V_5 * V_7 ;
int V_92 ;
int V_72 ;
V_7 = F_52 ( sizeof( * V_7 ) , V_98 ) ;
if ( ! V_7 )
return - V_104 ;
V_7 -> V_10 = V_10 ;
V_92 = F_58 ( V_56 , & V_7 -> V_4 ,
& V_103 -> V_105 -> V_4 ,
V_103 -> V_106 ? & V_103 -> V_106 -> V_4 : NULL ,
& V_107 , NULL ) ;
if ( V_92 < 0 )
goto V_108;
V_7 -> V_97 = F_36 ( & V_7 -> V_4 ) ;
if ( V_103 -> V_106 )
V_103 -> V_106 -> V_4 . V_109 = 1 << V_7 -> V_97 ;
for ( V_72 = 0 ; V_72 < V_103 -> V_110 ; V_72 ++ )
V_103 -> V_111 [ V_72 ] -> V_4 . V_109 = 1 << V_7 -> V_97 ;
F_59 ( & V_7 -> V_4 , & V_112 ) ;
F_60 ( & V_7 -> V_4 ) ;
V_10 -> V_7 = & V_7 -> V_4 ;
return 0 ;
V_108:
F_40 ( & V_7 -> V_4 ) ;
return V_92 ;
}
