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
V_36 |= V_41 | V_42 ;
F_3 ( V_36 , V_2 -> V_10 + V_38 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( F_20 ( V_2 , V_3 , F_22 ( V_3 ) ) ==
V_43 )
continue;
F_1 ( V_2 , V_3 , 0 ) ;
F_5 ( V_2 , V_3 , 16 ) ;
}
F_3 ( 0 , V_2 -> V_10 + V_44 ) ;
for ( V_37 = 0 ; V_37 < 33 ; V_37 ++ )
F_3 ( 0 , V_2 -> V_10 + V_14 + V_37 * 4 ) ;
F_3 ( 0 , V_2 -> V_10 + V_45 ) ;
F_3 ( 0xfc , V_2 -> V_10 + V_46 ) ;
return 0 ;
}
static T_2 F_23 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
char * V_20 )
{
struct V_47 * V_48 =
F_9 ( V_19 , struct V_47 , V_19 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
T_3 V_23 ;
F_24 ( V_17 ) ;
F_10 ( & V_2 -> V_24 ) ;
V_23 = snprintf ( V_20 , V_25 , L_1 ,
F_20 ( V_2 , V_48 -> V_3 , V_48 -> V_33 ) ) ;
F_11 ( & V_2 -> V_24 ) ;
F_25 ( V_17 ) ;
return V_23 ;
}
static T_2 F_26 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
const char * V_20 , T_3 V_23 )
{
struct V_47 * V_48 =
F_9 ( V_19 , struct V_47 , V_19 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
unsigned int V_4 ;
if ( F_27 ( V_20 , 16 , & V_4 ) < 0 )
return - V_27 ;
F_24 ( V_17 ) ;
F_10 ( & V_2 -> V_24 ) ;
F_16 ( V_2 , V_48 -> V_3 , V_48 -> V_33 , V_4 ) ;
F_11 ( & V_2 -> V_24 ) ;
F_25 ( V_17 ) ;
return V_23 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_21 * V_49 ;
struct V_50 * * V_51 ;
int V_37 , V_52 = V_53 + 2 ;
V_51 = F_29 ( V_2 -> V_17 , V_52 , sizeof( void * ) , V_54 ) ;
if ( ! V_51 )
return - V_55 ;
V_49 = F_29 ( V_2 -> V_17 , V_52 ,
sizeof( struct V_21 ) ,
V_54 ) ;
if ( ! V_49 )
return - V_55 ;
for ( V_37 = 0 ; V_37 < V_53 + 1 ; V_37 ++ ) {
char * V_56 ;
V_56 = F_30 ( V_2 -> V_17 , V_54 , L_3 , V_37 ,
V_37 == V_53 ? L_4 : L_5 ) ;
if ( ! V_56 )
return - V_55 ;
V_49 [ V_37 ] . V_19 . V_19 . V_56 = V_56 ;
V_49 [ V_37 ] . V_19 . V_19 . V_57 = V_58 | V_59 ;
V_49 [ V_37 ] . V_19 . V_60 = F_8 ;
V_49 [ V_37 ] . V_19 . V_61 = F_12 ;
F_31 ( & V_49 [ V_37 ] . V_19 . V_19 ) ;
V_51 [ V_37 ] = & V_49 [ V_37 ] . V_19 . V_19 ;
V_49 [ V_37 ] . V_2 = V_2 ;
V_49 [ V_37 ] . V_13 = V_37 ;
}
V_2 -> V_62 . V_56 = L_6 ;
V_2 -> V_62 . V_51 = V_51 ;
return F_32 ( & V_2 -> V_17 -> V_63 , & V_2 -> V_62 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_47 * V_64 ;
struct V_50 * * V_51 ;
int V_37 , V_65 , V_66 = V_28 ;
int V_67 = F_34 ( V_34 ) ;
int V_52 = V_66 * V_67 + 1 ;
V_51 = F_29 ( V_2 -> V_17 , V_52 , sizeof( void * ) , V_54 ) ;
if ( ! V_51 )
return - V_55 ;
V_64 = F_29 ( V_2 -> V_17 , V_52 ,
sizeof( struct V_47 ) ,
V_54 ) ;
if ( ! V_64 )
return - V_55 ;
for ( V_37 = 0 ; V_37 < V_66 ; V_37 ++ ) {
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ ) {
unsigned int V_68 = V_37 * V_67 + V_65 ;
char * V_56 ;
V_56 = F_30 ( V_2 -> V_17 , V_54 , L_7 , V_37 ,
V_34 [ V_65 ] . V_56 ) ;
if ( ! V_56 )
return - V_55 ;
V_64 [ V_68 ] . V_19 . V_19 . V_56 = V_56 ;
if ( V_34 [ V_65 ] . V_69 ) {
V_64 [ V_68 ] . V_19 . V_19 . V_57 |= V_58 ;
V_64 [ V_68 ] . V_19 . V_60 = F_23 ;
}
if ( V_34 [ V_65 ] . V_70 ) {
V_64 [ V_68 ] . V_19 . V_19 . V_57 |= V_59 ;
V_64 [ V_68 ] . V_19 . V_61 = F_26 ;
}
F_31 ( & V_64 [ V_68 ] . V_19 . V_19 ) ;
V_51 [ V_68 ] = & V_64 [ V_68 ] . V_19 . V_19 ;
V_64 [ V_68 ] . V_2 = V_2 ;
V_64 [ V_68 ] . V_3 = V_37 ;
V_64 [ V_68 ] . V_33 = V_65 ;
}
}
V_2 -> V_71 . V_56 = L_8 ;
V_2 -> V_71 . V_51 = V_51 ;
return F_32 ( & V_2 -> V_17 -> V_63 , & V_2 -> V_71 ) ;
}
static void F_35 ( struct V_72 * V_73 ,
struct V_74 * V_29 )
{
struct V_1 * V_2 = F_36 ( & V_73 -> V_17 ) ;
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
F_3 ( 0 , V_2 -> V_10 + V_45 ) ;
F_3 ( 0xfd , V_2 -> V_10 + V_46 ) ;
for ( V_5 = 0 , V_23 = V_75 ;
V_23 && ! ( V_5 & F_38 ( V_29 -> V_3 ) ) ; V_23 -- ) {
V_5 = F_2 ( V_2 -> V_10 + V_76 ) ;
F_39 () ;
}
F_3 ( 0xfc , V_2 -> V_10 + V_46 ) ;
if ( ! V_23 )
F_40 ( & V_73 -> V_17 , L_9 ,
V_29 -> V_3 ) ;
V_5 = F_2 ( V_2 -> V_10 + V_38 ) ;
V_5 &= ~ V_29 -> V_36 ;
F_3 ( V_5 , V_2 -> V_10 + V_38 ) ;
}
static void F_41 ( struct V_72 * V_73 ,
struct V_74 * V_29 )
{
struct V_1 * V_2 = F_36 ( & V_73 -> V_17 ) ;
T_1 V_77 = 0xfc0000 , V_78 ;
int V_13 ;
F_10 ( & V_2 -> V_24 ) ;
F_37 (master, gth->output[output->port].master,
TH_CONFIGURABLE_MASTERS + 1 ) {
F_7 ( V_2 , V_13 , V_29 -> V_3 ) ;
}
if ( V_29 -> V_79 )
V_77 |= 0xff ;
V_29 -> V_30 = true ;
F_11 ( & V_2 -> V_24 ) ;
V_78 = F_2 ( V_2 -> V_10 + V_38 ) ;
V_78 |= V_29 -> V_36 ;
F_3 ( V_78 , V_2 -> V_10 + V_38 ) ;
F_3 ( V_77 , V_2 -> V_10 + V_45 ) ;
F_3 ( 0 , V_2 -> V_10 + V_46 ) ;
}
static int F_42 ( struct V_72 * V_73 ,
struct V_72 * V_80 )
{
struct V_1 * V_2 = F_36 ( & V_73 -> V_17 ) ;
int V_37 , V_81 ;
if ( V_73 -> V_82 )
return - V_40 ;
if ( V_80 -> type != V_83 )
return - V_27 ;
for ( V_37 = 0 , V_81 = 0 ; V_37 < V_28 ; V_37 ++ ) {
if ( V_2 -> V_29 [ V_37 ] . V_84 != V_80 -> V_29 . type )
continue;
if ( V_80 -> V_81 == - 1 || V_80 -> V_81 == V_81 )
goto V_85;
V_81 ++ ;
}
return - V_86 ;
V_85:
F_10 ( & V_2 -> V_24 ) ;
V_80 -> V_29 . V_3 = V_37 ;
V_80 -> V_29 . V_30 = false ;
V_2 -> V_29 [ V_37 ] . V_29 = & V_80 -> V_29 ;
F_11 ( & V_2 -> V_24 ) ;
return 0 ;
}
static void F_43 ( struct V_72 * V_73 ,
struct V_72 * V_80 )
{
struct V_1 * V_2 = F_36 ( & V_73 -> V_17 ) ;
int V_3 = V_80 -> V_29 . V_3 ;
if ( V_73 -> V_82 )
return;
F_10 ( & V_2 -> V_24 ) ;
V_80 -> V_29 . V_3 = - 1 ;
V_80 -> V_29 . V_30 = false ;
V_2 -> V_29 [ V_3 ] . V_29 = NULL ;
F_11 ( & V_2 -> V_24 ) ;
}
static int
F_44 ( struct V_72 * V_73 , unsigned int V_13 )
{
struct V_1 * V_2 = F_36 ( & V_73 -> V_17 ) ;
int V_3 = 0 ;
if ( V_13 > V_53 )
V_13 = V_53 ;
F_10 ( & V_2 -> V_24 ) ;
if ( V_2 -> V_13 [ V_13 ] == - 1 ) {
F_15 ( V_13 , V_2 -> V_29 [ V_3 ] . V_13 ) ;
V_2 -> V_13 [ V_13 ] = V_3 ;
}
F_11 ( & V_2 -> V_24 ) ;
return 0 ;
}
static int F_45 ( struct V_72 * V_73 )
{
struct V_16 * V_17 = & V_73 -> V_17 ;
struct V_1 * V_2 ;
struct V_87 * V_88 ;
void T_4 * V_10 ;
int V_37 , V_89 ;
V_88 = F_46 ( V_73 , V_90 , 0 ) ;
if ( ! V_88 )
return - V_31 ;
V_10 = F_47 ( V_17 , V_88 -> V_91 , F_48 ( V_88 ) ) ;
if ( ! V_10 )
return - V_55 ;
V_2 = F_49 ( V_17 , sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_10 = V_10 ;
F_50 ( & V_2 -> V_24 ) ;
if ( V_73 -> V_82 )
goto V_92;
V_89 = F_21 ( V_2 ) ;
if ( V_89 ) {
if ( V_89 != - V_40 )
return V_89 ;
V_73 -> V_82 = true ;
goto V_92;
}
for ( V_37 = 0 ; V_37 < V_53 + 1 ; V_37 ++ )
V_2 -> V_13 [ V_37 ] = - 1 ;
for ( V_37 = 0 ; V_37 < V_28 ; V_37 ++ ) {
V_2 -> V_29 [ V_37 ] . V_2 = V_2 ;
V_2 -> V_29 [ V_37 ] . V_93 = V_37 ;
V_2 -> V_29 [ V_37 ] . V_84 =
F_20 ( V_2 , V_37 , F_22 ( V_3 ) ) ;
}
if ( F_33 ( V_2 ) ||
F_28 ( V_2 ) ) {
F_51 ( L_10 ) ;
if ( V_2 -> V_71 . V_51 )
F_52 ( & V_2 -> V_17 -> V_63 , & V_2 -> V_71 ) ;
return - V_55 ;
}
V_92:
F_53 ( V_17 , V_2 ) ;
return 0 ;
}
static void F_54 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_36 ( & V_73 -> V_17 ) ;
F_52 ( & V_2 -> V_17 -> V_63 , & V_2 -> V_71 ) ;
F_52 ( & V_2 -> V_17 -> V_63 , & V_2 -> V_62 ) ;
}
