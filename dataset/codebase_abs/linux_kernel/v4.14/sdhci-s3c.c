static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static unsigned int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_5 , V_6 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_5 = V_4 -> V_9 [ V_7 ] ;
if ( V_5 > V_6 )
V_6 = V_5 ;
}
return V_6 ;
}
static unsigned int F_4 ( struct V_1 * V_4 ,
unsigned int V_7 ,
unsigned int V_10 )
{
unsigned long V_5 ;
struct V_11 * V_12 = V_4 -> V_13 [ V_7 ] ;
int V_14 ;
if ( F_5 ( V_12 ) )
return V_15 ;
if ( V_4 -> V_16 ) {
V_5 = F_6 ( V_12 , V_10 ) ;
return V_10 - V_5 ;
}
V_5 = V_4 -> V_9 [ V_7 ] ;
for ( V_14 = 0 ; V_14 <= 8 ; ++ V_14 ) {
if ( ( V_5 >> V_14 ) <= V_10 )
break;
}
if ( V_14 > 8 ) {
F_7 ( & V_4 -> V_17 -> V_18 ,
L_1 ,
V_7 , V_5 , V_5 / 256 , V_10 ) ;
return V_15 ;
}
F_7 ( & V_4 -> V_17 -> V_18 , L_2 ,
V_7 , V_5 , V_10 , V_5 >> V_14 ) ;
return V_10 - ( V_5 >> V_14 ) ;
}
static void F_8 ( struct V_2 * V_3 , unsigned int clock )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_19 = V_15 ;
unsigned int V_20 ;
int V_21 = 0 ;
int V_7 ;
T_1 V_22 ;
V_3 -> V_23 -> V_24 = 0 ;
if ( clock == 0 ) {
F_9 ( V_3 , clock ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_20 = F_4 ( V_4 , V_7 , clock ) ;
if ( V_20 < V_19 ) {
V_19 = V_20 ;
V_21 = V_7 ;
}
}
F_7 ( & V_4 -> V_17 -> V_18 ,
L_3 ,
V_21 , clock , V_19 ) ;
if ( V_4 -> V_25 != V_21 ) {
struct V_11 * V_11 = V_4 -> V_13 [ V_21 ] ;
F_10 ( V_11 ) ;
if ( V_4 -> V_25 >= 0 )
F_11 (
V_4 -> V_13 [ V_4 -> V_25 ] ) ;
V_4 -> V_25 = V_21 ;
V_3 -> V_26 = V_4 -> V_9 [ V_21 ] ;
}
F_12 ( 0 , V_3 -> V_27 + V_28 ) ;
V_22 = F_13 ( V_3 -> V_27 + V_29 ) ;
V_22 &= ~ V_30 ;
V_22 |= V_21 << V_31 ;
F_14 ( V_22 , V_3 -> V_27 + V_29 ) ;
F_14 ( V_32 ,
V_3 -> V_27 + V_33 ) ;
V_22 = F_13 ( V_3 -> V_27 + V_29 ) ;
V_22 |= ( V_34 |
V_35 |
V_36 |
V_37 |
V_38 ) ;
F_14 ( V_22 , V_3 -> V_27 + V_29 ) ;
V_22 = ( V_39 | V_40 ) ;
if ( clock < 25 * 1000000 )
V_22 |= ( V_41 | V_42 ) ;
F_14 ( V_22 , V_3 -> V_27 + V_43 ) ;
F_9 ( V_3 , clock ) ;
}
static unsigned int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_5 , V_44 = V_45 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_5 = V_4 -> V_9 [ V_7 ] / 256 ;
if ( ! V_5 )
continue;
if ( V_5 < V_44 )
V_44 = V_5 ;
}
return V_44 ;
}
static unsigned int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_5 , V_6 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_11 * V_11 ;
V_11 = V_4 -> V_13 [ V_7 ] ;
if ( F_5 ( V_11 ) )
continue;
V_5 = F_6 ( V_11 , V_45 ) ;
if ( V_5 > V_6 )
V_6 = V_5 ;
}
return V_6 ;
}
static unsigned int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_5 , V_44 = V_45 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_11 * V_11 ;
V_11 = V_4 -> V_13 [ V_7 ] ;
if ( F_5 ( V_11 ) )
continue;
V_5 = F_6 ( V_11 , 0 ) ;
if ( V_5 < V_44 )
V_44 = V_5 ;
}
return V_44 ;
}
static void F_18 ( struct V_2 * V_3 , unsigned int clock )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_46 * V_18 = & V_4 -> V_17 -> V_18 ;
unsigned long V_47 ;
T_2 V_11 = 0 ;
int V_48 ;
V_3 -> V_23 -> V_24 = 0 ;
if ( clock == 0 ) {
F_19 ( V_3 , 0 , V_28 ) ;
return;
}
F_8 ( V_3 , clock ) ;
V_11 = F_20 ( V_3 , V_28 ) ;
V_11 &= ~ V_49 ;
F_19 ( V_3 , V_11 , V_28 ) ;
V_48 = F_21 ( V_4 -> V_13 [ V_4 -> V_25 ] , clock ) ;
if ( V_48 != 0 ) {
F_22 ( V_18 , L_4 ,
F_23 ( V_3 -> V_23 ) , clock ) ;
return;
}
V_11 = V_50 ;
F_19 ( V_3 , V_11 , V_28 ) ;
V_47 = 20 ;
while ( ! ( ( V_11 = F_20 ( V_3 , V_28 ) )
& V_51 ) ) {
if ( V_47 == 0 ) {
F_22 ( V_18 , L_5 ,
F_23 ( V_3 -> V_23 ) ) ;
return;
}
V_47 -- ;
F_24 ( 1 ) ;
}
V_11 |= V_49 ;
F_19 ( V_3 , V_11 , V_28 ) ;
}
static int F_25 ( struct V_46 * V_18 ,
struct V_2 * V_3 , struct V_52 * V_53 )
{
struct V_54 * V_55 = V_18 -> V_56 ;
T_1 V_57 ;
if ( F_26 ( V_55 , L_6 , & V_57 ) )
V_57 = 1 ;
V_53 -> V_57 = V_57 ;
if ( F_27 ( V_55 , L_7 , NULL ) ) {
V_53 -> V_58 = V_59 ;
return 0 ;
}
if ( F_27 ( V_55 , L_8 , NULL ) ) {
V_53 -> V_58 = V_60 ;
return 0 ;
}
if ( F_28 ( V_55 , L_9 , 0 ) )
return 0 ;
V_53 -> V_58 = V_61 ;
return 0 ;
}
static int F_25 ( struct V_46 * V_18 ,
struct V_2 * V_3 , struct V_52 * V_53 )
{
return - V_62 ;
}
static inline struct V_63 * F_29 (
struct V_64 * V_17 )
{
#ifdef F_30
if ( V_17 -> V_18 . V_56 ) {
const struct V_65 * V_66 ;
V_66 = F_31 ( V_67 , V_17 -> V_18 . V_56 ) ;
return (struct V_63 * ) V_66 -> V_68 ;
}
#endif
return (struct V_63 * )
F_32 ( V_17 ) -> V_69 ;
}
static int F_33 ( struct V_64 * V_17 )
{
struct V_52 * V_53 ;
struct V_63 * V_70 ;
struct V_46 * V_18 = & V_17 -> V_18 ;
struct V_2 * V_3 ;
struct V_1 * V_71 ;
struct V_72 * V_73 ;
int V_48 , V_74 , V_75 , V_76 ;
if ( ! V_17 -> V_18 . V_77 && ! V_17 -> V_18 . V_56 ) {
F_22 ( V_18 , L_10 ) ;
return - V_78 ;
}
V_74 = F_34 ( V_17 , 0 ) ;
if ( V_74 < 0 ) {
F_22 ( V_18 , L_11 ) ;
return V_74 ;
}
V_3 = F_35 ( V_18 , sizeof( struct V_1 ) ) ;
if ( F_5 ( V_3 ) ) {
F_22 ( V_18 , L_12 ) ;
return F_36 ( V_3 ) ;
}
V_71 = F_2 ( V_3 ) ;
V_53 = F_37 ( & V_17 -> V_18 , sizeof( * V_53 ) , V_79 ) ;
if ( ! V_53 ) {
V_48 = - V_80 ;
goto V_81;
}
if ( V_17 -> V_18 . V_56 ) {
V_48 = F_25 ( & V_17 -> V_18 , V_3 , V_53 ) ;
if ( V_48 )
goto V_81;
} else {
memcpy ( V_53 , V_17 -> V_18 . V_77 , sizeof( * V_53 ) ) ;
V_71 -> V_82 = - 1 ;
}
V_70 = F_29 ( V_17 ) ;
V_71 -> V_3 = V_3 ;
V_71 -> V_17 = V_17 ;
V_71 -> V_53 = V_53 ;
V_71 -> V_25 = - 1 ;
F_38 ( V_17 , V_3 ) ;
V_71 -> V_83 = F_39 ( V_18 , L_13 ) ;
if ( F_5 ( V_71 -> V_83 ) ) {
F_22 ( V_18 , L_14 ) ;
V_48 = F_36 ( V_71 -> V_83 ) ;
goto V_81;
}
F_10 ( V_71 -> V_83 ) ;
for ( V_76 = 0 , V_75 = 0 ; V_75 < V_8 ; V_75 ++ ) {
char V_84 [ 14 ] ;
snprintf ( V_84 , 14 , L_15 , V_75 ) ;
V_71 -> V_13 [ V_75 ] = F_39 ( V_18 , V_84 ) ;
if ( F_5 ( V_71 -> V_13 [ V_75 ] ) )
continue;
V_76 ++ ;
V_71 -> V_9 [ V_75 ] = F_40 ( V_71 -> V_13 [ V_75 ] ) ;
F_41 ( V_18 , L_16 ,
V_75 , V_84 , V_71 -> V_9 [ V_75 ] ) ;
}
if ( V_76 == 0 ) {
F_22 ( V_18 , L_17 ) ;
V_48 = - V_78 ;
goto V_85;
}
V_73 = F_42 ( V_17 , V_86 , 0 ) ;
V_3 -> V_27 = F_43 ( & V_17 -> V_18 , V_73 ) ;
if ( F_5 ( V_3 -> V_27 ) ) {
V_48 = F_36 ( V_3 -> V_27 ) ;
goto V_87;
}
if ( V_53 -> V_88 )
V_53 -> V_88 ( V_17 , V_53 -> V_57 ) ;
V_3 -> V_89 = L_18 ;
V_3 -> V_90 = & V_91 ;
V_3 -> V_92 = 0 ;
V_3 -> V_93 = 0 ;
V_3 -> V_74 = V_74 ;
V_3 -> V_92 |= V_94 ;
V_3 -> V_92 |= V_95 ;
if ( V_70 ) {
V_3 -> V_92 |= V_70 -> V_96 ;
V_71 -> V_16 = V_70 -> V_16 ;
}
#ifndef F_44
V_3 -> V_92 |= V_97 ;
#endif
V_3 -> V_92 |= V_98 ;
V_3 -> V_92 |= V_99 ;
V_3 -> V_92 |= V_100 ;
if ( V_53 -> V_58 == V_59 ||
V_53 -> V_58 == V_60 )
V_3 -> V_92 |= V_101 ;
if ( V_53 -> V_58 == V_60 )
V_3 -> V_23 -> V_102 = V_103 ;
switch ( V_53 -> V_57 ) {
case 8 :
V_3 -> V_23 -> V_102 |= V_104 ;
case 4 :
V_3 -> V_23 -> V_102 |= V_105 ;
break;
}
if ( V_53 -> V_106 )
V_3 -> V_23 -> V_106 |= V_53 -> V_106 ;
V_3 -> V_92 |= ( V_107 |
V_108 ) ;
V_3 -> V_92 |= V_109 ;
if ( V_71 -> V_16 ) {
V_91 . V_110 = F_18 ;
V_91 . V_111 = F_17 ;
V_91 . V_112 = F_16 ;
}
if ( V_53 -> V_113 )
V_3 -> V_23 -> V_102 |= V_53 -> V_113 ;
if ( V_53 -> V_114 )
V_3 -> V_23 -> V_115 |= V_53 -> V_114 ;
F_45 ( & V_17 -> V_18 ) ;
F_46 ( & V_17 -> V_18 , 50 ) ;
F_47 ( & V_17 -> V_18 ) ;
F_48 ( & V_17 -> V_18 , 1 ) ;
V_48 = F_49 ( V_3 -> V_23 ) ;
if ( V_48 )
goto V_87;
V_48 = F_50 ( V_3 ) ;
if ( V_48 ) {
F_22 ( V_18 , L_19 ) ;
goto V_87;
}
#ifdef F_51
if ( V_53 -> V_58 != V_61 )
F_11 ( V_71 -> V_83 ) ;
#endif
return 0 ;
V_87:
F_52 ( & V_17 -> V_18 ) ;
V_85:
F_11 ( V_71 -> V_83 ) ;
V_81:
F_53 ( V_3 ) ;
return V_48 ;
}
static int F_54 ( struct V_64 * V_17 )
{
struct V_2 * V_3 = F_55 ( V_17 ) ;
struct V_1 * V_71 = F_2 ( V_3 ) ;
if ( V_71 -> V_116 )
F_56 ( V_71 -> V_116 , V_71 ) ;
#ifdef F_51
if ( V_71 -> V_53 -> V_58 != V_61 )
F_10 ( V_71 -> V_83 ) ;
#endif
F_57 ( V_3 , 1 ) ;
F_58 ( & V_17 -> V_18 ) ;
F_52 ( & V_17 -> V_18 ) ;
F_11 ( V_71 -> V_83 ) ;
F_53 ( V_3 ) ;
return 0 ;
}
static int F_59 ( struct V_46 * V_18 )
{
struct V_2 * V_3 = F_60 ( V_18 ) ;
if ( V_3 -> V_117 != V_118 )
F_61 ( V_3 -> V_23 ) ;
return F_62 ( V_3 ) ;
}
static int F_63 ( struct V_46 * V_18 )
{
struct V_2 * V_3 = F_60 ( V_18 ) ;
return F_64 ( V_3 ) ;
}
static int F_65 ( struct V_46 * V_18 )
{
struct V_2 * V_3 = F_60 ( V_18 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_119 = V_4 -> V_83 ;
int V_48 ;
V_48 = F_66 ( V_3 ) ;
if ( V_3 -> V_117 != V_118 )
F_61 ( V_3 -> V_23 ) ;
if ( V_4 -> V_25 >= 0 )
F_11 ( V_4 -> V_13 [ V_4 -> V_25 ] ) ;
F_11 ( V_119 ) ;
return V_48 ;
}
static int F_67 ( struct V_46 * V_18 )
{
struct V_2 * V_3 = F_60 ( V_18 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_119 = V_4 -> V_83 ;
int V_48 ;
F_10 ( V_119 ) ;
if ( V_4 -> V_25 >= 0 )
F_10 ( V_4 -> V_13 [ V_4 -> V_25 ] ) ;
V_48 = F_68 ( V_3 ) ;
return V_48 ;
}
