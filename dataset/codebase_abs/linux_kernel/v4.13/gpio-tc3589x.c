static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_7 + ( V_3 / 8 ) * 2 ;
T_1 V_8 = F_3 ( V_3 % 8 ) ;
int V_9 ;
V_9 = F_4 ( V_5 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
return ! ! ( V_9 & V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_3 , int V_10 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_7 + ( V_3 / 8 ) * 2 ;
unsigned int V_11 = V_3 % 8 ;
T_1 V_12 [] = { V_10 ? F_3 ( V_11 ) : 0 , F_3 (pos) } ;
F_6 ( V_5 , V_6 , F_7 ( V_12 ) , V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_10 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_13 + V_3 / 8 ;
unsigned int V_11 = V_3 % 8 ;
F_5 ( V_2 , V_3 , V_10 ) ;
return F_9 ( V_5 , V_6 , F_3 ( V_11 ) , F_3 ( V_11 ) ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_13 + V_3 / 8 ;
unsigned int V_11 = V_3 % 8 ;
return F_9 ( V_5 , V_6 , F_3 ( V_11 ) , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_13 + V_3 / 8 ;
unsigned int V_11 = V_3 % 8 ;
int V_9 ;
V_9 = F_4 ( V_5 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
return ! ( V_9 & F_3 ( V_11 ) ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned long V_14 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_15 = V_16 + ( V_3 / 8 ) * 2 ;
T_1 V_17 = V_18 + ( V_3 / 8 ) * 2 ;
unsigned int V_11 = V_3 % 8 ;
int V_9 ;
switch ( F_13 ( V_14 ) ) {
case V_19 :
V_9 = F_9 ( V_5 , V_15 , F_3 ( V_11 ) , 0 ) ;
if ( V_9 )
return V_9 ;
return F_9 ( V_5 , V_17 , F_3 ( V_11 ) , F_3 ( V_11 ) ) ;
case V_20 :
V_9 = F_9 ( V_5 , V_15 , F_3 ( V_11 ) , F_3 ( V_11 ) ) ;
if ( V_9 )
return V_9 ;
return F_9 ( V_5 , V_17 , F_3 ( V_11 ) , F_3 ( V_11 ) ) ;
case V_21 :
return F_9 ( V_5 , V_17 , F_3 ( V_11 ) , 0 ) ;
default:
break;
}
return - V_22 ;
}
static int F_14 ( struct V_23 * V_24 , unsigned int type )
{
struct V_1 * V_25 = F_15 ( V_24 ) ;
struct V_4 * V_4 = F_2 ( V_25 ) ;
int V_3 = V_24 -> V_26 ;
int V_27 = V_3 / 8 ;
int V_8 = F_3 ( V_3 % 8 ) ;
if ( type == V_28 ) {
V_4 -> V_29 [ V_30 ] [ V_27 ] |= V_8 ;
return 0 ;
}
V_4 -> V_29 [ V_30 ] [ V_27 ] &= ~ V_8 ;
if ( type == V_31 || type == V_32 )
V_4 -> V_29 [ V_33 ] [ V_27 ] |= V_8 ;
else
V_4 -> V_29 [ V_33 ] [ V_27 ] &= ~ V_8 ;
if ( type == V_34 || type == V_32 )
V_4 -> V_29 [ V_35 ] [ V_27 ] |= V_8 ;
else
V_4 -> V_29 [ V_35 ] [ V_27 ] &= ~ V_8 ;
return 0 ;
}
static void F_16 ( struct V_23 * V_24 )
{
struct V_1 * V_25 = F_15 ( V_24 ) ;
struct V_4 * V_4 = F_2 ( V_25 ) ;
F_17 ( & V_4 -> V_36 ) ;
}
static void F_18 ( struct V_23 * V_24 )
{
struct V_1 * V_25 = F_15 ( V_24 ) ;
struct V_4 * V_4 = F_2 ( V_25 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
static const T_1 V_37 [] = {
[ V_30 ] = V_38 ,
[ V_35 ] = V_39 ,
[ V_33 ] = V_40 ,
[ V_41 ] = V_42 ,
} ;
int V_43 , V_44 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ ) {
T_1 V_47 = V_4 -> V_48 [ V_43 ] [ V_44 ] ;
T_1 V_49 = V_4 -> V_29 [ V_43 ] [ V_44 ] ;
if ( V_49 == V_47 )
continue;
V_4 -> V_48 [ V_43 ] [ V_44 ] = V_49 ;
F_19 ( V_5 , V_37 [ V_43 ] + V_44 * 8 , V_49 ) ;
}
}
F_20 ( & V_4 -> V_36 ) ;
}
static void F_21 ( struct V_23 * V_24 )
{
struct V_1 * V_25 = F_15 ( V_24 ) ;
struct V_4 * V_4 = F_2 ( V_25 ) ;
int V_3 = V_24 -> V_26 ;
int V_27 = V_3 / 8 ;
int V_8 = F_3 ( V_3 % 8 ) ;
V_4 -> V_29 [ V_41 ] [ V_27 ] &= ~ V_8 ;
}
static void F_22 ( struct V_23 * V_24 )
{
struct V_1 * V_25 = F_15 ( V_24 ) ;
struct V_4 * V_4 = F_2 ( V_25 ) ;
int V_3 = V_24 -> V_26 ;
int V_27 = V_3 / 8 ;
int V_8 = F_3 ( V_3 % 8 ) ;
V_4 -> V_29 [ V_41 ] [ V_27 ] |= V_8 ;
}
static T_2 F_23 ( int V_50 , void * V_51 )
{
struct V_4 * V_4 = V_51 ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_52 [ V_46 ] ;
int V_9 ;
int V_43 ;
V_9 = F_24 ( V_5 , V_53 ,
F_7 ( V_52 ) , V_52 ) ;
if ( V_9 < 0 )
return V_54 ;
for ( V_43 = 0 ; V_43 < F_7 ( V_52 ) ; V_43 ++ ) {
unsigned int V_55 = V_52 [ V_43 ] ;
if ( ! V_55 )
continue;
while ( V_55 ) {
int V_56 = F_25 ( V_55 ) ;
int line = V_43 * 8 + V_56 ;
int V_50 = F_26 ( V_4 -> V_2 . V_57 ,
line ) ;
F_27 ( V_50 ) ;
V_55 &= ~ ( 1 << V_56 ) ;
}
F_19 ( V_5 , V_58 + V_43 , V_52 [ V_43 ] ) ;
}
return V_59 ;
}
static int F_28 ( struct V_60 * V_61 )
{
struct V_5 * V_5 = F_29 ( V_61 -> V_51 . V_62 ) ;
struct V_63 * V_64 = V_61 -> V_51 . V_65 ;
struct V_4 * V_4 ;
int V_9 ;
int V_50 ;
if ( ! V_64 ) {
F_30 ( & V_61 -> V_51 , L_1 ) ;
return - V_66 ;
}
V_50 = F_31 ( V_61 , 0 ) ;
if ( V_50 < 0 )
return V_50 ;
V_4 = F_32 ( & V_61 -> V_51 , sizeof( struct V_4 ) ,
V_67 ) ;
if ( ! V_4 )
return - V_68 ;
F_33 ( & V_4 -> V_36 ) ;
V_4 -> V_51 = & V_61 -> V_51 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_2 = V_69 ;
V_4 -> V_2 . V_70 = V_5 -> V_71 ;
V_4 -> V_2 . V_62 = & V_61 -> V_51 ;
V_4 -> V_2 . V_72 = - 1 ;
V_4 -> V_2 . V_65 = V_64 ;
V_9 = F_9 ( V_5 , V_73 ,
V_74 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_34 ( & V_61 -> V_51 ,
V_50 , NULL , F_23 ,
V_75 , L_2 ,
V_4 ) ;
if ( V_9 ) {
F_30 ( & V_61 -> V_51 , L_3 , V_9 ) ;
return V_9 ;
}
V_9 = F_35 ( & V_61 -> V_51 , & V_4 -> V_2 ,
V_4 ) ;
if ( V_9 ) {
F_30 ( & V_61 -> V_51 , L_4 , V_9 ) ;
return V_9 ;
}
V_9 = F_36 ( & V_4 -> V_2 ,
& V_76 ,
0 ,
V_77 ,
V_78 ) ;
if ( V_9 ) {
F_30 ( & V_61 -> V_51 ,
L_5 ) ;
return V_9 ;
}
F_37 ( & V_4 -> V_2 ,
& V_76 ,
V_50 ) ;
F_38 ( V_61 , V_4 ) ;
return 0 ;
}
static int T_3 F_39 ( void )
{
return F_40 ( & V_79 ) ;
}
