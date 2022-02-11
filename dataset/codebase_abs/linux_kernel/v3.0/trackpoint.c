static int F_1 ( struct V_1 * V_1 , unsigned char V_2 , unsigned char * V_3 )
{
if ( F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_4 ) ) ||
F_2 ( V_1 , V_3 , F_3 ( 0 , 1 , V_2 ) ) ) {
return - 1 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , unsigned char V_2 , unsigned char V_5 )
{
if ( F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_4 ) ) ||
F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_6 ) ) ||
F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_2 ) ) ||
F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_5 ) ) ) {
return - 1 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , unsigned char V_2 , unsigned char V_7 )
{
if ( V_2 < 0x20 || V_2 >= 0x2F )
return - 1 ;
if ( F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_4 ) ) ||
F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_8 ) ) ||
F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_2 ) ) ||
F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_7 ) ) ) {
return - 1 ;
}
return 0 ;
}
static T_1 F_6 ( struct V_9 * V_9 , void * V_10 , char * V_11 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_15 * V_16 = V_10 ;
unsigned char V_17 = * ( unsigned char * ) ( ( char * ) V_13 + V_16 -> V_18 ) ;
if ( V_16 -> V_19 )
V_17 = ! V_17 ;
return sprintf ( V_11 , L_1 , V_17 ) ;
}
static T_1 F_7 ( struct V_9 * V_9 , void * V_10 ,
const char * V_11 , T_2 V_20 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_15 * V_16 = V_10 ;
unsigned char * V_21 = ( unsigned char * ) ( ( char * ) V_13 + V_16 -> V_18 ) ;
unsigned long V_17 ;
if ( F_8 ( V_11 , 10 , & V_17 ) || V_17 > 255 )
return - V_22 ;
* V_21 = V_17 ;
F_4 ( & V_9 -> V_1 , V_16 -> V_23 , V_17 ) ;
return V_20 ;
}
static T_1 F_9 ( struct V_9 * V_9 , void * V_10 ,
const char * V_11 , T_2 V_20 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_15 * V_16 = V_10 ;
unsigned char * V_21 = ( unsigned char * ) ( ( char * ) V_13 + V_16 -> V_18 ) ;
unsigned long V_17 ;
if ( F_8 ( V_11 , 10 , & V_17 ) || V_17 > 1 )
return - V_22 ;
if ( V_16 -> V_19 )
V_17 = ! V_17 ;
if ( * V_21 != V_17 ) {
* V_21 = V_17 ;
F_5 ( & V_9 -> V_1 , V_16 -> V_23 , V_16 -> V_7 ) ;
}
return V_20 ;
}
static int F_10 ( struct V_9 * V_9 , unsigned char * V_24 )
{
unsigned char V_25 [ 2 ] = { 0 } ;
if ( F_2 ( & V_9 -> V_1 , V_25 , F_3 ( 0 , 2 , V_26 ) ) )
return - 1 ;
if ( V_25 [ 0 ] != V_27 )
return - 1 ;
if ( V_24 )
* V_24 = V_25 [ 1 ] ;
return 0 ;
}
static int F_11 ( struct V_9 * V_9 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
unsigned char V_28 ;
F_1 ( & V_9 -> V_1 , V_29 , & V_28 ) ;
if ( V_28 & V_30 )
F_5 ( & V_9 -> V_1 , V_29 , V_30 ) ;
F_1 ( & V_9 -> V_1 , V_31 , & V_28 ) ;
if ( V_28 & V_32 )
F_5 ( & V_9 -> V_1 , V_31 , V_32 ) ;
F_1 ( & V_9 -> V_1 , V_33 , & V_28 ) ;
if ( V_28 & V_34 )
F_5 ( & V_9 -> V_1 , V_33 , V_34 ) ;
F_4 ( & V_9 -> V_1 , V_35 , V_13 -> V_36 ) ;
F_4 ( & V_9 -> V_1 , V_37 , V_13 -> V_38 ) ;
F_4 ( & V_9 -> V_1 , V_39 , V_13 -> V_40 ) ;
F_4 ( & V_9 -> V_1 , V_41 , V_13 -> V_42 ) ;
F_4 ( & V_9 -> V_1 , V_43 , V_13 -> V_44 ) ;
F_4 ( & V_9 -> V_1 , V_45 , V_13 -> V_46 ) ;
F_4 ( & V_9 -> V_1 , V_47 , V_13 -> V_48 ) ;
F_4 ( & V_9 -> V_1 , V_49 , V_13 -> V_50 ) ;
F_4 ( & V_9 -> V_1 , V_51 , V_13 -> V_52 ) ;
F_4 ( & V_9 -> V_1 , V_53 , V_13 -> V_54 ) ;
F_1 ( & V_9 -> V_1 , V_55 , & V_28 ) ;
if ( ( ( V_28 & V_56 ) == V_56 ) != V_13 -> V_57 )
F_5 ( & V_9 -> V_1 , V_55 , V_56 ) ;
F_1 ( & V_9 -> V_1 , V_58 , & V_28 ) ;
if ( ( ( V_28 & V_59 ) == V_59 ) != V_13 -> V_60 )
F_5 ( & V_9 -> V_1 , V_58 , V_59 ) ;
F_1 ( & V_9 -> V_1 , V_61 , & V_28 ) ;
if ( ( ( V_28 & V_62 ) == V_62 ) != V_13 -> V_63 )
F_5 ( & V_9 -> V_1 , V_61 , V_62 ) ;
return 0 ;
}
static void F_12 ( struct V_12 * V_13 )
{
V_13 -> V_57 = V_64 ;
V_13 -> V_36 = V_65 ;
V_13 -> V_40 = V_66 ;
V_13 -> V_42 = V_67 ;
V_13 -> V_44 = V_68 ;
V_13 -> V_46 = V_69 ;
V_13 -> V_48 = V_70 ;
V_13 -> V_50 = V_71 ;
V_13 -> V_52 = V_72 ;
V_13 -> V_54 = V_73 ;
V_13 -> V_38 = V_74 ;
V_13 -> V_60 = V_75 ;
V_13 -> V_63 = V_76 ;
}
static void F_13 ( struct V_9 * V_9 )
{
F_14 ( & V_9 -> V_1 . V_77 -> V_78 . V_79 , & V_80 ) ;
F_15 ( V_9 -> V_14 ) ;
V_9 -> V_14 = NULL ;
}
static int F_16 ( struct V_9 * V_9 )
{
if ( F_10 ( V_9 , NULL ) )
return - 1 ;
if ( F_11 ( V_9 ) )
return - 1 ;
return 0 ;
}
int F_17 ( struct V_9 * V_9 , bool V_81 )
{
struct V_1 * V_1 = & V_9 -> V_1 ;
unsigned char V_24 ;
unsigned char V_82 ;
int error ;
if ( F_10 ( V_9 , & V_24 ) )
return - 1 ;
if ( ! V_81 )
return 0 ;
if ( F_1 ( & V_9 -> V_1 , V_83 , & V_82 ) ) {
F_18 ( V_84 L_2 ) ;
V_82 = 0 ;
}
V_9 -> V_14 = F_19 ( sizeof( struct V_12 ) , V_85 ) ;
if ( ! V_9 -> V_14 )
return - V_86 ;
V_9 -> V_87 = L_3 ;
V_9 -> V_88 = L_4 ;
V_9 -> V_89 = F_16 ;
V_9 -> V_90 = F_13 ;
if ( ( V_82 & 0x0f ) >= 3 )
F_20 ( V_91 , V_9 -> V_78 -> V_92 ) ;
F_12 ( V_9 -> V_14 ) ;
F_11 ( V_9 ) ;
error = F_21 ( & V_1 -> V_77 -> V_78 . V_79 , & V_80 ) ;
if ( error ) {
F_18 ( V_93
L_5 ,
error ) ;
F_15 ( V_9 -> V_14 ) ;
V_9 -> V_14 = NULL ;
return - 1 ;
}
F_18 ( V_94 L_6 ,
V_24 , ( V_82 & 0xf0 ) >> 4 , V_82 & 0x0f ) ;
return 0 ;
}
