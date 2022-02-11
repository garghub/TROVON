int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return 0 ;
}
long F_2 ( struct V_1 * V_2 , unsigned int V_4 , unsigned long V_5 )
{
struct V_6 V_7 ;
struct V_8 V_9 ;
struct V_10 * V_11 = F_3 ( V_2 , struct V_10 , clock ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_15 , V_16 = 0 ;
switch ( V_4 ) {
case V_17 :
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_18 = V_11 -> V_14 -> V_18 ;
V_7 . V_19 = V_11 -> V_14 -> V_19 ;
V_7 . V_20 = V_11 -> V_14 -> V_20 ;
V_7 . V_21 = V_11 -> V_14 -> V_21 ;
V_7 . V_22 = V_11 -> V_14 -> V_22 ;
if ( F_4 ( ( void V_23 * ) V_5 , & V_7 , sizeof( V_7 ) ) )
V_16 = - V_24 ;
break;
case V_25 :
if ( F_5 ( & V_9 . V_26 , ( void V_23 * ) V_5 ,
sizeof( V_9 . V_26 ) ) ) {
V_16 = - V_24 ;
break;
}
if ( V_9 . V_26 . V_27 >= V_13 -> V_20 ) {
V_16 = - V_28 ;
break;
}
V_9 . type = V_29 ;
V_15 = V_9 . V_26 . V_30 & V_31 ? 1 : 0 ;
V_16 = V_13 -> V_15 ( V_13 , & V_9 , V_15 ) ;
break;
case V_32 :
if ( F_5 ( & V_9 . V_33 , ( void V_23 * ) V_5 ,
sizeof( V_9 . V_33 ) ) ) {
V_16 = - V_24 ;
break;
}
if ( V_9 . V_33 . V_27 >= V_13 -> V_21 ) {
V_16 = - V_28 ;
break;
}
V_9 . type = V_34 ;
V_15 = V_9 . V_33 . V_35 . V_36 || V_9 . V_33 . V_35 . V_37 ;
V_16 = V_13 -> V_15 ( V_13 , & V_9 , V_15 ) ;
break;
case V_38 :
if ( ! F_6 ( V_39 ) )
return - V_40 ;
V_9 . type = V_41 ;
V_15 = V_5 ? 1 : 0 ;
V_16 = V_13 -> V_15 ( V_13 , & V_9 , V_15 ) ;
break;
default:
V_16 = - V_42 ;
break;
}
return V_16 ;
}
unsigned int F_7 ( struct V_1 * V_2 , struct V_43 * V_44 , T_2 * V_45 )
{
struct V_10 * V_11 = F_3 ( V_2 , struct V_10 , clock ) ;
F_8 ( V_44 , & V_11 -> V_46 , V_45 ) ;
return F_9 ( & V_11 -> V_47 ) ? V_48 : 0 ;
}
T_3 F_10 ( struct V_1 * V_2 ,
T_4 V_49 , char V_23 * V_50 , T_5 V_51 )
{
struct V_10 * V_11 = F_3 ( V_2 , struct V_10 , clock ) ;
struct V_52 * V_53 = & V_11 -> V_47 ;
struct V_54 V_55 [ V_56 ] ;
unsigned long V_30 ;
T_5 V_57 , V_58 ;
if ( V_51 % sizeof( struct V_54 ) != 0 )
return - V_28 ;
if ( V_51 > sizeof( V_55 ) )
V_51 = sizeof( V_55 ) ;
V_51 = V_51 / sizeof( struct V_54 ) ;
if ( F_11 ( & V_11 -> V_59 ) )
return - V_60 ;
if ( F_12 ( V_11 -> V_46 ,
V_11 -> V_61 || F_9 ( V_53 ) ) ) {
F_13 ( & V_11 -> V_59 ) ;
return - V_60 ;
}
if ( V_11 -> V_61 ) {
F_13 ( & V_11 -> V_59 ) ;
return - V_62 ;
}
F_14 ( & V_53 -> V_63 , V_30 ) ;
V_57 = F_9 ( V_53 ) ;
if ( V_51 > V_57 )
V_51 = V_57 ;
for ( V_58 = 0 ; V_58 < V_51 ; V_58 ++ ) {
V_55 [ V_58 ] = V_53 -> V_50 [ V_53 -> V_64 ] ;
V_53 -> V_64 = ( V_53 -> V_64 + 1 ) % V_65 ;
}
F_15 ( & V_53 -> V_63 , V_30 ) ;
V_51 = V_51 * sizeof( struct V_54 ) ;
F_13 ( & V_11 -> V_59 ) ;
if ( F_4 ( V_50 , V_55 , V_51 ) )
return - V_24 ;
return V_51 ;
}
