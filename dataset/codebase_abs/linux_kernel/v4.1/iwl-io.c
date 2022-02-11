int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , int V_6 )
{
int V_7 = 0 ;
do {
if ( ( F_2 ( V_2 , V_3 ) & V_5 ) == ( V_4 & V_5 ) )
return V_7 ;
F_3 ( V_8 ) ;
V_7 += V_8 ;
} while ( V_7 < V_6 );
return - V_9 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 = 0x5a5a5a5a ;
unsigned long V_12 ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
V_11 = F_2 ( V_2 , V_10 ) ;
F_6 ( V_2 , & V_12 ) ;
}
return V_11 ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 )
{
unsigned long V_12 ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
F_8 ( V_2 , V_10 , V_11 ) ;
F_6 ( V_2 , & V_12 ) ;
}
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 ,
int V_6 )
{
int V_7 = 0 ;
do {
if ( ( F_4 ( V_2 , V_3 ) & V_5 ) == V_5 )
return V_7 ;
F_3 ( V_8 ) ;
V_7 += V_8 ;
} while ( V_7 < V_6 );
return - V_9 ;
}
T_1 F_10 ( struct V_1 * V_2 , T_1 V_13 )
{
T_1 V_14 = F_11 ( V_2 , V_13 ) ;
F_12 ( V_2 -> V_15 , V_13 , V_14 ) ;
return V_14 ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_14 )
{
F_14 ( V_2 -> V_15 , V_13 , V_14 ) ;
F_15 ( V_2 , V_13 , V_14 ) ;
}
T_1 F_16 ( struct V_1 * V_2 , T_1 V_13 )
{
unsigned long V_12 ;
T_1 V_14 = 0x5a5a5a5a ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
V_14 = F_10 ( V_2 , V_13 ) ;
F_6 ( V_2 , & V_12 ) ;
}
return V_14 ;
}
void F_17 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_14 )
{
unsigned long V_12 ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
F_13 ( V_2 , V_13 , V_14 ) ;
F_6 ( V_2 , & V_12 ) ;
}
}
int F_18 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , int V_6 )
{
int V_7 = 0 ;
do {
if ( ( F_16 ( V_2 , V_3 ) & V_5 ) == ( V_4 & V_5 ) )
return V_7 ;
F_3 ( V_8 ) ;
V_7 += V_8 ;
} while ( V_7 < V_6 );
return - V_9 ;
}
void F_19 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_5 )
{
unsigned long V_12 ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
F_13 ( V_2 , V_13 ,
F_10 ( V_2 , V_13 ) | V_5 ) ;
F_6 ( V_2 , & V_12 ) ;
}
}
void F_20 ( struct V_1 * V_2 , T_1 V_13 ,
T_1 V_4 , T_1 V_5 )
{
unsigned long V_12 ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
F_13 ( V_2 , V_13 ,
( F_10 ( V_2 , V_13 ) & V_5 ) | V_4 ) ;
F_6 ( V_2 , & V_12 ) ;
}
}
void F_21 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_5 )
{
unsigned long V_12 ;
T_1 V_14 ;
if ( F_5 ( V_2 , false , & V_12 ) ) {
V_14 = F_10 ( V_2 , V_13 ) ;
F_13 ( V_2 , V_13 , ( V_14 & ~ V_5 ) ) ;
F_6 ( V_2 , & V_12 ) ;
}
}
void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> V_17 != V_18 ) {
F_17 ( V_2 , V_19 ,
V_20 ) ;
F_17 ( V_2 , V_19 ,
V_21 ) ;
} else {
F_17 ( V_2 , V_22 ,
V_23 ) ;
F_17 ( V_2 , V_19 ,
V_20 ) ;
}
}
static const char * F_23 ( int V_24 )
{
#define F_24 ( T_2 ) case x: return #x
switch ( V_24 ) {
F_24 ( V_25 ) ;
F_24 ( V_26 ) ;
F_24 ( V_27 ) ;
F_24 ( V_28 ) ;
F_24 ( V_29 ) ;
F_24 ( V_30 ) ;
F_24 ( V_31 ) ;
F_24 ( V_32 ) ;
F_24 ( V_33 ) ;
default:
return L_1 ;
}
#undef F_24
}
int F_25 ( struct V_1 * V_2 , char * * V_34 )
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
#ifdef F_26
if ( V_34 ) {
int V_37 = 0 ;
T_3 V_38 = F_27 ( V_36 ) * 48 + 40 ;
* V_34 = F_28 ( V_38 , V_39 ) ;
if ( ! * V_34 )
return - V_40 ;
V_37 += F_29 ( * V_34 + V_37 , V_38 - V_37 ,
L_2 ) ;
for ( V_35 = 0 ; V_35 < F_27 ( V_36 ) ; V_35 ++ )
V_37 += F_29 ( * V_34 + V_37 , V_38 - V_37 ,
L_3 ,
F_23 ( V_36 [ V_35 ] ) ,
F_4 ( V_2 , V_36 [ V_35 ] ) ) ;
return V_37 ;
}
#endif
F_30 ( V_2 , L_2 ) ;
for ( V_35 = 0 ; V_35 < F_27 ( V_36 ) ; V_35 ++ )
F_30 ( V_2 , L_3 ,
F_23 ( V_36 [ V_35 ] ) ,
F_4 ( V_2 , V_36 [ V_35 ] ) ) ;
return 0 ;
}
