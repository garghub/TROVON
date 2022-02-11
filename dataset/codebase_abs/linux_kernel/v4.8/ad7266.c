static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , & V_2 -> V_4 . V_5 [ 0 ] , 2 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , & V_2 -> V_4 . V_5 [ 0 ] , 1 ) ;
}
static int F_4 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
return F_1 ( V_2 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
return F_3 ( V_2 ) ;
}
static T_1 F_7 ( int V_8 , void * V_9 )
{
struct V_10 * V_11 = V_9 ;
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_1 * V_2 = F_5 ( V_7 ) ;
int V_12 ;
V_12 = F_2 ( V_2 -> V_3 , V_2 -> V_4 . V_5 , 4 ) ;
if ( V_12 == 0 ) {
F_8 ( V_7 , & V_2 -> V_4 ,
V_11 -> V_13 ) ;
}
F_9 ( V_7 -> V_14 ) ;
return V_15 ;
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_16 )
{
unsigned int V_17 ;
if ( V_2 -> V_18 )
return;
switch ( V_2 -> V_19 ) {
case V_20 :
V_16 >>= 1 ;
break;
case V_21 :
V_16 |= 1 ;
break;
case V_22 :
V_16 &= ~ 1 ;
break;
}
for ( V_17 = 0 ; V_17 < 3 ; ++ V_17 )
F_11 ( V_2 -> V_23 [ V_17 ] . V_24 , ( bool ) ( V_16 & F_12 ( V_17 ) ) ) ;
}
static int F_13 ( struct V_6 * V_7 ,
const unsigned long * V_25 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_16 = F_14 ( V_25 , V_7 -> V_26 ) ;
F_10 ( V_2 , V_16 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int * V_27 ,
unsigned int V_28 )
{
int V_12 ;
F_10 ( V_2 , V_28 ) ;
V_12 = F_16 ( V_2 -> V_3 , & V_2 -> V_29 ) ;
* V_27 = F_17 ( V_2 -> V_4 . V_5 [ V_28 % 2 ] ) ;
return V_12 ;
}
static int F_18 ( struct V_6 * V_7 ,
struct V_30 const * V_31 , int * V_27 , int * V_32 , long V_33 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned long V_34 ;
int V_12 ;
switch ( V_33 ) {
case V_35 :
V_12 = F_19 ( V_7 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_2 , V_27 , V_31 -> V_28 ) ;
F_20 ( V_7 ) ;
* V_27 = ( * V_27 >> 2 ) & 0xfff ;
if ( V_31 -> V_36 . V_37 == 's' )
* V_27 = F_21 ( * V_27 , 11 ) ;
return V_38 ;
case V_39 :
V_34 = V_2 -> V_40 ;
if ( V_2 -> V_19 == V_22 )
V_34 *= 2 ;
if ( V_2 -> V_41 == V_42 )
V_34 *= 2 ;
* V_27 = V_34 ;
* V_32 = V_31 -> V_36 . V_43 ;
return V_44 ;
case V_45 :
if ( V_2 -> V_41 == V_42 &&
V_2 -> V_19 != V_22 )
* V_27 = 2048 ;
else
* V_27 = 0 ;
return V_38 ;
}
return - V_46 ;
}
static void F_22 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
bool V_47 , V_48 ;
const struct V_49 * V_50 ;
int V_17 ;
V_47 = V_2 -> V_19 != V_20 ;
V_48 = ( V_2 -> V_41 == V_42 ) |
( V_2 -> V_19 == V_22 ) ;
V_17 = F_23 ( V_47 , V_48 , V_2 -> V_18 ) ;
V_50 = & V_51 [ V_17 ] ;
V_7 -> V_52 = V_50 -> V_52 ;
V_7 -> V_53 = V_50 -> V_53 ;
V_7 -> V_54 = V_50 -> V_55 ;
V_7 -> V_26 = V_50 -> V_53 - 1 ;
}
static int F_24 ( struct V_56 * V_3 )
{
struct V_57 * V_58 = V_3 -> V_59 . V_60 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
unsigned int V_17 ;
int V_12 ;
V_7 = F_25 ( & V_3 -> V_59 , sizeof( * V_2 ) ) ;
if ( V_7 == NULL )
return - V_61 ;
V_2 = F_5 ( V_7 ) ;
V_2 -> V_62 = F_26 ( & V_3 -> V_59 , L_1 ) ;
if ( ! F_27 ( V_2 -> V_62 ) ) {
V_12 = F_28 ( V_2 -> V_62 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_29 ( V_2 -> V_62 ) ;
if ( V_12 < 0 )
goto V_63;
V_2 -> V_40 = V_12 / 1000 ;
} else {
if ( F_30 ( V_2 -> V_62 ) != - V_64 )
return F_30 ( V_2 -> V_62 ) ;
V_2 -> V_40 = 2500 ;
}
if ( V_58 ) {
V_2 -> V_18 = V_58 -> V_18 ;
V_2 -> V_19 = V_58 -> V_19 ;
V_2 -> V_41 = V_58 -> V_41 ;
if ( ! V_2 -> V_18 ) {
for ( V_17 = 0 ; V_17 < F_31 ( V_2 -> V_23 ) ; ++ V_17 ) {
V_2 -> V_23 [ V_17 ] . V_24 = V_58 -> V_65 [ V_17 ] ;
V_2 -> V_23 [ V_17 ] . V_66 = V_67 ;
V_2 -> V_23 [ V_17 ] . V_68 = V_69 [ V_17 ] ;
}
V_12 = F_32 ( V_2 -> V_23 ,
F_31 ( V_2 -> V_23 ) ) ;
if ( V_12 )
goto V_63;
}
} else {
V_2 -> V_18 = true ;
V_2 -> V_41 = V_70 ;
V_2 -> V_19 = V_22 ;
}
F_33 ( V_3 , V_7 ) ;
V_2 -> V_3 = V_3 ;
V_7 -> V_59 . V_71 = & V_3 -> V_59 ;
V_7 -> V_59 . V_72 = V_3 -> V_59 . V_72 ;
V_7 -> V_73 = F_34 ( V_3 ) -> V_73 ;
V_7 -> V_74 = V_75 ;
V_7 -> V_76 = & V_77 ;
F_22 ( V_7 ) ;
V_2 -> V_78 [ 0 ] . V_79 = & V_2 -> V_4 . V_5 [ 0 ] ;
V_2 -> V_78 [ 0 ] . V_80 = 2 ;
V_2 -> V_78 [ 0 ] . V_81 = 1 ;
V_2 -> V_78 [ 1 ] . V_79 = V_2 -> V_4 . V_5 ;
V_2 -> V_78 [ 1 ] . V_80 = 4 ;
V_2 -> V_78 [ 1 ] . V_81 = 1 ;
V_2 -> V_78 [ 2 ] . V_82 = & V_2 -> V_4 . V_5 [ 0 ] ;
V_2 -> V_78 [ 2 ] . V_80 = 1 ;
F_35 ( & V_2 -> V_29 ) ;
F_36 ( & V_2 -> V_78 [ 0 ] , & V_2 -> V_29 ) ;
F_36 ( & V_2 -> V_78 [ 1 ] , & V_2 -> V_29 ) ;
F_36 ( & V_2 -> V_78 [ 2 ] , & V_2 -> V_29 ) ;
V_12 = F_37 ( V_7 , & V_83 ,
& F_7 , & V_84 ) ;
if ( V_12 )
goto V_85;
V_12 = F_38 ( V_7 ) ;
if ( V_12 )
goto V_86;
return 0 ;
V_86:
F_39 ( V_7 ) ;
V_85:
if ( ! V_2 -> V_18 )
F_40 ( V_2 -> V_23 , F_31 ( V_2 -> V_23 ) ) ;
V_63:
if ( ! F_41 ( V_2 -> V_62 ) )
F_42 ( V_2 -> V_62 ) ;
return V_12 ;
}
static int F_43 ( struct V_56 * V_3 )
{
struct V_6 * V_7 = F_44 ( V_3 ) ;
struct V_1 * V_2 = F_5 ( V_7 ) ;
F_45 ( V_7 ) ;
F_39 ( V_7 ) ;
if ( ! V_2 -> V_18 )
F_40 ( V_2 -> V_23 , F_31 ( V_2 -> V_23 ) ) ;
if ( ! F_41 ( V_2 -> V_62 ) )
F_42 ( V_2 -> V_62 ) ;
return 0 ;
}
