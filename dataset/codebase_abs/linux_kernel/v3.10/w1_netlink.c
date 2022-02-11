void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_5 [ sizeof( struct V_6 ) + sizeof( struct V_3 ) ] ;
struct V_6 * V_7 = (struct V_6 * ) V_5 ;
struct V_3 * V_8 = (struct V_3 * ) ( V_7 + 1 ) ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
V_7 -> V_9 . V_10 = V_11 ;
V_7 -> V_9 . V_12 = V_13 ;
V_7 -> V_14 = V_2 -> V_14 ++ ;
V_7 -> V_15 = sizeof( struct V_3 ) ;
memcpy ( V_8 , V_4 , sizeof( struct V_3 ) ) ;
F_2 ( V_7 , 0 , V_16 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_6 * V_4 = V_2 -> V_18 ;
struct V_3 * V_19 = (struct V_3 * ) ( V_4 + 1 ) ;
struct V_20 * V_21 = (struct V_20 * ) ( V_19 + 1 ) ;
int V_22 ;
F_4 ( V_2 , V_17 ) ;
V_22 = V_2 -> V_23 - V_21 -> V_15 ;
if ( V_22 > 8 ) {
T_1 * V_24 = ( void * ) ( V_21 + 1 ) + V_21 -> V_15 ;
* V_24 = V_17 ;
V_21 -> V_15 += 8 ;
V_19 -> V_15 += 8 ;
V_4 -> V_15 += 8 ;
return;
}
V_4 -> V_25 ++ ;
F_2 ( V_4 , 0 , V_16 ) ;
V_4 -> V_15 = sizeof( struct V_3 ) + sizeof( struct V_20 ) ;
V_19 -> V_15 = sizeof( struct V_20 ) ;
V_21 -> V_15 = 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_6 * V_4 ,
unsigned int V_22 )
{
struct V_3 * V_19 = (struct V_3 * ) ( V_4 + 1 ) ;
struct V_20 * V_21 = (struct V_20 * ) ( V_19 + 1 ) ;
int V_26 = ( V_21 -> V_21 == V_27 ) ? V_28 : V_29 ;
V_2 -> V_18 = V_4 ;
V_2 -> V_23 = V_22 ;
F_6 ( V_2 , V_26 , F_3 ) ;
V_4 -> V_25 = 0 ;
F_2 ( V_4 , 0 , V_16 ) ;
V_2 -> V_18 = NULL ;
V_2 -> V_23 = 0 ;
return 0 ;
}
static int F_7 ( struct V_6 * V_4 , struct V_3 * V_19 ,
struct V_20 * V_21 )
{
void * V_24 ;
struct V_3 * V_30 ;
struct V_20 * V_31 ;
struct V_6 * V_32 ;
int V_33 ;
V_24 = F_8 ( sizeof( struct V_6 ) +
sizeof( struct V_3 ) +
sizeof( struct V_20 ) +
V_21 -> V_15 , V_16 ) ;
if ( ! V_24 )
return - V_34 ;
V_32 = (struct V_6 * ) ( V_24 ) ;
V_30 = (struct V_3 * ) ( V_32 + 1 ) ;
V_31 = (struct V_20 * ) ( V_30 + 1 ) ;
memcpy ( V_32 , V_4 , sizeof( struct V_6 ) ) ;
memcpy ( V_30 , V_19 , sizeof( struct V_3 ) ) ;
memcpy ( V_31 , V_21 , sizeof( struct V_20 ) ) ;
V_32 -> V_25 = V_4 -> V_14 + 1 ;
V_32 -> V_15 = sizeof( struct V_3 ) +
sizeof( struct V_20 ) + V_21 -> V_15 ;
V_30 -> V_15 = sizeof( struct V_20 ) + V_21 -> V_15 ;
memcpy ( V_31 -> V_24 , V_21 -> V_24 , V_31 -> V_15 ) ;
V_33 = F_2 ( V_32 , 0 , V_16 ) ;
F_9 ( V_24 ) ;
return V_33 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_6 * V_4 ,
struct V_3 * V_19 , struct V_20 * V_21 )
{
int V_33 = 0 ;
switch ( V_21 -> V_21 ) {
case V_35 :
F_11 ( V_2 , V_21 -> V_24 , V_21 -> V_15 ) ;
F_7 ( V_4 , V_19 , V_21 ) ;
break;
case V_36 :
F_12 ( V_2 , V_21 -> V_24 , V_21 -> V_15 ) ;
F_7 ( V_4 , V_19 , V_21 ) ;
break;
case V_37 :
F_13 ( V_2 , V_21 -> V_24 , V_21 -> V_15 ) ;
break;
default:
V_33 = - V_38 ;
break;
}
return V_33 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_6 * V_39 ,
struct V_3 * V_40 , struct V_20 * V_41 )
{
int V_33 = - V_38 ;
struct V_6 * V_4 ;
struct V_3 * V_19 ;
struct V_20 * V_21 ;
V_4 = F_8 ( V_42 , V_16 ) ;
if ( ! V_4 )
return - V_34 ;
V_4 -> V_9 = V_39 -> V_9 ;
V_4 -> V_14 = V_39 -> V_14 ;
V_4 -> V_25 = 0 ;
V_4 -> V_15 = sizeof( struct V_3 ) + sizeof( struct V_20 ) ;
V_19 = (struct V_3 * ) ( V_4 + 1 ) ;
V_21 = (struct V_20 * ) ( V_19 + 1 ) ;
V_19 -> type = V_43 ;
V_19 -> V_9 = V_40 -> V_9 ;
V_19 -> V_15 = sizeof( struct V_20 ) ;
V_21 -> V_21 = V_41 -> V_21 ;
V_21 -> V_15 = 0 ;
switch ( V_21 -> V_21 ) {
case V_44 :
case V_27 :
V_33 = F_5 ( V_2 , V_4 ,
V_42 - V_4 -> V_15 - sizeof( struct V_6 ) ) ;
break;
case V_36 :
case V_37 :
case V_35 :
V_33 = F_10 ( V_2 , V_39 , V_40 , V_41 ) ;
break;
case V_45 :
V_33 = F_15 ( V_2 ) ;
break;
default:
V_33 = - V_38 ;
break;
}
F_9 ( V_4 ) ;
return V_33 ;
}
static int F_16 ( struct V_46 * V_47 , struct V_6 * V_4 ,
struct V_3 * V_19 , struct V_20 * V_21 )
{
F_17 ( & V_47 -> V_48 -> V_2 , L_1 ,
V_49 , V_47 -> V_50 . V_51 , ( unsigned long long ) V_47 -> V_50 . V_9 ,
V_47 -> V_50 . V_52 , V_21 -> V_21 , V_21 -> V_15 ) ;
return F_10 ( V_47 -> V_48 , V_4 , V_19 , V_21 ) ;
}
static int F_18 ( struct V_6 * V_4 , struct V_3 * V_53 )
{
struct V_1 * V_7 ;
struct V_6 * V_54 ;
struct V_3 * V_8 ;
T_2 * V_9 ;
if ( V_53 -> type != V_55 ) {
F_19 ( V_56 L_2 ,
V_49 , V_4 -> V_9 . V_10 , V_4 -> V_9 . V_12 , V_53 -> type , V_53 -> V_15 ) ;
return - V_57 ;
}
V_54 = F_20 ( V_42 , V_16 ) ;
if ( ! V_54 )
return - V_34 ;
V_54 -> V_9 . V_10 = V_11 ;
V_54 -> V_9 . V_12 = V_13 ;
V_54 -> V_14 = V_4 -> V_14 ;
V_54 -> V_25 = 1 ;
V_54 -> V_15 = sizeof( struct V_3 ) ;
V_8 = (struct V_3 * ) ( V_54 + 1 ) ;
V_8 -> type = V_55 ;
V_8 -> V_58 = 0 ;
V_8 -> V_15 = 0 ;
V_9 = ( T_2 * ) ( V_8 + 1 ) ;
F_21 ( & V_59 ) ;
F_22 (m, &w1_masters, w1_master_entry) {
if ( V_54 -> V_15 + sizeof( * V_9 ) > V_42 - sizeof( struct V_6 ) ) {
F_2 ( V_54 , 0 , V_16 ) ;
V_54 -> V_25 ++ ;
V_54 -> V_15 = sizeof( struct V_3 ) ;
V_8 -> V_15 = 0 ;
V_9 = ( T_2 * ) ( V_8 + 1 ) ;
}
* V_9 = V_7 -> V_9 ;
V_8 -> V_15 += sizeof( * V_9 ) ;
V_54 -> V_15 += sizeof( * V_9 ) ;
V_9 ++ ;
}
V_54 -> V_25 = 0 ;
F_2 ( V_54 , 0 , V_16 ) ;
F_23 ( & V_59 ) ;
F_9 ( V_54 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_60 , struct V_3 * V_61 ,
struct V_20 * V_62 , int error )
{
struct V_6 * V_63 ;
struct V_3 * V_4 ;
struct V_20 * V_21 ;
V_63 = F_8 ( sizeof( * V_4 ) + sizeof( * V_21 ) + sizeof( * V_63 ) , V_16 ) ;
if ( ! V_63 )
return - V_34 ;
V_4 = (struct V_3 * ) ( V_63 + 1 ) ;
V_21 = (struct V_20 * ) ( V_4 + 1 ) ;
memcpy ( V_63 , V_60 , sizeof( * V_63 ) ) ;
V_63 -> V_15 = sizeof( * V_4 ) ;
memcpy ( V_4 , V_61 , sizeof( * V_4 ) ) ;
V_4 -> V_15 = 0 ;
V_4 -> V_58 = ( short ) - error ;
if ( V_62 ) {
memcpy ( V_21 , V_62 , sizeof( * V_21 ) ) ;
V_21 -> V_15 = 0 ;
V_4 -> V_15 += sizeof( * V_21 ) ;
V_63 -> V_15 += sizeof( * V_21 ) ;
}
error = F_2 ( V_63 , 0 , V_16 ) ;
F_9 ( V_63 ) ;
return error ;
}
static void F_25 ( struct V_6 * V_4 , struct V_64 * V_65 )
{
struct V_3 * V_7 = (struct V_3 * ) ( V_4 + 1 ) ;
struct V_20 * V_21 ;
struct V_46 * V_47 ;
struct V_1 * V_2 ;
int V_33 = 0 ;
while ( V_4 -> V_15 && ! V_33 ) {
struct V_66 V_9 ;
T_3 V_67 = V_7 -> V_15 ;
T_4 * V_68 = V_7 -> V_24 ;
V_2 = NULL ;
V_47 = NULL ;
V_21 = NULL ;
memcpy ( & V_9 , V_7 -> V_9 . V_9 , sizeof( V_9 ) ) ;
#if 0
printk("%s: %02x.%012llx.%02x: type=%02x, len=%u.\n",
__func__, id.family, (unsigned long long)id.id, id.crc, m->type, m->len);
#endif
if ( V_7 -> V_15 + sizeof( struct V_3 ) > V_4 -> V_15 ) {
V_33 = - V_69 ;
break;
}
if ( V_7 -> type == V_43 ) {
V_2 = F_26 ( V_7 -> V_9 . V_70 . V_9 ) ;
} else if ( V_7 -> type == V_71 ) {
V_47 = F_27 ( & V_9 ) ;
if ( V_47 )
V_2 = V_47 -> V_48 ;
} else {
V_33 = F_18 ( V_4 , V_7 ) ;
goto V_72;
}
if ( ! V_2 ) {
V_33 = - V_73 ;
goto V_72;
}
V_33 = 0 ;
if ( ! V_67 )
goto V_72;
F_21 ( & V_2 -> V_74 ) ;
if ( V_47 && F_28 ( V_47 ) ) {
V_33 = - V_73 ;
goto V_75;
}
while ( V_67 ) {
V_21 = (struct V_20 * ) V_68 ;
if ( V_21 -> V_15 + sizeof( struct V_20 ) > V_67 ) {
V_33 = - V_69 ;
break;
}
if ( V_47 )
V_33 = F_16 ( V_47 , V_4 , V_7 , V_21 ) ;
else
V_33 = F_14 ( V_2 , V_4 , V_7 , V_21 ) ;
F_24 ( V_4 , V_7 , V_21 , V_33 ) ;
V_33 = 0 ;
V_68 += V_21 -> V_15 + sizeof( struct V_20 ) ;
V_67 -= V_21 -> V_15 + sizeof( struct V_20 ) ;
}
V_75:
F_29 ( & V_2 -> V_76 ) ;
if ( V_47 )
F_29 ( & V_47 -> V_76 ) ;
F_23 ( & V_2 -> V_74 ) ;
V_72:
if ( ! V_21 || V_33 )
F_24 ( V_4 , V_7 , V_21 , V_33 ) ;
V_4 -> V_15 -= sizeof( struct V_3 ) + V_7 -> V_15 ;
V_7 = (struct V_3 * ) ( ( ( T_4 * ) V_7 ) + sizeof( struct V_3 ) + V_7 -> V_15 ) ;
if ( V_33 == - V_73 )
V_33 = 0 ;
}
}
int F_30 ( void )
{
struct V_77 V_78 = { . V_10 = V_11 , . V_12 = V_13 } ;
return F_31 ( & V_78 , L_3 , & F_25 ) ;
}
void F_32 ( void )
{
struct V_77 V_78 = { . V_10 = V_11 , . V_12 = V_13 } ;
F_33 ( & V_78 ) ;
}
void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
}
int F_30 ( void )
{
return 0 ;
}
void F_32 ( void )
{
}
