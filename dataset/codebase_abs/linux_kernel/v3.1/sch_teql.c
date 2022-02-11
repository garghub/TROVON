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
F_25 ( struct V_1 * V_2 , struct V_1 * V_43 , struct V_5 * V_6 )
{
struct V_16 * V_44 = F_8 ( V_6 , 0 ) ;
struct V_7 * V_8 = F_3 ( V_44 -> V_19 ) ;
struct V_21 * V_45 = F_26 ( F_27 ( V_2 ) ) ;
struct V_21 * V_22 = V_8 -> V_23 ;
if ( V_45 -> V_46 == NULL )
return - V_33 ;
if ( V_22 && V_22 -> V_46 == V_45 -> V_46 &&
memcmp ( V_22 -> V_47 , V_45 -> V_47 , V_45 -> V_46 -> V_48 ) == 0 ) {
F_28 ( & V_22 -> V_49 ) ;
} else {
V_22 = F_29 ( V_45 -> V_46 , V_45 -> V_47 , V_6 ) ;
if ( F_30 ( V_22 ) )
return F_31 ( V_22 ) ;
}
if ( F_32 ( V_22 , V_43 ) == 0 ) {
int V_50 ;
char V_51 [ V_52 ] ;
F_33 ( V_51 , V_22 , V_6 ) ;
V_50 = F_34 ( V_2 , V_6 , F_35 ( V_2 -> V_53 ) , V_51 ,
NULL , V_2 -> V_54 ) ;
if ( V_50 < 0 ) {
F_13 ( V_22 ) ;
return - V_33 ;
}
F_12 ( F_16 ( & V_8 -> V_23 , V_22 ) ) ;
return 0 ;
}
F_13 ( V_22 ) ;
return ( V_43 == NULL ) ? - V_55 : 1 ;
}
static inline int F_36 ( struct V_1 * V_2 ,
struct V_1 * V_43 , struct V_5 * V_6 )
{
struct V_16 * V_27 = F_8 ( V_6 , 0 ) ;
if ( V_27 -> V_19 == & V_56 )
return - V_57 ;
if ( V_6 -> V_58 == NULL ||
F_27 ( V_2 ) == NULL ||
F_26 ( F_27 ( V_2 ) ) == NULL )
return 0 ;
return F_25 ( V_2 , V_43 , V_6 ) ;
}
static T_2 F_37 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_25 * V_26 = F_38 ( V_6 ) ;
struct V_3 * V_59 , * V_8 ;
int V_60 ;
int V_61 ;
int V_62 = F_39 ( V_2 ) ;
struct V_1 * V_43 = NULL ;
V_59 = V_26 -> V_20 ;
V_63:
V_61 = 0 ;
V_60 = 0 ;
V_8 = V_59 ;
if ( ! V_8 )
goto V_64;
do {
struct V_5 * V_65 = F_2 ( V_8 ) ;
struct V_16 * V_66 = F_8 ( V_65 , 0 ) ;
const struct V_67 * V_68 = V_65 -> V_69 ;
if ( V_66 -> V_70 != V_8 )
continue;
if ( F_40 ( V_65 , V_62 ) ||
! F_41 ( V_65 ) ) {
V_60 = 1 ;
continue;
}
switch ( F_36 ( V_2 , V_43 , V_65 ) ) {
case 0 :
if ( F_42 ( V_66 ) ) {
unsigned int V_71 = F_43 ( V_2 ) ;
if ( ! F_44 ( V_66 ) &&
V_68 -> V_72 ( V_2 , V_65 ) == V_73 ) {
F_45 ( V_66 ) ;
F_46 ( V_66 ) ;
V_26 -> V_20 = F_18 ( V_8 ) ;
F_9 ( V_6 ) ;
V_26 -> V_74 ++ ;
V_26 -> V_75 += V_71 ;
return V_73 ;
}
F_46 ( V_66 ) ;
}
if ( F_47 ( V_6 ) )
V_60 = 1 ;
break;
case 1 :
V_26 -> V_20 = F_18 ( V_8 ) ;
return V_73 ;
default:
V_61 = 1 ;
break;
}
F_48 ( V_2 , F_49 ( V_2 ) ) ;
} while ( ( V_8 = F_18 ( V_8 ) ) != V_59 );
if ( V_61 && V_43 == NULL ) {
V_43 = V_2 ;
goto V_63;
}
if ( V_60 ) {
F_50 ( V_6 ) ;
return V_76 ;
}
V_26 -> V_77 ++ ;
V_64:
V_26 -> V_78 ++ ;
F_51 ( V_2 ) ;
return V_73 ;
}
static int F_52 ( struct V_5 * V_6 )
{
struct V_3 * V_8 ;
struct V_25 * V_18 = F_38 ( V_6 ) ;
int V_40 = 0xFFFE ;
unsigned int V_35 = V_79 | V_39 ;
if ( V_18 -> V_20 == NULL )
return - V_80 ;
V_35 = V_42 ;
V_8 = V_18 -> V_20 ;
do {
struct V_5 * V_65 = F_2 ( V_8 ) ;
if ( V_65 == NULL )
return - V_80 ;
if ( V_65 -> V_40 < V_40 )
V_40 = V_65 -> V_40 ;
if ( V_65 -> V_32 > V_81 )
return - V_33 ;
if ( ! ( V_65 -> V_35 & V_37 ) )
V_35 &= ~ V_37 ;
if ( ! ( V_65 -> V_35 & V_38 ) )
V_35 &= ~ V_38 ;
if ( ! ( V_65 -> V_35 & V_39 ) )
V_35 &= ~ V_39 ;
} while ( ( V_8 = F_18 ( V_8 ) ) != V_18 -> V_20 );
V_18 -> V_6 -> V_40 = V_40 ;
V_18 -> V_6 -> V_35 = ( V_18 -> V_6 -> V_35 & ~ V_42 ) | V_35 ;
F_53 ( V_18 -> V_6 ) ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
return 0 ;
}
static struct V_82 * F_55 ( struct V_5 * V_6 ,
struct V_82 * V_83 )
{
struct V_25 * V_18 = F_38 ( V_6 ) ;
V_83 -> V_74 = V_18 -> V_74 ;
V_83 -> V_75 = V_18 -> V_75 ;
V_83 -> V_77 = V_18 -> V_77 ;
V_83 -> V_78 = V_18 -> V_78 ;
return V_83 ;
}
static int F_56 ( struct V_5 * V_6 , int V_84 )
{
struct V_25 * V_18 = F_38 ( V_6 ) ;
struct V_3 * V_8 ;
if ( V_84 < 68 )
return - V_33 ;
V_8 = V_18 -> V_20 ;
if ( V_8 ) {
do {
if ( V_84 > F_2 ( V_8 ) -> V_40 )
return - V_33 ;
} while ( ( V_8 = F_18 ( V_8 ) ) != V_18 -> V_20 );
}
V_6 -> V_40 = V_84 ;
return 0 ;
}
static T_3 void F_57 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_38 ( V_6 ) ;
struct V_85 * V_31 = & V_26 -> V_86 ;
V_26 -> V_6 = V_6 ;
V_31 -> V_87 = sizeof( struct V_7 ) ;
V_31 -> V_88 = F_1 ;
V_31 -> V_89 = F_6 ;
V_31 -> V_90 = F_11 ;
V_31 -> V_91 = F_23 ;
V_31 -> V_92 = F_14 ;
V_31 -> V_93 = F_17 ;
V_31 -> V_94 = V_95 ;
V_6 -> V_69 = & V_96 ;
V_6 -> type = V_97 ;
V_6 -> V_40 = 1500 ;
V_6 -> V_10 = 100 ;
V_6 -> V_35 = V_79 ;
V_6 -> V_32 = V_81 ;
V_6 -> V_98 &= ~ V_99 ;
}
static int T_3 F_58 ( void )
{
int V_100 ;
int V_50 = - V_57 ;
for ( V_100 = 0 ; V_100 < V_101 ; V_100 ++ ) {
struct V_5 * V_6 ;
struct V_25 * V_26 ;
V_6 = F_59 ( sizeof( struct V_25 ) ,
L_1 , F_57 ) ;
if ( ! V_6 ) {
V_50 = - V_102 ;
break;
}
if ( ( V_50 = F_60 ( V_6 ) ) ) {
F_61 ( V_6 ) ;
break;
}
V_26 = F_38 ( V_6 ) ;
F_62 ( V_26 -> V_86 . V_103 , V_6 -> V_104 , V_105 ) ;
V_50 = F_63 ( & V_26 -> V_86 ) ;
if ( V_50 ) {
F_64 ( V_6 ) ;
F_61 ( V_6 ) ;
break;
}
F_65 ( & V_26 -> V_106 , & V_107 ) ;
}
return V_100 ? 0 : V_50 ;
}
static void T_4 F_66 ( void )
{
struct V_25 * V_26 , * V_108 ;
F_67 (master, nxt, &master_dev_list, master_list) {
F_68 ( & V_26 -> V_106 ) ;
F_69 ( & V_26 -> V_86 ) ;
F_64 ( V_26 -> V_6 ) ;
F_61 ( V_26 -> V_6 ) ;
}
}
