int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return 0 ;
}
long F_2 ( struct V_1 * V_2 , unsigned int V_4 , unsigned long V_5 )
{
struct V_6 V_7 ;
struct V_8 V_9 ;
struct V_10 * V_11 = NULL ;
struct V_12 * V_13 = F_3 ( V_2 , struct V_12 , clock ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_17 * V_18 ;
struct V_19 V_20 ;
int V_21 , V_22 = 0 ;
unsigned int V_23 ;
switch ( V_4 ) {
case V_24 :
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_25 = V_13 -> V_16 -> V_25 ;
V_7 . V_26 = V_13 -> V_16 -> V_26 ;
V_7 . V_27 = V_13 -> V_16 -> V_27 ;
V_7 . V_28 = V_13 -> V_16 -> V_28 ;
V_7 . V_29 = V_13 -> V_16 -> V_29 ;
if ( F_4 ( ( void V_30 * ) V_5 , & V_7 , sizeof( V_7 ) ) )
V_22 = - V_31 ;
break;
case V_32 :
if ( F_5 ( & V_9 . V_33 , ( void V_30 * ) V_5 ,
sizeof( V_9 . V_33 ) ) ) {
V_22 = - V_31 ;
break;
}
if ( V_9 . V_33 . V_34 >= V_15 -> V_27 ) {
V_22 = - V_35 ;
break;
}
V_9 . type = V_36 ;
V_21 = V_9 . V_33 . V_37 & V_38 ? 1 : 0 ;
V_22 = V_15 -> V_21 ( V_15 , & V_9 , V_21 ) ;
break;
case V_39 :
if ( F_5 ( & V_9 . V_40 , ( void V_30 * ) V_5 ,
sizeof( V_9 . V_40 ) ) ) {
V_22 = - V_31 ;
break;
}
if ( V_9 . V_40 . V_34 >= V_15 -> V_28 ) {
V_22 = - V_35 ;
break;
}
V_9 . type = V_41 ;
V_21 = V_9 . V_40 . V_42 . V_43 || V_9 . V_40 . V_42 . V_44 ;
V_22 = V_15 -> V_21 ( V_15 , & V_9 , V_21 ) ;
break;
case V_45 :
if ( ! F_6 ( V_46 ) )
return - V_47 ;
V_9 . type = V_48 ;
V_21 = V_5 ? 1 : 0 ;
V_22 = V_15 -> V_21 ( V_15 , & V_9 , V_21 ) ;
break;
case V_49 :
V_11 = F_7 ( sizeof( * V_11 ) , V_50 ) ;
if ( ! V_11 ) {
V_22 = - V_51 ;
break;
}
if ( F_5 ( V_11 , ( void V_30 * ) V_5 ,
sizeof( * V_11 ) ) ) {
V_22 = - V_31 ;
break;
}
if ( V_11 -> V_52 > V_53 ) {
V_22 = - V_35 ;
break;
}
V_18 = & V_11 -> V_20 [ 0 ] ;
for ( V_23 = 0 ; V_23 < V_11 -> V_52 ; V_23 ++ ) {
F_8 ( & V_20 ) ;
V_18 -> V_43 = V_20 . V_54 ;
V_18 -> V_44 = V_20 . V_55 ;
V_18 ++ ;
V_13 -> V_16 -> V_56 ( V_13 -> V_16 , & V_20 ) ;
V_18 -> V_43 = V_20 . V_54 ;
V_18 -> V_44 = V_20 . V_55 ;
V_18 ++ ;
}
F_8 ( & V_20 ) ;
V_18 -> V_43 = V_20 . V_54 ;
V_18 -> V_44 = V_20 . V_55 ;
if ( F_4 ( ( void V_30 * ) V_5 , V_11 , sizeof( * V_11 ) ) )
V_22 = - V_31 ;
break;
default:
V_22 = - V_57 ;
break;
}
F_9 ( V_11 ) ;
return V_22 ;
}
unsigned int F_10 ( struct V_1 * V_2 , struct V_58 * V_59 , T_2 * V_60 )
{
struct V_12 * V_13 = F_3 ( V_2 , struct V_12 , clock ) ;
F_11 ( V_59 , & V_13 -> V_61 , V_60 ) ;
return F_12 ( & V_13 -> V_62 ) ? V_63 : 0 ;
}
T_3 F_13 ( struct V_1 * V_2 ,
T_4 V_64 , char V_30 * V_65 , T_5 V_66 )
{
struct V_12 * V_13 = F_3 ( V_2 , struct V_12 , clock ) ;
struct V_67 * V_68 = & V_13 -> V_62 ;
struct V_69 * V_70 ;
unsigned long V_37 ;
T_5 V_71 , V_23 ;
int V_72 ;
if ( V_66 % sizeof( struct V_69 ) != 0 )
return - V_35 ;
if ( V_66 > V_73 )
V_66 = V_73 ;
V_66 = V_66 / sizeof( struct V_69 ) ;
if ( F_14 ( & V_13 -> V_74 ) )
return - V_75 ;
if ( F_15 ( V_13 -> V_61 ,
V_13 -> V_76 || F_12 ( V_68 ) ) ) {
F_16 ( & V_13 -> V_74 ) ;
return - V_75 ;
}
if ( V_13 -> V_76 ) {
F_16 ( & V_13 -> V_74 ) ;
return - V_77 ;
}
V_70 = F_7 ( V_73 , V_50 ) ;
if ( ! V_70 ) {
F_16 ( & V_13 -> V_74 ) ;
return - V_51 ;
}
F_17 ( & V_68 -> V_78 , V_37 ) ;
V_71 = F_12 ( V_68 ) ;
if ( V_66 > V_71 )
V_66 = V_71 ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
V_70 [ V_23 ] = V_68 -> V_65 [ V_68 -> V_79 ] ;
V_68 -> V_79 = ( V_68 -> V_79 + 1 ) % V_80 ;
}
F_18 ( & V_68 -> V_78 , V_37 ) ;
V_66 = V_66 * sizeof( struct V_69 ) ;
F_16 ( & V_13 -> V_74 ) ;
V_72 = V_66 ;
if ( F_4 ( V_65 , V_70 , V_66 ) )
V_72 = - V_31 ;
F_9 ( V_70 ) ;
return V_72 ;
}
