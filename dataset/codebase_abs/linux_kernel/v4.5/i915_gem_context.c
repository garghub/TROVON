static T_1 F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return V_3 ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
T_2 V_9 ;
switch ( F_4 ( V_2 ) -> V_10 ) {
case 6 :
V_9 = F_5 ( V_11 ) ;
V_8 = F_6 ( V_9 ) * 64 ;
break;
case 7 :
V_9 = F_5 ( V_12 ) ;
if ( F_7 ( V_2 ) )
V_8 = V_13 ;
else
V_8 = F_8 ( V_9 ) * 64 ;
break;
case 8 :
V_8 = V_14 ;
break;
default:
F_9 () ;
}
return V_8 ;
}
static void F_10 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_20 , * V_21 ;
if ( ! V_18 )
return;
F_11 (vma, next, &ppgtt->base.inactive_list,
mm_list) {
if ( F_12 ( F_13 ( V_20 ) ) )
break;
}
}
void F_14 ( struct V_22 * V_23 )
{
struct V_15 * V_16 = F_15 ( V_23 , F_16 ( * V_16 ) , V_24 ) ;
F_17 ( V_16 ) ;
if ( V_25 . V_26 )
F_18 ( V_16 ) ;
F_10 ( V_16 ) ;
F_19 ( V_16 -> V_18 ) ;
if ( V_16 -> V_27 . V_28 )
F_20 ( & V_16 -> V_27 . V_28 -> V_29 ) ;
F_21 ( & V_16 -> V_30 ) ;
F_22 ( V_16 ) ;
}
struct V_31 *
F_23 ( struct V_1 * V_2 , T_1 V_32 )
{
struct V_31 * V_33 ;
int V_8 ;
V_33 = F_24 ( V_2 , V_32 ) ;
if ( V_33 == NULL )
return F_25 ( - V_34 ) ;
if ( F_26 ( V_2 ) ) {
V_8 = F_27 ( V_33 , V_35 ) ;
if ( F_12 ( V_8 ) ) {
F_20 ( & V_33 -> V_29 ) ;
return F_25 ( V_8 ) ;
}
}
return V_33 ;
}
static struct V_15 *
F_28 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_15 * V_16 ;
int V_8 ;
V_16 = F_29 ( sizeof( * V_16 ) , V_38 ) ;
if ( V_16 == NULL )
return F_25 ( - V_34 ) ;
F_30 ( & V_16 -> V_24 ) ;
F_31 ( & V_16 -> V_30 , & V_6 -> V_39 ) ;
V_16 -> V_25 = V_6 ;
if ( V_6 -> V_40 ) {
struct V_31 * V_33 =
F_23 ( V_2 , V_6 -> V_40 ) ;
if ( F_32 ( V_33 ) ) {
V_8 = F_33 ( V_33 ) ;
goto V_41;
}
V_16 -> V_27 . V_28 = V_33 ;
}
if ( V_37 != NULL ) {
V_8 = F_34 ( & V_37 -> V_42 , V_16 ,
V_43 , 0 , V_38 ) ;
if ( V_8 < 0 )
goto V_41;
} else
V_8 = V_43 ;
V_16 -> V_37 = V_37 ;
V_16 -> V_44 = V_8 ;
V_16 -> V_45 = ( 1 << F_35 ( V_2 ) ) - 1 ;
V_16 -> V_46 . V_47 = V_48 ;
return V_16 ;
V_41:
F_36 ( V_16 ) ;
return F_25 ( V_8 ) ;
}
static struct V_15 *
F_37 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
const bool V_49 = V_37 == NULL ;
struct V_15 * V_16 ;
int V_8 = 0 ;
F_38 ( ! F_39 ( & V_2 -> V_50 ) ) ;
V_16 = F_28 ( V_2 , V_37 ) ;
if ( F_32 ( V_16 ) )
return V_16 ;
if ( V_49 && V_16 -> V_27 . V_28 ) {
V_8 = F_40 ( V_16 -> V_27 . V_28 ,
F_1 ( V_2 ) , 0 ) ;
if ( V_8 ) {
F_41 ( L_1 , V_8 ) ;
goto V_51;
}
}
if ( F_42 ( V_2 ) ) {
struct V_17 * V_18 = F_43 ( V_2 , V_37 ) ;
if ( F_44 ( V_18 ) ) {
F_41 ( L_2 ,
F_33 ( V_18 ) ) ;
V_8 = F_33 ( V_18 ) ;
goto V_52;
}
V_16 -> V_18 = V_18 ;
}
F_45 ( V_16 ) ;
return V_16 ;
V_52:
if ( V_49 && V_16 -> V_27 . V_28 )
F_46 ( V_16 -> V_27 . V_28 ) ;
V_51:
F_47 ( & V_37 -> V_42 , V_16 -> V_44 ) ;
F_36 ( V_16 ) ;
return F_25 ( V_8 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_53 ;
if ( V_25 . V_26 ) {
struct V_15 * V_16 ;
F_49 (ctx, &dev_priv->context_list, link) {
F_50 ( V_2 , V_16 ) ;
}
return;
}
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
struct V_55 * V_56 = & V_6 -> V_56 [ V_53 ] ;
struct V_15 * V_57 = V_56 -> V_58 ;
if ( V_57 ) {
if ( V_57 -> V_27 . V_28 && V_53 == V_59 )
F_46 ( V_57 -> V_27 . V_28 ) ;
F_36 ( V_57 ) ;
V_56 -> V_58 = NULL ;
}
if ( V_56 -> V_60 )
V_56 -> V_60 -> V_27 . V_61 = false ;
}
}
int F_51 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_15 * V_16 ;
int V_53 ;
if ( F_12 ( V_6 -> V_56 [ V_59 ] . V_60 ) )
return 0 ;
if ( F_52 ( V_2 ) && F_53 ( V_2 ) ) {
if ( ! V_25 . V_26 ) {
F_54 ( L_3 ) ;
return - V_62 ;
}
}
if ( V_25 . V_26 ) {
V_6 -> V_40 = 0 ;
} else if ( F_55 ( V_2 ) ) {
V_6 -> V_40 = F_56 ( F_3 ( V_2 ) , 4096 ) ;
if ( V_6 -> V_40 > ( 1 << 20 ) ) {
F_41 ( L_4 ,
V_6 -> V_40 ) ;
V_6 -> V_40 = 0 ;
}
}
V_16 = F_37 ( V_2 , NULL ) ;
if ( F_32 ( V_16 ) ) {
F_57 ( L_5 ,
F_33 ( V_16 ) ) ;
return F_33 ( V_16 ) ;
}
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
struct V_55 * V_56 = & V_6 -> V_56 [ V_53 ] ;
V_56 -> V_60 = V_16 ;
}
F_41 ( L_6 ,
V_25 . V_26 ? L_7 :
V_6 -> V_40 ? L_8 : L_9 ) ;
return 0 ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_15 * V_63 = V_6 -> V_56 [ V_59 ] . V_60 ;
int V_53 ;
if ( V_63 -> V_27 . V_28 ) {
F_59 ( V_2 ) ;
F_12 ( ! V_6 -> V_56 [ V_59 ] . V_58 ) ;
if ( V_6 -> V_56 [ V_59 ] . V_58 == V_63 ) {
F_12 ( V_63 -> V_27 . V_28 -> V_64 ) ;
F_46 ( V_63 -> V_27 . V_28 ) ;
F_36 ( V_63 ) ;
V_6 -> V_56 [ V_59 ] . V_58 = NULL ;
}
F_46 ( V_63 -> V_27 . V_28 ) ;
}
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
struct V_55 * V_56 = & V_6 -> V_56 [ V_53 ] ;
if ( V_56 -> V_58 )
F_36 ( V_56 -> V_58 ) ;
V_56 -> V_60 = NULL ;
V_56 -> V_58 = NULL ;
}
F_36 ( V_63 ) ;
}
int F_60 ( struct V_65 * V_66 )
{
struct V_55 * V_56 = V_66 -> V_56 ;
int V_8 ;
if ( V_25 . V_26 ) {
if ( V_56 -> V_67 == NULL )
return 0 ;
V_8 = V_56 -> V_67 ( V_66 ) ;
} else
V_8 = F_61 ( V_66 ) ;
if ( V_8 ) {
F_57 ( L_10 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_62 ( int V_68 , void * V_69 , void * V_70 )
{
struct V_15 * V_16 = V_69 ;
F_36 ( V_16 ) ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
struct V_36 * V_37 = V_72 -> V_73 ;
struct V_15 * V_16 ;
F_64 ( & V_37 -> V_42 ) ;
F_65 ( & V_2 -> V_50 ) ;
V_16 = F_37 ( V_2 , V_37 ) ;
F_66 ( & V_2 -> V_50 ) ;
if ( F_32 ( V_16 ) ) {
F_67 ( & V_37 -> V_42 ) ;
return F_33 ( V_16 ) ;
}
return 0 ;
}
void F_68 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
struct V_36 * V_37 = V_72 -> V_73 ;
F_69 ( & V_37 -> V_42 , F_62 , NULL ) ;
F_67 ( & V_37 -> V_42 ) ;
}
struct V_15 *
F_70 ( struct V_36 * V_37 , T_2 V_68 )
{
struct V_15 * V_16 ;
V_16 = (struct V_15 * ) F_71 ( & V_37 -> V_42 , V_68 ) ;
if ( ! V_16 )
return F_25 ( - V_74 ) ;
return V_16 ;
}
static inline int
F_72 ( struct V_65 * V_66 , T_2 V_75 )
{
struct V_55 * V_56 = V_66 -> V_56 ;
T_2 V_76 = V_75 | V_77 ;
const int V_78 =
F_73 ( V_56 -> V_2 ) ?
F_74 ( F_4 ( V_56 -> V_2 ) -> V_79 ) - 1 :
0 ;
int V_80 , V_53 , V_8 ;
if ( F_2 ( V_56 -> V_2 ) ) {
V_8 = V_56 -> V_81 ( V_66 , V_82 , 0 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_7 ( V_56 -> V_2 ) || F_4 ( V_56 -> V_2 ) -> V_10 >= 8 )
V_76 |= ( V_83 | V_84 ) ;
else if ( F_4 ( V_56 -> V_2 ) -> V_10 < 8 )
V_76 |= ( V_85 | V_86 ) ;
V_80 = 4 ;
if ( F_4 ( V_56 -> V_2 ) -> V_10 >= 7 )
V_80 += 2 + ( V_78 ? 4 * V_78 + 2 : 0 ) ;
V_8 = F_75 ( V_66 , V_80 ) ;
if ( V_8 )
return V_8 ;
if ( F_4 ( V_56 -> V_2 ) -> V_10 >= 7 ) {
F_76 ( V_56 , V_87 | V_88 ) ;
if ( V_78 ) {
struct V_55 * V_89 ;
F_76 ( V_56 , F_77 ( V_78 ) ) ;
F_78 (signaller, to_i915(ring->dev), i) {
if ( V_89 == V_56 )
continue;
F_79 ( V_56 , F_80 ( V_89 -> V_90 ) ) ;
F_76 ( V_56 , F_81 ( V_91 ) ) ;
}
}
}
F_76 ( V_56 , V_92 ) ;
F_76 ( V_56 , V_93 ) ;
F_76 ( V_56 , F_82 ( V_66 -> V_16 -> V_27 . V_28 ) |
V_76 ) ;
F_76 ( V_56 , V_92 ) ;
if ( F_4 ( V_56 -> V_2 ) -> V_10 >= 7 ) {
if ( V_78 ) {
struct V_55 * V_89 ;
F_76 ( V_56 , F_77 ( V_78 ) ) ;
F_78 (signaller, to_i915(ring->dev), i) {
if ( V_89 == V_56 )
continue;
F_79 ( V_56 , F_80 ( V_89 -> V_90 ) ) ;
F_76 ( V_56 , F_83 ( V_91 ) ) ;
}
}
F_76 ( V_56 , V_87 | V_94 ) ;
}
F_84 ( V_56 ) ;
return V_8 ;
}
static inline bool F_85 ( struct V_55 * V_56 ,
struct V_15 * V_95 ,
struct V_15 * V_96 )
{
if ( V_96 -> V_45 )
return false ;
if ( V_96 -> V_18 && V_95 == V_96 &&
! ( F_86 ( V_56 ) & V_96 -> V_18 -> V_97 ) )
return true ;
return false ;
}
static bool
F_87 ( struct V_55 * V_56 , struct V_15 * V_96 )
{
struct V_5 * V_6 = V_56 -> V_2 -> V_7 ;
if ( ! V_96 -> V_18 )
return false ;
if ( F_4 ( V_56 -> V_2 ) -> V_10 < 8 )
return true ;
if ( V_56 != & V_6 -> V_56 [ V_59 ] )
return true ;
return false ;
}
static bool
F_88 ( struct V_55 * V_56 , struct V_15 * V_96 ,
T_2 V_75 )
{
struct V_5 * V_6 = V_56 -> V_2 -> V_7 ;
if ( ! V_96 -> V_18 )
return false ;
if ( ! F_89 ( V_56 -> V_2 ) )
return false ;
if ( V_56 != & V_6 -> V_56 [ V_59 ] )
return false ;
if ( V_75 & V_98 )
return true ;
return false ;
}
static int F_90 ( struct V_65 * V_66 )
{
struct V_15 * V_96 = V_66 -> V_16 ;
struct V_55 * V_56 = V_66 -> V_56 ;
struct V_5 * V_6 = V_56 -> V_2 -> V_7 ;
struct V_15 * V_95 = V_56 -> V_58 ;
T_2 V_75 = 0 ;
bool V_99 = false ;
int V_8 , V_53 ;
if ( V_95 != NULL && V_56 == & V_6 -> V_56 [ V_59 ] ) {
F_38 ( V_95 -> V_27 . V_28 == NULL ) ;
F_38 ( ! F_91 ( V_95 -> V_27 . V_28 ) ) ;
}
if ( F_85 ( V_56 , V_95 , V_96 ) )
return 0 ;
if ( V_56 == & V_6 -> V_56 [ V_59 ] ) {
V_8 = F_40 ( V_96 -> V_27 . V_28 ,
F_1 ( V_56 -> V_2 ) , 0 ) ;
if ( V_8 )
return V_8 ;
}
V_95 = V_56 -> V_58 ;
if ( F_87 ( V_56 , V_96 ) ) {
F_92 ( V_56 , V_96 ) ;
V_8 = V_96 -> V_18 -> V_100 ( V_96 -> V_18 , V_66 ) ;
if ( V_8 )
goto V_101;
V_96 -> V_18 -> V_97 &= ~ F_86 ( V_56 ) ;
}
if ( V_56 != & V_6 -> V_56 [ V_59 ] ) {
if ( V_95 )
F_36 ( V_95 ) ;
goto V_102;
}
V_8 = F_93 ( V_96 -> V_27 . V_28 , false ) ;
if ( V_8 )
goto V_101;
if ( ! V_96 -> V_27 . V_61 || F_94 ( V_96 ) ) {
V_75 |= V_98 ;
} else if ( V_96 -> V_18 &&
( F_86 ( V_56 ) & V_96 -> V_18 -> V_97 ) ) {
V_75 |= V_103 ;
V_96 -> V_18 -> V_97 &= ~ F_86 ( V_56 ) ;
}
F_12 ( F_87 ( V_56 , V_96 ) &&
F_88 ( V_56 , V_96 , V_75 ) ) ;
V_8 = F_72 ( V_66 , V_75 ) ;
if ( V_8 )
goto V_101;
if ( F_88 ( V_56 , V_96 , V_75 ) ) {
F_92 ( V_56 , V_96 ) ;
V_8 = V_96 -> V_18 -> V_100 ( V_96 -> V_18 , V_66 ) ;
if ( V_8 ) {
F_57 ( L_11 ) ;
goto V_101;
}
}
for ( V_53 = 0 ; V_53 < V_104 ; V_53 ++ ) {
if ( ! ( V_96 -> V_45 & ( 1 << V_53 ) ) )
continue;
V_8 = F_95 ( V_66 , V_53 ) ;
if ( V_8 )
F_41 ( L_12 ) ;
else
V_96 -> V_45 &= ~ ( 1 << V_53 ) ;
}
if ( V_95 != NULL ) {
V_95 -> V_27 . V_28 -> V_29 . V_105 = V_106 ;
F_96 ( F_97 ( V_95 -> V_27 . V_28 ) , V_66 ) ;
V_95 -> V_27 . V_28 -> V_107 = 1 ;
F_46 ( V_95 -> V_27 . V_28 ) ;
F_36 ( V_95 ) ;
}
V_99 = ! V_96 -> V_27 . V_61 ;
V_96 -> V_27 . V_61 = true ;
V_102:
F_98 ( V_96 ) ;
V_56 -> V_58 = V_96 ;
if ( V_99 ) {
if ( V_56 -> V_67 ) {
V_8 = V_56 -> V_67 ( V_66 ) ;
if ( V_8 )
F_57 ( L_10 , V_8 ) ;
}
}
return 0 ;
V_101:
if ( V_56 -> V_68 == V_59 )
F_46 ( V_96 -> V_27 . V_28 ) ;
return V_8 ;
}
int F_61 ( struct V_65 * V_66 )
{
struct V_55 * V_56 = V_66 -> V_56 ;
struct V_5 * V_6 = V_56 -> V_2 -> V_7 ;
F_12 ( V_25 . V_26 ) ;
F_12 ( ! F_39 ( & V_6 -> V_2 -> V_50 ) ) ;
if ( V_66 -> V_16 -> V_27 . V_28 == NULL ) {
if ( V_66 -> V_16 != V_56 -> V_58 ) {
F_98 ( V_66 -> V_16 ) ;
if ( V_56 -> V_58 )
F_36 ( V_56 -> V_58 ) ;
V_56 -> V_58 = V_66 -> V_16 ;
}
return 0 ;
}
return F_90 ( V_66 ) ;
}
static bool F_99 ( struct V_1 * V_2 )
{
return V_25 . V_26 || F_100 ( V_2 ) -> V_40 ;
}
int F_101 ( struct V_1 * V_2 , void * V_70 ,
struct V_71 * V_72 )
{
struct V_108 * args = V_70 ;
struct V_36 * V_37 = V_72 -> V_73 ;
struct V_15 * V_16 ;
int V_8 ;
if ( ! F_99 ( V_2 ) )
return - V_109 ;
V_8 = F_102 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_16 = F_37 ( V_2 , V_37 ) ;
F_66 ( & V_2 -> V_50 ) ;
if ( F_32 ( V_16 ) )
return F_33 ( V_16 ) ;
args -> V_110 = V_16 -> V_44 ;
F_41 ( L_13 , args -> V_110 ) ;
return 0 ;
}
int F_103 ( struct V_1 * V_2 , void * V_70 ,
struct V_71 * V_72 )
{
struct V_111 * args = V_70 ;
struct V_36 * V_37 = V_72 -> V_73 ;
struct V_15 * V_16 ;
int V_8 ;
if ( args -> V_110 == V_43 )
return - V_74 ;
V_8 = F_102 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_16 = F_70 ( V_37 , args -> V_110 ) ;
if ( F_32 ( V_16 ) ) {
F_66 ( & V_2 -> V_50 ) ;
return F_33 ( V_16 ) ;
}
F_47 ( & V_16 -> V_37 -> V_42 , V_16 -> V_44 ) ;
F_36 ( V_16 ) ;
F_66 ( & V_2 -> V_50 ) ;
F_41 ( L_14 , args -> V_110 ) ;
return 0 ;
}
int F_104 ( struct V_1 * V_2 , void * V_70 ,
struct V_71 * V_72 )
{
struct V_36 * V_37 = V_72 -> V_73 ;
struct V_112 * args = V_70 ;
struct V_15 * V_16 ;
int V_8 ;
V_8 = F_102 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_16 = F_70 ( V_37 , args -> V_110 ) ;
if ( F_32 ( V_16 ) ) {
F_66 ( & V_2 -> V_50 ) ;
return F_33 ( V_16 ) ;
}
args -> V_32 = 0 ;
switch ( args -> V_113 ) {
case V_114 :
args -> V_115 = V_16 -> V_46 . V_47 ;
break;
case V_116 :
args -> V_115 = V_16 -> V_76 & V_117 ;
break;
case V_118 :
if ( V_16 -> V_18 )
args -> V_115 = V_16 -> V_18 -> V_29 . V_119 ;
else if ( F_100 ( V_2 ) -> V_120 . V_121 )
args -> V_115 = F_100 ( V_2 ) -> V_120 . V_121 -> V_29 . V_119 ;
else
args -> V_115 = F_100 ( V_2 ) -> V_122 . V_29 . V_119 ;
break;
default:
V_8 = - V_62 ;
break;
}
F_66 ( & V_2 -> V_50 ) ;
return V_8 ;
}
int F_105 ( struct V_1 * V_2 , void * V_70 ,
struct V_71 * V_72 )
{
struct V_36 * V_37 = V_72 -> V_73 ;
struct V_112 * args = V_70 ;
struct V_15 * V_16 ;
int V_8 ;
V_8 = F_102 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_16 = F_70 ( V_37 , args -> V_110 ) ;
if ( F_32 ( V_16 ) ) {
F_66 ( & V_2 -> V_50 ) ;
return F_33 ( V_16 ) ;
}
switch ( args -> V_113 ) {
case V_114 :
if ( args -> V_32 )
V_8 = - V_62 ;
else if ( args -> V_115 < V_16 -> V_46 . V_47 &&
! F_106 ( V_123 ) )
V_8 = - V_124 ;
else
V_16 -> V_46 . V_47 = args -> V_115 ;
break;
case V_116 :
if ( args -> V_32 ) {
V_8 = - V_62 ;
} else {
V_16 -> V_76 &= ~ V_117 ;
V_16 -> V_76 |= args -> V_115 ? V_117 : 0 ;
}
break;
default:
V_8 = - V_62 ;
break;
}
F_66 ( & V_2 -> V_50 ) ;
return V_8 ;
}
