static struct V_1 * T_1 F_1 ( void )
{
static unsigned V_2 ;
struct V_1 * V_3 ;
int V_4 ;
V_3 = F_2 ( 0 ) ;
if ( ! V_3 )
return F_3 ( - V_5 ) ;
V_3 -> V_6 &= ~ V_7 ;
strcpy ( V_3 -> V_8 , L_1 ) ;
if ( V_2 ++ == 0 )
F_4 ( V_9 ) ;
V_3 -> V_10 = & V_11 ;
V_3 -> type = V_12 ;
V_3 -> V_13 = 585 ;
V_3 -> V_14 |= V_15 ;
V_3 -> V_16 = 14 + 8 + sizeof( struct V_17 ) + 1 ;
V_4 = F_5 ( V_3 ) ;
if ( V_4 ) {
F_6 ( V_3 ) ;
return F_3 ( V_4 ) ;
}
if( V_18 == V_19 )
F_4 ( L_2 ,
V_3 -> V_8 ) ;
if( V_18 == V_20 )
F_4 ( L_3 ,
V_3 -> V_8 ) ;
return V_3 ;
}
static T_2 F_7 ( struct V_21 * V_22 , struct V_1 * V_3 )
{
T_3 V_23 = F_8 ( V_22 ) -> V_24 ;
struct V_17 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
F_9 ( & V_30 ) ;
for( V_27 = V_31 ; V_27 != NULL ; V_27 = V_27 -> V_32 )
{
if( V_27 -> V_33 == V_23 )
break;
}
if( V_27 == NULL ) {
F_10 ( & V_30 ) ;
return V_34 ;
}
V_29 = F_11 ( V_27 -> V_3 ) ;
if( V_18 == V_20 )
F_12 ( V_22 , 35 - ( sizeof( struct V_17 ) + 1 ) ) ;
V_25 = (struct V_17 * ) V_22 -> V_35 ;
V_25 -> V_36 = F_13 ( V_22 -> V_37 + ( 1 << 10 ) ) ;
V_25 -> V_38 = 0 ;
if( V_27 -> V_3 -> type == V_39 )
{
V_25 -> V_40 = 0 ;
V_25 -> V_41 = 0 ;
}
else
{
V_25 -> V_40 = V_27 -> V_42 . V_43 ;
V_25 -> V_41 = V_29 -> V_43 ;
}
V_25 -> V_44 = V_27 -> V_42 . V_45 ;
V_25 -> V_46 = V_29 -> V_45 ;
V_25 -> V_47 = 72 ;
V_25 -> V_48 = 72 ;
* ( ( V_49 * ) ( V_25 + 1 ) ) = 22 ;
V_22 -> V_50 = F_13 ( V_51 ) ;
V_3 -> V_52 . V_53 ++ ;
V_3 -> V_52 . V_54 += V_22 -> V_37 ;
F_14 ( V_27 -> V_3 , V_22 , & V_27 -> V_42 , NULL ) ;
F_10 ( & V_30 ) ;
return V_34 ;
}
static int F_15 ( struct V_26 * V_55 )
{
struct V_26 * V_27 = F_16 ( sizeof( * V_27 ) , V_56 ) ;
if ( V_27 == NULL )
return - V_5 ;
V_27 -> V_33 = V_55 -> V_33 ;
V_27 -> V_42 = V_55 -> V_42 ;
V_27 -> V_32 = NULL ;
if ( ( V_27 -> V_3 = F_17 ( & V_27 -> V_42 ) ) == NULL ) {
F_18 ( V_27 ) ;
return - V_57 ;
}
F_19 ( & V_30 ) ;
if ( F_20 ( V_27 ) ) {
F_21 ( & V_30 ) ;
F_18 ( V_27 ) ;
return - V_58 ;
}
V_27 -> V_32 = V_31 ;
V_31 = V_27 ;
F_21 ( & V_30 ) ;
return 0 ;
}
static int F_22 ( struct V_26 * V_27 )
{
struct V_26 * * V_59 = & V_31 ;
struct V_26 * V_60 ;
F_19 ( & V_30 ) ;
while( ( V_60 = * V_59 ) != NULL )
{
if( V_60 -> V_33 == V_27 -> V_33 &&
V_60 -> V_42 . V_43 == V_27 -> V_42 . V_43 &&
V_60 -> V_42 . V_45 == V_27 -> V_42 . V_45 )
{
* V_59 = V_60 -> V_32 ;
F_21 ( & V_30 ) ;
F_18 ( V_60 ) ;
return 0 ;
}
V_59 = & V_60 -> V_32 ;
}
F_21 ( & V_30 ) ;
return - V_61 ;
}
static struct V_26 * F_20 ( struct V_26 * V_27 )
{
struct V_26 * V_62 ;
for( V_62 = V_31 ; V_62 != NULL ; V_62 = V_62 -> V_32 )
{
if( V_62 -> V_33 == V_27 -> V_33 &&
V_62 -> V_42 . V_43 == V_27 -> V_42 . V_43 &&
V_62 -> V_42 . V_45 == V_27 -> V_42 . V_45 )
return V_62 ;
}
return NULL ;
}
static int F_23 ( struct V_1 * V_3 , struct V_63 * V_64 , int V_65 )
{
struct V_26 T_4 * V_27 = V_64 -> V_66 ;
struct V_26 V_67 , V_68 , * V_69 ;
if( ! F_24 ( V_70 ) )
return - V_71 ;
if( F_25 ( & V_67 , V_27 , sizeof( V_67 ) ) )
return - V_72 ;
switch( V_65 )
{
case V_73 :
return F_15 ( & V_67 ) ;
case V_74 :
F_19 ( & V_30 ) ;
V_69 = F_20 ( & V_67 ) ;
if ( V_69 )
memcpy ( & V_68 , V_69 , sizeof( V_68 ) ) ;
F_21 ( & V_30 ) ;
if ( V_69 ) {
if ( F_26 ( V_27 , & V_68 ,
sizeof( struct V_26 ) ) )
return - V_72 ;
return 0 ;
} else
return - V_61 ;
case V_75 :
return F_22 ( & V_67 ) ;
default:
return - V_76 ;
}
}
static int T_1 F_27 ( void )
{
V_77 = F_1 () ;
if ( F_28 ( V_77 ) )
return F_29 ( V_77 ) ;
return 0 ;
}
static void T_5 F_30 ( void )
{
struct V_26 * V_78 ;
F_31 ( V_77 ) ;
F_6 ( V_77 ) ;
while ( V_31 ) {
V_78 = V_31 -> V_32 ;
F_18 ( V_31 ) ;
V_31 = V_78 ;
}
}
