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
T_1 V_23 ;
if ( V_2 -> V_26 == 5 ) {
V_9 = F_8 ( V_2 -> V_4 -> V_6 , V_2 -> V_20 . V_22 ,
& V_23 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_8 ,
V_13 , V_23 , V_9 ) ;
if ( ! V_9 && ! ( V_23 & 0x7f ) )
F_14 ( & V_2 -> V_20 . V_21 ) ;
} else {
V_9 = F_2 ( V_2 -> V_4 -> V_6 ,
V_2 -> V_4 -> V_10 . V_15 +
V_2 -> V_27 . V_28 . V_29 ,
& V_23 , sizeof( V_23 ) ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_8 ,
V_13 , V_23 , V_9 ) ;
if ( ! V_9 && ! ( V_23 & 0x1f ) )
F_14 ( & V_2 -> V_27 . V_21 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , const void * V_30 ,
int V_31 , T_1 V_17 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_2 V_32 = V_4 -> V_10 . V_15 + V_16 ;
T_1 V_33 [] = { 0 , 0 } ;
int V_34 ;
int V_9 ;
V_9 = F_5 ( V_6 , V_4 -> V_10 . V_15 ,
V_33 , sizeof( V_33 ) ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 , L_9 , V_9 ) ;
return V_9 ;
}
for ( V_34 = 0 ; V_34 < V_31 ; V_34 ++ ) {
V_9 = F_5 ( V_6 , V_32 ,
V_30 , V_2 -> V_20 . V_35 ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 ,
L_10 , V_34 , V_9 ) ;
return V_9 ;
}
V_9 = F_6 ( V_2 , V_17 , V_36 , false ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 ,
L_11 ,
V_34 , V_9 ) ;
return V_9 ;
}
F_4 ( V_14 , & V_4 -> V_12 , L_12 ,
V_34 + 1 , V_31 ) ;
V_30 += V_2 -> V_20 . V_35 ;
V_2 -> V_37 += V_2 -> V_20 . V_35 ;
V_2 -> V_38 = ( V_2 -> V_37 * 100 ) /
V_2 -> V_39 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , const void * V_30 )
{
return F_15 ( V_2 , V_30 , V_2 -> V_20 . V_40 ,
V_41 ) ;
}
static int F_17 ( struct V_1 * V_2 , const void * V_30 )
{
return F_15 ( V_2 , V_30 , V_2 -> V_20 . V_42 ,
V_43 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_44 ,
V_45 , true ) ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_46 * V_47 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_48 = F_20 ( V_47 -> V_48 ) ;
T_3 V_49 = F_20 ( V_47 -> V_49 ) ;
int V_9 ;
V_2 -> V_37 = 0 ;
V_2 -> V_39 = V_48 + V_49 ;
if ( V_48 ) {
F_21 ( & V_4 -> V_12 , L_13 ) ;
V_9 = F_6 ( V_2 , V_50 ,
V_51 , true ) ;
if ( V_9 )
return V_9 ;
F_21 ( & V_4 -> V_12 , L_14 ,
V_48 ) ;
V_9 = F_16 ( V_2 , V_47 -> V_30 ) ;
if ( V_9 )
return V_9 ;
}
if ( V_49 ) {
if ( ! V_48 ) {
F_21 ( & V_4 -> V_12 , L_15 ) ;
V_9 = F_6 ( V_2 , V_52 ,
V_51 , true ) ;
if ( V_9 )
return V_9 ;
}
F_21 ( & V_4 -> V_12 , L_16 ,
V_49 ) ;
V_9 = F_17 ( V_2 , & V_47 -> V_30 [ V_48 ] ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_53 * V_54 )
{
const struct V_46 * V_47 =
( const struct V_46 * ) V_54 -> V_30 ;
T_3 V_48 = F_20 ( V_47 -> V_48 ) ;
T_3 V_49 = F_20 ( V_47 -> V_49 ) ;
int V_9 ;
F_23 ( F_24 ( struct V_46 , V_30 ) !=
V_55 ) ;
F_4 ( V_14 , & V_2 -> V_4 -> V_12 ,
L_17 ,
V_54 -> V_56 ,
F_20 ( V_47 -> V_57 ) ,
V_48 , V_49 ) ;
F_4 ( V_14 , & V_2 -> V_4 -> V_12 ,
L_18 ,
V_47 -> V_58 ,
( int ) sizeof( V_47 -> V_59 ) , V_47 -> V_59 ,
V_47 -> V_60 [ 0 ] , V_47 -> V_60 [ 1 ] ) ;
if ( V_48 && V_48 != V_2 -> V_20 . V_40 * V_2 -> V_20 . V_35 ) {
F_3 ( & V_2 -> V_4 -> V_12 ,
L_19 ,
V_48 , V_2 -> V_20 . V_40 * V_2 -> V_20 . V_35 ) ;
V_9 = - V_61 ;
goto V_62;
}
if ( V_49 &&
V_49 != V_2 -> V_20 . V_42 * V_2 -> V_20 . V_35 ) {
F_3 ( & V_2 -> V_4 -> V_12 ,
L_20 ,
V_49 ,
V_2 -> V_20 . V_42 * V_2 -> V_20 . V_35 ) ;
V_9 = - V_61 ;
goto V_62;
}
if ( V_48 && ! V_49 ) {
F_3 ( & V_2 -> V_4 -> V_12 , L_21 ) ;
V_9 = - V_61 ;
goto V_62;
}
F_21 ( & V_2 -> V_4 -> V_12 , L_22 ) ;
F_25 ( & V_2 -> V_20 . V_63 ) ;
V_9 = F_19 ( V_2 , V_47 ) ;
F_26 ( & V_2 -> V_20 . V_63 ) ;
V_62:
return V_9 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_13 ( & V_4 -> V_12 ) ;
return V_2 -> V_38 ;
}
static T_4 F_28 ( struct V_64 * V_12 ,
struct V_65 * V_66 ,
char * V_67 )
{
struct V_68 * V_30 = F_13 ( V_12 ) ;
struct V_3 * V_4 = V_30 -> V_69 ;
struct V_1 * V_2 ;
if ( V_4 ) {
V_2 = F_13 ( & V_4 -> V_12 ) ;
if ( V_2 -> V_26 == 5 )
return F_29 ( V_67 , V_70 , L_23 ,
V_2 -> V_7 [ 0 ] ,
V_2 -> V_7 [ 1 ] ) ;
else
return F_29 ( V_67 , V_70 , L_24 ,
V_2 -> V_7 [ 1 ] ,
V_2 -> V_7 [ 0 ] ) ;
}
return 0 ;
}
static T_4 F_30 ( struct V_64 * V_12 ,
struct V_65 * V_66 ,
char * V_67 )
{
struct V_68 * V_30 = F_13 ( V_12 ) ;
struct V_3 * V_4 = V_30 -> V_69 ;
struct V_1 * V_2 ;
if ( V_4 ) {
V_2 = F_13 ( & V_4 -> V_12 ) ;
return F_29 ( V_67 , V_70 , L_25 , V_2 -> V_71 ) ;
}
return 0 ;
}
static int F_31 ( struct V_68 * V_30 ,
const struct V_53 * V_54 )
{
struct V_5 * V_6 = V_30 -> V_6 ;
struct V_64 * V_12 = & V_6 -> V_12 ;
struct V_1 * V_2 ;
int V_9 ;
if ( ! V_30 -> V_69 ) {
F_32 ( V_12 , L_26 , V_13 ) ;
return - V_72 ;
}
V_2 = F_13 ( & V_30 -> V_69 -> V_12 ) ;
if ( V_2 -> V_26 == 7 ) {
if ( V_30 -> V_73 & V_74 ) {
F_3 ( V_12 , L_27 , V_13 ) ;
return - V_75 ;
}
} else if ( V_2 -> V_26 != 5 ) {
F_32 ( V_12 , L_28 ,
V_30 -> V_69 -> V_10 . V_76 ) ;
return - V_75 ;
}
if ( V_2 -> V_26 == 7 )
V_9 = F_33 ( V_2 , V_54 ) ;
else
V_9 = F_18 ( V_2 ) ;
if ( V_9 )
return V_9 ;
F_34 ( V_6 , false ) ;
F_35 ( V_6 ) ;
V_9 = F_36 ( V_30 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_37 ( V_30 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_30 -> V_77 || ! V_30 -> V_69 ) {
F_32 ( V_12 , L_29 ,
V_13 ) ;
return - V_72 ;
}
F_38 ( V_6 , false ) ;
V_2 = F_13 ( & V_30 -> V_69 -> V_12 ) ;
if ( V_2 -> V_26 == 7 )
V_9 = F_39 ( V_2 , V_54 ) ;
else
V_9 = F_22 ( V_2 , V_54 ) ;
if ( V_9 ) {
V_2 -> V_38 = V_9 ;
F_3 ( & V_2 -> V_4 -> V_12 ,
L_30 , V_9 ) ;
} else {
F_21 ( & V_2 -> V_4 -> V_12 , L_31 ) ;
}
F_34 ( V_6 , false ) ;
F_4 ( V_14 , V_12 , L_32 ) ;
F_35 ( V_6 ) ;
V_9 = F_40 ( V_6 , NULL , V_78 ) ;
if ( V_9 < 0 )
F_32 ( V_12 , L_33 ) ;
V_9 = F_36 ( V_30 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_37 ( V_30 ) ;
if ( V_9 )
return V_9 ;
F_38 ( V_6 , false ) ;
if ( V_30 -> V_79 -> V_12 . V_80 )
return F_41 ( V_6 ) ;
F_4 ( V_14 , V_12 , L_34 , V_13 ) ;
return V_9 ;
}
static T_4 F_42 ( struct V_64 * V_12 ,
struct V_65 * V_66 ,
const char * V_67 , T_5 V_81 )
{
struct V_68 * V_30 = F_13 ( V_12 ) ;
char V_82 [ V_83 ] ;
const struct V_53 * V_54 ;
T_5 V_84 = V_81 ;
int V_9 ;
if ( V_81 == 0 || V_81 >= V_83 )
return - V_72 ;
if ( V_67 [ V_81 - 1 ] == '\0' || V_67 [ V_81 - 1 ] == '\n' )
V_84 -= 1 ;
strncpy ( V_82 , V_67 , V_84 ) ;
V_82 [ V_84 ] = '\0' ;
V_9 = F_43 ( & V_54 , V_82 , V_12 ) ;
if ( V_9 )
return V_9 ;
F_21 ( V_12 , L_35 , V_82 ) ;
V_9 = F_31 ( V_30 , V_54 ) ;
F_44 ( V_54 ) ;
return V_9 ? : V_81 ;
}
static T_4 F_45 ( struct V_64 * V_12 ,
struct V_65 * V_66 ,
char * V_67 )
{
struct V_68 * V_30 = F_13 ( V_12 ) ;
int V_38 = 0 ;
if ( V_30 -> V_69 )
V_38 = F_27 ( V_30 -> V_69 ) ;
return F_29 ( V_67 , V_70 , L_36 , V_38 ) ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned char V_85 [ 9 ] ;
bool V_86 ;
T_1 V_87 = V_4 -> V_10 . V_76 ;
int V_9 ;
V_2 = F_47 ( & V_4 -> V_12 , sizeof( struct V_1 ) , V_88 ) ;
if ( ! V_2 )
return - V_89 ;
V_2 -> V_4 = V_4 ;
F_48 ( & V_4 -> V_12 , V_2 ) ;
if ( V_87 > 0 )
return F_49 ( V_2 ) ;
V_2 -> V_26 = 5 ;
V_9 = F_2 ( V_4 -> V_6 , V_4 -> V_10 . V_11 ,
V_85 , sizeof( V_85 ) ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 , L_37 ,
V_13 ) ;
return V_9 ;
}
snprintf ( V_2 -> V_7 , sizeof( V_2 -> V_7 ) ,
L_38 , V_85 [ 0 ] , V_85 [ 1 ] ) ;
F_50 ( & V_2 -> V_20 . V_63 ) ;
F_7 ( & V_2 -> V_20 . V_21 ) ;
V_2 -> V_20 . V_35 = F_51 ( & V_85 [ 3 ] ) ;
V_2 -> V_20 . V_40 = F_51 ( & V_85 [ 5 ] ) ;
V_2 -> V_20 . V_42 = F_51 ( & V_85 [ 7 ] ) ;
V_2 -> V_20 . V_22 = V_4 -> V_10 . V_15 + V_16 +
V_2 -> V_20 . V_35 ;
V_86 = V_85 [ 2 ] & ( 1 << 2 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_39 ,
V_2 -> V_7 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_40 ,
V_2 -> V_20 . V_35 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_41 ,
V_2 -> V_20 . V_40 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_42 ,
V_2 -> V_20 . V_42 ) ;
if ( V_86 ) {
V_9 = F_2 ( V_4 -> V_6 , V_4 -> V_10 . V_90 ,
V_85 , sizeof( V_85 ) ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 , L_43 ) ;
return V_9 ;
}
snprintf ( V_2 -> V_71 , sizeof( V_2 -> V_71 ) ,
L_44 ,
V_85 [ 0 ] , V_85 [ 1 ] ,
V_85 [ 2 ] , V_85 [ 3 ] ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_45 ,
V_2 -> V_71 ) ;
}
return 0 ;
}
int F_52 ( struct V_5 * V_6 )
{
return F_53 ( & V_6 -> V_12 . V_91 , & V_92 ) ;
}
void F_54 ( struct V_5 * V_6 )
{
F_55 ( & V_6 -> V_12 . V_91 , & V_92 ) ;
}
