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
static int F_13 ( struct V_21 * V_22 , unsigned int V_23 ,
T_1 V_24 )
{
F_14 ( L_1 , V_23 , V_24 ) ;
F_15 ( V_23 , & V_25 ) ;
F_16 ( V_23 ) ;
F_17 ( V_23 , V_26 ) ;
return 0 ;
}
int T_2 F_18 ( struct V_27 * V_28 , struct V_27 * V_29 )
{
T_3 V_30 = V_31 . V_32 ;
T_4 * V_33 = V_31 . V_34 ;
T_3 * V_35 = V_31 . V_36 ;
unsigned V_37 = F_19 ( V_30 ) ;
int V_38 , V_39 ;
V_40 = V_41 ;
if ( V_28 ) {
V_2 = F_20 ( V_28 , 0 ) ;
if ( F_21 ( V_28 , L_2 , & V_30 ) )
F_22 ( L_3 ,
V_30 ) ;
} else {
V_2 = F_23 ( V_31 . V_42 , V_43 ) ;
}
if ( F_24 ( ! V_2 ) )
return - V_20 ;
F_3 ( 0 , V_44 ) ;
F_3 ( 0 , F_25 ( 0 ) ) ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ )
F_3 ( ~ 0 , F_26 ( V_38 ) ) ;
F_3 ( 0 , V_45 ) ;
F_3 ( 0 , V_46 ) ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ )
F_3 ( ~ 0 , F_27 ( V_38 ) ) ;
F_3 ( 1 , V_10 ) ;
V_37 = ( V_30 + 3 ) >> 2 ;
if ( V_33 ) {
unsigned V_47 , V_48 ;
T_3 V_49 ;
for ( V_48 = V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
for ( V_49 = V_47 = 0 ; V_47 < 4 ; V_47 ++ , V_48 ++ ) {
V_49 >>= 8 ;
if ( V_48 < V_30 )
V_49 |= V_33 [ V_48 ] << 24 ;
}
F_3 ( V_49 , F_28 ( V_38 ) ) ;
}
} else {
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ )
F_3 ( 0x0f0f0f0f , F_28 ( V_38 ) ) ;
}
if ( V_35 )
for ( V_38 = 0 ; V_35 [ V_38 ] != - 1 ; V_38 ++ )
F_3 ( V_35 [ V_38 ] , F_29 ( V_38 ) ) ;
V_39 = F_30 ( - 1 , 0 , V_30 , 0 ) ;
if ( V_39 < 0 ) {
F_22 ( L_4 ) ;
V_39 = 0 ;
}
V_50 = F_31 ( V_28 , V_30 ,
V_39 , 0 , & V_51 , NULL ) ;
if ( ! V_50 ) {
F_32 ( L_5 ) ;
return - V_20 ;
}
F_3 ( 1 , V_44 ) ;
return 0 ;
}
void T_2 F_33 ( void )
{
F_18 ( NULL , NULL ) ;
}
