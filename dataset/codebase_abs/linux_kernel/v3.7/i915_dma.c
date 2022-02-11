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
static int F_11 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
V_2 -> V_17 =
F_12 ( V_4 , V_21 , V_21 ) ;
if ( ! V_2 -> V_17 ) {
F_13 ( L_1 ) ;
return - V_22 ;
}
F_14 ( ( void V_23 V_24 * ) V_2 -> V_17 -> V_25 ,
0 , V_21 ) ;
F_8 ( V_4 ) ;
F_15 ( L_2 ) ;
return 0 ;
}
static void F_16 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
struct V_26 * V_27 = F_5 ( V_2 ) ;
if ( V_2 -> V_17 ) {
F_17 ( V_4 , V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
}
if ( V_27 -> V_28 . V_29 ) {
V_27 -> V_28 . V_29 = 0 ;
F_18 ( V_2 -> V_5 . V_6 ) ;
}
F_10 ( V_20 , 0x1ffff000 ) ;
}
void F_19 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_26 * V_27 = F_5 ( V_2 ) ;
if ( F_20 ( V_4 , V_30 ) )
return;
V_27 -> V_31 = F_21 ( V_27 ) & V_32 ;
V_27 -> V_33 = F_22 ( V_27 ) & V_34 ;
V_27 -> V_35 = V_27 -> V_31 - ( V_27 -> V_33 + 8 ) ;
if ( V_27 -> V_35 < 0 )
V_27 -> V_35 += V_27 -> V_36 ;
if ( ! V_4 -> V_11 -> V_12 )
return;
V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
if ( V_27 -> V_31 == V_27 -> V_33 && V_10 -> V_14 )
V_10 -> V_14 -> V_37 |= V_38 ;
}
static int F_23 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
int V_39 ;
if ( V_4 -> V_40 )
F_24 ( V_4 ) ;
F_25 ( & V_4 -> V_41 ) ;
for ( V_39 = 0 ; V_39 < V_42 ; V_39 ++ )
F_26 ( & V_2 -> V_27 [ V_39 ] ) ;
F_27 ( & V_4 -> V_41 ) ;
if ( F_2 ( V_4 ) )
F_16 ( V_4 ) ;
return 0 ;
}
static int F_28 ( struct V_7 * V_4 , T_3 * V_43 )
{
T_2 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
int V_44 ;
V_10 -> V_45 = F_29 ( V_4 ) ;
if ( V_10 -> V_45 ) {
V_10 -> V_14 = ( V_46 * )
( ( V_47 * ) V_10 -> V_45 -> V_48 + V_43 -> V_49 ) ;
} else {
F_15 ( L_3 ) ;
}
if ( V_43 -> V_50 != 0 ) {
if ( F_5 ( V_2 ) -> V_51 != NULL ) {
F_23 ( V_4 ) ;
F_13 ( L_4
L_5 ) ;
return - V_52 ;
}
V_44 = F_30 ( V_4 ,
V_43 -> V_53 ,
V_43 -> V_50 ) ;
if ( V_44 ) {
F_23 ( V_4 ) ;
return V_44 ;
}
}
V_2 -> V_5 . V_54 = V_43 -> V_54 ;
V_2 -> V_5 . V_55 = V_43 -> V_55 ;
V_2 -> V_5 . V_56 = V_43 -> V_56 ;
V_2 -> V_5 . V_57 = 0 ;
if ( V_10 -> V_14 )
V_10 -> V_14 -> V_58 = 0 ;
V_2 -> V_5 . V_59 = 1 ;
return 0 ;
}
static int F_31 ( struct V_7 * V_4 )
{
T_2 * V_2 = ( T_2 * ) V_4 -> V_8 ;
struct V_26 * V_27 = F_5 ( V_2 ) ;
F_15 ( L_6 , V_60 ) ;
if ( V_27 -> V_61 == NULL ) {
F_13 ( L_7
L_8 ) ;
return - V_22 ;
}
if ( ! V_27 -> V_28 . V_62 ) {
F_13 ( L_9 ) ;
return - V_52 ;
}
F_15 ( L_10 ,
V_27 -> V_28 . V_62 ) ;
if ( V_27 -> V_28 . V_29 != 0 )
F_32 ( V_27 ) ;
else
F_8 ( V_4 ) ;
F_15 ( L_2 ) ;
return 0 ;
}
static int F_33 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
T_3 * V_43 = V_63 ;
int V_66 = 0 ;
if ( F_20 ( V_4 , V_30 ) )
return - V_67 ;
switch ( V_43 -> V_68 ) {
case V_69 :
V_66 = F_28 ( V_4 , V_43 ) ;
break;
case V_70 :
V_66 = F_23 ( V_4 ) ;
break;
case V_71 :
V_66 = F_31 ( V_4 ) ;
break;
default:
V_66 = - V_52 ;
break;
}
return V_66 ;
}
static int F_34 ( int V_72 )
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
static int F_35 ( struct V_7 * V_4 , int * V_73 , int V_74 )
{
T_2 * V_2 = V_4 -> V_8 ;
int V_39 , V_44 ;
if ( ( V_74 + 1 ) * sizeof( int ) >= F_5 ( V_2 ) -> V_36 - 8 )
return - V_52 ;
for ( V_39 = 0 ; V_39 < V_74 ; ) {
int V_75 = F_34 ( V_73 [ V_39 ] ) ;
if ( V_75 == 0 || V_39 + V_75 > V_74 )
return - V_52 ;
V_39 += V_75 ;
}
V_44 = F_36 ( ( V_74 + 1 ) & ~ 1 ) ;
if ( V_44 )
return V_44 ;
for ( V_39 = 0 ; V_39 < V_74 ; V_39 ++ )
F_37 ( V_73 [ V_39 ] ) ;
if ( V_74 & 1 )
F_37 ( 0 ) ;
F_38 () ;
return 0 ;
}
int
F_39 ( struct V_7 * V_4 ,
struct V_76 * V_77 ,
int V_78 , int V_79 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_44 ;
if ( V_77 -> V_80 <= V_77 -> y1 || V_77 -> V_81 <= V_77 -> V_82 ||
V_77 -> V_80 <= 0 || V_77 -> V_81 <= 0 ) {
F_13 ( L_11 ,
V_77 -> V_82 , V_77 -> y1 , V_77 -> V_81 , V_77 -> V_80 ) ;
return - V_52 ;
}
if ( F_9 ( V_4 ) -> V_19 >= 4 ) {
V_44 = F_36 ( 4 ) ;
if ( V_44 )
return V_44 ;
F_37 ( V_83 ) ;
F_37 ( ( V_77 -> V_82 & 0xffff ) | ( V_77 -> y1 << 16 ) ) ;
F_37 ( ( ( V_77 -> V_81 - 1 ) & 0xffff ) | ( ( V_77 -> V_80 - 1 ) << 16 ) ) ;
F_37 ( V_79 ) ;
} else {
V_44 = F_36 ( 6 ) ;
if ( V_44 )
return V_44 ;
F_37 ( V_84 ) ;
F_37 ( V_78 ) ;
F_37 ( ( V_77 -> V_82 & 0xffff ) | ( V_77 -> y1 << 16 ) ) ;
F_37 ( ( ( V_77 -> V_81 - 1 ) & 0xffff ) | ( ( V_77 -> V_80 - 1 ) << 16 ) ) ;
F_37 ( V_79 ) ;
F_37 ( 0 ) ;
}
F_38 () ;
return 0 ;
}
static void F_40 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
V_2 -> V_85 ++ ;
if ( V_2 -> V_85 > 0x7FFFFFFFUL )
V_2 -> V_85 = 0 ;
if ( V_10 -> V_14 )
V_10 -> V_14 -> V_86 = V_2 -> V_85 ;
if ( F_36 ( 4 ) == 0 ) {
F_37 ( V_87 ) ;
F_37 ( V_88 << V_89 ) ;
F_37 ( V_2 -> V_85 ) ;
F_37 ( 0 ) ;
F_38 () ;
}
}
static int F_41 ( struct V_7 * V_4 ,
T_4 * V_72 ,
struct V_76 * V_90 ,
void * V_91 )
{
int V_92 = V_72 -> V_93 ;
int V_39 = 0 , V_94 , V_44 ;
if ( V_72 -> V_75 & 0x3 ) {
F_13 ( L_12 ) ;
return - V_52 ;
}
F_19 ( V_4 ) ;
V_94 = V_92 ? V_92 : 1 ;
for ( V_39 = 0 ; V_39 < V_94 ; V_39 ++ ) {
if ( V_39 < V_92 ) {
V_44 = F_39 ( V_4 , & V_90 [ V_39 ] ,
V_72 -> V_78 , V_72 -> V_79 ) ;
if ( V_44 )
return V_44 ;
}
V_44 = F_35 ( V_4 , V_91 , V_72 -> V_75 / 4 ) ;
if ( V_44 )
return V_44 ;
}
F_40 ( V_4 ) ;
return 0 ;
}
static int F_42 ( struct V_7 * V_4 ,
T_5 * V_95 ,
struct V_76 * V_90 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_92 = V_95 -> V_93 ;
int V_39 , V_94 , V_44 ;
if ( ( V_95 -> V_96 | V_95 -> V_97 ) & 0x7 ) {
F_13 ( L_12 ) ;
return - V_52 ;
}
F_19 ( V_4 ) ;
V_94 = V_92 ? V_92 : 1 ;
for ( V_39 = 0 ; V_39 < V_94 ; V_39 ++ ) {
if ( V_39 < V_92 ) {
V_44 = F_39 ( V_4 , & V_90 [ V_39 ] ,
V_95 -> V_78 , V_95 -> V_79 ) ;
if ( V_44 )
return V_44 ;
}
if ( ! F_43 ( V_4 ) && ! F_44 ( V_4 ) ) {
V_44 = F_36 ( 2 ) ;
if ( V_44 )
return V_44 ;
if ( F_9 ( V_4 ) -> V_19 >= 4 ) {
F_37 ( V_98 | ( 2 << 6 ) | V_99 ) ;
F_37 ( V_95 -> V_96 ) ;
} else {
F_37 ( V_98 | ( 2 << 6 ) ) ;
F_37 ( V_95 -> V_96 | V_100 ) ;
}
} else {
V_44 = F_36 ( 4 ) ;
if ( V_44 )
return V_44 ;
F_37 ( V_101 ) ;
F_37 ( V_95 -> V_96 | V_100 ) ;
F_37 ( V_95 -> V_96 + V_95 -> V_97 - 4 ) ;
F_37 ( 0 ) ;
}
F_38 () ;
}
if ( F_45 ( V_4 ) || F_46 ( V_4 ) ) {
if ( F_36 ( 2 ) == 0 ) {
F_37 ( V_102 | V_103 | V_104 ) ;
F_37 ( V_105 ) ;
F_38 () ;
}
}
F_40 ( V_4 ) ;
return 0 ;
}
static int F_47 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 =
V_4 -> V_11 -> V_12 -> V_13 ;
int V_44 ;
if ( ! V_10 -> V_14 )
return - V_52 ;
F_15 ( L_13 ,
V_60 ,
V_2 -> V_5 . V_57 ,
V_10 -> V_14 -> V_58 ) ;
F_19 ( V_4 ) ;
V_44 = F_36 ( 10 ) ;
if ( V_44 )
return V_44 ;
F_37 ( V_102 | V_106 ) ;
F_37 ( 0 ) ;
F_37 ( V_107 | V_108 ) ;
F_37 ( 0 ) ;
if ( V_2 -> V_5 . V_57 == 0 ) {
F_37 ( V_2 -> V_5 . V_55 ) ;
V_2 -> V_5 . V_57 = 1 ;
} else {
F_37 ( V_2 -> V_5 . V_56 ) ;
V_2 -> V_5 . V_57 = 0 ;
}
F_37 ( 0 ) ;
F_37 ( V_109 | V_110 ) ;
F_37 ( 0 ) ;
F_38 () ;
V_10 -> V_14 -> V_86 = V_2 -> V_85 ++ ;
if ( F_36 ( 4 ) == 0 ) {
F_37 ( V_87 ) ;
F_37 ( V_88 << V_89 ) ;
F_37 ( V_2 -> V_85 ) ;
F_37 ( 0 ) ;
F_38 () ;
}
V_10 -> V_14 -> V_58 = V_2 -> V_5 . V_57 ;
return 0 ;
}
static int F_48 ( struct V_7 * V_4 )
{
struct V_26 * V_27 = F_5 ( V_4 -> V_8 ) ;
F_19 ( V_4 ) ;
return F_49 ( V_27 ) ;
}
static int F_50 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
int V_44 ;
if ( F_20 ( V_4 , V_30 ) )
return - V_67 ;
F_51 ( V_4 , V_65 ) ;
F_25 ( & V_4 -> V_41 ) ;
V_44 = F_48 ( V_4 ) ;
F_27 ( & V_4 -> V_41 ) ;
return V_44 ;
}
static int F_52 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
T_2 * V_2 = ( T_2 * ) V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
V_46 * V_14 = ( V_46 * )
V_10 -> V_14 ;
T_5 * V_95 = V_63 ;
int V_44 ;
struct V_76 * V_90 = NULL ;
if ( F_20 ( V_4 , V_30 ) )
return - V_67 ;
if ( ! V_2 -> V_5 . V_59 ) {
F_13 ( L_14 ) ;
return - V_52 ;
}
F_15 ( L_15 ,
V_95 -> V_96 , V_95 -> V_97 , V_95 -> V_93 ) ;
F_51 ( V_4 , V_65 ) ;
if ( V_95 -> V_93 < 0 )
return - V_52 ;
if ( V_95 -> V_93 ) {
V_90 = F_53 ( V_95 -> V_93 ,
sizeof( struct V_76 ) ,
V_111 ) ;
if ( V_90 == NULL )
return - V_22 ;
V_44 = F_54 ( V_90 , V_95 -> V_90 ,
V_95 -> V_93 *
sizeof( struct V_76 ) ) ;
if ( V_44 != 0 ) {
V_44 = - V_112 ;
goto V_113;
}
}
F_25 ( & V_4 -> V_41 ) ;
V_44 = F_42 ( V_4 , V_95 , V_90 ) ;
F_27 ( & V_4 -> V_41 ) ;
if ( V_14 )
V_14 -> V_15 = F_7 ( V_2 ) ;
V_113:
F_55 ( V_90 ) ;
return V_44 ;
}
static int F_56 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
T_2 * V_2 = ( T_2 * ) V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
V_46 * V_14 = ( V_46 * )
V_10 -> V_14 ;
T_4 * V_91 = V_63 ;
struct V_76 * V_90 = NULL ;
void * V_114 ;
int V_44 ;
F_15 ( L_16 ,
V_91 -> V_115 , V_91 -> V_75 , V_91 -> V_93 ) ;
if ( F_20 ( V_4 , V_30 ) )
return - V_67 ;
F_51 ( V_4 , V_65 ) ;
if ( V_91 -> V_93 < 0 )
return - V_52 ;
V_114 = F_57 ( V_91 -> V_75 , V_111 ) ;
if ( V_114 == NULL )
return - V_22 ;
V_44 = F_54 ( V_114 , V_91 -> V_115 , V_91 -> V_75 ) ;
if ( V_44 != 0 ) {
V_44 = - V_112 ;
goto V_116;
}
if ( V_91 -> V_93 ) {
V_90 = F_53 ( V_91 -> V_93 ,
sizeof( struct V_76 ) , V_111 ) ;
if ( V_90 == NULL ) {
V_44 = - V_22 ;
goto V_116;
}
V_44 = F_54 ( V_90 , V_91 -> V_90 ,
V_91 -> V_93 *
sizeof( struct V_76 ) ) ;
if ( V_44 != 0 ) {
V_44 = - V_112 ;
goto V_117;
}
}
F_25 ( & V_4 -> V_41 ) ;
V_44 = F_41 ( V_4 , V_91 , V_90 , V_114 ) ;
F_27 ( & V_4 -> V_41 ) ;
if ( V_44 ) {
F_13 ( L_17 ) ;
goto V_117;
}
if ( V_14 )
V_14 -> V_15 = F_7 ( V_2 ) ;
V_117:
F_55 ( V_90 ) ;
V_116:
F_55 ( V_114 ) ;
return V_44 ;
}
static int F_58 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
F_19 ( V_4 ) ;
F_15 ( L_18 ) ;
V_2 -> V_85 ++ ;
if ( V_2 -> V_85 > 0x7FFFFFFFUL )
V_2 -> V_85 = 1 ;
if ( V_10 -> V_14 )
V_10 -> V_14 -> V_86 = V_2 -> V_85 ;
if ( F_36 ( 4 ) == 0 ) {
F_37 ( V_87 ) ;
F_37 ( V_88 << V_89 ) ;
F_37 ( V_2 -> V_85 ) ;
F_37 ( V_118 ) ;
F_38 () ;
}
return V_2 -> V_85 ;
}
static int F_59 ( struct V_7 * V_4 , int V_119 )
{
T_2 * V_2 = ( T_2 * ) V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_12 -> V_13 ;
int V_44 = 0 ;
struct V_26 * V_27 = F_5 ( V_2 ) ;
F_15 ( L_19 , V_119 ,
F_7 ( V_2 ) ) ;
if ( F_7 ( V_2 ) >= V_119 ) {
if ( V_10 -> V_14 )
V_10 -> V_14 -> V_15 = F_7 ( V_2 ) ;
return 0 ;
}
if ( V_10 -> V_14 )
V_10 -> V_14 -> V_37 |= V_120 ;
if ( V_27 -> V_121 ( V_27 ) ) {
F_60 ( V_44 , V_27 -> V_122 , 3 * V_123 ,
F_7 ( V_2 ) >= V_119 ) ;
V_27 -> V_124 ( V_27 ) ;
} else if ( F_61 ( F_7 ( V_2 ) >= V_119 , 3000 ) )
V_44 = - V_125 ;
if ( V_44 == - V_125 ) {
F_13 ( L_20 ,
F_7 ( V_2 ) , ( int ) V_2 -> V_85 ) ;
}
return V_44 ;
}
static int F_62 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_6 * V_126 = V_63 ;
int V_127 ;
if ( F_20 ( V_4 , V_30 ) )
return - V_67 ;
if ( ! V_2 || ! F_5 ( V_2 ) -> V_61 ) {
F_13 ( L_21 ) ;
return - V_52 ;
}
F_51 ( V_4 , V_65 ) ;
F_25 ( & V_4 -> V_41 ) ;
V_127 = F_58 ( V_4 ) ;
F_27 ( & V_4 -> V_41 ) ;
if ( F_63 ( V_126 -> V_128 , & V_127 , sizeof( int ) ) ) {
F_13 ( L_22 ) ;
return - V_112 ;
}
return 0 ;
}
static int F_64 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_7 * V_129 = V_63 ;
if ( F_20 ( V_4 , V_30 ) )
return - V_67 ;
if ( ! V_2 ) {
F_13 ( L_21 ) ;
return - V_52 ;
}
return F_59 ( V_4 , V_129 -> V_128 ) ;
}
static int F_65 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_8 * V_130 = V_63 ;
if ( F_20 ( V_4 , V_30 ) )
return - V_67 ;
if ( ! V_2 ) {
F_13 ( L_21 ) ;
return - V_52 ;
}
V_130 -> V_130 = V_131 | V_132 ;
return 0 ;
}
static int F_66 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
return - V_52 ;
}
static int F_67 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
int V_44 ;
if ( F_20 ( V_4 , V_30 ) )
return - V_67 ;
F_15 ( L_6 , V_60 ) ;
F_51 ( V_4 , V_65 ) ;
F_25 ( & V_4 -> V_41 ) ;
V_44 = F_47 ( V_4 ) ;
F_27 ( & V_4 -> V_41 ) ;
return V_44 ;
}
static int F_68 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_9 * V_133 = V_63 ;
int V_134 ;
if ( ! V_2 ) {
F_13 ( L_21 ) ;
return - V_52 ;
}
switch ( V_133 -> V_133 ) {
case V_135 :
V_134 = V_4 -> V_136 -> V_137 ? 1 : 0 ;
break;
case V_138 :
V_134 = V_2 -> V_5 . V_59 ? 1 : 0 ;
break;
case V_139 :
V_134 = F_7 ( V_2 ) ;
break;
case V_140 :
V_134 = V_4 -> V_141 ;
break;
case V_142 :
V_134 = 1 ;
break;
case V_143 :
V_134 = V_2 -> V_144 - V_2 -> V_145 ;
break;
case V_146 :
V_134 = V_2 -> V_147 ? 1 : 0 ;
break;
case V_148 :
V_134 = 1 ;
break;
case V_149 :
V_134 = 1 ;
break;
case V_150 :
V_134 = F_69 ( & V_2 -> V_27 [ V_151 ] ) ;
break;
case V_152 :
V_134 = F_69 ( & V_2 -> V_27 [ V_153 ] ) ;
break;
case V_154 :
V_134 = 1 ;
break;
case V_155 :
V_134 = 1 ;
break;
case V_156 :
V_134 = F_9 ( V_4 ) -> V_19 >= 4 ;
break;
case V_157 :
V_134 = 1 ;
break;
case V_158 :
V_134 = 1 ;
break;
case V_159 :
V_134 = F_70 ( V_4 ) ;
break;
case V_160 :
V_134 = V_2 -> V_161 . V_162 ? 1 : 0 ;
break;
case V_163 :
V_134 = 1 ;
break;
case V_164 :
V_134 = F_71 ( V_4 ) ;
break;
case V_165 :
V_134 = 1 ;
break;
default:
F_15 ( L_23 ,
V_133 -> V_133 ) ;
return - V_52 ;
}
if ( F_63 ( V_133 -> V_134 , & V_134 , sizeof( int ) ) ) {
F_13 ( L_24 ) ;
return - V_112 ;
}
return 0 ;
}
static int F_72 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_10 * V_133 = V_63 ;
if ( ! V_2 ) {
F_13 ( L_21 ) ;
return - V_52 ;
}
switch ( V_133 -> V_133 ) {
case V_166 :
break;
case V_167 :
break;
case V_168 :
V_2 -> V_5 . V_59 = V_133 -> V_134 ? 1 : 0 ;
break;
case V_169 :
if ( V_133 -> V_134 > V_2 -> V_144 ||
V_133 -> V_134 < 0 )
return - V_52 ;
V_2 -> V_145 = V_133 -> V_134 ;
break;
default:
F_15 ( L_25 ,
V_133 -> V_133 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_73 ( struct V_7 * V_4 , void * V_63 ,
struct V_64 * V_65 )
{
T_2 * V_2 = V_4 -> V_8 ;
T_11 * V_170 = V_63 ;
struct V_26 * V_27 = F_5 ( V_2 ) ;
if ( F_20 ( V_4 , V_30 ) )
return - V_67 ;
if ( ! F_2 ( V_4 ) )
return - V_52 ;
if ( ! V_2 ) {
F_13 ( L_21 ) ;
return - V_52 ;
}
if ( F_20 ( V_4 , V_30 ) ) {
F_74 ( 1 , L_26 ) ;
return 0 ;
}
F_15 ( L_27 , ( T_1 ) V_170 -> V_16 ) ;
V_27 -> V_28 . V_29 = V_170 -> V_16 & ( 0x1ffff << 12 ) ;
V_2 -> V_5 . V_6 =
F_75 ( V_2 -> V_161 . V_171 + V_170 -> V_16 , 4096 ) ;
if ( V_2 -> V_5 . V_6 == NULL ) {
F_23 ( V_4 ) ;
V_27 -> V_28 . V_29 = 0 ;
F_13 ( L_7
L_28 ) ;
return - V_22 ;
}
F_14 ( V_2 -> V_5 . V_6 , 0 , V_21 ) ;
F_10 ( V_20 , V_27 -> V_28 . V_29 ) ;
F_15 ( L_29 ,
V_27 -> V_28 . V_29 ) ;
F_15 ( L_30 ,
V_27 -> V_28 . V_62 ) ;
return 0 ;
}
static int F_76 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
V_2 -> V_172 = F_77 ( 0 , F_78 ( 0 , 0 ) ) ;
if ( ! V_2 -> V_172 ) {
F_13 ( L_31 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_79 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
int V_3 = F_9 ( V_4 ) -> V_19 >= 4 ? V_173 : V_174 ;
T_1 V_175 , V_176 = 0 ;
T_12 V_177 ;
int V_44 ;
if ( F_9 ( V_4 ) -> V_19 >= 4 )
F_80 ( V_2 -> V_172 , V_3 + 4 , & V_176 ) ;
F_80 ( V_2 -> V_172 , V_3 , & V_175 ) ;
V_177 = ( ( T_12 ) V_176 << 32 ) | V_175 ;
#ifdef F_81
if ( V_177 &&
F_82 ( V_177 , V_177 + V_178 ) )
return 0 ;
#endif
V_2 -> V_179 . V_180 = L_32 ;
V_2 -> V_179 . V_181 = V_182 ;
V_44 = F_83 ( V_2 -> V_172 -> V_183 ,
& V_2 -> V_179 ,
V_178 , V_178 ,
V_184 ,
0 , V_185 ,
V_2 -> V_172 ) ;
if ( V_44 ) {
F_15 ( L_33 , V_44 ) ;
V_2 -> V_179 . V_96 = 0 ;
return V_44 ;
}
if ( F_9 ( V_4 ) -> V_19 >= 4 )
F_84 ( V_2 -> V_172 , V_3 + 4 ,
F_85 ( V_2 -> V_179 . V_96 ) ) ;
F_84 ( V_2 -> V_172 , V_3 ,
F_86 ( V_2 -> V_179 . V_96 ) ) ;
return 0 ;
}
static void
F_87 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
int V_186 = F_9 ( V_4 ) -> V_19 >= 4 ? V_173 : V_174 ;
T_1 V_187 ;
bool V_188 ;
V_2 -> V_189 = false ;
if ( F_88 ( V_4 ) || F_89 ( V_4 ) ) {
F_80 ( V_2 -> V_172 , V_190 , & V_187 ) ;
V_188 = ! ! ( V_187 & V_191 ) ;
} else {
F_80 ( V_2 -> V_172 , V_186 , & V_187 ) ;
V_188 = V_187 & 1 ;
}
if ( V_188 )
return;
if ( F_79 ( V_4 ) )
return;
V_2 -> V_189 = true ;
if ( F_88 ( V_4 ) || F_89 ( V_4 ) ) {
F_84 ( V_2 -> V_172 , V_190 ,
V_187 | V_191 ) ;
} else {
F_80 ( V_2 -> V_172 , V_186 , & V_187 ) ;
F_84 ( V_2 -> V_172 , V_186 , V_187 | 1 ) ;
}
}
static void
F_90 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
int V_186 = F_9 ( V_4 ) -> V_19 >= 4 ? V_173 : V_174 ;
T_1 V_187 ;
if ( V_2 -> V_189 ) {
if ( F_88 ( V_4 ) || F_89 ( V_4 ) ) {
F_80 ( V_2 -> V_172 , V_190 , & V_187 ) ;
V_187 &= ~ V_191 ;
F_84 ( V_2 -> V_172 , V_190 , V_187 ) ;
} else {
F_80 ( V_2 -> V_172 , V_186 , & V_187 ) ;
V_187 &= ~ 1 ;
F_84 ( V_2 -> V_172 , V_186 , V_187 ) ;
}
}
if ( V_2 -> V_179 . V_96 )
F_91 ( & V_2 -> V_179 ) ;
}
static unsigned int F_92 ( void * V_192 , bool V_193 )
{
struct V_7 * V_4 = V_192 ;
F_93 ( V_4 , V_193 ) ;
if ( V_193 )
return V_194 | V_195 |
V_196 | V_197 ;
else
return V_196 | V_197 ;
}
static void F_94 ( struct V_198 * V_136 , enum V_199 V_193 )
{
struct V_7 * V_4 = F_95 ( V_136 ) ;
T_13 V_200 = { . V_201 = V_202 } ;
if ( V_193 == V_203 ) {
F_96 ( L_34 ) ;
V_4 -> V_204 = V_205 ;
F_97 ( V_4 -> V_136 , V_206 ) ;
F_98 ( V_4 ) ;
V_4 -> V_204 = V_207 ;
} else {
F_99 ( L_35 ) ;
V_4 -> V_204 = V_205 ;
F_100 ( V_4 , V_200 ) ;
V_4 -> V_204 = V_208 ;
}
}
static bool F_101 ( struct V_198 * V_136 )
{
struct V_7 * V_4 = F_95 ( V_136 ) ;
bool V_209 ;
F_102 ( & V_4 -> V_210 ) ;
V_209 = ( V_4 -> V_211 == 0 ) ;
F_103 ( & V_4 -> V_210 ) ;
return V_209 ;
}
static int F_104 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_44 ;
V_44 = F_105 ( V_4 ) ;
if ( V_44 )
F_106 ( L_36 ) ;
V_44 = F_107 ( V_4 -> V_136 , V_4 , NULL , F_92 ) ;
if ( V_44 && V_44 != - V_67 )
goto V_212;
F_108 () ;
V_44 = F_109 ( V_4 -> V_136 , & V_213 ) ;
if ( V_44 )
goto V_214;
V_44 = F_110 ( V_4 ) ;
if ( V_44 )
goto V_215;
F_111 ( V_4 ) ;
V_44 = F_112 ( V_4 ) ;
if ( V_44 )
goto V_216;
F_113 ( V_4 ) ;
V_44 = F_114 ( V_4 ) ;
if ( V_44 )
goto V_217;
V_4 -> V_218 = 1 ;
V_44 = F_115 ( V_4 ) ;
if ( V_44 )
goto V_219;
F_116 ( V_4 ) ;
V_2 -> V_161 . V_220 = 0 ;
return 0 ;
V_219:
F_24 ( V_4 ) ;
V_217:
F_25 ( & V_4 -> V_41 ) ;
F_117 ( V_4 ) ;
F_27 ( & V_4 -> V_41 ) ;
F_118 ( V_4 ) ;
V_216:
F_119 ( V_4 ) ;
V_215:
F_120 ( V_4 -> V_136 ) ;
V_214:
F_107 ( V_4 -> V_136 , NULL , NULL , NULL ) ;
V_212:
return V_44 ;
}
int F_121 ( struct V_7 * V_4 , struct V_221 * V_12 )
{
struct V_9 * V_10 ;
V_10 = F_122 ( sizeof( * V_10 ) , V_111 ) ;
if ( ! V_10 )
return - V_22 ;
V_12 -> V_13 = V_10 ;
return 0 ;
}
void F_123 ( struct V_7 * V_4 , struct V_221 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_13 ;
if ( ! V_10 )
return;
F_55 ( V_10 ) ;
V_12 -> V_13 = NULL ;
}
static void
F_124 ( struct V_1 * V_2 , unsigned long V_222 ,
unsigned long V_36 )
{
V_2 -> V_161 . V_223 = - 1 ;
#if F_125 ( V_224 )
if ( V_225 )
return;
#endif
V_2 -> V_161 . V_223 = F_126 ( V_222 , V_36 , V_226 , 1 ) ;
if ( V_2 -> V_161 . V_223 < 0 ) {
F_106 ( L_37
L_38 ) ;
}
}
static void F_127 ( struct V_1 * V_2 )
{
struct V_227 * V_228 ;
struct V_198 * V_136 = V_2 -> V_4 -> V_136 ;
bool V_11 ;
V_228 = F_128 ( 1 ) ;
if ( ! V_228 )
return;
V_228 -> V_229 [ 0 ] . V_222 = V_2 -> V_161 . V_230 -> V_231 ;
V_228 -> V_229 [ 0 ] . V_36 =
V_2 -> V_161 . V_230 -> V_232 << V_233 ;
V_11 =
V_136 -> V_234 [ V_235 ] . V_181 & V_236 ;
F_129 ( V_228 , L_39 , V_11 ) ;
F_55 ( V_228 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
const struct V_237 * V_238 = V_2 -> V_238 ;
#define F_131 ( V_180 ) info->name ? #name "," : ""
#define F_132 ,
F_15 ( L_40
L_41 ,
V_238 -> V_19 ,
V_2 -> V_4 -> V_136 -> V_239 ,
V_240 ) ;
#undef F_131
#undef F_132
}
int F_133 ( struct V_7 * V_4 , unsigned long V_181 )
{
struct V_1 * V_2 ;
struct V_237 * V_238 ;
int V_44 = 0 , V_241 , V_242 ;
T_14 V_243 ;
V_238 = (struct V_237 * ) V_181 ;
if ( V_238 -> V_19 >= 6 && ! F_20 ( V_4 , V_30 ) )
return - V_67 ;
V_4 -> V_244 += 4 ;
V_4 -> V_245 [ 6 ] = V_246 ;
V_4 -> V_245 [ 7 ] = V_247 ;
V_4 -> V_245 [ 8 ] = V_248 ;
V_4 -> V_245 [ 9 ] = V_249 ;
V_2 = F_122 ( sizeof( T_2 ) , V_111 ) ;
if ( V_2 == NULL )
return - V_22 ;
V_4 -> V_8 = ( void * ) V_2 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_238 = V_238 ;
F_130 ( V_2 ) ;
if ( F_76 ( V_4 ) ) {
V_44 = - V_250 ;
goto V_251;
}
V_44 = F_134 ( V_2 -> V_172 , V_4 -> V_136 , NULL ) ;
if ( ! V_44 ) {
F_13 ( L_42 ) ;
V_44 = - V_250 ;
goto V_252;
}
V_2 -> V_161 . V_230 = F_135 () ;
if ( ! V_2 -> V_161 . V_230 ) {
F_13 ( L_43 ) ;
V_44 = - V_67 ;
goto V_253;
}
if ( F_20 ( V_4 , V_30 ) )
F_127 ( V_2 ) ;
F_136 ( V_4 -> V_136 ) ;
if ( F_137 ( V_4 ) )
F_138 ( & V_4 -> V_136 -> V_4 , F_139 ( 30 ) ) ;
if ( F_140 ( V_4 ) || F_141 ( V_4 ) )
F_138 ( & V_4 -> V_136 -> V_4 , F_139 ( 32 ) ) ;
V_241 = F_137 ( V_4 ) ? 1 : 0 ;
if ( V_238 -> V_19 < 5 )
V_242 = 512 * 1024 ;
else
V_242 = 2 * 1024 * 1024 ;
V_2 -> V_254 = F_142 ( V_4 -> V_136 , V_241 , V_242 ) ;
if ( ! V_2 -> V_254 ) {
F_13 ( L_44 ) ;
V_44 = - V_250 ;
goto V_253;
}
V_243 = V_2 -> V_161 . V_230 -> V_232 << V_233 ;
V_2 -> V_161 . V_171 = V_2 -> V_161 . V_230 -> V_231 ;
V_2 -> V_161 . V_255 =
F_143 ( V_2 -> V_161 . V_171 ,
V_243 ) ;
if ( V_2 -> V_161 . V_255 == NULL ) {
V_44 = - V_250 ;
goto V_256;
}
F_124 ( V_2 , V_2 -> V_161 . V_171 ,
V_243 ) ;
V_2 -> V_257 = F_144 ( L_45 , 0 ) ;
if ( V_2 -> V_257 == NULL ) {
F_13 ( L_46 ) ;
V_44 = - V_22 ;
goto V_258;
}
F_145 ( V_4 ) ;
F_146 ( V_4 ) ;
F_147 ( V_4 ) ;
F_87 ( V_4 ) ;
F_148 ( V_4 ) ;
F_149 ( V_4 ) ;
F_150 ( V_4 ) ;
F_151 ( V_4 ) ;
if ( ! F_2 ( V_4 ) ) {
V_44 = F_11 ( V_4 ) ;
if ( V_44 )
goto V_259;
}
if ( ! F_152 ( V_4 ) && ! F_153 ( V_4 ) )
F_154 ( V_4 -> V_136 ) ;
F_155 ( & V_2 -> V_260 ) ;
F_155 ( & V_2 -> V_261 ) ;
F_155 ( & V_2 -> V_262 . V_263 ) ;
F_155 ( & V_2 -> V_264 ) ;
if ( F_156 ( V_4 ) || F_157 ( V_4 ) )
V_2 -> V_265 = 3 ;
else if ( F_158 ( V_4 ) || ! F_137 ( V_4 ) )
V_2 -> V_265 = 2 ;
else
V_2 -> V_265 = 1 ;
V_44 = F_159 ( V_4 , V_2 -> V_265 ) ;
if ( V_44 )
goto V_259;
V_2 -> V_161 . V_220 = 1 ;
if ( F_20 ( V_4 , V_30 ) ) {
V_44 = F_104 ( V_4 ) ;
if ( V_44 < 0 ) {
F_13 ( L_47 ) ;
goto V_259;
}
}
F_160 ( V_4 ) ;
F_161 ( V_4 ) ;
F_162 () ;
F_163 ( & V_2 -> V_266 , V_267 ,
( unsigned long ) V_4 ) ;
if ( F_46 ( V_4 ) )
F_164 ( V_2 ) ;
return 0 ;
V_259:
if ( V_2 -> V_161 . V_268 . V_269 )
F_165 ( & V_2 -> V_161 . V_268 ) ;
if ( V_4 -> V_136 -> V_270 )
F_166 ( V_4 -> V_136 ) ;
F_167 ( V_4 ) ;
F_90 ( V_4 ) ;
F_168 ( V_2 -> V_257 ) ;
V_258:
if ( V_2 -> V_161 . V_223 >= 0 ) {
F_169 ( V_2 -> V_161 . V_223 ,
V_2 -> V_161 . V_171 ,
V_243 ) ;
V_2 -> V_161 . V_223 = - 1 ;
}
F_170 ( V_2 -> V_161 . V_255 ) ;
V_256:
F_171 ( V_4 -> V_136 , V_2 -> V_254 ) ;
V_253:
F_172 () ;
V_252:
F_173 ( V_2 -> V_172 ) ;
V_251:
F_55 ( V_2 ) ;
return V_44 ;
}
int F_174 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
int V_44 ;
F_175 () ;
F_176 ( V_4 ) ;
if ( V_2 -> V_161 . V_268 . V_269 )
F_165 ( & V_2 -> V_161 . V_268 ) ;
F_25 ( & V_4 -> V_41 ) ;
V_44 = F_177 ( V_4 ) ;
if ( V_44 )
F_13 ( L_48 , V_44 ) ;
F_178 ( V_4 ) ;
F_27 ( & V_4 -> V_41 ) ;
F_179 ( & V_2 -> V_161 . V_271 ) ;
F_170 ( V_2 -> V_161 . V_255 ) ;
if ( V_2 -> V_161 . V_223 >= 0 ) {
F_169 ( V_2 -> V_161 . V_223 ,
V_2 -> V_161 . V_171 ,
V_2 -> V_161 . V_230 -> V_232 * V_21 ) ;
V_2 -> V_161 . V_223 = - 1 ;
}
F_180 () ;
if ( F_20 ( V_4 , V_30 ) ) {
F_181 ( V_4 ) ;
F_182 ( V_4 ) ;
if ( V_2 -> V_272 && V_2 -> V_273 ) {
F_55 ( V_2 -> V_272 ) ;
V_2 -> V_272 = NULL ;
V_2 -> V_273 = 0 ;
}
F_120 ( V_4 -> V_136 ) ;
F_107 ( V_4 -> V_136 , NULL , NULL , NULL ) ;
}
F_183 ( & V_2 -> V_266 ) ;
F_184 ( & V_2 -> V_274 ) ;
F_185 ( V_4 ) ;
if ( V_4 -> V_136 -> V_270 )
F_166 ( V_4 -> V_136 ) ;
F_186 ( V_4 ) ;
if ( F_20 ( V_4 , V_30 ) ) {
F_187 ( V_2 -> V_257 ) ;
F_25 ( & V_4 -> V_41 ) ;
F_188 ( V_4 ) ;
F_117 ( V_4 ) ;
F_189 ( V_4 ) ;
F_27 ( & V_4 -> V_41 ) ;
F_118 ( V_4 ) ;
F_119 ( V_4 ) ;
F_190 ( & V_2 -> V_161 . V_275 ) ;
F_191 ( V_4 ) ;
if ( ! F_2 ( V_4 ) )
F_16 ( V_4 ) ;
}
if ( V_2 -> V_254 != NULL )
F_171 ( V_4 -> V_136 , V_2 -> V_254 ) ;
F_167 ( V_4 ) ;
F_90 ( V_4 ) ;
F_168 ( V_2 -> V_257 ) ;
F_173 ( V_2 -> V_172 ) ;
F_55 ( V_4 -> V_8 ) ;
return 0 ;
}
int F_192 ( struct V_7 * V_4 , struct V_64 * V_276 )
{
struct V_277 * V_65 ;
F_15 ( L_18 ) ;
V_65 = F_57 ( sizeof( * V_65 ) , V_111 ) ;
if ( ! V_65 )
return - V_22 ;
V_276 -> V_13 = V_65 ;
F_155 ( & V_65 -> V_161 . V_263 ) ;
F_193 ( & V_65 -> V_161 . V_278 ) ;
F_194 ( & V_65 -> V_279 ) ;
return 0 ;
}
void F_195 ( struct V_7 * V_4 )
{
T_2 * V_2 = V_4 -> V_8 ;
if ( ! V_2 )
return;
if ( F_20 ( V_4 , V_30 ) ) {
F_196 ( V_4 ) ;
F_197 () ;
return;
}
F_198 ( V_4 ) ;
F_23 ( V_4 ) ;
}
void F_199 ( struct V_7 * V_4 , struct V_64 * V_65 )
{
F_200 ( V_4 , V_65 ) ;
F_201 ( V_4 , V_65 ) ;
}
void F_202 ( struct V_7 * V_4 , struct V_64 * V_276 )
{
struct V_277 * V_65 = V_276 -> V_13 ;
F_55 ( V_65 ) ;
}
int F_203 ( struct V_7 * V_4 )
{
return 1 ;
}
