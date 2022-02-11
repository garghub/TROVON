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
F_16 ( & V_7 -> V_19 -> V_7 , L_1 , V_11 ) ;
V_11 |= ( V_17 | V_16 ) ;
if ( V_18 )
V_11 |= V_15 ;
else
V_11 |= ~ V_15 ;
F_9 ( V_2 , V_11 ) ;
if ( V_7 -> V_20 == V_21 )
F_14 ( V_7 ) ;
F_16 ( & V_7 -> V_19 -> V_7 , L_2 , F_8 ( V_2 ) ) ;
return 0 ;
}
static void F_17 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
V_2 -> V_22 |= V_15 | V_16 | V_23 ;
F_9 ( V_2 , V_2 -> V_22 ) ;
}
static bool F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
V_2 -> V_22 = F_8 ( V_2 ) ;
return ( V_2 -> V_22 & V_23 ) == V_23 ;
}
static bool F_19 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
V_2 -> V_24 = F_7 ( V_2 ) ;
return ( V_2 -> V_24 & V_25 ) == V_25 ;
}
static int F_20 ( struct V_6 * V_7 )
{
int V_26 ;
if ( F_19 ( V_7 ) )
return 0 ;
V_7 -> V_27 = false ;
F_21 ( & V_7 -> V_28 ) ;
V_26 = F_22 ( V_7 -> V_29 ,
V_7 -> V_27 ,
F_23 ( V_30 ) ) ;
F_24 ( & V_7 -> V_28 ) ;
if ( ! V_26 && ! V_7 -> V_27 ) {
if ( ! V_26 )
V_26 = - V_31 ;
F_25 ( & V_7 -> V_19 -> V_7 ,
L_3 , V_26 ) ;
return V_26 ;
}
V_7 -> V_27 = false ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 )
{
int V_32 = F_20 ( V_7 ) ;
if ( V_32 )
return V_32 ;
F_16 ( & V_7 -> V_19 -> V_7 , L_4 ) ;
F_17 ( V_7 ) ;
return V_32 ;
}
static unsigned char F_27 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
char V_33 , V_34 ;
V_2 -> V_22 = F_8 ( V_2 ) ;
V_33 = ( char ) ( ( V_2 -> V_22 & V_35 ) >> 8 ) ;
V_34 = ( char ) ( ( V_2 -> V_22 & V_36 ) >> 16 ) ;
return ( unsigned char ) ( V_34 - V_33 ) ;
}
static bool F_28 ( struct V_6 * V_7 )
{
return F_27 ( V_7 ) == 0 ;
}
static int F_29 ( struct V_6 * V_7 )
{
unsigned char V_37 , V_38 ;
V_37 = F_27 ( V_7 ) ;
V_38 = V_7 -> V_13 - V_37 ;
if ( V_37 > V_7 -> V_13 )
return - V_39 ;
return V_38 ;
}
static T_2 F_30 ( const struct V_6 * V_7 )
{
return V_7 -> V_13 * sizeof( T_1 ) - sizeof( struct V_40 ) ;
}
static int F_31 ( struct V_6 * V_7 ,
struct V_40 * V_41 ,
unsigned char * V_42 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_43 ;
unsigned long V_44 = V_41 -> V_44 ;
T_1 * V_45 = ( T_1 * ) V_42 ;
T_1 V_11 ;
T_1 V_46 ;
int V_47 ;
int V_38 ;
F_16 ( & V_7 -> V_19 -> V_7 , V_48 , F_32 ( V_41 ) ) ;
V_38 = F_33 ( V_7 ) ;
F_16 ( & V_7 -> V_19 -> V_7 , L_5 , V_38 ) ;
V_46 = F_34 ( V_44 ) ;
if ( V_38 < 0 || V_46 > V_38 )
return - V_49 ;
F_3 ( V_2 , V_50 , * ( ( T_1 * ) V_41 ) ) ;
for ( V_47 = 0 ; V_47 < V_44 / 4 ; V_47 ++ )
F_3 ( V_2 , V_50 , V_45 [ V_47 ] ) ;
V_43 = V_44 & 0x3 ;
if ( V_43 > 0 ) {
T_1 V_51 = 0 ;
memcpy ( & V_51 , & V_42 [ V_44 - V_43 ] , V_43 ) ;
F_3 ( V_2 , V_50 , V_51 ) ;
}
V_11 = F_8 ( V_2 ) | V_16 ;
F_9 ( V_2 , V_11 ) ;
if ( ! F_19 ( V_7 ) )
return - V_49 ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
char V_33 , V_34 ;
unsigned char V_52 , V_37 ;
V_2 -> V_24 = F_7 ( V_2 ) ;
V_52 = ( unsigned char ) ( ( V_2 -> V_24 & V_53 ) >> 24 ) ;
V_33 = ( char ) ( ( V_2 -> V_24 & V_54 ) >> 8 ) ;
V_34 = ( char ) ( ( V_2 -> V_24 & V_55 ) >> 16 ) ;
V_37 = ( unsigned char ) ( V_34 - V_33 ) ;
if ( V_37 > V_52 )
return - V_39 ;
F_16 ( & V_7 -> V_19 -> V_7 , L_6 , V_37 ) ;
return ( int ) V_37 ;
}
static int F_36 ( struct V_6 * V_7 , unsigned char * V_56 ,
unsigned long V_57 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 * V_45 = ( T_1 * ) V_56 ;
T_1 V_11 ;
for (; V_57 >= sizeof( T_1 ) ; V_57 -= sizeof( T_1 ) )
* V_45 ++ = F_5 ( V_7 ) ;
if ( V_57 > 0 ) {
T_1 V_51 = F_5 ( V_7 ) ;
memcpy ( V_45 , & V_51 , V_57 ) ;
}
V_11 = F_8 ( V_2 ) | V_16 ;
F_9 ( V_2 , V_11 ) ;
return 0 ;
}
T_3 F_37 ( int V_58 , void * V_59 )
{
struct V_6 * V_7 = (struct V_6 * ) V_59 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_60 = F_8 ( V_2 ) ;
if ( ( V_60 & V_12 ) != V_12 )
return V_61 ;
F_3 ( V_2 , V_10 , V_60 ) ;
return V_62 ;
}
T_3 F_38 ( int V_58 , void * V_59 )
{
struct V_6 * V_7 = (struct V_6 * ) V_59 ;
struct V_63 V_64 ;
T_4 V_65 ;
int V_66 ;
F_16 ( & V_7 -> V_19 -> V_7 , L_7 ) ;
F_24 ( & V_7 -> V_28 ) ;
F_39 ( & V_64 ) ;
if ( F_40 ( V_7 -> V_19 ) )
F_41 ( V_7 ) ;
if ( ! F_42 ( V_7 ) &&
V_7 -> V_20 != V_67 &&
V_7 -> V_20 != V_68 &&
V_7 -> V_20 != V_21 &&
V_7 -> V_20 != V_69 ) {
F_16 ( & V_7 -> V_19 -> V_7 , L_8 ) ;
F_43 ( V_7 , 1 ) ;
F_21 ( & V_7 -> V_28 ) ;
return V_70 ;
}
if ( ! F_44 ( V_7 ) ) {
if ( F_42 ( V_7 ) ) {
F_16 ( & V_7 -> V_19 -> V_7 , L_9 ) ;
V_7 -> V_27 = true ;
F_45 ( & V_7 -> V_29 ) ;
F_21 ( & V_7 -> V_28 ) ;
return V_70 ;
} else {
F_16 ( & V_7 -> V_19 -> V_7 , L_10 ) ;
F_14 ( V_7 ) ;
F_21 ( & V_7 -> V_28 ) ;
return V_70 ;
}
}
V_65 = F_46 ( V_7 ) ;
while ( V_65 > 0 ) {
if ( V_7 -> V_71 . V_72 . V_44 )
break;
F_16 ( & V_7 -> V_19 -> V_7 , L_11 , V_65 ) ;
F_16 ( & V_7 -> V_19 -> V_7 , L_12 ) ;
V_66 = F_47 ( V_7 , & V_64 , & V_65 ) ;
if ( V_66 )
goto V_73;
}
V_66 = F_48 ( V_7 , & V_64 ) ;
V_73:
F_16 ( & V_7 -> V_19 -> V_7 , L_13 ) ;
V_7 -> V_74 = F_49 ( V_7 ) ;
F_21 ( & V_7 -> V_28 ) ;
F_50 ( V_7 , & V_64 ) ;
return V_70 ;
}
struct V_6 * F_51 ( struct V_75 * V_19 )
{
struct V_6 * V_7 ;
V_7 = F_52 ( sizeof( struct V_6 ) +
sizeof( struct V_1 ) , V_76 ) ;
if ( ! V_7 )
return NULL ;
F_53 ( V_7 ) ;
V_7 -> V_77 = & V_78 ;
V_7 -> V_19 = V_19 ;
return V_7 ;
}
