static inline void F_1 ( void T_1 * V_1 , int V_2 , int V_3 ,
unsigned long V_4 )
{
F_2 ( V_4 , F_3 ( V_1 , V_2 , V_3 ) ) ;
}
static inline unsigned long F_4 ( void T_1 * V_1 , int V_2 , int V_3 )
{
return F_5 ( F_3 ( V_1 , V_2 , V_3 ) ) ;
}
static inline void F_6 ( void T_1 * V_1 , int V_3 ,
unsigned long V_4 )
{
F_2 ( V_4 , V_1 + V_3 ) ;
}
static inline unsigned long F_7 ( void T_1 * V_1 , int V_3 )
{
return F_5 ( V_1 + V_3 ) ;
}
static inline int F_8 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
int V_9 ;
int V_10 , V_11 , V_12 , V_13 ;
if ( V_8 -> V_14 & ~ 0x1f || V_8 -> V_15 & ~ 0x1f )
return 1 ;
if ( F_9 ( V_8 -> V_14 , & V_6 -> V_16 ) ||
F_9 ( V_8 -> V_15 , & V_6 -> V_16 ) )
return 1 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_17 ; V_9 ++ ) {
V_10 = F_10 ( V_6 -> V_18 [ V_9 ] ) ;
V_11 = F_11 ( V_6 -> V_18 [ V_9 ] ) ;
V_12 = V_8 -> V_19 ;
V_13 = V_8 -> V_19 + V_8 -> V_20 ;
if ( ( V_12 >= V_10 && V_12 < V_11 ) ||
( V_13 > V_10 && V_13 < V_11 ) )
return 1 ;
}
return 0 ;
}
static inline void F_12 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
int V_21 ;
if ( V_8 -> V_14 < 0 || V_8 -> V_15 < 0 )
return;
F_13 ( V_8 -> V_14 , & V_6 -> V_16 ) ;
F_13 ( V_8 -> V_15 , & V_6 -> V_16 ) ;
V_21 = V_6 -> V_17 ;
V_6 -> V_18 [ V_21 ] = F_14 ( V_8 -> V_19 ,
V_8 -> V_20 ) ;
V_6 -> V_17 ++ ;
}
static inline void F_15 ( struct V_5 * V_6 ,
struct V_7 * V_22 )
{
int V_9 ;
unsigned long V_23 ;
if ( V_22 -> V_14 < 0 || V_22 -> V_15 < 0 )
return;
F_16 ( V_22 -> V_14 , & V_6 -> V_16 ) ;
F_16 ( V_22 -> V_15 , & V_6 -> V_16 ) ;
V_23 = F_14 ( V_22 -> V_19 , V_22 -> V_20 ) ;
for ( V_9 = 0 ; V_9 < V_6 -> V_17 ; V_9 ++ ) {
if ( V_6 -> V_18 [ V_9 ] == V_23 ) {
while ( V_9 < V_6 -> V_17 - 1 ) {
V_6 -> V_18 [ V_9 ] =
V_6 -> V_18 [ V_9 + 1 ] ;
V_9 ++ ;
}
V_6 -> V_18 [ V_9 ] = 0 ;
V_6 -> V_17 -- ;
break;
}
}
}
static inline int F_17 ( int V_24 )
{
if ( V_24 == V_25 ||
V_24 == V_26 )
return 1 ;
return 0 ;
}
static inline void F_18 ( struct V_5 * V_6 ,
struct V_27 * V_28 ,
unsigned long V_29 ,
unsigned long V_30 )
{
unsigned long V_31 ;
V_31 = ( V_28 -> V_32 ) ? V_33 : V_34 ;
V_28 -> V_32 ^= 1 ;
F_1 ( V_6 -> V_1 , V_28 -> V_22 [ 0 ] . V_15 , V_31 ,
V_29 ) ;
F_1 ( V_6 -> V_1 , V_28 -> V_22 [ 0 ] . V_14 , V_31 ,
V_29 + V_28 -> V_22 [ 0 ] . V_35 ) ;
if ( F_17 ( V_28 -> V_36 ) ) {
F_1 ( V_6 -> V_1 , V_28 -> V_22 [ 1 ] . V_15 , V_31 ,
V_30 ) ;
F_1 ( V_6 -> V_1 , V_28 -> V_22 [ 1 ] . V_14 , V_31 ,
V_30 + V_28 -> V_22 [ 1 ] . V_35 ) ;
}
}
static inline void F_19 ( struct V_37 * V_38 ,
struct V_27 * V_28 ,
unsigned long * V_39 ,
unsigned long * V_40 )
{
unsigned long V_41 ;
if ( V_38 -> V_42 == V_43 )
V_41 = 0x80000000 | ( V_28 -> V_32 << 29 ) ;
else
V_41 = 0xc0000000 | ( V_28 -> V_32 << 23 ) ;
* V_39 = V_41 | ( V_28 -> V_22 [ 0 ] . V_14 << 24 ) ;
if ( F_17 ( V_28 -> V_36 ) )
* V_40 = V_41 | ( V_28 -> V_22 [ 1 ] . V_14 << 24 ) ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_7 * V_22 ,
int V_44 , int V_45 , int * V_46 )
{
unsigned long V_47 = F_21 ( V_44 , V_45 ) ;
unsigned long V_48 ;
int V_49 , V_50 , V_51 ;
int V_52 ;
V_49 = ( V_44 - 1 ) | 1023 ;
V_49 = V_49 | ( V_49 >> 1 ) ;
V_49 = V_49 | ( V_49 >> 2 ) ;
V_49 += 1 ;
if ( V_49 == 8192 && V_45 >= 1024 ) {
V_49 = V_50 = V_53 ;
V_51 = V_47 >> 11 ;
* V_46 = V_44 ;
V_52 = ( V_22 -> V_20 / 16 / V_54 ) ;
V_52 *= V_54 ;
} else {
V_50 = V_44 ;
V_51 = V_45 ;
* V_46 = V_49 ;
V_52 = V_22 -> V_20 / ( V_49 >> 10 ) / 2 ;
V_52 &= 0xff ;
}
V_48 = ( V_52 - 1 ) << 16 ;
F_1 ( V_6 -> V_1 , V_22 -> V_15 , V_55 ,
F_22 ( 0x0 , V_51 - 1 , V_50 - 1 ) ) ;
F_1 ( V_6 -> V_1 , V_22 -> V_14 , V_55 ,
F_22 ( 0xf , V_51 - 1 , V_50 - 1 ) ) ;
F_1 ( V_6 -> V_1 , V_22 -> V_15 , V_56 , V_48 ) ;
F_1 ( V_6 -> V_1 , V_22 -> V_14 , V_56 , V_48 ) ;
F_1 ( V_6 -> V_1 , V_22 -> V_15 , V_57 , V_50 ) ;
F_1 ( V_6 -> V_1 , V_22 -> V_14 , V_57 , V_50 ) ;
V_22 -> V_35 = V_44 * V_52 ;
F_1 ( V_6 -> V_1 , V_22 -> V_15 , V_58 ,
F_23 ( 0x70f , V_22 -> V_14 ,
V_22 -> V_19 ) ) ;
F_1 ( V_6 -> V_1 , V_22 -> V_14 , V_58 ,
F_23 ( 0x70f , V_22 -> V_15 ,
V_22 -> V_19 +
V_22 -> V_20 / 2 ) ) ;
return 0 ;
}
static void F_24 ( struct V_5 * V_6 ,
struct V_7 * V_22 )
{
F_1 ( V_6 -> V_1 , V_22 -> V_15 , V_58 , 0 ) ;
F_1 ( V_6 -> V_1 , V_22 -> V_14 , V_58 , 0 ) ;
V_22 -> V_35 = 0 ;
}
static int F_25 ( struct V_37 * V_38 ,
struct V_27 * V_28 ,
int V_44 , int V_45 , int V_36 ,
unsigned long V_29 ,
unsigned long V_30 ,
unsigned long * V_39 ,
unsigned long * V_40 ,
int * V_59 )
{
struct V_60 * V_61 ;
struct V_5 * V_6 ;
int V_21 , V_46 ;
int error = 0 ;
if ( ! V_38 || ! V_38 -> V_6 || ! V_38 -> V_61 || ! V_28 )
return - V_62 ;
if ( V_36 != V_25 &&
V_36 != V_26 &&
V_36 != V_63 )
return - V_62 ;
V_6 = V_38 -> V_6 ;
V_61 = V_38 -> V_61 ;
F_26 ( & V_61 -> V_64 , L_1 ,
V_44 , V_45 , ( ! V_36 ) ? L_2 : L_3 ,
V_29 , V_30 ) ;
F_27 ( & V_6 -> V_65 ) ;
if ( V_44 > 8192 ) {
F_28 ( & V_61 -> V_64 , L_4 ) ;
error = - V_62 ;
goto V_66;
}
if ( V_6 -> V_17 + 2 > V_67 ) {
F_28 ( & V_61 -> V_64 , L_5 ) ;
error = - V_62 ;
goto V_66;
}
if ( V_28 -> V_22 [ 0 ] . V_14 < 0 || V_28 -> V_22 [ 0 ] . V_15 < 0 ) {
F_28 ( & V_61 -> V_64 , L_6 ) ;
error = - V_62 ;
goto V_66;
}
if ( F_8 ( V_6 , & V_28 -> V_22 [ 0 ] ) ) {
F_28 ( & V_61 -> V_64 , L_7 ) ;
error = - V_62 ;
goto V_66;
}
V_21 = 1 ;
if ( V_28 -> V_22 [ 1 ] . V_14 >= 0 && V_28 -> V_22 [ 1 ] . V_15 >= 0 ) {
if ( F_8 ( V_6 , & V_28 -> V_22 [ 1 ] ) ) {
F_28 ( & V_61 -> V_64 , L_7 ) ;
error = - V_62 ;
goto V_66;
}
V_21 = 2 ;
}
if ( F_17 ( V_36 ) && V_21 != 2 ) {
F_28 ( & V_61 -> V_64 , L_8 ) ;
error = - V_62 ;
goto V_66;
}
V_28 -> V_36 = V_36 ;
F_12 ( V_6 , & V_28 -> V_22 [ 0 ] ) ;
if ( F_17 ( V_36 ) )
F_12 ( V_6 , & V_28 -> V_22 [ 1 ] ) ;
F_20 ( V_6 , & V_28 -> V_22 [ 0 ] , V_44 , V_45 , & V_46 ) ;
* V_59 = V_46 ;
if ( V_36 == V_25 )
F_20 ( V_6 , & V_28 -> V_22 [ 1 ] , V_44 , ( V_45 + 1 ) / 2 ,
& V_46 ) ;
else if ( V_36 == V_26 )
F_20 ( V_6 , & V_28 -> V_22 [ 1 ] , 2 * V_44 , ( V_45 + 1 ) / 2 ,
& V_46 ) ;
V_28 -> V_32 = 1 ;
F_18 ( V_6 , V_28 , V_29 , V_30 ) ;
F_19 ( V_38 , V_28 , V_39 , V_40 ) ;
F_26 ( & V_61 -> V_64 , L_9 ,
* V_39 , * V_40 ) ;
V_66:
F_29 ( & V_6 -> V_65 ) ;
return error ;
}
static int F_30 ( struct V_37 * V_38 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 ;
if ( ! V_38 || ! V_38 -> V_6 || ! V_28 )
return - V_62 ;
V_6 = V_38 -> V_6 ;
F_27 ( & V_6 -> V_65 ) ;
if ( F_17 ( V_28 -> V_36 ) ) {
F_24 ( V_6 , & V_28 -> V_22 [ 1 ] ) ;
F_15 ( V_6 , & V_28 -> V_22 [ 1 ] ) ;
}
F_24 ( V_6 , & V_28 -> V_22 [ 0 ] ) ;
F_15 ( V_6 , & V_28 -> V_22 [ 0 ] ) ;
F_29 ( & V_6 -> V_65 ) ;
return 0 ;
}
static int F_31 ( struct V_37 * V_38 ,
struct V_27 * V_28 ,
unsigned long V_29 ,
unsigned long V_30 ,
unsigned long * V_39 ,
unsigned long * V_40 )
{
struct V_5 * V_6 ;
if ( ! V_38 || ! V_38 -> V_6 || ! V_28 )
return - V_62 ;
V_6 = V_38 -> V_6 ;
F_27 ( & V_6 -> V_65 ) ;
F_18 ( V_6 , V_28 , V_29 , V_30 ) ;
F_19 ( V_38 , V_28 , V_39 , V_40 ) ;
F_29 ( & V_6 -> V_65 ) ;
return 0 ;
}
static int T_2 F_32 ( struct V_60 * V_61 )
{
struct V_5 * V_6 ;
struct V_37 * V_38 = V_61 -> V_64 . V_68 ;
struct V_69 * V_70 ;
int error ;
if ( ! V_38 ) {
F_28 ( & V_61 -> V_64 , L_10 ) ;
return - V_62 ;
}
V_70 = F_33 ( V_61 , V_71 , 0 ) ;
if ( ! V_70 ) {
F_28 ( & V_61 -> V_64 , L_11 ) ;
return - V_72 ;
}
V_6 = F_34 ( sizeof( * V_6 ) , V_73 ) ;
if ( ! V_6 ) {
F_28 ( & V_61 -> V_64 , L_12 ) ;
return - V_74 ;
}
F_35 ( V_61 , V_6 ) ;
F_36 ( & V_6 -> V_65 ) ;
V_6 -> V_1 = F_37 ( V_70 -> V_75 , F_38 ( V_70 ) ) ;
if ( ! V_6 -> V_1 ) {
F_28 ( & V_61 -> V_64 , L_13 ) ;
error = - V_76 ;
goto V_66;
}
V_38 -> V_77 = & V_78 ;
V_38 -> V_6 = V_6 ;
V_38 -> V_61 = V_61 ;
if ( V_38 -> V_42 == V_79 )
F_6 ( V_6 -> V_1 , V_80 , 1 << 29 ) ;
F_39 ( & V_61 -> V_64 , L_14 ) ;
return 0 ;
V_66:
F_40 ( V_61 ) ;
return error ;
}
static int F_40 ( struct V_60 * V_61 )
{
struct V_5 * V_6 = F_41 ( V_61 ) ;
if ( V_6 -> V_1 )
F_42 ( V_6 -> V_1 ) ;
F_43 ( & V_6 -> V_65 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
static int T_3 F_45 ( void )
{
return F_46 ( & V_81 ) ;
}
static void T_4 F_47 ( void )
{
F_48 ( & V_81 ) ;
}
