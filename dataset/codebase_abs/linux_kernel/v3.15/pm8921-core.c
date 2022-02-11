static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_4 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( V_2 -> V_7 , V_8 , V_3 ) ;
if ( V_5 ) {
F_4 ( L_1 , V_3 , V_5 ) ;
goto V_9;
}
V_5 = F_5 ( V_2 -> V_7 , V_10 , V_4 ) ;
if ( V_5 )
F_4 ( L_2 , V_5 ) ;
V_9:
F_6 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int
F_7 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_11 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( V_2 -> V_7 , V_8 , V_3 ) ;
if ( V_5 ) {
F_4 ( L_1 , V_3 , V_5 ) ;
goto V_9;
}
V_11 |= V_12 ;
V_5 = F_3 ( V_2 -> V_7 , V_13 , V_11 ) ;
if ( V_5 )
F_4 ( L_3 , V_5 ) ;
V_9:
F_6 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , int V_14 )
{
int V_15 , V_16 , V_17 , V_18 = 0 ;
unsigned int V_19 ;
V_18 = F_1 ( V_2 , V_14 , & V_19 ) ;
if ( V_18 ) {
F_4 ( L_4 , V_14 , V_18 ) ;
return V_18 ;
}
if ( ! V_19 ) {
F_4 ( L_5 , V_14 ) ;
return 0 ;
}
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
if ( V_19 & ( 1 << V_17 ) ) {
V_15 = V_14 * 8 + V_17 ;
V_16 = F_9 ( V_2 -> V_20 , V_15 ) ;
F_10 ( V_16 ) ;
}
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_21 )
{
unsigned int V_22 ;
int V_23 , V_17 , V_18 = 0 ;
V_18 = F_5 ( V_2 -> V_7 , V_24 + V_21 ,
& V_22 ) ;
if ( V_18 ) {
F_4 ( L_6 , V_21 , V_18 ) ;
return V_18 ;
}
if ( ! V_22 ) {
F_4 ( L_7 , V_21 ) ;
return 0 ;
}
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
if ( V_22 & ( 1 << V_17 ) ) {
V_23 = V_21 * 8 + V_17 ;
V_18 |= F_8 ( V_2 , V_23 ) ;
}
return V_18 ;
}
static void F_12 ( unsigned int V_16 , struct V_25 * V_26 )
{
struct V_1 * V_2 = F_13 ( V_26 ) ;
struct V_27 * V_27 = F_14 ( V_26 ) ;
unsigned int V_28 ;
int V_17 , V_18 , V_29 = 0 ;
F_15 ( V_27 , V_26 ) ;
V_18 = F_5 ( V_2 -> V_7 , V_30 , & V_28 ) ;
if ( V_18 ) {
F_4 ( L_8 , V_18 ) ;
return;
}
V_29 = V_28 >> 1 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_31 ; V_17 ++ )
if ( V_29 & ( 1 << V_17 ) )
F_11 ( V_2 , V_17 ) ;
F_16 ( V_27 , V_26 ) ;
}
static void F_17 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_18 ( V_33 ) ;
unsigned int V_15 = F_19 ( V_33 ) ;
int V_34 ;
T_1 V_14 , V_35 ;
V_14 = V_15 / 8 ;
V_34 = V_15 % 8 ;
V_35 = V_2 -> V_35 [ V_15 ] | V_36 | V_37 ;
F_7 ( V_2 , V_14 , V_35 ) ;
}
static void F_20 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_18 ( V_33 ) ;
unsigned int V_15 = F_19 ( V_33 ) ;
int V_34 ;
T_1 V_14 , V_35 ;
V_14 = V_15 / 8 ;
V_34 = V_15 % 8 ;
V_35 = V_2 -> V_35 [ V_15 ] ;
F_7 ( V_2 , V_14 , V_35 ) ;
}
static int F_21 ( struct V_32 * V_33 , unsigned int V_38 )
{
struct V_1 * V_2 = F_18 ( V_33 ) ;
unsigned int V_15 = F_19 ( V_33 ) ;
int V_34 ;
T_1 V_14 , V_35 ;
V_14 = V_15 / 8 ;
V_34 = V_15 % 8 ;
V_2 -> V_35 [ V_15 ] = ( V_34 << V_39 )
| V_36 ;
if ( V_38 & ( V_40 | V_41 ) ) {
if ( V_38 & V_40 )
V_2 -> V_35 [ V_15 ] &= ~ V_42 ;
if ( V_38 & V_41 )
V_2 -> V_35 [ V_15 ] &= ~ V_43 ;
} else {
V_2 -> V_35 [ V_15 ] |= V_44 ;
if ( V_38 & V_45 )
V_2 -> V_35 [ V_15 ] &= ~ V_42 ;
else
V_2 -> V_35 [ V_15 ] &= ~ V_43 ;
}
V_35 = V_2 -> V_35 [ V_15 ] | V_37 ;
return F_7 ( V_2 , V_14 , V_35 ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_16 )
{
int V_15 , V_5 ;
unsigned int V_14 , V_19 , V_46 ;
unsigned long V_47 ;
struct V_32 * V_32 = F_23 ( V_16 ) ;
V_15 = V_32 -> V_48 ;
V_14 = V_15 / 8 ;
V_46 = V_15 % 8 ;
F_24 ( & V_2 -> V_6 , V_47 ) ;
V_5 = F_3 ( V_2 -> V_7 , V_8 , V_14 ) ;
if ( V_5 ) {
F_4 ( L_9 ,
V_16 , V_15 , V_14 , V_5 ) ;
goto V_49;
}
V_5 = F_5 ( V_2 -> V_7 , V_50 , & V_19 ) ;
if ( V_5 ) {
F_4 ( L_10 ,
V_16 , V_15 , V_14 , V_5 ) ;
goto V_49;
}
V_5 = ( V_19 & ( 1 << V_46 ) ) ? 1 : 0 ;
V_49:
F_25 ( & V_2 -> V_6 , V_47 ) ;
return V_5 ;
}
static int F_26 ( struct V_51 * V_33 , unsigned int V_16 ,
T_2 V_48 )
{
struct V_1 * V_2 = V_33 -> V_52 ;
F_27 ( V_16 , & V_53 , V_54 ) ;
F_28 ( V_16 , V_2 ) ;
#ifdef F_29
F_30 ( V_16 , V_55 ) ;
#else
F_31 ( V_16 ) ;
#endif
return 0 ;
}
static int F_32 ( const struct V_56 * V_57 , T_3 V_58 , T_1 * V_59 )
{
const struct V_60 * V_61 = F_33 ( V_57 ) ;
const struct V_62 * V_63 = V_61 -> V_64 ;
return F_34 ( V_63 -> V_57 -> V_65 , V_58 , V_59 , 1 ) ;
}
static int F_35 ( const struct V_56 * V_57 , T_3 V_58 , T_1 V_59 )
{
const struct V_60 * V_61 = F_33 ( V_57 ) ;
const struct V_62 * V_63 = V_61 -> V_64 ;
return F_36 ( V_63 -> V_57 -> V_65 , V_58 , & V_59 , 1 ) ;
}
static int F_37 ( const struct V_56 * V_57 , T_3 V_58 , T_1 * V_66 ,
int V_67 )
{
const struct V_60 * V_61 = F_33 ( V_57 ) ;
const struct V_62 * V_63 = V_61 -> V_64 ;
return F_34 ( V_63 -> V_57 -> V_65 , V_58 , V_66 , V_67 ) ;
}
static int F_38 ( const struct V_56 * V_57 , T_3 V_58 , T_1 * V_66 ,
int V_67 )
{
const struct V_60 * V_61 = F_33 ( V_57 ) ;
const struct V_62 * V_63 = V_61 -> V_64 ;
return F_36 ( V_63 -> V_57 -> V_65 , V_58 , V_66 , V_67 ) ;
}
static int F_39 ( const struct V_56 * V_57 , int V_16 )
{
const struct V_60 * V_61 = F_33 ( V_57 ) ;
const struct V_62 * V_63 = V_61 -> V_64 ;
return F_22 ( V_63 -> V_27 , V_16 ) ;
}
static int F_40 ( struct V_68 * V_69 )
{
struct V_62 * V_63 ;
struct V_7 * V_7 ;
int V_16 , V_5 ;
unsigned int V_59 ;
T_4 V_70 ;
struct V_1 * V_2 ;
unsigned int V_71 = V_72 ;
V_16 = F_41 ( V_69 , 0 ) ;
if ( V_16 < 0 )
return V_16 ;
V_63 = F_42 ( & V_69 -> V_57 , sizeof( struct V_62 ) , V_73 ) ;
if ( ! V_63 ) {
F_4 ( L_11 ) ;
return - V_74 ;
}
V_7 = F_43 ( & V_69 -> V_57 , NULL , V_69 -> V_57 . V_65 ,
& V_75 ) ;
if ( F_44 ( V_7 ) )
return F_45 ( V_7 ) ;
V_5 = F_5 ( V_7 , V_76 , & V_59 ) ;
if ( V_5 ) {
F_4 ( L_12 , V_76 , V_5 ) ;
return V_5 ;
}
F_46 ( L_13 , V_59 ) ;
V_70 = V_59 ;
V_5 = F_5 ( V_7 , V_77 , & V_59 ) ;
if ( V_5 ) {
F_4 ( L_14 ,
V_77 , V_5 ) ;
return V_5 ;
}
F_46 ( L_15 , V_59 ) ;
V_70 |= V_59 << V_78 ;
V_63 -> V_57 = & V_69 -> V_57 ;
V_61 . V_64 = V_63 ;
F_47 ( V_69 , & V_61 ) ;
V_2 = F_42 ( & V_69 -> V_57 , sizeof( * V_2 ) +
sizeof( V_2 -> V_35 [ 0 ] ) * V_71 ,
V_73 ) ;
if ( ! V_2 )
return - V_74 ;
V_63 -> V_27 = V_2 ;
V_2 -> V_57 = & V_69 -> V_57 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_79 = V_71 ;
V_2 -> V_80 = F_48 ( V_2 -> V_79 , 8 ) ;
V_2 -> V_31 = F_48 ( V_2 -> V_80 , 8 ) ;
F_49 ( & V_2 -> V_6 ) ;
V_2 -> V_20 = F_50 ( V_69 -> V_57 . V_81 , V_71 ,
& V_82 ,
V_2 ) ;
if ( ! V_2 -> V_20 )
return - V_83 ;
F_51 ( V_16 , V_2 ) ;
F_52 ( V_16 , F_12 ) ;
F_53 ( V_16 , 1 ) ;
V_5 = F_54 ( V_69 -> V_57 . V_81 , NULL , NULL , & V_69 -> V_57 ) ;
if ( V_5 ) {
F_52 ( V_16 , NULL ) ;
F_51 ( V_16 , NULL ) ;
F_55 ( V_2 -> V_20 ) ;
}
return V_5 ;
}
static int F_56 ( struct V_56 * V_57 , void * V_84 )
{
F_57 ( F_58 ( V_57 ) ) ;
return 0 ;
}
static int F_59 ( struct V_68 * V_69 )
{
int V_16 = F_41 ( V_69 , 0 ) ;
struct V_62 * V_63 = V_61 . V_64 ;
struct V_1 * V_2 = V_63 -> V_27 ;
F_60 ( & V_69 -> V_57 , NULL , F_56 ) ;
F_52 ( V_16 , NULL ) ;
F_51 ( V_16 , NULL ) ;
F_55 ( V_2 -> V_20 ) ;
return 0 ;
}
static int T_5 F_61 ( void )
{
return F_62 ( & V_85 ) ;
}
static void T_6 F_63 ( void )
{
F_64 ( & V_85 ) ;
}
