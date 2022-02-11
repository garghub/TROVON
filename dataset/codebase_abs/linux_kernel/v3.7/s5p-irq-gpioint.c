static int F_1 ( struct V_1 * V_2 , unsigned int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_8 = ( V_2 -> V_9 - V_4 -> V_10 ) << 2 ;
switch ( type ) {
case V_11 :
type = V_12 ;
break;
case V_13 :
type = V_14 ;
break;
case V_15 :
type = V_16 ;
break;
case V_17 :
type = V_18 ;
break;
case V_19 :
type = V_20 ;
break;
case V_21 :
default:
F_3 ( V_22 L_1 ) ;
return - V_23 ;
}
V_4 -> V_24 &= ~ ( 0x7 << V_8 ) ;
V_4 -> V_24 |= type << V_8 ;
F_4 ( V_4 -> V_24 , V_4 -> V_25 + V_6 -> V_26 . type ) ;
return 0 ;
}
static void F_5 ( unsigned int V_9 , struct V_27 * V_28 )
{
struct V_29 * V_30 = F_6 ( V_9 ) ;
int V_31 , V_32 , V_33 ;
unsigned int V_34 , V_35 ;
struct V_36 * V_37 = F_7 ( V_9 ) ;
F_8 ( V_37 , V_28 ) ;
for ( V_31 = 0 ; V_31 < V_30 -> V_38 ; V_31 ++ ) {
struct V_39 * V_37 = V_30 -> V_40 [ V_31 ] ;
if ( ! V_37 )
continue;
V_32 = F_9 ( V_31 ) ;
V_34 = F_10 ( F_11 ( V_37 ) + V_41 + V_32 ) ;
if ( ! V_34 )
continue;
V_33 = F_9 ( V_31 ) ;
V_35 = F_10 ( F_11 ( V_37 ) + V_42 + V_33 ) ;
V_34 &= ~ V_35 ;
while ( V_34 ) {
int V_43 = F_12 ( V_34 ) - 1 ;
int V_44 = V_37 -> V_10 + V_43 ;
F_13 ( V_44 ) ;
V_34 &= ~ F_14 ( V_43 ) ;
}
}
F_15 ( V_37 , V_28 ) ;
}
static T_1 int F_16 ( struct V_39 * V_37 )
{
static int V_45 = 0 ;
int V_31 = V_37 -> V_31 ;
struct V_29 * V_46 , * V_30 = NULL ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( V_45 >= V_47 )
return - V_48 ;
F_17 (b, &banks, list) {
if ( V_31 >= V_46 -> V_49 && V_31 < V_46 -> V_49 + V_46 -> V_38 ) {
V_30 = V_46 ;
break;
}
}
if ( ! V_30 )
return - V_23 ;
if ( ! V_30 -> V_50 ) {
V_30 -> V_40 = F_18 ( sizeof( struct V_39 * ) *
V_30 -> V_38 , V_51 ) ;
if ( ! V_30 -> V_40 )
return - V_48 ;
F_19 ( V_30 -> V_9 , F_5 ) ;
F_20 ( V_30 -> V_9 , V_30 ) ;
V_30 -> V_50 = F_5 ;
F_3 ( V_52 L_2 ,
V_30 -> V_9 ) ;
}
V_37 -> V_10 = V_53 +
V_45 * V_54 ;
V_45 ++ ;
V_30 -> V_40 [ V_31 - V_30 -> V_49 ] = V_37 ;
V_4 = F_21 ( L_3 , 1 , V_37 -> V_10 ,
F_11 ( V_37 ) ,
V_55 ) ;
if ( ! V_4 )
return - V_48 ;
V_6 = V_4 -> V_7 ;
V_6 -> V_37 . V_56 = V_57 ;
V_6 -> V_37 . V_58 = V_59 ;
V_6 -> V_37 . V_60 = V_61 ;
V_6 -> V_37 . V_62 = F_1 ,
V_6 -> V_26 . V_63 = V_41 + F_9 ( V_31 - V_30 -> V_49 ) ;
V_6 -> V_26 . V_35 = V_42 + F_9 ( V_31 - V_30 -> V_49 ) ;
V_6 -> V_26 . type = V_64 + F_9 ( V_31 - V_30 -> V_49 ) ;
F_22 ( V_4 , F_23 ( V_37 -> V_37 . V_65 ) ,
V_66 ,
V_67 | V_68 , 0 ) ;
return 0 ;
}
int T_1 F_24 ( int V_69 )
{
struct V_39 * V_70 = F_25 ( V_69 ) ;
int V_43 , V_31 ;
int V_71 ;
if ( ! V_70 )
return - V_23 ;
V_43 = V_69 - V_70 -> V_37 . V_72 ;
V_31 = V_70 -> V_31 ;
if ( V_70 -> V_10 )
return V_70 -> V_10 + V_43 ;
V_71 = F_16 ( V_70 ) ;
if ( V_71 == 0 ) {
V_70 -> V_37 . V_73 = V_74 ;
F_3 ( V_52 L_4 ,
V_31 ) ;
return V_70 -> V_10 + V_43 ;
}
return V_71 ;
}
int T_1 F_26 ( int V_75 , int V_49 , int V_38 )
{
struct V_29 * V_30 ;
V_30 = F_18 ( sizeof( * V_30 ) , V_51 ) ;
if ( ! V_30 )
return - V_48 ;
V_30 -> V_49 = V_49 ;
V_30 -> V_38 = V_38 ;
V_30 -> V_9 = V_75 ;
F_27 ( & V_30 -> V_76 , & V_77 ) ;
return 0 ;
}
