void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
F_3 ( V_2 , V_3 , V_4 ) ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_5 ( V_2 -> V_5 , V_3 , V_4 ) ;
F_6 ( V_2 , V_3 , V_4 ) ;
}
T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_8 ( V_2 , V_3 ) ;
F_9 ( V_2 -> V_5 , V_3 , V_4 ) ;
return V_4 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 , int V_9 )
{
int V_10 = 0 ;
do {
if ( ( F_7 ( V_2 , V_6 ) & V_8 ) == ( V_7 & V_8 ) )
return V_10 ;
F_11 ( V_11 ) ;
V_10 += V_11 ;
} while ( V_10 < V_9 );
return - V_12 ;
}
T_1 F_12 ( struct V_1 * V_2 , T_1 V_13 )
{
T_1 V_14 = 0x5a5a5a5a ;
unsigned long V_15 ;
if ( F_13 ( V_2 , & V_15 ) ) {
V_14 = F_7 ( V_2 , V_13 ) ;
F_14 ( V_2 , & V_15 ) ;
}
return V_14 ;
}
void F_15 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_14 )
{
unsigned long V_15 ;
if ( F_13 ( V_2 , & V_15 ) ) {
F_4 ( V_2 , V_13 , V_14 ) ;
F_14 ( V_2 , & V_15 ) ;
}
}
int F_16 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_8 ,
int V_9 )
{
int V_10 = 0 ;
do {
if ( ( F_12 ( V_2 , V_6 ) & V_8 ) == V_8 )
return V_10 ;
F_11 ( V_11 ) ;
V_10 += V_11 ;
} while ( V_10 < V_9 );
return - V_12 ;
}
T_1 F_17 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_18 ( V_2 , V_3 ) ;
F_19 ( V_2 -> V_5 , V_3 , V_4 ) ;
return V_4 ;
}
void F_20 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_21 ( V_2 -> V_5 , V_3 , V_4 ) ;
F_22 ( V_2 , V_3 , V_4 ) ;
}
T_1 F_23 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_15 ;
T_1 V_4 = 0x5a5a5a5a ;
if ( F_13 ( V_2 , & V_15 ) ) {
V_4 = F_17 ( V_2 , V_3 ) ;
F_14 ( V_2 , & V_15 ) ;
}
return V_4 ;
}
void F_24 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned long V_15 ;
if ( F_13 ( V_2 , & V_15 ) ) {
F_20 ( V_2 , V_3 , V_4 ) ;
F_14 ( V_2 , & V_15 ) ;
}
}
int F_25 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 , int V_9 )
{
int V_10 = 0 ;
do {
if ( ( F_23 ( V_2 , V_6 ) & V_8 ) == ( V_7 & V_8 ) )
return V_10 ;
F_11 ( V_11 ) ;
V_10 += V_11 ;
} while ( V_10 < V_9 );
return - V_12 ;
}
void F_26 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
unsigned long V_15 ;
if ( F_13 ( V_2 , & V_15 ) ) {
F_20 ( V_2 , V_3 ,
F_17 ( V_2 , V_3 ) |
V_8 ) ;
F_14 ( V_2 , & V_15 ) ;
}
}
void F_27 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_7 , T_1 V_8 )
{
unsigned long V_15 ;
if ( F_13 ( V_2 , & V_15 ) ) {
F_20 ( V_2 , V_3 ,
( F_17 ( V_2 , V_3 ) &
V_8 ) | V_7 ) ;
F_14 ( V_2 , & V_15 ) ;
}
}
void F_28 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
unsigned long V_15 ;
T_1 V_4 ;
if ( F_13 ( V_2 , & V_15 ) ) {
V_4 = F_17 ( V_2 , V_3 ) ;
F_20 ( V_2 , V_3 , ( V_4 & ~ V_8 ) ) ;
F_14 ( V_2 , & V_15 ) ;
}
}
void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> V_17 != V_18 ) {
F_24 ( V_2 , V_19 ,
V_20 ) ;
F_24 ( V_2 , V_19 ,
V_21 ) ;
} else {
F_24 ( V_2 , V_22 ,
V_23 ) ;
F_24 ( V_2 , V_19 ,
V_20 ) ;
}
}
static const char * F_30 ( int V_24 )
{
#define F_31 ( T_3 ) case x: return #x
switch ( V_24 ) {
F_31 ( V_25 ) ;
F_31 ( V_26 ) ;
F_31 ( V_27 ) ;
F_31 ( V_28 ) ;
F_31 ( V_29 ) ;
F_31 ( V_30 ) ;
F_31 ( V_31 ) ;
F_31 ( V_32 ) ;
F_31 ( V_33 ) ;
default:
return L_1 ;
}
#undef F_31
}
int F_32 ( struct V_1 * V_2 , char * * V_34 )
{
int V_35 ;
static const T_1 V_36 [] = {
V_25 ,
V_26 ,
V_27 ,
V_28 ,
V_29 ,
V_30 ,
V_31 ,
V_32 ,
V_33
} ;
#ifdef F_33
if ( V_34 ) {
int V_37 = 0 ;
T_4 V_38 = F_34 ( V_36 ) * 48 + 40 ;
* V_34 = F_35 ( V_38 , V_39 ) ;
if ( ! * V_34 )
return - V_40 ;
V_37 += F_36 ( * V_34 + V_37 , V_38 - V_37 ,
L_2 ) ;
for ( V_35 = 0 ; V_35 < F_34 ( V_36 ) ; V_35 ++ )
V_37 += F_36 ( * V_34 + V_37 , V_38 - V_37 ,
L_3 ,
F_30 ( V_36 [ V_35 ] ) ,
F_12 ( V_2 , V_36 [ V_35 ] ) ) ;
return V_37 ;
}
#endif
F_37 ( V_2 , L_2 ) ;
for ( V_35 = 0 ; V_35 < F_34 ( V_36 ) ; V_35 ++ )
F_37 ( V_2 , L_3 ,
F_30 ( V_36 [ V_35 ] ) ,
F_12 ( V_2 , V_36 [ V_35 ] ) ) ;
return 0 ;
}
