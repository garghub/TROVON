static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
unsigned int V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned short * V_7 = V_2 -> V_8 -> V_9 ;
return V_7 [ F_3 ( V_3 , V_4 , V_5 ) ] ;
}
static void F_4 ( struct V_1 * V_2 , int V_10 , int V_11 )
{
unsigned long V_12 , V_13 ;
int V_14 ;
int V_15 ;
int V_3 , V_4 ;
unsigned int V_9 ;
F_5 ( 0xFFFFFFFF , V_2 -> V_16 + F_6 ( V_10 ) ) ;
V_12 = F_7 ( V_2 -> V_16 + F_8 ( V_10 ) ) ;
V_13 = V_2 -> V_17 [ V_10 ] ^ V_12 ;
V_2 -> V_17 [ V_10 ] = V_12 ;
F_9 (bit_nr, &change, BITS_PER_LONG) {
V_15 = V_12 & F_10 ( V_14 ) ;
V_15 = V_11 ? ! V_15 : V_15 ;
V_3 = F_11 ( V_14 , V_10 ) ;
V_4 = F_12 ( V_14 ) ;
V_9 = F_1 ( V_2 , V_3 , V_4 ) ;
F_13 ( V_2 -> V_8 , V_9 , V_15 ) ;
}
}
static T_1 F_14 ( int V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
int V_11 = ( V_2 -> V_20 >> V_21 ) & V_22 ;
int V_10 ;
for ( V_10 = 0 ; V_10 <= 1 ; V_10 ++ )
F_4 ( V_2 , V_10 , V_11 ) ;
F_15 ( V_2 -> V_8 ) ;
return V_23 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_24 ) {
error = F_17 ( V_2 -> V_24 ) ;
if ( error )
return error ;
}
F_5 ( V_2 -> V_25 , V_2 -> V_16 + V_26 ) ;
F_5 ( V_2 -> V_27 , V_2 -> V_16 + V_28 ) ;
F_5 ( V_2 -> V_29 , V_2 -> V_16 + V_30 ) ;
F_5 ( V_2 -> V_31 , V_2 -> V_16 + V_32 ) ;
F_5 ( V_2 -> V_31 , V_2 -> V_16 + V_33 ) ;
F_5 ( V_2 -> V_31 , V_2 -> V_16 + V_34 ) ;
F_5 ( V_2 -> V_31 , V_2 -> V_16 + V_35 ) ;
F_5 ( 0xFFFFFFFF , V_2 -> V_16 + V_36 ) ;
F_5 ( 0xFFFFFFFF , V_2 -> V_16 + V_37 ) ;
V_2 -> V_17 [ 0 ] = F_7 ( V_2 -> V_16 + V_38 ) ;
V_2 -> V_17 [ 0 ] = F_7 ( V_2 -> V_16 + V_39 ) ;
F_5 ( V_2 -> V_20 | V_40 , V_2 -> V_16 + V_41 ) ;
return 0 ;
}
static void F_18 ( const struct V_1 * V_2 )
{
T_2 V_42 ;
V_42 = F_7 ( V_2 -> V_16 + V_41 ) ;
V_42 &= ~ V_40 ;
F_5 ( 0 , V_2 -> V_16 + V_41 ) ;
F_5 ( 0 , V_2 -> V_16 + V_28 ) ;
F_5 ( 0 , V_2 -> V_16 + V_30 ) ;
F_5 ( 0xFFFFFFFF , V_2 -> V_16 + V_36 ) ;
F_5 ( 0xFFFFFFFF , V_2 -> V_16 + V_37 ) ;
if ( V_2 -> V_24 )
F_19 ( V_2 -> V_24 ) ;
}
static int F_20 ( struct V_8 * V_43 )
{
struct V_1 * V_2 = F_21 ( V_43 ) ;
return F_16 ( V_2 ) ;
}
static void F_22 ( struct V_8 * V_43 )
{
struct V_1 * V_2 = F_21 ( V_43 ) ;
F_18 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_44 * V_43 = V_2 -> V_8 -> V_43 . V_45 ;
struct V_46 * V_47 = V_43 -> V_48 ;
int error ;
unsigned int V_49 ;
unsigned int V_50 ;
unsigned int V_51 , V_52 , V_53 ;
V_2 -> V_20 = V_54 | V_55 ;
error = F_24 ( V_43 , & V_2 -> V_56 , & V_2 -> V_6 ) ;
if ( error ) {
F_25 ( V_43 , L_1 ) ;
return error ;
}
V_2 -> V_20 |= ( V_2 -> V_56 - 1 ) << V_57 ;
V_2 -> V_20 |= ( V_2 -> V_6 - 1 ) << V_58 ;
V_52 = ( 1 << ( V_2 -> V_6 ) ) - 1 ;
V_51 = V_2 -> V_56 ;
V_2 -> V_27 = V_52 ;
V_53 = 1 ;
while ( -- V_51 && V_53 ++ < 4 )
V_2 -> V_27 |= V_2 -> V_27 << V_59 ;
V_2 -> V_29 = 0 ;
if ( V_51 ) {
V_2 -> V_29 = V_52 ;
while ( -- V_51 )
V_2 -> V_29 |= V_2 -> V_29 << V_59 ;
}
V_2 -> V_31 = 0 ;
for ( V_50 = 0 ; V_50 <= 30 ; V_50 += 2 )
V_2 -> V_31 |= ( V_60 << V_50 ) ;
F_26 ( V_47 , L_2 , & V_49 ) ;
if ( V_49 > V_61 ) {
F_25 ( V_43 , L_3 ,
V_49 ) ;
return - V_62 ;
}
V_2 -> V_20 |= V_49 << V_63 ;
F_26 ( V_47 , L_4 , & V_49 ) ;
if ( V_49 > V_64 ) {
F_25 ( V_43 , L_5 ,
V_49 ) ;
return - V_62 ;
}
V_2 -> V_20 |= V_49 << V_65 ;
if ( F_27 ( V_47 , L_6 ) ) {
V_2 -> V_25 = ( ( 1 << V_2 -> V_56 ) - 1 ) <<
V_66 ;
} else {
V_2 -> V_25 = ( ( 1 << V_2 -> V_6 ) - 1 ) <<
V_67 ;
}
if ( F_27 ( V_47 , L_7 ) )
V_2 -> V_20 |= V_68 ;
F_28 ( V_43 , L_8 ,
V_2 -> V_56 , V_2 -> V_6 ,
V_2 -> V_20 , V_2 -> V_25 , V_2 -> V_31 ) ;
return 0 ;
}
static int F_29 ( struct V_69 * V_70 )
{
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_71 * V_72 ;
int error ;
V_2 = F_30 ( & V_70 -> V_43 , sizeof( * V_2 ) , V_73 ) ;
if ( ! V_2 )
return - V_74 ;
V_8 = F_31 ( & V_70 -> V_43 ) ;
if ( ! V_8 ) {
F_25 ( & V_70 -> V_43 , L_9 ) ;
return - V_74 ;
}
F_32 ( V_75 , V_8 -> V_76 ) ;
if ( F_27 ( V_70 -> V_43 . V_48 , L_10 ) )
F_32 ( V_77 , V_8 -> V_76 ) ;
V_8 -> V_78 = V_70 -> V_78 ;
V_8 -> V_79 = L_11 ;
V_8 -> V_43 . V_45 = & V_70 -> V_43 ;
V_8 -> V_80 = F_20 ;
V_8 -> V_81 = F_22 ;
V_8 -> V_82 . V_83 = V_84 ;
V_8 -> V_82 . V_85 = 0x0001 ;
V_8 -> V_82 . V_86 = 0x0001 ;
V_8 -> V_82 . V_87 = 0x0100 ;
F_33 ( V_8 , V_2 ) ;
V_2 -> V_8 = V_8 ;
error = F_23 ( V_2 ) ;
if ( error )
return error ;
error = F_34 ( NULL , NULL ,
V_2 -> V_56 , V_2 -> V_6 ,
NULL , V_8 ) ;
if ( error ) {
F_25 ( & V_70 -> V_43 , L_12 ) ;
return error ;
}
V_72 = F_35 ( V_70 , V_88 , 0 ) ;
if ( ! V_72 ) {
F_25 ( & V_70 -> V_43 , L_13 ) ;
return - V_89 ;
}
V_2 -> V_16 = F_36 ( & V_70 -> V_43 , V_72 ) ;
if ( F_37 ( V_2 -> V_16 ) )
return F_38 ( V_2 -> V_16 ) ;
V_2 -> V_24 = F_39 ( & V_70 -> V_43 , L_14 ) ;
if ( F_37 ( V_2 -> V_24 ) ) {
error = F_38 ( V_2 -> V_24 ) ;
if ( error != - V_90 ) {
if ( error != - V_91 )
F_25 ( & V_70 -> V_43 , L_15 ) ;
return error ;
}
F_28 ( & V_70 -> V_43 ,
L_16 ) ;
V_2 -> V_24 = NULL ;
} else {
unsigned int V_92 ;
long V_93 ;
error = F_26 ( V_70 -> V_43 . V_48 ,
L_17 , & V_92 ) ;
if ( error < 0 )
V_92 = V_94 ;
V_93 = F_40 ( V_2 -> V_24 , V_92 ) ;
if ( V_93 <= 0 )
return - V_62 ;
error = F_41 ( V_2 -> V_24 , V_93 ) ;
if ( error )
return error ;
error = F_17 ( V_2 -> V_24 ) ;
if ( error )
return error ;
}
F_18 ( V_2 ) ;
V_2 -> V_18 = F_42 ( V_70 , 0 ) ;
if ( V_2 -> V_18 < 0 ) {
F_25 ( & V_70 -> V_43 , L_18 ) ;
return - V_62 ;
}
error = F_43 ( & V_70 -> V_43 , V_2 -> V_18 ,
NULL , F_14 ,
V_95 , V_70 -> V_78 , V_2 ) ;
if ( error ) {
F_25 ( & V_70 -> V_43 , L_19 ) ;
return error ;
}
error = F_44 ( V_8 ) ;
if ( error ) {
F_25 ( & V_70 -> V_43 , L_20 ) ;
return error ;
}
return 0 ;
}
