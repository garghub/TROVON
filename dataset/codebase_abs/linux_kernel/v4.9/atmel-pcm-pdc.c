static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 [ V_3 ] . V_5 ;
struct V_7 * V_8 = & V_5 -> V_9 ;
T_1 V_10 = V_11 ;
V_8 -> V_12 . type = V_13 ;
V_8 -> V_12 . V_12 = V_2 -> V_14 -> V_12 ;
V_8 -> V_15 = NULL ;
V_8 -> V_16 = F_2 ( V_2 -> V_14 -> V_12 , V_10 ,
& V_8 -> V_17 , V_18 ) ;
F_3 ( L_1 ,
( void * ) V_8 -> V_16 , ( void * ) ( long ) V_8 -> V_17 , V_10 ) ;
if ( ! V_8 -> V_16 )
return - V_19 ;
V_8 -> V_20 = V_10 ;
return 0 ;
}
static int F_4 ( struct V_4 * V_5 ,
struct V_21 * V_22 )
{
return F_5 ( V_22 , V_22 -> V_23 ,
V_5 -> V_9 . V_17 >> V_24 ,
V_22 -> V_25 - V_22 -> V_23 , V_22 -> V_26 ) ;
}
static int F_6 ( struct V_27 * V_28 )
{
struct V_29 * V_14 = V_28 -> V_14 -> V_29 ;
struct V_1 * V_2 = V_28 -> V_2 ;
int V_30 ;
V_30 = F_7 ( V_14 -> V_12 , F_8 ( 32 ) ) ;
if ( V_30 )
return V_30 ;
if ( V_2 -> V_6 [ V_31 ] . V_5 ) {
F_3 ( L_2 ) ;
V_30 = F_1 ( V_2 ,
V_31 ) ;
if ( V_30 )
goto V_32;
}
if ( V_2 -> V_6 [ V_33 ] . V_5 ) {
F_3 ( L_3 ) ;
V_30 = F_1 ( V_2 ,
V_33 ) ;
if ( V_30 )
goto V_32;
}
V_32:
return V_30 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_5 = V_2 -> V_6 [ V_3 ] . V_5 ;
if ( ! V_5 )
continue;
V_8 = & V_5 -> V_9 ;
if ( ! V_8 -> V_16 )
continue;
F_10 ( V_2 -> V_14 -> V_12 , V_8 -> V_20 ,
V_8 -> V_16 , V_8 -> V_17 ) ;
V_8 -> V_16 = NULL ;
}
}
static void F_11 ( T_2 V_34 ,
struct V_4 * V_5 )
{
struct V_35 * V_36 = V_5 -> V_37 -> V_15 ;
struct V_38 * V_39 = V_36 -> V_39 ;
static int V_40 ;
V_40 ++ ;
if ( V_34 & V_39 -> V_41 -> V_42 ) {
F_12 ( L_4 ,
V_5 -> V_3 == V_31
? L_5 : L_6 ,
V_39 -> V_43 , V_34 , V_40 ) ;
F_13 ( V_39 -> V_44 -> V_45 , V_46 ,
V_39 -> V_41 -> V_47 ) ;
V_36 -> V_48 += V_36 -> V_49 ;
if ( V_36 -> V_48 >= V_36 -> V_50 )
V_36 -> V_48 = V_36 -> V_9 ;
F_13 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_52 ,
V_36 -> V_48 ) ;
F_13 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_53 ,
V_36 -> V_49 / V_39 -> V_54 ) ;
F_13 ( V_39 -> V_44 -> V_45 , V_46 ,
V_39 -> V_41 -> V_55 ) ;
}
if ( V_34 & V_39 -> V_41 -> V_56 ) {
V_36 -> V_48 += V_36 -> V_49 ;
if ( V_36 -> V_48 >= V_36 -> V_50 )
V_36 -> V_48 = V_36 -> V_9 ;
F_13 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_57 ,
V_36 -> V_48 ) ;
F_13 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_58 ,
V_36 -> V_49 / V_39 -> V_54 ) ;
}
F_14 ( V_5 ) ;
}
static int F_15 ( struct V_4 * V_5 ,
struct V_59 * V_39 )
{
struct V_60 * V_37 = V_5 -> V_37 ;
struct V_35 * V_36 = V_37 -> V_15 ;
struct V_27 * V_28 = V_5 -> V_15 ;
F_16 ( V_5 , & V_5 -> V_9 ) ;
V_37 -> V_61 = F_17 ( V_39 ) ;
V_36 -> V_39 = F_18 ( V_28 -> V_62 , V_5 ) ;
V_36 -> V_39 -> V_63 = F_11 ;
V_36 -> V_9 = V_37 -> V_64 ;
V_36 -> V_50 = V_37 -> V_64 + V_37 -> V_61 ;
V_36 -> V_49 = F_19 ( V_39 ) ;
F_3 ( L_7
L_8
L_9 ,
V_36 -> V_39 -> V_43 ,
V_37 -> V_61 ,
V_36 -> V_49 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
struct V_35 * V_36 = V_5 -> V_37 -> V_15 ;
struct V_38 * V_39 = V_36 -> V_39 ;
if ( V_39 != NULL ) {
F_13 ( V_39 -> V_44 -> V_45 , V_65 ,
V_39 -> V_41 -> V_47 ) ;
V_36 -> V_39 -> V_63 = NULL ;
}
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
struct V_35 * V_36 = V_5 -> V_37 -> V_15 ;
struct V_38 * V_39 = V_36 -> V_39 ;
F_13 ( V_39 -> V_44 -> V_45 , V_66 ,
V_39 -> V_41 -> V_56 | V_39 -> V_41 -> V_42 ) ;
F_13 ( V_39 -> V_44 -> V_45 , V_46 ,
V_39 -> V_41 -> V_47 ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 ,
int V_67 )
{
struct V_60 * V_28 = V_5 -> V_37 ;
struct V_35 * V_36 = V_28 -> V_15 ;
struct V_38 * V_39 = V_36 -> V_39 ;
int V_30 = 0 ;
F_3 ( L_10
L_11 ,
V_28 -> V_68 , V_28 -> V_69 , V_28 -> V_61 ) ;
switch ( V_67 ) {
case V_70 :
V_36 -> V_48 = V_36 -> V_9 ;
F_13 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_52 ,
V_36 -> V_48 ) ;
F_13 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_53 ,
V_36 -> V_49 / V_39 -> V_54 ) ;
V_36 -> V_48 += V_36 -> V_49 ;
F_13 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_57 ,
V_36 -> V_48 ) ;
F_13 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_58 ,
V_36 -> V_49 / V_39 -> V_54 ) ;
F_3 ( L_12
L_13
L_14 ,
( unsigned long ) V_36 -> V_48 ,
F_23 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_52 ) ,
F_23 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_53 ) ,
F_23 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_57 ) ,
F_23 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_58 ) ) ;
F_13 ( V_39 -> V_44 -> V_45 , V_71 ,
V_39 -> V_41 -> V_56 | V_39 -> V_41 -> V_42 ) ;
F_13 ( V_39 -> V_44 -> V_45 , V_65 ,
V_39 -> V_41 -> V_55 ) ;
F_3 ( L_15 ,
F_23 ( V_39 -> V_44 -> V_45 , V_72 ) ,
F_23 ( V_39 -> V_44 -> V_45 , V_71 ) ) ;
break;
case V_73 :
case V_74 :
case V_75 :
F_13 ( V_39 -> V_44 -> V_45 , V_46 ,
V_39 -> V_41 -> V_47 ) ;
break;
case V_76 :
case V_77 :
F_13 ( V_39 -> V_44 -> V_45 , V_46 ,
V_39 -> V_41 -> V_55 ) ;
break;
default:
V_30 = - V_78 ;
}
return V_30 ;
}
static T_3 F_24 (
struct V_4 * V_5 )
{
struct V_60 * V_37 = V_5 -> V_37 ;
struct V_35 * V_36 = V_37 -> V_15 ;
struct V_38 * V_39 = V_36 -> V_39 ;
T_4 V_79 ;
T_3 V_80 ;
V_79 = ( T_4 ) F_23 ( V_39 -> V_44 -> V_45 , V_39 -> V_51 -> V_52 ) ;
V_80 = F_25 ( V_37 , V_79 - V_36 -> V_9 ) ;
if ( V_80 == V_37 -> V_68 )
V_80 = 0 ;
return V_80 ;
}
static int F_26 ( struct V_4 * V_5 )
{
struct V_60 * V_37 = V_5 -> V_37 ;
struct V_35 * V_36 ;
int V_30 = 0 ;
F_27 ( V_5 , & V_81 ) ;
V_30 = F_28 ( V_37 ,
V_82 ) ;
if ( V_30 < 0 )
goto V_32;
V_36 = F_29 ( sizeof( struct V_35 ) , V_18 ) ;
if ( V_36 == NULL ) {
V_30 = - V_19 ;
goto V_32;
}
V_37 -> V_15 = V_36 ;
V_32:
return V_30 ;
}
static int F_30 ( struct V_4 * V_5 )
{
struct V_35 * V_36 = V_5 -> V_37 -> V_15 ;
F_31 ( V_36 ) ;
return 0 ;
}
int F_32 ( struct V_83 * V_12 )
{
return F_33 ( V_12 , & V_84 ) ;
}
void F_34 ( struct V_83 * V_12 )
{
F_35 ( V_12 ) ;
}
