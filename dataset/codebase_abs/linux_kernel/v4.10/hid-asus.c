static void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 * V_4 )
{
int V_5 , V_6 ;
int V_7 = ( V_4 [ 0 ] & V_8 ) << 4 | V_4 [ 1 ] ;
int V_9 = V_10 - ( ( V_4 [ 0 ] & V_11 ) << 8 | V_4 [ 2 ] ) ;
if ( V_3 == V_12 ) {
V_5 = V_13 ;
V_6 = V_14 ;
} else {
V_5 = ( V_4 [ 3 ] >> 4 ) & V_15 ;
V_6 = V_4 [ 4 ] & V_16 ;
}
F_2 ( V_2 , V_17 , V_7 ) ;
F_2 ( V_2 , V_18 , V_9 ) ;
F_2 ( V_2 , V_19 , V_5 ) ;
F_2 ( V_2 , V_20 , V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_23 * V_24 ;
int V_25 , V_26 , V_27 ;
V_24 = NULL ;
V_25 = V_22 -> V_28 ;
V_26 = 0 ;
for ( V_27 = 0 ; V_27 < V_22 -> V_29 ; ++ V_27 ) {
struct V_23 * V_30 = & V_22 -> V_31 [ V_27 ] ;
int V_32 = F_4 ( V_30 , V_33 ) ;
if ( V_32 < 0 )
continue;
if ( ( V_32 - V_25 ) & V_34 ) {
V_24 = V_30 ;
V_25 = V_32 ;
}
V_26 ++ ;
}
if ( V_24 ) {
F_2 ( V_2 , V_35 ,
F_4 ( V_24 , V_19 ) ) ;
}
}
static void F_5 ( struct V_1 * V_2 , T_1 * V_4 )
{
int V_27 ;
T_1 * V_36 = V_4 + 2 ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
bool V_38 = ! ! ( V_4 [ 1 ] & F_6 ( V_27 + 3 ) ) ;
int V_3 = V_36 [ 3 ] & V_39 ?
V_12 : V_40 ;
V_23 ( V_2 , V_27 ) ;
F_7 ( V_2 , V_3 , V_38 ) ;
if ( V_38 ) {
F_1 ( V_2 , V_3 , V_36 ) ;
V_36 += V_41 ;
}
}
F_8 ( V_2 , V_42 , V_4 [ 1 ] & V_43 ) ;
F_3 ( V_2 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_44 * V_45 ,
struct V_46 * V_47 , T_1 * V_4 , int V_48 )
{
struct V_49 * V_50 = F_12 ( V_45 ) ;
if ( V_50 -> V_51 & V_52 &&
V_4 [ 0 ] == V_53 &&
V_48 == V_54 ) {
F_5 ( V_50 -> V_2 , V_4 ) ;
return 1 ;
}
return 0 ;
}
static int F_13 ( struct V_44 * V_45 , struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_49 * V_50 = F_12 ( V_45 ) ;
if ( V_50 -> V_51 & V_52 ) {
int V_57 ;
F_14 ( V_2 , V_17 , 0 , V_58 , 0 , 0 ) ;
F_14 ( V_2 , V_18 , 0 , V_10 , 0 , 0 ) ;
F_14 ( V_2 , V_35 , 0 , V_13 , 0 , 0 ) ;
F_14 ( V_2 , V_19 , 0 , V_13 , 0 , 0 ) ;
F_14 ( V_2 , V_20 , 0 , V_14 , 0 , 0 ) ;
F_15 ( V_42 , V_2 -> V_59 ) ;
F_15 ( V_60 , V_2 -> V_61 ) ;
V_57 = F_16 ( V_2 , V_37 , V_62 ) ;
if ( V_57 ) {
F_17 ( V_45 , L_1 , V_57 ) ;
return V_57 ;
}
}
V_50 -> V_2 = V_2 ;
return 0 ;
}
static int F_18 ( struct V_44 * V_45 ,
struct V_55 * V_56 , struct V_63 * V_64 ,
struct V_65 * V_66 , unsigned long * * V_67 ,
int * V_68 )
{
struct V_49 * V_50 = F_12 ( V_45 ) ;
if ( V_50 -> V_51 & V_69 ) {
return - 1 ;
}
return 0 ;
}
static int F_19 ( struct V_44 * V_45 )
{
int V_57 ;
const unsigned char V_70 [] = { V_71 , 0x00 , 0x03 , 0x01 , 0x00 } ;
unsigned char * V_72 = F_20 ( V_70 , sizeof( V_70 ) , V_73 ) ;
if ( ! V_72 ) {
V_57 = - V_74 ;
F_17 ( V_45 , L_2 , V_57 ) ;
return V_57 ;
}
V_57 = F_21 ( V_45 , V_72 [ 0 ] , V_72 , sizeof( V_70 ) ,
V_75 , V_76 ) ;
F_22 ( V_72 ) ;
if ( V_57 != sizeof( V_70 ) ) {
F_17 ( V_45 , L_3 , V_57 ) ;
return V_57 ;
}
return 0 ;
}
static int T_2 F_23 ( struct V_44 * V_45 )
{
struct V_49 * V_50 = F_12 ( V_45 ) ;
if ( V_50 -> V_51 & V_52 )
return F_19 ( V_45 ) ;
return 0 ;
}
static int F_24 ( struct V_44 * V_45 , const struct V_77 * V_32 )
{
int V_57 ;
struct V_49 * V_50 ;
V_50 = F_25 ( & V_45 -> V_78 , sizeof( * V_50 ) , V_73 ) ;
if ( V_50 == NULL ) {
F_17 ( V_45 , L_4 ) ;
return - V_74 ;
}
F_26 ( V_45 , V_50 ) ;
V_50 -> V_51 = V_32 -> V_79 ;
if ( V_50 -> V_51 & V_80 )
V_45 -> V_51 |= V_81 ;
V_57 = F_27 ( V_45 ) ;
if ( V_57 ) {
F_17 ( V_45 , L_5 , V_57 ) ;
return V_57 ;
}
V_57 = F_28 ( V_45 , V_82 ) ;
if ( V_57 ) {
F_17 ( V_45 , L_6 , V_57 ) ;
return V_57 ;
}
if ( ! V_50 -> V_2 ) {
F_17 ( V_45 , L_7 ) ;
V_57 = - V_74 ;
goto V_83;
}
if ( V_50 -> V_51 & V_52 ) {
V_50 -> V_2 -> V_84 = L_8 ;
} else {
V_50 -> V_2 -> V_84 = L_9 ;
}
if ( V_50 -> V_51 & V_52 ) {
V_57 = F_19 ( V_45 ) ;
if ( V_57 )
goto V_83;
}
return 0 ;
V_83:
F_29 ( V_45 ) ;
return V_57 ;
}
static T_3 * F_30 ( struct V_44 * V_45 , T_3 * V_85 ,
unsigned int * V_86 )
{
struct V_49 * V_50 = F_12 ( V_45 ) ;
if ( V_50 -> V_51 & V_87 &&
* V_86 >= 56 && V_85 [ 54 ] == 0x25 && V_85 [ 55 ] == 0x65 ) {
F_31 ( V_45 , L_10 ) ;
V_85 [ 55 ] = 0xdd ;
}
return V_85 ;
}
