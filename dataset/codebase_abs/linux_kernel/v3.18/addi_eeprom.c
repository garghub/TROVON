static void F_1 ( unsigned long V_1 , unsigned int V_2 )
{
F_2 ( V_2 & ~ V_3 , V_1 ) ;
F_3 ( 100 ) ;
F_2 ( V_2 | V_3 , V_1 ) ;
F_3 ( 100 ) ;
}
static unsigned int F_4 ( unsigned long V_1 ,
unsigned int V_4 ,
unsigned char V_5 )
{
unsigned int V_2 = V_6 ;
int V_7 ;
F_2 ( V_2 , V_1 ) ;
F_3 ( 100 ) ;
for ( V_7 = ( V_5 - 1 ) ; V_7 >= 0 ; V_7 -- ) {
if ( V_4 & ( 1 << V_7 ) )
V_2 |= V_8 ;
else
V_2 &= ~ V_8 ;
F_2 ( V_2 , V_1 ) ;
F_3 ( 100 ) ;
F_1 ( V_1 , V_2 ) ;
}
return V_2 ;
}
static unsigned short F_5 ( unsigned long V_1 ,
unsigned short V_9 )
{
unsigned short V_2 = 0 ;
unsigned int V_4 ;
unsigned int V_10 ;
int V_7 ;
V_4 = V_11 | ( V_9 / 2 ) ;
V_4 = F_4 ( V_1 , V_4 , V_12 ) ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ ) {
F_1 ( V_1 , V_4 ) ;
V_10 = F_6 ( V_1 ) ;
F_3 ( 100 ) ;
V_2 <<= 1 ;
if ( V_10 & V_13 )
V_2 |= 0x1 ;
}
F_2 ( 0 , V_1 ) ;
F_3 ( 100 ) ;
return V_2 ;
}
static void F_7 ( unsigned long V_1 )
{
unsigned char V_2 ;
do {
V_2 = F_8 ( V_1 + V_14 ) ;
} while ( V_2 & 0x80 );
}
static unsigned short F_9 ( unsigned long V_1 ,
unsigned short V_9 )
{
unsigned short V_2 = 0 ;
unsigned char V_10 ;
unsigned char V_7 ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
F_10 ( V_15 , V_1 + V_14 ) ;
F_7 ( V_1 ) ;
F_10 ( ( V_9 + V_7 ) & 0xff , V_1 + V_16 ) ;
F_7 ( V_1 ) ;
F_10 ( V_17 , V_1 + V_14 ) ;
F_7 ( V_1 ) ;
F_10 ( ( ( V_9 + V_7 ) >> 8 ) & 0xff ,
V_1 + V_16 ) ;
F_7 ( V_1 ) ;
F_10 ( V_18 , V_1 + V_14 ) ;
F_7 ( V_1 ) ;
V_10 = F_8 ( V_1 + V_16 ) ;
F_7 ( V_1 ) ;
if ( V_7 == 0 )
V_2 |= V_10 ;
else
V_2 |= ( V_10 << 8 ) ;
}
return V_2 ;
}
static unsigned short F_11 ( unsigned long V_1 ,
char * type ,
unsigned short V_9 )
{
unsigned short V_2 = 0 ;
V_9 += V_19 ;
if ( ! strcmp ( type , L_1 ) || ! strcmp ( type , L_2 ) )
V_2 = F_9 ( V_1 , V_9 ) ;
if ( ! strcmp ( type , L_3 ) )
V_2 = F_5 ( V_1 , V_9 ) ;
return V_2 ;
}
static void F_12 ( struct V_20 * V_21 ,
unsigned long V_1 ,
unsigned short V_9 )
{
const struct V_22 * V_23 = V_21 -> V_24 ;
struct V_25 * V_26 = V_21 -> V_27 ;
char * type = V_23 -> V_28 ;
unsigned short V_10 ;
V_10 = F_11 ( V_1 , type , V_9 + 6 ) ;
V_26 -> V_29 . V_30 = V_10 ;
V_10 = F_11 ( V_1 , type , V_9 + 8 ) ;
V_10 = ( V_10 >> 7 ) & 0x01 ;
V_10 = F_11 ( V_1 , type , V_9 + 10 ) ;
}
static void F_13 ( struct V_20 * V_21 ,
unsigned long V_1 ,
unsigned short V_9 )
{
const struct V_22 * V_23 = V_21 -> V_24 ;
struct V_25 * V_26 = V_21 -> V_27 ;
char * type = V_23 -> V_28 ;
unsigned short V_10 ;
V_10 = F_11 ( V_1 , type , V_9 + 6 ) ;
V_26 -> V_29 . V_31 = V_10 ;
V_26 -> V_29 . V_32 = 0xffffffff >> ( 32 - V_10 ) ;
}
static void F_14 ( struct V_20 * V_21 ,
unsigned long V_1 ,
unsigned short V_9 )
{
struct V_25 * V_26 = V_21 -> V_27 ;
#if 0
const struct addi_board *this_board = dev->board_ptr;
char *type = this_board->pc_EepromChip;
unsigned short offset = 0;
unsigned short ntimers;
unsigned short tmp;
int i;
ntimers = addi_eeprom_readw(iobase, type, addr + 6);
for (i = 0; i < ntimers; i++) {
unsigned short size;
unsigned short res;
unsigned short mode;
unsigned short min_timing;
unsigned short timebase;
size = addi_eeprom_readw(iobase, type, addr + 8 + offset + 0);
tmp = addi_eeprom_readw(iobase, type, addr + 8 + offset + 2);
res = (tmp >> 10) & 0x3f;
mode = (tmp >> 4) & 0x3f;
tmp = addi_eeprom_readw(iobase, type, addr + 8 + offset + 4);
min_timing = (tmp >> 6) & 0x3ff;
Timebase = tmp & 0x3f;
offset += size;
}
#endif
V_26 -> V_29 . V_33 = 1 ;
}
static void F_15 ( struct V_20 * V_21 ,
unsigned long V_1 ,
unsigned short V_9 )
{
const struct V_22 * V_23 = V_21 -> V_24 ;
struct V_25 * V_26 = V_21 -> V_27 ;
char * type = V_23 -> V_28 ;
unsigned short V_10 ;
V_10 = F_11 ( V_1 , type , V_9 + 10 ) ;
V_26 -> V_29 . V_34 = ( V_10 >> 4 ) & 0x3ff ;
V_10 = F_11 ( V_1 , type , V_9 + 16 ) ;
V_10 = ( V_10 >> 8 ) & 0xff ;
V_26 -> V_29 . V_35 = 0xfff >> ( 16 - V_10 ) ;
}
static void F_16 ( struct V_20 * V_21 ,
unsigned long V_1 ,
unsigned short V_9 )
{
const struct V_22 * V_23 = V_21 -> V_24 ;
struct V_25 * V_26 = V_21 -> V_27 ;
char * type = V_23 -> V_28 ;
unsigned short V_36 ;
unsigned short V_10 ;
V_10 = F_11 ( V_1 , type , V_9 + 10 ) ;
V_26 -> V_29 . V_37 = ( V_10 >> 4 ) & 0x3ff ;
if ( ! strcmp ( V_23 -> V_38 , L_4 ) )
V_26 -> V_29 . V_37 *= 4 ;
V_10 = F_11 ( V_1 , type , V_9 + 16 ) ;
V_26 -> V_29 . V_39 = V_10 * 1000 ;
V_10 = F_11 ( V_1 , type , V_9 + 30 ) ;
V_26 -> V_29 . V_40 = V_10 * 1000 ;
V_10 = F_11 ( V_1 , type , V_9 + 20 ) ;
V_10 = F_11 ( V_1 , type , V_9 + 72 ) & 0xff ;
if ( V_10 ) {
V_36 = 74 + ( 2 * V_10 ) + ( 10 * ( 1 + ( V_10 / 16 ) ) ) ;
} else {
V_36 = 74 ;
}
V_10 = F_11 ( V_1 , type , V_9 + V_36 + 2 ) & 0x1f ;
V_26 -> V_29 . V_41 = 0xffff >> ( 16 - V_10 ) ;
}
static void F_17 ( struct V_20 * V_21 ,
unsigned long V_1 )
{
const struct V_22 * V_23 = V_21 -> V_24 ;
char * type = V_23 -> V_28 ;
unsigned short V_42 ;
unsigned char V_43 ;
int V_7 ;
V_42 = F_11 ( V_1 , type , 8 ) ;
V_43 = F_11 ( V_1 , type , 10 ) & 0xff ;
for ( V_7 = 0 ; V_7 < V_43 ; V_7 ++ ) {
unsigned short V_36 = V_7 * 4 ;
unsigned short V_9 ;
unsigned char V_44 ;
V_44 = F_11 ( V_1 , type , 12 + V_36 ) & 0x3f ;
V_9 = F_11 ( V_1 , type , 14 + V_36 ) ;
switch ( V_44 ) {
case V_45 :
F_12 ( V_21 , V_1 , V_9 ) ;
break;
case V_46 :
F_13 ( V_21 , V_1 , V_9 ) ;
break;
case V_47 :
F_16 ( V_21 , V_1 , V_9 ) ;
break;
case V_48 :
F_15 ( V_21 , V_1 , V_9 ) ;
break;
case V_49 :
case V_50 :
case V_51 :
F_14 ( V_21 , V_1 , V_9 ) ;
break;
}
}
}
