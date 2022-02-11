static int F_1 ( struct V_1 * V_2 , unsigned int * V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_7 , & V_4 ,
sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = F_3 ( V_4 ) ;
V_5 = ( V_5 & V_8 ) >> V_9 ;
if ( V_5 >= F_4 ( V_10 ) )
return - V_11 ;
* V_3 = V_10 [ V_5 ] ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
bool V_12 ;
int V_13 , V_6 ;
for ( V_13 = 0 ; V_13 < F_4 ( V_10 ) ; ++ V_13 ) {
if ( V_10 [ V_13 ] == V_3 )
break;
}
if ( V_13 == F_4 ( V_10 ) )
return - V_14 ;
V_6 = F_2 ( V_2 , V_7 , & V_4 ,
sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = F_3 ( V_4 ) ;
V_5 &= ~ ( V_8 | V_15 ) ;
V_5 |= V_13 << V_9 ;
V_12 = V_5 != F_3 ( V_4 ) ;
V_4 = F_6 ( V_5 ) ;
V_6 = F_7 ( V_2 , V_7 , & V_4 ,
sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_12 ) {
if ( F_8 ( 4000 ) > 0 )
return - V_16 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
enum V_17 * V_18 )
{
T_1 V_4 ;
T_2 V_5 ;
unsigned int V_19 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_7 , & V_4 ,
sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = F_3 ( V_4 ) ;
V_19 = V_5 & V_20 ;
if ( V_19 == 0x00 ) {
* V_18 = V_21 ;
} else if ( V_19 == 0x01 ) {
* V_18 = V_22 ;
} else if ( V_19 == 0x10 ) {
* V_18 = V_23 ;
} else if ( V_19 == 0x18 || V_19 == 0x19 ) {
V_6 = F_2 ( V_2 , V_24 ,
& V_4 , sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = F_3 ( V_4 ) ;
if ( V_19 == 0x18 ) {
if ( V_5 & V_25 )
* V_18 = V_26 ;
else
* V_18 = V_27 ;
} else {
if ( V_5 & V_28 )
* V_18 = V_29 ;
else
* V_18 = V_30 ;
}
} else {
* V_18 = V_31 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , bool V_32 )
{
T_1 V_4 ;
T_2 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_7 , & V_4 ,
sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return 0 ;
V_5 = F_3 ( V_4 ) ;
if ( V_32 )
V_5 |= V_15 ;
else
V_5 &= ~ V_15 ;
V_4 = F_6 ( V_5 ) ;
return F_7 ( V_2 , V_7 , & V_4 ,
sizeof( V_4 ) ) ;
}
static void F_11 ( struct V_33 * V_34 ,
enum V_35 V_36 ,
enum V_37 V_38 ,
unsigned char V_39 )
{
unsigned char V_40 [ 3 ] = { 0 , 0 , 0 } ;
V_34 -> V_41 = 2 ;
V_40 [ 0 ] = V_39 ;
V_40 [ 1 ] = V_39 ;
if ( V_38 & V_42 )
V_40 [ 2 ] = V_39 ;
if ( V_36 == V_43 ) {
if ( V_38 & V_44 ) {
V_40 [ 0 ] += 2 ;
V_40 [ 1 ] += 2 ;
if ( V_38 & V_42 )
V_40 [ 2 ] += 2 ;
}
if ( V_38 & V_45 ) {
V_40 [ 0 ] += 2 ;
V_40 [ 1 ] += 2 ;
if ( V_38 & V_42 )
V_40 [ 2 ] += 2 ;
}
if ( V_38 & V_46 ) {
V_40 [ 0 ] += 2 ;
V_40 [ 1 ] += 2 ;
}
} else {
V_40 [ 0 ] += 4 ;
V_40 [ 1 ] += 4 ;
}
V_40 [ 0 ] += 2 ;
V_40 [ 1 ] += 2 ;
V_34 -> V_47 [ 0 ] = F_12 ( 2 + V_40 [ 0 ] , 4 ) - 2 ;
V_34 -> V_47 [ 1 ] = F_12 ( 2 + V_40 [ 1 ] , 4 ) - 2 ;
if ( V_38 & V_42 )
V_34 -> V_47 [ 2 ] =
F_12 ( 2 + V_40 [ 2 ] , 4 ) - 2 ;
}
static void F_13 ( struct V_33 * V_34 ,
enum V_37 V_38 , T_2 V_5 ,
T_2 V_48 , T_2 V_49 ,
T_2 V_50 , T_2 V_51 )
{
unsigned char V_40 [ 3 ] = { 0 , 0 , 0 } ;
int V_13 ;
if ( ( V_38 & V_52 ) && ( V_5 & V_48 ) ) {
if ( V_5 & V_49 ) {
V_40 [ 0 ] += 4 ;
V_40 [ 1 ] += 4 ;
} else {
V_40 [ 0 ] += 8 ;
V_40 [ 1 ] += 4 ;
}
}
if ( ( V_38 & V_53 ) && ( V_5 & V_50 ) ) {
if ( V_5 & V_51 ) {
V_40 [ 0 ] += 4 ;
V_40 [ 1 ] += 4 ;
} else {
V_40 [ 0 ] += 8 ;
V_40 [ 1 ] += 4 ;
}
}
for ( V_13 = 0 ; V_13 < 3 ; ++ V_13 ) {
if ( V_40 [ V_13 ] > 0 )
V_40 [ V_13 ] = F_12 ( V_40 [ V_13 ] , 4 ) ;
V_34 -> V_54 [ V_13 ] = V_40 [ V_13 ] ;
}
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 V_4 ;
T_2 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_24 , & V_4 ,
sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = F_3 ( V_4 ) ;
F_11 ( & V_2 -> V_55 , V_43 ,
V_2 -> V_56 -> V_38 , V_2 -> V_56 -> V_57 ) ;
F_13 ( & V_2 -> V_55 ,
V_2 -> V_56 -> V_38 , V_5 ,
V_58 , V_25 ,
V_59 , V_28 ) ;
F_11 ( & V_2 -> V_60 , V_61 ,
V_2 -> V_56 -> V_38 , V_2 -> V_56 -> V_62 ) ;
F_13 ( & V_2 -> V_60 ,
V_2 -> V_56 -> V_38 , V_5 ,
V_63 , V_64 ,
V_65 , V_66 ) ;
V_2 -> V_55 . V_67 = 8 ;
V_2 -> V_55 . V_68 = 7 ;
V_2 -> V_55 . V_69 = 10 ;
V_2 -> V_60 . V_67 = 8 ;
V_2 -> V_60 . V_68 = 7 ;
V_2 -> V_60 . V_69 = 10 ;
return 0 ;
}
