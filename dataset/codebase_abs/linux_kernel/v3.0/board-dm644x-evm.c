static int
F_1 ( struct V_1 * V_2 , int V_3 , unsigned V_4 , void * V_5 )
{
struct V_6 * V_7 = V_8 ;
int V_9 ;
while ( V_4 -- ) {
V_7 -> V_3 = V_3 ++ ;
V_7 ++ ;
}
V_10 = F_2 ( L_1 , 0 ) ;
F_3 ( V_10 ,
& V_11 , sizeof V_11 ) ;
V_10 -> V_12 . V_13 = & V_2 -> V_12 ;
V_9 = F_4 ( V_10 ) ;
if ( V_9 < 0 ) {
F_5 ( V_10 ) ;
V_10 = NULL ;
}
return V_9 ;
}
static int
F_6 ( struct V_1 * V_2 , int V_3 , unsigned V_4 , void * V_5 )
{
if ( V_10 ) {
F_7 ( V_10 ) ;
V_10 = NULL ;
}
return 0 ;
}
static T_1
F_8 ( struct V_14 * V_15 , struct V_16 * V_17 , char * V_18 )
{
char * V_19 = F_9 ( V_20 ) ? L_2 : L_3 ;
strcpy ( V_18 , V_19 ) ;
return strlen ( V_19 ) ;
}
static int
F_10 ( struct V_1 * V_2 , int V_3 , unsigned V_4 , void * V_5 )
{
int V_9 ;
V_20 = V_3 + 7 ;
V_9 = F_11 ( V_20 , L_4 ) ;
if ( V_9 == 0 )
V_9 = F_12 ( V_20 ) ;
if ( V_9 == 0 )
V_9 = F_13 ( & V_2 -> V_12 , & V_21 ) ;
else
F_14 ( V_20 ) ;
if ( V_9 != 0 )
V_20 = - V_22 ;
F_11 ( V_3 + 3 , L_5 ) ;
F_15 ( V_3 + 3 , 0 ) ;
F_11 ( V_3 + 2 , L_6 ) ;
F_15 ( V_3 + 2 , 0 ) ;
F_11 ( V_3 + 1 , L_7 ) ;
F_15 ( V_3 + 1 , 0 ) ;
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 , int V_3 , unsigned V_4 , void * V_5 )
{
F_14 ( V_3 + 1 ) ;
F_14 ( V_3 + 2 ) ;
F_14 ( V_3 + 3 ) ;
if ( V_20 > 0 ) {
F_17 ( & V_2 -> V_12 , & V_21 ) ;
F_14 ( V_20 ) ;
}
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , int V_3 , unsigned V_4 , void * V_5 )
{
F_11 ( V_3 + 0 , L_8 ) ;
F_15 ( V_3 + 0 , 1 ) ;
F_11 ( V_3 + 1 , L_9 ) ;
F_15 ( V_3 + 1 , 1 ) ;
F_11 ( V_3 + 2 , L_10 ) ;
F_15 ( V_3 + 2 , 1 ) ;
F_11 ( V_3 + 3 , L_11 ) ;
F_15 ( V_3 + 3 , 0 ) ;
F_11 ( V_3 + 5 , L_12 ) ;
F_15 ( V_3 + 5 , 1 ) ;
F_11 ( V_3 + 6 , L_13 ) ;
F_15 ( V_3 + 6 , 0 ) ;
F_11 ( V_3 + 7 , L_14 ) ;
F_15 ( V_3 + 7 , 1 ) ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 , int V_3 , unsigned V_4 , void * V_5 )
{
F_14 ( V_3 + 7 ) ;
F_14 ( V_3 + 6 ) ;
F_14 ( V_3 + 5 ) ;
F_14 ( V_3 + 3 ) ;
F_14 ( V_3 + 2 ) ;
F_14 ( V_3 + 1 ) ;
F_14 ( V_3 + 0 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
V_25 = V_2 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
V_25 = NULL ;
return 0 ;
}
static int F_22 ( void )
{
static const char V_26 [ 2 ] = { 2 , 4 , } ;
char V_18 [ 4 ] ;
struct V_27 V_28 [ 2 ] = {
{
. V_29 = V_25 -> V_29 ,
. V_30 = 0 ,
. V_31 = 2 ,
. V_18 = ( void V_32 * ) V_26 ,
} ,
{
. V_29 = V_25 -> V_29 ,
. V_30 = V_33 ,
. V_31 = 4 ,
. V_18 = V_18 ,
} ,
} ;
int V_9 ;
if ( ! V_25 )
return - V_34 ;
V_9 = F_23 ( V_25 -> V_35 , V_28 , 2 ) ;
if ( V_9 < 0 )
return V_9 ;
F_24 ( & V_25 -> V_12 ,
L_15 ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ) ;
return ( V_18 [ 3 ] << 8 ) | V_18 [ 2 ] ;
}
static int F_25 ( int V_36 )
{
int V_9 = F_22 () ;
return ( V_9 < 0 ) ? V_9 : ! ( V_9 & F_26 ( 1 ) ) ;
}
static int F_27 ( int V_36 )
{
int V_9 = F_22 () ;
return ( V_9 < 0 ) ? V_9 : V_9 & F_26 ( 6 + 8 ) ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_37 ) ;
F_30 ( & V_38 ) ;
F_31 ( 1 , V_39 , F_32 ( V_39 ) ) ;
}
static void T_2
F_33 ( void )
{
F_34 ( & V_40 ) ;
F_35 () ;
}
static int F_36 ( struct V_41 * V_42 )
{
unsigned int V_43 ;
V_43 = F_37 ( V_42 , 26 ) ;
F_38 ( V_42 , 26 , ( V_43 | 0x800 ) ) ;
return 0 ;
}
static T_2 void F_39 ( void )
{
struct V_44 * V_45 ;
struct V_46 * V_47 = & V_46 ;
V_45 = F_40 ( NULL , L_16 ) ;
F_41 ( V_45 ) ;
if ( V_48 ) {
if ( V_49 || V_50 )
F_42 ( L_17
L_18
L_19 ) ;
F_43 () ;
} else if ( V_49 || V_50 ) {
F_44 ( V_51 ) ;
F_44 ( V_52 ) ;
if ( V_49 ) {
F_45 ( & V_53 ) ;
V_8 [ 7 ] . V_54 = L_20 ;
if ( V_50 )
F_42 ( L_21
L_22 ) ;
} else if ( V_50 )
F_45 ( & V_55 ) ;
}
F_46 ( V_56 ,
F_32 ( V_56 ) ) ;
F_28 () ;
F_47 ( 0 , & V_57 ) ;
F_48 ( & V_58 ) ;
F_49 ( & V_59 ) ;
F_50 ( 1000 , 8 ) ;
V_47 -> V_60 -> V_61 = V_62 ;
F_51 ( V_63 , V_64 ,
F_36 ) ;
}
