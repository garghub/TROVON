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
if ( V_2 -> V_5 . V_11 -> V_12 < 0x44 )
return false ;
* V_3 = 0x00330c ;
* V_4 = 0x54 ;
return true ;
default:
F_2 ( 1 ) ;
return false ;
}
}
static int
F_3 ( struct V_13 * V_14 ,
struct V_1 * V_2 , bool V_15 )
{
struct V_16 * V_17 = V_16 ( V_14 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_11 = V_19 -> V_14 . V_2 . V_5 . V_11 ;
struct V_21 * V_22 = V_11 -> V_22 ;
unsigned long V_23 ;
T_1 V_3 , V_4 ;
int V_24 ;
if ( ! F_1 ( V_2 , & V_3 , & V_4 ) )
return 0 ;
F_4 ( & V_19 -> V_14 . V_25 , V_23 ) ;
F_5 ( V_11 , 0x002500 , 0x00000001 , 0x00000000 ) ;
V_24 = F_6 ( V_11 , 0x003204 ) & ( V_19 -> V_14 . V_26 - 1 ) ;
if ( V_24 == V_17 -> V_14 . V_24 )
F_7 ( V_11 , V_3 , 0x00000000 ) ;
F_8 ( V_22 -> V_27 ) ;
F_9 ( V_22 -> V_27 , V_17 -> V_27 + V_4 , 0x00000000 ) ;
F_10 ( V_22 -> V_27 ) ;
F_5 ( V_11 , 0x002500 , 0x00000001 , 0x00000001 ) ;
F_11 ( & V_19 -> V_14 . V_25 , V_23 ) ;
return 0 ;
}
static int
F_12 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_14 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_11 = V_19 -> V_14 . V_2 . V_5 . V_11 ;
struct V_21 * V_22 = V_11 -> V_22 ;
unsigned long V_23 ;
T_1 V_28 , V_3 , V_4 ;
int V_24 ;
if ( ! F_1 ( V_2 , & V_3 , & V_4 ) )
return 0 ;
V_28 = V_17 -> V_29 [ V_2 -> V_5 . V_6 ] -> V_30 >> 4 ;
F_4 ( & V_19 -> V_14 . V_25 , V_23 ) ;
F_5 ( V_11 , 0x002500 , 0x00000001 , 0x00000000 ) ;
V_24 = F_6 ( V_11 , 0x003204 ) & ( V_19 -> V_14 . V_26 - 1 ) ;
if ( V_24 == V_17 -> V_14 . V_24 )
F_7 ( V_11 , V_3 , V_28 ) ;
F_8 ( V_22 -> V_27 ) ;
F_9 ( V_22 -> V_27 , V_17 -> V_27 + V_4 , V_28 ) ;
F_10 ( V_22 -> V_27 ) ;
F_5 ( V_11 , 0x002500 , 0x00000001 , 0x00000001 ) ;
F_11 ( & V_19 -> V_14 . V_25 , V_23 ) ;
return 0 ;
}
static void
F_13 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_14 ) ;
F_14 ( & V_17 -> V_29 [ V_2 -> V_5 . V_6 ] ) ;
}
static int
F_15 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_16 * V_17 = V_16 ( V_14 ) ;
const int V_29 = V_2 -> V_5 . V_6 ;
T_1 V_3 , V_4 ;
if ( ! F_1 ( V_2 , & V_3 , & V_4 ) )
return 0 ;
return F_16 ( V_32 , NULL , 0 , & V_17 -> V_29 [ V_29 ] ) ;
}
static int
F_17 ( struct V_13 * V_14 ,
struct V_31 * V_32 )
{
struct V_16 * V_17 = V_16 ( V_14 ) ;
struct V_21 * V_22 = V_17 -> V_19 -> V_14 . V_2 . V_5 . V_11 -> V_22 ;
T_1 V_33 = V_17 -> V_14 . V_24 << 23 ;
T_1 V_34 = V_32 -> V_34 ;
int V_35 ;
switch ( V_32 -> V_2 -> V_5 . V_6 ) {
case V_7 :
case V_8 : V_33 |= 0x00000000 ; break;
case V_9 : V_33 |= 0x00100000 ; break;
case V_10 : V_33 |= 0x00200000 ; break;
default:
F_2 ( 1 ) ;
return - V_36 ;
}
F_18 ( & V_17 -> V_19 -> V_14 . V_2 . V_5 . V_37 ) ;
V_35 = F_19 ( V_22 -> V_38 , V_32 , V_17 -> V_14 . V_24 , 4 ,
V_34 , V_33 ) ;
F_20 ( & V_17 -> V_19 -> V_14 . V_2 . V_5 . V_37 ) ;
return V_35 ;
}
static int
F_21 ( struct V_39 * V_14 , const struct V_40 * V_41 ,
void * V_42 , T_1 V_43 , struct V_31 * * V_44 )
{
struct V_31 * V_45 = V_41 -> V_45 ;
union {
struct V_46 V_47 ;
} * args = V_42 ;
struct V_18 * V_19 = V_18 ( V_14 ) ;
struct V_16 * V_17 = NULL ;
struct V_20 * V_11 = V_19 -> V_14 . V_2 . V_5 . V_11 ;
struct V_21 * V_22 = V_11 -> V_22 ;
int V_48 = - V_49 ;
F_22 ( V_45 , L_1 , V_43 ) ;
if ( ! ( V_48 = F_23 ( V_48 , & V_42 , & V_43 , args -> V_47 , 0 , 0 , false ) ) ) {
F_22 ( V_45 , L_2
L_3 , args -> V_47 . V_50 ,
args -> V_47 . V_51 , args -> V_47 . V_52 ) ;
if ( ! args -> V_47 . V_51 )
return - V_36 ;
} else
return V_48 ;
if ( ! ( V_17 = F_24 ( sizeof( * V_17 ) , V_53 ) ) )
return - V_54 ;
* V_44 = & V_17 -> V_14 . V_32 ;
V_48 = F_25 ( & V_55 , & V_19 -> V_14 ,
0x1000 , 0x1000 , false , 0 , args -> V_47 . V_51 ,
( 1ULL << V_7 ) |
( 1ULL << V_9 ) |
( 1ULL << V_10 ) |
( 1ULL << V_8 ) ,
0 , 0xc00000 , 0x1000 , V_41 , & V_17 -> V_14 ) ;
V_17 -> V_19 = V_19 ;
if ( V_48 )
return V_48 ;
args -> V_47 . V_24 = V_17 -> V_14 . V_24 ;
V_17 -> V_27 = V_17 -> V_14 . V_24 * 128 ;
F_8 ( V_22 -> V_27 ) ;
F_9 ( V_22 -> V_27 , V_17 -> V_27 + 0x00 , args -> V_47 . V_52 ) ;
F_9 ( V_22 -> V_27 , V_17 -> V_27 + 0x04 , args -> V_47 . V_52 ) ;
F_9 ( V_22 -> V_27 , V_17 -> V_27 + 0x0c , V_17 -> V_14 . V_56 -> V_30 >> 4 ) ;
F_9 ( V_22 -> V_27 , V_17 -> V_27 + 0x18 , 0x30000000 |
V_57 |
V_58 |
#ifdef F_26
V_59 |
#endif
V_60 ) ;
F_9 ( V_22 -> V_27 , V_17 -> V_27 + 0x3c , 0x0001ffff ) ;
F_10 ( V_22 -> V_27 ) ;
return 0 ;
}
