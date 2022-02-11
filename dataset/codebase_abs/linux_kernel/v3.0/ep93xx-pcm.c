static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 ) ;
}
static void F_3 ( void * V_4 ,
struct V_5 * V_6 )
{
}
static void F_4 ( void * V_4 ,
struct V_5 * V_6 ,
int V_7 , int error )
{
struct V_2 * V_3 = V_4 ;
struct V_8 * V_9 = V_3 -> V_10 -> V_11 ;
if ( V_6 == V_9 -> V_6 + V_9 -> V_12 - 1 )
V_9 -> V_13 = 0 ;
else
V_9 -> V_13 += V_6 -> V_14 ;
if ( ! error ) {
F_5 ( & V_9 -> V_15 , V_6 ) ;
F_6 ( & V_9 -> V_16 ) ;
} else {
F_7 ( V_3 , V_17 ) ;
}
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_18 * V_19 = V_3 -> V_11 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 ;
struct V_8 * V_9 ;
int V_24 ;
V_23 = F_9 ( V_21 , V_3 ) ;
F_10 ( V_3 , & V_25 ) ;
V_9 = F_11 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
memset ( & V_9 -> V_16 , 0 , sizeof( V_9 -> V_16 ) ) ;
V_9 -> V_16 . V_28 = F_1 ;
V_9 -> V_16 . V_1 = ( unsigned long ) V_3 ;
V_9 -> V_15 . V_29 = V_23 -> V_29 ;
V_9 -> V_15 . V_30 = V_23 -> V_31 | V_32 |
( ( V_3 -> V_33 == V_34 ) ?
V_35 : V_36 ) ;
V_9 -> V_15 . V_4 = V_3 ;
V_9 -> V_15 . V_37 = F_3 ;
V_9 -> V_15 . V_38 = F_4 ;
V_24 = F_12 ( & V_9 -> V_15 ) ;
if ( V_24 < 0 ) {
F_13 ( V_9 ) ;
return V_24 ;
}
V_3 -> V_10 -> V_11 = V_9 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_10 -> V_11 ;
F_15 ( & V_9 -> V_15 ) ;
F_13 ( V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_39 * V_40 )
{
struct V_41 * V_10 = V_3 -> V_10 ;
struct V_8 * V_9 = V_10 -> V_11 ;
T_1 V_42 = F_17 ( V_40 ) ;
T_1 V_43 = F_18 ( V_40 ) ;
int V_44 ;
F_19 ( V_3 , & V_3 -> V_45 ) ;
V_10 -> V_46 = V_42 ;
V_9 -> V_12 = ( V_42 + V_43 - 1 ) / V_43 ;
for ( V_44 = 0 ; V_44 < V_9 -> V_12 ; V_44 ++ ) {
V_9 -> V_6 [ V_44 ] . V_47 = V_10 -> V_48 + ( V_44 * V_43 ) ;
V_9 -> V_6 [ V_44 ] . V_14 = V_43 ;
if ( ( V_44 + 1 ) * V_43 > V_42 )
V_9 -> V_6 [ V_44 ] . V_14 = V_42 - ( V_44 * V_43 ) ;
}
return 0 ;
}
static int F_20 ( struct V_2 * V_3 )
{
F_19 ( V_3 , NULL ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , int V_49 )
{
struct V_8 * V_9 = V_3 -> V_10 -> V_11 ;
int V_24 ;
int V_44 ;
V_24 = 0 ;
switch ( V_49 ) {
case V_50 :
case V_51 :
case V_52 :
V_9 -> V_13 = 0 ;
for ( V_44 = 0 ; V_44 < V_9 -> V_12 ; V_44 ++ )
F_22 ( & V_9 -> V_15 , V_9 -> V_6 + V_44 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
F_23 ( & V_9 -> V_15 ) ;
break;
default:
V_24 = - V_56 ;
break;
}
return V_24 ;
}
static T_2 F_24 ( struct V_2 * V_3 )
{
struct V_41 * V_10 = V_3 -> V_10 ;
struct V_8 * V_9 = V_3 -> V_10 -> V_11 ;
return F_25 ( V_10 , V_9 -> V_13 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_57 * V_58 )
{
struct V_41 * V_10 = V_3 -> V_10 ;
return F_27 ( V_3 -> V_59 -> V_60 -> V_61 , V_58 ,
V_10 -> V_62 ,
V_10 -> V_48 ,
V_10 -> V_46 ) ;
}
static int F_28 ( struct V_63 * V_59 , int V_33 )
{
struct V_2 * V_3 = V_59 -> V_64 [ V_33 ] . V_3 ;
struct V_65 * V_6 = & V_3 -> V_45 ;
T_1 V_14 = V_25 . V_66 ;
V_6 -> V_61 . type = V_67 ;
V_6 -> V_61 . V_61 = V_59 -> V_60 -> V_61 ;
V_6 -> V_11 = NULL ;
V_6 -> V_68 = F_29 ( V_59 -> V_60 -> V_61 , V_14 ,
& V_6 -> V_69 , V_26 ) ;
V_6 -> V_7 = V_14 ;
return ( V_6 -> V_68 == NULL ) ? - V_27 : 0 ;
}
static void F_30 ( struct V_63 * V_59 )
{
struct V_2 * V_3 ;
struct V_65 * V_6 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < 2 ; V_33 ++ ) {
V_3 = V_59 -> V_64 [ V_33 ] . V_3 ;
if ( ! V_3 )
continue;
V_6 = & V_3 -> V_45 ;
if ( ! V_6 -> V_68 )
continue;
F_31 ( V_59 -> V_60 -> V_61 , V_6 -> V_7 , V_6 -> V_68 ,
V_6 -> V_69 ) ;
V_6 -> V_68 = NULL ;
}
}
static int F_32 ( struct V_70 * V_60 , struct V_20 * V_71 ,
struct V_63 * V_59 )
{
int V_24 = 0 ;
if ( ! V_60 -> V_61 -> V_72 )
V_60 -> V_61 -> V_72 = & V_73 ;
if ( ! V_60 -> V_61 -> V_74 )
V_60 -> V_61 -> V_74 = 0xffffffff ;
if ( V_71 -> V_75 -> V_76 . V_77 ) {
V_24 = F_28 ( V_59 ,
V_34 ) ;
if ( V_24 )
return V_24 ;
}
if ( V_71 -> V_75 -> V_78 . V_77 ) {
V_24 = F_28 ( V_59 ,
V_79 ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int T_3 F_33 ( struct V_80 * V_81 )
{
return F_34 ( & V_81 -> V_61 , & V_82 ) ;
}
static int T_4 F_35 ( struct V_80 * V_81 )
{
F_36 ( & V_81 -> V_61 ) ;
return 0 ;
}
static int T_5 F_37 ( void )
{
return F_38 ( & V_83 ) ;
}
static void T_6 F_39 ( void )
{
F_40 ( & V_83 ) ;
}
