static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 = NULL ;
V_5 = V_2 -> V_6 ;
F_2 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_8 ) {
V_3 = F_3 ( F_4 ( V_9 ) , V_9 ) ;
if ( V_3 )
goto V_10;
V_2 -> V_8 = true ;
}
F_5 ( V_5 -> V_11 ) ;
V_10:
F_6 ( & V_2 -> V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_2 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_8 ) {
V_3 = F_8 ( F_4 ( V_9 ) , V_9 ) ;
if ( V_3 )
goto V_10;
V_2 -> V_8 = false ;
}
V_10:
F_6 ( & V_2 -> V_7 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_12 , int V_13 )
{
T_1 V_14 [ 1 ] ;
struct V_15 V_16 ;
struct V_17 V_18 = {
. V_19 = 2 ,
. V_20 = V_14 ,
} ;
V_14 [ 0 ] = ( V_12 << 8 ) | V_13 ;
F_10 ( & V_16 ) ;
F_11 ( & V_18 , & V_16 ) ;
return F_12 ( V_2 -> V_21 , & V_16 ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned char V_22 ,
unsigned char V_23 )
{
int V_3 = 0 ;
if ( V_22 != V_24 )
V_3 = F_9 ( V_2 , 0x0 , V_22 ) ;
if ( V_23 != V_25 )
V_3 = F_9 ( V_2 , 0x1 , V_23 ) ;
return V_3 ;
}
static int F_14 ( struct V_1 * V_2 ,
const unsigned short * V_26 )
{
int V_3 = 0 , V_27 = 0 ;
while ( ( V_26 [ V_27 ] & V_28 ) != V_29 ) {
if ( ( V_26 [ V_27 ] & V_28 ) != V_30 ) {
V_3 = F_13 ( V_2 , V_26 [ V_27 ] , V_26 [ V_27 + 1 ] ) ;
if ( V_3 )
break;
} else {
F_5 ( V_26 [ V_27 + 1 ] ) ;
}
V_27 += 2 ;
}
return V_3 ;
}
static int F_15 ( struct V_1 * V_2 , const unsigned int * gamma )
{
unsigned int V_27 = 0 ;
int V_3 = 0 ;
V_3 = F_14 ( V_2 , V_31 ) ;
if ( V_3 ) {
F_16 ( V_2 -> V_32 , L_1 ) ;
goto V_33;
}
for ( V_27 = 0 ; V_27 < V_34 ; V_27 ++ ) {
V_3 = F_13 ( V_2 , V_24 , gamma [ V_27 ] ) ;
if ( V_3 ) {
F_16 ( V_2 -> V_32 , L_2 ) ;
goto V_33;
}
}
V_3 = F_14 ( V_2 , V_35 ) ;
if ( V_3 )
F_16 ( V_2 -> V_32 , L_3 ) ;
V_33:
return V_3 ;
}
static int F_17 ( struct V_1 * V_2 , int gamma )
{
return F_15 ( V_2 , V_36 . V_37 [ gamma ] ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_3 , V_27 ;
static const unsigned short * V_38 [] = {
V_39 ,
V_40 ,
V_41 ,
V_42 ,
V_43 ,
V_44 ,
V_45 ,
V_35 ,
V_46 ,
} ;
for ( V_27 = 0 ; V_27 < F_4 ( V_38 ) ; V_27 ++ ) {
V_3 = F_14 ( V_2 , V_38 [ V_27 ] ) ;
F_19 ( 300 , 310 ) ;
if ( V_3 )
break;
}
return V_3 ;
}
static int F_20 ( struct V_1 * V_2 )
{
return F_14 ( V_2 , V_47 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_14 ( V_2 , V_48 ) ;
V_3 = F_14 ( V_2 , V_49 ) ;
return V_3 ;
}
static int F_22 ( int V_50 )
{
return V_50 <= V_51 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
V_5 = V_2 -> V_6 ;
F_1 ( V_2 ) ;
if ( ! V_5 -> V_52 ) {
F_16 ( V_2 -> V_32 , L_4 ) ;
return - V_53 ;
} else {
V_5 -> V_52 ( V_2 -> V_54 ) ;
F_5 ( V_5 -> V_55 ) ;
}
V_3 = F_18 ( V_2 ) ;
if ( V_3 ) {
F_16 ( V_2 -> V_32 , L_5 ) ;
return V_3 ;
}
V_3 = F_20 ( V_2 ) ;
if ( V_3 ) {
F_16 ( V_2 -> V_32 , L_6 ) ;
return V_3 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
V_5 = V_2 -> V_6 ;
V_3 = F_21 ( V_2 ) ;
if ( V_3 ) {
F_16 ( V_2 -> V_32 , L_7 ) ;
return - V_56 ;
}
F_5 ( V_5 -> V_57 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , int V_50 )
{
int V_3 = 0 ;
if ( F_22 ( V_50 ) && ! F_22 ( V_2 -> V_50 ) )
V_3 = F_23 ( V_2 ) ;
else if ( ! F_22 ( V_50 ) && F_22 ( V_2 -> V_50 ) )
V_3 = F_24 ( V_2 ) ;
if ( ! V_3 )
V_2 -> V_50 = V_50 ;
return V_3 ;
}
static int F_26 ( struct V_58 * V_54 , int V_50 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
if ( V_50 != V_59 && V_50 != V_60 &&
V_50 != V_51 ) {
F_16 ( V_2 -> V_32 , L_8 ) ;
return - V_53 ;
}
return F_25 ( V_2 , V_50 ) ;
}
static int F_28 ( struct V_58 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
return V_2 -> V_50 ;
}
static int F_29 ( struct V_61 * V_62 )
{
return V_62 -> V_63 . V_64 ;
}
static int F_30 ( struct V_61 * V_62 )
{
int V_3 = 0 , V_64 = V_62 -> V_63 . V_64 ;
struct V_1 * V_2 = F_31 ( V_62 ) ;
if ( V_64 < V_65 ||
V_64 > V_62 -> V_63 . V_66 ) {
F_16 ( & V_62 -> V_32 , L_9 ,
V_65 , V_67 ) ;
return - V_53 ;
}
V_3 = F_17 ( V_2 , V_62 -> V_63 . V_64 ) ;
if ( V_3 ) {
F_16 ( & V_62 -> V_32 , L_10 ) ;
return - V_56 ;
}
return V_3 ;
}
static int F_32 ( struct V_68 * V_21 )
{
int V_3 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_58 * V_54 = NULL ;
struct V_61 * V_62 = NULL ;
struct V_69 V_63 ;
V_2 = F_33 ( & V_21 -> V_32 , sizeof( struct V_1 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_21 -> V_72 = 9 ;
V_3 = F_34 ( V_21 ) ;
if ( V_3 < 0 ) {
F_16 ( & V_21 -> V_32 , L_11 ) ;
return V_3 ;
}
V_2 -> V_21 = V_21 ;
V_2 -> V_32 = & V_21 -> V_32 ;
V_2 -> V_6 = V_21 -> V_32 . V_73 ;
if ( ! V_2 -> V_6 ) {
F_16 ( & V_21 -> V_32 , L_12 ) ;
return - V_53 ;
}
F_35 ( & V_2 -> V_7 ) ;
V_3 = F_36 ( V_2 -> V_32 , F_4 ( V_9 ) , V_9 ) ;
if ( V_3 ) {
F_16 ( V_2 -> V_32 , L_13 , V_3 ) ;
return V_3 ;
}
V_54 = F_37 ( L_14 , & V_21 -> V_32 , V_2 , & V_74 ) ;
if ( F_38 ( V_54 ) )
return F_39 ( V_54 ) ;
V_2 -> V_54 = V_54 ;
memset ( & V_63 , 0 , sizeof( struct V_69 ) ) ;
V_63 . type = V_75 ;
V_63 . V_66 = V_67 ;
V_62 = F_40 ( L_15 , & V_21 -> V_32 ,
V_2 , & V_76 , & V_63 ) ;
if ( F_38 ( V_62 ) ) {
V_3 = F_39 ( V_62 ) ;
goto V_77;
}
V_62 -> V_63 . V_64 = V_67 ;
V_2 -> V_62 = V_62 ;
if ( ! V_2 -> V_6 -> V_78 ) {
V_2 -> V_50 = V_60 ;
F_25 ( V_2 , V_59 ) ;
} else {
V_2 -> V_50 = V_59 ;
}
F_41 ( V_21 , V_2 ) ;
F_42 ( & V_21 -> V_32 , L_16 ) ;
return 0 ;
V_77:
F_43 ( V_2 -> V_54 ) ;
return V_3 ;
}
static int F_44 ( struct V_68 * V_21 )
{
struct V_1 * V_2 = F_45 ( V_21 ) ;
F_25 ( V_2 , V_60 ) ;
F_46 ( V_2 -> V_62 ) ;
F_43 ( V_2 -> V_54 ) ;
return 0 ;
}
static int F_47 ( struct V_79 * V_32 )
{
struct V_1 * V_2 = F_48 ( V_32 ) ;
F_49 ( V_32 , L_17 , V_2 -> V_50 ) ;
return F_25 ( V_2 , V_60 ) ;
}
static int F_50 ( struct V_79 * V_32 )
{
struct V_1 * V_2 = F_48 ( V_32 ) ;
V_2 -> V_50 = V_60 ;
return F_25 ( V_2 , V_59 ) ;
}
static void F_51 ( struct V_68 * V_21 )
{
struct V_1 * V_2 = F_45 ( V_21 ) ;
F_25 ( V_2 , V_60 ) ;
}
