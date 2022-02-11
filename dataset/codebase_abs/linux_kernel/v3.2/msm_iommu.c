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
return 0 ;
V_33:
F_65 ( V_10 ) ;
return - V_34 ;
}
static void F_66 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
unsigned long V_35 ;
unsigned long * V_14 ;
int V_16 ;
F_67 ( & V_36 , V_35 ) ;
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
F_70 ( & V_36 , V_35 ) ;
}
static int F_71 ( struct V_7 * V_8 , struct V_37 * V_25 )
{
struct V_9 * V_10 ;
struct V_38 * V_39 ;
struct V_1 * V_11 ;
struct V_12 * V_13 ;
struct V_12 * V_40 ;
int V_3 = 0 ;
unsigned long V_35 ;
F_67 ( & V_36 , V_35 ) ;
V_10 = V_8 -> V_10 ;
if ( ! V_10 || ! V_25 ) {
V_3 = - V_41 ;
goto V_5;
}
V_11 = F_12 ( V_25 -> V_26 ) ;
V_13 = F_12 ( V_25 ) ;
V_39 = V_25 -> V_42 ;
if ( ! V_11 || ! V_13 || ! V_39 ) {
V_3 = - V_41 ;
goto V_5;
}
if ( ! F_7 ( & V_13 -> V_43 ) ) {
V_3 = - V_44 ;
goto V_5;
}
F_10 (tmp_drvdata, &priv->list_attached, attached_elm)
if ( V_40 == V_13 ) {
V_3 = - V_44 ;
goto V_5;
}
V_3 = F_1 ( V_11 ) ;
if ( V_3 )
goto V_5;
F_35 ( V_11 -> V_27 , V_39 -> V_28 ,
F_72 ( V_10 -> V_15 ) ) ;
F_4 ( V_11 ) ;
F_73 ( & ( V_13 -> V_43 ) , & V_10 -> V_17 ) ;
V_3 = F_5 ( V_8 ) ;
V_5:
F_70 ( & V_36 , V_35 ) ;
return V_3 ;
}
static void F_74 ( struct V_7 * V_8 ,
struct V_37 * V_25 )
{
struct V_9 * V_10 ;
struct V_38 * V_39 ;
struct V_1 * V_11 ;
struct V_12 * V_13 ;
unsigned long V_35 ;
int V_3 ;
F_67 ( & V_36 , V_35 ) ;
V_10 = V_8 -> V_10 ;
if ( ! V_10 || ! V_25 )
goto V_5;
V_11 = F_12 ( V_25 -> V_26 ) ;
V_13 = F_12 ( V_25 ) ;
V_39 = V_25 -> V_42 ;
if ( ! V_11 || ! V_13 || ! V_39 )
goto V_5;
V_3 = F_5 ( V_8 ) ;
if ( V_3 )
goto V_5;
V_3 = F_1 ( V_11 ) ;
if ( V_3 )
goto V_5;
F_15 ( V_11 -> V_27 , V_39 -> V_28 ) ;
F_4 ( V_11 ) ;
F_75 ( & V_13 -> V_43 ) ;
V_5:
F_70 ( & V_36 , V_35 ) ;
}
static int F_76 ( struct V_7 * V_8 , unsigned long V_45 ,
T_2 V_46 , int V_47 , int V_48 )
{
struct V_9 * V_10 ;
unsigned long V_35 ;
unsigned long * V_14 ;
unsigned long * V_49 ;
unsigned long V_50 ;
unsigned long * V_21 ;
unsigned long * V_51 ;
unsigned long V_52 ;
unsigned int V_53 ;
T_3 V_54 = 0x1000UL << V_47 ;
int V_3 = 0 , V_55 , V_56 ;
F_67 ( & V_36 , V_35 ) ;
V_56 = ( V_48 & V_57 ) ? 1 : 0 ;
V_55 = V_58 [ V_48 & V_59 ] ;
if ( V_55 < 0 || V_55 > V_60 - 1 ) {
V_3 = - V_41 ;
goto V_5;
}
V_10 = V_8 -> V_10 ;
if ( ! V_10 ) {
V_3 = - V_41 ;
goto V_5;
}
V_14 = V_10 -> V_15 ;
if ( V_54 != V_61 && V_54 != V_62 &&
V_54 != V_63 && V_54 != V_23 ) {
F_77 ( L_1 , V_54 ) ;
V_3 = - V_41 ;
goto V_5;
}
if ( ! V_14 ) {
F_77 ( L_2 ) ;
V_3 = - V_41 ;
goto V_5;
}
if ( V_54 == V_61 || V_54 == V_62 ) {
V_53 = V_56 ? V_64 : 0 ;
V_53 |= V_55 & 0x01 ? V_65 : 0 ;
V_53 |= V_55 & 0x02 ? V_66 : 0 ;
V_53 |= V_55 & 0x04 ? V_67 : 0 ;
} else {
V_53 = V_56 ? V_68 : 0 ;
V_53 |= V_55 & 0x01 ? V_69 : 0 ;
V_53 |= V_55 & 0x02 ? V_70 : 0 ;
V_53 |= V_55 & 0x04 ? V_71 : 0 ;
}
V_50 = F_78 ( V_45 ) ;
V_49 = V_14 + V_50 ;
if ( V_54 == V_61 ) {
int V_16 = 0 ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
* ( V_49 + V_16 ) = ( V_46 & 0xFF000000 ) | V_72 |
V_73 | V_74 | V_75 |
V_64 | V_76 | V_53 ;
}
if ( V_54 == V_62 )
* V_49 = ( V_46 & 0xFFF00000 ) | V_73 | V_74 | V_76 |
V_75 | V_64 | V_53 ;
if ( ( V_54 == V_23 || V_54 == V_63 ) && ( * V_49 ) == 0 ) {
unsigned long * V_77 ;
V_77 = ( unsigned long * ) F_63 ( V_78 ,
F_64 ( V_23 ) ) ;
if ( ! V_77 ) {
F_77 ( L_3 ) ;
V_3 = - V_34 ;
goto V_5;
}
memset ( V_77 , 0 , V_23 ) ;
* V_49 = ( ( ( ( int ) F_72 ( V_77 ) ) & V_22 ) | V_20 ) ;
}
V_21 = ( unsigned long * ) F_9 ( ( ( * V_49 ) & V_22 ) ) ;
V_52 = F_79 ( V_45 ) ;
V_51 = V_21 + V_52 ;
if ( V_54 == V_23 )
* V_51 = ( V_46 & V_79 ) | V_80 | V_81 | V_82 |
V_68 | V_83 | V_53 ;
if ( V_54 == V_63 ) {
int V_16 ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
* ( V_51 + V_16 ) = ( V_46 & V_84 ) | V_80 |
V_82 | V_81 | V_68 | V_85 | V_53 ;
}
V_3 = F_5 ( V_8 ) ;
V_5:
F_70 ( & V_36 , V_35 ) ;
return V_3 ;
}
static int F_80 ( struct V_7 * V_8 , unsigned long V_45 ,
int V_47 )
{
struct V_9 * V_10 ;
unsigned long V_35 ;
unsigned long * V_14 ;
unsigned long * V_49 ;
unsigned long V_50 ;
unsigned long * V_21 ;
unsigned long * V_51 ;
unsigned long V_52 ;
T_3 V_54 = 0x1000UL << V_47 ;
int V_16 , V_3 = 0 ;
F_67 ( & V_36 , V_35 ) ;
V_10 = V_8 -> V_10 ;
if ( ! V_10 ) {
V_3 = - V_86 ;
goto V_5;
}
V_14 = V_10 -> V_15 ;
if ( V_54 != V_61 && V_54 != V_62 &&
V_54 != V_63 && V_54 != V_23 ) {
F_77 ( L_4 , V_54 ) ;
V_3 = - V_41 ;
goto V_5;
}
if ( ! V_14 ) {
F_77 ( L_2 ) ;
V_3 = - V_41 ;
goto V_5;
}
V_50 = F_78 ( V_45 ) ;
V_49 = V_14 + V_50 ;
if ( * V_49 == 0 ) {
F_77 ( L_5 ) ;
V_3 = - V_86 ;
goto V_5;
}
if ( V_54 == V_61 )
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
* ( V_49 + V_16 ) = 0 ;
if ( V_54 == V_62 )
* V_49 = 0 ;
V_21 = ( unsigned long * ) F_9 ( ( ( * V_49 ) & V_22 ) ) ;
V_52 = F_79 ( V_45 ) ;
V_51 = V_21 + V_52 ;
if ( V_54 == V_63 ) {
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
* ( V_51 + V_16 ) = 0 ;
}
if ( V_54 == V_23 )
* V_51 = 0 ;
if ( V_54 == V_23 || V_54 == V_63 ) {
int V_87 = 0 ;
for ( V_16 = 0 ; V_16 < V_88 ; V_16 ++ )
if ( V_21 [ V_16 ] )
V_87 = 1 ;
if ( ! V_87 ) {
F_68 ( ( unsigned long ) V_21 ) ;
* V_49 = 0 ;
}
}
V_3 = F_5 ( V_8 ) ;
if ( ! V_3 )
V_3 = V_47 ;
V_5:
F_70 ( & V_36 , V_35 ) ;
return V_3 ;
}
static T_2 F_81 ( struct V_7 * V_8 ,
unsigned long V_45 )
{
struct V_9 * V_10 ;
struct V_1 * V_11 ;
struct V_12 * V_13 ;
unsigned int V_89 ;
unsigned long V_35 ;
void T_1 * V_27 ;
T_2 V_3 = 0 ;
int V_29 ;
F_67 ( & V_36 , V_35 ) ;
V_10 = V_8 -> V_10 ;
if ( F_7 ( & V_10 -> V_17 ) )
goto V_5;
V_13 = F_82 ( V_10 -> V_17 . V_90 ,
struct V_12 , V_43 ) ;
V_11 = F_12 ( V_13 -> V_24 -> V_25 . V_26 ) ;
V_27 = V_11 -> V_27 ;
V_29 = V_13 -> V_28 ;
V_3 = F_1 ( V_11 ) ;
if ( V_3 )
goto V_5;
F_14 ( V_27 , V_29 , 0 ) ;
F_83 ( V_27 , V_29 , V_45 & V_91 ) ;
V_89 = F_84 ( V_27 , V_29 ) ;
if ( F_85 ( V_27 , V_29 ) )
V_3 = ( V_89 & 0xFF000000 ) | ( V_45 & 0x00FFFFFF ) ;
else
V_3 = ( V_89 & 0xFFFFF000 ) | ( V_45 & 0x00000FFF ) ;
if ( F_86 ( V_27 , V_29 ) )
V_3 = 0 ;
F_4 ( V_11 ) ;
V_5:
F_70 ( & V_36 , V_35 ) ;
return V_3 ;
}
static int F_87 ( struct V_7 * V_8 ,
unsigned long V_92 )
{
return 0 ;
}
static void F_88 ( void T_1 * V_27 , int V_29 )
{
unsigned int V_93 = F_89 ( V_27 , V_29 ) ;
F_90 ( L_6 ,
F_91 ( V_27 , V_29 ) , F_84 ( V_27 , V_29 ) ) ;
F_90 ( L_7 , V_93 ,
( V_93 & 0x02 ) ? L_8 : L_9 ,
( V_93 & 0x04 ) ? L_10 : L_9 ,
( V_93 & 0x08 ) ? L_11 : L_9 ,
( V_93 & 0x10 ) ? L_12 : L_9 ,
( V_93 & 0x20 ) ? L_13 : L_9 ,
( V_93 & 0x40 ) ? L_14 : L_9 ,
( V_93 & 0x80 ) ? L_15 : L_9 ,
( V_93 & 0x10000 ) ? L_16 : L_9 ,
( V_93 & 0x40000000 ) ? L_17 : L_9 ,
( V_93 & 0x80000000 ) ? L_18 : L_9 ) ;
F_90 ( L_19 ,
F_92 ( V_27 , V_29 ) , F_93 ( V_27 , V_29 ) ) ;
F_90 ( L_20 ,
F_94 ( V_27 , V_29 ) , F_95 ( V_27 , V_29 ) ) ;
F_90 ( L_21 ,
F_96 ( V_27 , V_29 ) , F_97 ( V_27 , V_29 ) ) ;
F_90 ( L_22 ,
F_98 ( V_27 , V_29 ) , F_99 ( V_27 , V_29 ) ) ;
}
T_4 F_100 ( int V_94 , void * V_95 )
{
struct V_1 * V_2 = V_95 ;
void T_1 * V_27 ;
unsigned int V_93 ;
int V_16 , V_3 ;
F_101 ( & V_36 ) ;
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
for ( V_16 = 0 ; V_16 < V_2 -> V_96 ; V_16 ++ ) {
V_93 = F_89 ( V_27 , V_16 ) ;
if ( V_93 ) {
F_90 ( L_26 , V_16 ) ;
F_90 ( L_27 ) ;
F_88 ( V_27 , V_16 ) ;
F_102 ( V_27 , V_16 , 0x4000000F ) ;
}
}
F_4 ( V_2 ) ;
V_5:
F_103 ( & V_36 ) ;
return 0 ;
}
static int T_5 F_104 ( int V_97 , int V_98 , int V_99 , int V_100 )
{
int V_16 = 0 ;
unsigned int V_30 = 0 ;
unsigned int V_31 = 0 ;
int V_101 , V_102 , V_103 , V_104 ;
F_46 ( V_30 ) ;
F_47 ( V_31 ) ;
for ( V_16 = 0 ; V_16 < V_60 ; V_16 ++ ) {
V_104 = F_105 ( V_30 , V_16 ) ;
V_103 = F_106 ( V_30 , V_16 ) ;
V_101 = F_107 ( V_31 , V_16 ) ;
V_102 = F_108 ( V_31 , V_16 ) ;
if ( V_97 == V_101 && V_98 == V_102 && V_103 == V_99 && V_104 == V_100 )
return V_16 ;
}
return - V_86 ;
}
static void T_5 F_109 ( void )
{
V_58 [ V_105 ] =
F_104 ( V_106 , V_106 , V_107 , 1 ) ;
V_58 [ V_108 ] =
F_104 ( V_109 , V_109 , V_107 , 1 ) ;
V_58 [ V_110 ] =
F_104 ( V_111 , V_111 , V_107 , 1 ) ;
V_58 [ V_112 ] =
F_104 ( V_113 , V_113 , V_107 , 1 ) ;
}
static int T_5 F_110 ( void )
{
F_109 () ;
F_111 ( & V_114 , & V_115 ) ;
return 0 ;
}
