static inline unsigned char F_1 ( void )
{
unsigned char V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_1 = ( F_3 ( V_4 ) & V_5 ) ;
F_4 ( & V_3 , V_2 ) ;
return V_1 ;
}
unsigned int F_5 ( struct V_6 * time )
{
unsigned char V_7 ;
unsigned long V_2 ;
unsigned char V_8 = 0 ;
#ifdef F_6
unsigned int V_9 ;
#endif
if ( F_1 () )
F_7 ( 20 ) ;
F_2 ( & V_3 , V_2 ) ;
time -> V_10 = F_3 ( V_11 ) ;
time -> V_12 = F_3 ( V_13 ) ;
time -> V_14 = F_3 ( V_15 ) ;
time -> V_16 = F_3 ( V_17 ) ;
time -> V_18 = F_3 ( V_19 ) ;
time -> V_20 = F_3 ( V_21 ) ;
#ifdef F_6
V_9 = F_3 ( V_22 ) ;
#endif
#ifdef F_8
if ( V_23 . V_24 . V_25 >= V_26 &&
V_23 . V_8 )
V_8 = F_3 ( V_23 . V_8 ) ;
#endif
V_7 = F_3 ( V_27 ) ;
F_4 ( & V_3 , V_2 ) ;
if ( ! ( V_7 & V_28 ) || V_29 )
{
time -> V_10 = F_9 ( time -> V_10 ) ;
time -> V_12 = F_9 ( time -> V_12 ) ;
time -> V_14 = F_9 ( time -> V_14 ) ;
time -> V_16 = F_9 ( time -> V_16 ) ;
time -> V_18 = F_9 ( time -> V_18 ) ;
time -> V_20 = F_9 ( time -> V_20 ) ;
V_8 = F_9 ( V_8 ) ;
}
#ifdef F_6
time -> V_20 += V_9 - 72 ;
#endif
if ( V_8 )
time -> V_20 += ( V_8 - 19 ) * 100 ;
if ( time -> V_20 <= 69 )
time -> V_20 += 100 ;
time -> V_18 -- ;
return V_30 ;
}
int F_10 ( struct V_6 * time )
{
unsigned long V_2 ;
unsigned char V_31 , V_32 , V_33 , V_34 , V_35 ;
unsigned char V_36 , V_37 ;
unsigned int V_38 ;
#ifdef F_6
unsigned int V_39 , V_40 ;
#endif
unsigned char V_8 = 0 ;
V_38 = time -> V_20 ;
V_31 = time -> V_18 + 1 ;
V_32 = time -> V_16 ;
V_33 = time -> V_14 ;
V_34 = time -> V_12 ;
V_35 = time -> V_10 ;
if ( V_38 > 255 )
return - V_41 ;
F_2 ( & V_3 , V_2 ) ;
#ifdef F_6
V_39 = V_38 ;
V_40 = ( ( ! ( ( V_38 + 1900 ) % 4 ) && ( ( V_38 + 1900 ) % 100 ) ) ||
! ( ( V_38 + 1900 ) % 400 ) ) ;
V_38 = 72 ;
if ( ! V_40 && V_31 < 3 ) {
V_39 -- ;
V_38 = 73 ;
}
#endif
#ifdef F_8
if ( V_23 . V_24 . V_25 >= V_26 &&
V_23 . V_8 ) {
V_8 = ( V_38 + 1900 ) / 100 ;
V_38 %= 100 ;
}
#endif
if ( V_38 > 169 ) {
F_4 ( & V_3 , V_2 ) ;
return - V_41 ;
}
if ( V_38 >= 100 )
V_38 -= 100 ;
if ( ! ( F_3 ( V_27 ) & V_28 )
|| V_29 ) {
V_35 = F_11 ( V_35 ) ;
V_34 = F_11 ( V_34 ) ;
V_33 = F_11 ( V_33 ) ;
V_32 = F_11 ( V_32 ) ;
V_31 = F_11 ( V_31 ) ;
V_38 = F_11 ( V_38 ) ;
V_8 = F_11 ( V_8 ) ;
}
V_36 = F_3 ( V_27 ) ;
F_12 ( ( V_36 | V_42 ) , V_27 ) ;
V_37 = F_3 ( V_4 ) ;
F_12 ( ( V_37 | V_43 ) , V_4 ) ;
#ifdef F_6
F_12 ( V_39 , V_22 ) ;
#endif
F_12 ( V_38 , V_21 ) ;
F_12 ( V_31 , V_19 ) ;
F_12 ( V_32 , V_17 ) ;
F_12 ( V_33 , V_15 ) ;
F_12 ( V_34 , V_13 ) ;
F_12 ( V_35 , V_11 ) ;
#ifdef F_8
if ( V_23 . V_24 . V_25 >= V_26 &&
V_23 . V_8 )
F_12 ( V_8 , V_23 . V_8 ) ;
#endif
F_12 ( V_36 , V_27 ) ;
F_12 ( V_37 , V_4 ) ;
F_4 ( & V_3 , V_2 ) ;
return 0 ;
}
