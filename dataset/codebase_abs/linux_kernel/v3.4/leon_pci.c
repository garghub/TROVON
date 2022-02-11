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
char * T_1 F_16 ( char * V_34 )
{
return V_34 ;
}
T_3 F_17 ( void * V_35 , const struct V_23 * V_36 ,
T_3 V_37 , T_3 V_38 )
{
return V_36 -> V_9 ;
}
int F_18 ( struct V_16 * V_11 , int V_39 )
{
return F_19 ( V_11 , V_39 ) ;
}
void T_1 F_20 ( struct V_16 * V_11 , int V_40 )
{
#ifdef F_12
F_13 ( V_41 L_4 , V_40 ,
F_14 ( V_11 ) ) ;
#endif
F_21 ( V_11 , V_42 , V_40 ) ;
}
void F_22 ( unsigned long V_43 , const void * V_44 , unsigned long V_45 )
{
while ( V_45 ) {
V_45 -= 1 ;
F_23 ( * ( const char * ) V_44 , V_43 ) ;
V_44 += 1 ;
}
}
void F_24 ( unsigned long V_43 , const void * V_44 , unsigned long V_45 )
{
while ( V_45 ) {
V_45 -= 2 ;
F_25 ( * ( const short * ) V_44 , V_43 ) ;
V_44 += 2 ;
}
}
void F_26 ( unsigned long V_43 , const void * V_44 , unsigned long V_45 )
{
while ( V_45 ) {
V_45 -= 4 ;
F_27 ( * ( const long * ) V_44 , V_43 ) ;
V_44 += 4 ;
}
}
void F_28 ( unsigned long V_43 , void * V_46 , unsigned long V_45 )
{
while ( V_45 ) {
V_45 -= 1 ;
* ( unsigned char * ) V_46 = F_29 ( V_43 ) ;
V_46 += 1 ;
}
}
void F_30 ( unsigned long V_43 , void * V_46 , unsigned long V_45 )
{
while ( V_45 ) {
V_45 -= 2 ;
* ( unsigned short * ) V_46 = F_31 ( V_43 ) ;
V_46 += 2 ;
}
}
void F_32 ( unsigned long V_43 , void * V_46 , unsigned long V_45 )
{
while ( V_45 ) {
V_45 -= 4 ;
* ( unsigned long * ) V_46 = F_33 ( V_43 ) ;
V_46 += 4 ;
}
}
