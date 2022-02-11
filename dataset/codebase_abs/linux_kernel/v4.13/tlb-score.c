void F_1 ( void )
{
unsigned long V_1 ;
unsigned long V_2 ;
int V_3 ;
F_2 ( V_1 ) ;
V_2 = F_3 () & V_4 ;
F_4 ( 0 ) ;
V_3 = F_5 () ;
for (; V_3 < V_5 ; V_3 ++ ) {
F_6 ( V_3 ) ;
F_7 ( V_6 ) ;
F_8 () ;
F_9 () ;
}
F_7 ( V_2 ) ;
F_10 ( V_1 ) ;
}
static inline void
F_11 ( struct V_7 * V_8 )
{
unsigned long V_1 ;
F_2 ( V_1 ) ;
F_12 ( V_8 ) ;
F_7 ( V_8 -> V_9 & V_4 ) ;
F_10 ( V_1 ) ;
}
void F_13 ( struct V_7 * V_8 )
{
if ( V_8 -> V_9 != 0 )
F_11 ( V_8 ) ;
}
void F_14 ( struct V_10 * V_11 , unsigned long V_12 ,
unsigned long V_13 )
{
struct V_7 * V_8 = V_11 -> V_14 ;
unsigned long V_15 = V_8 -> V_9 ;
if ( V_8 -> V_9 != 0 ) {
unsigned long V_1 ;
int V_16 ;
F_2 ( V_1 ) ;
V_16 = ( V_13 - V_12 + ( V_17 - 1 ) ) >> V_18 ;
if ( V_16 <= V_5 ) {
int V_19 = F_3 () & V_4 ;
int V_20 = V_15 & V_4 ;
V_12 &= V_21 ;
V_13 += ( V_17 - 1 ) ;
V_13 &= V_21 ;
while ( V_12 < V_13 ) {
int V_22 ;
F_7 ( V_12 | V_20 ) ;
V_12 += V_17 ;
F_8 () ;
F_15 () ;
V_22 = F_16 () ;
F_4 ( 0 ) ;
F_7 ( V_6 ) ;
if ( V_22 < 0 )
continue;
F_9 () ;
}
F_7 ( V_19 ) ;
} else {
F_12 ( V_8 ) ;
if ( V_8 == V_23 -> V_24 )
F_7 ( V_15 & V_4 ) ;
}
F_10 ( V_1 ) ;
}
}
void F_17 ( unsigned long V_12 , unsigned long V_13 )
{
unsigned long V_1 ;
int V_16 ;
F_2 ( V_1 ) ;
V_16 = ( V_13 - V_12 + ( V_17 - 1 ) ) >> V_18 ;
if ( V_16 <= V_5 ) {
int V_25 = F_3 () ;
V_12 &= V_21 ;
V_13 += V_17 - 1 ;
V_13 &= V_21 ;
while ( V_12 < V_13 ) {
long V_22 ;
F_7 ( V_12 ) ;
V_12 += V_17 ;
F_15 () ;
V_22 = F_16 () ;
if ( V_22 < 0 )
continue;
F_4 ( 0 ) ;
F_7 ( V_6 ) ;
F_8 () ;
F_9 () ;
}
F_7 ( V_25 ) ;
} else {
F_1 () ;
}
F_10 ( V_1 ) ;
}
void F_18 ( struct V_10 * V_11 , unsigned long V_26 )
{
if ( V_11 && V_11 -> V_14 -> V_9 != 0 ) {
unsigned long V_1 ;
int V_19 , V_20 , V_22 ;
unsigned long V_27 = V_11 -> V_14 -> V_9 ;
V_20 = V_27 & V_4 ;
V_26 &= V_21 ;
F_2 ( V_1 ) ;
V_19 = F_3 () & V_4 ;
F_7 ( V_26 | V_20 ) ;
F_8 () ;
F_15 () ;
V_22 = F_16 () ;
F_4 ( 0 ) ;
F_7 ( V_6 ) ;
if ( V_22 < 0 )
goto V_28;
F_8 () ;
F_9 () ;
V_28:
F_7 ( V_19 ) ;
F_10 ( V_1 ) ;
}
}
void F_19 ( unsigned long V_26 )
{
unsigned long V_1 ;
int V_19 , V_22 ;
F_2 ( V_1 ) ;
V_19 = F_3 () ;
V_26 &= ( V_21 << 1 ) ;
F_7 ( V_26 ) ;
F_8 () ;
F_15 () ;
V_22 = F_16 () ;
F_4 ( 0 ) ;
if ( V_22 >= 0 ) {
F_7 ( V_6 ) ;
F_8 () ;
F_9 () ;
}
F_7 ( V_19 ) ;
F_10 ( V_1 ) ;
}
void F_20 ( struct V_10 * V_11 , unsigned long V_29 , T_1 V_30 )
{
unsigned long V_1 ;
int V_22 , V_25 ;
if ( V_23 -> V_24 != V_11 -> V_14 )
return;
V_25 = F_3 () & V_4 ;
F_2 ( V_1 ) ;
V_29 &= V_21 ;
F_7 ( V_29 | V_25 ) ;
F_8 () ;
F_15 () ;
V_22 = F_16 () ;
F_4 ( F_21 ( V_30 ) ) ;
F_7 ( V_29 | V_25 ) ;
if ( V_22 < 0 )
F_22 () ;
else
F_9 () ;
F_7 ( V_25 ) ;
F_10 ( V_1 ) ;
}
void F_23 ( void )
{
F_24 ( 0 ) ;
F_1 () ;
memcpy ( ( void * ) ( V_31 + 0x100 ) ,
& V_32 , 0xFC ) ;
F_25 ( V_31 + 0x100 ,
V_31 + 0x1FC ) ;
}
