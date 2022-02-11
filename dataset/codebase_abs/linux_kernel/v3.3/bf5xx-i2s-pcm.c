static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 ) ;
}
static int F_3 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
T_1 V_7 = V_8 . V_9 ;
F_4 ( V_4 , V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_4 )
{
F_6 ( V_4 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_15 = F_8 ( V_11 , V_11 -> V_16 ) ;
F_9 ( L_1 , V_17 ) ;
if ( V_4 -> V_18 == V_19 ) {
F_10 ( V_13 , F_1 , V_4 ) ;
F_11 ( V_13 , V_11 -> V_20 ,
V_11 -> V_21 , V_15 ) ;
} else {
F_12 ( V_13 , F_1 , V_4 ) ;
F_13 ( V_13 , V_11 -> V_20 ,
V_11 -> V_21 , V_15 ) ;
}
return 0 ;
}
static int F_14 ( struct V_2 * V_4 , int V_22 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_23 = 0 ;
F_9 ( L_1 , V_17 ) ;
switch ( V_22 ) {
case V_24 :
if ( V_4 -> V_18 == V_19 )
F_15 ( V_13 ) ;
else
F_16 ( V_13 ) ;
break;
case V_25 :
case V_26 :
case V_27 :
if ( V_4 -> V_18 == V_19 )
F_17 ( V_13 ) ;
else
F_18 ( V_13 ) ;
break;
default:
V_23 = - V_28 ;
}
return V_23 ;
}
static T_2 F_19 ( struct V_2 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
unsigned int V_29 ;
T_2 V_30 ;
F_9 ( L_1 , V_17 ) ;
if ( V_4 -> V_18 == V_19 ) {
V_29 = F_20 ( V_13 ) ;
} else {
V_29 = F_21 ( V_13 ) ;
}
if ( V_29 == F_22 ( V_4 ) )
V_29 = 0 ;
V_30 = F_23 ( V_4 -> V_11 , V_29 ) ;
return V_30 ;
}
static int F_24 ( struct V_2 * V_4 )
{
struct V_31 * V_32 = V_4 -> V_14 ;
struct V_33 * V_34 = V_32 -> V_34 ;
struct V_12 * V_35 = F_25 ( V_34 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_36 * V_37 = & V_4 -> V_38 ;
int V_23 ;
F_9 ( L_1 , V_17 ) ;
F_26 ( V_4 , & V_8 ) ;
V_23 = F_27 ( V_11 ,
V_39 ) ;
if ( V_23 < 0 )
goto V_40;
if ( V_35 != NULL ) {
if ( V_4 -> V_18 == V_19 )
V_35 -> V_41 = V_37 -> V_42 ;
else
V_35 -> V_43 = V_37 -> V_42 ;
V_11 -> V_14 = V_35 ;
} else {
F_28 ( L_2 ) ;
return - 1 ;
}
return 0 ;
V_40:
return V_23 ;
}
static int F_29 ( struct V_2 * V_4 ,
struct V_44 * V_45 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
T_1 V_7 = V_45 -> V_46 - V_45 -> V_47 ;
V_45 -> V_47 = ( unsigned long ) V_11 -> V_20 ;
V_45 -> V_46 = V_45 -> V_47 + V_7 ;
V_45 -> V_48 |= V_49 ;
return 0 ;
}
static int F_30 ( struct V_50 * V_3 , int V_18 )
{
struct V_2 * V_4 = V_3 -> V_51 [ V_18 ] . V_4 ;
struct V_36 * V_37 = & V_4 -> V_38 ;
T_1 V_7 = V_8 . V_9 ;
V_37 -> V_52 . type = V_53 ;
V_37 -> V_52 . V_52 = V_3 -> V_54 -> V_52 ;
V_37 -> V_14 = NULL ;
V_37 -> V_42 = F_31 ( V_3 -> V_54 -> V_52 , V_7 ,
& V_37 -> V_55 , V_56 ) ;
if ( ! V_37 -> V_42 ) {
F_28 ( L_3 ) ;
return - V_57 ;
}
V_37 -> V_58 = V_7 ;
F_9 ( L_4 , V_17 ,
V_37 -> V_42 , V_37 -> V_58 ) ;
return 0 ;
}
static void F_32 ( struct V_50 * V_3 )
{
struct V_2 * V_4 ;
struct V_36 * V_37 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ ) {
V_4 = V_3 -> V_51 [ V_18 ] . V_4 ;
if ( ! V_4 )
continue;
V_37 = & V_4 -> V_38 ;
if ( ! V_37 -> V_42 )
continue;
F_33 ( NULL , V_37 -> V_58 , V_37 -> V_42 , 0 ) ;
V_37 -> V_42 = NULL ;
}
}
static int F_34 ( struct V_31 * V_32 )
{
struct V_59 * V_54 = V_32 -> V_54 -> V_59 ;
struct V_50 * V_3 = V_32 -> V_3 ;
int V_23 = 0 ;
F_9 ( L_1 , V_17 ) ;
if ( ! V_54 -> V_52 -> V_60 )
V_54 -> V_52 -> V_60 = & V_61 ;
if ( ! V_54 -> V_52 -> V_62 )
V_54 -> V_52 -> V_62 = F_35 ( 32 ) ;
if ( V_3 -> V_51 [ V_19 ] . V_4 ) {
V_23 = F_30 ( V_3 ,
V_19 ) ;
if ( V_23 )
goto V_40;
}
if ( V_3 -> V_51 [ V_63 ] . V_4 ) {
V_23 = F_30 ( V_3 ,
V_63 ) ;
if ( V_23 )
goto V_40;
}
V_40:
return V_23 ;
}
static int T_3 F_36 ( struct V_64 * V_65 )
{
return F_37 ( & V_65 -> V_52 , & V_66 ) ;
}
static int T_4 F_38 ( struct V_64 * V_65 )
{
F_39 ( & V_65 -> V_52 ) ;
return 0 ;
}
