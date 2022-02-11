int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 += V_3 ;
if ( V_2 -> V_7 == V_3 )
V_4 = F_2 ( V_2 ) ;
if ( V_4 == 0 ) {
V_6 += V_3 ;
V_2 -> V_8 -> V_9 = V_2 -> V_5 - 64 ;
}
return V_4 ;
}
void F_3 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_7 -= V_3 ;
V_6 -= V_3 ;
if ( V_2 -> V_7 == 0 )
F_4 ( V_2 ) ;
}
int F_5 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_1 * V_2 , int line , bool V_14 )
{
if ( ! V_11 )
return 0 ;
V_2 -> V_15 = V_11 ;
if ( V_16 != V_13 )
return 0 ;
if ( ! V_14 ) {
int V_17 = 0 ;
if ( V_18 &&
* V_18 == 'b' )
V_17 = 1 ;
if ( ( line & 1 ) != V_17 )
return 0 ;
}
if ( ! V_19 ) {
V_11 -> V_20 = line ;
F_6 ( V_11 -> V_21 , line , NULL ) ;
}
return 1 ;
}
void F_7 ( struct V_10 * V_11 , struct V_12 * V_22 )
{
const char * V_23 , * V_24 ;
char V_25 [] = L_1 ;
int V_26 , V_27 , V_28 , V_29 ;
char V_30 ;
if ( ! strcmp ( V_22 -> V_21 , L_2 ) ||
! strcmp ( V_22 -> V_21 , L_3 ) ||
! strcmp ( V_22 -> V_21 , L_4 ) ) {
V_23 = F_8 ( V_22 ,
L_5 , NULL ) ;
if ( ! V_23 )
V_23 = L_6 ;
} else if ( ! strcmp ( V_22 -> V_21 , L_7 ) ) {
V_23 = L_8 ;
} else {
struct V_12 * V_13 ;
char V_31 ;
V_31 = 'a' ;
if ( V_18 )
V_31 = * V_18 ;
V_25 [ 3 ] = V_31 ;
V_13 = F_9 ( L_9 ) ;
V_23 = F_8 ( V_13 , V_25 , NULL ) ;
if ( ! V_23 )
V_23 = L_8 ;
}
V_29 = V_32 | V_33 | V_34 ;
V_24 = V_23 ;
V_26 = F_10 ( V_24 , NULL , 0 ) ;
V_24 = strchr ( V_24 , ',' ) ;
V_27 = F_10 ( ++ V_24 , NULL , 0 ) ;
V_24 = strchr ( V_24 , ',' ) ;
V_30 = * ( ++ V_24 ) ;
V_24 = strchr ( V_24 , ',' ) ;
V_28 = F_10 ( ++ V_24 , NULL , 0 ) ;
V_24 = strchr ( V_24 , ',' ) ;
switch ( V_26 ) {
case 150 : V_29 |= V_35 ; break;
case 300 : V_29 |= V_36 ; break;
case 600 : V_29 |= V_37 ; break;
case 1200 : V_29 |= V_38 ; break;
case 2400 : V_29 |= V_39 ; break;
case 4800 : V_29 |= V_40 ; break;
case 9600 : V_29 |= V_41 ; break;
case 19200 : V_29 |= V_42 ; break;
case 38400 : V_29 |= V_43 ; break;
case 57600 : V_29 |= V_44 ; break;
case 115200 : V_29 |= V_45 ; break;
case 230400 : V_29 |= V_46 ; break;
case 460800 : V_29 |= V_47 ; break;
default: V_26 = 9600 ; V_29 |= V_41 ; break;
}
switch ( V_27 ) {
case 5 : V_29 |= V_48 ; break;
case 6 : V_29 |= V_49 ; break;
case 7 : V_29 |= V_50 ; break;
case 8 : V_29 |= V_51 ; break;
default: V_29 |= V_51 ; break;
}
switch ( V_30 ) {
case 'o' : V_29 |= ( V_52 | V_53 ) ; break;
case 'e' : V_29 |= V_52 ; break;
case 'n' : default: break;
}
switch ( V_28 ) {
case 2 : V_29 |= V_54 ; break;
case 1 : default: break;
}
V_11 -> V_29 = V_29 ;
}
unsigned int F_11 ( unsigned int V_29 , int * V_55 )
{
int V_56 ;
for ( V_56 = 0 ; V_57 [ V_56 ] . V_26 != - 1 ; V_56 ++ )
if ( V_57 [ V_56 ] . V_29 == ( V_29 & V_58 ) )
break;
V_56 += 1 ;
if ( V_57 [ V_56 ] . V_26 == - 1 )
V_56 = 0 ;
* V_55 = V_57 [ V_56 ] . V_26 ;
return V_57 [ V_56 ] . V_29 ;
}
int F_12 ( unsigned char V_59 , int V_60 )
{
static int V_61 = 0 ;
static int V_62 = 0 ;
if ( V_60 ) {
if ( V_61 && V_62 < 8 )
return 1 ;
V_62 = 0 ;
V_61 = 1 ;
return 2 ;
}
if ( V_61 ) {
V_62 ++ ;
if ( V_59 == 0x87 ) {
V_61 = 0 ;
}
return 1 ;
}
return 0 ;
}
static int T_1 F_13 ( void )
{
return 0 ;
}
