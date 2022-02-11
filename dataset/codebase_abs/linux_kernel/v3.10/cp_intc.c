static inline unsigned int F_1 ( unsigned V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( unsigned long V_3 , unsigned V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
F_3 ( V_5 -> V_6 , V_7 ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
F_3 ( 1 , V_8 ) ;
F_3 ( V_5 -> V_6 , V_9 ) ;
F_3 ( 1 , V_10 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
F_3 ( V_5 -> V_6 , V_11 ) ;
}
static int F_8 ( struct V_4 * V_5 , unsigned int V_12 )
{
unsigned V_13 = F_9 ( V_5 -> V_6 ) ;
unsigned V_14 = F_10 ( V_5 -> V_6 ) ;
unsigned V_15 = F_1 ( F_11 ( V_13 ) ) ;
unsigned type = F_1 ( F_12 ( V_13 ) ) ;
switch ( V_12 ) {
case V_16 :
V_15 |= V_14 ;
type |= V_14 ;
break;
case V_17 :
V_15 &= ~ V_14 ;
type |= V_14 ;
break;
case V_18 :
V_15 |= V_14 ;
type &= ~ V_14 ;
break;
case V_19 :
V_15 &= ~ V_14 ;
type &= ~ V_14 ;
break;
default:
return - V_20 ;
}
F_3 ( V_15 , F_11 ( V_13 ) ) ;
F_3 ( type , F_12 ( V_13 ) ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 , unsigned int V_21 )
{
return 0 ;
}
static int F_14 ( struct V_22 * V_23 , unsigned int V_24 ,
T_1 V_25 )
{
F_15 ( L_1 , V_24 , V_25 ) ;
F_16 ( V_24 , & V_26 ) ;
F_17 ( V_24 , V_27 | V_28 ) ;
F_18 ( V_24 , V_29 ) ;
return 0 ;
}
int T_2 F_19 ( struct V_30 * V_31 , struct V_30 * V_32 )
{
T_3 V_33 = V_34 . V_35 ;
T_4 * V_36 = V_34 . V_37 ;
T_3 * V_38 = V_34 . V_39 ;
unsigned V_40 = F_20 ( V_33 ) ;
int V_41 , V_42 ;
V_43 = V_44 ;
if ( V_31 ) {
V_2 = F_21 ( V_31 , 0 ) ;
if ( F_22 ( V_31 , L_2 , & V_33 ) )
F_23 ( L_3 ,
V_33 ) ;
} else {
V_2 = F_24 ( V_34 . V_45 , V_46 ) ;
}
if ( F_25 ( ! V_2 ) )
return - V_20 ;
F_3 ( 0 , V_47 ) ;
F_3 ( 0 , F_26 ( 0 ) ) ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ )
F_3 ( ~ 0 , F_27 ( V_41 ) ) ;
F_3 ( 0 , V_48 ) ;
F_3 ( 0 , V_49 ) ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ )
F_3 ( ~ 0 , F_28 ( V_41 ) ) ;
F_3 ( 1 , V_10 ) ;
V_40 = ( V_33 + 3 ) >> 2 ;
if ( V_36 ) {
unsigned V_50 , V_51 ;
T_3 V_52 ;
for ( V_51 = V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
for ( V_52 = V_50 = 0 ; V_50 < 4 ; V_50 ++ , V_51 ++ ) {
V_52 >>= 8 ;
if ( V_51 < V_33 )
V_52 |= V_36 [ V_51 ] << 24 ;
}
F_3 ( V_52 , F_29 ( V_41 ) ) ;
}
} else {
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ )
F_3 ( 0x0f0f0f0f , F_29 ( V_41 ) ) ;
}
if ( V_38 )
for ( V_41 = 0 ; V_38 [ V_41 ] != - 1 ; V_41 ++ )
F_3 ( V_38 [ V_41 ] , F_30 ( V_41 ) ) ;
V_42 = F_31 ( - 1 , 0 , V_33 , 0 ) ;
if ( V_42 < 0 ) {
F_23 ( L_4 ) ;
V_42 = 0 ;
}
V_53 = F_32 ( V_31 , V_33 ,
V_42 , 0 , & V_54 , NULL ) ;
if ( ! V_53 ) {
F_33 ( L_5 ) ;
return - V_20 ;
}
F_3 ( 1 , V_47 ) ;
return 0 ;
}
void T_2 F_34 ( void )
{
F_19 ( NULL , NULL ) ;
}
