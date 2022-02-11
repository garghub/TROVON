static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned long V_4 ;
F_2 ( V_5 -> V_6 , 0 ) ;
F_3 ( 2 ) ;
F_2 ( V_5 -> V_6 , 1 ) ;
F_3 ( 2 ) ;
V_4 = V_7 + F_4 ( 100 ) ;
do {
F_5 ( V_5 -> V_8 , V_9 , & V_3 ) ;
if ( V_3 & V_10 )
break;
F_6 ( 1000 , 2000 ) ;
} while ( ! F_7 ( V_7 , V_4 ) );
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned long V_4 ;
F_9 ( V_5 -> V_11 , L_1 ) ;
F_10 ( V_5 -> V_11 , 1 ) ;
F_3 ( 2 ) ;
F_2 ( V_5 -> V_11 , 0 ) ;
F_3 ( 2 ) ;
F_11 ( V_5 -> V_11 ) ;
V_4 = V_7 + F_4 ( 100 ) ;
do {
F_5 ( V_5 -> V_8 , V_9 , & V_3 ) ;
if ( V_3 & V_10 )
break;
F_6 ( 1000 , 2000 ) ;
} while ( ! F_7 ( V_7 , V_4 ) );
}
static unsigned short F_12 ( struct V_1 * V_12 ,
unsigned short V_13 )
{
T_1 V_3 ;
unsigned long V_4 ;
F_13 ( V_5 -> V_8 , V_14 ,
( ( ( V_13 | 0x80 ) << V_15 ) &
V_16 ) |
V_17 ) ;
V_4 = V_7 + F_4 ( 100 ) ;
do {
F_5 ( V_5 -> V_8 , V_9 , & V_3 ) ;
if ( V_3 & V_18 )
break;
F_6 ( 1000 , 2000 ) ;
} while ( ! F_7 ( V_7 , V_4 ) );
return ( ( V_3 & V_19 ) >>
V_20 ) ;
}
static void F_14 ( struct V_1 * V_12 ,
unsigned short V_13 , unsigned short V_21 )
{
T_1 V_3 ;
unsigned long V_4 ;
F_13 ( V_5 -> V_8 , V_14 ,
( ( V_13 << V_15 ) &
V_16 ) |
( ( V_21 << V_22 ) &
V_23 ) |
V_17 ) ;
V_4 = V_7 + F_4 ( 100 ) ;
do {
F_5 ( V_5 -> V_8 , V_14 , & V_3 ) ;
if ( ! ( V_3 & V_17 ) )
break;
F_6 ( 1000 , 2000 ) ;
} while ( ! F_7 ( V_7 , V_4 ) );
}
static inline void F_15 ( struct V_24 * V_2 )
{
F_16 ( V_2 -> V_8 , V_25 ,
V_26 ,
V_26 ) ;
F_16 ( V_2 -> V_8 , V_27 ,
V_28 |
V_29 ,
V_28 |
V_29 ) ;
}
static inline void F_17 ( struct V_24 * V_2 )
{
F_16 ( V_2 -> V_8 , V_25 ,
V_26 , 0 ) ;
F_16 ( V_2 -> V_8 , V_27 ,
V_28 , 0 ) ;
}
static inline void F_18 ( struct V_24 * V_2 )
{
F_16 ( V_2 -> V_8 , V_25 ,
V_30 ,
V_30 ) ;
}
static inline void F_19 ( struct V_24 * V_2 )
{
F_16 ( V_2 -> V_8 , V_25 ,
V_30 , 0 ) ;
}
static int F_20 ( struct V_31 * V_32 , int V_33 ,
struct V_34 * V_35 )
{
struct V_24 * V_2 = F_21 ( V_35 ) ;
switch ( V_33 ) {
case V_36 :
case V_37 :
case V_38 :
if ( V_32 -> V_39 == V_40 )
F_15 ( V_2 ) ;
else
F_18 ( V_2 ) ;
break;
case V_41 :
case V_42 :
case V_43 :
if ( V_32 -> V_39 == V_40 )
F_17 ( V_2 ) ;
else
F_19 ( V_2 ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static int F_22 ( struct V_34 * V_35 )
{
struct V_24 * V_2 = F_21 ( V_35 ) ;
V_35 -> V_45 = & V_2 -> V_45 ;
V_35 -> V_46 = & V_2 -> V_46 ;
return 0 ;
}
static bool F_23 ( struct V_47 * V_48 , unsigned int V_13 )
{
switch ( V_13 ) {
case V_27 :
case V_14 :
case V_9 :
case V_25 :
case V_49 :
case V_50 :
return true ;
default:
break;
}
return false ;
}
static bool F_24 ( struct V_47 * V_48 , unsigned int V_13 )
{
switch ( V_13 ) {
case V_9 :
case V_25 :
case V_49 :
case V_50 :
return true ;
default:
break;
}
return false ;
}
static bool F_25 ( struct V_47 * V_48 , unsigned int V_13 )
{
switch ( V_13 ) {
case V_49 :
case V_50 :
return true ;
default:
break;
}
return false ;
}
static int F_26 ( struct V_51 * V_52 )
{
struct V_24 * V_2 ;
struct V_53 * V_54 ;
T_1 V_55 [ 2 ] ;
void T_2 * V_56 ;
int V_57 = 0 ;
V_2 = F_27 ( & V_52 -> V_48 , sizeof( struct V_24 ) ,
V_58 ) ;
if ( ! V_2 ) {
F_28 ( & V_52 -> V_48 , L_2 ) ;
V_57 = - V_59 ;
goto V_60;
}
F_29 ( & V_52 -> V_48 , V_2 ) ;
V_2 -> V_61 = F_30 ( & V_52 -> V_48 , NULL ) ;
if ( F_31 ( V_2 -> V_61 ) ) {
F_28 ( & V_52 -> V_48 , L_3 ) ;
V_57 = F_32 ( V_2 -> V_61 ) ;
goto V_60;
}
V_54 = F_33 ( V_52 , V_62 , 0 ) ;
if ( ! V_54 ) {
F_28 ( & V_52 -> V_48 , L_4 ) ;
V_57 = - V_63 ;
goto V_64;
}
V_56 = F_34 ( & V_52 -> V_48 , V_54 ) ;
if ( F_31 ( V_56 ) ) {
V_57 = F_32 ( V_56 ) ;
goto V_64;
}
V_2 -> V_8 = F_35 ( & V_52 -> V_48 , V_56 ,
& V_65 ) ;
if ( F_31 ( V_2 -> V_8 ) ) {
F_28 ( & V_52 -> V_48 , L_5 ) ;
V_57 = F_32 ( V_2 -> V_8 ) ;
goto V_64;
}
if ( F_36 ( V_52 -> V_48 . V_66 ,
L_6 ,
V_55 , 2 ) < 0 ) {
F_28 ( & V_52 -> V_48 , L_7 ) ;
V_57 = - V_63 ;
goto V_64;
}
V_2 -> V_6 = F_37 ( V_52 -> V_48 . V_66 ,
L_8 , 0 ) ;
if ( F_38 ( V_2 -> V_6 ) ) {
V_57 = F_39 ( & V_52 -> V_48 , V_2 -> V_6 ,
V_67 , L_9 ) ;
if ( V_57 ) {
F_28 ( & V_52 -> V_48 , L_10 ) ;
goto V_64;
}
} else {
F_28 ( & V_52 -> V_48 , L_11 ) ;
goto V_64;
}
V_2 -> V_11 = F_37 ( V_52 -> V_48 . V_66 ,
L_12 , 0 ) ;
if ( ! F_38 ( V_2 -> V_11 ) ) {
F_28 ( & V_52 -> V_48 , L_13 ) ;
goto V_64;
}
V_2 -> V_45 . V_68 = V_54 -> V_69 + V_50 ;
V_2 -> V_45 . V_70 = V_71 ;
V_2 -> V_45 . V_72 = 4 ;
V_2 -> V_45 . V_73 = V_55 [ 1 ] ;
V_2 -> V_46 . V_68 = V_54 -> V_69 + V_49 ;
V_2 -> V_46 . V_70 = V_71 ;
V_2 -> V_46 . V_72 = 4 ;
V_2 -> V_46 . V_73 = V_55 [ 1 ] ;
V_57 = F_40 ( & V_2 -> V_74 , & V_52 -> V_48 ) ;
if ( V_57 )
goto V_64;
V_57 = F_41 ( & V_2 -> V_74 ) ;
if ( V_57 )
goto V_75;
V_57 = F_42 ( V_2 -> V_61 ) ;
if ( V_57 ) {
F_28 ( & V_52 -> V_48 , L_14 , V_57 ) ;
goto V_75;
}
V_57 = F_43 ( & V_76 ) ;
if ( V_57 ) {
F_28 ( & V_52 -> V_48 , L_15 , V_57 ) ;
goto V_75;
}
V_57 = F_44 ( & V_52 -> V_48 , & V_77 ,
& V_78 , 1 ) ;
if ( V_57 ) {
F_28 ( & V_52 -> V_48 , L_16 , V_57 ) ;
V_57 = - V_59 ;
goto V_75;
}
V_57 = F_45 ( & V_52 -> V_48 ) ;
if ( V_57 ) {
F_28 ( & V_52 -> V_48 , L_17 , V_57 ) ;
goto V_79;
}
V_5 = V_2 ;
return 0 ;
V_80:
F_46 ( & V_52 -> V_48 ) ;
V_79:
F_47 ( & V_52 -> V_48 ) ;
V_75:
F_48 ( & V_2 -> V_74 ) ;
V_64:
V_60:
F_43 ( NULL ) ;
return V_57 ;
}
static int F_49 ( struct V_51 * V_52 )
{
struct V_24 * V_2 = F_50 ( & V_52 -> V_48 ) ;
F_46 ( & V_52 -> V_48 ) ;
F_47 ( & V_52 -> V_48 ) ;
F_48 ( & V_2 -> V_74 ) ;
F_51 ( V_2 -> V_61 ) ;
F_43 ( NULL ) ;
return 0 ;
}
