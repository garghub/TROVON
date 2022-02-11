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
struct V_19 V_20 = { 0 } ;
struct V_21 * V_22 =
(struct V_21 * ) V_20 . V_23 ;
int V_24 = 0 , V_25 = 0 ;
int V_26 ;
int V_27 ;
struct V_28 * V_29 = F_4 ( V_2 ) ;
V_22 -> V_10 = 0 ;
while ( 1 ) {
while ( V_5 [ V_25 ] && isspace ( V_5 [ V_25 ] ) )
V_25 ++ ;
if ( ! V_5 [ V_25 ] )
break;
for ( V_26 = 0 ; V_26 < F_5 ( V_11 ) ; V_26 ++ ) {
if ( ! strncasecmp ( V_11 [ V_26 ] . V_8 , V_5 + V_25 ,
strlen ( V_11 [ V_26 ] . V_8 ) ) ) {
if ( V_11 [ V_26 ] . V_10 ) {
V_22 -> V_10 |= V_11 [ V_26 ] . V_10 ;
} else {
V_22 -> V_9 = V_11 [ V_26 ] . V_9 ;
V_24 = 1 ;
}
break;
}
}
while ( V_5 [ V_25 ] && ! isspace ( V_5 [ V_25 ] ) )
V_25 ++ ;
}
if ( ! V_24 )
return - V_30 ;
V_20 . V_31 = V_32 ;
V_20 . V_33 = sizeof( V_22 ) ;
V_27 = F_6 ( V_29 , & V_20 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_20 . V_34 != V_35 ) {
F_7 ( V_29 -> V_2 , L_10 , V_20 . V_34 ) ;
return - V_30 ;
}
return V_6 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
static const char * const V_36 [] = { L_11 , L_12 , L_13 } ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_19 V_20 = { 0 } ;
int V_27 ;
int V_6 = 0 ;
struct V_28 * V_29 = F_4 ( V_2 ) ;
V_20 . V_31 = V_43 ;
V_20 . V_44 = sizeof( * V_38 ) ;
V_27 = F_6 ( V_29 , & V_20 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_20 . V_34 != V_35 )
return F_2 ( V_5 , V_7 ,
L_14 , V_20 . V_34 ) ;
V_38 = (struct V_37 * ) V_20 . V_45 ;
V_38 -> V_46 [ sizeof( V_38 -> V_46 ) - 1 ] = '\0' ;
V_38 -> V_47 [ sizeof( V_38 -> V_47 ) - 1 ] = '\0' ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_15 , V_38 -> V_46 ) ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_16 , V_38 -> V_47 ) ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_17 ,
( V_38 -> V_48 < F_5 ( V_36 ) ?
V_36 [ V_38 -> V_48 ] : L_18 ) ) ;
V_20 . V_31 = V_49 ;
V_20 . V_44 = sizeof( V_20 . V_45 ) ;
V_27 = F_6 ( V_29 , & V_20 ) ;
if ( V_27 < 0 )
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_19 , V_27 ) ;
else if ( V_20 . V_34 != V_35 )
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_20 , V_20 . V_34 ) ;
else {
V_20 . V_45 [ sizeof( V_20 . V_45 ) - 1 ] = '\0' ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_21 , V_20 . V_45 ) ;
}
V_20 . V_31 = V_50 ;
V_20 . V_44 = sizeof( * V_40 ) ;
V_27 = F_6 ( V_29 , & V_20 ) ;
if ( V_27 < 0 )
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_22 , V_27 ) ;
else if ( V_20 . V_34 != V_35 )
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_23 , V_20 . V_34 ) ;
else {
V_40 = (struct V_39 * ) V_20 . V_45 ;
V_40 -> V_51 [ sizeof( V_40 -> V_51 ) - 1 ] = '\0' ;
V_40 -> V_52 [ sizeof( V_40 -> V_52 ) - 1 ] = '\0' ;
V_40 -> V_53 [ sizeof( V_40 -> V_53 ) - 1 ] = '\0' ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_24 , V_40 -> V_51 ) ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_25 , V_40 -> V_52 ) ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_26 , V_40 -> V_53 ) ;
}
V_20 . V_31 = V_54 ;
V_20 . V_44 = sizeof( * V_42 ) ;
V_27 = F_6 ( V_29 , & V_20 ) ;
if ( V_27 < 0 )
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_27 , V_27 ) ;
else if ( V_20 . V_34 != V_35 )
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_28 , V_20 . V_34 ) ;
else {
V_42 = (struct V_41 * ) V_20 . V_45 ;
V_6 += F_2 ( V_5 + V_6 , V_7 - V_6 ,
L_29 ,
V_42 -> V_55 ) ;
}
return V_6 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_56 * V_57 ;
struct V_19 V_20 = { 0 } ;
int V_27 ;
struct V_28 * V_29 = F_4 ( V_2 ) ;
V_20 . V_31 = V_58 ;
V_20 . V_44 = sizeof( * V_57 ) ;
V_27 = F_6 ( V_29 , & V_20 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_20 . V_34 != V_35 )
return F_2 ( V_5 , V_7 ,
L_14 , V_20 . V_34 ) ;
V_57 = (struct V_56 * ) V_20 . V_45 ;
return F_2 ( V_5 , V_7 ,
L_30
L_31 ,
V_57 -> V_59 , V_57 -> V_60 ,
V_57 -> V_61 , V_57 -> V_62 ) ;
}
void F_10 ( struct V_28 * V_29 )
{
int error ;
error = F_11 ( & V_29 -> V_63 -> V_64 , & V_65 ) ;
if ( error )
F_12 ( L_32 , error ) ;
}
void F_13 ( struct V_28 * V_29 )
{
F_14 ( & V_29 -> V_63 -> V_64 , & V_65 ) ;
}
