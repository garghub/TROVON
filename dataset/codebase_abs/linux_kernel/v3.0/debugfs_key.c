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
const T_6 * V_12 ;
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
V_12 = V_7 -> V_17 . V_23 . V_24 ;
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_4 ,
V_12 [ 0 ] , V_12 [ 1 ] , V_12 [ 2 ] , V_12 [ 3 ] , V_12 [ 4 ] , V_12 [ 5 ] ) ;
break;
case V_25 :
V_12 = V_7 -> V_17 . V_26 . V_24 ;
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_4 ,
V_12 [ 0 ] , V_12 [ 1 ] , V_12 [ 2 ] , V_12 [ 3 ] , V_12 [ 4 ] ,
V_12 [ 5 ] ) ;
break;
default:
return 0 ;
}
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_13 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
char V_5 [ 14 * V_27 + 1 ] , * V_28 = V_5 ;
int V_29 , V_13 ;
const T_6 * V_30 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_14 :
case V_15 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_2 ) ;
break;
case V_16 :
for ( V_29 = 0 ; V_29 < V_27 ; V_29 ++ )
V_28 += F_4 ( V_28 , sizeof( V_5 ) + V_5 - V_28 ,
L_3 ,
V_7 -> V_17 . V_18 . V_31 [ V_29 ] . V_20 ,
V_7 -> V_17 . V_18 . V_31 [ V_29 ] . V_21 ) ;
V_13 = V_28 - V_5 ;
break;
case V_22 :
for ( V_29 = 0 ; V_29 < V_27 + 1 ; V_29 ++ ) {
V_30 = V_7 -> V_17 . V_23 . V_32 [ V_29 ] ;
V_28 += F_4 ( V_28 , sizeof( V_5 ) + V_5 - V_28 ,
L_4 ,
V_30 [ 0 ] , V_30 [ 1 ] , V_30 [ 2 ] ,
V_30 [ 3 ] , V_30 [ 4 ] , V_30 [ 5 ] ) ;
}
V_13 = V_28 - V_5 ;
break;
case V_25 :
V_30 = V_7 -> V_17 . V_26 . V_32 ;
V_28 += F_4 ( V_28 , sizeof( V_5 ) + V_5 - V_28 ,
L_4 ,
V_30 [ 0 ] , V_30 [ 1 ] , V_30 [ 2 ] ,
V_30 [ 3 ] , V_30 [ 4 ] , V_30 [ 5 ] ) ;
V_13 = V_28 - V_5 ;
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
char V_5 [ 20 ] ;
int V_13 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_22 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 , V_7 -> V_17 . V_23 . V_33 ) ;
break;
case V_25 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_17 . V_26 . V_33 ) ;
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
case V_25 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_17 . V_26 . V_34 ) ;
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
int V_29 , V_35 = 2 * V_7 -> V_10 . V_36 + 2 ;
char * V_5 = F_9 ( V_35 , V_37 ) ;
char * V_28 = V_5 ;
T_1 V_38 ;
if ( ! V_5 )
return - V_39 ;
for ( V_29 = 0 ; V_29 < V_7 -> V_10 . V_36 ; V_29 ++ )
V_28 += F_4 ( V_28 , V_35 + V_5 - V_28 , L_6 , V_7 -> V_10 . V_7 [ V_29 ] ) ;
V_28 += F_4 ( V_28 , V_35 + V_5 - V_28 , L_2 ) ;
V_38 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_28 - V_5 ) ;
F_10 ( V_5 ) ;
return V_38 ;
}
void F_11 ( struct V_6 * V_7 )
{
static int V_40 ;
char V_5 [ 50 ] ;
struct V_41 * V_42 ;
if ( ! V_7 -> V_43 -> V_44 . V_45 )
return;
sprintf ( V_5 , L_7 , V_40 ) ;
V_7 -> V_44 . V_46 = V_40 ;
V_40 ++ ;
V_7 -> V_44 . V_47 = F_12 ( V_5 ,
V_7 -> V_43 -> V_44 . V_45 ) ;
if ( ! V_7 -> V_44 . V_47 )
return;
V_42 = V_7 -> V_42 ;
if ( V_42 ) {
sprintf ( V_5 , L_8 , V_42 -> V_42 . V_48 ) ;
V_7 -> V_44 . V_49 =
F_13 ( L_9 , V_7 -> V_44 . V_47 , V_5 ) ;
}
F_14 ( V_36 ) ;
F_14 ( V_50 ) ;
F_14 ( V_51 ) ;
F_14 ( V_52 ) ;
F_14 ( V_53 ) ;
F_14 ( V_54 ) ;
F_14 ( V_55 ) ;
F_14 ( V_56 ) ;
F_14 ( V_33 ) ;
F_14 ( V_34 ) ;
F_14 ( V_7 ) ;
F_14 ( V_57 ) ;
}
void F_15 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_16 ( V_7 -> V_44 . V_47 ) ;
V_7 -> V_44 . V_47 = NULL ;
}
void F_17 ( struct V_58 * V_59 )
{
char V_5 [ 50 ] ;
struct V_6 * V_7 ;
if ( ! V_59 -> V_44 . V_47 )
return;
F_18 ( & V_59 -> V_43 -> V_60 ) ;
if ( V_59 -> V_61 ) {
V_7 = F_19 ( V_59 -> V_43 ,
V_59 -> V_61 ) ;
sprintf ( V_5 , L_10 , V_7 -> V_44 . V_46 ) ;
V_59 -> V_44 . V_61 =
F_13 ( L_11 ,
V_59 -> V_44 . V_47 , V_5 ) ;
} else {
F_20 ( V_59 -> V_44 . V_61 ) ;
V_59 -> V_44 . V_61 = NULL ;
}
if ( V_59 -> V_62 ) {
V_7 = F_19 ( V_59 -> V_43 ,
V_59 -> V_62 ) ;
sprintf ( V_5 , L_10 , V_7 -> V_44 . V_46 ) ;
V_59 -> V_44 . V_62 =
F_13 ( L_12 ,
V_59 -> V_44 . V_47 , V_5 ) ;
} else {
F_20 ( V_59 -> V_44 . V_62 ) ;
V_59 -> V_44 . V_62 = NULL ;
}
}
void F_21 ( struct V_58 * V_59 )
{
char V_5 [ 50 ] ;
struct V_6 * V_7 ;
if ( ! V_59 -> V_44 . V_47 )
return;
V_7 = F_19 ( V_59 -> V_43 ,
V_59 -> V_63 ) ;
if ( V_7 ) {
sprintf ( V_5 , L_10 , V_7 -> V_44 . V_46 ) ;
V_59 -> V_44 . V_63 =
F_13 ( L_13 ,
V_59 -> V_44 . V_47 , V_5 ) ;
} else
F_22 ( V_59 ) ;
}
void F_22 ( struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_20 ( V_59 -> V_44 . V_63 ) ;
V_59 -> V_44 . V_63 = NULL ;
}
void F_23 ( struct V_6 * V_7 ,
struct V_41 * V_42 )
{
F_20 ( V_7 -> V_44 . V_49 ) ;
V_7 -> V_44 . V_49 = NULL ;
}
