static inline struct V_1 * F_1 ( unsigned int V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_2 + V_5 , V_3 ) ;
if ( V_4 )
F_3 ( V_4 , V_5 ) ;
return V_4 ;
}
static void F_4 ( struct V_6 * V_7 ,
struct V_1 * V_4 )
{
struct V_8 * V_9 = ( void * ) V_4 -> V_10 ;
if ( ( V_4 -> V_2 > 3 ) && ( V_9 -> V_11 == V_12 ) &&
( V_9 -> V_13 == V_14 ) ) {
memcpy ( & V_7 -> V_15 , V_9 ,
sizeof( struct V_8 ) ) ;
}
F_5 ( V_4 ) ;
F_6 ( & V_7 -> V_16 ) ;
}
static int F_7 ( struct V_6 * V_7 , char * V_17 )
{
struct V_18 * V_19 ;
struct V_1 * V_4 ;
unsigned long V_20 ;
int V_21 ;
V_4 = F_1 ( sizeof( struct V_18 ) ,
V_22 ) ;
if ( ! V_4 ) {
F_8 ( & V_7 -> V_23 -> V_24 ,
L_1 ) ;
return - V_25 ;
}
V_19 = (struct V_18 * )
F_9 ( V_4 , sizeof( struct V_18 ) ) ;
V_19 -> V_11 = V_26 ;
V_19 -> V_13 = V_27 ;
V_19 -> V_28 = 0 ;
V_7 -> V_15 . V_28 = 0 ;
V_21 = F_10 ( V_7 -> V_29 , V_4 ) ;
if ( V_21 )
return V_21 ;
V_20 = F_11 ( & V_7 -> V_16 ,
F_12 ( V_30 ) ) ;
F_13 ( & V_7 -> V_23 -> V_24 , L_2 ,
V_20 ) ;
if ( V_20 == 0 ) {
F_8 ( & V_7 -> V_23 -> V_24 ,
L_3 ) ;
return - V_31 ;
}
F_13 ( & V_7 -> V_23 -> V_24 , L_4 ,
V_7 -> V_15 . V_28 , V_7 -> V_15 . V_32 ) ;
if ( ( V_7 -> V_15 . V_28 != 5 ) || ( V_7 -> V_15 . V_32 != 0 ) ) {
F_8 ( & V_7 -> V_23 -> V_24 , L_5 ) ;
return - V_33 ;
}
snprintf ( V_17 , V_34 ,
L_6 ,
V_7 -> V_15 . V_35 ,
V_7 -> V_15 . V_36 ,
V_7 -> V_15 . V_37 ,
V_7 -> V_15 . V_38 ) ;
F_14 ( & V_7 -> V_23 -> V_24 , L_7 , V_17 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , T_2 * V_10 , int V_2 )
{
struct V_39 * V_40 = (struct V_39 * ) V_10 ;
struct V_1 * V_4 ;
unsigned long V_20 ;
int V_21 ;
if ( ( V_2 <= sizeof( struct V_39 ) ) ||
( V_2 > V_41 ) ||
( V_40 -> V_42 != V_43 ) ||
( V_40 -> V_44 != V_45 ) ) {
F_8 ( & V_7 -> V_23 -> V_24 ,
L_8 ,
V_2 , V_40 -> V_42 , V_40 -> V_44 ) ;
return 0 ;
}
V_2 -= sizeof( struct V_39 ) ;
V_10 += sizeof( struct V_39 ) ;
V_4 = F_1 ( V_2 , V_22 ) ;
if ( ! V_4 ) {
F_8 ( & V_7 -> V_23 -> V_24 , L_9 ) ;
return - V_25 ;
}
memcpy ( F_9 ( V_4 , V_2 ) , V_10 , V_2 ) ;
V_21 = F_10 ( V_7 -> V_29 , V_4 ) ;
if ( V_21 )
return V_21 ;
V_20 = F_11 ( & V_7 -> V_16 ,
F_12 ( V_30 ) ) ;
F_13 ( & V_7 -> V_23 -> V_24 , L_2 ,
V_20 ) ;
if ( V_20 == 0 ) {
F_8 ( & V_7 -> V_23 -> V_24 ,
L_3 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_16 ( struct V_6 * V_7 )
{
unsigned char V_17 [ V_34 ] ;
const struct V_46 * V_47 ;
T_3 V_48 , V_49 ;
T_2 * V_50 ;
int V_2 , V_21 ;
F_17 ( V_51 , & V_7 -> V_52 ) ;
V_21 = F_7 ( V_7 , V_17 ) ;
if ( V_21 )
goto exit;
V_21 = F_18 ( & V_47 , V_17 , & V_7 -> V_23 -> V_24 ) ;
if ( V_21 ) {
F_8 ( & V_7 -> V_23 -> V_24 , L_10 , V_21 ) ;
if ( V_21 == - V_53 )
V_21 = 0 ;
goto exit;
}
V_2 = V_47 -> V_54 ;
V_50 = ( T_2 * ) V_47 -> V_10 ;
if ( ( V_2 == 0 ) || ( V_50 == NULL ) ) {
F_13 ( & V_7 -> V_23 -> V_24 ,
L_11 , V_2 ) ;
goto V_55;
}
if ( F_19 ( ( (struct V_56 * ) V_50 ) -> V_57 ) !=
V_58 ) {
F_8 ( & V_7 -> V_23 -> V_24 , L_12 ) ;
V_21 = - V_33 ;
goto V_55;
}
V_2 -= sizeof( struct V_56 ) ;
V_50 += sizeof( struct V_56 ) ;
while ( V_2 > 0 ) {
V_48 =
F_20 ( ( (struct V_59 * ) V_50 ) -> type ) ;
V_49 =
F_20 ( ( (struct V_59 * ) V_50 ) -> V_2 ) ;
F_13 ( & V_7 -> V_23 -> V_24 , L_13 ,
V_48 , V_49 ) ;
switch ( V_48 ) {
case V_60 :
V_21 = F_15 ( V_7 ,
( (struct V_59 * ) V_50 ) -> V_10 ,
V_49 ) ;
if ( V_21 )
goto V_55;
break;
}
V_2 -= ( sizeof( struct V_59 ) + V_49 ) ;
V_50 += ( sizeof( struct V_59 ) + V_49 ) ;
}
V_55:
F_21 ( V_47 ) ;
exit:
F_22 ( V_51 , & V_7 -> V_52 ) ;
return V_21 ;
}
static void F_23 ( void * V_61 , char V_10 )
{
struct V_6 * V_7 = V_61 ;
V_7 -> V_62 = V_10 ;
F_6 ( & V_7 -> V_16 ) ;
}
static long F_24 ( void * V_61 , struct V_1 * V_4 )
{
struct V_6 * V_7 = V_61 ;
int V_21 ;
if ( ! V_4 )
return - V_63 ;
if ( ! V_7 ) {
F_5 ( V_4 ) ;
return - V_63 ;
}
F_13 ( & V_7 -> V_23 -> V_24 , L_14 , V_4 -> V_2 ) ;
F_25 ( V_4 , ( V_5 - 1 ) ) ;
if ( F_26 ( V_51 , & V_7 -> V_52 ) ) {
F_4 ( V_7 , V_4 ) ;
return 0 ;
}
V_21 = F_27 ( V_7 -> V_29 , V_4 ) ;
if ( V_21 < 0 ) {
F_8 ( & V_7 -> V_23 -> V_24 , L_15 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
static int F_28 ( struct V_64 * V_29 )
{
struct V_6 * V_7 = F_29 ( V_29 ) ;
unsigned long V_20 ;
int V_21 ;
if ( F_30 ( V_65 , & V_7 -> V_52 ) ) {
V_21 = - V_66 ;
goto exit;
}
V_67 . V_61 = V_7 ;
F_31 ( & V_7 -> V_16 ) ;
V_7 -> V_62 = - V_68 ;
V_21 = F_32 ( & V_67 ) ;
if ( V_21 < 0 ) {
if ( V_21 == - V_68 ) {
V_20 = F_11 (
& V_7 -> V_16 ,
F_12 ( V_69 ) ) ;
F_13 ( & V_7 -> V_23 -> V_24 ,
L_2 ,
V_20 ) ;
if ( V_20 == 0 ) {
V_21 = - V_31 ;
goto V_70;
} else if ( V_7 -> V_62 != 0 ) {
V_21 = V_7 -> V_62 ;
F_8 ( & V_7 -> V_23 -> V_24 ,
L_16 , V_21 ) ;
goto V_70;
}
} else {
F_8 ( & V_7 -> V_23 -> V_24 , L_17 , V_21 ) ;
goto V_70;
}
}
F_33 ( V_67 . V_71 == NULL ) ;
V_7 -> V_72 = V_67 . V_71 ;
if ( F_16 ( V_7 ) ) {
F_8 ( & V_7 -> V_23 -> V_24 , L_18 ,
V_21 ) ;
}
goto exit;
V_70:
F_22 ( V_65 , & V_7 -> V_52 ) ;
exit:
return V_21 ;
}
static int F_34 ( struct V_64 * V_29 )
{
struct V_6 * V_7 = F_29 ( V_29 ) ;
int V_21 ;
if ( ! F_35 ( V_65 , & V_7 -> V_52 ) )
return 0 ;
V_21 = F_36 ( & V_67 ) ;
if ( V_21 )
F_8 ( & V_7 -> V_23 -> V_24 , L_19 , V_21 ) ;
V_7 -> V_72 = NULL ;
return V_21 ;
}
static int F_10 ( struct V_64 * V_29 , struct V_1 * V_4 )
{
struct V_6 * V_7 = F_29 ( V_29 ) ;
struct V_39 V_40 = { V_43 , V_45 , 0x0000 } ;
long V_2 ;
F_13 ( & V_7 -> V_23 -> V_24 , L_20 , V_4 -> V_2 ) ;
if ( ! F_26 ( V_65 , & V_7 -> V_52 ) ) {
F_5 ( V_4 ) ;
return - V_33 ;
}
V_40 . V_2 = F_37 ( V_4 -> V_2 ) ;
memcpy ( F_38 ( V_4 , V_5 ) , & V_40 , V_5 ) ;
V_2 = V_7 -> V_72 ( V_4 ) ;
if ( V_2 < 0 ) {
F_5 ( V_4 ) ;
F_8 ( & V_7 -> V_23 -> V_24 , L_21 , V_2 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_39 ( struct V_73 * V_23 )
{
struct V_6 * V_7 ;
int V_21 ;
T_4 V_74 ;
V_7 = F_40 ( & V_23 -> V_24 , sizeof( struct V_6 ) , V_22 ) ;
if ( ! V_7 ) {
V_21 = - V_25 ;
goto exit;
}
V_7 -> V_23 = V_23 ;
V_74 = V_75
| V_76 | V_77
| V_78
| V_79
| V_80 ;
V_7 -> V_29 = F_41 ( & V_81 ,
V_74 ,
V_5 ,
0 ) ;
if ( ! V_7 -> V_29 ) {
F_8 ( & V_23 -> V_24 , L_22 ) ;
V_21 = - V_25 ;
goto exit;
}
F_42 ( V_7 -> V_29 , & V_23 -> V_24 ) ;
F_43 ( V_7 -> V_29 , V_7 ) ;
V_21 = F_44 ( V_7 -> V_29 ) ;
if ( V_21 < 0 ) {
F_8 ( & V_23 -> V_24 , L_23 , V_21 ) ;
goto V_82;
}
F_45 ( & V_23 -> V_24 , V_7 ) ;
goto exit;
V_82:
F_46 ( V_7 -> V_29 ) ;
exit:
return V_21 ;
}
static int F_47 ( struct V_73 * V_23 )
{
struct V_6 * V_7 = F_48 ( & V_23 -> V_24 ) ;
struct V_64 * V_29 ;
if ( ! V_7 )
return - V_63 ;
V_29 = V_7 -> V_29 ;
F_49 ( V_29 ) ;
F_46 ( V_29 ) ;
return 0 ;
}
