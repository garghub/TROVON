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
struct V_3 * V_8 ;
V_2 = F_7 ( & V_12 -> V_8 ) ;
V_14 = F_8 ( V_12 -> V_15 -> V_6 , 0 ) ;
V_8 = F_9 ( V_14 -> V_16 ) ;
if ( V_2 == NULL ) {
struct V_5 * V_15 = F_2 ( V_8 ) ;
if ( V_15 ) {
V_12 -> V_15 -> V_17 = V_4 ;
F_10 ( V_15 ) ;
}
} else {
F_11 ( V_4 , V_2 ) ;
}
V_4 -> V_8 . V_9 = V_12 -> V_8 . V_9 + V_8 -> V_8 . V_9 ;
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
struct V_7 * V_12 = F_3 ( V_4 ) ;
F_14 ( & V_12 -> V_8 ) ;
V_4 -> V_8 . V_9 = 0 ;
}
static void
F_15 ( struct V_3 * V_4 )
{
struct V_3 * V_8 , * V_18 ;
struct V_7 * V_12 = F_3 ( V_4 ) ;
struct V_19 * V_20 = V_12 -> V_15 ;
V_18 = V_20 -> V_17 ;
if ( V_18 ) {
do {
V_8 = F_16 ( V_18 ) ;
if ( V_8 == V_4 ) {
F_16 ( V_18 ) = F_16 ( V_8 ) ;
if ( V_8 == V_20 -> V_17 ) {
V_20 -> V_17 = F_16 ( V_8 ) ;
if ( V_8 == V_20 -> V_17 ) {
struct V_13 * V_21 ;
T_1 * V_22 ;
V_21 = F_8 ( V_20 -> V_6 , 0 ) ;
V_20 -> V_17 = NULL ;
V_22 = F_17 ( F_18 ( V_21 -> V_16 ) ) ;
F_19 ( V_22 ) ;
F_20 ( F_18 ( V_21 -> V_16 ) ) ;
F_21 ( V_22 ) ;
}
}
F_14 ( & V_12 -> V_8 ) ;
break;
}
} while ( ( V_18 = V_8 ) != V_20 -> V_17 );
}
}
static int F_22 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_19 * V_15 = (struct V_19 * ) V_4 -> V_25 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( V_6 -> V_26 > V_15 -> V_6 -> V_26 )
return - V_27 ;
if ( V_15 -> V_6 == V_6 )
return - V_28 ;
V_8 -> V_15 = V_15 ;
F_23 ( & V_8 -> V_8 ) ;
if ( V_15 -> V_17 ) {
if ( V_15 -> V_6 -> V_29 & V_30 ) {
if ( ( V_15 -> V_6 -> V_29 & V_31 &&
! ( V_6 -> V_29 & V_31 ) ) ||
( V_15 -> V_6 -> V_29 & V_32 &&
! ( V_6 -> V_29 & V_32 ) ) ||
( V_15 -> V_6 -> V_29 & V_33 &&
! ( V_6 -> V_29 & V_33 ) ) ||
V_6 -> V_34 < V_15 -> V_6 -> V_34 )
return - V_27 ;
} else {
if ( ! ( V_6 -> V_29 & V_31 ) )
V_15 -> V_6 -> V_29 &= ~ V_31 ;
if ( ! ( V_6 -> V_29 & V_32 ) )
V_15 -> V_6 -> V_29 &= ~ V_32 ;
if ( ! ( V_6 -> V_29 & V_33 ) )
V_15 -> V_6 -> V_29 &= ~ V_33 ;
if ( V_6 -> V_34 < V_15 -> V_6 -> V_34 )
V_15 -> V_6 -> V_34 = V_6 -> V_34 ;
}
V_8 -> V_35 = F_16 ( V_15 -> V_17 ) ;
F_16 ( V_15 -> V_17 ) = V_4 ;
} else {
V_8 -> V_35 = V_4 ;
V_15 -> V_17 = V_4 ;
V_15 -> V_6 -> V_34 = V_6 -> V_34 ;
V_15 -> V_6 -> V_29 = ( V_15 -> V_6 -> V_29 & ~ V_36 ) | ( V_6 -> V_29 & V_36 ) ;
}
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_1 * V_37 ,
struct V_5 * V_6 , struct V_13 * V_21 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 ;
int V_42 = 0 ;
V_41 = F_25 ( V_39 , V_2 ) ;
if ( ! V_41 )
return - V_43 ;
if ( V_39 -> V_6 != V_6 ) {
struct V_40 * V_44 ;
V_44 = F_26 ( V_41 -> V_45 , V_41 -> V_46 , V_6 ) ;
F_27 ( V_41 ) ;
if ( F_28 ( V_44 ) )
return F_29 ( V_44 ) ;
V_41 = V_44 ;
}
if ( F_30 ( V_41 , V_37 ) == 0 ) {
int V_42 ;
char V_47 [ V_48 ] ;
F_31 ( V_47 , V_41 , V_6 ) ;
V_42 = F_32 ( V_2 , V_6 , F_33 ( F_34 ( V_2 ) ) ,
V_47 , NULL , V_2 -> V_49 ) ;
if ( V_42 < 0 )
V_42 = - V_27 ;
} else {
V_42 = ( V_37 == NULL ) ? - V_50 : 1 ;
}
F_27 ( V_41 ) ;
return V_42 ;
}
static inline int F_35 ( struct V_1 * V_2 ,
struct V_1 * V_37 ,
struct V_5 * V_6 ,
struct V_13 * V_21 )
{
struct V_38 * V_39 = F_36 ( V_2 ) ;
int V_51 ;
if ( F_37 ( V_21 -> V_16 ) == & V_52 )
return - V_53 ;
if ( ! V_6 -> V_54 || ! V_39 )
return 0 ;
F_38 () ;
V_51 = F_24 ( V_2 , V_37 , V_6 , V_21 , V_39 ) ;
F_39 () ;
return V_51 ;
}
static T_2 F_40 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_19 * V_20 = F_41 ( V_6 ) ;
struct V_3 * V_55 , * V_8 ;
int V_56 ;
int V_57 ;
int V_58 = F_42 ( V_2 ) ;
struct V_1 * V_37 = NULL ;
V_55 = V_20 -> V_17 ;
V_59:
V_57 = 0 ;
V_56 = 0 ;
V_8 = V_55 ;
if ( ! V_8 )
goto V_60;
do {
struct V_5 * V_61 = F_2 ( V_8 ) ;
struct V_13 * V_62 = F_8 ( V_61 , 0 ) ;
if ( V_62 -> V_63 != V_8 )
continue;
if ( F_43 ( F_8 ( V_61 , V_58 ) ) ||
! F_44 ( V_61 ) ) {
V_56 = 1 ;
continue;
}
switch ( F_35 ( V_2 , V_37 , V_61 , V_62 ) ) {
case 0 :
if ( F_45 ( V_62 ) ) {
unsigned int V_64 = F_46 ( V_2 ) ;
if ( ! F_47 ( V_62 ) &&
F_48 ( V_2 , V_61 , V_62 , false ) ==
V_65 ) {
F_49 ( V_62 ) ;
V_20 -> V_17 = F_16 ( V_8 ) ;
F_10 ( V_6 ) ;
V_20 -> V_66 ++ ;
V_20 -> V_67 += V_64 ;
return V_65 ;
}
F_49 ( V_62 ) ;
}
if ( F_43 ( F_8 ( V_6 , 0 ) ) )
V_56 = 1 ;
break;
case 1 :
V_20 -> V_17 = F_16 ( V_8 ) ;
return V_65 ;
default:
V_57 = 1 ;
break;
}
F_50 ( V_2 , F_51 ( V_2 ) ) ;
} while ( ( V_8 = F_16 ( V_8 ) ) != V_55 );
if ( V_57 && V_37 == NULL ) {
V_37 = V_2 ;
goto V_59;
}
if ( V_56 ) {
F_52 ( V_6 ) ;
return V_68 ;
}
V_20 -> V_69 ++ ;
V_60:
V_20 -> V_70 ++ ;
F_53 ( V_2 ) ;
return V_65 ;
}
static int F_54 ( struct V_5 * V_6 )
{
struct V_3 * V_8 ;
struct V_19 * V_15 = F_41 ( V_6 ) ;
int V_34 = 0xFFFE ;
unsigned int V_29 = V_71 | V_33 ;
if ( V_15 -> V_17 == NULL )
return - V_72 ;
V_29 = V_36 ;
V_8 = V_15 -> V_17 ;
do {
struct V_5 * V_61 = F_2 ( V_8 ) ;
if ( V_61 == NULL )
return - V_72 ;
if ( V_61 -> V_34 < V_34 )
V_34 = V_61 -> V_34 ;
if ( V_61 -> V_26 > V_73 )
return - V_27 ;
if ( ! ( V_61 -> V_29 & V_31 ) )
V_29 &= ~ V_31 ;
if ( ! ( V_61 -> V_29 & V_32 ) )
V_29 &= ~ V_32 ;
if ( ! ( V_61 -> V_29 & V_33 ) )
V_29 &= ~ V_33 ;
} while ( ( V_8 = F_16 ( V_8 ) ) != V_15 -> V_17 );
V_15 -> V_6 -> V_34 = V_34 ;
V_15 -> V_6 -> V_29 = ( V_15 -> V_6 -> V_29 & ~ V_36 ) | V_29 ;
F_55 ( V_15 -> V_6 ) ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
return 0 ;
}
static struct V_74 * F_57 ( struct V_5 * V_6 ,
struct V_74 * V_75 )
{
struct V_19 * V_15 = F_41 ( V_6 ) ;
V_75 -> V_66 = V_15 -> V_66 ;
V_75 -> V_67 = V_15 -> V_67 ;
V_75 -> V_69 = V_15 -> V_69 ;
V_75 -> V_70 = V_15 -> V_70 ;
return V_75 ;
}
static int F_58 ( struct V_5 * V_6 , int V_76 )
{
struct V_19 * V_15 = F_41 ( V_6 ) ;
struct V_3 * V_8 ;
if ( V_76 < 68 )
return - V_27 ;
V_8 = V_15 -> V_17 ;
if ( V_8 ) {
do {
if ( V_76 > F_2 ( V_8 ) -> V_34 )
return - V_27 ;
} while ( ( V_8 = F_16 ( V_8 ) ) != V_15 -> V_17 );
}
V_6 -> V_34 = V_76 ;
return 0 ;
}
static T_3 void F_59 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_41 ( V_6 ) ;
struct V_77 * V_25 = & V_20 -> V_78 ;
V_20 -> V_6 = V_6 ;
V_25 -> V_79 = sizeof( struct V_7 ) ;
V_25 -> V_80 = F_1 ;
V_25 -> V_81 = F_6 ;
V_25 -> V_82 = F_12 ;
V_25 -> V_83 = F_22 ;
V_25 -> V_84 = F_13 ;
V_25 -> V_85 = F_15 ;
V_25 -> V_86 = V_87 ;
V_6 -> V_88 = & V_89 ;
V_6 -> type = V_90 ;
V_6 -> V_34 = 1500 ;
V_6 -> V_10 = 100 ;
V_6 -> V_29 = V_71 ;
V_6 -> V_26 = V_73 ;
F_60 ( V_6 ) ;
}
static int T_3 F_61 ( void )
{
int V_91 ;
int V_42 = - V_53 ;
for ( V_91 = 0 ; V_91 < V_92 ; V_91 ++ ) {
struct V_5 * V_6 ;
struct V_19 * V_20 ;
V_6 = F_62 ( sizeof( struct V_19 ) , L_1 ,
V_93 , F_59 ) ;
if ( ! V_6 ) {
V_42 = - V_94 ;
break;
}
if ( ( V_42 = F_63 ( V_6 ) ) ) {
F_64 ( V_6 ) ;
break;
}
V_20 = F_41 ( V_6 ) ;
F_65 ( V_20 -> V_78 . V_95 , V_6 -> V_96 , V_97 ) ;
V_42 = F_66 ( & V_20 -> V_78 ) ;
if ( V_42 ) {
F_67 ( V_6 ) ;
F_64 ( V_6 ) ;
break;
}
F_68 ( & V_20 -> V_98 , & V_99 ) ;
}
return V_91 ? 0 : V_42 ;
}
static void T_4 F_69 ( void )
{
struct V_19 * V_20 , * V_100 ;
F_70 (master, nxt, &master_dev_list, master_list) {
F_71 ( & V_20 -> V_98 ) ;
F_72 ( & V_20 -> V_78 ) ;
F_67 ( V_20 -> V_6 ) ;
F_64 ( V_20 -> V_6 ) ;
}
}
