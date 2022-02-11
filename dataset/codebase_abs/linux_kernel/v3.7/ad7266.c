static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_2 -> V_4 , 2 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_2 -> V_4 , 1 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
int V_7 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_6 ) ;
if ( V_7 )
F_3 ( V_2 ) ;
return V_7 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
return F_3 ( V_2 ) ;
}
static T_1 F_8 ( int V_8 , void * V_9 )
{
struct V_10 * V_11 = V_9 ;
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_12 * V_13 = V_6 -> V_13 ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_3 , V_2 -> V_4 , 4 ) ;
if ( V_7 == 0 ) {
if ( V_6 -> V_14 )
( ( V_15 * ) V_2 -> V_4 ) [ 1 ] = V_11 -> V_16 ;
F_9 ( V_13 , ( V_17 * ) V_2 -> V_4 ) ;
}
F_10 ( V_6 -> V_18 ) ;
return V_19 ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_20 )
{
unsigned int V_21 ;
if ( V_2 -> V_22 )
return;
switch ( V_2 -> V_23 ) {
case V_24 :
V_20 >>= 1 ;
break;
case V_25 :
V_20 |= 1 ;
break;
case V_26 :
V_20 &= ~ 1 ;
break;
}
for ( V_21 = 0 ; V_21 < 3 ; ++ V_21 )
F_12 ( V_2 -> V_27 [ V_21 ] . V_28 , ( bool ) ( V_20 & F_13 ( V_21 ) ) ) ;
}
static int F_14 ( struct V_5 * V_6 ,
const unsigned long * V_29 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
unsigned int V_20 = F_15 ( V_29 , V_6 -> V_30 ) ;
F_11 ( V_2 , V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int * V_31 ,
unsigned int V_32 )
{
int V_7 ;
F_11 ( V_2 , V_32 ) ;
V_7 = F_17 ( V_2 -> V_3 , & V_2 -> V_33 ) ;
* V_31 = F_18 ( V_2 -> V_4 [ V_32 % 2 ] ) ;
return V_7 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_34 const * V_35 , int * V_31 , int * V_36 , long V_37 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
unsigned long V_38 ;
int V_7 ;
switch ( V_37 ) {
case V_39 :
if ( F_20 ( V_6 ) )
return - V_40 ;
V_7 = F_16 ( V_2 , V_31 , V_35 -> V_32 ) ;
if ( V_7 )
return V_7 ;
* V_31 = ( * V_31 >> 2 ) & 0xfff ;
if ( V_35 -> V_41 . V_42 == 's' )
* V_31 = F_21 ( * V_31 , 11 ) ;
return V_43 ;
case V_44 :
V_38 = ( V_2 -> V_45 * 100 ) ;
if ( V_2 -> V_23 == V_26 )
V_38 *= 2 ;
if ( V_2 -> V_46 == V_47 )
V_38 *= 2 ;
V_38 >>= V_35 -> V_41 . V_48 ;
* V_31 = V_38 / 100000 ;
* V_36 = ( V_38 % 100000 ) * 10 ;
return V_49 ;
case V_50 :
if ( V_2 -> V_46 == V_47 &&
V_2 -> V_23 != V_26 )
* V_31 = 2048 ;
else
* V_31 = 0 ;
return V_43 ;
}
return - V_51 ;
}
static void T_2 F_22 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
bool V_52 , V_53 ;
const struct V_54 * V_55 ;
int V_21 ;
V_52 = V_2 -> V_23 != V_24 ;
V_53 = ( V_2 -> V_46 == V_47 ) |
( V_2 -> V_23 == V_26 ) ;
V_21 = F_23 ( V_52 , V_53 , V_2 -> V_22 ) ;
V_55 = & V_56 [ V_21 ] ;
V_6 -> V_57 = V_55 -> V_57 ;
V_6 -> V_58 = V_55 -> V_58 ;
V_6 -> V_59 = V_55 -> V_60 ;
V_6 -> V_30 = V_55 -> V_58 - 1 ;
}
static int T_2 F_24 ( struct V_61 * V_3 )
{
struct V_62 * V_63 = V_3 -> V_64 . V_65 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
unsigned int V_21 ;
int V_7 ;
V_6 = F_25 ( sizeof( * V_2 ) ) ;
if ( V_6 == NULL )
return - V_66 ;
V_2 = F_5 ( V_6 ) ;
V_2 -> V_67 = F_26 ( & V_3 -> V_64 , L_1 ) ;
if ( ! F_27 ( V_2 -> V_67 ) ) {
V_7 = F_28 ( V_2 -> V_67 ) ;
if ( V_7 )
goto V_68;
V_2 -> V_45 = F_29 ( V_2 -> V_67 ) ;
} else {
V_2 -> V_45 = 2500000 ;
}
if ( V_63 ) {
V_2 -> V_22 = V_63 -> V_22 ;
V_2 -> V_23 = V_63 -> V_23 ;
V_2 -> V_46 = V_63 -> V_46 ;
if ( ! V_2 -> V_22 ) {
for ( V_21 = 0 ; V_21 < F_30 ( V_2 -> V_27 ) ; ++ V_21 ) {
V_2 -> V_27 [ V_21 ] . V_28 = V_63 -> V_69 [ V_21 ] ;
V_2 -> V_27 [ V_21 ] . V_70 = V_71 ;
V_2 -> V_27 [ V_21 ] . V_72 = V_73 [ V_21 ] ;
}
V_7 = F_31 ( V_2 -> V_27 ,
F_30 ( V_2 -> V_27 ) ) ;
if ( V_7 )
goto V_74;
}
} else {
V_2 -> V_22 = true ;
V_2 -> V_46 = V_75 ;
V_2 -> V_23 = V_26 ;
}
F_32 ( V_3 , V_6 ) ;
V_2 -> V_3 = V_3 ;
V_6 -> V_64 . V_76 = & V_3 -> V_64 ;
V_6 -> V_77 = F_33 ( V_3 ) -> V_77 ;
V_6 -> V_78 = V_79 ;
V_6 -> V_80 = & V_81 ;
F_22 ( V_6 ) ;
V_2 -> V_82 [ 0 ] . V_83 = & V_2 -> V_4 ;
V_2 -> V_82 [ 0 ] . V_84 = 2 ;
V_2 -> V_82 [ 0 ] . V_85 = 1 ;
V_2 -> V_82 [ 1 ] . V_83 = & V_2 -> V_4 ;
V_2 -> V_82 [ 1 ] . V_84 = 4 ;
V_2 -> V_82 [ 1 ] . V_85 = 1 ;
V_2 -> V_82 [ 2 ] . V_86 = & V_2 -> V_4 ;
V_2 -> V_82 [ 2 ] . V_84 = 1 ;
F_34 ( & V_2 -> V_33 ) ;
F_35 ( & V_2 -> V_82 [ 0 ] , & V_2 -> V_33 ) ;
F_35 ( & V_2 -> V_82 [ 1 ] , & V_2 -> V_33 ) ;
F_35 ( & V_2 -> V_82 [ 2 ] , & V_2 -> V_33 ) ;
V_7 = F_36 ( V_6 , & V_87 ,
& F_8 , & V_88 ) ;
if ( V_7 )
goto V_89;
V_7 = F_37 ( V_6 ) ;
if ( V_7 )
goto V_90;
return 0 ;
V_90:
F_38 ( V_6 ) ;
V_89:
if ( ! V_2 -> V_22 )
F_39 ( V_2 -> V_27 , F_30 ( V_2 -> V_27 ) ) ;
V_74:
if ( ! F_27 ( V_2 -> V_67 ) )
F_40 ( V_2 -> V_67 ) ;
V_68:
if ( ! F_27 ( V_2 -> V_67 ) )
F_41 ( V_2 -> V_67 ) ;
F_42 ( V_6 ) ;
return V_7 ;
}
static int T_3 F_43 ( struct V_61 * V_3 )
{
struct V_5 * V_6 = F_44 ( V_3 ) ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
F_45 ( V_6 ) ;
F_38 ( V_6 ) ;
if ( ! V_2 -> V_22 )
F_39 ( V_2 -> V_27 , F_30 ( V_2 -> V_27 ) ) ;
if ( ! F_27 ( V_2 -> V_67 ) ) {
F_40 ( V_2 -> V_67 ) ;
F_41 ( V_2 -> V_67 ) ;
}
F_42 ( V_6 ) ;
return 0 ;
}
