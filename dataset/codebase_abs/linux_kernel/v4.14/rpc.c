void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_3 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_7 V_8 ;
if ( V_6 -> V_9 != 1 )
goto V_10;
if ( ( V_6 -> V_11 [ 0 ] . V_12 & V_13 ) !=
V_14 )
goto V_10;
F_7 ( & V_8 ) ;
V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_17 = V_8 . V_18 ;
V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_19 = V_8 . V_20 ;
V_6 -> V_21 = V_22 ;
return;
V_10:
V_6 -> V_21 = V_23 ;
}
static struct V_24 * F_8 ( struct V_1 * V_25 , T_1 V_26 )
{
struct V_24 * V_27 ;
F_9 ( & V_25 -> V_3 ) ;
F_10 (w, &wq->db, link)
if ( V_27 -> V_26 == V_26 )
goto V_28;
V_27 = F_11 ( sizeof( * V_27 ) , V_29 ) ;
if ( V_27 ) {
F_12 ( & V_27 -> V_30 ) ;
V_27 -> V_26 = V_26 ;
F_13 ( & V_27 -> V_31 , & V_25 -> V_4 ) ;
}
V_28:
F_14 ( & V_25 -> V_3 ) ;
return V_27 ;
}
static void F_15 ( struct V_1 * V_25 , T_1 V_26 )
{
struct V_24 * V_27 = F_8 ( V_25 , V_26 ) ;
if ( V_27 ) {
F_16 ( & V_27 -> V_30 ) ;
F_9 ( & V_25 -> V_3 ) ;
F_17 ( & V_27 -> V_31 ) ;
F_14 ( & V_25 -> V_3 ) ;
F_18 ( V_27 ) ;
}
}
static void F_19 ( struct V_1 * V_25 , T_1 V_26 )
{
struct V_24 * V_27 = F_8 ( V_25 , V_26 ) ;
if ( V_27 )
F_20 ( & V_27 -> V_30 ) ;
}
static void F_21 ( struct V_32 * V_32 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_9 != 1 )
goto V_10;
if ( ( V_6 -> V_11 [ 0 ] . V_12 & V_13 ) !=
V_33 )
goto V_10;
switch ( V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_17 ) {
case V_34 :
F_15 ( & V_32 -> V_35 , V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_19 ) ;
break;
case V_36 :
F_19 ( & V_32 -> V_35 , V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_19 ) ;
break;
default:
goto V_10;
}
V_6 -> V_21 = V_22 ;
return;
V_10:
V_6 -> V_21 = V_23 ;
}
static void F_22 ( struct V_5 * V_6 )
{
T_1 V_37 ;
if ( V_6 -> V_9 != 1 )
goto V_10;
if ( ( V_6 -> V_11 [ 0 ] . V_12 & V_13 ) !=
V_33 )
goto V_10;
V_37 = V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_17 ;
F_23 ( V_37 ) ;
V_6 -> V_21 = V_22 ;
return;
V_10:
V_6 -> V_21 = V_23 ;
}
static void F_24 ( struct V_38 * V_39 ,
struct V_5 * V_6 )
{
struct V_40 * V_11 ;
V_6 -> V_41 = V_42 ;
V_11 = F_25 ( V_6 -> V_9 , sizeof( struct V_40 ) ,
V_29 ) ;
if ( ! V_11 ) {
V_6 -> V_21 = V_43 ;
return;
}
if ( F_26 ( V_11 , V_6 -> V_9 , V_6 -> V_11 ) ) {
V_6 -> V_21 = V_23 ;
goto V_28;
}
V_6 -> V_21 = F_27 ( V_39 , V_6 -> V_44 , V_6 -> V_9 , V_11 ) ;
if ( F_28 ( V_6 -> V_11 , V_6 -> V_9 , V_11 ) )
V_6 -> V_21 = V_23 ;
V_28:
F_18 ( V_11 ) ;
}
static struct V_45 * F_29 ( struct V_38 * V_39 , T_2 V_46 )
{
T_1 V_21 ;
struct V_40 V_47 ;
struct V_32 * V_32 = F_30 ( V_39 -> V_48 ) ;
struct V_45 * V_49 ;
V_47 . V_12 = V_50 ;
V_47 . V_15 . V_16 . V_17 = V_51 ;
V_47 . V_15 . V_16 . V_19 = V_46 ;
V_47 . V_15 . V_16 . V_30 = 0 ;
V_21 = F_27 ( V_39 , V_52 , 1 , & V_47 ) ;
if ( V_21 )
return F_31 ( - V_53 ) ;
F_9 ( & V_32 -> V_54 . V_55 ) ;
V_49 = F_32 ( V_32 -> V_54 . V_39 , V_47 . V_15 . V_16 . V_30 ) ;
F_14 ( & V_32 -> V_54 . V_55 ) ;
return V_49 ;
}
static void F_33 ( struct V_38 * V_39 ,
struct V_5 * V_6 )
{
T_3 V_56 ;
struct V_45 * V_49 ;
T_2 V_46 ;
T_2 V_57 ;
V_6 -> V_41 = V_42 ;
if ( ! V_6 -> V_9 ||
V_6 -> V_11 [ 0 ] . V_12 != V_33 ) {
V_6 -> V_21 = V_23 ;
return;
}
for ( V_57 = 1 ; V_57 < V_6 -> V_9 ; V_57 ++ ) {
if ( V_6 -> V_11 [ V_57 ] . V_12 != V_58 ) {
V_6 -> V_21 = V_23 ;
return;
}
}
V_46 = V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_19 ;
switch ( V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_17 ) {
case V_51 :
V_49 = F_29 ( V_39 , V_46 ) ;
break;
case V_59 :
V_49 = F_34 ( V_39 , V_46 , V_60 ) ;
break;
default:
V_6 -> V_21 = V_23 ;
return;
}
if ( F_35 ( V_49 ) ) {
V_6 -> V_21 = V_43 ;
return;
}
if ( F_36 ( V_49 , 0 , & V_56 ) ) {
V_6 -> V_21 = V_23 ;
goto V_10;
}
V_6 -> V_11 [ 0 ] . V_12 = V_61 ;
V_6 -> V_11 [ 0 ] . V_15 . V_62 . V_63 = V_56 ;
V_6 -> V_11 [ 0 ] . V_15 . V_62 . V_64 = V_46 ;
V_6 -> V_11 [ 0 ] . V_15 . V_62 . V_65 = ( unsigned long ) V_49 ;
V_6 -> V_21 = V_22 ;
return;
V_10:
F_37 ( V_49 ) ;
}
static void F_38 ( struct V_38 * V_39 , struct V_45 * V_49 )
{
struct V_40 V_47 ;
V_47 . V_12 = V_50 ;
V_47 . V_15 . V_16 . V_17 = V_51 ;
V_47 . V_15 . V_16 . V_19 = F_39 ( V_49 ) ;
V_47 . V_15 . V_16 . V_30 = 0 ;
F_40 ( V_49 ) ;
F_27 ( V_39 , V_66 , 1 , & V_47 ) ;
}
static void F_41 ( struct V_38 * V_39 ,
struct V_5 * V_6 )
{
struct V_45 * V_49 ;
V_6 -> V_41 = V_42 ;
if ( V_6 -> V_9 != 1 ||
V_6 -> V_11 [ 0 ] . V_12 != V_33 ) {
V_6 -> V_21 = V_23 ;
return;
}
V_49 = (struct V_45 * ) ( unsigned long ) V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_19 ;
switch ( V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_17 ) {
case V_51 :
F_38 ( V_39 , V_49 ) ;
break;
case V_59 :
F_37 ( V_49 ) ;
break;
default:
V_6 -> V_21 = V_23 ;
}
V_6 -> V_21 = V_22 ;
}
static void F_42 ( struct V_38 * V_39 , struct V_32 * V_32 ,
struct V_45 * V_49 )
{
struct V_5 * V_6 ;
V_6 = F_43 ( V_49 , 0 ) ;
if ( F_35 ( V_6 ) ) {
F_44 ( L_1 , V_67 , V_49 ) ;
return;
}
switch ( V_6 -> V_44 ) {
case V_68 :
F_6 ( V_6 ) ;
break;
case V_69 :
F_21 ( V_32 , V_6 ) ;
break;
case V_70 :
F_22 ( V_6 ) ;
break;
case V_52 :
F_33 ( V_39 , V_6 ) ;
break;
case V_66 :
F_41 ( V_39 , V_6 ) ;
break;
default:
F_24 ( V_39 , V_6 ) ;
}
}
void F_45 ( struct V_38 * V_39 , struct V_71 * V_47 )
{
struct V_72 * V_48 = V_39 -> V_48 ;
struct V_32 * V_32 = F_30 ( V_48 ) ;
struct V_45 * V_49 ;
T_3 V_56 ;
switch ( F_46 ( V_47 -> V_73 ) ) {
case V_74 :
V_49 = F_34 ( V_39 , V_47 -> V_75 , V_60 ) ;
if ( ! F_35 ( V_49 ) && ! F_36 ( V_49 , 0 , & V_56 ) ) {
F_47 ( & V_47 -> V_75 , & V_47 -> V_76 , V_56 ) ;
F_47 ( & V_47 -> V_77 , & V_47 -> V_78 ,
( unsigned long ) V_49 ) ;
} else {
V_47 -> V_75 = 0 ;
V_47 -> V_76 = 0 ;
V_47 -> V_77 = 0 ;
V_47 -> V_78 = 0 ;
}
break;
case V_79 :
V_49 = F_48 ( V_47 -> V_75 , V_47 -> V_76 ) ;
F_37 ( V_49 ) ;
break;
case V_80 :
break;
case V_81 :
V_49 = F_48 ( V_47 -> V_75 , V_47 -> V_76 ) ;
F_42 ( V_39 , V_32 , V_49 ) ;
break;
default:
F_49 ( L_2 ,
( T_1 ) F_46 ( V_47 -> V_73 ) ) ;
break;
}
V_47 -> V_73 = V_82 ;
}
