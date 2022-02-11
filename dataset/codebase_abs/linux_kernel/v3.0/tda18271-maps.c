int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_4 -> V_7 ;
int V_8 , V_9 = 0 ;
while ( V_10 [ V_9 ] . V_11 < ( V_6 [ V_12 ] & 0x0f ) ) {
if ( V_10 [ V_9 + 1 ] . V_11 == 0 )
break;
V_9 ++ ;
}
if ( ( V_6 [ V_12 ] & 0x20 ) == 0x20 )
V_8 = V_10 [ V_9 ] . V_13 ;
else
V_8 = V_10 [ V_9 ] . V_14 ;
F_2 ( L_1 , V_9 , V_8 ) ;
return V_8 ;
}
int F_3 ( struct V_1 * V_2 ,
T_1 * V_15 , T_2 * V_16 , T_3 * V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 = 0 ;
while ( ( V_18 [ V_9 ] . V_19 * 1000 ) < * V_15 ) {
if ( V_18 [ V_9 + 1 ] . V_19 == 0 )
break;
V_9 ++ ;
}
* V_16 = V_18 [ V_9 ] . V_20 ;
* V_17 = V_18 [ V_9 ] . V_21 ;
F_2 ( L_2 , V_9 ,
V_18 [ V_9 ] . V_20 , V_18 [ V_9 ] . V_21 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , T_1 * V_15 , T_2 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 = V_4 -> V_25 ;
int V_9 = 0 ;
while ( ( V_24 [ V_9 ] . V_19 * 1000 ) < * V_15 ) {
if ( V_26 & V_27 )
F_2 ( L_3
L_4
L_5
L_6
L_7 ,
V_9 , V_24 [ V_9 ] . V_19 * 1000 , * V_15 ,
V_24 [ V_9 ] . V_28 , V_24 [ V_9 ] . V_29 , V_24 [ V_9 ] . V_30 ,
V_24 [ V_9 ] . V_31 , V_24 [ V_9 ] . V_32 , V_24 [ V_9 ] . V_33 ,
V_24 [ V_9 ] . V_34 , V_24 [ V_9 ] . V_35 ,
V_24 [ V_9 ] . V_36 , V_24 [ V_9 ] . V_37 ) ;
if ( V_24 [ V_9 ] . V_19 == 0 )
return - V_38 ;
V_9 ++ ;
}
if ( V_22 )
* V_22 = V_24 [ V_9 ] . V_39 ;
F_2 ( L_8 , V_9 , V_24 [ V_9 ] . V_39 ) ;
return V_9 ;
}
int F_5 ( struct V_1 * V_2 ,
enum V_40 V_41 ,
T_1 * V_15 , T_2 * V_42 , T_2 * div )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_43 * V_24 = NULL ;
unsigned int V_9 = 0 ;
char * V_44 ;
int V_45 = 0 ;
F_6 ( ! V_4 -> V_46 ) ;
switch ( V_41 ) {
case V_47 :
V_24 = V_4 -> V_46 -> V_48 ;
V_44 = L_9 ;
break;
case V_49 :
V_24 = V_4 -> V_46 -> V_50 ;
V_44 = L_10 ;
break;
default:
V_44 = L_11 ;
break;
}
if ( ! V_24 ) {
F_7 ( L_12 , V_44 ) ;
V_45 = - V_38 ;
goto V_51;
}
while ( ( V_24 [ V_9 ] . V_52 * 1000 ) < * V_15 ) {
if ( V_24 [ V_9 + 1 ] . V_52 == 0 ) {
F_2 ( L_13 ,
V_44 , * V_15 ) ;
V_45 = - V_53 ;
break;
}
V_9 ++ ;
}
* V_42 = V_24 [ V_9 ] . V_54 ;
* div = V_24 [ V_9 ] . V_11 ;
F_2 ( L_14 ,
V_9 , V_44 , * V_42 , * div ) ;
V_51:
return V_45 ;
}
int F_8 ( struct V_1 * V_2 ,
enum V_40 V_41 ,
T_1 * V_15 , T_2 * V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_55 * V_24 = NULL ;
unsigned int V_9 = 0 ;
char * V_44 ;
int V_45 = 0 ;
F_6 ( ! V_4 -> V_46 ) ;
switch ( V_41 ) {
case V_56 :
V_24 = V_4 -> V_46 -> V_57 ;
V_44 = L_15 ;
break;
case V_58 :
V_24 = V_4 -> V_46 -> V_59 ;
V_44 = L_16 ;
break;
case V_60 :
V_24 = V_4 -> V_46 -> V_22 ;
V_44 = L_17 ;
break;
case V_61 :
V_24 = V_4 -> V_46 -> V_62 ;
V_44 = L_18 ;
break;
case V_63 :
V_24 = V_4 -> V_46 -> V_64 ;
V_44 = L_19 ;
break;
case V_65 :
V_24 = V_4 -> V_46 -> V_66 ;
V_44 = L_20 ;
break;
case V_67 :
V_24 = V_4 -> V_46 -> V_68 ;
V_44 = L_21 ;
break;
default:
V_44 = L_11 ;
break;
}
if ( ! V_24 ) {
F_7 ( L_12 , V_44 ) ;
V_45 = - V_38 ;
goto V_51;
}
while ( ( V_24 [ V_9 ] . V_19 * 1000 ) < * V_15 ) {
if ( V_24 [ V_9 + 1 ] . V_19 == 0 ) {
F_2 ( L_13 ,
V_44 , * V_15 ) ;
V_45 = - V_53 ;
break;
}
V_9 ++ ;
}
* V_8 = V_24 [ V_9 ] . V_8 ;
F_2 ( L_22 , V_9 , V_44 , * V_8 ) ;
V_51:
return V_45 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_45 = 0 ;
switch ( V_4 -> V_69 ) {
case V_70 :
V_4 -> V_46 = & V_71 ;
memcpy ( & V_4 -> V_72 , & V_73 ,
sizeof( struct V_74 ) ) ;
break;
case V_75 :
V_4 -> V_46 = & V_76 ;
memcpy ( & V_4 -> V_72 , & V_77 ,
sizeof( struct V_74 ) ) ;
break;
default:
V_45 = - V_38 ;
break;
}
memcpy ( V_4 -> V_25 , & V_78 ,
sizeof( V_78 ) ) ;
return V_45 ;
}
