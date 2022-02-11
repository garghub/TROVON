static int
F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 V_4 ,
T_1 * V_5 , T_1 V_6 )
{
int V_7 ;
int V_8 ;
F_2 ( V_2 -> V_9 , L_1 ) ;
V_8 = F_3 ( V_2 -> V_10 , F_4 ( V_2 -> V_10 , 0x02 ) ,
V_3 , V_4 , & V_7 , V_11 ) ;
if ( V_8 != 0 ) {
F_5 ( V_2 -> V_9 ,
L_2 ,
V_8 , V_7 ) ;
return V_8 ;
}
else if ( V_7 != V_4 ) {
F_5 ( V_2 -> V_9 ,
L_3 ,
V_7 ) ;
}
else {
F_2 ( V_2 -> V_9 , L_4 ) ;
}
V_8 = F_3 ( V_2 -> V_10 , F_6 ( V_2 -> V_10 , 0x81 ) ,
V_5 , V_6 , & V_7 , V_11 ) ;
if ( V_8 != 0 )
F_5 ( V_2 -> V_9 ,
L_5 ,
V_8 , V_7 ) ;
else if ( V_7 != V_6 )
F_5 ( V_2 -> V_9 , L_6 ,
V_7 ) ;
return V_8 ;
}
static int
F_7 ( struct V_1 * V_2 , T_1 * V_12 )
{
const static char V_13 [] =
{ 0x57 , 0x50 , 0x04 , 0x00 , 0x00 , 0x00 , 0x00 , 0x20 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
const static char V_14 [] =
{ 0x57 , 0x50 , 0x04 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 , 0x00 , 0xf4 ,
0x00 , 0x00 } ;
const static int V_15 = 28 ;
char * V_16 ;
int V_8 ;
V_16 = F_8 ( V_15 , V_17 | V_18 ) ;
if ( ! V_16 )
return - V_19 ;
memcpy ( V_16 , V_13 , 12 ) ;
V_8 = F_1 ( V_2 , V_16 , sizeof( V_13 )
/ sizeof( V_13 [ 0 ] ) , V_16 , 24 ) ;
if ( V_8 != 0 )
return V_8 ;
memcpy ( V_16 , V_14 , 12 ) ;
V_8 = F_1 ( V_2 , V_16 , sizeof( V_14 )
/ sizeof( V_14 [ 0 ] ) , V_16 , 28 ) ;
if ( V_8 != 0 )
return V_8 ;
memcpy ( V_12 , V_16 + 10 , V_20 ) ;
F_9 ( V_16 ) ;
return V_8 ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_8 ;
T_1 V_12 [ V_20 ] ;
if ( V_22 -> V_23 -> V_24 . V_25 != V_26 )
return - V_27 ;
V_2 -> V_28 = F_6 ( V_2 -> V_10 , 0x81 & V_29 ) ;
V_2 -> V_30 = F_4 ( V_2 -> V_10 , 0x02 & V_29 ) ;
V_2 -> V_8 = NULL ;
V_2 -> V_9 -> V_31 += V_32 ;
V_2 -> V_33 = 1400 ;
V_2 -> V_34 = V_2 -> V_33 * 10 ;
V_8 = F_7 ( V_2 , V_12 ) ;
if ( V_8 < 0 ) {
F_11 ( V_22 , NULL ) ;
F_12 ( F_13 ( V_22 ) , V_22 ) ;
return V_8 ;
}
memcpy ( V_2 -> V_9 -> V_35 , V_12 , V_20 ) ;
memcpy ( V_2 -> V_9 -> V_36 , V_12 , V_20 ) ;
return V_8 ;
}
static struct V_37 *
F_14 ( struct V_1 * V_2 , struct V_37 * V_38 , T_2 V_39 )
{
struct V_37 * V_40 = NULL ;
T_3 V_41 ;
unsigned char * V_42 ;
unsigned char V_43 , V_44 ;
T_1 V_45 , V_46 = 0 ;
if ( ! F_15 ( V_38 ) ) {
int V_47 = F_16 ( V_38 ) ;
int V_48 = F_17 ( V_38 ) ;
if ( ( V_48 >= V_49 ) && ( V_47
>= V_32 ) )
goto V_50;
if ( ( V_47 + V_48 ) > ( V_32
+ V_49 ) ) {
V_38 -> V_51 = memmove ( V_38 -> V_52 + V_32 ,
V_38 -> V_51 , V_38 -> V_53 ) ;
F_18 ( V_38 , V_38 -> V_53 ) ;
goto V_50;
}
}
V_40 = F_19 ( V_38 , V_32 ,
V_49 , V_39 ) ;
if ( ! V_40 )
return NULL ;
F_20 ( V_38 ) ;
V_38 = V_40 ;
V_50:
V_42 = F_21 ( V_38 , V_32 ) ;
V_43 = V_42 [ V_32 + 12 ] ;
V_44 = V_42 [ V_32 + 13 ] ;
F_2 ( V_2 -> V_9 , L_7 , V_43 ,
V_44 ) ;
V_42 [ 0 ] = 0x57 ;
V_42 [ 1 ] = 0x44 ;
V_41 = V_38 -> V_53 - V_32 ;
F_22 ( V_41 , & V_42 [ 2 ] ) ;
V_42 [ 4 ] = V_43 ;
V_42 [ 5 ] = V_44 ;
V_45 = V_38 -> V_53 % V_49 ;
if ( V_45 > 0 ) {
V_46 = V_49 - V_45 ;
memset ( F_23 ( V_38 , V_46 ) , 0 , V_46 ) ;
}
F_2 (
V_2 -> V_9 ,
L_8 ,
V_41 , V_46 , V_42 [ 0 ] , V_42 [ 1 ] ,
V_42 [ 2 ] , V_42 [ 3 ] , V_42 [ 4 ] ,
V_42 [ 5 ] ) ;
return V_38 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
const static T_1 V_54 [] =
{ 0x57 , 0x5a , 0x00 , 0x00 , 0x08 , 0x00 } ;
const static T_1 V_55 [] =
{ 0x57 , 0x43 , 0x1e , 0x00 , 0x15 , 0x02 } ;
const static T_1 V_56 [] =
{ 0x57 , 0x50 , 0x0e , 0x00 , 0x00 , 0x00 } ;
int V_57 = 0 ;
if ( V_38 -> V_53 < V_32 )
return 0 ;
do {
struct V_37 * V_40 = NULL ;
T_1 * V_42 ;
T_3 V_58 , V_59 ;
int V_60 ;
V_42 = V_38 -> V_51 ;
if ( F_25 ( V_42 [ 0 ] != 0x57 || V_42 [ 1 ] != 0x44 ) ) {
if ( ! memcmp ( V_42 , V_55 ,
sizeof( V_55 ) ) || ! memcmp (
V_42 , V_56 ,
sizeof( V_56 ) ) ) {
F_2 (
V_2 -> V_9 ,
L_9 ,
V_42 [ 0 ] , V_42 [ 1 ] ,
V_42 [ 2 ] , V_42 [ 3 ] ,
V_42 [ 4 ] , V_42 [ 5 ] ,
V_38 -> V_53 - V_32 ) ;
}
else {
F_5 (
V_2 -> V_9 ,
L_10 ,
V_42 [ 0 ] , V_42 [ 1 ] ,
V_42 [ 2 ] , V_42 [ 3 ] ,
V_42 [ 4 ] , V_42 [ 5 ] ,
V_38 -> V_53 - V_32 ) ;
return 0 ;
}
}
else
F_2 (
V_2 -> V_9 ,
L_11 ,
V_42 [ 0 ] , V_42 [ 1 ] , V_42 [ 2 ] ,
V_42 [ 3 ] , V_42 [ 4 ] , V_42 [ 5 ] ,
V_38 -> V_53 - V_32 ) ;
V_58 = V_38 -> V_53 - ( 2 * V_32 ) ;
V_59 = F_26 ( & V_42 [ 2 ] ) ;
F_27 ( V_38 , V_32 ) ;
if ( V_58 < V_59 ) {
V_59 = V_58
+ V_32 ;
V_60 = true ;
}
else {
F_2 ( V_2 -> V_9 , L_12 , V_57
+ 1 ) ;
V_60 = ( memcmp ( V_38 -> V_51 + V_59 ,
V_54 ,
sizeof( V_54 ) ) == 0 ) ;
if ( ! V_60 ) {
V_42 = V_38 -> V_51 + V_59 ;
F_2 (
V_2 -> V_9 ,
L_13 ,
V_42 [ 0 ] , V_42 [ 1 ] ,
V_42 [ 2 ] , V_42 [ 3 ] ,
V_42 [ 4 ] , V_42 [ 5 ] ,
V_38 -> V_53 - V_32 ) ;
}
}
if ( V_60 ) {
V_40 = V_38 ;
}
else {
V_40 = F_28 ( V_38 , V_61 ) ;
if ( F_25 ( ! V_40 ) )
return 0 ;
}
F_29 ( V_40 , V_59 ) ;
if ( V_60 ) {
return 1 ;
}
else {
F_30 ( V_2 , V_40 ) ;
F_27 ( V_38 , V_59 ) ;
}
V_57 ++ ;
}
while ( V_38 -> V_53 );
return 1 ;
}
static int T_4 F_31 ( void )
{
return F_32 ( & V_62 ) ;
}
static void T_5 F_33 ( void )
{
F_34 ( & V_62 ) ;
}
