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
void F_12 ( T_1 * * V_18 , unsigned int V_19 , signed int V_20 ,
unsigned int V_21 )
{
if ( V_22 && V_19 <= 24 && V_19 != 5 )
F_13 ( V_18 , V_23 , V_21 , 28 , V_20 ) ;
else
F_13 ( V_18 , V_23 , V_21 , V_19 , V_20 ) ;
}
void F_14 ( struct V_24 * * V_25 , T_1 * V_26 , int V_27 )
{
( * V_25 ) -> V_26 = V_26 ;
( * V_25 ) -> V_25 = V_27 ;
( * V_25 ) ++ ;
}
int F_15 ( long V_26 )
{
return V_26 == ( int ) V_26 ;
}
static int F_16 ( long V_28 )
{
#ifdef F_17
return ( ( ( ( V_28 + 0x800080008000L ) >> 48 ) & 0xffff ) ^ 0x8000 ) - 0x8000 ;
#else
return 0 ;
#endif
}
static int F_18 ( long V_28 )
{
#ifdef F_17
return ( ( ( ( V_28 + 0x80008000L ) >> 32 ) & 0xffff ) ^ 0x8000 ) - 0x8000 ;
#else
return 0 ;
#endif
}
int F_19 ( long V_28 )
{
return ( ( ( ( V_28 + 0x8000L ) >> 16 ) & 0xffff ) ^ 0x8000 ) - 0x8000 ;
}
int F_20 ( long V_28 )
{
return ( ( V_28 & 0xffff ) ^ 0x8000 ) - 0x8000 ;
}
void F_21 ( T_1 * * V_18 , unsigned int V_29 , long V_26 )
{
if ( ! F_15 ( V_26 ) ) {
F_22 ( V_18 , V_29 , F_16 ( V_26 ) ) ;
if ( F_18 ( V_26 ) )
F_23 ( V_18 , V_29 , V_29 , F_18 ( V_26 ) ) ;
if ( F_19 ( V_26 ) ) {
F_24 ( V_18 , V_29 , V_29 , 16 ) ;
F_23 ( V_18 , V_29 , V_29 ,
F_19 ( V_26 ) ) ;
F_24 ( V_18 , V_29 , V_29 , 16 ) ;
} else
F_25 ( V_18 , V_29 , V_29 , 0 ) ;
} else
F_22 ( V_18 , V_29 , F_19 ( V_26 ) ) ;
}
void F_26 ( T_1 * * V_18 , unsigned int V_29 , long V_26 )
{
F_21 ( V_18 , V_29 , V_26 ) ;
if ( F_20 ( V_26 ) ) {
if ( ! F_15 ( V_26 ) )
F_23 ( V_18 , V_29 , V_29 ,
F_20 ( V_26 ) ) ;
else
F_27 ( V_18 , V_29 , V_29 ,
F_20 ( V_26 ) ) ;
}
}
void F_28 ( struct V_30 * * V_31 , T_1 * V_26 , int V_27 )
{
( * V_31 ) -> V_26 = V_26 ;
( * V_31 ) -> type = V_32 ;
( * V_31 ) -> V_25 = V_27 ;
( * V_31 ) ++ ;
}
void F_29 ( struct V_30 * V_31 ,
struct V_24 * V_25 )
{
struct V_24 * V_33 ;
for (; V_31 -> V_25 != V_34 ; V_31 ++ )
for ( V_33 = V_25 ; V_33 -> V_25 != V_34 ; V_33 ++ )
if ( V_31 -> V_25 == V_33 -> V_25 )
F_30 ( V_31 , V_33 ) ;
}
void F_31 ( struct V_30 * V_31 , T_1 * V_35 , T_1 * V_36 ,
long V_37 )
{
for (; V_31 -> V_25 != V_34 ; V_31 ++ )
if ( V_31 -> V_26 >= V_35 && V_31 -> V_26 < V_36 )
V_31 -> V_26 += V_37 ;
}
void F_32 ( struct V_24 * V_25 , T_1 * V_35 , T_1 * V_36 ,
long V_37 )
{
for (; V_25 -> V_25 != V_34 ; V_25 ++ )
if ( V_25 -> V_26 >= V_35 && V_25 -> V_26 < V_36 )
V_25 -> V_26 += V_37 ;
}
void F_33 ( struct V_30 * V_31 , struct V_24 * V_25 ,
T_1 * V_35 , T_1 * V_36 , T_1 * V_38 )
{
long V_37 = ( long ) ( V_38 - V_35 ) ;
memcpy ( V_38 , V_35 , ( V_36 - V_35 ) * sizeof( T_1 ) ) ;
F_31 ( V_31 , V_35 , V_36 , V_37 ) ;
F_32 ( V_25 , V_35 , V_36 , V_37 ) ;
}
int F_34 ( struct V_30 * V_31 , T_1 * V_26 )
{
for (; V_31 -> V_25 != V_34 ; V_31 ++ ) {
if ( V_31 -> V_26 == V_26
&& ( V_31 -> type == V_32
|| V_31 -> type == V_39 ) )
return 1 ;
}
return 0 ;
}
void F_35 ( T_1 * * V_40 , struct V_30 * * V_41 , unsigned int V_42 ,
int V_27 )
{
F_28 ( V_41 , * V_40 , V_27 ) ;
F_36 ( V_40 , V_42 , 0 ) ;
}
void F_37 ( T_1 * * V_40 , struct V_30 * * V_41 , int V_27 )
{
F_28 ( V_41 , * V_40 , V_27 ) ;
F_38 ( V_40 , 0 ) ;
}
void F_39 ( T_1 * * V_40 , struct V_30 * * V_41 , unsigned int V_43 ,
unsigned int V_44 , int V_27 )
{
F_28 ( V_41 , * V_40 , V_27 ) ;
F_40 ( V_40 , V_43 , V_44 , 0 ) ;
}
void F_41 ( T_1 * * V_40 , struct V_30 * * V_41 , unsigned int V_42 ,
int V_27 )
{
F_28 ( V_41 , * V_40 , V_27 ) ;
F_42 ( V_40 , V_42 , 0 ) ;
}
void F_43 ( T_1 * * V_40 , struct V_30 * * V_41 , unsigned int V_42 ,
int V_27 )
{
F_28 ( V_41 , * V_40 , V_27 ) ;
F_44 ( V_40 , V_42 , 0 ) ;
}
void F_45 ( T_1 * * V_40 , struct V_30 * * V_41 , unsigned int V_45 ,
unsigned int V_46 , int V_27 )
{
F_28 ( V_41 , * V_40 , V_27 ) ;
F_46 ( V_40 , V_45 , V_46 , 0 ) ;
}
void F_47 ( T_1 * * V_40 , struct V_30 * * V_41 , unsigned int V_42 ,
int V_27 )
{
F_28 ( V_41 , * V_40 , V_27 ) ;
F_48 ( V_40 , V_42 , 0 ) ;
}
void F_49 ( T_1 * * V_40 , struct V_30 * * V_41 , unsigned int V_42 ,
int V_27 )
{
F_28 ( V_41 , * V_40 , V_27 ) ;
F_50 ( V_40 , V_42 , 0 ) ;
}
void F_51 ( T_1 * * V_40 , struct V_30 * * V_41 , unsigned int V_42 ,
int V_27 )
{
F_28 ( V_41 , * V_40 , V_27 ) ;
F_52 ( V_40 , V_42 , 0 ) ;
}
void F_53 ( T_1 * * V_40 , struct V_30 * * V_41 , unsigned int V_42 ,
unsigned int V_47 , int V_27 )
{
F_28 ( V_41 , * V_40 , V_27 ) ;
F_54 ( V_40 , V_42 , V_47 , 0 ) ;
}
void F_55 ( T_1 * * V_40 , struct V_30 * * V_41 , unsigned int V_42 ,
unsigned int V_47 , int V_27 )
{
F_28 ( V_41 , * V_40 , V_27 ) ;
F_56 ( V_40 , V_42 , V_47 , 0 ) ;
}
