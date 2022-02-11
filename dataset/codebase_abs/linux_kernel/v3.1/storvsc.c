static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
F_3 ( & V_4 -> V_6 , 0 , 2 ) ;
F_4 ( & V_4 -> V_7 ) ;
V_4 -> V_3 = V_3 ;
V_3 -> V_8 = V_4 ;
return V_4 ;
}
static inline void F_5 ( struct V_1 * V_3 )
{
F_6 ( V_3 ) ;
}
static inline struct V_1 * F_7 (
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = (struct V_1 * ) V_3 -> V_8 ;
if ( V_4 && F_8 ( & V_4 -> V_6 ) )
F_9 ( & V_4 -> V_6 ) ;
else
V_4 = NULL ;
return V_4 ;
}
static inline struct V_1 * F_10 (
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = (struct V_1 * ) V_3 -> V_8 ;
while ( F_3 ( & V_4 -> V_6 , 2 , 1 ) != 2 )
F_11 ( 100 ) ;
return V_4 ;
}
static inline struct V_1 * F_12 (
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = (struct V_1 * ) V_3 -> V_8 ;
while ( F_3 ( & V_4 -> V_6 , 1 , 0 ) != 1 )
F_11 ( 100 ) ;
V_3 -> V_8 = NULL ;
return V_4 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_9 * V_10 ;
struct V_11 * V_11 ;
int V_12 , V_13 ;
V_4 = F_14 ( V_3 ) ;
if ( ! V_4 )
return - 1 ;
V_10 = & V_4 -> V_14 ;
V_11 = & V_10 -> V_11 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
F_15 ( & V_10 -> V_15 ) ;
V_11 -> V_16 = V_17 ;
V_11 -> V_18 = V_19 ;
F_16 ( V_20 , L_1 ) ;
V_12 = F_17 ( V_3 -> V_21 , V_11 ,
sizeof( struct V_11 ) ,
( unsigned long ) V_10 ,
V_22 ,
V_23 ) ;
if ( V_12 != 0 )
goto V_24;
V_13 = F_18 ( & V_10 -> V_15 , 5 * V_25 ) ;
if ( V_13 == 0 ) {
V_12 = - V_26 ;
goto V_24;
}
if ( V_11 -> V_16 != V_27 ||
V_11 -> V_28 != 0 )
goto V_24;
F_16 ( V_20 , L_2 ) ;
memset ( V_11 , 0 , sizeof( struct V_11 ) ) ;
V_11 -> V_16 = V_29 ;
V_11 -> V_18 = V_19 ;
V_11 -> V_30 . V_31 = V_32 ;
F_19 ( V_11 -> V_30 . V_33 ) ;
V_12 = F_17 ( V_3 -> V_21 , V_11 ,
sizeof( struct V_11 ) ,
( unsigned long ) V_10 ,
V_22 ,
V_23 ) ;
if ( V_12 != 0 )
goto V_24;
V_13 = F_18 ( & V_10 -> V_15 , 5 * V_25 ) ;
if ( V_13 == 0 ) {
V_12 = - V_26 ;
goto V_24;
}
if ( V_11 -> V_16 != V_27 ||
V_11 -> V_28 != 0 )
goto V_24;
F_16 ( V_20 , L_3 ) ;
memset ( V_11 , 0 , sizeof( struct V_11 ) ) ;
V_11 -> V_16 = V_34 ;
V_11 -> V_18 = V_19 ;
V_11 -> V_35 . V_36 =
V_4 -> V_36 ;
V_12 = F_17 ( V_3 -> V_21 , V_11 ,
sizeof( struct V_11 ) ,
( unsigned long ) V_10 ,
V_22 ,
V_23 ) ;
if ( V_12 != 0 )
goto V_24;
V_13 = F_18 ( & V_10 -> V_15 , 5 * V_25 ) ;
if ( V_13 == 0 ) {
V_12 = - V_26 ;
goto V_24;
}
if ( V_11 -> V_16 != V_27 ||
V_11 -> V_28 != 0 )
goto V_24;
V_4 -> V_37 = V_11 -> V_35 . V_37 ;
V_4 -> V_38
= V_11 -> V_35 . V_38 ;
F_16 ( V_20 , L_4 ) ;
memset ( V_11 , 0 , sizeof( struct V_11 ) ) ;
V_11 -> V_16 = V_39 ;
V_11 -> V_18 = V_19 ;
V_12 = F_17 ( V_3 -> V_21 , V_11 ,
sizeof( struct V_11 ) ,
( unsigned long ) V_10 ,
V_22 ,
V_23 ) ;
if ( V_12 != 0 )
goto V_24;
V_13 = F_18 ( & V_10 -> V_15 , 5 * V_25 ) ;
if ( V_13 == 0 ) {
V_12 = - V_26 ;
goto V_24;
}
if ( V_11 -> V_16 != V_27 ||
V_11 -> V_28 != 0 )
goto V_24;
F_16 ( V_20 , L_5 ) ;
V_24:
F_20 ( V_3 ) ;
return V_12 ;
}
static void F_21 ( struct V_2 * V_3 ,
struct V_11 * V_11 ,
struct V_9 * V_10 )
{
struct V_1 * V_4 ;
struct V_11 * V_40 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
V_40 = & V_10 -> V_11 ;
V_40 -> V_41 . V_42 = V_11 -> V_41 . V_42 ;
V_40 -> V_41 . V_43 = V_11 -> V_41 . V_43 ;
V_40 -> V_41 . V_44 =
V_11 -> V_41 . V_44 ;
if ( V_11 -> V_41 . V_42 != 0 ||
V_11 -> V_41 . V_43 != 1 ) {
F_22 ( V_20 ,
L_6 ,
V_40 -> V_41 . V_45 [ 0 ] ,
V_11 -> V_41 . V_42 ,
V_11 -> V_41 . V_43 ) ;
}
if ( ( V_11 -> V_41 . V_42 & 0xFF ) == 0x02 ) {
if ( V_11 -> V_41 . V_43 & 0x80 ) {
F_22 ( V_20 , L_7
L_8 , V_10 ,
V_11 -> V_41 . V_44 ) ;
memcpy ( V_10 -> V_46 ,
V_11 -> V_41 . V_47 ,
V_11 -> V_41 . V_44 ) ;
}
}
V_40 -> V_41 . V_48 =
V_11 -> V_41 . V_48 ;
V_10 -> V_49 ( V_10 ) ;
if ( F_23 ( & V_4 -> V_50 ) &&
V_4 -> V_51 )
F_24 ( & V_4 -> V_7 ) ;
F_20 ( V_3 ) ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_11 * V_11 ,
struct V_9 * V_10 )
{
switch ( V_11 -> V_16 ) {
case V_27 :
F_21 ( V_3 , V_11 , V_10 ) ;
break;
case V_52 :
F_16 ( V_20 , L_9 ) ;
break;
default:
F_16 ( V_20 , L_10 ,
V_11 -> V_16 ) ;
break;
}
}
static void F_26 ( void * V_53 )
{
struct V_2 * V_3 = (struct V_2 * ) V_53 ;
struct V_1 * V_4 ;
T_1 V_54 ;
T_2 V_55 ;
unsigned char V_56 [ F_27 ( sizeof( struct V_11 ) , 8 ) ] ;
struct V_9 * V_10 ;
int V_12 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
do {
V_12 = F_28 ( V_3 -> V_21 , V_56 ,
F_27 ( sizeof( struct V_11 ) , 8 ) ,
& V_54 , & V_55 ) ;
if ( V_12 == 0 && V_54 > 0 ) {
V_10 = (struct V_9 * )
( unsigned long ) V_55 ;
if ( ( V_10 == & V_4 -> V_14 ) ||
( V_10 == & V_4 -> V_57 ) ) {
memcpy ( & V_10 -> V_11 , V_56 ,
sizeof( struct V_11 ) ) ;
F_29 ( & V_10 -> V_15 ) ;
} else {
F_25 ( V_3 ,
(struct V_11 * ) V_56 ,
V_10 ) ;
}
} else {
break;
}
} while ( 1 );
F_20 ( V_3 ) ;
return;
}
static int F_30 ( struct V_2 * V_3 , T_1 V_58 )
{
struct V_59 V_60 ;
int V_12 ;
memset ( & V_60 , 0 , sizeof( struct V_59 ) ) ;
V_12 = F_31 ( V_3 -> V_21 ,
V_58 ,
V_58 ,
( void * ) & V_60 ,
sizeof( struct V_59 ) ,
F_26 , V_3 ) ;
if ( V_12 != 0 )
return - 1 ;
V_12 = F_13 ( V_3 ) ;
return V_12 ;
}
int F_32 ( struct V_2 * V_3 ,
void * V_61 )
{
struct V_1 * V_4 ;
struct V_62 * V_63 ;
int V_12 = 0 ;
V_63 = (struct V_62 * ) V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_12 = - 1 ;
goto V_24;
}
V_4 -> V_36 = V_63 -> V_36 ;
V_12 = F_30 ( V_3 , V_63 -> V_64 ) ;
V_63 -> V_37 = V_4 -> V_37 ;
V_63 -> V_38 = V_4 -> V_38 ;
V_24:
return V_12 ;
}
int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_16 ( V_20 , L_11 ,
V_3 -> V_8 ) ;
V_4 = F_10 ( V_3 ) ;
F_34 ( V_4 ) ;
V_4 = F_12 ( V_3 ) ;
F_35 ( V_3 -> V_21 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
int F_36 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_1 * V_4 ;
struct V_11 * V_11 ;
int V_12 = 0 ;
V_11 = & V_10 -> V_11 ;
V_4 = F_14 ( V_3 ) ;
if ( ! V_4 )
return - 2 ;
V_10 -> V_3 = V_3 ;
V_11 -> V_18 |= V_19 ;
V_11 -> V_41 . V_65 = sizeof( struct V_66 ) ;
V_11 -> V_41 . V_44 = V_67 ;
V_11 -> V_41 . V_48 =
V_10 -> V_68 . V_69 ;
V_11 -> V_16 = V_70 ;
if ( V_10 -> V_68 . V_69 ) {
V_12 = F_37 ( V_3 -> V_21 ,
& V_10 -> V_68 ,
V_11 ,
sizeof( struct V_11 ) ,
( unsigned long ) V_10 ) ;
} else {
V_12 = F_17 ( V_3 -> V_21 , V_11 ,
sizeof( struct V_11 ) ,
( unsigned long ) V_10 ,
V_22 ,
V_23 ) ;
}
if ( V_12 != 0 )
return V_12 ;
F_9 ( & V_4 -> V_50 ) ;
F_20 ( V_3 ) ;
return V_12 ;
}
int F_38 ( struct V_62 * V_63 ,
struct V_71 * V_72 )
{
static bool V_73 ;
static bool V_74 ;
V_72 -> V_75 = L_12 ;
V_72 -> V_76 = L_13 ;
if ( V_63 -> V_37 ) {
V_72 -> V_77 = 22 ;
if ( ! V_74 ) {
V_72 -> V_78 = true ;
V_74 = true ;
} else
V_72 -> V_78 = false ;
if ( V_63 -> V_38 )
V_72 -> V_79 = 3 ;
else
V_72 -> V_79 = 2 ;
return 0 ;
} else {
V_72 -> V_77 = 3 ;
if ( ! V_73 ) {
V_72 -> V_78 = true ;
V_73 = true ;
} else
V_72 -> V_78 = false ;
if ( V_63 -> V_38 )
V_72 -> V_79 = 1 ;
else
V_72 -> V_79 = 0 ;
return 0 ;
}
return - V_80 ;
}
