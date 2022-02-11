static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_7 + ( V_4 / 8 ) * 2 ;
T_1 V_8 = 1 << ( V_4 % 8 ) ;
int V_9 ;
V_9 = F_4 ( V_5 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_9 & V_8 ;
}
static void F_5 ( struct V_2 * V_3 , unsigned V_4 , int V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_7 + ( V_4 / 8 ) * 2 ;
unsigned V_11 = V_4 % 8 ;
T_1 V_12 [] = { ! ! V_10 << V_11 , 1 << V_11 } ;
F_6 ( V_5 , V_6 , F_7 ( V_12 ) , V_12 ) ;
}
static int F_8 ( struct V_2 * V_3 ,
unsigned V_4 , int V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_13 + V_4 / 8 ;
unsigned V_11 = V_4 % 8 ;
F_5 ( V_3 , V_4 , V_10 ) ;
return F_9 ( V_5 , V_6 , 1 << V_11 , 1 << V_11 ) ;
}
static int F_10 ( struct V_2 * V_3 ,
unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_13 + V_4 / 8 ;
unsigned V_11 = V_4 % 8 ;
return F_9 ( V_5 , V_6 , 1 << V_11 , 0 ) ;
}
static int F_11 ( struct V_1 * V_1 ,
int V_14 )
{
if ( ! V_1 )
return - V_15 ;
return F_12 ( V_1 -> V_16 , V_14 ) ;
}
static int F_13 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_11 ( V_1 , V_4 ) ;
}
static int F_14 ( struct V_17 * V_18 , unsigned int type )
{
struct V_1 * V_1 = F_15 ( V_18 ) ;
int V_4 = V_18 -> V_14 ;
int V_19 = V_4 / 8 ;
int V_8 = 1 << ( V_4 % 8 ) ;
if ( type == V_20 ) {
V_1 -> V_21 [ V_22 ] [ V_19 ] |= V_8 ;
return 0 ;
}
V_1 -> V_21 [ V_22 ] [ V_19 ] &= ~ V_8 ;
if ( type == V_23 || type == V_24 )
V_1 -> V_21 [ V_25 ] [ V_19 ] |= V_8 ;
else
V_1 -> V_21 [ V_25 ] [ V_19 ] &= ~ V_8 ;
if ( type == V_26 || type == V_24 )
V_1 -> V_21 [ V_27 ] [ V_19 ] |= V_8 ;
else
V_1 -> V_21 [ V_27 ] [ V_19 ] &= ~ V_8 ;
return 0 ;
}
static void F_16 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_15 ( V_18 ) ;
F_17 ( & V_1 -> V_28 ) ;
}
static void F_18 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_15 ( V_18 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
static const T_1 V_29 [] = {
[ V_22 ] = V_30 ,
[ V_27 ] = V_31 ,
[ V_25 ] = V_32 ,
[ V_33 ] = V_34 ,
} ;
int V_35 , V_36 ;
for ( V_35 = 0 ; V_35 < V_37 ; V_35 ++ ) {
for ( V_36 = 0 ; V_36 < V_38 ; V_36 ++ ) {
T_1 V_39 = V_1 -> V_40 [ V_35 ] [ V_36 ] ;
T_1 V_41 = V_1 -> V_21 [ V_35 ] [ V_36 ] ;
if ( V_41 == V_39 )
continue;
V_1 -> V_40 [ V_35 ] [ V_36 ] = V_41 ;
F_19 ( V_5 , V_29 [ V_35 ] + V_36 * 8 , V_41 ) ;
}
}
F_20 ( & V_1 -> V_28 ) ;
}
static void F_21 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_15 ( V_18 ) ;
int V_4 = V_18 -> V_14 ;
int V_19 = V_4 / 8 ;
int V_8 = 1 << ( V_4 % 8 ) ;
V_1 -> V_21 [ V_33 ] [ V_19 ] &= ~ V_8 ;
}
static void F_22 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_15 ( V_18 ) ;
int V_4 = V_18 -> V_14 ;
int V_19 = V_4 / 8 ;
int V_8 = 1 << ( V_4 % 8 ) ;
V_1 -> V_21 [ V_33 ] [ V_19 ] |= V_8 ;
}
static T_2 F_23 ( int V_42 , void * V_43 )
{
struct V_1 * V_1 = V_43 ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_44 [ V_38 ] ;
int V_9 ;
int V_35 ;
V_9 = F_24 ( V_5 , V_45 ,
F_7 ( V_44 ) , V_44 ) ;
if ( V_9 < 0 )
return V_46 ;
for ( V_35 = 0 ; V_35 < F_7 ( V_44 ) ; V_35 ++ ) {
unsigned int V_47 = V_44 [ V_35 ] ;
if ( ! V_47 )
continue;
while ( V_47 ) {
int V_48 = F_25 ( V_47 ) ;
int line = V_35 * 8 + V_48 ;
int V_42 = F_11 ( V_1 , line ) ;
F_26 ( V_42 ) ;
V_47 &= ~ ( 1 << V_48 ) ;
}
F_19 ( V_5 , V_49 + V_35 , V_44 [ V_35 ] ) ;
}
return V_50 ;
}
static int F_27 ( struct V_51 * V_18 , unsigned int V_42 ,
T_3 V_14 )
{
struct V_5 * V_1 = V_18 -> V_52 ;
F_28 ( V_42 , V_1 ) ;
F_29 ( V_42 , & V_53 ,
V_54 ) ;
F_30 ( V_42 , 1 ) ;
#ifdef F_31
F_32 ( V_42 , V_55 ) ;
#else
F_33 ( V_42 ) ;
#endif
return 0 ;
}
static void F_34 ( struct V_51 * V_18 , unsigned int V_42 )
{
#ifdef F_31
F_32 ( V_42 , 0 ) ;
#endif
F_29 ( V_42 , NULL , NULL ) ;
F_28 ( V_42 , NULL ) ;
}
static int F_35 ( struct V_1 * V_1 ,
struct V_56 * V_57 )
{
int V_58 = V_1 -> V_59 ;
V_1 -> V_16 = F_36 ( V_57 ,
V_1 -> V_3 . V_60 , V_58 , & V_61 ,
V_1 ) ;
if ( ! V_1 -> V_16 ) {
F_37 ( V_1 -> V_43 , L_1 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_38 ( struct V_63 * V_64 )
{
struct V_5 * V_5 = F_39 ( V_64 -> V_43 . V_65 ) ;
struct V_66 * V_67 ;
struct V_56 * V_57 = V_64 -> V_43 . V_68 ;
struct V_1 * V_1 ;
int V_9 ;
int V_42 ;
V_67 = V_5 -> V_67 -> V_69 ;
if ( ! ( V_67 || V_57 ) ) {
F_37 ( & V_64 -> V_43 , L_2 ) ;
return - V_15 ;
}
V_42 = F_40 ( V_64 , 0 ) ;
if ( V_42 < 0 )
return V_42 ;
V_1 = F_41 ( sizeof( struct V_1 ) , V_70 ) ;
if ( ! V_1 )
return - V_71 ;
F_42 ( & V_1 -> V_28 ) ;
V_1 -> V_43 = & V_64 -> V_43 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_3 = V_72 ;
V_1 -> V_3 . V_60 = V_5 -> V_73 ;
V_1 -> V_3 . V_43 = & V_64 -> V_43 ;
V_1 -> V_3 . V_58 = ( V_67 ) ? V_67 -> V_74 : - 1 ;
#ifdef F_43
V_1 -> V_3 . V_68 = V_57 ;
#endif
V_1 -> V_59 = V_5 -> V_59 ?
V_5 -> V_59 + F_44 ( 0 ) : 0 ;
V_9 = F_9 ( V_5 , V_75 ,
V_76 , 0 ) ;
if ( V_9 < 0 )
goto V_77;
V_9 = F_35 ( V_1 , V_57 ) ;
if ( V_9 )
goto V_77;
V_9 = F_45 ( V_42 , NULL , F_23 , V_78 ,
L_3 , V_1 ) ;
if ( V_9 ) {
F_37 ( & V_64 -> V_43 , L_4 , V_9 ) ;
goto V_77;
}
V_9 = F_46 ( & V_1 -> V_3 ) ;
if ( V_9 ) {
F_37 ( & V_64 -> V_43 , L_5 , V_9 ) ;
goto V_79;
}
if ( V_67 && V_67 -> V_80 )
V_67 -> V_80 ( V_5 , V_1 -> V_3 . V_58 ) ;
F_47 ( V_64 , V_1 ) ;
return 0 ;
V_79:
F_48 ( V_42 , V_1 ) ;
V_77:
F_49 ( V_1 ) ;
return V_9 ;
}
static int F_50 ( struct V_63 * V_64 )
{
struct V_1 * V_1 = F_51 ( V_64 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
struct V_66 * V_67 = V_5 -> V_67 -> V_69 ;
int V_42 = F_40 ( V_64 , 0 ) ;
int V_9 ;
if ( V_67 && V_67 -> remove )
V_67 -> remove ( V_5 , V_1 -> V_3 . V_58 ) ;
V_9 = F_52 ( & V_1 -> V_3 ) ;
if ( V_9 < 0 ) {
F_37 ( V_1 -> V_43 ,
L_6 , V_9 ) ;
return V_9 ;
}
F_48 ( V_42 , V_1 ) ;
F_49 ( V_1 ) ;
return 0 ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_81 ) ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_81 ) ;
}
