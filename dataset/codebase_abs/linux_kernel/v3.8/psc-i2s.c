static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
int V_7 ;
V_7 = - V_8 ;
V_6 = V_5 -> V_9 ;
V_6 &= ~ ( V_10 | V_11 ) ;
switch ( V_3 & V_12 ) {
case V_13 :
V_6 |= V_10 ;
break;
case V_14 :
break;
case V_15 :
V_6 |= V_11 ;
break;
default:
goto V_16;
}
V_6 &= ~ ( V_17 | V_18 ) ;
switch ( V_3 & V_19 ) {
case V_20 :
V_6 |= V_17 | V_18 ;
break;
case V_21 :
V_6 |= V_17 ;
break;
case V_22 :
V_6 |= V_18 ;
break;
case V_23 :
break;
default:
goto V_16;
}
switch ( V_3 & V_24 ) {
case V_25 :
V_6 |= V_26 ;
break;
case V_27 :
V_6 &= ~ V_26 ;
break;
default:
goto V_16;
}
V_5 -> V_9 = V_6 ;
V_7 = 0 ;
V_16:
return V_7 ;
}
static int F_3 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_1 * V_32 )
{
struct V_4 * V_5 = F_2 ( V_32 ) ;
int V_33 ;
unsigned long V_34 ;
V_34 = F_4 ( F_5 ( V_5 ) ) ;
if ( V_34 & ( V_35 | V_36 ) ) {
V_33 = F_4 ( F_6 ( V_5 ) ) ;
if ( ( F_7 ( V_33 ) != V_31 -> V_37 ) ||
( F_8 ( V_31 ) != V_5 -> V_38 ) )
return - V_8 ;
} else {
V_5 -> V_9 &= ~ ( 0x1f << 4 ) ;
V_5 -> V_9 |= F_9 ( V_31 -> V_37 ) ;
V_5 -> V_38 = F_8 ( V_31 ) ;
}
return 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
unsigned long V_39 ;
F_11 ( V_40 , F_12 ( V_5 ) ) ;
F_13 () ;
V_39 = 1000000 ;
while ( ! ( F_4 ( F_5 ( V_5 ) ) & V_41 ) && V_39 )
V_39 -- ;
if ( ! V_39 )
goto V_42;
F_11 ( 0 , F_6 ( V_5 ) ) ;
F_13 () ;
F_11 ( V_5 -> V_9 | V_43 , F_6 ( V_5 ) ) ;
F_13 () ;
V_39 = 1000000 ;
while ( ! ( F_4 ( F_5 ( V_5 ) ) & V_44 ) && V_39 )
V_39 -- ;
if ( V_39 )
return 0 ;
V_42:
F_11 ( 0 , F_6 ( V_5 ) ) ;
F_11 ( V_45 , F_12 ( V_5 ) ) ;
F_13 () ;
return - V_46 ;
}
static int F_14 ( struct V_4 * V_5 , int V_47 )
{
unsigned long V_39 , V_34 ;
int V_7 ;
V_7 = 0 ;
V_34 = F_4 ( F_5 ( V_5 ) ) ;
if ( ! ( V_34 & ( V_35 | V_36 ) ) ) {
V_7 = F_10 ( V_5 ) ;
if ( V_7 )
goto V_16;
}
F_11 ( F_15 ( V_47 ) , F_16 ( V_5 ) ) ;
F_13 () ;
F_11 ( F_17 ( V_47 ) , F_16 ( V_5 ) ) ;
F_13 () ;
V_39 = 1000000 ;
while ( ! ( F_4 ( F_5 ( V_5 ) ) & F_18 ( V_47 ) ) && V_39 )
V_39 -- ;
if ( ! V_39 ) {
F_11 ( F_19 ( V_47 ) , F_16 ( V_5 ) ) ;
F_13 () ;
V_7 = - V_46 ;
}
V_16:
return V_7 ;
}
static int F_20 ( struct V_4 * V_5 , int V_47 )
{
unsigned long V_39 , V_34 ;
F_11 ( F_19 ( V_47 ) , F_16 ( V_5 ) ) ;
F_13 () ;
V_39 = 1000000 ;
while ( ( F_4 ( F_5 ( V_5 ) ) & F_18 ( V_47 ) ) && V_39 )
V_39 -- ;
V_34 = F_4 ( F_5 ( V_5 ) ) ;
if ( ! ( V_34 & ( V_35 | V_36 ) ) ) {
F_11 ( 0 , F_6 ( V_5 ) ) ;
F_13 () ;
F_11 ( V_45 , F_12 ( V_5 ) ) ;
F_13 () ;
}
return 0 ;
}
static int F_21 ( struct V_28 * V_29 , int V_48 ,
struct V_1 * V_32 )
{
struct V_4 * V_5 = F_2 ( V_32 ) ;
int V_7 , V_47 = V_29 -> V_49 ;
switch ( V_48 ) {
case V_50 :
case V_51 :
V_7 = F_14 ( V_5 , V_47 ) ;
break;
case V_52 :
case V_53 :
V_7 = F_20 ( V_5 , V_47 ) ;
break;
default:
V_7 = - V_8 ;
}
return V_7 ;
}
static int F_22 ( struct V_28 * V_29 ,
struct V_1 * V_32 )
{
struct V_4 * V_5 = F_2 ( V_32 ) ;
F_23 ( V_32 , V_29 , & V_5 -> V_54 [ 0 ] ) ;
return 0 ;
}
static int F_24 ( struct V_55 * V_56 )
{
struct V_57 * V_58 , * V_59 ;
unsigned long V_60 ;
int V_7 ;
struct V_4 * V_61 ;
V_61 = F_25 ( & V_56 -> V_62 , sizeof( struct V_4 ) ,
V_63 ) ;
if ( ! V_61 )
return - V_64 ;
V_58 = F_26 ( V_56 , V_65 , 0 ) ;
if ( ! V_58 )
return - V_66 ;
V_7 = - V_67 ;
if ( ! F_27 ( & V_56 -> V_62 , V_58 -> V_68 ,
F_28 ( V_58 ) ,
V_56 -> V_69 ) )
return - V_67 ;
V_61 -> V_70 = F_29 ( & V_56 -> V_62 , V_58 -> V_68 ,
F_28 ( V_58 ) ) ;
if ( ! V_61 -> V_70 )
return - V_67 ;
V_59 = F_26 ( V_56 , V_71 , 0 ) ;
if ( ! V_59 )
return - V_67 ;
V_61 -> V_54 [ V_72 ] = V_59 -> V_68 ;
V_59 = F_26 ( V_56 , V_71 , 1 ) ;
if ( ! V_59 )
return - V_67 ;
V_61 -> V_54 [ V_73 ] = V_59 -> V_68 ;
V_60 = F_4 ( F_30 ( V_61 ) ) & V_74 ;
F_11 ( V_75 , F_12 ( V_61 ) ) ;
F_13 () ;
F_11 ( V_76 | V_60 , F_30 ( V_61 ) ) ;
F_11 ( 0 , F_6 ( V_61 ) ) ;
F_13 () ;
V_61 -> V_9 |= V_77 | V_78 ;
memcpy ( & V_61 -> V_79 , & V_80 ,
sizeof( struct V_81 ) ) ;
V_61 -> V_79 . V_69 = F_31 ( & V_56 -> V_62 ) ;
F_32 ( V_56 , V_61 ) ;
return F_33 ( & V_56 -> V_62 , & V_61 -> V_79 ) ;
}
static int F_34 ( struct V_55 * V_56 )
{
struct V_4 * V_61 = F_35 ( V_56 ) ;
F_36 ( & V_56 -> V_62 ) ;
F_11 ( 0 , F_6 ( V_61 ) ) ;
F_13 () ;
F_11 ( V_75 , F_12 ( V_61 ) ) ;
F_13 () ;
return 0 ;
}
static int F_37 ( struct V_82 * V_62 )
{
struct V_4 * V_61 = F_38 ( V_62 ) ;
V_61 -> V_83 [ 0 ] = F_4 ( F_30 ( V_61 ) ) ;
F_11 ( 0 , F_6 ( V_61 ) ) ;
F_13 () ;
F_11 ( V_75 , F_12 ( V_61 ) ) ;
F_13 () ;
return 0 ;
}
static int F_39 ( struct V_82 * V_62 )
{
struct V_4 * V_61 = F_38 ( V_62 ) ;
F_11 ( V_75 , F_12 ( V_61 ) ) ;
F_13 () ;
F_11 ( 0 , F_30 ( V_61 ) ) ;
F_13 () ;
F_11 ( V_61 -> V_83 [ 0 ] , F_30 ( V_61 ) ) ;
F_13 () ;
return 0 ;
}
