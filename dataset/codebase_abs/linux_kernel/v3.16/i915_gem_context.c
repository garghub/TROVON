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
if ( V_32 -> V_33 ) {
if ( F_22 ( V_32 -> V_33 -> V_5 . V_4 ) )
V_2 = F_23 ( V_32 ) ;
F_24 ( & V_32 -> V_33 -> V_5 ) ;
}
if ( V_2 )
F_25 ( & V_2 -> V_20 , F_8 ) ;
F_26 ( & V_32 -> V_34 ) ;
F_10 ( V_32 ) ;
}
static struct V_1 *
F_27 ( struct V_3 * V_4 , struct V_31 * V_32 )
{
struct V_1 * V_2 ;
int V_23 ;
V_2 = F_28 ( sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return F_29 ( - V_36 ) ;
V_23 = F_30 ( V_4 , V_2 ) ;
if ( V_23 ) {
F_10 ( V_2 ) ;
return F_29 ( V_23 ) ;
}
V_2 -> V_32 = V_32 ;
return V_2 ;
}
static struct V_31 *
F_31 ( struct V_3 * V_4 ,
struct V_37 * V_38 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_31 * V_32 ;
int V_23 ;
V_32 = F_28 ( sizeof( * V_32 ) , V_35 ) ;
if ( V_32 == NULL )
return F_29 ( - V_36 ) ;
F_32 ( & V_32 -> V_20 ) ;
F_33 ( & V_32 -> V_34 , & V_7 -> V_39 ) ;
if ( V_7 -> V_40 ) {
V_32 -> V_33 = F_34 ( V_4 , V_7 -> V_40 ) ;
if ( V_32 -> V_33 == NULL ) {
V_23 = - V_36 ;
goto V_41;
}
if ( F_14 ( V_4 ) -> V_25 >= 7 && ! F_35 ( V_4 ) ) {
V_23 = F_36 ( V_32 -> V_33 ,
V_42 ) ;
if ( F_4 ( V_23 ) )
goto V_41;
}
}
if ( V_38 != NULL ) {
V_23 = F_37 ( & V_38 -> V_43 , V_32 ,
V_44 , 0 , V_35 ) ;
if ( V_23 < 0 )
goto V_41;
} else
V_23 = V_44 ;
V_32 -> V_38 = V_38 ;
V_32 -> V_45 = V_23 ;
V_32 -> V_46 = ( 1 << F_38 ( V_4 ) ) - 1 ;
return V_32 ;
V_41:
F_39 ( V_32 ) ;
return F_29 ( V_23 ) ;
}
static struct V_31 *
F_40 ( struct V_3 * V_4 ,
struct V_37 * V_38 ,
bool V_47 )
{
const bool V_48 = V_38 == NULL ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_31 * V_32 ;
int V_23 = 0 ;
F_41 ( ! F_42 ( & V_4 -> V_49 ) ) ;
V_32 = F_31 ( V_4 , V_38 ) ;
if ( F_43 ( V_32 ) )
return V_32 ;
if ( V_48 && V_32 -> V_33 ) {
V_23 = F_44 ( V_32 -> V_33 ,
F_11 ( V_4 ) , 0 ) ;
if ( V_23 ) {
F_45 ( L_1 , V_23 ) ;
goto V_50;
}
}
if ( V_47 ) {
struct V_1 * V_2 = F_27 ( V_4 , V_32 ) ;
if ( F_46 ( V_2 ) ) {
F_45 ( L_2 ,
F_47 ( V_2 ) ) ;
V_23 = F_47 ( V_2 ) ;
goto V_51;
} else
V_32 -> V_10 = & V_2 -> V_5 ;
if ( V_48 ) {
if ( F_4 ( V_7 -> V_11 . V_12 ) ) {
V_23 = - V_52 ;
goto V_51;
}
V_7 -> V_11 . V_12 = V_2 ;
}
} else if ( F_22 ( V_4 ) ) {
V_32 -> V_10 = & V_7 -> V_11 . V_12 -> V_5 ;
F_48 ( & V_7 -> V_11 . V_12 -> V_20 ) ;
} else
V_32 -> V_10 = & V_7 -> V_53 . V_5 ;
return V_32 ;
V_51:
if ( V_48 && V_32 -> V_33 )
F_49 ( V_32 -> V_33 ) ;
V_50:
F_39 ( V_32 ) ;
return F_29 ( V_23 ) ;
}
void F_50 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
struct V_56 * V_57 = & V_7 -> V_57 [ V_54 ] ;
struct V_31 * V_58 = V_57 -> V_59 ;
if ( V_57 -> V_60 == V_58 )
continue;
if ( ! V_57 -> V_60 )
continue;
if ( V_58 -> V_33 && V_54 == V_61 ) {
F_4 ( F_44 ( V_58 -> V_33 ,
F_11 ( V_4 ) , 0 ) ) ;
V_58 -> V_33 -> V_5 . V_62 = 0 ;
V_58 -> V_33 -> V_63 = 0 ;
}
F_39 ( V_57 -> V_60 ) ;
F_51 ( V_58 ) ;
V_57 -> V_60 = V_58 ;
}
}
int F_52 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_31 * V_32 ;
int V_54 ;
if ( F_4 ( V_7 -> V_57 [ V_61 ] . V_59 ) )
return 0 ;
if ( F_53 ( V_4 ) ) {
V_7 -> V_40 = F_54 ( F_13 ( V_4 ) , 4096 ) ;
if ( V_7 -> V_40 > ( 1 << 20 ) ) {
F_45 ( L_3 ,
V_7 -> V_40 ) ;
V_7 -> V_40 = 0 ;
}
}
V_32 = F_40 ( V_4 , NULL , F_22 ( V_4 ) ) ;
if ( F_43 ( V_32 ) ) {
F_55 ( L_4 ,
F_47 ( V_32 ) ) ;
return F_47 ( V_32 ) ;
}
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ )
V_7 -> V_57 [ V_54 ] . V_59 = V_32 ;
F_45 ( L_5 , V_7 -> V_40 ? L_6 : L_7 ) ;
return 0 ;
}
void F_56 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_31 * V_58 = V_7 -> V_57 [ V_61 ] . V_59 ;
int V_54 ;
if ( V_58 -> V_33 ) {
F_57 ( V_4 ) ;
F_4 ( ! V_7 -> V_57 [ V_61 ] . V_60 ) ;
if ( V_7 -> V_57 [ V_61 ] . V_60 == V_58 ) {
F_4 ( V_58 -> V_33 -> V_63 ) ;
F_49 ( V_58 -> V_33 ) ;
F_39 ( V_58 ) ;
V_7 -> V_57 [ V_61 ] . V_60 = NULL ;
}
F_49 ( V_58 -> V_33 ) ;
}
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
struct V_56 * V_57 = & V_7 -> V_57 [ V_54 ] ;
if ( V_57 -> V_60 )
F_39 ( V_57 -> V_60 ) ;
V_57 -> V_59 = NULL ;
V_57 -> V_60 = NULL ;
}
F_39 ( V_58 ) ;
}
int F_58 ( struct V_6 * V_7 )
{
struct V_56 * V_57 ;
int V_23 , V_54 ;
if ( V_7 -> V_11 . V_12 ) {
struct V_1 * V_2 = V_7 -> V_11 . V_12 ;
V_2 -> V_64 ( V_2 ) ;
}
if ( F_59 ( & V_7 -> V_65 ) )
return 0 ;
F_41 ( ! V_7 -> V_57 [ V_61 ] . V_59 ) ;
F_60 (ring, dev_priv, i) {
V_23 = F_61 ( V_57 , V_57 -> V_59 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static int F_62 ( int V_45 , void * V_66 , void * V_67 )
{
struct V_31 * V_32 = V_66 ;
F_39 ( V_32 ) ;
return 0 ;
}
int F_63 ( struct V_3 * V_4 , struct V_68 * V_69 )
{
struct V_37 * V_38 = V_69 -> V_70 ;
struct V_31 * V_32 ;
F_64 ( & V_38 -> V_43 ) ;
F_65 ( & V_4 -> V_49 ) ;
V_32 = F_40 ( V_4 , V_38 , F_66 ( V_4 ) ) ;
F_67 ( & V_4 -> V_49 ) ;
if ( F_43 ( V_32 ) ) {
F_68 ( & V_38 -> V_43 ) ;
return F_47 ( V_32 ) ;
}
return 0 ;
}
void F_69 ( struct V_3 * V_4 , struct V_68 * V_69 )
{
struct V_37 * V_38 = V_69 -> V_70 ;
F_70 ( & V_38 -> V_43 , F_62 , NULL ) ;
F_68 ( & V_38 -> V_43 ) ;
}
struct V_31 *
F_71 ( struct V_37 * V_38 , T_2 V_45 )
{
struct V_31 * V_32 ;
V_32 = (struct V_31 * ) F_72 ( & V_38 -> V_43 , V_45 ) ;
if ( ! V_32 )
return F_29 ( - V_71 ) ;
return V_32 ;
}
static inline int
F_73 ( struct V_56 * V_57 ,
struct V_31 * V_72 ,
T_2 V_73 )
{
int V_23 ;
if ( F_12 ( V_57 -> V_4 ) ) {
V_23 = V_57 -> V_74 ( V_57 , V_75 , 0 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_74 ( V_57 , 6 ) ;
if ( V_23 )
return V_23 ;
if ( F_14 ( V_57 -> V_4 ) -> V_25 >= 7 )
F_75 ( V_57 , V_76 | V_77 ) ;
else
F_75 ( V_57 , V_78 ) ;
F_75 ( V_57 , V_78 ) ;
F_75 ( V_57 , V_79 ) ;
F_75 ( V_57 , F_76 ( V_72 -> V_33 ) |
V_80 |
V_81 |
V_82 |
V_73 ) ;
F_75 ( V_57 , V_78 ) ;
if ( F_14 ( V_57 -> V_4 ) -> V_25 >= 7 )
F_75 ( V_57 , V_76 | V_83 ) ;
else
F_75 ( V_57 , V_78 ) ;
F_77 ( V_57 ) ;
return V_23 ;
}
static int F_78 ( struct V_56 * V_57 ,
struct V_31 * V_84 )
{
struct V_6 * V_7 = V_57 -> V_4 -> V_8 ;
struct V_31 * V_85 = V_57 -> V_60 ;
struct V_1 * V_2 = F_23 ( V_84 ) ;
T_2 V_73 = 0 ;
bool V_86 = false ;
int V_23 , V_54 ;
if ( V_85 != NULL && V_57 == & V_7 -> V_57 [ V_61 ] ) {
F_41 ( V_85 -> V_33 == NULL ) ;
F_41 ( ! F_79 ( V_85 -> V_33 ) ) ;
}
if ( V_85 == V_84 && V_85 -> V_87 == V_57 && ! V_84 -> V_46 )
return 0 ;
if ( V_57 == & V_7 -> V_57 [ V_61 ] ) {
V_23 = F_44 ( V_84 -> V_33 ,
F_11 ( V_57 -> V_4 ) , 0 ) ;
if ( V_23 )
return V_23 ;
}
V_85 = V_57 -> V_60 ;
if ( F_66 ( V_57 -> V_4 ) ) {
V_23 = V_2 -> V_88 ( V_2 , V_57 , false ) ;
if ( V_23 )
goto V_89;
}
if ( V_57 != & V_7 -> V_57 [ V_61 ] ) {
if ( V_85 )
F_39 ( V_85 ) ;
goto V_90;
}
V_23 = F_80 ( V_84 -> V_33 , false ) ;
if ( V_23 )
goto V_89;
if ( ! V_84 -> V_33 -> V_91 ) {
struct V_16 * V_17 = F_81 ( V_84 -> V_33 ,
& V_7 -> V_53 . V_5 ) ;
V_17 -> V_92 ( V_17 , V_84 -> V_33 -> V_93 , V_94 ) ;
}
if ( ! V_84 -> V_95 || F_82 ( V_84 ) )
V_73 |= V_96 ;
V_23 = F_73 ( V_57 , V_84 , V_73 ) ;
if ( V_23 )
goto V_89;
for ( V_54 = 0 ; V_54 < V_97 ; V_54 ++ ) {
if ( ! ( V_84 -> V_46 & ( 1 << V_54 ) ) )
continue;
V_23 = F_83 ( V_57 , V_54 ) ;
if ( V_23 )
F_45 ( L_8 ) ;
else
V_84 -> V_46 &= ~ ( 1 << V_54 ) ;
}
if ( V_85 != NULL ) {
V_85 -> V_33 -> V_5 . V_98 = V_99 ;
F_84 ( F_85 ( V_85 -> V_33 ) , V_57 ) ;
V_85 -> V_33 -> V_100 = 1 ;
F_41 ( V_85 -> V_33 -> V_57 != V_57 ) ;
F_49 ( V_85 -> V_33 ) ;
F_39 ( V_85 ) ;
}
V_86 = ! V_84 -> V_95 && V_85 == NULL ;
V_84 -> V_95 = true ;
V_90:
F_51 ( V_84 ) ;
V_57 -> V_60 = V_84 ;
V_84 -> V_87 = V_57 ;
if ( V_86 ) {
V_23 = F_86 ( V_57 ) ;
if ( V_23 )
F_55 ( L_9 , V_23 ) ;
}
return 0 ;
V_89:
if ( V_57 -> V_45 == V_61 )
F_49 ( V_84 -> V_33 ) ;
return V_23 ;
}
int F_61 ( struct V_56 * V_57 ,
struct V_31 * V_84 )
{
struct V_6 * V_7 = V_57 -> V_4 -> V_8 ;
F_4 ( ! F_42 ( & V_7 -> V_4 -> V_49 ) ) ;
if ( V_84 -> V_33 == NULL ) {
if ( V_84 != V_57 -> V_60 ) {
F_51 ( V_84 ) ;
if ( V_57 -> V_60 )
F_39 ( V_57 -> V_60 ) ;
V_57 -> V_60 = V_84 ;
}
return 0 ;
}
return F_78 ( V_57 , V_84 ) ;
}
static bool F_87 ( struct V_3 * V_4 )
{
return F_88 ( V_4 ) -> V_40 ;
}
int F_89 ( struct V_3 * V_4 , void * V_67 ,
struct V_68 * V_69 )
{
struct V_101 * args = V_67 ;
struct V_37 * V_38 = V_69 -> V_70 ;
struct V_31 * V_32 ;
int V_23 ;
if ( ! F_87 ( V_4 ) )
return - V_102 ;
V_23 = F_90 ( V_4 ) ;
if ( V_23 )
return V_23 ;
V_32 = F_40 ( V_4 , V_38 , F_66 ( V_4 ) ) ;
F_67 ( & V_4 -> V_49 ) ;
if ( F_43 ( V_32 ) )
return F_47 ( V_32 ) ;
args -> V_103 = V_32 -> V_45 ;
F_45 ( L_10 , args -> V_103 ) ;
return 0 ;
}
int F_91 ( struct V_3 * V_4 , void * V_67 ,
struct V_68 * V_69 )
{
struct V_104 * args = V_67 ;
struct V_37 * V_38 = V_69 -> V_70 ;
struct V_31 * V_32 ;
int V_23 ;
if ( args -> V_103 == V_44 )
return - V_71 ;
V_23 = F_90 ( V_4 ) ;
if ( V_23 )
return V_23 ;
V_32 = F_71 ( V_38 , args -> V_103 ) ;
if ( F_43 ( V_32 ) ) {
F_67 ( & V_4 -> V_49 ) ;
return F_47 ( V_32 ) ;
}
F_92 ( & V_32 -> V_38 -> V_43 , V_32 -> V_45 ) ;
F_39 ( V_32 ) ;
F_67 ( & V_4 -> V_49 ) ;
F_45 ( L_11 , args -> V_103 ) ;
return 0 ;
}
