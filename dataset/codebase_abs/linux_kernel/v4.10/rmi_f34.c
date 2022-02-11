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
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , const void * V_27 )
{
return F_15 ( V_2 , V_27 , V_2 -> V_20 . V_34 ,
V_35 ) ;
}
static int F_17 ( struct V_1 * V_2 , const void * V_27 )
{
return F_15 ( V_2 , V_27 , V_2 -> V_20 . V_36 ,
V_37 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_38 ,
V_39 , true ) ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_40 * V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_9 ;
if ( V_41 -> V_42 ) {
F_20 ( & V_4 -> V_12 , L_13 ) ;
V_9 = F_6 ( V_2 , V_43 ,
V_44 , true ) ;
if ( V_9 )
return V_9 ;
F_20 ( & V_4 -> V_12 , L_14 ,
V_41 -> V_42 ) ;
V_9 = F_16 ( V_2 , V_41 -> V_27 ) ;
if ( V_9 )
return V_9 ;
}
if ( V_41 -> V_45 ) {
if ( ! V_41 -> V_42 ) {
F_20 ( & V_4 -> V_12 , L_15 ) ;
V_9 = F_6 ( V_2 , V_46 ,
V_44 , true ) ;
if ( V_9 )
return V_9 ;
}
F_20 ( & V_4 -> V_12 , L_16 ,
V_41 -> V_45 ) ;
V_9 = F_17 ( V_2 ,
& V_41 -> V_27 [ V_41 -> V_42 ] ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 , const struct V_47 * V_48 )
{
const struct V_40 * V_41 ;
int V_9 ;
V_41 = ( const struct V_40 * ) V_48 -> V_27 ;
F_22 ( F_23 ( struct V_40 , V_27 ) !=
V_49 ) ;
F_4 ( V_14 , & V_2 -> V_4 -> V_12 ,
L_17 ,
( int ) V_48 -> V_50 ,
F_24 ( V_41 -> V_51 ) ,
F_24 ( V_41 -> V_42 ) ,
F_24 ( V_41 -> V_45 ) ) ;
F_4 ( V_14 , & V_2 -> V_4 -> V_12 ,
L_18 ,
V_41 -> V_52 ,
( int ) sizeof( V_41 -> V_53 ) , V_41 -> V_53 ,
V_41 -> V_54 [ 0 ] , V_41 -> V_54 [ 1 ] ) ;
if ( V_41 -> V_42 &&
V_41 -> V_42 != V_2 -> V_20 . V_34 * V_2 -> V_20 . V_32 ) {
F_3 ( & V_2 -> V_4 -> V_12 ,
L_19 ,
V_41 -> V_42 ,
V_2 -> V_20 . V_34 * V_2 -> V_20 . V_32 ) ;
V_9 = - V_55 ;
goto V_56;
}
if ( V_41 -> V_45 &&
V_41 -> V_45 != V_2 -> V_20 . V_36 * V_2 -> V_20 . V_32 ) {
F_3 ( & V_2 -> V_4 -> V_12 ,
L_20 ,
V_41 -> V_45 ,
V_2 -> V_20 . V_36 * V_2 -> V_20 . V_32 ) ;
V_9 = - V_55 ;
goto V_56;
}
if ( V_41 -> V_42 && ! V_41 -> V_45 ) {
F_3 ( & V_2 -> V_4 -> V_12 , L_21 ) ;
V_9 = - V_55 ;
goto V_56;
}
F_20 ( & V_2 -> V_4 -> V_12 , L_22 ) ;
F_25 ( & V_2 -> V_20 . V_57 ) ;
V_9 = F_19 ( V_2 , V_41 ) ;
F_26 ( & V_2 -> V_20 . V_57 ) ;
V_56:
return V_9 ;
}
static int F_27 ( struct V_58 * V_27 ,
const struct V_47 * V_48 )
{
struct V_5 * V_6 = V_27 -> V_6 ;
struct V_59 * V_12 = & V_6 -> V_12 ;
struct V_1 * V_2 ;
int V_9 ;
if ( ! V_27 -> V_60 ) {
F_28 ( V_12 , L_23 , V_13 ) ;
return - V_61 ;
}
V_2 = F_13 ( & V_27 -> V_60 -> V_12 ) ;
if ( V_2 -> V_26 == 7 ) {
if ( V_27 -> V_62 & V_63 ) {
F_3 ( V_12 , L_24 , V_13 ) ;
return - V_64 ;
}
} else if ( V_2 -> V_26 != 5 ) {
F_28 ( V_12 , L_25 ,
V_27 -> V_60 -> V_10 . V_65 ) ;
return - V_64 ;
}
if ( V_2 -> V_26 == 7 )
V_9 = F_29 ( V_2 , V_48 ) ;
else
V_9 = F_18 ( V_2 ) ;
if ( V_9 )
return V_9 ;
F_30 ( V_6 , false ) ;
F_31 ( V_6 ) ;
V_9 = F_32 ( V_27 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_33 ( V_27 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_27 -> V_66 || ! V_27 -> V_60 ) {
F_28 ( V_12 , L_26 ,
V_13 ) ;
return - V_61 ;
}
F_34 ( V_6 , false ) ;
V_2 = F_13 ( & V_27 -> V_60 -> V_12 ) ;
if ( V_2 -> V_26 == 7 )
V_9 = F_35 ( V_2 , V_48 ) ;
else
V_9 = F_21 ( V_2 , V_48 ) ;
F_20 ( & V_2 -> V_4 -> V_12 , L_27 , V_9 ) ;
F_30 ( V_6 , false ) ;
F_4 ( V_14 , V_12 , L_28 ) ;
F_31 ( V_6 ) ;
V_9 = F_36 ( V_6 , NULL , V_67 ) ;
if ( V_9 < 0 )
F_28 ( V_12 , L_29 ) ;
V_9 = F_32 ( V_27 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_33 ( V_27 ) ;
if ( V_9 )
return V_9 ;
F_34 ( V_6 , false ) ;
if ( V_27 -> V_68 -> V_12 . V_69 )
return F_37 ( V_6 ) ;
F_4 ( V_14 , V_12 , L_30 , V_13 ) ;
return V_9 ;
}
static T_3 F_38 ( struct V_59 * V_12 ,
struct V_70 * V_71 ,
const char * V_72 , T_4 V_73 )
{
struct V_58 * V_27 = F_13 ( V_12 ) ;
char V_74 [ V_75 ] ;
const struct V_47 * V_48 ;
T_4 V_76 = V_73 ;
int V_9 ;
if ( V_73 == 0 || V_73 >= V_75 )
return - V_61 ;
if ( V_72 [ V_73 - 1 ] == '\0' || V_72 [ V_73 - 1 ] == '\n' )
V_76 -= 1 ;
strncpy ( V_74 , V_72 , V_76 ) ;
V_74 [ V_76 ] = '\0' ;
V_9 = F_39 ( & V_48 , V_74 , V_12 ) ;
if ( V_9 )
return V_9 ;
F_20 ( V_12 , L_31 , V_74 ) ;
V_9 = F_27 ( V_27 , V_48 ) ;
F_40 ( V_48 ) ;
return V_9 ? : V_73 ;
}
static int F_41 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned char V_77 [ 9 ] ;
bool V_78 ;
T_1 V_79 = V_4 -> V_10 . V_65 ;
int V_9 ;
V_2 = F_42 ( & V_4 -> V_12 , sizeof( struct V_1 ) , V_80 ) ;
if ( ! V_2 )
return - V_81 ;
V_2 -> V_4 = V_4 ;
F_43 ( & V_4 -> V_12 , V_2 ) ;
if ( V_79 > 0 )
return F_44 ( V_2 ) ;
else if ( V_79 != 0 )
return - V_64 ;
V_2 -> V_26 = 5 ;
V_9 = F_2 ( V_4 -> V_6 , V_4 -> V_10 . V_11 ,
V_77 , sizeof( V_77 ) ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 , L_32 ,
V_13 ) ;
return V_9 ;
}
snprintf ( V_2 -> V_7 , sizeof( V_2 -> V_7 ) ,
L_33 , V_77 [ 0 ] , V_77 [ 1 ] ) ;
F_45 ( & V_2 -> V_20 . V_57 ) ;
F_7 ( & V_2 -> V_20 . V_21 ) ;
V_2 -> V_20 . V_32 = F_46 ( & V_77 [ 3 ] ) ;
V_2 -> V_20 . V_34 = F_46 ( & V_77 [ 5 ] ) ;
V_2 -> V_20 . V_36 = F_46 ( & V_77 [ 7 ] ) ;
V_2 -> V_20 . V_22 = V_4 -> V_10 . V_15 + V_16 +
V_2 -> V_20 . V_32 ;
V_78 = V_77 [ 2 ] & ( 1 << 2 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_34 ,
V_2 -> V_7 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_35 ,
V_2 -> V_20 . V_32 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_36 ,
V_2 -> V_20 . V_34 ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_37 ,
V_2 -> V_20 . V_36 ) ;
if ( V_78 ) {
V_9 = F_2 ( V_4 -> V_6 , V_4 -> V_10 . V_82 ,
V_77 , sizeof( V_77 ) ) ;
if ( V_9 ) {
F_3 ( & V_4 -> V_12 , L_38 ) ;
return V_9 ;
}
snprintf ( V_2 -> V_83 , sizeof( V_2 -> V_83 ) ,
L_39 ,
V_77 [ 0 ] , V_77 [ 1 ] ,
V_77 [ 2 ] , V_77 [ 3 ] ) ;
F_4 ( V_14 , & V_4 -> V_12 , L_40 ,
V_2 -> V_83 ) ;
}
return 0 ;
}
int F_47 ( struct V_5 * V_6 )
{
return F_48 ( & V_6 -> V_12 . V_84 , & V_85 ) ;
}
void F_49 ( struct V_5 * V_6 )
{
F_50 ( & V_6 -> V_12 . V_84 , & V_85 ) ;
}
