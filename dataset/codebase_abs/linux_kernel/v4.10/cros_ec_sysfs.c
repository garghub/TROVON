static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_6 = 0 ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_1 ) ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_2 ) ;
return V_6 ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
static const struct {
const char * const V_8 ;
T_3 V_9 ;
T_3 V_10 ;
} V_11 [] = {
{ L_3 , V_12 , 0 } ,
{ L_4 , V_13 , 0 } ,
{ L_5 , V_14 , 0 } ,
{ L_6 , V_15 , 0 } ,
{ L_7 , V_16 , 0 } ,
{ L_8 , V_17 , 0 } ,
{ L_9 , - 1 , V_18 } ,
} ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 = 0 , V_24 = 0 ;
int V_25 ;
int V_26 ;
struct V_27 * V_28 = F_4 ( V_2 ,
struct V_27 , V_29 ) ;
V_20 = F_5 ( sizeof( * V_20 ) + sizeof( * V_22 ) , V_30 ) ;
if ( ! V_20 )
return - V_31 ;
V_22 = (struct V_21 * ) V_20 -> V_32 ;
V_22 -> V_10 = 0 ;
while ( 1 ) {
while ( V_5 [ V_24 ] && isspace ( V_5 [ V_24 ] ) )
V_24 ++ ;
if ( ! V_5 [ V_24 ] )
break;
for ( V_25 = 0 ; V_25 < F_6 ( V_11 ) ; V_25 ++ ) {
if ( ! strncasecmp ( V_11 [ V_25 ] . V_8 , V_5 + V_24 ,
strlen ( V_11 [ V_25 ] . V_8 ) ) ) {
if ( V_11 [ V_25 ] . V_10 ) {
V_22 -> V_10 |= V_11 [ V_25 ] . V_10 ;
} else {
V_22 -> V_9 = V_11 [ V_25 ] . V_9 ;
V_23 = 1 ;
}
break;
}
}
while ( V_5 [ V_24 ] && ! isspace ( V_5 [ V_24 ] ) )
V_24 ++ ;
}
if ( ! V_23 ) {
V_6 = - V_33 ;
goto exit;
}
V_20 -> V_34 = 0 ;
V_20 -> V_35 = V_36 + V_28 -> V_37 ;
V_20 -> V_38 = sizeof( * V_22 ) ;
V_20 -> V_39 = 0 ;
V_26 = F_7 ( V_28 -> V_40 , V_20 ) ;
if ( V_26 < 0 ) {
V_6 = V_26 ;
goto exit;
}
if ( V_20 -> V_41 != V_42 ) {
F_8 ( V_28 -> V_2 , L_10 , V_20 -> V_41 ) ;
V_6 = - V_33 ;
}
exit:
F_9 ( V_20 ) ;
return V_6 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
static const char * const V_43 [] = { L_11 , L_12 , L_13 } ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_19 * V_20 ;
int V_26 ;
int V_6 = 0 ;
struct V_27 * V_28 = F_4 ( V_2 ,
struct V_27 , V_29 ) ;
V_20 = F_5 ( sizeof( * V_20 ) + V_50 , V_30 ) ;
if ( ! V_20 )
return - V_31 ;
V_20 -> V_34 = 0 ;
V_20 -> V_35 = V_51 + V_28 -> V_37 ;
V_20 -> V_39 = sizeof( * V_45 ) ;
V_20 -> V_38 = 0 ;
V_26 = F_7 ( V_28 -> V_40 , V_20 ) ;
if ( V_26 < 0 ) {
V_6 = V_26 ;
goto exit;
}
if ( V_20 -> V_41 != V_42 ) {
V_6 = F_2 ( V_5 , V_7 ,
L_14 , V_20 -> V_41 ) ;
goto exit;
}
V_45 = (struct V_44 * ) V_20 -> V_32 ;
V_45 -> V_52 [ sizeof( V_45 -> V_52 ) - 1 ] = '\0' ;
V_45 -> V_53 [ sizeof( V_45 -> V_53 ) - 1 ] = '\0' ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_15 , V_45 -> V_52 ) ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_16 , V_45 -> V_53 ) ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_17 ,
( V_45 -> V_54 < F_6 ( V_43 ) ?
V_43 [ V_45 -> V_54 ] : L_18 ) ) ;
V_20 -> V_35 = V_55 + V_28 -> V_37 ;
V_20 -> V_39 = V_50 ;
V_26 = F_7 ( V_28 -> V_40 , V_20 ) ;
if ( V_26 < 0 )
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_19 , V_26 ) ;
else if ( V_20 -> V_41 != V_42 )
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_20 , V_20 -> V_41 ) ;
else {
V_20 -> V_32 [ sizeof( V_20 -> V_32 ) - 1 ] = '\0' ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_21 , V_20 -> V_32 ) ;
}
V_20 -> V_35 = V_56 + V_28 -> V_37 ;
V_20 -> V_39 = sizeof( * V_47 ) ;
V_26 = F_7 ( V_28 -> V_40 , V_20 ) ;
if ( V_26 < 0 )
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_22 , V_26 ) ;
else if ( V_20 -> V_41 != V_42 )
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_23 , V_20 -> V_41 ) ;
else {
V_47 = (struct V_46 * ) V_20 -> V_32 ;
V_47 -> V_57 [ sizeof( V_47 -> V_57 ) - 1 ] = '\0' ;
V_47 -> V_58 [ sizeof( V_47 -> V_58 ) - 1 ] = '\0' ;
V_47 -> V_59 [ sizeof( V_47 -> V_59 ) - 1 ] = '\0' ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_24 , V_47 -> V_57 ) ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_25 , V_47 -> V_58 ) ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_26 , V_47 -> V_59 ) ;
}
V_20 -> V_35 = V_60 + V_28 -> V_37 ;
V_20 -> V_39 = sizeof( * V_49 ) ;
V_26 = F_7 ( V_28 -> V_40 , V_20 ) ;
if ( V_26 < 0 )
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_27 , V_26 ) ;
else if ( V_20 -> V_41 != V_42 )
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_28 , V_20 -> V_41 ) ;
else {
V_49 = (struct V_48 * ) V_20 -> V_32 ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_29 ,
V_49 -> V_61 ) ;
}
exit:
F_9 ( V_20 ) ;
return V_6 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_62 * V_63 ;
struct V_19 * V_20 ;
int V_26 ;
struct V_27 * V_28 = F_4 ( V_2 ,
struct V_27 , V_29 ) ;
V_20 = F_5 ( sizeof( * V_20 ) + sizeof( * V_63 ) , V_30 ) ;
if ( ! V_20 )
return - V_31 ;
V_20 -> V_34 = 0 ;
V_20 -> V_35 = V_64 + V_28 -> V_37 ;
V_20 -> V_39 = sizeof( * V_63 ) ;
V_20 -> V_38 = 0 ;
V_26 = F_7 ( V_28 -> V_40 , V_20 ) ;
if ( V_26 < 0 )
goto exit;
if ( V_20 -> V_41 != V_42 ) {
V_26 = F_2 ( V_5 , V_7 ,
L_14 , V_20 -> V_41 ) ;
goto exit;
}
V_63 = (struct V_62 * ) V_20 -> V_32 ;
V_26 = F_2 ( V_5 , V_7 ,
L_30
L_31 ,
V_63 -> V_65 , V_63 -> V_66 ,
V_63 -> V_67 , V_63 -> V_68 ) ;
exit:
F_9 ( V_20 ) ;
return V_26 ;
}
