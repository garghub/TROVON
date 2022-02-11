int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , V_7 , 0 , NULL ,
V_8 ) ;
if ( F_3 ( V_6 ) ) {
int V_9 = F_4 ( V_6 ) ;
F_5 ( L_1 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
if ( V_6 -> V_11 != sizeof( * V_4 ) ) {
F_5 ( L_2 , V_2 -> V_10 ) ;
F_6 ( V_6 ) ;
return - V_12 ;
}
V_4 = (struct V_3 * ) V_6 -> V_13 ;
if ( ! F_7 ( & V_4 -> V_14 , V_15 ) ) {
F_5 ( L_3 ,
V_2 -> V_10 , & V_4 -> V_14 ) ;
F_8 ( V_16 , & V_2 -> V_17 ) ;
}
F_6 ( V_6 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
const T_1 V_18 [] = { 0x01 , 0x00 } ;
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , 0xfc11 , 2 , V_18 , V_19 ) ;
if ( F_3 ( V_6 ) ) {
F_10 ( V_2 , L_4 ,
F_4 ( V_6 ) ) ;
return F_4 ( V_6 ) ;
}
F_6 ( V_6 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , bool V_20 , bool V_21 )
{
T_1 V_18 [] = { 0x00 , 0x00 } ;
struct V_5 * V_6 ;
if ( V_20 )
V_18 [ 1 ] |= V_21 ? 0x02 : 0x01 ;
V_6 = F_2 ( V_2 , 0xfc11 , 2 , V_18 , V_19 ) ;
if ( F_3 ( V_6 ) ) {
F_10 ( V_2 , L_5 ,
F_4 ( V_6 ) ) ;
return F_4 ( V_6 ) ;
}
F_6 ( V_6 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , const T_2 * V_14 )
{
struct V_5 * V_6 ;
int V_9 ;
V_6 = F_2 ( V_2 , 0xfc31 , 6 , V_14 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_6 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
F_6 ( V_6 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 , bool V_22 )
{
struct V_5 * V_6 ;
T_1 V_18 [ 3 ] ;
int V_9 ;
if ( V_22 ) {
V_18 [ 0 ] = 0x03 ;
V_18 [ 1 ] = 0x03 ;
V_18 [ 2 ] = 0x03 ;
} else {
V_18 [ 0 ] = 0x00 ;
V_18 [ 1 ] = 0x00 ;
V_18 [ 2 ] = 0x00 ;
}
V_6 = F_2 ( V_2 , 0xfc43 , 3 , V_18 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
if ( V_9 == - V_23 )
goto V_24;
F_5 ( L_7 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
F_6 ( V_6 ) ;
V_24:
F_14 ( V_2 , V_22 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , bool V_22 )
{
int V_9 , V_25 ;
V_9 = F_9 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_25 = F_13 ( V_2 , V_22 ) ;
V_9 = F_11 ( V_2 , false , false ) ;
if ( V_9 )
return V_9 ;
return V_25 ;
}
void F_16 ( struct V_1 * V_2 , T_1 V_26 )
{
struct V_5 * V_6 ;
T_1 type = 0x00 ;
F_5 ( L_8 , V_2 -> V_10 , V_26 ) ;
V_6 = F_2 ( V_2 , V_27 , 0 , NULL , V_8 ) ;
if ( F_3 ( V_6 ) ) {
F_5 ( L_9 ,
V_2 -> V_10 , F_4 ( V_6 ) ) ;
return;
}
F_6 ( V_6 ) ;
V_6 = F_2 ( V_2 , 0xfc22 , 1 , & type , V_8 ) ;
if ( F_3 ( V_6 ) ) {
F_5 ( L_10 ,
V_2 -> V_10 , F_4 ( V_6 ) ) ;
return;
}
if ( V_6 -> V_11 != 13 ) {
F_5 ( L_11 , V_2 -> V_10 ) ;
F_6 ( V_6 ) ;
return;
}
F_5 ( L_12 , V_2 -> V_10 , ( char * ) ( V_6 -> V_13 + 1 ) ) ;
F_6 ( V_6 ) ;
}
void F_17 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
const char * V_30 ;
switch ( V_29 -> V_31 ) {
case 0x06 :
V_30 = L_13 ;
break;
case 0x23 :
V_30 = L_14 ;
break;
default:
return;
}
F_18 ( L_15 , V_2 -> V_10 ,
V_30 , V_29 -> V_32 >> 4 , V_29 -> V_32 & 0x0f ,
V_29 -> V_33 , V_29 -> V_34 , 2000 + V_29 -> V_35 ) ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_36 , T_3 V_37 ,
const void * V_18 )
{
while ( V_37 > 0 ) {
struct V_5 * V_6 ;
T_1 V_38 [ 253 ] , V_39 = ( V_37 > 252 ) ? 252 : V_37 ;
V_38 [ 0 ] = V_36 ;
memcpy ( V_38 + 1 , V_18 , V_39 ) ;
V_6 = F_2 ( V_2 , 0xfc09 , V_39 + 1 ,
V_38 , V_8 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
F_6 ( V_6 ) ;
V_37 -= V_39 ;
V_18 += V_39 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 , const char * V_40 )
{
const struct V_41 * V_42 ;
struct V_5 * V_6 ;
const T_1 * V_43 ;
int V_9 ;
V_9 = F_21 ( & V_42 , V_40 , & V_2 -> V_44 ) ;
if ( V_9 < 0 ) {
F_10 ( V_2 , L_16 ,
V_40 , V_9 ) ;
return V_9 ;
}
F_22 ( V_2 , L_17 , V_40 ) ;
V_43 = V_42 -> V_13 ;
while ( V_42 -> V_45 > V_43 - V_42 -> V_13 ) {
T_1 V_46 = V_43 [ 0 ] + sizeof( T_1 ) ;
V_6 = F_2 ( V_2 , 0xfc8b , V_46 , V_43 ,
V_8 ) ;
if ( F_3 ( V_6 ) ) {
F_10 ( V_2 , L_18 ,
F_4 ( V_6 ) ) ;
F_23 ( V_42 ) ;
return F_4 ( V_6 ) ;
}
V_43 += V_46 ;
F_6 ( V_6 ) ;
}
F_23 ( V_42 ) ;
F_22 ( V_2 , L_19 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , bool V_47 )
{
T_1 V_48 [ 8 ] = { 0x87 , 0x0c , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
struct V_5 * V_6 ;
int V_9 ;
if ( V_47 )
V_48 [ 1 ] |= 0x62 ;
V_6 = F_2 ( V_2 , 0xfc52 , 8 , V_48 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_20 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
F_6 ( V_6 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , bool V_47 )
{
int V_9 , V_25 ;
V_9 = F_9 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_25 = F_14 ( V_2 , V_47 ) ;
V_9 = F_11 ( V_2 , false , false ) ;
if ( V_9 )
return V_9 ;
return V_25 ;
}
int F_25 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , 0xfc05 , 0 , NULL , V_19 ) ;
if ( F_3 ( V_6 ) ) {
F_10 ( V_2 , L_21 ,
F_4 ( V_6 ) ) ;
return F_4 ( V_6 ) ;
}
if ( V_6 -> V_11 != sizeof( * V_29 ) ) {
F_10 ( V_2 , L_22 ) ;
F_6 ( V_6 ) ;
return - V_49 ;
}
memcpy ( V_29 , V_6 -> V_13 , sizeof( * V_29 ) ) ;
F_6 ( V_6 ) ;
return 0 ;
}
static int F_26 ( void * V_50 , const void * V_51 , T_4 V_52 ,
void * V_53 , T_4 V_54 )
{
struct V_55 * V_56 = V_50 ;
struct V_57 V_58 ;
struct V_59 * V_60 ;
struct V_5 * V_6 ;
int V_9 = 0 ;
if ( V_52 != sizeof( V_61 ) )
return - V_62 ;
switch ( V_54 ) {
case 1 :
V_58 . V_63 = V_64 ;
break;
case 2 :
V_58 . V_63 = V_65 ;
break;
case 4 :
V_58 . V_63 = V_66 ;
break;
default:
return - V_62 ;
}
V_58 . V_51 = * ( V_61 * ) V_51 ;
V_58 . V_11 = V_54 ;
F_27 ( V_56 -> V_2 , L_23 , F_28 ( V_58 . V_51 ) ) ;
V_6 = F_29 ( V_56 -> V_2 , V_56 -> V_67 , sizeof( V_58 ) , & V_58 ,
V_19 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_10 ( V_56 -> V_2 , L_24 ,
F_28 ( V_58 . V_51 ) , V_9 ) ;
return V_9 ;
}
if ( V_6 -> V_11 != sizeof( * V_60 ) + V_54 ) {
F_10 ( V_56 -> V_2 , L_25 ,
F_28 ( V_58 . V_51 ) ) ;
V_9 = - V_62 ;
goto V_24;
}
V_60 = (struct V_59 * ) V_6 -> V_13 ;
if ( V_60 -> V_51 != V_58 . V_51 ) {
F_10 ( V_56 -> V_2 , L_26 ,
F_28 ( V_60 -> V_51 ) ) ;
V_9 = - V_62 ;
goto V_24;
}
memcpy ( V_53 , V_60 -> V_13 , V_54 ) ;
V_24:
F_6 ( V_6 ) ;
return V_9 ;
}
static int F_30 ( void * V_50 ,
const void * V_51 , T_4 V_52 ,
const void * V_53 , T_4 V_54 )
{
struct V_55 * V_56 = V_50 ;
struct V_57 * V_58 ;
struct V_5 * V_6 ;
int V_37 = sizeof( * V_58 ) + V_54 ;
T_1 V_63 ;
int V_9 = 0 ;
if ( V_52 != sizeof( V_61 ) )
return - V_62 ;
switch ( V_54 ) {
case 1 :
V_63 = V_64 ;
break;
case 2 :
V_63 = V_65 ;
break;
case 4 :
V_63 = V_66 ;
break;
default:
return - V_62 ;
}
V_58 = F_31 ( V_37 , V_68 ) ;
if ( ! V_58 )
return - V_69 ;
V_58 -> V_51 = * ( V_61 * ) V_51 ;
V_58 -> V_63 = V_63 ;
V_58 -> V_11 = V_54 ;
memcpy ( & V_58 -> V_13 , V_53 , V_54 ) ;
F_27 ( V_56 -> V_2 , L_27 , F_28 ( V_58 -> V_51 ) ) ;
V_6 = F_29 ( V_56 -> V_2 , V_56 -> V_70 , V_37 , V_58 , V_19 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_10 ( V_56 -> V_2 , L_28 ,
F_28 ( V_58 -> V_51 ) , V_9 ) ;
goto V_24;
}
F_6 ( V_6 ) ;
V_24:
F_32 ( V_58 ) ;
return V_9 ;
}
static int F_33 ( void * V_50 , const void * V_13 , T_4 V_71 )
{
if ( F_34 ( V_71 < 4 , L_29 ) )
return - V_62 ;
return F_30 ( V_50 , V_13 , 4 , V_13 + 4 , V_71 - 4 ) ;
}
static void F_35 ( void * V_50 )
{
F_32 ( V_50 ) ;
}
struct V_72 * F_36 ( struct V_1 * V_2 , T_5 V_73 ,
T_5 V_74 )
{
struct V_55 * V_56 ;
F_22 ( V_2 , L_30 , V_73 ,
V_74 ) ;
V_56 = F_37 ( sizeof( * V_56 ) , V_68 ) ;
if ( ! V_56 )
return F_38 ( - V_69 ) ;
V_56 -> V_67 = V_73 ;
V_56 -> V_70 = V_74 ;
V_56 -> V_2 = V_2 ;
return F_39 ( & V_2 -> V_44 , & V_75 , V_56 , & V_76 ) ;
}
