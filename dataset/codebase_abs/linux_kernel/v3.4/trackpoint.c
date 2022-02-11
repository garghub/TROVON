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
unsigned char V_17 ;
int V_22 ;
V_22 = F_8 ( V_11 , 10 , & V_17 ) ;
if ( V_22 )
return V_22 ;
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
unsigned int V_17 ;
int V_22 ;
V_22 = F_10 ( V_11 , 10 , & V_17 ) ;
if ( V_22 )
return V_22 ;
if ( V_17 > 1 )
return - V_24 ;
if ( V_16 -> V_19 )
V_17 = ! V_17 ;
if ( * V_21 != V_17 ) {
* V_21 = V_17 ;
F_5 ( & V_9 -> V_1 , V_16 -> V_23 , V_16 -> V_7 ) ;
}
return V_20 ;
}
static int F_11 ( struct V_9 * V_9 , unsigned char * V_25 )
{
unsigned char V_26 [ 2 ] = { 0 } ;
if ( F_2 ( & V_9 -> V_1 , V_26 , F_3 ( 0 , 2 , V_27 ) ) )
return - 1 ;
if ( V_26 [ 0 ] != V_28 )
return - 1 ;
if ( V_25 )
* V_25 = V_26 [ 1 ] ;
return 0 ;
}
static int F_12 ( struct V_9 * V_9 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
unsigned char V_29 ;
F_1 ( & V_9 -> V_1 , V_30 , & V_29 ) ;
if ( V_29 & V_31 )
F_5 ( & V_9 -> V_1 , V_30 , V_31 ) ;
F_1 ( & V_9 -> V_1 , V_32 , & V_29 ) ;
if ( V_29 & V_33 )
F_5 ( & V_9 -> V_1 , V_32 , V_33 ) ;
F_1 ( & V_9 -> V_1 , V_34 , & V_29 ) ;
if ( V_29 & V_35 )
F_5 ( & V_9 -> V_1 , V_34 , V_35 ) ;
F_4 ( & V_9 -> V_1 , V_36 , V_13 -> V_37 ) ;
F_4 ( & V_9 -> V_1 , V_38 , V_13 -> V_39 ) ;
F_4 ( & V_9 -> V_1 , V_40 , V_13 -> V_41 ) ;
F_4 ( & V_9 -> V_1 , V_42 , V_13 -> V_43 ) ;
F_4 ( & V_9 -> V_1 , V_44 , V_13 -> V_45 ) ;
F_4 ( & V_9 -> V_1 , V_46 , V_13 -> V_47 ) ;
F_4 ( & V_9 -> V_1 , V_48 , V_13 -> V_49 ) ;
F_4 ( & V_9 -> V_1 , V_50 , V_13 -> V_51 ) ;
F_4 ( & V_9 -> V_1 , V_52 , V_13 -> V_53 ) ;
F_4 ( & V_9 -> V_1 , V_54 , V_13 -> V_55 ) ;
F_1 ( & V_9 -> V_1 , V_56 , & V_29 ) ;
if ( ( ( V_29 & V_57 ) == V_57 ) != V_13 -> V_58 )
F_5 ( & V_9 -> V_1 , V_56 , V_57 ) ;
F_1 ( & V_9 -> V_1 , V_59 , & V_29 ) ;
if ( ( ( V_29 & V_60 ) == V_60 ) != V_13 -> V_61 )
F_5 ( & V_9 -> V_1 , V_59 , V_60 ) ;
F_1 ( & V_9 -> V_1 , V_62 , & V_29 ) ;
if ( ( ( V_29 & V_63 ) == V_63 ) != V_13 -> V_64 )
F_5 ( & V_9 -> V_1 , V_62 , V_63 ) ;
return 0 ;
}
static void F_13 ( struct V_12 * V_13 )
{
V_13 -> V_58 = V_65 ;
V_13 -> V_37 = V_66 ;
V_13 -> V_41 = V_67 ;
V_13 -> V_43 = V_68 ;
V_13 -> V_45 = V_69 ;
V_13 -> V_47 = V_70 ;
V_13 -> V_49 = V_71 ;
V_13 -> V_51 = V_72 ;
V_13 -> V_53 = V_73 ;
V_13 -> V_55 = V_74 ;
V_13 -> V_39 = V_75 ;
V_13 -> V_61 = V_76 ;
V_13 -> V_64 = V_77 ;
}
static void F_14 ( struct V_9 * V_9 )
{
F_15 ( & V_9 -> V_1 . V_78 -> V_79 . V_80 , & V_81 ) ;
F_16 ( V_9 -> V_14 ) ;
V_9 -> V_14 = NULL ;
}
static int F_17 ( struct V_9 * V_9 )
{
if ( F_11 ( V_9 , NULL ) )
return - 1 ;
if ( F_12 ( V_9 ) )
return - 1 ;
return 0 ;
}
int F_18 ( struct V_9 * V_9 , bool V_82 )
{
struct V_1 * V_1 = & V_9 -> V_1 ;
unsigned char V_25 ;
unsigned char V_83 ;
int error ;
if ( F_11 ( V_9 , & V_25 ) )
return - 1 ;
if ( ! V_82 )
return 0 ;
if ( F_1 ( & V_9 -> V_1 , V_84 , & V_83 ) ) {
F_19 ( V_9 , L_2 ) ;
V_83 = 0 ;
}
V_9 -> V_14 = F_20 ( sizeof( struct V_12 ) , V_85 ) ;
if ( ! V_9 -> V_14 )
return - V_86 ;
V_9 -> V_87 = L_3 ;
V_9 -> V_88 = L_4 ;
V_9 -> V_89 = F_17 ;
V_9 -> V_90 = F_14 ;
if ( ( V_83 & 0x0f ) >= 3 )
F_21 ( V_91 , V_9 -> V_79 -> V_92 ) ;
F_13 ( V_9 -> V_14 ) ;
F_12 ( V_9 ) ;
error = F_22 ( & V_1 -> V_78 -> V_79 . V_80 , & V_81 ) ;
if ( error ) {
F_23 ( V_9 ,
L_5 ,
error ) ;
F_16 ( V_9 -> V_14 ) ;
V_9 -> V_14 = NULL ;
return - 1 ;
}
F_24 ( V_9 ,
L_6 ,
V_25 ,
( V_83 & 0xf0 ) >> 4 , V_83 & 0x0f ) ;
return 0 ;
}
