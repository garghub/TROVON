static inline void F_1 ( int V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_3 . V_4 + V_1 ) ;
}
static inline int F_3 ( int V_1 )
{
return F_4 ( V_3 . V_4 + V_1 ) ;
}
static void T_2 F_5 ( void )
{
V_5 = 0 ;
F_1 ( V_6 , 0 ) ;
}
void F_6 ( T_1 V_7 )
{
V_5 |= V_7 ;
F_1 ( V_6 , V_5 | V_8 ) ;
}
void F_7 ( T_1 V_7 )
{
V_5 &= ~ V_7 ;
if ( V_5 == 0 )
F_1 ( V_6 , 0 ) ;
else
F_1 ( V_6 ,
V_5 | V_8 ) ;
}
static T_3 F_8 ( int V_9 , void * V_10 )
{
int V_11 ;
T_3 V_12 = V_13 ;
F_9 ( & V_3 . V_14 ) ;
V_11 = F_3 ( V_15 ) ;
if ( V_11 & V_16 ) {
F_1 ( V_15 , V_16 ) ;
F_10 ( & V_17 ) ;
V_12 = V_18 ;
}
F_11 ( & V_3 . V_14 ) ;
return V_12 ;
}
int F_12 ( void )
{
int V_12 = 0 ;
if ( V_3 . V_19 != V_20 )
return - V_21 ;
F_13 ( & V_22 ) ;
V_23 ++ ;
if ( V_23 == 1 ) {
V_12 = F_14 ( V_3 . V_24 -> V_9 , F_8 ,
V_25 , L_1 , & V_23 ) ;
if ( V_12 )
V_23 -- ;
else
F_6 ( V_26 ) ;
}
F_15 ( & V_22 ) ;
return V_12 ;
}
void F_16 ( void )
{
F_13 ( & V_22 ) ;
V_23 -- ;
if ( V_23 == 0 ) {
F_7 ( V_26 ) ;
F_17 ( V_3 . V_24 -> V_9 , & V_23 ) ;
}
F_15 ( & V_22 ) ;
}
int F_18 ( unsigned int V_27 , struct V_28 * V_29 , int V_30 )
{
struct V_31 * V_32 ;
void * V_33 ;
T_4 V_34 ;
unsigned long V_35 ;
int V_36 ;
struct V_28 * V_37 ;
T_4 V_38 ;
V_33 = F_19 ( & V_3 . V_24 -> V_39 ,
V_30 * sizeof( struct V_31 ) ,
& V_34 , V_40 ) ;
if ( V_33 == NULL ) {
F_20 ( & V_3 . V_24 -> V_39 , L_2 ) ;
return - V_41 ;
}
F_13 ( & V_22 ) ;
V_32 = V_33 ;
V_38 = V_34 + sizeof( struct V_31 ) ;
F_21 (sg, sgentry, nsg, i) {
T_4 V_42 = F_22 ( V_37 ) ;
V_32 -> V_43 = V_42 & 0xfffffff0 ;
V_32 -> V_44 = ( ( V_45 ) V_42 >> 32 ) & 0x0fff ;
V_32 -> V_46 = V_27 ;
V_32 -> V_47 = F_23 ( V_37 ) >> 4 ;
V_32 -> V_48 = 0 ;
V_32 -> V_49 = ( V_38 & 0xfffffff0 ) | V_50 ;
V_32 -> V_51 = ( ( V_45 ) V_38 >> 32 ) & 0x0fff ;
V_32 -> V_52 = 0xffffffff ;
V_27 += F_23 ( V_37 ) ;
V_38 += sizeof( struct V_31 ) ;
V_32 ++ ;
}
V_32 [ - 1 ] . V_49 = V_53 | V_50 ;
F_24 ( & V_3 . V_14 , V_35 ) ;
F_25 ( & V_17 ) ;
F_1 ( V_54 , 0 ) ;
F_1 ( V_15 , V_55 | V_16 ) ;
F_1 ( V_56 , V_57 | V_58 ) ;
F_1 ( V_59 , V_34 | V_50 ) ;
F_1 ( V_60 ,
( ( ( V_45 ) V_34 >> 32 ) & 0x0fff ) | 0xf0000 ) ;
( void ) F_3 ( V_15 ) ;
F_1 ( V_15 , V_55 | V_61 ) ;
F_26 ( & V_3 . V_14 , V_35 ) ;
F_27 ( & V_17 , 1 ) ;
F_28 ( 1 ) ;
if ( ( F_3 ( V_15 ) & V_16 ) == 0 )
F_29 ( V_62 L_3 ) ;
F_1 ( V_15 , V_16 ) ;
F_1 ( V_56 , 0 ) ;
F_15 ( & V_22 ) ;
F_30 ( & V_3 . V_24 -> V_39 ,
V_30 * sizeof( struct V_31 ) , V_33 ,
V_34 ) ;
return 0 ;
}
static int F_31 ( int V_19 )
{
int V_36 ;
T_5 V_27 = 0 ;
T_1 V_63 ;
T_1 V_64 ;
for ( V_36 = 0 ; V_36 < F_32 ( V_65 ) ; V_36 ++ ) {
struct V_66 * V_24 ;
V_24 = F_33 ( V_67 , V_65 [ V_36 ] ,
NULL ) ;
if ( ! V_24 )
continue;
F_34 ( V_68 L_4 , V_24 -> V_69 ) ;
switch ( V_24 -> V_69 ) {
case V_70 :
case V_71 :
V_27 = 0xE0 ;
break;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
V_27 = 0xA0 ;
break;
}
if ( ! V_27 )
break;
F_35 ( V_24 , V_27 , & V_63 ) ;
F_36 ( V_24 ) ;
}
if ( ! V_27 ) {
F_29 ( V_62 L_5 ) ;
return - V_82 ;
}
V_63 = V_63 & 0x00007000 ;
F_34 ( V_68 L_6 , V_63 ) ;
if ( V_19 < V_83 ) {
switch ( V_63 ) {
case 0x00004000 :
V_64 = ( 16 << 20 ) ;
break;
case 0x00005000 :
V_64 = ( 32 << 20 ) ;
break;
case 0x00006000 :
V_64 = ( 64 << 20 ) ;
break;
default:
V_64 = ( 32 << 20 ) ;
break;
}
} else {
switch ( V_63 ) {
case 0x00001000 :
V_64 = ( 8 << 20 ) ;
break;
case 0x00002000 :
V_64 = ( 16 << 20 ) ;
break;
case 0x00003000 :
V_64 = ( 32 << 20 ) ;
break;
case 0x00004000 :
V_64 = ( 64 << 20 ) ;
break;
case 0x00005000 :
V_64 = ( 128 << 20 ) ;
break;
case 0x00006000 :
V_64 = ( 256 << 20 ) ;
break;
case 0x00007000 :
V_64 = ( 512 << 20 ) ;
break;
default:
V_64 = ( 32 << 20 ) ;
break;
}
}
return V_64 ;
}
static int T_2 F_37 ( struct V_84 * V_85 )
{
int V_12 ;
V_85 -> V_86 = F_38 ( V_85 -> V_24 , 1 ) ;
V_85 -> V_87 = F_39 ( V_85 -> V_24 , 1 ) ;
V_85 -> V_4 = F_40 ( V_85 -> V_86 ,
V_85 -> V_87 ) ;
if ( V_85 -> V_4 == NULL )
F_20 ( & V_85 -> V_24 -> V_39 ,
L_7
L_8 ) ;
if ( V_85 -> V_19 == V_88 )
V_85 -> V_89 = F_38 ( V_85 -> V_24 , 2 ) ;
else
V_85 -> V_89 = F_38 ( V_85 -> V_24 , 0 ) ;
V_12 = V_85 -> V_90 = F_31 ( V_85 -> V_19 ) ;
if ( V_12 < 0 )
goto V_91;
for (; V_85 -> V_90 >= 8 << 20 ; V_85 -> V_90 /= 2 ) {
V_85 -> V_92 = F_41 ( V_85 -> V_89 , V_85 -> V_90 ) ;
if ( V_85 -> V_92 )
break;
}
if ( V_85 -> V_92 == NULL ) {
V_12 = - V_41 ;
goto V_91;
}
return 0 ;
V_91:
F_42 ( V_85 -> V_4 ) ;
return V_12 ;
}
static void F_43 ( struct V_84 * V_85 )
{
F_42 ( V_85 -> V_92 ) ;
F_42 ( V_85 -> V_4 ) ;
}
static int T_2 F_44 ( struct V_84 * V_85 ,
struct V_93 * V_94 )
{
int V_12 ;
V_94 -> V_95 = F_45 ( V_94 -> V_96 , - 1 ) ;
if ( ! V_94 -> V_95 ) {
F_20 ( & V_85 -> V_24 -> V_39 , L_9 ,
V_94 -> V_96 ) ;
return - V_41 ;
}
V_94 -> V_95 -> V_39 . V_97 = & V_85 -> V_24 -> V_39 ;
V_94 -> V_95 -> V_39 . V_98 = V_85 ;
V_12 = F_46 ( V_94 -> V_95 ) ;
if ( V_12 ) {
F_20 ( & V_85 -> V_24 -> V_39 , L_10 ,
V_94 -> V_96 ) ;
F_47 ( V_94 -> V_95 ) ;
V_94 -> V_95 = NULL ;
}
return V_12 ;
}
static int T_2 F_48 ( struct V_84 * V_85 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_99 ; V_36 ++ )
F_44 ( V_85 , V_100 + V_36 ) ;
return 0 ;
}
static void F_49 ( void )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_99 ; V_36 ++ )
if ( V_100 [ V_36 ] . V_95 ) {
V_100 [ V_36 ] . V_95 -> V_39 . V_98 = NULL ;
F_50 ( V_100 [ V_36 ] . V_95 ) ;
}
}
void F_51 ( struct V_101 * V_102 )
{
F_52 ( & V_102 -> V_103 ) ;
F_13 ( & V_104 ) ;
F_53 ( & V_102 -> V_103 , & V_101 ) ;
F_15 ( & V_104 ) ;
}
void F_54 ( struct V_101 * V_102 )
{
F_13 ( & V_104 ) ;
F_55 ( & V_102 -> V_103 ) ;
F_15 ( & V_104 ) ;
}
static int F_56 ( struct V_66 * V_24 , T_6 V_105 )
{
struct V_101 * V_102 ;
if ( V_105 . V_106 != V_107 )
return 0 ;
F_13 ( & V_104 ) ;
F_57 (hooks, &viafb_pm_hooks, list)
V_102 -> V_108 ( V_102 -> V_109 ) ;
F_15 ( & V_104 ) ;
F_58 ( V_24 ) ;
F_59 ( V_24 ) ;
F_60 ( V_24 , F_61 ( V_24 , V_105 ) ) ;
return 0 ;
}
static int F_62 ( struct V_66 * V_24 )
{
struct V_101 * V_102 ;
F_60 ( V_24 , V_110 ) ;
F_63 ( V_24 ) ;
if ( F_64 ( V_24 ) )
return 0 ;
F_65 ( V_24 ) ;
F_13 ( & V_104 ) ;
F_66 (hooks, &viafb_pm_hooks, list)
V_102 -> V_111 ( V_102 -> V_109 ) ;
F_15 ( & V_104 ) ;
return 0 ;
}
static int T_2 F_67 ( struct V_66 * V_24 ,
const struct V_112 * V_113 )
{
int V_12 ;
V_12 = F_64 ( V_24 ) ;
if ( V_12 )
return V_12 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_24 = V_24 ;
V_3 . V_19 = V_113 -> V_114 ;
V_3 . V_115 = V_116 ;
if ( F_68 () )
V_3 . V_115 = V_117 ;
F_69 ( & V_3 . V_14 ) ;
V_12 = F_37 ( & V_3 ) ;
if ( V_12 )
goto V_118;
F_5 () ;
F_48 ( & V_3 ) ;
V_12 = F_70 ( & V_3 ) ;
if ( V_12 )
goto V_119;
return 0 ;
V_119:
F_49 () ;
F_43 ( & V_3 ) ;
V_118:
F_59 ( V_24 ) ;
return V_12 ;
}
static void T_7 F_71 ( struct V_66 * V_24 )
{
F_49 () ;
F_72 ( V_24 ) ;
F_43 ( & V_3 ) ;
F_59 ( V_24 ) ;
}
static int T_8 F_73 ( void )
{
int V_12 ;
V_12 = F_74 () ;
if ( V_12 )
return V_12 ;
F_75 () ;
F_76 () ;
return F_77 ( & V_120 ) ;
}
static void T_9 F_78 ( void )
{
F_79 ( & V_120 ) ;
F_80 () ;
F_81 () ;
F_82 () ;
}
