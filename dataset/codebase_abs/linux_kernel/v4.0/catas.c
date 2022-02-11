static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 -> V_6 , 0 , & V_3 ) ;
if ( V_4 ) {
F_3 ( V_2 , L_1 , V_4 ) ;
return V_4 ;
}
if ( V_3 == 0xffff ) {
F_3 ( V_2 , L_2 ) ;
return - V_7 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
if ( F_5 ( V_2 ) )
F_6 ( V_2 ) ;
if ( ! F_7 ( V_2 -> V_5 -> V_6 ) ) {
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
return 0 ;
V_8 = F_8 ( V_2 ) ;
if ( V_8 )
F_3 ( V_2 , L_3 ) ;
}
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 )
{
#define F_10 0x10
#define F_11 0x08
T_2 V_9 ;
T_2 V_10 ;
T_2 V_11 ;
unsigned long V_12 ;
struct V_13 * V_14 = V_13 ( V_2 ) ;
if ( F_7 ( V_2 -> V_5 -> V_6 ) )
return 0 ;
V_9 = F_12 ( F_13 ( ( V_15 char * ) V_14 -> V_16 . V_17 +
V_18 ) ) ;
if ( V_9 == 0xffffffff ) {
F_3 ( V_2 , L_4 ) ;
return 0 ;
}
if ( ! ( V_2 -> V_19 . V_20 & V_21 ) ) {
F_3 ( V_2 , L_5 ) ;
return - V_22 ;
}
V_10 = ( V_9 & ( T_2 ) ( 1 << F_10 ) ) >>
F_10 ;
V_11 = ( V_9 & ( T_2 ) ( 1 << F_11 ) ) >>
F_11 ;
if ( V_10 != V_11 ) {
F_3 ( V_2 , L_6 ) ;
return - V_23 ;
}
V_10 ^= 1 ;
F_14 ( V_2 , L_7 ) ;
V_9 = V_10 << F_10 ;
F_15 ( ( V_24 T_2 ) F_16 ( V_9 ) ,
( V_15 char * ) V_14 -> V_16 . V_17 + V_18 ) ;
F_17 () ;
V_12 = F_18 ( V_25 ) + V_26 ;
while ( F_19 ( V_26 , V_12 ) ) {
V_9 = F_12 ( F_13 ( ( V_15 char * ) V_14 -> V_16 . V_17 +
V_18 ) ) ;
V_11 = ( V_9 & ( T_2 ) ( 1 << F_11 ) ) >>
F_11 ;
V_10 = ( V_9 & ( T_2 ) ( 1 << F_10 ) ) >>
F_10 ;
if ( V_11 == V_10 ) {
F_14 ( V_2 , L_8 ) ;
return 0 ;
}
F_20 () ;
}
F_3 ( V_2 , L_9 ) ;
return - V_27 ;
}
static int F_21 ( T_2 V_28 )
{
return ( T_2 ) V_29 ==
( V_28 & ( T_2 ) V_29 ) ? 1 : 0 ;
}
void F_22 ( struct V_30 * V_5 )
{
int V_8 ;
struct V_1 * V_2 ;
if ( ! V_31 )
return;
F_23 ( & V_5 -> V_32 ) ;
if ( V_5 -> V_33 & V_34 )
goto V_35;
V_2 = V_5 -> V_2 ;
F_3 ( V_2 , L_10 ) ;
if ( F_24 ( V_2 ) )
V_8 = F_9 ( V_2 ) ;
else
V_8 = F_4 ( V_2 ) ;
F_25 ( V_8 != 0 ) ;
V_2 -> V_5 -> V_33 |= V_34 ;
F_3 ( V_2 , L_11 ) ;
F_26 ( & V_5 -> V_32 ) ;
F_27 ( V_2 , V_36 , 0 ) ;
F_28 ( V_2 ) ;
return;
V_35:
F_26 ( & V_5 -> V_32 ) ;
}
static void F_29 ( struct V_30 * V_5 )
{
int V_8 = 0 ;
F_22 ( V_5 ) ;
F_23 ( & V_5 -> V_37 ) ;
if ( V_5 -> V_38 & V_39 &&
! ( V_5 -> V_38 & V_40 ) ) {
V_8 = F_30 ( V_5 -> V_6 ) ;
F_31 ( V_5 -> V_2 , L_12 ,
V_8 ) ;
}
F_26 ( & V_5 -> V_37 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_13 ( V_2 ) ;
int V_41 ;
F_3 ( V_2 , L_13 ) ;
for ( V_41 = 0 ; V_41 < V_14 -> V_42 . V_43 ; ++ V_41 )
F_3 ( V_2 , L_14 ,
V_41 , F_12 ( F_13 ( V_14 -> V_44 . V_45 + V_41 ) ) ) ;
}
static void F_33 ( unsigned long V_46 )
{
struct V_1 * V_2 = (struct V_1 * ) V_46 ;
struct V_13 * V_14 = V_13 ( V_2 ) ;
T_2 V_28 ;
if ( F_24 ( V_2 ) ) {
V_28 = F_12 ( F_13 ( & V_14 -> V_16 . V_17 -> V_28 ) ) ;
if ( F_21 ( V_28 ) ) {
F_14 ( V_2 , L_15 ) ;
goto V_47;
}
} else if ( F_13 ( V_14 -> V_44 . V_45 ) ) {
F_32 ( V_2 ) ;
goto V_47;
}
if ( V_2 -> V_5 -> V_33 & V_34 ) {
F_14 ( V_2 , L_16 ) ;
goto V_47;
}
F_34 ( & V_14 -> V_44 . V_48 ,
F_35 ( V_26 + V_49 ) ) ;
return;
V_47:
if ( V_31 )
F_36 ( V_2 -> V_5 -> V_50 , & V_2 -> V_5 -> V_51 ) ;
}
static void F_37 ( struct V_52 * V_53 )
{
struct V_30 * V_5 =
F_38 ( V_53 , struct V_30 ,
V_51 ) ;
F_29 ( V_5 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_13 ( V_2 ) ;
T_3 V_54 ;
F_40 ( & V_14 -> V_44 . V_55 ) ;
F_41 ( & V_14 -> V_44 . V_48 ) ;
V_14 -> V_44 . V_45 = NULL ;
if ( ! F_24 ( V_2 ) ) {
V_54 = F_42 ( V_2 -> V_5 -> V_6 ,
V_14 -> V_42 . V_56 ) +
V_14 -> V_42 . V_57 ;
V_14 -> V_44 . V_45 = F_43 ( V_54 , V_14 -> V_42 . V_43 * 4 ) ;
if ( ! V_14 -> V_44 . V_45 ) {
F_14 ( V_2 , L_17 ,
( unsigned long long ) V_54 ) ;
return;
}
}
V_14 -> V_44 . V_48 . V_58 = ( unsigned long ) V_2 ;
V_14 -> V_44 . V_48 . V_59 = F_33 ;
V_14 -> V_44 . V_48 . V_60 =
F_35 ( V_26 + V_49 ) ;
F_44 ( & V_14 -> V_44 . V_48 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_13 ( V_2 ) ;
F_46 ( & V_14 -> V_44 . V_48 ) ;
if ( V_14 -> V_44 . V_45 ) {
F_47 ( V_14 -> V_44 . V_45 ) ;
V_14 -> V_44 . V_45 = NULL ;
}
if ( V_2 -> V_5 -> V_38 & V_40 )
F_48 ( V_2 -> V_5 -> V_50 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
F_50 ( & V_2 -> V_5 -> V_51 , F_37 ) ;
V_2 -> V_5 -> V_50 = F_51 ( L_18 ) ;
if ( ! V_2 -> V_5 -> V_50 )
return - V_61 ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_50 ) {
F_53 ( V_2 -> V_5 -> V_50 ) ;
V_2 -> V_5 -> V_50 = NULL ;
}
}
