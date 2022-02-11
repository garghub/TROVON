static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
F_2 ( L_1 , V_6 -> V_8 ,
V_1 , V_1 -> V_9 , V_1 -> V_10 ) ;
if ( ! F_3 ( V_11 , & V_6 -> V_12 ) )
goto V_13;
if ( ! V_1 -> V_9 )
V_6 -> V_14 . V_15 += V_1 -> V_16 ;
else
V_6 -> V_14 . V_17 ++ ;
V_13:
F_4 ( V_1 -> V_18 ) ;
F_5 ( V_3 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_4 ;
struct V_19 * V_20 = F_7 ( V_6 ) ;
int V_21 ;
F_2 ( L_1 , V_6 -> V_8 ,
V_1 , V_1 -> V_9 , V_1 -> V_10 ) ;
if ( ! F_3 ( V_11 , & V_6 -> V_12 ) )
return;
if ( V_1 -> V_9 == 0 ) {
bool V_22 = F_8 ( V_1 -> V_23 ) ;
V_20 -> V_24 [ V_22 ] = F_9 ( V_6 , V_20 -> V_24 [ V_22 ] ,
V_1 -> V_25 ,
V_1 -> V_10 ,
V_26 ,
F_10 ( V_26 ) ) ;
if ( F_11 ( V_20 -> V_24 [ V_22 ] ) ) {
F_12 ( L_2 , V_6 -> V_8 ) ;
V_6 -> V_14 . V_27 ++ ;
V_20 -> V_24 [ V_22 ] = NULL ;
}
}
F_13 ( V_1 , & V_20 -> V_28 ) ;
V_21 = F_14 ( V_1 , V_29 ) ;
if ( V_21 < 0 ) {
F_12 ( L_3 ,
V_6 -> V_8 , V_1 , - V_21 ) ;
F_15 ( V_1 ) ;
}
}
static inline int F_16 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_7 ( V_6 ) ;
struct V_1 * V_1 ;
unsigned char * V_30 ;
unsigned int V_23 ;
int V_21 , V_31 = 16 ;
F_2 ( L_4 , V_6 -> V_8 ) ;
V_1 = F_17 ( 0 , V_32 ) ;
if ( ! V_1 )
return - V_33 ;
V_30 = F_18 ( V_31 , V_32 ) ;
if ( ! V_30 ) {
F_19 ( V_1 ) ;
return - V_33 ;
}
V_23 = F_20 ( V_20 -> V_34 , 0x81 ) ;
F_21 ( V_1 , V_20 -> V_34 , V_23 , V_30 , V_31 ,
F_6 , V_6 , 1 ) ;
V_1 -> V_35 |= V_36 ;
F_13 ( V_1 , & V_20 -> V_28 ) ;
V_21 = F_14 ( V_1 , V_32 ) ;
if ( V_21 < 0 ) {
F_12 ( L_5 ,
V_6 -> V_8 , V_1 , - V_21 ) ;
F_15 ( V_1 ) ;
}
F_19 ( V_1 ) ;
return V_21 ;
}
static inline int F_22 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_7 ( V_6 ) ;
struct V_1 * V_1 ;
unsigned char * V_30 ;
unsigned int V_23 ;
int V_21 , V_31 = 64 ;
F_2 ( L_4 , V_6 -> V_8 ) ;
V_1 = F_17 ( 0 , V_32 ) ;
if ( ! V_1 )
return - V_33 ;
V_30 = F_18 ( V_31 , V_32 ) ;
if ( ! V_30 ) {
F_19 ( V_1 ) ;
return - V_33 ;
}
V_23 = F_23 ( V_20 -> V_34 , 0x82 ) ;
F_24 ( V_1 , V_20 -> V_34 , V_23 ,
V_30 , V_31 , F_6 , V_6 ) ;
V_1 -> V_35 |= V_36 ;
F_13 ( V_1 , & V_20 -> V_28 ) ;
V_21 = F_14 ( V_1 , V_32 ) ;
if ( V_21 < 0 ) {
F_12 ( L_5 ,
V_6 -> V_8 , V_1 , - V_21 ) ;
F_15 ( V_1 ) ;
}
F_19 ( V_1 ) ;
return V_21 ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_7 ( V_6 ) ;
int V_21 ;
F_2 ( L_4 , V_6 -> V_8 ) ;
V_21 = F_16 ( V_6 ) ;
if ( V_21 < 0 )
goto error;
V_21 = F_22 ( V_6 ) ;
if ( V_21 < 0 )
goto error;
return 0 ;
error:
F_26 ( & V_20 -> V_28 ) ;
return V_21 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_7 ( V_6 ) ;
F_2 ( L_4 , V_6 -> V_8 ) ;
F_26 ( & V_20 -> V_28 ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_7 ( V_6 ) ;
F_2 ( L_4 , V_6 -> V_8 ) ;
F_26 ( & V_20 -> V_37 ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
const T_1 V_38 [] = { 0x07 } ;
struct V_2 * V_3 ;
F_2 ( L_4 , V_6 -> V_8 ) ;
V_3 = F_30 ( V_6 , 0xfc0e , sizeof( V_38 ) , V_38 , V_39 ) ;
if ( F_11 ( V_3 ) )
return F_31 ( V_3 ) ;
F_32 ( L_6 , V_6 -> V_8 , ( char * ) ( V_3 -> V_20 + 1 ) ) ;
F_33 ( V_6 , L_4 , V_3 -> V_20 + 1 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_19 * V_20 = F_7 ( V_6 ) ;
struct V_40 * V_41 ;
struct V_1 * V_1 ;
unsigned int V_23 ;
int V_21 ;
F_2 ( L_4 , V_6 -> V_8 ) ;
V_3 -> V_7 = ( void * ) V_6 ;
V_1 = F_17 ( 0 , V_29 ) ;
if ( ! V_1 )
return - V_33 ;
* ( T_1 * ) F_35 ( V_3 , 1 ) = F_36 ( V_3 ) ;
switch ( F_36 ( V_3 ) ) {
case V_42 :
V_41 = F_18 ( sizeof( * V_41 ) , V_29 ) ;
if ( ! V_41 ) {
F_19 ( V_1 ) ;
return - V_33 ;
}
V_41 -> V_43 = V_44 ;
V_41 -> V_45 = 0 ;
V_41 -> V_46 = 0 ;
V_41 -> V_47 = 0 ;
V_41 -> V_48 = F_37 ( V_3 -> V_49 ) ;
V_23 = F_38 ( V_20 -> V_34 , 0x00 ) ;
F_39 ( V_1 , V_20 -> V_34 , V_23 , ( void * ) V_41 ,
V_3 -> V_20 , V_3 -> V_49 , F_1 , V_3 ) ;
V_6 -> V_14 . V_50 ++ ;
break;
case V_51 :
V_23 = F_40 ( V_20 -> V_34 , 0x02 ) ;
F_24 ( V_1 , V_20 -> V_34 , V_23 ,
V_3 -> V_20 , V_3 -> V_49 , F_1 , V_3 ) ;
V_6 -> V_14 . V_52 ++ ;
break;
case V_53 :
V_23 = F_40 ( V_20 -> V_34 , 0x02 ) ;
F_24 ( V_1 , V_20 -> V_34 , V_23 ,
V_3 -> V_20 , V_3 -> V_49 , F_1 , V_3 ) ;
V_6 -> V_14 . V_54 ++ ;
break;
default:
F_19 ( V_1 ) ;
return - V_55 ;
}
F_13 ( V_1 , & V_20 -> V_37 ) ;
V_21 = F_14 ( V_1 , V_29 ) ;
if ( V_21 < 0 ) {
F_12 ( L_7 , V_6 -> V_8 , V_1 ) ;
F_4 ( V_1 -> V_18 ) ;
F_15 ( V_1 ) ;
}
F_19 ( V_1 ) ;
return 0 ;
}
static int F_41 ( struct V_5 * V_6 , bool V_56 )
{
const T_1 V_38 [] = { 0x00 , V_56 } ;
struct V_2 * V_3 ;
F_2 ( L_4 , V_6 -> V_8 ) ;
if ( ! F_3 ( V_11 , & V_6 -> V_12 ) )
return - V_57 ;
V_3 = F_30 ( V_6 , 0xfc0e , sizeof( V_38 ) , V_38 , V_39 ) ;
if ( F_11 ( V_3 ) )
return F_31 ( V_3 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
static int F_42 ( struct V_58 * V_59 , const struct V_60 * V_61 )
{
struct V_19 * V_20 ;
struct V_5 * V_6 ;
int V_21 ;
F_2 ( L_8 , V_59 , V_61 ) ;
if ( V_59 -> V_62 -> V_63 . V_64 != 0 )
return - V_65 ;
V_20 = F_43 ( & V_59 -> V_7 , sizeof( * V_20 ) , V_32 ) ;
if ( ! V_20 )
return - V_33 ;
V_20 -> V_34 = F_44 ( V_59 ) ;
F_45 ( & V_20 -> V_37 ) ;
F_45 ( & V_20 -> V_28 ) ;
V_6 = F_46 () ;
if ( ! V_6 )
return - V_33 ;
V_6 -> V_66 = V_67 ;
F_47 ( V_6 , V_20 ) ;
V_20 -> V_6 = V_6 ;
F_48 ( V_6 , & V_59 -> V_7 ) ;
V_6 -> V_68 = F_25 ;
V_6 -> V_69 = F_27 ;
V_6 -> V_70 = F_28 ;
V_6 -> V_71 = F_29 ;
V_6 -> V_72 = F_34 ;
V_6 -> V_73 = F_41 ;
F_49 ( V_74 , & V_6 -> V_75 ) ;
V_21 = F_50 ( V_6 ) ;
if ( V_21 < 0 ) {
F_51 ( V_6 ) ;
return V_21 ;
}
F_52 ( V_59 , V_20 ) ;
return 0 ;
}
static void F_53 ( struct V_58 * V_59 )
{
struct V_19 * V_20 = F_54 ( V_59 ) ;
F_2 ( L_9 , V_59 ) ;
if ( ! V_20 )
return;
F_52 ( V_59 , NULL ) ;
F_55 ( V_20 -> V_6 ) ;
F_51 ( V_20 -> V_6 ) ;
F_5 ( V_20 -> V_24 [ 0 ] ) ;
F_5 ( V_20 -> V_24 [ 1 ] ) ;
}
