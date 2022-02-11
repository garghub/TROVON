static T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
T_1 V_3 ;
T_2 V_4 = V_5 [ V_1 ] . V_6 ;
F_2 ( & V_7 ) ;
F_3 ( F_4 ( V_4 , V_2 ) , V_5 [ V_1 ] . V_8 + 0x800 ) ;
V_3 = F_5 ( V_5 [ V_1 ] . V_8 + F_6 ( V_2 ) ) ;
F_7 ( & V_7 ) ;
return V_3 ;
}
static void F_8 ( T_2 V_1 , T_1 V_2 , T_1 V_3 )
{
T_2 V_4 = V_5 [ V_1 ] . V_6 ;
F_2 ( & V_7 ) ;
F_3 ( F_4 ( V_4 , V_2 ) , V_5 [ V_1 ] . V_8 + 0x800 ) ;
F_3 ( V_3 , V_5 [ V_1 ] . V_8 + F_6 ( V_2 ) ) ;
F_7 ( & V_7 ) ;
}
static void F_9 ( T_2 V_1 )
{
while ( F_1 ( V_1 , V_9 ) & V_10 )
F_10 ( 5 ) ;
}
static T_1 F_11 ( T_2 V_1 , T_1 V_2 )
{
F_9 ( V_1 ) ;
F_8 ( V_1 , V_11 , V_2 ) ;
F_8 ( V_1 , V_9 , V_12 ) ;
F_9 ( V_1 ) ;
return F_1 ( V_1 , V_13 ) ;
}
static void F_12 ( T_2 V_1 , T_1 V_2 , T_1 V_3 )
{
F_9 ( V_1 ) ;
F_8 ( V_1 , V_11 , V_2 ) ;
F_8 ( V_1 , V_13 , V_3 ) ;
F_8 ( V_1 , V_9 , V_14 | V_12 ) ;
}
static void F_13 ( T_2 V_1 )
{
T_2 V_15 = V_5 [ V_1 ] . V_16 ;
T_1 V_17 ;
if ( F_14 ( V_5 [ V_1 ] . V_8 == NULL ) )
return;
V_17 = F_11 ( V_1 , V_18 + V_15 * V_19 ) ;
V_17 &= ~ V_20 ;
F_12 ( V_1 , V_21 + V_15 * V_19 , V_17 ) ;
}
static void F_15 ( T_2 V_1 , T_1 V_22 )
{
T_2 V_15 = V_5 [ V_1 ] . V_16 ;
T_1 V_17 ;
V_17 = F_11 ( V_1 , V_18 + V_15 * V_19 ) ;
V_17 &= ~ V_20 ;
F_12 ( V_1 , V_21 + V_15 * V_19 , V_17 ) ;
V_17 |= V_20 ;
F_12 ( V_1 , V_21 + V_15 * V_19 , V_17 ) ;
V_17 &= ~ V_23 ;
V_17 |= V_22 << V_24 ;
F_12 ( V_1 , V_21 + V_15 * V_19 , V_17 ) ;
V_17 |= V_25 ;
F_12 ( V_1 , V_21 + V_15 * V_19 , V_17 ) ;
V_17 &= ~ V_25 ;
F_12 ( V_1 , V_21 + V_15 * V_19 , V_17 ) ;
F_16 ( 15 ) ;
}
static void F_17 ( T_2 V_1 )
{
T_2 V_15 = V_5 [ V_1 ] . V_16 ;
T_1 V_17 , V_26 = 0 ;
if ( F_14 ( V_5 [ V_1 ] . V_8 == NULL ) )
return;
do {
V_17 = F_11 ( V_1 , V_18 +
V_15 * V_19 ) ;
} while ( ( V_17 & V_27 ) && ( V_26 ++ < 1000 ) );
F_15 ( V_1 , 3 ) ;
}
static int F_18 ( struct V_28 * V_4 , void T_3 * V_2 )
{
struct V_29 * V_30 = V_4 -> V_31 ;
int V_32 = 0 , V_33 , V_34 = 0 ;
void T_3 * V_35 [ V_36 ] ;
struct V_29 * V_37 [ V_36 ] ;
memset ( V_5 , 0 , sizeof( struct V_38 ) * V_39 ) ;
memset ( V_37 , 0 , sizeof( struct V_29 * ) * V_36 ) ;
do {
T_1 V_17 ;
struct V_40 V_41 ;
if ( F_19 ( V_30 ,
L_1 , L_2 ,
V_34 , & V_41 ) )
break;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
if ( V_37 [ V_33 ] == V_41 . V_42 )
break;
}
if ( V_37 [ V_33 ] == NULL ) {
V_37 [ V_33 ] = V_41 . V_42 ;
V_35 [ V_33 ] = F_20 ( V_37 [ V_33 ] , 0 ) ;
if ( V_35 [ V_33 ] == NULL ) {
return 0 ;
}
V_32 += 1 ;
}
V_5 [ V_34 ] . V_16 = V_41 . args [ 0 ] ;
F_21 ( V_37 [ V_33 ] , L_3 , & V_17 ) ;
V_5 [ V_34 ] . V_6 = V_17 ;
V_5 [ V_34 ] . V_8 = V_35 [ V_33 ] ;
F_22 ( V_41 . V_42 ) ;
V_34 += 1 ;
} while ( V_34 < V_39 );
return 0 ;
}
static int F_23 ( struct V_43 * V_44 , unsigned int * V_45 ,
unsigned long V_46 )
{
const unsigned long * V_47 = F_24 ( & V_44 -> V_48 ) ;
struct V_49 * V_50 = V_44 -> V_50 ;
struct V_51 * V_52 = V_50 -> V_53 ;
T_2 * V_54 = V_52 -> V_55 + V_56 ;
struct V_57 V_58 ;
bool V_59 ;
T_1 V_60 ;
int V_61 ;
int V_62 = 10 ;
F_25 ( V_50 ) ;
F_26 ( V_44 -> V_28 , & V_58 ) ;
V_58 . V_63 = V_64 ;
F_27 ( & V_58 , 0 , 0 , V_54 ) ;
do {
F_13 ( V_44 -> V_50 -> V_65 ) ;
V_61 = F_28 ( V_44 , V_47 , V_46 , & V_59 , NULL ) ;
F_17 ( V_44 -> V_50 -> V_65 ) ;
if ( F_29 ( V_44 , V_66 , & V_60 ) )
break;
if ( ! ( V_60 & 0x3 ) )
break;
} while ( ! V_59 && V_62 -- );
F_30 ( V_50 ) ;
if ( V_59 )
* V_45 = F_31 ( V_50 ) ;
return V_61 ;
}
static int F_32 ( struct V_67 * V_68 )
{
struct V_28 * V_4 = & V_68 -> V_4 ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
struct V_73 * V_74 ;
int V_75 ;
int V_76 ;
int V_77 ;
int V_61 ;
struct V_78 V_79 = V_80 ;
const struct V_78 * V_81 [] = { & V_79 , NULL } ;
V_74 = F_33 ( V_68 , V_82 , 0 ) ;
if ( ! V_74 ) {
F_34 ( V_4 , L_4 ) ;
return - V_83 ;
}
V_75 = F_35 ( V_68 , 0 ) ;
if ( V_75 <= 0 ) {
F_34 ( V_4 , L_5 ) ;
return - V_83 ;
}
V_70 = F_36 ( V_4 , sizeof( * V_70 ) , V_84 ) ;
if ( ! V_70 ) {
F_34 ( V_4 , L_6 ) ;
return - V_85 ;
}
V_70 -> V_86 |= ( unsigned long ) V_79 . V_53 ;
V_70 -> V_87 = F_37 ( V_4 , V_74 -> V_88 , F_38 ( V_74 ) ) ;
if ( ! V_70 -> V_87 ) {
F_34 ( V_4 , L_7 , V_74 ) ;
return - V_85 ;
}
V_61 = F_18 ( V_4 , V_70 -> V_87 ) ;
if ( V_61 )
return V_61 ;
F_39 ( V_4 , V_70 , 0 , 0 ) ;
if ( V_70 -> V_89 & V_90 )
V_79 . V_86 |= V_91 ;
if ( V_70 -> V_89 & V_92 )
V_79 . V_86 |= V_93 ;
F_40 ( V_70 , & V_79 ) ;
V_76 = F_41 ( F_42 ( V_70 -> V_89 ) , F_43 ( V_70 -> V_94 ) ) ;
V_72 = F_44 ( V_4 , V_81 , V_76 ) ;
if ( ! V_72 ) {
V_61 = - V_85 ;
goto V_95;
}
V_72 -> V_53 = V_70 ;
if ( ! ( V_70 -> V_89 & V_96 ) || V_97 )
V_72 -> V_86 |= V_98 ;
if ( V_79 . V_86 & V_99 )
F_45 ( V_72 ) ;
for ( V_77 = 0 ; V_77 < V_72 -> V_76 ; V_77 ++ ) {
struct V_49 * V_50 = V_72 -> V_100 [ V_77 ] ;
F_46 ( V_50 , L_8 , V_74 ) ;
F_46 ( V_50 , L_9 , 0x100 + V_50 -> V_65 * 0x80 ) ;
if ( V_50 -> V_86 & V_99 )
V_50 -> V_101 = V_70 -> V_102 ;
if ( ! ( V_70 -> V_94 & ( 1 << V_77 ) ) )
V_50 -> V_103 = & V_104 ;
}
V_61 = F_47 ( V_72 ) ;
if ( V_61 )
goto V_95;
F_48 ( V_72 ) ;
F_49 ( V_72 , L_10 ) ;
V_61 = F_50 ( V_72 , V_75 , V_105 , 0 ,
& V_106 ) ;
if ( V_61 )
goto V_95;
return 0 ;
V_95:
return V_61 ;
}
static int F_51 ( struct V_28 * V_4 )
{
struct V_71 * V_72 = F_52 ( V_4 ) ;
struct V_69 * V_70 = V_72 -> V_53 ;
void T_3 * V_87 = V_70 -> V_87 ;
T_1 V_107 ;
int V_61 ;
if ( V_70 -> V_86 & V_108 ) {
F_34 ( V_4 , L_11 ) ;
return - V_109 ;
}
V_107 = F_5 ( V_87 + V_110 ) ;
V_107 &= ~ V_111 ;
F_3 ( V_107 , V_87 + V_110 ) ;
F_5 ( V_87 + V_110 ) ;
V_61 = F_53 ( V_72 , V_112 ) ;
if ( V_61 )
return V_61 ;
return 0 ;
}
static int F_54 ( struct V_28 * V_4 )
{
struct V_71 * V_72 = F_52 ( V_4 ) ;
int V_61 ;
if ( V_4 -> V_113 . V_114 . V_115 == V_116 ) {
V_61 = F_47 ( V_72 ) ;
if ( V_61 )
return V_61 ;
F_48 ( V_72 ) ;
}
F_55 ( V_72 ) ;
return 0 ;
}
