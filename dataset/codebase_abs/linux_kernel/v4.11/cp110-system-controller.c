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
static struct V_1 * F_8 ( const char * V_9 ,
const char * V_10 ,
struct V_5 * V_5 , T_2 V_7 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_11 V_12 ;
int V_13 ;
V_4 = F_9 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return F_10 ( - V_15 ) ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_9 = V_9 ;
V_12 . V_16 = & V_17 ;
V_12 . V_18 = & V_10 ;
V_12 . V_19 = 1 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_2 . V_12 = & V_12 ;
V_2 = & V_4 -> V_2 ;
V_13 = F_11 ( NULL , V_2 ) ;
if ( V_13 ) {
F_12 ( V_4 ) ;
V_2 = F_10 ( V_13 ) ;
}
return V_2 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_12 ( F_2 ( V_2 ) ) ;
}
static struct V_1 * F_15 ( struct V_20 * V_21 ,
void * V_22 )
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
static int F_16 ( struct V_32 * V_33 )
{
struct V_5 * V_5 ;
struct V_34 * V_35 = V_33 -> V_36 . V_37 ;
const char * V_38 , * V_39 , * V_40 , * V_41 , * V_42 ;
struct V_23 * V_43 ;
struct V_1 * V_2 , * * V_44 ;
T_1 V_45 ;
int V_46 , V_13 ;
V_5 = F_17 ( V_35 ) ;
if ( F_18 ( V_5 ) )
return F_19 ( V_5 ) ;
V_13 = F_7 ( V_5 , V_47 ,
& V_45 ) ;
if ( V_13 )
return V_13 ;
V_43 = F_20 ( & V_33 -> V_36 , sizeof( * V_43 ) +
sizeof( struct V_1 * ) * V_48 ,
V_14 ) ;
if ( ! V_43 )
return - V_15 ;
V_44 = V_43 -> V_29 ;
V_43 -> V_49 = V_48 ;
F_21 ( V_35 , L_1 ,
V_50 , & V_39 ) ;
V_2 = F_22 ( NULL , V_39 , NULL , 0 ,
1000 * 1000 * 1000 ) ;
if ( F_18 ( V_2 ) ) {
V_13 = F_19 ( V_2 ) ;
goto V_51;
}
V_44 [ V_50 ] = V_2 ;
F_21 ( V_35 , L_1 ,
V_52 , & V_38 ) ;
V_2 = F_23 ( NULL , V_38 , V_39 , 0 , 1 , 3 ) ;
if ( F_18 ( V_2 ) ) {
V_13 = F_19 ( V_2 ) ;
goto V_53;
}
V_44 [ V_52 ] = V_2 ;
F_21 ( V_35 , L_1 ,
V_54 , & V_41 ) ;
V_2 = F_23 ( NULL , V_41 , V_39 , 0 , 1 , 2 ) ;
if ( F_18 ( V_2 ) ) {
V_13 = F_19 ( V_2 ) ;
goto V_55;
}
V_44 [ V_54 ] = V_2 ;
F_21 ( V_35 , L_1 ,
V_56 , & V_40 ) ;
V_2 = F_23 ( NULL , V_40 , V_41 , 0 , 1 , 2 ) ;
if ( F_18 ( V_2 ) ) {
V_13 = F_19 ( V_2 ) ;
goto V_57;
}
V_44 [ V_56 ] = V_2 ;
F_21 ( V_35 , L_1 ,
V_58 , & V_42 ) ;
if ( V_45 & V_59 )
V_2 = F_23 ( NULL , V_42 ,
V_39 , 0 , 2 , 5 ) ;
else
V_2 = F_23 ( NULL , V_42 ,
V_40 , 0 , 1 , 1 ) ;
if ( F_18 ( V_2 ) ) {
V_13 = F_19 ( V_2 ) ;
goto V_60;
}
V_44 [ V_58 ] = V_2 ;
for ( V_46 = 0 ; V_46 < V_31 ; V_46 ++ ) {
const char * V_61 , * V_9 ;
int V_13 ;
V_13 = F_21 ( V_35 ,
L_2 ,
V_46 , & V_9 ) ;
if ( V_13 < 0 )
break;
if ( ! strcmp ( V_9 , L_3 ) )
continue;
switch ( V_46 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
F_21 ( V_35 ,
L_2 ,
V_67 , & V_61 ) ;
break;
case V_68 :
F_21 ( V_35 ,
L_2 ,
V_69 , & V_61 ) ;
break;
case V_70 :
V_61 = V_42 ;
break;
case V_71 :
V_61 = V_38 ;
break;
case V_72 :
case V_73 :
F_21 ( V_35 ,
L_2 ,
V_74 , & V_61 ) ;
break;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
F_21 ( V_35 ,
L_2 ,
V_80 , & V_61 ) ;
break;
case V_81 :
case V_82 :
case V_83 :
case V_84 :
F_21 ( V_35 ,
L_2 ,
V_85 , & V_61 ) ;
break;
default:
V_61 = V_40 ;
break;
}
V_2 = F_8 ( V_9 , V_61 , V_5 , V_46 ) ;
if ( F_18 ( V_2 ) ) {
V_13 = F_19 ( V_2 ) ;
goto V_86;
}
V_44 [ V_27 + V_46 ] = V_2 ;
}
V_13 = F_24 ( V_35 , F_15 , V_43 ) ;
if ( V_13 )
goto V_87;
F_25 ( V_33 , V_44 ) ;
return 0 ;
V_87:
V_86:
for ( V_46 = 0 ; V_46 < V_31 ; V_46 ++ ) {
V_2 = V_44 [ V_27 + V_46 ] ;
if ( V_2 )
F_13 ( V_2 ) ;
}
F_26 ( V_44 [ V_58 ] ) ;
V_60:
F_26 ( V_44 [ V_56 ] ) ;
V_57:
F_26 ( V_44 [ V_54 ] ) ;
V_55:
F_26 ( V_44 [ V_52 ] ) ;
V_53:
F_27 ( V_44 [ V_50 ] ) ;
V_51:
return V_13 ;
}
