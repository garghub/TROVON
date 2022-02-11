static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_2 , V_3 , F_3 ( V_2 , V_3 ) | V_4 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_2 , V_3 , F_3 ( V_2 , V_3 ) & ~ V_4 ) ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned long V_5 ;
F_6 ( & V_2 -> V_6 , V_5 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
F_7 ( & V_2 -> V_6 , V_5 ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned long V_5 ;
F_6 ( & V_2 -> V_6 , V_5 ) ;
F_4 ( V_2 , V_3 , V_4 ) ;
F_7 ( & V_2 -> V_6 , V_5 ) ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_7 )
{
unsigned long V_5 ;
T_1 V_8 ;
#ifdef F_10
F_11 ( V_7 & ~ V_4 ) ;
#endif
F_6 ( & V_2 -> V_6 , V_5 ) ;
V_8 = F_3 ( V_2 , V_3 ) ;
V_8 &= ~ V_4 ;
V_8 |= V_7 ;
F_2 ( V_2 , V_3 , V_8 ) ;
F_7 ( & V_2 -> V_6 , V_5 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_9 ,
T_1 V_10 , T_1 V_4 , int V_11 )
{
int V_12 = 0 ;
do {
if ( ( F_3 ( V_2 , V_9 ) & V_4 ) == ( V_10 & V_4 ) )
return V_12 ;
F_13 ( V_13 ) ;
V_12 += V_13 ;
} while ( V_12 < V_11 );
return - V_14 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_15 ;
F_15 ( & V_2 -> V_6 ) ;
F_1 ( V_2 , V_16 ,
V_17 ) ;
V_15 = F_12 ( V_2 , V_16 ,
V_18 ,
( V_19 |
V_20 ) , 15000 ) ;
if ( V_15 < 0 ) {
F_2 ( V_2 , V_21 , V_22 ) ;
return - V_23 ;
}
return 0 ;
}
bool F_16 ( struct V_1 * V_2 )
{
int V_15 = F_14 ( V_2 ) ;
if ( F_17 ( V_15 ) ) {
T_1 V_24 = F_3 ( V_2 , V_16 ) ;
F_18 ( 1 , L_1
L_2 , V_24 ) ;
return false ;
}
return true ;
}
void F_19 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_6 ) ;
F_4 ( V_2 , V_16 ,
V_17 ) ;
F_20 () ;
}
T_1 F_21 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_7 ;
unsigned long V_5 ;
F_6 ( & V_2 -> V_6 , V_5 ) ;
F_16 ( V_2 ) ;
V_7 = F_3 ( V_2 , V_3 ) ;
F_19 ( V_2 ) ;
F_7 ( & V_2 -> V_6 , V_5 ) ;
return V_7 ;
}
void F_22 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 )
{
unsigned long V_5 ;
F_6 ( & V_2 -> V_6 , V_5 ) ;
if ( F_23 ( F_16 ( V_2 ) ) ) {
F_2 ( V_2 , V_3 , V_7 ) ;
F_19 ( V_2 ) ;
}
F_7 ( & V_2 -> V_6 , V_5 ) ;
}
int F_24 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_4 ,
int V_11 )
{
int V_12 = 0 ;
do {
if ( ( F_21 ( V_2 , V_9 ) & V_4 ) == V_4 )
return V_12 ;
F_13 ( V_13 ) ;
V_12 += V_13 ;
} while ( V_12 < V_11 );
return - V_14 ;
}
static inline T_1 F_25 ( struct V_1 * V_2 , T_1 V_25 )
{
T_1 V_24 = F_26 ( V_2 , V_25 ) ;
F_27 ( V_2 -> V_26 , V_25 , V_24 ) ;
return V_24 ;
}
static inline void F_28 ( struct V_1 * V_2 , T_1 V_25 , T_1 V_24 )
{
F_29 ( V_2 -> V_26 , V_25 , V_24 ) ;
F_30 ( V_2 , V_25 , V_24 ) ;
}
T_1 F_31 ( struct V_1 * V_2 , T_1 V_25 )
{
unsigned long V_5 ;
T_1 V_24 ;
F_6 ( & V_2 -> V_6 , V_5 ) ;
F_16 ( V_2 ) ;
V_24 = F_25 ( V_2 , V_25 ) ;
F_19 ( V_2 ) ;
F_7 ( & V_2 -> V_6 , V_5 ) ;
return V_24 ;
}
void F_32 ( struct V_1 * V_2 , T_1 V_25 , T_1 V_24 )
{
unsigned long V_5 ;
F_6 ( & V_2 -> V_6 , V_5 ) ;
if ( F_23 ( F_16 ( V_2 ) ) ) {
F_28 ( V_2 , V_25 , V_24 ) ;
F_19 ( V_2 ) ;
}
F_7 ( & V_2 -> V_6 , V_5 ) ;
}
void F_33 ( struct V_1 * V_2 , T_1 V_25 , T_1 V_4 )
{
unsigned long V_5 ;
F_6 ( & V_2 -> V_6 , V_5 ) ;
if ( F_23 ( F_16 ( V_2 ) ) ) {
F_28 ( V_2 , V_25 ,
F_25 ( V_2 , V_25 ) | V_4 ) ;
F_19 ( V_2 ) ;
}
F_7 ( & V_2 -> V_6 , V_5 ) ;
}
void F_34 ( struct V_1 * V_2 , T_1 V_25 ,
T_1 V_10 , T_1 V_4 )
{
unsigned long V_5 ;
F_6 ( & V_2 -> V_6 , V_5 ) ;
if ( F_23 ( F_16 ( V_2 ) ) ) {
F_28 ( V_2 , V_25 ,
( F_25 ( V_2 , V_25 ) & V_4 ) | V_10 ) ;
F_19 ( V_2 ) ;
}
F_7 ( & V_2 -> V_6 , V_5 ) ;
}
void F_35 ( struct V_1 * V_2 , T_1 V_25 , T_1 V_4 )
{
unsigned long V_5 ;
T_1 V_24 ;
F_6 ( & V_2 -> V_6 , V_5 ) ;
if ( F_23 ( F_16 ( V_2 ) ) ) {
V_24 = F_25 ( V_2 , V_25 ) ;
F_28 ( V_2 , V_25 , ( V_24 & ~ V_4 ) ) ;
F_19 ( V_2 ) ;
}
F_7 ( & V_2 -> V_6 , V_5 ) ;
}
void F_36 ( struct V_1 * V_2 , T_1 V_9 ,
void * V_27 , int V_28 )
{
unsigned long V_5 ;
int V_29 ;
T_1 * V_30 = V_27 ;
F_6 ( & V_2 -> V_6 , V_5 ) ;
if ( F_23 ( F_16 ( V_2 ) ) ) {
F_2 ( V_2 , V_31 , V_9 ) ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
V_30 [ V_29 ] = F_3 ( V_2 , V_32 ) ;
F_19 ( V_2 ) ;
}
F_7 ( & V_2 -> V_6 , V_5 ) ;
}
T_1 F_37 ( struct V_1 * V_2 , T_1 V_9 )
{
T_1 V_7 ;
F_36 ( V_2 , V_9 , & V_7 , 1 ) ;
return V_7 ;
}
int F_38 ( struct V_1 * V_2 , T_1 V_9 ,
const void * V_27 , int V_28 )
{
unsigned long V_5 ;
int V_29 , V_33 = 0 ;
const T_1 * V_30 = V_27 ;
F_6 ( & V_2 -> V_6 , V_5 ) ;
if ( F_23 ( F_16 ( V_2 ) ) ) {
F_2 ( V_2 , V_34 , V_9 ) ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
F_2 ( V_2 , V_35 , V_30 [ V_29 ] ) ;
F_19 ( V_2 ) ;
} else
V_33 = - V_36 ;
F_7 ( & V_2 -> V_6 , V_5 ) ;
return V_33 ;
}
int F_39 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_24 )
{
return F_38 ( V_2 , V_9 , & V_24 , 1 ) ;
}
