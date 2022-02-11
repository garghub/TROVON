static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
int V_6 ;
V_6 = F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_10 , & V_5 ) ;
if ( V_6 )
return V_6 ;
return ( V_5 & V_11 ) == 0 ;
}
static T_2 F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_12 = F_5 ( V_2 ) ;
T_1 V_13 ;
int V_14 , V_6 ;
V_6 = F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_15 , & V_13 ) ;
if ( V_6 )
goto V_16;
V_13 &= V_17 ;
V_13 >>= V_18 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
if ( V_13 == V_4 -> V_19 [ V_14 ] . V_13 )
return V_14 ;
V_16:
F_6 ( L_1 ,
V_20 , F_7 ( V_2 ) ) ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 )
{
int V_21 , V_6 ;
T_1 V_5 ;
struct V_1 * V_2 = & V_4 -> V_7 . V_2 ;
const char * V_22 = F_7 ( V_2 ) ;
V_6 = F_9 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_10 ,
V_23 , V_23 ) ;
if ( V_6 )
return V_6 ;
for ( V_21 = 500 ; V_21 > 0 ; V_21 -- ) {
V_6 = F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_10 , & V_5 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_5 & V_23 ) )
return 0 ;
F_10 ( 1 ) ;
}
F_11 ( 1 , L_2 , V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
T_1 V_13 = V_4 -> V_19 [ V_24 ] . V_13 << V_18 ;
V_6 = F_9 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_15 ,
V_17 , V_13 ) ;
if ( V_6 )
return V_6 ;
return F_8 ( V_4 ) ;
}
static unsigned long
F_13 ( unsigned long V_25 , T_1 V_26 , T_1 V_27 , T_1 V_28 , T_1 V_29 )
{
if ( V_29 ) {
V_25 *= 2 ;
V_25 /= V_29 + 1 ;
}
if ( V_28 ) {
T_3 V_30 = V_25 ;
V_30 *= V_26 ;
F_14 ( V_30 , V_27 ) ;
V_25 = V_30 ;
}
return V_25 ;
}
static unsigned long
F_15 ( struct V_1 * V_2 , unsigned long V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_13 , V_29 , V_26 = 0 , V_27 = 0 , V_28 = 0 , V_32 ;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_15 , & V_13 ) ;
if ( V_4 -> V_33 ) {
V_32 = F_16 ( V_4 -> V_33 ) - 1 ;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_34 , & V_26 ) ;
V_26 &= V_32 ;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_35 , & V_27 ) ;
V_27 = ~ V_27 ;
V_27 &= V_32 ;
V_27 += V_26 ;
V_28 = V_13 & V_36 ;
V_28 >>= V_37 ;
}
V_32 = F_16 ( V_4 -> V_38 ) - 1 ;
V_29 = V_13 >> V_39 ;
V_29 &= V_32 ;
return F_13 ( V_31 , V_26 , V_27 , V_28 , V_29 ) ;
}
static int F_17 ( struct V_1 * V_2 , const struct V_40 * V_41 ,
struct V_42 * V_43 ,
enum V_44 V_45 )
{
unsigned long V_46 , V_25 = V_43 -> V_25 ;
struct V_1 * V_47 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_24 ;
switch ( V_45 ) {
case FLOOR :
V_41 = F_18 ( V_41 , V_25 ) ;
break;
case CEIL :
V_41 = F_19 ( V_41 , V_25 ) ;
break;
default:
return - V_48 ;
} ;
if ( ! V_41 )
return - V_48 ;
V_24 = F_20 ( V_2 , V_4 -> V_19 , V_41 -> V_49 ) ;
if ( V_24 < 0 )
return V_24 ;
V_46 = F_21 ( V_2 ) ;
V_47 = F_22 ( V_2 , V_24 ) ;
if ( V_46 & V_50 ) {
if ( V_41 -> V_51 ) {
V_25 /= 2 ;
V_25 *= V_41 -> V_51 + 1 ;
}
if ( V_41 -> V_27 ) {
T_3 V_30 = V_25 ;
V_30 = V_30 * V_41 -> V_27 ;
F_14 ( V_30 , V_41 -> V_26 ) ;
V_25 = V_30 ;
}
} else {
V_25 = F_23 ( V_47 ) ;
}
V_43 -> V_52 = V_47 ;
V_43 -> V_53 = V_25 ;
V_43 -> V_25 = V_41 -> V_54 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_17 ( V_2 , V_4 -> V_40 , V_43 , CEIL ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_17 ( V_2 , V_4 -> V_40 , V_43 , FLOOR ) ;
}
static int F_26 ( struct V_3 * V_4 , const struct V_40 * V_41 )
{
T_1 V_13 , V_32 ;
struct V_1 * V_2 = & V_4 -> V_7 . V_2 ;
int V_6 , V_24 = F_20 ( V_2 , V_4 -> V_19 , V_41 -> V_49 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_4 -> V_33 && V_41 -> V_27 ) {
V_32 = F_16 ( V_4 -> V_33 ) - 1 ;
V_6 = F_9 ( V_4 -> V_7 . V_8 ,
V_4 -> V_9 + V_34 , V_32 , V_41 -> V_26 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_9 ( V_4 -> V_7 . V_8 ,
V_4 -> V_9 + V_35 , V_32 , ~ ( V_41 -> V_27 - V_41 -> V_26 ) ) ;
if ( V_6 )
return V_6 ;
V_6 = F_9 ( V_4 -> V_7 . V_8 ,
V_4 -> V_9 + V_55 , V_32 , ~ V_41 -> V_27 ) ;
if ( V_6 )
return V_6 ;
}
V_32 = F_16 ( V_4 -> V_38 ) - 1 ;
V_32 |= V_17 | V_36 ;
V_13 = V_41 -> V_51 << V_39 ;
V_13 |= V_4 -> V_19 [ V_24 ] . V_13 << V_18 ;
if ( V_4 -> V_33 && V_41 -> V_27 && ( V_41 -> V_26 != V_41 -> V_27 ) )
V_13 |= V_56 ;
V_6 = F_9 ( V_4 -> V_7 . V_8 ,
V_4 -> V_9 + V_15 , V_32 , V_13 ) ;
if ( V_6 )
return V_6 ;
return F_8 ( V_4 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_25 ,
enum V_44 V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_40 * V_41 ;
switch ( V_45 ) {
case FLOOR :
V_41 = F_18 ( V_4 -> V_40 , V_25 ) ;
break;
case CEIL :
V_41 = F_19 ( V_4 -> V_40 , V_25 ) ;
break;
default:
return - V_48 ;
} ;
if ( ! V_41 )
return - V_48 ;
return F_26 ( V_4 , V_41 ) ;
}
static int F_28 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 )
{
return F_27 ( V_2 , V_25 , CEIL ) ;
}
static int F_29 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 )
{
return F_27 ( V_2 , V_25 , FLOOR ) ;
}
static int F_30 ( struct V_1 * V_2 ,
unsigned long V_25 , unsigned long V_31 , T_2 V_24 )
{
return F_27 ( V_2 , V_25 , CEIL ) ;
}
static int F_31 ( struct V_1 * V_2 ,
unsigned long V_25 , unsigned long V_31 , T_2 V_24 )
{
return F_27 ( V_2 , V_25 , FLOOR ) ;
}
static int F_32 ( struct V_1 * V_2 , unsigned long V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const char * V_22 = F_7 ( V_2 ) ;
int V_6 , V_21 ;
V_6 = F_9 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_10 ,
V_57 , V_57 ) ;
if ( V_6 )
return V_6 ;
for ( V_21 = 500 ; V_21 > 0 ; V_21 -- ) {
V_6 = F_1 ( V_2 ) ;
if ( V_6 )
break;
F_10 ( 1 ) ;
}
if ( ! V_21 )
F_33 ( L_3 , V_22 ) ;
V_6 = F_27 ( V_2 , V_25 , CEIL ) ;
if ( V_6 )
return V_6 ;
return F_9 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_10 ,
V_57 , 0 ) ;
}
static int F_34 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_58 = V_25 ;
if ( ! F_35 ( V_2 -> V_59 ) )
return 0 ;
return F_32 ( V_2 , V_4 -> V_58 ) ;
}
static unsigned long
F_36 ( struct V_1 * V_2 , unsigned long V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_58 = F_15 ( V_2 , V_31 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_32 ( V_2 , V_4 -> V_58 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_34 ( V_2 , V_4 -> V_40 [ 0 ] . V_54 , 0 ) ;
}
static int F_39 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 V_41 = * V_4 -> V_40 ;
const struct V_60 * V_61 ;
int V_62 = 100000 ;
T_4 V_63 = V_31 ;
T_4 V_64 ;
T_1 V_32 = F_16 ( V_4 -> V_38 ) - 1 ;
T_1 V_29 ;
if ( V_63 == 810000000 )
V_61 = V_65 ;
else
V_61 = V_66 ;
for (; V_61 -> V_67 ; V_61 ++ ) {
V_64 = V_25 ;
V_64 *= V_61 -> V_68 ;
V_64 = F_40 ( V_64 , V_61 -> V_67 ) ;
if ( ( V_63 < ( V_64 - V_62 ) ) ||
( V_63 > ( V_64 + V_62 ) ) )
continue;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_15 ,
& V_29 ) ;
V_41 . V_51 = V_29 ;
V_41 . V_51 >>= V_39 ;
V_41 . V_51 &= V_32 ;
V_41 . V_26 = V_61 -> V_67 ;
V_41 . V_27 = V_61 -> V_68 ;
return F_26 ( V_4 , & V_41 ) ;
}
return - V_48 ;
}
static int F_41 ( struct V_1 * V_2 ,
unsigned long V_25 , unsigned long V_31 , T_2 V_24 )
{
return F_39 ( V_2 , V_25 , V_31 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_40 * V_41 = V_4 -> V_40 ;
const struct V_60 * V_61 ;
int V_62 = 100000 ;
T_4 V_64 ;
T_1 V_32 = F_16 ( V_4 -> V_38 ) - 1 ;
T_1 V_29 ;
int V_24 = F_20 ( V_2 , V_4 -> V_19 , V_41 -> V_49 ) ;
V_43 -> V_52 = F_22 ( V_2 , V_24 ) ;
V_43 -> V_53 = F_23 ( V_43 -> V_52 ) ;
if ( V_43 -> V_53 == 810000000 )
V_61 = V_65 ;
else
V_61 = V_66 ;
for (; V_61 -> V_67 ; V_61 ++ ) {
V_64 = V_43 -> V_25 ;
V_64 *= V_61 -> V_68 ;
V_64 = F_40 ( V_64 , V_61 -> V_67 ) ;
if ( ( V_43 -> V_53 < ( V_64 - V_62 ) ) ||
( V_43 -> V_53 > ( V_64 + V_62 ) ) )
continue;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_15 ,
& V_29 ) ;
V_29 >>= V_39 ;
V_29 &= V_32 ;
V_43 -> V_25 = F_13 ( V_43 -> V_53 ,
V_61 -> V_67 , V_61 -> V_68 ,
! ! V_61 -> V_68 , V_29 ) ;
return 0 ;
}
return - V_48 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_40 * V_41 = V_4 -> V_40 ;
int V_24 = F_20 ( V_2 , V_4 -> V_19 , V_41 -> V_49 ) ;
unsigned long V_31 , div ;
T_1 V_32 = F_16 ( V_4 -> V_38 ) - 1 ;
struct V_1 * V_47 ;
if ( V_43 -> V_25 == 0 )
return - V_48 ;
V_43 -> V_52 = V_47 = F_22 ( V_2 , V_24 ) ;
V_43 -> V_53 = V_31 = F_44 ( V_47 , V_43 -> V_25 ) ;
div = F_45 ( ( 2 * V_31 ) , V_43 -> V_25 ) - 1 ;
div = F_46 ( T_1 , div , V_32 ) ;
V_43 -> V_25 = F_13 ( V_31 , 0 , 0 , 0 , div ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 V_41 = * V_4 -> V_40 ;
unsigned long div ;
T_1 V_32 = F_16 ( V_4 -> V_38 ) - 1 ;
div = F_45 ( ( 2 * V_31 ) , V_25 ) - 1 ;
div = F_46 ( T_1 , div , V_32 ) ;
V_41 . V_51 = div ;
return F_26 ( V_4 , & V_41 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
unsigned long V_25 , unsigned long V_31 , T_2 V_24 )
{
return F_47 ( V_2 , V_25 , V_31 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_31 , div ;
T_1 V_32 = F_16 ( V_4 -> V_38 ) - 1 ;
struct V_1 * V_47 ;
unsigned long V_25 = V_43 -> V_25 ;
if ( V_25 == 0 )
return - V_48 ;
V_47 = V_43 -> V_52 ;
V_43 -> V_53 = V_31 = F_44 ( V_47 , V_25 ) ;
div = F_45 ( ( 2 * V_31 ) , V_25 ) - 1 ;
div = F_46 ( T_1 , div , V_32 ) ;
V_43 -> V_25 = F_13 ( V_31 , 0 , 0 , 0 , div ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 V_41 = { 0 } ;
unsigned long div ;
int V_14 , V_12 = F_5 ( V_2 ) ;
T_1 V_32 = F_16 ( V_4 -> V_38 ) - 1 ;
T_1 V_13 ;
div = F_45 ( ( 2 * V_31 ) , V_25 ) - 1 ;
div = F_46 ( T_1 , div , V_32 ) ;
V_41 . V_51 = div ;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_15 , & V_13 ) ;
V_13 &= V_17 ;
V_13 >>= V_18 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
if ( V_13 == V_4 -> V_19 [ V_14 ] . V_13 ) {
V_41 . V_49 = V_4 -> V_19 [ V_14 ] . V_49 ;
return F_26 ( V_4 , & V_41 ) ;
}
}
return - V_48 ;
}
static int F_51 ( struct V_1 * V_2 ,
unsigned long V_25 , unsigned long V_31 , T_2 V_24 )
{
return F_50 ( V_2 , V_25 , V_31 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
unsigned long V_64 , V_63 ;
int V_62 = 100000 ;
const struct V_60 * V_61 = V_69 ;
for (; V_61 -> V_67 ; V_61 ++ ) {
V_64 = ( V_43 -> V_25 * V_61 -> V_68 ) / V_61 -> V_67 ;
V_63 = F_44 ( V_43 -> V_52 , V_64 ) ;
if ( ( V_63 < ( V_64 - V_62 ) ) ||
( V_63 > ( V_64 + V_62 ) ) )
continue;
V_43 -> V_53 = V_63 ;
V_43 -> V_25 = ( V_63 * V_61 -> V_67 ) / V_61 -> V_68 ;
return 0 ;
}
return - V_48 ;
}
static int F_53 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 V_41 = { 0 } ;
const struct V_60 * V_61 = V_69 ;
unsigned long V_64 ;
int V_62 = 100000 ;
T_1 V_32 = F_16 ( V_4 -> V_38 ) - 1 ;
T_1 V_29 , V_13 ;
int V_14 , V_12 = F_5 ( V_2 ) ;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_15 , & V_13 ) ;
V_13 &= V_17 ;
V_13 >>= V_18 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
if ( V_13 == V_4 -> V_19 [ V_14 ] . V_13 ) {
V_41 . V_49 = V_4 -> V_19 [ V_14 ] . V_49 ;
break;
}
for (; V_61 -> V_67 ; V_61 ++ ) {
V_64 = ( V_25 * V_61 -> V_68 ) / V_61 -> V_67 ;
if ( ( V_31 < ( V_64 - V_62 ) ) ||
( V_31 > ( V_64 + V_62 ) ) )
continue;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_15 ,
& V_29 ) ;
V_41 . V_51 = V_29 ;
V_41 . V_51 >>= V_39 ;
V_41 . V_51 &= V_32 ;
V_41 . V_26 = V_61 -> V_67 ;
V_41 . V_27 = V_61 -> V_68 ;
return F_26 ( V_4 , & V_41 ) ;
}
return - V_48 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 , T_2 V_24 )
{
return F_53 ( V_2 , V_25 , V_31 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_42 V_70 = { } ;
struct V_1 * V_71 , * V_72 , * V_73 , * V_74 ;
unsigned long V_75 ;
int V_6 ;
V_74 = F_22 ( V_2 , 0 ) ;
if ( V_43 -> V_25 == F_23 ( V_74 ) ) {
V_43 -> V_52 = V_74 ;
return 0 ;
}
V_73 = F_22 ( V_2 , 2 ) ;
V_71 = F_22 ( V_2 , 3 ) ;
V_72 = F_22 ( V_2 , 4 ) ;
V_75 = F_23 ( V_73 ) ;
V_70 . V_25 = V_43 -> V_25 = F_56 ( V_43 -> V_25 , V_75 ) ;
if ( V_43 -> V_25 == V_75 ) {
V_43 -> V_25 = V_43 -> V_53 = V_75 ;
V_43 -> V_52 = V_73 ;
return 0 ;
}
if ( V_43 -> V_52 == V_73 ) {
if ( F_23 ( V_72 ) == V_43 -> V_25 )
V_43 -> V_52 = V_72 ;
else
V_43 -> V_52 = V_71 ;
} else if ( V_43 -> V_52 == V_72 ) {
V_43 -> V_52 = V_71 ;
} else {
V_43 -> V_52 = V_72 ;
}
V_6 = F_57 ( V_43 -> V_52 , & V_70 ) ;
if ( V_6 )
return V_6 ;
V_43 -> V_25 = V_43 -> V_53 = V_70 . V_25 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 , T_2 V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_13 ;
int V_6 ;
V_13 = V_4 -> V_19 [ V_24 ] . V_13 << V_18 ;
V_6 = F_59 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_15 , V_13 ) ;
if ( V_6 )
return V_6 ;
return F_8 ( V_4 ) ;
}
static int F_60 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 )
{
return 0 ;
}
