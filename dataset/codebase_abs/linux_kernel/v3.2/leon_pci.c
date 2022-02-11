void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( & V_2 -> V_7 , 0 , V_4 -> V_8 , V_4 ) ;
if ( V_6 ) {
V_6 -> V_9 [ 0 ] = & V_4 -> V_10 ;
V_6 -> V_9 [ 1 ] = & V_4 -> V_11 ;
V_6 -> V_9 [ 2 ] = NULL ;
F_3 ( V_6 ) ;
F_4 ( V_12 , V_4 -> V_13 ) ;
F_5 () ;
}
}
void F_6 ( struct V_14 * V_7 , struct V_15 * V_16 ,
struct V_9 * V_17 )
{
struct V_3 * V_4 = V_7 -> V_18 -> V_19 ;
V_16 -> V_20 = V_17 -> V_20 ;
V_16 -> V_21 = V_17 -> V_21 ;
if ( V_17 -> V_22 & V_23 ) {
V_16 -> V_20 -= ( V_4 -> V_10 . V_20 - 0x1000 ) ;
V_16 -> V_21 -= ( V_4 -> V_10 . V_20 - 0x1000 ) ;
}
}
void F_7 ( struct V_14 * V_7 , struct V_9 * V_17 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = V_7 -> V_18 -> V_19 ;
V_17 -> V_20 = V_16 -> V_20 ;
V_17 -> V_21 = V_16 -> V_21 ;
if ( V_17 -> V_22 & V_23 ) {
V_17 -> V_20 += ( V_4 -> V_10 . V_20 - 0x1000 ) ;
V_17 -> V_21 += ( V_4 -> V_10 . V_20 - 0x1000 ) ;
}
}
void T_1 F_8 ( struct V_5 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_19 ;
struct V_14 * V_7 ;
int V_25 , V_26 , V_27 ;
T_2 V_28 ;
if ( V_24 -> V_29 == NULL ) {
V_24 -> V_9 [ 0 ] = & V_4 -> V_10 ;
V_24 -> V_9 [ 1 ] = & V_4 -> V_11 ;
V_24 -> V_9 [ 2 ] = NULL ;
}
F_9 (dev, &pbus->devices, bus_list) {
V_26 = V_27 = 0 ;
for ( V_25 = 0 ; V_25 < V_30 ; V_25 ++ ) {
unsigned long V_31 = V_7 -> V_9 [ V_25 ] . V_22 ;
if ( V_31 & V_23 )
V_26 = 1 ;
else if ( V_31 & V_32 )
V_27 = 1 ;
}
if ( V_7 -> V_9 [ V_30 ] . V_21 != 0 ) {
V_7 -> V_9 [ V_30 ] . V_22 |=
V_33 ;
V_27 = 1 ;
}
F_10 ( V_24 , V_7 -> V_34 , V_35 , & V_28 ) ;
if ( V_26 && ! ( V_28 & V_36 ) ) {
#ifdef F_11
F_12 ( V_37 L_1 ,
F_13 ( V_7 ) ) ;
#endif
V_28 |= V_36 ;
F_14 ( V_24 , V_7 -> V_34 , V_35 ,
V_28 ) ;
}
if ( V_27 && ! ( V_28 & V_38 ) ) {
#ifdef F_11
F_12 ( V_37 L_2
L_3 , F_13 ( V_7 ) ) ;
#endif
V_28 |= V_38 ;
F_14 ( V_24 , V_7 -> V_34 , V_35 ,
V_28 ) ;
}
}
}
char * T_1 F_15 ( char * V_39 )
{
return V_39 ;
}
T_3 F_16 ( void * V_40 , const struct V_9 * V_17 ,
T_3 V_41 , T_3 V_42 )
{
return V_17 -> V_20 ;
}
int F_17 ( struct V_14 * V_7 , int V_43 )
{
return F_18 ( V_7 , V_43 ) ;
}
struct V_44 * F_19 ( struct V_14 * V_45 )
{
return NULL ;
}
void T_1 F_20 ( struct V_14 * V_7 , int V_46 )
{
#ifdef F_11
F_12 ( V_47 L_4 , V_46 ,
F_13 ( V_7 ) ) ;
#endif
F_21 ( V_7 , V_48 , V_46 ) ;
}
void F_22 ( unsigned long V_49 , const void * V_50 , unsigned long V_51 )
{
while ( V_51 ) {
V_51 -= 1 ;
F_23 ( * ( const char * ) V_50 , V_49 ) ;
V_50 += 1 ;
}
}
void F_24 ( unsigned long V_49 , const void * V_50 , unsigned long V_51 )
{
while ( V_51 ) {
V_51 -= 2 ;
F_25 ( * ( const short * ) V_50 , V_49 ) ;
V_50 += 2 ;
}
}
void F_26 ( unsigned long V_49 , const void * V_50 , unsigned long V_51 )
{
while ( V_51 ) {
V_51 -= 4 ;
F_27 ( * ( const long * ) V_50 , V_49 ) ;
V_50 += 4 ;
}
}
void F_28 ( unsigned long V_49 , void * V_52 , unsigned long V_51 )
{
while ( V_51 ) {
V_51 -= 1 ;
* ( unsigned char * ) V_52 = F_29 ( V_49 ) ;
V_52 += 1 ;
}
}
void F_30 ( unsigned long V_49 , void * V_52 , unsigned long V_51 )
{
while ( V_51 ) {
V_51 -= 2 ;
* ( unsigned short * ) V_52 = F_31 ( V_49 ) ;
V_52 += 2 ;
}
}
void F_32 ( unsigned long V_49 , void * V_52 , unsigned long V_51 )
{
while ( V_51 ) {
V_51 -= 4 ;
* ( unsigned long * ) V_52 = F_33 ( V_49 ) ;
V_52 += 4 ;
}
}
