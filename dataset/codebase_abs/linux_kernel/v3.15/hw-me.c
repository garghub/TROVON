static inline T_1 F_1 ( const struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( const struct V_1 * V_2 ,
unsigned long V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_1 F_5 ( const struct V_6 * V_7 )
{
return F_1 ( F_6 ( V_7 ) , V_8 ) ;
}
static inline T_1 F_7 ( const struct V_1 * V_2 )
{
return F_1 ( V_2 , V_9 ) ;
}
static inline T_1 F_8 ( const struct V_1 * V_2 )
{
return F_1 ( V_2 , V_10 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_11 )
{
V_11 &= ~ V_12 ;
F_3 ( V_2 , V_10 , V_11 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
T_1 V_11 = F_8 ( F_6 ( V_7 ) ) ;
V_7 -> V_13 = ( V_11 & V_14 ) >> 24 ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
if ( ( V_11 & V_12 ) == V_12 )
F_3 ( V_2 , V_10 , V_11 ) ;
}
static void F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
V_11 |= V_15 ;
F_9 ( V_2 , V_11 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
V_11 &= ~ V_15 ;
F_9 ( V_2 , V_11 ) ;
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
V_11 |= V_16 ;
V_11 &= ~ V_17 ;
F_9 ( V_2 , V_11 ) ;
}
static int F_15 ( struct V_6 * V_7 , bool V_18 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
V_11 |= V_17 | V_16 | V_12 ;
if ( V_18 )
V_11 |= V_15 ;
else
V_11 &= ~ V_15 ;
F_3 ( V_2 , V_10 , V_11 ) ;
if ( V_18 == false )
F_14 ( V_7 ) ;
return 0 ;
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
V_2 -> V_19 |= V_15 | V_16 | V_20 ;
F_9 ( V_2 , V_2 -> V_19 ) ;
}
static bool F_17 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
V_2 -> V_19 = F_8 ( V_2 ) ;
return ( V_2 -> V_19 & V_20 ) == V_20 ;
}
static bool F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
V_2 -> V_21 = F_7 ( V_2 ) ;
return ( V_2 -> V_21 & V_22 ) == V_22 ;
}
static int F_19 ( struct V_6 * V_7 )
{
int V_23 ;
if ( F_18 ( V_7 ) )
return 0 ;
V_7 -> V_24 = false ;
F_20 ( & V_7 -> V_25 ) ;
V_23 = F_21 ( V_7 -> V_26 ,
V_7 -> V_24 ,
F_22 ( V_27 ) ) ;
F_23 ( & V_7 -> V_25 ) ;
if ( ! V_23 && ! V_7 -> V_24 ) {
if ( ! V_23 )
V_23 = - V_28 ;
F_24 ( & V_7 -> V_29 -> V_7 ,
L_1 , V_23 ) ;
return V_23 ;
}
V_7 -> V_24 = false ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 )
{
int V_30 = F_19 ( V_7 ) ;
if ( V_30 )
return V_30 ;
F_26 ( & V_7 -> V_29 -> V_7 , L_2 ) ;
F_16 ( V_7 ) ;
return V_30 ;
}
static unsigned char F_27 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
char V_31 , V_32 ;
V_2 -> V_19 = F_8 ( V_2 ) ;
V_31 = ( char ) ( ( V_2 -> V_19 & V_33 ) >> 8 ) ;
V_32 = ( char ) ( ( V_2 -> V_19 & V_34 ) >> 16 ) ;
return ( unsigned char ) ( V_32 - V_31 ) ;
}
static bool F_28 ( struct V_6 * V_7 )
{
return F_27 ( V_7 ) == 0 ;
}
static int F_29 ( struct V_6 * V_7 )
{
unsigned char V_35 , V_36 ;
V_35 = F_27 ( V_7 ) ;
V_36 = V_7 -> V_13 - V_35 ;
if ( V_35 > V_7 -> V_13 )
return - V_37 ;
return V_36 ;
}
static T_2 F_30 ( const struct V_6 * V_7 )
{
return V_7 -> V_13 * sizeof( T_1 ) - sizeof( struct V_38 ) ;
}
static int F_31 ( struct V_6 * V_7 ,
struct V_38 * V_39 ,
unsigned char * V_40 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_41 ;
unsigned long V_42 = V_39 -> V_42 ;
T_1 * V_43 = ( T_1 * ) V_40 ;
T_1 V_11 ;
T_1 V_44 ;
int V_45 ;
int V_36 ;
F_26 ( & V_7 -> V_29 -> V_7 , V_46 , F_32 ( V_39 ) ) ;
V_36 = F_33 ( V_7 ) ;
F_26 ( & V_7 -> V_29 -> V_7 , L_3 , V_36 ) ;
V_44 = F_34 ( V_42 ) ;
if ( V_36 < 0 || V_44 > V_36 )
return - V_47 ;
F_3 ( V_2 , V_48 , * ( ( T_1 * ) V_39 ) ) ;
for ( V_45 = 0 ; V_45 < V_42 / 4 ; V_45 ++ )
F_3 ( V_2 , V_48 , V_43 [ V_45 ] ) ;
V_41 = V_42 & 0x3 ;
if ( V_41 > 0 ) {
T_1 V_49 = 0 ;
memcpy ( & V_49 , & V_40 [ V_42 - V_41 ] , V_41 ) ;
F_3 ( V_2 , V_48 , V_49 ) ;
}
V_11 = F_8 ( V_2 ) | V_16 ;
F_9 ( V_2 , V_11 ) ;
if ( ! F_18 ( V_7 ) )
return - V_50 ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
char V_31 , V_32 ;
unsigned char V_51 , V_35 ;
V_2 -> V_21 = F_7 ( V_2 ) ;
V_51 = ( unsigned char ) ( ( V_2 -> V_21 & V_52 ) >> 24 ) ;
V_31 = ( char ) ( ( V_2 -> V_21 & V_53 ) >> 8 ) ;
V_32 = ( char ) ( ( V_2 -> V_21 & V_54 ) >> 16 ) ;
V_35 = ( unsigned char ) ( V_32 - V_31 ) ;
if ( V_35 > V_51 )
return - V_37 ;
F_26 ( & V_7 -> V_29 -> V_7 , L_4 , V_35 ) ;
return ( int ) V_35 ;
}
static int F_36 ( struct V_6 * V_7 , unsigned char * V_55 ,
unsigned long V_56 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 * V_43 = ( T_1 * ) V_55 ;
T_1 V_11 ;
for (; V_56 >= sizeof( T_1 ) ; V_56 -= sizeof( T_1 ) )
* V_43 ++ = F_5 ( V_7 ) ;
if ( V_56 > 0 ) {
T_1 V_49 = F_5 ( V_7 ) ;
memcpy ( V_43 , & V_49 , V_56 ) ;
}
V_11 = F_8 ( V_2 ) | V_16 ;
F_9 ( V_2 , V_11 ) ;
return 0 ;
}
T_3 F_37 ( int V_57 , void * V_58 )
{
struct V_6 * V_7 = (struct V_6 * ) V_58 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_59 = F_8 ( V_2 ) ;
if ( ( V_59 & V_12 ) != V_12 )
return V_60 ;
F_3 ( V_2 , V_10 , V_59 ) ;
return V_61 ;
}
T_3 F_38 ( int V_57 , void * V_58 )
{
struct V_6 * V_7 = (struct V_6 * ) V_58 ;
struct V_62 V_63 ;
T_4 V_64 ;
int V_65 = 0 ;
F_26 ( & V_7 -> V_29 -> V_7 , L_5 ) ;
F_23 ( & V_7 -> V_25 ) ;
F_39 ( & V_63 ) ;
if ( F_40 ( V_7 -> V_29 ) )
F_41 ( V_7 ) ;
if ( ! F_42 ( V_7 ) && V_7 -> V_66 != V_67 ) {
F_43 ( & V_7 -> V_29 -> V_7 , L_6 ) ;
F_44 ( & V_7 -> V_68 ) ;
goto V_69;
}
if ( ! F_45 ( V_7 ) ) {
if ( F_42 ( V_7 ) ) {
F_26 ( & V_7 -> V_29 -> V_7 , L_7 ) ;
V_7 -> V_24 = true ;
F_46 ( & V_7 -> V_26 ) ;
} else {
F_26 ( & V_7 -> V_29 -> V_7 , L_8 ) ;
F_14 ( V_7 ) ;
}
goto V_69;
}
V_64 = F_47 ( V_7 ) ;
while ( V_64 > 0 ) {
F_26 ( & V_7 -> V_29 -> V_7 , L_9 , V_64 ) ;
V_65 = F_48 ( V_7 , & V_63 , & V_64 ) ;
if ( V_65 == - V_70 )
break;
if ( V_65 && V_7 -> V_66 != V_67 ) {
F_24 ( & V_7 -> V_29 -> V_7 , L_10 ,
V_65 ) ;
F_44 ( & V_7 -> V_68 ) ;
goto V_69;
}
}
V_7 -> V_71 = F_49 ( V_7 ) ;
V_65 = F_50 ( V_7 , & V_63 ) ;
V_7 -> V_71 = F_49 ( V_7 ) ;
F_51 ( V_7 , & V_63 ) ;
V_69:
F_26 ( & V_7 -> V_29 -> V_7 , L_11 , V_65 ) ;
F_20 ( & V_7 -> V_25 ) ;
return V_72 ;
}
struct V_6 * F_52 ( struct V_73 * V_29 )
{
struct V_6 * V_7 ;
V_7 = F_53 ( sizeof( struct V_6 ) +
sizeof( struct V_1 ) , V_74 ) ;
if ( ! V_7 )
return NULL ;
F_54 ( V_7 ) ;
V_7 -> V_75 = & V_76 ;
V_7 -> V_29 = V_29 ;
return V_7 ;
}
