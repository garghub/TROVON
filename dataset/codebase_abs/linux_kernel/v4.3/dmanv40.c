static bool
F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
switch ( V_2 -> V_5 . V_6 ) {
case V_7 :
case V_8 :
return false ;
case V_9 :
* V_3 = 0x0032e0 ;
* V_4 = 0x38 ;
return true ;
case V_10 :
* V_3 = 0x00330c ;
* V_4 = 0x54 ;
return true ;
default:
F_2 ( 1 ) ;
return false ;
}
}
static int
F_3 ( struct V_11 * V_12 ,
struct V_1 * V_2 , bool V_13 )
{
struct V_14 * V_15 = V_14 ( V_12 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_12 . V_2 . V_5 . V_19 ;
struct V_20 * V_21 = V_19 -> V_21 ;
unsigned long V_22 ;
T_1 V_3 , V_4 ;
int V_23 ;
if ( ! F_1 ( V_2 , & V_3 , & V_4 ) )
return 0 ;
F_4 ( & V_17 -> V_12 . V_24 , V_22 ) ;
F_5 ( V_19 , 0x002500 , 0x00000001 , 0x00000000 ) ;
V_23 = F_6 ( V_19 , 0x003204 ) & ( V_17 -> V_12 . V_25 - 1 ) ;
if ( V_23 == V_15 -> V_12 . V_23 )
F_7 ( V_19 , V_3 , 0x00000000 ) ;
F_8 ( V_21 -> V_26 ) ;
F_9 ( V_21 -> V_26 , V_15 -> V_26 + V_4 , 0x00000000 ) ;
F_10 ( V_21 -> V_26 ) ;
F_5 ( V_19 , 0x002500 , 0x00000001 , 0x00000001 ) ;
F_11 ( & V_17 -> V_12 . V_24 , V_22 ) ;
return 0 ;
}
static int
F_12 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_14 * V_15 = V_14 ( V_12 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_12 . V_2 . V_5 . V_19 ;
struct V_20 * V_21 = V_19 -> V_21 ;
unsigned long V_22 ;
T_1 V_27 , V_3 , V_4 ;
int V_23 ;
if ( ! F_1 ( V_2 , & V_3 , & V_4 ) )
return 0 ;
V_27 = V_15 -> V_28 [ V_2 -> V_5 . V_6 ] -> V_29 >> 4 ;
F_4 ( & V_17 -> V_12 . V_24 , V_22 ) ;
F_5 ( V_19 , 0x002500 , 0x00000001 , 0x00000000 ) ;
V_23 = F_6 ( V_19 , 0x003204 ) & ( V_17 -> V_12 . V_25 - 1 ) ;
if ( V_23 == V_15 -> V_12 . V_23 )
F_7 ( V_19 , V_3 , V_27 ) ;
F_8 ( V_21 -> V_26 ) ;
F_9 ( V_21 -> V_26 , V_15 -> V_26 + V_4 , V_27 ) ;
F_10 ( V_21 -> V_26 ) ;
F_5 ( V_19 , 0x002500 , 0x00000001 , 0x00000001 ) ;
F_11 ( & V_17 -> V_12 . V_24 , V_22 ) ;
return 0 ;
}
static void
F_13 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_14 * V_15 = V_14 ( V_12 ) ;
F_14 ( & V_15 -> V_28 [ V_2 -> V_5 . V_6 ] ) ;
}
static int
F_15 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_14 * V_15 = V_14 ( V_12 ) ;
const int V_28 = V_2 -> V_5 . V_6 ;
T_1 V_3 , V_4 ;
if ( ! F_1 ( V_2 , & V_3 , & V_4 ) )
return 0 ;
return F_16 ( V_31 , NULL , 0 , & V_15 -> V_28 [ V_28 ] ) ;
}
static int
F_17 ( struct V_11 * V_12 ,
struct V_30 * V_31 )
{
struct V_14 * V_15 = V_14 ( V_12 ) ;
struct V_20 * V_21 = V_15 -> V_17 -> V_12 . V_2 . V_5 . V_19 -> V_21 ;
T_1 V_32 = V_15 -> V_12 . V_23 << 23 ;
T_1 V_33 = V_31 -> V_33 ;
int V_34 ;
switch ( V_31 -> V_2 -> V_5 . V_6 ) {
case V_7 :
case V_8 : V_32 |= 0x00000000 ; break;
case V_9 : V_32 |= 0x00100000 ; break;
case V_10 : V_32 |= 0x00200000 ; break;
default:
F_2 ( 1 ) ;
return - V_35 ;
}
F_18 ( & V_15 -> V_17 -> V_12 . V_2 . V_5 . V_36 ) ;
V_34 = F_19 ( V_21 -> V_37 , V_31 , V_15 -> V_12 . V_23 , 4 ,
V_33 , V_32 ) ;
F_20 ( & V_15 -> V_17 -> V_12 . V_2 . V_5 . V_36 ) ;
return V_34 ;
}
static int
F_21 ( struct V_38 * V_12 , const struct V_39 * V_40 ,
void * V_41 , T_1 V_42 , struct V_30 * * V_43 )
{
struct V_30 * V_44 = V_40 -> V_44 ;
union {
struct V_45 V_46 ;
} * args = V_41 ;
struct V_16 * V_17 = V_16 ( V_12 ) ;
struct V_14 * V_15 = NULL ;
struct V_18 * V_19 = V_17 -> V_12 . V_2 . V_5 . V_19 ;
struct V_20 * V_21 = V_19 -> V_21 ;
int V_47 ;
F_22 ( V_44 , L_1 , V_42 ) ;
if ( F_23 ( args -> V_46 , 0 , 0 , false ) ) {
F_22 ( V_44 , L_2
L_3 , args -> V_46 . V_48 ,
args -> V_46 . V_49 , args -> V_46 . V_50 ) ;
if ( ! args -> V_46 . V_49 )
return - V_35 ;
} else
return V_47 ;
if ( ! ( V_15 = F_24 ( sizeof( * V_15 ) , V_51 ) ) )
return - V_52 ;
* V_43 = & V_15 -> V_12 . V_31 ;
V_47 = F_25 ( & V_53 , & V_17 -> V_12 ,
0x1000 , 0x1000 , false , 0 , args -> V_46 . V_49 ,
( 1ULL << V_7 ) |
( 1ULL << V_9 ) |
( 1ULL << V_10 ) |
( 1ULL << V_8 ) ,
0 , 0xc00000 , 0x1000 , V_40 , & V_15 -> V_12 ) ;
V_15 -> V_17 = V_17 ;
if ( V_47 )
return V_47 ;
args -> V_46 . V_23 = V_15 -> V_12 . V_23 ;
V_15 -> V_26 = V_15 -> V_12 . V_23 * 128 ;
F_8 ( V_21 -> V_26 ) ;
F_9 ( V_21 -> V_26 , V_15 -> V_26 + 0x00 , args -> V_46 . V_50 ) ;
F_9 ( V_21 -> V_26 , V_15 -> V_26 + 0x04 , args -> V_46 . V_50 ) ;
F_9 ( V_21 -> V_26 , V_15 -> V_26 + 0x0c , V_15 -> V_12 . V_54 -> V_29 >> 4 ) ;
F_9 ( V_21 -> V_26 , V_15 -> V_26 + 0x18 , 0x30000000 |
V_55 |
V_56 |
#ifdef F_26
V_57 |
#endif
V_58 ) ;
F_9 ( V_21 -> V_26 , V_15 -> V_26 + 0x3c , 0x0001ffff ) ;
F_10 ( V_21 -> V_26 ) ;
return 0 ;
}
