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
int V_11 ;
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
V_23 = V_21 -> V_17 [ V_21 -> V_16 - 1 ] ;
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
if ( V_6 -> V_46 -> V_47 ) {
F_17 ( V_2 -> V_48 , V_24 , V_49 ) ;
V_45 ++ ;
}
if ( V_6 -> V_46 -> V_50 ) {
F_17 ( V_2 -> V_48 , V_31 , V_51 ) ;
V_45 ++ ;
}
return ! V_45 ;
}
int F_18 ( struct V_1 * V_2 , T_2 V_19 )
{
int V_11 ;
V_11 = F_10 ( V_2 , V_19 , V_25 ) ;
if ( V_11 == V_31 ) {
F_6 ( V_2 ) ;
V_11 = F_12 ( V_2 , V_14 ,
V_52 , NULL , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
} else if ( V_11 < 0 ) {
F_19 ( V_2 -> V_48 , V_19 ) ;
return V_11 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 , T_2 V_19 )
{
int V_11 ;
V_11 = F_10 ( V_2 , V_19 , V_44 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , T_2 V_19 ,
T_1 * V_53 , T_3 V_54 ,
T_4 V_55 , void * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_22 ( L_1 , V_19 ) ;
switch ( V_19 ) {
case V_31 :
V_6 -> V_8 . V_55 = V_55 ;
V_6 -> V_8 . V_56 = V_56 ;
F_13 ( & V_6 -> V_8 . V_57 , V_39 +
F_14 ( V_6 -> V_8 . V_18 ) ) ;
V_6 -> V_8 . V_58 = true ;
return F_12 ( V_2 , V_14 ,
V_59 ,
V_53 , V_54 ) ;
default:
return - V_60 ;
}
}
static void F_23 ( unsigned long V_17 )
{
T_1 V_61 = 0x01 ;
struct V_5 * V_6 = (struct V_5 * ) V_17 ;
F_22 ( L_2 ) ;
V_6 -> V_8 . V_58 = false ;
if ( ! V_6 -> V_8 . V_62 ) {
V_6 -> V_8 . V_62 = true ;
F_12 ( V_6 -> V_2 , V_14 ,
V_52 , NULL , 0 ) ;
} else {
V_6 -> V_8 . V_62 = false ;
F_12 ( V_6 -> V_2 , V_37 ,
V_63 , & V_61 , 1 ) ;
}
V_6 -> V_8 . V_55 ( V_6 -> V_8 . V_56 , NULL , 0 , - V_64 ) ;
}
static void F_24 ( unsigned long V_17 )
{
struct V_5 * V_6 = (struct V_5 * ) V_17 ;
F_22 ( L_2 ) ;
V_6 -> V_8 . V_41 = false ;
F_25 ( & V_6 -> V_8 . V_36 ) ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_65 ,
T_1 V_66 , struct V_12 * V_13 )
{
int V_11 = 0 ;
struct V_67 * V_68 = & V_2 -> V_48 -> V_68 ;
struct V_69 * V_70 ;
F_22 ( L_3 , V_66 ) ;
switch ( V_66 ) {
case V_71 :
break;
case V_72 :
if ( V_13 -> V_16 < V_73 + 2 &&
V_13 -> V_17 [ 0 ] != V_74 )
return - V_75 ;
V_70 = (struct V_69 * ) F_27 ( V_68 ,
V_13 -> V_16 - 2 , V_76 ) ;
V_70 -> V_77 = V_13 -> V_17 [ 1 ] ;
memcpy ( V_70 -> V_78 , & V_13 -> V_17 [ 2 ] ,
V_70 -> V_77 ) ;
if ( V_13 -> V_17 [ V_70 -> V_77 + 2 ] !=
V_79 )
return - V_75 ;
V_70 -> V_80 = V_13 -> V_17 [ V_70 -> V_77 + 3 ] ;
memcpy ( V_70 -> V_81 , V_13 -> V_17 +
V_70 -> V_77 + 4 , V_70 -> V_80 ) ;
V_11 = F_28 ( V_2 -> V_48 , V_65 , V_70 ) ;
break;
default:
return 1 ;
}
F_9 ( V_13 ) ;
return V_11 ;
}
int F_29 ( struct V_1 * V_2 ,
T_1 V_66 , struct V_12 * V_13 )
{
int V_11 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_22 ( L_4 , V_66 ) ;
switch ( V_66 ) {
case V_59 :
F_30 ( & V_6 -> V_8 . V_57 ) ;
V_6 -> V_8 . V_58 = false ;
V_11 = F_12 ( V_2 , V_37 ,
V_82 , NULL , 0 ) ;
if ( V_11 < 0 )
goto exit;
V_6 -> V_8 . V_55 ( V_6 -> V_8 . V_56 ,
V_13 -> V_17 , V_13 -> V_16 , 0 ) ;
break;
case V_83 :
F_13 ( & V_6 -> V_8 . V_57 , V_39 +
F_14 ( V_6 -> V_8 . V_18 ) ) ;
break;
}
exit:
F_9 ( V_13 ) ;
return V_11 ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_32 ( & V_6 -> V_8 . V_36 ) ;
F_33 ( & V_6 -> V_8 . V_57 ) ;
V_6 -> V_8 . V_57 . V_17 = ( unsigned long ) V_6 ;
V_6 -> V_8 . V_57 . V_84 = F_23 ;
V_6 -> V_8 . V_58 = false ;
F_33 ( & V_6 -> V_8 . V_38 ) ;
V_6 -> V_8 . V_38 . V_17 = ( unsigned long ) V_6 ;
V_6 -> V_8 . V_38 . V_84 = F_24 ;
V_6 -> V_8 . V_41 = false ;
V_6 -> V_8 . V_28 = 0 ;
V_6 -> V_8 . V_29 = 0 ;
V_6 -> V_8 . V_62 = false ;
V_6 -> V_8 . V_18 =
F_8 ( V_10 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_8 . V_58 )
F_30 ( & V_6 -> V_8 . V_57 ) ;
if ( V_6 -> V_8 . V_41 )
F_30 ( & V_6 -> V_8 . V_38 ) ;
V_6 -> V_8 . V_58 = false ;
V_6 -> V_8 . V_41 = false ;
}
