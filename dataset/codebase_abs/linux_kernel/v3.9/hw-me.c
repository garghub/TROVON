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
static void F_15 ( struct V_6 * V_7 , bool V_18 )
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
static unsigned char F_20 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
char V_26 , V_27 ;
V_2 -> V_22 = F_8 ( V_2 ) ;
V_26 = ( char ) ( ( V_2 -> V_22 & V_28 ) >> 8 ) ;
V_27 = ( char ) ( ( V_2 -> V_22 & V_29 ) >> 16 ) ;
return ( unsigned char ) ( V_27 - V_26 ) ;
}
static bool F_21 ( struct V_6 * V_7 )
{
return F_20 ( V_7 ) == 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
unsigned char V_30 , V_31 ;
V_30 = F_20 ( V_7 ) ;
V_31 = V_7 -> V_13 - V_30 ;
if ( V_30 > V_7 -> V_13 )
return - V_32 ;
return V_31 ;
}
static T_2 F_23 ( const struct V_6 * V_7 )
{
return V_7 -> V_13 * sizeof( T_1 ) - sizeof( struct V_33 ) ;
}
static int F_24 ( struct V_6 * V_7 ,
struct V_33 * V_34 ,
unsigned char * V_35 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_36 , V_37 ;
unsigned long V_38 = V_34 -> V_38 ;
T_1 * V_39 = ( T_1 * ) V_35 ;
T_1 V_11 ;
int V_40 ;
int V_31 ;
F_16 ( & V_7 -> V_19 -> V_7 , V_41 , F_25 ( V_34 ) ) ;
V_31 = F_26 ( V_7 ) ;
F_16 ( & V_7 -> V_19 -> V_7 , L_3 , V_31 ) ;
V_37 = F_27 ( V_38 ) ;
if ( V_31 < 0 || V_37 > V_31 )
return - V_42 ;
F_3 ( V_2 , V_43 , * ( ( T_1 * ) V_34 ) ) ;
for ( V_40 = 0 ; V_40 < V_38 / 4 ; V_40 ++ )
F_3 ( V_2 , V_43 , V_39 [ V_40 ] ) ;
V_36 = V_38 & 0x3 ;
if ( V_36 > 0 ) {
T_1 V_44 = 0 ;
memcpy ( & V_44 , & V_35 [ V_38 - V_36 ] , V_36 ) ;
F_3 ( V_2 , V_43 , V_44 ) ;
}
V_11 = F_8 ( V_2 ) | V_16 ;
F_9 ( V_2 , V_11 ) ;
if ( ! F_19 ( V_7 ) )
return - V_42 ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
char V_26 , V_27 ;
unsigned char V_45 , V_30 ;
V_2 -> V_24 = F_7 ( V_2 ) ;
V_45 = ( unsigned char ) ( ( V_2 -> V_24 & V_46 ) >> 24 ) ;
V_26 = ( char ) ( ( V_2 -> V_24 & V_47 ) >> 8 ) ;
V_27 = ( char ) ( ( V_2 -> V_24 & V_48 ) >> 16 ) ;
V_30 = ( unsigned char ) ( V_27 - V_26 ) ;
if ( V_30 > V_45 )
return - V_32 ;
F_16 ( & V_7 -> V_19 -> V_7 , L_4 , V_30 ) ;
return ( int ) V_30 ;
}
static int F_29 ( struct V_6 * V_7 , unsigned char * V_49 ,
unsigned long V_50 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 * V_39 = ( T_1 * ) V_49 ;
T_1 V_11 ;
for (; V_50 >= sizeof( T_1 ) ; V_50 -= sizeof( T_1 ) )
* V_39 ++ = F_5 ( V_7 ) ;
if ( V_50 > 0 ) {
T_1 V_44 = F_5 ( V_7 ) ;
memcpy ( V_39 , & V_44 , V_50 ) ;
}
V_11 = F_8 ( V_2 ) | V_16 ;
F_9 ( V_2 , V_11 ) ;
return 0 ;
}
T_3 F_30 ( int V_51 , void * V_52 )
{
struct V_6 * V_7 = (struct V_6 * ) V_52 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_53 = F_8 ( V_2 ) ;
if ( ( V_53 & V_12 ) != V_12 )
return V_54 ;
F_3 ( V_2 , V_10 , V_53 ) ;
return V_55 ;
}
T_3 F_31 ( int V_51 , void * V_52 )
{
struct V_6 * V_7 = (struct V_6 * ) V_52 ;
struct V_56 V_57 ;
struct V_56 * V_58 = NULL , * V_59 = NULL ;
struct V_60 * V_61 ;
T_4 V_62 ;
int V_63 ;
bool V_64 ;
F_16 ( & V_7 -> V_19 -> V_7 , L_5 ) ;
F_32 ( & V_7 -> V_65 ) ;
F_33 ( & V_57 ) ;
if ( F_34 ( V_7 -> V_19 ) )
F_35 ( V_7 ) ;
if ( ! F_36 ( V_7 ) &&
V_7 -> V_20 != V_66 &&
V_7 -> V_20 != V_67 ) {
F_16 ( & V_7 -> V_19 -> V_7 , L_6 ) ;
F_37 ( V_7 , 1 ) ;
F_38 ( & V_7 -> V_65 ) ;
return V_68 ;
}
if ( ! F_39 ( V_7 ) ) {
if ( F_36 ( V_7 ) ) {
F_16 ( & V_7 -> V_19 -> V_7 , L_7 ) ;
F_40 ( V_7 ) ;
F_16 ( & V_7 -> V_19 -> V_7 , L_8 ) ;
V_7 -> V_20 = V_69 ;
F_41 ( V_7 ) ;
F_38 ( & V_7 -> V_65 ) ;
return V_68 ;
} else {
F_16 ( & V_7 -> V_19 -> V_7 , L_9 ) ;
F_14 ( V_7 ) ;
F_38 ( & V_7 -> V_65 ) ;
return V_68 ;
}
}
V_62 = F_42 ( V_7 ) ;
while ( V_62 > 0 ) {
if ( V_7 -> V_70 . V_71 . V_38 )
break;
F_16 ( & V_7 -> V_19 -> V_7 , L_10 , V_62 ) ;
F_16 ( & V_7 -> V_19 -> V_7 , L_11 ) ;
V_63 = F_43 ( V_7 , & V_57 , & V_62 ) ;
if ( V_63 )
goto V_72;
}
V_63 = F_44 ( V_7 , & V_57 ) ;
V_72:
F_16 ( & V_7 -> V_19 -> V_7 , L_12 ) ;
V_7 -> V_73 = F_45 ( V_7 ) ;
V_64 = false ;
if ( V_7 -> V_74 && F_46 ( & V_7 -> V_75 ) ) {
F_16 ( & V_7 -> V_19 -> V_7 , L_13 ) ;
V_64 = true ;
}
F_38 ( & V_7 -> V_65 ) ;
if ( V_64 ) {
F_16 ( & V_7 -> V_19 -> V_7 , L_14 ) ;
F_47 ( & V_7 -> V_75 ) ;
V_64 = false ;
}
if ( F_48 ( & V_57 . V_76 ) )
return V_68 ;
F_49 (cb_pos, cb_next, &complete_list.list, list) {
V_61 = V_58 -> V_61 ;
F_50 ( & V_58 -> V_76 ) ;
if ( V_61 ) {
if ( V_61 != & V_7 -> V_77 ) {
F_16 ( & V_7 -> V_19 -> V_7 , L_15 ) ;
F_51 ( V_61 , V_58 ) ;
V_58 = NULL ;
} else if ( V_61 == & V_7 -> V_77 ) {
F_52 ( V_7 , V_58 ) ;
}
}
}
return V_68 ;
}
struct V_6 * F_53 ( struct V_78 * V_19 )
{
struct V_6 * V_7 ;
V_7 = F_54 ( sizeof( struct V_6 ) +
sizeof( struct V_1 ) , V_79 ) ;
if ( ! V_7 )
return NULL ;
F_55 ( V_7 ) ;
F_56 ( & V_7 -> V_80 . V_81 ) ;
F_56 ( & V_7 -> V_77 . V_81 ) ;
F_33 ( & V_7 -> V_82 ) ;
F_33 ( & V_7 -> V_83 ) ;
F_57 ( & V_7 -> V_84 , V_85 ) ;
F_58 ( & V_7 -> V_86 , V_87 ) ;
V_7 -> V_88 = & V_89 ;
V_7 -> V_19 = V_19 ;
return V_7 ;
}
