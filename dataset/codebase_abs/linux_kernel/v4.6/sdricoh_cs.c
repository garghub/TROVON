static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 = F_2 ( V_2 -> V_5 + V_3 ) ;
F_3 ( V_2 -> V_6 , L_1 , V_3 , V_4 ) ;
return V_4 ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_5 ( V_4 , V_2 -> V_5 + V_3 ) ;
F_3 ( V_2 -> V_6 , L_2 , V_3 , V_4 ) ;
}
static inline unsigned int F_6 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 = F_7 ( V_2 -> V_5 + V_3 ) ;
F_3 ( V_2 -> V_6 , L_3 , V_3 , V_4 ) ;
return V_4 ;
}
static inline void F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned short V_4 )
{
F_9 ( V_4 , V_2 -> V_5 + V_3 ) ;
F_3 ( V_2 -> V_6 , L_4 , V_3 , V_4 ) ;
}
static inline unsigned int F_10 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 = F_11 ( V_2 -> V_5 + V_3 ) ;
F_3 ( V_2 -> V_6 , L_3 , V_3 , V_4 ) ;
return V_4 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_7 ,
unsigned int V_8 ) {
unsigned int V_9 ;
unsigned int V_10 = 0 ;
struct V_11 * V_6 = V_2 -> V_6 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
V_10 = F_1 ( V_2 , V_12 ) ;
F_4 ( V_2 , V_13 , V_10 ) ;
if ( V_10 & V_7 )
break;
}
if ( V_9 == V_8 ) {
F_13 ( V_6 , L_5 , V_7 ) ;
return - V_14 ;
}
if ( V_10 & 0x7F0000 ) {
F_13 ( V_6 , L_6 , V_7 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned char V_16 ,
unsigned int V_17 )
{
unsigned int V_10 ;
int V_18 = 0 ;
unsigned int V_9 = 0 ;
F_4 ( V_2 , V_12 , 0x18 ) ;
F_4 ( V_2 , V_19 , V_17 ) ;
F_4 ( V_2 , V_20 , ( 0x10000 << 8 ) | V_16 ) ;
if ( V_16 ) {
for ( V_9 = 0 ; V_9 < V_21 ; V_9 ++ ) {
V_10 = F_1 ( V_2 , V_12 ) ;
F_4 ( V_2 , V_13 , V_10 ) ;
if ( V_10 & V_22 )
break;
}
if ( V_9 == V_21 || V_10 & V_23 )
V_18 = - V_14 ;
}
return V_18 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_6 , L_7 ) ;
F_4 ( V_2 , V_24 , 0x10001 ) ;
F_4 ( V_2 , V_25 , 0x10000 ) ;
if ( F_1 ( V_2 , V_25 ) != 0x10000 )
return - V_26 ;
F_4 ( V_2 , V_25 , 0x10007 ) ;
F_4 ( V_2 , V_27 , 0x2000000 ) ;
F_4 ( V_2 , V_28 , 0xe0 ) ;
F_4 ( V_2 , V_12 , 0x18 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_29 ,
T_1 * V_30 , int V_31 )
{
int V_32 ;
T_2 V_33 = 0 ;
if ( V_29 ) {
if ( F_12 ( V_2 , V_34 ,
V_35 ) )
return - V_14 ;
F_4 ( V_2 , V_12 , 0x18 ) ;
while ( V_31 ) {
V_33 = F_1 ( V_2 , V_36 ) ;
V_32 = F_18 ( V_31 , 4 ) ;
V_31 -= V_32 ;
while ( V_32 ) {
* V_30 = V_33 & 0xFF ;
V_30 ++ ;
V_33 >>= 8 ;
V_32 -- ;
}
}
} else {
if ( F_12 ( V_2 , V_37 ,
V_35 ) )
return - V_14 ;
F_4 ( V_2 , V_12 , 0x18 ) ;
while ( V_31 ) {
V_32 = F_18 ( V_31 , 4 ) ;
V_31 -= V_32 ;
while ( V_32 ) {
V_33 >>= 8 ;
V_33 |= ( T_2 ) * V_30 << 24 ;
V_30 ++ ;
V_32 -- ;
}
F_4 ( V_2 , V_36 , V_33 ) ;
}
}
if ( V_31 )
return - V_26 ;
return 0 ;
}
static void F_19 ( struct V_38 * V_39 , struct V_40 * V_41 )
{
struct V_1 * V_2 = F_20 ( V_39 ) ;
struct V_42 * V_43 = V_41 -> V_43 ;
struct V_44 * V_33 = V_43 -> V_33 ;
struct V_11 * V_6 = V_2 -> V_6 ;
unsigned char V_16 = V_43 -> V_16 ;
int V_45 ;
F_16 ( V_6 , L_8 ) ;
F_16 ( V_6 , L_9 , V_16 ) ;
F_4 ( V_2 , V_12 , 0x18 ) ;
if ( V_2 -> V_46 ) {
V_16 |= 64 ;
V_2 -> V_46 = 0 ;
} else if ( V_16 == 55 )
V_2 -> V_46 = 1 ;
if ( V_33 ) {
F_8 ( V_2 , V_47 , V_33 -> V_48 ) ;
F_4 ( V_2 , V_49 , 0 ) ;
}
V_43 -> error = F_14 ( V_2 , V_16 , V_43 -> V_17 ) ;
if ( V_43 -> V_50 & V_51 ) {
if ( V_43 -> V_50 & V_52 ) {
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ ) {
V_43 -> V_53 [ V_45 ] =
F_1 ( V_2 ,
V_54 + ( 3 - V_45 ) * 4 ) << 8 ;
if ( V_45 != 3 )
V_43 -> V_53 [ V_45 ] |=
F_10 ( V_2 , V_54 +
( 3 - V_45 ) * 4 - 1 ) ;
}
} else
V_43 -> V_53 [ 0 ] = F_1 ( V_2 , V_54 ) ;
}
if ( V_33 && V_43 -> error == 0 ) {
F_16 ( V_6 , L_10
L_11 , V_33 -> V_48 , V_33 -> V_55 ,
V_33 -> V_56 , V_33 -> V_57 -> V_58 ) ;
F_4 ( V_2 , V_12 , 0x837f031e ) ;
for ( V_45 = 0 ; V_45 < V_33 -> V_55 ; V_45 ++ ) {
T_3 V_31 = V_33 -> V_48 ;
T_1 * V_30 ;
struct V_59 * V_59 ;
int V_18 ;
V_59 = F_21 ( V_33 -> V_57 ) ;
V_30 = F_22 ( V_59 ) + V_33 -> V_57 -> V_60 + ( V_31 * V_45 ) ;
V_18 =
F_17 ( V_2 ,
V_33 -> V_50 & V_61 , V_30 , V_31 ) ;
F_23 ( V_59 ) ;
F_24 ( V_59 ) ;
if ( V_18 ) {
F_13 ( V_6 , L_12
L_13 , V_43 -> V_16 ) ;
V_43 -> error = V_18 ;
break;
} else
V_33 -> V_62 += V_31 ;
}
F_4 ( V_2 , V_49 , 1 ) ;
if ( F_12 ( V_2 , V_63 ,
V_35 ) ) {
F_13 ( V_6 , L_14 ) ;
V_43 -> error = - V_15 ;
}
}
F_25 ( V_39 , V_41 ) ;
F_16 ( V_6 , L_8 ) ;
}
static void F_26 ( struct V_38 * V_39 , struct V_64 * V_65 )
{
struct V_1 * V_2 = F_20 ( V_39 ) ;
F_16 ( V_2 -> V_6 , L_15 ) ;
if ( V_65 -> V_66 == V_67 ) {
F_4 ( V_2 , V_28 , 0xc0e0 ) ;
if ( V_65 -> V_68 == V_69 ) {
F_4 ( V_2 , V_27 , 0x2000300 ) ;
F_4 ( V_2 , V_28 , 0x40e0 ) ;
} else {
F_4 ( V_2 , V_27 , 0x2000340 ) ;
}
} else if ( V_65 -> V_66 == V_70 ) {
F_4 ( V_2 , V_27 , 0x2000320 ) ;
F_4 ( V_2 , V_28 , 0xe0 ) ;
}
}
static int F_27 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_20 ( V_39 ) ;
unsigned int V_10 ;
V_10 = F_1 ( V_2 , V_12 ) ;
F_4 ( V_2 , V_13 , V_10 ) ;
if ( V_71 )
return ! ( V_10 & V_72 ) ;
return ( V_10 & V_72 ) ;
}
static int F_28 ( struct V_73 * V_73 ,
struct V_74 * V_75 )
{
int V_18 ;
void T_4 * V_5 ;
struct V_38 * V_39 ;
struct V_1 * V_2 ;
struct V_11 * V_6 = & V_75 -> V_6 ;
if ( F_29 ( V_73 , V_76 ) !=
V_77 ) {
F_16 ( V_6 , L_16 ) ;
return - V_78 ;
}
V_5 =
F_30 ( V_73 , V_76 , V_77 ) ;
if ( ! V_5 ) {
F_13 ( V_6 , L_17 ) ;
return - V_78 ;
}
if ( F_2 ( V_5 + V_79 ) != 0x4000 ) {
F_16 ( V_6 , L_18 ) ;
V_18 = - V_78 ;
goto V_80;
}
V_39 = V_75 -> V_81 =
F_31 ( sizeof( struct V_1 ) , & V_75 -> V_6 ) ;
if ( ! V_39 ) {
F_13 ( V_6 , L_19 ) ;
V_18 = - V_82 ;
goto V_80;
}
V_2 = F_20 ( V_39 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_73 = V_73 ;
V_39 -> V_83 = & V_84 ;
V_39 -> V_85 = 450000 ;
V_39 -> V_86 = 24000000 ;
V_39 -> V_87 = V_88 | V_89 ;
V_39 -> V_90 |= V_91 ;
V_39 -> V_92 = 1024 * 512 ;
V_39 -> V_93 = 512 ;
if ( F_15 ( V_2 ) ) {
F_16 ( V_6 , L_20 ) ;
V_18 = - V_26 ;
goto V_94;
}
V_18 = F_32 ( V_39 ) ;
if ( ! V_18 ) {
F_16 ( V_6 , L_21 ) ;
return 0 ;
}
V_94:
F_33 ( V_39 ) ;
V_80:
F_34 ( V_73 , V_5 ) ;
return V_18 ;
}
static int F_35 ( struct V_74 * V_75 )
{
struct V_73 * V_73 = NULL ;
F_36 ( & V_75 -> V_6 , L_22
L_23 , V_75 -> V_95 [ 0 ] , V_75 -> V_95 [ 1 ] ) ;
while ( ( V_73 =
F_37 ( V_96 , V_97 ,
V_73 ) ) ) {
if ( ! F_28 ( V_73 , V_75 ) ) {
F_36 ( & V_75 -> V_6 , L_24 ) ;
return 0 ;
}
}
F_13 ( & V_75 -> V_6 , L_25 ) ;
return - V_78 ;
}
static void F_38 ( struct V_74 * V_98 )
{
struct V_38 * V_39 = V_98 -> V_81 ;
F_16 ( & V_98 -> V_6 , L_26 ) ;
if ( V_39 ) {
struct V_1 * V_2 = F_20 ( V_39 ) ;
F_39 ( V_39 ) ;
F_34 ( V_2 -> V_73 , V_2 -> V_5 ) ;
F_40 ( V_2 -> V_73 ) ;
F_33 ( V_39 ) ;
}
F_41 ( V_98 ) ;
}
static int F_42 ( struct V_74 * V_98 )
{
F_16 ( & V_98 -> V_6 , L_27 ) ;
return 0 ;
}
static int F_43 ( struct V_74 * V_98 )
{
struct V_38 * V_39 = V_98 -> V_81 ;
F_16 ( & V_98 -> V_6 , L_28 ) ;
F_15 ( F_20 ( V_39 ) ) ;
return 0 ;
}
