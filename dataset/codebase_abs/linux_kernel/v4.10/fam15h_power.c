static bool F_1 ( void )
{
return V_1 . V_2 == 0x15 && V_1 . V_3 >= 0x60 ;
}
static T_1 F_2 ( struct V_4 * V_5 ,
struct V_6 * V_7 , char * V_8 )
{
T_2 V_9 , V_10 , V_11 ;
T_3 V_12 ;
T_4 V_13 ;
struct V_14 * V_15 = F_3 ( V_5 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
F_4 ( V_17 -> V_19 , F_5 ( F_6 ( V_17 -> V_20 ) , 5 ) ,
V_21 , & V_9 ) ;
if ( F_1 () ) {
V_12 = V_9 >> 4 ;
V_12 = F_7 ( V_12 , 27 ) ;
} else {
V_12 = ( V_9 >> 4 ) & 0x3fffff ;
V_12 = F_7 ( V_12 , 21 ) ;
}
V_11 = ( V_9 & 0xf ) + 1 ;
F_4 ( V_17 -> V_19 , F_5 ( F_6 ( V_17 -> V_20 ) , 5 ) ,
V_22 , & V_9 ) ;
if ( F_1 () )
V_10 = V_9 >> 16 ;
else
V_10 = ( V_9 >> 16 ) & 0x1fff ;
V_13 = ( ( T_4 ) ( V_10 +
V_15 -> V_23 ) ) << V_11 ;
V_13 -= V_12 ;
V_13 *= V_15 -> V_24 ;
V_13 = ( V_13 * 15625 ) >> ( 10 + V_11 ) ;
return sprintf ( V_8 , L_1 , ( unsigned int ) V_13 ) ;
}
static T_1 F_8 ( struct V_4 * V_5 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_14 * V_15 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_1 , V_15 -> V_25 ) ;
}
static void F_9 ( void * V_26 )
{
struct V_14 * V_15 = V_26 ;
int V_27 , V_28 ;
V_27 = F_10 () ;
V_28 = F_11 ( V_27 ) . V_29 ;
F_12 ( V_30 , & V_15 -> V_31 [ V_28 ] ) ;
F_12 ( V_32 , & V_15 -> V_33 [ V_28 ] ) ;
V_15 -> V_34 [ V_28 ] = 1 ;
}
static int F_13 ( struct V_14 * V_15 )
{
int V_35 , V_36 ;
T_5 V_37 ;
int V_38 , V_27 ;
V_38 = F_14 ( & V_37 , V_39 ) ;
if ( ! V_38 )
return - V_40 ;
memset ( V_15 -> V_34 , 0 , sizeof( int ) * V_41 ) ;
F_15 () ;
V_35 = - 1 ;
F_16 (cpu) {
V_36 = F_17 ( V_27 ) ;
if ( V_36 == V_35 )
continue;
V_35 = V_36 ;
F_18 ( F_19 ( F_20 ( V_27 ) ) , V_37 ) ;
}
F_21 ( V_37 , F_9 , V_15 , true ) ;
F_22 () ;
F_23 ( V_37 ) ;
return 0 ;
}
static T_1 F_24 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_14 * V_15 = F_3 ( V_5 ) ;
T_4 V_42 [ V_41 ] , V_43 [ V_41 ] ,
V_44 [ V_41 ] ;
T_4 V_45 , V_46 ;
int V_28 , V_47 , V_38 ;
signed long V_48 ;
V_47 = V_1 . V_49 ;
V_38 = F_13 ( V_15 ) ;
if ( V_38 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_47 ; V_28 ++ ) {
V_42 [ V_28 ] = V_15 -> V_31 [ V_28 ] ;
V_43 [ V_28 ] = V_15 -> V_33 [ V_28 ] ;
}
V_48 = F_25 ( F_26 ( V_15 -> V_50 ) ) ;
if ( V_48 )
return 0 ;
V_38 = F_13 ( V_15 ) ;
if ( V_38 )
return 0 ;
for ( V_28 = 0 , V_46 = 0 ; V_28 < V_47 ; V_28 ++ ) {
if ( V_15 -> V_34 [ V_28 ] == 0 )
continue;
if ( V_15 -> V_31 [ V_28 ] < V_42 [ V_28 ] ) {
V_44 [ V_28 ] = V_15 -> V_51 + V_15 -> V_31 [ V_28 ] ;
V_44 [ V_28 ] -= V_42 [ V_28 ] ;
} else {
V_44 [ V_28 ] = V_15 -> V_31 [ V_28 ] - V_42 [ V_28 ] ;
}
V_45 = V_15 -> V_33 [ V_28 ] - V_43 [ V_28 ] ;
V_44 [ V_28 ] *= V_15 -> V_52 * 1000 ;
F_27 ( V_44 [ V_28 ] , V_45 ) ;
V_46 += V_44 [ V_28 ] ;
}
return sprintf ( V_8 , L_2 , ( unsigned long long ) V_46 ) ;
}
static T_1 F_28 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_14 * V_15 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_3 , V_15 -> V_50 ) ;
}
static T_1 F_29 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
const char * V_8 , T_6 V_53 )
{
struct V_14 * V_15 = F_3 ( V_5 ) ;
unsigned long V_54 ;
int V_38 ;
V_38 = F_30 ( V_8 , 10 , & V_54 ) ;
if ( V_38 )
return V_38 ;
if ( V_54 > V_55 )
return - V_56 ;
if ( V_54 <= 0 )
return - V_56 ;
V_15 -> V_50 = V_54 ;
return V_53 ;
}
static int F_31 ( struct V_16 * V_18 ,
struct V_14 * V_15 )
{
int V_57 = V_58 ;
struct V_59 * * V_60 ;
struct V_61 * V_62 = & V_1 ;
if ( V_62 -> V_2 == 0x15 &&
( V_62 -> V_3 <= 0xf ||
( V_62 -> V_3 >= 0x60 && V_62 -> V_3 <= 0x7f ) ) )
V_57 += 1 ;
if ( F_32 ( V_63 ) )
V_57 += 2 ;
V_60 = F_33 ( & V_18 -> V_5 , V_57 ,
sizeof( * V_60 ) ,
V_39 ) ;
if ( ! V_60 )
return - V_40 ;
V_57 = 0 ;
V_60 [ V_57 ++ ] = & V_64 . V_7 ;
if ( V_62 -> V_2 == 0x15 &&
( V_62 -> V_3 <= 0xf ||
( V_62 -> V_3 >= 0x60 && V_62 -> V_3 <= 0x7f ) ) )
V_60 [ V_57 ++ ] = & V_65 . V_7 ;
if ( F_32 ( V_63 ) ) {
V_60 [ V_57 ++ ] = & V_66 . V_7 ;
V_60 [ V_57 ++ ] = & V_67 . V_7 ;
}
V_15 -> V_68 . V_69 = V_60 ;
return 0 ;
}
static bool F_34 ( struct V_16 * V_17 )
{
T_2 V_9 ;
F_4 ( V_17 -> V_19 , F_5 ( F_6 ( V_17 -> V_20 ) , 3 ) ,
V_70 , & V_9 ) ;
if ( ( V_9 & F_35 ( 29 ) ) && ( ( V_9 >> 30 ) & 3 ) )
return false ;
return true ;
}
static void F_36 ( struct V_16 * V_18 )
{
T_2 V_9 ;
if ( ! F_37 ( V_71 , V_18 ) )
return;
F_4 ( V_18 -> V_19 ,
F_5 ( F_6 ( V_18 -> V_20 ) , 5 ) ,
V_21 , & V_9 ) ;
if ( ( V_9 & 0xf ) != 0xe )
return;
V_9 &= ~ 0xf ;
V_9 |= 0x9 ;
F_38 ( V_18 -> V_19 ,
F_5 ( F_6 ( V_18 -> V_20 ) , 5 ) ,
V_21 , V_9 ) ;
}
static int F_39 ( struct V_16 * V_18 )
{
F_36 ( V_18 ) ;
return 0 ;
}
static int F_40 ( struct V_16 * V_17 ,
struct V_14 * V_15 )
{
T_2 V_9 ;
T_4 V_72 ;
int V_38 ;
F_41 ( V_17 , V_73 , & V_9 ) ;
V_15 -> V_23 = V_9 >> 16 ;
V_72 = V_9 & 0xffff ;
F_4 ( V_17 -> V_19 , F_5 ( F_6 ( V_17 -> V_20 ) , 5 ) ,
V_22 , & V_9 ) ;
V_15 -> V_24 = ( ( V_9 & 0x3ff ) << 6 ) | ( ( V_9 >> 10 ) & 0x3f ) ;
V_72 *= V_15 -> V_24 ;
if ( ( V_72 >> 16 ) >= 256 )
F_42 ( & V_17 -> V_5 ,
L_4 ,
( unsigned int ) ( V_72 >> 16 ) ) ;
V_15 -> V_25 = ( V_72 * 15625 ) >> 10 ;
V_38 = F_31 ( V_17 , V_15 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_32 ( V_63 ) )
return 0 ;
V_15 -> V_52 = F_43 ( 0x80000007 ) ;
if ( F_12 ( V_74 , & V_72 ) ) {
F_44 ( L_5 ) ;
return - V_75 ;
}
V_15 -> V_51 = V_72 ;
V_15 -> V_50 = 10 ;
return F_13 ( V_15 ) ;
}
static int F_45 ( struct V_16 * V_18 ,
const struct V_76 * V_77 )
{
struct V_14 * V_15 ;
struct V_4 * V_5 = & V_18 -> V_5 ;
struct V_4 * V_78 ;
int V_38 ;
F_36 ( V_18 ) ;
if ( ! F_34 ( V_18 ) )
return - V_75 ;
V_15 = F_46 ( V_5 , sizeof( struct V_14 ) , V_39 ) ;
if ( ! V_15 )
return - V_40 ;
V_38 = F_40 ( V_18 , V_15 ) ;
if ( V_38 )
return V_38 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_79 [ 0 ] = & V_15 -> V_68 ;
V_78 = F_47 ( V_5 , L_6 ,
V_15 ,
& V_15 -> V_79 [ 0 ] ) ;
return F_48 ( V_78 ) ;
}
