static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 . V_4 -> V_5 , 0 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_7 -> V_8 = V_9 ;
F_5 ( V_7 , L_1 ) ;
return F_1 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_5 ( V_7 , L_2 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_8 ( V_2 -> V_3 . V_12 ) ;
struct V_10 * V_13 ;
V_13 = F_9 ( V_11 -> V_14 , F_10 ( F_11 ( V_11 -> V_15 ) , 1 ) ) ;
if ( V_13 && V_13 -> V_16 == V_17
&& V_13 -> V_18 == V_19 ) {
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_7 -> V_8 |= V_20 ;
F_5 ( V_7 , L_3 ) ;
}
F_12 ( V_13 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_7 -> V_8 |= V_21 ;
F_5 ( V_7 , L_4 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
#ifdef F_15
V_7 -> V_8 |= V_22 ;
F_5 ( V_7 , L_5 ) ;
return 0 ;
#else
F_16 ( V_7 , L_6 ) ;
return - V_23 ;
#endif
}
static void F_17 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_18 ( V_25 , struct V_6 , V_26 ) ;
int V_27 ;
V_27 = F_19 ( V_7 ) ;
if ( V_27 != 0 ) {
F_16 ( V_7 , L_7 ,
L_8 , V_27 ) ;
return;
}
V_27 = F_20 ( V_7 ) ;
if ( V_27 != 0 )
F_16 ( V_7 , L_7 ,
L_9 , V_27 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_7 -> V_8 |= V_28 ;
F_22 ( & V_7 -> V_26 , F_17 ) ;
F_5 ( V_7 , L_10 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_10 * V_29 ;
T_1 V_30 ;
if ( F_24 () )
V_7 -> V_8 |= V_31 ;
V_29 = F_25 ( V_32 ,
V_33 , NULL ) ;
if ( ! V_29 )
return 0 ;
V_30 = V_29 -> V_34 ;
if ( ( V_30 >= 0x40 ) && ( V_30 <= 0x4f ) ) {
V_7 -> V_8 |= V_35 ;
F_5 ( V_7 , L_11 ) ;
}
F_12 ( V_29 ) ;
V_29 = NULL ;
return 0 ;
}
static void F_26 ( struct V_6 * V_7 , int V_36 )
{
struct V_10 * V_11 ;
T_2 V_37 ;
V_11 = F_8 ( F_27 ( V_7 ) -> V_3 . V_12 ) ;
F_28 ( V_11 , 0x50 , & V_37 ) ;
if ( V_36 == 0 )
F_29 ( V_11 , 0x50 , V_37 & 0xfcff ) ;
else
F_29 ( V_11 , 0x50 , V_37 | 0x0300 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_38 = 0 ;
if ( V_2 -> V_3 . V_12 ) {
struct V_10 * V_11 = F_8 ( V_2 -> V_3 . V_12 ) ;
const struct V_39 * V_40 ;
V_40 = F_31 ( V_41 , V_11 ) ;
if ( V_40 != NULL ) {
int (* F_32)( struct V_1 * V_7 );
F_32 = ( void * ) V_40 -> V_42 ;
V_38 = F_32 ( V_2 ) ;
}
}
if ( V_38 == 0 ) {
F_33 ( V_7 ) ;
return F_19 ( V_7 ) ;
}
return V_38 ;
}
static int T_3 F_34 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_38 ;
#ifdef F_35
if ( V_2 -> V_3 . V_12 ) {
struct V_10 * V_11 = F_8 ( V_2 -> V_3 . V_12 ) ;
if ( F_36 ( & V_11 -> V_5 ) )
V_7 -> V_43 |= V_44 ;
}
#endif
V_38 = F_37 ( V_7 ) ;
if ( V_38 < 0 ) {
F_16 ( V_7 , L_12 ) ;
F_38 ( V_2 ) ;
}
return V_38 ;
}
static int F_39 ( struct V_1 * V_2 , bool V_45 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
unsigned long V_8 ;
int V_46 = 0 ;
F_40 ( & V_7 -> V_47 , V_8 ) ;
if ( V_7 -> V_48 != V_49 ) {
V_46 = - V_50 ;
goto V_51;
}
F_41 ( V_7 , V_52 , & V_7 -> V_53 -> V_54 ) ;
( void ) F_42 ( V_7 , & V_7 -> V_53 -> V_54 ) ;
F_43 ( V_55 , & V_2 -> V_8 ) ;
V_51:
F_44 ( & V_7 -> V_47 , V_8 ) ;
return V_46 ;
}
static int F_45 ( struct V_1 * V_2 , bool V_56 )
{
F_46 ( V_55 , & V_2 -> V_8 ) ;
if ( V_56 )
F_47 ( F_4 ( V_2 ) ) ;
F_48 ( V_2 ) ;
return 0 ;
}
