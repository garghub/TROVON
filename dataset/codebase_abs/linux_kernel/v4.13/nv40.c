static enum V_1
V_1 ( struct V_2 * V_3 )
{
switch ( V_3 -> V_4 . V_5 -> V_6 ) {
case 0x43 :
case 0x44 :
case 0x4a :
case 0x47 :
return V_7 ;
case 0x46 :
case 0x49 :
case 0x4b :
case 0x4e :
case 0x4c :
case 0x67 :
case 0x68 :
case 0x63 :
return V_8 ;
default:
return V_9 ;
}
}
static int
F_1 ( struct V_2 * V_3 )
{
struct V_10 * V_5 = V_3 -> V_4 . V_5 ;
enum V_1 V_11 = V_1 ( V_3 ) ;
if ( V_11 == V_8 ) {
F_2 ( V_5 , 0x15b8 , 0x80000000 , 0 ) ;
F_3 ( V_5 , 0x15b0 , 0x80003fff ) ;
F_4 ( 20 ) ;
return F_5 ( V_5 , 0x15b4 ) & 0x3fff ;
} else if ( V_11 == V_7 ) {
F_3 ( V_5 , 0x15b0 , 0xff ) ;
F_4 ( 20 ) ;
return F_5 ( V_5 , 0x15b4 ) & 0xff ;
} else
return - V_12 ;
}
static int
F_6 ( struct V_2 * V_3 )
{
struct V_10 * V_5 = V_3 -> V_4 . V_5 ;
struct V_13 * V_14 = & V_3 -> V_15 ;
enum V_1 V_11 = V_1 ( V_3 ) ;
int V_16 ;
if ( V_11 == V_8 ) {
F_3 ( V_5 , 0x15b0 , 0x80003fff ) ;
V_16 = F_5 ( V_5 , 0x15b4 ) & 0x3fff ;
} else if ( V_11 == V_7 ) {
F_3 ( V_5 , 0x15b0 , 0xff ) ;
V_16 = F_5 ( V_5 , 0x15b4 ) & 0xff ;
} else
return - V_12 ;
if ( ! V_14 -> V_17 || ! V_14 -> V_18 ||
! V_14 -> V_19 || ! V_14 -> V_20 )
return - V_12 ;
V_16 = V_16 * V_14 -> V_18 / V_14 -> V_17 ;
V_16 = V_16 + V_14 -> V_19 / V_14 -> V_20 ;
V_16 = V_16 + V_14 -> V_21 - 8 ;
if ( V_16 < 0 )
V_16 = 0 ;
return V_16 ;
}
static int
F_7 ( struct V_2 * V_3 , int line , bool V_22 )
{
struct V_23 * V_4 = & V_3 -> V_4 ;
struct V_10 * V_5 = V_4 -> V_5 ;
T_1 V_24 = V_22 ? 0x80000000 : 0x00000000 ;
if ( line == 2 ) F_2 ( V_5 , 0x0010f0 , 0x80000000 , V_24 ) ;
else if ( line == 9 ) F_2 ( V_5 , 0x0015f4 , 0x80000000 , V_24 ) ;
else {
F_8 ( V_4 , L_1 , line ) ;
return - V_12 ;
}
return 0 ;
}
static int
F_9 ( struct V_2 * V_3 , int line , T_1 * V_25 , T_1 * V_26 )
{
struct V_23 * V_4 = & V_3 -> V_4 ;
struct V_10 * V_5 = V_4 -> V_5 ;
if ( line == 2 ) {
T_1 V_27 = F_5 ( V_5 , 0x0010f0 ) ;
if ( V_27 & 0x80000000 ) {
* V_26 = ( V_27 & 0x7fff0000 ) >> 16 ;
* V_25 = ( V_27 & 0x00007fff ) ;
return 0 ;
}
} else
if ( line == 9 ) {
T_1 V_27 = F_5 ( V_5 , 0x0015f4 ) ;
if ( V_27 & 0x80000000 ) {
* V_25 = F_5 ( V_5 , 0x0015f8 ) ;
* V_26 = ( V_27 & 0x7fffffff ) ;
return 0 ;
}
} else {
F_8 ( V_4 , L_1 , line ) ;
return - V_12 ;
}
return - V_28 ;
}
static int
F_10 ( struct V_2 * V_3 , int line , T_1 V_25 , T_1 V_26 )
{
struct V_23 * V_4 = & V_3 -> V_4 ;
struct V_10 * V_5 = V_4 -> V_5 ;
if ( line == 2 ) {
F_2 ( V_5 , 0x0010f0 , 0x7fff7fff , ( V_26 << 16 ) | V_25 ) ;
} else
if ( line == 9 ) {
F_3 ( V_5 , 0x0015f8 , V_25 ) ;
F_2 ( V_5 , 0x0015f4 , 0x7fffffff , V_26 ) ;
} else {
F_8 ( V_4 , L_1 , line ) ;
return - V_12 ;
}
return 0 ;
}
void
F_11 ( struct V_2 * V_3 )
{
struct V_23 * V_4 = & V_3 -> V_4 ;
struct V_10 * V_5 = V_4 -> V_5 ;
T_2 V_29 = F_5 ( V_5 , 0x1100 ) ;
F_3 ( V_5 , 0x1100 , 0x70000 ) ;
F_8 ( V_4 , L_2 , V_29 ) ;
}
static void
F_12 ( struct V_2 * V_3 )
{
F_1 ( V_3 ) ;
}
int
F_13 ( struct V_10 * V_5 , int V_30 ,
struct V_2 * * V_31 )
{
return F_14 ( & V_32 , V_5 , V_30 , V_31 ) ;
}
