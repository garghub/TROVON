int F_1 ( int V_1 )
{
int V_2 ;
for( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if( V_4 [ V_2 ] -> V_5 == V_1 )
return V_2 ;
}
return - V_6 ;
}
int F_2 ( T_1 * V_7 )
{
int V_8 ;
V_8 = F_1 ( V_7 -> V_1 ) ;
if( ! F_3 ( V_8 ) ) {
F_4 ( L_1 , V_8 ) ;
return - V_6 ;
}
switch( V_7 -> F_2 ) {
case V_9 :
{
unsigned long V_10 ;
T_2 V_11 ;
memcpy ( & V_10 , V_7 -> V_12 . V_13 , sizeof( unsigned long ) ) ;
if ( F_5 ( & V_11 , ( T_2 V_14 * ) V_10 ,
sizeof( T_2 ) ) ) {
F_4 ( L_2 ,
V_4 [ V_8 ] -> V_15 , V_10 ) ;
return - V_16 ;
}
return F_6 ( V_8 , & V_11 ) ;
}
case V_17 :
return F_7 ( V_8 , V_7 -> V_18 , V_7 -> V_12 . V_19 ) ;
case V_20 :
return F_8 ( V_8 , V_7 -> V_18 ) ;
case V_21 :
return F_9 ( V_8 , V_7 -> V_18 ) ;
case V_22 :
return F_10 ( V_8 , V_7 -> V_18 ) ;
case V_23 :
return F_11 ( V_8 , V_7 -> V_18 ) ;
case V_24 :
return F_12 ( V_8 , V_7 -> V_18 , V_7 -> V_12 . V_13 ) ;
case V_25 :
return F_13 ( V_8 , V_7 -> V_18 ) ;
case V_26 :
return F_14 ( V_8 , V_7 -> V_18 ) ;
default:
return - V_27 ;
}
return 0 ;
}
int F_15 ( int V_8 )
{
int V_28 ;
if( ! F_3 ( V_8 ) ) {
F_4 ( L_1 , V_8 ) ;
return - V_6 ;
}
V_28 = F_16 ( V_8 , V_29 , V_30 ,
V_31 ,
V_32 ,
0 , 0 , NULL ) ;
F_4 ( L_3 , V_4 [ V_8 ] -> V_15 ) ;
return V_28 ;
}
static int F_7 ( int V_8 , unsigned long V_33 , T_3 V_19 )
{
int V_28 ;
char V_34 [ 48 ] ;
if( ! F_3 ( V_8 ) ) {
F_4 ( L_1 , V_8 ) ;
return - V_6 ;
}
strcpy ( V_34 , V_19 . V_35 ) ;
V_28 = F_16 ( V_8 , V_36 , V_37 ,
V_38 ,
V_39 ,
( unsigned char ) V_33 + 1 ,
strlen ( V_34 ) ,
( unsigned int * ) V_34 ) ;
F_4 ( L_4 ,
V_4 [ V_8 ] -> V_15 , V_34 , V_33 + 1 ) ;
return V_28 ;
}
static int F_9 ( int V_8 , unsigned long V_33 )
{
if( ! F_3 ( V_8 ) ) {
F_4 ( L_1 , V_8 ) ;
return - V_6 ;
}
if( F_17 ( V_8 , V_33 + 1 ) ) {
F_8 ( V_8 , V_33 + 1 ) ;
return - V_40 ;
}
F_18 ( V_8 , V_41 , V_33 , NULL ) ;
F_4 ( L_5 ,
V_4 [ V_8 ] -> V_15 , V_33 + 1 ) ;
return 0 ;
}
static int F_8 ( int V_8 , unsigned long V_33 )
{
int V_28 ;
if( ! F_3 ( V_8 ) ) {
F_4 ( L_1 , V_8 ) ;
return - V_6 ;
}
V_28 = F_16 ( V_8 , V_36 , V_37 ,
V_38 ,
V_42 ,
( unsigned char ) V_33 + 1 ,
0 ,
NULL ) ;
F_4 ( L_6 ,
V_4 [ V_8 ] -> V_15 , V_33 + 1 ) ;
return V_28 ;
}
static int F_13 ( int V_8 , unsigned long V_18 )
{
int V_28 = 0 ;
int V_43 , V_33 ;
if( ! F_3 ( V_8 ) ) {
F_4 ( L_1 , V_8 ) ;
return - V_6 ;
}
V_43 = V_18 >> 8 ;
V_33 = V_18 & 0xff ;
V_4 [ V_8 ] -> V_33 [ V_33 ] . V_44 = V_43 ;
F_4 ( L_7 ,
V_4 [ V_8 ] -> V_15 , V_33 + 1 ) ;
V_28 = F_16 ( V_8 , V_36 , V_45 ,
V_46 ,
V_47 ,
( unsigned char ) V_33 + 1 ,
1 ,
( unsigned int * ) V_43 ) ;
if( V_28 )
return V_28 ;
return 0 ;
}
static int F_14 ( int V_8 , unsigned long V_33 )
{
int V_43 = V_33 >> 8 ;
if( ! F_3 ( V_8 ) ) {
F_4 ( L_1 , V_8 ) ;
return - V_6 ;
}
V_4 [ V_8 ] -> V_33 [ V_33 ] . V_48 = V_43 ;
return 0 ;
}
static int F_10 ( int V_8 , unsigned long V_33 )
{
if( ! F_3 ( V_8 ) ) {
F_4 ( L_1 , V_8 ) ;
return - V_6 ;
}
if( F_17 ( V_8 , V_33 + 1 ) )
{
F_8 ( V_8 , V_33 + 1 ) ;
return - V_40 ;
}
F_4 ( L_8 ,
V_4 [ V_8 ] -> V_15 , V_33 + 1 ) ;
F_18 ( V_8 , V_41 , V_33 , NULL ) ;
return 0 ;
}
static int F_11 ( int V_8 , unsigned long V_18 )
{
if( ! F_3 ( V_8 ) ) {
F_4 ( L_1 , V_8 ) ;
return - V_6 ;
}
strcpy ( V_4 [ V_8 ] -> V_33 [ V_18 ] . V_49 , L_9 ) ;
V_4 [ V_8 ] -> V_33 [ V_18 ] . V_50 = 1 ;
F_4 ( L_10 ,
V_4 [ V_8 ] -> V_15 , V_18 + 1 ) ;
return 0 ;
}
static int F_12 ( int V_8 , unsigned long V_18 , char * V_13 )
{
if( ! F_3 ( V_8 ) ) {
F_4 ( L_1 , V_8 ) ;
return - V_6 ;
}
strcpy ( V_4 [ V_8 ] -> V_33 [ V_18 ] . V_49 , V_13 ) ;
V_4 [ V_8 ] -> V_33 [ V_18 ] . V_50 = 0 ;
F_4 ( L_11 ,
V_4 [ V_8 ] -> V_15 , V_18 + 1 ,
V_4 [ V_8 ] -> V_33 [ V_18 ] . V_49 ) ;
return 0 ;
}
int F_19 ( int V_8 )
{
unsigned long V_51 ;
if( ! F_3 ( V_8 ) ) {
F_4 ( L_1 , V_8 ) ;
return - V_6 ;
}
F_18 ( V_8 , V_52 , 0 , NULL ) ;
if( V_4 [ V_8 ] -> V_53 ) {
F_20 ( & V_4 [ V_8 ] -> V_54 ) ;
}
V_4 [ V_8 ] -> V_53 = 0 ;
F_21 ( & V_4 [ V_8 ] -> V_55 , V_51 ) ;
F_22 ( & V_4 [ V_8 ] -> V_56 ) ;
V_4 [ V_8 ] -> V_56 . V_57 = V_58 ;
V_4 [ V_8 ] -> V_56 . V_59 = V_8 ;
V_4 [ V_8 ] -> V_56 . V_60 = V_61 + V_62 ;
F_23 ( & V_4 [ V_8 ] -> V_56 ) ;
F_24 ( & V_4 [ V_8 ] -> V_55 , V_51 ) ;
F_25 ( 0x1 , V_4 [ V_8 ] -> V_63 [ V_64 ] ) ;
F_4 ( L_12 , V_4 [ V_8 ] -> V_15 ) ;
return 0 ;
}
void F_26 ( int V_8 )
{
while( F_27 ( V_4 [ V_8 ] -> V_63 [ V_65 ] ) & V_66 )
F_27 ( V_4 [ V_8 ] -> V_63 [ V_67 ] ) ;
}
