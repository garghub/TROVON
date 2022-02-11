static inline int F_1 ( struct V_1 * V_2 )
{
unsigned char * V_3 = V_2 -> V_4 ;
unsigned int V_5 = V_2 -> V_5 ;
V_3 [ 0 ] = V_6 ;
if ( V_2 -> V_7 == 16 ) {
V_3 [ 1 ] = V_5 >> 8 ;
V_3 [ 2 ] = V_5 ;
} else {
V_3 [ 1 ] = V_5 ;
}
F_2 ( & V_2 -> V_8 -> V_9 , L_1 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
return F_3 ( V_2 -> V_8 , V_3 , ( V_2 -> V_7 == 16 ) ? 3 : 2 ) ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
unsigned char * V_10 = V_2 -> V_4 ;
struct V_11 V_12 = {
. V_13 = V_10 ,
. V_14 = V_2 -> V_15 ,
. V_16 = ( V_2 -> V_7 * 2 ) / 8 ,
} ;
struct V_17 V_18 ;
V_10 [ 0 ] = V_19 ;
V_10 [ 1 ] = 0x00 ;
V_10 [ 2 ] = 0x00 ;
V_10 [ 3 ] = 0x00 ;
F_5 ( & V_18 ) ;
F_6 ( & V_12 , & V_18 ) ;
return F_7 ( V_2 -> V_8 , & V_18 ) ;
}
static unsigned char * F_8 ( unsigned int V_20 )
{
V_20 &= 3 ;
switch ( V_20 ) {
case V_21 :
return L_2 ;
case V_22 :
return L_3 ;
case V_23 :
return L_4 ;
case V_24 :
return L_5 ;
}
return L_6 ;
}
static T_1 F_9 ( struct V_25 * V_9 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_1 * V_2 = F_10 ( V_9 ) ;
char * V_29 = V_28 ;
unsigned char * V_3 = V_2 -> V_15 ;
unsigned long V_30 = 0 ;
int V_31 ;
int V_32 ;
F_11 ( & V_2 -> V_33 ) ;
V_32 = F_4 ( V_2 ) ;
F_2 ( V_9 , L_7 , V_32 ) ;
if ( V_32 < 0 ) {
F_12 ( & V_2 -> V_33 ) ;
return V_32 ;
}
for ( V_31 = 0 ; V_31 < ( V_2 -> V_7 * 2 ) / 8 ; V_31 += 1 ) {
V_30 <<= 8 ;
V_30 |= ( ( unsigned long ) V_3 [ V_31 ] ) ;
F_2 ( V_9 , L_8 , V_31 , V_3 [ V_31 ] ) ;
}
for ( V_31 = 0 ; V_31 < V_2 -> V_7 ; V_31 ++ ) {
V_29 += sprintf ( V_29 , L_9 , F_8 ( V_30 >> ( V_31 * 2 ) ) ) ;
}
* V_29 ++ = '\n' ;
F_12 ( & V_2 -> V_33 ) ;
return V_29 - V_28 ;
}
static T_1 F_13 ( struct V_25 * V_9 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_1 * V_2 = F_10 ( V_9 ) ;
int V_34 = F_14 ( V_27 ) ;
int V_35 ;
F_11 ( & V_2 -> V_33 ) ;
V_35 = ( V_2 -> V_5 >> V_34 ) & 1 ;
F_12 ( & V_2 -> V_33 ) ;
return snprintf ( V_28 , V_36 , L_10 , V_35 ) ;
}
static T_1 F_15 ( struct V_25 * V_9 ,
struct V_26 * V_27 ,
const char * V_28 , T_2 V_16 )
{
struct V_1 * V_2 = F_10 ( V_9 ) ;
int V_34 = F_14 ( V_27 ) ;
unsigned long V_37 ;
char * V_38 ;
V_37 = F_16 ( V_28 , & V_38 , 0 ) ;
if ( V_28 == V_38 )
return - V_39 ;
F_2 ( V_9 , L_11 , V_34 , V_37 ) ;
F_11 ( & V_2 -> V_33 ) ;
if ( V_37 )
V_2 -> V_5 |= 1 << V_34 ;
else
V_2 -> V_5 &= ~ ( 1 << V_34 ) ;
F_1 ( V_2 ) ;
F_12 ( & V_2 -> V_33 ) ;
return V_16 ;
}
static int F_14 ( struct V_26 * V_27 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_17 ( V_40 ) ; V_31 ++ ) {
if ( V_40 [ V_31 ] == V_27 )
return V_31 ;
}
return - 1 ;
}
static int T_3 F_18 ( struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_43 * V_44 ;
int V_31 ;
int V_32 ;
V_44 = V_42 -> V_9 . V_45 ;
if ( V_44 == NULL ) {
F_19 ( & V_42 -> V_9 , L_12 ) ;
return - V_39 ;
}
V_2 = F_20 ( sizeof( struct V_1 ) , V_46 ) ;
if ( V_2 == NULL ) {
F_19 ( & V_42 -> V_9 , L_13 ) ;
return - V_47 ;
}
V_2 -> V_8 = V_42 ;
V_2 -> V_7 = V_44 -> V_48 ;
V_2 -> V_5 = V_44 -> V_49 ;
F_21 ( & V_2 -> V_33 ) ;
V_32 = F_22 ( & V_42 -> V_9 , & V_50 ) ;
if ( V_32 ) {
F_19 ( & V_42 -> V_9 , L_14 ) ;
goto V_51;
}
for ( V_31 = 0 ; V_31 < V_44 -> V_48 ; V_31 ++ ) {
V_32 = F_22 ( & V_42 -> V_9 , V_40 [ V_31 ] ) ;
if ( V_32 ) {
F_19 ( & V_42 -> V_9 , L_15 ) ;
goto V_52;
}
}
F_23 ( V_42 , V_2 ) ;
return 0 ;
V_52:
while ( -- V_31 >= 0 )
F_24 ( & V_42 -> V_9 , V_40 [ V_31 ] ) ;
F_24 ( & V_42 -> V_9 , & V_50 ) ;
V_51:
F_25 ( V_2 ) ;
return V_32 ;
}
static int T_4 F_26 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_27 ( V_42 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_7 ; V_31 ++ )
F_24 ( & V_42 -> V_9 , V_40 [ V_31 ] ) ;
F_24 ( & V_42 -> V_9 , & V_50 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static T_5 int F_28 ( void )
{
return F_29 ( & V_53 ) ;
}
static T_6 void F_30 ( void )
{
F_31 ( & V_53 ) ;
}
