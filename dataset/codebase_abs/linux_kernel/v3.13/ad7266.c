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
return F_1 ( V_2 ) ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
return F_3 ( V_2 ) ;
}
static T_1 F_7 ( int V_7 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
struct V_5 * V_6 = V_10 -> V_6 ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
int V_11 ;
V_11 = F_2 ( V_2 -> V_3 , V_2 -> V_4 , 4 ) ;
if ( V_11 == 0 ) {
F_8 ( V_6 , V_2 -> V_4 ,
V_10 -> V_12 ) ;
}
F_9 ( V_6 -> V_13 ) ;
return V_14 ;
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_15 )
{
unsigned int V_16 ;
if ( V_2 -> V_17 )
return;
switch ( V_2 -> V_18 ) {
case V_19 :
V_15 >>= 1 ;
break;
case V_20 :
V_15 |= 1 ;
break;
case V_21 :
V_15 &= ~ 1 ;
break;
}
for ( V_16 = 0 ; V_16 < 3 ; ++ V_16 )
F_11 ( V_2 -> V_22 [ V_16 ] . V_23 , ( bool ) ( V_15 & F_12 ( V_16 ) ) ) ;
}
static int F_13 ( struct V_5 * V_6 ,
const unsigned long * V_24 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
unsigned int V_15 = F_14 ( V_24 , V_6 -> V_25 ) ;
F_10 ( V_2 , V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int * V_26 ,
unsigned int V_27 )
{
int V_11 ;
F_10 ( V_2 , V_27 ) ;
V_11 = F_16 ( V_2 -> V_3 , & V_2 -> V_28 ) ;
* V_26 = F_17 ( V_2 -> V_4 [ V_27 % 2 ] ) ;
return V_11 ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_29 const * V_30 , int * V_26 , int * V_31 , long V_32 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
unsigned long V_33 ;
int V_11 ;
switch ( V_32 ) {
case V_34 :
if ( F_19 ( V_6 ) )
return - V_35 ;
V_11 = F_15 ( V_2 , V_26 , V_30 -> V_27 ) ;
if ( V_11 )
return V_11 ;
* V_26 = ( * V_26 >> 2 ) & 0xfff ;
if ( V_30 -> V_36 . V_37 == 's' )
* V_26 = F_20 ( * V_26 , 11 ) ;
return V_38 ;
case V_39 :
V_33 = V_2 -> V_40 ;
if ( V_2 -> V_18 == V_21 )
V_33 *= 2 ;
if ( V_2 -> V_41 == V_42 )
V_33 *= 2 ;
* V_26 = V_33 ;
* V_31 = V_30 -> V_36 . V_43 ;
return V_44 ;
case V_45 :
if ( V_2 -> V_41 == V_42 &&
V_2 -> V_18 != V_21 )
* V_26 = 2048 ;
else
* V_26 = 0 ;
return V_38 ;
}
return - V_46 ;
}
static void F_21 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
bool V_47 , V_48 ;
const struct V_49 * V_50 ;
int V_16 ;
V_47 = V_2 -> V_18 != V_19 ;
V_48 = ( V_2 -> V_41 == V_42 ) |
( V_2 -> V_18 == V_21 ) ;
V_16 = F_22 ( V_47 , V_48 , V_2 -> V_17 ) ;
V_50 = & V_51 [ V_16 ] ;
V_6 -> V_52 = V_50 -> V_52 ;
V_6 -> V_53 = V_50 -> V_53 ;
V_6 -> V_54 = V_50 -> V_55 ;
V_6 -> V_25 = V_50 -> V_53 - 1 ;
}
static int F_23 ( struct V_56 * V_3 )
{
struct V_57 * V_58 = V_3 -> V_59 . V_60 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
unsigned int V_16 ;
int V_11 ;
V_6 = F_24 ( & V_3 -> V_59 , sizeof( * V_2 ) ) ;
if ( V_6 == NULL )
return - V_61 ;
V_2 = F_5 ( V_6 ) ;
V_2 -> V_62 = F_25 ( & V_3 -> V_59 , L_1 ) ;
if ( ! F_26 ( V_2 -> V_62 ) ) {
V_11 = F_27 ( V_2 -> V_62 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_28 ( V_2 -> V_62 ) ;
if ( V_11 < 0 )
goto V_63;
V_2 -> V_40 = V_11 / 1000 ;
} else {
V_2 -> V_40 = 2500 ;
}
if ( V_58 ) {
V_2 -> V_17 = V_58 -> V_17 ;
V_2 -> V_18 = V_58 -> V_18 ;
V_2 -> V_41 = V_58 -> V_41 ;
if ( ! V_2 -> V_17 ) {
for ( V_16 = 0 ; V_16 < F_29 ( V_2 -> V_22 ) ; ++ V_16 ) {
V_2 -> V_22 [ V_16 ] . V_23 = V_58 -> V_64 [ V_16 ] ;
V_2 -> V_22 [ V_16 ] . V_65 = V_66 ;
V_2 -> V_22 [ V_16 ] . V_67 = V_68 [ V_16 ] ;
}
V_11 = F_30 ( V_2 -> V_22 ,
F_29 ( V_2 -> V_22 ) ) ;
if ( V_11 )
goto V_63;
}
} else {
V_2 -> V_17 = true ;
V_2 -> V_41 = V_69 ;
V_2 -> V_18 = V_21 ;
}
F_31 ( V_3 , V_6 ) ;
V_2 -> V_3 = V_3 ;
V_6 -> V_59 . V_70 = & V_3 -> V_59 ;
V_6 -> V_71 = F_32 ( V_3 ) -> V_71 ;
V_6 -> V_72 = V_73 ;
V_6 -> V_74 = & V_75 ;
F_21 ( V_6 ) ;
V_2 -> V_76 [ 0 ] . V_77 = & V_2 -> V_4 ;
V_2 -> V_76 [ 0 ] . V_78 = 2 ;
V_2 -> V_76 [ 0 ] . V_79 = 1 ;
V_2 -> V_76 [ 1 ] . V_77 = & V_2 -> V_4 ;
V_2 -> V_76 [ 1 ] . V_78 = 4 ;
V_2 -> V_76 [ 1 ] . V_79 = 1 ;
V_2 -> V_76 [ 2 ] . V_80 = & V_2 -> V_4 ;
V_2 -> V_76 [ 2 ] . V_78 = 1 ;
F_33 ( & V_2 -> V_28 ) ;
F_34 ( & V_2 -> V_76 [ 0 ] , & V_2 -> V_28 ) ;
F_34 ( & V_2 -> V_76 [ 1 ] , & V_2 -> V_28 ) ;
F_34 ( & V_2 -> V_76 [ 2 ] , & V_2 -> V_28 ) ;
V_11 = F_35 ( V_6 , & V_81 ,
& F_7 , & V_82 ) ;
if ( V_11 )
goto V_83;
V_11 = F_36 ( V_6 ) ;
if ( V_11 )
goto V_84;
return 0 ;
V_84:
F_37 ( V_6 ) ;
V_83:
if ( ! V_2 -> V_17 )
F_38 ( V_2 -> V_22 , F_29 ( V_2 -> V_22 ) ) ;
V_63:
if ( ! F_26 ( V_2 -> V_62 ) )
F_39 ( V_2 -> V_62 ) ;
return V_11 ;
}
static int F_40 ( struct V_56 * V_3 )
{
struct V_5 * V_6 = F_41 ( V_3 ) ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
F_42 ( V_6 ) ;
F_37 ( V_6 ) ;
if ( ! V_2 -> V_17 )
F_38 ( V_2 -> V_22 , F_29 ( V_2 -> V_22 ) ) ;
if ( ! F_26 ( V_2 -> V_62 ) )
F_39 ( V_2 -> V_62 ) ;
return 0 ;
}
