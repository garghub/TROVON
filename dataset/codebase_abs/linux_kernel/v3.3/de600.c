static inline T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_4 , V_5 ) ;
V_3 = F_3 ( V_6 ) ;
F_2 ( V_7 | V_8 , V_5 ) ;
return V_3 ;
}
static inline T_1 F_4 ( unsigned char type , struct V_1 * V_2 )
{
T_1 V_9 ;
F_2 ( ( type ) , V_5 ) ;
V_9 = ( ( unsigned char ) F_3 ( V_6 ) ) >> 4 ;
F_2 ( ( type ) | V_8 , V_5 ) ;
return ( ( unsigned char ) F_3 ( V_6 ) & ( unsigned char ) 0xf0 ) | V_9 ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
int V_11 = F_6 ( V_12 , V_13 , 0 , V_2 -> V_14 , V_2 ) ;
if ( V_11 ) {
F_7 ( V_15 L_1 , V_2 -> V_14 , V_12 ) ;
return V_11 ;
}
F_8 ( & V_16 , V_10 ) ;
V_11 = F_9 ( V_2 ) ;
F_10 ( & V_16 , V_10 ) ;
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_12 () ;
V_17 = 0 ;
F_13 ( V_18 ) ;
F_13 ( V_19 ) ;
F_13 ( 0 ) ;
F_14 () ;
F_15 ( V_12 , V_2 ) ;
return 0 ;
}
static inline void F_16 ( struct V_1 * V_2 )
{
F_13 ( V_20 ) ;
F_14 () ;
V_21 ;
F_12 () ;
F_13 ( 0 ) ;
}
static int F_17 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
unsigned long V_10 ;
int V_24 ;
int V_25 ;
int V_26 ;
T_1 * V_27 = V_23 -> V_28 ;
int V_29 ;
if ( V_30 <= 0 ) {
V_26 = V_31 - F_18 ( V_2 ) ;
if ( V_26 < V_32 / 20 )
return V_33 ;
F_7 ( V_34 L_2 , V_2 -> V_14 , V_26 , L_3 ) ;
F_8 ( & V_16 , V_10 ) ;
if ( F_9 ( V_2 ) ) {
F_10 ( & V_16 , V_10 ) ;
return V_33 ;
}
F_10 ( & V_16 , V_10 ) ;
}
F_19 ( L_4 , V_23 -> V_25 , V_35 , V_30 ) ;
if ( ( V_25 = V_23 -> V_25 ) < V_36 )
V_25 = V_36 ;
F_8 ( & V_16 , V_10 ) ;
F_12 () ;
V_37 [ V_35 ] = V_24 = F_20 ( V_35 ) - V_25 ;
V_35 = ( V_35 + 1 ) % V_38 ;
if( V_39 )
{
F_21 ( V_40 , V_41 ) ;
F_4 ( V_42 , V_2 ) ;
if ( V_43 || ( F_4 ( V_42 , V_2 ) != 0xde ) ) {
if ( F_9 ( V_2 ) ) {
F_10 ( & V_16 , V_10 ) ;
return V_33 ;
}
}
}
F_21 ( V_24 , V_41 ) ;
for ( V_29 = 0 ; V_29 < V_23 -> V_25 ; ++ V_29 , ++ V_27 )
F_22 ( * V_27 ) ;
for (; V_29 < V_25 ; ++ V_29 )
F_22 ( 0 ) ;
if ( V_30 -- == V_38 ) {
V_2 -> V_44 = V_31 ;
F_23 ( V_2 ) ;
F_21 ( V_24 , V_45 ) ;
F_13 ( V_46 ) ;
}
else {
if ( V_30 )
F_23 ( V_2 ) ;
else
F_24 ( V_2 ) ;
F_14 () ;
}
F_10 ( & V_16 , V_10 ) ;
F_25 ( V_23 ) ;
return V_47 ;
}
static T_2 V_13 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
T_1 V_50 ;
int V_51 = 0 ;
int V_52 = 0 ;
F_26 ( & V_16 ) ;
F_12 () ;
V_50 = F_1 ( V_2 ) ;
do {
F_19 ( L_5 , V_50 ) ;
if ( V_50 & V_53 )
F_27 ( V_2 ) ;
else if ( ! ( V_50 & V_54 ) )
F_13 ( V_55 ) ;
if ( V_30 < V_38 )
V_51 = F_28 ( V_2 , V_50 ) ;
else
V_51 = 0 ;
V_50 = F_1 ( V_2 ) ;
} while ( ( V_50 & V_53 ) || ( ( ++ V_52 < 100 ) && V_51 ) );
F_14 () ;
if ( V_51 )
F_16 ( V_2 ) ;
F_29 ( & V_16 ) ;
return V_56 ;
}
static int F_28 ( struct V_1 * V_2 , int V_50 )
{
if ( V_50 & V_57 )
return 1 ;
if ( ! ( V_50 & V_58 ) ) {
V_59 = ( V_59 + 1 ) % V_38 ;
++ V_30 ;
V_2 -> V_60 . V_61 ++ ;
F_30 ( V_2 ) ;
}
if ( ( V_30 < V_38 ) || ( V_50 & V_58 ) ) {
V_2 -> V_44 = V_31 ;
F_21 ( V_37 [ V_59 ] , V_45 ) ;
F_13 ( V_46 ) ;
return 1 ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
int V_29 ;
int V_62 ;
int V_63 ;
unsigned char * V_27 ;
V_63 = F_4 ( V_64 , V_2 ) ;
V_63 += ( F_4 ( V_64 , V_2 ) << 8 ) ;
V_63 -= 4 ;
V_62 = F_31 () ;
F_32 () ;
F_13 ( V_55 ) ;
if ( ( V_63 < 32 ) || ( V_63 > 1535 ) ) {
F_7 ( V_34 L_6 , V_2 -> V_14 , V_63 ) ;
if ( V_63 > 10000 )
F_9 ( V_2 ) ;
return;
}
V_23 = F_33 ( V_63 + 2 ) ;
if ( V_23 == NULL ) {
F_7 ( L_7 , V_2 -> V_14 , V_63 ) ;
return;
}
F_34 ( V_23 , 2 ) ;
V_27 = F_35 ( V_23 , V_63 ) ;
F_21 ( V_62 , V_41 ) ;
for ( V_29 = V_63 ; V_29 > 0 ; -- V_29 , ++ V_27 )
* V_27 = F_4 ( V_42 , V_2 ) ;
V_23 -> V_65 = F_36 ( V_23 , V_2 ) ;
F_37 ( V_23 ) ;
V_2 -> V_60 . V_66 ++ ;
V_2 -> V_60 . V_67 += V_63 ;
}
static struct V_1 * T_3 F_38 ( void )
{
int V_29 ;
struct V_1 * V_2 ;
int V_68 ;
V_2 = F_39 ( 0 ) ;
if ( ! V_2 )
return F_40 ( - V_69 ) ;
if ( ! F_41 ( V_70 , 3 , L_8 ) ) {
F_7 ( V_34 L_9 , V_70 ) ;
V_68 = - V_71 ;
goto V_72;
}
F_7 ( V_73 L_10 , V_2 -> V_14 ) ;
F_19 ( L_11 , V_74 ) ;
V_68 = - V_75 ;
V_17 = 0 ;
F_12 () ;
( void ) F_1 ( V_2 ) ;
F_13 ( V_18 ) ;
F_13 ( V_19 ) ;
if ( F_1 ( V_2 ) & 0xf0 ) {
F_7 ( L_12 , V_5 ) ;
goto V_76;
}
F_21 ( V_40 , V_41 ) ;
for ( V_29 = 0 ; V_29 < V_77 ; V_29 ++ ) {
V_2 -> V_78 [ V_29 ] = F_4 ( V_42 , V_2 ) ;
V_2 -> V_79 [ V_29 ] = 0xff ;
}
if ( ( V_2 -> V_78 [ 1 ] == 0xde ) && ( V_2 -> V_78 [ 2 ] == 0x15 ) ) {
V_2 -> V_78 [ 0 ] = 0x00 ;
V_2 -> V_78 [ 1 ] = 0x80 ;
V_2 -> V_78 [ 2 ] = 0xc8 ;
V_2 -> V_78 [ 3 ] &= 0x0f ;
V_2 -> V_78 [ 3 ] |= 0x70 ;
} else {
F_7 ( L_13 ) ;
goto V_76;
}
F_7 ( L_14 , V_2 -> V_78 ) ;
V_2 -> V_80 = & V_81 ;
V_2 -> V_10 &= ~ V_82 ;
F_14 () ;
V_68 = F_42 ( V_2 ) ;
if ( V_68 )
goto V_76;
return V_2 ;
V_76:
F_43 ( V_70 , 3 ) ;
V_72:
F_44 ( V_2 ) ;
return F_40 ( V_68 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_29 ;
F_12 () ;
V_17 = 0 ;
F_13 ( V_18 ) ;
F_13 ( V_19 ) ;
F_21 ( V_40 , V_41 ) ;
F_4 ( V_42 , V_2 ) ;
if ( ( F_4 ( V_42 , V_2 ) != 0xde ) ||
( F_4 ( V_42 , V_2 ) != 0x15 ) ) {
F_7 ( L_15 ) ;
V_2 -> V_10 &= ~ V_83 ;
F_11 ( V_2 ) ;
V_43 = 1 ;
F_24 ( V_2 ) ;
return 1 ;
}
if ( V_43 ) {
F_7 ( V_73 L_16 , V_2 -> V_14 ) ;
V_43 = 0 ;
}
V_35 = 0 ;
V_59 = 0 ;
V_30 = V_38 ;
F_21 ( V_40 , V_41 ) ;
for ( V_29 = 0 ; V_29 < V_77 ; V_29 ++ )
F_22 ( V_2 -> V_78 [ V_29 ] ) ;
V_17 = V_84 | V_85 ;
F_21 ( V_86 , V_41 ) ;
F_13 ( V_55 ) ;
F_14 () ;
F_23 ( V_2 ) ;
return 0 ;
}
static int T_3 F_45 ( void )
{
V_87 = F_38 () ;
if ( F_46 ( V_87 ) )
return F_47 ( V_87 ) ;
return 0 ;
}
static void T_4 F_48 ( void )
{
F_49 ( V_87 ) ;
F_43 ( V_70 , 3 ) ;
F_44 ( V_87 ) ;
}
