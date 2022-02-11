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
for ( V_31 = 0 ; V_31 < V_30 -> V_36 ; V_31 ++ ) {
struct V_37 * V_38 = V_30 -> V_39 [ V_31 ] ;
if ( ! V_38 )
continue;
V_32 = F_7 ( V_31 ) ;
V_34 = F_8 ( F_9 ( V_38 ) + V_40 + V_32 ) ;
if ( ! V_34 )
continue;
V_33 = F_7 ( V_31 ) ;
V_35 = F_8 ( F_9 ( V_38 ) + V_41 + V_33 ) ;
V_34 &= ~ V_35 ;
while ( V_34 ) {
int V_42 = F_10 ( V_34 ) - 1 ;
int V_43 = V_38 -> V_10 + V_42 ;
F_11 ( V_43 ) ;
V_34 &= ~ F_12 ( V_42 ) ;
}
}
}
static T_1 int F_13 ( struct V_37 * V_38 )
{
static int V_44 = 0 ;
int V_31 = V_38 -> V_31 ;
struct V_29 * V_30 = NULL ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( V_44 >= V_45 )
return - V_46 ;
F_14 (bank, &banks, list) {
if ( V_31 >= V_30 -> V_47 &&
V_31 < V_30 -> V_47 + V_30 -> V_36 )
break;
}
if ( ! V_30 )
return - V_23 ;
if ( ! V_30 -> V_48 ) {
V_30 -> V_39 = F_15 ( sizeof( struct V_37 * ) *
V_30 -> V_36 , V_49 ) ;
if ( ! V_30 -> V_39 )
return - V_46 ;
F_16 ( V_30 -> V_9 , F_5 ) ;
F_17 ( V_30 -> V_9 , V_30 ) ;
V_30 -> V_48 = F_5 ;
F_3 ( V_50 L_2 ,
V_30 -> V_9 ) ;
}
V_38 -> V_10 = V_51 +
V_44 * V_52 ;
V_44 ++ ;
V_30 -> V_39 [ V_31 - V_30 -> V_47 ] = V_38 ;
V_4 = F_18 ( L_3 , 1 , V_38 -> V_10 ,
( void V_53 * ) F_9 ( V_38 ) ,
V_54 ) ;
if ( ! V_4 )
return - V_46 ;
V_6 = V_4 -> V_7 ;
V_6 -> V_38 . V_55 = V_56 ;
V_6 -> V_38 . V_57 = V_58 ;
V_6 -> V_38 . V_59 = V_60 ;
V_6 -> V_38 . V_61 = F_1 ,
V_6 -> V_26 . V_62 = V_40 + F_7 ( V_38 -> V_31 ) ;
V_6 -> V_26 . V_35 = V_41 + F_7 ( V_38 -> V_31 ) ;
V_6 -> V_26 . type = V_63 + F_7 ( V_38 -> V_31 ) ;
F_19 ( V_4 , F_20 ( V_38 -> V_38 . V_64 ) ,
V_65 ,
V_66 | V_67 , 0 ) ;
return 0 ;
}
int T_1 F_21 ( int V_68 )
{
struct V_37 * V_69 = F_22 ( V_68 ) ;
int V_42 , V_31 ;
int V_70 ;
if ( ! V_69 )
return - V_23 ;
V_42 = V_68 - V_69 -> V_38 . V_71 ;
V_31 = V_69 -> V_31 ;
if ( V_69 -> V_10 )
return V_69 -> V_10 + V_42 ;
V_70 = F_13 ( V_69 ) ;
if ( V_70 == 0 ) {
V_69 -> V_38 . V_72 = V_73 ;
F_3 ( V_50 L_4 ,
V_31 ) ;
return V_69 -> V_10 + V_42 ;
}
return V_70 ;
}
int T_1 F_23 ( int V_74 , int V_47 , int V_36 )
{
struct V_29 * V_30 ;
V_30 = F_15 ( sizeof( * V_30 ) , V_49 ) ;
if ( ! V_30 )
return - V_46 ;
V_30 -> V_47 = V_47 ;
V_30 -> V_36 = V_36 ;
V_30 -> V_9 = V_74 ;
F_24 ( & V_30 -> V_75 , & V_76 ) ;
return 0 ;
}
