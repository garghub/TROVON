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
static void F_13 ( struct V_6 * V_8 )
{
struct V_55 * V_56 = V_8 -> V_56 ;
struct V_5 * V_7 = F_3 ( V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 -> V_11 -> V_9 ;
unsigned int V_57 ;
F_14 ( V_8 ) ;
F_15 ( V_56 -> V_56 ) ;
F_5 ( V_9 , V_58 , V_59 ) ;
while ( ! F_16 ( V_9 , V_60 , & V_57 ) &&
( V_57 & V_59 ) )
F_17 () ;
F_5 ( V_9 , V_58 , V_61 ) ;
while ( ! F_16 ( V_9 , V_60 , & V_57 ) &&
( V_57 & V_61 ) )
F_17 () ;
F_5 ( V_9 , V_58 , V_62 ) ;
while ( ! F_16 ( V_9 , V_60 , & V_57 ) &&
( V_57 & V_62 ) )
F_17 () ;
F_18 ( V_7 -> V_10 -> V_11 -> V_34 ) ;
F_19 ( V_56 -> V_56 ) ;
F_20 ( V_56 -> V_56 ) ;
F_21 ( V_56 -> V_56 ) ;
}
static void F_22 ( struct V_6 * V_8 )
{
struct V_55 * V_56 = V_8 -> V_56 ;
struct V_5 * V_7 = F_3 ( V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 -> V_11 -> V_9 ;
unsigned int V_57 ;
F_15 ( V_56 -> V_56 ) ;
F_23 ( V_56 -> V_56 ) ;
F_24 ( V_56 -> V_56 ) ;
F_25 ( V_7 -> V_10 -> V_11 -> V_34 ) ;
F_5 ( V_9 , V_63 , V_62 ) ;
while ( ! F_16 ( V_9 , V_60 , & V_57 ) &&
! ( V_57 & V_62 ) )
F_17 () ;
F_5 ( V_9 , V_63 , V_61 ) ;
while ( ! F_16 ( V_9 , V_60 , & V_57 ) &&
! ( V_57 & V_61 ) )
F_17 () ;
F_5 ( V_9 , V_63 , V_59 ) ;
while ( ! F_16 ( V_9 , V_60 , & V_57 ) &&
! ( V_57 & V_59 ) )
F_17 () ;
F_21 ( V_56 -> V_56 ) ;
F_26 ( V_8 ) ;
}
static int F_27 ( struct V_2 * V_3 )
{
unsigned int V_64 = V_65 ;
struct V_1 * V_66 ;
struct V_67 * V_68 ;
struct V_69 * V_70 ;
struct V_5 * V_7 ;
int V_71 ;
V_7 = F_3 ( V_3 -> V_7 ) ;
F_28 (state->state, connector, cstate, i) {
struct V_72 * V_73 = & V_70 -> V_74 ;
unsigned int V_75 = 0 ;
int V_76 ;
if ( ! V_68 -> V_7 )
continue;
for ( V_76 = 0 ; V_76 < V_73 -> V_77 ; V_76 ++ ) {
switch ( V_73 -> V_78 [ V_76 ] ) {
case V_79 :
V_75 |= V_80 ;
break;
case V_81 :
V_75 |= V_82 ;
break;
case V_83 :
V_75 |= V_84 ;
break;
case V_85 :
V_75 |= V_86 ;
break;
default:
break;
}
}
if ( V_7 -> V_10 -> V_87 -> V_88 )
V_64 &= V_75 ;
else
V_64 |= V_75 ;
}
if ( ! V_64 )
return - V_89 ;
V_66 = F_1 ( V_3 ) ;
V_66 -> V_44 = F_29 ( V_64 ) - 1 ;
return 0 ;
}
static int F_30 ( struct V_6 * V_8 ,
struct V_2 * V_90 )
{
int V_91 ;
V_91 = F_27 ( V_90 ) ;
if ( V_91 )
return V_91 ;
V_91 = F_31 ( V_90 ) ;
if ( V_91 )
return V_91 ;
return F_32 ( V_90 ) ;
}
static void F_33 ( struct V_6 * V_8 ,
struct V_2 * V_92 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
if ( V_8 -> V_3 -> V_93 ) {
V_8 -> V_3 -> V_93 -> V_94 = F_34 ( V_8 ) ;
F_35 ( F_36 ( V_8 ) != 0 ) ;
V_7 -> V_93 = V_8 -> V_3 -> V_93 ;
V_8 -> V_3 -> V_93 = NULL ;
}
}
static void F_37 ( struct V_6 * V_7 ,
struct V_2 * V_92 )
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
struct V_55 * V_56 = V_7 -> V_4 . V_56 ;
unsigned long V_39 ;
F_42 ( & V_56 -> V_95 , V_39 ) ;
if ( V_7 -> V_93 ) {
F_43 ( & V_7 -> V_4 , V_7 -> V_93 ) ;
F_44 ( & V_7 -> V_4 ) ;
V_7 -> V_93 = NULL ;
}
F_45 ( & V_56 -> V_95 , V_39 ) ;
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
V_3 = F_50 ( sizeof( * V_3 ) , V_96 ) ;
if ( V_3 ) {
V_7 -> V_3 = & V_3 -> V_4 ;
V_7 -> V_3 -> V_7 = V_7 ;
}
}
static struct V_2 *
F_51 ( struct V_6 * V_7 )
{
struct V_1 * V_3 , * V_97 ;
if ( F_35 ( ! V_7 -> V_3 ) )
return NULL ;
V_3 = F_52 ( sizeof( * V_3 ) , V_96 ) ;
if ( ! V_3 )
return NULL ;
F_53 ( V_7 , & V_3 -> V_4 ) ;
V_97 = F_1 ( V_7 -> V_3 ) ;
V_3 -> V_44 = V_97 -> V_44 ;
return & V_3 -> V_4 ;
}
static void F_54 ( struct V_6 * V_7 ,
struct V_2 * V_90 )
{
struct V_1 * V_3 ;
V_3 = F_1 ( V_90 ) ;
F_49 ( V_90 ) ;
F_40 ( V_3 ) ;
}
static int F_55 ( struct V_6 * V_8 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 -> V_11 -> V_9 ;
F_5 ( V_9 , V_98 , V_99 ) ;
return 0 ;
}
static void F_56 ( struct V_6 * V_8 )
{
struct V_5 * V_7 = F_3 ( V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 -> V_11 -> V_9 ;
F_5 ( V_9 , V_100 , V_99 ) ;
}
int F_57 ( struct V_55 * V_56 )
{
struct V_101 * V_102 = NULL , * V_103 = NULL ;
struct V_104 * V_10 = V_56 -> V_105 ;
struct V_5 * V_7 ;
int V_91 ;
int V_71 ;
V_7 = F_50 ( sizeof( * V_7 ) , V_96 ) ;
if ( ! V_7 )
return - V_106 ;
V_7 -> V_10 = V_10 ;
for ( V_71 = 0 ; V_71 < V_107 ; V_71 ++ ) {
if ( ! V_10 -> V_108 [ V_71 ] )
continue;
switch ( V_10 -> V_108 [ V_71 ] -> V_87 -> type ) {
case V_109 :
V_102 = F_58 ( V_10 -> V_108 [ V_71 ] ) ;
break;
case V_110 :
V_103 = F_58 ( V_10 -> V_108 [ V_71 ] ) ;
break;
default:
break;
}
}
V_91 = F_59 ( V_56 , & V_7 -> V_4 , & V_102 -> V_4 ,
& V_103 -> V_4 , & V_111 ,
NULL ) ;
if ( V_91 < 0 )
goto V_112;
V_7 -> V_113 = F_34 ( & V_7 -> V_4 ) ;
for ( V_71 = 0 ; V_71 < V_107 ; V_71 ++ ) {
struct V_101 * V_114 ;
if ( V_10 -> V_108 [ V_71 ] &&
V_10 -> V_108 [ V_71 ] -> V_87 -> type == V_115 ) {
V_114 = F_58 ( V_10 -> V_108 [ V_71 ] ) ;
V_114 -> V_4 . V_116 = 1 << V_7 -> V_113 ;
}
}
F_60 ( & V_7 -> V_4 , & V_117 ) ;
F_61 ( & V_7 -> V_4 ) ;
V_10 -> V_7 = & V_7 -> V_4 ;
return 0 ;
V_112:
F_38 ( & V_7 -> V_4 ) ;
return V_91 ;
}
