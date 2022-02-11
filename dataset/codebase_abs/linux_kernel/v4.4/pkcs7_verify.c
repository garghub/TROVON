static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_9 , V_10 ;
void * V_11 ;
int V_12 ;
F_2 ( L_1 , V_4 -> V_13 , V_4 -> V_14 . V_15 ) ;
if ( V_4 -> V_14 . V_15 >= V_16 ||
! V_17 [ V_4 -> V_14 . V_15 ] )
return - V_18 ;
V_6 = F_3 ( V_17 [ V_4 -> V_14 . V_15 ] ,
0 , 0 ) ;
if ( F_4 ( V_6 ) )
return ( F_5 ( V_6 ) == - V_19 ) ? - V_18 : F_5 ( V_6 ) ;
V_10 = F_6 ( V_6 ) + sizeof( * V_8 ) ;
V_4 -> V_14 . V_9 = V_9 = F_7 ( V_6 ) ;
V_12 = - V_20 ;
V_11 = F_8 ( F_9 ( V_9 , F_10 ( * V_8 ) ) + V_10 ,
V_21 ) ;
if ( ! V_11 )
goto V_22;
V_8 = F_11 ( V_11 + V_9 , F_10 ( * V_8 ) ) ;
V_8 -> V_6 = V_6 ;
V_8 -> V_23 = V_24 ;
V_12 = F_12 ( V_8 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_13 ( V_8 , V_2 -> V_25 , V_2 -> V_26 , V_11 ) ;
if ( V_12 < 0 )
goto error;
F_14 ( L_2 , 8 , V_11 ) ;
if ( V_4 -> V_27 ) {
T_2 V_28 ;
if ( ! V_4 -> V_29 ) {
F_15 ( L_3 , V_4 -> V_13 ) ;
V_12 = - V_30 ;
goto error;
}
if ( V_4 -> V_31 != V_4 -> V_14 . V_9 ) {
F_16 ( L_4 ,
V_4 -> V_13 , V_4 -> V_31 ) ;
V_12 = - V_32 ;
goto error;
}
if ( memcmp ( V_11 , V_4 -> V_29 , V_4 -> V_31 ) != 0 ) {
F_16 ( L_5 ,
V_4 -> V_13 ) ;
V_12 = - V_30 ;
goto error;
}
memset ( V_11 , 0 , V_4 -> V_14 . V_9 ) ;
V_12 = F_12 ( V_8 ) ;
if ( V_12 < 0 )
goto error;
V_28 = V_33 | V_34 ;
V_12 = F_17 ( V_8 , & V_28 , 1 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_13 ( V_8 , V_4 -> V_27 ,
V_4 -> V_35 , V_11 ) ;
if ( V_12 < 0 )
goto error;
F_14 ( L_6 , 8 , V_11 ) ;
}
V_4 -> V_14 . V_11 = V_11 ;
V_11 = NULL ;
error:
F_18 ( V_11 ) ;
V_22:
F_19 ( V_6 ) ;
F_20 ( L_7 , V_12 ) ;
return V_12 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_36 * V_37 ;
unsigned V_38 = 1 ;
F_2 ( L_8 , V_4 -> V_13 ) ;
for ( V_37 = V_2 -> V_39 ; V_37 ; V_37 = V_37 -> V_40 , V_38 ++ ) {
if ( ! F_22 ( V_37 -> V_41 , V_4 -> V_42 ) )
continue;
F_14 ( L_9 ,
V_4 -> V_13 , V_38 ) ;
if ( V_37 -> V_43 -> V_44 != V_4 -> V_14 . V_44 ) {
F_15 ( L_10 ,
V_4 -> V_13 ) ;
continue;
}
V_4 -> V_45 = V_37 ;
return 0 ;
}
F_16 ( L_11 ,
V_4 -> V_13 ,
V_4 -> V_42 -> V_46 , V_4 -> V_42 -> V_25 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_45 , * V_47 ;
struct V_48 * V_49 ;
int V_12 ;
F_2 ( L_12 ) ;
for ( V_47 = V_2 -> V_39 ; V_47 ; V_47 = V_47 -> V_40 )
V_47 -> V_50 = false ;
for (; ; ) {
F_16 ( L_13 ,
V_37 -> V_51 ,
V_37 -> V_52 , V_37 -> V_53 ) ;
V_37 -> V_50 = true ;
V_12 = F_24 ( V_37 ) ;
if ( V_12 < 0 )
goto V_54;
F_16 ( L_14 , V_37 -> V_55 ) ;
if ( V_37 -> V_56 )
F_16 ( L_15 ,
V_37 -> V_56 -> V_46 , V_37 -> V_56 -> V_25 ) ;
if ( V_37 -> V_57 )
F_16 ( L_16 ,
V_37 -> V_57 -> V_46 , V_37 -> V_57 -> V_25 ) ;
if ( ( ! V_37 -> V_56 && ! V_37 -> V_57 ) ||
strcmp ( V_37 -> V_51 , V_37 -> V_55 ) == 0 ) {
F_16 ( L_17 ) ;
if ( V_37 -> V_58 != V_37 -> V_59 ||
memcmp ( V_37 -> V_60 , V_37 -> V_61 ,
V_37 -> V_59 ) != 0 )
return 0 ;
V_12 = F_25 ( V_37 -> V_43 , V_37 ) ;
if ( V_12 < 0 )
goto V_54;
V_37 -> V_45 = V_37 ;
F_16 ( L_18 ) ;
return 0 ;
}
V_49 = V_37 -> V_56 ;
if ( V_49 ) {
F_16 ( L_19 , V_49 -> V_46 , V_49 -> V_25 ) ;
for ( V_47 = V_2 -> V_39 ; V_47 ; V_47 = V_47 -> V_40 ) {
F_16 ( L_20 ,
V_47 -> V_13 , V_47 -> V_41 -> V_46 , V_47 -> V_41 -> V_25 ) ;
if ( F_22 ( V_47 -> V_41 , V_49 ) )
goto V_62;
}
} else {
V_49 = V_37 -> V_57 ;
F_16 ( L_19 , V_49 -> V_46 , V_49 -> V_25 ) ;
for ( V_47 = V_2 -> V_39 ; V_47 ; V_47 = V_47 -> V_40 ) {
if ( ! V_47 -> V_63 )
continue;
F_16 ( L_20 ,
V_47 -> V_13 , V_47 -> V_63 -> V_46 , V_47 -> V_63 -> V_25 ) ;
if ( F_22 ( V_47 -> V_63 , V_49 ) )
goto V_64;
}
}
F_16 ( L_21 ) ;
return 0 ;
V_62:
if ( V_37 -> V_57 &&
! F_22 ( V_47 -> V_63 , V_37 -> V_57 ) ) {
F_15 ( L_22 ,
V_4 -> V_13 , V_37 -> V_13 , V_47 -> V_13 ) ;
return - V_30 ;
}
V_64:
F_16 ( L_23 , V_47 -> V_51 ) ;
if ( V_47 -> V_50 ) {
F_15 ( L_24 ,
V_4 -> V_13 ) ;
return 0 ;
}
V_12 = F_25 ( V_47 -> V_43 , V_37 ) ;
if ( V_12 < 0 )
return V_12 ;
V_37 -> V_45 = V_47 ;
if ( V_37 == V_47 ) {
F_16 ( L_18 ) ;
return 0 ;
}
V_37 = V_47 ;
F_26 () ;
}
V_54:
if ( V_12 == - V_18 )
return 0 ;
return V_12 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_12 ;
F_2 ( L_25 , V_4 -> V_13 ) ;
V_12 = F_1 ( V_2 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_21 ( V_2 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! V_4 -> V_45 )
return 0 ;
F_14 ( L_26 ,
V_4 -> V_45 -> V_13 , V_4 -> V_13 ) ;
if ( F_28 ( V_65 , & V_4 -> V_66 ) ) {
if ( V_4 -> V_67 < V_4 -> V_45 -> V_68 ||
V_4 -> V_67 > V_4 -> V_45 -> V_69 ) {
F_15 ( L_27 ) ;
return - V_30 ;
}
}
V_12 = F_29 ( V_4 -> V_45 -> V_43 , & V_4 -> V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
F_14 ( L_28 , V_4 -> V_13 ) ;
return F_23 ( V_2 , V_4 ) ;
}
int F_30 ( struct V_1 * V_2 ,
enum V_70 V_71 )
{
struct V_3 * V_4 ;
struct V_36 * V_37 ;
int V_72 = - V_18 ;
int V_12 , V_73 ;
F_2 ( L_12 ) ;
switch ( V_71 ) {
case V_74 :
if ( V_2 -> V_75 != V_76 ) {
F_15 ( L_29 ) ;
return - V_30 ;
}
if ( V_2 -> V_77 ) {
F_15 ( L_30 ) ;
return - V_30 ;
}
break;
case V_78 :
if ( V_2 -> V_75 != V_76 ) {
F_15 ( L_31 ) ;
return - V_30 ;
}
if ( ! V_2 -> V_77 ) {
F_15 ( L_32 ) ;
return - V_30 ;
}
break;
case V_79 :
if ( V_2 -> V_75 != V_80 ) {
F_15 ( L_33 ) ;
return - V_30 ;
}
break;
case V_81 :
if ( V_2 -> V_75 != V_76 ) {
F_15 ( L_34 ) ;
return - V_30 ;
}
break;
default:
return - V_82 ;
}
for ( V_73 = 0 , V_37 = V_2 -> V_39 ; V_37 ; V_37 = V_37 -> V_40 , V_73 ++ ) {
V_12 = F_24 ( V_37 ) ;
if ( V_12 < 0 )
return V_12 ;
}
for ( V_4 = V_2 -> V_83 ; V_4 ; V_4 = V_4 -> V_40 ) {
V_12 = F_27 ( V_2 , V_4 ) ;
if ( V_12 < 0 ) {
if ( V_12 == - V_18 ) {
V_4 -> V_84 = true ;
continue;
}
F_20 ( L_7 , V_12 ) ;
return V_12 ;
}
V_72 = 0 ;
}
F_20 ( L_7 , V_72 ) ;
return V_72 ;
}
int F_31 ( struct V_1 * V_2 ,
const void * V_25 , T_1 V_85 )
{
if ( V_2 -> V_25 ) {
F_16 ( L_35 ) ;
return - V_82 ;
}
V_2 -> V_25 = V_25 ;
V_2 -> V_26 = V_85 ;
return 0 ;
}
