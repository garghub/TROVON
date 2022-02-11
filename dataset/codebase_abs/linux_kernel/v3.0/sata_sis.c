static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
unsigned int V_10 = V_11 + ( 4 * V_3 ) ;
T_1 V_12 ;
if ( V_5 -> V_13 ) {
switch ( V_7 -> V_14 ) {
case 0x0180 :
case 0x0181 :
F_3 ( V_7 , V_15 , & V_12 ) ;
if ( ( V_12 & V_16 ) == 0 )
V_10 += V_17 ;
break;
case 0x0182 :
case 0x0183 :
case 0x1182 :
V_10 += V_18 ;
break;
}
}
if ( V_2 -> V_19 )
V_10 += 0x10 ;
return V_10 ;
}
static T_2 F_4 ( struct V_1 * V_2 ,
unsigned int V_3 , T_2 * V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_5 -> V_8 -> V_9 ) ;
unsigned int V_21 = F_1 ( V_2 , V_3 ) ;
if ( V_3 == V_22 )
return - V_23 ;
F_5 ( V_7 , V_21 , V_20 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_3 , T_2 V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_5 -> V_8 -> V_9 ) ;
unsigned int V_21 = F_1 ( V_2 , V_3 ) ;
F_7 ( V_7 , V_21 , V_20 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 , T_2 * V_20 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
void T_3 * V_24 = V_5 -> V_25 . V_26 + V_2 -> V_19 * 0x10 ;
if ( V_3 > V_27 )
return - V_23 ;
if ( V_5 -> V_28 & V_29 )
return F_4 ( V_2 , V_3 , V_20 ) ;
* V_20 = F_9 ( V_24 + V_3 * 4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 , T_2 V_20 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
void T_3 * V_24 = V_5 -> V_25 . V_26 + V_2 -> V_19 * 0x10 ;
if ( V_3 > V_27 )
return - V_23 ;
if ( V_5 -> V_28 & V_29 )
return F_6 ( V_2 , V_3 , V_20 ) ;
F_11 ( V_20 , V_24 + ( V_3 * 4 ) ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , const struct V_30 * V_31 )
{
static int V_32 ;
struct V_33 V_34 = V_35 ;
const struct V_33 * V_36 [] = { & V_34 , & V_34 } ;
struct V_37 * V_8 ;
T_2 V_38 , V_20 ;
T_1 V_12 ;
T_1 V_39 = 0x20 ;
int V_40 , V_41 ;
if ( ! V_32 ++ )
F_13 ( V_42 , & V_7 -> V_9 , L_1 V_43 L_2 ) ;
V_41 = F_14 ( V_7 ) ;
if ( V_41 )
return V_41 ;
F_5 ( V_7 , V_44 , & V_38 ) ;
if ( ( V_38 & V_45 ) == 0 )
V_34 . V_28 |= V_29 ;
if ( ( ! ( V_34 . V_28 & V_29 ) ) &&
( ( F_15 ( V_7 , V_46 ) == 0 ) ||
( F_16 ( V_7 , V_46 ) < 128 ) ) ) {
V_38 &= ~ V_45 ;
F_7 ( V_7 , V_44 , V_38 ) ;
V_34 . V_28 |= V_29 ;
}
F_3 ( V_7 , V_15 , & V_12 ) ;
switch ( V_31 -> V_14 ) {
case 0x0180 :
case 0x0181 :
switch ( V_12 & 0x30 ) {
case 0x10 :
V_36 [ 1 ] = & V_47 ;
break;
case 0x30 :
V_36 [ 0 ] = & V_47 ;
break;
}
if ( ( V_12 & V_16 ) == 0 ) {
F_13 ( V_42 , & V_7 -> V_9 ,
L_3 ) ;
V_39 = 64 ;
} else {
F_13 ( V_42 , & V_7 -> V_9 ,
L_4 ) ;
V_39 = 0 ;
V_34 . V_28 |= V_48 ;
}
break;
case 0x0182 :
case 0x0183 :
F_5 ( V_7 , 0x6C , & V_20 ) ;
if ( V_20 & ( 1L << 31 ) ) {
F_13 ( V_42 , & V_7 -> V_9 ,
L_5 ) ;
V_34 . V_28 |= V_48 ;
} else {
F_13 ( V_42 , & V_7 -> V_9 ,
L_6 ) ;
}
break;
case 0x1182 :
F_13 ( V_42 , & V_7 -> V_9 ,
L_7 ) ;
V_34 . V_28 |= V_48 ;
break;
case 0x1183 :
F_13 ( V_42 , & V_7 -> V_9 ,
L_8 ) ;
V_36 [ 0 ] = & V_47 ;
V_36 [ 1 ] = & V_47 ;
break;
}
V_41 = F_17 ( V_7 , V_36 , & V_8 ) ;
if ( V_41 )
return V_41 ;
for ( V_40 = 0 ; V_40 < 2 ; V_40 ++ ) {
struct V_4 * V_5 = V_8 -> V_49 [ V_40 ] ;
if ( V_5 -> V_28 & V_50 &&
V_5 -> V_28 & V_48 ) {
V_41 = F_18 ( V_5 ) ;
if ( V_41 )
return V_41 ;
}
}
if ( ! ( V_34 . V_28 & V_29 ) ) {
void T_3 * V_51 ;
V_41 = F_19 ( V_7 , 1 << V_46 , V_52 ) ;
if ( V_41 )
return V_41 ;
V_51 = V_8 -> V_53 [ V_46 ] ;
V_8 -> V_49 [ 0 ] -> V_25 . V_26 = V_51 ;
V_8 -> V_49 [ 1 ] -> V_25 . V_26 = V_51 + V_39 ;
}
F_20 ( V_7 ) ;
F_21 ( V_7 , 1 ) ;
return F_22 ( V_8 , V_7 -> V_54 , V_55 ,
V_56 , & V_57 ) ;
}
static int T_4 F_23 ( void )
{
return F_24 ( & V_58 ) ;
}
static void T_5 F_25 ( void )
{
F_26 ( & V_58 ) ;
}
