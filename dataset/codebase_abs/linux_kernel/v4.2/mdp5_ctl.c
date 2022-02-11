static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static inline
void F_4 ( struct V_9 * V_10 , T_1 V_11 , T_1 V_12 )
{
struct V_1 * V_1 = F_1 ( V_10 -> V_13 ) ;
( void ) V_10 -> V_14 ;
F_5 ( V_1 , V_11 , V_12 ) ;
}
static inline
T_1 F_6 ( struct V_9 * V_10 , T_1 V_11 )
{
struct V_1 * V_1 = F_1 ( V_10 -> V_13 ) ;
( void ) V_10 -> V_14 ;
return F_7 ( V_1 , V_11 ) ;
}
static void F_8 ( struct V_1 * V_1 ,
struct V_15 * V_16 )
{
unsigned long V_17 ;
T_1 V_18 ;
F_9 ( & V_1 -> V_19 , V_17 ) ;
V_18 = F_7 ( V_1 , F_10 ( 0 ) ) ;
switch ( V_16 -> V_20 ) {
case 0 :
V_18 &= ~ V_21 ;
V_18 |= F_11 ( V_16 -> type ) ;
break;
case 1 :
V_18 &= ~ V_22 ;
V_18 |= F_12 ( V_16 -> type ) ;
break;
case 2 :
V_18 &= ~ V_23 ;
V_18 |= F_13 ( V_16 -> type ) ;
break;
case 3 :
V_18 &= ~ V_24 ;
V_18 |= F_14 ( V_16 -> type ) ;
break;
default:
F_15 () ;
break;
}
F_5 ( V_1 , F_10 ( 0 ) , V_18 ) ;
F_16 ( & V_1 -> V_19 , V_17 ) ;
}
static void F_17 ( struct V_9 * V_10 , struct V_15 * V_16 )
{
unsigned long V_17 ;
T_1 V_25 = 0 ;
if ( ! F_18 ( V_16 -> type ) )
V_25 |= F_19 ( V_26 + V_16 -> V_20 ) ;
switch ( V_16 -> type ) {
case V_27 :
if ( V_16 -> V_28 == V_29 )
V_25 |= V_30 ;
break;
case V_31 :
if ( V_16 -> V_28 == V_32 )
V_25 |= F_20 ( V_33 ) ;
break;
default:
break;
}
F_9 ( & V_10 -> V_34 , V_17 ) ;
F_4 ( V_10 , F_21 ( V_10 -> V_35 ) , V_25 ) ;
F_16 ( & V_10 -> V_34 , V_17 ) ;
}
int F_22 ( struct V_9 * V_10 , struct V_15 * V_16 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
memcpy ( & V_10 -> V_36 . V_16 , V_16 , sizeof( * V_16 ) ) ;
V_10 -> V_36 . V_37 = F_23 ( V_10 -> V_38 ) |
F_24 ( V_16 ) ;
if ( ! F_18 ( V_16 -> type ) )
F_8 ( V_1 , V_16 ) ;
F_17 ( V_10 , V_16 ) ;
return 0 ;
}
static bool F_25 ( struct V_9 * V_10 )
{
struct V_39 * V_36 = & V_10 -> V_36 ;
if ( ! V_36 -> V_40 || V_36 -> V_37 != 0 )
return false ;
switch ( V_36 -> V_16 . type ) {
case V_31 :
return true ;
case V_27 :
return V_36 -> V_16 . V_28 == V_29 ;
default:
return false ;
}
}
static void F_26 ( struct V_9 * V_10 )
{
unsigned long V_17 ;
F_9 ( & V_10 -> V_34 , V_17 ) ;
F_4 ( V_10 , F_27 ( V_10 -> V_35 ) , 1 ) ;
F_16 ( & V_10 -> V_34 , V_17 ) ;
}
static void F_28 ( struct V_9 * V_10 )
{
struct V_39 * V_36 = & V_10 -> V_36 ;
struct V_15 * V_16 = & V_10 -> V_36 . V_16 ;
V_36 -> V_37 = F_23 ( V_10 -> V_38 ) ;
if ( V_16 -> type == V_31 )
V_36 -> V_37 |= F_24 ( V_16 ) ;
}
int F_29 ( struct V_9 * V_10 , bool V_41 )
{
if ( F_30 ( ! V_10 ) )
return - V_42 ;
V_10 -> V_36 . V_40 = V_41 ;
F_31 ( L_1 , V_10 -> V_36 . V_16 . V_20 , V_41 ? L_2 : L_3 ) ;
if ( F_25 ( V_10 ) ) {
F_26 ( V_10 ) ;
F_28 ( V_10 ) ;
}
return 0 ;
}
int F_32 ( struct V_9 * V_10 , int V_43 , bool V_44 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
unsigned long V_17 ;
T_1 V_45 ;
int V_38 = V_10 -> V_38 ;
if ( F_33 ( F_30 ( V_38 < 0 ) ) ) {
F_34 ( V_3 -> V_6 -> V_6 , L_4 ,
V_10 -> V_35 , V_38 ) ;
return - V_42 ;
}
F_9 ( & V_10 -> V_34 , V_17 ) ;
V_45 = F_6 ( V_10 , F_35 ( V_10 -> V_35 , V_38 ) ) ;
if ( V_44 )
V_45 |= V_46 ;
else
V_45 &= ~ V_46 ;
F_4 ( V_10 , F_35 ( V_10 -> V_35 , V_38 ) , V_45 ) ;
F_16 ( & V_10 -> V_34 , V_17 ) ;
V_10 -> V_47 = F_36 ( V_43 ) ;
V_10 -> V_48 = V_44 ;
return 0 ;
}
int F_37 ( struct V_9 * V_10 , T_1 V_38 , T_1 V_45 )
{
unsigned long V_17 ;
if ( V_10 -> V_48 )
V_45 |= V_46 ;
else
V_45 &= ~ V_46 ;
F_9 ( & V_10 -> V_34 , V_17 ) ;
F_4 ( V_10 , F_35 ( V_10 -> V_35 , V_38 ) , V_45 ) ;
F_16 ( & V_10 -> V_34 , V_17 ) ;
V_10 -> V_47 = F_23 ( V_38 ) ;
return 0 ;
}
T_1 F_24 ( struct V_15 * V_16 )
{
if ( V_16 -> type == V_31 )
return V_49 ;
switch ( V_16 -> V_20 ) {
case 0 : return V_50 ;
case 1 : return V_51 ;
case 2 : return V_52 ;
case 3 : return V_53 ;
default: return 0 ;
}
}
T_1 F_36 ( int V_43 )
{
switch ( V_43 ) {
case 0 : return V_54 ;
case 1 : return V_55 ;
default: return 0 ;
}
}
T_1 F_38 ( enum V_56 V_57 )
{
switch ( V_57 ) {
case V_58 : return V_59 ;
case V_60 : return V_61 ;
case V_62 : return V_63 ;
case V_64 : return V_65 ;
case V_66 : return V_67 ;
case V_68 : return V_69 ;
case V_70 : return V_71 ;
case V_72 : return V_73 ;
case V_74 : return V_75 ;
case V_76 : return V_77 ;
default: return 0 ;
}
}
T_1 F_23 ( int V_38 )
{
switch ( V_38 ) {
case 0 : return V_78 ;
case 1 : return V_79 ;
case 2 : return V_80 ;
case 5 : return V_81 ;
default: return 0 ;
}
}
static T_1 F_39 ( struct V_9 * V_10 , T_1 V_82 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
T_1 V_83 = 0 ;
#define F_40 ( T_2 ) \
(!(ctl_mgr->flush_hw_mask & bit) && (flush_mask & bit))
if ( F_40 ( V_54 ) )
V_83 |= F_23 ( V_10 -> V_38 ) ;
return V_83 ;
}
T_1 F_41 ( struct V_9 * V_10 , T_1 V_82 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
struct V_39 * V_36 = & V_10 -> V_36 ;
unsigned long V_17 ;
V_36 -> V_37 &= ~ V_82 ;
F_42 ( L_5 , V_82 ,
V_36 -> V_37 , V_10 -> V_47 ) ;
if ( V_10 -> V_47 & V_82 ) {
V_82 |= V_84 ;
V_10 -> V_47 = 0 ;
}
V_82 |= F_39 ( V_10 , V_82 ) ;
V_82 &= V_3 -> V_85 ;
if ( V_82 ) {
F_9 ( & V_10 -> V_34 , V_17 ) ;
F_4 ( V_10 , F_43 ( V_10 -> V_35 ) , V_82 ) ;
F_16 ( & V_10 -> V_34 , V_17 ) ;
}
if ( F_25 ( V_10 ) ) {
F_26 ( V_10 ) ;
F_28 ( V_10 ) ;
}
return V_82 ;
}
T_1 F_44 ( struct V_9 * V_10 )
{
return F_6 ( V_10 , F_43 ( V_10 -> V_35 ) ) ;
}
void F_45 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
unsigned long V_17 ;
if ( F_33 ( F_30 ( V_10 -> V_35 >= V_86 ) || ! V_10 -> V_87 ) ) {
F_34 ( V_3 -> V_6 -> V_6 , L_6 ,
V_10 -> V_35 , V_10 -> V_87 ) ;
return;
}
F_9 ( & V_3 -> V_88 , V_17 ) ;
V_10 -> V_87 = false ;
F_16 ( & V_3 -> V_88 , V_17 ) ;
F_31 ( L_7 , V_10 -> V_35 ) ;
}
int F_46 ( struct V_9 * V_10 )
{
return F_30 ( ! V_10 ) ? - V_42 : V_10 -> V_35 ;
}
struct V_9 * F_47 ( struct V_2 * V_3 ,
struct V_89 * V_90 )
{
struct V_9 * V_10 = NULL ;
unsigned long V_17 ;
int V_91 ;
F_9 ( & V_3 -> V_88 , V_17 ) ;
for ( V_91 = 0 ; V_91 < V_3 -> V_92 ; V_91 ++ )
if ( ! V_3 -> V_93 [ V_91 ] . V_87 )
break;
if ( F_33 ( V_91 >= V_3 -> V_92 ) ) {
F_34 ( V_3 -> V_6 -> V_6 , L_8 ) ;
goto V_94;
}
V_10 = & V_3 -> V_93 [ V_91 ] ;
V_10 -> V_38 = F_48 ( V_90 ) ;
V_10 -> V_90 = V_90 ;
V_10 -> V_87 = true ;
V_10 -> V_47 = 0 ;
F_31 ( L_9 , V_10 -> V_35 ) ;
V_94:
F_16 ( & V_3 -> V_88 , V_17 ) ;
return V_10 ;
}
void F_49 ( struct V_2 * V_3 )
{
unsigned long V_17 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_3 -> V_92 ; V_91 ++ ) {
struct V_9 * V_10 = & V_3 -> V_93 [ V_91 ] ;
F_9 ( & V_10 -> V_34 , V_17 ) ;
F_4 ( V_10 , F_21 ( V_10 -> V_35 ) , 0 ) ;
F_16 ( & V_10 -> V_34 , V_17 ) ;
}
}
void F_50 ( struct V_2 * V_3 )
{
F_51 ( V_3 ) ;
}
struct V_2 * F_52 ( struct V_95 * V_6 ,
void T_3 * V_96 , const struct V_97 * V_98 )
{
struct V_2 * V_3 ;
const struct V_99 * V_100 = & V_98 -> V_10 ;
unsigned long V_17 ;
int V_91 , V_101 ;
V_3 = F_53 ( sizeof( * V_3 ) , V_102 ) ;
if ( ! V_3 ) {
F_34 ( V_6 -> V_6 , L_10 ) ;
V_101 = - V_103 ;
goto V_104;
}
if ( F_33 ( F_30 ( V_100 -> V_105 > V_86 ) ) ) {
F_34 ( V_6 -> V_6 , L_11 ,
V_100 -> V_105 ) ;
V_101 = - V_106 ;
goto V_104;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_107 = V_98 -> V_38 . V_105 ;
V_3 -> V_92 = V_100 -> V_105 ;
V_3 -> V_85 = V_100 -> V_85 ;
F_54 ( & V_3 -> V_88 ) ;
F_9 ( & V_3 -> V_88 , V_17 ) ;
for ( V_91 = 0 ; V_91 < V_3 -> V_92 ; V_91 ++ ) {
struct V_9 * V_10 = & V_3 -> V_93 [ V_91 ] ;
if ( F_30 ( ! V_100 -> V_108 [ V_91 ] ) ) {
F_34 ( V_6 -> V_6 , L_12 , V_91 ) ;
V_101 = - V_42 ;
goto V_104;
}
V_10 -> V_13 = V_3 ;
V_10 -> V_35 = V_91 ;
V_10 -> V_14 = V_100 -> V_108 [ V_91 ] ;
V_10 -> V_87 = false ;
F_54 ( & V_10 -> V_34 ) ;
}
F_16 ( & V_3 -> V_88 , V_17 ) ;
F_31 ( L_13 , V_3 -> V_92 ) ;
return V_3 ;
V_104:
if ( V_3 )
F_50 ( V_3 ) ;
return F_55 ( V_101 ) ;
}
