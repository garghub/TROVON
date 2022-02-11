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
F_2 ( & V_2 -> V_25 -> V_26 , L_1 ,
V_27 , V_4 -> V_10 ) ;
V_5 = - V_28 ;
goto error;
}
V_9 = F_3 ( V_4 -> V_29 , V_30 ) ;
if ( ! V_9 ) {
V_5 = - V_31 ;
goto error;
}
if ( V_8 == ( V_15 | V_16 ) ) {
memcpy ( V_9 , V_4 -> V_32 , V_4 -> V_29 ) ;
V_6 = F_4 ( V_2 -> V_25 , 0 ) ;
} else {
V_6 = F_5 ( V_2 -> V_25 , 0 ) ;
}
F_6 ( 1 ) ;
V_5 = F_7 ( V_2 -> V_25 , V_6 , V_7 , V_8 , V_4 -> V_33 ,
V_4 -> V_34 , V_9 , V_4 -> V_29 , V_35 ) ;
F_8 ( V_2 -> V_25 , V_7 , V_8 , V_4 -> V_33 ,
V_4 -> V_34 , V_9 , V_4 -> V_29 ) ;
if ( V_5 < 0 )
goto V_36;
else
V_5 = 0 ;
if ( ! V_5 && V_8 == ( V_15 | V_18 ) )
memcpy ( V_4 -> V_32 , V_9 , V_4 -> V_29 ) ;
F_9 ( V_9 ) ;
return V_5 ;
V_36:
F_9 ( V_9 ) ;
error:
F_10 ( & V_2 -> V_25 -> V_26 , L_2 , V_37 , V_5 ) ;
return V_5 ;
}
static int F_11 ( struct V_38 * V_39 , struct V_40 V_41 [] ,
int V_42 )
{
struct V_1 * V_2 = F_12 ( V_39 ) ;
struct V_3 V_4 ;
int V_43 = 0 ;
int V_5 ;
if ( V_42 > 2 )
return - V_28 ;
if ( F_13 ( & V_2 -> V_44 ) < 0 )
return - V_45 ;
while ( V_43 < V_42 ) {
if ( V_42 > V_43 + 1 && ( V_41 [ V_43 + 1 ] . V_46 & V_47 ) ) {
if ( V_41 [ V_43 ] . V_48 == V_49 . V_50 ) {
V_4 . V_10 = V_24 ;
V_4 . V_33 = 0 ;
V_4 . V_34 = 0xff00 + V_41 [ V_43 ] . V_9 [ 0 ] ;
V_4 . V_29 = V_41 [ V_43 + 1 ] . V_51 ;
V_4 . V_32 = & V_41 [ V_43 + 1 ] . V_9 [ 0 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
V_43 += 2 ;
} else {
F_2 ( & V_2 -> V_25 -> V_26 , L_3 \
L_4 ,
V_27 ) ;
V_5 = - V_52 ;
V_43 += 2 ;
}
} else {
if ( V_41 [ V_43 ] . V_48 == V_49 . V_50 ) {
V_4 . V_10 = V_22 ;
V_4 . V_33 = V_41 [ V_43 ] . V_9 [ 1 ] ;
V_4 . V_34 = 0xff00 + V_41 [ V_43 ] . V_9 [ 0 ] ;
V_4 . V_29 = 0 ;
V_4 . V_32 = NULL ;
V_5 = F_1 ( V_2 , & V_4 ) ;
V_43 += 1 ;
} else {
V_4 . V_10 = V_13 ;
V_4 . V_33 = V_41 [ V_43 ] . V_9 [ 0 ] ;
V_4 . V_34 = 0x0100 + V_41 [ V_43 ] . V_48 ;
V_4 . V_29 = V_41 [ V_43 ] . V_51 - 1 ;
V_4 . V_32 = & V_41 [ V_43 ] . V_9 [ 1 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
V_43 += 1 ;
}
}
if ( V_5 )
goto error;
}
V_5 = V_43 ;
error:
F_14 ( & V_2 -> V_44 ) ;
return V_5 ;
}
static T_2 F_15 ( struct V_38 * V_53 )
{
return V_54 ;
}
static int F_16 ( struct V_1 * V_2 , const char * * V_55 )
{
int V_5 ;
T_1 V_56 ;
struct V_3 V_4 = { V_19 , 0 , 1 , sizeof( V_56 ) , & V_56 } ;
F_10 ( & V_2 -> V_25 -> V_26 , L_5 , V_37 ) ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto error;
F_10 ( & V_2 -> V_25 -> V_26 , L_6 , V_37 , V_56 ) ;
if ( V_56 == 0x01 )
V_5 = V_57 ;
else
V_5 = V_58 ;
return V_5 ;
error:
F_10 ( & V_2 -> V_25 -> V_26 , L_2 , V_37 , V_5 ) ;
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_59 * V_60 )
{
int V_5 , V_51 , V_61 ;
struct V_3 V_4 = { V_11 , 0 , 0 , 0 , NULL } ;
F_10 ( & V_2 -> V_25 -> V_26 , L_5 , V_37 ) ;
#define F_18 2048
for ( V_61 = V_60 -> V_29 ; V_61 > 0 ; V_61 -= F_18 ) {
V_51 = V_61 ;
if ( V_51 > F_18 )
V_51 = F_18 ;
V_4 . V_29 = V_51 ;
V_4 . V_32 = ( T_1 * ) & V_60 -> V_32 [ V_60 -> V_29 - V_61 ] ;
V_4 . V_34 = V_60 -> V_29 - V_61 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 ) {
F_2 ( & V_2 -> V_25 -> V_26 ,
L_7 ,
V_27 , V_5 ) ;
goto error;
}
}
V_4 . V_29 = 0 ;
V_4 . V_10 = V_21 ;
V_4 . V_33 = 0 ;
V_4 . V_34 = 0x0001 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto error;
V_4 . V_10 = V_12 ;
V_4 . V_33 = 0 ;
V_4 . V_34 = 0x0206 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto error;
V_4 . V_10 = V_13 ;
V_4 . V_33 = 0 ;
V_4 . V_34 = 0x00c6 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto error;
return V_5 ;
error:
F_10 ( & V_2 -> V_25 -> V_26 , L_2 , V_37 , V_5 ) ;
return V_5 ;
}
static int F_19 ( struct V_62 * V_39 )
{
struct V_1 * V_2 = F_20 ( V_39 ) ;
F_10 ( & V_2 -> V_25 -> V_26 , L_5 , V_37 ) ;
V_39 -> V_63 [ 0 ] = F_21 ( V_64 , & V_49 ,
& V_2 -> V_65 ) ;
if ( V_39 -> V_63 [ 0 ] == NULL )
return - V_66 ;
return 0 ;
}
static int F_22 ( struct V_62 * V_39 )
{
struct V_1 * V_2 = F_20 ( V_39 ) ;
F_10 ( & V_2 -> V_25 -> V_26 , L_5 , V_37 ) ;
return F_21 ( V_67 , V_39 -> V_63 [ 0 ] , & V_2 -> V_65 ,
& V_68 ) == NULL ? - V_66 : 0 ;
}
static int F_23 ( struct V_69 * V_63 , int V_70 )
{
struct V_1 * V_2 = F_24 ( V_63 ) ;
struct V_3 V_4 = { V_14 , 0x7f01 , 0x0202 , 0 , NULL } ;
F_10 ( & V_2 -> V_25 -> V_26 , L_8 , V_37 , V_70 ) ;
if ( V_70 )
V_4 . V_34 = 0x0102 ;
return F_1 ( V_2 , & V_4 ) ;
}
