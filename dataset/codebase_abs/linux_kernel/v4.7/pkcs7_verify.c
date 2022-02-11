static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
T_1 V_11 ;
int V_12 ;
F_2 ( L_1 , V_4 -> V_13 , V_4 -> V_6 -> V_14 ) ;
if ( ! V_4 -> V_6 -> V_14 )
return - V_15 ;
V_8 = F_3 ( V_4 -> V_6 -> V_14 , 0 , 0 ) ;
if ( F_4 ( V_8 ) )
return ( F_5 ( V_8 ) == - V_16 ) ? - V_15 : F_5 ( V_8 ) ;
V_11 = F_6 ( V_8 ) + sizeof( * V_10 ) ;
V_6 -> V_17 = F_7 ( V_8 ) ;
V_12 = - V_18 ;
V_6 -> V_19 = F_8 ( V_6 -> V_17 , V_20 ) ;
if ( ! V_6 -> V_19 )
goto V_21;
V_10 = F_9 ( V_11 , V_20 ) ;
if ( ! V_10 )
goto V_21;
V_10 -> V_8 = V_8 ;
V_10 -> V_22 = V_23 ;
V_12 = F_10 ( V_10 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_11 ( V_10 , V_2 -> V_24 , V_2 -> V_25 ,
V_6 -> V_19 ) ;
if ( V_12 < 0 )
goto error;
F_12 ( L_2 , 8 , V_6 -> V_19 ) ;
if ( V_4 -> V_26 ) {
T_2 V_27 ;
if ( ! V_4 -> V_28 ) {
F_13 ( L_3 , V_4 -> V_13 ) ;
V_12 = - V_29 ;
goto error;
}
if ( V_4 -> V_30 != V_6 -> V_17 ) {
F_14 ( L_4 ,
V_4 -> V_13 , V_4 -> V_30 ) ;
V_12 = - V_31 ;
goto error;
}
if ( memcmp ( V_6 -> V_19 , V_4 -> V_28 ,
V_4 -> V_30 ) != 0 ) {
F_14 ( L_5 ,
V_4 -> V_13 ) ;
V_12 = - V_29 ;
goto error;
}
memset ( V_6 -> V_19 , 0 , V_6 -> V_17 ) ;
V_12 = F_10 ( V_10 ) ;
if ( V_12 < 0 )
goto error;
V_27 = V_32 | V_33 ;
V_12 = F_15 ( V_10 , & V_27 , 1 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_11 ( V_10 , V_4 -> V_26 ,
V_4 -> V_34 , V_6 -> V_19 ) ;
if ( V_12 < 0 )
goto error;
F_12 ( L_6 , 8 , V_6 -> V_19 ) ;
}
error:
F_16 ( V_10 ) ;
V_21:
F_17 ( V_8 ) ;
F_18 ( L_7 , V_12 ) ;
return V_12 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_35 * V_36 ;
unsigned V_37 = 1 ;
F_2 ( L_8 , V_4 -> V_13 ) ;
for ( V_36 = V_2 -> V_38 ; V_36 ; V_36 = V_36 -> V_39 , V_37 ++ ) {
if ( ! F_20 ( V_36 -> V_40 , V_4 -> V_6 -> V_41 [ 0 ] ) )
continue;
F_12 ( L_9 ,
V_4 -> V_13 , V_37 ) ;
if ( V_36 -> V_42 -> V_43 != V_4 -> V_6 -> V_43 ) {
F_13 ( L_10 ,
V_4 -> V_13 ) ;
continue;
}
V_4 -> V_44 = V_36 ;
return 0 ;
}
F_14 ( L_11 ,
V_4 -> V_13 ,
V_4 -> V_6 -> V_41 [ 0 ] -> V_45 , V_4 -> V_6 -> V_41 [ 0 ] -> V_24 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_35 * V_36 = V_4 -> V_44 , * V_46 ;
struct V_47 * V_48 ;
int V_12 ;
F_2 ( L_12 ) ;
for ( V_46 = V_2 -> V_38 ; V_46 ; V_46 = V_46 -> V_39 )
V_46 -> V_49 = false ;
for (; ; ) {
F_14 ( L_13 ,
V_36 -> V_50 ,
V_36 -> V_51 , V_36 -> V_52 ) ;
V_36 -> V_49 = true ;
if ( V_36 -> V_53 )
goto V_54;
F_14 ( L_14 , V_36 -> V_55 ) ;
V_6 = V_36 -> V_6 ;
if ( V_6 -> V_41 [ 0 ] )
F_14 ( L_15 ,
V_6 -> V_41 [ 0 ] -> V_45 , V_6 -> V_41 [ 0 ] -> V_24 ) ;
if ( V_6 -> V_41 [ 1 ] )
F_14 ( L_16 ,
V_6 -> V_41 [ 1 ] -> V_45 , V_6 -> V_41 [ 1 ] -> V_24 ) ;
if ( V_36 -> V_56 ) {
if ( V_36 -> V_57 )
goto V_54;
V_36 -> V_44 = V_36 ;
F_14 ( L_17 ) ;
return 0 ;
}
V_48 = V_6 -> V_41 [ 0 ] ;
if ( V_48 ) {
F_14 ( L_18 , V_48 -> V_45 , V_48 -> V_24 ) ;
for ( V_46 = V_2 -> V_38 ; V_46 ; V_46 = V_46 -> V_39 ) {
F_14 ( L_19 ,
V_46 -> V_13 , V_46 -> V_40 -> V_45 , V_46 -> V_40 -> V_24 ) ;
if ( F_20 ( V_46 -> V_40 , V_48 ) )
goto V_58;
}
} else if ( V_6 -> V_41 [ 1 ] ) {
V_48 = V_6 -> V_41 [ 1 ] ;
F_14 ( L_18 , V_48 -> V_45 , V_48 -> V_24 ) ;
for ( V_46 = V_2 -> V_38 ; V_46 ; V_46 = V_46 -> V_39 ) {
if ( ! V_46 -> V_59 )
continue;
F_14 ( L_19 ,
V_46 -> V_13 , V_46 -> V_59 -> V_45 , V_46 -> V_59 -> V_24 ) ;
if ( F_20 ( V_46 -> V_59 , V_48 ) )
goto V_60;
}
}
F_14 ( L_20 ) ;
return 0 ;
V_58:
if ( V_6 -> V_41 [ 1 ] &&
! F_20 ( V_46 -> V_59 , V_6 -> V_41 [ 1 ] ) ) {
F_13 ( L_21 ,
V_4 -> V_13 , V_36 -> V_13 , V_46 -> V_13 ) ;
return - V_29 ;
}
V_60:
F_14 ( L_22 , V_46 -> V_50 ) ;
if ( V_46 -> V_49 ) {
F_13 ( L_23 ,
V_4 -> V_13 ) ;
return 0 ;
}
V_12 = F_22 ( V_46 -> V_42 , V_46 -> V_6 ) ;
if ( V_12 < 0 )
return V_12 ;
V_36 -> V_44 = V_46 ;
if ( V_36 == V_46 ) {
F_14 ( L_17 ) ;
return 0 ;
}
V_36 = V_46 ;
F_23 () ;
}
V_54:
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_12 ;
F_2 ( L_24 , V_4 -> V_13 ) ;
V_12 = F_1 ( V_2 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_19 ( V_2 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! V_4 -> V_44 )
return 0 ;
F_12 ( L_25 ,
V_4 -> V_44 -> V_13 , V_4 -> V_13 ) ;
if ( F_25 ( V_61 , & V_4 -> V_62 ) ) {
if ( V_4 -> V_63 < V_4 -> V_44 -> V_64 ||
V_4 -> V_63 > V_4 -> V_44 -> V_65 ) {
F_13 ( L_26 ) ;
return - V_29 ;
}
}
V_12 = F_22 ( V_4 -> V_44 -> V_42 , V_4 -> V_6 ) ;
if ( V_12 < 0 )
return V_12 ;
F_12 ( L_27 , V_4 -> V_13 ) ;
return F_21 ( V_2 , V_4 ) ;
}
int F_26 ( struct V_1 * V_2 ,
enum V_66 V_67 )
{
struct V_3 * V_4 ;
int V_68 = - V_15 ;
int V_12 ;
F_2 ( L_12 ) ;
switch ( V_67 ) {
case V_69 :
if ( V_2 -> V_70 != V_71 ) {
F_13 ( L_28 ) ;
return - V_29 ;
}
if ( V_2 -> V_72 ) {
F_13 ( L_29 ) ;
return - V_29 ;
}
break;
case V_73 :
if ( V_2 -> V_70 != V_71 ) {
F_13 ( L_30 ) ;
return - V_29 ;
}
if ( ! V_2 -> V_72 ) {
F_13 ( L_31 ) ;
return - V_29 ;
}
break;
case V_74 :
if ( V_2 -> V_70 != V_75 ) {
F_13 ( L_32 ) ;
return - V_29 ;
}
break;
case V_76 :
if ( V_2 -> V_70 != V_71 ) {
F_13 ( L_33 ) ;
return - V_29 ;
}
break;
default:
return - V_77 ;
}
for ( V_4 = V_2 -> V_78 ; V_4 ; V_4 = V_4 -> V_39 ) {
V_12 = F_24 ( V_2 , V_4 ) ;
if ( V_12 < 0 ) {
if ( V_12 == - V_15 ) {
V_4 -> V_79 = true ;
continue;
}
F_18 ( L_7 , V_12 ) ;
return V_12 ;
}
V_68 = 0 ;
}
F_18 ( L_7 , V_68 ) ;
return V_68 ;
}
int F_27 ( struct V_1 * V_2 ,
const void * V_24 , T_1 V_80 )
{
if ( V_2 -> V_24 ) {
F_14 ( L_34 ) ;
return - V_77 ;
}
V_2 -> V_24 = V_24 ;
V_2 -> V_25 = V_80 ;
return 0 ;
}
