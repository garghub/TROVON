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
T_4 V_34 [ V_35 ] ;
struct V_36 * V_22 = NULL ;
F_15 ( V_25 ) ;
struct V_37 V_38 , V_39 ;
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_40 * V_41 = V_17 -> V_42 ;
int V_23 = 0 ;
V_22 = F_16 ( V_41 , V_15 ) ;
if ( ! V_22 ) {
F_17 ( V_43
L_1 ,
V_44 ) ;
return - V_20 ;
}
F_18 (
V_22 , V_45 | V_46 ,
F_12 , & V_25 ) ;
F_19 ( V_35 < sizeof( V_30 ) ) ;
memcpy ( V_34 , & V_30 , sizeof( V_30 ) ) ;
memset ( & V_34 [ sizeof( V_30 ) ] , 0 ,
V_35 - sizeof( V_30 ) ) ;
F_20 ( & V_38 , 1 ) ;
F_21 ( & V_38 , V_33 , V_47 , 0 ) ;
F_20 ( & V_39 , 1 ) ;
F_21 ( & V_39 , V_32 , V_47 , 0 ) ;
F_22 ( V_22 , & V_39 , & V_38 , V_47 ,
V_34 ) ;
if ( V_29 == V_48 )
V_23 = F_23 ( V_22 ) ;
else
V_23 = F_24 ( V_22 ) ;
if ( V_23 == - V_27 || V_23 == - V_49 ) {
F_25 ( V_22 -> V_50 . V_26 != & V_25 ) ;
F_26 ( & V_25 . V_28 ) ;
V_23 = V_25 . V_23 ;
}
F_27 ( V_22 ) ;
if ( V_23 ) {
F_17 ( V_43
L_2 ,
V_44 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static struct V_31 * F_28 ( struct V_1 * V_2 , T_1 V_15 )
{
V_2 -> V_5 . V_6 = F_29 ( V_7 , V_15 ) ;
if ( V_2 -> V_5 . V_6 == NULL )
return F_8 ( - V_20 ) ;
V_2 -> V_3 |= V_4 ;
return V_2 -> V_5 . V_6 ;
}
struct V_31 * F_30 ( struct V_14 * V_14 ,
struct V_31 * V_51 , T_1 V_15 )
{
struct V_1 * V_2 ;
struct V_31 * V_52 = NULL ;
int V_53 ;
F_25 ( ! F_31 ( V_51 ) ) ;
V_2 = F_7 ( V_14 , V_15 ) ;
if ( F_32 ( V_2 ) )
return (struct V_31 * ) V_2 ;
V_52 = F_28 ( V_2 , V_15 ) ;
if ( F_32 ( V_52 ) )
goto V_54;
V_2 -> V_5 . V_8 = V_51 ;
V_53 = F_14 ( V_14 , V_55 , V_51 -> V_30 ,
V_51 , V_52 ,
V_15 ) ;
if ( V_53 ) {
V_52 = F_8 ( V_53 ) ;
goto V_54;
}
F_33 ( V_52 ) ;
F_34 ( V_52 , ( unsigned long ) V_2 ) ;
F_35 ( V_52 ) ;
return V_52 ;
V_54:
F_1 ( V_2 ) ;
return V_52 ;
}
int F_36 ( struct V_31 * V_31 )
{
F_25 ( ! F_31 ( V_31 ) ) ;
return F_14 ( V_31 -> V_56 -> V_57 ,
V_48 , V_31 -> V_30 , V_31 , V_31 , V_58 ) ;
}
int F_37 ( struct V_14 * V_14 , T_3 V_59 ,
T_5 V_60 , unsigned int V_61 )
{
struct V_1 * V_2 ;
struct V_31 * V_52 = NULL ;
struct V_62 * V_62 ;
int V_63 , V_53 = 0 ;
F_25 ( V_14 -> V_64 -> V_65 != V_47 ) ;
V_2 = F_7 ( V_14 , V_58 ) ;
if ( F_32 ( V_2 ) )
return F_38 ( V_2 ) ;
V_52 = F_28 ( V_2 , V_66 ) ;
if ( F_32 ( V_52 ) ) {
V_53 = F_38 ( V_52 ) ;
goto V_54;
}
while ( V_61 -- ) {
V_53 = F_14 ( V_14 , V_55 , V_59 ,
F_39 ( 0 ) , V_52 ,
V_58 ) ;
if ( V_53 )
goto V_54;
V_62 = F_40 ( V_66 , 1 ) ;
if ( ! V_62 ) {
V_53 = - V_20 ;
goto V_54;
}
V_62 -> V_67 = V_14 -> V_64 -> V_68 ;
V_62 -> V_69 . V_70 =
V_60 << ( V_14 -> V_64 -> V_71 - 9 ) ;
V_63 = F_41 ( V_62 , V_52 ,
V_14 -> V_64 -> V_65 , 0 ) ;
if ( V_63 != V_14 -> V_64 -> V_65 ) {
F_42 ( 1 ) ;
F_43 ( V_62 ) ;
V_53 = - V_72 ;
goto V_54;
}
V_53 = F_44 ( V_73 , V_62 ) ;
if ( ( V_53 == 0 ) && V_62 -> V_74 )
V_53 = - V_72 ;
F_43 ( V_62 ) ;
if ( V_53 )
goto V_54;
V_59 ++ ;
V_60 ++ ;
}
V_53 = 0 ;
V_54:
F_1 ( V_2 ) ;
return V_53 ;
}
static int F_45 ( struct V_75 * V_75 , unsigned int V_3 )
{
struct V_75 * V_76 ;
struct V_16 * V_17 ;
int V_77 , V_78 ;
if ( V_3 & V_79 )
return - V_80 ;
V_76 = F_46 ( V_75 ) ;
if ( ! F_47 ( V_76 ) -> V_64 -> V_81 -> V_82 ( F_47 ( V_76 ) ) ) {
F_48 ( V_76 ) ;
return 0 ;
}
V_17 = F_47 ( V_76 ) -> V_18 ;
if ( V_17 && V_17 -> V_83 &&
( V_17 -> V_83 -> V_3 & ( ( 1 << V_84 ) |
( 1 << V_85 ) |
( 1 << V_86 ) ) ) )
V_17 = NULL ;
F_49 ( & V_75 -> V_87 ) ;
V_78 = V_75 -> V_88 & V_89 ;
F_50 ( & V_75 -> V_87 ) ;
V_77 = ( V_17 != NULL ) ;
F_48 ( V_76 ) ;
if ( ( ! V_78 && F_51 ( V_75 ) ) ||
( ! V_78 && V_77 ) ||
( V_78 && ! V_77 ) )
return 0 ;
return 1 ;
}
static void F_52 ( struct V_90 * V_91 )
{
struct V_1 * V_2 =
F_53 ( V_91 , struct V_1 , V_92 . V_91 ) ;
struct V_62 * V_62 = V_2 -> V_92 . V_62 ;
struct V_93 * V_94 ;
int V_95 ;
F_54 (bv, bio, i) {
struct V_31 * V_31 = V_94 -> V_96 ;
int V_63 = F_36 ( V_31 ) ;
if ( V_63 ) {
F_55 ( 1 ) ;
F_56 ( V_31 ) ;
} else {
F_57 ( V_31 ) ;
}
F_58 ( V_31 ) ;
}
F_1 ( V_2 ) ;
F_43 ( V_62 ) ;
}
void F_59 ( struct V_1 * V_2 , struct V_62 * V_62 )
{
F_60 ( & V_2 -> V_92 . V_91 , F_52 ) ;
V_2 -> V_92 . V_62 = V_62 ;
F_61 ( V_97 , & V_2 -> V_92 . V_91 ) ;
}
void F_62 ( struct V_31 * * V_31 , bool V_98 )
{
struct V_1 * V_2 ;
struct V_31 * V_6 ;
if ( ( * V_31 ) -> V_56 )
return;
V_6 = * V_31 ;
V_2 = (struct V_1 * ) F_63 ( V_6 ) ;
* V_31 = V_2 -> V_5 . V_8 ;
if ( V_98 )
F_64 ( V_6 ) ;
}
void F_64 ( struct V_31 * V_31 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_63 ( V_31 ) ;
F_34 ( V_31 , ( unsigned long ) NULL ) ;
F_65 ( V_31 ) ;
F_58 ( V_31 ) ;
F_1 ( V_2 ) ;
}
static void F_66 ( void )
{
struct V_1 * V_99 , * V_100 ;
F_67 (pos, n, &fscrypt_free_ctxs, free_list)
F_3 ( V_10 , V_99 ) ;
F_68 ( & V_13 ) ;
F_69 ( V_7 ) ;
V_7 = NULL ;
}
int F_70 ( void )
{
int V_95 , V_23 = - V_20 ;
if ( V_7 )
return 0 ;
F_71 ( & V_101 ) ;
if ( V_7 )
goto V_102;
for ( V_95 = 0 ; V_95 < V_103 ; V_95 ++ ) {
struct V_1 * V_2 ;
V_2 = F_11 ( V_10 , V_58 ) ;
if ( ! V_2 )
goto V_104;
F_5 ( & V_2 -> V_12 , & V_13 ) ;
}
V_7 =
F_72 ( V_105 , 0 ) ;
if ( ! V_7 )
goto V_104;
V_102:
F_73 ( & V_101 ) ;
return 0 ;
V_104:
F_66 () ;
F_73 ( & V_101 ) ;
return V_23 ;
}
static int T_6 F_74 ( void )
{
V_97 = F_75 ( L_3 ,
V_106 , 0 ) ;
if ( ! V_97 )
goto V_104;
V_10 = F_76 ( V_1 , V_107 ) ;
if ( ! V_10 )
goto V_108;
V_109 = F_76 ( V_16 , V_107 ) ;
if ( ! V_109 )
goto V_110;
return 0 ;
V_110:
F_77 ( V_10 ) ;
V_108:
F_78 ( V_97 ) ;
V_104:
return - V_20 ;
}
static void T_7 F_79 ( void )
{
F_66 () ;
if ( V_97 )
F_78 ( V_97 ) ;
F_77 ( V_10 ) ;
F_77 ( V_109 ) ;
}
