void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( V_2 -> V_3 & V_4 && V_2 -> V_5 . V_6 ) {
F_2 ( V_2 -> V_5 . V_6 , V_7 ) ;
V_2 -> V_5 . V_6 = NULL ;
}
V_2 -> V_5 . V_8 = NULL ;
if ( V_2 -> V_3 & V_9 ) {
F_3 ( V_10 , V_2 ) ;
} else {
F_4 ( & V_11 , V_3 ) ;
F_5 ( & V_2 -> V_12 , & V_13 ) ;
F_6 ( & V_11 , V_3 ) ;
}
}
struct V_1 * F_7 ( struct V_14 * V_14 , T_1 V_15 )
{
struct V_1 * V_2 = NULL ;
struct V_16 * V_17 = V_14 -> V_18 ;
unsigned long V_3 ;
if ( V_17 == NULL )
return F_8 ( - V_19 ) ;
F_4 ( & V_11 , V_3 ) ;
V_2 = F_9 ( & V_13 ,
struct V_1 , V_12 ) ;
if ( V_2 )
F_10 ( & V_2 -> V_12 ) ;
F_6 ( & V_11 , V_3 ) ;
if ( ! V_2 ) {
V_2 = F_11 ( V_10 , V_15 ) ;
if ( ! V_2 )
return F_8 ( - V_20 ) ;
V_2 -> V_3 |= V_9 ;
} else {
V_2 -> V_3 &= ~ V_9 ;
}
V_2 -> V_3 &= ~ V_4 ;
return V_2 ;
}
static void F_12 ( struct V_21 * V_22 , int V_23 )
{
struct V_24 * V_25 = V_22 -> V_26 ;
if ( V_23 == - V_27 )
return;
V_25 -> V_23 = V_23 ;
F_13 ( & V_25 -> V_28 ) ;
}
static int F_14 ( struct V_14 * V_14 ,
T_2 V_29 , T_3 V_30 ,
struct V_31 * V_32 , struct V_31 * V_33 ,
T_1 V_15 )
{
struct {
T_4 V_30 ;
T_5 V_34 [ V_35 - sizeof( T_4 ) ] ;
} V_36 ;
struct V_37 * V_22 = NULL ;
F_15 ( V_25 ) ;
struct V_38 V_39 , V_40 ;
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_41 * V_42 = V_17 -> V_43 ;
int V_23 = 0 ;
V_22 = F_16 ( V_42 , V_15 ) ;
if ( ! V_22 ) {
F_17 ( V_44
L_1 ,
V_45 ) ;
return - V_20 ;
}
F_18 (
V_22 , V_46 | V_47 ,
F_12 , & V_25 ) ;
F_19 ( sizeof( V_36 ) != V_35 ) ;
V_36 . V_30 = F_20 ( V_30 ) ;
memset ( V_36 . V_34 , 0 , sizeof( V_36 . V_34 ) ) ;
F_21 ( & V_39 , 1 ) ;
F_22 ( & V_39 , V_33 , V_48 , 0 ) ;
F_21 ( & V_40 , 1 ) ;
F_22 ( & V_40 , V_32 , V_48 , 0 ) ;
F_23 ( V_22 , & V_40 , & V_39 , V_48 , & V_36 ) ;
if ( V_29 == V_49 )
V_23 = F_24 ( V_22 ) ;
else
V_23 = F_25 ( V_22 ) ;
if ( V_23 == - V_27 || V_23 == - V_50 ) {
F_26 ( V_22 -> V_51 . V_26 != & V_25 ) ;
F_27 ( & V_25 . V_28 ) ;
V_23 = V_25 . V_23 ;
}
F_28 ( V_22 ) ;
if ( V_23 ) {
F_17 ( V_44
L_2 ,
V_45 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static struct V_31 * F_29 ( struct V_1 * V_2 , T_1 V_15 )
{
V_2 -> V_5 . V_6 = F_30 ( V_7 , V_15 ) ;
if ( V_2 -> V_5 . V_6 == NULL )
return F_8 ( - V_20 ) ;
V_2 -> V_3 |= V_4 ;
return V_2 -> V_5 . V_6 ;
}
struct V_31 * F_31 ( struct V_14 * V_14 ,
struct V_31 * V_52 , T_1 V_15 )
{
struct V_1 * V_2 ;
struct V_31 * V_53 = NULL ;
int V_54 ;
F_26 ( ! F_32 ( V_52 ) ) ;
V_2 = F_7 ( V_14 , V_15 ) ;
if ( F_33 ( V_2 ) )
return (struct V_31 * ) V_2 ;
V_53 = F_29 ( V_2 , V_15 ) ;
if ( F_33 ( V_53 ) )
goto V_55;
V_2 -> V_5 . V_8 = V_52 ;
V_54 = F_14 ( V_14 , V_56 , V_52 -> V_30 ,
V_52 , V_53 ,
V_15 ) ;
if ( V_54 ) {
V_53 = F_8 ( V_54 ) ;
goto V_55;
}
F_34 ( V_53 ) ;
F_35 ( V_53 , ( unsigned long ) V_2 ) ;
F_36 ( V_53 ) ;
return V_53 ;
V_55:
F_1 ( V_2 ) ;
return V_53 ;
}
int F_37 ( struct V_31 * V_31 )
{
F_26 ( ! F_32 ( V_31 ) ) ;
return F_14 ( V_31 -> V_57 -> V_58 ,
V_49 , V_31 -> V_30 , V_31 , V_31 , V_59 ) ;
}
int F_38 ( struct V_14 * V_14 , T_3 V_60 ,
T_6 V_61 , unsigned int V_62 )
{
struct V_1 * V_2 ;
struct V_31 * V_53 = NULL ;
struct V_63 * V_63 ;
int V_64 , V_54 = 0 ;
F_26 ( V_14 -> V_65 -> V_66 != V_48 ) ;
V_2 = F_7 ( V_14 , V_59 ) ;
if ( F_33 ( V_2 ) )
return F_39 ( V_2 ) ;
V_53 = F_29 ( V_2 , V_67 ) ;
if ( F_33 ( V_53 ) ) {
V_54 = F_39 ( V_53 ) ;
goto V_55;
}
while ( V_62 -- ) {
V_54 = F_14 ( V_14 , V_56 , V_60 ,
F_40 ( 0 ) , V_53 ,
V_59 ) ;
if ( V_54 )
goto V_55;
V_63 = F_41 ( V_67 , 1 ) ;
if ( ! V_63 ) {
V_54 = - V_20 ;
goto V_55;
}
V_63 -> V_68 = V_14 -> V_65 -> V_69 ;
V_63 -> V_70 . V_71 =
V_61 << ( V_14 -> V_65 -> V_72 - 9 ) ;
F_42 ( V_63 , V_73 , 0 ) ;
V_64 = F_43 ( V_63 , V_53 ,
V_14 -> V_65 -> V_66 , 0 ) ;
if ( V_64 != V_14 -> V_65 -> V_66 ) {
F_44 ( 1 ) ;
F_45 ( V_63 ) ;
V_54 = - V_74 ;
goto V_55;
}
V_54 = F_46 ( V_63 ) ;
if ( ( V_54 == 0 ) && V_63 -> V_75 )
V_54 = - V_74 ;
F_45 ( V_63 ) ;
if ( V_54 )
goto V_55;
V_60 ++ ;
V_61 ++ ;
}
V_54 = 0 ;
V_55:
F_1 ( V_2 ) ;
return V_54 ;
}
static int F_47 ( struct V_76 * V_76 , unsigned int V_3 )
{
struct V_76 * V_77 ;
struct V_16 * V_17 ;
int V_78 , V_79 ;
if ( V_3 & V_80 )
return - V_81 ;
V_77 = F_48 ( V_76 ) ;
if ( ! F_49 ( V_77 ) -> V_65 -> V_82 -> V_83 ( F_49 ( V_77 ) ) ) {
F_50 ( V_77 ) ;
return 0 ;
}
V_17 = F_49 ( V_77 ) -> V_18 ;
if ( V_17 && V_17 -> V_84 &&
( V_17 -> V_84 -> V_3 & ( ( 1 << V_85 ) |
( 1 << V_86 ) |
( 1 << V_87 ) ) ) )
V_17 = NULL ;
F_51 ( & V_76 -> V_88 ) ;
V_79 = V_76 -> V_89 & V_90 ;
F_52 ( & V_76 -> V_88 ) ;
V_78 = ( V_17 != NULL ) ;
F_50 ( V_77 ) ;
if ( ( ! V_79 && F_53 ( V_76 ) ) ||
( ! V_79 && V_78 ) ||
( V_79 && ! V_78 ) )
return 0 ;
return 1 ;
}
static void F_54 ( struct V_91 * V_92 )
{
struct V_1 * V_2 =
F_55 ( V_92 , struct V_1 , V_93 . V_92 ) ;
struct V_63 * V_63 = V_2 -> V_93 . V_63 ;
struct V_94 * V_95 ;
int V_96 ;
F_56 (bv, bio, i) {
struct V_31 * V_31 = V_95 -> V_97 ;
int V_64 = F_37 ( V_31 ) ;
if ( V_64 ) {
F_57 ( 1 ) ;
F_58 ( V_31 ) ;
} else {
F_59 ( V_31 ) ;
}
F_60 ( V_31 ) ;
}
F_1 ( V_2 ) ;
F_45 ( V_63 ) ;
}
void F_61 ( struct V_1 * V_2 , struct V_63 * V_63 )
{
F_62 ( & V_2 -> V_93 . V_92 , F_54 ) ;
V_2 -> V_93 . V_63 = V_63 ;
F_63 ( V_98 , & V_2 -> V_93 . V_92 ) ;
}
void F_64 ( struct V_31 * * V_31 , bool V_99 )
{
struct V_1 * V_2 ;
struct V_31 * V_6 ;
if ( ( * V_31 ) -> V_57 )
return;
V_6 = * V_31 ;
V_2 = (struct V_1 * ) F_65 ( V_6 ) ;
* V_31 = V_2 -> V_5 . V_8 ;
if ( V_99 )
F_66 ( V_6 ) ;
}
void F_66 ( struct V_31 * V_31 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_65 ( V_31 ) ;
F_35 ( V_31 , ( unsigned long ) NULL ) ;
F_67 ( V_31 ) ;
F_60 ( V_31 ) ;
F_1 ( V_2 ) ;
}
static void F_68 ( void )
{
struct V_1 * V_100 , * V_101 ;
F_69 (pos, n, &fscrypt_free_ctxs, free_list)
F_3 ( V_10 , V_100 ) ;
F_70 ( & V_13 ) ;
F_71 ( V_7 ) ;
V_7 = NULL ;
}
int F_72 ( void )
{
int V_96 , V_23 = - V_20 ;
if ( V_7 )
return 0 ;
F_73 ( & V_102 ) ;
if ( V_7 )
goto V_103;
for ( V_96 = 0 ; V_96 < V_104 ; V_96 ++ ) {
struct V_1 * V_2 ;
V_2 = F_11 ( V_10 , V_59 ) ;
if ( ! V_2 )
goto V_105;
F_5 ( & V_2 -> V_12 , & V_13 ) ;
}
V_7 =
F_74 ( V_106 , 0 ) ;
if ( ! V_7 )
goto V_105;
V_103:
F_75 ( & V_102 ) ;
return 0 ;
V_105:
F_68 () ;
F_75 ( & V_102 ) ;
return V_23 ;
}
static int T_7 F_76 ( void )
{
V_98 = F_77 ( L_3 ,
V_107 , 0 ) ;
if ( ! V_98 )
goto V_105;
V_10 = F_78 ( V_1 , V_108 ) ;
if ( ! V_10 )
goto V_109;
V_110 = F_78 ( V_16 , V_108 ) ;
if ( ! V_110 )
goto V_111;
return 0 ;
V_111:
F_79 ( V_10 ) ;
V_109:
F_80 ( V_98 ) ;
V_105:
return - V_20 ;
}
static void T_8 F_81 ( void )
{
F_68 () ;
if ( V_98 )
F_80 ( V_98 ) ;
F_79 ( V_10 ) ;
F_79 ( V_110 ) ;
}
