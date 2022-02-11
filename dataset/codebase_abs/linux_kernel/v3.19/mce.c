static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_5 = V_4 -> V_5 ;
switch ( V_4 -> V_5 ) {
case V_6 :
V_2 -> V_7 . V_8 . V_9 = V_4 -> V_7 . V_9 ;
break;
case V_10 :
V_2 -> V_7 . V_11 . V_12 = V_4 -> V_7 . V_12 ;
break;
case V_13 :
V_2 -> V_7 . V_14 . V_15 = V_4 -> V_7 . V_15 ;
break;
case V_16 :
V_2 -> V_7 . V_17 . V_18 = V_4 -> V_7 . V_18 ;
break;
case V_19 :
default:
break;
}
}
void F_2 ( struct V_20 * V_21 , long V_22 ,
struct V_3 * V_4 ,
T_1 V_23 , T_1 V_24 )
{
T_1 V_25 ;
int V_26 = F_3 ( V_27 ) ;
struct V_1 * V_2 = F_4 ( & V_28 [ V_26 ] ) ;
if ( V_26 >= V_29 )
return;
V_2 -> V_30 = V_31 ;
V_2 -> V_32 = V_23 ;
V_2 -> V_25 = V_21 -> V_33 ;
V_2 -> V_34 = V_21 -> V_35 [ 3 ] ;
V_2 -> V_36 = 1 ;
V_2 -> V_37 = V_38 ;
if ( V_22 )
V_2 -> V_39 = V_40 ;
else
V_2 -> V_39 = V_41 ;
V_2 -> V_42 = V_43 ;
V_25 = V_21 -> V_33 ;
F_1 ( V_2 , V_4 ) ;
if ( ! V_24 )
return;
if ( V_2 -> V_5 == V_16 ) {
V_2 -> V_7 . V_17 . V_44 = true ;
V_2 -> V_7 . V_17 . V_45 = V_24 ;
} else if ( V_2 -> V_5 == V_10 ) {
V_2 -> V_7 . V_11 . V_44 = true ;
V_2 -> V_7 . V_11 . V_45 = V_24 ;
} else if ( V_2 -> V_5 == V_13 ) {
V_2 -> V_7 . V_14 . V_44 = true ;
V_2 -> V_7 . V_14 . V_45 = V_24 ;
} else if ( V_2 -> V_5 == V_6 ) {
V_2 -> V_7 . V_8 . V_44 = true ;
V_2 -> V_7 . V_8 . V_45 = V_24 ;
}
return;
}
int F_5 ( struct V_1 * V_2 , bool V_46 )
{
int V_26 = F_6 ( V_27 ) - 1 ;
struct V_1 * V_47 ;
int V_48 = 0 ;
if ( V_26 < 0 )
return V_48 ;
if ( V_26 < V_29 ) {
V_47 = F_4 ( & V_28 [ V_26 ] ) ;
if ( V_2 )
* V_2 = * V_47 ;
if ( V_46 )
V_47 -> V_36 = 0 ;
V_48 = 1 ;
}
if ( V_46 )
F_7 ( V_27 ) ;
return V_48 ;
}
void F_8 ( void )
{
F_5 ( NULL , true ) ;
}
void F_9 ( void )
{
int V_26 ;
struct V_1 V_49 ;
if ( ! F_5 ( & V_49 , V_50 ) )
return;
V_26 = F_3 ( V_51 ) ;
if ( V_26 >= V_29 ) {
F_7 ( V_51 ) ;
return;
}
memcpy ( F_4 ( & V_52 [ V_26 ] ) , & V_49 , sizeof( V_49 ) ) ;
F_10 ( & V_53 ) ;
}
static void F_11 ( struct V_54 * V_55 )
{
int V_26 ;
while ( F_6 ( V_51 ) > 0 ) {
V_26 = F_6 ( V_51 ) - 1 ;
F_12 (
F_4 ( & V_52 [ V_26 ] ) ) ;
F_7 ( V_51 ) ;
}
}
void F_12 ( struct V_1 * V_49 )
{
const char * V_56 , * V_57 , * V_58 ;
static const char * V_59 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
} ;
static const char * V_60 [] = {
L_1 ,
L_6 ,
L_7 ,
} ;
static const char * V_61 [] = {
L_1 ,
L_6 ,
L_7 ,
} ;
static const char * V_62 [] = {
L_1 ,
L_6 ,
L_7 ,
} ;
if ( V_49 -> V_30 != V_31 ) {
F_13 ( L_8 ,
V_49 -> V_30 ) ;
return;
}
switch ( V_49 -> V_42 ) {
case V_63 :
V_56 = V_64 ;
V_57 = L_9 ;
break;
case V_65 :
V_56 = V_66 ;
V_57 = L_10 ;
break;
case V_43 :
V_56 = V_67 ;
V_57 = L_11 ;
break;
case V_68 :
default:
V_56 = V_67 ;
V_57 = L_12 ;
break;
}
F_14 ( L_13 , V_56 , V_57 ,
V_49 -> V_39 == V_40 ?
L_14 : L_15 ) ;
F_14 ( L_16 , V_56 ,
V_49 -> V_37 == V_38 ? L_17 : L_18 ) ;
switch ( V_49 -> V_5 ) {
case V_6 :
V_58 = V_49 -> V_7 . V_8 . V_9 <
F_15 ( V_59 ) ?
V_59 [ V_49 -> V_7 . V_8 . V_9 ]
: L_18 ;
F_14 ( L_19 , V_56 , V_58 ) ;
if ( V_49 -> V_7 . V_8 . V_44 )
F_14 ( L_20 ,
V_56 , V_49 -> V_7 . V_8 . V_45 ) ;
if ( V_49 -> V_7 . V_8 . V_69 )
F_14 ( L_21 ,
V_56 , V_49 -> V_7 . V_8 . V_70 ) ;
break;
case V_10 :
V_58 = V_49 -> V_7 . V_11 . V_12 <
F_15 ( V_60 ) ?
V_60 [ V_49 -> V_7 . V_11 . V_12 ]
: L_18 ;
F_14 ( L_22 , V_56 , V_58 ) ;
if ( V_49 -> V_7 . V_11 . V_44 )
F_14 ( L_20 ,
V_56 , V_49 -> V_7 . V_11 . V_45 ) ;
break;
case V_13 :
V_58 = V_49 -> V_7 . V_14 . V_15 <
F_15 ( V_61 ) ?
V_61 [ V_49 -> V_7 . V_14 . V_15 ]
: L_18 ;
F_14 ( L_23 , V_56 , V_58 ) ;
if ( V_49 -> V_7 . V_14 . V_44 )
F_14 ( L_20 ,
V_56 , V_49 -> V_7 . V_14 . V_45 ) ;
break;
case V_16 :
V_58 = V_49 -> V_7 . V_17 . V_18 <
F_15 ( V_62 ) ?
V_62 [ V_49 -> V_7 . V_17 . V_18 ]
: L_18 ;
F_14 ( L_24 , V_56 , V_58 ) ;
if ( V_49 -> V_7 . V_17 . V_44 )
F_14 ( L_20 ,
V_56 , V_49 -> V_7 . V_17 . V_45 ) ;
break;
default:
case V_19 :
F_14 ( L_25 , V_56 ) ;
break;
}
}
T_1 F_16 ( struct V_1 * V_49 )
{
switch ( V_49 -> V_5 ) {
case V_6 :
if ( V_49 -> V_7 . V_8 . V_44 )
return V_49 -> V_7 . V_8 . V_45 ;
break;
case V_10 :
if ( V_49 -> V_7 . V_11 . V_44 )
return V_49 -> V_7 . V_11 . V_45 ;
break;
case V_13 :
if ( V_49 -> V_7 . V_14 . V_44 )
return V_49 -> V_7 . V_14 . V_45 ;
break;
case V_16 :
if ( V_49 -> V_7 . V_17 . V_44 )
return V_49 -> V_7 . V_17 . V_45 ;
break;
default:
case V_19 :
break;
}
return 0 ;
}
