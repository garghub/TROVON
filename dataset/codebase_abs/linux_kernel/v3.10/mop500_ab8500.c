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
F_9 ( V_23 -> V_24 ) ;
V_21 -> V_25 . V_26 . V_27 [ 0 ] = V_8 -> V_2 ;
return 0 ;
}
static int F_10 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_8 ( V_19 ) ;
struct V_7 * V_8 =
F_9 ( V_23 -> V_24 ) ;
unsigned int V_28 = V_21 -> V_25 . V_26 . V_27 [ 0 ] ;
if ( V_28 > ( unsigned int ) V_4 )
return - V_17 ;
if ( V_8 -> V_2 == V_28 )
return 0 ;
V_8 -> V_2 = V_28 ;
return 1 ;
}
int F_11 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
return F_2 ( V_32 -> V_24 -> V_6 ,
F_9 ( V_32 -> V_24 ) ) ;
}
void F_12 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_5 * V_6 = V_32 -> V_24 -> V_6 ;
F_6 ( V_6 , L_8 , V_13 ) ;
if ( V_30 -> V_34 == V_35 )
V_36 = V_37 ;
else
V_38 = V_39 ;
}
int F_13 ( struct V_29 * V_30 ,
struct V_40 * V_41 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_42 * V_43 = V_32 -> V_43 ;
struct V_42 * V_44 = V_32 -> V_44 ;
struct V_5 * V_6 = V_32 -> V_24 -> V_6 ;
unsigned int V_45 ;
int V_46 , V_47 = 0 , V_48 , V_49 ;
unsigned int V_50 , V_51 ;
bool V_52 ;
F_6 ( V_6 , L_8 , V_13 ) ;
F_6 ( V_6 , L_9
L_10
L_11
L_12 ,
V_13 ,
V_30 -> V_53 -> V_54 ,
V_30 -> V_53 -> V_55 ,
V_30 -> V_54 ,
V_30 -> V_56 ) ;
V_46 = F_14 ( V_41 ) ;
switch ( F_15 ( V_41 ) ) {
case V_57 :
V_51 = 32 ;
break;
case V_58 :
V_51 = 16 ;
break;
default:
return - V_17 ;
}
if ( V_46 == 8 )
V_48 = V_59 ;
else
V_48 = V_60 ;
F_6 ( V_6 , L_13 , V_13 ,
( V_48 == V_60 ) ? L_14 : L_15 ) ;
if ( V_48 == V_60 ) {
V_45 = V_61 |
V_62 |
V_63 |
V_64 ;
} else {
V_45 = V_61 |
V_62 |
V_63 |
V_65 ;
}
V_47 = F_16 ( V_43 , V_45 ) ;
if ( V_47 < 0 ) {
F_4 ( V_6 ,
L_16 ,
V_13 , V_47 ) ;
return V_47 ;
}
V_47 = F_16 ( V_44 , V_45 ) ;
if ( V_47 < 0 ) {
F_4 ( V_6 ,
L_17 ,
V_13 , V_47 ) ;
return V_47 ;
}
V_52 = ( V_30 -> V_34 == V_35 ) ;
switch ( V_46 ) {
case 1 :
V_49 = 16 ;
V_36 = ( V_52 ) ? V_66 : 0 ;
V_38 = ( V_52 ) ? 0 : V_67 ;
break;
case 2 :
V_49 = 16 ;
V_36 = ( V_52 ) ? V_68 : 0 ;
V_38 = ( V_52 ) ? 0 : V_69 ;
break;
case 8 :
V_49 = 16 ;
V_36 = ( V_52 ) ? V_70 : 0 ;
V_38 = ( V_52 ) ? 0 : V_71 ;
break;
default:
return - V_17 ;
}
if ( V_48 == V_60 )
V_50 = V_51 ;
else
V_50 = 20 ;
F_6 ( V_6 , L_18 , V_13 ,
V_36 , V_38 ) ;
V_47 = F_17 ( V_44 , V_36 , V_38 , V_49 ,
V_51 ) ;
if ( V_47 )
return V_47 ;
F_6 ( V_6 , L_19 , V_13 ,
V_36 , V_38 ) ;
V_47 = F_17 ( V_43 , V_36 , V_38 , V_49 ,
V_50 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
int F_18 ( struct V_31 * V_32 )
{
struct V_22 * V_23 = V_32 -> V_23 ;
struct V_5 * V_6 = V_32 -> V_24 -> V_6 ;
struct V_7 * V_8 ;
int V_47 ;
F_6 ( V_6 , L_20 , V_13 ) ;
V_8 = F_19 ( V_6 , sizeof( struct V_7 ) ,
V_72 ) ;
F_20 ( V_32 -> V_24 , V_8 ) ;
V_8 -> V_15 = F_21 ( V_6 , L_21 ) ;
if ( F_3 ( V_8 -> V_15 ) )
F_22 ( V_6 , L_22 ,
V_13 ) ;
V_8 -> V_16 = F_21 ( V_6 , L_23 ) ;
if ( F_3 ( V_8 -> V_16 ) )
F_22 ( V_6 , L_24 ,
V_13 ) ;
V_8 -> V_12 = F_21 ( V_6 , L_25 ) ;
if ( F_3 ( V_8 -> V_12 ) )
F_22 ( V_6 , L_26 ,
V_13 ) ;
V_8 -> V_2 = V_4 ;
V_47 = F_2 ( V_6 , V_8 ) ;
if ( V_47 < 0 )
F_22 ( V_6 , L_27 ,
V_13 ) ;
V_8 -> V_2 = V_4 ;
V_47 = F_23 ( V_23 , V_73 ,
F_24 ( V_73 ) ) ;
if ( V_47 < 0 ) {
F_25 ( L_28 ,
V_13 , V_47 ) ;
return V_47 ;
}
V_47 = F_26 ( & V_23 -> V_74 , L_29 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_30 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_31 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_32 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_33 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_34 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_35 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_36 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_37 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_38 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_39 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_40 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_41 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_42 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_43 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_44 ) ;
V_47 |= F_26 ( & V_23 -> V_74 , L_45 ) ;
return V_47 ;
}
void F_27 ( struct V_75 * V_24 )
{
struct V_7 * V_8 = F_9 ( V_24 ) ;
if ( V_8 -> V_15 != NULL )
F_28 ( V_8 -> V_15 ) ;
if ( V_8 -> V_16 != NULL )
F_28 ( V_8 -> V_16 ) ;
if ( V_8 -> V_12 != NULL )
F_28 ( V_8 -> V_12 ) ;
F_20 ( V_24 , V_8 ) ;
}
