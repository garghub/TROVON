static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( V_8 -> V_8 . V_9 < V_6 -> V_10 ) {
F_4 ( & V_8 -> V_8 , V_2 ) ;
return V_11 ;
}
F_5 ( V_2 ) ;
V_4 -> V_12 . V_13 ++ ;
return V_14 ;
}
static struct V_1 *
F_6 ( struct V_3 * V_4 )
{
struct V_7 * V_15 = F_3 ( V_4 ) ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
V_2 = F_7 ( & V_15 -> V_8 ) ;
V_17 = F_8 ( V_15 -> V_18 -> V_6 , 0 ) ;
if ( V_2 == NULL ) {
struct V_5 * V_18 = F_2 ( V_17 -> V_19 ) ;
if ( V_18 ) {
V_15 -> V_18 -> V_20 = V_4 ;
F_9 ( V_18 ) ;
}
} else {
F_10 ( V_4 , V_2 ) ;
}
V_4 -> V_8 . V_9 = V_15 -> V_8 . V_9 + V_17 -> V_19 -> V_8 . V_9 ;
return V_2 ;
}
static struct V_1 *
F_11 ( struct V_3 * V_4 )
{
return NULL ;
}
static inline void
F_12 ( struct V_21 * V_22 )
{
if ( V_22 )
F_13 ( V_22 ) ;
}
static void
F_14 ( struct V_3 * V_4 )
{
struct V_7 * V_15 = F_3 ( V_4 ) ;
F_15 ( & V_15 -> V_8 ) ;
V_4 -> V_8 . V_9 = 0 ;
F_12 ( F_16 ( & V_15 -> V_23 , NULL ) ) ;
}
static void
F_17 ( struct V_3 * V_4 )
{
struct V_3 * V_8 , * V_24 ;
struct V_7 * V_15 = F_3 ( V_4 ) ;
struct V_25 * V_26 = V_15 -> V_18 ;
V_24 = V_26 -> V_20 ;
if ( V_24 ) {
do {
V_8 = F_18 ( V_24 ) ;
if ( V_8 == V_4 ) {
F_18 ( V_24 ) = F_18 ( V_8 ) ;
if ( V_8 == V_26 -> V_20 ) {
V_26 -> V_20 = F_18 ( V_8 ) ;
if ( V_8 == V_26 -> V_20 ) {
struct V_16 * V_27 ;
T_1 * V_28 ;
V_27 = F_8 ( V_26 -> V_6 , 0 ) ;
V_26 -> V_20 = NULL ;
V_28 = F_19 ( V_27 -> V_19 ) ;
F_20 ( V_28 ) ;
F_21 ( V_27 -> V_19 ) ;
F_22 ( V_28 ) ;
}
}
F_15 ( & V_15 -> V_8 ) ;
F_12 ( F_16 ( & V_15 -> V_23 , NULL ) ) ;
break;
}
} while ( ( V_24 = V_8 ) != V_26 -> V_20 );
}
}
static int F_23 ( struct V_3 * V_4 , struct V_29 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_25 * V_18 = (struct V_25 * ) V_4 -> V_31 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( V_6 -> V_32 > V_18 -> V_6 -> V_32 )
return - V_33 ;
if ( V_18 -> V_6 == V_6 )
return - V_34 ;
V_8 -> V_18 = V_18 ;
F_24 ( & V_8 -> V_8 ) ;
if ( V_18 -> V_20 ) {
if ( V_18 -> V_6 -> V_35 & V_36 ) {
if ( ( V_18 -> V_6 -> V_35 & V_37 &&
! ( V_6 -> V_35 & V_37 ) ) ||
( V_18 -> V_6 -> V_35 & V_38 &&
! ( V_6 -> V_35 & V_38 ) ) ||
( V_18 -> V_6 -> V_35 & V_39 &&
! ( V_6 -> V_35 & V_39 ) ) ||
V_6 -> V_40 < V_18 -> V_6 -> V_40 )
return - V_33 ;
} else {
if ( ! ( V_6 -> V_35 & V_37 ) )
V_18 -> V_6 -> V_35 &= ~ V_37 ;
if ( ! ( V_6 -> V_35 & V_38 ) )
V_18 -> V_6 -> V_35 &= ~ V_38 ;
if ( ! ( V_6 -> V_35 & V_39 ) )
V_18 -> V_6 -> V_35 &= ~ V_39 ;
if ( V_6 -> V_40 < V_18 -> V_6 -> V_40 )
V_18 -> V_6 -> V_40 = V_6 -> V_40 ;
}
V_8 -> V_41 = F_18 ( V_18 -> V_20 ) ;
F_18 ( V_18 -> V_20 ) = V_4 ;
} else {
V_8 -> V_41 = V_4 ;
V_18 -> V_20 = V_4 ;
V_18 -> V_6 -> V_40 = V_6 -> V_40 ;
V_18 -> V_6 -> V_35 = ( V_18 -> V_6 -> V_35 & ~ V_42 ) | ( V_6 -> V_35 & V_42 ) ;
}
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_1 * V_43 ,
struct V_5 * V_6 , struct V_16 * V_27 ,
struct V_21 * V_44 )
{
struct V_7 * V_8 = F_3 ( V_27 -> V_19 ) ;
struct V_21 * V_22 = V_8 -> V_23 ;
if ( V_44 -> V_45 == NULL )
return - V_33 ;
if ( V_22 && V_22 -> V_45 == V_44 -> V_45 &&
memcmp ( V_22 -> V_46 , V_44 -> V_46 , V_44 -> V_45 -> V_47 ) == 0 ) {
F_26 ( & V_22 -> V_48 ) ;
} else {
V_22 = F_27 ( V_44 -> V_45 , V_44 -> V_46 , V_6 ) ;
if ( F_28 ( V_22 ) )
return F_29 ( V_22 ) ;
}
if ( F_30 ( V_22 , V_43 ) == 0 ) {
int V_49 ;
char V_50 [ V_51 ] ;
F_31 ( V_50 , V_22 , V_6 ) ;
V_49 = F_32 ( V_2 , V_6 , F_33 ( V_2 -> V_52 ) , V_50 ,
NULL , V_2 -> V_53 ) ;
if ( V_49 < 0 ) {
F_13 ( V_22 ) ;
return - V_33 ;
}
F_12 ( F_16 ( & V_8 -> V_23 , V_22 ) ) ;
return 0 ;
}
F_13 ( V_22 ) ;
return ( V_43 == NULL ) ? - V_54 : 1 ;
}
static inline int F_34 ( struct V_1 * V_2 ,
struct V_1 * V_43 ,
struct V_5 * V_6 ,
struct V_16 * V_27 )
{
struct V_55 * V_56 = F_35 ( V_2 ) ;
struct V_21 * V_44 ;
int V_57 ;
if ( V_27 -> V_19 == & V_58 )
return - V_59 ;
if ( ! V_6 -> V_60 || ! V_56 )
return 0 ;
F_36 () ;
V_44 = F_37 ( V_56 ) ;
V_57 = V_44 ? F_25 ( V_2 , V_43 , V_6 , V_27 , V_44 ) : 0 ;
F_38 () ;
return V_57 ;
}
static T_2 F_39 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_25 * V_26 = F_40 ( V_6 ) ;
struct V_3 * V_61 , * V_8 ;
int V_62 ;
int V_63 ;
int V_64 = F_41 ( V_2 ) ;
struct V_1 * V_43 = NULL ;
V_61 = V_26 -> V_20 ;
V_65:
V_63 = 0 ;
V_62 = 0 ;
V_8 = V_61 ;
if ( ! V_8 )
goto V_66;
do {
struct V_5 * V_67 = F_2 ( V_8 ) ;
struct V_16 * V_68 = F_8 ( V_67 , 0 ) ;
const struct V_69 * V_70 = V_67 -> V_71 ;
if ( V_68 -> V_72 != V_8 )
continue;
if ( F_42 ( V_67 , V_64 ) ||
! F_43 ( V_67 ) ) {
V_62 = 1 ;
continue;
}
switch ( F_34 ( V_2 , V_43 , V_67 , V_68 ) ) {
case 0 :
if ( F_44 ( V_68 ) ) {
unsigned int V_73 = F_45 ( V_2 ) ;
if ( ! F_46 ( V_68 ) &&
V_70 -> V_74 ( V_2 , V_67 ) == V_75 ) {
F_47 ( V_68 ) ;
F_48 ( V_68 ) ;
V_26 -> V_20 = F_18 ( V_8 ) ;
F_9 ( V_6 ) ;
V_26 -> V_76 ++ ;
V_26 -> V_77 += V_73 ;
return V_75 ;
}
F_48 ( V_68 ) ;
}
if ( F_49 ( V_6 ) )
V_62 = 1 ;
break;
case 1 :
V_26 -> V_20 = F_18 ( V_8 ) ;
return V_75 ;
default:
V_63 = 1 ;
break;
}
F_50 ( V_2 , F_51 ( V_2 ) ) ;
} while ( ( V_8 = F_18 ( V_8 ) ) != V_61 );
if ( V_63 && V_43 == NULL ) {
V_43 = V_2 ;
goto V_65;
}
if ( V_62 ) {
F_52 ( V_6 ) ;
return V_78 ;
}
V_26 -> V_79 ++ ;
V_66:
V_26 -> V_80 ++ ;
F_53 ( V_2 ) ;
return V_75 ;
}
static int F_54 ( struct V_5 * V_6 )
{
struct V_3 * V_8 ;
struct V_25 * V_18 = F_40 ( V_6 ) ;
int V_40 = 0xFFFE ;
unsigned int V_35 = V_81 | V_39 ;
if ( V_18 -> V_20 == NULL )
return - V_82 ;
V_35 = V_42 ;
V_8 = V_18 -> V_20 ;
do {
struct V_5 * V_67 = F_2 ( V_8 ) ;
if ( V_67 == NULL )
return - V_82 ;
if ( V_67 -> V_40 < V_40 )
V_40 = V_67 -> V_40 ;
if ( V_67 -> V_32 > V_83 )
return - V_33 ;
if ( ! ( V_67 -> V_35 & V_37 ) )
V_35 &= ~ V_37 ;
if ( ! ( V_67 -> V_35 & V_38 ) )
V_35 &= ~ V_38 ;
if ( ! ( V_67 -> V_35 & V_39 ) )
V_35 &= ~ V_39 ;
} while ( ( V_8 = F_18 ( V_8 ) ) != V_18 -> V_20 );
V_18 -> V_6 -> V_40 = V_40 ;
V_18 -> V_6 -> V_35 = ( V_18 -> V_6 -> V_35 & ~ V_42 ) | V_35 ;
F_55 ( V_18 -> V_6 ) ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
return 0 ;
}
static struct V_84 * F_57 ( struct V_5 * V_6 ,
struct V_84 * V_85 )
{
struct V_25 * V_18 = F_40 ( V_6 ) ;
V_85 -> V_76 = V_18 -> V_76 ;
V_85 -> V_77 = V_18 -> V_77 ;
V_85 -> V_79 = V_18 -> V_79 ;
V_85 -> V_80 = V_18 -> V_80 ;
return V_85 ;
}
static int F_58 ( struct V_5 * V_6 , int V_86 )
{
struct V_25 * V_18 = F_40 ( V_6 ) ;
struct V_3 * V_8 ;
if ( V_86 < 68 )
return - V_33 ;
V_8 = V_18 -> V_20 ;
if ( V_8 ) {
do {
if ( V_86 > F_2 ( V_8 ) -> V_40 )
return - V_33 ;
} while ( ( V_8 = F_18 ( V_8 ) ) != V_18 -> V_20 );
}
V_6 -> V_40 = V_86 ;
return 0 ;
}
static T_3 void F_59 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_40 ( V_6 ) ;
struct V_87 * V_31 = & V_26 -> V_88 ;
V_26 -> V_6 = V_6 ;
V_31 -> V_89 = sizeof( struct V_7 ) ;
V_31 -> V_90 = F_1 ;
V_31 -> V_91 = F_6 ;
V_31 -> V_92 = F_11 ;
V_31 -> V_93 = F_23 ;
V_31 -> V_94 = F_14 ;
V_31 -> V_95 = F_17 ;
V_31 -> V_96 = V_97 ;
V_6 -> V_71 = & V_98 ;
V_6 -> type = V_99 ;
V_6 -> V_40 = 1500 ;
V_6 -> V_10 = 100 ;
V_6 -> V_35 = V_81 ;
V_6 -> V_32 = V_83 ;
V_6 -> V_100 &= ~ V_101 ;
}
static int T_3 F_60 ( void )
{
int V_102 ;
int V_49 = - V_59 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ ) {
struct V_5 * V_6 ;
struct V_25 * V_26 ;
V_6 = F_61 ( sizeof( struct V_25 ) ,
L_1 , F_59 ) ;
if ( ! V_6 ) {
V_49 = - V_104 ;
break;
}
if ( ( V_49 = F_62 ( V_6 ) ) ) {
F_63 ( V_6 ) ;
break;
}
V_26 = F_40 ( V_6 ) ;
F_64 ( V_26 -> V_88 . V_105 , V_6 -> V_106 , V_107 ) ;
V_49 = F_65 ( & V_26 -> V_88 ) ;
if ( V_49 ) {
F_66 ( V_6 ) ;
F_63 ( V_6 ) ;
break;
}
F_67 ( & V_26 -> V_108 , & V_109 ) ;
}
return V_102 ? 0 : V_49 ;
}
static void T_4 F_68 ( void )
{
struct V_25 * V_26 , * V_110 ;
F_69 (master, nxt, &master_dev_list, master_list) {
F_70 ( & V_26 -> V_108 ) ;
F_71 ( & V_26 -> V_88 ) ;
F_66 ( V_26 -> V_6 ) ;
F_63 ( V_26 -> V_6 ) ;
}
}
