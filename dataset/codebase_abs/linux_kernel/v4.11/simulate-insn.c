static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_2 , V_3 , V_4 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_2 , V_3 , F_4 ( V_4 ) ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , int V_3 )
{
return F_6 ( V_2 , V_3 ) ;
}
static inline T_2 F_7 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( F_6 ( V_2 , V_3 ) ) ;
}
static bool T_3 F_8 ( T_2 V_5 , struct V_1 * V_2 )
{
int V_6 = V_5 & 0x1f ;
return ( V_5 & ( 1 << 31 ) ) ?
( F_5 ( V_2 , V_6 ) == 0 ) : ( F_7 ( V_2 , V_6 ) == 0 ) ;
}
static bool T_3 F_9 ( T_2 V_5 , struct V_1 * V_2 )
{
int V_6 = V_5 & 0x1f ;
return ( V_5 & ( 1 << 31 ) ) ?
( F_5 ( V_2 , V_6 ) != 0 ) : ( F_7 ( V_2 , V_6 ) != 0 ) ;
}
static bool T_3 F_10 ( T_2 V_5 , struct V_1 * V_2 )
{
int V_6 = V_5 & 0x1f ;
int V_7 = ( ( V_5 & ( 1 << 31 ) ) >> 26 ) | ( ( V_5 >> 19 ) & 0x1f ) ;
return ( ( F_5 ( V_2 , V_6 ) >> V_7 ) & 0x1 ) == 0 ;
}
static bool T_3 F_11 ( T_2 V_5 , struct V_1 * V_2 )
{
int V_6 = V_5 & 0x1f ;
int V_7 = ( ( V_5 & ( 1 << 31 ) ) >> 26 ) | ( ( V_5 >> 19 ) & 0x1f ) ;
return ( ( F_5 ( V_2 , V_6 ) >> V_7 ) & 0x1 ) != 0 ;
}
void T_3
F_12 ( T_2 V_5 , long V_8 , struct V_1 * V_2 )
{
long V_9 , V_6 , V_4 ;
V_6 = V_5 & 0x1f ;
V_9 = ( ( V_5 >> 3 ) & 0x1ffffc ) | ( ( V_5 >> 29 ) & 0x3 ) ;
V_9 = F_13 ( V_9 , 20 ) ;
if ( V_5 & 0x80000000 )
V_4 = ( V_9 << 12 ) + ( V_8 & 0xfffffffffffff000 ) ;
else
V_4 = V_9 + V_8 ;
F_1 ( V_2 , V_6 , V_4 ) ;
F_14 ( V_2 , F_15 ( V_2 ) + 4 ) ;
}
void T_3
F_16 ( T_2 V_5 , long V_8 , struct V_1 * V_2 )
{
int V_10 = F_17 ( V_5 ) ;
if ( V_5 & ( 1 << 31 ) )
F_1 ( V_2 , 30 , V_8 + 4 ) ;
F_14 ( V_2 , V_8 + V_10 ) ;
}
void T_3
F_18 ( T_2 V_5 , long V_8 , struct V_1 * V_2 )
{
int V_10 = 4 ;
if ( V_11 [ V_5 & 0xf ] ( V_2 -> V_12 & 0xffffffff ) )
V_10 = F_19 ( V_5 ) ;
F_14 ( V_2 , V_8 + V_10 ) ;
}
void T_3
F_20 ( T_2 V_5 , long V_8 , struct V_1 * V_2 )
{
int V_6 = ( V_5 >> 5 ) & 0x1f ;
F_14 ( V_2 , F_5 ( V_2 , V_6 ) ) ;
if ( ( ( V_5 >> 21 ) & 0x3 ) == 1 )
F_1 ( V_2 , 30 , V_8 + 4 ) ;
}
void T_3
F_21 ( T_2 V_5 , long V_8 , struct V_1 * V_2 )
{
int V_10 = 4 ;
if ( V_5 & ( 1 << 24 ) ) {
if ( F_9 ( V_5 , V_2 ) )
V_10 = F_22 ( V_5 ) ;
} else {
if ( F_8 ( V_5 , V_2 ) )
V_10 = F_22 ( V_5 ) ;
}
F_14 ( V_2 , V_8 + V_10 ) ;
}
void T_3
F_23 ( T_2 V_5 , long V_8 , struct V_1 * V_2 )
{
int V_10 = 4 ;
if ( V_5 & ( 1 << 24 ) ) {
if ( F_11 ( V_5 , V_2 ) )
V_10 = F_24 ( V_5 ) ;
} else {
if ( F_10 ( V_5 , V_2 ) )
V_10 = F_24 ( V_5 ) ;
}
F_14 ( V_2 , V_8 + V_10 ) ;
}
void T_3
F_25 ( T_2 V_5 , long V_8 , struct V_1 * V_2 )
{
T_1 * V_13 ;
int V_6 = V_5 & 0x1f ;
int V_10 ;
V_10 = F_26 ( V_5 ) ;
V_13 = ( T_1 * ) ( V_8 + V_10 ) ;
if ( V_5 & ( 1 << 30 ) )
F_1 ( V_2 , V_6 , * V_13 ) ;
else
F_3 ( V_2 , V_6 , * V_13 ) ;
F_14 ( V_2 , F_15 ( V_2 ) + 4 ) ;
}
void T_3
F_27 ( T_2 V_5 , long V_8 , struct V_1 * V_2 )
{
T_4 * V_13 ;
int V_6 = V_5 & 0x1f ;
int V_10 ;
V_10 = F_26 ( V_5 ) ;
V_13 = ( T_4 * ) ( V_8 + V_10 ) ;
F_1 ( V_2 , V_6 , * V_13 ) ;
F_14 ( V_2 , F_15 ( V_2 ) + 4 ) ;
}
