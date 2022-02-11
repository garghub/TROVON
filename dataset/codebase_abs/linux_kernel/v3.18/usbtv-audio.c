static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_4 -> V_7 = V_2 ;
V_6 -> V_8 = V_9 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_4 ( & V_4 -> V_10 ) ) {
F_5 ( & V_4 -> V_10 , 0 ) ;
F_6 ( & V_4 -> V_11 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_14 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_14 = F_8 ( V_2 ,
F_9 ( V_13 ) ) ;
if ( V_14 < 0 ) {
F_10 ( V_4 -> V_15 , L_1 ,
V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_16 = 0 ;
V_4 -> V_17 = 0 ;
return 0 ;
}
static void F_14 ( struct V_18 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_19 ;
struct V_1 * V_2 = V_4 -> V_7 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_20 , V_21 , V_22 , V_23 , V_24 ;
int V_25 ;
void * V_26 ;
switch ( V_18 -> V_27 ) {
case 0 :
case - V_28 :
break;
case - V_29 :
case - V_30 :
case - V_31 :
case - V_32 :
return;
default:
F_10 ( V_4 -> V_15 , L_2 ,
V_18 -> V_27 ) ;
}
if ( ! F_4 ( & V_4 -> V_10 ) )
return;
V_21 = V_6 -> V_33 >> 3 ;
V_22 = V_34 / V_21 ;
V_23 = V_4 -> V_16 ;
V_24 = V_4 -> V_17 ;
V_25 = 0 ;
for ( V_20 = 0 ; V_20 < V_18 -> V_35 ; V_20 += V_36 ) {
V_26 = V_18 -> V_37 + V_20 + V_38 ;
if ( V_23 + V_22 >= V_6 -> V_39 ) {
T_1 V_40 = ( V_6 -> V_39 - V_23 ) *
V_21 ;
memcpy ( V_6 -> V_41 + V_23 * V_21 ,
V_26 , V_40 ) ;
memcpy ( V_6 -> V_41 , V_26 + V_40 ,
V_22 * V_21 - V_40 ) ;
} else {
memcpy ( V_6 -> V_41 + V_23 * V_21 ,
V_26 , V_22 * V_21 ) ;
}
V_23 += V_22 ;
V_24 += V_22 ;
if ( V_23 >= V_6 -> V_39 )
V_23 -= V_6 -> V_39 ;
if ( V_24 >= V_6 -> V_42 ) {
V_24 -= V_6 -> V_42 ;
V_25 = 1 ;
}
}
F_15 ( V_2 ) ;
V_4 -> V_16 = V_23 ;
V_4 -> V_17 = V_24 ;
F_16 ( V_2 ) ;
if ( V_25 )
F_17 ( V_2 ) ;
F_18 ( V_18 , V_43 ) ;
}
static int F_19 ( struct V_3 * V_4 )
{
unsigned int V_44 ;
static const T_2 V_45 [] [ 2 ] = {
{ V_46 + 0x0008 , 0x0001 } ,
{ V_46 + 0x01d0 , 0x00ff } ,
{ V_46 + 0x01d9 , 0x0002 } ,
{ V_46 + 0x01da , 0x0013 } ,
{ V_46 + 0x01db , 0x0012 } ,
{ V_46 + 0x01e9 , 0x0002 } ,
{ V_46 + 0x01ec , 0x006c } ,
{ V_46 + 0x0294 , 0x0020 } ,
{ V_46 + 0x0255 , 0x00cf } ,
{ V_46 + 0x0256 , 0x0020 } ,
{ V_46 + 0x01eb , 0x0030 } ,
{ V_46 + 0x027d , 0x00a6 } ,
{ V_46 + 0x0280 , 0x0011 } ,
{ V_46 + 0x0281 , 0x0040 } ,
{ V_46 + 0x0282 , 0x0011 } ,
{ V_46 + 0x0283 , 0x0040 } ,
{ 0xf891 , 0x0010 } ,
{ V_46 + 0x0284 , 0x00aa } ,
} ;
V_4 -> V_47 = F_20 ( 0 , V_48 ) ;
if ( V_4 -> V_47 == NULL )
goto V_49;
V_44 = F_21 ( V_4 -> V_50 , V_51 ) ;
V_4 -> V_47 -> V_37 = F_22 (
V_52 , V_48 ) ;
if ( V_4 -> V_47 -> V_37 == NULL )
goto V_53;
F_23 ( V_4 -> V_47 , V_4 -> V_50 , V_44 ,
V_4 -> V_47 -> V_37 , V_52 ,
F_14 , V_4 ) ;
F_24 ( V_4 , V_45 , F_25 ( V_45 ) ) ;
F_26 ( V_4 -> V_50 , V_44 ) ;
F_18 ( V_4 -> V_47 , V_43 ) ;
return 0 ;
V_53:
F_27 ( V_4 -> V_47 ) ;
V_4 -> V_47 = NULL ;
V_49:
return - V_54 ;
}
static int F_28 ( struct V_3 * V_4 )
{
static const T_2 V_45 [] [ 2 ] = {
{ V_46 + 0x027d , 0x0000 } ,
{ V_46 + 0x0280 , 0x0010 } ,
{ V_46 + 0x0282 , 0x0010 } ,
} ;
if ( V_4 -> V_47 ) {
F_29 ( V_4 -> V_47 ) ;
F_30 ( V_4 -> V_47 -> V_37 ) ;
F_27 ( V_4 -> V_47 ) ;
V_4 -> V_47 = NULL ;
}
F_24 ( V_4 , V_45 , F_25 ( V_45 ) ) ;
return 0 ;
}
void F_31 ( struct V_3 * V_3 )
{
if ( F_4 ( & V_3 -> V_10 ) && V_3 -> V_47 )
F_29 ( V_3 -> V_47 ) ;
}
void F_32 ( struct V_3 * V_3 )
{
if ( F_4 ( & V_3 -> V_10 ) && V_3 -> V_47 )
F_18 ( V_3 -> V_47 , V_43 ) ;
}
static void F_33 ( struct V_55 * V_56 )
{
struct V_3 * V_4 = F_34 ( V_56 , struct V_3 , V_11 ) ;
if ( F_4 ( & V_4 -> V_10 ) )
F_19 ( V_4 ) ;
else
F_28 ( V_4 ) ;
}
static int F_35 ( struct V_1 * V_2 , int V_57 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_57 ) {
case V_58 :
case V_59 :
case V_60 :
F_5 ( & V_4 -> V_10 , 1 ) ;
break;
case V_61 :
case V_62 :
case V_63 :
F_5 ( & V_4 -> V_10 , 0 ) ;
break;
default:
return - V_64 ;
}
F_6 ( & V_4 -> V_11 ) ;
return 0 ;
}
static T_3 F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_16 ;
}
int F_37 ( struct V_3 * V_3 )
{
int V_14 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
F_38 ( & V_3 -> V_11 , F_33 ) ;
F_5 ( & V_3 -> V_10 , 0 ) ;
V_14 = F_39 ( & V_3 -> V_50 -> V_15 , V_69 , L_3 ,
V_70 , 0 , & V_66 ) ;
if ( V_14 < 0 )
return V_14 ;
F_40 ( V_66 -> V_71 , V_3 -> V_15 -> V_71 -> V_72 , sizeof( V_66 -> V_71 ) ) ;
F_40 ( V_66 -> V_73 , L_3 , sizeof( V_66 -> V_73 ) ) ;
snprintf ( V_66 -> V_74 , sizeof( V_66 -> V_74 ) ,
L_4 , V_3 -> V_50 -> V_75 -> V_76 ,
V_3 -> V_50 -> V_77 ) ;
F_41 ( V_66 , V_3 -> V_15 ) ;
V_3 -> V_78 = V_66 ;
V_14 = F_42 ( V_66 , L_5 , 0 , 0 , 1 , & V_68 ) ;
if ( V_14 < 0 )
goto V_79;
F_40 ( V_68 -> V_72 , L_6 , sizeof( V_68 -> V_72 ) ) ;
V_68 -> V_80 = 0 ;
V_68 -> V_81 = V_3 ;
F_43 ( V_68 , V_82 , & V_83 ) ;
F_44 ( V_68 , V_84 ,
F_45 ( V_48 ) , V_85 ,
V_85 ) ;
V_14 = F_46 ( V_66 ) ;
if ( V_14 )
goto V_79;
return 0 ;
V_79:
V_3 -> V_78 = NULL ;
F_47 ( V_66 ) ;
return V_14 ;
}
void F_48 ( struct V_3 * V_3 )
{
if ( V_3 -> V_78 && V_3 -> V_50 ) {
F_47 ( V_3 -> V_78 ) ;
V_3 -> V_78 = NULL ;
}
}
