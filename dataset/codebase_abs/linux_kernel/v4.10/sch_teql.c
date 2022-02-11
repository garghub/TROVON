static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_1 * * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_4 ) ;
if ( V_9 -> V_9 . V_10 < V_7 -> V_11 ) {
F_4 ( & V_9 -> V_9 , V_2 ) ;
return V_12 ;
}
return F_5 ( V_2 , V_4 , V_5 ) ;
}
static struct V_1 *
F_6 ( struct V_3 * V_4 )
{
struct V_8 * V_13 = F_3 ( V_4 ) ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
struct V_3 * V_9 ;
V_2 = F_7 ( & V_13 -> V_9 ) ;
V_15 = F_8 ( V_13 -> V_16 -> V_7 , 0 ) ;
V_9 = F_9 ( V_15 -> V_17 ) ;
if ( V_2 == NULL ) {
struct V_6 * V_16 = F_2 ( V_9 ) ;
if ( V_16 ) {
V_13 -> V_16 -> V_18 = V_4 ;
F_10 ( V_16 ) ;
}
} else {
F_11 ( V_4 , V_2 ) ;
}
V_4 -> V_9 . V_10 = V_13 -> V_9 . V_10 + V_9 -> V_9 . V_10 ;
return V_2 ;
}
static struct V_1 *
F_12 ( struct V_3 * V_4 )
{
return NULL ;
}
static void
F_13 ( struct V_3 * V_4 )
{
struct V_8 * V_13 = F_3 ( V_4 ) ;
F_14 ( & V_13 -> V_9 ) ;
V_4 -> V_9 . V_10 = 0 ;
}
static void
F_15 ( struct V_3 * V_4 )
{
struct V_3 * V_9 , * V_19 ;
struct V_8 * V_13 = F_3 ( V_4 ) ;
struct V_20 * V_21 = V_13 -> V_16 ;
V_19 = V_21 -> V_18 ;
if ( V_19 ) {
do {
V_9 = F_16 ( V_19 ) ;
if ( V_9 == V_4 ) {
F_16 ( V_19 ) = F_16 ( V_9 ) ;
if ( V_9 == V_21 -> V_18 ) {
V_21 -> V_18 = F_16 ( V_9 ) ;
if ( V_9 == V_21 -> V_18 ) {
struct V_14 * V_22 ;
T_1 * V_23 ;
V_22 = F_8 ( V_21 -> V_7 , 0 ) ;
V_21 -> V_18 = NULL ;
V_23 = F_17 ( F_18 ( V_22 -> V_17 ) ) ;
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_22 -> V_17 ) ) ;
F_21 ( V_23 ) ;
}
}
F_14 ( & V_13 -> V_9 ) ;
break;
}
} while ( ( V_19 = V_9 ) != V_21 -> V_18 );
}
}
static int F_22 ( struct V_3 * V_4 , struct V_24 * V_25 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_20 * V_16 = (struct V_20 * ) V_4 -> V_26 ;
struct V_8 * V_9 = F_3 ( V_4 ) ;
if ( V_7 -> V_27 > V_16 -> V_7 -> V_27 )
return - V_28 ;
if ( V_16 -> V_7 == V_7 )
return - V_29 ;
V_9 -> V_16 = V_16 ;
F_23 ( & V_9 -> V_9 ) ;
if ( V_16 -> V_18 ) {
if ( V_16 -> V_7 -> V_30 & V_31 ) {
if ( ( V_16 -> V_7 -> V_30 & V_32 &&
! ( V_7 -> V_30 & V_32 ) ) ||
( V_16 -> V_7 -> V_30 & V_33 &&
! ( V_7 -> V_30 & V_33 ) ) ||
( V_16 -> V_7 -> V_30 & V_34 &&
! ( V_7 -> V_30 & V_34 ) ) ||
V_7 -> V_35 < V_16 -> V_7 -> V_35 )
return - V_28 ;
} else {
if ( ! ( V_7 -> V_30 & V_32 ) )
V_16 -> V_7 -> V_30 &= ~ V_32 ;
if ( ! ( V_7 -> V_30 & V_33 ) )
V_16 -> V_7 -> V_30 &= ~ V_33 ;
if ( ! ( V_7 -> V_30 & V_34 ) )
V_16 -> V_7 -> V_30 &= ~ V_34 ;
if ( V_7 -> V_35 < V_16 -> V_7 -> V_35 )
V_16 -> V_7 -> V_35 = V_7 -> V_35 ;
}
V_9 -> V_36 = F_16 ( V_16 -> V_18 ) ;
F_16 ( V_16 -> V_18 ) = V_4 ;
} else {
V_9 -> V_36 = V_4 ;
V_16 -> V_18 = V_4 ;
V_16 -> V_7 -> V_35 = V_7 -> V_35 ;
V_16 -> V_7 -> V_30 = ( V_16 -> V_7 -> V_30 & ~ V_37 ) | ( V_7 -> V_30 & V_37 ) ;
}
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_1 * V_38 ,
struct V_6 * V_7 , struct V_14 * V_22 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 ;
int V_43 = 0 ;
V_42 = F_25 ( V_40 , V_2 ) ;
if ( ! V_42 )
return - V_44 ;
if ( V_40 -> V_7 != V_7 ) {
struct V_41 * V_45 ;
V_45 = F_26 ( V_42 -> V_46 , V_42 -> V_47 , V_7 ) ;
F_27 ( V_42 ) ;
if ( F_28 ( V_45 ) )
return F_29 ( V_45 ) ;
V_42 = V_45 ;
}
if ( F_30 ( V_42 , V_38 ) == 0 ) {
int V_43 ;
char V_48 [ V_49 ] ;
F_31 ( V_48 , V_42 , V_7 ) ;
V_43 = F_32 ( V_2 , V_7 , F_33 ( F_34 ( V_2 ) ) ,
V_48 , NULL , V_2 -> V_50 ) ;
if ( V_43 < 0 )
V_43 = - V_28 ;
} else {
V_43 = ( V_38 == NULL ) ? - V_51 : 1 ;
}
F_27 ( V_42 ) ;
return V_43 ;
}
static inline int F_35 ( struct V_1 * V_2 ,
struct V_1 * V_38 ,
struct V_6 * V_7 ,
struct V_14 * V_22 )
{
struct V_39 * V_40 = F_36 ( V_2 ) ;
int V_52 ;
if ( F_37 ( V_22 -> V_17 ) == & V_53 )
return - V_54 ;
if ( ! V_7 -> V_55 || ! V_40 )
return 0 ;
F_38 () ;
V_52 = F_24 ( V_2 , V_38 , V_7 , V_22 , V_40 ) ;
F_39 () ;
return V_52 ;
}
static T_2 F_40 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_20 * V_21 = F_41 ( V_7 ) ;
struct V_3 * V_56 , * V_9 ;
int V_57 ;
int V_58 ;
int V_59 = F_42 ( V_2 ) ;
struct V_1 * V_38 = NULL ;
V_56 = V_21 -> V_18 ;
V_60:
V_58 = 0 ;
V_57 = 0 ;
V_9 = V_56 ;
if ( ! V_9 )
goto V_61;
do {
struct V_6 * V_62 = F_2 ( V_9 ) ;
struct V_14 * V_63 = F_8 ( V_62 , 0 ) ;
if ( V_63 -> V_64 != V_9 )
continue;
if ( F_43 ( F_8 ( V_62 , V_59 ) ) ||
! F_44 ( V_62 ) ) {
V_57 = 1 ;
continue;
}
switch ( F_35 ( V_2 , V_38 , V_62 , V_63 ) ) {
case 0 :
if ( F_45 ( V_63 ) ) {
unsigned int V_65 = F_46 ( V_2 ) ;
if ( ! F_47 ( V_63 ) &&
F_48 ( V_2 , V_62 , V_63 , false ) ==
V_66 ) {
F_49 ( V_63 ) ;
V_21 -> V_18 = F_16 ( V_9 ) ;
F_10 ( V_7 ) ;
V_21 -> V_67 ++ ;
V_21 -> V_68 += V_65 ;
return V_66 ;
}
F_49 ( V_63 ) ;
}
if ( F_43 ( F_8 ( V_7 , 0 ) ) )
V_57 = 1 ;
break;
case 1 :
V_21 -> V_18 = F_16 ( V_9 ) ;
return V_66 ;
default:
V_58 = 1 ;
break;
}
F_50 ( V_2 , F_51 ( V_2 ) ) ;
} while ( ( V_9 = F_16 ( V_9 ) ) != V_56 );
if ( V_58 && V_38 == NULL ) {
V_38 = V_2 ;
goto V_60;
}
if ( V_57 ) {
F_52 ( V_7 ) ;
return V_69 ;
}
V_21 -> V_70 ++ ;
V_61:
V_21 -> V_71 ++ ;
F_53 ( V_2 ) ;
return V_66 ;
}
static int F_54 ( struct V_6 * V_7 )
{
struct V_3 * V_9 ;
struct V_20 * V_16 = F_41 ( V_7 ) ;
int V_35 = 0xFFFE ;
unsigned int V_30 = V_72 | V_34 ;
if ( V_16 -> V_18 == NULL )
return - V_73 ;
V_30 = V_37 ;
V_9 = V_16 -> V_18 ;
do {
struct V_6 * V_62 = F_2 ( V_9 ) ;
if ( V_62 == NULL )
return - V_73 ;
if ( V_62 -> V_35 < V_35 )
V_35 = V_62 -> V_35 ;
if ( V_62 -> V_27 > V_74 )
return - V_28 ;
if ( ! ( V_62 -> V_30 & V_32 ) )
V_30 &= ~ V_32 ;
if ( ! ( V_62 -> V_30 & V_33 ) )
V_30 &= ~ V_33 ;
if ( ! ( V_62 -> V_30 & V_34 ) )
V_30 &= ~ V_34 ;
} while ( ( V_9 = F_16 ( V_9 ) ) != V_16 -> V_18 );
V_16 -> V_7 -> V_35 = V_35 ;
V_16 -> V_7 -> V_30 = ( V_16 -> V_7 -> V_30 & ~ V_37 ) | V_30 ;
F_55 ( V_16 -> V_7 ) ;
return 0 ;
}
static int F_56 ( struct V_6 * V_7 )
{
F_52 ( V_7 ) ;
return 0 ;
}
static struct V_75 * F_57 ( struct V_6 * V_7 ,
struct V_75 * V_76 )
{
struct V_20 * V_16 = F_41 ( V_7 ) ;
V_76 -> V_67 = V_16 -> V_67 ;
V_76 -> V_68 = V_16 -> V_68 ;
V_76 -> V_70 = V_16 -> V_70 ;
V_76 -> V_71 = V_16 -> V_71 ;
return V_76 ;
}
static int F_58 ( struct V_6 * V_7 , int V_77 )
{
struct V_20 * V_16 = F_41 ( V_7 ) ;
struct V_3 * V_9 ;
V_9 = V_16 -> V_18 ;
if ( V_9 ) {
do {
if ( V_77 > F_2 ( V_9 ) -> V_35 )
return - V_28 ;
} while ( ( V_9 = F_16 ( V_9 ) ) != V_16 -> V_18 );
}
V_7 -> V_35 = V_77 ;
return 0 ;
}
static T_3 void F_59 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = F_41 ( V_7 ) ;
struct V_78 * V_26 = & V_21 -> V_79 ;
V_21 -> V_7 = V_7 ;
V_26 -> V_80 = sizeof( struct V_8 ) ;
V_26 -> V_81 = F_1 ;
V_26 -> V_82 = F_6 ;
V_26 -> V_83 = F_12 ;
V_26 -> V_84 = F_22 ;
V_26 -> V_85 = F_13 ;
V_26 -> V_86 = F_15 ;
V_26 -> V_87 = V_88 ;
V_7 -> V_89 = & V_90 ;
V_7 -> type = V_91 ;
V_7 -> V_35 = 1500 ;
V_7 -> V_92 = 68 ;
V_7 -> V_93 = 65535 ;
V_7 -> V_11 = 100 ;
V_7 -> V_30 = V_72 ;
V_7 -> V_27 = V_74 ;
F_60 ( V_7 ) ;
}
static int T_3 F_61 ( void )
{
int V_94 ;
int V_43 = - V_54 ;
for ( V_94 = 0 ; V_94 < V_95 ; V_94 ++ ) {
struct V_6 * V_7 ;
struct V_20 * V_21 ;
V_7 = F_62 ( sizeof( struct V_20 ) , L_1 ,
V_96 , F_59 ) ;
if ( ! V_7 ) {
V_43 = - V_97 ;
break;
}
if ( ( V_43 = F_63 ( V_7 ) ) ) {
F_64 ( V_7 ) ;
break;
}
V_21 = F_41 ( V_7 ) ;
F_65 ( V_21 -> V_79 . V_98 , V_7 -> V_99 , V_100 ) ;
V_43 = F_66 ( & V_21 -> V_79 ) ;
if ( V_43 ) {
F_67 ( V_7 ) ;
F_64 ( V_7 ) ;
break;
}
F_68 ( & V_21 -> V_101 , & V_102 ) ;
}
return V_94 ? 0 : V_43 ;
}
static void T_4 F_69 ( void )
{
struct V_20 * V_21 , * V_103 ;
F_70 (master, nxt, &master_dev_list, master_list) {
F_71 ( & V_21 -> V_101 ) ;
F_72 ( & V_21 -> V_79 ) ;
F_67 ( V_21 -> V_7 ) ;
F_64 ( V_21 -> V_7 ) ;
}
}
