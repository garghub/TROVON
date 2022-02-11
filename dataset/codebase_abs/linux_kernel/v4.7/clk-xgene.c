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
static int F_33 ( struct V_3 * V_4 )
{
struct V_45 * V_46 = F_34 ( V_4 ) ;
unsigned long V_24 = 0 ;
T_1 V_2 ;
T_4 V_7 ;
if ( V_46 -> V_25 )
F_35 ( V_46 -> V_25 , V_24 ) ;
if ( V_46 -> V_47 . V_48 != NULL ) {
F_7 ( L_12 , F_8 ( V_4 ) ) ;
V_7 = F_36 ( V_46 -> V_47 . V_48 ) ;
V_2 = F_1 ( V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_49 ) ;
V_2 |= V_46 -> V_47 . V_50 ;
F_3 ( V_2 , V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_49 ) ;
F_7 ( L_13 ,
F_8 ( V_4 ) , & V_7 ,
V_46 -> V_47 . V_49 , V_46 -> V_47 . V_50 ,
V_2 ) ;
V_2 = F_1 ( V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_51 ) ;
V_2 &= ~ V_46 -> V_47 . V_52 ;
F_3 ( V_2 , V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_51 ) ;
F_7 ( L_14 ,
F_8 ( V_4 ) , & V_7 ,
V_46 -> V_47 . V_51 , V_46 -> V_47 . V_52 ,
V_2 ) ;
}
if ( V_46 -> V_25 )
F_37 ( V_46 -> V_25 , V_24 ) ;
return 0 ;
}
static void F_38 ( struct V_3 * V_4 )
{
struct V_45 * V_46 = F_34 ( V_4 ) ;
unsigned long V_24 = 0 ;
T_1 V_2 ;
if ( V_46 -> V_25 )
F_35 ( V_46 -> V_25 , V_24 ) ;
if ( V_46 -> V_47 . V_48 != NULL ) {
F_7 ( L_15 , F_8 ( V_4 ) ) ;
V_2 = F_1 ( V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_51 ) ;
V_2 |= V_46 -> V_47 . V_52 ;
F_3 ( V_2 , V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_51 ) ;
V_2 = F_1 ( V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_49 ) ;
V_2 &= ~ V_46 -> V_47 . V_50 ;
F_3 ( V_2 , V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_49 ) ;
}
if ( V_46 -> V_25 )
F_37 ( V_46 -> V_25 , V_24 ) ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_45 * V_46 = F_34 ( V_4 ) ;
T_1 V_2 = 0 ;
if ( V_46 -> V_47 . V_48 != NULL ) {
F_7 ( L_16 , F_8 ( V_4 ) ) ;
V_2 = F_1 ( V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_49 ) ;
F_7 ( L_17 , F_8 ( V_4 ) ,
V_2 & V_46 -> V_47 . V_50 ? L_3 :
L_2 ) ;
}
if ( V_46 -> V_47 . V_48 == NULL )
return 1 ;
return V_2 & V_46 -> V_47 . V_50 ? 1 : 0 ;
}
static unsigned long F_40 ( struct V_3 * V_4 ,
unsigned long V_10 )
{
struct V_45 * V_46 = F_34 ( V_4 ) ;
T_1 V_2 ;
if ( V_46 -> V_47 . V_53 ) {
V_2 = F_1 ( V_46 -> V_47 . V_53 +
V_46 -> V_47 . V_54 ) ;
V_2 >>= V_46 -> V_47 . V_55 ;
V_2 &= ( 1 << V_46 -> V_47 . V_56 ) - 1 ;
F_7 ( L_18 ,
F_8 ( V_4 ) ,
V_10 / V_2 , V_10 ) ;
return V_10 / V_2 ;
} else {
F_7 ( L_18 ,
F_8 ( V_4 ) , V_10 , V_10 ) ;
return V_10 ;
}
}
static int F_41 ( struct V_3 * V_4 , unsigned long V_57 ,
unsigned long V_10 )
{
struct V_45 * V_46 = F_34 ( V_4 ) ;
unsigned long V_24 = 0 ;
T_1 V_2 ;
T_1 V_58 ;
T_1 V_59 ;
if ( V_46 -> V_25 )
F_35 ( V_46 -> V_25 , V_24 ) ;
if ( V_46 -> V_47 . V_53 ) {
if ( V_57 > V_10 )
V_57 = V_10 ;
V_59 = V_58 = V_10 / V_57 ;
V_58 &= ( 1 << V_46 -> V_47 . V_56 ) - 1 ;
V_58 <<= V_46 -> V_47 . V_55 ;
V_2 = F_1 ( V_46 -> V_47 . V_53 +
V_46 -> V_47 . V_54 ) ;
V_2 &= ~ ( ( ( 1 << V_46 -> V_47 . V_56 ) - 1 )
<< V_46 -> V_47 . V_55 ) ;
V_2 |= V_58 ;
F_3 ( V_2 , V_46 -> V_47 . V_53 +
V_46 -> V_47 . V_54 ) ;
F_7 ( L_19 , F_8 ( V_4 ) ,
V_10 / V_59 ) ;
} else {
V_59 = 1 ;
}
if ( V_46 -> V_25 )
F_37 ( V_46 -> V_25 , V_24 ) ;
return V_10 / V_59 ;
}
static long F_42 ( struct V_3 * V_4 , unsigned long V_57 ,
unsigned long * V_60 )
{
struct V_45 * V_46 = F_34 ( V_4 ) ;
unsigned long V_10 = * V_60 ;
T_1 V_58 ;
if ( V_46 -> V_47 . V_53 ) {
if ( V_57 > V_10 )
V_57 = V_10 ;
V_58 = V_10 / V_57 ;
} else {
V_58 = 1 ;
}
return V_10 / V_58 ;
}
static struct V_19 * F_43 ( struct V_20 * V_21 ,
const char * V_22 , const char * V_23 ,
struct V_61 * V_62 , T_3 * V_25 )
{
struct V_45 * V_26 ;
struct V_19 * V_19 ;
struct V_27 V_28 ;
int V_63 ;
V_26 = F_17 ( sizeof( * V_26 ) , V_29 ) ;
if ( ! V_26 ) {
F_18 ( L_5 , V_30 ) ;
return F_19 ( - V_31 ) ;
}
V_28 . V_22 = V_22 ;
V_28 . V_32 = & V_64 ;
V_28 . V_24 = 0 ;
V_28 . V_34 = V_23 ? & V_23 : NULL ;
V_28 . V_35 = V_23 ? 1 : 0 ;
V_26 -> V_25 = V_25 ;
V_26 -> V_4 . V_28 = & V_28 ;
V_26 -> V_47 = * V_62 ;
V_19 = F_20 ( V_21 , & V_26 -> V_4 ) ;
if ( F_21 ( V_19 ) ) {
F_18 ( L_6 , V_30 , V_22 ) ;
F_22 ( V_26 ) ;
return V_19 ;
}
V_63 = F_30 ( V_19 , V_22 , NULL ) ;
if ( V_63 != 0 ) {
F_18 ( L_20 ,
V_30 , V_22 ) ;
}
return V_19 ;
}
static void T_5 F_44 ( struct V_36 * V_37 )
{
const char * V_40 = V_37 -> V_41 ;
struct V_19 * V_19 ;
struct V_65 V_66 ;
int V_63 ;
struct V_61 V_62 ;
int V_67 ;
if ( ! F_45 ( V_37 ) )
return;
V_62 . V_48 = NULL ;
V_62 . V_53 = NULL ;
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ ) {
void T_2 * V_68 ;
V_63 = F_46 ( V_37 , V_67 , & V_66 ) ;
if ( V_63 != 0 ) {
if ( V_67 == 0 ) {
F_18 ( L_21 ,
V_37 -> V_41 ) ;
return;
}
break;
}
V_68 = F_26 ( V_37 , V_67 ) ;
if ( V_68 == NULL ) {
F_18 ( L_22 ,
V_67 , V_37 -> V_41 ) ;
goto V_69;
}
if ( strcmp ( V_66 . V_22 , L_23 ) == 0 )
V_62 . V_53 = V_68 ;
else
V_62 . V_48 = V_68 ;
}
if ( F_47 ( V_37 , L_24 , & V_62 . V_51 ) )
V_62 . V_51 = 0 ;
if ( F_47 ( V_37 , L_25 , & V_62 . V_52 ) )
V_62 . V_52 = 0xF ;
if ( F_47 ( V_37 , L_26 ,
& V_62 . V_49 ) )
V_62 . V_49 = 0x8 ;
if ( F_47 ( V_37 , L_27 , & V_62 . V_50 ) )
V_62 . V_50 = 0xF ;
if ( F_47 ( V_37 , L_28 ,
& V_62 . V_54 ) )
V_62 . V_54 = 0 ;
if ( F_47 ( V_37 , L_29 ,
& V_62 . V_56 ) )
V_62 . V_56 = 0 ;
if ( F_47 ( V_37 , L_30 ,
& V_62 . V_55 ) )
V_62 . V_55 = 0 ;
F_27 ( V_37 , L_10 , & V_40 ) ;
V_19 = F_43 ( NULL , V_40 ,
F_28 ( V_37 , 0 ) , & V_62 , & V_42 ) ;
if ( F_21 ( V_19 ) )
goto V_69;
F_7 ( L_31 , V_40 ) ;
V_63 = F_29 ( V_37 , V_43 , V_19 ) ;
if ( V_63 != 0 )
F_18 ( L_32 , V_30 ,
V_37 -> V_41 ) ;
return;
V_69:
if ( V_62 . V_48 )
F_48 ( V_62 . V_48 ) ;
if ( V_62 . V_53 )
F_48 ( V_62 . V_53 ) ;
}
