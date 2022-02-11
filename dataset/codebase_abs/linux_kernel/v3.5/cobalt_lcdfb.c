static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( ( V_4 ) V_3 << 24 , V_2 -> V_5 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_5 ) >> 24 ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
F_2 ( ( V_4 ) V_6 << 24 , V_2 -> V_5 + V_7 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_5 + V_7 ) >> 24 ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
do {
} while ( F_4 ( V_2 -> V_5 + V_8 ) & 1 );
}
static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_7 ( V_2 ) ;
F_2 ( V_3 , V_2 -> V_5 + V_9 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_4 ( V_2 -> V_5 + V_9 ) ;
F_7 ( V_2 ) ;
return F_4 ( V_2 -> V_5 + V_10 ) & 0xff ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
F_7 ( V_2 ) ;
F_2 ( V_6 , V_2 -> V_5 + V_11 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_4 ( V_2 -> V_5 + V_11 ) ;
F_7 ( V_2 ) ;
return F_4 ( V_2 -> V_5 + V_10 ) & 0xff ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_12 = 0 ;
int V_13 = 10 , V_14 = 0 ;
do {
V_12 = F_3 ( V_2 ) ;
V_12 &= V_15 ;
if ( V_12 != V_15 )
break;
if ( F_9 ( 1 ) )
return - V_16 ;
V_13 -- ;
} while ( V_13 );
if ( V_12 == V_15 )
V_14 = - V_17 ;
return V_14 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
F_11 ( 150 ) ;
F_1 ( V_2 , V_19 ) ;
}
F_11 ( 150 ) ;
F_1 ( V_2 , V_20 ) ;
F_11 ( 150 ) ;
F_1 ( V_2 , V_21 ) ;
}
static T_2 F_12 ( struct V_1 * V_2 , char T_3 * V_22 ,
T_4 V_23 , T_5 * V_24 )
{
char V_25 [ V_26 ] ;
unsigned long V_27 ;
int V_28 , V_14 = 0 ;
V_27 = * V_24 ;
if ( V_27 >= V_26 || V_23 == 0 )
return 0 ;
if ( V_23 > V_26 )
V_23 = V_26 ;
if ( V_27 + V_23 > V_26 )
V_23 = V_26 - V_27 ;
for ( V_28 = 0 ; V_28 < V_23 ; V_28 ++ ) {
V_14 = F_8 ( V_2 ) ;
if ( V_14 < 0 )
break;
F_1 ( V_2 , F_13 ( V_27 ) ) ;
V_14 = F_8 ( V_2 ) ;
if ( V_14 < 0 )
break;
V_25 [ V_28 ] = F_6 ( V_2 ) ;
if ( V_27 == 0x0f )
V_27 = 0x40 ;
else
V_27 ++ ;
}
if ( V_14 < 0 && F_14 ( V_29 ) )
return - V_30 ;
if ( F_15 ( V_22 , V_25 , V_28 ) )
return - V_31 ;
* V_24 += V_28 ;
return V_28 ;
}
static T_2 F_16 ( struct V_1 * V_2 , const char T_3 * V_22 ,
T_4 V_23 , T_5 * V_24 )
{
char V_32 [ V_26 ] ;
unsigned long V_27 ;
int V_28 , V_14 = 0 ;
V_27 = * V_24 ;
if ( V_27 >= V_26 || V_23 == 0 )
return 0 ;
if ( V_23 > V_26 )
V_23 = V_26 ;
if ( V_27 + V_23 > V_26 )
V_23 = V_26 - V_27 ;
if ( F_17 ( V_32 , V_22 , V_23 ) )
return - V_31 ;
for ( V_28 = 0 ; V_28 < V_23 ; V_28 ++ ) {
V_14 = F_8 ( V_2 ) ;
if ( V_14 < 0 )
break;
F_1 ( V_2 , F_13 ( V_27 ) ) ;
V_14 = F_8 ( V_2 ) ;
if ( V_14 < 0 )
break;
F_5 ( V_2 , V_32 [ V_28 ] ) ;
if ( V_27 == 0x0f )
V_27 = 0x40 ;
else
V_27 ++ ;
}
if ( V_14 < 0 && F_14 ( V_29 ) )
return - V_30 ;
* V_24 += V_28 ;
return V_28 ;
}
static int F_18 ( int V_33 , struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_8 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
switch ( V_33 ) {
case V_34 :
F_1 ( V_2 , V_35 ) ;
break;
default:
F_1 ( V_2 , V_36 ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
V_4 V_39 , V_40 ;
int V_14 ;
switch ( V_38 -> V_41 ) {
case V_42 :
V_39 = V_38 -> V_43 . V_44 ;
V_40 = V_38 -> V_43 . V_45 ;
if ( V_39 >= V_46 || V_40 >= V_47 )
return - V_48 ;
V_14 = F_8 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
F_1 ( V_2 ,
F_13 ( V_2 -> V_49 . V_50 * V_40 + V_39 ) ) ;
break;
default:
return - V_48 ;
}
V_14 = F_8 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_38 -> V_51 )
F_1 ( V_2 , V_52 ) ;
else
F_1 ( V_2 , V_53 ) ;
return 0 ;
}
static int T_6 F_20 ( struct V_54 * V_55 )
{
struct V_1 * V_2 ;
struct V_56 * V_57 ;
int V_14 ;
V_2 = F_21 ( 0 , & V_55 -> V_55 ) ;
if ( ! V_2 )
return - V_58 ;
V_57 = F_22 ( V_55 , V_59 , 0 ) ;
if ( ! V_57 ) {
F_23 ( V_2 ) ;
return - V_17 ;
}
V_2 -> V_60 = F_24 ( V_57 ) ;
V_2 -> V_5 = F_25 ( V_57 -> V_61 , V_2 -> V_60 ) ;
V_2 -> V_62 = & V_63 ;
V_2 -> V_49 = V_64 ;
V_2 -> V_49 . V_65 = V_57 -> V_61 ;
V_2 -> V_49 . V_66 = V_2 -> V_60 ;
V_2 -> V_67 = NULL ;
V_2 -> V_68 = NULL ;
V_2 -> V_69 = V_70 ;
V_14 = F_26 ( V_2 ) ;
if ( V_14 < 0 ) {
F_27 ( V_2 -> V_5 ) ;
F_23 ( V_2 ) ;
return V_14 ;
}
F_28 ( V_55 , V_2 ) ;
F_10 ( V_2 ) ;
F_29 ( V_71 L_1 ,
V_2 -> V_72 ) ;
return 0 ;
}
static int T_7 F_30 ( struct V_54 * V_55 )
{
struct V_1 * V_2 ;
V_2 = F_31 ( V_55 ) ;
if ( V_2 ) {
F_27 ( V_2 -> V_5 ) ;
F_32 ( V_2 ) ;
F_23 ( V_2 ) ;
}
return 0 ;
}
static int T_8 F_33 ( void )
{
return F_34 ( & V_73 ) ;
}
static void T_9 F_35 ( void )
{
F_36 ( & V_73 ) ;
}
