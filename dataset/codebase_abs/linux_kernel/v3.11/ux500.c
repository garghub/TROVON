static void F_1 ( struct V_1 * V_1 , int V_2 )
{
T_1 V_3 ;
unsigned long V_4 = V_5 + F_2 ( 1000 ) ;
V_3 = F_3 ( V_1 -> V_6 , V_7 ) ;
if ( V_2 ) {
if ( V_1 -> V_8 -> V_9 == V_10 ) {
V_3 |= V_11 ;
F_4 ( V_1 -> V_6 , V_7 , V_3 ) ;
while ( F_3 ( V_1 -> V_6 , V_7 ) & 0x80 ) {
if ( F_5 ( V_5 , V_4 ) ) {
F_6 ( V_1 -> V_12 ,
L_1 ) ;
break;
}
}
} else {
V_1 -> V_13 = 1 ;
V_1 -> V_8 -> V_14 -> V_15 = 1 ;
V_1 -> V_8 -> V_9 = V_16 ;
V_3 |= V_11 ;
F_7 ( V_1 ) ;
}
} else {
V_1 -> V_13 = 0 ;
V_1 -> V_8 -> V_14 -> V_15 = 0 ;
V_3 &= ~ V_11 ;
F_8 ( V_1 ) ;
}
F_4 ( V_1 -> V_6 , V_7 , V_3 ) ;
if ( ! V_2 )
F_9 ( 200 ) ;
F_10 ( V_1 -> V_12 , L_2 ,
F_11 ( V_1 -> V_8 -> V_9 ) ,
F_3 ( V_1 -> V_6 , V_7 ) ) ;
}
static int F_12 ( struct V_17 * V_18 ,
unsigned long V_19 , void * V_20 )
{
struct V_1 * V_1 = F_13 ( V_18 , struct V_1 , V_18 ) ;
F_10 ( V_1 -> V_12 , L_3 ,
V_19 , F_11 ( V_1 -> V_8 -> V_9 ) ) ;
switch ( V_19 ) {
case V_21 :
F_10 ( V_1 -> V_12 , L_4 ) ;
F_1 ( V_1 , 1 ) ;
break;
case V_22 :
F_10 ( V_1 -> V_12 , L_5 ) ;
break;
case V_23 :
F_10 ( V_1 -> V_12 , L_6 ) ;
if ( F_14 ( V_1 ) )
F_1 ( V_1 , 0 ) ;
else
V_1 -> V_8 -> V_9 = V_24 ;
break;
default:
F_10 ( V_1 -> V_12 , L_7 ) ;
return V_25 ;
}
return V_26 ;
}
static T_2 F_15 ( int V_27 , void * V_28 )
{
unsigned long V_29 ;
T_2 V_30 = V_31 ;
struct V_1 * V_1 = V_28 ;
F_16 ( & V_1 -> V_32 , V_29 ) ;
V_1 -> V_33 = F_3 ( V_1 -> V_6 , V_34 ) ;
V_1 -> V_35 = F_17 ( V_1 -> V_6 , V_36 ) ;
V_1 -> V_37 = F_17 ( V_1 -> V_6 , V_38 ) ;
if ( V_1 -> V_33 || V_1 -> V_35 || V_1 -> V_37 )
V_30 = F_18 ( V_1 ) ;
F_19 ( & V_1 -> V_32 , V_29 ) ;
return V_30 ;
}
static int F_20 ( struct V_1 * V_1 )
{
int V_39 ;
V_1 -> V_8 = F_21 ( V_40 ) ;
if ( F_22 ( V_1 -> V_8 ) ) {
F_23 ( L_8 ) ;
return - V_41 ;
}
V_1 -> V_18 . V_42 = F_12 ;
V_39 = F_24 ( V_1 -> V_8 , & V_1 -> V_18 ) ;
if ( V_39 < 0 ) {
F_10 ( V_1 -> V_12 , L_9 ) ;
return V_39 ;
}
V_1 -> V_43 = F_15 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
F_26 ( V_1 -> V_8 , & V_1 -> V_18 ) ;
F_27 ( V_1 -> V_8 ) ;
return 0 ;
}
static struct V_44 *
F_28 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
struct V_44 * V_49 ;
const char * V_50 ;
int strlen ;
V_49 = F_29 ( & V_46 -> V_51 , sizeof( * V_49 ) , V_52 ) ;
if ( ! V_49 )
return NULL ;
V_50 = F_30 ( V_48 , L_10 , & strlen ) ;
if ( ! V_50 ) {
F_6 ( & V_46 -> V_51 , L_11 ) ;
return NULL ;
}
if ( strlen > 0 ) {
if ( ! strcmp ( V_50 , L_12 ) )
V_49 -> V_50 = V_53 ;
if ( ! strcmp ( V_50 , L_13 ) )
V_49 -> V_50 = V_54 ;
if ( ! strcmp ( V_50 , L_14 ) )
V_49 -> V_50 = V_55 ;
}
return V_49 ;
}
static int F_31 ( struct V_45 * V_46 )
{
struct V_56 V_57 [ 2 ] ;
struct V_44 * V_49 = V_46 -> V_51 . V_58 ;
struct V_47 * V_48 = V_46 -> V_51 . V_59 ;
struct V_45 * V_1 ;
struct V_60 * V_61 ;
struct V_62 * V_62 ;
int V_63 = - V_64 ;
if ( ! V_49 ) {
if ( V_48 ) {
V_49 = F_28 ( V_46 , V_48 ) ;
if ( ! V_49 )
goto V_65;
V_46 -> V_51 . V_58 = V_49 ;
} else {
F_6 ( & V_46 -> V_51 , L_15 ) ;
goto V_65;
}
}
V_61 = F_32 ( sizeof( * V_61 ) , V_52 ) ;
if ( ! V_61 ) {
F_6 ( & V_46 -> V_51 , L_16 ) ;
goto V_65;
}
V_1 = F_33 ( L_17 , V_66 ) ;
if ( ! V_1 ) {
F_6 ( & V_46 -> V_51 , L_18 ) ;
goto V_67;
}
V_62 = F_34 ( & V_46 -> V_51 , L_19 ) ;
if ( F_35 ( V_62 ) ) {
F_6 ( & V_46 -> V_51 , L_20 ) ;
V_63 = F_36 ( V_62 ) ;
goto V_68;
}
V_63 = F_37 ( V_62 ) ;
if ( V_63 ) {
F_6 ( & V_46 -> V_51 , L_21 ) ;
goto V_69;
}
V_1 -> V_51 . V_70 = & V_46 -> V_51 ;
V_1 -> V_51 . V_71 = & V_46 -> V_51 . V_72 ;
V_1 -> V_51 . V_72 = V_46 -> V_51 . V_72 ;
V_1 -> V_51 . V_59 = V_46 -> V_51 . V_59 ;
V_61 -> V_51 = & V_46 -> V_51 ;
V_61 -> V_1 = V_1 ;
V_61 -> V_62 = V_62 ;
V_49 -> V_73 = & V_74 ;
V_49 -> V_75 = & V_76 ;
F_38 ( V_46 , V_61 ) ;
memset ( V_57 , 0x00 , sizeof( * V_57 ) *
F_39 ( V_57 ) ) ;
V_57 [ 0 ] . V_77 = V_46 -> V_56 [ 0 ] . V_77 ;
V_57 [ 0 ] . V_78 = V_46 -> V_56 [ 0 ] . V_78 ;
V_57 [ 0 ] . V_79 = V_46 -> V_56 [ 0 ] . V_79 ;
V_57 [ 0 ] . V_29 = V_46 -> V_56 [ 0 ] . V_29 ;
V_57 [ 1 ] . V_77 = V_46 -> V_56 [ 1 ] . V_77 ;
V_57 [ 1 ] . V_78 = V_46 -> V_56 [ 1 ] . V_78 ;
V_57 [ 1 ] . V_79 = V_46 -> V_56 [ 1 ] . V_79 ;
V_57 [ 1 ] . V_29 = V_46 -> V_56 [ 1 ] . V_29 ;
V_63 = F_40 ( V_1 , V_57 ,
F_39 ( V_57 ) ) ;
if ( V_63 ) {
F_6 ( & V_46 -> V_51 , L_22 ) ;
goto V_80;
}
V_63 = F_41 ( V_1 , V_49 , sizeof( * V_49 ) ) ;
if ( V_63 ) {
F_6 ( & V_46 -> V_51 , L_23 ) ;
goto V_80;
}
V_63 = F_42 ( V_1 ) ;
if ( V_63 ) {
F_6 ( & V_46 -> V_51 , L_24 ) ;
goto V_80;
}
return 0 ;
V_80:
F_43 ( V_62 ) ;
V_69:
F_44 ( V_62 ) ;
V_68:
F_45 ( V_1 ) ;
V_67:
F_46 ( V_61 ) ;
V_65:
return V_63 ;
}
static int F_47 ( struct V_45 * V_46 )
{
struct V_60 * V_61 = F_48 ( V_46 ) ;
F_49 ( V_61 -> V_1 ) ;
F_43 ( V_61 -> V_62 ) ;
F_44 ( V_61 -> V_62 ) ;
F_46 ( V_61 ) ;
return 0 ;
}
static int F_50 ( struct V_81 * V_51 )
{
struct V_60 * V_61 = F_51 ( V_51 ) ;
struct V_1 * V_1 = F_52 ( V_61 ) ;
F_53 ( V_1 -> V_8 , 1 ) ;
F_43 ( V_61 -> V_62 ) ;
return 0 ;
}
static int F_54 ( struct V_81 * V_51 )
{
struct V_60 * V_61 = F_51 ( V_51 ) ;
struct V_1 * V_1 = F_52 ( V_61 ) ;
int V_63 ;
V_63 = F_37 ( V_61 -> V_62 ) ;
if ( V_63 ) {
F_6 ( V_51 , L_21 ) ;
return V_63 ;
}
F_53 ( V_1 -> V_8 , 0 ) ;
return 0 ;
}
