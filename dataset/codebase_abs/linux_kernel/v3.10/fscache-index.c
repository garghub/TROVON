int F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static T_1 F_5 ( const void * V_2 ,
void * V_3 , T_1 V_4 )
{
const struct V_5 * V_6 = V_2 ;
const struct V_7 * V_8 = (struct V_7 * ) & V_6 -> V_9 ;
const struct V_10 * sin = (struct V_10 * ) & V_6 -> V_9 ;
struct V_11 * V_12 = V_3 ;
T_1 V_13 = sizeof( struct V_11 ) ;
V_12 -> V_14 = V_6 -> V_15 -> V_16 ;
V_12 -> V_17 = V_6 -> V_9 . V_18 ;
memset ( V_12 , 0 , V_13 ) ;
switch ( V_6 -> V_9 . V_18 ) {
case V_19 :
V_12 -> V_20 = sin -> V_21 ;
V_12 -> V_22 [ 0 ] . V_23 = sin -> V_24 ;
V_13 += sizeof( V_12 -> V_22 [ 0 ] . V_23 ) ;
break;
case V_25 :
V_12 -> V_20 = V_8 -> V_26 ;
V_12 -> V_22 [ 0 ] . V_27 = V_8 -> V_28 ;
V_13 += sizeof( V_12 -> V_22 [ 0 ] . V_27 ) ;
break;
default:
F_6 ( V_29 L_1 ,
V_6 -> V_9 . V_18 ) ;
V_13 = 0 ;
break;
}
return V_13 ;
}
static T_1 F_7 ( const void * V_2 ,
void * V_3 , T_1 V_4 )
{
const struct V_30 * V_12 ;
const struct V_31 * V_32 = V_2 ;
T_1 V_13 ;
V_12 = V_32 -> V_33 ;
V_13 = sizeof( V_12 -> V_12 ) + V_12 -> V_12 . V_34 ;
if ( V_13 > V_4 ) {
V_13 = 0 ;
} else {
memcpy ( V_3 , & V_12 -> V_12 , sizeof( V_12 -> V_12 ) ) ;
memcpy ( V_3 + sizeof( V_12 -> V_12 ) ,
V_12 -> V_12 . V_35 , V_12 -> V_12 . V_34 ) ;
}
return V_13 ;
}
static T_1 F_8 ( const void * V_2 ,
void * V_3 , T_1 V_4 )
{
const struct V_36 * V_37 = V_2 ;
T_1 V_38 ;
V_38 = V_37 -> V_39 . V_40 ;
memcpy ( V_3 , V_37 -> V_39 . V_41 , V_38 ) ;
return V_38 ;
}
static void F_9 ( const void * V_2 ,
T_2 * V_40 )
{
const struct V_36 * V_37 = V_2 ;
* V_40 = V_37 -> V_42 . V_43 ;
}
static T_1 F_10 ( const void * V_2 ,
void * V_3 , T_1 V_4 )
{
struct V_44 V_45 ;
const struct V_36 * V_37 = V_2 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_40 = V_37 -> V_42 . V_43 ;
V_45 . V_46 = V_37 -> V_42 . V_47 ;
V_45 . ctime = V_37 -> V_42 . V_48 ;
if ( F_11 ( & V_37 -> V_42 ) -> V_5 -> V_15 -> V_16 == 4 )
V_45 . V_49 = V_37 -> V_42 . V_50 ;
if ( V_4 > sizeof( V_45 ) )
V_4 = sizeof( V_45 ) ;
memcpy ( V_3 , & V_45 , V_4 ) ;
return V_4 ;
}
static
enum V_51 F_12 ( void * V_2 ,
const void * V_41 ,
T_1 V_52 )
{
struct V_44 V_45 ;
struct V_36 * V_37 = V_2 ;
if ( V_52 != sizeof( V_45 ) )
return V_53 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_40 = V_37 -> V_42 . V_43 ;
V_45 . V_46 = V_37 -> V_42 . V_47 ;
V_45 . ctime = V_37 -> V_42 . V_48 ;
if ( F_11 ( & V_37 -> V_42 ) -> V_5 -> V_15 -> V_16 == 4 )
V_45 . V_49 = V_37 -> V_42 . V_50 ;
if ( memcmp ( V_41 , & V_45 , V_52 ) != 0 )
return V_53 ;
return V_54 ;
}
static void F_13 ( void * V_2 )
{
struct V_36 * V_37 = V_2 ;
struct V_55 V_56 ;
T_3 V_57 ;
int V_58 , V_59 ;
F_14 ( & V_56 , 0 ) ;
V_57 = 0 ;
F_15 ( L_2 , V_37 ) ;
for (; ; ) {
V_59 = F_16 ( & V_56 ,
V_37 -> V_42 . V_60 ,
V_57 ,
V_61 - F_17 ( & V_56 ) ) ;
if ( ! V_59 )
break;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ )
F_18 ( V_56 . V_62 [ V_58 ] ) ;
V_57 = V_56 . V_62 [ V_59 - 1 ] -> V_63 + 1 ;
V_56 . V_64 = V_59 ;
F_19 ( & V_56 ) ;
F_20 () ;
}
}
static void F_21 ( void * V_2 , void * V_65 )
{
F_22 ( V_65 ) ;
}
static void F_23 ( void * V_2 , void * V_65 )
{
if ( V_65 )
F_24 ( V_65 ) ;
}
