static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_4 = ( ( V_6 -> V_7 & 0x01 ) << 2 ) | ( V_6 -> V_8 & 0x03 ) ;
V_3 = F_2 ( V_2 -> V_9 , V_10 , 0x07 , V_4 ) ;
if ( V_3 < 0 )
goto V_11;
V_4 = ( ( V_6 -> V_12 & 0x01 ) << 1 ) |
( V_6 -> V_13 & 0x07 ) ;
V_3 = F_2 ( V_2 -> V_9 , V_14 , 0x07 , V_4 ) ;
if ( V_3 < 0 )
goto V_11;
V_3 = F_2 ( V_2 -> V_9 , V_14 , 0x80 , 0x00 ) ;
if ( V_3 < 0 )
goto V_11;
if ( V_6 -> V_13 != V_15 ) {
V_3 = F_3 ( V_2 -> V_9 ,
V_16 , V_6 -> V_17 ) ;
if ( V_3 < 0 )
goto V_11;
}
if ( V_6 -> V_12 != V_18 ) {
V_3 = F_3 ( V_2 -> V_9 ,
V_19 , V_6 -> V_20 ) ;
if ( V_3 < 0 )
goto V_11;
}
return V_3 ;
V_11:
F_4 ( V_2 -> V_21 , L_1 ) ;
return V_3 ;
}
static void F_5 ( struct V_22 * V_23 )
{
int V_3 ;
unsigned int V_4 ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_23 , struct V_1 , V_23 . V_23 ) ;
V_3 = F_7 ( V_2 -> V_9 , V_24 , & V_4 ) ;
if ( V_3 < 0 ) {
F_4 ( V_2 -> V_21 ,
L_2 ) ;
return;
}
F_8 ( V_2 -> V_21 , L_3 , V_4 ) ;
}
static T_1 F_9 ( int V_25 , void * V_26 )
{
int V_3 ;
struct V_1 * V_2 = V_26 ;
unsigned long V_27 = F_10 ( V_28 ) ;
F_11 ( V_2 -> V_29 , & V_2 -> V_23 , V_27 ) ;
V_3 = F_2 ( V_2 -> V_9 , V_14 , 0x80 , 0x00 ) ;
if ( V_3 < 0 )
goto V_11;
return V_30 ;
V_11:
F_4 ( V_2 -> V_21 , L_1 ) ;
return V_30 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_23 , F_5 ) ;
V_2 -> V_29 = F_14 ( L_4 ) ;
if ( ! V_2 -> V_29 ) {
F_4 ( V_2 -> V_21 , L_5 ) ;
return - 1 ;
}
if ( F_15
( V_2 -> V_25 , NULL , F_9 ,
V_31 | V_32 , L_6 , V_2 ) ) {
F_4 ( V_2 -> V_21 , L_7 ) ;
return - 1 ;
}
return 0 ;
}
static bool
F_16 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 -> V_35 )
return false ;
V_2 -> V_6 -> V_35 ( V_34 -> V_36 . V_37 - 1 ,
V_2 -> V_6 -> V_38 ) ;
return true ;
}
static int F_17 ( struct V_33 * V_34 )
{
int V_3 ;
struct V_1 * V_2 = F_18 ( V_34 ) ;
enum V_39 V_8 = V_2 -> V_6 -> V_8 ;
if ( ! V_34 -> V_36 . V_37 ) {
V_3 = F_2 ( V_2 -> V_9 , V_14 , 0x04 , 0x00 ) ;
if ( V_3 < 0 )
goto V_11;
return V_34 -> V_36 . V_37 ;
}
if ( V_8 == V_40 || V_8 == V_41 ) {
if ( ! F_16 ( V_34 , V_2 ) )
F_4 ( V_2 -> V_21 , L_8 ) ;
} else {
V_3 = F_2 ( V_2 -> V_9 , V_14 , 0x80 , 0x00 ) ;
if ( V_3 < 0 )
goto V_11;
F_19 ( 1 ) ;
V_3 = F_3 ( V_2 -> V_9 ,
V_16 , V_34 -> V_36 . V_37 - 1 ) ;
if ( V_3 < 0 )
goto V_11;
}
return V_34 -> V_36 . V_37 ;
V_11:
F_4 ( V_2 -> V_21 , L_9 ) ;
return V_34 -> V_36 . V_37 ;
}
static int F_20 ( struct V_33 * V_34 )
{
unsigned int V_4 ;
int V_37 , V_3 ;
struct V_1 * V_2 = F_18 ( V_34 ) ;
enum V_39 V_8 = V_2 -> V_6 -> V_8 ;
if ( V_8 == V_40 || V_8 == V_41 ) {
V_3 = F_7 ( V_2 -> V_9 , V_42 , & V_4 ) ;
if ( V_3 < 0 )
goto V_11;
V_37 = V_4 & 0x01 ;
V_3 = F_7 ( V_2 -> V_9 , V_43 , & V_4 ) ;
if ( V_3 < 0 )
goto V_11;
V_37 = ( ( V_37 << 8 ) | V_4 ) + 1 ;
} else {
V_3 = F_2 ( V_2 -> V_9 , V_14 , 0x80 , 0x00 ) ;
if ( V_3 < 0 )
goto V_11;
F_19 ( 1 ) ;
V_3 = F_7 ( V_2 -> V_9 , V_16 , & V_4 ) ;
if ( V_3 < 0 )
goto V_11;
V_37 = V_4 + 1 ;
}
V_34 -> V_36 . V_37 = V_37 ;
return V_34 -> V_36 . V_37 ;
V_11:
F_4 ( V_2 -> V_21 , L_1 ) ;
return 0 ;
}
static int F_21 ( struct V_33 * V_34 )
{
int V_3 ;
struct V_1 * V_2 = F_18 ( V_34 ) ;
enum V_39 V_8 = V_2 -> V_6 -> V_8 ;
if ( V_8 == V_44 || V_8 == V_41 ) {
if ( ! F_16 ( V_34 , V_2 ) )
F_4 ( V_2 -> V_21 ,
L_10 ) ;
} else {
V_3 = F_2 ( V_2 -> V_9 , V_14 , 0x80 , 0x00 ) ;
if ( V_3 < 0 )
goto V_11;
F_19 ( 1 ) ;
V_3 = F_3 ( V_2 -> V_9 ,
V_19 , V_34 -> V_36 . V_37 - 1 ) ;
}
return V_34 -> V_36 . V_37 ;
V_11:
F_4 ( V_2 -> V_21 , L_1 ) ;
return V_34 -> V_36 . V_37 ;
}
static int F_22 ( struct V_33 * V_34 )
{
unsigned int V_4 ;
int V_37 , V_3 ;
struct V_1 * V_2 = F_18 ( V_34 ) ;
enum V_39 V_8 = V_2 -> V_6 -> V_8 ;
if ( V_8 == V_44 || V_8 == V_41 ) {
V_3 = F_7 ( V_2 -> V_9 , V_42 , & V_4 ) ;
if ( V_3 < 0 )
goto V_11;
V_37 = V_4 & 0x01 ;
V_3 = F_7 ( V_2 -> V_9 , V_43 , & V_4 ) ;
if ( V_3 < 0 )
goto V_11;
V_37 = ( ( V_37 << 8 ) | V_4 ) + 1 ;
} else {
V_3 = F_2 ( V_2 -> V_9 , V_14 , 0x80 , 0x00 ) ;
if ( V_3 < 0 )
goto V_11;
F_19 ( 1 ) ;
V_3 = F_7 ( V_2 -> V_9 , V_19 , & V_4 ) ;
if ( V_3 < 0 )
goto V_11;
V_37 = V_4 + 1 ;
}
V_34 -> V_36 . V_37 = V_37 ;
return V_34 -> V_36 . V_37 ;
V_11:
F_4 ( V_2 -> V_21 , L_1 ) ;
return V_34 -> V_36 . V_37 ;
}
static int F_23 ( struct V_1 * V_2 ,
enum V_45 V_46 )
{
const char * V_47 = V_48 [ V_46 ] ;
struct V_49 V_36 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_36 . type = V_50 ;
switch ( V_46 ) {
case V_51 :
case V_52 :
V_36 . V_37 = V_6 -> V_17 ;
V_36 . V_53 = V_6 -> V_54 ;
V_2 -> V_55 =
F_24 ( V_47 , V_2 -> V_21 , V_2 ,
& V_56 , & V_36 ) ;
if ( F_25 ( V_2 -> V_55 ) )
return F_26 ( V_2 -> V_55 ) ;
break;
case V_57 :
V_36 . V_37 = V_6 -> V_20 ;
V_36 . V_53 = V_6 -> V_58 ;
V_2 -> V_59 =
F_24 ( V_47 , V_2 -> V_21 , V_2 ,
& V_60 , & V_36 ) ;
if ( F_25 ( V_2 -> V_59 ) )
return F_26 ( V_2 -> V_59 ) ;
break;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_55 )
F_28 ( V_2 -> V_55 ) ;
if ( V_2 -> V_59 )
F_28 ( V_2 -> V_59 ) ;
}
static int F_29 ( struct V_61 * V_62 ,
const struct V_63 * V_64 )
{
struct V_5 * V_6 = V_62 -> V_21 . V_65 ;
struct V_1 * V_2 ;
int V_3 ;
if ( ! F_30 ( V_62 -> V_66 , V_67 ) ) {
F_4 ( & V_62 -> V_21 , L_11 ) ;
return - V_68 ;
}
if ( V_6 == NULL ) {
F_4 ( & V_62 -> V_21 , L_12 ) ;
return - V_69 ;
}
V_2 = F_31 ( & V_62 -> V_21 , sizeof( struct V_1 ) ,
V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_21 = & V_62 -> V_21 ;
V_2 -> V_9 = F_32 ( V_62 , & V_72 ) ;
if ( F_25 ( V_2 -> V_9 ) ) {
V_3 = F_26 ( V_2 -> V_9 ) ;
F_4 ( & V_62 -> V_21 , L_13 ,
V_3 ) ;
return V_3 ;
}
F_33 ( V_62 , V_2 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_62 -> V_21 , L_14 ) ;
goto V_73;
}
switch ( V_6 -> V_13 ) {
case V_74 :
V_3 = F_23 ( V_2 , V_52 ) ;
V_6 -> V_12 = V_18 ;
break;
case V_75 :
V_3 = F_23 ( V_2 , V_51 ) ;
break;
case V_76 :
V_3 = F_23 ( V_2 , V_57 ) ;
V_6 -> V_12 = V_18 ;
break;
default:
break;
}
if ( V_3 < 0 )
goto V_77;
if ( V_6 -> V_12 && V_2 -> V_59 == NULL ) {
V_3 = F_23 ( V_2 , V_57 ) ;
if ( V_3 < 0 )
goto V_77;
}
V_2 -> V_25 = V_62 -> V_25 ;
if ( V_2 -> V_25 )
F_12 ( V_2 ) ;
F_8 ( & V_62 -> V_21 , L_15 ) ;
return 0 ;
V_77:
F_4 ( & V_62 -> V_21 , L_16 ) ;
F_27 ( V_2 ) ;
V_73:
return V_3 ;
}
static int F_34 ( struct V_61 * V_62 )
{
int V_3 ;
struct V_1 * V_2 = F_35 ( V_62 ) ;
V_3 = F_3 ( V_2 -> V_9 , V_16 , 0 ) ;
if ( V_3 < 0 )
F_4 ( V_2 -> V_21 , L_1 ) ;
V_3 = F_3 ( V_2 -> V_9 , V_19 , 0 ) ;
if ( V_3 < 0 )
F_4 ( V_2 -> V_21 , L_1 ) ;
F_27 ( V_2 ) ;
if ( V_2 -> V_25 ) {
F_36 ( V_2 -> V_25 , V_2 ) ;
F_37 ( V_2 -> V_29 ) ;
F_38 ( V_2 -> V_29 ) ;
}
return 0 ;
}
