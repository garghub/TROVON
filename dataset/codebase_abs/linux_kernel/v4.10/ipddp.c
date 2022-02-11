static struct V_1 * T_1 F_1 ( void )
{
static unsigned V_2 ;
struct V_1 * V_3 ;
int V_4 ;
V_3 = F_2 ( 0 ) ;
if ( ! V_3 )
return F_3 ( - V_5 ) ;
F_4 ( V_3 ) ;
strcpy ( V_3 -> V_6 , L_1 ) ;
if ( V_2 ++ == 0 )
F_5 ( V_7 ) ;
V_3 -> V_8 = & V_9 ;
V_3 -> type = V_10 ;
V_3 -> V_11 = 585 ;
V_3 -> V_12 |= V_13 ;
V_3 -> V_14 = 14 + 8 + sizeof( struct V_15 ) + 1 ;
V_4 = F_6 ( V_3 ) ;
if ( V_4 ) {
F_7 ( V_3 ) ;
return F_3 ( V_4 ) ;
}
if( V_16 == V_17 )
F_5 ( L_2 ,
V_3 -> V_6 ) ;
if( V_16 == V_18 )
F_5 ( L_3 ,
V_3 -> V_6 ) ;
return V_3 ;
}
static T_2 F_8 ( struct V_19 * V_20 , struct V_1 * V_3 )
{
T_3 V_21 = F_9 ( V_20 ) -> V_22 ;
struct V_15 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
F_10 ( & V_28 ) ;
for( V_25 = V_29 ; V_25 != NULL ; V_25 = V_25 -> V_30 )
{
if( V_25 -> V_31 == V_21 )
break;
}
if( V_25 == NULL ) {
F_11 ( & V_28 ) ;
return V_32 ;
}
V_27 = F_12 ( V_25 -> V_3 ) ;
if( V_16 == V_18 )
F_13 ( V_20 , 35 - ( sizeof( struct V_15 ) + 1 ) ) ;
V_23 = (struct V_15 * ) V_20 -> V_33 ;
V_23 -> V_34 = F_14 ( V_20 -> V_35 + ( 1 << 10 ) ) ;
V_23 -> V_36 = 0 ;
if( V_25 -> V_3 -> type == V_37 )
{
V_23 -> V_38 = 0 ;
V_23 -> V_39 = 0 ;
}
else
{
V_23 -> V_38 = V_25 -> V_40 . V_41 ;
V_23 -> V_39 = V_27 -> V_41 ;
}
V_23 -> V_42 = V_25 -> V_40 . V_43 ;
V_23 -> V_44 = V_27 -> V_43 ;
V_23 -> V_45 = 72 ;
V_23 -> V_46 = 72 ;
* ( ( V_47 * ) ( V_23 + 1 ) ) = 22 ;
V_20 -> V_48 = F_14 ( V_49 ) ;
V_3 -> V_50 . V_51 ++ ;
V_3 -> V_50 . V_52 += V_20 -> V_35 ;
F_15 ( V_25 -> V_3 , V_20 , & V_25 -> V_40 , NULL ) ;
F_11 ( & V_28 ) ;
return V_32 ;
}
static int F_16 ( struct V_24 * V_53 )
{
struct V_24 * V_25 = F_17 ( sizeof( * V_25 ) , V_54 ) ;
if ( V_25 == NULL )
return - V_5 ;
V_25 -> V_31 = V_53 -> V_31 ;
V_25 -> V_40 = V_53 -> V_40 ;
V_25 -> V_30 = NULL ;
if ( ( V_25 -> V_3 = F_18 ( & V_25 -> V_40 ) ) == NULL ) {
F_19 ( V_25 ) ;
return - V_55 ;
}
F_20 ( & V_28 ) ;
if ( F_21 ( V_25 ) ) {
F_22 ( & V_28 ) ;
F_19 ( V_25 ) ;
return - V_56 ;
}
V_25 -> V_30 = V_29 ;
V_29 = V_25 ;
F_22 ( & V_28 ) ;
return 0 ;
}
static int F_23 ( struct V_24 * V_25 )
{
struct V_24 * * V_57 = & V_29 ;
struct V_24 * V_58 ;
F_20 ( & V_28 ) ;
while( ( V_58 = * V_57 ) != NULL )
{
if( V_58 -> V_31 == V_25 -> V_31 &&
V_58 -> V_40 . V_41 == V_25 -> V_40 . V_41 &&
V_58 -> V_40 . V_43 == V_25 -> V_40 . V_43 )
{
* V_57 = V_58 -> V_30 ;
F_22 ( & V_28 ) ;
F_19 ( V_58 ) ;
return 0 ;
}
V_57 = & V_58 -> V_30 ;
}
F_22 ( & V_28 ) ;
return - V_59 ;
}
static struct V_24 * F_21 ( struct V_24 * V_25 )
{
struct V_24 * V_60 ;
for( V_60 = V_29 ; V_60 != NULL ; V_60 = V_60 -> V_30 )
{
if( V_60 -> V_31 == V_25 -> V_31 &&
V_60 -> V_40 . V_41 == V_25 -> V_40 . V_41 &&
V_60 -> V_40 . V_43 == V_25 -> V_40 . V_43 )
return V_60 ;
}
return NULL ;
}
static int F_24 ( struct V_1 * V_3 , struct V_61 * V_62 , int V_63 )
{
struct V_24 T_4 * V_25 = V_62 -> V_64 ;
struct V_24 V_65 , V_66 , * V_67 ;
if( ! F_25 ( V_68 ) )
return - V_69 ;
if( F_26 ( & V_65 , V_25 , sizeof( V_65 ) ) )
return - V_70 ;
switch( V_63 )
{
case V_71 :
return F_16 ( & V_65 ) ;
case V_72 :
F_20 ( & V_28 ) ;
V_67 = F_21 ( & V_65 ) ;
if ( V_67 )
memcpy ( & V_66 , V_67 , sizeof( V_66 ) ) ;
F_22 ( & V_28 ) ;
if ( V_67 ) {
if ( F_27 ( V_25 , & V_66 ,
sizeof( struct V_24 ) ) )
return - V_70 ;
return 0 ;
} else
return - V_59 ;
case V_73 :
return F_23 ( & V_65 ) ;
default:
return - V_74 ;
}
}
static int T_1 F_28 ( void )
{
V_75 = F_1 () ;
if ( F_29 ( V_75 ) )
return F_30 ( V_75 ) ;
return 0 ;
}
static void T_5 F_31 ( void )
{
struct V_24 * V_76 ;
F_32 ( V_75 ) ;
F_7 ( V_75 ) ;
while ( V_29 ) {
V_76 = V_29 -> V_30 ;
F_19 ( V_29 ) ;
V_29 = V_76 ;
}
}
