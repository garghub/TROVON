static int
F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
F_2 ( V_2 -> V_2 , V_4 ) ;
F_3 ( V_2 , V_4 , V_3 ) ;
}
F_4 ( V_2 , 30 , 0 ) ;
F_5 ( V_2 , 30 , 0x1d8 ) ;
F_6 ( V_2 , 30 , 0x1e0 ) ;
F_7 ( V_2 , 30 , 0x1d8 ) ;
F_4 ( V_2 , 31 , 0 ) ;
F_5 ( V_2 , 31 , 0x1d8 ) ;
F_6 ( V_2 , 31 , 0x1e0 ) ;
F_7 ( V_2 , 31 , 0x1d8 ) ;
return 0 ;
}
static void
F_8 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
F_3 ( V_2 , V_4 , V_6 ) ;
F_9 ( V_2 -> V_2 , V_4 ) ;
}
}
static unsigned short
F_10 ( const void T_1 * V_7 , int V_8 , int V_9 )
{
unsigned short V_10 ;
if ( V_9 & V_11 ) {
unsigned char V_12 ;
F_11 ( V_12 , ( unsigned char T_1 * ) V_7 + V_8 ) ;
V_10 = V_12 << 8 ;
} else {
#ifdef F_12
F_11 ( V_10 , ( unsigned short T_1 * ) V_7 + V_8 ) ;
#else
unsigned short V_12 ;
F_11 ( V_12 , ( unsigned short T_1 * ) V_7 + V_8 ) ;
V_10 = F_13 ( V_12 ) ;
#endif
}
if ( V_9 & V_13 )
V_10 ^= 0x8000 ;
return V_10 ;
}
static void
F_14 ( struct V_1 * V_2 )
{
while ( ( F_15 ( V_2 ) & 0x80000000 ) != 0 ) {
F_16 ( 1 ) ;
if ( F_17 ( V_14 ) )
break;
}
}
static inline void
F_18 ( struct V_1 * V_2 , int * V_8 , unsigned short V_15 )
{
if ( V_16 ) {
if ( V_16 > 1 )
F_14 ( V_2 ) ;
F_19 ( V_2 , * V_8 ) ;
}
F_20 ( V_2 , V_15 ) ;
* V_8 += 1 ;
}
int
F_21 ( struct V_17 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 ,
const void T_1 * V_15 , long V_23 )
{
int V_4 ;
int V_24 ;
int V_8 ;
int V_25 ;
int V_26 , V_27 ;
struct V_1 * V_2 ;
V_2 = V_18 -> V_28 ;
if ( F_22 ( ! V_20 ) )
return - V_29 ;
if ( V_20 -> V_30 . V_31 == 0 )
return 0 ;
if ( V_20 -> V_30 . V_32 > V_20 -> V_30 . V_33 ) {
int V_34 = V_20 -> V_30 . V_32 ;
V_20 -> V_30 . V_32 = V_20 -> V_30 . V_33 ;
V_20 -> V_30 . V_33 = V_34 ;
}
V_25 = V_20 -> V_30 . V_31 ;
if ( V_20 -> V_30 . V_35 & ( V_36 | V_37 ) )
V_25 += V_20 -> V_30 . V_33 - V_20 -> V_30 . V_32 ;
if ( V_20 -> V_30 . V_35 & V_38 )
V_25 += V_39 ;
V_20 -> V_40 = F_23 ( V_22 , V_25 * 2 ) ;
if ( V_20 -> V_40 == NULL ) {
return - V_41 ;
}
if ( V_20 -> V_30 . V_35 & V_11 ) {
if ( ! F_24 ( V_42 , V_15 , V_20 -> V_30 . V_31 ) )
return - V_43 ;
} else {
if ( ! F_24 ( V_42 , V_15 , V_20 -> V_30 . V_31 * 2 ) )
return - V_43 ;
}
V_20 -> V_30 . V_44 -= V_20 -> V_30 . V_45 ;
V_20 -> V_30 . V_32 -= V_20 -> V_30 . V_45 ;
V_20 -> V_30 . V_33 -= V_20 -> V_30 . V_45 ;
V_20 -> V_30 . V_45 = 0 ;
V_26 = V_46 + ( V_20 -> V_40 -> V_8 >> 1 ) ;
V_27 = V_26 ;
V_20 -> V_30 . V_25 = V_25 * 2 ;
F_25 ( V_2 -> V_2 ) ;
if ( ( V_24 = F_1 ( V_2 , V_47 ) ) != 0 )
return V_24 ;
F_14 ( V_2 ) ;
F_19 ( V_2 , V_26 ) ;
#if 0
if (! sp->block->offset) {
for (i = 0; i < BLANK_HEAD_SIZE; i++) {
write_word(emu, &dram_offset, 0);
}
}
#endif
V_8 = 0 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_30 . V_31 ; V_4 ++ ) {
unsigned short V_48 ;
V_48 = F_10 ( V_15 , V_8 , V_20 -> V_30 . V_35 ) ;
V_8 ++ ;
F_18 ( V_2 , & V_26 , V_48 ) ;
F_26 () ;
if ( V_4 == V_20 -> V_30 . V_33 &&
( V_20 -> V_30 . V_35 & ( V_36 | V_37 ) ) )
{
int V_49 = V_20 -> V_30 . V_33 - V_20 -> V_30 . V_32 ;
int V_50 ;
for ( V_50 = 1 ; V_50 <= V_49 ; V_50 ++ ) {
V_48 = F_10 ( V_15 , V_8 - V_50 , V_20 -> V_30 . V_35 ) ;
F_18 ( V_2 , & V_26 , V_48 ) ;
}
if ( V_20 -> V_30 . V_35 & V_36 ) {
V_20 -> V_30 . V_33 += V_49 ;
} else {
V_20 -> V_30 . V_32 += V_49 ;
V_20 -> V_30 . V_33 += V_49 ;
}
V_20 -> V_30 . V_44 += V_49 ;
}
}
if ( V_20 -> V_30 . V_35 & V_38 ) {
for ( V_4 = 0 ; V_4 < V_39 ; V_4 ++ ) {
F_18 ( V_2 , & V_26 , 0 ) ;
}
if ( V_20 -> V_30 . V_35 & V_51 ) {
V_20 -> V_30 . V_32 = V_20 -> V_30 . V_44 + V_52 ;
V_20 -> V_30 . V_33 = V_20 -> V_30 . V_44 + V_53 ;
}
}
V_20 -> V_30 . V_45 += V_27 ;
V_20 -> V_30 . V_44 += V_27 ;
V_20 -> V_30 . V_32 += V_27 ;
V_20 -> V_30 . V_33 += V_27 ;
F_8 ( V_2 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
int
F_28 ( struct V_17 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 )
{
if ( V_20 -> V_40 ) {
F_29 ( V_22 , V_20 -> V_40 ) ;
V_20 -> V_40 = NULL ;
}
return 0 ;
}
void
F_30 ( struct V_17 * V_18 )
{
F_25 ( V_18 ) ;
}
