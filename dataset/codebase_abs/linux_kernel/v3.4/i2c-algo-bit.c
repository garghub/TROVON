static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 ) ;
F_3 ( ( V_2 -> F_3 + 1 ) / 2 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 1 ) ;
F_3 ( ( V_2 -> F_3 + 1 ) / 2 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 0 ) ;
F_3 ( V_2 -> F_3 / 2 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_6 ( V_2 , 1 ) ;
if ( ! V_2 -> V_4 )
goto V_5;
V_3 = V_6 ;
while ( ! V_4 ( V_2 ) ) {
if ( F_8 ( V_6 , V_3 + V_2 -> V_7 ) ) {
if ( V_4 ( V_2 ) )
break;
return - V_8 ;
}
F_9 () ;
}
#ifdef F_10
if ( V_6 != V_3 && V_9 >= 3 )
F_11 ( L_1
L_2 , V_6 - V_3 ) ;
#endif
V_5:
F_3 ( V_2 -> F_3 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 ) ;
F_3 ( V_2 -> F_3 ) ;
F_5 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
F_7 ( V_2 ) ;
F_2 ( V_2 , 0 ) ;
F_3 ( V_2 -> F_3 ) ;
F_5 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
F_2 ( V_2 , 1 ) ;
F_3 ( V_2 -> F_3 ) ;
}
static int F_15 ( struct V_10 * V_11 , unsigned char V_12 )
{
int V_13 ;
int V_14 ;
int V_15 ;
struct V_1 * V_2 = V_11 -> V_16 ;
for ( V_13 = 7 ; V_13 >= 0 ; V_13 -- ) {
V_14 = ( V_12 >> V_13 ) & 1 ;
F_2 ( V_2 , V_14 ) ;
F_3 ( ( V_2 -> F_3 + 1 ) / 2 ) ;
if ( F_7 ( V_2 ) < 0 ) {
F_16 ( 1 , & V_11 -> V_17 , L_3
L_4 , ( int ) V_12 , V_13 ) ;
return - V_8 ;
}
F_5 ( V_2 ) ;
}
F_4 ( V_2 ) ;
if ( F_7 ( V_2 ) < 0 ) {
F_16 ( 1 , & V_11 -> V_17 , L_3
L_5 , ( int ) V_12 ) ;
return - V_8 ;
}
V_15 = ! F_17 ( V_2 ) ;
F_16 ( 2 , & V_11 -> V_17 , L_6 , ( int ) V_12 ,
V_15 ? L_7 : L_8 ) ;
F_5 ( V_2 ) ;
return V_15 ;
}
static int F_18 ( struct V_10 * V_11 )
{
int V_13 ;
unsigned char V_18 = 0 ;
struct V_1 * V_2 = V_11 -> V_16 ;
F_4 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
if ( F_7 ( V_2 ) < 0 ) {
F_16 ( 1 , & V_11 -> V_17 , L_9
L_10 , 7 - V_13 ) ;
return - V_8 ;
}
V_18 *= 2 ;
if ( F_17 ( V_2 ) )
V_18 |= 0x01 ;
F_6 ( V_2 , 0 ) ;
F_3 ( V_13 == 7 ? V_2 -> F_3 / 2 : V_2 -> F_3 ) ;
}
return V_18 ;
}
static int F_19 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_16 ;
const char * V_19 = V_11 -> V_19 ;
int V_20 , V_21 , V_22 ;
if ( V_2 -> V_23 ) {
V_22 = V_2 -> V_23 ( V_11 ) ;
if ( V_22 < 0 )
return - V_24 ;
}
if ( V_2 -> V_4 == NULL )
F_20 ( L_11 , V_19 ) ;
V_21 = F_17 ( V_2 ) ;
V_20 = ( V_2 -> V_4 == NULL ) ? 1 : V_4 ( V_2 ) ;
if ( ! V_20 || ! V_21 ) {
F_21 ( V_25
L_12 ,
V_19 , V_20 , V_21 ) ;
goto V_26;
}
F_1 ( V_2 ) ;
V_21 = F_17 ( V_2 ) ;
V_20 = ( V_2 -> V_4 == NULL ) ? 1 : V_4 ( V_2 ) ;
if ( V_21 ) {
F_21 ( V_25 L_13 , V_19 ) ;
goto V_26;
}
if ( ! V_20 ) {
F_21 ( V_25 L_14
L_15 , V_19 ) ;
goto V_26;
}
F_4 ( V_2 ) ;
V_21 = F_17 ( V_2 ) ;
V_20 = ( V_2 -> V_4 == NULL ) ? 1 : V_4 ( V_2 ) ;
if ( ! V_21 ) {
F_21 ( V_25 L_16 , V_19 ) ;
goto V_26;
}
if ( ! V_20 ) {
F_21 ( V_25 L_14
L_17 , V_19 ) ;
goto V_26;
}
F_5 ( V_2 ) ;
V_21 = F_17 ( V_2 ) ;
V_20 = ( V_2 -> V_4 == NULL ) ? 0 : V_4 ( V_2 ) ;
if ( V_20 ) {
F_21 ( V_25 L_18 , V_19 ) ;
goto V_26;
}
if ( ! V_21 ) {
F_21 ( V_25 L_19
L_20 , V_19 ) ;
goto V_26;
}
F_7 ( V_2 ) ;
V_21 = F_17 ( V_2 ) ;
V_20 = ( V_2 -> V_4 == NULL ) ? 1 : V_4 ( V_2 ) ;
if ( ! V_20 ) {
F_21 ( V_25 L_21 , V_19 ) ;
goto V_26;
}
if ( ! V_21 ) {
F_21 ( V_25 L_19
L_22 , V_19 ) ;
goto V_26;
}
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_11 ) ;
F_20 ( L_23 , V_19 ) ;
return 0 ;
V_26:
F_4 ( V_2 ) ;
F_7 ( V_2 ) ;
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_11 ) ;
return - V_24 ;
}
static int F_22 ( struct V_10 * V_11 ,
unsigned char V_28 , int V_29 )
{
struct V_1 * V_2 = V_11 -> V_16 ;
int V_13 , V_22 = 0 ;
for ( V_13 = 0 ; V_13 <= V_29 ; V_13 ++ ) {
V_22 = F_15 ( V_11 , V_28 ) ;
if ( V_22 == 1 || V_13 == V_29 )
break;
F_16 ( 3 , & V_11 -> V_17 , L_24 ) ;
F_14 ( V_2 ) ;
F_3 ( V_2 -> F_3 ) ;
F_23 () ;
F_16 ( 3 , & V_11 -> V_17 , L_25 ) ;
F_12 ( V_2 ) ;
}
if ( V_13 && V_22 )
F_16 ( 1 , & V_11 -> V_17 , L_26
L_27 , V_13 + 1 ,
V_28 & 1 ? L_28 : L_29 , V_28 >> 1 ,
V_22 == 1 ? L_30 : L_31 ) ;
return V_22 ;
}
static int F_24 ( struct V_10 * V_11 , struct V_30 * V_31 )
{
const unsigned char * V_32 = V_31 -> V_33 ;
int V_34 = V_31 -> V_35 ;
unsigned short V_36 = V_31 -> V_37 & V_38 ;
int V_39 ;
int V_40 = 0 ;
while ( V_34 > 0 ) {
V_39 = F_15 ( V_11 , * V_32 ) ;
if ( ( V_39 > 0 ) || ( V_36 && ( V_39 == 0 ) ) ) {
V_34 -- ;
V_32 ++ ;
V_40 ++ ;
} else if ( V_39 == 0 ) {
F_25 ( & V_11 -> V_17 , L_32 ) ;
return - V_41 ;
} else {
F_25 ( & V_11 -> V_17 , L_33 ,
V_39 ) ;
return V_39 ;
}
}
return V_40 ;
}
static int F_26 ( struct V_10 * V_11 , int V_42 )
{
struct V_1 * V_2 = V_11 -> V_16 ;
if ( V_42 )
F_2 ( V_2 , 0 ) ;
F_3 ( ( V_2 -> F_3 + 1 ) / 2 ) ;
if ( F_7 ( V_2 ) < 0 ) {
F_25 ( & V_11 -> V_17 , L_34 ) ;
return - V_8 ;
}
F_5 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_10 * V_11 , struct V_30 * V_31 )
{
int V_43 ;
int V_44 = 0 ;
unsigned char * V_32 = V_31 -> V_33 ;
int V_34 = V_31 -> V_35 ;
const unsigned V_37 = V_31 -> V_37 ;
while ( V_34 > 0 ) {
V_43 = F_18 ( V_11 ) ;
if ( V_43 >= 0 ) {
* V_32 = V_43 ;
V_44 ++ ;
} else {
break;
}
V_32 ++ ;
V_34 -- ;
if ( V_44 == 1 && ( V_37 & V_45 ) ) {
if ( V_43 <= 0 || V_43 > V_46 ) {
if ( ! ( V_37 & V_47 ) )
F_26 ( V_11 , 0 ) ;
F_25 ( & V_11 -> V_17 , L_35
L_36 , V_43 ) ;
return - V_48 ;
}
V_34 += V_43 ;
V_31 -> V_35 += V_43 ;
}
F_16 ( 2 , & V_11 -> V_17 , L_37 ,
V_43 ,
( V_37 & V_47 )
? L_38
: ( V_34 ? L_7 : L_8 ) ) ;
if ( ! ( V_37 & V_47 ) ) {
V_43 = F_26 ( V_11 , V_34 ) ;
if ( V_43 < 0 )
return V_43 ;
}
}
return V_44 ;
}
static int F_28 ( struct V_10 * V_11 , struct V_30 * V_31 )
{
unsigned short V_37 = V_31 -> V_37 ;
unsigned short V_36 = V_31 -> V_37 & V_38 ;
struct V_1 * V_2 = V_11 -> V_16 ;
unsigned char V_28 ;
int V_22 , V_29 ;
V_29 = V_36 ? 0 : V_11 -> V_29 ;
if ( V_37 & V_49 ) {
V_28 = 0xf0 | ( ( V_31 -> V_28 >> 7 ) & 0x06 ) ;
F_16 ( 2 , & V_11 -> V_17 , L_39 , V_28 ) ;
V_22 = F_22 ( V_11 , V_28 , V_29 ) ;
if ( ( V_22 != 1 ) && ! V_36 ) {
F_25 ( & V_11 -> V_17 ,
L_40 ) ;
return - V_50 ;
}
V_22 = F_15 ( V_11 , V_31 -> V_28 & 0xff ) ;
if ( ( V_22 != 1 ) && ! V_36 ) {
F_25 ( & V_11 -> V_17 , L_41 ) ;
return - V_50 ;
}
if ( V_37 & V_51 ) {
F_16 ( 3 , & V_11 -> V_17 , L_42
L_43 ) ;
F_13 ( V_2 ) ;
V_28 |= 0x01 ;
V_22 = F_22 ( V_11 , V_28 , V_29 ) ;
if ( ( V_22 != 1 ) && ! V_36 ) {
F_25 ( & V_11 -> V_17 ,
L_44 ) ;
return - V_41 ;
}
}
} else {
V_28 = V_31 -> V_28 << 1 ;
if ( V_37 & V_51 )
V_28 |= 1 ;
if ( V_37 & V_52 )
V_28 ^= 1 ;
V_22 = F_22 ( V_11 , V_28 , V_29 ) ;
if ( ( V_22 != 1 ) && ! V_36 )
return - V_50 ;
}
return 0 ;
}
static int F_29 ( struct V_10 * V_11 ,
struct V_30 V_53 [] , int V_54 )
{
struct V_30 * V_55 ;
struct V_1 * V_2 = V_11 -> V_16 ;
int V_13 , V_22 ;
unsigned short V_36 ;
if ( V_2 -> V_23 ) {
V_22 = V_2 -> V_23 ( V_11 ) ;
if ( V_22 < 0 )
return V_22 ;
}
F_16 ( 3 , & V_11 -> V_17 , L_25 ) ;
F_12 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_54 ; V_13 ++ ) {
V_55 = & V_53 [ V_13 ] ;
V_36 = V_55 -> V_37 & V_38 ;
if ( ! ( V_55 -> V_37 & V_56 ) ) {
if ( V_13 ) {
F_16 ( 3 , & V_11 -> V_17 , L_45
L_46 ) ;
F_13 ( V_2 ) ;
}
V_22 = F_28 ( V_11 , V_55 ) ;
if ( ( V_22 != 0 ) && ! V_36 ) {
F_16 ( 1 , & V_11 -> V_17 , L_47
L_48 ,
V_53 [ V_13 ] . V_28 , V_13 ) ;
goto V_26;
}
}
if ( V_55 -> V_37 & V_51 ) {
V_22 = F_27 ( V_11 , V_55 ) ;
if ( V_22 >= 1 )
F_16 ( 2 , & V_11 -> V_17 , L_49 ,
V_22 , V_22 == 1 ? L_50 : L_51 ) ;
if ( V_22 < V_55 -> V_35 ) {
if ( V_22 >= 0 )
V_22 = - V_41 ;
goto V_26;
}
} else {
V_22 = F_24 ( V_11 , V_55 ) ;
if ( V_22 >= 1 )
F_16 ( 2 , & V_11 -> V_17 , L_52 ,
V_22 , V_22 == 1 ? L_50 : L_51 ) ;
if ( V_22 < V_55 -> V_35 ) {
if ( V_22 >= 0 )
V_22 = - V_41 ;
goto V_26;
}
}
}
V_22 = V_13 ;
V_26:
F_16 ( 3 , & V_11 -> V_17 , L_24 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_11 ) ;
return V_22 ;
}
static T_1 F_30 ( struct V_10 * V_2 )
{
return V_57 | V_58 |
V_59 |
V_60 |
V_61 | V_62 ;
}
static int F_31 ( struct V_10 * V_2 ,
int (* F_32)( struct V_10 * ) )
{
struct V_1 * V_63 = V_2 -> V_16 ;
int V_22 ;
if ( V_64 ) {
V_22 = F_19 ( V_2 ) ;
if ( V_64 >= 2 && V_22 < 0 )
return - V_24 ;
}
V_2 -> V_65 = & V_66 ;
V_2 -> V_29 = 3 ;
V_22 = F_32 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_63 -> V_4 == NULL ) {
F_33 ( & V_2 -> V_17 , L_53 ) ;
F_33 ( & V_2 -> V_17 , L_54 ) ;
}
return 0 ;
}
int F_34 ( struct V_10 * V_2 )
{
return F_31 ( V_2 , V_67 ) ;
}
int F_35 ( struct V_10 * V_2 )
{
return F_31 ( V_2 , V_68 ) ;
}
