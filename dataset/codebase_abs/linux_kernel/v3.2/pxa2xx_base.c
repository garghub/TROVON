static inline T_1 F_1 ( T_1 V_1 ,
T_1 V_2 )
{
T_1 V_3 = V_1 * V_2 ;
return ( V_3 / 300000 ) + ( ( V_3 % 300000 ) ? 1 : 0 ) - 1 ;
}
static inline T_1 F_2 ( T_1 V_1 ,
T_1 V_2 )
{
T_1 V_3 = V_1 * V_2 ;
return ( V_3 / 300000 ) + ( ( V_3 % 300000 ) ? 1 : 0 ) + 1 ;
}
static inline T_1 F_3 ( T_1 V_1 ,
T_1 V_2 )
{
T_1 V_3 = V_1 * V_2 ;
return ( V_3 / 100000 ) + ( ( V_3 % 100000 ) ? 1 : 0 ) - 1 ;
}
static inline T_1 F_4 ( T_1 V_2 ,
T_1 V_4 )
{
return ( 300000 * ( V_4 + 1 ) / V_2 ) ;
}
static int F_5 ( int V_5 , int V_6 , int clock )
{
T_2 V_7 ;
V_7 = ( ( F_3 ( V_6 , clock )
& V_8 ) << V_9 )
| ( ( F_2 ( V_6 , clock )
& V_10 ) << V_11 )
| ( ( F_1 ( V_6 , clock )
& V_12 ) << V_13 ) ;
F_6 ( V_7 , F_7 ( V_5 ) ) ;
return 0 ;
}
static int F_8 ( int V_5 , int V_6 , int clock )
{
T_2 V_7 ;
V_7 = ( ( F_3 ( V_6 , clock )
& V_8 ) << V_9 )
| ( ( F_2 ( V_6 , clock )
& V_10 ) << V_11 )
| ( ( F_1 ( V_6 , clock )
& V_12 ) << V_13 ) ;
F_6 ( V_7 , F_9 ( V_5 ) ) ;
return 0 ;
}
static int F_10 ( int V_5 , int V_6 , int clock )
{
T_2 V_7 ;
V_7 = ( ( F_3 ( V_6 , clock )
& V_8 ) << V_9 )
| ( ( F_2 ( V_6 , clock )
& V_10 ) << V_11 )
| ( ( F_1 ( V_6 , clock )
& V_12 ) << V_13 ) ;
F_6 ( V_7 , F_11 ( V_5 ) ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 , unsigned int V_16 )
{
struct V_17 V_18 ;
int V_5 = V_15 -> V_19 ;
F_13 ( V_15 , & V_18 ) ;
F_5 ( V_5 , V_18 . V_20 , V_16 ) ;
F_10 ( V_5 , V_18 . V_21 , V_16 ) ;
F_8 ( V_5 , V_18 . V_22 , V_16 ) ;
return 0 ;
}
static int F_14 ( struct V_14 * V_15 )
{
unsigned long V_16 = F_15 ( V_15 -> V_16 ) ;
return F_12 ( V_15 , V_16 / 10000 ) ;
}
static int
F_16 ( struct V_14 * V_15 ,
unsigned long V_7 ,
struct V_23 * V_24 )
{
switch ( V_7 ) {
case V_25 :
if ( V_24 -> V_26 > V_24 -> V_27 ) {
F_17 ( V_15 , 2 , L_1
L_2 ,
V_24 -> V_26 / 1000 , ( V_24 -> V_26 / 100 ) % 10 ,
V_24 -> V_27 / 1000 , ( V_24 -> V_27 / 100 ) % 10 ) ;
F_14 ( V_15 ) ;
}
break;
case V_28 :
if ( V_24 -> V_26 < V_24 -> V_27 ) {
F_17 ( V_15 , 2 , L_3
L_4 ,
V_24 -> V_26 / 1000 , ( V_24 -> V_26 / 100 ) % 10 ,
V_24 -> V_27 / 1000 , ( V_24 -> V_27 / 100 ) % 10 ) ;
F_14 ( V_15 ) ;
}
break;
}
return 0 ;
}
void F_18 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
T_2 V_34 = V_35 ;
if ( ( V_32 -> V_36 + V_32 -> V_19 ) > 1 ||
F_19 () || F_20 () )
V_34 |= V_37 ;
F_6 ( V_34 , V_38 ) ;
}
int F_21 ( struct V_14 * V_15 )
{
V_15 -> V_39 . V_40 = F_22 ( V_15 -> V_19 ) ;
V_15 -> V_39 . V_41 = F_22 ( V_15 -> V_19 ) + V_42 - 1 ;
V_15 -> V_39 . V_43 = V_44 [ V_15 -> V_19 ] ;
V_15 -> V_39 . V_45 = V_46 ;
V_15 -> V_47 . V_40 = F_23 ( V_15 -> V_19 ) ;
V_15 -> V_47 . V_41 = F_23 ( V_15 -> V_19 ) + V_48 - 1 ;
V_15 -> V_47 . V_43 = L_5 ;
V_15 -> V_47 . V_45 = V_46 | V_49 ;
V_15 -> V_50 . V_40 = F_24 ( V_15 -> V_19 ) ;
V_15 -> V_50 . V_41 = F_24 ( V_15 -> V_19 ) + V_51 - 1 ;
V_15 -> V_50 . V_43 = L_6 ;
V_15 -> V_50 . V_45 = V_46 ;
V_15 -> V_52 . V_40 = F_25 ( V_15 -> V_19 ) ;
V_15 -> V_52 . V_41 = F_25 ( V_15 -> V_19 ) + V_53 - 1 ;
V_15 -> V_52 . V_43 = L_7 ;
V_15 -> V_52 . V_45 = V_46 ;
return F_26 ( V_15 ) ;
}
void F_27 ( struct V_31 * V_32 )
{
V_32 -> V_54 = F_14 ;
#ifdef F_28
V_32 -> V_55 = F_16 ;
#endif
}
static int F_29 ( struct V_56 * V_30 )
{
int V_57 , V_58 = 0 ;
struct V_31 * V_32 ;
struct V_59 * V_60 ;
struct V_14 * V_15 ;
struct V_16 * V_16 ;
V_32 = (struct V_31 * ) V_30 -> V_30 . V_33 ;
if ( ! V_32 ) {
V_58 = - V_61 ;
goto V_62;
}
if ( F_30 () && V_32 -> V_19 > 1 ) {
F_31 ( & V_30 -> V_30 , L_8 ) ;
V_58 = - V_63 ;
goto V_62;
}
V_16 = F_32 ( & V_30 -> V_30 , NULL ) ;
if ( ! V_16 )
return - V_61 ;
F_27 ( V_32 ) ;
V_60 = F_33 ( F_34 ( V_32 -> V_19 ) , V_64 ) ;
if ( ! V_60 ) {
F_35 ( V_16 ) ;
return - V_65 ;
}
V_60 -> V_66 = V_32 -> V_19 ;
V_60 -> V_16 = V_16 ;
for ( V_57 = 0 ; V_57 < V_32 -> V_19 ; V_57 ++ ) {
V_15 = & V_60 -> V_15 [ V_57 ] ;
V_15 -> V_19 = V_32 -> V_36 + V_57 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_32 = V_32 ;
V_15 -> V_67 . V_68 = V_32 -> V_68 ;
V_15 -> V_67 . V_30 . V_69 = & V_30 -> V_30 ;
V_15 -> V_67 . V_70 = V_71 ;
V_58 = F_21 ( V_15 ) ;
if ( V_58 )
goto V_72;
}
if ( V_58 ) {
while ( -- V_57 >= 0 )
F_36 ( & V_60 -> V_15 [ V_57 ] ) ;
F_37 ( V_60 ) ;
F_35 ( V_16 ) ;
} else {
F_18 ( & V_30 -> V_30 ) ;
F_38 ( & V_30 -> V_30 , V_60 ) ;
}
return 0 ;
V_72:
while ( -- V_57 >= 0 )
F_36 ( & V_60 -> V_15 [ V_57 ] ) ;
F_37 ( V_60 ) ;
V_62:
return V_58 ;
}
static int F_39 ( struct V_56 * V_30 )
{
struct V_59 * V_60 = F_40 ( V_30 ) ;
int V_57 ;
F_41 ( V_30 , NULL ) ;
for ( V_57 = 0 ; V_57 < V_60 -> V_66 ; V_57 ++ )
F_36 ( & V_60 -> V_15 [ V_57 ] ) ;
F_35 ( V_60 -> V_16 ) ;
F_37 ( V_60 ) ;
return 0 ;
}
static int F_42 ( struct V_29 * V_30 )
{
F_18 ( V_30 ) ;
return 0 ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_73 ) ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_73 ) ;
}
