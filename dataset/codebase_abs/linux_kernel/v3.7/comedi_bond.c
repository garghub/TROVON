static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
#define F_2 (sizeof(unsigned int)*8)
unsigned V_11 = F_2 , V_12 = 0 , V_13 ;
if ( V_9 -> V_11 < V_11 )
V_11 = V_9 -> V_11 ;
for ( V_13 = 0 ; V_12 < V_11 && V_13 < V_9 -> V_14 ; ++ V_13 ) {
struct V_15 * V_16 = V_9 -> V_17 [ V_13 ] ;
unsigned int V_18 = ( ( 1 << V_16 -> V_11 ) - 1 ) ;
unsigned int V_19 , V_20 ;
if ( V_16 -> V_11 >= F_2 )
V_18 = ( unsigned int ) ( - 1 ) ;
V_19 = ( V_7 [ 0 ] >> V_12 ) & V_18 ;
V_20 = ( V_7 [ 1 ] >> V_12 ) & V_18 ;
if ( F_3 ( V_16 -> V_2 , V_16 -> V_21 , V_19 ,
& V_20 ) != 2 )
return - V_22 ;
V_7 [ 1 ] &= ~ ( V_18 << V_12 ) ;
V_7 [ 1 ] |= ( V_20 & V_18 ) << V_12 ;
V_4 -> V_23 = V_7 [ 1 ] ;
V_12 += V_16 -> V_11 ;
}
return V_6 -> V_24 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_25 = F_5 ( V_6 -> V_26 ) , V_27 , V_28 = V_4 -> V_28 ;
unsigned int V_29 ;
struct V_15 * V_16 ;
if ( V_25 < 0 || V_25 >= V_9 -> V_11 )
return - V_22 ;
V_16 = V_9 -> V_30 [ V_25 ] ;
switch ( V_7 [ 0 ] ) {
case V_31 :
V_29 = V_32 ;
V_28 |= 1 << V_25 ;
break;
case V_33 :
V_29 = V_34 ;
V_28 &= ~ ( 1 << V_25 ) ;
break;
case V_35 :
V_7 [ 1 ] =
( V_28 & ( 1 << V_25 ) ) ? V_32 : V_34 ;
return V_6 -> V_24 ;
break;
default:
return - V_22 ;
break;
}
V_25 -= V_16 -> V_36 ;
V_27 = F_6 ( V_16 -> V_2 , V_16 -> V_21 , V_25 , V_29 ) ;
if ( V_27 != 1 )
return - V_22 ;
V_4 -> V_28 = V_28 ;
return V_6 -> V_24 ;
}
static void * Realloc ( const void * V_37 , T_1 V_38 , T_1 V_39 )
{
void * V_40 = F_7 ( V_38 , V_41 ) ;
if ( V_40 && V_37 )
memcpy ( V_40 , V_37 , F_8 ( V_39 , V_38 ) ) ;
F_9 ( V_37 ) ;
return V_40 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_13 ;
struct V_1 * V_44 [ V_45 ] ;
memset ( V_44 , 0 , sizeof( V_44 ) ) ;
V_9 -> V_46 [ 0 ] = 0 ;
for ( V_13 = 0 ; V_13 < V_47 && ( ! V_13 || V_43 -> V_48 [ V_13 ] ) ; ++ V_13 ) {
char V_49 [] = L_1 ;
int V_50 = V_43 -> V_48 [ V_13 ] ;
struct V_1 * V_51 ;
int V_52 = - 1 , V_11 , V_53 ;
struct V_15 * V_16 = NULL ;
if ( V_50 < 0 || V_50 >= V_45 ) {
F_11 ( V_2 -> V_54 ,
L_2 , V_50 ) ;
return 0 ;
}
if ( V_50 == V_2 -> V_50 ) {
F_11 ( V_2 -> V_54 ,
L_3 ) ;
return 0 ;
}
if ( V_44 [ V_50 ] ) {
F_11 ( V_2 -> V_54 ,
L_4 , V_50 ) ;
return 0 ;
}
snprintf ( V_49 , sizeof( V_49 ) , L_5 , V_50 ) ;
V_49 [ sizeof( V_49 ) - 1 ] = 0 ;
V_51 = V_44 [ V_50 ] = F_12 ( V_49 ) ;
if ( ! V_51 ) {
F_11 ( V_2 -> V_54 ,
L_6 , V_50 ) ;
return 0 ;
}
while ( ( V_52 = F_13 ( V_51 , V_55 ,
V_52 + 1 ) ) > - 1 ) {
V_11 = F_14 ( V_51 , V_52 ) ;
if ( V_11 <= 0 ) {
F_11 ( V_2 -> V_54 ,
L_7 ,
V_11 , V_50 , V_52 ) ;
return 0 ;
}
V_16 = F_7 ( sizeof( * V_16 ) , V_41 ) ;
if ( ! V_16 ) {
F_11 ( V_2 -> V_54 , L_8 ) ;
return 0 ;
}
V_16 -> V_2 = V_51 ;
V_16 -> V_50 = V_50 ;
V_16 -> V_21 = V_52 ;
V_16 -> V_56 = V_55 ;
V_16 -> V_11 = V_11 ;
V_16 -> V_36 = V_9 -> V_11 ;
while ( V_11 -- )
V_9 -> V_30 [ V_9 -> V_11 ++ ] = V_16 ;
V_53 = V_9 -> V_14 * sizeof( V_16 ) ;
V_9 -> V_17 =
Realloc ( V_9 -> V_17 ,
++ V_9 -> V_14 * sizeof( V_16 ) , V_53 ) ;
if ( ! V_9 -> V_17 ) {
F_11 ( V_2 -> V_54 ,
L_9 ) ;
return 0 ;
}
V_9 -> V_17 [ V_9 -> V_14 - 1 ] = V_16 ;
{
char V_57 [ 20 ] ;
int V_58 =
V_59 - strlen ( V_9 -> V_46 ) - 1 ;
snprintf ( V_57 , sizeof( V_57 ) , L_10 , V_2 -> V_50 ,
V_16 -> V_21 ) ;
V_57 [ sizeof( V_57 ) - 1 ] = 0 ;
strncat ( V_9 -> V_46 , V_57 , V_58 ) ;
}
}
}
if ( ! V_9 -> V_11 ) {
F_11 ( V_2 -> V_54 , L_11 ) ;
return 0 ;
}
return 1 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_27 ;
V_27 = F_16 ( V_2 , sizeof( * V_9 ) ) ;
if ( V_27 )
return V_27 ;
V_9 = V_2 -> V_10 ;
if ( ! F_10 ( V_2 , V_43 ) )
return - V_22 ;
V_2 -> V_60 = V_9 -> V_46 ;
V_27 = F_17 ( V_2 , 1 ) ;
if ( V_27 )
return V_27 ;
V_4 = & V_2 -> V_61 [ 0 ] ;
V_4 -> type = V_55 ;
V_4 -> V_62 = V_63 | V_64 ;
V_4 -> V_65 = V_9 -> V_11 ;
V_4 -> V_66 = 1 ;
V_4 -> V_67 = & V_68 ;
V_4 -> V_69 = F_1 ;
V_4 -> V_70 = F_4 ;
F_18 ( V_2 -> V_54 ,
L_12 ,
V_2 -> V_71 -> V_72 , V_2 -> V_60 ,
V_9 -> V_11 , V_9 -> V_14 ) ;
return 1 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned long V_73 = 0 ;
if ( V_9 ) {
while ( V_9 -> V_14 -- && V_9 -> V_17 ) {
struct V_15 * V_16 ;
V_16 = V_9 -> V_17 [ V_9 -> V_14 ] ;
if ( ! V_16 )
continue;
if ( ! ( V_73 & ( 0x1 << V_16 -> V_50 ) ) ) {
F_20 ( V_16 -> V_2 ) ;
V_73 |= ( 0x1 << V_16 -> V_50 ) ;
}
F_9 ( V_16 ) ;
}
F_9 ( V_9 -> V_17 ) ;
V_9 -> V_17 = NULL ;
F_9 ( V_9 ) ;
V_2 -> V_10 = NULL ;
}
}
