static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_3 )
goto V_5;
if ( V_2 -> V_6 ) {
V_3 = F_2 ( V_2 -> V_6 ) ;
if ( V_3 )
F_3 ( V_2 -> V_4 ) ;
}
V_5:
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 )
F_3 ( V_2 -> V_6 ) ;
F_3 ( V_2 -> V_4 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_1 * V_11 ;
struct V_12 * V_13 ;
int V_3 = 0 ;
#ifndef F_6
unsigned long * V_14 = V_10 -> V_15 ;
int V_16 ;
if ( ! F_7 ( & V_10 -> V_17 ) ) {
F_8 ( V_14 , V_14 + V_18 ) ;
for ( V_16 = 0 ; V_16 < V_19 ; V_16 ++ )
if ( ( V_14 [ V_16 ] & 0x03 ) == V_20 ) {
void * V_21 = F_9 ( V_14 [ V_16 ] &
V_22 ) ;
F_8 ( V_21 , V_21 + V_23 ) ;
}
}
#endif
F_10 (ctx_drvdata, &priv->list_attached, attached_elm) {
if ( ! V_13 -> V_24 || ! V_13 -> V_24 -> V_25 . V_26 )
F_11 () ;
V_11 = F_12 ( V_13 -> V_24 -> V_25 . V_26 ) ;
F_13 ( ! V_11 ) ;
V_3 = F_1 ( V_11 ) ;
if ( V_3 )
goto V_5;
F_14 ( V_11 -> V_27 , V_13 -> V_28 , 0 ) ;
F_4 ( V_11 ) ;
}
V_5:
return V_3 ;
}
static void F_15 ( void T_1 * V_27 , int V_29 )
{
F_16 ( V_27 , V_29 , 0 ) ;
F_17 ( V_27 , V_29 , 0 ) ;
F_18 ( V_27 , V_29 , 0 ) ;
F_19 ( V_27 , V_29 , 0 ) ;
F_20 ( V_27 , V_29 , 0 ) ;
F_21 ( V_27 , V_29 , 0 ) ;
F_22 ( V_27 , V_29 , 0 ) ;
F_23 ( V_27 , V_29 , 0 ) ;
F_24 ( V_27 , V_29 , 0 ) ;
F_25 ( V_27 , V_29 , 0 ) ;
F_26 ( V_27 , V_29 , 0 ) ;
F_27 ( V_27 , V_29 , 0 ) ;
F_28 ( V_27 , V_29 , 0 ) ;
F_29 ( V_27 , V_29 , 0 ) ;
F_14 ( V_27 , V_29 , 0 ) ;
F_30 ( V_27 , V_29 , 0 ) ;
F_31 ( V_27 , V_29 , 0 ) ;
F_32 ( V_27 , V_29 , 0 ) ;
F_33 ( V_27 , V_29 , 0 ) ;
F_34 ( V_27 , V_29 , 0 ) ;
}
static void F_35 ( void T_1 * V_27 , int V_29 , T_2 V_15 )
{
unsigned int V_30 , V_31 ;
F_15 ( V_27 , V_29 ) ;
F_36 ( V_27 , V_29 , 0x3 ) ;
F_37 ( V_27 , V_29 , 0x3 ) ;
F_26 ( V_27 , V_29 , 0 ) ;
F_38 ( V_27 , V_29 , ( V_15 >> 14 ) ) ;
F_14 ( V_27 , V_29 , 0 ) ;
F_39 ( V_27 , V_29 , 0 ) ;
F_40 ( V_27 , V_29 , 1 ) ;
F_41 ( V_27 , V_29 , 1 ) ;
F_42 ( V_27 , V_29 , 1 ) ;
F_43 ( V_27 , V_29 , 1 ) ;
F_44 ( V_27 , V_29 , 1 ) ;
F_45 ( V_27 , V_29 , 1 ) ;
F_46 ( V_30 ) ;
F_47 ( V_31 ) ;
F_33 ( V_27 , V_29 , V_30 ) ;
F_34 ( V_27 , V_29 , V_31 ) ;
F_48 ( V_27 , V_29 , 1 ) ;
#ifdef F_6
F_49 ( V_27 , V_29 , 1 ) ;
F_50 ( V_27 , V_29 , 1 ) ;
F_51 ( V_27 , V_29 , 1 ) ;
F_52 ( V_27 , V_29 , 1 ) ;
F_53 ( V_27 , V_29 , 0 ) ;
F_54 ( V_27 , V_29 , 1 ) ;
F_55 ( V_27 , V_29 , 0 ) ;
F_56 ( V_27 , V_29 , 1 ) ;
F_57 ( V_27 , V_29 , 1 ) ;
F_58 ( V_27 , V_29 , 1 ) ;
#endif
F_59 ( V_27 , V_29 , 1 ) ;
}
static int F_60 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_61 ( sizeof( * V_10 ) , V_32 ) ;
if ( ! V_10 )
goto V_33;
F_62 ( & V_10 -> V_17 ) ;
V_10 -> V_15 = ( unsigned long * ) F_63 ( V_32 ,
F_64 ( V_18 ) ) ;
if ( ! V_10 -> V_15 )
goto V_33;
memset ( V_10 -> V_15 , 0 , V_18 ) ;
V_8 -> V_10 = V_10 ;
V_8 -> V_34 . V_35 = 0 ;
V_8 -> V_34 . V_36 = ( 1ULL << 32 ) - 1 ;
V_8 -> V_34 . V_37 = true ;
return 0 ;
V_33:
F_65 ( V_10 ) ;
return - V_38 ;
}
static void F_66 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
unsigned long V_39 ;
unsigned long * V_14 ;
int V_16 ;
F_67 ( & V_40 , V_39 ) ;
V_10 = V_8 -> V_10 ;
V_8 -> V_10 = NULL ;
if ( V_10 ) {
V_14 = V_10 -> V_15 ;
for ( V_16 = 0 ; V_16 < V_19 ; V_16 ++ )
if ( ( V_14 [ V_16 ] & 0x03 ) == V_20 )
F_68 ( ( unsigned long ) F_9 ( ( ( V_14 [ V_16 ] ) &
V_22 ) ) ) ;
F_69 ( ( unsigned long ) V_10 -> V_15 , F_64 ( V_18 ) ) ;
V_10 -> V_15 = NULL ;
}
F_65 ( V_10 ) ;
F_70 ( & V_40 , V_39 ) ;
}
static int F_71 ( struct V_7 * V_8 , struct V_41 * V_25 )
{
struct V_9 * V_10 ;
struct V_42 * V_43 ;
struct V_1 * V_11 ;
struct V_12 * V_13 ;
struct V_12 * V_44 ;
int V_3 = 0 ;
unsigned long V_39 ;
F_67 ( & V_40 , V_39 ) ;
V_10 = V_8 -> V_10 ;
if ( ! V_10 || ! V_25 ) {
V_3 = - V_45 ;
goto V_5;
}
V_11 = F_12 ( V_25 -> V_26 ) ;
V_13 = F_12 ( V_25 ) ;
V_43 = V_25 -> V_46 ;
if ( ! V_11 || ! V_13 || ! V_43 ) {
V_3 = - V_45 ;
goto V_5;
}
if ( ! F_7 ( & V_13 -> V_47 ) ) {
V_3 = - V_48 ;
goto V_5;
}
F_10 (tmp_drvdata, &priv->list_attached, attached_elm)
if ( V_44 == V_13 ) {
V_3 = - V_48 ;
goto V_5;
}
V_3 = F_1 ( V_11 ) ;
if ( V_3 )
goto V_5;
F_35 ( V_11 -> V_27 , V_43 -> V_28 ,
F_72 ( V_10 -> V_15 ) ) ;
F_4 ( V_11 ) ;
F_73 ( & ( V_13 -> V_47 ) , & V_10 -> V_17 ) ;
V_3 = F_5 ( V_8 ) ;
V_5:
F_70 ( & V_40 , V_39 ) ;
return V_3 ;
}
static void F_74 ( struct V_7 * V_8 ,
struct V_41 * V_25 )
{
struct V_9 * V_10 ;
struct V_42 * V_43 ;
struct V_1 * V_11 ;
struct V_12 * V_13 ;
unsigned long V_39 ;
int V_3 ;
F_67 ( & V_40 , V_39 ) ;
V_10 = V_8 -> V_10 ;
if ( ! V_10 || ! V_25 )
goto V_5;
V_11 = F_12 ( V_25 -> V_26 ) ;
V_13 = F_12 ( V_25 ) ;
V_43 = V_25 -> V_46 ;
if ( ! V_11 || ! V_13 || ! V_43 )
goto V_5;
V_3 = F_5 ( V_8 ) ;
if ( V_3 )
goto V_5;
V_3 = F_1 ( V_11 ) ;
if ( V_3 )
goto V_5;
F_15 ( V_11 -> V_27 , V_43 -> V_28 ) ;
F_4 ( V_11 ) ;
F_75 ( & V_13 -> V_47 ) ;
V_5:
F_70 ( & V_40 , V_39 ) ;
}
static int F_76 ( struct V_7 * V_8 , unsigned long V_49 ,
T_2 V_50 , T_3 V_51 , int V_52 )
{
struct V_9 * V_10 ;
unsigned long V_39 ;
unsigned long * V_14 ;
unsigned long * V_53 ;
unsigned long V_54 ;
unsigned long * V_21 ;
unsigned long * V_55 ;
unsigned long V_56 ;
unsigned int V_57 ;
int V_3 = 0 , V_58 , V_59 ;
F_67 ( & V_40 , V_39 ) ;
V_59 = ( V_52 & V_60 ) ? 1 : 0 ;
V_58 = V_61 [ V_52 & V_62 ] ;
if ( V_58 < 0 || V_58 > V_63 - 1 ) {
V_3 = - V_45 ;
goto V_5;
}
V_10 = V_8 -> V_10 ;
if ( ! V_10 ) {
V_3 = - V_45 ;
goto V_5;
}
V_14 = V_10 -> V_15 ;
if ( V_51 != V_64 && V_51 != V_65 &&
V_51 != V_66 && V_51 != V_23 ) {
F_77 ( L_1 , V_51 ) ;
V_3 = - V_45 ;
goto V_5;
}
if ( ! V_14 ) {
F_77 ( L_2 ) ;
V_3 = - V_45 ;
goto V_5;
}
if ( V_51 == V_64 || V_51 == V_65 ) {
V_57 = V_59 ? V_67 : 0 ;
V_57 |= V_58 & 0x01 ? V_68 : 0 ;
V_57 |= V_58 & 0x02 ? V_69 : 0 ;
V_57 |= V_58 & 0x04 ? V_70 : 0 ;
} else {
V_57 = V_59 ? V_71 : 0 ;
V_57 |= V_58 & 0x01 ? V_72 : 0 ;
V_57 |= V_58 & 0x02 ? V_73 : 0 ;
V_57 |= V_58 & 0x04 ? V_74 : 0 ;
}
V_54 = F_78 ( V_49 ) ;
V_53 = V_14 + V_54 ;
if ( V_51 == V_64 ) {
int V_16 = 0 ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
* ( V_53 + V_16 ) = ( V_50 & 0xFF000000 ) | V_75 |
V_76 | V_77 | V_78 |
V_67 | V_79 | V_57 ;
}
if ( V_51 == V_65 )
* V_53 = ( V_50 & 0xFFF00000 ) | V_76 | V_77 | V_79 |
V_78 | V_67 | V_57 ;
if ( ( V_51 == V_23 || V_51 == V_66 ) && ( * V_53 ) == 0 ) {
unsigned long * V_80 ;
V_80 = ( unsigned long * ) F_63 ( V_81 ,
F_64 ( V_23 ) ) ;
if ( ! V_80 ) {
F_77 ( L_3 ) ;
V_3 = - V_38 ;
goto V_5;
}
memset ( V_80 , 0 , V_23 ) ;
* V_53 = ( ( ( ( int ) F_72 ( V_80 ) ) & V_22 ) | V_20 ) ;
}
V_21 = ( unsigned long * ) F_9 ( ( ( * V_53 ) & V_22 ) ) ;
V_56 = F_79 ( V_49 ) ;
V_55 = V_21 + V_56 ;
if ( V_51 == V_23 )
* V_55 = ( V_50 & V_82 ) | V_83 | V_84 | V_85 |
V_71 | V_86 | V_57 ;
if ( V_51 == V_66 ) {
int V_16 ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
* ( V_55 + V_16 ) = ( V_50 & V_87 ) | V_83 |
V_85 | V_84 | V_71 | V_88 | V_57 ;
}
V_3 = F_5 ( V_8 ) ;
V_5:
F_70 ( & V_40 , V_39 ) ;
return V_3 ;
}
static T_3 F_80 ( struct V_7 * V_8 , unsigned long V_49 ,
T_3 V_51 )
{
struct V_9 * V_10 ;
unsigned long V_39 ;
unsigned long * V_14 ;
unsigned long * V_53 ;
unsigned long V_54 ;
unsigned long * V_21 ;
unsigned long * V_55 ;
unsigned long V_56 ;
int V_16 , V_3 = 0 ;
F_67 ( & V_40 , V_39 ) ;
V_10 = V_8 -> V_10 ;
if ( ! V_10 )
goto V_5;
V_14 = V_10 -> V_15 ;
if ( V_51 != V_64 && V_51 != V_65 &&
V_51 != V_66 && V_51 != V_23 ) {
F_77 ( L_4 , V_51 ) ;
goto V_5;
}
if ( ! V_14 ) {
F_77 ( L_2 ) ;
goto V_5;
}
V_54 = F_78 ( V_49 ) ;
V_53 = V_14 + V_54 ;
if ( * V_53 == 0 ) {
F_77 ( L_5 ) ;
goto V_5;
}
if ( V_51 == V_64 )
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
* ( V_53 + V_16 ) = 0 ;
if ( V_51 == V_65 )
* V_53 = 0 ;
V_21 = ( unsigned long * ) F_9 ( ( ( * V_53 ) & V_22 ) ) ;
V_56 = F_79 ( V_49 ) ;
V_55 = V_21 + V_56 ;
if ( V_51 == V_66 ) {
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
* ( V_55 + V_16 ) = 0 ;
}
if ( V_51 == V_23 )
* V_55 = 0 ;
if ( V_51 == V_23 || V_51 == V_66 ) {
int V_89 = 0 ;
for ( V_16 = 0 ; V_16 < V_90 ; V_16 ++ )
if ( V_21 [ V_16 ] )
V_89 = 1 ;
if ( ! V_89 ) {
F_68 ( ( unsigned long ) V_21 ) ;
* V_53 = 0 ;
}
}
V_3 = F_5 ( V_8 ) ;
V_5:
F_70 ( & V_40 , V_39 ) ;
V_51 = V_3 ? 0 : V_51 ;
return V_51 ;
}
static T_2 F_81 ( struct V_7 * V_8 ,
T_4 V_49 )
{
struct V_9 * V_10 ;
struct V_1 * V_11 ;
struct V_12 * V_13 ;
unsigned int V_91 ;
unsigned long V_39 ;
void T_1 * V_27 ;
T_2 V_3 = 0 ;
int V_29 ;
F_67 ( & V_40 , V_39 ) ;
V_10 = V_8 -> V_10 ;
if ( F_7 ( & V_10 -> V_17 ) )
goto V_5;
V_13 = F_82 ( V_10 -> V_17 . V_92 ,
struct V_12 , V_47 ) ;
V_11 = F_12 ( V_13 -> V_24 -> V_25 . V_26 ) ;
V_27 = V_11 -> V_27 ;
V_29 = V_13 -> V_28 ;
V_3 = F_1 ( V_11 ) ;
if ( V_3 )
goto V_5;
F_14 ( V_27 , V_29 , 0 ) ;
F_83 ( V_27 , V_29 , V_49 & V_93 ) ;
V_91 = F_84 ( V_27 , V_29 ) ;
if ( F_85 ( V_27 , V_29 ) )
V_3 = ( V_91 & 0xFF000000 ) | ( V_49 & 0x00FFFFFF ) ;
else
V_3 = ( V_91 & 0xFFFFF000 ) | ( V_49 & 0x00000FFF ) ;
if ( F_86 ( V_27 , V_29 ) )
V_3 = 0 ;
F_4 ( V_11 ) ;
V_5:
F_70 ( & V_40 , V_39 ) ;
return V_3 ;
}
static int F_87 ( struct V_7 * V_8 ,
unsigned long V_94 )
{
return 0 ;
}
static void F_88 ( void T_1 * V_27 , int V_29 )
{
unsigned int V_95 = F_89 ( V_27 , V_29 ) ;
F_90 ( L_6 ,
F_91 ( V_27 , V_29 ) , F_84 ( V_27 , V_29 ) ) ;
F_90 ( L_7 , V_95 ,
( V_95 & 0x02 ) ? L_8 : L_9 ,
( V_95 & 0x04 ) ? L_10 : L_9 ,
( V_95 & 0x08 ) ? L_11 : L_9 ,
( V_95 & 0x10 ) ? L_12 : L_9 ,
( V_95 & 0x20 ) ? L_13 : L_9 ,
( V_95 & 0x40 ) ? L_14 : L_9 ,
( V_95 & 0x80 ) ? L_15 : L_9 ,
( V_95 & 0x10000 ) ? L_16 : L_9 ,
( V_95 & 0x40000000 ) ? L_17 : L_9 ,
( V_95 & 0x80000000 ) ? L_18 : L_9 ) ;
F_90 ( L_19 ,
F_92 ( V_27 , V_29 ) , F_93 ( V_27 , V_29 ) ) ;
F_90 ( L_20 ,
F_94 ( V_27 , V_29 ) , F_95 ( V_27 , V_29 ) ) ;
F_90 ( L_21 ,
F_96 ( V_27 , V_29 ) , F_97 ( V_27 , V_29 ) ) ;
F_90 ( L_22 ,
F_98 ( V_27 , V_29 ) , F_99 ( V_27 , V_29 ) ) ;
}
T_5 F_100 ( int V_96 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
void T_1 * V_27 ;
unsigned int V_95 ;
int V_16 , V_3 ;
F_101 ( & V_40 ) ;
if ( ! V_2 ) {
F_90 ( L_23 ) ;
goto V_5;
}
V_27 = V_2 -> V_27 ;
F_90 ( L_24 ) ;
F_90 ( L_25 , ( unsigned int ) V_27 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_5;
for ( V_16 = 0 ; V_16 < V_2 -> V_98 ; V_16 ++ ) {
V_95 = F_89 ( V_27 , V_16 ) ;
if ( V_95 ) {
F_90 ( L_26 , V_16 ) ;
F_90 ( L_27 ) ;
F_88 ( V_27 , V_16 ) ;
F_102 ( V_27 , V_16 , 0x4000000F ) ;
}
}
F_4 ( V_2 ) ;
V_5:
F_103 ( & V_40 ) ;
return 0 ;
}
static int T_6 F_104 ( int V_99 , int V_100 , int V_101 , int V_102 )
{
int V_16 = 0 ;
unsigned int V_30 = 0 ;
unsigned int V_31 = 0 ;
int V_103 , V_104 , V_105 , V_106 ;
F_46 ( V_30 ) ;
F_47 ( V_31 ) ;
for ( V_16 = 0 ; V_16 < V_63 ; V_16 ++ ) {
V_106 = F_105 ( V_30 , V_16 ) ;
V_105 = F_106 ( V_30 , V_16 ) ;
V_103 = F_107 ( V_31 , V_16 ) ;
V_104 = F_108 ( V_31 , V_16 ) ;
if ( V_99 == V_103 && V_100 == V_104 && V_105 == V_101 && V_106 == V_102 )
return V_16 ;
}
return - V_107 ;
}
static void T_6 F_109 ( void )
{
V_61 [ V_108 ] =
F_104 ( V_109 , V_109 , V_110 , 1 ) ;
V_61 [ V_111 ] =
F_104 ( V_112 , V_112 , V_110 , 1 ) ;
V_61 [ V_113 ] =
F_104 ( V_114 , V_114 , V_110 , 1 ) ;
V_61 [ V_115 ] =
F_104 ( V_116 , V_116 , V_110 , 1 ) ;
}
static int T_6 F_110 ( void )
{
F_109 () ;
F_111 ( & V_117 , & V_118 ) ;
return 0 ;
}
