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
static int F_11 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return V_1 -> V_14 + V_4 ;
}
static int F_12 ( struct V_15 * V_16 , unsigned int type )
{
struct V_1 * V_1 = F_13 ( V_16 ) ;
int V_4 = V_16 -> V_17 - V_1 -> V_14 ;
int V_18 = V_4 / 8 ;
int V_8 = 1 << ( V_4 % 8 ) ;
if ( type == V_19 ) {
V_1 -> V_20 [ V_21 ] [ V_18 ] |= V_8 ;
return 0 ;
}
V_1 -> V_20 [ V_21 ] [ V_18 ] &= ~ V_8 ;
if ( type == V_22 || type == V_23 )
V_1 -> V_20 [ V_24 ] [ V_18 ] |= V_8 ;
else
V_1 -> V_20 [ V_24 ] [ V_18 ] &= ~ V_8 ;
if ( type == V_25 || type == V_23 )
V_1 -> V_20 [ V_26 ] [ V_18 ] |= V_8 ;
else
V_1 -> V_20 [ V_26 ] [ V_18 ] &= ~ V_8 ;
return 0 ;
}
static void F_14 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_13 ( V_16 ) ;
F_15 ( & V_1 -> V_27 ) ;
}
static void F_16 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_13 ( V_16 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
static const T_1 V_28 [] = {
[ V_21 ] = V_29 ,
[ V_26 ] = V_30 ,
[ V_24 ] = V_31 ,
[ V_32 ] = V_33 ,
} ;
int V_34 , V_35 ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ ) {
for ( V_35 = 0 ; V_35 < V_37 ; V_35 ++ ) {
T_1 V_38 = V_1 -> V_39 [ V_34 ] [ V_35 ] ;
T_1 V_40 = V_1 -> V_20 [ V_34 ] [ V_35 ] ;
if ( V_40 == V_38 )
continue;
V_1 -> V_39 [ V_34 ] [ V_35 ] = V_40 ;
F_17 ( V_5 , V_28 [ V_34 ] + V_35 * 8 , V_40 ) ;
}
}
F_18 ( & V_1 -> V_27 ) ;
}
static void F_19 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_13 ( V_16 ) ;
int V_4 = V_16 -> V_17 - V_1 -> V_14 ;
int V_18 = V_4 / 8 ;
int V_8 = 1 << ( V_4 % 8 ) ;
V_1 -> V_20 [ V_32 ] [ V_18 ] &= ~ V_8 ;
}
static void F_20 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_13 ( V_16 ) ;
int V_4 = V_16 -> V_17 - V_1 -> V_14 ;
int V_18 = V_4 / 8 ;
int V_8 = 1 << ( V_4 % 8 ) ;
V_1 -> V_20 [ V_32 ] [ V_18 ] |= V_8 ;
}
static T_2 F_21 ( int V_17 , void * V_41 )
{
struct V_1 * V_1 = V_41 ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_42 [ V_37 ] ;
int V_9 ;
int V_34 ;
V_9 = F_22 ( V_5 , V_43 ,
F_7 ( V_42 ) , V_42 ) ;
if ( V_9 < 0 )
return V_44 ;
for ( V_34 = 0 ; V_34 < F_7 ( V_42 ) ; V_34 ++ ) {
unsigned int V_45 = V_42 [ V_34 ] ;
if ( ! V_45 )
continue;
while ( V_45 ) {
int V_46 = F_23 ( V_45 ) ;
int line = V_34 * 8 + V_46 ;
F_24 ( V_1 -> V_14 + line ) ;
V_45 &= ~ ( 1 << V_46 ) ;
}
F_17 ( V_5 , V_47 + V_34 , V_42 [ V_34 ] ) ;
}
return V_48 ;
}
static int F_25 ( struct V_1 * V_1 )
{
int V_49 = V_1 -> V_14 ;
int V_17 ;
for ( V_17 = V_49 ; V_17 < V_49 + V_1 -> V_3 . V_50 ; V_17 ++ ) {
F_26 ( V_17 , V_1 ) ;
F_27 ( V_17 , & V_51 ,
V_52 ) ;
F_28 ( V_17 , 1 ) ;
#ifdef F_29
F_30 ( V_17 , V_53 ) ;
#else
F_31 ( V_17 ) ;
#endif
}
return 0 ;
}
static void F_32 ( struct V_1 * V_1 )
{
int V_49 = V_1 -> V_14 ;
int V_17 ;
for ( V_17 = V_49 ; V_17 < V_49 + V_1 -> V_3 . V_50 ; V_17 ++ ) {
#ifdef F_29
F_30 ( V_17 , 0 ) ;
#endif
F_27 ( V_17 , NULL , NULL ) ;
F_26 ( V_17 , NULL ) ;
}
}
static int T_3 F_33 ( struct V_54 * V_55 )
{
struct V_5 * V_5 = F_34 ( V_55 -> V_41 . V_56 ) ;
struct V_57 * V_58 ;
struct V_1 * V_1 ;
int V_9 ;
int V_17 ;
V_58 = V_5 -> V_58 -> V_59 ;
if ( ! V_58 )
return - V_60 ;
V_17 = F_35 ( V_55 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_1 = F_36 ( sizeof( struct V_1 ) , V_61 ) ;
if ( ! V_1 )
return - V_62 ;
F_37 ( & V_1 -> V_27 ) ;
V_1 -> V_41 = & V_55 -> V_41 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_3 = V_63 ;
V_1 -> V_3 . V_50 = V_5 -> V_64 ;
V_1 -> V_3 . V_41 = & V_55 -> V_41 ;
V_1 -> V_3 . V_49 = V_58 -> V_65 ;
V_1 -> V_14 = V_5 -> V_14 + F_38 ( 0 ) ;
V_9 = F_9 ( V_5 , V_66 ,
V_67 , 0 ) ;
if ( V_9 < 0 )
goto V_68;
V_9 = F_25 ( V_1 ) ;
if ( V_9 )
goto V_68;
V_9 = F_39 ( V_17 , NULL , F_21 , V_69 ,
L_1 , V_1 ) ;
if ( V_9 ) {
F_40 ( & V_55 -> V_41 , L_2 , V_9 ) ;
goto V_70;
}
V_9 = F_41 ( & V_1 -> V_3 ) ;
if ( V_9 ) {
F_40 ( & V_55 -> V_41 , L_3 , V_9 ) ;
goto V_71;
}
if ( V_58 -> V_72 )
V_58 -> V_72 ( V_5 , V_1 -> V_3 . V_49 ) ;
F_42 ( V_55 , V_1 ) ;
return 0 ;
V_71:
F_43 ( V_17 , V_1 ) ;
V_70:
F_32 ( V_1 ) ;
V_68:
F_44 ( V_1 ) ;
return V_9 ;
}
static int T_4 F_45 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_46 ( V_55 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
struct V_57 * V_58 = V_5 -> V_58 -> V_59 ;
int V_17 = F_35 ( V_55 , 0 ) ;
int V_9 ;
if ( V_58 -> remove )
V_58 -> remove ( V_5 , V_1 -> V_3 . V_49 ) ;
V_9 = F_47 ( & V_1 -> V_3 ) ;
if ( V_9 < 0 ) {
F_40 ( V_1 -> V_41 ,
L_4 , V_9 ) ;
return V_9 ;
}
F_43 ( V_17 , V_1 ) ;
F_32 ( V_1 ) ;
F_42 ( V_55 , NULL ) ;
F_44 ( V_1 ) ;
return 0 ;
}
static int T_5 F_48 ( void )
{
return F_49 ( & V_73 ) ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_73 ) ;
}
