static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ,
V_4 , V_4 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 ,
V_3 , V_4 , 0 ) ;
}
static void F_4 ( struct V_1 * V_2 , bool V_5 )
{
unsigned char V_6 ;
int V_7 ;
F_2 ( V_2 ,
V_8 ,
V_9 , F_5 ( V_5 ) ) ;
F_6 ( 3 ) ;
V_7 = 300 ;
do {
V_6 = F_7 ( V_2 , V_8 ) &
V_9 ;
if ( V_5 && V_6 )
break;
else if ( ! V_5 && ! V_6 )
break;
F_6 ( 3 ) ;
} while ( -- V_7 );
if ( V_7 == 0 )
F_8 ( V_2 -> V_10 , L_1 , V_6 , V_5 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 0 ) ;
F_10 ( V_2 , V_8 ,
V_11 , F_11 ( 0 ) ) ;
F_10 ( V_2 , V_8 ,
V_12 , F_12 ( 0 ) ) ;
F_10 ( V_2 , V_8 ,
V_13 , F_13 ( 0 ) ) ;
F_10 ( V_2 , V_8 ,
V_14 , F_14 ( 0 ) ) ;
F_15 ( V_2 , V_15 , F_16 ( 0 ) ) ;
F_15 ( V_2 , V_16 , 0 ) ;
F_15 ( V_2 , V_17 , 0 ) ;
F_15 ( V_2 , V_18 , 0 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
T_1 * * V_21 , int V_22 , int V_23 )
{
T_1 * V_24 = * V_21 ;
V_2 -> V_25 . V_26 = 0 ;
while ( V_22 > 0 ) {
T_2 V_27 = F_18 ( V_20 -> V_28 +
( V_2 -> V_25 . V_26 * V_2 -> V_25 . V_29 ) ) ;
V_24 [ 0 ] = F_19 ( F_20 ( V_27 ) ) ;
V_24 [ 1 ] = F_19 ( F_21 ( V_27 ) ) ;
V_24 [ 2 ] = F_19 ( V_2 -> V_25 . V_29 ) ;
V_22 -= V_2 -> V_25 . V_29 ;
V_24 [ 3 ] = ( V_22 || ! V_23 ) ? 0 : F_19 ( 0x01 ) ;
V_24 += 4 ;
V_2 -> V_25 . V_26 ++ ;
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_19 * V_30 , unsigned int V_31 ,
T_1 V_32 )
{
F_9 ( V_2 ) ;
F_15 ( V_2 , V_15 ,
F_16 ( V_30 -> V_27 ) ) ;
F_15 ( V_2 , V_16 ,
F_23 ( V_30 -> V_27 ) ) ;
F_15 ( V_2 , V_17 , V_31 ) ;
F_15 ( V_2 , V_18 , V_32 - 1 ) ;
F_10 ( V_2 , V_8 ,
V_11 , F_11 ( 1 ) ) ;
F_10 ( V_2 , V_8 ,
V_12 , F_12 ( 1 ) ) ;
F_10 ( V_2 , V_8 ,
V_13 , F_13 ( 1 ) ) ;
F_10 ( V_2 , V_8 ,
V_14 , F_14 ( V_33 ) ) ;
}
static void F_24 ( struct V_1 * V_2 ,
unsigned int V_22 , bool V_5 )
{
if ( V_5 )
F_2 ( V_2 ,
V_34 ,
V_35 ,
F_25 ( 1 ) ) ;
F_26 ( V_2 , V_36 , V_22 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_2 ( V_2 ,
V_34 ,
V_35 ,
F_25 ( 0 ) ) ;
F_26 ( V_2 , V_36 , 0 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
F_9 ( V_2 ) ;
V_2 -> V_37 . V_38 ( V_2 -> V_10 , & V_2 -> V_25 . V_20 ) ;
V_2 -> V_37 . V_38 ( V_2 -> V_10 , & V_2 -> V_25 . V_30 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_39 = 0 ;
if ( ! F_30 ( V_2 -> V_25 . V_40 ,
V_2 -> V_25 . V_41 ,
F_31 ( V_42 ) ) ) {
F_8 ( V_2 -> V_10 , L_2 , V_43 ) ;
V_39 = - V_44 ;
goto V_45;
}
F_32 ( V_2 -> V_10 , L_3 , V_43 ) ;
if ( V_2 -> V_25 . V_46 != V_47 ) {
F_8 ( V_2 -> V_10 , L_4 , V_43 ) ;
V_39 = - V_44 ;
}
V_45:
V_2 -> V_25 . V_46 = V_48 ;
return V_39 ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_4 ( V_2 , false ) ;
}
static void F_34 ( struct V_1 * V_2 , unsigned int V_22 ,
const void * V_49 , bool V_50 , bool V_51 )
{
F_32 ( V_2 -> V_10 , L_5 , V_22 , V_50 ) ;
F_32 ( V_2 -> V_10 , L_6 ,
V_2 -> V_25 . V_52 , V_51 ) ;
F_32 ( V_2 -> V_10 , L_7 , V_2 -> V_25 . V_53 ) ;
if ( V_2 -> V_25 . V_52 + V_22 > V_2 -> V_25 . V_29 ) {
unsigned int V_54 = V_2 -> V_25 . V_29 -
V_2 -> V_25 . V_52 ;
memcpy ( V_2 -> V_25 . V_20 . V_28 + V_2 -> V_25 . V_52 ,
V_49 , V_54 ) ;
V_22 -= V_54 ;
V_49 += V_54 ;
V_2 -> V_25 . V_52 = 0 ;
}
memcpy ( V_2 -> V_25 . V_20 . V_28 + V_2 -> V_25 . V_52 ,
V_49 , V_22 ) ;
if ( V_2 -> V_25 . V_53 == V_2 -> V_25 . V_29 )
V_2 -> V_25 . V_52 = 0 ;
else
V_2 -> V_25 . V_52 = V_2 -> V_25 . V_53 ;
V_2 -> V_25 . V_41 = false ;
if ( V_50 )
F_1 ( V_2 ) ;
V_2 -> V_25 . V_55 . V_56 ( V_2 , V_2 -> V_25 . V_53 , V_51 ) ;
if ( V_51 )
V_2 -> V_25 . V_55 . V_57 ( V_2 , true ) ;
}
static int
F_35 ( struct V_1 * V_2 , const void * V_58 ,
T_1 V_59 , bool V_60 )
{
int V_39 = 0 ;
bool V_61 = true ;
unsigned int V_62 ;
T_1 V_22 ;
unsigned int V_63 = V_59 ;
const void * V_49 = V_58 ;
if ( V_59 <= 0 )
return - V_64 ;
F_32 ( V_2 -> V_10 , L_8 , V_43 , V_63 ) ;
while ( V_63 ) {
if ( V_63 > V_2 -> V_25 . V_29 ) {
if ( V_2 -> V_25 . V_53 == 0 )
V_2 -> V_25 . V_53 = V_2 -> V_25 . V_29 ;
V_22 = V_2 -> V_25 . V_29 ;
F_34 ( V_2 , V_22 , V_49 , true , V_61 ) ;
if ( V_60 ) {
V_61 = false ;
V_39 = F_29 ( V_2 ) ;
if ( V_39 < 0 ) {
F_33 ( V_2 ) ;
return V_39 ;
}
}
} else {
F_3 ( V_2 ) ;
if ( ( V_2 -> V_25 . V_53 + V_63 )
<= V_2 -> V_25 . V_29 ) {
V_2 -> V_25 . V_53 += V_63 ;
} else {
V_62 = V_63 -
( V_2 -> V_25 . V_29 -
V_2 -> V_25 . V_53 ) ;
V_2 -> V_25 . V_53 = V_62 ;
}
V_22 = V_63 ;
F_34 ( V_2 , V_22 ,
V_49 , false , V_61 ) ;
}
V_63 -= V_22 ;
V_49 = V_49 + V_22 ;
if ( ! V_60 )
return V_63 ;
}
return V_63 ;
}
void F_36 ( struct V_1 * V_2 )
{
T_3 V_65 ;
V_65 =
F_37 ( V_2 , V_66 ) ;
if ( ! ( V_65 & V_67 ) )
V_2 -> V_25 . V_46 = V_68 ;
else
V_2 -> V_25 . V_46 = V_47 ;
V_2 -> V_25 . V_41 = true ;
F_38 ( & V_2 -> V_25 . V_40 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
int V_39 ;
T_1 * V_24 ;
V_2 -> V_25 . V_29 = V_69 ;
V_2 -> V_25 . V_55 . V_70 = F_17 ;
V_2 -> V_25 . V_55 . V_71 = F_22 ;
V_2 -> V_25 . V_55 . V_56 = F_24 ;
V_2 -> V_25 . V_55 . V_72 = F_27 ;
V_2 -> V_25 . V_55 . V_57 = F_4 ;
V_2 -> V_25 . V_55 . V_73 = F_28 ;
V_2 -> V_25 . V_55 . V_74 = F_35 ;
V_2 -> V_25 . V_55 . V_75 = F_33 ;
V_39 = V_2 -> V_37 . V_76 ( V_2 -> V_10 ,
& V_2 -> V_25 . V_20 , V_2 -> V_25 . V_29 ) ;
if ( V_39 < 0 ) {
F_8 ( V_2 -> V_10 , L_9 , V_39 ) ;
return V_39 ;
}
V_39 = V_2 -> V_37 . V_76 ( V_2 -> V_10 ,
& V_2 -> V_25 . V_30 , V_77 ) ;
if ( V_39 < 0 ) {
F_8 ( V_2 -> V_10 , L_10 , V_39 ) ;
V_2 -> V_37 . V_38 ( V_2 -> V_10 , & V_2 -> V_25 . V_20 ) ;
return V_39 ;
}
V_24 = ( T_1 * ) V_2 -> V_25 . V_30 . V_28 ;
V_2 -> V_25 . V_55 . V_70 ( V_2 , & V_2 -> V_25 . V_20 ,
& V_24 , V_2 -> V_25 . V_29 , 1 ) ;
V_2 -> V_25 . V_55 . V_71 ( V_2 , & V_2 -> V_25 . V_30 ,
V_2 -> V_25 . V_29 , V_2 -> V_25 . V_26 ) ;
V_2 -> V_25 . V_53 = 0 ;
V_2 -> V_25 . V_52 = 0 ;
F_40 ( & V_2 -> V_25 . V_40 ) ;
return V_39 ;
}
