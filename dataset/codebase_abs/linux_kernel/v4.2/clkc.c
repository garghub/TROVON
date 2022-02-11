struct V_1 * * T_1 F_1 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
V_5 = F_2 ( V_4 , sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return F_3 ( - V_7 ) ;
V_8 . V_5 = V_5 ;
V_8 . V_9 = V_4 ;
F_4 ( V_3 , V_10 , & V_8 ) ;
return V_5 ;
}
static void F_5 ( struct V_1 * V_1 , unsigned int V_11 )
{
if ( V_5 && V_11 )
V_5 [ V_11 ] = V_1 ;
}
static struct V_1 * T_1
F_6 ( const struct V_12 * V_12 ,
void T_2 * V_13 )
{
struct V_1 * V_1 ;
struct V_14 * V_15 = NULL ;
struct V_16 * div = NULL ;
struct V_17 * V_18 = NULL ;
const struct V_19 * V_20 = NULL ;
const struct V_21 * V_21 ;
V_21 = V_12 -> V_22 . V_23 ;
if ( V_12 -> V_24 > 1 ) {
V_15 = F_7 ( sizeof( * V_15 ) , V_6 ) ;
if ( ! V_15 )
return F_3 ( - V_7 ) ;
V_15 -> V_25 = V_13 + V_12 -> V_26
+ V_21 -> V_27 . V_26 ;
V_15 -> V_28 = V_21 -> V_27 . V_28 ;
V_15 -> V_29 = F_8 ( V_21 -> V_27 . V_30 ) - 1 ;
V_15 -> V_31 = V_21 -> V_32 ;
V_15 -> V_33 = & V_34 ;
V_15 -> V_35 = V_21 -> V_36 ;
V_20 = ( V_21 -> V_32 & V_37 ) ?
& V_38 : & V_39 ;
}
if ( F_9 ( & V_21 -> V_40 ) ) {
div = F_7 ( sizeof( * div ) , V_6 ) ;
if ( ! div ) {
V_1 = F_3 ( - V_7 ) ;
goto error;
}
div -> V_25 = V_13 + V_12 -> V_26
+ V_21 -> V_40 . V_26 ;
div -> V_28 = V_21 -> V_40 . V_28 ;
div -> V_30 = V_21 -> V_40 . V_30 ;
div -> V_33 = & V_34 ;
div -> V_31 = V_21 -> V_41 ;
div -> V_35 = V_21 -> V_42 ;
}
if ( F_9 ( & V_21 -> V_43 ) ) {
V_18 = F_7 ( sizeof( * V_18 ) , V_6 ) ;
if ( ! V_18 ) {
V_1 = F_3 ( - V_7 ) ;
goto error;
}
V_18 -> V_25 = V_13 + V_12 -> V_26
+ V_21 -> V_40 . V_26 ;
V_18 -> V_44 = V_21 -> V_43 . V_28 ;
V_18 -> V_31 = V_21 -> V_45 ;
V_18 -> V_33 = & V_34 ;
}
V_1 = F_10 ( NULL , V_12 -> V_46 ,
V_12 -> V_47 ,
V_12 -> V_24 ,
V_15 ? & V_15 -> V_48 : NULL , V_20 ,
div ? & div -> V_48 : NULL , & V_49 ,
V_18 ? & V_18 -> V_48 : NULL , & V_50 ,
V_12 -> V_31 ) ;
if ( F_11 ( V_1 ) )
goto error;
return V_1 ;
error:
F_12 ( V_18 ) ;
F_12 ( div ) ;
F_12 ( V_15 ) ;
return V_1 ;
}
static struct V_1 * T_1
F_13 ( const struct V_12 * V_12 ,
void T_2 * V_13 )
{
struct V_1 * V_1 ;
const struct V_51 * V_51 ;
const struct V_52 * V_53 ;
unsigned int V_54 , div ;
T_3 V_25 ;
V_51 = & V_12 -> V_22 . V_55 ;
V_54 = V_12 -> V_22 . V_55 . V_54 ;
div = V_12 -> V_22 . V_55 . div ;
if ( ! V_54 ) {
V_54 = 1 ;
V_53 = & V_51 -> V_56 ;
if ( F_9 ( V_53 ) ) {
V_25 = F_14 ( V_13 + V_12 -> V_26 + V_53 -> V_26 ) ;
V_54 = F_15 ( V_53 -> V_30 , V_53 -> V_28 , V_25 ) ;
}
}
if ( ! div ) {
div = 1 ;
V_53 = & V_51 -> V_40 ;
if ( F_9 ( V_53 ) ) {
V_25 = F_14 ( V_13 + V_12 -> V_26 + V_53 -> V_26 ) ;
V_54 = F_15 ( V_53 -> V_30 , V_53 -> V_28 , V_25 ) ;
}
}
V_1 = F_16 ( NULL ,
V_12 -> V_46 ,
V_12 -> V_47 [ 0 ] ,
V_12 -> V_31 ,
V_54 , div ) ;
return V_1 ;
}
static struct V_1 * T_1
F_17 ( const struct V_12 * V_12 ,
void T_2 * V_13 )
{
struct V_1 * V_1 ;
const struct V_57 * V_57 ;
const struct V_52 * V_58 ;
unsigned long V_59 ;
T_3 V_25 ;
V_57 = & V_12 -> V_22 . V_60 ;
V_59 = V_57 -> V_59 ;
if ( ! V_59 ) {
V_58 = & V_57 -> V_61 ;
V_25 = F_14 ( V_13 + V_12 -> V_26 + V_58 -> V_26 ) ;
V_59 = F_15 ( V_58 -> V_30 , V_58 -> V_28 , V_25 ) ;
}
V_59 *= 1000000 ;
V_1 = F_18 ( NULL ,
V_12 -> V_46 ,
V_12 -> V_24
? V_12 -> V_47 [ 0 ] : NULL ,
V_12 -> V_31 , V_59 ) ;
return V_1 ;
}
void T_1 F_19 ( const struct V_12 * V_62 ,
T_4 V_63 ,
void T_2 * V_13 )
{
unsigned int V_64 ;
struct V_1 * V_1 = NULL ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
const struct V_12 * V_12 = & V_62 [ V_64 ] ;
switch ( V_12 -> V_65 ) {
case V_66 :
V_1 = F_17 ( V_12 ,
V_13 ) ;
break;
case V_67 :
V_1 = F_13 ( V_12 ,
V_13 ) ;
break;
case V_68 :
V_1 = F_6 ( V_12 ,
V_13 ) ;
break;
case V_69 :
V_1 = F_20 ( V_12 , V_13 ,
& V_34 ) ;
break;
case V_70 :
V_1 = F_21 ( V_12 , V_13 ,
& V_34 ) ;
break;
default:
V_1 = NULL ;
}
if ( ! V_1 ) {
F_22 ( L_1 , V_71 ,
V_12 -> V_65 ) ;
continue;
}
if ( F_11 ( V_1 ) ) {
F_23 ( L_2 , V_71 ,
V_12 -> V_46 ) ;
continue;
}
F_5 ( V_1 , V_12 -> V_72 ) ;
}
}
