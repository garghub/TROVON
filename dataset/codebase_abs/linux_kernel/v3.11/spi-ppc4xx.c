static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 V_7 ;
F_2 ( & V_2 -> V_8 , L_1 ,
V_4 -> V_9 , V_4 -> V_10 , V_4 -> V_11 ) ;
V_6 = F_3 ( V_2 -> V_12 ) ;
V_6 -> V_13 = V_4 -> V_9 ;
V_6 -> V_14 = V_4 -> V_10 ;
V_6 -> V_11 = V_4 -> V_11 ;
V_6 -> V_15 = 0 ;
V_7 = V_6 -> V_13 ? V_6 -> V_13 [ 0 ] : 0 ;
F_4 ( & V_6 -> V_16 -> V_17 , V_7 ) ;
F_4 ( & V_6 -> V_16 -> V_18 , V_19 ) ;
F_5 ( & V_6 -> V_20 ) ;
return V_6 -> V_15 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_2 -> V_12 ) ;
struct V_21 * V_22 = V_2 -> V_23 ;
int V_24 ;
T_1 V_25 = 0 ;
T_2 V_26 ;
T_1 V_27 ;
V_27 = V_2 -> V_27 ;
V_26 = V_2 -> V_28 ;
if ( V_4 ) {
if ( V_4 -> V_27 )
V_27 = V_4 -> V_27 ;
if ( V_4 -> V_29 )
V_26 = F_7 ( V_4 -> V_29 , V_2 -> V_28 ) ;
}
if ( ! V_26 || ( V_26 > V_2 -> V_28 ) ) {
F_8 ( & V_2 -> V_8 , L_2 , V_26 ) ;
return - V_30 ;
}
F_4 ( & V_6 -> V_16 -> V_31 , V_22 -> V_31 ) ;
V_24 = ( V_6 -> V_32 / V_26 ) - 1 ;
if ( V_24 > 0 )
V_25 = F_7 ( V_24 , 0xff ) ;
F_2 ( & V_2 -> V_8 , L_3 , V_25 , V_26 ) ;
if ( F_9 ( & V_6 -> V_16 -> V_25 ) != V_25 )
F_4 ( & V_6 -> V_16 -> V_25 , V_25 ) ;
F_10 ( & V_6 -> V_33 . V_34 ) ;
if ( ! V_6 -> V_33 . V_35 ) {
V_6 -> V_33 . V_36 ( V_2 , V_37 ) ;
}
F_11 ( & V_6 -> V_33 . V_34 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 ;
if ( ! V_2 -> V_28 ) {
F_8 ( & V_2 -> V_8 , L_4 ) ;
return - V_30 ;
}
if ( V_22 == NULL ) {
V_22 = F_13 ( sizeof *V_22 , V_38 ) ;
if ( ! V_22 )
return - V_39 ;
V_2 -> V_23 = V_22 ;
}
V_22 -> V_31 = V_40 ;
switch ( V_2 -> V_31 & ( V_41 | V_42 ) ) {
case V_43 :
V_22 -> V_31 |= V_44 ;
break;
case V_45 :
V_22 -> V_31 |= V_46 ;
break;
case V_47 :
V_22 -> V_31 |= V_48 ;
break;
case V_49 :
V_22 -> V_31 |= V_50 ;
break;
}
if ( V_2 -> V_31 & V_51 )
V_22 -> V_31 |= V_52 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , int V_53 )
{
struct V_5 * V_6 = F_3 ( V_2 -> V_12 ) ;
unsigned int V_22 = V_2 -> V_54 ;
unsigned int V_55 ;
if ( ! V_6 -> V_12 -> V_56 || V_6 -> V_57 [ V_22 ] == - V_58 )
return;
V_55 = V_2 -> V_31 & V_59 ? 1 : 0 ;
if ( V_53 == V_37 )
V_55 = ! V_55 ;
F_15 ( V_6 -> V_57 [ V_22 ] , V_55 ) ;
}
static T_3 F_16 ( int V_60 , void * V_61 )
{
struct V_5 * V_6 ;
T_1 V_62 ;
T_1 V_7 ;
unsigned int V_15 ;
V_6 = (struct V_5 * ) V_61 ;
V_62 = F_9 ( & V_6 -> V_16 -> V_63 ) ;
if ( ! V_62 )
return V_64 ;
if ( F_17 ( V_62 & V_65 ) ) {
T_1 V_66 ;
int V_67 = 0 ;
F_2 ( V_6 -> V_8 , L_5 ) ;
do {
F_18 ( 10 ) ;
V_66 = F_9 ( & V_6 -> V_16 -> V_63 ) ;
} while ( ++ V_67 < 100 && V_66 & V_65 );
if ( V_67 >= 100 ) {
F_8 ( V_6 -> V_8 , L_6 ) ;
F_19 ( & V_6 -> V_20 ) ;
return V_68 ;
} else {
V_62 = F_9 ( & V_6 -> V_16 -> V_63 ) ;
F_2 ( V_6 -> V_8 , L_7 , V_67 , V_62 ) ;
}
}
V_15 = V_6 -> V_15 ;
V_6 -> V_15 ++ ;
V_7 = F_9 ( & V_6 -> V_16 -> V_69 ) ;
if ( V_6 -> V_14 )
V_6 -> V_14 [ V_15 ] = V_7 ;
V_15 ++ ;
if ( V_15 < V_6 -> V_11 ) {
V_7 = V_6 -> V_13 ? V_6 -> V_13 [ V_15 ] : 0 ;
F_4 ( & V_6 -> V_16 -> V_17 , V_7 ) ;
F_4 ( & V_6 -> V_16 -> V_18 , V_19 ) ;
} else {
F_19 ( & V_6 -> V_20 ) ;
}
return V_68 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_23 ) ;
}
static void F_22 ( struct V_5 * V_6 )
{
F_23 ( V_70 , V_71 , 0x80000000 >> 14 , 0 ) ;
}
static void F_24 ( struct V_5 * V_6 )
{
if ( V_6 -> V_12 -> V_56 ) {
int V_72 ;
for ( V_72 = 0 ; V_72 < V_6 -> V_12 -> V_56 ; V_72 ++ )
if ( F_25 ( V_6 -> V_57 [ V_72 ] ) )
F_26 ( V_6 -> V_57 [ V_72 ] ) ;
F_21 ( V_6 -> V_57 ) ;
V_6 -> V_57 = NULL ;
}
}
static int F_27 ( struct V_73 * V_74 )
{
struct V_5 * V_6 ;
struct V_75 * V_12 ;
struct V_76 * V_77 ;
struct V_78 V_78 ;
struct V_79 * V_80 = V_74 -> V_8 . V_81 ;
struct V_82 * V_8 = & V_74 -> V_8 ;
struct V_79 * V_83 ;
int V_84 ;
int V_85 ;
const unsigned int * V_86 ;
V_12 = F_28 ( V_8 , sizeof *V_6 ) ;
if ( V_12 == NULL )
return - V_39 ;
V_12 -> V_8 . V_81 = V_80 ;
F_29 ( V_74 , V_12 ) ;
V_6 = F_3 ( V_12 ) ;
V_6 -> V_12 = F_30 ( V_12 ) ;
V_6 -> V_8 = V_8 ;
F_31 ( & V_6 -> V_20 ) ;
V_85 = F_32 ( V_80 ) ;
if ( V_85 > 0 ) {
int V_72 ;
V_6 -> V_57 = F_13 ( sizeof( int ) * V_85 , V_38 ) ;
if ( ! V_6 -> V_57 ) {
V_84 = - V_39 ;
goto V_87;
}
for ( V_72 = 0 ; V_72 < V_85 ; V_72 ++ ) {
int V_88 ;
enum V_89 V_90 ;
V_88 = F_33 ( V_80 , V_72 , & V_90 ) ;
V_6 -> V_57 [ V_72 ] = V_88 ;
if ( F_25 ( V_88 ) ) {
V_84 = F_34 ( V_88 , V_80 -> V_91 ) ;
if ( V_84 < 0 ) {
F_8 ( V_8 , L_8
L_9 , V_72 , V_84 ) ;
goto F_24;
}
F_35 ( V_88 ,
! ! ( V_90 & V_92 ) ) ;
} else if ( V_88 == - V_58 ) {
;
} else {
F_8 ( V_8 , L_10 , V_72 , V_88 ) ;
V_84 = - V_30 ;
goto F_24;
}
}
}
V_77 = & V_6 -> V_33 ;
V_77 -> V_12 = V_6 -> V_12 ;
V_77 -> V_93 = F_6 ;
V_77 -> V_36 = F_14 ;
V_77 -> V_94 = F_1 ;
V_77 -> V_95 = 0 ;
V_77 -> V_12 -> V_96 = F_12 ;
V_77 -> V_12 -> V_97 = F_20 ;
V_77 -> V_12 -> V_98 = F_36 ( 8 ) ;
V_77 -> V_12 -> V_99 =
V_41 | V_42 | V_59 | V_51 ;
V_77 -> V_12 -> V_56 = V_85 > 0 ? V_85 : 0 ;
V_83 = F_37 ( NULL , NULL , L_11 ) ;
if ( V_83 == NULL ) {
F_8 ( V_8 , L_12 ) ;
V_84 = - V_100 ;
goto F_24;
}
V_86 = F_38 ( V_83 , L_13 , NULL ) ;
if ( V_86 == NULL ) {
F_8 ( V_8 , L_14 ) ;
F_39 ( V_83 ) ;
V_84 = - V_100 ;
goto F_24;
}
V_6 -> V_32 = * V_86 ;
V_6 -> V_32 >>= 2 ;
F_39 ( V_83 ) ;
V_84 = F_40 ( V_80 , 0 , & V_78 ) ;
if ( V_84 ) {
F_8 ( V_8 , L_15 ) ;
goto F_24;
}
V_6 -> V_101 = V_78 . V_102 ;
V_6 -> V_103 = F_41 ( & V_78 ) ;
if ( V_6 -> V_103 < sizeof( struct V_104 ) ) {
F_8 ( V_8 , L_16 ) ;
V_84 = - V_30 ;
goto F_24;
}
V_6 -> V_105 = F_42 ( V_80 , 0 ) ;
V_84 = F_43 ( V_6 -> V_105 , F_16 ,
0 , L_17 , ( void * ) V_6 ) ;
if ( V_84 ) {
F_8 ( V_8 , L_18 ) ;
goto F_24;
}
if ( ! F_44 ( V_6 -> V_101 , V_6 -> V_103 , V_106 ) ) {
F_8 ( V_8 , L_19 ) ;
V_84 = - V_107 ;
goto V_108;
}
V_6 -> V_16 = F_45 ( V_6 -> V_101 , sizeof( struct V_104 ) ) ;
if ( ! V_6 -> V_16 ) {
F_8 ( V_8 , L_20 ) ;
V_84 = - V_109 ;
goto V_110;
}
F_22 ( V_6 ) ;
V_8 -> V_111 = 0 ;
V_84 = F_46 ( V_77 ) ;
if ( V_84 ) {
F_8 ( V_8 , L_21 ) ;
goto V_112;
}
F_47 ( V_8 , L_22 ) ;
return 0 ;
V_112:
F_48 ( V_6 -> V_16 ) ;
V_110:
F_49 ( V_6 -> V_101 , V_6 -> V_103 ) ;
V_108:
F_50 ( V_6 -> V_105 , V_6 ) ;
F_24:
F_24 ( V_6 ) ;
V_87:
F_51 ( V_12 ) ;
F_8 ( V_8 , L_23 ) ;
return V_84 ;
}
static int F_52 ( struct V_73 * V_74 )
{
struct V_75 * V_12 = F_53 ( V_74 ) ;
struct V_5 * V_6 = F_3 ( V_12 ) ;
F_54 ( & V_6 -> V_33 ) ;
F_49 ( V_6 -> V_101 , V_6 -> V_103 ) ;
F_50 ( V_6 -> V_105 , V_6 ) ;
F_48 ( V_6 -> V_16 ) ;
F_24 ( V_6 ) ;
return 0 ;
}
