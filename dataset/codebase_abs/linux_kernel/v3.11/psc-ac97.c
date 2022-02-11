static unsigned short F_1 ( struct V_1 * V_2 ,
unsigned short V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned short V_6 , V_7 ;
unsigned long V_8 ;
F_3 ( V_9 , F_4 ( V_5 ) ) ;
F_5 () ;
V_6 = V_10 ;
do {
F_6 ( & V_5 -> V_11 ) ;
F_3 ( V_12 | F_7 ( V_3 ) ,
F_8 ( V_5 ) ) ;
F_5 () ;
V_7 = 20 ;
do {
F_9 ( 21 ) ;
if ( F_10 ( F_4 ( V_5 ) ) & V_9 )
break;
} while ( -- V_7 );
V_8 = F_10 ( F_8 ( V_5 ) ) ;
F_3 ( V_9 , F_4 ( V_5 ) ) ;
F_5 () ;
F_11 ( & V_5 -> V_11 ) ;
if ( V_3 != ( ( V_8 >> 16 ) & 0x7f ) )
V_7 = 1 ;
} while ( -- V_6 && ! V_7 );
return V_6 ? V_8 & 0xffff : 0xffff ;
}
static void F_12 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_7 , V_6 ;
F_3 ( V_9 , F_4 ( V_5 ) ) ;
F_5 () ;
V_6 = V_10 ;
do {
F_6 ( & V_5 -> V_11 ) ;
F_3 ( F_7 ( V_3 ) | ( V_13 & 0xffff ) ,
F_8 ( V_5 ) ) ;
F_5 () ;
V_7 = 20 ;
do {
F_9 ( 21 ) ;
if ( F_10 ( F_4 ( V_5 ) ) & V_9 )
break;
} while ( -- V_7 );
F_3 ( V_9 , F_4 ( V_5 ) ) ;
F_5 () ;
F_11 ( & V_5 -> V_11 ) ;
} while ( -- V_6 && ! V_7 );
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_14 , F_14 ( V_5 ) ) ;
F_5 () ;
F_15 ( 10 ) ;
F_3 ( 0 , F_14 ( V_5 ) ) ;
F_5 () ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_15 ;
F_3 ( 0 , F_17 ( V_16 ) ) ;
F_5 () ;
F_3 ( V_17 , F_18 ( V_5 ) ) ;
F_5 () ;
F_3 ( V_18 , F_14 ( V_5 ) ) ;
F_5 () ;
F_15 ( 500 ) ;
F_3 ( 0 , F_14 ( V_5 ) ) ;
F_5 () ;
F_3 ( V_19 , F_18 ( V_5 ) ) ;
F_5 () ;
V_15 = 1000 ;
while ( ! ( ( F_10 ( F_19 ( V_5 ) ) & V_20 ) ) && ( -- V_15 ) )
F_15 ( 1 ) ;
if ( V_15 == 0 ) {
F_20 ( V_21 L_1 ) ;
return;
}
F_3 ( V_5 -> V_22 | V_23 , F_17 ( V_5 ) ) ;
F_5 () ;
V_15 = 1000 ;
while ( ! ( ( F_10 ( F_19 ( V_5 ) ) & V_24 ) ) && ( -- V_15 ) )
F_15 ( 1 ) ;
if ( V_15 == 0 )
F_20 ( V_21 L_2 ) ;
}
static int F_21 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_4 * V_5 = F_22 ( V_30 ) ;
unsigned long V_31 , V_32 , V_33 ;
int V_34 , V_35 , V_36 = V_26 -> V_37 ;
V_34 = F_23 ( V_28 ) ;
V_31 = V_32 = F_10 ( F_17 ( V_5 ) ) ;
V_33 = F_10 ( F_19 ( V_5 ) ) ;
if ( V_33 & ( V_38 | V_39 ) ) {
if ( ( F_24 ( V_31 ) != V_28 -> V_40 ) ||
( V_5 -> V_41 != F_25 ( V_28 ) ) )
return - V_42 ;
} else {
V_31 &= ~ V_43 ;
V_31 |= F_26 ( V_28 -> V_40 ) ;
if ( V_36 == V_44 ) {
V_31 &= ~ V_45 ;
V_31 |= F_27 ( 3 ) ;
V_31 |= F_27 ( 4 ) ;
} else {
V_31 &= ~ V_46 ;
V_31 |= F_28 ( 3 ) ;
V_31 |= F_28 ( 4 ) ;
}
if ( ! ( V_31 ^ V_32 ) )
goto V_47;
F_6 ( & V_5 -> V_11 ) ;
F_3 ( V_31 & ~ V_23 , F_17 ( V_5 ) ) ;
F_5 () ;
V_35 = 100 ;
while ( ( F_10 ( F_19 ( V_5 ) ) & V_24 ) && -- V_35 )
F_15 ( 1 ) ;
if ( ! V_35 )
F_20 ( V_21 L_3 ) ;
F_3 ( V_31 , F_17 ( V_5 ) ) ;
F_5 () ;
F_3 ( V_31 | V_23 , F_17 ( V_5 ) ) ;
F_5 () ;
V_35 = 100 ;
while ( ( ! ( F_10 ( F_19 ( V_5 ) ) & V_24 ) ) && -- V_35 )
F_15 ( 1 ) ;
if ( ! V_35 )
F_20 ( V_21 L_4 ) ;
F_11 ( & V_5 -> V_11 ) ;
V_5 -> V_22 = V_31 ;
V_5 -> V_41 = F_25 ( V_28 ) ;
}
V_47:
return 0 ;
}
static int F_29 ( struct V_25 * V_26 ,
int V_48 , struct V_29 * V_30 )
{
struct V_4 * V_5 = F_22 ( V_30 ) ;
int V_49 , V_36 = V_26 -> V_37 ;
V_49 = 0 ;
switch ( V_48 ) {
case V_50 :
case V_51 :
F_3 ( F_30 ( V_36 ) , F_31 ( V_5 ) ) ;
F_5 () ;
F_3 ( F_32 ( V_36 ) , F_31 ( V_5 ) ) ;
F_5 () ;
break;
case V_52 :
case V_53 :
F_3 ( F_33 ( V_36 ) , F_31 ( V_5 ) ) ;
F_5 () ;
while ( F_10 ( F_19 ( V_5 ) ) & F_34 ( V_36 ) )
asm volatile ("nop");
F_3 ( F_30 ( V_36 ) , F_31 ( V_5 ) ) ;
F_5 () ;
break;
default:
V_49 = - V_42 ;
}
return V_49 ;
}
static int F_35 ( struct V_25 * V_26 ,
struct V_29 * V_30 )
{
struct V_4 * V_5 = F_22 ( V_30 ) ;
F_36 ( V_30 , V_26 , & V_5 -> V_54 [ 0 ] ) ;
return 0 ;
}
static int F_37 ( struct V_29 * V_30 )
{
return V_16 ? 0 : - V_55 ;
}
static int F_38 ( struct V_56 * V_57 )
{
int V_49 ;
struct V_58 * V_59 , * V_60 ;
unsigned long V_61 ;
struct V_4 * V_62 ;
V_62 = F_39 ( & V_57 -> V_63 , sizeof( struct V_4 ) ,
V_64 ) ;
if ( ! V_62 )
return - V_65 ;
F_40 ( & V_62 -> V_11 ) ;
V_59 = F_41 ( V_57 , V_66 , 0 ) ;
if ( ! V_59 )
return - V_55 ;
V_62 -> V_67 = F_42 ( & V_57 -> V_63 , V_59 ) ;
if ( F_43 ( V_62 -> V_67 ) )
return F_44 ( V_62 -> V_67 ) ;
V_60 = F_41 ( V_57 , V_68 , 0 ) ;
if ( ! V_60 )
return - V_69 ;
V_62 -> V_54 [ V_44 ] = V_60 -> V_70 ;
V_60 = F_41 ( V_57 , V_68 , 1 ) ;
if ( ! V_60 )
return - V_69 ;
V_62 -> V_54 [ V_71 ] = V_60 -> V_70 ;
V_62 -> V_22 = V_72 | V_73 |
V_23 ;
V_61 = F_10 ( F_45 ( V_62 ) ) & V_74 ;
F_3 ( V_17 , F_18 ( V_62 ) ) ;
F_5 () ;
F_3 ( 0 , F_45 ( V_62 ) ) ;
F_5 () ;
F_3 ( V_75 | V_61 , F_45 ( V_62 ) ) ;
F_5 () ;
memcpy ( & V_62 -> V_76 , & V_77 ,
sizeof( struct V_78 ) ) ;
V_62 -> V_76 . V_79 = F_46 ( & V_57 -> V_63 ) ;
F_47 ( V_57 , V_62 ) ;
V_49 = F_48 ( & V_80 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_49 ( & V_57 -> V_63 , & V_81 ,
& V_62 -> V_76 , 1 ) ;
if ( V_49 )
return V_49 ;
V_16 = V_62 ;
return 0 ;
}
static int F_50 ( struct V_56 * V_57 )
{
struct V_4 * V_62 = F_51 ( V_57 ) ;
F_52 ( & V_57 -> V_63 ) ;
F_3 ( 0 , F_17 ( V_62 ) ) ;
F_5 () ;
F_3 ( V_17 , F_18 ( V_62 ) ) ;
F_5 () ;
V_16 = NULL ;
return 0 ;
}
static int F_53 ( struct V_82 * V_63 )
{
struct V_4 * V_62 = F_54 ( V_63 ) ;
V_62 -> V_83 [ 0 ] = F_10 ( F_45 ( V_62 ) ) ;
F_3 ( 0 , F_17 ( V_62 ) ) ;
F_5 () ;
F_3 ( V_17 , F_18 ( V_62 ) ) ;
F_5 () ;
return 0 ;
}
static int F_55 ( struct V_82 * V_63 )
{
struct V_4 * V_62 = F_54 ( V_63 ) ;
F_3 ( V_62 -> V_83 [ 0 ] | V_75 , F_45 ( V_62 ) ) ;
F_5 () ;
return 0 ;
}
