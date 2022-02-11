void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_5 ) ;
struct V_6 * V_7 ;
F_3 ( & V_5 , & V_4 -> V_8 ,
V_4 -> V_8 . V_9 - 0x1000 ) ;
F_4 ( & V_5 , & V_4 -> V_10 ) ;
V_7 = F_5 ( & V_2 -> V_11 , 0 , V_4 -> V_12 , V_4 ,
& V_5 ) ;
if ( V_7 ) {
F_6 ( V_13 , V_4 -> V_14 ) ;
F_7 () ;
} else {
F_8 ( & V_5 ) ;
}
}
void T_1 F_9 ( struct V_6 * V_15 )
{
struct V_16 * V_11 ;
int V_17 , V_18 , V_19 ;
T_2 V_20 ;
F_10 (dev, &pbus->devices, bus_list) {
V_18 = V_19 = 0 ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
unsigned long V_22 = V_11 -> V_23 [ V_17 ] . V_24 ;
if ( V_22 & V_25 )
V_18 = 1 ;
else if ( V_22 & V_26 )
V_19 = 1 ;
}
if ( V_11 -> V_23 [ V_21 ] . V_27 != 0 ) {
V_11 -> V_23 [ V_21 ] . V_24 |=
V_28 ;
V_19 = 1 ;
}
F_11 ( V_15 , V_11 -> V_29 , V_30 , & V_20 ) ;
if ( V_18 && ! ( V_20 & V_31 ) ) {
#ifdef F_12
F_13 ( V_32 L_1 ,
F_14 ( V_11 ) ) ;
#endif
V_20 |= V_31 ;
F_15 ( V_15 , V_11 -> V_29 , V_30 ,
V_20 ) ;
}
if ( V_19 && ! ( V_20 & V_33 ) ) {
#ifdef F_12
F_13 ( V_32 L_2
L_3 , F_14 ( V_11 ) ) ;
#endif
V_20 |= V_33 ;
F_15 ( V_15 , V_11 -> V_29 , V_30 ,
V_20 ) ;
}
}
}
T_3 F_16 ( void * V_34 , const struct V_23 * V_35 ,
T_3 V_36 , T_3 V_37 )
{
return V_35 -> V_9 ;
}
int F_17 ( struct V_16 * V_11 , int V_38 )
{
return F_18 ( V_11 , V_38 ) ;
}
void F_19 ( unsigned long V_39 , const void * V_40 , unsigned long V_41 )
{
while ( V_41 ) {
V_41 -= 1 ;
F_20 ( * ( const char * ) V_40 , V_39 ) ;
V_40 += 1 ;
}
}
void F_21 ( unsigned long V_39 , const void * V_40 , unsigned long V_41 )
{
while ( V_41 ) {
V_41 -= 2 ;
F_22 ( * ( const short * ) V_40 , V_39 ) ;
V_40 += 2 ;
}
}
void F_23 ( unsigned long V_39 , const void * V_40 , unsigned long V_41 )
{
while ( V_41 ) {
V_41 -= 4 ;
F_24 ( * ( const long * ) V_40 , V_39 ) ;
V_40 += 4 ;
}
}
void F_25 ( unsigned long V_39 , void * V_42 , unsigned long V_41 )
{
while ( V_41 ) {
V_41 -= 1 ;
* ( unsigned char * ) V_42 = F_26 ( V_39 ) ;
V_42 += 1 ;
}
}
void F_27 ( unsigned long V_39 , void * V_42 , unsigned long V_41 )
{
while ( V_41 ) {
V_41 -= 2 ;
* ( unsigned short * ) V_42 = F_28 ( V_39 ) ;
V_42 += 2 ;
}
}
void F_29 ( unsigned long V_39 , void * V_42 , unsigned long V_41 )
{
while ( V_41 ) {
V_41 -= 4 ;
* ( unsigned long * ) V_42 = F_30 ( V_39 ) ;
V_42 += 4 ;
}
}
