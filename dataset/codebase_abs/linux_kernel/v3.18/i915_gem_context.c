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
if ( V_20 . V_21 )
F_13 ( V_18 ) ;
F_14 ( V_18 -> V_22 ) ;
if ( V_18 -> V_23 . V_24 )
F_15 ( & V_18 -> V_23 . V_24 -> V_25 ) ;
F_16 ( & V_18 -> V_26 ) ;
F_17 ( V_18 ) ;
}
struct V_27 *
F_18 ( struct V_1 * V_2 , T_1 V_28 )
{
struct V_27 * V_29 ;
int V_8 ;
V_29 = F_19 ( V_2 , V_28 ) ;
if ( V_29 == NULL )
return F_20 ( - V_30 ) ;
if ( F_4 ( V_2 ) -> V_10 >= 7 && ! F_21 ( V_2 ) ) {
V_8 = F_22 ( V_29 , V_31 ) ;
if ( F_23 ( V_8 ) ) {
F_15 ( & V_29 -> V_25 ) ;
return F_20 ( V_8 ) ;
}
}
return V_29 ;
}
static struct V_17 *
F_24 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_18 ;
int V_8 ;
V_18 = F_25 ( sizeof( * V_18 ) , V_34 ) ;
if ( V_18 == NULL )
return F_20 ( - V_30 ) ;
F_26 ( & V_18 -> V_19 ) ;
F_27 ( & V_18 -> V_26 , & V_6 -> V_35 ) ;
if ( V_6 -> V_36 ) {
struct V_27 * V_29 =
F_18 ( V_2 , V_6 -> V_36 ) ;
if ( F_28 ( V_29 ) ) {
V_8 = F_29 ( V_29 ) ;
goto V_37;
}
V_18 -> V_23 . V_24 = V_29 ;
}
if ( V_33 != NULL ) {
V_8 = F_30 ( & V_33 -> V_38 , V_18 ,
V_39 , 0 , V_34 ) ;
if ( V_8 < 0 )
goto V_37;
} else
V_8 = V_39 ;
V_18 -> V_33 = V_33 ;
V_18 -> V_40 = V_8 ;
V_18 -> V_41 = ( 1 << F_31 ( V_2 ) ) - 1 ;
return V_18 ;
V_37:
F_32 ( V_18 ) ;
return F_20 ( V_8 ) ;
}
static struct V_17 *
F_33 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
const bool V_42 = V_33 == NULL ;
struct V_17 * V_18 ;
int V_8 = 0 ;
F_34 ( ! F_35 ( & V_2 -> V_43 ) ) ;
V_18 = F_24 ( V_2 , V_33 ) ;
if ( F_28 ( V_18 ) )
return V_18 ;
if ( V_42 && V_18 -> V_23 . V_24 ) {
V_8 = F_36 ( V_18 -> V_23 . V_24 ,
F_1 ( V_2 ) , 0 ) ;
if ( V_8 ) {
F_37 ( L_1 , V_8 ) ;
goto V_44;
}
}
if ( F_38 ( V_2 ) ) {
struct V_45 * V_22 = F_39 ( V_2 , V_33 ) ;
if ( F_40 ( V_22 ) ) {
F_37 ( L_2 ,
F_29 ( V_22 ) ) ;
V_8 = F_29 ( V_22 ) ;
goto V_46;
}
V_18 -> V_22 = V_22 ;
}
return V_18 ;
V_46:
if ( V_42 && V_18 -> V_23 . V_24 )
F_41 ( V_18 -> V_23 . V_24 ) ;
V_44:
F_32 ( V_18 ) ;
return F_20 ( V_8 ) ;
}
void F_42 ( struct V_1 * V_2 )
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
F_41 ( V_51 -> V_23 . V_24 ) ;
F_32 ( V_51 ) ;
V_50 -> V_52 = NULL ;
}
}
}
int F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_18 ;
int V_47 ;
if ( F_23 ( V_6 -> V_50 [ V_53 ] . V_54 ) )
return 0 ;
if ( V_20 . V_21 ) {
V_6 -> V_36 = 0 ;
} else if ( F_44 ( V_2 ) ) {
V_6 -> V_36 = F_45 ( F_3 ( V_2 ) , 4096 ) ;
if ( V_6 -> V_36 > ( 1 << 20 ) ) {
F_37 ( L_3 ,
V_6 -> V_36 ) ;
V_6 -> V_36 = 0 ;
}
}
V_18 = F_33 ( V_2 , NULL ) ;
if ( F_28 ( V_18 ) ) {
F_46 ( L_4 ,
F_29 ( V_18 ) ) ;
return F_29 ( V_18 ) ;
}
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
struct V_49 * V_50 = & V_6 -> V_50 [ V_47 ] ;
V_50 -> V_54 = V_18 ;
}
F_37 ( L_5 ,
V_20 . V_21 ? L_6 :
V_6 -> V_36 ? L_7 : L_8 ) ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_55 = V_6 -> V_50 [ V_53 ] . V_54 ;
int V_47 ;
if ( V_55 -> V_23 . V_24 ) {
F_48 ( V_2 ) ;
F_23 ( ! V_6 -> V_50 [ V_53 ] . V_52 ) ;
if ( V_6 -> V_50 [ V_53 ] . V_52 == V_55 ) {
F_23 ( V_55 -> V_23 . V_24 -> V_56 ) ;
F_41 ( V_55 -> V_23 . V_24 ) ;
F_32 ( V_55 ) ;
V_6 -> V_50 [ V_53 ] . V_52 = NULL ;
}
F_41 ( V_55 -> V_23 . V_24 ) ;
}
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
struct V_49 * V_50 = & V_6 -> V_50 [ V_47 ] ;
if ( V_50 -> V_52 )
F_32 ( V_50 -> V_52 ) ;
V_50 -> V_54 = NULL ;
V_50 -> V_52 = NULL ;
}
F_32 ( V_55 ) ;
}
int F_49 ( struct V_5 * V_6 )
{
struct V_49 * V_50 ;
int V_8 , V_47 ;
F_34 ( ! V_6 -> V_50 [ V_53 ] . V_54 ) ;
if ( V_20 . V_21 )
return 0 ;
F_50 (ring, dev_priv, i) {
V_8 = F_51 ( V_50 , V_50 -> V_54 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static int F_52 ( int V_57 , void * V_58 , void * V_59 )
{
struct V_17 * V_18 = V_58 ;
F_32 ( V_18 ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_32 * V_33 = V_61 -> V_62 ;
struct V_17 * V_18 ;
F_54 ( & V_33 -> V_38 ) ;
F_55 ( & V_2 -> V_43 ) ;
V_18 = F_33 ( V_2 , V_33 ) ;
F_56 ( & V_2 -> V_43 ) ;
if ( F_28 ( V_18 ) ) {
F_57 ( & V_33 -> V_38 ) ;
return F_29 ( V_18 ) ;
}
return 0 ;
}
void F_58 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_32 * V_33 = V_61 -> V_62 ;
F_59 ( & V_33 -> V_38 , F_52 , NULL ) ;
F_57 ( & V_33 -> V_38 ) ;
}
struct V_17 *
F_60 ( struct V_32 * V_33 , T_2 V_57 )
{
struct V_17 * V_18 ;
V_18 = (struct V_17 * ) F_61 ( & V_33 -> V_38 , V_57 ) ;
if ( ! V_18 )
return F_20 ( - V_63 ) ;
return V_18 ;
}
static inline int
F_62 ( struct V_49 * V_50 ,
struct V_17 * V_64 ,
T_2 V_65 )
{
T_2 V_66 = V_65 | V_67 ;
int V_8 ;
if ( F_2 ( V_50 -> V_2 ) ) {
V_8 = V_50 -> V_68 ( V_50 , V_69 , 0 ) ;
if ( V_8 )
return V_8 ;
}
if ( ! F_7 ( V_50 -> V_2 ) && F_4 ( V_50 -> V_2 ) -> V_10 < 8 )
V_66 |= ( V_70 | V_71 ) ;
V_8 = F_63 ( V_50 , 6 ) ;
if ( V_8 )
return V_8 ;
if ( F_4 ( V_50 -> V_2 ) -> V_10 >= 7 )
F_64 ( V_50 , V_72 | V_73 ) ;
else
F_64 ( V_50 , V_74 ) ;
F_64 ( V_50 , V_74 ) ;
F_64 ( V_50 , V_75 ) ;
F_64 ( V_50 , F_65 ( V_64 -> V_23 . V_24 ) |
V_66 ) ;
F_64 ( V_50 , V_74 ) ;
if ( F_4 ( V_50 -> V_2 ) -> V_10 >= 7 )
F_64 ( V_50 , V_72 | V_76 ) ;
else
F_64 ( V_50 , V_74 ) ;
F_66 ( V_50 ) ;
return V_8 ;
}
static int F_67 ( struct V_49 * V_50 ,
struct V_17 * V_77 )
{
struct V_5 * V_6 = V_50 -> V_2 -> V_7 ;
struct V_17 * V_78 = V_50 -> V_52 ;
T_2 V_65 = 0 ;
bool V_79 = false ;
int V_8 , V_47 ;
if ( V_78 != NULL && V_50 == & V_6 -> V_50 [ V_53 ] ) {
F_34 ( V_78 -> V_23 . V_24 == NULL ) ;
F_34 ( ! F_68 ( V_78 -> V_23 . V_24 ) ) ;
}
if ( V_78 == V_77 && ! V_77 -> V_41 )
return 0 ;
if ( V_50 == & V_6 -> V_50 [ V_53 ] ) {
V_8 = F_36 ( V_77 -> V_23 . V_24 ,
F_1 ( V_50 -> V_2 ) , 0 ) ;
if ( V_8 )
return V_8 ;
}
V_78 = V_50 -> V_52 ;
if ( V_77 -> V_22 ) {
V_8 = V_77 -> V_22 -> V_80 ( V_77 -> V_22 , V_50 ) ;
if ( V_8 )
goto V_81;
}
if ( V_50 != & V_6 -> V_50 [ V_53 ] ) {
if ( V_78 )
F_32 ( V_78 ) ;
goto V_82;
}
V_8 = F_69 ( V_77 -> V_23 . V_24 , false ) ;
if ( V_8 )
goto V_81;
if ( ! V_77 -> V_23 . V_24 -> V_83 ) {
struct V_84 * V_85 = F_70 ( V_77 -> V_23 . V_24 ,
& V_6 -> V_86 . V_25 ) ;
V_85 -> V_87 ( V_85 , V_77 -> V_23 . V_24 -> V_88 , V_89 ) ;
}
if ( ! V_77 -> V_23 . V_90 || F_71 ( V_77 ) )
V_65 |= V_91 ;
V_8 = F_62 ( V_50 , V_77 , V_65 ) ;
if ( V_8 )
goto V_81;
for ( V_47 = 0 ; V_47 < V_92 ; V_47 ++ ) {
if ( ! ( V_77 -> V_41 & ( 1 << V_47 ) ) )
continue;
V_8 = F_72 ( V_50 , V_47 ) ;
if ( V_8 )
F_37 ( L_9 ) ;
else
V_77 -> V_41 &= ~ ( 1 << V_47 ) ;
}
if ( V_78 != NULL ) {
V_78 -> V_23 . V_24 -> V_25 . V_93 = V_94 ;
F_73 ( F_74 ( V_78 -> V_23 . V_24 ) , V_50 ) ;
V_78 -> V_23 . V_24 -> V_95 = 1 ;
F_34 ( V_78 -> V_23 . V_24 -> V_50 != V_50 ) ;
F_41 ( V_78 -> V_23 . V_24 ) ;
F_32 ( V_78 ) ;
}
V_79 = ! V_77 -> V_23 . V_90 && V_78 == NULL ;
V_77 -> V_23 . V_90 = true ;
V_82:
F_75 ( V_77 ) ;
V_50 -> V_52 = V_77 ;
if ( V_79 ) {
if ( V_50 -> V_96 ) {
V_8 = V_50 -> V_96 ( V_50 ) ;
if ( V_8 )
F_46 ( L_10 , V_8 ) ;
}
V_8 = F_76 ( V_50 ) ;
if ( V_8 )
F_46 ( L_11 , V_8 ) ;
}
return 0 ;
V_81:
if ( V_50 -> V_57 == V_53 )
F_41 ( V_77 -> V_23 . V_24 ) ;
return V_8 ;
}
int F_51 ( struct V_49 * V_50 ,
struct V_17 * V_77 )
{
struct V_5 * V_6 = V_50 -> V_2 -> V_7 ;
F_23 ( V_20 . V_21 ) ;
F_23 ( ! F_35 ( & V_6 -> V_2 -> V_43 ) ) ;
if ( V_77 -> V_23 . V_24 == NULL ) {
if ( V_77 != V_50 -> V_52 ) {
F_75 ( V_77 ) ;
if ( V_50 -> V_52 )
F_32 ( V_50 -> V_52 ) ;
V_50 -> V_52 = V_77 ;
}
return 0 ;
}
return F_67 ( V_50 , V_77 ) ;
}
static bool F_77 ( struct V_1 * V_2 )
{
return V_20 . V_21 || F_78 ( V_2 ) -> V_36 ;
}
int F_79 ( struct V_1 * V_2 , void * V_59 ,
struct V_60 * V_61 )
{
struct V_97 * args = V_59 ;
struct V_32 * V_33 = V_61 -> V_62 ;
struct V_17 * V_18 ;
int V_8 ;
if ( ! F_77 ( V_2 ) )
return - V_98 ;
V_8 = F_80 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_33 ( V_2 , V_33 ) ;
F_56 ( & V_2 -> V_43 ) ;
if ( F_28 ( V_18 ) )
return F_29 ( V_18 ) ;
args -> V_99 = V_18 -> V_40 ;
F_37 ( L_12 , args -> V_99 ) ;
return 0 ;
}
int F_81 ( struct V_1 * V_2 , void * V_59 ,
struct V_60 * V_61 )
{
struct V_100 * args = V_59 ;
struct V_32 * V_33 = V_61 -> V_62 ;
struct V_17 * V_18 ;
int V_8 ;
if ( args -> V_99 == V_39 )
return - V_63 ;
V_8 = F_80 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_18 = F_60 ( V_33 , args -> V_99 ) ;
if ( F_28 ( V_18 ) ) {
F_56 ( & V_2 -> V_43 ) ;
return F_29 ( V_18 ) ;
}
F_82 ( & V_18 -> V_33 -> V_38 , V_18 -> V_40 ) ;
F_32 ( V_18 ) ;
F_56 ( & V_2 -> V_43 ) ;
F_37 ( L_13 , args -> V_99 ) ;
return 0 ;
}
