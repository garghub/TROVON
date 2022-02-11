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
static unsigned long F_8 ( struct V_5 * V_6 , T_2 V_7 )
{
return F_9 ( V_6 -> V_8 , V_7 ) ;
}
static void F_10 ( struct V_5 * V_6 , unsigned long V_9 ,
T_2 V_7 )
{
F_11 ( V_6 -> V_8 , V_9 , V_7 ) ;
}
static int F_12 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
T_2 V_7 )
{
unsigned long V_9 ;
unsigned long V_2 ;
V_2 = F_13 ( & V_6 -> V_12 , 28 ) ;
if ( V_2 == 28 )
return - V_13 ;
V_11 -> V_14 = & V_6 -> V_15 [ V_2 ] ;
V_2 = F_14 ( & V_6 -> V_12 , 32 , 28 ) ;
if ( V_2 == 32 )
return - V_13 ;
V_11 -> V_16 = & V_6 -> V_15 [ V_2 ] ;
V_9 = F_8 ( V_6 , V_7 * 1024 ) ;
if ( V_9 == 0 )
return - V_13 ;
F_15 ( V_11 -> V_16 -> V_17 , & V_6 -> V_12 ) ;
F_15 ( V_11 -> V_14 -> V_17 , & V_6 -> V_12 ) ;
V_11 -> V_16 -> V_18 = V_9 - V_6 -> V_19 ;
V_11 -> V_16 -> V_7 = V_7 ;
return 0 ;
}
static void F_16 ( struct V_5 * V_6 ,
struct V_10 * V_11 )
{
F_10 ( V_6 , V_6 -> V_19 + V_11 -> V_16 -> V_18 ,
V_11 -> V_16 -> V_7 * 1024 ) ;
F_17 ( V_11 -> V_16 -> V_17 , & V_6 -> V_12 ) ;
F_17 ( V_11 -> V_14 -> V_17 , & V_6 -> V_12 ) ;
}
static int F_18 ( int V_20 )
{
if ( V_20 == V_21 ||
V_20 == V_22 )
return 1 ;
return 0 ;
}
static void F_19 ( struct V_5 * V_6 ,
struct V_23 * V_14 ,
unsigned long V_24 ,
unsigned long V_25 )
{
struct V_26 * V_27 = V_14 -> V_28 [ 0 ] . V_16 ;
unsigned long V_29 ;
V_27 -> V_30 ^= 1 ;
V_29 = V_27 -> V_30 ? V_31 : V_32 ;
F_1 ( V_6 -> V_1 , V_14 -> V_28 [ 0 ] . V_14 -> V_17 , V_29 ,
V_24 ) ;
F_1 ( V_6 -> V_1 , V_14 -> V_28 [ 0 ] . V_16 -> V_17 , V_29 ,
V_24 + V_14 -> V_28 [ 0 ] . V_16 -> V_33 ) ;
if ( V_14 -> V_34 == 2 ) {
F_1 ( V_6 -> V_1 , V_14 -> V_28 [ 1 ] . V_14 -> V_17 ,
V_29 , V_25 ) ;
F_1 ( V_6 -> V_1 , V_14 -> V_28 [ 1 ] . V_16 -> V_17 ,
V_29 , V_25 +
V_14 -> V_28 [ 1 ] . V_16 -> V_33 ) ;
}
}
static void
F_20 ( struct V_35 * V_36 ,
struct V_23 * V_14 ,
unsigned long * V_37 , unsigned long * V_38 )
{
struct V_26 * V_27 = V_14 -> V_28 [ 0 ] . V_16 ;
unsigned long V_39 ;
if ( V_36 -> V_40 == V_41 )
V_39 = 0x80000000 | ( V_27 -> V_30 << 29 ) ;
else
V_39 = 0xc0000000 | ( V_27 -> V_30 << 23 ) ;
* V_37 = V_39 | ( V_14 -> V_28 [ 0 ] . V_16 -> V_17 << 24 ) ;
if ( V_14 -> V_34 == 2 )
* V_38 = V_39
| ( V_14 -> V_28 [ 1 ] . V_16 -> V_17 << 24 ) ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
unsigned int V_42 , unsigned int V_43 ,
unsigned int * V_44 )
{
struct V_26 * V_16 = V_11 -> V_16 ;
unsigned long V_45 = F_22 ( V_42 , V_43 ) ;
unsigned long V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
V_47 = ( V_42 - 1 ) | 1023 ;
V_47 = V_47 | ( V_47 >> 1 ) ;
V_47 = V_47 | ( V_47 >> 2 ) ;
V_47 += 1 ;
if ( V_47 == 8192 && V_43 >= 1024 ) {
V_47 = V_48 = V_51 ;
V_49 = V_45 >> 11 ;
* V_44 = V_42 ;
V_50 = V_11 -> V_16 -> V_7 / 16 / V_52 ;
V_50 *= V_52 ;
} else {
V_48 = V_42 ;
V_49 = V_43 ;
* V_44 = V_47 ;
V_50 = V_11 -> V_16 -> V_7 / ( V_47 >> 10 ) / 2 ;
V_50 &= 0xff ;
}
V_46 = ( V_50 - 1 ) << 16 ;
F_1 ( V_6 -> V_1 , V_11 -> V_14 -> V_17 , V_53 ,
F_23 ( 0x0 , V_49 - 1 , V_48 - 1 ) ) ;
F_1 ( V_6 -> V_1 , V_11 -> V_16 -> V_17 , V_53 ,
F_23 ( 0xf , V_49 - 1 , V_48 - 1 ) ) ;
F_1 ( V_6 -> V_1 , V_11 -> V_14 -> V_17 , V_54 , V_46 ) ;
F_1 ( V_6 -> V_1 , V_11 -> V_16 -> V_17 , V_54 , V_46 ) ;
F_1 ( V_6 -> V_1 , V_11 -> V_14 -> V_17 , V_55 , V_48 ) ;
F_1 ( V_6 -> V_1 , V_11 -> V_16 -> V_17 , V_55 , V_48 ) ;
V_11 -> V_14 -> V_33 = V_42 * V_50 ;
V_11 -> V_16 -> V_33 = V_42 * V_50 ;
F_1 ( V_6 -> V_1 , V_11 -> V_14 -> V_17 , V_56 ,
F_24 ( V_11 -> V_16 -> V_17 , V_16 -> V_18 )
| V_57 | V_58 | V_59 | V_60 |
V_61 ) ;
F_1 ( V_6 -> V_1 , V_11 -> V_16 -> V_17 , V_56 ,
F_24 ( V_11 -> V_14 -> V_17 , V_16 -> V_18 +
V_11 -> V_16 -> V_7 / 2 ) |
V_57 | V_58 | V_59 | V_60 |
V_61 ) ;
return 0 ;
}
static void F_25 ( struct V_5 * V_6 ,
struct V_10 * V_11 )
{
F_1 ( V_6 -> V_1 , V_11 -> V_14 -> V_17 , V_56 ,
V_62 | V_63 | V_64 ) ;
F_1 ( V_6 -> V_1 , V_11 -> V_16 -> V_17 , V_56 ,
V_62 | V_63 | V_64 ) ;
V_11 -> V_14 -> V_33 = 0 ;
V_11 -> V_16 -> V_33 = 0 ;
}
unsigned long F_26 ( struct V_35 * V_36 ,
T_2 V_7 )
{
struct V_5 * V_6 = V_36 -> V_6 ;
return F_8 ( V_6 , V_7 ) ;
}
void F_27 ( struct V_35 * V_36 , unsigned long V_9 ,
T_2 V_7 )
{
struct V_5 * V_6 = V_36 -> V_6 ;
F_10 ( V_6 , V_9 , V_7 ) ;
}
static struct V_23 *
F_28 ( struct V_5 * V_6 ,
const struct V_65 * V_66 ,
int V_67 )
{
unsigned int V_34 = F_18 ( V_67 ) ? 2 : 1 ;
struct V_23 * V_14 ;
int V_68 ;
V_14 = F_29 ( sizeof( * V_14 ) , V_69 ) ;
if ( V_14 == NULL )
return F_30 ( - V_13 ) ;
V_14 -> V_34 = V_34 ;
V_68 = F_12 ( V_6 , & V_14 -> V_28 [ 0 ] ,
V_66 -> V_27 [ 0 ] . V_70 ) ;
if ( V_68 < 0 )
goto error;
V_14 -> V_28 [ 0 ] . V_16 -> V_30 = 1 ;
V_14 -> V_28 [ 0 ] . V_16 -> V_67 = V_67 ;
if ( V_14 -> V_34 == 1 )
return V_14 ;
V_68 = F_12 ( V_6 , & V_14 -> V_28 [ 1 ] ,
V_66 -> V_27 [ 1 ] . V_70 ) ;
if ( V_68 < 0 ) {
F_16 ( V_6 , & V_14 -> V_28 [ 0 ] ) ;
goto error;
}
return V_14 ;
error:
F_31 ( V_14 ) ;
return F_30 ( - V_13 ) ;
}
void * F_32 ( struct V_35 * V_36 ,
const struct V_65 * V_66 ,
unsigned int V_42 , unsigned int V_43 ,
unsigned int V_67 , unsigned int * V_71 )
{
struct V_23 * V_14 ;
struct V_5 * V_6 = V_36 -> V_6 ;
struct V_72 * V_73 = V_36 -> V_73 ;
unsigned int V_34 = F_18 ( V_67 ) ? 2 : 1 ;
unsigned int V_44 ;
if ( V_6 == NULL )
return F_30 ( - V_74 ) ;
if ( V_67 != V_21 &&
V_67 != V_22 &&
V_67 != V_75 )
return F_30 ( - V_76 ) ;
F_33 ( & V_73 -> V_77 , L_1 , V_42 , V_43 ,
! V_67 ? L_2 : L_3 ) ;
if ( V_42 > 8192 ) {
F_34 ( & V_73 -> V_77 , L_4 ) ;
return F_30 ( - V_76 ) ;
}
if ( V_66 -> V_27 [ 0 ] . V_70 == 0 )
return F_30 ( - V_76 ) ;
if ( V_34 == 2 && V_66 -> V_27 [ 1 ] . V_70 == 0 )
return F_30 ( - V_76 ) ;
F_35 ( & V_6 -> V_78 ) ;
V_14 = F_28 ( V_6 , V_66 , V_67 ) ;
if ( F_36 ( V_14 ) ) {
F_34 ( & V_73 -> V_77 , L_5 ,
F_37 ( V_14 ) ) ;
goto V_79;
}
F_21 ( V_6 , & V_14 -> V_28 [ 0 ] , V_42 , V_43 , & V_44 ) ;
* V_71 = V_44 ;
if ( V_67 == V_21 )
F_21 ( V_6 , & V_14 -> V_28 [ 1 ] ,
V_42 , ( V_43 + 1 ) / 2 , & V_44 ) ;
else if ( V_67 == V_22 )
F_21 ( V_6 , & V_14 -> V_28 [ 1 ] ,
2 * V_42 , ( V_43 + 1 ) / 2 , & V_44 ) ;
V_79:
F_38 ( & V_6 -> V_78 ) ;
return V_14 ;
}
void
F_39 ( struct V_35 * V_36 , void * V_80 )
{
struct V_23 * V_14 = V_80 ;
struct V_5 * V_6 = V_36 -> V_6 ;
F_35 ( & V_6 -> V_78 ) ;
F_25 ( V_6 , & V_14 -> V_28 [ 0 ] ) ;
F_16 ( V_6 , & V_14 -> V_28 [ 0 ] ) ;
if ( V_14 -> V_34 == 2 ) {
F_25 ( V_6 , & V_14 -> V_28 [ 1 ] ) ;
F_16 ( V_6 , & V_14 -> V_28 [ 1 ] ) ;
}
F_31 ( V_14 ) ;
F_38 ( & V_6 -> V_78 ) ;
}
void
F_40 ( struct V_35 * V_36 , void * V_80 ,
unsigned long V_24 ,
unsigned long V_25 ,
unsigned long * V_37 ,
unsigned long * V_38 )
{
struct V_23 * V_14 = V_80 ;
struct V_5 * V_6 = V_36 -> V_6 ;
F_35 ( & V_6 -> V_78 ) ;
F_19 ( V_6 , V_14 , V_24 , V_25 ) ;
F_20 ( V_36 , V_14 , V_37 , V_38 ) ;
F_38 ( & V_6 -> V_78 ) ;
}
static int F_41 ( struct V_81 * V_77 )
{
struct V_72 * V_73 = F_42 ( V_77 ) ;
struct V_5 * V_6 = F_43 ( V_73 ) ;
unsigned int V_82 , V_83 ;
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ )
V_6 -> V_85 [ V_82 ] = F_7 ( V_6 -> V_1 , V_86 [ V_82 ] ) ;
for ( V_82 = 0 ; V_82 < 32 ; V_82 ++ ) {
if ( ! F_44 ( V_82 , & V_6 -> V_12 ) )
continue;
for ( V_83 = 0 ; V_83 < V_87 ; V_83 ++ ) {
V_6 -> V_15 [ V_82 ] . V_85 [ V_83 ] =
F_4 ( V_6 -> V_1 , V_82 , V_88 [ V_83 ] ) ;
if ( V_88 [ V_83 ] == V_56 )
V_6 -> V_15 [ V_82 ] . V_85 [ V_83 ] |=
V_62 | V_63 | V_64 ;
}
}
return 0 ;
}
static int F_45 ( struct V_81 * V_77 )
{
struct V_72 * V_73 = F_42 ( V_77 ) ;
struct V_5 * V_6 = F_43 ( V_73 ) ;
unsigned int V_82 , V_83 ;
for ( V_82 = 0 ; V_82 < 32 ; V_82 ++ ) {
if ( ! F_44 ( V_82 , & V_6 -> V_12 ) )
continue;
for ( V_83 = 0 ; V_83 < V_87 ; V_83 ++ )
F_1 ( V_6 -> V_1 , V_82 , V_88 [ V_83 ] ,
V_6 -> V_15 [ V_82 ] . V_85 [ V_83 ] ) ;
}
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ )
F_6 ( V_6 -> V_1 , V_86 [ V_82 ] , V_6 -> V_85 [ V_82 ] ) ;
return 0 ;
}
static int F_46 ( struct V_72 * V_73 )
{
struct V_5 * V_6 ;
struct V_35 * V_36 = V_73 -> V_77 . V_89 ;
struct V_90 * V_85 ;
struct V_90 * V_19 ;
unsigned int V_82 ;
int error ;
if ( ! V_36 ) {
F_34 ( & V_73 -> V_77 , L_6 ) ;
return - V_76 ;
}
V_85 = F_47 ( V_73 , V_91 , 0 ) ;
V_19 = F_47 ( V_73 , V_91 , 1 ) ;
if ( V_85 == NULL || V_19 == NULL ) {
F_34 ( & V_73 -> V_77 , L_7 ) ;
return - V_92 ;
}
V_6 = F_29 ( sizeof( * V_6 ) , V_69 ) ;
if ( ! V_6 ) {
F_34 ( & V_73 -> V_77 , L_8 ) ;
return - V_13 ;
}
F_48 ( & V_6 -> V_78 ) ;
V_6 -> V_12 = V_36 -> V_93 ;
for ( V_82 = 0 ; V_82 < V_94 ; ++ V_82 )
V_6 -> V_15 [ V_82 ] . V_17 = V_82 ;
V_36 -> V_6 = V_6 ;
V_36 -> V_73 = V_73 ;
if ( ! F_49 ( V_85 -> V_95 , F_50 ( V_85 ) , V_73 -> V_96 ) ) {
F_34 ( & V_73 -> V_77 , L_9 ) ;
error = - V_97 ;
goto V_98;
}
if ( ! F_49 ( V_19 -> V_95 , F_50 ( V_19 ) ,
V_73 -> V_96 ) ) {
F_34 ( & V_73 -> V_77 , L_10 ) ;
error = - V_97 ;
goto V_99;
}
V_6 -> V_1 = F_51 ( V_85 -> V_95 , F_50 ( V_85 ) ) ;
if ( ! V_6 -> V_1 ) {
F_34 ( & V_73 -> V_77 , L_11 ) ;
error = - V_100 ;
goto V_101;
}
V_6 -> V_19 = V_19 -> V_95 ;
V_6 -> V_8 = F_52 ( F_53 ( V_102 ) , - 1 ) ;
if ( V_6 -> V_8 == NULL ) {
error = - V_13 ;
goto V_103;
}
error = F_54 ( V_6 -> V_8 , V_19 -> V_95 , F_50 ( V_19 ) ,
- 1 ) ;
if ( error < 0 )
goto V_103;
if ( V_36 -> V_40 == V_104 )
F_6 ( V_6 -> V_1 , V_105 , V_106 ) ;
F_55 ( V_73 , V_6 ) ;
F_56 ( & V_73 -> V_77 ) ;
F_57 ( & V_73 -> V_77 , L_12 ) ;
return 0 ;
V_103:
if ( V_6 -> V_8 )
F_58 ( V_6 -> V_8 ) ;
F_59 ( V_6 -> V_1 ) ;
V_101:
F_60 ( V_19 -> V_95 , F_50 ( V_19 ) ) ;
V_99:
F_60 ( V_85 -> V_95 , F_50 ( V_85 ) ) ;
V_98:
F_61 ( & V_6 -> V_78 ) ;
F_31 ( V_6 ) ;
return error ;
}
static int F_62 ( struct V_72 * V_73 )
{
struct V_5 * V_6 = F_43 ( V_73 ) ;
struct V_90 * V_85 = F_47 ( V_73 , V_91 , 0 ) ;
struct V_90 * V_19 = F_47 ( V_73 , V_91 , 1 ) ;
F_63 ( & V_73 -> V_77 ) ;
F_58 ( V_6 -> V_8 ) ;
F_59 ( V_6 -> V_1 ) ;
F_60 ( V_19 -> V_95 , F_50 ( V_19 ) ) ;
F_60 ( V_85 -> V_95 , F_50 ( V_85 ) ) ;
F_61 ( & V_6 -> V_78 ) ;
F_31 ( V_6 ) ;
return 0 ;
}
