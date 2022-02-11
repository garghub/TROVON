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
static inline T_1 F_9 ( T_2 V_1 )
{
F_2 ( ( V_1 > 0xff || V_1 < - 0x100 ) ,
V_3 L_1 ) ;
return ( V_1 & V_14 ) << V_15 ;
}
static inline T_1 F_10 ( T_1 V_1 )
{
F_2 ( V_1 & ~ V_16 , V_3 L_1 ) ;
return V_1 & V_16 ;
}
static inline T_1 F_11 ( T_1 V_1 )
{
F_2 ( V_1 & ~ V_17 , V_3 L_1 ) ;
return V_1 & V_17 ;
}
void T_3 (F_12)( T_1 * * V_18 , unsigned int V_19 , signed int V_20 ,
unsigned int V_21 )
{
if ( V_22 && V_19 <= 24 && V_19 != 5 )
F_13 ( V_18 , V_23 , V_21 , 28 , V_20 ) ;
else
F_13 ( V_18 , V_23 , V_21 , V_19 , V_20 ) ;
}
void T_3 (F_14)( struct V_24 * * V_25 , T_1 * V_26 , int V_27 )
{
( * V_25 ) -> V_26 = V_26 ;
( * V_25 ) -> V_25 = V_27 ;
( * V_25 ) ++ ;
}
int T_3 (F_15)( long V_26 )
{
#ifdef F_16
return ( ( ( V_26 ) & 0xffffffff00000000L ) == 0xffffffff00000000L ) ;
#else
return 1 ;
#endif
}
static int F_17 ( long V_28 )
{
#ifdef F_16
return ( ( ( ( V_28 + 0x800080008000L ) >> 48 ) & 0xffff ) ^ 0x8000 ) - 0x8000 ;
#else
return 0 ;
#endif
}
static int F_18 ( long V_28 )
{
#ifdef F_16
return ( ( ( ( V_28 + 0x80008000L ) >> 32 ) & 0xffff ) ^ 0x8000 ) - 0x8000 ;
#else
return 0 ;
#endif
}
int T_3 (F_19)( long V_28 )
{
return ( ( ( ( V_28 + 0x8000L ) >> 16 ) & 0xffff ) ^ 0x8000 ) - 0x8000 ;
}
int T_3 (F_20)( long V_28 )
{
return ( ( V_28 & 0xffff ) ^ 0x8000 ) - 0x8000 ;
}
void T_3 (F_21)( T_1 * * V_18 , unsigned int V_29 , long V_26 )
{
if ( ! T_3 ( F_15 ) ( V_26 ) ) {
T_3 ( V_30 ) ( V_18 , V_29 , F_17 ( V_26 ) ) ;
if ( F_18 ( V_26 ) )
T_3 ( V_31 ) ( V_18 , V_29 , V_29 , F_18 ( V_26 ) ) ;
if ( T_3 ( F_19 ( V_26 ) ) ) {
T_3 ( V_32 ) ( V_18 , V_29 , V_29 , 16 ) ;
T_3 (V_31)( V_18 , V_29 , V_29 ,
T_3 (F_19)( V_26 ) );
T_3 ( V_32 ) ( V_18 , V_29 , V_29 , 16 ) ;
} else
T_3 ( V_33 ) ( V_18 , V_29 , V_29 , 0 ) ;
} else
T_3 ( V_30 ) ( V_18 , V_29 , T_3 ( F_19 ( V_26 ) ) ) ;
}
void T_3 (F_22)( T_1 * * V_18 , unsigned int V_29 , long V_26 )
{
T_3 (F_21)( V_18 , V_29 , V_26 );
if ( T_3 ( F_20 ( V_26 ) ) ) {
if ( ! T_3 ( F_15 ) ( V_26 ) )
T_3 ( V_31 ) ( V_18 , V_29 , V_29 ,
T_3 ( F_20 ( V_26 ) ) ) ;
else
T_3 ( V_34 ) ( V_18 , V_29 , V_29 ,
T_3 ( F_20 ( V_26 ) ) ) ;
}
}
void T_3 (F_23)( struct V_35 * * V_36 , T_1 * V_26 , int V_27 )
{
( * V_36 ) -> V_26 = V_26 ;
( * V_36 ) -> type = V_37 ;
( * V_36 ) -> V_25 = V_27 ;
( * V_36 ) ++ ;
}
void T_3 (F_24)( struct V_35 * V_36 ,
struct V_24 * V_25 )
{
struct V_24 * V_38 ;
for (; V_36 -> V_25 != V_39 ; V_36 ++ )
for ( V_38 = V_25 ; V_38 -> V_25 != V_39 ; V_38 ++ )
if ( V_36 -> V_25 == V_38 -> V_25 )
F_25 ( V_36 , V_38 ) ;
}
void T_3 (F_26)( struct V_35 * V_36 , T_1 * V_40 , T_1 * V_41 ,
long V_42 )
{
for (; V_36 -> V_25 != V_39 ; V_36 ++ )
if ( V_36 -> V_26 >= V_40 && V_36 -> V_26 < V_41 )
V_36 -> V_26 += V_42 ;
}
void T_3 (F_27)( struct V_24 * V_25 , T_1 * V_40 , T_1 * V_41 ,
long V_42 )
{
for (; V_25 -> V_25 != V_39 ; V_25 ++ )
if ( V_25 -> V_26 >= V_40 && V_25 -> V_26 < V_41 )
V_25 -> V_26 += V_42 ;
}
void T_3 (F_28)( struct V_35 * V_36 , struct V_24 * V_25 ,
T_1 * V_40 , T_1 * V_41 , T_1 * V_43 )
{
long V_42 = ( long ) ( V_43 - V_40 ) ;
memcpy ( V_43 , V_40 , ( V_41 - V_40 ) * sizeof( T_1 ) ) ;
T_3 ( F_26 ( V_36 , V_40 , V_41 , V_42 ) ) ;
T_3 ( F_27 ( V_25 , V_40 , V_41 , V_42 ) ) ;
}
int T_3 (F_29)( struct V_35 * V_36 , T_1 * V_26 )
{
for (; V_36 -> V_25 != V_39 ; V_36 ++ ) {
if ( V_36 -> V_26 == V_26
&& ( V_36 -> type == V_37
|| V_36 -> type == V_44 ) )
return 1 ;
}
return 0 ;
}
void T_3 (F_30)( T_1 * * V_45 , struct V_35 * * V_46 , unsigned int V_47 ,
int V_27 )
{
F_23 ( V_46 , * V_45 , V_27 ) ;
T_3 ( V_48 ) ( V_45 , V_47 , 0 ) ;
}
void T_3 (F_31)( T_1 * * V_45 , struct V_35 * * V_46 , int V_27 )
{
F_23 ( V_46 , * V_45 , V_27 ) ;
T_3 ( V_49 ) ( V_45 , 0 ) ;
}
void T_3 (F_32)( T_1 * * V_45 , struct V_35 * * V_46 , unsigned int V_50 ,
unsigned int V_51 , int V_27 )
{
F_23 ( V_46 , * V_45 , V_27 ) ;
T_3 ( V_52 ) ( V_45 , V_50 , V_51 , 0 ) ;
}
void T_3 (F_33)( T_1 * * V_45 , struct V_35 * * V_46 , unsigned int V_47 ,
int V_27 )
{
F_23 ( V_46 , * V_45 , V_27 ) ;
T_3 ( V_53 ) ( V_45 , V_47 , 0 ) ;
}
void T_3 (F_34)( T_1 * * V_45 , struct V_35 * * V_46 , unsigned int V_47 ,
int V_27 )
{
F_23 ( V_46 , * V_45 , V_27 ) ;
T_3 ( V_54 ) ( V_45 , V_47 , 0 ) ;
}
void T_3 (F_35)( T_1 * * V_45 , struct V_35 * * V_46 , unsigned int V_55 ,
unsigned int V_56 , int V_27 )
{
F_23 ( V_46 , * V_45 , V_27 ) ;
T_3 ( V_57 ) ( V_45 , V_55 , V_56 , 0 ) ;
}
void T_3 (F_36)( T_1 * * V_45 , struct V_35 * * V_46 , unsigned int V_47 ,
int V_27 )
{
F_23 ( V_46 , * V_45 , V_27 ) ;
T_3 ( V_58 ) ( V_45 , V_47 , 0 ) ;
}
void T_3 (F_37)( T_1 * * V_45 , struct V_35 * * V_46 , unsigned int V_47 ,
int V_27 )
{
F_23 ( V_46 , * V_45 , V_27 ) ;
T_3 ( V_59 ) ( V_45 , V_47 , 0 ) ;
}
void T_3 (F_38)( T_1 * * V_45 , struct V_35 * * V_46 , unsigned int V_47 ,
int V_27 )
{
F_23 ( V_46 , * V_45 , V_27 ) ;
T_3 ( V_60 ) ( V_45 , V_47 , 0 ) ;
}
void T_3 (F_39)( T_1 * * V_45 , struct V_35 * * V_46 , unsigned int V_47 ,
unsigned int V_61 , int V_27 )
{
F_23 ( V_46 , * V_45 , V_27 ) ;
T_3 ( V_62 ) ( V_45 , V_47 , V_61 , 0 ) ;
}
void T_3 (F_40)( T_1 * * V_45 , struct V_35 * * V_46 , unsigned int V_47 ,
unsigned int V_61 , int V_27 )
{
F_23 ( V_46 , * V_45 , V_27 ) ;
T_3 ( V_63 ) ( V_45 , V_47 , V_61 , 0 ) ;
}
