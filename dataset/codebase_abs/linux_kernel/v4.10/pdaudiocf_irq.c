T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned short V_5 ;
bool V_6 = false ;
if ( ( V_4 -> V_7 & ( V_8 |
V_9 |
V_10 ) ) != V_9 )
return V_11 ;
V_5 = F_2 ( V_4 -> V_12 + V_13 ) ;
if ( V_5 & ( V_14 | V_15 ) ) {
if ( V_5 & V_15 )
F_3 ( V_16 L_1 ) ;
if ( V_4 -> V_17 )
V_6 = true ;
if ( ! ( V_5 & V_18 ) )
V_5 |= V_18 ;
}
if ( F_4 () != NULL )
F_5 ( V_4 -> V_19 , 0 ) ;
return V_6 ? V_20 : V_11 ;
}
static inline void F_6 ( T_2 * V_21 , T_2 V_22 , unsigned int V_23 , unsigned long V_24 )
{
while ( V_23 -- > 0 ) {
* V_21 ++ = F_2 ( V_24 ) ^ V_22 ;
F_2 ( V_24 ) ;
}
}
static inline void F_7 ( T_3 * V_21 , T_3 V_22 , unsigned int V_23 , unsigned long V_24 )
{
register T_2 V_25 , V_26 ;
while ( V_23 -- > 0 ) {
V_25 = F_2 ( V_24 ) ;
V_26 = F_2 ( V_24 ) ;
F_2 ( V_24 ) ;
* V_21 ++ = ( ( ( ( T_3 ) V_26 & 0xff ) << 24 ) | ( ( T_3 ) V_25 << 8 ) ) ^ V_22 ;
}
}
static inline void F_8 ( T_2 * V_21 , T_2 V_22 , unsigned int V_23 , unsigned long V_24 )
{
while ( V_23 -- > 0 ) {
* V_21 ++ = F_2 ( V_24 ) ^ V_22 ;
* V_21 ++ = F_2 ( V_24 ) ^ V_22 ;
}
}
static inline void F_9 ( T_3 * V_21 , T_3 V_22 , unsigned int V_23 , unsigned long V_24 )
{
register T_2 V_25 , V_26 , V_27 ;
while ( V_23 -- > 0 ) {
V_25 = F_2 ( V_24 ) ;
V_26 = F_2 ( V_24 ) ;
V_27 = F_2 ( V_24 ) ;
* V_21 ++ = ( ( ( ( T_3 ) V_26 & 0xff ) << 24 ) | ( ( T_3 ) V_25 << 8 ) ) ^ V_22 ;
* V_21 ++ = ( ( ( T_3 ) V_27 << 16 ) | ( V_26 & 0xff00 ) ) ^ V_22 ;
}
}
static inline void F_10 ( T_2 * V_21 , T_2 V_22 , unsigned int V_23 , unsigned long V_24 )
{
while ( V_23 -- > 0 ) {
* V_21 ++ = F_11 ( F_2 ( V_24 ) ^ V_22 ) ;
F_2 ( V_24 ) ;
}
}
static inline void F_12 ( T_3 * V_21 , T_3 V_22 , unsigned int V_23 , unsigned long V_24 )
{
register T_2 V_25 , V_26 ;
while ( V_23 -- > 0 ) {
V_25 = F_2 ( V_24 ) ;
V_26 = F_2 ( V_24 ) ;
F_2 ( V_24 ) ;
* V_21 ++ = F_13 ( ( ( ( V_26 & 0xff ) << 24 ) | ( ( T_3 ) V_25 << 8 ) ) ^ V_22 ) ;
}
}
static inline void F_14 ( T_2 * V_21 , T_2 V_22 , unsigned int V_23 , unsigned long V_24 )
{
while ( V_23 -- > 0 ) {
* V_21 ++ = F_11 ( F_2 ( V_24 ) ^ V_22 ) ;
* V_21 ++ = F_11 ( F_2 ( V_24 ) ^ V_22 ) ;
}
}
static inline void F_15 ( T_3 * V_21 , T_3 V_22 , unsigned int V_23 , unsigned long V_24 )
{
register T_2 V_25 , V_26 , V_27 ;
while ( V_23 -- > 0 ) {
V_25 = F_2 ( V_24 ) ;
V_26 = F_2 ( V_24 ) ;
V_27 = F_2 ( V_24 ) ;
* V_21 ++ = F_13 ( ( ( ( V_26 & 0xff ) << 24 ) | ( ( T_3 ) V_25 << 8 ) ) ^ V_22 ) ;
* V_21 ++ = F_13 ( ( ( ( T_3 ) V_27 << 16 ) | ( V_26 & 0xff00 ) ) ^ V_22 ) ;
}
}
static inline void F_16 ( T_4 * V_21 , T_2 V_22 , unsigned int V_23 , unsigned long V_24 )
{
register T_2 V_25 , V_26 ;
register T_3 V_28 ;
while ( V_23 -- > 0 ) {
V_25 = F_2 ( V_24 ) ;
V_26 = F_2 ( V_24 ) ;
F_2 ( V_24 ) ;
V_28 = ( ( ( V_26 & 0xff ) << 8 ) | ( V_25 << 16 ) ) ^ V_22 ;
* V_21 ++ = ( T_4 ) ( V_28 >> 8 ) ;
* V_21 ++ = ( T_4 ) ( V_28 >> 16 ) ;
* V_21 ++ = ( T_4 ) ( V_28 >> 24 ) ;
}
}
static inline void F_17 ( T_4 * V_21 , T_2 V_22 , unsigned int V_23 , unsigned long V_24 )
{
register T_2 V_25 , V_26 ;
register T_3 V_28 ;
while ( V_23 -- > 0 ) {
V_25 = F_2 ( V_24 ) ;
V_26 = F_2 ( V_24 ) ;
F_2 ( V_24 ) ;
V_28 = ( ( ( V_26 & 0xff ) << 8 ) | ( V_25 << 16 ) ) ^ V_22 ;
* V_21 ++ = ( T_4 ) ( V_28 >> 24 ) ;
* V_21 ++ = ( T_4 ) ( V_28 >> 16 ) ;
* V_21 ++ = ( T_4 ) ( V_28 >> 8 ) ;
}
}
static inline void F_18 ( T_4 * V_21 , T_3 V_22 , unsigned int V_23 , unsigned long V_24 )
{
register T_2 V_25 , V_26 , V_27 ;
register T_3 V_28 , V_29 ;
while ( V_23 -- > 0 ) {
V_25 = F_2 ( V_24 ) ;
V_26 = F_2 ( V_24 ) ;
V_27 = F_2 ( V_24 ) ;
V_28 = ( ( ( ( T_3 ) V_26 & 0xff ) << 24 ) | ( ( T_3 ) V_25 << 8 ) ) ^ V_22 ;
V_29 = ( ( ( T_3 ) V_27 << 16 ) | ( V_26 & 0xff00 ) ) ^ V_22 ;
* V_21 ++ = ( T_4 ) ( V_28 >> 8 ) ;
* V_21 ++ = ( T_4 ) ( V_28 >> 16 ) ;
* V_21 ++ = ( T_4 ) ( V_28 >> 24 ) ;
* V_21 ++ = ( T_4 ) ( V_29 >> 8 ) ;
* V_21 ++ = ( T_4 ) ( V_29 >> 16 ) ;
* V_21 ++ = ( T_4 ) ( V_29 >> 24 ) ;
}
}
static inline void F_19 ( T_4 * V_21 , T_3 V_22 , unsigned int V_23 , unsigned long V_24 )
{
register T_2 V_25 , V_26 , V_27 ;
register T_3 V_28 , V_29 ;
while ( V_23 -- > 0 ) {
V_25 = F_2 ( V_24 ) ;
V_26 = F_2 ( V_24 ) ;
V_27 = F_2 ( V_24 ) ;
V_28 = ( ( ( ( T_3 ) V_26 & 0xff ) << 24 ) | ( ( T_3 ) V_25 << 8 ) ) ^ V_22 ;
V_29 = ( ( ( T_3 ) V_27 << 16 ) | ( V_26 & 0xff00 ) ) ^ V_22 ;
* V_21 ++ = ( T_4 ) ( V_28 >> 24 ) ;
* V_21 ++ = ( T_4 ) ( V_28 >> 16 ) ;
* V_21 ++ = ( T_4 ) ( V_28 >> 8 ) ;
* V_21 ++ = ( T_4 ) ( V_29 >> 24 ) ;
* V_21 ++ = ( T_4 ) ( V_29 >> 16 ) ;
* V_21 ++ = ( T_4 ) ( V_29 >> 8 ) ;
}
}
static void F_20 ( struct V_3 * V_4 , unsigned int V_23 , unsigned int V_30 )
{
unsigned long V_24 = V_4 -> V_12 + V_31 ;
unsigned int V_22 = V_4 -> V_32 ;
if ( V_4 -> V_33 == 3 ) {
if ( V_4 -> V_34 ) {
if ( V_4 -> V_35 == 1 ) {
F_16 ( ( char * ) V_4 -> V_36 + ( V_30 * 3 ) , V_22 , V_23 , V_24 ) ;
} else {
F_18 ( ( char * ) V_4 -> V_36 + ( V_30 * 6 ) , V_22 , V_23 , V_24 ) ;
}
} else {
if ( V_4 -> V_35 == 1 ) {
F_17 ( ( char * ) V_4 -> V_36 + ( V_30 * 3 ) , V_22 , V_23 , V_24 ) ;
} else {
F_19 ( ( char * ) V_4 -> V_36 + ( V_30 * 6 ) , V_22 , V_23 , V_24 ) ;
}
}
return;
}
if ( V_4 -> V_37 == 0 ) {
if ( V_4 -> V_35 == 1 ) {
if ( V_4 -> V_38 == 2 ) {
F_6 ( ( T_2 * ) V_4 -> V_36 + V_30 , V_22 , V_23 , V_24 ) ;
} else {
F_7 ( ( T_3 * ) V_4 -> V_36 + V_30 , V_22 , V_23 , V_24 ) ;
}
} else {
if ( V_4 -> V_38 == 2 ) {
F_8 ( ( T_2 * ) V_4 -> V_36 + ( V_30 * 2 ) , V_22 , V_23 , V_24 ) ;
} else {
F_9 ( ( T_3 * ) V_4 -> V_36 + ( V_30 * 2 ) , V_22 , V_23 , V_24 ) ;
}
}
} else {
if ( V_4 -> V_35 == 1 ) {
if ( V_4 -> V_38 == 2 ) {
F_10 ( ( T_2 * ) V_4 -> V_36 + V_30 , V_22 , V_23 , V_24 ) ;
} else {
F_12 ( ( T_3 * ) V_4 -> V_36 + V_30 , V_22 , V_23 , V_24 ) ;
}
} else {
if ( V_4 -> V_38 == 2 ) {
F_14 ( ( T_2 * ) V_4 -> V_36 + ( V_30 * 2 ) , V_22 , V_23 , V_24 ) ;
} else {
F_15 ( ( T_3 * ) V_4 -> V_36 + ( V_30 * 2 ) , V_22 , V_23 , V_24 ) ;
}
}
}
}
T_1 F_21 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_23 , V_30 , V_39 , V_40 , V_41 ;
if ( ( V_4 -> V_7 & ( V_8 | V_9 ) ) != V_9 )
return V_11 ;
if ( V_4 -> V_17 == NULL || V_4 -> V_17 -> V_42 == NULL || ! F_22 ( V_4 -> V_17 ) )
return V_11 ;
V_40 = F_2 ( V_4 -> V_12 + V_43 ) ;
V_41 = F_2 ( V_4 -> V_12 + V_44 ) ;
V_23 = V_41 - V_40 ;
if ( V_23 < 0 )
V_23 += 0x10000 ;
if ( V_23 == 0 )
V_23 = 0x10000 ;
V_23 /= V_4 -> V_38 ;
if ( V_23 > 64 )
V_23 -= 32 ;
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
V_30 = V_4 -> V_45 + V_4 -> V_46 ;
V_30 %= V_4 -> V_47 ;
V_4 -> V_46 += V_23 ;
while ( V_23 > 0 ) {
V_39 = V_4 -> V_47 - V_30 ;
if ( V_39 > V_23 )
V_39 = V_23 ;
F_20 ( V_4 , V_39 , V_30 ) ;
V_30 += V_39 ;
V_30 %= V_4 -> V_47 ;
V_23 -= V_39 ;
}
#endif
F_23 ( & V_4 -> V_48 ) ;
while ( V_4 -> V_46 >= V_4 -> V_49 ) {
V_4 -> V_45 += V_4 -> V_49 ;
V_4 -> V_45 %= V_4 -> V_47 ;
V_4 -> V_46 -= V_4 -> V_49 ;
F_24 ( & V_4 -> V_48 ) ;
F_25 ( V_4 -> V_17 ) ;
F_23 ( & V_4 -> V_48 ) ;
}
F_24 ( & V_4 -> V_48 ) ;
return V_11 ;
}
