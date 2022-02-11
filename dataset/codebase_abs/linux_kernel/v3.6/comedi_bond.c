static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
#define F_2 (sizeof(unsigned int)*8)
unsigned V_8 = F_2 , V_9 = 0 , V_10 ;
if ( V_11 -> V_8 < V_8 )
V_8 = V_11 -> V_8 ;
for ( V_10 = 0 ; V_9 < V_8 && V_10 < V_11 -> V_12 ; ++ V_10 ) {
struct V_13 * V_14 = V_11 -> V_15 [ V_10 ] ;
unsigned int V_16 = ( ( 1 << V_14 -> V_8 ) - 1 ) ;
unsigned int V_17 , V_18 ;
if ( V_14 -> V_8 >= F_2 )
V_16 = ( unsigned int ) ( - 1 ) ;
V_17 = ( V_7 [ 0 ] >> V_9 ) & V_16 ;
V_18 = ( V_7 [ 1 ] >> V_9 ) & V_16 ;
if ( F_3 ( V_14 -> V_2 , V_14 -> V_19 , V_17 ,
& V_18 ) != 2 )
return - V_20 ;
V_7 [ 1 ] &= ~ ( V_16 << V_9 ) ;
V_7 [ 1 ] |= ( V_18 & V_16 ) << V_9 ;
V_4 -> V_21 = V_7 [ 1 ] ;
V_9 += V_14 -> V_8 ;
}
return V_6 -> V_22 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_23 = F_5 ( V_6 -> V_24 ) , V_25 , V_26 = V_4 -> V_26 ;
unsigned int V_27 ;
struct V_13 * V_14 ;
if ( V_23 < 0 || V_23 >= V_11 -> V_8 )
return - V_20 ;
V_14 = V_11 -> V_28 [ V_23 ] ;
switch ( V_7 [ 0 ] ) {
case V_29 :
V_27 = V_30 ;
V_26 |= 1 << V_23 ;
break;
case V_31 :
V_27 = V_32 ;
V_26 &= ~ ( 1 << V_23 ) ;
break;
case V_33 :
V_7 [ 1 ] =
( V_26 & ( 1 << V_23 ) ) ? V_30 : V_32 ;
return V_6 -> V_22 ;
break;
default:
return - V_20 ;
break;
}
V_23 -= V_14 -> V_34 ;
V_25 = F_6 ( V_14 -> V_2 , V_14 -> V_19 , V_23 , V_27 ) ;
if ( V_25 != 1 )
return - V_20 ;
V_4 -> V_26 = V_26 ;
return V_6 -> V_22 ;
}
static void * Realloc ( const void * V_35 , T_1 V_36 , T_1 V_37 )
{
void * V_38 = F_7 ( V_36 , V_39 ) ;
if ( V_38 && V_35 )
memcpy ( V_38 , V_35 , F_8 ( V_37 , V_36 ) ) ;
F_9 ( V_35 ) ;
return V_38 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
int V_10 ;
struct V_1 * V_42 [ V_43 ] ;
memset ( V_42 , 0 , sizeof( V_42 ) ) ;
V_11 -> V_44 [ 0 ] = 0 ;
for ( V_10 = 0 ; V_10 < V_45 && ( ! V_10 || V_41 -> V_46 [ V_10 ] ) ; ++ V_10 ) {
char V_47 [] = L_1 ;
int V_48 = V_41 -> V_46 [ V_10 ] ;
struct V_1 * V_49 ;
int V_50 = - 1 , V_8 , V_51 ;
struct V_13 * V_14 = NULL ;
if ( V_48 < 0 || V_48 >= V_43 ) {
ERROR ( L_2 , V_48 ) ;
return 0 ;
}
if ( V_48 == V_2 -> V_48 ) {
ERROR ( L_3 ) ;
return 0 ;
}
if ( V_42 [ V_48 ] ) {
ERROR ( L_4 , V_48 ) ;
return 0 ;
}
snprintf ( V_47 , sizeof( V_47 ) , L_5 , V_48 ) ;
V_47 [ sizeof( V_47 ) - 1 ] = 0 ;
V_49 = V_42 [ V_48 ] = F_11 ( V_47 ) ;
if ( ! V_49 ) {
ERROR ( L_6 , V_48 ) ;
return 0 ;
}
while ( ( V_50 = F_12 ( V_49 , V_52 ,
V_50 + 1 ) ) > - 1 ) {
V_8 = F_13 ( V_49 , V_50 ) ;
if ( V_8 <= 0 ) {
ERROR ( L_7
L_8 ,
V_8 , V_48 , V_50 ) ;
return 0 ;
}
V_14 = F_7 ( sizeof( * V_14 ) , V_39 ) ;
if ( ! V_14 ) {
ERROR ( L_9 ) ;
return 0 ;
}
V_14 -> V_2 = V_49 ;
V_14 -> V_48 = V_48 ;
V_14 -> V_19 = V_50 ;
V_14 -> V_53 = V_52 ;
V_14 -> V_8 = V_8 ;
V_14 -> V_34 = V_11 -> V_8 ;
while ( V_8 -- )
V_11 -> V_28 [ V_11 -> V_8 ++ ] = V_14 ;
V_51 = V_11 -> V_12 * sizeof( V_14 ) ;
V_11 -> V_15 =
Realloc ( V_11 -> V_15 ,
++ V_11 -> V_12 * sizeof( V_14 ) , V_51 ) ;
if ( ! V_11 -> V_15 ) {
ERROR ( L_10
L_11 ) ;
return 0 ;
}
V_11 -> V_15 [ V_11 -> V_12 - 1 ] = V_14 ;
{
char V_54 [ 20 ] ;
int V_55 =
V_56 - strlen ( V_11 -> V_44 ) - 1 ;
snprintf ( V_54 , sizeof( V_54 ) , L_12 , V_2 -> V_48 ,
V_14 -> V_19 ) ;
V_54 [ sizeof( V_54 ) - 1 ] = 0 ;
strncat ( V_11 -> V_44 , V_54 , V_55 ) ;
}
}
}
if ( ! V_11 -> V_8 ) {
ERROR ( L_13 ) ;
return 0 ;
}
return 1 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 ;
int V_25 ;
F_15 ( L_14 , V_2 -> V_48 ) ;
if ( F_16 ( V_2 , sizeof( struct V_57 ) ) < 0 )
return - V_58 ;
if ( ! F_10 ( V_2 , V_41 ) )
return - V_20 ;
V_2 -> V_59 = V_11 -> V_44 ;
V_25 = F_17 ( V_2 , 1 ) ;
if ( V_25 )
return V_25 ;
V_4 = V_2 -> V_60 + 0 ;
V_4 -> type = V_52 ;
V_4 -> V_61 = V_62 | V_63 ;
V_4 -> V_64 = V_11 -> V_8 ;
V_4 -> V_65 = 1 ;
V_4 -> V_66 = & V_67 ;
V_4 -> V_68 = F_1 ;
V_4 -> V_69 = F_4 ;
F_15 ( L_15
L_16
L_17 ,
V_11 -> V_8 , V_11 -> V_12 ) ;
return 1 ;
}
static void F_18 ( struct V_1 * V_2 )
{
unsigned long V_70 = 0 ;
if ( V_11 ) {
while ( V_11 -> V_12 -- && V_11 -> V_15 ) {
struct V_13 * V_14 ;
V_14 = V_11 -> V_15 [ V_11 -> V_12 ] ;
if ( ! V_14 )
continue;
if ( ! ( V_70 & ( 0x1 << V_14 -> V_48 ) ) ) {
F_19 ( V_14 -> V_2 ) ;
V_70 |= ( 0x1 << V_14 -> V_48 ) ;
}
F_9 ( V_14 ) ;
}
F_9 ( V_11 -> V_15 ) ;
V_11 -> V_15 = NULL ;
F_9 ( V_11 ) ;
V_2 -> V_71 = NULL ;
}
}
