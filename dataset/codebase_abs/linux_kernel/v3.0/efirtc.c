static inline int
F_1 ( T_1 * V_1 )
{
return V_2 [ F_2 ( V_1 -> V_3 ) ] [ V_1 -> V_4 - 1 ] + V_1 -> V_5 - 1 ;
}
static int
F_3 ( T_1 * V_1 )
{
int V_6 ;
int V_7 = 0 ;
if ( V_1 -> V_3 < 1998 ) {
F_4 ( V_8 L_1 ) ;
return - 1 ;
}
for( V_6 = V_9 ; V_6 < V_1 -> V_3 ; V_6 ++ ) {
V_7 += 365 + ( F_2 ( V_6 ) ? 1 : 0 ) ;
}
V_7 += F_1 ( V_1 ) ;
return ( V_7 + 4 ) % 7 ;
}
static void
F_5 ( struct V_10 * V_11 , T_1 * V_1 )
{
V_1 -> V_3 = V_11 -> V_12 + 1900 ;
V_1 -> V_4 = V_11 -> V_13 + 1 ;
V_1 -> V_5 = V_11 -> V_14 ;
V_1 -> V_15 = V_11 -> V_16 ;
V_1 -> V_17 = V_11 -> V_18 ;
V_1 -> V_19 = V_11 -> V_20 ;
V_1 -> V_21 = 0 ;
V_1 -> V_22 = V_11 -> V_23 ? V_24 : 0 ;
V_1 -> V_25 = V_26 ;
}
static void
F_6 ( T_1 * V_1 , struct V_10 * V_11 )
{
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_20 = V_1 -> V_19 ;
V_11 -> V_18 = V_1 -> V_17 ;
V_11 -> V_16 = V_1 -> V_15 ;
V_11 -> V_14 = V_1 -> V_5 ;
V_11 -> V_13 = V_1 -> V_4 - 1 ;
V_11 -> V_12 = V_1 -> V_3 - 1900 ;
V_11 -> V_27 = F_3 ( V_1 ) ;
V_11 -> V_28 = F_1 ( V_1 ) ;
switch ( V_1 -> V_22 & V_24 ) {
case V_24 :
V_11 -> V_23 = 1 ;
break;
case V_29 :
V_11 -> V_23 = 0 ;
break;
default:
V_11 -> V_23 = - 1 ;
}
}
static long F_7 ( struct V_30 * V_30 , unsigned int V_31 ,
unsigned long V_32 )
{
T_2 V_33 ;
unsigned long V_34 ;
T_1 V_1 ;
T_3 V_35 ;
struct V_10 V_11 ;
struct V_36 T_4 * V_37 ;
unsigned char V_38 , V_39 ;
switch ( V_31 ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
return - V_52 ;
case V_53 :
F_8 ( & V_54 , V_34 ) ;
V_33 = V_55 . V_56 ( & V_1 , & V_35 ) ;
F_9 ( & V_54 , V_34 ) ;
if ( V_33 != V_57 ) {
F_4 ( V_8 L_2 ) ;
return - V_52 ;
}
F_6 ( & V_1 , & V_11 ) ;
return F_10 ( ( void T_4 * ) V_32 , & V_11 ,
sizeof ( struct V_10 ) ) ? - V_58 : 0 ;
case V_59 :
if ( ! F_11 ( V_60 ) ) return - V_61 ;
if ( F_12 ( & V_11 , (struct V_10 T_4 * ) V_32 ,
sizeof( struct V_10 ) ) )
return - V_58 ;
F_5 ( & V_11 , & V_1 ) ;
F_8 ( & V_54 , V_34 ) ;
V_33 = V_55 . V_62 ( & V_1 ) ;
F_9 ( & V_54 , V_34 ) ;
return V_33 == V_57 ? 0 : - V_52 ;
case V_63 :
if ( ! F_11 ( V_60 ) ) return - V_61 ;
V_37 = (struct V_36 T_4 * ) V_32 ;
if ( F_13 ( V_38 , & V_37 -> V_38 )
|| F_12 ( & V_11 , & V_37 -> time , sizeof( struct V_10 ) ) )
return - V_58 ;
F_5 ( & V_11 , & V_1 ) ;
F_8 ( & V_54 , V_34 ) ;
V_33 = V_55 . V_64 ( ( V_65 ) V_38 , & V_1 ) ;
F_9 ( & V_54 , V_34 ) ;
return V_33 == V_57 ? 0 : - V_52 ;
case V_66 :
F_8 ( & V_54 , V_34 ) ;
V_33 = V_55 . V_67 ( ( V_65 * ) & V_38 , ( V_65 * ) & V_39 , & V_1 ) ;
F_9 ( & V_54 , V_34 ) ;
if ( V_33 != V_57 ) return - V_52 ;
V_37 = (struct V_36 T_4 * ) V_32 ;
if ( F_14 ( V_38 , & V_37 -> V_38 )
|| F_14 ( V_39 , & V_37 -> V_39 ) ) return - V_58 ;
F_6 ( & V_1 , & V_11 ) ;
return F_10 ( & V_37 -> time , & V_11 ,
sizeof( struct V_10 ) ) ? - V_58 : 0 ;
}
return - V_68 ;
}
static int F_15 ( struct V_69 * V_69 , struct V_30 * V_30 )
{
return 0 ;
}
static int F_16 ( struct V_69 * V_69 , struct V_30 * V_30 )
{
return 0 ;
}
static int
F_17 ( char * V_70 )
{
T_1 V_1 , V_71 ;
T_3 V_35 ;
char * V_72 = V_70 ;
V_65 V_38 , V_39 ;
unsigned long V_34 ;
memset ( & V_1 , 0 , sizeof( V_1 ) ) ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
F_8 ( & V_54 , V_34 ) ;
V_55 . V_56 ( & V_1 , & V_35 ) ;
V_55 . V_67 ( & V_38 , & V_39 , & V_71 ) ;
F_9 ( & V_54 , V_34 ) ;
V_72 += sprintf ( V_72 ,
L_3
L_4
L_5 ,
V_1 . V_15 , V_1 . V_17 , V_1 . V_19 , V_1 . V_21 ,
V_1 . V_3 , V_1 . V_4 , V_1 . V_5 ,
V_1 . V_22 ) ;
if ( V_1 . V_25 == V_26 )
V_72 += sprintf ( V_72 , L_6 ) ;
else
V_72 += sprintf ( V_72 , L_7 , V_1 . V_25 ) ;
V_72 += sprintf ( V_72 ,
L_8
L_9
L_10
L_11
L_12 ,
V_71 . V_15 , V_71 . V_17 , V_71 . V_19 , V_71 . V_21 ,
V_71 . V_3 , V_71 . V_4 , V_71 . V_5 ,
V_71 . V_22 ,
V_38 == 1 ? L_13 : L_14 ,
V_39 == 1 ? L_13 : L_14 ) ;
if ( V_1 . V_25 == V_26 )
V_72 += sprintf ( V_72 , L_6 ) ;
else
V_72 += sprintf ( V_72 , L_7 , V_71 . V_25 ) ;
V_72 += sprintf ( V_72 ,
L_15
L_16
L_17 ,
V_35 . V_73 , V_35 . V_74 , V_35 . V_75 ) ;
return V_72 - V_70 ;
}
static int
F_18 ( char * V_76 , char * * V_77 , T_5 V_78 ,
int V_79 , int * V_80 , void * V_81 )
{
int V_82 = F_17 ( V_76 ) ;
if ( V_82 <= V_78 + V_79 ) * V_80 = 1 ;
* V_77 = V_76 + V_78 ;
V_82 -= V_78 ;
if ( V_82 > V_79 ) V_82 = V_79 ;
if ( V_82 < 0 ) V_82 = 0 ;
return V_82 ;
}
static int T_6
F_19 ( void )
{
int V_83 ;
struct V_84 * V_85 ;
F_4 ( V_86 L_18 , V_87 ) ;
V_83 = F_20 ( & V_88 ) ;
if ( V_83 ) {
F_4 ( V_8 L_19 ,
V_89 ) ;
return V_83 ;
}
V_85 = F_21 ( L_20 , 0 , NULL ,
F_18 , NULL ) ;
if ( V_85 == NULL ) {
F_4 ( V_8 L_21 ) ;
F_22 ( & V_88 ) ;
return - 1 ;
}
return 0 ;
}
static void T_7
F_23 ( void )
{
}
