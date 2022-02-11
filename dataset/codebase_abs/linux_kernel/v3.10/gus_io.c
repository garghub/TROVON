void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
F_2 () ;
F_3 ( F_4 ( V_2 , V_4 ) ) ;
}
}
static inline void F_5 ( struct V_1 * V_2 , unsigned char V_5 )
{
unsigned char V_6 ;
F_6 ( V_5 | 0x80 , V_2 -> V_7 . V_8 ) ;
F_2 () ;
V_6 = F_3 ( V_2 -> V_7 . V_9 ) ;
F_2 () ;
F_6 ( V_5 , V_2 -> V_7 . V_8 ) ;
F_2 () ;
F_6 ( ( V_6 | 0x03 ) & ~ ( 0x80 | 0x20 ) , V_2 -> V_7 . V_9 ) ;
F_2 () ;
}
static inline void F_7 ( struct V_1 * V_2 ,
unsigned char V_5 ,
unsigned char V_10 )
{
F_6 ( V_5 , V_2 -> V_7 . V_8 ) ;
F_2 () ;
F_6 ( V_10 , V_2 -> V_7 . V_9 ) ;
F_2 () ;
}
static inline unsigned char F_8 ( struct V_1 * V_2 ,
unsigned char V_5 )
{
F_6 ( V_5 , V_2 -> V_7 . V_8 ) ;
F_2 () ;
return F_3 ( V_2 -> V_7 . V_9 ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
unsigned char V_5 , unsigned int V_10 )
{
F_6 ( V_5 , V_2 -> V_7 . V_8 ) ;
F_2 () ;
F_10 ( ( unsigned short ) V_10 , V_2 -> V_7 . V_11 ) ;
F_2 () ;
}
static inline unsigned short F_11 ( struct V_1 * V_2 ,
unsigned char V_5 )
{
F_6 ( V_5 , V_2 -> V_7 . V_8 ) ;
F_2 () ;
return F_12 ( V_2 -> V_7 . V_11 ) ;
}
static inline void F_13 ( struct V_1 * V_2 ,
unsigned char V_5 , unsigned char V_10 )
{
F_6 ( V_5 , V_2 -> V_7 . V_12 ) ;
F_3 ( V_2 -> V_7 . V_12 ) ;
F_3 ( V_2 -> V_7 . V_12 ) ;
F_6 ( V_10 , V_2 -> V_7 . V_13 ) ;
F_3 ( V_2 -> V_7 . V_12 ) ;
F_3 ( V_2 -> V_7 . V_12 ) ;
}
static inline void F_14 ( struct V_1 * V_2 , unsigned char V_5 ,
unsigned int V_14 , int V_15 )
{
if ( V_2 -> V_7 . V_16 ) {
if ( V_15 )
V_14 = ( ( V_14 >> 1 ) & ~ 0x0000000f ) | ( V_14 & 0x0000000f ) ;
F_7 ( V_2 , V_17 , ( unsigned char ) ( ( V_14 >> 26 ) & 0x03 ) ) ;
} else if ( V_15 )
V_14 = ( V_14 & 0x00c0000f ) | ( ( V_14 & 0x003ffff0 ) >> 1 ) ;
F_9 ( V_2 , V_5 , ( unsigned short ) ( V_14 >> 11 ) ) ;
F_9 ( V_2 , V_5 + 1 , ( unsigned short ) ( V_14 << 5 ) ) ;
}
static inline unsigned int F_15 ( struct V_1 * V_2 ,
unsigned char V_5 , short V_15 )
{
unsigned int V_18 ;
V_18 = ( ( unsigned int ) F_11 ( V_2 , V_5 | 0x80 ) << 11 ) & 0xfff800 ;
V_18 |= ( ( unsigned int ) F_11 ( V_2 , ( V_5 + 1 ) | 0x80 ) >> 5 ) & 0x0007ff ;
if ( V_2 -> V_7 . V_16 ) {
V_18 |= ( unsigned int ) F_8 ( V_2 , V_17 | 0x80 ) << 26 ;
if ( V_15 )
V_18 = ( ( V_18 << 1 ) & 0xffffffe0 ) | ( V_18 & 0x0000000f ) ;
} else if ( V_15 )
V_18 = ( ( V_18 & 0x001ffff0 ) << 1 ) | ( V_18 & 0x00c0000f ) ;
return V_18 ;
}
void F_16 ( struct V_1 * V_2 , unsigned char V_5 )
{
F_5 ( V_2 , V_5 ) ;
}
void F_17 ( struct V_1 * V_2 ,
unsigned char V_5 ,
unsigned char V_10 )
{
F_7 ( V_2 , V_5 , V_10 ) ;
}
unsigned char F_18 ( struct V_1 * V_2 , unsigned char V_5 )
{
return F_8 ( V_2 , V_5 ) ;
}
void F_19 ( struct V_1 * V_2 ,
unsigned char V_5 ,
unsigned int V_10 )
{
F_9 ( V_2 , V_5 , V_10 ) ;
}
unsigned short F_20 ( struct V_1 * V_2 , unsigned char V_5 )
{
return F_11 ( V_2 , V_5 ) ;
}
void F_21 ( struct V_1 * V_2 ,
unsigned char V_5 ,
unsigned char V_10 )
{
F_13 ( V_2 , V_5 , V_10 ) ;
}
void F_22 ( struct V_1 * V_2 , unsigned char V_5 ,
unsigned int V_14 , short V_15 )
{
F_14 ( V_2 , V_5 , V_14 , V_15 ) ;
}
unsigned int F_23 ( struct V_1 * V_2 ,
unsigned char V_5 ,
short V_15 )
{
return F_15 ( V_2 , V_5 , V_15 ) ;
}
void F_24 ( struct V_1 * V_2 , unsigned char V_5 )
{
unsigned long V_19 ;
F_25 ( & V_2 -> V_20 , V_19 ) ;
F_5 ( V_2 , V_5 ) ;
F_26 ( & V_2 -> V_20 , V_19 ) ;
}
void F_27 ( struct V_1 * V_2 ,
unsigned char V_5 ,
unsigned char V_10 )
{
unsigned long V_19 ;
F_25 ( & V_2 -> V_20 , V_19 ) ;
F_7 ( V_2 , V_5 , V_10 ) ;
F_26 ( & V_2 -> V_20 , V_19 ) ;
}
unsigned char F_28 ( struct V_1 * V_2 , unsigned char V_5 )
{
unsigned long V_19 ;
unsigned char V_18 ;
F_25 ( & V_2 -> V_20 , V_19 ) ;
V_18 = F_8 ( V_2 , V_5 ) ;
F_26 ( & V_2 -> V_20 , V_19 ) ;
return V_18 ;
}
void F_29 ( struct V_1 * V_2 ,
unsigned char V_5 ,
unsigned int V_10 )
{
unsigned long V_19 ;
F_25 ( & V_2 -> V_20 , V_19 ) ;
F_9 ( V_2 , V_5 , V_10 ) ;
F_26 ( & V_2 -> V_20 , V_19 ) ;
}
unsigned short F_30 ( struct V_1 * V_2 , unsigned char V_5 )
{
unsigned long V_19 ;
unsigned short V_18 ;
F_25 ( & V_2 -> V_20 , V_19 ) ;
V_18 = F_11 ( V_2 , V_5 ) ;
F_26 ( & V_2 -> V_20 , V_19 ) ;
return V_18 ;
}
static unsigned int F_31 ( struct V_1 * V_2 ,
unsigned char V_5 , short V_15 )
{
unsigned int V_18 ;
unsigned long V_19 ;
F_25 ( & V_2 -> V_20 , V_19 ) ;
V_18 = F_15 ( V_2 , V_5 , V_15 ) ;
F_26 ( & V_2 -> V_20 , V_19 ) ;
return V_18 ;
}
void F_32 ( struct V_1 * V_2 , unsigned int V_14 )
{
F_6 ( 0x43 , V_2 -> V_7 . V_8 ) ;
F_2 () ;
F_10 ( ( unsigned short ) V_14 , V_2 -> V_7 . V_11 ) ;
F_2 () ;
F_6 ( 0x44 , V_2 -> V_7 . V_8 ) ;
F_2 () ;
F_6 ( ( unsigned char ) ( V_14 >> 16 ) , V_2 -> V_7 . V_9 ) ;
F_2 () ;
}
void F_33 ( struct V_1 * V_2 , unsigned int V_14 , unsigned char V_10 )
{
unsigned long V_19 ;
F_25 ( & V_2 -> V_20 , V_19 ) ;
F_6 ( V_21 , V_2 -> V_7 . V_8 ) ;
F_2 () ;
F_10 ( ( unsigned short ) V_14 , V_2 -> V_7 . V_11 ) ;
F_2 () ;
F_6 ( V_22 , V_2 -> V_7 . V_8 ) ;
F_2 () ;
F_6 ( ( unsigned char ) ( V_14 >> 16 ) , V_2 -> V_7 . V_9 ) ;
F_2 () ;
F_6 ( V_10 , V_2 -> V_7 . V_23 ) ;
F_26 ( & V_2 -> V_20 , V_19 ) ;
}
unsigned char F_34 ( struct V_1 * V_2 , unsigned int V_14 )
{
unsigned long V_19 ;
unsigned char V_18 ;
F_25 ( & V_2 -> V_20 , V_19 ) ;
F_6 ( V_21 , V_2 -> V_7 . V_8 ) ;
F_2 () ;
F_10 ( ( unsigned short ) V_14 , V_2 -> V_7 . V_11 ) ;
F_2 () ;
F_6 ( V_22 , V_2 -> V_7 . V_8 ) ;
F_2 () ;
F_6 ( ( unsigned char ) ( V_14 >> 16 ) , V_2 -> V_7 . V_9 ) ;
F_2 () ;
V_18 = F_3 ( V_2 -> V_7 . V_23 ) ;
F_26 ( & V_2 -> V_20 , V_19 ) ;
return V_18 ;
}
void F_35 ( struct V_1 * V_2 )
{
unsigned short V_24 ;
static unsigned short V_25 [ 32 - 14 + 1 ] =
{
44100 , 41160 , 38587 , 36317 , 34300 , 32494 , 30870 , 29400 , 28063 , 26843 ,
25725 , 24696 , 23746 , 22866 , 22050 , 21289 , 20580 , 19916 , 19293
} ;
V_24 = V_2 -> V_7 . V_26 ;
if ( V_24 > 32 )
V_24 = 32 ;
if ( V_24 < 14 )
V_24 = 14 ;
if ( V_2 -> V_7 . V_16 )
V_24 = 32 ;
V_2 -> V_7 . V_26 = V_24 ;
V_2 -> V_7 . V_27 =
V_2 -> V_7 . V_16 ? 44100 : V_25 [ V_24 - 14 ] ;
if ( ! V_2 -> V_7 . V_16 ) {
F_27 ( V_2 , V_28 , 0xc0 | ( V_24 - 1 ) ) ;
F_36 ( 100 ) ;
}
}
void F_37 ( struct V_1 * V_2 )
{
unsigned char V_29 ;
int V_30 , V_31 ;
V_30 = V_2 -> V_7 . V_32 ;
F_38 ( V_33 L_1 , V_30 , V_31 = F_39 ( V_2 , 0 ) , F_39 ( V_2 , 0x0d ) ) ;
F_38 ( V_33 L_2 , V_30 , F_40 ( V_2 , 1 ) ) ;
F_38 ( V_33 L_3 , V_30 , F_31 ( V_2 , 2 , V_31 & 4 ) , F_31 ( V_2 , 2 , ( V_31 & 4 ) ^ 4 ) , F_31 ( V_2 , 4 , V_31 & 4 ) , F_31 ( V_2 , 4 , ( V_31 & 4 ) ^ 4 ) ) ;
F_38 ( V_33 L_4 , V_30 , F_39 ( V_2 , 7 ) , F_39 ( V_2 , 8 ) , F_39 ( V_2 , 6 ) ) ;
F_38 ( V_33 L_5 , V_30 , F_40 ( V_2 , 9 ) ) ;
F_38 ( V_33 L_6 , V_30 , F_31 ( V_2 , 0x0a , V_31 & 4 ) , F_31 ( V_2 , 0x0a , ( V_31 & 4 ) ^ 4 ) ) ;
if ( V_2 -> V_34 && F_39 ( V_2 , 0x19 ) & 0x01 ) {
V_29 = F_39 ( V_2 , 0x15 ) ;
F_38 ( V_33 L_7 , V_30 , V_29 ) ;
if ( V_29 & 0x01 ) {
F_38 ( V_33 L_8 , V_30 , F_31 ( V_2 , 0x11 , V_31 & 4 ) ) ;
F_38 ( V_33 L_9 , V_30 , F_40 ( V_2 , 0x16 ) ) ;
F_38 ( V_33 L_10 , V_30 , F_40 ( V_2 , 0x1d ) ) ;
F_38 ( V_33 L_11 , V_30 , F_39 ( V_2 , 0x14 ) ) ;
}
if ( V_29 & 0x20 ) {
F_38 ( V_33 L_12 , V_30 , F_40 ( V_2 , 0x13 ) , F_40 ( V_2 , 0x13 ) >> 4 ) ;
F_38 ( V_33 L_13 , V_30 , F_40 ( V_2 , 0x1c ) , F_40 ( V_2 , 0x1c ) >> 4 ) ;
F_38 ( V_33 L_14 , V_30 , F_40 ( V_2 , 0x0c ) , F_40 ( V_2 , 0x0c ) >> 4 ) ;
F_38 ( V_33 L_15 , V_30 , F_40 ( V_2 , 0x1b ) , F_40 ( V_2 , 0x1b ) >> 4 ) ;
} else
F_38 ( V_33 L_16 , V_30 , F_39 ( V_2 , 0x0c ) ) ;
} else
F_38 ( V_33 L_16 , V_30 , F_39 ( V_2 , 0x0c ) ) ;
}
