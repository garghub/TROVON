static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_4 , void * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 = F_4 ( V_4 ) ;
F_5 ( V_7 -> V_9 , L_1 , sizeof( V_7 -> V_9 ) ) ;
F_5 ( V_7 -> V_10 , L_2 , sizeof( V_7 -> V_10 ) ) ;
F_6 ( V_8 -> V_11 , V_7 -> V_12 , sizeof( V_7 -> V_12 ) ) ;
V_7 -> V_13 = V_14 | V_15 ;
V_7 -> V_16 = V_7 -> V_13 | V_17 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_4 , void * V_5 ,
struct V_18 * V_19 )
{
struct V_1 * V_8 = F_4 ( V_4 ) ;
return F_8 ( V_8 -> V_20 , V_21 , V_22 , V_19 ) ;
}
static int F_9 ( struct V_4 * V_4 , void * V_5 ,
const struct V_18 * V_19 )
{
struct V_1 * V_8 = F_4 ( V_4 ) ;
return F_8 ( V_8 -> V_20 , V_21 , V_23 , V_19 ) ;
}
static int F_10 ( struct V_4 * V_4 , void * V_5 ,
const struct V_24 * V_25 )
{
struct V_1 * V_8 = F_4 ( V_4 ) ;
return F_8 ( V_8 -> V_20 , V_21 , V_26 , V_25 ) ;
}
static int F_11 ( struct V_4 * V_4 , void * V_5 ,
struct V_24 * V_25 )
{
struct V_1 * V_8 = F_4 ( V_4 ) ;
return F_8 ( V_8 -> V_20 , V_21 , V_27 , V_25 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_28 * V_29 = & V_8 -> V_28 ;
F_13 ( V_29 ) ;
F_14 ( & V_8 -> V_3 ) ;
F_15 ( V_8 -> V_30 ) ;
F_15 ( V_8 ) ;
}
static int F_16 ( struct V_1 * V_8 )
{
unsigned long V_31 = V_32 + F_17 ( V_33 ) + 1 ;
T_1 * V_30 = V_8 -> V_30 ;
int V_34 ;
V_34 = F_18 ( V_8 -> V_11 , F_19 ( V_8 -> V_11 , 0 ) ,
0x09 , 0x21 , 0x033f , 0 , V_8 -> V_30 ,
V_35 , V_36 ) ;
if ( V_34 < 0 )
return V_34 ;
for (; ; ) {
V_34 = F_18 ( V_8 -> V_11 , F_20 ( V_8 -> V_11 , 0 ) ,
0x01 , 0xa1 , 0x033f , 0 , V_8 -> V_30 ,
V_35 , V_36 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( ! V_8 -> V_30 [ 1 ] ) {
switch ( V_30 [ 1 ] ) {
case 0x32 :
if ( V_8 -> V_30 [ 2 ] == 0 )
return 0 ;
break;
case 0x14 :
case 0x12 :
if ( V_8 -> V_30 [ 2 ] & V_37 )
return 0 ;
break;
case 0x06 :
if ( ( V_8 -> V_30 [ 2 ] & V_37 ) && V_8 -> V_30 [ 9 ] == 0x08 )
return 0 ;
break;
default:
return 0 ;
}
}
if ( F_21 ( V_31 ) )
return - V_38 ;
F_22 ( 3 ) ;
}
return V_34 ;
}
static int F_23 ( struct V_1 * V_8 )
{
int V_34 = 0 ;
int V_39 ;
V_8 -> V_30 [ 0 ] = 0x3f ;
for ( V_39 = 0 ; V_39 < F_24 ( V_40 ) ; V_39 ++ ) {
int V_41 = V_40 [ V_39 ] . V_41 ;
const T_1 * V_42 = V_40 [ V_39 ] . V_42 ;
memcpy ( V_8 -> V_30 + 1 , V_42 , V_41 ) ;
memset ( V_8 -> V_30 + V_41 + 1 , 0 , V_35 - 1 - V_41 ) ;
V_34 = F_16 ( V_8 ) ;
}
return V_34 ;
}
static int F_25 ( struct V_1 * V_8 , T_1 * V_42 , char * V_43 , int V_41 )
{
int V_34 ;
V_8 -> V_30 [ 0 ] = 0x3f ;
V_8 -> V_30 [ 1 ] = 0x06 ;
memcpy ( V_8 -> V_30 + 2 , V_42 , 3 ) ;
memcpy ( V_8 -> V_30 + 5 , V_43 , V_41 ) ;
memset ( V_8 -> V_30 + 5 + V_41 , 0 , V_35 - 5 - V_41 ) ;
V_34 = F_18 ( V_8 -> V_11 , F_19 ( V_8 -> V_11 , 0 ) ,
0x09 , 0x21 , 0x033f , 0 , V_8 -> V_30 ,
V_35 , V_36 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static int F_26 ( struct V_1 * V_8 , char * V_43 , int V_41 )
{
unsigned long V_31 = V_32 + F_17 ( V_33 ) + 1 ;
int V_34 ;
for (; ; ) {
V_34 = F_18 ( V_8 -> V_11 ,
F_20 ( V_8 -> V_11 , 0 ) ,
0x01 , 0xa1 , 0x033f , 0 , V_8 -> V_30 ,
V_35 , V_36 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_8 -> V_30 [ 1 ] == 0 && ( V_8 -> V_30 [ 2 ] & V_37 ) ) {
memcpy ( V_43 , V_8 -> V_30 + 2 , V_41 ) ;
return 0 ;
}
if ( F_21 ( V_31 ) ) {
V_43 [ 0 ] = 0 ;
return 0 ;
}
F_22 ( 3 ) ;
}
}
static int F_27 ( struct V_1 * V_8 , char * V_43 , int V_41 )
{
int V_34 = - V_44 ;
int V_39 ;
if ( V_41 > V_35 - 5 )
return - V_44 ;
for ( V_39 = 0 ; V_39 < F_24 ( V_45 ) ; V_39 ++ ) {
if ( V_43 [ 0 ] == V_45 [ V_39 ] . V_46 )
V_34 = F_25 ( V_8 , V_45 [ V_39 ] . V_42 ,
V_43 , V_41 ) ;
}
return V_34 < 0 ? V_34 : 0 ;
}
static int F_28 ( struct V_28 * V_28 ,
struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_8 = F_29 ( V_28 ) ;
int V_34 = - V_44 ;
int V_39 ;
if ( V_49 <= 0 )
return 0 ;
for ( V_39 = 0 ; V_39 < V_49 ; V_39 ++ ) {
if ( V_48 [ V_39 ] . V_50 & V_51 )
V_34 = F_26 ( V_8 , V_48 [ V_39 ] . V_52 , V_48 [ V_39 ] . V_41 ) ;
else
V_34 = F_27 ( V_8 , V_48 [ V_39 ] . V_52 , V_48 [ V_39 ] . V_41 ) ;
if ( V_34 )
break;
}
return V_34 ? V_34 : V_49 ;
}
static T_2 F_30 ( struct V_28 * V_29 )
{
return V_53 | V_54 ;
}
static int F_31 ( struct V_1 * V_8 )
{
V_8 -> V_28 = V_55 ;
V_8 -> V_28 . V_56 . V_57 = & V_8 -> V_11 -> V_56 ;
F_32 ( & V_8 -> V_28 , V_8 ) ;
return F_33 ( & V_8 -> V_28 ) ;
}
static int F_34 ( struct V_58 * V_59 ,
const struct V_60 * V_61 )
{
struct V_1 * V_8 ;
struct V_28 * V_29 ;
struct V_20 * V_62 ;
int V_34 = - V_63 ;
F_35 ( & V_59 -> V_56 , L_3 ,
V_61 -> V_64 , V_61 -> V_65 ) ;
V_8 = F_36 ( sizeof( struct V_1 ) , V_66 ) ;
if ( V_8 )
V_8 -> V_30 = F_37 ( V_35 , V_66 ) ;
if ( ! V_8 || ! V_8 -> V_30 ) {
F_38 ( & V_59 -> V_56 , L_4 ) ;
F_15 ( V_8 ) ;
return - V_63 ;
}
F_39 ( & V_8 -> V_67 ) ;
V_8 -> V_11 = F_40 ( V_59 ) ;
V_8 -> V_59 = V_59 ;
F_41 ( V_59 , & V_8 -> V_3 ) ;
V_34 = F_23 ( V_8 ) ;
if ( V_34 < 0 )
goto V_68;
V_34 = F_42 ( & V_59 -> V_56 , & V_8 -> V_3 ) ;
if ( V_34 < 0 ) {
F_38 ( & V_59 -> V_56 , L_5 ) ;
goto V_68;
}
V_34 = F_31 ( V_8 ) ;
if ( V_34 < 0 ) {
F_38 ( & V_59 -> V_56 , L_6 ) ;
goto V_69;
}
V_29 = & V_8 -> V_28 ;
V_62 = F_43 ( & V_8 -> V_3 , V_29 ,
& V_70 , NULL ) ;
V_8 -> V_20 = V_62 ;
if ( ! V_62 ) {
F_38 ( & V_59 -> V_56 , L_7 ) ;
V_34 = - V_71 ;
goto V_72;
}
V_8 -> V_73 . V_74 = V_62 -> V_74 ;
V_8 -> V_3 . V_75 = F_12 ;
F_5 ( V_8 -> V_73 . V_76 , V_8 -> V_3 . V_76 ,
sizeof( V_8 -> V_73 . V_76 ) ) ;
V_8 -> V_73 . V_3 = & V_8 -> V_3 ;
V_8 -> V_73 . V_77 = & V_78 ;
V_8 -> V_73 . V_79 = & V_80 ;
V_8 -> V_73 . V_67 = & V_8 -> V_67 ;
V_8 -> V_73 . V_75 = V_81 ;
V_8 -> V_73 . V_82 = V_83 ;
F_44 ( & V_8 -> V_73 , V_8 ) ;
F_45 ( V_84 , & V_8 -> V_73 . V_50 ) ;
V_34 = F_46 ( & V_8 -> V_73 , V_85 , - 1 ) ;
if ( V_34 < 0 ) {
F_38 ( & V_59 -> V_56 , L_8 ) ;
goto V_72;
}
F_35 ( & V_59 -> V_56 , L_9 ,
F_47 ( & V_8 -> V_73 ) ) ;
return 0 ;
V_72:
F_13 ( V_29 ) ;
V_69:
F_14 ( & V_8 -> V_3 ) ;
V_68:
F_15 ( V_8 -> V_30 ) ;
F_15 ( V_8 ) ;
return V_34 ;
}
static void F_48 ( struct V_58 * V_59 )
{
struct V_1 * V_8 = F_1 ( F_49 ( V_59 ) ) ;
F_35 ( & V_59 -> V_56 , L_10 ) ;
F_50 ( & V_8 -> V_67 ) ;
F_41 ( V_59 , NULL ) ;
F_51 ( & V_8 -> V_73 ) ;
F_52 ( & V_8 -> V_3 ) ;
F_53 ( & V_8 -> V_67 ) ;
F_54 ( & V_8 -> V_3 ) ;
}
