static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 [ 4 ] , V_7 [ 4 ] ;
int V_8 = V_9 , V_10 ;
do {
V_10 = F_3 ( V_5 , V_11 ,
4 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_3 ( V_5 , V_11 ,
4 , V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( memcmp ( V_6 , V_7 , sizeof( V_6 ) ) == 0 ) {
V_4 -> V_12 = V_6 [ 0 ] & V_13 ;
V_4 -> V_14 = ( V_6 [ 0 ] & V_15 )
>> V_16 ;
V_4 -> V_17 = V_6 [ 1 ] & V_18 ;
V_4 -> V_19 = ( ( V_6 [ 1 ] >> V_20 )
& 0x7 ) - 1 ;
V_4 -> V_21 = ( ( V_6 [ 2 ] & V_22 )
>> V_23 ) - 1 ;
V_4 -> V_24 = ( V_6 [ 2 ] & V_25 ) ;
V_4 -> V_26 = ( ( V_6 [ 3 ] & V_27 )
>> V_28 ) * 100 ;
V_4 -> V_26 += V_6 [ 3 ] & V_29 ;
V_4 -> V_30 = F_4 ( V_4 -> V_24 , V_4 -> V_21 ,
V_4 -> V_26 ) ;
V_4 -> V_26 -= 1900 ;
F_5 ( V_2 , L_1 ,
V_8 ,
V_6 [ 0 ] , V_6 [ 1 ] , V_6 [ 2 ] , V_6 [ 3 ] ) ;
return 0 ;
}
} while ( V_8 -- );
F_6 ( V_2 , L_2 ) ;
return - V_31 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 time [ 4 ] ;
T_1 V_32 ;
int V_10 , V_8 = V_33 ;
time [ 0 ] = V_4 -> V_12 ;
time [ 0 ] |= V_4 -> V_14 << V_16 ;
time [ 1 ] = V_4 -> V_17 ;
time [ 1 ] |= ( V_4 -> V_19 + 1 ) << V_20 ;
time [ 2 ] = V_4 -> V_24 ;
time [ 2 ] |= ( V_4 -> V_21 + 1 ) << V_23 ;
time [ 3 ] = ( ( V_4 -> V_26 + 1900 ) / 100 ) << V_28 ;
time [ 3 ] |= ( V_4 -> V_26 + 1900 ) % 100 ;
F_5 ( V_2 , L_3 ,
time [ 0 ] , time [ 1 ] , time [ 2 ] , time [ 3 ] ) ;
V_10 = F_8 ( V_5 , V_34 , V_35 ) ;
if ( V_10 < 0 )
return V_10 ;
do {
V_32 = F_9 ( V_5 , V_34 ) ;
F_10 ( F_11 ( 1 ) ) ;
} while ( -- V_8 && ! ( V_32 & V_36 ) );
if ( ! V_8 ) {
F_6 ( V_2 , L_4 ) ;
return - V_31 ;
}
V_10 = F_12 ( V_5 , V_11 , 4 , time ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_13 ( V_5 , V_34 ,
V_35 ) ;
return V_10 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_3 * V_4 = & V_38 -> time ;
T_1 time [ 4 ] ;
int V_10 ;
V_10 = F_3 ( V_5 , V_39 , 4 , time ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 -> V_12 = time [ 0 ] & V_40 ;
if ( V_4 -> V_12 == V_40 )
V_4 -> V_12 = - 1 ;
V_4 -> V_14 = time [ 0 ] & V_41 ;
if ( V_4 -> V_14 == V_41 )
V_4 -> V_14 = - 1 ;
else
V_4 -> V_14 >>= V_42 ;
V_4 -> V_17 = time [ 1 ] & V_43 ;
if ( V_4 -> V_17 == V_43 )
V_4 -> V_17 = - 1 ;
V_4 -> V_19 = ( ( time [ 1 ] >> V_44 ) & 0x7 ) - 1 ;
if ( V_4 -> V_19 > 7 )
V_4 -> V_19 = - 1 ;
V_4 -> V_21 = time [ 2 ] & V_45 ;
if ( V_4 -> V_21 == V_45 )
V_4 -> V_21 = - 1 ;
else
V_4 -> V_21 = ( V_4 -> V_21 >> V_46 ) - 1 ;
V_4 -> V_24 = ( time [ 2 ] & V_47 ) ;
if ( V_4 -> V_24 == V_47 )
V_4 -> V_24 = - 1 ;
V_4 -> V_26 = - 1 ;
V_38 -> V_48 = ! ( time [ 3 ] & V_49 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_5 )
{
int V_8 = V_50 ;
T_1 V_32 ;
int V_10 ;
V_10 = F_8 ( V_5 , V_34 ,
V_51 ) ;
if ( V_10 < 0 )
return V_10 ;
do {
V_32 = F_9 ( V_5 , V_34 ) ;
F_10 ( F_11 ( 1 ) ) ;
} while ( V_8 -- && ! ( V_32 & V_49 ) );
if ( ! ( V_32 & V_49 ) )
return - V_52 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_5 )
{
int V_10 ;
int V_8 = V_50 ;
T_1 V_32 ;
V_10 = F_13 ( V_5 , V_34 ,
V_51 ) ;
if ( V_10 < 0 )
return V_10 ;
do {
V_32 = F_9 ( V_5 , V_34 ) ;
F_10 ( F_11 ( 1 ) ) ;
} while ( V_8 -- && V_32 & V_49 );
if ( V_32 & V_49 )
return - V_52 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_48 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
if ( V_48 )
return F_16 ( V_5 ) ;
else
return F_15 ( V_5 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_3 * V_4 = & V_38 -> time ;
T_1 time [ 3 ] ;
int V_10 ;
memset ( time , 0 , sizeof( time ) ) ;
if ( V_4 -> V_12 != - 1 )
time [ 0 ] |= V_4 -> V_12 ;
else
time [ 0 ] |= V_40 ;
if ( V_4 -> V_14 != - 1 )
time [ 0 ] |= V_4 -> V_14 << V_42 ;
else
time [ 0 ] |= V_41 ;
if ( V_4 -> V_17 != - 1 )
time [ 1 ] |= V_4 -> V_17 ;
else
time [ 1 ] |= V_43 ;
if ( V_4 -> V_19 != - 1 )
time [ 1 ] |= ( V_4 -> V_19 + 1 ) << V_44 ;
else
time [ 1 ] |= V_53 ;
if ( V_4 -> V_24 != - 1 )
time [ 2 ] |= V_4 -> V_24 ;
else
time [ 2 ] |= V_47 ;
if ( V_4 -> V_21 != - 1 )
time [ 2 ] |= ( V_4 -> V_21 + 1 ) << V_46 ;
else
time [ 2 ] |= V_45 ;
V_10 = F_15 ( V_5 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_12 ( V_5 , V_39 ,
3 , time ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_38 -> V_48 )
V_10 = F_16 ( V_5 ) ;
return V_10 ;
}
static T_2 F_19 ( int V_54 , void * V_55 )
{
struct V_5 * V_5 = V_55 ;
struct V_56 * V_57 = V_5 -> V_57 . V_57 ;
int V_10 ;
F_20 ( V_57 , 1 , V_58 | V_59 ) ;
V_10 = F_8 ( V_5 , V_34 ,
V_51 ) ;
if ( V_10 != 0 ) {
F_6 ( & ( V_5 -> V_57 . V_60 -> V_2 ) ,
L_5 , V_10 ) ;
}
return V_61 ;
}
static T_2 F_21 ( int V_54 , void * V_55 )
{
struct V_5 * V_5 = V_55 ;
struct V_56 * V_57 = V_5 -> V_57 . V_57 ;
F_20 ( V_57 , 1 , V_58 | V_62 ) ;
return V_61 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_63 * V_60 = F_23 ( V_2 ) ;
struct V_5 * V_5 = F_2 ( & V_60 -> V_2 ) ;
int V_10 = 0 ;
T_1 V_64 ;
V_64 = F_9 ( V_5 , V_34 ) ;
if ( F_24 ( & V_5 -> V_57 . V_60 -> V_2 ) &&
V_64 & V_49 ) {
V_10 = F_15 ( V_5 ) ;
if ( V_10 != 0 )
F_6 ( & V_60 -> V_2 , L_6 ,
V_10 ) ;
}
return V_10 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_63 * V_60 = F_23 ( V_2 ) ;
struct V_5 * V_5 = F_2 ( & V_60 -> V_2 ) ;
int V_10 ;
if ( V_5 -> V_57 . V_65 ) {
V_10 = F_16 ( V_5 ) ;
if ( V_10 != 0 )
F_6 ( & V_60 -> V_2 ,
L_7 , V_10 ) ;
}
return 0 ;
}
static int F_26 ( struct V_63 * V_60 )
{
struct V_5 * V_5 = F_27 ( V_60 ) ;
struct V_66 * V_67 = & V_5 -> V_57 ;
int V_10 = 0 ;
T_1 V_68 , V_69 ;
V_68 = F_9 ( V_5 , V_34 ) ;
if ( V_68 & V_70 ) {
F_6 ( & V_60 -> V_2 , L_8 ) ;
return - V_71 ;
}
if ( V_68 & V_72 ) {
F_6 ( & V_60 -> V_2 , L_9 ) ;
return - V_71 ;
}
V_69 = F_9 ( V_5 , V_73 ) ;
if ( ! ( V_69 & V_74 ) ) {
F_28 ( V_5 -> V_2 , L_10 ) ;
F_29 ( V_5 ) ;
V_10 = F_8 ( V_5 , V_73 ,
V_74 ) ;
if ( V_10 < 0 ) {
F_6 ( & V_60 -> V_2 , L_11 , V_10 ) ;
return V_10 ;
}
F_30 ( V_5 ) ;
}
if ( V_68 & V_36 ) {
int V_8 ;
V_10 = F_13 ( V_5 , V_34 ,
V_35 ) ;
if ( V_10 < 0 ) {
F_6 ( & V_60 -> V_2 , L_12 , V_10 ) ;
return V_10 ;
}
V_8 = V_33 ;
do {
V_68 = F_9 ( V_5 ,
V_34 ) ;
} while ( V_68 & V_36 && -- V_8 );
if ( V_8 == 0 ) {
F_6 ( & V_60 -> V_2 , L_13 ) ;
return - V_75 ;
}
}
F_31 ( & V_60 -> V_2 , 1 ) ;
V_67 -> V_57 = F_32 ( L_14 , & V_60 -> V_2 ,
& V_76 , V_77 ) ;
if ( F_33 ( V_67 -> V_57 ) ) {
V_10 = F_34 ( V_67 -> V_57 ) ;
F_6 ( & V_60 -> V_2 , L_15 , V_10 ) ;
return V_10 ;
}
F_35 ( V_5 , V_78 ,
F_21 , 0 ,
L_16 , V_5 ) ;
F_36 ( V_5 , V_78 ) ;
F_35 ( V_5 , V_79 ,
F_19 , 0 ,
L_17 , V_5 ) ;
return 0 ;
}
static int T_3 F_37 ( struct V_63 * V_60 )
{
struct V_5 * V_5 = F_27 ( V_60 ) ;
struct V_66 * V_67 = & V_5 -> V_57 ;
F_38 ( V_5 , V_78 , V_5 ) ;
F_38 ( V_5 , V_79 , V_5 ) ;
F_39 ( V_67 -> V_57 ) ;
return 0 ;
}
