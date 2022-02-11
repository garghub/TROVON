static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_3 ( V_7 , 0x00 ) ;
if ( V_8 < 0 )
return V_8 ;
return sprintf ( V_5 , L_1 , 1 << ( 2 * ( V_8 & 3 ) ) ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 , V_8 ;
unsigned long int V_10 ;
int V_11 ;
F_5 ( V_2 ) ;
F_6 ( 100 ) ;
F_7 ( & V_12 ) ;
V_11 = F_3 ( V_7 , 0x02 ) ;
if ( V_11 < 0 ) {
F_8 ( V_2 ) ;
F_9 ( & V_12 ) ;
return V_11 ;
}
V_9 = F_3 ( V_7 , 0x01 ) ;
F_9 ( & V_12 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 ) ;
return V_9 ;
}
V_9 |= V_11 << 8 ;
V_8 = F_3 ( V_7 , 0x00 ) ;
F_8 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_10 = ( ( ( ( 1 << ( 2 * ( V_8 & 3 ) ) ) ) * 1000 ) * V_9 ) / 65536 ;
return sprintf ( V_5 , L_2 , V_10 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 ;
unsigned long V_8 ;
V_9 = F_11 ( V_5 , 10 , & V_8 ) ;
if ( V_9 )
return V_9 ;
if ( V_8 < 1 || V_8 > 64000 )
return - V_14 ;
if ( V_8 <= 1000 )
V_8 = 1 ;
else if ( V_8 <= 4000 )
V_8 = 2 ;
else if ( V_8 <= 16000 )
V_8 = 3 ;
else
V_8 = 4 ;
V_9 = F_3 ( V_7 , 0x00 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 &= 0xFC ;
V_9 |= V_8 - 1 ;
V_9 = F_12 ( V_7 , 0x00 , V_9 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_13 ;
}
static void F_13 ( struct V_6 * V_7 , int V_15 )
{
int V_9 ;
V_9 = F_3 ( V_7 , 0x00 ) ;
if ( V_9 < 0 )
return;
if ( V_15 )
V_9 |= 0x80 ;
else
V_9 &= 0x7F ;
F_12 ( V_7 , 0x00 , V_9 ) ;
}
static int F_14 ( struct V_6 * V_7 )
{
int V_16 ;
V_16 = F_12 ( V_7 , 0x00 , 0xc0 ) ;
if ( V_16 < 0 ) {
F_15 ( & V_7 -> V_2 , L_3 ) ;
return V_16 ;
}
return 0 ;
}
static int F_16 ( struct V_6 * V_7 ,
const struct V_17 * V_18 )
{
int V_19 ;
V_19 = F_14 ( V_7 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_17 ( & V_7 -> V_2 . V_20 , & V_21 ) ;
if ( V_19 ) {
F_15 ( & V_7 -> V_2 , L_4 ) ;
return V_19 ;
}
F_18 ( & V_7 -> V_2 , L_5 , V_7 -> V_22 ) ;
F_13 ( V_7 , 0 ) ;
F_19 ( & V_7 -> V_2 ) ;
return V_19 ;
}
static int F_20 ( struct V_6 * V_7 )
{
F_21 ( & V_7 -> V_2 . V_20 , & V_21 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_13 ( V_7 , 0 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_13 ( V_7 , 1 ) ;
return 0 ;
}
