static int
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
T_1 V_5 [ 2 ] ;
int V_6 ;
V_5 [ 0 ] = V_3 ;
V_5 [ 1 ] = V_4 ;
V_6 = F_2 ( V_2 -> V_7 , ( const char * ) V_5 , 2 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 != 2 )
return - V_8 ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_9 , V_4 ;
int V_6 ;
V_9 = ( T_1 ) V_3 ;
V_6 = F_2 ( V_2 -> V_7 , & V_9 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 != 1 )
return - V_8 ;
V_6 = F_4 ( V_2 -> V_7 , ( char * ) & V_4 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_5 [ 2 ] ;
T_2 V_11 ;
V_5 [ 1 ] = F_3 ( V_2 , V_10 ) ;
V_5 [ 0 ] = F_3 ( V_2 , V_10 + 1 ) ;
V_11 = V_5 [ 1 ] + ( V_5 [ 0 ] << 8 ) ;
return ( V_11 == 0xffff ? 0 : ( 90000 * 60 ) / V_11 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_12 )
{
F_7 ( V_2 , V_12 , 0 ) ;
if ( V_2 -> type == V_13 )
F_7 ( V_2 , V_12 , 1 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_12 , int V_14 )
{
T_1 V_15 ;
if ( V_12 > 0xff )
V_12 = 0xff ;
else if ( V_12 < - 1 )
V_12 = 0 ;
if ( V_2 -> type == V_16 && V_14 == 1 )
return;
if ( V_2 -> V_17 [ V_14 ] != V_12 ) {
if ( V_18 ) {
if ( V_12 == - 1 )
F_8 ( V_19 L_1
L_2 , V_20 [ V_14 + 1 ] ) ;
else
F_8 ( V_19 L_3
L_2 , V_12 , V_20 [ V_14 + 1 ] ) ;
}
} else
return;
if ( V_12 >= 0 ) {
V_15 = F_3 ( V_2 , V_21 [ V_14 ] ) ;
V_15 &= ~ V_22 ;
F_1 ( V_2 , V_21 [ V_14 ] ,
V_15 | V_23 | V_2 -> V_24 [ V_14 ] ) ;
F_1 ( V_2 , V_25 [ V_14 ] , V_12 ) ;
} else {
if( V_2 -> type == V_13 ) {
V_15 = F_3 ( V_2 ,
V_21 [ V_14 ] ) & ( ~ V_23 ) ;
V_15 &= ~ V_22 ;
V_15 |= V_2 -> V_24 [ V_14 ] ;
F_1 ( V_2 ,
V_21 [ V_14 ] , V_15 | V_26 [ V_14 ] ) ;
} else {
V_15 = F_3 ( V_2 , V_21 [ V_14 ] ) ;
V_15 &= ~ V_22 ;
V_15 |= V_2 -> V_24 [ V_14 ] ;
F_1 ( V_2 , V_21 [ V_14 ] , V_15 & ( ~ V_27 ) ) ;
}
}
V_2 -> V_17 [ V_14 ] = V_12 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
for ( V_28 = 0 ; V_28 < 3 ; V_28 ++ )
V_2 -> V_29 [ V_28 ] = F_3 ( V_2 , V_30 [ V_28 ] ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_29 [ 0 ] != V_2 -> V_31 [ 0 ]
|| V_2 -> V_29 [ 1 ] != V_2 -> V_31 [ 1 ]
|| V_2 -> V_29 [ 2 ] != V_2 -> V_31 [ 2 ] ) {
F_8 ( V_32 L_4
L_5
L_6
L_7 ,
V_2 -> V_29 [ 0 ] , V_2 -> V_29 [ 1 ] , V_2 -> V_29 [ 2 ] ,
V_2 -> V_33 [ 0 ] , V_2 -> V_33 [ 1 ] , V_2 -> V_33 [ 2 ] ,
F_5 ( V_2 , V_34 [ 0 ] ) ) ;
}
V_2 -> V_31 [ 0 ] = V_2 -> V_29 [ 0 ] ;
V_2 -> V_31 [ 1 ] = V_2 -> V_29 [ 1 ] ;
V_2 -> V_31 [ 2 ] = V_2 -> V_29 [ 2 ] ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
int V_28 = 0 ;
for ( V_28 = 1 ; V_28 < 3 ; V_28 ++ ) {
int V_36 = 0 ;
int V_37 = ( V_2 -> type == V_13 && V_28 == 2 ) ;
int V_38 = V_2 -> V_29 [ V_28 ] - V_2 -> V_33 [ V_28 ] ;
if ( V_38 > - 1 ) {
int V_39 = ( 255 - V_40 ) / 7 ;
int V_41 = 0 ;
if ( abs ( V_38 - V_2 -> V_42 [ V_37 ] ) < 2 )
continue;
V_36 = 1 ;
V_41 = V_40 + ( ( V_38 - 1 ) * V_39 ) ;
if ( V_41 < V_40 )
V_41 = V_40 ;
if ( V_41 > 255 )
V_41 = 255 ;
if ( V_18 )
F_8 ( V_19 L_8
L_9 ,
V_41 , V_38 ,
V_20 [ V_37 + 1 ] ) ;
F_6 ( V_2 , V_41 ) ;
V_2 -> V_42 [ V_37 ] = V_38 ;
} else if ( V_38 < - 2 ) {
if ( V_28 == 2 && V_35 < - 1 ) {
if ( V_2 -> V_17 [ V_37 ] != 0 )
if ( V_18 )
F_8 ( V_19 L_10
L_11 ) ;
F_6 ( V_2 , 0 ) ;
}
}
V_35 = V_38 ;
if ( V_36 )
return;
}
}
static int F_12 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
F_13 () ;
while( ! F_14 () ) {
F_15 () ;
F_16 ( 2000 ) ;
#ifndef F_17
if ( V_40 != - 1 )
F_9 ( V_2 ) ;
#else
F_9 ( V_2 ) ;
#endif
if ( V_40 != - 1 )
F_11 ( V_2 ) ;
#ifdef F_17
F_10 ( V_2 ) ;
#endif
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , int V_28 )
{
V_2 -> V_33 [ V_28 ] = V_44 [ V_28 ] + V_45 ;
F_1 ( V_2 , V_46 [ V_28 ] , V_2 -> V_33 [ V_28 ] ) ;
V_2 -> V_33 [ V_28 ] = V_47 [ V_28 ] + V_45 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_7 -> V_50 . V_51 ;
struct V_52 * V_50 ;
int V_53 ;
V_2 -> V_54 = F_20 ( V_49 , L_12 , NULL ) ;
if ( ! V_2 -> V_54 )
return;
V_50 = & V_2 -> V_54 -> V_50 ;
F_21 ( V_50 , V_2 ) ;
V_53 = F_22 ( V_50 , & V_55 ) ;
V_53 |= F_22 ( V_50 , & V_56 ) ;
V_53 |= F_22 ( V_50 , & V_57 ) ;
V_53 |= F_22 ( V_50 , & V_58 ) ;
V_53 |= F_22 ( V_50 , & V_59 ) ;
V_53 |= F_22 ( V_50 , & V_60 ) ;
V_53 |= F_22 ( V_50 , & V_61 ) ;
V_53 |= F_22 ( V_50 , & V_62 ) ;
V_53 |= F_22 ( V_50 , & V_63 ) ;
if( V_2 -> type == V_13 )
V_53 |= F_22 ( V_50 , & V_64 ) ;
if ( V_53 )
F_8 ( V_65
L_13 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_52 * V_50 ;
if ( ! V_2 -> V_54 )
return;
V_50 = & V_2 -> V_54 -> V_50 ;
F_24 ( V_50 , & V_55 ) ;
F_24 ( V_50 , & V_56 ) ;
F_24 ( V_50 , & V_57 ) ;
F_24 ( V_50 , & V_58 ) ;
F_24 ( V_50 , & V_59 ) ;
F_24 ( V_50 , & V_60 ) ;
F_24 ( V_50 , & V_61 ) ;
F_24 ( V_50 , & V_62 ) ;
F_24 ( V_50 , & V_63 ) ;
if ( V_2 -> type == V_13 )
F_24 ( V_50 , & V_64 ) ;
F_25 ( V_2 -> V_54 ) ;
}
static int F_26 ( struct V_66 * V_67 ,
const struct V_68 * V_69 )
{
struct V_48 * V_49 = V_67 -> V_50 . V_51 ;
struct V_1 * V_2 ;
const T_3 * V_70 ;
int V_28 , V_6 , V_71 , V_72 = 0 ;
if ( ! V_49 )
return - V_73 ;
V_70 = F_27 ( V_49 , L_14 , NULL ) ;
if ( ! V_70 )
return - V_73 ;
V_71 = F_28 ( V_70 ) ;
F_8 ( V_32 L_15 ,
V_71 , V_71 == 1 ? L_16 : L_17 ) ;
if ( V_71 != 1 )
return - V_73 ;
if ( F_27 ( V_49 , L_18 , NULL ) ) {
for ( V_28 = 0 ; V_28 < 3 ; V_28 ++ ) {
V_20 [ V_28 ] = F_27 ( V_49 ,
L_18 , NULL ) + V_72 ;
if ( V_20 [ V_28 ] == NULL )
V_20 [ V_28 ] = L_16 ;
F_8 ( V_32 L_19 , V_28 , V_20 [ V_28 ] ) ;
V_72 += strlen ( V_20 [ V_28 ] ) + 1 ;
}
}
V_2 = F_29 ( sizeof( struct V_1 ) , V_74 ) ;
if ( ! V_2 )
return - V_75 ;
F_30 ( V_67 , V_2 ) ;
V_2 -> V_7 = V_67 ;
V_2 -> type = V_69 -> V_76 ;
V_6 = F_3 ( V_2 , V_77 ) ;
if ( V_6 < 0 ) {
F_31 ( & V_67 -> V_50 , L_20 ) ;
F_32 ( V_2 ) ;
return - V_8 ;
}
if ( V_40 == - 1 )
V_40 = 64 ;
if ( V_2 -> type == V_13 ) {
F_8 ( V_32 L_21 ) ;
F_1 ( V_2 , V_77 , 1 ) ;
} else
F_8 ( V_32 L_22 ) ;
for ( V_28 = 0 ; V_28 < 3 ; V_28 ++ ) {
V_2 -> V_78 [ V_28 ] = F_3 ( V_2 , V_46 [ V_28 ] ) ;
F_18 ( V_2 , V_28 ) ;
}
F_8 ( V_32 L_23
L_24 ,
V_2 -> V_78 [ 0 ] , V_2 -> V_78 [ 1 ] ,
V_2 -> V_78 [ 2 ] , V_2 -> V_33 [ 0 ] , V_2 -> V_33 [ 1 ] ,
V_2 -> V_33 [ 2 ] ) ;
V_2 -> V_24 [ 0 ] = F_3 ( V_2 , V_21 [ 0 ] ) & V_22 ;
V_2 -> V_24 [ 1 ] = F_3 ( V_2 , V_21 [ 1 ] ) & V_22 ;
V_2 -> V_17 [ 0 ] = - 2 ;
V_2 -> V_17 [ 1 ] = - 2 ;
V_2 -> V_42 [ 0 ] = - 80 ;
V_2 -> V_42 [ 1 ] = - 80 ;
if ( V_40 != - 1 ) {
F_6 ( V_2 , 0 ) ;
} else {
F_6 ( V_2 , - 1 ) ;
}
V_2 -> V_79 = F_33 ( F_12 , V_2 , L_25 ) ;
if ( V_2 -> V_79 == F_34 ( - V_75 ) ) {
F_8 ( V_32 L_26 ) ;
V_2 -> V_79 = NULL ;
return - V_75 ;
}
F_19 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_36 ( V_67 ) ;
int V_28 ;
F_23 ( V_2 ) ;
if ( V_2 -> V_79 != NULL )
F_37 ( V_2 -> V_79 ) ;
F_8 ( V_32 L_27
L_28 ,
V_2 -> V_33 [ 0 ] , V_2 -> V_33 [ 1 ] , V_2 -> V_33 [ 2 ] ,
V_2 -> V_78 [ 0 ] , V_2 -> V_78 [ 1 ] ,
V_2 -> V_78 [ 2 ] ) ;
for ( V_28 = 0 ; V_28 < 3 ; V_28 ++ )
F_1 ( V_2 , V_46 [ V_28 ] , V_2 -> V_78 [ V_28 ] ) ;
F_6 ( V_2 , - 1 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static int T_4 F_38 ( void )
{
#ifndef F_39
F_40 ( L_29 ) ;
#endif
return F_41 ( & V_80 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_80 ) ;
}
