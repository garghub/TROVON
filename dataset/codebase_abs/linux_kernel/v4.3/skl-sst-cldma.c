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
static void F_4 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * * V_7 , int V_8 , int V_9 )
{
T_1 * V_10 = * V_7 ;
V_2 -> V_11 . V_12 = 0 ;
while ( V_8 > 0 ) {
T_2 V_13 = F_5 ( V_6 -> V_14 +
( V_2 -> V_11 . V_12 * V_2 -> V_11 . V_15 ) ) ;
V_10 [ 0 ] = F_6 ( F_7 ( V_13 ) ) ;
V_10 [ 1 ] = F_6 ( F_8 ( V_13 ) ) ;
V_10 [ 2 ] = F_6 ( V_2 -> V_11 . V_15 ) ;
V_8 -= V_2 -> V_11 . V_15 ;
V_10 [ 3 ] = ( V_8 || ! V_9 ) ? 0 : F_6 ( 0x01 ) ;
V_10 += 4 ;
V_2 -> V_11 . V_12 ++ ;
}
}
static void F_9 ( struct V_1 * V_2 ,
struct V_5 * V_16 , unsigned int V_17 ,
T_1 V_18 )
{
F_10 ( V_2 , V_19 ,
F_11 ( V_16 -> V_13 ) ) ;
F_10 ( V_2 , V_20 ,
F_12 ( V_16 -> V_13 ) ) ;
F_10 ( V_2 , V_21 , V_17 ) ;
F_10 ( V_2 , V_22 , V_18 - 1 ) ;
F_13 ( V_2 , V_23 ,
V_24 , F_14 ( 1 ) ) ;
F_13 ( V_2 , V_23 ,
V_25 , F_15 ( 1 ) ) ;
F_13 ( V_2 , V_23 ,
V_26 , F_16 ( 1 ) ) ;
F_13 ( V_2 , V_23 ,
V_27 , F_17 ( V_28 ) ) ;
}
static void F_18 ( struct V_1 * V_2 ,
unsigned int V_8 , bool V_29 )
{
if ( V_29 )
F_2 ( V_2 ,
V_30 ,
V_31 ,
F_19 ( 1 ) ) ;
F_20 ( V_2 , V_32 , V_8 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_2 ( V_2 ,
V_30 ,
V_31 ,
F_19 ( 0 ) ) ;
F_20 ( V_2 , V_32 , 0 ) ;
}
static void F_22 ( struct V_1 * V_2 , bool V_29 )
{
if ( V_29 )
F_2 ( V_2 ,
V_23 ,
V_33 , F_23 ( 1 ) ) ;
else
F_2 ( V_2 ,
V_23 ,
V_33 , F_23 ( 0 ) ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_13 ( V_2 , V_23 ,
V_24 , F_14 ( 0 ) ) ;
F_13 ( V_2 , V_23 ,
V_25 , F_15 ( 0 ) ) ;
F_13 ( V_2 , V_23 ,
V_26 , F_16 ( 0 ) ) ;
F_13 ( V_2 , V_23 ,
V_27 , F_17 ( 0 ) ) ;
F_10 ( V_2 , V_19 , F_11 ( 0 ) ) ;
F_10 ( V_2 , V_20 , 0 ) ;
F_10 ( V_2 , V_21 , 0 ) ;
F_10 ( V_2 , V_22 , 0 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_34 = 0 ;
if ( ! F_26 ( V_2 -> V_11 . V_35 ,
V_2 -> V_11 . V_36 ,
F_27 ( V_37 ) ) ) {
F_28 ( V_2 -> V_38 , L_1 , V_39 ) ;
V_34 = - V_40 ;
goto V_41;
}
F_29 ( V_2 -> V_38 , L_2 , V_39 ) ;
if ( V_2 -> V_11 . V_42 != V_43 ) {
F_28 ( V_2 -> V_38 , L_3 , V_39 ) ;
V_34 = - V_40 ;
}
V_41:
V_2 -> V_11 . V_42 = V_44 ;
return V_34 ;
}
static void F_30 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_45 . V_46 ( V_2 , false ) ;
}
static void F_31 ( struct V_1 * V_2 , unsigned int V_8 ,
const void * V_47 , bool V_48 , bool V_49 )
{
F_29 ( V_2 -> V_38 , L_4 , V_8 , V_48 ) ;
F_29 ( V_2 -> V_38 , L_5 ,
V_2 -> V_11 . V_50 , V_49 ) ;
F_29 ( V_2 -> V_38 , L_6 , V_2 -> V_11 . V_51 ) ;
memcpy ( V_2 -> V_11 . V_6 . V_14 + V_2 -> V_11 . V_50 ,
V_47 , V_8 ) ;
if ( V_2 -> V_11 . V_51 == V_2 -> V_11 . V_15 )
V_2 -> V_11 . V_50 = 0 ;
else
V_2 -> V_11 . V_50 = V_2 -> V_11 . V_51 ;
V_2 -> V_11 . V_36 = false ;
if ( V_48 )
F_1 ( V_2 ) ;
V_2 -> V_11 . V_45 . V_52 ( V_2 , V_2 -> V_11 . V_51 , V_49 ) ;
if ( V_49 )
V_2 -> V_11 . V_45 . V_46 ( V_2 , true ) ;
}
static int
F_32 ( struct V_1 * V_2 , const void * V_53 , T_1 V_54 )
{
int V_34 = 0 ;
bool V_55 = true ;
unsigned int V_56 ;
T_1 V_8 ;
unsigned int V_57 = V_54 ;
const void * V_47 = V_53 ;
if ( V_54 <= 0 )
return - V_58 ;
F_29 ( V_2 -> V_38 , L_7 , V_39 , V_57 ) ;
while ( V_57 ) {
if ( V_57 > V_2 -> V_11 . V_15 ) {
if ( V_2 -> V_11 . V_51 == 0 )
V_2 -> V_11 . V_51 = V_2 -> V_11 . V_15 ;
V_8 = V_2 -> V_11 . V_15 ;
F_31 ( V_2 , V_8 , V_47 , true , V_55 ) ;
V_55 = false ;
V_34 = F_25 ( V_2 ) ;
if ( V_34 < 0 ) {
F_30 ( V_2 ) ;
return V_34 ;
}
} else {
F_3 ( V_2 ) ;
if ( ( V_2 -> V_11 . V_51 + V_57 )
<= V_2 -> V_11 . V_15 ) {
V_2 -> V_11 . V_51 += V_57 ;
} else {
V_56 = V_57 -
( V_2 -> V_11 . V_15 -
V_2 -> V_11 . V_51 ) ;
V_2 -> V_11 . V_51 = V_56 ;
}
V_8 = V_57 ;
F_31 ( V_2 , V_8 ,
V_47 , false , V_55 ) ;
}
V_57 -= V_8 ;
V_47 = V_47 + V_8 ;
}
return V_34 ;
}
void F_33 ( struct V_1 * V_2 )
{
T_3 V_59 ;
V_59 =
F_34 ( V_2 , V_60 ) ;
if ( ! ( V_59 & V_61 ) )
V_2 -> V_11 . V_42 = V_62 ;
else
V_2 -> V_11 . V_42 = V_43 ;
V_2 -> V_11 . V_36 = true ;
F_35 ( & V_2 -> V_11 . V_35 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_34 ;
T_1 * V_10 ;
V_2 -> V_11 . V_15 = V_63 ;
V_2 -> V_11 . V_45 . V_64 = F_4 ;
V_2 -> V_11 . V_45 . V_65 = F_9 ;
V_2 -> V_11 . V_45 . V_52 = F_18 ;
V_2 -> V_11 . V_45 . V_66 = F_21 ;
V_2 -> V_11 . V_45 . V_46 = F_22 ;
V_2 -> V_11 . V_45 . V_67 = F_24 ;
V_2 -> V_11 . V_45 . V_68 = F_32 ;
V_2 -> V_11 . V_45 . V_69 = F_30 ;
V_34 = V_2 -> V_70 . V_71 ( V_2 -> V_38 ,
& V_2 -> V_11 . V_6 , V_2 -> V_11 . V_15 ) ;
if ( V_34 < 0 ) {
F_28 ( V_2 -> V_38 , L_8 , V_34 ) ;
return V_34 ;
}
V_34 = V_2 -> V_70 . V_71 ( V_2 -> V_38 ,
& V_2 -> V_11 . V_16 , V_72 ) ;
if ( V_34 < 0 ) {
F_28 ( V_2 -> V_38 , L_9 , V_34 ) ;
V_2 -> V_70 . V_73 ( V_2 -> V_38 , & V_2 -> V_11 . V_6 ) ;
return V_34 ;
}
V_10 = ( T_1 * ) V_2 -> V_11 . V_16 . V_14 ;
V_2 -> V_11 . V_45 . V_64 ( V_2 , & V_2 -> V_11 . V_6 ,
& V_10 , V_2 -> V_11 . V_15 , 1 ) ;
V_2 -> V_11 . V_45 . V_65 ( V_2 , & V_2 -> V_11 . V_16 ,
V_2 -> V_11 . V_15 , V_2 -> V_11 . V_12 ) ;
V_2 -> V_11 . V_51 = 0 ;
V_2 -> V_11 . V_50 = 0 ;
F_37 ( & V_2 -> V_11 . V_35 ) ;
return V_34 ;
}
