static inline T_1 F_1 ( T_1 V_1 )
{
F_2 ( V_1 & ~ V_2 , V_3 L_1 ) ;
return ( V_1 & V_2 ) << V_4 ;
}
static inline T_1 F_3 ( T_1 V_1 )
{
F_2 ( V_1 & ~ V_5 , V_3 L_1 ) ;
return ( V_1 & V_5 ) << V_6 ;
}
static inline T_1 F_4 ( T_1 V_1 )
{
F_2 ( V_1 & ~ V_7 , V_3 L_1 ) ;
return ( V_1 & V_7 ) << V_8 ;
}
static inline T_1 F_5 ( T_1 V_1 )
{
F_2 ( V_1 & ~ V_9 , V_3 L_1 ) ;
return ( V_1 & V_9 ) << V_10 ;
}
static inline T_1 F_6 ( T_2 V_1 )
{
F_2 ( V_1 > 0x7fff || V_1 < - 0x8000 ,
V_3 L_1 ) ;
return V_1 & 0xffff ;
}
static inline T_1 F_7 ( T_1 V_1 )
{
F_2 ( V_1 & ~ V_11 , V_3 L_1 ) ;
return V_1 & V_11 ;
}
static inline T_1 F_8 ( T_1 V_1 )
{
F_2 ( V_1 & ~ V_12 ,
V_3 L_1 ) ;
return ( V_1 & V_12 ) << V_13 ;
}
static inline T_1 F_9 ( T_1 V_1 )
{
F_2 ( V_1 & ~ V_14 , V_3 L_1 ) ;
return V_1 & V_14 ;
}
static inline T_1 F_10 ( T_1 V_1 )
{
F_2 ( V_1 & ~ V_15 , V_3 L_1 ) ;
return V_1 & V_15 ;
}
void T_3 (F_11)( T_1 * * V_16 , unsigned int V_17 , signed int V_18 ,
unsigned int V_19 )
{
if ( F_12 ( V_20 ) && V_17 <= 24 && V_17 != 5 )
F_13 ( V_16 , V_21 , V_19 , 28 , V_18 ) ;
else
F_13 ( V_16 , V_21 , V_19 , V_17 , V_18 ) ;
}
void T_3 (F_14)( struct V_22 * * V_23 , T_1 * V_24 , int V_25 )
{
( * V_23 ) -> V_24 = V_24 ;
( * V_23 ) -> V_23 = V_25 ;
( * V_23 ) ++ ;
}
int T_3 (F_15)( long V_24 )
{
#ifdef F_16
return ( ( ( V_24 ) & 0xffffffff00000000L ) == 0xffffffff00000000L ) ;
#else
return 1 ;
#endif
}
static int F_17 ( long V_26 )
{
#ifdef F_16
return ( ( ( ( V_26 + 0x800080008000L ) >> 48 ) & 0xffff ) ^ 0x8000 ) - 0x8000 ;
#else
return 0 ;
#endif
}
static int F_18 ( long V_26 )
{
#ifdef F_16
return ( ( ( ( V_26 + 0x80008000L ) >> 32 ) & 0xffff ) ^ 0x8000 ) - 0x8000 ;
#else
return 0 ;
#endif
}
int T_3 (F_19)( long V_26 )
{
return ( ( ( ( V_26 + 0x8000L ) >> 16 ) & 0xffff ) ^ 0x8000 ) - 0x8000 ;
}
int T_3 (F_20)( long V_26 )
{
return ( ( V_26 & 0xffff ) ^ 0x8000 ) - 0x8000 ;
}
void T_3 (F_21)( T_1 * * V_16 , unsigned int V_27 , long V_24 )
{
if ( ! T_3 ( F_15 ) ( V_24 ) ) {
T_3 ( V_28 ) ( V_16 , V_27 , F_17 ( V_24 ) ) ;
if ( F_18 ( V_24 ) )
T_3 ( V_29 ) ( V_16 , V_27 , V_27 , F_18 ( V_24 ) ) ;
if ( T_3 ( F_19 ( V_24 ) ) ) {
T_3 ( V_30 ) ( V_16 , V_27 , V_27 , 16 ) ;
T_3 (V_29)( V_16 , V_27 , V_27 ,
T_3 (F_19)( V_24 ) );
T_3 ( V_30 ) ( V_16 , V_27 , V_27 , 16 ) ;
} else
T_3 ( V_31 ) ( V_16 , V_27 , V_27 , 0 ) ;
} else
T_3 ( V_28 ) ( V_16 , V_27 , T_3 ( F_19 ( V_24 ) ) ) ;
}
void T_3 (F_22)( T_1 * * V_16 , unsigned int V_27 , long V_24 )
{
T_3 (F_21)( V_16 , V_27 , V_24 );
if ( T_3 ( F_20 ( V_24 ) ) ) {
if ( ! T_3 ( F_15 ) ( V_24 ) )
T_3 ( V_29 ) ( V_16 , V_27 , V_27 ,
T_3 ( F_20 ( V_24 ) ) ) ;
else
T_3 ( V_32 ) ( V_16 , V_27 , V_27 ,
T_3 ( F_20 ( V_24 ) ) ) ;
}
}
void T_3 (F_23)( struct V_33 * * V_34 , T_1 * V_24 , int V_25 )
{
( * V_34 ) -> V_24 = V_24 ;
( * V_34 ) -> type = V_35 ;
( * V_34 ) -> V_23 = V_25 ;
( * V_34 ) ++ ;
}
void T_3 (F_24)( struct V_33 * V_34 ,
struct V_22 * V_23 )
{
struct V_22 * V_36 ;
for (; V_34 -> V_23 != V_37 ; V_34 ++ )
for ( V_36 = V_23 ; V_36 -> V_23 != V_37 ; V_36 ++ )
if ( V_34 -> V_23 == V_36 -> V_23 )
F_25 ( V_34 , V_36 ) ;
}
void T_3 (F_26)( struct V_33 * V_34 , T_1 * V_38 , T_1 * V_39 ,
long V_40 )
{
for (; V_34 -> V_23 != V_37 ; V_34 ++ )
if ( V_34 -> V_24 >= V_38 && V_34 -> V_24 < V_39 )
V_34 -> V_24 += V_40 ;
}
void T_3 (F_27)( struct V_22 * V_23 , T_1 * V_38 , T_1 * V_39 ,
long V_40 )
{
for (; V_23 -> V_23 != V_37 ; V_23 ++ )
if ( V_23 -> V_24 >= V_38 && V_23 -> V_24 < V_39 )
V_23 -> V_24 += V_40 ;
}
void T_3 (F_28)( struct V_33 * V_34 , struct V_22 * V_23 ,
T_1 * V_38 , T_1 * V_39 , T_1 * V_41 )
{
long V_40 = ( long ) ( V_41 - V_38 ) ;
memcpy ( V_41 , V_38 , ( V_39 - V_38 ) * sizeof( T_1 ) ) ;
T_3 ( F_26 ( V_34 , V_38 , V_39 , V_40 ) ) ;
T_3 ( F_27 ( V_23 , V_38 , V_39 , V_40 ) ) ;
}
int T_3 (F_29)( struct V_33 * V_34 , T_1 * V_24 )
{
for (; V_34 -> V_23 != V_37 ; V_34 ++ ) {
if ( V_34 -> V_24 == V_24
&& ( V_34 -> type == V_35
|| V_34 -> type == V_42 ) )
return 1 ;
}
return 0 ;
}
void T_3 (F_30)( T_1 * * V_43 , struct V_33 * * V_44 , unsigned int V_45 ,
int V_25 )
{
F_23 ( V_44 , * V_43 , V_25 ) ;
T_3 ( V_46 ) ( V_43 , V_45 , 0 ) ;
}
void T_3 (F_31)( T_1 * * V_43 , struct V_33 * * V_44 , int V_25 )
{
F_23 ( V_44 , * V_43 , V_25 ) ;
T_3 ( V_47 ) ( V_43 , 0 ) ;
}
void T_3 (F_32)( T_1 * * V_43 , struct V_33 * * V_44 , unsigned int V_48 ,
unsigned int V_49 , int V_25 )
{
F_23 ( V_44 , * V_43 , V_25 ) ;
T_3 ( V_50 ) ( V_43 , V_48 , V_49 , 0 ) ;
}
void T_3 (F_33)( T_1 * * V_43 , struct V_33 * * V_44 , unsigned int V_45 ,
int V_25 )
{
F_23 ( V_44 , * V_43 , V_25 ) ;
T_3 ( V_51 ) ( V_43 , V_45 , 0 ) ;
}
void T_3 (F_34)( T_1 * * V_43 , struct V_33 * * V_44 , unsigned int V_45 ,
int V_25 )
{
F_23 ( V_44 , * V_43 , V_25 ) ;
T_3 ( V_52 ) ( V_43 , V_45 , 0 ) ;
}
void T_3 (F_35)( T_1 * * V_43 , struct V_33 * * V_44 , unsigned int V_53 ,
unsigned int V_54 , int V_25 )
{
F_23 ( V_44 , * V_43 , V_25 ) ;
T_3 ( V_55 ) ( V_43 , V_53 , V_54 , 0 ) ;
}
void T_3 (F_36)( T_1 * * V_43 , struct V_33 * * V_44 , unsigned int V_45 ,
int V_25 )
{
F_23 ( V_44 , * V_43 , V_25 ) ;
T_3 ( V_56 ) ( V_43 , V_45 , 0 ) ;
}
void T_3 (F_37)( T_1 * * V_43 , struct V_33 * * V_44 , unsigned int V_45 ,
int V_25 )
{
F_23 ( V_44 , * V_43 , V_25 ) ;
T_3 ( V_57 ) ( V_43 , V_45 , 0 ) ;
}
void T_3 (F_38)( T_1 * * V_43 , struct V_33 * * V_44 , unsigned int V_45 ,
int V_25 )
{
F_23 ( V_44 , * V_43 , V_25 ) ;
T_3 ( V_58 ) ( V_43 , V_45 , 0 ) ;
}
void T_3 (F_39)( T_1 * * V_43 , struct V_33 * * V_44 , unsigned int V_45 ,
unsigned int V_59 , int V_25 )
{
F_23 ( V_44 , * V_43 , V_25 ) ;
T_3 ( V_60 ) ( V_43 , V_45 , V_59 , 0 ) ;
}
void T_3 (F_40)( T_1 * * V_43 , struct V_33 * * V_44 , unsigned int V_45 ,
unsigned int V_59 , int V_25 )
{
F_23 ( V_44 , * V_43 , V_25 ) ;
T_3 ( V_61 ) ( V_43 , V_45 , V_59 , 0 ) ;
}
