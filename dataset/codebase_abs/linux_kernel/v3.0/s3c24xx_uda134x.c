static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
#ifdef F_2
struct V_4 * V_5 = V_2 -> V_5 ;
#endif
F_3 ( & V_6 ) ;
F_4 ( L_1 , V_7 , V_8 ) ;
if ( V_8 == 0 ) {
V_9 = F_5 ( & V_10 -> V_11 , L_2 ) ;
if ( ! V_9 ) {
F_6 ( V_12 L_3 , V_7 ) ;
V_3 = - V_13 ;
} else {
V_14 = F_5 ( & V_10 -> V_11 ,
L_4 ) ;
if ( ! V_14 ) {
F_6 ( V_12 L_5 ,
V_7 ) ;
F_7 ( V_9 ) ;
V_3 = - V_13 ;
}
}
if ( ! V_3 ) {
int V_15 , V_16 ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ ) {
int V_17 = V_15 ? 256 : 384 ;
V_18 [ V_15 * 33 ] = F_8 ( V_9 ) / V_17 ;
for ( V_16 = 1 ; V_16 < 33 ; V_16 ++ )
V_18 [ V_15 * 33 + V_16 ] = F_8 ( V_14 ) /
( V_16 * V_17 ) ;
}
}
}
V_8 += 1 ;
F_9 ( & V_6 ) ;
if ( ! V_3 ) {
#ifdef F_2
V_3 = F_10 ( V_5 , 0 ,
V_19 ,
& V_20 ) ;
if ( V_3 < 0 )
F_6 ( V_12 L_6 ,
V_7 ) ;
#endif
}
return V_3 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_3 ( & V_6 ) ;
F_4 ( L_1 , V_7 , V_8 ) ;
V_8 -= 1 ;
if ( V_8 == 0 ) {
F_7 ( V_9 ) ;
V_9 = NULL ;
F_7 ( V_14 ) ;
V_14 = NULL ;
}
F_9 ( & V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
struct V_26 * V_28 = V_24 -> V_28 ;
unsigned int V_29 = 0 ;
int V_3 = 0 ;
int V_30 , V_31 ;
unsigned long V_32 = F_13 ( V_22 ) ;
long V_33 , V_34 ;
unsigned int div ;
int V_15 , V_35 ;
V_33 = 999999 ;
V_35 = 0 ;
for ( V_15 = 0 ; V_15 < 2 * 33 ; V_15 ++ ) {
V_34 = V_18 [ V_15 ] - V_32 ;
if ( V_34 < 0 )
V_34 = - V_34 ;
if ( V_34 < V_33 ) {
V_33 = V_34 ;
V_35 = V_15 ;
}
}
if ( V_35 / 33 == 1 )
V_31 = V_36 ;
else
V_31 = V_37 ;
if ( V_35 % 33 == 0 ) {
V_30 = V_38 ;
div = 1 ;
} else {
V_30 = V_39 ;
div = V_35 % 33 ;
}
F_4 ( L_7 , V_7 , V_32 , V_35 ) ;
V_29 = ( V_31 == V_37 ? 384 : 256 ) * V_32 ;
F_4 ( L_8 , V_7 ,
V_31 == V_37 ? L_9 : L_10 ,
V_30 == V_38 ? L_11 : L_12 ,
div , V_29 , V_33 ) ;
if ( ( V_33 * 100 / V_32 ) > 5 ) {
F_6 ( V_12 L_13
L_14 ,
V_33 * 100 / V_32 ) ;
return - V_40 ;
}
V_3 = F_14 ( V_27 , V_41 |
V_42 | V_43 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_14 ( V_28 , V_41 |
V_42 | V_43 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_15 ( V_28 , V_30 , V_29 ,
V_44 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_16 ( V_28 , V_45 , V_31 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_16 ( V_28 , V_46 ,
V_47 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_16 ( V_28 , V_48 ,
F_17 ( div , div ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_15 ( V_27 , 0 , V_29 ,
V_49 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static void F_18 ( int V_50 )
{
F_19 ( V_51 -> V_52 , V_50 > 0 ) ;
}
static void F_20 ( int V_50 )
{
F_19 ( V_51 -> V_53 , V_50 > 0 ) ;
}
static void F_21 ( int V_50 )
{
F_19 ( V_51 -> V_54 , V_50 > 0 ) ;
}
static int F_22 ( int V_55 , char * V_56 )
{
if ( F_23 ( V_55 , L_15 ) < 0 ) {
F_6 ( V_12 L_16
L_17 , V_56 ) ;
return - V_13 ;
}
F_24 ( V_55 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_57 * V_58 )
{
int V_3 ;
F_6 ( V_59 L_18 ) ;
V_51 = V_58 -> V_11 . V_60 ;
if ( V_51 == NULL ) {
F_6 ( V_12 L_16
L_19 ) ;
return - V_61 ;
}
V_62 . V_63 = V_51 -> V_63 ;
V_62 . V_64 = V_51 -> V_64 ;
if ( F_22 ( V_51 -> V_52 ,
L_20 ) < 0 )
return - V_13 ;
if ( F_22 ( V_51 -> V_53 ,
L_21 ) < 0 ) {
F_26 ( V_51 -> V_52 ) ;
return - V_13 ;
}
if ( F_22 ( V_51 -> V_54 ,
L_22 ) < 0 ) {
F_26 ( V_51 -> V_52 ) ;
F_26 ( V_51 -> V_53 ) ;
return - V_13 ;
}
V_10 = F_27 ( L_23 , - 1 ) ;
if ( ! V_10 ) {
F_6 ( V_12 L_16
L_24 ) ;
return - V_65 ;
}
F_28 ( V_10 ,
& V_66 ) ;
F_29 ( V_10 , & V_62 , sizeof( V_62 ) ) ;
V_3 = F_30 ( V_10 ) ;
if ( V_3 ) {
F_6 ( V_12 L_25 ) ;
F_31 ( V_10 ) ;
}
return V_3 ;
}
static int F_32 ( struct V_57 * V_58 )
{
F_33 ( V_10 ) ;
F_26 ( V_51 -> V_52 ) ;
F_26 ( V_51 -> V_53 ) ;
F_26 ( V_51 -> V_54 ) ;
return 0 ;
}
static int T_1 F_34 ( void )
{
return F_35 ( & V_67 ) ;
}
static void T_2 F_36 ( void )
{
F_37 ( & V_67 ) ;
}
