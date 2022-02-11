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
T_1 V_5 ;
int V_3 , V_36 ;
V_5 = F_2 ( V_2 -> V_10 + V_37 ) ;
if ( V_5 & V_38 )
return - V_39 ;
V_5 |= V_40 | V_41 ;
F_3 ( V_5 , V_2 -> V_10 + V_37 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( F_20 ( V_2 , V_3 , F_22 ( V_3 ) ) ==
V_42 )
continue;
F_1 ( V_2 , V_3 , 0 ) ;
F_5 ( V_2 , V_3 , 16 ) ;
}
F_3 ( 0 , V_2 -> V_10 + V_43 ) ;
for ( V_36 = 0 ; V_36 < 33 ; V_36 ++ )
F_3 ( 0 , V_2 -> V_10 + V_14 + V_36 * 4 ) ;
F_3 ( 0 , V_2 -> V_10 + V_44 ) ;
F_3 ( 0xfc , V_2 -> V_10 + V_45 ) ;
return 0 ;
}
static T_2 F_23 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
char * V_20 )
{
struct V_46 * V_47 =
F_9 ( V_19 , struct V_46 , V_19 ) ;
struct V_1 * V_2 = V_47 -> V_2 ;
T_3 V_23 ;
F_24 ( V_17 ) ;
F_10 ( & V_2 -> V_24 ) ;
V_23 = snprintf ( V_20 , V_25 , L_1 ,
F_20 ( V_2 , V_47 -> V_3 , V_47 -> V_33 ) ) ;
F_11 ( & V_2 -> V_24 ) ;
F_25 ( V_17 ) ;
return V_23 ;
}
static T_2 F_26 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
const char * V_20 , T_3 V_23 )
{
struct V_46 * V_47 =
F_9 ( V_19 , struct V_46 , V_19 ) ;
struct V_1 * V_2 = V_47 -> V_2 ;
unsigned int V_4 ;
if ( F_27 ( V_20 , 16 , & V_4 ) < 0 )
return - V_27 ;
F_24 ( V_17 ) ;
F_10 ( & V_2 -> V_24 ) ;
F_16 ( V_2 , V_47 -> V_3 , V_47 -> V_33 , V_4 ) ;
F_11 ( & V_2 -> V_24 ) ;
F_25 ( V_17 ) ;
return V_23 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_21 * V_48 ;
struct V_49 * * V_50 ;
int V_36 , V_51 = V_52 + 2 ;
V_50 = F_29 ( V_2 -> V_17 , V_51 , sizeof( void * ) , V_53 ) ;
if ( ! V_50 )
return - V_54 ;
V_48 = F_29 ( V_2 -> V_17 , V_51 ,
sizeof( struct V_21 ) ,
V_53 ) ;
if ( ! V_48 )
return - V_54 ;
for ( V_36 = 0 ; V_36 < V_52 + 1 ; V_36 ++ ) {
char * V_55 ;
V_55 = F_30 ( V_2 -> V_17 , V_53 , L_3 , V_36 ,
V_36 == V_52 ? L_4 : L_5 ) ;
if ( ! V_55 )
return - V_54 ;
V_48 [ V_36 ] . V_19 . V_19 . V_55 = V_55 ;
V_48 [ V_36 ] . V_19 . V_19 . V_56 = V_57 | V_58 ;
V_48 [ V_36 ] . V_19 . V_59 = F_8 ;
V_48 [ V_36 ] . V_19 . V_60 = F_12 ;
F_31 ( & V_48 [ V_36 ] . V_19 . V_19 ) ;
V_50 [ V_36 ] = & V_48 [ V_36 ] . V_19 . V_19 ;
V_48 [ V_36 ] . V_2 = V_2 ;
V_48 [ V_36 ] . V_13 = V_36 ;
}
V_2 -> V_61 . V_55 = L_6 ;
V_2 -> V_61 . V_50 = V_50 ;
return F_32 ( & V_2 -> V_17 -> V_62 , & V_2 -> V_61 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_46 * V_63 ;
struct V_49 * * V_50 ;
int V_36 , V_64 , V_65 = V_28 ;
int V_66 = F_34 ( V_34 ) ;
int V_51 = V_65 * V_66 + 1 ;
V_50 = F_29 ( V_2 -> V_17 , V_51 , sizeof( void * ) , V_53 ) ;
if ( ! V_50 )
return - V_54 ;
V_63 = F_29 ( V_2 -> V_17 , V_51 ,
sizeof( struct V_46 ) ,
V_53 ) ;
if ( ! V_63 )
return - V_54 ;
for ( V_36 = 0 ; V_36 < V_65 ; V_36 ++ ) {
for ( V_64 = 0 ; V_64 < V_66 ; V_64 ++ ) {
unsigned int V_67 = V_36 * V_66 + V_64 ;
char * V_55 ;
V_55 = F_30 ( V_2 -> V_17 , V_53 , L_7 , V_36 ,
V_34 [ V_64 ] . V_55 ) ;
if ( ! V_55 )
return - V_54 ;
V_63 [ V_67 ] . V_19 . V_19 . V_55 = V_55 ;
if ( V_34 [ V_64 ] . V_68 ) {
V_63 [ V_67 ] . V_19 . V_19 . V_56 |= V_57 ;
V_63 [ V_67 ] . V_19 . V_59 = F_23 ;
}
if ( V_34 [ V_64 ] . V_69 ) {
V_63 [ V_67 ] . V_19 . V_19 . V_56 |= V_58 ;
V_63 [ V_67 ] . V_19 . V_60 = F_26 ;
}
F_31 ( & V_63 [ V_67 ] . V_19 . V_19 ) ;
V_50 [ V_67 ] = & V_63 [ V_67 ] . V_19 . V_19 ;
V_63 [ V_67 ] . V_2 = V_2 ;
V_63 [ V_67 ] . V_3 = V_36 ;
V_63 [ V_67 ] . V_33 = V_64 ;
}
}
V_2 -> V_70 . V_55 = L_8 ;
V_2 -> V_70 . V_50 = V_50 ;
return F_32 ( & V_2 -> V_17 -> V_62 , & V_2 -> V_70 ) ;
}
static void F_35 ( struct V_71 * V_72 ,
struct V_73 * V_29 )
{
struct V_1 * V_2 = F_36 ( & V_72 -> V_17 ) ;
unsigned long V_23 ;
int V_13 ;
T_1 V_5 ;
F_10 ( & V_2 -> V_24 ) ;
V_29 -> V_30 = false ;
F_37 (master, gth->output[output->port].master,
TH_CONFIGURABLE_MASTERS) {
F_7 ( V_2 , V_13 , - 1 ) ;
}
F_11 ( & V_2 -> V_24 ) ;
F_3 ( 0 , V_2 -> V_10 + V_44 ) ;
F_3 ( 0xfd , V_2 -> V_10 + V_45 ) ;
for ( V_5 = 0 , V_23 = V_74 ;
V_23 && ! ( V_5 & F_38 ( V_29 -> V_3 ) ) ; V_23 -- ) {
V_5 = F_2 ( V_2 -> V_10 + V_75 ) ;
F_39 () ;
}
F_3 ( 0xfc , V_2 -> V_10 + V_45 ) ;
if ( ! V_23 )
F_40 ( & V_72 -> V_17 , L_9 ,
V_29 -> V_3 ) ;
V_5 = F_2 ( V_2 -> V_10 + V_37 ) ;
V_5 &= ~ V_29 -> V_76 ;
F_3 ( V_5 , V_2 -> V_10 + V_37 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_2 ( V_2 -> V_10 + V_77 ) ;
V_5 &= ~ V_78 ;
F_3 ( V_5 , V_2 -> V_10 + V_77 ) ;
}
static void F_42 ( struct V_71 * V_72 ,
struct V_73 * V_29 )
{
struct V_1 * V_2 = F_36 ( & V_72 -> V_17 ) ;
struct V_79 * V_80 = F_43 ( V_72 ) ;
T_1 V_81 = 0xfc0000 , V_82 ;
int V_13 ;
F_10 ( & V_2 -> V_24 ) ;
F_37 (master, gth->output[output->port].master,
TH_CONFIGURABLE_MASTERS + 1 ) {
F_7 ( V_2 , V_13 , V_29 -> V_3 ) ;
}
if ( V_29 -> V_83 )
V_81 |= 0xff ;
V_29 -> V_30 = true ;
F_11 ( & V_2 -> V_24 ) ;
if ( F_44 ( V_80 , V_84 ) )
F_41 ( V_2 ) ;
V_82 = F_2 ( V_2 -> V_10 + V_37 ) ;
V_82 |= V_29 -> V_76 ;
F_3 ( V_82 , V_2 -> V_10 + V_37 ) ;
F_3 ( V_81 , V_2 -> V_10 + V_44 ) ;
F_3 ( 0 , V_2 -> V_10 + V_45 ) ;
}
static int F_45 ( struct V_71 * V_72 ,
struct V_71 * V_85 )
{
struct V_1 * V_2 = F_36 ( & V_72 -> V_17 ) ;
int V_36 , V_86 ;
if ( V_72 -> V_87 )
return - V_39 ;
if ( V_85 -> type != V_88 )
return - V_27 ;
for ( V_36 = 0 , V_86 = 0 ; V_36 < V_28 ; V_36 ++ ) {
if ( V_2 -> V_29 [ V_36 ] . V_89 != V_85 -> V_29 . type )
continue;
if ( V_85 -> V_86 == - 1 || V_85 -> V_86 == V_86 )
goto V_90;
V_86 ++ ;
}
return - V_91 ;
V_90:
F_10 ( & V_2 -> V_24 ) ;
V_85 -> V_29 . V_3 = V_36 ;
V_85 -> V_29 . V_30 = false ;
V_2 -> V_29 [ V_36 ] . V_29 = & V_85 -> V_29 ;
F_11 ( & V_2 -> V_24 ) ;
return 0 ;
}
static void F_46 ( struct V_71 * V_72 ,
struct V_71 * V_85 )
{
struct V_1 * V_2 = F_36 ( & V_72 -> V_17 ) ;
int V_3 = V_85 -> V_29 . V_3 ;
if ( V_72 -> V_87 )
return;
F_10 ( & V_2 -> V_24 ) ;
V_85 -> V_29 . V_3 = - 1 ;
V_85 -> V_29 . V_30 = false ;
V_2 -> V_29 [ V_3 ] . V_29 = NULL ;
F_11 ( & V_2 -> V_24 ) ;
}
static int
F_47 ( struct V_71 * V_72 , unsigned int V_13 )
{
struct V_1 * V_2 = F_36 ( & V_72 -> V_17 ) ;
int V_3 = 0 ;
if ( V_13 > V_52 )
V_13 = V_52 ;
F_10 ( & V_2 -> V_24 ) ;
if ( V_2 -> V_13 [ V_13 ] == - 1 ) {
F_15 ( V_13 , V_2 -> V_29 [ V_3 ] . V_13 ) ;
V_2 -> V_13 [ V_13 ] = V_3 ;
}
F_11 ( & V_2 -> V_24 ) ;
return 0 ;
}
static int F_48 ( struct V_71 * V_72 )
{
struct V_16 * V_17 = & V_72 -> V_17 ;
struct V_79 * V_80 = F_36 ( V_17 -> V_92 ) ;
struct V_1 * V_2 ;
struct V_93 * V_94 ;
void T_4 * V_10 ;
int V_36 , V_95 ;
V_94 = F_49 ( V_72 , V_96 , 0 ) ;
if ( ! V_94 )
return - V_31 ;
V_10 = F_50 ( V_17 , V_94 -> V_97 , F_51 ( V_94 ) ) ;
if ( ! V_10 )
return - V_54 ;
V_2 = F_52 ( V_17 , sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_10 = V_10 ;
F_53 ( & V_2 -> V_24 ) ;
F_54 ( V_17 , V_2 ) ;
if ( V_72 -> V_87 )
return 0 ;
V_95 = F_21 ( V_2 ) ;
if ( V_95 ) {
if ( V_95 != - V_39 )
return V_95 ;
V_72 -> V_87 = true ;
return 0 ;
}
for ( V_36 = 0 ; V_36 < V_52 + 1 ; V_36 ++ )
V_2 -> V_13 [ V_36 ] = - 1 ;
for ( V_36 = 0 ; V_36 < V_28 ; V_36 ++ ) {
V_2 -> V_29 [ V_36 ] . V_2 = V_2 ;
V_2 -> V_29 [ V_36 ] . V_98 = V_36 ;
V_2 -> V_29 [ V_36 ] . V_89 =
F_20 ( V_2 , V_36 , F_22 ( V_3 ) ) ;
if ( V_2 -> V_29 [ V_36 ] . V_89 == V_42 )
continue;
V_95 = F_55 ( V_80 , V_2 -> V_29 [ V_36 ] . V_89 ) ;
if ( V_95 && V_95 != - V_31 )
return V_95 ;
}
if ( F_33 ( V_2 ) ||
F_28 ( V_2 ) ) {
F_56 ( L_10 ) ;
if ( V_2 -> V_70 . V_50 )
F_57 ( & V_2 -> V_17 -> V_62 , & V_2 -> V_70 ) ;
return - V_54 ;
}
return 0 ;
}
static void F_58 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_36 ( & V_72 -> V_17 ) ;
F_57 ( & V_2 -> V_17 -> V_62 , & V_2 -> V_70 ) ;
F_57 ( & V_2 -> V_17 -> V_62 , & V_2 -> V_61 ) ;
}
