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
V_58 . V_63 = 0x80 ;
F_27 ( & V_58 , 0 , 0 , V_54 ) ;
do {
F_13 ( V_44 -> V_50 -> V_64 ) ;
V_61 = F_28 ( V_44 , V_47 , V_46 , & V_59 , NULL ) ;
F_17 ( V_44 -> V_50 -> V_64 ) ;
if ( F_29 ( V_44 , V_65 , & V_60 ) )
break;
if ( ! ( V_60 & 0x3 ) )
break;
} while ( ! V_59 && V_62 -- );
F_30 ( V_50 ) ;
if ( V_59 )
* V_45 = F_31 ( V_50 ) ;
return V_61 ;
}
static int T_4 F_32 ( struct V_66 * V_67 )
{
struct V_28 * V_4 = & V_67 -> V_4 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
int V_74 ;
int V_75 ;
int V_76 ;
int V_61 ;
struct V_77 V_78 = V_79 ;
const struct V_77 * V_80 [] = { & V_78 , NULL } ;
V_73 = F_33 ( V_67 , V_81 , 0 ) ;
if ( ! V_73 ) {
F_34 ( V_4 , L_4 ) ;
return - V_82 ;
}
V_74 = F_35 ( V_67 , 0 ) ;
if ( V_74 <= 0 ) {
F_34 ( V_4 , L_5 ) ;
return - V_82 ;
}
V_69 = F_36 ( V_4 , sizeof( * V_69 ) , V_83 ) ;
if ( ! V_69 ) {
F_34 ( V_4 , L_6 ) ;
return - V_84 ;
}
V_69 -> V_85 |= ( unsigned long ) V_78 . V_53 ;
V_69 -> V_86 = F_37 ( V_4 , V_73 -> V_87 , F_38 ( V_73 ) ) ;
if ( ! V_69 -> V_86 ) {
F_34 ( V_4 , L_7 , V_73 ) ;
return - V_84 ;
}
V_61 = F_18 ( V_4 , V_69 -> V_86 ) ;
if ( V_61 )
return V_61 ;
F_39 ( V_4 , V_69 , 0 , 0 ) ;
if ( V_69 -> V_88 & V_89 )
V_78 . V_85 |= V_90 ;
if ( V_69 -> V_88 & V_91 )
V_78 . V_85 |= V_92 ;
F_40 ( V_69 , & V_78 ) ;
V_75 = F_41 ( F_42 ( V_69 -> V_88 ) , F_43 ( V_69 -> V_93 ) ) ;
V_71 = F_44 ( V_4 , V_80 , V_75 ) ;
if ( ! V_71 ) {
V_61 = - V_84 ;
goto V_94;
}
V_71 -> V_53 = V_69 ;
if ( ! ( V_69 -> V_88 & V_95 ) || V_96 )
V_71 -> V_85 |= V_97 ;
if ( V_78 . V_85 & V_98 )
F_45 ( V_71 ) ;
for ( V_76 = 0 ; V_76 < V_71 -> V_75 ; V_76 ++ ) {
struct V_49 * V_50 = V_71 -> V_99 [ V_76 ] ;
F_46 ( V_50 , L_8 , V_73 ) ;
F_46 ( V_50 , L_9 , 0x100 + V_50 -> V_64 * 0x80 ) ;
if ( V_50 -> V_85 & V_98 )
V_50 -> V_100 = V_69 -> V_101 ;
if ( ! ( V_69 -> V_93 & ( 1 << V_76 ) ) )
V_50 -> V_102 = & V_103 ;
}
V_61 = F_47 ( V_71 ) ;
if ( V_61 )
goto V_94;
F_48 ( V_71 ) ;
F_49 ( V_71 , L_10 ) ;
V_61 = F_50 ( V_71 , V_74 , V_104 , 0 ,
& V_105 ) ;
if ( V_61 )
goto V_94;
return 0 ;
V_94:
return V_61 ;
}
static int T_5 F_51 ( struct V_66 * V_67 )
{
struct V_28 * V_4 = & V_67 -> V_4 ;
struct V_70 * V_71 = F_52 ( V_4 ) ;
F_53 ( V_71 ) ;
return 0 ;
}
static int F_54 ( struct V_28 * V_4 )
{
struct V_70 * V_71 = F_52 ( V_4 ) ;
struct V_68 * V_69 = V_71 -> V_53 ;
void T_3 * V_86 = V_69 -> V_86 ;
T_1 V_106 ;
int V_61 ;
if ( V_69 -> V_85 & V_107 ) {
F_34 ( V_4 , L_11 ) ;
return - V_108 ;
}
V_106 = F_5 ( V_86 + V_109 ) ;
V_106 &= ~ V_110 ;
F_3 ( V_106 , V_86 + V_109 ) ;
F_5 ( V_86 + V_109 ) ;
V_61 = F_55 ( V_71 , V_111 ) ;
if ( V_61 )
return V_61 ;
return 0 ;
}
static int F_56 ( struct V_28 * V_4 )
{
struct V_70 * V_71 = F_52 ( V_4 ) ;
int V_61 ;
if ( V_4 -> V_112 . V_113 . V_114 == V_115 ) {
V_61 = F_47 ( V_71 ) ;
if ( V_61 )
return V_61 ;
F_48 ( V_71 ) ;
}
F_57 ( V_71 ) ;
return 0 ;
}
