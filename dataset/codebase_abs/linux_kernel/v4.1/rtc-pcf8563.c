static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 , unsigned char * V_5 )
{
struct V_6 V_7 [] = {
{
. V_8 = V_2 -> V_8 ,
. V_9 = 1 ,
. V_5 = & V_3 ,
} ,
{
. V_8 = V_2 -> V_8 ,
. V_10 = V_11 ,
. V_9 = V_4 ,
. V_5 = V_5
} ,
} ;
if ( ( F_2 ( V_2 -> V_12 , V_7 , 2 ) ) != 2 ) {
F_3 ( & V_2 -> V_13 , L_1 , V_14 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_4 ,
unsigned char * V_5 )
{
int V_16 , V_17 ;
for ( V_16 = 0 ; V_16 < V_4 ; V_16 ++ ) {
unsigned char V_18 [ 2 ] = { V_3 + V_16 , V_5 [ V_16 ] } ;
V_17 = F_5 ( V_2 , V_18 , sizeof( V_18 ) ) ;
if ( V_17 != sizeof( V_18 ) ) {
F_3 ( & V_2 -> V_13 ,
L_2 ,
V_14 , V_17 , V_18 [ 0 ] , V_18 [ 1 ] ) ;
return - V_15 ;
}
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , bool V_19 )
{
unsigned char V_5 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_20 , 1 , & V_5 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_19 )
V_5 |= V_21 ;
else
V_5 &= ~ V_21 ;
V_5 &= ~ ( V_22 | V_23 ) ;
V_17 = F_4 ( V_2 , V_20 , 1 , & V_5 ) ;
if ( V_17 < 0 ) {
F_3 ( & V_2 -> V_13 , L_3 , V_14 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned char * V_24 ,
unsigned char * V_25 )
{
unsigned char V_5 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_20 , 1 , & V_5 ) ;
if ( V_17 )
return V_17 ;
if ( V_24 )
* V_24 = ! ! ( V_5 & V_21 ) ;
if ( V_25 )
* V_25 = ! ! ( V_5 & V_22 ) ;
return 0 ;
}
static T_1 F_8 ( int V_26 , void * V_27 )
{
struct V_28 * V_28 = F_9 ( V_27 ) ;
int V_17 ;
char V_29 ;
V_17 = F_7 ( V_28 -> V_2 , NULL , & V_29 ) ;
if ( V_17 )
return V_30 ;
if ( V_29 ) {
F_10 ( V_28 -> V_31 , 1 , V_32 | V_33 ) ;
F_6 ( V_28 -> V_2 , 1 ) ;
return V_34 ;
}
return V_30 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_28 * V_28 = F_9 ( V_2 ) ;
unsigned char V_5 [ 9 ] ;
int V_17 ;
V_17 = F_1 ( V_2 , V_37 , 9 , V_5 ) ;
if ( V_17 )
return V_17 ;
if ( V_5 [ V_38 ] & V_39 ) {
V_28 -> V_40 = 1 ;
F_12 ( & V_2 -> V_13 ,
L_4 ) ;
}
F_13 ( & V_2 -> V_13 ,
L_5
L_6 ,
V_14 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ,
V_5 [ 4 ] , V_5 [ 5 ] , V_5 [ 6 ] , V_5 [ 7 ] ,
V_5 [ 8 ] ) ;
V_36 -> V_41 = F_14 ( V_5 [ V_38 ] & 0x7F ) ;
V_36 -> V_42 = F_14 ( V_5 [ V_43 ] & 0x7F ) ;
V_36 -> V_44 = F_14 ( V_5 [ V_45 ] & 0x3F ) ;
V_36 -> V_46 = F_14 ( V_5 [ V_47 ] & 0x3F ) ;
V_36 -> V_48 = V_5 [ V_49 ] & 0x07 ;
V_36 -> V_50 = F_14 ( V_5 [ V_51 ] & 0x1F ) - 1 ;
V_36 -> V_52 = F_14 ( V_5 [ V_53 ] ) ;
if ( V_36 -> V_52 < 70 )
V_36 -> V_52 += 100 ;
V_28 -> V_54 = ( V_5 [ V_51 ] & V_55 ) ?
( V_36 -> V_52 >= 100 ) : ( V_36 -> V_52 < 100 ) ;
F_13 ( & V_2 -> V_13 , L_7
L_8 ,
V_14 ,
V_36 -> V_41 , V_36 -> V_42 , V_36 -> V_44 ,
V_36 -> V_46 , V_36 -> V_50 , V_36 -> V_52 , V_36 -> V_48 ) ;
if ( F_15 ( V_36 ) < 0 )
F_3 ( & V_2 -> V_13 , L_9 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_28 * V_28 = F_9 ( V_2 ) ;
unsigned char V_5 [ 9 ] ;
F_13 ( & V_2 -> V_13 , L_10
L_8 ,
V_14 ,
V_36 -> V_41 , V_36 -> V_42 , V_36 -> V_44 ,
V_36 -> V_46 , V_36 -> V_50 , V_36 -> V_52 , V_36 -> V_48 ) ;
V_5 [ V_38 ] = F_17 ( V_36 -> V_41 ) ;
V_5 [ V_43 ] = F_17 ( V_36 -> V_42 ) ;
V_5 [ V_45 ] = F_17 ( V_36 -> V_44 ) ;
V_5 [ V_47 ] = F_17 ( V_36 -> V_46 ) ;
V_5 [ V_51 ] = F_17 ( V_36 -> V_50 + 1 ) ;
V_5 [ V_53 ] = F_17 ( V_36 -> V_52 % 100 ) ;
if ( V_28 -> V_54 ? ( V_36 -> V_52 >= 100 ) : ( V_36 -> V_52 < 100 ) )
V_5 [ V_51 ] |= V_55 ;
V_5 [ V_49 ] = V_36 -> V_48 & 0x07 ;
return F_4 ( V_2 , V_38 ,
9 - V_38 , V_5 + V_38 ) ;
}
static int F_18 ( struct V_56 * V_13 , unsigned int V_57 , unsigned long V_58 )
{
struct V_28 * V_28 = F_9 ( F_19 ( V_13 ) ) ;
struct V_35 V_36 ;
switch ( V_57 ) {
case V_59 :
if ( V_28 -> V_40 )
F_12 ( V_13 , L_4 ) ;
if ( F_20 ( ( void V_60 * ) V_58 , & V_28 -> V_40 ,
sizeof( int ) ) )
return - V_61 ;
return 0 ;
case V_62 :
if ( F_11 ( F_19 ( V_13 ) , & V_36 ) )
F_16 ( F_19 ( V_13 ) , & V_36 ) ;
V_28 -> V_40 = 0 ;
return 0 ;
default:
return - V_63 ;
}
}
static int F_21 ( struct V_56 * V_13 , struct V_35 * V_36 )
{
return F_11 ( F_19 ( V_13 ) , V_36 ) ;
}
static int F_22 ( struct V_56 * V_13 , struct V_35 * V_36 )
{
return F_16 ( F_19 ( V_13 ) , V_36 ) ;
}
static int F_23 ( struct V_56 * V_13 , struct V_64 * V_36 )
{
struct V_1 * V_2 = F_19 ( V_13 ) ;
unsigned char V_5 [ 4 ] ;
int V_17 ;
V_17 = F_1 ( V_2 , V_65 , 4 , V_5 ) ;
if ( V_17 )
return V_17 ;
F_13 ( & V_2 -> V_13 ,
L_11 ,
V_14 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ) ;
V_36 -> time . V_42 = F_14 ( V_5 [ 0 ] & 0x7F ) ;
V_36 -> time . V_44 = F_14 ( V_5 [ 1 ] & 0x3F ) ;
V_36 -> time . V_46 = F_14 ( V_5 [ 2 ] & 0x3F ) ;
V_36 -> time . V_48 = F_14 ( V_5 [ 3 ] & 0x7 ) ;
V_36 -> time . V_50 = - 1 ;
V_36 -> time . V_52 = - 1 ;
V_36 -> time . V_66 = - 1 ;
V_36 -> time . V_67 = - 1 ;
V_17 = F_7 ( V_2 , & V_36 -> V_68 , & V_36 -> V_29 ) ;
if ( V_17 < 0 )
return V_17 ;
F_13 ( & V_2 -> V_13 , L_12
L_13 , V_14 , V_36 -> time . V_42 ,
V_36 -> time . V_44 , V_36 -> time . V_46 , V_36 -> time . V_48 ,
V_36 -> V_68 , V_36 -> V_29 ) ;
return 0 ;
}
static int F_24 ( struct V_56 * V_13 , struct V_64 * V_36 )
{
struct V_1 * V_2 = F_19 ( V_13 ) ;
unsigned char V_5 [ 4 ] ;
int V_17 ;
unsigned long V_69 ;
if ( V_36 -> time . V_41 ) {
F_25 ( & V_36 -> time , & V_69 ) ;
V_69 += 60 - V_36 -> time . V_41 ;
F_26 ( V_69 , & V_36 -> time ) ;
}
F_13 ( V_13 , L_14
L_15 , V_14 ,
V_36 -> time . V_42 , V_36 -> time . V_44 , V_36 -> time . V_48 ,
V_36 -> time . V_46 , V_36 -> V_68 , V_36 -> V_29 ) ;
V_5 [ 0 ] = F_17 ( V_36 -> time . V_42 ) ;
V_5 [ 1 ] = F_17 ( V_36 -> time . V_44 ) ;
V_5 [ 2 ] = F_17 ( V_36 -> time . V_46 ) ;
V_5 [ 3 ] = V_36 -> time . V_48 & 0x07 ;
V_17 = F_4 ( V_2 , V_65 , 4 , V_5 ) ;
if ( V_17 )
return V_17 ;
return F_6 ( V_2 , 1 ) ;
}
static int F_27 ( struct V_56 * V_13 , unsigned int V_68 )
{
F_13 ( V_13 , L_16 , V_14 , V_68 ) ;
return F_6 ( F_19 ( V_13 ) , ! ! V_68 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
const struct V_70 * V_71 )
{
struct V_28 * V_28 ;
int V_17 ;
unsigned char V_5 ;
unsigned char V_72 ;
F_13 ( & V_2 -> V_13 , L_17 , V_14 ) ;
if ( ! F_29 ( V_2 -> V_12 , V_73 ) )
return - V_74 ;
V_28 = F_30 ( & V_2 -> V_13 , sizeof( struct V_28 ) ,
V_75 ) ;
if ( ! V_28 )
return - V_76 ;
F_12 ( & V_2 -> V_13 , L_18 V_77 L_19 ) ;
F_31 ( V_2 , V_28 ) ;
V_28 -> V_2 = V_2 ;
F_32 ( & V_2 -> V_13 , 1 ) ;
V_5 = V_78 ;
V_17 = F_4 ( V_2 , V_79 , 1 , & V_5 ) ;
if ( V_17 < 0 ) {
F_3 ( & V_2 -> V_13 , L_3 , V_14 ) ;
return V_17 ;
}
V_17 = F_7 ( V_2 , NULL , & V_72 ) ;
if ( V_17 < 0 ) {
F_3 ( & V_2 -> V_13 , L_1 , V_14 ) ;
return V_17 ;
}
if ( V_72 )
F_6 ( V_2 , 0 ) ;
V_28 -> V_31 = F_33 ( & V_2 -> V_13 ,
V_80 . V_81 . V_82 ,
& V_83 , V_84 ) ;
if ( F_34 ( V_28 -> V_31 ) )
return F_35 ( V_28 -> V_31 ) ;
if ( V_2 -> V_26 > 0 ) {
V_17 = F_36 ( & V_2 -> V_13 , V_2 -> V_26 ,
NULL , F_8 ,
V_85 | V_86 | V_87 ,
V_28 -> V_31 -> V_82 , V_2 ) ;
if ( V_17 ) {
F_3 ( & V_2 -> V_13 , L_20 ,
V_2 -> V_26 ) ;
return V_17 ;
}
}
V_28 -> V_31 -> V_88 = 1 ;
return 0 ;
}
