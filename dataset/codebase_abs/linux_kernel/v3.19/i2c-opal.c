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
V_1 = F_6 ( V_19 . V_23 [ 1 ] ) ;
if ( V_1 != V_24 ) {
V_1 = F_1 ( V_1 ) ;
goto exit;
}
exit:
F_7 ( V_20 ) ;
return V_1 ;
}
static int F_8 ( struct V_25 * V_26 , struct V_27 * V_28 ,
int V_29 )
{
unsigned long V_30 = ( unsigned long ) V_26 -> V_31 ;
struct V_16 V_17 ;
int V_1 , V_32 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
switch( V_29 ) {
case 0 :
return 0 ;
case 1 :
V_17 . type = ( V_28 [ 0 ] . V_33 & V_34 ) ?
V_35 : V_36 ;
V_17 . V_37 = F_9 ( V_28 [ 0 ] . V_37 ) ;
V_17 . V_38 = F_10 ( V_28 [ 0 ] . V_39 ) ;
V_17 . V_40 = F_11 ( F_12 ( V_28 [ 0 ] . V_41 ) ) ;
break;
case 2 :
if ( ( V_28 [ 0 ] . V_33 & V_34 ) || ! ( V_28 [ 1 ] . V_33 & V_34 ) )
return - V_42 ;
if ( V_28 [ 0 ] . V_39 > 4 )
return - V_42 ;
if ( V_28 [ 0 ] . V_37 != V_28 [ 1 ] . V_37 )
return - V_42 ;
V_17 . type = V_43 ;
V_17 . V_37 = F_9 ( V_28 [ 0 ] . V_37 ) ;
V_17 . V_44 = V_28 [ 0 ] . V_39 ;
for ( V_32 = 0 ; V_32 < V_28 [ 0 ] . V_39 ; V_32 ++ )
V_17 . V_45 = ( V_17 . V_45 << 8 ) | V_28 [ 0 ] . V_41 [ V_32 ] ;
V_17 . V_45 = F_10 ( V_17 . V_45 ) ;
V_17 . V_38 = F_10 ( V_28 [ 1 ] . V_39 ) ;
V_17 . V_40 = F_11 ( F_12 ( V_28 [ 1 ] . V_41 ) ) ;
break;
default:
return - V_42 ;
}
V_1 = F_2 ( V_30 , & V_17 ) ;
if ( V_1 )
return V_1 ;
return V_29 ;
}
static int F_13 ( struct V_25 * V_26 , T_2 V_37 ,
unsigned short V_33 , char V_46 ,
T_3 V_47 , int V_38 , union V_48 * V_49 )
{
unsigned long V_30 = ( unsigned long ) V_26 -> V_31 ;
struct V_16 V_17 ;
T_3 V_50 [ 2 ] ;
int V_1 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_37 = F_9 ( V_37 ) ;
switch ( V_38 ) {
case V_51 :
V_17 . V_40 = F_11 ( F_12 ( & V_49 -> V_52 ) ) ;
V_17 . V_38 = F_10 ( 1 ) ;
case V_53 :
V_17 . type = ( V_46 == V_54 ) ?
V_35 : V_36 ;
break;
case V_55 :
V_17 . V_40 = F_11 ( F_12 ( & V_49 -> V_52 ) ) ;
V_17 . V_38 = F_10 ( 1 ) ;
V_17 . V_45 = F_10 ( V_47 ) ;
V_17 . V_44 = 1 ;
V_17 . type = ( V_46 == V_54 ) ?
V_43 : V_56 ;
break;
case V_57 :
if ( ! V_46 ) {
V_50 [ 0 ] = V_49 -> V_58 & 0xff ;
V_50 [ 1 ] = ( V_49 -> V_58 >> 8 ) & 0xff ;
}
V_17 . V_40 = F_11 ( F_12 ( V_50 ) ) ;
V_17 . V_38 = F_10 ( 2 ) ;
V_17 . V_45 = F_10 ( V_47 ) ;
V_17 . V_44 = 1 ;
V_17 . type = ( V_46 == V_54 ) ?
V_43 : V_56 ;
break;
case V_59 :
V_17 . V_40 = F_11 ( F_12 ( & V_49 -> V_60 [ 1 ] ) ) ;
V_17 . V_38 = F_10 ( V_49 -> V_60 [ 0 ] ) ;
V_17 . V_45 = F_10 ( V_47 ) ;
V_17 . V_44 = 1 ;
V_17 . type = ( V_46 == V_54 ) ?
V_43 : V_56 ;
break;
default:
return - V_5 ;
}
V_1 = F_2 ( V_30 , & V_17 ) ;
if ( ! V_1 && V_46 && V_38 == V_57 ) {
V_49 -> V_58 = ( ( T_2 ) V_50 [ 1 ] ) << 8 ;
V_49 -> V_58 |= V_50 [ 0 ] ;
}
return V_1 ;
}
static T_1 F_14 ( struct V_25 * V_61 )
{
return V_62 | V_63 | V_64 |
V_65 | V_66 |
V_67 ;
}
static int F_15 ( struct V_68 * V_69 )
{
struct V_25 * V_61 ;
const char * V_70 ;
T_1 V_30 ;
int V_1 ;
if ( ! V_69 -> V_71 . V_72 )
return - V_73 ;
V_1 = F_16 ( V_69 -> V_71 . V_72 , L_2 , & V_30 ) ;
if ( V_1 ) {
F_17 ( & V_69 -> V_71 , L_3 ) ;
return - V_14 ;
}
V_61 = F_18 ( & V_69 -> V_71 , sizeof( * V_61 ) , V_74 ) ;
if ( ! V_61 )
return - V_3 ;
V_61 -> V_75 = & V_76 ;
V_61 -> V_31 = ( void * ) ( unsigned long ) V_30 ;
V_61 -> V_71 . V_77 = & V_69 -> V_71 ;
V_61 -> V_71 . V_72 = F_19 ( V_69 -> V_71 . V_72 ) ;
V_70 = F_20 ( V_69 -> V_71 . V_72 , L_4 , NULL ) ;
if ( V_70 )
F_21 ( V_61 -> V_78 , V_70 , sizeof( V_61 -> V_78 ) ) ;
else
F_21 ( V_61 -> V_78 , L_5 , sizeof( V_61 -> V_78 ) ) ;
F_22 ( V_69 , V_61 ) ;
V_1 = F_23 ( V_61 ) ;
if ( V_1 )
F_17 ( & V_69 -> V_71 , L_6 ) ;
return V_1 ;
}
static int F_24 ( struct V_68 * V_69 )
{
struct V_25 * V_61 = F_25 ( V_69 ) ;
F_26 ( V_61 ) ;
return 0 ;
}
static int T_4 F_27 ( void )
{
if ( ! F_28 ( V_79 ) )
return - V_73 ;
return F_29 ( & V_80 ) ;
}
static void T_5 F_30 ( void )
{
return F_31 ( & V_80 ) ;
}
