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
void T_1 F_19 ( struct V_16 * V_11 , int V_39 )
{
#ifdef F_12
F_13 ( V_40 L_4 , V_39 ,
F_14 ( V_11 ) ) ;
#endif
F_20 ( V_11 , V_41 , V_39 ) ;
}
void F_21 ( unsigned long V_42 , const void * V_43 , unsigned long V_44 )
{
while ( V_44 ) {
V_44 -= 1 ;
F_22 ( * ( const char * ) V_43 , V_42 ) ;
V_43 += 1 ;
}
}
void F_23 ( unsigned long V_42 , const void * V_43 , unsigned long V_44 )
{
while ( V_44 ) {
V_44 -= 2 ;
F_24 ( * ( const short * ) V_43 , V_42 ) ;
V_43 += 2 ;
}
}
void F_25 ( unsigned long V_42 , const void * V_43 , unsigned long V_44 )
{
while ( V_44 ) {
V_44 -= 4 ;
F_26 ( * ( const long * ) V_43 , V_42 ) ;
V_43 += 4 ;
}
}
void F_27 ( unsigned long V_42 , void * V_45 , unsigned long V_44 )
{
while ( V_44 ) {
V_44 -= 1 ;
* ( unsigned char * ) V_45 = F_28 ( V_42 ) ;
V_45 += 1 ;
}
}
void F_29 ( unsigned long V_42 , void * V_45 , unsigned long V_44 )
{
while ( V_44 ) {
V_44 -= 2 ;
* ( unsigned short * ) V_45 = F_30 ( V_42 ) ;
V_45 += 2 ;
}
}
void F_31 ( unsigned long V_42 , void * V_45 , unsigned long V_44 )
{
while ( V_44 ) {
V_44 -= 4 ;
* ( unsigned long * ) V_45 = F_32 ( V_42 ) ;
V_45 += 4 ;
}
}
