static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
unsigned long V_5 = V_3 & 4 ? V_6 : V_7 ;
T_1 V_8 ;
int V_9 = ( V_3 & 3 ) * 8 ;
V_8 = F_2 ( V_2 -> V_10 + V_5 ) ;
V_8 &= ~ ( 0xff << V_9 ) ;
V_8 |= V_4 << V_9 ;
F_3 ( V_8 , V_2 -> V_10 + V_5 ) ;
}
static unsigned int F_4 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_5 = V_3 & 4 ? V_6 : V_7 ;
T_1 V_8 ;
int V_9 = ( V_3 & 3 ) * 8 ;
V_8 = F_2 ( V_2 -> V_10 + V_5 ) ;
V_8 &= 0xff << V_9 ;
V_8 >>= V_9 ;
return V_8 ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_11 )
{
unsigned long V_5 = V_12 + ( ( V_3 / 2 ) * 4 ) ;
int V_9 = ( V_3 & 1 ) * 16 ;
T_1 V_8 ;
V_8 = F_2 ( V_2 -> V_10 + V_5 ) ;
V_8 &= ~ ( 0xffff << V_9 ) ;
V_8 |= V_11 << V_9 ;
F_3 ( V_8 , V_2 -> V_10 + V_5 ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_5 = V_12 + ( ( V_3 / 2 ) * 4 ) ;
int V_9 = ( V_3 & 1 ) * 16 ;
T_1 V_8 ;
V_8 = F_2 ( V_2 -> V_10 + V_5 ) ;
V_8 &= 0xffff << V_9 ;
V_8 >>= V_9 ;
return V_8 ;
}
static void
F_7 ( struct V_1 * V_2 , unsigned int V_13 , int V_3 )
{
unsigned int V_5 = V_14 + ( ( V_13 >> 1 ) & ~ 3u ) ;
unsigned int V_9 = ( V_13 & 0x7 ) * 4 ;
T_1 V_8 ;
if ( V_13 >= 256 ) {
V_5 = V_15 ;
V_9 = 0 ;
}
V_8 = F_2 ( V_2 -> V_10 + V_5 ) ;
V_8 &= ~ ( 0xf << V_9 ) ;
if ( V_3 >= 0 )
V_8 |= ( 0x8 | V_3 ) << V_9 ;
F_3 ( V_8 , V_2 -> V_10 + V_5 ) ;
}
static T_2 F_8 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 =
F_9 ( V_19 , struct V_21 , V_19 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
T_3 V_23 ;
int V_3 ;
F_10 ( & V_2 -> V_24 ) ;
V_3 = V_2 -> V_13 [ V_22 -> V_13 ] ;
F_11 ( & V_2 -> V_24 ) ;
if ( V_3 >= 0 )
V_23 = snprintf ( V_20 , V_25 , L_1 , V_3 ) ;
else
V_23 = snprintf ( V_20 , V_25 , L_2 ) ;
return V_23 ;
}
static T_2 F_12 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
const char * V_20 , T_3 V_23 )
{
struct V_21 * V_22 =
F_9 ( V_19 , struct V_21 , V_19 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_26 , V_3 ;
if ( F_13 ( V_20 , 10 , & V_3 ) < 0 )
return - V_27 ;
if ( V_3 >= V_28 || V_3 < - 1 )
return - V_27 ;
F_10 ( & V_2 -> V_24 ) ;
V_26 = V_2 -> V_13 [ V_22 -> V_13 ] ;
if ( V_26 >= 0 ) {
V_2 -> V_13 [ V_22 -> V_13 ] = - 1 ;
F_14 ( V_22 -> V_13 , V_2 -> V_29 [ V_26 ] . V_13 ) ;
if ( V_2 -> V_29 [ V_26 ] . V_29 -> V_30 )
F_7 ( V_2 , V_22 -> V_13 , - 1 ) ;
}
if ( V_3 >= 0 ) {
if ( ! V_2 -> V_29 [ V_3 ] . V_29 ) {
V_23 = - V_31 ;
goto V_32;
}
F_15 ( V_22 -> V_13 , V_2 -> V_29 [ V_3 ] . V_13 ) ;
if ( V_2 -> V_29 [ V_3 ] . V_29 -> V_30 )
F_7 ( V_2 , V_22 -> V_13 , V_3 ) ;
}
V_2 -> V_13 [ V_22 -> V_13 ] = V_3 ;
V_32:
F_11 ( & V_2 -> V_24 ) ;
return V_23 ;
}
static void
F_16 ( struct V_1 * V_2 , int V_3 , unsigned int V_33 ,
unsigned int V_8 )
{
unsigned int V_4 = V_34 [ V_33 ] . F_17 ( V_2 , V_3 ) ;
unsigned int V_35 = V_34 [ V_33 ] . V_35 ;
unsigned int V_9 = F_18 ( V_35 ) ;
V_4 &= ~ V_35 ;
V_4 |= ( V_8 << V_9 ) & V_35 ;
V_34 [ V_33 ] . F_19 ( V_2 , V_3 , V_4 ) ;
}
static unsigned int
F_20 ( struct V_1 * V_2 , int V_3 , unsigned int V_33 )
{
unsigned int V_4 = V_34 [ V_33 ] . F_17 ( V_2 , V_3 ) ;
unsigned int V_35 = V_34 [ V_33 ] . V_35 ;
unsigned int V_9 = F_18 ( V_35 ) ;
V_4 &= V_35 ;
V_4 >>= V_9 ;
return V_4 ;
}
static int F_21 ( struct V_1 * V_2 )
{
T_1 V_36 ;
int V_3 , V_37 ;
V_36 = F_2 ( V_2 -> V_10 + V_38 ) ;
if ( V_36 & V_39 )
return - V_40 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( F_20 ( V_2 , V_3 , F_22 ( V_3 ) ) ==
V_41 )
continue;
F_1 ( V_2 , V_3 , 0 ) ;
F_5 ( V_2 , V_3 , 16 ) ;
}
F_3 ( 0 , V_2 -> V_10 + V_42 ) ;
for ( V_37 = 0 ; V_37 < 33 ; V_37 ++ )
F_3 ( 0 , V_2 -> V_10 + V_14 + V_37 * 4 ) ;
F_3 ( 0 , V_2 -> V_10 + V_43 ) ;
F_3 ( 0xfc , V_2 -> V_10 + V_44 ) ;
return 0 ;
}
static T_2 F_23 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
char * V_20 )
{
struct V_45 * V_46 =
F_9 ( V_19 , struct V_45 , V_19 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
T_3 V_23 ;
F_10 ( & V_2 -> V_24 ) ;
V_23 = snprintf ( V_20 , V_25 , L_1 ,
F_20 ( V_2 , V_46 -> V_3 , V_46 -> V_33 ) ) ;
F_11 ( & V_2 -> V_24 ) ;
return V_23 ;
}
static T_2 F_24 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
const char * V_20 , T_3 V_23 )
{
struct V_45 * V_46 =
F_9 ( V_19 , struct V_45 , V_19 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
unsigned int V_4 ;
if ( F_25 ( V_20 , 16 , & V_4 ) < 0 )
return - V_27 ;
F_10 ( & V_2 -> V_24 ) ;
F_16 ( V_2 , V_46 -> V_3 , V_46 -> V_33 , V_4 ) ;
F_11 ( & V_2 -> V_24 ) ;
return V_23 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_21 * V_47 ;
struct V_48 * * V_49 ;
int V_37 , V_50 = V_51 + 2 ;
V_49 = F_27 ( V_2 -> V_17 , V_50 , sizeof( void * ) , V_52 ) ;
if ( ! V_49 )
return - V_53 ;
V_47 = F_27 ( V_2 -> V_17 , V_50 ,
sizeof( struct V_21 ) ,
V_52 ) ;
if ( ! V_47 )
return - V_53 ;
for ( V_37 = 0 ; V_37 < V_51 + 1 ; V_37 ++ ) {
char * V_54 ;
V_54 = F_28 ( V_2 -> V_17 , V_52 , L_3 , V_37 ,
V_37 == V_51 ? L_4 : L_5 ) ;
if ( ! V_54 )
return - V_53 ;
V_47 [ V_37 ] . V_19 . V_19 . V_54 = V_54 ;
V_47 [ V_37 ] . V_19 . V_19 . V_55 = V_56 | V_57 ;
V_47 [ V_37 ] . V_19 . V_58 = F_8 ;
V_47 [ V_37 ] . V_19 . V_59 = F_12 ;
F_29 ( & V_47 [ V_37 ] . V_19 . V_19 ) ;
V_49 [ V_37 ] = & V_47 [ V_37 ] . V_19 . V_19 ;
V_47 [ V_37 ] . V_2 = V_2 ;
V_47 [ V_37 ] . V_13 = V_37 ;
}
V_2 -> V_60 . V_54 = L_6 ;
V_2 -> V_60 . V_49 = V_49 ;
return F_30 ( & V_2 -> V_17 -> V_61 , & V_2 -> V_60 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_45 * V_62 ;
struct V_48 * * V_49 ;
int V_37 , V_63 , V_64 = V_28 ;
int V_65 = F_32 ( V_34 ) ;
int V_50 = V_64 * V_65 + 1 ;
V_49 = F_27 ( V_2 -> V_17 , V_50 , sizeof( void * ) , V_52 ) ;
if ( ! V_49 )
return - V_53 ;
V_62 = F_27 ( V_2 -> V_17 , V_50 ,
sizeof( struct V_45 ) ,
V_52 ) ;
if ( ! V_62 )
return - V_53 ;
for ( V_37 = 0 ; V_37 < V_64 ; V_37 ++ ) {
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
unsigned int V_66 = V_37 * V_65 + V_63 ;
char * V_54 ;
V_54 = F_28 ( V_2 -> V_17 , V_52 , L_7 , V_37 ,
V_34 [ V_63 ] . V_54 ) ;
if ( ! V_54 )
return - V_53 ;
V_62 [ V_66 ] . V_19 . V_19 . V_54 = V_54 ;
if ( V_34 [ V_63 ] . V_67 ) {
V_62 [ V_66 ] . V_19 . V_19 . V_55 |= V_56 ;
V_62 [ V_66 ] . V_19 . V_58 = F_23 ;
}
if ( V_34 [ V_63 ] . V_68 ) {
V_62 [ V_66 ] . V_19 . V_19 . V_55 |= V_57 ;
V_62 [ V_66 ] . V_19 . V_59 = F_24 ;
}
F_29 ( & V_62 [ V_66 ] . V_19 . V_19 ) ;
V_49 [ V_66 ] = & V_62 [ V_66 ] . V_19 . V_19 ;
V_62 [ V_66 ] . V_2 = V_2 ;
V_62 [ V_66 ] . V_3 = V_37 ;
V_62 [ V_66 ] . V_33 = V_63 ;
}
}
V_2 -> V_69 . V_54 = L_8 ;
V_2 -> V_69 . V_49 = V_49 ;
return F_30 ( & V_2 -> V_17 -> V_61 , & V_2 -> V_69 ) ;
}
static void F_33 ( struct V_70 * V_71 ,
struct V_72 * V_29 )
{
struct V_1 * V_2 = F_34 ( & V_71 -> V_17 ) ;
unsigned long V_23 ;
int V_13 ;
T_1 V_5 ;
F_10 ( & V_2 -> V_24 ) ;
V_29 -> V_30 = false ;
F_35 (master, gth->output[output->port].master,
TH_CONFIGURABLE_MASTERS) {
F_7 ( V_2 , V_13 , - 1 ) ;
}
F_11 ( & V_2 -> V_24 ) ;
F_3 ( 0 , V_2 -> V_10 + V_43 ) ;
F_3 ( 0xfd , V_2 -> V_10 + V_44 ) ;
for ( V_5 = 0 , V_23 = V_73 ;
V_23 && ! ( V_5 & F_36 ( V_29 -> V_3 ) ) ; V_23 -- ) {
V_5 = F_2 ( V_2 -> V_10 + V_74 ) ;
F_37 () ;
}
F_3 ( 0xfc , V_2 -> V_10 + V_44 ) ;
if ( ! V_23 )
F_38 ( & V_71 -> V_17 , L_9 ,
V_29 -> V_3 ) ;
}
static void F_39 ( struct V_70 * V_71 ,
struct V_72 * V_29 )
{
struct V_1 * V_2 = F_34 ( & V_71 -> V_17 ) ;
T_1 V_75 = 0xfc0000 ;
int V_13 ;
F_10 ( & V_2 -> V_24 ) ;
F_35 (master, gth->output[output->port].master,
TH_CONFIGURABLE_MASTERS + 1 ) {
F_7 ( V_2 , V_13 , V_29 -> V_3 ) ;
}
if ( V_29 -> V_76 )
V_75 |= 0xff ;
V_29 -> V_30 = true ;
F_11 ( & V_2 -> V_24 ) ;
F_3 ( V_75 , V_2 -> V_10 + V_43 ) ;
F_3 ( 0 , V_2 -> V_10 + V_44 ) ;
}
static int F_40 ( struct V_70 * V_71 ,
struct V_70 * V_77 )
{
struct V_1 * V_2 = F_34 ( & V_71 -> V_17 ) ;
int V_37 , V_78 ;
if ( V_77 -> type != V_79 )
return - V_27 ;
for ( V_37 = 0 , V_78 = 0 ; V_37 < V_28 ; V_37 ++ ) {
if ( V_2 -> V_29 [ V_37 ] . V_80 != V_77 -> V_29 . type )
continue;
if ( V_77 -> V_78 == - 1 || V_77 -> V_78 == V_78 )
goto V_81;
V_78 ++ ;
}
return - V_82 ;
V_81:
F_10 ( & V_2 -> V_24 ) ;
V_77 -> V_29 . V_3 = V_37 ;
V_77 -> V_29 . V_30 = false ;
V_2 -> V_29 [ V_37 ] . V_29 = & V_77 -> V_29 ;
F_11 ( & V_2 -> V_24 ) ;
return 0 ;
}
static void F_41 ( struct V_70 * V_71 ,
struct V_70 * V_77 )
{
struct V_1 * V_2 = F_34 ( & V_71 -> V_17 ) ;
int V_3 = V_77 -> V_29 . V_3 ;
F_10 ( & V_2 -> V_24 ) ;
V_77 -> V_29 . V_3 = - 1 ;
V_77 -> V_29 . V_30 = false ;
V_2 -> V_29 [ V_3 ] . V_29 = NULL ;
F_11 ( & V_2 -> V_24 ) ;
}
static int
F_42 ( struct V_70 * V_71 , unsigned int V_13 )
{
struct V_1 * V_2 = F_34 ( & V_71 -> V_17 ) ;
int V_3 = 0 ;
if ( V_13 > V_51 )
V_13 = V_51 ;
F_10 ( & V_2 -> V_24 ) ;
if ( V_2 -> V_13 [ V_13 ] == - 1 ) {
F_15 ( V_13 , V_2 -> V_29 [ V_3 ] . V_13 ) ;
V_2 -> V_13 [ V_13 ] = V_3 ;
}
F_11 ( & V_2 -> V_24 ) ;
return 0 ;
}
static int F_43 ( struct V_70 * V_71 )
{
struct V_16 * V_17 = & V_71 -> V_17 ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
void T_4 * V_10 ;
int V_37 , V_85 ;
V_84 = F_44 ( V_71 , V_86 , 0 ) ;
if ( ! V_84 )
return - V_31 ;
V_10 = F_45 ( V_17 , V_84 -> V_87 , F_46 ( V_84 ) ) ;
if ( ! V_10 )
return - V_53 ;
V_2 = F_47 ( V_17 , sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_10 = V_10 ;
F_48 ( & V_2 -> V_24 ) ;
V_85 = F_21 ( V_2 ) ;
if ( V_85 )
return V_85 ;
for ( V_37 = 0 ; V_37 < V_51 + 1 ; V_37 ++ )
V_2 -> V_13 [ V_37 ] = - 1 ;
for ( V_37 = 0 ; V_37 < V_28 ; V_37 ++ ) {
V_2 -> V_29 [ V_37 ] . V_2 = V_2 ;
V_2 -> V_29 [ V_37 ] . V_88 = V_37 ;
V_2 -> V_29 [ V_37 ] . V_80 =
F_20 ( V_2 , V_37 , F_22 ( V_3 ) ) ;
}
if ( F_31 ( V_2 ) ||
F_26 ( V_2 ) ) {
F_49 ( L_10 ) ;
if ( V_2 -> V_69 . V_49 )
F_50 ( & V_2 -> V_17 -> V_61 , & V_2 -> V_69 ) ;
return - V_53 ;
}
F_51 ( V_17 , V_2 ) ;
return 0 ;
}
static void F_52 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_34 ( & V_71 -> V_17 ) ;
F_50 ( & V_2 -> V_17 -> V_61 , & V_2 -> V_69 ) ;
F_50 ( & V_2 -> V_17 -> V_61 , & V_2 -> V_60 ) ;
}
