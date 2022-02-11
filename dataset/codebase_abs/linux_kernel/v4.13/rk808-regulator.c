static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
struct V_6 * V_7 = V_4 -> V_8 [ V_5 ] ;
unsigned int V_9 ;
int V_10 ;
if ( ! V_7 || F_4 ( V_7 ) == 0 )
return F_5 ( V_2 ) ;
V_10 = F_6 ( V_2 -> V_11 ,
V_2 -> V_12 -> V_13 + V_14 ,
& V_9 ) ;
if ( V_10 != 0 )
return V_10 ;
V_9 &= V_2 -> V_12 -> V_15 ;
V_9 >>= F_7 ( V_2 -> V_12 -> V_15 ) - 1 ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_16 )
{
int V_10 , V_17 ;
unsigned int V_18 , V_19 , V_9 , V_20 = V_2 -> V_12 -> V_15 ;
V_10 = F_6 ( V_2 -> V_11 , V_2 -> V_12 -> V_13 , & V_9 ) ;
if ( V_10 != 0 )
return V_10 ;
V_19 = V_9 & ~ V_20 ;
V_18 = V_9 & V_20 ;
V_18 >>= F_7 ( V_20 ) - 1 ;
V_17 = V_16 - V_18 ;
while ( V_17 > V_21 ) {
V_18 += V_21 ;
V_9 = V_18 << ( F_7 ( V_20 ) - 1 ) ;
V_9 |= V_19 ;
V_10 = F_9 ( V_2 -> V_11 , V_2 -> V_12 -> V_13 , V_9 ) ;
V_17 = V_16 - V_18 ;
}
V_16 <<= F_7 ( V_20 ) - 1 ;
V_9 = V_19 | V_16 ;
V_10 = F_9 ( V_2 -> V_11 , V_2 -> V_12 -> V_13 , V_9 ) ;
F_10 ( 1 ) ;
return V_10 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
struct V_6 * V_7 = V_4 -> V_8 [ V_5 ] ;
unsigned int V_22 = V_2 -> V_12 -> V_13 ;
unsigned V_18 ;
int V_10 , V_23 ;
if ( ! V_7 )
return F_8 ( V_2 , V_16 ) ;
V_23 = F_4 ( V_7 ) ;
if ( V_23 == 0 ) {
V_22 += V_14 ;
V_10 = F_6 ( V_2 -> V_11 , V_2 -> V_12 -> V_13 , & V_18 ) ;
} else {
V_10 = F_6 ( V_2 -> V_11 ,
V_22 + V_14 ,
& V_18 ) ;
}
if ( V_10 != 0 )
return V_10 ;
V_16 <<= F_7 ( V_2 -> V_12 -> V_15 ) - 1 ;
V_16 |= V_18 & ~ V_2 -> V_12 -> V_15 ;
V_10 = F_9 ( V_2 -> V_11 , V_22 , V_16 ) ;
if ( V_10 )
return V_10 ;
F_12 ( V_7 , ! V_23 ) ;
return V_10 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned int V_24 ,
unsigned int V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
struct V_6 * V_7 = V_4 -> V_8 [ V_5 ] ;
if ( ! V_7 )
return 0 ;
return F_14 ( V_2 , V_24 , V_25 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_26 )
{
unsigned int V_27 = V_28 ;
unsigned int V_22 = V_29 [ F_3 ( V_2 ) ] ;
switch ( V_26 ) {
case 1 ... 2000 :
V_27 = V_30 ;
break;
case 2001 ... 4000 :
V_27 = V_31 ;
break;
case 4001 ... 6000 :
V_27 = V_32 ;
break;
case 6001 ... 10000 :
break;
default:
F_16 ( L_1 ,
V_2 -> V_12 -> V_33 , V_26 ) ;
}
return F_17 ( V_2 -> V_11 , V_22 ,
V_34 , V_27 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_35 )
{
unsigned int V_22 ;
int V_16 = F_19 ( V_2 , V_35 , V_35 ) ;
if ( V_16 < 0 )
return - V_36 ;
V_22 = V_2 -> V_12 -> V_13 + V_37 ;
return F_17 ( V_2 -> V_11 , V_22 ,
V_2 -> V_12 -> V_15 ,
V_16 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_35 )
{
unsigned int V_22 ;
int V_16 = F_21 ( V_2 , V_35 , V_35 ) ;
if ( V_16 < 0 )
return - V_36 ;
V_22 = V_2 -> V_12 -> V_13 + V_37 ;
return F_17 ( V_2 -> V_11 , V_22 ,
V_2 -> V_12 -> V_15 ,
V_16 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
unsigned int V_22 ;
V_22 = V_2 -> V_12 -> V_38 + V_39 ;
return F_17 ( V_2 -> V_11 , V_22 ,
V_2 -> V_12 -> V_40 ,
0 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
unsigned int V_22 ;
V_22 = V_2 -> V_12 -> V_38 + V_39 ;
return F_17 ( V_2 -> V_11 , V_22 ,
V_2 -> V_12 -> V_40 ,
V_2 -> V_12 -> V_40 ) ;
}
static int F_24 ( struct V_41 * V_42 ,
struct V_41 * V_43 ,
struct V_11 * V_44 ,
struct V_3 * V_4 )
{
struct V_45 * V_46 ;
int V_19 , V_10 = 0 , V_47 ;
V_46 = F_25 ( V_43 -> V_48 , L_2 ) ;
if ( ! V_46 )
return - V_49 ;
for ( V_47 = 0 ; V_47 < F_26 ( V_4 -> V_8 ) ; V_47 ++ ) {
V_4 -> V_8 [ V_47 ] =
F_27 ( V_43 , L_3 , V_47 ,
V_50 ) ;
if ( F_28 ( V_4 -> V_8 [ V_47 ] ) ) {
V_10 = F_29 ( V_4 -> V_8 [ V_47 ] ) ;
F_30 ( V_42 , L_4 , V_47 , V_10 ) ;
goto V_51;
}
if ( ! V_4 -> V_8 [ V_47 ] ) {
F_31 ( V_42 , L_5 , V_47 ) ;
continue;
}
V_19 = V_47 ? V_52 : V_53 ;
V_10 = F_17 ( V_44 , V_54 , V_19 ,
F_32 ( V_4 -> V_8 [ V_47 ] ) ?
0 : V_19 ) ;
}
V_51:
F_33 ( V_46 ) ;
return V_10 ;
}
static int F_34 ( struct V_55 * V_56 )
{
struct V_57 * V_57 = F_35 ( V_56 -> V_42 . V_58 ) ;
struct V_59 * V_60 = V_57 -> V_61 ;
struct V_62 V_63 = {} ;
struct V_1 * V_64 ;
struct V_3 * V_4 ;
const struct V_65 * V_66 ;
int V_10 , V_47 , V_67 ;
V_4 = F_36 ( & V_56 -> V_42 , sizeof( * V_4 ) , V_68 ) ;
if ( ! V_4 )
return - V_69 ;
V_10 = F_24 ( & V_56 -> V_42 , & V_60 -> V_42 ,
V_57 -> V_11 , V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
F_37 ( V_56 , V_4 ) ;
switch ( V_57 -> V_70 ) {
case V_71 :
V_66 = V_72 ;
V_67 = V_73 ;
break;
case V_74 :
V_66 = V_75 ;
V_67 = V_76 ;
break;
default:
F_30 ( & V_60 -> V_42 , L_6 ,
V_57 -> V_70 ) ;
return - V_36 ;
}
V_63 . V_42 = & V_60 -> V_42 ;
V_63 . V_77 = V_4 ;
V_63 . V_11 = V_57 -> V_11 ;
for ( V_47 = 0 ; V_47 < V_67 ; V_47 ++ ) {
V_64 = F_38 ( & V_56 -> V_42 ,
& V_66 [ V_47 ] , & V_63 ) ;
if ( F_28 ( V_64 ) ) {
F_30 ( & V_60 -> V_42 ,
L_7 , V_47 ) ;
return F_29 ( V_64 ) ;
}
}
return 0 ;
}
