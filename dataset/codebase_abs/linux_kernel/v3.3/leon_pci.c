void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_5 ) ;
struct V_6 * V_7 ;
F_3 ( & V_5 , & V_4 -> V_8 ) ;
F_3 ( & V_5 , & V_4 -> V_9 ) ;
V_7 = F_4 ( & V_2 -> V_10 , 0 , V_4 -> V_11 , V_4 ,
& V_5 ) ;
if ( V_7 ) {
F_5 ( V_12 , V_4 -> V_13 ) ;
F_6 () ;
} else {
F_7 ( & V_5 ) ;
}
}
void F_8 ( struct V_14 * V_10 , struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 = V_10 -> V_19 -> V_20 ;
V_16 -> V_21 = V_18 -> V_21 ;
V_16 -> V_22 = V_18 -> V_22 ;
if ( V_18 -> V_23 & V_24 ) {
V_16 -> V_21 -= ( V_4 -> V_8 . V_21 - 0x1000 ) ;
V_16 -> V_22 -= ( V_4 -> V_8 . V_21 - 0x1000 ) ;
}
}
void F_9 ( struct V_14 * V_10 , struct V_17 * V_18 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = V_10 -> V_19 -> V_20 ;
V_18 -> V_21 = V_16 -> V_21 ;
V_18 -> V_22 = V_16 -> V_22 ;
if ( V_18 -> V_23 & V_24 ) {
V_18 -> V_21 += ( V_4 -> V_8 . V_21 - 0x1000 ) ;
V_18 -> V_22 += ( V_4 -> V_8 . V_21 - 0x1000 ) ;
}
}
void T_1 F_10 ( struct V_6 * V_25 )
{
struct V_3 * V_4 = V_25 -> V_20 ;
struct V_14 * V_10 ;
int V_26 , V_27 , V_28 ;
T_2 V_29 ;
F_11 (dev, &pbus->devices, bus_list) {
V_27 = V_28 = 0 ;
for ( V_26 = 0 ; V_26 < V_30 ; V_26 ++ ) {
unsigned long V_31 = V_10 -> V_17 [ V_26 ] . V_23 ;
if ( V_31 & V_24 )
V_27 = 1 ;
else if ( V_31 & V_32 )
V_28 = 1 ;
}
if ( V_10 -> V_17 [ V_30 ] . V_22 != 0 ) {
V_10 -> V_17 [ V_30 ] . V_23 |=
V_33 ;
V_28 = 1 ;
}
F_12 ( V_25 , V_10 -> V_34 , V_35 , & V_29 ) ;
if ( V_27 && ! ( V_29 & V_36 ) ) {
#ifdef F_13
F_14 ( V_37 L_1 ,
F_15 ( V_10 ) ) ;
#endif
V_29 |= V_36 ;
F_16 ( V_25 , V_10 -> V_34 , V_35 ,
V_29 ) ;
}
if ( V_28 && ! ( V_29 & V_38 ) ) {
#ifdef F_13
F_14 ( V_37 L_2
L_3 , F_15 ( V_10 ) ) ;
#endif
V_29 |= V_38 ;
F_16 ( V_25 , V_10 -> V_34 , V_35 ,
V_29 ) ;
}
}
}
char * T_1 F_17 ( char * V_39 )
{
return V_39 ;
}
T_3 F_18 ( void * V_40 , const struct V_17 * V_18 ,
T_3 V_41 , T_3 V_42 )
{
return V_18 -> V_21 ;
}
int F_19 ( struct V_14 * V_10 , int V_43 )
{
return F_20 ( V_10 , V_43 ) ;
}
struct V_44 * F_21 ( struct V_14 * V_45 )
{
return NULL ;
}
void T_1 F_22 ( struct V_14 * V_10 , int V_46 )
{
#ifdef F_13
F_14 ( V_47 L_4 , V_46 ,
F_15 ( V_10 ) ) ;
#endif
F_23 ( V_10 , V_48 , V_46 ) ;
}
void F_24 ( unsigned long V_49 , const void * V_50 , unsigned long V_51 )
{
while ( V_51 ) {
V_51 -= 1 ;
F_25 ( * ( const char * ) V_50 , V_49 ) ;
V_50 += 1 ;
}
}
void F_26 ( unsigned long V_49 , const void * V_50 , unsigned long V_51 )
{
while ( V_51 ) {
V_51 -= 2 ;
F_27 ( * ( const short * ) V_50 , V_49 ) ;
V_50 += 2 ;
}
}
void F_28 ( unsigned long V_49 , const void * V_50 , unsigned long V_51 )
{
while ( V_51 ) {
V_51 -= 4 ;
F_29 ( * ( const long * ) V_50 , V_49 ) ;
V_50 += 4 ;
}
}
void F_30 ( unsigned long V_49 , void * V_52 , unsigned long V_51 )
{
while ( V_51 ) {
V_51 -= 1 ;
* ( unsigned char * ) V_52 = F_31 ( V_49 ) ;
V_52 += 1 ;
}
}
void F_32 ( unsigned long V_49 , void * V_52 , unsigned long V_51 )
{
while ( V_51 ) {
V_51 -= 2 ;
* ( unsigned short * ) V_52 = F_33 ( V_49 ) ;
V_52 += 2 ;
}
}
void F_34 ( unsigned long V_49 , void * V_52 , unsigned long V_51 )
{
while ( V_51 ) {
V_51 -= 4 ;
* ( unsigned long * ) V_52 = F_35 ( V_49 ) ;
V_52 += 4 ;
}
}
