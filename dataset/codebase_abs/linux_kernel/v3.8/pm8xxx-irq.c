static int F_1 ( const struct V_1 * V_2 , T_1 * V_3 )
{
return F_2 ( V_2 -> V_4 , V_5 , V_3 ) ;
}
static int F_3 ( const struct V_1 * V_2 , T_1 V_6 , T_1 * V_7 )
{
return F_2 ( V_2 -> V_4 ,
V_8 + V_6 , V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_7 , T_1 * V_9 )
{
int V_10 ;
F_5 ( & V_2 -> V_11 ) ;
V_10 = F_6 ( V_2 -> V_4 , V_12 , V_7 ) ;
if ( V_10 ) {
F_7 ( L_1 , V_7 , V_10 ) ;
goto V_13;
}
V_10 = F_2 ( V_2 -> V_4 , V_14 , V_9 ) ;
if ( V_10 )
F_7 ( L_2 , V_10 ) ;
V_13:
F_8 ( & V_2 -> V_11 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_15 )
{
int V_10 ;
F_5 ( & V_2 -> V_11 ) ;
V_10 = F_6 ( V_2 -> V_4 , V_12 , V_7 ) ;
if ( V_10 ) {
F_7 ( L_1 , V_7 , V_10 ) ;
goto V_13;
}
V_15 |= V_16 ;
V_10 = F_6 ( V_2 -> V_4 , V_17 , V_15 ) ;
if ( V_10 )
F_7 ( L_3 , V_10 ) ;
V_13:
F_8 ( & V_2 -> V_11 ) ;
return V_10 ;
}
static int F_10 ( struct V_1 * V_2 , int V_18 )
{
int V_19 , V_20 , V_21 , V_22 = 0 ;
T_1 V_23 ;
V_22 = F_4 ( V_2 , V_18 , & V_23 ) ;
if ( V_22 ) {
F_7 ( L_4 , V_18 , V_22 ) ;
return V_22 ;
}
if ( ! V_23 ) {
F_7 ( L_5 , V_18 ) ;
return 0 ;
}
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
if ( V_23 & ( 1 << V_21 ) ) {
V_19 = V_18 * 8 + V_21 ;
V_20 = V_19 + V_2 -> V_24 ;
F_11 ( V_20 ) ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_25 )
{
T_1 V_26 ;
int V_27 , V_21 , V_22 = 0 ;
V_22 = F_3 ( V_2 , V_25 , & V_26 ) ;
if ( V_22 ) {
F_7 ( L_6 , V_25 , V_22 ) ;
return V_22 ;
}
if ( ! V_26 ) {
F_7 ( L_7 , V_25 ) ;
return 0 ;
}
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ )
if ( V_26 & ( 1 << V_21 ) ) {
V_27 = V_25 * 8 + V_21 ;
V_22 |= F_10 ( V_2 , V_27 ) ;
}
return V_22 ;
}
static void F_13 ( unsigned int V_20 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_14 ( V_29 ) ;
struct V_30 * V_30 = F_15 ( V_29 ) ;
T_1 V_31 ;
int V_21 , V_22 , V_32 = 0 ;
V_22 = F_1 ( V_2 , & V_31 ) ;
if ( V_22 ) {
F_7 ( L_8 , V_22 ) ;
return;
}
V_32 = V_31 >> 1 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_33 ; V_21 ++ )
if ( V_32 & ( 1 << V_21 ) )
F_12 ( V_2 , V_21 ) ;
V_30 -> V_34 ( & V_29 -> V_35 ) ;
}
static void F_16 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
unsigned int V_19 = V_36 -> V_20 - V_2 -> V_24 ;
int V_25 , V_37 ;
T_1 V_18 , V_38 ;
V_18 = V_19 / 8 ;
V_25 = V_18 / 8 ;
V_37 = V_19 % 8 ;
V_38 = V_2 -> V_38 [ V_19 ] | V_39 | V_40 ;
F_9 ( V_2 , V_18 , V_38 ) ;
}
static void F_18 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
unsigned int V_19 = V_36 -> V_20 - V_2 -> V_24 ;
int V_25 , V_37 ;
T_1 V_18 , V_38 ;
V_18 = V_19 / 8 ;
V_25 = V_18 / 8 ;
V_37 = V_19 % 8 ;
V_38 = V_2 -> V_38 [ V_19 ] ;
F_9 ( V_2 , V_18 , V_38 ) ;
}
static int F_19 ( struct V_35 * V_36 , unsigned int V_41 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
unsigned int V_19 = V_36 -> V_20 - V_2 -> V_24 ;
int V_25 , V_37 ;
T_1 V_18 , V_38 ;
V_18 = V_19 / 8 ;
V_25 = V_18 / 8 ;
V_37 = V_19 % 8 ;
V_2 -> V_38 [ V_19 ] = ( V_37 << V_42 )
| V_39 ;
if ( V_41 & ( V_43 | V_44 ) ) {
if ( V_41 & V_43 )
V_2 -> V_38 [ V_19 ] &= ~ V_45 ;
if ( V_41 & V_44 )
V_2 -> V_38 [ V_19 ] &= ~ V_46 ;
} else {
V_2 -> V_38 [ V_19 ] |= V_47 ;
if ( V_41 & V_48 )
V_2 -> V_38 [ V_19 ] &= ~ V_45 ;
else
V_2 -> V_38 [ V_19 ] &= ~ V_46 ;
}
V_38 = V_2 -> V_38 [ V_19 ] | V_40 ;
return F_9 ( V_2 , V_18 , V_38 ) ;
}
static int F_20 ( struct V_35 * V_36 , unsigned int V_49 )
{
return 0 ;
}
int F_21 ( struct V_1 * V_2 , int V_20 )
{
int V_19 , V_10 ;
T_1 V_18 , V_23 , V_50 ;
unsigned long V_51 ;
if ( V_2 == NULL || V_20 < V_2 -> V_24 ||
V_20 >= V_2 -> V_24 + V_2 -> V_52 )
return - V_53 ;
V_19 = V_20 - V_2 -> V_24 ;
V_18 = V_19 / 8 ;
V_50 = V_19 % 8 ;
F_22 ( & V_2 -> V_11 , V_51 ) ;
V_10 = F_6 ( V_2 -> V_4 , V_12 , V_18 ) ;
if ( V_10 ) {
F_7 ( L_9 ,
V_20 , V_19 , V_18 , V_10 ) ;
goto V_54;
}
V_10 = F_2 ( V_2 -> V_4 , V_55 , & V_23 ) ;
if ( V_10 ) {
F_7 ( L_10 ,
V_20 , V_19 , V_18 , V_10 ) ;
goto V_54;
}
V_10 = ( V_23 & ( 1 << V_50 ) ) ? 1 : 0 ;
V_54:
F_23 ( & V_2 -> V_11 , V_51 ) ;
return V_10 ;
}
struct V_1 * F_24 ( struct V_56 * V_4 ,
const struct V_57 * V_58 )
{
struct V_1 * V_2 ;
int V_59 , V_10 ;
unsigned int V_19 ;
if ( ! V_58 ) {
F_7 ( L_11 ) ;
return F_25 ( - V_53 ) ;
}
V_59 = V_58 -> V_59 ;
if ( V_59 < 0 ) {
F_7 ( L_12 ) ;
V_10 = V_59 ;
return F_25 ( - V_53 ) ;
}
V_2 = F_26 ( sizeof( struct V_1 )
+ sizeof( T_1 ) * V_58 -> V_60 . V_61 , V_62 ) ;
if ( ! V_2 ) {
F_7 ( L_13 ) ;
return F_25 ( - V_53 ) ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_59 = V_59 ;
V_2 -> V_24 = V_58 -> V_24 ;
V_2 -> V_52 = V_58 -> V_60 . V_61 ;
V_2 -> V_63 = F_27 ( V_2 -> V_52 , 8 ) ;
V_2 -> V_33 = F_27 ( V_2 -> V_63 , 8 ) ;
F_28 ( & V_2 -> V_11 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_52 ; V_19 ++ ) {
F_29 ( V_2 -> V_24 + V_19 ,
& V_64 ,
V_65 ) ;
F_30 ( V_2 -> V_24 + V_19 , V_2 ) ;
#ifdef F_31
F_32 ( V_2 -> V_24 + V_19 , V_66 ) ;
#else
F_33 ( V_2 -> V_24 + V_19 ) ;
#endif
}
F_34 ( V_59 , V_58 -> V_67 ) ;
F_35 ( V_59 , V_2 ) ;
F_36 ( V_59 , F_13 ) ;
F_37 ( V_59 , 1 ) ;
return V_2 ;
}
int F_38 ( struct V_1 * V_2 )
{
F_36 ( V_2 -> V_59 , NULL ) ;
F_39 ( V_2 ) ;
return 0 ;
}
