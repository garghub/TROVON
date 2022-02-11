static T_1 F_1 ( struct V_1 * V_1 ,
char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 15 ] ;
struct V_6 * V_7 = V_1 -> V_8 ;
T_5 V_9 = V_7 -> V_10 . V_11 ;
sprintf ( V_5 , L_1 ,
V_9 >> 24 , ( V_9 >> 16 ) & 0xff , ( V_9 >> 8 ) & 0xff , V_9 & 0xff ) ;
return F_2 ( V_2 , V_3 , V_4 , V_5 , strlen ( V_5 ) ) ;
}
static T_1 F_3 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
T_6 V_12 ;
char V_5 [ 20 ] ;
int V_13 ;
struct V_6 * V_7 = V_1 -> V_8 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_14 :
case V_15 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_2 ) ;
break;
case V_16 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_3 ,
V_7 -> V_17 . V_18 . V_19 . V_20 ,
V_7 -> V_17 . V_18 . V_19 . V_21 ) ;
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
V_12 = F_5 ( & V_7 -> V_10 . V_30 ) ;
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_4 ,
( V_31 ) ( V_12 >> 40 ) , ( V_31 ) ( V_12 >> 32 ) , ( V_31 ) ( V_12 >> 24 ) ,
( V_31 ) ( V_12 >> 16 ) , ( V_31 ) ( V_12 >> 8 ) , ( V_31 ) V_12 ) ;
break;
default:
return 0 ;
}
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_13 ) ;
}
static T_1 F_6 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 14 * V_32 + 1 ] , * V_33 = V_5 ;
int V_34 , V_13 ;
const V_31 * V_35 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_14 :
case V_15 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_2 ) ;
break;
case V_16 :
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ )
V_33 += F_4 ( V_33 , sizeof( V_5 ) + V_5 - V_33 ,
L_3 ,
V_7 -> V_17 . V_18 . V_36 [ V_34 ] . V_20 ,
V_7 -> V_17 . V_18 . V_36 [ V_34 ] . V_21 ) ;
V_13 = V_33 - V_5 ;
break;
case V_22 :
case V_23 :
for ( V_34 = 0 ; V_34 < V_32 + 1 ; V_34 ++ ) {
V_35 = V_7 -> V_17 . V_37 . V_38 [ V_34 ] ;
V_33 += F_4 ( V_33 , sizeof( V_5 ) + V_5 - V_33 ,
L_4 ,
V_35 [ 0 ] , V_35 [ 1 ] , V_35 [ 2 ] ,
V_35 [ 3 ] , V_35 [ 4 ] , V_35 [ 5 ] ) ;
}
V_13 = V_33 - V_5 ;
break;
case V_24 :
case V_25 :
V_35 = V_7 -> V_17 . V_39 . V_38 ;
V_33 += F_4 ( V_33 , sizeof( V_5 ) + V_5 - V_33 ,
L_4 ,
V_35 [ 0 ] , V_35 [ 1 ] , V_35 [ 2 ] ,
V_35 [ 3 ] , V_35 [ 4 ] , V_35 [ 5 ] ) ;
V_13 = V_33 - V_5 ;
break;
case V_26 :
case V_27 :
V_35 = V_7 -> V_17 . V_40 . V_38 ;
V_33 += F_4 ( V_33 , sizeof( V_5 ) + V_5 - V_33 ,
L_4 ,
V_35 [ 0 ] , V_35 [ 1 ] , V_35 [ 2 ] ,
V_35 [ 3 ] , V_35 [ 4 ] , V_35 [ 5 ] ) ;
V_13 = V_33 - V_5 ;
break;
case V_28 :
case V_29 :
for ( V_34 = 0 ; V_34 < V_32 + 1 ; V_34 ++ ) {
V_35 = V_7 -> V_17 . V_41 . V_38 [ V_34 ] ;
V_33 += F_4 ( V_33 , sizeof( V_5 ) + V_5 - V_33 ,
L_4 ,
V_35 [ 0 ] , V_35 [ 1 ] , V_35 [ 2 ] ,
V_35 [ 3 ] , V_35 [ 4 ] , V_35 [ 5 ] ) ;
}
V_13 = V_33 - V_5 ;
break;
default:
return 0 ;
}
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_13 ) ;
}
static T_1 F_7 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 20 ] ;
int V_13 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_22 :
case V_23 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 , V_7 -> V_17 . V_37 . V_42 ) ;
break;
case V_24 :
case V_25 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_17 . V_39 . V_42 ) ;
break;
case V_26 :
case V_27 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_17 . V_40 . V_42 ) ;
break;
case V_28 :
case V_29 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 , V_7 -> V_17 . V_41 . V_42 ) ;
break;
default:
return 0 ;
}
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_13 ) ;
}
static T_1 F_8 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 20 ] ;
int V_13 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_24 :
case V_25 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_17 . V_39 . V_43 ) ;
break;
case V_26 :
case V_27 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_17 . V_40 . V_43 ) ;
break;
default:
return 0 ;
}
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_13 ) ;
}
static T_1 F_9 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 20 ] ;
int V_13 ;
if ( V_7 -> V_10 . V_11 != V_16 )
return - V_44 ;
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 , V_7 -> V_17 . V_18 . V_45 ) ;
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_13 ) ;
}
static T_1 F_10 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
int V_34 , V_46 = 2 * V_7 -> V_10 . V_47 + 2 ;
char * V_5 = F_11 ( V_46 , V_48 ) ;
char * V_33 = V_5 ;
T_1 V_49 ;
if ( ! V_5 )
return - V_50 ;
for ( V_34 = 0 ; V_34 < V_7 -> V_10 . V_47 ; V_34 ++ )
V_33 += F_4 ( V_33 , V_46 + V_5 - V_33 , L_6 , V_7 -> V_10 . V_7 [ V_34 ] ) ;
V_33 += F_4 ( V_33 , V_46 + V_5 - V_33 , L_2 ) ;
V_49 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_33 - V_5 ) ;
F_12 ( V_5 ) ;
return V_49 ;
}
void F_13 ( struct V_6 * V_7 )
{
static int V_51 ;
char V_5 [ 100 ] ;
struct V_52 * V_53 ;
if ( ! V_7 -> V_54 -> V_55 . V_56 )
return;
sprintf ( V_5 , L_7 , V_51 ) ;
V_7 -> V_55 . V_57 = V_51 ;
V_51 ++ ;
V_7 -> V_55 . V_58 = F_14 ( V_5 ,
V_7 -> V_54 -> V_55 . V_56 ) ;
if ( ! V_7 -> V_55 . V_58 )
return;
V_53 = V_7 -> V_53 ;
if ( V_53 ) {
sprintf ( V_5 , L_8 ,
V_53 -> V_59 -> V_60 , V_53 -> V_53 . V_61 ) ;
V_7 -> V_55 . V_62 =
F_15 ( L_9 , V_7 -> V_55 . V_58 , V_5 ) ;
}
F_16 ( V_47 ) ;
F_16 ( V_63 ) ;
F_16 ( V_64 ) ;
F_16 ( V_65 ) ;
F_16 ( V_66 ) ;
F_16 ( V_67 ) ;
F_16 ( V_68 ) ;
F_16 ( V_69 ) ;
F_16 ( V_42 ) ;
F_16 ( V_43 ) ;
F_16 ( V_45 ) ;
F_16 ( V_7 ) ;
F_16 ( V_70 ) ;
}
void F_17 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_18 ( V_7 -> V_55 . V_58 ) ;
V_7 -> V_55 . V_58 = NULL ;
}
void F_19 ( struct V_71 * V_59 )
{
char V_5 [ 50 ] ;
struct V_6 * V_7 ;
if ( ! V_59 -> V_72 . V_73 )
return;
F_20 ( & V_59 -> V_54 -> V_74 ) ;
F_21 ( V_59 -> V_55 . V_75 ) ;
V_59 -> V_55 . V_75 = NULL ;
if ( V_59 -> V_75 ) {
V_7 = F_22 ( V_59 -> V_54 ,
V_59 -> V_75 ) ;
sprintf ( V_5 , L_10 , V_7 -> V_55 . V_57 ) ;
V_59 -> V_55 . V_75 =
F_15 ( L_11 ,
V_59 -> V_72 . V_73 , V_5 ) ;
}
F_21 ( V_59 -> V_55 . V_76 ) ;
V_59 -> V_55 . V_76 = NULL ;
if ( V_59 -> V_76 ) {
V_7 = F_22 ( V_59 -> V_54 ,
V_59 -> V_76 ) ;
sprintf ( V_5 , L_10 , V_7 -> V_55 . V_57 ) ;
V_59 -> V_55 . V_76 =
F_15 ( L_12 ,
V_59 -> V_72 . V_73 , V_5 ) ;
}
}
void F_23 ( struct V_71 * V_59 )
{
char V_5 [ 50 ] ;
struct V_6 * V_7 ;
if ( ! V_59 -> V_72 . V_73 )
return;
V_7 = F_22 ( V_59 -> V_54 ,
V_59 -> V_77 ) ;
if ( V_7 ) {
sprintf ( V_5 , L_10 , V_7 -> V_55 . V_57 ) ;
V_59 -> V_55 . V_77 =
F_15 ( L_13 ,
V_59 -> V_72 . V_73 , V_5 ) ;
} else
F_24 ( V_59 ) ;
}
void F_24 ( struct V_71 * V_59 )
{
if ( ! V_59 )
return;
F_21 ( V_59 -> V_55 . V_77 ) ;
V_59 -> V_55 . V_77 = NULL ;
}
void F_25 ( struct V_6 * V_7 ,
struct V_52 * V_53 )
{
F_21 ( V_7 -> V_55 . V_62 ) ;
V_7 -> V_55 . V_62 = NULL ;
}
