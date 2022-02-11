static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_5 -> V_6 [ V_5 -> V_7 ] ) )
return 1 ;
F_5 ( V_5 -> V_8 , L_1 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_5 )
{
if ( V_5 -> V_6 [ V_5 -> V_7 ] >= 0 ) {
int V_9 = 1000000 ;
while ( -- V_9 && ! F_3 ( & V_5 -> V_4 ) )
F_7 () ;
if ( ! V_9 )
F_8 ( V_5 -> V_8 , L_2 ) ;
} else {
F_9 ( 100 ) ;
}
}
static void F_10 ( struct V_2 * V_4 , int V_10 , unsigned int V_11 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_1 V_15 ;
if ( ! ( V_11 & V_5 -> V_16 ) ) {
F_11 ( & V_5 -> V_17 ) ;
if ( V_10 == V_18 )
return;
V_5 -> V_16 = V_11 & ( V_19 | V_20 ) ;
}
if ( V_11 & V_21 ) {
if ( V_11 & V_19 )
F_12 ( & V_5 -> V_17 , V_5 -> V_22 ) ;
else if ( V_11 & V_20 )
F_12 ( & V_5 -> V_17 , V_5 -> V_23 ) ;
}
V_15 = ( V_10 << ( 32 - V_5 -> V_17 . V_24 ) ) |
V_5 -> V_25 [ V_5 -> V_7 ] ;
F_13 ( & V_5 -> V_17 , V_13 -> V_26 , V_15 ) ;
if ( V_5 -> V_27 & V_28 )
F_6 ( V_5 ) ;
}
static void F_14 ( struct V_2 * V_4 , int V_29 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_29 == - 1 ) {
V_13 -> V_30 ( V_4 , V_18 , 0 | V_21 ) ;
} else if ( V_29 >= 0 && V_29 < V_31 ) {
V_5 -> V_7 = V_29 ;
V_13 -> V_26 = V_5 -> V_32 + V_5 -> V_25 [ V_29 ] ;
V_13 -> V_33 = V_13 -> V_26 ;
} else {
F_15 () ;
}
}
static T_2 F_16 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
return F_17 ( V_5 -> V_13 . V_26 ) ;
}
static void F_18 ( struct V_2 * V_4 , T_2 * V_34 , int V_35 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ )
V_34 [ V_36 ] = F_17 ( V_5 -> V_13 . V_26 ) ;
}
static void F_19 ( struct V_2 * V_4 , const T_2 * V_34 , int V_35 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ ) {
F_20 ( V_5 -> V_13 . V_33 , V_34 [ V_36 ] ) ;
if ( V_5 -> V_27 & V_37 )
F_6 ( V_5 ) ;
}
if ( V_5 -> V_27 & V_38 )
F_6 ( V_5 ) ;
}
static int T_3 F_21 ( struct V_1 * V_5 ,
const struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
int V_43 ;
struct V_39 * V_44 ;
static const char * V_45 [] = { L_3 , NULL , } ;
V_5 -> V_13 . V_26 = V_5 -> V_32 ;
V_5 -> V_13 . V_33 = V_5 -> V_32 ;
V_5 -> V_13 . V_30 = F_10 ;
V_5 -> V_13 . V_46 = V_5 -> V_46 ;
V_5 -> V_13 . V_47 = F_16 ;
V_5 -> V_13 . V_48 = F_18 ;
V_5 -> V_13 . V_49 = F_19 ;
V_5 -> V_13 . V_50 . V_51 = V_52 ;
if ( V_5 -> V_53 > 1 )
V_5 -> V_13 . V_54 = F_14 ;
if ( V_5 -> V_6 [ 0 ] >= 0 )
V_5 -> V_13 . V_55 = F_3 ;
V_5 -> V_4 . V_14 = & V_5 -> V_13 ;
V_5 -> V_4 . V_56 = V_57 ;
V_44 = F_22 ( V_40 , NULL ) ;
if ( ! V_44 )
return - V_58 ;
V_5 -> V_4 . V_59 = F_23 ( V_60 , L_4 , ( V_61 ) V_42 -> V_62 ,
V_44 -> V_59 ) ;
if ( ! V_5 -> V_4 . V_59 ) {
V_43 = - V_63 ;
goto V_64;
}
V_43 = F_24 ( & V_5 -> V_4 , V_5 -> V_53 ) ;
if ( V_43 )
goto V_64;
V_43 = F_25 ( & V_5 -> V_4 , V_45 , & V_5 -> V_65 , 0 ) ;
#ifdef F_26
if ( V_43 == 0 ) {
V_43 = F_27 ( V_5 -> V_8 , V_44 , & V_5 -> V_65 ) ;
if ( V_43 < 0 )
goto V_64;
}
#endif
V_43 = F_28 ( & V_5 -> V_4 , V_5 -> V_65 , V_43 ) ;
V_64:
F_29 ( V_44 ) ;
return V_43 ;
}
static int T_3 F_30 ( struct V_66 * V_67 )
{
struct V_1 * V_5 ;
struct V_41 V_42 ;
const T_4 * V_68 ;
int V_6 ;
int V_43 ;
int V_69 ;
int V_36 ;
V_5 = F_31 ( sizeof( * V_5 ) , V_60 ) ;
if ( ! V_5 )
return - V_63 ;
V_43 = F_32 ( V_67 -> V_8 . V_70 , 0 , & V_42 ) ;
if ( V_43 ) {
F_8 ( & V_67 -> V_8 , L_5 ) ;
goto V_71;
}
V_43 = F_33 ( V_42 . V_62 , & V_5 -> V_17 ) ;
if ( V_43 ) {
F_8 ( & V_67 -> V_8 , L_6 ) ;
goto V_71;
}
V_68 = F_34 ( V_67 -> V_8 . V_70 , L_7 ,
& V_69 ) ;
if ( ! V_68 || V_69 != sizeof( V_72 ) ) {
F_8 ( & V_67 -> V_8 , L_8 ) ;
V_43 = - V_73 ;
goto V_71;
}
V_5 -> V_22 = * V_68 ;
V_68 = F_34 ( V_67 -> V_8 . V_70 , L_9 , & V_69 ) ;
if ( ! V_68 || V_69 != sizeof( V_72 ) ) {
F_8 ( & V_67 -> V_8 , L_10 ) ;
V_43 = - V_73 ;
goto V_71;
}
V_5 -> V_23 = * V_68 ;
V_68 = F_34 ( V_67 -> V_8 . V_70 ,
L_11 , & V_69 ) ;
if ( V_68 && ( V_69 / sizeof( V_72 ) ) > 0 ) {
V_5 -> V_53 = V_69 / sizeof( V_72 ) ;
if ( V_5 -> V_53 >= V_31 ) {
F_8 ( & V_67 -> V_8 , L_12 ) ;
goto V_71;
}
for ( V_36 = 0 ; V_36 < V_5 -> V_53 ; V_36 ++ )
V_5 -> V_25 [ V_36 ] = F_35 ( V_68 [ V_36 ] ) ;
} else {
V_5 -> V_53 = 1 ;
}
for ( V_36 = 0 ; V_36 < V_5 -> V_53 ; V_36 ++ ) {
V_5 -> V_6 [ V_36 ] = - 1 ;
V_6 = F_36 ( V_67 -> V_8 . V_70 , V_36 ) ;
if ( V_6 >= 0 ) {
V_43 = F_37 ( V_6 , F_38 ( & V_67 -> V_8 ) ) ;
if ( V_43 ) {
F_8 ( & V_67 -> V_8 ,
L_13 , V_36 ) ;
goto V_74;
}
F_39 ( V_6 ) ;
V_5 -> V_6 [ V_36 ] = V_6 ;
} else if ( V_6 == - V_73 ) {
F_8 ( & V_67 -> V_8 , L_14 , V_36 ) ;
goto V_74;
}
}
V_68 = F_34 ( V_67 -> V_8 . V_70 , L_15 , NULL ) ;
if ( V_68 )
V_5 -> V_46 = F_40 ( V_68 ) ;
else
V_5 -> V_46 = 50 ;
V_68 = F_34 ( V_67 -> V_8 . V_70 , L_16 , & V_69 ) ;
if ( V_68 && V_69 == sizeof( V_72 ) )
V_5 -> V_27 = F_40 ( V_68 ) ;
else
V_5 -> V_27 = V_28 |
V_37 ;
V_5 -> V_32 = F_41 ( & V_67 -> V_8 , V_42 . V_62 ,
F_42 ( & V_42 ) ) ;
if ( ! V_5 -> V_32 ) {
V_43 = - V_63 ;
goto V_74;
}
V_5 -> V_8 = & V_67 -> V_8 ;
V_5 -> V_16 = V_20 ;
V_43 = F_21 ( V_5 , V_67 -> V_8 . V_70 , & V_42 ) ;
if ( V_43 )
goto V_74;
F_43 ( & V_67 -> V_8 , V_5 ) ;
return 0 ;
V_74:
for ( V_36 = 0 ; V_36 < V_5 -> V_53 ; V_36 ++ ) {
if ( V_5 -> V_6 [ V_36 ] < 0 )
break;
F_44 ( V_5 -> V_6 [ V_36 ] ) ;
}
V_71:
F_45 ( V_5 ) ;
return V_43 ;
}
static int T_5 F_46 ( struct V_66 * V_67 )
{
struct V_1 * V_5 = F_47 ( & V_67 -> V_8 ) ;
int V_36 ;
F_48 ( & V_5 -> V_4 ) ;
F_45 ( V_5 -> V_4 . V_59 ) ;
for ( V_36 = 0 ; V_36 < V_5 -> V_53 ; V_36 ++ ) {
if ( V_5 -> V_6 [ V_36 ] < 0 )
break;
F_44 ( V_5 -> V_6 [ V_36 ] ) ;
}
F_45 ( V_5 ) ;
return 0 ;
}
static int T_6 F_49 ( void )
{
return F_50 ( & V_75 ) ;
}
static void T_7 F_51 ( void )
{
F_52 ( & V_75 ) ;
}
