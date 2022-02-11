static inline const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
default:
return L_3 ;
}
}
static int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
int V_9 ;
struct V_10 * V_11 ;
if ( F_3 ( V_8 -> V_12 ) ) {
F_4 ( V_6 ,
L_4 , V_13 ) ;
return - V_14 ;
}
switch ( V_8 -> V_2 ) {
case V_3 :
V_11 = V_8 -> V_15 ;
break;
case V_4 :
V_11 = V_8 -> V_16 ;
break;
default:
return - V_17 ;
}
if ( F_3 ( V_11 ) ) {
F_4 ( V_6 , L_5 , V_13 ,
F_1 ( V_8 -> V_2 ) ) ;
return - V_14 ;
}
V_9 = F_5 ( V_8 -> V_12 , V_11 ) ;
if ( V_9 )
F_4 ( V_6 ,
L_6 ,
V_13 , F_1 ( V_8 -> V_2 ) , V_9 ) ;
else
F_6 ( V_6 ,
L_7 ,
V_13 , F_1 ( V_8 -> V_2 ) ) ;
return V_9 ;
}
static int F_7 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_8 ( V_19 ) ;
struct V_7 * V_8 =
F_9 ( V_23 ) ;
V_21 -> V_24 . V_25 . V_26 [ 0 ] = V_8 -> V_2 ;
return 0 ;
}
static int F_10 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_8 ( V_19 ) ;
struct V_7 * V_8 =
F_9 ( V_23 ) ;
unsigned int V_27 = V_21 -> V_24 . V_25 . V_26 [ 0 ] ;
if ( V_27 > ( unsigned int ) V_4 )
return - V_17 ;
if ( V_8 -> V_2 == V_27 )
return 0 ;
V_8 -> V_2 = V_27 ;
return 1 ;
}
static int F_11 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_32 ;
return F_2 ( V_31 -> V_23 -> V_6 ,
F_9 ( V_31 -> V_23 ) ) ;
}
static void F_12 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_32 ;
struct V_5 * V_6 = V_31 -> V_23 -> V_6 ;
F_6 ( V_6 , L_8 , V_13 ) ;
if ( V_29 -> V_33 == V_34 )
V_35 = V_36 ;
else
V_37 = V_38 ;
}
static int F_13 ( struct V_28 * V_29 ,
struct V_39 * V_40 )
{
struct V_30 * V_31 = V_29 -> V_32 ;
struct V_41 * V_42 = V_31 -> V_42 ;
struct V_41 * V_43 = V_31 -> V_43 ;
struct V_5 * V_6 = V_31 -> V_23 -> V_6 ;
unsigned int V_44 ;
int V_45 , V_46 = 0 , V_47 , V_48 ;
unsigned int V_49 , V_50 ;
bool V_51 ;
F_6 ( V_6 , L_8 , V_13 ) ;
F_6 ( V_6 , L_9
L_10
L_11
L_12 ,
V_13 ,
V_29 -> V_52 -> V_53 ,
V_29 -> V_52 -> V_54 ,
V_29 -> V_53 ,
V_29 -> V_55 ) ;
F_14 ( & V_56 ) ;
if ( V_57 ) {
if ( V_58 != F_15 ( V_40 ) ||
V_59 != F_16 ( V_40 ) ) {
F_17 ( & V_56 ) ;
return - V_60 ;
}
} else {
V_58 = F_15 ( V_40 ) ;
V_59 = F_16 ( V_40 ) ;
}
F_18 ( V_43 -> V_54 , & V_57 ) ;
F_17 ( & V_56 ) ;
V_45 = F_16 ( V_40 ) ;
switch ( F_19 ( V_40 ) ) {
case V_61 :
V_50 = 32 ;
break;
case V_62 :
V_50 = 16 ;
break;
default:
return - V_17 ;
}
if ( V_45 == 8 )
V_47 = V_63 ;
else
V_47 = V_64 ;
F_6 ( V_6 , L_13 , V_13 ,
( V_47 == V_64 ) ? L_14 : L_15 ) ;
if ( V_47 == V_64 ) {
V_44 = V_65 |
V_66 |
V_67 |
V_68 ;
} else {
V_44 = V_65 |
V_66 |
V_67 |
V_69 ;
}
V_46 = F_20 ( V_42 , V_44 ) ;
if ( V_46 < 0 ) {
F_4 ( V_6 ,
L_16 ,
V_13 , V_46 ) ;
return V_46 ;
}
V_46 = F_20 ( V_43 , V_44 ) ;
if ( V_46 < 0 ) {
F_4 ( V_6 ,
L_17 ,
V_13 , V_46 ) ;
return V_46 ;
}
V_51 = ( V_29 -> V_33 == V_34 ) ;
switch ( V_45 ) {
case 1 :
V_48 = 16 ;
V_35 = ( V_51 ) ? V_70 : 0 ;
V_37 = ( V_51 ) ? 0 : V_71 ;
break;
case 2 :
V_48 = 16 ;
V_35 = ( V_51 ) ? V_72 : 0 ;
V_37 = ( V_51 ) ? 0 : V_73 ;
break;
case 8 :
V_48 = 16 ;
V_35 = ( V_51 ) ? V_74 : 0 ;
V_37 = ( V_51 ) ? 0 : V_75 ;
break;
default:
return - V_17 ;
}
if ( V_47 == V_64 )
V_49 = V_50 ;
else
V_49 = 20 ;
F_6 ( V_6 , L_18 , V_13 ,
V_35 , V_37 ) ;
V_46 = F_21 ( V_43 , V_35 , V_37 , V_48 ,
V_50 ) ;
if ( V_46 )
return V_46 ;
F_6 ( V_6 , L_19 , V_13 ,
V_35 , V_37 ) ;
V_46 = F_21 ( V_42 , V_35 , V_37 , V_48 ,
V_49 ) ;
if ( V_46 )
return V_46 ;
return 0 ;
}
static int F_22 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_32 ;
struct V_41 * V_43 = V_31 -> V_43 ;
F_14 ( & V_56 ) ;
F_23 ( V_43 -> V_54 , & V_57 ) ;
F_17 ( & V_56 ) ;
return 0 ;
}
int F_24 ( struct V_30 * V_31 )
{
struct V_76 * V_77 = V_31 -> V_77 ;
struct V_5 * V_6 = V_31 -> V_23 -> V_6 ;
struct V_7 * V_8 ;
int V_46 ;
F_6 ( V_6 , L_20 , V_13 ) ;
V_8 = F_25 ( V_6 , sizeof( struct V_7 ) ,
V_78 ) ;
F_26 ( V_31 -> V_23 , V_8 ) ;
V_8 -> V_15 = F_27 ( V_6 , L_21 ) ;
if ( F_3 ( V_8 -> V_15 ) )
F_28 ( V_6 , L_22 ,
V_13 ) ;
V_8 -> V_16 = F_27 ( V_6 , L_23 ) ;
if ( F_3 ( V_8 -> V_16 ) )
F_28 ( V_6 , L_24 ,
V_13 ) ;
V_8 -> V_12 = F_27 ( V_6 , L_25 ) ;
if ( F_3 ( V_8 -> V_12 ) )
F_28 ( V_6 , L_26 ,
V_13 ) ;
V_8 -> V_2 = V_4 ;
V_46 = F_2 ( V_6 , V_8 ) ;
if ( V_46 < 0 )
F_28 ( V_6 , L_27 ,
V_13 ) ;
V_8 -> V_2 = V_4 ;
V_46 = F_29 ( V_77 -> V_23 , V_79 ,
F_30 ( V_79 ) ) ;
if ( V_46 < 0 ) {
F_31 ( L_28 ,
V_13 , V_46 ) ;
return V_46 ;
}
V_46 = F_32 ( & V_77 -> V_80 , L_29 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_30 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_31 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_32 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_33 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_34 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_35 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_36 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_37 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_38 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_39 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_40 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_41 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_42 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_43 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_44 ) ;
V_46 |= F_32 ( & V_77 -> V_80 , L_45 ) ;
return V_46 ;
}
void F_33 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = F_9 ( V_23 ) ;
if ( V_8 -> V_15 != NULL )
F_34 ( V_8 -> V_15 ) ;
if ( V_8 -> V_16 != NULL )
F_34 ( V_8 -> V_16 ) ;
if ( V_8 -> V_12 != NULL )
F_34 ( V_8 -> V_12 ) ;
F_26 ( V_23 , V_8 ) ;
}
