static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
V_2 -> V_5 -> V_6 ( V_2 -> V_7 , V_3 , V_4 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 , int V_4 )
{
return V_2 -> V_5 -> V_8 ( V_2 -> V_7 , V_4 ) ;
}
static int F_3 ( struct V_9 * V_10 , T_1 V_11 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_11 == V_12 )
V_2 -> V_13 = 0 ;
else
V_2 -> V_13 |= F_5 ( V_11 ) | F_5 ( 15 ) ;
F_1 ( V_2 , V_2 -> V_13 & 255 , V_14 ) ;
F_1 ( V_2 , V_2 -> V_13 >> 8 , V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 , T_1 V_16 ,
T_2 V_17 , struct V_18 * V_19 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
unsigned int V_20 , V_21 ;
switch ( V_17 ) {
case V_22 :
V_21 = V_23 ;
break;
case V_24 :
default:
V_21 = V_25 ;
break;
case V_26 :
V_21 = V_27 ;
break;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_28 ; V_20 ++ )
F_1 ( V_2 , V_19 -> V_19 [ V_20 ] , V_29 + V_20 ) ;
F_1 ( V_2 , V_19 -> V_28 , V_30 ) ;
F_1 ( V_2 , V_21 | V_31 , V_32 ) ;
return 0 ;
}
static T_3 F_7 ( int V_33 , void * V_34 )
{
struct V_9 * V_10 = V_34 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
unsigned int V_35 = F_2 ( V_2 , V_36 ) ;
T_3 V_37 = V_38 ;
if ( V_35 == 0 )
return V_39 ;
F_1 ( V_2 , V_35 , V_36 ) ;
if ( V_35 & V_40 ) {
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = true ;
V_37 = V_44 ;
} else if ( V_35 & V_45 ) {
V_2 -> V_41 = V_46 ;
V_2 -> V_43 = true ;
V_37 = V_44 ;
} else if ( V_35 & V_47 ) {
V_2 -> V_41 = V_48 ;
V_2 -> V_43 = true ;
V_37 = V_44 ;
}
if ( V_35 & V_49 ) {
unsigned int V_28 , V_20 ;
V_28 = F_2 ( V_2 , V_50 ) ;
if ( V_28 > sizeof( V_2 -> V_51 . V_19 ) )
V_28 = sizeof( V_2 -> V_51 . V_19 ) ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ )
V_2 -> V_51 . V_19 [ V_20 ] =
F_2 ( V_2 , V_52 + V_20 ) ;
F_1 ( V_2 , 0 , V_53 ) ;
V_2 -> V_51 . V_28 = V_28 ;
F_8 () ;
V_2 -> V_54 = true ;
V_37 = V_44 ;
}
return V_37 ;
}
static T_3 F_9 ( int V_33 , void * V_34 )
{
struct V_9 * V_10 = V_34 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_2 -> V_43 ) {
V_2 -> V_43 = false ;
F_10 ( V_10 , V_2 -> V_41 ) ;
}
if ( V_2 -> V_54 ) {
V_2 -> V_54 = false ;
F_11 () ;
F_12 ( V_10 , & V_2 -> V_51 ) ;
}
return V_38 ;
}
static int F_13 ( struct V_9 * V_10 , bool V_55 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( ! V_55 ) {
F_1 ( V_2 , ~ 0 , V_56 ) ;
F_1 ( V_2 , ~ 0 , V_57 ) ;
F_1 ( V_2 , 0 , V_58 ) ;
V_2 -> V_5 -> V_59 ( V_2 -> V_7 ) ;
} else {
unsigned int V_60 ;
F_1 ( V_2 , 0 , V_32 ) ;
F_1 ( V_2 , ~ 0 , V_36 ) ;
F_1 ( V_2 , 0 , V_53 ) ;
F_3 ( V_2 -> V_10 , V_12 ) ;
V_2 -> V_5 -> V_55 ( V_2 -> V_7 ) ;
V_60 = V_40 | V_47 | V_49 |
V_45 ;
F_1 ( V_2 , V_60 , V_58 ) ;
F_1 ( V_2 , ~ V_60 , V_56 ) ;
F_1 ( V_2 , ~ V_60 , V_57 ) ;
}
return 0 ;
}
static void F_14 ( void * V_34 )
{
struct V_1 * V_2 = V_34 ;
F_15 ( V_2 -> V_10 ) ;
}
static int F_16 ( struct V_61 * V_62 )
{
struct V_63 * V_34 = F_17 ( & V_62 -> V_64 ) ;
struct V_1 * V_2 ;
int V_37 ;
if ( ! V_34 )
return - V_65 ;
V_2 = F_18 ( & V_62 -> V_64 , sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 )
return - V_67 ;
V_2 -> V_33 = V_34 -> V_33 ;
V_2 -> V_5 = V_34 -> V_5 ;
V_2 -> V_7 = V_34 -> V_7 ;
F_19 ( V_62 , V_2 ) ;
F_1 ( V_2 , 0 , V_30 ) ;
F_1 ( V_2 , ~ 0 , V_56 ) ;
F_1 ( V_2 , ~ 0 , V_57 ) ;
F_1 ( V_2 , 0 , V_58 ) ;
V_2 -> V_10 = F_20 ( & V_68 , V_2 , L_1 ,
V_69 | V_70 |
V_71 | V_72 ,
V_73 ) ;
if ( F_21 ( V_2 -> V_10 ) )
return F_22 ( V_2 -> V_10 ) ;
V_2 -> V_10 -> V_74 = V_75 ;
V_37 = F_23 ( & V_62 -> V_64 , F_14 , V_2 ) ;
if ( V_37 ) {
F_15 ( V_2 -> V_10 ) ;
return V_37 ;
}
V_37 = F_24 ( & V_62 -> V_64 , V_2 -> V_33 ,
F_7 ,
F_9 , V_76 ,
L_2 , V_2 -> V_10 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 -> V_77 = F_25 ( V_62 -> V_64 . V_78 ) ;
if ( ! V_2 -> V_77 )
return - V_67 ;
V_37 = F_26 ( V_2 -> V_10 , V_62 -> V_64 . V_78 ) ;
if ( V_37 < 0 ) {
F_27 ( V_2 -> V_77 ) ;
return V_37 ;
}
F_28 ( & V_62 -> V_64 , F_14 , V_2 ) ;
F_29 ( V_2 -> V_10 , V_2 -> V_77 ) ;
return 0 ;
}
static int F_30 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_31 ( V_62 ) ;
F_32 ( V_2 -> V_10 ) ;
F_27 ( V_2 -> V_77 ) ;
return 0 ;
}
