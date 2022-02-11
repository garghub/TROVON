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
int F_9 ( struct V_1 * V_2 , const T_1 * V_14 )
{
struct V_5 * V_6 ;
int V_9 ;
V_6 = F_2 ( V_2 , 0xfc31 , 6 , V_14 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_4 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
F_6 ( V_6 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , bool V_18 )
{
struct V_5 * V_6 ;
T_2 V_19 [ 3 ] ;
int V_9 ;
if ( V_18 ) {
V_19 [ 0 ] = 0x03 ;
V_19 [ 1 ] = 0x03 ;
V_19 [ 2 ] = 0x03 ;
} else {
V_19 [ 0 ] = 0x00 ;
V_19 [ 1 ] = 0x00 ;
V_19 [ 2 ] = 0x00 ;
}
V_6 = F_2 ( V_2 , 0xfc43 , 3 , V_19 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
if ( V_9 == - V_20 )
goto V_21;
F_5 ( L_5 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
F_6 ( V_6 ) ;
V_21:
F_11 ( V_2 , V_18 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , bool V_18 )
{
struct V_5 * V_6 ;
T_2 V_19 [ 2 ] ;
int V_9 ;
V_19 [ 0 ] = 0x01 ;
V_19 [ 1 ] = 0x00 ;
V_6 = F_2 ( V_2 , 0xfc11 , 2 , V_19 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_6 ,
V_2 -> V_10 , V_9 ) ;
return F_4 ( V_6 ) ;
}
F_6 ( V_6 ) ;
V_9 = F_10 ( V_2 , V_18 ) ;
V_19 [ 0 ] = 0x00 ;
V_19 [ 1 ] = 0x00 ;
V_6 = F_2 ( V_2 , 0xfc11 , 2 , V_19 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_7 ,
V_2 -> V_10 , V_9 ) ;
return F_4 ( V_6 ) ;
}
F_6 ( V_6 ) ;
return V_9 ;
}
void F_13 ( struct V_1 * V_2 , T_2 V_22 )
{
struct V_5 * V_6 ;
T_2 type = 0x00 ;
F_5 ( L_8 , V_2 -> V_10 , V_22 ) ;
V_6 = F_2 ( V_2 , V_23 , 0 , NULL , V_8 ) ;
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
void F_14 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
const char * V_26 ;
switch ( V_25 -> V_27 ) {
case 0x06 :
V_26 = L_13 ;
break;
case 0x23 :
V_26 = L_14 ;
break;
default:
return;
}
F_15 ( L_15 , V_2 -> V_10 ,
V_26 , V_25 -> V_28 >> 4 , V_25 -> V_28 & 0x0f ,
V_25 -> V_29 , V_25 -> V_30 , 2000 + V_25 -> V_31 ) ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_32 , T_3 V_33 ,
const void * V_19 )
{
while ( V_33 > 0 ) {
struct V_5 * V_6 ;
T_2 V_34 [ 253 ] , V_35 = ( V_33 > 252 ) ? 252 : V_33 ;
V_34 [ 0 ] = V_32 ;
memcpy ( V_34 + 1 , V_19 , V_35 ) ;
V_6 = F_2 ( V_2 , 0xfc09 , V_35 + 1 ,
V_34 , V_8 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
F_6 ( V_6 ) ;
V_33 -= V_35 ;
V_19 += V_35 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 , const char * V_36 )
{
const struct V_37 * V_38 ;
struct V_5 * V_6 ;
const T_2 * V_39 ;
int V_9 ;
V_9 = F_18 ( & V_38 , V_36 , & V_2 -> V_40 ) ;
if ( V_9 < 0 ) {
F_19 ( V_2 , L_16 ,
V_36 , V_9 ) ;
return V_9 ;
}
F_20 ( V_2 , L_17 , V_36 ) ;
V_39 = V_38 -> V_13 ;
while ( V_38 -> V_41 > V_39 - V_38 -> V_13 ) {
T_2 V_42 = V_39 [ 0 ] + sizeof( T_2 ) ;
V_6 = F_2 ( V_2 , 0xfc8b , V_42 , V_39 ,
V_8 ) ;
if ( F_3 ( V_6 ) ) {
F_19 ( V_2 , L_18 ,
F_4 ( V_6 ) ) ;
F_21 ( V_38 ) ;
return F_4 ( V_6 ) ;
}
V_39 += V_42 ;
F_6 ( V_6 ) ;
}
F_21 ( V_38 ) ;
F_20 ( V_2 , L_19 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , bool V_43 )
{
T_2 V_44 [ 8 ] = { 0x87 , 0x0c , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
struct V_5 * V_6 ;
int V_9 ;
if ( V_43 )
V_44 [ 1 ] |= 0x62 ;
V_6 = F_2 ( V_2 , 0xfc52 , 8 , V_44 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_20 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
F_6 ( V_6 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , bool V_43 )
{
struct V_5 * V_6 ;
T_2 V_19 [ 2 ] ;
int V_9 ;
V_19 [ 0 ] = 0x01 ;
V_19 [ 1 ] = 0x00 ;
V_6 = F_2 ( V_2 , 0xfc11 , 2 , V_19 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_6 ,
V_2 -> V_10 , V_9 ) ;
return F_4 ( V_6 ) ;
}
F_6 ( V_6 ) ;
V_9 = F_11 ( V_2 , V_43 ) ;
V_19 [ 0 ] = 0x00 ;
V_19 [ 1 ] = 0x00 ;
V_6 = F_2 ( V_2 , 0xfc11 , 2 , V_19 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_7 ,
V_2 -> V_10 , V_9 ) ;
return F_4 ( V_6 ) ;
}
F_6 ( V_6 ) ;
return V_9 ;
}
static int F_23 ( void * V_45 , const void * V_46 , T_4 V_47 ,
void * V_48 , T_4 V_49 )
{
struct V_50 * V_51 = V_45 ;
struct V_52 V_53 ;
struct V_54 * V_55 ;
struct V_5 * V_6 ;
int V_9 = 0 ;
if ( V_47 != sizeof( V_56 ) )
return - V_57 ;
switch ( V_49 ) {
case 1 :
V_53 . V_58 = V_59 ;
break;
case 2 :
V_53 . V_58 = V_60 ;
break;
case 4 :
V_53 . V_58 = V_61 ;
break;
default:
return - V_57 ;
}
V_53 . V_46 = * ( V_56 * ) V_46 ;
V_53 . V_11 = V_49 ;
F_24 ( V_51 -> V_2 , L_21 , F_25 ( V_53 . V_46 ) ) ;
V_6 = F_26 ( V_51 -> V_2 , V_51 -> V_62 , sizeof( V_53 ) , & V_53 ,
V_63 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_19 ( V_51 -> V_2 , L_22 ,
F_25 ( V_53 . V_46 ) , V_9 ) ;
return V_9 ;
}
if ( V_6 -> V_11 != sizeof( * V_55 ) + V_49 ) {
F_19 ( V_51 -> V_2 , L_23 ,
F_25 ( V_53 . V_46 ) ) ;
V_9 = - V_57 ;
goto V_21;
}
V_55 = (struct V_54 * ) V_6 -> V_13 ;
if ( V_55 -> V_46 != V_53 . V_46 ) {
F_19 ( V_51 -> V_2 , L_24 ,
F_25 ( V_55 -> V_46 ) ) ;
V_9 = - V_57 ;
goto V_21;
}
memcpy ( V_48 , V_55 -> V_13 , V_49 ) ;
V_21:
F_6 ( V_6 ) ;
return V_9 ;
}
static int F_27 ( void * V_45 ,
const void * V_46 , T_4 V_47 ,
const void * V_48 , T_4 V_49 )
{
struct V_50 * V_51 = V_45 ;
struct V_52 * V_53 ;
struct V_5 * V_6 ;
int V_33 = sizeof( * V_53 ) + V_49 ;
T_2 V_58 ;
int V_9 = 0 ;
if ( V_47 != sizeof( V_56 ) )
return - V_57 ;
switch ( V_49 ) {
case 1 :
V_58 = V_59 ;
break;
case 2 :
V_58 = V_60 ;
break;
case 4 :
V_58 = V_61 ;
break;
default:
return - V_57 ;
}
V_53 = F_28 ( V_33 , V_64 ) ;
if ( ! V_53 )
return - V_65 ;
V_53 -> V_46 = * ( V_56 * ) V_46 ;
V_53 -> V_58 = V_58 ;
V_53 -> V_11 = V_49 ;
memcpy ( & V_53 -> V_13 , V_48 , V_49 ) ;
F_24 ( V_51 -> V_2 , L_25 , F_25 ( V_53 -> V_46 ) ) ;
V_6 = F_26 ( V_51 -> V_2 , V_51 -> V_66 , V_33 , V_53 , V_63 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_19 ( V_51 -> V_2 , L_26 ,
F_25 ( V_53 -> V_46 ) , V_9 ) ;
goto V_21;
}
F_6 ( V_6 ) ;
V_21:
F_29 ( V_53 ) ;
return V_9 ;
}
static int F_30 ( void * V_45 , const void * V_13 , T_4 V_67 )
{
if ( F_31 ( V_67 < 4 , L_27 ) )
return - V_57 ;
return F_27 ( V_45 , V_13 , 4 , V_13 + 4 , V_67 - 4 ) ;
}
static void F_32 ( void * V_45 )
{
F_29 ( V_45 ) ;
}
struct V_68 * F_33 ( struct V_1 * V_2 , T_5 V_69 ,
T_5 V_70 )
{
struct V_50 * V_51 ;
F_20 ( V_2 , L_28 , V_69 ,
V_70 ) ;
V_51 = F_34 ( sizeof( * V_51 ) , V_64 ) ;
if ( ! V_51 )
return F_35 ( - V_65 ) ;
V_51 -> V_62 = V_69 ;
V_51 -> V_66 = V_70 ;
V_51 -> V_2 = V_2 ;
return F_36 ( & V_2 -> V_40 , & V_71 , V_51 , & V_72 ) ;
}
