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
void F_7 ( struct V_1 * V_2 , T_3 V_3 , T_3 V_4 )
{
F_8 ( V_2 -> V_5 , V_3 , V_4 ) ;
F_6 ( V_2 , V_3 , F_9 ( V_4 ) ) ;
F_6 ( V_2 , V_3 + 4 , F_10 ( V_4 ) ) ;
}
T_1 F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_12 ( V_2 , V_3 ) ;
F_13 ( V_2 -> V_5 , V_3 , V_4 ) ;
return V_4 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 , int V_9 )
{
int V_10 = 0 ;
do {
if ( ( F_11 ( V_2 , V_6 ) & V_8 ) == ( V_7 & V_8 ) )
return V_10 ;
F_15 ( V_11 ) ;
V_10 += V_11 ;
} while ( V_10 < V_9 );
return - V_12 ;
}
T_1 F_16 ( struct V_1 * V_2 , T_1 V_13 )
{
T_1 V_14 = 0x5a5a5a5a ;
unsigned long V_15 ;
if ( F_17 ( V_2 , & V_15 ) ) {
V_14 = F_11 ( V_2 , V_13 ) ;
F_18 ( V_2 , & V_15 ) ;
}
return V_14 ;
}
void F_19 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_14 )
{
unsigned long V_15 ;
if ( F_17 ( V_2 , & V_15 ) ) {
F_4 ( V_2 , V_13 , V_14 ) ;
F_18 ( V_2 , & V_15 ) ;
}
}
void F_20 ( struct V_1 * V_2 , T_3 V_13 , T_3 V_14 )
{
unsigned long V_15 ;
if ( F_17 ( V_2 , & V_15 ) ) {
F_7 ( V_2 , V_13 , V_14 ) ;
F_18 ( V_2 , & V_15 ) ;
}
}
int F_21 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_8 ,
int V_9 )
{
int V_10 = 0 ;
do {
if ( ( F_16 ( V_2 , V_6 ) & V_8 ) == V_8 )
return V_10 ;
F_15 ( V_11 ) ;
V_10 += V_11 ;
} while ( V_10 < V_9 );
return - V_12 ;
}
T_1 F_22 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_23 ( V_2 , V_3 ) ;
F_24 ( V_2 -> V_5 , V_3 , V_4 ) ;
return V_4 ;
}
void F_25 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_26 ( V_2 -> V_5 , V_3 , V_4 ) ;
F_27 ( V_2 , V_3 , V_4 ) ;
}
void F_28 ( struct V_1 * V_2 , T_3 V_3 , T_3 V_4 )
{
F_29 ( V_2 -> V_5 , V_3 , V_4 ) ;
F_25 ( V_2 , V_3 , V_4 & 0xffffffff ) ;
F_25 ( V_2 , V_3 + 4 , V_4 >> 32 ) ;
}
T_1 F_30 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_15 ;
T_1 V_4 = 0x5a5a5a5a ;
if ( F_17 ( V_2 , & V_15 ) ) {
V_4 = F_22 ( V_2 , V_3 ) ;
F_18 ( V_2 , & V_15 ) ;
}
return V_4 ;
}
void F_31 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned long V_15 ;
if ( F_17 ( V_2 , & V_15 ) ) {
F_25 ( V_2 , V_3 , V_4 ) ;
F_18 ( V_2 , & V_15 ) ;
}
}
int F_32 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 , int V_9 )
{
int V_10 = 0 ;
do {
if ( ( F_30 ( V_2 , V_6 ) & V_8 ) == ( V_7 & V_8 ) )
return V_10 ;
F_15 ( V_11 ) ;
V_10 += V_11 ;
} while ( V_10 < V_9 );
return - V_12 ;
}
void F_33 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
unsigned long V_15 ;
if ( F_17 ( V_2 , & V_15 ) ) {
F_25 ( V_2 , V_3 ,
F_22 ( V_2 , V_3 ) |
V_8 ) ;
F_18 ( V_2 , & V_15 ) ;
}
}
void F_34 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_7 , T_1 V_8 )
{
unsigned long V_15 ;
if ( F_17 ( V_2 , & V_15 ) ) {
F_25 ( V_2 , V_3 ,
( F_22 ( V_2 , V_3 ) &
V_8 ) | V_7 ) ;
F_18 ( V_2 , & V_15 ) ;
}
}
void F_35 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
unsigned long V_15 ;
T_1 V_4 ;
if ( F_17 ( V_2 , & V_15 ) ) {
V_4 = F_22 ( V_2 , V_3 ) ;
F_25 ( V_2 , V_3 , ( V_4 & ~ V_8 ) ) ;
F_18 ( V_2 , & V_15 ) ;
}
}
void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> V_17 < V_18 )
F_31 ( V_2 , V_19 ,
V_20 ) ;
else
F_31 ( V_2 , V_21 ,
V_22 ) ;
}
static const char * F_37 ( int V_23 )
{
#define F_38 ( T_4 ) case x: return #x
#define F_39 ( T_5 , V_13 , T_6 ) { if (arg == reg(q)) return #reg; }
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
F_39 ( V_23 , V_26 , V_24 ) ;
F_39 ( V_23 , V_27 , V_24 ) ;
F_39 ( V_23 , V_28 , V_24 ) ;
F_39 ( V_23 , V_29 , V_24 ) ;
}
switch ( V_23 ) {
F_38 ( V_30 ) ;
F_38 ( V_31 ) ;
F_38 ( V_32 ) ;
F_38 ( V_33 ) ;
F_38 ( V_34 ) ;
default:
return L_1 ;
}
#undef F_39
}
static int F_40 ( struct V_1 * V_2 , char * * V_35 )
{
int V_24 , T_6 ;
int V_36 = V_2 -> V_37 ;
static const T_1 V_38 [] = {
V_30 ,
V_31 ,
V_32 ,
V_33 ,
V_34 ,
} ;
static const struct V_13 V_39 [] = {
{ V_40 , true } ,
{ V_41 , false } ,
{ V_42 , false } ,
{ V_43 , true } ,
} ;
#ifdef F_41
if ( V_35 ) {
int V_44 = 0 ;
T_7 V_45 = F_42 ( V_38 ) * 53 +
F_42 ( V_39 ) * 53 * V_36 + 40 ;
* V_35 = F_43 ( V_45 , V_46 ) ;
if ( ! * V_35 )
return - V_47 ;
V_44 += F_44 ( * V_35 + V_44 , V_45 - V_44 ,
L_2 ) ;
for ( V_24 = 0 ; V_24 < F_42 ( V_38 ) ; V_24 ++ )
V_44 += F_44 ( * V_35 + V_44 , V_45 - V_44 ,
L_3 ,
F_37 ( V_38 [ V_24 ] ) ,
F_30 ( V_2 , V_38 [ V_24 ] ) ) ;
for ( V_24 = 0 ; V_24 < F_42 ( V_39 ) ; V_24 ++ )
for ( T_6 = 0 ; T_6 < V_36 ; T_6 ++ ) {
T_1 V_6 = V_39 [ V_24 ] . V_6 ;
V_6 += T_6 * ( V_39 [ V_24 ] . V_48 ? 8 : 4 ) ;
V_44 += F_44 ( * V_35 + V_44 , V_45 - V_44 ,
L_4 ,
F_37 ( V_6 ) , T_6 ,
F_30 ( V_2 , V_6 ) ) ;
}
return V_44 ;
}
#endif
F_45 ( V_2 , L_2 ) ;
for ( V_24 = 0 ; V_24 < F_42 ( V_38 ) ; V_24 ++ )
F_45 ( V_2 , L_5 ,
F_37 ( V_38 [ V_24 ] ) ,
F_30 ( V_2 , V_38 [ V_24 ] ) ) ;
for ( V_24 = 0 ; V_24 < F_42 ( V_39 ) ; V_24 ++ )
for ( T_6 = 0 ; T_6 < V_36 ; T_6 ++ ) {
T_1 V_6 = V_39 [ V_24 ] . V_6 ;
V_6 += T_6 * ( V_39 [ V_24 ] . V_48 ? 8 : 4 ) ;
F_45 ( V_2 , L_6 ,
F_37 ( V_6 ) , T_6 ,
F_30 ( V_2 , V_6 ) ) ;
}
return 0 ;
}
static const char * F_46 ( int V_23 )
{
switch ( V_23 ) {
F_38 ( V_49 ) ;
F_38 ( V_50 ) ;
F_38 ( V_51 ) ;
F_38 ( V_52 ) ;
F_38 ( V_53 ) ;
F_38 ( V_54 ) ;
F_38 ( V_55 ) ;
F_38 ( V_33 ) ;
F_38 ( V_34 ) ;
default:
return L_1 ;
}
#undef F_38
}
int F_47 ( struct V_1 * V_2 , char * * V_35 )
{
int V_24 ;
static const T_1 V_56 [] = {
V_49 ,
V_50 ,
V_51 ,
V_52 ,
V_53 ,
V_54 ,
V_55 ,
V_33 ,
V_34
} ;
if ( V_2 -> V_16 -> V_57 )
return F_40 ( V_2 , V_35 ) ;
#ifdef F_41
if ( V_35 ) {
int V_44 = 0 ;
T_7 V_45 = F_42 ( V_56 ) * 48 + 40 ;
* V_35 = F_43 ( V_45 , V_46 ) ;
if ( ! * V_35 )
return - V_47 ;
V_44 += F_44 ( * V_35 + V_44 , V_45 - V_44 ,
L_7 ) ;
for ( V_24 = 0 ; V_24 < F_42 ( V_56 ) ; V_24 ++ )
V_44 += F_44 ( * V_35 + V_44 , V_45 - V_44 ,
L_5 ,
F_46 ( V_56 [ V_24 ] ) ,
F_16 ( V_2 , V_56 [ V_24 ] ) ) ;
return V_44 ;
}
#endif
F_45 ( V_2 , L_7 ) ;
for ( V_24 = 0 ; V_24 < F_42 ( V_56 ) ; V_24 ++ )
F_45 ( V_2 , L_5 ,
F_46 ( V_56 [ V_24 ] ) ,
F_16 ( V_2 , V_56 [ V_24 ] ) ) ;
return 0 ;
}
