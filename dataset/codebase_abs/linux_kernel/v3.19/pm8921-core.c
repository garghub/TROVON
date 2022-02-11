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
T_1 V_14 , V_34 ;
V_14 = V_15 / 8 ;
V_34 = V_2 -> V_34 [ V_15 ] | V_35 | V_36 ;
F_7 ( V_2 , V_14 , V_34 ) ;
}
static void F_20 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_18 ( V_33 ) ;
unsigned int V_15 = F_19 ( V_33 ) ;
T_1 V_14 , V_34 ;
V_14 = V_15 / 8 ;
V_34 = V_2 -> V_34 [ V_15 ] ;
F_7 ( V_2 , V_14 , V_34 ) ;
}
static int F_21 ( struct V_32 * V_33 , unsigned int V_37 )
{
struct V_1 * V_2 = F_18 ( V_33 ) ;
unsigned int V_15 = F_19 ( V_33 ) ;
int V_38 ;
T_1 V_14 , V_34 ;
V_14 = V_15 / 8 ;
V_38 = V_15 % 8 ;
V_2 -> V_34 [ V_15 ] = ( V_38 << V_39 )
| V_35 ;
if ( V_37 & ( V_40 | V_41 ) ) {
if ( V_37 & V_40 )
V_2 -> V_34 [ V_15 ] &= ~ V_42 ;
if ( V_37 & V_41 )
V_2 -> V_34 [ V_15 ] &= ~ V_43 ;
} else {
V_2 -> V_34 [ V_15 ] |= V_44 ;
if ( V_37 & V_45 )
V_2 -> V_34 [ V_15 ] &= ~ V_42 ;
else
V_2 -> V_34 [ V_15 ] &= ~ V_43 ;
}
V_34 = V_2 -> V_34 [ V_15 ] | V_36 ;
return F_7 ( V_2 , V_14 , V_34 ) ;
}
static int F_22 ( struct V_46 * V_33 , unsigned int V_16 ,
T_2 V_47 )
{
struct V_1 * V_2 = V_33 -> V_48 ;
F_23 ( V_16 , & V_49 , V_50 ) ;
F_24 ( V_16 , V_2 ) ;
#ifdef F_25
F_26 ( V_16 , V_51 ) ;
#else
F_27 ( V_16 ) ;
#endif
return 0 ;
}
static int F_28 ( struct V_52 * V_53 )
{
struct V_7 * V_7 ;
int V_16 , V_5 ;
unsigned int V_54 ;
T_3 V_55 ;
struct V_1 * V_2 ;
unsigned int V_56 = V_57 ;
V_16 = F_29 ( V_53 , 0 ) ;
if ( V_16 < 0 )
return V_16 ;
V_7 = F_30 ( & V_53 -> V_58 , NULL , V_53 -> V_58 . V_59 ,
& V_60 ) ;
if ( F_31 ( V_7 ) )
return F_32 ( V_7 ) ;
V_5 = F_5 ( V_7 , V_61 , & V_54 ) ;
if ( V_5 ) {
F_4 ( L_9 , V_61 , V_5 ) ;
return V_5 ;
}
F_33 ( L_10 , V_54 ) ;
V_55 = V_54 ;
V_5 = F_5 ( V_7 , V_62 , & V_54 ) ;
if ( V_5 ) {
F_4 ( L_11 ,
V_62 , V_5 ) ;
return V_5 ;
}
F_33 ( L_12 , V_54 ) ;
V_55 |= V_54 << V_63 ;
V_2 = F_34 ( & V_53 -> V_58 , sizeof( * V_2 ) +
sizeof( V_2 -> V_34 [ 0 ] ) * V_56 ,
V_64 ) ;
if ( ! V_2 )
return - V_65 ;
F_35 ( V_53 , V_2 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_66 = V_56 ;
V_2 -> V_67 = F_36 ( V_2 -> V_66 , 8 ) ;
V_2 -> V_31 = F_36 ( V_2 -> V_67 , 8 ) ;
F_37 ( & V_2 -> V_6 ) ;
V_2 -> V_20 = F_38 ( V_53 -> V_58 . V_68 , V_56 ,
& V_69 ,
V_2 ) ;
if ( ! V_2 -> V_20 )
return - V_70 ;
F_39 ( V_16 , V_2 ) ;
F_40 ( V_16 , F_12 ) ;
F_41 ( V_16 , 1 ) ;
V_5 = F_42 ( V_53 -> V_58 . V_68 , NULL , NULL , & V_53 -> V_58 ) ;
if ( V_5 ) {
F_40 ( V_16 , NULL ) ;
F_39 ( V_16 , NULL ) ;
F_43 ( V_2 -> V_20 ) ;
}
return V_5 ;
}
static int F_44 ( struct V_71 * V_58 , void * V_72 )
{
F_45 ( F_46 ( V_58 ) ) ;
return 0 ;
}
static int F_47 ( struct V_52 * V_53 )
{
int V_16 = F_29 ( V_53 , 0 ) ;
struct V_1 * V_2 = F_48 ( V_53 ) ;
F_49 ( & V_53 -> V_58 , NULL , F_44 ) ;
F_40 ( V_16 , NULL ) ;
F_39 ( V_16 , NULL ) ;
F_43 ( V_2 -> V_20 ) ;
return 0 ;
}
static int T_4 F_50 ( void )
{
return F_51 ( & V_73 ) ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_73 ) ;
}
