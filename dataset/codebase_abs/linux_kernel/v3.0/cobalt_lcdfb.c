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
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_8 = 0 ;
int V_9 = 10 , V_10 = 0 ;
do {
V_8 = F_3 ( V_2 ) ;
V_8 &= V_11 ;
if ( V_8 != V_11 )
break;
if ( F_8 ( 1 ) )
return - V_12 ;
V_9 -- ;
} while ( V_9 );
if ( V_8 == V_11 )
V_10 = - V_13 ;
return V_10 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
F_10 ( 150 ) ;
F_1 ( V_2 , V_15 ) ;
}
F_10 ( 150 ) ;
F_1 ( V_2 , V_16 ) ;
F_10 ( 150 ) ;
F_1 ( V_2 , V_17 ) ;
}
static T_2 F_11 ( struct V_1 * V_2 , char T_3 * V_18 ,
T_4 V_19 , T_5 * V_20 )
{
char V_21 [ V_22 ] ;
unsigned long V_23 ;
int V_24 , V_10 = 0 ;
V_23 = * V_20 ;
if ( V_23 >= V_22 || V_19 == 0 )
return 0 ;
if ( V_19 > V_22 )
V_19 = V_22 ;
if ( V_23 + V_19 > V_22 )
V_19 = V_22 - V_23 ;
for ( V_24 = 0 ; V_24 < V_19 ; V_24 ++ ) {
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
break;
F_1 ( V_2 , F_12 ( V_23 ) ) ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
break;
V_21 [ V_24 ] = F_6 ( V_2 ) ;
if ( V_23 == 0x0f )
V_23 = 0x40 ;
else
V_23 ++ ;
}
if ( V_10 < 0 && F_13 ( V_25 ) )
return - V_26 ;
if ( F_14 ( V_18 , V_21 , V_24 ) )
return - V_27 ;
* V_20 += V_24 ;
return V_24 ;
}
static T_2 F_15 ( struct V_1 * V_2 , const char T_3 * V_18 ,
T_4 V_19 , T_5 * V_20 )
{
char V_28 [ V_22 ] ;
unsigned long V_23 ;
int V_24 , V_10 = 0 ;
V_23 = * V_20 ;
if ( V_23 >= V_22 || V_19 == 0 )
return 0 ;
if ( V_19 > V_22 )
V_19 = V_22 ;
if ( V_23 + V_19 > V_22 )
V_19 = V_22 - V_23 ;
if ( F_16 ( V_28 , V_18 , V_19 ) )
return - V_27 ;
for ( V_24 = 0 ; V_24 < V_19 ; V_24 ++ ) {
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
break;
F_1 ( V_2 , F_12 ( V_23 ) ) ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
break;
F_5 ( V_2 , V_28 [ V_24 ] ) ;
if ( V_23 == 0x0f )
V_23 = 0x40 ;
else
V_23 ++ ;
}
if ( V_10 < 0 && F_13 ( V_25 ) )
return - V_26 ;
* V_20 += V_24 ;
return V_24 ;
}
static int F_17 ( int V_29 , struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
switch ( V_29 ) {
case V_30 :
F_1 ( V_2 , V_31 ) ;
break;
default:
F_1 ( V_2 , V_32 ) ;
break;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
V_4 V_35 , V_36 ;
int V_10 ;
switch ( V_34 -> V_37 ) {
case V_38 :
V_35 = V_34 -> V_39 . V_40 ;
V_36 = V_34 -> V_39 . V_41 ;
if ( V_35 >= V_42 || V_36 >= V_43 )
return - V_44 ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
F_1 ( V_2 ,
F_12 ( V_2 -> V_45 . V_46 * V_36 + V_35 ) ) ;
break;
default:
return - V_44 ;
}
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_34 -> V_47 )
F_1 ( V_2 , V_48 ) ;
else
F_1 ( V_2 , V_49 ) ;
return 0 ;
}
static int T_6 F_19 ( struct V_50 * V_51 )
{
struct V_1 * V_2 ;
struct V_52 * V_53 ;
int V_10 ;
V_2 = F_20 ( 0 , & V_51 -> V_51 ) ;
if ( ! V_2 )
return - V_54 ;
V_53 = F_21 ( V_51 , V_55 , 0 ) ;
if ( ! V_53 ) {
F_22 ( V_2 ) ;
return - V_13 ;
}
V_2 -> V_56 = V_53 -> V_57 - V_53 -> V_58 + 1 ;
V_2 -> V_5 = F_23 ( V_53 -> V_58 , V_2 -> V_56 ) ;
V_2 -> V_59 = & V_60 ;
V_2 -> V_45 = V_61 ;
V_2 -> V_45 . V_62 = V_53 -> V_58 ;
V_2 -> V_45 . V_63 = V_2 -> V_56 ;
V_2 -> V_64 = NULL ;
V_2 -> V_65 = NULL ;
V_2 -> V_66 = V_67 ;
V_10 = F_24 ( V_2 ) ;
if ( V_10 < 0 ) {
F_25 ( V_2 -> V_5 ) ;
F_22 ( V_2 ) ;
return V_10 ;
}
F_26 ( V_51 , V_2 ) ;
F_9 ( V_2 ) ;
F_27 ( V_68 L_1 ,
V_2 -> V_69 ) ;
return 0 ;
}
static int T_7 F_28 ( struct V_50 * V_51 )
{
struct V_1 * V_2 ;
V_2 = F_29 ( V_51 ) ;
if ( V_2 ) {
F_25 ( V_2 -> V_5 ) ;
F_30 ( V_2 ) ;
F_22 ( V_2 ) ;
}
return 0 ;
}
static int T_8 F_31 ( void )
{
return F_32 ( & V_70 ) ;
}
static void T_9 F_33 ( void )
{
F_34 ( & V_70 ) ;
}
