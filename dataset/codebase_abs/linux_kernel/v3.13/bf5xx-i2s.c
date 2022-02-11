static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 = 0 ;
switch ( V_3 & V_10 ) {
case V_11 :
V_7 -> V_12 |= V_13 | V_14 ;
V_7 -> V_15 |= V_16 | V_17 ;
V_7 -> V_18 |= V_19 ;
V_7 -> V_20 |= V_21 ;
break;
case V_22 :
V_7 -> V_12 |= V_13 ;
V_7 -> V_15 |= V_16 ;
break;
case V_23 :
V_9 = - V_24 ;
break;
default:
F_3 ( V_2 -> V_25 , L_1 ,
V_26 ) ;
V_9 = - V_24 ;
break;
}
switch ( V_3 & V_27 ) {
case V_28 :
break;
case V_29 :
case V_30 :
case V_31 :
V_9 = - V_24 ;
break;
default:
F_3 ( V_2 -> V_25 , L_2 ,
V_26 ) ;
V_9 = - V_24 ;
break;
}
return V_9 ;
}
static int F_4 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_1 * V_36 )
{
struct V_4 * V_5 = F_2 ( V_36 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 = 0 ;
V_7 -> V_18 &= ~ 0x1f ;
V_7 -> V_20 &= ~ 0x1f ;
switch ( F_5 ( V_35 ) ) {
case V_37 :
V_7 -> V_18 |= 7 ;
V_7 -> V_20 |= 7 ;
V_5 -> V_38 = 1 ;
break;
case V_39 :
V_7 -> V_18 |= 15 ;
V_7 -> V_20 |= 15 ;
V_5 -> V_38 = 2 ;
break;
case V_40 :
V_7 -> V_18 |= 23 ;
V_7 -> V_20 |= 23 ;
V_5 -> V_38 = 3 ;
break;
case V_41 :
V_7 -> V_18 |= 31 ;
V_7 -> V_20 |= 31 ;
V_5 -> V_38 = 4 ;
break;
}
if ( ! V_7 -> V_42 ) {
V_7 -> V_42 = 1 ;
V_9 = F_6 ( V_5 , V_7 -> V_15 ,
V_7 -> V_20 , 0 , 0 ) ;
if ( V_9 ) {
F_3 ( V_36 -> V_25 , L_3 ) ;
return - V_43 ;
}
V_9 = F_7 ( V_5 , V_7 -> V_12 ,
V_7 -> V_18 , 0 , 0 ) ;
if ( V_9 ) {
F_3 ( V_36 -> V_25 , L_3 ) ;
return - V_43 ;
}
}
return 0 ;
}
static void F_8 ( struct V_32 * V_33 ,
struct V_1 * V_36 )
{
struct V_4 * V_5 = F_2 ( V_36 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_9 ( V_36 -> V_25 , L_4 , V_26 ) ;
if ( ! V_36 -> V_44 )
V_7 -> V_42 = 0 ;
}
static int F_10 ( struct V_1 * V_36 ,
unsigned int V_45 , unsigned int * V_46 ,
unsigned int V_47 , unsigned int * V_48 )
{
struct V_4 * V_5 = F_2 ( V_36 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned int V_49 = 0 , V_50 = 0 ;
unsigned int V_51 ;
int V_52 ;
if ( ( V_45 > V_53 ) ||
( V_47 > V_53 ) )
return - V_24 ;
for ( V_52 = 0 ; V_52 < V_45 ; V_52 ++ ) {
V_51 = V_46 [ V_52 ] ;
if ( ( V_51 < V_53 ) &&
( ! ( V_49 & ( 1 << V_51 ) ) ) ) {
V_7 -> V_54 . V_55 [ V_52 ] = V_51 ;
V_49 |= 1 << V_51 ;
} else
return - V_24 ;
}
for ( V_52 = 0 ; V_52 < V_47 ; V_52 ++ ) {
V_51 = V_48 [ V_52 ] ;
if ( ( V_51 < V_53 ) &&
( ! ( V_50 & ( 1 << V_51 ) ) ) ) {
V_7 -> V_56 . V_55 [ V_52 ] = V_51 ;
V_50 |= 1 << V_51 ;
} else
return - V_24 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_36 , unsigned int V_57 ,
unsigned int V_58 , int V_59 , int V_60 )
{
struct V_4 * V_5 = F_2 ( V_36 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_59 % 8 != 0 || V_59 > 8 )
return - V_24 ;
if ( V_60 != 32 )
return - V_24 ;
V_7 -> V_59 = V_59 ;
V_7 -> V_57 = V_57 ;
V_7 -> V_58 = V_58 ;
V_7 -> V_54 . V_61 = V_59 != 0 ;
V_7 -> V_56 . V_61 = V_59 != 0 ;
return F_12 ( V_5 , V_59 , V_57 , V_58 , 0 ) ;
}
static int F_13 ( struct V_1 * V_36 )
{
struct V_4 * V_5 = F_2 ( V_36 ) ;
F_9 ( V_36 -> V_25 , L_5 , V_26 , V_36 -> V_62 ) ;
if ( V_36 -> V_63 )
F_14 ( V_5 ) ;
if ( V_36 -> V_64 )
F_15 ( V_5 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_36 )
{
struct V_4 * V_5 = F_2 ( V_36 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
F_9 ( V_36 -> V_25 , L_5 , V_26 , V_36 -> V_62 ) ;
V_9 = F_6 ( V_5 , V_7 -> V_15 ,
V_7 -> V_20 , 0 , 0 ) ;
if ( V_9 ) {
F_3 ( V_36 -> V_25 , L_3 ) ;
return - V_43 ;
}
V_9 = F_7 ( V_5 , V_7 -> V_12 ,
V_7 -> V_18 , 0 , 0 ) ;
if ( V_9 ) {
F_3 ( V_36 -> V_25 , L_3 ) ;
return - V_43 ;
}
return F_12 ( V_5 , V_7 -> V_59 ,
V_7 -> V_57 , V_7 -> V_58 , 0 ) ;
}
static int F_17 ( struct V_1 * V_36 )
{
struct V_4 * V_5 = F_2 ( V_36 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned int V_52 ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
V_7 -> V_54 . V_55 [ V_52 ] = V_52 ;
V_7 -> V_56 . V_55 [ V_52 ] = V_52 ;
}
V_36 -> V_65 = & V_7 -> V_54 ;
V_36 -> V_66 = & V_7 -> V_56 ;
return 0 ;
}
static int F_18 ( struct V_67 * V_68 )
{
struct V_4 * V_5 ;
int V_9 ;
V_5 = F_19 ( V_68 , 4 , 8 * sizeof( V_69 ) ,
sizeof( struct V_6 ) ) ;
if ( ! V_5 )
return - V_70 ;
V_9 = F_20 ( & V_68 -> V_25 , & V_71 ,
& V_72 , 1 ) ;
if ( V_9 ) {
F_3 ( & V_68 -> V_25 , L_6 , V_9 ) ;
F_21 ( V_5 ) ;
return V_9 ;
}
return 0 ;
}
static int F_22 ( struct V_67 * V_68 )
{
struct V_4 * V_5 = F_23 ( V_68 ) ;
F_9 ( & V_68 -> V_25 , L_4 , V_26 ) ;
F_24 ( & V_68 -> V_25 ) ;
F_21 ( V_5 ) ;
return 0 ;
}
