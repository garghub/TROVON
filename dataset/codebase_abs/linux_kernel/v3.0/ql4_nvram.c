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
int F_19 ( struct V_2 * V_3 )
{
int V_30 = V_31 ;
T_3 V_32 = 0 ;
T_1 V_33 ;
unsigned long V_34 ;
F_20 ( & V_3 -> V_35 , V_34 ) ;
for ( V_33 = 0 ; V_33 < F_6 ( V_3 ) ; V_33 ++ )
V_32 += F_18 ( V_3 , V_33 ) ;
F_21 ( & V_3 -> V_35 , V_34 ) ;
if ( V_32 == 0 )
V_30 = V_36 ;
return V_30 ;
}
int F_22 ( struct V_2 * V_3 , T_4 V_37 , T_4 V_38 )
{
T_1 V_23 ;
unsigned long V_34 ;
unsigned int V_39 = 30 ;
F_23 ( F_12 ( L_2
L_3 , V_3 -> V_40 , V_37 , V_38 ) ) ;
do {
F_20 ( & V_3 -> V_35 , V_34 ) ;
F_2 ( ( V_37 | V_38 ) , F_24 ( V_3 ) ) ;
V_23 = F_16 ( F_24 ( V_3 ) ) ;
F_21 ( & V_3 -> V_35 , V_34 ) ;
if ( ( V_23 & ( V_37 >> 16 ) ) == V_38 ) {
F_23 ( F_12 ( L_4
L_5 , V_3 -> V_40 ,
V_37 , V_38 ) ) ;
return V_36 ;
}
F_25 ( 1 ) ;
} while ( -- V_39 );
return V_31 ;
}
void F_26 ( struct V_2 * V_3 , T_4 V_37 )
{
unsigned long V_34 ;
F_20 ( & V_3 -> V_35 , V_34 ) ;
F_2 ( V_37 , F_24 ( V_3 ) ) ;
F_4 ( F_24 ( V_3 ) ) ;
F_21 ( & V_3 -> V_35 , V_34 ) ;
F_23 ( F_12 ( L_6 , V_3 -> V_40 ,
V_37 ) ) ;
}
int F_27 ( struct V_2 * V_3 , T_4 V_37 , T_4 V_38 )
{
T_1 V_23 ;
unsigned long V_34 ;
F_20 ( & V_3 -> V_35 , V_34 ) ;
F_2 ( ( V_37 | V_38 ) , F_24 ( V_3 ) ) ;
V_23 = F_16 ( F_24 ( V_3 ) ) ;
F_21 ( & V_3 -> V_35 , V_34 ) ;
if ( ( V_23 & ( V_37 >> 16 ) ) == V_38 ) {
F_23 ( F_12 ( L_7
L_8 , V_3 -> V_40 ,
V_37 , V_38 , V_23 ) ) ;
return 1 ;
}
return 0 ;
}
