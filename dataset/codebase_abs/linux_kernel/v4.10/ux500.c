static void F_1 ( struct V_1 * V_1 , int V_2 )
{
T_1 V_3 ;
unsigned long V_4 = V_5 + F_2 ( 1000 ) ;
V_3 = F_3 ( V_1 -> V_6 , V_7 ) ;
if ( V_2 ) {
if ( V_1 -> V_8 -> V_9 -> V_10 == V_11 ) {
V_3 |= V_12 ;
F_4 ( V_1 -> V_6 , V_7 , V_3 ) ;
while ( F_3 ( V_1 -> V_6 , V_7 ) & 0x80 ) {
if ( F_5 ( V_5 , V_4 ) ) {
F_6 ( V_1 -> V_13 ,
L_1 ) ;
break;
}
}
} else {
V_1 -> V_14 = 1 ;
V_1 -> V_8 -> V_9 -> V_15 = 1 ;
V_1 -> V_8 -> V_9 -> V_10 = V_16 ;
V_3 |= V_12 ;
F_7 ( V_1 ) ;
}
} else {
V_1 -> V_14 = 0 ;
V_1 -> V_8 -> V_9 -> V_15 = 0 ;
V_3 &= ~ V_12 ;
F_8 ( V_1 ) ;
}
F_4 ( V_1 -> V_6 , V_7 , V_3 ) ;
if ( ! V_2 )
F_9 ( 200 ) ;
F_10 ( V_1 -> V_13 , L_2 ,
F_11 ( V_1 -> V_8 -> V_9 -> V_10 ) ,
F_3 ( V_1 -> V_6 , V_7 ) ) ;
}
static int F_12 ( struct V_17 * V_18 ,
unsigned long V_19 , void * V_20 )
{
struct V_1 * V_1 = F_13 ( V_18 , struct V_1 , V_18 ) ;
F_10 ( V_1 -> V_13 , L_3 ,
V_19 , F_11 ( V_1 -> V_8 -> V_9 -> V_10 ) ) ;
switch ( V_19 ) {
case V_21 :
F_10 ( V_1 -> V_13 , L_4 ) ;
F_1 ( V_1 , 1 ) ;
break;
case V_22 :
F_10 ( V_1 -> V_13 , L_5 ) ;
break;
case V_23 :
F_10 ( V_1 -> V_13 , L_6 ) ;
if ( F_14 ( V_1 ) )
F_1 ( V_1 , 0 ) ;
else
V_1 -> V_8 -> V_9 -> V_10 = V_24 ;
break;
default:
F_10 ( V_1 -> V_13 , L_7 ) ;
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
F_10 ( V_1 -> V_13 , L_9 ) ;
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
struct V_44 * V_49 = F_32 ( & V_46 -> V_51 ) ;
struct V_47 * V_48 = V_46 -> V_51 . V_58 ;
struct V_45 * V_1 ;
struct V_59 * V_60 ;
struct V_61 * V_61 ;
int V_62 = - V_63 ;
if ( ! V_49 ) {
if ( V_48 ) {
V_49 = F_28 ( V_46 , V_48 ) ;
if ( ! V_49 )
goto V_64;
V_46 -> V_51 . V_65 = V_49 ;
} else {
F_6 ( & V_46 -> V_51 , L_15 ) ;
goto V_64;
}
}
V_60 = F_29 ( & V_46 -> V_51 , sizeof( * V_60 ) , V_52 ) ;
if ( ! V_60 )
goto V_64;
V_1 = F_33 ( L_16 , V_66 ) ;
if ( ! V_1 ) {
F_6 ( & V_46 -> V_51 , L_17 ) ;
goto V_64;
}
V_61 = F_34 ( & V_46 -> V_51 , NULL ) ;
if ( F_35 ( V_61 ) ) {
F_6 ( & V_46 -> V_51 , L_18 ) ;
V_62 = F_36 ( V_61 ) ;
goto V_67;
}
V_62 = F_37 ( V_61 ) ;
if ( V_62 ) {
F_6 ( & V_46 -> V_51 , L_19 ) ;
goto V_67;
}
V_1 -> V_51 . V_68 = & V_46 -> V_51 ;
V_1 -> V_51 . V_69 = & V_46 -> V_51 . V_70 ;
V_1 -> V_51 . V_70 = V_46 -> V_51 . V_70 ;
V_60 -> V_51 = & V_46 -> V_51 ;
V_60 -> V_1 = V_1 ;
V_60 -> V_61 = V_61 ;
V_49 -> V_71 = & V_72 ;
V_49 -> V_73 = & V_74 ;
F_38 ( V_46 , V_60 ) ;
memset ( V_57 , 0x00 , sizeof( * V_57 ) *
F_39 ( V_57 ) ) ;
V_57 [ 0 ] . V_75 = V_46 -> V_56 [ 0 ] . V_75 ;
V_57 [ 0 ] . V_76 = V_46 -> V_56 [ 0 ] . V_76 ;
V_57 [ 0 ] . V_77 = V_46 -> V_56 [ 0 ] . V_77 ;
V_57 [ 0 ] . V_29 = V_46 -> V_56 [ 0 ] . V_29 ;
V_57 [ 1 ] . V_75 = V_46 -> V_56 [ 1 ] . V_75 ;
V_57 [ 1 ] . V_76 = V_46 -> V_56 [ 1 ] . V_76 ;
V_57 [ 1 ] . V_77 = V_46 -> V_56 [ 1 ] . V_77 ;
V_57 [ 1 ] . V_29 = V_46 -> V_56 [ 1 ] . V_29 ;
V_62 = F_40 ( V_1 , V_57 ,
F_39 ( V_57 ) ) ;
if ( V_62 ) {
F_6 ( & V_46 -> V_51 , L_20 ) ;
goto V_78;
}
V_62 = F_41 ( V_1 , V_49 , sizeof( * V_49 ) ) ;
if ( V_62 ) {
F_6 ( & V_46 -> V_51 , L_21 ) ;
goto V_78;
}
V_62 = F_42 ( V_1 ) ;
if ( V_62 ) {
F_6 ( & V_46 -> V_51 , L_22 ) ;
goto V_78;
}
return 0 ;
V_78:
F_43 ( V_61 ) ;
V_67:
F_44 ( V_1 ) ;
V_64:
return V_62 ;
}
static int F_45 ( struct V_45 * V_46 )
{
struct V_59 * V_60 = F_46 ( V_46 ) ;
F_47 ( V_60 -> V_1 ) ;
F_43 ( V_60 -> V_61 ) ;
return 0 ;
}
static int F_48 ( struct V_79 * V_51 )
{
struct V_59 * V_60 = F_49 ( V_51 ) ;
struct V_1 * V_1 = F_50 ( V_60 ) ;
if ( V_1 )
F_51 ( V_1 -> V_8 , 1 ) ;
F_43 ( V_60 -> V_61 ) ;
return 0 ;
}
static int F_52 ( struct V_79 * V_51 )
{
struct V_59 * V_60 = F_49 ( V_51 ) ;
struct V_1 * V_1 = F_50 ( V_60 ) ;
int V_62 ;
V_62 = F_37 ( V_60 -> V_61 ) ;
if ( V_62 ) {
F_6 ( V_51 , L_19 ) ;
return V_62 ;
}
if ( V_1 )
F_51 ( V_1 -> V_8 , 0 ) ;
return 0 ;
}
