static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_3 ( V_7 , 0x81 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & 1 )
return sprintf ( V_5 , L_1 ) ;
else
return sprintf ( V_5 , L_2 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 ;
int V_10 = 10 ;
do {
F_5 ( 30 ) ;
V_9 = F_3 ( V_7 , 0x86 ) ;
} while ( ! ( V_9 & 0x80 ) && V_10 -- );
if ( V_10 < 0 ) {
F_6 ( V_2 , L_3 ) ;
return - V_11 ;
}
return 0 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_7 ) ;
int V_14 ;
int V_15 ;
F_9 ( V_2 ) ;
F_10 ( & V_13 -> V_16 ) ;
F_11 ( V_7 , 0x40 ) ;
V_15 = F_3 ( V_7 , 0x81 ) ;
F_12 ( V_7 , 0x81 , V_15 | 0x08 ) ;
V_14 = F_4 ( V_2 ) ;
if ( V_14 < 0 )
goto V_17;
V_15 = F_3 ( V_7 , 0x8C ) ;
if ( V_15 < 0 ) {
V_14 = V_15 ;
goto V_17;
}
V_14 = F_3 ( V_7 , 0x8D ) ;
if ( V_14 < 0 )
goto V_17;
F_13 ( & V_13 -> V_16 ) ;
F_14 ( V_2 ) ;
V_15 = ( V_14 << 8 ) | V_15 ;
return sprintf ( V_5 , L_4 , V_15 ) ;
V_17:
F_13 ( & V_13 -> V_16 ) ;
F_14 ( V_2 ) ;
return V_14 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_7 ) ;
int V_14 ;
unsigned long V_8 ;
V_14 = F_16 ( V_5 , 10 , & V_8 ) ;
if ( V_14 )
return V_14 ;
if ( V_8 < 4096 )
V_8 = 1 ;
else if ( V_8 < 65536 )
V_8 = 2 ;
else
return - V_19 ;
F_9 ( V_2 ) ;
F_10 ( & V_13 -> V_16 ) ;
V_14 = F_3 ( V_7 , 0x81 ) ;
if ( V_14 < 0 )
goto V_20;
V_14 = V_14 & 0xFA ;
if ( V_8 == 1 )
V_14 = ( V_14 | 0x01 ) ;
else
V_14 = ( V_14 | 0x00 ) ;
V_14 = F_12 ( V_7 , 0x81 , V_14 ) ;
if ( V_14 >= 0 ) {
F_13 ( & V_13 -> V_16 ) ;
F_14 ( V_2 ) ;
return V_18 ;
}
V_20:
F_13 ( & V_13 -> V_16 ) ;
F_14 ( V_2 ) ;
return V_14 ;
}
static int F_17 ( struct V_6 * V_7 , bool V_21 )
{
int V_14 ;
struct V_12 * V_13 = F_8 ( V_7 ) ;
F_10 ( & V_13 -> V_16 ) ;
V_14 = F_3 ( V_7 , 0x80 ) ;
if ( V_14 < 0 )
goto V_20;
if ( V_21 )
V_14 = V_14 | 0x01 ;
else
V_14 = V_14 & 0xFE ;
V_14 = F_12 ( V_7 , 0x80 , V_14 ) ;
V_20:
F_13 ( & V_13 -> V_16 ) ;
return V_14 ;
}
static int F_18 ( struct V_6 * V_7 )
{
int V_14 ;
V_14 = F_12 ( V_7 , 0x80 , 0x01 ) ;
if ( V_14 < 0 ) {
F_19 ( & V_7 -> V_2 , L_5 ) ;
return V_14 ;
}
V_14 = F_12 ( V_7 , 0x81 , 0x08 ) ;
if ( V_14 < 0 )
F_19 ( & V_7 -> V_2 , L_6 ) ;
F_4 ( & V_7 -> V_2 ) ;
return V_14 ;
}
static int F_20 ( struct V_6 * V_7 ,
const struct V_22 * V_23 )
{
int V_24 ;
struct V_12 * V_13 ;
V_13 = F_21 ( sizeof( struct V_12 ) , V_25 ) ;
if ( V_13 == NULL ) {
F_19 ( & V_7 -> V_2 , L_7 ) ;
return - V_26 ;
}
F_22 ( V_7 , V_13 ) ;
V_24 = F_23 ( & V_7 -> V_2 . V_27 , & V_28 ) ;
if ( V_24 ) {
F_19 ( & V_7 -> V_2 , L_8 ) ;
goto V_29;
}
F_24 ( & V_7 -> V_2 , L_9 ) ;
F_18 ( V_7 ) ;
F_25 ( & V_13 -> V_16 ) ;
F_26 ( & V_7 -> V_2 ) ;
F_27 ( & V_7 -> V_2 ) ;
return V_24 ;
V_29:
F_28 ( V_13 ) ;
return V_24 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_8 ( V_7 ) ;
F_9 ( & V_7 -> V_2 ) ;
F_17 ( V_7 , false ) ;
F_30 ( & V_7 -> V_2 . V_27 , & V_28 ) ;
F_31 ( & V_7 -> V_2 ) ;
F_32 ( & V_7 -> V_2 ) ;
F_33 ( & V_7 -> V_2 ) ;
F_28 ( V_13 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_17 ( V_7 , false ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_17 ( V_7 , true ) ;
return 0 ;
}
