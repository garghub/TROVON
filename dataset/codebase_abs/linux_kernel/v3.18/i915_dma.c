static inline T_1
F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( F_2 ( V_2 -> V_4 ) )
return F_3 ( V_2 -> V_5 . V_6 + V_3 ) ;
else
return F_4 ( F_5 ( V_2 ) , V_3 ) ;
}
void F_6 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 ;
if ( F_7 ( V_4 , V_11 ) )
return;
if ( V_4 -> V_12 -> V_13 ) {
V_10 = V_4 -> V_12 -> V_13 -> V_14 ;
if ( V_10 -> V_15 )
V_10 -> V_15 -> V_16 =
F_8 ( V_2 ) ;
}
}
static void F_9 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
T_1 V_17 ;
V_17 = V_2 -> V_18 -> V_19 ;
if ( F_10 ( V_4 ) -> V_20 >= 4 )
V_17 |= ( V_2 -> V_18 -> V_19 >> 28 ) & 0xf0 ;
F_11 ( V_21 , V_17 ) ;
}
static void F_12 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_22 * V_23 = F_5 ( V_2 ) ;
if ( V_2 -> V_18 ) {
F_13 ( V_4 , V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
if ( V_23 -> V_24 . V_25 ) {
V_23 -> V_24 . V_25 = 0 ;
F_14 ( V_2 -> V_5 . V_6 ) ;
}
F_11 ( V_21 , 0x1ffff000 ) ;
}
void F_15 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_22 * V_23 = F_5 ( V_2 ) ;
struct V_26 * V_27 = V_23 -> V_28 ;
if ( F_7 ( V_4 , V_11 ) )
return;
V_27 -> V_29 = F_16 ( V_23 ) & V_30 ;
V_27 -> V_31 = F_17 ( V_23 ) & V_32 ;
V_27 -> V_33 = V_27 -> V_29 - ( V_27 -> V_31 + V_34 ) ;
if ( V_27 -> V_33 < 0 )
V_27 -> V_33 += V_27 -> V_35 ;
if ( ! V_4 -> V_12 -> V_13 )
return;
V_10 = V_4 -> V_12 -> V_13 -> V_14 ;
if ( V_27 -> V_29 == V_27 -> V_31 && V_10 -> V_15 )
V_10 -> V_15 -> V_36 |= V_37 ;
}
static int F_18 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_38 ;
if ( V_4 -> V_39 )
F_19 ( V_4 ) ;
F_20 ( & V_4 -> V_40 ) ;
for ( V_38 = 0 ; V_38 < V_41 ; V_38 ++ )
F_21 ( & V_2 -> V_23 [ V_38 ] ) ;
F_22 ( & V_4 -> V_40 ) ;
if ( F_2 ( V_4 ) )
F_12 ( V_4 ) ;
return 0 ;
}
static int F_23 ( struct V_7 * V_4 , T_2 * V_42 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_12 -> V_13 -> V_14 ;
int V_43 ;
V_10 -> V_44 = F_24 ( V_4 ) ;
if ( V_10 -> V_44 ) {
V_10 -> V_15 = ( V_45 * )
( ( V_46 * ) V_10 -> V_44 -> V_47 + V_42 -> V_48 ) ;
} else {
F_25 ( L_1 ) ;
}
if ( V_42 -> V_49 != 0 ) {
if ( F_5 ( V_2 ) -> V_28 -> V_50 != NULL ) {
F_18 ( V_4 ) ;
F_26 ( L_2
L_3 ) ;
return - V_51 ;
}
V_43 = F_27 ( V_4 ,
V_42 -> V_52 ,
V_42 -> V_49 ) ;
if ( V_43 ) {
F_18 ( V_4 ) ;
return V_43 ;
}
}
V_2 -> V_5 . V_53 = V_42 -> V_53 ;
V_2 -> V_5 . V_54 = V_42 -> V_54 ;
V_2 -> V_5 . V_55 = V_42 -> V_55 ;
V_2 -> V_5 . V_56 = 0 ;
if ( V_10 -> V_15 )
V_10 -> V_15 -> V_57 = 0 ;
V_2 -> V_5 . V_58 = 1 ;
return 0 ;
}
static int F_28 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_22 * V_23 = F_5 ( V_2 ) ;
F_25 ( L_4 , V_59 ) ;
if ( V_23 -> V_28 -> V_60 == NULL ) {
F_26 ( L_5
L_6 ) ;
return - V_61 ;
}
if ( ! V_23 -> V_24 . V_62 ) {
F_26 ( L_7 ) ;
return - V_51 ;
}
F_25 ( L_8 ,
V_23 -> V_24 . V_62 ) ;
if ( V_23 -> V_24 . V_25 != 0 )
F_29 ( V_23 ) ;
else
F_9 ( V_4 ) ;
F_25 ( L_9 ) ;
return 0 ;
}
static int F_30 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
T_2 * V_42 = V_63 ;
int V_66 = 0 ;
if ( F_7 ( V_4 , V_11 ) )
return - V_67 ;
switch ( V_42 -> V_68 ) {
case V_69 :
V_66 = F_23 ( V_4 , V_42 ) ;
break;
case V_70 :
V_66 = F_18 ( V_4 ) ;
break;
case V_71 :
V_66 = F_28 ( V_4 ) ;
break;
default:
V_66 = - V_51 ;
break;
}
return V_66 ;
}
static int F_31 ( int V_72 )
{
switch ( ( ( V_72 >> 29 ) & 0x7 ) ) {
case 0x0 :
switch ( ( V_72 >> 23 ) & 0x3f ) {
case 0x0 :
return 1 ;
case 0x4 :
return 1 ;
default:
return 0 ;
}
break;
case 0x1 :
return 0 ;
case 0x2 :
return ( V_72 & 0xff ) + 2 ;
case 0x3 :
if ( ( ( V_72 >> 24 ) & 0x1f ) <= 0x18 )
return 1 ;
switch ( ( V_72 >> 24 ) & 0x1f ) {
case 0x1c :
return 1 ;
case 0x1d :
switch ( ( V_72 >> 16 ) & 0xff ) {
case 0x3 :
return ( V_72 & 0x1f ) + 2 ;
case 0x4 :
return ( V_72 & 0xf ) + 2 ;
default:
return ( V_72 & 0xffff ) + 2 ;
}
case 0x1e :
if ( V_72 & ( 1 << 23 ) )
return ( V_72 & 0xffff ) + 1 ;
else
return 1 ;
case 0x1f :
if ( ( V_72 & ( 1 << 23 ) ) == 0 )
return ( V_72 & 0x1ffff ) + 2 ;
else if ( V_72 & ( 1 << 17 ) )
if ( ( V_72 & 0xffff ) == 0 )
return 0 ;
else
return ( ( ( V_72 & 0xffff ) + 1 ) / 2 ) + 1 ;
else
return 2 ;
default:
return 0 ;
}
default:
return 0 ;
}
return 0 ;
}
static int F_32 ( struct V_7 * V_4 , int * V_28 , int V_73 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_38 , V_43 ;
if ( ( V_73 + 1 ) * sizeof( int ) >= F_5 ( V_2 ) -> V_28 -> V_35 - 8 )
return - V_51 ;
for ( V_38 = 0 ; V_38 < V_73 ; ) {
int V_74 = F_31 ( V_28 [ V_38 ] ) ;
if ( V_74 == 0 || V_38 + V_74 > V_73 )
return - V_51 ;
V_38 += V_74 ;
}
V_43 = F_33 ( ( V_73 + 1 ) & ~ 1 ) ;
if ( V_43 )
return V_43 ;
for ( V_38 = 0 ; V_38 < V_73 ; V_38 ++ )
F_34 ( V_28 [ V_38 ] ) ;
if ( V_73 & 1 )
F_34 ( 0 ) ;
F_35 () ;
return 0 ;
}
int
F_36 ( struct V_7 * V_4 ,
struct V_75 * V_76 ,
int V_77 , int V_78 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_43 ;
if ( V_76 -> V_79 <= V_76 -> y1 || V_76 -> V_80 <= V_76 -> V_81 ||
V_76 -> V_79 <= 0 || V_76 -> V_80 <= 0 ) {
F_26 ( L_10 ,
V_76 -> V_81 , V_76 -> y1 , V_76 -> V_80 , V_76 -> V_79 ) ;
return - V_51 ;
}
if ( F_10 ( V_4 ) -> V_20 >= 4 ) {
V_43 = F_33 ( 4 ) ;
if ( V_43 )
return V_43 ;
F_34 ( V_82 ) ;
F_34 ( ( V_76 -> V_81 & 0xffff ) | ( V_76 -> y1 << 16 ) ) ;
F_34 ( ( ( V_76 -> V_80 - 1 ) & 0xffff ) | ( ( V_76 -> V_79 - 1 ) << 16 ) ) ;
F_34 ( V_78 ) ;
} else {
V_43 = F_33 ( 6 ) ;
if ( V_43 )
return V_43 ;
F_34 ( V_83 ) ;
F_34 ( V_77 ) ;
F_34 ( ( V_76 -> V_81 & 0xffff ) | ( V_76 -> y1 << 16 ) ) ;
F_34 ( ( ( V_76 -> V_80 - 1 ) & 0xffff ) | ( ( V_76 -> V_79 - 1 ) << 16 ) ) ;
F_34 ( V_78 ) ;
F_34 ( 0 ) ;
}
F_35 () ;
return 0 ;
}
static void F_37 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_12 -> V_13 -> V_14 ;
V_2 -> V_5 . V_84 ++ ;
if ( V_2 -> V_5 . V_84 > 0x7FFFFFFFUL )
V_2 -> V_5 . V_84 = 0 ;
if ( V_10 -> V_15 )
V_10 -> V_15 -> V_85 = V_2 -> V_5 . V_84 ;
if ( F_33 ( 4 ) == 0 ) {
F_34 ( V_86 ) ;
F_34 ( V_87 << V_88 ) ;
F_34 ( V_2 -> V_5 . V_84 ) ;
F_34 ( 0 ) ;
F_35 () ;
}
}
static int F_38 ( struct V_7 * V_4 ,
T_3 * V_72 ,
struct V_75 * V_89 ,
void * V_90 )
{
int V_91 = V_72 -> V_92 ;
int V_38 = 0 , V_93 , V_43 ;
if ( V_72 -> V_74 & 0x3 ) {
F_26 ( L_11 ) ;
return - V_51 ;
}
F_15 ( V_4 ) ;
V_93 = V_91 ? V_91 : 1 ;
for ( V_38 = 0 ; V_38 < V_93 ; V_38 ++ ) {
if ( V_38 < V_91 ) {
V_43 = F_36 ( V_4 , & V_89 [ V_38 ] ,
V_72 -> V_77 , V_72 -> V_78 ) ;
if ( V_43 )
return V_43 ;
}
V_43 = F_32 ( V_4 , V_90 , V_72 -> V_74 / 4 ) ;
if ( V_43 )
return V_43 ;
}
F_37 ( V_4 ) ;
return 0 ;
}
static int F_39 ( struct V_7 * V_4 ,
T_4 * V_94 ,
struct V_75 * V_89 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_91 = V_94 -> V_92 ;
int V_38 , V_93 , V_43 ;
if ( ( V_94 -> V_95 | V_94 -> V_96 ) & 0x7 ) {
F_26 ( L_11 ) ;
return - V_51 ;
}
F_15 ( V_4 ) ;
V_93 = V_91 ? V_91 : 1 ;
for ( V_38 = 0 ; V_38 < V_93 ; V_38 ++ ) {
if ( V_38 < V_91 ) {
V_43 = F_36 ( V_4 , & V_89 [ V_38 ] ,
V_94 -> V_77 , V_94 -> V_78 ) ;
if ( V_43 )
return V_43 ;
}
if ( ! F_40 ( V_4 ) && ! F_41 ( V_4 ) ) {
V_43 = F_33 ( 2 ) ;
if ( V_43 )
return V_43 ;
if ( F_10 ( V_4 ) -> V_20 >= 4 ) {
F_34 ( V_97 | ( 2 << 6 ) | V_98 ) ;
F_34 ( V_94 -> V_95 ) ;
} else {
F_34 ( V_97 | ( 2 << 6 ) ) ;
F_34 ( V_94 -> V_95 | V_99 ) ;
}
} else {
V_43 = F_33 ( 4 ) ;
if ( V_43 )
return V_43 ;
F_34 ( V_100 ) ;
F_34 ( V_94 -> V_95 | V_99 ) ;
F_34 ( V_94 -> V_95 + V_94 -> V_96 - 4 ) ;
F_34 ( 0 ) ;
}
F_35 () ;
}
if ( F_42 ( V_4 ) || F_43 ( V_4 ) ) {
if ( F_33 ( 2 ) == 0 ) {
F_34 ( V_101 | V_102 | V_103 ) ;
F_34 ( V_104 ) ;
F_35 () ;
}
}
F_37 ( V_4 ) ;
return 0 ;
}
static int F_44 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 =
V_4 -> V_12 -> V_13 -> V_14 ;
int V_43 ;
if ( ! V_10 -> V_15 )
return - V_51 ;
F_25 ( L_12 ,
V_59 ,
V_2 -> V_5 . V_56 ,
V_10 -> V_15 -> V_57 ) ;
F_15 ( V_4 ) ;
V_43 = F_33 ( 10 ) ;
if ( V_43 )
return V_43 ;
F_34 ( V_101 | V_105 ) ;
F_34 ( 0 ) ;
F_34 ( V_106 | V_107 ) ;
F_34 ( 0 ) ;
if ( V_2 -> V_5 . V_56 == 0 ) {
F_34 ( V_2 -> V_5 . V_54 ) ;
V_2 -> V_5 . V_56 = 1 ;
} else {
F_34 ( V_2 -> V_5 . V_55 ) ;
V_2 -> V_5 . V_56 = 0 ;
}
F_34 ( 0 ) ;
F_34 ( V_108 | V_109 ) ;
F_34 ( 0 ) ;
F_35 () ;
V_10 -> V_15 -> V_85 = V_2 -> V_5 . V_84 ++ ;
if ( F_33 ( 4 ) == 0 ) {
F_34 ( V_86 ) ;
F_34 ( V_87 << V_88 ) ;
F_34 ( V_2 -> V_5 . V_84 ) ;
F_34 ( 0 ) ;
F_35 () ;
}
V_10 -> V_15 -> V_57 = V_2 -> V_5 . V_56 ;
return 0 ;
}
static int F_45 ( struct V_7 * V_4 )
{
F_15 ( V_4 ) ;
return F_46 ( F_5 ( V_4 -> V_8 ) ) ;
}
static int F_47 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
int V_43 ;
if ( F_7 ( V_4 , V_11 ) )
return - V_67 ;
F_48 ( V_4 , V_65 ) ;
F_20 ( & V_4 -> V_40 ) ;
V_43 = F_45 ( V_4 ) ;
F_22 ( & V_4 -> V_40 ) ;
return V_43 ;
}
static int F_49 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 ;
V_45 * V_15 ;
T_4 * V_94 = V_63 ;
int V_43 ;
struct V_75 * V_89 = NULL ;
if ( F_7 ( V_4 , V_11 ) )
return - V_67 ;
V_10 = V_4 -> V_12 -> V_13 -> V_14 ;
V_15 = ( V_45 * ) V_10 -> V_15 ;
if ( ! V_2 -> V_5 . V_58 ) {
F_26 ( L_13 ) ;
return - V_51 ;
}
F_25 ( L_14 ,
V_94 -> V_95 , V_94 -> V_96 , V_94 -> V_92 ) ;
F_48 ( V_4 , V_65 ) ;
if ( V_94 -> V_92 < 0 )
return - V_51 ;
if ( V_94 -> V_92 ) {
V_89 = F_50 ( V_94 -> V_92 ,
sizeof( * V_89 ) ,
V_110 ) ;
if ( V_89 == NULL )
return - V_61 ;
V_43 = F_51 ( V_89 , V_94 -> V_89 ,
V_94 -> V_92 *
sizeof( struct V_75 ) ) ;
if ( V_43 != 0 ) {
V_43 = - V_111 ;
goto V_112;
}
}
F_20 ( & V_4 -> V_40 ) ;
V_43 = F_39 ( V_4 , V_94 , V_89 ) ;
F_22 ( & V_4 -> V_40 ) ;
if ( V_15 )
V_15 -> V_16 = F_8 ( V_2 ) ;
V_112:
F_52 ( V_89 ) ;
return V_43 ;
}
static int F_53 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 ;
V_45 * V_15 ;
T_3 * V_90 = V_63 ;
struct V_75 * V_89 = NULL ;
void * V_113 ;
int V_43 ;
F_25 ( L_15 ,
V_90 -> V_114 , V_90 -> V_74 , V_90 -> V_92 ) ;
if ( F_7 ( V_4 , V_11 ) )
return - V_67 ;
V_10 = V_4 -> V_12 -> V_13 -> V_14 ;
V_15 = ( V_45 * ) V_10 -> V_15 ;
F_48 ( V_4 , V_65 ) ;
if ( V_90 -> V_92 < 0 )
return - V_51 ;
V_113 = F_54 ( V_90 -> V_74 , V_110 ) ;
if ( V_113 == NULL )
return - V_61 ;
V_43 = F_51 ( V_113 , V_90 -> V_114 , V_90 -> V_74 ) ;
if ( V_43 != 0 ) {
V_43 = - V_111 ;
goto V_115;
}
if ( V_90 -> V_92 ) {
V_89 = F_50 ( V_90 -> V_92 ,
sizeof( * V_89 ) , V_110 ) ;
if ( V_89 == NULL ) {
V_43 = - V_61 ;
goto V_115;
}
V_43 = F_51 ( V_89 , V_90 -> V_89 ,
V_90 -> V_92 *
sizeof( struct V_75 ) ) ;
if ( V_43 != 0 ) {
V_43 = - V_111 ;
goto V_116;
}
}
F_20 ( & V_4 -> V_40 ) ;
V_43 = F_38 ( V_4 , V_90 , V_89 , V_113 ) ;
F_22 ( & V_4 -> V_40 ) ;
if ( V_43 ) {
F_26 ( L_16 ) ;
goto V_116;
}
if ( V_15 )
V_15 -> V_16 = F_8 ( V_2 ) ;
V_116:
F_52 ( V_89 ) ;
V_115:
F_52 ( V_113 ) ;
return V_43 ;
}
static int F_55 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_12 -> V_13 -> V_14 ;
F_15 ( V_4 ) ;
F_25 ( L_17 ) ;
V_2 -> V_5 . V_84 ++ ;
if ( V_2 -> V_5 . V_84 > 0x7FFFFFFFUL )
V_2 -> V_5 . V_84 = 1 ;
if ( V_10 -> V_15 )
V_10 -> V_15 -> V_85 = V_2 -> V_5 . V_84 ;
if ( F_33 ( 4 ) == 0 ) {
F_34 ( V_86 ) ;
F_34 ( V_87 << V_88 ) ;
F_34 ( V_2 -> V_5 . V_84 ) ;
F_34 ( V_117 ) ;
F_35 () ;
}
return V_2 -> V_5 . V_84 ;
}
static int F_56 ( struct V_7 * V_4 , int V_118 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_12 -> V_13 -> V_14 ;
int V_43 = 0 ;
struct V_22 * V_23 = F_5 ( V_2 ) ;
F_25 ( L_18 , V_118 ,
F_8 ( V_2 ) ) ;
if ( F_8 ( V_2 ) >= V_118 ) {
if ( V_10 -> V_15 )
V_10 -> V_15 -> V_16 = F_8 ( V_2 ) ;
return 0 ;
}
if ( V_10 -> V_15 )
V_10 -> V_15 -> V_36 |= V_119 ;
if ( V_23 -> V_120 ( V_23 ) ) {
F_57 ( V_43 , V_23 -> V_121 , 3 * V_122 ,
F_8 ( V_2 ) >= V_118 ) ;
V_23 -> V_123 ( V_23 ) ;
} else if ( F_58 ( F_8 ( V_2 ) >= V_118 , 3000 ) )
V_43 = - V_124 ;
if ( V_43 == - V_124 ) {
F_26 ( L_19 ,
F_8 ( V_2 ) , ( int ) V_2 -> V_5 . V_84 ) ;
}
return V_43 ;
}
static int F_59 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
T_5 * V_125 = V_63 ;
int V_126 ;
if ( F_7 ( V_4 , V_11 ) )
return - V_67 ;
if ( ! V_2 || ! F_5 ( V_2 ) -> V_28 -> V_60 ) {
F_26 ( L_20 ) ;
return - V_51 ;
}
F_48 ( V_4 , V_65 ) ;
F_20 ( & V_4 -> V_40 ) ;
V_126 = F_55 ( V_4 ) ;
F_22 ( & V_4 -> V_40 ) ;
if ( F_60 ( V_125 -> V_127 , & V_126 , sizeof( int ) ) ) {
F_26 ( L_21 ) ;
return - V_111 ;
}
return 0 ;
}
static int F_61 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
T_6 * V_128 = V_63 ;
if ( F_7 ( V_4 , V_11 ) )
return - V_67 ;
if ( ! V_2 ) {
F_26 ( L_20 ) ;
return - V_51 ;
}
return F_56 ( V_4 , V_128 -> V_127 ) ;
}
static int F_62 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
T_7 * V_129 = V_63 ;
if ( F_7 ( V_4 , V_11 ) )
return - V_67 ;
if ( ! V_2 ) {
F_26 ( L_20 ) ;
return - V_51 ;
}
V_129 -> V_129 = V_130 | V_131 ;
return 0 ;
}
static int F_63 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
return - V_51 ;
}
static int F_64 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
int V_43 ;
if ( F_7 ( V_4 , V_11 ) )
return - V_67 ;
F_25 ( L_4 , V_59 ) ;
F_48 ( V_4 , V_65 ) ;
F_20 ( & V_4 -> V_40 ) ;
V_43 = F_44 ( V_4 ) ;
F_22 ( & V_4 -> V_40 ) ;
return V_43 ;
}
static int F_65 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
T_8 * V_132 = V_63 ;
int V_133 ;
if ( ! V_2 ) {
F_26 ( L_20 ) ;
return - V_51 ;
}
switch ( V_132 -> V_132 ) {
case V_134 :
V_133 = V_4 -> V_135 -> V_136 ? 1 : 0 ;
break;
case V_137 :
V_133 = V_2 -> V_5 . V_58 ? 1 : 0 ;
break;
case V_138 :
V_133 = F_8 ( V_2 ) ;
break;
case V_139 :
V_133 = V_4 -> V_135 -> V_140 ;
break;
case V_141 :
V_133 = 1 ;
break;
case V_142 :
V_133 = V_2 -> V_143 - V_2 -> V_144 ;
break;
case V_145 :
V_133 = V_2 -> V_146 ? 1 : 0 ;
break;
case V_147 :
V_133 = 1 ;
break;
case V_148 :
V_133 = 1 ;
break;
case V_149 :
V_133 = F_66 ( & V_2 -> V_23 [ V_150 ] ) ;
break;
case V_151 :
V_133 = F_66 ( & V_2 -> V_23 [ V_152 ] ) ;
break;
case V_153 :
V_133 = F_66 ( & V_2 -> V_23 [ V_154 ] ) ;
break;
case V_155 :
V_133 = 1 ;
break;
case V_156 :
V_133 = 1 ;
break;
case V_157 :
V_133 = F_10 ( V_4 ) -> V_20 >= 4 ;
break;
case V_158 :
V_133 = 1 ;
break;
case V_159 :
V_133 = 1 ;
break;
case V_160 :
V_133 = F_67 ( V_4 ) ;
break;
case V_161 :
V_133 = F_68 ( V_4 ) ;
break;
case V_162 :
V_133 = F_69 ( V_4 ) ;
break;
case V_163 :
V_133 = 1 ;
break;
case V_164 :
V_133 = F_70 ( V_4 ) ;
break;
case V_165 :
V_133 = 1 ;
break;
case V_166 :
V_133 = F_71 ( V_167 ) ;
break;
case V_168 :
V_133 = 1 ;
break;
case V_169 :
V_133 = 1 ;
break;
case V_170 :
V_133 = 1 ;
break;
case V_171 :
V_133 = F_72 () ;
break;
default:
F_73 ( L_22 , V_132 -> V_132 ) ;
return - V_51 ;
}
if ( F_60 ( V_132 -> V_133 , & V_133 , sizeof( int ) ) ) {
F_26 ( L_23 ) ;
return - V_111 ;
}
return 0 ;
}
static int F_74 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
T_9 * V_132 = V_63 ;
if ( ! V_2 ) {
F_26 ( L_20 ) ;
return - V_51 ;
}
switch ( V_132 -> V_132 ) {
case V_172 :
break;
case V_173 :
break;
case V_174 :
V_2 -> V_5 . V_58 = V_132 -> V_133 ? 1 : 0 ;
break;
case V_175 :
if ( V_132 -> V_133 > V_2 -> V_143 ||
V_132 -> V_133 < 0 )
return - V_51 ;
V_2 -> V_144 = V_132 -> V_133 ;
break;
default:
F_25 ( L_24 ,
V_132 -> V_132 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_75 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
T_10 * V_176 = V_63 ;
struct V_22 * V_23 ;
if ( F_7 ( V_4 , V_11 ) )
return - V_67 ;
if ( ! F_2 ( V_4 ) )
return - V_51 ;
if ( ! V_2 ) {
F_26 ( L_20 ) ;
return - V_51 ;
}
if ( F_7 ( V_4 , V_11 ) ) {
F_76 ( 1 , L_25 ) ;
return 0 ;
}
F_25 ( L_26 , ( T_1 ) V_176 -> V_17 ) ;
V_23 = F_5 ( V_2 ) ;
V_23 -> V_24 . V_25 = V_176 -> V_17 & ( 0x1ffff << 12 ) ;
V_2 -> V_5 . V_6 =
F_77 ( V_2 -> V_177 . V_178 + V_176 -> V_17 , 4096 ) ;
if ( V_2 -> V_5 . V_6 == NULL ) {
F_18 ( V_4 ) ;
V_23 -> V_24 . V_25 = 0 ;
F_26 ( L_5
L_27 ) ;
return - V_61 ;
}
F_78 ( V_2 -> V_5 . V_6 , 0 , V_179 ) ;
F_11 ( V_21 , V_23 -> V_24 . V_25 ) ;
F_25 ( L_28 ,
V_23 -> V_24 . V_25 ) ;
F_25 ( L_29 ,
V_23 -> V_24 . V_62 ) ;
return 0 ;
}
static int F_79 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
V_2 -> V_180 = F_80 ( 0 , F_81 ( 0 , 0 ) ) ;
if ( ! V_2 -> V_180 ) {
F_26 ( L_30 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_82 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_3 = F_10 ( V_4 ) -> V_20 >= 4 ? V_181 : V_182 ;
T_1 V_183 , V_184 = 0 ;
T_11 V_185 ;
int V_43 ;
if ( F_10 ( V_4 ) -> V_20 >= 4 )
F_83 ( V_2 -> V_180 , V_3 + 4 , & V_184 ) ;
F_83 ( V_2 -> V_180 , V_3 , & V_183 ) ;
V_185 = ( ( T_11 ) V_184 << 32 ) | V_183 ;
#ifdef F_84
if ( V_185 &&
F_85 ( V_185 , V_185 + V_186 ) )
return 0 ;
#endif
V_2 -> V_187 . V_188 = L_31 ;
V_2 -> V_187 . V_189 = V_190 ;
V_43 = F_86 ( V_2 -> V_180 -> V_191 ,
& V_2 -> V_187 ,
V_186 , V_186 ,
V_192 ,
0 , V_193 ,
V_2 -> V_180 ) ;
if ( V_43 ) {
F_25 ( L_32 , V_43 ) ;
V_2 -> V_187 . V_95 = 0 ;
return V_43 ;
}
if ( F_10 ( V_4 ) -> V_20 >= 4 )
F_87 ( V_2 -> V_180 , V_3 + 4 ,
F_88 ( V_2 -> V_187 . V_95 ) ) ;
F_87 ( V_2 -> V_180 , V_3 ,
F_89 ( V_2 -> V_187 . V_95 ) ) ;
return 0 ;
}
static void
F_90 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_194 = F_10 ( V_4 ) -> V_20 >= 4 ? V_181 : V_182 ;
T_1 V_195 ;
bool V_196 ;
if ( F_91 ( V_4 ) )
return;
V_2 -> V_197 = false ;
if ( F_92 ( V_4 ) || F_93 ( V_4 ) ) {
F_83 ( V_2 -> V_180 , V_198 , & V_195 ) ;
V_196 = ! ! ( V_195 & V_199 ) ;
} else {
F_83 ( V_2 -> V_180 , V_194 , & V_195 ) ;
V_196 = V_195 & 1 ;
}
if ( V_196 )
return;
if ( F_82 ( V_4 ) )
return;
V_2 -> V_197 = true ;
if ( F_92 ( V_4 ) || F_93 ( V_4 ) ) {
F_87 ( V_2 -> V_180 , V_198 ,
V_195 | V_199 ) ;
} else {
F_83 ( V_2 -> V_180 , V_194 , & V_195 ) ;
F_87 ( V_2 -> V_180 , V_194 , V_195 | 1 ) ;
}
}
static void
F_94 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_194 = F_10 ( V_4 ) -> V_20 >= 4 ? V_181 : V_182 ;
T_1 V_195 ;
if ( V_2 -> V_197 ) {
if ( F_92 ( V_4 ) || F_93 ( V_4 ) ) {
F_83 ( V_2 -> V_180 , V_198 , & V_195 ) ;
V_195 &= ~ V_199 ;
F_87 ( V_2 -> V_180 , V_198 , V_195 ) ;
} else {
F_83 ( V_2 -> V_180 , V_194 , & V_195 ) ;
V_195 &= ~ 1 ;
F_87 ( V_2 -> V_180 , V_194 , V_195 ) ;
}
}
if ( V_2 -> V_187 . V_95 )
F_95 ( & V_2 -> V_187 ) ;
}
static unsigned int F_96 ( void * V_200 , bool V_201 )
{
struct V_7 * V_4 = V_200 ;
F_97 ( V_4 , V_201 ) ;
if ( V_201 )
return V_202 | V_203 |
V_204 | V_205 ;
else
return V_204 | V_205 ;
}
static void F_98 ( struct V_206 * V_135 , enum V_207 V_201 )
{
struct V_7 * V_4 = F_99 ( V_135 ) ;
T_12 V_208 = { . V_209 = V_210 } ;
if ( V_201 == V_211 ) {
F_100 ( L_33 ) ;
V_4 -> V_212 = V_213 ;
F_101 ( V_4 -> V_135 , V_214 ) ;
F_102 ( V_4 ) ;
V_4 -> V_212 = V_215 ;
} else {
F_103 ( L_34 ) ;
V_4 -> V_212 = V_213 ;
F_104 ( V_4 , V_208 ) ;
V_4 -> V_212 = V_216 ;
}
}
static bool F_105 ( struct V_206 * V_135 )
{
struct V_7 * V_4 = F_99 ( V_135 ) ;
return V_4 -> V_217 == 0 ;
}
static int F_106 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_43 ;
V_43 = F_107 ( V_4 ) ;
if ( V_43 )
F_108 ( L_35 ) ;
V_43 = F_109 ( V_4 -> V_135 , V_4 , NULL , F_96 ) ;
if ( V_43 && V_43 != - V_67 )
goto V_218;
F_110 () ;
V_43 = F_111 ( V_4 -> V_135 , & V_219 , false ) ;
if ( V_43 )
goto V_220;
V_43 = F_112 ( V_4 ) ;
if ( V_43 )
goto V_221;
F_113 ( V_2 ) ;
V_2 -> V_222 . V_223 = false ;
V_43 = F_114 ( V_4 , V_4 -> V_135 -> V_136 ) ;
if ( V_43 )
goto V_224;
F_115 ( V_4 ) ;
V_43 = F_116 ( V_4 ) ;
if ( V_43 )
goto V_225;
F_117 ( V_4 ) ;
V_4 -> V_226 = true ;
if ( F_10 ( V_4 ) -> V_227 == 0 )
return 0 ;
V_43 = F_118 ( V_4 ) ;
if ( V_43 )
goto V_228;
F_119 ( V_4 ) ;
F_120 ( V_229 , V_2 ) ;
F_121 ( V_4 ) ;
return 0 ;
V_228:
F_20 ( & V_4 -> V_40 ) ;
F_122 ( V_4 ) ;
F_123 ( V_4 ) ;
F_22 ( & V_4 -> V_40 ) ;
V_225:
F_19 ( V_4 ) ;
V_224:
F_124 ( V_4 ) ;
V_221:
F_125 ( V_4 -> V_135 ) ;
V_220:
F_109 ( V_4 -> V_135 , NULL , NULL , NULL ) ;
V_218:
return V_43 ;
}
int F_126 ( struct V_7 * V_4 , struct V_230 * V_13 )
{
struct V_9 * V_10 ;
V_10 = F_127 ( sizeof( * V_10 ) , V_110 ) ;
if ( ! V_10 )
return - V_61 ;
V_13 -> V_14 = V_10 ;
return 0 ;
}
void F_128 ( struct V_7 * V_4 , struct V_230 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_14 ;
if ( ! V_10 )
return;
F_52 ( V_10 ) ;
V_13 -> V_14 = NULL ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_231 * V_232 ;
struct V_206 * V_135 = V_2 -> V_4 -> V_135 ;
bool V_12 ;
int V_43 ;
V_232 = F_130 ( 1 ) ;
if ( ! V_232 )
return - V_61 ;
V_232 -> V_233 [ 0 ] . V_234 = V_2 -> V_177 . V_178 ;
V_232 -> V_233 [ 0 ] . V_35 = V_2 -> V_177 . V_235 ;
V_12 =
V_135 -> V_236 [ V_237 ] . V_189 & V_238 ;
V_43 = F_131 ( V_232 , L_36 , V_12 ) ;
F_52 ( V_232 ) ;
return V_43 ;
}
static int F_129 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_132 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_132 ( struct V_1 * V_2 )
{
return - V_67 ;
}
static int F_132 ( struct V_1 * V_2 )
{
int V_43 = 0 ;
F_108 ( L_37 ) ;
F_133 () ;
if ( F_134 ( & V_239 ) )
V_43 = F_135 ( & V_240 , 0 , V_241 - 1 , 1 ) ;
if ( V_43 == 0 ) {
V_43 = F_136 ( & V_239 ) ;
if ( V_43 == - V_67 )
V_43 = 0 ;
}
F_137 () ;
return V_43 ;
}
static void F_138 ( struct V_1 * V_2 )
{
const struct V_242 * V_243 = & V_2 -> V_243 ;
#define F_139 ( V_188 ) "%s"
#define F_140
#define F_141 ( V_188 ) info->name ? #name "," : ""
#define F_142 ,
F_25 ( L_38
F_143 ( F_139 , F_140 ) ,
V_243 -> V_20 ,
V_2 -> V_4 -> V_135 -> V_140 ,
V_2 -> V_4 -> V_135 -> V_244 ,
F_143 ( F_141 , F_142 ) ) ;
#undef F_139
#undef F_140
#undef F_141
#undef F_142
}
static void F_144 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_242 * V_243 ;
enum V_129 V_129 ;
V_243 = (struct V_242 * ) & V_2 -> V_243 ;
if ( F_91 ( V_4 ) )
F_145 (dev_priv, pipe)
V_243 -> V_245 [ V_129 ] = 2 ;
else
F_145 (dev_priv, pipe)
V_243 -> V_245 [ V_129 ] = 1 ;
if ( V_246 . V_247 ) {
F_108 ( L_39 ) ;
V_243 -> V_227 = 0 ;
} else if ( V_243 -> V_227 > 0 &&
( F_10 ( V_4 ) -> V_20 == 7 || F_10 ( V_4 ) -> V_20 == 8 ) &&
! F_91 ( V_4 ) ) {
T_1 V_248 = F_146 ( V_249 ) ;
T_1 V_250 = F_146 ( V_251 ) ;
if ( V_248 & V_252 ||
V_250 & V_253 ||
( V_2 -> V_254 == V_255 &&
! ( V_250 & V_256 ) ) ) {
F_108 ( L_40 ) ;
V_243 -> V_227 = 0 ;
}
}
}
int F_147 ( struct V_7 * V_4 , unsigned long V_189 )
{
struct V_1 * V_2 ;
struct V_242 * V_243 , * V_257 ;
int V_43 = 0 , V_258 , V_259 ;
T_13 V_260 ;
V_243 = (struct V_242 * ) V_189 ;
if ( V_243 -> V_20 >= 6 && ! F_7 ( V_4 , V_11 ) ) {
F_108 ( L_41 ) ;
F_108 ( L_42 ) ;
return - V_67 ;
}
if ( ! F_7 ( V_4 , V_11 ) && ! V_4 -> V_261 )
return - V_51 ;
V_2 = F_127 ( sizeof( * V_2 ) , V_110 ) ;
if ( V_2 == NULL )
return - V_61 ;
V_4 -> V_8 = V_2 ;
V_2 -> V_4 = V_4 ;
V_257 = (struct V_242 * ) & V_2 -> V_243 ;
memcpy ( V_257 , V_243 , sizeof( V_2 -> V_243 ) ) ;
V_257 -> V_262 = V_4 -> V_135 -> V_140 ;
F_148 ( & V_2 -> V_263 ) ;
F_148 ( & V_2 -> V_264 . V_265 ) ;
F_148 ( & V_2 -> V_266 ) ;
F_148 ( & V_2 -> V_267 . V_265 ) ;
F_148 ( & V_2 -> V_268 . V_269 ) ;
F_148 ( & V_2 -> V_270 ) ;
F_149 ( & V_2 -> V_271 ) ;
F_149 ( & V_2 -> V_272 ) ;
F_150 ( V_4 ) ;
F_151 ( V_4 ) ;
F_138 ( V_2 ) ;
if ( F_152 ( V_4 ) )
F_108 ( L_43
L_44 ) ;
if ( F_79 ( V_4 ) ) {
V_43 = - V_273 ;
goto V_274;
}
V_258 = F_153 ( V_4 ) ? 1 : 0 ;
if ( V_243 -> V_20 < 5 )
V_259 = 512 * 1024 ;
else
V_259 = 2 * 1024 * 1024 ;
V_2 -> V_275 = F_154 ( V_4 -> V_135 , V_258 , V_259 ) ;
if ( ! V_2 -> V_275 ) {
F_26 ( L_45 ) ;
V_43 = - V_273 ;
goto V_276;
}
F_155 ( V_4 ) ;
F_156 ( V_4 ) ;
V_43 = F_157 ( V_4 ) ;
if ( V_43 )
goto V_277;
if ( F_7 ( V_4 , V_11 ) ) {
V_43 = F_129 ( V_2 ) ;
if ( V_43 ) {
F_26 ( L_46 ) ;
goto V_278;
}
V_43 = F_132 ( V_2 ) ;
if ( V_43 ) {
F_26 ( L_47 ) ;
goto V_278;
}
}
F_158 ( V_4 -> V_135 ) ;
if ( F_153 ( V_4 ) )
F_159 ( & V_4 -> V_135 -> V_4 , F_160 ( 30 ) ) ;
if ( F_161 ( V_4 ) || F_162 ( V_4 ) )
F_159 ( & V_4 -> V_135 -> V_4 , F_160 ( 32 ) ) ;
V_260 = V_2 -> V_177 . V_235 ;
V_2 -> V_177 . V_279 =
F_163 ( V_2 -> V_177 . V_178 ,
V_260 ) ;
if ( V_2 -> V_177 . V_279 == NULL ) {
V_43 = - V_273 ;
goto V_278;
}
V_2 -> V_177 . V_280 = F_164 ( V_2 -> V_177 . V_178 ,
V_260 ) ;
V_2 -> V_281 = F_165 ( L_48 , 0 ) ;
if ( V_2 -> V_281 == NULL ) {
F_26 ( L_49 ) ;
V_43 = - V_61 ;
goto V_282;
}
V_2 -> V_283 = F_165 ( L_50 , 0 ) ;
if ( V_2 -> V_283 == NULL ) {
F_26 ( L_51 ) ;
V_43 = - V_61 ;
goto V_284;
}
F_166 ( V_4 ) ;
F_167 ( V_4 ) ;
F_90 ( V_4 ) ;
F_168 ( V_4 ) ;
F_169 ( V_4 ) ;
F_170 ( V_4 ) ;
F_171 ( V_4 ) ;
if ( ! F_172 ( V_4 ) && ! F_173 ( V_4 ) )
F_174 ( V_4 -> V_135 ) ;
F_144 ( V_4 ) ;
if ( F_10 ( V_4 ) -> V_227 ) {
V_43 = F_175 ( V_4 , F_10 ( V_4 ) -> V_227 ) ;
if ( V_43 )
goto V_285;
}
F_176 ( V_2 ) ;
if ( F_7 ( V_4 , V_11 ) ) {
V_43 = F_106 ( V_4 ) ;
if ( V_43 < 0 ) {
F_26 ( L_52 ) ;
goto V_286;
}
} else {
V_2 -> V_287 . V_288 = 1 ;
}
F_177 ( V_4 ) ;
if ( F_10 ( V_4 ) -> V_227 ) {
F_178 ( V_4 ) ;
F_179 () ;
}
if ( F_43 ( V_4 ) )
F_180 ( V_2 ) ;
F_181 ( V_2 ) ;
return 0 ;
V_286:
F_182 ( V_2 ) ;
F_183 ( V_4 ) ;
V_285:
F_184 ( F_185 ( & V_2 -> V_268 . V_289 ) ) ;
F_186 ( & V_2 -> V_268 . V_290 ) ;
if ( V_4 -> V_135 -> V_291 )
F_187 ( V_4 -> V_135 ) ;
F_188 ( V_4 ) ;
F_94 ( V_4 ) ;
F_189 ( & V_2 -> V_292 ) ;
F_190 ( V_2 -> V_283 ) ;
V_284:
F_190 ( V_2 -> V_281 ) ;
V_282:
F_191 ( V_2 -> V_177 . V_280 ) ;
F_192 ( V_2 -> V_177 . V_279 ) ;
V_278:
F_193 ( V_4 ) ;
V_277:
F_194 ( V_4 ) ;
F_195 ( V_4 -> V_135 , V_2 -> V_275 ) ;
V_276:
F_196 ( V_2 -> V_180 ) ;
V_274:
if ( V_2 -> V_293 )
F_197 ( V_2 -> V_293 ) ;
F_52 ( V_2 ) ;
return V_43 ;
}
int F_198 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_43 ;
V_43 = F_199 ( V_4 ) ;
if ( V_43 ) {
F_26 ( L_53 , V_43 ) ;
return V_43 ;
}
F_200 ( V_2 ) ;
F_201 () ;
F_202 ( V_2 , true ) ;
F_182 ( V_2 ) ;
F_203 ( V_4 ) ;
F_184 ( F_185 ( & V_2 -> V_268 . V_289 ) ) ;
F_186 ( & V_2 -> V_268 . V_290 ) ;
F_192 ( V_2 -> V_177 . V_279 ) ;
F_191 ( V_2 -> V_177 . V_280 ) ;
F_204 () ;
if ( F_7 ( V_4 , V_11 ) ) {
F_205 ( V_4 ) ;
F_206 ( V_4 ) ;
if ( V_2 -> V_294 . V_295 && V_2 -> V_294 . V_296 ) {
F_52 ( V_2 -> V_294 . V_295 ) ;
V_2 -> V_294 . V_295 = NULL ;
V_2 -> V_294 . V_296 = 0 ;
}
F_125 ( V_4 -> V_135 ) ;
F_109 ( V_4 -> V_135 , NULL , NULL , NULL ) ;
}
F_207 ( & V_2 -> V_264 . V_297 ) ;
F_208 ( & V_2 -> V_264 . V_298 ) ;
F_209 ( V_4 ) ;
if ( V_4 -> V_135 -> V_291 )
F_187 ( V_4 -> V_135 ) ;
F_210 ( V_4 ) ;
if ( F_7 ( V_4 , V_11 ) ) {
F_211 ( V_2 -> V_281 ) ;
F_20 ( & V_4 -> V_40 ) ;
F_122 ( V_4 ) ;
F_123 ( V_4 ) ;
F_22 ( & V_4 -> V_40 ) ;
F_124 ( V_4 ) ;
if ( ! F_2 ( V_4 ) )
F_12 ( V_4 ) ;
}
F_183 ( V_4 ) ;
F_188 ( V_4 ) ;
F_94 ( V_4 ) ;
F_190 ( V_2 -> V_283 ) ;
F_190 ( V_2 -> V_281 ) ;
F_189 ( & V_2 -> V_292 ) ;
F_193 ( V_4 ) ;
F_194 ( V_4 ) ;
if ( V_2 -> V_275 != NULL )
F_195 ( V_4 -> V_135 , V_2 -> V_275 ) ;
if ( V_2 -> V_293 )
F_197 ( V_2 -> V_293 ) ;
F_196 ( V_2 -> V_180 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
int F_212 ( struct V_7 * V_4 , struct V_64 * V_299 )
{
int V_43 ;
V_43 = F_213 ( V_4 , V_299 ) ;
if ( V_43 )
return V_43 ;
return 0 ;
}
void F_214 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
if ( ! V_2 )
return;
if ( F_7 ( V_4 , V_11 ) ) {
F_215 ( V_4 ) ;
F_216 () ;
return;
}
F_217 ( V_4 ) ;
F_18 ( V_4 ) ;
}
void F_218 ( struct V_7 * V_4 , struct V_64 * V_299 )
{
F_20 ( & V_4 -> V_40 ) ;
F_219 ( V_4 , V_299 ) ;
F_220 ( V_4 , V_299 ) ;
F_22 ( & V_4 -> V_40 ) ;
if ( F_7 ( V_4 , V_11 ) )
F_221 ( V_4 , V_299 ) ;
}
void F_222 ( struct V_7 * V_4 , struct V_64 * V_299 )
{
struct V_300 * V_65 = V_299 -> V_14 ;
if ( V_65 && V_65 -> V_301 )
V_65 -> V_301 = NULL ;
F_52 ( V_65 ) ;
}
int F_223 ( struct V_7 * V_4 )
{
return 1 ;
}
