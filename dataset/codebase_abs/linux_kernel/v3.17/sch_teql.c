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
}
static void
F_16 ( struct V_3 * V_4 )
{
struct V_3 * V_8 , * V_20 ;
struct V_7 * V_12 = F_3 ( V_4 ) ;
struct V_21 * V_22 = V_12 -> V_15 ;
V_20 = V_22 -> V_17 ;
if ( V_20 ) {
do {
V_8 = F_17 ( V_20 ) ;
if ( V_8 == V_4 ) {
F_17 ( V_20 ) = F_17 ( V_8 ) ;
if ( V_8 == V_22 -> V_17 ) {
V_22 -> V_17 = F_17 ( V_8 ) ;
if ( V_8 == V_22 -> V_17 ) {
struct V_13 * V_23 ;
T_1 * V_24 ;
V_23 = F_8 ( V_22 -> V_6 , 0 ) ;
V_22 -> V_17 = NULL ;
V_24 = F_18 ( V_23 -> V_16 ) ;
F_19 ( V_24 ) ;
F_20 ( V_23 -> V_16 ) ;
F_21 ( V_24 ) ;
}
}
F_15 ( & V_12 -> V_8 ) ;
break;
}
} while ( ( V_20 = V_8 ) != V_22 -> V_17 );
}
}
static int F_22 ( struct V_3 * V_4 , struct V_25 * V_26 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_21 * V_15 = (struct V_21 * ) V_4 -> V_27 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( V_6 -> V_28 > V_15 -> V_6 -> V_28 )
return - V_29 ;
if ( V_15 -> V_6 == V_6 )
return - V_30 ;
V_8 -> V_15 = V_15 ;
F_23 ( & V_8 -> V_8 ) ;
if ( V_15 -> V_17 ) {
if ( V_15 -> V_6 -> V_31 & V_32 ) {
if ( ( V_15 -> V_6 -> V_31 & V_33 &&
! ( V_6 -> V_31 & V_33 ) ) ||
( V_15 -> V_6 -> V_31 & V_34 &&
! ( V_6 -> V_31 & V_34 ) ) ||
( V_15 -> V_6 -> V_31 & V_35 &&
! ( V_6 -> V_31 & V_35 ) ) ||
V_6 -> V_36 < V_15 -> V_6 -> V_36 )
return - V_29 ;
} else {
if ( ! ( V_6 -> V_31 & V_33 ) )
V_15 -> V_6 -> V_31 &= ~ V_33 ;
if ( ! ( V_6 -> V_31 & V_34 ) )
V_15 -> V_6 -> V_31 &= ~ V_34 ;
if ( ! ( V_6 -> V_31 & V_35 ) )
V_15 -> V_6 -> V_31 &= ~ V_35 ;
if ( V_6 -> V_36 < V_15 -> V_6 -> V_36 )
V_15 -> V_6 -> V_36 = V_6 -> V_36 ;
}
V_8 -> V_37 = F_17 ( V_15 -> V_17 ) ;
F_17 ( V_15 -> V_17 ) = V_4 ;
} else {
V_8 -> V_37 = V_4 ;
V_15 -> V_17 = V_4 ;
V_15 -> V_6 -> V_36 = V_6 -> V_36 ;
V_15 -> V_6 -> V_31 = ( V_15 -> V_6 -> V_31 & ~ V_38 ) | ( V_6 -> V_31 & V_38 ) ;
}
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_1 * V_39 ,
struct V_5 * V_6 , struct V_13 * V_23 ,
struct V_40 * V_41 )
{
struct V_18 * V_19 ;
int V_42 = 0 ;
V_19 = F_25 ( V_41 , V_2 ) ;
if ( ! V_19 )
return - V_43 ;
if ( V_41 -> V_6 != V_6 ) {
struct V_18 * V_44 ;
V_44 = F_26 ( V_19 -> V_45 , V_19 -> V_46 , V_6 ) ;
F_13 ( V_19 ) ;
if ( F_27 ( V_44 ) )
return F_28 ( V_44 ) ;
V_19 = V_44 ;
}
if ( F_29 ( V_19 , V_39 ) == 0 ) {
int V_42 ;
char V_47 [ V_48 ] ;
F_30 ( V_47 , V_19 , V_6 ) ;
V_42 = F_31 ( V_2 , V_6 , F_32 ( V_2 -> V_49 ) , V_47 ,
NULL , V_2 -> V_50 ) ;
if ( V_42 < 0 )
V_42 = - V_29 ;
} else {
V_42 = ( V_39 == NULL ) ? - V_51 : 1 ;
}
F_13 ( V_19 ) ;
return V_42 ;
}
static inline int F_33 ( struct V_1 * V_2 ,
struct V_1 * V_39 ,
struct V_5 * V_6 ,
struct V_13 * V_23 )
{
struct V_40 * V_41 = F_34 ( V_2 ) ;
int V_52 ;
if ( V_23 -> V_16 == & V_53 )
return - V_54 ;
if ( ! V_6 -> V_55 || ! V_41 )
return 0 ;
F_35 () ;
V_52 = F_24 ( V_2 , V_39 , V_6 , V_23 , V_41 ) ;
F_36 () ;
return V_52 ;
}
static T_2 F_37 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_21 * V_22 = F_38 ( V_6 ) ;
struct V_3 * V_56 , * V_8 ;
int V_57 ;
int V_58 ;
int V_59 = F_39 ( V_2 ) ;
struct V_1 * V_39 = NULL ;
V_56 = V_22 -> V_17 ;
V_60:
V_58 = 0 ;
V_57 = 0 ;
V_8 = V_56 ;
if ( ! V_8 )
goto V_61;
do {
struct V_5 * V_62 = F_2 ( V_8 ) ;
struct V_13 * V_63 = F_8 ( V_62 , 0 ) ;
const struct V_64 * V_65 = V_62 -> V_66 ;
if ( V_63 -> V_67 != V_8 )
continue;
if ( F_40 ( F_8 ( V_62 , V_59 ) ) ||
! F_41 ( V_62 ) ) {
V_57 = 1 ;
continue;
}
switch ( F_33 ( V_2 , V_39 , V_62 , V_63 ) ) {
case 0 :
if ( F_42 ( V_63 ) ) {
unsigned int V_68 = F_43 ( V_2 ) ;
if ( ! F_44 ( V_63 ) &&
V_65 -> V_69 ( V_2 , V_62 ) == V_70 ) {
F_45 ( V_63 ) ;
F_46 ( V_63 ) ;
V_22 -> V_17 = F_17 ( V_8 ) ;
F_9 ( V_6 ) ;
V_22 -> V_71 ++ ;
V_22 -> V_72 += V_68 ;
return V_70 ;
}
F_46 ( V_63 ) ;
}
if ( F_40 ( F_8 ( V_6 , 0 ) ) )
V_57 = 1 ;
break;
case 1 :
V_22 -> V_17 = F_17 ( V_8 ) ;
return V_70 ;
default:
V_58 = 1 ;
break;
}
F_47 ( V_2 , F_48 ( V_2 ) ) ;
} while ( ( V_8 = F_17 ( V_8 ) ) != V_56 );
if ( V_58 && V_39 == NULL ) {
V_39 = V_2 ;
goto V_60;
}
if ( V_57 ) {
F_49 ( V_6 ) ;
return V_73 ;
}
V_22 -> V_74 ++ ;
V_61:
V_22 -> V_75 ++ ;
F_50 ( V_2 ) ;
return V_70 ;
}
static int F_51 ( struct V_5 * V_6 )
{
struct V_3 * V_8 ;
struct V_21 * V_15 = F_38 ( V_6 ) ;
int V_36 = 0xFFFE ;
unsigned int V_31 = V_76 | V_35 ;
if ( V_15 -> V_17 == NULL )
return - V_77 ;
V_31 = V_38 ;
V_8 = V_15 -> V_17 ;
do {
struct V_5 * V_62 = F_2 ( V_8 ) ;
if ( V_62 == NULL )
return - V_77 ;
if ( V_62 -> V_36 < V_36 )
V_36 = V_62 -> V_36 ;
if ( V_62 -> V_28 > V_78 )
return - V_29 ;
if ( ! ( V_62 -> V_31 & V_33 ) )
V_31 &= ~ V_33 ;
if ( ! ( V_62 -> V_31 & V_34 ) )
V_31 &= ~ V_34 ;
if ( ! ( V_62 -> V_31 & V_35 ) )
V_31 &= ~ V_35 ;
} while ( ( V_8 = F_17 ( V_8 ) ) != V_15 -> V_17 );
V_15 -> V_6 -> V_36 = V_36 ;
V_15 -> V_6 -> V_31 = ( V_15 -> V_6 -> V_31 & ~ V_38 ) | V_31 ;
F_52 ( V_15 -> V_6 ) ;
return 0 ;
}
static int F_53 ( struct V_5 * V_6 )
{
F_49 ( V_6 ) ;
return 0 ;
}
static struct V_79 * F_54 ( struct V_5 * V_6 ,
struct V_79 * V_80 )
{
struct V_21 * V_15 = F_38 ( V_6 ) ;
V_80 -> V_71 = V_15 -> V_71 ;
V_80 -> V_72 = V_15 -> V_72 ;
V_80 -> V_74 = V_15 -> V_74 ;
V_80 -> V_75 = V_15 -> V_75 ;
return V_80 ;
}
static int F_55 ( struct V_5 * V_6 , int V_81 )
{
struct V_21 * V_15 = F_38 ( V_6 ) ;
struct V_3 * V_8 ;
if ( V_81 < 68 )
return - V_29 ;
V_8 = V_15 -> V_17 ;
if ( V_8 ) {
do {
if ( V_81 > F_2 ( V_8 ) -> V_36 )
return - V_29 ;
} while ( ( V_8 = F_17 ( V_8 ) ) != V_15 -> V_17 );
}
V_6 -> V_36 = V_81 ;
return 0 ;
}
static T_3 void F_56 ( struct V_5 * V_6 )
{
struct V_21 * V_22 = F_38 ( V_6 ) ;
struct V_82 * V_27 = & V_22 -> V_83 ;
V_22 -> V_6 = V_6 ;
V_27 -> V_84 = sizeof( struct V_7 ) ;
V_27 -> V_85 = F_1 ;
V_27 -> V_86 = F_6 ;
V_27 -> V_87 = F_11 ;
V_27 -> V_88 = F_22 ;
V_27 -> V_89 = F_14 ;
V_27 -> V_90 = F_16 ;
V_27 -> V_91 = V_92 ;
V_6 -> V_66 = & V_93 ;
V_6 -> type = V_94 ;
V_6 -> V_36 = 1500 ;
V_6 -> V_10 = 100 ;
V_6 -> V_31 = V_76 ;
V_6 -> V_28 = V_78 ;
V_6 -> V_95 &= ~ V_96 ;
}
static int T_3 F_57 ( void )
{
int V_97 ;
int V_42 = - V_54 ;
for ( V_97 = 0 ; V_97 < V_98 ; V_97 ++ ) {
struct V_5 * V_6 ;
struct V_21 * V_22 ;
V_6 = F_58 ( sizeof( struct V_21 ) , L_1 ,
V_99 , F_56 ) ;
if ( ! V_6 ) {
V_42 = - V_100 ;
break;
}
if ( ( V_42 = F_59 ( V_6 ) ) ) {
F_60 ( V_6 ) ;
break;
}
V_22 = F_38 ( V_6 ) ;
F_61 ( V_22 -> V_83 . V_101 , V_6 -> V_102 , V_103 ) ;
V_42 = F_62 ( & V_22 -> V_83 ) ;
if ( V_42 ) {
F_63 ( V_6 ) ;
F_60 ( V_6 ) ;
break;
}
F_64 ( & V_22 -> V_104 , & V_105 ) ;
}
return V_97 ? 0 : V_42 ;
}
static void T_4 F_65 ( void )
{
struct V_21 * V_22 , * V_106 ;
F_66 (master, nxt, &master_dev_list, master_list) {
F_67 ( & V_22 -> V_104 ) ;
F_68 ( & V_22 -> V_83 ) ;
F_63 ( V_22 -> V_6 ) ;
F_60 ( V_22 -> V_6 ) ;
}
}
