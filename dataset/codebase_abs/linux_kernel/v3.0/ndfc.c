static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_7 ;
V_4 = F_2 ( V_9 -> V_10 + V_11 ) ;
if ( V_3 >= 0 ) {
V_4 &= ~ V_12 ;
V_4 |= F_3 ( V_3 + V_9 -> V_13 ) ;
} else
V_4 |= V_14 ;
F_4 ( V_9 -> V_10 + V_11 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_15 , unsigned int V_16 )
{
struct V_5 * V_3 = V_2 -> V_7 ;
struct V_8 * V_9 = V_3 -> V_7 ;
if ( V_15 == V_17 )
return;
if ( V_16 & V_18 )
F_6 ( V_15 & 0xFF , V_9 -> V_10 + V_19 ) ;
else
F_6 ( V_15 & 0xFF , V_9 -> V_10 + V_20 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_7 ;
struct V_8 * V_9 = V_3 -> V_7 ;
return F_2 ( V_9 -> V_10 + V_21 ) & V_22 ;
}
static void F_8 ( struct V_1 * V_2 , int V_23 )
{
T_1 V_4 ;
struct V_5 * V_3 = V_2 -> V_7 ;
struct V_8 * V_9 = V_3 -> V_7 ;
V_4 = F_2 ( V_9 -> V_10 + V_11 ) ;
V_4 |= V_24 ;
F_4 ( V_9 -> V_10 + V_11 , V_4 ) ;
F_9 () ;
}
static int F_10 ( struct V_1 * V_2 ,
const T_2 * V_25 , T_2 * V_26 )
{
struct V_5 * V_3 = V_2 -> V_7 ;
struct V_8 * V_9 = V_3 -> V_7 ;
T_1 V_27 ;
T_3 * V_28 = ( T_3 * ) & V_27 ;
F_9 () ;
V_27 = F_2 ( V_9 -> V_10 + V_29 ) ;
V_26 [ 0 ] = V_28 [ 1 ] ;
V_26 [ 1 ] = V_28 [ 2 ] ;
V_26 [ 2 ] = V_28 [ 3 ] ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , T_3 * V_30 , int V_31 )
{
struct V_5 * V_3 = V_2 -> V_7 ;
struct V_8 * V_9 = V_3 -> V_7 ;
T_1 * V_28 = ( T_1 * ) V_30 ;
for(; V_31 > 0 ; V_31 -= 4 )
* V_28 ++ = F_2 ( V_9 -> V_10 + V_32 ) ;
}
static void F_12 ( struct V_1 * V_2 , const T_3 * V_30 , int V_31 )
{
struct V_5 * V_3 = V_2 -> V_7 ;
struct V_8 * V_9 = V_3 -> V_7 ;
T_1 * V_28 = ( T_1 * ) V_30 ;
for(; V_31 > 0 ; V_31 -= 4 )
F_4 ( V_9 -> V_10 + V_32 , * V_28 ++ ) ;
}
static int F_13 ( struct V_1 * V_2 , const T_3 * V_30 , int V_31 )
{
struct V_5 * V_3 = V_2 -> V_7 ;
struct V_8 * V_9 = V_3 -> V_7 ;
T_1 * V_28 = ( T_1 * ) V_30 ;
for(; V_31 > 0 ; V_31 -= 4 )
if ( * V_28 ++ != F_2 ( V_9 -> V_10 + V_32 ) )
return - V_33 ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 ,
struct V_34 * V_35 )
{
#ifdef F_15
static const char * V_36 [] = { L_1 , NULL } ;
#else
static const char * V_36 [] = { NULL } ;
#endif
struct V_34 * V_37 ;
struct V_5 * V_3 = & V_9 -> V_3 ;
int V_38 ;
V_3 -> V_39 = V_9 -> V_10 + V_32 ;
V_3 -> V_40 = V_9 -> V_10 + V_32 ;
V_3 -> V_41 = F_5 ;
V_3 -> V_42 = F_7 ;
V_3 -> V_43 = F_1 ;
V_3 -> V_44 = 50 ;
V_3 -> V_45 = & V_9 -> V_46 ;
V_3 -> V_47 = F_11 ;
V_3 -> V_48 = F_12 ;
V_3 -> V_49 = F_13 ;
V_3 -> V_27 . V_50 = V_51 ;
V_3 -> V_27 . V_52 = F_8 ;
V_3 -> V_27 . V_53 = F_10 ;
V_3 -> V_27 . V_23 = V_54 ;
V_3 -> V_27 . V_55 = 256 ;
V_3 -> V_27 . V_56 = 3 ;
V_3 -> V_7 = V_9 ;
V_9 -> V_2 . V_7 = V_3 ;
V_9 -> V_2 . V_57 = V_58 ;
V_37 = F_16 ( V_35 , NULL ) ;
if ( ! V_37 )
return - V_59 ;
V_9 -> V_2 . V_60 = F_17 ( V_61 , L_2 ,
F_18 ( & V_9 -> V_62 -> V_63 ) , V_37 -> V_60 ) ;
if ( ! V_9 -> V_2 . V_60 ) {
V_38 = - V_64 ;
goto V_65;
}
V_38 = F_19 ( & V_9 -> V_2 , 1 ) ;
if ( V_38 )
goto V_65;
V_38 = F_20 ( & V_9 -> V_2 , V_36 , & V_9 -> V_66 , 0 ) ;
if ( V_38 < 0 )
goto V_65;
if ( V_38 == 0 ) {
V_38 = F_21 ( & V_9 -> V_62 -> V_63 , V_37 ,
& V_9 -> V_66 ) ;
if ( V_38 < 0 )
goto V_65;
}
V_38 = F_22 ( & V_9 -> V_2 , V_9 -> V_66 , V_38 ) ;
V_65:
F_23 ( V_37 ) ;
if ( V_38 )
F_24 ( V_9 -> V_2 . V_60 ) ;
return V_38 ;
}
static int T_4 F_25 ( struct V_67 * V_62 )
{
struct V_8 * V_9 ;
const T_5 * V_68 ;
T_6 V_4 ;
int V_65 , V_31 , V_69 ;
V_68 = F_26 ( V_62 -> V_63 . V_70 , L_3 , & V_31 ) ;
if ( V_68 == NULL || V_31 != 12 ) {
F_27 ( & V_62 -> V_63 , L_4 , V_31 ) ;
return - V_71 ;
}
V_69 = F_28 ( V_68 [ 0 ] ) ;
if ( V_69 >= V_72 ) {
F_27 ( & V_62 -> V_63 , L_5 , V_69 ) ;
return - V_73 ;
}
V_9 = & V_74 [ V_69 ] ;
V_9 -> V_13 = V_69 ;
F_29 ( & V_9 -> V_46 . V_75 ) ;
F_30 ( & V_9 -> V_46 . V_76 ) ;
V_9 -> V_62 = V_62 ;
F_31 ( & V_62 -> V_63 , V_9 ) ;
V_9 -> V_10 = F_32 ( V_62 -> V_63 . V_70 , 0 ) ;
if ( ! V_9 -> V_10 ) {
F_27 ( & V_62 -> V_63 , L_6 ) ;
return - V_77 ;
}
V_4 = F_3 ( V_9 -> V_13 ) ;
V_68 = F_26 ( V_62 -> V_63 . V_70 , L_7 , NULL ) ;
if ( V_68 )
V_4 |= F_33 ( V_68 ) ;
F_4 ( V_9 -> V_10 + V_11 , V_4 ) ;
V_68 = F_26 ( V_62 -> V_63 . V_70 , L_8 , NULL ) ;
if ( V_68 ) {
int V_78 = V_79 + ( V_9 -> V_13 << 2 ) ;
F_4 ( V_9 -> V_10 + V_78 , F_33 ( V_68 ) ) ;
}
V_65 = F_14 ( V_9 , V_62 -> V_63 . V_70 ) ;
if ( V_65 ) {
F_34 ( V_9 -> V_10 ) ;
return V_65 ;
}
return 0 ;
}
static int T_7 F_35 ( struct V_67 * V_62 )
{
struct V_8 * V_9 = F_36 ( & V_62 -> V_63 ) ;
F_37 ( & V_9 -> V_2 ) ;
return 0 ;
}
static int T_8 F_38 ( void )
{
return F_39 ( & V_80 ) ;
}
static void T_9 F_40 ( void )
{
F_41 ( & V_80 ) ;
}
