static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
if ( V_3 == V_5 ) {
if ( V_2 -> V_6 -> V_7 )
return F_2 ( V_2 -> V_6 -> V_8 ) ;
else
return F_2 ( V_2 -> V_6 -> V_8 + 0x280 ) ;
}
V_4 = V_9 [ V_3 ] ;
if ( ( V_3 == V_10 ) || ( V_3 == V_11 ) )
return F_3 ( V_2 -> V_12 + V_4 ) ;
else
return F_2 ( V_2 -> V_12 + V_4 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_13 )
{
unsigned long V_4 ;
if ( V_3 == V_5 ) {
if ( V_2 -> V_6 -> V_7 )
return F_5 ( V_13 , V_2 -> V_6 -> V_8 ) ;
else
return F_5 ( V_13 , V_2 -> V_6 -> V_8 + 0x280 ) ;
}
V_4 = V_9 [ V_3 ] ;
if ( ( V_3 == V_10 ) || ( V_3 == V_11 ) )
F_6 ( V_13 , V_2 -> V_12 + V_4 ) ;
else
F_5 ( V_13 , V_2 -> V_12 + V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_14 )
{
unsigned long V_15 , V_13 ;
F_8 ( & V_16 , V_15 ) ;
V_13 = F_1 ( V_2 , V_5 ) ;
if ( V_14 )
V_13 |= 1 << V_2 -> V_17 ;
else
V_13 &= ~ ( 1 << V_2 -> V_17 ) ;
F_4 ( V_2 , V_5 , V_13 ) ;
F_9 ( & V_16 , V_15 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
unsigned long V_18 ;
unsigned long V_19 ;
int V_20 ;
F_11 ( & V_2 -> V_6 -> V_21 -> V_22 ) ;
F_12 ( & V_2 -> V_6 -> V_21 -> V_22 , true ) ;
V_20 = F_13 ( V_2 -> V_6 -> V_23 ) ;
if ( V_20 ) {
F_14 ( & V_2 -> V_6 -> V_21 -> V_22 , L_1 ,
V_2 -> V_17 ) ;
return V_20 ;
}
F_7 ( V_2 , 0 ) ;
V_19 = F_15 ( V_2 -> V_6 -> V_23 ) / 64 ;
V_18 = ( V_19 + V_24 / 2 ) / V_24 ;
F_4 ( V_2 , V_25 , V_26 | V_27 ) ;
F_4 ( V_2 , V_28 , F_16 ( V_29 ) |
F_17 ( V_29 ) ) ;
F_4 ( V_2 , V_11 , V_18 ) ;
F_4 ( V_2 , V_10 , 0 ) ;
F_4 ( V_2 , V_30 , V_31 ) ;
F_4 ( V_2 , V_32 , V_33 ) ;
F_7 ( V_2 , 1 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0 ) ;
F_19 ( V_2 -> V_6 -> V_23 ) ;
F_12 ( & V_2 -> V_6 -> V_21 -> V_22 , false ) ;
F_20 ( & V_2 -> V_6 -> V_21 -> V_22 ) ;
}
static T_1 F_21 ( int V_34 , void * V_35 )
{
struct V_1 * V_2 = V_35 ;
F_1 ( V_2 , V_36 ) ;
F_4 ( V_2 , V_36 , ~ V_37 ) ;
V_2 -> V_38 . V_39 ( & V_2 -> V_38 ) ;
return V_40 ;
}
static struct V_1 * F_22 ( struct V_41 * V_38 )
{
return F_23 ( V_38 , struct V_1 , V_38 ) ;
}
static void F_24 ( enum V_42 V_43 ,
struct V_41 * V_38 )
{
struct V_1 * V_2 = F_22 ( V_38 ) ;
int V_44 = 0 ;
switch ( V_38 -> V_43 ) {
case V_45 :
F_18 ( V_2 ) ;
V_44 = 1 ;
break;
default:
break;
}
switch ( V_43 ) {
case V_45 :
F_25 ( & V_2 -> V_6 -> V_21 -> V_22 ,
L_2 , V_2 -> V_17 ) ;
F_10 ( V_2 ) ;
break;
case V_46 :
if ( ! V_44 )
F_18 ( V_2 ) ;
break;
case V_47 :
default:
break;
}
}
static void F_26 ( struct V_41 * V_38 )
{
F_27 ( & F_22 ( V_38 ) -> V_6 -> V_21 -> V_22 ) ;
}
static void F_28 ( struct V_41 * V_38 )
{
F_29 ( & F_22 ( V_38 ) -> V_6 -> V_21 -> V_22 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
const char * V_48 )
{
struct V_41 * V_38 = & V_2 -> V_38 ;
int V_20 ;
V_38 -> V_48 = V_48 ;
V_38 -> V_49 = V_50 ;
V_38 -> V_51 = 200 ;
V_38 -> V_52 = V_53 ;
V_38 -> V_54 = F_24 ;
V_38 -> V_55 = F_26 ;
V_38 -> V_56 = F_28 ;
F_25 ( & V_2 -> V_6 -> V_21 -> V_22 , L_3 ,
V_2 -> V_17 ) ;
F_31 ( V_38 ) ;
V_20 = F_32 ( V_2 -> V_34 , F_21 ,
V_57 | V_58 | V_59 ,
F_33 ( & V_2 -> V_6 -> V_21 -> V_22 ) , V_2 ) ;
if ( V_20 ) {
F_14 ( & V_2 -> V_6 -> V_21 -> V_22 , L_4 ,
V_2 -> V_17 , V_2 -> V_34 ) ;
return;
}
}
static int F_34 ( struct V_1 * V_2 , const char * V_48 ,
bool V_60 )
{
if ( V_60 ) {
V_2 -> V_6 -> V_61 = true ;
F_30 ( V_2 , V_48 ) ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_17 ,
struct V_62 * V_6 )
{
static const unsigned int V_63 [] = {
0x300 , 0x380 , 0x000 ,
} ;
bool V_60 ;
V_2 -> V_6 = V_6 ;
if ( V_6 -> V_7 ) {
struct V_64 * V_65 = V_6 -> V_21 -> V_22 . V_66 ;
V_60 = V_65 -> V_67 != 0 ;
V_2 -> V_34 = F_36 ( V_6 -> V_21 , 0 ) ;
V_2 -> V_12 = V_6 -> V_8 - V_65 -> V_68 ;
V_2 -> V_17 = V_65 -> V_69 ;
} else {
char V_48 [ 6 ] ;
V_60 = true ;
sprintf ( V_48 , L_5 , V_17 ) ;
V_2 -> V_34 = F_37 ( V_6 -> V_21 , V_48 ) ;
V_2 -> V_12 = V_6 -> V_8 + V_63 [ V_17 ] ;
V_2 -> V_17 = V_17 ;
}
if ( V_2 -> V_34 < 0 ) {
if ( ! V_6 -> V_7 )
return 0 ;
F_14 ( & V_6 -> V_21 -> V_22 , L_6 ,
V_2 -> V_17 ) ;
return V_2 -> V_34 ;
}
return F_34 ( V_2 , F_33 ( & V_6 -> V_21 -> V_22 ) , V_60 ) ;
}
static int F_38 ( struct V_62 * V_6 )
{
struct V_70 * V_71 ;
V_71 = F_39 ( V_6 -> V_21 , V_72 , 0 ) ;
if ( ! V_71 ) {
F_14 ( & V_6 -> V_21 -> V_22 , L_7 ) ;
return - V_73 ;
}
V_6 -> V_8 = F_40 ( V_71 -> V_14 , F_41 ( V_71 ) ) ;
if ( V_6 -> V_8 == NULL )
return - V_73 ;
if ( V_6 -> V_7 ) {
struct V_64 * V_65 = V_6 -> V_21 -> V_22 . V_66 ;
V_6 -> V_8 += V_65 -> V_68 ;
}
return 0 ;
}
static void F_42 ( struct V_62 * V_6 )
{
if ( V_6 -> V_7 ) {
struct V_64 * V_65 = V_6 -> V_21 -> V_22 . V_66 ;
V_6 -> V_8 -= V_65 -> V_68 ;
}
F_43 ( V_6 -> V_8 ) ;
}
static int F_44 ( struct V_62 * V_6 ,
struct V_74 * V_21 )
{
struct V_64 * V_65 = V_21 -> V_22 . V_66 ;
const struct V_75 * V_76 = V_21 -> V_77 ;
unsigned int V_78 ;
int V_20 ;
V_6 -> V_21 = V_21 ;
V_6 -> V_7 = V_76 -> V_79 ;
if ( V_6 -> V_7 && ! V_65 ) {
F_14 ( & V_6 -> V_21 -> V_22 , L_8 ) ;
return - V_73 ;
}
V_6 -> V_23 = F_45 ( & V_6 -> V_21 -> V_22 , V_6 -> V_7 ? L_9 : L_10 ) ;
if ( F_46 ( V_6 -> V_23 ) ) {
F_14 ( & V_6 -> V_21 -> V_22 , L_11 ) ;
return F_47 ( V_6 -> V_23 ) ;
}
V_20 = F_48 ( V_6 -> V_23 ) ;
if ( V_20 < 0 )
goto V_80;
V_20 = F_38 ( V_6 ) ;
if ( V_20 < 0 ) {
F_14 ( & V_6 -> V_21 -> V_22 , L_12 ) ;
goto V_81;
}
if ( V_6 -> V_7 )
V_6 -> V_82 = 1 ;
else
V_6 -> V_82 = 3 ;
V_6 -> V_83 = F_49 ( sizeof( * V_6 -> V_83 ) * V_6 -> V_82 ,
V_84 ) ;
if ( V_6 -> V_83 == NULL ) {
V_20 = - V_85 ;
goto V_86;
}
if ( V_6 -> V_7 ) {
V_20 = F_35 ( & V_6 -> V_83 [ 0 ] , 0 , V_6 ) ;
if ( V_20 < 0 )
goto V_86;
} else {
for ( V_78 = 0 ; V_78 < V_6 -> V_82 ; ++ V_78 ) {
V_20 = F_35 ( & V_6 -> V_83 [ V_78 ] , V_78 , V_6 ) ;
if ( V_20 < 0 )
goto V_86;
}
}
F_50 ( V_21 , V_6 ) ;
return 0 ;
V_86:
F_51 ( V_6 -> V_83 ) ;
F_42 ( V_6 ) ;
V_81:
F_52 ( V_6 -> V_23 ) ;
V_80:
F_53 ( V_6 -> V_23 ) ;
return V_20 ;
}
static int F_54 ( struct V_74 * V_21 )
{
struct V_62 * V_6 = F_55 ( V_21 ) ;
int V_20 ;
if ( ! F_56 ( V_21 ) ) {
F_57 ( & V_21 -> V_22 ) ;
F_58 ( & V_21 -> V_22 ) ;
}
if ( V_6 ) {
F_25 ( & V_21 -> V_22 , L_13 ) ;
goto V_87;
}
V_6 = F_49 ( sizeof( * V_6 ) , V_84 ) ;
if ( V_6 == NULL )
return - V_85 ;
V_20 = F_44 ( V_6 , V_21 ) ;
if ( V_20 ) {
F_51 ( V_6 ) ;
F_59 ( & V_21 -> V_22 ) ;
return V_20 ;
}
if ( F_56 ( V_21 ) )
return 0 ;
V_87:
if ( V_6 -> V_61 )
F_60 ( & V_21 -> V_22 ) ;
else
F_59 ( & V_21 -> V_22 ) ;
return 0 ;
}
static int F_61 ( struct V_74 * V_21 )
{
return - V_88 ;
}
static int T_2 F_62 ( void )
{
return F_63 ( & V_89 ) ;
}
static void T_3 F_64 ( void )
{
F_65 ( & V_89 ) ;
}
