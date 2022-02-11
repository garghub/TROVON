static inline T_1 F_1 ( void T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
static inline void F_3 ( T_1 V_2 , void T_2 * V_1 )
{
F_4 ( V_2 , V_1 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_6 ( V_4 ) ;
T_1 V_2 ;
V_2 = F_1 ( V_6 -> V_7 + V_6 -> V_8 ) ;
F_7 ( L_1 , F_8 ( V_4 ) ,
V_2 & V_9 ? L_2 : L_3 ) ;
return V_2 & V_9 ? 0 : 1 ;
}
static unsigned long F_9 ( struct V_3 * V_4 ,
unsigned long V_10 )
{
struct V_5 * V_6 = F_6 ( V_4 ) ;
unsigned long V_11 ;
unsigned long V_12 ;
T_1 V_13 ;
T_1 V_14 ;
T_1 V_15 ;
T_1 V_16 ;
V_13 = F_1 ( V_6 -> V_7 + V_6 -> V_8 ) ;
if ( V_6 -> V_17 <= 1 ) {
if ( V_6 -> type == V_18 ) {
V_15 = 2 ;
V_12 = V_10 * ( F_10 ( V_13 ) + 4 ) ;
} else {
V_14 = F_11 ( V_13 ) + 1 ;
V_15 = F_12 ( V_13 ) + 1 ;
V_16 = F_13 ( V_13 ) ;
V_11 = V_10 / V_14 ;
V_12 = V_11 * V_16 ;
}
} else {
V_15 = F_14 ( V_13 ) ? 2 : 3 ;
V_12 = V_10 * F_15 ( V_13 ) ;
}
F_7 ( L_4 ,
F_8 ( V_4 ) , V_12 / V_15 , V_10 ,
V_6 -> V_17 ) ;
return V_12 / V_15 ;
}
static struct V_19 * F_16 ( struct V_20 * V_21 ,
const char * V_22 , const char * V_23 ,
unsigned long V_24 , void T_2 * V_7 , T_1 V_8 ,
T_1 type , T_3 * V_25 , int V_17 )
{
struct V_5 * V_26 ;
struct V_19 * V_19 ;
struct V_27 V_28 ;
V_26 = F_17 ( sizeof( * V_26 ) , V_29 ) ;
if ( ! V_26 ) {
F_18 ( L_5 , V_30 ) ;
return F_19 ( - V_31 ) ;
}
V_28 . V_22 = V_22 ;
V_28 . V_32 = & V_33 ;
V_28 . V_24 = V_24 ;
V_28 . V_34 = V_23 ? & V_23 : NULL ;
V_28 . V_35 = V_23 ? 1 : 0 ;
V_26 -> V_17 = V_17 ;
V_26 -> V_7 = V_7 ;
V_26 -> V_25 = V_25 ;
V_26 -> V_8 = V_8 ;
V_26 -> type = type ;
V_26 -> V_4 . V_28 = & V_28 ;
V_19 = F_20 ( V_21 , & V_26 -> V_4 ) ;
if ( F_21 ( V_19 ) ) {
F_18 ( L_6 , V_30 , V_22 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
return V_19 ;
}
static int F_23 ( struct V_36 * V_37 )
{
if ( F_24 ( V_37 , L_7 ) )
return 1 ;
if ( F_24 ( V_37 , L_8 ) )
return 1 ;
return 2 ;
}
static void F_25 ( struct V_36 * V_37 , enum V_38 V_39 )
{
const char * V_40 = V_37 -> V_41 ;
struct V_19 * V_19 ;
void T_2 * V_7 ;
int V_17 = F_23 ( V_37 ) ;
V_7 = F_26 ( V_37 , 0 ) ;
if ( V_7 == NULL ) {
F_18 ( L_9 , V_37 -> V_41 ) ;
return;
}
F_27 ( V_37 , L_10 , & V_40 ) ;
V_19 = F_16 ( NULL ,
V_40 , F_28 ( V_37 , 0 ) ,
0 , V_7 , 0 , V_39 , & V_42 ,
V_17 ) ;
if ( ! F_21 ( V_19 ) ) {
F_29 ( V_37 , V_43 , V_19 ) ;
F_30 ( V_19 , V_40 , NULL ) ;
F_7 ( L_11 , V_40 ) ;
}
}
static void F_31 ( struct V_36 * V_37 )
{
F_25 ( V_37 , V_44 ) ;
}
static void F_32 ( struct V_36 * V_37 )
{
F_25 ( V_37 , V_18 ) ;
}
static unsigned long F_33 ( struct V_3 * V_4 ,
unsigned long V_10 )
{
struct V_45 * V_46 = F_34 ( V_4 ) ;
unsigned long V_24 = 0 ;
T_4 V_47 , V_48 ;
T_1 V_49 ;
if ( V_46 -> V_25 )
F_35 ( V_46 -> V_25 , V_24 ) ;
else
F_36 ( V_46 -> V_25 ) ;
V_49 = F_37 ( V_46 -> V_7 ) ;
if ( V_46 -> V_25 )
F_38 ( V_46 -> V_25 , V_24 ) ;
else
F_39 ( V_46 -> V_25 ) ;
V_47 = ( T_4 ) V_10 ;
V_48 = ( V_49 & V_46 -> V_50 ) >> V_46 -> V_51 ;
if ( V_46 -> V_24 & V_52 )
V_48 = V_46 -> V_53 - V_48 ;
else
V_48 ++ ;
F_40 ( V_47 , V_46 -> V_53 ) ;
V_47 *= V_48 ;
if ( V_47 == 0 )
V_47 = ( T_4 ) V_10 ;
return V_47 ;
}
static long F_41 ( struct V_3 * V_4 , unsigned long V_54 ,
unsigned long * V_10 )
{
struct V_45 * V_46 = F_34 ( V_4 ) ;
T_4 V_47 , V_48 ;
if ( ! V_54 || V_54 >= * V_10 )
return * V_10 ;
V_47 = V_54 * V_46 -> V_53 ;
V_48 = F_42 ( V_47 , * V_10 ) ;
V_47 = ( T_4 ) * V_10 * V_48 ;
F_40 ( V_47 , V_46 -> V_53 ) ;
return V_47 ;
}
static int F_43 ( struct V_3 * V_4 , unsigned long V_54 ,
unsigned long V_10 )
{
struct V_45 * V_46 = F_34 ( V_4 ) ;
unsigned long V_24 = 0 ;
T_4 V_48 , V_47 ;
T_1 V_49 ;
V_47 = V_54 * V_46 -> V_53 ;
V_48 = F_42 ( V_47 , ( T_4 ) V_10 ) ;
if ( V_46 -> V_24 & V_52 )
V_48 = V_46 -> V_53 - V_48 ;
else
V_48 -- ;
if ( V_46 -> V_25 )
F_35 ( V_46 -> V_25 , V_24 ) ;
else
F_36 ( V_46 -> V_25 ) ;
V_49 = F_37 ( V_46 -> V_7 ) ;
V_49 &= ~ V_46 -> V_50 ;
V_49 |= ( V_48 << V_46 -> V_51 ) ;
F_44 ( V_49 , V_46 -> V_7 ) ;
if ( V_46 -> V_25 )
F_38 ( V_46 -> V_25 , V_24 ) ;
else
F_39 ( V_46 -> V_25 ) ;
return 0 ;
}
static struct V_19 *
F_45 ( struct V_20 * V_21 ,
const char * V_22 , const char * V_23 ,
unsigned long V_24 , void T_2 * V_7 , T_5 V_51 ,
T_5 V_55 , T_4 V_53 , T_1 V_56 , T_3 * V_25 )
{
struct V_45 * V_46 ;
struct V_27 V_28 ;
struct V_19 * V_19 ;
V_46 = F_17 ( sizeof( * V_46 ) , V_29 ) ;
if ( ! V_46 )
return F_19 ( - V_31 ) ;
V_28 . V_22 = V_22 ;
V_28 . V_32 = & V_57 ;
V_28 . V_24 = V_24 ;
V_28 . V_34 = V_23 ? & V_23 : NULL ;
V_28 . V_35 = V_23 ? 1 : 0 ;
V_46 -> V_7 = V_7 ;
V_46 -> V_51 = V_51 ;
V_46 -> V_50 = ( F_46 ( V_55 ) - 1 ) << V_51 ;
V_46 -> V_53 = V_53 ;
V_46 -> V_24 = V_56 ;
V_46 -> V_25 = V_25 ;
V_46 -> V_4 . V_28 = & V_28 ;
V_19 = F_20 ( V_21 , & V_46 -> V_4 ) ;
if ( F_21 ( V_19 ) ) {
F_18 ( L_6 , V_30 , V_22 ) ;
F_22 ( V_46 ) ;
return NULL ;
}
return V_19 ;
}
static void F_47 ( struct V_36 * V_37 )
{
const char * V_40 = V_37 -> V_41 ;
void T_2 * V_58 ;
struct V_59 V_60 ;
struct V_19 * V_19 ;
T_4 V_53 ;
T_1 V_24 = 0 ;
int V_61 ;
if ( ! F_48 ( V_37 ) )
return;
V_61 = F_49 ( V_37 , 0 , & V_60 ) ;
if ( V_61 != 0 ) {
F_18 ( L_12 , V_37 -> V_41 ) ;
return;
}
V_58 = F_26 ( V_37 , 0 ) ;
if ( ! V_58 ) {
F_18 ( L_13 , V_37 -> V_41 ) ;
return;
}
F_27 ( V_37 , L_10 , & V_40 ) ;
V_53 = F_46 ( V_62 ) ;
V_24 |= V_52 ;
V_19 = F_45 ( NULL , V_40 ,
F_28 ( V_37 , 0 ) , 0 ,
V_58 , V_63 ,
V_62 , V_53 ,
V_24 , & V_42 ) ;
if ( ! F_21 ( V_19 ) ) {
F_29 ( V_37 , V_43 , V_19 ) ;
F_30 ( V_19 , V_40 , NULL ) ;
F_7 ( L_14 , V_40 ) ;
} else {
if ( V_58 )
F_50 ( V_58 ) ;
}
}
static int F_51 ( struct V_3 * V_4 )
{
struct V_64 * V_65 = F_52 ( V_4 ) ;
unsigned long V_24 = 0 ;
T_1 V_2 ;
if ( V_65 -> V_25 )
F_35 ( V_65 -> V_25 , V_24 ) ;
if ( V_65 -> V_66 . V_58 != NULL ) {
F_7 ( L_15 , F_8 ( V_4 ) ) ;
V_2 = F_1 ( V_65 -> V_66 . V_58 +
V_65 -> V_66 . V_67 ) ;
V_2 |= V_65 -> V_66 . V_68 ;
F_3 ( V_2 , V_65 -> V_66 . V_58 +
V_65 -> V_66 . V_67 ) ;
F_7 ( L_16 ,
F_8 ( V_4 ) ,
V_65 -> V_66 . V_67 , V_65 -> V_66 . V_68 ,
V_2 ) ;
V_2 = F_1 ( V_65 -> V_66 . V_58 +
V_65 -> V_66 . V_69 ) ;
V_2 &= ~ V_65 -> V_66 . V_70 ;
F_3 ( V_2 , V_65 -> V_66 . V_58 +
V_65 -> V_66 . V_69 ) ;
F_7 ( L_17 ,
F_8 ( V_4 ) ,
V_65 -> V_66 . V_69 , V_65 -> V_66 . V_70 ,
V_2 ) ;
}
if ( V_65 -> V_25 )
F_38 ( V_65 -> V_25 , V_24 ) ;
return 0 ;
}
static void F_53 ( struct V_3 * V_4 )
{
struct V_64 * V_65 = F_52 ( V_4 ) ;
unsigned long V_24 = 0 ;
T_1 V_2 ;
if ( V_65 -> V_25 )
F_35 ( V_65 -> V_25 , V_24 ) ;
if ( V_65 -> V_66 . V_58 != NULL ) {
F_7 ( L_18 , F_8 ( V_4 ) ) ;
V_2 = F_1 ( V_65 -> V_66 . V_58 +
V_65 -> V_66 . V_69 ) ;
V_2 |= V_65 -> V_66 . V_70 ;
F_3 ( V_2 , V_65 -> V_66 . V_58 +
V_65 -> V_66 . V_69 ) ;
V_2 = F_1 ( V_65 -> V_66 . V_58 +
V_65 -> V_66 . V_67 ) ;
V_2 &= ~ V_65 -> V_66 . V_68 ;
F_3 ( V_2 , V_65 -> V_66 . V_58 +
V_65 -> V_66 . V_67 ) ;
}
if ( V_65 -> V_25 )
F_38 ( V_65 -> V_25 , V_24 ) ;
}
static int F_54 ( struct V_3 * V_4 )
{
struct V_64 * V_65 = F_52 ( V_4 ) ;
T_1 V_2 = 0 ;
if ( V_65 -> V_66 . V_58 != NULL ) {
F_7 ( L_19 , F_8 ( V_4 ) ) ;
V_2 = F_1 ( V_65 -> V_66 . V_58 +
V_65 -> V_66 . V_67 ) ;
F_7 ( L_20 , F_8 ( V_4 ) ,
V_2 & V_65 -> V_66 . V_68 ? L_3 :
L_2 ) ;
}
if ( V_65 -> V_66 . V_58 == NULL )
return 1 ;
return V_2 & V_65 -> V_66 . V_68 ? 1 : 0 ;
}
static unsigned long F_55 ( struct V_3 * V_4 ,
unsigned long V_10 )
{
struct V_64 * V_65 = F_52 ( V_4 ) ;
T_1 V_2 ;
if ( V_65 -> V_66 . V_71 ) {
V_2 = F_1 ( V_65 -> V_66 . V_71 +
V_65 -> V_66 . V_72 ) ;
V_2 >>= V_65 -> V_66 . V_73 ;
V_2 &= ( 1 << V_65 -> V_66 . V_74 ) - 1 ;
F_7 ( L_21 ,
F_8 ( V_4 ) ,
V_10 / V_2 , V_10 ) ;
return V_10 / V_2 ;
} else {
F_7 ( L_21 ,
F_8 ( V_4 ) , V_10 , V_10 ) ;
return V_10 ;
}
}
static int F_56 ( struct V_3 * V_4 , unsigned long V_54 ,
unsigned long V_10 )
{
struct V_64 * V_65 = F_52 ( V_4 ) ;
unsigned long V_24 = 0 ;
T_1 V_2 ;
T_1 V_75 ;
T_1 V_76 ;
if ( V_65 -> V_25 )
F_35 ( V_65 -> V_25 , V_24 ) ;
if ( V_65 -> V_66 . V_71 ) {
if ( V_54 > V_10 )
V_54 = V_10 ;
V_76 = V_75 = V_10 / V_54 ;
V_75 &= ( 1 << V_65 -> V_66 . V_74 ) - 1 ;
V_75 <<= V_65 -> V_66 . V_73 ;
V_2 = F_1 ( V_65 -> V_66 . V_71 +
V_65 -> V_66 . V_72 ) ;
V_2 &= ~ ( ( ( 1 << V_65 -> V_66 . V_74 ) - 1 )
<< V_65 -> V_66 . V_73 ) ;
V_2 |= V_75 ;
F_3 ( V_2 , V_65 -> V_66 . V_71 +
V_65 -> V_66 . V_72 ) ;
F_7 ( L_22 , F_8 ( V_4 ) ,
V_10 / V_76 ) ;
} else {
V_76 = 1 ;
}
if ( V_65 -> V_25 )
F_38 ( V_65 -> V_25 , V_24 ) ;
return V_10 / V_76 ;
}
static long F_57 ( struct V_3 * V_4 , unsigned long V_54 ,
unsigned long * V_77 )
{
struct V_64 * V_65 = F_52 ( V_4 ) ;
unsigned long V_10 = * V_77 ;
T_1 V_75 ;
if ( V_65 -> V_66 . V_71 ) {
if ( V_54 > V_10 )
V_54 = V_10 ;
V_75 = V_10 / V_54 ;
} else {
V_75 = 1 ;
}
return V_10 / V_75 ;
}
static struct V_19 * F_58 ( struct V_20 * V_21 ,
const char * V_22 , const char * V_23 ,
struct V_78 * V_79 , T_3 * V_25 )
{
struct V_64 * V_26 ;
struct V_19 * V_19 ;
struct V_27 V_28 ;
int V_61 ;
V_26 = F_17 ( sizeof( * V_26 ) , V_29 ) ;
if ( ! V_26 ) {
F_18 ( L_5 , V_30 ) ;
return F_19 ( - V_31 ) ;
}
V_28 . V_22 = V_22 ;
V_28 . V_32 = & V_80 ;
V_28 . V_24 = 0 ;
V_28 . V_34 = V_23 ? & V_23 : NULL ;
V_28 . V_35 = V_23 ? 1 : 0 ;
V_26 -> V_25 = V_25 ;
V_26 -> V_4 . V_28 = & V_28 ;
V_26 -> V_66 = * V_79 ;
V_19 = F_20 ( V_21 , & V_26 -> V_4 ) ;
if ( F_21 ( V_19 ) ) {
F_18 ( L_6 , V_30 , V_22 ) ;
F_22 ( V_26 ) ;
return V_19 ;
}
V_61 = F_30 ( V_19 , V_22 , NULL ) ;
if ( V_61 != 0 ) {
F_18 ( L_23 ,
V_30 , V_22 ) ;
}
return V_19 ;
}
static void T_6 F_59 ( struct V_36 * V_37 )
{
const char * V_40 = V_37 -> V_41 ;
struct V_19 * V_19 ;
struct V_59 V_60 ;
int V_61 ;
struct V_78 V_79 ;
int V_81 ;
if ( ! F_48 ( V_37 ) )
return;
V_79 . V_58 = NULL ;
V_79 . V_71 = NULL ;
for ( V_81 = 0 ; V_81 < 2 ; V_81 ++ ) {
void T_2 * V_82 ;
V_61 = F_49 ( V_37 , V_81 , & V_60 ) ;
if ( V_61 != 0 ) {
if ( V_81 == 0 ) {
F_18 ( L_12 ,
V_37 -> V_41 ) ;
return;
}
break;
}
V_82 = F_26 ( V_37 , V_81 ) ;
if ( V_82 == NULL ) {
F_18 ( L_24 ,
V_81 , V_37 -> V_41 ) ;
goto V_83;
}
if ( strcmp ( V_60 . V_22 , L_25 ) == 0 )
V_79 . V_71 = V_82 ;
else
V_79 . V_58 = V_82 ;
}
if ( F_60 ( V_37 , L_26 , & V_79 . V_69 ) )
V_79 . V_69 = 0 ;
if ( F_60 ( V_37 , L_27 , & V_79 . V_70 ) )
V_79 . V_70 = 0xF ;
if ( F_60 ( V_37 , L_28 ,
& V_79 . V_67 ) )
V_79 . V_67 = 0x8 ;
if ( F_60 ( V_37 , L_29 , & V_79 . V_68 ) )
V_79 . V_68 = 0xF ;
if ( F_60 ( V_37 , L_30 ,
& V_79 . V_72 ) )
V_79 . V_72 = 0 ;
if ( F_60 ( V_37 , L_31 ,
& V_79 . V_74 ) )
V_79 . V_74 = 0 ;
if ( F_60 ( V_37 , L_32 ,
& V_79 . V_73 ) )
V_79 . V_73 = 0 ;
F_27 ( V_37 , L_10 , & V_40 ) ;
V_19 = F_58 ( NULL , V_40 ,
F_28 ( V_37 , 0 ) , & V_79 , & V_42 ) ;
if ( F_21 ( V_19 ) )
goto V_83;
F_7 ( L_14 , V_40 ) ;
V_61 = F_29 ( V_37 , V_43 , V_19 ) ;
if ( V_61 != 0 )
F_18 ( L_33 , V_30 ,
V_37 -> V_41 ) ;
return;
V_83:
if ( V_79 . V_58 )
F_50 ( V_79 . V_58 ) ;
if ( V_79 . V_71 )
F_50 ( V_79 . V_71 ) ;
}
