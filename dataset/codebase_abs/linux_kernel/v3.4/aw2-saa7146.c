int F_1 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_3 ) ;
F_2 ( ( V_4 << 16 ) , V_5 ) ;
V_2 -> V_6 = NULL ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 ,
void T_1 * V_7 )
{
unsigned int V_8 ;
unsigned int V_9 = 0 ;
int V_10 ;
V_2 -> V_6 = V_7 ;
F_2 ( 0 , V_3 ) ;
F_2 ( ( V_4 << 16 ) , V_5 ) ;
#ifdef F_4
V_9 |= V_11 ;
V_9 |= V_12 ;
#endif
V_9 |= 0 * V_13 ;
V_9 |= 0 * V_14 ;
V_9 |= 3 * V_15 ;
V_9 |= 2 * V_16 ;
V_9 |= 3 * V_17 ;
F_2 ( V_9 , V_18 ) ;
F_2 ( 3 * ( V_19 ) + 3 * ( V_20 ) +
3 * ( V_21 ) + 3 * ( V_22 ) +
3 * ( V_23 ) + 3 * ( V_24 ) , V_25 ) ;
F_2 ( ( V_26 << 16 ) | V_26 , V_5 ) ;
F_2 ( ( V_27 << 16 ) | V_27 , V_5 ) ;
F_2 ( V_28 | V_29 | V_30 | V_31 | V_32 , V_3 ) ;
V_8 = V_33 | V_34 ;
F_2 ( V_8 , V_35 ) ;
F_5 ( V_2 , 0 ) ;
for ( V_10 = 0 ; V_10 < 8 ; ++ V_10 ) {
F_2 ( V_36 [ V_10 ] , V_37 + ( V_10 * 4 ) ) ;
F_2 ( V_38 [ V_10 ] , V_39 + ( V_10 * 4 ) ) ;
}
}
void F_6 ( struct V_1 * V_2 ,
int V_40 ,
unsigned long V_41 ,
unsigned long V_42 ,
unsigned long V_43 )
{
unsigned long V_44 , V_45 ;
V_44 = ( 0L << 11 ) ;
V_45 = F_7 ( V_42 ) ;
V_44 |= ( V_45 << 4 ) ;
if ( V_40 == 0 ) {
F_2 ( V_44 , V_46 ) ;
F_2 ( V_41 , V_47 ) ;
F_2 ( V_41 + V_43 , V_48 ) ;
} else if ( V_40 == 1 ) {
F_2 ( V_44 , V_49 ) ;
F_2 ( V_41 , V_50 ) ;
F_2 ( V_41 + V_43 , V_51 ) ;
} else {
F_8 ( V_52
L_1
L_2 ) ;
}
}
void F_9 ( struct V_1 * V_2 ,
int V_40 , unsigned long V_41 ,
unsigned long V_42 ,
unsigned long V_43 )
{
unsigned long V_44 , V_45 ;
V_44 = ( 0L << 11 ) ;
V_45 = F_7 ( V_42 ) ;
V_44 |= ( V_45 << 4 ) ;
if ( V_40 == 0 ) {
F_2 ( V_44 , V_53 ) ;
F_2 ( V_41 , V_54 ) ;
F_2 ( V_41 + V_43 , V_55 ) ;
} else {
F_8 ( V_52
L_3
L_4 ) ;
}
}
void F_10 ( unsigned int V_40 ,
T_2
V_56 ,
void * V_57 )
{
if ( V_40 < V_58 ) {
V_59 [ V_40 ] . V_56 =
( T_2 ) V_56 ;
V_59 [ V_40 ] . V_57 =
( void * ) V_57 ;
}
}
void F_11 ( unsigned int V_40 ,
T_2
V_56 ,
void * V_57 )
{
if ( V_40 < V_60 ) {
V_61 [ V_40 ] . V_56 =
( T_2 ) V_56 ;
V_61 [ V_40 ] . V_57 =
( void * ) V_57 ;
}
}
void F_12 ( struct V_1 * V_2 ,
int V_40 )
{
unsigned int V_9 = 0 ;
V_9 = F_13 ( V_18 ) ;
if ( V_40 == 0 ) {
F_2 ( ( V_62 << 16 ) | V_62 , V_5 ) ;
V_9 |= 2 * V_14 ;
F_2 ( V_9 , V_18 ) ;
} else if ( V_40 == 1 ) {
F_2 ( ( V_63 << 16 ) | V_63 , V_5 ) ;
V_9 |= 1 * V_13 ;
F_2 ( V_9 , V_18 ) ;
}
}
void F_14 ( struct V_1 * V_2 ,
int V_40 )
{
unsigned int V_9 = 0 ;
V_9 = F_13 ( V_18 ) ;
if ( V_40 == 0 ) {
V_9 &= ~ ( 3 * V_14 ) ;
F_2 ( V_9 , V_18 ) ;
F_2 ( ( V_62 << 16 ) , V_5 ) ;
} else if ( V_40 == 1 ) {
V_9 &= ~ ( 3 * V_13 ) ;
F_2 ( V_9 , V_18 ) ;
F_2 ( ( V_63 << 16 ) , V_5 ) ;
}
}
void F_15 ( struct V_1 * V_2 ,
int V_40 )
{
if ( V_40 == 0 )
F_2 ( ( V_64 << 16 ) | V_64 , V_5 ) ;
}
void F_16 ( struct V_1 * V_2 ,
int V_40 )
{
if ( V_40 == 0 )
F_2 ( ( V_64 << 16 ) , V_5 ) ;
}
T_3 F_17 ( int V_65 , void * V_66 )
{
unsigned int V_67 ;
unsigned int V_68 ;
struct V_1 * V_2 = V_66 ;
V_67 = F_13 ( V_69 ) ;
if ( ! V_67 )
return V_70 ;
F_2 ( V_67 , V_69 ) ;
if ( V_67 & ( V_31 | V_32 ) ) {
V_68 = F_13 ( V_71 ) ;
F_2 ( 0x100 , V_71 ) ;
}
if ( V_67 & V_28 ) {
if ( V_59 [ 1 ] . V_56 != NULL ) {
V_59 [ 1 ] .
V_56 ( V_59 [ 1 ] .
V_57 ) ;
}
}
if ( V_67 & V_29 ) {
if ( V_59 [ 0 ] . V_56 != NULL ) {
V_59 [ 0 ] .
V_56 ( V_59 [ 0 ] .
V_57 ) ;
}
}
if ( V_67 & V_30 ) {
if ( V_61 [ 0 ] . V_56 != NULL ) {
V_61 [ 0 ] .
V_56 ( V_61 [ 0 ] .
V_57 ) ;
}
}
return V_72 ;
}
unsigned int F_18 ( struct V_1 * V_2 ,
int V_40 ,
unsigned char * V_73 ,
unsigned int V_43 )
{
long V_74 = 0 ;
T_4 V_75 = 0 ;
if ( V_40 == 0 ) {
V_74 = F_13 ( V_76 ) ;
V_75 = V_74 - ( long ) V_73 ;
if ( V_75 == V_43 )
V_75 = 0 ;
}
if ( V_40 == 1 ) {
V_74 = F_13 ( V_77 ) ;
V_75 = V_74 - ( T_4 ) V_73 ;
if ( V_75 == V_43 )
V_75 = 0 ;
}
return V_75 ;
}
unsigned int F_19 ( struct V_1 * V_2 ,
int V_40 ,
unsigned char * V_73 ,
unsigned int V_43 )
{
T_4 V_74 = 0 ;
T_4 V_75 = 0 ;
if ( V_40 == 0 ) {
V_74 = F_13 ( V_78 ) ;
V_75 = V_74 - ( T_4 ) V_73 ;
if ( V_75 == V_43 )
V_75 = 0 ;
}
return V_75 ;
}
void F_5 ( struct V_1 * V_2 ,
int V_79 )
{
if ( V_79 )
F_2 ( 0x40 , V_80 ) ;
else
F_2 ( 0x50 , V_80 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
unsigned int V_81 = F_13 ( V_80 ) ;
if ( ( V_81 & 0xFF ) == 0x40 )
return 1 ;
else
return 0 ;
}
static int F_7 ( int V_82 )
{
int V_83 = 32 ;
int V_84 = 0 ;
while ( V_83 < V_82 ) {
V_83 *= 2 ;
V_84 ++ ;
}
return V_84 ;
}
