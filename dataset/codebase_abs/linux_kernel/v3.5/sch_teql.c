static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( V_8 -> V_8 . V_9 < V_6 -> V_10 ) {
F_4 ( & V_8 -> V_8 , V_2 ) ;
return V_11 ;
}
return F_5 ( V_2 , V_4 ) ;
}
static struct V_1 *
F_6 ( struct V_3 * V_4 )
{
struct V_7 * V_12 = F_3 ( V_4 ) ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
V_2 = F_7 ( & V_12 -> V_8 ) ;
V_14 = F_8 ( V_12 -> V_15 -> V_6 , 0 ) ;
if ( V_2 == NULL ) {
struct V_5 * V_15 = F_2 ( V_14 -> V_16 ) ;
if ( V_15 ) {
V_12 -> V_15 -> V_17 = V_4 ;
F_9 ( V_15 ) ;
}
} else {
F_10 ( V_4 , V_2 ) ;
}
V_4 -> V_8 . V_9 = V_12 -> V_8 . V_9 + V_14 -> V_16 -> V_8 . V_9 ;
return V_2 ;
}
static struct V_1 *
F_11 ( struct V_3 * V_4 )
{
return NULL ;
}
static inline void
F_12 ( struct V_18 * V_19 )
{
if ( V_19 )
F_13 ( V_19 ) ;
}
static void
F_14 ( struct V_3 * V_4 )
{
struct V_7 * V_12 = F_3 ( V_4 ) ;
F_15 ( & V_12 -> V_8 ) ;
V_4 -> V_8 . V_9 = 0 ;
F_12 ( F_16 ( & V_12 -> V_20 , NULL ) ) ;
}
static void
F_17 ( struct V_3 * V_4 )
{
struct V_3 * V_8 , * V_21 ;
struct V_7 * V_12 = F_3 ( V_4 ) ;
struct V_22 * V_23 = V_12 -> V_15 ;
V_21 = V_23 -> V_17 ;
if ( V_21 ) {
do {
V_8 = F_18 ( V_21 ) ;
if ( V_8 == V_4 ) {
F_18 ( V_21 ) = F_18 ( V_8 ) ;
if ( V_8 == V_23 -> V_17 ) {
V_23 -> V_17 = F_18 ( V_8 ) ;
if ( V_8 == V_23 -> V_17 ) {
struct V_13 * V_24 ;
T_1 * V_25 ;
V_24 = F_8 ( V_23 -> V_6 , 0 ) ;
V_23 -> V_17 = NULL ;
V_25 = F_19 ( V_24 -> V_16 ) ;
F_20 ( V_25 ) ;
F_21 ( V_24 -> V_16 ) ;
F_22 ( V_25 ) ;
}
}
F_15 ( & V_12 -> V_8 ) ;
F_12 ( F_16 ( & V_12 -> V_20 , NULL ) ) ;
break;
}
} while ( ( V_21 = V_8 ) != V_23 -> V_17 );
}
}
static int F_23 ( struct V_3 * V_4 , struct V_26 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_22 * V_15 = (struct V_22 * ) V_4 -> V_28 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( V_6 -> V_29 > V_15 -> V_6 -> V_29 )
return - V_30 ;
if ( V_15 -> V_6 == V_6 )
return - V_31 ;
V_8 -> V_15 = V_15 ;
F_24 ( & V_8 -> V_8 ) ;
if ( V_15 -> V_17 ) {
if ( V_15 -> V_6 -> V_32 & V_33 ) {
if ( ( V_15 -> V_6 -> V_32 & V_34 &&
! ( V_6 -> V_32 & V_34 ) ) ||
( V_15 -> V_6 -> V_32 & V_35 &&
! ( V_6 -> V_32 & V_35 ) ) ||
( V_15 -> V_6 -> V_32 & V_36 &&
! ( V_6 -> V_32 & V_36 ) ) ||
V_6 -> V_37 < V_15 -> V_6 -> V_37 )
return - V_30 ;
} else {
if ( ! ( V_6 -> V_32 & V_34 ) )
V_15 -> V_6 -> V_32 &= ~ V_34 ;
if ( ! ( V_6 -> V_32 & V_35 ) )
V_15 -> V_6 -> V_32 &= ~ V_35 ;
if ( ! ( V_6 -> V_32 & V_36 ) )
V_15 -> V_6 -> V_32 &= ~ V_36 ;
if ( V_6 -> V_37 < V_15 -> V_6 -> V_37 )
V_15 -> V_6 -> V_37 = V_6 -> V_37 ;
}
V_8 -> V_38 = F_18 ( V_15 -> V_17 ) ;
F_18 ( V_15 -> V_17 ) = V_4 ;
} else {
V_8 -> V_38 = V_4 ;
V_15 -> V_17 = V_4 ;
V_15 -> V_6 -> V_37 = V_6 -> V_37 ;
V_15 -> V_6 -> V_32 = ( V_15 -> V_6 -> V_32 & ~ V_39 ) | ( V_6 -> V_32 & V_39 ) ;
}
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_1 * V_40 ,
struct V_5 * V_6 , struct V_13 * V_24 ,
struct V_18 * V_41 )
{
struct V_7 * V_8 = F_3 ( V_24 -> V_16 ) ;
struct V_18 * V_19 = V_8 -> V_20 ;
if ( V_41 -> V_42 == NULL )
return - V_30 ;
if ( V_19 && V_19 -> V_42 == V_41 -> V_42 &&
memcmp ( V_19 -> V_43 , V_41 -> V_43 , V_41 -> V_42 -> V_44 ) == 0 ) {
F_26 ( & V_19 -> V_45 ) ;
} else {
V_19 = F_27 ( V_41 -> V_42 , V_41 -> V_43 , V_6 ) ;
if ( F_28 ( V_19 ) )
return F_29 ( V_19 ) ;
}
if ( F_30 ( V_19 , V_40 ) == 0 ) {
int V_46 ;
char V_47 [ V_48 ] ;
F_31 ( V_47 , V_19 , V_6 ) ;
V_46 = F_32 ( V_2 , V_6 , F_33 ( V_2 -> V_49 ) , V_47 ,
NULL , V_2 -> V_50 ) ;
if ( V_46 < 0 ) {
F_13 ( V_19 ) ;
return - V_30 ;
}
F_12 ( F_16 ( & V_8 -> V_20 , V_19 ) ) ;
return 0 ;
}
F_13 ( V_19 ) ;
return ( V_40 == NULL ) ? - V_51 : 1 ;
}
static inline int F_34 ( struct V_1 * V_2 ,
struct V_1 * V_40 ,
struct V_5 * V_6 ,
struct V_13 * V_24 )
{
struct V_52 * V_53 = F_35 ( V_2 ) ;
struct V_18 * V_41 ;
int V_54 ;
if ( V_24 -> V_16 == & V_55 )
return - V_56 ;
if ( ! V_6 -> V_57 || ! V_53 )
return 0 ;
F_36 () ;
V_41 = F_37 ( V_53 ) ;
V_54 = V_41 ? F_25 ( V_2 , V_40 , V_6 , V_24 , V_41 ) : 0 ;
F_38 () ;
return V_54 ;
}
static T_2 F_39 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_22 * V_23 = F_40 ( V_6 ) ;
struct V_3 * V_58 , * V_8 ;
int V_59 ;
int V_60 ;
int V_61 = F_41 ( V_2 ) ;
struct V_1 * V_40 = NULL ;
V_58 = V_23 -> V_17 ;
V_62:
V_60 = 0 ;
V_59 = 0 ;
V_8 = V_58 ;
if ( ! V_8 )
goto V_63;
do {
struct V_5 * V_64 = F_2 ( V_8 ) ;
struct V_13 * V_65 = F_8 ( V_64 , 0 ) ;
const struct V_66 * V_67 = V_64 -> V_68 ;
if ( V_65 -> V_69 != V_8 )
continue;
if ( F_42 ( F_8 ( V_64 , V_61 ) ) ||
! F_43 ( V_64 ) ) {
V_59 = 1 ;
continue;
}
switch ( F_34 ( V_2 , V_40 , V_64 , V_65 ) ) {
case 0 :
if ( F_44 ( V_65 ) ) {
unsigned int V_70 = F_45 ( V_2 ) ;
if ( ! F_46 ( V_65 ) &&
V_67 -> V_71 ( V_2 , V_64 ) == V_72 ) {
F_47 ( V_65 ) ;
F_48 ( V_65 ) ;
V_23 -> V_17 = F_18 ( V_8 ) ;
F_9 ( V_6 ) ;
V_23 -> V_73 ++ ;
V_23 -> V_74 += V_70 ;
return V_72 ;
}
F_48 ( V_65 ) ;
}
if ( F_42 ( F_8 ( V_6 , 0 ) ) )
V_59 = 1 ;
break;
case 1 :
V_23 -> V_17 = F_18 ( V_8 ) ;
return V_72 ;
default:
V_60 = 1 ;
break;
}
F_49 ( V_2 , F_50 ( V_2 ) ) ;
} while ( ( V_8 = F_18 ( V_8 ) ) != V_58 );
if ( V_60 && V_40 == NULL ) {
V_40 = V_2 ;
goto V_62;
}
if ( V_59 ) {
F_51 ( V_6 ) ;
return V_75 ;
}
V_23 -> V_76 ++ ;
V_63:
V_23 -> V_77 ++ ;
F_52 ( V_2 ) ;
return V_72 ;
}
static int F_53 ( struct V_5 * V_6 )
{
struct V_3 * V_8 ;
struct V_22 * V_15 = F_40 ( V_6 ) ;
int V_37 = 0xFFFE ;
unsigned int V_32 = V_78 | V_36 ;
if ( V_15 -> V_17 == NULL )
return - V_79 ;
V_32 = V_39 ;
V_8 = V_15 -> V_17 ;
do {
struct V_5 * V_64 = F_2 ( V_8 ) ;
if ( V_64 == NULL )
return - V_79 ;
if ( V_64 -> V_37 < V_37 )
V_37 = V_64 -> V_37 ;
if ( V_64 -> V_29 > V_80 )
return - V_30 ;
if ( ! ( V_64 -> V_32 & V_34 ) )
V_32 &= ~ V_34 ;
if ( ! ( V_64 -> V_32 & V_35 ) )
V_32 &= ~ V_35 ;
if ( ! ( V_64 -> V_32 & V_36 ) )
V_32 &= ~ V_36 ;
} while ( ( V_8 = F_18 ( V_8 ) ) != V_15 -> V_17 );
V_15 -> V_6 -> V_37 = V_37 ;
V_15 -> V_6 -> V_32 = ( V_15 -> V_6 -> V_32 & ~ V_39 ) | V_32 ;
F_54 ( V_15 -> V_6 ) ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 )
{
F_51 ( V_6 ) ;
return 0 ;
}
static struct V_81 * F_56 ( struct V_5 * V_6 ,
struct V_81 * V_82 )
{
struct V_22 * V_15 = F_40 ( V_6 ) ;
V_82 -> V_73 = V_15 -> V_73 ;
V_82 -> V_74 = V_15 -> V_74 ;
V_82 -> V_76 = V_15 -> V_76 ;
V_82 -> V_77 = V_15 -> V_77 ;
return V_82 ;
}
static int F_57 ( struct V_5 * V_6 , int V_83 )
{
struct V_22 * V_15 = F_40 ( V_6 ) ;
struct V_3 * V_8 ;
if ( V_83 < 68 )
return - V_30 ;
V_8 = V_15 -> V_17 ;
if ( V_8 ) {
do {
if ( V_83 > F_2 ( V_8 ) -> V_37 )
return - V_30 ;
} while ( ( V_8 = F_18 ( V_8 ) ) != V_15 -> V_17 );
}
V_6 -> V_37 = V_83 ;
return 0 ;
}
static T_3 void F_58 ( struct V_5 * V_6 )
{
struct V_22 * V_23 = F_40 ( V_6 ) ;
struct V_84 * V_28 = & V_23 -> V_85 ;
V_23 -> V_6 = V_6 ;
V_28 -> V_86 = sizeof( struct V_7 ) ;
V_28 -> V_87 = F_1 ;
V_28 -> V_88 = F_6 ;
V_28 -> V_89 = F_11 ;
V_28 -> V_90 = F_23 ;
V_28 -> V_91 = F_14 ;
V_28 -> V_92 = F_17 ;
V_28 -> V_93 = V_94 ;
V_6 -> V_68 = & V_95 ;
V_6 -> type = V_96 ;
V_6 -> V_37 = 1500 ;
V_6 -> V_10 = 100 ;
V_6 -> V_32 = V_78 ;
V_6 -> V_29 = V_80 ;
V_6 -> V_97 &= ~ V_98 ;
}
static int T_3 F_59 ( void )
{
int V_99 ;
int V_46 = - V_56 ;
for ( V_99 = 0 ; V_99 < V_100 ; V_99 ++ ) {
struct V_5 * V_6 ;
struct V_22 * V_23 ;
V_6 = F_60 ( sizeof( struct V_22 ) ,
L_1 , F_58 ) ;
if ( ! V_6 ) {
V_46 = - V_101 ;
break;
}
if ( ( V_46 = F_61 ( V_6 ) ) ) {
F_62 ( V_6 ) ;
break;
}
V_23 = F_40 ( V_6 ) ;
F_63 ( V_23 -> V_85 . V_102 , V_6 -> V_103 , V_104 ) ;
V_46 = F_64 ( & V_23 -> V_85 ) ;
if ( V_46 ) {
F_65 ( V_6 ) ;
F_62 ( V_6 ) ;
break;
}
F_66 ( & V_23 -> V_105 , & V_106 ) ;
}
return V_99 ? 0 : V_46 ;
}
static void T_4 F_67 ( void )
{
struct V_22 * V_23 , * V_107 ;
F_68 (master, nxt, &master_dev_list, master_list) {
F_69 ( & V_23 -> V_105 ) ;
F_70 ( & V_23 -> V_85 ) ;
F_65 ( V_23 -> V_6 ) ;
F_62 ( V_23 -> V_6 ) ;
}
}
