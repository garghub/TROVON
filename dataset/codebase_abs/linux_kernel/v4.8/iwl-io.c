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
F_6 ( V_2 , V_3 , V_4 & 0xffffffff ) ;
F_6 ( V_2 , V_3 + 4 , V_4 >> 32 ) ;
}
T_1 F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_10 ( V_2 , V_3 ) ;
F_11 ( V_2 -> V_5 , V_3 , V_4 ) ;
return V_4 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 , int V_9 )
{
int V_10 = 0 ;
do {
if ( ( F_9 ( V_2 , V_6 ) & V_8 ) == ( V_7 & V_8 ) )
return V_10 ;
F_13 ( V_11 ) ;
V_10 += V_11 ;
} while ( V_10 < V_9 );
return - V_12 ;
}
T_1 F_14 ( struct V_1 * V_2 , T_1 V_13 )
{
T_1 V_14 = 0x5a5a5a5a ;
unsigned long V_15 ;
if ( F_15 ( V_2 , & V_15 ) ) {
V_14 = F_9 ( V_2 , V_13 ) ;
F_16 ( V_2 , & V_15 ) ;
}
return V_14 ;
}
void F_17 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_14 )
{
unsigned long V_15 ;
if ( F_15 ( V_2 , & V_15 ) ) {
F_4 ( V_2 , V_13 , V_14 ) ;
F_16 ( V_2 , & V_15 ) ;
}
}
void F_18 ( struct V_1 * V_2 , T_3 V_13 , T_3 V_14 )
{
unsigned long V_15 ;
if ( F_15 ( V_2 , & V_15 ) ) {
F_7 ( V_2 , V_13 , V_14 ) ;
F_16 ( V_2 , & V_15 ) ;
}
}
int F_19 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_8 ,
int V_9 )
{
int V_10 = 0 ;
do {
if ( ( F_14 ( V_2 , V_6 ) & V_8 ) == V_8 )
return V_10 ;
F_13 ( V_11 ) ;
V_10 += V_11 ;
} while ( V_10 < V_9 );
return - V_12 ;
}
T_1 F_20 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_21 ( V_2 , V_3 ) ;
F_22 ( V_2 -> V_5 , V_3 , V_4 ) ;
return V_4 ;
}
void F_23 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_24 ( V_2 -> V_5 , V_3 , V_4 ) ;
F_25 ( V_2 , V_3 , V_4 ) ;
}
void F_26 ( struct V_1 * V_2 , T_3 V_3 , T_3 V_4 )
{
F_27 ( V_2 -> V_5 , V_3 , V_4 ) ;
F_23 ( V_2 , V_3 , V_4 & 0xffffffff ) ;
F_23 ( V_2 , V_3 + 4 , V_4 >> 32 ) ;
}
T_1 F_28 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_15 ;
T_1 V_4 = 0x5a5a5a5a ;
if ( F_15 ( V_2 , & V_15 ) ) {
V_4 = F_20 ( V_2 , V_3 ) ;
F_16 ( V_2 , & V_15 ) ;
}
return V_4 ;
}
void F_29 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned long V_15 ;
if ( F_15 ( V_2 , & V_15 ) ) {
F_23 ( V_2 , V_3 , V_4 ) ;
F_16 ( V_2 , & V_15 ) ;
}
}
int F_30 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 , int V_9 )
{
int V_10 = 0 ;
do {
if ( ( F_28 ( V_2 , V_6 ) & V_8 ) == ( V_7 & V_8 ) )
return V_10 ;
F_13 ( V_11 ) ;
V_10 += V_11 ;
} while ( V_10 < V_9 );
return - V_12 ;
}
void F_31 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
unsigned long V_15 ;
if ( F_15 ( V_2 , & V_15 ) ) {
F_23 ( V_2 , V_3 ,
F_20 ( V_2 , V_3 ) |
V_8 ) ;
F_16 ( V_2 , & V_15 ) ;
}
}
void F_32 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_7 , T_1 V_8 )
{
unsigned long V_15 ;
if ( F_15 ( V_2 , & V_15 ) ) {
F_23 ( V_2 , V_3 ,
( F_20 ( V_2 , V_3 ) &
V_8 ) | V_7 ) ;
F_16 ( V_2 , & V_15 ) ;
}
}
void F_33 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
unsigned long V_15 ;
T_1 V_4 ;
if ( F_15 ( V_2 , & V_15 ) ) {
V_4 = F_20 ( V_2 , V_3 ) ;
F_23 ( V_2 , V_3 , ( V_4 & ~ V_8 ) ) ;
F_16 ( V_2 , & V_15 ) ;
}
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> V_17 != V_18 ) {
F_29 ( V_2 , V_19 ,
V_20 ) ;
F_29 ( V_2 , V_19 ,
V_21 ) ;
} else {
F_29 ( V_2 , V_22 ,
V_23 ) ;
F_29 ( V_2 , V_19 ,
V_20 ) ;
}
}
static const char * F_35 ( int V_24 )
{
#define F_36 ( T_4 ) case x: return #x
#define F_37 ( T_5 , V_13 , T_6 ) { if (arg == reg(q)) return #reg; }
int V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
F_37 ( V_24 , V_27 , V_25 ) ;
F_37 ( V_24 , V_28 , V_25 ) ;
F_37 ( V_24 , V_29 , V_25 ) ;
F_37 ( V_24 , V_30 , V_25 ) ;
} ;
switch ( V_24 ) {
F_36 ( V_31 ) ;
F_36 ( V_32 ) ;
F_36 ( V_33 ) ;
F_36 ( V_34 ) ;
F_36 ( V_35 ) ;
default:
return L_1 ;
}
#undef F_37
}
static int F_38 ( struct V_1 * V_2 , char * * V_36 )
{
int V_25 , T_6 ;
int V_37 = V_2 -> V_38 ;
static const T_1 V_39 [] = {
V_31 ,
V_32 ,
V_33 ,
V_34 ,
V_35 ,
} ;
static const struct V_13 V_40 [] = {
{ V_41 , true } ,
{ V_42 , false } ,
{ V_43 , false } ,
{ V_44 , true } ,
} ;
#ifdef F_39
if ( V_36 ) {
int V_45 = 0 ;
T_7 V_46 = F_40 ( V_39 ) * 53 +
F_40 ( V_40 ) * 53 * V_37 + 40 ;
* V_36 = F_41 ( V_46 , V_47 ) ;
if ( ! * V_36 )
return - V_48 ;
V_45 += F_42 ( * V_36 + V_45 , V_46 - V_45 ,
L_2 ) ;
for ( V_25 = 0 ; V_25 < F_40 ( V_39 ) ; V_25 ++ )
V_45 += F_42 ( * V_36 + V_45 , V_46 - V_45 ,
L_3 ,
F_35 ( V_39 [ V_25 ] ) ,
F_28 ( V_2 , V_39 [ V_25 ] ) ) ;
for ( V_25 = 0 ; V_25 < F_40 ( V_40 ) ; V_25 ++ )
for ( T_6 = 0 ; T_6 < V_37 ; T_6 ++ ) {
T_1 V_6 = V_40 [ V_25 ] . V_6 ;
V_6 += T_6 * ( V_40 [ V_25 ] . V_49 ? 8 : 4 ) ;
V_45 += F_42 ( * V_36 + V_45 , V_46 - V_45 ,
L_4 ,
F_35 ( V_6 ) , T_6 ,
F_28 ( V_2 , V_6 ) ) ;
}
return V_45 ;
}
#endif
F_43 ( V_2 , L_2 ) ;
for ( V_25 = 0 ; V_25 < F_40 ( V_39 ) ; V_25 ++ )
F_43 ( V_2 , L_5 ,
F_35 ( V_39 [ V_25 ] ) ,
F_28 ( V_2 , V_39 [ V_25 ] ) ) ;
for ( V_25 = 0 ; V_25 < F_40 ( V_40 ) ; V_25 ++ )
for ( T_6 = 0 ; T_6 < V_37 ; T_6 ++ ) {
T_1 V_6 = V_40 [ V_25 ] . V_6 ;
V_6 += T_6 * ( V_40 [ V_25 ] . V_49 ? 8 : 4 ) ;
F_43 ( V_2 , L_6 ,
F_35 ( V_6 ) , T_6 ,
F_28 ( V_2 , V_6 ) ) ;
}
return 0 ;
}
static const char * F_44 ( int V_24 )
{
switch ( V_24 ) {
F_36 ( V_50 ) ;
F_36 ( V_51 ) ;
F_36 ( V_52 ) ;
F_36 ( V_53 ) ;
F_36 ( V_54 ) ;
F_36 ( V_55 ) ;
F_36 ( V_56 ) ;
F_36 ( V_34 ) ;
F_36 ( V_35 ) ;
default:
return L_1 ;
}
#undef F_36
}
int F_45 ( struct V_1 * V_2 , char * * V_36 )
{
int V_25 ;
static const T_1 V_57 [] = {
V_50 ,
V_51 ,
V_52 ,
V_53 ,
V_54 ,
V_55 ,
V_56 ,
V_34 ,
V_35
} ;
if ( V_2 -> V_16 -> V_58 )
return F_38 ( V_2 , V_36 ) ;
#ifdef F_39
if ( V_36 ) {
int V_45 = 0 ;
T_7 V_46 = F_40 ( V_57 ) * 48 + 40 ;
* V_36 = F_41 ( V_46 , V_47 ) ;
if ( ! * V_36 )
return - V_48 ;
V_45 += F_42 ( * V_36 + V_45 , V_46 - V_45 ,
L_7 ) ;
for ( V_25 = 0 ; V_25 < F_40 ( V_57 ) ; V_25 ++ )
V_45 += F_42 ( * V_36 + V_45 , V_46 - V_45 ,
L_5 ,
F_44 ( V_57 [ V_25 ] ) ,
F_14 ( V_2 , V_57 [ V_25 ] ) ) ;
return V_45 ;
}
#endif
F_43 ( V_2 , L_7 ) ;
for ( V_25 = 0 ; V_25 < F_40 ( V_57 ) ; V_25 ++ )
F_43 ( V_2 , L_5 ,
F_44 ( V_57 [ V_25 ] ) ,
F_14 ( V_2 , V_57 [ V_25 ] ) ) ;
return 0 ;
}
