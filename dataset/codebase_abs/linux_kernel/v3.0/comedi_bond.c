static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( L_1 , V_2 -> V_7 ) ;
if ( F_3 ( V_2 , sizeof( struct V_8 ) ) < 0 )
return - V_9 ;
if ( ! F_4 ( V_2 , V_4 ) )
return - V_10 ;
V_2 -> V_11 = V_12 -> V_13 ;
if ( F_5 ( V_2 , 1 ) < 0 )
return - V_9 ;
V_6 = V_2 -> V_14 + 0 ;
V_6 -> type = V_15 ;
V_6 -> V_16 = V_17 | V_18 ;
V_6 -> V_19 = V_12 -> V_20 ;
V_6 -> V_21 = 1 ;
V_6 -> V_22 = & V_23 ;
V_6 -> V_24 = V_25 ;
V_6 -> V_26 = V_27 ;
F_2 ( L_2
L_3
L_4 ,
V_12 -> V_20 , V_12 -> V_28 ) ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_2 ( L_5 , V_2 -> V_7 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int V_25 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_29 * V_30 , unsigned int * V_31 )
{
#define F_8 (sizeof(unsigned int)*8)
unsigned V_20 = F_8 , V_32 = 0 , V_33 ;
if ( V_30 -> V_34 != 2 )
return - V_10 ;
if ( V_12 -> V_20 < V_20 )
V_20 = V_12 -> V_20 ;
for ( V_33 = 0 ; V_32 < V_20 && V_33 < V_12 -> V_28 ; ++ V_33 ) {
struct V_35 * V_36 = V_12 -> V_37 [ V_33 ] ;
unsigned int V_38 = ( ( 1 << V_36 -> V_20 ) - 1 ) ;
unsigned int V_39 , V_40 ;
if ( V_36 -> V_20 >= F_8 )
V_38 = ( unsigned int ) ( - 1 ) ;
V_39 = ( V_31 [ 0 ] >> V_32 ) & V_38 ;
V_40 = ( V_31 [ 1 ] >> V_32 ) & V_38 ;
if ( F_9 ( V_36 -> V_2 , V_36 -> V_41 , V_39 ,
& V_40 ) != 2 )
return - V_10 ;
V_31 [ 1 ] &= ~ ( V_38 << V_32 ) ;
V_31 [ 1 ] |= ( V_40 & V_38 ) << V_32 ;
V_6 -> V_42 = V_31 [ 1 ] ;
V_32 += V_36 -> V_20 ;
}
return V_30 -> V_34 ;
}
static int V_27 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_29 * V_30 , unsigned int * V_31 )
{
int V_43 = F_10 ( V_30 -> V_44 ) , V_45 , V_46 = V_6 -> V_46 ;
unsigned int V_47 ;
struct V_35 * V_36 ;
if ( V_43 < 0 || V_43 >= V_12 -> V_20 )
return - V_10 ;
V_36 = V_12 -> V_48 [ V_43 ] ;
switch ( V_31 [ 0 ] ) {
case V_49 :
V_47 = V_50 ;
V_46 |= 1 << V_43 ;
break;
case V_51 :
V_47 = V_52 ;
V_46 &= ~ ( 1 << V_43 ) ;
break;
case V_53 :
V_31 [ 1 ] =
( V_46 & ( 1 << V_43 ) ) ? V_50 : V_52 ;
return V_30 -> V_34 ;
break;
default:
return - V_10 ;
break;
}
V_43 -= V_36 -> V_54 ;
V_45 = F_11 ( V_36 -> V_2 , V_36 -> V_41 , V_43 , V_47 ) ;
if ( V_45 != 1 )
return - V_10 ;
V_6 -> V_46 = V_46 ;
return V_30 -> V_34 ;
}
static void * Realloc ( const void * V_55 , T_1 V_56 , T_1 V_57 )
{
void * V_58 = F_12 ( V_56 , V_59 ) ;
if ( V_58 && V_55 )
memcpy ( V_58 , V_55 , F_13 ( V_57 , V_56 ) ) ;
F_14 ( V_55 ) ;
return V_58 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_33 ;
struct V_1 * V_60 [ V_61 ] ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
V_12 -> V_13 [ 0 ] = 0 ;
for ( V_33 = 0 ; V_33 < V_62 && ( ! V_33 || V_4 -> V_63 [ V_33 ] ) ; ++ V_33 ) {
char V_64 [] = L_6 ;
int V_7 = V_4 -> V_63 [ V_33 ] ;
struct V_1 * V_65 ;
int V_66 = - 1 , V_20 , V_67 ;
struct V_35 * V_36 = NULL ;
if ( V_7 < 0 || V_7 >= V_61 ) {
ERROR ( L_7 , V_7 ) ;
return 0 ;
}
if ( V_7 == V_2 -> V_7 ) {
ERROR ( L_8 ) ;
return 0 ;
}
if ( V_60 [ V_7 ] ) {
ERROR ( L_9 , V_7 ) ;
return 0 ;
}
snprintf ( V_64 , sizeof( V_64 ) , L_10 , V_7 ) ;
V_64 [ sizeof( V_64 ) - 1 ] = 0 ;
V_65 = V_60 [ V_7 ] = F_15 ( V_64 ) ;
if ( ! V_65 ) {
ERROR ( L_11 , V_7 ) ;
return 0 ;
}
while ( ( V_66 = F_16 ( V_65 , V_15 ,
V_66 + 1 ) ) > - 1 ) {
V_20 = F_17 ( V_65 , V_66 ) ;
if ( V_20 <= 0 ) {
ERROR ( L_12
L_13 ,
V_20 , V_7 , V_66 ) ;
return 0 ;
}
V_36 = F_12 ( sizeof( * V_36 ) , V_59 ) ;
if ( ! V_36 ) {
ERROR ( L_14 ) ;
return 0 ;
}
V_36 -> V_2 = V_65 ;
V_36 -> V_7 = V_7 ;
V_36 -> V_41 = V_66 ;
V_36 -> V_68 = V_15 ;
V_36 -> V_20 = V_20 ;
V_36 -> V_54 = V_12 -> V_20 ;
while ( V_20 -- )
V_12 -> V_48 [ V_12 -> V_20 ++ ] = V_36 ;
V_67 = V_12 -> V_28 * sizeof( V_36 ) ;
V_12 -> V_37 =
Realloc ( V_12 -> V_37 ,
++ V_12 -> V_28 * sizeof( V_36 ) , V_67 ) ;
if ( ! V_12 -> V_37 ) {
ERROR ( L_15
L_16 ) ;
return 0 ;
}
V_12 -> V_37 [ V_12 -> V_28 - 1 ] = V_36 ;
{
char V_69 [ 20 ] ;
int V_70 =
V_71 - strlen ( V_12 -> V_13 ) - 1 ;
snprintf ( V_69 , sizeof( V_69 ) , L_17 , V_2 -> V_7 ,
V_36 -> V_41 ) ;
V_69 [ sizeof( V_69 ) - 1 ] = 0 ;
strncat ( V_12 -> V_13 , V_69 , V_70 ) ;
}
}
}
if ( ! V_12 -> V_20 ) {
ERROR ( L_18 ) ;
return 0 ;
}
return 1 ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned long V_72 = 0 ;
if ( V_12 ) {
while ( V_12 -> V_28 -- && V_12 -> V_37 ) {
struct V_35 * V_36 ;
V_36 = V_12 -> V_37 [ V_12 -> V_28 ] ;
if ( ! V_36 )
continue;
if ( ! ( V_72 & ( 0x1 << V_36 -> V_7 ) ) ) {
F_18 ( V_36 -> V_2 ) ;
V_72 |= ( 0x1 << V_36 -> V_7 ) ;
}
F_14 ( V_36 ) ;
}
F_14 ( V_12 -> V_37 ) ;
V_12 -> V_37 = NULL ;
F_14 ( V_12 ) ;
V_2 -> V_73 = NULL ;
}
}
static int T_2 F_19 ( void )
{
return F_20 ( & V_74 ) ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_74 ) ;
}
