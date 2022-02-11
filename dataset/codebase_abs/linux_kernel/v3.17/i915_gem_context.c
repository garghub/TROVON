static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = & V_2 -> V_5 ;
if ( V_2 == V_7 -> V_11 . V_12 ||
( F_2 ( & V_10 -> V_13 ) && F_2 ( & V_10 -> V_14 ) ) ) {
V_2 -> V_5 . V_15 ( & V_2 -> V_5 ) ;
return;
}
if ( ! F_2 ( & V_10 -> V_13 ) ) {
struct V_16 * V_17 ;
F_3 (vma, &vm->active_list, mm_list)
if ( F_4 ( F_2 ( & V_17 -> V_18 ) ||
F_5 ( & V_17 -> V_18 ) ) )
break;
F_6 ( & V_2 -> V_5 , true ) ;
} else {
F_7 ( V_4 ) ;
F_6 ( & V_2 -> V_5 , false ) ;
}
V_2 -> V_5 . V_15 ( & V_2 -> V_5 ) ;
}
static void F_8 ( struct V_19 * V_19 )
{
struct V_1 * V_2 =
F_9 ( V_19 , struct V_1 , V_20 ) ;
F_1 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static T_1 F_11 ( struct V_3 * V_4 )
{
if ( F_12 ( V_4 ) )
return V_21 ;
return V_22 ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
int V_23 ;
T_2 V_24 ;
switch ( F_14 ( V_4 ) -> V_25 ) {
case 6 :
V_24 = F_15 ( V_26 ) ;
V_23 = F_16 ( V_24 ) * 64 ;
break;
case 7 :
V_24 = F_15 ( V_27 ) ;
if ( F_17 ( V_4 ) )
V_23 = V_28 ;
else
V_23 = F_18 ( V_24 ) * 64 ;
break;
case 8 :
V_23 = V_29 ;
break;
default:
F_19 () ;
}
return V_23 ;
}
void F_20 ( struct V_19 * V_30 )
{
struct V_31 * V_32 = F_9 ( V_30 ,
F_21 ( * V_32 ) , V_20 ) ;
struct V_1 * V_2 = NULL ;
if ( V_32 -> V_33 . V_34 ) {
if ( F_22 ( V_32 -> V_33 . V_34 -> V_5 . V_4 ) )
V_2 = F_23 ( V_32 ) ;
}
if ( V_2 )
F_24 ( & V_2 -> V_20 , F_8 ) ;
if ( V_32 -> V_33 . V_34 )
F_25 ( & V_32 -> V_33 . V_34 -> V_5 ) ;
F_26 ( & V_32 -> V_35 ) ;
F_10 ( V_32 ) ;
}
static struct V_36 *
F_27 ( struct V_3 * V_4 , T_1 V_37 )
{
struct V_36 * V_38 ;
int V_23 ;
V_38 = F_28 ( V_4 , V_37 ) ;
if ( V_38 == NULL )
return F_29 ( - V_39 ) ;
if ( F_14 ( V_4 ) -> V_25 >= 7 && ! F_30 ( V_4 ) ) {
V_23 = F_31 ( V_38 , V_40 ) ;
if ( F_4 ( V_23 ) ) {
F_25 ( & V_38 -> V_5 ) ;
return F_29 ( V_23 ) ;
}
}
return V_38 ;
}
static struct V_1 *
F_32 ( struct V_3 * V_4 , struct V_31 * V_32 )
{
struct V_1 * V_2 ;
int V_23 ;
V_2 = F_33 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return F_29 ( - V_39 ) ;
V_23 = F_34 ( V_4 , V_2 ) ;
if ( V_23 ) {
F_10 ( V_2 ) ;
return F_29 ( V_23 ) ;
}
V_2 -> V_32 = V_32 ;
return V_2 ;
}
static struct V_31 *
F_35 ( struct V_3 * V_4 ,
struct V_42 * V_43 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_31 * V_32 ;
int V_23 ;
V_32 = F_33 ( sizeof( * V_32 ) , V_41 ) ;
if ( V_32 == NULL )
return F_29 ( - V_39 ) ;
F_36 ( & V_32 -> V_20 ) ;
F_37 ( & V_32 -> V_35 , & V_7 -> V_44 ) ;
if ( V_7 -> V_45 ) {
struct V_36 * V_38 =
F_27 ( V_4 , V_7 -> V_45 ) ;
if ( F_38 ( V_38 ) ) {
V_23 = F_39 ( V_38 ) ;
goto V_46;
}
V_32 -> V_33 . V_34 = V_38 ;
}
if ( V_43 != NULL ) {
V_23 = F_40 ( & V_43 -> V_47 , V_32 ,
V_48 , 0 , V_41 ) ;
if ( V_23 < 0 )
goto V_46;
} else
V_23 = V_48 ;
V_32 -> V_43 = V_43 ;
V_32 -> V_49 = V_23 ;
V_32 -> V_50 = ( 1 << F_41 ( V_4 ) ) - 1 ;
return V_32 ;
V_46:
F_42 ( V_32 ) ;
return F_29 ( V_23 ) ;
}
static struct V_31 *
F_43 ( struct V_3 * V_4 ,
struct V_42 * V_43 ,
bool V_51 )
{
const bool V_52 = V_43 == NULL ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_31 * V_32 ;
int V_23 = 0 ;
F_44 ( ! F_45 ( & V_4 -> V_53 ) ) ;
V_32 = F_35 ( V_4 , V_43 ) ;
if ( F_38 ( V_32 ) )
return V_32 ;
if ( V_52 && V_32 -> V_33 . V_34 ) {
V_23 = F_46 ( V_32 -> V_33 . V_34 ,
F_11 ( V_4 ) , 0 ) ;
if ( V_23 ) {
F_47 ( L_1 , V_23 ) ;
goto V_54;
}
}
if ( V_51 ) {
struct V_1 * V_2 = F_32 ( V_4 , V_32 ) ;
if ( F_48 ( V_2 ) ) {
F_47 ( L_2 ,
F_39 ( V_2 ) ) ;
V_23 = F_39 ( V_2 ) ;
goto V_55;
} else
V_32 -> V_10 = & V_2 -> V_5 ;
if ( V_52 ) {
if ( F_4 ( V_7 -> V_11 . V_12 ) ) {
V_23 = - V_56 ;
goto V_55;
}
V_7 -> V_11 . V_12 = V_2 ;
}
} else if ( F_22 ( V_4 ) ) {
V_32 -> V_10 = & V_7 -> V_11 . V_12 -> V_5 ;
F_49 ( & V_7 -> V_11 . V_12 -> V_20 ) ;
} else
V_32 -> V_10 = & V_7 -> V_57 . V_5 ;
return V_32 ;
V_55:
if ( V_52 && V_32 -> V_33 . V_34 )
F_50 ( V_32 -> V_33 . V_34 ) ;
V_54:
F_42 ( V_32 ) ;
return F_29 ( V_23 ) ;
}
void F_51 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
struct V_60 * V_61 = & V_7 -> V_61 [ V_58 ] ;
struct V_31 * V_62 = V_61 -> V_63 ;
struct V_31 * V_64 = V_61 -> V_65 ;
if ( V_64 == V_62 )
continue;
if ( ! V_64 )
continue;
if ( V_62 -> V_33 . V_34 && V_58 == V_66 ) {
F_4 ( F_46 ( V_62 -> V_33 . V_34 ,
F_11 ( V_4 ) , 0 ) ) ;
V_62 -> V_33 . V_34 -> V_5 . V_67 = 0 ;
V_62 -> V_33 . V_34 -> V_68 = 0 ;
}
if ( V_64 -> V_33 . V_34 && V_58 == V_66 )
F_50 ( V_64 -> V_33 . V_34 ) ;
F_42 ( V_64 ) ;
F_52 ( V_62 ) ;
V_61 -> V_65 = V_62 ;
}
}
int F_53 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_31 * V_32 ;
int V_58 ;
if ( F_4 ( V_7 -> V_61 [ V_66 ] . V_63 ) )
return 0 ;
if ( F_54 ( V_4 ) ) {
V_7 -> V_45 = F_55 ( F_13 ( V_4 ) , 4096 ) ;
if ( V_7 -> V_45 > ( 1 << 20 ) ) {
F_47 ( L_3 ,
V_7 -> V_45 ) ;
V_7 -> V_45 = 0 ;
}
}
V_32 = F_43 ( V_4 , NULL , F_22 ( V_4 ) ) ;
if ( F_38 ( V_32 ) ) {
F_56 ( L_4 ,
F_39 ( V_32 ) ) ;
return F_39 ( V_32 ) ;
}
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ )
V_7 -> V_61 [ V_58 ] . V_63 = V_32 ;
F_47 ( L_5 , V_7 -> V_45 ? L_6 : L_7 ) ;
return 0 ;
}
void F_57 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_31 * V_62 = V_7 -> V_61 [ V_66 ] . V_63 ;
int V_58 ;
if ( V_62 -> V_33 . V_34 ) {
F_58 ( V_4 ) ;
F_4 ( ! V_7 -> V_61 [ V_66 ] . V_65 ) ;
if ( V_7 -> V_61 [ V_66 ] . V_65 == V_62 ) {
F_4 ( V_62 -> V_33 . V_34 -> V_68 ) ;
F_50 ( V_62 -> V_33 . V_34 ) ;
F_42 ( V_62 ) ;
V_7 -> V_61 [ V_66 ] . V_65 = NULL ;
}
F_50 ( V_62 -> V_33 . V_34 ) ;
}
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
struct V_60 * V_61 = & V_7 -> V_61 [ V_58 ] ;
if ( V_61 -> V_65 )
F_42 ( V_61 -> V_65 ) ;
V_61 -> V_63 = NULL ;
V_61 -> V_65 = NULL ;
}
F_42 ( V_62 ) ;
}
int F_59 ( struct V_6 * V_7 )
{
struct V_60 * V_61 ;
int V_23 , V_58 ;
if ( V_7 -> V_11 . V_12 ) {
struct V_1 * V_2 = V_7 -> V_11 . V_12 ;
V_2 -> V_69 ( V_2 ) ;
}
if ( F_60 ( & V_7 -> V_70 ) )
return 0 ;
F_44 ( ! V_7 -> V_61 [ V_66 ] . V_63 ) ;
F_61 (ring, dev_priv, i) {
V_23 = F_62 ( V_61 , V_61 -> V_63 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static int F_63 ( int V_71 , void * V_72 , void * V_73 )
{
struct V_31 * V_32 = V_72 ;
F_42 ( V_32 ) ;
return 0 ;
}
int F_64 ( struct V_3 * V_4 , struct V_74 * V_75 )
{
struct V_42 * V_43 = V_75 -> V_76 ;
struct V_31 * V_32 ;
F_65 ( & V_43 -> V_47 ) ;
F_66 ( & V_4 -> V_53 ) ;
V_32 = F_43 ( V_4 , V_43 , F_67 ( V_4 ) ) ;
F_68 ( & V_4 -> V_53 ) ;
if ( F_38 ( V_32 ) ) {
F_69 ( & V_43 -> V_47 ) ;
return F_39 ( V_32 ) ;
}
return 0 ;
}
void F_70 ( struct V_3 * V_4 , struct V_74 * V_75 )
{
struct V_42 * V_43 = V_75 -> V_76 ;
F_71 ( & V_43 -> V_47 , F_63 , NULL ) ;
F_69 ( & V_43 -> V_47 ) ;
}
struct V_31 *
F_72 ( struct V_42 * V_43 , T_2 V_71 )
{
struct V_31 * V_32 ;
V_32 = (struct V_31 * ) F_73 ( & V_43 -> V_47 , V_71 ) ;
if ( ! V_32 )
return F_29 ( - V_77 ) ;
return V_32 ;
}
static inline int
F_74 ( struct V_60 * V_61 ,
struct V_31 * V_78 ,
T_2 V_79 )
{
int V_23 ;
if ( F_12 ( V_61 -> V_4 ) ) {
V_23 = V_61 -> V_80 ( V_61 , V_81 , 0 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_75 ( V_61 , 6 ) ;
if ( V_23 )
return V_23 ;
if ( F_14 ( V_61 -> V_4 ) -> V_25 >= 7 )
F_76 ( V_61 , V_82 | V_83 ) ;
else
F_76 ( V_61 , V_84 ) ;
F_76 ( V_61 , V_84 ) ;
F_76 ( V_61 , V_85 ) ;
F_76 ( V_61 , F_77 ( V_78 -> V_33 . V_34 ) |
V_86 |
V_87 |
V_88 |
V_79 ) ;
F_76 ( V_61 , V_84 ) ;
if ( F_14 ( V_61 -> V_4 ) -> V_25 >= 7 )
F_76 ( V_61 , V_82 | V_89 ) ;
else
F_76 ( V_61 , V_84 ) ;
F_78 ( V_61 ) ;
return V_23 ;
}
static int F_79 ( struct V_60 * V_61 ,
struct V_31 * V_90 )
{
struct V_6 * V_7 = V_61 -> V_4 -> V_8 ;
struct V_31 * V_91 = V_61 -> V_65 ;
struct V_1 * V_2 = F_23 ( V_90 ) ;
T_2 V_79 = 0 ;
bool V_92 = false ;
int V_23 , V_58 ;
if ( V_91 != NULL && V_61 == & V_7 -> V_61 [ V_66 ] ) {
F_44 ( V_91 -> V_33 . V_34 == NULL ) ;
F_44 ( ! F_80 ( V_91 -> V_33 . V_34 ) ) ;
}
if ( V_91 == V_90 && ! V_90 -> V_50 )
return 0 ;
if ( V_61 == & V_7 -> V_61 [ V_66 ] ) {
V_23 = F_46 ( V_90 -> V_33 . V_34 ,
F_11 ( V_61 -> V_4 ) , 0 ) ;
if ( V_23 )
return V_23 ;
}
V_91 = V_61 -> V_65 ;
if ( F_67 ( V_61 -> V_4 ) ) {
V_23 = V_2 -> V_93 ( V_2 , V_61 , false ) ;
if ( V_23 )
goto V_94;
}
if ( V_61 != & V_7 -> V_61 [ V_66 ] ) {
if ( V_91 )
F_42 ( V_91 ) ;
goto V_95;
}
V_23 = F_81 ( V_90 -> V_33 . V_34 , false ) ;
if ( V_23 )
goto V_94;
if ( ! V_90 -> V_33 . V_34 -> V_96 ) {
struct V_16 * V_17 = F_82 ( V_90 -> V_33 . V_34 ,
& V_7 -> V_57 . V_5 ) ;
V_17 -> V_97 ( V_17 , V_90 -> V_33 . V_34 -> V_98 , V_99 ) ;
}
if ( ! V_90 -> V_33 . V_100 || F_83 ( V_90 ) )
V_79 |= V_101 ;
V_23 = F_74 ( V_61 , V_90 , V_79 ) ;
if ( V_23 )
goto V_94;
for ( V_58 = 0 ; V_58 < V_102 ; V_58 ++ ) {
if ( ! ( V_90 -> V_50 & ( 1 << V_58 ) ) )
continue;
V_23 = F_84 ( V_61 , V_58 ) ;
if ( V_23 )
F_47 ( L_8 ) ;
else
V_90 -> V_50 &= ~ ( 1 << V_58 ) ;
}
if ( V_91 != NULL ) {
V_91 -> V_33 . V_34 -> V_5 . V_103 = V_104 ;
F_85 ( F_86 ( V_91 -> V_33 . V_34 ) , V_61 ) ;
V_91 -> V_33 . V_34 -> V_105 = 1 ;
F_44 ( V_91 -> V_33 . V_34 -> V_61 != V_61 ) ;
F_50 ( V_91 -> V_33 . V_34 ) ;
F_42 ( V_91 ) ;
}
V_92 = ! V_90 -> V_33 . V_100 && V_91 == NULL ;
V_90 -> V_33 . V_100 = true ;
V_95:
F_52 ( V_90 ) ;
V_61 -> V_65 = V_90 ;
if ( V_92 ) {
V_23 = F_87 ( V_61 ) ;
if ( V_23 )
F_56 ( L_9 , V_23 ) ;
}
return 0 ;
V_94:
if ( V_61 -> V_71 == V_66 )
F_50 ( V_90 -> V_33 . V_34 ) ;
return V_23 ;
}
int F_62 ( struct V_60 * V_61 ,
struct V_31 * V_90 )
{
struct V_6 * V_7 = V_61 -> V_4 -> V_8 ;
F_4 ( ! F_45 ( & V_7 -> V_4 -> V_53 ) ) ;
if ( V_90 -> V_33 . V_34 == NULL ) {
if ( V_90 != V_61 -> V_65 ) {
F_52 ( V_90 ) ;
if ( V_61 -> V_65 )
F_42 ( V_61 -> V_65 ) ;
V_61 -> V_65 = V_90 ;
}
return 0 ;
}
return F_79 ( V_61 , V_90 ) ;
}
static bool F_88 ( struct V_3 * V_4 )
{
return F_89 ( V_4 ) -> V_45 ;
}
int F_90 ( struct V_3 * V_4 , void * V_73 ,
struct V_74 * V_75 )
{
struct V_106 * args = V_73 ;
struct V_42 * V_43 = V_75 -> V_76 ;
struct V_31 * V_32 ;
int V_23 ;
if ( ! F_88 ( V_4 ) )
return - V_107 ;
V_23 = F_91 ( V_4 ) ;
if ( V_23 )
return V_23 ;
V_32 = F_43 ( V_4 , V_43 , F_67 ( V_4 ) ) ;
F_68 ( & V_4 -> V_53 ) ;
if ( F_38 ( V_32 ) )
return F_39 ( V_32 ) ;
args -> V_108 = V_32 -> V_49 ;
F_47 ( L_10 , args -> V_108 ) ;
return 0 ;
}
int F_92 ( struct V_3 * V_4 , void * V_73 ,
struct V_74 * V_75 )
{
struct V_109 * args = V_73 ;
struct V_42 * V_43 = V_75 -> V_76 ;
struct V_31 * V_32 ;
int V_23 ;
if ( args -> V_108 == V_48 )
return - V_77 ;
V_23 = F_91 ( V_4 ) ;
if ( V_23 )
return V_23 ;
V_32 = F_72 ( V_43 , args -> V_108 ) ;
if ( F_38 ( V_32 ) ) {
F_68 ( & V_4 -> V_53 ) ;
return F_39 ( V_32 ) ;
}
F_93 ( & V_32 -> V_43 -> V_47 , V_32 -> V_49 ) ;
F_42 ( V_32 ) ;
F_68 ( & V_4 -> V_53 ) ;
F_47 ( L_11 , args -> V_108 ) ;
return 0 ;
}
