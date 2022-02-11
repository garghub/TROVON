static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , V_6 ,
F_4 ( V_4 -> V_7 ) , F_4 ( V_4 -> V_7 ) ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , V_6 ,
F_4 ( V_4 -> V_7 ) , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_8 ;
F_7 ( V_4 -> V_5 , V_6 , & V_8 ) ;
return V_8 & F_4 ( V_4 -> V_7 ) ;
}
static struct V_9 * F_8 ( const char * V_10 ,
const char * V_11 ,
struct V_5 * V_5 , T_2 V_7 )
{
struct V_3 * V_4 ;
struct V_9 * V_9 ;
struct V_12 V_13 ;
V_4 = F_9 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return F_10 ( - V_15 ) ;
V_13 . V_10 = V_10 ;
V_13 . V_16 = & V_17 ;
V_13 . V_18 = & V_11 ;
V_13 . V_19 = 1 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_2 . V_13 = & V_13 ;
V_9 = F_11 ( NULL , & V_4 -> V_2 ) ;
if ( F_12 ( V_9 ) )
F_13 ( V_4 ) ;
return V_9 ;
}
static void F_14 ( struct V_9 * V_9 )
{
struct V_1 * V_2 ;
V_2 = F_15 ( V_9 ) ;
if ( ! V_2 )
return;
F_16 ( V_9 ) ;
F_13 ( F_2 ( V_2 ) ) ;
}
static struct V_9 * F_17 ( struct V_20 * V_21 , void * V_22 )
{
struct V_23 * V_24 = V_22 ;
unsigned int type = V_21 -> args [ 0 ] ;
unsigned int V_25 = V_21 -> args [ 1 ] ;
if ( type == V_26 ) {
if ( V_25 > V_27 )
return F_10 ( - V_28 ) ;
return V_24 -> V_29 [ V_25 ] ;
} else if ( type == V_30 ) {
if ( V_25 > V_31 )
return F_10 ( - V_28 ) ;
return V_24 -> V_29 [ V_27 + V_25 ] ;
}
return F_10 ( - V_28 ) ;
}
static int F_18 ( struct V_32 * V_33 )
{
struct V_5 * V_5 ;
struct V_34 * V_35 = V_33 -> V_36 . V_37 ;
const char * V_38 , * V_39 , * V_40 , * V_41 , * V_42 ;
struct V_9 * V_9 ;
T_1 V_43 ;
int V_44 , V_45 ;
V_5 = F_19 ( V_35 ) ;
if ( F_12 ( V_5 ) )
return F_20 ( V_5 ) ;
V_45 = F_7 ( V_5 , V_46 ,
& V_43 ) ;
if ( V_45 )
return V_45 ;
F_21 ( V_35 , L_1 ,
V_47 , & V_39 ) ;
V_9 = F_22 ( NULL , V_39 , NULL , 0 ,
1000 * 1000 * 1000 ) ;
if ( F_12 ( V_9 ) ) {
V_45 = F_20 ( V_9 ) ;
goto V_48;
}
V_49 [ V_47 ] = V_9 ;
F_21 ( V_35 , L_1 ,
V_50 , & V_38 ) ;
V_9 = F_23 ( NULL , V_38 , V_39 , 0 , 1 , 3 ) ;
if ( F_12 ( V_9 ) ) {
V_45 = F_20 ( V_9 ) ;
goto V_51;
}
V_49 [ V_50 ] = V_9 ;
F_21 ( V_35 , L_1 ,
V_52 , & V_41 ) ;
V_9 = F_23 ( NULL , V_41 , V_39 , 0 , 1 , 2 ) ;
if ( F_12 ( V_9 ) ) {
V_45 = F_20 ( V_9 ) ;
goto V_53;
}
V_49 [ V_52 ] = V_9 ;
F_21 ( V_35 , L_1 ,
V_54 , & V_40 ) ;
V_9 = F_23 ( NULL , V_40 , V_41 , 0 , 1 , 2 ) ;
if ( F_12 ( V_9 ) ) {
V_45 = F_20 ( V_9 ) ;
goto V_55;
}
V_49 [ V_54 ] = V_9 ;
F_21 ( V_35 , L_1 ,
V_56 , & V_42 ) ;
if ( V_43 & V_57 )
V_9 = F_23 ( NULL , V_42 ,
V_39 , 0 , 2 , 5 ) ;
else
V_9 = F_23 ( NULL , V_42 ,
V_40 , 0 , 1 , 1 ) ;
if ( F_12 ( V_9 ) ) {
V_45 = F_20 ( V_9 ) ;
goto V_58;
}
V_49 [ V_56 ] = V_9 ;
for ( V_44 = 0 ; V_44 < V_31 ; V_44 ++ ) {
const char * V_59 , * V_10 ;
int V_45 ;
V_45 = F_21 ( V_35 ,
L_2 ,
V_44 , & V_10 ) ;
if ( V_45 < 0 )
break;
if ( ! strcmp ( V_10 , L_3 ) )
continue;
switch ( V_44 ) {
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
F_21 ( V_35 ,
L_2 ,
V_65 , & V_59 ) ;
break;
case V_66 :
V_59 = V_42 ;
break;
case V_67 :
V_59 = V_38 ;
break;
case V_68 :
F_21 ( V_35 ,
L_2 ,
V_69 , & V_59 ) ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
F_21 ( V_35 ,
L_2 ,
V_75 , & V_59 ) ;
break;
case V_76 :
case V_77 :
case V_78 :
case V_79 :
F_21 ( V_35 ,
L_2 ,
V_80 , & V_59 ) ;
break;
default:
V_59 = V_40 ;
break;
}
V_9 = F_8 ( V_10 , V_59 , V_5 , V_44 ) ;
if ( F_12 ( V_9 ) ) {
V_45 = F_20 ( V_9 ) ;
goto V_81;
}
V_49 [ V_27 + V_44 ] = V_9 ;
}
V_45 = F_24 ( V_35 , F_17 , & V_82 ) ;
if ( V_45 )
goto V_83;
return 0 ;
V_83:
V_81:
for ( V_44 = 0 ; V_44 < V_31 ; V_44 ++ ) {
V_9 = V_49 [ V_27 + V_44 ] ;
if ( V_9 )
F_14 ( V_9 ) ;
}
F_25 ( V_49 [ V_56 ] ) ;
V_58:
F_25 ( V_49 [ V_54 ] ) ;
V_55:
F_25 ( V_49 [ V_52 ] ) ;
V_53:
F_25 ( V_49 [ V_50 ] ) ;
V_51:
F_26 ( V_49 [ V_47 ] ) ;
V_48:
return V_45 ;
}
static int F_27 ( struct V_32 * V_33 )
{
int V_44 ;
F_28 ( V_33 -> V_36 . V_37 ) ;
for ( V_44 = 0 ; V_44 < V_31 ; V_44 ++ ) {
struct V_9 * V_9 = V_49 [ V_27 + V_44 ] ;
if ( V_9 )
F_14 ( V_9 ) ;
}
F_25 ( V_49 [ V_56 ] ) ;
F_25 ( V_49 [ V_54 ] ) ;
F_25 ( V_49 [ V_52 ] ) ;
F_25 ( V_49 [ V_50 ] ) ;
F_26 ( V_49 [ V_47 ] ) ;
return 0 ;
}
