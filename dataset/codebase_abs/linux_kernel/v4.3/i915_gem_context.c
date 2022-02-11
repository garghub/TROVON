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
void F_10 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_11 ( V_16 , F_12 ( * V_18 ) , V_19 ) ;
F_13 ( V_18 ) ;
if ( V_20 . V_21 )
F_14 ( V_18 ) ;
F_15 ( V_18 -> V_22 ) ;
if ( V_18 -> V_23 . V_24 )
F_16 ( & V_18 -> V_23 . V_24 -> V_25 ) ;
F_17 ( & V_18 -> V_26 ) ;
F_18 ( V_18 ) ;
}
struct V_27 *
F_19 ( struct V_1 * V_2 , T_1 V_28 )
{
struct V_27 * V_29 ;
int V_8 ;
V_29 = F_20 ( V_2 , V_28 ) ;
if ( V_29 == NULL )
return F_21 ( - V_30 ) ;
if ( F_4 ( V_2 ) -> V_10 >= 7 && ! F_22 ( V_2 ) ) {
V_8 = F_23 ( V_29 , V_31 ) ;
if ( F_24 ( V_8 ) ) {
F_16 ( & V_29 -> V_25 ) ;
return F_21 ( V_8 ) ;
}
}
return V_29 ;
}
static struct V_17 *
F_25 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_18 ;
int V_8 ;
V_18 = F_26 ( sizeof( * V_18 ) , V_34 ) ;
if ( V_18 == NULL )
return F_21 ( - V_30 ) ;
F_27 ( & V_18 -> V_19 ) ;
F_28 ( & V_18 -> V_26 , & V_6 -> V_35 ) ;
V_18 -> V_20 = V_6 ;
if ( V_6 -> V_36 ) {
struct V_27 * V_29 =
F_19 ( V_2 , V_6 -> V_36 ) ;
if ( F_29 ( V_29 ) ) {
V_8 = F_30 ( V_29 ) ;
goto V_37;
}
V_18 -> V_23 . V_24 = V_29 ;
}
if ( V_33 != NULL ) {
V_8 = F_31 ( & V_33 -> V_38 , V_18 ,
V_39 , 0 , V_34 ) ;
if ( V_8 < 0 )
goto V_37;
} else
V_8 = V_39 ;
V_18 -> V_33 = V_33 ;
V_18 -> V_40 = V_8 ;
V_18 -> V_41 = ( 1 << F_32 ( V_2 ) ) - 1 ;
V_18 -> V_42 . V_43 = V_44 ;
return V_18 ;
V_37:
F_33 ( V_18 ) ;
return F_21 ( V_8 ) ;
}
static struct V_17 *
F_34 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
const bool V_45 = V_33 == NULL ;
struct V_17 * V_18 ;
int V_8 = 0 ;
F_35 ( ! F_36 ( & V_2 -> V_46 ) ) ;
V_18 = F_25 ( V_2 , V_33 ) ;
if ( F_29 ( V_18 ) )
return V_18 ;
if ( V_45 && V_18 -> V_23 . V_24 ) {
V_8 = F_37 ( V_18 -> V_23 . V_24 ,
F_1 ( V_2 ) , 0 ) ;
if ( V_8 ) {
F_38 ( L_1 , V_8 ) ;
goto V_47;
}
}
if ( F_39 ( V_2 ) ) {
struct V_48 * V_22 = F_40 ( V_2 , V_33 ) ;
if ( F_41 ( V_22 ) ) {
F_38 ( L_2 ,
F_30 ( V_22 ) ) ;
V_8 = F_30 ( V_22 ) ;
goto V_49;
}
V_18 -> V_22 = V_22 ;
}
F_42 ( V_18 ) ;
return V_18 ;
V_49:
if ( V_45 && V_18 -> V_23 . V_24 )
F_43 ( V_18 -> V_23 . V_24 ) ;
V_47:
F_44 ( & V_33 -> V_38 , V_18 -> V_40 ) ;
F_33 ( V_18 ) ;
return F_21 ( V_8 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_50 ;
if ( V_20 . V_21 ) {
struct V_17 * V_18 ;
F_46 (ctx, &dev_priv->context_list, link) {
F_47 ( V_2 , V_18 ) ;
}
return;
}
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
struct V_52 * V_53 = & V_6 -> V_53 [ V_50 ] ;
struct V_17 * V_54 = V_53 -> V_55 ;
if ( V_54 ) {
if ( V_54 -> V_23 . V_24 && V_50 == V_56 )
F_43 ( V_54 -> V_23 . V_24 ) ;
F_33 ( V_54 ) ;
V_53 -> V_55 = NULL ;
}
}
}
int F_48 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_18 ;
int V_50 ;
if ( F_24 ( V_6 -> V_53 [ V_56 ] . V_57 ) )
return 0 ;
if ( V_20 . V_21 ) {
V_6 -> V_36 = 0 ;
} else if ( F_49 ( V_2 ) ) {
V_6 -> V_36 = F_50 ( F_3 ( V_2 ) , 4096 ) ;
if ( V_6 -> V_36 > ( 1 << 20 ) ) {
F_38 ( L_3 ,
V_6 -> V_36 ) ;
V_6 -> V_36 = 0 ;
}
}
V_18 = F_34 ( V_2 , NULL ) ;
if ( F_29 ( V_18 ) ) {
F_51 ( L_4 ,
F_30 ( V_18 ) ) ;
return F_30 ( V_18 ) ;
}
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
struct V_52 * V_53 = & V_6 -> V_53 [ V_50 ] ;
V_53 -> V_57 = V_18 ;
}
F_38 ( L_5 ,
V_20 . V_21 ? L_6 :
V_6 -> V_36 ? L_7 : L_8 ) ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_58 = V_6 -> V_53 [ V_56 ] . V_57 ;
int V_50 ;
if ( V_58 -> V_23 . V_24 ) {
F_53 ( V_2 ) ;
F_24 ( ! V_6 -> V_53 [ V_56 ] . V_55 ) ;
if ( V_6 -> V_53 [ V_56 ] . V_55 == V_58 ) {
F_24 ( V_58 -> V_23 . V_24 -> V_59 ) ;
F_43 ( V_58 -> V_23 . V_24 ) ;
F_33 ( V_58 ) ;
V_6 -> V_53 [ V_56 ] . V_55 = NULL ;
}
F_43 ( V_58 -> V_23 . V_24 ) ;
}
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
struct V_52 * V_53 = & V_6 -> V_53 [ V_50 ] ;
if ( V_53 -> V_55 )
F_33 ( V_53 -> V_55 ) ;
V_53 -> V_57 = NULL ;
V_53 -> V_55 = NULL ;
}
F_33 ( V_58 ) ;
}
int F_54 ( struct V_60 * V_61 )
{
struct V_52 * V_53 = V_61 -> V_53 ;
int V_8 ;
if ( V_20 . V_21 ) {
if ( V_53 -> V_62 == NULL )
return 0 ;
V_8 = V_53 -> V_62 ( V_61 ) ;
} else
V_8 = F_55 ( V_61 ) ;
if ( V_8 ) {
F_51 ( L_9 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_56 ( int V_63 , void * V_64 , void * V_65 )
{
struct V_17 * V_18 = V_64 ;
F_33 ( V_18 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_32 * V_33 = V_67 -> V_68 ;
struct V_17 * V_18 ;
F_58 ( & V_33 -> V_38 ) ;
F_59 ( & V_2 -> V_46 ) ;
V_18 = F_34 ( V_2 , V_33 ) ;
F_60 ( & V_2 -> V_46 ) ;
if ( F_29 ( V_18 ) ) {
F_61 ( & V_33 -> V_38 ) ;
return F_30 ( V_18 ) ;
}
return 0 ;
}
void F_62 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_32 * V_33 = V_67 -> V_68 ;
F_63 ( & V_33 -> V_38 , F_56 , NULL ) ;
F_61 ( & V_33 -> V_38 ) ;
}
struct V_17 *
F_64 ( struct V_32 * V_33 , T_2 V_63 )
{
struct V_17 * V_18 ;
V_18 = (struct V_17 * ) F_65 ( & V_33 -> V_38 , V_63 ) ;
if ( ! V_18 )
return F_21 ( - V_69 ) ;
return V_18 ;
}
static inline int
F_66 ( struct V_60 * V_61 , T_2 V_70 )
{
struct V_52 * V_53 = V_61 -> V_53 ;
T_2 V_71 = V_70 | V_72 ;
const int V_73 =
F_67 ( V_53 -> V_2 ) ?
F_68 ( F_4 ( V_53 -> V_2 ) -> V_74 ) - 1 :
0 ;
int V_75 , V_50 , V_8 ;
if ( F_2 ( V_53 -> V_2 ) ) {
V_8 = V_53 -> V_76 ( V_61 , V_77 , 0 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_7 ( V_53 -> V_2 ) || F_4 ( V_53 -> V_2 ) -> V_10 >= 8 )
V_71 |= ( V_78 | V_79 ) ;
else if ( F_4 ( V_53 -> V_2 ) -> V_10 < 8 )
V_71 |= ( V_80 | V_81 ) ;
V_75 = 4 ;
if ( F_4 ( V_53 -> V_2 ) -> V_10 >= 7 )
V_75 += 2 + ( V_73 ? 4 * V_73 + 2 : 0 ) ;
V_8 = F_69 ( V_61 , V_75 ) ;
if ( V_8 )
return V_8 ;
if ( F_4 ( V_53 -> V_2 ) -> V_10 >= 7 ) {
F_70 ( V_53 , V_82 | V_83 ) ;
if ( V_73 ) {
struct V_52 * V_84 ;
F_70 ( V_53 , F_71 ( V_73 ) ) ;
F_72 (signaller, to_i915(ring->dev), i) {
if ( V_84 == V_53 )
continue;
F_70 ( V_53 , F_73 ( V_84 -> V_85 ) ) ;
F_70 ( V_53 , F_74 ( V_86 ) ) ;
}
}
}
F_70 ( V_53 , V_87 ) ;
F_70 ( V_53 , V_88 ) ;
F_70 ( V_53 , F_75 ( V_61 -> V_18 -> V_23 . V_24 ) |
V_71 ) ;
F_70 ( V_53 , V_87 ) ;
if ( F_4 ( V_53 -> V_2 ) -> V_10 >= 7 ) {
if ( V_73 ) {
struct V_52 * V_84 ;
F_70 ( V_53 , F_71 ( V_73 ) ) ;
F_72 (signaller, to_i915(ring->dev), i) {
if ( V_84 == V_53 )
continue;
F_70 ( V_53 , F_73 ( V_84 -> V_85 ) ) ;
F_70 ( V_53 , F_76 ( V_86 ) ) ;
}
}
F_70 ( V_53 , V_82 | V_89 ) ;
}
F_77 ( V_53 ) ;
return V_8 ;
}
static inline bool F_78 ( struct V_52 * V_53 ,
struct V_17 * V_90 ,
struct V_17 * V_91 )
{
if ( V_91 -> V_41 )
return false ;
if ( V_91 -> V_22 && V_90 == V_91 &&
! ( F_79 ( V_53 ) & V_91 -> V_22 -> V_92 ) )
return true ;
return false ;
}
static bool
F_80 ( struct V_52 * V_53 , struct V_17 * V_91 )
{
struct V_5 * V_6 = V_53 -> V_2 -> V_7 ;
if ( ! V_91 -> V_22 )
return false ;
if ( F_4 ( V_53 -> V_2 ) -> V_10 < 8 )
return true ;
if ( V_53 != & V_6 -> V_53 [ V_56 ] )
return true ;
return false ;
}
static bool
F_81 ( struct V_52 * V_53 , struct V_17 * V_91 ,
T_2 V_70 )
{
struct V_5 * V_6 = V_53 -> V_2 -> V_7 ;
if ( ! V_91 -> V_22 )
return false ;
if ( ! F_82 ( V_53 -> V_2 ) )
return false ;
if ( V_53 != & V_6 -> V_53 [ V_56 ] )
return false ;
if ( V_70 & V_93 )
return true ;
return false ;
}
static int F_83 ( struct V_60 * V_61 )
{
struct V_17 * V_91 = V_61 -> V_18 ;
struct V_52 * V_53 = V_61 -> V_53 ;
struct V_5 * V_6 = V_53 -> V_2 -> V_7 ;
struct V_17 * V_90 = V_53 -> V_55 ;
T_2 V_70 = 0 ;
bool V_94 = false ;
int V_8 , V_50 ;
if ( V_90 != NULL && V_53 == & V_6 -> V_53 [ V_56 ] ) {
F_35 ( V_90 -> V_23 . V_24 == NULL ) ;
F_35 ( ! F_84 ( V_90 -> V_23 . V_24 ) ) ;
}
if ( F_78 ( V_53 , V_90 , V_91 ) )
return 0 ;
if ( V_53 == & V_6 -> V_53 [ V_56 ] ) {
V_8 = F_37 ( V_91 -> V_23 . V_24 ,
F_1 ( V_53 -> V_2 ) , 0 ) ;
if ( V_8 )
return V_8 ;
}
V_90 = V_53 -> V_55 ;
if ( F_80 ( V_53 , V_91 ) ) {
F_85 ( V_53 , V_91 ) ;
V_8 = V_91 -> V_22 -> V_95 ( V_91 -> V_22 , V_61 ) ;
if ( V_8 )
goto V_96;
V_91 -> V_22 -> V_92 &= ~ F_79 ( V_53 ) ;
}
if ( V_53 != & V_6 -> V_53 [ V_56 ] ) {
if ( V_90 )
F_33 ( V_90 ) ;
goto V_97;
}
V_8 = F_86 ( V_91 -> V_23 . V_24 , false ) ;
if ( V_8 )
goto V_96;
if ( ! V_91 -> V_23 . V_98 ) {
V_70 |= V_93 ;
} else if ( V_91 -> V_22 &&
( F_79 ( V_53 ) & V_91 -> V_22 -> V_92 ) ) {
V_70 |= V_99 ;
V_91 -> V_22 -> V_92 &= ~ F_79 ( V_53 ) ;
}
F_24 ( F_80 ( V_53 , V_91 ) &&
F_81 ( V_53 , V_91 , V_70 ) ) ;
V_8 = F_66 ( V_61 , V_70 ) ;
if ( V_8 )
goto V_96;
if ( F_81 ( V_53 , V_91 , V_70 ) ) {
F_85 ( V_53 , V_91 ) ;
V_8 = V_91 -> V_22 -> V_95 ( V_91 -> V_22 , V_61 ) ;
if ( V_8 ) {
F_51 ( L_10 ) ;
goto V_96;
}
}
for ( V_50 = 0 ; V_50 < V_100 ; V_50 ++ ) {
if ( ! ( V_91 -> V_41 & ( 1 << V_50 ) ) )
continue;
V_8 = F_87 ( V_61 , V_50 ) ;
if ( V_8 )
F_38 ( L_11 ) ;
else
V_91 -> V_41 &= ~ ( 1 << V_50 ) ;
}
if ( V_90 != NULL ) {
V_90 -> V_23 . V_24 -> V_25 . V_101 = V_102 ;
F_88 ( F_89 ( V_90 -> V_23 . V_24 ) , V_61 ) ;
V_90 -> V_23 . V_24 -> V_103 = 1 ;
F_43 ( V_90 -> V_23 . V_24 ) ;
F_33 ( V_90 ) ;
}
V_94 = ! V_91 -> V_23 . V_98 ;
V_91 -> V_23 . V_98 = true ;
V_97:
F_90 ( V_91 ) ;
V_53 -> V_55 = V_91 ;
if ( V_94 ) {
if ( V_53 -> V_62 ) {
V_8 = V_53 -> V_62 ( V_61 ) ;
if ( V_8 )
F_51 ( L_9 , V_8 ) ;
}
}
return 0 ;
V_96:
if ( V_53 -> V_63 == V_56 )
F_43 ( V_91 -> V_23 . V_24 ) ;
return V_8 ;
}
int F_55 ( struct V_60 * V_61 )
{
struct V_52 * V_53 = V_61 -> V_53 ;
struct V_5 * V_6 = V_53 -> V_2 -> V_7 ;
F_24 ( V_20 . V_21 ) ;
F_24 ( ! F_36 ( & V_6 -> V_2 -> V_46 ) ) ;
if ( V_61 -> V_18 -> V_23 . V_24 == NULL ) {
if ( V_61 -> V_18 != V_53 -> V_55 ) {
F_90 ( V_61 -> V_18 ) ;
if ( V_53 -> V_55 )
F_33 ( V_53 -> V_55 ) ;
V_53 -> V_55 = V_61 -> V_18 ;
}
return 0 ;
}
return F_83 ( V_61 ) ;
}
static bool F_91 ( struct V_1 * V_2 )
{
return V_20 . V_21 || F_92 ( V_2 ) -> V_36 ;
}
int F_93 ( struct V_1 * V_2 , void * V_65 ,
struct V_66 * V_67 )
{
struct V_104 * args = V_65 ;
struct V_32 * V_33 = V_67 -> V_68 ;
struct V_17 * V_18 ;
int V_8 ;
if ( ! F_91 ( V_2 ) )
return - V_105 ;
V_8 = F_94 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_34 ( V_2 , V_33 ) ;
F_60 ( & V_2 -> V_46 ) ;
if ( F_29 ( V_18 ) )
return F_30 ( V_18 ) ;
args -> V_106 = V_18 -> V_40 ;
F_38 ( L_12 , args -> V_106 ) ;
return 0 ;
}
int F_95 ( struct V_1 * V_2 , void * V_65 ,
struct V_66 * V_67 )
{
struct V_107 * args = V_65 ;
struct V_32 * V_33 = V_67 -> V_68 ;
struct V_17 * V_18 ;
int V_8 ;
if ( args -> V_106 == V_39 )
return - V_69 ;
V_8 = F_94 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_64 ( V_33 , args -> V_106 ) ;
if ( F_29 ( V_18 ) ) {
F_60 ( & V_2 -> V_46 ) ;
return F_30 ( V_18 ) ;
}
F_44 ( & V_18 -> V_33 -> V_38 , V_18 -> V_40 ) ;
F_33 ( V_18 ) ;
F_60 ( & V_2 -> V_46 ) ;
F_38 ( L_13 , args -> V_106 ) ;
return 0 ;
}
int F_96 ( struct V_1 * V_2 , void * V_65 ,
struct V_66 * V_67 )
{
struct V_32 * V_33 = V_67 -> V_68 ;
struct V_108 * args = V_65 ;
struct V_17 * V_18 ;
int V_8 ;
V_8 = F_94 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_64 ( V_33 , args -> V_106 ) ;
if ( F_29 ( V_18 ) ) {
F_60 ( & V_2 -> V_46 ) ;
return F_30 ( V_18 ) ;
}
args -> V_28 = 0 ;
switch ( args -> V_109 ) {
case V_110 :
args -> V_111 = V_18 -> V_42 . V_43 ;
break;
case V_112 :
args -> V_111 = V_18 -> V_71 & V_113 ;
break;
default:
V_8 = - V_114 ;
break;
}
F_60 ( & V_2 -> V_46 ) ;
return V_8 ;
}
int F_97 ( struct V_1 * V_2 , void * V_65 ,
struct V_66 * V_67 )
{
struct V_32 * V_33 = V_67 -> V_68 ;
struct V_108 * args = V_65 ;
struct V_17 * V_18 ;
int V_8 ;
V_8 = F_94 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_64 ( V_33 , args -> V_106 ) ;
if ( F_29 ( V_18 ) ) {
F_60 ( & V_2 -> V_46 ) ;
return F_30 ( V_18 ) ;
}
switch ( args -> V_109 ) {
case V_110 :
if ( args -> V_28 )
V_8 = - V_114 ;
else if ( args -> V_111 < V_18 -> V_42 . V_43 &&
! F_98 ( V_115 ) )
V_8 = - V_116 ;
else
V_18 -> V_42 . V_43 = args -> V_111 ;
break;
case V_112 :
if ( args -> V_28 ) {
V_8 = - V_114 ;
} else {
V_18 -> V_71 &= ~ V_113 ;
V_18 -> V_71 |= args -> V_111 ? V_113 : 0 ;
}
break;
default:
V_8 = - V_114 ;
break;
}
F_60 ( & V_2 -> V_46 ) ;
return V_8 ;
}
