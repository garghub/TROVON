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
int V_4 = V_18 -> V_19 ;
int V_20 = V_4 / 8 ;
int V_8 = 1 << ( V_4 % 8 ) ;
if ( type == V_21 ) {
V_1 -> V_22 [ V_23 ] [ V_20 ] |= V_8 ;
return 0 ;
}
V_1 -> V_22 [ V_23 ] [ V_20 ] &= ~ V_8 ;
if ( type == V_24 || type == V_25 )
V_1 -> V_22 [ V_26 ] [ V_20 ] |= V_8 ;
else
V_1 -> V_22 [ V_26 ] [ V_20 ] &= ~ V_8 ;
if ( type == V_27 || type == V_25 )
V_1 -> V_22 [ V_28 ] [ V_20 ] |= V_8 ;
else
V_1 -> V_22 [ V_28 ] [ V_20 ] &= ~ V_8 ;
return 0 ;
}
static void F_16 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_15 ( V_18 ) ;
F_17 ( & V_1 -> V_29 ) ;
}
static void F_18 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_15 ( V_18 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
static const T_1 V_30 [] = {
[ V_23 ] = V_31 ,
[ V_28 ] = V_32 ,
[ V_26 ] = V_33 ,
[ V_34 ] = V_35 ,
} ;
int V_36 , V_37 ;
for ( V_36 = 0 ; V_36 < V_38 ; V_36 ++ ) {
for ( V_37 = 0 ; V_37 < V_39 ; V_37 ++ ) {
T_1 V_40 = V_1 -> V_41 [ V_36 ] [ V_37 ] ;
T_1 V_42 = V_1 -> V_22 [ V_36 ] [ V_37 ] ;
if ( V_42 == V_40 )
continue;
V_1 -> V_41 [ V_36 ] [ V_37 ] = V_42 ;
F_19 ( V_5 , V_30 [ V_36 ] + V_37 * 8 , V_42 ) ;
}
}
F_20 ( & V_1 -> V_29 ) ;
}
static void F_21 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_15 ( V_18 ) ;
int V_4 = V_18 -> V_19 ;
int V_20 = V_4 / 8 ;
int V_8 = 1 << ( V_4 % 8 ) ;
V_1 -> V_22 [ V_34 ] [ V_20 ] &= ~ V_8 ;
}
static void F_22 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_15 ( V_18 ) ;
int V_4 = V_18 -> V_19 ;
int V_20 = V_4 / 8 ;
int V_8 = 1 << ( V_4 % 8 ) ;
V_1 -> V_22 [ V_34 ] [ V_20 ] |= V_8 ;
}
static T_2 F_23 ( int V_14 , void * V_43 )
{
struct V_1 * V_1 = V_43 ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_44 [ V_39 ] ;
int V_9 ;
int V_36 ;
V_9 = F_24 ( V_5 , V_45 ,
F_7 ( V_44 ) , V_44 ) ;
if ( V_9 < 0 )
return V_46 ;
for ( V_36 = 0 ; V_36 < F_7 ( V_44 ) ; V_36 ++ ) {
unsigned int V_47 = V_44 [ V_36 ] ;
if ( ! V_47 )
continue;
while ( V_47 ) {
int V_48 = F_25 ( V_47 ) ;
int line = V_36 * 8 + V_48 ;
int V_49 = F_11 ( V_1 , line ) ;
F_26 ( V_49 ) ;
V_47 &= ~ ( 1 << V_48 ) ;
}
F_19 ( V_5 , V_50 + V_36 , V_44 [ V_36 ] ) ;
}
return V_51 ;
}
static int F_27 ( struct V_52 * V_18 , unsigned int V_49 ,
T_3 V_19 )
{
struct V_5 * V_1 = V_18 -> V_53 ;
F_28 ( V_49 , V_1 ) ;
F_29 ( V_49 , & V_54 ,
V_55 ) ;
F_30 ( V_49 , 1 ) ;
#ifdef F_31
F_32 ( V_49 , V_56 ) ;
#else
F_33 ( V_49 ) ;
#endif
return 0 ;
}
static void F_34 ( struct V_52 * V_18 , unsigned int V_49 )
{
#ifdef F_31
F_32 ( V_49 , 0 ) ;
#endif
F_29 ( V_49 , NULL , NULL ) ;
F_28 ( V_49 , NULL ) ;
}
static int F_35 ( struct V_1 * V_1 ,
struct V_57 * V_58 )
{
int V_59 = V_1 -> V_60 ;
if ( V_59 ) {
V_1 -> V_16 = F_36 (
NULL , V_1 -> V_3 . V_61 , V_59 ,
0 , & V_62 , V_1 ) ;
}
else {
V_1 -> V_16 = F_37 (
V_58 , V_1 -> V_3 . V_61 ,
& V_62 , V_1 ) ;
}
if ( ! V_1 -> V_16 ) {
F_38 ( V_1 -> V_43 , L_1 ) ;
return - V_63 ;
}
return 0 ;
}
static int T_4 F_39 ( struct V_64 * V_65 )
{
struct V_5 * V_5 = F_40 ( V_65 -> V_43 . V_66 ) ;
struct V_67 * V_68 ;
struct V_57 * V_58 = V_65 -> V_43 . V_69 ;
struct V_1 * V_1 ;
int V_9 ;
int V_14 ;
V_68 = V_5 -> V_68 -> V_70 ;
if ( ! ( V_68 || V_58 ) ) {
F_38 ( & V_65 -> V_43 , L_2 ) ;
return - V_15 ;
}
V_14 = F_41 ( V_65 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
V_1 = F_42 ( sizeof( struct V_1 ) , V_71 ) ;
if ( ! V_1 )
return - V_72 ;
F_43 ( & V_1 -> V_29 ) ;
V_1 -> V_43 = & V_65 -> V_43 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_3 = V_73 ;
V_1 -> V_3 . V_61 = V_5 -> V_74 ;
V_1 -> V_3 . V_43 = & V_65 -> V_43 ;
V_1 -> V_3 . V_59 = ( V_68 ) ? V_68 -> V_75 : - 1 ;
#ifdef F_44
V_1 -> V_3 . V_69 = V_58 ;
#endif
V_1 -> V_60 = V_5 -> V_60 ?
V_5 -> V_60 + F_45 ( 0 ) : 0 ;
V_9 = F_9 ( V_5 , V_76 ,
V_77 , 0 ) ;
if ( V_9 < 0 )
goto V_78;
V_9 = F_35 ( V_1 , V_58 ) ;
if ( V_9 )
goto V_78;
V_9 = F_46 ( V_14 , NULL , F_23 , V_79 ,
L_3 , V_1 ) ;
if ( V_9 ) {
F_38 ( & V_65 -> V_43 , L_4 , V_9 ) ;
goto V_78;
}
V_9 = F_47 ( & V_1 -> V_3 ) ;
if ( V_9 ) {
F_38 ( & V_65 -> V_43 , L_5 , V_9 ) ;
goto V_80;
}
if ( V_68 && V_68 -> V_81 )
V_68 -> V_81 ( V_5 , V_1 -> V_3 . V_59 ) ;
F_48 ( V_65 , V_1 ) ;
return 0 ;
V_80:
F_49 ( V_14 , V_1 ) ;
V_78:
F_50 ( V_1 ) ;
return V_9 ;
}
static int T_5 F_51 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_52 ( V_65 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
struct V_67 * V_68 = V_5 -> V_68 -> V_70 ;
int V_14 = F_41 ( V_65 , 0 ) ;
int V_9 ;
if ( V_68 && V_68 -> remove )
V_68 -> remove ( V_5 , V_1 -> V_3 . V_59 ) ;
V_9 = F_53 ( & V_1 -> V_3 ) ;
if ( V_9 < 0 ) {
F_38 ( V_1 -> V_43 ,
L_6 , V_9 ) ;
return V_9 ;
}
F_49 ( V_14 , V_1 ) ;
F_48 ( V_65 , NULL ) ;
F_50 ( V_1 ) ;
return 0 ;
}
static int T_6 F_54 ( void )
{
return F_55 ( & V_82 ) ;
}
static void T_7 F_56 ( void )
{
F_57 ( & V_82 ) ;
}
