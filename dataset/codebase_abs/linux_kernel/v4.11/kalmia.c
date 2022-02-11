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
static const char V_13 [] =
{ 0x57 , 0x50 , 0x04 , 0x00 , 0x00 , 0x00 , 0x00 , 0x20 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
static const char V_14 [] =
{ 0x57 , 0x50 , 0x04 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 , 0x00 , 0xf4 ,
0x00 , 0x00 } ;
static const int V_15 = 28 ;
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
if ( V_8 ) {
F_11 ( V_22 , NULL ) ;
F_12 ( F_13 ( V_22 ) , V_22 ) ;
return V_8 ;
}
memcpy ( V_2 -> V_9 -> V_35 , V_12 , V_20 ) ;
return V_8 ;
}
static struct V_36 *
F_14 ( struct V_1 * V_2 , struct V_36 * V_37 , T_2 V_38 )
{
struct V_36 * V_39 = NULL ;
T_3 V_40 ;
unsigned char * V_41 ;
unsigned char V_42 , V_43 ;
T_1 V_44 , V_45 = 0 ;
if ( ! F_15 ( V_37 ) ) {
int V_46 = F_16 ( V_37 ) ;
int V_47 = F_17 ( V_37 ) ;
if ( ( V_47 >= V_48 ) && ( V_46
>= V_32 ) )
goto V_49;
if ( ( V_46 + V_47 ) > ( V_32
+ V_48 ) ) {
V_37 -> V_50 = memmove ( V_37 -> V_51 + V_32 ,
V_37 -> V_50 , V_37 -> V_52 ) ;
F_18 ( V_37 , V_37 -> V_52 ) ;
goto V_49;
}
}
V_39 = F_19 ( V_37 , V_32 ,
V_48 , V_38 ) ;
if ( ! V_39 )
return NULL ;
F_20 ( V_37 ) ;
V_37 = V_39 ;
V_49:
V_41 = F_21 ( V_37 , V_32 ) ;
V_42 = V_41 [ V_32 + 12 ] ;
V_43 = V_41 [ V_32 + 13 ] ;
F_2 ( V_2 -> V_9 , L_7 , V_42 ,
V_43 ) ;
V_41 [ 0 ] = 0x57 ;
V_41 [ 1 ] = 0x44 ;
V_40 = V_37 -> V_52 - V_32 ;
F_22 ( V_40 , & V_41 [ 2 ] ) ;
V_41 [ 4 ] = V_42 ;
V_41 [ 5 ] = V_43 ;
V_44 = V_37 -> V_52 % V_48 ;
if ( V_44 > 0 ) {
V_45 = V_48 - V_44 ;
memset ( F_23 ( V_37 , V_45 ) , 0 , V_45 ) ;
}
F_2 ( V_2 -> V_9 ,
L_8 ,
V_40 , V_45 , V_41 ) ;
return V_37 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
static const T_1 V_53 [] =
{ 0x57 , 0x5a , 0x00 , 0x00 , 0x08 , 0x00 } ;
static const T_1 V_54 [] =
{ 0x57 , 0x43 , 0x1e , 0x00 , 0x15 , 0x02 } ;
static const T_1 V_55 [] =
{ 0x57 , 0x50 , 0x0e , 0x00 , 0x00 , 0x00 } ;
int V_56 = 0 ;
if ( V_37 -> V_52 < V_32 )
return 0 ;
do {
struct V_36 * V_39 = NULL ;
T_1 * V_41 ;
T_3 V_57 , V_58 ;
int V_59 ;
V_41 = V_37 -> V_50 ;
if ( F_25 ( V_41 [ 0 ] != 0x57 || V_41 [ 1 ] != 0x44 ) ) {
if ( ! memcmp ( V_41 , V_54 ,
sizeof( V_54 ) ) || ! memcmp (
V_41 , V_55 ,
sizeof( V_55 ) ) ) {
F_2 ( V_2 -> V_9 ,
L_9 ,
V_41 ,
V_37 -> V_52 - V_32 ) ;
}
else {
F_5 ( V_2 -> V_9 ,
L_10 ,
V_41 ,
V_37 -> V_52 - V_32 ) ;
return 0 ;
}
}
else
F_2 ( V_2 -> V_9 ,
L_11 ,
V_41 , V_37 -> V_52 - V_32 ) ;
V_57 = V_37 -> V_52 - ( 2 * V_32 ) ;
V_58 = F_26 ( & V_41 [ 2 ] ) ;
F_27 ( V_37 , V_32 ) ;
if ( V_57 < V_58 ) {
V_58 = V_57
+ V_32 ;
V_59 = true ;
}
else {
F_2 ( V_2 -> V_9 , L_12 , V_56
+ 1 ) ;
V_59 = ( memcmp ( V_37 -> V_50 + V_58 ,
V_53 ,
sizeof( V_53 ) ) == 0 ) ;
if ( ! V_59 ) {
V_41 = V_37 -> V_50 + V_58 ;
F_2 ( V_2 -> V_9 ,
L_13 ,
V_41 ,
V_37 -> V_52 - V_32 ) ;
}
}
if ( V_59 ) {
V_39 = V_37 ;
}
else {
V_39 = F_28 ( V_37 , V_60 ) ;
if ( F_25 ( ! V_39 ) )
return 0 ;
}
F_29 ( V_39 , V_58 ) ;
if ( V_59 ) {
return 1 ;
}
else {
F_30 ( V_2 , V_39 ) ;
F_27 ( V_37 , V_58 ) ;
}
V_56 ++ ;
}
while ( V_37 -> V_52 );
return 1 ;
}
