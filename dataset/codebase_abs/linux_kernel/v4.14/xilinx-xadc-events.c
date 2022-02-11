static const struct V_1 * F_1 (
struct V_2 * V_3 , unsigned int V_4 )
{
switch ( V_4 ) {
case V_5 :
case V_6 :
return & V_3 -> V_7 [ 0 ] ;
case V_8 :
case V_9 :
return & V_3 -> V_7 [ V_4 ] ;
default:
return & V_3 -> V_7 [ V_4 - 1 ] ;
}
}
static void F_2 ( struct V_2 * V_3 , unsigned int V_4 )
{
const struct V_1 * V_10 ;
if ( V_4 == 0 )
return;
V_10 = F_1 ( V_3 , V_4 ) ;
if ( V_10 -> type == V_11 ) {
F_3 ( V_3 ,
F_4 ( V_10 -> type , V_10 -> V_12 ,
V_13 , V_14 ) ,
F_5 ( V_3 ) ) ;
} else {
F_3 ( V_3 ,
F_4 ( V_10 -> type , V_10 -> V_12 ,
V_13 , V_15 ) ,
F_5 ( V_3 ) ) ;
}
}
void F_6 ( struct V_2 * V_3 , unsigned long V_16 )
{
unsigned int V_17 ;
F_7 (i, &events, 8 )
F_2 ( V_3 , V_17 ) ;
}
static unsigned int F_8 ( const struct V_1 * V_10 ,
enum V_18 V_19 )
{
unsigned int V_20 ;
if ( V_10 -> type == V_11 ) {
V_20 = V_5 ;
} else {
if ( V_10 -> V_12 < 2 )
V_20 = V_10 -> V_12 + 1 ;
else
V_20 = V_10 -> V_12 + 6 ;
}
if ( V_19 == V_21 )
V_20 += 4 ;
return V_20 ;
}
static unsigned int F_9 ( const struct V_1 * V_10 )
{
if ( V_10 -> type == V_11 )
return V_22 ;
switch ( V_10 -> V_12 ) {
case 0 :
return V_23 ;
case 1 :
return V_24 ;
case 2 :
return V_25 ;
case 3 :
return V_26 ;
case 4 :
return V_27 ;
case 5 :
return V_28 ;
default:
return 0 ;
}
}
int F_10 ( struct V_2 * V_3 ,
const struct V_1 * V_10 , enum V_29 type ,
enum V_18 V_19 )
{
struct V_30 * V_30 = F_11 ( V_3 ) ;
return ( bool ) ( V_30 -> V_31 & F_9 ( V_10 ) ) ;
}
int F_12 ( struct V_2 * V_3 ,
const struct V_1 * V_10 , enum V_29 type ,
enum V_18 V_19 , int V_32 )
{
unsigned int V_33 = F_9 ( V_10 ) ;
struct V_30 * V_30 = F_11 ( V_3 ) ;
T_1 V_34 , V_35 ;
int V_36 ;
F_13 ( & V_30 -> V_37 ) ;
if ( V_32 )
V_30 -> V_31 |= V_33 ;
else
V_30 -> V_31 &= ~ V_33 ;
V_30 -> V_38 -> V_39 ( V_30 , V_30 -> V_31 ) ;
V_36 = F_14 ( V_30 , V_40 , & V_34 ) ;
if ( V_36 )
goto V_41;
V_35 = V_34 ;
V_34 |= V_42 ;
V_34 &= ~ ( ( V_30 -> V_31 & 0xf0 ) << 4 ) ;
V_34 &= ~ ( ( V_30 -> V_31 & 0x08 ) >> 3 ) ;
V_34 &= ~ ( ( V_30 -> V_31 & 0x07 ) << 1 ) ;
if ( V_35 != V_34 )
V_36 = F_15 ( V_30 , V_40 , V_34 ) ;
V_41:
F_16 ( & V_30 -> V_37 ) ;
return V_36 ;
}
int F_17 ( struct V_2 * V_3 ,
const struct V_1 * V_10 , enum V_29 type ,
enum V_18 V_19 , enum V_43 V_44 ,
int * V_45 , int * V_46 )
{
unsigned int V_20 = F_8 ( V_10 , V_19 ) ;
struct V_30 * V_30 = F_11 ( V_3 ) ;
switch ( V_44 ) {
case V_47 :
* V_45 = V_30 -> V_48 [ V_20 ] ;
break;
case V_49 :
* V_45 = V_30 -> V_50 ;
break;
default:
return - V_51 ;
}
* V_45 >>= V_52 ;
return V_53 ;
}
int F_18 ( struct V_2 * V_3 ,
const struct V_1 * V_10 , enum V_29 type ,
enum V_18 V_19 , enum V_43 V_44 ,
int V_45 , int V_46 )
{
unsigned int V_20 = F_8 ( V_10 , V_19 ) ;
struct V_30 * V_30 = F_11 ( V_3 ) ;
int V_36 = 0 ;
V_45 <<= V_52 ;
if ( V_45 < 0 || V_45 > 0xffff )
return - V_51 ;
F_13 ( & V_30 -> V_37 ) ;
switch ( V_44 ) {
case V_47 :
V_30 -> V_48 [ V_20 ] = V_45 ;
break;
case V_49 :
V_30 -> V_50 = V_45 ;
break;
default:
F_16 ( & V_30 -> V_37 ) ;
return - V_51 ;
}
if ( V_10 -> type == V_11 ) {
V_45 |= 0x3 ;
if ( V_30 -> V_48 [ V_20 ] < V_30 -> V_50 )
V_30 -> V_48 [ V_20 + 4 ] = 0 ;
else
V_30 -> V_48 [ V_20 + 4 ] = V_30 -> V_48 [ V_20 ] -
V_30 -> V_50 ;
V_36 = F_15 ( V_30 , F_19 ( V_20 + 4 ) ,
V_30 -> V_48 [ V_20 + 4 ] ) ;
if ( V_36 )
goto V_54;
}
if ( V_44 == V_47 )
V_36 = F_15 ( V_30 , F_19 ( V_20 ) , V_45 ) ;
V_54:
F_16 ( & V_30 -> V_37 ) ;
return V_36 ;
}
