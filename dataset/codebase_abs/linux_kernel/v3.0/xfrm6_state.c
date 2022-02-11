static void
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = & V_4 -> V_7 . V_8 ;
F_2 ( (struct V_9 * ) & V_2 -> V_10 , & V_6 -> V_10 ) ;
F_2 ( (struct V_9 * ) & V_2 -> V_11 , & V_6 -> V_11 ) ;
V_2 -> V_12 = F_3 ( V_4 , & V_6 -> V_13 ) ;
V_2 -> V_14 = F_4 ( 0xffff ) ;
V_2 -> V_15 = F_5 ( V_4 , & V_6 -> V_13 ) ;
V_2 -> V_16 = F_4 ( 0xffff ) ;
V_2 -> V_17 = V_18 ;
V_2 -> V_19 = 128 ;
V_2 -> V_20 = 128 ;
V_2 -> V_21 = V_6 -> V_22 ;
V_2 -> V_23 = V_6 -> V_24 ;
}
static void
F_6 ( struct V_25 * V_26 , const struct V_27 * V_28 ,
const T_1 * V_10 , const T_1 * V_11 )
{
V_26 -> V_29 = V_28 -> V_29 ;
if ( F_7 ( (struct V_9 * ) & V_26 -> V_29 . V_10 ) )
memcpy ( & V_26 -> V_29 . V_10 , V_10 , sizeof( V_26 -> V_2 . V_10 ) ) ;
memcpy ( & V_26 -> V_30 . V_11 , & V_28 -> V_11 , sizeof( V_26 -> V_30 . V_11 ) ) ;
if ( F_7 ( (struct V_9 * ) & V_26 -> V_30 . V_11 ) )
memcpy ( & V_26 -> V_30 . V_11 , V_11 , sizeof( V_26 -> V_30 . V_11 ) ) ;
V_26 -> V_30 . V_31 = V_28 -> V_31 ;
V_26 -> V_30 . V_32 = V_28 -> V_32 ;
V_26 -> V_30 . V_17 = V_18 ;
}
static int
F_8 ( void * * V_33 , void * * V_34 , int V_35 , int (* F_9)( void * V_36 ) , int V_37 )
{
int V_38 ;
int V_39 [ V_40 ] ;
int V_41 [ V_37 ] ;
memset ( V_41 , 0 , sizeof( V_41 ) ) ;
for ( V_38 = 0 ; V_38 < V_35 ; V_38 ++ ) {
int V_42 ;
V_39 [ V_38 ] = V_42 = F_9 ( V_34 [ V_38 ] ) ;
V_41 [ V_42 ] ++ ;
}
for ( V_38 = 2 ; V_38 < V_37 ; V_38 ++ )
V_41 [ V_38 ] += V_41 [ V_38 - 1 ] ;
for ( V_38 = 0 ; V_38 < V_35 ; V_38 ++ ) {
V_33 [ V_41 [ V_39 [ V_38 ] - 1 ] ++ ] = V_34 [ V_38 ] ;
V_34 [ V_38 ] = NULL ;
}
return 0 ;
}
static int F_10 ( void * V_36 )
{
struct V_25 * V_43 = V_36 ;
switch ( V_43 -> V_30 . V_31 ) {
case V_44 :
if ( V_43 -> V_29 . V_21 != V_45 )
return 1 ;
else
return 3 ;
#if F_11 ( V_46 ) || F_11 ( V_47 )
case V_48 :
case V_49 :
return 2 ;
#endif
case V_50 :
case V_51 :
return 4 ;
}
return 5 ;
}
static int
F_12 ( struct V_25 * * V_33 , struct V_25 * * V_34 , int V_35 )
{
return F_8 ( ( void * * ) V_33 , ( void * * ) V_34 , V_35 ,
F_10 , 6 ) ;
}
static int F_13 ( void * V_36 )
{
struct V_27 * V_43 = V_36 ;
switch ( V_43 -> V_31 ) {
case V_44 :
return 1 ;
#if F_11 ( V_46 ) || F_11 ( V_47 )
case V_48 :
case V_49 :
return 2 ;
#endif
case V_50 :
case V_51 :
return 3 ;
}
return 4 ;
}
static int
F_14 ( struct V_27 * * V_33 , struct V_27 * * V_34 , int V_35 )
{
return F_8 ( ( void * * ) V_33 , ( void * * ) V_34 , V_35 ,
F_13 , 5 ) ;
}
int F_15 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_16 ( V_53 ) ;
F_17 ( V_53 ) -> V_56 = sizeof( * V_55 ) ;
F_17 ( V_53 ) -> V_29 = 0 ;
F_17 ( V_53 ) -> V_57 = F_4 ( V_58 ) ;
F_17 ( V_53 ) -> V_59 = F_18 ( V_55 ) ;
F_17 ( V_53 ) -> V_60 = V_55 -> V_61 ;
F_17 ( V_53 ) -> V_62 = 0 ;
memcpy ( F_17 ( V_53 ) -> V_63 , V_55 -> V_63 ,
sizeof( F_17 ( V_53 ) -> V_63 ) ) ;
return 0 ;
}
int T_2 F_19 ( void )
{
return F_20 ( & V_64 ) ;
}
void F_21 ( void )
{
F_22 ( & V_64 ) ;
}
