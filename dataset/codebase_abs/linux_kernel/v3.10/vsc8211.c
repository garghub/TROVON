static int F_1 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_1 , V_3 , 0 ) ;
}
static int F_3 ( struct V_1 * V_1 )
{
return F_4 ( V_1 , V_3 , V_4 ,
V_5 ) ;
}
static int F_5 ( struct V_1 * V_1 )
{
return F_4 ( V_1 , V_3 , V_4 , 0 ) ;
}
static int F_6 ( struct V_1 * V_1 )
{
T_1 V_6 ;
return F_7 ( V_1 , V_3 , V_7 , & V_6 ) ;
}
static int F_8 ( struct V_1 * V_1 )
{
return F_9 ( V_1 , V_3 , V_8 ,
V_9 | V_10 ,
V_11 | V_12 ) ;
}
static int F_10 ( struct V_1 * V_1 )
{
return F_9 ( V_1 , V_3 , V_8 ,
V_9 | V_10 ,
V_12 ) ;
}
static int F_11 ( struct V_1 * V_1 , int * V_13 ,
int * V_14 , int * V_15 , int * V_16 )
{
unsigned int V_17 , V_18 , V_19 , V_20 ;
int V_21 , V_22 = - 1 , V_23 = - 1 , V_24 = 0 ;
V_21 = F_7 ( V_1 , V_3 , V_8 , & V_17 ) ;
if ( ! V_21 )
V_21 = F_7 ( V_1 , V_3 , V_25 , & V_18 ) ;
if ( V_21 )
return V_21 ;
if ( V_13 ) {
if ( ! ( V_18 & V_26 ) )
V_21 = F_7 ( V_1 , V_3 , V_25 ,
& V_18 ) ;
if ( V_21 )
return V_21 ;
* V_13 = ( V_18 & V_26 ) != 0 ;
}
if ( ! ( V_17 & V_11 ) ) {
V_23 = ( V_17 & V_27 ) ? V_28 : V_29 ;
if ( V_17 & V_30 )
V_22 = V_31 ;
else if ( V_17 & V_32 )
V_22 = V_33 ;
else
V_22 = V_34 ;
} else if ( V_18 & V_35 ) {
V_21 = F_7 ( V_1 , V_3 , V_36 ,
& V_18 ) ;
if ( V_21 )
return V_21 ;
V_23 = ( V_18 & V_37 ) ? V_28 : V_29 ;
V_22 = F_12 ( V_18 ) ;
if ( V_22 == 0 )
V_22 = V_34 ;
else if ( V_22 == 1 )
V_22 = V_33 ;
else
V_22 = V_31 ;
if ( V_16 && V_23 == V_28 ) {
V_21 = F_7 ( V_1 , V_3 , V_38 ,
& V_19 ) ;
if ( ! V_21 )
V_21 = F_7 ( V_1 , V_3 ,
V_39 , & V_20 ) ;
if ( V_21 )
return V_21 ;
if ( V_19 & V_20 & V_40 )
V_24 = V_41 | V_42 ;
else if ( ( V_19 & V_40 ) &&
( V_19 & V_43 ) &&
( V_20 & V_43 ) )
V_24 = V_42 ;
else if ( ( V_19 & V_43 ) &&
( V_20 & V_40 ) )
V_24 = V_41 ;
}
}
if ( V_14 )
* V_14 = V_22 ;
if ( V_15 )
* V_15 = V_23 ;
if ( V_16 )
* V_16 = V_24 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 , int * V_13 ,
int * V_14 , int * V_15 , int * V_16 )
{
unsigned int V_17 , V_18 , V_19 , V_20 ;
int V_21 , V_22 = - 1 , V_23 = - 1 , V_24 = 0 ;
V_21 = F_7 ( V_1 , V_3 , V_8 , & V_17 ) ;
if ( ! V_21 )
V_21 = F_7 ( V_1 , V_3 , V_25 , & V_18 ) ;
if ( V_21 )
return V_21 ;
if ( V_13 ) {
if ( ! ( V_18 & V_26 ) )
V_21 = F_7 ( V_1 , V_3 , V_25 ,
& V_18 ) ;
if ( V_21 )
return V_21 ;
* V_13 = ( V_18 & V_26 ) != 0 ;
}
if ( ! ( V_17 & V_11 ) ) {
V_23 = ( V_17 & V_27 ) ? V_28 : V_29 ;
if ( V_17 & V_30 )
V_22 = V_31 ;
else if ( V_17 & V_32 )
V_22 = V_33 ;
else
V_22 = V_34 ;
} else if ( V_18 & V_35 ) {
V_21 = F_7 ( V_1 , V_3 , V_38 , & V_19 ) ;
if ( ! V_21 )
V_21 = F_7 ( V_1 , V_3 , V_39 ,
& V_20 ) ;
if ( V_21 )
return V_21 ;
if ( V_20 & V_19 & V_44 ) {
V_23 = V_28 ;
V_22 = V_31 ;
} else if ( V_20 & V_19 & V_45 ) {
V_23 = V_29 ;
V_22 = V_31 ;
}
if ( V_16 && V_23 == V_28 ) {
if ( V_19 & V_20 & V_46 )
V_24 = V_41 | V_42 ;
else if ( ( V_19 & V_46 ) &&
( V_20 & V_19 & V_47 ) )
V_24 = V_42 ;
else if ( ( V_19 & V_47 ) &&
( V_20 & V_46 ) )
V_24 = V_41 ;
}
}
if ( V_14 )
* V_14 = V_22 ;
if ( V_15 )
* V_15 = V_23 ;
if ( V_16 )
* V_16 = V_24 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_48 , int V_49 )
{
int V_21 ;
V_21 = F_4 ( V_48 , V_3 , V_50 , 0x52b5 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_4 ( V_48 , V_3 , 18 , 0x12 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_4 ( V_48 , V_3 , 17 , V_49 ? 0x2803 : 0x3003 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_4 ( V_48 , V_3 , 16 , 0x87fa ) ;
if ( V_21 )
return V_21 ;
V_21 = F_4 ( V_48 , V_3 , V_50 , 0 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
int F_15 ( struct V_1 * V_48 , int V_14 , int V_15 )
{
int V_21 ;
V_21 = F_16 ( V_48 , V_14 , V_15 ) ;
if ( ! V_21 )
V_21 = F_14 ( V_48 , 1 ) ;
return V_21 ;
}
static int F_17 ( struct V_1 * V_1 , int V_49 )
{
return F_9 ( V_1 , 0 , V_8 , V_9 ,
V_49 ? V_9 : 0 ) ;
}
static int F_18 ( struct V_1 * V_1 )
{
unsigned int V_51 ;
int V_21 , V_52 = 0 ;
V_21 = F_7 ( V_1 , V_3 , V_7 , & V_51 ) ;
if ( V_21 )
return V_21 ;
V_51 &= V_5 ;
if ( V_51 & V_53 )
V_52 |= V_54 ;
if ( V_51 & ( V_55 | V_56 ) )
V_52 |= V_57 ;
return V_52 ;
}
int F_19 ( struct V_1 * V_48 , struct V_58 * V_58 ,
int V_59 , const struct V_60 * V_60 )
{
int V_21 ;
unsigned int V_6 ;
F_20 ( V_48 , V_58 , V_59 , & V_61 , V_60 ,
V_62 | V_63 |
V_64 | V_65 | V_66 |
V_67 | V_68 , L_1 ) ;
F_21 ( 20 ) ;
V_21 = F_7 ( V_48 , V_3 , V_69 , & V_6 ) ;
if ( V_21 )
return V_21 ;
if ( V_6 & V_70 ) {
return F_4 ( V_48 , V_3 , V_71 ,
0x100 ) ;
}
V_48 -> V_72 = V_64 | V_65 |
V_66 | V_73 | V_68 ;
V_48 -> V_74 = L_2 ;
V_48 -> V_75 = & V_76 ;
V_21 = F_4 ( V_48 , V_3 , V_50 , 1 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_4 ( V_48 , V_3 , V_77 , 1 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_4 ( V_48 , V_3 , V_50 , 0 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_4 ( V_48 , V_3 , V_69 ,
V_6 | V_78 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_1 ( V_48 , 0 ) ;
if ( V_21 )
return V_21 ;
F_22 ( 5 ) ;
return 0 ;
}
