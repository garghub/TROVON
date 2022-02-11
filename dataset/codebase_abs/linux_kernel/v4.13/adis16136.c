static T_1 F_1 ( struct V_1 * V_1 ,
char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_5 = V_1 -> V_6 ;
T_5 V_7 , V_8 , V_9 , V_10 ;
char V_11 [ 20 ] ;
T_3 V_12 ;
int V_13 ;
V_13 = F_2 ( & V_5 -> V_14 , V_15 ,
& V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_2 ( & V_5 -> V_14 , V_16 , & V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_2 ( & V_5 -> V_14 , V_17 , & V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_2 ( & V_5 -> V_14 , V_18 , & V_9 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 = snprintf ( V_11 , sizeof( V_11 ) , L_1 , V_7 , V_8 ,
V_9 , V_10 ) ;
return F_3 ( V_2 , V_3 , V_4 , V_11 , V_12 ) ;
}
static int F_4 ( void * V_19 , T_6 * V_20 )
{
struct V_5 * V_5 = V_19 ;
T_7 V_21 ;
int V_13 ;
V_13 = F_2 ( & V_5 -> V_14 , V_22 ,
& V_21 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_20 = V_21 ;
return 0 ;
}
static int F_5 ( void * V_19 , T_6 * V_20 )
{
struct V_5 * V_5 = V_19 ;
T_5 V_23 ;
int V_13 ;
V_13 = F_2 ( & V_5 -> V_14 , V_24 ,
& V_23 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_20 = V_23 ;
return 0 ;
}
static int F_6 ( struct V_25 * V_26 )
{
struct V_5 * V_5 = F_7 ( V_26 ) ;
F_8 ( L_2 , 0400 , V_26 -> V_27 ,
V_5 , & V_28 ) ;
F_8 ( L_3 , 0400 , V_26 -> V_27 ,
V_5 , & V_29 ) ;
F_8 ( L_4 , 0400 , V_26 -> V_27 ,
V_5 , & V_30 ) ;
return 0 ;
}
static int F_6 ( struct V_25 * V_26 )
{
return 0 ;
}
static int F_9 ( struct V_5 * V_5 , unsigned int V_31 )
{
unsigned int V_32 ;
V_32 = 32768 / V_31 ;
if ( V_32 < 0xf )
V_32 = 0xf ;
else if ( V_32 > 0xffff )
V_32 = 0xffff ;
else
V_32 -- ;
return F_10 ( & V_5 -> V_14 , V_33 , V_32 ) ;
}
static int F_11 ( struct V_5 * V_5 , unsigned int * V_31 )
{
T_5 V_32 ;
int V_13 ;
V_13 = F_2 ( & V_5 -> V_14 , V_33 , & V_32 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_31 = 32768 / ( V_32 + 1 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_34 * V_35 ,
struct V_36 * V_37 , const char * V_11 , T_3 V_12 )
{
struct V_25 * V_26 = F_13 ( V_35 ) ;
struct V_5 * V_5 = F_7 ( V_26 ) ;
unsigned int V_20 ;
int V_13 ;
V_13 = F_14 ( V_11 , 10 , & V_20 ) ;
if ( V_13 )
return V_13 ;
if ( V_20 == 0 )
return - V_38 ;
V_13 = F_9 ( V_5 , V_20 ) ;
return V_13 ? V_13 : V_12 ;
}
static T_1 F_15 ( struct V_34 * V_35 ,
struct V_36 * V_37 , char * V_11 )
{
struct V_25 * V_26 = F_13 ( V_35 ) ;
struct V_5 * V_5 = F_7 ( V_26 ) ;
unsigned int V_31 ;
int V_13 ;
V_13 = F_11 ( V_5 , & V_31 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_11 , L_5 , V_31 ) ;
}
static int F_16 ( struct V_25 * V_26 , int V_20 )
{
struct V_5 * V_5 = F_7 ( V_26 ) ;
unsigned int V_31 ;
int V_39 , V_13 ;
V_13 = F_11 ( V_5 , & V_31 ) ;
if ( V_13 < 0 )
return V_13 ;
for ( V_39 = F_17 ( V_40 ) - 1 ; V_39 >= 1 ; V_39 -- ) {
if ( V_31 / V_40 [ V_39 ] >= V_20 )
break;
}
return F_10 ( & V_5 -> V_14 , V_41 , V_39 ) ;
}
static int F_18 ( struct V_25 * V_26 , int * V_20 )
{
struct V_5 * V_5 = F_7 ( V_26 ) ;
unsigned int V_31 ;
T_5 V_42 ;
int V_13 ;
F_19 ( & V_26 -> V_43 ) ;
V_13 = F_2 ( & V_5 -> V_14 , V_41 , & V_42 ) ;
if ( V_13 < 0 )
goto V_44;
V_13 = F_11 ( V_5 , & V_31 ) ;
if ( V_13 < 0 )
goto V_44;
* V_20 = V_31 / V_40 [ V_42 & 0x07 ] ;
V_44:
F_20 ( & V_26 -> V_43 ) ;
return V_13 ? V_13 : V_45 ;
}
static int F_21 ( struct V_25 * V_26 ,
const struct V_46 * V_47 , int * V_20 , int * V_48 , long V_49 )
{
struct V_5 * V_5 = F_7 ( V_26 ) ;
T_8 V_50 ;
int V_13 ;
switch ( V_49 ) {
case V_51 :
return F_22 ( V_26 , V_47 , 0 , V_20 ) ;
case V_52 :
switch ( V_47 -> type ) {
case V_53 :
* V_20 = V_5 -> V_54 -> V_55 ;
* V_48 = ( V_5 -> V_54 -> V_56 << 16 ) ;
return V_57 ;
case V_58 :
* V_20 = 10 ;
* V_48 = 697000 ;
return V_59 ;
default:
return - V_38 ;
}
case V_60 :
V_13 = F_23 ( & V_5 -> V_14 ,
V_61 , & V_50 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_20 = F_24 ( V_50 , 31 ) ;
return V_45 ;
case V_62 :
return F_18 ( V_26 , V_20 ) ;
default:
return - V_38 ;
}
}
static int F_25 ( struct V_25 * V_26 ,
const struct V_46 * V_47 , int V_20 , int V_48 , long V_49 )
{
struct V_5 * V_5 = F_7 ( V_26 ) ;
switch ( V_49 ) {
case V_60 :
return F_26 ( & V_5 -> V_14 ,
V_61 , V_20 ) ;
case V_62 :
return F_16 ( V_26 , V_20 ) ;
default:
break;
}
return - V_38 ;
}
static int F_27 ( struct V_25 * V_26 )
{
struct V_5 * V_5 = F_7 ( V_26 ) ;
int V_13 ;
V_13 = F_10 ( & V_5 -> V_14 , V_63 , 0xff ) ;
if ( V_13 )
F_28 ( & V_26 -> V_35 ,
L_6 , V_13 ) ;
return V_13 ;
}
static int F_29 ( struct V_25 * V_26 )
{
struct V_5 * V_5 = F_7 ( V_26 ) ;
unsigned int V_64 ;
T_5 V_21 ;
int V_13 ;
V_13 = F_30 ( & V_5 -> V_14 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_2 ( & V_5 -> V_14 , V_22 ,
& V_21 ) ;
if ( V_13 )
return V_13 ;
V_13 = sscanf ( V_26 -> V_65 , L_7 , & V_64 ) ;
if ( V_13 != 1 )
return - V_38 ;
if ( V_21 != V_64 )
F_31 ( & V_26 -> V_35 , L_8 ,
V_64 , V_21 ) ;
return 0 ;
}
static int F_32 ( struct V_66 * V_67 )
{
const struct V_68 * V_69 = F_33 ( V_67 ) ;
struct V_5 * V_5 ;
struct V_25 * V_26 ;
int V_13 ;
V_26 = F_34 ( & V_67 -> V_35 , sizeof( * V_5 ) ) ;
if ( V_26 == NULL )
return - V_70 ;
F_35 ( V_67 , V_26 ) ;
V_5 = F_7 ( V_26 ) ;
V_5 -> V_54 = & V_71 [ V_69 -> V_72 ] ;
V_26 -> V_35 . V_73 = & V_67 -> V_35 ;
V_26 -> V_65 = F_33 ( V_67 ) -> V_65 ;
V_26 -> V_74 = V_75 ;
V_26 -> V_76 = F_17 ( V_75 ) ;
V_26 -> V_49 = & V_77 ;
V_26 -> V_78 = V_79 ;
V_13 = F_36 ( & V_5 -> V_14 , V_26 , V_67 , & V_80 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_37 ( & V_5 -> V_14 , V_26 , NULL ) ;
if ( V_13 )
return V_13 ;
V_13 = F_29 ( V_26 ) ;
if ( V_13 )
goto V_81;
V_13 = F_38 ( V_26 ) ;
if ( V_13 )
goto V_82;
F_6 ( V_26 ) ;
return 0 ;
V_82:
F_27 ( V_26 ) ;
V_81:
F_39 ( & V_5 -> V_14 , V_26 ) ;
return V_13 ;
}
static int F_40 ( struct V_66 * V_67 )
{
struct V_25 * V_26 = F_41 ( V_67 ) ;
struct V_5 * V_5 = F_7 ( V_26 ) ;
F_42 ( V_26 ) ;
F_27 ( V_26 ) ;
F_39 ( & V_5 -> V_14 , V_26 ) ;
return 0 ;
}
