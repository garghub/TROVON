static int F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 , V_12 ;
T_1 * V_13 = V_9 -> V_14 ;
int V_15 ;
if ( V_3 != V_16 && ! V_5 )
return - V_17 ;
F_3 ( & V_9 -> V_18 ) ;
switch ( V_3 ) {
case V_19 :
V_11 = sizeof( V_20 ) ;
V_12 = sizeof( V_21 ) ;
memcpy ( V_13 , V_20 , V_11 ) ;
V_13 [ 14 ] = V_4 & 0xff ;
break;
case V_22 :
V_11 = sizeof( V_23 ) ;
V_12 = sizeof( V_24 ) ;
memcpy ( V_13 , V_23 , V_11 ) ;
V_13 [ 14 ] = V_4 & 0xff ;
V_13 [ 17 ] = * V_5 ;
break;
case V_16 :
V_11 = sizeof( V_25 ) ;
V_12 = sizeof( V_24 ) ;
memcpy ( V_13 , V_25 , V_11 ) ;
V_13 [ 14 ] = V_4 & 0xff ;
V_13 [ 15 ] = ( V_4 >> 8 ) & 0xff ;
V_13 [ 16 ] = ( V_4 >> 16 ) & 0xff ;
break;
default:
V_15 = - V_17 ;
goto V_26;
}
V_15 = F_4 ( V_7 ,
F_5 ( V_7 ,
V_9 -> V_27 -> V_28 ) ,
V_9 -> V_14 ,
V_11 ,
NULL ,
V_29 ) ;
if ( V_15 )
goto V_26;
V_15 = F_4 ( V_7 ,
F_6 ( V_7 ,
V_9 -> V_30 -> V_28 ) ,
V_9 -> V_31 ,
V_12 ,
NULL ,
V_29 ) ;
if ( V_15 )
goto V_26;
if ( V_3 == V_19 ) {
* V_5 = V_9 -> V_31 [ 14 ] ;
V_9 -> V_31 [ 14 ] = 0x00 ;
if ( memcmp ( V_9 -> V_31 , V_21 ,
sizeof( V_21 ) ) ) {
V_15 = - V_17 ;
}
} else if ( memcmp ( V_9 -> V_31 , V_24 ,
sizeof( V_24 ) ) ) {
V_15 = - V_17 ;
}
V_26:
F_7 ( & V_9 -> V_18 ) ;
return V_15 ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 ,
T_2 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 , V_12 ;
T_1 * V_13 = V_9 -> V_14 ;
int V_15 ;
if ( ( V_3 == V_32 || V_3 == V_33 ) && ! V_4 )
return - V_17 ;
F_3 ( & V_9 -> V_18 ) ;
switch ( V_3 ) {
case V_34 :
V_11 = sizeof( V_35 ) ;
V_12 = sizeof( V_24 ) ;
memcpy ( V_13 , V_35 , V_11 ) ;
break;
case V_36 :
V_11 = sizeof( V_37 ) ;
V_12 = sizeof( V_24 ) ;
memcpy ( V_13 , V_37 , V_11 ) ;
break;
case V_32 :
V_11 = sizeof( V_38 ) ;
V_12 = sizeof( V_39 ) ;
memcpy ( V_13 , V_38 , V_11 ) ;
break;
case V_33 :
V_11 = sizeof( V_40 ) ;
V_12 = sizeof( V_24 ) ;
memcpy ( V_13 , V_40 , V_11 ) ;
* ( ( V_41 * ) & V_13 [ 12 ] ) = F_9 ( * V_4 ) ;
break;
default:
V_15 = - V_17 ;
goto V_26;
}
V_15 = F_4 ( V_7 ,
F_5 ( V_7 ,
V_9 -> V_27 -> V_28 ) ,
V_9 -> V_14 ,
V_11 ,
NULL ,
V_29 ) ;
if ( V_15 )
goto V_26;
V_15 = F_4 ( V_7 ,
F_6 ( V_7 ,
V_9 -> V_30 -> V_28 ) ,
V_9 -> V_31 ,
V_12 ,
NULL ,
V_29 ) ;
if ( V_15 )
goto V_26;
if ( V_3 == V_32 ) {
int V_42 ;
* V_4 = F_10 ( * ( ( V_41 * ) & V_9 -> V_31 [ 12 ] ) ) ;
for ( V_42 = 12 ; V_42 < sizeof( V_39 ) ; ++ V_42 )
V_9 -> V_31 [ V_42 ] = 0x00 ;
if ( memcmp ( V_9 -> V_31 , V_39 ,
sizeof( V_39 ) ) ) {
V_15 = - V_17 ;
}
} else if ( memcmp ( V_9 -> V_31 , V_24 ,
sizeof( V_24 ) ) ) {
V_15 = - V_17 ;
}
V_26:
F_7 ( & V_9 -> V_18 ) ;
return V_15 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned int * V_47 )
{
int V_15 ;
V_15 = F_12 ( V_2 , V_44 , V_46 , V_47 , 0 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_1 ( V_2 , V_16 , V_44 -> V_48 , NULL ) ;
if ( V_15 )
return V_15 ;
return V_46 -> V_49 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned int * V_47 )
{
unsigned int V_50 ;
int V_15 ;
T_1 V_51 ;
T_1 V_5 ;
V_50 = F_14 ( V_44 , V_47 ) ;
for ( V_51 = 0 ; V_51 < 3 ; V_51 ++ ) {
if ( V_50 & ( 0xFF << V_51 * 8 ) ) {
V_5 = ( V_44 -> V_52 >> V_51 * 8 ) & 0xFF ;
V_15 = F_1 ( V_2 , V_22 ,
V_51 , & V_5 ) ;
if ( V_15 )
return V_15 ;
}
}
V_47 [ 1 ] = 0 ;
for ( V_51 = 0 ; V_51 < 3 ; V_51 ++ ) {
V_15 = F_1 ( V_2 , V_19 , V_51 , & V_5 ) ;
if ( V_15 )
return V_15 ;
V_47 [ 1 ] |= V_5 << V_51 * 8 ;
}
return V_46 -> V_49 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned int * V_47 )
{
int V_15 ;
T_2 V_4 = 0 ;
switch ( V_47 [ 0 ] ) {
case V_53 :
V_15 = F_8 ( V_2 , V_34 , NULL ) ;
break;
case V_54 :
V_15 = F_8 ( V_2 , V_36 , NULL ) ;
break;
case V_55 :
V_15 = F_8 ( V_2 , V_36 , NULL ) ;
if ( V_15 )
break;
V_15 = F_8 ( V_2 , V_33 , & V_4 ) ;
break;
default:
return - V_17 ;
}
return V_15 ? V_15 : V_46 -> V_49 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned int * V_47 )
{
int V_15 ;
T_2 V_4 ;
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_46 -> V_49 ; V_42 ++ ) {
V_15 = F_8 ( V_2 , V_32 , & V_4 ) ;
if ( V_15 )
return V_15 ;
V_47 [ V_42 ] = V_4 ;
}
return V_46 -> V_49 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned int * V_47 )
{
int V_15 ;
if ( V_46 -> V_49 ) {
T_2 V_4 = V_47 [ V_46 -> V_49 - 1 ] ;
V_15 = F_8 ( V_2 , V_33 , & V_4 ) ;
if ( V_15 )
return V_15 ;
}
return V_46 -> V_49 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_3 V_56 ;
V_56 = F_19 ( V_9 -> V_30 -> V_57 ) ;
V_9 -> V_31 = F_20 ( V_56 , V_58 ) ;
if ( ! V_9 -> V_31 )
return - V_59 ;
V_56 = F_19 ( V_9 -> V_27 -> V_57 ) ;
V_9 -> V_14 = F_20 ( V_56 , V_58 ) ;
if ( ! V_9 -> V_14 ) {
F_21 ( V_9 -> V_31 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = F_23 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_62 * V_63 = V_61 -> V_64 ;
struct V_65 * V_66 ;
int V_42 ;
if ( V_63 -> V_67 . V_68 != 2 ) {
F_24 ( V_2 -> V_69 , L_1 ) ;
return - V_70 ;
}
for ( V_42 = 0 ; V_42 < V_63 -> V_67 . V_68 ; V_42 ++ ) {
V_66 = & V_63 -> V_71 [ V_42 ] . V_67 ;
if ( F_25 ( V_66 ) ) {
if ( ! V_9 -> V_30 )
V_9 -> V_30 = V_66 ;
continue;
}
if ( F_26 ( V_66 ) ) {
if ( ! V_9 -> V_27 )
V_9 -> V_27 = V_66 ;
continue;
}
}
if ( ! V_9 -> V_30 || ! V_9 -> V_27 )
return - V_70 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned long V_72 )
{
struct V_60 * V_61 = F_23 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_43 * V_44 ;
int V_15 ;
V_9 = F_28 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_59 ;
V_15 = F_22 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_18 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_29 ( & V_9 -> V_18 ) ;
F_30 ( V_61 , V_9 ) ;
V_15 = F_31 ( V_2 , 2 ) ;
if ( V_15 )
return V_15 ;
V_44 = & V_2 -> V_73 [ 0 ] ;
V_44 -> type = V_74 ;
V_44 -> V_75 = V_76 | V_77 ;
V_44 -> V_78 = 24 ;
V_44 -> V_79 = 1 ;
V_44 -> V_80 = & V_81 ;
V_44 -> V_82 = F_13 ;
V_44 -> V_83 = F_11 ;
V_44 = & V_2 -> V_73 [ 1 ] ;
V_44 -> type = V_84 ;
V_44 -> V_75 = V_76 | V_77 | V_85 ;
V_44 -> V_78 = 1 ;
V_44 -> V_79 = 0xffffffff ;
V_44 -> V_86 = F_16 ;
V_44 -> V_87 = F_17 ;
V_44 -> V_83 = F_15 ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = F_23 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
if ( ! V_9 )
return;
F_3 ( & V_9 -> V_18 ) ;
F_30 ( V_61 , NULL ) ;
F_21 ( V_9 -> V_31 ) ;
F_21 ( V_9 -> V_14 ) ;
F_7 ( & V_9 -> V_18 ) ;
}
static int F_33 ( struct V_60 * V_61 ,
const struct V_88 * V_89 )
{
return F_34 ( V_61 , & V_90 , V_89 -> V_91 ) ;
}
