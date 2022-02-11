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
struct V_32 V_33 = V_34 ;
const struct V_32 * V_35 [] = { & V_33 , & V_33 } ;
struct V_36 * V_8 ;
T_2 V_37 , V_20 ;
T_1 V_12 ;
T_1 V_38 = 0x20 ;
int V_39 , V_40 ;
F_13 ( & V_7 -> V_9 , V_41 ) ;
V_40 = F_14 ( V_7 ) ;
if ( V_40 )
return V_40 ;
F_5 ( V_7 , V_42 , & V_37 ) ;
if ( ( V_37 & V_43 ) == 0 )
V_33 . V_28 |= V_29 ;
if ( ( ! ( V_33 . V_28 & V_29 ) ) &&
( ( F_15 ( V_7 , V_44 ) == 0 ) ||
( F_16 ( V_7 , V_44 ) < 128 ) ) ) {
V_37 &= ~ V_43 ;
F_7 ( V_7 , V_42 , V_37 ) ;
V_33 . V_28 |= V_29 ;
}
F_3 ( V_7 , V_15 , & V_12 ) ;
switch ( V_31 -> V_14 ) {
case 0x0180 :
case 0x0181 :
switch ( V_12 & 0x30 ) {
case 0x10 :
V_35 [ 1 ] = & V_45 ;
break;
case 0x30 :
V_35 [ 0 ] = & V_45 ;
break;
}
if ( ( V_12 & V_16 ) == 0 ) {
F_17 ( & V_7 -> V_9 ,
L_1 ) ;
V_38 = 64 ;
} else {
F_17 ( & V_7 -> V_9 ,
L_2 ) ;
V_38 = 0 ;
V_33 . V_28 |= V_46 ;
}
break;
case 0x0182 :
case 0x0183 :
F_5 ( V_7 , 0x6C , & V_20 ) ;
if ( V_20 & ( 1L << 31 ) ) {
F_17 ( & V_7 -> V_9 , L_3 ) ;
V_33 . V_28 |= V_46 ;
} else {
F_17 ( & V_7 -> V_9 , L_4 ) ;
}
break;
case 0x1182 :
F_17 ( & V_7 -> V_9 ,
L_5 ) ;
V_33 . V_28 |= V_46 ;
break;
case 0x1183 :
F_17 ( & V_7 -> V_9 ,
L_6 ) ;
V_35 [ 0 ] = & V_45 ;
V_35 [ 1 ] = & V_45 ;
break;
}
V_40 = F_18 ( V_7 , V_35 , & V_8 ) ;
if ( V_40 )
return V_40 ;
for ( V_39 = 0 ; V_39 < 2 ; V_39 ++ ) {
struct V_4 * V_5 = V_8 -> V_47 [ V_39 ] ;
if ( V_5 -> V_28 & V_48 &&
V_5 -> V_28 & V_46 ) {
V_40 = F_19 ( V_5 ) ;
if ( V_40 )
return V_40 ;
}
}
if ( ! ( V_33 . V_28 & V_29 ) ) {
void T_3 * V_49 ;
V_40 = F_20 ( V_7 , 1 << V_44 , V_50 ) ;
if ( V_40 )
return V_40 ;
V_49 = V_8 -> V_51 [ V_44 ] ;
V_8 -> V_47 [ 0 ] -> V_25 . V_26 = V_49 ;
V_8 -> V_47 [ 1 ] -> V_25 . V_26 = V_49 + V_38 ;
}
F_21 ( V_7 ) ;
F_22 ( V_7 , 1 ) ;
return F_23 ( V_8 , V_7 -> V_52 , V_53 ,
V_54 , & V_55 ) ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_56 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_56 ) ;
}
