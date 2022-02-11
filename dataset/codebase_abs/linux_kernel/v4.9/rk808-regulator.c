static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_6 -> V_5 - V_7 ;
struct V_8 * V_9 = V_4 -> V_10 [ V_5 ] ;
unsigned int V_11 ;
int V_12 ;
if ( ! V_9 || F_3 ( V_9 ) == 0 )
return F_4 ( V_2 ) ;
V_12 = F_5 ( V_2 -> V_13 ,
V_2 -> V_6 -> V_14 + V_15 ,
& V_11 ) ;
if ( V_12 != 0 )
return V_12 ;
V_11 &= V_2 -> V_6 -> V_16 ;
V_11 >>= F_6 ( V_2 -> V_6 -> V_16 ) - 1 ;
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_17 )
{
int V_12 , V_18 ;
unsigned int V_19 , V_20 , V_11 , V_21 = V_2 -> V_6 -> V_16 ;
V_12 = F_5 ( V_2 -> V_13 , V_2 -> V_6 -> V_14 , & V_11 ) ;
if ( V_12 != 0 )
return V_12 ;
V_20 = V_11 & ~ V_21 ;
V_19 = V_11 & V_21 ;
V_19 >>= F_6 ( V_21 ) - 1 ;
V_18 = V_17 - V_19 ;
while ( V_18 > V_22 ) {
V_19 += V_22 ;
V_11 = V_19 << ( F_6 ( V_21 ) - 1 ) ;
V_11 |= V_20 ;
V_12 = F_8 ( V_2 -> V_13 , V_2 -> V_6 -> V_14 , V_11 ) ;
V_18 = V_17 - V_19 ;
}
V_17 <<= F_6 ( V_21 ) - 1 ;
V_11 = V_20 | V_17 ;
V_12 = F_8 ( V_2 -> V_13 , V_2 -> V_6 -> V_14 , V_11 ) ;
F_9 ( 1 ) ;
return V_12 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_6 -> V_5 - V_7 ;
struct V_8 * V_9 = V_4 -> V_10 [ V_5 ] ;
unsigned int V_23 = V_2 -> V_6 -> V_14 ;
unsigned V_19 ;
int V_12 , V_24 ;
if ( ! V_9 )
return F_7 ( V_2 , V_17 ) ;
V_24 = F_3 ( V_9 ) ;
if ( V_24 == 0 ) {
V_23 += V_15 ;
V_12 = F_5 ( V_2 -> V_13 , V_2 -> V_6 -> V_14 , & V_19 ) ;
} else {
V_12 = F_5 ( V_2 -> V_13 ,
V_23 + V_15 ,
& V_19 ) ;
}
if ( V_12 != 0 )
return V_12 ;
V_17 <<= F_6 ( V_2 -> V_6 -> V_16 ) - 1 ;
V_17 |= V_19 & ~ V_2 -> V_6 -> V_16 ;
V_12 = F_8 ( V_2 -> V_13 , V_23 , V_17 ) ;
if ( V_12 )
return V_12 ;
F_11 ( V_9 , ! V_24 ) ;
return V_12 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_25 ,
unsigned int V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_6 -> V_5 - V_7 ;
struct V_8 * V_9 = V_4 -> V_10 [ V_5 ] ;
if ( ! V_9 )
return 0 ;
return F_13 ( V_2 , V_25 , V_26 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_27 )
{
unsigned int V_28 = V_29 ;
unsigned int V_23 = V_30 [ V_2 -> V_6 -> V_5 -
V_7 ] ;
switch ( V_27 ) {
case 1 ... 2000 :
V_28 = V_31 ;
break;
case 2001 ... 4000 :
V_28 = V_32 ;
break;
case 4001 ... 6000 :
V_28 = V_33 ;
break;
case 6001 ... 10000 :
break;
default:
F_15 ( L_1 ,
V_2 -> V_6 -> V_34 , V_27 ) ;
}
return F_16 ( V_2 -> V_13 , V_23 ,
V_35 , V_28 ) ;
}
static int F_17 ( struct V_1 * V_2 , int V_36 )
{
unsigned int V_23 ;
int V_17 = F_18 ( V_2 , V_36 , V_36 ) ;
if ( V_17 < 0 )
return - V_37 ;
V_23 = V_2 -> V_6 -> V_14 + V_38 ;
return F_16 ( V_2 -> V_13 , V_23 ,
V_2 -> V_6 -> V_16 ,
V_17 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_36 )
{
unsigned int V_23 ;
int V_17 = F_20 ( V_2 , V_36 , V_36 ) ;
if ( V_17 < 0 )
return - V_37 ;
V_23 = V_2 -> V_6 -> V_14 + V_38 ;
return F_16 ( V_2 -> V_13 , V_23 ,
V_2 -> V_6 -> V_16 ,
V_17 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
unsigned int V_23 ;
V_23 = V_2 -> V_6 -> V_39 + V_40 ;
return F_16 ( V_2 -> V_13 , V_23 ,
V_2 -> V_6 -> V_41 ,
0 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
unsigned int V_23 ;
V_23 = V_2 -> V_6 -> V_39 + V_40 ;
return F_16 ( V_2 -> V_13 , V_23 ,
V_2 -> V_6 -> V_41 ,
V_2 -> V_6 -> V_41 ) ;
}
static int F_23 ( struct V_42 * V_43 ,
struct V_42 * V_44 ,
struct V_13 * V_45 ,
struct V_3 * V_4 )
{
struct V_46 * V_47 ;
int V_20 , V_12 = 0 , V_48 ;
V_47 = F_24 ( V_44 -> V_49 , L_2 ) ;
if ( ! V_47 )
return - V_50 ;
for ( V_48 = 0 ; V_48 < F_25 ( V_4 -> V_10 ) ; V_48 ++ ) {
V_4 -> V_10 [ V_48 ] =
F_26 ( V_44 , L_3 , V_48 ,
V_51 ) ;
if ( F_27 ( V_4 -> V_10 [ V_48 ] ) ) {
V_12 = F_28 ( V_4 -> V_10 [ V_48 ] ) ;
F_29 ( V_43 , L_4 , V_48 , V_12 ) ;
goto V_52;
}
if ( ! V_4 -> V_10 [ V_48 ] ) {
F_30 ( V_43 , L_5 , V_48 ) ;
continue;
}
V_20 = V_48 ? V_53 : V_54 ;
V_12 = F_16 ( V_45 , V_55 , V_20 ,
F_31 ( V_4 -> V_10 [ V_48 ] ) ?
0 : V_20 ) ;
}
V_52:
F_32 ( V_47 ) ;
return V_12 ;
}
static int F_33 ( struct V_56 * V_57 )
{
struct V_58 * V_58 = F_34 ( V_57 -> V_43 . V_59 ) ;
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_63 V_64 = {} ;
struct V_1 * V_65 ;
struct V_3 * V_4 ;
const struct V_66 * V_67 ;
int V_12 , V_48 , V_68 ;
V_4 = F_35 ( & V_57 -> V_43 , sizeof( * V_4 ) , V_69 ) ;
if ( ! V_4 )
return - V_70 ;
V_12 = F_23 ( & V_57 -> V_43 , & V_61 -> V_43 ,
V_58 -> V_13 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
F_36 ( V_57 , V_4 ) ;
switch ( V_58 -> V_71 ) {
case V_72 :
V_67 = V_73 ;
V_68 = V_74 ;
break;
case V_75 :
V_67 = V_76 ;
V_68 = V_77 ;
break;
default:
F_29 ( & V_61 -> V_43 , L_6 ,
V_58 -> V_71 ) ;
return - V_37 ;
}
V_64 . V_43 = & V_61 -> V_43 ;
V_64 . V_78 = V_4 ;
V_64 . V_13 = V_58 -> V_13 ;
for ( V_48 = 0 ; V_48 < V_68 ; V_48 ++ ) {
V_65 = F_37 ( & V_57 -> V_43 ,
& V_67 [ V_48 ] , & V_64 ) ;
if ( F_27 ( V_65 ) ) {
F_29 ( & V_61 -> V_43 ,
L_7 , V_48 ) ;
return F_28 ( V_65 ) ;
}
}
return 0 ;
}
