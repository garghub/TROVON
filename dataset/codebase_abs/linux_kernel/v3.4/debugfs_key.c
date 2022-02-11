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
V_12 = F_5 ( & V_7 -> V_17 . V_23 . V_24 ) ;
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_4 ,
( V_25 ) ( V_12 >> 40 ) , ( V_25 ) ( V_12 >> 32 ) , ( V_25 ) ( V_12 >> 24 ) ,
( V_25 ) ( V_12 >> 16 ) , ( V_25 ) ( V_12 >> 8 ) , ( V_25 ) V_12 ) ;
break;
case V_26 :
V_12 = F_5 ( & V_7 -> V_17 . V_27 . V_24 ) ;
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_4 ,
( V_25 ) ( V_12 >> 40 ) , ( V_25 ) ( V_12 >> 32 ) , ( V_25 ) ( V_12 >> 24 ) ,
( V_25 ) ( V_12 >> 16 ) , ( V_25 ) ( V_12 >> 8 ) , ( V_25 ) V_12 ) ;
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
char V_5 [ 14 * V_28 + 1 ] , * V_29 = V_5 ;
int V_30 , V_13 ;
const V_25 * V_31 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_14 :
case V_15 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_2 ) ;
break;
case V_16 :
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ )
V_29 += F_4 ( V_29 , sizeof( V_5 ) + V_5 - V_29 ,
L_3 ,
V_7 -> V_17 . V_18 . V_32 [ V_30 ] . V_20 ,
V_7 -> V_17 . V_18 . V_32 [ V_30 ] . V_21 ) ;
V_13 = V_29 - V_5 ;
break;
case V_22 :
for ( V_30 = 0 ; V_30 < V_28 + 1 ; V_30 ++ ) {
V_31 = V_7 -> V_17 . V_23 . V_33 [ V_30 ] ;
V_29 += F_4 ( V_29 , sizeof( V_5 ) + V_5 - V_29 ,
L_4 ,
V_31 [ 0 ] , V_31 [ 1 ] , V_31 [ 2 ] ,
V_31 [ 3 ] , V_31 [ 4 ] , V_31 [ 5 ] ) ;
}
V_13 = V_29 - V_5 ;
break;
case V_26 :
V_31 = V_7 -> V_17 . V_27 . V_33 ;
V_29 += F_4 ( V_29 , sizeof( V_5 ) + V_5 - V_29 ,
L_4 ,
V_31 [ 0 ] , V_31 [ 1 ] , V_31 [ 2 ] ,
V_31 [ 3 ] , V_31 [ 4 ] , V_31 [ 5 ] ) ;
V_13 = V_29 - V_5 ;
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
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 , V_7 -> V_17 . V_23 . V_34 ) ;
break;
case V_26 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_17 . V_27 . V_34 ) ;
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
case V_26 :
V_13 = F_4 ( V_5 , sizeof( V_5 ) , L_5 ,
V_7 -> V_17 . V_27 . V_35 ) ;
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
int V_30 , V_36 = 2 * V_7 -> V_10 . V_37 + 2 ;
char * V_5 = F_10 ( V_36 , V_38 ) ;
char * V_29 = V_5 ;
T_1 V_39 ;
if ( ! V_5 )
return - V_40 ;
for ( V_30 = 0 ; V_30 < V_7 -> V_10 . V_37 ; V_30 ++ )
V_29 += F_4 ( V_29 , V_36 + V_5 - V_29 , L_6 , V_7 -> V_10 . V_7 [ V_30 ] ) ;
V_29 += F_4 ( V_29 , V_36 + V_5 - V_29 , L_2 ) ;
V_39 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_29 - V_5 ) ;
F_11 ( V_5 ) ;
return V_39 ;
}
void F_12 ( struct V_6 * V_7 )
{
static int V_41 ;
char V_5 [ 100 ] ;
struct V_42 * V_43 ;
if ( ! V_7 -> V_44 -> V_45 . V_46 )
return;
sprintf ( V_5 , L_7 , V_41 ) ;
V_7 -> V_45 . V_47 = V_41 ;
V_41 ++ ;
V_7 -> V_45 . V_48 = F_13 ( V_5 ,
V_7 -> V_44 -> V_45 . V_46 ) ;
if ( ! V_7 -> V_45 . V_48 )
return;
V_43 = V_7 -> V_43 ;
if ( V_43 ) {
sprintf ( V_5 , L_8 ,
V_43 -> V_49 -> V_50 , V_43 -> V_43 . V_51 ) ;
V_7 -> V_45 . V_52 =
F_14 ( L_9 , V_7 -> V_45 . V_48 , V_5 ) ;
}
F_15 ( V_37 ) ;
F_15 ( V_53 ) ;
F_15 ( V_54 ) ;
F_15 ( V_55 ) ;
F_15 ( V_56 ) ;
F_15 ( V_57 ) ;
F_15 ( V_58 ) ;
F_15 ( V_59 ) ;
F_15 ( V_34 ) ;
F_15 ( V_35 ) ;
F_15 ( V_7 ) ;
F_15 ( V_60 ) ;
}
void F_16 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_17 ( V_7 -> V_45 . V_48 ) ;
V_7 -> V_45 . V_48 = NULL ;
}
void F_18 ( struct V_61 * V_49 )
{
char V_5 [ 50 ] ;
struct V_6 * V_7 ;
if ( ! V_49 -> V_45 . V_48 )
return;
F_19 ( & V_49 -> V_44 -> V_62 ) ;
if ( V_49 -> V_63 ) {
V_7 = F_20 ( V_49 -> V_44 ,
V_49 -> V_63 ) ;
sprintf ( V_5 , L_10 , V_7 -> V_45 . V_47 ) ;
V_49 -> V_45 . V_63 =
F_14 ( L_11 ,
V_49 -> V_45 . V_48 , V_5 ) ;
} else {
F_21 ( V_49 -> V_45 . V_63 ) ;
V_49 -> V_45 . V_63 = NULL ;
}
if ( V_49 -> V_64 ) {
V_7 = F_20 ( V_49 -> V_44 ,
V_49 -> V_64 ) ;
sprintf ( V_5 , L_10 , V_7 -> V_45 . V_47 ) ;
V_49 -> V_45 . V_64 =
F_14 ( L_12 ,
V_49 -> V_45 . V_48 , V_5 ) ;
} else {
F_21 ( V_49 -> V_45 . V_64 ) ;
V_49 -> V_45 . V_64 = NULL ;
}
}
void F_22 ( struct V_61 * V_49 )
{
char V_5 [ 50 ] ;
struct V_6 * V_7 ;
if ( ! V_49 -> V_45 . V_48 )
return;
V_7 = F_20 ( V_49 -> V_44 ,
V_49 -> V_65 ) ;
if ( V_7 ) {
sprintf ( V_5 , L_10 , V_7 -> V_45 . V_47 ) ;
V_49 -> V_45 . V_65 =
F_14 ( L_13 ,
V_49 -> V_45 . V_48 , V_5 ) ;
} else
F_23 ( V_49 ) ;
}
void F_23 ( struct V_61 * V_49 )
{
if ( ! V_49 )
return;
F_21 ( V_49 -> V_45 . V_65 ) ;
V_49 -> V_45 . V_65 = NULL ;
}
void F_24 ( struct V_6 * V_7 ,
struct V_42 * V_43 )
{
F_21 ( V_7 -> V_45 . V_52 ) ;
V_7 -> V_45 . V_52 = NULL ;
}
