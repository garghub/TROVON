int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
T_1 V_3 ;
int V_4 ;
if ( V_1 -> V_5 . V_6 == V_2 )
return 0 ;
F_2 ( L_1 , V_2 ) ;
V_3 = ( 1 - V_2 ) ;
V_4 = F_3 ( V_1 , V_7 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
V_1 -> V_5 . V_6 = V_2 ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_1 , T_2 * V_9 )
{
T_1 V_3 ;
int V_4 ;
V_4 = F_3 ( V_1 , V_10 , V_8 , V_9 ,
strlen ( V_9 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
V_3 = ( T_1 ) 0x1 ;
V_4 = F_3 ( V_1 , V_11 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , T_2 V_2 )
{
T_1 V_3 ;
int V_4 ;
V_3 = ( T_1 ) 0xcafe ;
V_4 = F_3 ( V_1 , V_12 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
V_3 = ( T_1 ) 0xa ;
V_4 = F_3 ( V_1 , V_13 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , T_2 type , T_1 V_14 )
{
T_1 V_3 ;
int V_4 ;
V_14 |= type << 8 ;
V_3 = V_14 ;
V_4 = F_3 ( V_1 , V_15 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
int F_7 ( struct V_1 * V_1 , T_2 V_16 )
{
T_1 V_3 ;
int V_4 ;
T_2 V_9 [] = L_2 ;
F_2 ( L_3 , V_16 ,
V_17 , V_18 ) ;
if ( V_16 == V_17 ) {
F_6 ( V_1 , 0 , strlen ( V_9 ) ) ;
F_4 ( V_1 , V_9 ) ;
F_5 ( V_1 , 0x0 ) ;
}
if ( V_16 == V_17 )
V_3 = 0x01 ;
else
V_3 = 0x00 ;
V_4 = F_3 ( V_1 , V_19 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_16 == V_17 ) {
F_6 ( V_1 , 0 , strlen ( V_9 ) ) ;
F_4 ( V_1 , V_9 ) ;
}
V_1 -> V_5 . V_20 . V_21 = V_16 ;
return 0 ;
}
int F_8 ( struct V_1 * V_1 , T_2 * V_9 , T_2 V_22 )
{
T_1 V_3 ;
int V_4 ;
if ( V_1 -> V_23 != V_24 )
return - V_25 ;
F_7 ( V_1 , 0 ) ;
F_6 ( V_1 , V_22 , strlen ( V_9 ) ) ;
F_4 ( V_1 , V_9 ) ;
F_5 ( V_1 , 0x0 ) ;
V_3 = 1 ;
V_4 = F_3 ( V_1 , V_19 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
int F_9 ( struct V_1 * V_1 , T_3 V_26 )
{
T_1 V_3 ;
int V_4 ;
if ( V_1 -> V_23 != V_24 )
return - V_25 ;
F_2 ( L_4 , V_26 ) ;
V_26 = ( V_26 - 87500 ) / 100 ;
V_3 = ( T_1 ) V_26 ;
V_4 = F_3 ( V_1 , V_27 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
int F_10 ( struct V_1 * V_1 , T_2 V_28 )
{
T_1 V_3 ;
int V_4 ;
if ( V_28 != V_29 && V_28 != V_30 ) {
F_11 ( L_5 ) ;
return - V_31 ;
}
V_3 = ( T_1 ) V_28 ;
V_4 = F_3 ( V_1 , V_32 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
int F_12 ( struct V_1 * V_1 , T_2 V_33 )
{
T_1 V_3 ;
int V_4 ;
F_2 ( L_6 , V_33 ) ;
V_3 = V_33 ;
V_4 = F_3 ( V_1 , V_34 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_35 * V_36 = & V_1 -> V_5 ;
T_1 V_3 ;
int V_4 ;
V_3 = V_36 -> V_37 ;
V_4 = F_3 ( V_1 , V_38 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , T_2 V_39 )
{
struct V_35 * V_36 = & V_1 -> V_5 ;
unsigned long V_40 ;
T_1 V_3 ;
int V_4 ;
V_3 = V_41 ;
V_4 = F_3 ( V_1 , V_42 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
V_3 = V_39 ;
V_4 = F_3 ( V_1 , V_43 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
F_15 ( & V_1 -> V_44 ) ;
V_40 = F_16 ( & V_1 -> V_44 ,
V_45 ) ;
if ( ! V_40 ) {
F_11 ( L_7 ,
F_17 ( V_45 ) / 1000 ) ;
return - V_46 ;
}
F_18 ( V_47 , & V_1 -> V_21 ) ;
V_36 -> V_48 = V_39 ;
return 0 ;
}
int F_19 ( struct V_1 * V_1 , T_2 V_49 )
{
T_1 V_3 ;
struct V_35 * V_36 = & V_1 -> V_5 ;
int V_4 ;
if ( V_1 -> V_23 != V_24 )
return - V_25 ;
F_2 ( L_8 , ( long int ) V_49 ) ;
if ( ! F_20 ( V_50 , & V_1 -> V_21 ) ) {
V_36 -> V_51 = V_49 ;
return 0 ;
}
V_3 = ( V_52 - V_49 ) ;
V_4 = F_3 ( V_1 , V_53 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
V_36 -> V_51 = V_49 ;
return 0 ;
}
int F_21 ( struct V_1 * V_1 , T_3 V_54 )
{
struct V_35 * V_36 = & V_1 -> V_5 ;
T_1 V_3 ;
int V_4 ;
if ( V_1 -> V_23 != V_24 )
return - V_25 ;
switch ( V_54 ) {
case V_55 :
V_3 = V_56 ;
break;
case V_57 :
V_3 = V_58 ;
break;
case V_59 :
V_3 = V_60 ;
break;
}
V_4 = F_3 ( V_1 , V_61 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
V_36 -> V_62 = V_3 ;
return V_4 ;
}
int F_22 ( struct V_1 * V_1 )
{
T_1 V_63 ;
T_3 V_64 ;
int V_4 ;
if ( V_1 -> V_23 != V_24 )
return - V_25 ;
V_4 = F_3 ( V_1 , V_65 , V_66 ,
NULL , sizeof( V_63 ) , & V_63 , & V_64 ) ;
if ( V_4 < 0 )
return V_4 ;
V_63 = F_23 ( V_63 ) ;
return V_63 ;
}
int F_24 ( struct V_1 * V_1 , T_3 V_67 )
{
struct V_35 * V_36 = & V_1 -> V_5 ;
T_1 V_3 , V_68 ;
int V_4 ;
if ( F_20 ( V_47 , & V_1 -> V_21 ) ) {
F_14 ( V_1 , 0 ) ;
F_25 ( V_47 , & V_1 -> V_21 ) ;
}
V_3 = ( V_69 | V_70 ) ;
V_4 = F_3 ( V_1 , V_42 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
V_36 -> V_71 = ( unsigned long ) V_67 ;
F_2 ( L_9 , ( long int ) V_36 -> V_71 ) ;
V_68 = V_67 / 10 ;
V_3 = V_68 ;
V_4 = F_3 ( V_1 , V_72 , V_8 , & V_3 ,
sizeof( V_3 ) , NULL , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
F_19 ( V_1 , V_36 -> V_51 ) ;
F_21 ( V_1 , V_36 -> V_62 ) ;
V_36 -> V_37 = 0x01 ;
F_13 ( V_1 ) ;
F_14 ( V_1 , 0x01 ) ;
V_36 -> V_6 = V_73 ;
V_36 -> V_20 . V_21 = V_18 ;
return 0 ;
}
