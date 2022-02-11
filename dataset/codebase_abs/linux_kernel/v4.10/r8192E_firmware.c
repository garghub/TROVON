static bool F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned long V_5 = V_6 + F_2 ( V_4 ) ;
while ( F_3 ( V_6 , V_5 ) ) {
if ( F_4 ( V_2 , V_7 ) & V_3 )
return true ;
F_5 ( 2 ) ;
}
return false ;
}
static bool F_6 ( struct V_1 * V_2 )
{
T_1 V_8 = 0 ;
if ( ! F_1 ( V_2 , V_9 , 200 ) ) {
F_7 ( V_2 , L_1 ) ;
return false ;
}
F_8 ( V_2 , L_2 ) ;
V_8 = F_4 ( V_2 , V_7 ) ;
F_9 ( V_2 , V_7 ,
( V_10 ) ( ( V_8 | V_11 ) & 0xff ) ) ;
F_5 ( 1 ) ;
if ( ! F_1 ( V_2 , V_12 , 200 ) ) {
F_7 ( V_2 , L_3 ) ;
return false ;
}
F_8 ( V_2 , L_4 ) ;
return true ;
}
static bool F_10 ( struct V_1 * V_2 ,
V_10 V_13 )
{
struct V_14 * V_15 = F_11 ( V_2 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
bool V_19 = true ;
switch ( V_13 ) {
case V_20 :
V_17 -> V_21 = V_22 ;
break;
case V_23 :
V_17 -> V_21 = V_24 ;
V_19 = F_6 ( V_2 ) ;
if ( V_19 )
V_17 -> V_21 = V_25 ;
else
F_8 ( V_2 , L_5 ) ;
break;
case V_26 :
V_17 -> V_21 = V_27 ;
F_5 ( 1 ) ;
V_19 = F_1 ( V_2 , V_28 , 20 ) ;
if ( V_19 )
V_17 -> V_21 = V_29 ;
else
F_12 ( V_30 ,
L_6 ,
V_19 ) ;
break;
default:
V_19 = false ;
F_8 ( V_2 , L_7 ) ;
break;
}
return V_19 ;
}
static bool F_13 ( struct V_1 * V_2 , struct V_31 * V_32 ,
const char * V_33 , V_10 V_34 )
{
const struct V_35 * V_36 ;
int V_37 , V_38 ;
bool V_39 = true ;
V_37 = F_14 ( & V_36 , V_33 , & V_2 -> V_2 ) ;
if ( V_37 < 0 )
return false ;
if ( F_15 ( V_36 -> V_40 , 4 ) > V_41 - V_34 ) {
F_7 ( V_2 , L_8 ,
V_33 ) ;
V_39 = false ;
goto V_42;
}
if ( V_34 )
memset ( V_32 -> V_43 , 0 , V_34 ) ;
if ( V_36 -> V_40 % 4 )
memset ( V_32 -> V_43 + V_34 + V_36 -> V_40 , 0 , 4 ) ;
memcpy ( V_32 -> V_43 + V_34 , V_36 -> V_43 , V_36 -> V_40 ) ;
V_32 -> V_40 = F_15 ( V_36 -> V_40 , 4 ) + V_34 ;
for ( V_38 = V_34 ; V_38 < V_32 -> V_40 ; V_38 += 4 ) {
T_1 * V_43 = ( T_1 * ) ( V_32 -> V_43 + V_38 ) ;
* V_43 = F_16 ( V_43 ) ;
}
V_42:
F_17 ( V_36 ) ;
return V_39 ;
}
bool F_18 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_11 ( V_2 ) ;
bool V_19 = true ;
T_1 V_44 = 0 ;
V_10 * V_45 = NULL ;
V_10 V_38 = 0 ;
enum V_46 V_47 = V_48 ;
enum V_49 V_50 = V_20 ;
struct V_16 * V_17 = V_15 -> V_18 ;
F_8 ( V_2 , L_9 ) ;
if ( V_17 -> V_21 == V_51 ) {
V_47 = V_48 ;
V_50 = V_20 ;
} else if ( V_17 -> V_21 == V_29 ) {
V_47 = V_52 ;
V_50 = V_26 ;
} else {
F_12 ( V_30 ,
L_10 ) ;
}
for ( V_38 = V_50 ; V_38 <= V_26 ; V_38 ++ ) {
if ( V_47 == V_48 ) {
if ( V_17 -> V_53 [ V_38 ] . V_40 == 0 ) {
const char * V_54 [ 3 ] = {
V_55 ,
V_56 ,
V_57
} ;
int V_58 = 0 ;
if ( V_38 == V_23 )
V_58 = 128 ;
if ( ! F_13 ( V_2 ,
& V_17 -> V_53 [ V_38 ] ,
V_54 [ V_38 ] ,
V_58 ) )
goto V_59;
}
}
V_45 = V_17 -> V_53 [ V_38 ] . V_43 ;
V_44 = V_17 -> V_53 [ V_38 ] . V_40 ;
V_19 = F_19 ( V_2 , V_60 ,
V_45 , V_44 ) ;
if ( ! V_19 )
goto V_59;
if ( ! F_10 ( V_2 , V_38 ) )
goto V_59;
}
F_8 ( V_2 , L_11 ) ;
return V_19 ;
V_59:
F_7 ( V_2 , L_12 , V_61 ) ;
return false ;
}
