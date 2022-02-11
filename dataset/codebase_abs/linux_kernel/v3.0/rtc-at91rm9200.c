static void F_1 ( unsigned int V_1 , unsigned int V_2 ,
struct V_3 * V_4 )
{
unsigned int time , V_5 ;
do {
time = F_2 ( V_1 ) ;
V_5 = F_2 ( V_2 ) ;
} while ( ( time != F_2 ( V_1 ) ) ||
( V_5 != F_2 ( V_2 ) ) );
V_4 -> V_6 = F_3 ( ( time & V_7 ) >> 0 ) ;
V_4 -> V_8 = F_3 ( ( time & V_9 ) >> 8 ) ;
V_4 -> V_10 = F_3 ( ( time & V_11 ) >> 16 ) ;
V_4 -> V_12 = F_3 ( V_5 & V_13 ) * 100 ;
V_4 -> V_12 += F_3 ( ( V_5 & V_14 ) >> 8 ) ;
V_4 -> V_15 = F_3 ( ( V_5 & V_16 ) >> 21 ) - 1 ;
V_4 -> V_17 = F_3 ( ( V_5 & V_18 ) >> 16 ) - 1 ;
V_4 -> V_19 = F_3 ( ( V_5 & V_20 ) >> 24 ) ;
}
static int F_4 ( struct V_21 * V_22 , struct V_3 * V_4 )
{
F_1 ( V_23 , V_24 , V_4 ) ;
V_4 -> V_25 = F_5 ( V_4 -> V_19 , V_4 -> V_17 , V_4 -> V_12 ) ;
V_4 -> V_12 = V_4 -> V_12 - 1900 ;
F_6 ( L_1 , V_26 ,
1900 + V_4 -> V_12 , V_4 -> V_17 , V_4 -> V_19 ,
V_4 -> V_10 , V_4 -> V_8 , V_4 -> V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_21 * V_22 , struct V_3 * V_4 )
{
unsigned long V_27 ;
F_6 ( L_1 , V_26 ,
1900 + V_4 -> V_12 , V_4 -> V_17 , V_4 -> V_19 ,
V_4 -> V_10 , V_4 -> V_8 , V_4 -> V_6 ) ;
V_27 = F_2 ( V_28 ) ;
F_8 ( V_28 , V_27 | V_29 | V_30 ) ;
F_8 ( V_31 , V_32 ) ;
F_9 ( & V_33 ) ;
F_8 ( V_34 , V_32 ) ;
F_8 ( V_23 ,
F_10 ( V_4 -> V_6 ) << 0
| F_10 ( V_4 -> V_8 ) << 8
| F_10 ( V_4 -> V_10 ) << 16 ) ;
F_8 ( V_24 ,
F_10 ( ( V_4 -> V_12 + 1900 ) / 100 )
| F_10 ( V_4 -> V_12 % 100 ) << 8
| F_10 ( V_4 -> V_17 + 1 ) << 16
| F_10 ( V_4 -> V_15 + 1 ) << 21
| F_10 ( V_4 -> V_19 ) << 24 ) ;
V_27 = F_2 ( V_28 ) ;
F_8 ( V_28 , V_27 & ~ ( V_29 | V_30 ) ) ;
return 0 ;
}
static int F_11 ( struct V_21 * V_22 , struct V_35 * V_36 )
{
struct V_3 * V_4 = & V_36 -> time ;
F_1 ( V_37 , V_38 , V_4 ) ;
V_4 -> V_25 = F_5 ( V_4 -> V_19 , V_4 -> V_17 , V_4 -> V_12 ) ;
V_4 -> V_12 = V_39 - 1900 ;
V_36 -> V_40 = ( F_2 ( V_41 ) & V_42 )
? 1 : 0 ;
F_6 ( L_1 , V_26 ,
1900 + V_4 -> V_12 , V_4 -> V_17 , V_4 -> V_19 ,
V_4 -> V_10 , V_4 -> V_8 , V_4 -> V_6 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * V_22 , struct V_35 * V_36 )
{
struct V_3 V_4 ;
F_1 ( V_23 , V_24 , & V_4 ) ;
V_39 = V_4 . V_12 ;
V_4 . V_10 = V_36 -> time . V_10 ;
V_4 . V_8 = V_36 -> time . V_8 ;
V_4 . V_6 = V_36 -> time . V_6 ;
F_8 ( V_34 , V_42 ) ;
F_8 ( V_37 ,
F_10 ( V_4 . V_6 ) << 0
| F_10 ( V_4 . V_8 ) << 8
| F_10 ( V_4 . V_10 ) << 16
| V_43 | V_44 | V_45 ) ;
F_8 ( V_38 ,
F_10 ( V_4 . V_17 + 1 ) << 16
| F_10 ( V_4 . V_19 ) << 24
| V_46 | V_47 ) ;
if ( V_36 -> V_40 ) {
F_8 ( V_48 , V_42 ) ;
F_8 ( V_31 , V_42 ) ;
}
F_6 ( L_1 , V_26 ,
V_39 , V_4 . V_17 , V_4 . V_19 , V_4 . V_10 ,
V_4 . V_8 , V_4 . V_6 ) ;
return 0 ;
}
static int F_13 ( struct V_21 * V_22 , unsigned int V_40 )
{
F_6 ( L_2 , V_26 , V_40 ) ;
if ( V_40 ) {
F_8 ( V_48 , V_42 ) ;
F_8 ( V_31 , V_42 ) ;
} else
F_8 ( V_34 , V_42 ) ;
return 0 ;
}
static int F_14 ( struct V_21 * V_22 , struct V_49 * V_50 )
{
unsigned long V_51 = F_2 ( V_41 ) ;
F_15 ( V_50 , L_3 ,
( V_51 & V_32 ) ? L_4 : L_5 ) ;
F_15 ( V_50 , L_6 ,
( V_51 & V_52 ) ? L_4 : L_5 ) ;
return 0 ;
}
static T_1 F_16 ( int V_53 , void * V_54 )
{
struct V_55 * V_56 = V_54 ;
struct V_57 * V_58 = F_17 ( V_56 ) ;
unsigned int V_59 ;
unsigned long V_60 = 0 ;
V_59 = F_2 ( V_61 ) & F_2 ( V_41 ) ;
if ( V_59 ) {
if ( V_59 & V_42 )
V_60 |= ( V_62 | V_63 ) ;
if ( V_59 & V_52 )
V_60 |= ( V_64 | V_63 ) ;
if ( V_59 & V_32 )
F_18 ( & V_33 ) ;
F_8 ( V_48 , V_59 ) ;
F_19 ( V_58 , 1 , V_60 ) ;
F_6 ( L_7 , V_26 ,
V_60 >> 8 , V_60 & 0x000000FF ) ;
return V_65 ;
}
return V_66 ;
}
static int T_2 F_20 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
int V_67 ;
F_8 ( V_28 , 0 ) ;
F_8 ( V_68 , 0 ) ;
F_8 ( V_34 , V_32 | V_42 |
V_52 | V_69 |
V_70 ) ;
V_67 = F_21 ( V_71 , F_16 ,
V_72 ,
L_8 , V_56 ) ;
if ( V_67 ) {
F_22 ( V_73 L_9 ,
V_71 ) ;
return V_67 ;
}
if ( ! F_23 ( & V_56 -> V_22 ) )
F_24 ( & V_56 -> V_22 , 1 ) ;
V_58 = F_25 ( V_56 -> V_74 , & V_56 -> V_22 ,
& V_75 , V_76 ) ;
if ( F_26 ( V_58 ) ) {
F_27 ( V_71 , V_56 ) ;
return F_28 ( V_58 ) ;
}
F_29 ( V_56 , V_58 ) ;
F_22 ( V_77 L_10 ) ;
return 0 ;
}
static int T_3 F_30 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_17 ( V_56 ) ;
F_8 ( V_34 , V_32 | V_42 |
V_52 | V_69 |
V_70 ) ;
F_27 ( V_71 , V_56 ) ;
F_31 ( V_58 ) ;
F_29 ( V_56 , NULL ) ;
return 0 ;
}
static int F_32 ( struct V_21 * V_22 )
{
V_78 = F_2 ( V_41 )
& ( V_42 | V_52 ) ;
if ( V_78 ) {
if ( F_33 ( V_22 ) )
F_34 ( V_71 ) ;
else
F_8 ( V_34 , V_78 ) ;
}
return 0 ;
}
static int F_35 ( struct V_21 * V_22 )
{
if ( V_78 ) {
if ( F_33 ( V_22 ) )
F_36 ( V_71 ) ;
else
F_8 ( V_31 , V_78 ) ;
}
return 0 ;
}
static int T_2 F_37 ( void )
{
return F_38 ( & V_79 , F_20 ) ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_79 ) ;
}
