static inline void F_1 ( void T_1 * V_1 , const void * V_2 , int V_3 )
{
F_2 ( V_1 , V_2 , V_3 / 4 ) ;
}
int F_3 ( struct V_4 * V_5 )
{
union V_6 V_7 ;
F_4 ( V_5 -> V_8 , L_1 ) ;
V_7 . V_9 = F_5 ( V_5 -> V_10 , V_11 ) ;
F_4 ( V_5 -> V_8 , L_2 , V_7 . V_9 ) ;
V_7 . V_9 |= 0x7 ;
F_6 ( V_5 -> V_10 , V_11 , V_7 . V_9 ) ;
V_7 . V_9 = F_5 ( V_5 -> V_10 , V_11 ) ;
F_4 ( V_5 -> V_8 , L_2 , V_7 . V_9 ) ;
V_7 . V_9 &= ~ ( 0x1 ) ;
F_6 ( V_5 -> V_10 , V_11 , V_7 . V_9 ) ;
V_7 . V_9 = F_5 ( V_5 -> V_10 , V_11 ) ;
F_4 ( V_5 -> V_8 , L_2 , V_7 . V_9 ) ;
return 0 ;
}
int F_7 ( struct V_4 * V_5 )
{
union V_6 V_7 ;
F_4 ( V_5 -> V_8 , L_3 ) ;
V_7 . V_9 = F_5 ( V_5 -> V_10 , V_11 ) ;
F_4 ( V_5 -> V_8 , L_2 , V_7 . V_9 ) ;
V_7 . V_9 |= 0x7 ;
F_6 ( V_5 -> V_10 , V_11 , V_7 . V_9 ) ;
V_7 . V_9 = F_5 ( V_5 -> V_10 , V_11 ) ;
F_4 ( V_5 -> V_8 , L_2 , V_7 . V_9 ) ;
V_7 . V_12 . V_13 = 1 ;
V_7 . V_9 &= ~ ( 0x5 ) ;
F_6 ( V_5 -> V_10 , V_11 , V_7 . V_9 ) ;
V_7 . V_9 = F_5 ( V_5 -> V_10 , V_11 ) ;
F_4 ( V_5 -> V_8 , L_4 ,
V_7 . V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_4 * V_14 , unsigned long V_15 ,
struct V_16 * * V_17 , T_2 * V_18 )
{
struct V_19 * V_20 ;
const void * V_21 = V_14 -> V_22 ;
F_4 ( V_14 -> V_8 , L_5 ) ;
V_20 = (struct V_19 * ) V_21 ;
F_4 ( V_14 -> V_8 ,
L_6 ,
V_20 -> V_23 , V_20 -> V_24 , V_20 -> V_25 ,
V_20 -> V_26 , sizeof( * V_20 ) ) ;
if ( ( strncmp ( V_20 -> V_23 , V_27 , 4 ) != 0 ) ||
( V_15 != V_20 -> V_24 + sizeof( * V_20 ) ) ) {
F_9 ( V_14 -> V_8 , L_7 ) ;
return - V_28 ;
}
* V_18 = V_20 -> V_25 ;
* V_17 = ( void * ) V_21 + sizeof( * V_20 ) ;
return 0 ;
}
static int F_10 ( struct V_29 * V_30 ,
void * V_31 , const void * V_2 , T_2 V_15 , bool V_32 )
{
struct V_33 * V_34 ;
V_34 = F_11 ( sizeof( * V_34 ) , V_35 ) ;
if ( V_34 == NULL )
return - V_36 ;
V_34 -> V_37 = V_31 ;
V_34 -> V_2 = V_2 ;
V_34 -> V_15 = V_15 ;
V_34 -> V_32 = V_32 ;
F_12 ( & V_34 -> V_38 , V_30 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_16 * V_17 , struct V_29 * V_30 )
{
struct V_39 * V_40 ;
T_2 V_3 ;
int V_41 = 0 ;
void T_1 * V_42 ;
F_4 ( V_5 -> V_8 , L_8 ,
V_17 -> V_23 , V_17 -> V_43 ,
V_17 -> V_44 , V_17 -> type ) ;
F_4 ( V_5 -> V_8 , L_9 , V_17 -> V_45 ) ;
V_40 = ( void * ) V_17 + sizeof( * V_17 ) ;
for ( V_3 = 0 ; V_3 < V_17 -> V_44 ; V_3 ++ ) {
if ( V_40 -> V_15 <= 0 ) {
F_9 ( V_5 -> V_8 , L_10 ) ;
return - V_28 ;
}
switch ( V_40 -> type ) {
case V_46 :
V_42 = V_5 -> V_47 ;
break;
case V_48 :
V_42 = V_5 -> V_49 ;
break;
case V_50 :
V_42 = V_5 -> V_51 ;
break;
case V_52 :
V_40 = ( void * ) V_40 + sizeof( * V_40 ) + V_40 -> V_15 ;
continue;
default:
F_9 ( V_5 -> V_8 , L_11 ,
V_40 -> type , V_3 ) ;
return - V_28 ;
}
V_41 = F_10 ( V_30 ,
V_42 + V_40 -> V_53 ,
( void * ) V_40 + sizeof( * V_40 ) , V_40 -> V_15 , 1 ) ;
if ( V_41 )
return V_41 ;
V_40 = ( void * ) V_40 + sizeof( * V_40 ) + V_40 -> V_15 ;
}
return 0 ;
}
static int F_14 ( struct V_4 * V_14 , unsigned long V_15 ,
struct V_29 * V_54 )
{
struct V_16 * V_17 ;
T_2 V_3 , V_18 ;
int V_41 ;
V_41 = F_8 ( V_14 , V_15 , & V_17 , & V_18 ) ;
if ( V_41 )
return V_41 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_41 = F_13 ( V_14 , V_17 , V_54 ) ;
if ( V_41 )
return V_41 ;
V_17 = ( void * ) V_17 + sizeof( * V_17 ) + V_17 -> V_43 ;
}
return 0 ;
}
static void F_15 ( struct V_29 * V_30 )
{
struct V_33 * V_34 ;
F_16 (listnode, memcpy_list, memcpylist) {
if ( V_34 -> V_32 == true )
F_1 ( ( void T_1 * ) V_34 -> V_37 ,
V_34 -> V_2 , V_34 -> V_15 ) ;
else
memcpy ( V_34 -> V_37 , V_34 -> V_2 , V_34 -> V_15 ) ;
}
}
void F_17 ( struct V_4 * V_5 )
{
struct V_33 * V_34 , * V_55 ;
if ( ! F_18 ( & V_5 -> V_30 ) ) {
F_19 (listnode, tmplistnode,
&sst_drv_ctx->memcpy_list, memcpylist) {
F_20 ( & V_34 -> V_38 ) ;
F_21 ( V_34 ) ;
}
}
}
static int F_22 ( struct V_4 * V_56 ,
const struct V_57 * V_58 )
{
int V_59 = 0 ;
V_56 -> V_22 = F_11 ( V_58 -> V_15 , V_35 ) ;
if ( ! V_56 -> V_22 ) {
V_59 = - V_36 ;
goto V_60;
}
F_4 ( V_56 -> V_8 , L_12 , V_56 -> V_22 ) ;
F_4 ( V_56 -> V_8 , L_13 , ( unsigned long ) F_23 ( V_56 -> V_22 ) ) ;
memcpy ( V_56 -> V_22 , V_58 -> V_61 , V_58 -> V_15 ) ;
V_59 = F_14 ( V_56 , V_58 -> V_15 , & V_56 -> V_30 ) ;
if ( V_59 ) {
F_9 ( V_56 -> V_8 , L_14 ) ;
F_21 ( V_56 -> V_22 ) ;
V_56 -> V_22 = NULL ;
}
V_60:
F_24 ( V_58 ) ;
return V_59 ;
}
void F_25 ( const struct V_57 * V_58 , void * V_62 )
{
struct V_4 * V_14 = V_62 ;
F_4 ( V_14 -> V_8 , L_5 ) ;
if ( V_58 == NULL ) {
F_9 ( V_14 -> V_8 , L_15 ) ;
return;
}
F_26 ( & V_14 -> V_63 ) ;
if ( V_14 -> V_64 != V_65 ||
V_14 -> V_22 != NULL ) {
if ( V_58 != NULL )
F_24 ( V_58 ) ;
F_27 ( & V_14 -> V_63 ) ;
return;
}
F_4 ( V_14 -> V_8 , L_16 ) ;
F_22 ( V_14 , V_58 ) ;
F_27 ( & V_14 -> V_63 ) ;
}
static int F_28 ( struct V_4 * V_56 )
{
int V_59 = 0 ;
const struct V_57 * V_58 ;
V_59 = F_29 ( & V_58 , V_56 -> V_66 , V_56 -> V_8 ) ;
if ( V_58 == NULL ) {
F_9 ( V_56 -> V_8 , L_17 ) ;
return - V_28 ;
}
if ( V_59 ) {
F_9 ( V_56 -> V_8 , L_18 , V_59 ) ;
return V_59 ;
}
F_26 ( & V_56 -> V_63 ) ;
V_59 = F_22 ( V_56 , V_58 ) ;
F_27 ( & V_56 -> V_63 ) ;
return V_59 ;
}
static void F_30 ( void T_1 * V_67 ,
unsigned int V_68 )
{
void T_1 * V_69 ;
T_2 V_70 = 0 ;
V_69 = ( void T_1 * ) ( V_67 + V_71 ) ;
F_1 ( V_69 , ( void * ) & V_68 , sizeof( T_2 ) ) ;
V_70 |= ( 1 << V_72 ) ;
V_69 = ( void T_1 * ) ( V_67 + V_73 ) ;
F_1 ( V_69 , & V_70 , sizeof( T_2 ) ) ;
}
void F_31 ( struct V_4 * V_14 )
{
F_30 ( V_14 -> V_49 , V_14 -> V_68 ) ;
F_4 ( V_14 -> V_8 , L_19 ) ;
}
int F_32 ( struct V_4 * V_5 )
{
int V_41 = 0 ;
struct V_74 * V_40 ;
F_4 ( V_5 -> V_8 , L_20 ) ;
if ( V_5 -> V_64 != V_65 ||
V_5 -> V_64 == V_75 )
return - V_76 ;
if ( ! V_5 -> V_22 ) {
F_4 ( V_5 -> V_8 , L_21 ) ;
V_41 = F_28 ( V_5 ) ;
if ( V_41 )
return V_41 ;
}
F_33 ( ! V_5 -> V_22 ) ;
V_40 = F_34 ( V_5 , 0 , V_77 ) ;
if ( V_40 == NULL )
return - V_36 ;
F_35 ( V_5 -> V_78 , 0 ) ;
V_5 -> V_64 = V_79 ;
V_41 = V_5 -> V_80 -> V_81 ( V_5 ) ;
if ( V_41 )
goto V_82;
F_15 ( & V_5 -> V_30 ) ;
if ( V_5 -> V_80 -> V_83 )
V_5 -> V_80 -> V_83 ( V_5 ) ;
V_41 = V_5 -> V_80 -> V_84 ( V_5 ) ;
if ( V_41 )
goto V_82;
V_41 = F_36 ( V_5 , V_40 ) ;
if ( V_41 ) {
F_9 ( V_5 -> V_8 , L_22 , V_41 ) ;
V_41 = - V_85 ;
}
V_82:
F_35 ( V_5 -> V_78 , V_86 ) ;
F_37 ( V_5 , V_40 ) ;
F_4 ( V_5 -> V_8 , L_23 ) ;
if ( V_5 -> V_80 -> V_87 )
V_5 -> V_80 -> V_87 () ;
V_5 -> V_64 = V_88 ;
return V_41 ;
}
