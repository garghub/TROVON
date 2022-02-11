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
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
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
struct V_23 * V_43 ;
struct V_9 * V_9 , * * V_44 ;
T_1 V_45 ;
int V_46 , V_47 ;
V_5 = F_19 ( V_35 ) ;
if ( F_12 ( V_5 ) )
return F_20 ( V_5 ) ;
V_47 = F_7 ( V_5 , V_48 ,
& V_45 ) ;
if ( V_47 )
return V_47 ;
V_44 = F_21 ( & V_33 -> V_36 , sizeof( struct V_9 * ) ,
V_49 , V_14 ) ;
if ( ! V_44 )
return - V_15 ;
V_43 = F_22 ( & V_33 -> V_36 ,
sizeof( * V_43 ) ,
V_14 ) ;
if ( ! V_43 )
return - V_15 ;
V_43 -> V_29 = V_44 ;
V_43 -> V_50 = V_49 ;
F_23 ( V_35 , L_1 ,
V_51 , & V_39 ) ;
V_9 = F_24 ( NULL , V_39 , NULL , 0 ,
1000 * 1000 * 1000 ) ;
if ( F_12 ( V_9 ) ) {
V_47 = F_20 ( V_9 ) ;
goto V_52;
}
V_44 [ V_51 ] = V_9 ;
F_23 ( V_35 , L_1 ,
V_53 , & V_38 ) ;
V_9 = F_25 ( NULL , V_38 , V_39 , 0 , 1 , 3 ) ;
if ( F_12 ( V_9 ) ) {
V_47 = F_20 ( V_9 ) ;
goto V_54;
}
V_44 [ V_53 ] = V_9 ;
F_23 ( V_35 , L_1 ,
V_55 , & V_41 ) ;
V_9 = F_25 ( NULL , V_41 , V_39 , 0 , 1 , 2 ) ;
if ( F_12 ( V_9 ) ) {
V_47 = F_20 ( V_9 ) ;
goto V_56;
}
V_44 [ V_55 ] = V_9 ;
F_23 ( V_35 , L_1 ,
V_57 , & V_40 ) ;
V_9 = F_25 ( NULL , V_40 , V_41 , 0 , 1 , 2 ) ;
if ( F_12 ( V_9 ) ) {
V_47 = F_20 ( V_9 ) ;
goto V_58;
}
V_44 [ V_57 ] = V_9 ;
F_23 ( V_35 , L_1 ,
V_59 , & V_42 ) ;
if ( V_45 & V_60 )
V_9 = F_25 ( NULL , V_42 ,
V_39 , 0 , 2 , 5 ) ;
else
V_9 = F_25 ( NULL , V_42 ,
V_40 , 0 , 1 , 1 ) ;
if ( F_12 ( V_9 ) ) {
V_47 = F_20 ( V_9 ) ;
goto V_61;
}
V_44 [ V_59 ] = V_9 ;
for ( V_46 = 0 ; V_46 < V_31 ; V_46 ++ ) {
const char * V_62 , * V_10 ;
int V_47 ;
V_47 = F_23 ( V_35 ,
L_2 ,
V_46 , & V_10 ) ;
if ( V_47 < 0 )
break;
if ( ! strcmp ( V_10 , L_3 ) )
continue;
switch ( V_46 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
F_23 ( V_35 ,
L_2 ,
V_68 , & V_62 ) ;
break;
case V_69 :
V_62 = V_42 ;
break;
case V_70 :
V_62 = V_38 ;
break;
case V_71 :
F_23 ( V_35 ,
L_2 ,
V_72 , & V_62 ) ;
break;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
F_23 ( V_35 ,
L_2 ,
V_78 , & V_62 ) ;
break;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
F_23 ( V_35 ,
L_2 ,
V_83 , & V_62 ) ;
break;
default:
V_62 = V_40 ;
break;
}
V_9 = F_8 ( V_10 , V_62 , V_5 , V_46 ) ;
if ( F_12 ( V_9 ) ) {
V_47 = F_20 ( V_9 ) ;
goto V_84;
}
V_44 [ V_27 + V_46 ] = V_9 ;
}
V_47 = F_26 ( V_35 , F_17 , V_43 ) ;
if ( V_47 )
goto V_85;
F_27 ( V_33 , V_44 ) ;
return 0 ;
V_85:
V_84:
for ( V_46 = 0 ; V_46 < V_31 ; V_46 ++ ) {
V_9 = V_44 [ V_27 + V_46 ] ;
if ( V_9 )
F_14 ( V_9 ) ;
}
F_28 ( V_44 [ V_59 ] ) ;
V_61:
F_28 ( V_44 [ V_57 ] ) ;
V_58:
F_28 ( V_44 [ V_55 ] ) ;
V_56:
F_28 ( V_44 [ V_53 ] ) ;
V_54:
F_29 ( V_44 [ V_51 ] ) ;
V_52:
return V_47 ;
}
static int F_30 ( struct V_32 * V_33 )
{
struct V_9 * * V_44 = F_31 ( V_33 ) ;
int V_46 ;
F_32 ( V_33 -> V_36 . V_37 ) ;
for ( V_46 = 0 ; V_46 < V_31 ; V_46 ++ ) {
struct V_9 * V_9 = V_44 [ V_27 + V_46 ] ;
if ( V_9 )
F_14 ( V_9 ) ;
}
F_28 ( V_44 [ V_59 ] ) ;
F_28 ( V_44 [ V_57 ] ) ;
F_28 ( V_44 [ V_55 ] ) ;
F_28 ( V_44 [ V_53 ] ) ;
F_29 ( V_44 [ V_51 ] ) ;
return 0 ;
}
