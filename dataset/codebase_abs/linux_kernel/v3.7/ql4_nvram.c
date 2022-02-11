static inline void F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
F_2 ( V_1 , F_3 ( V_3 ) ) ;
F_4 ( F_3 ( V_3 ) ) ;
F_5 ( 1 ) ;
}
static inline int F_6 ( struct V_2 * V_3 )
{
return F_7 ( V_3 ) ? V_4 : V_5 ;
}
static inline int F_8 ( struct V_2 * V_3 )
{
return F_7 ( V_3 ) ? V_6 :
V_7 ;
}
static inline int F_9 ( struct V_2 * V_3 )
{
return V_8 ;
}
static int F_10 ( struct V_2 * V_3 )
{
F_11 ( F_12 ( V_9 L_1 ) ) ;
V_3 -> V_10 = V_11 | 0x000f0000 ;
F_1 ( V_3 -> V_10 , V_3 ) ;
return 1 ;
}
static int F_13 ( struct V_2 * V_3 , int V_1 , int V_12 )
{
int V_13 ;
int V_14 ;
int V_15 ;
int V_16 ;
F_1 ( V_3 -> V_10 | V_17 , V_3 ) ;
F_1 ( V_3 -> V_10 | V_17 |
V_18 , V_3 ) ;
F_1 ( V_3 -> V_10 | V_17 |
V_19 , V_3 ) ;
V_14 = 1 << ( V_20 - 1 ) ;
V_16 = 0xffff ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
V_15 =
( V_1 & V_14 ) ? V_17 : V_21 ;
if ( V_16 != V_15 ) {
F_1 ( V_3 -> V_10 | V_15 , V_3 ) ;
V_16 = V_15 ;
}
F_1 ( V_3 -> V_10 | V_15 |
V_18 , V_3 ) ;
F_1 ( V_3 -> V_10 | V_15 |
V_19 , V_3 ) ;
V_1 = V_1 << 1 ;
}
V_14 = 1 << ( F_8 ( V_3 ) - 1 ) ;
V_16 = 0xffff ;
for ( V_13 = 0 ; V_13 < F_8 ( V_3 ) ; V_13 ++ ) {
V_15 = V_12 & V_14 ? V_17 :
V_21 ;
if ( V_16 != V_15 ) {
F_1 ( V_3 -> V_10 | V_15 , V_3 ) ;
V_16 = V_15 ;
}
F_1 ( V_3 -> V_10 | V_15 |
V_18 , V_3 ) ;
F_1 ( V_3 -> V_10 | V_15 |
V_19 , V_3 ) ;
V_12 = V_12 << 1 ;
}
return 1 ;
}
static int F_14 ( struct V_2 * V_3 )
{
V_3 -> V_10 = V_22 | 0x000f0000 ;
F_1 ( V_3 -> V_10 , V_3 ) ;
return 1 ;
}
static int F_15 ( struct V_2 * V_3 , unsigned short * V_23 )
{
int V_13 ;
int V_24 = 0 ;
int V_15 ;
for ( V_13 = 0 ; V_13 < F_9 ( V_3 ) ; V_13 ++ ) {
F_1 ( V_3 -> V_10 |
V_18 , V_3 ) ;
F_1 ( V_3 -> V_10 |
V_19 , V_3 ) ;
V_15 = ( F_16 ( F_3 ( V_3 ) ) & V_25 ) ? 1 : 0 ;
V_24 = ( V_24 << 1 ) | V_15 ;
}
* V_23 = V_24 ;
return 1 ;
}
static int F_17 ( int V_26 , T_2 * V_23 ,
struct V_2 * V_3 )
{
F_10 ( V_3 ) ;
F_13 ( V_3 , V_27 , V_26 ) ;
F_15 ( V_3 , V_23 ) ;
F_14 ( V_3 ) ;
return 1 ;
}
T_2 F_18 ( struct V_2 * V_3 , int V_28 )
{
T_2 V_29 = 0 ;
F_17 ( V_28 , & V_29 , V_3 ) ;
return V_29 ;
}
T_3 F_19 ( struct V_2 * V_3 , int V_28 )
{
T_2 V_29 = 0 ;
T_3 V_30 = 0 ;
int V_31 = 0 ;
if ( V_28 & 0x1 )
V_31 = ( V_28 - 1 ) / 2 ;
else
V_31 = V_28 / 2 ;
V_29 = F_20 ( F_18 ( V_3 , V_31 ) ) ;
if ( V_28 & 0x1 )
V_30 = ( T_3 ) ( ( V_29 & 0xff00 ) >> 8 ) ;
else
V_30 = ( T_3 ) ( ( V_29 & 0x00ff ) ) ;
return V_30 ;
}
int F_21 ( struct V_2 * V_3 )
{
int V_32 = V_33 ;
T_4 V_34 = 0 ;
T_1 V_31 ;
unsigned long V_35 ;
F_22 ( & V_3 -> V_36 , V_35 ) ;
for ( V_31 = 0 ; V_31 < F_6 ( V_3 ) ; V_31 ++ )
V_34 += F_18 ( V_3 , V_31 ) ;
F_23 ( & V_3 -> V_36 , V_35 ) ;
if ( V_34 == 0 )
V_32 = V_37 ;
return V_32 ;
}
int F_24 ( struct V_2 * V_3 , T_5 V_38 , T_5 V_39 )
{
T_1 V_23 ;
unsigned long V_35 ;
unsigned int V_40 = 30 ;
F_25 ( F_12 ( L_2
L_3 , V_3 -> V_41 , V_38 , V_39 ) ) ;
do {
F_22 ( & V_3 -> V_36 , V_35 ) ;
F_2 ( ( V_38 | V_39 ) , F_26 ( V_3 ) ) ;
V_23 = F_16 ( F_26 ( V_3 ) ) ;
F_23 ( & V_3 -> V_36 , V_35 ) ;
if ( ( V_23 & ( V_38 >> 16 ) ) == V_39 ) {
F_25 ( F_12 ( L_4
L_5 , V_3 -> V_41 ,
V_38 , V_39 ) ) ;
return V_37 ;
}
F_27 ( 1 ) ;
} while ( -- V_40 );
return V_33 ;
}
void F_28 ( struct V_2 * V_3 , T_5 V_38 )
{
unsigned long V_35 ;
F_22 ( & V_3 -> V_36 , V_35 ) ;
F_2 ( V_38 , F_26 ( V_3 ) ) ;
F_4 ( F_26 ( V_3 ) ) ;
F_23 ( & V_3 -> V_36 , V_35 ) ;
F_25 ( F_12 ( L_6 , V_3 -> V_41 ,
V_38 ) ) ;
}
int F_29 ( struct V_2 * V_3 , T_5 V_38 , T_5 V_39 )
{
T_1 V_23 ;
unsigned long V_35 ;
F_22 ( & V_3 -> V_36 , V_35 ) ;
F_2 ( ( V_38 | V_39 ) , F_26 ( V_3 ) ) ;
V_23 = F_16 ( F_26 ( V_3 ) ) ;
F_23 ( & V_3 -> V_36 , V_35 ) ;
if ( ( V_23 & ( V_38 >> 16 ) ) == V_39 ) {
F_25 ( F_12 ( L_7
L_8 , V_3 -> V_41 ,
V_38 , V_39 , V_23 ) ) ;
return 1 ;
}
return 0 ;
}
