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
unsigned char V_5 [ 2 ] ;
int V_17 ;
V_17 = F_1 ( V_2 , V_20 , 1 , V_5 + 1 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_19 )
V_5 [ 1 ] |= V_21 ;
else
V_5 [ 1 ] &= ~ V_21 ;
V_5 [ 1 ] &= ~ V_22 ;
V_5 [ 0 ] = V_20 ;
V_17 = F_4 ( V_2 , V_20 , 1 , V_5 + 1 ) ;
if ( V_17 < 0 ) {
F_3 ( & V_2 -> V_13 , L_3 , V_14 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned char * V_23 ,
unsigned char * V_24 )
{
unsigned char V_5 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_20 , 1 , & V_5 ) ;
if ( V_17 )
return V_17 ;
if ( V_23 )
* V_23 = ! ! ( V_5 & V_21 ) ;
if ( V_24 )
* V_24 = ! ! ( V_5 & V_22 ) ;
return 0 ;
}
static T_1 F_8 ( int V_25 , void * V_26 )
{
struct V_27 * V_27 = F_9 ( V_26 ) ;
int V_17 ;
char V_28 ;
V_17 = F_7 ( V_27 -> V_2 , NULL , & V_28 ) ;
if ( V_17 )
return V_29 ;
if ( V_28 ) {
F_10 ( V_27 -> V_30 , 1 , V_31 | V_32 ) ;
F_6 ( V_27 -> V_2 , 1 ) ;
return V_33 ;
}
return V_29 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_27 * V_27 = F_9 ( V_2 ) ;
unsigned char V_5 [ 9 ] ;
int V_17 ;
V_17 = F_1 ( V_2 , V_36 , 9 , V_5 ) ;
if ( V_17 )
return V_17 ;
if ( V_5 [ V_37 ] & V_38 ) {
V_27 -> V_39 = 1 ;
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
V_35 -> V_40 = F_14 ( V_5 [ V_37 ] & 0x7F ) ;
V_35 -> V_41 = F_14 ( V_5 [ V_42 ] & 0x7F ) ;
V_35 -> V_43 = F_14 ( V_5 [ V_44 ] & 0x3F ) ;
V_35 -> V_45 = F_14 ( V_5 [ V_46 ] & 0x3F ) ;
V_35 -> V_47 = V_5 [ V_48 ] & 0x07 ;
V_35 -> V_49 = F_14 ( V_5 [ V_50 ] & 0x1F ) - 1 ;
V_35 -> V_51 = F_14 ( V_5 [ V_52 ] ) ;
if ( V_35 -> V_51 < 70 )
V_35 -> V_51 += 100 ;
V_27 -> V_53 = ( V_5 [ V_50 ] & V_54 ) ?
( V_35 -> V_51 >= 100 ) : ( V_35 -> V_51 < 100 ) ;
F_13 ( & V_2 -> V_13 , L_7
L_8 ,
V_14 ,
V_35 -> V_40 , V_35 -> V_41 , V_35 -> V_43 ,
V_35 -> V_45 , V_35 -> V_49 , V_35 -> V_51 , V_35 -> V_47 ) ;
if ( F_15 ( V_35 ) < 0 )
F_3 ( & V_2 -> V_13 , L_9 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_27 * V_27 = F_9 ( V_2 ) ;
int V_17 ;
unsigned char V_5 [ 9 ] ;
F_13 ( & V_2 -> V_13 , L_10
L_8 ,
V_14 ,
V_35 -> V_40 , V_35 -> V_41 , V_35 -> V_43 ,
V_35 -> V_45 , V_35 -> V_49 , V_35 -> V_51 , V_35 -> V_47 ) ;
V_5 [ V_37 ] = F_17 ( V_35 -> V_40 ) ;
V_5 [ V_42 ] = F_17 ( V_35 -> V_41 ) ;
V_5 [ V_44 ] = F_17 ( V_35 -> V_43 ) ;
V_5 [ V_46 ] = F_17 ( V_35 -> V_45 ) ;
V_5 [ V_50 ] = F_17 ( V_35 -> V_49 + 1 ) ;
V_5 [ V_52 ] = F_17 ( V_35 -> V_51 % 100 ) ;
if ( V_27 -> V_53 ? ( V_35 -> V_51 >= 100 ) : ( V_35 -> V_51 < 100 ) )
V_5 [ V_50 ] |= V_54 ;
V_5 [ V_48 ] = V_35 -> V_47 & 0x07 ;
V_17 = F_4 ( V_2 , V_37 ,
9 - V_37 , V_5 + V_37 ) ;
if ( V_17 )
return V_17 ;
return 0 ;
}
static int F_18 ( struct V_55 * V_13 , unsigned int V_56 , unsigned long V_57 )
{
struct V_27 * V_27 = F_9 ( F_19 ( V_13 ) ) ;
struct V_34 V_35 ;
switch ( V_56 ) {
case V_58 :
if ( V_27 -> V_39 )
F_12 ( V_13 , L_4 ) ;
if ( F_20 ( ( void V_59 * ) V_57 , & V_27 -> V_39 ,
sizeof( int ) ) )
return - V_60 ;
return 0 ;
case V_61 :
if ( F_11 ( F_19 ( V_13 ) , & V_35 ) )
F_16 ( F_19 ( V_13 ) , & V_35 ) ;
V_27 -> V_39 = 0 ;
return 0 ;
default:
return - V_62 ;
}
}
static int F_21 ( struct V_55 * V_13 , struct V_34 * V_35 )
{
return F_11 ( F_19 ( V_13 ) , V_35 ) ;
}
static int F_22 ( struct V_55 * V_13 , struct V_34 * V_35 )
{
return F_16 ( F_19 ( V_13 ) , V_35 ) ;
}
static int F_23 ( struct V_55 * V_13 , struct V_63 * V_35 )
{
struct V_1 * V_2 = F_19 ( V_13 ) ;
unsigned char V_5 [ 4 ] ;
int V_17 ;
V_17 = F_1 ( V_2 , V_64 , 4 , V_5 ) ;
if ( V_17 )
return V_17 ;
F_13 ( & V_2 -> V_13 ,
L_11 ,
V_14 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ) ;
V_35 -> time . V_41 = F_14 ( V_5 [ 0 ] & 0x7F ) ;
V_35 -> time . V_43 = F_14 ( V_5 [ 1 ] & 0x7F ) ;
V_35 -> time . V_45 = F_14 ( V_5 [ 2 ] & 0x1F ) ;
V_35 -> time . V_47 = F_14 ( V_5 [ 3 ] & 0x7 ) ;
V_35 -> time . V_49 = - 1 ;
V_35 -> time . V_51 = - 1 ;
V_35 -> time . V_65 = - 1 ;
V_35 -> time . V_66 = - 1 ;
V_17 = F_7 ( V_2 , & V_35 -> V_67 , & V_35 -> V_28 ) ;
if ( V_17 < 0 )
return V_17 ;
F_13 ( & V_2 -> V_13 , L_12
L_13 , V_14 , V_35 -> time . V_41 ,
V_35 -> time . V_43 , V_35 -> time . V_45 , V_35 -> time . V_47 ,
V_35 -> V_67 , V_35 -> V_28 ) ;
return 0 ;
}
static int F_24 ( struct V_55 * V_13 , struct V_63 * V_35 )
{
struct V_1 * V_2 = F_19 ( V_13 ) ;
unsigned char V_5 [ 4 ] ;
int V_17 ;
F_13 ( V_13 , L_14
L_15 , V_14 ,
V_35 -> time . V_41 , V_35 -> time . V_43 , V_35 -> time . V_47 ,
V_35 -> time . V_45 , V_35 -> V_67 , V_35 -> V_28 ) ;
V_5 [ 0 ] = F_17 ( V_35 -> time . V_41 ) ;
V_5 [ 1 ] = F_17 ( V_35 -> time . V_43 ) ;
V_5 [ 2 ] = F_17 ( V_35 -> time . V_45 ) ;
V_5 [ 3 ] = V_35 -> time . V_47 & 0x07 ;
V_17 = F_4 ( V_2 , V_64 , 4 , V_5 ) ;
if ( V_17 )
return V_17 ;
return F_6 ( V_2 , 1 ) ;
}
static int F_25 ( struct V_55 * V_13 , unsigned int V_67 )
{
return F_6 ( F_19 ( V_13 ) , ! ! V_67 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_68 * V_69 )
{
struct V_27 * V_27 ;
int V_17 ;
F_13 ( & V_2 -> V_13 , L_16 , V_14 ) ;
if ( ! F_27 ( V_2 -> V_12 , V_70 ) )
return - V_71 ;
V_27 = F_28 ( & V_2 -> V_13 , sizeof( struct V_27 ) ,
V_72 ) ;
if ( ! V_27 )
return - V_73 ;
F_12 ( & V_2 -> V_13 , L_17 V_74 L_18 ) ;
F_29 ( V_2 , V_27 ) ;
V_27 -> V_2 = V_2 ;
F_30 ( & V_2 -> V_13 , 1 ) ;
V_27 -> V_30 = F_31 ( & V_2 -> V_13 ,
V_75 . V_76 . V_77 ,
& V_78 , V_79 ) ;
if ( F_32 ( V_27 -> V_30 ) )
return F_33 ( V_27 -> V_30 ) ;
if ( V_2 -> V_25 > 0 ) {
V_17 = F_34 ( & V_2 -> V_13 , V_2 -> V_25 ,
NULL , F_8 ,
V_80 | V_81 | V_82 ,
V_27 -> V_30 -> V_77 , V_2 ) ;
if ( V_17 ) {
F_3 ( & V_2 -> V_13 , L_19 ,
V_2 -> V_25 ) ;
return V_17 ;
}
}
return 0 ;
}
