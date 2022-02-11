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
static T_1 F_3 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
T_6 V_12 ;
int V_13 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_14 :
case V_15 :
return - V_16 ;
case V_17 :
return - V_18 ;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
V_13 = F_4 ( V_2 , V_3 , 16 , & V_12 ) ;
if ( V_13 )
return V_13 ;
if ( V_12 >= ( 1ULL << 48 ) )
return - V_27 ;
F_5 ( & V_7 -> V_10 . V_28 , V_12 ) ;
return V_3 ;
default:
return 0 ;
}
}
static T_1 F_6 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
T_6 V_12 ;
char V_5 [ 20 ] ;
int V_29 ;
struct V_6 * V_7 = V_1 -> V_8 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_14 :
case V_15 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_2 ) ;
break;
case V_17 :
V_12 = F_8 ( & V_7 -> V_10 . V_28 ) ;
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_3 ,
F_9 ( V_12 ) ,
F_10 ( V_12 ) ) ;
break;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
V_12 = F_8 ( & V_7 -> V_10 . V_28 ) ;
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_4 ,
( V_30 ) ( V_12 >> 40 ) , ( V_30 ) ( V_12 >> 32 ) , ( V_30 ) ( V_12 >> 24 ) ,
( V_30 ) ( V_12 >> 16 ) , ( V_30 ) ( V_12 >> 8 ) , ( V_30 ) V_12 ) ;
break;
default:
return 0 ;
}
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_29 ) ;
}
static T_1 F_11 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 14 * V_31 + 1 ] , * V_32 = V_5 ;
int V_33 , V_29 ;
const V_30 * V_34 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_14 :
case V_15 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_2 ) ;
break;
case V_17 :
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ )
V_32 += F_7 ( V_32 , sizeof( V_5 ) + V_5 - V_32 ,
L_3 ,
V_7 -> V_35 . V_36 . V_37 [ V_33 ] . V_38 ,
V_7 -> V_35 . V_36 . V_37 [ V_33 ] . V_39 ) ;
V_29 = V_32 - V_5 ;
break;
case V_19 :
case V_20 :
for ( V_33 = 0 ; V_33 < V_31 + 1 ; V_33 ++ ) {
V_34 = V_7 -> V_35 . V_40 . V_41 [ V_33 ] ;
V_32 += F_7 ( V_32 , sizeof( V_5 ) + V_5 - V_32 ,
L_4 ,
V_34 [ 0 ] , V_34 [ 1 ] , V_34 [ 2 ] ,
V_34 [ 3 ] , V_34 [ 4 ] , V_34 [ 5 ] ) ;
}
V_29 = V_32 - V_5 ;
break;
case V_21 :
case V_22 :
V_34 = V_7 -> V_35 . V_42 . V_41 ;
V_32 += F_7 ( V_32 , sizeof( V_5 ) + V_5 - V_32 ,
L_4 ,
V_34 [ 0 ] , V_34 [ 1 ] , V_34 [ 2 ] ,
V_34 [ 3 ] , V_34 [ 4 ] , V_34 [ 5 ] ) ;
V_29 = V_32 - V_5 ;
break;
case V_23 :
case V_24 :
V_34 = V_7 -> V_35 . V_43 . V_41 ;
V_32 += F_7 ( V_32 , sizeof( V_5 ) + V_5 - V_32 ,
L_4 ,
V_34 [ 0 ] , V_34 [ 1 ] , V_34 [ 2 ] ,
V_34 [ 3 ] , V_34 [ 4 ] , V_34 [ 5 ] ) ;
V_29 = V_32 - V_5 ;
break;
case V_25 :
case V_26 :
for ( V_33 = 0 ; V_33 < V_31 + 1 ; V_33 ++ ) {
V_34 = V_7 -> V_35 . V_44 . V_41 [ V_33 ] ;
V_32 += F_7 ( V_32 , sizeof( V_5 ) + V_5 - V_32 ,
L_4 ,
V_34 [ 0 ] , V_34 [ 1 ] , V_34 [ 2 ] ,
V_34 [ 3 ] , V_34 [ 4 ] , V_34 [ 5 ] ) ;
}
V_29 = V_32 - V_5 ;
break;
default:
return 0 ;
}
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_29 ) ;
}
static T_1 F_12 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 20 ] ;
int V_29 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_19 :
case V_20 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 , V_7 -> V_35 . V_40 . V_45 ) ;
break;
case V_21 :
case V_22 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_35 . V_42 . V_45 ) ;
break;
case V_23 :
case V_24 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_35 . V_43 . V_45 ) ;
break;
case V_25 :
case V_26 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 , V_7 -> V_35 . V_44 . V_45 ) ;
break;
default:
return 0 ;
}
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_29 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 20 ] ;
int V_29 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_21 :
case V_22 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_35 . V_42 . V_46 ) ;
break;
case V_23 :
case V_24 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_35 . V_43 . V_46 ) ;
break;
default:
return 0 ;
}
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_29 ) ;
}
static T_1 F_14 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 20 ] ;
int V_29 ;
if ( V_7 -> V_10 . V_11 != V_17 )
return - V_16 ;
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 , V_7 -> V_35 . V_36 . V_47 ) ;
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_29 ) ;
}
static T_1 F_15 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
int V_33 , V_48 = 2 * V_7 -> V_10 . V_49 + 2 ;
char * V_5 = F_16 ( V_48 , V_50 ) ;
char * V_32 = V_5 ;
T_1 V_51 ;
if ( ! V_5 )
return - V_52 ;
for ( V_33 = 0 ; V_33 < V_7 -> V_10 . V_49 ; V_33 ++ )
V_32 += F_7 ( V_32 , V_48 + V_5 - V_32 , L_6 , V_7 -> V_10 . V_7 [ V_33 ] ) ;
V_32 += F_7 ( V_32 , V_48 + V_5 - V_32 , L_2 ) ;
V_51 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_32 - V_5 ) ;
F_17 ( V_5 ) ;
return V_51 ;
}
void F_18 ( struct V_6 * V_7 )
{
static int V_53 ;
char V_5 [ 100 ] ;
struct V_54 * V_55 ;
if ( ! V_7 -> V_56 -> V_57 . V_58 )
return;
sprintf ( V_5 , L_7 , V_53 ) ;
V_7 -> V_57 . V_59 = V_53 ;
V_53 ++ ;
V_7 -> V_57 . V_60 = F_19 ( V_5 ,
V_7 -> V_56 -> V_57 . V_58 ) ;
if ( ! V_7 -> V_57 . V_60 )
return;
V_55 = V_7 -> V_55 ;
if ( V_55 ) {
sprintf ( V_5 , L_8 ,
V_55 -> V_61 -> V_62 , V_55 -> V_55 . V_63 ) ;
V_7 -> V_57 . V_64 =
F_20 ( L_9 , V_7 -> V_57 . V_60 , V_5 ) ;
}
F_21 ( V_49 ) ;
F_21 ( V_65 ) ;
F_21 ( V_66 ) ;
F_21 ( V_67 ) ;
F_21 ( V_68 ) ;
F_22 ( V_69 ) ;
F_21 ( V_70 ) ;
F_21 ( V_45 ) ;
F_21 ( V_46 ) ;
F_21 ( V_47 ) ;
F_21 ( V_7 ) ;
F_21 ( V_71 ) ;
}
void F_23 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_24 ( V_7 -> V_57 . V_60 ) ;
V_7 -> V_57 . V_60 = NULL ;
}
void F_25 ( struct V_72 * V_61 )
{
char V_5 [ 50 ] ;
struct V_6 * V_7 ;
if ( ! V_61 -> V_73 . V_74 )
return;
F_26 ( & V_61 -> V_56 -> V_75 ) ;
F_27 ( V_61 -> V_57 . V_76 ) ;
V_61 -> V_57 . V_76 = NULL ;
if ( V_61 -> V_76 ) {
V_7 = F_28 ( V_61 -> V_56 ,
V_61 -> V_76 ) ;
sprintf ( V_5 , L_10 , V_7 -> V_57 . V_59 ) ;
V_61 -> V_57 . V_76 =
F_20 ( L_11 ,
V_61 -> V_73 . V_74 , V_5 ) ;
}
F_27 ( V_61 -> V_57 . V_77 ) ;
V_61 -> V_57 . V_77 = NULL ;
if ( V_61 -> V_77 ) {
V_7 = F_28 ( V_61 -> V_56 ,
V_61 -> V_77 ) ;
sprintf ( V_5 , L_10 , V_7 -> V_57 . V_59 ) ;
V_61 -> V_57 . V_77 =
F_20 ( L_12 ,
V_61 -> V_73 . V_74 , V_5 ) ;
}
}
void F_29 ( struct V_72 * V_61 )
{
char V_5 [ 50 ] ;
struct V_6 * V_7 ;
if ( ! V_61 -> V_73 . V_74 )
return;
V_7 = F_28 ( V_61 -> V_56 ,
V_61 -> V_78 ) ;
if ( V_7 ) {
sprintf ( V_5 , L_10 , V_7 -> V_57 . V_59 ) ;
V_61 -> V_57 . V_78 =
F_20 ( L_13 ,
V_61 -> V_73 . V_74 , V_5 ) ;
} else
F_30 ( V_61 ) ;
}
void F_30 ( struct V_72 * V_61 )
{
if ( ! V_61 )
return;
F_27 ( V_61 -> V_57 . V_78 ) ;
V_61 -> V_57 . V_78 = NULL ;
}
void F_31 ( struct V_6 * V_7 ,
struct V_54 * V_55 )
{
F_27 ( V_7 -> V_57 . V_64 ) ;
V_7 -> V_57 . V_64 = NULL ;
}
