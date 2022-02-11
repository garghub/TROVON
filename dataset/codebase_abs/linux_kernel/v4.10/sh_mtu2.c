static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
if ( V_3 == V_5 )
return F_2 ( V_2 -> V_6 -> V_7 + 0x280 ) ;
V_4 = V_8 [ V_3 ] ;
if ( ( V_3 == V_9 ) || ( V_3 == V_10 ) )
return F_3 ( V_2 -> V_11 + V_4 ) ;
else
return F_2 ( V_2 -> V_11 + V_4 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_12 )
{
unsigned long V_4 ;
if ( V_3 == V_5 )
return F_5 ( V_12 , V_2 -> V_6 -> V_7 + 0x280 ) ;
V_4 = V_8 [ V_3 ] ;
if ( ( V_3 == V_9 ) || ( V_3 == V_10 ) )
F_6 ( V_12 , V_2 -> V_11 + V_4 ) ;
else
F_5 ( V_12 , V_2 -> V_11 + V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_13 )
{
unsigned long V_14 , V_12 ;
F_8 ( & V_2 -> V_6 -> V_15 , V_14 ) ;
V_12 = F_1 ( V_2 , V_5 ) ;
if ( V_13 )
V_12 |= 1 << V_2 -> V_16 ;
else
V_12 &= ~ ( 1 << V_2 -> V_16 ) ;
F_4 ( V_2 , V_5 , V_12 ) ;
F_9 ( & V_2 -> V_6 -> V_15 , V_14 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
unsigned long V_18 ;
int V_19 ;
F_11 ( & V_2 -> V_6 -> V_20 -> V_21 ) ;
F_12 ( & V_2 -> V_6 -> V_20 -> V_21 , true ) ;
V_19 = F_13 ( V_2 -> V_6 -> V_22 ) ;
if ( V_19 ) {
F_14 ( & V_2 -> V_6 -> V_20 -> V_21 , L_1 ,
V_2 -> V_16 ) ;
return V_19 ;
}
F_7 ( V_2 , 0 ) ;
V_18 = F_15 ( V_2 -> V_6 -> V_22 ) / 64 ;
V_17 = ( V_18 + V_23 / 2 ) / V_23 ;
F_4 ( V_2 , V_24 , V_25 | V_26 ) ;
F_4 ( V_2 , V_27 , F_16 ( V_28 ) |
F_17 ( V_28 ) ) ;
F_4 ( V_2 , V_10 , V_17 ) ;
F_4 ( V_2 , V_9 , 0 ) ;
F_4 ( V_2 , V_29 , V_30 ) ;
F_4 ( V_2 , V_31 , V_32 ) ;
F_7 ( V_2 , 1 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0 ) ;
F_19 ( V_2 -> V_6 -> V_22 ) ;
F_12 ( & V_2 -> V_6 -> V_20 -> V_21 , false ) ;
F_20 ( & V_2 -> V_6 -> V_20 -> V_21 ) ;
}
static T_1 F_21 ( int V_33 , void * V_34 )
{
struct V_1 * V_2 = V_34 ;
F_1 ( V_2 , V_35 ) ;
F_4 ( V_2 , V_35 , ~ V_36 ) ;
V_2 -> V_37 . V_38 ( & V_2 -> V_37 ) ;
return V_39 ;
}
static struct V_1 * F_22 ( struct V_40 * V_37 )
{
return F_23 ( V_37 , struct V_1 , V_37 ) ;
}
static int F_24 ( struct V_40 * V_37 )
{
struct V_1 * V_2 = F_22 ( V_37 ) ;
if ( F_25 ( V_37 ) )
F_18 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_40 * V_37 )
{
struct V_1 * V_2 = F_22 ( V_37 ) ;
if ( F_25 ( V_37 ) )
F_18 ( V_2 ) ;
F_27 ( & V_2 -> V_6 -> V_20 -> V_21 , L_2 ,
V_2 -> V_16 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static void F_28 ( struct V_40 * V_37 )
{
F_29 ( & F_22 ( V_37 ) -> V_6 -> V_20 -> V_21 ) ;
}
static void F_30 ( struct V_40 * V_37 )
{
F_31 ( & F_22 ( V_37 ) -> V_6 -> V_20 -> V_21 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
const char * V_41 )
{
struct V_40 * V_37 = & V_2 -> V_37 ;
V_37 -> V_41 = V_41 ;
V_37 -> V_42 = V_43 ;
V_37 -> V_44 = 200 ;
V_37 -> V_45 = V_46 ;
V_37 -> V_47 = F_24 ;
V_37 -> V_48 = F_26 ;
V_37 -> V_49 = F_28 ;
V_37 -> V_50 = F_30 ;
F_27 ( & V_2 -> V_6 -> V_20 -> V_21 , L_3 ,
V_2 -> V_16 ) ;
F_33 ( V_37 ) ;
}
static int F_34 ( struct V_1 * V_2 , const char * V_41 )
{
V_2 -> V_6 -> V_51 = true ;
F_32 ( V_2 , V_41 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_16 ,
struct V_52 * V_6 )
{
static const unsigned int V_53 [] = {
0x300 , 0x380 , 0x000 ,
} ;
char V_41 [ 6 ] ;
int V_33 ;
int V_19 ;
V_2 -> V_6 = V_6 ;
sprintf ( V_41 , L_4 , V_16 ) ;
V_33 = F_36 ( V_6 -> V_20 , V_41 ) ;
if ( V_33 < 0 ) {
return 0 ;
}
V_19 = F_37 ( V_33 , F_21 ,
V_54 | V_55 | V_56 ,
F_38 ( & V_2 -> V_6 -> V_20 -> V_21 ) , V_2 ) ;
if ( V_19 ) {
F_14 ( & V_2 -> V_6 -> V_20 -> V_21 , L_5 ,
V_16 , V_33 ) ;
return V_19 ;
}
V_2 -> V_11 = V_6 -> V_7 + V_53 [ V_16 ] ;
V_2 -> V_16 = V_16 ;
return F_34 ( V_2 , F_38 ( & V_6 -> V_20 -> V_21 ) ) ;
}
static int F_39 ( struct V_52 * V_6 )
{
struct V_57 * V_58 ;
V_58 = F_40 ( V_6 -> V_20 , V_59 , 0 ) ;
if ( ! V_58 ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_6 ) ;
return - V_60 ;
}
V_6 -> V_7 = F_41 ( V_58 -> V_13 , F_42 ( V_58 ) ) ;
if ( V_6 -> V_7 == NULL )
return - V_60 ;
return 0 ;
}
static int F_43 ( struct V_52 * V_6 ,
struct V_61 * V_20 )
{
unsigned int V_62 ;
int V_19 ;
V_6 -> V_20 = V_20 ;
F_44 ( & V_6 -> V_15 ) ;
V_6 -> V_22 = F_45 ( & V_6 -> V_20 -> V_21 , L_7 ) ;
if ( F_46 ( V_6 -> V_22 ) ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_8 ) ;
return F_47 ( V_6 -> V_22 ) ;
}
V_19 = F_48 ( V_6 -> V_22 ) ;
if ( V_19 < 0 )
goto V_63;
V_19 = F_39 ( V_6 ) ;
if ( V_19 < 0 ) {
F_14 ( & V_6 -> V_20 -> V_21 , L_9 ) ;
goto V_64;
}
V_6 -> V_65 = 3 ;
V_6 -> V_66 = F_49 ( sizeof( * V_6 -> V_66 ) * V_6 -> V_65 ,
V_67 ) ;
if ( V_6 -> V_66 == NULL ) {
V_19 = - V_68 ;
goto V_69;
}
for ( V_62 = 0 ; V_62 < V_6 -> V_65 ; ++ V_62 ) {
V_19 = F_35 ( & V_6 -> V_66 [ V_62 ] , V_62 , V_6 ) ;
if ( V_19 < 0 )
goto V_69;
}
F_50 ( V_20 , V_6 ) ;
return 0 ;
V_69:
F_51 ( V_6 -> V_66 ) ;
F_52 ( V_6 -> V_7 ) ;
V_64:
F_53 ( V_6 -> V_22 ) ;
V_63:
F_54 ( V_6 -> V_22 ) ;
return V_19 ;
}
static int F_55 ( struct V_61 * V_20 )
{
struct V_52 * V_6 = F_56 ( V_20 ) ;
int V_19 ;
if ( ! F_57 ( V_20 ) ) {
F_58 ( & V_20 -> V_21 ) ;
F_59 ( & V_20 -> V_21 ) ;
}
if ( V_6 ) {
F_27 ( & V_20 -> V_21 , L_10 ) ;
goto V_70;
}
V_6 = F_49 ( sizeof( * V_6 ) , V_67 ) ;
if ( V_6 == NULL )
return - V_68 ;
V_19 = F_43 ( V_6 , V_20 ) ;
if ( V_19 ) {
F_51 ( V_6 ) ;
F_60 ( & V_20 -> V_21 ) ;
return V_19 ;
}
if ( F_57 ( V_20 ) )
return 0 ;
V_70:
if ( V_6 -> V_51 )
F_61 ( & V_20 -> V_21 ) ;
else
F_60 ( & V_20 -> V_21 ) ;
return 0 ;
}
static int F_62 ( struct V_61 * V_20 )
{
return - V_71 ;
}
static int T_2 F_63 ( void )
{
return F_64 ( & V_72 ) ;
}
static void T_3 F_65 ( void )
{
F_66 ( & V_72 ) ;
}
