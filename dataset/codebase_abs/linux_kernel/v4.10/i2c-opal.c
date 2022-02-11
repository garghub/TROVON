static int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return - V_3 ;
case V_4 :
return - V_5 ;
case V_6 :
return - V_7 ;
case V_8 :
return - V_9 ;
case V_10 :
return - V_11 ;
case V_12 :
return - V_13 ;
default:
return - V_14 ;
}
}
static int F_2 ( T_1 V_15 , struct V_16 * V_17 )
{
struct V_18 V_19 ;
int V_20 , V_1 ;
V_20 = F_3 () ;
if ( V_20 < 0 ) {
if ( V_20 != - V_21 )
F_4 ( L_1 ) ;
return V_20 ;
}
V_1 = V_16 ( V_20 , V_15 , V_17 ) ;
if ( V_1 != V_22 ) {
V_1 = F_1 ( V_1 ) ;
goto exit;
}
V_1 = F_5 ( V_20 , & V_19 ) ;
if ( V_1 )
goto exit;
V_1 = F_6 ( V_19 ) ;
if ( V_1 != V_23 ) {
V_1 = F_1 ( V_1 ) ;
goto exit;
}
exit:
F_7 ( V_20 ) ;
return V_1 ;
}
static int F_8 ( struct V_24 * V_25 , struct V_26 * V_27 ,
int V_28 )
{
unsigned long V_29 = ( unsigned long ) V_25 -> V_30 ;
struct V_16 V_17 ;
int V_1 , V_31 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
switch( V_28 ) {
case 0 :
return 0 ;
case 1 :
V_17 . type = ( V_27 [ 0 ] . V_32 & V_33 ) ?
V_34 : V_35 ;
V_17 . V_36 = F_9 ( V_27 [ 0 ] . V_36 ) ;
V_17 . V_37 = F_10 ( V_27 [ 0 ] . V_38 ) ;
V_17 . V_39 = F_11 ( F_12 ( V_27 [ 0 ] . V_40 ) ) ;
break;
case 2 :
V_17 . type = ( V_27 [ 1 ] . V_32 & V_33 ) ?
V_41 : V_42 ;
V_17 . V_36 = F_9 ( V_27 [ 0 ] . V_36 ) ;
V_17 . V_43 = V_27 [ 0 ] . V_38 ;
for ( V_31 = 0 ; V_31 < V_27 [ 0 ] . V_38 ; V_31 ++ )
V_17 . V_44 = ( V_17 . V_44 << 8 ) | V_27 [ 0 ] . V_40 [ V_31 ] ;
V_17 . V_44 = F_10 ( V_17 . V_44 ) ;
V_17 . V_37 = F_10 ( V_27 [ 1 ] . V_38 ) ;
V_17 . V_39 = F_11 ( F_12 ( V_27 [ 1 ] . V_40 ) ) ;
break;
default:
return - V_45 ;
}
V_1 = F_2 ( V_29 , & V_17 ) ;
if ( V_1 )
return V_1 ;
return V_28 ;
}
static int F_13 ( struct V_24 * V_25 , T_2 V_36 ,
unsigned short V_32 , char V_46 ,
T_3 V_47 , int V_37 , union V_48 * V_49 )
{
unsigned long V_29 = ( unsigned long ) V_25 -> V_30 ;
struct V_16 V_17 ;
T_3 V_50 [ 2 ] ;
int V_1 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_36 = F_9 ( V_36 ) ;
switch ( V_37 ) {
case V_51 :
V_17 . V_39 = F_11 ( F_12 ( & V_49 -> V_52 ) ) ;
V_17 . V_37 = F_10 ( 1 ) ;
case V_53 :
V_17 . type = ( V_46 == V_54 ) ?
V_34 : V_35 ;
break;
case V_55 :
V_17 . V_39 = F_11 ( F_12 ( & V_49 -> V_52 ) ) ;
V_17 . V_37 = F_10 ( 1 ) ;
V_17 . V_44 = F_10 ( V_47 ) ;
V_17 . V_43 = 1 ;
V_17 . type = ( V_46 == V_54 ) ?
V_41 : V_42 ;
break;
case V_56 :
if ( ! V_46 ) {
V_50 [ 0 ] = V_49 -> V_57 & 0xff ;
V_50 [ 1 ] = ( V_49 -> V_57 >> 8 ) & 0xff ;
}
V_17 . V_39 = F_11 ( F_12 ( V_50 ) ) ;
V_17 . V_37 = F_10 ( 2 ) ;
V_17 . V_44 = F_10 ( V_47 ) ;
V_17 . V_43 = 1 ;
V_17 . type = ( V_46 == V_54 ) ?
V_41 : V_42 ;
break;
case V_58 :
V_17 . V_39 = F_11 ( F_12 ( & V_49 -> V_59 [ 1 ] ) ) ;
V_17 . V_37 = F_10 ( V_49 -> V_59 [ 0 ] ) ;
V_17 . V_44 = F_10 ( V_47 ) ;
V_17 . V_43 = 1 ;
V_17 . type = ( V_46 == V_54 ) ?
V_41 : V_42 ;
break;
default:
return - V_5 ;
}
V_1 = F_2 ( V_29 , & V_17 ) ;
if ( ! V_1 && V_46 && V_37 == V_56 ) {
V_49 -> V_57 = ( ( T_2 ) V_50 [ 1 ] ) << 8 ;
V_49 -> V_57 |= V_50 [ 0 ] ;
}
return V_1 ;
}
static T_1 F_14 ( struct V_24 * V_60 )
{
return V_61 | V_62 | V_63 |
V_64 | V_65 |
V_66 ;
}
static int F_15 ( struct V_67 * V_68 )
{
struct V_24 * V_60 ;
const char * V_69 ;
T_1 V_29 ;
int V_1 ;
if ( ! V_68 -> V_70 . V_71 )
return - V_72 ;
V_1 = F_16 ( V_68 -> V_70 . V_71 , L_2 , & V_29 ) ;
if ( V_1 ) {
F_17 ( & V_68 -> V_70 , L_3 ) ;
return - V_14 ;
}
V_60 = F_18 ( & V_68 -> V_70 , sizeof( * V_60 ) , V_73 ) ;
if ( ! V_60 )
return - V_3 ;
V_60 -> V_74 = & V_75 ;
V_60 -> V_30 = ( void * ) ( unsigned long ) V_29 ;
V_60 -> V_76 = & V_77 ;
V_60 -> V_70 . V_78 = & V_68 -> V_70 ;
V_60 -> V_70 . V_71 = F_19 ( V_68 -> V_70 . V_71 ) ;
V_69 = F_20 ( V_68 -> V_70 . V_71 , L_4 , NULL ) ;
if ( V_69 )
F_21 ( V_60 -> V_79 , V_69 , sizeof( V_60 -> V_79 ) ) ;
else
F_21 ( V_60 -> V_79 , L_5 , sizeof( V_60 -> V_79 ) ) ;
F_22 ( V_68 , V_60 ) ;
V_1 = F_23 ( V_60 ) ;
if ( V_1 )
F_17 ( & V_68 -> V_70 , L_6 ) ;
return V_1 ;
}
static int F_24 ( struct V_67 * V_68 )
{
struct V_24 * V_60 = F_25 ( V_68 ) ;
F_26 ( V_60 ) ;
return 0 ;
}
static int T_4 F_27 ( void )
{
if ( ! F_28 ( V_80 ) )
return - V_72 ;
return F_29 ( & V_81 ) ;
}
static void T_5 F_30 ( void )
{
return F_31 ( & V_81 ) ;
}
