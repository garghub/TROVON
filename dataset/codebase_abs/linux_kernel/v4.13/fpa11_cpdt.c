static inline void F_1 ( const unsigned int V_1 , const unsigned int T_1 * V_2 )
{
T_2 * V_3 = F_2 () ;
V_3 -> V_4 [ V_1 ] = V_5 ;
F_3 ( V_3 -> V_6 [ V_1 ] . V_7 , V_2 ) ;
}
static inline void F_4 ( const unsigned int V_1 , const unsigned int T_1 * V_2 )
{
T_2 * V_3 = F_2 () ;
unsigned int * V_8 ;
V_8 = ( unsigned int * ) & V_3 -> V_6 [ V_1 ] . V_9 ;
V_3 -> V_4 [ V_1 ] = V_10 ;
#ifdef F_5
F_3 ( V_8 [ 0 ] , & V_2 [ 0 ] ) ;
F_3 ( V_8 [ 1 ] , & V_2 [ 1 ] ) ;
#else
F_3 ( V_8 [ 0 ] , & V_2 [ 1 ] ) ;
F_3 ( V_8 [ 1 ] , & V_2 [ 0 ] ) ;
#endif
}
static inline void F_6 ( const unsigned int V_1 , const unsigned int T_1 * V_2 )
{
T_2 * V_3 = F_2 () ;
unsigned int * V_8 ;
V_8 = ( unsigned int * ) & V_3 -> V_6 [ V_1 ] . V_11 ;
V_3 -> V_4 [ V_1 ] = V_12 ;
F_3 ( V_8 [ 0 ] , & V_2 [ 0 ] ) ;
#ifdef F_5
F_3 ( V_8 [ 1 ] , & V_2 [ 1 ] ) ;
F_3 ( V_8 [ 2 ] , & V_2 [ 2 ] ) ;
#else
F_3 ( V_8 [ 1 ] , & V_2 [ 2 ] ) ;
F_3 ( V_8 [ 2 ] , & V_2 [ 1 ] ) ;
#endif
}
static inline void F_7 ( const unsigned int V_1 , const unsigned int T_1 * V_2 )
{
T_2 * V_3 = F_2 () ;
register unsigned int * V_8 ;
unsigned long V_13 ;
V_8 = ( unsigned int * ) & ( V_3 -> V_6 [ V_1 ] ) ;
F_3 ( V_13 , & V_2 [ 0 ] ) ;
V_3 -> V_4 [ V_1 ] = ( V_13 >> 14 ) & 0x00000003 ;
switch ( V_3 -> V_4 [ V_1 ] ) {
case V_5 :
case V_10 :
{
F_3 ( V_8 [ 0 ] , & V_2 [ 2 ] ) ;
F_3 ( V_8 [ 1 ] , & V_2 [ 1 ] ) ;
V_8 [ 2 ] = 0 ;
}
break;
#ifdef F_8
case V_12 :
{
F_3 ( V_8 [ 1 ] , & V_2 [ 2 ] ) ;
F_3 ( V_8 [ 2 ] , & V_2 [ 1 ] ) ;
V_8 [ 0 ] = ( V_13 & 0x80003fff ) ;
}
break;
#endif
}
}
static inline void F_9 ( struct V_14 * V_15 , const unsigned int V_1 , unsigned int T_1 * V_2 )
{
T_2 * V_3 = F_2 () ;
union {
T_3 V_16 ;
unsigned int V_17 [ 1 ] ;
} V_18 ;
switch ( V_3 -> V_4 [ V_1 ] ) {
case V_10 :
V_18 . V_16 = F_10 ( V_15 , V_3 -> V_6 [ V_1 ] . V_9 ) ;
break;
#ifdef F_8
case V_12 :
V_18 . V_16 = F_11 ( V_15 , V_3 -> V_6 [ V_1 ] . V_11 ) ;
break;
#endif
default:
V_18 . V_16 = V_3 -> V_6 [ V_1 ] . V_7 ;
}
F_12 ( V_18 . V_17 [ 0 ] , V_2 ) ;
}
static inline void F_13 ( struct V_14 * V_15 , const unsigned int V_1 , unsigned int T_1 * V_2 )
{
T_2 * V_3 = F_2 () ;
union {
T_4 V_16 ;
unsigned int V_17 [ 2 ] ;
} V_18 ;
switch ( V_3 -> V_4 [ V_1 ] ) {
case V_5 :
V_18 . V_16 = F_14 ( V_3 -> V_6 [ V_1 ] . V_7 ) ;
break;
#ifdef F_8
case V_12 :
V_18 . V_16 = F_15 ( V_15 , V_3 -> V_6 [ V_1 ] . V_11 ) ;
break;
#endif
default:
V_18 . V_16 = V_3 -> V_6 [ V_1 ] . V_9 ;
}
#ifdef F_5
F_12 ( V_18 . V_17 [ 0 ] , & V_2 [ 0 ] ) ;
F_12 ( V_18 . V_17 [ 1 ] , & V_2 [ 1 ] ) ;
#else
F_12 ( V_18 . V_17 [ 1 ] , & V_2 [ 0 ] ) ;
F_12 ( V_18 . V_17 [ 0 ] , & V_2 [ 1 ] ) ;
#endif
}
static inline void F_16 ( const unsigned int V_1 , unsigned int T_1 * V_2 )
{
T_2 * V_3 = F_2 () ;
union {
T_5 V_16 ;
unsigned int V_17 [ 3 ] ;
} V_18 ;
switch ( V_3 -> V_4 [ V_1 ] ) {
case V_5 :
V_18 . V_16 = F_17 ( V_3 -> V_6 [ V_1 ] . V_7 ) ;
break;
case V_10 :
V_18 . V_16 = F_18 ( V_3 -> V_6 [ V_1 ] . V_9 ) ;
break;
default:
V_18 . V_16 = V_3 -> V_6 [ V_1 ] . V_11 ;
}
F_12 ( V_18 . V_17 [ 0 ] , & V_2 [ 0 ] ) ;
#ifdef F_5
F_12 ( V_18 . V_17 [ 1 ] , & V_2 [ 1 ] ) ;
F_12 ( V_18 . V_17 [ 2 ] , & V_2 [ 2 ] ) ;
#else
F_12 ( V_18 . V_17 [ 1 ] , & V_2 [ 2 ] ) ;
F_12 ( V_18 . V_17 [ 2 ] , & V_2 [ 1 ] ) ;
#endif
}
static inline void F_19 ( const unsigned int V_1 , unsigned int T_1 * V_2 )
{
T_2 * V_3 = F_2 () ;
register unsigned int V_19 , * V_8 ;
V_8 = ( unsigned int * ) & ( V_3 -> V_6 [ V_1 ] ) ;
V_19 = V_3 -> V_4 [ V_1 ] ;
switch ( V_19 ) {
case V_5 :
case V_10 :
{
F_12 ( V_8 [ 0 ] , & V_2 [ 2 ] ) ;
F_12 ( V_8 [ 1 ] , & V_2 [ 1 ] ) ;
F_12 ( V_19 << 14 , & V_2 [ 0 ] ) ;
}
break;
#ifdef F_8
case V_12 :
{
F_12 ( V_8 [ 2 ] , & V_2 [ 1 ] ) ;
F_12 ( V_8 [ 1 ] , & V_2 [ 2 ] ) ;
F_12 ( ( V_8 [ 0 ] & 0x80003fff ) | ( V_19 << 14 ) , & V_2 [ 0 ] ) ;
}
break;
#endif
}
}
unsigned int F_20 ( const unsigned int V_20 )
{
unsigned int T_1 * V_21 , * V_22 , * V_23 ;
unsigned int V_24 = 1 , V_25 = F_21 ( V_20 ) ;
V_21 = ( unsigned int T_1 * ) F_22 ( F_23 ( V_20 ) ) ;
if ( V_26 == F_23 ( V_20 ) ) {
V_21 += 2 ;
V_25 = 0 ;
}
V_23 = V_21 ;
if ( F_24 ( V_20 ) )
V_23 += F_25 ( V_20 ) ;
else
V_23 -= F_25 ( V_20 ) ;
if ( F_26 ( V_20 ) )
V_22 = V_23 ;
else
V_22 = V_21 ;
switch ( V_20 & V_27 ) {
case V_28 :
F_1 ( F_27 ( V_20 ) , V_22 ) ;
break;
case V_29 :
F_4 ( F_27 ( V_20 ) , V_22 ) ;
break;
#ifdef F_8
case V_30 :
F_6 ( F_27 ( V_20 ) , V_22 ) ;
break;
#endif
default:
V_24 = 0 ;
}
if ( V_25 )
F_28 ( F_23 ( V_20 ) , ( unsigned long ) V_23 ) ;
return V_24 ;
}
unsigned int F_29 ( const unsigned int V_20 )
{
unsigned int T_1 * V_21 , * V_22 , * V_23 ;
unsigned int V_24 = 1 , V_25 = F_21 ( V_20 ) ;
struct V_14 V_15 ;
V_15 . V_31 = F_30 ( V_20 ) ;
V_15 . V_32 = F_31 ( V_20 ) ;
V_15 . V_33 = 0 ;
V_21 = ( unsigned int T_1 * ) F_22 ( F_23 ( V_20 ) ) ;
if ( V_26 == F_23 ( V_20 ) ) {
V_21 += 2 ;
V_25 = 0 ;
}
V_23 = V_21 ;
if ( F_24 ( V_20 ) )
V_23 += F_25 ( V_20 ) ;
else
V_23 -= F_25 ( V_20 ) ;
if ( F_26 ( V_20 ) )
V_22 = V_23 ;
else
V_22 = V_21 ;
switch ( V_20 & V_27 ) {
case V_28 :
F_9 ( & V_15 , F_27 ( V_20 ) , V_22 ) ;
break;
case V_29 :
F_13 ( & V_15 , F_27 ( V_20 ) , V_22 ) ;
break;
#ifdef F_8
case V_30 :
F_16 ( F_27 ( V_20 ) , V_22 ) ;
break;
#endif
default:
V_24 = 0 ;
}
if ( V_15 . V_33 )
F_32 ( V_15 . V_33 ) ;
if ( V_25 )
F_28 ( F_23 ( V_20 ) , ( unsigned long ) V_23 ) ;
return V_24 ;
}
unsigned int F_33 ( const unsigned int V_20 )
{
unsigned int T_1 * V_21 , * V_22 , * V_23 ;
unsigned int V_17 , V_34 , V_25 = F_21 ( V_20 ) ;
V_21 = ( unsigned int T_1 * ) F_22 ( F_23 ( V_20 ) ) ;
if ( V_26 == F_23 ( V_20 ) ) {
V_21 += 2 ;
V_25 = 0 ;
}
V_23 = V_21 ;
if ( F_24 ( V_20 ) )
V_23 += F_25 ( V_20 ) ;
else
V_23 -= F_25 ( V_20 ) ;
if ( F_26 ( V_20 ) )
V_22 = V_23 ;
else
V_22 = V_21 ;
V_34 = F_27 ( V_20 ) ;
for ( V_17 = F_34 ( V_20 ) ; V_17 > 0 ; V_17 -- ) {
F_7 ( V_34 , V_22 ) ;
V_22 += 3 ;
V_34 ++ ;
if ( V_34 == 8 )
V_34 = 0 ;
}
if ( V_25 )
F_28 ( F_23 ( V_20 ) , ( unsigned long ) V_23 ) ;
return 1 ;
}
unsigned int F_35 ( const unsigned int V_20 )
{
unsigned int T_1 * V_21 , * V_22 , * V_23 ;
unsigned int V_17 , V_34 , V_25 = F_21 ( V_20 ) ;
V_21 = ( unsigned int T_1 * ) F_22 ( F_23 ( V_20 ) ) ;
if ( V_26 == F_23 ( V_20 ) ) {
V_21 += 2 ;
V_25 = 0 ;
}
V_23 = V_21 ;
if ( F_24 ( V_20 ) )
V_23 += F_25 ( V_20 ) ;
else
V_23 -= F_25 ( V_20 ) ;
if ( F_26 ( V_20 ) )
V_22 = V_23 ;
else
V_22 = V_21 ;
V_34 = F_27 ( V_20 ) ;
for ( V_17 = F_34 ( V_20 ) ; V_17 > 0 ; V_17 -- ) {
F_19 ( V_34 , V_22 ) ;
V_22 += 3 ;
V_34 ++ ;
if ( V_34 == 8 )
V_34 = 0 ;
}
if ( V_25 )
F_28 ( F_23 ( V_20 ) , ( unsigned long ) V_23 ) ;
return 1 ;
}
unsigned int F_36 ( const unsigned int V_20 )
{
unsigned int V_24 = 0 ;
if ( F_37 ( V_20 ) ) {
V_24 = F_20 ( V_20 ) ;
} else if ( F_38 ( V_20 ) ) {
V_24 = F_33 ( V_20 ) ;
} else if ( F_39 ( V_20 ) ) {
V_24 = F_29 ( V_20 ) ;
} else if ( F_40 ( V_20 ) ) {
V_24 = F_35 ( V_20 ) ;
} else {
V_24 = 0 ;
}
return V_24 ;
}
