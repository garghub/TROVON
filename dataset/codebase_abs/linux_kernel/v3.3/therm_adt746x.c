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
static int
F_5 ( struct V_10 * V_11 )
{
unsigned long V_12 ;
struct V_13 V_14 ;
struct V_15 * V_16 ;
if ( strncmp ( V_11 -> V_17 , L_1 , 5 ) )
return - V_8 ;
V_12 = F_6 ( V_11 -> V_17 + 6 , NULL , 10 ) ;
if ( V_12 != V_18 )
return - V_8 ;
memset ( & V_14 , 0 , sizeof( struct V_13 ) ) ;
F_7 ( V_14 . type , L_2 , V_19 ) ;
V_14 . V_20 = V_21 ;
V_16 = F_8 ( V_11 , & V_14 ) ;
if ( ! V_16 )
return - V_8 ;
F_9 ( & V_16 -> V_22 , & V_23 . V_24 ) ;
return 0 ;
}
static int
F_10 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
int V_25 ;
F_12 () ;
if ( V_26 != NULL ) {
F_13 ( V_26 ) ;
}
F_14 ( V_27 L_3
L_4 ,
V_2 -> V_28 [ 0 ] , V_2 -> V_28 [ 1 ] , V_2 -> V_28 [ 2 ] ,
V_2 -> V_29 [ 0 ] , V_2 -> V_29 [ 1 ] ,
V_2 -> V_29 [ 2 ] ) ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ )
F_1 ( V_2 , V_30 [ V_25 ] , V_2 -> V_29 [ V_25 ] ) ;
F_15 ( V_2 , - 1 ) ;
V_1 = NULL ;
F_16 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_20 )
{
T_1 V_5 [ 2 ] ;
T_2 V_31 ;
V_5 [ 1 ] = F_3 ( V_2 , V_20 ) ;
V_5 [ 0 ] = F_3 ( V_2 , V_20 + 1 ) ;
V_31 = V_5 [ 1 ] + ( V_5 [ 0 ] << 8 ) ;
return ( V_31 == 0xffff ? 0 : ( 90000 * 60 ) / V_31 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_32 )
{
F_18 ( V_2 , V_32 , 0 ) ;
if ( V_33 == V_34 )
F_18 ( V_2 , V_32 , 1 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_32 , int V_35 )
{
T_1 V_36 ;
if ( V_32 > 0xff )
V_32 = 0xff ;
else if ( V_32 < - 1 )
V_32 = 0 ;
if ( V_33 == V_37 && V_35 == 1 )
return;
if ( V_2 -> V_38 [ V_35 ] != V_32 ) {
if ( V_39 ) {
if ( V_32 == - 1 )
F_14 ( V_40 L_5
L_6 , V_41 [ V_35 + 1 ] ) ;
else
F_14 ( V_40 L_7
L_6 , V_32 , V_41 [ V_35 + 1 ] ) ;
}
} else
return;
if ( V_32 >= 0 ) {
V_36 = F_3 ( V_2 , V_42 [ V_35 ] ) ;
V_36 &= ~ V_43 ;
F_1 ( V_2 , V_42 [ V_35 ] ,
V_36 | V_44 | V_2 -> V_45 [ V_35 ] ) ;
F_1 ( V_2 , V_46 [ V_35 ] , V_32 ) ;
} else {
if( V_33 == V_34 ) {
V_36 = F_3 ( V_2 ,
V_42 [ V_35 ] ) & ( ~ V_44 ) ;
V_36 &= ~ V_43 ;
V_36 |= V_2 -> V_45 [ V_35 ] ;
F_1 ( V_2 ,
V_42 [ V_35 ] , V_36 | V_47 [ V_35 ] ) ;
} else {
V_36 = F_3 ( V_2 , V_42 [ V_35 ] ) ;
V_36 &= ~ V_43 ;
V_36 |= V_2 -> V_45 [ V_35 ] ;
F_1 ( V_2 , V_42 [ V_35 ] , V_36 & ( ~ V_48 ) ) ;
}
}
V_2 -> V_38 [ V_35 ] = V_32 ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ )
V_2 -> V_49 [ V_25 ] = F_3 ( V_2 , V_50 [ V_25 ] ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 [ 0 ] != V_2 -> V_51 [ 0 ]
|| V_2 -> V_49 [ 1 ] != V_2 -> V_51 [ 1 ]
|| V_2 -> V_49 [ 2 ] != V_2 -> V_51 [ 2 ] ) {
F_14 ( V_27 L_8
L_9
L_10
L_11 ,
V_2 -> V_49 [ 0 ] , V_2 -> V_49 [ 1 ] , V_2 -> V_49 [ 2 ] ,
V_2 -> V_28 [ 0 ] , V_2 -> V_28 [ 1 ] , V_2 -> V_28 [ 2 ] ,
F_17 ( V_2 , V_52 [ 0 ] ) ) ;
}
V_2 -> V_51 [ 0 ] = V_2 -> V_49 [ 0 ] ;
V_2 -> V_51 [ 1 ] = V_2 -> V_49 [ 1 ] ;
V_2 -> V_51 [ 2 ] = V_2 -> V_49 [ 2 ] ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_53 = 0 ;
int V_25 = 0 ;
for ( V_25 = 1 ; V_25 < 3 ; V_25 ++ ) {
int V_54 = 0 ;
int V_55 = ( V_33 == V_34 && V_25 == 2 ) ;
int V_56 = V_2 -> V_49 [ V_25 ] - V_2 -> V_28 [ V_25 ] ;
if ( V_56 > - 1 ) {
int V_57 = ( 255 - V_58 ) / 7 ;
int V_59 = 0 ;
if ( abs ( V_56 - V_2 -> V_60 [ V_55 ] ) < 2 )
continue;
V_54 = 1 ;
V_59 = V_58 + ( ( V_56 - 1 ) * V_57 ) ;
if ( V_59 < V_58 )
V_59 = V_58 ;
if ( V_59 > 255 )
V_59 = 255 ;
if ( V_39 )
F_14 ( V_40 L_12
L_13 ,
V_59 , V_56 ,
V_41 [ V_55 + 1 ] ) ;
F_15 ( V_2 , V_59 ) ;
V_2 -> V_60 [ V_55 ] = V_56 ;
} else if ( V_56 < - 2 ) {
if ( V_25 == 2 && V_53 < - 1 ) {
if ( V_2 -> V_38 [ V_55 ] != 0 )
if ( V_39 )
F_14 ( V_40 L_14
L_15 ) ;
F_15 ( V_2 , 0 ) ;
}
}
V_53 = V_56 ;
if ( V_54 )
return;
}
}
static int F_22 ( void * V_61 )
{
struct V_1 * V_2 = V_61 ;
F_23 () ;
while( ! F_24 () ) {
F_25 () ;
F_26 ( 2000 ) ;
#ifndef F_27
if ( V_58 != - 1 )
F_19 ( V_2 ) ;
#else
F_19 ( V_2 ) ;
#endif
if ( V_58 != - 1 )
F_21 ( V_2 ) ;
#ifdef F_27
F_20 ( V_2 ) ;
#endif
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , int V_25 )
{
V_2 -> V_28 [ V_25 ] = V_62 [ V_25 ] + V_63 ;
F_1 ( V_2 , V_30 [ V_25 ] , V_2 -> V_28 [ V_25 ] ) ;
V_2 -> V_28 [ V_25 ] = V_64 [ V_25 ] + V_63 ;
}
static int F_29 ( struct V_15 * V_16 ,
const struct V_65 * V_66 )
{
struct V_1 * V_2 ;
int V_6 ;
int V_25 ;
if ( V_1 )
return 0 ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_67 ) ;
if ( ! V_2 )
return - V_68 ;
F_31 ( V_16 , V_2 ) ;
V_2 -> V_7 = V_16 ;
V_6 = F_3 ( V_2 , V_69 ) ;
if ( V_6 < 0 ) {
F_32 ( & V_16 -> V_70 , L_16 ) ;
F_16 ( V_2 ) ;
return - V_8 ;
}
if ( V_58 == - 1 )
V_58 = 64 ;
if( V_33 == V_34 ) {
F_14 ( V_27 L_17 ) ;
F_1 ( V_2 , V_69 , 1 ) ;
} else
F_14 ( V_27 L_18 ) ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ ) {
V_2 -> V_29 [ V_25 ] = F_3 ( V_2 , V_30 [ V_25 ] ) ;
F_28 ( V_2 , V_25 ) ;
}
F_14 ( V_27 L_19
L_20 ,
V_2 -> V_29 [ 0 ] , V_2 -> V_29 [ 1 ] ,
V_2 -> V_29 [ 2 ] , V_2 -> V_28 [ 0 ] , V_2 -> V_28 [ 1 ] ,
V_2 -> V_28 [ 2 ] ) ;
V_1 = V_2 ;
V_2 -> V_45 [ 0 ] = F_3 ( V_2 , V_42 [ 0 ] ) & V_43 ;
V_2 -> V_45 [ 1 ] = F_3 ( V_2 , V_42 [ 1 ] ) & V_43 ;
V_2 -> V_38 [ 0 ] = - 2 ;
V_2 -> V_38 [ 1 ] = - 2 ;
V_2 -> V_60 [ 0 ] = - 80 ;
V_2 -> V_60 [ 1 ] = - 80 ;
if ( V_58 != - 1 ) {
F_15 ( V_2 , 0 ) ;
} else {
F_15 ( V_2 , - 1 ) ;
}
V_26 = F_33 ( F_22 , V_2 , L_21 ) ;
if ( V_26 == F_34 ( - V_68 ) ) {
F_14 ( V_27 L_22 ) ;
V_26 = NULL ;
return - V_68 ;
}
F_35 () ;
return 0 ;
}
static int T_3
F_36 ( void )
{
struct V_71 * V_72 ;
const T_4 * V_73 ;
int V_25 = 0 , V_74 = 0 ;
V_72 = F_37 ( NULL , L_23 ) ;
if ( ! V_72 )
return - V_8 ;
if ( F_38 ( V_72 , L_24 ) )
V_33 = V_34 ;
else if ( F_38 ( V_72 , L_25 ) )
V_33 = V_37 ;
else {
F_39 ( V_72 ) ;
return - V_8 ;
}
V_73 = F_40 ( V_72 , L_26 , NULL ) ;
F_14 ( V_27 L_27 , * V_73 ,
( * V_73 == 1 ) ? L_28 : L_29 ) ;
if ( * V_73 != 1 ) {
F_39 ( V_72 ) ;
return - V_8 ;
}
V_73 = F_40 ( V_72 , L_30 , NULL ) ;
if ( ! V_73 ) {
F_39 ( V_72 ) ;
return - V_8 ;
}
if ( strstr ( V_72 -> V_75 , L_31 ) != NULL ) {
const char * V_76 = ( strstr ( V_72 -> V_75 , L_31 ) + 9 ) ;
V_18 = V_76 [ 0 ] - '0' ;
} else {
V_18 = ( ( * V_73 ) >> 8 ) & 0x0f ;
}
V_21 = ( ( * V_73 ) & 0xff ) >> 1 ;
F_14 ( V_27 L_32
L_33 ,
V_18 , V_21 , V_63 , V_58 ) ;
if ( F_40 ( V_72 , L_34 , NULL ) ) {
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ ) {
V_41 [ V_25 ] = F_40 ( V_72 ,
L_34 , NULL ) + V_74 ;
if ( V_41 [ V_25 ] == NULL )
V_41 [ V_25 ] = L_28 ;
F_14 ( V_27 L_35 , V_25 , V_41 [ V_25 ] ) ;
V_74 += strlen ( V_41 [ V_25 ] ) + 1 ;
}
} else {
V_41 [ 0 ] = L_36 ;
V_41 [ 1 ] = L_36 ;
V_41 [ 2 ] = L_36 ;
}
V_77 = F_41 ( V_72 , L_37 , NULL ) ;
F_39 ( V_72 ) ;
if ( V_77 == NULL ) {
F_14 ( V_78 L_38 ) ;
return - V_8 ;
}
#ifndef F_42
F_43 ( L_39 ) ;
#endif
return F_44 ( & V_23 ) ;
}
static void F_35 ( void )
{
int V_79 ;
V_79 = F_45 ( & V_77 -> V_70 , & V_80 ) ;
V_79 |= F_45 ( & V_77 -> V_70 , & V_81 ) ;
V_79 |= F_45 ( & V_77 -> V_70 , & V_82 ) ;
V_79 |= F_45 ( & V_77 -> V_70 , & V_83 ) ;
V_79 |= F_45 ( & V_77 -> V_70 , & V_84 ) ;
V_79 |= F_45 ( & V_77 -> V_70 , & V_85 ) ;
V_79 |= F_45 ( & V_77 -> V_70 , & V_86 ) ;
V_79 |= F_45 ( & V_77 -> V_70 , & V_87 ) ;
V_79 |= F_45 ( & V_77 -> V_70 , & V_88 ) ;
if( V_33 == V_34 )
V_79 |= F_45 ( & V_77 -> V_70 , & V_89 ) ;
if ( V_79 )
F_14 ( V_90
L_40 ) ;
}
static void F_12 ( void )
{
if ( V_77 ) {
F_46 ( & V_77 -> V_70 , & V_80 ) ;
F_46 ( & V_77 -> V_70 , & V_81 ) ;
F_46 ( & V_77 -> V_70 , & V_82 ) ;
F_46 ( & V_77 -> V_70 , & V_83 ) ;
F_46 ( & V_77 -> V_70 , & V_84 ) ;
F_46 ( & V_77 -> V_70 , & V_85 ) ;
F_46 ( & V_77 -> V_70 , & V_86 ) ;
F_46 ( & V_77 -> V_70 , & V_87 ) ;
F_46 ( & V_77 -> V_70 , & V_88 ) ;
if( V_33 == V_34 )
F_46 ( & V_77 -> V_70 ,
& V_89 ) ;
}
}
static void T_5
F_47 ( void )
{
F_48 ( & V_23 ) ;
F_49 ( V_77 ) ;
}
