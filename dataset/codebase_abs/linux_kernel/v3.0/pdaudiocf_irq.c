T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned short V_5 ;
if ( ( V_4 -> V_6 & ( V_7 |
V_8 |
V_9 ) ) != V_8 )
return V_10 ;
V_5 = F_2 ( V_4 -> V_11 + V_12 ) ;
if ( V_5 & ( V_13 | V_14 ) ) {
if ( V_5 & V_14 )
F_3 ( V_15 L_1 ) ;
if ( V_4 -> V_16 )
F_4 ( & V_4 -> V_17 ) ;
if ( ! ( V_5 & V_18 ) )
V_5 |= V_18 ;
}
if ( F_5 () != NULL )
F_6 ( V_4 -> V_19 , 0 ) ;
return V_10 ;
}
static inline void F_7 ( T_2 * V_20 , T_2 V_21 , unsigned int V_22 , unsigned long V_23 )
{
while ( V_22 -- > 0 ) {
* V_20 ++ = F_2 ( V_23 ) ^ V_21 ;
F_2 ( V_23 ) ;
}
}
static inline void F_8 ( T_3 * V_20 , T_3 V_21 , unsigned int V_22 , unsigned long V_23 )
{
register T_2 V_24 , V_25 ;
while ( V_22 -- > 0 ) {
V_24 = F_2 ( V_23 ) ;
V_25 = F_2 ( V_23 ) ;
F_2 ( V_23 ) ;
* V_20 ++ = ( ( ( ( T_3 ) V_25 & 0xff ) << 24 ) | ( ( T_3 ) V_24 << 8 ) ) ^ V_21 ;
}
}
static inline void F_9 ( T_2 * V_20 , T_2 V_21 , unsigned int V_22 , unsigned long V_23 )
{
while ( V_22 -- > 0 ) {
* V_20 ++ = F_2 ( V_23 ) ^ V_21 ;
* V_20 ++ = F_2 ( V_23 ) ^ V_21 ;
}
}
static inline void F_10 ( T_3 * V_20 , T_3 V_21 , unsigned int V_22 , unsigned long V_23 )
{
register T_2 V_24 , V_25 , V_26 ;
while ( V_22 -- > 0 ) {
V_24 = F_2 ( V_23 ) ;
V_25 = F_2 ( V_23 ) ;
V_26 = F_2 ( V_23 ) ;
* V_20 ++ = ( ( ( ( T_3 ) V_25 & 0xff ) << 24 ) | ( ( T_3 ) V_24 << 8 ) ) ^ V_21 ;
* V_20 ++ = ( ( ( T_3 ) V_26 << 16 ) | ( V_25 & 0xff00 ) ) ^ V_21 ;
}
}
static inline void F_11 ( T_2 * V_20 , T_2 V_21 , unsigned int V_22 , unsigned long V_23 )
{
while ( V_22 -- > 0 ) {
* V_20 ++ = F_12 ( F_2 ( V_23 ) ^ V_21 ) ;
F_2 ( V_23 ) ;
}
}
static inline void F_13 ( T_3 * V_20 , T_3 V_21 , unsigned int V_22 , unsigned long V_23 )
{
register T_2 V_24 , V_25 ;
while ( V_22 -- > 0 ) {
V_24 = F_2 ( V_23 ) ;
V_25 = F_2 ( V_23 ) ;
F_2 ( V_23 ) ;
* V_20 ++ = F_14 ( ( ( ( V_25 & 0xff ) << 24 ) | ( ( T_3 ) V_24 << 8 ) ) ^ V_21 ) ;
}
}
static inline void F_15 ( T_2 * V_20 , T_2 V_21 , unsigned int V_22 , unsigned long V_23 )
{
while ( V_22 -- > 0 ) {
* V_20 ++ = F_12 ( F_2 ( V_23 ) ^ V_21 ) ;
* V_20 ++ = F_12 ( F_2 ( V_23 ) ^ V_21 ) ;
}
}
static inline void F_16 ( T_3 * V_20 , T_3 V_21 , unsigned int V_22 , unsigned long V_23 )
{
register T_2 V_24 , V_25 , V_26 ;
while ( V_22 -- > 0 ) {
V_24 = F_2 ( V_23 ) ;
V_25 = F_2 ( V_23 ) ;
V_26 = F_2 ( V_23 ) ;
* V_20 ++ = F_14 ( ( ( ( V_25 & 0xff ) << 24 ) | ( ( T_3 ) V_24 << 8 ) ) ^ V_21 ) ;
* V_20 ++ = F_14 ( ( ( ( T_3 ) V_26 << 16 ) | ( V_25 & 0xff00 ) ) ^ V_21 ) ;
}
}
static inline void F_17 ( T_4 * V_20 , T_2 V_21 , unsigned int V_22 , unsigned long V_23 )
{
register T_2 V_24 , V_25 ;
register T_3 V_27 ;
while ( V_22 -- > 0 ) {
V_24 = F_2 ( V_23 ) ;
V_25 = F_2 ( V_23 ) ;
F_2 ( V_23 ) ;
V_27 = ( ( ( V_25 & 0xff ) << 8 ) | ( V_24 << 16 ) ) ^ V_21 ;
* V_20 ++ = ( T_4 ) ( V_27 >> 8 ) ;
* V_20 ++ = ( T_4 ) ( V_27 >> 16 ) ;
* V_20 ++ = ( T_4 ) ( V_27 >> 24 ) ;
}
}
static inline void F_18 ( T_4 * V_20 , T_2 V_21 , unsigned int V_22 , unsigned long V_23 )
{
register T_2 V_24 , V_25 ;
register T_3 V_27 ;
while ( V_22 -- > 0 ) {
V_24 = F_2 ( V_23 ) ;
V_25 = F_2 ( V_23 ) ;
F_2 ( V_23 ) ;
V_27 = ( ( ( V_25 & 0xff ) << 8 ) | ( V_24 << 16 ) ) ^ V_21 ;
* V_20 ++ = ( T_4 ) ( V_27 >> 24 ) ;
* V_20 ++ = ( T_4 ) ( V_27 >> 16 ) ;
* V_20 ++ = ( T_4 ) ( V_27 >> 8 ) ;
}
}
static inline void F_19 ( T_4 * V_20 , T_3 V_21 , unsigned int V_22 , unsigned long V_23 )
{
register T_2 V_24 , V_25 , V_26 ;
register T_3 V_27 , V_28 ;
while ( V_22 -- > 0 ) {
V_24 = F_2 ( V_23 ) ;
V_25 = F_2 ( V_23 ) ;
V_26 = F_2 ( V_23 ) ;
V_27 = ( ( ( ( T_3 ) V_25 & 0xff ) << 24 ) | ( ( T_3 ) V_24 << 8 ) ) ^ V_21 ;
V_28 = ( ( ( T_3 ) V_26 << 16 ) | ( V_25 & 0xff00 ) ) ^ V_21 ;
* V_20 ++ = ( T_4 ) ( V_27 >> 8 ) ;
* V_20 ++ = ( T_4 ) ( V_27 >> 16 ) ;
* V_20 ++ = ( T_4 ) ( V_27 >> 24 ) ;
* V_20 ++ = ( T_4 ) ( V_28 >> 8 ) ;
* V_20 ++ = ( T_4 ) ( V_28 >> 16 ) ;
* V_20 ++ = ( T_4 ) ( V_28 >> 24 ) ;
}
}
static inline void F_20 ( T_4 * V_20 , T_3 V_21 , unsigned int V_22 , unsigned long V_23 )
{
register T_2 V_24 , V_25 , V_26 ;
register T_3 V_27 , V_28 ;
while ( V_22 -- > 0 ) {
V_24 = F_2 ( V_23 ) ;
V_25 = F_2 ( V_23 ) ;
V_26 = F_2 ( V_23 ) ;
V_27 = ( ( ( ( T_3 ) V_25 & 0xff ) << 24 ) | ( ( T_3 ) V_24 << 8 ) ) ^ V_21 ;
V_28 = ( ( ( T_3 ) V_26 << 16 ) | ( V_25 & 0xff00 ) ) ^ V_21 ;
* V_20 ++ = ( T_4 ) ( V_27 >> 24 ) ;
* V_20 ++ = ( T_4 ) ( V_27 >> 16 ) ;
* V_20 ++ = ( T_4 ) ( V_27 >> 8 ) ;
* V_20 ++ = ( T_4 ) ( V_28 >> 24 ) ;
* V_20 ++ = ( T_4 ) ( V_28 >> 16 ) ;
* V_20 ++ = ( T_4 ) ( V_28 >> 8 ) ;
}
}
static void F_21 ( struct V_3 * V_4 , unsigned int V_22 , unsigned int V_29 )
{
unsigned long V_23 = V_4 -> V_11 + V_30 ;
unsigned int V_21 = V_4 -> V_31 ;
if ( V_4 -> V_32 == 3 ) {
if ( V_4 -> V_33 ) {
if ( V_4 -> V_34 == 1 ) {
F_17 ( ( char * ) V_4 -> V_35 + ( V_29 * 3 ) , V_21 , V_22 , V_23 ) ;
} else {
F_19 ( ( char * ) V_4 -> V_35 + ( V_29 * 6 ) , V_21 , V_22 , V_23 ) ;
}
} else {
if ( V_4 -> V_34 == 1 ) {
F_18 ( ( char * ) V_4 -> V_35 + ( V_29 * 3 ) , V_21 , V_22 , V_23 ) ;
} else {
F_20 ( ( char * ) V_4 -> V_35 + ( V_29 * 6 ) , V_21 , V_22 , V_23 ) ;
}
}
return;
}
if ( V_4 -> V_36 == 0 ) {
if ( V_4 -> V_34 == 1 ) {
if ( V_4 -> V_37 == 2 ) {
F_7 ( ( T_2 * ) V_4 -> V_35 + V_29 , V_21 , V_22 , V_23 ) ;
} else {
F_8 ( ( T_3 * ) V_4 -> V_35 + V_29 , V_21 , V_22 , V_23 ) ;
}
} else {
if ( V_4 -> V_37 == 2 ) {
F_9 ( ( T_2 * ) V_4 -> V_35 + ( V_29 * 2 ) , V_21 , V_22 , V_23 ) ;
} else {
F_10 ( ( T_3 * ) V_4 -> V_35 + ( V_29 * 2 ) , V_21 , V_22 , V_23 ) ;
}
}
} else {
if ( V_4 -> V_34 == 1 ) {
if ( V_4 -> V_37 == 2 ) {
F_11 ( ( T_2 * ) V_4 -> V_35 + V_29 , V_21 , V_22 , V_23 ) ;
} else {
F_13 ( ( T_3 * ) V_4 -> V_35 + V_29 , V_21 , V_22 , V_23 ) ;
}
} else {
if ( V_4 -> V_37 == 2 ) {
F_15 ( ( T_2 * ) V_4 -> V_35 + ( V_29 * 2 ) , V_21 , V_22 , V_23 ) ;
} else {
F_16 ( ( T_3 * ) V_4 -> V_35 + ( V_29 * 2 ) , V_21 , V_22 , V_23 ) ;
}
}
}
}
void F_22 ( unsigned long V_38 )
{
struct V_3 * V_4 = (struct V_3 * ) V_38 ;
int V_22 , V_29 , V_39 , V_40 , V_41 ;
if ( ( V_4 -> V_6 & ( V_7 | V_8 ) ) != V_8 )
return;
if ( V_4 -> V_16 == NULL || V_4 -> V_16 -> V_42 == NULL || ! F_23 ( V_4 -> V_16 ) )
return;
V_40 = F_2 ( V_4 -> V_11 + V_43 ) ;
V_41 = F_2 ( V_4 -> V_11 + V_44 ) ;
V_22 = V_41 - V_40 ;
if ( V_22 < 0 )
V_22 += 0x10000 ;
if ( V_22 == 0 )
V_22 = 0x10000 ;
V_22 /= V_4 -> V_37 ;
if ( V_22 > 64 )
V_22 -= 32 ;
#if 0
chip->pcm_hwptr += size;
chip->pcm_hwptr %= chip->pcm_size;
chip->pcm_tdone += size;
if (chip->pcm_frame == 2) {
unsigned long rdp_port = chip->port + PDAUDIOCF_REG_MD;
while (size-- > 0) {
inw(rdp_port);
inw(rdp_port);
}
} else {
unsigned long rdp_port = chip->port + PDAUDIOCF_REG_MD;
while (size-- > 0) {
inw(rdp_port);
inw(rdp_port);
inw(rdp_port);
}
}
#else
V_29 = V_4 -> V_45 + V_4 -> V_46 ;
V_29 %= V_4 -> V_47 ;
V_4 -> V_46 += V_22 ;
while ( V_22 > 0 ) {
V_39 = V_4 -> V_47 - V_29 ;
if ( V_39 > V_22 )
V_39 = V_22 ;
F_21 ( V_4 , V_39 , V_29 ) ;
V_29 += V_39 ;
V_29 %= V_4 -> V_47 ;
V_22 -= V_39 ;
}
#endif
F_24 ( & V_4 -> V_48 ) ;
while ( V_4 -> V_46 >= V_4 -> V_49 ) {
V_4 -> V_45 += V_4 -> V_49 ;
V_4 -> V_45 %= V_4 -> V_47 ;
V_4 -> V_46 -= V_4 -> V_49 ;
F_25 ( & V_4 -> V_48 ) ;
F_26 ( V_4 -> V_16 ) ;
F_24 ( & V_4 -> V_48 ) ;
}
F_25 ( & V_4 -> V_48 ) ;
}
