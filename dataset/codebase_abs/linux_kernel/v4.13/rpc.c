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
F_23 ( V_38 ) ;
F_24 ( V_37 ) ;
V_6 -> V_21 = V_22 ;
return;
V_10:
V_6 -> V_21 = V_23 ;
}
static void F_25 ( struct V_39 * V_40 ,
struct V_5 * V_6 )
{
struct V_41 * V_11 ;
V_6 -> V_42 = V_43 ;
V_11 = F_26 ( V_6 -> V_9 , sizeof( struct V_41 ) ,
V_29 ) ;
if ( ! V_11 ) {
V_6 -> V_21 = V_44 ;
return;
}
if ( F_27 ( V_11 , V_6 -> V_9 , V_6 -> V_11 ) ) {
V_6 -> V_21 = V_23 ;
goto V_28;
}
V_6 -> V_21 = F_28 ( V_40 , V_6 -> V_45 , V_6 -> V_9 , V_11 ) ;
if ( F_29 ( V_6 -> V_11 , V_6 -> V_9 , V_11 ) )
V_6 -> V_21 = V_23 ;
V_28:
F_18 ( V_11 ) ;
}
static struct V_46 * F_30 ( struct V_39 * V_40 , T_2 V_47 )
{
T_1 V_21 ;
struct V_41 V_48 ;
struct V_32 * V_32 = F_31 ( V_40 -> V_49 ) ;
struct V_46 * V_50 ;
V_48 . V_12 = V_51 ;
V_48 . V_15 . V_16 . V_17 = V_52 ;
V_48 . V_15 . V_16 . V_19 = V_47 ;
V_48 . V_15 . V_16 . V_30 = 0 ;
V_21 = F_28 ( V_40 , V_53 , 1 , & V_48 ) ;
if ( V_21 )
return F_32 ( - V_54 ) ;
F_9 ( & V_32 -> V_55 . V_56 ) ;
V_50 = F_33 ( V_32 -> V_55 . V_40 , V_48 . V_15 . V_16 . V_30 ) ;
F_14 ( & V_32 -> V_55 . V_56 ) ;
return V_50 ;
}
static void F_34 ( struct V_39 * V_40 ,
struct V_5 * V_6 )
{
T_3 V_57 ;
struct V_46 * V_50 ;
T_2 V_47 ;
T_2 V_58 ;
V_6 -> V_42 = V_43 ;
if ( ! V_6 -> V_9 ||
V_6 -> V_11 [ 0 ] . V_12 != V_33 ) {
V_6 -> V_21 = V_23 ;
return;
}
for ( V_58 = 1 ; V_58 < V_6 -> V_9 ; V_58 ++ ) {
if ( V_6 -> V_11 [ V_58 ] . V_12 != V_59 ) {
V_6 -> V_21 = V_23 ;
return;
}
}
V_47 = V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_19 ;
switch ( V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_17 ) {
case V_52 :
V_50 = F_30 ( V_40 , V_47 ) ;
break;
case V_60 :
V_50 = F_35 ( V_40 , V_47 , V_61 ) ;
break;
default:
V_6 -> V_21 = V_23 ;
return;
}
if ( F_36 ( V_50 ) ) {
V_6 -> V_21 = V_44 ;
return;
}
if ( F_37 ( V_50 , 0 , & V_57 ) ) {
V_6 -> V_21 = V_23 ;
goto V_10;
}
V_6 -> V_11 [ 0 ] . V_12 = V_62 ;
V_6 -> V_11 [ 0 ] . V_15 . V_63 . V_64 = V_57 ;
V_6 -> V_11 [ 0 ] . V_15 . V_63 . V_65 = V_47 ;
V_6 -> V_11 [ 0 ] . V_15 . V_63 . V_66 = ( unsigned long ) V_50 ;
V_6 -> V_21 = V_22 ;
return;
V_10:
F_38 ( V_50 ) ;
}
static void F_39 ( struct V_39 * V_40 , struct V_46 * V_50 )
{
struct V_41 V_48 ;
V_48 . V_12 = V_51 ;
V_48 . V_15 . V_16 . V_17 = V_52 ;
V_48 . V_15 . V_16 . V_19 = F_40 ( V_50 ) ;
V_48 . V_15 . V_16 . V_30 = 0 ;
F_41 ( V_50 ) ;
F_28 ( V_40 , V_67 , 1 , & V_48 ) ;
}
static void F_42 ( struct V_39 * V_40 ,
struct V_5 * V_6 )
{
struct V_46 * V_50 ;
V_6 -> V_42 = V_43 ;
if ( V_6 -> V_9 != 1 ||
V_6 -> V_11 [ 0 ] . V_12 != V_33 ) {
V_6 -> V_21 = V_23 ;
return;
}
V_50 = (struct V_46 * ) ( unsigned long ) V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_19 ;
switch ( V_6 -> V_11 [ 0 ] . V_15 . V_16 . V_17 ) {
case V_52 :
F_39 ( V_40 , V_50 ) ;
break;
case V_60 :
F_38 ( V_50 ) ;
break;
default:
V_6 -> V_21 = V_23 ;
}
V_6 -> V_21 = V_22 ;
}
static void F_43 ( struct V_39 * V_40 , struct V_32 * V_32 ,
struct V_46 * V_50 )
{
struct V_5 * V_6 ;
V_6 = F_44 ( V_50 , 0 ) ;
if ( F_36 ( V_6 ) ) {
F_45 ( L_1 , V_68 , V_50 ) ;
return;
}
switch ( V_6 -> V_45 ) {
case V_69 :
F_6 ( V_6 ) ;
break;
case V_70 :
F_21 ( V_32 , V_6 ) ;
break;
case V_71 :
F_22 ( V_6 ) ;
break;
case V_53 :
F_34 ( V_40 , V_6 ) ;
break;
case V_67 :
F_42 ( V_40 , V_6 ) ;
break;
default:
F_25 ( V_40 , V_6 ) ;
}
}
void F_46 ( struct V_39 * V_40 , struct V_72 * V_48 )
{
struct V_73 * V_49 = V_40 -> V_49 ;
struct V_32 * V_32 = F_31 ( V_49 ) ;
struct V_46 * V_50 ;
T_3 V_57 ;
switch ( F_47 ( V_48 -> V_74 ) ) {
case V_75 :
V_50 = F_35 ( V_40 , V_48 -> V_76 , V_61 ) ;
if ( ! F_36 ( V_50 ) && ! F_37 ( V_50 , 0 , & V_57 ) ) {
F_48 ( & V_48 -> V_76 , & V_48 -> V_77 , V_57 ) ;
F_48 ( & V_48 -> V_78 , & V_48 -> V_79 ,
( unsigned long ) V_50 ) ;
} else {
V_48 -> V_76 = 0 ;
V_48 -> V_77 = 0 ;
V_48 -> V_78 = 0 ;
V_48 -> V_79 = 0 ;
}
break;
case V_80 :
V_50 = F_49 ( V_48 -> V_76 , V_48 -> V_77 ) ;
F_38 ( V_50 ) ;
break;
case V_81 :
break;
case V_82 :
V_50 = F_49 ( V_48 -> V_76 , V_48 -> V_77 ) ;
F_43 ( V_40 , V_32 , V_50 ) ;
break;
default:
F_50 ( L_2 ,
( T_1 ) F_47 ( V_48 -> V_74 ) ) ;
break;
}
V_48 -> V_74 = V_83 ;
}
