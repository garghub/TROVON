void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_5 ) ;
struct V_6 * V_7 ;
F_3 ( & V_5 , & V_4 -> V_8 ,
V_4 -> V_8 . V_9 - 0x1000 ) ;
F_4 ( & V_5 , & V_4 -> V_10 ) ;
V_4 -> V_11 . V_12 = V_13 ;
F_4 ( & V_5 , & V_4 -> V_11 ) ;
V_7 = F_5 ( & V_2 -> V_14 , 0 , V_4 -> V_15 , V_4 ,
& V_5 ) ;
if ( V_7 ) {
F_6 ( V_16 , V_4 -> V_17 ) ;
F_7 () ;
} else {
F_8 ( & V_5 ) ;
}
}
void F_9 ( struct V_6 * V_18 )
{
struct V_19 * V_14 ;
int V_20 , V_21 , V_22 ;
T_1 V_23 ;
F_10 (dev, &pbus->devices, bus_list) {
V_21 = V_22 = 0 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
unsigned long V_25 = V_14 -> V_26 [ V_20 ] . V_12 ;
if ( V_25 & V_27 )
V_21 = 1 ;
else if ( V_25 & V_28 )
V_22 = 1 ;
}
if ( V_14 -> V_26 [ V_24 ] . V_29 != 0 ) {
V_14 -> V_26 [ V_24 ] . V_12 |=
V_30 ;
V_22 = 1 ;
}
F_11 ( V_18 , V_14 -> V_31 , V_32 , & V_23 ) ;
if ( V_21 && ! ( V_23 & V_33 ) ) {
#ifdef F_12
F_13 ( V_34 L_1 ,
F_14 ( V_14 ) ) ;
#endif
V_23 |= V_33 ;
F_15 ( V_18 , V_14 -> V_31 , V_32 ,
V_23 ) ;
}
if ( V_22 && ! ( V_23 & V_35 ) ) {
#ifdef F_12
F_13 ( V_34 L_2
L_3 , F_14 ( V_14 ) ) ;
#endif
V_23 |= V_35 ;
F_15 ( V_18 , V_14 -> V_31 , V_32 ,
V_23 ) ;
}
}
}
T_2 F_16 ( void * V_36 , const struct V_26 * V_37 ,
T_2 V_38 , T_2 V_39 )
{
return V_37 -> V_9 ;
}
int F_17 ( struct V_19 * V_14 , int V_40 )
{
return F_18 ( V_14 , V_40 ) ;
}
void F_19 ( unsigned long V_41 , const void * V_42 , unsigned long V_43 )
{
while ( V_43 ) {
V_43 -= 1 ;
F_20 ( * ( const char * ) V_42 , V_41 ) ;
V_42 += 1 ;
}
}
void F_21 ( unsigned long V_41 , const void * V_42 , unsigned long V_43 )
{
while ( V_43 ) {
V_43 -= 2 ;
F_22 ( * ( const short * ) V_42 , V_41 ) ;
V_42 += 2 ;
}
}
void F_23 ( unsigned long V_41 , const void * V_42 , unsigned long V_43 )
{
while ( V_43 ) {
V_43 -= 4 ;
F_24 ( * ( const long * ) V_42 , V_41 ) ;
V_42 += 4 ;
}
}
void F_25 ( unsigned long V_41 , void * V_44 , unsigned long V_43 )
{
while ( V_43 ) {
V_43 -= 1 ;
* ( unsigned char * ) V_44 = F_26 ( V_41 ) ;
V_44 += 1 ;
}
}
void F_27 ( unsigned long V_41 , void * V_44 , unsigned long V_43 )
{
while ( V_43 ) {
V_43 -= 2 ;
* ( unsigned short * ) V_44 = F_28 ( V_41 ) ;
V_44 += 2 ;
}
}
void F_29 ( unsigned long V_41 , void * V_44 , unsigned long V_43 )
{
while ( V_43 ) {
V_43 -= 4 ;
* ( unsigned long * ) V_44 = F_30 ( V_41 ) ;
V_44 += 4 ;
}
}
