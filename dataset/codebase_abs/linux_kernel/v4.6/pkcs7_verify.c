static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_9 , V_10 ;
void * V_11 ;
int V_12 ;
F_2 ( L_1 , V_4 -> V_13 , V_4 -> V_14 . V_15 ) ;
if ( ! V_4 -> V_14 . V_15 )
return - V_16 ;
V_6 = F_3 ( V_4 -> V_14 . V_15 , 0 , 0 ) ;
if ( F_4 ( V_6 ) )
return ( F_5 ( V_6 ) == - V_17 ) ? - V_16 : F_5 ( V_6 ) ;
V_10 = F_6 ( V_6 ) + sizeof( * V_8 ) ;
V_4 -> V_14 . V_9 = V_9 = F_7 ( V_6 ) ;
V_12 = - V_18 ;
V_11 = F_8 ( F_9 ( V_9 , F_10 ( * V_8 ) ) + V_10 ,
V_19 ) ;
if ( ! V_11 )
goto V_20;
V_8 = F_11 ( V_11 + V_9 , F_10 ( * V_8 ) ) ;
V_8 -> V_6 = V_6 ;
V_8 -> V_21 = V_22 ;
V_12 = F_12 ( V_8 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_13 ( V_8 , V_2 -> V_23 , V_2 -> V_24 , V_11 ) ;
if ( V_12 < 0 )
goto error;
F_14 ( L_2 , 8 , V_11 ) ;
if ( V_4 -> V_25 ) {
T_2 V_26 ;
if ( ! V_4 -> V_27 ) {
F_15 ( L_3 , V_4 -> V_13 ) ;
V_12 = - V_28 ;
goto error;
}
if ( V_4 -> V_29 != V_4 -> V_14 . V_9 ) {
F_16 ( L_4 ,
V_4 -> V_13 , V_4 -> V_29 ) ;
V_12 = - V_30 ;
goto error;
}
if ( memcmp ( V_11 , V_4 -> V_27 , V_4 -> V_29 ) != 0 ) {
F_16 ( L_5 ,
V_4 -> V_13 ) ;
V_12 = - V_28 ;
goto error;
}
memset ( V_11 , 0 , V_4 -> V_14 . V_9 ) ;
V_12 = F_12 ( V_8 ) ;
if ( V_12 < 0 )
goto error;
V_26 = V_31 | V_32 ;
V_12 = F_17 ( V_8 , & V_26 , 1 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_13 ( V_8 , V_4 -> V_25 ,
V_4 -> V_33 , V_11 ) ;
if ( V_12 < 0 )
goto error;
F_14 ( L_6 , 8 , V_11 ) ;
}
V_4 -> V_14 . V_11 = V_11 ;
V_11 = NULL ;
error:
F_18 ( V_11 ) ;
V_20:
F_19 ( V_6 ) ;
F_20 ( L_7 , V_12 ) ;
return V_12 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_34 * V_35 ;
unsigned V_36 = 1 ;
F_2 ( L_8 , V_4 -> V_13 ) ;
for ( V_35 = V_2 -> V_37 ; V_35 ; V_35 = V_35 -> V_38 , V_36 ++ ) {
if ( ! F_22 ( V_35 -> V_39 , V_4 -> V_40 ) )
continue;
F_14 ( L_9 ,
V_4 -> V_13 , V_36 ) ;
if ( V_35 -> V_41 -> V_42 != V_4 -> V_14 . V_42 ) {
F_15 ( L_10 ,
V_4 -> V_13 ) ;
continue;
}
V_4 -> V_43 = V_35 ;
return 0 ;
}
F_16 ( L_11 ,
V_4 -> V_13 ,
V_4 -> V_40 -> V_44 , V_4 -> V_40 -> V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_34 * V_35 = V_4 -> V_43 , * V_45 ;
struct V_46 * V_47 ;
int V_12 ;
F_2 ( L_12 ) ;
for ( V_45 = V_2 -> V_37 ; V_45 ; V_45 = V_45 -> V_38 )
V_45 -> V_48 = false ;
for (; ; ) {
F_16 ( L_13 ,
V_35 -> V_49 ,
V_35 -> V_50 , V_35 -> V_51 ) ;
V_35 -> V_48 = true ;
V_12 = F_24 ( V_35 ) ;
if ( V_12 < 0 )
goto V_52;
F_16 ( L_14 , V_35 -> V_53 ) ;
if ( V_35 -> V_54 )
F_16 ( L_15 ,
V_35 -> V_54 -> V_44 , V_35 -> V_54 -> V_23 ) ;
if ( V_35 -> V_55 )
F_16 ( L_16 ,
V_35 -> V_55 -> V_44 , V_35 -> V_55 -> V_23 ) ;
if ( ( ! V_35 -> V_54 && ! V_35 -> V_55 ) ||
strcmp ( V_35 -> V_49 , V_35 -> V_53 ) == 0 ) {
F_16 ( L_17 ) ;
if ( V_35 -> V_56 != V_35 -> V_57 ||
memcmp ( V_35 -> V_58 , V_35 -> V_59 ,
V_35 -> V_57 ) != 0 )
return 0 ;
V_12 = F_25 ( V_35 -> V_41 , V_35 ) ;
if ( V_12 < 0 )
goto V_52;
V_35 -> V_43 = V_35 ;
F_16 ( L_18 ) ;
return 0 ;
}
V_47 = V_35 -> V_54 ;
if ( V_47 ) {
F_16 ( L_19 , V_47 -> V_44 , V_47 -> V_23 ) ;
for ( V_45 = V_2 -> V_37 ; V_45 ; V_45 = V_45 -> V_38 ) {
F_16 ( L_20 ,
V_45 -> V_13 , V_45 -> V_39 -> V_44 , V_45 -> V_39 -> V_23 ) ;
if ( F_22 ( V_45 -> V_39 , V_47 ) )
goto V_60;
}
} else {
V_47 = V_35 -> V_55 ;
F_16 ( L_19 , V_47 -> V_44 , V_47 -> V_23 ) ;
for ( V_45 = V_2 -> V_37 ; V_45 ; V_45 = V_45 -> V_38 ) {
if ( ! V_45 -> V_61 )
continue;
F_16 ( L_20 ,
V_45 -> V_13 , V_45 -> V_61 -> V_44 , V_45 -> V_61 -> V_23 ) ;
if ( F_22 ( V_45 -> V_61 , V_47 ) )
goto V_62;
}
}
F_16 ( L_21 ) ;
return 0 ;
V_60:
if ( V_35 -> V_55 &&
! F_22 ( V_45 -> V_61 , V_35 -> V_55 ) ) {
F_15 ( L_22 ,
V_4 -> V_13 , V_35 -> V_13 , V_45 -> V_13 ) ;
return - V_28 ;
}
V_62:
F_16 ( L_23 , V_45 -> V_49 ) ;
if ( V_45 -> V_48 ) {
F_15 ( L_24 ,
V_4 -> V_13 ) ;
return 0 ;
}
V_12 = F_25 ( V_45 -> V_41 , V_35 ) ;
if ( V_12 < 0 )
return V_12 ;
V_35 -> V_43 = V_45 ;
if ( V_35 == V_45 ) {
F_16 ( L_18 ) ;
return 0 ;
}
V_35 = V_45 ;
F_26 () ;
}
V_52:
if ( V_12 == - V_16 )
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
if ( ! V_4 -> V_43 )
return 0 ;
F_14 ( L_26 ,
V_4 -> V_43 -> V_13 , V_4 -> V_13 ) ;
if ( F_28 ( V_63 , & V_4 -> V_64 ) ) {
if ( V_4 -> V_65 < V_4 -> V_43 -> V_66 ||
V_4 -> V_65 > V_4 -> V_43 -> V_67 ) {
F_15 ( L_27 ) ;
return - V_28 ;
}
}
V_12 = F_29 ( V_4 -> V_43 -> V_41 , & V_4 -> V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
F_14 ( L_28 , V_4 -> V_13 ) ;
return F_23 ( V_2 , V_4 ) ;
}
int F_30 ( struct V_1 * V_2 ,
enum V_68 V_69 )
{
struct V_3 * V_4 ;
struct V_34 * V_35 ;
int V_70 = - V_16 ;
int V_12 , V_71 ;
F_2 ( L_12 ) ;
switch ( V_69 ) {
case V_72 :
if ( V_2 -> V_73 != V_74 ) {
F_15 ( L_29 ) ;
return - V_28 ;
}
if ( V_2 -> V_75 ) {
F_15 ( L_30 ) ;
return - V_28 ;
}
break;
case V_76 :
if ( V_2 -> V_73 != V_74 ) {
F_15 ( L_31 ) ;
return - V_28 ;
}
if ( ! V_2 -> V_75 ) {
F_15 ( L_32 ) ;
return - V_28 ;
}
break;
case V_77 :
if ( V_2 -> V_73 != V_78 ) {
F_15 ( L_33 ) ;
return - V_28 ;
}
break;
case V_79 :
if ( V_2 -> V_73 != V_74 ) {
F_15 ( L_34 ) ;
return - V_28 ;
}
break;
default:
return - V_80 ;
}
for ( V_71 = 0 , V_35 = V_2 -> V_37 ; V_35 ; V_35 = V_35 -> V_38 , V_71 ++ ) {
V_12 = F_24 ( V_35 ) ;
if ( V_12 < 0 )
return V_12 ;
}
for ( V_4 = V_2 -> V_81 ; V_4 ; V_4 = V_4 -> V_38 ) {
V_12 = F_27 ( V_2 , V_4 ) ;
if ( V_12 < 0 ) {
if ( V_12 == - V_16 ) {
V_4 -> V_82 = true ;
continue;
}
F_20 ( L_7 , V_12 ) ;
return V_12 ;
}
V_70 = 0 ;
}
F_20 ( L_7 , V_70 ) ;
return V_70 ;
}
int F_31 ( struct V_1 * V_2 ,
const void * V_23 , T_1 V_83 )
{
if ( V_2 -> V_23 ) {
F_16 ( L_35 ) ;
return - V_80 ;
}
V_2 -> V_23 = V_23 ;
V_2 -> V_24 = V_83 ;
return 0 ;
}
