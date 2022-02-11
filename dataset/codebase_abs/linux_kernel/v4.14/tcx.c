static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 , * V_6 ;
if ( V_4 -> V_7 )
return;
V_5 = V_4 -> V_8 ;
if ( V_5 == NULL )
return;
for ( V_6 = V_5 + V_2 -> V_9 . V_10 ; V_5 < V_6 ; V_5 ++ ) {
T_1 V_11 = F_2 ( V_5 ) ;
V_11 &= 0xffffff ;
F_3 ( V_11 , V_5 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
unsigned long V_12 ;
F_5 ( & V_4 -> V_13 , V_12 ) ;
F_1 ( V_2 ) ;
F_6 ( & V_4 -> V_13 , V_12 ) ;
}
static int F_7 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
return 0 ;
}
static int F_8 ( unsigned V_16 ,
unsigned V_17 , unsigned V_18 , unsigned V_19 ,
unsigned V_20 , struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
struct V_21 T_2 * V_22 = V_4 -> V_22 ;
unsigned long V_12 ;
if ( V_16 >= 256 )
return 1 ;
V_17 >>= 8 ;
V_18 >>= 8 ;
V_19 >>= 8 ;
F_5 ( & V_4 -> V_13 , V_12 ) ;
F_3 ( V_16 << 24 , & V_22 -> V_23 ) ;
F_3 ( V_17 << 24 , & V_22 -> V_24 ) ;
F_3 ( V_18 << 24 , & V_22 -> V_24 ) ;
F_3 ( V_19 << 24 , & V_22 -> V_24 ) ;
F_6 ( & V_4 -> V_13 , V_12 ) ;
return 0 ;
}
static int
F_9 ( int V_25 , struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
struct V_26 T_2 * V_27 = V_4 -> V_27 ;
unsigned long V_12 ;
T_1 V_28 ;
F_5 ( & V_4 -> V_13 , V_12 ) ;
V_28 = F_2 ( & V_27 -> V_29 ) ;
switch ( V_25 ) {
case V_30 :
V_28 &= ~ ( V_31 |
V_32 ) ;
V_28 |= V_33 ;
V_4 -> V_12 &= ~ V_34 ;
break;
case V_35 :
V_28 &= ~ V_33 ;
V_4 -> V_12 |= V_34 ;
break;
case V_36 :
V_28 |= V_31 ;
break;
case V_37 :
V_28 |= V_32 ;
break;
case V_38 :
break;
}
F_3 ( V_28 , & V_27 -> V_29 ) ;
F_6 ( & V_4 -> V_13 , V_12 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
return F_11 ( V_4 -> V_41 ,
V_2 -> V_9 . V_42 , V_2 -> V_9 . V_10 ,
V_4 -> V_43 , V_40 ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_44 ,
unsigned long V_45 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
return F_13 ( V_44 , V_45 , V_2 ,
V_46 ,
( V_4 -> V_7 ? 8 : 24 ) ,
V_2 -> V_9 . V_10 ) ;
}
static void
F_14 ( struct V_1 * V_2 , int V_47 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
const char * V_48 ;
if ( V_4 -> V_7 )
V_48 = L_1 ;
else
V_48 = L_2 ;
F_15 ( V_2 -> V_9 . V_49 , V_48 , sizeof( V_2 -> V_9 . V_49 ) ) ;
V_2 -> V_9 . type = V_50 ;
V_2 -> V_9 . V_51 = V_52 ;
V_2 -> V_9 . V_53 = V_47 ;
V_2 -> V_9 . V_54 = V_55 ;
}
static void F_16 ( struct V_56 * V_57 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_58 )
F_17 ( & V_57 -> V_59 [ 7 ] ,
V_4 -> V_58 , sizeof( struct V_60 ) ) ;
if ( V_4 -> V_27 )
F_17 ( & V_57 -> V_59 [ 9 ] ,
V_4 -> V_27 , sizeof( struct V_26 ) ) ;
if ( V_4 -> V_22 )
F_17 ( & V_57 -> V_59 [ 8 ] ,
V_4 -> V_22 , sizeof( struct V_21 ) ) ;
if ( V_4 -> V_8 )
F_17 ( & V_57 -> V_59 [ 4 ] ,
V_4 -> V_8 , V_2 -> V_9 . V_10 * sizeof( T_1 ) ) ;
if ( V_2 -> V_61 )
F_17 ( & V_57 -> V_59 [ 0 ] ,
V_2 -> V_61 , V_2 -> V_9 . V_10 ) ;
}
static int F_18 ( struct V_56 * V_57 )
{
struct V_62 * V_63 = V_57 -> V_64 . V_65 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_47 , V_66 , V_67 ;
V_2 = F_19 ( sizeof( struct V_3 ) , & V_57 -> V_64 ) ;
V_67 = - V_68 ;
if ( ! V_2 )
goto V_69;
V_4 = V_2 -> V_4 ;
F_20 ( & V_4 -> V_13 ) ;
V_4 -> V_7 =
( F_21 ( V_63 , L_3 , NULL ) != NULL ) ;
F_22 ( & V_2 -> V_15 , V_63 , 8 ) ;
V_2 -> V_15 . V_17 . V_70 = 8 ;
V_2 -> V_15 . V_18 . V_70 = 8 ;
V_2 -> V_15 . V_19 . V_70 = 8 ;
V_47 = F_23 ( V_63 , L_4 ,
V_2 -> V_15 . V_71 ) ;
V_2 -> V_9 . V_10 = F_24 ( V_47 * V_2 -> V_15 . V_72 ) ;
V_4 -> V_58 = F_25 ( & V_57 -> V_59 [ 7 ] , 0 ,
sizeof( struct V_60 ) , L_5 ) ;
V_4 -> V_27 = F_25 ( & V_57 -> V_59 [ 9 ] , 0 ,
sizeof( struct V_26 ) , L_6 ) ;
V_4 -> V_22 = F_25 ( & V_57 -> V_59 [ 8 ] , 0 ,
sizeof( struct V_21 ) , L_7 ) ;
V_2 -> V_61 = F_25 ( & V_57 -> V_59 [ 0 ] , 0 ,
V_2 -> V_9 . V_10 , L_8 ) ;
if ( ! V_4 -> V_58 || ! V_4 -> V_27 ||
! V_4 -> V_22 || ! V_2 -> V_61 )
goto V_73;
memcpy ( & V_4 -> V_41 , & V_74 , sizeof( V_4 -> V_41 ) ) ;
if ( ! V_4 -> V_7 ) {
V_4 -> V_8 = F_25 ( & V_57 -> V_59 [ 4 ] , 0 ,
V_2 -> V_9 . V_10 * sizeof( T_1 ) ,
L_9 ) ;
if ( ! V_4 -> V_8 )
goto V_73;
} else {
V_4 -> V_41 [ 1 ] . V_75 = V_76 ;
V_4 -> V_41 [ 4 ] . V_75 = V_76 ;
V_4 -> V_41 [ 5 ] . V_75 = V_76 ;
V_4 -> V_41 [ 6 ] . V_75 = V_76 ;
}
V_2 -> V_9 . V_42 = V_57 -> V_59 [ 0 ] . V_77 ;
V_4 -> V_43 = V_57 -> V_59 [ 0 ] . V_12 & V_78 ;
for ( V_66 = 0 ; V_66 < V_79 ; V_66 ++ ) {
int V_80 ;
switch ( V_66 ) {
case 10 :
V_80 = 12 ;
break;
case 11 : case 12 :
V_80 = V_66 - 1 ;
break;
default:
V_80 = V_66 ;
break;
}
V_4 -> V_41 [ V_66 ] . V_81 = V_57 -> V_59 [ V_80 ] . V_77 ;
}
V_2 -> V_12 = V_82 ;
V_2 -> V_83 = & V_84 ;
F_3 ( 0x04 << 24 , & V_4 -> V_22 -> V_23 ) ;
F_3 ( 0xff << 24 , & V_4 -> V_22 -> V_85 ) ;
F_3 ( 0x05 << 24 , & V_4 -> V_22 -> V_23 ) ;
F_3 ( 0x00 << 24 , & V_4 -> V_22 -> V_85 ) ;
F_3 ( 0x06 << 24 , & V_4 -> V_22 -> V_23 ) ;
F_3 ( 0x73 << 24 , & V_4 -> V_22 -> V_85 ) ;
F_3 ( 0x07 << 24 , & V_4 -> V_22 -> V_23 ) ;
F_3 ( 0x00 << 24 , & V_4 -> V_22 -> V_85 ) ;
F_4 ( V_2 ) ;
F_9 ( V_30 , V_2 ) ;
if ( F_26 ( & V_2 -> V_86 , 256 , 0 ) )
goto V_73;
F_27 ( & V_2 -> V_86 , V_2 ) ;
F_14 ( V_2 , V_47 ) ;
V_67 = F_28 ( V_2 ) ;
if ( V_67 < 0 )
goto V_87;
F_29 ( & V_57 -> V_64 , V_2 ) ;
F_30 ( V_88 L_10 ,
V_63 ,
V_4 -> V_43 ,
V_2 -> V_9 . V_42 ,
V_4 -> V_7 ? L_11 : L_12 ) ;
return 0 ;
V_87:
F_31 ( & V_2 -> V_86 ) ;
V_73:
F_16 ( V_57 , V_2 , V_4 ) ;
F_32 ( V_2 ) ;
V_69:
return V_67 ;
}
static int F_33 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_34 ( & V_57 -> V_64 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_35 ( V_2 ) ;
F_31 ( & V_2 -> V_86 ) ;
F_16 ( V_57 , V_2 , V_4 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static int T_3 F_36 ( void )
{
if ( F_37 ( L_13 , NULL ) )
return - V_89 ;
return F_38 ( & V_90 ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_90 ) ;
}
