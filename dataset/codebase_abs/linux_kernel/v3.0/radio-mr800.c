static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , char V_5 )
{
int V_6 ;
int V_7 ;
V_4 -> V_8 [ 0 ] = 0x00 ;
V_4 -> V_8 [ 1 ] = 0x55 ;
V_4 -> V_8 [ 2 ] = 0xaa ;
V_4 -> V_8 [ 3 ] = 0x00 ;
V_4 -> V_8 [ 4 ] = V_9 ;
V_4 -> V_8 [ 5 ] = V_5 ;
V_4 -> V_8 [ 6 ] = 0x00 ;
V_4 -> V_8 [ 7 ] = 0x00 ;
V_6 = F_4 ( V_4 -> V_10 , F_5 ( V_4 -> V_10 , 2 ) ,
( void * ) ( V_4 -> V_8 ) , V_11 , & V_7 , V_12 ) ;
if ( V_6 < 0 || V_7 != V_11 ) {
F_6 ( & V_4 -> V_13 . V_14 , L_1 ) ;
return V_6 ;
}
V_4 -> V_15 = V_5 ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_4 , int V_16 )
{
int V_6 ;
int V_7 ;
unsigned short V_17 = 0x10 + ( V_16 >> 3 ) / 25 ;
V_4 -> V_8 [ 0 ] = 0x00 ;
V_4 -> V_8 [ 1 ] = 0x55 ;
V_4 -> V_8 [ 2 ] = 0xaa ;
V_4 -> V_8 [ 3 ] = 0x03 ;
V_4 -> V_8 [ 4 ] = V_18 ;
V_4 -> V_8 [ 5 ] = 0x00 ;
V_4 -> V_8 [ 6 ] = 0x00 ;
V_4 -> V_8 [ 7 ] = 0x08 ;
V_6 = F_4 ( V_4 -> V_10 , F_5 ( V_4 -> V_10 , 2 ) ,
( void * ) ( V_4 -> V_8 ) , V_11 , & V_7 , V_12 ) ;
if ( V_6 < 0 || V_7 != V_11 )
goto V_19;
V_4 -> V_8 [ 0 ] = ( V_17 >> 8 ) & 0xff ;
V_4 -> V_8 [ 1 ] = V_17 & 0xff ;
V_4 -> V_8 [ 2 ] = 0x01 ;
V_4 -> V_8 [ 3 ] = 0x00 ;
V_4 -> V_8 [ 4 ] = 0x00 ;
V_4 -> V_8 [ 7 ] = 0x00 ;
V_6 = F_4 ( V_4 -> V_10 , F_5 ( V_4 -> V_10 , 2 ) ,
( void * ) ( V_4 -> V_8 ) , V_11 , & V_7 , V_12 ) ;
if ( V_6 < 0 || V_7 != V_11 )
goto V_19;
V_4 -> V_20 = V_16 ;
goto V_21;
V_19:
F_6 ( & V_4 -> V_13 . V_14 , L_2 ) ;
V_21:
return V_6 ;
}
static int F_8 ( struct V_1 * V_4 , char V_5 )
{
int V_6 ;
int V_7 ;
V_4 -> V_8 [ 0 ] = 0x00 ;
V_4 -> V_8 [ 1 ] = 0x55 ;
V_4 -> V_8 [ 2 ] = 0xaa ;
V_4 -> V_8 [ 3 ] = 0x00 ;
V_4 -> V_8 [ 4 ] = V_22 ;
V_4 -> V_8 [ 5 ] = V_5 ;
V_4 -> V_8 [ 6 ] = 0x00 ;
V_4 -> V_8 [ 7 ] = 0x00 ;
V_6 = F_4 ( V_4 -> V_10 , F_5 ( V_4 -> V_10 , 2 ) ,
( void * ) ( V_4 -> V_8 ) , V_11 , & V_7 , V_12 ) ;
if ( V_6 < 0 || V_7 != V_11 ) {
F_6 ( & V_4 -> V_13 . V_14 , L_3 ) ;
return V_6 ;
}
if ( V_5 == V_23 )
V_4 -> V_24 = 1 ;
else
V_4 -> V_24 = 0 ;
return V_6 ;
}
static void F_9 ( struct V_25 * V_26 )
{
struct V_1 * V_4 = F_1 ( F_10 ( V_26 ) ) ;
F_11 ( & V_4 -> V_27 ) ;
F_12 ( & V_4 -> V_13 . V_14 ) ;
F_13 ( & V_4 -> V_3 ) ;
F_14 ( & V_4 -> V_13 ) ;
F_15 ( & V_4 -> V_27 ) ;
F_16 ( & V_4 -> V_13 . V_14 ) ;
}
static int F_17 ( struct V_28 * V_28 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_4 = V_28 -> V_32 ;
F_18 ( V_31 -> V_33 , L_4 , sizeof( V_31 -> V_33 ) ) ;
F_18 ( V_31 -> V_34 , L_5 , sizeof( V_31 -> V_34 ) ) ;
F_19 ( V_4 -> V_10 , V_31 -> V_35 , sizeof( V_31 -> V_35 ) ) ;
V_31 -> V_36 = V_37 ;
V_31 -> V_38 = V_39 ;
return 0 ;
}
static int F_20 ( struct V_28 * V_28 , void * V_29 ,
struct V_40 * V_31 )
{
struct V_1 * V_4 = V_28 -> V_32 ;
int V_6 ;
if ( V_31 -> V_41 > 0 )
return - V_42 ;
V_6 = F_8 ( V_4 , V_23 ) ;
strcpy ( V_31 -> V_43 , L_6 ) ;
V_31 -> type = V_44 ;
V_31 -> V_45 = V_46 * V_47 ;
V_31 -> V_48 = V_49 * V_47 ;
V_31 -> V_50 = V_51 | V_52 ;
V_31 -> V_53 = V_54 ;
if ( V_4 -> V_24 )
V_31 -> V_55 = V_56 ;
else
V_31 -> V_55 = V_57 ;
V_31 -> signal = 0xffff ;
V_31 -> V_58 = 0 ;
return V_6 ;
}
static int F_21 ( struct V_28 * V_28 , void * V_29 ,
struct V_40 * V_31 )
{
struct V_1 * V_4 = V_28 -> V_32 ;
int V_6 = - V_42 ;
if ( V_31 -> V_41 > 0 )
return - V_42 ;
switch ( V_31 -> V_55 ) {
case V_57 :
V_6 = F_8 ( V_4 , V_59 ) ;
break;
case V_56 :
V_6 = F_8 ( V_4 , V_23 ) ;
break;
}
return V_6 ;
}
static int F_22 ( struct V_28 * V_28 , void * V_29 ,
struct V_60 * V_61 )
{
struct V_1 * V_4 = V_28 -> V_32 ;
if ( V_61 -> V_62 != 0 || V_61 -> type != V_44 )
return - V_42 ;
return F_7 ( V_4 , V_61 -> V_63 ) ;
}
static int F_23 ( struct V_28 * V_28 , void * V_29 ,
struct V_60 * V_61 )
{
struct V_1 * V_4 = V_28 -> V_32 ;
if ( V_61 -> V_62 != 0 )
return - V_42 ;
V_61 -> type = V_44 ;
V_61 -> V_63 = V_4 -> V_20 ;
return 0 ;
}
static int F_24 ( struct V_28 * V_28 , void * V_29 ,
struct V_64 * V_65 )
{
switch ( V_65 -> V_66 ) {
case V_67 :
return F_25 ( V_65 , 0 , 1 , 1 , 1 ) ;
}
return - V_42 ;
}
static int F_26 ( struct V_28 * V_28 , void * V_29 ,
struct V_68 * V_69 )
{
struct V_1 * V_4 = V_28 -> V_32 ;
switch ( V_69 -> V_66 ) {
case V_67 :
V_69 -> V_70 = V_4 -> V_15 ;
return 0 ;
}
return - V_42 ;
}
static int F_27 ( struct V_28 * V_28 , void * V_29 ,
struct V_68 * V_69 )
{
struct V_1 * V_4 = V_28 -> V_32 ;
int V_6 = - V_42 ;
switch ( V_69 -> V_66 ) {
case V_67 :
if ( V_69 -> V_70 )
V_6 = F_3 ( V_4 , V_71 ) ;
else
V_6 = F_3 ( V_4 , V_72 ) ;
break;
}
return V_6 ;
}
static int F_28 ( struct V_28 * V_28 , void * V_29 ,
struct V_73 * V_74 )
{
if ( V_74 -> V_41 > 1 )
return - V_42 ;
strcpy ( V_74 -> V_43 , L_7 ) ;
V_74 -> V_53 = V_75 ;
return 0 ;
}
static int F_29 ( struct V_28 * V_28 , void * V_29 ,
struct V_73 * V_74 )
{
if ( V_74 -> V_41 != 0 )
return - V_42 ;
return 0 ;
}
static int F_30 ( struct V_28 * V_76 , void * V_29 , unsigned int * V_77 )
{
* V_77 = 0 ;
return 0 ;
}
static int F_31 ( struct V_28 * V_76 , void * V_29 , unsigned int V_77 )
{
if ( V_77 != 0 )
return - V_42 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_4 )
{
int V_6 ;
V_6 = F_3 ( V_4 , V_71 ) ;
if ( V_6 )
goto V_19;
V_6 = F_8 ( V_4 , V_23 ) ;
if ( V_6 )
goto V_19;
V_4 -> V_78 = 1 ;
goto V_21;
V_19:
F_33 ( & V_4 -> V_13 . V_14 , L_8 ) ;
V_21:
return V_6 ;
}
static int F_34 ( struct V_28 * V_28 )
{
struct V_1 * V_4 = F_35 ( V_28 ) ;
int V_6 ;
V_28 -> V_32 = V_4 ;
V_6 = F_36 ( V_4 -> V_26 ) ;
if ( V_6 )
return V_6 ;
if ( F_37 ( ! V_4 -> V_78 ) ) {
V_6 = F_32 ( V_4 ) ;
if ( V_6 )
F_38 ( V_4 -> V_26 ) ;
}
return V_6 ;
}
static int F_39 ( struct V_28 * V_28 )
{
struct V_1 * V_4 = V_28 -> V_32 ;
if ( F_40 ( & V_4 -> V_13 ) )
F_38 ( V_4 -> V_26 ) ;
return 0 ;
}
static int F_41 ( struct V_25 * V_26 , T_1 V_79 )
{
struct V_1 * V_4 = F_1 ( F_10 ( V_26 ) ) ;
F_11 ( & V_4 -> V_27 ) ;
if ( ! V_4 -> V_15 && V_4 -> V_78 ) {
F_3 ( V_4 , V_71 ) ;
V_4 -> V_15 = 0 ;
}
F_15 ( & V_4 -> V_27 ) ;
F_42 ( & V_26 -> V_14 , L_9 ) ;
return 0 ;
}
static int F_43 ( struct V_25 * V_26 )
{
struct V_1 * V_4 = F_1 ( F_10 ( V_26 ) ) ;
F_11 ( & V_4 -> V_27 ) ;
if ( F_37 ( ! V_4 -> V_78 ) )
goto V_80;
if ( V_4 -> V_24 )
F_8 ( V_4 , V_23 ) ;
else
F_8 ( V_4 , V_59 ) ;
F_7 ( V_4 , V_4 -> V_20 ) ;
if ( ! V_4 -> V_15 )
F_3 ( V_4 , V_72 ) ;
V_80:
F_15 ( & V_4 -> V_27 ) ;
F_42 ( & V_26 -> V_14 , L_10 ) ;
return 0 ;
}
static void F_44 ( struct V_81 * V_13 )
{
struct V_1 * V_4 = F_45 ( V_13 ) ;
F_46 ( V_4 -> V_8 ) ;
F_46 ( V_4 ) ;
}
static int F_47 ( struct V_25 * V_26 ,
const struct V_82 * V_66 )
{
struct V_1 * V_4 ;
int V_6 = 0 ;
V_4 = F_48 ( sizeof( struct V_1 ) , V_83 ) ;
if ( ! V_4 ) {
F_49 ( & V_26 -> V_14 , L_11 ) ;
V_6 = - V_84 ;
goto V_85;
}
V_4 -> V_8 = F_50 ( V_11 , V_83 ) ;
if ( ! V_4 -> V_8 ) {
F_49 ( & V_26 -> V_14 , L_12 ) ;
V_6 = - V_84 ;
goto V_86;
}
V_6 = F_51 ( & V_26 -> V_14 , & V_4 -> V_3 ) ;
if ( V_6 < 0 ) {
F_49 ( & V_26 -> V_14 , L_13 ) ;
goto V_87;
}
F_52 ( & V_4 -> V_27 ) ;
F_18 ( V_4 -> V_13 . V_43 , V_4 -> V_3 . V_43 ,
sizeof( V_4 -> V_13 . V_43 ) ) ;
V_4 -> V_13 . V_3 = & V_4 -> V_3 ;
V_4 -> V_13 . V_88 = & V_89 ;
V_4 -> V_13 . V_90 = & V_91 ;
V_4 -> V_13 . V_92 = F_44 ;
V_4 -> V_13 . V_27 = & V_4 -> V_27 ;
V_4 -> V_10 = F_53 ( V_26 ) ;
V_4 -> V_26 = V_26 ;
V_4 -> V_20 = 95.16 * V_47 ;
F_54 ( & V_4 -> V_13 , V_4 ) ;
V_6 = F_55 ( & V_4 -> V_13 , V_93 ,
V_94 ) ;
if ( V_6 < 0 ) {
F_49 ( & V_26 -> V_14 , L_14 ) ;
goto V_95;
}
return 0 ;
V_95:
F_56 ( & V_4 -> V_3 ) ;
V_87:
F_46 ( V_4 -> V_8 ) ;
V_86:
F_46 ( V_4 ) ;
V_85:
return V_6 ;
}
static int T_2 F_57 ( void )
{
int V_6 = F_58 ( & V_96 ) ;
F_59 ( V_97
L_15 V_98 L_16 V_99 L_17 ) ;
if ( V_6 )
F_60 ( V_97
L_18 , V_6 ) ;
return V_6 ;
}
static void T_3 F_61 ( void )
{
F_62 ( & V_96 ) ;
}
