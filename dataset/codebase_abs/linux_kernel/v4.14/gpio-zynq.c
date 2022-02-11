static int F_1 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 -> V_4 & V_5 ) ;
}
static int F_2 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 -> V_4 & V_6 ) ;
}
static inline void F_3 ( unsigned int V_7 ,
unsigned int * V_8 ,
unsigned int * V_9 ,
struct V_1 * V_2 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_3 -> V_11 ; V_10 ++ ) {
if ( ( V_7 >= V_2 -> V_3 -> V_12 [ V_10 ] ) &&
( V_7 <= V_2 -> V_3 -> V_13 [ V_10 ] ) ) {
* V_8 = V_10 ;
* V_9 = V_7 -
V_2 -> V_3 -> V_12 [ V_10 ] ;
return;
}
}
F_4 ( true , L_1 , V_7 ) ;
* V_8 = 0 ;
* V_9 = 0 ;
}
static int F_5 ( struct V_14 * V_15 , unsigned int V_16 )
{
T_1 V_17 ;
unsigned int V_8 , V_9 ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
F_3 ( V_16 , & V_8 , & V_9 , V_2 ) ;
if ( F_2 ( V_2 ) ) {
if ( F_1 ( V_2 ) ) {
if ( V_8 <= 1 ) {
V_17 = F_7 ( V_2 -> V_18 +
F_8 ( V_8 ) ) ;
} else {
V_17 = F_7 ( V_2 -> V_18 +
F_9 ( V_8 ) ) ;
}
} else {
if ( V_8 <= 2 ) {
V_17 = F_7 ( V_2 -> V_18 +
F_8 ( V_8 ) ) ;
} else {
V_17 = F_7 ( V_2 -> V_18 +
F_9 ( V_8 ) ) ;
}
}
} else {
V_17 = F_7 ( V_2 -> V_18 +
F_8 ( V_8 ) ) ;
}
return ( V_17 >> V_9 ) & 1 ;
}
static void F_10 ( struct V_14 * V_15 , unsigned int V_16 ,
int V_19 )
{
unsigned int V_20 , V_8 , V_9 ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
F_3 ( V_16 , & V_8 , & V_9 , V_2 ) ;
if ( V_9 >= V_21 ) {
V_9 -= V_21 ;
V_20 = F_11 ( V_8 ) ;
} else {
V_20 = F_12 ( V_8 ) ;
}
V_19 = ! ! V_19 ;
V_19 = ~ ( 1 << ( V_9 + V_21 ) ) &
( ( V_19 << V_9 ) | V_22 ) ;
F_13 ( V_19 , V_2 -> V_18 + V_20 ) ;
}
static int F_14 ( struct V_14 * V_15 , unsigned int V_16 )
{
T_1 V_23 ;
unsigned int V_8 , V_9 ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
F_3 ( V_16 , & V_8 , & V_9 , V_2 ) ;
if ( F_1 ( V_2 ) && V_8 == 0 &&
( V_9 == 7 || V_9 == 8 ) )
return - V_24 ;
V_23 = F_7 ( V_2 -> V_18 + F_15 ( V_8 ) ) ;
V_23 &= ~ F_16 ( V_9 ) ;
F_13 ( V_23 , V_2 -> V_18 + F_15 ( V_8 ) ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 , unsigned int V_16 ,
int V_19 )
{
T_1 V_23 ;
unsigned int V_8 , V_9 ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
F_3 ( V_16 , & V_8 , & V_9 , V_2 ) ;
V_23 = F_7 ( V_2 -> V_18 + F_15 ( V_8 ) ) ;
V_23 |= F_16 ( V_9 ) ;
F_13 ( V_23 , V_2 -> V_18 + F_15 ( V_8 ) ) ;
V_23 = F_7 ( V_2 -> V_18 + F_18 ( V_8 ) ) ;
V_23 |= F_16 ( V_9 ) ;
F_13 ( V_23 , V_2 -> V_18 + F_18 ( V_8 ) ) ;
F_10 ( V_15 , V_16 , V_19 ) ;
return 0 ;
}
static void F_19 ( struct V_25 * V_25 )
{
unsigned int V_26 , V_8 , V_9 ;
struct V_1 * V_2 =
F_6 ( F_20 ( V_25 ) ) ;
V_26 = V_25 -> V_27 ;
F_3 ( V_26 , & V_8 , & V_9 , V_2 ) ;
F_13 ( F_16 ( V_9 ) ,
V_2 -> V_18 + F_21 ( V_8 ) ) ;
}
static void F_22 ( struct V_25 * V_25 )
{
unsigned int V_26 , V_8 , V_9 ;
struct V_1 * V_2 =
F_6 ( F_20 ( V_25 ) ) ;
V_26 = V_25 -> V_27 ;
F_3 ( V_26 , & V_8 , & V_9 , V_2 ) ;
F_13 ( F_16 ( V_9 ) ,
V_2 -> V_18 + F_23 ( V_8 ) ) ;
}
static void F_24 ( struct V_25 * V_25 )
{
unsigned int V_26 , V_8 , V_9 ;
struct V_1 * V_2 =
F_6 ( F_20 ( V_25 ) ) ;
V_26 = V_25 -> V_27 ;
F_3 ( V_26 , & V_8 , & V_9 , V_2 ) ;
F_13 ( F_16 ( V_9 ) ,
V_2 -> V_18 + F_25 ( V_8 ) ) ;
}
static void F_26 ( struct V_25 * V_25 )
{
F_24 ( V_25 ) ;
F_22 ( V_25 ) ;
}
static int F_27 ( struct V_25 * V_25 , unsigned int type )
{
T_1 V_28 , V_29 , V_30 ;
unsigned int V_26 , V_8 , V_9 ;
struct V_1 * V_2 =
F_6 ( F_20 ( V_25 ) ) ;
V_26 = V_25 -> V_27 ;
F_3 ( V_26 , & V_8 , & V_9 , V_2 ) ;
V_28 = F_7 ( V_2 -> V_18 +
F_28 ( V_8 ) ) ;
V_29 = F_7 ( V_2 -> V_18 +
F_29 ( V_8 ) ) ;
V_30 = F_7 ( V_2 -> V_18 +
F_30 ( V_8 ) ) ;
switch ( type ) {
case V_31 :
V_28 |= F_16 ( V_9 ) ;
V_29 |= F_16 ( V_9 ) ;
V_30 &= ~ F_16 ( V_9 ) ;
break;
case V_32 :
V_28 |= F_16 ( V_9 ) ;
V_29 &= ~ F_16 ( V_9 ) ;
V_30 &= ~ F_16 ( V_9 ) ;
break;
case V_33 :
V_28 |= F_16 ( V_9 ) ;
V_30 |= F_16 ( V_9 ) ;
break;
case V_34 :
V_28 &= ~ F_16 ( V_9 ) ;
V_29 |= F_16 ( V_9 ) ;
break;
case V_35 :
V_28 &= ~ F_16 ( V_9 ) ;
V_29 &= ~ F_16 ( V_9 ) ;
break;
default:
return - V_24 ;
}
F_13 ( V_28 ,
V_2 -> V_18 + F_28 ( V_8 ) ) ;
F_13 ( V_29 ,
V_2 -> V_18 + F_29 ( V_8 ) ) ;
F_13 ( V_30 ,
V_2 -> V_18 + F_30 ( V_8 ) ) ;
if ( type & V_36 )
F_31 ( V_25 ,
& V_37 ,
V_38 , NULL ) ;
else
F_31 ( V_25 ,
& V_39 ,
V_40 , NULL ) ;
return 0 ;
}
static int F_32 ( struct V_25 * V_17 , unsigned int V_41 )
{
struct V_1 * V_2 =
F_6 ( F_20 ( V_17 ) ) ;
F_33 ( V_2 -> V_42 , V_41 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 ,
unsigned int V_8 ,
unsigned long V_43 )
{
unsigned int V_44 = V_2 -> V_3 -> V_12 [ V_8 ] ;
struct V_45 * V_46 = V_2 -> V_15 . V_46 ;
int V_47 ;
if ( ! V_43 )
return;
F_35 (offset, &pending, 32 ) {
unsigned int V_48 ;
V_48 = F_36 ( V_46 , V_47 + V_44 ) ;
F_37 ( V_48 ) ;
}
}
static void F_38 ( struct V_49 * V_50 )
{
T_1 V_51 , V_52 ;
unsigned int V_8 ;
struct V_1 * V_2 =
F_6 ( F_39 ( V_50 ) ) ;
struct V_53 * V_54 = F_40 ( V_50 ) ;
F_41 ( V_54 , V_50 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_3 -> V_11 ; V_8 ++ ) {
V_51 = F_7 ( V_2 -> V_18 +
F_25 ( V_8 ) ) ;
V_52 = F_7 ( V_2 -> V_18 +
F_42 ( V_8 ) ) ;
F_34 ( V_2 , V_8 , V_51 & ~ V_52 ) ;
}
F_43 ( V_54 , V_50 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_3 -> V_11 ; V_8 ++ ) {
V_2 -> V_55 . V_56 [ V_8 ] =
F_7 ( V_2 -> V_18 +
F_12 ( V_8 ) ) ;
V_2 -> V_55 . V_57 [ V_8 ] =
F_7 ( V_2 -> V_18 +
F_11 ( V_8 ) ) ;
V_2 -> V_55 . V_58 [ V_8 ] = F_7 ( V_2 -> V_18 +
F_15 ( V_8 ) ) ;
V_2 -> V_55 . V_59 [ V_8 ] = F_7 ( V_2 -> V_18 +
F_42 ( V_8 ) ) ;
V_2 -> V_55 . V_28 [ V_8 ] =
F_7 ( V_2 -> V_18 +
F_28 ( V_8 ) ) ;
V_2 -> V_55 . V_60 [ V_8 ] =
F_7 ( V_2 -> V_18 +
F_29 ( V_8 ) ) ;
V_2 -> V_55 . V_30 [ V_8 ] =
F_7 ( V_2 -> V_18 +
F_30 ( V_8 ) ) ;
}
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_3 -> V_11 ; V_8 ++ ) {
F_13 ( V_2 -> V_55 . V_56 [ V_8 ] ,
V_2 -> V_18 +
F_12 ( V_8 ) ) ;
F_13 ( V_2 -> V_55 . V_57 [ V_8 ] ,
V_2 -> V_18 +
F_11 ( V_8 ) ) ;
F_13 ( V_2 -> V_55 . V_58 [ V_8 ] ,
V_2 -> V_18 +
F_15 ( V_8 ) ) ;
F_13 ( V_2 -> V_55 . V_59 [ V_8 ] ,
V_2 -> V_18 +
F_23 ( V_8 ) ) ;
F_13 ( V_2 -> V_55 . V_28 [ V_8 ] ,
V_2 -> V_18 +
F_28 ( V_8 ) ) ;
F_13 ( V_2 -> V_55 . V_60 [ V_8 ] ,
V_2 -> V_18 +
F_29 ( V_8 ) ) ;
F_13 ( V_2 -> V_55 . V_30 [ V_8 ] ,
V_2 -> V_18 +
F_30 ( V_8 ) ) ;
}
}
static int T_2 F_46 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_47 ( V_62 ) ;
int V_42 = F_48 ( V_64 , 0 ) ;
struct V_25 * V_17 = F_49 ( V_42 ) ;
struct V_1 * V_2 = F_50 ( V_64 ) ;
if ( ! F_51 ( V_17 ) ) {
F_44 ( V_2 ) ;
return F_52 ( V_62 ) ;
}
return 0 ;
}
static int T_2 F_53 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_47 ( V_62 ) ;
int V_42 = F_48 ( V_64 , 0 ) ;
struct V_25 * V_17 = F_49 ( V_42 ) ;
struct V_1 * V_2 = F_50 ( V_64 ) ;
int V_65 ;
if ( ! F_51 ( V_17 ) ) {
V_65 = F_54 ( V_62 ) ;
F_45 ( V_2 ) ;
return V_65 ;
}
return 0 ;
}
static int T_2 F_55 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_47 ( V_62 ) ;
struct V_1 * V_2 = F_50 ( V_64 ) ;
F_56 ( V_2 -> V_66 ) ;
return 0 ;
}
static int T_2 F_57 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_47 ( V_62 ) ;
struct V_1 * V_2 = F_50 ( V_64 ) ;
return F_58 ( V_2 -> V_66 ) ;
}
static int F_59 ( struct V_14 * V_15 , unsigned int V_47 )
{
int V_65 ;
V_65 = F_60 ( V_15 -> V_67 ) ;
return V_65 < 0 ? V_65 : 0 ;
}
static void F_61 ( struct V_14 * V_15 , unsigned int V_47 )
{
F_62 ( V_15 -> V_67 ) ;
}
static int F_63 ( struct V_63 * V_64 )
{
int V_65 , V_8 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_68 * V_69 ;
const struct V_70 * V_71 ;
V_2 = F_64 ( & V_64 -> V_62 , sizeof( * V_2 ) , V_72 ) ;
if ( ! V_2 )
return - V_73 ;
V_71 = F_65 ( V_74 , V_64 -> V_62 . V_75 ) ;
if ( ! V_71 ) {
F_66 ( & V_64 -> V_62 , L_2 ) ;
return - V_24 ;
}
V_2 -> V_3 = V_71 -> V_17 ;
F_67 ( V_64 , V_2 ) ;
V_69 = F_68 ( V_64 , V_76 , 0 ) ;
V_2 -> V_18 = F_69 ( & V_64 -> V_62 , V_69 ) ;
if ( F_70 ( V_2 -> V_18 ) )
return F_71 ( V_2 -> V_18 ) ;
V_2 -> V_42 = F_48 ( V_64 , 0 ) ;
if ( V_2 -> V_42 < 0 ) {
F_66 ( & V_64 -> V_62 , L_3 ) ;
return V_2 -> V_42 ;
}
V_15 = & V_2 -> V_15 ;
V_15 -> V_77 = V_2 -> V_3 -> V_77 ;
V_15 -> V_78 = V_79 ;
V_15 -> V_67 = & V_64 -> V_62 ;
V_15 -> V_80 = F_5 ;
V_15 -> V_81 = F_10 ;
V_15 -> V_82 = F_59 ;
V_15 -> free = F_61 ;
V_15 -> V_83 = F_14 ;
V_15 -> V_84 = F_17 ;
V_15 -> V_85 = - 1 ;
V_15 -> V_86 = V_2 -> V_3 -> V_86 ;
V_2 -> V_66 = F_72 ( & V_64 -> V_62 , NULL ) ;
if ( F_70 ( V_2 -> V_66 ) ) {
F_66 ( & V_64 -> V_62 , L_4 ) ;
return F_71 ( V_2 -> V_66 ) ;
}
V_65 = F_58 ( V_2 -> V_66 ) ;
if ( V_65 ) {
F_66 ( & V_64 -> V_62 , L_5 ) ;
return V_65 ;
}
F_73 ( & V_64 -> V_62 ) ;
F_74 ( & V_64 -> V_62 ) ;
V_65 = F_60 ( & V_64 -> V_62 ) ;
if ( V_65 < 0 )
goto V_87;
V_65 = F_75 ( V_15 , V_2 ) ;
if ( V_65 ) {
F_66 ( & V_64 -> V_62 , L_6 ) ;
goto V_88;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_3 -> V_11 ; V_8 ++ )
F_13 ( V_89 , V_2 -> V_18 +
F_21 ( V_8 ) ) ;
V_65 = F_76 ( V_15 , & V_39 , 0 ,
V_40 , V_90 ) ;
if ( V_65 ) {
F_66 ( & V_64 -> V_62 , L_7 ) ;
goto V_91;
}
F_77 ( V_15 , & V_39 , V_2 -> V_42 ,
F_38 ) ;
F_62 ( & V_64 -> V_62 ) ;
return 0 ;
V_91:
F_78 ( V_15 ) ;
V_88:
F_62 ( & V_64 -> V_62 ) ;
V_87:
F_79 ( & V_64 -> V_62 ) ;
F_56 ( V_2 -> V_66 ) ;
return V_65 ;
}
static int F_80 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_50 ( V_64 ) ;
F_60 ( & V_64 -> V_62 ) ;
F_78 ( & V_2 -> V_15 ) ;
F_56 ( V_2 -> V_66 ) ;
F_81 ( & V_64 -> V_62 , 0 ) ;
F_79 ( & V_64 -> V_62 ) ;
return 0 ;
}
static int T_3 F_82 ( void )
{
return F_83 ( & V_92 ) ;
}
static void T_4 F_84 ( void )
{
F_85 ( & V_92 ) ;
}
