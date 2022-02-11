static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 [ V_8 ] ;
int V_9 ;
V_9 = F_2 ( V_6 , V_4 -> V_10 . V_11 ,
V_7 , sizeof( V_7 ) ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 , L_1 ,
V_13 , V_9 ) ;
return V_9 ;
}
F_4 ( V_14 , & V_4 -> V_12 , L_2 ,
V_13 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
V_9 = F_5 ( V_6 ,
V_4 -> V_10 . V_15 + V_16 ,
V_7 , sizeof( V_7 ) ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 , L_3 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_17 ,
unsigned int V_18 , bool V_19 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_9 ;
if ( V_19 ) {
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
F_7 ( & V_2 -> V_20 . V_21 ) ;
V_9 = F_8 ( V_6 , V_2 -> V_20 . V_22 , & V_2 -> V_20 . V_23 ) ;
if ( V_9 ) {
F_3 ( & V_2 -> V_4 -> V_12 ,
L_4 ,
V_13 , V_9 , V_17 ) ;
return V_9 ;
}
V_2 -> V_20 . V_23 |= V_17 & 0x0f ;
V_9 = F_9 ( V_6 , V_2 -> V_20 . V_22 , V_2 -> V_20 . V_23 ) ;
if ( V_9 < 0 ) {
F_3 ( & V_2 -> V_4 -> V_12 ,
L_5 ,
V_17 , V_9 ) ;
return V_9 ;
}
if ( ! F_10 ( & V_2 -> V_20 . V_21 ,
F_11 ( V_18 ) ) ) {
V_9 = F_8 ( V_6 , V_2 -> V_20 . V_22 , & V_2 -> V_20 . V_23 ) ;
if ( V_9 ) {
F_3 ( & V_2 -> V_4 -> V_12 ,
L_6 ,
V_13 , V_17 , V_9 ) ;
return V_9 ;
}
if ( V_2 -> V_20 . V_23 & 0x7f ) {
F_3 ( & V_2 -> V_4 -> V_12 ,
L_7 ,
V_13 , V_17 , V_2 -> V_20 . V_23 ) ;
return - V_24 ;
}
}
return 0 ;
}
static int F_12 ( struct V_3 * V_4 , unsigned long * V_25 )
{
struct V_1 * V_2 = F_13 ( & V_4 -> V_12 ) ;
int V_9 ;
if ( V_2 -> V_26 != 5 )
return 0 ;
V_9 = F_8 ( V_2 -> V_4 -> V_6 , V_2 -> V_20 . V_22 , & V_2 -> V_20 . V_23 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_8 ,
V_13 , V_2 -> V_20 . V_23 , V_9 ) ;
if ( ! V_9 && ! ( V_2 -> V_20 . V_23 & 0x7f ) )
F_14 ( & V_2 -> V_20 . V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , const void * V_27 ,
int V_28 , T_1 V_17 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_2 V_29 = V_4 -> V_10 . V_15 + V_16 ;
T_1 V_30 [] = { 0 , 0 } ;
int V_31 ;
int V_9 ;
V_9 = F_5 ( V_6 , V_4 -> V_10 . V_15 ,
V_30 , sizeof( V_30 ) ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 , L_9 , V_9 ) ;
return V_9 ;
}
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ ) {
V_9 = F_5 ( V_6 , V_29 ,
V_27 , V_2 -> V_20 . V_32 ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 ,
L_10 , V_31 , V_9 ) ;
return V_9 ;
}
V_9 = F_6 ( V_2 , V_17 , V_33 , false ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 ,
L_11 ,
V_31 , V_9 ) ;
return V_9 ;
}
F_4 ( V_14 , & V_4 -> V_12 , L_12 ,
V_31 + 1 , V_28 ) ;
V_27 += V_2 -> V_20 . V_32 ;
V_2 -> V_34 += V_2 -> V_20 . V_32 ;
V_2 -> V_35 = ( V_2 -> V_34 * 100 ) /
V_2 -> V_36 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , const void * V_27 )
{
return F_15 ( V_2 , V_27 , V_2 -> V_20 . V_37 ,
V_38 ) ;
}
static int F_17 ( struct V_1 * V_2 , const void * V_27 )
{
return F_15 ( V_2 , V_27 , V_2 -> V_20 . V_39 ,
V_40 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_41 ,
V_42 , true ) ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_43 * V_44 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_45 = F_20 ( V_44 -> V_45 ) ;
T_3 V_46 = F_20 ( V_44 -> V_46 ) ;
int V_9 ;
V_2 -> V_34 = 0 ;
V_2 -> V_36 = V_45 + V_46 ;
if ( V_45 ) {
F_21 ( & V_4 -> V_12 , L_13 ) ;
V_9 = F_6 ( V_2 , V_47 ,
V_48 , true ) ;
if ( V_9 )
return V_9 ;
F_21 ( & V_4 -> V_12 , L_14 ,
V_45 ) ;
V_9 = F_16 ( V_2 , V_44 -> V_27 ) ;
if ( V_9 )
return V_9 ;
}
if ( V_46 ) {
if ( ! V_45 ) {
F_21 ( & V_4 -> V_12 , L_15 ) ;
V_9 = F_6 ( V_2 , V_49 ,
V_48 , true ) ;
if ( V_9 )
return V_9 ;
}
F_21 ( & V_4 -> V_12 , L_16 ,
V_46 ) ;
V_9 = F_17 ( V_2 , & V_44 -> V_27 [ V_45 ] ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_50 * V_51 )
{
const struct V_43 * V_44 =
( const struct V_43 * ) V_51 -> V_27 ;
T_3 V_45 = F_20 ( V_44 -> V_45 ) ;
T_3 V_46 = F_20 ( V_44 -> V_46 ) ;
int V_9 ;
F_23 ( F_24 ( struct V_43 , V_27 ) !=
V_52 ) ;
F_4 ( V_14 , & V_2 -> V_4 -> V_12 ,
L_17 ,
V_51 -> V_53 ,
F_20 ( V_44 -> V_54 ) ,
V_45 , V_46 ) ;
F_4 ( V_14 , & V_2 -> V_4 -> V_12 ,
L_18 ,
V_44 -> V_55 ,
( int ) sizeof( V_44 -> V_56 ) , V_44 -> V_56 ,
V_44 -> V_57 [ 0 ] , V_44 -> V_57 [ 1 ] ) ;
if ( V_45 && V_45 != V_2 -> V_20 . V_37 * V_2 -> V_20 . V_32 ) {
F_3 ( & V_2 -> V_4 -> V_12 ,
L_19 ,
V_45 , V_2 -> V_20 . V_37 * V_2 -> V_20 . V_32 ) ;
V_9 = - V_58 ;
goto V_59;
}
if ( V_46 &&
V_46 != V_2 -> V_20 . V_39 * V_2 -> V_20 . V_32 ) {
F_3 ( & V_2 -> V_4 -> V_12 ,
L_20 ,
V_46 ,
V_2 -> V_20 . V_39 * V_2 -> V_20 . V_32 ) ;
V_9 = - V_58 ;
goto V_59;
}
if ( V_45 && ! V_46 ) {
F_3 ( & V_2 -> V_4 -> V_12 , L_21 ) ;
V_9 = - V_58 ;
goto V_59;
}
F_21 ( & V_2 -> V_4 -> V_12 , L_22 ) ;
F_25 ( & V_2 -> V_20 . V_60 ) ;
V_9 = F_19 ( V_2 , V_44 ) ;
F_26 ( & V_2 -> V_20 . V_60 ) ;
V_59:
return V_9 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_13 ( & V_4 -> V_12 ) ;
return V_2 -> V_35 ;
}
static T_4 F_28 ( struct V_61 * V_12 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_65 * V_27 = F_13 ( V_12 ) ;
struct V_3 * V_4 = V_27 -> V_66 ;
struct V_1 * V_2 ;
if ( V_4 ) {
V_2 = F_13 ( & V_4 -> V_12 ) ;
if ( V_2 -> V_26 == 5 )
return F_29 ( V_64 , V_67 , L_23 ,
V_2 -> V_7 [ 0 ] ,
V_2 -> V_7 [ 1 ] ) ;
else
return F_29 ( V_64 , V_67 , L_24 ,
V_2 -> V_7 [ 1 ] ,
V_2 -> V_7 [ 0 ] ) ;
}
return 0 ;
}
static T_4 F_30 ( struct V_61 * V_12 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_65 * V_27 = F_13 ( V_12 ) ;
struct V_3 * V_4 = V_27 -> V_66 ;
struct V_1 * V_2 ;
if ( V_4 ) {
V_2 = F_13 ( & V_4 -> V_12 ) ;
return F_29 ( V_64 , V_67 , L_25 , V_2 -> V_68 ) ;
}
return 0 ;
}
static int F_31 ( struct V_65 * V_27 ,
const struct V_50 * V_51 )
{
struct V_5 * V_6 = V_27 -> V_6 ;
struct V_61 * V_12 = & V_6 -> V_12 ;
struct V_1 * V_2 ;
int V_9 ;
if ( ! V_27 -> V_66 ) {
F_32 ( V_12 , L_26 , V_13 ) ;
return - V_69 ;
}
V_2 = F_13 ( & V_27 -> V_66 -> V_12 ) ;
if ( V_2 -> V_26 == 7 ) {
if ( V_27 -> V_70 & V_71 ) {
F_3 ( V_12 , L_27 , V_13 ) ;
return - V_72 ;
}
} else if ( V_2 -> V_26 != 5 ) {
F_32 ( V_12 , L_28 ,
V_27 -> V_66 -> V_10 . V_73 ) ;
return - V_72 ;
}
if ( V_2 -> V_26 == 7 )
V_9 = F_33 ( V_2 , V_51 ) ;
else
V_9 = F_18 ( V_2 ) ;
if ( V_9 )
return V_9 ;
F_34 ( V_6 , false ) ;
F_35 ( V_6 ) ;
V_9 = F_36 ( V_27 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_37 ( V_27 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_27 -> V_74 || ! V_27 -> V_66 ) {
F_32 ( V_12 , L_29 ,
V_13 ) ;
return - V_69 ;
}
F_38 ( V_6 , false ) ;
V_2 = F_13 ( & V_27 -> V_66 -> V_12 ) ;
if ( V_2 -> V_26 == 7 )
V_9 = F_39 ( V_2 , V_51 ) ;
else
V_9 = F_22 ( V_2 , V_51 ) ;
if ( V_9 ) {
V_2 -> V_35 = V_9 ;
F_3 ( & V_2 -> V_4 -> V_12 ,
L_30 , V_9 ) ;
} else {
F_21 ( & V_2 -> V_4 -> V_12 , L_31 ) ;
}
F_34 ( V_6 , false ) ;
F_4 ( V_14 , V_12 , L_32 ) ;
F_35 ( V_6 ) ;
V_9 = F_40 ( V_6 , NULL , V_75 ) ;
if ( V_9 < 0 )
F_32 ( V_12 , L_33 ) ;
V_9 = F_36 ( V_27 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_37 ( V_27 ) ;
if ( V_9 )
return V_9 ;
F_38 ( V_6 , false ) ;
if ( V_27 -> V_76 -> V_12 . V_77 )
return F_41 ( V_6 ) ;
F_4 ( V_14 , V_12 , L_34 , V_13 ) ;
return V_9 ;
}
static T_4 F_42 ( struct V_61 * V_12 ,
struct V_62 * V_63 ,
const char * V_64 , T_5 V_78 )
{
struct V_65 * V_27 = F_13 ( V_12 ) ;
char V_79 [ V_80 ] ;
const struct V_50 * V_51 ;
T_5 V_81 = V_78 ;
int V_9 ;
if ( V_78 == 0 || V_78 >= V_80 )
return - V_69 ;
if ( V_64 [ V_78 - 1 ] == '\0' || V_64 [ V_78 - 1 ] == '\n' )
V_81 -= 1 ;
strncpy ( V_79 , V_64 , V_81 ) ;
V_79 [ V_81 ] = '\0' ;
V_9 = F_43 ( & V_51 , V_79 , V_12 ) ;
if ( V_9 )
return V_9 ;
F_21 ( V_12 , L_35 , V_79 ) ;
V_9 = F_31 ( V_27 , V_51 ) ;
F_44 ( V_51 ) ;
return V_9 ? : V_78 ;
}
static T_4 F_45 ( struct V_61 * V_12 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_65 * V_27 = F_13 ( V_12 ) ;
int V_35 = 0 ;
if ( V_27 -> V_66 )
V_35 = F_27 ( V_27 -> V_66 ) ;
return F_29 ( V_64 , V_67 , L_36 , V_35 ) ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned char V_82 [ 9 ] ;
bool V_83 ;
T_1 V_84 = V_4 -> V_10 . V_73 ;
int V_9 ;
V_2 = F_47 ( & V_4 -> V_12 , sizeof( struct V_1 ) , V_85 ) ;
if ( ! V_2 )
return - V_86 ;
V_2 -> V_4 = V_4 ;
F_48 ( & V_4 -> V_12 , V_2 ) ;
if ( V_84 > 0 )
return F_49 ( V_2 ) ;
V_2 -> V_26 = 5 ;
V_9 = F_2 ( V_4 -> V_6 , V_4 -> V_10 . V_11 ,
V_82 , sizeof( V_82 ) ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 , L_37 ,
V_13 ) ;
return V_9 ;
}
snprintf ( V_2 -> V_7 , sizeof( V_2 -> V_7 ) ,
L_38 , V_82 [ 0 ] , V_82 [ 1 ] ) ;
F_50 ( & V_2 -> V_20 . V_60 ) ;
F_7 ( & V_2 -> V_20 . V_21 ) ;
V_2 -> V_20 . V_32 = F_51 ( & V_82 [ 3 ] ) ;
V_2 -> V_20 . V_37 = F_51 ( & V_82 [ 5 ] ) ;
V_2 -> V_20 . V_39 = F_51 ( & V_82 [ 7 ] ) ;
V_2 -> V_20 . V_22 = V_4 -> V_10 . V_15 + V_16 +
V_2 -> V_20 . V_32 ;
V_83 = V_82 [ 2 ] & ( 1 << 2 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_39 ,
V_2 -> V_7 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_40 ,
V_2 -> V_20 . V_32 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_41 ,
V_2 -> V_20 . V_37 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_42 ,
V_2 -> V_20 . V_39 ) ;
if ( V_83 ) {
V_9 = F_2 ( V_4 -> V_6 , V_4 -> V_10 . V_87 ,
V_82 , sizeof( V_82 ) ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 , L_43 ) ;
return V_9 ;
}
snprintf ( V_2 -> V_68 , sizeof( V_2 -> V_68 ) ,
L_44 ,
V_82 [ 0 ] , V_82 [ 1 ] ,
V_82 [ 2 ] , V_82 [ 3 ] ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_45 ,
V_2 -> V_68 ) ;
}
return 0 ;
}
int F_52 ( struct V_5 * V_6 )
{
return F_53 ( & V_6 -> V_12 . V_88 , & V_89 ) ;
}
void F_54 ( struct V_5 * V_6 )
{
F_55 ( & V_6 -> V_12 . V_88 , & V_89 ) ;
}
