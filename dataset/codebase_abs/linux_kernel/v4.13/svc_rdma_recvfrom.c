static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_6 ;
T_1 V_7 ;
int V_8 ;
V_6 = V_4 -> V_9 [ 0 ] ;
F_2 ( V_2 -> V_10 [ 0 ] ) ;
V_2 -> V_10 [ 0 ] = V_6 ;
V_2 -> V_11 . V_12 [ 0 ] . V_13 = F_3 ( V_6 ) ;
V_2 -> V_11 . V_12 [ 0 ] . V_14 =
F_4 ( V_15 , V_5 , V_4 -> V_16 [ 0 ] . V_17 ) ;
V_2 -> V_11 . V_18 = V_5 ;
V_2 -> V_11 . V_19 = V_5 ;
V_7 = V_5 - V_2 -> V_11 . V_12 [ 0 ] . V_14 ;
V_2 -> V_11 . V_20 = V_7 ;
V_2 -> V_11 . V_21 = 0 ;
V_8 = 1 ;
while ( V_7 && V_8 < V_4 -> V_22 ) {
V_6 = V_4 -> V_9 [ V_8 ] ;
F_2 ( V_2 -> V_10 [ V_8 ] ) ;
V_2 -> V_10 [ V_8 ] = V_6 ;
V_7 -= F_4 ( T_1 , V_7 , V_4 -> V_16 [ V_8 ] . V_17 ) ;
V_8 ++ ;
}
V_2 -> V_23 = & V_2 -> V_10 [ V_8 ] ;
V_2 -> V_24 = V_2 -> V_23 + 1 ;
V_7 = V_8 ;
while ( V_8 < V_4 -> V_22 ) {
V_6 = V_4 -> V_9 [ V_8 ++ ] ;
F_2 ( V_6 ) ;
}
V_4 -> V_22 = V_7 ;
V_2 -> V_11 . V_25 [ 0 ] . V_13 = NULL ;
V_2 -> V_11 . V_25 [ 0 ] . V_14 = 0 ;
}
static T_2 * F_5 ( T_2 * V_26 , const T_2 * V_27 )
{
T_1 V_28 ;
bool V_29 ;
V_29 = true ;
while ( * V_26 ++ != V_30 ) {
if ( V_29 ) {
V_28 = F_6 ( V_26 ++ ) ;
V_29 = false ;
} else if ( F_6 ( V_26 ++ ) != V_28 ) {
return NULL ;
}
V_26 ++ ;
if ( F_6 ( V_26 ++ ) > V_31 )
return NULL ;
V_26 += 2 ;
if ( V_26 > V_27 )
return NULL ;
}
return V_26 ;
}
static T_2 * F_7 ( T_2 * V_26 , const T_2 * V_27 ,
T_1 V_32 )
{
T_1 V_33 , V_34 ;
V_34 = F_6 ( V_26 ++ ) ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
V_26 ++ ;
if ( F_6 ( V_26 ++ ) > V_32 )
return NULL ;
V_26 += 2 ;
if ( V_26 > V_27 )
return NULL ;
}
return V_26 ;
}
static T_2 * F_8 ( T_2 * V_26 , const T_2 * V_27 )
{
T_1 V_35 ;
V_35 = 0 ;
while ( * V_26 ++ != V_30 ) {
V_26 = F_7 ( V_26 , V_27 , V_36 ) ;
if ( ! V_26 )
return NULL ;
if ( V_35 ++ > 1 )
return NULL ;
}
return V_26 ;
}
static T_2 * F_9 ( T_2 * V_26 , const T_2 * V_27 )
{
if ( * V_26 ++ != V_30 ) {
V_26 = F_7 ( V_26 , V_27 , V_31 ) ;
if ( ! V_26 )
return NULL ;
}
return V_26 ;
}
static int F_10 ( struct V_37 * V_11 )
{
T_2 * V_26 , * V_27 , * V_38 ;
unsigned int V_39 ;
char * V_40 ;
if ( V_11 -> V_18 <= V_41 )
goto V_42;
V_38 = V_11 -> V_12 [ 0 ] . V_13 ;
if ( * ( V_38 + 1 ) != V_43 )
goto V_44;
switch ( * ( V_38 + 3 ) ) {
case V_45 :
V_40 = L_1 ;
break;
case V_46 :
V_40 = L_2 ;
break;
case V_47 :
goto V_48;
case V_49 :
goto V_48;
default:
goto V_50;
}
V_27 = ( T_2 * ) ( ( unsigned long ) V_38 + V_11 -> V_18 ) ;
V_26 = F_5 ( V_38 + 4 , V_27 ) ;
if ( ! V_26 )
goto V_51;
V_26 = F_8 ( V_26 , V_27 ) ;
if ( ! V_26 )
goto V_51;
V_26 = F_9 ( V_26 , V_27 ) ;
if ( ! V_26 )
goto V_51;
if ( V_26 > V_27 )
goto V_51;
V_11 -> V_12 [ 0 ] . V_13 = V_26 ;
V_39 = ( unsigned long ) V_26 - ( unsigned long ) V_38 ;
V_11 -> V_12 [ 0 ] . V_14 -= V_39 ;
V_11 -> V_18 -= V_39 ;
F_11 ( L_3 ,
V_40 , F_6 ( V_38 ) , V_39 ) ;
return V_39 ;
V_42:
F_11 ( L_4 , V_11 -> V_18 ) ;
return - V_52 ;
V_44:
F_11 ( L_5 ,
F_6 ( V_38 + 1 ) ) ;
return - V_53 ;
V_48:
F_11 ( L_6 ) ;
return 0 ;
V_50:
F_11 ( L_7 ,
F_6 ( V_38 + 3 ) ) ;
return - V_52 ;
V_51:
F_11 ( L_8 ) ;
return - V_52 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_12 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_12 -> V_22 ; V_54 ++ ) {
F_2 ( V_2 -> V_10 [ V_54 ] ) ;
V_2 -> V_10 [ V_54 ] = V_12 -> V_9 [ V_54 ] ;
}
V_2 -> V_11 . V_9 = & V_2 -> V_10 [ V_12 -> V_55 ] ;
V_2 -> V_11 . V_20 = V_12 -> V_56 . V_20 ;
V_2 -> V_23 = & V_2 -> V_10 [ V_54 ] ;
V_2 -> V_24 = V_2 -> V_23 + 1 ;
V_2 -> V_11 . V_12 [ 0 ] = V_12 -> V_56 . V_12 [ 0 ] ;
V_2 -> V_11 . V_25 [ 0 ] = V_12 -> V_56 . V_25 [ 0 ] ;
V_2 -> V_11 . V_18 = V_12 -> V_56 . V_18 ;
V_2 -> V_11 . V_19 = V_12 -> V_56 . V_19 ;
}
static void F_13 ( struct V_57 * V_58 ,
T_2 * V_38 , int V_59 )
{
struct V_3 * V_4 ;
T_2 * V_26 , * V_60 ;
unsigned int V_17 ;
struct V_6 * V_6 ;
int V_61 ;
V_61 = F_14 ( V_58 , V_62 ) ;
if ( V_61 )
return;
V_6 = F_15 ( V_62 ) ;
if ( ! V_6 )
return;
V_60 = F_3 ( V_6 ) ;
V_26 = V_60 ;
* V_26 ++ = * V_38 ;
* V_26 ++ = * ( V_38 + 1 ) ;
* V_26 ++ = V_58 -> V_63 ;
* V_26 ++ = V_49 ;
if ( V_59 == - V_53 ) {
* V_26 ++ = V_64 ;
* V_26 ++ = V_43 ;
* V_26 ++ = V_43 ;
} else {
* V_26 ++ = V_65 ;
}
V_17 = ( unsigned long ) V_26 - ( unsigned long ) V_60 ;
V_4 = F_16 ( V_58 ) ;
V_61 = F_17 ( V_58 , V_4 , V_60 , V_17 ) ;
if ( V_61 ) {
F_11 ( L_9 ,
V_61 ) ;
return;
}
V_61 = F_18 ( V_58 , V_4 , 1 , 0 ) ;
if ( V_61 ) {
F_11 ( L_10 ,
V_61 ) ;
F_19 ( V_4 ) ;
F_20 ( V_4 , 1 ) ;
}
}
static bool F_21 ( struct V_66 * V_58 ,
T_2 * V_67 )
{
T_2 * V_26 ;
if ( ! V_58 -> V_68 )
return false ;
V_26 = V_67 + 3 ;
if ( * V_26 ++ != V_45 )
return false ;
if ( * V_26 ++ != V_30 )
return false ;
if ( * V_26 ++ != V_30 )
return false ;
if ( * V_26 ++ != V_30 )
return false ;
if ( * V_26 ++ != * V_67 )
return false ;
if ( * V_26 == F_22 ( V_69 ) )
return false ;
return true ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_66 * V_58 = V_2 -> V_70 ;
struct V_57 * V_71 =
F_24 ( V_58 , struct V_57 , V_72 ) ;
struct V_3 * V_4 ;
T_2 * V_26 ;
int V_61 ;
F_25 ( & V_71 -> V_73 ) ;
if ( ! F_26 ( & V_71 -> V_74 ) ) {
V_4 = F_27 ( & V_71 -> V_74 ,
struct V_3 , V_75 ) ;
F_28 ( & V_4 -> V_75 ) ;
F_29 ( & V_71 -> V_73 ) ;
F_12 ( V_2 , V_4 ) ;
goto V_76;
} else if ( ! F_26 ( & V_71 -> V_77 ) ) {
V_4 = F_27 ( & V_71 -> V_77 ,
struct V_3 , V_75 ) ;
F_28 ( & V_4 -> V_75 ) ;
} else {
F_30 ( V_78 , & V_58 -> V_79 ) ;
F_29 ( & V_71 -> V_73 ) ;
return 0 ;
}
F_29 ( & V_71 -> V_73 ) ;
F_11 ( L_11 ,
V_4 , V_71 , V_2 ) ;
F_31 ( & V_80 ) ;
F_1 ( V_2 , V_4 , V_4 -> V_81 ) ;
V_26 = ( T_2 * ) V_2 -> V_11 . V_12 [ 0 ] . V_13 ;
V_61 = F_10 ( & V_2 -> V_11 ) ;
if ( V_61 < 0 )
goto V_82;
if ( V_61 == 0 )
goto V_48;
V_2 -> V_83 = V_61 ;
if ( F_21 ( V_58 , V_26 ) ) {
V_61 = F_32 ( V_58 -> V_68 , V_26 ,
& V_2 -> V_11 ) ;
F_20 ( V_4 , 0 ) ;
if ( V_61 )
goto V_84;
return V_61 ;
}
V_26 += V_85 ;
if ( * V_26 != V_30 )
goto V_86;
V_76:
F_20 ( V_4 , 0 ) ;
F_11 ( L_12 ,
V_71 , V_2 , V_2 -> V_11 . V_18 ) ;
V_2 -> V_87 = V_88 ;
F_33 ( V_2 , V_58 ) ;
return V_2 -> V_11 . V_18 ;
V_86:
V_61 = F_34 ( V_71 , V_2 , V_4 , V_26 ) ;
if ( V_61 < 0 )
goto V_89;
return 0 ;
V_82:
F_13 ( V_71 , V_26 , V_61 ) ;
F_20 ( V_4 , 0 ) ;
return 0 ;
V_89:
if ( V_61 == - V_52 )
F_13 ( V_71 , V_26 , V_61 ) ;
F_20 ( V_4 , 1 ) ;
return V_61 ;
V_48:
F_20 ( V_4 , 1 ) ;
V_84:
return F_14 ( V_71 , V_62 ) ;
}
