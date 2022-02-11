static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_6 )
* V_5 -> V_6 = ( ( V_7 * ) V_3 ) [ 1 ] ;
if ( V_5 -> V_1 . V_8 )
F_3 ( & V_5 -> V_9 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
if ( V_5 -> V_1 . V_8 ) {
if ( ! F_5 ( & V_5 -> V_9 ,
F_6 ( V_10 ) ) )
return - V_11 ;
}
if ( * V_5 -> V_6 == 0xffffffff )
return - V_12 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 , V_7 V_13 ,
V_7 V_14 , V_7 V_15 , V_7 V_16 ,
V_7 V_17 , V_7 * V_18 )
{
V_7 V_19 [ 3 ] ;
int V_20 ;
V_19 [ 0 ] = F_8 ( V_21 , V_13 ,
V_22 , V_16 , V_15 , V_17 ) ;
V_19 [ 1 ] = F_9 ( V_14 ) ;
V_19 [ 2 ] = 0 ;
V_5 -> V_6 = V_18 ;
V_20 = F_10 ( V_5 -> V_23 , & V_19 ) ;
if ( V_20 < 0 )
goto V_24;
V_20 = F_4 ( V_5 ) ;
V_24:
V_5 -> V_6 = NULL ;
return V_20 ;
}
static int F_11 ( struct V_4 * V_5 , V_7 V_13 ,
V_7 V_14 , V_7 V_15 , V_7 V_16 , V_7 V_25 ,
V_7 V_18 )
{
V_7 V_19 [ 3 ] ;
int V_20 ;
V_19 [ 0 ] = F_8 ( V_21 , V_13 ,
V_26 , V_16 , V_15 , V_25 ) ;
V_19 [ 1 ] = F_9 ( V_14 ) ;
V_19 [ 2 ] = V_18 ;
V_5 -> V_6 = V_19 ;
V_20 = F_10 ( V_5 -> V_23 , & V_19 ) ;
if ( V_20 < 0 )
goto V_24;
V_20 = F_4 ( V_5 ) ;
V_24:
V_5 -> V_6 = NULL ;
return V_20 ;
}
static int F_12 ( struct V_4 * V_5 , V_7 V_13 , V_7 V_14 ,
V_7 V_15 , V_7 V_16 , V_7 V_17 ,
V_7 V_27 , void * V_18 )
{
T_1 V_28 ;
V_7 V_19 [ 3 ] ;
int V_20 ;
V_28 = F_13 ( V_5 -> V_29 , V_5 -> V_30 , V_17 , V_31 ) ;
if ( F_14 ( V_5 -> V_29 , V_28 ) ) {
F_15 ( & V_5 -> V_32 . V_29 , L_1 ,
V_5 -> V_30 ) ;
V_20 = - V_33 ;
goto V_24;
}
V_19 [ 0 ] = F_8 ( V_21 , V_13 , V_22 ,
V_16 , V_15 , V_17 ) ;
V_19 [ 1 ] = V_34 |
F_16 ( V_27 ) |
F_17 ( V_28 ) |
F_9 ( V_14 ) ;
V_19 [ 2 ] = ( V_7 ) V_28 ;
V_5 -> V_6 = V_19 ;
V_20 = F_10 ( V_5 -> V_23 , & V_19 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_4 ( V_5 ) ;
memcpy ( V_18 , V_5 -> V_30 , V_17 ) ;
V_35:
F_18 ( V_5 -> V_29 , V_28 , V_17 , V_31 ) ;
V_24:
V_5 -> V_6 = NULL ;
return V_20 ;
}
static int F_19 ( struct V_4 * V_5 , V_7 V_13 ,
V_7 V_14 , V_7 V_15 , V_7 V_16 , V_7 V_25 ,
void * V_18 )
{
T_1 V_28 ;
V_7 V_19 [ 3 ] ;
int V_20 ;
memcpy ( V_5 -> V_30 , V_18 , V_25 ) ;
V_28 = F_13 ( V_5 -> V_29 , V_5 -> V_30 , V_25 ,
V_36 ) ;
if ( F_14 ( V_5 -> V_29 , V_28 ) ) {
F_15 ( & V_5 -> V_32 . V_29 , L_1 ,
V_5 -> V_30 ) ;
V_20 = - V_33 ;
goto V_24;
}
V_19 [ 0 ] = F_8 ( V_21 , V_13 , V_26 ,
V_16 , V_15 , V_25 ) ;
V_19 [ 1 ] = V_34 |
F_17 ( V_28 ) |
F_9 ( V_14 ) ;
V_19 [ 2 ] = ( V_7 ) V_28 ;
V_5 -> V_6 = V_19 ;
if ( V_5 -> V_1 . V_8 )
F_20 ( & V_5 -> V_9 ) ;
V_20 = F_10 ( V_5 -> V_23 , & V_19 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_4 ( V_5 ) ;
V_35:
F_18 ( V_5 -> V_29 , V_28 , V_25 , V_36 ) ;
V_24:
V_5 -> V_6 = NULL ;
return V_20 ;
}
static int F_21 ( struct V_37 * V_38 , T_2 V_14 ,
unsigned short V_39 , char V_40 ,
T_3 V_41 , int V_42 ,
union V_43 * V_18 )
{
struct V_4 * V_5 = F_22 ( V_38 ) ;
int V_44 = - V_45 ;
V_7 V_46 ;
switch ( V_42 ) {
case V_47 :
if ( V_40 == V_48 ) {
V_44 = F_7 ( V_5 , V_14 , 0 , 0 ,
V_49 ,
V_50 , & V_46 ) ;
V_18 -> V_51 = V_46 ;
} else {
V_44 = F_11 ( V_5 , V_14 , V_41 , V_52 ,
V_49 ,
0 , 0 ) ;
}
break;
case V_53 :
if ( V_40 == V_48 ) {
V_44 = F_7 ( V_5 , V_14 , V_41 , V_52 ,
V_49 ,
V_50 , & V_46 ) ;
V_18 -> V_51 = V_46 ;
} else {
V_46 = V_18 -> V_51 ;
V_44 = F_11 ( V_5 , V_14 , V_41 , V_52 ,
V_49 ,
V_50 , V_46 ) ;
}
break;
case V_54 :
if ( V_40 == V_48 ) {
V_44 = F_7 ( V_5 , V_14 , V_41 , V_52 ,
V_49 ,
V_55 , & V_46 ) ;
V_18 -> V_56 = V_46 ;
} else {
V_46 = V_18 -> V_56 ;
V_44 = F_11 ( V_5 , V_14 , V_41 , V_52 ,
V_49 ,
V_55 , V_46 ) ;
}
break;
case V_57 :
if ( V_40 == V_48 ) {
V_44 = F_12 ( V_5 , V_14 , V_41 ,
V_52 ,
V_49 ,
V_58 + 1 ,
V_59 ,
& V_18 -> V_60 [ 0 ] ) ;
} else {
V_44 = F_19 ( V_5 , V_14 , V_41 ,
V_52 ,
V_49 ,
V_18 -> V_60 [ 0 ] + 1 ,
& V_18 -> V_60 [ 0 ] ) ;
}
break;
case V_61 :
if ( V_40 == V_48 ) {
V_44 = F_12 ( V_5 , V_14 ,
V_41 ,
V_52 ,
V_62 ,
V_58 ,
V_63 ,
& V_18 -> V_60 [ 1 ] ) ;
} else {
V_44 = F_19 ( V_5 , V_14 , V_41 ,
V_52 ,
V_62 ,
V_18 -> V_60 [ 0 ] ,
& V_18 -> V_60 [ 1 ] ) ;
}
break;
default:
break;
}
return V_44 ;
}
static V_7 F_23 ( struct V_37 * V_32 )
{
return V_64 |
V_65 |
V_66 |
V_67 |
V_68 ;
}
static int F_24 ( struct V_69 * V_70 )
{
struct V_4 * V_5 ;
struct V_37 * V_32 ;
struct V_1 * V_2 ;
int V_20 ;
V_5 = F_25 ( & V_70 -> V_29 , sizeof( * V_5 ) , V_71 ) ;
if ( ! V_5 )
return - V_33 ;
V_5 -> V_29 = & V_70 -> V_29 ;
F_26 ( V_70 , V_5 ) ;
V_2 = & V_5 -> V_1 ;
V_2 -> V_29 = & V_70 -> V_29 ;
V_2 -> V_72 = F_1 ;
V_2 -> V_8 = true ;
F_27 ( & V_5 -> V_9 ) ;
V_2 -> V_73 = V_10 ;
V_2 -> V_74 = false ;
V_5 -> V_23 = F_28 ( V_2 , V_75 ) ;
if ( F_29 ( V_5 -> V_23 ) ) {
F_15 ( & V_70 -> V_29 , L_2 ) ;
return F_30 ( V_5 -> V_23 ) ;
}
V_20 = F_31 ( & V_70 -> V_29 , F_32 ( 64 ) ) ;
if ( V_20 )
F_33 ( & V_70 -> V_29 , L_3 ) ;
V_32 = & V_5 -> V_32 ;
snprintf ( V_32 -> V_76 , sizeof( V_32 -> V_76 ) , L_4 ) ;
V_32 -> V_77 = & V_78 ;
V_32 -> V_79 = V_80 ;
V_32 -> V_29 . V_81 = & V_70 -> V_29 ;
V_32 -> V_29 . V_82 = V_70 -> V_29 . V_82 ;
F_34 ( V_32 , V_5 ) ;
V_20 = F_35 ( V_32 ) ;
if ( V_20 ) {
F_36 ( V_5 -> V_23 ) ;
return V_20 ;
}
F_37 ( & V_70 -> V_29 , L_5 ) ;
return 0 ;
}
static int F_38 ( struct V_69 * V_70 )
{
struct V_4 * V_5 = F_39 ( V_70 ) ;
F_40 ( & V_5 -> V_32 ) ;
F_36 ( V_5 -> V_23 ) ;
return 0 ;
}
