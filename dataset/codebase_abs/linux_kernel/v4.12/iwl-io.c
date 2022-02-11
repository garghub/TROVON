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
if ( V_2 -> V_16 -> V_17 != V_18 ) {
F_31 ( V_2 , V_19 ,
V_20 ) ;
F_31 ( V_2 , V_19 ,
V_21 ) ;
} else if ( V_2 -> V_16 -> V_22 ) {
F_31 ( V_2 , V_23 ,
V_24 ) ;
} else {
F_31 ( V_2 , V_25 ,
V_24 ) ;
F_31 ( V_2 , V_19 ,
V_20 ) ;
}
}
static const char * F_37 ( int V_26 )
{
#define F_38 ( T_4 ) case x: return #x
#define F_39 ( T_5 , V_13 , T_6 ) { if (arg == reg(q)) return #reg; }
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
F_39 ( V_26 , V_29 , V_27 ) ;
F_39 ( V_26 , V_30 , V_27 ) ;
F_39 ( V_26 , V_31 , V_27 ) ;
F_39 ( V_26 , V_32 , V_27 ) ;
}
switch ( V_26 ) {
F_38 ( V_33 ) ;
F_38 ( V_34 ) ;
F_38 ( V_35 ) ;
F_38 ( V_36 ) ;
F_38 ( V_37 ) ;
default:
return L_1 ;
}
#undef F_39
}
static int F_40 ( struct V_1 * V_2 , char * * V_38 )
{
int V_27 , T_6 ;
int V_39 = V_2 -> V_40 ;
static const T_1 V_41 [] = {
V_33 ,
V_34 ,
V_35 ,
V_36 ,
V_37 ,
} ;
static const struct V_13 V_42 [] = {
{ V_43 , true } ,
{ V_44 , false } ,
{ V_45 , false } ,
{ V_46 , true } ,
} ;
#ifdef F_41
if ( V_38 ) {
int V_47 = 0 ;
T_7 V_48 = F_42 ( V_41 ) * 53 +
F_42 ( V_42 ) * 53 * V_39 + 40 ;
* V_38 = F_43 ( V_48 , V_49 ) ;
if ( ! * V_38 )
return - V_50 ;
V_47 += F_44 ( * V_38 + V_47 , V_48 - V_47 ,
L_2 ) ;
for ( V_27 = 0 ; V_27 < F_42 ( V_41 ) ; V_27 ++ )
V_47 += F_44 ( * V_38 + V_47 , V_48 - V_47 ,
L_3 ,
F_37 ( V_41 [ V_27 ] ) ,
F_30 ( V_2 , V_41 [ V_27 ] ) ) ;
for ( V_27 = 0 ; V_27 < F_42 ( V_42 ) ; V_27 ++ )
for ( T_6 = 0 ; T_6 < V_39 ; T_6 ++ ) {
T_1 V_6 = V_42 [ V_27 ] . V_6 ;
V_6 += T_6 * ( V_42 [ V_27 ] . V_51 ? 8 : 4 ) ;
V_47 += F_44 ( * V_38 + V_47 , V_48 - V_47 ,
L_4 ,
F_37 ( V_6 ) , T_6 ,
F_30 ( V_2 , V_6 ) ) ;
}
return V_47 ;
}
#endif
F_45 ( V_2 , L_2 ) ;
for ( V_27 = 0 ; V_27 < F_42 ( V_41 ) ; V_27 ++ )
F_45 ( V_2 , L_5 ,
F_37 ( V_41 [ V_27 ] ) ,
F_30 ( V_2 , V_41 [ V_27 ] ) ) ;
for ( V_27 = 0 ; V_27 < F_42 ( V_42 ) ; V_27 ++ )
for ( T_6 = 0 ; T_6 < V_39 ; T_6 ++ ) {
T_1 V_6 = V_42 [ V_27 ] . V_6 ;
V_6 += T_6 * ( V_42 [ V_27 ] . V_51 ? 8 : 4 ) ;
F_45 ( V_2 , L_6 ,
F_37 ( V_6 ) , T_6 ,
F_30 ( V_2 , V_6 ) ) ;
}
return 0 ;
}
static const char * F_46 ( int V_26 )
{
switch ( V_26 ) {
F_38 ( V_52 ) ;
F_38 ( V_53 ) ;
F_38 ( V_54 ) ;
F_38 ( V_55 ) ;
F_38 ( V_56 ) ;
F_38 ( V_57 ) ;
F_38 ( V_58 ) ;
F_38 ( V_36 ) ;
F_38 ( V_37 ) ;
default:
return L_1 ;
}
#undef F_38
}
int F_47 ( struct V_1 * V_2 , char * * V_38 )
{
int V_27 ;
static const T_1 V_59 [] = {
V_52 ,
V_53 ,
V_54 ,
V_55 ,
V_56 ,
V_57 ,
V_58 ,
V_36 ,
V_37
} ;
if ( V_2 -> V_16 -> V_60 )
return F_40 ( V_2 , V_38 ) ;
#ifdef F_41
if ( V_38 ) {
int V_47 = 0 ;
T_7 V_48 = F_42 ( V_59 ) * 48 + 40 ;
* V_38 = F_43 ( V_48 , V_49 ) ;
if ( ! * V_38 )
return - V_50 ;
V_47 += F_44 ( * V_38 + V_47 , V_48 - V_47 ,
L_7 ) ;
for ( V_27 = 0 ; V_27 < F_42 ( V_59 ) ; V_27 ++ )
V_47 += F_44 ( * V_38 + V_47 , V_48 - V_47 ,
L_5 ,
F_46 ( V_59 [ V_27 ] ) ,
F_16 ( V_2 , V_59 [ V_27 ] ) ) ;
return V_47 ;
}
#endif
F_45 ( V_2 , L_7 ) ;
for ( V_27 = 0 ; V_27 < F_42 ( V_59 ) ; V_27 ++ )
F_45 ( V_2 , L_5 ,
F_46 ( V_59 [ V_27 ] ) ,
F_16 ( V_2 , V_59 [ V_27 ] ) ) ;
return 0 ;
}
