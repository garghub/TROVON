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
struct V_17 * V_18 = F_11 ( V_16 ,
F_12 ( * V_18 ) , V_19 ) ;
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
F_33 ( V_18 ) ;
return F_21 ( V_8 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_50 ;
if ( V_20 . V_21 ) {
struct V_17 * V_18 ;
F_45 (ctx, &dev_priv->context_list, link) {
F_46 ( V_2 , V_18 ) ;
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
int F_47 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_18 ;
int V_50 ;
if ( F_24 ( V_6 -> V_53 [ V_56 ] . V_57 ) )
return 0 ;
if ( V_20 . V_21 ) {
V_6 -> V_36 = 0 ;
} else if ( F_48 ( V_2 ) ) {
V_6 -> V_36 = F_49 ( F_3 ( V_2 ) , 4096 ) ;
if ( V_6 -> V_36 > ( 1 << 20 ) ) {
F_38 ( L_3 ,
V_6 -> V_36 ) ;
V_6 -> V_36 = 0 ;
}
}
V_18 = F_34 ( V_2 , NULL ) ;
if ( F_29 ( V_18 ) ) {
F_50 ( L_4 ,
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
void F_51 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_58 = V_6 -> V_53 [ V_56 ] . V_57 ;
int V_50 ;
if ( V_58 -> V_23 . V_24 ) {
F_52 ( V_2 ) ;
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
int F_53 ( struct V_5 * V_6 )
{
struct V_52 * V_53 ;
int V_8 , V_50 ;
F_35 ( ! V_6 -> V_53 [ V_56 ] . V_57 ) ;
if ( V_20 . V_21 ) {
F_54 (ring, dev_priv, i) {
if ( V_53 -> V_60 ) {
V_8 = V_53 -> V_60 ( V_53 ,
V_53 -> V_57 ) ;
if ( V_8 ) {
F_50 ( L_9 ,
V_8 ) ;
return V_8 ;
}
}
}
} else
F_54 (ring, dev_priv, i) {
V_8 = F_55 ( V_53 , V_53 -> V_57 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static int F_56 ( int V_61 , void * V_62 , void * V_63 )
{
struct V_17 * V_18 = V_62 ;
F_33 ( V_18 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
struct V_32 * V_33 = V_65 -> V_66 ;
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
void F_62 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
struct V_32 * V_33 = V_65 -> V_66 ;
F_63 ( & V_33 -> V_38 , F_56 , NULL ) ;
F_61 ( & V_33 -> V_38 ) ;
}
struct V_17 *
F_64 ( struct V_32 * V_33 , T_2 V_61 )
{
struct V_17 * V_18 ;
V_18 = (struct V_17 * ) F_65 ( & V_33 -> V_38 , V_61 ) ;
if ( ! V_18 )
return F_21 ( - V_67 ) ;
return V_18 ;
}
static inline int
F_66 ( struct V_52 * V_53 ,
struct V_17 * V_68 ,
T_2 V_69 )
{
T_2 V_70 = V_69 | V_71 ;
const int V_72 =
F_67 ( V_53 -> V_2 ) ?
F_68 ( F_4 ( V_53 -> V_2 ) -> V_73 ) - 1 :
0 ;
int V_74 , V_50 , V_8 ;
if ( F_2 ( V_53 -> V_2 ) ) {
V_8 = V_53 -> V_75 ( V_53 , V_76 , 0 ) ;
if ( V_8 )
return V_8 ;
}
if ( ! F_7 ( V_53 -> V_2 ) && F_4 ( V_53 -> V_2 ) -> V_10 < 8 )
V_70 |= ( V_77 | V_78 ) ;
V_74 = 4 ;
if ( F_4 ( V_53 -> V_2 ) -> V_10 >= 7 )
V_74 += 2 + ( V_72 ? 4 * V_72 + 2 : 0 ) ;
V_8 = F_69 ( V_53 , V_74 ) ;
if ( V_8 )
return V_8 ;
if ( F_4 ( V_53 -> V_2 ) -> V_10 >= 7 ) {
F_70 ( V_53 , V_79 | V_80 ) ;
if ( V_72 ) {
struct V_52 * V_81 ;
F_70 ( V_53 , F_71 ( V_72 ) ) ;
F_54 (signaller, to_i915(ring->dev), i) {
if ( V_81 == V_53 )
continue;
F_70 ( V_53 , F_72 ( V_81 -> V_82 ) ) ;
F_70 ( V_53 , F_73 ( V_83 ) ) ;
}
}
}
F_70 ( V_53 , V_84 ) ;
F_70 ( V_53 , V_85 ) ;
F_70 ( V_53 , F_74 ( V_68 -> V_23 . V_24 ) |
V_70 ) ;
F_70 ( V_53 , V_84 ) ;
if ( F_4 ( V_53 -> V_2 ) -> V_10 >= 7 ) {
if ( V_72 ) {
struct V_52 * V_81 ;
F_70 ( V_53 , F_71 ( V_72 ) ) ;
F_54 (signaller, to_i915(ring->dev), i) {
if ( V_81 == V_53 )
continue;
F_70 ( V_53 , F_72 ( V_81 -> V_82 ) ) ;
F_70 ( V_53 , F_75 ( V_83 ) ) ;
}
}
F_70 ( V_53 , V_79 | V_86 ) ;
}
F_76 ( V_53 ) ;
return V_8 ;
}
static inline bool F_77 ( struct V_52 * V_53 ,
struct V_17 * V_87 ,
struct V_17 * V_88 )
{
struct V_5 * V_6 = V_53 -> V_2 -> V_7 ;
if ( V_88 -> V_41 )
return false ;
if ( V_88 -> V_22 ) {
if ( V_87 == V_88 && ! F_78 ( V_53 -> V_61 ,
& V_88 -> V_22 -> V_89 ) )
return true ;
} else if ( V_6 -> V_90 . V_91 ) {
if ( V_87 == V_88 && ! F_78 ( V_53 -> V_61 ,
& V_6 -> V_90 . V_91 -> V_89 ) )
return true ;
}
return false ;
}
static bool
F_79 ( struct V_52 * V_53 , struct V_17 * V_88 )
{
struct V_5 * V_6 = V_53 -> V_2 -> V_7 ;
if ( ! V_88 -> V_22 )
return false ;
if ( F_4 ( V_53 -> V_2 ) -> V_10 < 8 )
return true ;
if ( V_53 != & V_6 -> V_53 [ V_56 ] )
return true ;
return false ;
}
static bool
F_80 ( struct V_52 * V_53 , struct V_17 * V_88 ,
T_2 V_69 )
{
struct V_5 * V_6 = V_53 -> V_2 -> V_7 ;
if ( ! V_88 -> V_22 )
return false ;
if ( ! F_81 ( V_53 -> V_2 ) )
return false ;
if ( V_53 != & V_6 -> V_53 [ V_56 ] )
return false ;
if ( V_69 & V_92 )
return true ;
return false ;
}
static int F_82 ( struct V_52 * V_53 ,
struct V_17 * V_88 )
{
struct V_5 * V_6 = V_53 -> V_2 -> V_7 ;
struct V_17 * V_87 = V_53 -> V_55 ;
T_2 V_69 = 0 ;
bool V_93 = false ;
struct V_94 * V_95 ;
int V_8 , V_50 ;
if ( V_87 != NULL && V_53 == & V_6 -> V_53 [ V_56 ] ) {
F_35 ( V_87 -> V_23 . V_24 == NULL ) ;
F_35 ( ! F_83 ( V_87 -> V_23 . V_24 ) ) ;
}
if ( F_77 ( V_53 , V_87 , V_88 ) )
return 0 ;
if ( V_53 == & V_6 -> V_53 [ V_56 ] ) {
V_8 = F_37 ( V_88 -> V_23 . V_24 ,
F_1 ( V_53 -> V_2 ) , 0 ) ;
if ( V_8 )
return V_8 ;
}
V_87 = V_53 -> V_55 ;
if ( F_79 ( V_53 , V_88 ) ) {
F_84 ( V_53 , V_88 ) ;
V_8 = V_88 -> V_22 -> V_96 ( V_88 -> V_22 , V_53 ) ;
if ( V_8 )
goto V_97;
F_85 ( V_53 -> V_61 , & V_88 -> V_22 -> V_89 ) ;
}
if ( V_53 != & V_6 -> V_53 [ V_56 ] ) {
if ( V_87 )
F_33 ( V_87 ) ;
goto V_98;
}
V_8 = F_86 ( V_88 -> V_23 . V_24 , false ) ;
if ( V_8 )
goto V_97;
V_95 = F_87 ( V_88 -> V_23 . V_24 ) ;
if ( ! ( V_95 -> V_99 & V_100 ) ) {
V_8 = F_88 ( V_95 ,
V_88 -> V_23 . V_24 -> V_101 ,
V_100 ) ;
if ( F_89 ( V_8 , L_10 ) )
goto V_97;
}
if ( ! V_88 -> V_23 . V_102 ) {
V_69 |= V_92 ;
} else if ( V_88 -> V_22 &&
F_90 ( V_53 -> V_61 , & V_88 -> V_22 -> V_89 ) )
V_69 |= V_103 ;
F_24 ( F_79 ( V_53 , V_88 ) &&
F_80 ( V_53 , V_88 , V_69 ) ) ;
V_8 = F_66 ( V_53 , V_88 , V_69 ) ;
if ( V_8 )
goto V_97;
if ( F_80 ( V_53 , V_88 , V_69 ) ) {
F_84 ( V_53 , V_88 ) ;
V_8 = V_88 -> V_22 -> V_96 ( V_88 -> V_22 , V_53 ) ;
if ( V_8 ) {
F_50 ( L_11 ) ;
goto V_97;
}
}
for ( V_50 = 0 ; V_50 < V_104 ; V_50 ++ ) {
if ( ! ( V_88 -> V_41 & ( 1 << V_50 ) ) )
continue;
V_8 = F_91 ( V_53 , V_50 ) ;
if ( V_8 )
F_38 ( L_12 ) ;
else
V_88 -> V_41 &= ~ ( 1 << V_50 ) ;
}
if ( V_87 != NULL ) {
V_87 -> V_23 . V_24 -> V_25 . V_105 = V_106 ;
F_92 ( F_87 ( V_87 -> V_23 . V_24 ) , V_53 ) ;
V_87 -> V_23 . V_24 -> V_107 = 1 ;
F_35 ( F_93 (
V_87 -> V_23 . V_24 -> V_108 ) != V_53 ) ;
F_43 ( V_87 -> V_23 . V_24 ) ;
F_33 ( V_87 ) ;
}
V_93 = ! V_88 -> V_23 . V_102 ;
V_88 -> V_23 . V_102 = true ;
V_98:
F_94 ( V_88 ) ;
V_53 -> V_55 = V_88 ;
if ( V_93 ) {
if ( V_53 -> V_60 ) {
V_8 = V_53 -> V_60 ( V_53 , V_88 ) ;
if ( V_8 )
F_50 ( L_9 , V_8 ) ;
}
}
return 0 ;
V_97:
if ( V_53 -> V_61 == V_56 )
F_43 ( V_88 -> V_23 . V_24 ) ;
return V_8 ;
}
int F_55 ( struct V_52 * V_53 ,
struct V_17 * V_88 )
{
struct V_5 * V_6 = V_53 -> V_2 -> V_7 ;
F_24 ( V_20 . V_21 ) ;
F_24 ( ! F_36 ( & V_6 -> V_2 -> V_46 ) ) ;
if ( V_88 -> V_23 . V_24 == NULL ) {
if ( V_88 != V_53 -> V_55 ) {
F_94 ( V_88 ) ;
if ( V_53 -> V_55 )
F_33 ( V_53 -> V_55 ) ;
V_53 -> V_55 = V_88 ;
}
return 0 ;
}
return F_82 ( V_53 , V_88 ) ;
}
static bool F_95 ( struct V_1 * V_2 )
{
return V_20 . V_21 || F_96 ( V_2 ) -> V_36 ;
}
int F_97 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_109 * args = V_63 ;
struct V_32 * V_33 = V_65 -> V_66 ;
struct V_17 * V_18 ;
int V_8 ;
if ( ! F_95 ( V_2 ) )
return - V_110 ;
V_8 = F_98 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_34 ( V_2 , V_33 ) ;
F_60 ( & V_2 -> V_46 ) ;
if ( F_29 ( V_18 ) )
return F_30 ( V_18 ) ;
args -> V_111 = V_18 -> V_40 ;
F_38 ( L_13 , args -> V_111 ) ;
return 0 ;
}
int F_99 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_112 * args = V_63 ;
struct V_32 * V_33 = V_65 -> V_66 ;
struct V_17 * V_18 ;
int V_8 ;
if ( args -> V_111 == V_39 )
return - V_67 ;
V_8 = F_98 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_64 ( V_33 , args -> V_111 ) ;
if ( F_29 ( V_18 ) ) {
F_60 ( & V_2 -> V_46 ) ;
return F_30 ( V_18 ) ;
}
F_100 ( & V_18 -> V_33 -> V_38 , V_18 -> V_40 ) ;
F_33 ( V_18 ) ;
F_60 ( & V_2 -> V_46 ) ;
F_38 ( L_14 , args -> V_111 ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_32 * V_33 = V_65 -> V_66 ;
struct V_113 * args = V_63 ;
struct V_17 * V_18 ;
int V_8 ;
V_8 = F_98 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_64 ( V_33 , args -> V_111 ) ;
if ( F_29 ( V_18 ) ) {
F_60 ( & V_2 -> V_46 ) ;
return F_30 ( V_18 ) ;
}
args -> V_28 = 0 ;
switch ( args -> V_114 ) {
case V_115 :
args -> V_116 = V_18 -> V_42 . V_43 ;
break;
default:
V_8 = - V_117 ;
break;
}
F_60 ( & V_2 -> V_46 ) ;
return V_8 ;
}
int F_102 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_32 * V_33 = V_65 -> V_66 ;
struct V_113 * args = V_63 ;
struct V_17 * V_18 ;
int V_8 ;
V_8 = F_98 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_64 ( V_33 , args -> V_111 ) ;
if ( F_29 ( V_18 ) ) {
F_60 ( & V_2 -> V_46 ) ;
return F_30 ( V_18 ) ;
}
switch ( args -> V_114 ) {
case V_115 :
if ( args -> V_28 )
V_8 = - V_117 ;
else if ( args -> V_116 < V_18 -> V_42 . V_43 &&
! F_103 ( V_118 ) )
V_8 = - V_119 ;
else
V_18 -> V_42 . V_43 = args -> V_116 ;
break;
default:
V_8 = - V_117 ;
break;
}
F_60 ( & V_2 -> V_46 ) ;
return V_8 ;
}
