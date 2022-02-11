static int F_1 ( int * V_1 ,
const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( * V_1 == V_6 ) {
* V_1 = V_3 -> V_7 ;
return 0 ;
}
switch ( V_3 -> type ) {
case V_8 :
switch ( * V_1 ) {
case V_9 :
F_2 ( L_1 , V_3 -> V_10 ) ;
return 0 ;
case V_11 :
F_2 ( L_2 , V_3 -> V_10 ) ;
return 0 ;
}
break;
case V_12 :
if ( * V_1 >= V_3 -> V_13 . V_14 . V_15 && * V_1 <= V_3 -> V_13 . V_14 . V_16 ) {
F_2 ( L_3 , V_3 -> V_10 , * V_1 ) ;
return 0 ;
}
break;
case V_17 : {
int V_18 ;
const struct V_19 * V_20 ;
for ( V_18 = 0 ; V_18 < V_3 -> V_13 . V_21 . V_22 ; V_18 ++ ) {
V_20 = & V_3 -> V_13 . V_21 . V_23 [ V_18 ] ;
if ( * V_1 == V_20 -> V_18 ) {
if ( V_20 -> V_24 [ 0 ] != '\0' )
F_2 ( L_4 , V_20 -> V_24 ) ;
return 0 ;
}
}
}
break;
default:
F_3 () ;
}
F_2 ( L_5 ,
V_3 -> V_10 , * V_1 , V_3 -> V_25 ) ;
* V_1 = V_3 -> V_7 ;
return - 1 ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = & V_5 -> V_27 ;
int V_28 , V_29 ;
{
static const struct V_2 V_3 = {
. type = V_17 ,
. V_10 = L_6 ,
. V_25 = L_7 ,
. V_7 = 0 ,
. V_13 = { . V_21 = { . V_22 = ( int ) F_5 ( V_30 ) ,
. V_23 = V_30 } }
} ;
V_28 = V_31 ;
F_1 ( & V_28 , & V_3 , V_5 ) ;
}
{
static const struct V_2 V_3 = {
. type = V_17 ,
. V_10 = L_8 ,
. V_25 = L_7 ,
. V_7 = 0 ,
. V_13 = { . V_21 = { . V_22 = ( int ) F_5 ( V_32 ) ,
. V_23 = V_32 } }
} ;
V_29 = V_33 ;
F_1 ( & V_29 , & V_3 , V_5 ) ;
}
{
static const struct V_2 V_3 = {
. type = V_17 ,
. V_10 = L_9 ,
. V_25 = L_7 ,
. V_7 = V_34 ,
. V_13 = { . V_21 = { . V_22 = ( int ) F_5 ( V_35 ) ,
. V_23 = V_35 } }
} ;
if ( V_28 || V_29 ) {
F_2 ( L_10 ) ;
V_27 -> V_36 . V_37 = V_3 . V_7 ;
} else {
V_27 -> V_36 . V_37 = V_38 ;
F_1 (
( int * ) ( & V_27 -> V_36 . V_37 ) ,
& V_3 , V_5 ) ;
}
}
switch ( V_28 + V_29 ) {
case 0 :
V_27 -> V_39 . V_40 = V_27 -> V_39 . V_41 = 1 ;
if ( ( V_28 || V_29 ) )
F_2 ( L_11 ) ;
V_27 -> V_39 . V_42 = V_43 ;
V_27 -> V_39 . V_44 = V_45 ;
break;
case V_46 :
F_2 ( L_12 ) ;
F_2 ( L_13 ) ;
V_27 -> V_39 . V_40 = V_27 -> V_39 . V_41 = 1 ;
V_27 -> V_36 . V_37 = V_47 |
V_48 ;
V_27 -> V_39 . V_42 = V_43 ;
V_27 -> V_39 . V_44 = V_45 ;
break;
case V_49 :
F_2 ( L_14 ) ;
F_2 ( L_15 ) ;
V_27 -> V_39 . V_40 = V_27 -> V_39 . V_41 = 1 ;
V_27 -> V_36 . V_37 = V_50 |
V_51 |
V_52 ;
V_27 -> V_39 . V_42 = V_43 ;
V_27 -> V_39 . V_44 = V_53 ;
break;
case V_43 :
F_2 ( L_16 ) ;
F_2 ( L_17 ) ;
V_27 -> V_39 . V_40 = V_27 -> V_39 . V_41 = 1 ;
V_27 -> V_36 . V_37 = V_47 |
V_50 ;
V_27 -> V_39 . V_42 = V_43 ;
V_27 -> V_39 . V_44 = V_45 ;
break;
case V_43 + V_46 :
F_2 ( L_18 ) ;
V_27 -> V_39 . V_40 = V_27 -> V_39 . V_41 = 0 ;
V_27 -> V_36 . V_37 = 0 ;
V_27 -> V_39 . V_42 = V_43 ;
V_27 -> V_39 . V_44 = V_45 ;
break;
case V_43 + V_49 :
F_2 ( L_19 ) ;
V_27 -> V_39 . V_40 = V_27 -> V_39 . V_41 = 0 ;
V_27 -> V_36 . V_37 = 0 ;
V_27 -> V_39 . V_42 = V_43 ;
V_27 -> V_39 . V_44 = V_53 ;
break;
case V_54 :
F_2 ( L_20 ) ;
F_2 ( L_21 ) ;
V_27 -> V_39 . V_40 = V_27 -> V_39 . V_41 = 1 ;
V_27 -> V_36 . V_37 = V_48 |
V_51 ;
V_27 -> V_39 . V_42 = V_54 ;
V_27 -> V_39 . V_44 = V_45 ;
break;
case V_54 + V_46 :
F_2 ( L_22 ) ;
V_27 -> V_39 . V_40 = V_27 -> V_39 . V_41 = 0 ;
V_27 -> V_36 . V_37 = 0 ;
V_27 -> V_39 . V_42 = V_54 ;
V_27 -> V_39 . V_44 = V_45 ;
break;
case V_54 + V_49 :
F_2 ( L_23 ) ;
V_27 -> V_39 . V_40 = V_27 -> V_39 . V_41 = 0 ;
V_27 -> V_36 . V_37 = 0 ;
V_27 -> V_39 . V_42 = V_54 ;
V_27 -> V_39 . V_44 = V_53 ;
break;
case V_55 :
F_2 ( L_24 ) ;
goto V_56;
case V_55 + V_46 :
F_2 ( L_25 ) ;
case V_55 + V_49 :
V_56:
F_2 ( L_26 ) ;
V_27 -> V_39 . V_40 = V_27 -> V_39 . V_41 = 1 ;
V_27 -> V_36 . V_37 = V_52 ;
V_27 -> V_39 . V_42 = V_55 ;
V_27 -> V_39 . V_44 = V_53 ;
break;
default:
F_3 () ;
}
}
void F_6 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = & V_5 -> V_27 ;
struct V_57 * V_58 = V_5 -> V_59 ;
int V_60 ;
{
static const struct V_2 V_3 = {
. type = V_12 ,
. V_10 = L_27 ,
. V_25 = L_28
F_7 ( V_61 ) ,
. V_7 = V_61 ,
. V_13 = { . V_14 = { . V_15 = V_62 ,
. V_16 = V_63 } }
} ;
struct V_64 * V_65 = V_5 -> V_65 ;
V_65 -> V_66 = V_67 ;
F_1 ( & V_65 -> V_66 , & V_3 , V_5 ) ;
V_65 -> V_66 = F_8 ( V_65 -> V_66 ,
V_68 ) ;
}
{
static const struct V_2 V_3 = {
. type = V_12 ,
. V_10 = L_29 ,
. V_25 = L_28
F_7 ( V_69 ) ,
. V_7 = V_69 ,
. V_13 = { . V_14 = { . V_15 = V_70 ,
. V_16 = V_71 } }
} ;
struct V_72 * V_73 = V_5 -> V_73 ;
V_73 -> V_66 = V_74 ;
F_1 ( & V_73 -> V_66 , & V_3 , V_5 ) ;
V_73 -> V_66 = F_8 ( V_73 -> V_66 ,
V_75 ) ;
}
{
static const struct V_2 V_3 = {
. type = V_8 ,
. V_10 = L_30 ,
. V_25 = L_31 ,
. V_7 = V_76
} ;
V_60 = V_77 ;
F_1 ( & V_60 , & V_3 , V_5 ) ;
if ( ! V_60 )
V_58 -> V_78 &= ~ V_79 ;
}
{
static const struct V_2 V_3 = {
. type = V_8 ,
. V_10 = L_30 ,
. V_25 = L_31 ,
. V_7 = V_80
} ;
V_60 = V_81 ;
F_1 ( & V_60 , & V_3 , V_5 ) ;
if ( ! V_60 )
V_58 -> V_78 &= ~ V_82 ;
}
{
static const struct V_2 V_3 = {
. type = V_17 ,
. V_10 = L_32 ,
. V_25 = L_33 ,
. V_7 = V_83 ,
. V_13 = { . V_21 = { . V_22 = ( int ) F_5 ( V_84 ) ,
. V_23 = V_84 } }
} ;
V_27 -> V_39 . V_85 = V_86 ;
F_1 ( ( int * ) ( & V_27 -> V_39 . V_85 ) ,
& V_3 , V_5 ) ;
}
F_4 ( V_5 ) ;
}
