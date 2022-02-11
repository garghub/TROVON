static inline void F_1 ( void T_1 * V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned long V_4 )
{
F_2 ( V_4 , F_3 ( V_1 , V_2 , V_3 ) ) ;
}
static inline unsigned long F_4 ( void T_1 * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
return F_5 ( F_3 ( V_1 , V_2 , V_3 ) ) ;
}
static inline void F_6 ( void T_1 * V_1 , unsigned int V_3 ,
unsigned long V_4 )
{
F_2 ( V_4 , V_1 + V_3 ) ;
}
static inline unsigned long F_7 ( void T_1 * V_1 , unsigned int V_3 )
{
return F_5 ( V_1 + V_3 ) ;
}
static int F_8 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
T_2 V_9 )
{
unsigned long V_10 ;
unsigned long V_2 ;
V_2 = F_9 ( & V_6 -> V_11 , 28 ) ;
if ( V_2 == 28 )
return - V_12 ;
V_8 -> V_13 = & V_6 -> V_14 [ V_2 ] ;
V_2 = F_10 ( & V_6 -> V_11 , 32 , 28 ) ;
if ( V_2 == 32 )
return - V_12 ;
V_8 -> V_15 = & V_6 -> V_14 [ V_2 ] ;
V_10 = F_11 ( V_6 -> V_16 , V_9 * 1024 ) ;
if ( V_10 == 0 )
return - V_12 ;
F_12 ( V_8 -> V_15 -> V_17 , & V_6 -> V_11 ) ;
F_12 ( V_8 -> V_13 -> V_17 , & V_6 -> V_11 ) ;
V_8 -> V_15 -> V_18 = V_10 - V_6 -> V_19 ;
V_8 -> V_15 -> V_9 = V_9 ;
return 0 ;
}
static void F_13 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
F_14 ( V_6 -> V_16 , V_6 -> V_19 + V_8 -> V_15 -> V_18 ,
V_8 -> V_15 -> V_9 * 1024 ) ;
F_15 ( V_8 -> V_15 -> V_17 , & V_6 -> V_11 ) ;
F_15 ( V_8 -> V_13 -> V_17 , & V_6 -> V_11 ) ;
}
static int F_16 ( int V_20 )
{
if ( V_20 == V_21 ||
V_20 == V_22 )
return 1 ;
return 0 ;
}
static struct V_23 *
F_17 ( struct V_5 * V_6 ,
const struct V_24 * V_25 ,
int V_26 )
{
struct V_23 * V_13 ;
unsigned int V_27 = F_16 ( V_26 ) ? 2 : 1 ;
int V_28 ;
if ( V_25 -> V_29 [ 0 ] . V_30 == 0 )
return F_18 ( - V_31 ) ;
if ( V_27 == 2 && V_25 -> V_29 [ 1 ] . V_30 == 0 )
return F_18 ( - V_31 ) ;
V_13 = F_19 ( sizeof( * V_13 ) , V_32 ) ;
if ( V_13 == NULL )
return F_18 ( - V_12 ) ;
V_13 -> V_27 = V_27 ;
V_28 = F_8 ( V_6 , & V_13 -> V_33 [ 0 ] , V_25 -> V_29 [ 0 ] . V_30 ) ;
if ( V_28 < 0 )
goto error;
V_13 -> V_33 [ 0 ] . V_15 -> V_34 = 1 ;
V_13 -> V_33 [ 0 ] . V_15 -> V_26 = V_26 ;
if ( V_13 -> V_27 == 1 )
return V_13 ;
V_28 = F_8 ( V_6 , & V_13 -> V_33 [ 1 ] , V_25 -> V_29 [ 1 ] . V_30 ) ;
if ( V_28 < 0 ) {
F_13 ( V_6 , & V_13 -> V_33 [ 0 ] ) ;
goto error;
}
return V_13 ;
error:
F_20 ( V_13 ) ;
return F_18 ( - V_12 ) ;
}
static void F_21 ( struct V_5 * V_6 ,
struct V_23 * V_13 )
{
F_13 ( V_6 , & V_13 -> V_33 [ 0 ] ) ;
if ( V_13 -> V_27 == 2 )
F_13 ( V_6 , & V_13 -> V_33 [ 1 ] ) ;
F_20 ( V_13 ) ;
}
static void F_22 ( struct V_5 * V_6 ,
struct V_23 * V_13 ,
unsigned long V_35 ,
unsigned long V_36 )
{
struct V_37 * V_29 = V_13 -> V_33 [ 0 ] . V_15 ;
unsigned long V_38 ;
V_29 -> V_34 ^= 1 ;
V_38 = V_29 -> V_34 ? V_39 : V_40 ;
F_1 ( V_6 -> V_1 , V_13 -> V_33 [ 0 ] . V_13 -> V_17 , V_38 ,
V_35 ) ;
F_1 ( V_6 -> V_1 , V_13 -> V_33 [ 0 ] . V_15 -> V_17 , V_38 ,
V_35 + V_13 -> V_33 [ 0 ] . V_15 -> V_41 ) ;
if ( V_13 -> V_27 == 2 ) {
F_1 ( V_6 -> V_1 , V_13 -> V_33 [ 1 ] . V_13 -> V_17 ,
V_38 , V_36 ) ;
F_1 ( V_6 -> V_1 , V_13 -> V_33 [ 1 ] . V_15 -> V_17 ,
V_38 , V_36 +
V_13 -> V_33 [ 1 ] . V_15 -> V_41 ) ;
}
}
static void
F_23 ( struct V_42 * V_43 ,
struct V_23 * V_13 ,
unsigned long * V_44 , unsigned long * V_45 )
{
struct V_37 * V_29 = V_13 -> V_33 [ 0 ] . V_15 ;
unsigned long V_46 ;
if ( V_43 -> V_47 == V_48 )
V_46 = 0x80000000 | ( V_29 -> V_34 << 29 ) ;
else
V_46 = 0xc0000000 | ( V_29 -> V_34 << 23 ) ;
* V_44 = V_46 | ( V_13 -> V_33 [ 0 ] . V_15 -> V_17 << 24 ) ;
if ( V_13 -> V_27 == 2 )
* V_45 = V_46
| ( V_13 -> V_33 [ 1 ] . V_15 -> V_17 << 24 ) ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int V_49 , unsigned int V_50 ,
unsigned int * V_51 )
{
struct V_37 * V_15 = V_8 -> V_15 ;
unsigned long V_52 = F_25 ( V_49 , V_50 ) ;
unsigned long V_53 ;
unsigned int V_54 ;
unsigned int V_55 ;
unsigned int V_56 ;
unsigned int V_57 ;
V_54 = ( V_49 - 1 ) | 1023 ;
V_54 = V_54 | ( V_54 >> 1 ) ;
V_54 = V_54 | ( V_54 >> 2 ) ;
V_54 += 1 ;
if ( V_54 == 8192 && V_50 >= 1024 ) {
V_54 = V_55 = V_58 ;
V_56 = V_52 >> 11 ;
* V_51 = V_49 ;
V_57 = V_8 -> V_15 -> V_9 / 16 / V_59 ;
V_57 *= V_59 ;
} else {
V_55 = V_49 ;
V_56 = V_50 ;
* V_51 = V_54 ;
V_57 = V_8 -> V_15 -> V_9 / ( V_54 >> 10 ) / 2 ;
V_57 &= 0xff ;
}
V_53 = ( V_57 - 1 ) << 16 ;
F_1 ( V_6 -> V_1 , V_8 -> V_13 -> V_17 , V_60 ,
F_26 ( 0x0 , V_56 - 1 , V_55 - 1 ) ) ;
F_1 ( V_6 -> V_1 , V_8 -> V_15 -> V_17 , V_60 ,
F_26 ( 0xf , V_56 - 1 , V_55 - 1 ) ) ;
F_1 ( V_6 -> V_1 , V_8 -> V_13 -> V_17 , V_61 , V_53 ) ;
F_1 ( V_6 -> V_1 , V_8 -> V_15 -> V_17 , V_61 , V_53 ) ;
F_1 ( V_6 -> V_1 , V_8 -> V_13 -> V_17 , V_62 , V_55 ) ;
F_1 ( V_6 -> V_1 , V_8 -> V_15 -> V_17 , V_62 , V_55 ) ;
V_8 -> V_13 -> V_41 = V_49 * V_57 ;
V_8 -> V_15 -> V_41 = V_49 * V_57 ;
F_1 ( V_6 -> V_1 , V_8 -> V_13 -> V_17 , V_63 ,
F_27 ( V_8 -> V_15 -> V_17 , V_15 -> V_18 )
| V_64 | V_65 | V_66 | V_67 |
V_68 ) ;
F_1 ( V_6 -> V_1 , V_8 -> V_15 -> V_17 , V_63 ,
F_27 ( V_8 -> V_13 -> V_17 , V_15 -> V_18 +
V_8 -> V_15 -> V_9 / 2 ) |
V_64 | V_65 | V_66 | V_67 |
V_68 ) ;
return 0 ;
}
static void F_28 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
F_1 ( V_6 -> V_1 , V_8 -> V_13 -> V_17 , V_63 ,
V_69 | V_70 | V_71 ) ;
F_1 ( V_6 -> V_1 , V_8 -> V_15 -> V_17 , V_63 ,
V_69 | V_70 | V_71 ) ;
V_8 -> V_13 -> V_41 = 0 ;
V_8 -> V_15 -> V_41 = 0 ;
}
static void * F_29 ( struct V_42 * V_43 ,
const struct V_24 * V_25 ,
unsigned int V_49 , unsigned int V_50 ,
unsigned int V_26 ,
unsigned int * V_72 )
{
struct V_23 * V_13 ;
struct V_5 * V_6 = V_43 -> V_6 ;
struct V_73 * V_74 = V_43 -> V_74 ;
unsigned int V_51 ;
if ( V_26 != V_21 &&
V_26 != V_22 &&
V_26 != V_75 )
return F_18 ( - V_31 ) ;
F_30 ( & V_74 -> V_76 , L_1 , V_49 , V_50 ,
! V_26 ? L_2 : L_3 ) ;
if ( V_49 > 8192 ) {
F_31 ( & V_74 -> V_76 , L_4 ) ;
return F_18 ( - V_31 ) ;
}
F_32 ( & V_6 -> V_77 ) ;
V_13 = F_17 ( V_6 , V_25 , V_26 ) ;
if ( F_33 ( V_13 ) ) {
F_31 ( & V_74 -> V_76 , L_5 ,
F_34 ( V_13 ) ) ;
goto V_78;
}
F_24 ( V_6 , & V_13 -> V_33 [ 0 ] , V_49 , V_50 , & V_51 ) ;
* V_72 = V_51 ;
if ( V_26 == V_21 )
F_24 ( V_6 , & V_13 -> V_33 [ 1 ] , V_49 , ( V_50 + 1 ) / 2 ,
& V_51 ) ;
else if ( V_26 == V_22 )
F_24 ( V_6 , & V_13 -> V_33 [ 1 ] , 2 * V_49 , ( V_50 + 1 ) / 2 ,
& V_51 ) ;
V_78:
F_35 ( & V_6 -> V_77 ) ;
return V_13 ;
}
static void
F_36 ( struct V_42 * V_43 , void * V_79 )
{
struct V_23 * V_13 = V_79 ;
struct V_5 * V_6 = V_43 -> V_6 ;
F_32 ( & V_6 -> V_77 ) ;
F_28 ( V_6 , & V_13 -> V_33 [ 0 ] ) ;
if ( V_13 -> V_27 == 2 )
F_28 ( V_6 , & V_13 -> V_33 [ 1 ] ) ;
F_21 ( V_6 , V_13 ) ;
F_35 ( & V_6 -> V_77 ) ;
}
static void
F_37 ( struct V_42 * V_43 , void * V_79 ,
unsigned long V_35 , unsigned long V_36 ,
unsigned long * V_44 , unsigned long * V_45 )
{
struct V_23 * V_13 = V_79 ;
struct V_5 * V_6 = V_43 -> V_6 ;
F_32 ( & V_6 -> V_77 ) ;
F_22 ( V_6 , V_13 , V_35 , V_36 ) ;
F_23 ( V_43 , V_13 , V_44 , V_45 ) ;
F_35 ( & V_6 -> V_77 ) ;
}
static int F_38 ( struct V_80 * V_76 )
{
struct V_73 * V_74 = F_39 ( V_76 ) ;
struct V_5 * V_6 = F_40 ( V_74 ) ;
unsigned int V_81 , V_82 ;
for ( V_81 = 0 ; V_81 < V_83 ; V_81 ++ )
V_6 -> V_84 [ V_81 ] = F_7 ( V_6 -> V_1 , V_85 [ V_81 ] ) ;
for ( V_81 = 0 ; V_81 < 32 ; V_81 ++ ) {
if ( ! F_41 ( V_81 , & V_6 -> V_11 ) )
continue;
for ( V_82 = 0 ; V_82 < V_86 ; V_82 ++ ) {
V_6 -> V_14 [ V_81 ] . V_84 [ V_82 ] =
F_4 ( V_6 -> V_1 , V_81 , V_87 [ V_82 ] ) ;
if ( V_87 [ V_82 ] == V_63 )
V_6 -> V_14 [ V_81 ] . V_84 [ V_82 ] |=
V_69 | V_70 | V_71 ;
}
}
return 0 ;
}
static int F_42 ( struct V_80 * V_76 )
{
struct V_73 * V_74 = F_39 ( V_76 ) ;
struct V_5 * V_6 = F_40 ( V_74 ) ;
unsigned int V_81 , V_82 ;
for ( V_81 = 0 ; V_81 < 32 ; V_81 ++ ) {
if ( ! F_41 ( V_81 , & V_6 -> V_11 ) )
continue;
for ( V_82 = 0 ; V_82 < V_86 ; V_82 ++ )
F_1 ( V_6 -> V_1 , V_81 , V_87 [ V_82 ] ,
V_6 -> V_14 [ V_81 ] . V_84 [ V_82 ] ) ;
}
for ( V_81 = 0 ; V_81 < V_83 ; V_81 ++ )
F_6 ( V_6 -> V_1 , V_85 [ V_81 ] , V_6 -> V_84 [ V_81 ] ) ;
return 0 ;
}
static int T_3 F_43 ( struct V_73 * V_74 )
{
struct V_5 * V_6 ;
struct V_42 * V_43 = V_74 -> V_76 . V_88 ;
struct V_89 * V_84 ;
struct V_89 * V_19 ;
unsigned int V_81 ;
int error ;
if ( ! V_43 ) {
F_31 ( & V_74 -> V_76 , L_6 ) ;
return - V_31 ;
}
V_84 = F_44 ( V_74 , V_90 , 0 ) ;
V_19 = F_44 ( V_74 , V_90 , 1 ) ;
if ( V_84 == NULL || V_19 == NULL ) {
F_31 ( & V_74 -> V_76 , L_7 ) ;
return - V_91 ;
}
V_6 = F_19 ( sizeof( * V_6 ) , V_32 ) ;
if ( ! V_6 ) {
F_31 ( & V_74 -> V_76 , L_8 ) ;
return - V_12 ;
}
F_45 ( & V_6 -> V_77 ) ;
V_6 -> V_11 = V_43 -> V_92 ;
for ( V_81 = 0 ; V_81 < V_93 ; ++ V_81 )
V_6 -> V_14 [ V_81 ] . V_17 = V_81 ;
V_43 -> V_94 = & V_95 ;
V_43 -> V_6 = V_6 ;
V_43 -> V_74 = V_74 ;
if ( ! F_46 ( V_84 -> V_96 , F_47 ( V_84 ) , V_74 -> V_97 ) ) {
F_31 ( & V_74 -> V_76 , L_9 ) ;
error = - V_98 ;
goto V_99;
}
if ( ! F_46 ( V_19 -> V_96 , F_47 ( V_19 ) ,
V_74 -> V_97 ) ) {
F_31 ( & V_74 -> V_76 , L_10 ) ;
error = - V_98 ;
goto V_100;
}
V_6 -> V_1 = F_48 ( V_84 -> V_96 , F_47 ( V_84 ) ) ;
if ( ! V_6 -> V_1 ) {
F_31 ( & V_74 -> V_76 , L_11 ) ;
error = - V_101 ;
goto V_102;
}
V_6 -> V_19 = V_19 -> V_96 ;
V_6 -> V_16 = F_49 ( F_50 ( V_103 ) , - 1 ) ;
if ( V_6 -> V_16 == NULL ) {
error = - V_12 ;
goto V_104;
}
error = F_51 ( V_6 -> V_16 , V_19 -> V_96 , F_47 ( V_19 ) ,
- 1 ) ;
if ( error < 0 )
goto V_104;
if ( V_43 -> V_47 == V_105 )
F_6 ( V_6 -> V_1 , V_106 , V_107 ) ;
F_52 ( V_74 , V_6 ) ;
F_53 ( & V_74 -> V_76 ) ;
F_54 ( & V_74 -> V_76 , L_12 ) ;
return 0 ;
V_104:
if ( V_6 -> V_16 )
F_55 ( V_6 -> V_16 ) ;
F_56 ( V_6 -> V_1 ) ;
V_102:
F_57 ( V_19 -> V_96 , F_47 ( V_19 ) ) ;
V_100:
F_57 ( V_84 -> V_96 , F_47 ( V_84 ) ) ;
V_99:
F_58 ( & V_6 -> V_77 ) ;
F_20 ( V_6 ) ;
return error ;
}
static int F_59 ( struct V_73 * V_74 )
{
struct V_5 * V_6 = F_40 ( V_74 ) ;
struct V_89 * V_84 = F_44 ( V_74 , V_90 , 0 ) ;
struct V_89 * V_19 = F_44 ( V_74 , V_90 , 1 ) ;
F_60 ( & V_74 -> V_76 ) ;
F_55 ( V_6 -> V_16 ) ;
F_56 ( V_6 -> V_1 ) ;
F_57 ( V_19 -> V_96 , F_47 ( V_19 ) ) ;
F_57 ( V_84 -> V_96 , F_47 ( V_84 ) ) ;
F_58 ( & V_6 -> V_77 ) ;
F_20 ( V_6 ) ;
return 0 ;
}
