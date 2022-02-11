static T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
for ( V_3 = 1 ; V_3 < V_7 ; V_3 ++ ) {
V_4 = F_3 ( V_6 -> V_8 . V_9 [ V_3 ] ) ;
if ( F_4 ( V_4 ) )
V_3 ++ ;
if ( F_5 ( V_4 ) ) {
V_3 ++ ;
return V_6 -> V_8 . V_9 [ V_3 ] >> 4 ;
}
}
return V_10 ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_11 ;
struct V_12 * V_13 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_11 = F_7 ( V_2 , V_14 ,
V_15 , & V_13 ) ;
if ( V_11 < 0 )
return;
if ( V_13 -> V_16 <= V_7 ) {
memcpy ( V_6 -> V_8 . V_9 , V_13 -> V_17 , V_13 -> V_16 ) ;
V_6 -> V_8 . V_18 =
F_8 ( F_1 ( V_2 ) ) ;
}
F_9 ( V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_19 ,
T_1 V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_11 , V_3 ;
struct V_12 * V_21 ;
T_1 V_22 , V_23 ;
switch ( V_19 ) {
case V_24 :
V_22 = ( V_20 == V_25 ?
V_26 :
V_27 ) ;
V_6 -> V_8 . V_28 = 0 ;
V_6 -> V_8 . V_29 = V_30 ;
break;
case V_31 :
V_22 = ( V_20 == V_25 ?
V_32 :
V_33 ) ;
V_6 -> V_8 . V_28 = 0 ;
V_6 -> V_8 . V_29 = V_34 ;
break;
default:
return - V_35 ;
}
F_11 ( & V_6 -> V_8 . V_36 ) ;
V_11 = F_12 ( V_2 , V_37 , V_22 ,
NULL , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
F_13 ( & V_6 -> V_8 . V_38 , V_39 +
F_14 ( V_40 ) ) ;
V_6 -> V_8 . V_41 = true ;
F_15 ( & V_6 -> V_8 . V_36 ) ;
V_11 = F_7 ( V_2 , V_42 ,
V_43 ,
& V_21 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_3 = 0 ; V_3 < V_21 -> V_16 &&
V_21 -> V_17 [ V_3 ] != V_19 ; V_3 ++ )
;
V_23 = V_21 -> V_17 [ V_3 ] ;
F_9 ( V_21 ) ;
if ( V_20 == V_25 && V_23 == V_19 )
return V_19 ;
else if ( V_20 == V_44 && V_23 != V_19 )
return V_19 ;
return - 1 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_45 = 0 ;
if ( F_17 ( V_46 , & V_2 -> V_47 ) )
return 0 ;
if ( V_6 -> V_48 -> V_49 ) {
F_18 ( V_2 -> V_50 , V_24 , V_51 ) ;
V_45 ++ ;
}
if ( V_6 -> V_48 -> V_52 ) {
F_18 ( V_2 -> V_50 , V_31 , V_53 ) ;
V_45 ++ ;
}
return ! V_45 ;
}
int F_19 ( struct V_1 * V_2 , T_2 V_19 )
{
int V_11 ;
V_11 = F_10 ( V_2 , V_19 , V_25 ) ;
if ( V_11 == V_31 ) {
F_6 ( V_2 ) ;
V_11 = F_12 ( V_2 , V_14 ,
V_54 , NULL , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
} else if ( V_11 < 0 ) {
F_20 ( V_2 -> V_50 , V_19 ) ;
return V_11 ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 , T_2 V_19 )
{
int V_11 ;
V_11 = F_10 ( V_2 , V_19 , V_44 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , T_2 V_19 ,
T_1 * V_55 , T_3 V_56 ,
T_4 V_57 , void * V_58 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_23 ( L_1 , V_19 ) ;
switch ( V_19 ) {
case V_31 :
V_6 -> V_8 . V_57 = V_57 ;
V_6 -> V_8 . V_58 = V_58 ;
F_13 ( & V_6 -> V_8 . V_59 , V_39 +
F_14 ( V_6 -> V_8 . V_18 ) ) ;
V_6 -> V_8 . V_60 = true ;
return F_12 ( V_2 , V_14 ,
V_61 ,
V_55 , V_56 ) ;
default:
return - V_62 ;
}
}
static void F_24 ( unsigned long V_17 )
{
T_1 V_63 = 0x01 ;
struct V_5 * V_6 = (struct V_5 * ) V_17 ;
F_23 ( L_2 ) ;
V_6 -> V_8 . V_60 = false ;
if ( ! V_6 -> V_8 . V_64 ) {
V_6 -> V_8 . V_64 = true ;
F_12 ( V_6 -> V_2 , V_14 ,
V_54 , NULL , 0 ) ;
} else {
V_6 -> V_8 . V_64 = false ;
F_12 ( V_6 -> V_2 , V_37 ,
V_65 , & V_63 , 1 ) ;
}
V_6 -> V_8 . V_57 ( V_6 -> V_8 . V_58 , NULL , 0 , - V_66 ) ;
}
static void F_25 ( unsigned long V_17 )
{
struct V_5 * V_6 = (struct V_5 * ) V_17 ;
F_23 ( L_2 ) ;
V_6 -> V_8 . V_41 = false ;
F_26 ( & V_6 -> V_8 . V_36 ) ;
}
int F_27 ( struct V_1 * V_2 , T_1 V_67 ,
T_1 V_68 , struct V_12 * V_13 )
{
int V_11 = 0 ;
struct V_69 * V_70 = & V_2 -> V_50 -> V_70 ;
struct V_71 * V_72 ;
F_23 ( L_3 , V_68 ) ;
switch ( V_68 ) {
case V_73 :
V_11 = F_28 ( V_2 -> V_50 , V_67 ) ;
break;
case V_74 :
if ( V_13 -> V_16 < V_75 + 2 &&
V_13 -> V_17 [ 0 ] != V_76 )
return - V_77 ;
V_72 = (struct V_71 * ) F_29 ( V_70 ,
V_13 -> V_16 - 2 , V_78 ) ;
V_72 -> V_79 = V_13 -> V_17 [ 1 ] ;
memcpy ( V_72 -> V_80 , & V_13 -> V_17 [ 2 ] ,
V_72 -> V_79 ) ;
if ( V_13 -> V_17 [ V_72 -> V_79 + 2 ] !=
V_81 )
return - V_77 ;
V_72 -> V_82 = V_13 -> V_17 [ V_72 -> V_79 + 3 ] ;
memcpy ( V_72 -> V_83 , V_13 -> V_17 +
V_72 -> V_79 + 4 , V_72 -> V_82 ) ;
V_11 = F_30 ( V_2 -> V_50 , V_67 , V_72 ) ;
break;
default:
F_31 ( & V_2 -> V_50 -> V_70 , L_4 ) ;
return 1 ;
}
F_9 ( V_13 ) ;
return V_11 ;
}
int F_32 ( struct V_1 * V_2 ,
T_1 V_68 , struct V_12 * V_13 )
{
int V_11 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_23 ( L_5 , V_68 ) ;
switch ( V_68 ) {
case V_61 :
F_33 ( & V_6 -> V_8 . V_59 ) ;
V_6 -> V_8 . V_60 = false ;
V_11 = F_12 ( V_2 , V_37 ,
V_84 , NULL , 0 ) ;
if ( V_11 < 0 )
goto exit;
V_6 -> V_8 . V_57 ( V_6 -> V_8 . V_58 ,
V_13 -> V_17 , V_13 -> V_16 , 0 ) ;
break;
case V_85 :
F_13 ( & V_6 -> V_8 . V_59 , V_39 +
F_14 ( V_6 -> V_8 . V_18 ) ) ;
break;
default:
F_31 ( & V_2 -> V_50 -> V_70 , L_6 ) ;
return 1 ;
}
exit:
F_9 ( V_13 ) ;
return V_11 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_35 ( & V_6 -> V_8 . V_36 ) ;
F_36 ( & V_6 -> V_8 . V_59 ) ;
V_6 -> V_8 . V_59 . V_17 = ( unsigned long ) V_6 ;
V_6 -> V_8 . V_59 . V_86 = F_24 ;
V_6 -> V_8 . V_60 = false ;
F_36 ( & V_6 -> V_8 . V_38 ) ;
V_6 -> V_8 . V_38 . V_17 = ( unsigned long ) V_6 ;
V_6 -> V_8 . V_38 . V_86 = F_25 ;
V_6 -> V_8 . V_41 = false ;
V_6 -> V_8 . V_28 = 0 ;
V_6 -> V_8 . V_29 = 0 ;
V_6 -> V_8 . V_64 = false ;
V_6 -> V_8 . V_18 =
F_8 ( V_10 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_8 . V_60 )
F_33 ( & V_6 -> V_8 . V_59 ) ;
if ( V_6 -> V_8 . V_41 )
F_33 ( & V_6 -> V_8 . V_38 ) ;
V_6 -> V_8 . V_60 = false ;
V_6 -> V_8 . V_41 = false ;
}
