static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
unsigned int V_6 ;
T_1 V_7 , V_8 ;
T_1 * V_9 ;
switch ( V_4 -> V_10 ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
V_8 = ( V_15 | V_16 ) ;
V_7 = V_4 -> V_10 ;
break;
case V_17 :
V_8 = ( V_15 | V_18 ) ;
V_7 = V_4 -> V_10 ;
break;
case V_19 :
V_8 = ( V_15 | V_18 ) ;
V_7 = V_20 ;
break;
case V_21 :
V_8 = ( V_15 | V_16 ) ;
V_7 = V_20 ;
break;
case V_22 :
V_8 = ( V_15 | V_16 ) ;
V_7 = V_23 ;
break;
case V_24 :
V_8 = ( V_15 | V_18 ) ;
V_7 = V_23 ;
break;
default:
F_2 ( L_1 , V_4 -> V_10 ) ;
V_5 = - V_25 ;
goto error;
}
V_9 = F_3 ( V_4 -> V_26 , V_27 ) ;
if ( ! V_9 ) {
V_5 = - V_28 ;
goto error;
}
if ( V_8 == ( V_15 | V_16 ) ) {
memcpy ( V_9 , V_4 -> V_29 , V_4 -> V_26 ) ;
V_6 = F_4 ( V_2 , 0 ) ;
} else {
V_6 = F_5 ( V_2 , 0 ) ;
}
F_6 ( 1 ) ;
V_5 = F_7 ( V_2 , V_6 , V_7 , V_8 , V_4 -> V_30 ,
V_4 -> V_31 , V_9 , V_4 -> V_26 , V_32 ) ;
F_8 ( V_7 , V_8 , V_4 -> V_30 , V_4 -> V_31 , V_9 ,
V_4 -> V_26 , V_33 ) ;
if ( V_5 < 0 )
goto V_34;
else
V_5 = 0 ;
if ( ! V_5 && V_8 == ( V_15 | V_18 ) )
memcpy ( V_4 -> V_29 , V_9 , V_4 -> V_26 ) ;
F_9 ( V_9 ) ;
return V_5 ;
V_34:
F_9 ( V_9 ) ;
error:
F_10 ( L_2 , V_35 , V_5 ) ;
return V_5 ;
}
static int F_11 ( struct V_36 * V_37 , struct V_3 * V_4 )
{
return F_1 ( V_37 -> V_2 , V_4 ) ;
}
static int F_12 ( struct V_38 * V_39 , struct V_40 V_41 [] ,
int V_42 )
{
struct V_36 * V_37 = F_13 ( V_39 ) ;
struct V_3 V_4 ;
int V_43 = 0 ;
int V_5 ;
if ( V_42 > 2 )
return - V_44 ;
if ( F_14 ( & V_37 -> V_45 ) < 0 )
return - V_46 ;
while ( V_43 < V_42 ) {
if ( V_42 > V_43 + 1 && ( V_41 [ V_43 + 1 ] . V_47 & V_48 ) ) {
if ( V_41 [ V_43 ] . V_49 == V_50 . V_51 ) {
V_4 . V_10 = V_24 ;
V_4 . V_30 = 0 ;
V_4 . V_31 = 0xff00 + V_41 [ V_43 ] . V_9 [ 0 ] ;
V_4 . V_26 = V_41 [ V_43 + 1 ] . V_52 ;
V_4 . V_29 = & V_41 [ V_43 + 1 ] . V_9 [ 0 ] ;
V_5 = F_11 ( V_37 , & V_4 ) ;
V_43 += 2 ;
} else {
F_2 ( L_3 ) ;
V_5 = - V_53 ;
V_43 += 2 ;
}
} else {
if ( V_41 [ V_43 ] . V_49 == V_50 . V_51 ) {
V_4 . V_10 = V_22 ;
V_4 . V_30 = V_41 [ V_43 ] . V_9 [ 1 ] ;
V_4 . V_31 = 0xff00 + V_41 [ V_43 ] . V_9 [ 0 ] ;
V_4 . V_26 = 0 ;
V_4 . V_29 = NULL ;
V_5 = F_11 ( V_37 , & V_4 ) ;
V_43 += 1 ;
} else {
V_4 . V_10 = V_13 ;
V_4 . V_30 = V_41 [ V_43 ] . V_9 [ 0 ] ;
V_4 . V_31 = 0x0100 + V_41 [ V_43 ] . V_49 ;
V_4 . V_26 = V_41 [ V_43 ] . V_52 - 1 ;
V_4 . V_29 = & V_41 [ V_43 ] . V_9 [ 1 ] ;
V_5 = F_11 ( V_37 , & V_4 ) ;
V_43 += 1 ;
}
}
if ( V_5 )
goto error;
}
V_5 = V_43 ;
error:
F_15 ( & V_37 -> V_45 ) ;
return V_43 ;
}
static T_2 F_16 ( struct V_38 * V_54 )
{
return V_55 ;
}
static int F_17 ( struct V_56 * V_39 )
{
F_10 ( L_4 , V_35 ) ;
V_39 -> V_57 [ 0 ] . V_58 = F_18 ( V_59 , & V_50 ,
& V_39 -> V_60 -> V_61 ) ;
if ( V_39 -> V_57 [ 0 ] . V_58 == NULL )
return - V_62 ;
return 0 ;
}
static int F_19 ( struct V_56 * V_39 )
{
F_10 ( L_4 , V_35 ) ;
return F_18 ( V_63 , V_39 -> V_57 [ 0 ] . V_58 , & V_39 -> V_60 -> V_61 ,
& V_64 ) == NULL ? - V_62 : 0 ;
}
static int F_20 ( struct V_56 * V_39 , int V_65 )
{
struct V_3 V_4 = { V_14 , 0x7f01 , 0x0202 , 0 , NULL } ;
F_10 ( L_5 , V_35 , V_65 ) ;
if ( V_65 )
V_4 . V_31 = 0x0102 ;
return F_11 ( V_39 -> V_60 , & V_4 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_66 * V_67 )
{
int V_43 , V_52 , V_68 , V_69 , V_5 ;
T_3 V_49 = 0x0000 ;
struct V_3 V_4 = { V_11 , 0 , 0 , 0 , NULL } ;
F_10 ( L_4 , V_35 ) ;
#define F_22 2048
V_68 = V_67 -> V_26 / F_22 ;
V_69 = V_67 -> V_26 % F_22 ;
V_52 = F_22 ;
for ( V_43 = 0 ; V_43 <= V_68 ; V_43 ++ ) {
if ( V_43 == V_68 )
V_52 = V_69 ;
V_4 . V_26 = V_52 ;
V_4 . V_29 = ( T_1 * ) ( V_67 -> V_29 + V_43 * F_22 ) ;
V_4 . V_31 = V_49 ;
V_49 += F_22 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 ) {
F_2 ( L_6 , V_5 , V_43 ) ;
goto error;
}
}
V_4 . V_26 = 0 ;
V_4 . V_10 = V_21 ;
V_4 . V_30 = 0 ;
V_4 . V_31 = 0x0001 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto error;
V_4 . V_10 = V_12 ;
V_4 . V_30 = 0 ;
V_4 . V_31 = 0x0206 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto error;
V_4 . V_10 = V_13 ;
V_4 . V_30 = 0 ;
V_4 . V_31 = 0x00c6 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto error;
return V_5 ;
error:
F_10 ( L_2 , V_35 , V_5 ) ;
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
struct V_72 * * V_73 , int * V_74 )
{
int V_5 ;
T_1 V_75 ;
struct V_3 V_4 = { V_19 , 0 , 1 , sizeof( V_75 ) , & V_75 } ;
F_10 ( L_4 , V_35 ) ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto error;
F_10 ( L_7 , V_35 , V_75 ) ;
if ( V_75 == 0x01 )
* V_74 = 0 ;
else
* V_74 = 1 ;
return V_5 ;
error:
F_10 ( L_2 , V_35 , V_5 ) ;
return V_5 ;
}
static int F_24 ( struct V_76 * V_77 ,
const struct V_78 * V_79 )
{
int V_5 ;
F_10 ( L_8 , V_35 ,
V_77 -> V_80 -> V_73 . V_81 ) ;
V_5 = F_25 ( V_77 , & V_82 , V_83 , NULL ,
V_84 ) ;
if ( V_5 )
goto error;
return V_5 ;
error:
F_10 ( L_2 , V_35 , V_5 ) ;
return V_5 ;
}
