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
struct V_1 * V_2 = F_5 ( V_6 ) ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_3 , V_2 -> V_4 , 4 ) ;
if ( V_7 == 0 ) {
if ( V_6 -> V_12 )
( ( V_13 * ) V_2 -> V_4 ) [ 1 ] = V_11 -> V_14 ;
F_9 ( V_6 , ( V_15 * ) V_2 -> V_4 ) ;
}
F_10 ( V_6 -> V_16 ) ;
return V_17 ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_18 )
{
unsigned int V_19 ;
if ( V_2 -> V_20 )
return;
switch ( V_2 -> V_21 ) {
case V_22 :
V_18 >>= 1 ;
break;
case V_23 :
V_18 |= 1 ;
break;
case V_24 :
V_18 &= ~ 1 ;
break;
}
for ( V_19 = 0 ; V_19 < 3 ; ++ V_19 )
F_12 ( V_2 -> V_25 [ V_19 ] . V_26 , ( bool ) ( V_18 & F_13 ( V_19 ) ) ) ;
}
static int F_14 ( struct V_5 * V_6 ,
const unsigned long * V_27 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
unsigned int V_18 = F_15 ( V_27 , V_6 -> V_28 ) ;
F_11 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int * V_29 ,
unsigned int V_30 )
{
int V_7 ;
F_11 ( V_2 , V_30 ) ;
V_7 = F_17 ( V_2 -> V_3 , & V_2 -> V_31 ) ;
* V_29 = F_18 ( V_2 -> V_4 [ V_30 % 2 ] ) ;
return V_7 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_32 const * V_33 , int * V_29 , int * V_34 , long V_35 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
unsigned long V_36 ;
int V_7 ;
switch ( V_35 ) {
case V_37 :
if ( F_20 ( V_6 ) )
return - V_38 ;
V_7 = F_16 ( V_2 , V_29 , V_33 -> V_30 ) ;
if ( V_7 )
return V_7 ;
* V_29 = ( * V_29 >> 2 ) & 0xfff ;
if ( V_33 -> V_39 . V_40 == 's' )
* V_29 = F_21 ( * V_29 , 11 ) ;
return V_41 ;
case V_42 :
V_36 = ( V_2 -> V_43 * 100 ) ;
if ( V_2 -> V_21 == V_24 )
V_36 *= 2 ;
if ( V_2 -> V_44 == V_45 )
V_36 *= 2 ;
V_36 >>= V_33 -> V_39 . V_46 ;
* V_29 = V_36 / 100000 ;
* V_34 = ( V_36 % 100000 ) * 10 ;
return V_47 ;
case V_48 :
if ( V_2 -> V_44 == V_45 &&
V_2 -> V_21 != V_24 )
* V_29 = 2048 ;
else
* V_29 = 0 ;
return V_41 ;
}
return - V_49 ;
}
static void F_22 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
bool V_50 , V_51 ;
const struct V_52 * V_53 ;
int V_19 ;
V_50 = V_2 -> V_21 != V_22 ;
V_51 = ( V_2 -> V_44 == V_45 ) |
( V_2 -> V_21 == V_24 ) ;
V_19 = F_23 ( V_50 , V_51 , V_2 -> V_20 ) ;
V_53 = & V_54 [ V_19 ] ;
V_6 -> V_55 = V_53 -> V_55 ;
V_6 -> V_56 = V_53 -> V_56 ;
V_6 -> V_57 = V_53 -> V_58 ;
V_6 -> V_28 = V_53 -> V_56 - 1 ;
}
static int F_24 ( struct V_59 * V_3 )
{
struct V_60 * V_61 = V_3 -> V_62 . V_63 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
unsigned int V_19 ;
int V_7 ;
V_6 = F_25 ( sizeof( * V_2 ) ) ;
if ( V_6 == NULL )
return - V_64 ;
V_2 = F_5 ( V_6 ) ;
V_2 -> V_65 = F_26 ( & V_3 -> V_62 , L_1 ) ;
if ( ! F_27 ( V_2 -> V_65 ) ) {
V_7 = F_28 ( V_2 -> V_65 ) ;
if ( V_7 )
goto V_66;
V_7 = F_29 ( V_2 -> V_65 ) ;
if ( V_7 < 0 )
goto V_67;
V_2 -> V_43 = V_7 ;
} else {
V_2 -> V_43 = 2500000 ;
}
if ( V_61 ) {
V_2 -> V_20 = V_61 -> V_20 ;
V_2 -> V_21 = V_61 -> V_21 ;
V_2 -> V_44 = V_61 -> V_44 ;
if ( ! V_2 -> V_20 ) {
for ( V_19 = 0 ; V_19 < F_30 ( V_2 -> V_25 ) ; ++ V_19 ) {
V_2 -> V_25 [ V_19 ] . V_26 = V_61 -> V_68 [ V_19 ] ;
V_2 -> V_25 [ V_19 ] . V_69 = V_70 ;
V_2 -> V_25 [ V_19 ] . V_71 = V_72 [ V_19 ] ;
}
V_7 = F_31 ( V_2 -> V_25 ,
F_30 ( V_2 -> V_25 ) ) ;
if ( V_7 )
goto V_67;
}
} else {
V_2 -> V_20 = true ;
V_2 -> V_44 = V_73 ;
V_2 -> V_21 = V_24 ;
}
F_32 ( V_3 , V_6 ) ;
V_2 -> V_3 = V_3 ;
V_6 -> V_62 . V_74 = & V_3 -> V_62 ;
V_6 -> V_75 = F_33 ( V_3 ) -> V_75 ;
V_6 -> V_76 = V_77 ;
V_6 -> V_78 = & V_79 ;
F_22 ( V_6 ) ;
V_2 -> V_80 [ 0 ] . V_81 = & V_2 -> V_4 ;
V_2 -> V_80 [ 0 ] . V_82 = 2 ;
V_2 -> V_80 [ 0 ] . V_83 = 1 ;
V_2 -> V_80 [ 1 ] . V_81 = & V_2 -> V_4 ;
V_2 -> V_80 [ 1 ] . V_82 = 4 ;
V_2 -> V_80 [ 1 ] . V_83 = 1 ;
V_2 -> V_80 [ 2 ] . V_84 = & V_2 -> V_4 ;
V_2 -> V_80 [ 2 ] . V_82 = 1 ;
F_34 ( & V_2 -> V_31 ) ;
F_35 ( & V_2 -> V_80 [ 0 ] , & V_2 -> V_31 ) ;
F_35 ( & V_2 -> V_80 [ 1 ] , & V_2 -> V_31 ) ;
F_35 ( & V_2 -> V_80 [ 2 ] , & V_2 -> V_31 ) ;
V_7 = F_36 ( V_6 , & V_85 ,
& F_8 , & V_86 ) ;
if ( V_7 )
goto V_87;
V_7 = F_37 ( V_6 ) ;
if ( V_7 )
goto V_88;
return 0 ;
V_88:
F_38 ( V_6 ) ;
V_87:
if ( ! V_2 -> V_20 )
F_39 ( V_2 -> V_25 , F_30 ( V_2 -> V_25 ) ) ;
V_67:
if ( ! F_27 ( V_2 -> V_65 ) )
F_40 ( V_2 -> V_65 ) ;
V_66:
if ( ! F_27 ( V_2 -> V_65 ) )
F_41 ( V_2 -> V_65 ) ;
F_42 ( V_6 ) ;
return V_7 ;
}
static int F_43 ( struct V_59 * V_3 )
{
struct V_5 * V_6 = F_44 ( V_3 ) ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
F_45 ( V_6 ) ;
F_38 ( V_6 ) ;
if ( ! V_2 -> V_20 )
F_39 ( V_2 -> V_25 , F_30 ( V_2 -> V_25 ) ) ;
if ( ! F_27 ( V_2 -> V_65 ) ) {
F_40 ( V_2 -> V_65 ) ;
F_41 ( V_2 -> V_65 ) ;
}
F_42 ( V_6 ) ;
return 0 ;
}
