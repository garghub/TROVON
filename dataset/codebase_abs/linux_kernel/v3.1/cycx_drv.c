static int T_1 F_1 ( void )
{
F_2 ( L_1 ,
V_1 , V_2 , V_3 , V_4 ) ;
return 0 ;
}
static void F_3 ( void )
{
}
int F_4 ( struct V_5 * V_6 , void * V_7 , T_2 V_8 , unsigned long V_9 )
{
int V_10 ;
if ( ! F_5 ( V_11 , V_6 -> V_12 ) ) {
F_6 ( L_2 , V_6 -> V_12 ) ;
return - V_13 ;
}
if ( ! V_9 ) {
F_6 ( L_3 ) ;
return - V_13 ;
} else if ( ! F_5 ( V_14 , V_9 ) ) {
F_6 ( L_4 , V_9 ) ;
return - V_13 ;
}
V_6 -> V_9 = F_7 ( V_9 , V_15 ) ;
V_6 -> V_16 = V_15 ;
if ( ! F_8 ( V_6 -> V_9 ) ) {
F_6 ( L_5 ,
V_9 ) ;
return - V_13 ;
}
F_2 ( L_6 , V_9 ) ;
V_10 = F_9 ( V_6 , V_7 , V_8 ) ;
if ( V_10 )
F_10 ( V_6 ) ;
return V_10 ;
}
int F_10 ( struct V_5 * V_6 )
{
F_11 ( V_6 -> V_9 ) ;
return 0 ;
}
static void F_12 ( struct V_5 * V_6 )
{
F_13 ( 0 , V_6 -> V_9 ) ;
}
void F_14 ( struct V_5 * V_6 )
{
F_15 ( 0 , V_6 -> V_9 + V_17 ) ;
}
int F_16 ( void T_3 * V_18 )
{
T_4 V_19 = 0 ;
while ( F_17 ( V_18 ) ) {
F_18 ( 1000 ) ;
if ( ++ V_19 > 50 )
return - 1 ;
}
return 0 ;
}
int F_19 ( struct V_5 * V_6 , T_2 V_18 , void * V_20 , T_2 V_8 )
{
if ( V_8 == 1 )
* ( V_21 * ) V_20 = F_20 ( V_6 -> V_9 + V_18 ) ;
else
F_21 ( V_20 , V_6 -> V_9 + V_18 , V_8 ) ;
return 0 ;
}
int F_22 ( struct V_5 * V_6 , T_2 V_18 , void * V_20 , T_2 V_8 )
{
if ( V_8 == 1 )
F_13 ( * ( V_21 * ) V_20 , V_6 -> V_9 + V_18 ) ;
else
F_23 ( V_6 -> V_9 + V_18 , V_20 , V_8 ) ;
return 0 ;
}
static int F_24 ( void T_3 * V_18 )
{
int V_22 = 0 ;
for (; V_22 < 3 ; V_22 ++ ) {
F_15 ( V_23 , V_18 + 0x10 ) ;
if ( F_17 ( V_18 + 0x10 ) == V_23 )
if ( F_17 ( V_18 + 0x10 ) == V_23 )
return 1 ;
F_25 ( 1 * 1000 ) ;
}
return 0 ;
}
static void F_26 ( void T_3 * V_18 , V_21 * V_24 , T_2 V_25 )
{
void T_3 * V_26 = V_18 + V_27 ;
T_4 V_19 ;
for ( V_19 = 0 ; V_19 < V_25 ; V_19 ++ ) {
F_13 ( * V_24 ++ , V_26 ++ ) ;
}
}
static int F_27 ( void T_3 * V_18 , V_21 * V_24 , T_2 V_25 )
{
F_23 ( V_18 + V_28 , V_24 , V_25 ) ;
F_15 ( V_29 , V_18 + V_30 ) ;
return F_28 ( V_18 ) ;
}
static void F_29 ( void T_3 * V_18 )
{
F_13 ( 0xea , V_18 + 0x30 ) ;
F_13 ( 0x00 , V_18 + 0x31 ) ;
F_13 ( 0xc4 , V_18 + 0x32 ) ;
F_13 ( 0x00 , V_18 + 0x33 ) ;
F_13 ( 0x00 , V_18 + 0x34 ) ;
F_15 ( V_31 , V_18 + V_30 ) ;
}
static void F_30 ( void T_3 * V_18 , V_21 * V_32 , T_2 V_8 )
{
void T_3 * V_33 = V_18 + V_34 ;
F_13 ( 0xea , V_33 ++ ) ;
F_13 ( 0x00 , V_33 ++ ) ;
F_13 ( 0xfc , V_33 ++ ) ;
F_13 ( 0x00 , V_33 ++ ) ;
F_13 ( 0xf0 , V_33 ) ;
F_26 ( V_18 , V_32 , V_8 ) ;
F_13 ( 0 , V_18 + V_35 ) ;
F_25 ( 1 * 1000 ) ;
}
static int F_31 ( void T_3 * V_18 , V_21 * V_32 , T_2 V_8 )
{
void T_3 * V_36 = V_18 + V_30 ;
T_2 V_19 ;
F_15 ( V_37 , V_36 + sizeof( T_4 ) ) ;
F_15 ( V_38 , V_36 ) ;
if ( F_28 ( V_18 ) < 0 )
return - 1 ;
F_15 ( 0 , V_36 + sizeof( T_4 ) ) ;
F_15 ( 0x4000 , V_36 + 2 * sizeof( T_4 ) ) ;
F_15 ( V_39 , V_36 ) ;
if ( F_28 ( V_18 ) < 0 )
return - 1 ;
for ( V_19 = 0 ; V_19 < V_8 ; V_19 += V_37 )
if ( F_27 ( V_18 , V_32 + V_19 ,
F_32 ( T_2 , V_37 , ( V_8 - V_19 ) ) ) < 0 ) {
F_6 ( L_7 ) ;
return - 1 ;
}
return 0 ;
}
static int F_33 ( void T_3 * V_18 , V_21 * V_32 , T_2 V_8 )
{
void T_3 * V_36 = V_18 + V_30 ;
T_2 V_19 ;
F_15 ( V_37 , V_36 + sizeof( T_4 ) ) ;
F_15 ( V_38 , V_36 ) ;
if ( F_28 ( V_18 ) < 0 )
return - 1 ;
F_15 ( 0x0000 , V_36 + sizeof( T_4 ) ) ;
F_15 ( 0xc400 , V_36 + 2 * sizeof( T_4 ) ) ;
F_15 ( V_39 , V_36 ) ;
if ( F_28 ( V_18 ) < 0 )
return - 1 ;
for ( V_19 = 0 ; V_19 < V_8 ; V_19 += V_37 )
if ( F_27 ( V_18 , V_32 + V_19 ,
F_32 ( T_2 , V_37 , ( V_8 - V_19 ) ) ) ) {
F_6 ( L_7 ) ;
return - 1 ;
}
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , struct V_40 * V_7 , T_2 V_8 )
{
int V_19 , V_41 ;
struct V_42 * V_43 ;
V_21 * V_44 ,
* V_45 ,
* V_46 ;
void T_3 * V_47 = V_6 -> V_9 + 0x400 ;
T_4 V_48 ;
F_2 ( L_8 , V_7 -> V_49 ) ;
if ( strcmp ( V_7 -> V_49 , V_50 ) ) {
F_6 ( L_9 ) ;
return - V_13 ;
}
F_2 ( L_10 , V_7 -> V_51 ) ;
if ( V_7 -> V_51 != V_52 ) {
F_6 ( L_11 ,
V_53 , V_7 -> V_51 , V_52 ) ;
return - V_13 ;
}
V_48 = F_34 ( ( V_21 * ) & V_7 -> V_54 , sizeof( struct V_55 ) +
V_7 -> V_54 . V_56 ) ;
if ( V_48 != V_7 -> F_34 ) {
F_6 ( L_12 , V_53 ) ;
F_6 ( L_13 ,
V_8 - ( int ) sizeof( struct V_40 ) - 1 ,
V_7 -> V_54 . V_56 ) ;
F_6 ( L_14 ,
V_48 , V_7 -> F_34 ) ;
return - V_13 ;
}
V_43 = (struct V_42 * ) & V_7 -> V_57 ;
#ifdef F_35
F_2 ( L_15 , V_53 ) ;
F_2 ( L_16 , V_43 -> V_58 ) ;
F_2 ( L_17 , V_43 -> V_59 ) ;
F_2 ( L_18 , V_43 -> V_60 ) ;
#endif
V_44 = ( ( V_21 * ) V_43 ) + sizeof( struct V_42 ) ;
V_45 = V_44 + V_43 -> V_58 ;
V_46 = V_45 + V_43 -> V_59 ;
F_2 ( L_19 ,
V_7 -> V_61 [ 0 ] ? V_7 -> V_61 : L_20 ,
V_7 -> V_54 . V_62 ) ;
for ( V_19 = 0 ; V_19 < 5 ; V_19 ++ ) {
if ( ! F_36 ( V_6 -> V_9 ) ) {
F_6 ( L_21 ) ;
return - V_13 ;
}
F_30 ( V_6 -> V_9 , V_44 , V_43 -> V_58 ) ;
F_15 ( V_63 , V_47 ) ;
F_25 ( 1 * 1000 ) ;
for ( V_41 = 0 ; V_41 < 3 ; V_41 ++ )
if ( ! F_17 ( V_47 ) )
goto V_64;
else
F_25 ( 1 * 1000 ) ;
}
F_6 ( L_22 ) ;
return - V_13 ;
V_64:
if ( F_31 ( V_6 -> V_9 , V_45 , V_43 -> V_59 ) ) {
F_6 ( L_23 ) ;
return - V_13 ;
}
if ( F_33 ( V_6 -> V_9 , V_46 , V_43 -> V_60 ) ) {
F_6 ( L_24 ) ;
return - V_13 ;
}
F_37 ( V_6 ) ;
F_29 ( V_6 -> V_9 ) ;
F_25 ( 7 * 1000 ) ;
F_2 ( L_25 ) ;
F_12 ( V_6 ) ;
return 0 ;
}
static void F_37 ( struct V_5 * V_6 )
{
F_13 ( V_65 , V_6 -> V_9 + V_66 ) ;
}
static int F_8 ( void T_3 * V_18 )
{
F_36 ( V_18 ) ;
return F_24 ( V_18 ) ;
}
static int F_5 ( const long * V_67 , long V_68 )
{
int V_19 = 1 ;
for (; V_19 <= V_67 [ 0 ] ; ++ V_19 )
if ( V_67 [ V_19 ] == V_68 )
return V_19 ;
return 0 ;
}
static int F_36 ( void T_3 * V_18 )
{
F_13 ( 0 , V_18 + V_69 ) ;
F_25 ( 2 * 1000 ) ;
F_13 ( 0 , V_18 + V_70 ) ;
F_25 ( 2 * 1000 ) ;
return F_24 ( V_18 ) ;
}
static T_4 F_34 ( V_21 * V_20 , T_2 V_8 )
{
T_4 V_71 = 0 ;
T_4 V_72 , V_73 ;
for (; V_8 ; -- V_8 , ++ V_20 )
for ( V_72 = 0x80 ; V_72 ; V_72 >>= 1 ) {
V_73 = ( V_71 & 0x8000 ) ;
V_71 <<= 1 ;
V_71 |= ( ( * V_20 & V_72 ) ? 1 : 0 ) ;
if ( V_73 )
V_71 ^= 0x1021 ;
}
return V_71 ;
}
