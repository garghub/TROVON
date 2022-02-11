static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 )
return F_3 ( V_4 -> V_5 ) & V_6 ;
else
return 0 ;
}
static void F_4 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 ;
void * V_13 ;
int V_14 ;
V_13 = ( void * ) F_2 ( V_2 ) ;
V_14 = F_1 ( V_2 ) ;
if ( ! V_13 || V_14 == 0 )
return;
V_12 = F_5 ( V_10 -> V_15 , 20 + V_14 ,
V_16 ) ;
if ( V_12 == NULL ) {
F_6 ( V_8 ,
L_1 ) ;
return;
}
F_7 ( V_12 , V_17 , V_18 ) ;
F_8 ( V_12 , V_19 , V_14 , V_13 ) ;
F_9 ( V_12 , V_16 ) ;
return;
V_20:
F_10 ( V_12 ) ;
F_6 ( V_8 , L_2 ) ;
}
void F_11 ( struct V_7 * V_8 )
{
V_8 -> V_21 = F_4 ;
V_8 -> V_22 . V_23 = false ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = & V_8 -> V_26 -> V_25 ;
if ( V_8 -> V_22 . V_23 ) {
if ( V_8 -> V_22 . V_27 &&
V_8 -> V_22 . V_28 )
F_13 ( V_25 ,
V_29 ,
V_8 -> V_22 . V_27 ,
V_8 -> V_22 . V_28 ) ;
V_8 -> V_22 . V_23 = false ;
V_8 -> V_22 . V_27 = NULL ;
V_8 -> V_22 . V_30 = NULL ;
V_8 -> V_22 . V_28 = 0 ;
}
}
void F_14 ( struct V_7 * V_8 )
{
F_12 ( V_8 ) ;
}
static int F_15 ( struct V_9 * V_10 , struct V_31 * * V_32 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_33 V_34 ;
memset ( & V_34 , 0 , sizeof( struct V_33 ) ) ;
if ( ! V_32 [ V_35 ] ||
! V_32 [ V_36 ] ) {
F_6 ( V_8 ,
L_3 ) ;
return - V_37 ;
}
V_34 . V_38 = F_16 ( V_32 [ V_35 ] ) ;
V_34 . V_13 [ 0 ] = F_17 ( V_32 [ V_36 ] ) ;
V_34 . V_39 [ 0 ] = F_18 ( V_32 [ V_36 ] ) ;
V_34 . V_40 [ 0 ] = V_41 ;
F_19 ( V_8 , L_4
L_5 , V_34 . V_38 , V_34 . V_42 , V_34 . V_39 [ 0 ] ) ;
return F_20 ( V_8 , & V_34 ) ;
}
static int F_21 ( struct V_9 * V_10 , struct V_31 * * V_32 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
T_1 V_43 , V_44 ;
T_2 V_45 ;
struct V_11 * V_12 ;
int V_46 = 0 ;
if ( ! V_32 [ V_47 ] ) {
F_6 ( V_8 , L_6 ) ;
return - V_37 ;
}
V_43 = F_22 ( V_32 [ V_47 ] ) ;
F_19 ( V_8 , L_7 , V_43 ) ;
switch ( F_22 ( V_32 [ V_17 ] ) ) {
case V_48 :
V_44 = F_23 ( V_8 , V_43 ) ;
F_19 ( V_8 , L_8 , V_44 ) ;
V_12 = F_24 ( V_10 -> V_15 , 20 ) ;
if ( ! V_12 ) {
F_6 ( V_8 , L_9 ) ;
return - V_49 ;
}
F_7 ( V_12 , V_50 , V_44 ) ;
V_46 = F_25 ( V_12 ) ;
if ( V_46 < 0 )
F_6 ( V_8 ,
L_10 , V_46 ) ;
break;
case V_51 :
if ( ! V_32 [ V_50 ] ) {
F_6 ( V_8 ,
L_11 ) ;
return - V_37 ;
} else {
V_44 = F_22 ( V_32 [ V_50 ] ) ;
F_19 ( V_8 , L_12 , V_44 ) ;
F_26 ( V_8 , V_43 , V_44 ) ;
}
break;
case V_52 :
if ( ! V_32 [ V_53 ] ) {
F_6 ( V_8 , L_11 ) ;
return - V_37 ;
} else {
V_45 = F_16 ( V_32 [ V_53 ] ) ;
F_19 ( V_8 , L_13 , V_45 ) ;
F_27 ( V_8 , V_43 , V_45 ) ;
}
break;
default:
F_6 ( V_8 , L_14 ) ;
return - V_54 ;
}
return V_46 ;
V_20:
F_10 ( V_12 ) ;
return - V_55 ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_56 V_57 ;
int V_58 ;
F_29 ( V_8 , & V_57 ,
V_59 ,
NULL , NULL ) ;
V_58 = F_30 ( V_8 ) ;
if ( V_58 ) {
F_6 ( V_8 ,
L_15 , V_58 ) ;
goto V_60;
}
V_58 = F_31 ( V_8 , & V_57 , 2 * V_61 ) ;
if ( V_58 )
F_6 ( V_8 , L_16
L_17 , V_58 ) ;
return V_58 ;
V_60:
F_32 ( V_8 , & V_57 ) ;
return V_58 ;
}
static int F_33 ( struct V_9 * V_10 , struct V_31 * * V_32 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_11 * V_12 ;
unsigned char * V_62 = NULL ;
int V_46 = 0 , V_63 = 0 ;
switch ( F_22 ( V_32 [ V_17 ] ) ) {
case V_64 :
V_62 = ( unsigned char * ) V_8 -> V_65 -> V_66 ;
V_63 = strlen ( V_8 -> V_65 -> V_66 ) ;
V_12 = F_24 ( V_10 -> V_15 ,
V_63 + 20 ) ;
if ( ! V_12 ) {
F_6 ( V_8 ,
L_9 ) ;
return - V_49 ;
}
F_7 ( V_12 , V_17 ,
V_67 ) ;
F_8 ( V_12 , V_68 ,
V_63 , V_62 ) ;
V_46 = F_25 ( V_12 ) ;
if ( V_46 < 0 )
F_6 ( V_8 , L_10 ,
V_46 ) ;
break;
case V_69 :
V_46 = F_34 ( V_8 , & V_8 -> V_70 ,
V_71 , - 1 ) ;
if ( V_46 )
F_6 ( V_8 ,
L_18 , V_46 ) ;
break;
case V_72 :
F_28 ( V_8 ) ;
F_35 ( V_8 ) ;
break;
case V_73 :
V_46 = F_34 ( V_8 ,
& V_8 -> V_74 ,
V_75 ,
V_76 ) ;
if ( V_46 ) {
F_6 ( V_8 ,
L_19 , V_46 ) ;
break;
}
V_46 = F_36 ( V_8 ) ;
if ( V_46 )
F_6 ( V_8 ,
L_20 , V_46 ) ;
break;
case V_77 :
if ( V_8 -> V_78 ) {
V_12 = F_24 ( V_10 -> V_15 ,
V_8 -> V_65 -> V_79 -> V_80 + 20 ) ;
if ( ! V_12 ) {
F_6 ( V_8 ,
L_9 ) ;
return - V_49 ;
}
F_7 ( V_12 , V_17 ,
V_81 ) ;
F_8 ( V_12 , V_82 ,
V_8 -> V_65 -> V_79 -> V_80 ,
V_8 -> V_78 ) ;
V_46 = F_25 ( V_12 ) ;
if ( V_46 < 0 )
F_6 ( V_8 ,
L_10 ,
V_46 ) ;
} else
return - V_83 ;
break;
case V_84 :
if ( ! V_32 [ V_85 ] ) {
F_6 ( V_8 ,
L_21 ) ;
return - V_37 ;
}
V_8 -> V_86 = F_22 ( V_32 [ V_85 ] ) ;
break;
default:
F_6 ( V_8 , L_22 ) ;
return - V_54 ;
}
return V_46 ;
V_20:
F_10 ( V_12 ) ;
return - V_55 ;
}
static int F_37 ( struct V_9 * V_10 , struct V_31 * * V_32 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_11 * V_12 ;
int V_46 = 0 ;
struct V_24 * V_25 = & V_8 -> V_26 -> V_25 ;
switch ( F_22 ( V_32 [ V_17 ] ) ) {
case V_87 :
if ( V_8 -> V_22 . V_23 )
return - V_88 ;
V_8 -> V_22 . V_27 =
F_38 ( V_25 ,
V_29 ,
& V_8 -> V_22 . V_28 ,
V_89 ) ;
if ( ! V_8 -> V_22 . V_27 )
return - V_49 ;
V_8 -> V_22 . V_23 = true ;
V_8 -> V_22 . V_30 = ( T_2 * ) F_39 (
V_8 -> V_22 . V_27 , 0x100 ) ;
memset ( V_8 -> V_22 . V_30 , 0x03B ,
V_90 ) ;
V_12 = F_24 ( V_10 -> V_15 ,
sizeof( V_8 -> V_22 . V_28 ) + 20 ) ;
if ( ! V_12 ) {
F_6 ( V_8 ,
L_9 ) ;
F_12 ( V_8 ) ;
return - V_49 ;
}
F_8 ( V_12 , V_91 ,
sizeof( V_8 -> V_22 . V_28 ) ,
( V_92 * ) & V_8 -> V_22 . V_28 ) ;
V_46 = F_25 ( V_12 ) ;
if ( V_46 < 0 ) {
F_6 ( V_8 ,
L_10 ,
V_46 ) ;
}
break;
case V_93 :
F_12 ( V_8 ) ;
break;
case V_94 :
if ( V_8 -> V_22 . V_23 &&
V_8 -> V_22 . V_30 ) {
V_12 = F_24 ( V_10 -> V_15 ,
20 + V_90 ) ;
if ( V_12 == NULL ) {
F_6 ( V_8 ,
L_9 ) ;
return - V_49 ;
}
F_8 ( V_12 , V_95 ,
V_90 ,
V_8 -> V_22 . V_30 ) ;
V_46 = F_25 ( V_12 ) ;
if ( V_46 < 0 ) {
F_6 ( V_8 ,
L_10 , V_46 ) ;
}
} else
return - V_83 ;
break;
default:
F_6 ( V_8 , L_23 ) ;
return - V_54 ;
}
return V_46 ;
V_20:
F_10 ( V_12 ) ;
if ( F_22 ( V_32 [ V_17 ] ) ==
V_87 )
F_12 ( V_8 ) ;
return - V_55 ;
}
int F_40 ( struct V_9 * V_10 , void * V_13 , int V_39 )
{
struct V_31 * V_32 [ V_96 - 1 ] ;
struct V_7 * V_8 = V_10 -> V_8 ;
int V_97 ;
V_97 = F_41 ( V_32 , V_96 - 1 , V_13 , V_39 ,
V_98 ) ;
if ( V_97 != 0 ) {
F_6 ( V_8 ,
L_24 , V_97 ) ;
return V_97 ;
}
if ( ! V_32 [ V_17 ] ) {
F_6 ( V_8 , L_25 ) ;
return - V_37 ;
}
F_42 ( & V_8 -> V_99 ) ;
switch ( F_22 ( V_32 [ V_17 ] ) ) {
case V_100 :
F_6 ( V_8 , L_26 ) ;
V_97 = F_15 ( V_10 , V_32 ) ;
break;
case V_48 :
case V_51 :
case V_52 :
F_6 ( V_8 , L_27 ) ;
V_97 = F_21 ( V_10 , V_32 ) ;
break;
case V_64 :
case V_69 :
case V_72 :
case V_73 :
case V_77 :
case V_84 :
F_6 ( V_8 , L_28 ) ;
V_97 = F_33 ( V_10 , V_32 ) ;
break;
case V_87 :
case V_93 :
case V_94 :
F_6 ( V_8 , L_29 ) ;
V_97 = F_37 ( V_10 , V_32 ) ;
break;
default:
F_6 ( V_8 , L_30 ) ;
V_97 = - V_54 ;
break;
}
F_43 ( & V_8 -> V_99 ) ;
return V_97 ;
}
