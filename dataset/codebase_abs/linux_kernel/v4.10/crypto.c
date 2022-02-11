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
struct V_1 * F_7 ( const struct V_14 * V_14 , T_1 V_15 )
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
static int F_14 ( const struct V_14 * V_14 ,
T_2 V_29 , T_3 V_30 ,
struct V_31 * V_32 , struct V_31 * V_33 ,
unsigned int V_34 , unsigned int V_35 ,
T_1 V_15 )
{
struct {
T_4 V_36 ;
T_5 V_37 [ V_38 - sizeof( T_4 ) ] ;
} V_39 ;
struct V_40 * V_22 = NULL ;
F_15 ( V_25 ) ;
struct V_41 V_42 , V_43 ;
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_44 * V_45 = V_17 -> V_46 ;
int V_23 = 0 ;
F_16 ( V_34 == 0 ) ;
V_22 = F_17 ( V_45 , V_15 ) ;
if ( ! V_22 ) {
F_18 ( V_47
L_1 ,
V_48 ) ;
return - V_20 ;
}
F_19 (
V_22 , V_49 | V_50 ,
F_12 , & V_25 ) ;
F_20 ( sizeof( V_39 ) != V_38 ) ;
V_39 . V_36 = F_21 ( V_30 ) ;
memset ( V_39 . V_37 , 0 , sizeof( V_39 . V_37 ) ) ;
F_22 ( & V_42 , 1 ) ;
F_23 ( & V_42 , V_33 , V_34 , V_35 ) ;
F_22 ( & V_43 , 1 ) ;
F_23 ( & V_43 , V_32 , V_34 , V_35 ) ;
F_24 ( V_22 , & V_43 , & V_42 , V_34 , & V_39 ) ;
if ( V_29 == V_51 )
V_23 = F_25 ( V_22 ) ;
else
V_23 = F_26 ( V_22 ) ;
if ( V_23 == - V_27 || V_23 == - V_52 ) {
F_16 ( V_22 -> V_53 . V_26 != & V_25 ) ;
F_27 ( & V_25 . V_28 ) ;
V_23 = V_25 . V_23 ;
}
F_28 ( V_22 ) ;
if ( V_23 ) {
F_18 ( V_47
L_2 ,
V_48 , V_23 ) ;
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
struct V_31 * F_31 ( const struct V_14 * V_14 ,
struct V_31 * V_31 ,
unsigned int V_34 ,
unsigned int V_35 ,
T_3 V_30 , T_1 V_15 )
{
struct V_1 * V_2 ;
struct V_31 * V_54 = V_31 ;
int V_55 ;
F_16 ( V_34 % V_56 != 0 ) ;
if ( V_14 -> V_57 -> V_58 -> V_3 & V_59 ) {
V_55 = F_14 ( V_14 , V_60 , V_30 ,
V_31 , V_54 ,
V_34 , V_35 , V_15 ) ;
if ( V_55 )
return F_8 ( V_55 ) ;
return V_54 ;
}
F_16 ( ! F_32 ( V_31 ) ) ;
V_2 = F_7 ( V_14 , V_15 ) ;
if ( F_33 ( V_2 ) )
return (struct V_31 * ) V_2 ;
V_54 = F_29 ( V_2 , V_15 ) ;
if ( F_33 ( V_54 ) )
goto V_61;
V_2 -> V_5 . V_8 = V_31 ;
V_55 = F_14 ( V_14 , V_60 , V_30 ,
V_31 , V_54 ,
V_34 , V_35 , V_15 ) ;
if ( V_55 ) {
V_54 = F_8 ( V_55 ) ;
goto V_61;
}
F_34 ( V_54 ) ;
F_35 ( V_54 , ( unsigned long ) V_2 ) ;
F_36 ( V_54 ) ;
return V_54 ;
V_61:
F_1 ( V_2 ) ;
return V_54 ;
}
int F_37 ( const struct V_14 * V_14 , struct V_31 * V_31 ,
unsigned int V_34 , unsigned int V_35 , T_3 V_30 )
{
if ( ! ( V_14 -> V_57 -> V_58 -> V_3 & V_59 ) )
F_16 ( ! F_32 ( V_31 ) ) ;
return F_14 ( V_14 , V_51 , V_30 , V_31 , V_31 , V_34 ,
V_35 , V_62 ) ;
}
int F_38 ( const struct V_14 * V_14 , T_6 V_63 ,
T_7 V_64 , unsigned int V_34 )
{
struct V_1 * V_2 ;
struct V_31 * V_54 = NULL ;
struct V_65 * V_65 ;
int V_66 , V_55 = 0 ;
F_16 ( V_14 -> V_57 -> V_67 != V_68 ) ;
V_2 = F_7 ( V_14 , V_62 ) ;
if ( F_33 ( V_2 ) )
return F_39 ( V_2 ) ;
V_54 = F_29 ( V_2 , V_69 ) ;
if ( F_33 ( V_54 ) ) {
V_55 = F_39 ( V_54 ) ;
goto V_61;
}
while ( V_34 -- ) {
V_55 = F_14 ( V_14 , V_60 , V_63 ,
F_40 ( 0 ) , V_54 ,
V_68 , 0 , V_62 ) ;
if ( V_55 )
goto V_61;
V_65 = F_41 ( V_69 , 1 ) ;
if ( ! V_65 ) {
V_55 = - V_20 ;
goto V_61;
}
V_65 -> V_70 = V_14 -> V_57 -> V_71 ;
V_65 -> V_72 . V_73 =
V_64 << ( V_14 -> V_57 -> V_74 - 9 ) ;
F_42 ( V_65 , V_75 , 0 ) ;
V_66 = F_43 ( V_65 , V_54 ,
V_14 -> V_57 -> V_67 , 0 ) ;
if ( V_66 != V_14 -> V_57 -> V_67 ) {
F_44 ( 1 ) ;
F_45 ( V_65 ) ;
V_55 = - V_76 ;
goto V_61;
}
V_55 = F_46 ( V_65 ) ;
if ( ( V_55 == 0 ) && V_65 -> V_77 )
V_55 = - V_76 ;
F_45 ( V_65 ) ;
if ( V_55 )
goto V_61;
V_63 ++ ;
V_64 ++ ;
}
V_55 = 0 ;
V_61:
F_1 ( V_2 ) ;
return V_55 ;
}
static int F_47 ( struct V_78 * V_78 , unsigned int V_3 )
{
struct V_78 * V_79 ;
struct V_16 * V_17 ;
int V_80 , V_81 ;
if ( V_3 & V_82 )
return - V_83 ;
V_79 = F_48 ( V_78 ) ;
if ( ! F_49 ( V_79 ) -> V_57 -> V_58 -> V_84 ( F_49 ( V_79 ) ) ) {
F_50 ( V_79 ) ;
return 0 ;
}
V_17 = F_49 ( V_79 ) -> V_18 ;
if ( V_17 && V_17 -> V_85 &&
( V_17 -> V_85 -> V_3 & ( ( 1 << V_86 ) |
( 1 << V_87 ) |
( 1 << V_88 ) ) ) )
V_17 = NULL ;
F_51 ( & V_78 -> V_89 ) ;
V_81 = V_78 -> V_90 & V_91 ;
F_52 ( & V_78 -> V_89 ) ;
V_80 = ( V_17 != NULL ) ;
F_50 ( V_79 ) ;
if ( ( ! V_81 && F_53 ( V_78 ) ) ||
( ! V_81 && V_80 ) ||
( V_81 && ! V_80 ) )
return 0 ;
return 1 ;
}
static void F_54 ( struct V_92 * V_93 )
{
struct V_1 * V_2 =
F_55 ( V_93 , struct V_1 , V_94 . V_93 ) ;
struct V_65 * V_65 = V_2 -> V_94 . V_65 ;
struct V_95 * V_96 ;
int V_97 ;
F_56 (bv, bio, i) {
struct V_31 * V_31 = V_96 -> V_98 ;
int V_66 = F_37 ( V_31 -> V_99 -> V_100 , V_31 ,
V_68 , 0 , V_31 -> V_36 ) ;
if ( V_66 ) {
F_57 ( 1 ) ;
F_58 ( V_31 ) ;
} else {
F_59 ( V_31 ) ;
}
F_60 ( V_31 ) ;
}
F_1 ( V_2 ) ;
F_45 ( V_65 ) ;
}
void F_61 ( struct V_1 * V_2 , struct V_65 * V_65 )
{
F_62 ( & V_2 -> V_94 . V_93 , F_54 ) ;
V_2 -> V_94 . V_65 = V_65 ;
F_63 ( V_101 , & V_2 -> V_94 . V_93 ) ;
}
void F_64 ( struct V_31 * * V_31 , bool V_102 )
{
struct V_1 * V_2 ;
struct V_31 * V_6 ;
if ( ( * V_31 ) -> V_99 )
return;
V_6 = * V_31 ;
V_2 = (struct V_1 * ) F_65 ( V_6 ) ;
* V_31 = V_2 -> V_5 . V_8 ;
if ( V_102 )
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
struct V_1 * V_103 , * V_104 ;
F_69 (pos, n, &fscrypt_free_ctxs, free_list)
F_3 ( V_10 , V_103 ) ;
F_70 ( & V_13 ) ;
F_71 ( V_7 ) ;
V_7 = NULL ;
}
int F_72 ( unsigned int V_105 )
{
int V_97 , V_23 = - V_20 ;
if ( V_105 & V_59 || V_7 )
return 0 ;
F_73 ( & V_106 ) ;
if ( V_7 )
goto V_107;
for ( V_97 = 0 ; V_97 < V_108 ; V_97 ++ ) {
struct V_1 * V_2 ;
V_2 = F_11 ( V_10 , V_62 ) ;
if ( ! V_2 )
goto V_109;
F_5 ( & V_2 -> V_12 , & V_13 ) ;
}
V_7 =
F_74 ( V_110 , 0 ) ;
if ( ! V_7 )
goto V_109;
V_107:
F_75 ( & V_106 ) ;
return 0 ;
V_109:
F_68 () ;
F_75 ( & V_106 ) ;
return V_23 ;
}
static int T_8 F_76 ( void )
{
V_101 = F_77 ( L_3 ,
V_111 , 0 ) ;
if ( ! V_101 )
goto V_109;
V_10 = F_78 ( V_1 , V_112 ) ;
if ( ! V_10 )
goto V_113;
V_114 = F_78 ( V_16 , V_112 ) ;
if ( ! V_114 )
goto V_115;
return 0 ;
V_115:
F_79 ( V_10 ) ;
V_113:
F_80 ( V_101 ) ;
V_109:
return - V_20 ;
}
static void T_9 F_81 ( void )
{
F_68 () ;
if ( V_101 )
F_80 ( V_101 ) ;
F_79 ( V_10 ) ;
F_79 ( V_114 ) ;
}
