void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned int V_4 = F_2 () ;
if ( V_2 -> V_5 && F_3 ( V_4 , V_2 -> V_5 ) != V_6 ) {
unsigned long V_7 ;
unsigned long V_8 ;
unsigned long V_9 = V_10 ;
V_8 = F_4 ( V_4 , V_2 -> V_5 ) ;
V_3 &= V_11 ;
F_5 ( V_7 ) ;
if ( V_2 -> V_5 != V_12 -> V_13 ) {
V_9 = F_6 () ;
F_7 ( V_8 ) ;
}
F_8 ( V_8 , V_3 ) ;
if ( V_9 != V_10 )
F_7 ( V_9 ) ;
F_9 ( V_7 ) ;
}
}
void F_10 ( struct V_1 * V_2 , unsigned long V_14 ,
unsigned long V_15 )
{
struct V_16 * V_13 = V_2 -> V_5 ;
unsigned int V_4 = F_2 () ;
if ( F_3 ( V_4 , V_13 ) != V_6 ) {
unsigned long V_7 ;
int V_17 ;
F_5 ( V_7 ) ;
V_17 = ( V_15 - V_14 + ( V_18 - 1 ) ) >> V_19 ;
if ( V_17 > ( V_20 / 4 ) ) {
F_3 ( V_4 , V_13 ) = V_6 ;
if ( V_13 == V_12 -> V_13 )
F_11 ( V_13 , V_4 ) ;
} else {
unsigned long V_8 ;
unsigned long V_9 = V_10 ;
V_8 = F_4 ( V_4 , V_13 ) ;
V_14 &= V_11 ;
V_15 += ( V_18 - 1 ) ;
V_15 &= V_11 ;
if ( V_13 != V_12 -> V_13 ) {
V_9 = F_6 () ;
F_7 ( V_8 ) ;
}
while ( V_14 < V_15 ) {
F_8 ( V_8 , V_14 ) ;
V_14 += V_18 ;
}
if ( V_9 != V_10 )
F_7 ( V_9 ) ;
}
F_9 ( V_7 ) ;
}
}
void F_12 ( unsigned long V_14 , unsigned long V_15 )
{
unsigned int V_4 = F_2 () ;
unsigned long V_7 ;
int V_17 ;
F_5 ( V_7 ) ;
V_17 = ( V_15 - V_14 + ( V_18 - 1 ) ) >> V_19 ;
if ( V_17 > ( V_20 / 4 ) ) {
F_13 () ;
} else {
unsigned long V_8 ;
unsigned long V_9 = F_6 () ;
V_8 = F_4 ( V_4 , & V_21 ) ;
V_14 &= V_11 ;
V_15 += ( V_18 - 1 ) ;
V_15 &= V_11 ;
F_7 ( V_8 ) ;
while ( V_14 < V_15 ) {
F_8 ( V_8 , V_14 ) ;
V_14 += V_18 ;
}
F_7 ( V_9 ) ;
}
F_9 ( V_7 ) ;
}
void F_14 ( struct V_16 * V_13 )
{
unsigned int V_4 = F_2 () ;
if ( F_3 ( V_4 , V_13 ) != V_6 ) {
unsigned long V_7 ;
F_5 ( V_7 ) ;
F_3 ( V_4 , V_13 ) = V_6 ;
if ( V_13 == V_12 -> V_13 )
F_11 ( V_13 , V_4 ) ;
F_9 ( V_7 ) ;
}
}
void F_15 ( void )
{
unsigned long V_7 ;
F_5 ( V_7 ) ;
F_16 ( F_17 ( V_22 ) | V_23 , V_22 ) ;
F_9 ( V_7 ) ;
}
