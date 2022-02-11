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
if ( V_20 . V_21 )
return;
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
int F_45 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_18 ;
int V_50 ;
if ( F_24 ( V_6 -> V_53 [ V_56 ] . V_57 ) )
return 0 ;
if ( V_20 . V_21 ) {
V_6 -> V_36 = 0 ;
} else if ( F_46 ( V_2 ) ) {
V_6 -> V_36 = F_47 ( F_3 ( V_2 ) , 4096 ) ;
if ( V_6 -> V_36 > ( 1 << 20 ) ) {
F_38 ( L_3 ,
V_6 -> V_36 ) ;
V_6 -> V_36 = 0 ;
}
}
V_18 = F_34 ( V_2 , NULL ) ;
if ( F_29 ( V_18 ) ) {
F_48 ( L_4 ,
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
void F_49 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_58 = V_6 -> V_53 [ V_56 ] . V_57 ;
int V_50 ;
if ( V_58 -> V_23 . V_24 ) {
F_50 ( V_2 ) ;
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
int F_51 ( struct V_5 * V_6 )
{
struct V_52 * V_53 ;
int V_8 , V_50 ;
F_35 ( ! V_6 -> V_53 [ V_56 ] . V_57 ) ;
if ( V_20 . V_21 ) {
F_52 (ring, dev_priv, i) {
if ( V_53 -> V_60 ) {
V_8 = V_53 -> V_60 ( V_53 ,
V_53 -> V_57 ) ;
if ( V_8 ) {
F_48 ( L_9 ,
V_8 ) ;
return V_8 ;
}
}
}
} else
F_52 (ring, dev_priv, i) {
V_8 = F_53 ( V_53 , V_53 -> V_57 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static int F_54 ( int V_61 , void * V_62 , void * V_63 )
{
struct V_17 * V_18 = V_62 ;
F_33 ( V_18 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
struct V_32 * V_33 = V_65 -> V_66 ;
struct V_17 * V_18 ;
F_56 ( & V_33 -> V_38 ) ;
F_57 ( & V_2 -> V_46 ) ;
V_18 = F_34 ( V_2 , V_33 ) ;
F_58 ( & V_2 -> V_46 ) ;
if ( F_29 ( V_18 ) ) {
F_59 ( & V_33 -> V_38 ) ;
return F_30 ( V_18 ) ;
}
return 0 ;
}
void F_60 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
struct V_32 * V_33 = V_65 -> V_66 ;
F_61 ( & V_33 -> V_38 , F_54 , NULL ) ;
F_59 ( & V_33 -> V_38 ) ;
}
struct V_17 *
F_62 ( struct V_32 * V_33 , T_2 V_61 )
{
struct V_17 * V_18 ;
V_18 = (struct V_17 * ) F_63 ( & V_33 -> V_38 , V_61 ) ;
if ( ! V_18 )
return F_21 ( - V_67 ) ;
return V_18 ;
}
static inline int
F_64 ( struct V_52 * V_53 ,
struct V_17 * V_68 ,
T_2 V_69 )
{
T_2 V_70 = V_69 | V_71 ;
const int V_72 =
F_65 ( V_53 -> V_2 ) ?
F_66 ( F_4 ( V_53 -> V_2 ) -> V_73 ) - 1 :
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
V_8 = F_67 ( V_53 , V_74 ) ;
if ( V_8 )
return V_8 ;
if ( F_4 ( V_53 -> V_2 ) -> V_10 >= 7 ) {
F_68 ( V_53 , V_79 | V_80 ) ;
if ( V_72 ) {
struct V_52 * V_81 ;
F_68 ( V_53 , F_69 ( V_72 ) ) ;
F_52 (signaller, to_i915(ring->dev), i) {
if ( V_81 == V_53 )
continue;
F_68 ( V_53 , F_70 ( V_81 -> V_82 ) ) ;
F_68 ( V_53 , F_71 ( V_83 ) ) ;
}
}
}
F_68 ( V_53 , V_84 ) ;
F_68 ( V_53 , V_85 ) ;
F_68 ( V_53 , F_72 ( V_68 -> V_23 . V_24 ) |
V_70 ) ;
F_68 ( V_53 , V_84 ) ;
if ( F_4 ( V_53 -> V_2 ) -> V_10 >= 7 ) {
if ( V_72 ) {
struct V_52 * V_81 ;
F_68 ( V_53 , F_69 ( V_72 ) ) ;
F_52 (signaller, to_i915(ring->dev), i) {
if ( V_81 == V_53 )
continue;
F_68 ( V_53 , F_70 ( V_81 -> V_82 ) ) ;
F_68 ( V_53 , F_73 ( V_83 ) ) ;
}
}
F_68 ( V_53 , V_79 | V_86 ) ;
}
F_74 ( V_53 ) ;
return V_8 ;
}
static int F_75 ( struct V_52 * V_53 ,
struct V_17 * V_87 )
{
struct V_5 * V_6 = V_53 -> V_2 -> V_7 ;
struct V_17 * V_88 = V_53 -> V_55 ;
T_2 V_69 = 0 ;
bool V_89 = false ;
struct V_90 * V_91 ;
int V_8 , V_50 ;
if ( V_88 != NULL && V_53 == & V_6 -> V_53 [ V_56 ] ) {
F_35 ( V_88 -> V_23 . V_24 == NULL ) ;
F_35 ( ! F_76 ( V_88 -> V_23 . V_24 ) ) ;
}
if ( V_88 == V_87 && ! V_87 -> V_41 )
return 0 ;
if ( V_53 == & V_6 -> V_53 [ V_56 ] ) {
V_8 = F_37 ( V_87 -> V_23 . V_24 ,
F_1 ( V_53 -> V_2 ) , 0 ) ;
if ( V_8 )
return V_8 ;
}
V_88 = V_53 -> V_55 ;
if ( V_87 -> V_22 ) {
F_77 ( V_53 , V_87 ) ;
V_8 = V_87 -> V_22 -> V_92 ( V_87 -> V_22 , V_53 ) ;
if ( V_8 )
goto V_93;
}
if ( V_53 != & V_6 -> V_53 [ V_56 ] ) {
if ( V_88 )
F_33 ( V_88 ) ;
goto V_94;
}
V_8 = F_78 ( V_87 -> V_23 . V_24 , false ) ;
if ( V_8 )
goto V_93;
V_91 = F_79 ( V_87 -> V_23 . V_24 ) ;
if ( ! ( V_91 -> V_95 & V_96 ) ) {
V_8 = F_80 ( V_91 ,
V_87 -> V_23 . V_24 -> V_97 ,
V_96 ) ;
if ( F_81 ( V_8 , L_10 ) )
goto V_93;
}
if ( ! V_87 -> V_23 . V_98 || F_82 ( V_87 ) )
V_69 |= V_99 ;
V_8 = F_64 ( V_53 , V_87 , V_69 ) ;
if ( V_8 )
goto V_93;
for ( V_50 = 0 ; V_50 < V_100 ; V_50 ++ ) {
if ( ! ( V_87 -> V_41 & ( 1 << V_50 ) ) )
continue;
V_8 = F_83 ( V_53 , V_50 ) ;
if ( V_8 )
F_38 ( L_11 ) ;
else
V_87 -> V_41 &= ~ ( 1 << V_50 ) ;
}
if ( V_88 != NULL ) {
V_88 -> V_23 . V_24 -> V_25 . V_101 = V_102 ;
F_84 ( F_79 ( V_88 -> V_23 . V_24 ) , V_53 ) ;
V_88 -> V_23 . V_24 -> V_103 = 1 ;
F_35 ( F_85 (
V_88 -> V_23 . V_24 -> V_104 ) != V_53 ) ;
F_43 ( V_88 -> V_23 . V_24 ) ;
F_33 ( V_88 ) ;
}
V_89 = ! V_87 -> V_23 . V_98 && V_88 == NULL ;
V_87 -> V_23 . V_98 = true ;
V_94:
F_86 ( V_87 ) ;
V_53 -> V_55 = V_87 ;
if ( V_89 ) {
if ( V_53 -> V_60 ) {
V_8 = V_53 -> V_60 ( V_53 , V_87 ) ;
if ( V_8 )
F_48 ( L_9 , V_8 ) ;
}
}
return 0 ;
V_93:
if ( V_53 -> V_61 == V_56 )
F_43 ( V_87 -> V_23 . V_24 ) ;
return V_8 ;
}
int F_53 ( struct V_52 * V_53 ,
struct V_17 * V_87 )
{
struct V_5 * V_6 = V_53 -> V_2 -> V_7 ;
F_24 ( V_20 . V_21 ) ;
F_24 ( ! F_36 ( & V_6 -> V_2 -> V_46 ) ) ;
if ( V_87 -> V_23 . V_24 == NULL ) {
if ( V_87 != V_53 -> V_55 ) {
F_86 ( V_87 ) ;
if ( V_53 -> V_55 )
F_33 ( V_53 -> V_55 ) ;
V_53 -> V_55 = V_87 ;
}
return 0 ;
}
return F_75 ( V_53 , V_87 ) ;
}
static bool F_87 ( struct V_1 * V_2 )
{
return V_20 . V_21 || F_88 ( V_2 ) -> V_36 ;
}
int F_89 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_105 * args = V_63 ;
struct V_32 * V_33 = V_65 -> V_66 ;
struct V_17 * V_18 ;
int V_8 ;
if ( ! F_87 ( V_2 ) )
return - V_106 ;
V_8 = F_90 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_34 ( V_2 , V_33 ) ;
F_58 ( & V_2 -> V_46 ) ;
if ( F_29 ( V_18 ) )
return F_30 ( V_18 ) ;
args -> V_107 = V_18 -> V_40 ;
F_38 ( L_12 , args -> V_107 ) ;
return 0 ;
}
int F_91 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_108 * args = V_63 ;
struct V_32 * V_33 = V_65 -> V_66 ;
struct V_17 * V_18 ;
int V_8 ;
if ( args -> V_107 == V_39 )
return - V_67 ;
V_8 = F_90 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_62 ( V_33 , args -> V_107 ) ;
if ( F_29 ( V_18 ) ) {
F_58 ( & V_2 -> V_46 ) ;
return F_30 ( V_18 ) ;
}
F_92 ( & V_18 -> V_33 -> V_38 , V_18 -> V_40 ) ;
F_33 ( V_18 ) ;
F_58 ( & V_2 -> V_46 ) ;
F_38 ( L_13 , args -> V_107 ) ;
return 0 ;
}
int F_93 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_32 * V_33 = V_65 -> V_66 ;
struct V_109 * args = V_63 ;
struct V_17 * V_18 ;
int V_8 ;
V_8 = F_90 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_62 ( V_33 , args -> V_107 ) ;
if ( F_29 ( V_18 ) ) {
F_58 ( & V_2 -> V_46 ) ;
return F_30 ( V_18 ) ;
}
args -> V_28 = 0 ;
switch ( args -> V_110 ) {
case V_111 :
args -> V_112 = V_18 -> V_42 . V_43 ;
break;
default:
V_8 = - V_113 ;
break;
}
F_58 ( & V_2 -> V_46 ) ;
return V_8 ;
}
int F_94 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_32 * V_33 = V_65 -> V_66 ;
struct V_109 * args = V_63 ;
struct V_17 * V_18 ;
int V_8 ;
V_8 = F_90 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_62 ( V_33 , args -> V_107 ) ;
if ( F_29 ( V_18 ) ) {
F_58 ( & V_2 -> V_46 ) ;
return F_30 ( V_18 ) ;
}
switch ( args -> V_110 ) {
case V_111 :
if ( args -> V_28 )
V_8 = - V_113 ;
else if ( args -> V_112 < V_18 -> V_42 . V_43 &&
! F_95 ( V_114 ) )
V_8 = - V_115 ;
else
V_18 -> V_42 . V_43 = args -> V_112 ;
break;
default:
V_8 = - V_113 ;
break;
}
F_58 ( & V_2 -> V_46 ) ;
return V_8 ;
}
