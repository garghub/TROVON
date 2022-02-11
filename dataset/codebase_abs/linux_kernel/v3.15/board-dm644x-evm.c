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
. V_29 = 0 ,
. V_30 = 2 ,
. V_18 = ( void V_31 * ) V_26 ,
} ,
{
. V_29 = V_32 ,
. V_30 = 4 ,
. V_18 = V_18 ,
} ,
} ;
int V_9 ;
if ( ! V_25 )
return - V_33 ;
V_28 [ 0 ] . V_34 = V_25 -> V_34 ;
V_28 [ 1 ] . V_34 = V_25 -> V_34 ;
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
F_34 () ;
}
static int F_35 ( struct V_40 * V_41 )
{
unsigned int V_42 ;
V_42 = F_36 ( V_41 , 26 ) ;
F_37 ( V_41 , 26 , ( V_42 | 0x800 ) ) ;
return 0 ;
}
static T_2 void F_38 ( void )
{
int V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 = & V_46 ;
V_43 = F_39 () ;
if ( V_43 )
F_40 ( L_16 , V_48 , V_43 ) ;
V_45 = F_41 ( NULL , L_17 ) ;
F_42 ( V_45 ) ;
if ( V_49 ) {
if ( V_50 || V_51 )
F_43 ( L_18
L_19
L_20 ) ;
F_44 () ;
} else if ( V_50 || V_51 ) {
F_45 ( V_52 ) ;
F_45 ( V_53 ) ;
if ( V_50 ) {
F_46 ( & V_54 ) ;
if ( F_47 ( & V_54 ) )
F_40 ( L_21 ,
V_48 ) ;
V_8 [ 7 ] . V_55 = L_22 ;
if ( V_51 )
F_43 ( L_23
L_24 ) ;
} else if ( V_51 )
F_46 ( & V_56 ) ;
}
F_48 ( V_57 ,
F_32 ( V_57 ) ) ;
F_28 () ;
F_49 ( 0 , & V_58 ) ;
F_50 ( & V_59 , & V_60 ) ;
F_51 ( V_61 ) ;
F_52 ( & V_62 ) ;
F_53 ( 1000 , 8 ) ;
if ( F_54 ( V_63 ) ) {
V_47 -> V_64 -> V_65 = V_66 ;
F_55 ( V_67 , V_68 ,
F_35 ) ;
}
}
