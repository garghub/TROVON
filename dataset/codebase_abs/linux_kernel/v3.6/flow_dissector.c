static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
F_2 ( F_3 ( F_4 ( * V_2 ) , V_5 ) !=
F_3 ( F_4 ( * V_2 ) , V_6 ) + sizeof( V_2 -> V_6 ) ) ;
memcpy ( & V_2 -> V_6 , & V_4 -> V_7 , sizeof( V_2 -> V_6 ) + sizeof( V_2 -> V_5 ) ) ;
}
bool F_5 ( const struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_10 , V_11 = F_6 ( V_9 ) ;
T_1 V_12 ;
T_2 V_13 = V_9 -> V_14 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_15:
switch ( V_13 ) {
case F_7 ( V_16 ) : {
const struct V_3 * V_4 ;
struct V_3 V_17 ;
V_18:
V_4 = F_8 ( V_9 , V_11 , sizeof( V_17 ) , & V_17 ) ;
if ( ! V_4 )
return false ;
if ( F_9 ( V_4 ) )
V_12 = 0 ;
else
V_12 = V_4 -> V_14 ;
F_1 ( V_2 , V_4 ) ;
V_11 += V_4 -> V_19 * 4 ;
break;
}
case F_7 ( V_20 ) : {
const struct V_21 * V_4 ;
struct V_21 V_17 ;
V_22:
V_4 = F_8 ( V_9 , V_11 , sizeof( V_17 ) , & V_17 ) ;
if ( ! V_4 )
return false ;
V_12 = V_4 -> V_23 ;
V_2 -> V_6 = ( V_24 V_25 ) F_10 ( & V_4 -> V_7 ) ;
V_2 -> V_5 = ( V_24 V_25 ) F_10 ( & V_4 -> V_26 ) ;
V_11 += sizeof( struct V_21 ) ;
break;
}
case F_7 ( V_27 ) : {
const struct V_28 * V_29 ;
struct V_28 V_30 ;
V_29 = F_8 ( V_9 , V_11 , sizeof( V_30 ) , & V_30 ) ;
if ( ! V_29 )
return false ;
V_13 = V_29 -> V_31 ;
V_11 += sizeof( * V_29 ) ;
goto V_15;
}
case F_7 ( V_32 ) : {
struct {
struct V_33 V_34 ;
T_2 V_13 ;
} * V_34 , V_35 ;
V_34 = F_8 ( V_9 , V_11 , sizeof( V_35 ) , & V_35 ) ;
if ( ! V_34 )
return false ;
V_13 = V_34 -> V_13 ;
V_11 += V_36 ;
switch ( V_13 ) {
case F_7 ( V_37 ) :
goto V_18;
case F_7 ( V_38 ) :
goto V_22;
default:
return false ;
}
}
default:
return false ;
}
switch ( V_12 ) {
case V_39 : {
struct V_40 {
T_2 V_41 ;
T_2 V_13 ;
} * V_34 , V_35 ;
V_34 = F_8 ( V_9 , V_11 , sizeof( V_35 ) , & V_35 ) ;
if ( ! V_34 )
return false ;
if ( ! ( V_34 -> V_41 & ( V_42 | V_43 ) ) ) {
V_13 = V_34 -> V_13 ;
V_11 += 4 ;
if ( V_34 -> V_41 & V_44 )
V_11 += 4 ;
if ( V_34 -> V_41 & V_45 )
V_11 += 4 ;
if ( V_34 -> V_41 & V_46 )
V_11 += 4 ;
goto V_15;
}
break;
}
case V_47 :
goto V_15;
default:
break;
}
V_2 -> V_12 = V_12 ;
V_10 = F_11 ( V_12 ) ;
if ( V_10 >= 0 ) {
V_25 * V_48 , V_49 ;
V_11 += V_10 ;
V_48 = F_8 ( V_9 , V_11 , sizeof( V_49 ) , & V_49 ) ;
if ( V_48 )
V_2 -> V_48 = * V_48 ;
}
return true ;
}
