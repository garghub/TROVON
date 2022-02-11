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
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_3 ,
V_7 -> V_30 . V_31 . V_32 . V_33 ,
V_7 -> V_30 . V_31 . V_32 . V_34 ) ;
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
( V_35 ) ( V_12 >> 40 ) , ( V_35 ) ( V_12 >> 32 ) , ( V_35 ) ( V_12 >> 24 ) ,
( V_35 ) ( V_12 >> 16 ) , ( V_35 ) ( V_12 >> 8 ) , ( V_35 ) V_12 ) ;
break;
default:
return 0 ;
}
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_29 ) ;
}
static T_1 F_9 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 14 * V_36 + 1 ] , * V_37 = V_5 ;
int V_38 , V_29 ;
const V_35 * V_39 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_14 :
case V_15 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_2 ) ;
break;
case V_17 :
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ )
V_37 += F_7 ( V_37 , sizeof( V_5 ) + V_5 - V_37 ,
L_3 ,
V_7 -> V_30 . V_31 . V_40 [ V_38 ] . V_33 ,
V_7 -> V_30 . V_31 . V_40 [ V_38 ] . V_34 ) ;
V_29 = V_37 - V_5 ;
break;
case V_19 :
case V_20 :
for ( V_38 = 0 ; V_38 < V_36 + 1 ; V_38 ++ ) {
V_39 = V_7 -> V_30 . V_41 . V_42 [ V_38 ] ;
V_37 += F_7 ( V_37 , sizeof( V_5 ) + V_5 - V_37 ,
L_4 ,
V_39 [ 0 ] , V_39 [ 1 ] , V_39 [ 2 ] ,
V_39 [ 3 ] , V_39 [ 4 ] , V_39 [ 5 ] ) ;
}
V_29 = V_37 - V_5 ;
break;
case V_21 :
case V_22 :
V_39 = V_7 -> V_30 . V_43 . V_42 ;
V_37 += F_7 ( V_37 , sizeof( V_5 ) + V_5 - V_37 ,
L_4 ,
V_39 [ 0 ] , V_39 [ 1 ] , V_39 [ 2 ] ,
V_39 [ 3 ] , V_39 [ 4 ] , V_39 [ 5 ] ) ;
V_29 = V_37 - V_5 ;
break;
case V_23 :
case V_24 :
V_39 = V_7 -> V_30 . V_44 . V_42 ;
V_37 += F_7 ( V_37 , sizeof( V_5 ) + V_5 - V_37 ,
L_4 ,
V_39 [ 0 ] , V_39 [ 1 ] , V_39 [ 2 ] ,
V_39 [ 3 ] , V_39 [ 4 ] , V_39 [ 5 ] ) ;
V_29 = V_37 - V_5 ;
break;
case V_25 :
case V_26 :
for ( V_38 = 0 ; V_38 < V_36 + 1 ; V_38 ++ ) {
V_39 = V_7 -> V_30 . V_45 . V_42 [ V_38 ] ;
V_37 += F_7 ( V_37 , sizeof( V_5 ) + V_5 - V_37 ,
L_4 ,
V_39 [ 0 ] , V_39 [ 1 ] , V_39 [ 2 ] ,
V_39 [ 3 ] , V_39 [ 4 ] , V_39 [ 5 ] ) ;
}
V_29 = V_37 - V_5 ;
break;
default:
return 0 ;
}
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_29 ) ;
}
static T_1 F_10 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 20 ] ;
int V_29 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_19 :
case V_20 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 , V_7 -> V_30 . V_41 . V_46 ) ;
break;
case V_21 :
case V_22 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_30 . V_43 . V_46 ) ;
break;
case V_23 :
case V_24 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_30 . V_44 . V_46 ) ;
break;
case V_25 :
case V_26 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 , V_7 -> V_30 . V_45 . V_46 ) ;
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
char V_5 [ 20 ] ;
int V_29 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_21 :
case V_22 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_30 . V_43 . V_47 ) ;
break;
case V_23 :
case V_24 :
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_30 . V_44 . V_47 ) ;
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
if ( V_7 -> V_10 . V_11 != V_17 )
return - V_16 ;
V_29 = F_7 ( V_5 , sizeof( V_5 ) , L_5 , V_7 -> V_30 . V_31 . V_48 ) ;
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_29 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
int V_38 , V_49 = 2 * V_7 -> V_10 . V_50 + 2 ;
char * V_5 = F_14 ( V_49 , V_51 ) ;
char * V_37 = V_5 ;
T_1 V_52 ;
if ( ! V_5 )
return - V_53 ;
for ( V_38 = 0 ; V_38 < V_7 -> V_10 . V_50 ; V_38 ++ )
V_37 += F_7 ( V_37 , V_49 + V_5 - V_37 , L_6 , V_7 -> V_10 . V_7 [ V_38 ] ) ;
V_37 += F_7 ( V_37 , V_49 + V_5 - V_37 , L_2 ) ;
V_52 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_37 - V_5 ) ;
F_15 ( V_5 ) ;
return V_52 ;
}
void F_16 ( struct V_6 * V_7 )
{
static int V_54 ;
char V_5 [ 100 ] ;
struct V_55 * V_56 ;
if ( ! V_7 -> V_57 -> V_58 . V_59 )
return;
sprintf ( V_5 , L_7 , V_54 ) ;
V_7 -> V_58 . V_60 = V_54 ;
V_54 ++ ;
V_7 -> V_58 . V_61 = F_17 ( V_5 ,
V_7 -> V_57 -> V_58 . V_59 ) ;
if ( ! V_7 -> V_58 . V_61 )
return;
V_56 = V_7 -> V_56 ;
if ( V_56 ) {
sprintf ( V_5 , L_8 ,
V_56 -> V_62 -> V_63 , V_56 -> V_56 . V_64 ) ;
V_7 -> V_58 . V_65 =
F_18 ( L_9 , V_7 -> V_58 . V_61 , V_5 ) ;
}
F_19 ( V_50 ) ;
F_19 ( V_66 ) ;
F_19 ( V_67 ) ;
F_19 ( V_68 ) ;
F_19 ( V_69 ) ;
F_20 ( V_70 ) ;
F_19 ( V_71 ) ;
F_19 ( V_46 ) ;
F_19 ( V_47 ) ;
F_19 ( V_48 ) ;
F_19 ( V_7 ) ;
F_19 ( V_72 ) ;
}
void F_21 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_22 ( V_7 -> V_58 . V_61 ) ;
V_7 -> V_58 . V_61 = NULL ;
}
void F_23 ( struct V_73 * V_62 )
{
char V_5 [ 50 ] ;
struct V_6 * V_7 ;
if ( ! V_62 -> V_74 . V_75 )
return;
F_24 ( & V_62 -> V_57 -> V_76 ) ;
F_25 ( V_62 -> V_58 . V_77 ) ;
V_62 -> V_58 . V_77 = NULL ;
if ( V_62 -> V_77 ) {
V_7 = F_26 ( V_62 -> V_57 ,
V_62 -> V_77 ) ;
sprintf ( V_5 , L_10 , V_7 -> V_58 . V_60 ) ;
V_62 -> V_58 . V_77 =
F_18 ( L_11 ,
V_62 -> V_74 . V_75 , V_5 ) ;
}
F_25 ( V_62 -> V_58 . V_78 ) ;
V_62 -> V_58 . V_78 = NULL ;
if ( V_62 -> V_78 ) {
V_7 = F_26 ( V_62 -> V_57 ,
V_62 -> V_78 ) ;
sprintf ( V_5 , L_10 , V_7 -> V_58 . V_60 ) ;
V_62 -> V_58 . V_78 =
F_18 ( L_12 ,
V_62 -> V_74 . V_75 , V_5 ) ;
}
}
void F_27 ( struct V_73 * V_62 )
{
char V_5 [ 50 ] ;
struct V_6 * V_7 ;
if ( ! V_62 -> V_74 . V_75 )
return;
V_7 = F_26 ( V_62 -> V_57 ,
V_62 -> V_79 ) ;
if ( V_7 ) {
sprintf ( V_5 , L_10 , V_7 -> V_58 . V_60 ) ;
V_62 -> V_58 . V_79 =
F_18 ( L_13 ,
V_62 -> V_74 . V_75 , V_5 ) ;
} else
F_28 ( V_62 ) ;
}
void F_28 ( struct V_73 * V_62 )
{
if ( ! V_62 )
return;
F_25 ( V_62 -> V_58 . V_79 ) ;
V_62 -> V_58 . V_79 = NULL ;
}
void F_29 ( struct V_6 * V_7 ,
struct V_55 * V_56 )
{
F_25 ( V_7 -> V_58 . V_65 ) ;
V_7 -> V_58 . V_65 = NULL ;
}
