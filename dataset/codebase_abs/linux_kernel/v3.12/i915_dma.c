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
T_2 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 ;
if ( V_4 -> V_11 -> V_12 ) {
V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
if ( V_10 -> V_14 )
V_10 -> V_14 -> V_15 =
F_7 ( V_2 ) ;
}
}
static void F_8 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_1 V_16 ;
V_16 = V_2 -> V_17 -> V_18 ;
if ( F_9 ( V_4 ) -> V_19 >= 4 )
V_16 |= ( V_2 -> V_17 -> V_18 >> 28 ) & 0xf0 ;
F_10 ( V_20 , V_16 ) ;
}
static void F_11 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
struct V_21 * V_22 = F_5 ( V_2 ) ;
if ( V_2 -> V_17 ) {
F_12 ( V_4 , V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
}
if ( V_22 -> V_23 . V_24 ) {
V_22 -> V_23 . V_24 = 0 ;
F_13 ( V_2 -> V_5 . V_6 ) ;
}
F_10 ( V_20 , 0x1ffff000 ) ;
}
void F_14 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_21 * V_22 = F_5 ( V_2 ) ;
if ( F_15 ( V_4 , V_25 ) )
return;
V_22 -> V_26 = F_16 ( V_22 ) & V_27 ;
V_22 -> V_28 = F_17 ( V_22 ) & V_29 ;
V_22 -> V_30 = V_22 -> V_26 - ( V_22 -> V_28 + V_31 ) ;
if ( V_22 -> V_30 < 0 )
V_22 -> V_30 += V_22 -> V_32 ;
if ( ! V_4 -> V_11 -> V_12 )
return;
V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
if ( V_22 -> V_26 == V_22 -> V_28 && V_10 -> V_14 )
V_10 -> V_14 -> V_33 |= V_34 ;
}
static int F_18 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
int V_35 ;
if ( V_4 -> V_36 )
F_19 ( V_4 ) ;
F_20 ( & V_4 -> V_37 ) ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ )
F_21 ( & V_2 -> V_22 [ V_35 ] ) ;
F_22 ( & V_4 -> V_37 ) ;
if ( F_2 ( V_4 ) )
F_11 ( V_4 ) ;
return 0 ;
}
static int F_23 ( struct V_7 * V_4 , T_3 * V_39 )
{
T_2 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
int V_40 ;
V_10 -> V_41 = F_24 ( V_4 ) ;
if ( V_10 -> V_41 ) {
V_10 -> V_14 = ( V_42 * )
( ( V_43 * ) V_10 -> V_41 -> V_44 + V_39 -> V_45 ) ;
} else {
F_25 ( L_1 ) ;
}
if ( V_39 -> V_46 != 0 ) {
if ( F_5 ( V_2 ) -> V_47 != NULL ) {
F_18 ( V_4 ) ;
F_26 ( L_2
L_3 ) ;
return - V_48 ;
}
V_40 = F_27 ( V_4 ,
V_39 -> V_49 ,
V_39 -> V_46 ) ;
if ( V_40 ) {
F_18 ( V_4 ) ;
return V_40 ;
}
}
V_2 -> V_5 . V_50 = V_39 -> V_50 ;
V_2 -> V_5 . V_51 = V_39 -> V_51 ;
V_2 -> V_5 . V_52 = V_39 -> V_52 ;
V_2 -> V_5 . V_53 = 0 ;
if ( V_10 -> V_14 )
V_10 -> V_14 -> V_54 = 0 ;
V_2 -> V_5 . V_55 = 1 ;
return 0 ;
}
static int F_28 ( struct V_7 * V_4 )
{
T_2 * V_2 = ( T_2 * ) V_4 -> V_8 ;
struct V_21 * V_22 = F_5 ( V_2 ) ;
F_25 ( L_4 , V_56 ) ;
if ( V_22 -> V_57 == NULL ) {
F_26 ( L_5
L_6 ) ;
return - V_58 ;
}
if ( ! V_22 -> V_23 . V_59 ) {
F_26 ( L_7 ) ;
return - V_48 ;
}
F_25 ( L_8 ,
V_22 -> V_23 . V_59 ) ;
if ( V_22 -> V_23 . V_24 != 0 )
F_29 ( V_22 ) ;
else
F_8 ( V_4 ) ;
F_25 ( L_9 ) ;
return 0 ;
}
static int F_30 ( struct V_7 * V_4 , void * V_60 ,
struct V_61 * V_62 )
{
T_3 * V_39 = V_60 ;
int V_63 = 0 ;
if ( F_15 ( V_4 , V_25 ) )
return - V_64 ;
switch ( V_39 -> V_65 ) {
case V_66 :
V_63 = F_23 ( V_4 , V_39 ) ;
break;
case V_67 :
V_63 = F_18 ( V_4 ) ;
break;
case V_68 :
V_63 = F_28 ( V_4 ) ;
break;
default:
V_63 = - V_48 ;
break;
}
return V_63 ;
}
static int F_31 ( int V_69 )
{
switch ( ( ( V_69 >> 29 ) & 0x7 ) ) {
case 0x0 :
switch ( ( V_69 >> 23 ) & 0x3f ) {
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
return ( V_69 & 0xff ) + 2 ;
case 0x3 :
if ( ( ( V_69 >> 24 ) & 0x1f ) <= 0x18 )
return 1 ;
switch ( ( V_69 >> 24 ) & 0x1f ) {
case 0x1c :
return 1 ;
case 0x1d :
switch ( ( V_69 >> 16 ) & 0xff ) {
case 0x3 :
return ( V_69 & 0x1f ) + 2 ;
case 0x4 :
return ( V_69 & 0xf ) + 2 ;
default:
return ( V_69 & 0xffff ) + 2 ;
}
case 0x1e :
if ( V_69 & ( 1 << 23 ) )
return ( V_69 & 0xffff ) + 1 ;
else
return 1 ;
case 0x1f :
if ( ( V_69 & ( 1 << 23 ) ) == 0 )
return ( V_69 & 0x1ffff ) + 2 ;
else if ( V_69 & ( 1 << 17 ) )
if ( ( V_69 & 0xffff ) == 0 )
return 0 ;
else
return ( ( ( V_69 & 0xffff ) + 1 ) / 2 ) + 1 ;
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
static int F_32 ( struct V_7 * V_4 , int * V_70 , int V_71 )
{
T_2 * V_2 = V_4 -> V_8 ;
int V_35 , V_40 ;
if ( ( V_71 + 1 ) * sizeof( int ) >= F_5 ( V_2 ) -> V_32 - 8 )
return - V_48 ;
for ( V_35 = 0 ; V_35 < V_71 ; ) {
int V_72 = F_31 ( V_70 [ V_35 ] ) ;
if ( V_72 == 0 || V_35 + V_72 > V_71 )
return - V_48 ;
V_35 += V_72 ;
}
V_40 = F_33 ( ( V_71 + 1 ) & ~ 1 ) ;
if ( V_40 )
return V_40 ;
for ( V_35 = 0 ; V_35 < V_71 ; V_35 ++ )
F_34 ( V_70 [ V_35 ] ) ;
if ( V_71 & 1 )
F_34 ( 0 ) ;
F_35 () ;
return 0 ;
}
int
F_36 ( struct V_7 * V_4 ,
struct V_73 * V_74 ,
int V_75 , int V_76 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_40 ;
if ( V_74 -> V_77 <= V_74 -> y1 || V_74 -> V_78 <= V_74 -> V_79 ||
V_74 -> V_77 <= 0 || V_74 -> V_78 <= 0 ) {
F_26 ( L_10 ,
V_74 -> V_79 , V_74 -> y1 , V_74 -> V_78 , V_74 -> V_77 ) ;
return - V_48 ;
}
if ( F_9 ( V_4 ) -> V_19 >= 4 ) {
V_40 = F_33 ( 4 ) ;
if ( V_40 )
return V_40 ;
F_34 ( V_80 ) ;
F_34 ( ( V_74 -> V_79 & 0xffff ) | ( V_74 -> y1 << 16 ) ) ;
F_34 ( ( ( V_74 -> V_78 - 1 ) & 0xffff ) | ( ( V_74 -> V_77 - 1 ) << 16 ) ) ;
F_34 ( V_76 ) ;
} else {
V_40 = F_33 ( 6 ) ;
if ( V_40 )
return V_40 ;
F_34 ( V_81 ) ;
F_34 ( V_75 ) ;
F_34 ( ( V_74 -> V_79 & 0xffff ) | ( V_74 -> y1 << 16 ) ) ;
F_34 ( ( ( V_74 -> V_78 - 1 ) & 0xffff ) | ( ( V_74 -> V_77 - 1 ) << 16 ) ) ;
F_34 ( V_76 ) ;
F_34 ( 0 ) ;
}
F_35 () ;
return 0 ;
}
static void F_37 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
V_2 -> V_5 . V_82 ++ ;
if ( V_2 -> V_5 . V_82 > 0x7FFFFFFFUL )
V_2 -> V_5 . V_82 = 0 ;
if ( V_10 -> V_14 )
V_10 -> V_14 -> V_83 = V_2 -> V_5 . V_82 ;
if ( F_33 ( 4 ) == 0 ) {
F_34 ( V_84 ) ;
F_34 ( V_85 << V_86 ) ;
F_34 ( V_2 -> V_5 . V_82 ) ;
F_34 ( 0 ) ;
F_35 () ;
}
}
static int F_38 ( struct V_7 * V_4 ,
T_4 * V_69 ,
struct V_73 * V_87 ,
void * V_88 )
{
int V_89 = V_69 -> V_90 ;
int V_35 = 0 , V_91 , V_40 ;
if ( V_69 -> V_72 & 0x3 ) {
F_26 ( L_11 ) ;
return - V_48 ;
}
F_14 ( V_4 ) ;
V_91 = V_89 ? V_89 : 1 ;
for ( V_35 = 0 ; V_35 < V_91 ; V_35 ++ ) {
if ( V_35 < V_89 ) {
V_40 = F_36 ( V_4 , & V_87 [ V_35 ] ,
V_69 -> V_75 , V_69 -> V_76 ) ;
if ( V_40 )
return V_40 ;
}
V_40 = F_32 ( V_4 , V_88 , V_69 -> V_72 / 4 ) ;
if ( V_40 )
return V_40 ;
}
F_37 ( V_4 ) ;
return 0 ;
}
static int F_39 ( struct V_7 * V_4 ,
T_5 * V_92 ,
struct V_73 * V_87 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_89 = V_92 -> V_90 ;
int V_35 , V_91 , V_40 ;
if ( ( V_92 -> V_93 | V_92 -> V_94 ) & 0x7 ) {
F_26 ( L_11 ) ;
return - V_48 ;
}
F_14 ( V_4 ) ;
V_91 = V_89 ? V_89 : 1 ;
for ( V_35 = 0 ; V_35 < V_91 ; V_35 ++ ) {
if ( V_35 < V_89 ) {
V_40 = F_36 ( V_4 , & V_87 [ V_35 ] ,
V_92 -> V_75 , V_92 -> V_76 ) ;
if ( V_40 )
return V_40 ;
}
if ( ! F_40 ( V_4 ) && ! F_41 ( V_4 ) ) {
V_40 = F_33 ( 2 ) ;
if ( V_40 )
return V_40 ;
if ( F_9 ( V_4 ) -> V_19 >= 4 ) {
F_34 ( V_95 | ( 2 << 6 ) | V_96 ) ;
F_34 ( V_92 -> V_93 ) ;
} else {
F_34 ( V_95 | ( 2 << 6 ) ) ;
F_34 ( V_92 -> V_93 | V_97 ) ;
}
} else {
V_40 = F_33 ( 4 ) ;
if ( V_40 )
return V_40 ;
F_34 ( V_98 ) ;
F_34 ( V_92 -> V_93 | V_97 ) ;
F_34 ( V_92 -> V_93 + V_92 -> V_94 - 4 ) ;
F_34 ( 0 ) ;
}
F_35 () ;
}
if ( F_42 ( V_4 ) || F_43 ( V_4 ) ) {
if ( F_33 ( 2 ) == 0 ) {
F_34 ( V_99 | V_100 | V_101 ) ;
F_34 ( V_102 ) ;
F_35 () ;
}
}
F_37 ( V_4 ) ;
return 0 ;
}
static int F_44 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 =
V_4 -> V_11 -> V_12 -> V_13 ;
int V_40 ;
if ( ! V_10 -> V_14 )
return - V_48 ;
F_25 ( L_12 ,
V_56 ,
V_2 -> V_5 . V_53 ,
V_10 -> V_14 -> V_54 ) ;
F_14 ( V_4 ) ;
V_40 = F_33 ( 10 ) ;
if ( V_40 )
return V_40 ;
F_34 ( V_99 | V_103 ) ;
F_34 ( 0 ) ;
F_34 ( V_104 | V_105 ) ;
F_34 ( 0 ) ;
if ( V_2 -> V_5 . V_53 == 0 ) {
F_34 ( V_2 -> V_5 . V_51 ) ;
V_2 -> V_5 . V_53 = 1 ;
} else {
F_34 ( V_2 -> V_5 . V_52 ) ;
V_2 -> V_5 . V_53 = 0 ;
}
F_34 ( 0 ) ;
F_34 ( V_106 | V_107 ) ;
F_34 ( 0 ) ;
F_35 () ;
V_10 -> V_14 -> V_83 = V_2 -> V_5 . V_82 ++ ;
if ( F_33 ( 4 ) == 0 ) {
F_34 ( V_84 ) ;
F_34 ( V_85 << V_86 ) ;
F_34 ( V_2 -> V_5 . V_82 ) ;
F_34 ( 0 ) ;
F_35 () ;
}
V_10 -> V_14 -> V_54 = V_2 -> V_5 . V_53 ;
return 0 ;
}
static int F_45 ( struct V_7 * V_4 )
{
F_14 ( V_4 ) ;
return F_46 ( F_5 ( V_4 -> V_8 ) ) ;
}
static int F_47 ( struct V_7 * V_4 , void * V_60 ,
struct V_61 * V_62 )
{
int V_40 ;
if ( F_15 ( V_4 , V_25 ) )
return - V_64 ;
F_48 ( V_4 , V_62 ) ;
F_20 ( & V_4 -> V_37 ) ;
V_40 = F_45 ( V_4 ) ;
F_22 ( & V_4 -> V_37 ) ;
return V_40 ;
}
static int F_49 ( struct V_7 * V_4 , void * V_60 ,
struct V_61 * V_62 )
{
T_2 * V_2 = ( T_2 * ) V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
V_42 * V_14 = ( V_42 * )
V_10 -> V_14 ;
T_5 * V_92 = V_60 ;
int V_40 ;
struct V_73 * V_87 = NULL ;
if ( F_15 ( V_4 , V_25 ) )
return - V_64 ;
if ( ! V_2 -> V_5 . V_55 ) {
F_26 ( L_13 ) ;
return - V_48 ;
}
F_25 ( L_14 ,
V_92 -> V_93 , V_92 -> V_94 , V_92 -> V_90 ) ;
F_48 ( V_4 , V_62 ) ;
if ( V_92 -> V_90 < 0 )
return - V_48 ;
if ( V_92 -> V_90 ) {
V_87 = F_50 ( V_92 -> V_90 ,
sizeof( struct V_73 ) ,
V_108 ) ;
if ( V_87 == NULL )
return - V_58 ;
V_40 = F_51 ( V_87 , V_92 -> V_87 ,
V_92 -> V_90 *
sizeof( struct V_73 ) ) ;
if ( V_40 != 0 ) {
V_40 = - V_109 ;
goto V_110;
}
}
F_20 ( & V_4 -> V_37 ) ;
V_40 = F_39 ( V_4 , V_92 , V_87 ) ;
F_22 ( & V_4 -> V_37 ) ;
if ( V_14 )
V_14 -> V_15 = F_7 ( V_2 ) ;
V_110:
F_52 ( V_87 ) ;
return V_40 ;
}
static int F_53 ( struct V_7 * V_4 , void * V_60 ,
struct V_61 * V_62 )
{
T_2 * V_2 = ( T_2 * ) V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
V_42 * V_14 = ( V_42 * )
V_10 -> V_14 ;
T_4 * V_88 = V_60 ;
struct V_73 * V_87 = NULL ;
void * V_111 ;
int V_40 ;
F_25 ( L_15 ,
V_88 -> V_112 , V_88 -> V_72 , V_88 -> V_90 ) ;
if ( F_15 ( V_4 , V_25 ) )
return - V_64 ;
F_48 ( V_4 , V_62 ) ;
if ( V_88 -> V_90 < 0 )
return - V_48 ;
V_111 = F_54 ( V_88 -> V_72 , V_108 ) ;
if ( V_111 == NULL )
return - V_58 ;
V_40 = F_51 ( V_111 , V_88 -> V_112 , V_88 -> V_72 ) ;
if ( V_40 != 0 ) {
V_40 = - V_109 ;
goto V_113;
}
if ( V_88 -> V_90 ) {
V_87 = F_50 ( V_88 -> V_90 ,
sizeof( struct V_73 ) , V_108 ) ;
if ( V_87 == NULL ) {
V_40 = - V_58 ;
goto V_113;
}
V_40 = F_51 ( V_87 , V_88 -> V_87 ,
V_88 -> V_90 *
sizeof( struct V_73 ) ) ;
if ( V_40 != 0 ) {
V_40 = - V_109 ;
goto V_114;
}
}
F_20 ( & V_4 -> V_37 ) ;
V_40 = F_38 ( V_4 , V_88 , V_87 , V_111 ) ;
F_22 ( & V_4 -> V_37 ) ;
if ( V_40 ) {
F_26 ( L_16 ) ;
goto V_114;
}
if ( V_14 )
V_14 -> V_15 = F_7 ( V_2 ) ;
V_114:
F_52 ( V_87 ) ;
V_113:
F_52 ( V_111 ) ;
return V_40 ;
}
static int F_55 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
F_14 ( V_4 ) ;
F_25 ( L_17 ) ;
V_2 -> V_5 . V_82 ++ ;
if ( V_2 -> V_5 . V_82 > 0x7FFFFFFFUL )
V_2 -> V_5 . V_82 = 1 ;
if ( V_10 -> V_14 )
V_10 -> V_14 -> V_83 = V_2 -> V_5 . V_82 ;
if ( F_33 ( 4 ) == 0 ) {
F_34 ( V_84 ) ;
F_34 ( V_85 << V_86 ) ;
F_34 ( V_2 -> V_5 . V_82 ) ;
F_34 ( V_115 ) ;
F_35 () ;
}
return V_2 -> V_5 . V_82 ;
}
static int F_56 ( struct V_7 * V_4 , int V_116 )
{
T_2 * V_2 = ( T_2 * ) V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
int V_40 = 0 ;
struct V_21 * V_22 = F_5 ( V_2 ) ;
F_25 ( L_18 , V_116 ,
F_7 ( V_2 ) ) ;
if ( F_7 ( V_2 ) >= V_116 ) {
if ( V_10 -> V_14 )
V_10 -> V_14 -> V_15 = F_7 ( V_2 ) ;
return 0 ;
}
if ( V_10 -> V_14 )
V_10 -> V_14 -> V_33 |= V_117 ;
if ( V_22 -> V_118 ( V_22 ) ) {
F_57 ( V_40 , V_22 -> V_119 , 3 * V_120 ,
F_7 ( V_2 ) >= V_116 ) ;
V_22 -> V_121 ( V_22 ) ;
} else if ( F_58 ( F_7 ( V_2 ) >= V_116 , 3000 ) )
V_40 = - V_122 ;
if ( V_40 == - V_122 ) {
F_26 ( L_19 ,
F_7 ( V_2 ) , ( int ) V_2 -> V_5 . V_82 ) ;
}
return V_40 ;
}
static int F_59 ( struct V_7 * V_4 , void * V_60 ,
struct V_61 * V_62 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_6 * V_123 = V_60 ;
int V_124 ;
if ( F_15 ( V_4 , V_25 ) )
return - V_64 ;
if ( ! V_2 || ! F_5 ( V_2 ) -> V_57 ) {
F_26 ( L_20 ) ;
return - V_48 ;
}
F_48 ( V_4 , V_62 ) ;
F_20 ( & V_4 -> V_37 ) ;
V_124 = F_55 ( V_4 ) ;
F_22 ( & V_4 -> V_37 ) ;
if ( F_60 ( V_123 -> V_125 , & V_124 , sizeof( int ) ) ) {
F_26 ( L_21 ) ;
return - V_109 ;
}
return 0 ;
}
static int F_61 ( struct V_7 * V_4 , void * V_60 ,
struct V_61 * V_62 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_7 * V_126 = V_60 ;
if ( F_15 ( V_4 , V_25 ) )
return - V_64 ;
if ( ! V_2 ) {
F_26 ( L_20 ) ;
return - V_48 ;
}
return F_56 ( V_4 , V_126 -> V_125 ) ;
}
static int F_62 ( struct V_7 * V_4 , void * V_60 ,
struct V_61 * V_62 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_8 * V_127 = V_60 ;
if ( F_15 ( V_4 , V_25 ) )
return - V_64 ;
if ( ! V_2 ) {
F_26 ( L_20 ) ;
return - V_48 ;
}
V_127 -> V_127 = V_128 | V_129 ;
return 0 ;
}
static int F_63 ( struct V_7 * V_4 , void * V_60 ,
struct V_61 * V_62 )
{
return - V_48 ;
}
static int F_64 ( struct V_7 * V_4 , void * V_60 ,
struct V_61 * V_62 )
{
int V_40 ;
if ( F_15 ( V_4 , V_25 ) )
return - V_64 ;
F_25 ( L_4 , V_56 ) ;
F_48 ( V_4 , V_62 ) ;
F_20 ( & V_4 -> V_37 ) ;
V_40 = F_44 ( V_4 ) ;
F_22 ( & V_4 -> V_37 ) ;
return V_40 ;
}
static int F_65 ( struct V_7 * V_4 , void * V_60 ,
struct V_61 * V_62 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_9 * V_130 = V_60 ;
int V_131 ;
if ( ! V_2 ) {
F_26 ( L_20 ) ;
return - V_48 ;
}
switch ( V_130 -> V_130 ) {
case V_132 :
V_131 = V_4 -> V_133 -> V_134 ? 1 : 0 ;
break;
case V_135 :
V_131 = V_2 -> V_5 . V_55 ? 1 : 0 ;
break;
case V_136 :
V_131 = F_7 ( V_2 ) ;
break;
case V_137 :
V_131 = V_4 -> V_138 ;
break;
case V_139 :
V_131 = 1 ;
break;
case V_140 :
V_131 = V_2 -> V_141 - V_2 -> V_142 ;
break;
case V_143 :
V_131 = V_2 -> V_144 ? 1 : 0 ;
break;
case V_145 :
V_131 = 1 ;
break;
case V_146 :
V_131 = 1 ;
break;
case V_147 :
V_131 = F_66 ( & V_2 -> V_22 [ V_148 ] ) ;
break;
case V_149 :
V_131 = F_66 ( & V_2 -> V_22 [ V_150 ] ) ;
break;
case V_151 :
V_131 = F_66 ( & V_2 -> V_22 [ V_152 ] ) ;
break;
case V_153 :
V_131 = 1 ;
break;
case V_154 :
V_131 = 1 ;
break;
case V_155 :
V_131 = F_9 ( V_4 ) -> V_19 >= 4 ;
break;
case V_156 :
V_131 = 1 ;
break;
case V_157 :
V_131 = 1 ;
break;
case V_158 :
V_131 = F_67 ( V_4 ) ;
break;
case V_159 :
V_131 = F_68 ( V_4 ) ;
break;
case V_160 :
V_131 = V_2 -> V_161 . V_162 ? 1 : 0 ;
break;
case V_163 :
V_131 = 1 ;
break;
case V_164 :
V_131 = F_69 ( V_4 ) ;
break;
case V_165 :
V_131 = 1 ;
break;
case V_166 :
V_131 = F_70 ( V_167 ) ;
break;
case V_168 :
V_131 = 1 ;
break;
case V_169 :
V_131 = 1 ;
break;
case V_170 :
V_131 = 1 ;
break;
default:
F_71 ( L_22 , V_130 -> V_130 ) ;
return - V_48 ;
}
if ( F_60 ( V_130 -> V_131 , & V_131 , sizeof( int ) ) ) {
F_26 ( L_23 ) ;
return - V_109 ;
}
return 0 ;
}
static int F_72 ( struct V_7 * V_4 , void * V_60 ,
struct V_61 * V_62 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_10 * V_130 = V_60 ;
if ( ! V_2 ) {
F_26 ( L_20 ) ;
return - V_48 ;
}
switch ( V_130 -> V_130 ) {
case V_171 :
break;
case V_172 :
break;
case V_173 :
V_2 -> V_5 . V_55 = V_130 -> V_131 ? 1 : 0 ;
break;
case V_174 :
if ( V_130 -> V_131 > V_2 -> V_141 ||
V_130 -> V_131 < 0 )
return - V_48 ;
V_2 -> V_142 = V_130 -> V_131 ;
break;
default:
F_25 ( L_24 ,
V_130 -> V_130 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_73 ( struct V_7 * V_4 , void * V_60 ,
struct V_61 * V_62 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_11 * V_175 = V_60 ;
struct V_21 * V_22 ;
if ( F_15 ( V_4 , V_25 ) )
return - V_64 ;
if ( ! F_2 ( V_4 ) )
return - V_48 ;
if ( ! V_2 ) {
F_26 ( L_20 ) ;
return - V_48 ;
}
if ( F_15 ( V_4 , V_25 ) ) {
F_74 ( 1 , L_25 ) ;
return 0 ;
}
F_25 ( L_26 , ( T_1 ) V_175 -> V_16 ) ;
V_22 = F_5 ( V_2 ) ;
V_22 -> V_23 . V_24 = V_175 -> V_16 & ( 0x1ffff << 12 ) ;
V_2 -> V_5 . V_6 =
F_75 ( V_2 -> V_176 . V_177 + V_175 -> V_16 , 4096 ) ;
if ( V_2 -> V_5 . V_6 == NULL ) {
F_18 ( V_4 ) ;
V_22 -> V_23 . V_24 = 0 ;
F_26 ( L_5
L_27 ) ;
return - V_58 ;
}
F_76 ( V_2 -> V_5 . V_6 , 0 , V_178 ) ;
F_10 ( V_20 , V_22 -> V_23 . V_24 ) ;
F_25 ( L_28 ,
V_22 -> V_23 . V_24 ) ;
F_25 ( L_29 ,
V_22 -> V_23 . V_59 ) ;
return 0 ;
}
static int F_77 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
V_2 -> V_179 = F_78 ( 0 , F_79 ( 0 , 0 ) ) ;
if ( ! V_2 -> V_179 ) {
F_26 ( L_30 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_80 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
int V_3 = F_9 ( V_4 ) -> V_19 >= 4 ? V_180 : V_181 ;
T_1 V_182 , V_183 = 0 ;
T_12 V_184 ;
int V_40 ;
if ( F_9 ( V_4 ) -> V_19 >= 4 )
F_81 ( V_2 -> V_179 , V_3 + 4 , & V_183 ) ;
F_81 ( V_2 -> V_179 , V_3 , & V_182 ) ;
V_184 = ( ( T_12 ) V_183 << 32 ) | V_182 ;
#ifdef F_82
if ( V_184 &&
F_83 ( V_184 , V_184 + V_185 ) )
return 0 ;
#endif
V_2 -> V_186 . V_187 = L_31 ;
V_2 -> V_186 . V_188 = V_189 ;
V_40 = F_84 ( V_2 -> V_179 -> V_190 ,
& V_2 -> V_186 ,
V_185 , V_185 ,
V_191 ,
0 , V_192 ,
V_2 -> V_179 ) ;
if ( V_40 ) {
F_25 ( L_32 , V_40 ) ;
V_2 -> V_186 . V_93 = 0 ;
return V_40 ;
}
if ( F_9 ( V_4 ) -> V_19 >= 4 )
F_85 ( V_2 -> V_179 , V_3 + 4 ,
F_86 ( V_2 -> V_186 . V_93 ) ) ;
F_85 ( V_2 -> V_179 , V_3 ,
F_87 ( V_2 -> V_186 . V_93 ) ) ;
return 0 ;
}
static void
F_88 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
int V_193 = F_9 ( V_4 ) -> V_19 >= 4 ? V_180 : V_181 ;
T_1 V_194 ;
bool V_195 ;
V_2 -> V_196 = false ;
if ( F_89 ( V_4 ) || F_90 ( V_4 ) ) {
F_81 ( V_2 -> V_179 , V_197 , & V_194 ) ;
V_195 = ! ! ( V_194 & V_198 ) ;
} else {
F_81 ( V_2 -> V_179 , V_193 , & V_194 ) ;
V_195 = V_194 & 1 ;
}
if ( V_195 )
return;
if ( F_80 ( V_4 ) )
return;
V_2 -> V_196 = true ;
if ( F_89 ( V_4 ) || F_90 ( V_4 ) ) {
F_85 ( V_2 -> V_179 , V_197 ,
V_194 | V_198 ) ;
} else {
F_81 ( V_2 -> V_179 , V_193 , & V_194 ) ;
F_85 ( V_2 -> V_179 , V_193 , V_194 | 1 ) ;
}
}
static void
F_91 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
int V_193 = F_9 ( V_4 ) -> V_19 >= 4 ? V_180 : V_181 ;
T_1 V_194 ;
if ( V_2 -> V_196 ) {
if ( F_89 ( V_4 ) || F_90 ( V_4 ) ) {
F_81 ( V_2 -> V_179 , V_197 , & V_194 ) ;
V_194 &= ~ V_198 ;
F_85 ( V_2 -> V_179 , V_197 , V_194 ) ;
} else {
F_81 ( V_2 -> V_179 , V_193 , & V_194 ) ;
V_194 &= ~ 1 ;
F_85 ( V_2 -> V_179 , V_193 , V_194 ) ;
}
}
if ( V_2 -> V_186 . V_93 )
F_92 ( & V_2 -> V_186 ) ;
}
static unsigned int F_93 ( void * V_199 , bool V_200 )
{
struct V_7 * V_4 = V_199 ;
F_94 ( V_4 , V_200 ) ;
if ( V_200 )
return V_201 | V_202 |
V_203 | V_204 ;
else
return V_203 | V_204 ;
}
static void F_95 ( struct V_205 * V_133 , enum V_206 V_200 )
{
struct V_7 * V_4 = F_96 ( V_133 ) ;
T_13 V_207 = { . V_208 = V_209 } ;
if ( V_200 == V_210 ) {
F_97 ( L_33 ) ;
V_4 -> V_211 = V_212 ;
F_98 ( V_4 -> V_133 , V_213 ) ;
F_99 ( V_4 ) ;
V_4 -> V_211 = V_214 ;
} else {
F_100 ( L_34 ) ;
V_4 -> V_211 = V_212 ;
F_101 ( V_4 , V_207 ) ;
V_4 -> V_211 = V_215 ;
}
}
static bool F_102 ( struct V_205 * V_133 )
{
struct V_7 * V_4 = F_96 ( V_133 ) ;
bool V_216 ;
F_103 ( & V_4 -> V_217 ) ;
V_216 = ( V_4 -> V_218 == 0 ) ;
F_104 ( & V_4 -> V_217 ) ;
return V_216 ;
}
static int F_105 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_40 ;
V_40 = F_106 ( V_4 ) ;
if ( V_40 )
F_107 ( L_35 ) ;
V_40 = F_108 ( V_4 -> V_133 , V_4 , NULL , F_93 ) ;
if ( V_40 && V_40 != - V_64 )
goto V_219;
F_109 () ;
V_40 = F_110 ( V_4 -> V_133 , & V_220 , false ) ;
if ( V_40 )
goto V_221;
V_40 = F_111 ( V_4 ) ;
if ( V_40 )
goto V_222;
V_40 = F_112 ( V_4 ) ;
if ( V_40 )
goto V_223;
F_113 ( V_4 ) ;
V_40 = F_114 ( V_4 ) ;
if ( V_40 )
goto V_224;
F_115 ( & V_2 -> V_225 , V_226 ) ;
F_116 ( V_4 ) ;
V_4 -> V_227 = 1 ;
if ( F_9 ( V_4 ) -> V_228 == 0 )
return 0 ;
V_40 = F_117 ( V_4 ) ;
if ( V_40 )
goto V_229;
F_118 ( V_4 ) ;
F_119 ( V_4 ) ;
V_2 -> V_230 = true ;
F_120 ( V_4 ) ;
return 0 ;
V_229:
F_20 ( & V_4 -> V_37 ) ;
F_121 ( V_4 ) ;
F_122 ( V_4 ) ;
F_22 ( & V_4 -> V_37 ) ;
F_123 ( V_4 ) ;
F_124 ( & V_2 -> V_176 . V_231 . V_161 ) ;
V_224:
F_19 ( V_4 ) ;
V_223:
F_125 ( V_4 ) ;
V_222:
F_126 ( V_4 -> V_133 ) ;
V_221:
F_108 ( V_4 -> V_133 , NULL , NULL , NULL ) ;
V_219:
return V_40 ;
}
int F_127 ( struct V_7 * V_4 , struct V_232 * V_12 )
{
struct V_9 * V_10 ;
V_10 = F_128 ( sizeof( * V_10 ) , V_108 ) ;
if ( ! V_10 )
return - V_58 ;
V_12 -> V_13 = V_10 ;
return 0 ;
}
void F_129 ( struct V_7 * V_4 , struct V_232 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_13 ;
if ( ! V_10 )
return;
F_52 ( V_10 ) ;
V_12 -> V_13 = NULL ;
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_233 * V_234 ;
struct V_205 * V_133 = V_2 -> V_4 -> V_133 ;
bool V_11 ;
V_234 = F_131 ( 1 ) ;
if ( ! V_234 )
return;
V_234 -> V_235 [ 0 ] . V_231 = V_2 -> V_176 . V_177 ;
V_234 -> V_235 [ 0 ] . V_32 = V_2 -> V_176 . V_236 ;
V_11 =
V_133 -> V_237 [ V_238 ] . V_188 & V_239 ;
F_132 ( V_234 , L_36 , V_11 ) ;
F_52 ( V_234 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
const struct V_240 * V_241 = V_2 -> V_241 ;
#define F_134 ( V_187 ) "%s"
#define F_135
#define F_136 ( V_187 ) info->name ? #name "," : ""
#define F_137 ,
F_25 ( L_37
F_138 ( F_134 , F_135 ) ,
V_241 -> V_19 ,
V_2 -> V_4 -> V_133 -> V_242 ,
F_138 ( F_136 , F_137 ) ) ;
#undef F_134
#undef F_135
#undef F_136
#undef F_137
}
int F_139 ( struct V_7 * V_4 , unsigned long V_188 )
{
struct V_1 * V_2 ;
struct V_240 * V_241 ;
int V_40 = 0 , V_243 , V_244 ;
T_14 V_245 ;
V_241 = (struct V_240 * ) V_188 ;
if ( V_241 -> V_19 >= 6 && ! F_15 ( V_4 , V_25 ) )
return - V_64 ;
V_4 -> V_246 += 4 ;
V_4 -> V_247 [ 6 ] = V_248 ;
V_4 -> V_247 [ 7 ] = V_249 ;
V_4 -> V_247 [ 8 ] = V_250 ;
V_4 -> V_247 [ 9 ] = V_251 ;
V_2 = F_128 ( sizeof( T_2 ) , V_108 ) ;
if ( V_2 == NULL )
return - V_58 ;
V_4 -> V_8 = ( void * ) V_2 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_241 = V_241 ;
F_140 ( & V_2 -> V_252 ) ;
F_140 ( & V_2 -> V_253 . V_254 ) ;
F_140 ( & V_2 -> V_255 . V_254 ) ;
F_140 ( & V_2 -> V_256 . V_254 ) ;
F_140 ( & V_2 -> V_161 . V_257 ) ;
F_141 ( & V_2 -> V_258 ) ;
F_141 ( & V_2 -> V_259 . V_260 ) ;
F_141 ( & V_2 -> V_261 ) ;
F_141 ( & V_2 -> V_262 . V_254 ) ;
V_2 -> V_262 . V_263 = false ;
V_2 -> V_262 . V_264 = false ;
V_2 -> V_262 . V_265 = false ;
V_2 -> V_262 . V_195 = false ;
V_2 -> V_262 . V_266 = 2 ;
F_142 ( & V_2 -> V_262 . V_267 , V_268 ) ;
F_133 ( V_2 ) ;
if ( F_143 ( V_4 ) )
F_107 ( L_38
L_39 ) ;
if ( F_77 ( V_4 ) ) {
V_40 = - V_269 ;
goto V_270;
}
V_243 = F_144 ( V_4 ) ? 1 : 0 ;
if ( V_241 -> V_19 < 5 )
V_244 = 512 * 1024 ;
else
V_244 = 2 * 1024 * 1024 ;
V_2 -> V_271 = F_145 ( V_4 -> V_133 , V_243 , V_244 ) ;
if ( ! V_2 -> V_271 ) {
F_26 ( L_40 ) ;
V_40 = - V_269 ;
goto V_272;
}
F_146 ( V_4 ) ;
if ( F_147 ( V_4 ) && ( F_148 ( V_273 ) == 1 ) ) {
V_2 -> V_274 = 128 ;
F_107 ( L_41 , V_2 -> V_274 ) ;
}
V_40 = F_149 ( V_4 ) ;
if ( V_40 )
goto V_272;
if ( F_15 ( V_4 , V_25 ) )
F_130 ( V_2 ) ;
F_150 ( V_4 -> V_133 ) ;
if ( F_144 ( V_4 ) )
F_151 ( & V_4 -> V_133 -> V_4 , F_152 ( 30 ) ) ;
if ( F_153 ( V_4 ) || F_154 ( V_4 ) )
F_151 ( & V_4 -> V_133 -> V_4 , F_152 ( 32 ) ) ;
V_245 = V_2 -> V_176 . V_236 ;
V_2 -> V_176 . V_275 =
F_155 ( V_2 -> V_176 . V_177 ,
V_245 ) ;
if ( V_2 -> V_176 . V_275 == NULL ) {
V_40 = - V_269 ;
goto V_276;
}
V_2 -> V_176 . V_277 = F_156 ( V_2 -> V_176 . V_177 ,
V_245 ) ;
V_2 -> V_278 = F_157 ( L_42 , 0 ) ;
if ( V_2 -> V_278 == NULL ) {
F_26 ( L_43 ) ;
V_40 = - V_58 ;
goto V_279;
}
F_158 ( V_4 ) ;
F_159 ( V_4 ) ;
F_160 ( V_4 ) ;
F_161 ( V_4 ) ;
F_162 ( V_4 ) ;
F_88 ( V_4 ) ;
F_163 ( V_4 ) ;
F_164 ( V_4 ) ;
F_165 ( V_4 ) ;
F_166 ( V_4 ) ;
if ( ! F_167 ( V_4 ) && ! F_168 ( V_4 ) )
F_169 ( V_4 -> V_133 ) ;
V_2 -> V_280 = 1 ;
if ( F_170 ( V_4 ) )
V_2 -> V_280 = 2 ;
if ( F_9 ( V_4 ) -> V_228 ) {
V_40 = F_171 ( V_4 , F_9 ( V_4 ) -> V_228 ) ;
if ( V_40 )
goto V_281;
}
if ( F_172 ( V_4 ) )
F_173 ( V_4 ) ;
if ( F_15 ( V_4 , V_25 ) ) {
V_40 = F_105 ( V_4 ) ;
if ( V_40 < 0 ) {
F_26 ( L_44 ) ;
goto V_281;
}
} else {
V_2 -> V_282 . V_283 = 1 ;
}
F_174 ( V_4 ) ;
if ( F_9 ( V_4 ) -> V_228 ) {
F_175 ( V_4 ) ;
F_176 () ;
}
if ( F_43 ( V_4 ) )
F_177 ( V_2 ) ;
return 0 ;
V_281:
if ( V_2 -> V_161 . V_284 . V_285 )
F_178 ( & V_2 -> V_161 . V_284 ) ;
if ( V_4 -> V_133 -> V_286 )
F_179 ( V_4 -> V_133 ) ;
F_180 ( V_4 ) ;
F_91 ( V_4 ) ;
F_181 ( V_2 -> V_278 ) ;
V_279:
F_182 ( V_2 -> V_176 . V_277 ) ;
F_183 ( V_2 -> V_176 . V_275 ) ;
V_2 -> V_176 . V_231 . V_287 ( & V_2 -> V_176 . V_231 ) ;
V_276:
F_184 ( V_4 -> V_133 , V_2 -> V_271 ) ;
V_272:
F_185 ( V_2 -> V_179 ) ;
V_270:
F_52 ( V_2 ) ;
return V_40 ;
}
int F_186 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_40 ;
F_187 () ;
if ( F_172 ( V_4 ) ) {
F_188 ( V_4 , true ) ;
F_189 ( V_4 ) ;
}
F_190 ( V_4 ) ;
if ( V_2 -> V_161 . V_284 . V_285 )
F_178 ( & V_2 -> V_161 . V_284 ) ;
F_20 ( & V_4 -> V_37 ) ;
V_40 = F_191 ( V_4 ) ;
if ( V_40 )
F_26 ( L_45 , V_40 ) ;
F_192 ( V_4 ) ;
F_22 ( & V_4 -> V_37 ) ;
F_193 ( & V_2 -> V_161 . V_288 ) ;
F_183 ( V_2 -> V_176 . V_275 ) ;
F_182 ( V_2 -> V_176 . V_277 ) ;
F_194 () ;
if ( F_15 ( V_4 , V_25 ) ) {
F_195 ( V_4 ) ;
F_196 ( V_4 ) ;
F_197 ( & V_2 -> V_225 ) ;
if ( V_2 -> V_289 . V_290 && V_2 -> V_289 . V_291 ) {
F_52 ( V_2 -> V_289 . V_290 ) ;
V_2 -> V_289 . V_290 = NULL ;
V_2 -> V_289 . V_291 = 0 ;
}
F_126 ( V_4 -> V_133 ) ;
F_108 ( V_4 -> V_133 , NULL , NULL , NULL ) ;
}
F_198 ( & V_2 -> V_253 . V_292 ) ;
F_197 ( & V_2 -> V_253 . V_293 ) ;
F_199 ( V_4 ) ;
F_193 ( & V_2 -> V_262 . V_267 ) ;
if ( V_4 -> V_133 -> V_286 )
F_179 ( V_4 -> V_133 ) ;
F_200 ( V_4 ) ;
if ( F_15 ( V_4 , V_25 ) ) {
F_201 ( V_2 -> V_278 ) ;
F_20 ( & V_4 -> V_37 ) ;
F_202 ( V_4 ) ;
F_121 ( V_4 ) ;
F_122 ( V_4 ) ;
F_22 ( & V_4 -> V_37 ) ;
F_123 ( V_4 ) ;
F_125 ( V_4 ) ;
if ( ! F_2 ( V_4 ) )
F_11 ( V_4 ) ;
}
F_203 ( & V_2 -> V_176 . V_231 . V_294 ) ;
F_204 ( ! F_205 ( & V_2 -> V_295 ) ) ;
F_124 ( & V_2 -> V_176 . V_231 . V_161 ) ;
if ( V_2 -> V_271 != NULL )
F_184 ( V_4 -> V_133 , V_2 -> V_271 ) ;
F_180 ( V_4 ) ;
F_91 ( V_4 ) ;
F_181 ( V_2 -> V_278 ) ;
F_206 ( & V_2 -> V_296 ) ;
V_2 -> V_176 . V_231 . V_287 ( & V_2 -> V_176 . V_231 ) ;
if ( V_2 -> V_297 )
F_207 ( V_2 -> V_297 ) ;
F_185 ( V_2 -> V_179 ) ;
F_52 ( V_4 -> V_8 ) ;
return 0 ;
}
int F_208 ( struct V_7 * V_4 , struct V_61 * V_298 )
{
struct V_299 * V_62 ;
F_25 ( L_17 ) ;
V_62 = F_128 ( sizeof( * V_62 ) , V_108 ) ;
if ( ! V_62 )
return - V_58 ;
V_298 -> V_13 = V_62 ;
F_140 ( & V_62 -> V_161 . V_254 ) ;
F_209 ( & V_62 -> V_161 . V_300 ) ;
F_210 ( & V_62 -> V_301 ) ;
return 0 ;
}
void F_211 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
if ( ! V_2 )
return;
if ( F_15 ( V_4 , V_25 ) ) {
F_212 ( V_4 ) ;
F_213 () ;
return;
}
F_214 ( V_4 ) ;
F_18 ( V_4 ) ;
}
void F_215 ( struct V_7 * V_4 , struct V_61 * V_62 )
{
F_216 ( V_4 , V_62 ) ;
F_217 ( V_4 , V_62 ) ;
}
void F_218 ( struct V_7 * V_4 , struct V_61 * V_298 )
{
struct V_299 * V_62 = V_298 -> V_13 ;
F_52 ( V_62 ) ;
}
int F_219 ( struct V_7 * V_4 )
{
return 1 ;
}
