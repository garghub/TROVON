static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( & V_2 -> V_4 [ V_3 ] ) & 0xff ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , int V_3 )
{
F_4 ( V_5 , & V_2 -> V_4 [ V_3 ] ) ;
}
static int F_5 ( struct V_6 * V_7 , unsigned int V_8 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_9 ;
unsigned char V_10 ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
V_10 = F_1 ( V_2 , V_12 ) ;
if ( V_8 )
V_10 &= ~ V_13 ;
else
V_10 |= V_13 ;
F_3 ( V_2 , V_10 , V_12 ) ;
F_8 ( & V_2 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 , unsigned int V_14 , unsigned long V_15 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_9 ;
unsigned char V_10 ;
switch ( V_14 ) {
case V_16 :
F_7 ( & V_2 -> V_11 , V_9 ) ;
V_10 = F_1 ( V_2 , V_12 ) ;
V_10 |= V_17 ;
F_3 ( V_2 , V_10 , V_12 ) ;
F_8 ( & V_2 -> V_11 , V_9 ) ;
break;
case V_18 :
F_7 ( & V_2 -> V_11 , V_9 ) ;
V_10 = F_1 ( V_2 , V_12 ) ;
V_10 &= ~ V_17 ;
F_3 ( V_2 , V_10 , V_12 ) ;
F_8 ( & V_2 -> V_11 , V_9 ) ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned char V_22 , V_14 , V_23 ;
const char * V_24 ;
V_22 = F_1 ( V_2 , V_25 ) ;
F_11 ( V_21 ,
L_1
L_2 ,
( V_22 & V_26 ) ? L_3 : L_4 ,
( V_22 & V_27 ) ? L_3 : L_4 ) ;
V_23 = ( ( F_1 ( V_2 , V_28 ) & 0x80 ) >> 5 ) |
( ( F_1 ( V_2 , V_29 ) & 0x80 ) >> 6 ) |
( ( F_1 ( V_2 , V_30 ) & 0x80 ) >> 7 ) ;
switch ( V_23 ) {
case 7 :
V_24 = L_5 ;
break;
case 3 :
V_24 = L_6 ;
break;
case 1 :
V_24 = L_7 ;
break;
case 0 :
V_24 = L_8 ;
break;
default:
V_24 = L_9 ;
break;
}
F_11 ( V_21 , L_10 , V_24 ) ;
V_14 = F_1 ( V_2 , V_12 ) ;
F_11 ( V_21 ,
L_11
L_12
L_13
L_14
L_15
L_16
L_17 ,
( V_14 & V_31 ) ? L_18 : L_19 ,
( V_14 & V_32 ) ? L_18 : L_19 ,
( V_14 & V_13 ) ? L_3 : L_4 ,
( V_14 & V_17 ) ? L_3 : L_4 ,
( V_14 & V_33 ) ? L_20 : L_21 ,
( V_14 & V_34 ) ? L_22 : L_23 ,
( V_14 & V_35 ) ? L_24 : L_25 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned char V_38 ;
unsigned long V_9 ;
unsigned long V_39 = V_40 ;
if ( F_1 ( V_2 , V_12 ) & V_41 )
while ( F_13 ( V_40 , V_39 + 2 * V_42 / 100 ) )
F_14 () ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
V_38 = F_1 ( V_2 , V_12 ) ;
F_3 ( V_2 , ( V_38 | V_41 ) , V_12 ) ;
V_37 -> V_43 = F_1 ( V_2 , V_44 ) ;
V_37 -> V_45 = F_1 ( V_2 , V_46 ) ;
V_37 -> V_47 = F_1 ( V_2 , V_48 ) & 0x3f ;
V_37 -> V_49 = F_1 ( V_2 , V_50 ) ;
V_37 -> V_51 = F_1 ( V_2 , V_25 ) & 0x1f ;
V_37 -> V_52 = F_1 ( V_2 , V_53 ) ;
F_3 ( V_2 , V_38 , V_12 ) ;
F_8 ( & V_2 -> V_11 , V_9 ) ;
V_37 -> V_43 = F_15 ( V_37 -> V_43 ) ;
V_37 -> V_45 = F_15 ( V_37 -> V_45 ) ;
V_37 -> V_47 = F_15 ( V_37 -> V_47 ) ;
V_37 -> V_49 = F_15 ( V_37 -> V_49 ) ;
V_37 -> V_51 = F_15 ( V_37 -> V_51 ) ;
V_37 -> V_52 = F_15 ( V_37 -> V_52 ) ;
if ( V_37 -> V_52 < 45 )
V_37 -> V_52 += 30 ;
V_37 -> V_52 += 40 ;
if ( V_37 -> V_52 < 70 )
V_37 -> V_52 += 100 ;
V_37 -> V_51 -- ;
return F_16 ( V_37 ) ;
}
static int F_17 ( struct V_6 * V_7 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned char V_54 , V_55 , V_56 , V_57 , V_58 ;
unsigned char V_38 ;
unsigned int V_59 ;
unsigned long V_9 ;
V_59 = V_37 -> V_52 + 1900 ;
V_54 = V_37 -> V_51 + 1 ;
V_55 = V_37 -> V_49 ;
V_56 = V_37 -> V_47 ;
V_57 = V_37 -> V_45 ;
V_58 = V_37 -> V_43 ;
if ( V_59 < 1970 )
return - V_60 ;
V_59 -= 1940 ;
if ( V_59 > 255 )
return - V_60 ;
if ( V_59 >= 100 )
V_59 -= 100 ;
V_58 = F_18 ( V_58 ) ;
V_57 = F_18 ( V_57 ) ;
V_56 = F_18 ( V_56 ) ;
V_55 = F_18 ( V_55 ) ;
V_54 = F_18 ( V_54 ) ;
V_59 = F_18 ( V_59 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
V_38 = F_1 ( V_2 , V_12 ) ;
F_3 ( V_2 , ( V_38 | V_41 ) , V_12 ) ;
F_3 ( V_2 , V_59 , V_53 ) ;
F_3 ( V_2 , V_54 , V_25 ) ;
F_3 ( V_2 , V_55 , V_50 ) ;
F_3 ( V_2 , V_56 , V_48 ) ;
F_3 ( V_2 , V_57 , V_46 ) ;
F_3 ( V_2 , V_58 , V_44 ) ;
F_3 ( V_2 , 0 , V_61 ) ;
F_3 ( V_2 , V_38 , V_12 ) ;
F_8 ( & V_2 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 , struct V_62 * V_63 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned char V_14 ;
unsigned long V_9 ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
V_63 -> time . V_45 = F_1 ( V_2 , V_28 ) & 0x7f ;
V_63 -> time . V_47 = F_1 ( V_2 , V_29 ) & 0x1f ;
V_63 -> time . V_64 = F_1 ( V_2 , V_30 ) & 0x07 ;
V_14 = F_1 ( V_2 , V_12 ) ;
F_8 ( & V_2 -> V_11 , V_9 ) ;
V_63 -> time . V_45 = F_15 ( V_63 -> time . V_45 ) ;
V_63 -> time . V_47 = F_15 ( V_63 -> time . V_47 ) ;
V_63 -> time . V_43 = 0 ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 , struct V_62 * V_63 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned char V_56 , V_57 , V_58 ;
V_56 = V_63 -> time . V_47 ;
V_57 = V_63 -> time . V_45 ;
V_58 = V_63 -> time . V_43 ;
if ( V_56 >= 24 )
V_56 = 0xff ;
if ( V_57 >= 60 )
V_57 = 0xff ;
if ( V_58 != 0 )
return - V_60 ;
V_57 = F_18 ( V_57 ) ;
V_56 = F_18 ( V_56 ) ;
F_21 ( & V_2 -> V_11 ) ;
F_3 ( V_2 , V_56 , V_29 ) ;
F_3 ( V_2 , V_57 , V_28 ) ;
F_22 ( & V_2 -> V_11 ) ;
return 0 ;
}
static int T_2 F_23 ( struct V_65 * V_66 )
{
struct V_67 * V_68 ;
struct V_69 * V_70 ;
struct V_1 * V_2 ;
int V_71 = 0 ;
V_70 = F_24 ( V_66 , V_72 , 0 ) ;
if ( ! V_70 )
return - V_73 ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_74 ) ;
if ( ! V_2 )
return - V_75 ;
V_2 -> V_76 = F_26 ( V_70 ) ;
if ( ! F_27 ( V_70 -> V_77 , V_2 -> V_76 , V_66 -> V_78 ) ) {
V_71 = - V_79 ;
goto V_80;
}
V_2 -> V_81 = V_70 -> V_77 ;
V_2 -> V_4 = F_28 ( V_2 -> V_81 , V_2 -> V_76 ) ;
if ( ! V_2 -> V_4 ) {
V_71 = - V_75 ;
goto V_80;
}
F_29 ( & V_2 -> V_11 ) ;
F_30 ( V_66 , V_2 ) ;
V_68 = F_31 ( L_26 , & V_66 -> V_7 ,
& V_82 , V_83 ) ;
if ( F_32 ( V_68 ) ) {
V_71 = F_33 ( V_68 ) ;
goto V_80;
}
V_2 -> V_68 = V_68 ;
return 0 ;
V_80:
if ( V_2 -> V_68 )
F_34 ( V_2 -> V_68 ) ;
if ( V_2 -> V_4 )
F_35 ( V_2 -> V_4 ) ;
if ( V_2 -> V_81 )
F_36 ( V_2 -> V_81 , V_2 -> V_76 ) ;
F_37 ( V_2 ) ;
return V_71 ;
}
static int T_3 F_38 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_39 ( V_66 ) ;
F_34 ( V_2 -> V_68 ) ;
F_35 ( V_2 -> V_4 ) ;
F_36 ( V_2 -> V_81 , V_2 -> V_76 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_84 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_84 ) ;
}
