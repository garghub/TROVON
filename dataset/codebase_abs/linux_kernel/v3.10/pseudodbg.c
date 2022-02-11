static const char * F_1 ( int V_1 , int V_2 )
{
return V_3 [ ( V_1 << 3 ) | V_2 ] ;
}
static bool F_2 ( struct V_4 * V_5 , long * V_6 , int V_1 , int V_2 )
{
long * V_7 = & V_5 -> V_8 ;
unsigned long V_9 ;
if ( V_1 == 5 ||
( V_1 == 4 && ( V_2 == 4 || V_2 == 5 ) ) ||
( V_1 == 7 ) )
return false ;
if ( V_1 == 0 || ( V_1 == 1 && V_2 < 6 ) )
V_7 -= ( V_2 + 8 * V_1 ) ;
else if ( V_1 == 1 && V_2 == 6 )
V_7 = & V_5 -> V_10 ;
else if ( V_1 == 1 && V_2 == 7 )
V_7 = & V_5 -> V_5 ;
else if ( V_1 == 2 ) {
V_7 = & V_5 -> V_11 ;
V_7 -= V_2 ;
} else if ( V_1 == 3 && V_2 >= 4 ) {
V_7 = & V_5 -> V_12 ;
V_7 -= ( V_2 - 4 ) ;
} else if ( V_1 == 3 && V_2 < 4 ) {
V_7 = & V_5 -> V_13 ;
V_7 -= V_2 ;
} else if ( V_1 == 4 && V_2 < 4 ) {
V_7 = & V_5 -> V_14 ;
V_7 -= V_2 ;
} else if ( V_1 == 4 && V_2 == 6 )
V_7 = & V_5 -> V_15 ;
else if ( V_1 == 4 && V_2 == 7 )
V_7 = & V_5 -> V_16 ;
else if ( V_1 == 6 && V_2 < 6 ) {
V_7 = & V_5 -> V_17 ;
V_7 -= V_2 ;
} else if ( V_1 == 6 && V_2 == 6 ) {
__asm__ __volatile__("%0 = cycles;\n" : "=d"(tmp));
V_7 = & V_9 ;
} else if ( V_1 == 6 && V_2 == 7 ) {
__asm__ __volatile__("%0 = cycles2;\n" : "=d"(tmp));
V_7 = & V_9 ;
}
* V_6 = * V_7 ;
return true ;
}
bool F_3 ( struct V_4 * V_5 , unsigned int V_18 )
{
int V_19 = ( ( V_18 >> V_20 ) & V_21 ) ;
int V_22 = ( ( V_18 >> ( V_23 ) ) & V_24 ) ;
int V_1 = ( ( V_18 >> ( V_25 ) ) & V_26 ) ;
int V_27 = ( ( V_18 >> ( V_28 ) ) & V_29 ) ;
long V_6 ;
if ( ( V_18 & 0xFF000000 ) != V_30 )
return false ;
if ( ! F_2 ( V_5 , & V_6 , V_1 , V_27 ) )
return false ;
if ( V_22 == 0 || V_22 == 2 ) {
if ( V_19 != ( V_6 & 0xFFFF ) ) {
F_4 ( L_1 ,
F_1 ( V_1 , V_27 ) ,
V_19 , ( unsigned int ) ( V_6 & 0xFFFF ) ) ;
return false ;
}
} else if ( V_22 == 1 || V_22 == 3 ) {
if ( V_19 != ( ( V_6 >> 16 ) & 0xFFFF ) ) {
F_4 ( L_2 ,
F_1 ( V_1 , V_27 ) ,
V_19 , ( unsigned int ) ( ( V_6 >> 16 ) & 0xFFFF ) ) ;
return false ;
}
}
V_5 -> V_31 += 4 ;
return true ;
}
bool F_5 ( struct V_4 * V_5 , unsigned int V_18 )
{
int V_1 , V_32 , V_2 ;
long V_6 , V_33 ;
if ( ( V_18 & 0xFF000000 ) != V_34 )
return false ;
V_18 >>= 16 ;
V_1 = ( ( V_18 >> V_35 ) & V_36 ) ;
V_32 = ( ( V_18 >> V_37 ) & V_38 ) ;
V_2 = ( ( V_18 >> V_39 ) & V_36 ) ;
if ( V_32 == 3 && ( V_2 == 0 || V_2 == 1 ) ) {
if ( ! F_2 ( V_5 , & V_6 , 4 , 2 * V_2 ) )
return false ;
if ( ! F_2 ( V_5 , & V_33 , 4 , 2 * V_2 + 1 ) )
return false ;
F_4 ( L_3 , V_2 , V_6 & 0xFF , V_33 ) ;
V_5 -> V_31 += 2 ;
return true ;
} else if ( V_32 == 0 ) {
if ( ! F_2 ( V_5 , & V_6 , V_1 , V_2 ) )
return false ;
F_4 ( L_4 , F_1 ( V_1 , V_2 ) , V_6 ) ;
V_5 -> V_31 += 2 ;
return true ;
}
return false ;
}
