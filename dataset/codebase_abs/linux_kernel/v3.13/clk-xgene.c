static inline T_1 F_1 ( void * V_1 )
{
return F_2 ( V_1 ) ;
}
static inline void F_3 ( T_1 V_2 , void * V_1 )
{
return F_4 ( V_2 , V_1 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_6 ( V_4 ) ;
T_1 V_2 ;
V_2 = F_1 ( V_6 -> V_7 + V_6 -> V_8 ) ;
F_7 ( L_1 , V_6 -> V_9 ,
V_2 & V_10 ? L_2 : L_3 ) ;
return V_2 & V_10 ? 0 : 1 ;
}
static unsigned long F_8 ( struct V_3 * V_4 ,
unsigned long V_11 )
{
struct V_5 * V_6 = F_6 ( V_4 ) ;
unsigned long V_12 ;
unsigned long V_13 ;
T_1 V_14 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_17 ;
V_14 = F_1 ( V_6 -> V_7 + V_6 -> V_8 ) ;
if ( V_6 -> type == V_18 ) {
V_16 = 2 ;
V_13 = V_11 * ( F_9 ( V_14 ) + 4 ) ;
} else {
V_15 = F_10 ( V_14 ) + 1 ;
V_16 = F_11 ( V_14 ) + 1 ;
V_17 = F_12 ( V_14 ) ;
V_12 = V_11 / V_15 ;
V_13 = V_12 * V_17 ;
}
F_7 ( L_4 , V_6 -> V_9 ,
V_13 / V_16 , V_11 ) ;
return V_13 / V_16 ;
}
static struct V_19 * F_13 ( struct V_20 * V_21 ,
const char * V_9 , const char * V_22 ,
unsigned long V_23 , void T_2 * V_7 , T_1 V_8 ,
T_1 type , T_3 * V_24 )
{
struct V_5 * V_25 ;
struct V_19 * V_19 ;
struct V_26 V_27 ;
V_25 = F_14 ( sizeof( * V_25 ) , V_28 ) ;
if ( ! V_25 ) {
F_15 ( L_5 , V_29 ) ;
return F_16 ( - V_30 ) ;
}
V_27 . V_9 = V_9 ;
V_27 . V_31 = & V_32 ;
V_27 . V_23 = V_23 ;
V_27 . V_33 = V_22 ? & V_22 : NULL ;
V_27 . V_34 = V_22 ? 1 : 0 ;
V_25 -> V_9 = V_9 ;
V_25 -> V_7 = V_7 ;
V_25 -> V_24 = V_24 ;
V_25 -> V_8 = V_8 ;
V_25 -> type = type ;
V_25 -> V_4 . V_27 = & V_27 ;
V_19 = F_17 ( V_21 , & V_25 -> V_4 ) ;
if ( F_18 ( V_19 ) ) {
F_15 ( L_6 , V_29 , V_9 ) ;
F_19 ( V_25 ) ;
return NULL ;
}
return V_19 ;
}
static void F_20 ( struct V_35 * V_36 , enum V_37 V_38 )
{
const char * V_39 = V_36 -> V_40 ;
struct V_19 * V_19 ;
void * V_7 ;
V_7 = F_21 ( V_36 , 0 ) ;
if ( V_7 == NULL ) {
F_15 ( L_7 , V_36 -> V_40 ) ;
return;
}
F_22 ( V_36 , L_8 , & V_39 ) ;
V_19 = F_13 ( NULL ,
V_39 , F_23 ( V_36 , 0 ) ,
V_41 , V_7 , 0 , V_38 , & V_42 ) ;
if ( ! F_18 ( V_19 ) ) {
F_24 ( V_36 , V_43 , V_19 ) ;
F_25 ( V_19 , V_39 , NULL ) ;
F_7 ( L_9 , V_39 ) ;
}
}
static void F_26 ( struct V_35 * V_36 )
{
F_20 ( V_36 , V_44 ) ;
}
static void F_27 ( struct V_35 * V_36 )
{
F_20 ( V_36 , V_18 ) ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_45 * V_46 = F_29 ( V_4 ) ;
unsigned long V_23 = 0 ;
T_1 V_2 ;
if ( V_46 -> V_24 )
F_30 ( V_46 -> V_24 , V_23 ) ;
if ( V_46 -> V_47 . V_48 != NULL ) {
F_7 ( L_10 , V_46 -> V_9 ) ;
V_2 = F_1 ( V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_49 ) ;
V_2 |= V_46 -> V_47 . V_50 ;
F_3 ( V_2 , V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_49 ) ;
F_7 ( L_11 ,
V_46 -> V_9 , F_31 ( V_46 -> V_47 . V_48 ) ,
V_46 -> V_47 . V_49 , V_46 -> V_47 . V_50 ,
V_2 ) ;
V_2 = F_1 ( V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_51 ) ;
V_2 &= ~ V_46 -> V_47 . V_52 ;
F_3 ( V_2 , V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_51 ) ;
F_7 ( L_12 ,
V_46 -> V_9 , F_31 ( V_46 -> V_47 . V_48 ) ,
V_46 -> V_47 . V_51 , V_46 -> V_47 . V_52 ,
V_2 ) ;
}
if ( V_46 -> V_24 )
F_32 ( V_46 -> V_24 , V_23 ) ;
return 0 ;
}
static void F_33 ( struct V_3 * V_4 )
{
struct V_45 * V_46 = F_29 ( V_4 ) ;
unsigned long V_23 = 0 ;
T_1 V_2 ;
if ( V_46 -> V_24 )
F_30 ( V_46 -> V_24 , V_23 ) ;
if ( V_46 -> V_47 . V_48 != NULL ) {
F_7 ( L_13 , V_46 -> V_9 ) ;
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
if ( V_46 -> V_24 )
F_32 ( V_46 -> V_24 , V_23 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_45 * V_46 = F_29 ( V_4 ) ;
T_1 V_2 = 0 ;
if ( V_46 -> V_47 . V_48 != NULL ) {
F_7 ( L_14 , V_46 -> V_9 ) ;
V_2 = F_1 ( V_46 -> V_47 . V_48 +
V_46 -> V_47 . V_49 ) ;
F_7 ( L_15 , V_46 -> V_9 ,
V_2 & V_46 -> V_47 . V_50 ? L_3 :
L_2 ) ;
}
if ( V_46 -> V_47 . V_48 == NULL )
return 1 ;
return V_2 & V_46 -> V_47 . V_50 ? 1 : 0 ;
}
static unsigned long F_35 ( struct V_3 * V_4 ,
unsigned long V_11 )
{
struct V_45 * V_46 = F_29 ( V_4 ) ;
T_1 V_2 ;
if ( V_46 -> V_47 . V_53 ) {
V_2 = F_1 ( V_46 -> V_47 . V_53 +
V_46 -> V_47 . V_54 ) ;
V_2 >>= V_46 -> V_47 . V_55 ;
V_2 &= ( 1 << V_46 -> V_47 . V_56 ) - 1 ;
F_7 ( L_16 ,
V_46 -> V_9 , V_11 / V_2 , V_11 ) ;
return V_11 / V_2 ;
} else {
F_7 ( L_16 ,
V_46 -> V_9 , V_11 , V_11 ) ;
return V_11 ;
}
}
static int F_36 ( struct V_3 * V_4 , unsigned long V_57 ,
unsigned long V_11 )
{
struct V_45 * V_46 = F_29 ( V_4 ) ;
unsigned long V_23 = 0 ;
T_1 V_2 ;
T_1 V_58 ;
T_1 V_59 ;
if ( V_46 -> V_24 )
F_30 ( V_46 -> V_24 , V_23 ) ;
if ( V_46 -> V_47 . V_53 ) {
if ( V_57 > V_11 )
V_57 = V_11 ;
V_59 = V_58 = V_11 / V_57 ;
V_58 &= ( 1 << V_46 -> V_47 . V_56 ) - 1 ;
V_58 <<= V_46 -> V_47 . V_55 ;
V_2 = F_1 ( V_46 -> V_47 . V_53 +
V_46 -> V_47 . V_54 ) ;
V_2 &= ~ ( ( 1 << V_46 -> V_47 . V_56 ) - 1 ) ;
V_2 |= V_58 ;
F_3 ( V_2 , V_46 -> V_47 . V_53 +
V_46 -> V_47 . V_54 ) ;
F_7 ( L_17 , V_46 -> V_9 ,
V_11 / V_59 ) ;
} else {
V_59 = 1 ;
}
if ( V_46 -> V_24 )
F_32 ( V_46 -> V_24 , V_23 ) ;
return V_11 / V_59 ;
}
static long F_37 ( struct V_3 * V_4 , unsigned long V_57 ,
unsigned long * V_60 )
{
struct V_45 * V_46 = F_29 ( V_4 ) ;
unsigned long V_11 = * V_60 ;
T_1 V_58 ;
if ( V_46 -> V_47 . V_53 ) {
if ( V_57 > V_11 )
V_57 = V_11 ;
V_58 = V_11 / V_57 ;
} else {
V_58 = 1 ;
}
return V_11 / V_58 ;
}
static struct V_19 * F_38 ( struct V_20 * V_21 ,
const char * V_9 , const char * V_22 ,
struct V_61 * V_62 , T_3 * V_24 )
{
struct V_45 * V_25 ;
struct V_19 * V_19 ;
struct V_26 V_27 ;
int V_63 ;
V_25 = F_14 ( sizeof( * V_25 ) , V_28 ) ;
if ( ! V_25 ) {
F_15 ( L_5 , V_29 ) ;
return F_16 ( - V_30 ) ;
}
V_27 . V_9 = V_9 ;
V_27 . V_31 = & V_64 ;
V_27 . V_23 = 0 ;
V_27 . V_33 = V_22 ? & V_22 : NULL ;
V_27 . V_34 = V_22 ? 1 : 0 ;
V_25 -> V_9 = V_9 ;
V_25 -> V_24 = V_24 ;
V_25 -> V_4 . V_27 = & V_27 ;
V_25 -> V_47 = * V_62 ;
V_19 = F_17 ( V_21 , & V_25 -> V_4 ) ;
if ( F_18 ( V_19 ) ) {
F_15 ( L_6 , V_29 , V_9 ) ;
F_19 ( V_25 ) ;
return V_19 ;
}
V_63 = F_25 ( V_19 , V_9 , NULL ) ;
if ( V_63 != 0 ) {
F_15 ( L_18 ,
V_29 , V_9 ) ;
}
return V_19 ;
}
static void T_4 F_39 ( struct V_35 * V_36 )
{
const char * V_39 = V_36 -> V_40 ;
struct V_19 * V_19 ;
struct V_65 V_66 ;
int V_63 ;
struct V_61 V_62 ;
int V_67 ;
if ( ! F_40 ( V_36 ) )
return;
V_62 . V_48 = NULL ;
V_62 . V_53 = NULL ;
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ ) {
void * V_68 ;
V_63 = F_41 ( V_36 , V_67 , & V_66 ) ;
if ( V_63 != 0 ) {
if ( V_67 == 0 ) {
F_15 ( L_19 ,
V_36 -> V_40 ) ;
return;
}
break;
}
V_68 = F_21 ( V_36 , V_67 ) ;
if ( V_68 == NULL ) {
F_15 ( L_20 ,
V_67 , V_36 -> V_40 ) ;
goto V_69;
}
if ( strcmp ( V_66 . V_9 , L_21 ) == 0 )
V_62 . V_53 = V_68 ;
else
V_62 . V_48 = V_68 ;
}
if ( F_42 ( V_36 , L_22 , & V_62 . V_51 ) )
V_62 . V_51 = 0 ;
if ( F_42 ( V_36 , L_23 , & V_62 . V_52 ) )
V_62 . V_52 = 0xF ;
if ( F_42 ( V_36 , L_24 ,
& V_62 . V_49 ) )
V_62 . V_49 = 0x8 ;
if ( F_42 ( V_36 , L_25 , & V_62 . V_50 ) )
V_62 . V_50 = 0xF ;
if ( F_42 ( V_36 , L_26 ,
& V_62 . V_54 ) )
V_62 . V_54 = 0 ;
if ( F_42 ( V_36 , L_27 ,
& V_62 . V_56 ) )
V_62 . V_56 = 0 ;
if ( F_42 ( V_36 , L_28 ,
& V_62 . V_55 ) )
V_62 . V_55 = 0 ;
F_22 ( V_36 , L_8 , & V_39 ) ;
V_19 = F_38 ( NULL , V_39 ,
F_23 ( V_36 , 0 ) , & V_62 , & V_42 ) ;
if ( F_18 ( V_19 ) )
goto V_69;
F_7 ( L_29 , V_39 ) ;
V_63 = F_24 ( V_36 , V_43 , V_19 ) ;
if ( V_63 != 0 )
F_15 ( L_30 , V_29 ,
V_36 -> V_40 ) ;
return;
V_69:
if ( V_62 . V_48 )
F_43 ( V_62 . V_48 ) ;
if ( V_62 . V_53 )
F_43 ( V_62 . V_53 ) ;
}
