static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
unsigned long V_8 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_4 ( V_2 , V_10 , V_3 , V_4 ) ;
F_5 ( V_4 , V_2 -> V_11 + V_3 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static inline T_1 F_7 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
unsigned long V_8 ;
T_1 V_4 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_4 = F_8 ( V_2 -> V_11 + V_3 ) ;
F_4 ( V_2 , V_12 , V_3 , V_4 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
return V_4 ;
}
static inline void F_9 ( struct V_1 * V_2 , int V_3 , T_3 V_4 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
unsigned long V_8 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_4 ( V_2 , V_13 , V_3 , V_4 ) ;
F_10 ( V_4 , V_2 -> V_11 + V_3 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static inline T_3 F_11 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
unsigned long V_8 ;
T_3 V_4 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_4 = F_12 ( V_2 -> V_11 + V_3 ) ;
F_4 ( V_2 , V_14 , V_3 , V_4 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
return V_4 ;
}
static inline void F_13 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_15 , int V_16 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
unsigned long V_8 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_4 ( V_2 , V_17 , V_3 , V_16 ) ;
F_14 ( V_2 -> V_11 + V_3 , V_15 , V_16 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static inline void F_15 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_15 , int V_16 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
unsigned long V_8 ;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_4 ( V_2 , V_18 , V_3 , V_16 ) ;
F_16 ( V_2 -> V_11 + V_3 , V_15 , V_16 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_3 V_19 , void * V_15 ,
int V_20 )
{
T_3 V_21 ;
T_3 * V_22 ;
V_21 = ( V_19 == 1 ) ? V_23 : V_24 ;
V_22 = ( T_3 * ) V_15 ;
if ( V_20 / 2 )
F_18 ( V_21 , V_15 , V_20 / 2 ) ;
V_22 += V_20 / 2 ;
if ( V_20 & 1 )
* ( ( char * ) V_22 ) = F_19 ( V_21 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_3 V_19 , void * V_15 , int V_20 )
{
T_3 V_21 ;
T_3 * V_22 ;
V_21 = ( V_19 == 1 ) ? V_23 : V_24 ;
V_22 = ( T_3 * ) V_15 ;
if ( V_20 / 2 )
F_21 ( V_21 , V_15 , V_20 / 2 ) ;
V_22 += V_20 / 2 ;
if ( V_20 & 1 )
F_22 ( * ( ( char * ) V_22 ) , V_21 ) ;
return 0 ;
}
static void F_23 ( T_2 * V_7 )
{
unsigned char V_25 ;
struct V_26 * V_27 = V_7 -> V_27 ;
F_24 ( V_28 L_1 ,
V_29 ) ;
if ( V_27 -> V_30 == NULL ) {
V_25 = F_8 ( V_27 -> V_31 ) ;
F_5 ( V_25 | V_32 , V_27 -> V_31 ) ;
F_25 ( 2 ) ;
F_5 ( V_25 & ~ V_32 , V_27 -> V_31 ) ;
F_25 ( 2 ) ;
} else {
V_25 = F_26 ( V_27 -> V_30 + V_27 -> V_31 ) ;
F_27 ( V_25 | V_32 ,
V_27 -> V_30 + V_27 -> V_31 ) ;
F_25 ( 2 ) ;
F_27 ( V_25 & ~ V_32 ,
V_27 -> V_30 + V_27 -> V_31 ) ;
F_25 ( 2 ) ;
}
}
static void F_28 ( T_2 * V_7 , int V_33 )
{
unsigned char V_25 ;
struct V_26 * V_27 = V_7 -> V_27 ;
if ( V_27 -> V_30 == NULL ) {
V_25 = F_8 ( V_27 -> V_31 ) ;
F_5 ( V_25 | V_32 , V_27 -> V_31 ) ;
F_25 ( 10 ) ;
F_5 ( V_33 , V_27 -> V_31 + 2 ) ;
F_25 ( 10 ) ;
F_5 ( V_25 & ~ V_32 , V_27 -> V_31 ) ;
F_25 ( 10 ) ;
} else {
V_25 = F_26 ( V_27 -> V_30 + V_27 -> V_31 ) ;
F_27 ( V_25 | V_32 ,
V_27 -> V_30 + V_27 -> V_31 ) ;
F_25 ( 10 ) ;
F_27 ( V_33 , V_27 -> V_30 + V_27 -> V_31 + 2 ) ;
F_25 ( 10 ) ;
F_27 ( V_25 & ~ V_32 ,
V_27 -> V_30 + V_27 -> V_31 ) ;
F_25 ( 10 ) ;
}
}
static int F_29 ( void T_4 * V_30 , int V_34 ,
unsigned int * V_31 ,
unsigned int * V_35 )
{
#define F_30 0x1A
#define F_31 0x20
#define F_32 0xFF
#define F_33 256
T_1 * V_36 ;
int V_37 , V_22 ;
unsigned int V_38 , V_39 , V_40 , V_41 ;
struct V_42 * V_43 ;
V_36 = F_34 ( F_33 , V_44 ) ;
if ( V_36 == NULL )
return - V_45 ;
for ( V_37 = 0 ; V_37 < F_33 ; V_37 ++ )
V_36 [ V_37 ] = F_26 ( V_30 + 2 * V_37 ) ;
F_24 ( V_28 L_2 ,
V_29 , V_36 [ 0 ] , V_36 [ 1 ] , V_36 [ 2 ] , V_36 [ 3 ] , V_36 [ 4 ] , V_36 [ 5 ] ) ;
* V_31 = 0x3e0 ;
* V_35 = 0x01 ;
V_40 = V_41 = 0 ;
V_22 = 0 ;
while ( V_22 < F_33 - 1 && V_36 [ V_22 ] != F_32 ) {
if ( V_22 + 2 + V_36 [ V_22 + 1 ] > F_33 )
goto V_46;
switch ( V_36 [ V_22 ] ) {
case F_30 :
if ( V_36 [ V_22 + 1 ] < 2 )
goto V_46;
V_38 = ( V_36 [ V_22 + 2 ] & 0x3c ) >> 2 ;
V_39 = V_36 [ V_22 + 2 ] & 0x03 ;
if ( 4 + V_39 + V_38 > V_36 [ V_22 + 1 ] )
goto V_46;
* V_35 = V_36 [ V_22 + 3 ] & 0x3F ;
* V_31 = 0 ;
for ( V_37 = 0 ; V_37 <= V_39 ; V_37 ++ )
* V_31 += V_36 [ V_22 + 4 + V_37 ] << ( 8 * V_37 ) ;
F_24 ( V_28 L_3
L_4 , V_29 ,
* V_35 , * V_31 ) ;
if ( * V_31 > V_34 ) {
F_24 ( V_47 L_5
L_6 , V_29 ) ;
F_35 ( V_36 ) ;
return - 1 ;
}
break;
case F_31 :
if ( V_36 [ V_22 + 1 ] < 4 )
goto V_46;
V_40 = V_36 [ V_22 + 2 ] + ( V_36 [ V_22 + 3 ] << 8 ) ;
V_41 = V_36 [ V_22 + 4 ] + ( V_36 [ V_22 + 5 ] << 8 ) ;
F_24 ( V_28 L_7 ,
V_29 , V_40 , V_41 ) ;
break;
}
V_22 += V_36 [ V_22 + 1 ] + 2 ;
}
if ( V_22 >= F_33 || V_36 [ V_22 ] != F_32 )
goto V_46;
for ( V_43 = V_48 ; V_43 -> V_40 != 0 ; V_43 ++ )
if ( V_40 == V_43 -> V_40 && V_41 == V_43 -> V_41 ) {
F_35 ( V_36 ) ;
return 0 ;
}
F_24 ( V_49 L_8
L_9 , V_29 , V_40 , V_41 ) ;
goto V_50;
V_46:
F_24 ( V_51 L_10 , V_29 ) ;
V_50:
F_35 ( V_36 ) ;
if ( V_52 ) {
F_24 ( V_49 L_11
L_12 , V_29 ) ;
return 0 ;
}
return - 1 ;
}
static int F_36 ( struct V_53 * V_54 ,
const struct V_55 * V_56 )
{
unsigned int V_57 , V_58 ;
unsigned long V_59 ;
unsigned int V_60 ;
void T_4 * V_30 = NULL ;
unsigned int V_31 = 0 , V_35 = 0 ;
T_5 V_61 ;
T_2 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_5 * V_6 ;
static int V_62 ;
int V_63 = 0 ;
int V_64 ;
struct V_26 * V_27 ;
V_27 = F_37 ( sizeof( * V_27 ) , V_44 ) ;
if ( V_27 == NULL )
return - V_45 ;
if ( F_38 ( V_54 ) )
goto V_65;
V_64 = ( V_54 -> V_66 == 0x15e8 ) && ( V_54 -> V_67 == 0x0131 ) ;
V_58 = F_39 ( V_54 , 1 ) ;
V_57 = F_39 ( V_54 , V_64 ? 2 : 3 ) ;
if ( V_64 ) {
V_30 = NULL ;
F_24 ( V_49 L_13
L_14 ,
V_58 , V_54 -> V_68 , V_57 ) ;
V_31 = V_58 ;
V_35 = 0x04 ;
F_5 ( V_35 | V_69 | V_70 , V_58 ) ;
F_25 ( 1 ) ;
V_61 = F_8 ( V_58 ) ;
if ( V_61 != ( V_35 | V_69 | V_70 ) ) {
F_24 ( V_47 L_15
L_16 , V_29 ,
V_35 | V_69 | V_70 , V_61 ) ;
goto V_50;
}
} else {
V_59 = F_39 ( V_54 , 2 ) ;
V_60 = F_40 ( V_54 , 2 ) ;
if ( V_60 < V_71 )
goto V_50;
V_30 = F_41 ( V_59 , V_60 ) ;
if ( V_30 == NULL ) {
F_24 ( V_47 L_17 ,
V_29 ) ;
goto V_50;
}
F_24 ( V_49 L_18
L_19 ,
V_59 , V_58 , V_54 -> V_68 , V_57 ) ;
if ( F_29 ( V_30 , V_60 ,
& V_31 , & V_35 ) ) {
F_24 ( V_49 L_20
L_21 ) ;
goto V_50;
}
F_24 ( V_28 L_22
L_23 ) ;
F_27 ( V_35 | V_69 | V_70 ,
V_30 + V_31 ) ;
V_61 = F_42 ( V_58 + V_72 ) ;
F_24 ( V_28 L_24 , V_61 ) ;
if ( ! ( V_61 & V_73 ) ) {
F_43 ( V_61 | V_73 ,
V_58 + V_72 ) ;
if ( ! ( F_42 ( V_58 + V_72 ) &
V_73 ) ) {
F_24 ( V_51 L_25
L_26 , V_29 ) ;
goto V_50;
}
}
V_61 = F_42 ( V_58 + V_74 ) ;
F_24 ( V_28 L_27
L_28 ,
V_61 , ( V_61 & V_75 ) != 0 ) ;
}
V_2 = F_44 ( & V_76 , V_62 ,
& V_54 -> V_2 ) ;
if ( V_2 == NULL )
goto V_50;
V_6 = F_2 ( V_2 ) ;
V_7 = V_6 -> V_7 ;
V_7 -> V_27 = V_27 ;
V_62 ++ ;
V_2 -> V_68 = V_54 -> V_68 ;
V_2 -> V_11 = V_57 ;
V_27 -> V_30 = V_30 ;
V_27 -> V_31 = V_31 ;
F_45 ( V_54 , V_2 ) ;
if ( F_46 ( V_2 -> V_68 , V_77 , V_78 , V_2 -> V_79 ,
V_2 ) ) {
F_24 ( V_51 L_29 , V_2 -> V_79 ) ;
goto V_50;
} else
V_63 = 1 ;
if ( F_47 ( V_2 , 1 ) ) {
F_24 ( V_28 L_30 ,
V_29 ) ;
goto V_50;
}
return F_48 ( V_2 ) ;
V_50:
if ( V_63 && V_2 )
F_49 ( V_2 -> V_68 , V_2 ) ;
if ( V_30 )
F_50 ( V_30 ) ;
F_51 ( V_54 ) ;
F_52 ( V_2 ) ;
V_65:
F_35 ( V_27 ) ;
return - V_80 ;
}
static void F_53 ( struct V_53 * V_54 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_26 * V_27 ;
V_2 = F_54 ( V_54 ) ;
V_6 = F_2 ( V_2 ) ;
V_27 = V_6 -> V_7 -> V_27 ;
F_23 ( V_6 -> V_7 ) ;
F_55 ( V_2 ) ;
if ( V_27 -> V_30 )
F_50 ( V_27 -> V_30 ) ;
if ( V_2 -> V_68 )
F_49 ( V_2 -> V_68 , V_2 ) ;
F_52 ( V_2 ) ;
F_35 ( V_27 ) ;
F_51 ( V_54 ) ;
}
