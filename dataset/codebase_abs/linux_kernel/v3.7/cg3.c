static int F_1 ( unsigned V_1 ,
unsigned V_2 , unsigned V_3 , unsigned V_4 ,
unsigned V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
struct V_10 T_1 * V_11 = & V_9 -> V_12 -> V_13 ;
unsigned long V_14 ;
T_2 * V_15 ;
T_3 * V_16 ;
int V_17 ;
if ( V_1 >= 256 )
return 1 ;
V_2 >>= 8 ;
V_3 >>= 8 ;
V_4 >>= 8 ;
F_2 ( & V_9 -> V_18 , V_14 ) ;
V_16 = ( T_3 * ) V_9 -> V_19 + ( V_1 * 3 ) ;
V_16 [ 0 ] = V_2 ;
V_16 [ 1 ] = V_3 ;
V_16 [ 2 ] = V_4 ;
#define F_3 ( T_4 ) ((((x)>>2)<<1) + ((x)>>2))
#define F_4 ( T_4 ) ((x)&~0x3)
V_17 = 3 ;
V_15 = & V_9 -> V_19 [ F_3 ( V_1 ) ] ;
F_5 ( F_4 ( V_1 ) , & V_11 -> V_20 ) ;
while ( V_17 -- )
F_5 ( * V_15 ++ , & V_11 -> V_21 ) ;
#undef F_3
#undef F_4
F_6 ( & V_9 -> V_18 , V_14 ) ;
return 0 ;
}
static int F_7 ( int V_22 , struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
struct V_23 T_1 * V_12 = V_9 -> V_12 ;
unsigned long V_14 ;
T_3 V_24 ;
F_2 ( & V_9 -> V_18 , V_14 ) ;
switch ( V_22 ) {
case V_25 :
V_24 = F_8 ( & V_12 -> V_26 ) ;
V_24 |= V_27 ;
F_9 ( V_24 , & V_12 -> V_26 ) ;
V_9 -> V_14 &= ~ V_28 ;
break;
case V_29 :
case V_30 :
case V_31 :
case V_32 :
V_24 = F_8 ( & V_12 -> V_26 ) ;
V_24 &= ~ V_27 ;
F_9 ( V_24 , & V_12 -> V_26 ) ;
V_9 -> V_14 |= V_28 ;
break;
}
F_6 ( & V_9 -> V_18 , V_14 ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , struct V_33 * V_34 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
return F_11 ( V_35 ,
V_7 -> V_36 . V_37 , V_7 -> V_36 . V_38 ,
V_9 -> V_39 ,
V_34 ) ;
}
static int F_12 ( struct V_6 * V_7 , unsigned int V_40 , unsigned long V_41 )
{
return F_13 ( V_40 , V_41 , V_7 ,
V_42 , 8 , V_7 -> V_36 . V_38 ) ;
}
static void T_5 F_14 ( struct V_6 * V_7 , int V_43 ,
struct V_44 * V_45 )
{
F_15 ( V_7 -> V_36 . V_46 , V_45 -> V_47 , sizeof( V_7 -> V_36 . V_46 ) ) ;
V_7 -> V_36 . type = V_48 ;
V_7 -> V_36 . V_49 = V_50 ;
V_7 -> V_36 . V_51 = V_43 ;
V_7 -> V_36 . V_52 = V_53 ;
}
static void T_5 F_16 ( struct V_54 * V_55 ,
struct V_44 * V_45 )
{
const char * V_56 ;
char * V_57 ;
int V_58 , V_59 ;
V_56 = F_17 ( V_45 , L_1 , NULL ) ;
if ( V_56 ) {
V_58 = F_18 ( V_56 , & V_57 , 10 ) ;
if ( V_58 && * V_57 == 'x' ) {
V_59 = F_18 ( V_57 + 1 , & V_57 , 10 ) ;
if ( V_59 && * V_57 == '-' ) {
if ( V_55 -> V_60 != V_58 ||
V_55 -> V_61 != V_59 ) {
V_55 -> V_60 = V_55 -> V_62 = V_58 ;
V_55 -> V_61 = V_55 -> V_63 = V_59 ;
}
}
}
}
}
static int T_5 F_19 ( struct V_8 * V_9 )
{
enum V_64 type ;
T_3 * V_57 ;
if ( V_9 -> V_14 & V_65 )
type = V_66 ;
else {
T_3 V_67 = F_8 ( & V_9 -> V_12 -> V_67 ) , V_68 ;
if ( ( V_67 & V_69 ) == V_70 ) {
V_68 = V_67 & V_71 ;
if ( V_68 == V_72 ||
V_68 == V_73 )
type = V_74 ;
else
type = V_75 ;
} else {
F_20 ( V_76 L_2 ,
V_67 ) ;
return - V_77 ;
}
}
for ( V_57 = V_78 [ type ] ; * V_57 ; V_57 += 2 ) {
T_3 T_1 * V_79 = & ( ( T_3 T_1 * ) V_9 -> V_12 ) [ V_57 [ 0 ] ] ;
F_9 ( V_57 [ 1 ] , V_79 ) ;
}
for ( V_57 = V_80 ; * V_57 ; V_57 += 2 ) {
T_3 T_1 * V_79 ;
V_79 = ( T_3 T_1 * ) & V_9 -> V_12 -> V_13 . V_20 ;
F_9 ( V_57 [ 0 ] , V_79 ) ;
V_79 = ( T_3 T_1 * ) & V_9 -> V_12 -> V_13 . V_26 ;
F_9 ( V_57 [ 1 ] , V_79 ) ;
}
return 0 ;
}
static int T_5 F_21 ( struct V_81 * V_82 )
{
struct V_44 * V_45 = V_82 -> V_83 . V_84 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_43 , V_85 ;
V_7 = F_22 ( sizeof( struct V_8 ) , & V_82 -> V_83 ) ;
V_85 = - V_86 ;
if ( ! V_7 )
goto V_87;
V_9 = V_7 -> V_9 ;
F_23 ( & V_9 -> V_18 ) ;
V_7 -> V_36 . V_37 = V_82 -> V_88 [ 0 ] . V_89 ;
V_9 -> V_39 = V_82 -> V_88 [ 0 ] . V_14 & V_90 ;
F_24 ( & V_7 -> V_55 , V_45 , 8 ) ;
V_7 -> V_55 . V_2 . V_91 = 8 ;
V_7 -> V_55 . V_3 . V_91 = 8 ;
V_7 -> V_55 . V_4 . V_91 = 8 ;
if ( ! strcmp ( V_45 -> V_47 , L_3 ) )
V_9 -> V_14 |= V_65 ;
if ( V_9 -> V_14 & V_65 )
F_16 ( & V_7 -> V_55 , V_45 ) ;
V_43 = F_25 ( V_45 , L_4 ,
V_7 -> V_55 . V_60 ) ;
V_7 -> V_36 . V_38 = F_26 ( V_43 * V_7 -> V_55 . V_61 ) ;
V_9 -> V_12 = F_27 ( & V_82 -> V_88 [ 0 ] , V_92 ,
sizeof( struct V_23 ) , L_5 ) ;
if ( ! V_9 -> V_12 )
goto V_93;
V_7 -> V_14 = V_94 ;
V_7 -> V_95 = & V_96 ;
V_7 -> V_97 = F_27 ( & V_82 -> V_88 [ 0 ] , V_98 ,
V_7 -> V_36 . V_38 , L_6 ) ;
if ( ! V_7 -> V_97 )
goto V_99;
F_7 ( V_25 , V_7 ) ;
if ( ! F_28 ( V_45 , L_7 , NULL ) ) {
V_85 = F_19 ( V_9 ) ;
if ( V_85 )
goto V_100;
}
V_85 = F_29 ( & V_7 -> V_13 , 256 , 0 ) ;
if ( V_85 )
goto V_100;
F_30 ( & V_7 -> V_13 , V_7 ) ;
F_14 ( V_7 , V_43 , V_45 ) ;
V_85 = F_31 ( V_7 ) ;
if ( V_85 < 0 )
goto V_101;
F_32 ( & V_82 -> V_83 , V_7 ) ;
F_20 ( V_102 L_8 ,
V_45 -> V_103 , V_9 -> V_39 , V_7 -> V_36 . V_37 ) ;
return 0 ;
V_101:
F_33 ( & V_7 -> V_13 ) ;
V_100:
F_34 ( & V_82 -> V_88 [ 0 ] , V_7 -> V_97 , V_7 -> V_36 . V_38 ) ;
V_99:
F_34 ( & V_82 -> V_88 [ 0 ] , V_9 -> V_12 , sizeof( struct V_23 ) ) ;
V_93:
F_35 ( V_7 ) ;
V_87:
return V_85 ;
}
static int T_6 F_36 ( struct V_81 * V_82 )
{
struct V_6 * V_7 = F_37 ( & V_82 -> V_83 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_38 ( V_7 ) ;
F_33 ( & V_7 -> V_13 ) ;
F_34 ( & V_82 -> V_88 [ 0 ] , V_9 -> V_12 , sizeof( struct V_23 ) ) ;
F_34 ( & V_82 -> V_88 [ 0 ] , V_7 -> V_97 , V_7 -> V_36 . V_38 ) ;
F_35 ( V_7 ) ;
F_32 ( & V_82 -> V_83 , NULL ) ;
return 0 ;
}
static int T_7 F_39 ( void )
{
if ( F_40 ( L_9 , NULL ) )
return - V_104 ;
return F_41 ( & V_105 ) ;
}
static void T_8 F_42 ( void )
{
F_43 ( & V_105 ) ;
}
