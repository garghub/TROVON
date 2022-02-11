static T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static inline int F_2 ( int V_3 , bool V_4 )
{
int V_5 , V_6 , V_7 ;
if ( ! V_3 )
return V_3 ;
if ( V_4 )
V_5 = V_8 [ V_3 ] ;
else
V_5 = V_9 [ V_3 ] ;
if ( V_5 )
return V_5 ;
if ( V_10 &&
F_3 ( V_3 , V_10 -> V_11 ) ) {
V_6 = F_4 ( V_10 -> V_11 ,
V_12 ) ;
if ( V_4 )
V_7 = V_13 - V_14 . V_4 ;
else
V_7 = V_15 - V_14 . V_16 ;
V_5 = V_7 + ( ( V_3 - V_6 ) << 1 ) ;
} else if ( ! V_17 )
V_5 = V_3 ;
else
V_5 = V_3 << 1 ;
if ( V_4 )
V_8 [ V_3 ] = V_5 ;
else
V_9 [ V_3 ] = V_5 ;
return V_5 ;
}
static inline int F_5 ( int V_3 )
{
int V_18 , V_6 ;
if ( ! V_3 )
return V_3 ;
V_18 = V_19 [ V_3 ] ;
if ( V_18 )
return V_18 ;
if ( V_10 &&
F_3 ( V_3 , V_10 -> V_11 ) ) {
V_6 = F_4 ( V_10 -> V_11 ,
V_12 ) ;
V_18 = V_3 - V_6 + 6 ;
} else
V_18 = V_3 ;
V_19 [ V_3 ] = V_18 ;
return V_18 ;
}
static int F_6 ( struct V_20 * V_21 )
{
if ( V_21 -> V_22 . V_23 && V_21 -> V_22 . V_24 )
V_21 -> V_25 . V_26 &= ~ ( V_27 |
V_28 ) ;
else if ( V_21 -> V_22 . V_23 )
V_21 -> V_25 . V_26 |= V_29 ;
else if ( V_21 -> V_22 . V_24 )
V_21 -> V_25 . V_26 |= V_30 ;
return 0 ;
}
static int F_7 ( struct V_20 * V_21 )
{
if ( F_8 ( V_21 ) || V_21 -> V_31 & V_32 )
return - V_33 ;
if ( V_21 -> V_22 . V_34 || V_21 -> V_22 . V_35 ||
V_21 -> V_22 . V_23 || V_21 -> V_22 . V_24 )
return - V_33 ;
V_21 -> V_25 . V_26 &= ~ ( V_27 |
V_28 ) ;
if ( V_21 -> V_25 . V_26 & ~ ( V_36 |
V_37 ) )
return - V_33 ;
return 0 ;
}
static inline unsigned int F_9 ( struct V_38 * V_39 )
{
return ( ( V_39 -> V_26 >> 24 ) & 0x0f00 ) | ( V_39 -> V_26 & 0x00ff ) ;
}
static inline int F_10 ( struct V_38 * V_39 )
{
return ( V_39 -> V_26 & 0xe0 ) == 0xe0 ;
}
static inline int F_11 ( struct V_38 * V_39 )
{
return V_10 && F_10 ( V_39 ) ;
}
static inline int F_12 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_42 ;
return V_43 && V_43 -> V_44 != - 1 ;
}
static int F_13 ( struct V_20 * V_21 )
{
int V_18 ;
if ( V_21 -> V_22 . V_45 && F_14 () )
return - V_46 ;
if ( F_15 ( V_21 ) )
return - V_47 ;
V_18 = F_16 ( V_21 ) ;
if ( V_18 )
return V_18 ;
if ( V_21 -> V_22 . type == V_48 )
V_21 -> V_25 . V_26 |= V_21 -> V_22 . V_26 & V_49 ;
if ( F_11 ( & V_21 -> V_25 ) )
return F_7 ( V_21 ) ;
return F_6 ( V_21 ) ;
}
static void F_17 ( struct V_40 * V_41 ,
struct V_20 * V_21 )
{
struct V_42 * V_43 = V_41 -> V_42 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_14 . V_51 ; V_50 ++ ) {
if ( F_18 ( V_43 -> V_52 + V_50 , V_21 , NULL ) == V_21 )
break;
}
}
static void F_19 ( struct V_38 * V_39 )
{
int V_53 = F_20 ( F_21 () ) . V_54 ;
if ( V_39 -> V_26 & V_37 ) {
V_39 -> V_26 |= V_55 ;
V_39 -> V_26 &= ~ V_56 ;
V_39 -> V_26 |= ( T_1 ) ( V_53 ) <<
V_57 ;
}
}
static struct V_58 *
F_22 ( struct V_40 * V_41 , struct V_20 * V_21 ,
struct V_58 * V_59 )
{
struct V_38 * V_39 = & V_21 -> V_25 ;
struct V_42 * V_43 = V_41 -> V_42 ;
struct V_20 * V_60 ;
int V_61 , V_62 = - 1 ;
if ( ! V_59 )
V_59 = & V_63 ;
if ( V_41 -> V_64 )
return V_59 ;
F_23 (idx, c->idxmsk, x86_pmu.num_counters) {
if ( V_62 == - 1 || V_39 -> V_61 == V_61 )
V_60 = F_18 ( V_43 -> V_52 + V_61 , NULL , V_21 ) ;
else if ( V_43 -> V_52 [ V_61 ] == V_21 )
V_60 = V_21 ;
else
continue;
if ( V_60 && V_60 != V_21 )
continue;
if ( V_62 != - 1 )
F_18 ( V_43 -> V_52 + V_62 , V_21 , NULL ) ;
V_62 = V_61 ;
if ( V_60 == V_21 )
break;
}
if ( V_62 == - 1 )
return & V_65 ;
if ( F_11 ( V_39 ) )
F_19 ( V_39 ) ;
return & V_43 -> V_66 [ V_62 ] ;
}
static struct V_42 * F_24 ( int V_67 )
{
struct V_42 * V_43 ;
int V_50 ;
V_43 = F_25 ( sizeof( struct V_42 ) , V_68 | V_69 ,
F_26 ( V_67 ) ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_44 = - 1 ;
for ( V_50 = 0 ; V_50 < V_14 . V_51 ; V_50 ++ ) {
F_27 ( V_50 , V_43 -> V_66 [ V_50 ] . V_11 ) ;
V_43 -> V_66 [ V_50 ] . V_70 = 1 ;
}
return V_43 ;
}
static int F_28 ( int V_67 )
{
struct V_40 * V_41 = & F_29 ( V_40 , V_67 ) ;
F_30 ( V_41 -> V_42 ) ;
if ( V_71 . V_72 < 2 )
return V_73 ;
V_41 -> V_42 = F_24 ( V_67 ) ;
if ( ! V_41 -> V_42 )
return V_74 ;
return V_73 ;
}
static void F_31 ( int V_67 )
{
struct V_40 * V_41 = & F_29 ( V_40 , V_67 ) ;
struct V_42 * V_43 ;
int V_50 , V_44 ;
V_41 -> V_75 = V_30 ;
if ( V_71 . V_72 < 2 )
return;
V_44 = F_32 ( V_67 ) ;
F_30 ( V_44 == V_76 ) ;
F_33 (i) {
V_43 = F_29 ( V_40 , V_50 ) . V_42 ;
if ( F_30 ( ! V_43 ) )
continue;
if ( V_43 -> V_44 == V_44 ) {
V_41 -> V_77 = V_41 -> V_42 ;
V_41 -> V_42 = V_43 ;
break;
}
}
V_41 -> V_42 -> V_44 = V_44 ;
V_41 -> V_42 -> V_78 ++ ;
}
static void F_34 ( int V_67 )
{
struct V_40 * V_79 ;
if ( V_71 . V_72 < 2 )
return;
V_79 = & F_29 ( V_40 , V_67 ) ;
if ( V_79 -> V_42 ) {
struct V_42 * V_43 = V_79 -> V_42 ;
if ( V_43 -> V_44 == - 1 || -- V_43 -> V_78 == 0 )
F_35 ( V_43 ) ;
V_79 -> V_42 = NULL ;
}
}
static struct V_58 *
F_36 ( struct V_40 * V_41 , struct V_20 * V_21 )
{
if ( ! ( F_12 ( V_41 ) && F_10 ( & V_21 -> V_25 ) ) )
return & V_63 ;
return F_22 ( V_41 , V_21 ,
V_10 ) ;
}
static void F_37 ( struct V_40 * V_41 ,
struct V_20 * V_21 )
{
if ( F_12 ( V_41 ) && F_10 ( & V_21 -> V_25 ) )
F_17 ( V_41 , V_21 ) ;
}
static struct V_58 *
F_38 ( struct V_40 * V_41 , struct V_20 * V_21 )
{
struct V_38 * V_39 = & V_21 -> V_25 ;
unsigned int V_80 = F_9 ( V_39 ) ;
switch ( V_80 & V_81 ) {
case V_82 :
switch ( V_80 ) {
case 0x000 :
if ( ! ( V_39 -> V_26 & 0x0000F000ULL ) )
break;
if ( ! ( V_39 -> V_26 & 0x00000F00ULL ) )
break;
return & V_83 ;
case 0x004 :
if ( F_39 ( V_39 -> V_26 & V_84 ) <= 1 )
break;
return & V_83 ;
case 0x003 :
case 0x00B :
case 0x00D :
return & V_83 ;
}
return & V_85 ;
case V_86 :
case V_87 :
case V_88 :
switch ( V_80 ) {
case 0x023 :
case 0x043 :
case 0x045 :
case 0x046 :
case 0x054 :
case 0x055 :
return & V_89 ;
case 0x02D :
return & V_83 ;
case 0x02E :
return & V_90 ;
case 0x031 :
if ( F_39 ( V_39 -> V_26 & V_84 ) <= 1 )
return & V_89 ;
return & V_65 ;
case 0x1C0 :
return & V_85 ;
default:
return & V_91 ;
}
case V_92 :
case V_93 :
case V_94 :
switch ( V_80 ) {
case 0x08F :
case 0x187 :
case 0x188 :
return & V_95 ;
case 0x0DB ... 0x0DF :
case 0x1D6 :
case 0x1D8 :
return & V_91 ;
default:
return & V_89 ;
}
case V_96 :
return F_22 ( V_41 , V_21 ,
V_10 ) ;
default:
return & V_65 ;
}
}
static T_2 F_40 ( char * V_97 , T_1 V_26 )
{
T_1 V_21 = ( V_26 & V_98 ) |
( V_26 & V_99 ) >> 24 ;
return F_41 ( V_97 , V_26 , V_21 ) ;
}
static int F_42 ( void )
{
if ( V_71 . V_100 == 0x15 )
V_14 . V_101 = F_38 ;
return 0 ;
}
static int F_43 ( void )
{
if ( ! V_17 ) {
F_44 ( V_14 . V_101 == F_38 ,
V_102 L_1 ) ;
return - V_103 ;
}
F_44 ( V_14 . V_101 == F_36 ,
V_102 L_2 ) ;
V_14 . V_4 = V_104 ;
V_14 . V_16 = V_105 ;
V_14 . V_51 = V_106 ;
F_45 ( V_107 L_3 ) ;
return 0 ;
}
static int F_46 ( void )
{
if ( ! V_108 )
return - V_103 ;
V_14 . V_51 += V_109 ;
if ( V_17 )
V_10 = & V_110 ;
else
V_10 = & V_111 ;
F_45 ( V_107 L_4 ) ;
return 0 ;
}
T_3 int F_47 ( void )
{
if ( V_71 . V_100 < 6 )
return - V_103 ;
V_14 = V_112 ;
F_42 () ;
F_43 () ;
F_46 () ;
memcpy ( V_113 , V_114 ,
sizeof( V_113 ) ) ;
return 0 ;
}
void F_48 ( void )
{
struct V_40 * V_41 = & F_49 ( V_40 ) ;
V_41 -> V_75 = 0 ;
F_50 () ;
F_51 ( 0 ) ;
}
void F_52 ( void )
{
struct V_40 * V_41 = & F_49 ( V_40 ) ;
V_41 -> V_75 = V_30 ;
F_50 () ;
F_51 ( 0 ) ;
}
