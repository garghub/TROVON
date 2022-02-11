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
return V_18 ;
V_37:
F_33 ( V_18 ) ;
return F_21 ( V_8 ) ;
}
static struct V_17 *
F_34 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
const bool V_42 = V_33 == NULL ;
struct V_17 * V_18 ;
int V_8 = 0 ;
F_35 ( ! F_36 ( & V_2 -> V_43 ) ) ;
V_18 = F_25 ( V_2 , V_33 ) ;
if ( F_29 ( V_18 ) )
return V_18 ;
if ( V_42 && V_18 -> V_23 . V_24 ) {
V_8 = F_37 ( V_18 -> V_23 . V_24 ,
F_1 ( V_2 ) , 0 ) ;
if ( V_8 ) {
F_38 ( L_1 , V_8 ) ;
goto V_44;
}
}
if ( F_39 ( V_2 ) ) {
struct V_45 * V_22 = F_40 ( V_2 , V_33 ) ;
if ( F_41 ( V_22 ) ) {
F_38 ( L_2 ,
F_30 ( V_22 ) ) ;
V_8 = F_30 ( V_22 ) ;
goto V_46;
}
V_18 -> V_22 = V_22 ;
}
F_42 ( V_18 ) ;
return V_18 ;
V_46:
if ( V_42 && V_18 -> V_23 . V_24 )
F_43 ( V_18 -> V_23 . V_24 ) ;
V_44:
F_33 ( V_18 ) ;
return F_21 ( V_8 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_47 ;
if ( V_20 . V_21 )
return;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
struct V_49 * V_50 = & V_6 -> V_50 [ V_47 ] ;
struct V_17 * V_51 = V_50 -> V_52 ;
if ( V_51 ) {
if ( V_51 -> V_23 . V_24 && V_47 == V_53 )
F_43 ( V_51 -> V_23 . V_24 ) ;
F_33 ( V_51 ) ;
V_50 -> V_52 = NULL ;
}
}
}
int F_45 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_18 ;
int V_47 ;
if ( F_24 ( V_6 -> V_50 [ V_53 ] . V_54 ) )
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
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
struct V_49 * V_50 = & V_6 -> V_50 [ V_47 ] ;
V_50 -> V_54 = V_18 ;
}
F_38 ( L_5 ,
V_20 . V_21 ? L_6 :
V_6 -> V_36 ? L_7 : L_8 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_55 = V_6 -> V_50 [ V_53 ] . V_54 ;
int V_47 ;
if ( V_55 -> V_23 . V_24 ) {
F_50 ( V_2 ) ;
F_24 ( ! V_6 -> V_50 [ V_53 ] . V_52 ) ;
if ( V_6 -> V_50 [ V_53 ] . V_52 == V_55 ) {
F_24 ( V_55 -> V_23 . V_24 -> V_56 ) ;
F_43 ( V_55 -> V_23 . V_24 ) ;
F_33 ( V_55 ) ;
V_6 -> V_50 [ V_53 ] . V_52 = NULL ;
}
F_43 ( V_55 -> V_23 . V_24 ) ;
}
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
struct V_49 * V_50 = & V_6 -> V_50 [ V_47 ] ;
if ( V_50 -> V_52 )
F_33 ( V_50 -> V_52 ) ;
V_50 -> V_54 = NULL ;
V_50 -> V_52 = NULL ;
}
F_33 ( V_55 ) ;
}
int F_51 ( struct V_5 * V_6 )
{
struct V_49 * V_50 ;
int V_8 , V_47 ;
F_35 ( ! V_6 -> V_50 [ V_53 ] . V_54 ) ;
if ( V_20 . V_21 )
return 0 ;
F_52 (ring, dev_priv, i) {
V_8 = F_53 ( V_50 , V_50 -> V_54 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static int F_54 ( int V_57 , void * V_58 , void * V_59 )
{
struct V_17 * V_18 = V_58 ;
F_33 ( V_18 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_32 * V_33 = V_61 -> V_62 ;
struct V_17 * V_18 ;
F_56 ( & V_33 -> V_38 ) ;
F_57 ( & V_2 -> V_43 ) ;
V_18 = F_34 ( V_2 , V_33 ) ;
F_58 ( & V_2 -> V_43 ) ;
if ( F_29 ( V_18 ) ) {
F_59 ( & V_33 -> V_38 ) ;
return F_30 ( V_18 ) ;
}
return 0 ;
}
void F_60 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_32 * V_33 = V_61 -> V_62 ;
F_61 ( & V_33 -> V_38 , F_54 , NULL ) ;
F_59 ( & V_33 -> V_38 ) ;
}
struct V_17 *
F_62 ( struct V_32 * V_33 , T_2 V_57 )
{
struct V_17 * V_18 ;
V_18 = (struct V_17 * ) F_63 ( & V_33 -> V_38 , V_57 ) ;
if ( ! V_18 )
return F_21 ( - V_63 ) ;
return V_18 ;
}
static inline int
F_64 ( struct V_49 * V_50 ,
struct V_17 * V_64 ,
T_2 V_65 )
{
T_2 V_66 = V_65 | V_67 ;
const int V_68 =
F_65 ( V_50 -> V_2 ) ?
F_66 ( F_4 ( V_50 -> V_2 ) -> V_69 ) - 1 :
0 ;
int V_70 , V_47 , V_8 ;
if ( F_2 ( V_50 -> V_2 ) ) {
V_8 = V_50 -> V_71 ( V_50 , V_72 , 0 ) ;
if ( V_8 )
return V_8 ;
}
if ( ! F_7 ( V_50 -> V_2 ) && F_4 ( V_50 -> V_2 ) -> V_10 < 8 )
V_66 |= ( V_73 | V_74 ) ;
V_70 = 4 ;
if ( F_4 ( V_50 -> V_2 ) -> V_10 >= 7 )
V_70 += 2 + ( V_68 ? 4 * V_68 + 2 : 0 ) ;
V_8 = F_67 ( V_50 , V_70 ) ;
if ( V_8 )
return V_8 ;
if ( F_4 ( V_50 -> V_2 ) -> V_10 >= 7 ) {
F_68 ( V_50 , V_75 | V_76 ) ;
if ( V_68 ) {
struct V_49 * V_77 ;
F_68 ( V_50 , F_69 ( V_68 ) ) ;
F_52 (signaller, to_i915(ring->dev), i) {
if ( V_77 == V_50 )
continue;
F_68 ( V_50 , F_70 ( V_77 -> V_78 ) ) ;
F_68 ( V_50 , F_71 ( V_79 ) ) ;
}
}
}
F_68 ( V_50 , V_80 ) ;
F_68 ( V_50 , V_81 ) ;
F_68 ( V_50 , F_72 ( V_64 -> V_23 . V_24 ) |
V_66 ) ;
F_68 ( V_50 , V_80 ) ;
if ( F_4 ( V_50 -> V_2 ) -> V_10 >= 7 ) {
if ( V_68 ) {
struct V_49 * V_77 ;
F_68 ( V_50 , F_69 ( V_68 ) ) ;
F_52 (signaller, to_i915(ring->dev), i) {
if ( V_77 == V_50 )
continue;
F_68 ( V_50 , F_70 ( V_77 -> V_78 ) ) ;
F_68 ( V_50 , F_73 ( V_79 ) ) ;
}
}
F_68 ( V_50 , V_75 | V_82 ) ;
}
F_74 ( V_50 ) ;
return V_8 ;
}
static int F_75 ( struct V_49 * V_50 ,
struct V_17 * V_83 )
{
struct V_5 * V_6 = V_50 -> V_2 -> V_7 ;
struct V_17 * V_84 = V_50 -> V_52 ;
T_2 V_65 = 0 ;
bool V_85 = false ;
struct V_86 * V_87 ;
int V_8 , V_47 ;
if ( V_84 != NULL && V_50 == & V_6 -> V_50 [ V_53 ] ) {
F_35 ( V_84 -> V_23 . V_24 == NULL ) ;
F_35 ( ! F_76 ( V_84 -> V_23 . V_24 ) ) ;
}
if ( V_84 == V_83 && ! V_83 -> V_41 )
return 0 ;
if ( V_50 == & V_6 -> V_50 [ V_53 ] ) {
V_8 = F_37 ( V_83 -> V_23 . V_24 ,
F_1 ( V_50 -> V_2 ) , 0 ) ;
if ( V_8 )
return V_8 ;
}
V_84 = V_50 -> V_52 ;
if ( V_83 -> V_22 ) {
F_77 ( V_50 , V_83 ) ;
V_8 = V_83 -> V_22 -> V_88 ( V_83 -> V_22 , V_50 ) ;
if ( V_8 )
goto V_89;
}
if ( V_50 != & V_6 -> V_50 [ V_53 ] ) {
if ( V_84 )
F_33 ( V_84 ) ;
goto V_90;
}
V_8 = F_78 ( V_83 -> V_23 . V_24 , false ) ;
if ( V_8 )
goto V_89;
V_87 = F_79 ( V_83 -> V_23 . V_24 ) ;
if ( ! ( V_87 -> V_91 & V_92 ) )
V_87 -> V_93 ( V_87 , V_83 -> V_23 . V_24 -> V_94 ,
V_92 ) ;
if ( ! V_83 -> V_23 . V_95 || F_80 ( V_83 ) )
V_65 |= V_96 ;
V_8 = F_64 ( V_50 , V_83 , V_65 ) ;
if ( V_8 )
goto V_89;
for ( V_47 = 0 ; V_47 < V_97 ; V_47 ++ ) {
if ( ! ( V_83 -> V_41 & ( 1 << V_47 ) ) )
continue;
V_8 = F_81 ( V_50 , V_47 ) ;
if ( V_8 )
F_38 ( L_9 ) ;
else
V_83 -> V_41 &= ~ ( 1 << V_47 ) ;
}
if ( V_84 != NULL ) {
V_84 -> V_23 . V_24 -> V_25 . V_98 = V_99 ;
F_82 ( F_79 ( V_84 -> V_23 . V_24 ) , V_50 ) ;
V_84 -> V_23 . V_24 -> V_100 = 1 ;
F_35 ( V_84 -> V_23 . V_24 -> V_50 != V_50 ) ;
F_43 ( V_84 -> V_23 . V_24 ) ;
F_33 ( V_84 ) ;
}
V_85 = ! V_83 -> V_23 . V_95 && V_84 == NULL ;
V_83 -> V_23 . V_95 = true ;
V_90:
F_83 ( V_83 ) ;
V_50 -> V_52 = V_83 ;
if ( V_85 ) {
if ( V_50 -> V_101 ) {
V_8 = V_50 -> V_101 ( V_50 , V_83 ) ;
if ( V_8 )
F_48 ( L_10 , V_8 ) ;
}
V_8 = F_84 ( V_50 ) ;
if ( V_8 )
F_48 ( L_11 , V_8 ) ;
}
return 0 ;
V_89:
if ( V_50 -> V_57 == V_53 )
F_43 ( V_83 -> V_23 . V_24 ) ;
return V_8 ;
}
int F_53 ( struct V_49 * V_50 ,
struct V_17 * V_83 )
{
struct V_5 * V_6 = V_50 -> V_2 -> V_7 ;
F_24 ( V_20 . V_21 ) ;
F_24 ( ! F_36 ( & V_6 -> V_2 -> V_43 ) ) ;
if ( V_83 -> V_23 . V_24 == NULL ) {
if ( V_83 != V_50 -> V_52 ) {
F_83 ( V_83 ) ;
if ( V_50 -> V_52 )
F_33 ( V_50 -> V_52 ) ;
V_50 -> V_52 = V_83 ;
}
return 0 ;
}
return F_75 ( V_50 , V_83 ) ;
}
static bool F_85 ( struct V_1 * V_2 )
{
return V_20 . V_21 || F_86 ( V_2 ) -> V_36 ;
}
int F_87 ( struct V_1 * V_2 , void * V_59 ,
struct V_60 * V_61 )
{
struct V_102 * args = V_59 ;
struct V_32 * V_33 = V_61 -> V_62 ;
struct V_17 * V_18 ;
int V_8 ;
if ( ! F_85 ( V_2 ) )
return - V_103 ;
V_8 = F_88 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_34 ( V_2 , V_33 ) ;
F_58 ( & V_2 -> V_43 ) ;
if ( F_29 ( V_18 ) )
return F_30 ( V_18 ) ;
args -> V_104 = V_18 -> V_40 ;
F_38 ( L_12 , args -> V_104 ) ;
return 0 ;
}
int F_89 ( struct V_1 * V_2 , void * V_59 ,
struct V_60 * V_61 )
{
struct V_105 * args = V_59 ;
struct V_32 * V_33 = V_61 -> V_62 ;
struct V_17 * V_18 ;
int V_8 ;
if ( args -> V_104 == V_39 )
return - V_63 ;
V_8 = F_88 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_62 ( V_33 , args -> V_104 ) ;
if ( F_29 ( V_18 ) ) {
F_58 ( & V_2 -> V_43 ) ;
return F_30 ( V_18 ) ;
}
F_90 ( & V_18 -> V_33 -> V_38 , V_18 -> V_40 ) ;
F_33 ( V_18 ) ;
F_58 ( & V_2 -> V_43 ) ;
F_38 ( L_13 , args -> V_104 ) ;
return 0 ;
}
